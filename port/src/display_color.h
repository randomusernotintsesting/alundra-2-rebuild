#ifndef A2_DISPLAY_COLOR_H
#define A2_DISPLAY_COLOR_H
#include <stdint.h>

/* Presentation arithmetic only. Native VRAM and its STP bit stay RGB555. */
static inline uint32_t display_rgb(int r,int g,int b) {
    return 0xff000000u|((uint32_t)r<<16)|((uint32_t)g<<8)|(uint32_t)b;
}
static inline uint32_t display_from_555(uint16_t c) {
    return display_rgb((c&31)*8,((c>>5)&31)*8,((c>>10)&31)*8);
}
static inline int display_clamp(int c) { return c<0?0:c>255?255:c; }
static inline uint32_t display_blend(uint32_t before,int r,int g,int b,int mode) {
    int br=(before>>16)&255,bg=(before>>8)&255,bb=before&255;
    switch(mode) {
    case 0:r=(br+r)/2;g=(bg+g)/2;b=(bb+b)/2;break;
    case 1:r=br+r;g=bg+g;b=bb+b;break;
    case 2:r=br-r;g=bg-g;b=bb-b;break;
    default:r=br+r/4;g=bg+g/4;b=bb+b/4;break;
    }
    return display_rgb(display_clamp(r),display_clamp(g),display_clamp(b));
}
static inline uint32_t display_coverage(uint32_t before,uint32_t after,unsigned a) {
    if(!a)return before;if(a==255)return after;
    uint32_t result=0xff000000u;
    for(unsigned shift=0;shift<24;shift+=8) {
        unsigned b=(before>>shift)&255,f=(after>>shift)&255;
        result|=((b*(255-a)+f*a+127)/255)<<shift;
    }
    return result;
}
static inline uint32_t display_tex_color(uint32_t before,int r,int g,int b,
                                         int semi,uint16_t texel,int mode) {
    if(!texel)return before;
    r=display_clamp((((texel&31)*8)*r)>>7);
    g=display_clamp(((((texel>>5)&31)*8)*g)>>7);
    b=display_clamp(((((texel>>10)&31)*8)*b)>>7);
    return semi&&(texel&0x8000)?display_blend(before,r,g,b,mode):display_rgb(r,g,b);
}
#endif
