/* Real GP0/raster. Immutable owner tokens are supplied at the independently
 * tested packet-observer boundary, as in test_gpu_native_mesh. */
#define main native_mesh_fixture_main
#include "test_gpu_native_mesh.c"
#undef main
static int stale_corner,unowned;
static int quad_shape,reverse_shape,shape_offset,shape_yoffset;
static uint32_t model_producer_pc=0x8001338cu;
static int bad_producer_corner=-1;
static const double *corner_depths;

static void model_triangle(uint64_t owner,unsigned face,unsigned layer,double z,
                           uint32_t rgb,int semi,int textured,uint16_t texel) {
 uint32_t words[12],src[4],dst[4],native[4],base=0x80090008;unsigned n=0;
 unsigned count=quad_shape?4:3;
 uint64_t object=world_precision_begin_object();
 unsigned command=0x20u|(semi?2u:0u)|(textured?4u:0u)|(quad_shape?8u:0u);
 words[n++]=(command<<24)|rgb;
 const int xs[4]={4,28,4,28},ys[4]={4,4,28,28};
 for(unsigned j=0;j<count;j++){
  unsigned k=reverse_shape&&(j==1||j==2)?3-j:j;
  native[j]=xy(xs[k]+shape_offset,ys[k]+shape_yoffset);src[j]=0x1f800100+j*16;dst[j]=base+4*n;words[n++]=native[j];
  if(textured)words[n++]=(j==1?0x104u<<16:0)|32u|(32u<<8);
  world_precision_vertex v={.x=xs[k]+shape_offset+.25,.y=ys[k]+shape_yoffset+.5,.z=corner_depths?corner_depths[k]:z,.projection_id=1000+object*3+j,
   .native_word=native[j],.producer_pc=(int)j==bad_producer_corner?0x8001338cu:model_producer_pc,.projection_kind=WORLD_PROJECTION_CAMERA,
   .camera_generation=object};
  world_precision_record(src[j],native[j],object,&v);
 }
 assert(world_precision_emit(dst,native,src,count,object));
 if(textured)seed_texel(288,32,texel);
 owned=(A2ActorPacket){.owner_handle=owner,.native_face_index=face,.material_layer=layer};
 owned_token=unowned?0:99;owned_address=base;owned_count=n;memcpy(owned_words,words,4*n);
 if(stale_corner)world_precision_invalidate(dst[2],4);
 for(unsigned j=0;j<n;j++)gpu_gp0_at(words[j],base+4*j);
}
/* Real PC00 G4s from producer2521 / consumer2523, verified against
 * RAM2522: torso202897 and pauldron202943. Exact Q16 screen coordinates;
 * the reciprocal depths at fine sample(648,400) are .00094806385 and
 * .00094311517 respectively, so the torso must remain visible. */
static void captured_shoulder_quad(int shoulder) {
 static const uint32_t command[2][8]={
  {0x38281921u,0x006500a4u,0x00271c23u,0x006400a1u,0x00433841u,0x006200a2u,0x00231d23u,0x006200a1u},
  {0x38210609u,0x006500a2u,0x0003061du,0x006300a1u,0x00503b56u,0x006300a4u,0x002c0d10u,0x006100a2u}};
 static const int32_t fine[2][4][2]={
  {{10765943,6632891},{10612837,6582640},{10666569,6501512},{10591092,6490148}},
  {{10672149,6637111},{10563275,6513541},{10740574,6550334},{10640148,6381333}}};
 static const double z[2][4]={{1060.879740417,1053.394102514,1060.440517306,1055.275988758},
                            {1060.460062921,1061.326449871,1055.307744086,1053.765722990}};
 uint32_t src[4],dst[4],native[4],base=0x80090008;uint64_t object=world_precision_begin_object();
 for(unsigned j=0;j<4;j++) {
  native[j]=command[shoulder][2*j+1];src[j]=0x1f800100+j*16;dst[j]=base+4*(2*j+1);
  world_precision_vertex v={.x=fine[shoulder][j][0]/65536.0,.y=fine[shoulder][j][1]/65536.0,
   .z=z[shoulder][j],.projection_id=1000+object*4+j,.native_word=native[j],
   .producer_pc=0x8001338c,.projection_kind=WORLD_PROJECTION_CAMERA,.camera_generation=object};
  world_precision_record(src[j],native[j],object,&v);
 }
 assert(world_precision_emit(dst,native,src,4,object));
 owned=(A2ActorPacket){.owner_handle=77,.source_mesh_index=shoulder?6:2};
 owned_token=99;owned_address=base;owned_count=8;memcpy(owned_words,command[shoulder],sizeof command[shoulder]);
 for(unsigned j=0;j<8;j++)gpu_gp0_at(command[shoulder][j],base+4*j);
}
static void begin_model_test(void) {
 fresh(4,0,0);g.dax2=319;g.day2=215;
 stale_corner=unowned=quad_shape=reverse_shape=shape_offset=shape_yoffset=0;corner_depths=NULL;
 model_producer_pc=0x8001338cu;bad_producer_corner=-1;
 world_camera_configure(1);gpu_model_depth_configure(1);gpu_model_depth_barrier();
}
/* Ground-shadow source tags come from separately exercised retained
 * emitter/RTPT tests. Exercise the real GP0/STP/fine raster boundary here. */
