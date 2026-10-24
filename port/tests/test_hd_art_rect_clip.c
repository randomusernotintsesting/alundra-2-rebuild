/* Actual GP0 regression: clipped HD sprites retain every VRAM/SHADOW pixel
 * while sampling only visible fine pixels. The existing rect reference flag
 * retains the former unbounded fine loop as a differential oracle.
 * cc -O2 -Isrc tests/test_hd_art_rect_clip.c src/hd_art.c -o /tmp/a2-art-rect-clip
 */
#define A2_GPU_RECT_TEST 1
#define A2_HD_TEST_COUNT 1
#define main existing_hd_art_gpu_main
#include "test_hd_art_gpu.c"
#undef main

typedef struct {
    int x,y,w,h,left,top,right,bottom;
    unsigned u,v,window,visible;
    int corrupt;
} ClipCase;

static void draw_clip(const ClipCase *c,int reference,unsigned bpp,unsigned mode,int semi) {
    memset(SHADOW,0x5a,(size_t)IR_W*IR_H*sizeof *SHADOW);
    setup(1,bpp,mode);
    if(c->corrupt)GPU_VRAM[17*1024+640+8/(16/bpp)]^=1;
    gpu_gp0(0xe3000000|(unsigned)c->left|((unsigned)c->top<<10));
    gpu_gp0(0xe4000000|(unsigned)c->right|((unsigned)c->bottom<<10));
    gpu_gp0(0xe2000000|c->window);
    gpu_rect_test_reference=reference;
    hd_ui_test_calls=0;
    gpu_gp0((semi?0x66000000u:0x64000000u)|0x906048);
    gpu_gp0(((unsigned)c->x&0x7ff)|(((unsigned)c->y&0x7ff)<<16));
    gpu_gp0((500u<<22)|c->u|(c->v<<8));
    gpu_gp0((unsigned)c->w|((unsigned)c->h<<16));
}

int main(void) {
    const ClipCase cases[]={
        /* Captured Settings background dimensions, with matching test art. */
        {0,0,624,64,0,0,319,239,0,0,31|(31<<5)|(1<<10)|(2<<15),320*64,0},
        /* Left/top clipping must retain original fractional UV origin. */
        {-3,-2,12,11,0,0,7,7,0,0,1|(2<<5)|(1<<10)|(2<<15),8*8,0},
        {4,5,12,11,5,6,11,12,8,16,0,7*7,0},
        /* Wrapping in both axes still finds the art at u8,v16. */
        {4,5,24,32,6,7,19,28,255,255,0,14*22,0},
        {30,30,12,11,0,0,15,15,8,16,0,0,0},
        {4,5,12,11,20,20,10,10,8,16,0,0,0},
        /* Source guard rejection falls back to ordinary native sampling. */
        {4,5,12,11,5,6,11,12,8,16,0,7*7,1},
        /* Destination overlaps source: retain the authoritative native pass. */
        {642,16,12,11,643,17,649,23,8,16,0,7*7,1},
    };
    for(unsigned i=0;i<256;i++)colors[i]=i%3==0?0:(uint16_t)((i*97u)&0x7fff)|(i&1?0x8000:0);
    pattern();
    uint16_t *expected=malloc(1024*512*16*sizeof *expected);assert(expected);
    unsigned checked=0,failures=0;
    for(int scale=2;scale<=4;scale++) {
        gpu_set_ir(scale);
        size_t bytes=(size_t)IR_W*IR_H*sizeof *SHADOW;
        for(unsigned bpp=4;bpp<=8;bpp+=4)for(unsigned mode=0;mode<4;mode++)
        for(int semi=0;semi<=1;semi++)for(unsigned i=0;i<sizeof cases/sizeof cases[0];i++) {
            const ClipCase *c=&cases[i];
            draw_clip(c,1,bpp,mode,semi);
            unsigned long before=hd_ui_test_calls;
            save_native();memcpy(expected,SHADOW,bytes);
            draw_clip(c,0,bpp,mode,semi);
            same_native();assert(!memcmp(expected,SHADOW,bytes));
            if(!c->corrupt) {
                assert(before==(unsigned long)c->w*c->h*scale*scale);
                unsigned long wanted=(unsigned long)c->visible*scale*scale;
                if(hd_ui_test_calls!=wanted) {
                    if(!failures)fprintf(stderr,"excess HD samples: case%u IR%d bpp%u mode%u semi%d got=%lu wanted=%lu; full buffers identical\n",
                        i,scale,bpp,mode,semi,hd_ui_test_calls,wanted);
                    failures++;
                }
            } else assert(!hd_ui_test_calls);
            if(i==0 && bpp==4 && mode==0 && !semi)
                printf("IR%d Settings-size HD samples: %lu -> %lu\n",scale,before,hd_ui_test_calls);
            checked++;
        }
    }
    free(expected);gpu_set_ir(1);
    printf("HD rect draw-area clip: %u full-buffer cases, %u excess-sampling failures\n",checked,failures);
    return failures?1:0;
}
