/* Palette-aware fine art must not freeze colors or treat index0 as alpha0. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "hd_art.h"
static uint16_t vram[1024*512];
static const uint8_t source4[]={0,7,2,15};
static uint32_t fine[2*2*16];
static A2HDArt art={8,16,2,2,4,source4,fine};

/* Identity covers the complete asset even for one scanline draw. Packing
 * must keep odd U and wrapped VRAM rows distinct from neighbouring bytes. */
static void byte_source_boundaries(void) {
    static uint8_t source[256*17];
    const A2HDArt *matched[1];
    const unsigned origins[]={0,1,126,127,128,129,254,255};
    for(unsigned page=0;page<32;page+=15)for(unsigned k=0;k<sizeof origins/sizeof *origins;k++) {
        unsigned u=origins[k],width=256-u,height=17,v=239;
        A2HDArt a={u,v,width,height,8,source,fine};
        memset(vram,0xa5,sizeof vram);
        unsigned tx=(page&15)*64,ty=((page>>4)&1)*256;
        for(unsigned y=0;y<height;y++)for(unsigned x=0;x<width;x++) {
            unsigned value=(x*137+y*73+19)&255,coord=u+x;
            source[y*width+x]=(uint8_t)value;
            uint16_t *word=&vram[((ty+v+y)&511)*1024+((tx+coord/2)&1023)];
            unsigned shift=(coord&1)*8;
            *word=(uint16_t)((*word&~(255u<<shift))|(value<<shift));
        }
        assert(a2_hd_art_prepare(&a,1,vram,page|0x80,u,v,u,v,matched,1)==1);
        /* Each byte, including the last row outside the submitted UV range. */
        for(unsigned y=0;y<height;y++)for(unsigned x=0;x<width;x++) {
            unsigned coord=u+x,shift=(coord&1)*8;
            uint16_t *word=&vram[((ty+v+y)&511)*1024+((tx+coord/2)&1023)];
            *word^=(uint16_t)(1u<<shift);
            assert(!a2_hd_art_prepare(&a,1,vram,page|0x80,u,v,u,v,matched,1));
            *word^=(uint16_t)(1u<<shift);
        }
        if(u&1) {
            vram[((ty+v)&511)*1024+((tx+u/2)&1023)]^=0xff;
            assert(a2_hd_art_prepare(&a,1,vram,page|0x80,u,v,u,v,matched,1)==1);
        }
    }
    /* Both partial end words straddle X1023 -> X0, within the same row. */
    const uint8_t two[]={137,255};
    A2HDArt a={127,255,2,1,8,two,fine};
    vram[511*1024+1023]=0x8900;vram[511*1024]=0x00ff;
    assert(a2_hd_art_prepare(&a,1,vram,0x9f,127,255,128,255,matched,1)==1);
    vram[511*1024+1023]^=0xff;vram[511*1024]^=0xff00;
    assert(a2_hd_art_prepare(&a,1,vram,0x9f,127,255,128,255,matched,1)==1);
}

static void language_selection(void) {
    const A2HDArt *matched[2];
    /* A forbidden language's source must never be read. Labels deliberately
       share one native source, as the resident loading texture does. */
    A2HDArt labels[]={
        {8,16,2,2,4,NULL,NULL,4},
        {8,16,2,2,4,source4,fine,1},
        {8,16,2,2,4,source4,fine,6},
        {8,16,2,2,4,source4,fine,0}
    };
    a2_hd_art_set_language(0);
    assert(a2_hd_art_prepare(labels,4,vram,0,8,16,9,17,matched,1)==1);
    assert(matched[0]==&labels[1]);
    labels[0].width=0;
    for(int language=1;language<=2;language++) {
        a2_hd_art_set_language(language);
        assert(a2_hd_art_prepare(labels,4,vram,0,8,16,9,17,matched,2)==2);
        assert(matched[0]==&labels[2] && matched[1]==&labels[3]);
    }
    a2_hd_art_set_language(-1); /* Invalid input leaves the selected locale. */
    a2_hd_art_set_language(32);
    assert(a2_hd_art_prepare(labels,4,vram,0,8,16,9,17,matched,1)==1);
    assert(matched[0]==&labels[2]);
    vram[17*1024+2]^=1;
    assert(!a2_hd_art_prepare(labels,4,vram,0,8,16,9,17,matched,2));
    vram[17*1024+2]^=1;
    a2_hd_art_set_language(0);
}

