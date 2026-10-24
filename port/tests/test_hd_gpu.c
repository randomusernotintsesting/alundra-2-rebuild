#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define A2_HD_FONTS 1
#define A2_HD_TEST_COUNT 1
#include "../src/gpu.c"
#include "../src/hd_font.c"
#include "../src/hd_ui.c"
uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t psx_frame_no, gpu_flips;
uint32_t a2_ramwatch;
void psx_mmio_write(uint32_t p,uint32_t v,int s) {(void)p;(void)v;(void)s;abort();}
void a2_ramwatch_hit(uint32_t p,uint32_t v,int s) {(void)p;(void)v;(void)s;abort();}
void psx_vblank_tick(void) {}
uint32_t psx_mmio_read(uint32_t p,int s) {(void)p;(void)s;return 0;}
int a2_modelcap_active(void) {return 0;}
FILE *a2_modelcap_file(void) {return NULL;}
static uint16_t native_pixels[12*24], coarse_fine[36*72];
static unsigned xy(unsigned x,unsigned y) {return x | (y<<16);}

static void draw_width(unsigned col, unsigned width) {
    gpu_gp0(0x02000000);gpu_gp0(0);gpu_gp0(xy(64,64));
    gpu_gp0(0xe100023e);
    gpu_gp0(0x64000000|col);gpu_gp0(xy(8,8));
    gpu_gp0((0x767fU<<16)|(24<<8));gpu_gp0(xy(width,24));
}
static void draw(unsigned col) { draw_width(col,12); }

static void plate_quad(void) {
    gpu_gp0(0x02000000);gpu_gp0(0);gpu_gp0(xy(128,128));
    gpu_gp0(0x2c808080);gpu_gp0(xy(8,8));gpu_gp0((500U<<22));
    gpu_gp0(xy(80,8));gpu_gp0((0x3cU<<16)|71);
    gpu_gp0(xy(8,32));gpu_gp0(23<<8);
    gpu_gp0(xy(80,32));gpu_gp0((23<<8)|71);
}

static void plate_rect(void) {
    gpu_gp0(0x02000000);gpu_gp0(0);gpu_gp0(xy(128,128));
    gpu_gp0(0xe100003c);
    gpu_gp0(0x64808080);gpu_gp0(xy(8,8));
    gpu_gp0(500U<<22);gpu_gp0(xy(72,24));
}

static void unmatched_rect_skips_hd(void) {
    gpu_gp1(0);gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|127|(127<<10));
    setenv("A2_HDUI","1",1);
    hd_ui_test_calls=0;
    gpu_gp0(0x600000ff);gpu_gp0(0);gpu_gp0(xy(128,128));
    assert(hd_ui_test_calls==0); /* No per-pixel HD work without a match. */
    assert(GPU_VRAM[127*1024+127]==0x001f);
    assert(gpu_display_px(383,383)==0x001f);
    /* An ordinary 15bpp textured rectangle also cannot match a HD atlas. */
    gpu_gp0(0x0200ff00);gpu_gp0(xy(128,128));gpu_gp0(xy(128,128));
    gpu_gp0(0xe1000100);
    gpu_gp0(0x64808080);gpu_gp0(0);gpu_gp0(128|(128<<8));gpu_gp0(xy(128,128));
    assert(hd_ui_test_calls==0);
    assert(GPU_VRAM[127*1024+127]==0x03e0);
    assert(gpu_display_px(383,383)==0x03e0);
}

static void plate_test(void) {
    gpu_gp1(0);gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|127|(127<<10));
    const A2HDPlate *p=&a2_hd_plates[0];
    for(unsigned y=0;y<p->height;y++)for(unsigned x=0;x<p->width;x++) {
        unsigned pos=(256+y)*1024+768+x/4,shift=(x&3)*4;
        GPU_VRAM[pos]=(GPU_VRAM[pos]&~(15<<shift))|(p->source[y*p->width+x]<<shift);
    }
    for(int i=0;i<16;i++)GPU_VRAM[500*1024+i]=i==15?0:(uint16_t)(0x8000+(15-i)*0x421);
    static uint16_t before[216*72],native[72*24];
    setenv("A2_HDUI","0",1);plate_quad();
    for(int y=0;y<72;y++)for(int x=0;x<216;x++)before[y*216+x]=gpu_display_px(24+x,24+y);
    for(int y=0;y<24;y++)for(int x=0;x<72;x++)native[y*72+x]=GPU_VRAM[(8+y)*1024+8+x];
    setenv("A2_HDUI","1",1);plate_quad();
    int changed=0;
    for(int y=0;y<72;y++)for(int x=0;x<216;x++) {
        uint16_t now=gpu_display_px(24+x,24+y);
        changed+=now!=before[y*216+x];
        if(y<9)assert(now==before[y*216+x]); /* original top bevel */
    }
    assert(changed>0);
    for(int y=0;y<24;y++)for(int x=0;x<72;x++)assert(native[y*72+x]==GPU_VRAM[(8+y)*1024+8+x]);
    setenv("A2_HDUI","0",1);plate_rect();
    for(int y=0;y<72;y++)for(int x=0;x<216;x++)before[y*216+x]=gpu_display_px(24+x,24+y);
    for(int y=0;y<24;y++)for(int x=0;x<72;x++)native[y*72+x]=GPU_VRAM[(8+y)*1024+8+x];
    setenv("A2_HDUI","1",1);hd_ui_test_calls=0;plate_rect();
    assert(hd_ui_test_calls>0); /* Guard must not disable recognized plates. */
    changed=0;
    for(int y=0;y<72;y++)for(int x=0;x<216;x++)changed+=before[y*216+x]!=gpu_display_px(24+x,24+y);
    assert(changed>0);
    for(int y=0;y<24;y++)for(int x=0;x<72;x++)assert(native[y*72+x]==GPU_VRAM[(8+y)*1024+8+x]);
}

