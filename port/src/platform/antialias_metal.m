#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#include "antialias.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

@interface A2AAStorage:NSObject {
@public id<MTLDevice> device; id<MTLCommandQueue> queue;
    id<MTLComputePipelineState> pipeline; id<MTLTexture> input;
    id<MTLBuffer> output, cachedInput; int width,height,cacheValid;
} @end
@implementation A2AAStorage @end
struct A2Antialias { void *storage; A2AntialiasStats stats; };
A2AntialiasStats a2_antialias_stats(const A2Antialias *aa) {
    return aa?aa->stats:(A2AntialiasStats){0,0};
}
static void fail(char *error,size_t size,NSString *message) {
    if(error&&size)snprintf(error,size,"%s",message.UTF8String?:"Metal antialias failed");
}

#include "fxaa_source.h"


A2Antialias *a2_antialias_create(char *error,size_t error_size) { @autoreleasepool {
    if(error&&error_size)error[0]=0;
    A2AAStorage *s=[A2AAStorage new];s->device=MTLCreateSystemDefaultDevice();
    if(!s->device){fail(error,error_size,@"No Metal device");return NULL;}
    NSError *failure=nil;
    id<MTLLibrary> library=[s->device newLibraryWithSource:a2_fxaa_source options:nil error:&failure];
    if(!library){fail(error,error_size,failure.localizedDescription);return NULL;}
    s->pipeline=[s->device newComputePipelineStateWithFunction:[library newFunctionWithName:@"antialias"] error:&failure];
    s->queue=[s->device newCommandQueue];
    if(!s->pipeline||!s->queue){fail(error,error_size,failure.localizedDescription);return NULL;}
    A2Antialias *aa=calloc(1,sizeof *aa);if(!aa){fail(error,error_size,@"Allocation failed");return NULL;}
    aa->storage=(__bridge_retained void *)s;
    fprintf(stderr,"antialias: Metal FXAA enabled on %s\n",s->device.name.UTF8String);
    return aa;
} }
int a2_antialias_apply(A2Antialias *aa,uint32_t *pixels,int width,int height,
                       int stride,char *error,size_t error_size) { @autoreleasepool {
    if(error&&error_size)error[0]=0;
    if(!aa||!pixels||width<1||height<1||width>4096||height>4096||stride<width||
       (size_t)stride>SIZE_MAX/4/(size_t)height){fail(error,error_size,@"Invalid AA image layout");return 0;}
    A2AAStorage *s=(__bridge A2AAStorage *)aa->storage;
    if(s->width!=width||s->height!=height) {
        MTLTextureDescriptor *d=[MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatBGRA8Unorm
            width:width height:height mipmapped:NO];
        d.usage=MTLTextureUsageShaderRead;
        d.storageMode=s->device.hasUnifiedMemory?MTLStorageModeShared:MTLStorageModeManaged;
        id<MTLTexture> input=[s->device newTextureWithDescriptor:d];
        id<MTLBuffer> output=[s->device newBufferWithLength:(size_t)width*height*4 options:MTLResourceStorageModeShared];
        if(!input||!output){fail(error,error_size,@"AA frame allocation failed");return 0;}
        s->input=input;s->output=output;s->width=width;s->height=height;s->cacheValid=0;
        /* Reuse is optional under memory pressure; drawing remains available. */
        s->cachedInput=[s->device newBufferWithLength:(size_t)width*height*4 options:MTLResourceStorageModeShared];
    }
    uint32_t *savedInput=s->cachedInput.contents;
    int unchanged=s->cacheValid && savedInput;
    for(int y=0;unchanged&&y<height;y++)
        unchanged=!memcmp(pixels+(size_t)y*stride,savedInput+(size_t)y*width,(size_t)width*4);
    if(unchanged) {
        /* Compare visible pixels, not padding or a dirty hint. Cursor, fade,
         * palette and same-buffer writes therefore cannot reuse stale AA. */
        const uint32_t *result=s->output.contents;
        for(int y=0;y<height;y++)memcpy(pixels+(size_t)y*stride,result+(size_t)y*width,(size_t)width*4);
        ++aa->stats.reused_frames;return 1;
    }
    s->cacheValid=0;
    if(savedInput)for(int y=0;y<height;y++)
        memcpy(savedInput+(size_t)y*width,pixels+(size_t)y*stride,(size_t)width*4);
    [s->input replaceRegion:MTLRegionMake2D(0,0,width,height) mipmapLevel:0 withBytes:pixels bytesPerRow:(size_t)stride*4];
    id<MTLCommandBuffer> command=[s->queue commandBuffer];
    id<MTLComputeCommandEncoder> encoder=[command computeCommandEncoder];
    if(!command||!encoder){fail(error,error_size,@"AA command allocation failed");return 0;}
    [encoder setComputePipelineState:s->pipeline];[encoder setTexture:s->input atIndex:0];
    [encoder setBuffer:s->output offset:0 atIndex:0];
    NSUInteger tw=s->pipeline.threadExecutionWidth,th=MIN((NSUInteger)8,s->pipeline.maxTotalThreadsPerThreadgroup/tw);
    [encoder dispatchThreadgroups:MTLSizeMake((width+tw-1)/tw,(height+th-1)/th,1)
           threadsPerThreadgroup:MTLSizeMake(tw,th,1)];
    [encoder endEncoding];++aa->stats.gpu_dispatches;[command commit];[command waitUntilCompleted];
    if(command.status!=MTLCommandBufferStatusCompleted){fail(error,error_size,command.error.localizedDescription);return 0;}
    s->cacheValid=savedInput!=NULL;
    /* The software raster is retained. Readback makes recordings and the SDL
     * window use identical AA pixels, and leaves native menus independent. */
    const uint32_t *result=s->output.contents;
    for(int y=0;y<height;y++)memcpy(pixels+(size_t)y*stride,result+(size_t)y*width,(size_t)width*4);
    return 1;
} }
void a2_antialias_destroy(A2Antialias *aa) {
    if(!aa)return;
    if(getenv("A2_AA_PROFILE"))fprintf(stderr,"antialias-stats: gpu_dispatches=%llu reused_frames=%llu\n",
        (unsigned long long)aa->stats.gpu_dispatches,(unsigned long long)aa->stats.reused_frames);
    A2AAStorage *released=CFBridgingRelease(aa->storage);(void)released;free(aa);
}
