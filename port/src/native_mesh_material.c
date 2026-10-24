#include "native_mesh_material.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
/* Approved v5 PC00.runtime.json and canonical model records, binary32 exact.
 * Source SHA is original guest mesh identity, not a material-name heuristic.
 * Modern asset SHA: 01ffe01dc58612a2e3665cd69d4fa28e8e7435efbd352f6c4909067b37c1c2af.
 * No dynamic sidecar parser or implicit Principled interpretation is used. */
typedef struct {uint32_t kind,texture;float color[4],roughness,metallic,specular;} Recipe;
static const Recipe pc00[28]={
    {0,UINT32_MAX,{0x1.1eb8520000000p-4f,0x1.ba5e360000000p-6f,0x1.47ae140000000p-7f,0x1.0000000000000p+0f},0x1.75c2900000000p-1f,0x0.0p+0f,0x1.0000000000000p-1f},
    {0,UINT32_MAX,{0x1.d70a3e0000000p-2f,0x1.f5c2900000000p-2f,0x1.0f5c280000000p-1f,0x1.0000000000000p+0f},0x1.3d70a40000000p-2f,0x1.dc28f60000000p-1f,0x1.0000000000000p-1f},
    {0,UINT32_MAX,{0x1.0f5c280000000p-1f,0x1.23d70a0000000p-2f,0x1.0a3d700000000p-4f,0x1.0000000000000p+0f},0x1.5c28f60000000p-2f,0x1.570a3e0000000p-1f,0x1.0000000000000p-1f},
    {0,UINT32_MAX,{0x1.3d70a40000000p-1f,0x1.b851ec0000000p-2f,0x1.47ae140000000p-3f,0x1.0000000000000p+0f},0x1.851eb80000000p-2f,0x1.5c28f60000000p-1f,0x1.0000000000000p-1f},
    {0,UINT32_MAX,{0x1.b851ec0000000p-2f,0x1.d70a3e0000000p-2f,0x1.0000000000000p-1f,0x1.0000000000000p+0f},0x1.ae147a0000000p-2f,0x1.3d70a40000000p-1f,0x1.0000000000000p-1f},
    {0,UINT32_MAX,{0x1.23d70a0000000p-1f,0x1.3851ec0000000p-1f,0x1.4ccccc0000000p-1f,0x1.0000000000000p+0f},0x1.0000000000000p-2f,0x1.eb851e0000000p-1f,0x1.0000000000000p-1f},
    {0,UINT32_MAX,{0x1.47ae140000000p-3f,0x1.70a3d80000000p-3f,0x1.99999a0000000p-3f,0x1.0000000000000p+0f},0x1.b851ec0000000p-2f,0x1.b333340000000p-1f,0x1.0000000000000p-1f},
    {1,2,{0x1.0000000000000p+0f,0x1.0000000000000p+0f,0x1.0000000000000p+0f,0x1.0000000000000p+0f},0x1.3d70a40000000p-2f,0x1.dc28f60000000p-1f,0x1.0000000000000p-1f},
    {0,UINT32_MAX,{0x1.626e660000000p-7f,0x1.aea9dc0000000p-8f,0x1.cae29a0000000p-9f,0x1.0000000000000p+0f},0x1.c28f5c0000000p-1f,0x0.0p+0f,0x1.c28f5c0000000p-3f},
    {0,UINT32_MAX,{0x1.928ede0000000p-2f,0x1.6e52160000000p-3f,0x1.0f31ba0000000p-5f,0x1.0000000000000p+0f},0x1.5c28f60000000p-2f,0x1.5c28f60000000p-1f,0x1.c28f5c0000000p-3f},
    {0,UINT32_MAX,{0x1.0e75d20000000p-4f,0x1.7c908e0000000p-6f,0x1.d77e280000000p-8f,0x1.0000000000000p+0f},0x1.75c2900000000p-1f,0x0.0p+0f,0x1.c28f5c0000000p-3f},
    {0,UINT32_MAX,{0x1.a033fc0000000p-2f,0x1.a3a38a0000000p-3f,0x1.80bb120000000p-5f,0x1.0000000000000p+0f},0x1.47ae140000000p-2f,0x1.5c28f60000000p-1f,0x1.c28f5c0000000p-3f},
    {0,UINT32_MAX,{0x1.40ab400000000p-4f,0x1.0e75d20000000p-4f,0x1.a3a38a0000000p-3f,0x1.0000000000000p+0f},0x1.ae147a0000000p-1f,0x0.0p+0f,0x1.c28f5c0000000p-3f},
    {0,UINT32_MAX,{0x1.ecbbf00000000p-6f,0x1.bdd67c0000000p-6f,0x1.05033e0000000p-4f,0x1.0000000000000p+0f},0x1.a3d70a0000000p-1f,0x0.0p+0f,0x1.c28f5c0000000p-3f},
    {0,UINT32_MAX,{0x1.181ab80000000p-4f,0x1.413c3e0000000p-6f,0x1.206a020000000p-8f,0x1.0000000000000p+0f},0x1.7ae1480000000p-1f,0x0.0p+0f,0x1.c28f5c0000000p-3f},
    {0,UINT32_MAX,{0x1.6bcf5e0000000p-1f,0x1.181ab80000000p-4f,0x1.63123a0000000p-9f,0x1.0000000000000p+0f},0x1.a8f5c20000000p-1f,0x0.0p+0f,0x1.c28f5c0000000p-3f},
    {0,UINT32_MAX,{0x1.8918fc0000000p-1f,0x1.5245a00000000p-2f,0x1.01fb300000000p-3f,0x1.0000000000000p+0f},0x1.5c28f60000000p-1f,0x0.0p+0f,0x1.c28f5c0000000p-3f},
    {0,UINT32_MAX,{0x1.0e75d20000000p-4f,0x1.413c3e0000000p-6f,0x1.6364a40000000p-8f,0x1.0000000000000p+0f},0x1.8000000000000p-1f,0x0.0p+0f,0x1.c28f5c0000000p-3f},
    {0,UINT32_MAX,{0x1.dd3aa40000000p-3f,0x1.f164280000000p-3f,0x1.6e52160000000p-3f,0x1.0000000000000p+0f},0x1.b851ec0000000p-1f,0x0.0p+0f,0x1.c28f5c0000000p-3f},
    {1,0,{0x1.0000000000000p+0f,0x1.0000000000000p+0f,0x1.0000000000000p+0f,0x1.0000000000000p+0f},0x1.0000000000000p+0f,0x0.0p+0f,0x0.0p+0f},
    {1,1,{0x1.0000000000000p+0f,0x1.0000000000000p+0f,0x1.0000000000000p+0f,0x1.0000000000000p+0f},0x1.0000000000000p+0f,0x0.0p+0f,0x0.0p+0f},
    {0,UINT32_MAX,{0x1.0000000000000p+0f,0x1.0000000000000p+0f,0x1.0000000000000p+0f,0x1.0000000000000p+0f},0x1.0000000000000p+0f,0x0.0p+0f,0x0.0p+0f},
    {1,1,{0x1.0000000000000p+0f,0x1.0000000000000p+0f,0x1.0000000000000p+0f,0x1.0000000000000p+0f},0x1.0000000000000p+0f,0x0.0p+0f,0x0.0p+0f},
    {1,1,{0x1.0000000000000p+0f,0x1.0000000000000p+0f,0x1.0000000000000p+0f,0x1.0000000000000p+0f},0x1.0000000000000p+0f,0x0.0p+0f,0x0.0p+0f},
    {0,UINT32_MAX,{0x1.0000000000000p+0f,0x1.0000000000000p+0f,0x1.0000000000000p+0f,0x1.0000000000000p+0f},0x1.0000000000000p+0f,0x0.0p+0f,0x0.0p+0f},
    {1,1,{0x1.0000000000000p+0f,0x1.0000000000000p+0f,0x1.0000000000000p+0f,0x1.0000000000000p+0f},0x1.0000000000000p+0f,0x0.0p+0f,0x0.0p+0f},
    {0,UINT32_MAX,{0x1.b15d000000000p-5f,0x1.91a76c0000000p-6f,0x1.87f9880000000p-8f,0x1.0000000000000p+0f},0x1.6b851e0000000p-1f,0x0.0p+0f,0x1.0000000000000p-1f},
    {0,UINT32_MAX,{0x1.839a5a0000000p-4f,0x1.9091200000000p-5f,0x1.2f92ac0000000p-7f,0x1.0000000000000p+0f},0x1.570a3e0000000p-1f,0x0.0p+0f,0x1.0000000000000p-1f},
};
static const uint8_t pc00_source[32]={0xb6,0xcb,0xf3,0xc4,0xd4,0xcf,0x45,0x6f,0x49,0x21,0xdd,0xe9,0x6b,0xa7,0x69,0xd0,0x92,0x14,0x3e,0x85,0x5a,0x28,0x2c,0xa5,0xff,0x87,0x97,0x7f,0x30,0x9e,0xb7,0x20};
static int unit(float x){return isfinite(x)&&x>=0&&x<=1;}
static int qualified(const A2NativeModel *m,uint32_t index){
    if(m->source_variant||m->file_flags!=A2_MODEL_SIGNED_CORNER_RGB||m->joint_count!=19||
       m->material_count!=28||m->texture_count!=3||memcmp(m->source_sha256,pc00_source,32))return 0;
    if(!m->textures)return 0;
    for(unsigned i=0;i<3;i++)if(m->textures[i].flags!=1)return 0;
    const A2ModelMaterial *a=&m->materials[index];const Recipe *r=&pc00[index];
    char name[32]={0};snprintf(name,sizeof name,"PC00_material_%02u",index);
    return !memcmp(a->name,name,32)&&a->kind==r->kind&&a->texture[0]==r->texture&&
      a->texture[1]==UINT32_MAX&&!memcmp(a->base_color,r->color,sizeof r->color)&&
      a->roughness==r->roughness&&a->roughness_min==r->roughness&&a->roughness_max==r->roughness&&
      a->metallic==r->metallic&&a->specular==r->specular&&a->alpha_cutoff==.5f&&
      a->ior==1.5f&&a->coat==0&&a->coat_roughness==.03f&&a->flags==1;
}
int a2_mesh_material(const A2NativeModel *model,uint32_t index,A2MeshHandle texture,A2MeshMaterial *out){
    if(!model||!out||!model->materials||index>=model->material_count)return 0;
    const A2ModelMaterial *m=&model->materials[index];
    if(m->kind>1||m->alpha_mode||m->opacity!=1||m->base_color[3]!=1||
       !unit(m->roughness)||!unit(m->metallic)||!unit(m->alpha_cutoff))return 0;
    for(unsigned i=0;i<4;i++)if(!unit(m->base_color[i]))return 0;
    A2MeshMaterial d={0};memcpy(d.base_color,m->base_color,sizeof d.base_color);
    d.roughness=m->roughness;d.metallic=m->metallic;d.alpha_cutoff=m->alpha_cutoff;
    d.shader=m->kind?A2_MESH_LAYERED_ATLAS:A2_MESH_PLAIN;
    if(m->texture[0]!=UINT32_MAX){
        if(!model->textures||m->texture[0]>=model->texture_count||!texture)return 0;
        d.texture=texture;d.texture_srgb=model->textures[m->texture[0]].flags&1;
    }else if(texture)return 0;
    if(!strncmp(model->source_key,"PC00",32)){
        if(!qualified(model,index))return 0;
        if(index>=19&&index<=25)d.address=m->kind?A2_MESH_REPEAT:A2_MESH_CLAMP;
        else{
            d.shader=index==7?A2_MESH_LIT_SHIELD:A2_MESH_LIT_CONSTANT;d.specular=m->specular;
            if(index==7){d.filter=A2_MESH_LINEAR;d.address=A2_MESH_CLIP;
                d.bump_strength=.2f;d.bump_distance=.06f;d.bump_invert=1;}
        }
    }
    *out=d;return 1;
}