int main(void) {
    byte_source_boundaries();memset(vram,0,sizeof vram);
    const A2HDArt *matched[2]; A2HDArtSample s;
    /* page0 source pixel (8,16) packs at VRAMword2, not byte8. */
    vram[16*1024+2]=0x0070; vram[17*1024+2]=0x00f2;
    for(unsigned i=0;i<64;i++) fine[i]=0xff000000u; /* fully covered index0 */
    fine[1]=0x80800700u; /* indices0/7, mix128, coverage128 */
    vram[480*1024]=0x801f; vram[480*1024+7]=0x03e0;
    assert(a2_hd_art_prepare(&art,1,vram,0,8,16,9,17,matched,2)==1);
    assert(a2_hd_art_sample(matched,1,vram,480u<<6,8*256,16*256,&s));
    assert(s.first==0x801f && s.second==0x801f && s.mix==0 && s.coverage==255);
    assert(a2_hd_art_sample(matched,1,vram,480u<<6,8*256+64,16*256,&s));
    assert(s.first==0x801f && s.second==0x03e0 && s.mix==128 && s.coverage==128);
    vram[480*1024]=0x7c00; vram[480*1024+7]=0;
    assert(a2_hd_art_sample(matched,1,vram,480u<<6,8*256+64,16*256,&s));
    assert(s.first==0x7c00 && s.second==0); /* live state, nonzero transparent index */
    assert(!a2_hd_art_sample(matched,1,vram,0,8*256-1,16*256,&s));
    assert(!a2_hd_art_sample(matched,1,vram,0,10*256,16*256,&s));
    assert(a2_hd_art_prepare(&art,1,vram,0,9,17,9,17,matched,1)==1); /* contained draw */
    vram[16*1024+2]^=0x1000; /* unrelated packed nibble outside source remains irrelevant */
    assert(a2_hd_art_prepare(&art,1,vram,0,8,16,9,17,matched,1)==1);
    vram[17*1024+2]^=1; /* changed source outside sampled1x1 still rejects complete art */
    assert(a2_hd_art_prepare(&art,1,vram,0,8,16,8,16,matched,1)==0);
    vram[17*1024+2]^=1;
    assert(a2_hd_art_prepare(&art,1,vram,0x80,8,16,9,17,matched,1)==0);
    assert(a2_hd_art_prepare(&art,1,vram,0,8,16,9,17,matched,0)==0);
    language_selection();
    const uint8_t source8[]={0,137,2,255};
    A2HDArt art8={8,16,2,2,8,source8,fine};
    vram[16*1024+4]=0x8900; vram[17*1024+4]=0xff02;
    assert(a2_hd_art_prepare(&art8,1,vram,0x80,8,16,9,17,matched,1)==1);
    assert(a2_hd_art_prepare(&art8,1,vram,0,8,16,9,17,matched,1)==0);
    /* E2 mask bits clear selected integer address bits, never fine fractions. */
    int u=0xff80,v=0xff40;
    a2_hd_art_window_uv(0x731c,&u,&v);
    assert(u==0xff80 && v==0x3f40); /* maskE0/C0, offsetE0/00 */
    u=-64;v=256*256+192; a2_hd_art_window_uv(0,&u,&v);
    assert(u==0xffc0 && v==192);
    puts("HD art: exact source, formats, CLUT states, transparency and texture-window coordinates passed");
    return 0;
}
