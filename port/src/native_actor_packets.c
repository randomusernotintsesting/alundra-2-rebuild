#include "native_actor_packets.h"
#include "native_actor_source_layout.h"
#include "native_color_table.h"
#include "native_color_preview.h"
#include <limits.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RAM_SIZE 0x200000u
#define HASH_SIZE (2u*A2_ACTOR_PACKET_LIMIT)
#define SOURCE_COUNT A2_ACTOR_SOURCE_COUNT
_Static_assert((HASH_SIZE&(HASH_SIZE-1))==0,"packet hash size must be a power of two");
#define CODE_BEGIN 0x10000u
typedef struct { A2ActorPacket value; uint64_t token; unsigned owner,observed; } Packet;
typedef struct { A2ActorPacketOwner value; unsigned valid,sealed,color_failed; } Owner;
static const uint8_t *memory;
static size_t memory_size;
static Packet packets[A2_ACTOR_PACKET_LIMIT];
static Owner owners[A2_ACTOR_PACKET_OWNER_LIMIT];
static unsigned packet_count,owner_count,hash_slots[HASH_SIZE];
static uint64_t serial,sequence,build_generation;
static uint32_t frame;
extern uint32_t psx_frame_no;
static unsigned have_frame,overflow,active,part_owner,part_index,part_active;
static unsigned code_dirty=1,code_valid;

static struct {
 unsigned active,format,count,face,layer,owner,part,color,seen;
 uint32_t base,finish,source_rgb[3],target_rgb[3],expected_rgb[3],fine_rgb[3];
 A2NativeSceneLight light;
} pending;
static int color_enabled;
static const A2ColorPart *part_colors;
static void census_retire(void);
static struct { unsigned used; char key[A2_ACTOR_SOURCE_KEY_SIZE]; uint8_t hash[32]; } source_failures[SOURCE_COUNT];
static struct {
 unsigned active,count,format;uint32_t finish,base,part;
 A2ActorPart source;
} source_emission;
static void source_emission_begin(const uint32_t *r);
static void source_emission_finish(uint32_t pc,uint32_t instruction,uint32_t address,const uint32_t *r);
int a2_native_actor_packets_enabled;
uint32_t a2_native_actor_packets_watch_begin=UINT32_MAX,a2_native_actor_packets_watch_end;

