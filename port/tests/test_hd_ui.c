#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../src/hd_ui.c"
#include "fixtures/en_title_source.h"
static uint16_t vram[1024*512];
static int enabled=1;
int a2_hd_font_enabled(void) {return enabled;}
static void english_title_sources(void) {
    a2_hd_ui_set_language(2);
    for(unsigned choice=0;choice<2;choice++) {
        unsigned u=64+64*choice;const A2HDPlate *found[128];
        memset(vram,0,sizeof vram);
        for(unsigned y=0;y<16;y++)for(unsigned x=0;x<64;x++)
            vram[(240+y)*1024+(u+x)/2]|=en_title_source[choice][y*64+x]<<(((u+x)&1)*8);
        unsigned n=a2_hd_ui_prepare(vram,128,u,240,u+63,255,found,128);
        assert(n==1);assert(found[0]->u==u&&found[0]->v==240);
        unsigned fractional=0;
        for(unsigned i=0;i<64*16*16;i++)fractional+=found[0]->alpha[i]>0&&found[0]->alpha[i]<255;
        assert(fractional>100);
        a2_hd_ui_set_language(1);
        assert(!a2_hd_ui_prepare(vram,128,u,240,u+63,255,found,128));
        a2_hd_ui_set_language(2);vram[240*1024+u/2]^=1;
        assert(!a2_hd_ui_prepare(vram,128,u,240,u+63,255,found,128));
    }
    a2_hd_ui_set_language(0);memset(vram,0,sizeof vram);
}
static void all_source_formats(void) {
    const A2HDPlate *found[128];
    unsigned eight_bit=0;
    for(unsigned i=0;i<a2_hd_plate_count;i++) {
        const A2HDPlate *p=&a2_hd_plates[i];
        int mode=0;
        for(unsigned j=0;j<p->width*p->height;j++)mode|=p->source[j]>15;
        eight_bit+=mode;
        memset(vram,0,sizeof vram);
        for(unsigned y=0;y<p->height;y++)for(unsigned x=0;x<p->width;x++) {
            unsigned u=p->u+x,shift=(u&(mode?1:3))*(mode?8:4);
            unsigned pos=(p->v+y)*1024+(u>>(mode?1:2));
            unsigned mask=mode?255:15;
            vram[pos]=(vram[pos]&~(mask<<shift))|(p->source[y*p->width+x]<<shift);
        }
        unsigned count=a2_hd_ui_prepare(vram,mode<<7,p->u,p->v,
                                        p->u+p->width-1,p->v+p->height-1,found,128);
        int matched=0;
        for(unsigned j=0;j<count;j++)matched+=found[j]==p;
        assert(matched==1);
        vram[p->v*1024+(p->u>>(mode?1:2))]^=1U<<((p->u&(mode?1:3))*(mode?8:4));
        count=a2_hd_ui_prepare(vram,mode<<7,p->u,p->v,
                              p->u+p->width-1,p->v+p->height-1,found,128);
        for(unsigned j=0;j<count;j++)assert(found[j]!=p);
    }
    assert(eight_bit>=2); /* Brightness's actual 8bpp index source, not 4bpp. */
}
static void shop_sources(void) {
    for(unsigned i=0;i<a2_hd_shop_plate_count;i++) {
        a2_hd_ui_set_language(i<3?0:2);
        const A2HDPlate *p=&a2_hd_shop_plates[i],*found[128];
        memset(vram,0,sizeof vram);
        for(unsigned y=0;y<p->height;y++)for(unsigned x=0;x<p->width;x++)
            vram[(p->v+y)*1024+(p->u+x)/4]|=p->source[y*p->width+x]<<(((p->u+x)%4)*4);
        unsigned n=a2_hd_ui_prepare(vram,0,p->u,p->v,p->u+p->width-1,p->v+p->height-1,found,128);
        int matched=0;for(unsigned j=0;j<n;j++)matched+=found[j]==p;assert(matched==1);
    }
    a2_hd_ui_set_language(0);memset(vram,0,sizeof vram);
}
int main(void) {
    english_title_sources();
    shop_sources();
    int bounds[4]={-1,-2,-3,-4};
    assert(!a2_hd_ui_bounds(NULL,0,bounds));assert(bounds[0]==-1&&bounds[3]==-4);
    const A2HDPlate *regions[]={&a2_hd_plates[0],&a2_hd_plates[4],&a2_hd_plates[55]};
    assert(a2_hd_ui_bounds(regions,3,bounds));
    assert(bounds[0]==0&&bounds[1]==0&&bounds[2]==244&&bounds[3]==200);
    const A2HDPlate *p=&a2_hd_plates[0], *found[16];
    for(unsigned y=0;y<p->height;y++)for(unsigned x=0;x<p->width;x++) {
        unsigned pos=(256+p->v+y)*1024+768+(p->u+x)/4;
        unsigned shift=((p->u+x)&3)*4;
        vram[pos]=(vram[pos]&~(15<<shift))|(p->source[y*p->width+x]<<shift);
    }
    assert(a2_hd_ui_prepare(vram,0x3c,0,0,71,23,found,16)==1);
    assert(found[0]==p);
    /* A parent sprite may contain a whole plate or draw only a clipped part. */
    assert(a2_hd_ui_prepare(vram,0x3c,0,0,135,127,found,16)==1);
    assert(a2_hd_ui_prepare(vram,0x3c,20,6,30,12,found,16)==1);
    assert(a2_hd_ui_prepare(vram,0x3c,144,0,200,24,found,16)==0);
    vram[256*1024+768]^=1;
    assert(a2_hd_ui_prepare(vram,0x3c,0,0,71,23,found,16)==0);
    vram[256*1024+768]^=1;
    enabled=0;
    assert(a2_hd_ui_prepare(vram,0x3c,0,0,71,23,found,16)==0);
    enabled=1;
    assert(a2_hd_ui_prepare(vram,0x3c,0,0,71,23,found,16)==1);
    for(int i=0;i<16;i++)vram[500*1024+i]=i==15?0:(uint16_t)(0x8000+i*0x421);
    A2HDUISample s;
    int antialias=0,ink=0;
    for(int y=0;y<24*4;y++)for(int x=0;x<72*4;x++) {
        assert(a2_hd_ui_sample(found,1,vram,500<<6,x*64,y*64,&s));
        antialias+=s.alpha>0&&s.alpha<255;ink+=s.alpha==255;
        if(x<8 || y<8)assert(s.alpha==0); /* untouched plate frame */
    }
    assert(antialias>0&&ink>0);
    assert(!a2_hd_ui_sample(found,1,vram,500<<6,72*256,0,&s));
    all_source_formats();
    a2_hd_ui_set_language(2);
    for(unsigned i=0;i<a2_hd_en_plate_count;i++) {
        const A2HDPlate *p=&a2_hd_en_plates[i];const A2HDPlate *found[128];
        int mode=0;for(unsigned j=0;j<p->width*p->height;j++)mode|=p->source[j]>15;
        memset(vram,0,sizeof vram);
        for(unsigned y=0;y<p->height;y++)for(unsigned x=0;x<p->width;x++) {
            unsigned u=p->u+x,pos=(p->v+y)*1024+(u>>(mode?1:2)),shift=(u&(mode?1:3))*(mode?8:4);
            vram[pos]=(vram[pos]&~((mode?255u:15u)<<shift))|(p->source[y*p->width+x]<<shift);
        }
        unsigned n=a2_hd_ui_prepare(vram,mode<<7,p->u,p->v,p->u+p->width-1,p->v+p->height-1,found,128);
        int seen=0;for(unsigned j=0;j<n;j++)seen+=found[j]==p;assert(seen==1);
        a2_hd_ui_set_language(1);
        assert(!a2_hd_ui_prepare(vram,mode<<7,p->u,p->v,p->u+p->width-1,p->v+p->height-1,found,128));
        a2_hd_ui_set_language(2);
    }
    puts("HD plate RU/EN full-source identity, JP isolation, contained regions and alpha passed");
    return 0;
}