static const double *physical_shadow_depths;
static double physical_shadow_dx,physical_shadow_shear;
static int shadow_uv_gradient;
static void ground_shadow(int tagged,int fault,double z,uint16_t texel,int reverse) {
 uint32_t words[9]={0x2e808080},src[4],dst[4],native[4],base=0x80098008;
 const int xs[4]={4,28,4,28},ys[4]={4,4,28,28};
 uint64_t object=world_precision_begin_object();owned_token=0;
 shadow_geometry_fixture=fault!=9;memset(&shadow_geometry_value,0,sizeof shadow_geometry_value);
 memcpy(shadow_geometry_value.origin_q12,fixture_owner.camera_origin_q12,sizeof shadow_geometry_value.origin_q12);
 memcpy(shadow_geometry_value.rotation_q12,fixture_owner.camera_rotation_q12,sizeof shadow_geometry_value.rotation_q12);
 shadow_geometry_value.h=fixture_owner.projection_h;shadow_geometry_value.ofx=fixture_owner.projection_ofx;
 shadow_geometry_value.ofy=fixture_owner.projection_ofy;
 if(fault==3)shadow_geometry_value.origin_q12[0]++;
 if(fault==5)shadow_geometry_value.rotation_q12[0]++;
 if(fault==6)shadow_geometry_value.h++;
 if(fault==7)shadow_geometry_value.ofx++;
 if(fault==8)shadow_geometry_value.ofy++;
 if(fault==10)words[0]^=0x02000000;
 if(fault==11)words[0]^=0x08000000;
 for(unsigned j=0;j<4;j++) {
  unsigned k=reverse&&(j==1||j==2)?3-j:j;
  shadow_geometry_value.x[j]=(fault==4?20+(xs[k]-4)/3:xs[k])+.25;shadow_geometry_value.y[j]=ys[k]+.5;shadow_geometry_value.z[j]=physical_shadow_depths?physical_shadow_depths[k]:z;
  shadow_geometry_value.x[j]+=physical_shadow_dx+physical_shadow_shear*(ys[k]-4)/24.;
  if(fault==12 && k==3){shadow_geometry_value.x[j]=4.25;shadow_geometry_value.y[j]=4.5;}
  if(k==3) {
   if(fault==13)shadow_geometry_value.x[j]=NAN;
   if(fault==14)shadow_geometry_value.y[j]=1024;
   if(fault==15)shadow_geometry_value.z[j]=0;
   if(fault==16)shadow_geometry_value.z[j]=65536;
  }
  native[j]=xy(xs[k],ys[k]);src[j]=0x1f800180+16*j;dst[j]=base+4*(1+2*j);
  words[1+2*j]=native[j];words[2+2*j]=(j==1?0x104u<<16:0)|32u|(32u<<8);
  if(shadow_uv_gradient)words[2+2*j]=(j==1?0x104u<<16:0)|(unsigned)(32+xs[k]-4)|((unsigned)(32+ys[k]-4)<<8);
  world_precision_vertex v={.x=xs[k]+.25,.y=ys[k]+.5,.z=z,.projection_id=2000+object*4+j,
    .native_word=native[j],.producer_pc=fault==2?0x8001338c:0x800155d8,
    .projection_kind=WORLD_PROJECTION_NATIVE_Q16};
  world_precision_record(src[j],native[j],object,&v);
 }
 if(tagged)assert(world_precision_emit(dst,native,src,4,object));
 if(fault==1)world_precision_invalidate(dst[3],4);
 seed_texel(288,32,texel);
 if(shadow_uv_gradient)for(int y=0;y<=24;y++)for(int x=0;x<=24;x++)
  seed_texel(288+x,32+y,(uint16_t)((texel&0x8000)|0x400|x|(y<<5)));
 for(unsigned j=0;j<9;j++)gpu_gp0_at(words[j],base+4*j);
 shadow_geometry_fixture=0;
}
/* Physical coverage differs from the native integer footprint at both
 * exterior edges. Test expansion as well as removal: clipping alone cannot
 * produce the newly covered right edge. Optional shear makes the edge slant. */
