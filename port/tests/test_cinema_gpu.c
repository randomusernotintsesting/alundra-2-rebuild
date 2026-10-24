/* Real GP0 source/core isolation and additional geometry fixture. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int allocation_failure;
static void *fixture_calloc(size_t n,size_t size) {
    if(allocation_failure)return NULL;return calloc(n,size);
}
#define calloc fixture_calloc
#define A2_CINEMA_EXPANSION 1
#include "../src/gpu.c"
#undef calloc
#include "../src/frame_compose.c"
uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
uint32_t psx_frame_no,gpu_flips;
void psx_vblank_tick(void) {}
uint32_t psx_mmio_read(uint32_t p,int n) {(void)p;(void)n;return 0;}
int a2_modelcap_active(void) {return 0;}
FILE *a2_modelcap_file(void) {return NULL;}
static uint16_t baseline[1024*512];
static void cmd(uint32_t v) {gpu_gp0(v);}
static uint32_t xy(int x,int y) {return (uint16_t)x|((uint32_t)(uint16_t)y<<16);}
static void picture(int by) {
    cmd(0xe5000000u|((unsigned)by<<11));
    cmd(0xe3000000u|((unsigned)by<<10));cmd(0xe4000000u|319|((unsigned)(by+171)<<10));
}
static void seal(int by) {cmd(0xe4000000u|319|((unsigned)(by+215)<<10));}
static void geometry(void) {
    /* A large red quad spans both extra strips and the complete original core. */
    cmd(0x280000f8);cmd(xy(0,-30));cmd(xy(320,-30));cmd(xy(0,205));cmd(xy(320,205));
}
static void caption(int by) {
    cmd(0x60000000);cmd(xy(0,172));cmd(xy(320,44));
    for(int y=0;y<16;y++)GPU_VRAM[y*1024+640]=0x0123;
    unsigned clut=(480<<6)|60;
    GPU_VRAM[480*1024+960]=0;GPU_VRAM[480*1024+961]=0x8000;
    GPU_VRAM[480*1024+962]=0x4210;GPU_VRAM[480*1024+963]=0x7fff;
    cmd(0xe100000a);cmd(0x64808080);cmd(xy(20,174));cmd(clut<<16);cmd(xy(4,16));
    (void)by;
}
int main(void) {
    int left=0,right=1279;
    assert(!cinema_span(-((int64_t)1<<45),4,1,&left,&right));assert(left==0);
    for(int scale=1;scale<=4;scale++)for(int by=0;by<=256;by+=256) {
        gpu_set_ir(scale);gpu_gp1(0);memset(PSX_RAM,0,sizeof PSX_RAM);
        PSX_RAM[0x811d8]=5;PSX_RAM[0x79e9c]=1;memset(GPU_VRAM,0,sizeof GPU_VRAM);
        gpu_set_cinema_expansion(0);picture(by);geometry();seal(by);
        memcpy(baseline,GPU_VRAM,sizeof baseline);
        memset(GPU_VRAM,0,sizeof GPU_VRAM);gpu_set_cinema_expansion(1);
        picture(by);assert(!gpu_cinema_expansion_ready(by));geometry();seal(by);
        assert(!memcmp(baseline,GPU_VRAM,sizeof baseline));
        assert(gpu_cinema_expansion_ready(by));
        for(int y=-22*scale;y<194*scale;y++) {
            const uint16_t *r=gpu_cinema_extra_row(by,y);
            if(y>=0&&y<172*scale) {assert(!r);continue;}
            assert(r);for(int x=0;x<320*scale;x++)assert(r[x]==31);
        }
        assert(!gpu_cinema_extra_row(by,-22*scale-1));assert(!gpu_cinema_extra_row(by,194*scale));
        assert(!gpu_cinema_expansion_ready(128));
        caption(by);
        const uint8_t *alpha=gpu_cinema_subtitle_alpha_row(by,0);assert(alpha);
        for(int x=20*scale;x<23*scale;x++)assert(alpha[x]==255);
        assert(alpha[23*scale]==0);
        A2CinemaRaster r={0,by,320,216,0,12,320,240,1,5};
        A2CinemaLayout l={0,172,34,174,32,207};
        int pitch=320*scale+7,height=240*scale;
        uint32_t *out=malloc((size_t)pitch*height*4);assert(out);
        for(int n=0;n<pitch*height;n++)out[n]=0x12345678;
        assert(a2_compose_cinema_expanded(out,pitch,scale,&r,&l));
        assert(out[0]==0xff000000);assert(out[12*scale*pitch]==0xfff80000);
        assert(out[228*scale*pitch]==0xff000000);
        int text=207*scale*pitch;
        assert(out[text+20*scale]==0xfff8f8f8);
        assert(out[text+21*scale]==0xff808080);
        assert(out[text+22*scale]==0xff000000); /* Opaque black is preserved. */
        assert(out[text+23*scale]==0xfff80000); /* Transparent exposes scene. */
        for(int y=0;y<height;y++)for(int x=320*scale;x<pitch;x++)assert(out[y*pitch+x]==0x12345678);
        /* Synthetic partial coverage exercises premultiplied glyph blending
         * independently from texture sampling: half-white over full red. */
        cinema_alpha[by/256][24*scale]=128;
        if(scale==1)GPU_VRAM[(by+174)*1024+24]=0x4210;
        else SHADOW[((by+174)*scale)*IR_W+24*scale]=0x4210;
        assert(a2_compose_cinema_expanded(out,pitch,scale,&r,&l));
        assert(out[text+24*scale]==0xfffc8080);
        free(out);
        /* The original game's exact self-copy must not flash the bars. */
        cmd(0x80000000);cmd(xy(0,by));cmd(xy(0,by));cmd(xy(2,1));
        assert(gpu_cinema_expansion_ready(by));
        cmd(0x80000000);cmd(xy(640,0));cmd(xy(0,by));cmd(xy(2,1));
        assert(!gpu_cinema_expansion_ready(by));
        picture(by);geometry();seal(by);assert(gpu_cinema_expansion_ready(by));
        cmd(0x80000000);cmd(xy(640,0));cmd(xy(1000,by));cmd(xy(64,1));
        assert(!gpu_cinema_expansion_ready(by));
        picture(by);geometry();seal(by);assert(gpu_cinema_expansion_ready(by));
        cmd(0xe4000000u|319|((unsigned)(by+200)<<10));assert(!gpu_cinema_expansion_ready(by));
        picture(by);geometry();seal(by);gpu_gp1(0);assert(!gpu_cinema_expansion_ready(by));
        picture(by);
        Vtx a={-700,by+10,248,0,0,0,0},b={324,by+9,248,0,0,0,0},c={-700,by+182,248,0,0,0,0};
        WorldFineTriangle precise={{{-700*65536LL,(by+10)*65536LL},
            {324*65536LL,(by+10)*65536LL-1},{-700*65536LL,(by+182)*65536LL}}};
        cinema_triangle(a,b,c,0,0,0,&precise);seal(by);
        cmd(0x60000000);cmd(xy(0,172));cmd(xy(320,44));
        cmd(0xe1000020);cmd(0x62202020);cmd(xy(0,0));cmd(xy(320,216));
        assert(!gpu_cinema_expansion_ready(by)); /* Unverified subtitle-band fade. */
        gpu_set_cinema_expansion(0);assert(!gpu_cinema_expansion_ready(by));
    }
    gpu_gp1(0);gpu_set_cinema_expansion(1);
    picture(0);geometry();seal(0);assert(gpu_cinema_expansion_ready(0));
    picture(256);assert(gpu_cinema_expansion_ready(0));
    geometry();seal(256);assert(gpu_cinema_expansion_ready(0)&&gpu_cinema_expansion_ready(256));
    gpu_set_ir(1);gpu_gp1(0);gpu_set_cinema_expansion(1);
    allocation_failure=1;picture(0);geometry();seal(0);
    assert(!gpu_cinema_expansion_ready(0));allocation_failure=0;
    picture(0);geometry();seal(0);assert(gpu_cinema_expansion_ready(0));
    PSX_RAM[0x811d8]=4;assert(!gpu_cinema_expansion_ready(0));
    PSX_RAM[0x811d8]=5;assert(!gpu_cinema_expansion_ready(0));
    puts("cinema GPU strips, captions, failure/reset gates preserve native VRAM at IR1-4 and both buffers");return 0;
}
