/* Exercise actual GP0 composition, not merely the asset sampler. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/hd_art.h"
static const uint8_t source4[]={1,2,3,1};
static const uint8_t source8[]={137,2,255,137};
static uint32_t pixels[64], large_pixels[256*256*16];
static A2HDArt a2_hd_art_assets[2];
static const unsigned a2_hd_art_asset_count=2;
#define A2_HD_FONTS 1
#define A2_HD_ART 1
#define A2_HD_ART_TEST 1
#include "../src/gpu.c"
#include "../src/hd_font.c"
#include "../src/hd_ui.c"
/* hd_art.c is linked separately: hd_ui.c has a private palette() helper. */
uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t psx_frame_no,gpu_flips,a2_ramwatch;
void psx_mmio_write(uint32_t p,uint32_t v,int s){(void)p;(void)v;(void)s;abort();}
void a2_ramwatch_hit(uint32_t p,uint32_t v,int s){(void)p;(void)v;(void)s;abort();}
void psx_vblank_tick(void){}
uint32_t psx_mmio_read(uint32_t p,int s){(void)p;(void)s;return 0;}
int a2_modelcap_active(void){return 0;}
FILE *a2_modelcap_file(void){return NULL;}
static uint16_t native[1024*512],fine[64*64];
static uint16_t colors[256];
static const uint16_t background=0x314a;
static unsigned xy(unsigned x,unsigned y){return x|(y<<16);}

