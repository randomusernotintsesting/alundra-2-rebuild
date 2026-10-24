/* Optional real cooked-artifact qualification. No fixture path is built in.
 * Usage: verify_mesh_materials_macos PC00.A2M [rgba-depth-owner.bin] */
#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#include "native_mesh_material.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static A2MeshMat4 identity(void){A2MeshMat4 a={0};for(int i=0;i<4;i++)a.m[i*5]=1;return a;}
int main(int argc,char **argv){@autoreleasepool{
 assert(argc==2||argc==3);if(!MTLCreateSystemDefaultDevice())return 77;FILE *file=fopen(argv[1],"rb");assert(file);assert(!fseek(file,0,SEEK_END));long size=ftell(file);assert(size>0);rewind(file);void *bytes=malloc((size_t)size);assert(bytes&&fread(bytes,1,(size_t)size,file)==(size_t)size);fclose(file);
 char error[512]={0};A2NativeModel *model=NULL;assert(a2_native_model_decode(bytes,(size_t)size,&model,error,sizeof error));free(bytes);
 assert(!strcmp(model->source_key,"PC00")&&model->material_count==28&&model->submesh_count==50&&model->joint_count==19);
 A2MeshMaterial materials[28];for(unsigned i=0;i<28;i++){A2MeshHandle placeholder=model->materials[i].texture[0]==UINT32_MAX?0:1;assert(a2_mesh_material(model,i,placeholder,&materials[i]));}
 A2MeshBackend *b=a2_mesh_backend_create(128,128,error,sizeof error);if(!b)fprintf(stderr,"%s\n",error);assert(b);
 A2MeshVertex *v=calloc(model->vertex_count,sizeof *v);assert(v);for(unsigned i=0;i<model->vertex_count;i++){const A2ModelVertex *s=&model->vertices[i];A2MeshVertex *d=&v[i];memcpy(d->position,s->position,sizeof d->position);memcpy(d->normal,s->normal,sizeof d->normal);memcpy(d->uv,s->uv[0],sizeof d->uv);memcpy(d->uv1,s->uv[1],sizeof d->uv1);memcpy(d->color,s->color[0],sizeof d->color);memcpy(d->color1,s->color[1],sizeof d->color1);memcpy(d->joints,s->joints,sizeof d->joints);memcpy(d->weights,s->weights,sizeof d->weights);}
 A2MeshHandle mesh=a2_mesh_create(b,v,model->vertex_count,model->indices,model->index_count,(A2MeshIndexType)model->index_width);free(v);assert(mesh);A2MeshHandle textures[3];for(unsigned i=0;i<3;i++){A2ModelTexture *t=&model->textures[i];textures[i]=a2_mesh_texture_create(b,t->width,t->height,t->rgba,(size_t)t->width*4);assert(textures[i]);}
 A2MeshMat4 joints[19];for(unsigned i=0;i<19;i++)joints[i]=identity();A2MeshDraw draws[50]={0};for(unsigned i=0;i<50;i++){A2ModelSubmesh *s=&model->submeshes[i];A2MeshDraw *d=&draws[i];d->mesh=mesh;d->first_index=s->first_index;d->index_count=s->index_count;d->model=identity();d->joints=joints;d->joint_count=19;uint32_t t=model->materials[s->material].texture[0];assert(a2_mesh_material(model,s->material,t==UINT32_MAX?0:textures[t],&d->material));d->depth_test=d->depth_write=d->color_write=1;d->owner_tag=1;}
 A2MeshFrame frame={0};frame.view_projection=identity();frame.view_projection.m[0]=.008f;frame.view_projection.m[5]=-.008f;frame.view_projection.m[7]=-.75f;frame.view_projection.m[10]=.002f;frame.view_projection.m[11]=.5f;frame.clear_depth=1;frame.encode_srgb=1;frame.camera_world[1]=-70;frame.camera_world[2]=-300;
 assert(a2_mesh_render(b,&frame,draws,50));uint8_t rgba[128*128*4];float depth[128*128];uint32_t owners[128*128];assert(a2_mesh_readback(b,rgba,sizeof rgba,512,depth,sizeof depth,512));assert(a2_mesh_readback_owners(b,owners,sizeof owners,512));unsigned covered=0;for(unsigned i=0;i<128*128;i++)if(owners[i]){assert(owners[i]==1&&depth[i]>0&&depth[i]<1);covered++;}assert(covered>1000);
 if(argc==3){FILE *out=fopen(argv[2],"wb");assert(out);assert(fwrite(rgba,1,sizeof rgba,out)==sizeof rgba);assert(fwrite(depth,1,sizeof depth,out)==sizeof depth);assert(fwrite(owners,1,sizeof owners,out)==sizeof owners);fclose(out);}
 printf("PASS: actual PC00 %u vertices, %u triangles, 28 checked recipes, 3 samplers/textures, 19 identity skin drivers, all 50 submeshes submitted, %u owned pixels\n",model->vertex_count,model->index_count/3,covered);
 a2_mesh_backend_destroy(b);a2_native_model_destroy(model);return 0;
}}
