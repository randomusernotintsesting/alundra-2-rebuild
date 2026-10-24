/* Real GP0 commands: replacement changes SHADOW only, including alpha0/black. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/hd_portraits.h"
static uint8_t source[2][40*48],rgba[2][320*384*4];
static uint16_t fixture_colors[256];
static A2HDPortrait a2_hd_portraits_assets[2];
static unsigned a2_hd_portraits_asset_count=2;
#define A2_HD_FONTS 1
#define A2_HD_PORTRAITS 1
#define A2_HD_PORTRAITS_TEST 1
#include "../src/gpu.c"
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
static uint16_t native[1024*512],fine[256*256];
static unsigned xy(unsigned x,unsigned y){return x|(y<<16);}
static void exact(unsigned x,unsigned y,uint16_t expected,const char *label){
    uint16_t got=gpu_display_px(x,y);
    if(got!=expected){fprintf(stderr,"%s (%u,%u): got %04x wanted %04x\n",label,x,y,got,expected);abort();}
}
static void upload(unsigned id){
    for(unsigned y=0;y<48;y++)for(unsigned x=0;x<40;x+=2)
        GPU_VRAM[(296+y)*1024+736+x/2]=source[id][y*40+x]|(source[id][y*40+x+1]<<8);
    for(unsigned p=0;p<256;p++)GPU_VRAM[507*1024+768+p]=fixture_colors[p];
}
static void setup(int enabled,unsigned id){
    setenv("A2_HDUI","1",1);setenv("A2_HD_PORTRAITS",enabled?"1":"0",1);
    gpu_gp1(0);memset(GPU_VRAM,0,sizeof GPU_VRAM);
    gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|127|(127<<10));
    gpu_gp0(0x02605050);gpu_gp0(0);gpu_gp0(xy(128,128));
    upload(id);gpu_gp0(0xe100009b);
}
static void rect(unsigned u,unsigned v,unsigned w,unsigned h,unsigned col,int semi){
    gpu_gp0((semi?0x66000000:0x64000000)|col);gpu_gp0(xy(8,8));
    gpu_gp0((0x7ef0u<<16)|u|(v<<8));gpu_gp0(xy(w,h));
}
static void quad(int flip,unsigned col,int semi,int gouraud){
    gpu_gp0((gouraud?0x3c000000:semi?0x2e000000:0x2c000000)|col);
    for(unsigned i=0;i<4;i++){
        if(i && gouraud)gpu_gp0(i==1?0x808080:col);
        gpu_gp0(xy(8+(i&1)*40,8+(i>>1)*48));
        gpu_gp0((i==0?0x7ef0u<<16:i==1?0x9bu<<16:0)|
            (flip?104-(i&1)*40:64+(i&1)*40)|((40+(i>>1)*48)<<8));
    }
}
static void save_native(void){memcpy(native,GPU_VRAM,sizeof native);}
static void same_native(void){assert(!memcmp(native,GPU_VRAM,sizeof native));}
static void save_fine(void){for(unsigned y=0;y<256;y++)for(unsigned x=0;x<256;x++)fine[y*256+x]=gpu_display_px(x,y);}
static void same_fine(void){for(unsigned y=0;y<256;y++)for(unsigned x=0;x<256;x++)exact(x,y,fine[y*256+x],"fallback");}
static void initialize(void){
    fixture_colors[1]=0x001f;fixture_colors[2]=0x03e0;
    memset(source,1,sizeof source);source[1][40*48-1]=2;
    /* HD red appears where the native texel is transparent. */
    source[0][2]=0;
    for(unsigned id=0;id<2;id++){
        a2_hd_portraits_assets[id]=(A2HDPortrait){320,384,source[id],fixture_colors,rgba[id]};
        for(unsigned y=0;y<384;y++)for(unsigned x=0;x<320;x++){
            const uint8_t colors[6][4]={{248,248,248,0},{0,0,0,255},{248,0,0,255},
                {248,0,0,128},{160,80,240,255},{160,80,240,128}};
            memcpy(rgba[id]+(y*320+x)*4,id?(uint8_t[]){0,248,0,255}:colors[(x/8)%6],4);
        }
    }
}
static void rgba_and_semi(void){
    for(unsigned scale=2;scale<=4;scale++)for(int semi=0;semi<=1;semi++){
        gpu_set_ir((int)scale);
        setup(0,0);rect(64,40,40,48,0x808080,semi);save_native();
        setup(1,0);rect(64,40,40,48,0x808080,semi);same_native();
        unsigned x=8*scale,y=8*scale;
        exact(x,y,0x314a,"alpha0 retains prior background, suppresses old portrait");
        exact(x+scale,y,0,"opaque RGB black stays opaque");
        exact(x+2*scale,y,0x001f,"opaque red over native transparent texel");
        exact(x+3*scale,y,0x18b4,"partial red blends once in RGB8");
        exact(x+4*scale,y,0x7954,"opaque RGB8 color");
        exact(x+5*scale,y,0x554f,"partial RGB8 color");
        exact(x-1,y,0x314a,"left edge");exact(x+40*scale,y,0x314a,"right edge");
    }
    gpu_set_ir(4);
    setup(0,0);quad(0,0x808080,1,0);save_native();
    setup(1,0);quad(0,0x808080,1,0);same_native();
    exact(32,32,0x314a,"0x2e alpha0");exact(36,32,0,"0x2e black");
    exact(40,32,31,"0x2e STP-clear source is opaque");
    exact(44,32,0x18b4,"0x2e explicit partial alpha only");
    /* Unset switch defaults on; A2_HDUI remains the parent setting. */
    setup(1,0);unsetenv("A2_HD_PORTRAITS");rect(64,40,40,48,0x808080,0);exact(36,32,0,"default on");
    setup(0,0);rect(64,40,40,48,0x808080,0);save_fine();
    setup(1,0);setenv("A2_HDUI","0",1);rect(64,40,40,48,0x808080,0);same_fine();
}
static void modulation_and_order(void){
    setup(0,0);rect(64,40,40,48,0x408040,1);save_native();
    setup(1,0);rect(64,40,40,48,0x408040,1);same_native();
    exact(40,32,15,"red modulation");exact(48,32,0x3d4a,"RGB modulation");
    setup(0,0);quad(0,0x404040,0,1);save_native();
    setup(1,0);quad(0,0x404040,0,1);same_native();
    exact(40,32,16,"Gouraud RGB modulation");
    /* Two identical alpha layers must blend against the previous result. */
    setup(1,0);rect(64,40,40,48,0x808080,0);rect(64,40,40,48,0x808080,0);
    exact(44,32,0x0c59,"ordered alpha compositing");
    gpu_gp0(0x600000f8);gpu_gp0(xy(8,8));gpu_gp0(xy(40,48));
    exact(32,32,31,"following ordinary primitive resets portrait");
}
static void identity_and_fallback(void){
    for(unsigned kind=0;kind<4;kind++)for(int enabled=0;enabled<=1;enabled++){
        setup(enabled,0);
        if(kind==0)GPU_VRAM[343*1024+755]^=0x100; /* Unsampled index. */
        if(kind==1)GPU_VRAM[507*1024+1023]^=1; /* Complete CLUT identity. */
        if(kind==2)gpu_gp0(0xe100001b); /* 4bpp. */
        if(kind==3)a2_hd_portraits_asset_count=0;
        rect(64,40,40,48,0x808080,0);
        if(!enabled){save_native();save_fine();}else{same_native();same_fine();}
        a2_hd_portraits_asset_count=2;
    }
    setup(1,0);rect(64,40,40,48,0x808080,0);exact(36,32,0,"first source");
    upload(1);rect(64,40,40,48,0x808080,0);exact(36,32,0x03e0,"same page switches identity");
    upload(0);rect(64,40,40,48,0x808080,0);exact(36,32,0,"switch back");
    gpu_set_ir(1);
    setup(0,0);rect(64,40,40,48,0x808080,0);save_native();save_fine();
    setup(1,0);rect(64,40,40,48,0x808080,0);same_native();same_fine();
    gpu_set_ir(4);
}
static void bounds_windows_mirroring(void){
    setup(1,0);gpu_gp0(0xe3000000|9|(9<<10));gpu_gp0(0xe4000000|11|(11<<10));
    rect(64,40,40,48,0x808080,0);
    exact(35,36,0x314a,"left clip");exact(36,35,0x314a,"top clip");
    exact(36,36,0,"clip retains UV position");exact(48,36,0x314a,"right clip");exact(36,48,0x314a,"bottom clip");
    unsigned window=8|(5<<5)|(8<<10)|(5<<15);
    for(int enabled=0;enabled<=1;enabled++){
        setup(enabled,0);gpu_gp0(0xe2000000|window);rect(0,0,6,1,0x808080,1);
        if(!enabled)save_native();else same_native();
    }
    exact(32,32,0x314a,"texture window alpha0");exact(36,32,0,"window keeps subpixels");exact(40,32,31,"window maps into portrait");
    setup(0,0);quad(1,0x808080,1,0);save_native();
    setup(1,0);quad(1,0x808080,1,0);same_native();
    exact(191,32,0x314a,"mirrored alpha0");exact(187,32,0,"mirrored black");exact(183,32,31,"mirrored red");
}
int main(void){
    initialize();rgba_and_semi();modulation_and_order();identity_and_fallback();bounds_windows_mirroring();
    gpu_set_ir(1);puts("HD portraits GPU: native VRAM identical; RGBA, semi, modulation, order, identity, clip, mirror, window, IR1–4 passed");
}