static void shadow_physical_footprint(void) {
 for(int scale=2;scale<=4;scale++)for(int page=0;page<=256;page+=256)
 for(int reversed=0;reversed<2;reversed++)for(int shear=0;shear<2;shear++)
 for(int model=0;model<2;model++) {
  begin_model_test();fresh(scale,page,0);world_camera_configure(1);
  if(model){quad_shape=1;model_triangle(77,1,0,100,0x0000ff,0,0,0);}
  physical_shadow_dx=.75;physical_shadow_shear=shear*.5;
  ground_shadow(1,0,200,model?0x8000:0x03e0,reversed);
  physical_shadow_dx=physical_shadow_shear=0;
  /* The physical left edge lies between5 and5.5. Native starts at4. */
  assert(*shadow_px(4*scale+1,(page+10)*scale)==(model?31:0));
  /* Physical right edge lies between29 and29.5. Native ends at28. */
  if(!model)assert(*shadow_px(28*scale+1,(page+10)*scale)==0x03e0);
  assert(*shadow_px(10*scale,(page+10)*scale)==(model?31:0x03e0));
  assert(GPU_VRAM[(page+10)*1024+4]==(model?0x800f:0x03e0));
  assert(GPU_VRAM[(page+10)*1024+28]==0);
 }
}
static void shadow_affine_uv_and_diagonal(void) {
 static uint16_t native_image[1024*512];
 for(int page=0;page<=256;page+=256)for(int reverse=0;reverse<2;reverse++)
 for(int stp=0;stp<2;stp++)for(int tagged=0;tagged<2;tagged++) {
  begin_model_test();fresh(4,page,0);world_camera_configure(1);
  gpu_gp0(0x02ffffff);gpu_gp0(xy(0,page));gpu_gp0(xy(32,32));
  physical_shadow_dx=.75;physical_shadow_shear=.5;shadow_uv_gradient=1;
  ground_shadow(tagged,0,200,stp?0x8000:0,reverse);
  physical_shadow_dx=physical_shadow_shear=0;shadow_uv_gradient=0;
  if(!tagged){memcpy(native_image,GPU_VRAM,sizeof native_image);continue;}
  assert(!memcmp(native_image,GPU_VRAM,sizeof native_image));
  /* Physical parallelogram(5,4.5),(29,4.5),(5.5,28.5),(29.5,28.5).
   * At(16,16), affine UV=(42.760416...,43.5): texel RGB5=(10,11,1).
   * At(17.25,16.5), UV=(44,44) and the sample lies exactly on the split.
   * A shared edge must blend once, irrespective of winding. */
  assert(*shadow_px(64,page*4+64)==(stp?0xc2b4:0x056a));
  assert(*shadow_px(69,page*4+66)==(stp?0xc2b5:0x058c));
 }
}
static void shadow_physical_fallback(void) {
 uint16_t reference[128*128];
 for(int fault=13;fault<=16;fault++)for(int tagged=0;tagged<2;tagged++) {
  begin_model_test();physical_shadow_dx=.75;
  ground_shadow(tagged,fault,200,0x83e0,0);physical_shadow_dx=0;
  for(int y=0;y<128;y++)for(int x=0;x<128;x++) {
   if(!tagged)reference[y*128+x]=*shadow_px(x,y);
   else assert(reference[y*128+x]==*shadow_px(x,y));
  }
 }
}
static void shadow_occlusion_tests(void) {
 for(int scale=2;scale<=4;scale++)for(int page=0;page<=256;page+=256)
 for(int reverse=0;reverse<2;reverse++) {
  begin_model_test();fresh(scale,page,0);world_camera_configure(1);g.dax2=319;g.day2=page+215;
  quad_shape=1;model_triangle(77,1,0,100,0x0000ff,0,0,0);
  ground_shadow(1,0,200,0x8000,reverse);
  assert(GPU_VRAM[(page+10)*1024+10]==0x800f); /* Native shadow still drawn. */
  assert(*shadow_px(10*scale,(page+10)*scale)==31); /* RED: shadow behind chest wins. */
  assert(*shadow_px(24*scale,(page+24)*scale)==31); /* Quad second half. */
  /* Native split x+y=32 differs from physical split x+y=32.75.
   * The sample belongs to the other physical half of this same quad. */
  assert(*shadow_px(16*scale,(page+16)*scale+1)==31);
 }
 /* fresh() disables the world camera. Unsupported shadows retain the
  * native footprint, including subpixel edges, even with camera tags. */
 for(int scale=2;scale<=4;scale++)for(int command_kind=0;command_kind<3;command_kind++) {
  int command=command_kind==0?0:command_kind==1?10:11;
  uint16_t reference[128*128],native[32*32];
  for(int tagged=0;tagged<2;tagged++) {
   begin_model_test();fresh(scale,0,0);g.dax2=319;g.day2=215;
   ground_shadow(tagged,command,200,0x83e0,0);
   for(int y=0;y<32;y++)for(int x=0;x<32;x++) {
    if(!tagged)native[y*32+x]=GPU_VRAM[y*1024+x];else assert(native[y*32+x]==GPU_VRAM[y*1024+x]);
   }
   for(int y=0;y<32*scale;y++)for(int x=0;x<32*scale;x++) {
    if(!tagged)reference[y*128+x]=*shadow_px(x,y);else assert(reference[y*128+x]==*shadow_px(x,y));
   }
  }
 }
 /* Unknown/stale tags, nearby/front shadows and non-STP samples retain
  * source ordering. Transparent holes and hidden shadows retain depth. */
 for(int kind=0;kind<15;kind++) {
  begin_model_test();model_triangle(77,1,0,100,0x0000ff,0,0,0);
  if(kind==5)gpu_model_depth_configure(0);
  ground_shadow(kind!=0,kind==1?1:kind==2?2:kind==8?3:kind==9?4:kind>=10?kind-5:0,kind==3?90:kind==4?110:200,
                kind==6?0x03e0:kind==7?0:0x8000,0);
  uint16_t value=*shadow_px(40,40);
  /* kind9 supplies a certified physical quad entirely to the right of
   * this model sample; its old integer footprint must no longer shade it. */
  assert(value==(kind==6?0x03e0:kind==7||kind==9?31:0x800f));
 }
 begin_model_test();model_triangle(77,1,0,100,0x0000ff,0,0,0);
 gpu_gp0(0xe2000001);ground_shadow(1,0,200,0x8000,0);
 assert(*shadow_px(40,40)==0x800f); /* Material state outside sealed payload. */
 for(int farther=0;farther<2;farther++) {
  begin_model_test();model_triangle(77,1,0,100,0x0000ff,0,0,0);
  ground_shadow(1,0,farther?132.5:132.,0x8000,0);
  assert(*shadow_px(40,40)==(farther?31:0x800f));
 }
 begin_model_test();quad_shape=1;model_triangle(77,1,0,100,0x0000ff,0,0,0);
 const double slope[4]={110,600,600,110};physical_shadow_depths=slope;
 ground_shadow(1,0,20,0x8000,0);physical_shadow_depths=NULL;
 assert(*shadow_px(20,20)==0x800f);assert(*shadow_px(80,40)==31);assert(*shadow_px(108,108)==0x800f);
 begin_model_test();quad_shape=1;model_triangle(77,1,0,100,0x0000ff,0,0,0);
 const double split_slope[4]={10000,130,130,100};physical_shadow_depths=split_slope;
 ground_shadow(1,0,20,0x8000,0);physical_shadow_depths=NULL;
 /* At (16,16.25), containing half gives Z132.73; extrapolating the
  * native half would give Z130.80 and incorrectly preserve the shadow. */
 assert(*shadow_px(64,65)==31);
 begin_model_test();quad_shape=1;model_triangle(77,1,0,100,0x0000ff,0,0,0);
 const double folded[4]={200,200,200,50};physical_shadow_depths=folded;
 ground_shadow(1,12,200,0x8000,0);physical_shadow_depths=NULL;
 /* Adversarial geometry oracle: its physical halves completely overlap,
  * while native XY still form an unfolded quad. Both fine triangles blend
  * in order: red31 ->15 ->7. This is not a shared-edge ownership case.
  * The nearer physical half is in front, so neither sample is occluded. */
 assert(*shadow_px(40,40)==0x8007);
 assert(GPU_VRAM[10*1024+10]==0x800f);
 begin_model_test();model_triangle(77,1,0,100,0x0000ff,0,0,0);
 ground_shadow(1,0,200,0x8000,0);model_triangle(77,2,0,300,0xff0000,0,0,0);
 assert(*shadow_px(40,40)==31);
}
/* EVENT uses the same authoritative packet/world boundary as GAME, with
 * its own original projection instruction and letterboxed drawing area. */
