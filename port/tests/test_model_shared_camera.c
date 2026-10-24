/* Independent visible-color expectations through actual GP0. The fixture
 * supplies sealed owner identities, whose producer boundary has its own tests. */
#define A2_MODEL_DEPTH_FIXTURE_ONLY 1
#include "test_model_depth.c"
static uint16_t reference_native[1024*512];
static void setup_shared(int scale,int page,int event) {
 fixture_distinct_owners=fixture_missing_owner=0;begin_model_test();fresh(scale,page,0);
 world_camera_configure(1);gpu_model_depth_configure(1);
 fixture_source_family=event?A2_ACTOR_EVENT00:A2_ACTOR_GAME00;
 model_producer_pc=event?0x80013424u:0x8001338cu;g.day2=page+(event?171:215);
 memset(&fixture_owner,0,sizeof fixture_owner);
 fixture_owner.handle=77;fixture_owner.instance.source_family=fixture_source_family;
 fixture_owner.camera_origin_q12[0]=12345;fixture_owner.camera_origin_q12[1]=-23456;fixture_owner.camera_origin_q12[2]=34567;
 fixture_owner.camera_rotation_q12[0]=fixture_owner.camera_rotation_q12[4]=fixture_owner.camera_rotation_q12[8]=4096;
 fixture_owner.projection_h=121;fixture_owner.projection_ofx=160<<16;fixture_owner.projection_ofy=106<<16;
 fixture_other_owner=fixture_owner;fixture_other_owner.handle=88;fixture_distinct_owners=1;
 fixture_other_owner.instance.renderer_root_q12[0]=4096;
 fixture_third_owner=fixture_owner;fixture_third_owner.handle=99;fixture_third_owner.instance.renderer_root_q12[0]=-4096;
 if(SHADOW_RGB)for(int y=page*IR;y<(page+40)*IR;y++)for(int x=0;x<40*IR;x++)SHADOW_RGB[(size_t)y*IR_W+x]=0xff000000u;
}
static void expect_color(int page,int x,int y,uint16_t fine,uint32_t rgb) {
 size_t at=(size_t)((page+y)*IR)*IR_W+x*IR;
 assert(SHADOW[at]==fine);if(SHADOW_RGB)assert(SHADOW_RGB[at]==rgb);
}
static void ordered_pair(int reverse,int slope) {
 static const double depths[4]={2,8,2,8};quad_shape=slope;
 for(int i=0;i<2;i++) {
  int far=i^reverse;corner_depths=!far&&slope?depths:NULL;
  /* Deliberately identical face IDs in independent owners. */
  model_triangle(far?88:77,17,0,far?4:2,far?0xff0000:0x0000ff,0,0,0);
 }
 corner_depths=NULL;
}
#ifndef A2_SHARED_CAMERA_FIXTURE_ONLY
int main(void) {
 setenv("A2_COLOR_PRECISION","1",1);setenv("A2_IRSCALE","4",1);gpu_ir();unsigned cases=0;
 for(int scale=2;scale<=4;scale++)for(int page=0;page<=256;page+=256)
 for(int event=0;event<2;event++)for(int rgb=0;rgb<2;rgb++)for(int reverse=0;reverse<2;reverse++)for(int slope=0;slope<2;slope++) {
  for(int enabled=0;enabled<2;enabled++) {
   setup_shared(scale,page,event);uint32_t *plane=SHADOW_RGB;if(!rgb)SHADOW_RGB=NULL;
   gpu_model_depth_configure(enabled);ordered_pair(reverse,slope);
   if(!enabled)memcpy(reference_native,GPU_VRAM,sizeof GPU_VRAM);
   else {assert(!memcmp(reference_native,GPU_VRAM,sizeof GPU_VRAM));expect_color(page,10,10,31,0xffff0000u);if(slope)expect_color(page,22,10,31u<<10,0xff0000ffu);}
   SHADOW_RGB=plane;
  }
  cases++;
 }
 /* Every copied camera component is required to match. */
 for(int fault=0;fault<16;fault++) {
  setup_shared(4,0,0);
  if(fault<3)fixture_other_owner.camera_origin_q12[fault]++;
  else if(fault<12)fixture_other_owner.camera_rotation_q12[fault-3]++;
  else if(fault==12)fixture_other_owner.projection_h++;
  else if(fault==13)fixture_other_owner.projection_ofx++;
  else if(fault==14)fixture_other_owner.projection_ofy++;
  else fixture_other_owner.instance.source_family=A2_ACTOR_EVENT00;
  ordered_pair(0,0);expect_color(0,10,10,31u<<10,0xff0000ffu);cases++;
 }
 /* A previously matching pair cannot stay cached after the prior owner
  * becomes unavailable between primitives. Its next write is ordered. */
 setup_shared(4,0,0);ordered_pair(0,0);expect_color(0,10,10,31,0xffff0000u);
 fixture_missing_owner=77;model_triangle(88,18,0,4,0xff0000,0,0,0);expect_color(0,10,10,31u<<10,0xff0000ffu);cases++;
 /* Equal planes preserve material order even with equal face numbers. */
 setup_shared(4,256,1);model_triangle(77,17,0,2,0x0000ff,0,0,0);model_triangle(88,17,0,2,0xff0000,0,0,0);expect_color(256,10,10,31u<<10,0xff0000ffu);cases++;
 for(int page=0;page<=256;page+=256)for(int event=0;event<2;event++)for(int kind=0;kind<4;kind++) {
  setup_shared(4,page,event);model_triangle(77,1,0,2,0x0000ff,0,0,0);
  uint16_t texel=kind==0?0:kind==1?0x8000:kind==2?0x03e0:0x8000;
  model_triangle(88,1,0,kind==3?1:4,0x808080,1,1,texel);
  if(kind==3)expect_color(page,10,10,0x800f,0xff7f0000u);
  else expect_color(page,10,10,31,0xffff0000u);
  model_triangle(77,2,0,8,0xff0000,0,0,0);
  expect_color(page,10,10,kind==3?31u<<10:31,kind==3?0xff0000ffu:0xffff0000u);cases++;
 }
 /* A third model covers two different prior owners on every row. Only
  * one shares its camera; cache churn must not confuse the two regions. */
 setup_shared(4,0,0);quad_shape=1;
 model_triangle(77,1,0,2,0x0000ff,0,0,0);
 fixture_other_owner.camera_origin_q12[0]++;shape_offset=24;
 model_triangle(88,1,0,2,0x00ff00,0,0,0);shape_offset=12;
 model_triangle(99,1,0,4,0xff0000,0,0,0);
 for(int y=8;y<24;y++)for(int x=18;x<24;x++)expect_color(0,x,y,31,0xffff0000u);
 for(int y=8;y<24;y++)for(int x=30;x<36;x++)expect_color(0,x,y,31u<<10,0xff0000ffu);
 cases++;
 /* Different-camera STP is ordered, even if its numeric Z lies behind
  * the old sample; that blend retires covered depth for the next draw. */
 for(int front=0;front<2;front++) {
  setup_shared(4,0,0);fixture_other_owner.camera_origin_q12[0]++;
  model_triangle(77,1,0,2,0x0000ff,0,0,0);
  model_triangle(88,1,0,front?1:4,0x808080,1,1,0x8000);expect_color(0,10,10,0x800f,0xff7f0000u);
  model_triangle(77,2,0,8,0xff0000,0,0,0);expect_color(0,10,10,31u<<10,0xff0000ffu);cases++;
 }
 fixture_distinct_owners=fixture_missing_owner=0;
 printf("PASS: %u shared-camera GP0 cases, sameface IDs, both orders/crossing planes, all camera fields, owner invalidation, STP/holes, IR2-4/pages/GAME/EVENT/RGB\n",cases);return 0;
}

#endif
