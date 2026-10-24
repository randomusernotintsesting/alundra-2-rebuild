#include "native_mesh_scene.h"
#include "native_flint.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static uint32_t u32(FILE *f) { unsigned char b[4];assert(fread(b,1,4,f)==4);return (uint32_t)b[0]|(uint32_t)b[1]<<8|(uint32_t)b[2]<<16|(uint32_t)b[3]<<24; }
static int identity(const A2MeshMat4 *m) {for(unsigned i=0;i<16;i++)if(m->m[i]!=(float)(i%5==0))return 0;return 1;}
static A2NativeModel *model(const char *path) {
 FILE *f=fopen(path,"rb");assert(f);assert(!fseek(f,0,SEEK_END));long n=ftell(f);assert(n>0);rewind(f);
 void *b=malloc((size_t)n);assert(b);assert(fread(b,1,(size_t)n,f)==(size_t)n);fclose(f);
 A2NativeModel *m=NULL;char e[256];assert(a2_native_model_decode(b,(size_t)n,&m,e,sizeof e));free(b);return m;
}
static void checks(const A2ActorPacketOwner *src,A2NativeModel *m,const A2MeshMat4 *actor,const A2MeshMat4 skin[19],const unsigned map[16]) {
 A2ActorPacketOwner o=*src;A2MeshMat4 a,b[19];
 assert(a2_flint_owner_supported(&o,m));
 /* EVENT numerically matching a gameplay walk phase still uses native motion. */
 o.instance.animation_clock_known=1;o.instance.animation_selector=5;o.instance.clip_frame=0;
 o.instance.clip_length=24;o.instance.animation_flags=0;o.instance.action_id=2;
 assert(a2_flint_pose(&o,m,&a,b,19));assert(!memcmp(&a,actor,sizeof a)&&!memcmp(b,skin,sizeof b));
 assert(!memcmp(&b[17],&b[10],sizeof b[0])&&!memcmp(&b[18],&b[13],sizeof b[0]));
 memset(o.camera_origin_q12,0x34,sizeof o.camera_origin_q12);memset(o.instance.orientation,0x45,sizeof o.instance.orientation);
 assert(a2_flint_pose(&o,m,&a,b,19));assert(!memcmp(&a,actor,sizeof a)&&!memcmp(b,skin,sizeof b));
 o=*src;o.instance.renderer_root_q12[0]+=4096*32;
 for(unsigned i=0;i<o.instance.part_count;i++)o.parts[i].translation0[0]+=32;
 assert(a2_flint_pose(&o,m,&a,b,19));assert(!memcmp(b,skin,sizeof b));assert(a.m[3]==actor->m[3]+32);
 for(unsigned hidden=0;hidden<o.instance.part_count;hidden++) {
  o=*src;o.parts[hidden].visible=o.parts[hidden].valid=0;o.parts[hidden].fallback=~0u;
  memset(o.parts[hidden].matrix_q12,0xa5,sizeof o.parts[hidden].matrix_q12);
  assert(a2_flint_pose(&o,m,&a,b,19));for(unsigned i=0;i<19;i++)for(unsigned k=0;k<16;k++)assert(isfinite(b[i].m[k]));
  if(hidden==map[14])assert(identity(&b[14]));
  if(hidden==map[6]||hidden==map[7])assert(identity(&b[16]));
  if(hidden==map[15])for(unsigned sub=0;sub<50;sub++)
   assert(a2_flint_submesh_visible(&o,m,sub)==(!((sub>=37&&sub<=40)||sub>=44)&&(map[14]<o.instance.part_count||sub<41||sub>43)));
 }
 o=*src;
 for(unsigned i=0;i<o.instance.part_count;i++) {
  unsigned consumed=0;for(unsigned j=0;j<16;j++)if(map[j]==i)consumed=1;
  assert(a2_flint_source_part_replaced(&o,i)==(int)consumed);
 }
 assert(!a2_flint_source_part_replaced(&o,o.instance.part_count));
#define BAD() do { a=*actor;memcpy(b,skin,sizeof b);assert(!a2_flint_owner_supported(&o,m));assert(!a2_flint_pose(&o,m,&a,b,19));assert(!memcmp(&a,actor,sizeof a)&&!memcmp(b,skin,sizeof b)); } while(0)
 o=*src;o.parts[0].source_sha256[0]^=1;BAD();
 o=*src;o.parts[0].source_mesh_index=1;BAD();
 o=*src;o.parts[0].valid=0;BAD();
 o=*src;o.parts[0].vertex_override_address=4;BAD();
 o=*src;o.instance.part_count=32;BAD();
 o=*src;o.instance.source_family=A2_ACTOR_GAME00;BAD();
 o=*src;o.instance.generation_known=0;BAD();
#undef BAD
}
int main(int argc,char **argv) {
 assert(argc==4);A2NativeModel *m=model(argv[1]);FILE *in=fopen(argv[2],"rb"),*out=fopen(argv[3],"wb");assert(in&&out);
 unsigned count=u32(in);
 for(unsigned sample=0;sample<count;sample++) {
  A2ActorPacketOwner o={0};o.instance.source_family=A2_ACTOR_EVENT00;o.instance.valid=o.instance.generation_known=1;
  o.instance.part_count=u32(in);assert(o.instance.part_count<=A2_ACTOR_PACKET_PART_LIMIT);unsigned char sha[32];assert(fread(sha,1,32,in)==32);
  for(unsigned k=0;k<3;k++)o.instance.renderer_root_q12[k]=(int32_t)u32(in);
  unsigned map[16];for(unsigned j=0;j<16;j++)map[j]=u32(in);
  for(unsigned j=0;j<o.instance.part_count;j++) {
   A2ActorPart *p=&o.parts[j];p->source_mesh_index=(uint16_t)j;strcpy(p->source_key,"FRITTO");memcpy(p->source_sha256,sha,32);
   for(unsigned k=0;k<9;k++)p->matrix_q12[k]=(int16_t)u32(in);
   for(unsigned k=0;k<3;k++)p->pretranslation[k]=(int16_t)u32(in);
   for(unsigned k=0;k<3;k++)p->translation0[k]=(int32_t)u32(in);
   for(unsigned k=0;k<3;k++)p->translation1[k]=(int32_t)u32(in);
   p->valid=p->visible=1;
  }
  A2MeshMat4 actor,skin[19];assert(a2_flint_owner_supported(&o,m));assert(a2_flint_pose(&o,m,&actor,skin,19));
  checks(&o,m,&actor,skin,map);
  assert(fwrite(actor.m,sizeof(float),16,out)==16);assert(fwrite(skin,sizeof skin,1,out)==1);
 }
 assert(fgetc(in)==EOF);fclose(in);assert(!fclose(out));a2_native_model_destroy(m);
 printf("EVENT retarget: %u samples; source qualification, hidden/equipment/extras, root, camera, native timing, finite and atomic rejection passed\n",count);return 0;
}
