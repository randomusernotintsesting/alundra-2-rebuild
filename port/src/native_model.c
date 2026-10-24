#include "native_model.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint32_t rd32(const uint8_t *p) { return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24; }
static uint64_t rd64(const uint8_t *p) { return rd32(p)|(uint64_t)rd32(p+4)<<32; }
static float rdf(const uint8_t *p) { uint32_t u=rd32(p);float f;memcpy(&f,&u,4);return f; }
static void floats(float *dst,const uint8_t *p,unsigned n) { for(unsigned i=0;i<n;i++)dst[i]=rdf(p+4*i); }
static int finite_array(const float *p,unsigned n) { for(unsigned i=0;i<n;i++)if(!isfinite(p[i]))return 0;return 1; }
static int unit(float x) { return isfinite(x)&&x>=0&&x<=1; }
static int zeros(const uint8_t *p,size_t n) { for(size_t i=0;i<n;i++)if(p[i])return 0;return 1; }
static int name_valid(const uint8_t *p) {
    unsigned i=0;while(i<32&&p[i]){if(p[i]<32||p[i]>126)return 0;i++;}
    return i>0&&i<32&&zeros(p+i,32-i);
}
static int bounds_valid(const float *p) {
    return finite_array(p,6)&&p[0]<=p[3]&&p[1]<=p[4]&&p[2]<=p[5];
}
static int contains(const float *b,const float *p) {
    for(unsigned i=0;i<3;i++)if((double)p[i]<(double)b[i]-1e-4||(double)p[i]>(double)b[i+3]+1e-4)return 0;
    return 1;
}
static int inverse_valid(const float *a,const float *b) {
    if(!finite_array(a,16)||!finite_array(b,16))return 0;
    if(a[12]!=0||a[13]!=0||a[14]!=0||a[15]!=1||b[12]!=0||b[13]!=0||b[14]!=0||b[15]!=1)return 0;
    for(unsigned pass=0;pass<2;pass++){
        const float *x=pass?b:a,*y=pass?a:b;
        for(unsigned r=0;r<4;r++)for(unsigned c=0;c<4;c++){
            double sum=0,scale=0;
            for(unsigned k=0;k<4;k++){double t=(double)x[4*r+k]*y[4*k+c];sum+=t;scale+=fabs(t);}
            /* A relative-only residual can accept a singular matrix when
             * large products cancel. The identity must remain absolute. */
            if(fabs(sum-(r==c))>fmin(1e-3,1e-4+1e-6*scale))return 0;
        }
    }
    return 1;
}
static int fail(char *error,size_t n,const char *message) { if(error&&n)snprintf(error,n,"A2M2: %s",message);return 0; }
void a2_native_model_destroy(A2NativeModel *m) {
    if(!m)return;
    if(m->textures)for(uint32_t i=0;i<m->texture_count;i++)free(m->textures[i].rgba);
    free(m->vertices);free(m->indices);free(m->materials);free(m->joints);free(m->submeshes);free(m->textures);free(m);
}
static uint32_t index_at(const A2NativeModel *m,uint32_t i) {
    return m->index_width==2?((const uint16_t *)m->indices)[i]:((const uint32_t *)m->indices)[i];
}
typedef struct { uint64_t start,length; } Range;
static int range_compare(const void *a,const void *b) {
    uint64_t x=((const Range *)a)->start,y=((const Range *)b)->start;return x<y?-1:x>y;
}
static int covers(Range *r,unsigned n,uint64_t bytes) {
    qsort(r,n,sizeof *r,range_compare);uint64_t end=0;
    for(unsigned i=0;i<n;i++){if(r[i].start!=end)return 0;end+=r[i].length;}
    return end==bytes;
}
int a2_native_model_decode(const void *bytes,size_t length,A2NativeModel **out,char *error,size_t error_size) {
    A2NativeModel *m=NULL;const char *reason="invalid header";
    if(error&&error_size)error[0]=0;
    if(!out||*out)return fail(error,error_size,"output slot must be empty");
    if(!bytes||length<256||length>A2_MODEL_MAX_BYTES)return fail(error,error_size,"invalid file length");
    const uint8_t *b=bytes;
    if(memcmp(b,"A2M2\0\0\0\0",8)||rd32(b+8)!=1||rd32(b+12)!=256||rd64(b+16)!=length||
       (rd32(b+24)&~A2_MODEL_SIGNED_CORNER_RGB)||rd32(b+60)||!zeros(b+216,40)||!name_valid(b+160)||zeros(b+128,32))goto bad;
    uint32_t count[6],stride[6]={96,0,128,144,48,32};
    const uint32_t caps[6]={1000000,3000000,128,A2_MODEL_MAX_JOINTS,256,64};
    uint64_t offset[7],size[7];uint32_t width=rd32(b+56);
    if(width!=2&&width!=4)goto bad;
    stride[1]=width;reason="invalid section counts or ranges";
    for(unsigned i=0;i<6;i++){
        count[i]=rd32(b+32+4*i);offset[i]=rd64(b+64+8*i);size[i]=(uint64_t)count[i]*stride[i];
        if(count[i]>caps[i]||(!count[i]&&i!=5))goto bad;
    }
    if(count[1]%3)goto bad;
    offset[6]=rd64(b+112);size[6]=rd64(b+120);
    if(size[6]>64u*1024u*1024u||(!count[5]&&size[6]))goto bad;
    for(unsigned i=0;i<7;i++){
        if(offset[i]<256||(offset[i]&3)||offset[i]>length||size[i]>length-offset[i])goto bad;
        for(unsigned j=0;j<i;j++)if(size[i]&&size[j]&&offset[i]<offset[j]+size[j]&&offset[j]<offset[i]+size[i])goto bad;
    }
    reason="allocation failed";m=calloc(1,sizeof *m);if(!m)goto bad;
    m->allocated_bytes=sizeof *m;m->source_variant=rd32(b+28);m->file_flags=rd32(b+24);m->index_width=width;
    memcpy(m->source_key,b+160,32);memcpy(m->source_sha256,b+128,32);floats(m->bounds,b+192,6);
    m->vertex_count=count[0];m->index_count=count[1];m->material_count=count[2];
    m->joint_count=count[3];m->submesh_count=count[4];m->texture_count=count[5];
#define ALLOC(field,n,type) do { size_t a2_n=(n);if(a2_n>SIZE_MAX/sizeof(type))goto bad; \
    size_t a2_bytes=a2_n*sizeof(type);if(a2_bytes){m->field=calloc(a2_n,sizeof(type));if(!m->field)goto bad;} \
    m->allocated_bytes+=a2_bytes; } while(0)
    ALLOC(vertices,count[0],A2ModelVertex);ALLOC(indices,(size_t)count[1]*width,uint8_t);
    ALLOC(materials,count[2],A2ModelMaterial);ALLOC(joints,count[3],A2ModelJoint);
    ALLOC(submeshes,count[4],A2ModelSubmesh);ALLOC(textures,count[5],A2ModelTexture);
