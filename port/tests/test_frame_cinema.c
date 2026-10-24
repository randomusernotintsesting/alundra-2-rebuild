/* Every fine picture/subtitle pixel must survive moving the cinematic bands.
 * Literal original/target bounds are independent of the layout resolver. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "frame_compose.h"
static uint16_t *vram;
static int width, height, rows;
const uint32_t *gpu_display_argb_row(int y) {(void)y;return NULL;}
const uint16_t *gpu_display_row(int y) {
    assert(y>=0 && y<height);
    rows++;
    return vram+(size_t)y*width;
}
static uint32_t color(uint16_t c) {
    return 0xff000000u | ((uint32_t)(c&31)<<19) |
           ((uint32_t)((c>>5)&31)<<11) | ((uint32_t)((c>>10)&31)<<3);
}
int main(void) {
    for(int scale=1;scale<=4;scale++) {
        width=1024*scale; height=512*scale;
        vram=malloc((size_t)width*height*2); assert(vram);
        for(size_t i=0;i<(size_t)width*height;i++)
            vram[i]=(uint16_t)(i*7919u+(i>>7)*37u);
        int w=320*scale,h=240*scale,pitch=w+17;
        size_t count=(size_t)pitch*(h+2);
        uint32_t *actual=malloc(count*4),*want=malloc(count*4);
        assert(actual && want);
        for(int buffer=0;buffer<=256;buffer+=256) {
            for(size_t i=0;i<count;i++)actual[i]=want[i]=0x12345678;
            for(int y=0;y<h;y++)for(int x=0;x<w;x++) {
                int sy=-1;
                if(y>=34*scale && y<206*scale)sy=y-34*scale;
                if(y>=207*scale && y<239*scale)sy=y-207*scale+174*scale;
                want[pitch+(size_t)y*pitch+x]=sy<0?0xff000000u:
                    color(vram[(size_t)(buffer*scale+sy)*width+x]);
            }
            A2CinemaRaster raster={0,buffer,320,216,0,12,320,240,1,5};
            A2CinemaLayout layout={0,172,34,174,32,207};
            rows=0;
            a2_compose_cinema(actual+pitch,pitch,scale,&raster,&layout);
            if(memcmp(actual,want,count*4)) {
                fprintf(stderr,"cinema picture/subtitle pixel mismatch: IR%d VRAMy%d\n",scale,buffer);
                return 1;
            }
            assert(rows==204*scale); /* no hidden second full-frame pass */
        }
        free(actual);free(want);free(vram);
    }
    puts("cinema composition: exact picture and two subtitle lines, IR1–4, both buffers, pitch guards passed");
    return 0;
}
