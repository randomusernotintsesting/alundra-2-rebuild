#include "native_mesh_material.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
static void sha(uint8_t *p){const char *s="b6cbf3c4d4cf456f4921dde96ba769d092143e855a282ca5ff87977f309eb720";for(int i=0;i<32;i++){unsigned x;assert(sscanf(s+2*i,"%2x",&x)==1);p[i]=(uint8_t)x;}}
int main(void){
 A2ModelMaterial mats[28]={0};A2ModelTexture textures[3]={0};A2NativeModel model={0};strcpy(model.source_key,"PC00");sha(model.source_sha256);model.material_count=28;model.materials=mats;model.joint_count=19;model.texture_count=3;model.textures=textures;model.file_flags=A2_MODEL_SIGNED_CORNER_RGB;
 for(unsigned i=0;i<3;i++)textures[i].flags=1;
 A2ModelMaterial *m=&mats[0];m->texture[0]=m->texture[1]=UINT32_MAX;m->base_color[0]=.07f;m->base_color[1]=.027f;m->base_color[2]=.01f;m->base_color[3]=1;m->roughness=m->roughness_min=m->roughness_max=.73f;m->alpha_cutoff=.5f;m->opacity=1;m->specular=.5f;m->ior=1.5f;m->coat_roughness=.03f;m->flags=1;strcpy(m->name,"PC00_material_00");
 A2MeshMaterial out;memset(&out,0x4a,sizeof out);assert(a2_mesh_material(&model,0,0,&out));assert(out.shader==A2_MESH_LIT_CONSTANT&&out.base_color[0]==.07f&&out.specular==.5f);A2MeshMaterial good=out;
 m->name[15]='1';assert(!a2_mesh_material(&model,0,0,&out));assert(!memcmp(&out,&good,sizeof out));strcpy(m->name,"PC00_material_00");
 model.source_sha256[0]^=1;assert(!a2_mesh_material(&model,0,0,&out));model.source_sha256[0]^=1;
 textures[1].flags=0;assert(!a2_mesh_material(&model,0,0,&out));textures[1].flags=1;
 model.source_variant=1;assert(!a2_mesh_material(&model,0,0,&out));model.source_variant=0;
 m->roughness=nextafterf(.73f,1);assert(!a2_mesh_material(&model,0,0,&out));m->roughness=.73f;
 m=&mats[19];*m=mats[0];m->kind=1;m->texture[0]=0;m->roughness=m->roughness_min=m->roughness_max=1;m->specular=0;for(int k=0;k<4;k++)m->base_color[k]=1;strcpy(m->name,"PC00_material_19");textures[0].flags=1;
 assert(!a2_mesh_material(&model,19,0,&out));assert(a2_mesh_material(&model,19,91,&out));assert(out.shader==A2_MESH_LAYERED_ATLAS&&out.filter==A2_MESH_NEAREST&&out.address==A2_MESH_REPEAT&&out.texture==91&&out.texture_srgb==1);
 m=&mats[7];*m=mats[19];m->texture[0]=2;m->roughness=m->roughness_min=m->roughness_max=.31f;m->metallic=.93f;m->specular=.5f;strcpy(m->name,"PC00_material_07");textures[2].flags=1;
 assert(a2_mesh_material(&model,7,92,&out));assert(out.shader==A2_MESH_LIT_SHIELD&&out.filter==A2_MESH_LINEAR&&out.address==A2_MESH_CLIP);assert(out.bump_strength==.2f&&fabsf(out.bump_distance-.06f)<1e-7f&&out.bump_invert==1);
 /* Old chest gets only the old defaults, including unlit/clamped sampling. */
 strcpy(model.source_key,"T02");m=&mats[0];assert(a2_mesh_material(&model,0,0,&out));A2MeshMaterial chest={0};memcpy(chest.base_color,m->base_color,sizeof chest.base_color);chest.roughness=m->roughness;chest.metallic=m->metallic;chest.alpha_cutoff=m->alpha_cutoff;assert(!memcmp(&out,&chest,sizeof out));
 m->opacity=.5f;assert(!a2_mesh_material(&model,0,0,&out));m->opacity=1;m->texture[0]=3;assert(!a2_mesh_material(&model,0,1,&out));m->texture[0]=UINT32_MAX;m->metallic=NAN;assert(!a2_mesh_material(&model,0,0,&out));
 puts("PASS: pure qualified PC00 material recipes, rejected identity/record changes, samplers, shield bump units, unchanged opaque chest mapping");return 0;
}
