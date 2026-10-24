/* Wrong source/CLUT must reject the entire portrait; samples keep explicit RGBA. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "../src/hd_portraits.h"
#include "../assets/hd_portraits_data.h"
static uint16_t vram[1024*512], before[1024*512];
static const unsigned page=0x9b,clut=0x7ef0;
static void upload(const A2HDPortrait *a,unsigned tp,unsigned cp) {
    for(unsigned y=0;y<48;y++)for(unsigned x=0;x<40;x+=2)
        vram[((((tp>>4)&1)*256+40+y)&511)*1024+(((tp&15)*64+(64+x)/2)&1023)] =
            a->source[y*40+x]|(a->source[y*40+x+1]<<8);
    /* Split the row explicitly: independent from production's masked reads,
       and avoids a local AppleClang O3 miscompile of wrapped vector stores. */
    unsigned cx=(cp&63)*16,cy=(cp>>6)&511,first=1024-cx;
    if(first>256)first=256;
    memcpy(vram+cy*1024+cx,a->palette,first*sizeof(uint16_t));
    memcpy(vram+cy*1024,a->palette+first,(256-first)*sizeof(uint16_t));
}
static void all_identities(void) {
    for(unsigned i=0;i<14;i++) {
        const A2HDPortrait *a=&a2_hd_portraits_assets[i];
        memset(vram,0,sizeof vram);upload(a,page,clut);
        memcpy(before,vram,sizeof before);
        assert(a2_hd_portrait_prepare(a2_hd_portraits_assets,14,vram,page,clut,64,40,103,87)==a);
        /* Restricting sampled bounds cannot weaken the full signature. */
        assert(a2_hd_portrait_prepare(a2_hd_portraits_assets,14,vram,page,clut,64,40,64,40)==a);
        assert(!a2_hd_portrait_prepare(a2_hd_portraits_assets,14,vram,page,clut,0,0,63,39));
        assert(!a2_hd_portrait_prepare(a2_hd_portraits_assets,14,vram,page&~0x180u,clut,64,40,103,87));
        assert(!a2_hd_portrait_prepare(a2_hd_portraits_assets,14,vram,page|0x100,clut,64,40,103,87));
        assert(!memcmp(vram,before,sizeof vram));
        vram[(256+87)*1024+704+51]^=0x100;
        assert(!a2_hd_portrait_prepare(a2_hd_portraits_assets,14,vram,page,clut,64,40,64,40));
        upload(a,page,clut);
        vram[507*1024+768+255]^=1; /* Even an unused palette entry is identity. */
        assert(!a2_hd_portrait_prepare(a2_hd_portraits_assets,14,vram,page,clut,64,40,64,40));
        upload(a,page,clut);
        assert(!a2_hd_portrait_prepare(NULL,0,vram,page,clut,64,40,103,87));
    }
    /* Texture page and CLUT addressing wrap just as native GPU sampling does. */
    upload(&a2_hd_portraits_assets[5],0x9f,0x7fff);
    for(unsigned p=0;p<256;p++) {
        unsigned address=511*1024+((1008+p)&1023);
        assert(vram[address]==a2_hd_portraits_assets[5].palette[p]);
    }
    for(unsigned y=0;y<48;y++)for(unsigned x=0;x<40;x+=2) {
        unsigned want=a2_hd_portraits_assets[5].source[y*40+x]|(a2_hd_portraits_assets[5].source[y*40+x+1]<<8);
        unsigned got=vram[(296+y)*1024+992+x/2];
        assert(got==want);
    }
    memcpy(before,vram,sizeof before);
    assert(a2_hd_portrait_prepare(a2_hd_portraits_assets,14,vram,0x9f,0x7fff,64,40,103,87)==&a2_hd_portraits_assets[5]);
    assert(!memcmp(vram,before,sizeof vram));
}
static void exact_sampling(void) {
    static uint8_t rgba[320*384*4];
    A2HDPortrait a={320,384,NULL,NULL,rgba};
    A2HDPortraitSample p;
    rgba[0]=19;rgba[1]=29;rgba[2]=39;rgba[3]=0;
    memcpy(rgba+4,(uint8_t[]){0,0,0,255},4);
    memcpy(rgba+(383*320+319)*4,(uint8_t[]){251,129,63,128},4);
    assert(a2_hd_portrait_sample(&a,0,64*256,40*256,&p));
    assert(p.r==19 && p.g==29 && p.b==39 && p.a==0);
    assert(a2_hd_portrait_sample(&a,0,64*256+32,40*256,&p));
    assert(p.r==0 && p.g==0 && p.b==0 && p.a==255);
    assert(a2_hd_portrait_sample(&a,0,104*256-1,88*256-1,&p));
    assert(p.r==251 && p.g==129 && p.b==63 && p.a==128);
    assert(!a2_hd_portrait_sample(&a,0,104*256,40*256,&p));
    assert(!a2_hd_portrait_sample(&a,0,64*256,88*256,&p));
    assert(!a2_hd_portrait_sample(NULL,0,64*256,40*256,&p));
    /* E2 forces U bit6 and V bits3/5, keeping the fractional subpixel. */
    unsigned window=8|(5<<5)|(8<<10)|(5<<15);
    assert(a2_hd_portrait_sample(&a,window,32,0,&p));
    assert(p.r==0 && p.g==0 && p.b==0 && p.a==255);
    assert(a2_hd_portrait_sample(&a,0,(256+64)*256+32,40*256,&p));
    assert(p.r==0 && p.a==255);
    /* Actual dimensions, not a hardcoded 4x/8x assumption. */
    a.width=2;a.height=1;
    assert(a2_hd_portrait_sample(&a,0,84*256,40*256,&p));
    assert(p.r==0 && p.a==255);
}
int main(void) { all_identities();exact_sampling();puts("HD portraits: fourteen identities, full CLUT, fallback, window, dimensions and RGBA passed"); }
