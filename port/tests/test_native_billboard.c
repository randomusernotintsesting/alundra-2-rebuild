/* Execute the genuine retained complete billboard loop, including projection,
 * clipping, fog, FT4 component mixing and OT insertion. Only its object,
 * descriptor list and camera are fixture inputs. No synthetic GP0 emitter. */
#define A2_WORLD_PRECISION 1
#define A2_NATIVE_BILLBOARD 1
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/psx_rt.h"
#include "../src/gte.c"
#include "../src/interp.c"
#include "../src/native_billboard.c"
#include "fixtures/native_chest_packets.h"
uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
uint32_t R[32],HI,LO,psx_next,psx_work,psx_frame_no=4396,a2_ramwatch;
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
void a2_world_shadow_before(uint32_t p,const uint32_t*r,int v){(void)p;(void)r;(void)v;}
void a2_world_shadow_project(uint32_t p,const uint32_t*r){(void)p;(void)r;}
void a2_world_shadow_store(uint32_t p,uint32_t a,uint32_t w,const uint32_t*r){(void)p;(void)a;(void)w;(void)r;}
static int reward_precision;
static unsigned run(int enabled,int fault){
 memset(PSX_RAM,0,sizeof PSX_RAM);memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);memset(R,0,sizeof R);
 memcpy(PSX_RAM+0x10000,chest_al22,sizeof chest_al22);
 a2_native_billboard_init(PSX_RAM,sizeof PSX_RAM);a2_native_billboard_configure(enabled);
 world_precision_configure(1);world_camera_configure(reward_precision);HI=LO=psx_work=psx_next=0;psx_bb_budget=1000000;
 for(int i=0;i<32;i++){gte_ctrl_write(i,0);gte_data_write(i,0);}
 const uint32_t obj=0x8011763c,desc=0x8012a4f8+32*72,list=0x8012a4b8,base=0x80110000;
 const int16_t mat[10]={4096,0,0,0,4096,0,0,0,4096,0};
 memcpy(PSX_RAM+0x180000,mat,sizeof mat);
 sw_(obj,1);sw_(obj+4,base);sw_(obj+8,base+4096);sw_(obj+12,0x80119000);
 sw_(obj+20,list);sw_(obj+28,0x80180000);sw_(obj+32,0x80180000);sw_(obj+36,0x80180000);
 sw_(obj+44,1024);sw_(obj+48,0);sw_(obj+52,0);
 sw_(list,1);sw_(list+4,desc);sw_(list+8,0);
 sh_(desc,0xc000);sh_(desc+4,27);sh_(desc+6,0x7db8);
 sw_(desc+8,60u*4096u);sw_(desc+12,20u*4096u);sw_(desc+16,700u*4096u);
 sw_(desc+44,0x2c808080);sh_(desc+48,0xe000);sh_(desc+50,0x1f1f);
 sb_(desc+52,32);sb_(desc+53,32);
 gte_ctrl_write(24,160<<16);gte_ctrl_write(25,124<<16);gte_ctrl_write(26,96);
 if(fault==1)sw_(desc+8,32769u*4096u);
 if(fault==2)memcpy(PSX_RAM+0x181000,PSX_RAM+(obj&0x1fffff),0x5c);
 if(fault==3)sw_(0x80010000,lw_(0x80010000)^1);
 if(fault==4)gte_ctrl_write(26,0);
 R[29]=0x801ff000;R[31]=fault==5?0x80025460:0x8002542c;R[4]=fault==2?0x80181000:obj;
 uint32_t target=fault==5?0x80025460u:0x8002542cu,pc=0x80014318;
 for(unsigned segments=0;pc!=target;segments++){
  assert(segments<12);psx_interp(pc);pc=psx_next;
  if(pc==0x800146c4u){
   if(fault==6)sw_(desc+8,lw_(desc+8));
   if(fault==7)sw_(0x80010000,lw_(0x80010000));
   if(fault==8)sw_(0x80180000,lw_(0x80180000));
   if(fault==9)gte_ctrl_write(26,97);
   if(fault==10)world_precision_reset();
  }
 }
 assert(psx_next==target);
 if(fault==11)sw_(base+4,lw_(base+4));
 if(fault==12)sb_(base+9,lb_(base+9));
 if(fault==13)a2_native_billboard_reset();
 uint64_t token=a2_native_billboard_token(base+8,lw_(base+8));
 if(enabled&&!fault){
  assert(token);double depth=0;uint32_t words[9];memcpy(words,PSX_RAM+0x110008,sizeof words);
  words[1]^=1;assert(!a2_native_billboard_consume(base+8,token,words,9,&depth));words[1]^=1;
  assert(!a2_native_billboard_consume(base+8,token,words,8,&depth));
  assert(!a2_native_billboard_consume(base+4,token,words,9,&depth));
  assert(a2_native_billboard_consume(base+8,token,words,9,&depth));
  assert(depth==700.0*4092.0/4096.0);
  assert(!a2_native_billboard_consume(base+8,token,words,9,&depth));
 }else assert(!token);
 return token!=0;
}
int main(void){
 static uint8_t ram[PSX_RAM_SIZE],scratch[0x400];static uint32_t regs[32],gte[64],state[5];
 for(int fault=0;fault<=13;fault++){
  run(0,fault);memcpy(ram,PSX_RAM,sizeof ram);memcpy(scratch,PSX_SCRATCH,sizeof scratch);memcpy(regs,R,sizeof regs);
  for(int i=0;i<64;i++)gte[i]=i<32?gte_data_read(i):gte_ctrl_read(i-32);
  state[0]=HI;state[1]=LO;state[2]=psx_next;state[3]=psx_work;state[4]=psx_bb_budget;
  run(1,fault);
  assert(!memcmp(ram,PSX_RAM,sizeof ram)&&!memcmp(scratch,PSX_SCRATCH,sizeof scratch)&&!memcmp(regs,R,sizeof regs));
  for(int i=0;i<64;i++)assert(gte[i]==(i<32?gte_data_read(i):gte_ctrl_read(i-32)));
  assert(state[0]==HI&&state[1]==LO&&state[2]==psx_next&&state[3]==psx_work&&state[4]==(uint32_t)psx_bb_budget);
 }
 reward_precision=1;run(1,0);
 for(unsigned i=0;i<4;i++){
  uint32_t a=0x8011000c+8*i;world_precision_vertex v;
  assert(a2_native_billboard_vertex(a,lw_(a),&v));
  double x=160+(59.75+(i&1?32:-32))*16368.0/4092.0*96/700*.75;
  double y=124+(20+(i&2?32:-32))*16368.0/4092.0*96/700;
  assert(fabs(v.x-x)<1.0/65536&&fabs(v.y-y)<1.0/65536);
 }
 for(int fault=1;fault<=13;fault++){
  run(1,fault);world_precision_vertex v;
  assert(!a2_native_billboard_vertex(0x8011000c,lw_(0x8011000c),&v));
 }
 puts("native billboard: actual retained projection/FT4/OT and full native equality PASS");return 0;
}
