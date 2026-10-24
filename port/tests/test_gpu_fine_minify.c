/* Exact color contract of model_minify_pixel, independent literal expectations. */
#include "gpu_fine.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
static uint16_t native[1024*512];
static char error[2048];
static A2FineParams triangle(unsigned width,unsigned height,unsigned r,unsigned g,unsigned b) {
    A2FineParams p={0};p.width=width;p.height=height;p.clip[2]=width-1;p.clip[3]=height-1;
    p.uv[2]=p.uv[3]=65280;p.state[0]=256;p.state[3]=1|2|4|8;
    p.p[0]=(A2FineVertex){0,0,r,g,b,0,0,0};
    p.p[1]=(A2FineVertex){8*65536,0,r,g,b,0,0,0};
    p.p[2]=(A2FineVertex){0,8*65536,r,g,b,0,0,0};return p;
}
static void allocate(unsigned width,unsigned height,uint16_t **low,uint32_t **rgb) {
    size_t page=(size_t)sysconf(_SC_PAGESIZE),pixels=(size_t)width*height;
    size_t a=(pixels*2+page-1)/page*page,b=(pixels*4+page-1)/page*page;
    assert(!posix_memalign((void **)low,page,a));assert(!posix_memalign((void **)rgb,page,b));
    memset(*low,0,a);memset(*rgb,0,b);
}
static A2FineMinify footprint(unsigned count) {
    A2FineMinify f={0};f.count=count;for(unsigned i=0;i<count;i++)f.offsets[i][0]=(i&1)?384:0;return f;
}
static void transparency_rounding_stp(void) {
    uint16_t *low;uint32_t *rgb;allocate(8,8,&low,&rgb);
    A2FineGpu *c=a2_fine_gpu_create(8,8,low,rgb,error,sizeof error);assert(c);
    for(unsigned count=2;count<=16;count*=2)for(unsigned kind=0;kind<4;kind++) {
        for(unsigned i=0;i<64;i++){low[i]=0xfc00;rgb[i]=kind==3?0x7f0309f7:0xff0309f7;}
        memset(native,0,sizeof native);
        if(kind==0)native[0]=0x001f;
        if(kind==1)native[0]=0x801f;
        if(kind==2)native[1]=0x001f; /* Missing center preserves before STP. */
        a2_fine_gpu_written(c,0,0,1024,512);
        A2FineParams p=triangle(8,8,129,129,129);A2FineMinify f=footprint(count);
        uint8_t *allow=NULL,*minify=NULL;
        assert(a2_fine_gpu_enqueue_minified(c,&p,native,&f,&allow,&minify,error,sizeof error));
        assert(allow&&minify==allow+8);
        for(unsigned i=0;i<8;i++)assert(!allow[i]&&!minify[i]);
        minify[1]=2; /* Minify overrides zero ordinary allowance at (1,1). */
        f.count=0;memset(f.offsets,0,sizeof f.offsets); /* Backend must copy metadata. */
        memset(native,0,sizeof native); /* Also copy/lease native texture now. */
        assert(a2_fine_gpu_sync(c,error,sizeof error));
        if(kind==3){assert(low[9]==0xfc00&&rgb[9]==0x7f0309f7);}
        else {
            assert(low[9]==(kind==0?0x4010:0xc010));
            assert(rgb[9]==0xff7e057c); /* Separate 5-bit/8-bit averages, round half up. */
        }
        assert(low[10]==0xfc00&&rgb[10]==(kind==3?0x7f0309f7:0xff0309f7));
    }
    /* Clamp extremes before filtering; two solid colors avoid bilinear mixing. */
    for(unsigned i=0;i<64;i++){low[i]=0;rgb[i]=0;}
    native[0]=0x001f;native[254]=native[255]=0x7c00;
    a2_fine_gpu_written(c,0,0,1024,512);A2FineParams p=triangle(8,8,128,128,128);
    A2FineMinify f=footprint(2);f.offsets[0][0]=-65280;f.offsets[1][0]=65280;
    uint8_t *allow=NULL,*minify=NULL;
    assert(a2_fine_gpu_enqueue_minified(c,&p,native,&f,&allow,&minify,error,sizeof error));minify[1]=2;
    assert(a2_fine_gpu_sync(c,error,sizeof error));assert(low[9]==0x4010&&rgb[9]==0xff7c007c);
    a2_fine_gpu_destroy(c);free(low);free(rgb);
}
static void ordered_mixed_paths(void) {
    uint16_t *low;uint32_t *rgb;allocate(8,8,&low,&rgb);
    A2FineGpu *c=a2_fine_gpu_create(8,8,low,rgb,error,sizeof error);assert(c);
    A2FineParams base=triangle(8,8,0,0,248);base.state[3]=0;
    assert(a2_fine_gpu_enqueue(c,&base,NULL,error,sizeof error));
    memset(native,0,sizeof native);native[0]=0x001f;a2_fine_gpu_written(c,0,0,1024,512);
    A2FineParams p=triangle(8,8,128,128,128);A2FineMinify f=footprint(2);
    uint8_t *allow=NULL,*minify=NULL;
    assert(a2_fine_gpu_enqueue_minified(c,&p,native,&f,&allow,&minify,error,sizeof error));
    allow[1]=(1<<1)|(1<<3);minify[1]=(1<<2)|(1<<3);
    assert(a2_fine_gpu_stats(c).submissions==0);
    assert(a2_fine_gpu_sync(c,error,sizeof error));
    assert(low[9]==0x001f&&rgb[9]==0xfff80000); /* Ordinary allowed center. */
    assert(low[10]==0x4010&&rgb[10]==0xff7c007c); /* Paired minify over queued base. */
    assert(low[11]==0x4010&&rgb[11]==0xff7c007c); /* Minify wins over allow. */
    assert(low[12]==0x7c00&&rgb[12]==0xff0000f8); /* Neither bit preserves base. */
    /* Invalid metadata cannot discard a previously accepted ordinary command. */
    assert(a2_fine_gpu_enqueue(c,&base,NULL,error,sizeof error));
    f.count=3;allow=minify=(uint8_t *)1;
    assert(!a2_fine_gpu_enqueue_minified(c,&p,native,&f,&allow,&minify,error,sizeof error)&&!allow&&!minify);
    f.count=2;f.offsets[0][0]=65281;allow=minify=(uint8_t *)1;
    assert(!a2_fine_gpu_enqueue_minified(c,&p,native,&f,&allow,&minify,error,sizeof error)&&!allow&&!minify);
    assert(a2_fine_gpu_sync(c,error,sizeof error));assert(low[9]==0x7c00&&rgb[9]==0xff0000f8);
    a2_fine_gpu_destroy(c);free(low);free(rgb);
}
static void bounded_two_plane_pool(void) {
    uint16_t *low;uint32_t *rgb;allocate(1024,1024,&low,&rgb);
    A2FineGpu *c=a2_fine_gpu_create(1024,1024,low,rgb,error,sizeof error);assert(c);
    memset(native,0,sizeof native);native[0]=0x001f;
    A2FineParams p=triangle(1024,1024,128,128,128);A2FineMinify f=footprint(2);
    uint8_t *allow=NULL,*minify=NULL;unsigned count=0;
    for(unsigned i=0;i<100;i++) {
        allow=minify=(uint8_t *)1;
        if(!a2_fine_gpu_enqueue_minified(c,&p,native,&f,&allow,&minify,error,sizeof error)){
            assert(!allow&&!minify);break;
        }
        assert(allow&&minify==allow+1024*1024/8);
        minify[128]=2;count++;
    }
    assert(count>8&&count<100);assert(a2_fine_gpu_stats(c).queued_triangles==count);
    assert(a2_fine_gpu_sync(c,error,sizeof error));
    assert(a2_fine_gpu_enqueue_minified(c,&p,native,&f,&allow,&minify,error,sizeof error));
    for(unsigned i=0;i<1024*1024/8;i++)assert(!allow[i]&&!minify[i]);
    minify[128]=2;assert(a2_fine_gpu_sync(c,error,sizeof error));
    a2_fine_gpu_destroy(c);free(low);free(rgb);
}
int main(void) {
    transparency_rounding_stp();ordered_mixed_paths();bounded_two_plane_pool();
    puts("PASS: Metal minify transparent taps, STP, separate rounded colors, offsets, immutable metadata, mixed masks and bounded retry");
}
