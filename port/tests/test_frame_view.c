/* Borrowed frame bytes must match the established composition oracle. */
#include "frame_compose.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static uint32_t *rgb;
static int width,height,mode;
const uint16_t *gpu_display_row(int y) { (void)y; abort(); }
const uint32_t *gpu_display_argb_row(int y) {
    y%=height;if(y<0)y+=height;
    if(mode==1 || (mode==2 && y==17))return NULL;
    if(mode==3 && y==17)y++;
    return rgb+(size_t)y*width;
}
static void reject(int scale,const int *v) {
    A2FrameView view={rgb,1,1,1};
    assert(!a2_frame_view(&view,scale,v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7]));
    assert(!view.pixels && !view.width && !view.height && !view.stride);
}
int main(void) {
    const int accepted[][8]={
        {0,0,320,216,0,0,320,216},{0,256,320,216,0,0,320,216},
        {17,21,320,240,0,0,320,240},{-1024,-512,320,216,0,0,320,216},
        {7,9,55,33,-7,-5,41,28},{0,0,1024,512,0,0,1024,512},
        {INT_MAX,0,1,1,0,0,1,1},{INT_MIN,0,1,1,0,0,1,1}
    };
    const int rejected[][8]={
        {0,0,320,216,0,12,320,240}, /* borders */
        {0,0,320,216,1,0,320,216},
        {0,0,319,216,0,0,320,216},
        {1000,0,320,216,0,0,320,216}, /* horizontal wrap */
        {0,400,320,216,0,0,320,216}, /* vertical wrap */
        {0,0,320,240,0,0,0,240},{0,0,320,240,0,0,1025,240},
        {0,0,320,240,0,0,320,513},{0,0,320,240,0,0,-1,240},
        {0,0,INT_MAX,INT_MAX,INT_MIN,INT_MIN,320,240}
    };
    for(int scale=1;scale<=4;scale++) {
        width=1024*scale;height=512*scale;
        size_t count=(size_t)width*height;
        rgb=malloc(count*sizeof *rgb);assert(rgb);
        for(size_t i=0;i<count;i++)rgb[i]=0xff000000u|((i*1717u+(i>>7))&0xffffffu);
        for(size_t k=0;k<sizeof accepted/sizeof *accepted;k++) {
            const int *v=accepted[k];A2FrameView view={0};
            assert(a2_frame_view(&view,scale,v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7]));
            assert(view.width==v[6]*scale && view.height==v[7]*scale && view.stride==width);
            uint32_t *copy=malloc((size_t)view.width*view.height*4);assert(copy);
            /* Normalize coordinates for the older int-based oracle. */
            a2_compose_frame(copy,view.width,scale,v[0]%1024,v[1]%512,v[2],v[3],v[4],v[5],v[6],v[7]);
            for(int y=0;y<view.height;y++)
                assert(!memcmp(view.pixels+(size_t)y*view.stride,copy+(size_t)y*view.width,(size_t)view.width*4));
            free(copy);
        }
        for(size_t k=0;k<sizeof rejected/sizeof *rejected;k++)reject(scale,rejected[k]);
        for(mode=1;mode<=3;mode++)reject(scale,accepted[0]);mode=0;
        reject(0,accepted[0]);reject(5,accepted[0]);
        assert(!a2_frame_view(NULL,scale,0,0,320,216,0,0,320,216));
        for(size_t i=0;i<count;i++)assert(rgb[i]==(0xff000000u|((i*1717u+(i>>7))&0xffffffu)));
        free(rgb);
    }
    puts("Frame view: exact IR1-4, pages, offsets, clipping; rejected borders/wrap/invalid rows; source unchanged");
    return 0;
}