static void begin_event_depth(int scale,int page) {
 begin_model_test();fresh(scale,page,0);
 fixture_source_family=A2_ACTOR_EVENT00;model_producer_pc=0x80013424u;
 g.day2=page+171;world_camera_configure(1);gpu_model_depth_configure(1);
}
static void event_surface_order(void) {
 static uint16_t native_reference[1024*512];
 for(int scale=2;scale<=4;scale++)for(int page=0;page<=256;page+=256)
 for(int reverse=0;reverse<2;reverse++)for(int quad=0;quad<2;quad++)
 for(int order=0;order<2;order++)for(int enabled=0;enabled<2;enabled++) {
  begin_event_depth(scale,page);quad_shape=quad;reverse_shape=reverse;
  gpu_model_depth_configure(enabled);
  const double depths[4]={2,8,8,2};
  for(int draw=0;draw<2;draw++) {
   int slope=draw==order;corner_depths=slope?depths:NULL;
   model_triangle(77,slope?1:2,0,4,slope?0x0000ff:0xff0000,0,0,0);
  }
  if(!enabled){memcpy(native_reference,GPU_VRAM,sizeof native_reference);continue;}
  assert(!memcmp(native_reference,GPU_VRAM,sizeof native_reference));
  /* Reciprocal Z crosses4. Red is nearer at10,10; blue at20,6.
   * Quad sample24,24 belongs only to its second half and must be red. */
  uint16_t near=*shadow_px(10*scale,(page+10)*scale);
  if(near!=31)fprintf(stderr,"EVENT farther face wins: IR%d page%d reverse%d quad%d order%d got%04x expected001f\n",scale,page,reverse,quad,order,near);
  assert(near==31);
  assert(*shadow_px(20*scale,(page+6)*scale)==(31u<<10));
  if(quad)assert(*shadow_px(24*scale,(page+24)*scale)==31);
 }
}
static void event_depth_boundaries(void) {
 for(int scale=2;scale<=4;scale++)for(int page=0;page<=256;page+=256) {
  begin_event_depth(scale,page);shape_yoffset=152;
  model_triangle(77,1,0,2,0x0000ff,0,0,0);
  model_triangle(77,2,0,4,0xff0000,0,0,0);
  assert(*shadow_px(6*scale,(page+171)*scale)==31);
  assert(*shadow_px(6*scale,(page+172)*scale)==0);
 }
 /* Mismatched projection families or scissor do not turn unrelated
  * geometry into an occluder. The fourth corner must also be checked. */
 for(int fault=0;fault<8;fault++) {
  begin_event_depth(fault==7?1:4,0);quad_shape=1;
  if(fault==0){fixture_source_family=A2_ACTOR_GAME00;g.day2=215;}
  if(fault==1)fixture_source_family=255;
  if(fault==2)model_producer_pc=0x8001338cu;
  if(fault==3)bad_producer_corner=3;
  if(fault==4)g.day2=215;
  if(fault==5)world_camera_configure(0);
  if(fault==6)unowned=1;
  model_triangle(77,1,0,2,0x0000ff,0,0,0);
  model_triangle(77,2,0,4,0xff0000,0,0,0);
  assert(GPU_VRAM[10*1024+10]==(31u<<10));
  assert(*shadow_px(10*IR,10*IR)==(31u<<10));
 }
}
static void event_material_and_ownership(void) {
 for(int type=0;type<3;type++) {
  begin_event_depth(4,0);
  model_triangle(77,1,1,2,0x808080,1,1,type==0?0:type==1?0x801f:0x001f);
  model_triangle(77,2,0,4,0xff0000,0,0,0);
  assert(*shadow_px(40,40)==(type==2?31:(31u<<10)));
 }
 for(int foreign=0;foreign<2;foreign++)for(int hole=0;hole<2;hole++) {
  begin_event_depth(4,256);model_triangle(77,1,0,2,0x0000ff,0,0,0);
  shape_offset=20;unowned=!foreign;
  model_triangle(foreign?88:77,3,1,1,0x808080,1,1,hole?0:0x83e0);
  shape_offset=unowned=0;model_triangle(77,2,0,4,0xff0000,0,0,0);
  assert(*shadow_px(40,256*4+40)==31);
  assert(*shadow_px(100,256*4+24)==(hole?31:(31u<<10)));
 }
 begin_event_depth(4,0);model_triangle(77,1,0,2,0x0000ff,0,0,0);
 stale_corner=1;model_triangle(77,2,0,4,0xff0000,0,0,0);
 assert(*shadow_px(40,40)==(31u<<10));
 stale_corner=0;model_triangle(77,3,0,8,0x00ff00,0,0,0);
 assert(*shadow_px(40,40)==(31u<<5));
 begin_event_depth(4,0);model_triangle(77,1,0,2,0x0000ff,0,0,0);
 gpu_model_depth_barrier();model_triangle(77,2,0,4,0xff0000,0,0,0);
 assert(*shadow_px(40,40)==(31u<<10));
}

