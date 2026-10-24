#define A2_NATIVE_ACTOR_SOURCES 1
#include "native_actor_sources.h"
#include "../assets/native_chest_sources.h"
#include "fixtures/native_pc00_fixture.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../src/psx_rt.h"
/* Actual single generated resident function, with its real native loop. */
#include "../gen/scps_008.c"
uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];uint32_t R[32],HI,LO,psx_next,psx_work,a2_ramwatch;
int psx_bb_budget=1000000;
void psx_bb_fire(void){psx_bb_budget=1000000;}
void a2_ramwatch_hit(uint32_t a,uint32_t v,int n){(void)a;(void)v;(void)n;}
uint32_t psx_mmio_read(uint32_t a,int n){(void)a;(void)n;return 0;}
void psx_mmio_write(uint32_t a,uint32_t v,int n){(void)a;(void)v;(void)n;}
static unsigned bound;static uint64_t generation;static char key[64];static uint8_t hash[32];
static uint32_t expected_address=0x100000;
int a2_native_actor_snapshot_source_bind(uint32_t a,const char*k,const uint8_t*h,uint64_t g){assert(a==expected_address);strcpy(key,k);memcpy(hash,h,32);generation=g;bound=1;return 1;}
void a2_native_actor_snapshot_source_unbind(uint32_t a){if((a&0x1fffff)==expected_address)bound=0;}
static void setup(unsigned which){
 a2_native_actor_sources_reset();memset(PSX_RAM,0,sizeof PSX_RAM);memset(R,0,sizeof R);bound=0;
 expected_address=0x100000;
 memcpy(PSX_RAM+0x2492c,chest_relocation_code,sizeof chest_relocation_code);
 memcpy(PSX_RAM+0x100000,which?t03_original:t02_original,1760);
 a2_native_actor_sources_init(PSX_RAM,sizeof PSX_RAM);a2_native_actor_sources_configure(1);
 R[4]=0x80100000;R[29]=0x801ff000;R[31]=0x80040000;
}
static void pc00_setup(void){
 setup(0);expected_address=0x175cb4;
 pc00_fixture("native_pc00_source.bin",PSX_RAM+expected_address,31216);
 pc00_fixture("native_pc00_tables.bin",PSX_RAM+0x4fc74,1024);
 R[4]=0x80175cb4;R[5]=0x8004fc74;R[6]=0x8004fc88;R[7]=0;
}
static void pc00_sources(void){
 static uint8_t native[PSX_RAM_SIZE],relocated[31216];uint32_t regs[32],work,next;
 pc00_fixture("native_pc00_relocated.bin",relocated,sizeof relocated);
 pc00_setup();a2_native_actor_sources_configure(0);psx_work=0;f_8002492C();
 memcpy(native,PSX_RAM,sizeof native);memcpy(regs,R,sizeof regs);work=psx_work;next=psx_next;
 assert(!memcmp(PSX_RAM+expected_address,relocated,sizeof relocated));
 pc00_setup();psx_work=0;f_8002492C();
 assert(bound&&!strcmp(key,"PC00")&&!memcmp(hash,pc00_sha,32));
 assert(!memcmp(native,PSX_RAM,sizeof native)&&!memcmp(regs,R,sizeof regs)&&work==psx_work&&next==psx_next);
 uint64_t old=generation;R[4]=0x80175cb4;f_8002492C();assert(bound&&old==generation);
 sb_(0x80175cb4+31215,lb_(0x80175cb4+31215));assert(!bound);
 R[4]=0x80175cb4;f_8002492C();assert(!bound);
 pc00_setup();PSX_RAM[expected_address+31215]^=1;f_8002492C();assert(!bound);
 pc00_setup();PSX_RAM[expected_address+0xbec]^=1;f_8002492C();assert(!bound);
 pc00_setup();f_8002492C();assert(bound);PSX_RAM[expected_address+31215]^=1;
 R[4]=0x80175cb4;f_8002492C();assert(!bound);
 pc00_setup();a2_native_actor_sources_before_relocation(0x801ff000);
 a2_native_actor_sources_after_relocation(0x801ff000,0);assert(!bound);
 puts("PC00 sources: exact original hash, full relocated capture equality, native state equality, tail/vertex/mutation/wrap rejection pass");
}
static void catalogue_source(const unsigned char *blob,size_t bytes,const char *expected_hash){
 static unsigned char native[PSX_RAM_SIZE];uint32_t regs[32],work,next;
 unsigned char wanted[32];for(unsigned j=0;j<32;j++){
  unsigned value;assert(sscanf(expected_hash+2*j,"%2x",&value)==1);wanted[j]=(unsigned char)value;
 }
 assert(bytes>=304&&bytes<=0x80000);
 for(unsigned address=0x100000;address<=0x140000;address+=0x40000){
  for(int enabled=0;enabled<2;enabled++){
   setup(0);expected_address=address;memcpy(PSX_RAM+address,blob,bytes);
   a2_native_actor_sources_configure(enabled);R[4]=0x80000000u+address;
   R[5]=R[6]=R[7]=0;psx_work=0;f_8002492C();
   if(!enabled){
    assert(!bound);memcpy(native,PSX_RAM,sizeof native);memcpy(regs,R,sizeof regs);work=psx_work;next=psx_next;
   }else{
    assert(bound&&!strcmp(key,(const char*)blob)&&!memcmp(hash,wanted,32));
    assert(!memcmp(native,PSX_RAM,sizeof native)&&!memcmp(regs,R,sizeof regs)&&work==psx_work&&next==psx_next);
    uint64_t old=generation;R[4]=0x80000000u+address;f_8002492C();assert(bound&&generation==old);
    sb_(0x80000000u+address+(uint32_t)bytes-1,lb_(0x80000000u+address+(uint32_t)bytes-1));assert(!bound);
   }
  }
  setup(0);expected_address=address;memcpy(PSX_RAM+address,blob,bytes);PSX_RAM[address+bytes-1]^=1;
  R[4]=0x80000000u+address;R[5]=R[6]=R[7]=0;f_8002492C();assert(!bound);
 }
}
static void catalogue_examples(void){
 static unsigned char blob[15800];
 pc00_fixture("native_e03_source.bin",blob,1800);
 catalogue_source(blob,1800,"d996617b1fd8626bfd3eae660596cc2b2dededc6adc01744fcf4453c6b193a56");
 pc00_fixture("native_n01_source.bin",blob,15800);
 catalogue_source(blob,15800,"a167884badd1c57afde46938c1c0b27143f7ce24824fa029534a3858b0434831");
 pc00_fixture("native_t01_source.bin",blob,724);
 catalogue_source(blob,724,"b1527bccb5db2873378cda55247347011d52250fbe7e0df0acc5bd4dcd7f109e");
 puts("actor source catalogue: enemy E03, NPC N01 and environment T01, two addresses, exact native relocation equality and mutation retirement pass");
}
int main(int argc,char **argv){
 if(argc==2){
  FILE *list=fopen(argv[1],"r");assert(list);char path[4096];static unsigned char blob[0x80000];unsigned count=0;
  while(fgets(path,sizeof path,list)){
   path[strcspn(path,"\r\n")]=0;const char *name=strrchr(path,'/');assert(name&&strlen(++name)==68);
   FILE *f=fopen(path,"rb");assert(f);size_t bytes=fread(blob,1,sizeof blob,f);assert(fgetc(f)==EOF);assert(!fclose(f));
   catalogue_source(blob,bytes,name);count++;
  }
  assert(!ferror(list)&&!fclose(list));printf("actor source corpus: %u original blobs, two relocation addresses, full native state equality and mutation checks pass\n",count);return 0;
 }
 catalogue_examples();
 pc00_sources();
 setup(0);f_8002492C();assert(bound&&generation&&!strcmp(key,"T02")&&hash[0]==0xfb);
 assert(PSX_RAM[0x10001f]==1&&lw_(0x80100020)==0x80100130);
 uint64_t old=generation;R[4]=0x80100000;f_8002492C();assert(bound&&generation==old&&R[2]==1);
 /* Native same-value writes revoke identity, including the very last byte.
  * The already-relocated shortcut cannot manufacture a replacement proof. */
 sb_(0xa01006df,lb_(0xa01006df));assert(!bound);
 R[4]=0x80100000;f_8002492C();assert(!bound);
 setup(1);f_8002492C();assert(bound&&!strcmp(key,"T03")&&hash[0]==0xd7&&generation>old);
 a2_native_actor_sources_invalidate(0x100001,1);assert(!bound);
 setup(0);PSX_RAM[0x100301]^=1;f_8002492C();assert(!bound);
 setup(0);PSX_RAM[0x10001f]=1;f_8002492C();assert(!bound);
 setup(0);sw_(0x8002492c,lw_(0x8002492c)^1);f_8002492C();assert(!bound);
 setup(0);a2_native_actor_sources_before_relocation(0x80100000);
 a2_native_actor_sources_after_relocation(0x80110000,0);assert(!bound);
 setup(0);f_8002492C();assert(bound);a2_native_actor_sources_invalidate(0x1ffffe,4);assert(!bound);
 /* Observer ON and OFF execute the identical relocation, including all UV,
  * palette/tpage edits, native registers and cooperative loop counters. */
 static uint8_t native[PSX_RAM_SIZE];uint32_t regs[32],work,next;
 setup(0);a2_native_actor_sources_configure(0);psx_work=0;f_8002492C();
 memcpy(native,PSX_RAM,sizeof native);memcpy(regs,R,sizeof regs);work=psx_work;next=psx_next;
 setup(0);psx_work=0;f_8002492C();assert(bound);
 assert(!memcmp(native,PSX_RAM,sizeof native)&&!memcmp(regs,R,sizeof regs)&&work==psx_work&&next==psx_next);
 puts("actor sources: exact T02/T03 real relocation, stale/modified/code/wrap rejection and native equality pass");
 return 0;
}
