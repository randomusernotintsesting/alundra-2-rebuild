#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#import <QuartzCore/CAMetalLayer.h>
#include "gpu_present.h"
#include "display_layout.h"
#include "fxaa_source.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <mach/mach_time.h>
#import <AppKit/NSApplication.h>
#import <AppKit/NSWindow.h>
#import <AppKit/NSView.h>

static NSString *const presentation_source=@
"kernel void raw_copy(texture2d<float> t [[texture(0)]],device uint *out [[buffer(0)]],uint2 p [[thread_position_in_grid]]){\n"
" uint2 size=uint2(t.get_width(),t.get_height());if(any(p>=size))return;\n"
" uint4 c=uint4(round(t.read(p)*255));out[p.y*size.x+p.x]=c.b|(c.g<<8)|(c.r<<16)|(c.a<<24);}\n"
"uint4 unpack_color(uint p){return uint4((p>>16)&255,(p>>8)&255,p&255,p>>24);}\n"
"uint4 panel_color(uint4 d,texture2d<float,access::read> t,int2 p,int4 r){\n"
" int2 q=p-r.xy;if(any(q<0)||any(q>=r.zw))return d;uint4 s=uint4(round(t.read(uint2(q))*255));\n"
" if(!s.a)return d;return uint4(min(uint3(255),s.rgb+(d.rgb*(255-s.a)+127)/255),255);}\n"
"kernel void compose_final(device const uint *raw [[buffer(0)]],constant int4 *rects [[buffer(1)]],constant uint &count [[buffer(2)]],\n"
" texture2d<float,access::write> out [[texture(0)]],texture2d<float,access::read> a [[texture(1)]],\n"
" texture2d<float,access::read> b [[texture(2)]],texture2d<float,access::read> c [[texture(3)]],uint2 p [[thread_position_in_grid]]){\n"
" uint2 size=uint2(out.get_width(),out.get_height());if(any(p>=size))return;uint4 d=unpack_color(raw[p.y*size.x+p.x]);\n"
" if(count>0)d=panel_color(d,a,int2(p),rects[0]);if(count>1)d=panel_color(d,b,int2(p),rects[1]);\n"
" if(count>2)d=panel_color(d,c,int2(p),rects[2]);out.write(float4(d)/255,p);}\n"
"struct ScreenVertex{float4 position [[position]];float2 uv;};\n"
"vertex ScreenVertex screen_vertex(uint id [[vertex_id]]){\n"
" constexpr float2 uv[6]={float2(0,0),float2(1,0),float2(1,1),float2(0,0),float2(1,1),float2(0,1)};\n"
" ScreenVertex v;v.uv=uv[id];v.position=float4(v.uv.x*2-1,1-v.uv.y*2,0,1);return v;}\n"
"fragment float4 screen_fragment(ScreenVertex v [[stage_in]],texture2d<float> t [[texture(0)]],sampler s [[sampler(0)]]){return t.sample(s,v.uv);}\n";

