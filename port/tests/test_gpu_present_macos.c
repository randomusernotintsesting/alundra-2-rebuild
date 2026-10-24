#ifdef A2_GPU_PRESENT_TEST_RED
#define A2_GPU_API __attribute__((weak_import))
#endif
#include "gpu_present.h"
#include "antialias.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static void overlay(uint32_t *dst,int w,int h,int stride,const A2PromptPixels *p) {
    for(int y=0;y<h;y++)for(int x=0;x<w;x++) {
        int sx=x-p->x,sy=y-p->y;if(sx<0||sy<0||sx>=p->width||sy>=p->height)continue;
        uint32_t src=p->pixels[sy*p->width+sx],d=dst[y*stride+x],a=src>>24;
        if(!a)continue;uint32_t result=0xff000000u;
        for(unsigned shift=0;shift<24;shift+=8) {
            unsigned v=((src>>shift)&255)+(((d>>shift)&255)*(255-a)+127)/255;
            result|=(v>255?255:v)<<shift;
        }
        dst[y*stride+x]=result;
    }
}
static void equal(const uint32_t *a,const uint32_t *b,int w,int h,int stride) {
    for(int y=0;y<h;y++)for(int x=0;x<stride;x++)if(a[y*stride+x]!=b[y*stride+x]) {
        fprintf(stderr,"pixel mismatch %dx%d (%d,%d): %08x != %08x\n",w,h,x,y,a[y*stride+x],b[y*stride+x]);abort();
    }
}
int main(void) {
    char error[1024];A2Antialias *aa=a2_antialias_create(error,sizeof error);
    if(!aa){fprintf(stderr,"Metal unavailable: %s\n",error);return 77;}
#ifdef A2_GPU_PRESENT_TEST_RED
    if(!a2_gpu_present_create){fputs("FAIL: no GPU-resident presentation; AA result requires CPU readback\n",stderr);a2_antialias_destroy(aa);return 1;}
#endif
    A2GpuPresent *p=a2_gpu_present_create(NULL,error,sizeof error);
    if(!p){fprintf(stderr,"resident backend: %s\n",error);abort();}
    uint32_t ink[3][6]={{0,0x80402010,0xff007fc1,0x01010000,0xf02080d0,0},
        {0x80804000,0x40201000,0xff04080c,0,0xfe807f20,0x02010201},
        {0xffffffff,0,0x90805020,0x40010203,0xff030405,0}};
    const int dims[][2]={{96,80},{95,33},{1,1},{1280,1920},{1280,864}};
    unsigned cases=0;
    for(unsigned shape=0;shape<5;shape++)for(int enabled=0;enabled<=1;enabled++) {
        int w=dims[shape][0],h=dims[shape][1],stride=w+7;size_t bytes=(size_t)stride*h*4;
        uint32_t *raw=malloc(bytes),*saved=malloc(bytes),*expected=malloc(bytes),*actual=malloc(bytes);
        assert(raw&&saved&&expected&&actual);
        for(int y=0;y<h;y++)for(int x=0;x<stride;x++)
            raw[y*stride+x]=x>=w?0xdeadbeefu:((x+3*y)%7?0xff000000u:0x71000000u)|
                (y>.37*x+21?0xbdf3f7u:0x182235u)^((x*23+y*47)&0x1f1f1fu);
        for(unsigned round=0;round<6;round++) {
            /* Late changed pixel must invalidate raw/AA cache. Other rounds
             * change only overlays, remove all overlays, or repeat them. */
            if(round==2)raw[(h-1)*stride+w-1]^=0x00ffffffu;
            if(round==3)ink[1][2]^=0x00070809u;
            memcpy(saved,raw,bytes);memcpy(expected,raw,bytes);memcpy(actual,raw,bytes);
            if(enabled)assert(a2_antialias_apply(aa,expected,w,h,stride,error,sizeof error));
            assert(a2_gpu_present_prepare(p,raw,w,h,stride,enabled,error,sizeof error));
            unsigned count=round==4?0:3;
            for(unsigned i=0;i<count;i++) {
                A2PromptPixels panel={ink[i],(int)i-1,(int)i,3,2,100+i+(round>=3?3:0)};
                if(round>=3)panel.x-=2;
                overlay(expected,w,h,stride,&panel);
                assert(a2_gpu_present_panel(p,&panel,error,sizeof error));
            }
            if(round&1)assert(a2_gpu_present_commit(p,0,0,error,sizeof error)==0);
            assert(a2_gpu_present_readback(p,actual,stride,error,sizeof error));
            equal(expected,actual,w,h,stride);equal(saved,raw,w,h,stride);
            assert(a2_gpu_present_commit(p,0,0,error,sizeof error)==0);
            ++cases;
        }
        free(raw);free(saved);free(expected);free(actual);
    }
    /* Normal submissions retain results without any capture/readback. */
    uint32_t raw[16];for(unsigned i=0;i<16;i++)raw[i]=0xff205070u+i;
    A2GpuPresentStats before=a2_gpu_present_stats(p);
    for(unsigned i=0;i<12;i++) {
        raw[15]^=0x00ffffffu;
        assert(a2_gpu_present_prepare(p,raw,4,4,4,1,error,sizeof error));
        assert(a2_gpu_present_commit(p,0,0,error,sizeof error)==0);
    }
    assert(a2_gpu_present_flush(p,error,sizeof error));
    A2GpuPresentStats after=a2_gpu_present_stats(p);
    assert(after.readbacks==before.readbacks&&after.window_readbacks==0);
    assert(after.aa_dispatches==before.aa_dispatches+12&&after.aa_reuses>0);
    uint32_t result[16],expected[16];memcpy(expected,raw,sizeof raw);
    assert(a2_antialias_apply(aa,expected,4,4,4,error,sizeof error));
    assert(a2_gpu_present_readback(p,result,4,error,sizeof error));equal(result,expected,4,4,4);
    assert(!a2_gpu_present_prepare(p,raw,4,4,3,1,error,sizeof error));
    assert(!a2_gpu_present_readback(p,result,3,error,sizeof error));
    a2_gpu_present_destroy(p);a2_antialias_destroy(aa);
    printf("PASS%u real Metal final-image cases: unchanged FXAA, ordered/clipped premultiplied panels, cache changes, stride/resize, raw immutability;12 normal submissions without readback\n",cases);
}
