#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#include "gpu_fine.h"
#include "texture_versions.h"
#include "gpu_fine_shader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdarg.h>

enum { TILE=16, MAX_COMMANDS=65536, MAX_ENTRIES=16*1024*1024,
       TEXTURE_BYTES=8*1024*1024, MASK_BYTES=8*1024*1024, TEXTURE_SLOTS=256, POOL_MAP_SIZE=1024 };
typedef struct { uint32_t offset,width,palette,mode; } TextureRegion;
typedef struct { A2FineParams params; TextureRegion texture; uint32_t maskOffset,maskStride,minifyMaskOffset,footprintOffset; } FineCommand;
typedef struct { int x0,y0,x1,y1; const A2TexVersion *lease; } FineBounds;
typedef struct { uint64_t id; TextureRegion region; } PoolEntry;
typedef struct { uint32_t width,height,columns,tile; } BatchInfo;
_Static_assert(sizeof(FineCommand)==208,"Metal command ABI");
static double now_ms(void) {
    struct timespec t;clock_gettime(CLOCK_MONOTONIC,&t);
    return t.tv_sec*1000.0+t.tv_nsec*1e-6;
}
static int fail(char *error,size_t size,const char *format,...) {
    if(error&&size){va_list args;va_start(args,format);vsnprintf(error,size,format,args);va_end(args);}
    return 0;
}
static void clear_error(char *error,size_t size){if(error&&size)*error=0;}

/* CPU metadata and Metal buffers have one owner. No GPU submission is in
 * flight when enqueue mutates them; sync commits and retires the whole batch. */
@interface A2FineContext : NSObject {
@public
    id<MTLDevice> device;
    id<MTLCommandQueue> queue;
    id<MTLComputePipelineState> pipeline;
    id<MTLBuffer> lowBuffer,rgbBuffer,commandBuffer,offsetBuffer,indexBuffer,activeBuffer,textureBuffer,maskBuffer;
    FineCommand *commands;
    uint32_t *offsets,*indices,*active;
    uint16_t *textureWords;
    uint8_t *maskWords;
    FineBounds *bounds;
    A2TexCache *cache;
    PoolEntry poolMap[POOL_MAP_SIZE];
    unsigned width,height,columns,tiles,count,commandCapacity,indexCapacity,entries,activeCount,poolUsed,maskUsed,maskCapacity;
    BOOL failed;
    char failure[512];
    A2FineGpuStats stats;
}
@end
@implementation A2FineContext
- (void)dealloc {
    for(unsigned i=0;i<count;i++)if(bounds[i].lease)a2_tex_release(cache,bounds[i].lease);
    free(bounds);a2_tex_destroy(cache);
    /* lowBuffer/rgbBuffer deliberately have no deallocator. */
}
@end

