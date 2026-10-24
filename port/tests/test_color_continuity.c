/* Real GP0 raster; the immutable packet observer is tested separately. */
#define main native_mesh_fixture_main
#include "test_gpu_native_mesh.c"
#undef main

static void draw(int mode,int scale,int page,int reverse,int thin,int fault) {
 fresh(scale,page,0);world_camera_configure(1);gpu_model_depth_configure(1);
 if(fault==5)gpu_model_depth_configure(0);
 if(fault==6)g.day2--;
 gpu_model_depth_barrier();
 const uint32_t original[3]={0x200070,0x005028,0x600018};
 const uint32_t corrected[3]={0x205080,0x207050,0x705020};
 const double xx[3]={4.125,thin?4.875:28.25,4.125};
 const double yy[3]={4.25,4.25,thin?5.875:28.5};
 uint32_t words[6],src[3],dst[3],native[3],base=0x80090008;
 uint64_t object=world_precision_begin_object();
 owned=(A2ActorPacket){.owner_handle=77,.fine_rgb_valid=mode==2&&fault!=3};
 for(unsigned j=0;j<3;j++) {
  unsigned k=reverse&&j?3-j:j;
  words[2*j]=(j?0:fault==4?0x32000000u:0x30000000u)|(mode==1?corrected[k]:original[k]);
  native[j]=xy((int)xx[k],(int)yy[k]);words[2*j+1]=native[j];
  src[j]=0x1f800100+16*j;dst[j]=base+4*(2*j+1);
  owned.fine_rgb[j]=corrected[k];
  world_precision_vertex v={.x=xx[k],.y=yy[k],.z=100,
   .projection_id=1000+object*3+j,.native_word=native[j],
   .producer_pc=0x8001338c,.projection_kind=WORLD_PROJECTION_CAMERA,
   .camera_generation=object};
  world_precision_record(src[j],native[j],object,&v);
 }
 assert(world_precision_emit(dst,native,src,3,object));
 if(fault==2)world_precision_invalidate(dst[1],4);
 owned_token=fault==1?0:99;owned_address=base;owned_count=6;
 memcpy(owned_words,words,sizeof words);
 for(unsigned j=0;j<6;j++)gpu_gp0_at(words[j],base+4*j);
}

int main(void) {
 static uint16_t native[1024*512];
 uint16_t *fine=malloc(1024u*512u*16u*2u);assert(fine);
 for(int scale=1;scale<=4;scale++)for(int page=0;page<=256;page+=256)
 for(int reverse=0;reverse<2;reverse++)for(int thin=0;thin<2;thin++) {
  draw(0,scale,page,reverse,thin,0);memcpy(native,GPU_VRAM,sizeof native);
  size_t bytes=SHADOW?(size_t)IR_W*IR_H*2:0;
  if(bytes)memcpy(fine,SHADOW,bytes);
  draw(2,scale,page,reverse,thin,0);
  assert(!memcmp(native,GPU_VRAM,sizeof native));
  if(scale==1) {if(bytes)assert(!memcmp(fine,SHADOW,bytes));continue;}
  if(!bytes||!memcmp(fine,SHADOW,bytes))fprintf(stderr,"unchanged scale=%d page=%d reverse=%d thin=%d consumed=%u depth_admitted=%llu\n",scale,page,reverse,thin,consumed,(unsigned long long)model_depth_admitted);
  assert(bytes&&memcmp(fine,SHADOW,bytes));
  memcpy(fine,SHADOW,bytes);
  draw(1,scale,page,reverse,thin,0);
  assert(!memcmp(fine,SHADOW,bytes)); /* independent native-color oracle */
  for(int fault=1;fault<=6;fault++) {
   draw(0,scale,page,reverse,thin,fault);memcpy(fine,SHADOW,bytes);
   memcpy(native,GPU_VRAM,sizeof native);
   draw(2,scale,page,reverse,thin,fault);
   assert(!memcmp(fine,SHADOW,bytes)&&!memcmp(native,GPU_VRAM,sizeof native));
  }
 }
 free(fine);
 puts("PASS: GP0 presentation colors, full native VRAM equality, pages, winding, thin triangles, IR1 and invalid metadata fallback");
 return 0;
}
