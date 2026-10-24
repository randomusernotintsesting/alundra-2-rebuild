/* Retained AL22 emitter, real memory helpers, no GPU/native game. Snapshot
 * dependency is a copied, source-bound closed/open T02 fixture. Lifetime and
 * source-bind observations themselves are tested by their own modules. */
#define A2_NATIVE_ACTOR_PACKETS 1
#include "native_actor_packets.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "fixtures/native_chest_packets.h"
#include "fixtures/native_pc00_fixture.h"
#include "native_actor_source_layout.h"
#include "../src/psx_rt.h"
#include "../src/gte.c"
#include "../src/interp.c"
uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
uint32_t R[32],HI,LO,psx_next,psx_work,psx_frame_no=16750,a2_ramwatch;
int psx_bb_budget=1000000;
void a2_ramwatch_hit(uint32_t a,uint32_t v,int n){(void)a;(void)v;(void)n;}
uint32_t psx_mmio_read(uint32_t a,int n){(void)a;(void)n;return 0;}
void psx_mmio_write(uint32_t a,uint32_t v,int n){(void)a;(void)v;(void)n;}
uint32_t psx_cop0_read(int r){(void)r;return 0;}
void psx_cop0_write(int r,uint32_t v){(void)r;(void)v;}
void psx_rfe(void){}
void psx_syscall_at(uint32_t pc){(void)pc;abort();}
void psx_break(uint32_t c){(void)c;abort();}
void psx_bb_fire(void){psx_bb_budget=1000000;}
int a2_wide(void){return 0;}
static A2ActorFrame snapshot;
static unsigned selected_instance;
/* Controlled emitter-register fault; source RAM remains unchanged. */
static uint32_t fixture_color_override;
const A2ActorFrame *a2_native_actor_snapshot_current(void){return &snapshot;}
static uint32_t pack(int x,int y){return (uint16_t)x|((uint32_t)(uint16_t)y<<16);}
static void setup(int open){
 memset(PSX_RAM,0,sizeof PSX_RAM);memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);memset(R,0,sizeof R);
 memcpy(PSX_RAM+0x10000,chest_al22,sizeof chest_al22);
 memcpy(PSX_RAM+0x1ab464,chest_registry,sizeof chest_registry);
 memcpy(PSX_RAM+0x1ec5a0,chest_closed_parts,sizeof chest_closed_parts);
 if(open)memcpy(PSX_RAM+0x1ec5f0,chest_open_lid,80);
 memset(&snapshot,0,sizeof snapshot);snapshot.sequence=1;snapshot.guest_frame=16750;snapshot.build_generation=1;
 selected_instance=0;
 snapshot.valid=1;snapshot.instance_count=1;snapshot.part_count=2;snapshot.draw_object_address=0x8011763c;
 A2ActorInstance *i=&snapshot.instances[0];i->entity_address=0x80119a34;i->registry_address=0x801ab464;
 i->instance_generation=77;i->generation_known=1;i->valid=1;i->selected_for_draw=1;i->part_count=2;
 i->actor_world_q12[0]=2293760;i->actor_world_q12[2]=3522560;
 memcpy(i->renderer_root_q12,i->actor_world_q12,sizeof i->renderer_root_q12);
 for(unsigned k=0;k<2;k++){
  A2ActorPart *p=&snapshot.parts[k];p->address=0x801ec5a0+k*80;p->registry_address=i->registry_address;
  p->source_mesh_index=k;p->flags=0x2000;p->source_generation=41;p->valid=p->visible=1;
  strcpy(p->source_key,"T02");
  const unsigned char sha[32]={0xfb,0xbc,0x6e,0xd2,0x0a,0x3f,0xc8,0xcf,0x8a,0xc6,0x9e,0x1c,0x1a,0xf7,0x4a,0x8a,0xe4,0x4d,0x45,0x1f,0xcf,0xbb,0x47,0x30,0x23,0x21,0xc1,0x18,0x2f,0xef,0xab,0xf1};
  memcpy(p->source_sha256,sha,32);memcpy(p->raw,PSX_RAM+(p->address&0x1fffff),80);
  memcpy(p->matrix_q12,p->raw+32,18);memcpy(p->translation0,p->raw+8,12);memcpy(p->translation1,p->raw+20,12);
 }
 a2_native_actor_packets_init(PSX_RAM,sizeof PSX_RAM);a2_native_actor_packets_configure(1);
 R[4]=snapshot.draw_object_address;a2_native_actor_packets_before(0x80012e68,R);
 R[4]=0x800157b0;R[5]=0x1f800000;sw_(R[4]+0x68,snapshot.draw_object_address);
 sw_(R[4]+0x64,0x80110000);sw_(R[4]+0x5f8,0);sw_(R[4]+0x5cc,0);sw_(R[4]+0xab0,0);
 sh_(R[5]+0x3d0,0xffff);sh_(R[5]+0x3d2,0);
}
static unsigned emit(unsigned part,unsigned face_index,unsigned layer,uint32_t base,uint32_t caller){
 R[30]=snapshot.parts[snapshot.instances[selected_instance].first_part+part].address;sw_(R[4]+0x70,R[30]);
 a2_native_actor_packets_before(0x800130f8,R);
 R[3]=lw_(snapshot.instances[selected_instance].registry_address+32+part*4);
 a2_native_actor_packets_before(0x80013194,R);
 uint32_t face=R[3]+24;
 for(unsigned j=0;j<face_index;j++)face+=(lh_(face)&4)?80:44;
 R[3]=face;uint32_t mat=face+(layer?44:8);unsigned command=lw_(mat)>>24;
 const int xy[4][2]={{30,30},{90,30},{90,90},{30,90}};
 for(unsigned j=0;j<4;j++){
  R[16+j*2]=xy[j][0];R[17+j*2]=xy[j][1];
  sw_(R[5]+0x3b8+j*4,0x1f800000+j*16);sw_(0x1f800000+j*16,pack(xy[j][0],xy[j][1]));
  sw_(R[5]+0x3a8+j*4,500);R[8+j]=lw_(mat+j*4);
 }
 R[14]=lw_(mat+16);R[15]=lw_(mat+20);R[24]=lw_(mat+24);
 R[8]^=fixture_color_override;
 R[12]=R[15]>>16;R[13]=R[14]>>16;R[25]=R[24]>>16;
 R[1]=lw_(mat+28);R[2]=base;R[7]=0x80008000;R[30]=0;R[31]=caller;
 psx_interp(0x80013cb8);
 return command&8?(command&4?12:8):(command&4?9:6);
}
static void seal(void){a2_native_actor_packets_before(0x800130c0,R);}
static void restart(void){
 a2_native_actor_packets_reset();R[4]=snapshot.draw_object_address;
 a2_native_actor_packets_before(0x80012e68,R);R[4]=0x800157b0;
}
static unsigned all_faces(void){
 unsigned emitted=0;
 for(unsigned part=0;part<2;part++){
  uint32_t face=lw_(snapshot.instances[0].registry_address+32+part*4)+24;
  for(unsigned index=0;index<9;index++){
   int two=!!(lh_(face)&4);
   if(two)emit(part,index,1,0x800f9000+80*emitted++,0x800137e0);
   emit(part,index,0,0x800f9000+80*emitted++,two?0x80013894:0x80013754);
   face+=two?80:44;
  }
 }
 return emitted;
}
/* A hidden channel has stale pose bytes by design; it still identifies its
 * original source. Only the visible sibling actually visits the emitter. */
