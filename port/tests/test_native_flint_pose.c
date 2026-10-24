#include "native_mesh_scene.h"
#include "native_flint.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint32_t read32(FILE *f) {
    unsigned char b[4]; assert(fread(b,1,4,f)==4);
    return (uint32_t)b[0]|(uint32_t)b[1]<<8|(uint32_t)b[2]<<16|(uint32_t)b[3]<<24;
}
static A2NativeModel *load_model(const char *path) {
    FILE *f=fopen(path,"rb"); assert(f); assert(!fseek(f,0,SEEK_END));
    long n=ftell(f); assert(n>0); rewind(f); void *bytes=malloc((size_t)n); assert(bytes);
    assert(fread(bytes,1,(size_t)n,f)==(size_t)n); fclose(f);
    A2NativeModel *m=NULL; char error[256];
    if(!a2_native_model_decode(bytes,(size_t)n,&m,error,sizeof error)) {
        fprintf(stderr,"decode: %s\n",error); abort();
    }
    free(bytes); return m;
}
static int is_identity(const A2MeshMat4 *m) {
    for(unsigned i=0;i<16;i++)if(m->m[i]!=(float)(i%5==0))return 0;return 1;
}
static void checks(const A2ActorPacketOwner *source,A2NativeModel *m) {
    A2ActorPacketOwner o=*source;A2MeshMat4 actor,skin[19],a,b[19];
    assert(a2_flint_model_supported(m));assert(a2_mesh_pose(&o,m,&actor,skin,19));
    /* Camera, diagnostics and actor orientation never enter actor-space skin.
     * The native per-part matrices already contain the actor orientation. */
    memset(o.camera_origin_q12,0x34,sizeof o.camera_origin_q12);
    memset(o.camera_rotation_q12,0x61,sizeof o.camera_rotation_q12);
    memset(o.instance.actor_world_q12,0x12,sizeof o.instance.actor_world_q12);
    memset(o.instance.orientation,0x56,sizeof o.instance.orientation);
    assert(a2_mesh_pose(&o,m,&a,b,19));assert(!memcmp(&a,&actor,sizeof a)&&!memcmp(b,skin,sizeof b));
    o=*source;o.instance.renderer_root_q12[0]+=16*4096;
    for(unsigned i=0;i<16;i++)o.parts[i].translation0[0]+=16;
    assert(a2_mesh_pose(&o,m,&a,b,19));assert(!memcmp(b,skin,sizeof b));
    assert(a.m[3]==actor.m[3]+16);assert(a.m[7]==actor.m[7]&&a.m[11]==actor.m[11]);
    /* Unqualified action (including a jump still carrying selector5) must not
     * receive authored walk/ground corrections. The feet use native deltas. */
    o=*source;o.instance.action_id=0xffff;o.instance.animation_selector=5;
    assert(a2_mesh_pose(&o,m,&a,b,19));
    for(unsigned i=0;i<16;i++)assert(!memcmp(&b[i],&skin[i],sizeof b[i]));
    assert(!memcmp(&b[16],&skin[16],sizeof b[16]));
    assert(!memcmp(&b[17],&b[10],sizeof b[0])&&!memcmp(&b[18],&b[13],sizeof b[0]));
    for(unsigned r=0;r<3;r++)assert(a.m[r*4+3]==(float)((double)o.instance.renderer_root_q12[r]/4096));
    o=*source;o.instance.animation_clock_known=0;
    assert(a2_mesh_pose(&o,m,&a,b,19));assert(!memcmp(&b[17],&b[10],sizeof b[0]));
    for(unsigned hidden=0;hidden<16;hidden++) {
        o=*source;o.parts[hidden].visible=o.parts[hidden].valid=0;o.parts[hidden].fallback=~0u;
        memset(o.parts[hidden].matrix_q12,0xa5,sizeof o.parts[hidden].matrix_q12);
        memset(o.parts[hidden].translation0,0x7f,sizeof o.parts[hidden].translation0);
        assert(a2_mesh_pose(&o,m,&a,b,19));assert(is_identity(&b[hidden]));
        for(unsigned j=0;j<19;j++)for(unsigned k=0;k<16;k++)assert(isfinite(b[j].m[k]));
        if(hidden==6||hidden==7)assert(is_identity(&b[16]));
        if(hidden==14)for(unsigned sub=0;sub<50;sub++)
            assert(a2_flint_submesh_visible(&o,m,sub)==(sub<41||sub>43));
        /* Shield driver16 also moves the bare glove and left arm. Native15
         * controls equipment visibility, independently of mount pose inputs. */
        if(hidden==15)for(unsigned sub=0;sub<50;sub++)
            assert(a2_flint_submesh_visible(&o,m,sub)==!((sub>=37&&sub<=40)||sub>=44));
    }
    o=*source;
    for(unsigned sub=0;sub<50;sub++)assert(a2_flint_submesh_visible(&o,m,sub)==1);
    assert(a2_flint_submesh_visible(&o,m,50)==-1);
    /* Reject malformed sources/poses without publishing partial output. */
#define REJECT() do { a=actor;memcpy(b,skin,sizeof b);assert(!a2_mesh_pose(&o,m,&a,b,19)); \
    assert(!memcmp(&a,&actor,sizeof a)&&!memcmp(b,skin,sizeof b)); } while(0)
    o=*source;o.parts[0].source_sha256[0]^=1;REJECT();
    o=*source;o.parts[0].source_mesh_index=1;REJECT();
    o=*source;o.parts[0].valid=0;REJECT();
    o=*source;o.parts[0].fallback=A2_ACTOR_UNBOUND_SOURCE;REJECT();
    o=*source;o.parts[0].vertex_override_address=1;REJECT();
    o=*source;o.instance.valid=0;REJECT();
    o=*source;o.instance.generation_known=0;REJECT();
    o=*source;o.instance.part_count=15;REJECT();
    o=*source;memset(o.parts[6].matrix_q12,0,sizeof o.parts[6].matrix_q12);REJECT();
    o=*source;float saved=m->joints[0].inverse_bind[0];m->joints[0].inverse_bind[0]=NAN;REJECT();m->joints[0].inverse_bind[0]=saved;
    m->source_variant=1;REJECT();m->source_variant=0;
    o=*source;a=actor;memcpy(b,skin,sizeof b);assert(!a2_mesh_pose(&o,m,&a,b,18));
    assert(!memcmp(&a,&actor,sizeof a)&&!memcmp(b,skin,sizeof b));
    assert(!a2_flint_pose(NULL,m,&a,b,19)&&!a2_flint_pose(&o,NULL,&a,b,19));
    assert(!a2_flint_pose(&o,m,NULL,b,19)&&!a2_flint_pose(&o,m,&a,NULL,19));