#undef ALLOC
    reason="invalid vertex or bounds";if(!bounds_valid(m->bounds))goto bad;
    for(uint32_t i=0;i<count[0];i++){
        const uint8_t *p=b+offset[0]+(uint64_t)i*96;A2ModelVertex *v=&m->vertices[i];
        floats(v->position,p,3);floats(v->normal,p+12,3);
        for(unsigned k=0;k<2;k++){floats(v->uv[k],p+24+k*8,2);floats(v->color[k],p+40+k*16,4);}
        floats(v->weights,p+80,4);
        double normal=0,weights=0;
        if(!finite_array(v->position,3)||!finite_array(v->normal,3)||!contains(m->bounds,v->position))goto bad;
        for(unsigned k=0;k<3;k++)normal+=(double)v->normal[k]*v->normal[k];
        if(fabs(normal-1)>1e-3)goto bad;
        for(unsigned k=0;k<2;k++){
            if(!finite_array(v->uv[k],2))goto bad;
            for(unsigned c=0;c<4;c++){
                float color=v->color[k][c];
                if(c<3 && (m->file_flags&A2_MODEL_SIGNED_CORNER_RGB)){
                    if(!isfinite(color)||color < -16.0f||color > 16.0f)goto bad;
                }else if(!unit(color))goto bad;
            }
        }
        for(unsigned k=0;k<4;k++){
            v->joints[k]=(uint16_t)(p[72+2*k]|(uint16_t)p[73+2*k]<<8);
            if(!unit(v->weights[k])||(v->weights[k]>0&&v->joints[k]>=count[3]))goto bad;
            weights+=v->weights[k];
        }
        if(fabs(weights-1)>1e-4)goto bad;
    }
    reason="invalid index";
    for(uint32_t i=0;i<count[1];i++){
        const uint8_t *p=b+offset[1]+(uint64_t)i*width;
        uint32_t x=width==2?(uint32_t)p[0]|(uint32_t)p[1]<<8:rd32(p);
        if(x>=count[0])goto bad;
        if(width==2)((uint16_t *)m->indices)[i]=(uint16_t)x;else ((uint32_t *)m->indices)[i]=x;
    }
    reason="invalid material";
    for(uint32_t i=0;i<count[2];i++){
        const uint8_t *p=b+offset[2]+(uint64_t)i*128;A2ModelMaterial *v=&m->materials[i];
        v->kind=rd32(p);v->alpha_mode=rd32(p+4);v->texture[0]=rd32(p+8);v->texture[1]=rd32(p+12);
        floats(v->base_color,p+16,4);v->roughness=rdf(p+32);v->metallic=rdf(p+36);v->alpha_cutoff=rdf(p+40);
        v->opacity=rdf(p+44);v->specular=rdf(p+48);v->ior=rdf(p+52);v->coat=rdf(p+56);v->coat_roughness=rdf(p+60);
        v->flags=rd32(p+64);v->roughness_min=rdf(p+68);v->roughness_max=rdf(p+72);memcpy(v->name,p+80,32);
        if(v->kind>3||v->alpha_mode>2||v->flags>1||rd32(p+76)||!zeros(p+112,16)||!name_valid(p+80))goto bad;
        for(unsigned k=0;k<2;k++)if(v->texture[k]!=UINT32_MAX&&v->texture[k]>=count[5])goto bad;
        if((v->kind==1||v->kind==2)&&v->texture[0]==UINT32_MAX)goto bad;
        for(unsigned k=0;k<4;k++)if(!unit(v->base_color[k]))goto bad;
        if(!unit(v->roughness)||!unit(v->metallic)||!unit(v->alpha_cutoff)||!unit(v->opacity)||!unit(v->specular)||
           !isfinite(v->ior)||v->ior<1||v->ior>3||!unit(v->coat)||!unit(v->coat_roughness)||
           !unit(v->roughness_min)||!unit(v->roughness_max)||v->roughness_min>v->roughness_max)goto bad;
    }
    reason="invalid bind matrix or joint graph";
    for(uint32_t i=0;i<count[3];i++){
        const uint8_t *p=b+offset[3]+(uint64_t)i*144;A2ModelJoint *j=&m->joints[i];
        j->source_id=rd32(p);j->parent=rd32(p+4);j->flags=rd32(p+8);
        floats(j->bind,p+16,16);floats(j->inverse_bind,p+80,16);
        if(j->source_id==UINT32_MAX||(j->parent!=UINT32_MAX&&j->parent>=count[3])||j->flags>1||rd32(p+12)||
           !inverse_valid(j->bind,j->inverse_bind))goto bad;
        for(uint32_t k=0;k<i;k++)if(m->joints[k].source_id==j->source_id)goto bad;
    }
    for(uint32_t i=0;i<count[3];i++){
        uint32_t p=i,steps=0;
        while(p!=UINT32_MAX){if(++steps>count[3])goto bad;p=m->joints[p].parent;}
    }
    Range ranges[256];reason="invalid submesh or coverage";
    for(uint32_t i=0;i<count[4];i++){
        const uint8_t *p=b+offset[4]+(uint64_t)i*48;A2ModelSubmesh *s=&m->submeshes[i];
        s->first_index=rd32(p);s->index_count=rd32(p+4);s->material=rd32(p+8);s->source_part=rd32(p+12);
        floats(s->bounds,p+16,6);
        if(s->first_index%3||!s->index_count||s->index_count%3||s->first_index>count[1]||
           s->index_count>count[1]-s->first_index||s->material>=count[2]||!bounds_valid(s->bounds)||!zeros(p+40,8))goto bad;
        if(s->source_part!=UINT32_MAX){
            int found=0;for(uint32_t k=0;k<count[3];k++)if(m->joints[k].source_id==s->source_part)found=1;
            if(!found)goto bad;
        }
        ranges[i]=(Range){s->first_index,s->index_count};
    }
    if(!covers(ranges,count[4],count[1]))goto bad;
    /* Coverage must be proved before walking indices: malicious overlapping
     * ranges must not multiply traversal cost by the submesh count. */
    for(uint32_t i=0;i<count[4];i++){
        const A2ModelSubmesh *s=&m->submeshes[i];
        for(uint32_t k=s->first_index;k<s->first_index+s->index_count;k++)
            if(!contains(s->bounds,m->vertices[index_at(m,k)].position))goto bad;
    }
    reason="invalid texture pixels";
    for(uint32_t i=0;i<count[5];i++){
        const uint8_t *p=b+offset[5]+(uint64_t)i*32;A2ModelTexture *t=&m->textures[i];
        t->width=rd32(p);t->height=rd32(p+4);t->flags=rd32(p+24);
        uint64_t start=rd64(p+8),n=rd64(p+16);
        if(!t->width||!t->height||t->width>4096||t->height>4096||t->flags>1||rd32(p+28)||
           n!=(uint64_t)t->width*t->height*4||start>size[6]||n>size[6]-start)goto bad;
        ranges[i]=(Range){start,n};t->bytes=(size_t)n;
    }
    if(!covers(ranges,count[5],size[6]))goto bad;
    /* No pixel allocation before the aggregate budget and disjoint coverage
     * are validated. Aliased 64 MiB ranges must not allocate gigabytes. */
    for(uint32_t i=0;i<count[5];i++){
        const uint8_t *p=b+offset[5]+(uint64_t)i*32;A2ModelTexture *t=&m->textures[i];
        uint64_t start=rd64(p+8);
        t->rgba=malloc(t->bytes);if(!t->rgba){reason="texture allocation failed";goto bad;}
        m->allocated_bytes+=t->bytes;memcpy(t->rgba,b+offset[6]+start,t->bytes);
    }
    *out=m;return 1;
bad:
    a2_native_model_destroy(m);return fail(error,error_size,reason);
}
int a2_native_model_load(A2Resources *r,A2ResourceId id,A2NativeModel **out,char *error,size_t error_size) {
    if(!out||*out)return fail(error,error_size,"output slot must be empty");
    uint64_t size=a2_resource_size(r,id);
    if(size<256||size>A2_MODEL_MAX_BYTES)return fail(error,error_size,"resource size out of range");
    void *data=malloc((size_t)size);if(!data)return fail(error,error_size,"resource allocation failed");
    int ok=a2_resource_pread(r,id,0,data,(size_t)size,error,error_size);
    if(ok)ok=a2_native_model_decode(data,(size_t)size,out,error,error_size);
    free(data);return ok;
}