static int reserve_commands(A2FineContext *c,unsigned required) {
    if(required<=c->commandCapacity)return 1;
    unsigned capacity=c->commandCapacity?c->commandCapacity:256;
    while(capacity<required)capacity*=2;
    if(capacity>MAX_COMMANDS)return 0;
    id<MTLBuffer> buffer=[c->device newBufferWithLength:(size_t)capacity*sizeof(FineCommand) options:MTLResourceStorageModeShared];
    if(!buffer)return 0;
    FineBounds *bounds=realloc(c->bounds,(size_t)capacity*sizeof *bounds);
    if(!bounds)return 0;
    if(c->count)memcpy(buffer.contents,c->commands,(size_t)c->count*sizeof(FineCommand));
    c->bounds=bounds;c->commandBuffer=buffer;c->commands=buffer.contents;c->commandCapacity=capacity;
    c->stats.buffer_allocations++;
    return 1;
}
static int reserve_indices(A2FineContext *c,unsigned required) {
    if(required<=c->indexCapacity)return 1;
    unsigned capacity=c->indexCapacity?c->indexCapacity:4096;
    while(capacity<required)capacity*=2;
    if(capacity>MAX_ENTRIES)return 0;
    id<MTLBuffer> buffer=[c->device newBufferWithLength:(size_t)capacity*4 options:MTLResourceStorageModeShared];
    if(!buffer)return 0;
    c->indexBuffer=buffer;c->indices=buffer.contents;c->indexCapacity=capacity;
    c->stats.buffer_allocations++;
    return 1;
}
static int reserve_masks(A2FineContext *c,unsigned required) {
    if(required<=c->maskCapacity)return 1;
    if(required>MASK_BYTES)return 0;
    unsigned capacity=c->maskCapacity?c->maskCapacity:65536;
    while(capacity<required)capacity*=2;
    id<MTLBuffer> buffer=[c->device newBufferWithLength:capacity options:MTLResourceStorageModeShared];
    if(!buffer)return 0;
    /* CPU filled previous masks before this call; preserve them before moving
     * the pool. No Metal work has been submitted while enqueue is allowed. */
    if(c->maskUsed)memcpy(buffer.contents,c->maskWords,c->maskUsed);
    c->maskBuffer=buffer;c->maskWords=buffer.contents;c->maskCapacity=capacity;
    c->stats.buffer_allocations++;return 1;
}
static int bounds_for(A2FineContext *c,const A2FineParams *p,FineBounds *out) {
    if(!p||p->width!=c->width||p->height!=c->height||(p->state[3]&~63u))return 0;
    if((p->state[3]&8)&&(p->uv[0]>p->uv[2]||p->uv[1]>p->uv[3]))return 0;
    int64_t minx=p->p[0].x,maxx=minx,miny=p->p[0].y,maxy=miny;
    for(unsigned a=0;a<3;a++) {
        const A2FineVertex *v=&p->p[a];
        if(v->r>255||v->g>255||v->b>255||v->u>255||v->v>255||
           v->x<-(1ll<<31)||v->x>(1ll<<31)||v->y<-(1ll<<31)||v->y>(1ll<<31))return 0;
        for(unsigned b=0;b<a;b++) {
            int64_t dx=v->x-p->p[b].x,dy=v->y-p->p[b].y;
            if(dx<=-(1ll<<30)||dx>=(1ll<<30)||dy<=-(1ll<<30)||dy>=(1ll<<30))return 0;
        }
        if(v->x<minx)minx=v->x;if(v->x>maxx)maxx=v->x;
        if(v->y<miny)miny=v->y;if(v->y>maxy)maxy=v->y;
    }
    int x0=(int)(minx/65536-(minx<0&&minx%65536)),x1=(int)(maxx/65536-(maxx<0&&maxx%65536));
    int y0=(int)(miny/65536-(miny<0&&miny%65536)),y1=(int)(maxy/65536-(maxy<0&&maxy%65536));
    if(x0<0)x0=0;if(y0<0)y0=0;if(x0<p->clip[0])x0=p->clip[0];if(y0<p->clip[1])y0=p->clip[1];
    if(x1>=(int)c->width)x1=(int)c->width-1;if(y1>=(int)c->height)y1=(int)c->height-1;
    if(x1>p->clip[2])x1=p->clip[2];if(y1>p->clip[3])y1=p->clip[3];
    *out=(FineBounds){x0,y0,x1,y1,NULL};return 1;
}
static PoolEntry *pool_entry(A2FineContext *c,uint64_t id) {
    unsigned at=(unsigned)((id*11400714819323198485ull)>>32)&(POOL_MAP_SIZE-1);
    for(unsigned i=0;i<POOL_MAP_SIZE;i++,at=(at+1)&(POOL_MAP_SIZE-1))
        if(!c->poolMap[at].id||c->poolMap[at].id==id)return &c->poolMap[at];
    return NULL;
}
static int pool_region(A2FineContext *c,const A2TexVersion *version,TextureRegion *out) {
    A2TexRegion region=a2_tex_region(version);PoolEntry *entry=pool_entry(c,region.id);
    if(entry&&entry->id){*out=entry->region;return 1;}
    unsigned bytes=region.word_count*2;
    if(!entry||bytes>TEXTURE_BYTES-c->poolUsed) {
        /* No earlier accepted command may lose its immutable pool offsets. */
        if(c->count)return 0;
        memset(c->poolMap,0,sizeof c->poolMap);c->poolUsed=0;entry=pool_entry(c,region.id);
    }
    if(!entry||bytes>TEXTURE_BYTES-c->poolUsed)return 0;
    *out=(TextureRegion){c->poolUsed/2,region.width_words,region.width_words*256,region.mode};
    memcpy(c->textureWords+c->poolUsed/2,a2_tex_words(version),bytes);
    entry->id=region.id;entry->region=*out;c->poolUsed+=bytes;
    c->stats.uploaded_bytes+=bytes;c->stats.texture_uploaded_bytes+=bytes;
    if(c->stats.peak_texture_pool_bytes<c->poolUsed)c->stats.peak_texture_pool_bytes=c->poolUsed;
    return 1;
}

