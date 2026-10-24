#include "native_billboard.h"
#include "psx_rt.h"
#include "world_precision.h"
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PACKETS 256u
#define WORDS 16384u
typedef struct {
 uint32_t base,words[14],count;uint64_t token,version;double depth;
 unsigned precision_count,depth_consumed;world_precision_vertex vertices[4];
} Packet;
typedef struct {uint32_t address,index;} Word;
static Packet packets[PACKETS];
static Word word_map[WORDS];
static unsigned next_packet;
static uint64_t serial;
static const uint8_t *memory;
static size_t memory_size;
int a2_native_billboard_enabled;
uint32_t a2_native_billboard_watch_begin=UINT32_MAX,a2_native_billboard_watch_end;
extern uint32_t psx_frame_no;
static struct {
 unsigned active,stage;const char *reason;
 uint32_t object,descriptor,matrix,list,origin[3],controls[3],rotation[5],raw_object[23],raw_descriptor[18];
 int32_t input[3],center[3];uint32_t diagonals[2],packet_base;
 uint64_t version,prior_projection;double depth;
} build;
static struct {
 unsigned wanted,active,stage,bytes,visited,emit_active,layer,polygon_count;
 uint32_t object,matrix,header,list,record,next,packet_base,caller,prefix;
 uint32_t raw_object[23],raw_header[132],rotation[5],raw_record[24],origin[3],controls[3],diagonals[2];
 int32_t input[3],center[3];uint64_t version,prior_projection;double depth;
 const char *reason;
} world;
static void world_before(uint32_t pc,const uint32_t r[32],int code_valid);
static void world_after(uint32_t pc,uint32_t address,const uint32_t r[32]);
static struct {unsigned initialized,enabled,lines;uint32_t first,last;} trace;

