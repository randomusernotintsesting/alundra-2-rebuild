/* Compile real generated segments; only HD host APIs are replaced.
 * cc -O1 -UNDEBUG -Iport/src -Iport/gen port/tests/test_hd_guest_hooks.c
 *    port/gen/scps_006.c port/gen/scps_010.c port/gen/scps_011.c
 *    -o /tmp/a2-hd-guest-hooks
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "scps_decls.h"
#include "hd_font.h"

uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t R[32], HI, LO, psx_next, psx_work, a2_ramwatch;
int psx_bb_budget=1000000;
static int enabled, calls, notes, seen_original;
static uint32_t seen_token, note_args[4];
static uint8_t saved_ram[PSX_RAM_SIZE];
static uint32_t entry_regs[32];

int a2_hd_guest_advance(uint32_t token,int original) {
    ++calls;seen_token=token;seen_original=original;
    return enabled ? 9 : original;
}
void a2_hd_guest_note(uint32_t token,uint32_t base,uint32_t u,uint32_t v) {
    ++notes;note_args[0]=token;note_args[1]=base;note_args[2]=u;note_args[3]=v;
    /* Observer must be called before guest prologue or any guest writes. */
    assert(!memcmp(R,entry_regs,sizeof R));
    assert(!memcmp(PSX_RAM,saved_ram,sizeof PSX_RAM));
}
void psx_break(uint32_t n) {(void)n;abort();}
void psx_trap(uint32_t n) {(void)n;abort();}
void psx_bb_fire(void) {abort();}
uint32_t psx_mmio_read(uint32_t p,int s) {(void)p;(void)s;abort();}
void psx_mmio_write(uint32_t p,uint32_t v,int s) {(void)p;(void)v;(void)s;abort();}
void a2_ramwatch_hit(uint32_t p,uint32_t v,int s) {(void)p;(void)v;(void)s;abort();}

static void dispatch(void) {
    switch(psx_next) {
    case 0x8001f9f4:f_8001F9F4();break;
    case 0x8001fa6c:f_8001FA6C();break;
    case 0x8001fa94:f_8001FA94();break;
    case 0x8001fac4:f_8001FAC4();break;
    case 0x8001fb18:f_8001FB18();break;
    case 0x80029c4c:f_80029C4C();break;
    case 0x80029f34:f_80029F34();break;
    default:fprintf(stderr,"unexpected %08x\n",psx_next);abort();
    }
}
static void width_case(unsigned mode,uint32_t token,unsigned stored,int want) {
    uint32_t disabled_regs[32];
    for(enabled=0;enabled<=1;enabled++) {
        memset(PSX_RAM,0x5a,sizeof PSX_RAM);memset(R,0,sizeof R);
        sw_(0x800640f0,mode);sh_(0x80065b50,12);sw_(0x8014c880,0x80180000);
        unsigned byte=token&255;if(byte<32)byte=32;
        sb_(0x80065b60+(byte-32)*49+48,stored);
        sb_(0x80180000+(byte-32)*73+72,stored);
        memcpy(saved_ram,PSX_RAM,sizeof PSX_RAM);
        R[4]=token;R[29]=0x801ff000;R[31]=0xffaaffaa;
        calls=0;seen_token=0;psx_next=0x8001f9f4;
        unsigned steps=0;
        while(psx_next!=0xffaaffaa) {assert(++steps<12);dispatch();}
        assert(calls==1 && seen_token==token && seen_original==want);
        assert(R[2]==(uint32_t)(enabled?9:want));
        assert(R[3]==(uint32_t)want && R[29]==0x801ff000 && R[31]==0xffaaffaa);
        if (!enabled) memcpy(disabled_regs,R,sizeof R);
        else for (unsigned reg=0;reg<32;reg++)
            if (reg!=2) assert(R[reg]==disabled_regs[reg]);
        /* Original routine/helper writes only its frame; no bank/VRAM/MMIO. */
        assert(!memcmp(PSX_RAM,saved_ram,0x1ff000-40));
        assert(!memcmp(PSX_RAM+0x1ff000,saved_ram+0x1ff000,PSX_RAM_SIZE-0x1ff000));
    }
}
int main(void) {
    /* Main direct-return branch plus every replicated helper continuation. */
    width_case(0,0x0030,8,12);width_case(2,0x0030,8,12);
    width_case(0,0xabcdff54,7,7);width_case(0,0xff54,0,6);width_case(0,0xff54,13,6);
    width_case(1,0xff54,7,7);width_case(1,0xff54,0,0);width_case(1,0xff20,0,6);
    width_case(2,0xabcdff54,6,6);width_case(2,0xff54,0,6);width_case(2,0xff54,255,6);
    width_case(3,0xff54,6,6);width_case(3,0xff54,13,0);width_case(3,0xff20,0,6);
    memset(R,0,sizeof R);R[4]=0xff54;R[5]=896;R[6]=120;R[7]=24;
    R[29]=0x801ff000;R[31]=0xffaaffaa;sw_(0x800640f0,2);sh_(0x80065b50,12);
    memcpy(entry_regs,R,sizeof R);memcpy(saved_ram,PSX_RAM,sizeof PSX_RAM);
    notes=0;f_8001FECC();
    assert(notes==1 && note_args[0]==0xff54 && note_args[1]==896 && note_args[2]==120 && note_args[3]==24);
    assert(psx_next==0x80029e48 && R[29]==0x801ff000-368);
    assert(R[16]==120 && R[17]==896 && R[18]==24);
    assert(!memcmp(PSX_RAM,saved_ram,0x1ff000-368));
    puts("HD guest hooks: all width paths, token identity, observer and unchanged banks passed");
    return 0;
}
