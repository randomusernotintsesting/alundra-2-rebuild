/* Standalone replay of logged menu rectangles against retained VRAM.
 * Compile without SDL or generated guest code; no app/card/source writes.
 * cc -O2 -Iport/src port/tests/diagnose_hd_art_throughput.c port/src/hd_art.c -o /tmp/a2-art-bench
 * /tmp/a2-art-bench VRAM.bin primitive.log frame iterations
 */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../src/hd_art.h"
static uint64_t preparations, sample_calls, candidates;
static double prepare_seconds;
static double now(void) {
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec + t.tv_nsec * 1e-9;
}
static unsigned measured_prepare(const A2HDArt *a,unsigned n,const uint16_t *v,
    uint32_t p,int u0,int v0,int u1,int v1,const A2HDArt **out,unsigned cap) {
    double t=now();
    unsigned count=a2_hd_art_prepare(a,n,v,p,u0,v0,u1,v1,out,cap);
    prepare_seconds+=now()-t;preparations++;candidates+=count;
    return count;
}
static int measured_sample(const A2HDArt *const *a,unsigned n,const uint16_t *v,
    uint32_t c,int u,int y,A2HDArtSample *out) {
    sample_calls++;
    return a2_hd_art_sample(a,n,v,c,u,y,out);
}
#define A2_HD_FONTS 1
#define A2_HD_ART 1
#define a2_hd_art_prepare measured_prepare
#define a2_hd_art_sample measured_sample
#include "../src/gpu.c"
#undef a2_hd_art_prepare
#undef a2_hd_art_sample
#include "../src/hd_font.c"
#include "../src/hd_ui.c"
uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
uint32_t psx_frame_no,gpu_flips,a2_ramwatch;
void psx_mmio_write(uint32_t p,uint32_t v,int s){(void)p;(void)v;(void)s;abort();}
void a2_ramwatch_hit(uint32_t p,uint32_t v,int s){(void)p;(void)v;(void)s;abort();}
void psx_vblank_tick(void){}
uint32_t psx_mmio_read(uint32_t p,int s){(void)p;(void)s;return 0;}
int a2_modelcap_active(void){return 0;}
FILE *a2_modelcap_file(void){return NULL;}
typedef struct { int c,tex,x,y,w,h,u,v,page,mode,clut,col; } Rect;
static Rect rects[1024];
static unsigned rect_count;
static uint16_t initial[1024*512];
static uint32_t pack(int x,int y){return (uint16_t)x|((uint32_t)(uint16_t)y<<16);}
static void draw(void) {
    for(unsigned i=0;i<rect_count;i++) {
        const Rect *r=&rects[i];
        /* Captured Settings background packet environment, verified in
         * frame5399 RAM at800F6474; all other captured rectangles follow
         * the E2 reset. This is a specific diagnostic, not a GP0 trace loader. */
        gpu_gp0(0xe2000000u|((r->w==624 && r->h==64 && r->u==224 && r->v==192)?0x0c731cu:0));
        gpu_gp0(0xe1000000u|(unsigned)r->page);
        gpu_gp0(((unsigned)r->c<<24)|(unsigned)r->col);
        gpu_gp0(pack(r->x,r->y));
        if(r->tex)gpu_gp0(((unsigned)r->clut<<16)|((unsigned)r->v<<8)|(unsigned)r->u);
        if(!(r->c&0x18))gpu_gp0(pack(r->w,r->h));
    }
}
static uint64_t hash_words(const uint16_t *p,size_t n) {
    uint64_t h=1469598103934665603ull;
    for(size_t i=0;i<n;i++)h=(h^p[i])*1099511628211ull;
    return h;
}
int main(int argc,char **argv) {
    if(argc!=5){fprintf(stderr,"VRAM.bin primitive.log frame iterations\n");return 2;}
    int target=atoi(argv[3]),iterations=atoi(argv[4]);
    assert(iterations>0);
    FILE *f=fopen(argv[1],"rb");assert(f);
    assert(fread(initial,sizeof initial,1,f)==1);fclose(f);
    f=fopen(argv[2],"r");assert(f);char line[2048];
    while(fgets(line,sizeof line,f)) {
        Rect r;int frame;
        if(sscanf(line,"rect: f=%d c=%x tex=%d xy=%d,%d wh=%dx%d u,v=%d,%d tpage=%x(mode%d) clut=%x col=%x",
            &frame,&r.c,&r.tex,&r.x,&r.y,&r.w,&r.h,&r.u,&r.v,&r.page,&r.mode,&r.clut,&r.col)==13 && frame==target) {
            assert(rect_count<1024);rects[rect_count++]=r;
        }
    }
    fclose(f);assert(rect_count);
    setenv("A2_HDUI","1",1);gpu_set_ir(3);gpu_gp1(0);gpu_set_filter(0);
    memcpy(GPU_VRAM,initial,sizeof initial);
    for(int y=0;y<512*3;y++)for(int x=0;x<1024*3;x++)
        *shadow_px(x,y)=initial[(y/3)*1024+x/3];
    gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|319|(479<<10));
    gpu_gp0(0xe2000000);gpu_gp0(0xe5000000);
    draw();preparations=sample_calls=candidates=0;prepare_seconds=0;
    double t=now();for(int i=0;i<iterations;i++)draw();double elapsed=now()-t;
    printf("assets=%u rects=%u iterations=%d total_ms/frame=%.3f art_prepare_ms/frame=%.3f "
           "prepare/frame=%.1f candidates/frame=%.1f art_sample/frame=%.1f native=%016llx fine=%016llx\n",
        a2_hd_art_asset_count,rect_count,iterations,elapsed*1000/iterations,
        prepare_seconds*1000/iterations,(double)preparations/iterations,
        (double)candidates/iterations,(double)sample_calls/iterations,
        (unsigned long long)hash_words(GPU_VRAM,1024*512),
        (unsigned long long)hash_words(SHADOW,1024*512*9));
    return 0;
}
