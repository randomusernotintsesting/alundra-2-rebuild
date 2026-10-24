#include "native_flint.h"
#include <float.h>
#include <math.h>
#include <string.h>
#include "native_flint_data.h"
#include "native_flint_retarget_data.h"

typedef double Mat[4][4];
static void identity(Mat m) { memset(m,0,sizeof(Mat));for(unsigned i=0;i<4;i++)m[i][i]=1; }
static void multiply(Mat out,const Mat a,const Mat b) {
    Mat v;for(unsigned i=0;i<4;i++)for(unsigned j=0;j<4;j++) {
        v[i][j]=0;for(unsigned k=0;k<4;k++)v[i][j]+=a[i][k]*b[k][j];
    }
    memcpy(out,v,sizeof v);
}
static void point(double out[3],const Mat m,const double p[3]) {
    double v[3];for(unsigned i=0;i<3;i++)v[i]=m[i][0]*p[0]+m[i][1]*p[1]+m[i][2]*p[2]+m[i][3];
    memcpy(out,v,sizeof v);
}
static void direction(double out[3],const Mat m,const double p[3]) {
    double v[3];for(unsigned i=0;i<3;i++)v[i]=m[i][0]*p[0]+m[i][1]*p[1]+m[i][2]*p[2];
    memcpy(out,v,sizeof v);
}
static double dot(const double a[3],const double b[3]) {return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];}
static void cross(double out[3],const double a[3],const double b[3]) {
    double v[3]={a[1]*b[2]-a[2]*b[1],a[2]*b[0]-a[0]*b[2],a[0]*b[1]-a[1]*b[0]};memcpy(out,v,sizeof v);
}
static int normalize(double v[3]) {
    double n=sqrt(dot(v,v));if(!isfinite(n)||n<1e-12)return 0;
    for(unsigned i=0;i<3;i++)v[i]/=n;return 1;
}
static int quaternion_matrix(Mat out,double q[4]) {
    double n=0;for(unsigned i=0;i<4;i++)n+=q[i]*q[i];n=sqrt(n);
    if(!isfinite(n)||n<1e-12)return 0;for(unsigned i=0;i<4;i++)q[i]/=n;
    double w=q[0],x=q[1],y=q[2],z=q[3];identity(out);
    out[0][0]=1-2*(y*y+z*z);out[0][1]=2*(x*y-z*w);out[0][2]=2*(x*z+y*w);
    out[1][0]=2*(x*y+z*w);out[1][1]=1-2*(x*x+z*z);out[1][2]=2*(y*z-x*w);
    out[2][0]=2*(x*z-y*w);out[2][1]=2*(y*z+x*w);out[2][2]=1-2*(x*x+y*y);return 1;
}
/* Equivalent rotation extraction to Matrix.to_quaternion(): remove column
 * scale, extract and normalize a quaternion. Native D itself stays full affine. */
