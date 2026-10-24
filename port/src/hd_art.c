#include "hd_art.h"
#include <string.h>

static unsigned selected_language=1; /* Default Russian; one bit per locale. */

void a2_hd_art_set_language(int language) {
    if(language>=0 && language<=2) selected_language=1u<<(unsigned)language;
}

unsigned a2_hd_art_prepare(const A2HDArt *assets,unsigned asset_count,
                          const uint16_t *vram,uint32_t tpage,
                          int u0,int v0,int u1,int v1,
                          const A2HDArt **out,unsigned capacity) {
    unsigned mode=(tpage>>7)&3;
    if(mode>1 || u0<0 || v0<0 || u1>255 || v1>255 || u1<u0 || v1<v0) return 0;
    unsigned count=0,tx=(tpage&15)*64,ty=((tpage>>4)&1)*256;
    for(unsigned i=0;i<asset_count && count<capacity;i++) {
        const A2HDArt *a=&assets[i];
        if((a->language_mask && !(a->language_mask&selected_language)) ||
           a->bpp!=(mode?8:4) || !a->width || !a->height ||
           a->u+a->width>256 || a->v+a->height>256 ||
           a->u>u1 || a->v>v1 || a->u+a->width<=u0 || a->v+a->height<=v0) continue;
        int same=1;
#if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        if(mode==1) {
            /* Title art is submitted one scanline at a time. Its 8-bit
             * indices already equal the byte representation of VRAM on
             * little-endian hosts; still check the complete live source.
             * Odd U and X1023 wrap must not include neighbouring bytes. */
            unsigned start=(tx*2+a->u)&2047,first=2048-start;
            if(first>a->width)first=a->width;
            for(unsigned y=0;y<a->height && same;y++) {
                const uint8_t *row=(const uint8_t *)(vram+((ty+a->v+y)&511)*1024);
                const uint8_t *source=a->source+y*a->width;
                same=!memcmp(row+start,source,first) &&
                     !memcmp(row,source+first,a->width-first);
            }
        } else
#endif
        {
            for(unsigned y=0;y<a->height && same;y++) for(unsigned x=0;x<a->width;x++) {
                unsigned u=a->u+x;
                uint16_t word=vram[((ty+a->v+y)&511)*1024+((tx+(u>>(mode?1:2)))&1023)];
                unsigned index=(word>>((u&(mode?1:3))*(mode?8:4)))&(mode?255:15);
                if(index!=a->source[y*a->width+x]) { same=0; break; }
            }
        }
        if(same) out[count++]=a;
    }
    return count;
}

static uint16_t palette(const uint16_t *vram,uint32_t clut,unsigned index) {
    return vram[((clut>>6)&511)*1024+(((clut&63)*16+index)&1023)];
}

int a2_hd_art_sample(const A2HDArt *const *assets,unsigned count,
                     const uint16_t *vram,uint32_t clut,
                     int u_fp,int v_fp,A2HDArtSample *out) {
    for(unsigned i=0;i<count;i++) {
        const A2HDArt *a=assets[i];
        int x=u_fp-a->u*256,y=v_fp-a->v*256;
        if(x<0 || y<0 || x>=a->width*256 || y>=a->height*256) continue;
        uint32_t pixel=a->pixels[((unsigned)y>>6)*(a->width*4)+((unsigned)x>>6)];
        out->first=palette(vram,clut,pixel&255);
        out->second=palette(vram,clut,(pixel>>8)&255);
        out->mix=(uint8_t)(pixel>>16);
        out->coverage=(uint8_t)(pixel>>24);
        return 1;
    }
    return 0;
}

void a2_hd_art_window_uv(uint32_t window,int *u_fp,int *v_fp) {
    unsigned mu=(window&31)*8,mv=((window>>5)&31)*8;
    unsigned ou=((window>>10)&31)*8,ov=((window>>15)&31)*8;
    unsigned u=((uint32_t)*u_fp>>8)&255,v=((uint32_t)*v_fp>>8)&255;
    u=(u&~mu)|(ou&mu); v=(v&~mv)|(ov&mv);
    *u_fp=(int)(u*256+((unsigned)*u_fp&255));
    *v_fp=(int)(v*256+((unsigned)*v_fp&255));
}