/* Independent per-channel oracle. Alternatives always use original dst. */
static uint16_t shade(uint16_t before,uint16_t texel,unsigned col,int semi,unsigned mode){
    if(!texel)return before;
    uint16_t out=texel&0x8000;
    for(unsigned c=0;c<3;c++){
        int a=((before>>(5*c))&31)*8;
        int z=(((texel>>(5*c))&31)*8)*((col>>(8*c))&255)/128;
        if(z>255)z=255;
        if(semi && (texel&0x8000)){
            if(mode==0)z=(a+z)/2;
            else if(mode==1)z=a+z;
            else if(mode==2)z=a-z;
            else z=a+z/4;
        }
        if(z<0)z=0;if(z>255)z=255;
        out|=(uint16_t)((z/8)<<(5*c));
    }
    return out;
}
static uint16_t coverage(uint16_t a,uint16_t b,unsigned amount){
    if(!amount)return a;
    uint16_t out=b&0x8000;
    for(unsigned c=0;c<3;c++)
        out|=(uint16_t)(((((a>>(5*c))&31)*(255-amount)+
                           ((b>>(5*c))&31)*amount+127)/255)<<(5*c));
    return out;
}
static uint16_t expected_art(uint16_t before,uint32_t p,unsigned col,int semi,unsigned mode){
    uint16_t a=shade(before,colors[p&255],col,semi,mode);
    uint16_t b=shade(before,colors[(p>>8)&255],col,semi,mode);
    return coverage(before,coverage(a,b,(p>>16)&255),p>>24);
}
static void exact(unsigned x,unsigned y,uint16_t expected,const char *label){
    uint16_t actual=gpu_display_px(x,y);
    if(actual!=expected){
        fprintf(stderr,"%s (%u,%u): got %04X, wanted %04X\n",label,x,y,actual,expected);
        abort();
    }
}
static void upload(const A2HDArt *a,unsigned page){
    unsigned bits=a->bpp,per=16/bits,tx=(page&15)*64,ty=((page>>4)&1)*256;
    for(unsigned y=0;y<a->height;y++)for(unsigned x=0;x<a->width;x++){
        unsigned u=a->u+x,shift=(u%per)*bits;
        uint16_t *dst=&GPU_VRAM[(ty+a->v+y)*1024+tx+u/per];
        unsigned mask=(1u<<bits)-1;
        *dst=(uint16_t)((*dst&~(mask<<shift))|(a->source[y*a->width+x]<<shift));
    }
}
static void setup(int enabled,unsigned bpp,unsigned mode){
    gpu_gp1(0);memset(GPU_VRAM,0,sizeof GPU_VRAM);
    gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|127|(127<<10));
    setenv("A2_HDUI",enabled?"1":"0",1);
    gpu_gp0(0x02000000|0x605050);gpu_gp0(0);gpu_gp0(xy(128,128));
    assert(GPU_VRAM[0]==background);
    a2_hd_art_assets[0]=(A2HDArt){8,16,2,2,(uint8_t)bpp,bpp==4?source4:source8,pixels};
    a2_hd_art_assets[1]=(A2HDArt){0};
    unsigned page=10|(bpp==8?0x80:0)|(mode<<5);
    upload(&a2_hd_art_assets[0],page);
    for(unsigned i=0;i<256;i++)GPU_VRAM[500*1024+i]=colors[i];
    gpu_gp0(0xe1000000|page);
}
static void rect(unsigned u,unsigned v,unsigned w,unsigned h,unsigned col,int semi){
    gpu_gp0((semi?0x66000000:0x64000000)|col);gpu_gp0(xy(8,8));
    gpu_gp0((500u<<22)|u|(v<<8));gpu_gp0(xy(w,h));
}
static void save_native(void){memcpy(native,GPU_VRAM,sizeof native);}
static void same_native(void){assert(!memcmp(native,GPU_VRAM,sizeof native));}
static void save_fine(void){
    for(unsigned y=0;y<64;y++)for(unsigned x=0;x<64;x++)fine[y*64+x]=gpu_display_px(x,y);
}
static void same_fine(void){
    for(unsigned y=0;y<64;y++)for(unsigned x=0;x<64;x++)exact(x,y,fine[y*64+x],"fallback");
}
static void pattern(void){
    for(unsigned i=0;i<64;i++){
        unsigned alpha=i%3==0?0:i%3==1?255:173;
        pixels[i]=(alpha<<24)|((i*37u%256)<<16)|(5u<<8)|4u;
    }
}
static void basic_rectangles(void){
    pattern();
    for(unsigned bpp=4;bpp<=8;bpp+=4)for(unsigned mode=0;mode<4;mode++)
    for(int semi=0;semi<=1;semi++)for(unsigned state=0;state<4;state++){
        colors[4]=state&1?0:0x819f;colors[5]=state&2?0x03e0:0xfc00;
        setup(0,bpp,mode);rect(8,16,2,2,0x906048,semi);save_native();
        setup(1,bpp,mode);rect(8,16,2,2,0x906048,semi);same_native();
        for(unsigned y=0;y<8;y++)for(unsigned x=0;x<8;x++)
            exact(32+x,32+y,expected_art(background,pixels[y*8+x],0x906048,semi,mode),"art rectangle");
        exact(31,32,background,"left bound");exact(40,32,background,"right bound");
    }
    /* Index zero may be opaque; a nonzero index may map to transparent zero. */
    colors[0]=0x83e0;colors[5]=0;
    for(unsigned i=0;i<64;i++)pixels[i]=0xff000000u;
    setup(1,4,0);rect(8,16,2,2,0x808080,0);exact(32,32,colors[0],"opaque index zero");
    for(unsigned i=0;i<64;i++)pixels[i]=0xff000505u;
    setup(1,4,0);rect(8,16,2,2,0x808080,0);exact(32,32,background,"transparent palette value");
}
static void windows_and_wrapping(void){
    colors[4]=0x801f;colors[5]=0x03e0;pattern();
    unsigned window=1|(2<<5)|(1<<10)|(2<<15);
    setup(0,4,0);gpu_gp0(0xe2000000|window);rect(0,0,2,2,0x808080,1);save_native();
    setup(1,4,0);gpu_gp0(0xe2000000|window);rect(0,0,2,2,0x808080,1);same_native();
    for(unsigned y=0;y<8;y++)for(unsigned x=0;x<8;x++)
        exact(32+x,32+y,expected_art(background,pixels[y*8+x],0x808080,1,0),"window fraction");
    for(int enabled=0;enabled<=1;enabled++){
        setup(enabled,4,0);a2_hd_art_assets[0].u=0;upload(&a2_hd_art_assets[0],10);
        rect(255,16,3,2,0x808080,0);
        if(!enabled)save_native();else same_native();
    }
    for(unsigned y=0;y<8;y++)for(unsigned x=0;x<8;x++)
        exact(36+x,32+y,expected_art(background,pixels[y*8+x],0x808080,0,0),"UV wrap fraction");
}
static void fallback_and_clip(void){
    pattern();
    /* Mutating an unsampled native texel must reject the whole source identity. */
    setup(0,4,0);GPU_VRAM[17*1024+642]^=1;rect(8,16,1,1,0x808080,0);save_native();save_fine();
    setup(1,4,0);GPU_VRAM[17*1024+642]^=1;rect(8,16,1,1,0x808080,0);same_native();same_fine();
    /* Matching words in an incompatible texture format are not enough. */
    setup(0,4,0);gpu_gp0(0xe100008a);rect(8,16,2,2,0x808080,0);save_native();save_fine();
    setup(1,4,0);gpu_gp0(0xe100008a);rect(8,16,2,2,0x808080,0);same_native();same_fine();
    setup(1,4,0);gpu_gp0(0xe4000000|8|(8<<10));rect(8,16,2,2,0x808080,0);
    exact(36,32,background,"draw area X");exact(32,36,background,"draw area Y");
    for(unsigned y=0;y<4;y++)for(unsigned x=0;x<4;x++)
        exact(32+x,32+y,expected_art(background,pixels[y*8+x],0x808080,0,0),"clip interior");
    /* A following ordinary primitive cannot inherit art candidates. */
    gpu_gp0(0xe4000000|127|(127<<10));
    gpu_gp0(0x600000f8);gpu_gp0(xy(8,8));gpu_gp0(xy(2,2));
    exact(32,32,31,"primitive reset");
}
static void quad(int enabled,int shape,int gouraud){
    setup(enabled,4,1);
    unsigned col[4]={0x302010,0x908070,0x605040,0xc0b0a0};
    gpu_gp0((gouraud?0x3e000000u:shape==2?0x26000000u:0x2e000000u)|col[0]);
    unsigned n=shape==2?3:4;
    for(unsigned i=0;i<n;i++){
        if(i && gouraud)gpu_gp0(col[i]);
        gpu_gp0(xy(8+(i&1)*2+(shape==1 && i==3),8+(i>>1)*2));
        gpu_gp0((i==0?500u<<22:i==1?0x2au<<16:0)|(8+(i&1)*2)|((16+(i>>1)*2)<<8));
    }
}
static void polygons(void){
    for(unsigned i=0;i<64;i++)pixels[i]=0xff000404u;
    colors[4]=0x93df;
    for(int shape=1;shape<=2;shape++){
        quad(0,shape,0);save_native();save_fine();quad(1,shape,0);same_native();same_fine();
    }
    quad(0,0,1);save_native();quad(1,0,1);same_native();
    /* At fine pixel (33,33), vertex weights are 3/4,1/8,1/8.
       GPU truncates each interpolated 8-bit modulation component. */
    exact(33,33,shade(background,colors[4],0x423222,1,1),"Gouraud modulation");
    assert(gpu_display_px(32,32)!=gpu_display_px(37,32));
}
static void polygon_window_and_flip(void){
    pattern();colors[4]=0x801f;colors[5]=0x03e0;
    for(int flip=0;flip<=1;flip++){
        for(int enabled=0;enabled<=1;enabled++){
            setup(enabled,4,0);
            if(!flip)gpu_gp0(0xe2000000|1|(2<<5)|(1<<10)|(2<<15));
            gpu_gp0(0x2c808080);
            for(unsigned i=0;i<4;i++){
                unsigned u=flip?10-(i&1)*2:(i&1)*2,v=(flip?16:0)+(i>>1)*2;
                gpu_gp0(xy(8+(i&1)*2,8+(i>>1)*2));
                gpu_gp0((i==0?500u<<22:i==1?10u<<16:0)|u|(v<<8));
            }
            if(!enabled)save_native();else same_native();
        }
        for(unsigned y=0;y<8;y++)for(unsigned x=flip?1:0;x<8;x++){
            unsigned sx=flip?8-x:x;
            exact(32+x,32+y,expected_art(background,pixels[y*8+sx],0x808080,0,0),
                  flip?"flipped quad UV":"windowed quad fraction");
        }
    }
}
static void words_above_art(void){
    const A2HDPlate *p=&a2_hd_plates[0];
    assert(p->width<=256 && p->height<=256);
    for(unsigned i=0;i<p->width*p->height*16;i++)large_pixels[i]=0xff000404u;
    for(unsigned i=0;i<16;i++)colors[i]=(uint16_t)(0x8000|((i*157)&0x7fff));
    colors[4]=0xa01f;
    for(int enabled=0;enabled<=1;enabled++){
        setup(enabled,4,0);
        a2_hd_art_assets[0]=(A2HDArt){p->u,p->v,p->width,p->height,4,p->source,large_pixels};
        upload(&a2_hd_art_assets[0],10);
        rect(p->u,p->v,p->width,p->height,0x808080,1);
        if(!enabled)save_native();else same_native();
    }
    unsigned seen_ink=0,seen_blank=0;
    for(unsigned y=0;y<p->height*4;y++)for(unsigned x=0;x<p->width*4;x++){
        unsigned pos=y*p->width*4+x,a=p->alpha[pos];
        unsigned edge=x&&y?p->alpha[(y-1)*p->width*4+x-1]:0;
        uint16_t expected=shade(background,colors[4],0x808080,1,0);
        expected=coverage(expected,shade(background,colors[p->shadow_index],0x808080,1,0),edge);
        expected=coverage(expected,shade(background,colors[p->ink_index],0x808080,1,0),a);
        exact(32+x,32+y,expected,"word above art, one semi blend");
        seen_ink+=a!=0;seen_blank+=!a && !edge;
    }
    assert(seen_ink && seen_blank);
}
static void glyph_has_priority(void){
    static uint8_t glyph_source[12*24];
    static uint16_t glyph_fine[48*96];
    const uint8_t *r=a2_hd_bank24+(0x53-32)*73;
    for(unsigned y=0;y<24;y++)for(unsigned x=0;x<12;x++)
        glyph_source[y*12+x]=(r[y*3+x/4]>>(6-2*(x%4)))&3;
    for(unsigned i=0;i<12*24*16;i++)large_pixels[i]=0xff000404u;
    sw_(0x800640f0,2);sw_(0x8014c880,0x8014c888);
    memcpy(PSX_RAM+0x14c888,a2_hd_bank24,sizeof a2_hd_bank24);
    for(int art=0;art<=1;art++){
        setup(1,4,0);
        a2_hd_art_assets[0]=(A2HDArt){0,24,12,24,4,glyph_source,large_pixels};
        upload(&a2_hd_art_assets[0],30);
        if(!art)a2_hd_art_assets[0].width=0;
        gpu_gp0(0xe100001e);a2_hd_guest_note(0xff53,896,0,24);
        assert(a2_hd_font_match(GPU_VRAM,30,0,24,12,24));
        rect(0,24,12,24,0x808080,0);
        assert(!hd_plate_count && !hd_art_count);
        if(!art)save_native();else same_native();
        for(unsigned y=0;y<96;y++)for(unsigned x=0;x<48;x++){
            if(!art)glyph_fine[y*48+x]=gpu_display_px(32+x,32+y);
            else exact(32+x,32+y,glyph_fine[y*48+x],"glyph priority over matching art");
        }
    }
}
static void lower_internal_resolutions(void){
    pattern();colors[4]=0x87e0;colors[5]=0x7c00;
    for(unsigned scale=2;scale<=3;scale++){
        gpu_set_ir((int)scale);
        setup(0,4,3);rect(8,16,2,2,0x808080,1);save_native();
        setup(1,4,3);rect(8,16,2,2,0x808080,1);same_native();
        assert(!hd_plate_count && !hd_art_count);
        for(unsigned y=0;y<2*scale;y++)for(unsigned x=0;x<2*scale;x++){
            unsigned sx=(x*256/scale)/64,sy=(y*256/scale)/64;
            exact(8*scale+x,8*scale+y,expected_art(background,pixels[sy*8+sx],0x808080,1,3),"IR2/3 exact sample");
        }
    }
    gpu_set_ir(1);
    setup(0,4,0);rect(8,16,2,2,0x808080,1);save_native();
    setup(1,4,0);rect(8,16,2,2,0x808080,1);same_native();
    assert(!hd_plate_count && !hd_art_count);
}
int main(void){
    gpu_set_ir(4);
    for(unsigned i=0;i<256;i++)colors[i]=(uint16_t)(i?0x8000|((i*113)&0x7fff):0);
    basic_rectangles();windows_and_wrapping();fallback_and_clip();polygons();polygon_window_and_flip();words_above_art();
    glyph_has_priority();lower_internal_resolutions();
    gpu_set_ir(1);
    puts("HD art GPU: native VRAM, CLUT/STP/semi, windows, fallback, clip, Gouraud and word composition passed");
    return 0;
}