static int rotation(Mat out,const Mat in) {
    Mat m;memcpy(m,in,sizeof m);
    for(unsigned c=0;c<3;c++) {
        double v[3]={m[0][c],m[1][c],m[2][c]};if(!normalize(v))return 0;
        for(unsigned r=0;r<3;r++)m[r][c]=v[r];
    }
    double determinant=m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1])-
        m[0][1]*(m[1][0]*m[2][2]-m[1][2]*m[2][0])+m[0][2]*(m[1][0]*m[2][1]-m[1][1]*m[2][0]);
    if(fabs(determinant)<1e-12)return 0;
    if(determinant<0)for(unsigned r=0;r<3;r++)for(unsigned c=0;c<3;c++)m[r][c]=-m[r][c];
    double q[4],trace=m[0][0]+m[1][1]+m[2][2];
    if(trace>0) {
        double s=2*sqrt(trace+1);q[0]=s/4;q[1]=(m[2][1]-m[1][2])/s;
        q[2]=(m[0][2]-m[2][0])/s;q[3]=(m[1][0]-m[0][1])/s;
    } else {
        unsigned i=0;if(m[1][1]>m[i][i])i=1;if(m[2][2]>m[i][i])i=2;
        unsigned j=(i+1)%3,k=(i+2)%3;double s=2*sqrt(fmax(0,1+m[i][i]-m[j][j]-m[k][k]));
        if(s<1e-12)return 0;q[0]=(m[k][j]-m[j][k])/s;q[i+1]=s/4;
        q[j+1]=(m[j][i]+m[i][j])/s;q[k+1]=(m[k][i]+m[i][k])/s;
    }
    return quaternion_matrix(out,q);
}
static int mount(Mat out,const Mat native[19]) {
    Mat base,swing,r;double axis[3],target[3],elbow[3],wrist[3],from[3],v[3];
    if(!rotation(base,native[6]))return 0;
    point(elbow,native[6],flint_elbow);point(wrist,native[7],flint_wrist);
    for(unsigned i=0;i<3;i++){axis[i]=flint_wrist[i]-flint_elbow[i];target[i]=wrist[i]-elbow[i];}
    if(!normalize(axis)||!normalize(target))return 0;direction(from,base,axis);if(!normalize(from))return 0;
    cross(v,from,target);double q[4]={1+dot(from,target),v[0],v[1],v[2]};
    if(sqrt(dot(v,v))<=FLT_EPSILON) {
        /* Match mathutils rotation_difference's collinear policy, including
         * its dominant-axis perpendicular at the ambiguous 180-degree turn. */
        if(dot(from,target)>0){q[0]=1;q[1]=q[2]=q[3]=0;}
        else {
            unsigned k=0;if(fabs(from[1])>fabs(from[k]))k=1;if(fabs(from[2])>fabs(from[k]))k=2;
            for(unsigned i=0;i<3;i++)v[i]=i==k?-from[(k+1)%3]-from[(k+2)%3]:from[k];
            if(!normalize(v))return 0;q[0]=0;for(unsigned i=0;i<3;i++)q[i+1]=v[i];
        }
    }
    if(!quaternion_matrix(swing,q))return 0;multiply(r,swing,base);
    direction(v,r,flint_wrist);for(unsigned i=0;i<3;i++)r[i][3]=wrist[i]-v[i];
    memcpy(out,r,sizeof r);return 1;
}
static int foot(Mat out,const Mat native[19],const FlintFoot *f) {
    Mat pelvis,basis,r;double heading[3],toe[3],ankle[3],forward[3],right[3],normal[3],v[3];
    static const double down[3]={0,-1,0},up[3]={0,0,1};
    if(!rotation(pelvis,native[3]))return 0;direction(heading,pelvis,down);heading[2]=0;
    if(!normalize(heading))return 0;double x=heading[0],y=heading[1];
    heading[0]=cos(f->toe_out)*x-sin(f->toe_out)*y;heading[1]=sin(f->toe_out)*x+cos(f->toe_out)*y;
    direction(toe,native[f->source],f->forward);point(ankle,native[f->shin],f->ankle);
    double pitch=atan2(toe[2],fmax(.1,dot(toe,heading)));
    double swing=fmax(0,fmin(1,(ankle[2]-f->low_ankle-.018)/.075));swing=swing*swing*(3-2*swing);
    pitch=fmax(-0.3490658503988659,fmin(0.4363323129985824,pitch))*swing;
    for(unsigned i=0;i<3;i++)forward[i]=heading[i]*cos(pitch)+up[i]*sin(pitch);
    cross(right,heading,up);if(!normalize(right))return 0;cross(normal,right,forward);if(!normalize(normal))return 0;
    identity(r);identity(basis);
    for(unsigned i=0;i<3;i++) {
        r[i][0]=right[i];r[i][1]=forward[i];r[i][2]=normal[i];
        for(unsigned j=0;j<3;j++)basis[i][j]=f->basis[j][i];
    }
    multiply(r,r,basis);direction(v,r,f->ankle);for(unsigned i=0;i<3;i++)r[i][3]=ankle[i]-v[i];
    double low=INFINITY;for(size_t i=0;i<f->sole_count;i++){point(v,r,f->sole[i]);low=fmin(low,v[2]);}
    r[2][3]+=fmax(0,f->clearance-low);memcpy(out,r,sizeof r);return 1;
}
static const FlintPhase *phase(const A2ActorInstance *a) {
    if(a->source_family!=A2_ACTOR_GAME00||!a->animation_clock_known)return NULL;
    for(size_t i=0;i<sizeof flint_phases/sizeof flint_phases[0];i++) {
        const FlintPhase *p=&flint_phases[i];
        if(a->animation_selector==p->selector&&a->clip_frame==p->frame&&a->clip_length==p->length&&
           a->animation_flags==p->flags&&a->action_id==p->action)return p;
    }
    return NULL;
}
static void floor_delta(double out[3],const FlintPhase *p) {
    memset(out,0,3*sizeof *out);if(!p)return;
    const FlintFloorTrack *t=&flint_floor_tracks[p->track];size_t lo=0,hi=t->count-1;
    while(hi-lo>1){size_t m=lo+(hi-lo)/2;if(t->keys[m].time<=p->time)lo=m;else hi=m;}
    double a=fmax(0,fmin(1,(p->time-t->keys[lo].time)/(t->keys[hi].time-t->keys[lo].time)));
    for(unsigned i=0;i<3;i++)out[i]=t->keys[lo].delta[i]+a*(t->keys[hi].delta[i]-t->keys[lo].delta[i]);
}
int a2_flint_model_supported(const A2NativeModel *m) {
    if(!m||strncmp(m->source_key,"PC00",32)||m->source_variant||memcmp(m->source_sha256,flint_source_sha,32)||
       m->joint_count!=19||!m->joints||m->submesh_count!=50||!m->submeshes||m->vertex_count!=8766||m->index_count!=35850)return 0;
    for(unsigned i=0;i<19;i++)if(m->joints[i].source_id!=i||m->joints[i].parent!=UINT32_MAX||m->joints[i].flags!=1||
        memcmp(m->joints[i].bind,flint_bind[i],sizeof flint_bind[i])||
        memcmp(m->joints[i].inverse_bind,flint_inverse_bind[i],sizeof flint_inverse_bind[i]))return 0;
    return 1;
}
static int owner_parts(const A2ActorPacketOwner *o,const A2ActorPart *parts[16],uint32_t *visible) {
    if(!o||o->instance.source_family!=A2_ACTOR_GAME00||!o->instance.valid||!o->instance.generation_known||o->instance.part_count!=16)return 0;
    memset(parts,0,16*sizeof *parts);*visible=0;
    for(unsigned i=0;i<16;i++) {
        const A2ActorPart *p=&o->parts[i];unsigned j=p->source_mesh_index;
        if(j>=16||parts[j]||strncmp(p->source_key,"PC00",32)||memcmp(p->source_sha256,flint_source_sha,32))return 0;
        parts[j]=p;if(p->visible){if(!p->valid||p->fallback||p->vertex_override_address)return 0;*visible|=1u<<j;}
    }
    return 1;
}
/* FRITTO remains its original source identity. Coordinates are calibrated
 * from paired source geometry; no native rest/parent hierarchy is asserted. */
