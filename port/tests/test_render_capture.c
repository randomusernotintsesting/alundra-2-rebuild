#include "render_capture.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
static int capture_flushed, bounded_reads;
static int checked_flush(SDL_Renderer *r) { capture_flushed=1;return SDL_RenderFlush(r); }
static int checked_logical(SDL_Renderer *r,int w,int h) { assert(capture_flushed);return SDL_RenderSetLogicalSize(r,w,h); }
static int checked_scale(SDL_Renderer *r,float x,float y) { assert(capture_flushed);return SDL_RenderSetScale(r,x,y); }
static int checked_viewport(SDL_Renderer *r,const SDL_Rect *rect) { assert(capture_flushed);return SDL_RenderSetViewport(r,rect); }
static int checked_read(SDL_Renderer *r,const SDL_Rect *rect,Uint32 format,void *pixels,int pitch) {
    assert(capture_flushed);assert(rect);assert(rect->x==0&&rect->y==0);
    assert(rect->w>0&&rect->h>0&&rect->w<=pitch/4);bounded_reads++;
    return SDL_RenderReadPixels(r,rect,format,pixels,pitch);
}
#define SDL_RenderFlush checked_flush
#define SDL_RenderSetLogicalSize checked_logical
#define SDL_RenderSetScale checked_scale
#define SDL_RenderSetViewport checked_viewport
#define SDL_RenderReadPixels checked_read
#ifndef A2_CAPTURE_IMPLEMENTATION
#define A2_CAPTURE_IMPLEMENTATION "../src/render_capture.c"
#endif
#include A2_CAPTURE_IMPLEMENTATION
#undef SDL_RenderFlush
#undef SDL_RenderSetLogicalSize
#undef SDL_RenderSetScale
#undef SDL_RenderSetViewport
#undef SDL_RenderReadPixels
static const Uint32 colors[]={0xffff0000u,0xff00ff00u,0xff0000ffu,0xffffff00u};
static void draw(SDL_Renderer *r,SDL_Texture *texture,int w,int h,int implicit) {
    assert(!SDL_SetRenderDrawColor(r,0,0,0,255));assert(!SDL_RenderClear(r));
    SDL_Rect dst={0,0,w,h};assert(!SDL_RenderCopy(r,texture,NULL,implicit?NULL:&dst));
}
static void corners(SDL_Surface *s,int lw,int lh,int integer) {
    double scale=(double)s->w/lw;if((double)s->h/lh<scale)scale=(double)s->h/lh;
    if(integer){scale=(int)scale;if(scale<1)scale=1;}
    double x0=(s->w-lw*scale)/2,y0=(s->h-lh*scale)/2;
    for(int q=0;q<4;q++){
        int x=(int)(x0+lw*scale*(q%2?0.75:0.25)),y=(int)(y0+lh*scale*(q/2?0.75:0.25));
        const Uint32 *row=(const Uint32*)((const Uint8*)s->pixels+y*s->pitch);
        assert((row[x]&0xffffffu)==(colors[q]&0xffffffu));
    }
}
static void exercise(SDL_Renderer *r,SDL_Texture *texture,int lw,int lh,int integer) {
    assert(!SDL_RenderSetIntegerScale(r,integer));assert(!SDL_RenderSetLogicalSize(r,lw,lh));assert(!SDL_RenderSetViewport(r,NULL));
    draw(r,texture,lw,lh,0);capture_flushed=0;
    SDL_Surface *s=a2_render_capture_window(r);assert(s);assert(s->w==1512&&s->h==982);corners(s,lw,lh,integer);SDL_FreeSurface(s);
    int gotw,goth;SDL_RenderGetLogicalSize(r,&gotw,&goth);assert(gotw==lw&&goth==lh);assert(SDL_RenderGetIntegerScale(r)==(SDL_bool)integer);
    /* A previously corrupted explicit viewport must not overflow readback.
     * Its actual zoomed pixels must survive normalization for diagnosis. */
    SDL_Rect huge={0,0,8192,8192};assert(!SDL_RenderSetViewport(r,&huge));draw(r,texture,lw,lh,1);capture_flushed=0;
    s=a2_render_capture_window(r);assert(s);Uint32 *last=(Uint32*)((Uint8*)s->pixels+(s->h-100)*s->pitch);
    assert((last[s->w-100]&0xffffffu)==0xff0000u);SDL_FreeSurface(s);
    draw(r,texture,lw,lh,0);capture_flushed=0;s=a2_render_capture_window(r);assert(s);corners(s,lw,lh,integer);SDL_FreeSurface(s);
}
int main(void) {
    SDL_SetHint(SDL_HINT_RENDER_DRIVER,"software");assert(!SDL_Init(SDL_INIT_VIDEO));
    SDL_Window *w=SDL_CreateWindow("owned capture fixture",0,0,1512,982,SDL_WINDOW_HIDDEN);assert(w);
    SDL_Renderer *r=SDL_CreateRenderer(w,-1,SDL_RENDERER_SOFTWARE);assert(r);
    SDL_Texture *t=SDL_CreateTexture(r,SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STATIC,2,2);assert(t);assert(!SDL_UpdateTexture(t,NULL,colors,8));
    exercise(r,t,960,540,0);exercise(r,t,640,480,1);
    assert(!SDL_RenderSetLogicalSize(r,0,0));assert(!SDL_RenderSetViewport(r,NULL));draw(r,t,1512,982,0);capture_flushed=0;
    SDL_Surface *s=a2_render_capture_window(r);assert(s);corners(s,1512,982,0);SDL_FreeSurface(s);
    int lw,lh;SDL_RenderGetLogicalSize(r,&lw,&lh);assert(!lw&&!lh);
    SDL_Texture *target=SDL_CreateTexture(r,SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_TARGET,16,16);assert(target);
    assert(!SDL_SetRenderTarget(r,target));capture_flushed=0;assert(!a2_render_capture_window(r));assert(SDL_GetRenderTarget(r)==target);
    assert(!SDL_SetRenderTarget(r,NULL));SDL_DestroyTexture(target);
    assert(bounded_reads==7);SDL_DestroyTexture(t);SDL_DestroyRenderer(r);SDL_DestroyWindow(w);SDL_Quit();
    puts("bounded window readback and post-flush pixel preservation: pass");return 0;
}
