#include "native_mesh_scene.h"
#include "native_flint.h"
#include "native_mesh_material.h"
#include <stdlib.h>
#include <string.h>

#define SCENE_MODELS 3u
typedef struct {
    const A2NativeModel *model;
    A2MeshHandle mesh,textures[64];
} SceneModel;
struct A2MeshScene {
    A2MeshBackend *backend;
    unsigned width,height;
    SceneModel models[SCENE_MODELS];
    A2MeshMat4 skin[A2_ACTOR_PACKET_OWNER_LIMIT][A2_MESH_MAX_JOINTS];
    A2MeshDraw draws[A2_MESH_MAX_DRAWS];
};
A2MeshScene *a2_mesh_scene_create(unsigned width,unsigned height,char *error,size_t error_size){
    A2MeshScene *s=calloc(1,sizeof *s);if(!s)return NULL;
    s->backend=a2_mesh_backend_create(width,height,error,error_size);
    if(!s->backend){free(s);return NULL;}s->width=width;s->height=height;return s;
}
void a2_mesh_scene_destroy(A2MeshScene *s){if(s){a2_mesh_backend_destroy(s->backend);free(s);}}
int a2_mesh_scene_add(A2MeshScene *s,const A2NativeModel *m){
    if(!s||!m||m->texture_count>64||m->source_variant)return 0;
    int flint=!strcmp(m->source_key,"PC00");
    if(flint?m->joint_count!=19:(m->joint_count!=2||
       (strcmp(m->source_key,"T02")&&strcmp(m->source_key,"T03"))))return 0;
    if(flint&&!a2_flint_model_supported(m))return 0;
    SceneModel *entry=NULL;
    for(unsigned i=0;i<SCENE_MODELS;i++){
        if(s->models[i].model&&!strcmp(s->models[i].model->source_key,m->source_key))return 0;
        if(!s->models[i].model&&!entry)entry=&s->models[i];
    }
    if(!entry)return 0;
    A2MeshVertex *vertices=calloc(m->vertex_count,sizeof *vertices);if(!vertices)return 0;
    for(uint32_t i=0;i<m->vertex_count;i++){
        const A2ModelVertex *v=&m->vertices[i];A2MeshVertex *d=&vertices[i];
        memcpy(d->position,v->position,sizeof d->position);memcpy(d->normal,v->normal,sizeof d->normal);
        memcpy(d->uv,v->uv[0],sizeof d->uv);memcpy(d->uv1,v->uv[1],sizeof d->uv1);
        memcpy(d->color,v->color[0],sizeof d->color);memcpy(d->color1,v->color[1],sizeof d->color1);
        memcpy(d->joints,v->joints,sizeof d->joints);memcpy(d->weights,v->weights,sizeof d->weights);
    }
    entry->mesh=a2_mesh_create(s->backend,vertices,m->vertex_count,m->indices,m->index_count,(A2MeshIndexType)m->index_width);
    free(vertices);if(!entry->mesh)return 0;
    for(uint32_t i=0;i<m->texture_count;i++){
        const A2ModelTexture *t=&m->textures[i];
        entry->textures[i]=a2_mesh_texture_create(s->backend,t->width,t->height,t->rgba,(size_t)t->width*4);
        if(!entry->textures[i]){
            for(uint32_t j=0;j<i;j++)a2_mesh_texture_destroy(s->backend,entry->textures[j]);
            a2_mesh_destroy(s->backend,entry->mesh);memset(entry,0,sizeof *entry);return 0;
        }
    }
    entry->model=m;return 1;
}
static const SceneModel *supported_model(const A2MeshScene *s,const A2ActorPacketOwner *o){
    if(!s||!o||!o->instance.part_count||o->instance.part_count>A2_ACTOR_PACKET_PART_LIMIT||
       !o->parts[0].source_generation)return NULL;
    for(unsigned j=1;j<o->instance.part_count;j++)
        if(o->parts[j].source_generation!=o->parts[0].source_generation)return NULL;
    for(unsigned i=0;i<SCENE_MODELS;i++){
        const SceneModel *entry=&s->models[i];const A2NativeModel *m=entry->model;
        if(!m||m->source_variant||!m->joints||!m->submesh_count||
           !m->submeshes||!m->materials)continue;
        if(!strcmp(m->source_key,"PC00")){
            if(!a2_flint_owner_supported(o,m))continue;
        }else{
        if(strncmp(m->source_key,o->parts[0].source_key,32))continue;
        unsigned native_parts=!strcmp(m->source_key,"PC00")?16:2;
        if(o->instance.part_count!=native_parts||m->joint_count!=(native_parts==16?19:2))continue;
        unsigned matches=0;
        uint32_t seen=0;
        for(unsigned j=0;j<native_parts;j++){
            const A2ActorPart *p=&o->parts[j];
            if(strncmp(p->source_key,m->source_key,32)||memcmp(p->source_sha256,m->source_sha256,32)||
               p->source_generation!=o->parts[0].source_generation||p->source_mesh_index>=native_parts||
               (seen&(1u<<p->source_mesh_index)))break;
            seen|=1u<<p->source_mesh_index;
            unsigned joints=0;
            for(unsigned k=0;k<native_parts;k++)joints+=p->source_mesh_index==m->joints[k].source_id;
            if(joints!=1)break;
            ++matches;
        }
        if(matches!=native_parts)continue;
        }
        uint32_t j=0;
        for(;j<m->submesh_count;j++){
            const A2ModelSubmesh *sub=&m->submeshes[j];
            if(sub->material>=m->material_count)break;
            A2MeshMaterial material;
            A2MeshHandle texture=m->materials[sub->material].texture[0]==UINT32_MAX?0:1;
            if(!a2_mesh_material(m,sub->material,texture,&material))break;
        }
        if(j==m->submesh_count)return entry;
    }
    return NULL;
}
size_t a2_mesh_scene_plan(const A2MeshScene *s,const A2ActorPacketOwner *const *owners,size_t count,
                          const A2ActorPacketOwner **selected,size_t capacity){
    if(!s||!owners||!selected||count>A2_ACTOR_PACKET_OWNER_LIMIT)return 0;
    const A2ActorPacketOwner *plan[A2_ACTOR_PACKET_OWNER_LIMIT];size_t used=0;
    for(size_t i=0;i<count;i++)if(supported_model(s,owners[i])){
        if(used==capacity)return 0;
        plan[used++]=owners[i];
    }
    if(used)memcpy(selected,plan,used*sizeof *selected);
    return used;
}
int a2_mesh_scene_draw(A2MeshScene *s,const A2ActorPacketOwner *const *owners,size_t count,
                       unsigned scale,int wide,uint8_t *rgba,size_t rgba_size,float *depth,size_t depth_size){
    if(!s||!owners||!count||count>A2_ACTOR_PACKET_OWNER_LIMIT||scale<1||scale>4||
       s->width!=320*scale||s->height!=216*scale||!rgba||!depth||
       rgba_size<(size_t)s->width*s->height*4||depth_size<(size_t)s->width*s->height*sizeof(float))return 0;
    A2MeshFrame frame={0};frame.clear_depth=1;frame.encode_srgb=1;
    if(!a2_mesh_camera(owners[0],320,216,scale,wide,&frame.view_projection))return 0;
    for(unsigned r=0;r<3;r++)frame.camera_world[r]=(float)((double)owners[0]->camera_origin_q12[r]/4096);
    size_t draws=0;
    for(size_t i=0;i<count;i++){
        const A2ActorPacketOwner *o=owners[i];A2MeshMat4 camera,actor;
        if(!a2_mesh_camera(o,320,216,scale,wide,&camera)||memcmp(&camera,&frame.view_projection,sizeof camera))return 0;
        const SceneModel *entry=supported_model(s,o);
        if(!entry||!a2_mesh_pose(o,entry->model,&actor,s->skin[i],A2_MESH_MAX_JOINTS))return 0;
        const A2NativeModel *m=entry->model;
        for(uint32_t j=0;j<m->submesh_count;j++){
            const A2ModelSubmesh *sub=&m->submeshes[j];const A2ModelMaterial *mat=&m->materials[sub->material];
            if(!strcmp(m->source_key,"PC00")){
                int visible=a2_flint_submesh_visible(o,m,j);
                if(visible<0)return 0;if(!visible)continue;
            }else{
                const A2ActorPart *part=NULL;
                for(unsigned k=0;k<o->instance.part_count;k++)if(o->parts[k].source_mesh_index==sub->source_part)part=&o->parts[k];
                if(!part)return 0;if(!part->visible)continue;if(!part->valid)return 0;
            }
            if(draws==A2_MESH_MAX_DRAWS)return 0;
            A2MeshDraw *d=&s->draws[draws++];memset(d,0,sizeof *d);
            d->mesh=entry->mesh;d->first_index=sub->first_index;d->index_count=sub->index_count;
            d->model=actor;d->joints=s->skin[i];d->joint_count=m->joint_count;
            A2MeshHandle texture=mat->texture[0]==UINT32_MAX?0:entry->textures[mat->texture[0]];
            if(!a2_mesh_material(m,sub->material,texture,&d->material))return 0;
            d->depth_test=d->depth_write=d->color_write=1;
            d->owner_tag=(uint32_t)i+1;
            if(!strcmp(m->source_key,"PC00"))d->native_light=o->light;
        }
    }
    if(!a2_mesh_render(s->backend,&frame,s->draws,draws))return 0;
    return a2_mesh_readback(s->backend,rgba,rgba_size,(size_t)s->width*4,depth,depth_size,(size_t)s->width*sizeof(float));
}
int a2_mesh_scene_read_owners(A2MeshScene *s,uint32_t *owners,size_t size){
    return s&&a2_mesh_readback_owners(s->backend,owners,size,(size_t)s->width*sizeof *owners);
}
