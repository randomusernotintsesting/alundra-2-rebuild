#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#include "native_mesh_backend.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
static uint8_t pixels[64*64*4],saved[64*64*4];
static float depths[64*64];static uint32_t owners[64*64];
static A2MeshMat4 identity(void){A2MeshMat4 a={0};for(int i=0;i<4;i++)a.m[i*5]=1;return a;}
static void read_image(A2MeshBackend *b){assert(a2_mesh_readback(b,pixels,sizeof pixels,256,depths,sizeof depths,256));assert(a2_mesh_readback_owners(b,owners,sizeof owners,256));}
static A2MeshDraw draw(A2MeshHandle h){A2MeshDraw d={0};d.mesh=h;d.index_count=6;d.model=identity();d.material.base_color[0]=d.material.base_color[1]=d.material.base_color[2]=d.material.base_color[3]=1;d.material.roughness=.5f;d.material.specular=.5f;d.depth_test=d.depth_write=d.color_write=1;d.owner_tag=91;return d;}
static A2MeshVertex vertices[4];static const uint16_t indices[]={0,1,2,0,2,3};
static void init_vertices(void){memset(vertices,0,sizeof vertices);const float xy[4][2]={{-.9f,.9f},{.9f,.9f},{.9f,-.9f},{-.9f,-.9f}};for(int i=0;i<4;i++){memcpy(vertices[i].position,xy[i],8);vertices[i].position[2]=.6f;vertices[i].normal[2]=-1;vertices[i].weights[0]=1;for(int k=0;k<4;k++)vertices[i].color[k]=vertices[i].color1[k]=1;}}
static A2MeshHandle mesh(A2MeshBackend *b){A2MeshHandle h=a2_mesh_create(b,vertices,4,indices,6,A2_MESH_INDEX_U16);assert(h);return h;}
static void center(int r,int g,int b){const uint8_t *p=pixels+4*(32*64+32);assert(abs(p[0]-r)<=1&&abs(p[1]-g)<=1&&abs(p[2]-b)<=1);assert(p[3]==255);assert(owners[32*64+32]==91);assert(fabsf(depths[32*64+32]-.6f)<1e-6f);}
/* A frozen old/new backend writes all three complete targets for unchanged
 * zero-default chest material paths. Never compare only a checksum of color. */
