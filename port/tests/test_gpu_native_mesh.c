/* Real GP0 decode/raster + real typed world metadata. The live boundary is
 * a recording oracle: no Metal, SDL, game, source assets or user files.
 * Packet ownership is injected only at its separately-tested API boundary. */
#define A2_NATIVE_MESH 1
#define A2_NATIVE_ACTOR_PACKETS 1
#define A2_DIALOGUE_PACKETS 1
#define A2_NATIVE_BILLBOARD 1
#define A2_WORLD_PRECISION 1
#define A2_HUD_PRESENT 1
#define A2_HD_FONTS 1
#define A2_HD_ART 1
#define A2_HD_ART_TEST 1
#define A2_HD_PORTRAITS 1
#define A2_HD_PORTRAITS_TEST 1
#include "hd_art.h"
#include "hd_portraits.h"
static const A2HDArt a2_hd_art_assets[1];
static const unsigned a2_hd_art_asset_count=0;
static const A2HDPortrait a2_hd_portraits_assets[1];
static const unsigned a2_hd_portraits_asset_count=0;
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "native_actor_packets.h"
#ifndef A2_NATIVE_MESH_GPU_SOURCE
#define A2_NATIVE_MESH_GPU_SOURCE "../src/gpu.c"
#endif
#include A2_NATIVE_MESH_GPU_SOURCE
void gpu_scene_submit_complete(void);

uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
uint32_t psx_frame_no=123,gpu_flips,a2_ramwatch;
void psx_vblank_tick(void){}
uint32_t psx_mmio_read(uint32_t p,int n){(void)p;(void)n;return 0;}
void psx_mmio_write(uint32_t p,uint32_t v,int n){(void)p;(void)v;(void)n;abort();}
void a2_ramwatch_hit(uint32_t p,uint32_t v,int n){(void)p;(void)v;(void)n;}
int a2_modelcap_active(void){return 0;}
FILE *a2_modelcap_file(void){return NULL;}
int a2_wide(void){return 1;}
static int hd_sample_fixture;
static unsigned mixed_hd_hits,mixed_hd_misses;
static A2HDUISample hd_sample_value;
void a2_hud_present_reset(void){}
uint64_t a2_hud_present_packet_token(uint32_t a,uint32_t w){(void)a;(void)w;return 0;}
int a2_hud_present_consume(uint32_t a,uint64_t t,const uint32_t *w,unsigned n,int *anchor){(void)a;(void)t;(void)w;(void)n;(void)anchor;return 0;}
int a2_hd_font_enabled(void){return 0;}
void a2_hd_font_reset(void){}
const A2HDGlyph *a2_hd_font_match(const uint16_t *v,uint32_t t,int u,int y,int w,int h){(void)v;(void)t;(void)u;(void)y;(void)w;(void)h;return NULL;}
unsigned a2_hd_font_alpha(const A2HDGlyph *g,int x,int y,int s){(void)g;(void)x;(void)y;(void)s;return 0;}
const uint8_t *a2_hd_font_coverage(const A2HDGlyph *g,int s){(void)g;(void)s;return NULL;}
unsigned a2_hd_ui_prepare(const uint16_t *v,uint32_t t,int u,int y,int w,int h,const A2HDPlate **o,unsigned c){(void)v;(void)t;(void)u;(void)y;(void)w;(void)h;(void)o;(void)c;return 0;}
int a2_hd_ui_sample_indices(const A2HDPlate *const *p,unsigned n,int u,int v,A2HDUIIndices *out){(void)p;(void)n;(void)u;(void)v;(void)out;return 0;}
int a2_hd_ui_bounds(const A2HDPlate *const *p,unsigned n,int out[4]){(void)p;(void)n;(void)out;return 0;}
int a2_hd_ui_sample(const A2HDPlate *const *p,unsigned n,const uint16_t *v,uint32_t c,int u,int y,A2HDUISample *o){(void)p;(void)n;(void)v;(void)c;(void)u;(void)y;if(!hd_sample_fixture)return 0;if(hd_sample_fixture==2){if((u>>8)&1){mixed_hd_misses++;return 0;}mixed_hd_hits++;}*o=hd_sample_value;return 1;}

static int art_fixture,portrait_fixture;
static A2HDArtSample art_value;
static A2HDPortraitSample portrait_value;
unsigned a2_hd_art_prepare(const A2HDArt *a,unsigned n,const uint16_t *v,uint32_t t,int x,int y,int x1,int y1,const A2HDArt **o,unsigned c){(void)a;(void)n;(void)v;(void)t;(void)x;(void)y;(void)x1;(void)y1;(void)o;(void)c;return 0;}
int a2_hd_art_sample(const A2HDArt *const *a,unsigned n,const uint16_t *v,uint32_t c,int u,int y,A2HDArtSample *out){(void)a;(void)n;(void)v;(void)c;(void)u;(void)y;if(!art_fixture)return 0;*out=art_value;return 1;}
void a2_hd_art_window_uv(uint32_t w,int *u,int *v){(void)w;(void)u;(void)v;}
const A2HDPortrait *a2_hd_portrait_prepare(const A2HDPortrait *a,unsigned n,const uint16_t *v,uint32_t t,uint32_t c,int x,int y,int x1,int y1){(void)a;(void)n;(void)v;(void)t;(void)c;(void)x;(void)y;(void)x1;(void)y1;return NULL;}
int a2_hd_portrait_sample(const A2HDPortrait *a,uint32_t w,int u,int v,A2HDPortraitSample *out){(void)a;(void)w;(void)u;(void)v;if(!portrait_fixture)return 0;*out=portrait_value;return 1;}

int a2_native_actor_packets_enabled=1;
uint32_t a2_native_actor_packets_watch_begin=UINT32_MAX,a2_native_actor_packets_watch_end;
void a2_native_actor_packets_invalidate(uint32_t a,size_t n){(void)a;(void)n;}
static uint64_t owned_token;
static uint32_t owned_address,owned_words[12];static unsigned owned_count,consumed,prefix_queries;
static A2ActorPacket owned;
static A2ActorPacketOwner fixture_owner;
static A2ActorPacketOwner fixture_other_owner,fixture_third_owner;
static int fixture_distinct_owners;
static uint64_t fixture_missing_owner;
static int fixture_source_family=A2_ACTOR_GAME00;
/* Full shadow certificates are independently tested through retained code;
 * this GPU boundary supplies an explicit physical-plane oracle. */
static int shadow_geometry_fixture;
static A2WorldShadowGeometry shadow_geometry_value;
int a2_world_shadow_geometry(const world_precision_vertex *v,unsigned n,int wide,
                            uint32_t address,const uint32_t *words,unsigned count,A2WorldShadowGeometry *out) {
 (void)v;(void)wide;(void)address;(void)words;
 if(!shadow_geometry_fixture || n!=4 || count!=9)return 0;
 *out=shadow_geometry_value;return 1;
}
const A2ActorPacketOwner *a2_native_actor_packets_owner(uint64_t handle){
 if(handle && handle==fixture_missing_owner)return NULL;
 if(fixture_distinct_owners && handle==88)return &fixture_other_owner;
 if(fixture_distinct_owners && handle==99)return &fixture_third_owner;
 if(!fixture_distinct_owners)fixture_owner.instance.renderer_root_q12[0]=(int32_t)handle;
 fixture_owner.handle=handle;fixture_owner.instance.source_family=fixture_source_family;
 return handle?&fixture_owner:NULL;
}
uint64_t a2_native_actor_packets_token(uint32_t a,uint32_t w){
 if(a==owned_address-4&&(w>>24==0xe1||w>>24==0xe2))prefix_queries++;
 return a==owned_address&&w==owned_words[0]?owned_token:0;
}
int a2_native_actor_packets_consume(uint32_t a,uint64_t t,const uint32_t *w,unsigned n,const A2ActorPacket **out){
 assert(a==owned_address&&t&&t==owned_token&&n==owned_count&&!memcmp(w,owned_words,4*n));
 consumed++;*out=&owned;return 1;
}

size_t a2_native_actor_packets_owners_latest(const A2ActorPacketOwner **out,size_t capacity){(void)out;(void)capacity;return 0;}
size_t a2_native_actor_packets_owner_packets(uint64_t h,const A2ActorPacket **out,size_t capacity){(void)h;(void)out;(void)capacity;return 0;}