int main(void) {
    gpu_set_ir(3);gpu_gp1(0);
    gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|63|(63<<10));
    sw_(0x800640f0,2);sw_(0x8014c880,0x8014c888);
    memcpy(PSX_RAM+0x14c888,a2_hd_bank24,sizeof a2_hd_bank24);
    const uint8_t *r=a2_hd_bank24+(0x53-32)*73;
    for(int y=0;y<24;y++)for(int x=0;x<3;x++) {
        unsigned b=r[y*3+x];
        GPU_VRAM[(280+y)*1024+896+x]=((b>>6)&3)|(((b>>4)&3)<<4)|(((b>>2)&3)<<8)|((b&3)<<12);
    }
    unsigned pal=(0x767f>>6)*1024+(0x767f&63)*16;
    GPU_VRAM[pal]=0;GPU_VRAM[pal+1]=0xa94a;
    GPU_VRAM[pal+2]=0xd293;GPU_VRAM[pal+3]=0xef7b;
    setenv("A2_HDUI","0",1);draw(0x808080);
    for(int y=0;y<24;y++)for(int x=0;x<12;x++)
        native_pixels[y*12+x]=GPU_VRAM[(8+y)*1024+8+x];
    for(int y=0;y<72;y++)for(int x=0;x<36;x++)
        coarse_fine[y*36+x]=gpu_display_px(24+x,24+y);
    setenv("A2_HDUI","1",1);a2_hd_guest_note(0xff53,896,0,24);
    draw(0x808080);
    int changed=0,subpixel=0;
    for(int y=0;y<24;y++)for(int x=0;x<12;x++)
        assert(native_pixels[y*12+x]==GPU_VRAM[(8+y)*1024+8+x]);
    for(int y=0;y<72;y++)for(int x=0;x<36;x++) {
        changed+=coarse_fine[y*36+x]!=gpu_display_px(24+x,24+y);
        subpixel+=gpu_display_px(24+x,24+y)!=gpu_display_px(24+(x/3)*3,24+(y/3)*3);
    }
    assert(changed>0 && subpixel>0); /* fails if HD is merely nearest enlargement */
    /* Lowercase а has natural advance5 but a legitimate right bearing;
       layout advance must not crop the new font's full coverage. */
    r=a2_hd_bank24+(0x61-32)*73;
    for(int y=0;y<24;y++)for(int x=0;x<3;x++) {
        unsigned b=r[y*3+x];
        GPU_VRAM[(280+y)*1024+896+x]=((b>>6)&3)|(((b>>4)&3)<<4)|(((b>>2)&3)<<8)|((b&3)<<12);
    }
    a2_hd_guest_note(0xff61,896,0,24);draw_width(0x808080,5);
    int bearing=0;
    for(int y=0;y<72;y++)for(int x=15;x<36;x++)
        bearing+=(gpu_display_px(24+x,24+y)&0x7fff)!=0;
    assert(bearing>0);
    draw(0);
    for(int y=0;y<72;y++)for(int x=0;x<36;x++)
        assert((gpu_display_px(24+x,24+y)&0x7fff)==0); /* fade modulation */
    gpu_gp0(0xe4000000|10|(10<<10));draw(0x808080);
    assert((gpu_display_px(33,30)&0x7fff)==0); /* original clip, x11 excluded */
    plate_test();
    unmatched_rect_skips_hd();
    gpu_set_ir(1);
    puts("HD glyph fine detail, native VRAM, fade and clip passed");
    return 0;
}
