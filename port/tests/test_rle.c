/* Golden test for the recompiled RLE decoder under the FLAT dispatcher.
 * Usage: test_rle <stream.bin> <golden.bin>
 * The generated file provides f_8001C26C + its call-return segments and
 * `test_table`; this harness runs a minimal dispatch loop with HLE at
 * the two PSY-Q callees (DrawSync 0x800328F4, LoadImage 0x80032BA0).
 */
#include <stdio.h>
#include <stdlib.h>
#include "psx_rt.h"

uint8_t PSX_RAM[PSX_RAM_SIZE];
uint8_t PSX_SCRATCH[0x400];
uint32_t R[32];
uint32_t HI, LO;
uint32_t psx_next;
int psx_bb_budget = 1 << 30;
uint32_t psx_work;
uint32_t a2_ramwatch;
void a2_ramwatch_hit(uint32_t phys, uint32_t v, int size) {
    (void)phys; (void)v; (void)size;
}
void psx_bb_fire(void) { psx_bb_budget = 1 << 30; }
uint32_t psx_mmio_read(uint32_t p, int size) { (void)p; (void)size; return 0; }
void psx_mmio_write(uint32_t p, uint32_t v, int size) { (void)p; (void)v; (void)size; }
void psx_call(uint32_t addr) { (void)addr; }

extern const psx_func_entry test_table[];
extern const int test_table_n;

void psx_break(uint32_t code) {
    fprintf(stderr, "FAIL: break %u hit\n", code);
    exit(3);
}
void psx_syscall(void) { exit(3); }
void psx_syscall_at(uint32_t pc) { (void)pc; exit(3); }
void psx_trap(uint32_t a) { fprintf(stderr, "FAIL: trap %08X\n", a); exit(3); }
uint32_t psx_cop0_read(int r) { (void)r; return 0; }
void psx_cop0_write(int r, uint32_t v) { (void)r; (void)v; }
void psx_rfe(void) {}
void gte_cmd(uint32_t op) { (void)op; }
uint32_t gte_data_read(int r) { (void)r; return 0; }
void gte_data_write(int r, uint32_t v) { (void)r; (void)v; }
uint32_t gte_ctrl_read(int r) { (void)r; return 0; }
void gte_ctrl_write(int r, uint32_t v) { (void)r; (void)v; }

static void run(uint32_t entry) {
    const uint32_t SENT = 0xFFAA0004u;
    R[31] = SENT;
    psx_next = entry;
    while (psx_next != SENT) {
        uint32_t t = psx_next;
        psx_next = 0;
        if (t == 0x800328F4u) { psx_next = R[31]; continue; }  /* DrawSync */
        if (t == 0x80032BA0u) {                                /* LoadImage */
            fprintf(stderr, "FAIL: LoadImage in memory mode\n");
            exit(2);
        }
        void (*fn)(void) = 0;
        for (int i = 0; i < test_table_n; i++)
            if (test_table[i].addr == t) { fn = test_table[i].fn; break; }
        if (!fn) {
            fprintf(stderr, "FAIL: no segment at 0x%08X\n", t);
            exit(2);
        }
        fn();
        if (!psx_next) psx_next = R[31];
    }
}

static long slurp(const char *path, uint8_t *dst, long max) {
    FILE *f = fopen(path, "rb");
    if (!f) { perror(path); exit(4); }
    long n = fread(dst, 1, max, f);
    fclose(f);
    return n;
}

int main(int argc, char **argv) {
    if (argc != 3) { fprintf(stderr, "usage: %s stream golden\n", argv[0]); return 4; }
    static uint8_t golden[1 << 22];

    const uint32_t src = 0x80100000, dst = 0x80180000;
    slurp(argv[1], PSX_RAM + PSX_ADDR(src) + 4, 1 << 20);
    long glen = slurp(argv[2], golden, sizeof golden);

    R[29] = 0x801FFF00;
    R[4] = src;
    R[5] = (uint32_t)glen;
    R[6] = dst;
    R[7] = 0x801FFE00;
    run(0x8001C26Cu);

    for (long k = 0; k < glen; k++) {
        if (PSX_RAM[PSX_ADDR(dst) + k] != golden[k]) {
            fprintf(stderr, "FAIL: byte %ld differs (got %02X want %02X)\n",
                    k, PSX_RAM[PSX_ADDR(dst) + k], golden[k]);
            return 1;
        }
    }
    printf("OK %ld bytes\n", glen);
    return 0;
}