static int span(uint32_t a,unsigned n,uint32_t *p){
 uint32_t q=a&0x1fffffffu;
 if(q>=0x800000u||(a&3u)||n>0x200000u)return 0;
 q&=0x1fffffu;if(q>0x200000u-n)return 0;*p=q;return 1;
}
static uint32_t u32(uint32_t p){uint32_t w;memcpy(&w,memory+p,4);return w;}
static void watch(uint32_t a,unsigned n){
 if(a<a2_native_billboard_watch_begin)a2_native_billboard_watch_begin=a;
 if(a+n>a2_native_billboard_watch_end)a2_native_billboard_watch_end=a+n;
}
static int overlap(uint32_t a,size_t n,uint32_t p,unsigned count){return a<(uint64_t)p+count&&(uint64_t)a+n>p;}
static void fail(const char *reason){build.stage=0;build.reason=reason;}
static int tracing(void){
 if(!trace.initialized){int saved=errno;trace.initialized=1;
  const char*s=getenv("A2_BILLBOARD_TRACE");char*end;
  if(s&&*s>='0'&&*s<='9'){errno=0;unsigned long long first=strtoull(s,&end,10);
   if(!errno&&first<=UINT32_MAX&&*end==':'&&end[1]>='0'&&end[1]<='9'){
    errno=0;unsigned long long last=strtoull(end+1,&end,10);
    if(!errno&&!*end&&last<=UINT32_MAX&&last>=first){trace.enabled=1;trace.first=(uint32_t)first;trace.last=(uint32_t)last;}
   }
  }errno=saved;
 }
 return trace.enabled&&psx_frame_no>=trace.first&&psx_frame_no<=trace.last&&trace.lines<8192;
}
static void log_state(uint32_t pc,uint32_t dma,unsigned captured){
 if(!tracing())return;
 fprintf(stderr,"nativebillboard: frame=%u pc=%08x object=%08x descriptor=%08x slot=%d stage=%u reason=%s input=%d,%d,%d center=%d,%d,%d diagonal=%08x,%08x depth=%.17g dma=%08x captured=%u",
  psx_frame_no,pc,build.object,build.descriptor,
  build.descriptor>=0x12a4f8u&&build.descriptor<0x12a4f8u+60u*72u?(int)((build.descriptor-0x12a4f8u)/72u):-1,
  build.stage,build.reason?build.reason:"none",build.input[0],build.input[1],build.input[2],
  build.center[0],build.center[1],build.center[2],build.diagonals[0],build.diagonals[1],build.depth,dma,captured);
 fprintf(stderr," raw=%d,%d,%d offset=%d,%d,%d camera=%d,%d,%d flags=%08x command=%08x controls=%08x,%08x,%08x",
  (int32_t)build.raw_descriptor[2],(int32_t)build.raw_descriptor[3],(int32_t)build.raw_descriptor[4],
  (int32_t)build.raw_descriptor[5],(int32_t)build.raw_descriptor[6],(int32_t)build.raw_descriptor[7],
  (int32_t)build.origin[0],(int32_t)build.origin[1],(int32_t)build.origin[2],build.raw_descriptor[0],build.raw_descriptor[11],
  build.controls[0],build.controls[1],build.controls[2]);
 uint32_t p;if(dma&&memory&&span(dma,44,&p)){fputs(" words=",stderr);for(unsigned i=0;i<11;i++)fprintf(stderr,"%08x,",u32(p+4*i));}
 fputc('\n',stderr);if(++trace.lines==8192)fputs("nativebillboard-limit: incomplete=1\n",stderr);
}
void a2_native_billboard_reset(void){
 memset(packets,0,sizeof packets);memset(word_map,0,sizeof word_map);memset(&build,0,sizeof build);
 memset(&world,0,sizeof world);
 next_packet=0;a2_native_billboard_watch_begin=UINT32_MAX;a2_native_billboard_watch_end=0;
}
void a2_native_billboard_init(const uint8_t *ram,size_t bytes){a2_native_billboard_reset();memory=ram;memory_size=bytes;}
void a2_native_billboard_configure(int enabled){a2_native_billboard_enabled=!!enabled;a2_native_billboard_reset();}
void a2_native_billboard_invalidate(uint32_t address,size_t bytes){
 uint32_t p=address&0x1fffffffu;
 if(!a2_native_billboard_enabled||!bytes||p>=0x800000u)return;p&=0x1fffffu;
 if(bytes>0x200000u-p){a2_native_billboard_reset();return;}
 if(build.active&&(overlap(p,bytes,build.object&0x1fffffu,92)||
     overlap(p,bytes,build.matrix,20)||overlap(p,bytes,build.list,40)||
     (build.stage&&overlap(p,bytes,build.descriptor,72)))){
  build.active=0;fail("source-write");
 }
 if((world.active||world.wanted)&&
    (overlap(p,bytes,world.object&0x1fffffu,92)||overlap(p,bytes,world.matrix,20)||
     overlap(p,bytes,world.header,0x210)||
     (world.active&&(overlap(p,bytes,0x157b0,12)||overlap(p,bytes,0x157e8,20)||
       overlap(p,bytes,0x15818,4)||overlap(p,bytes,0x15da0,4)||
       (world.bytes&&overlap(p,bytes,world.record,world.bytes)))))){
  world.wanted=world.active=world.stage=world.emit_active=0;world.reason="source-write";
 }
 if(bytes>=WORDS*4u){for(unsigned i=0;i<PACKETS;i++)packets[i].token=0;return;}
 uint64_t end=((uint64_t)p+bytes+3u)&~UINT64_C(3);
 for(uint32_t w=p&~3u;w<end;w+=4){
  Word *m=&word_map[(w>>2)&(WORDS-1)];
  if(m->index&&m->address==w){Packet*q=&packets[m->index-1];
   if(w>=q->base&&w<q->base+4*(q->count+2))q->token=0;
  }
 }
}
static unsigned publish(uint32_t p,unsigned count,uint64_t version,double depth){
 if(++serial==0){a2_native_billboard_configure(0);return 0;}
 unsigned index=next_packet++%PACKETS;Packet*q=&packets[index];q->token=0;
 for(unsigned i=0;i<count+2;i++){uint32_t a=p+4*i;Word*m=&word_map[(a>>2)&(WORDS-1)];
  if(m->index&&m->index!=index+1){Packet*old=&packets[m->index-1];
   if(m->address>=old->base&&m->address<old->base+4*(old->count+2))old->token=0;}
  m->address=a;m->index=index+1;
 }
 memcpy(q->words,memory+p,4*(count+2));q->base=p;q->count=count;
 q->version=version;q->depth=depth;q->token=serial;q->precision_count=q->depth_consumed=0;
 watch(p,4*(count+2));return 1;
}
/* The native loop rotates an integer center and projects two integer
 * diagonals, then mixes their X/Y components. Preserve that construction
 * using the verified source's Q12 camera and unrounded matrix product. */