#undef REJECT
}
int main(int argc,char **argv) {
    if(sizeof(((A2ActorPacketOwner *)0)->parts)/sizeof(A2ActorPart)<16) {
        fputs("FAIL: PC00 requires room for all 16 captured native parts\n",stderr);return 1;
    }
    assert(argc==4); A2NativeModel *m=load_model(argv[1]);
    FILE *input=fopen(argv[2],"rb"),*output=fopen(argv[3],"wb"); assert(input&&output);
    unsigned count=read32(input);
    for(unsigned sample=0;sample<count;sample++) {
        A2ActorPacketOwner owner={0}; owner.instance.valid=owner.instance.generation_known=1;
        owner.instance.part_count=16; owner.instance.animation_clock_known=1;
        for(unsigned k=0;k<3;k++)owner.instance.renderer_root_q12[k]=(int32_t)read32(input);
        owner.instance.animation_selector=read32(input);owner.instance.clip_frame=(uint16_t)read32(input);
        owner.instance.clip_length=(uint16_t)read32(input);owner.instance.animation_flags=(uint16_t)read32(input);
        owner.instance.action_id=(uint16_t)read32(input);
        for(unsigned k=0;k<16;k++) {
            A2ActorPart *p=&owner.parts[k]; p->source_mesh_index=(uint16_t)k;
            strcpy(p->source_key,m->source_key);memcpy(p->source_sha256,m->source_sha256,32);
            for(unsigned i=0;i<9;i++)p->matrix_q12[i]=(int16_t)read32(input);
            for(unsigned i=0;i<3;i++)p->pretranslation[i]=(int16_t)read32(input);
            for(unsigned i=0;i<3;i++)p->translation0[i]=(int32_t)read32(input);
            for(unsigned i=0;i<3;i++)p->translation1[i]=(int32_t)read32(input);
            p->visible=read32(input);p->valid=read32(input);p->fallback=read32(input);
        }
        A2MeshMat4 actor,skin[19];
        if(!a2_mesh_pose(&owner,m,&actor,skin,19)) {
            fprintf(stderr,"FAIL: approved PC00 sample %u must produce 19-driver pose\n",sample);
            return 1;
        }
        if(sample==0||sample==31||sample==59)checks(&owner,m);
        assert(fwrite(actor.m,sizeof(float),16,output)==16);
        for(unsigned j=0;j<19;j++)assert(fwrite(skin[j].m,sizeof(float),16,output)==16);
    }
    assert(fgetc(input)==EOF); fclose(input); assert(!fclose(output));a2_native_model_destroy(m);
    printf("native Flint: %u approved sample poses written; hidden/equipment, camera, root, unknown actions, finite and atomic rejection checks passed\n",count);return 0;
}
