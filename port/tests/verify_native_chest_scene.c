/* Explicit offline pose diagnostic. Studio camera and diagnostic ownership only.
 * This does NOT establish runtime packet binding, occlusion, or gameplay camera. */
#include "native_mesh_scene.h"
#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "retained_parts.inc"

static unsigned u16(const unsigned char *p){return p[0]|(unsigned)p[1]<<8;}
static uint32_t u32(const unsigned char *p){return u16(p)|(uint32_t)u16(p+2)<<16;}
static void *read_file(const char *path,size_t *size){
    FILE *f=fopen(path,"rb");assert(f);assert(!fseek(f,0,SEEK_END));long n=ftell(f);assert(n>0&&n<=128*1024*1024);rewind(f);
    void *p=malloc((size_t)n);assert(p&&fread(p,1,(size_t)n,f)==(size_t)n);assert(!fclose(f));*size=(size_t)n;return p;
}
static void normalized(double *v){double n=sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);assert(n>1e-10);for(int i=0;i<3;i++)v[i]/=n;}
static void cross(const double *a,const double *b,double *c){c[0]=a[1]*b[2]-a[2]*b[1];c[1]=a[2]*b[0]-a[0]*b[2];c[2]=a[0]*b[1]-a[1]*b[0];}
static void studio_camera(A2ActorPacketOwner *o){
    /* Native world Y points down. Eye=(155,-105,65) and target=(0,-35,0),
     * relative to the actual actor root. These are explicit studio choices. */
    const double eye[]={155,-105,65},target[]={0,-35,0},up[]={0,-1,0};
    double forward[3],right[3],down[3];for(int i=0;i<3;i++)forward[i]=target[i]-eye[i];normalized(forward);
    cross(forward,up,right);normalized(right);cross(forward,right,down);normalized(down);
    for(int i=0;i<3;i++){
        o->camera_origin_q12[i]=o->instance.renderer_root_q12[i]+(int32_t)(eye[i]*4096);
        o->camera_rotation_q12[i]=(int16_t)lround(right[i]*4096);
        o->camera_rotation_q12[i+3]=(int16_t)lround(down[i]*4096);
        o->camera_rotation_q12[i+6]=(int16_t)lround(forward[i]*4096);
    }
    o->projection_h=220;o->projection_ofx=160<<16;o->projection_ofy=108<<16;
}
static void owner_from_ram(A2ActorPacketOwner *o,const unsigned char *ram,unsigned pose,const A2NativeModel *m){
    memset(o,0,sizeof *o);o->handle=pose+1;o->submission_sequence=pose+1;o->guest_frame=pose?17200:16750;
    o->instance.valid=o->instance.generation_known=o->instance.selected_for_draw=1;
    o->instance.instance_generation=1;o->instance.part_count=2;o->instance.entity_address=0x80119a34;
    const unsigned char *e=ram+0x119a34;
    for(unsigned i=0;i<3;i++){
        o->instance.actor_world_q12[i]=(int32_t)u32(e+24+4*i);
        o->instance.actor_offset_q12[i]=(int32_t)u32(e+36+4*i);
        int32_t value=o->instance.actor_world_q12[i]+o->instance.actor_offset_q12[i];
        o->instance.renderer_root_q12[i]=i==1?-value:value;
    }
    const int32_t root[]={2293760,0,3522560};assert(!memcmp(root,o->instance.renderer_root_q12,sizeof root));
    for(unsigned i=0;i<2;i++){
        const unsigned char *p=ram+0x1ec5a0+80*i;assert(!memcmp(p,expected_parts[pose][i],80));
        A2ActorPart *part=&o->parts[i];part->address=0x801ec5a0+80*i;part->flags=(uint16_t)u16(p);part->source_mesh_index=(uint16_t)u16(p+2);
        assert(part->source_mesh_index==i);assert(!(part->flags&(7|0x200|0x1000)));
        part->valid=part->visible=1;part->source_generation=1;strcpy(part->source_key,m->source_key);memcpy(part->source_sha256,m->source_sha256,32);
        for(unsigned a=0;a<3;a++){part->translation0[a]=(int32_t)u32(p+8+4*a);part->translation1[a]=(int32_t)u32(p+20+4*a);part->pretranslation[a]=(int16_t)u16(p+52+2*a);}
        for(unsigned a=0;a<9;a++)part->matrix_q12[a]=(int16_t)u16(p+32+2*a);
        memcpy(part->raw,p,80);
    }
    studio_camera(o);
}
static void transform(const float *m,const double *p,double *out){for(unsigned r=0;r<4;r++){out[r]=0;for(unsigned c=0;c<4;c++)out[r]+=m[4*r+c]*p[c];}}
static void project(const A2MeshMat4 *camera,const A2MeshMat4 *actor,const A2MeshMat4 *skin,const float *p,double *screen,unsigned w,unsigned h){
    double v[]={p[0],p[1],p[2],1},a[4],b[4],c[4];transform(skin->m,v,a);transform(actor->m,a,b);transform(camera->m,b,c);assert(c[3]>0);
    screen[0]=(c[0]/c[3]+1)*w*.5;screen[1]=(1-c[1]/c[3])*h*.5;screen[2]=c[2]/c[3];
}
static void matrix_json(FILE *f,const A2MeshMat4 *m){fputc('[',f);for(unsigned i=0;i<16;i++)fprintf(f,"%s%.9g",i?",":"",m->m[i]);fputc(']',f);}
static void write_output(const char *out,const char *label,const unsigned char *rgba,unsigned w,unsigned h){
    char path[4096];assert(snprintf(path,sizeof path,"%s/%s.rgba",out,label)<(int)sizeof path);FILE *f=fopen(path,"wbx");assert(f);assert(fwrite(rgba,4,(size_t)w*h,f)==(size_t)w*h);assert(!fclose(f));
    assert(snprintf(path,sizeof path,"%s/%s.ppm",out,label)<(int)sizeof path);f=fopen(path,"wbx");assert(f);fprintf(f,"P6\n%u %u\n255\n",w,h);
    for(unsigned y=0;y<h;y++)for(unsigned x=0;x<w;x++){
        const unsigned char *p=rgba+4*((size_t)y*w+x);unsigned char pixel[3];unsigned checker=((x/24+y/24)&1)?50:38;
        for(unsigned c=0;c<3;c++)pixel[c]=(unsigned char)((p[c]*p[3]+checker*(255-p[3])+127)/255);
        assert(fwrite(pixel,1,3,f)==3);
    }
    assert(!fclose(f));
}
int main(int argc,char **argv){
    if(argc!=5){fprintf(stderr,"usage: %s T02.A2M RAM16750 RAM17200 OUTPUT_DIR\n",argv[0]);return 2;}
    char error[256],path[4096];size_t bytes;void *data=read_file(argv[1],&bytes);A2NativeModel *model=NULL;
    assert(a2_native_model_decode(data,bytes,&model,error,sizeof error));free(data);assert(!strcmp(model->source_key,"T02")&&model->joint_count==2);
    const unsigned char expected_sha[32]={0xfb,0xbc,0x6e,0xd2,0x0a,0x3f,0xc8,0xcf,0x8a,0xc6,0x9e,0x1c,0x1a,0xf7,0x4a,0x8a,0xe4,0x4d,0x45,0x1f,0xcf,0xbb,0x47,0x30,0x23,0x21,0xc1,0x18,0x2f,0xef,0xab,0xf1};assert(!memcmp(expected_sha,model->source_sha256,32));
    const unsigned scale=3,w=320*scale,h=216*scale;size_t pixels=(size_t)w*h;
    A2MeshScene *scene=a2_mesh_scene_create(w,h,error,sizeof error);if(!scene){fprintf(stderr,"%s\n",error);a2_native_model_destroy(model);return 77;}
    assert(a2_mesh_scene_add(scene,model));unsigned char *rgba=malloc(pixels*4),*closed=malloc(pixels*4);float *depth=malloc(pixels*sizeof *depth);assert(rgba&&closed&&depth);
    assert(snprintf(path,sizeof path,"%s/scene-report.json",argv[4])<(int)sizeof path);FILE *report=fopen(path,"wx");assert(report);
    fputs("{\"kind\":\"offline_verified_native_pose_with_explicit_studio_camera\",\"runtime_binding_proven\":false,\"historical_game_camera\":false,\"material_pass\":\"unlit authored atlas\",\"diagnostic_generation\":1,\"width\":960,\"height\":648,\"poses\":[",report);
    A2MeshMat4 closed_body={0};
    for(unsigned pose=0;pose<2;pose++){
        data=read_file(argv[pose+2],&bytes);assert(bytes==0x200000);A2ActorPacketOwner owner;owner_from_ram(&owner,data,pose,model);free(data);
        A2MeshMat4 actor,skin[2],camera;assert(a2_mesh_pose(&owner,model,&actor,skin,2));assert(a2_mesh_camera(&owner,320,216,scale,0,&camera));
        if(!pose)closed_body=skin[0];else assert(!memcmp(&closed_body,&skin[0],sizeof closed_body));
        const A2ActorPacketOwner *list[]={&owner};assert(a2_mesh_scene_draw(scene,list,1,scale,0,rgba,pixels*4,depth,pixels*sizeof *depth));
        unsigned coverage=0,minx=w,miny=h,maxx=0,maxy=0;
        for(unsigned y=0;y<h;y++)for(unsigned x=0;x<w;x++){
            size_t i=(size_t)y*w+x;assert(isfinite(depth[i])&&depth[i]>=0&&depth[i]<=1);
            if(rgba[4*i+3]){coverage++;if(x<minx)minx=x;if(x>maxx)maxx=x;if(y<miny)miny=y;if(y>maxy)maxy=y;}
        }
        assert(coverage>100);if(!pose)memcpy(closed,rgba,pixels*4);else assert(memcmp(closed,rgba,pixels*4));
        write_output(argv[4],pose?"open":"closed",rgba,w,h);
        fprintf(report,"%s{\"frame\":%u,\"coverage_pixels\":%u,\"pixel_bbox\":[%u,%u,%u,%u],\"actor\":",pose?",":"",owner.guest_frame,coverage,minx,miny,maxx,maxy);matrix_json(report,&actor);
        fputs(",\"view_projection\":",report);matrix_json(report,&camera);fputs(",\"skin\":[",report);matrix_json(report,&skin[0]);fputc(',',report);matrix_json(report,&skin[1]);fputs("],\"projected_part_bounds\":[",report);
        for(unsigned part=0;part<2;part++){
            double box[]={DBL_MAX,DBL_MAX,-DBL_MAX,-DBL_MAX};
            for(unsigned i=0;i<model->vertex_count;i++)if(model->vertices[i].joints[0]==part){
                double p[3];project(&camera,&actor,&skin[part],model->vertices[i].position,p,w,h);
                if(p[0]<box[0])box[0]=p[0];if(p[1]<box[1])box[1]=p[1];if(p[0]>box[2])box[2]=p[0];if(p[1]>box[3])box[3]=p[1];
            }
            fprintf(report,"%s[%.9g,%.9g,%.9g,%.9g]",part?",":"",box[0],box[1],box[2],box[3]);
        }
        fputs("]}",report);
    }
    fputs("],\"body_skin_unchanged\":true,\"open_closed_pixels_differ\":true}\n",report);assert(!fclose(report));
    free(rgba);free(closed);free(depth);a2_mesh_scene_destroy(scene);a2_native_model_destroy(model);puts("native chest scene: retained body/lid poses, studio camera, two distinct GPU readbacks pass");return 0;
}