static unsigned provider_kind,provider_count,provider_consumed,provider_fail;
static uint32_t provider_address,provider_words[12];static uint64_t provider_token;
static double provider_depth;
uint64_t a2_dialogue_packets_token(uint32_t a,uint32_t w){return provider_kind==1&&a==provider_address&&w==provider_words[0]?provider_token:0;}
int a2_dialogue_packets_consume(uint32_t a,uint64_t t,const uint32_t *w,unsigned n){
 assert(provider_kind==1&&a==provider_address&&t==provider_token&&n==provider_count&&!memcmp(w,provider_words,n*4));
 provider_token=0;provider_consumed++;return !provider_fail;
}
void a2_dialogue_packets_reset(void){provider_token=0;}
uint64_t a2_native_billboard_token(uint32_t a,uint32_t w){return provider_kind==2&&a==provider_address&&w==provider_words[0]?provider_token:0;}
int a2_native_billboard_consume(uint32_t a,uint64_t t,const uint32_t *w,unsigned n,double *z){
 assert(provider_kind==2&&a==provider_address&&t==provider_token&&n==provider_count&&!memcmp(w,provider_words,n*4));
 provider_token=0;provider_consumed++;*z=provider_depth;return !provider_fail;
}
void a2_native_billboard_reset(void){provider_token=0;}
/* This fixture isolates packet ownership; camera-aware billboards are covered
 * by test_world_billboard with the real billboard producer. */
int a2_native_billboard_vertex(uint32_t address,uint32_t word,world_precision_vertex *out){
 (void)address;(void)word;(void)out;return 0;
}

int a2_mesh_live_enabled,a2_mesh_live_active,a2_mesh_live_writes_watched,a2_mesh_live_failed;
int a2_mesh_live_x0,a2_mesh_live_y0,a2_mesh_live_x1,a2_mesh_live_y1;
static unsigned resets,clears,starts,invalidations,unknown_pixels,finalizes,row_calls,invalidation_calls;
static int force_no_owner;
static int recording_scale,recording_page,invalid;
static A2CompositePixel samples[160*160];static unsigned visits[160*160],sample_count;
static uint16_t alternate[160*160];static unsigned destination_queries;
static unsigned claims,transfer_reads,transfer_stores,selected_stores;
static uint16_t color_oracle(uint16_t,int,int,int,int,int,uint16_t,unsigned);
void a2_mesh_live_reset(void){resets++;a2_mesh_live_active=0;}
void a2_mesh_live_clear(uint32_t f,int s,int x,int y,int w,int h){
 assert(f==psx_frame_no);(void)s;(void)x;(void)y;(void)w;(void)h;clears++;
}
void a2_mesh_live_start(uint32_t f,int s,int page,const uint16_t *shadow,size_t stride,int wide){
 assert(f==psx_frame_no&&s==recording_scale&&page==recording_page&&shadow==SHADOW&&stride==(size_t)IR_W&&wide==1);
 starts++;a2_mesh_live_active=!force_no_owner&&!invalid;
}
int a2_mesh_live_owns(uint64_t h){return a2_mesh_live_enabled&&h==77;}
int a2_mesh_live_claim(uint64_t h){claims++;return a2_mesh_live_owns(h);}
int a2_mesh_live_claim_part(uint64_t h,unsigned part){(void)part;return a2_mesh_live_claim(h);}
void a2_mesh_live_start_view(uint32_t f,int s,int p,const uint16_t *v,size_t stride,int wide,int height){assert(height==172||height==216);a2_mesh_live_start(f,s,p,v,stride,wide);}
static int selected_index(int x,int y){
 x%=IR_W;y%=IR_H;if(x<0)x+=IR_W;if(y<0)y+=IR_H;
 if(!a2_mesh_live_enabled||force_no_owner||invalid||x<a2_mesh_live_x0||x>=a2_mesh_live_x1||y<a2_mesh_live_y0||y>=a2_mesh_live_y1)return -1;
 int index=(y-recording_page*recording_scale)*160+x;assert(index>=0&&index<160*160);return index;
}
uint16_t a2_mesh_live_read(int x,int y,uint16_t original){
 transfer_reads++;int i=selected_index(x,y);return i<0?original:alternate[i];
}
void a2_mesh_live_store(int x,int y,uint16_t value){
 transfer_stores++;int i=selected_index(x,y);if(i>=0){alternate[i]=value;selected_stores++;}
}
void a2_mesh_live_pixel(int x,int y,A2CompositePixel p){
 assert(x>=a2_mesh_live_x0&&x<a2_mesh_live_x1&&y>=a2_mesh_live_y0&&y<a2_mesh_live_y1);
 unsigned i=(unsigned)(y-recording_page*recording_scale)*160+(unsigned)x;assert(i<160*160);
 samples[i]=p;visits[i]++;sample_count++;
 if(p.kind==A2_COMPOSITE_UNKNOWN){unknown_pixels++;invalid=1;a2_mesh_live_active=0;}
 else if(p.kind!=A2_COMPOSITE_OWNED && (p.kind!=A2_COMPOSITE_WORLD || p.depth<=.5f))
  alternate[i]=color_oracle(alternate[i],p.r,p.g,p.b,p.semi,0,0,p.blend_mode)|(p.textured?(p.texel&0x8000):0);
}
uint16_t *a2_mesh_live_destination(int x,int y,A2CompositeKind kind,float depth){
 if(!a2_mesh_live_active||x<a2_mesh_live_x0||x>=a2_mesh_live_x1||y<a2_mesh_live_y0||y>=a2_mesh_live_y1)return NULL;
 destination_queries++;
 if(kind==A2_COMPOSITE_UNKNOWN||(kind==A2_COMPOSITE_WORLD&&(!isfinite(depth)||depth<0||depth>1))){
  unknown_pixels++;invalid=1;a2_mesh_live_active=0;return NULL;
 }
 if(kind==A2_COMPOSITE_OWNED||(kind==A2_COMPOSITE_WORLD&&depth>.5f))return NULL;
 unsigned i=(unsigned)(y-recording_page*recording_scale)*160+(unsigned)x;assert(i<160*160);
 return &alternate[i];
}
void a2_mesh_live_invalidate_rect(int x,int y,int w,int h){
 invalidation_calls++;
 if(w>0&&h>0&&x<a2_mesh_live_x1&&y<a2_mesh_live_y1&&x+w>a2_mesh_live_x0&&y+h>a2_mesh_live_y0){
  invalidations++;invalid=1;a2_mesh_live_active=0;
 }
}
void a2_mesh_live_finalize(void){finalizes++;}
void a2_mesh_live_finalize_at(uint32_t frame,const char *source){
 assert(frame==psx_frame_no&&(!strcmp(source,"scene-submit")||!strcmp(source,"vblank")));finalizes++;a2_mesh_live_active=0;
}
const uint16_t *a2_mesh_live_row(int y,const uint16_t *o,size_t w){(void)y;assert(w==(size_t)IR_W);row_calls++;return o;}

typedef struct {int x,y;double z;} Corner;
static uint32_t xy(int x,int y){return (uint16_t)x|((uint32_t)(uint16_t)y<<16);}
static void fresh(int scale,int page,int enabled){
 fixture_source_family=A2_ACTOR_GAME00;
 a2_mesh_live_enabled=0;world_precision_configure(1);gpu_set_ir(scale);gpu_gp1(0);gpu_set_world_raster(1);gpu_set_filter(0);
 memset(GPU_VRAM,0,sizeof GPU_VRAM);if(SHADOW)memset(SHADOW,0,(size_t)IR_W*IR_H*2);
 gpu_gp0(0xe3000000u|((unsigned)page<<10));gpu_gp0(0xe4000000u|319u|((unsigned)(page+215)<<10));
 gpu_gp0(0xe5000000u|((unsigned)page<<11));gpu_gp0(0xe1000000);
 recording_scale=scale;recording_page=page;invalid=0;a2_mesh_live_active=0;
 a2_mesh_live_x0=0;a2_mesh_live_x1=40*scale;a2_mesh_live_y0=page*scale;a2_mesh_live_y1=(page+40)*scale;
 memset(visits,0,sizeof visits);memset(samples,0,sizeof samples);
 memset(alternate,0,sizeof alternate);destination_queries=0;
 claims=transfer_reads=transfer_stores=selected_stores=0;a2_mesh_live_failed=0;
 sample_count=unknown_pixels=invalidations=starts=clears=consumed=prefix_queries=0;owned_token=0;owned_address=0;
 a2_mesh_live_enabled=enabled;a2_mesh_live_writes_watched=enabled;force_no_owner=0;invalidation_calls=0;
 hd_sample_value=(A2HDUISample){.background=0x4210,.ink=0x7fff,.alpha=160};
 provider_kind=provider_count=provider_consumed=provider_fail=0;provider_token=0;
 hd_sample_fixture=art_fixture=portrait_fixture=0;hd_art_count=hd_plate_count=0;hd_portrait=NULL;
}
/* Match actual uploaded texture storage; native VRAM remains authoritative,
 * and presentation starts with the same texels at every fine location. */