#ifndef A2_MODEL_DEPTH_FIXTURE_ONLY
/* The first triangle runs with depth enabled but an empty segment. Later
 * triangles must stop using ordinary writes as soon as a model owns depth. */
static void ordinary_to_model_sequence(void) {
 for(int scale=2;scale<=4;scale++)for(int page=0;page<=256;page+=256)for(int hole=0;hole<2;hole++) {
  begin_model_test();fresh(scale,page,0);world_camera_configure(1);gpu_model_depth_barrier();
  unowned=1;model_triangle(77,9,0,8,0x2468ac,0,0,0);unowned=0;
  size_t offset=(size_t)(page+10)*scale*IR_W+10*scale;
  assert(!model_depth_plane_valid&&!model_depth_has_samples);
  assert(SHADOW_RGB&&SHADOW_RGB[offset]==0xffac6824u);
  model_triangle(77,1,0,2,0x0000ff,0,0,0);
  assert(model_depth_plane_valid&&model_depth_has_samples&&SHADOW_RGB[offset]==0xffff0000u);
  unowned=1;model_triangle(77,3,1,3,0x808080,1,1,hole?0:0x83e0);unowned=0;
  assert(!model_depth_plane_valid&&model_depth_has_samples);
  model_triangle(77,2,0,4,0xff0000,0,0,0);
  assert(SHADOW[offset]==(hole?31:31u<<10));
  assert(SHADOW_RGB[offset]==(hole?0xffff0000u:0xff0000ffu));
  assert(GPU_VRAM[(page+10)*1024+10]==(31u<<10));
 }
}
static void ordinary_route_guards(void) {
 /* Conservative admission is part of this optimization's contract even
  * where a particular inactive fixture would happen to produce one color. */
 for(int reason=0;reason<4;reason++) {
  begin_model_test();assert(fine_pixel_ordinary());
  if(reason==0)model_depth_plane_valid=1;
  if(reason==1)model_depth_has_samples=1;
  if(reason==2)a2_mesh_live_enabled=1;
  if(reason==3)mesh_pixel_kind=A2_COMPOSITE_OWNED;
  assert(!a2_mesh_live_active&&!fine_pixel_ordinary());
 }
 begin_model_test();
 mesh_pixel_kind=A2_COMPOSITE_OWNED;
 uint16_t *pixel=shadow_px(40,40);*pixel=0x1973;SHADOW_RGB[pixel-SHADOW]=0xff193b57u;
 Vtx v={.r=255,.gr=0,.b=0};
 WorldFineTriangle triangle={{{4*65536,4*65536},{28*65536,4*65536},{4*65536,28*65536}}};
 raster_tri_world_fine(v,v,v,triangle,0,0,0,4,NULL);
 assert(*pixel==0x1973&&SHADOW_RGB[pixel-SHADOW]==0xff193b57u);
}
/* A folded source quad projects both halves onto the same samples. Its
 * first three vertices are on the near plane, its last vertex behind it.
 * Source face equality does not make these physical surfaces coincident. */
