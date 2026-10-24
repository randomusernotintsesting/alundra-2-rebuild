#include "world_shadow.h"
#include "psx_rt.h"
#include "world_precision.h"
#include "world_shadow_code.h"
#include <limits.h>
#include <math.h>
#include <string.h>
static struct {
 unsigned wanted,active,finished,count,groups,group,pending,stored,verified_group;
 uint32_t invalid; /* indices whose native RTPT word has no provenance */
 uint32_t packet,origin[3],matrix[5],controls[3],inputs[34][3],projected_words[32];
 uint64_t object,code_version;
 world_precision_vertex vertices[3];
} shadow;
static int shadow_enabled;
#define SHADOW_CERTIFICATES 64u
static struct {
 uint64_t generation,version;
 unsigned count;
 uint32_t invalid,words[32];
 double wide_scale; /* horizontal squeeze in force when the batch was projected */
 int32_t origin[3],h,ofx,ofy;
 int16_t rotation[9];
 double camera[32][3];
} certificates[SHADOW_CERTIFICATES];
static struct {uint64_t generation,version;uint32_t address,words[9];} materials[256];
static unsigned material_slot(uint32_t address){return ((address>>2)^(address>>12))&255u;}
static void certify_batch(void) {
 /* Ordinary AL22 transforms also reach the return hook. They must not
  * clear a previously emitted shadow still waiting in the ordering table. */
 if(!shadow.finished || !shadow.object)return;
 unsigned slot=(unsigned)(shadow.object%SHADOW_CERTIFICATES);
 memset(&certificates[slot],0,sizeof certificates[slot]);
 int16_t rotation[9];
 for(unsigned j=0;j<9;j++)rotation[j]=(int16_t)(shadow.matrix[j/2]>>(16*(j%2)));
 double camera[32][3]={{0}};
 for(unsigned i=0;i<shadow.count;i++) {
  if(shadow.invalid>>i&1)continue;
  int64_t delta[3];
  for(unsigned j=0;j<3;j++) {
   delta[j]=(int64_t)(int32_t)shadow.inputs[i][j]-(int32_t)shadow.origin[j];
   /* Reject SUBU wrapping; these full source coordinates must describe
    * the same native packed point already verified by the RTPT observer. */
   if(delta[j]<INT32_MIN || delta[j]>INT32_MAX)return;
  }
  for(unsigned j=0;j<3;j++) {
   int64_t sum=0;for(unsigned k=0;k<3;k++)sum+=(int64_t)rotation[j*3+k]*delta[k];
   camera[i][j]=(double)sum/16777216.0;
  }
  double z=camera[i][2];
  if(!isfinite(z)||z<1||z>=65536 || !shadow.controls[2] || shadow.controls[2]>=2*z)return;
 }
 certificates[slot].generation=shadow.object;certificates[slot].version=shadow.code_version;
 certificates[slot].count=shadow.count;certificates[slot].invalid=shadow.invalid;certificates[slot].wide_scale=world_precision_wide_scale();
 memcpy(certificates[slot].words,shadow.projected_words,sizeof certificates[slot].words);
 for(unsigned j=0;j<3;j++)certificates[slot].origin[j]=(int32_t)shadow.origin[j];
 memcpy(certificates[slot].rotation,rotation,sizeof rotation);
 certificates[slot].ofx=(int32_t)shadow.controls[0];certificates[slot].ofy=(int32_t)shadow.controls[1];
 certificates[slot].h=(int32_t)shadow.controls[2];memcpy(certificates[slot].camera,camera,sizeof camera);
}
static int ram_span(uint32_t a,unsigned n);
int a2_world_shadow_geometry(const world_precision_vertex *v,unsigned count,int wide,uint32_t address,const uint32_t *words,unsigned word_count,A2WorldShadowGeometry *out) {
 if(!shadow_enabled || !world_precision_enabled || !v || !out || !words || count!=4 || word_count!=9 || !ram_span(address,36))return 0;
 uint64_t generation=v[0].camera_generation;
 address&=0x1fffffu;unsigned material=material_slot(address);
 if(materials[material].address!=address || materials[material].generation!=generation ||
    materials[material].version!=world_precision_code_version ||
    memcmp(materials[material].words,words,36))return 0;
 unsigned slot=(unsigned)(generation%SHADOW_CERTIFICATES);
 if(!generation || certificates[slot].generation!=generation ||
    certificates[slot].version!=world_precision_code_version)return 0;
 A2WorldShadowGeometry result={0};
 for(unsigned i=0;i<4;i++) {
  uint32_t source=v[i].source_address;
  if(v[i].producer_pc!=0x800155d8u || v[i].projection_kind!=WORLD_PROJECTION_NATIVE_Q16 ||
     v[i].camera_generation!=generation || v[i].generation!=v[0].generation ||
     source<0x1f800220u || (source-0x1f800220u)%8)return 0;
  unsigned index=(source-0x1f800220u)/8;
  if(index>=certificates[slot].count || (certificates[slot].invalid>>index&1) || v[i].native_word!=certificates[slot].words[index])return 0;
  /* The retained emitter copies each consecutive group of four. */
  if((i==0 && index%4) || (i && source!=v[0].source_address+8*i))return 0;
  const double *point=certificates[slot].camera[index];
  result.z[i]=point[2];
  /* The squeeze of the native words it certifies (captured at projection). */
  result.x[i]=point[0]*certificates[slot].h/point[2]*(wide?certificates[slot].wide_scale:1.)+certificates[slot].ofx/65536.;
  result.y[i]=point[1]*certificates[slot].h/point[2]+certificates[slot].ofy/65536.;
  if(!isfinite(result.x[i]) || !isfinite(result.y[i]) ||
     result.x[i]<-1024 || result.x[i]>=1024 || result.y[i]<-1024 || result.y[i]>=1024)return 0;
 }
 memcpy(result.origin_q12,certificates[slot].origin,sizeof result.origin_q12);
 memcpy(result.rotation_q12,certificates[slot].rotation,sizeof result.rotation_q12);
 result.h=certificates[slot].h;result.ofx=certificates[slot].ofx;result.ofy=certificates[slot].ofy;
 *out=result;return 1;
}
void a2_world_shadow_configure(int enabled){
 shadow_enabled=!!enabled;memset(&shadow,0,sizeof shadow);memset(certificates,0,sizeof certificates);memset(materials,0,sizeof materials);
}
static int code_matches(void){
 return lw_(0x800811d8)==4 &&
  !memcmp(PSX_RAM+0x8de88,world_shadow_game_code,sizeof world_shadow_game_code)&&
  !memcmp(PSX_RAM+0x25598,world_shadow_setup_code,sizeof world_shadow_setup_code);
}
static int ram_span(uint32_t a,unsigned n){
 uint32_t p=a&0x1fffffffu;return !(a&3)&&p<0x800000u&&(p&0x1fffffu)<=PSX_RAM_SIZE-n;
}
void a2_world_shadow_begin(const uint32_t r[32]){
 memset(&shadow,0,sizeof shadow);
 if(!shadow_enabled||!world_precision_enabled||!r||!code_matches()||r[4]!=0x1f800000u||
    (r[31]!=0x8008eab0u&&r[31]!=0x8008eafcu)||
    !r[7]||r[7]>32||(r[7]&3)||!ram_span(r[5],44u*(r[7]/4)))return;
 shadow.wanted=1;shadow.count=r[7];shadow.groups=(r[7]+2)/3;shadow.packet=r[5];
}
void a2_world_shadow_before(uint32_t pc,const uint32_t r[32],int valid){
 if(pc==0x80015454u){
  shadow.active=shadow.finished=shadow.pending=shadow.verified_group=0;
  if(!shadow.wanted||!valid||!code_matches()||r[31]!=0x80025670u||
     r[4]!=0x8011763cu||r[5]!=shadow.groups||
     lw_(r[4]+16)!=0x1f800198u||lw_(r[4]+20)!=0x1f800220u)return;
  uint32_t matrix=lw_(r[4]+28);if(!ram_span(matrix,20))return;
  for(unsigned i=0;i<shadow.groups*3;i++){
   uint32_t point=lw_(0x1f800198u+4*i);
   if(point!=0x1f800000u+12*i)return;
   for(unsigned j=0;j<3;j++)shadow.inputs[i][j]=lw_(point+4*j);
  }
  for(unsigned j=0;j<3;j++)shadow.origin[j]=lw_(r[4]+44+4*j);
  for(unsigned j=0;j<5;j++)shadow.matrix[j]=lw_(matrix+4*j);
  for(unsigned j=0;j<3;j++)shadow.controls[j]=gte_ctrl_read(24+j);
  shadow.object=world_precision_begin_object();shadow.code_version=world_precision_code_version;
  shadow.group=0;shadow.invalid=0;shadow.active=1;shadow.wanted=0;
 }else if(pc==0x8001554cu || pc==0x80015614u) {
  if(!shadow.active)return;
  unsigned group=pc==0x8001554cu?0:shadow.group+1;
  static const unsigned registers[3][3]={{8,9,10},{11,12,13},{14,15,24}};
  int matches=valid && shadow.code_version==world_precision_code_version && group<shadow.groups &&
    (pc==0x8001554cu?shadow.group==0&&!shadow.pending:shadow.pending);
  for(unsigned j=0;j<3;j++)if(r[21+j]!=shadow.origin[j])matches=0;
  for(unsigned i=0;i<3;i++) {
   unsigned index=group*3+i;if(index>=shadow.count)continue;
   if(r[16+i]!=0x1f800000u+12*index)matches=0;
   for(unsigned j=0;j<3;j++)if(r[registers[i][j]]!=shadow.inputs[index][j])matches=0;
  }
  if(!matches){shadow.active=shadow.finished=shadow.pending=shadow.verified_group=0;return;}
  shadow.verified_group=group+1;
 }else if(pc==0x80015700u){
  shadow.finished=shadow.active&&shadow.group==shadow.groups&&!shadow.pending&&
   shadow.code_version==world_precision_code_version&&valid;
  shadow.active=0;certify_batch();
 }
}
void a2_world_shadow_project(uint32_t pc,const uint32_t r[32]){
 if(pc!=0x800155d8u||!shadow.active)return;
 shadow.pending=0;shadow.stored=0;
 if(shadow.group>=shadow.groups||shadow.verified_group!=shadow.group+1||shadow.code_version!=world_precision_code_version||
    r[4]!=0x800157b0u||r[5]!=0x1f800000u||
    r[6]!=0x1f800220u+24*shadow.group)return;
 for(unsigned j=0;j<5;j++){
  uint32_t expected=j==4?(uint32_t)(int32_t)(int16_t)shadow.matrix[j]:shadow.matrix[j];
  if(gte_ctrl_read(j)!=expected)return;
 }
 for(unsigned j=0;j<3;j++)if(gte_ctrl_read(5+j)||gte_ctrl_read(24+j)!=shadow.controls[j]||
    lw_(0x8011763cu+44+4*j)!=shadow.origin[j] || r[21+j]!=shadow.origin[j])return;
 for(unsigned i=0;i<3;i++){
  /* The final RTPT triple is padded with up to two zero points. Their
   * invalid depth is not evidence against earlier, used FIFO vertices. */
  if(shadow.group*3+i>=shadow.count){memset(&shadow.vertices[i],0,sizeof shadow.vertices[i]);continue;}
  int32_t full[3];
  for(unsigned j=0;j<3;j++){
   unsigned index=shadow.group*3+i;
   if(lw_(0x1f800000u+12*index+4*j)!=shadow.inputs[index][j])return;
   /* Original SUBU wraps before arithmetic SRA12. Reject any int16 pack loss. */
   full[j]=(int32_t)(shadow.inputs[index][j]-shadow.origin[j])>>12;
   if(full[j]<INT16_MIN||full[j]>INT16_MAX)return;
  }
  uint32_t xy=(uint16_t)full[0]|((uint32_t)(uint16_t)full[1]<<16);
  if(gte_data_read(2*i)!=xy||(int16_t)gte_data_read(2*i+1)!=full[2])return;
  uint32_t word=gte_data_read(12+i);
  shadow.projected_words[shadow.group*3+i]=word;
  if(!world_precision_gte_read(12+i,word,&shadow.vertices[i])||
     shadow.vertices[i].producer_pc!=pc||
     shadow.vertices[i].projection_kind!=WORLD_PROJECTION_NATIVE_Q16) {
   /* A saturated or otherwise unprojectable point (an off-screen shadow)
    * loses provenance alone; its quad falls back, the batch continues. */
   memset(&shadow.vertices[i],0,sizeof shadow.vertices[i]);
   shadow.vertices[i].native_word=word;shadow.invalid|=1u<<(shadow.group*3+i);
   continue;
  }
  shadow.vertices[i].camera_generation=shadow.object;
 }
 shadow.pending=1;
}
void a2_world_shadow_store(uint32_t pc,uint32_t address,uint32_t word,const uint32_t r[32]){
 if(!shadow.active||!shadow.pending)return;
 unsigned i;
 switch(pc){case 0x800156b0u:case 0x800156e8u:i=0;break;
  case 0x800156b8u:case 0x800156f0u:i=1;break;
  case 0x800156c0u:case 0x800156f8u:i=2;break;default:return;}
 uint32_t base=0x1f800220u+shadow.group*24;
 if(shadow.code_version!=world_precision_code_version||r[6]!=base||address!=base+8*i||
    shadow.stored!=i||(shadow.group*3+i<shadow.count&&word!=shadow.vertices[i].native_word)){shadow.pending=0;return;}
 if(shadow.group*3+i<shadow.count)world_precision_record(address,word,shadow.object,&shadow.vertices[i]);
 if(++shadow.stored==3){shadow.pending=0;++shadow.group;}
}
void a2_world_shadow_emit(const uint32_t r[32]){
 if(!world_precision_enabled||!shadow.finished||shadow.code_version!=world_precision_code_version||
    !code_matches()||r[23]!=0x1f800000u||r[17]>=shadow.count||(r[17]&3)||
    r[18]!=0x1f800000u+8*r[17]||r[20]!=shadow.packet+44)return;
 uint32_t base=shadow.packet;shadow.packet=r[20];
 if((lw_(base)>>24)!=10||lw_(base+4)!=0xe2000000u||
    (lw_(base+8)>>24)!=0x2e||(lw_(r[4])&0xffffffu)!=(base&0xffffffu))return;
 uint32_t sources[4],destinations[4],words[4];
 for(unsigned i=0;i<4;i++){
  sources[i]=0x1f800220u+8*(r[17]+i);destinations[i]=base+12+8*i;
  words[i]=lw_(destinations[i]);if(words[i]!=lw_(sources[i]))return;
 }
 if(world_precision_emit(destinations,words,sources,4,shadow.object)) {
  uint32_t address=(base+8)&0x1fffffu;unsigned slot=material_slot(address);
  materials[slot].generation=shadow.object;materials[slot].version=shadow.code_version;
  materials[slot].address=address;memcpy(materials[slot].words,PSX_RAM+address,36);
 }
}