static void precise_packet(const double relative[3],const uint32_t rotation[5],
                           const uint32_t controls[3],unsigned width,unsigned height,
                           uint32_t producer) {
 static int enabled=-1;
 if(enabled<0){const char *value=getenv("A2_BILLBOARD_PRECISION");enabled=!value||strcmp(value,"0");}
 if(!enabled)return;
 if(!world_camera_enabled||!width||!height)return;
 Packet*q=&packets[(next_packet-1)%PACKETS];
 double center[3]={0};int16_t matrix[10];memcpy(matrix,rotation,sizeof matrix);
 for(unsigned row=0;row<3;row++)for(unsigned col=0;col<3;col++)
  center[row]+=matrix[row*3+col]*relative[col]/4096.0;
 double z=center[2]*4092.0/4096.0;
 if(!isfinite(z)||z<1.0/4096||z>=65536||!controls[2]||controls[2]>65535||controls[2]>=2*z)return;
 unsigned command=q->words[2]>>24,nv=(command&8)?4:3,stride=(command&16)?3:2;
 world_precision_vertex vertices[4];uint64_t generation=world_precision_begin_object();
 int a2_wide(void);double wide=a2_wide()?world_precision_wide_scale():1.0;
 for(unsigned i=0;i<nv;i++){
  unsigned corner=nv==3&&i==2?3:i;
  double x=(center[0]+(corner&1?(double)width:-(double)width))*16368.0/4096.0*controls[2]/z*wide+(int32_t)controls[0]/65536.0;
  double y=(center[1]+(corner&2?(double)height:-(double)height))*16368.0/4096.0*controls[2]/z+(int32_t)controls[1]/65536.0;
  if(!isfinite(x)||!isfinite(y)||x< -1024||x>=1024||y< -1024||y>=1024)return;
  uint32_t offset=3+stride*i;
  vertices[i]=(world_precision_vertex){.x=floor(x*65536)/65536,.y=floor(y*65536)/65536,.z=z,
   .projection_id=generation,.generation=generation,.native_word=q->words[offset],
   .producer_pc=producer,.source_address=q->base+4*offset,
   .projection_kind=WORLD_PROJECTION_CAMERA,.camera_generation=generation};
 }
 memcpy(q->vertices,vertices,nv*sizeof *vertices);q->precision_count=nv;
 if(tracing()){
  fprintf(stderr,"billboard-precision: frame=%u source=%08x producer=%08x vertices=%u",psx_frame_no,q->base,producer,nv);
  for(unsigned i=0;i<nv;i++)fprintf(stderr," xy%u=%.9f,%.9f",i,vertices[i].x,vertices[i].y);
  fprintf(stderr," z=%.9f\n",z);++trace.lines;
 }
}
static int source_matches(const uint32_t r[32]){
 if(!build.active||build.version!=world_precision_code_version||!world_precision_enabled||
    r[4]!=0x800157b0u||r[5]!=0x1f800000u||
    memcmp(memory+(build.object&0x1fffffu),build.raw_object,92)||
    memcmp(memory+build.matrix,build.rotation,20)||
    memcmp(memory+build.descriptor,build.raw_descriptor,72)||
    lw_(r[4]+0x68)!=build.object)return 0;
 for(unsigned j=0;j<3;j++)if(lw_(r[4]+0x3b8+4*j)!=build.origin[j]||gte_ctrl_read(24+j)!=build.controls[j])return 0;
 return 1;
}
void a2_native_billboard_before(uint32_t pc,const uint32_t r[32],int code_valid){
 if(!a2_native_billboard_enabled||!r)return;
 if(pc<0x80014318u||pc>0x800146b8u){world_before(pc,r,code_valid);return;}
 if(pc==0x80014318u){
  memset(&build,0,sizeof build);build.object=r[4];build.reason="entry-rejected";
  uint32_t p,m,l;
  if(memory&&memory_size==PSX_RAM_SIZE&&world_precision_enabled&&code_valid&&r[4]==0x8011763cu&&
     r[31]==0x8002542cu&&span(r[4],92,&p)&&span(u32(p+36),20,&m)&&span(u32(p+20),40,&l)){
   memcpy(build.raw_object,memory+p,92);memcpy(build.rotation,memory+m,20);
   build.matrix=m;build.list=l;build.version=world_precision_code_version;
   for(unsigned j=0;j<3;j++){build.origin[j]=u32(p+44+4*j);build.controls[j]=gte_ctrl_read(24+j);}
   watch(p,92);watch(m,20);watch(l,40);build.active=1;build.reason="entry";
  }log_state(pc,0,0);return;
 }
 if(pc==0x800146b8u){build.active=0;build.stage=0;return;}
 if(pc==0x80014444u){
  build.stage=0;build.depth=0;memset(build.diagonals,0,sizeof build.diagonals);
  uint32_t p;build.descriptor=r[30]&0x1fffffffu;build.reason="descriptor-rejected";
  if(!build.active||!code_valid||!span(r[30],72,&p)||p<0x12a4f8u||p>=0x12a4f8u+60u*72u||(p-0x12a4f8u)%72u)return;
  build.descriptor=p;memcpy(build.raw_descriptor,memory+p,72);watch(p,72);
  if(!(build.raw_descriptor[0]&0x8000u))return;
  build.stage=1;build.reason="descriptor";return;
 }
 if(pc==0x80014548u&&!build.stage){log_state(pc,0,0);return;}
 if(!build.stage)return;
 if(!code_valid||!source_matches(r)){fail("source-changed");return;}
 if(pc==0x80014498u){
  if(build.stage!=1){fail("stage-order");return;}
  for(unsigned j=0;j<3;j++){
   uint32_t full=build.raw_descriptor[2+j]+build.raw_descriptor[5+j]-build.origin[j];
   if(r[16+j]!=full){fail("source-input");return;}
   int32_t v=(int32_t)full;v=v/4096-(v<0&&v%4096!=0);
   if(v<INT16_MIN||v>INT16_MAX){fail("source-pack-wrap");return;}build.input[j]=v;
  }
  for(unsigned j=0;j<5;j++){uint32_t value=j==4?(uint32_t)(int32_t)(int16_t)build.rotation[j]:build.rotation[j];
   if(gte_ctrl_read(j)!=value){fail("camera-control");return;}}
  for(unsigned j=5;j<8;j++)if(gte_ctrl_read(j)){fail("camera-translation");return;}
  build.stage=2;
 }else if(pc==0x800144c8u){
  if(build.stage!=2||(gte_ctrl_read(31)&0x7fc00000u)){fail("center-invalid");return;}
  if(gte_data_read(0)!=((uint16_t)build.input[0]|((uint32_t)(uint16_t)build.input[1]<<16))||
     (int16_t)gte_data_read(1)!=build.input[2]){fail("center-input");return;}
  for(unsigned j=0;j<5;j++){uint32_t expected=j==4?(uint32_t)(int32_t)(int16_t)build.rotation[j]:build.rotation[j];
   if(gte_ctrl_read(j)!=expected){fail("center-control");return;}}
  for(unsigned j=5;j<8;j++)if(gte_ctrl_read(j)){fail("center-translation");return;}
  for(unsigned j=0;j<3;j++)build.center[j]=(int32_t)gte_data_read(25+j);
  build.stage=3;
 }else if(pc==0x80014548u){
  if(build.stage!=3){fail("stage-order");log_state(pc,0,0);return;}
  unsigned width=(build.raw_descriptor[13]&255u),height=(build.raw_descriptor[13]>>8)&255u;
  for(unsigned j=0;j<3;j++)if(build.center[j]<INT16_MIN||build.center[j]>INT16_MAX){fail("center-pack-wrap");log_state(pc,0,0);return;}
  if(build.center[2]<50||!width||!height){fail("depth-or-size");log_state(pc,0,0);return;}
  for(unsigned i=0;i<2;i++){
   int32_t x=build.center[0]+(i?-(int)width:(int)width),y=build.center[1]+(i?-(int)height:(int)height);
   if(x<INT16_MIN||x>INT16_MAX||y<INT16_MIN||y>INT16_MAX||
      gte_data_read(2*i)!=((uint16_t)x|((uint32_t)(uint16_t)y<<16))||
      (int16_t)gte_data_read(2*i+1)!=build.center[2]){fail("corner-pack-wrap");log_state(pc,0,0);return;}
  }
  const uint32_t diagonal[5]={0x3ff0,0,0x3ff0,0,0xffc};
  for(unsigned j=0;j<5;j++)if(gte_ctrl_read(j)!=diagonal[j]){fail("billboard-control");log_state(pc,0,0);return;}
  for(unsigned j=5;j<8;j++)if(gte_ctrl_read(j)){fail("billboard-translation");log_state(pc,0,0);return;}
  uint32_t packet_physical;
  if(!span(r[2],44,&packet_physical)){fail("packet-bounds");log_state(pc,0,0);return;}
  build.packet_base=r[2];
  build.prior_projection=0;
  for(unsigned i=0;i<3;i++){world_precision_vertex old;
   if(world_precision_gte_read(12+i,gte_data_read(12+i),&old)&&old.projection_id>build.prior_projection)
    build.prior_projection=old.projection_id;}
  build.stage=4;log_state(pc,0,0);
 }else if(pc==0x8001454cu){
  world_precision_vertex v[2];
  if(build.stage!=4){fail("stage-order");return;}
  for(unsigned i=0;i<2;i++){
   build.diagonals[i]=gte_data_read(12+i);
   if(!world_precision_gte_read(12+i,build.diagonals[i],&v[i])||v[i].producer_pc!=0x80014548u||
      v[i].projection_kind!=WORLD_PROJECTION_NATIVE_Q16||v[i].projection_id<=build.prior_projection||
      (i&&v[i].projection_id<=v[0].projection_id)){fail("projection-invalid");log_state(pc,0,0);return;}
  }
  if(v[0].z!=v[1].z||v[0].z!=build.center[2]*4092.0/4096.0||!isfinite(v[0].z)||v[0].z<=0){fail("projection-depth");log_state(pc,0,0);return;}
  build.depth=v[0].z;build.stage=5;build.reason="projected";log_state(pc,0,0);
 }
}
void a2_native_billboard_after_store(uint32_t pc,uint32_t address,uint32_t word,const uint32_t r[32]){
 if(a2_native_billboard_enabled&&r&&(pc==0x800128acu||pc==0x80012988u)){world_after(pc,address,r);return;}
 if(!a2_native_billboard_enabled||pc!=0x800147e4u||!r)return;
 uint32_t p;unsigned captured=0;
 if(build.stage==5&&source_matches(r)&&r[31]==0x80014664u&&address==r[2]&&address==build.packet_base&&span(address,44,&p)&&
    (word>>24)==10&&u32(p)==word&&u32(p+4)==0xe2000000u&&
    ((u32(p+8)>>24)&0xfdu)==0x2cu){
  const uint32_t hi=build.diagonals[0],lo=build.diagonals[1];
  const uint32_t xy[4]={lo,(hi&0xffffu)|(lo&0xffff0000u),(lo&0xffffu)|(hi&0xffff0000u),hi};
  unsigned valid=1;for(unsigned i=0;i<4;i++)if(u32(p+12+8*i)!=xy[i])valid=0;
  if(valid){
   captured=publish(p,9,build.version,build.depth);build.reason="captured";
   if(captured){
    double relative[3];for(unsigned j=0;j<3;j++)
     relative[j]=(int32_t)(build.raw_descriptor[2+j]+build.raw_descriptor[5+j]-build.origin[j])/4096.0;
    precise_packet(relative,build.rotation,build.controls,build.raw_descriptor[13]&255u,
                   (build.raw_descriptor[13]>>8)&255u,0x80014548u);
   }
  }else build.reason="packet-corners";
 }else if(build.stage)build.reason="packet-contract";
 log_state(pc,address,captured);build.stage=0;
}
static void world_fail(const char *reason){world.stage=world.emit_active=0;world.reason=reason;}
static void world_log(uint32_t pc,unsigned captured){
 if(!tracing())return;
 fprintf(stderr,"nativeworldbillboard: frame=%u pc=%08x object=%08x header=%08x record=%08x bytes=%u stage=%u reason=%s input=%d,%d,%d center=%d,%d,%d diagonal=%08x,%08x depth=%.17g caller=%08x dma=%08x layer=%u captured=%u\n",
  psx_frame_no,pc,world.object,world.header,world.record,world.bytes,world.stage,
  world.reason?world.reason:"none",world.input[0],world.input[1],world.input[2],
  world.center[0],world.center[1],world.center[2],world.diagonals[0],world.diagonals[1],
  world.depth,world.caller,world.packet_base,world.layer,captured);
 if(++trace.lines==8192)fputs("nativebillboard-limit: incomplete=1\n",stderr);
}
static int world_matches(const uint32_t r[32]){
 if(!world.active||!world_precision_enabled||world.version!=world_precision_code_version||
    r[4]!=0x800157b0u||r[5]!=0x1f800000u||
    memcmp(memory+(world.object&0x1fffffu),world.raw_object,92)||
    memcmp(memory+world.matrix,world.rotation,20)||
    memcmp(memory+world.header,world.raw_header,0x210)||
    lw_(r[4]+0x68)!=world.object||lw_(r[4]+0x5f0)!=world.list||
    memcmp(memory+0x157e8,world.rotation,20)||
    (world.bytes&&memcmp(memory+world.record,world.raw_record,world.bytes)))return 0;
 for(unsigned j=0;j<3;j++)if(lw_(r[4]+4*j)!=world.origin[j]||gte_ctrl_read(24+j)!=world.controls[j])return 0;
 return 1;
}
static int world_rotation(void){
 for(unsigned j=0;j<5;j++){
  uint32_t wanted=j==4?(uint32_t)(int32_t)(int16_t)world.rotation[j]:world.rotation[j];
  if(gte_ctrl_read(j)!=wanted)return 0;
 }
 for(unsigned j=5;j<8;j++)if(gte_ctrl_read(j))return 0;
 return 1;
}
static void world_before(uint32_t pc,const uint32_t r[32],int code_valid){
 if(pc==0x800100a8u){
  memset(&world,0,sizeof world);uint32_t p,m,h;world.reason="setup-rejected";
  if(!memory||memory_size!=PSX_RAM_SIZE||!world_precision_enabled||!code_valid||
     !span(r[4],92,&p)||!span(u32(p+36),20,&m)||!span(u32(p+16),0x210,&h))return;
  world.object=r[4];world.matrix=m;world.header=h;world.version=world_precision_code_version;
  memcpy(world.raw_object,memory+p,92);memcpy(world.rotation,memory+m,20);
  memcpy(world.raw_header,memory+h,0x210);world.list=u32(h+0x200);
  for(unsigned j=0;j<3;j++){
   int32_t raw=(int32_t)world.raw_object[11+j];
   world.origin[j]=(uint32_t)(raw/4096-(raw<0&&raw%4096!=0));
   world.controls[j]=gte_ctrl_read(24+j);
  }
  watch(p,92);watch(m,20);watch(h,0x210);world.wanted=1;return;
 }
 if(pc==0x80014cd8u){
  unsigned wanted=world.wanted;world.wanted=0;world.active=wanted;
  if(!wanted||!code_valid||r[31]!=0x80010420u||!world_matches(r)){
   world.active=0;world_fail("entry-rejected");world_log(pc,0);return;
  }
  world.next=world.list;world.reason="entry";
  watch(0x157b0,12);watch(0x157e8,20);watch(0x15818,4);watch(0x15da0,4);return;
 }
 if(pc==0x800150f4u){world.active=world.stage=world.emit_active=0;return;}
 if(!world.active)return;
 if(pc==0x80014d4cu){
  world.bytes=world.stage=world.visited=world.emit_active=0;world.depth=0;
  memset(world.diagonals,0,sizeof world.diagonals);world.record=r[3]&0x1fffffu;
  uint32_t p;
  if(!code_valid||!world_matches(r)||r[3]!=world.next||!span(r[3],60,&p)){
   world.active=0;world_fail("record-link");return;
  }
  if(!(u32(p)&0xffffu)){world.active=0;return;}
  world.bytes=(u32(p+16)&4)?96:60;
  if(!span(r[3],world.bytes,&p)){world.active=0;world_fail("record-bounds");return;}
  world.record=p;memcpy(world.raw_record,memory+p,world.bytes);watch(p,world.bytes);
  world.next=r[3]+world.bytes;
  /* The specialized 8000 feedback/raw-UV dispatcher is a separate contract. */
  if((world.raw_record[0]&0x4000u)||(world.raw_record[4]&0x8000u)){world_fail("record-flags");return;}
  world.stage=1;world.reason="record";return;
 }
 if(!world.stage)return;
 if(!code_valid||!world_matches(r)){world_fail("source-changed");return;}
 if(pc==0x80014dc8u){
  if(world.stage!=1||!world_rotation()){world_fail("center-control");return;}
  /* The source word is packed: source + (source >>16), then camera
   * subtraction, then native signed16 packing. Do not treat it as Q12. */
  for(unsigned j=0;j<3;j++){
   uint32_t raw=world.raw_record[1+j];
   int64_t value=(int16_t)raw+(int64_t)(raw>>16)-(int32_t)world.origin[j];
   if(value<INT16_MIN||value>INT16_MAX){world_fail("source-pack-wrap");return;}
   world.input[j]=(int32_t)value;
  }
  if(gte_data_read(0)!=((uint16_t)world.input[0]|((uint32_t)(uint16_t)world.input[1]<<16))||
     (int16_t)gte_data_read(1)!=world.input[2]){world_fail("center-input");return;}
  world.stage=2;
 }else if(pc==0x80014dccu){
  if(world.stage!=2||!world_rotation()||(gte_ctrl_read(31)&0x7fc00000u)){world_fail("center-invalid");return;}
  for(unsigned j=0;j<3;j++)world.center[j]=(int32_t)gte_data_read(25+j);
  world.stage=3;
 }else if(pc==0x80014e4cu){
  if(world.stage!=3){world_fail("stage-order");return;}
  unsigned width=world.raw_record[5]&0xffffu,height=world.raw_record[5]>>16;
  for(unsigned j=0;j<3;j++)if(world.center[j]<INT16_MIN||world.center[j]>INT16_MAX){world_fail("center-pack-wrap");return;}
  if(world.center[2]<=0||!width||!height){world_fail("depth-or-size");return;}
  for(unsigned j=0;j<2;j++){
   int64_t x=(int64_t)world.center[0]+(j?-(int)width:(int)width);
   int64_t y=(int64_t)world.center[1]+(j?-(int)height:(int)height);
   if(x<INT16_MIN||x>INT16_MAX||y<INT16_MIN||y>INT16_MAX||
      gte_data_read(2*j)!=((uint16_t)x|((uint32_t)(uint16_t)y<<16))||
      (int16_t)gte_data_read(2*j+1)!=world.center[2]){world_fail("corner-pack-wrap");return;}
  }
  const uint32_t diagonal[5]={0x3ff0,0,0x3ff0,0,0xffc};
  for(unsigned j=0;j<5;j++)if(gte_ctrl_read(j)!=diagonal[j]){world_fail("billboard-control");return;}
  for(unsigned j=5;j<8;j++)if(gte_ctrl_read(j)){world_fail("billboard-translation");return;}
  world.prior_projection=0;
  for(unsigned j=0;j<3;j++){world_precision_vertex old;
   if(world_precision_gte_read(12+j,gte_data_read(12+j),&old)&&old.projection_id>world.prior_projection)
    world.prior_projection=old.projection_id;
  }
  world.stage=4;
 }else if(pc==0x80014e50u){
  world_precision_vertex v[2];
  if(world.stage!=4){world_fail("stage-order");return;}
  for(unsigned j=0;j<2;j++){
   world.diagonals[j]=gte_data_read(12+j);
   if(!world_precision_gte_read(12+j,world.diagonals[j],&v[j])||v[j].producer_pc!=0x80014e4cu||
      v[j].projection_kind!=WORLD_PROJECTION_NATIVE_Q16||v[j].projection_id<=world.prior_projection||
      (j&&v[j].projection_id<=v[0].projection_id)){world_fail("projection-invalid");return;}
  }
  if(v[0].z!=v[1].z||!isfinite(v[0].z)||v[0].z<=0||v[0].z!=world.center[2]*4092.0/4096.0){world_fail("projection-depth");return;}
  world.depth=v[0].z;world.stage=5;world.reason="projected";world_log(pc,0);
 }else if(pc==0x800126c8u){
  world.emit_active=0;world.caller=r[31];unsigned layer,two=world.bytes==96;
  switch(r[31]){
   case 0x80014f40u:case 0x80014f80u:if(two)return;layer=0;break;
   case 0x80014fecu:case 0x8001502cu:if(!two)return;layer=1;break;
   case 0x80015090u:case 0x800150d0u:if(!two)return;layer=0;break;
   default:return;
  }
  unsigned format=(r[8]>>24)&0xfcu;
  if(world.stage!=5||(r[3]&0x1fffffu)!=world.record||world.visited!=(two&&!layer?2u:0u)||
     !world_rotation())return;
  /* Native normal G3/G4 can visit this dispatcher and emit no packet. That
   * first material must not prevent the second independently proven layer.
   * Track source call order separately from successful packet publication. */
  world.visited|=1u<<layer;
  if(format!=0x3cu&&format!=0x34u)return;
  world.polygon_count=format==0x3cu?12:9;
  const uint32_t hi=world.diagonals[0],lo=world.diagonals[1];
  const uint32_t xy[4]={lo,(hi&0xffffu)|(lo&0xffff0000u),hi,(lo&0xffffu)|(hi&0xffff0000u)};
  for(unsigned j=0;j<4;j++)if(((uint16_t)r[16+2*j]|((uint32_t)(uint16_t)r[17+2*j]<<16))!=xy[j])return;
  uint32_t p;if(!span(r[2],4*(world.polygon_count+2),&p))return;
  world.prefix=world.raw_record[(layer?0x58:0x34)/4];
  if(lw_(r[5]+0x370)!=world.prefix||((world.prefix>>24)!=0xe2u&&(world.prefix>>24)!=0xe1u))return;
  world.packet_base=r[2];world.layer=layer;world.emit_active=1;
 }
}
static void world_after(uint32_t pc,uint32_t address,const uint32_t r[32]){
 if(!world.emit_active)return;
 world.emit_active=0;unsigned captured=0;uint32_t p;
 if(world_matches(r)&&world_rotation()&&r[31]==world.caller&&r[2]==world.packet_base&&
    address==r[2]+0x20&&span(r[2],4*(world.polygon_count+2),&p)&&
    pc==(world.polygon_count==12?0x800128acu:0x80012988u)&&
    (u32(p)>>24)==world.polygon_count+1&&u32(p+4)==world.prefix&&
    ((u32(p+8)>>24)&0xfcu)==(world.polygon_count==12?0x3cu:0x34u)){
  const uint32_t hi=world.diagonals[0],lo=world.diagonals[1];
  const uint32_t xy[4]={lo,(hi&0xffffu)|(lo&0xffff0000u),(lo&0xffffu)|(hi&0xffff0000u),hi};
  unsigned valid=1,nv=world.polygon_count/3;
  for(unsigned j=0;j<nv;j++)if(u32(p+12+12*j)!=(nv==3&&j==2?hi:xy[j]))valid=0;
  if(valid){
   captured=publish(p,world.polygon_count,world.version,world.depth);world.reason="captured";
   if(captured){
    double relative[3];for(unsigned j=0;j<3;j++){
     uint32_t raw=world.raw_record[1+j];
     relative[j]=(int16_t)raw+(double)(raw>>16)-(int32_t)world.raw_object[11+j]/4096.0;
    }
    precise_packet(relative,world.rotation,world.controls,world.raw_record[5]&65535u,
                   world.raw_record[5]>>16,0x80014e4cu);
   }
  }
  else world.reason="packet-corners";
 }else world.reason="packet-contract";
 world_log(pc,captured);
}
static Packet *packet(uint32_t address,uint32_t command){
 uint32_t p;if(!a2_native_billboard_enabled||!world_precision_enabled||!memory||!span(address,4,&p))return NULL;
 Word*m=&word_map[(p>>2)&(WORDS-1)];if(!m->index||m->address!=p)return NULL;
 Packet*q=&packets[m->index-1];
 if(!q->token||p!=q->base+8||q->version!=world_precision_code_version||q->words[2]!=command||
    memcmp(q->words,memory+q->base,4*(q->count+2)))return NULL;
 return q;
}
uint64_t a2_native_billboard_token(uint32_t address,uint32_t command){Packet*q=packet(address,command);return q&&!q->depth_consumed?q->token:0;}
int a2_native_billboard_consume(uint32_t address,uint64_t token,const uint32_t*words,unsigned count,double*depth){
 if(!words||(count!=9&&count!=12)||!depth||!token)return 0;Packet*q=packet(address,words[0]);
 if(!q||q->depth_consumed||q->count!=count||q->token!=token||memcmp(q->words+2,words,4*count))return 0;
 *depth=q->depth;q->depth_consumed=1;return 1;
}
int a2_native_billboard_vertex(uint32_t address,uint32_t word,world_precision_vertex *out){
 uint32_t p;if(!a2_native_billboard_enabled||!world_precision_enabled||!world_camera_enabled||
              !memory||!out||!span(address,4,&p))return 0;
 Word*m=&word_map[(p>>2)&(WORDS-1)];if(!m->index||m->address!=p)return 0;
 Packet*q=&packets[m->index-1];
 if(!q->token||!q->precision_count||q->version!=world_precision_code_version||
    memcmp(q->words,memory+q->base,4*(q->count+2)))return 0;
 for(unsigned i=0;i<q->precision_count;i++)if(q->vertices[i].source_address==p&&q->vertices[i].native_word==word){
  *out=q->vertices[i];return 1;
 }
 return 0;
}
