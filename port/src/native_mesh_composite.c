#include "native_mesh_composite.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct A2MeshComposite {
    uint32_t width,height;
    uint16_t *alternate,*model;
    float *depth;
    uint8_t *coverage;
    uint8_t *owners,anchored[65];
    unsigned owner_count;
    int valid;
    unsigned failure;
};

A2MeshComposite *a2_mesh_composite_create(uint32_t width,uint32_t height){
    if(!width||!height||width>4096||height>4096||(uint64_t)width*height>4u*1024u*1024u)return NULL;
    A2MeshComposite *c=calloc(1,sizeof *c);if(!c)return NULL;
    size_t n=(size_t)width*height;c->width=width;c->height=height;
    c->alternate=malloc(n*sizeof *c->alternate);c->model=malloc(n*sizeof *c->model);
    c->depth=malloc(n*sizeof *c->depth);c->coverage=malloc(n);
    c->owners=malloc(n);
    if(!c->alternate||!c->model||!c->depth||!c->coverage||!c->owners){a2_mesh_composite_destroy(c);return NULL;}
    return c;
}
void a2_mesh_composite_destroy(A2MeshComposite *c){
    if(c){free(c->alternate);free(c->model);free(c->depth);free(c->coverage);free(c->owners);free(c);}
}
void a2_mesh_composite_invalidate(A2MeshComposite *c){if(c){if(c->valid)c->failure=1;c->valid=0;}}
int a2_mesh_composite_valid(const A2MeshComposite *c){return c&&c->valid;}
unsigned a2_mesh_composite_failure(const A2MeshComposite *c){return c?c->failure:2;}
static int image_valid(const A2MeshComposite *c,A2CompositeImage a,size_t pixel_size){
    size_t row=(size_t)c->width*pixel_size;
    return a.data&&a.stride>=row&&a.size>=row&&
        (c->height==1||a.stride<=(a.size-row)/(c->height-1));
}
int a2_mesh_composite_begin(A2MeshComposite *c,int clean,
    A2CompositeImage background,A2CompositeImage model,A2CompositeImage depth,A2CompositeImage coverage){
    if(!c)return 0;c->valid=0;c->failure=2;c->owner_count=0;memset(c->anchored,0,sizeof c->anchored);
    if(clean!=1||!image_valid(c,background,2)||!image_valid(c,model,2)||
       !image_valid(c,depth,sizeof(float))||!image_valid(c,coverage,1))return 0;
    /* memcpy also permits byte-aligned diagnostic buffers. Input strides have
     * already been checked against their declared spans without multiplication. */
    for(uint32_t y=0;y<c->height;y++){
        size_t index=(size_t)y*c->width;
        memcpy(c->alternate+index,(const uint8_t *)background.data+y*background.stride,c->width*2u);
        memcpy(c->model+index,(const uint8_t *)model.data+y*model.stride,c->width*2u);
        memcpy(c->depth+index,(const uint8_t *)depth.data+y*depth.stride,c->width*sizeof(float));
        memcpy(c->coverage+index,(const uint8_t *)coverage.data+y*coverage.stride,c->width);
        for(uint32_t x=0;x<c->width;x++){
            size_t i=index+x;if(c->coverage[i]>1)return 0;
            if(c->coverage[i]){
                if(!isfinite(c->depth[i])||c->depth[i]<0||c->depth[i]>1)return 0;
                c->model[i]&=0x7fff;c->alternate[i]=c->model[i];
            }
        }
    }
    c->valid=1;c->failure=0;return 1;
}
int a2_mesh_composite_owners(A2MeshComposite *c,A2CompositeImage tags,unsigned count){
    if(!c||!c->valid)return 0;
    if(!count||count>64||!image_valid(c,tags,sizeof(uint32_t)))goto bad;
    for(uint32_t y=0;y<c->height;y++)for(uint32_t x=0;x<c->width;x++){
        uint32_t tag;memcpy(&tag,(const uint8_t *)tags.data+y*tags.stride+x*4,4);
        size_t i=(size_t)y*c->width+x;
        if(tag>count||(c->coverage[i]&&!tag))goto bad;
        c->owners[i]=(uint8_t)tag;
    }
    c->owner_count=count;memset(c->anchored,0,sizeof c->anchored);return 1;
bad:c->valid=0;c->failure=2;return 0;
}
int a2_mesh_composite_anchor(A2MeshComposite *c,unsigned tag){
    if(!c||!c->valid||!tag||tag>c->owner_count)return 0;
    c->anchored[tag]=1;return 1;
}
void a2_mesh_composite_store(A2MeshComposite *c,int x,int y,uint16_t value){
    if(!c||!c->valid||x<0||y<0||(uint32_t)x>=c->width||(uint32_t)y>=c->height)return;
    size_t i=(size_t)y*c->width+(unsigned)x;
    c->alternate[i]=value;c->coverage[i]=c->owners[i]=0;
}
/* Exact gpu.c blend()/put_fine_pixel() RGB8 arithmetic AFTER modulation,
 * including C integer division and saturation before RGB555 quantization. */
