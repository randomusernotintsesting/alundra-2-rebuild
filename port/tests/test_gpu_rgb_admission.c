#define main original_mesh_fixture_main
#include "test_gpu_native_mesh.c"
#undef main
static void camera_face(unsigned face,double z,unsigned color,int tex,uint16_t texel) {
 uint32_t words[9],src[3],dst[3],native[3],base=0x80090008;unsigned n=0;
 const int xx[3]={4,28,4},yy[3]={4,4,28};uint64_t object=world_precision_begin_object();
 words[n++]=(tex?0x24808080u:0x20000000u|color);
 for(unsigned j=0;j<3;j++) {
  native[j]=xy(xx[j],yy[j]);src[j]=0x1f800100+j*16;dst[j]=base+n*4;words[n++]=native[j];
  if(tex)words[n++]=(j==1?0x104u<<16:0)|32u|(32u<<8);
  world_precision_vertex v={.x=xx[j]+.25,.y=yy[j]+.5,.z=z,.projection_id=1000+object*3+j,
   .native_word=native[j],.producer_pc=fixture_source_family==A2_ACTOR_EVENT00?0x80013424:0x8001338c,
   .projection_kind=WORLD_PROJECTION_CAMERA,.camera_generation=object};
  world_precision_record(src[j],native[j],object,&v);
 }
 if(tex)seed_texel(288,32,texel);
 assert(world_precision_emit(dst,native,src,3,object));
 owned=(A2ActorPacket){.owner_handle=77,.native_face_index=face};owned_token=99;owned_address=base;owned_count=n;memcpy(owned_words,words,n*4);
 for(unsigned j=0;j<n;j++)gpu_gp0_at(words[j],base+j*4);
}
int main(void) {
 setenv("A2_COLOR_PRECISION","1",1);gpu_set_ir(1);
 for(int scale=2;scale<=4;scale++)for(int page=0;page<=256;page+=256)for(int event=0;event<2;event++) {
  fresh(scale,page,0);fixture_source_family=event?A2_ACTOR_EVENT00:A2_ACTOR_GAME00;
  g.day2=page+(event?171:215);world_camera_configure(1);gpu_model_depth_configure(1);gpu_model_depth_barrier();
  camera_face(1,2,0x050709,0,0);size_t at=(size_t)(page+10)*scale*IR_W+10*scale;
  assert(SHADOW_RGB[at]==0xff090705);
  uint64_t rejects=model_depth_rejected;camera_face(2,4,0x173b81,0,0);
  assert(model_depth_rejected>rejects && SHADOW_RGB[at]==0xff090705);
  camera_face(3,1,0,1,0);assert(SHADOW_RGB[at]==0xff090705);
  camera_face(4,1,0,1,0x8000);assert(SHADOW_RGB[at]==0xff000000);
  camera_face(5,.5,0x0f1317,0,0);assert(SHADOW_RGB[at]==0xff17130f);
  /* External color-only destination has no relationship to SHADOW. */
  uint16_t external=0;mesh_pixel_kind=A2_COMPOSITE_UNKNOWN;
  put_fine_pixel_impl(&external,7,11,15,0,0,0,0,0);
  assert(external==(1u<<5|1u<<10) && SHADOW_RGB[at]==0xff17130f);
  a2_mesh_live_enabled=1;assert(!gpu_display_argb_row(0));a2_mesh_live_enabled=0;assert(gpu_display_argb_row(0));
  portrait_fixture=1;portrait_value=(A2HDPortraitSample){.r=17,.g=31,.b=57,.a=173};
  SHADOW_RGB[at]=0xff07131d;assert(put_hd_portrait(10*scale,(page+10)*scale,128,128,128,0,0));
  unsigned r=(17*173+7*82+127)/255,gc=(31*173+19*82+127)/255,b=(57*173+29*82+127)/255;
  assert(SHADOW_RGB[at]==(0xff000000u|(r<<16)|(gc<<8)|b));
 }
 puts("PASS: real GAME/EVENT GP0 depth admission in RGB,IR2–4,both pages,transparent discard,STP black,external destination,mesh row gate and portrait alpha");
 return 0;
}
