/* Real host glyph recognition against the embedded known-source banks. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/hd_font.c"
#include "../assets/hd_font_en_data.h"

uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t psx_frame_no, gpu_flips;
uint32_t a2_ramwatch;
void psx_mmio_write(uint32_t p,uint32_t v,int s) {(void)p;(void)v;(void)s;abort();}
void a2_ramwatch_hit(uint32_t p,uint32_t v,int s) {(void)p;(void)v;(void)s;abort();}
static int test_ir = 3;
int gpu_ir(void) { return test_ir; }
uint32_t psx_mmio_read(uint32_t p, int size) { (void)p; (void)size; return 0; }
static uint16_t test_vram[512*1024];

/* Independent copy of the pre-cache integer area-integration contract. */
static unsigned alpha_oracle(const A2HDGlyph *g,int x,int y,int s) {
    if(!g || s<1 || s>4 || x<0 || y<0 || x>=12*s || y>=24*s)return 0;
    unsigned sum=0;
    for(int sy=y*4/s;sy<((y+1)*4+s-1)/s;sy++)
        for(int sx=x*4/s;sx<((x+1)*4+s-1)/s;sx++) {
            int xa=sx*s>x*4?sx*s:x*4,xb=(sx+1)*s<(x+1)*4?(sx+1)*s:(x+1)*4;
            int ya=sy*s>y*4?sy*s:y*4,yb=(sy+1)*s<(y+1)*4?(sy+1)*s:(y+1)*4;
            sum+=g->alpha[sy*48+sx]*(unsigned)((xb-xa)*(yb-ya));
        }
    return (sum+8)/16;
}

static void test_alpha_memoization(void) {
    /* Cache must be lazy and invalidated by scale, not synthetic addresses. */
    memset(alpha_cache_ready,0,sizeof alpha_cache_ready);
    alpha_cache_scale=0;
    assert(a2_hd_font_alpha(&a2_hd_glyphs16[7],0,0,3)==alpha_oracle(&a2_hd_glyphs16[7],0,0,3));
    for(int i=0;i<192;i++)assert(alpha_cache_ready[i]==(i==7));
    assert(alpha_cache_scale==3);
    assert(a2_hd_font_alpha(&a2_hd_glyphs24[5],0,0,2)==alpha_oracle(&a2_hd_glyphs24[5],0,0,2));
    for(int i=0;i<192;i++)assert(alpha_cache_ready[i]==(i==101));
    assert(alpha_cache_scale==2);
    const int scales[]={1,2,3,4,3,1,4,2};
    for(unsigned k=0;k<sizeof scales/sizeof scales[0];k++) {
        int s=scales[k];
        for(int family=0;family<2;family++)for(int n=0;n<96;n++) {
            const A2HDGlyph *g=family?&a2_hd_glyphs24[n]:&a2_hd_glyphs16[n];
            for(int y=-2;y<24*s+2;y++)for(int x=-2;x<12*s+2;x++)
                assert(a2_hd_font_alpha(g,x,y,s)==alpha_oracle(g,x,y,s));
        }
    }
    A2HDGlyph synthetic=a2_hd_glyphs24[7];
    memset(synthetic.alpha,17,sizeof synthetic.alpha);
    for(int s=1;s<=4;s++)assert(a2_hd_font_alpha(&synthetic,0,0,s)==17);
    memset(synthetic.alpha,231,sizeof synthetic.alpha);
    for(int s=1;s<=4;s++)assert(a2_hd_font_alpha(&synthetic,0,0,s)==231);
    assert(a2_hd_font_alpha(NULL,0,0,3)==0);
    assert(a2_hd_font_alpha(&synthetic,0,0,0)==0);
    assert(a2_hd_font_alpha(&synthetic,0,0,5)==0);
    a2_hd_font_reset();
    assert(a2_hd_font_alpha(&a2_hd_glyphs24[7],3,3,3)==alpha_oracle(&a2_hd_glyphs24[7],3,3,3));
}

static void test_coverage_view(void) {
    const A2HDGlyph *families[]={a2_hd_glyphs16,a2_hd_glyphs24,a2_hd_en_glyphs16,a2_hd_en_glyphs24};
    const int scales[]={1,2,3,4,2};
    for(unsigned k=0;k<sizeof scales/sizeof scales[0];k++)for(int f=0;f<4;f++)for(int n=0;n<96;n++) {
        int scale=scales[k];const A2HDGlyph *g=&families[f][n];
        const uint8_t *view=a2_hd_font_coverage(g,scale);assert(view);
        for(int y=0;y<24*scale;y++)for(int x=0;x<12*scale;x++)
            assert(view[y*A2_HD_FONT_COVERAGE_STRIDE+x]==alpha_oracle(g,x,y,scale));
    }
    A2HDGlyph synthetic=a2_hd_glyphs24[7];
    memset(synthetic.alpha,173,sizeof synthetic.alpha);
    assert(!a2_hd_font_coverage(&synthetic,4));
    assert(a2_hd_font_alpha(&synthetic,3,5,4)==173);
    assert(!a2_hd_font_coverage(NULL,4));
    assert(!a2_hd_font_coverage(&a2_hd_glyphs24[7],0));
    assert(!a2_hd_font_coverage(&a2_hd_glyphs24[7],5));
}