static void seed_texel(int x,int y,uint16_t value){
 GPU_VRAM[(y&511)*1024+(x&1023)]=value;
 for(int oy=0;oy<IR;oy++)for(int ox=0;ox<IR;ox++)*shadow_px(x*IR+ox,y*IR+oy)=value;
}
static void triangle(const Corner *p,unsigned command,int tracked,int owned_test,int broken){
 uint32_t words[12],src[3],dst[3],native[3],base=0x80090008;unsigned n=0;
 uint64_t object=world_precision_begin_object();words[n++]=(command<<24)|0x406080;
 for(unsigned j=0;j<3;j++){
  if(j&&(command&16))words[n++]=0x406080;
  native[j]=xy(p[j].x,p[j].y);src[j]=0x1f800100+j*16;dst[j]=base+4*n;words[n++]=native[j];
  if(command&4)words[n++]=(j==1?0x104u<<16:0)|32u|(32u<<8);
  world_precision_vertex v;
  world_precision_gte_push(native[j],(int64_t)p[j].x*65536+16384,(int64_t)p[j].y*65536+32768,900,1);
  assert(world_precision_gte_read(14,native[j],&v));v.z=p[j].z;
  world_precision_record(src[j],native[j],object,&v);
 }
 if(tracked)assert(world_precision_emit(dst,native,src,3,object));
 if(owned_test){owned=(A2ActorPacket){.owner_handle=77};owned_token=99;owned_address=base;owned_count=n;memcpy(owned_words,words,4*n);}
 for(unsigned j=0;j<n;j++)gpu_gp0_at(words[j],broken&&j==n-1?base+4*j+4:base+4*j);
}
static uint16_t color_oracle(uint16_t before,int r,int grn,int b,int semi,int tex,uint16_t texel,unsigned mode){
 if(tex&&!texel)return before;
 int colors[3]={r,grn,b};uint16_t result=tex?(texel&0x8000):0;
 for(unsigned c=0;c<3;c++){
  int source=colors[c],bg=((before>>(5*c))&31)*8;
  if(tex){source=(((texel>>(5*c))&31)*8*source)/128;if(source>255)source=255;}
  if(semi&&(!tex||(texel&0x8000))){
   if(mode==0)source=(bg+source)/2;else if(mode==1)source=bg+source;
   else if(mode==2)source=bg-source;else source=bg+source/4;
  }
  if(source<0)source=0;if(source>255)source=255;
  result|=(uint16_t)((source/8)<<(5*c));
 }
 return result;
}
static uint16_t alpha_oracle(uint16_t before,uint16_t after,unsigned amount){
 if(!amount)return before;
 uint16_t result=after&0x8000;
 for(unsigned c=0;c<3;c++)result|=(uint16_t)(((((before>>(5*c))&31)*(255-amount)+((after>>(5*c))&31)*amount+127)/255)<<(5*c));
 return result;
}
static void hud_font_alternate(void){
 fresh(2,0,1);a2_mesh_live_start(psx_frame_no,2,0,SHADOW,IR_W,1);mesh_pixel_kind=A2_COMPOSITE_HUD;
 const unsigned x=16,y=16,i=y*160+x;const uint16_t native=31<<5,modern=31<<10,ink=0x83ef;
 SHADOW[y*IR_W+x]=native;alternate[i]=modern;
 put_font_coverage(x,y,128,96,80,1,ink,128);
 assert(!invalid&&a2_mesh_live_active);
 assert(SHADOW[y*IR_W+x]==alpha_oracle(native,color_oracle(native,128,96,80,1,1,ink,0),128));
 assert(alternate[i]==alpha_oracle(modern,color_oracle(modern,128,96,80,1,1,ink,0),128));
 assert(destination_queries==1);
}

static void hd_background_matrix(void){
 const unsigned coverages[]={0,128,255};
 for(int scale=2;scale<=4;scale++)for(int page=0;page<=256;page+=256)
 for(unsigned mode=0;mode<4;mode++)for(unsigned stp=0;stp<2;stp++)for(unsigned a=0;a<3;a++){
  fresh(scale,page,1);a2_mesh_live_start(psx_frame_no,scale,page,SHADOW,IR_W,1);
  mesh_pixel_kind=A2_COMPOSITE_HUD;cur_tpage=mode<<5;
  int x=8*scale,y=(page+8)*scale;unsigned i=(y-page*scale)*160+x;
  uint16_t native=0x1278,modern=0x5b21,ink=(uint16_t)(0x124f|(stp<<15));
  unsigned coverage=coverages[a];SHADOW[(size_t)y*IR_W+x]=native;alternate[i]=modern;
  put_font_coverage(x,y,151,93,177,1,ink,coverage);
  assert(!invalid);
  assert(SHADOW[(size_t)y*IR_W+x]==alpha_oracle(native,color_oracle(native,151,93,177,1,1,ink,mode),coverage));
  assert(alternate[i]==alpha_oracle(modern,color_oracle(modern,151,93,177,1,1,ink,mode),coverage));
  assert(destination_queries==(coverage?1u:0u));
 }
 for(unsigned mode=0;mode<4;mode++)for(unsigned m=0;m<3;m++)for(unsigned c=0;c<3;c++)for(int artwork=0;artwork<=1;artwork++){
  fresh(2,0,1);a2_mesh_live_start(psx_frame_no,2,0,SHADOW,IR_W,1);mesh_pixel_kind=A2_COMPOSITE_HUD;cur_tpage=mode<<5;
  hd_sample_fixture=1;art_fixture=artwork;hd_plate_count=1;hd_art_count=artwork;
  hd_sample_value.shadow=0x8821;hd_sample_value.shadow_alpha=93;
  art_value=(A2HDArtSample){0x93ef,0x5210,(uint8_t)coverages[m],(uint8_t)coverages[c]};
  const unsigned x=16,y=16,i=y*160+x;uint16_t before[2]={0x1278,0x5b21};
  SHADOW[y*IR_W+x]=before[0];alternate[i]=before[1];assert(put_hd_ui(x,y,151,93,177,1,0,0));assert(!invalid);
  for(unsigned d=0;d<2;d++){
   uint16_t first=color_oracle(before[d],151,93,177,1,1,art_value.first,mode);
   uint16_t second=color_oracle(before[d],151,93,177,1,1,art_value.second,mode);
   uint16_t base=artwork?alpha_oracle(before[d],alpha_oracle(first,second,art_value.mix),art_value.coverage):color_oracle(before[d],151,93,177,1,1,hd_sample_value.background,mode);
   uint16_t shade=color_oracle(before[d],151,93,177,1,1,hd_sample_value.shadow,mode);
   base=alpha_oracle(base,shade,hd_sample_value.shadow_alpha);
   uint16_t ink=color_oracle(before[d],151,93,177,1,1,0x7fff,mode);
   uint16_t expected=alpha_oracle(base,ink,160);
   assert((d?alternate[i]:SHADOW[y*IR_W+x])==expected);
  }
 }
 for(unsigned a=0;a<3;a++){
  fresh(2,0,1);a2_mesh_live_start(psx_frame_no,2,0,SHADOW,IR_W,1);mesh_pixel_kind=A2_COMPOSITE_HUD;
  portrait_fixture=1;portrait_value=(A2HDPortraitSample){0,119,251,(uint8_t)coverages[a]};
  unsigned x=16,y=16,i=y*160+x;uint16_t before[2]={0x1278,0x5b21};
  SHADOW[y*IR_W+x]=before[0];alternate[i]=before[1];assert(put_hd_portrait(x,y,128,93,177,0,0));assert(!invalid);
  for(unsigned d=0;d<2;d++){
   unsigned rgb[3]={0,119*93/128,255};uint16_t expected=0;
   for(unsigned ch=0;ch<3;ch++)expected|=(uint16_t)((((rgb[ch]*coverages[a]+((before[d]>>(5*ch))&31)*8*(255-coverages[a])+127)/255)>>3)<<(5*ch));
   assert((d?alternate[i]:SHADOW[y*IR_W+x])==expected);
  }
 }
}
static void rectangle_alternate(void){
 for(int scale=2;scale<=4;scale++)for(int page=0;page<=256;page+=256)
 for(unsigned mode=0;mode<4;mode++)for(int semi=0;semi<=1;semi++)for(unsigned texture=0;texture<4;texture++){
  fresh(scale,page,1);a2_mesh_live_start(psx_frame_no,scale,page,SHADOW,IR_W,1);mesh_pixel_kind=A2_COMPOSITE_HUD;cur_tpage=mode<<5;
  const uint16_t native=0x1278,modern=0x5b21;
  uint16_t texel=texture==3?0:(uint16_t)(0x124f|(texture==2?0x8000:0));
  if(texture){cur_tpage|=(2u<<7)|6u;for(int ty=0;ty<2;ty++)for(int tx=384;tx<386;tx++)seed_texel(tx,ty,texel);}
  for(int y=8*scale;y<10*scale;y++)for(int x=8*scale;x<10*scale;x++){
   SHADOW[(size_t)(y+page*scale)*IR_W+x]=native;alternate[y*160+x]=modern;
  }
  rect_fine_blocks(8,page+8,2,2,0,0,151,93,177,semi,texture!=0,scale);assert(!invalid);
  for(int y=8*scale;y<10*scale;y++)for(int x=8*scale;x<10*scale;x++){
   assert(SHADOW[(size_t)(y+page*scale)*IR_W+x]==color_oracle(native,151,93,177,semi,texture!=0,texel,mode));
   assert(alternate[y*160+x]==color_oracle(modern,151,93,177,semi,texture!=0,texel,mode));
  }
 }
}
static void direct_role_guards(void){
 fresh(2,0,1);a2_mesh_live_start(psx_frame_no,2,0,SHADOW,IR_W,1);mesh_pixel_kind=A2_COMPOSITE_UNKNOWN;
 hd_art_count=1;art_fixture=1;art_value=(A2HDArtSample){0xffff,0x124f,128,0};
 assert(put_hd_ui(16,16,128,128,128,1,0,0));assert(!invalid&&!destination_queries);
 for(int missing=0;missing<2;missing++) {
  fresh(2,0,1);a2_mesh_live_start(psx_frame_no,2,0,SHADOW,IR_W,1);mesh_pixel_kind=A2_COMPOSITE_WORLD;
  mesh_depth_valid=!missing;mesh_depth_plane[0]=mesh_depth_plane[1]=0;mesh_depth_plane[2]=NAN;
  put_font_coverage(16,16,128,128,128,0,0xffff,128);assert(!invalid&&destination_queries==1&&alternate[16*160+16]);
 }
 fresh(2,0,1);a2_mesh_live_start(psx_frame_no,2,0,SHADOW,IR_W,1);mesh_pixel_kind=A2_COMPOSITE_UNKNOWN;
 put_font_coverage(16,16,128,128,128,0,0,255);put_font_coverage(16,16,128,128,128,0,0xffff,0);
 put_font_coverage(-1,16,128,128,128,0,0xffff,255);put_font_coverage(100,16,128,128,128,0,0xffff,255);
 assert(!invalid&&!destination_queries);
 for(unsigned kind=A2_COMPOSITE_UNKNOWN;kind<=A2_COMPOSITE_HUD;kind++)for(int far=0;far<2;far++){
  fresh(2,0,1);a2_mesh_live_start(psx_frame_no,2,0,SHADOW,IR_W,1);
  mesh_pixel_kind=(A2CompositeKind)kind;mesh_depth_valid=1;mesh_depth_plane[0]=mesh_depth_plane[1]=0;mesh_depth_plane[2]=far?.75:.25;
  alternate[16*160+16]=0x4321;put_font_coverage(16,16,128,128,128,0,0xffff,128);
  assert(!invalid);if(kind==A2_COMPOSITE_OWNED||(kind==A2_COMPOSITE_WORLD&&far))assert(alternate[16*160+16]==0x4321);else assert(alternate[16*160+16]!=0x4321);
  if(kind==A2_COMPOSITE_OWNED)assert(!SHADOW[16*IR_W+16]);
 }
}

