/* Real cinema and normal GPU code compiled together. The retained selected
 * main image is a read-only oracle; no Metal, game or source assets run. */
#define A2_CINEMA_EXPANSION 1
#define A2_NATIVE_MESH 1
#define A2_NATIVE_ACTOR_PACKETS 1
#define A2_WORLD_PRECISION 1
#define A2_HUD_PRESENT 1
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/gpu.c"
#include "../src/frame_compose.c"

uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
uint32_t psx_frame_no=20,gpu_flips,a2_ramwatch;
void psx_vblank_tick(void){}
uint32_t psx_mmio_read(uint32_t p,int n){(void)p;(void)n;return 0;}
void psx_mmio_write(uint32_t p,uint32_t v,int n){(void)p;(void)v;(void)n;abort();}
void a2_ramwatch_hit(uint32_t p,uint32_t v,int n){(void)p;(void)v;(void)n;}
int a2_modelcap_active(void){return 0;}
FILE *a2_modelcap_file(void){return NULL;}
int a2_wide(void){return 1;}
int a2_world_shadow_geometry(const world_precision_vertex *v,unsigned n,int wide,uint32_t address,
                            const uint32_t *words,unsigned count,A2WorldShadowGeometry *out) {
 (void)v;(void)n;(void)wide;(void)address;(void)words;(void)count;(void)out;return 0;
}
void a2_hud_present_reset(void){}
uint64_t a2_hud_present_packet_token(uint32_t a,uint32_t w){(void)a;(void)w;return 0;}
int a2_hud_present_consume(uint32_t a,uint64_t t,const uint32_t *w,unsigned n,int *anchor){(void)a;(void)t;(void)w;(void)n;(void)anchor;return 0;}
int a2_native_actor_packets_enabled;
uint32_t a2_native_actor_packets_watch_begin=UINT32_MAX,a2_native_actor_packets_watch_end;
void a2_native_actor_packets_invalidate(uint32_t a,size_t n){(void)a;(void)n;}
uint64_t a2_native_actor_packets_token(uint32_t a,uint32_t w){(void)a;(void)w;return 0;}
int a2_native_actor_packets_consume(uint32_t a,uint64_t t,const uint32_t *w,unsigned n,const A2ActorPacket **out){(void)a;(void)t;(void)w;(void)n;*out=NULL;return 0;}
const A2ActorPacketOwner *a2_native_actor_packets_owner(uint64_t h){(void)h;return NULL;}
size_t a2_native_actor_packets_owners_latest(const A2ActorPacketOwner **out,size_t n){(void)out;(void)n;return 0;}
size_t a2_native_actor_packets_owner_packets(uint64_t h,const A2ActorPacket **out,size_t n){(void)h;(void)out;(void)n;return 0;}

int a2_mesh_live_enabled,a2_mesh_live_active,a2_mesh_live_writes_watched,a2_mesh_live_failed;
int a2_mesh_live_x0,a2_mesh_live_y0,a2_mesh_live_x1,a2_mesh_live_y1;
static unsigned live_pixels,live_stores,live_reads;
static uint16_t selected_row[4096];
void a2_mesh_live_reset(void){a2_mesh_live_active=0;}
void a2_mesh_live_clear(uint32_t f,int s,int x,int y,int w,int h){(void)f;(void)s;(void)x;(void)y;(void)w;(void)h;}
void a2_mesh_live_start(uint32_t f,int s,int p,const uint16_t *v,size_t stride,int wide){(void)f;(void)s;(void)p;(void)v;(void)stride;(void)wide;}
int a2_mesh_live_owns(uint64_t h){return a2_mesh_live_enabled&&h==77;}
int a2_mesh_live_claim(uint64_t h){return a2_mesh_live_owns(h);}
int a2_mesh_live_claim_part(uint64_t h,unsigned part){(void)part;return a2_mesh_live_claim(h);}
void a2_mesh_live_start_view(uint32_t f,int s,int p,const uint16_t *v,size_t stride,int wide,int height){assert(height==172||height==216);a2_mesh_live_start(f,s,p,v,stride,wide);}
void a2_mesh_live_pixel(int x,int y,A2CompositePixel p){(void)x;(void)y;(void)p;++live_pixels;}
uint16_t *a2_mesh_live_destination(int x,int y,A2CompositeKind k,float z){(void)x;(void)y;(void)k;(void)z;abort();}
void a2_mesh_live_invalidate_rect(int x,int y,int w,int h){(void)x;(void)y;(void)w;(void)h;a2_mesh_live_failed=1;}
uint16_t a2_mesh_live_read(int x,int y,uint16_t original){(void)x;(void)y;++live_reads;return a2_mesh_live_enabled?selected_row[0]:original;}
void a2_mesh_live_store(int x,int y,uint16_t value){(void)x;(void)y;(void)value;++live_stores;}
void a2_mesh_live_finalize(void){}
void a2_mesh_live_finalize_at(uint32_t f,const char *s){(void)f;(void)s;}
const uint16_t *a2_mesh_live_row(int y,const uint16_t *original,size_t width){(void)y;assert(width<=4096);return a2_mesh_live_enabled?selected_row:original;}

