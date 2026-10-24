/* Real Metal integration checks: deferred execution, ordered destination reads,
 * immutable post-native texture versions, bounded capacity, and borrowed memory. */
#include "gpu_fine.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
static uint16_t native[1024*512];
static char error[2048];
static A2FineParams triangle(unsigned flags,unsigned page,unsigned r,unsigned g,unsigned b) {
    A2FineParams p={0};
    p.p[0]=(A2FineVertex){0,0,r,g,b,0,0,0};
    p.p[1]=(A2FineVertex){8*65536,0,r,g,b,0,0,0};
    p.p[2]=(A2FineVertex){0,8*65536,r,g,b,0,0,0};
    p.clip[2]=p.clip[3]=7;p.width=p.height=8;p.state[0]=page;p.state[3]=flags;
    return p;
}
int main(void) {
    size_t page=(size_t)sysconf(_SC_PAGESIZE);uint16_t *low=NULL;uint32_t *rgb=NULL;
    assert(!posix_memalign((void **)&low,page,page));assert(!posix_memalign((void **)&rgb,page,page));
    memset(low,0,page);memset(rgb,0,page);
    assert(!a2_fine_gpu_create(8,8,low+1,rgb,error,sizeof error));
    A2FineGpu *c=a2_fine_gpu_create(8,8,low,rgb,error,sizeof error);
    if(!c){fprintf(stderr,"create: %s\n",error);return 1;}
    assert(a2_fine_gpu_sync(c,error,sizeof error));
    A2FineParams p=triangle(0,0,248,0,0);
    assert(a2_fine_gpu_enqueue(c,&p,NULL,error,sizeof error));
    assert(low[9]==0&&rgb[9]==0);
    assert(a2_fine_gpu_stats(c).submissions==0);
    p=triangle(4,0,0,0,248); /* Average blue over queued red. */
    assert(a2_fine_gpu_enqueue(c,&p,NULL,error,sizeof error));
    assert(a2_fine_gpu_sync(c,error,sizeof error));
    assert(low[9]==(15|(15<<10))&&rgb[9]==0xff7c007c);
    assert(low[63]==0&&rgb[63]==0); /* Outside both triangles. */
    A2FineGpuStats s=a2_fine_gpu_stats(c);assert(s.triangles==2&&s.submissions==1&&s.waits==1);
    assert(a2_fine_gpu_sync(c,error,sizeof error));assert(a2_fine_gpu_stats(c).waits==1);
    /* Missing texture copying/leases, dirty marks or reordering breaks this. */
    p=triangle(2,256,128,128,128);native[0]=0x001f;
    a2_fine_gpu_written(c,0,0,1,1);assert(a2_fine_gpu_enqueue(c,&p,native,error,sizeof error));
    p=triangle(2|4,256|(1<<5),128,128,128);native[0]=0xfc00;
    a2_fine_gpu_written(c,0,0,1,1);assert(a2_fine_gpu_enqueue(c,&p,native,error,sizeof error));
    memset(native,0,sizeof native); /* Inputs need no lifetime beyond enqueue. */
    assert(a2_fine_gpu_sync(c,error,sizeof error));
    assert(low[9]==0xfc1f&&rgb[9]==0xfff800f8);
    s=a2_fine_gpu_stats(c);assert(s.texture_uploaded_bytes==2*256*256*2);
    /* Unsupported input accepts nothing and does not discard earlier work. */
    p=triangle(0,0,0,248,0);assert(a2_fine_gpu_enqueue(c,&p,NULL,error,sizeof error));
    p.p[1].r=256;assert(!a2_fine_gpu_enqueue(c,&p,NULL,error,sizeof error));
    assert(a2_fine_gpu_sync(c,error,sizeof error));assert(low[9]==0x03e0&&rgb[9]==0xff00f800);
    /* Texture pool exhaustion is bounded, retires cleanly, then can retry. */
    unsigned accepted=0;
    p=triangle(2,256,128,128,128);
    for(unsigned i=0;i<200;i++) {
        native[0]=(uint16_t)(1+i);a2_fine_gpu_written(c,0,0,1,1);
        if(!a2_fine_gpu_enqueue(c,&p,native,error,sizeof error))break;
        accepted++;
    }
    assert(accepted>1&&accepted<200);
    assert(a2_fine_gpu_sync(c,error,sizeof error));
    assert(a2_fine_gpu_enqueue(c,&p,native,error,sizeof error));
    assert(a2_fine_gpu_sync(c,error,sizeof error));assert(low[9]==native[0]);
    /* CPU writes after the barrier remain visible in the same borrowed pages. */
    low[9]=0x001f;rgb[9]=0xfff80000;p=triangle(4,0,0,0,248);
    assert(a2_fine_gpu_enqueue(c,&p,NULL,error,sizeof error));
    a2_fine_gpu_destroy(c); /* Drains pending work without taking ownership. */
    assert(low[9]==(15|(15<<10))&&rgb[9]==0xff7c007c);
    free(low);free(rgb);
    puts("PASS: Metal deferred batches, ordered blending, immutable textures, bounded retry, borrowed surfaces");
    return 0;
}
