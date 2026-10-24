/* Actual decoded chest models and retained body/lid poses. Only the external
 * Metal backend is replaced with a recording sink; no native game is run. */
#include "native_mesh_scene.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fixtures/native_chest_packets.h"

struct A2MeshBackend { unsigned width,height; };
static unsigned submissions,recorded_count;
static A2MeshHandle next_handle;
static A2MeshDraw recorded[A2_MESH_MAX_DRAWS];
A2MeshBackend *a2_mesh_backend_create(uint32_t w,uint32_t h,char *e,size_t n){
    (void)e;(void)n;A2MeshBackend *b=malloc(sizeof *b);assert(b);b->width=w;b->height=h;return b;
}
void a2_mesh_backend_destroy(A2MeshBackend *b){free(b);}
A2MeshHandle a2_mesh_create(A2MeshBackend *b,const A2MeshVertex *v,uint32_t nv,
                           const void *indices,uint32_t ni,A2MeshIndexType type){
    assert(b&&v&&nv&&indices&&ni&&(type==2||type==4));return ++next_handle;
}
int a2_mesh_destroy(A2MeshBackend *b,A2MeshHandle h){assert(b&&h);return 1;}
A2MeshHandle a2_mesh_texture_create(A2MeshBackend *b,uint32_t w,uint32_t h,const uint8_t *p,size_t pitch){
    assert(b&&w&&h&&p&&pitch>=w*4);return ++next_handle;
}
int a2_mesh_texture_destroy(A2MeshBackend *b,A2MeshHandle h){assert(b&&h);return 1;}
int a2_mesh_render(A2MeshBackend *b,const A2MeshFrame *frame,const A2MeshDraw *draws,size_t count){
    assert(b&&frame&&draws&&count<=A2_MESH_MAX_DRAWS);
    for(size_t i=0;i<count;i++)assert(draws[i].depth_test==1&&draws[i].depth_write==1&&draws[i].color_write==1);
    memcpy(recorded,draws,count*sizeof *draws);recorded_count=(unsigned)count;++submissions;return 1;
}
int a2_mesh_readback(A2MeshBackend *b,uint8_t *rgba,size_t bytes,size_t stride,float *depth,size_t dbytes,size_t dstride){
    assert(b&&rgba&&depth&&bytes>=stride*b->height&&dbytes>=dstride*b->height);
    memset(rgba,0,bytes);memset(depth,0,dbytes);return 1;
}
int a2_mesh_readback_owners(A2MeshBackend *b,uint32_t *owners,size_t bytes,size_t stride){
    assert(b&&stride==b->width*sizeof *owners);
    if(!owners||bytes<stride*b->height)return 0;
    memset(owners,0,bytes);
    if(recorded_count){owners[0]=recorded[0].owner_tag;owners[b->width+1]=recorded[recorded_count-1].owner_tag;}
    return 1;
}

#ifdef A2_SCENE_PLAN_BASELINE
/* Exact pre-change caller behavior: all sealed owners are submitted, including
 * unsupported resources. This negative control must fail the mixed plan. */
static size_t plan(const A2MeshScene *s,const A2ActorPacketOwner *const *in,size_t n,
                   const A2ActorPacketOwner **out,size_t capacity){
    (void)s;if(n>capacity)return 0;memcpy(out,in,n*sizeof *out);return n;
}
#else
#define plan a2_mesh_scene_plan
#endif