static void hidden_source_case(unsigned hidden,unsigned flags,int enabled){
 setup(0);A2ActorPart *h=&snapshot.parts[hidden];
 h->valid=h->visible=0;h->fallback=A2_ACTOR_BAD_RECORD;h->flags|=flags;
 sh_(h->address,h->flags);memcpy(h->raw,PSX_RAM+(h->address&0x1fffffu),80);
 a2_native_actor_packets_configure(enabled);restart();
 HI=LO=psx_work=psx_next=0;psx_bb_budget=1000000;
 for(unsigned j=0;j<32;j++){gte_ctrl_write(j,0);gte_data_write(j,0);}
 unsigned n=emit(!hidden,0,0,0x800f9000,0x80013894);seal();
 uint64_t t=a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008));
 if(!enabled){assert(!t);return;}
 assert(t);assert(!a2_native_actor_packets_source_failed("T02",snapshot.parts[0].source_sha256));const A2ActorPacket *p;
 assert(a2_native_actor_packets_consume(0x800f9008,t,(const uint32_t*)(PSX_RAM+0xf9008),n,&p));
 const A2ActorPacketOwner *o=a2_native_actor_packets_owner(p->owner_handle);assert(o);
 assert(p->source_mesh_index==!hidden&&!o->parts[hidden].valid&&!o->parts[hidden].visible);
 assert(o->parts[hidden].fallback==A2_ACTOR_BAD_RECORD);
 assert(!memcmp(o->parts[hidden].raw,h->raw,80));assert(a2_native_actor_packets_owner_complete(o->handle));
}
static void hidden_source_equality(void){
 static uint8_t ram[PSX_RAM_SIZE],scratch[0x400];uint32_t regs[32],gte[64],state[5];
 for(unsigned hidden=0;hidden<2;hidden++)for(unsigned f=0;f<2;f++){
  hidden_source_case(hidden,f?0x200u:1u,0);
  memcpy(ram,PSX_RAM,sizeof ram);memcpy(scratch,PSX_SCRATCH,sizeof scratch);memcpy(regs,R,sizeof regs);
  for(unsigned j=0;j<64;j++)gte[j]=j<32?gte_data_read(j):gte_ctrl_read(j-32);
  state[0]=HI;state[1]=LO;state[2]=psx_work;state[3]=psx_next;state[4]=psx_bb_budget;
  hidden_source_case(hidden,f?0x200u:1u,1);
  assert(!memcmp(ram,PSX_RAM,sizeof ram)&&!memcmp(scratch,PSX_SCRATCH,sizeof scratch)&&!memcmp(regs,R,sizeof regs));
  for(unsigned j=0;j<64;j++)assert(gte[j]==(j<32?gte_data_read(j):gte_ctrl_read(j-32)));
  assert(state[0]==HI&&state[1]==LO&&state[2]==psx_work&&state[3]==psx_next&&state[4]==(uint32_t)psx_bb_budget);
 }
}
static void sealed_source_epoch(void){
 for(unsigned kind=0;kind<3;kind++){
  setup(0);unsigned n=emit(0,0,0,0x800f9000,0x80013894);seal();
  const A2ActorPacketOwner *owners[1];assert(a2_native_actor_packets_owners(16750,owners,1)==1);
  A2ActorPacketOwner saved=*owners[0];
  uint64_t token=a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008));assert(token);
  const uint32_t writes[]={0x801ab464,0x80119a34,0x801ec5a0};
  sb_(writes[kind],lb_(writes[kind])^1); /* Actual later native source/entity/arena reuse. */
  assert(a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008))==token);
  const A2ActorPacketOwner *old=a2_native_actor_packets_owner(saved.handle);assert(old);
  assert(!memcmp(old,&saved,sizeof saved));
  assert(!a2_native_actor_packets_source_failed("T02",snapshot.parts[0].source_sha256));
  const A2ActorPacket *packet;
  assert(a2_native_actor_packets_consume(0x800f9008,token,(const uint32_t*)(PSX_RAM+0xf9008),n,&packet));
  assert(packet->entity_generation==saved.instance.instance_generation&&a2_native_actor_packets_owner_complete(saved.handle));
  /* A new build cannot repurpose the sealed pose at an identical arena address. */
  snapshot.build_generation++;snapshot.sequence++;snapshot.valid=0;
  R[4]=snapshot.draw_object_address;a2_native_actor_packets_before(0x80012e68,R);
  assert(!a2_native_actor_packets_owner(saved.handle));
  assert(!a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008)));
 }
}
static void repeated_packet_identity(void){
 setup(0);unsigned na=emit(0,0,0,0x800f9000,0x80013894);
 unsigned nb=emit(1,0,0,0x800f9050,0x80013894);seal();
 uint64_t ta=a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008));
 uint64_t tb=a2_native_actor_packets_token(0x800f9058,lw_(0x800f9058));assert(ta&&tb&&ta!=tb);
 const A2ActorPacketOwner *unobserved[1];assert(a2_native_actor_packets_owners(16750,unobserved,1)==1);
 assert(!a2_native_actor_packets_owner_complete(unobserved[0]->handle));
 const A2ActorPacket *p=NULL;
 assert(a2_native_actor_packets_consume(0x800f9008,ta,(const uint32_t *)(PSX_RAM+0xf9008),na,&p));
 A2ActorPacket saved=*p;uint64_t owner=p->owner_handle;
 assert(!a2_native_actor_packets_owner_complete(owner));
 /* Repeated rendering retains source identity, but never substitutes for a
  * different packet's first observation in the completion accounting. */
 assert(a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008))==ta);
 assert(a2_native_actor_packets_consume(0x800f9008,ta,saved.words+2,na,&p));
 assert(!memcmp(p,&saved,sizeof saved)&&!a2_native_actor_packets_owner_complete(owner));
 assert(!a2_native_actor_packets_consume(0x800f9008,tb,saved.words+2,na,&p)&&!p);
 assert(!a2_native_actor_packets_consume(0x800f9008,0,saved.words+2,na,&p)&&!p);
 assert(a2_native_actor_packets_consume(0x800f9058,tb,(const uint32_t *)(PSX_RAM+0xf9058),nb,&p));
 assert(p->owner_handle==owner&&a2_native_actor_packets_owner_complete(owner));
 assert(a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008))==ta);
 assert(a2_native_actor_packets_token(0x800f9058,lw_(0x800f9058))==tb);
 /* A forged repeat payload still poisons the whole exact owner. */
 uint32_t forged[12];memcpy(forged,saved.words+2,na*4);forged[1]^=1;
 assert(!a2_native_actor_packets_consume(0x800f9008,ta,forged,na,&p)&&!p);
 assert(!a2_native_actor_packets_owner_complete(owner));
 assert(!a2_native_actor_packets_token(0x800f9058,lw_(0x800f9058)));
 /* Identical bytes at a recycled address belong to a new build/token. */
 snapshot.build_generation++;snapshot.sequence++;R[4]=snapshot.draw_object_address;
 a2_native_actor_packets_before(0x80012e68,R);R[4]=0x800157b0;
 sw_(saved.ot_bucket,saved.previous_head);
 na=emit(0,0,0,0x800f9000,0x80013894);seal();
 assert(!memcmp(PSX_RAM+0xf9000,saved.words,4*(saved.dma_word_count+1)));
 uint64_t next=a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008));assert(next&&next!=ta);
 assert(!a2_native_actor_packets_consume(0x800f9008,ta,(const uint32_t *)(PSX_RAM+0xf9008),na,&p)&&!p);
 assert(a2_native_actor_packets_consume(0x800f9008,next,(const uint32_t *)(PSX_RAM+0xf9008),na,&p));
 assert(p->owner_handle!=owner&&a2_native_actor_packets_owner_complete(p->owner_handle));
}
static void rejected_source_equality(void){
 static uint8_t ram[PSX_RAM_SIZE],scratch[0x400];uint32_t regs[32],gte[64],state[5];
 for(unsigned open=0;open<2;open++)for(unsigned enabled=0;enabled<2;enabled++){
  setup(open);snapshot.instances[0].fallback=A2_ACTOR_MISSING_ROOT;
  a2_native_actor_packets_configure(enabled);restart();
  HI=LO=psx_work=psx_next=0;psx_bb_budget=1000000;
  for(unsigned j=0;j<32;j++){gte_ctrl_write(j,0);gte_data_write(j,0);}
  assert(all_faces()==27);seal();
  assert(a2_native_actor_packets_source_failed("T02",snapshot.parts[0].source_sha256)==(int)enabled);
  if(!enabled){
   memcpy(ram,PSX_RAM,sizeof ram);memcpy(scratch,PSX_SCRATCH,sizeof scratch);memcpy(regs,R,sizeof regs);
   for(unsigned j=0;j<64;j++)gte[j]=j<32?gte_data_read(j):gte_ctrl_read(j-32);
   state[0]=HI;state[1]=LO;state[2]=psx_work;state[3]=psx_next;state[4]=psx_bb_budget;
  }else{
   assert(!memcmp(ram,PSX_RAM,sizeof ram)&&!memcmp(scratch,PSX_SCRATCH,sizeof scratch)&&!memcmp(regs,R,sizeof regs));
   for(unsigned j=0;j<64;j++)assert(gte[j]==(j<32?gte_data_read(j):gte_ctrl_read(j-32)));
   assert(state[0]==HI&&state[1]==LO&&state[2]==psx_work&&state[3]==psx_next&&state[4]==(uint32_t)psx_bb_budget);
  }
 }
}
static void historical_source_invalidation(void){
 for(unsigned code=0;code<2;code++)for(unsigned queued=0;queued<3;queued++){
  setup(0);unsigned count=emit(0,0,0,0x800f9000,0x80013894);seal();
  uint64_t token=a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008));assert(token);
  const A2ActorPacket *packet;uint32_t words[12];memcpy(words,PSX_RAM+0xf9008,count*4);
  assert(a2_native_actor_packets_consume(0x800f9008,token,words,count,&packet));
  uint32_t address=code?0x80010000:0x800f9008;sb_(address,lb_(address));
  /* A copied completed display does not depend on later guest reuse. */
  assert(!a2_native_actor_packets_source_failed("T02",snapshot.parts[0].source_sha256));
  if(queued==1)assert(!a2_native_actor_packets_consume(0x800f9008,token,words,count,&packet));
  else assert(!a2_native_actor_packets_token(0x800f9008,words[0]^(queued==2?0x02020001u:0u)));
  /* Attempting to draw the retired source again must not show its original. */
  assert(a2_native_actor_packets_source_failed("T02",snapshot.parts[0].source_sha256));
 }
 setup(0);unsigned count=emit(0,0,0,0x800f9000,0x80013894);
 emit(1,0,0,0x800f9050,0x80013894);seal();
 uint64_t token=a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008));
 const A2ActorPacket *packet;
 assert(a2_native_actor_packets_consume(0x800f9008,token,(const uint32_t *)(PSX_RAM+0xf9008),count,&packet));
 sb_(0x80010000,lb_(0x80010000));
 assert(a2_native_actor_packets_source_failed("T02",snapshot.parts[0].source_sha256));
}
static void source_failure_cases(void){
 setup(0);snapshot.instances[0].fallback=A2_ACTOR_MISSING_ROOT;restart();
 assert(!a2_native_actor_packets_source_failed("T02",snapshot.parts[0].source_sha256));
 emit(0,0,0,0x800f9000,0x80013894);seal();
 assert(a2_native_actor_packets_source_failed("T02",snapshot.parts[0].source_sha256));
 assert(!a2_native_actor_packets_source_failed("T03",snapshot.parts[0].source_sha256));
 uint8_t wrong[32];memcpy(wrong,snapshot.parts[0].source_sha256,32);wrong[0]^=1;
 assert(!a2_native_actor_packets_source_failed("T02",wrong));
 a2_native_actor_packets_reset();assert(!a2_native_actor_packets_source_failed("T02",snapshot.parts[0].source_sha256));
 setup(0);emit(0,0,0,0x800f9000,0x80013894);seal();
 assert(!a2_native_actor_packets_source_failed("T02",snapshot.parts[0].source_sha256));
 sb_(0x800f9008,lb_(0x800f9008));
 assert(a2_native_actor_packets_source_failed("T02",snapshot.parts[0].source_sha256));
 snapshot.build_generation++;snapshot.sequence++;R[4]=snapshot.draw_object_address;
 a2_native_actor_packets_before(0x80012e68,R);
 assert(!a2_native_actor_packets_source_failed("T02",snapshot.parts[0].source_sha256));
 for(unsigned shadow=0;shadow<2;shadow++){
  setup(0);snapshot.instances[0].fallback=A2_ACTOR_MISSING_ROOT;
  snapshot.shadow_pass=shadow;snapshot.instances[0].selected_for_draw=shadow;
  restart();emit(0,0,0,0x800f9000,0x80013894);seal();
  assert(!a2_native_actor_packets_source_failed("T02",snapshot.parts[0].source_sha256));
 }
}

