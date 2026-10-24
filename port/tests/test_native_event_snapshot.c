#include "native_actor_snapshot.h"
#include "fixtures/native_event_fixture.h"
#include <assert.h>
#include <string.h>
static uint8_t ram[0x200000];
static void setup(void){
 memset(ram,0,sizeof ram);event_fixture(ram);
 a2_native_actor_snapshot_init(ram,sizeof ram);a2_native_actor_snapshot_configure(1);
 assert(a2_native_actor_snapshot_source_bind(0x80164330,"FRITTO",event_intro_sha,123));
#ifndef A2_TEST_PRE_EVENT
 a2_native_actor_snapshot_event_reset(0x800ce6e8);
#endif
}
static void build(int omit,int sparse){
 /* RAM was retained after the same descriptor was reused for effects.
  * Restore the exact 8008A0E0 main-submission arena assignment. */
 uint32_t main_arena=0x800d9428;memcpy(ram+0xd76f0+20,&main_arena,4);
#ifdef A2_TEST_PRE_EVENT
 (void)omit;(void)sparse;
 a2_native_actor_snapshot_begin(6000,0x800d9428,0x8008a0ec);
 a2_native_actor_snapshot_instance(0x800ce6e8,0x800d9478);
#else
 a2_native_actor_snapshot_event_begin(6000,0x800d9428);
 a2_native_actor_snapshot_event_instance(0x800ce6e8,0x800d94c8);
 const int32_t root_q12[]={25284608,-4608000,610304};
 a2_native_actor_snapshot_root(0x800ce6e8,root_q12);
 uint32_t cursor=0x800d94c8;
 for(unsigned k=0;k<16;k++){
  if((int)k==omit)continue;
  if(sparse)memmove(ram+(cursor&0x1fffff),ram+0xd94c8+80*k,80);
  a2_native_actor_snapshot_event_part(0x800ce6e8,k,sparse?cursor:0x800d94c8+80*k);
  cursor+=80;
 }
 if(sparse){uint16_t end=0x8000;memcpy(ram+(cursor&0x1fffff),&end,2);}
#endif
}
static const A2ActorFrame *capture(unsigned frame){
 a2_native_actor_snapshot_capture(frame,0x800d76f0,256,160<<16,86<<16);
 return a2_native_actor_snapshot_current();
}
int main(void){
 setup();build(-1,0);const A2ActorFrame *s=capture(6000);
 assert(s->valid&&s->instance_count==1&&s->part_count==16);
#ifdef A2_TEST_PRE_EVENT
 return 0;
#else
 assert(s->source_family==A2_ACTOR_EVENT00);
 const A2ActorInstance *i=&s->instances[0];assert(i->source_family==A2_ACTOR_EVENT00&&i->generation_known&&i->instance_generation);
 assert(i->renderer_root_q12[0]==25284608&&i->renderer_root_q12[1]==-4608000&&i->renderer_root_q12[2]==610304);
 assert(i->clip_frame==19&&i->clip_length==19&&i->animation_state_address==0x800ce7ec);
 for(unsigned k=0;k<16;k++){
  const A2ActorPart *p=&s->parts[k];assert(p->source_mesh_index==k&&p->valid&&p->visible&&p->source_generation==123);
  assert(!strcmp(p->source_key,"FRITTO")&&!memcmp(p->source_sha256,event_intro_sha,32));
  assert(!memcmp(p->raw,ram+0xd94c8+80*k,80));
 }
 uint64_t generation=i->instance_generation,build_generation=s->build_generation;
 assert(capture(6000)->valid);assert(!capture(6001)->valid);
 build(-1,0);s=capture(6001);assert(s->valid&&s->build_generation!=build_generation&&s->instances[0].instance_generation==generation);
 a2_native_actor_snapshot_event_reset(0x800ce6e8);assert(!capture(6001)->valid);
 build(-1,0);s=capture(6001);assert(s->valid&&s->instances[0].instance_generation!=generation);
 /* Native omitted channels have identity but no address/pose. */
 for(unsigned hidden=0;hidden<16;hidden++){
  setup();build((int)hidden,1);s=capture(6000);assert(s->valid);
  const A2ActorPart *p=&s->parts[hidden];assert(!p->visible&&!p->valid&&!p->address&&p->source_generation==123&&p->source_mesh_index==hidden);
  for(unsigned k=0;k<16;k++)if(k!=hidden)assert(s->parts[k].visible&&s->parts[k].valid);
 }
 /* An omitted observation of an actually present native part is not a hidden channel. */
 setup();build(7,0);assert(!capture(6000)->valid);
 setup();build(-1,0);ram[0xd94c8+32]^=1;assert(!capture(6000)->valid);
 setup();build(-1,0);ram[0x88a04]^=1;assert(!capture(6000)->valid);
 setup();build(-1,0);ram[0xd76f0+20]^=4;assert(!capture(6000)->valid);
 setup();build(-1,0);a2_native_actor_snapshot_event_part(0x800ce6e8,0,0x800d94c8);assert(!capture(6000)->valid);
 setup();build(-1,0);a2_native_actor_snapshot_event_part(0x800ce6e8,16,0x800d99c8);assert(!capture(6000)->valid);
 setup();build(-1,0);a2_native_actor_snapshot_event_part(0x800ce6ec,0,0x800d94c8);assert(!capture(6000)->valid);
 setup();uint16_t huge=257;memcpy(ram+0xce6e8+266,&huge,2);
 a2_native_actor_snapshot_event_begin(6000,0x800d9428);a2_native_actor_snapshot_event_instance(0x800ce6e8,0x800d94c8);assert(!capture(6000)->valid);
 puts("EVENT snapshot: exact RAM06000 source/16 matrices/root/clip, sparse16hidden cases, missed-hook/stale/mutation/source-code/overflow/lifetime rejection pass");
 return 0;
#endif
}