static int physical(uint32_t a,uint32_t bytes,uint32_t *p){
 uint32_t q=a&0x1fffffffu;if(q>=0x800000u)return 0;q&=0x1fffffu;
 if(bytes>RAM_SIZE-q)return 0;*p=q;return 1;
}
static uint32_t u32(uint32_t p){uint32_t v;memcpy(&v,memory+p,4);return v;}
static uint16_t u16(uint32_t p){uint16_t v;memcpy(&v,memory+p,2);return v;}
uint32_t a2_native_actor_packets_code_end=0x15ea0u;
static int code_matches(void){
 if(!memory||memory_size!=RAM_SIZE)return 0;
 if(code_dirty){uint64_t h=UINT64_C(14695981039346656037);
  for(uint32_t p=CODE_BEGIN;p<0x157b0u;p++)h=(h^memory[p])*UINT64_C(1099511628211);
  code_valid=h==UINT64_C(0x5e1437c3f76cfa12)?1u:0u;
  if(!code_valid){
   for(uint32_t p=0x157b0u;p<0x15ea0u;p++)h=(h^memory[p])*UINT64_C(1099511628211);
   if(h==UINT64_C(0x6b8b62a2245699dd))code_valid=2;
  }
  a2_native_actor_packets_code_end=code_valid==1?0x157b0u:0x15ea0u;
  code_dirty=0;
 }return code_valid;
}
static uint32_t context_address(void){return code_valid==2?0x15ea0u:0x157b0u;}
static unsigned entity_bytes(const A2ActorInstance *i){return i->source_family==A2_ACTOR_EVENT00?1728u:804u;}
static uint32_t native_finish(unsigned format){
 if(code_valid==2)return format==0x30?0x80014230u:format==0x34?0x80014480u:format==0x38?0x8001413cu:0x80014378u;
 return format==0x30?0x80013ff8u:format==0x34?0x80014248u:format==0x38?0x80013f04u:0x80014140u;
}
static uint32_t caller(const uint32_t *r){
 if(code_valid==2)switch(r[31]){
  case 0x800137ecu:case 0x800137b4u:case 0x8001392cu:case 0x800138f4u:
  case 0x80013878u:case 0x80013840u:return r[31]-0x98u;
 }
 return code_valid==2?0:r[31];
}
static uint32_t canonical_site(uint32_t pc){
 if(code_matches()==2)switch(pc){
  case 0x80012ef8u:return 0x80012e68u;
  case 0x80013158u:return 0x800130c0u;
  case 0x80013190u:return 0x800130f8u;
  case 0x8001322cu:return 0x80013194u;
  case 0x80013950u:return 0x800138b8u;
  case 0x80013d54u:return 0x80013cbcu;
  default:return 0;
 }
 return pc;
}
static void watch(uint32_t a,uint32_t bytes){
 if(a<a2_native_actor_packets_watch_begin)a2_native_actor_packets_watch_begin=a;
 if(a+bytes>a2_native_actor_packets_watch_end)a2_native_actor_packets_watch_end=a+bytes;
}
void a2_native_actor_packets_reset(void){
 part_colors=NULL;
 census_retire();
 memset(source_failures,0,sizeof source_failures);source_emission.active=0;
 memset(packets,0,sizeof packets);memset(owners,0,sizeof owners);memset(hash_slots,0,sizeof hash_slots);
 packet_count=owner_count=have_frame=overflow=active=part_active=pending.active=0;
 sequence=0;build_generation=0;
 a2_native_actor_packets_watch_begin=UINT32_MAX;a2_native_actor_packets_watch_end=0;
}
void a2_native_actor_packets_init(const uint8_t *ram,size_t bytes){
 a2_native_actor_packets_reset();memory=ram;memory_size=bytes;code_dirty=1;code_valid=0;a2_native_actor_packets_code_end=0x15ea0u;
}
void a2_native_actor_packets_configure(int enabled){
 const char *setting=getenv("A2_COLOR_CONTINUITY");
 color_enabled=setting&&!strcmp(setting,"1");
 a2_native_actor_packets_enabled=!!enabled;a2_native_actor_packets_reset();code_dirty=1;a2_native_actor_packets_code_end=0x15ea0u;
}
static void reject_all(void){
 for(unsigned i=0;i<owner_count;i++)owners[i].valid=0;
 overflow=1;active=part_active=pending.active=0;
}
typedef A2ActorSourceLayout Source;
#define sources a2_actor_source_layouts
static unsigned source_kind(const A2ActorPart *p){
 return a2_actor_source_find(p->source_key,p->source_sha256);
}
static int source_identity(const A2ActorPart *p){
 /* Source identity survives a hidden/unsupported pose. The renderer must
  * separately admit visible valid parts; never revive their stale matrices. */
 return p->source_generation&&source_kind(p)<SOURCE_COUNT&&
        !(p->fallback&(A2_ACTOR_UNBOUND_SOURCE|A2_ACTOR_DIFFERENT_PART_SOURCE|A2_ACTOR_UNKNOWN_LIFETIME));
}
static int source_layout(const A2ActorPart *p,uint32_t *header,uint32_t *face_end){
 unsigned kind=source_kind(p),mesh=p->source_mesh_index;uint32_t registry,h,v;
 if(kind==SOURCE_COUNT)return 0;const Source *s=&sources[kind];
 if(mesh>=s->parts||!physical(p->registry_address,s->bytes,&registry)||
    u32(registry+32+4*s->parts)!=UINT32_MAX||u32(registry+0x12c)!=s->parts||
    !physical(u32(registry+32+4*mesh),24,&h)||h!=registry+s->header[mesh]||
    u16(h+14)!=s->faces[mesh]||
    u16(h+16)!=((mesh+1<s->parts?s->header[mesh+1]:s->bytes)-s->face_end[mesh])/16||
    !physical(u32(h+20),0,&v)||v!=registry+s->face_end[mesh])return 0;
 uint32_t cursor=h+24;
 for(unsigned j=0;j<s->faces[mesh];j++){
  if(cursor>v||v-cursor<8)return 0;
  unsigned bytes=(u16(cursor)&4)?80:44;if(bytes>v-cursor)return 0;cursor+=bytes;
 }
 if(cursor!=v)return 0;*header=h;*face_end=v;return 1;
}
static int source_face(const A2ActorPart *p,uint32_t address,uint32_t *out,unsigned *index){
 uint32_t header,end,face;if(!source_layout(p,&header,&end)||!physical(address,8,&face))return 0;
 uint32_t cursor=header+24;unsigned j=0;
 while(cursor<end){
  if(cursor==face){*out=face;*index=j;return 1;}
  cursor+=(u16(cursor)&4)?80:44;++j;
 }
 return 0;
}
static const A2ColorPart *color_part(const A2ActorPart *p) {
 if(!color_enabled)return NULL;
 for(unsigned i=0;i<sizeof a2_color_parts/sizeof *a2_color_parts;i++) {
  const A2ColorPart *d=&a2_color_parts[i];
  if(d->mesh!=p->source_mesh_index||memcmp(d->hash,p->source_sha256,32))continue;
  return d;
 }
 return NULL;
}
static int color_part_matches(const A2ActorPart *p,const A2ColorPart *d) {
 uint32_t base;unsigned kind=source_kind(p);
 if(kind==SOURCE_COUNT||!physical(p->registry_address,sources[kind].bytes,&base))return 0;
 for(unsigned j=0;j<d->check_count;j++) {
  const A2ColorCheck *c=&a2_color_checks[d->check_first+j];
  if(c->offset>sources[kind].bytes||c->bytes>sources[kind].bytes-c->offset||
     memcmp(memory+base+c->offset,a2_color_bytes+c->data,c->bytes))return 0;
 }
 return 1;
}
static void color_reject(unsigned owner) {
 owners[owner].color_failed=1;
 for(unsigned j=0;j<packet_count;j++)if(packets[j].owner==owner)packets[j].value.fine_rgb_valid=0;
}
static int instance_sources(const A2ActorFrame *s,const A2ActorInstance *i){
 if(!i->part_count||i->part_count>A2_ACTOR_PACKET_PART_LIMIT||i->first_part>s->part_count||
    i->part_count>s->part_count-i->first_part)return 0;
 const A2ActorPart *p=s->parts+i->first_part;unsigned kind=source_kind(p);
 if(kind==SOURCE_COUNT||i->part_count!=sources[kind].parts)return 0;
 for(unsigned k=0;k<i->part_count;k++){
  uint32_t h,end;
  if(!source_identity(p+k)||p[k].source_mesh_index!=k||p[k].registry_address!=i->registry_address||
     p[k].source_generation!=p[0].source_generation||source_kind(p+k)!=kind||
     !source_layout(p+k,&h,&end))return 0;
 }
 return 1;
}
static void source_failed_mark(const A2ActorPart *p){
 unsigned index=source_kind(p);if(index==SOURCE_COUNT)return;
 source_failures[index].used=1;
 memcpy(source_failures[index].key,p->source_key,sizeof source_failures[index].key);
 memcpy(source_failures[index].hash,p->source_sha256,32);
}
static int owner_unobserved(unsigned owner){
 for(unsigned j=0;j<packet_count;j++)if(packets[j].owner==owner&&!packets[j].observed)return 1;
 return 0;
}
/* Independent source proof for a completed main emission. This does not
 * admit geometry: it catches a known source that the stricter owner/pose
 * pipeline could not retain. No failure is inferred from a skipped actor. */
