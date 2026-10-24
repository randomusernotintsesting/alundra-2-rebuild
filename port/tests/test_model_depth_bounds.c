/* Actual GP0: bounded depth work must preserve visible color and future
 * occlusion, including unknown writes crossing live model samples. */
#include <stdint.h>
static uint64_t depth_bounds_sample_calls;
static int depth_bounds_reference;
#define A2_MODEL_DEPTH_BOUNDS_TEST 1
#define A2_MODEL_DEPTH_FIXTURE_ONLY 1
#include "test_model_depth.c"
static uint16_t ref_native[1024*512],ref_fine[512*256];
static uint32_t ref_rgb[512*256];
static void setup_bounds(int scale,int page) {
 begin_model_test();fresh(scale,page,0);g.dax2=319;g.day2=page+215;
 world_camera_configure(1);gpu_model_depth_configure(1);
 /* Base fixture predates RGB888 and only clears555. Set the compared RGB
  * background independently for every replay, including untouched pixels. */
 for(int y=page*scale;y<(page+64)*scale;y++)for(int x=0;x<128*scale;x++)
  SHADOW_RGB[(size_t)y*IR_W+x]=0xff000000u;
}
static void snapshot_bounds(int scale,int page,int compare) {
 if(compare)assert(!memcmp(ref_native,GPU_VRAM,sizeof GPU_VRAM));
 else memcpy(ref_native,GPU_VRAM,sizeof GPU_VRAM);
 for(int y=0;y<64*scale;y++)for(int x=0;x<128*scale;x++) {
  size_t k=(size_t)y*512+x,n=(size_t)(page*scale+y)*IR_W+x;
  if(compare){assert(ref_fine[k]==SHADOW[n]);assert(ref_rgb[k]==SHADOW_RGB[n]);}
  else {ref_fine[k]=SHADOW[n];ref_rgb[k]=SHADOW_RGB[n];}
 }
}
static void outside_rows(void) {
 for(int scale=2;scale<=4;scale++)for(int page=0;page<=256;page+=256)
 for(int legacy=0;legacy<2;legacy++)for(int quad=0;quad<2;quad++) {
  for(int pass=0;pass<2;pass++) {
   depth_bounds_reference=!pass;setup_bounds(scale,page);quad_shape=quad;
   model_triangle(77,1,0,2,0x0000ff,0,0,0);
   assert(*shadow_px(10*scale,(page+10)*scale)==31);
   shape_offset=64;unowned=1;stale_corner=legacy;depth_bounds_sample_calls=0;
   model_triangle(77,2,0,3,0x00ff00,0,0,0);
   uint64_t work=depth_bounds_sample_calls;
   assert(*shadow_px(10*scale,(page+10)*scale)==31);
   assert(*shadow_px(74*scale,(page+10)*scale)==(31u<<5));
   snapshot_bounds(scale,page,pass);
   if(!pass)assert(work>0);
   else if(work){fprintf(stderr,"outside model bounds: %llu unnecessary depth calls, expected0; IR%d page%d legacy%d quad%d\n",(unsigned long long)work,scale,page,legacy,quad);exit(1);}
  }
 }
}
static void crossing_retirement(void) {
 for(int scale=2;scale<=4;scale++)for(int page=0;page<=256;page+=256)
 for(int legacy=0;legacy<2;legacy++)for(int kind=0;kind<4;kind++) {
  for(int pass=0;pass<2;pass++) {
   depth_bounds_reference=!pass;setup_bounds(scale,page);
   model_triangle(77,1,0,2,0x0000ff,0,0,0);
   shape_offset=20;unowned=1;stale_corner=legacy;
   model_triangle(77,3,0,1,0x808080,1,1,kind==0?0:kind==1?0x83e0:kind==2?0x03e0:0x8000);
   unowned=shape_offset=stale_corner=0;
   model_triangle(77,2,0,4,0xff0000,0,0,0);
   assert(*shadow_px(10*scale,(page+10)*scale)==31);
   assert(*shadow_px(25*scale,(page+6)*scale)==(kind?31u<<10:31));
   snapshot_bounds(scale,page,pass);
  }
 }
}
static void retired_epoch(void) {
 for(int scale=2;scale<=4;scale++)for(int page=0;page<=256;page+=256)
 for(int pass=0;pass<2;pass++) {
  depth_bounds_reference=!pass;setup_bounds(scale,page);
  model_triangle(77,1,0,2,0x0000ff,0,0,0);gpu_model_depth_barrier();
  shape_offset=96;model_triangle(77,2,0,2,0x0000ff,0,0,0);
  shape_offset=0;unowned=1;depth_bounds_sample_calls=0;
  model_triangle(77,3,0,3,0x00ff00,0,0,0);
  if(pass)assert(depth_bounds_sample_calls==0);
  unowned=0;model_triangle(77,4,0,4,0xff0000,0,0,0);
  assert(*shadow_px(10*scale,(page+10)*scale)==(31u<<10));
  assert(*shadow_px(106*scale,(page+10)*scale)==31);
  snapshot_bounds(scale,page,pass);
 }
}
int main(void) {
 setenv("A2_COLOR_PRECISION","1",1);setenv("A2_IRSCALE","4",1);gpu_ir();
 outside_rows();crossing_retirement();retired_epoch();
 puts("model_depth_bounds: PASS24 outside-row,48 crossing retirement,6 epoch-reuse paired GP0 cases; IR2/3/4 both pages exact/legacy, native/fine/RGB, zero outside depth-call budget");
 return 0;
}
