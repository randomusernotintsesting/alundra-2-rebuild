#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#import <QuartzCore/CAMetalLayer.h>
#include "gpu_present.h"
#include <assert.h>
#include <stdatomic.h>
#include <stdio.h>
/* A real Metal backend with the OS drawable wait controlled at its boundary.
 * Replacing asynchronous acquisition with nextDrawable on the caller must fail. */
@interface WaitingLayer : CAMetalLayer {
@public
    dispatch_semaphore_t entered,gate,released,watchdogDone;
    atomic_int calls,active,rescued,framebufferCapture;
}
@end
@implementation WaitingLayer
- (instancetype)init {
    self=[super init];if(self){entered=dispatch_semaphore_create(0);gate=dispatch_semaphore_create(0);
        released=dispatch_semaphore_create(0);watchdogDone=dispatch_semaphore_create(0);
        atomic_init(&calls,0);atomic_init(&active,0);atomic_init(&rescued,0);atomic_init(&framebufferCapture,0);}
    return self;
}
- (id<CAMetalDrawable>)nextDrawable {
    atomic_fetch_add(&calls,1);atomic_fetch_add(&active,1);
    if(!self.framebufferOnly)atomic_store(&framebufferCapture,1);
    dispatch_semaphore_signal(entered);dispatch_semaphore_wait(gate,DISPATCH_TIME_FOREVER);
    atomic_fetch_sub(&active,1);return nil;
}
@end
static void check(int ok,const char *message){if(!ok){fprintf(stderr,"FAIL: %s\n",message);exit(1);}}
static WaitingLayer *layer(void) {
    WaitingLayer *l=[WaitingLayer layer];l.device=MTLCreateSystemDefaultDevice();
    l.pixelFormat=MTLPixelFormatBGRA8Unorm;l.drawableSize=CGSizeMake(32,32);return l;
}
static void watchdog(WaitingLayer *l) {
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{
        dispatch_semaphore_wait(l->entered,DISPATCH_TIME_FOREVER);
        if(dispatch_semaphore_wait(l->released,dispatch_time(DISPATCH_TIME_NOW,300*NSEC_PER_MSEC))) {
            atomic_store(&l->rescued,1);dispatch_semaphore_signal(l->gate);
        }
        dispatch_semaphore_signal(l->watchdogDone);
    });
}
int main(void) { @autoreleasepool {
    char error[1024];uint32_t pixels[32*32],actual[32*32];
    for(unsigned i=0;i<32*32;i++)pixels[i]=0xffb27326;
    WaitingLayer *l=layer();A2GpuPresent *p=a2_gpu_present_create((__bridge void *)l,error,sizeof error);check(p!=NULL,error);
    watchdog(l);
    check(a2_gpu_present_prepare(p,pixels,32,32,32,0,error,sizeof error),error);
    check(a2_gpu_present_commit(p,1,0,error,sizeof error)==0,error);
    int blocked=atomic_load(&l->rescued);
    if(!blocked) {
        /* Wait for acquisition to enter without competing with the watchdog. */
        for(unsigned i=0;i<200&&atomic_load(&l->calls)==0;i++)[NSThread sleepForTimeInterval:.001];
        check(atomic_load(&l->active)==1,"one acquisition must remain pending");
        for(unsigned i=0;i<20;i++) {
            pixels[0]=0xff000000|i;
            check(a2_gpu_present_prepare(p,pixels,32,32,32,0,error,sizeof error),error);
            check(a2_gpu_present_commit(p,1,0,error,sizeof error)==0,error);
        }
        check(atomic_load(&l->calls)==1,"must not queue extra drawable requests");
        check(a2_gpu_present_readback(p,actual,32,error,sizeof error),error);
        check(!memcmp(pixels,actual,sizeof pixels),"latest frame must survive a blocked window");
        check(!atomic_load(&l->rescued),"preparing later frames must not wait for drawable");
        dispatch_semaphore_signal(l->released);dispatch_semaphore_signal(l->gate);
    }
    dispatch_semaphore_wait(l->watchdogDone,DISPATCH_TIME_FOREVER);
#ifdef A2_TEST_ASYNC_API
    check(a2_gpu_present_suspend(p,error,sizeof error),error);
    check(atomic_load(&l->active)==0,"suspend must drain acquisition before SDL takeover");
    int count=atomic_load(&l->calls);
    check(a2_gpu_present_commit(p,1,0,error,sizeof error)==0,error);
    check(atomic_load(&l->calls)==count,"suspended backend must not resume on commit");
    dispatch_semaphore_signal(l->gate);
    check(a2_gpu_present_prepare(p,pixels,32,32,32,1,error,sizeof error),error);
    check(a2_gpu_present_suspend(p,error,sizeof error),error);
    check(atomic_load(&l->calls)==count+1,"prepare must resume acquisition");
    dispatch_semaphore_signal(l->gate);
    check(a2_gpu_present_commit(p,0,1,error,sizeof error)==0,error);
    check(atomic_load(&l->framebufferCapture),"explicit capture must acquire a readable actual drawable");
    check(l.framebufferOnly,"capture must restore the layer property");
#endif
    a2_gpu_present_destroy(p);
    check(atomic_load(&l->active)==0,"destroy must not leave an active acquisition");
    check(!blocked,"ordinary commit waited for nextDrawable; watchdog had to release it");
    puts("PASS: nonblocking drawable wait, bounded requests, fresh image, suspend/resume/capture/teardown");return 0;
} }