static void source_emission_begin(const uint32_t *r){
 source_emission.active=0;
 const A2ActorFrame *s=a2_native_actor_snapshot_current();
 if(!s||!s->build_generation||s->build_generation!=build_generation||s->shadow_pass||
    s->draw_object_address!=(s->source_family==A2_ACTOR_EVENT00?0x800d76f0u:0x8011763cu)||s->instance_count>A2_ACTOR_MAX_INSTANCES||
    s->part_count>A2_ACTOR_MAX_PARTS||!code_matches()||r[4]!=(0x80000000u|context_address())||r[5]!=0x1f800000u||
    u32(context_address()+0x68)!=s->draw_object_address||(u32(context_address()+0x5cc)&0x100u))return;
 uint32_t pa=u32(context_address()+0x70),part;
 if(!physical(pa,80,&part))return;
 const A2ActorPart *source=NULL;
 for(unsigned j=0;j<s->instance_count&&!source;j++){
  const A2ActorInstance *i=&s->instances[j];
  if(!i->selected_for_draw||!i->generation_known||!i->instance_generation||
     i->first_part>s->part_count||i->part_count>s->part_count-i->first_part)continue;
  for(unsigned k=0;k<i->part_count;k++){
   const A2ActorPart *p=&s->parts[i->first_part+k];uint32_t pp;
   if(p->source_mesh_index<A2_ACTOR_PACKET_PART_LIMIT&&p->registry_address==i->registry_address&&source_identity(p)&&
      physical(p->address,80,&pp)&&pp==part&&!memcmp(p->raw,memory+part,80)&&
      u32(part+60)==p->registry_address&&u16(part+2)==p->source_mesh_index){source=p;break;}
  }
 }
 if(!source)return;
 unsigned layer;
 switch(caller(r)){
 case 0x80013754:case 0x8001371c:case 0x80013894:case 0x8001385c:layer=0;break;
 case 0x800137e0:case 0x800137a8:layer=1;break;
 default:return;
 }
 uint32_t face;unsigned index;
 if(!source_face(source,r[3],&face,&index))return;
 unsigned two=!!(u16(face)&4u);
 if((layer&&!two)||((caller(r)==0x80013754u||caller(r)==0x8001371cu)&&two)||
    ((caller(r)==0x80013894u||caller(r)==0x8001385cu)&&!two))return;
 unsigned format=(r[8]>>24)&0xfcu;
 if((format!=0x30&&format!=0x34&&format!=0x38&&format!=0x3c)||
    format!=((u32(face+(layer?44:8))>>24)&0xfcu))return;
 unsigned count=format==0x30?6:format==0x34?9:format==0x38?8:12;uint32_t base;
 if(!physical(r[2],4*(count+2),&base)||(base&3))return;
 source_emission.active=1;source_emission.count=count;source_emission.format=format;
 source_emission.finish=native_finish(format);
 source_emission.base=base;source_emission.part=part;source_emission.source=*source;
}
static void source_emission_finish(uint32_t pc,uint32_t instruction,uint32_t address,const uint32_t *r){
 if(!source_emission.active||pc!=source_emission.finish)return;source_emission.active=0;
 unsigned stride=(source_emission.format&4)?12:8,count=source_emission.count;uint32_t base,bucket,p;
 if(!code_matches()||instruction!=(stride==12?0xac570020u:0xac570018u)||
    !physical(r[2],4*(count+2),&base)||base!=source_emission.base||
    !physical(address,4,&p)||p!=base+(stride==12?32:24)||
    !physical(r[8],4,&bucket)||(bucket&3)||(u32(bucket)&0xffffffu)!=base||
    u32(base)>>24!=count+1||((u32(base+8)>>24)&0xfcu)!=source_emission.format||
    (u32(base+4)>>24!=0xe1&&u32(base+4)>>24!=0xe2)||
    memcmp(memory+source_emission.part,source_emission.source.raw,80))return;
 for(unsigned j=0;j<packet_count;j++)if(packets[j].value.command_address==base+8&&
    owners[packets[j].owner].valid&&packets[j].value.submission_sequence==sequence&&
    packets[j].value.polygon_word_count==count&&
    !memcmp(packets[j].value.words,memory+base,4*(count+2)))return;
 source_failed_mark(&source_emission.source);
}
/* Diagnostic-only census. Identity is explicitly attributed to a copied
 * snapshot or still-valid owner, never inferred from XY or relocated bytes.
 * UNKNOWN identities remain in the census so rejected paths cannot disappear. */