static void packet_provider_routes(void){
 for(int scale=2;scale<=4;scale++)for(int page=0;page<=256;page+=256)
 for(unsigned kind=1;kind<=2;kind++)for(unsigned fault=0;fault<4;fault++) {
  fresh(scale,page,1);provider_kind=kind;provider_address=0x800a0008;provider_token=71;provider_depth=4;
  provider_fail=fault==2;
  gpu_gp0(0xe1000000u|(2u<<7)|6u);
  for(int y=0;y<16;y++)for(int x=384;x<400;x++)seed_texel(x,y,0xffff);
  if(kind==1) {
   uint32_t words[]={0x66707070,xy(8,8),0,xy(8,8)};provider_count=4;memcpy(provider_words,words,sizeof words);
  } else {
   uint32_t words[]={0x2e808080,xy(8,8),0,xy(16,8),8u|((2u<<7|6u)<<16),xy(8,16),8u<<8,xy(16,16),8u|(8u<<8)};
   provider_count=9;memcpy(provider_words,words,sizeof words);
  }
  if(fault==3)provider_depth=NAN;
  /* An E2 prefix must not accidentally take the polygon/rect token. */
  gpu_gp0_at(0xe2000000,provider_address-4);
  for(unsigned i=0;i<provider_count;i++)gpu_gp0_at(provider_words[i],provider_address+4*i+(fault==1&&i==provider_count-1?4:0));
  int accepted=fault==0||(kind==1&&fault==3);
  assert(provider_consumed==(fault==1?0u:1u));
  if(!accepted){
   assert(!invalid&&sample_count);
   for(unsigned i=0;i<160*160;i++)if(visits[i])assert(samples[i].kind==A2_COMPOSITE_ORDERED);
  }
  else {
   assert(!invalid&&a2_mesh_live_active);
   if(kind==1)assert(sample_count&&samples[8*scale*160+8*scale].kind==A2_COMPOSITE_HUD);
   else {
    assert(sample_count);
    for(unsigned i=0;i<160*160;i++)if(visits[i]) {
     assert(samples[i].kind==A2_COMPOSITE_WORLD);
     assert(fabs(samples[i].depth-(65536.0/65535.0)*(1-1.0/4))<1e-6);
    }
   }
  }
 }
}

/* The WORLD producer now supplies both GT3 and GT4. Exercise actual FIFO
 * lengths and both halves of the quad through the real raster, independently
 * of the producer's native-interpreter tests. Provenance is the API seam here. */
static void world_billboard_raster_routes(void){
 static uint16_t native[1024*512];
 uint16_t *fine=malloc(1024u*512u*16u*2u);assert(fine);
 const unsigned commands[]={0x34,0x35,0x36,0x37,0x3c,0x3d,0x3e,0x3f};
 for(int scale=2;scale<=4;scale++)for(int page=0;page<=256;page+=256)
 for(unsigned op=0;op<8;op++)for(unsigned far=0;far<2;far++)for(unsigned enabled=0;enabled<2;enabled++){
  fresh(scale,page,enabled);provider_kind=2;provider_address=0x800a0008;
  provider_token=enabled?71:0;provider_depth=far?773.244140625:1.25;
  for(int y=0;y<16;y++)for(int x=384;x<400;x++)seed_texel(x,y,0xffff);
  uint32_t words[]={commands[op]<<24|0x608080,xy(8,8),0,
                   0x806080,xy(16,8),8u|((2u<<7|6u)<<16),
                   0x808060,xy(8,16),8u<<8,
                   0x808080,xy(16,16),8u|(8u<<8)};
  provider_count=(commands[op]&8)?12:9;memcpy(provider_words,words,provider_count*4);
  gpu_gp0_at(0xe2000000,provider_address-4);
  for(unsigned i=0;i<provider_count;i++)gpu_gp0_at(words[i],provider_address+4*i);
  if(!enabled){memcpy(native,GPU_VRAM,sizeof native);memcpy(fine,SHADOW,(size_t)IR_W*IR_H*2);continue;}
  assert(provider_consumed==1&&!invalid&&sample_count&&a2_mesh_live_active);
  assert(!memcmp(native,GPU_VRAM,sizeof native)&&!memcmp(fine,SHADOW,(size_t)IR_W*IR_H*2));
  unsigned covered=0;
  for(unsigned i=0;i<160*160;i++)if(visits[i]){
   ++covered;assert(samples[i].kind==A2_COMPOSITE_WORLD);
   assert(fabs(samples[i].depth-(65536.0/65535.0)*(1-1.0/provider_depth))<1e-6);
   assert(far?alternate[i]==0:alternate[i]!=0);
  }
  unsigned side=8u*(unsigned)scale;
  assert(covered==(provider_count==12?side*side:side*(side+1)/2));
 }
 free(fine);
}

