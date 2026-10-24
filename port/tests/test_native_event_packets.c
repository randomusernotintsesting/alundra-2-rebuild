/* Exact retained EVENT AL22 emitters and source/pose records from RAM06000.
 * Screen XY and projected normals are controlled emitter inputs: this tests
 * packet transport, not a complete EVENT entity/pose/projection traversal. */
#define main original_actor_packet_fixture_main
#include "test_native_actor_packets.c"
#undef main
#include "fixtures/native_event_fixture.h"

enum { EVENT_PACKETS=612 };
static const unsigned event_face_counts[16]={20,12,44,20,12,44,59,40,57,54,32,24,32,16,52,31};
static void event_restart(void){
 a2_native_actor_packets_reset();R[4]=snapshot.draw_object_address;
 a2_native_actor_packets_before(0x80012ef8,R);R[4]=0x80015ea0;
}
static void event_setup(int enabled,int light){
 memset(PSX_RAM,0,sizeof PSX_RAM);memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);memset(R,0,sizeof R);
 event_fixture(PSX_RAM);pc00_fixture("native_event_al22.bin",PSX_RAM+0x10000,26968);
 memset(&snapshot,0,sizeof snapshot);snapshot.sequence=snapshot.build_generation=1;
 snapshot.guest_frame=psx_frame_no=6000;snapshot.valid=1;snapshot.instance_count=1;snapshot.part_count=16;
 snapshot.source_family=A2_ACTOR_EVENT00;snapshot.draw_object_address=0x800d76f0;
 A2ActorInstance *i=&snapshot.instances[0];i->source_family=A2_ACTOR_EVENT00;
 i->entity_address=0x800ce6e8;i->registry_address=0x80164330;i->instance_generation=77;
 i->generation_known=i->valid=i->selected_for_draw=1;i->part_count=16;
 const int32_t root[3]={25284608,-4608000,610304};memcpy(i->renderer_root_q12,root,sizeof root);
 memcpy(i->actor_world_q12,root,sizeof root);
 for(unsigned k=0;k<16;k++){
  A2ActorPart *p=&snapshot.parts[k];p->address=0x800d94c8+80*k;p->registry_address=i->registry_address;
  p->source_mesh_index=k;p->source_generation=123;p->valid=p->visible=1;
  strcpy(p->source_key,"FRITTO");memcpy(p->source_sha256,event_intro_sha,32);
  memcpy(p->raw,PSX_RAM+(p->address&0x1fffff),80);memcpy(&p->flags,p->raw,4);
  memcpy(p->matrix_q12,p->raw+32,18);memcpy(p->translation0,p->raw+8,12);memcpy(p->translation1,p->raw+20,12);
 }
 a2_native_actor_packets_init(PSX_RAM,sizeof PSX_RAM);a2_native_actor_packets_configure(enabled);
 R[4]=0x80015ea0;R[5]=0x1f800000;sw_(R[4]+0x68,snapshot.draw_object_address);
 sw_(R[4]+0x64,0x80110000);sw_(R[4]+0x5f8,0);sw_(R[4]+0x5cc,0);sw_(R[4]+0xab0,0);
 sh_(R[5]+0x3d0,0xffff);sh_(R[5]+0x3d2,0);
 HI=LO=psx_work=psx_next=0;psx_bb_budget=1000000;
 for(unsigned j=0;j<32;j++){gte_ctrl_write(j,0);gte_data_write(j,0);}
 if(light){gte_ctrl_write(26,256);gte_ctrl_write(13,4096);gte_ctrl_write(14,2048);gte_ctrl_write(15,1024);}
 event_restart();
}
static unsigned event_emit(unsigned part,unsigned face_index,unsigned layer,uint32_t base,uint32_t caller){
 R[30]=snapshot.parts[part].address;sw_(R[4]+0x70,R[30]);
 a2_native_actor_packets_before(0x80013190,R);
 R[3]=lw_(snapshot.instances[0].registry_address+32+part*4);
 a2_native_actor_packets_before(0x8001322c,R);
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
 R[12]=R[15]>>16;R[13]=R[14]>>16;R[25]=R[24]>>16;
 R[1]=lw_(mat+28);R[2]=base;R[7]=0x80008000;R[30]=0;R[31]=caller;
 psx_interp(0x80013d50);
 return command&8?(command&4?12:8):(command&4?9:6);
}
static void event_seal(void){a2_native_actor_packets_before(0x80013158,R);}
static unsigned event_all_faces(int wrapped){
 unsigned emitted=0;
 for(unsigned part=0;part<16;part++){
  uint32_t h=lw_(0x80164330+32+4*part),face=h+24;assert(lh_(h+14)==event_face_counts[part]);
  for(unsigned index=0;index<event_face_counts[part];index++){
   unsigned two=!!(lh_(face)&4),adjust=wrapped?0x38u:0u;
   if(two)event_emit(part,index,1,0x80060000+80*emitted++,0x80013878-adjust);
   event_emit(part,index,0,0x80060000+80*emitted++,(two?0x8001392c:0x800137ec)-adjust);
   face+=two?80:44;
  }
 }
 return emitted;
}
static const A2ActorPacketOwner *event_owner(void){
 const A2ActorPacketOwner *o[1];assert(a2_native_actor_packets_owners_latest(o,1)==1);return o[0];
}
static void event_equality(void){
 static uint8_t ram[PSX_RAM_SIZE],scratch[0x400];uint32_t regs[32],gte[64],state[5];
 for(unsigned light=0;light<2;light++)for(unsigned wrapped=0;wrapped<2;wrapped++){
  for(unsigned enabled=0;enabled<2;enabled++){
   event_setup(enabled,light);assert(event_all_faces(wrapped)==EVENT_PACKETS);event_seal();
   if(!enabled){
    memcpy(ram,PSX_RAM,sizeof ram);memcpy(scratch,PSX_SCRATCH,sizeof scratch);memcpy(regs,R,sizeof regs);
    for(unsigned j=0;j<64;j++)gte[j]=j<32?gte_data_read(j):gte_ctrl_read(j-32);
    state[0]=HI;state[1]=LO;state[2]=psx_work;state[3]=psx_next;state[4]=psx_bb_budget;
   }else{
    const A2ActorPacketOwner *o=event_owner();assert(o->packet_count==EVENT_PACKETS&&o->light.known==light);
    assert(!memcmp(ram,PSX_RAM,sizeof ram)&&!memcmp(scratch,PSX_SCRATCH,sizeof scratch)&&!memcmp(regs,R,sizeof regs));
    for(unsigned j=0;j<64;j++)assert(gte[j]==(j<32?gte_data_read(j):gte_ctrl_read(j-32)));
    assert(state[0]==HI&&state[1]==LO&&state[2]==psx_work&&state[3]==psx_next&&state[4]==(uint32_t)psx_bb_budget);
    assert(!memcmp(&o->instance,&snapshot.instances[0],sizeof o->instance));
    for(unsigned k=0;k<16;k++)assert(!memcmp(&o->parts[k],&snapshot.parts[k],sizeof o->parts[k]));
    if(light){assert(o->light.projection_h==256&&o->light.background[0]==4096&&o->light.background[1]==2048&&o->light.background[2]==1024);}
   }
  }
 }
}
static void event_tokens(void){
 event_setup(1,1);assert(event_all_faces(0)==EVENT_PACKETS);event_seal();
 const A2ActorPacketOwner *o=event_owner();uint64_t owner=o->handle;
 const A2ActorPacket *p[EVENT_PACKETS];assert(a2_native_actor_packets_owner_packets(owner,p,EVENT_PACKETS)==EVENT_PACKETS);
 unsigned counts[16]={0},formats[4]={0},layers[2]={0};
 for(unsigned j=0;j<EVENT_PACKETS;j++){
  const A2ActorPacket *got;uint64_t t=a2_native_actor_packets_token(p[j]->command_address,p[j]->words[2]);assert(t);
  assert(a2_native_actor_packets_consume(p[j]->command_address,t,p[j]->words+2,p[j]->polygon_word_count,&got));
  assert(got==p[j]&&got->entity_generation==77);counts[got->source_mesh_index]++;
  formats[((got->words[2]>>24)&0xc)/4]++;layers[got->material_layer]++;
  assert(a2_native_actor_packets_token(p[j]->command_address,p[j]->words[2])==t);
  assert(a2_native_actor_packets_consume(p[j]->command_address,t,p[j]->words+2,p[j]->polygon_word_count,&got));
 }
 assert(a2_native_actor_packets_owner_complete(owner));
 for(unsigned k=0;k<16;k++)assert(counts[k]>=event_face_counts[k]);
 assert(layers[0]==549&&layers[1]==63);
 assert(formats[0]+formats[1]+formats[2]+formats[3]==EVENT_PACKETS);
 uint64_t t=a2_native_actor_packets_token(p[0]->command_address,p[0]->words[2]);
 uint32_t bad[12];memcpy(bad,p[0]->words+2,p[0]->polygon_word_count*4);bad[1]^=1;
 const A2ActorPacket *got;assert(!a2_native_actor_packets_consume(p[0]->command_address,t,bad,p[0]->polygon_word_count,&got));
 assert(a2_native_actor_packets_source_failed("FRITTO",event_intro_sha));
 printf("EVENT native packet formats G3=%u GT3=%u G4=%u GT4=%u; main=%u secondary=%u\n",formats[0],formats[1],formats[2],formats[3],layers[0],layers[1]);
}
static void event_guards(void){
 const A2ActorPacketOwner *o[1];
 for(unsigned fault=0;fault<9;fault++){
  event_setup(1,1);
  if(fault==0)snapshot.source_family=A2_ACTOR_GAME00;
  if(fault==1)snapshot.parts[15].source_sha256[0]^=1;
  if(fault==2)snapshot.parts[15].source_generation++;
  if(fault==3)snapshot.parts[15].source_mesh_index=14;
  if(fault==4)snapshot.shadow_pass=1;
  event_restart();
  if(fault==5)sw_(snapshot.parts[0].address,lw_(snapshot.parts[0].address));
  event_emit(0,0,0,0x80060000,fault==6?0x80013754:0x800137ec);
  if(fault==7)sb_(0x80010000,lb_(0x80010000));
  if(fault==8){gte_ctrl_write(13,4097);event_emit(0,1,0,0x80060050,0x800137ec);}
  event_seal();assert(!a2_native_actor_packets_owners_latest(o,1));
 }
 /* C0 camera changes do not alter the original light-space contract. */
 event_setup(1,1);event_emit(0,0,0,0x80060000,0x800137ec);gte_ctrl_write(0,123);
 event_emit(0,1,0,0x80060050,0x800137ec);event_seal();assert(event_owner()->packet_count==2);
 /* An unknown GAME00 seal cannot prematurely expose an EVENT owner. */
 event_setup(1,1);event_emit(0,0,0,0x80060000,0x800137ec);
 a2_native_actor_packets_before(0x800130c0,R);assert(!a2_native_actor_packets_owners_latest(o,1));
 event_seal();assert(event_owner()->packet_count==1);
 /* Complete fixed-capacity overflow is fail closed, with source attribution. */
 event_setup(1,0);
 for(unsigned j=0;j<=A2_ACTOR_PACKET_LIMIT;j++)event_emit(0,0,0,0x80060000+80*j,0x800137ec);
 event_seal();assert(!a2_native_actor_packets_owners_latest(o,1));
 assert(a2_native_actor_packets_source_failed("FRITTO",event_intro_sha));
}
/* The real EVENT owner and original FRITTO part must certify the active
 * projection, while wrong-family context, writes and sealed owners cannot. */