static struct {
 unsigned initialized,enabled,lines,pending;uint32_t first,last;
 uint32_t entry_frame,part,registry,mesh,flags,context_flags,material_flags;
 uint32_t caller,dma,command,finish,face_address;
 unsigned format,count,layer,face,entity_known,generation_known;
 uint32_t entity,action;uint64_t generation,source_generation;
 char key[A2_ACTOR_SOURCE_KEY_SIZE];const char *identity,*reason;
} census;
static int census_range(void){
 if(!census.initialized){
  int saved_errno=errno;
  census.initialized=1;const char *s=getenv("A2_MESH_EMIT_TRACE");char *end;
  if(s&&*s>='0'&&*s<='9'){
   errno=0;unsigned long long first=strtoull(s,&end,10);
   if(!errno&&first<=UINT32_MAX&&*end==':'&&end[1]>='0'&&end[1]<='9'){
    const char *tail=end+1;errno=0;unsigned long long last=strtoull(tail,&end,10);
    if(!errno&&!*end&&last<=UINT32_MAX&&first<=last){
     census.first=(uint32_t)first;census.last=(uint32_t)last;census.enabled=1;
    }
   }
  }
  errno=saved_errno;
 }
 return census.enabled&&psx_frame_no>=census.first&&psx_frame_no<=census.last&&census.lines<65536;
}
static int census_same(uint32_t a,uint32_t b){
 uint32_t x,y;return physical(a,1,&x)&&physical(b,1,&y)&&x==y;
}
static int census_identity(const A2ActorPart *p){
 A2ActorPart identity=*p;identity.valid=identity.visible=1;identity.fallback=identity.flags=0;
 return source_identity(&identity);
}
static void census_line(const char *phase,unsigned captured,uint64_t owner,unsigned owner_valid){
 if(census.lines>=65536)return;
 fprintf(stderr,"nativeemit: phase=%s frame=%u entry_frame=%u key=%s identity=%s source_generation=%llu registry=%08x source_part=%u part=%08x entity_known=%u entity=%08x generation_known=%u generation=%llu action=%u flags=%04x context5cc=%08x contextab0=%04x shadow=%u caller=%08x dma=%08x command_address=%08x command=%08x format=%02x layer=%u source_face=%u face_address=%08x captured=%u owner=%llu owner_valid=%u reason=%s line=%u\n",
  phase,psx_frame_no,census.entry_frame,census.key,census.identity,
  (unsigned long long)census.source_generation,census.registry,census.mesh,census.part,
  census.entity_known,census.entity,census.generation_known,(unsigned long long)census.generation,
  census.action,census.flags,census.context_flags,census.material_flags,!!(census.context_flags&0x100u),
  census.caller,census.dma,census.dma?census.dma+8:0,census.command,census.format,census.layer,
  census.face,census.face_address,captured,(unsigned long long)owner,owner_valid,census.reason,++census.lines);
 if(census.lines==65536)fprintf(stderr,"nativeemit-limit: first=%u last=%u limit=65536 incomplete=1\n",census.first,census.last);
}
static void census_retire(void){
 if(census.pending){census.pending=0;census.reason="terminal-not-observed";census_line("unfinished",0,0,0);}
}
static void census_entry(const uint32_t *r){
 if(!census_range())return;
 if(census.pending){census.reason="terminal-not-observed";census_line("unfinished",0,0,0);}
 census.pending=0;census.entry_frame=psx_frame_no;census.part=census.registry=census.flags=0;
 census.mesh=census.face=census.layer=UINT_MAX;census.context_flags=census.material_flags=0;
 census.entity_known=census.generation_known=census.entity=census.action=0;
 census.generation=census.source_generation=0;census.dma=census.face_address=0;
 strcpy(census.key,"UNKNOWN");census.identity="none";census.reason="code-identity";
 census.caller=r[31];census.command=r[8];census.format=(r[8]>>24)&0xfcu;
 if(!code_matches()){census_line("entry",0,0,0);return;}
 uint32_t context,part;
 if(!physical(r[4],0xab2,&context)||context!=context_address()||
    (r[5]&0x1fffffffu)!=0x1f800000u){census.reason="context";census_line("entry",0,0,0);return;}
 census.context_flags=u32(context+0x5cc);census.material_flags=u16(context+0xab0);
 census.part=u32(context+0x70);
 if(!physical(census.part,80,&part)){census.reason="part-span";census_line("entry",0,0,0);return;}
 census.registry=u32(part+60);census.mesh=u16(part+2);census.flags=u16(part);
 const A2ActorFrame *s=a2_native_actor_snapshot_current();
 const A2ActorInstance *instance=NULL;const A2ActorPart *source=NULL;
 if(s&&s->instance_count<=A2_ACTOR_MAX_INSTANCES&&s->part_count<=A2_ACTOR_MAX_PARTS){
  for(unsigned j=0;j<s->part_count;j++){
   const A2ActorPart *p=&s->parts[j];
   if(census_same(p->registry_address,census.registry)&&p->source_mesh_index==census.mesh&&census_identity(p)){
    if(!source){source=p;census.identity="snapshot-source";}
    if(census_same(p->address,census.part)&&!memcmp(p->raw,memory+part,80)){
     source=p;census.identity="snapshot-part";
     for(unsigned k=0;k<s->instance_count;k++){
      const A2ActorInstance *i=&s->instances[k];
      if(i->first_part<=j&&i->part_count<=s->part_count-i->first_part&&j-i->first_part<i->part_count){instance=i;break;}
     }
     break;
    }
   }
  }
 }
 if(!source)for(unsigned j=0;j<owner_count&&!source;j++)if(owners[j].valid&&owners[j].sealed)
  for(unsigned k=0;k<owners[j].value.instance.part_count;k++){
   const A2ActorPart *p=&owners[j].value.parts[k];
   if(census_same(p->registry_address,census.registry)&&p->source_mesh_index==census.mesh&&census_identity(p)){
    source=p;census.identity="retained-owner-source";break;
   }
  }
 if(source){memcpy(census.key,source->source_key,sizeof census.key);census.key[sizeof census.key-1]=0;census.source_generation=source->source_generation;}
 if(instance){census.entity_known=1;census.entity=instance->entity_address;census.generation_known=instance->generation_known;
  census.generation=instance->instance_generation;census.action=instance->action_id;
  uint32_t e;if(physical(instance->entity_address,804,&e))census.action=u16(e+20);
 }
 census.reason="pending";
 if(!s||!s->valid)census.reason="snapshot-invalid";
 else if(s->shadow_pass||(census.context_flags&0x100u))census.reason="shadow-pass";
 else if(!source)census.reason="source-unbound";
 else if(!instance)census.reason="entity-unresolved";
 else if(!instance->valid||!instance->generation_known||!instance->instance_generation||
   !instance->selected_for_draw||!instance->part_count||instance->part_count>A2_ACTOR_PACKET_PART_LIMIT||(instance->fallback&~A2_ACTOR_UNKNOWN_ANIMATION))census.reason="instance-ineligible";
 else if(!instance_sources(s,instance))census.reason="part-ineligible";
 else if(!part_active)census.reason="part-not-observed";
 else if(!owners[part_owner].valid)census.reason="owner-invalid";
 else if(!pending.active)census.reason="emitter-contract";
 if(census.material_flags&0x800u)census.reason="feedback-path";
 uint32_t registry,header,face;
 if(census.mesh>4095||!physical(census.registry,32+4*(census.mesh+1),&registry)||
    !physical(u32(registry+32+4*census.mesh),24,&header)||!physical(r[3],8,&face)){
  census.reason="source-face-span";census_line("entry",0,0,0);return;
 }
 census.face_address=r[3];uint32_t cursor=header+24;unsigned faces=u16(header+14);
 if(faces<=4096)for(unsigned j=0;j<faces;j++){
  if(cursor>RAM_SIZE-8)break;if(cursor==face){census.face=j;break;}
  unsigned bytes=(u16(cursor)&4)?80:44;if(bytes>RAM_SIZE-cursor)break;cursor+=bytes;
 }
 if(census.face==UINT_MAX)census.reason="face-not-in-source";
 switch(caller(r)){
  case 0x80013754u:case 0x8001371cu:case 0x80013894u:case 0x8001385cu:census.layer=0;break;
  case 0x800137e0u:case 0x800137a8u:census.layer=1;break;
  default:census.reason="unknown-caller";break;
 }
 switch(census.format){
  case 0x30:census.count=6;census.finish=native_finish(0x30);break;
  case 0x34:census.count=9;census.finish=native_finish(0x34);break;
  case 0x38:census.count=8;census.finish=native_finish(0x38);break;
  case 0x3c:census.count=12;census.finish=native_finish(0x3c);break;
  default:census.reason="unsupported-format";census_line("entry",0,0,0);return;
 }
 if(!physical(r[2],4*(census.count+2),&census.dma)||(census.dma&3)){
  census.dma=0;census.reason="packet-span";census_line("entry",0,0,0);return;
 }
 census.pending=1;census_line("entry",0,0,0);
}
static void census_after_store(uint32_t pc,uint32_t instruction,uint32_t address,const uint32_t *r){
 if(!census.pending||pc!=census.finish)return;census.pending=0;
 /* Complete an entry that crossed a tick, even if its last store is just
  * outside the requested interval. The bounded line limit still applies. */
 unsigned stride=(census.format&4)?12:8;uint32_t base,p;
 if(!code_matches()||instruction!=(stride==12?0xac570020u:0xac570018u)||
    !physical(r[2],4*(census.count+2),&base)||base!=census.dma||
    !physical(address,4,&p)||p!=base+(stride==12?32:24)){
  census.reason="terminal-contract";census_line("final",0,0,0);return;
 }
 census.command=u32(base+8);
 if(u32(base)>>24!=census.count+1||((census.command>>24)&0xfcu)!=census.format||
    (u32(base+4)>>24!=0xe1&&u32(base+4)>>24!=0xe2))census.reason="payload-contract";
 unsigned captured=0,valid=0;uint64_t handle=0;
 for(unsigned j=0;j<packet_count;j++)if(packets[j].value.command_address==base+8&&
   packets[j].value.submission_sequence==sequence&&packets[j].value.polygon_word_count==census.count&&
   !memcmp(packets[j].value.words,memory+base,4*(census.count+2))){
  captured=1;handle=packets[j].value.owner_handle;valid=owners[packets[j].owner].valid;
  census.reason=valid?"captured":"captured-invalid-owner";break;
 }
 if(!captured&&!strcmp(census.reason,"pending"))census.reason="completion-contract";
 census_line("final",captured,handle,valid);
}
static void trace_frame_reset(const A2ActorFrame *s){
 static unsigned initialized,enabled,lines;static uint32_t first_frame;
 if(!initialized){const char *t=getenv("A2_MESH_TRACE");
  enabled=t!=NULL;first_frame=t?(uint32_t)strtoul(t,NULL,10):UINT32_MAX;initialized=1;
 }
 if(!enabled||psx_frame_no<first_frame||lines>=2048||!owner_count)return;
 unsigned sealed=0,valid_sealed=0;
 for(unsigned j=0;j<owner_count;j++)if(owners[j].sealed){++sealed;if(owners[j].valid)++valid_sealed;}
 fprintf(stderr,"nativepacket-reset: frame=%u old_build=%u new_build=%u shadow=%u sealed=%u valid_sealed=%u owners=%u old_generation=%llu new_generation=%llu line=%u\n",
  psx_frame_no,frame,s->guest_frame,s->shadow_pass,sealed,valid_sealed,owner_count,
  (unsigned long long)build_generation,(unsigned long long)s->build_generation,++lines);
}
static void begin(const uint32_t *r){
 active=part_active=pending.active=0;
 const A2ActorFrame *s=a2_native_actor_snapshot_current();
 if(!s)return;
 /* A logical arena build can span several guest ticks, including a
  * later unsupported shadow submission. Only a new real build retires the
  * collection; source/packet/entity writes still revoke individual owners. */
 if(!s->build_generation){
  if(have_frame)trace_frame_reset(s);
  a2_native_actor_packets_reset();return;
 }
 if(!have_frame||build_generation!=s->build_generation){
  if(have_frame)trace_frame_reset(s);
  a2_native_actor_packets_reset();build_generation=s->build_generation;
  frame=s->guest_frame;have_frame=1;
 }
 if(overflow||!s->valid||s->shadow_pass||!s->sequence||r[4]!=s->draw_object_address||!code_matches())return;
 if((s->source_family==A2_ACTOR_EVENT00)!=(code_valid==2))return;
 if(s->sequence<=sequence)return;
 sequence=s->sequence;
 if(s->instance_count>A2_ACTOR_MAX_INSTANCES||s->part_count>A2_ACTOR_MAX_PARTS){reject_all();return;}
 for(unsigned j=0;j<s->instance_count;j++){
  const A2ActorInstance *i=&s->instances[j];
  if(!i->valid||!i->generation_known||!i->instance_generation||!i->selected_for_draw||
     (i->fallback&~A2_ACTOR_UNKNOWN_ANIMATION)||!instance_sources(s,i))continue;
  const A2ActorPart *p=s->parts+i->first_part;
  if(owner_count==A2_ACTOR_PACKET_OWNER_LIMIT||serial==UINT64_MAX){reject_all();return;}
  if(!owner_count)frame=s->guest_frame; /* first actually eligible main */
  Owner *o=&owners[owner_count++];o->valid=1;o->value.handle=++serial;
  o->value.submission_sequence=sequence;o->value.guest_frame=frame;o->value.instance=*i;
  memcpy(o->value.parts,p,i->part_count*sizeof *p);
  /* Validate every candidate part before view-dependent part visits. A
   * changed or unseen sibling cannot leave only some owner colors enabled. */
  o->color_failed=0;
  for(unsigned k=0;k<i->part_count;k++) {
   const A2ColorPart *d=color_part(p+k);
   if(d&&!color_part_matches(p+k,d))o->color_failed=1;
  }
  memcpy(o->value.camera_origin_q12,s->camera_origin_q12,sizeof o->value.camera_origin_q12);
  memcpy(o->value.camera_rotation_q12,s->camera_rotation_q12,sizeof o->value.camera_rotation_q12);
  o->value.projection_h=s->projection_h;o->value.projection_ofx=s->projection_ofx;o->value.projection_ofy=s->projection_ofy;
  for(unsigned k=0;k<i->part_count;k++){uint32_t a;if(!p[k].address&&!p[k].visible&&i->source_family==A2_ACTOR_EVENT00)continue;if(physical(p[k].address,80,&a))watch(a,80);else o->valid=0;}
  uint32_t source;unsigned bytes=sources[source_kind(p)].bytes;
  if(physical(i->registry_address,bytes,&source))watch(source,bytes);else o->valid=0;
  uint32_t entity;if(physical(i->entity_address,entity_bytes(i),&entity))watch(entity,entity_bytes(i));else o->valid=0;
 }
 active=1;
}
static void part_begin(const uint32_t *r){
 part_colors=NULL;
 part_active=pending.active=0;
 if(!active||!code_matches()||r[4]!=(0x80000000u|context_address())||r[5]!=0x1f800000u||
    u32(context_address()+0x70)!=r[30]||(u32(context_address()+0x5cc)&0x100u))return;
 for(unsigned j=0;j<owner_count;j++){
  Owner *o=&owners[j];if(!o->valid||o->sealed||o->value.submission_sequence!=sequence)continue;
  for(unsigned k=0;k<o->value.instance.part_count;k++)if(o->value.parts[k].address==r[30]){
   uint32_t p,header,end,actual;
   if(!physical(r[30],80,&p)||memcmp(memory+p,o->value.parts[k].raw,80)||
      !source_layout(&o->value.parts[k],&header,&end)||!physical(r[3],24,&actual)||actual!=header){o->valid=0;return;}
   part_owner=j;part_index=k;part_active=1;
   const A2ActorPart *part=&o->value.parts[k];
   if(!o->color_failed&&part->valid&&part->visible&&!part->fallback)part_colors=color_part(part);
   return;
  }
 }
}
const A2ActorPacketOwner *a2_native_actor_packets_projecting(uint32_t context,
                                                            uint32_t part,uint32_t shared_bank){
 if(!a2_native_actor_packets_enabled||overflow||!active||!part_active||
    part_owner>=owner_count||!code_matches()||context!=(0x80000000u|context_address())||
    u32(context_address()+0x70)!=part||(u32(context_address()+0x5cc)&0x100u)||
    (u16(context_address()+0xab0)&0x800u))return NULL;
 const Owner *o=&owners[part_owner];
 if(!o->valid||o->sealed||o->value.submission_sequence!=sequence||
    o->value.instance.source_family!=(code_valid==2?A2_ACTOR_EVENT00:A2_ACTOR_GAME00)||
    part_index>=o->value.instance.part_count)return NULL;
 const A2ActorPart *p=&o->value.parts[part_index];uint32_t a,bank,expected;
 if(p->address!=part||!p->valid||!p->visible||p->fallback||
    (p->flags&(0x8000u|0x1000u|0x0200u|7u))||
    !physical(part,80,&a)||memcmp(p->raw,memory+a,80)||
    !physical(shared_bank,196u*16u,&bank)||!bank||(bank&3u)||
    !physical(u32(a+72),196u*16u,&expected)||bank!=expected)return NULL;
 return &o->value;
}
static void emit_begin(const uint32_t *r){
 pending.color=pending.seen=0;
 memset(&pending.light,0,sizeof pending.light);
 pending.active=0;if(!part_active||!active||!owners[part_owner].valid)return;
 if(!code_matches()||r[4]!=(0x80000000u|context_address())||r[5]!=0x1f800000u||
    (u16(context_address()+0xab0)&0x800u)){owners[part_owner].valid=0;return;}
 unsigned layer;
 switch(caller(r)){
 case 0x80013754:case 0x8001371c:layer=0;break;
 case 0x800137e0:case 0x800137a8:layer=1;break;
 case 0x80013894:case 0x8001385c:layer=0;break;
 default:owners[part_owner].valid=0;return;
 }
 uint32_t face;unsigned index;
 if(!source_face(&owners[part_owner].value.parts[part_index],r[3],&face,&index)){
  owners[part_owner].valid=0;return;
 }
 unsigned two=!!(u16(face)&4u);
 if((layer&&!two)||((caller(r)==0x80013754u||caller(r)==0x8001371cu)&&two)||
    ((caller(r)==0x80013894u||caller(r)==0x8001385cu)&&!two)){owners[part_owner].valid=0;return;}
 unsigned format=(r[8]>>24)&0xfcu;
 if((format!=0x30&&format!=0x34&&format!=0x38&&format!=0x3c)||
    format!=((u32(face+(layer?44:8))>>24)&0xfcu)){owners[part_owner].valid=0;return;}
 uint32_t base;if(!physical(r[2],56,&base)||(base&3)){owners[part_owner].valid=0;return;}
 pending.active=1;pending.format=format;pending.owner=part_owner;pending.part=part_index;
 pending.face=index;pending.layer=layer;pending.base=base;
 pending.count=format==0x30?6:format==0x34?9:format==0x38?8:12;
 pending.finish=native_finish(format);
 if(part_colors&&format==0x30&&!layer&&!owners[part_owner].color_failed) {
  for(unsigned j=0;j<3;j++)pending.source_rgb[j]=pending.target_rgb[j]=u32(face+8+4*j)&0xffffffu;
  for(unsigned j=0;j<part_colors->row_count;j++) {
   const A2ColorRow *row=&a2_color_rows[part_colors->row_first+j];
   if(row->face==index&&row->corner<3) {
    if(row->original!=pending.source_rgb[row->corner]){color_reject(part_owner);return;}
    pending.target_rgb[row->corner]=row->replacement;pending.color=1;
   }
  }
 }
}
int a2_native_actor_packets_color_site(uint32_t pc,uint32_t instruction) {
 if(!a2_native_actor_packets_enabled||!pending.active||!pending.color||
    owners[pending.owner].color_failed||instruction!=0x4ae80413u)return 0;
 /* Both independently certified AL22 profiles use these three NCDS sites.
  * GAME:13f34/13f7c/13fb4; EVENT:1416c/141b4/141ec. */
 return pc==pending.finish-0xc4u||pc==pending.finish-0x7cu||pc==pending.finish-0x44u;
}
void a2_native_actor_packets_color_gte(uint32_t pc,const uint32_t data[32],const uint32_t control[32]) {
 if(!data||!control||!a2_native_actor_packets_color_site(pc,0x4ae80413u))return;
 unsigned corner=pc==pending.finish-0xc4u?0:pc==pending.finish-0x7cu?1:2;
 if((pending.seen&(1u<<corner))||(data[6]&0xffffffu)!=pending.source_rgb[corner]||
    !a2_color_preview_ncds(data,control,pending.source_rgb[corner],&pending.expected_rgb[corner])||
    !a2_color_preview_ncds(data,control,pending.target_rgb[corner],&pending.fine_rgb[corner])) {
  color_reject(pending.owner);return;
 }
 pending.seen|=1u<<corner;
}
void a2_native_actor_packets_before(uint32_t pc,const uint32_t *r){
 if(!a2_native_actor_packets_enabled||!r)return;
 pc=canonical_site(pc);
 if(pc==0x80012e68u||pc==0x800130f8u||pc==0x800138b8u||pc==0x800130c0u)census_retire();
 if(pc==0x80012e68u||pc==0x800130f8u||pc==0x800138b8u||pc==0x800130c0u)source_emission.active=0;
 if(pc==0x80012e68u)begin(r);
 else if(pc==0x800130f8u||pc==0x800138b8u)part_active=pending.active=0;
 else if(pc==0x80013194u)part_begin(r);
 else if(pc==0x80013cbcu){emit_begin(r);source_emission_begin(r);census_entry(r);}
 else if(pc==0x800130c0u){
  if(active)for(unsigned j=0;j<owner_count;j++)if(owners[j].value.submission_sequence==sequence)owners[j].sealed=1;
  active=part_active=pending.active=0;
 }
}
void a2_native_actor_packets_before_gte(uint32_t pc,const uint32_t *r,const uint32_t control[32]){
 a2_native_actor_packets_before(pc,r);
 if(pending.active&&control&&canonical_site(pc)==0x80013cbcu)(void)a2_native_scene_light_decode(control,&pending.light);
}
static void packet_after_store(uint32_t pc,uint32_t instruction,uint32_t address,const uint32_t *r){
 if(!a2_native_actor_packets_enabled||!pending.active||pc!=pending.finish)return;
 pending.active=0;Owner *o=&owners[pending.owner];uint32_t base,bucket,p;
 unsigned stride=(pending.format&4)?12:8;
 if(!o->valid||!active||!code_matches()||instruction!=(stride==12?0xac570020u:0xac570018u)||
    !physical(r[2],56,&base)||base!=pending.base||!physical(address,4,&p)||p!=base+(stride==12?32:24)||
    !physical(r[8],4,&bucket)||(bucket&3)||(u32(bucket)&0xffffffu)!=base||
    u32(base)>>24!=pending.count+1||((u32(base+8)>>24)&0xfcu)!=pending.format||
    (u32(base+4)>>24!=0xe1&&u32(base+4)>>24!=0xe2)){o->valid=0;return;}
 if(o->value.packet_count){
  if(o->value.light.known!=pending.light.known||
     (pending.light.known&&!a2_native_scene_light_equal(&o->value.light,&pending.light))){o->valid=0;return;}
 }else o->value.light=pending.light;
 unsigned h=((base+8)>>2)&(HASH_SIZE-1);
 while(hash_slots[h]){
  if(packets[hash_slots[h]-1].value.command_address==base+8){o->valid=0;return;}
  h=(h+1)&(HASH_SIZE-1);
 }
 if(packet_count==A2_ACTOR_PACKET_LIMIT||serial==UINT64_MAX){reject_all();return;}
 Packet *q=&packets[packet_count++];q->token=++serial;q->owner=pending.owner;q->observed=0;
 A2ActorPacket *v=&q->value;v->owner_handle=o->value.handle;v->submission_sequence=sequence;
 v->entity_generation=o->value.instance.instance_generation;v->dma_base=base;v->command_address=base+8;
 v->ot_bucket=bucket;v->previous_head=u32(base)&0xffffffu;v->prefix_word=u32(base+4);
 v->source_mesh_index=pending.part;v->native_face_index=pending.face;v->material_layer=pending.layer;
 v->polygon_word_count=pending.count;v->dma_word_count=pending.count+1;
 memcpy(v->words,memory+base,4*(pending.count+2));hash_slots[h]=packet_count;
 v->fine_rgb_valid=0;
 if(pending.color&&!o->color_failed) {
  int valid=pending.seen==7;
  for(unsigned j=0;j<3;j++)if((v->words[2+2*j]&0xffffffu)!=(pending.expected_rgb[j]&0xffffffu))valid=0;
  if(!valid)color_reject(pending.owner);
  else {v->fine_rgb_valid=1;memcpy(v->fine_rgb,pending.fine_rgb,sizeof v->fine_rgb);}
 }
 ++o->value.packet_count;watch(base,4*(pending.count+2));
}
void a2_native_actor_packets_after_store(uint32_t pc,uint32_t instruction,uint32_t address,const uint32_t *r){
 packet_after_store(pc,instruction,address,r);
 if(a2_native_actor_packets_enabled&&r)source_emission_finish(pc,instruction,address,r);
 if(a2_native_actor_packets_enabled&&r)census_after_store(pc,instruction,address,r);
}
static Packet *find(uint32_t address){
 /* Overflow retires admission, not immutable address attribution. A later
  * retry must still be recognized as a failed source instead of ORDERED. */
 uint32_t p;if(!a2_native_actor_packets_enabled||!physical(address,4,&p)||(p&3))return NULL;
 unsigned h=(p>>2)&(HASH_SIZE-1);
 while(hash_slots[h]){Packet *q=&packets[hash_slots[h]-1];if(q->value.command_address==p)return q;h=(h+1)&(HASH_SIZE-1);}
 return NULL;
}
const A2ActorPacketOwner *a2_native_actor_packets_owner(uint64_t handle){
 if(!a2_native_actor_packets_enabled||overflow)return NULL;
 for(unsigned j=0;j<owner_count;j++)if(owners[j].value.handle==handle)
  return owners[j].valid&&owners[j].sealed?&owners[j].value:NULL;
 return NULL;
}
size_t a2_native_actor_packets_owners(uint32_t guest_frame,const A2ActorPacketOwner **out,size_t capacity){
 if(!out||!have_frame||frame!=guest_frame||overflow||!a2_native_actor_packets_enabled)return 0;
 size_t n=0;for(unsigned j=0;j<owner_count;j++)if(owners[j].valid&&owners[j].sealed&&owners[j].value.packet_count)n++;
 if(n>capacity)return 0;
 n=0;for(unsigned j=0;j<owner_count;j++)if(owners[j].valid&&owners[j].sealed&&owners[j].value.packet_count)out[n++]=&owners[j].value;
 return n;
}
size_t a2_native_actor_packets_owner_packets(uint64_t handle,const A2ActorPacket **out,size_t capacity){
 const A2ActorPacketOwner *o=a2_native_actor_packets_owner(handle);
 if(!o||!out||o->packet_count>capacity)return 0;
 size_t n=0;for(unsigned j=0;j<packet_count;j++)if(packets[j].value.owner_handle==handle)out[n++]=&packets[j].value;
 return n;
}
size_t a2_native_actor_packets_owners_latest(const A2ActorPacketOwner **out,size_t capacity){
 return a2_native_actor_packets_owners(frame,out,capacity);
}
int a2_native_actor_packets_owner_complete(uint64_t handle){
 const A2ActorPacketOwner *o=a2_native_actor_packets_owner(handle);if(!o||!o->packet_count)return 0;
 for(unsigned j=0;j<packet_count;j++)if(packets[j].value.owner_handle==handle&&!packets[j].observed)return 0;
 return 1;
}
/* Repeated dispatch retains the exact source identity. This optional trace
 * reports repeat token queries without changing first-observation accounting. */