static void folded_model_quad(int reverse,unsigned layer,uint32_t near_rgb) {
 uint32_t words[8],src[4],dst[4],native[4],base=0x80090008;
 uint64_t object=world_precision_begin_object();
 const int xs[4]={4,28,4,10},ys[4]={4,4,28,10};
 for(unsigned j=0;j<4;j++) {
  unsigned k=reverse?3-j:j;
  uint32_t rgb=k==3?0xff0000:near_rgb;
  words[2*j]=rgb|(j==0?0x38000000u:0);native[j]=xy(xs[k],ys[k]);words[2*j+1]=native[j];
  src[j]=0x1f800100+j*16;dst[j]=base+4*(2*j+1);
  world_precision_vertex v={.x=xs[k]+.25,.y=ys[k]+.5,.z=k==3?4:2,
   .projection_id=1000+object*4+j,.native_word=native[j],.producer_pc=model_producer_pc,
   .projection_kind=WORLD_PROJECTION_CAMERA,.camera_generation=object};
  world_precision_record(src[j],native[j],object,&v);
 }
 assert(world_precision_emit(dst,native,src,4,object));
 owned=(A2ActorPacket){.owner_handle=77,.native_face_index=1,.material_layer=layer};
 owned_token=99;owned_address=base;owned_count=8;memcpy(owned_words,words,sizeof words);
 for(unsigned j=0;j<8;j++)gpu_gp0_at(words[j],base+4*j);
}
static void folded_face_depth(void) {
 static uint16_t native_reference[1024*512];
 for(int family=0;family<2;family++)for(int scale=2;scale<=4;scale++)
 for(int page=0;page<=256;page+=256)for(int reverse=0;reverse<2;reverse++)
 for(int enabled=0;enabled<2;enabled++) {
  if(family)begin_event_depth(scale,page);
  else {begin_model_test();fresh(scale,page,0);world_camera_configure(1);gpu_model_depth_configure(1);}
  gpu_model_depth_configure(enabled);
  folded_model_quad(reverse,0,0x0000ff);
  if(enabled) {
   uint16_t px=*shadow_px(11*scale,(page+11)*scale);
   if(px!=31)fprintf(stderr,"folded face depth: family%d IR%d page%d reverse%d got%04x expected001f\n",family,scale,page,reverse,px);
   assert(px==31);
  }
  /* A physically coincident second material must still paint the near half. */
  folded_model_quad(reverse,1,0x00ff00);
  if(enabled)assert(*shadow_px(11*scale,(page+11)*scale)==(31u<<5));
  if(!enabled)memcpy(native_reference,GPU_VRAM,sizeof native_reference);
  else assert(!memcmp(native_reference,GPU_VRAM,sizeof native_reference));
 }
 puts("folded face depth: 24 GAME/EVENT scale/page/order cases preserve nearest half, coincident material and full native VRAM");
}
/* Opaque camera-projected WORLD faces (room renderer RTPS) use the same
 * fine raster without an actor owner. */
static void world_triangle(double z,uint32_t rgb) {
 uint32_t saved=model_producer_pc;model_producer_pc=0x80010d4cu;unowned=1;
 model_triangle(0,0,0,z,rgb,0,0,0);
 unowned=0;model_producer_pc=saved;
}
/* Previous-frame model region around the fixture's (4..28) faces. */
static void model_region(int valid) {
 model_roi_now.valid=0;model_roi_last.valid=valid;
 model_roi_last.x0=10;model_roi_last.y0=10;model_roi_last.x1=20;model_roi_last.y1=20;model_roi_frame=psx_frame_no;
}
static void world_model_order(void) {
 /* RED before WORLD depth: a model behind a nearer WORLD face drew over it. */
 begin_model_test();world_depth_enabled=1;model_region(1);
 world_triangle(2,0x0000ff);model_triangle(77,1,0,40,0xff0000,0,0,0);
 assert(*shadow_px(40,40)==31);
 /* A farther WORLD face never hides the model drawn after it. */
 begin_model_test();world_triangle(40,0x0000ff);model_triangle(77,1,0,4,0xff0000,0,0,0);
 assert(*shadow_px(40,40)==(31u<<10));
 /* WORLD drawn later keeps original order even over a nearer model:
  * authored covers (tree crowns) depend on it. */
 begin_model_test();model_triangle(77,1,0,4,0xff0000,0,0,0);world_triangle(40,0x0000ff);
 assert(*shadow_px(40,40)==31);
 /* Contact band: within8 camera units the original order remains. */
 begin_model_test();world_triangle(100,0x0000ff);model_triangle(77,1,0,107,0xff0000,0,0,0);
 assert(*shadow_px(40,40)==(31u<<10));
 /* Pass barriers retire WORLD depth as they retire model depth. */
 begin_model_test();world_triangle(2,0x0000ff);gpu_model_depth_barrier();
 model_triangle(77,1,0,40,0xff0000,0,0,0);
 assert(*shadow_px(40,40)==(31u<<10));
 /* No model region yet (first frame of a scene): native order. */
 begin_model_test();model_region(0);world_triangle(2,0x0000ff);model_triangle(77,1,0,40,0xff0000,0,0,0);
 assert(*shadow_px(40,40)==(31u<<10));
 /* A WORLD face far from every model region records no depth. */
 begin_model_test();model_region(1);model_roi_last.x0=200;model_roi_last.x1=210;
 world_triangle(2,0x0000ff);model_triangle(77,1,0,40,0xff0000,0,0,0);
 assert(*shadow_px(40,40)==(31u<<10));
 model_region(1);
 /* Disabled: original PS1 order. */
 begin_model_test();world_depth_enabled=0;
 world_triangle(2,0x0000ff);model_triangle(77,1,0,40,0xff0000,0,0,0);
 assert(*shadow_px(40,40)==(31u<<10));
}
/* With WORLD depth, a ground shadow is a decal on its physical plane: it
 * never darkens a model (beyond4) or WORLD face (beyond16) in front of the
 * plane, and it keeps the depth it darkens. */
