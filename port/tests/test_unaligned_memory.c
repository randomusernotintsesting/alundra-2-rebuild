/* The ship door copies a RotMatrix from scratchpad with LWL/LWR. Mapping
 * those loads to RAM collapses the door; stores must preserve the same split. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "psx_rt.h"

uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t a2_ramwatch;
static unsigned watch_hits;
void a2_ramwatch_hit(uint32_t address, uint32_t value, int size) {
    (void)address; (void)value; (void)size;
    watch_hits++;
}

static void word_is(const char *operation, uint32_t address, unsigned lane,
                    uint32_t got, uint32_t want) {
    if (got != want) {
        fprintf(stderr, "%s at %08X lane%u: got %08X, wanted %08X\n",
                operation, address, lane, got, want);
        exit(1);
    }
}

static uint32_t word_at(const uint8_t *bytes) {
    uint32_t word;
    memcpy(&word, bytes, sizeof word);
    return word;
}

static void merge_cases(uint32_t address, int scratch) {
    static const uint32_t left_load[] = {
        0x11BBCCDD, 0x2211CCDD, 0x332211DD, 0x44332211};
    static const uint32_t right_load[] = {
        0x44332211, 0xAA443322, 0xAABB4433, 0xAABBCC44};
    static const uint32_t left_store[] = {
        0x443322AA, 0x4433AABB, 0x44AABBCC, 0xAABBCCDD};
    static const uint32_t right_store[] = {
        0xAABBCCDD, 0xBBCCDD11, 0xCCDD2211, 0xDD332211};
    static const uint8_t initial[] = {0x11,0x22,0x33,0x44};
    const unsigned offset = address & (scratch ? 0x3FF : 0x1FFFFF);
    uint8_t *memory = scratch ? PSX_SCRATCH : PSX_RAM;
    uint8_t *other = scratch ? PSX_RAM : PSX_SCRATCH;
    const size_t other_size = scratch ? sizeof PSX_RAM : sizeof PSX_SCRATCH;
    for (unsigned lane=0; lane<4; lane++) {
        memset(PSX_RAM, 0x5A, sizeof PSX_RAM);
        memset(PSX_SCRATCH, 0x5A, sizeof PSX_SCRATCH);
        memcpy(memory+offset, initial, sizeof initial);
        a2_ramwatch = (address & 0x1FFFFC) | 1;
        watch_hits = 0;
        word_is("LWL", address,lane,lwl_(address+lane,0xAABBCCDD),left_load[lane]);
        word_is("LWR", address,lane,lwr_(address+lane,0xAABBCCDD),right_load[lane]);
        assert(word_at(memory+offset)==0x44332211);
        swl_(address+lane,0xAABBCCDD);
        word_is("SWL",address,lane,word_at(memory+offset),left_store[lane]);
        memcpy(memory+offset,initial,sizeof initial);
        swr_(address+lane,0xAABBCCDD);
        word_is("SWR",address,lane,word_at(memory+offset),right_store[lane]);
        for (size_t i=0; i<other_size; i++) assert(other[i]==0x5A);
        const size_t memory_size = scratch ? sizeof PSX_SCRATCH : sizeof PSX_RAM;
        if (offset) assert(memory[offset-1]==0x5A);
        if (offset+4<memory_size) assert(memory[offset+4]==0x5A);
        assert(watch_hits == (scratch ? 0u : 2u));
    }
}

static void door_matrix_copy(void) {
    /* A quarter-turn around Y, in the game's Q12 matrix format, followed
     * by the padding halfword copied by the original door callback. */
    static const int16_t rotation[10] = {0,0,-4096, 0,4096,0, 4096,0,0,0};
    memset(PSX_RAM,0,sizeof PSX_RAM);
    memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);
    memcpy(PSX_SCRATCH+0x90,rotation,sizeof rotation);
    a2_ramwatch=0;
    for (unsigned i=0; i<sizeof rotation; i+=4) {
        uint32_t value=lwl_(0x1F800093+i,0xFEDCBA98);
        value=lwr_(0x1F800090+i,value);
        swl_(0x801EC663+i,value);
        swr_(0x801EC660+i,value);
    }
    assert(memcmp(PSX_RAM+0x1EC660,rotation,sizeof rotation)==0);
    for (unsigned i=0x90; i<0x90+sizeof rotation; i++) assert(PSX_RAM[i]==0);
    assert(memcmp(PSX_SCRATCH+0x90,rotation,sizeof rotation)==0);
}

int main(void) {
    /* Scratchpad physical, cached, and uncached aliases. Exercise the first
     * word, observed matrix location and final complete word of the 1 KiB. */
    const uint32_t scratch[] = {0x1F800000,0x9F800000,0xBF800000,
                                0x1F800090,0x9F800090,0xBF800090,
                                0x1F8003FC,0x9F8003FC,0xBF8003FC};
    for(unsigned i=0; i<sizeof scratch/sizeof scratch[0]; i++) merge_cases(scratch[i],1);
    const uint32_t ram[] = {0x00000090,0x00200090,0x00400090,0x00600090,
                            0x80000090,0x80200090,0xA0000090,0xA0600090,
                            0x001FFFFC,0x807FFFFC,0xA07FFFFC,
                            /* The first word outside scratch keeps the
                             * existing unaligned-helper RAM fallback. */
                            0x1F800400,0x9F800400,0xBF800400};
    for(unsigned i=0; i<sizeof ram/sizeof ram[0]; i++) merge_cases(ram[i],0);
    door_matrix_copy();
    puts("PASS: unaligned merge lanes, scratchpad aliases/boundary, RAM mirrors and door matrix copy");
    return 0;
}