static void event_projection_owner(void){
 for(unsigned fault=0;fault<6;fault++){
  event_setup(1,1);
  R[30]=snapshot.parts[0].address;sw_(R[4]+0x70,R[30]);
  R[3]=lw_(snapshot.instances[0].registry_address+32);
  a2_native_actor_packets_before(0x80013190,R);
  a2_native_actor_packets_before(0x8001322c,R);
  uint32_t context=R[4],bank=lw_(R[30]+72);
  if(fault==1)context=0x800157b0;
  if(fault==2)sb_(R[30]+8,lb_(R[30]+8));
  if(fault==3)a2_native_actor_packets_before(0x80013158,R);
  if(fault==4)sw_(0x80015d00,lw_(0x80015d00));
  if(fault==5)bank+=4;
  const A2ActorPacketOwner *owner=a2_native_actor_packets_projecting(context,R[30],bank);
  if(!fault){assert(owner);assert(owner->instance.source_family==A2_ACTOR_EVENT00);}
  else assert(!owner);
 }
}
int main(void){
 event_projection_owner();event_equality();event_tokens();event_guards();
 puts("PASS: EVENT retained 612 emissions/16 parts, six callers, exact native state OFF/ON, copied light, repeats/source/family/clock-free lifetime and overflow guards");
 return 0;
}
