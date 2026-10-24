/* Actual generated EVENT entry/continuation observations, with retained
 * native pose output supplied between callbacks. No game or GPU is run. */
#define A2_NATIVE_ACTOR_SNAPSHOT 1
#include "psx_rt.h"
#include "fixtures/native_event_fixture.h"
#include "../gen/event00_006.c"
#include "../gen/event00_008.c"
uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
uint32_t R[32],HI,LO,psx_next,psx_work,psx_frame_no,a2_ramwatch;
int psx_bb_budget=1000000;
void psx_bb_fire(void){abort();}
void psx_break(uint32_t x){(void)x;abort();}
void psx_syscall_at(uint32_t x){(void)x;abort();}
void a2_ramwatch_hit(uint32_t a,uint32_t b,int c){(void)a;(void)b;(void)c;abort();}
uint32_t psx_mmio_read(uint32_t a,int n){(void)a;(void)n;abort();}
void psx_mmio_write(uint32_t a,uint32_t b,int n){(void)a;(void)b;(void)n;abort();}
static uint32_t ctrl[32],data_regs[32];
uint32_t gte_ctrl_read(int r){return ctrl[r&31];}
void gte_ctrl_write(int r,uint32_t n){ctrl[r&31]=n;}
void gte_cmd(uint32_t n){(void)n;abort();}
uint32_t gte_data_read(int r){return data_regs[r&31];}
void gte_data_write(int r,uint32_t n){data_regs[r&31]=n;}
static void setup(int enabled){
 memset(PSX_RAM,0,sizeof PSX_RAM);memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);memset(R,0,sizeof R);
 memset(ctrl,0,sizeof ctrl);memset(data_regs,0,sizeof data_regs);event_fixture(PSX_RAM);
 HI=0x12345678;LO=0x87654321;psx_next=psx_work=0;psx_frame_no=6000;psx_bb_budget=1000000;
 a2_native_actor_snapshot_init(PSX_RAM,sizeof PSX_RAM);a2_native_actor_snapshot_configure(enabled);
 assert(a2_native_actor_snapshot_source_bind(0x80164330,"FRITTO",event_intro_sha,123));
}
static void route(void){
 R[22]=1728;R[19]=0x801d0000;R[29]=0x801f0000;ev_8008BB98();assert(psx_next==0x8008bfb8);
 /* The real init continuation clears this slot. Restore retained initialized
  * entity/source/arena output before observing the later builder. */
 event_fixture(PSX_RAM);memset(R,0,sizeof R);R[29]=0x801f0000;ev_80088A04();assert(psx_next==0x80088b28);
 memset(R,0,sizeof R);R[29]=0x801f0000;R[20]=0x800ce6e8;sw_(R[29]+2572,0x800d94c8);
 ev_80088E38();assert(psx_next==0x80025c58&&R[4]==0x800ce7ec);
 sw_(R[29]+2136,25284608);sw_(R[29]+2140,(uint32_t)-4608000);sw_(R[29]+2144,610304);
 R[21]=16;ev_80088EB8();assert(psx_next==0x80089610);
 for(unsigned k=0;k<16;k++){
  R[20]=0x800ce6e8;R[21]=k;R[19]=0x800d94c8+80*k+58;sw_(R[29]+2572,0x800d94c8+80*k);
  ev_80089550();assert(psx_next==0x80088ec0&&R[21]==k+1&&lw_(R[29]+2572)==0x800d94c8+80*(k+1));
 }
 /* The main native submission assignment precedes the shared camera hook;
  * retained RAM held this descriptor's subsequent effects submission. */
 sw_(0x800d76f0+20,0x800d9428);a2_native_actor_snapshot_capture(6000,0x800d76f0,256,160<<16,86<<16);
}
int main(void){
 static uint8_t ram[PSX_RAM_SIZE],scratch[0x400];uint32_t regs[32],gte[64],state[5];
 setup(0);route();memcpy(ram,PSX_RAM,sizeof ram);memcpy(scratch,PSX_SCRATCH,sizeof scratch);memcpy(regs,R,sizeof regs);
 memcpy(gte,ctrl,sizeof ctrl);memcpy(gte+32,data_regs,sizeof data_regs);
 state[0]=HI;state[1]=LO;state[2]=psx_next;state[3]=psx_work;state[4]=psx_bb_budget;
 setup(1);route();const A2ActorFrame *s=a2_native_actor_snapshot_current();
 assert(s->valid&&s->instance_count==1&&s->part_count==16&&s->instances[0].fallback==A2_ACTOR_UNKNOWN_ANIMATION);
 assert(s->instances[0].generation_known&&s->instances[0].renderer_root_q12[1]==-4608000);
 for(unsigned k=0;k<16;k++)assert(s->parts[k].valid&&s->parts[k].visible&&s->parts[k].source_mesh_index==k);
 assert(!memcmp(ram,PSX_RAM,sizeof ram)&&!memcmp(scratch,PSX_SCRATCH,sizeof scratch)&&!memcmp(regs,R,sizeof regs));
 assert(!memcmp(gte,ctrl,sizeof ctrl)&&!memcmp(gte+32,data_regs,sizeof data_regs));
 assert(state[0]==HI&&state[1]==LO&&state[2]==psx_next&&state[3]==psx_work&&state[4]==(uint32_t)psx_bb_budget);
 puts("EVENT snapshot guest: actual generated allocation/begin/instance/root/16 part continuations; exact RAM/scratch/GPR/GTE/HI/LO/work/pc/budget OFF/ON equality pass");
 return 0;
}
