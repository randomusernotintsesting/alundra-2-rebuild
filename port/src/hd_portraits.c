#include "hd_portraits.h"
#include <stddef.h>

const A2HDPortrait *a2_hd_portrait_prepare(const A2HDPortrait *assets,unsigned count,
    const uint16_t *vram,uint32_t tpage,uint32_t clut,int u0,int v0,int u1,int v1) {
    if(!assets || !vram || ((tpage>>7)&3)!=1 || u0<0 || v0<0 || u1>255 || v1>255 ||
       u1<u0 || v1<v0 || u0>=104 || v0>=88 || u1<64 || v1<40) return 0;
    unsigned tx=(tpage&15)*64,ty=((tpage>>4)&1)*256;
    unsigned cx=(clut&63)*16,cy=(clut>>6)&511;
    for(unsigned i=0;i<count;i++) {
        const A2HDPortrait *a=&assets[i];
        if(!a->source || !a->palette || !a->rgba || !a->width || !a->height) continue;
        int same=1;
        for(unsigned p=0;p<256;p++) {
            if(vram[cy*1024+((cx+p)&1023)]!=a->palette[p]) {same=0;break;}
        }
        for(unsigned y=0;y<48 && same;y++)for(unsigned x=0;x<40;x+=2) {
            uint16_t want=(uint16_t)(a->source[y*40+x]|(a->source[y*40+x+1]<<8));
            if(vram[((ty+40+y)&511)*1024+((tx+32+x/2)&1023)]!=want) {same=0;break;}
        }
        if(same) return a;
    }
    return 0;
}

int a2_hd_portrait_sample(const A2HDPortrait *a,uint32_t window,
    int u_fp,int v_fp,A2HDPortraitSample *out) {
    if(!a || !a->rgba || !a->width || !a->height || !out) return 0;
    unsigned mu=(window&31)*8,mv=((window>>5)&31)*8;
    unsigned u=((unsigned)u_fp>>8)&255,v=((unsigned)v_fp>>8)&255;
    u=(u&~mu)|((((window>>10)&31)*8)&mu);
    v=(v&~mv)|((((window>>15)&31)*8)&mv);
    if(u<64 || u>=104 || v<40 || v>=88) return 0;
    unsigned x=((u-64)*256+((unsigned)u_fp&255))*a->width/(40*256);
    unsigned y=((v-40)*256+((unsigned)v_fp&255))*a->height/(48*256);
    const uint8_t *p=a->rgba+((size_t)y*a->width+x)*4;
    *out=(A2HDPortraitSample){p[0],p[1],p[2],p[3]};
    return 1;
}
