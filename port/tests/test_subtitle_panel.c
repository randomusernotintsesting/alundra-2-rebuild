#include "subtitle_panel.h"
#include "gpu_present.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    /* A moving game must reuse the same small text raster. Hiding a caption
     * must remove the panel immediately, including after a resolution change. */
    assert(!a2_subtitle_panel_set(NULL,4,320,240,239));
    const A2PromptPixels *p=a2_subtitle_panel_set("I can't stand it anymore!",4,320,240,239);
    assert(p && p->pixels && p->width<1280 && p->height<=128);
    assert(p->x>=0 && p->y>=0 && p->x+p->width<=1280 && p->y+p->height<=960);
    uint64_t first=p->generation;const uint32_t *pixels=p->pixels;
    for(unsigned i=0;i<120;i++) {
        p=a2_subtitle_panel_set("I can't stand it anymore!",4,320,240,239);
        assert(p && p->generation==first && p->pixels==pixels);
    }
    p=a2_subtitle_panel_set("A real pirate wouldn't be caught dead\nfloating up in the air like this.",4,320,240,239);
    assert(p && p->generation!=first && p->height<=128);
    /* Exercise the real GPU compositor against the actual CPU caption, with
     * captures only in this test. A repeated panel must not upload again. */
    char error[256];A2GpuPresent *gpu=a2_gpu_present_create(NULL,error,sizeof error);assert(gpu);
    int w=1280,h=960,pitch=1287;
    uint32_t *raw=malloc((size_t)pitch*h*4),*cpu=malloc((size_t)pitch*h*4),*actual=malloc((size_t)pitch*h*4);
    assert(raw&&cpu&&actual);
    for(int i=0;i<pitch*h;i++)raw[i]=0xff345678u;
    memcpy(cpu,raw,(size_t)pitch*h*4);memcpy(actual,raw,(size_t)pitch*h*4);
    a2_subtitle_panel_compose(cpu,pitch,w,h);
    assert(memcmp(cpu,raw,(size_t)pitch*h*4));
    assert(a2_gpu_present_prepare(gpu,raw,w,h,pitch,0,error,sizeof error));
    assert(a2_gpu_present_panel(gpu,p,error,sizeof error));
    assert(a2_gpu_present_readback(gpu,actual,pitch,error,sizeof error));
    assert(!memcmp(cpu,actual,(size_t)pitch*h*4));
    for(int i=0;i<10;i++) {
        assert(a2_gpu_present_prepare(gpu,raw,w,h,pitch,0,error,sizeof error));
        assert(a2_gpu_present_panel(gpu,p,error,sizeof error));
        assert(a2_gpu_present_commit(gpu,0,0,error,sizeof error)==0);
    }
    A2GpuPresentStats stats=a2_gpu_present_stats(gpu);
    assert(stats.panel_uploads==1 && stats.readbacks==1);
    assert(!a2_subtitle_panel_set(NULL,4,320,240,239));
    memcpy(cpu,raw,(size_t)pitch*h*4);a2_subtitle_panel_compose(cpu,pitch,w,h);
    assert(!memcmp(cpu,raw,(size_t)pitch*h*4));
    p=a2_subtitle_panel_set("Chill out, Pop!",2,320,240,239);
    assert(p && p->x+p->width<=640 && p->y+p->height<=480);
    assert(!a2_subtitle_panel_set("Invalid",0,320,240,239));
    a2_subtitle_panel_close();a2_gpu_present_destroy(gpu);
    free(raw);free(cpu);free(actual);
    puts("Subtitles: readable bounds, repeated-frame cache, immediate hide and exact CPU/Metal pixels passed");
}
