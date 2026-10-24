/* Actual cooked PC00 plus the existing chest scene regressions. The GPU is
 * a recording sink; independent Metal/pose tests verify those components. */
#define main chest_regression_main
#include "test_native_mesh_plan.c"
#undef main
#include "fixtures/flint_reference_parts.h"
#include "native_actor_source_layout.h"
static A2NativeModel *load_flint(const char *path){
    FILE *f=fopen(path,"rb");assert(f);assert(!fseek(f,0,SEEK_END));long n=ftell(f);assert(n>0);rewind(f);
    void *data=malloc((size_t)n);assert(data&&fread(data,1,(size_t)n,f)==(size_t)n);fclose(f);
    A2NativeModel *m=NULL;char error[256];assert(a2_native_model_decode(data,(size_t)n,&m,error,sizeof error));free(data);
    assert(!strcmp(m->source_key,"PC00")&&m->joint_count==19&&m->submesh_count==50);return m;
}
static void flint_owner(A2ActorPacketOwner *o,const A2NativeModel *m){
    memset(o,0,sizeof *o);assert(sizeof o->parts/sizeof o->parts[0]>=16);
    o->handle=500;o->guest_frame=2999;o->instance.valid=o->instance.generation_known=o->instance.selected_for_draw=1;
    o->instance.instance_generation=10;o->instance.part_count=16;o->instance.registry_address=0x80175cb4;
    o->instance.renderer_root_q12[0]=-716768;o->instance.renderer_root_q12[2]=99664;
    o->instance.animation_clock_known=1;o->instance.clip_generation=1;o->instance.clip_length=30;
    for(unsigned j=0;j<16;j++){
        const uint8_t *raw=flint_reference_parts[j];A2ActorPart *p=&o->parts[j];memcpy(p->raw,raw,80);
        p->valid=p->visible=1;p->flags=u16(raw);p->source_mesh_index=j;p->source_generation=17;
        p->registry_address=o->instance.registry_address;strcpy(p->source_key,m->source_key);memcpy(p->source_sha256,m->source_sha256,32);
        for(unsigned r=0;r<3;r++){p->translation0[r]=(int32_t)u32(raw+8+4*r);p->translation1[r]=(int32_t)u32(raw+20+4*r);p->pretranslation[r]=(int16_t)u16(raw+52+2*r);}
        for(unsigned r=0;r<9;r++)p->matrix_q12[r]=(int16_t)u16(raw+32+2*r);
    }
    for(unsigned j=0;j<3;j++)o->camera_rotation_q12[j*4]=4096;
    o->projection_h=96;o->projection_ofx=160<<16;o->projection_ofy=108<<16;
}
int main(int argc,char **argv){
    assert(argc==4);assert(!chest_regression_main(3,argv));
    A2NativeModel *t02=load(argv[1],"T02"),*pc00=load_flint(argv[3]);char error[128];
    A2MeshScene *s=a2_mesh_scene_create(640,432,error,sizeof error);assert(s);
    assert(a2_mesh_scene_add(s,t02));assert(a2_mesh_scene_add(s,pc00));
    A2ActorPacketOwner actors[2];owner(actors,t02,0,2);flint_owner(actors+1,pc00);
    actors[1].light.known=1;actors[1].light.projection_h=96;
    actors[1].light.background[0]=2048;actors[1].light.background[1]=4096;
    const A2ActorPacketOwner *in[]={actors,actors+1},*chosen[2]={0};
    assert(plan(s,in,2,chosen,2)==2);assert(draw(s,chosen,2));
    assert(recorded_count==t02->submesh_count+pc00->submesh_count);
    for(unsigned j=0;j<recorded_count;j++)assert(recorded[j].joint_count==(j<t02->submesh_count?2:19));
    for(unsigned j=0;j<t02->submesh_count;j++)assert(!recorded[j].native_light.known);
    for(unsigned j=t02->submesh_count;j<recorded_count;j++){
        assert(recorded[j].owner_tag==2);
        assert(!memcmp(&recorded[j].native_light,&actors[1].light,sizeof actors[1].light));
    }
    /* Hidden equipment must omit its influenced geometry, never show an
     * identity-skinned replacement or silently revive its original mesh. */
    actors[1].parts[14].visible=actors[1].parts[14].valid=0;
    assert(plan(s,in,2,chosen,2)==2&&draw(s,chosen,2));
    assert(recorded_count<t02->submesh_count+pc00->submesh_count&&recorded_count>t02->submesh_count);
    actors[1].parts[14].visible=actors[1].parts[14].valid=1;
    actors[1].parts[7].source_generation=18;assert(plan(s,in,2,chosen,2)==1);actors[1].parts[7].source_generation=17;
    actors[1].parts[7].source_sha256[0]^=1;assert(plan(s,in,2,chosen,2)==1);actors[1].parts[7].source_sha256[0]^=1;
    actors[1].parts[7].source_mesh_index=6;assert(plan(s,in,2,chosen,2)==1);actors[1].parts[7].source_mesh_index=7;
    assert(plan(s,in,2,chosen,2)==2);
    for(unsigned j=0;j<16;j++)actors[1].parts[j].valid=actors[1].parts[j].visible=0;
    assert(plan(s,in,2,chosen,2)==2&&draw(s,chosen,2)&&recorded_count==t02->submesh_count);
    /* Same modern resource serves explicitly calibrated cinematic identity;
     * retain the original key/hash and sparse source order in the owner. */
    flint_owner(actors+1,pc00);A2ActorPart original[16];memcpy(original,actors[1].parts,sizeof original);
    const unsigned mapping[16]={8,9,6,7,11,10,14,12,1,2,0,4,5,3,15,13};
    const A2ActorSourceLayout *event=NULL;
    const uint8_t event_hash[32]={0xda,0x63,0x5e,0x4f,0x05,0xdd,0xf4,0x72,0xef,0xf0,0xe1,0x7b,0x83,0x54,0x42,0x2c,0xf1,0x72,0xc2,0x21,0x04,0xc4,0x02,0xa1,0x23,0x03,0x55,0x52,0x57,0xa9,0xdf,0xb5};
    unsigned event_index=a2_actor_source_find("FRITTO",event_hash);
    if(event_index<A2_ACTOR_SOURCE_COUNT)event=&a2_actor_source_layouts[event_index];
    assert(event&&event->parts==16);actors[1].instance.source_family=A2_ACTOR_EVENT00;
    for(unsigned j=0;j<16;j++){
        A2ActorPart *p=&actors[1].parts[mapping[j]];*p=original[j];p->source_mesh_index=mapping[j];
        strcpy(p->source_key,"FRITTO");memcpy(p->source_sha256,event->hash,32);
    }
    actors[1].light.known=1;actors[1].light.projection_h=96;
    assert(plan(s,in,2,chosen,2)==2&&draw(s,chosen,2));
    assert(recorded_count==t02->submesh_count+pc00->submesh_count);
    for(unsigned j=t02->submesh_count;j<recorded_count;j++)assert(recorded[j].native_light.known==1);
    actors[1].parts[7].source_generation++;assert(plan(s,in,2,chosen,2)==1);actors[1].parts[7].source_generation--;
    actors[1].parts[7].source_sha256[1]^=1;assert(plan(s,in,2,chosen,2)==1);
    a2_mesh_scene_destroy(s);a2_native_model_destroy(t02);a2_native_model_destroy(pc00);
    puts("PC00 scene: mixed hero/chest, 19 joints, hidden equipment and strict resource ownership pass");return 0;
}
