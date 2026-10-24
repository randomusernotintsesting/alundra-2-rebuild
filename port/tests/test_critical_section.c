/* EnterCriticalSection must return the old enabled state. The original
 * card-event cleanup restores interrupts only when that return equals 1.
 * Link the real dispatcher, BIOS event registry and generated guest code;
 * platform devices are inert and no memory card is initialized or opened. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "scps_decls.h"
/* This fixture exercises critical sections without a native save operation. */
int a2_native_save_handle(uint32_t address) { (void)address; return 0; }

extern int psx_critical;
void kernel_syscall(uint32_t table, uint32_t number);
void psx_deliver_event(uint32_t cls, uint32_t spec);

uint32_t psx_work, psx_frame_no, seq_ticks;
int a2_modelcap_active(void) { return 0; }
FILE *a2_modelcap_file(void) { return NULL; }
int psx_bb_budget = 1000000;
void psx_bb_fire(void) { abort(); }
void psx_interp(uint32_t entry) {
    fprintf(stderr, "unexpected guest segment %08X\n", entry);
    abort();
}
void psx_vblank_tick(void) { abort(); }
void gpu_gp0(uint32_t word) { (void)word; abort(); }
uint16_t psx_pad_buttons(void) { return 0xffff; }
uint32_t psx_irq_active(void) { return 0; }
uint32_t psx_mmio_read(uint32_t address, int size) {
    (void)address; (void)size; abort();
}
void psx_mmio_write(uint32_t address, uint32_t value, int size) {
    (void)address; (void)value; (void)size; abort();
}

/* Only the real segments reachable from the card-event cleanup. BIOS B0:09
 * is dispatched through kernel_hle.c by the normal native dispatcher. */
#define ENTRY(address) {0x##address##u, f_##address}
const psx_func_entry scps_table[] = {
    ENTRY(80030D18), ENTRY(80030D28), ENTRY(8003CC74), ENTRY(8003CC84),
    ENTRY(8003CC94), ENTRY(8003CCA4), ENTRY(8003CCB4), ENTRY(8003CCC4),
    ENTRY(8003CCD4), ENTRY(8003CCE4), ENTRY(8003CCF4), ENTRY(8003CD04),
    ENTRY(8003CD18), ENTRY(8003D068)
};
const int scps_table_n = sizeof scps_table / sizeof scps_table[0];
#define EMPTY_OVERLAY(name) \
    const psx_func_entry name##_table[] = {{0, NULL}}; \
    const int name##_table_n = 0
EMPTY_OVERLAY(game00);
EMPTY_OVERLAY(game01);
EMPTY_OVERLAY(game02);
EMPTY_OVERLAY(game03);
EMPTY_OVERLAY(event00);

static unsigned failures;
static void expect_word(const char *label, uint32_t actual, uint32_t wanted) {
    if (actual != wanted) {
        fprintf(stderr, "FAIL %s: got %08X, expected %08X\n",
                label, actual, wanted);
        failures++;
    }
}

static void enter_returns_previous_enabled_state(void) {
    /* Wrong/missing return, inverted old state, or returning 1 unconditionally
     * must fail independently of the guest's previous v0 value. */
    static const struct { int before; uint32_t stale, wanted; } cases[] = {
        {0, 0, 1}, {0, 0x8003c400, 1}, {0, 1, 1},
        {1, 0, 0}, {1, 0x8003c400, 0}, {1, 1, 0}
    };
    for (unsigned i = 0; i < sizeof cases / sizeof cases[0]; i++) {
        psx_critical = cases[i].before;
        R[2] = cases[i].stale;
        R[4] = 1;
        psx_syscall_at(0x80030d1c);
        expect_word("EnterCriticalSection return", R[2], cases[i].wanted);
        expect_word("EnterCriticalSection disables interrupts", psx_critical, 1);
    }
}

static void exit_preserves_registers(void) {
    /* ExitCriticalSection has no return value: clearing v0 here corrupts the
     * caller even if the interrupt flag itself is restored correctly. */
    for (unsigned i = 0; i < 32; i++) R[i] = 0x12340000u + i;
    R[0] = 0;
    R[2] = 0x8003c400;
    R[4] = 2;
    HI = 0x11223344;
    LO = 0x55667788;
    uint32_t before[32];
    memcpy(before, R, sizeof before);
    psx_critical = 1;
    psx_syscall_at(0x80030d2c);
    expect_word("ExitCriticalSection enables interrupts", psx_critical, 0);
    for (unsigned i = 0; i < 32; i++)
        expect_word("ExitCriticalSection preserves register", R[i], before[i]);
    expect_word("ExitCriticalSection preserves HI", HI, 0x11223344);
    expect_word("ExitCriticalSection preserves LO", LO, 0x55667788);
}

static void card_cleanup_preserves_previous_interrupt_state(int disabled,
                                                           uint32_t stale) {
    memset(PSX_RAM, 0, sizeof PSX_RAM);
    memset(R, 0, sizeof R);
    uint32_t events[8];
    for (unsigned i = 0; i < 8; i++) {
        R[4] = 0xf0000011;
        R[5] = 1u << i;
        R[6] = 0x2000;
        R[7] = 0;
        kernel_syscall(0xb0, 8);
        events[i] = R[2];
        assert(events[i] != 0xffffffff);
        sw_(0x8007ba10u + i * 4, events[i]);
        R[4] = events[i];
        kernel_syscall(0xb0, 12);
    }
    R[2] = stale;
    R[16] = 0x76543210;
    R[29] = 0x801ff000;
    R[31] = 0x800c8944;
    psx_critical = disabled;
    psx_call(0x8003cc74);
    expect_word(disabled ? "nested card cleanup keeps interrupts disabled"
                         : "card cleanup restores interrupts",
                psx_critical, (uint32_t)disabled);
    expect_word("card cleanup restores s0", R[16], 0x76543210);
    expect_word("card cleanup restores stack", R[29], 0x801ff000);
    expect_word("card cleanup returns to caller", R[31], 0x800c8944);
    /* A closed event must no longer receive delivery; this proves the real
     * cleanup and BIOS event close path both ran before checking IRQ state. */
    for (unsigned i = 0; i < 8; i++) {
        psx_deliver_event(0xf0000011, 1u << i);
        R[4] = events[i];
        kernel_syscall(0xb0, 11);
        expect_word("closed card event cannot receive delivery", R[2], 0);
    }
}

int main(void) {
    enter_returns_previous_enabled_state();
    exit_preserves_registers();
    card_cleanup_preserves_previous_interrupt_state(0, 0x8003c400);
    card_cleanup_preserves_previous_interrupt_state(1, 1);
    if (failures) return 1;
    puts("PASS: critical-section return contract and real card-event cleanup");
    return 0;
}
