/* Bounded real GP0 triangle throughput probe; no SDL or user files.
 * cc -O3 -Iport/src port/tests/diagnose_gpu_triangles.c -o /tmp/a2-tri-bench
 * Optional -DA2_TRIANGLE_GPU_SOURCE='"/absolute/frozen/gpu.c"' builds baseline.
 */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef A2_TRIANGLE_GPU_SOURCE
#define A2_TRIANGLE_GPU_SOURCE "../src/gpu.c"
#endif
#include A2_TRIANGLE_GPU_SOURCE
uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
uint32_t psx_frame_no,gpu_flips;
void psx_vblank_tick(void) {}
uint32_t psx_mmio_read(uint32_t p,int n) {(void)p;(void)n;return 0;}
int a2_modelcap_active(void) {return 0;}
FILE *a2_modelcap_file(void) {return NULL;}
static double now(void) {
    struct timespec ts;clock_gettime(CLOCK_MONOTONIC,&ts);
    return ts.tv_sec+ts.tv_nsec*1e-9;
}
static uint64_t hash(const uint16_t *p,size_t n) {
    uint64_t h=1469598103934665603ull;
    for(size_t i=0;i<n;i++)h=(h^p[i])*1099511628211ull;
    return h;
}
static void draw(unsigned cmd,int small) {
    unsigned coords[4]={0,320,224u<<16,(224u<<16)|320};
    if(small){coords[0]=20|(15u<<16);coords[1]=130|(37u<<16);
        coords[2]=45|(118u<<16);coords[3]=184|(150u<<16);}
    unsigned colors[]={0x3050e0,0xc0a020,0x40e080,0xf06090};
    for(unsigned i=0;i<4;i++) {
        if(!i||(cmd&16))gpu_gp0((!i?cmd<<24:0)|colors[i]);
        gpu_gp0(coords[i]);
        if(cmd&4)gpu_gp0((i&1?255:0)|(i&2?255u<<8:0)|
            (i==0?480u<<22:i==1?0x0108u<<16:0));
    }
}
int main(int argc,char **argv) {
    int iterations=argc>1?atoi(argv[1]):120;assert(iterations>0);
    gpu_set_ir(4);gpu_set_filter(0);gpu_gp1(0);
    gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|319|(223<<10));
    gpu_gp0(0xe1000128);
    for(unsigned i=0;i<1024*512;i++)GPU_VRAM[i]=(uint16_t)(i*73u+(i>>7));
    for(unsigned i=0;i<(unsigned)IR_W*IR_H;i++)SHADOW[i]=(uint16_t)(i*37u+(i>>5));
    for(int small=0;small<2;small++)for(unsigned cmd=0x38;cmd<=0x3e;cmd+=2) {
        double t=now();
        for(int i=0;i<iterations;i++)draw(cmd,small);
        double ms=(now()-t)*1000/iterations;
        printf("cmd=%02X small=%d IR4 ms=%.6f native=%016llx fine=%016llx\n",
            cmd,small,ms,(unsigned long long)hash(GPU_VRAM,1024*512),
            (unsigned long long)hash(SHADOW,(size_t)IR_W*IR_H));
    }
    gpu_set_ir(1);return 0;
}
