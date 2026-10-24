/* Independent scalar oracle for the TV raster, including untouched pitch. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "frame_compose.h"
static uint16_t *source;
static uint32_t *argb;
static int use_argb;
static int width, height, row_calls;
static int wrap(int n, int extent) { n %= extent; return n < 0 ? n + extent : n; }
const uint16_t *gpu_display_row(int y) {
    row_calls++;
    return source + (size_t)wrap(y, height) * width;
}
const uint32_t *gpu_display_argb_row(int y) {
    if(!use_argb)return NULL;row_calls++;
    return argb+(size_t)wrap(y,height)*width;
}
static uint32_t color(uint16_t c) {
    uint32_t r = (c & 31) << 3, g = ((c >> 5) & 31) << 3;
    uint32_t b = ((c >> 10) & 31) << 3;
    return 0xff000000u | (r << 16) | (g << 8) | b;
}
int main(void) {
    for(int bank=0;bank<=256;bank+=256) {
        const A2CinemaRaster original={0,bank,320,216,0,12,320,240,1,4};
        A2CinemaRaster game=original;
        assert(a2_gameplay_canvas(&game));
        assert(game.dx==0 && game.dy==bank && game.dw==320 && game.dh==216);
        assert(game.xo==0 && game.yo==0 && game.cw==320 && game.ch==216);
        assert(game.on==1 && game.overlay==4);
        for(int field=0;field<10;field++) {
            A2CinemaRaster unusual=original;
            switch(field) {
            case 0: unusual.dx=1; break;
            case 1: unusual.dy=42; break;
            case 2: unusual.dw=256; break;
            case 3: unusual.dh=480; break;
            case 4: unusual.xo=1; break;
            case 5: unusual.yo=30; break;
            case 6: unusual.cw=512; break;
            case 7: unusual.ch=480; break;
            case 8: unusual.on=0; break;
            case 9: unusual.overlay=5; break;
            }
            A2CinemaRaster saved=unusual;
            assert(!a2_gameplay_canvas(&unusual));
            assert(!memcmp(&unusual,&saved,sizeof unusual));
        }
    }
    const int cases[][8] = {
        {0,0,320,240,0,0,320,240}, {17,256,320,480,0,0,320,480},
        {0,0,320,216,0,0,320,216}, {0,256,320,216,0,0,320,216},
        {1013,503,64,32,3,4,80,48}, {-17,-23,51,39,11,9,73,61},
        {2041,1021,1024,512,0,0,1024,512}, {7,9,55,33,-7,-5,41,29},
        {1,2,20,20,100,100,40,30}, {1,2,0,0,0,0,40,30},
        {3,5,28,18,-40,0,30,20}, {2,3,13,11,9,8,17,15}
    };
    for (int scale=1; scale<=4; scale++) {
        width=1024*scale; height=512*scale;
        source=malloc((size_t)width*height*sizeof *source); assert(source);
        for (size_t i=0; i<(size_t)width*height; i++) source[i]=(uint16_t)(i*37u+(i>>5));
        argb=malloc((size_t)width*height*sizeof *argb);assert(argb);
        for(size_t i=0;i<(size_t)width*height;i++)argb[i]=0xff000000u|((i*1717u+(i>>7))&0xffffffu);
        for(use_argb=0;use_argb<=1;use_argb++)for (unsigned k=0; k<sizeof cases/sizeof cases[0]; k++) {
            const int *v=cases[k]; int cw=v[6]*scale,ch=v[7]*scale,pitch=cw+13;
            size_t count=(size_t)pitch*(ch+2);
            uint32_t *actual=malloc(count*4), *expected=malloc(count*4);
            assert(actual && expected);
            for (size_t i=0;i<count;i++) actual[i]=expected[i]=0x12345678;
            for (int y=0;y<ch;y++) for (int x=0;x<cw;x++) {
                int px=x-v[4]*scale,py=y-v[5]*scale;
                uint32_t out=0xff000000u;
                if (px>=0 && py>=0 && px<v[2]*scale && py<v[3]*scale)
                    {size_t at=(size_t)wrap(v[1]*scale+py,height)*width+wrap(v[0]*scale+px,width);
                     out=use_argb?argb[at]:color(source[at]);}
                expected[pitch+(size_t)y*pitch+x]=out;
            }
            row_calls=0;
            a2_compose_frame(actual+pitch,pitch,scale,v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7]);
            assert(!memcmp(actual,expected,count*4));
            assert(row_calls<=ch);
            free(actual); free(expected);
        }
        free(source);free(argb);
    }
    puts("Frame composition: scalar oracle, IR1–4, borders, clipping, wrap and pitch passed");
    return 0;
}