static void pc00_setup_packets(void){
 setup(0);a2_native_actor_packets_reset();
 pc00_fixture("native_pc00_relocated.bin",PSX_RAM+0x175cb4,31216);
 pc00_fixture("native_pc00_parts.bin",PSX_RAM+0x1ec050,1280);
 snapshot.part_count=16;A2ActorInstance *i=&snapshot.instances[0];
 i->registry_address=0x80175cb4;i->entity_address=0x80119710;i->part_count=16;
 i->animation_selector=6;i->clip_frame=16;i->clip_length=16;i->animation_clock_known=1;
 i->clip_generation=31;i->animation_update_tick=307;i->entity_update_calls=100;
 for(unsigned k=0;k<16;k++){
  A2ActorPart *p=&snapshot.parts[k];memset(p,0,sizeof *p);
  p->address=0x801ec050+80*k;p->registry_address=i->registry_address;
  p->source_mesh_index=k;p->flags=0x2000;p->source_generation=41;p->valid=p->visible=1;
  strcpy(p->source_key,"PC00");memcpy(p->source_sha256,pc00_sha,32);
  memcpy(p->raw,PSX_RAM+(p->address&0x1fffff),80);
  memcpy(p->matrix_q12,p->raw+32,18);memcpy(p->translation0,p->raw+8,12);memcpy(p->translation1,p->raw+20,12);
 }
 restart();
}
static unsigned pc00_all_faces(void){
 static const unsigned counts[16]={57,54,51,34,17,36,45,36,24,4,33,24,4,33,31,16};
 unsigned emitted=0;
 for(unsigned part=0;part<16;part++){
  uint32_t face=lw_(0x80175cb4+32+4*part)+24;
  for(unsigned index=0;index<counts[part];index++){
   unsigned two=!!(lh_(face)&4);
   if(two)emit(part,index,1,0x80060000+80*emitted++,0x800137e0);
   emit(part,index,0,0x80060000+80*emitted++,two?0x80013894:0x80013754);
   face+=two?80:44;
  }
 }
 return emitted;
}
static void pc00_and_chest_packets(void){
 setup(0);A2ActorInstance chest=snapshot.instances[0];A2ActorPart chest_parts[2];
 memcpy(chest_parts,snapshot.parts,sizeof chest_parts);
 pc00_setup_packets();snapshot.instance_count=2;snapshot.part_count=18;
 snapshot.instances[1]=chest;snapshot.instances[1].first_part=16;
 memcpy(snapshot.parts+16,chest_parts,sizeof chest_parts);restart();
 assert(pc00_all_faces()==546);selected_instance=1;
 unsigned total=0;
 for(unsigned part=0;part<2;part++){
  uint32_t face=lw_(chest.registry_address+32+4*part)+24;
  for(unsigned j=0;j<9;j++){
   unsigned two=!!(lh_(face)&4);
   if(two)emit(part,j,1,0x800f9000+80*total++,0x800137e0);
   emit(part,j,0,0x800f9000+80*total++,two?0x80013894:0x80013754);
   face+=two?80:44;
  }
 }
 assert(total==27);seal();const A2ActorPacketOwner *owners[2];
 assert(a2_native_actor_packets_owners_latest(owners,2)==2);
 assert(owners[0]->packet_count==546&&owners[1]->packet_count==27);
 assert(owners[0]->instance.part_count==16&&owners[1]->instance.part_count==2);
 uint64_t chest_token=a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008));assert(chest_token);
 sb_(0x80060008,lb_(0x80060008));
 assert(a2_native_actor_packets_source_failed("PC00",pc00_sha));
 assert(!a2_native_actor_packets_source_failed("T02",chest_parts[0].source_sha256));
 assert(a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008))==chest_token);
 sb_(0x800f9008,lb_(0x800f9008));
 assert(a2_native_actor_packets_source_failed("PC00",pc00_sha));
 assert(a2_native_actor_packets_source_failed("T02",chest_parts[0].source_sha256));
 puts("PC00 + T02: 573 simultaneous original packets, separate owner identity and independent source failure pass");
}
static void pc00_packets(void){
 static uint8_t ram[PSX_RAM_SIZE],scratch[0x400];uint32_t regs[32],gte[64],state[5];
 for(unsigned enabled=0;enabled<2;enabled++){
  pc00_setup_packets();a2_native_actor_packets_configure(enabled);restart();
  HI=LO=psx_work=psx_next=0;psx_bb_budget=1000000;
  for(unsigned j=0;j<32;j++){gte_ctrl_write(j,0);gte_data_write(j,0);}
  assert(pc00_all_faces()==546);seal();
  if(!enabled){
   memcpy(ram,PSX_RAM,sizeof ram);memcpy(scratch,PSX_SCRATCH,sizeof scratch);memcpy(regs,R,sizeof regs);
   for(unsigned j=0;j<64;j++)gte[j]=j<32?gte_data_read(j):gte_ctrl_read(j-32);
   state[0]=HI;state[1]=LO;state[2]=psx_work;state[3]=psx_next;state[4]=psx_bb_budget;
  }else{
   assert(!memcmp(ram,PSX_RAM,sizeof ram)&&!memcmp(scratch,PSX_SCRATCH,sizeof scratch)&&!memcmp(regs,R,sizeof regs));
   for(unsigned j=0;j<64;j++)assert(gte[j]==(j<32?gte_data_read(j):gte_ctrl_read(j-32)));
   assert(state[0]==HI&&state[1]==LO&&state[2]==psx_work&&state[3]==psx_next&&state[4]==(uint32_t)psx_bb_budget);
  }
 }
 const A2ActorPacketOwner *oo[1];assert(a2_native_actor_packets_owners_latest(oo,1)==1);
 const A2ActorPacket *pp[546];assert(a2_native_actor_packets_owner_packets(oo[0]->handle,pp,546)==546);
 A2ActorPacketOwner saved=*oo[0];assert(!memcmp(&saved.instance,&snapshot.instances[0],sizeof saved.instance));
 for(unsigned k=0;k<16;k++)assert(saved.parts[k].source_mesh_index==k&&!memcmp(&saved.parts[k],&snapshot.parts[k],sizeof saved.parts[k]));
 uint64_t first=0;unsigned counts[16]={0};
 for(unsigned j=0;j<546;j++){
  const A2ActorPacket *p=pp[j],*got;uint64_t t=a2_native_actor_packets_token(p->command_address,p->words[2]);assert(t);
  if(!j)first=t;
  assert(a2_native_actor_packets_consume(p->command_address,t,p->words+2,p->polygon_word_count,&got));
  counts[got->source_mesh_index]++;
 }
 assert(counts[0]==63&&counts[2]==71&&counts[15]==28);
 assert(a2_native_actor_packets_owner_complete(saved.handle));
 assert(a2_native_actor_packets_token(pp[0]->command_address,pp[0]->words[2])==first);
 sb_(0x80175cb4+31215,lb_(0x80175cb4+31215)^1);sb_(0x801ec050+80*15,0);
 assert(!memcmp(a2_native_actor_packets_owner(saved.handle),&saved,sizeof saved));
 assert(a2_native_actor_packets_token(pp[0]->command_address,pp[0]->words[2])==first);
 uint32_t forged[12];memcpy(forged,pp[0]->words+2,pp[0]->polygon_word_count*4);forged[1]^=1;
 const A2ActorPacket *got;assert(!a2_native_actor_packets_consume(pp[0]->command_address,first,forged,pp[0]->polygon_word_count,&got));
 assert(a2_native_actor_packets_source_failed("PC00",pc00_sha));
 /* Hidden final part identity is retained but its stale pose remains invalid. */
 pc00_setup_packets();snapshot.parts[15].valid=snapshot.parts[15].visible=0;
 snapshot.parts[15].fallback=A2_ACTOR_BAD_RECORD;snapshot.parts[15].flags|=1;
 sh_(snapshot.parts[15].address,snapshot.parts[15].flags);memcpy(snapshot.parts[15].raw,PSX_RAM+0x1ec500,80);
 restart();emit(0,0,0,0x80060000,0x80013754);seal();
 assert(a2_native_actor_packets_owners_latest(oo,1)==1&&!oo[0]->parts[15].valid&&!oo[0]->parts[15].visible);
 for(unsigned fault=0;fault<9;fault++){
  pc00_setup_packets();
  if(fault==0)snapshot.parts[15].source_sha256[0]^=1;
  if(fault==1)snapshot.parts[15].source_mesh_index=14;
  if(fault==2)snapshot.instances[0].part_count=17;
  if(fault==3)snapshot.parts[15].source_generation++;
  if(fault==4)sw_(0x80175cb4+32+15*4,0x80175cb4+304);
  if(fault==5)sh_(lw_(0x80175cb4+32)+14,58);
  if(fault==6)sh_(lw_(0x80175cb4+32)+16,47);
  if(fault==7)sw_(0x80175cb4+0x12c,17);
  if(fault==8)sw_(0x80175cb4+32+4*16,0);
  restart();emit(0,0,0,0x80060000,0x80013754);seal();
  assert(!a2_native_actor_packets_owners_latest(oo,1));
 }
 pc00_setup_packets();emit(15,0,0,0x80060000,0x80013894);
 sb_(0x80175cb4+31215,lb_(0x80175cb4+31215));seal();
 assert(!a2_native_actor_packets_owners_latest(oo,1));
 pc00_setup_packets();
 for(unsigned j=0;j<A2_ACTOR_PACKET_LIMIT;j++)emit(0,0,0,0x80060000+80*j,0x80013754);
 seal();assert(a2_native_actor_packets_owners_latest(oo,1)==1&&oo[0]->packet_count==A2_ACTOR_PACKET_LIMIT);
 snapshot.sequence++;R[4]=snapshot.draw_object_address;a2_native_actor_packets_before(0x80012e68,R);R[4]=0x800157b0;
 emit(0,0,0,0x80060000+80*A2_ACTOR_PACKET_LIMIT,0x80013754);
 seal();assert(!a2_native_actor_packets_owners_latest(oo,1));assert(a2_native_actor_packets_source_failed("PC00",pc00_sha));
 puts("PC00 packets: 546 actual source emissions, native equality, 16 copied parts/animation, repeated token, hidden identity, malformed source, tail write and overflow pass");
}
/* Catalogue coverage through the actual AL22 packet emitter. The source
 * geometry/material records are original; poses and screen coordinates are
 * synthetic. This checks packet ownership, not whole-scene visibility.
 * Real relocation is independently exercised by test_native_actor_sources. */
