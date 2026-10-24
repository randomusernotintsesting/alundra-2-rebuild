/* Host tag transport with explicit synthetic camera certificates. Real GTE,
 * original source records and actor ownership are separate runtime gates. */
#include "world_precision.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#ifdef A2_SHARED_BASELINE
/* Model N's absent sharing: retain the original strict per-part API. */
static int world_precision_share_record(uint32_t a,uint32_t w,uint64_t g,uint64_t id,uint64_t s){(void)a;(void)w;(void)g;(void)id;(void)s;return 1;}
#define world_precision_emit_actor(d,w,s,n,g,o) world_precision_emit(d,w,s,n,g)
#define world_precision_frontface_actor(s,w,g,t,o,f) world_precision_frontface(s,w,g,t,f)
#endif
static uint32_t source[4]={0x80120004,0x1f800000,0x1f800010,0x80120014};
static const uint32_t destination[4]={0x8009000c,0x80090018,0x80090024,0x80090030};
static const double x[4]={10.25,30.25,30.25,10.25},y[4]={10.25,10.25,30.25,30.25};
static uint32_t words[4];static uint64_t parent,child;static world_precision_vertex values[4];
static const uint64_t owner_scope=42;
static uint32_t actor_producer=0x8001338c;
static void vertex(unsigned i,uint64_t object){
 words[i]=(uint16_t)(int)x[i]|((uint32_t)(uint16_t)(int)y[i]<<16);
 world_precision_producer_pc=actor_producer;
 world_precision_gte_push(words[i],(int64_t)(x[i]*65536),(int64_t)(y[i]*65536),600.5+i,1);
 assert(world_precision_gte_read(14,words[i],&values[i]));
 values[i].projection_kind=WORLD_PROJECTION_CAMERA;values[i].camera_generation=object;
 world_precision_record(source[i],words[i],object,&values[i]);
}
static void setup(void){
 world_precision_configure(1);world_camera_configure(1);
 parent=world_precision_begin_object();vertex(0,parent);vertex(3,parent);
 assert(world_precision_share_record(source[0],words[0],parent,values[0].projection_id,owner_scope));
 assert(world_precision_share_record(source[3],words[3],parent,values[3].projection_id,owner_scope));
 child=world_precision_begin_object();vertex(1,child);vertex(2,child);
}
static void revoked(void){
 world_precision_vertex value;
 for(unsigned i=0;i<4;i++)assert(!world_precision_packet(destination[i],words[i],&value));
}
static void loan_and_local_lifetime(void){
 setup();assert(!world_precision_emit(destination,words,source,4,child));
 assert(world_precision_emit_actor(destination,words,source,4,child,owner_scope));
 uint64_t packet_generation=0;
 for(unsigned i=0;i<4;i++){
  world_precision_vertex v;assert(world_precision_packet(destination[i],words[i],&v));
  assert(v.x==values[i].x&&v.y==values[i].y&&v.z==values[i].z);
  assert(v.projection_id==values[i].projection_id&&v.camera_generation==child);
  assert(v.source_address==(source[i]&0x1fffffff));
  if(i)assert(v.generation==packet_generation);packet_generation=v.generation;
 }
 int front=-1;
 for(unsigned tri=0;tri<2;tri++){
  assert(!world_precision_frontface(source,words,child,tri,&front));
  assert(world_precision_frontface_actor(source,words,child,tri,owner_scope,&front)&&front);
 }
 assert(!world_precision_emit_actor(destination,words,source,4,child,owner_scope+1));revoked();
 assert(!world_precision_frontface_actor(source,words,child,0,owner_scope+1,&front));
 /* Even the same actor owner cannot lend another part's local scratch. */
 uint64_t later=world_precision_begin_object();
 assert(!world_precision_emit_actor(destination,words,source,4,later,owner_scope));revoked();
 assert(!world_precision_share_record(source[1],words[1],child,values[1].projection_id,owner_scope));
}
static void complete_record_writes(void){
 for(unsigned slot=0;slot<2;slot++)for(unsigned byte=0;byte<16;byte++){
  setup();uint32_t a=source[slot?3:0]+byte;
  world_precision_invalidate(a,1); /* Same-value writes also take this path. */
  assert(!world_precision_emit_actor(destination,words,source,4,child,owner_scope));revoked();
 }
 setup();world_precision_invalidate(source[0]-1,1);
 assert(world_precision_emit_actor(destination,words,source,4,child,owner_scope));
 setup();world_precision_invalidate(source[3]+16,1);
 assert(world_precision_emit_actor(destination,words,source,4,child,owner_scope));
 setup();world_precision_invalidate((source[0]&0x1fffff)+0x200000+8,4);
 assert(!world_precision_emit_actor(destination,words,source,4,child,owner_scope));revoked();
}
static void invalid_certificates(void){
 for(unsigned bad=0;bad<8;bad++){
  setup();world_precision_vertex v=values[0];
  if(bad==0)v.projection_kind=WORLD_PROJECTION_NATIVE_Q16;
  if(bad==1)v.camera_generation=child;
  if(bad==2)v.producer_pc=0x80010d4c;
  if(bad==7)v.producer_pc=0x80010d54;
  world_precision_record(source[0],words[0],parent,&v);
  uint32_t address=source[0],word=words[0];uint64_t object=parent,scope=owner_scope;
  if(bad==3)object=child;
  if(bad==4)scope=0;
  if(bad==5)word^=1;
  uint64_t id=values[0].projection_id;if(bad==6)id++;
  assert(!world_precision_share_record(address,word,object,id,scope));
  assert(!world_precision_emit_actor(destination,words,source,4,child,owner_scope));revoked();
 }
 setup();world_precision_reset();
 assert(!world_precision_emit_actor(destination,words,source,4,child,owner_scope));revoked();
 /* A later ordinary record at the same address cannot inherit its old scope. */
 setup();world_precision_record(source[0],words[0],parent,&values[0]);
 assert(!world_precision_emit_actor(destination,words,source,4,child,owner_scope));revoked();
}
static unsigned tag_index(uint32_t a){a&=0x1fffff;return ((a>>2)^(a>>17))&32767;}
static void collision_lifetime(void){
 setup();uint32_t other=0;
 for(uint32_t a=0x40000;a<0x100000;a+=4)if(tag_index(a)==tag_index(source[0])){other=0x80000000u|a;break;}
 assert(other && other!=source[0]);
 world_precision_vertex v=values[0];uint64_t another=world_precision_begin_object();v.camera_generation=another;
 world_precision_record(other,words[0],another,&v);
 uint32_t loan[4]={other,source[1],source[2],source[3]};
 assert(!world_precision_emit_actor(destination,words,loan,4,child,owner_scope));revoked();
 /* Restoring an ordinary record cannot resurrect a scope evicted by a collision. */
 world_precision_record(source[0],words[0],parent,&values[0]);
 assert(!world_precision_emit_actor(destination,words,source,4,child,owner_scope));revoked();
}
int main(void){
 const uint32_t producers[]={0x8001338c,0x80013424};
 for(unsigned profile=0;profile<2;profile++)for(unsigned align=0;align<16;align+=4){
  actor_producer=producers[profile];
  source[0]=0x80120000+align;source[3]=source[0]+16;
  loan_and_local_lifetime();complete_record_writes();invalid_certificates();collision_lifetime();
  for(unsigned alias=0;alias<4;alias++)for(unsigned offset=0;offset<16;offset+=2){
   setup();world_precision_invalidate((source[0]&0x1fffff)+alias*0x200000+offset,2);
   assert(!world_precision_emit_actor(destination,words,source,4,child,owner_scope));revoked();
  }
 }
 puts("GAME/EVENT shared actor tags: exact XYZ/projection identity, consumer camera certificate, strict local lifetime,16-byte same-value invalidation, scopes and culling pass");return 0;
}
