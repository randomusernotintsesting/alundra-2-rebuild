/* Retained complete AL22 RTPT loop plus real generated batch entry and OT
 * insertion. The resident camera setup and FT4 XY copies are explicit fixture
 * inputs; this does not pretend to replay the whole entity shadow builder. */
#define A2_WORLD_PRECISION 1
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../src/psx_rt.h"
#include "../src/gte.c"
#include "../src/world_shadow.h"
static void shadow_before_fixture(uint32_t pc,const uint32_t r[32],int valid);
#define a2_world_shadow_before shadow_before_fixture
#include "../src/interp.c"
#undef a2_world_shadow_before
#include "../src/world_shadow.c"
#include "fixtures/native_chest_packets.h"
#include "../gen/game00_008.c"
uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
uint32_t R[32],HI,LO,psx_next,psx_work,psx_frame_no=4200,a2_ramwatch;
int psx_bb_budget=1000000;
void a2_ramwatch_hit(uint32_t a,uint32_t v,int n){(void)a;(void)v;(void)n;}
uint32_t psx_mmio_read(uint32_t a,int n){(void)a;(void)n;abort();}
void psx_mmio_write(uint32_t a,uint32_t v,int n){(void)a;(void)v;(void)n;abort();}
uint32_t psx_cop0_read(int r){(void)r;return 0;}
void psx_cop0_write(int r,uint32_t v){(void)r;(void)v;}
void psx_rfe(void){}
void psx_syscall_at(uint32_t p){(void)p;abort();}
void psx_break(uint32_t p){(void)p;abort();}
void psx_bb_fire(void){abort();}
int a2_wide(void){return 1;}
static uint32_t pack(int x,int y){return (uint16_t)x|((uint32_t)(uint16_t)y<<16);}
static unsigned origin_fraction=1024,point_count=4;
static int injection_fault,injected;
static void shadow_before_fixture(uint32_t pc,const uint32_t r[32],int valid) {
 if(!injected && ((injection_fault==11||injection_fault==13)?pc==0x8001554cu:
                 (injection_fault==12||injection_fault==14)?pc==0x80015614u:0)) {
  R[injection_fault<=12?8:21]++;injected=1;
 }
 a2_world_shadow_before(pc,r,valid);
}
static unsigned run(int enabled,int fault,int shadow_enabled){
 injection_fault=fault;injected=0;
 memset(PSX_RAM,0,sizeof PSX_RAM);memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);memset(R,0,sizeof R);
 memcpy(PSX_RAM+0x10000,chest_al22,sizeof chest_al22);
 memcpy(PSX_RAM+0x8de88,world_shadow_game_code,sizeof world_shadow_game_code);
 memcpy(PSX_RAM+0x25598,world_shadow_setup_code,sizeof world_shadow_setup_code);
 world_precision_configure(enabled);world_camera_configure(1);sw_(0x800811d8,4);
 for(int i=0;i<32;i++){gte_ctrl_write(i,0);gte_data_write(i,0);}
 const int16_t mat[10]={4096,0,0,0,4096,0,0,0,4096,0};
 memcpy(PSX_RAM+0x180000,mat,sizeof mat);
 gte_ctrl_write(24,160<<16);gte_ctrl_write(25,124<<16);gte_ctrl_write(26,96);
 uint32_t obj=0x8011763c,base=0x80110000;
 sw_(obj+28,0x80180000);sw_(obj+44,origin_fraction);sw_(obj+48,0);sw_(obj+52,0);
 const int xyz[4][3]={{-60,20,500},{60,20,500},{-60,20,700},{60,20,700}};
 for(unsigned i=0;i<point_count;i++)sw_(0x1f800198+4*i,0x1f800000+12*i);
 for(unsigned i=0;i<point_count;i++)for(unsigned j=0;j<3;j++)
  sw_(0x1f800000+12*i+4*j,(uint32_t)(xyz[i%4][j]*4096));
 if(fault==4)sw_(0x1f800000,32769u*4096u);
 /* An off-screen point in a later RTPT group saturates SX (no provenance). */
 if(fault==15)sw_(0x1f800000+12*5,8000u*4096u);
 R[29]=0x801ff000;R[31]=fault==1?0x8008dead:0x8008eafc;
 R[4]=0x1f800000;R[5]=base;R[7]=point_count;
 if(fault==2)PSX_RAM[0x8df98]^=1;
 g0_8008DE88();assert(psx_next==0x80025598u);
 if(fault==8){a2_world_shadow_configure(0);a2_world_shadow_configure(1);}
 /* Source-proven resident setup supplies this OBJ and camera to AL22. */
 R[4]=obj;R[5]=(point_count+2)/3;R[31]=0x80025670;
 if(fault==3)sw_(0x80010000,lw_(0x80010000)^1);
 psx_interp(0x80015454);assert(psx_next==0x80025670);
 if(fault==9||fault==10)a2_world_shadow_configure(0);
 if(fault==10)a2_world_shadow_configure(1);
 sw_(base,10u<<24);sw_(base+4,0xe2000000);sw_(base+8,0x2e808080);
 for(unsigned i=0;i<4;i++)sw_(base+12+8*i,lw_(0x1f800220+8*i));
 if(fault==5)sw_(0x1f800220,lw_(0x1f800220));
 if(fault==6)world_precision_reset();
 if(fault==7)sw_(base+12,lw_(base+12)^1);
 R[16]=base+28;R[17]=0;R[18]=0x1f800000;R[20]=base;R[23]=0x1f800000;R[8]=4;
 R[4]=120;R[5]=0x00ff0000;sw_(R[29]+80,0x80119000);sw_(0x801191e0,0x00ffffff);
 g0_8008E174();
 unsigned count=0;
 for(unsigned i=0;i<4;i++){
  world_precision_vertex v;
  if(world_precision_packet(base+12+8*i,lw_(base+12+8*i),&v)){
   ++count;assert(v.producer_pc==0x800155d8);
   assert(v.z==xyz[i][2]);
   assert(v.native_word==lw_(0x1f800220+8*i));
   assert(v.source_address==0x1f800220+8*i);
   assert(v.x>=((int16_t)v.native_word)&&v.x<(int16_t)v.native_word+1.0);
  }
 }
 if(enabled&&shadow_enabled&&(!fault||fault==15))assert(count==4);else assert(count==0);
 return count;
}
static void certificate_tests(void) {
 for(unsigned count=4;count<=32;count*=2) {
  point_count=count;a2_world_shadow_configure(1);run(1,0,1);
  for(int fault=11;fault<=14;fault++) {
   a2_world_shadow_configure(1);run(1,fault,1);assert(injected);
  }
 }
 /* One unprojectable vertex invalidates only its own quad, not the batch. */
 point_count=8;a2_world_shadow_configure(1);run(1,15,1);
 {
  world_precision_vertex v[4];uint32_t words[9];A2WorldShadowGeometry g;
  for(unsigned j=0;j<4;j++)assert(world_precision_packet(0x80110008+4+8*j,lw_(0x80110008+4+8*j),&v[j]));
  for(unsigned j=0;j<9;j++)words[j]=lw_(0x80110008+4*j);
  assert(a2_world_shadow_geometry(v,4,1,0x80110008,words,9,&g));
  assert((int16_t)lw_(0x1f800220+8*5)==1023);
  /* Its source record carries no provenance, so the second quad cannot emit. */
  uint32_t dst[4]={0x80120000,0x80120008,0x80120010,0x80120018},src[4],w[4];
  for(unsigned j=0;j<4;j++){src[j]=0x1f800220+8*(4+j);w[j]=lw_(src[j]);sw_(dst[j],w[j]);}
  assert(!world_precision_emit(dst,w,src,4,shadow.object));
 }
 point_count=4;
 world_precision_vertex vertices[4];uint32_t packet[9];A2WorldShadowGeometry physical;
 uint32_t base=0x80110008;
 for(unsigned fraction=1024;fraction<=3072;fraction+=2048) {
  origin_fraction=fraction;a2_world_shadow_configure(1);run(1,0,1);
  for(unsigned j=0;j<4;j++)assert(world_precision_packet(base+4+8*j,lw_(base+4+8*j),&vertices[j]));
  for(unsigned j=0;j<9;j++)packet[j]=lw_(base+4*j);
  assert(a2_world_shadow_geometry(vertices,4,1,base,packet,9,&physical));
  /* An unrelated later AL22 transform must not retire an emitted shadow
   * certificate. Only a replacing certificate/configuration may do so. */
  a2_world_shadow_before(0x80015454u,R,1);
  a2_world_shadow_before(0x80015700u,R,1);
  assert(a2_world_shadow_geometry(vertices,4,1,base,packet,9,&physical));
  assert(physical.origin_q12[0]==(int)fraction && physical.h==96 && physical.ofx==160*65536 && physical.ofy==124*65536);
  const int xs[4]={-60,60,-60,60},zs[4]={500,500,700,700};
  for(unsigned j=0;j<4;j++) {
   assert(physical.z[j]==zs[j]);
   double expected=(xs[j]-fraction/4096.)*96/zs[j]*.75+160;
   assert(fabs(physical.x[j]-expected)<1e-12);
   assert(fabs(physical.y[j]-(20.*96/zs[j]+124))<1e-12);
  }
  /* Material mutation does not touch any XY provenance. */
  for(unsigned j=0;j<9;j+=2) {
   packet[j]^=1;assert(!a2_world_shadow_geometry(vertices,4,1,base,packet,9,&physical));packet[j]^=1;
  }
  assert(!a2_world_shadow_geometry(vertices,4,1,base+4,packet,9,&physical));
  world_precision_vertex bad[4];memcpy(bad,vertices,sizeof bad);bad[3].source_address=bad[2].source_address;
  assert(!a2_world_shadow_geometry(bad,4,1,base,packet,9,&physical));
  memcpy(bad,vertices,sizeof bad);bad[3].camera_generation++;
  assert(!a2_world_shadow_geometry(bad,4,1,base,packet,9,&physical));
  a2_world_shadow_configure(0);assert(!a2_world_shadow_geometry(vertices,4,1,base,packet,9,&physical));
 }
 origin_fraction=1024;
}
int main(void){
 certificate_tests();
 static uint8_t ram[PSX_RAM_SIZE],scratch[0x400];static uint32_t regs[32],gte[64];
 /* Precision alone must preserve the original shadow raster. */
 run(1,0,0);
 for(int fault=0;fault<=10;fault++){
  a2_world_shadow_configure(1);
  run(0,fault,1);memcpy(ram,PSX_RAM,sizeof ram);memcpy(scratch,PSX_SCRATCH,sizeof scratch);memcpy(regs,R,sizeof regs);
  for(int i=0;i<64;i++)gte[i]=i<32?gte_data_read(i):gte_ctrl_read(i-32);
  a2_world_shadow_configure(1);run(1,fault,1);
  assert(!memcmp(ram,PSX_RAM,sizeof ram)&&!memcmp(scratch,PSX_SCRATCH,sizeof scratch)&&!memcmp(regs,R,sizeof regs));
  for(int i=0;i<64;i++)assert(gte[i]==(i<32?gte_data_read(i):gte_ctrl_read(i-32)));
 }
 /* Disabling transport keeps precision active and preserves native state. */
 a2_world_shadow_configure(1);run(1,0,1);
 memcpy(ram,PSX_RAM,sizeof ram);memcpy(scratch,PSX_SCRATCH,sizeof scratch);memcpy(regs,R,sizeof regs);
 for(int i=0;i<64;i++)gte[i]=i<32?gte_data_read(i):gte_ctrl_read(i-32);
 a2_world_shadow_configure(0);run(1,0,0);
 assert(world_precision_enabled&&world_camera_enabled);
 assert(!memcmp(ram,PSX_RAM,sizeof ram)&&!memcmp(scratch,PSX_SCRATCH,sizeof scratch)&&!memcmp(regs,R,sizeof regs));
 for(int i=0;i<64;i++)assert(gte[i]==(i<32?gte_data_read(i):gte_ctrl_read(i-32)));
 a2_world_shadow_configure(1);run(1,0,1);
 puts("world shadow: default-off, explicit enable, pending/finished transitions, retained RTPT/OT and native equality PASS");
 return 0;
}
