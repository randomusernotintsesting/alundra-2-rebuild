/* Actual generated GAME00 continuations; the SDK calls are returned explicitly.
 * This proves boundary placement, not an emulated asynchronous DMA scheduler. */
#include "psx_rt.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../gen/game00_004.c"
#include "../gen/event00_011.c"
#include "../gen/event00_013.c"
uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t R[32], HI, LO, psx_next, psx_work, a2_ramwatch;
int psx_bb_budget=1000000;
static unsigned notified, dma_reads;
static uint32_t dma_control;
static unsigned event_path,event_page;
/* Independent retained EVENT source words, including continuation load. */
static const uint32_t event_prefix[]={
 0x27bdffe0u,0xafb10014u,0x3c11800bu,0x3c04800fu,0x8e237754u,
 0x2484e788u,0xafbf0018u,0xafb00010u,0x00031080u,0x00431021u,
 0x00021080u,0x0c00cc49u,0x00442021u,0x8e227754u,0x00000000u,
 0x00022040u,0x00822021u,0x000420c0u,0x00822023u,0x00042080u,
 0x3c02800fu,0x2442e6d0u,0x0c00cbd6u,0x00822021u,0x3c10800bu,
 0x8e227754u,0x26107668u,0x00022100u,0x00822021u,0x00042080u,
 0x0c00cbbau,0x00902021u,0x8e227754u};
static const uint32_t event_alt_prefix[]={
 0x27bdffe0u,0xafbf0018u,0xafb10014u,0x14800006u,0xafb00010u,
 0x3c02800fu,0x2442ffc8u,0xa0400018u,0x080266f5u,0xa0400074u,
 0x3c02800fu,0x2442ffc8u,0x24030001u,0xa0430018u,0xa0430074u,
 0x3c10800fu,0x3c04800fu,0x9203f700u,0x24840080u,0x00031080u,
 0x00431021u,0x00021080u,0x0c00cc49u,0x00442021u,0x9202f700u,
 0x00000000u,0x00022040u,0x00822021u,0x000420c0u,0x00822023u,
 0x00042080u,0x3c02800fu,0x2442ffc8u,0x0c00cbd6u,0x00822021u,
 0x3c11800bu,0x9203f700u,0x8e243308u,0x000310c0u,0x00431023u,
 0x00021080u,0x00431023u,0x00021080u,0x00431023u,0x00021140u,
 0x00431021u,0x000210c0u,0x00822021u,0x0c00cbbau,0x24846a04u,
 0x9202f700u};
static const uint32_t retained_prefix[]={
 0x27bdffe0u,0xafb00010u,0x3c108011u,0x261033d0u,0xafbf0018u,
 0xafb10014u,0x8e114140u,0x0c00cbbau,0x2624209cu,0x8e044148u,
 0x0c00cbbau,0x24840020u,0x3c020001u};
