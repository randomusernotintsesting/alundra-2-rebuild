/* Native EXE entry is a post-BIOS handoff, not cold controller power-on.
 * Exercise actual compiled CD_init cleanup, CD_cw issue and IRQ-consume
 * segments against the real controller. Only platform IRQ/MMIO are bridged.
 */
#include <assert.h>
#include <stdio.h>
#include "scps_decls.h"
#include "../src/spu.c"
#include "../src/cdrom.c"

uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t R[32], HI, LO, psx_next, psx_work, a2_ramwatch, psx_frame_no;
int psx_bb_budget = 1000000, psx_in_irq, psx_critical;
static unsigned irq_count, dispatch_count;
static uint32_t test_dpcr;
void psx_break(uint32_t n) {(void)n; abort();}
void psx_bb_fire(void) {abort();}
void psx_trap(uint32_t n) {(void)n; abort();}
void a2_ramwatch_hit(uint32_t p,uint32_t v,int s) {(void)p;(void)v;(void)s;abort();}
void a2_ramwatch_blk(uint32_t p,uint32_t n,const char *t) {(void)p;(void)n;(void)t;}
uint32_t psx_mmio_read(uint32_t p,int s) {
    assert(s == 1 && p >= 0x1f801800 && p < 0x1f801804);
    return cd_read_reg((int)(p & 3));
}
void psx_mmio_write(uint32_t p,uint32_t v,int s) {
    if (p == 0x1f8010f0) { assert(s == 4); test_dpcr=v; return; }
    assert(s == 1 && p >= 0x1f801800 && p < 0x1f801804);
    cd_write_reg((int)(p & 3), (uint8_t)v);
}
void psx_irq_set(int bit) { assert(bit == 2); irq_count++; }
void psx_irq_dispatch(void) {
    uint32_t saved[32], saved_next=psx_next;
    memcpy(saved, R, sizeof saved);
    dispatch_count++;
    R[31]=0x12345678;
    f_80040238(); /* Actual libds response read, acknowledgement and status. */
    assert(psx_next == 0x12345678);
    memcpy(R, saved, sizeof saved); psx_next=saved_next;
}

static void guest_fixture(void) {
    memset(PSX_RAM, 0, sizeof PSX_RAM); memset(R, 0, sizeof R);
    R[29]=0x801ff000;
    sw_(0x8005c284, 0x1f801800); sw_(0x8005c288, 0x1f801801);
    sw_(0x8005c28c, 0x1f801802); sw_(0x8005c290, 0x1f801803);
    sw_(0x8005c294, 0x1f8010f0);
    /* Original IRQ dispatch table's INT3 entry at 8001938C + 2*4. */
    sw_(0x80019394, 0x8004049c);
}
static void guest_init_prefix(void) {
    f_800413F8();
    assert(psx_next == 0x8004147c); /* Clean flags skip the mask=7 write. */
    f_8004147C();
    assert(psx_next == 0x80040ce4 && R[4] == 1 && test_dpcr == 0x1325);
}
static void guest_issue_nop(void) {
    R[17]=1; R[16]=R[18]=R[22]=0;
    f_80040DAC(); /* CD_cw after the prior-command sync has completed. */
    assert(psx_next == 0x80037d98); /* Waiting begins with VSync(-1). */
    assert(PSX_RAM[0x5c29c] == 0);
}
int main(void) {
    assert(irq_en == 0 && irq_fl == 0 && pend_n == 0);
    guest_fixture(); guest_init_prefix(); guest_issue_nop();
    assert(!irq_count && !dispatch_count && !irq_fl && pend_n == 1);
    cd_vblank();
    assert(irq_fl == 3 && !irq_count && PSX_RAM[0x5c29c] == 0);
    /* This characterizes why an unprepared EXE handoff waits for timeout. */
    cd_vblank();
    assert(irq_fl == 3 && !irq_count && PSX_RAM[0x5c29c] == 0);

    /* Fresh controller fixture; the explicit handoff is the only change. */
    irq_fl=0; pend_n=0; resp_i=resp_n=0; index_reg=0;
    guest_fixture();
    cd_boot_handoff();
    assert(!irq_fl && !pend_n && !resp_n && !irq_count && !reading && !mode);
    guest_init_prefix(); guest_issue_nop();
    assert(!irq_count && !dispatch_count && !irq_fl && pend_n == 1);
    cd_vblank();
    assert(irq_count == 1 && dispatch_count == 1);
    assert(!irq_fl && !pend_n && PSX_RAM[0x5c29c] == 2);
    assert(PSX_RAM[0x7bec0] == 2); /* Motor-on status reached guest response. */

    /* A later command remains deferred, and guest masking is not undone. */
    guest_issue_nop();
    assert(irq_count == 1 && !irq_fl && pend_n == 1);
    cd_vblank();
    assert(irq_count == 2 && PSX_RAM[0x5c29c] == 2);
    cd_write_reg(0,1); cd_write_reg(2,0); cd_write_reg(0,0);
    cd_command(0x0a);
    assert(irq_en == 0 && pend_n == 2);
    cd_vblank();
    assert(irq_count == 2 && irq_fl == 3 && pend_n == 1 && irq_en == 0);
    puts("post-BIOS handoff completes compiled guest Nop without bypassing delay or later masks");
}
