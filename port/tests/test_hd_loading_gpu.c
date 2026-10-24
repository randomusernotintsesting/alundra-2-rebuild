/* Genuine resident loading GT4 packets, captured after native relocation.
 * The Python driver supplies only the accepted atlas and ten HD assets.
 * Missing vertical-first recognition must fail at the first composition.
 */
#define _POSIX_C_SOURCE 200809L
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hd_art.h"
#include "loading_art_fixture.h"
#include "loading_source_fixture.h"
#include "fixtures/loading_gt4.h"
static unsigned prepared;
static unsigned loading_prepare(const A2HDArt *a,unsigned count,const uint16_t *v,
    uint32_t page,int u0,int v0,int u1,int v1,const A2HDArt **out,unsigned cap) {
    unsigned n=a2_hd_art_prepare(a,count,v,page,u0,v0,u1,v1,out,cap);
    prepared+=n!=0;
    return n;
}
#define a2_hd_art_prepare loading_prepare
#define A2_HD_FONTS 1
#define A2_HD_ART 1
#define A2_HD_ART_TEST 1
#include "../src/gpu.c"
#undef a2_hd_art_prepare
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
static uint16_t native[1024*512],baseline[1024*512],russian[1024*512],english[1024*512];
static unsigned xy(unsigned x,unsigned y){return x|(y<<16);}

static void compose(int enabled,int language,int horizontal,int corrupt_label) {
    gpu_gp1(0);
    setenv("A2_HDUI",enabled?"1":"0",1);
    a2_hd_art_set_language(language);
    memset(GPU_VRAM,0,sizeof GPU_VRAM);
    gpu_gp0(0x02000000);gpu_gp0(0);gpu_gp0(xy(320,216));
    gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|319|(215<<10));
    /* Native resident upload: source y=0 starts at VRAM y=320, while
       TPAGE 0x1f begins at 256. The captured UVs already include +64. */
    gpu_gp0(0xa0000000);gpu_gp0(xy(960,320));gpu_gp0(xy(64,144));
    for(unsigned i=0;i<sizeof loading_indices;i+=8) {
        uint32_t packed=0;
        for(unsigned n=0;n<8;n++)packed|=(uint32_t)loading_indices[i+n]<<(n*4);
        gpu_gp0(packed);
    }
    gpu_gp0(0xa0000000);gpu_gp0(xy(992,471));gpu_gp0(xy(16,1));
    for(unsigned i=0;i<16;i+=2)
        gpu_gp0(loading_palette[i]|((uint32_t)loading_palette[i+1]<<16));
    if(corrupt_label)GPU_VRAM[432*1024+960]^=1;
    prepared=0;
    /* Original 2D composer inserts each primitive at the list head. */
    for(int i=23;i>=0;i--) {
        uint32_t p[12];memcpy(p,loading_gt4[i],sizeof p);
        if(horizontal) {
            for(unsigned k=0;k<3;k++) {
                uint32_t temp=p[3+k];p[3+k]=p[6+k];p[6+k]=temp;
            }
            /* CLUT/TPAGE belong to packet positions, not vertex identity. */
            p[5]=(p[5]&0xffff)|0x001f0000;p[8]&=0xffff;
        }
        for(unsigned n=0;n<12;n++)gpu_gp0(p[n]);
    }
    if(enabled && !corrupt_label)assert(prepared==24);
}

static void save_pixels(uint16_t *out) {
    for(unsigned y=0;y<512;y++)for(unsigned x=0;x<1024;x++)
        out[y*1024+x]=gpu_display_px(x,y);
}
static void same_pixels(const uint16_t *expected) {
    for(unsigned y=0;y<512;y++)for(unsigned x=0;x<1024;x++)
        assert(expected[y*1024+x]==gpu_display_px(x,y));
}
static void same_native(void){assert(!memcmp(native,GPU_VRAM,sizeof native));}

static void frame_regions(void) {
    for(unsigned frame=0;frame<8;frame++) {
        unsigned left=(frame&1)*512,top=(frame>>1)*128,key_changes=0,label_changes=0,locales=0;
        for(unsigned y=0;y<128;y++)for(unsigned x=0;x<512;x++) {
            unsigned pos=(top+y)*1024+left+x;
            if(x<128) {
                key_changes+=baseline[pos]!=russian[pos];
                assert(russian[pos]==english[pos]);
            } else {
                label_changes+=baseline[pos]!=russian[pos];
                locales+=russian[pos]!=english[pos];
            }
        }
        assert(key_changes && label_changes && locales);
    }
}

static void copy_and_display(void) {
    /* The production copy path must carry the authored subpixels along with
       the native precomposed tiles; display selection must keep them intact. */
    gpu_gp0(0x80000000);gpu_gp0(0);gpu_gp0(xy(256,256));gpu_gp0(xy(256,128));
    for(unsigned y=0;y<128;y++)for(unsigned x=0;x<256;x++)
        assert(GPU_VRAM[(256+y)*1024+256+x]==GPU_VRAM[y*1024+x]);
    static const unsigned frames[]={0,1,2,3,4,5,6,7,6,5};
    for(unsigned i=0;i<sizeof frames/sizeof frames[0];i++) {
        unsigned x=(frames[i]&1)*128,y=(frames[i]>>1)*32;
        gpu_gp1(0x05000000|x|(y<<10));
        assert(g.disp_x==(int)x && g.disp_y==(int)y);
        for(unsigned fy=0;fy<128;fy++)for(unsigned fx=0;fx<512;fx++)
            assert(gpu_display_px(x*4+fx,y*4+fy)==
                   gpu_display_px((256+x)*4+fx,(256+y)*4+fy));
    }
}

static void reject_nonrectangular_quads(void) {
    /* Changing any XY or UV edge makes the genuine rectangle ineligible.
       The new ordering must not broaden matching to arbitrary triangles. */
    for(unsigned vertex=0;vertex<4;vertex++)for(unsigned field=0;field<4;field++) {
        uint32_t p[12];memcpy(p,loading_gt4[0],sizeof p);
        unsigned word=vertex*3+(field<2?1:2);
        unsigned shift=field<2?(field*16):((field-2)*8);
        p[word]+=1u<<shift;
        prepared=0;
        for(unsigned n=0;n<12;n++)gpu_gp0(p[n]);
        assert(!prepared);
    }
}

int main(void) {
    gpu_set_ir(4);
    compose(0,0,0,0);memcpy(native,GPU_VRAM,sizeof native);save_pixels(baseline);
    compose(1,0,0,0);same_native();save_pixels(russian);
    compose(1,2,0,0);same_native();save_pixels(english);
    compose(1,1,0,0);same_native();same_pixels(english);
    frame_regions();copy_and_display();
    compose(1,0,1,0);same_native();same_pixels(russian);
    reject_nonrectangular_quads();
    /* One wrong texel anywhere in the label rejects the complete replacement,
       including the partial entrance frames which do not sample that texel. */
    compose(0,0,0,1);memcpy(native,GPU_VRAM,sizeof native);save_pixels(baseline);
    compose(1,0,0,1);same_native();assert(prepared==16);
    for(unsigned frame=0;frame<8;frame++)
        for(unsigned y=0;y<128;y++)for(unsigned x=128;x<512;x++) {
            unsigned fx=(frame&1)*512+x,fy=(frame>>1)*128+y;
            assert(gpu_display_px(fx,fy)==baseline[fy*1024+fx]);
        }
    gpu_set_ir(1);
    puts("Loading GPU: 24 captured GT4s, both orders, locales, exact source, native VRAM and shadow copy passed");
    return 0;
}