static void trace_repeat(const Packet *q,uint32_t address,uint32_t command){
 static unsigned initialized,enabled;
 static uint32_t first_frame;
 static uint64_t repeats;
 extern uint32_t psx_frame_no;
 if(!initialized){const char *s=getenv("A2_MESH_TRACE");
  enabled=s!=NULL;first_frame=s?(uint32_t)strtoul(s,NULL,10):UINT32_MAX;initialized=1;
 }
 if(!enabled||psx_frame_no<first_frame||
    !a2_native_actor_packets_owner(q->value.owner_handle)||q->value.words[2]!=command||
    memcmp(memory+q->value.dma_base,q->value.words,4*(q->value.dma_word_count+1)))return;
 ++repeats;
 if(repeats<=256)fprintf(stderr,
  "nativepacket-repeat: frame=%u build_frame=%u address=%08x owner=%llu native_face=%u part=%u layer=%u count=%llu\n",
  psx_frame_no,frame,address,(unsigned long long)q->value.owner_handle,
  q->value.native_face_index,q->value.source_mesh_index,q->value.material_layer,
  (unsigned long long)repeats);
}
uint64_t a2_native_actor_packets_token(uint32_t address,uint32_t command){
 Packet *q=find(address);if(!q)return 0;
 if(!a2_native_actor_packets_owner(q->value.owner_handle)){
  /* Same-build reuse at a retired source address is ambiguous. A polygon
   * retry must not fall through to original geometry, even if color changed. */
  unsigned opcode=command>>24;
  if(opcode>=0x20&&opcode<0x40)source_failed_mark(&owners[q->owner].value.parts[0]);
  return 0;
 }
 if(q->value.words[2]!=command||memcmp(memory+q->value.dma_base,q->value.words,4*(q->value.dma_word_count+1)))return 0;
 if(q->observed)trace_repeat(q,address,command);
 return q->token;
}
int a2_native_actor_packets_consume(uint32_t address,uint64_t token,const uint32_t *words,unsigned count,const A2ActorPacket **out){
 Packet *q=find(address);if(out)*out=NULL;
 if(!out||!q||!token||token!=q->token||!words)return 0;
 if(!a2_native_actor_packets_owner(q->value.owner_handle)){
  if(count&&(words[0]>>24)>=0x20&&(words[0]>>24)<0x40)
   source_failed_mark(&owners[q->owner].value.parts[0]);
  return 0;
 }
 if(count!=q->value.polygon_word_count||memcmp(words,q->value.words+2,4*count)||
    memcmp(memory+q->value.dma_base,q->value.words,4*(q->value.dma_word_count+1))){
  owners[q->owner].valid=0;source_failed_mark(&owners[q->owner].value.parts[0]);return 0;}
 q->observed=1;*out=&q->value;return 1;
}
void a2_native_actor_packets_invalidate(uint32_t address,size_t bytes){
 uint32_t p;if(!bytes||!physical(address,0,&p))return;
 if(bytes>RAM_SIZE-p){code_dirty=1;reject_all();return;}
 uint32_t end=p+(uint32_t)bytes;
 if(p<a2_native_actor_packets_code_end&&end>CODE_BEGIN){code_dirty=1;reject_all();return;}
 for(unsigned j=0;j<packet_count;j++)if(p<packets[j].value.dma_base+4*(packets[j].value.dma_word_count+1)&&end>packets[j].value.dma_base)owners[packets[j].owner].valid=0;
 /* 9051C->9009C->90168 legitimately reuses801EC000 after the main
  * submission. Sealed copied poses and packets no longer depend on it. */
 for(unsigned j=0;j<owner_count;j++)if(owners[j].valid&&!owners[j].sealed)for(unsigned k=0;k<owners[j].value.instance.part_count;k++){
  uint32_t a;if(owners[j].value.parts[k].address&&physical(owners[j].value.parts[k].address,80,&a)&&p<a+80&&end>a)owners[j].valid=0;
 }
 /* A sealed submission owns copied source identity, entity generation and
  * pose. Later guest updates cannot alter those already-built packet bytes.
  * Packet/code writes and the next build/reset still retire the old owner. */
 for(unsigned j=0;j<owner_count;j++)if(owners[j].valid&&!owners[j].sealed){
  uint32_t a;unsigned kind=source_kind(&owners[j].value.parts[0]);
  unsigned bytes=kind<SOURCE_COUNT?sources[kind].bytes:0;
  if(bytes&&physical(owners[j].value.instance.registry_address,bytes,&a)&&p<a+bytes&&end>a)owners[j].valid=0;
  if(physical(owners[j].value.instance.entity_address,entity_bytes(&owners[j].value.instance),&a)&&p<a+entity_bytes(&owners[j].value.instance)&&end>a)owners[j].valid=0;
 }
}

int a2_native_actor_packets_source_failed(const char *key,const uint8_t hash[32]){
 if(!a2_native_actor_packets_enabled||!key||!hash)return 0;
 for(unsigned j=0;j<SOURCE_COUNT;j++)if(source_failures[j].used&&
    !strncmp(key,source_failures[j].key,A2_ACTOR_SOURCE_KEY_SIZE)&&!memcmp(hash,source_failures[j].hash,32))return 1;
 for(unsigned j=0;j<owner_count;j++)if(!owners[j].valid&&owners[j].value.packet_count&&owner_unobserved(j)){
  const A2ActorPart *p=&owners[j].value.parts[0];
  if(!strncmp(key,p->source_key,A2_ACTOR_SOURCE_KEY_SIZE)&&!memcmp(hash,p->source_sha256,32))return 1;
 }
 return 0;
}