static void shadow_decal_rules(void) {
 double saved_model=shadow_model_margin,saved_world=shadow_world_margin;int saved_keep=shadow_keep_depth;
 shadow_model_margin=4;shadow_world_margin=16;shadow_keep_depth=1;
 for(int kind=0;kind<5;kind++) {
  begin_model_test();world_depth_enabled=1;model_region(1);
  if(kind<2)model_triangle(77,1,0,100,0x0000ff,0,0,0);else world_triangle(kind==2?50:100,0x0000ff);
  ground_shadow(1,0,kind==0?110:kind==1?102:kind==2?100:105,0x8000,0);
  uint16_t value=*shadow_px(40,40);
  /* Boots / wall in front keep their colour; ground contact is shaded. */
  assert(kind==0||kind==2?value==31:value!=31);
  if(kind==1) { /* Shaded model depth survives: a farther face stays hidden. */
   model_triangle(77,2,0,200,0xff0000,0,0,0);assert(*shadow_px(40,40)==value);
  }
 }
 world_depth_enabled=0;shadow_model_margin=saved_model;shadow_world_margin=saved_world;shadow_keep_depth=saved_keep;
}
int main(void) {
 folded_face_depth();
 setenv("A2_COLOR_PRECISION","1",1);
 ordinary_to_model_sequence();ordinary_route_guards();
 event_surface_order();
 event_depth_boundaries();
 event_material_and_ownership();
 shadow_physical_footprint();
 shadow_affine_uv_and_diagonal();
 shadow_physical_fallback();
 shadow_occlusion_tests();
 world_model_order();
 shadow_decal_rules();
 begin_model_test();
 model_triangle(77,1,0,2,0x0000ff,0,0,0);
 uint16_t near=*shadow_px(40,40);assert(near==31);
 model_triangle(77,2,0,4,0xff0000,0,0,0);
 assert(GPU_VRAM[10*1024+10]==(31u<<10)); /* Native ordered raster unchanged. */
 assert(*shadow_px(40,40)==near); /* RED: the farther surface currently wins. */
 model_triangle(77,2,1,4,0x00ff00,1,0,0);
 assert(*shadow_px(40,40)==near); /* Hidden surface's overlay is also hidden. */
 model_triangle(77,1,1,2,0x00ff00,1,0,0);
 assert(*shadow_px(40,40)==(15u|(15u<<5))); /* Coincident material order. */

 /* STP, rather than packet/layer number, decides whether depth is written. */
 for(int type=0;type<3;type++) {
  begin_model_test();
  uint16_t texel=type==0?0:type==1?0x801f:0x001f;
  model_triangle(77,1,1,2,0x808080,1,1,texel);
  model_triangle(77,2,0,4,0xff0000,0,0,0);
  assert(*shadow_px(40,40)==(type==2?31:(31u<<10)));
 }

 /* A farther sealed owner in this same camera remains occluded. Unknown
  * coverage and bulk/pass barriers still retire prior depth. */
 for(int barrier=0;barrier<7;barrier++) {
  begin_model_test();model_triangle(77,1,0,2,0x0000ff,0,0,0);
  if(barrier==0)model_triangle(88,1,0,3,0x00ff00,0,0,0);
  if(barrier==1){gpu_gp0(0x6000ff00);gpu_gp0(xy(4,4));gpu_gp0(xy(24,24));}
  if(barrier==2)gpu_model_depth_barrier();
  if(barrier==3){unowned=1;model_triangle(77,3,0,3,0x00ff00,0,0,0);unowned=0;}
  if(barrier==4){gpu_gp0(0x4800ff00);gpu_gp0(xy(4,10));gpu_gp0(xy(28,10));gpu_gp0(0x50005000);}
  if(barrier>=5){gpu_gp0(barrier==5?0xa1000000:0xbf000000);gpu_gp0(xy(10,10));gpu_gp0(xy(1,1));gpu_gp0(0x03e0);}
  model_triangle(77,2,0,4,0xff0000,0,0,0);
  assert(*shadow_px(40,40)==(barrier==0?31:(31u<<10)));
 }
 begin_model_test();model_triangle(77,1,0,2,0x0000ff,0,0,0);
 gpu_gp0(0xe1000000);gpu_gp0(0xe2000000);
 model_triangle(77,2,0,4,0xff0000,0,0,0);
 assert(*shadow_px(40,40)==31); /* Ordinary material prefixes retain the segment. */
 begin_model_test();model_triangle(77,1,0,2,0x0000ff,0,0,0);
 stale_corner=1;model_triangle(77,2,0,4,0xff0000,0,0,0);
 assert(*shadow_px(40,40)==(31u<<10));
 stale_corner=0;model_triangle(77,3,0,8,0x00ff00,0,0,0);
 assert(*shadow_px(40,40)==(31u<<5)); /* fallback write retired the old depth */
 /* Suppressed original faces do not write SHADOW and cannot erase its
  * depth. Replacement failure may retain OWNED even after active becomes0. */
 begin_model_test();model_triangle(77,1,0,2,0x0000ff,0,0,0);
 model_depth_plane_valid=0;mesh_pixel_kind=A2_COMPOSITE_OWNED;
 put_fine_pixel(shadow_px(40,40),0,255,0,0,0,0,0);
 assert(*shadow_px(40,40)==31);
 model_triangle(77,2,0,4,0xff0000,0,0,0);
 assert(*shadow_px(40,40)==31);
 /* An interleaved polygon which never touches this surface cannot make
  * the same actor forget its nearer depth. Actual PS1 ordering interleaves
  * PC00 and room packets between torso202897 and pauldron202943. */
 for(int foreign=0;foreign<2;foreign++) {
  begin_model_test();model_triangle(77,1,0,2,0x0000ff,0,0,0);
  shape_offset=40;unowned=!foreign;
  model_triangle(foreign?88:77,3,0,3,0x00ff00,0,0,0);
  shape_offset=unowned=0;
  model_triangle(77,2,0,4,0xff0000,0,0,0);
  assert(*shadow_px(40,40)==31);
 }
 /* Transparent holes preserve prior depth; foreign STP blending retires
  * its covered pixel. A nearer opaque owner in the same camera now keeps
  * its physical depth when the first owner later draws behind it. */
 for(int foreign=0;foreign<2;foreign++)for(int type=0;type<4;type++) {
  begin_model_test();model_triangle(77,1,0,2,0x0000ff,0,0,0);
  unowned=!foreign;shape_offset=20;
  model_triangle(foreign?88:77,3,1,1,0x808080,1,1,type==0?0:type==1?0x83e0:type==2?0x03e0:0x001f);
  unowned=shape_offset=0;
  model_triangle(77,2,0,4,0xff0000,0,0,0);
  assert(*shadow_px(40,40)==31); /* outside foreign coverage */
  assert(*shadow_px(100,24)==(type==0?31:foreign&&type>=2?(type==2?31u<<5:31):31u<<10));
 }
 begin_model_test();captured_shoulder_quad(0);
 uint16_t torso=*shadow_px(648,400);assert(torso!=0);
 unowned=1;model_triangle(77,3,0,3,0x00ff00,0,0,0);unowned=0;
 captured_shoulder_quad(1);
 assert(*shadow_px(648,400)==torso);
 /* Replaying J2's global retirement establishes that these exact captured
  * colors do expose the error, even with unchanged original geometry. */
 gpu_model_depth_barrier();captured_shoulder_quad(1);
 assert(*shadow_px(648,400)!=torso);
 /* A reciprocal plane crosses z=4 inside the shape. Literal samples on
  * opposite sides catch constant/linear-z interpolation and winding mistakes;
  * the last sample is exclusively in a quad's second triangle. */
 for(int scale=2;scale<=4;scale++)for(int page=0;page<=256;page+=256)
 for(int reverse=0;reverse<2;reverse++)for(int quad=0;quad<2;quad++)
 for(int order=0;order<2;order++) {
  begin_model_test();fresh(scale,page,0);world_camera_configure(1);gpu_model_depth_barrier();
  quad_shape=quad;reverse_shape=reverse;
  const double depths[4]={2,8,8,2};
  for(int draw=0;draw<2;draw++) {
   int slope=draw==order;corner_depths=slope?depths:NULL;
   model_triangle(77,slope?1:2,0,4,slope?0x0000ff:0xff0000,0,0,0);
  }
  if(*shadow_px(10*scale,(page+10)*scale)!=31)fprintf(stderr,"slope scale%d page%d reverse%d quad%d order%d value%04x admitted%llu plane %g,%g,%g valid%d\n",scale,page,reverse,quad,order,*shadow_px(10*scale,(page+10)*scale),(unsigned long long)model_depth_admitted,model_depth_plane[0],model_depth_plane[1],model_depth_plane[2],model_depth_plane_valid);
  assert(*shadow_px(10*scale,(page+10)*scale)==31);
  assert(*shadow_px(20*scale,(page+6)*scale)==(31u<<10));
  if(quad)assert(*shadow_px(24*scale,(page+24)*scale)==31);
 }
 puts("model depth: opaque visibility, native raster, STP/transparent discard, layers, owners, barriers and stale-corner fallback pass");
}
#endif