static void owned_coverage_diagnostic(void){
 uint16_t *native=malloc(sizeof GPU_VRAM),*fine=NULL;assert(native);
 FILE *log=tmpfile();assert(log);int saved=dup(STDERR_FILENO);assert(saved>=0);fflush(stderr);assert(dup2(fileno(log),STDERR_FILENO)>=0);
 for(unsigned enabled=0;enabled<2;enabled++){
  if(enabled)setenv("A2_MESH_TRACE","0",1);else unsetenv("A2_MESH_TRACE");
  memset(&mesh_coverage_trace,0,sizeof mesh_coverage_trace);
  fresh(2,0,1);a2_mesh_live_x0=a2_mesh_live_y0=20;a2_mesh_live_x1=a2_mesh_live_y1=30;
  const Corner corners[]={{4,4,2},{28,4,4},{4,28,8}};
  triangle(corners,0x20,1,1,0);mesh_coverage_flush();assert(!invalid&&consumed==1);
  fflush(stderr);
  if(!enabled){
   assert(ftell(log)==0&&!mesh_coverage_trace.pixels&&!mesh_coverage_trace.outside);
   memcpy(native,GPU_VRAM,sizeof GPU_VRAM);fine=malloc((size_t)IR_W*IR_H*2);assert(fine);memcpy(fine,SHADOW,(size_t)IR_W*IR_H*2);
  }else {
   assert(ftell(log)>0&&mesh_coverage_trace.pixels>mesh_coverage_trace.outside&&mesh_coverage_trace.outside>0);
   assert(mesh_coverage_trace.lines==1&&mesh_coverage_trace.owner==77&&mesh_coverage_trace.source==0x80090008);
   assert(!memcmp(native,GPU_VRAM,sizeof GPU_VRAM)&&!memcmp(fine,SHADOW,(size_t)IR_W*IR_H*2));
   assert(mesh_coverage_trace.roi[0]==20&&mesh_coverage_trace.roi[2]==30);
  }
 }
 fflush(stderr);assert(dup2(saved,STDERR_FILENO)>=0);close(saved);fclose(log);free(fine);free(native);
 unsetenv("A2_MESH_TRACE");memset(&mesh_coverage_trace,0,sizeof mesh_coverage_trace);
}
static void depth_oracle(int scale,int page,int reversed,int clip){
 fresh(scale,page,1);
 Corner p[3]={{clip?-4:4,4,2},{28,4,4},{clip?-4:4,28,8}};
 if(reversed){Corner t=p[1];p[1]=p[2];p[2]=t;}
 triangle(p,0x20,1,0,0);assert(world_primitive_valid&&sample_count&&!invalid);
 double ax=p[0].x+.25,ay=p[0].y+.5,bx=p[1].x+.25,by=p[1].y+.5,cx=p[2].x+.25,cy=p[2].y+.5;
 double determinant=(bx-ax)*(cy-ay)-(by-ay)*(cx-ax);
 unsigned expected_count=0;
 for(int y=0;y<40*scale;y++)for(int x=0;x<40*scale;x++){
  double sx=(double)x/scale,sy=(double)y/scale;
  double b=((sx-ax)*(cy-ay)-(sy-ay)*(cx-ax))/determinant;
  double c=((bx-ax)*(sy-ay)-(by-ay)*(sx-ax))/determinant,a=1-b-c;
  /* Non-boundary points are sufficient to detect wrong coverage, winding,
   * pixel location and reciprocal depth without duplicating raster edges. */
  unsigned index=(unsigned)y*160+(unsigned)x;
  if(fabs(a)<1e-10||fabs(b)<1e-10||fabs(c)<1e-10)continue;
  int covered=a>0&&b>0&&c>0;
  assert(visits[index]==(unsigned)covered);
  if(!covered)continue;expected_count++;
  double expected=(65536.0/65535.0)*(1-a/p[0].z-b/p[1].z-c/p[2].z);
  if(fabs(samples[index].depth-expected)>1e-6){
   fprintf(stderr,"depth IR%d page%d reverse%d @%d,%d: %.9f != %.9f\n",scale,page,reversed,x,y,samples[index].depth,expected);abort();
  }
  assert(samples[index].kind==A2_COMPOSITE_WORLD&&samples[index].r==128&&samples[index].g==96&&samples[index].b==64);
 }
 assert(expected_count>40);
}
/* The retained close-approach G4 at frame4246 has native corners
 * (158,147),(158,146),(158,148),(160,144): only its second half draws.
 * Translate that shape into this fixture's ROI, retaining unequal depths.
 * Fractions vary by vertex, so even the collinear native half has a nonzero
 * precise area. IR1 keeps native coverage; HD uses both precise halves. */