static const FlintRetarget *event_parts(const A2ActorPacketOwner *o,const A2ActorPart *parts[16],uint32_t *visible) {
    if(!o||o->instance.source_family!=A2_ACTOR_EVENT00||!o->instance.valid||
       !o->instance.generation_known||!o->instance.part_count||o->instance.part_count>A2_ACTOR_PACKET_PART_LIMIT)return NULL;
    const FlintRetarget *set=NULL;
    for(size_t i=0;i<sizeof flint_event_sources/sizeof flint_event_sources[0];i++)
        if(!memcmp(o->parts[0].source_sha256,flint_event_sources[i].sha,32)){set=&flint_event_sources[i];break;}
    if(!set||o->instance.part_count!=set->parts)return NULL;
    const A2ActorPart *source[A2_ACTOR_PACKET_PART_LIMIT]={0};
    memset(parts,0,16*sizeof *parts);*visible=0;
    for(unsigned i=0;i<o->instance.part_count;i++) {
        const A2ActorPart *p=&o->parts[i];unsigned j=p->source_mesh_index;
        if(j>=set->parts||source[j]||strncmp(p->source_key,"FRITTO",A2_ACTOR_SOURCE_KEY_SIZE)||
           memcmp(p->source_sha256,set->sha,32))return NULL;
        /* Extras are not consumed by this adapter; their original packets stay
         * native. Only mapped, visible parts must have a usable rigid record. */
        source[j]=p;
    }
    for(unsigned i=0;i<16;i++) {
        unsigned j=flint_event_parts[set->mapping][i];if(j>=set->parts)continue;
        const A2ActorPart *p=source[j];if(!p)return NULL;parts[i]=p;
        if(p->visible){if(!p->valid||p->fallback||p->vertex_override_address)return NULL;*visible|=1u<<i;}
    }
    return set;
}
int a2_flint_owner_supported(const A2ActorPacketOwner *o,const A2NativeModel *m) {
    const A2ActorPart *parts[16];uint32_t visible;
    if(!a2_flint_model_supported(m))return 0;
    return o&&o->instance.source_family==A2_ACTOR_EVENT00?event_parts(o,parts,&visible)!=NULL:owner_parts(o,parts,&visible);
}
int a2_flint_source_part_replaced(const A2ActorPacketOwner *o,unsigned source_part) {
    const A2ActorPart *parts[16];uint32_t visible;
    if(!o)return 0;
    if(o->instance.source_family==A2_ACTOR_EVENT00) {
        const FlintRetarget *set=event_parts(o,parts,&visible);if(!set||source_part>=set->parts)return 0;
        for(unsigned i=0;i<16;i++)if(flint_event_parts[set->mapping][i]==source_part)return 1;
        return 0;
    }
    return source_part<16&&owner_parts(o,parts,&visible);
}
static uint32_t dependencies(unsigned driver,int walk) {
    if(driver<16)return 1u<<driver;
    if(driver==16)return (1u<<6)|(1u<<7);
    if(driver==17)return (1u<<10)|(walk?((1u<<3)|(1u<<9)):0);
    return (1u<<13)|(walk?((1u<<3)|(1u<<12)):0);
}
int a2_flint_submesh_visible(const A2ActorPacketOwner *o,const A2NativeModel *m,unsigned submesh) {
    const A2ActorPart *parts[16];uint32_t visible;
    if(!a2_flint_model_supported(m)||submesh>=50||!o)return -1;
    if(o->instance.source_family==A2_ACTOR_EVENT00) {if(!event_parts(o,parts,&visible))return -1;}
    else if(!owner_parts(o,parts,&visible))return -1;
    const FlintPhase *p=phase(&o->instance);int walk=p&&p->track==1;
    uint32_t needed=flint_submesh_visibility[submesh],drivers=flint_submesh_drivers[submesh];
    for(unsigned j=0;j<19;j++)if(drivers&(1u<<j))needed|=dependencies(j,walk);
    return (needed&visible)==needed;
}
static int gameplay_pose(const A2ActorPacketOwner *o,const A2NativeModel *m,A2MeshMat4 *actor,A2MeshMat4 *skin,size_t capacity) {
    const A2ActorPart *parts[16];uint32_t visible;
    if(!actor||!skin||capacity<19||!a2_flint_model_supported(m)||!owner_parts(o,parts,&visible))return 0;
    const FlintPhase *p=phase(&o->instance);int walk=p&&p->track==1;
    Mat native[19],delta[19];
    for(unsigned i=0;i<19;i++){identity(native[i]);identity(delta[i]);}
    for(unsigned i=0;i<16;i++) {
        if(!(visible&(1u<<i)))continue;Mat pose,inverse;identity(pose);
        memcpy(inverse,flint_source_inverse[i],sizeof inverse);const A2ActorPart *part=parts[i];
        for(unsigned r=0;r<3;r++) {
            pose[r][3]=(double)part->translation0[r]+part->translation1[r]-(double)o->instance.renderer_root_q12[r]/4096;
            for(unsigned c=0;c<3;c++) {
                pose[r][c]=(double)part->matrix_q12[r*3+c]/4096;
                pose[r][3]+=pose[r][c]*part->pretranslation[c];
            }
        }
        multiply(delta[i],pose,inverse);multiply(native[i],flint_h,delta[i]);multiply(native[i],native[i],flint_h_inverse);
    }
    for(unsigned i=16;i<19;i++) {
        uint32_t needed=dependencies(i,walk);if((needed&visible)!=needed)continue;
        if(i==16) {if(!mount(native[i],native))return 0;}
        else if(walk) {if(!foot(native[i],native,&flint_feet[i-17]))return 0;}
        else {memcpy(delta[i],delta[i==17?10:13],sizeof(Mat));continue;}
        multiply(delta[i],flint_h_inverse,native[i]);multiply(delta[i],delta[i],flint_h);
    }
    A2MeshMat4 result[19],a;memset(&a,0,sizeof a);for(unsigned i=0;i<4;i++)a.m[i*5]=1;
    double correction[3];floor_delta(correction,p);
    for(unsigned r=0;r<3;r++)a.m[r*4+3]=(float)((double)o->instance.renderer_root_q12[r]/4096+correction[r]);
    for(unsigned i=0;i<19;i++)for(unsigned r=0;r<4;r++)for(unsigned c=0;c<4;c++) {
        float x=(float)delta[i][r][c];if(!isfinite(x))return 0;result[i].m[r*4+c]=x;
    }
    *actor=a;memcpy(skin,result,sizeof result);return 1;
}

