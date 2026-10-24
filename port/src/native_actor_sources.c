#include "native_actor_sources.h"
#include "native_actor_snapshot.h"
#include "native_actor_source_layout.h"
#include "../assets/native_chest_sources.h"
#include <limits.h>
#include <string.h>
#define RAM_SIZE 0x200000u
#define CHEST_SIZE 1760u
#define PC00_SIZE 31216u
#define SOURCE_LIMIT 64u
typedef struct {uint32_t address;unsigned valid,bytes;uint64_t generation;uint8_t relocated_hash[32];} Binding;
static Binding bindings[SOURCE_LIMIT];
static const uint8_t *memory;static size_t memory_size;static uint64_t serial;
static unsigned code_dirty=1,code_valid;
static struct {uint32_t address,headers[A2_ACTOR_SOURCE_PART_LIMIT],vertices[A2_ACTOR_SOURCE_PART_LIMIT];unsigned active,which,bytes,parts;} pending;
int a2_native_actor_sources_enabled;
uint32_t a2_native_actor_sources_watch_begin=UINT32_MAX,a2_native_actor_sources_watch_end;
/* Fixed, allocation-free SHA256 over the complete source. A matching name or
 * structural header alone never establishes original resource identity. */
static uint32_t ror(uint32_t v,unsigned n){return (v>>n)|(v<<(32-n));}
static void source_hash(const uint8_t *data,size_t size,uint8_t out[32]){
 static const uint32_t k[64]={
  0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
  0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
  0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
  0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
  0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
  0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
  0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
  0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2};
 uint32_t h[8]={0x6a09e667,0xbb67ae85,0x3c6ef372,0xa54ff53a,0x510e527f,0x9b05688c,0x1f83d9ab,0x5be0cd19};
 size_t total=(size+9+63)&~(size_t)63;uint64_t bits=(uint64_t)size*8;
 for(size_t offset=0;offset<total;offset+=64){
  uint32_t w[64]={0};
  for(unsigned j=0;j<64;j++){
   size_t at=offset+j;uint8_t b=at<size?data[at]:at==size?0x80:at>=total-8?(uint8_t)(bits>>(8*(total-1-at))):0;
   w[j/4]|=(uint32_t)b<<(24-8*(j%4));
  }
  for(unsigned j=16;j<64;j++){
   uint32_t a=w[j-15],b=w[j-2];
   w[j]=w[j-16]+(ror(a,7)^ror(a,18)^(a>>3))+w[j-7]+(ror(b,17)^ror(b,19)^(b>>10));
  }
  uint32_t a=h[0],b=h[1],c=h[2],d=h[3],e=h[4],f=h[5],g=h[6],v=h[7];
  for(unsigned j=0;j<64;j++){
   uint32_t t=v+(ror(e,6)^ror(e,11)^ror(e,25))+((e&f)^(~e&g))+k[j]+w[j];
   uint32_t u=(ror(a,2)^ror(a,13)^ror(a,22))+((a&b)^(a&c)^(b&c));
   v=g;g=f;f=e;e=d+t;d=c;c=b;b=a;a=t+u;
  }
  h[0]+=a;h[1]+=b;h[2]+=c;h[3]+=d;h[4]+=e;h[5]+=f;h[6]+=g;h[7]+=v;
 }
 for(unsigned j=0;j<32;j++)out[j]=(uint8_t)(h[j/4]>>(24-8*(j%4)));
}
static int physical(uint32_t a,uint32_t *out){
 a&=0x1fffffffu;if(a>=0x800000u)return 0;*out=a&0x1fffffu;return 1;
}
static uint32_t u32(uint32_t a){uint32_t v;memcpy(&v,memory+a,4);return v;}
static void retire(Binding *b){if(b->valid)a2_native_actor_snapshot_source_unbind(b->address);b->valid=0;}
void a2_native_actor_sources_reset(void){
 for(unsigned j=0;j<SOURCE_LIMIT;j++)retire(&bindings[j]);
 pending.active=0;a2_native_actor_sources_watch_begin=UINT32_MAX;a2_native_actor_sources_watch_end=0;
}
void a2_native_actor_sources_init(const uint8_t *ram,size_t size){a2_native_actor_sources_reset();memory=ram;memory_size=size;code_dirty=1;}
void a2_native_actor_sources_configure(int enabled){a2_native_actor_sources_reset();a2_native_actor_sources_enabled=!!enabled;code_dirty=1;}
static int code_matches(void){
 if(!memory||memory_size!=RAM_SIZE)return 0;
 if(code_dirty){code_valid=!memcmp(memory+0x2492c,chest_relocation_code,sizeof chest_relocation_code);code_dirty=0;}
 return code_valid;
}
void a2_native_actor_sources_before_relocation(uint32_t registry){
 if(!a2_native_actor_sources_enabled)return;
 pending.active=0;uint32_t p;if(!physical(registry,&p)||p>RAM_SIZE-32||(p&3)||!code_matches())return;
 if(memory[p+31]){
  /* A repeated setup may keep an existing identity, never invent one from
   * relocated bytes. Out-of-band mutation fails even without an observed write. */
  for(unsigned j=0;j<SOURCE_LIMIT;j++)if(bindings[j].valid&&bindings[j].address==p){
   uint8_t hash[32];source_hash(memory+p,bindings[j].bytes,hash);
   if(memcmp(hash,bindings[j].relocated_hash,32))retire(&bindings[j]);
  }
  return;
 }
 unsigned which=A2_ACTOR_SOURCE_COUNT,bytes=0,parts=0;
 for(unsigned j=a2_actor_source_lower_bound((const char*)memory+p);j<A2_ACTOR_SOURCE_COUNT &&
     !strncmp((const char*)memory+p,a2_actor_source_layouts[j].key,32);j++){
  const A2ActorSourceLayout *source=&a2_actor_source_layouts[j];
  if(p>RAM_SIZE-source->bytes||memcmp(memory+p,source->key,strlen(source->key)+1))continue;
  uint8_t hash[32];source_hash(memory+p,source->bytes,hash);
  if(!memcmp(hash,source->hash,32)){which=j;bytes=source->bytes;parts=source->parts;break;}
 }
 /* An attempted reload at the same address also retires its former proof,
  * including an unrecognized replacement that bypassed normal write hooks. */
 for(unsigned j=0;j<SOURCE_LIMIT;j++)if(bindings[j].valid&&
   p<bindings[j].address+bindings[j].bytes&&p+(bytes?bytes:32)>bindings[j].address)retire(&bindings[j]);
 if(which==A2_ACTOR_SOURCE_COUNT)return;
 pending.address=p;pending.which=which;pending.bytes=bytes;pending.parts=parts;
 for(unsigned j=0;j<parts;j++){
  pending.headers[j]=u32(p+32+4*j);
  pending.vertices[j]=u32(p+pending.headers[j]+20);
 }
 pending.active=1;
}
void a2_native_actor_sources_after_relocation(uint32_t registry,uint32_t result){
 if(!a2_native_actor_sources_enabled||!pending.active)return;
 unsigned which=pending.which;uint32_t p;pending.active=0;
 if(result!=0||!physical(registry,&p)||p!=pending.address||!code_matches()||memory[p+31]!=1||
    u32(p+32+4*pending.parts)!=UINT32_MAX)return;
 for(unsigned j=0;j<pending.parts;j++)if(u32(p+32+4*j)!=registry+pending.headers[j]||
    u32(p+pending.headers[j]+20)!=registry+pending.vertices[j])return;
 unsigned j;for(j=0;j<SOURCE_LIMIT&&bindings[j].valid;j++){}
 if(j==SOURCE_LIMIT||serial==UINT64_MAX)return;
 uint64_t generation=++serial;const A2ActorSourceLayout *source=&a2_actor_source_layouts[which];
 if(!a2_native_actor_snapshot_source_bind(p,source->key,source->hash,generation))return;
 Binding *b=&bindings[j];b->valid=1;b->address=p;b->generation=generation;b->bytes=pending.bytes;
 source_hash(memory+p,b->bytes,b->relocated_hash);
 if(p<a2_native_actor_sources_watch_begin)a2_native_actor_sources_watch_begin=p;
 if(p+b->bytes>a2_native_actor_sources_watch_end)a2_native_actor_sources_watch_end=p+b->bytes;
}
void a2_native_actor_sources_invalidate(uint32_t address,size_t bytes){
 uint32_t p;if(!bytes||!physical(address,&p))return;
 if(bytes>RAM_SIZE-p){code_dirty=1;a2_native_actor_sources_reset();return;}
 uint32_t end=p+(uint32_t)bytes;
 if(p<0x24d2cu&&end>0x2492cu){code_dirty=1;a2_native_actor_sources_reset();return;}
 for(unsigned j=0;j<SOURCE_LIMIT;j++)if(bindings[j].valid&&p<bindings[j].address+bindings[j].bytes&&end>bindings[j].address)retire(&bindings[j]);
 /* Only the synchronous, source-verified2492C routine writes the pending
  * blob. Its precise success epilogue seals those changes; no pending bind
  * is exposed during that transaction. Code changes above abort it. */
}