static uint16_t u16(const uint8_t *p){return (uint16_t)(p[0]|(unsigned)p[1]<<8);}
static uint32_t u32(const uint8_t *p){return u16(p)|(uint32_t)u16(p+2)<<16;}
static A2NativeModel *load(const char *path,const char *key){
    FILE *f=fopen(path,"rb");assert(f);assert(!fseek(f,0,SEEK_END));long n=ftell(f);
    assert(n>0&&n<=A2_MODEL_MAX_BYTES);rewind(f);uint8_t *data=malloc((size_t)n);assert(data);
    assert(fread(data,1,(size_t)n,f)==(size_t)n&&!fclose(f));A2NativeModel *m=NULL;char error[256];
    assert(a2_native_model_decode(data,(size_t)n,&m,error,sizeof error));free(data);
    assert(!strcmp(m->source_key,key)&&m->joint_count==2);return m;
}
static void owner(A2ActorPacketOwner *o,const A2NativeModel *m,unsigned which,uint64_t source_generation){
    memset(o,0,sizeof *o);o->handle=which+100;o->instance.valid=o->instance.generation_known=o->instance.selected_for_draw=1;
    o->instance.instance_generation=which+200;o->instance.part_count=2;
    o->instance.entity_address=0x80119710+804*which;
    o->instance.registry_address=0x80180000+0x1000*which;
    o->instance.renderer_root_q12[0]=(560+100*(int)which)*4096;o->instance.renderer_root_q12[2]=860*4096;
    for(unsigned j=0;j<2;j++){
        const uint8_t *raw=j&&which==2?chest_open_lid:chest_closed_parts+80*j;A2ActorPart *p=&o->parts[j];
        memcpy(p->raw,raw,80);p->valid=p->visible=1;p->flags=u16(raw);p->source_mesh_index=j;
        p->address=0x801ec050+240*which+80*j;p->registry_address=o->instance.registry_address;
        p->source_generation=source_generation;strcpy(p->source_key,m->source_key);memcpy(p->source_sha256,m->source_sha256,32);
        for(unsigned r=0;r<3;r++){
            p->translation0[r]=(int32_t)u32(raw+8+4*r);p->translation1[r]=(int32_t)u32(raw+20+4*r);p->pretranslation[r]=(int16_t)u16(raw+52+2*r);
        }
        p->translation0[0]+=100*(int)which;
        for(unsigned r=0;r<9;r++)p->matrix_q12[r]=(int16_t)u16(raw+32+2*r);
    }
    for(unsigned j=0;j<3;j++)o->camera_rotation_q12[j*4]=4096;
    o->projection_h=96;o->projection_ofx=160<<16;o->projection_ofy=108<<16;
}
static unsigned draw(A2MeshScene *s,const A2ActorPacketOwner *const *owners,size_t count){
    const size_t n=640u*432u;uint8_t *rgba=malloc(n*4);float *depth=malloc(n*sizeof *depth);assert(rgba&&depth);
    unsigned ok=a2_mesh_scene_draw(s,owners,count,2,1,rgba,n*4,depth,n*sizeof *depth);
    free(rgba);free(depth);return ok;
}
int main(int argc,char **argv){
    assert(argc==3);A2NativeModel *t02=load(argv[1],"T02"),*t03=load(argv[2],"T03");
    unsigned nonopaque=0;for(unsigned j=0;j<t03->material_count;j++)nonopaque|=t03->materials[j].alpha_mode!=0||t03->materials[j].kind>1;
    assert(nonopaque); /* Real cooked T03 is outside the opaque bridge. */
    char error[128];A2MeshScene *s=a2_mesh_scene_create(640,432,error,sizeof error);assert(s);
    assert(a2_mesh_scene_add(s,t02)&&a2_mesh_scene_add(s,t03));
    A2ActorPacketOwner owners[3],before[3];owner(&owners[0],t02,0,11);owner(&owners[1],t03,1,17);owner(&owners[2],t02,2,29);
    memcpy(before,owners,sizeof owners);
    const A2ActorPacketOwner *all[]={owners,owners+1,owners+2},*selected[3]={0};
    assert(!draw(s,all,3)&&submissions==0); /* Real old group failure. */
    size_t count=plan(s,all,3,selected,3);
    assert(count==2&&selected[0]==owners&&selected[1]==owners+2);
    assert(!submissions&&!memcmp(before,owners,sizeof owners));
    assert(draw(s,selected,count)&&submissions==1&&recorded_count==2*t02->submesh_count);
    assert(recorded[0].model.m[3]==560&&recorded[t02->submesh_count].model.m[3]==760);
    assert(recorded[0].mesh==recorded[t02->submesh_count].mesh);
    for(unsigned i=0;i<recorded_count;i++)assert(recorded[i].owner_tag==i/t02->submesh_count+1);
    uint32_t *owner_map=malloc(640u*432u*sizeof *owner_map);assert(owner_map);
    assert(a2_mesh_scene_read_owners(s,owner_map,640u*432u*sizeof *owner_map));
    assert(owner_map[0]==1&&owner_map[641]==2&&owner_map[1]==0);
    assert(!a2_mesh_scene_read_owners(NULL,owner_map,640u*432u*sizeof *owner_map));
    assert(!a2_mesh_scene_read_owners(s,owner_map,1));free(owner_map);
    /* An unsupported leading camera cannot choose the supported scene camera. */
    const A2ActorPacketOwner *reordered[]={owners+1,owners+2,owners};owners[1].projection_h=0;
    assert(plan(s,reordered,3,selected,3)==2&&selected[0]==owners+2&&selected[1]==owners);
    assert(draw(s,selected,2)&&submissions==2);
    assert(recorded[0].model.m[3]==760&&recorded[t02->submesh_count].model.m[3]==560);
    for(unsigned i=0;i<recorded_count;i++)assert(recorded[i].owner_tag==i/t02->submesh_count+1);
    /* Failed pose or inconsistent cameras still reject before backend submission. */
    owners[2].projection_h=97;assert(!draw(s,selected,2)&&submissions==2);owners[2].projection_h=96;
    owners[2].parts[1].valid=0;assert(!draw(s,selected,2)&&submissions==2);owners[2].parts[1].valid=1;
    owners[2].projection_h=0;assert(!draw(s,selected,2)&&submissions==2);owners[2].projection_h=96;
    /* Same name with changed source bytes never acquires the loaded model. */
    owners[2].parts[1].source_sha256[0]^=1;assert(plan(s,all,3,selected,3)==1&&selected[0]==owners);
    owners[2].parts[1].source_sha256[0]^=1;
    owners[2].parts[1].source_generation=0;assert(plan(s,all,3,selected,3)==1);owners[2].parts[1].source_generation=29;
    owners[2].parts[1].source_generation=30;assert(plan(s,all,3,selected,3)==1);owners[2].parts[1].source_generation=29;
    strcpy(owners[2].parts[0].source_key,"MISSING");assert(plan(s,all,3,selected,3)==1);strcpy(owners[2].parts[0].source_key,"T02");
    /* Capacity failure leaves output untouched; no partial suppression plan. */
    selected[0]=owners+1;selected[1]=owners+1;selected[2]=owners+1;
    assert(!plan(s,all,3,selected,1));for(unsigned j=0;j<3;j++)assert(selected[j]==owners+1);
    assert(!plan(NULL,all,3,selected,3)&&!plan(s,NULL,3,selected,3)&&!plan(s,all,3,NULL,3));
    assert(!plan(s,all,A2_ACTOR_PACKET_OWNER_LIMIT+1,selected,3));
    A2MeshScene *empty=a2_mesh_scene_create(640,432,error,sizeof error);assert(empty);
    assert(!plan(empty,all,3,selected,3));a2_mesh_scene_destroy(empty);
    /* Retain material policy even if a caller supplies a modified model. */
    A2ModelMaterial saved=t02->materials[0];t02->materials[0].alpha_mode=2;assert(!plan(s,all,3,selected,3));
    t02->materials[0]=saved;t02->materials[0].opacity=.5f;assert(!plan(s,all,3,selected,3));
    t02->materials[0]=saved;t02->materials[0].kind=2;assert(!plan(s,all,3,selected,3));t02->materials[0]=saved;
    t02->source_variant=1;assert(!plan(s,all,3,selected,3));t02->source_variant=0;
    assert(plan(s,all,3,selected,3)==2);
    /* Source identity survives hidden parts; an unused stale lid pose must not
     * disable the visible body. Submit only submeshes belonging to that body. */
    for(unsigned hidden=0;hidden<2;hidden++){
        A2ActorPart saved_part=owners[0].parts[hidden];
        owners[0].parts[hidden].visible=0;owners[0].parts[hidden].valid=0;
        const A2ActorPacketOwner *one[]={owners};
        assert(plan(s,one,1,selected,3)==1&&draw(s,selected,1));
        unsigned expected=0;
        for(unsigned j=0;j<t02->submesh_count;j++)if(t02->submeshes[j].source_part!=saved_part.source_mesh_index){
            assert(recorded[expected].first_index==t02->submeshes[j].first_index);
            assert(recorded[expected].owner_tag==1);++expected;
        }
        assert(expected&&recorded_count==expected);
        owners[0].parts[hidden]=saved_part;
    }
    /* Tags are owner-array indices, not compacted draw indices: a hidden
     * leading instance leaves the next visible instance tagged 2. */
    owners[0].parts[0].visible=owners[0].parts[1].visible=0;
    const A2ActorPacketOwner *two[]={owners,owners+2};
    assert(draw(s,two,2)&&recorded_count==t02->submesh_count);
    for(unsigned i=0;i<recorded_count;i++)assert(recorded[i].owner_tag==2);
    owners[2].parts[0].visible=owners[2].parts[1].visible=0;
    assert(draw(s,two,2)&&!recorded_count);
    owners[0].parts[0].visible=owners[0].parts[1].visible=1;
    owners[2].parts[0].visible=owners[2].parts[1].visible=1;
    uint32_t source_part=t02->submeshes[0].source_part;
    t02->submeshes[0].source_part=UINT32_MAX;
    unsigned prior=submissions;assert(!draw(s,two,2)&&submissions==prior);
    t02->submeshes[0].source_part=source_part;
    a2_mesh_scene_destroy(s);a2_native_model_destroy(t02);a2_native_model_destroy(t03);
    puts("mesh plan: decoded mixed resources, distinct instances, stable selection and strict pose/camera/material guards pass");return 0;
}