static void legacy(A2MeshBackend *b,A2MeshFrame *f,const char *path){
 FILE *out=fopen(path,"wb");assert(out);init_vertices();for(int i=0;i<4;i++){vertices[i].uv1[0]=(i==1||i==2)?1:0;vertices[i].uv1[1]=i>=2?1:0;for(int k=0;k<3;k++){vertices[i].color[k]=.1f+.17f*k;vertices[i].color1[k]=.2f+.13f*k;}}
 A2MeshHandle h=mesh(b);const uint8_t texels[]={160,71,11,0,90,120,64,128,240,178,40,255,19,63,192,255};A2MeshHandle t=a2_mesh_texture_create(b,2,2,texels,8);assert(t);
 for(int mode=0;mode<12;mode++){A2MeshDraw d[2]={draw(h),draw(h)};d[0].material.shader=mode&1;d[0].material.texture=t;d[0].material.texture_srgb=(mode>>1)&1;d[1]=d[0];d[1].model.m[0]=.37f;d[1].model.m[5]=.42f;d[1].model.m[11]=-.2f;d[1].owner_tag=101;f->encode_srgb=(mode>>2)&1;assert(a2_mesh_render(b,f,d,2));read_image(b);assert(fwrite(pixels,1,sizeof pixels,out)==sizeof pixels);assert(fwrite(depths,1,sizeof depths,out)==sizeof depths);assert(fwrite(owners,1,sizeof owners,out)==sizeof owners);}
 fclose(out);assert(a2_mesh_destroy(b,h));assert(a2_mesh_texture_destroy(b,t));
}
int main(int argc,char **argv){@autoreleasepool{
 if(!MTLCreateSystemDefaultDevice())return 77;char error[512]={0};A2MeshBackend *b=a2_mesh_backend_create(64,64,error,sizeof error);if(!b)fprintf(stderr,"%s\n",error);assert(b);
 A2MeshFrame f={0};f.view_projection=identity();f.clear_depth=1;f.camera_world[2]=-3;
 if(argc==3&&!strcmp(argv[1],"--legacy")){legacy(b,&f,argv[2]);a2_mesh_backend_destroy(b);return 0;}
 init_vertices();for(int i=0;i<4;i++)for(int k=0;k<3;k++)vertices[i].color[k]=-1;
 A2MeshHandle h=mesh(b);A2MeshDraw d=draw(h);d.material.shader=A2_MESH_LIT_CONSTANT;d.material.base_color[0]=.4f;d.material.base_color[1]=.2f;d.material.base_color[2]=.1f;
 assert(a2_mesh_render(b,&f,&d,1));read_image(b);assert(pixels[4*(32*64+32)]>10);memcpy(saved,pixels,sizeof saved);
 /* Constant Principled color must ignore all signed source corner channels. */
 assert(a2_mesh_destroy(b,h));for(int i=0;i<4;i++)for(int k=0;k<3;k++)vertices[i].color[k]=16;
 h=mesh(b);d.mesh=h;assert(a2_mesh_render(b,&f,&d,1));read_image(b);assert(!memcmp(saved,pixels,sizeof saved));
 d.material.roughness=.1f;d.material.metallic=1;assert(a2_mesh_render(b,&f,&d,1));read_image(b);assert(memcmp(saved,pixels,sizeof saved));
 /* The same image must follow inverse-transpose normals with a nonuniform
  * skinned scale, compared to an independently pretransformed mesh normal. */
 assert(a2_mesh_destroy(b,h));init_vertices();for(int i=0;i<4;i++){vertices[i].normal[0]=.6f;vertices[i].normal[2]=-.8f;}h=mesh(b);d=draw(h);d.material.shader=A2_MESH_LIT_CONSTANT;
 A2MeshMat4 joint=identity();joint.m[0]=2;joint.m[5]=.5f;d.joints=&joint;d.joint_count=1;d.model.m[0]=.5f;d.model.m[5]=2;
 /* Include an uncompensated Z scale: source normal (0.6,0,-0.8) becomes
  * (0.6,0,-0.4), independently encoded below, with identical positions. */
 joint.m[10]=2;d.model.m[11]=-.6f;
 assert(a2_mesh_render(b,&f,&d,1));read_image(b);memcpy(saved,pixels,sizeof saved);assert(a2_mesh_destroy(b,h));
 for(int i=0;i<4;i++){vertices[i].normal[0]=.6f;vertices[i].normal[2]=-.4f;}
 h=mesh(b);d=draw(h);d.material.shader=A2_MESH_LIT_CONSTANT;assert(a2_mesh_render(b,&f,&d,1));read_image(b);assert(!memcmp(saved,pixels,sizeof saved));assert(a2_mesh_destroy(b,h));
 /* Signed channels are mixed before output clamping. -0.25 + atlas alpha
  * must produce a positive endpoint; signed UVs repeat rather than clamp. */
 init_vertices();for(int i=0;i<4;i++){vertices[i].uv1[0]=-1.25f;vertices[i].uv1[1]=2.25f;for(int k=0;k<3;k++){vertices[i].color[k]=-.25f;vertices[i].color1[k]=.5f;}}
 h=mesh(b);const uint8_t texels[]={255,0,0,128,0,255,0,128,0,0,255,128,255,255,255,128};A2MeshHandle t=a2_mesh_texture_create(b,2,2,texels,8);assert(t);d=draw(h);d.material.shader=A2_MESH_LAYERED_ATLAS;d.material.texture=t;d.material.address=A2_MESH_REPEAT;
 assert(a2_mesh_render(b,&f,&d,1));read_image(b);center(0,96,0);
 d.material.address=A2_MESH_CLAMP;assert(a2_mesh_render(b,&f,&d,1));read_image(b);center(0,0,96);
 /* Linear sampling must interpolate (four texels average at center); clip
  * returns black alpha outside, so the opaque atlas still keeps its base. */
 assert(a2_mesh_destroy(b,h));for(int i=0;i<4;i++){vertices[i].uv1[0]=vertices[i].uv1[1]=.5f;for(int k=0;k<3;k++)vertices[i].color[k]=.2f;}h=mesh(b);d.mesh=h;d.material.filter=A2_MESH_LINEAR;assert(a2_mesh_render(b,&f,&d,1));read_image(b);center(89,89,89);
 /* sRGB texels decode before linear interpolation: primaries still average
  * to linear .5. A post-filter decode would incorrectly yield .214. */
 d.material.texture_srgb=1;assert(a2_mesh_render(b,&f,&d,1));read_image(b);center(89,89,89);d.material.texture_srgb=0;
 assert(a2_mesh_destroy(b,h));for(int i=0;i<4;i++)vertices[i].uv1[0]=-2;h=mesh(b);d.mesh=h;d.material.address=A2_MESH_CLIP;assert(a2_mesh_render(b,&f,&d,1));read_image(b);center(51,51,51);
 /* Lit shield consumes the same alpha blend, then the actual alpha-height
  * derivatives alter lighting only; depth and owner stay byte-identical. */
 assert(a2_mesh_destroy(b,h));init_vertices();for(int i=0;i<4;i++){vertices[i].uv1[0]=(i==1||i==2)?1:0;vertices[i].uv1[1]=i>=2?1:0;for(int k=0;k<3;k++){vertices[i].color[k]=.46f;vertices[i].color1[k]=.5f;}}
 h=mesh(b);const uint8_t bumptex[]={128,128,128,0,128,128,128,255,128,128,128,0,128,128,128,255};A2MeshHandle bt=a2_mesh_texture_create(b,2,2,bumptex,8);assert(bt);d=draw(h);d.material.shader=A2_MESH_LIT_SHIELD;d.material.texture=bt;d.material.filter=A2_MESH_LINEAR;d.material.address=A2_MESH_CLIP;d.material.metallic=.93f;d.material.roughness=.31f;
 assert(a2_mesh_render(b,&f,&d,1));read_image(b);memcpy(saved,pixels,sizeof saved);float olddepth[4096];uint32_t oldowner[4096];memcpy(olddepth,depths,sizeof depths);memcpy(oldowner,owners,sizeof owners);
 d.material.bump_strength=.2f;d.material.bump_distance=.06f;d.material.bump_invert=1;assert(a2_mesh_render(b,&f,&d,1));read_image(b);assert(memcmp(saved,pixels,sizeof saved));assert(!memcmp(olddepth,depths,sizeof depths)&&!memcmp(oldowner,owners,sizeof owners));
 /* Mixed 50-submesh Flint + two chest draws; per-draw constants/owner cannot
  * bleed into the final chest. Every draw is submitted, including late ones. */
 A2MeshDraw batch[52];for(int i=0;i<52;i++){batch[i]=d;batch[i].owner_tag=(unsigned)i+1;batch[i].depth_test=0;batch[i].material.shader=i<50?A2_MESH_LIT_CONSTANT:A2_MESH_PLAIN;batch[i].material.texture=0;batch[i].material.bump_strength=0;batch[i].material.bump_distance=0;batch[i].material.base_color[0]=i==51?.2f:.8f;}
 assert(a2_mesh_render(b,&f,batch,52));read_image(b);assert(owners[32*64+32]==52);
 memcpy(saved,pixels,sizeof saved);d.material.filter=(A2MeshFilter)2;assert(!a2_mesh_render(b,&f,&d,1));read_image(b);assert(!memcmp(saved,pixels,sizeof saved));d.material.filter=A2_MESH_LINEAR;d.material.address=(A2MeshAddress)3;assert(!a2_mesh_render(b,&f,&d,1));d.material.address=A2_MESH_CLIP;d.material.bump_distance=NAN;assert(!a2_mesh_render(b,&f,&d,1));
 /* Bounds are inclusive; out-of-range RGB and alpha are rejected at upload. */
 vertices[0].color[0]=-16;A2MeshHandle edge=mesh(b);assert(a2_mesh_destroy(b,edge));vertices[0].color[0]=nextafterf(-16,-INFINITY);assert(!a2_mesh_create(b,vertices,4,indices,6,A2_MESH_INDEX_U16));vertices[0].color[0]=0;vertices[0].color1[3]=1.01f;assert(!a2_mesh_create(b,vertices,4,indices,6,A2_MESH_INDEX_U16));
 a2_mesh_backend_destroy(b);puts("PASS: Metal signed UV/RGB, constant albedo, inverse-transpose skin normals, sampler modes, shield bump, material validation, mixed 52-draw ownership");return 0;
}}