static unsigned catalogue_packets(const unsigned char *blob,const A2ActorSourceLayout *layout){
 static unsigned char native_ram[PSX_RAM_SIZE],native_scratch[0x400];
 uint32_t regs[32],gte[64],state[5];unsigned total=0;
 for(unsigned enabled=0;enabled<2;enabled++){
  setup(0);a2_native_actor_packets_reset();
  const uint32_t registry=0x80180000,parts=0x801d0000;
  memcpy(PSX_RAM+(registry&0x1fffff),blob,layout->bytes);
  snapshot.part_count=layout->parts;
  A2ActorInstance *instance=&snapshot.instances[0];
  instance->registry_address=registry;instance->part_count=layout->parts;
  for(unsigned k=0;k<layout->parts;k++){
   uint32_t header=registry+layout->header[k];
   sw_(registry+32+4*k,header);sw_(header+20,registry+layout->face_end[k]);
   A2ActorPart *part=&snapshot.parts[k];memset(part,0,sizeof *part);
   part->address=parts+80*k;part->registry_address=registry;
   part->source_mesh_index=k;part->flags=0x2000;part->source_generation=41;
   part->valid=part->visible=1;strcpy(part->source_key,layout->key);
   memcpy(part->source_sha256,layout->hash,32);
   memset(PSX_RAM+(part->address&0x1fffff),0,80);
   sh_(part->address,0x2000);sh_(part->address+2,k);sw_(part->address+60,registry);
   for(unsigned axis=0;axis<3;axis++)sh_(part->address+32+axis*8,4096);
   memcpy(part->raw,PSX_RAM+(part->address&0x1fffff),80);
   memcpy(part->matrix_q12,part->raw+32,18);
  }
  a2_native_actor_packets_configure(enabled);restart();
  HI=LO=psx_work=psx_next=0;psx_bb_budget=1000000;
  for(unsigned j=0;j<32;j++){gte_ctrl_write(j,0);gte_data_write(j,0);}
  unsigned words[A2_ACTOR_PACKET_LIMIT],expected[A2_ACTOR_PACKET_LIMIT][3],emitted=0;
  for(unsigned k=0;k<layout->parts;k++){
   uint32_t face=registry+layout->header[k]+24;
   for(unsigned f=0;f<layout->faces[k];f++){
    unsigned two=!!(lh_(face)&4);assert(emitted+two+1<A2_ACTOR_PACKET_LIMIT);
    if(two){
     expected[emitted][0]=k;expected[emitted][1]=f;expected[emitted][2]=1;
     words[emitted]=emit(k,f,1,0x80060000+80*emitted,0x800137e0);emitted++;
    }
    expected[emitted][0]=k;expected[emitted][1]=f;expected[emitted][2]=0;
    words[emitted]=emit(k,f,0,0x80060000+80*emitted,two?0x80013894:0x80013754);emitted++;
    face+=two?80:44;
   }
  }
  seal();total=emitted;
  if(!enabled){
   memcpy(native_ram,PSX_RAM,sizeof native_ram);memcpy(native_scratch,PSX_SCRATCH,sizeof native_scratch);memcpy(regs,R,sizeof regs);
   for(unsigned j=0;j<64;j++)gte[j]=j<32?gte_data_read(j):gte_ctrl_read(j-32);
   state[0]=HI;state[1]=LO;state[2]=psx_work;state[3]=psx_next;state[4]=psx_bb_budget;
  }else{
   assert(!memcmp(native_ram,PSX_RAM,sizeof native_ram)&&!memcmp(native_scratch,PSX_SCRATCH,sizeof native_scratch)&&!memcmp(regs,R,sizeof regs));
   for(unsigned j=0;j<64;j++)assert(gte[j]==(j<32?gte_data_read(j):gte_ctrl_read(j-32)));
   assert(state[0]==HI&&state[1]==LO&&state[2]==psx_work&&state[3]==psx_next&&state[4]==(uint32_t)psx_bb_budget);
   const A2ActorPacketOwner *owners[1];assert(a2_native_actor_packets_owners(16750,owners,1)==1);
   assert(owners[0]->packet_count==emitted&&!a2_native_actor_packets_owner_complete(owners[0]->handle));
   assert(!a2_native_actor_packets_source_failed(layout->key,layout->hash));
   for(unsigned j=0;j<emitted;j++){
    uint32_t address=0x80060008+80*j;const A2ActorPacket *packet;
    uint64_t token=a2_native_actor_packets_token(address,lw_(address));assert(token);
    assert(a2_native_actor_packets_consume(address,token,(const uint32_t*)(PSX_RAM+(address&0x1fffff)),words[j],&packet));
    assert(packet->owner_handle==owners[0]->handle&&packet->source_mesh_index==expected[j][0]&&
           packet->native_face_index==expected[j][1]&&packet->material_layer==expected[j][2]);
   }
   assert(a2_native_actor_packets_owner_complete(owners[0]->handle));
  }
 }
 return total;
}
static unsigned catalogue_file(const char *path,const char *hash){
 unsigned char blob[65536],digest[32];FILE *f=fopen(path,"rb");assert(f);
 size_t bytes=fread(blob,1,sizeof blob,f);assert(!ferror(f)&&feof(f));fclose(f);
 for(unsigned j=0;j<32;j++){unsigned value;assert(sscanf(hash+2*j,"%2x",&value)==1);digest[j]=value;}
 unsigned index=a2_actor_source_find((const char*)blob,digest);assert(index<A2_ACTOR_SOURCE_COUNT);
 assert(bytes==a2_actor_source_layouts[index].bytes);
 return catalogue_packets(blob,&a2_actor_source_layouts[index]);
}
int main(int argc,char **argv){
 if(argc==2){
  FILE *list=fopen(argv[1],"r");assert(list);char path[4096];unsigned blobs=0,packets=0;
  while(fgets(path,sizeof path,list)){
   path[strcspn(path,"\r\n")]=0;const char *name=strrchr(path,'/');name=name?name+1:path;
   assert(strlen(name)==68&&!strcmp(name+64,".bin"));packets+=catalogue_file(path,name);blobs++;
  }
  assert(!ferror(list));fclose(list);
  printf("actor packet corpus: %u original blobs, %u real AL22 emissions, complete ownership, native RAM/scratch/GTE/register equality; synthetic poses and screen coordinates\n",blobs,packets);return 0;
 }
 const char *names[]={"native_e03_source.bin","native_n01_source.bin","native_t01_source.bin"};
 const char *hashes[]={"d996617b1fd8626bfd3eae660596cc2b2dededc6adc01744fcf4453c6b193a56","a167884badd1c57afde46938c1c0b27143f7ce24824fa029534a3858b0434831","b1527bccb5db2873378cda55247347011d52250fbe7e0df0acc5bd4dcd7f109e"};
 const unsigned sizes[]={1800,15800,724};unsigned char blob[15800];unsigned emitted=0;
 for(unsigned j=0;j<3;j++){
  pc00_fixture(names[j],blob,sizes[j]);uint8_t digest[32];
  for(unsigned k=0;k<32;k++){unsigned v;assert(sscanf(hashes[j]+2*k,"%2x",&v)==1);digest[k]=v;}
  unsigned index=a2_actor_source_find((const char*)blob,digest);
  assert(index<A2_ACTOR_SOURCE_COUNT&&!strcmp(a2_actor_source_layouts[index].key,(const char*)blob)&&a2_actor_source_layouts[index].bytes==sizes[j]);
  emitted+=catalogue_packets(blob,&a2_actor_source_layouts[index]);
 }
 printf("actor catalogue packets: E03/N01/T01, %u real emissions and exact native state equality with synthetic poses pass\n",emitted);
 pc00_packets();pc00_and_chest_packets();
 historical_source_invalidation();source_failure_cases();rejected_source_equality();
 repeated_packet_identity();sealed_source_epoch();hidden_source_equality();
 setup(0);unsigned n=emit(0,0,0,0x800f9000,0x80013894);seal();
 uint64_t token=a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008));assert(token);
 assert(!a2_native_actor_packets_token(0x800f9004,lw_(0x800f9004)));
 const A2ActorPacket *p=NULL;assert(a2_native_actor_packets_consume(0x800f9008,token,(const uint32_t*)(PSX_RAM+0xf9008),n,&p));
 assert(p&&p->source_mesh_index==0&&p->native_face_index==0&&p->material_layer==0);
 const A2ActorPacketOwner *o=a2_native_actor_packets_owner(p->owner_handle);assert(o&&o->instance.entity_address==0x80119a34);
 assert(!memcmp(o->parts[0].raw,chest_closed_parts,80));
 assert(a2_native_actor_packets_consume(0x800f9008,token,p->words+2,n,&p));
 assert(a2_native_actor_packets_owner_complete(o->handle));
 /* Every repeat requires the complete immutable packet and live owner.
  * Direct fixture byte mutation deliberately bypasses the normal invalidator. */
 assert(a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008))==token);
 assert(!a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008)^1));
 PSX_RAM[0xf900c]^=1;
 assert(!a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008)));
 PSX_RAM[0xf900c]^=1;
 assert(a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008))==token);
 a2_native_actor_packets_invalidate(0x800f9000,1);
 assert(!a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008)));
 assert(!a2_native_actor_packets_owner_complete(o->handle));
 assert(!a2_native_actor_packets_consume(0x800f9008,token,(const uint32_t*)(PSX_RAM+0xf9008),n,&p)&&!p);
 /* Both material layers, actual reversed OT order, all closed/open faces. */
 for(int open=0;open<=1;open++){
  setup(open);unsigned total=all_faces();assert(total==27);
  assert(!a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008)));seal();
  const A2ActorPacketOwner *oo[2]={0};assert(!a2_native_actor_packets_owners(16751,oo,2));
  assert(!a2_native_actor_packets_owners(16750,oo,0)&&!oo[0]);
  assert(a2_native_actor_packets_owners(16750,oo,2)==1&&oo[0]->packet_count==27);
  const A2ActorPacket *pp[27];assert(!a2_native_actor_packets_owner_packets(oo[0]->handle,pp,26));
  assert(a2_native_actor_packets_owner_packets(oo[0]->handle,pp,27)==27);
  assert(pp[0]->material_layer==1&&pp[1]->material_layer==0&&pp[0]->native_face_index==pp[1]->native_face_index);
  assert(pp[1]->previous_head==pp[0]->dma_base); /* prepend reverses layers */
  assert(!a2_native_actor_packets_owner_complete(oo[0]->handle));
  uint32_t node=lw_(pp[0]->ot_bucket)&0xffffffu;unsigned got=0,e1=0,e2=0;
  while(node){
   uint64_t t=a2_native_actor_packets_token(node+8,lw_(node+8));assert(t);
   unsigned count=(lw_(node)>>24)-1;
   assert(!a2_native_actor_packets_token(node+4,lw_(node+4)));
   assert(a2_native_actor_packets_consume(node+8,t,(const uint32_t*)(PSX_RAM+node+8),count,&p));
   assert(p->owner_handle==oo[0]->handle);e1+=p->prefix_word>>24==0xe1;e2+=p->prefix_word>>24==0xe2;
   node=p->previous_head;got++;
  }
  assert(got==27&&e1&&e2&&a2_native_actor_packets_owner_complete(oo[0]->handle));
  assert(!memcmp(oo[0]->parts[1].raw,open?chest_open_lid:chest_closed_parts+80,80));
 }
 /* Unsealed source/entity and any packet/code mutation retire the owner.
  * Sealed source/entity/pose reuse is covered by sealed_source_epoch above. */
 const uint32_t writes[]={0x800f9000,0x800f9004,0x800f9008,0x801ab464,0x80119a34,0x80013cbc};
 for(unsigned j=0;j<sizeof writes/sizeof *writes;j++){
  setup(0);emit(0,0,0,0x800f9000,0x80013894);emit(1,0,0,0x800f9050,0x80013894);
  if(j!=3&&j!=4)seal();
  token=a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008));assert((j==3||j==4)?!token:!!token);
  sb_(writes[j],lb_(writes[j]));seal();assert(!a2_native_actor_packets_token(0x800f9058,lw_(0x800f9058)));
 }
 setup(0);emit(0,0,0,0x800f9000,0x80013894);sb_(0x801ec5a0,lb_(0x801ec5a0));seal();
 assert(!a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008))); /* unsealed pose changes revoke */
 setup(0);emit(0,0,0,0x800f9000,0x80013894);seal();sb_(0x801ec5a0,lb_(0x801ec5a0)^1);
 assert(a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008))); /* later90168 arena reuse cannot change copied completed main */
 for(int fault=0;fault<12;fault++){
  setup(0);
  if(fault==0)snapshot.parts[0].source_generation=0;
  if(fault==1)snapshot.parts[0].source_sha256[0]^=1;
  if(fault==2)snapshot.instances[0].generation_known=0;
  if(fault==3)snapshot.parts[1].fallback=A2_ACTOR_UNBOUND_SOURCE;
  if(fault==4)snapshot.shadow_pass=1;
  if(fault==5)snapshot.parts[1].registry_address+=4;
  if(fault==6)snapshot.instances[0].fallback=A2_ACTOR_MISSING_ROOT;
  if(fault==7)strcpy(snapshot.parts[0].source_key,"PC00");
  if(fault==8)snapshot.parts[1].source_generation++;
  if(fault==9)snapshot.parts[1].source_mesh_index=0;
  if(fault==10)snapshot.parts[1].fallback=A2_ACTOR_DIFFERENT_PART_SOURCE;
  if(fault==11)snapshot.parts[1].fallback=A2_ACTOR_UNKNOWN_LIFETIME;
  restart();emit(0,0,0,0x800f9000,0x80013894);seal();assert(!a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008)));
 }
 setup(0);emit(0,0,0,0x800f9000,0x80013894);emit(1,0,0,0x800f9050,0x80011400);seal();
 assert(!a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008))); /* unknown caller poisons whole owner */
 setup(0);emit(0,0,0,0x800f9000,0x80013894);seal();
 token=a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008));assert(token);a2_native_actor_packets_reset();
 assert(!a2_native_actor_packets_consume(0x800f9008,token,(const uint32_t*)(PSX_RAM+0xf9008),8,&p));
 /* Two explicitly different instance generations may share model, pose and
  * native XY; exact part addresses still determine different owners. */
 setup(0);snapshot.instance_count=2;snapshot.part_count=4;
 snapshot.instances[1]=snapshot.instances[0];snapshot.instances[1].entity_address=0x80119d58;
 snapshot.instances[1].instance_generation=78;snapshot.instances[1].first_part=2;
 for(unsigned j=0;j<2;j++){
  snapshot.parts[2+j]=snapshot.parts[j];snapshot.parts[2+j].address=0x801ec700+80*j;
  memcpy(PSX_RAM+(snapshot.parts[2+j].address&0x1fffff),snapshot.parts[2+j].raw,80);
 }
 restart();emit(0,0,0,0x800f9000,0x80013894);selected_instance=1;emit(0,0,0,0x800f9050,0x80013894);seal();
 const A2ActorPacketOwner *both[2];assert(a2_native_actor_packets_owners(16750,both,2)==2);
 assert(both[0]->handle!=both[1]->handle&&both[0]->instance.instance_generation!=both[1]->instance.instance_generation);
 sb_(0x80119d58,lb_(0x80119d58));assert(a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008)));
 assert(a2_native_actor_packets_token(0x800f9058,lw_(0x800f9058))); /* immutable second submission also survives */
 sb_(0x800f9058,lb_(0x800f9058));
 assert(a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008)));
 assert(!a2_native_actor_packets_token(0x800f9058,lw_(0x800f9058)));
 /* A later shadow submission cannot retire an already sealed main packet. */
 setup(0);emit(0,0,0,0x800f9000,0x80013894);seal();snapshot.sequence++;snapshot.shadow_pass=1;
 R[4]=snapshot.draw_object_address;a2_native_actor_packets_before(0x80012e68,R);seal();
 assert(a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008)));
 /* Distinct main submissions in one guest frame survive together. */
 snapshot.shadow_pass=0;snapshot.sequence++;R[4]=snapshot.draw_object_address;
 a2_native_actor_packets_before(0x80012e68,R);R[4]=0x800157b0;emit(0,0,0,0x800f9050,0x80013894);seal();
 assert(a2_native_actor_packets_owners(16750,both,2)==2);
 /* The same native arena build can finish shadow/unsupported submissions in
  * a later tick. Immutable sealed main packets still belong to that build. */
 for(unsigned unsupported=0;unsupported<2;unsupported++){
  setup(0);emit(0,0,0,0x800f9000,0x80013894);seal();
  uint64_t saved=a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008));assert(saved);
  snapshot.sequence++;snapshot.guest_frame++;
  snapshot.shadow_pass=!unsupported;
  if(unsupported){snapshot.valid=0;snapshot.draw_object_address=0x801176e8;}
  R[4]=snapshot.draw_object_address;a2_native_actor_packets_before(0x80012e68,R);seal();
  assert(a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008))==saved);
  assert(a2_native_actor_packets_owners(16750,both,2)==1);
  sb_(0x800f9008,lb_(0x800f9008));
  assert(!a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008)));
 }
 /* A new real arena build retires the old owners even in the same tick,
  * and even if that new capture is invalid or has no source generation. */
 for(unsigned generation=0;generation<2;generation++){
  setup(0);emit(0,0,0,0x800f9000,0x80013894);seal();
  snapshot.sequence++;snapshot.build_generation=generation?2:0;snapshot.valid=0;
  R[4]=snapshot.draw_object_address;a2_native_actor_packets_before(0x80012e68,R);
  assert(!a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008)));
 }
 /* An earlier rejected/ineligible capture cannot label later owners with
  * its tick; the collection reports the first actually eligible main. */
 for(unsigned ineligible=0;ineligible<2;ineligible++){
  setup(0);snapshot.build_generation=2;snapshot.sequence++;snapshot.guest_frame=16749;
  snapshot.valid=ineligible;snapshot.instances[0].selected_for_draw=0;
  R[4]=snapshot.draw_object_address;a2_native_actor_packets_before(0x80012e68,R);
  snapshot.valid=1;snapshot.instances[0].selected_for_draw=1;snapshot.sequence++;snapshot.guest_frame=16750;
  R[4]=snapshot.draw_object_address;a2_native_actor_packets_before(0x80012e68,R);
  R[4]=0x800157b0;emit(0,0,0,0x800f9000,0x80013894);seal();
  assert(a2_native_actor_packets_owners(16750,both,2)==1&&both[0]->guest_frame==16750);
  assert(!a2_native_actor_packets_owners(16749,both,2));
 }
 /* Full packet-capacity overflow rejects every owner, never only the tail. */
 setup(0);for(unsigned j=0;j<=A2_ACTOR_PACKET_LIMIT;j++)emit(0,0,0,0x80060000+80*j,0x80013894);seal();
 assert(!a2_native_actor_packets_token(0x80060008,lw_(0x80060008)));
 setup(0);for(unsigned j=0;j<=A2_ACTOR_PACKET_OWNER_LIMIT;j++){
  if(j){snapshot.sequence++;R[4]=snapshot.draw_object_address;a2_native_actor_packets_before(0x80012e68,R);R[4]=0x800157b0;}
  emit(0,0,0,0x800f9000+80*j,0x80013894);seal();
 }
 assert(!a2_native_actor_packets_owners(16750,both,2));
 /* Native VRAM input, RAM, scratch and registers unchanged with observerOFF. */
 static uint8_t native_ram[PSX_RAM_SIZE],native_scratch[0x400];uint32_t regs[32],work,next;
 setup(1);a2_native_actor_packets_configure(0);psx_work=0;all_faces();seal();
 memcpy(native_ram,PSX_RAM,sizeof native_ram);memcpy(native_scratch,PSX_SCRATCH,sizeof native_scratch);memcpy(regs,R,sizeof regs);work=psx_work;next=psx_next;
 setup(1);psx_work=0;all_faces();seal();
 assert(!memcmp(native_ram,PSX_RAM,sizeof native_ram)&&!memcmp(native_scratch,PSX_SCRATCH,sizeof native_scratch)&&!memcmp(regs,R,sizeof regs)&&work==psx_work&&next==psx_next);
 puts("actor packets: 27 real closed/open T02 emissions, repeated source identity, hidden-source identity, immutable sealed lifetime, native equality and guards pass");
 return 0;
}
