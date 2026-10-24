/* Shared-root meshes can be separately submitted animated pieces. Keep
 * their authored order, while retaining each owner's opaque self-depth. */
#define A2_SHARED_CAMERA_FIXTURE_ONLY 1
#include "test_model_shared_camera.c"
int main(void) {
 setenv("A2_COLOR_PRECISION","1",1);setenv("A2_IRSCALE","4",1);gpu_ir();unsigned cases=0;
 for(int scale=2;scale<=4;scale++)for(int page=0;page<=256;page+=256)
 for(int event=0;event<2;event++)for(int rgb=0;rgb<2;rgb++)for(int reverse=0;reverse<2;reverse++) {
  for(int enabled=0;enabled<2;enabled++) {
   setup_shared(scale,page,event);uint32_t *plane=SHADOW_RGB;if(!rgb)SHADOW_RGB=NULL;
   const int32_t root[3]={-1773568,8192000,-3268608};
   memcpy(fixture_owner.instance.renderer_root_q12,root,sizeof root);
   memcpy(fixture_other_owner.instance.renderer_root_q12,root,sizeof root);
   gpu_model_depth_configure(enabled);ordered_pair(reverse,0);
   if(!enabled)memcpy(reference_native,GPU_VRAM,sizeof GPU_VRAM);
   else {
    assert(!memcmp(reference_native,GPU_VRAM,sizeof GPU_VRAM));
    expect_color(page,10,10,reverse?31:31u<<10,reverse?0xffff0000u:0xff0000ffu);
   }
   SHADOW_RGB=plane;
  }
  cases++;
 }
 /* Exact equality is conservative. A one-Q12 difference is not inferred
  * attachment: exercise all axes, both signs, and cache invalidation. */
 for(int axis=0;axis<3;axis++)for(int sign=-1;sign<=1;sign+=2) {
  setup_shared(4,0,0);memcpy(fixture_other_owner.instance.renderer_root_q12,
    fixture_owner.instance.renderer_root_q12,sizeof fixture_owner.instance.renderer_root_q12);
  fixture_other_owner.instance.renderer_root_q12[axis]+=sign;
  ordered_pair(0,0);expect_color(0,10,10,31,0xffff0000u);
  fixture_other_owner.instance.renderer_root_q12[axis]-=sign;
  model_triangle(88,18,0,4,0xff0000,0,0,0);expect_color(0,10,10,31u<<10,0xff0000ffu);cases++;
 }
 /* A/B/A must replace ownership. Old hidden A depth cannot survive B's
  * opaque write; the newly visible A then protects against its own back face. */
 setup_shared(4,0,0);memcpy(fixture_other_owner.instance.renderer_root_q12,
   fixture_owner.instance.renderer_root_q12,sizeof fixture_owner.instance.renderer_root_q12);
 model_triangle(77,1,0,2,0x0000ff,0,0,0);
 model_triangle(88,1,0,4,0xff0000,0,0,0);expect_color(0,10,10,31u<<10,0xff0000ffu);
 model_triangle(77,2,0,8,0x00ff00,0,0,0);expect_color(0,10,10,31u<<5,0xff00ff00u);
 model_triangle(77,3,0,16,0xff0000,0,0,0);expect_color(0,10,10,31u<<5,0xff00ff00u);cases++;
 /* Shared-root STP blends remain ordered and retire prior foreign depth. */
 for(int front=0;front<2;front++) {
  setup_shared(4,256,1);memcpy(fixture_other_owner.instance.renderer_root_q12,
    fixture_owner.instance.renderer_root_q12,sizeof fixture_owner.instance.renderer_root_q12);
  model_triangle(77,1,0,2,0x0000ff,0,0,0);
  model_triangle(88,1,0,front?1:4,0x808080,1,1,0x8000);expect_color(256,10,10,0x800f,0xff7f0000u);
  model_triangle(77,2,0,8,0xff0000,0,0,0);expect_color(256,10,10,31u<<10,0xff0000ffu);cases++;
 }
 /* Contact layers preserve submission order among three objects too;
  * they are deliberately not an order-independent merged owner. */
 for(int third_first=0;third_first<2;third_first++) {
  setup_shared(4,0,0);memcpy(fixture_other_owner.instance.renderer_root_q12,
    fixture_owner.instance.renderer_root_q12,sizeof fixture_owner.instance.renderer_root_q12);
  model_triangle(77,1,0,2,0x0000ff,0,0,0);
  if(third_first)model_triangle(99,1,0,3,0x00ff00,0,0,0);
  model_triangle(88,2,0,4,0xff0000,0,0,0);
  if(!third_first)model_triangle(99,1,0,3,0x00ff00,0,0,0);
  expect_color(0,10,10,third_first?31u<<10:31u<<5,third_first?0xff0000ffu:0xff00ff00u);cases++;
 }
 setup_shared(4,0,0);memcpy(fixture_other_owner.instance.renderer_root_q12,
   fixture_owner.instance.renderer_root_q12,sizeof fixture_owner.instance.renderer_root_q12);
 model_triangle(77,1,0,2,0x0000ff,0,0,0);
 model_triangle(88,2,0,1,0x808080,1,1,0);
 model_triangle(77,3,0,4,0xff0000,0,0,0);expect_color(0,10,10,31,0xffff0000u);cases++;
 printf("PASS: %u shared-root cases, exact/one-Q12 axes, opaque ownership replacement and self-depth, STP, IR/pages/GAME/EVENT/RGB\n",cases);
 return 0;
}