static uint16_t apply(uint16_t before,A2CompositePixel p,int semi){
    const int source[3]={p.r,p.g,p.b};uint16_t result=p.textured?(p.texel&0x8000):0;
    for(unsigned channel=0;channel<3;channel++){
        int color=source[channel],bg=((before>>(channel*5))&31)*8;
        if(semi)switch(p.blend_mode){
            case 0:color=(bg+color)/2;break;
            case 1:color=bg+color;break;
            case 2:color=bg-color;break;
            default:color=bg+color/4;break;
        }
        if(color<0)color=0;if(color>255)color=255;
        result|=(uint16_t)((color>>3)<<(channel*5));
    }
    return result;
}
uint16_t *a2_mesh_composite_destination(A2MeshComposite *c,int x,int y,A2CompositeKind kind,float depth){
    if(!c||!c->valid||x<0||y<0||(uint32_t)x>=c->width||(uint32_t)y>=c->height)return NULL;
    if(kind<A2_COMPOSITE_WORLD||kind>A2_COMPOSITE_ORDERED){c->valid=0;c->failure=3;return NULL;}
    if(kind==A2_COMPOSITE_OWNED)return NULL;
    size_t i=(size_t)y*c->width+(uint32_t)x;
    if(kind==A2_COMPOSITE_ORDERED&&c->coverage[i]){
        if(!c->owner_count){c->valid=0;c->failure=2;return NULL;}
        if(!c->anchored[c->owners[i]])return NULL;
    }
    if(kind==A2_COMPOSITE_WORLD&&c->coverage[i]){
        if(!isfinite(depth)||depth<0||depth>1){c->valid=0;c->failure=4;return NULL;}
        /* Opaque model depth is fixed. Near/equal WORLD and HUD preserve OT
         * order; a farther world fragment must not erase earlier foreground. */
        if(depth>c->depth[i])return NULL;
    }
    return &c->alternate[i];
}
void a2_mesh_composite_pixel(A2MeshComposite *c,int x,int y,A2CompositePixel p){
    if(!c||!c->valid||x<0||y<0||(uint32_t)x>=c->width||(uint32_t)y>=c->height)return;
    if(p.semi>1||p.textured>1||p.blend_mode>3){c->valid=0;c->failure=2;return;}
    if(p.textured&&!p.texel)return;
    uint16_t *dst=a2_mesh_composite_destination(c,x,y,p.kind,p.depth);
    if(dst)*dst=apply(*dst,p,p.semi&&(!p.textured||(p.texel&0x8000)));
}
const uint16_t *a2_mesh_composite_row(const A2MeshComposite *c,uint32_t y,const uint16_t *original){
    return c&&c->valid&&y<c->height?c->alternate+(size_t)y*c->width:original;
}
