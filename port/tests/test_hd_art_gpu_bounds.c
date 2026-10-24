/* Catches unrelated art disabling the ordinary block renderer on repeated
 * backgrounds. The reference forces the old full-UV candidate region after
 * every window/wrap; output comparison covers every native and fine pixel.
 * cc -O2 -Iport/src port/tests/test_hd_art_gpu_bounds.c port/src/hd_art.c -o /tmp/a2-art-bounds
 */
#include "../src/hd_art.h"
static int reference_bounds;
static unsigned bounds_prepare(const A2HDArt *a,unsigned count,const uint16_t *v,
    uint32_t page,int u0,int v0,int u1,int v1,const A2HDArt **out,unsigned cap) {
    if(reference_bounds){u0=v0=0;u1=v1=255;}
    return a2_hd_art_prepare(a,count,v,page,u0,v0,u1,v1,out,cap);
}
#define a2_hd_art_prepare bounds_prepare
#define A2_HD_TEST_COUNT 1
#define main existing_hd_art_gpu_main
#include "test_hd_art_gpu.c"
#undef main
#undef a2_hd_art_prepare
static uint16_t *reference_fine;
static uint8_t cell_source[64];
static uint32_t cell_pixels[1024];
typedef struct {unsigned au,av,u,v,w,h,window;int expected,quad,flip;} BoundsCase;
static void draw_case(const BoundsCase *c,int ref,int semi,unsigned mode,unsigned bpp) {
    reference_bounds=ref;
    setup(1,bpp,mode);
    unsigned page=10|(bpp==8?0x80:0)|(mode<<5),per=bpp==8?2:4;
    for(unsigned y=0;y<256;y++)for(unsigned x=0;x<256/per;x++)
        GPU_VRAM[y*1024+640+x]=(uint16_t)(0x3211u^(y*16u+x));
    a2_hd_art_assets[0]=(A2HDArt){c->au,c->av,8,8,bpp,cell_source,cell_pixels};
    upload(&a2_hd_art_assets[0],page);
    gpu_gp0(0xe2000000|c->window);
    hd_ui_test_calls=0;hd_span_test_calls=0;
    if(c->quad) {
        gpu_gp0((semi?0x2e000000u:0x2c000000u)|0x906048);
        for(unsigned i=0;i<4;i++) {
            gpu_gp0(xy(8+(i&1)*c->w,8+(i>>1)*c->h));
            unsigned u=c->u+((i&1)^c->flip)*c->w,v=c->v+(i>>1)*c->h;
            gpu_gp0((i==0?500u<<22:i==1?page<<16:0)|(u&255)|((v&255)<<8));
        }
    } else rect(c->u,c->v,c->w,c->h,0x906048,semi);
}
int main(void) {
    const BoundsCase cases[]={
        /* Actual Settings E2 range224..255,192..255 excludes the cell. */
        {8,16,224,192,624,64,0x0c731c,0,0,0},
        /* Partial masks include both fractional endpoints of the art cell. */
        {8,16,0,0,8,8,1|(2<<5)|(1<<10)|(2<<15),1,0,0},
        {16,16,0,0,8,8,1|(2<<5)|(1<<10)|(2<<15),0,0,0},
        /* Partial noncontiguous mask forces bits3/5, leaving bit4 variable. */
        {40,16,0,16,32,8,5|(5<<10),1,0,0},
        {0,16,0,16,32,8,5|(5<<10),0,0,0},
        /* Wrap either axis independently; never widen the other axis. */
        {0,16,255,16,9,8,0,1,0,0},
        {8,0,8,255,8,9,0,1,0,0},
        {8,16,255,192,624,64,0,0,0,0},
        /* Repeated eight-texel description-cell style window. */
        {80,64,0,0,64,64,31|(31<<5)|(10<<10)|(8<<15),1,0,0},
        /* Quads cover partial masks, reversed UV and fractional bounds. */
        {8,16,0,0,7,7,1|(2<<5)|(1<<10)|(2<<15),1,1,0},
        {8,16,0,0,7,7,1|(2<<5)|(1<<10)|(2<<15),1,1,1},
        {40,16,0,16,31,7,5|(5<<10),1,1,1},
    };
    for(unsigned i=0;i<256;i++)colors[i]=(uint16_t)(i?(i&1?0x8000:0)|((i*91u)&0x7fff):0);
    for(unsigned i=0;i<64;i++)cell_source[i]=(uint8_t)(1+i%3);
    for(unsigned i=0;i<1024;i++)cell_pixels[i]=((i%3==0?0u:i%3==1?255u:173u)<<24)|
        (((i*37u)&255)<<16)|((i%16u)<<8)|((i/16u)%16u);
    reference_fine=malloc(1024*512*16*sizeof *reference_fine);assert(reference_fine);
    unsigned checked=0;
    for(int scale=2;scale<=4;scale++)for(unsigned bpp=4;bpp<=8;bpp+=4)
    for(unsigned mode=0;mode<4;mode++)for(int semi=0;semi<2;semi++)
    for(unsigned i=0;i<sizeof cases/sizeof cases[0];i++) {
        gpu_set_ir(scale);
        draw_case(&cases[i],1,semi,mode,bpp);
        save_native();memcpy(reference_fine,SHADOW,1024*512*scale*scale*2);
        draw_case(&cases[i],0,semi,mode,bpp);
        same_native();assert(!memcmp(reference_fine,SHADOW,1024*512*scale*scale*2));
        if(!cases[i].expected && (hd_ui_test_calls||hd_span_test_calls)) {
            fprintf(stderr,"unreachable art still sampled: case%u IR%d bpp%u mode%u semi%d calls=%lu\n",
                i,scale,bpp,mode,semi,hd_ui_test_calls);return 1;
        }
        if(cases[i].expected)assert(hd_ui_test_calls||hd_span_test_calls);
        checked++;
    }
    free(reference_fine);
    printf("HD art reachable-UV bounds: %u exact full-buffer cases passed\n",checked);
    return 0;
}