void psx_bb_fire(void){abort();}
void psx_break(uint32_t x){(void)x;abort();}
void psx_syscall_at(uint32_t x){(void)x;abort();}
void a2_ramwatch_hit(uint32_t a,uint32_t b,int c){(void)a;(void)b;(void)c;abort();}
uint32_t psx_mmio_read(uint32_t a,int n){assert(a==0x1f8010a8u&&n==4);++dma_reads;return dma_control;}
void psx_mmio_write(uint32_t a,uint32_t b,int n){(void)a;(void)b;(void)n;abort();}
void gpu_scene_submit_complete(void){
 ++notified;
 if(event_path){
  assert(R[2]==0&&R[31]==(event_path==1?0x80093648u:0x80099c60u));
  if(event_path==1){assert(lw_(0x800b7754)==event_page);assert(lw_(0x800b7758)==0x800b7668u+68*event_page);}
  else {assert(lb_(0x800ef700)==event_page);assert(lw_(0x800efa30)==0x80180000u+27400*event_page);}
  return;
 }
 /* At notification, BOTH front/back OT pairs are still unswapped. */
 assert(lw_(0x80117510)==0x80115470u&&lw_(0x80117514)==0x801133d0u);
 assert(lw_(0x80117518)==0x80110000u&&lw_(0x8011751c)==0x80110100u);
 assert(R[2]==0&&R[31]==0x80086a30u);
}
static void setup(void){
 memset(PSX_RAM,0,sizeof PSX_RAM);memset(R,0,sizeof R);
 memcpy(PSX_RAM+0x86a00,retained_prefix,sizeof retained_prefix);
 sw_(0x800811d8,4);sw_(0x800553dc,0x8005539c);
 sw_(0x800553a4,0x8003468c);sw_(0x800553b4,0x800345f0);
 sw_(0x800554f8,0x1f8010a8);
 sw_(0x8005550c,17);sw_(0x80055510,17);
 sw_(0x80117510,0x80115470);sw_(0x80117514,0x801133d0);
 sw_(0x80117518,0x80110000);sw_(0x8011751c,0x80110100);
 R[29]=0x801ff000;R[31]=0x80086878;R[16]=123;R[17]=456;
 notified=0;dma_reads=0;dma_control=0;psx_next=0;event_path=0;
}
static void to_boundary(void){
 g0_80086A00();
 assert(notified==0&&psx_next==0x80032ee8u&&R[31]==0x80086a24u);
 assert(R[4]==0x8011750cu);
 R[2]=0;g0_80086A24();
 assert(notified==0&&psx_next==0x80032ee8u&&R[31]==0x80086a30u);
 assert(R[4]==0x80110020u);R[2]=0;
}
static void event_setup(unsigned path,unsigned page){
 setup();event_path=path;event_page=page;sw_(0x800811d8,5);
 memcpy(PSX_RAM+0x935c8,event_prefix,sizeof event_prefix);
 memcpy(PSX_RAM+0x99b98,event_alt_prefix,sizeof event_alt_prefix);
 sw_(0x800b7754,page);sw_(0x800b7758,0x800b7668+68*page);
 sb_(0x800ef700,page);sw_(0x800b3308,0x80180000);sw_(0x800efa30,0x80180000+27400*page);
 if(path==1){
  ev_800935C8();assert(!notified&&psx_next==0x80033124u&&R[4]==0x800ee788u+20*page);
  R[2]=0;ev_800935FC();assert(!notified&&psx_next==0x80032f58u&&R[4]==0x800ee6d0u+92*page);
  R[2]=0;ev_80093628();assert(!notified&&psx_next==0x80032ee8u&&R[4]==0x800b7668u+68*page);
 }else{
  R[4]=1;ev_80099B98();assert(!notified&&psx_next==0x80033124u&&R[4]==0x800f0080u+20*page);
  R[2]=0;ev_80099BF8();assert(!notified&&psx_next==0x80032f58u&&R[4]==0x800effc8u+92*page);
  R[2]=0;ev_80099C24();assert(!notified&&psx_next==0x80032ee8u&&R[4]==0x80180000u+27400*page+27140);
 }
 R[2]=0;
}
static void event_return(void){if(event_path==1)ev_80093648();else ev_80099C60();}
static void event_cases(void){
 static uint8_t expected_ram[PSX_RAM_SIZE];uint32_t expected_r[32];
 for(unsigned path=1;path<=2;path++)for(unsigned page=0;page<2;page++){
  event_setup(path,page);event_return();assert(notified==1&&dma_reads==1&&psx_next==0x80032d18u);
  if(path==1)assert(lw_(0x800b7754)==!page&&lw_(0x800b7758)==0x800b7668u+68*!page);
  else assert(lb_(0x800ef700)==!page&&lw_(0x800efa30)==0x80180000u+27400*!page);
  memcpy(expected_ram,PSX_RAM,sizeof PSX_RAM);memcpy(expected_r,R,sizeof R);
  event_setup(path,page);dma_control=0x01000000;event_return();assert(!notified&&dma_reads==1);
  assert(!memcmp(expected_ram,PSX_RAM,sizeof PSX_RAM)&&!memcmp(expected_r,R,sizeof R));
  unsigned offset=path==1?0x935c8u:0x99b98u;
  unsigned bytes=path==1?sizeof event_prefix:sizeof event_alt_prefix;
  for(unsigned k=0;k<bytes;k+=4){event_setup(path,page);PSX_RAM[offset+k]^=1;event_return();assert(!notified&&!dma_reads);}
  for(unsigned k=0;k<9;k++){
   event_setup(path,page);
   switch(k){
    case 0:sw_(0x800811d8,4);break;
    case 1:R[2]=UINT32_MAX;break;
    case 2:sw_(0x80055510,16);break;
    case 3:sw_(0x800553dc,0x80055400);break;
    case 4:sw_(0x800553a4,0x80034668);break;
    case 5:sw_(0x800553b4,0x800342f8);break;
    case 6:sw_(0x800554f8,0x1f8010b8);break;
    case 7:R[31]=path==1?0x800935fcu:0x80099c24u;break;
    case 8:R[31]=0x80086a30;break;
   }
   event_return();assert(!notified&&!dma_reads);
  }
 }
}
int main(void){
 event_cases();
 setup();to_boundary();g0_80086A30();
 assert(notified==1&&dma_reads==1);
 assert(lw_(0x80117510)==0x801133d0u&&lw_(0x80117514)==0x80115470u);
 assert(lw_(0x80117518)==0x80110100u&&lw_(0x8011751c)==0x80110000u);
 assert(R[16]==123&&R[17]==456&&R[29]==0x801ff000&&psx_next==0x80086878u);
 uint8_t expected_ram[PSX_RAM_SIZE];uint32_t expected_r[32];
 memcpy(expected_ram,PSX_RAM,sizeof PSX_RAM);memcpy(expected_r,R,sizeof R);
 /* Non-native-mesh notification is a no-op; guest writes/results stay exact. */
 setup();to_boundary();dma_control=0x01000000;g0_80086A30();
 assert(!notified);assert(!memcmp(expected_ram,PSX_RAM,sizeof PSX_RAM));
 assert(!memcmp(expected_r,R,sizeof R));
 for(unsigned k=0;k<13;k++){
  setup();to_boundary();PSX_RAM[0x86a00+4*k]^=1;g0_80086A30();assert(!notified);
 }
 for(unsigned k=0;k<8;k++){
  setup();to_boundary();
  switch(k){
   case 0:sw_(0x800811d8,5);break;
   case 1:R[2]=UINT32_MAX;break;
   case 2:sw_(0x80055510,16);break;
   case 3:sw_(0x800553dc,0x80055400);break;
   case 4:sw_(0x800553a4,0x80034668);break;
   case 5:sw_(0x800553b4,0x800342f8);break;
   case 6:sw_(0x800554f8,0x1f8010b8);break;
   case 7:R[31]=0x80086a24;break;
  }
  g0_80086A30();assert(!notified);
 }
 puts("scene submit: GAME00 + both EVENT generated boundaries/pages, guest state, all source words and code/queue/DMA guards PASS");
 return 0;
}
