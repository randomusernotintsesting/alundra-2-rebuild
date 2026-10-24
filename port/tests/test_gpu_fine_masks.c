/* Visibility mask behavior on real Metal: clipped origins/byte boundaries,
 * deferred immutable masks, mixed draws, zero masks, bounded pool and retry. */
#include "gpu_fine.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
static char error[2048];
static A2FineParams triangle(unsigned width,unsigned height,unsigned red,unsigned green,unsigned blue) {
    A2FineParams p={0};p.width=width;p.height=height;p.clip[2]=width-1;p.clip[3]=height-1;
    p.p[0]=(A2FineVertex){0,0,red,green,blue,0,0,0};
    p.p[1]=(A2FineVertex){(int64_t)width*65536,0,red,green,blue,0,0,0};
    p.p[2]=(A2FineVertex){0,(int64_t)height*65536,red,green,blue,0,0,0};
    return p;
}
static void alloc_surfaces(unsigned width,unsigned height,uint16_t **low,uint32_t **rgb) {
    size_t page=(size_t)sysconf(_SC_PAGESIZE),pixels=(size_t)width*height;
    size_t lb=(pixels*2+page-1)/page*page,rb=(pixels*4+page-1)/page*page;
    assert(!posix_memalign((void **)low,page,lb));assert(!posix_memalign((void **)rgb,page,rb));
    memset(*low,0,lb);memset(*rgb,0,rb);
}
static void origins_and_order(void) {
    uint16_t *low;uint32_t *rgb;alloc_surfaces(32,24,&low,&rgb);
    A2FineGpu *c=a2_fine_gpu_create(32,24,low,rgb,error,sizeof error);assert(c);
    A2FineParams p=triangle(32,24,248,0,0);p.clip[0]=1;p.clip[1]=1;p.clip[2]=17;p.clip[3]=4;
    uint8_t *mask=NULL;
    assert(a2_fine_gpu_enqueue_masked(c,&p,NULL,&mask,error,sizeof error)&&mask);
    for(unsigned i=0;i<12;i++)assert(mask[i]==0);
    mask[0]=1;mask[1]=1;mask[2]=1;mask[9]=1; /* (1,1),(9,1),(17,1),(1,4). */
    p.p[0].r=p.p[1].r=p.p[2].r=0;p.p[0].b=p.p[1].b=p.p[2].b=248;p.state[3]=4;
    assert(a2_fine_gpu_enqueue_masked(c,&p,NULL,&mask,error,sizeof error)&&mask);
    for(unsigned i=0;i<12;i++)assert(mask[i]==0);
    mask[1]=1;mask[3]=2; /* Average blue at (9,1) and (2,2). */
    p=triangle(32,24,0,248,0);p.state[0]=1<<5;p.state[3]=4;
    assert(a2_fine_gpu_enqueue(c,&p,NULL,error,sizeof error));
    p=triangle(32,24,0,0,248);
    assert(a2_fine_gpu_enqueue_masked(c,&p,NULL,&mask,error,sizeof error)&&mask); /* All zero: no draw. */
    for(unsigned i=0;i<32*24/8;i++)assert(mask[i]==0);
    assert(a2_fine_gpu_stats(c).submissions==0);
    for(unsigned i=0;i<32*24;i++)assert(low[i]==0&&rgb[i]==0);
    mask=(uint8_t *)1;p.clip[0]=-1;
    assert(!a2_fine_gpu_enqueue_masked(c,&p,NULL,&mask,error,sizeof error)&&!mask);
    assert(a2_fine_gpu_sync(c,error,sizeof error));
    assert(low[32+1]==0x03ff&&rgb[32+1]==0xfff8f800);
    assert(low[32+9]==(15|(31<<5)|(15<<10))&&rgb[32+9]==0xff7cf87c);
    assert(low[32+17]==0x03ff&&rgb[32+17]==0xfff8f800);
    assert(low[4*32+1]==0x03ff&&rgb[4*32+1]==0xfff8f800);
    assert(low[2*32+2]==((31<<5)|(15<<10))&&rgb[2*32+2]==0xff00f87c);
    assert(low[3*32+3]==0x03e0&&rgb[3*32+3]==0xff00f800);
    assert(low[23*32+31]==0&&rgb[23*32+31]==0);
    A2FineGpuStats stats=a2_fine_gpu_stats(c);assert(stats.masked_triangles==3&&stats.submissions==1);
    a2_fine_gpu_destroy(c);free(low);free(rgb);
}
static void bounded_immutable_masks(void) {
    uint16_t *low;uint32_t *rgb;alloc_surfaces(1024,1024,&low,&rgb);
    A2FineGpu *c=a2_fine_gpu_create(1024,1024,low,rgb,error,sizeof error);assert(c);
    A2FineParams p=triangle(1024,1024,248,0,0);
    p.p[1].x=8*65536;p.p[2].y=8*65536; /* Large reserved clip, one occupied tile. */
    uint8_t *mask=NULL;unsigned accepted=0;
    for(unsigned i=0;i<100;i++) {
        mask=(uint8_t *)1;
        if(!a2_fine_gpu_enqueue_masked(c,&p,NULL,&mask,error,sizeof error)){assert(!mask);break;}
        assert(mask);assert(mask[128]==0);mask[128]=(uint8_t)(i?4:2);
        accepted++;
        p.p[0].r=p.p[1].r=p.p[2].r=0;p.p[0].b=p.p[1].b=p.p[2].b=248;
    }
    assert(accepted>8&&accepted<100);
    A2FineGpuStats stats=a2_fine_gpu_stats(c);
    assert(stats.submissions==0&&stats.queued_triangles==accepted);
    assert(a2_fine_gpu_sync(c,error,sizeof error));
    assert(low[1024+1]==0x001f&&rgb[1024+1]==0xfff80000); /* Original survives every growth. */
    assert(low[1024+2]==0x7c00&&rgb[1024+2]==0xff0000f8);
    assert(a2_fine_gpu_enqueue_masked(c,&p,NULL,&mask,error,sizeof error)&&mask);
    for(unsigned i=0;i<1024*1024/8;i++)assert(mask[i]==0); /* Retired pool gets zeroed. */
    mask[128]=2;
    assert(a2_fine_gpu_sync(c,error,sizeof error));
    assert(low[1024+1]==0x7c00&&rgb[1024+1]==0xff0000f8);
    a2_fine_gpu_destroy(c);free(low);free(rgb);
}
int main(void) {
    origins_and_order();bounded_immutable_masks();
    puts("PASS: Metal visibility masks, clipped origins/stride, immutable growth, mixed ordering, zero masks, bounded retry");
}