static void bank24(void) {
    sw_(0x800640f0, 2);
    sw_(0x8014c880, 0x8014c888);
    memcpy(PSX_RAM + 0x14c888, a2_hd_bank24, sizeof a2_hd_bank24);
}

static void upload(unsigned token, int x, int y, int height) {
    const uint8_t *bank = height == 24 ? a2_hd_bank24 : a2_hd_bank16;
    const uint8_t *record = bank + ((token & 127)-32)*(height*3+1);
    for (int row=0; row<height; row++)
        for (int word=0; word<3; word++) {
            unsigned b = record[row*3+word];
            test_vram[(y+row)*1024+x+word] = ((b>>6)&3) |
                (((b>>4)&3)<<4) | (((b>>2)&3)<<8) | ((b&3)<<12);
        }
}

static void test_english_source(void) {
    a2_hd_font_reset();
    sw_(0x800640f0,0);
    memcpy(PSX_RAM+0x65b60,a2_hd_en_bank16,sizeof a2_hd_en_bank16);
    unsigned cell='Y'-32;
    const uint8_t *record=a2_hd_en_bank16+cell*49;
    for(unsigned y=0;y<16;y++)for(unsigned x=0;x<3;x++) {
        unsigned b=record[y*3+x];
        test_vram[(280+y)*1024+896+x]=((b>>6)&3)|(((b>>4)&3)<<4)|
            (((b>>2)&3)<<8)|((b&3)<<12);
    }
    a2_hd_guest_note(0xff59,896,0,24);
    const A2HDGlyph *glyph=a2_hd_font_match(test_vram,0x23e,0,24,12,16);
    assert(glyph && glyph->codepoint=='Y');
    assert(a2_hd_guest_advance(0xff59,12)==glyph->advance);
    assert(a2_hd_guest_advance(0x0059,12)==12); /* Japanese glyph is not Latin Y. */
    for(int s=1;s<=4;s++)for(int y=0;y<16*s;y++)for(int x=0;x<12*s;x++)
        assert(a2_hd_font_alpha(glyph,x,y,s)==alpha_oracle(glyph,x,y,s));
    test_vram[280*1024+896]^=1;
    assert(!a2_hd_font_match(test_vram,0x23e,0,24,12,16));
}

int main(void) {
    test_alpha_memoization();
    test_coverage_view();
    assert(setenv("A2_HDUI", "1", 1) == 0);
    test_english_source();
    bank24();
    /* Native Cyrillic Ш uses fixed advance6; natural outline metrics must
       distinguish it from the narrow exclamation mark, not squeeze it. */
    assert(a2_hd_guest_advance(0xff59, 6) > 6);
    assert(a2_hd_guest_advance(0xff21, 6) < 6);
    assert(a2_hd_guest_advance(0x0021, 12) == 12); /* original JP cell */
    assert(a2_hd_guest_advance(0xff10, 9) == 9);  /* control/outside bank */
    test_ir = 1;
    assert(a2_hd_guest_advance(0xff59, 6) == 6);
    test_ir = 3;
    PSX_RAM[0x14c888+100] ^= 1;
    assert(a2_hd_guest_advance(0xff59, 6) == 6); /* unknown bank */
    bank24();

    upload(0xff53, 896, 280, 24); /* Cyrillic Т: exact native cache */
    assert(!a2_hd_font_match(test_vram,0x23e,0,24,6,24)); /* no token metadata */
    a2_hd_guest_note(0xff53,896,0,24);
    const A2HDGlyph *glyph = a2_hd_font_match(test_vram,0x23e,0,24,6,24);
    assert(glyph && glyph->codepoint == 0x0422);
    assert(!a2_hd_font_match(test_vram,0x2be,0,24,6,24)); /* 8bpp */
    assert(!a2_hd_font_match(test_vram,0x23e,0,24,13,24));
    assert(!a2_hd_font_match(test_vram,0x23e,0,24,6,16));
    test_vram[280*1024+896] ^= 1;
    assert(!a2_hd_font_match(test_vram,0x23e,0,24,6,24)); /* overwritten cache */
    upload(0xff53,896,280,24);
    int ink=0, edge=0;
    for (int y=0;y<72;y++) for(int x=0;x<36;x++) {
        unsigned a = a2_hd_font_alpha(glyph,x,y,3);
        ink += a == 255; edge += a > 0 && a < 255;
    }
    assert(ink > 0 && edge > 0);
    assert(a2_hd_font_alpha(glyph,-1,0,3)==0);
    assert(a2_hd_font_alpha(glyph,36,0,3)==0);
    a2_hd_font_reset();
    assert(!a2_hd_font_match(test_vram,0x23e,0,24,6,24));
    puts("HD font source identity, proportional metrics and coverage passed");
    return 0;
}
