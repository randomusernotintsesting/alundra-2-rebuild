/* Real retained GAME emitter, interpreter, GTE and immutable packet owner. */
#define main original_packet_test_main
#include "test_native_actor_packets.c"
#undef main

static unsigned run_colors(int enabled,int fault) {
 setenv("A2_COLOR_CONTINUITY",enabled?"1":"0",1);
 setup(1);
 for(unsigned j=0;j<32;j++){gte_ctrl_write(j,0);gte_data_write(j,0);}
 for(unsigned j=13;j<=15;j++)gte_ctrl_write(j,4096);
 if(fault) {
  /* Alter an input before the observer starts: no lifetime shortcut can
   * detect this. The complete source component guard must reject it. */
  uint32_t h=lw_(snapshot.instances[0].registry_address+32);
  uint32_t f=h+24;for(unsigned j=0;j<6;j++)f+=(lh_(f)&4)?80:44;
  if(fault==1)PSX_RAM[(f&0x1fffff)+8]^=1;
  if(fault==2)PSX_RAM[(f&0x1fffff)+4]^=1;
  if(fault==3)PSX_RAM[(lw_(h+20)&0x1fffff)]^=1;
  if(fault==4) {
   f=h+24;for(unsigned j=0;j<4;j++)f+=(lh_(f)&4)?80:44;
   uint32_t physical=f&0x1fffffu;
   /* An excluded 44-byte G4 becomes an opaque G3 without changing layout.
    * Copy a seed triangle's indices/material so it joins that component. */
   uint32_t seed=physical+44;
   memcpy(PSX_RAM+physical,PSX_RAM+seed,2);
   memcpy(PSX_RAM+physical+4,PSX_RAM+seed+4,4);
   PSX_RAM[physical+11]=0x30;
  }
  restart();
 }
 unsigned n=all_faces();seal();unsigned corrected=0;
 for(unsigned j=0;j<n;j++) {
  uint32_t address=0x800f9008+80*j;
  uint64_t token=a2_native_actor_packets_token(address,lw_(address));assert(token);
  const A2ActorPacket *p;
  unsigned count=(lw_(address-8)>>24)-1;
  assert(a2_native_actor_packets_consume(address,token,(const uint32_t*)(PSX_RAM+(address&0x1fffff)),count,&p));
  if(p->fine_rgb_valid) {
   assert(enabled&&!fault);
   assert(p->polygon_word_count==6&&p->material_layer==0);
   uint32_t h=lw_(snapshot.instances[0].registry_address+32+4*p->source_mesh_index),f=h+24;
   for(unsigned k=0;k<p->native_face_index;k++)f+=(lh_(f)&4)?80:44;
   for(unsigned k=0;k<3;k++)if(lb_(f+4+k)==8)
    assert((p->fine_rgb[k]&0xffffffu)==(p->source_mesh_index?0x002f8du:0x000649u));
   corrected++;
  }
 }
 return corrected;
}
static void unvisited_changed_part(void) {
 for(int fault=0;fault<2;fault++) {
  setenv("A2_COLOR_CONTINUITY","1",1);setup(1);
  for(unsigned j=0;j<32;j++){gte_ctrl_write(j,0);gte_data_write(j,0);}
  for(unsigned j=13;j<=15;j++)gte_ctrl_write(j,4096);
  if(fault) {
   uint32_t h=lw_(snapshot.instances[0].registry_address+32),f=h+24;
   for(unsigned j=0;j<5;j++)f+=(lh_(f)&4)?80:44;
   PSX_RAM[(f&0x1fffff)+8]^=1;restart();
  }
  emit(1,6,0,0x800f9000,0x80013754);seal(); /* body part never visited */
  const A2ActorPacket *p;uint64_t t=a2_native_actor_packets_token(0x800f9008,lw_(0x800f9008));assert(t);
  assert(a2_native_actor_packets_consume(0x800f9008,t,(const uint32_t*)(PSX_RAM+0xf9008),6,&p));
  assert(p->fine_rgb_valid==!fault);
 }
}
static void immutable_colors(void) {
 assert(run_colors(1,0)>=8);
 const A2ActorPacketOwner *o[1];const A2ActorPacket *packets[32];
 assert(a2_native_actor_packets_owners(16750,o,1)==1);
 size_t n=a2_native_actor_packets_owner_packets(o[0]->handle,packets,32);
 const A2ActorPacket *p=NULL;
 for(size_t j=0;j<n;j++)if(packets[j]->fine_rgb_valid){p=packets[j];break;}
 assert(p);A2ActorPacket saved=*p;
 uint64_t t=a2_native_actor_packets_token(p->command_address,p->words[2]);assert(t);
 sb_(snapshot.instances[0].registry_address,lb_(snapshot.instances[0].registry_address)^1);
 const A2ActorPacket *current;
 assert(a2_native_actor_packets_consume(p->command_address,t,p->words+2,p->polygon_word_count,&current));
 assert(!memcmp(&saved,current,sizeof saved));
 sb_(p->command_address+4,lb_(p->command_address+4)^1);
 assert(!a2_native_actor_packets_token(saved.command_address,saved.words[2]));
 assert(!a2_native_actor_packets_consume(saved.command_address,t,saved.words+2,saved.polygon_word_count,&current));
 a2_native_actor_packets_reset();
 assert(!a2_native_actor_packets_token(saved.command_address,saved.words[2]));
}
static void modified_emitter_colors(void) {
 setenv("A2_COLOR_CONTINUITY","1",1);setup(1);
 for(unsigned j=0;j<32;j++){gte_ctrl_write(j,0);gte_data_write(j,0);}
 for(unsigned j=13;j<=15;j++)gte_ctrl_write(j,4096);
 emit(0,5,0,0x800f9000,0x80013754);
 fixture_color_override=1;emit(0,6,0,0x800f9050,0x80013754);fixture_color_override=0;
 emit(0,7,0,0x800f90a0,0x80013754);seal();
 for(unsigned j=0;j<3;j++) {
  uint32_t a=0x800f9008+80*j;const A2ActorPacket *p;
  uint64_t t=a2_native_actor_packets_token(a,lw_(a));assert(t);
  assert(a2_native_actor_packets_consume(a,t,(const uint32_t*)(PSX_RAM+(a&0x1fffff)),6,&p));
  assert(!p->fine_rgb_valid); /* earlier and later siblings both fall back */
 }
}
int main(void) {
 static uint8_t ram[PSX_RAM_SIZE],scratch[0x400];uint32_t regs[32],gte[64];
 assert(run_colors(0,0)==0);
 memcpy(ram,PSX_RAM,sizeof ram);memcpy(scratch,PSX_SCRATCH,sizeof scratch);memcpy(regs,R,sizeof regs);
 for(unsigned j=0;j<64;j++)gte[j]=j<32?gte_data_read(j):gte_ctrl_read(j-32);
 unsigned corrected=run_colors(1,0);assert(corrected>=8);
 assert(!memcmp(ram,PSX_RAM,sizeof ram)&&!memcmp(scratch,PSX_SCRATCH,sizeof scratch)&&!memcmp(regs,R,sizeof regs));
 for(unsigned j=0;j<64;j++)assert(gte[j]==(j<32?gte_data_read(j):gte_ctrl_read(j-32)));
 for(int fault=1;fault<=4;fault++)assert(run_colors(1,fault)==0);
 immutable_colors();modified_emitter_colors();unvisited_changed_part();
 puts("PASS: retained emitter colors, full guest state equality, source guards, native tint fallback, sealed metadata and invalid packet/reset rejection");
 return 0;
}
