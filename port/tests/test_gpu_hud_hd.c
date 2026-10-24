/* Known authored coverage and palette alternatives through the complete HD
 * sampler and GP0 HUD geometry, with independent destination/coverage math. */
#define A2_HUD_PRESENT 1
#define main ordinary_hd_test_main
#include "test_hd_art_gpu.c"
#undef main
uint32_t a2_hud_present_watch_begin,a2_hud_present_watch_end;
static int tag_anchor=-1;
void a2_hud_present_invalidate(uint32_t a,size_t n){(void)a;(void)n;}
void a2_hud_present_reset(void){tag_anchor=-1;}
uint64_t a2_hud_present_packet_token(uint32_t a,uint32_t w){(void)w;return a==0x110004&&tag_anchor>=0?1:0;}
int a2_hud_present_consume(uint32_t a,uint64_t t,const uint32_t *w,unsigned n,int *anchor){
    (void)w;(void)n;if(a!=0x110004||!t||tag_anchor<0)return 0;*anchor=tag_anchor;tag_anchor=-1;return 1;
}
static void packet(unsigned x,unsigned page,unsigned col,int semi,int anchor) {
    uint32_t words[]={((semi?0x2e:0x2c)<<24)|col,xy(x,8),(500u<<22)|8|(16u<<8),
        xy(x+36,8),(page<<16)|10|(16u<<8),xy(x,44),8|(18u<<8),xy(x+36,44),10|(18u<<8)};
    tag_anchor=anchor;for(unsigned i=0;i<9;i++)gpu_gp0_at(words[i],0x110004+4*i);
}
static void prepare_hd(unsigned bpp,unsigned mode) {
    setup(1,bpp,mode);
    gpu_gp0(0xe4000000u|319u|(215u<<10));
    gpu_gp0(0x02605050);gpu_gp0(0);gpu_gp0(xy(320,216));
}
int main(void) {
    setenv("A2_IRSCALE","1",1);
    for(unsigned i=0;i<256;i++)colors[i]=(uint16_t)(i?(i&1?0x8000:0)|((i*91u)&0x7fff):0);
    for(unsigned i=0;i<64;i++)pixels[i]=((i%3==0?0u:i%3==1?255u:173u)<<24)|
        (((i*37u)&255)<<16)|((i%4u)<<8)|((i/4u)%4u);
    for(int scale=1;scale<=4;scale++)for(unsigned bpp=4;bpp<=8;bpp+=4)
    for(unsigned mode=0;mode<4;mode++)for(int semi=0;semi<2;semi++)for(int anchor=0;anchor<=320;anchor+=320) {
        gpu_set_ir(scale);unsigned x=anchor?272:8,page=10|(bpp==8?0x80:0)|(mode<<5),col=0x906048;
        prepare_hd(bpp,mode);packet(x,page,col,semi,-1);save_native();
        prepare_hd(bpp,mode);packet(x,page,col,semi,anchor);same_native();
        int left=(int)(5*x+anchor)*scale,right=left+36*5*scale;
        for(int y=0;y<216*scale;y++)for(int fx=0;fx<320*scale;fx++) {
            uint16_t wanted=background;
            if(fx*6>=left&&fx*6<right&&y>=8*scale&&y<44*scale) {
                unsigned u=(unsigned)((int64_t)(fx*6-left)*512/(36*5*scale));
                unsigned v=(unsigned)((int64_t)(y-8*scale)*512/(36*scale));
                wanted=expected_art(background,pixels[(v/64)*8+u/64],col,semi,mode);
            }
            exact((unsigned)fx,(unsigned)y,wanted,"HUD HD coverage");
        }
    }
    puts("PASS: corrected HUD HD coverage/mixed palettes IR1–4, both anchors, 4/8bpp and four STP blend modes; native VRAM unchanged");
}
