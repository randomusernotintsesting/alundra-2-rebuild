/* Real GP0 address transport, complete-primitive gating and unchanged native
 * rendering. No SDL, game data, save files or screen-XY lookup. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define A2_WORLD_PRECISION 1
#include "../src/world_precision.h"
#include "../src/gpu.c"

uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t psx_frame_no, gpu_flips, a2_ramwatch;
void psx_mmio_write(uint32_t p,uint32_t v,int s){(void)p;(void)v;(void)s;abort();}
uint32_t psx_mmio_read(uint32_t p,int s){(void)p;(void)s;return 0;}
void a2_ramwatch_hit(uint32_t p,uint32_t v,int s){(void)p;(void)v;(void)s;}
void psx_vblank_tick(void){}
int a2_modelcap_active(void){return 0;}
FILE *a2_modelcap_file(void){return NULL;}

static const uint32_t xy[4]={0x000a000a,0x000a0014,0x0014000a,0x00140014};
static uint16_t native_reference[1024*512], fine_reference[1024*512*4];

static void seed(uint32_t base) {
    uint64_t object=world_precision_begin_object();
    uint32_t src[4],dst[4];
    for(unsigned i=0;i<4;i++) {
        src[i]=0x1f800100+i*16; dst[i]=base+4+i*4;
        world_precision_vertex v;
        world_precision_gte_push(xy[i],((int64_t)(xy[i]&65535)<<16)+16384,
            ((int64_t)(xy[i]>>16)<<16)+32768,100.0,1);
        assert(world_precision_gte_read(14,xy[i],&v));
        world_precision_record(src[i],xy[i],object,&v);
    }
    assert(world_precision_emit(dst,xy,src,4,object));
}

static void clear_surfaces(void) {
    memset(GPU_VRAM,0,sizeof GPU_VRAM);
    memset(SHADOW,0,1024*512*4*sizeof *SHADOW);
}

static void submit(uint32_t base,int untracked) {
    gpu_gp0_at(0x280000ff,base);
    for(unsigned i=0;i<4;i++) {
        if(untracked==(int)i) gpu_gp0(xy[i]);
        else gpu_gp0_at(xy[i],base+4+i*4);
    }
}

int main(void) {
    world_precision_configure(1);
    gpu_set_ir(2);gpu_gp1(0);
    gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|319|(239<<10));
    seed(0x80090000);
    clear_surfaces();
    submit(0x80090000,-1);
    assert(world_primitive_valid);
    for(unsigned i=0;i<4;i++) {
        assert(world_vertices[i].native_word==xy[i]);
        assert(world_vertices[i].source_address==0x1f800100+i*16);
        assert(world_vertices[i].x==(double)(xy[i]&65535)+0.25);
        assert(world_vertices[i].y==(double)(xy[i]>>16)+0.5);
    }
    memcpy(native_reference,GPU_VRAM,sizeof native_reference);
    memcpy(fine_reference,SHADOW,sizeof fine_reference);
    for(int lane=0;lane<4;lane++) {
        clear_surfaces();submit(0x80090000,lane);
        assert(!world_primitive_valid);
        assert(!memcmp(native_reference,GPU_VRAM,sizeof native_reference));
        /* Trace/provenance stage must not change even the fine output yet. */
        assert(!memcmp(fine_reference,SHADOW,sizeof fine_reference));
    }
    submit(0xa0290000,-1); /* KSEG + physical RAM mirror resolves same packet. */
    assert(world_primitive_valid);
    seed(0x800a0000);
    gpu_gp0_at(0x280000ff,0x80090000);
    for(unsigned i=0;i<4;i++)gpu_gp0_at(xy[i],(i<2?0x80090000:0x800a0000)+4+i*4);
    assert(!world_primitive_valid); /* Cannot assemble different packet epochs. */
    world_precision_invalidate(0x80090005,1);
    submit(0x80090000,-1);
    assert(!world_primitive_valid); /* Identical partial overwrite loses provenance. */
    seed(0x80090000);
    gpu_gp0_at(0x280000ff,0x80090000);
    gpu_gp0_at(xy[0],0x80090004);
    /* A queued XY word belongs to its ingress generation. Rebuilding the
     * same addresses with identical native XY must not tag it retroactively. */
    seed(0x80090000);
    for(unsigned i=1;i<4;i++) gpu_gp0_at(xy[i],0x80090004+i*4);
    assert(!world_primitive_valid);
    submit(0x80090000,-1);
    assert(world_primitive_valid); /* The rebuilt packet works when read whole. */
    gpu_gp0_at(0x280000ff,0x80090000);
    gpu_gp0_at(xy[0],0x80090004);
    world_precision_invalidate(0x80090004,4);
    for(unsigned i=1;i<4;i++) gpu_gp0_at(xy[i],0x80090004+i*4);
    assert(!world_primitive_valid); /* Ingress snapshots must also remain live. */
    seed(0x80090000);
    gpu_gp0_at(0x280000ff,0x80090000);
    gpu_gp0_at(xy[0],0x80090004);
    gpu_gp1(0x01000000); /* Reset packet assembly with stale address entries. */
    gpu_gp0(0x280000ff);
    for(unsigned i=0;i<4;i++)gpu_gp0(xy[i]);
    assert(!world_primitive_valid);
    puts("PASS: exact GP0 word addresses, complete provenance, native/fine trace equivalence, reset and stale/mixed fallback");
    return 0;
}