typedef struct {int x,y,w,h;} PanelRect;
@interface A2PresentationStorage:NSObject {
@public
    id<MTLDevice> device;id<MTLCommandQueue> queue;CAMetalLayer *layer;
    id<MTLComputePipelineState> aa,copy,compose;id<MTLRenderPipelineState> screen;
    id<MTLSamplerState> linear,nearest;
    id<MTLTexture> input,final,transparent,panels[3];
    id<MTLBuffer> packed,readback,windowReadback;
    id<MTLCommandBuffer> pending,last;
    NSMutableData *cachedInput;
    int width,height,antialias,rawValid,finalValid,ready,sealed;
    int windowWidth,windowHeight,windowStride;
    uint64_t generations[3],finalGenerations[3];
    PanelRect rects[3],finalRects[3];unsigned count,finalCount;
    BOOL originalFramebufferOnly;
    /* Only this mailbox crosses threads. Image resources and GPU commands
     * remain owned by the game thread. Never hold the lock in nextDrawable. */
    dispatch_queue_t drawableQueue;
    NSLock *drawableLock;
    id<CAMetalDrawable> readyDrawable;
    BOOL drawableRequested,drawablePaused;
} @end
@implementation A2PresentationStorage @end
struct A2GpuPresent {void *storage;A2GpuPresentStats stats;int trace,fill_screen;double tick_ms,trace_ms[5];};
static uint64_t trace_clock(A2GpuPresent *p){return p->trace?mach_absolute_time():0;}
static void trace_stage(A2GpuPresent *p,unsigned stage,uint64_t start){if(p->trace)p->trace_ms[stage]+=(mach_absolute_time()-start)*p->tick_ms;}
static int fail(char *error,size_t size,NSString *message) {
    if(error&&size)snprintf(error,size,"%s",message.UTF8String?:"Metal presentation failed");
    return 0;
}
static void clear_error(char *error,size_t size){if(error&&size)error[0]=0;}
static A2PresentationStorage *storage(A2GpuPresent *p){return (__bridge A2PresentationStorage *)p->storage;}
static void request_drawable(A2PresentationStorage *s) {
    if(!s->layer)return;
    [s->drawableLock lock];
    BOOL request=!s->drawablePaused&&!s->drawableRequested&&!s->readyDrawable;
    if(request)s->drawableRequested=YES;
    [s->drawableLock unlock];
    if(!request)return;
    /* Retain storage, never the C backend pointer. There is at most one
     * queued/in-flight request OR one retained ready drawable. */
    dispatch_async(s->drawableQueue,^{ @autoreleasepool {
        id<CAMetalDrawable> drawable=[s->layer nextDrawable];
        [s->drawableLock lock];
        if(!s->drawablePaused)s->readyDrawable=drawable;
        s->drawableRequested=NO;
        [s->drawableLock unlock];
    }});
}
static id<CAMetalDrawable> take_drawable(A2PresentationStorage *s) {
    [s->drawableLock lock];
    id<CAMetalDrawable> drawable=s->readyDrawable;s->readyDrawable=nil;
    [s->drawableLock unlock];
    /* A resize can finish while acquisition is pending. Discard an old
     * surface; the next request will use the current layer dimensions. */
    CGSize size=s->layer.drawableSize;
    if(drawable&&(drawable.texture.width!=(NSUInteger)size.width||drawable.texture.height!=(NSUInteger)size.height))return nil;
    return drawable;
}
static void pause_drawables(A2PresentationStorage *s) {
    if(!s->layer)return;
    [s->drawableLock lock];s->drawablePaused=YES;s->readyDrawable=nil;[s->drawableLock unlock];
    /* SDL takeover, explicit capture and teardown only. Normal flush/prepare
     * never waits for acquisition. Drain the worker's autoreleasepool too. */
    dispatch_sync(s->drawableQueue,^{});
}
static int wait_previous(A2GpuPresent *p,char *error,size_t size) {
    A2PresentationStorage *s=storage(p);if(!s->last)return 1;
    if(s->last.status<MTLCommandBufferStatusCompleted){++p->stats.previous_waits;[s->last waitUntilCompleted];}
    if(s->last.status!=MTLCommandBufferStatusCompleted) {
        s->rawValid=s->finalValid=0;return fail(error,size,s->last.error.localizedDescription);
    }
    s->last=nil;return 1;
}
static int command(A2PresentationStorage *s,char *error,size_t size) {
    if(!s->pending)s->pending=[s->queue commandBuffer];
    return s->pending!=nil||fail(error,size,@"Presentation command allocation failed");
}
static void dispatch(id<MTLComputeCommandEncoder> e,id<MTLComputePipelineState> pipeline,int w,int h) {
    NSUInteger tw=pipeline.threadExecutionWidth,th=MIN((NSUInteger)8,pipeline.maxTotalThreadsPerThreadgroup/tw);
    [e dispatchThreadgroups:MTLSizeMake((w+tw-1)/tw,(h+th-1)/th,1) threadsPerThreadgroup:MTLSizeMake(tw,th,1)];
    [e endEncoding];
}
static void submit(A2GpuPresent *p) {
    A2PresentationStorage *s=storage(p);if(!s->pending)return;
    s->last=s->pending;s->pending=nil;[s->last commit];++p->stats.commits;
}
static id<MTLTexture> texture(A2PresentationStorage *s,int w,int h,BOOL private,MTLTextureUsage usage) {
    MTLTextureDescriptor *d=[MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatBGRA8Unorm width:w height:h mipmapped:NO];
    d.storageMode=private?MTLStorageModePrivate:(s->device.hasUnifiedMemory?MTLStorageModeShared:MTLStorageModeManaged);
    d.usage=usage;return [s->device newTextureWithDescriptor:d];
}
static int seal(A2GpuPresent *p,char *error,size_t size) {
    A2PresentationStorage *s=storage(p);
    if(!s->ready)return fail(error,size,@"No prepared presentation frame");
    if(s->sealed)return 1;
    BOOL unchanged=s->finalValid&&s->count==s->finalCount;
    for(unsigned i=0;unchanged&&i<s->count;i++)
        unchanged=s->generations[i]==s->finalGenerations[i]&&!memcmp(s->rects+i,s->finalRects+i,sizeof(PanelRect));
    if(!unchanged) {
        if(!command(s,error,size))return 0;
        id<MTLComputeCommandEncoder> e=[s->pending computeCommandEncoder];
        if(!e)return fail(error,size,@"Composite encoder allocation failed");
        [e setComputePipelineState:s->compose];[e setBuffer:s->packed offset:0 atIndex:0];
        [e setBytes:s->rects length:sizeof s->rects atIndex:1];[e setBytes:&s->count length:sizeof s->count atIndex:2];
        [e setTexture:s->final atIndex:0];
        for(unsigned i=0;i<3;i++)[e setTexture:i<s->count?s->panels[i]:s->transparent atIndex:i+1];
        dispatch(e,s->compose,s->width,s->height);++p->stats.composites;
        memcpy(s->finalRects,s->rects,sizeof s->rects);memcpy(s->finalGenerations,s->generations,sizeof s->generations);
        s->finalCount=s->count;s->finalValid=1;
    }
    s->sealed=1;return 1;
}
A2GpuPresent *a2_gpu_present_create(void *layer,char *error,size_t size) { @autoreleasepool {
    clear_error(error,size);A2PresentationStorage *s=[A2PresentationStorage new];
    s->layer=(__bridge CAMetalLayer *)layer;s->device=layer?s->layer.device:MTLCreateSystemDefaultDevice();
    if(!s->device){fail(error,size,@"No Metal presentation device");return NULL;}
    if(layer&&s->layer.pixelFormat!=MTLPixelFormatBGRA8Unorm){fail(error,size,@"Unsupported presentation layer pixel format");return NULL;}
    s->originalFramebufferOnly=layer?s->layer.framebufferOnly:YES;
    if(layer) {
        s->drawableLock=[NSLock new];
        s->drawableQueue=dispatch_queue_create("org.alundra2.drawable",DISPATCH_QUEUE_SERIAL);
    }
    NSError *failure=nil;
    id<MTLLibrary> library=[s->device newLibraryWithSource:[a2_fxaa_source stringByAppendingString:presentation_source] options:nil error:&failure];
    if(!library){fail(error,size,failure.localizedDescription);return NULL;}
    s->aa=[s->device newComputePipelineStateWithFunction:[library newFunctionWithName:@"antialias"] error:&failure];
    s->copy=[s->device newComputePipelineStateWithFunction:[library newFunctionWithName:@"raw_copy"] error:&failure];
    s->compose=[s->device newComputePipelineStateWithFunction:[library newFunctionWithName:@"compose_final"] error:&failure];
    MTLRenderPipelineDescriptor *d=[MTLRenderPipelineDescriptor new];
    d.vertexFunction=[library newFunctionWithName:@"screen_vertex"];d.fragmentFunction=[library newFunctionWithName:@"screen_fragment"];
    d.colorAttachments[0].pixelFormat=MTLPixelFormatBGRA8Unorm;
    s->screen=[s->device newRenderPipelineStateWithDescriptor:d error:&failure];
    MTLSamplerDescriptor *sampler=[MTLSamplerDescriptor new];
    sampler.sAddressMode=sampler.tAddressMode=MTLSamplerAddressModeClampToEdge;
    sampler.minFilter=sampler.magFilter=MTLSamplerMinMagFilterLinear;s->linear=[s->device newSamplerStateWithDescriptor:sampler];
    sampler.minFilter=sampler.magFilter=MTLSamplerMinMagFilterNearest;s->nearest=[s->device newSamplerStateWithDescriptor:sampler];
    s->queue=[s->device newCommandQueue];s->transparent=texture(s,1,1,NO,MTLTextureUsageShaderRead);
    if(!s->aa||!s->copy||!s->compose||!s->screen||!s->queue||!s->linear||!s->nearest||!s->transparent) {
        fail(error,size,failure.localizedDescription?:@"Presentation pipeline allocation failed");return NULL;
    }
    uint32_t zero=0;[s->transparent replaceRegion:MTLRegionMake2D(0,0,1,1) mipmapLevel:0 withBytes:&zero bytesPerRow:4];
    A2GpuPresent *p=calloc(1,sizeof *p);if(!p){fail(error,size,@"Presentation allocation failed");return NULL;}
    p->storage=(__bridge_retained void *)s;
    p->trace=getenv("A2_GPU_PRESENT_STAGES")!=NULL;
    if(p->trace){mach_timebase_info_data_t t;mach_timebase_info(&t);p->tick_ms=(double)t.numer/t.denom/1e6;}
    fprintf(stderr,"gpu-present: Metal resident output on %s layer=%s\n",s->device.name.UTF8String,layer?"SDL":"offscreen-test");
    return p;
} }
int a2_gpu_present_prepare(A2GpuPresent *p,const uint32_t *pixels,int w,int h,int stride,int aa,char *error,size_t size) { @autoreleasepool {
    clear_error(error,size);
    if(!p||!pixels||w<1||h<1||w>4096||h>4096||stride<w||(size_t)stride>SIZE_MAX/4/(size_t)h)
        return fail(error,size,@"Invalid presentation image layout");
    if(!a2_gpu_present_flush(p,error,size))return 0;
    A2PresentationStorage *s=storage(p);aa=!!aa;
    [s->drawableLock lock];s->drawablePaused=NO;[s->drawableLock unlock];
    request_drawable(s);
    s->windowReadback=nil;s->windowWidth=s->windowHeight=s->windowStride=0;
    if(s->width!=w||s->height!=h) {
        id<MTLTexture> input=texture(s,w,h,NO,MTLTextureUsageShaderRead);
        id<MTLTexture> final=texture(s,w,h,YES,MTLTextureUsageShaderRead|MTLTextureUsageShaderWrite);
        id<MTLBuffer> packed=[s->device newBufferWithLength:(size_t)w*h*4 options:MTLResourceStorageModePrivate];
        if(!input||!final||!packed)return fail(error,size,@"Presentation frame allocation failed");
        s->input=input;s->final=final;s->packed=packed;s->width=w;s->height=h;s->rawValid=s->finalValid=0;s->readback=nil;
        s->cachedInput=[NSMutableData dataWithLength:(size_t)w*h*4];
    }
    const uint32_t *cached=s->cachedInput.bytes;
    BOOL unchanged=s->rawValid&&s->antialias==aa&&cached;
    for(int y=0;unchanged&&y<h;y++)unchanged=!memcmp(pixels+(size_t)y*stride,cached+(size_t)y*w,(size_t)w*4);
    s->count=0;s->sealed=0;s->ready=1;s->antialias=aa;
    if(unchanged){if(aa)++p->stats.aa_reuses;}
    else {
        s->rawValid=s->finalValid=0;
        [s->input replaceRegion:MTLRegionMake2D(0,0,w,h) mipmapLevel:0 withBytes:pixels bytesPerRow:(size_t)stride*4];
        if(!command(s,error,size))return 0;
        id<MTLComputeCommandEncoder> e=[s->pending computeCommandEncoder];
        if(!e)return fail(error,size,@"AA encoder allocation failed");
        id<MTLComputePipelineState> pipeline=aa?s->aa:s->copy;
        [e setComputePipelineState:pipeline];[e setTexture:s->input atIndex:0];[e setBuffer:s->packed offset:0 atIndex:0];
        dispatch(e,pipeline,w,h);if(aa)++p->stats.aa_dispatches;
        uint32_t *saved=s->cachedInput.mutableBytes;
        if(saved)for(int y=0;y<h;y++)memcpy(saved+(size_t)y*w,pixels+(size_t)y*stride,(size_t)w*4);
        s->rawValid=saved!=NULL;
    }
    ++p->stats.prepared;return 1;
} }
int a2_gpu_present_panel(A2GpuPresent *p,const A2PromptPixels *panel,char *error,size_t size) { @autoreleasepool {
    clear_error(error,size);
    if(!p||!panel||!panel->pixels||!panel->generation||panel->width<1||panel->height<1||panel->width>4096||panel->height>4096||
       panel->x< -16384||panel->x>16384||panel->y< -16384||panel->y>16384)return fail(error,size,@"Invalid presentation panel");
    A2PresentationStorage *s=storage(p);
    if(!s->ready||s->sealed||s->count>=3)return fail(error,size,@"Presentation panels are sealed or full");
    unsigned i=s->count;int w=panel->width,h=panel->height;
    if(!s->panels[i]||s->panels[i].width!=(NSUInteger)w||s->panels[i].height!=(NSUInteger)h) {
        id<MTLTexture> t=texture(s,w,h,NO,MTLTextureUsageShaderRead);
        if(!t)return fail(error,size,@"Presentation panel allocation failed");
        s->panels[i]=t;s->generations[i]=0;
    }
    if(s->generations[i]!=panel->generation) {
        [s->panels[i] replaceRegion:MTLRegionMake2D(0,0,w,h) mipmapLevel:0 withBytes:panel->pixels bytesPerRow:(size_t)w*4];
        s->generations[i]=panel->generation;++p->stats.panel_uploads;
    }
    s->rects[i]=(PanelRect){panel->x,panel->y,w,h};s->count++;return 1;
} }
static int encode_readback(A2PresentationStorage *s,id<MTLTexture> t,id<MTLBuffer> buffer,NSUInteger pitch,char *error,size_t size) {
    if(!command(s,error,size))return 0;
    id<MTLBlitCommandEncoder> e=[s->pending blitCommandEncoder];
    if(!e)return fail(error,size,@"Presentation readback encoder allocation failed");
    [e copyFromTexture:t sourceSlice:0 sourceLevel:0 sourceOrigin:MTLOriginMake(0,0,0) sourceSize:MTLSizeMake(t.width,t.height,1)
        toBuffer:buffer destinationOffset:0 destinationBytesPerRow:pitch destinationBytesPerImage:pitch*t.height];
    [e endEncoding];return 1;
}
static int gpu_present_commit_body(A2GpuPresent *p,int show,int capture,char *error,size_t size) { @autoreleasepool {
    clear_error(error,size);if(!p){fail(error,size,@"No presentation backend");return -1;}
    A2PresentationStorage *s=storage(p);uint64_t mark=trace_clock(p);if(!seal(p,error,size))return -1;trace_stage(p,0,mark);
    int shown=0;
    if((show||capture)&&s->layer) {
        if(s->layer.pixelFormat!=MTLPixelFormatBGRA8Unorm){fail(error,size,@"Presentation layer format changed");return -1;}
        mark=trace_clock(p);id<CAMetalDrawable> drawable;
        if(capture) {
            pause_drawables(s);s->layer.framebufferOnly=NO;
            drawable=[s->layer nextDrawable];s->layer.framebufferOnly=s->originalFramebufferOnly;
        } else drawable=take_drawable(s);
        trace_stage(p,1,mark);
        if(drawable) {
            mark=trace_clock(p);if(!command(s,error,size))return -1;
            id<MTLTexture> target=drawable.texture;
            MTLRenderPassDescriptor *pass=[MTLRenderPassDescriptor renderPassDescriptor];
            pass.colorAttachments[0].texture=target;pass.colorAttachments[0].loadAction=MTLLoadActionClear;
            pass.colorAttachments[0].storeAction=MTLStoreActionStore;pass.colorAttachments[0].clearColor=MTLClearColorMake(0,0,0,1);
            id<MTLRenderCommandEncoder> e=[s->pending renderCommandEncoderWithDescriptor:pass];
            if(!e){fail(error,size,@"Presentation render encoder allocation failed");return -1;}
            A2DisplayViewport v=a2_display_viewport((int)target.width,(int)target.height,p->fill_screen);
            [e setViewport:(MTLViewport){v.x,v.y,v.width,v.height,0,1}];
            [e setRenderPipelineState:s->screen];[e setFragmentTexture:s->final atIndex:0];
            [e setFragmentSamplerState:s->antialias?s->linear:s->nearest atIndex:0];
            [e drawPrimitives:MTLPrimitiveTypeTriangle vertexStart:0 vertexCount:6];[e endEncoding];
            if(capture) {
                NSUInteger pitch=(target.width*4+255)&~(NSUInteger)255;
                s->windowReadback=[s->device newBufferWithLength:pitch*target.height options:MTLResourceStorageModeShared];
                if(!s->windowReadback||!encode_readback(s,target,s->windowReadback,pitch,error,size)) {
                    if(!s->windowReadback)fail(error,size,@"Window capture allocation failed");return -1;
                }
                s->windowWidth=(int)target.width;s->windowHeight=(int)target.height;s->windowStride=(int)pitch/4;++p->stats.window_readbacks;
            }
            trace_stage(p,2,mark);
            if(show){mark=trace_clock(p);[s->pending presentDrawable:drawable];trace_stage(p,3,mark);++p->stats.presented;shown=1;}
        }
    }
    mark=trace_clock(p);submit(p);trace_stage(p,4,mark);
    if(show&&!capture)request_drawable(s);return shown;
} }
int a2_gpu_present_commit(A2GpuPresent *p,int show,int capture,char *error,size_t size) {
    if(!p||!p->trace)return gpu_present_commit_body(p,show,capture,error,size);
    memset(p->trace_ms,0,sizeof p->trace_ms);uint64_t start=mach_absolute_time();
    int result=gpu_present_commit_body(p,show,capture,error,size);
    double total=(mach_absolute_time()-start)*p->tick_ms,rest=total;
    for(unsigned i=0;i<5;i++)rest-=p->trace_ms[i];
    if(total>=20.0||p->stats.prepared%60==0) {
        A2PresentationStorage *s=storage(p);int active=-1,visible=-1,occluded=-1,minimized=-1;
        if([NSThread isMainThread]) {
            active=NSApp.active;id delegate=s->layer.delegate;
            if([delegate isKindOfClass:[NSView class]]) {
                NSWindow *w=[(NSView *)delegate window];
                if(w){visible=w.visible;minimized=w.miniaturized;occluded=!(w.occlusionState&NSWindowOcclusionStateVisible);}
            }
        }
        fprintf(stderr,"gpu-present-stage: frame=%llu show=%d capture=%d result=%d total_ms=%.6f seal_ms=%.6f drawable_ms=%.6f encode_ms=%.6f present_ms=%.6f submit_ms=%.6f remainder_ms=%.6f active=%d visible=%d occluded=%d minimized=%d\n",
            (unsigned long long)p->stats.prepared,show,capture,result,total,p->trace_ms[0],p->trace_ms[1],p->trace_ms[2],p->trace_ms[3],p->trace_ms[4],rest,active,visible,occluded,minimized);
    }
    return result;
}
int a2_gpu_present_readback(A2GpuPresent *p,uint32_t *dst,int stride,char *error,size_t size) { @autoreleasepool {
    clear_error(error,size);if(!p||!dst)return fail(error,size,@"Invalid presentation readback");
    A2PresentationStorage *s=storage(p);
    if(!s->ready||stride<s->width||(size_t)stride>SIZE_MAX/4/(size_t)s->height)return fail(error,size,@"Invalid readback layout");
    /* Captures are already synchronous. Check an earlier submitted command
     * before replacing its completion handle, including its error status. */
    if(!wait_previous(p,error,size))return 0;
    if(!seal(p,error,size))return 0;
    NSUInteger pitch=((NSUInteger)s->width*4+255)&~(NSUInteger)255;
    if(!s->readback)s->readback=[s->device newBufferWithLength:pitch*s->height options:MTLResourceStorageModeShared];
    if(!s->readback)return fail(error,size,@"Presentation readback allocation failed");
    if(!encode_readback(s,s->final,s->readback,pitch,error,size))return 0;
    submit(p);if(!wait_previous(p,error,size))return 0;
    const char *src=s->readback.contents;
    for(int y=0;y<s->height;y++)memcpy(dst+(size_t)y*stride,src+(size_t)y*pitch,(size_t)s->width*4);
    ++p->stats.readbacks;return 1;
} }
const uint32_t *a2_gpu_present_window_pixels(A2GpuPresent *p,int *width,int *height,int *stride,char *error,size_t size) { @autoreleasepool {
    clear_error(error,size);if(!p){fail(error,size,@"No window capture backend");return NULL;}
    A2PresentationStorage *s=storage(p);
    if(!s->windowReadback){fail(error,size,@"No drawable was captured");return NULL;}
    if(!a2_gpu_present_flush(p,error,size))return NULL;
    if(width)*width=s->windowWidth;if(height)*height=s->windowHeight;if(stride)*stride=s->windowStride;
    return s->windowReadback.contents;
} }
int a2_gpu_present_flush(A2GpuPresent *p,char *error,size_t size) { @autoreleasepool {
    clear_error(error,size);if(!p)return 1;A2PresentationStorage *s=storage(p);
    if(s->ready&&!seal(p,error,size))return 0;submit(p);return wait_previous(p,error,size);
} }
int a2_gpu_present_suspend(A2GpuPresent *p,char *error,size_t size) { @autoreleasepool {
    if(p)pause_drawables(storage(p));
    return a2_gpu_present_flush(p,error,size);
} }
A2GpuPresentStats a2_gpu_present_stats(const A2GpuPresent *p){return p?p->stats:(A2GpuPresentStats){0};}
void a2_gpu_present_destroy(A2GpuPresent *p) { @autoreleasepool {
    if(!p)return;char error[1024];
    if(!a2_gpu_present_suspend(p,error,sizeof error))fprintf(stderr,"gpu-present: teardown: %s\n",error);
    A2PresentationStorage *s=CFBridgingRelease(p->storage);if(s->layer)s->layer.framebufferOnly=s->originalFramebufferOnly;
    if(getenv("A2_GPU_PRESENT_PROFILE")) {
        A2GpuPresentStats v=p->stats;
        fprintf(stderr,"gpu-present-stats: prepared=%llu aa_dispatches=%llu aa_reuses=%llu panel_uploads=%llu composites=%llu commits=%llu submitted=%llu readbacks=%llu window_readbacks=%llu previous_waits=%llu\n",
            (unsigned long long)v.prepared,(unsigned long long)v.aa_dispatches,(unsigned long long)v.aa_reuses,(unsigned long long)v.panel_uploads,
            (unsigned long long)v.composites,(unsigned long long)v.commits,(unsigned long long)v.presented,(unsigned long long)v.readbacks,
            (unsigned long long)v.window_readbacks,(unsigned long long)v.previous_waits);
    }
    free(p);
} }

void a2_gpu_present_set_fill(A2GpuPresent *p,int fill) {if(p)p->fill_screen=!!fill;}