static uint32_t xy(int x,int y){return (uint16_t)x|((uint32_t)(uint16_t)y<<16);}
static void picture(int page){
 gpu_gp0(0xe5000000u|((unsigned)page<<11));gpu_gp0(0xe3000000u|((unsigned)page<<10));
 gpu_gp0(0xe4000000u|319|((unsigned)(page+171)<<10));
}
static void seal(int page){gpu_gp0(0xe4000000u|319|((unsigned)(page+215)<<10));}
static void setup(int scale,int page,int enabled){
 a2_mesh_live_enabled=0;gpu_set_ir(scale);gpu_gp1(0);
 memset(PSX_RAM,0,sizeof PSX_RAM);PSX_RAM[0x811d8]=5;PSX_RAM[0x79e9c]=1;
 memset(GPU_VRAM,0,sizeof GPU_VRAM);memset(SHADOW,0,(size_t)IR_W*IR_H*2);
 gpu_set_filter(0);gpu_set_cinema_expansion(1);picture(page);
 a2_mesh_live_enabled=enabled;a2_mesh_live_active=enabled;a2_mesh_live_writes_watched=enabled;a2_mesh_live_failed=0;
 /* A deliberately wide recording domain catches any accidental coordinate
  * derivation from the separately allocated cinema pointer. */
 a2_mesh_live_x0=a2_mesh_live_y0=INT_MIN;a2_mesh_live_x1=a2_mesh_live_y1=INT_MAX;
 live_pixels=live_stores=live_reads=0;for(unsigned i=0;i<4096;i++)selected_row[i]=31<<10;
 mesh_pixel_kind=A2_COMPOSITE_WORLD;mesh_depth_valid=1;
 mesh_depth_plane[0]=mesh_depth_plane[1]=0;mesh_depth_plane[2]=.25;
}
static void external_geometry(int page){
 Vtx a={0,page-30,248,0,0,8,8},b={320,page-30,248,0,0,8,8},c={0,page+205,248,0,0,8,8};
 cinema_triangle(a,b,c,0,0,0,NULL);
 cinema_rect(0,page,320,216,0,0,64,96,128,1,0);
 a=(Vtx){0,page+180,0,248,0,0,0};b=(Vtx){319,page+180,0,248,0,0,0};cinema_line(a,b,0);
}
static void isolated_external_pixels(void){
 static uint16_t baseline[320*44*16],zero[1024*512*16];
 for(int scale=1;scale<=4;scale++)for(int page=0;page<=256;page+=256)for(int enabled=0;enabled<2;enabled++){
  setup(scale,page,enabled);external_geometry(page);
  assert(!live_pixels&&!live_stores&&!a2_mesh_live_failed&&a2_mesh_live_active==enabled);
  assert(!memcmp(SHADOW,zero,(size_t)IR_W*IR_H*2)&&!memcmp(GPU_VRAM,zero,sizeof GPU_VRAM));
  if(!enabled)memcpy(baseline,cinema_extra[page/256],(size_t)320*44*scale*scale*2);
  else assert(!memcmp(baseline,cinema_extra[page/256],(size_t)320*44*scale*scale*2));
  seal(page);assert(gpu_cinema_expansion_ready(page));
 }
}
static void owned_selects_centered_cinema(void){
 for(int scale=1;scale<=4;scale++)for(int page=0;page<=256;page+=256)for(unsigned site=0;site<3;site++){
  setup(scale,page,1);mesh_pixel_kind=A2_COMPOSITE_OWNED;mesh_pixel_owner=77;
  Vtx a={0,page-30,248,0,0,0,0},b={320,page-30,248,0,0,0,0},c={0,page+205,248,0,0,0,0};
  if(site==0)cinema_triangle(a,b,c,0,0,0,NULL);
  if(site==1){a.y=b.y=page+180;cinema_line(a,b,0);}
  if(site==2)cinema_rect(0,page,320,216,0,0,248,0,0,0,0);
  seal(page);assert(!gpu_cinema_expansion_ready(page)&&!cinema_ready[page/256]);
  assert(!live_pixels&&!live_stores&&!a2_mesh_live_failed&&a2_mesh_live_active);
  assert(gpu_display_px(10*scale,(page+10)*scale)==(31<<10));
  A2CinemaRaster raster={0,page,320,216,0,12,320,240,1,5};A2CinemaLayout layout={0,172,34,174,32,207};
  int width=320*scale;uint32_t *out=malloc((size_t)width*240*scale*4);assert(out);
  assert(!a2_compose_cinema_expanded(out,width,scale,&raster,&layout));
  a2_compose_cinema(out,width,scale,&raster,&layout);
  assert(out[34*scale*width]==0xff0000f8u&&out[0]==0xff000000u);free(out);
  /* A fresh ordinary event generation can expand normally again. */
  picture(page);mesh_pixel_kind=A2_COMPOSITE_ORDERED;external_geometry(page);seal(page);
  assert(gpu_cinema_expansion_ready(page));
 }
}
static void selected_external_texture(void){
 for(unsigned site=0;site<2;site++){
  setup(2,0,1);cur_tpage=2u<<7;GPU_VRAM[8*1024+8]=31;
  for(int y=16;y<18;y++)for(int x=16;x<18;x++)SHADOW[y*IR_W+x]=31;
  if(site==0)cinema_rect(0,172,1,1,8,8,128,128,128,0,1);
  else{Vtx a={0,170,128,128,128,8,8},b={10,170,128,128,128,8,8},c={0,180,128,128,128,8,8};cinema_triangle(a,b,c,0,1,0,NULL);}
  assert(live_reads&&!live_pixels&&!live_stores&&GPU_VRAM[8*1024+8]==31);
  assert(cinema_extra[0][22*2*320*2]==(31<<10));
 }
}
int main(void){
 isolated_external_pixels();owned_selects_centered_cinema();selected_external_texture();
 puts("PASS: cinema+mesh external pixels isolated, OWNED selects centered main image, event generations recover, nearest feedback uses selected texture");return 0;
}
