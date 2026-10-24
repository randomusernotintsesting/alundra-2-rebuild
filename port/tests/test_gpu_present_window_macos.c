#include "gpu_present.h"
#include "antialias.h"
#include "render_capture.h"
#include <SDL.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    if(!getenv("A2_TEST_GPU_WINDOW"))return 77;
    assert(SDL_Init(SDL_INIT_VIDEO)==0);
    SDL_Window *win=SDL_CreateWindow("Alundra2 finite GPU resize test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
        384,216,SDL_WINDOW_ALLOW_HIGHDPI|SDL_WINDOW_RESIZABLE);assert(win);
    SDL_Renderer *ren=SDL_CreateRenderer(win,-1,0);assert(ren);
    char error[1024];void *layer=SDL_RenderGetMetalLayer(ren);assert(layer);
    A2GpuPresent *p=a2_gpu_present_create(layer,error,sizeof error);assert(p);
    A2Antialias *aa=a2_antialias_create(error,sizeof error);assert(aa);
    enum {W=96,H=80,P=103};uint32_t raw[P*H],expected[P*H];
    for(int y=0;y<H;y++)for(int x=0;x<P;x++)
        raw[y*P+x]=0xff000000u|(y>x*.37+21?0xbef0e7:0x183139)^((x*23+y*41)&0x1f1f1f);
    SDL_Texture *tex=SDL_CreateTexture(ren,SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STREAMING,W,H);assert(tex);
    const int dims[][2]={{384,216},{500,500},{501,367},{701,377}};unsigned failures=0;
    for(unsigned i=0;i<4;i++)for(int enabled=0;enabled<2;enabled++)for(int fill=0;fill<2;fill++) {
        SDL_SetWindowSize(win,dims[i][0],dims[i][1]);SDL_PumpEvents();SDL_Delay(40);SDL_PumpEvents();
        assert(a2_gpu_present_suspend(p,error,sizeof error));
        assert(!SDL_RenderSetLogicalSize(ren,fill?0:960,fill?0:540));assert(!SDL_RenderSetViewport(ren,NULL));
        memcpy(expected,raw,sizeof raw);
        if(enabled)assert(a2_antialias_apply(aa,expected,W,H,P,error,sizeof error));
        assert(!SDL_UpdateTexture(tex,NULL,expected,P*4));assert(!SDL_SetTextureScaleMode(tex,enabled?SDL_ScaleModeLinear:SDL_ScaleModeNearest));
        assert(!SDL_SetRenderDrawColor(ren,0,0,0,255));assert(!SDL_RenderClear(ren));assert(!SDL_RenderCopy(ren,tex,NULL,NULL));
        SDL_Surface *reference=a2_render_capture_window(ren);assert(reference);SDL_RenderPresent(ren);assert(!SDL_RenderFlush(ren));
        a2_gpu_present_set_fill(p,fill);
        assert(a2_gpu_present_prepare(p,raw,W,H,P,enabled,error,sizeof error));
        assert(a2_gpu_present_commit(p,0,1,error,sizeof error)==0);
        int w,h,stride;const uint32_t *actual=a2_gpu_present_window_pixels(p,&w,&h,&stride,error,sizeof error);assert(actual);
        assert(w==reference->w&&h==reference->h);
        unsigned changed=0,max_error=0;uint64_t sum=0;
        for(int y=0;y<h;y++)for(int x=0;x<w;x++) {
            uint32_t a=actual[y*stride+x],b=((uint32_t*)((char*)reference->pixels+y*reference->pitch))[x];
            changed+=(a&0xffffff)!=(b&0xffffff);
            for(unsigned shift=0;shift<24;shift+=8) {unsigned d=abs((int)((a>>shift)&255)-(int)((b>>shift)&255));if(d>max_error)max_error=d;sum+=d;}
        }
        printf("window=%dx%d drawable=%dx%d AA=%d fill=%d changed=%u max_error=%u mean_error=%.9f\n",dims[i][0],dims[i][1],w,h,enabled,fill,changed,max_error,sum/(double)(w*h*3));
        if(changed)failures++;
        SDL_FreeSurface(reference);
    }
    a2_gpu_present_destroy(p);a2_antialias_destroy(aa);SDL_DestroyTexture(tex);SDL_DestroyRenderer(ren);SDL_DestroyWindow(win);SDL_Quit();
    return failures?1:0;
}
