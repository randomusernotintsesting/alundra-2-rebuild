#include "native_mesh_scene.h"
#include "native_flint.h"
#include <math.h>
#include <string.h>

static void identity(A2MeshMat4 *m){memset(m,0,sizeof *m);for(unsigned i=0;i<4;i++)m->m[i*5]=1;}
static int multiply(A2MeshMat4 *out,const A2MeshMat4 *a,const A2MeshMat4 *b){
    A2MeshMat4 m;
    for(unsigned r=0;r<4;r++)for(unsigned c=0;c<4;c++){
        double x=0;for(unsigned k=0;k<4;k++)x+=(double)a->m[r*4+k]*b->m[k*4+c];
        m.m[r*4+c]=(float)x;if(!isfinite(m.m[r*4+c]))return 0;
    }
    *out=m;return 1;
}
int a2_mesh_pose(const A2ActorPacketOwner *owner,const A2NativeModel *model,
                 A2MeshMat4 *actor,A2MeshMat4 *skin,size_t capacity){
    if(model&&!strncmp(model->source_key,"PC00",32))return a2_flint_pose(owner,model,actor,skin,capacity);
    if(!owner||!model||!actor||!skin||!owner->instance.valid||!owner->instance.generation_known||
       owner->instance.part_count!=2||!model->joints||model->joint_count!=2||capacity<2)return 0;
    A2MeshMat4 a,result[2];identity(&a);
    for(unsigned r=0;r<3;r++)a.m[r*4+3]=(float)((double)owner->instance.renderer_root_q12[r]/4096);
    for(unsigned j=0;j<2;j++){
        const A2ActorPart *p=NULL;
        for(unsigned k=0;k<2;k++)if(owner->parts[k].source_mesh_index==model->joints[j].source_id){
            if(p)return 0;p=&owner->parts[k];
        }
        if(!p||strncmp(p->source_key,model->source_key,32)||
           memcmp(p->source_sha256,model->source_sha256,32))return 0;
        /* Hidden parts have no pose update in the original animation pass.
         * Their submeshes are omitted by the scene, so never read stale pose
         * storage as a bone matrix. The unused GPU palette entry is identity. */
        if(!p->visible){identity(&result[j]);continue;}
        if(!p->valid||p->fallback)return 0;
        A2MeshMat4 pose,inverse;identity(&pose);memcpy(inverse.m,model->joints[j].inverse_bind,sizeof inverse.m);
        for(unsigned r=0;r<3;r++){
            double translation=(double)p->translation0[r]+p->translation1[r]-(double)owner->instance.renderer_root_q12[r]/4096;
            for(unsigned c=0;c<3;c++){
                pose.m[r*4+c]=(float)p->matrix_q12[r*3+c]/4096;
                translation+=(double)p->matrix_q12[r*3+c]*p->pretranslation[c]/4096;
            }
            pose.m[r*4+3]=(float)translation;
        }
        if(!multiply(&result[j],&pose,&inverse))return 0;
    }
    *actor=a;memcpy(skin,result,sizeof result);return 1;
}
int a2_mesh_camera(const A2ActorPacketOwner *o,unsigned width,unsigned height,
                   unsigned scale,int wide,A2MeshMat4 *out){
    if(!o||!out||width!=320||height!=216||scale<1||scale>4||o->projection_h<=0||o->projection_h>65535||
       (wide!=0&&wide!=1))return 0;
    A2MeshMat4 view,projection;identity(&view);memset(&projection,0,sizeof projection);
    for(unsigned r=0;r<3;r++){
        double t=0;
        for(unsigned c=0;c<3;c++){
            view.m[r*4+c]=(float)o->camera_rotation_q12[r*3+c]/4096;
            t-=(double)o->camera_rotation_q12[r*3+c]*o->camera_origin_q12[c]/16777216;
        }
        view.m[r*4+3]=(float)t;
    }
    /* Pixel-center adjustment is +0.5 fine pixel in screen space. */
    projection.m[0]=(float)(2.0*o->projection_h*(wide?.75:1)/width);
    projection.m[2]=(float)(2.0*o->projection_ofx/65536/width-1+1.0/(width*scale));
    projection.m[5]=(float)(-2.0*o->projection_h/height);
    projection.m[6]=(float)(1-2.0*o->projection_ofy/65536/height-1.0/(height*scale));
    const double far_plane=65536,near_plane=1;
    projection.m[10]=(float)(far_plane/(far_plane-near_plane));
    projection.m[11]=(float)(-far_plane*near_plane/(far_plane-near_plane));
    projection.m[14]=1;
    return multiply(out,&projection,&view);
}