A2FineGpu *a2_fine_gpu_create(unsigned width,unsigned height,uint16_t *low,uint32_t *rgb,char *error,size_t size) {@autoreleasepool {
    clear_error(error,size);size_t page=(size_t)sysconf(_SC_PAGESIZE);
    if(!width||!height||width>4096||height>4096||!low||!rgb||!page||
       (uintptr_t)low%page||(uintptr_t)rgb%page) {
        fail(error,size,"fine GPU requires dimensions 1..4096 and page-aligned borrowed surfaces");return NULL;
    }
    A2FineContext *c=[A2FineContext new];c->device=MTLCreateSystemDefaultDevice();
    if(!c->device){fail(error,size,"no Metal device");return NULL;}
    NSError *metalError=nil;MTLCompileOptions *options=[MTLCompileOptions new];
    /* Retain the exact H30 setting on older supported SDKs/runtimes too. */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    options.fastMathEnabled=NO;
#pragma clang diagnostic pop
    id<MTLLibrary> library=[c->device newLibraryWithSource:[NSString stringWithUTF8String:a2_gpu_fine_shader] options:options error:&metalError];
    if(!library){fail(error,size,"fine GPU shader: %s",metalError.description.UTF8String);return NULL;}
    c->pipeline=[c->device newComputePipelineStateWithFunction:[library newFunctionWithName:@"fine_tiles"] error:&metalError];
    if(!c->pipeline||c->pipeline.maxTotalThreadsPerThreadgroup<TILE*TILE){
        fail(error,size,"fine GPU pipeline: %s",metalError?metalError.description.UTF8String:"unsupported tile size");return NULL;
    }
    c->width=width;c->height=height;c->columns=(width+TILE-1)/TILE;c->tiles=c->columns*((height+TILE-1)/TILE);
    c->queue=[c->device newCommandQueue];c->cache=a2_tex_create(TEXTURE_BYTES,TEXTURE_SLOTS);
    size_t pixels=(size_t)width*height;
    c->lowBuffer=[c->device newBufferWithBytesNoCopy:low length:((pixels*2+page-1)/page)*page options:MTLResourceStorageModeShared deallocator:nil];
    c->rgbBuffer=[c->device newBufferWithBytesNoCopy:rgb length:((pixels*4+page-1)/page)*page options:MTLResourceStorageModeShared deallocator:nil];
    c->offsetBuffer=[c->device newBufferWithLength:((size_t)c->tiles+1)*4 options:MTLResourceStorageModeShared];
    /* Second half is reusable CPU insertion cursor storage, never sent to GPU. */
    c->activeBuffer=[c->device newBufferWithLength:(size_t)c->tiles*8 options:MTLResourceStorageModeShared];
    c->textureBuffer=[c->device newBufferWithLength:TEXTURE_BYTES options:MTLResourceStorageModeShared];
    if(!c->queue||!c->cache||!c->lowBuffer||!c->rgbBuffer||!c->offsetBuffer||!c->activeBuffer||!c->textureBuffer||
       !reserve_commands(c,1)||!reserve_indices(c,1)||!reserve_masks(c,1)) {
        fail(error,size,"fine GPU bounded buffer allocation failed");return NULL;
    }
    c->offsets=c->offsetBuffer.contents;c->active=c->activeBuffer.contents;c->textureWords=c->textureBuffer.contents;
    memset(c->offsets,0,((size_t)c->tiles+1)*4);c->stats.buffer_allocations+=5;
    return (__bridge_retained A2FineGpu *)c;
}}
static int enqueue(A2FineGpu *ctx,const A2FineParams *params,const uint16_t *native,const A2FineMinify *footprint,uint8_t **mask,uint8_t **minify,char *error,size_t size) {@autoreleasepool {
    if(mask)*mask=NULL;if(minify)*minify=NULL;
    clear_error(error,size);A2FineContext *c=(__bridge A2FineContext *)ctx;
    if(!c)return fail(error,size,"fine GPU context unavailable");
    if(c->failed)return fail(error,size,"fine GPU failed: %s",c->failure);
    double begin=now_ms();FineBounds b;
    if(!bounds_for(c,params,&b)||((params->state[3]&2)&&!native)) {
        c->stats.unsupported_rejections++;return fail(error,size,"fine GPU affine contract unsupported");
    }
    if(footprint) {
        unsigned n=footprint->count;
        if((params->state[3]&(2|8))!=(2|8)||(n!=2&&n!=4&&n!=8&&n!=16)) {
            c->stats.unsupported_rejections++;return fail(error,size,"fine GPU minify requires filtered texture and 2/4/8/16 samples");
        }
        for(unsigned i=0;i<n;i++)for(unsigned axis=0;axis<2;axis++)
            if(footprint->offsets[i][axis]<-65280||footprint->offsets[i][axis]>65280) {
                c->stats.unsupported_rejections++;return fail(error,size,"fine GPU minify offset outside exact Q8 contract");
            }
    }
    unsigned maskBytes=0,planeBytes=0,maskStride=0,footprintOffset=UINT32_MAX;
    if(mask) {
        if(params->clip[0]<0||params->clip[1]<0||params->clip[2]<params->clip[0]||
           params->clip[3]<params->clip[1]||params->clip[2]>=(int)c->width||params->clip[3]>=(int)c->height) {
            c->stats.unsupported_rejections++;return fail(error,size,"fine GPU mask clip must be nonempty and inside the surface");
        }
        maskStride=((unsigned)(params->clip[2]-params->clip[0])+8)/8;
        planeBytes=maskStride*(unsigned)(params->clip[3]-params->clip[1]+1);
        maskBytes=planeBytes;
        if(footprint) {
            footprintOffset=(c->maskUsed+planeBytes*2+3)&~3u;
            maskBytes=footprintOffset+sizeof(A2FineMinify)-c->maskUsed;
        }
        if(maskBytes>MASK_BYTES-c->maskUsed||!reserve_masks(c,c->maskUsed+maskBytes)) {
            c->stats.capacity_rejections++;return fail(error,size,"fine GPU mask capacity: synchronize then retry");
        }
    }
    unsigned added=0;
    if(b.x0<=b.x1&&b.y0<=b.y1)added=(unsigned)(b.x1/TILE-b.x0/TILE+1)*(unsigned)(b.y1/TILE-b.y0/TILE+1);
    if(c->count==MAX_COMMANDS||added>MAX_ENTRIES-c->entries||
       !reserve_commands(c,c->count+1)||!reserve_indices(c,c->entries+added)) {
        c->stats.capacity_rejections++;return fail(error,size,"fine GPU command/tile capacity: synchronize then retry");
    }
    TextureRegion region={0};
    if((params->state[3]&2)&&added) {
        b.lease=a2_tex_acquire(c->cache,native,params->state[0],params->state[1]);
        if(!b.lease||!pool_region(c,b.lease,&region)) {
            if(b.lease)a2_tex_release(c->cache,b.lease);
            c->stats.capacity_rejections++;return fail(error,size,"fine GPU texture capacity: synchronize then retry");
        }
    }
    /* All possible refusals are above. Publish the zeroed mask only once the
     * command is irrevocably admitted; filling it cannot cause a later refusal. */
    unsigned maskOffset=UINT32_MAX,minifyMaskOffset=UINT32_MAX;
    if(mask) {
        maskOffset=c->maskUsed;memset(c->maskWords+maskOffset,0,maskBytes);
        if(footprint) {
            minifyMaskOffset=maskOffset+planeBytes;
            memcpy(c->maskWords+footprintOffset,footprint,sizeof *footprint);
            c->stats.minified_triangles++;
        }
        c->maskUsed+=maskBytes;c->stats.masked_triangles++;c->stats.mask_uploaded_bytes+=maskBytes;
        if(c->stats.peak_mask_pool_bytes<c->maskUsed)c->stats.peak_mask_pool_bytes=c->maskUsed;
    }
    c->commands[c->count]=(FineCommand){*params,region,maskOffset,maskStride,minifyMaskOffset,footprintOffset};c->bounds[c->count]=b;c->count++;c->entries+=added;
    if(added)for(unsigned y=(unsigned)b.y0/TILE;y<=(unsigned)b.y1/TILE;y++)
        for(unsigned x=(unsigned)b.x0/TILE;x<=(unsigned)b.x1/TILE;x++) {
            unsigned tile=y*c->columns+x;
            if(!c->offsets[tile+1]++)c->active[c->activeCount++]=tile;
        }
    c->stats.triangles++;c->stats.queued_triangles=c->count;
    if(c->stats.peak_queued_triangles<c->count)c->stats.peak_queued_triangles=c->count;
    c->stats.prepare_ms+=now_ms()-begin;
    if(mask)*mask=c->maskWords+maskOffset;
    if(minify)*minify=c->maskWords+minifyMaskOffset;
    return 1;
}}
int a2_fine_gpu_enqueue(A2FineGpu *ctx,const A2FineParams *params,const uint16_t *native,char *error,size_t size) {
    return enqueue(ctx,params,native,NULL,NULL,NULL,error,size);
}
int a2_fine_gpu_enqueue_masked(A2FineGpu *ctx,const A2FineParams *params,const uint16_t *native,uint8_t **mask,char *error,size_t size) {
    if(!mask)return fail(error,size,"fine GPU masked enqueue requires a mask output");
    return enqueue(ctx,params,native,NULL,mask,NULL,error,size);
}
int a2_fine_gpu_enqueue_minified(A2FineGpu *ctx,const A2FineParams *params,const uint16_t *native,
    const A2FineMinify *footprint,uint8_t **allow,uint8_t **minify,char *error,size_t size) {
    if(allow)*allow=NULL;if(minify)*minify=NULL;
    if(!allow||!minify||allow==minify||!footprint)return fail(error,size,"fine GPU minified enqueue requires footprint and distinct mask outputs");
    return enqueue(ctx,params,native,footprint,allow,minify,error,size);
}
void a2_fine_gpu_written(A2FineGpu *ctx,int x,int y,int width,int height) {
    A2FineContext *c=(__bridge A2FineContext *)ctx;if(c)a2_tex_written(c->cache,x,y,width,height);
}
static void retire(A2FineContext *c) {
    for(unsigned i=0;i<c->count;i++)if(c->bounds[i].lease)a2_tex_release(c->cache,c->bounds[i].lease);
    c->count=0;c->entries=0;c->activeCount=0;c->maskUsed=0;c->stats.queued_triangles=0;
    memset(c->offsets,0,((size_t)c->tiles+1)*4);
}
int a2_fine_gpu_sync(A2FineGpu *ctx,char *error,size_t size) {@autoreleasepool {
    clear_error(error,size);A2FineContext *c=(__bridge A2FineContext *)ctx;
    if(!c)return fail(error,size,"fine GPU context unavailable");
    if(c->failed)return fail(error,size,"fine GPU failed: %s",c->failure);
    if(!c->count)return 1;
    if(!c->entries){retire(c);return 1;}
    double begin=now_ms();
    for(unsigned i=1;i<=c->tiles;i++)c->offsets[i]+=c->offsets[i-1];
    uint32_t *cursor=c->active+c->tiles;memcpy(cursor,c->offsets,(size_t)c->tiles*4);
    for(unsigned i=0;i<c->count;i++) {
        FineBounds b=c->bounds[i];if(b.x0>b.x1||b.y0>b.y1)continue;
        for(unsigned y=(unsigned)b.y0/TILE;y<=(unsigned)b.y1/TILE;y++)
            for(unsigned x=(unsigned)b.x0/TILE;x<=(unsigned)b.x1/TILE;x++)c->indices[cursor[y*c->columns+x]++]=i;
    }
    c->stats.prepare_ms+=now_ms()-begin;begin=now_ms();
    id<MTLCommandBuffer> command=[c->queue commandBuffer];id<MTLComputeCommandEncoder> encoder=[command computeCommandEncoder];
    if(!command||!encoder) {
        c->failed=YES;snprintf(c->failure,sizeof c->failure,"Metal command encoder allocation failed");
        retire(c);return fail(error,size,"%s",c->failure);
    }
    BatchInfo info={c->width,c->height,c->columns,TILE};
    [encoder setComputePipelineState:c->pipeline];
    [encoder setBuffer:c->commandBuffer offset:0 atIndex:0];[encoder setBuffer:c->textureBuffer offset:0 atIndex:1];
    [encoder setBuffer:c->lowBuffer offset:0 atIndex:2];[encoder setBuffer:c->rgbBuffer offset:0 atIndex:3];
    [encoder setBuffer:c->offsetBuffer offset:0 atIndex:4];[encoder setBuffer:c->indexBuffer offset:0 atIndex:5];
    [encoder setBytes:&info length:sizeof info atIndex:6];[encoder setBuffer:c->activeBuffer offset:0 atIndex:7];
    [encoder setBuffer:c->maskBuffer offset:0 atIndex:8];
    [encoder dispatchThreadgroups:MTLSizeMake(c->activeCount,1,1) threadsPerThreadgroup:MTLSizeMake(TILE,TILE,1)];
    [encoder endEncoding];[command commit];
    c->stats.submissions++;c->stats.uploaded_bytes+=(size_t)c->count*sizeof(FineCommand)+(size_t)(c->tiles+1)*4+(size_t)c->entries*4+(size_t)c->activeCount*4+c->maskUsed;
    c->stats.encode_ms+=now_ms()-begin;begin=now_ms();
    [command waitUntilCompleted];c->stats.waits++;c->stats.wait_ms+=now_ms()-begin;
    if(command.status!=MTLCommandBufferStatusCompleted) {
        c->failed=YES;snprintf(c->failure,sizeof c->failure,"Metal execution: %s",command.error.description.UTF8String);
    } else c->stats.gpu_ms+=(command.GPUEndTime-command.GPUStartTime)*1000.0;
    retire(c);
    return c->failed?fail(error,size,"%s",c->failure):1;
}}
A2FineGpuStats a2_fine_gpu_stats(const A2FineGpu *ctx) {
    A2FineContext *c=(__bridge A2FineContext *)ctx;if(!c)return (A2FineGpuStats){0};
    A2FineGpuStats stats=c->stats;A2TexStats ts=a2_tex_stats(c->cache);
    stats.texture_requests=ts.requests;stats.texture_hits=ts.hits;stats.texture_misses=ts.misses;stats.texture_copied_bytes=ts.copied_bytes;
    return stats;
}
void a2_fine_gpu_destroy(A2FineGpu *ctx) {
    if(!ctx)return;
    char error[512];if(!a2_fine_gpu_sync(ctx,error,sizeof error))fprintf(stderr,"fine GPU destroy: %s\n",error);
    @autoreleasepool { A2FineContext *c=(__bridge_transfer A2FineContext *)ctx;(void)c; }
}