static void fallback_quad(const Corner *p,int camera,int fault){
 uint32_t words[8],src[4],dst[4],native[4],base=0x80090108;
 uint64_t object=world_precision_begin_object();
 for(unsigned j=0;j<4;j++){
  words[2*j]=(j?0:0x38000000u)|0x406080;
  native[j]=xy(p[j].x,p[j].y);words[2*j+1]=native[j];
  src[j]=0x1f800200+j*16;dst[j]=base+4*(2*j+1);
  world_precision_vertex v;
  world_precision_gte_push(native[j],(int64_t)p[j].x*65536+8192*(j+1),
                           (int64_t)p[j].y*65536+4096*(j+1),900,1);
  assert(world_precision_gte_read(14,native[j],&v));v.z=p[j].z;
  if(camera){v.projection_kind=WORLD_PROJECTION_CAMERA;v.camera_generation=object;}
  if(fault==2)v.z=NAN;
  if(fault==3)v.z=0;
  if(fault==4)v.z=65536;
  if(fault==5&&j==3){v.projection_kind=WORLD_PROJECTION_CAMERA;v.camera_generation=object;}
  world_precision_record(src[j],native[j],object,&v);
 }
 if(fault!=1){int emitted=world_precision_emit(dst,native,src,4,object);assert(emitted==(fault!=5));}
 for(unsigned j=0;j<8;j++)gpu_gp0_at(words[j],base+4*j);
}
static void fallback_quad_oracle(int scale,int page,int reverse,int half,int clip,int camera){
 Corner p[4]={{14,17,2},{14,16,4},{14,18,8},{16,14,16}};
 if(reverse){Corner t=p[1];p[1]=p[2];p[2]=t;}
 if(half){Corner t=p[0];p[0]=p[3];p[3]=t;t=p[1];p[1]=p[2];p[2]=t;}
 if(clip)for(int i=0;i<4;i++)p[i].x-=15;
 static uint16_t native[1024*512];
 uint16_t *fine=malloc((size_t)1024*512*scale*scale*2);assert(fine);
 fresh(scale,page,0);fallback_quad(p,camera,0);
 memcpy(native,GPU_VRAM,sizeof native);memcpy(fine,SHADOW,(size_t)IR_W*IR_H*2);
 fresh(scale,page,1);fallback_quad(p,camera,0);
 assert(!memcmp(native,GPU_VRAM,sizeof native));assert(!memcmp(fine,SHADOW,(size_t)IR_W*IR_H*2));free(fine);
 if(!sample_count||invalid){fprintf(stderr,"degenerate G4 IR%d page%d reverse%d half%d clip%d camera%d samples%u unknown%u\n",scale,page,reverse,half,clip,camera,sample_count,unknown_pixels);abort();}
 assert(world_primitive_valid);
 unsigned interiors=0,depth_checked=0;
 for(int y=0;y<40*scale;y++)for(int x=0;x<40*scale;x++){
  unsigned index=(unsigned)y*160+(unsigned)x;
  double sx=(double)x/scale,sy=(double)y/scale,expected=0;
  unsigned covered=0;int boundary=0;
  for(int t=0;t<2;t++){
   double ax=p[t].x,ay=p[t].y,bx=p[t+1].x,by=p[t+1].y,cx=p[t+2].x,cy=p[t+2].y;
   if(scale>1){
    ax+=(t+1)/8.0;ay+=(t+1)/16.0;
    bx+=(t+2)/8.0;by+=(t+2)/16.0;
    cx+=(t+3)/8.0;cy+=(t+3)/16.0;
   }
   double determinant=(bx-ax)*(cy-ay)-(by-ay)*(cx-ax);
   if(determinant==0)continue;
   double b=((sx-ax)*(cy-ay)-(sy-ay)*(cx-ax))/determinant;
   double c=((bx-ax)*(sy-ay)-(by-ay)*(sx-ax))/determinant,a=1-b-c;
   if(fabs(a)<1e-10||fabs(b)<1e-10||fabs(c)<1e-10){boundary=1;continue;}
   if(a>0&&b>0&&c>0){
    covered++;
    expected=(65536.0/65535.0)*(1-a/p[t].z-b/p[t+1].z-c/p[t+2].z);
   }
  }
  /* Shared-edge ownership has separate exact tests. This independent
   * floating oracle checks strict interiors and each half's depth plane. */
  if(boundary)continue;
  assert(visits[index]==covered);interiors+=covered;
  if(!covered)continue;
  assert(samples[index].kind==A2_COMPOSITE_WORLD);
  assert(isfinite(samples[index].depth)&&fabs(samples[index].depth-expected)<1e-6);
  depth_checked++;
 }
 assert(interiors&&depth_checked);
}
static void fallback_quad_rejection(void){
 const Corner good[3]={{4,4,2},{28,4,4},{4,28,8}};
 const Corner p[4]={{14,17,2},{14,16,4},{14,18,8},{16,14,16}};
 for(int scale=2;scale<=4;scale++)for(int page=0;page<=256;page+=256)for(int fault=1;fault<=5;fault++){
  fresh(scale,page,1);triangle(good,0x20,1,0,0);assert(sample_count&&!invalid);
  /* A valid preceding triangle must not lend its plane to untracked,
   * nonfinite/out-of-range depth, or mixed-kind quad metadata. */
  memset(visits,0,sizeof visits);sample_count=0;
  fallback_quad(p,0,fault);assert(sample_count&&!unknown_pixels&&!invalid);
  for(unsigned i=0;i<160*160;i++)if(visits[i])assert(samples[i].kind==A2_COMPOSITE_ORDERED);
 }
}
static void native_equality(void){
 static uint16_t vram[1024*512];uint16_t *fine=malloc(1024u*512u*16u*2u);assert(fine);
 const Corner p[]={{4,4,2},{28,4,4},{4,28,8}};
 for(int s=1;s<=4;s++){
  fresh(s,256,0);triangle(p,0x22,1,0,0);
  memcpy(fine,SHADOW,(size_t)IR_W*IR_H*2); /* Native world without the old chest. */
  triangle(p,0x20,0,1,0);memcpy(vram,GPU_VRAM,sizeof vram);
  fresh(s,256,1);triangle(p,0x22,1,0,0);triangle(p,0x20,0,1,0);
  assert(!memcmp(vram,GPU_VRAM,sizeof vram)&&!memcmp(fine,SHADOW,(size_t)IR_W*IR_H*2));
  assert(consumed==1&&sample_count);
 }
 free(fine);
}
static void invalidation_routes(void){
 const Corner p[]={{4,4,2},{28,4,4},{4,28,8}};
 fresh(2,0,1);triangle(p,0x20,0,0,0);assert(sample_count&&!unknown_pixels&&!invalid);
 fresh(2,0,1);triangle(p,0x20,1,0,0);gpu_scene_submit_complete();unsigned prior=starts;
 gpu_gp0(0x480000ff);gpu_gp0(xy(8,8));gpu_gp0(xy(9,9));gpu_gp0(xy(10,10));gpu_gp0(0x50005000);assert(starts>prior&&!invalidations&&!invalid);
 fresh(2,0,1);triangle(p,0x20,1,0,0);gpu_gp0(0x620000ff);gpu_gp0(xy(8,8));gpu_gp0(xy(4,4));assert(!invalidations&&!invalid);
 fresh(2,256,1);triangle(p,0x20,1,0,0);gpu_scene_submit_complete();gpu_gp0(0x80000000);gpu_gp0(xy(8,264));gpu_gp0(xy(80,264));gpu_gp0(xy(4,4));assert(transfer_reads&&transfer_stores&&!invalidations&&!invalid);
 fresh(2,256,1);triangle(p,0x20,1,0,0);gpu_scene_submit_complete();gpu_gp0(0xa0000000);gpu_gp0(xy(8,264));gpu_gp0(xy(2,1));gpu_gp0(0x7fff7fff);assert(selected_stores&&!invalidations&&!invalid);
 fresh(2,0,1);triangle(p,0x20,1,0,0);unsigned before=resets;gpu_gp1(0);assert(resets==before+1&&!a2_mesh_live_active);
 fresh(2,0,1);triangle(p,0x20,1,0,0);before=resets;gpu_set_ir(3);assert(resets==before+1&&!a2_mesh_live_active);
 fresh(2,0,1);triangle(p,0x20,1,0,0);mesh_pixel_kind=A2_COMPOSITE_UNKNOWN;put_font_coverage(20,20,128,128,128,0,0x7fff,128);assert(!unknown_pixels&&!invalid);
 fresh(2,0,1);triangle(p,0x20,1,0,0);before=finalizes;gpu_scene_submit_complete();assert(finalizes==before+1);
 a2_mesh_live_enabled=0;before=finalizes;gpu_scene_submit_complete();assert(finalizes==before);a2_mesh_live_enabled=1;
 before=finalizes;gpu_vblank();assert(finalizes==before+1);before=row_calls;(void)gpu_display_row(20);assert(row_calls==before+1);
 fresh(2,0,1);gpu_gp0(0x02000000);gpu_gp0(0);gpu_gp0(xy(320,216));assert(clears==1);
}
static void fill_wrap_invalidation(void){
 static uint16_t native[1024*512];
 uint16_t *fine=malloc(1024u*512u*16u*2u);assert(fine);
 /* Actual GP0 fill inputs: wrap X on both pages, Y, corner, canonical clears. */
 const struct {int page,x,y,w,h,canonical;} cases[]={
  {0,1008,8,32,1,0},{256,1008,264,32,1,0},
  {0,16,511,16,2,0},{0,1008,511,32,2,0},
  {0,0,0,320,216,1},{256,0,256,320,216,1}
 };
 for(int scale=1;scale<=4;scale++)for(unsigned c=0;c<sizeof cases/sizeof cases[0];c++){
  for(int enabled=0;enabled<2;enabled++){
   fresh(scale,cases[c].page,enabled);
   gpu_gp0(0x020000ff);gpu_gp0(xy(cases[c].x,cases[c].y));gpu_gp0(xy(cases[c].w,cases[c].h));
   assert(GPU_VRAM[((cases[c].y+cases[c].h-1)&511)*1024+((cases[c].x+cases[c].w-1)&1023)]==31);
   if(cases[c].canonical){assert(clears==1&&!invalidation_calls&&!invalid);}
   else {assert(!invalid&&!invalidations);if(enabled)assert(clears==0&&selected_stores);}
   if(!enabled){memcpy(native,GPU_VRAM,sizeof native);if(SHADOW)memcpy(fine,SHADOW,(size_t)IR_W*IR_H*2);}
   else {assert(!memcmp(native,GPU_VRAM,sizeof native));if(SHADOW)assert(!memcmp(fine,SHADOW,(size_t)IR_W*IR_H*2));}
  }
 }
 free(fine);
}
static void inactive_hd_write_guard(void){
 static uint16_t expected[2048*1024],native[1024*512];
 for(int watched=1;watched>=0;watched--){
  fresh(2,0,1);a2_mesh_live_writes_watched=watched;force_no_owner=1;
  /* Actual title-class GP0 sprite plus direct HD coverage writer. */
  gpu_gp0(0x660080ff);gpu_gp0(xy(8,8));gpu_gp0(0);gpu_gp0(xy(4,4));
  put_font_coverage(20,20,128,100,80,1,0xffff,128);
  hd_plate_count=1;hd_sample_fixture=1;assert(put_hd_ui(22,22,100,120,128,0,0,0));hd_sample_fixture=0;hd_plate_count=0;
  assert(starts==1); /* guarding writes must never suppress discovery */
  if(watched){assert(!invalidations);memcpy(expected,SHADOW,sizeof expected);memcpy(native,GPU_VRAM,sizeof native);}
  else{assert(invalidation_calls==0);assert(!memcmp(expected,SHADOW,sizeof expected));assert(!memcmp(native,GPU_VRAM,sizeof native));}
 }
}
static void owned_prefix_and_blend(void){
 const Corner p[]={{4,4,2},{28,4,4},{4,28,8}};
 for(unsigned e=0;e<2;e++){
  fresh(2,0,1);owned_address=0x80090008;
  uint32_t prefix=e?0xe2000841u:0xe1000060u;
  gpu_gp0_at(prefix,owned_address-4);assert(prefix_queries==1);
  triangle(p,0x20,0,1,0);assert(consumed==1&&!unknown_pixels);
  assert(e?g.texwin==(prefix&0xfffff):g.texpage==(prefix&0xffffu));
  for(unsigned j=0;j<160*160;j++)if(visits[j])assert(samples[j].kind==A2_COMPOSITE_OWNED);
 }
 fresh(2,0,1);triangle(p,0x20,0,1,1);assert(consumed==0&&sample_count&&!unknown_pixels&&!invalid); /* no false owner; actual stream remains ORDERED */
 for(unsigned stp=0;stp<2;stp++){
  fresh(2,0,1);seed_texel(256+32,32,(uint16_t)(0x4210|(stp?0x8000:0)));
  triangle(p,0x26,1,0,0);assert(sample_count&&!invalid);
  for(unsigned j=0;j<160*160;j++)if(visits[j]){
   assert(samples[j].textured&&samples[j].semi==stp&&samples[j].texel==(uint16_t)(0x4210|(stp?0x8000:0)));
   assert(samples[j].r==128&&samples[j].g==96&&samples[j].b==64); /* resolved modulation exactly once */
  }
 }
 fresh(2,0,1);triangle(p,0x26,1,0,0);assert(!sample_count&&!unknown_pixels); /* transparent texel */
}
static void repeated_owned_presentation(void){
 static uint16_t zero[1024*512*16],native[1024*512];
 const Corner p[]={{4,4,2},{28,4,4},{4,28,8}};
 for(int scale=1;scale<=4;scale++)for(int page=0;page<=256;page+=256){
  fresh(scale,page,1);
  /* Deliberately smaller than the native silhouette: source suppression is
   * global, while the alternate coverage callback remains ROI-bounded. */
  a2_mesh_live_x0=10*scale;a2_mesh_live_x1=15*scale;
  a2_mesh_live_y0=(page+10)*scale;a2_mesh_live_y1=(page+15)*scale;
  triangle(p,0x20,0,1,0);
  assert(claims==1&&consumed==1&&sample_count&&!invalid);
  assert(!memcmp(SHADOW,zero,(size_t)IR_W*IR_H*2));
  assert(GPU_VRAM[(page+8)*1024+8]!=0);memcpy(native,GPU_VRAM,sizeof native);
  unsigned first_samples=sample_count;gpu_scene_submit_complete();assert(!a2_mesh_live_active);
  for(unsigned j=0;j<owned_count;j++)gpu_gp0_at(owned_words[j],owned_address+j*4);
  assert(claims==2&&consumed==2&&sample_count==2*first_samples&&!invalid);
  assert(!memcmp(SHADOW,zero,(size_t)IR_W*IR_H*2)&&!memcmp(native,GPU_VRAM,sizeof native));
 }
}
static void selected_transfer_routes(void){
 for(int scale=1;scale<=4;scale++)for(int page=0;page<=256;page+=256){
  fresh(scale,page,1);a2_mesh_live_start(psx_frame_no,scale,page,SHADOW,IR_W,1);gpu_scene_submit_complete();
  for(int oy=0;oy<scale;oy++)for(int ox=0;ox<scale;ox++){
   int x=8*scale+ox,y=(page+8)*scale+oy;
   *shadow_px(x,y)=0x1111;*shadow_px(x+scale,y)=0x2222;
   alternate[(8*scale+oy)*160+x]=(uint16_t)(0x5000+oy*scale+ox);
  }
  GPU_VRAM[(page+8)*1024+8]=0x1111;GPU_VRAM[(page+8)*1024+9]=0x2222;
  /* Forward overlap must read each newly selected destination, preserving
   * fine detail; the game still reads/copies its own native VRAM values. */
  gpu_gp0(0x80000000);gpu_gp0(xy(8,page+8));gpu_gp0(xy(9,page+8));gpu_gp0(xy(2,1));
  assert(!invalid&&!a2_mesh_live_active&&transfer_reads&&selected_stores);
  assert(GPU_VRAM[(page+8)*1024+9]==0x1111&&GPU_VRAM[(page+8)*1024+10]==0x1111);
  for(int oy=0;oy<scale;oy++)for(int ox=0;ox<scale;ox++)for(int block=9;block<=10;block++){
   uint16_t expected=(uint16_t)(0x5000+oy*scale+ox);int x=block*scale+ox,y=(page+8)*scale+oy;
   assert(*shadow_px(x,y)==expected&&alternate[(8*scale+oy)*160+x]==expected);
  }
  /* The selected source must also survive a copy outside the mesh ROI. */
  gpu_gp0(0x80000000);gpu_gp0(xy(8,page+8));gpu_gp0(xy(80,page+8));gpu_gp0(xy(1,1));
  for(int oy=0;oy<scale;oy++)for(int ox=0;ox<scale;ox++)
   assert(*shadow_px(80*scale+ox,(page+8)*scale+oy)==(uint16_t)(0x5000+oy*scale+ox));
  /* Actual A0 payload, including zero and an odd final halfword, crosses a
   * publication boundary without another ordinary primitive activation. */
  gpu_gp0(0xa0000000);gpu_gp0(xy(8,page+8));gpu_gp0(xy(3,1));gpu_gp0(0x22220000);gpu_vblank();gpu_gp0(0xdead3333);
  const uint16_t uploaded[]={0,0x2222,0x3333};
  for(int block=0;block<3;block++){
   assert(GPU_VRAM[(page+8)*1024+8+block]==uploaded[block]);
   for(int oy=0;oy<scale;oy++)for(int ox=0;ox<scale;ox++){
    int x=(8+block)*scale+ox,y=(page+8)*scale+oy;
    assert(*shadow_px(x,y)==uploaded[block]&&alternate[(8*scale+oy)*160+x]==uploaded[block]);
   }
  }
  assert(!invalid&&!invalidations&&!a2_mesh_live_active);
  /* Wrapped source overlaps the first destination after X wraps. */
  for(int oy=0;oy<scale;oy++)for(int ox=0;ox<scale;ox++){
   *shadow_px(1023*scale+ox,(page+8)*scale+oy)=0x4567;
   alternate[(8*scale+oy)*160+ox]=0x7654;
  }
  gpu_gp0(0x80000000);gpu_gp0(xy(1023,page+8));gpu_gp0(xy(0,page+8));gpu_gp0(xy(2,1));
  for(int oy=0;oy<scale;oy++)for(int x=0;x<2*scale;x++)
   assert(*shadow_px(x,(page+8)*scale+oy)==0x4567&&alternate[(8*scale+oy)*160+x]==0x4567);
 }
 for(int scale=1;scale<=4;scale++){
  fresh(scale,0,1);a2_mesh_live_start(psx_frame_no,scale,0,SHADOW,IR_W,1);gpu_scene_submit_complete();
  for(int oy=0;oy<scale;oy++)for(int ox=0;ox<scale;ox++)*shadow_px(8*scale+ox,511*scale+oy)=0x3456;
  gpu_gp0(0x80000000);gpu_gp0(xy(8,511));gpu_gp0(xy(8,0));gpu_gp0(xy(1,2));
  for(int y=0;y<2*scale;y++)for(int ox=0;ox<scale;ox++)
   assert(*shadow_px(8*scale+ox,y)==0x3456&&alternate[y*160+8*scale+ox]==0x3456);
 }
}
static void owned_hd_suppression(void){
 for(unsigned site=0;site<3;site++)for(unsigned outside=0;outside<2;outside++){
  fresh(2,0,1);a2_mesh_live_start(psx_frame_no,2,0,SHADOW,IR_W,1);mesh_pixel_kind=A2_COMPOSITE_OWNED;
  int x=outside?100:16,y=16;uint16_t before=0x1234;
  *shadow_px(x,y)=before;alternate[y*160+x]=0x5678;
  if(site==0)put_font_coverage(x,y,128,128,128,1,0xffff,192);
  if(site==1){portrait_fixture=1;portrait_value=(A2HDPortraitSample){255,0,0,192};assert(put_hd_portrait(x,y,128,128,128,0,0));}
  if(site==2){hd_plate_count=1;hd_sample_fixture=1;assert(put_hd_ui(x,y,128,128,128,1,0,0));}
  assert(*shadow_px(x,y)==before&&alternate[y*160+x]==0x5678&&!invalid);
 }
}
static void narrow_scissor_ordered(void){
 const Corner p[]={{4,4,2},{28,4,4},{4,28,8}};
 for(int scale=1;scale<=4;scale++)for(int page=0;page<=256;page+=256){
  fresh(scale,page,1);a2_mesh_live_start(psx_frame_no,scale,page,SHADOW,IR_W,1);gpu_scene_submit_complete();
  gpu_gp0(0xe3000000u|8u|((unsigned)(page+8)<<10));
  gpu_gp0(0xe4000000u|10u|((unsigned)(page+10)<<10));
  triangle(p,0x20,0,0,0);assert(sample_count&&!invalidations&&!invalid);
  for(unsigned i=0;i<160*160;i++)if(visits[i]){
   unsigned x=i%160,y=i/160;assert(x>=8u*scale&&x<11u*scale&&y>=8u*scale&&y<11u*scale);
   assert(samples[i].kind==A2_COMPOSITE_ORDERED);
  }
 }
}
static void selected_framebuffer_texture(void){
 for(int scale=1;scale<=4;scale++)for(int page=0;page<=256;page+=256)for(unsigned transparent=0;transparent<2;transparent++)for(unsigned mode=2;mode<=3;mode++){
  fresh(scale,page,1);a2_mesh_live_start(psx_frame_no,scale,page,SHADOW,IR_W,1);gpu_scene_submit_complete();
  const uint16_t old=transparent?0:31,modern=31<<10;
  gpu_gp0(0xe1000000u|(mode<<7)|(page?16u:0));
  cur_tpage=g.texpage; /* Direct sampler invocation uses the current primitive page. */
  for(int y=8;y<10;y++)for(int x=8;x<10;x++){
   seed_texel(x,page+y,old);
   for(int oy=0;oy<scale;oy++)for(int ox=0;ox<scale;ox++)alternate[(y*scale+oy)*160+x*scale+ox]=modern;
  }
  assert(sample_tex(8,8)==old);
  assert(sample_tex_fine(8*256,8*256)==modern);
  assert(sample_tex_fine(8*256+128,8*256+128)==modern);
  /* A retained mesh page can change while submission is inactive. Even a
   * populated native cache must bypass its old texels for display feedback. */
  assert(a2_mesh_live_enabled&&!a2_mesh_live_active);
  FineTexCache cache={0};FineTexCell *cell=&cache.cells[(8+17*8)&63];
  cell->key=8|(8<<8);cell->kind=2;
  for(unsigned i=0;i<4;i++)cell->texels[i]=old;
  assert(sample_tex_cached(8*256,8*256,&cache)==modern);
  for(int y=8;y<10;y++)for(int x=8;x<10;x++)
   for(int oy=0;oy<scale;oy++)for(int ox=0;ox<scale;ox++)alternate[(y*scale+oy)*160+x*scale+ox]=31<<5;
  assert(sample_tex_cached(8*256,8*256,&cache)==(31<<5));
  for(int y=8;y<10;y++)for(int x=8;x<10;x++)
   for(int oy=0;oy<scale;oy++)for(int ox=0;ox<scale;ox++)alternate[(y*scale+oy)*160+x*scale+ox]=modern;
  /* Default nearest sampling must use the same selected framebuffer while
   * the native GP0 pass continues to sample the unmodified old texel. */
  seed_texel(20,page+20,31<<5);
  gpu_gp0(0x65808080);gpu_gp0(xy(20,20));gpu_gp0(8u|(8u<<8));gpu_gp0(xy(1,1));
  assert(GPU_VRAM[(page+20)*1024+20]==(transparent?(31<<5):old));
  for(int oy=0;oy<scale;oy++)for(int ox=0;ox<scale;ox++){
   int x=20*scale+ox,y=(page+20)*scale+oy;
   assert(*shadow_px(x,y)==modern&&alternate[(20*scale+oy)*160+x]==modern);
  }
 }
}
static void cached_native_footprint_bookkeeping(void){
 fresh(2,0,0);fine_uv_reset();
 for(unsigned i=0;i<1024*512;i++)GPU_VRAM[i]=i%7?(uint16_t)(i*73u+(i>>7)):0;
 const unsigned windows[]={0,0x731c,0xfffff,0x54321,0x7c01f,0x10842};
 const unsigned coords[]={0,7,8,127,128,254,255};
 unsigned checks=0;
 for(unsigned mode=0;mode<4;mode++)for(unsigned page=0;page<=31;page+=31)
  for(unsigned w=0;w<6;w++)for(unsigned ui=0;ui<7;ui++)for(unsigned vi=0;vi<7;vi++){
   unsigned u=coords[ui],v=coords[vi];uint16_t expected[4];
   cur_tpage=page|(mode<<7);cur_clut=page?0x7fff:0;g.texwin=windows[w];
   mesh_sample_direct=7;mesh_sample_x=-99;mesh_sample_y=-77;
   expected[0]=sample_tex((int)u,(int)v);expected[1]=sample_tex((int)u+1,(int)v);
   expected[2]=sample_tex((int)u,(int)v+1);expected[3]=sample_tex((int)u+1,(int)v+1);
   int direct=mesh_sample_direct,x=mesh_sample_x,y=mesh_sample_y;
   FineTexCache cache;for(unsigned i=0;i<64;i++)cache.cells[i].key=UINT32_MAX;
   mesh_sample_direct=7;mesh_sample_x=-99;mesh_sample_y=-77;
   (void)sample_tex_cached((int)u*256+37,(int)v*256+213,&cache);
   FineTexCell *cell=&cache.cells[(u+17*v)&63];
   assert(cell->key==(u|(v<<8))&&!memcmp(cell->texels,expected,sizeof expected));
   assert(mesh_sample_direct==direct&&mesh_sample_x==x&&mesh_sample_y==y);
   mesh_sample_direct=9;mesh_sample_x=-88;mesh_sample_y=-66;
   (void)sample_tex_cached((int)u*256+213,(int)v*256+37,&cache);
   assert(mesh_sample_direct==9&&mesh_sample_x==-88&&mesh_sample_y==-66);
   checks++;
  }
 assert(checks==2352);printf("Cached native footprint: %u window/wrap/bookkeeping and hit cases pass\n",checks);
}
static void full_page_rectangle_clear(void){
 for(int scale=1;scale<=4;scale++)for(int page=0;page<=256;page+=256){
  fresh(scale,page,1);
  gpu_gp0(0xe3000000u|((unsigned)page<<10));
  gpu_gp0(0xe4000000u|319u|((unsigned)(page+215)<<10));
  unsigned before=clears;
  gpu_gp0(0x60483020);gpu_gp0(xy(0,0));gpu_gp0(xy(320,216));
  assert(clears==before+1&&starts==0);
  assert(GPU_VRAM[page*1024]==(4u|(6u<<5)|(9u<<10)));
  /* A fade, cropped scissor or partial-size rectangle cannot establish a
   * new clean page. These must retain ordinary ordered composition. */
  for(unsigned mode=0;mode<4;mode++){
   fresh(scale,page,1);
   gpu_gp0(0xe3000000u|(mode==1?1u:0u)|((unsigned)page<<10));
   gpu_gp0(0xe4000000u|319u|((unsigned)(page+(mode==3?99:215))<<10));
   before=clears;gpu_gp0(mode==0?0x62000000:0x60000000);
   gpu_gp0(xy(0,0));gpu_gp0(xy(mode==2?319:320,216));
   assert(clears==before&&starts==1);
  }
 }
}
int main(void){
 setenv("A2_WORLD_PERSPECTIVE","0",1);
 repeated_owned_presentation();
 selected_transfer_routes();narrow_scissor_ordered();owned_hd_suppression();
 hud_font_alternate();hd_background_matrix();rectangle_alternate();direct_role_guards();packet_provider_routes();world_billboard_raster_routes();owned_coverage_diagnostic();
 for(int s=2;s<=4;s++)for(int page=0;page<=256;page+=256)for(int reverse=0;reverse<2;reverse++)for(int clip=0;clip<2;clip++)depth_oracle(s,page,reverse,clip);
 for(int s=2;s<=4;s++)for(int page=0;page<=256;page+=256)for(int reverse=0;reverse<2;reverse++)for(int half=0;half<2;half++)for(int clip=0;clip<2;clip++)for(int camera=0;camera<2;camera++)fallback_quad_oracle(s,page,reverse,half,clip,camera);
 fallback_quad_rejection();
 native_equality();owned_prefix_and_blend();invalidation_routes();fill_wrap_invalidation();inactive_hd_write_guard();
 selected_framebuffer_texture();
 cached_native_footprint_bookkeeping();
 full_page_rectangle_clear();
 puts("GPU native mesh: native VRAM equality, repeated source suppression IR1–4, selected transfers, ordered input, typed depth, HD coverage and lifecycle pass");
 return 0;
}
