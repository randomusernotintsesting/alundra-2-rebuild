#include "native_mesh_scene.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
static void identity(float *m){memset(m,0,16*sizeof *m);for(int i=0;i<4;i++)m[i*5]=1;}
static void point(const A2MeshMat4 *m,const float *p,float *out){
    for(int r=0;r<4;r++)out[r]=m->m[r*4]*p[0]+m->m[r*4+1]*p[1]+m->m[r*4+2]*p[2]+m->m[r*4+3];
}
int main(void){
    A2ActorPacketOwner o={0};o.instance.valid=1;o.instance.generation_known=1;
    o.instance.part_count=2;o.instance.renderer_root_q12[0]=10*4096;
    A2ModelJoint j[2]={0};A2NativeModel m={0};m.joints=j;m.joint_count=2;
    strcpy(m.source_key,"T02");memset(m.source_sha256,42,32);
    for(int k=0;k<2;k++){
        A2ActorPart *p=&o.parts[k];p->valid=p->visible=1;p->source_mesh_index=k;
        strcpy(p->source_key,m.source_key);memcpy(p->source_sha256,m.source_sha256,32);
        p->translation0[0]=10;p->matrix_q12[0]=p->matrix_q12[4]=p->matrix_q12[8]=4096;
        j[k].source_id=k;identity(j[k].bind);identity(j[k].inverse_bind);
    }
    /* Lid rotates around x=2: P(t) * inverse(B), not P(t) twice. */
    j[1].bind[3]=2;j[1].inverse_bind[3]=-2;
    o.parts[1].translation1[0]=2;
    o.parts[1].matrix_q12[0]=0;o.parts[1].matrix_q12[1]=-4096;
    o.parts[1].matrix_q12[3]=4096;o.parts[1].matrix_q12[4]=0;
    A2MeshMat4 actor,skin[2];assert(a2_mesh_pose(&o,&m,&actor,skin,2));
    float p[3]={3,0,0},out[4];point(&skin[1],p,out);
    assert(out[0]==2&&out[1]==1&&out[2]==0&&out[3]==1);
    float world_out[4];point(&actor,out,world_out);assert(world_out[0]==12);
    o.parts[1].valid=0;assert(!a2_mesh_pose(&o,&m,&actor,skin,2));o.parts[1].valid=1;
    o.parts[1].source_sha256[0]^=1;assert(!a2_mesh_pose(&o,&m,&actor,skin,2));o.parts[1].source_sha256[0]^=1;
    for(unsigned hidden=0;hidden<2;hidden++){
        A2ActorPart saved=o.parts[hidden];A2MeshMat4 expected[2];
        assert(a2_mesh_pose(&o,&m,&actor,expected,2));
        o.parts[hidden].visible=o.parts[hidden].valid=0;
        o.parts[hidden].fallback=1;memset(o.parts[hidden].matrix_q12,0xa5,sizeof o.parts[hidden].matrix_q12);
        assert(a2_mesh_pose(&o,&m,&actor,skin,2));
        assert(!memcmp(&skin[1-hidden],&expected[1-hidden],sizeof skin[0]));
        A2MeshMat4 unused;identity(unused.m);assert(!memcmp(&skin[hidden],&unused,sizeof unused));
        o.parts[hidden].source_sha256[0]^=1;assert(!a2_mesh_pose(&o,&m,&actor,skin,2));
        o.parts[hidden]=saved;
    }
    for(int i=0;i<3;i++)o.camera_rotation_q12[i*4]=4096;
    o.projection_h=100;o.projection_ofx=160*65536;o.projection_ofy=108*65536;
    o.camera_origin_q12[0]=5*4096+2048;
    A2MeshMat4 camera;assert(a2_mesh_camera(&o,320,216,4,1,&camera));
    float world[3]={25.5f,30,100};point(&camera,world,out);
    /* GTE x=160+100*.75*20/100, y=108+100*30/100.
     * Half fine-pixel shift aligns Metal centers with native integer samples. */
    double x=(out[0]/out[3]+1)*640-.5,y=(1-out[1]/out[3])*432-.5;
    assert(fabs(x-700)<.0001&&fabs(y-552)<.0001);
    assert(out[2]>0&&out[2]<out[3]);
    memset(o.camera_rotation_q12,0,sizeof o.camera_rotation_q12);
    o.camera_rotation_q12[2]=4096;o.camera_rotation_q12[4]=4096;o.camera_rotation_q12[6]=-4096;
    o.camera_origin_q12[1]=7*4096+1024;o.camera_origin_q12[2]=9*4096+3072;
    o.projection_ofx=147*65536;o.projection_ofy=102*65536;
    float rotated_world[3]={-194.5f,47.25f,69.75f}; /* camera XYZ=(60,40,200) */
    for(unsigned scale=1;scale<=4;scale++)for(int wide=0;wide<=1;wide++){
        assert(a2_mesh_camera(&o,320,216,scale,wide,&camera));point(&camera,rotated_world,out);
        x=(out[0]/out[3]+1)*160*scale-.5;y=(1-out[1]/out[3])*108*scale-.5;
        assert(fabs(x-(147+(wide?22.5:30))*scale)<.0002&&fabs(y-122*scale)<.0002);
        assert(fabs(out[2]/out[3]-(65536./65535.-(65536./65535.)/200))<1e-6);
    }
    o.projection_h=0;assert(!a2_mesh_camera(&o,320,216,4,1,&camera));
    puts("native mesh pose: hinge inverse bind, actor once, fractional camera and wide projection passed");
}