static int event_pose(const A2ActorPacketOwner *o,const A2NativeModel *m,A2MeshMat4 *actor,A2MeshMat4 *skin,size_t capacity) {
    const A2ActorPart *parts[16];uint32_t visible;
    if(!actor||!skin||capacity<19||!a2_flint_model_supported(m))return 0;
    const FlintRetarget *set=event_parts(o,parts,&visible);if(!set)return 0;
    Mat native[19],delta[19];
    for(unsigned i=0;i<19;i++){identity(native[i]);identity(delta[i]);}
    for(unsigned i=0;i<16;i++) {
        if(!(visible&(1u<<i)))continue;
        Mat pose,converted,inverse,canonical;identity(pose);const A2ActorPart *p=parts[i];
        for(unsigned r=0;r<3;r++) {
            pose[r][3]=(double)p->translation0[r]+p->translation1[r]-(double)o->instance.renderer_root_q12[r]/4096;
            for(unsigned c=0;c<3;c++) {
                pose[r][c]=(double)p->matrix_q12[r*3+c]/4096;
                pose[r][3]+=pose[r][c]*p->pretranslation[c];
            }
        }
        multiply(converted,pose,flint_event_conversion[set->calibration][i]);
        memcpy(inverse,flint_source_inverse[i],sizeof inverse);multiply(delta[i],converted,inverse);
        /* Authored helper coordinates use gameplay units. Remove only the
         * measured common uniform source scale before evaluating the helper;
         * restore it to the complete resulting affine transform below. */
        memcpy(canonical,delta[i],sizeof canonical);
        for(unsigned r=0;r<3;r++)for(unsigned c=0;c<4;c++)canonical[r][c]/=set->scale;
        multiply(native[i],flint_h,canonical);multiply(native[i],native[i],flint_h_inverse);
    }
    if((visible&((1u<<6)|(1u<<7)))==((1u<<6)|(1u<<7))) {
        if(!mount(native[16],native))return 0;
        multiply(delta[16],flint_h_inverse,native[16]);multiply(delta[16],delta[16],flint_h);
        for(unsigned r=0;r<3;r++)for(unsigned c=0;c<4;c++)delta[16][r][c]*=set->scale;
    }
    if(visible&(1u<<10))memcpy(delta[17],delta[10],sizeof(Mat));
    if(visible&(1u<<13))memcpy(delta[18],delta[13],sizeof(Mat));
    A2MeshMat4 result[19],a;memset(&a,0,sizeof a);for(unsigned i=0;i<4;i++)a.m[i*5]=1;
    for(unsigned r=0;r<3;r++)a.m[r*4+3]=(float)((double)o->instance.renderer_root_q12[r]/4096);
    for(unsigned i=0;i<19;i++)for(unsigned r=0;r<4;r++)for(unsigned c=0;c<4;c++) {
        float x=(float)delta[i][r][c];if(!isfinite(x))return 0;result[i].m[r*4+c]=x;
    }
    *actor=a;memcpy(skin,result,sizeof result);return 1;
}
int a2_flint_pose(const A2ActorPacketOwner *o,const A2NativeModel *m,A2MeshMat4 *actor,A2MeshMat4 *skin,size_t capacity) {
    return o&&o->instance.source_family==A2_ACTOR_EVENT00?event_pose(o,m,actor,skin,capacity):gameplay_pose(o,m,actor,skin,capacity);
}
