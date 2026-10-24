#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#include "native_mesh_backend.h"
#include <math.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { ResourceLimit=128, UniformStride=512, JointStride=A2_MESH_MAX_JOINTS*64 };
typedef struct {
    float camera[16],model[16],color[4];
    float cutoff;uint32_t alpha,skin_count,shader,texture_srgb,owner_tag;
    float roughness,metallic,specular,bump_strength,bump_distance;uint32_t bump_invert;
    float camera_world[4];
    uint32_t scene_known,pad[3];
    float scene_light[3][4],scene_color[3][4],scene_background[4],scene_far[4],scene_depth[4];
} UploadUniform;
_Static_assert(sizeof(A2MeshVertex)==96,"cooked vertex ABI");
_Static_assert(offsetof(A2MeshVertex,joints)==72,"cooked joints ABI");
_Static_assert(offsetof(A2MeshVertex,weights)==80,"cooked weights ABI");
_Static_assert(sizeof(UploadUniform)<=UniformStride,"uniform stride");
_Static_assert(offsetof(UploadUniform,owner_tag)==164,"owner uniform ABI");
_Static_assert(offsetof(UploadUniform,camera_world)==192,"lighting uniform ABI");
_Static_assert(offsetof(UploadUniform,scene_light)==224,"native lighting uniform ABI");
@interface A2MetalMesh:NSObject {
@public id<MTLBuffer> vertices,indices; uint32_t index_count,required_joints; MTLIndexType index_type;
} @end
@implementation A2MetalMesh @end
@interface A2MetalStorage:NSObject {
@public id<MTLDevice> device;id<MTLCommandQueue> queue;
    id<MTLRenderPipelineState> pipelines[2][2][2];
    id<MTLDepthStencilState> depth_states[2][2];id<MTLSamplerState> samplers[2][3];
    id<MTLTexture> color[2],depth,owner,white;
    id<MTLBuffer> uniforms,joints,color_read,depth_read,owner_read;
    NSMutableDictionary<NSNumber *,A2MetalMesh *> *meshes;
    NSMutableDictionary<NSNumber *,id<MTLTexture>> *textures,*srgb_textures;
    uint32_t width,height;size_t row_bytes;unsigned completed;uint64_t submissions;
} @end
@implementation A2MetalStorage @end
struct A2MeshBackend {void *storage;};
static _Atomic uint64_t next_handle=1;
static A2MetalStorage *storage(const A2MeshBackend *b){return b?(__bridge A2MetalStorage *)b->storage:nil;}
static void error_text(char *out,size_t size,NSString *message){if(out&&size)snprintf(out,size,"%s",message.UTF8String?:"Metal operation failed");}
static int finite_values(const float *p,size_t n){for(size_t j=0;j<n;j++)if(!isfinite(p[j]))return 0;return 1;}
static int unit(float v){return isfinite(v)&&v>=0&&v<=1;}
static int boolean(unsigned v){return v<=1;}
static int matrix_valid(const A2MeshMat4 *m){return finite_values(m->m,16);}
static void transpose(float *dst,const A2MeshMat4 *src){for(unsigned r=0;r<4;r++)for(unsigned c=0;c<4;c++)dst[4*c+r]=src->m[4*r+c];}
static int image_layout(uint32_t width,uint32_t height,size_t stride,size_t bytes){
    size_t row=(size_t)width*4;
    return stride>=row&&height&&stride<=(SIZE_MAX-row)/(height-1?:1)&&bytes>=(height-1)*stride+row;
}
static id<MTLTexture> target(id<MTLDevice> d,uint32_t w,uint32_t h,MTLPixelFormat format){
    MTLTextureDescriptor *t=[MTLTextureDescriptor texture2DDescriptorWithPixelFormat:format width:w height:h mipmapped:NO];
    t.storageMode=MTLStorageModePrivate;t.usage=MTLTextureUsageRenderTarget|MTLTextureUsageShaderRead;
    return [d newTextureWithDescriptor:t];
}
static NSString *const shader_source=@
"#include <metal_stdlib>\n"
"using namespace metal;\n"
"struct V { packed_float3 p,n; packed_float2 uv,uv1; packed_float4 c,c1; ushort4 ids; packed_float4 w; };\n"
"struct U { float4x4 camera,model; float4 color; float cutoff; uint alpha,skin_count,shader,texture_srgb,owner_tag; float roughness,metallic,specular,bump_strength,bump_distance; uint bump_invert; float4 camera_world; uint scene_known,pad0,pad1,pad2; float4 scene_light[3],scene_color[3],scene_background,scene_far,scene_depth; };\n"
"struct O { float4 position [[position]]; float2 uv; float4 c,c1; float3 world,normal; float camera_z; };\n"
"struct F { float4 color [[color(0)]]; uint owner [[color(1)]]; };\n"
"float3 normal_transform(float3x3 m,float3 n){float3 a=cross(m[1],m[2]),b=cross(m[2],m[0]),c=cross(m[0],m[1]);float det=dot(m[0],a);return abs(det)>1e-12?(float3x3(a,b,c)*n)/det:float3(0);}\n"
"float3 safe_normal(float3 n){float q=dot(n,n);return q>1e-20&&isfinite(q)?n*rsqrt(q):float3(0);}\n"
"vertex O mesh_vertex(uint id [[vertex_id]],device const V *v [[buffer(0)]],constant U &u [[buffer(1)]],device const float4x4 *joints [[buffer(2)]]) {\n"
" V a=v[id];float4 p=float4(float3(a.p),1);float3x3 skin=float3x3(1);\n"
" if(u.skin_count){float4 s=0;if(u.shader>=2||u.scene_known)skin=float3x3(0);for(uint k=0;k<4;k++)if(a.w[k]>0){s+=a.w[k]*(joints[a.ids[k]]*p);if(u.shader>=2||u.scene_known){float4x4 j=joints[a.ids[k]];skin+=a.w[k]*float3x3(j[0].xyz,j[1].xyz,j[2].xyz);}}p=s;}\n"
" O o;o.position=u.camera*u.model*p;o.uv=(u.shader==1||u.shader==3)?float2(a.uv1):float2(a.uv);o.c=float4(a.c);o.c1=float4(a.c1);o.world=0;o.normal=0;o.camera_z=o.position.w;\n"
" if(u.shader>=2||u.scene_known){o.world=(u.model*p).xyz;float3x3 m=float3x3(u.model[0].xyz,u.model[1].xyz,u.model[2].xyz)*skin;o.normal=safe_normal(normal_transform(m,float3(a.n)));}return o;}\n"
"float3 decode(float3 c){return select(c/12.92,pow((c+.055)/1.055,float3(2.4)),c>float3(.04045));}\n"
"float3 lit(float3 base,float3 n,float3 v,constant U &u){\n"
" float3 l=normalize(float3(-.35,-.8,-.5)),h=safe_normal(l+v);float nl=max(dot(n,l),0.0),nv=max(dot(n,v),1e-4),nh=max(dot(n,h),0.0),vh=max(dot(v,h),0.0);\n"
" float r=max(u.roughness,.045),a=r*r,a2=a*a,den=nh*nh*(a2-1)+1,D=a2/(M_PI_F*den*den),k=(r+1)*(r+1)/8;\n"
" float G=(nv/(nv*(1-k)+k))*(nl/(nl*(1-k)+k));float3 f0=mix(float3(.08*u.specular),base,u.metallic),F=f0+(1-f0)*pow(1-vh,5.0);\n"
" return .35*base+1.4*nl*((1-F)*(1-u.metallic)*base/M_PI_F+D*G*F/(4*nv*max(nl,1e-4)));}\n"
"float3 encode(float3 c){return select(12.92*c,1.055*pow(max(c,float3(0)),float3(1.0/2.4))-.055,c>float3(.0031308));}\n"
"float3 native_scene(float3 albedo,float3 normal,float z,constant U &u){\n"
" // Same signed control units and saturation stages as actor NCDS. Modern\n"
" // authored albedo is encoded before the native color operation, then decoded\n"
" // for the output attachment. It is not multiplied in linear-light space.\n"
" float3 li=clamp(floor(float3(dot(u.scene_light[0].xyz,normal),dot(u.scene_light[1].xyz,normal),dot(u.scene_light[2].xyz,normal))),float3(0),float3(32767));\n"
" float3 ir=clamp(floor(u.scene_background.xyz+float3(dot(u.scene_color[0].xyz,li),dot(u.scene_color[1].xyz,li),dot(u.scene_color[2].xyz,li))/4096.0),float3(0),float3(32767));\n"
" float sz=clamp(floor(z),0.0,65535.0),h=u.scene_depth.z;\n"
" float q=(sz==0||h>=sz*2)?131071.0:min(131071.0,floor((floor(h*131072.0/sz)+1)/2));\n"
" float ir0=clamp(floor((q*u.scene_depth.x+u.scene_depth.y)/4096.0),0.0,4096.0);\n"
" float3 color=encode(albedo)*255.0*ir*16.0;\n"
" float3 delta=clamp(floor(u.scene_far.xyz-color/4096.0),float3(-32768),float3(32767));\n"
" float3 result=clamp(floor(floor((color+ir0*delta)/4096.0)/16.0),float3(0),float3(255));\n"
" return decode(result/255.0);\n"
"}\n"
"fragment F mesh_fragment(O in [[stage_in]],constant U &u [[buffer(1)]],texture2d<float> tex [[texture(0)]],sampler smp [[sampler(0)]]) {\n"
" float4 t=tex.sample(smp,in.uv);if(u.texture_srgb)t.rgb=decode(t.rgb);float4 c;\n"
" if(u.shader==1)c=float4(mix(in.c.rgb,2*in.c1.rgb*t.rgb,t.a)*u.color.rgb,1);else c=in.c*t*u.color;\n"
" if(u.shader>=2||u.scene_known){float3 v=safe_normal(u.camera_world.xyz-in.world),n=safe_normal(in.normal);float3 dx=dfdx(in.world),dy=dfdy(in.world);if(dot(n,n)<.5)n=safe_normal(cross(dx,dy));if(!u.scene_known&&dot(n,v)<0)n=-n;\n"
"   if(u.shader==3){c=float4(mix(in.c.rgb,2*in.c1.rgb*t.rgb,t.a)*u.color.rgb,1);if(u.bump_strength>0&&u.bump_distance>0){float3 r1=cross(dy,n),r2=cross(n,dx);float det=dot(dx,r1);if(abs(det)>1e-12){float sign=u.bump_invert?-1.0:1.0;float3 gradient=(dfdx(t.a)*r1+dfdy(t.a)*r2)/det;n=safe_normal(n-sign*u.bump_strength*u.bump_distance*gradient);}}}\n"
"   else if(u.shader==2)c=u.color;\n"
"   c.rgb=u.scene_known?native_scene(c.rgb,n,in.camera_z,u):lit(max(c.rgb,float3(0)),n,v,u);\n"
" }\n"
" if(u.alpha==1&&c.a<u.cutoff)discard_fragment();if(u.alpha==0)c.a=1;F out;out.color=c;out.owner=u.owner_tag;return out;}\n"
;
A2MeshBackend *a2_mesh_backend_create(uint32_t width,uint32_t height,char *error,size_t error_size){ @autoreleasepool {
    if(error&&error_size)error[0]=0;
    if(!width||!height||width>4096||height>4096){error_text(error,error_size,@"Invalid offscreen dimensions");return NULL;}
    A2MetalStorage *s=[A2MetalStorage new];s->device=MTLCreateSystemDefaultDevice();
    if(!s->device){error_text(error,error_size,@"No Metal device");return NULL;}
    s->width=width;s->height=height;s->row_bytes=((size_t)width*4+255)&~(size_t)255;
    s->queue=[s->device newCommandQueue];s->meshes=[NSMutableDictionary new];s->textures=[NSMutableDictionary new];s->srgb_textures=[NSMutableDictionary new];
    NSError *failure=nil;MTLCompileOptions *options=[MTLCompileOptions new];
    if(@available(macOS 15.0,*))options.mathMode=MTLMathModeSafe;
    else {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
        options.fastMathEnabled=NO;
#pragma clang diagnostic pop
    }
    id<MTLLibrary> library=[s->device newLibraryWithSource:shader_source options:options error:&failure];
    if(!library){error_text(error,error_size,failure.localizedDescription);return NULL;}
    id<MTLFunction> vs=[library newFunctionWithName:@"mesh_vertex"],fs=[library newFunctionWithName:@"mesh_fragment"];
    for(unsigned srgb=0;srgb<2;srgb++)for(unsigned blend=0;blend<2;blend++)for(unsigned write=0;write<2;write++){
        MTLRenderPipelineDescriptor *p=[MTLRenderPipelineDescriptor new];p.vertexFunction=vs;p.fragmentFunction=fs;
        p.depthAttachmentPixelFormat=MTLPixelFormatDepth32Float;
        MTLRenderPipelineColorAttachmentDescriptor *a=p.colorAttachments[0];
        a.pixelFormat=srgb?MTLPixelFormatRGBA8Unorm_sRGB:MTLPixelFormatRGBA8Unorm;
        a.writeMask=write?MTLColorWriteMaskAll:MTLColorWriteMaskNone;a.blendingEnabled=blend;
        a.sourceRGBBlendFactor=MTLBlendFactorSourceAlpha;a.destinationRGBBlendFactor=MTLBlendFactorOneMinusSourceAlpha;
        a.sourceAlphaBlendFactor=MTLBlendFactorOne;a.destinationAlphaBlendFactor=MTLBlendFactorOneMinusSourceAlpha;
        p.colorAttachments[1].pixelFormat=MTLPixelFormatR32Uint;
        p.colorAttachments[1].writeMask=write?MTLColorWriteMaskAll:MTLColorWriteMaskNone;
        p.colorAttachments[1].blendingEnabled=NO;
        s->pipelines[srgb][blend][write]=[s->device newRenderPipelineStateWithDescriptor:p error:&failure];
        if(!s->pipelines[srgb][blend][write]){error_text(error,error_size,failure.localizedDescription);return NULL;}
    }
    for(unsigned test=0;test<2;test++)for(unsigned write=0;write<2;write++){
        MTLDepthStencilDescriptor *d=[MTLDepthStencilDescriptor new];d.depthCompareFunction=test?MTLCompareFunctionLess:MTLCompareFunctionAlways;d.depthWriteEnabled=write;
        s->depth_states[test][write]=[s->device newDepthStencilStateWithDescriptor:d];if(!s->depth_states[test][write])return NULL;
    }
    for(unsigned filter=0;filter<2;filter++)for(unsigned address=0;address<3;address++){
        MTLSamplerDescriptor *sampler=[MTLSamplerDescriptor new];
        sampler.minFilter=sampler.magFilter=filter?MTLSamplerMinMagFilterLinear:MTLSamplerMinMagFilterNearest;
        const MTLSamplerAddressMode modes[]={MTLSamplerAddressModeClampToEdge,MTLSamplerAddressModeRepeat,MTLSamplerAddressModeClampToZero};
        sampler.sAddressMode=sampler.tAddressMode=modes[address];
        s->samplers[filter][address]=[s->device newSamplerStateWithDescriptor:sampler];
        if(!s->samplers[filter][address]){error_text(error,error_size,@"Metal sampler allocation failed");return NULL;}
    }
    s->color[0]=target(s->device,width,height,MTLPixelFormatRGBA8Unorm);s->color[1]=target(s->device,width,height,MTLPixelFormatRGBA8Unorm_sRGB);
    s->depth=target(s->device,width,height,MTLPixelFormatDepth32Float);
    s->owner=target(s->device,width,height,MTLPixelFormatR32Uint);
    s->uniforms=[s->device newBufferWithLength:A2_MESH_MAX_DRAWS*UniformStride options:MTLResourceStorageModeShared];
    s->joints=[s->device newBufferWithLength:A2_MESH_MAX_DRAWS*JointStride options:MTLResourceStorageModeShared];
    s->color_read=[s->device newBufferWithLength:s->row_bytes*height options:MTLResourceStorageModeShared];
    s->depth_read=[s->device newBufferWithLength:s->row_bytes*height options:MTLResourceStorageModeShared];
    s->owner_read=[s->device newBufferWithLength:s->row_bytes*height options:MTLResourceStorageModeShared];
    MTLTextureDescriptor *white=[MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatRGBA8Unorm width:1 height:1 mipmapped:NO];
    white.storageMode=MTLStorageModeShared;white.usage=MTLTextureUsageShaderRead;s->white=[s->device newTextureWithDescriptor:white];
    if(!s->queue||!s->samplers[0][0]||!s->color[0]||!s->color[1]||!s->depth||!s->owner||!s->uniforms||!s->joints||!s->color_read||!s->depth_read||!s->owner_read||!s->white){error_text(error,error_size,@"Metal resource allocation failed");return NULL;}
    uint8_t pixel[]={255,255,255,255};[s->white replaceRegion:MTLRegionMake2D(0,0,1,1) mipmapLevel:0 withBytes:pixel bytesPerRow:4];
    A2MeshBackend *b=calloc(1,sizeof *b);if(!b){error_text(error,error_size,@"Backend allocation failed");return NULL;}
    b->storage=(void *)CFBridgingRetain(s);return b;
} }
void a2_mesh_backend_destroy(A2MeshBackend *b){if(b){id released=CFBridgingRelease(b->storage);(void)released;free(b);}}
const char *a2_mesh_backend_name(const A2MeshBackend *b){return storage(b)?"Metal offscreen unlit / controlled GGX":NULL;}
void a2_mesh_backend_stats(const A2MeshBackend *b,A2MeshStats *out){if(out){A2MetalStorage *s=storage(b);*out=s?(A2MeshStats){(uint32_t)s->meshes.count,(uint32_t)s->textures.count,s->submissions}:(A2MeshStats){0};}}
A2MeshHandle a2_mesh_create(A2MeshBackend *b,const A2MeshVertex *v,uint32_t vertices,const void *indices,uint32_t count,A2MeshIndexType type){ @autoreleasepool {
    A2MetalStorage *s=storage(b);if(!s||!v||!indices||!vertices||!count||count%3||(type!=2&&type!=4)||s->meshes.count>=ResourceLimit)return 0;
    if(vertices>s->device.maxBufferLength/sizeof *v||count>s->device.maxBufferLength/(unsigned)type)return 0;
    unsigned required=0;
    for(uint32_t j=0;j<vertices;j++){
        if(!finite_values(v[j].position,3)||!finite_values(v[j].normal,3)||!finite_values(v[j].uv,2)||!finite_values(v[j].uv1,2)||!finite_values(v[j].color,4)||!finite_values(v[j].color1,4))return 0;
        for(unsigned k=0;k<3;k++)if(v[j].color[k]<-16||v[j].color[k]>16||v[j].color1[k]<-16||v[j].color1[k]>16)return 0;
        if(!unit(v[j].color[3])||!unit(v[j].color1[3]))return 0;
        double sum=0;for(unsigned k=0;k<4;k++){float w=v[j].weights[k];if(!unit(w))return 0;sum+=w;if(w>0){if(v[j].joints[k]>=A2_MESH_MAX_JOINTS)return 0;unsigned n=v[j].joints[k]+1;if(n>required)required=n;}}
        if(fabs(sum-1)>1e-4)return 0;
    }
    for(uint32_t j=0;j<count;j++){uint32_t i=0;if(type==2){uint16_t a;memcpy(&a,(const uint8_t *)indices+2*(size_t)j,2);i=a;}else memcpy(&i,(const uint8_t *)indices+4*(size_t)j,4);if(i>=vertices)return 0;}
    A2MetalMesh *m=[A2MetalMesh new];m->vertices=[s->device newBufferWithBytes:v length:(size_t)vertices*sizeof *v options:MTLResourceStorageModeShared];
    m->indices=[s->device newBufferWithBytes:indices length:(size_t)count*(unsigned)type options:MTLResourceStorageModeShared];
    if(!m->vertices||!m->indices)return 0;m->index_count=count;m->required_joints=required;m->index_type=type==2?MTLIndexTypeUInt16:MTLIndexTypeUInt32;
    uint64_t h=atomic_fetch_add(&next_handle,1);s->meshes[@(h)]=m;return h;
} }
int a2_mesh_destroy(A2MeshBackend *b,A2MeshHandle h){A2MetalStorage *s=storage(b);if(!s||!h||!s->meshes[@(h)])return 0;[s->meshes removeObjectForKey:@(h)];return 1;}
A2MeshHandle a2_mesh_texture_create(A2MeshBackend *b,uint32_t w,uint32_t h,const uint8_t *rgba,size_t stride){ @autoreleasepool {
    A2MetalStorage *s=storage(b);if(!s||!rgba||!w||!h||w>4096||h>4096||stride<(size_t)w*4||stride>SIZE_MAX/h||s->textures.count>=ResourceLimit)return 0;
    MTLTextureDescriptor *d=[MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatRGBA8Unorm width:w height:h mipmapped:NO];d.storageMode=MTLStorageModeShared;d.usage=MTLTextureUsageShaderRead|MTLTextureUsagePixelFormatView;
    id<MTLTexture> t=[s->device newTextureWithDescriptor:d];if(!t)return 0;
    [t replaceRegion:MTLRegionMake2D(0,0,w,h) mipmapLevel:0 withBytes:rgba bytesPerRow:stride];
    id<MTLTexture> srgb=[t newTextureViewWithPixelFormat:MTLPixelFormatRGBA8Unorm_sRGB];if(!srgb)return 0;
    uint64_t handle=atomic_fetch_add(&next_handle,1);s->textures[@(handle)]=t;s->srgb_textures[@(handle)]=srgb;return handle;
} }
int a2_mesh_texture_destroy(A2MeshBackend *b,A2MeshHandle h){A2MetalStorage *s=storage(b);if(!s||!h||!s->textures[@(h)])return 0;[s->textures removeObjectForKey:@(h)];[s->srgb_textures removeObjectForKey:@(h)];return 1;}
static int material_valid(const A2MeshMaterial *m){
    if(!finite_values(m->base_color,4)||!unit(m->roughness)||!unit(m->metallic)||!unit(m->alpha_cutoff)||!boolean(m->texture_srgb))return 0;
    if(m->alpha<A2_MESH_OPAQUE||m->alpha>A2_MESH_BLEND||m->shader<A2_MESH_PLAIN||m->shader>A2_MESH_LIT_SHIELD)return 0;
    if(m->filter<A2_MESH_NEAREST||m->filter>A2_MESH_LINEAR||m->address<A2_MESH_CLAMP||m->address>A2_MESH_CLIP||
       !unit(m->specular)||!unit(m->bump_strength)||!isfinite(m->bump_distance)||m->bump_distance<0||m->bump_distance>1||!boolean(m->bump_invert))return 0;
    return m->shader==A2_MESH_PLAIN||m->alpha==A2_MESH_OPAQUE;
}
int a2_mesh_render(A2MeshBackend *b,const A2MeshFrame *frame,const A2MeshDraw *draws,size_t count){ @autoreleasepool {
    A2MetalStorage *s=storage(b);if(!s||!frame||(!draws&&count)||count>A2_MESH_MAX_DRAWS||!matrix_valid(&frame->view_projection)||!unit(frame->clear_depth)||!boolean(frame->encode_srgb))return 0;
    for(unsigned j=0;j<4;j++)if(!unit(frame->clear_rgba[j]))return 0;
    if(!finite_values(frame->camera_world,3))return 0;
    for(size_t j=0;j<count;j++){
        const A2MeshDraw *d=&draws[j];A2MetalMesh *m=s->meshes[@(d->mesh)];
        if(!m||!d->index_count||d->index_count%3||d->first_index>m->index_count||d->index_count>m->index_count-d->first_index||!matrix_valid(&d->model)||!material_valid(&d->material)||!boolean(d->depth_test)||!boolean(d->depth_write)||!boolean(d->color_write))return 0;
        if(!a2_native_scene_light_valid(&d->native_light))return 0;
        if(d->material.texture&&!s->textures[@(d->material.texture)])return 0;
        if(d->joint_count>A2_MESH_MAX_JOINTS||(d->joint_count&&(!d->joints||d->joint_count<m->required_joints)))return 0;
        for(unsigned k=0;k<d->joint_count;k++)if(!matrix_valid(&d->joints[k]))return 0;
    }
    /* Constants persist on the device; only bytes change between submissions.
     * A prior command has completed synchronously before these writes. */
    for(size_t j=0;j<count;j++){
        const A2MeshDraw *d=&draws[j];UploadUniform *u=(void *)((uint8_t *)s->uniforms.contents+j*UniformStride);memset(u,0,sizeof *u);
        transpose(u->camera,&frame->view_projection);transpose(u->model,&d->model);memcpy(u->color,d->material.base_color,sizeof u->color);
        u->cutoff=d->material.alpha_cutoff;u->alpha=d->material.alpha;u->skin_count=d->joint_count;u->shader=d->material.shader;u->texture_srgb=d->material.texture_srgb;
        u->owner_tag=d->owner_tag;u->roughness=d->material.roughness;u->metallic=d->material.metallic;
        u->specular=d->material.specular;u->bump_strength=d->material.bump_strength;
        u->bump_distance=d->material.bump_distance;u->bump_invert=d->material.bump_invert;
        memcpy(u->camera_world,frame->camera_world,sizeof frame->camera_world);
        u->scene_known=d->native_light.known;
        if(u->scene_known){const A2NativeSceneLight *n=&d->native_light;
            for(unsigned r=0;r<3;r++){
                for(unsigned c=0;c<3;c++){u->scene_light[r][c]=n->light_q12[r*3+c];u->scene_color[r][c]=n->color_q12[r*3+c];}
                u->scene_background[r]=(float)n->background[r];u->scene_far[r]=(float)n->far_color[r];
            }
            u->scene_depth[0]=(float)n->dqa;u->scene_depth[1]=(float)n->dqb;u->scene_depth[2]=(float)n->projection_h;
        }
        /* Hardware sRGB view decodes BEFORE linear filtering. Nearest keeps
         * the original manual decode and unchanged chest arithmetic. */
        if(d->material.texture&&d->material.texture_srgb&&d->material.filter==A2_MESH_LINEAR)u->texture_srgb=0;
        for(unsigned k=0;k<d->joint_count;k++)transpose((float *)((uint8_t *)s->joints.contents+j*JointStride+64*k),&d->joints[k]);
    }
    s->completed=0;id<MTLCommandBuffer> command=[s->queue commandBuffer];if(!command)return 0;
    MTLRenderPassDescriptor *pass=[MTLRenderPassDescriptor renderPassDescriptor];
    pass.colorAttachments[0].texture=s->color[frame->encode_srgb];pass.colorAttachments[0].loadAction=MTLLoadActionClear;pass.colorAttachments[0].storeAction=MTLStoreActionStore;
    pass.colorAttachments[0].clearColor=MTLClearColorMake(frame->clear_rgba[0],frame->clear_rgba[1],frame->clear_rgba[2],frame->clear_rgba[3]);
    pass.colorAttachments[1].texture=s->owner;pass.colorAttachments[1].loadAction=MTLLoadActionClear;pass.colorAttachments[1].storeAction=MTLStoreActionStore;
    pass.colorAttachments[1].clearColor=MTLClearColorMake(0,0,0,0);
    pass.depthAttachment.texture=s->depth;pass.depthAttachment.loadAction=MTLLoadActionClear;pass.depthAttachment.storeAction=MTLStoreActionStore;pass.depthAttachment.clearDepth=frame->clear_depth;
    id<MTLRenderCommandEncoder> encoder=[command renderCommandEncoderWithDescriptor:pass];if(!encoder)return 0;
    [encoder setCullMode:MTLCullModeNone];[encoder setViewport:(MTLViewport){0,0,s->width,s->height,0,1}];
    for(size_t j=0;j<count;j++){
        const A2MeshDraw *d=&draws[j];A2MetalMesh *m=s->meshes[@(d->mesh)];
        [encoder setRenderPipelineState:s->pipelines[frame->encode_srgb][d->material.alpha==A2_MESH_BLEND][d->color_write]];
        [encoder setDepthStencilState:s->depth_states[d->depth_test][d->depth_write]];
        [encoder setVertexBuffer:m->vertices offset:0 atIndex:0];[encoder setVertexBuffer:s->uniforms offset:j*UniformStride atIndex:1];[encoder setVertexBuffer:s->joints offset:j*JointStride atIndex:2];
        [encoder setFragmentBuffer:s->uniforms offset:j*UniformStride atIndex:1];
        id<MTLTexture> texture=s->white;
        if(d->material.texture)texture=d->material.texture_srgb&&d->material.filter==A2_MESH_LINEAR?s->srgb_textures[@(d->material.texture)]:s->textures[@(d->material.texture)];
        [encoder setFragmentTexture:texture atIndex:0];[encoder setFragmentSamplerState:s->samplers[d->material.filter][d->material.address] atIndex:0];
        [encoder drawIndexedPrimitives:MTLPrimitiveTypeTriangle indexCount:d->index_count indexType:m->index_type indexBuffer:m->indices indexBufferOffset:(size_t)d->first_index*(m->index_type==MTLIndexTypeUInt16?2:4)];
    }
    [encoder endEncoding];id<MTLBlitCommandEncoder> blit=[command blitCommandEncoder];if(!blit)return 0;
    [blit copyFromTexture:s->color[frame->encode_srgb] sourceSlice:0 sourceLevel:0 sourceOrigin:MTLOriginMake(0,0,0) sourceSize:MTLSizeMake(s->width,s->height,1) toBuffer:s->color_read destinationOffset:0 destinationBytesPerRow:s->row_bytes destinationBytesPerImage:s->row_bytes*s->height];
    [blit copyFromTexture:s->depth sourceSlice:0 sourceLevel:0 sourceOrigin:MTLOriginMake(0,0,0) sourceSize:MTLSizeMake(s->width,s->height,1) toBuffer:s->depth_read destinationOffset:0 destinationBytesPerRow:s->row_bytes destinationBytesPerImage:s->row_bytes*s->height];
    [blit copyFromTexture:s->owner sourceSlice:0 sourceLevel:0 sourceOrigin:MTLOriginMake(0,0,0) sourceSize:MTLSizeMake(s->width,s->height,1) toBuffer:s->owner_read destinationOffset:0 destinationBytesPerRow:s->row_bytes destinationBytesPerImage:s->row_bytes*s->height];
    [blit endEncoding];[command commit];[command waitUntilCompleted];
    if(command.status!=MTLCommandBufferStatusCompleted)return 0;s->completed=1;++s->submissions;return 1;
} }
int a2_mesh_readback(A2MeshBackend *b,uint8_t *rgba,size_t rgba_bytes,size_t rgba_stride,float *depth,size_t depth_bytes,size_t depth_stride){
    A2MetalStorage *s=storage(b);if(!s||!s->completed||!rgba||!depth||!image_layout(s->width,s->height,rgba_stride,rgba_bytes)||!image_layout(s->width,s->height,depth_stride,depth_bytes))return 0;
    for(unsigned y=0;y<s->height;y++){
        memcpy(rgba+y*rgba_stride,(uint8_t *)s->color_read.contents+y*s->row_bytes,s->width*4);
        memcpy((uint8_t *)depth+y*depth_stride,(uint8_t *)s->depth_read.contents+y*s->row_bytes,s->width*4);
    }
    return 1;
}
int a2_mesh_readback_owners(A2MeshBackend *b,uint32_t *owners,size_t bytes,size_t stride){
    A2MetalStorage *s=storage(b);if(!s||!s->completed||!owners||!image_layout(s->width,s->height,stride,bytes))return 0;
    for(unsigned y=0;y<s->height;y++)
        memcpy((uint8_t *)owners+y*stride,(uint8_t *)s->owner_read.contents+y*s->row_bytes,s->width*4);
    return 1;
}
