#define main frozen_transport_fixture_main
#ifndef A2_FINE_ORACLE_SOURCE
#define A2_FINE_ORACLE_SOURCE "test_world_precision_gpu.c"
#endif
#include A2_FINE_ORACLE_SOURCE
#undef main
#include "texture_versions.h"
static uint64_t random_state=0x248facb9804317ull,samples;
static uint32_t random32(void){random_state^=random_state<<13;random_state^=random_state>>7;random_state^=random_state<<17;return (uint32_t)random_state;}
static void check(const A2TexVersion *v,uint32_t page,uint32_t clut,uint32_t window,unsigned count){
 cur_tpage=page;cur_clut=clut;g.texwin=window;
 for(unsigned i=0;i<count;i++){
  int x=count==65536?(int)(i&255):(int)(random32()%2048)-1024;
  int y=count==65536?(int)(i>>8):(int)(random32()%2048)-1024;
  assert(a2_tex_sample(v,window,x,y)==sample_tex(x,y));samples++;
 }
}
static void all_formats(void){
 A2TexCache *cache=a2_tex_create(1024*1024,16);assert(cache);
 const uint32_t cluts[]={0,63,511*64+63,256*64+1,15*64+62,31*64+31};
 for(unsigned i=0;i<1024*512;i++)GPU_VRAM[i]=(uint16_t)random32();
 for(unsigned mode=0;mode<4;mode++)for(unsigned page=0;page<32;page++)for(unsigned palette=0;palette<6;palette++){
  unsigned tp=(mode<<7)|page,cl=cluts[palette];const A2TexVersion *v=a2_tex_acquire(cache,GPU_VRAM,tp,cl);assert(v);
  for(unsigned j=0;j<4;j++)check(v,tp,cl,j?random32()&0xfffff:0,4096);
  if(palette==0)check(v,tp,cl,0,65536);
  const A2TexVersion *same=a2_tex_acquire(cache,GPU_VRAM,tp^(3<<5),cl);assert(same==v);a2_tex_release(cache,same);
  if(mode>=2){same=a2_tex_acquire(cache,GPU_VRAM,tp^128,cl^32767);assert(same==v);a2_tex_release(cache,same);}
  a2_tex_release(cache,v);
 }
 assert(a2_tex_stats(cache).peak_bytes<=1024*1024);a2_tex_destroy(cache);
}
static void invalidation_and_leases(void){
 A2TexCache *cache=a2_tex_create(1024*1024,8);assert(cache);
 GPU_VRAM[0]=0x1234;const A2TexVersion *old=a2_tex_acquire(cache,GPU_VRAM,256,0);assert(old);
 uint64_t old_id=a2_tex_region(old).id;
 GPU_VRAM[400*1024+512]^=17;a2_tex_written(cache,512,400,1,1);
 const A2TexVersion *same=a2_tex_acquire(cache,GPU_VRAM,256,0);assert(same==old);a2_tex_release(cache,same);
 GPU_VRAM[0]=0x4567;a2_tex_written(cache,0,0,1,1);
 const A2TexVersion *next=a2_tex_acquire(cache,GPU_VRAM,256,0);assert(next&&a2_tex_region(next).id!=old_id);
 assert(a2_tex_sample(old,0,0,0)==0x1234&&a2_tex_sample(next,0,0,0)==0x4567);a2_tex_release(cache,next);
 a2_tex_reset(cache);next=a2_tex_acquire(cache,GPU_VRAM,256,0);assert(next&&a2_tex_region(next).id!=old_id);a2_tex_release(cache,next);
 a2_tex_test_set_epoch(cache,UINT64_MAX);GPU_VRAM[0]=0x789a;a2_tex_written(cache,0,0,1,1);
 next=a2_tex_acquire(cache,GPU_VRAM,256,0);assert(next&&a2_tex_sample(next,0,0,0)==0x789a&&a2_tex_sample(old,0,0,0)==0x1234);
 assert(a2_tex_stats(cache).epoch_resets==2);a2_tex_release(cache,next);a2_tex_release(cache,old);
 /* Independent wrapped palette change, including an old pinned lease. */
 GPU_VRAM[0]=0;GPU_VRAM[511*1024+1008]=0x1357;a2_tex_written(cache,0,0,1,1);a2_tex_written(cache,1008,511,1,1);
 old=a2_tex_acquire(cache,GPU_VRAM,0,511*64+63);assert(old);old_id=a2_tex_region(old).id;
 GPU_VRAM[511*1024+1008]=0x2468;a2_tex_written(cache,-16,-1,1,1);
 next=a2_tex_acquire(cache,GPU_VRAM,0,511*64+63);assert(next&&a2_tex_region(next).id!=old_id);
 assert(a2_tex_sample(old,0,0,0)==0x1357&&a2_tex_sample(next,0,0,0)==0x2468);a2_tex_release(cache,old);a2_tex_release(cache,next);
 /* Only the final wrapped8-bit CLUT tile changes. */
 GPU_VRAM[0]=255;GPU_VRAM[511*1024+239]=0x4321;a2_tex_written(cache,0,0,1,1);a2_tex_written(cache,239,511,1,1);
 old=a2_tex_acquire(cache,GPU_VRAM,128,511*64+63);assert(old);old_id=a2_tex_region(old).id;
 GPU_VRAM[511*1024+239]=0x6543;a2_tex_written(cache,239,511,1,1);
 next=a2_tex_acquire(cache,GPU_VRAM,128,511*64+63);assert(next&&a2_tex_region(next).id!=old_id);
 assert(a2_tex_sample(old,0,0,0)==0x4321&&a2_tex_sample(next,0,0,0)==0x6543);a2_tex_release(cache,old);a2_tex_release(cache,next);
 /* Only the final wrapped direct-color page tile changes. */
 GPU_VRAM[511*1024+191]=0x1122;a2_tex_written(cache,191,511,1,1);
 old=a2_tex_acquire(cache,GPU_VRAM,287,0);old_id=a2_tex_region(old).id;
 GPU_VRAM[511*1024+191]=0x3344;a2_tex_written(cache,191,511,1,1);
 next=a2_tex_acquire(cache,GPU_VRAM,287,0);assert(next&&a2_tex_region(next).id!=old_id);
 assert(a2_tex_sample(old,0,255,255)==0x1122&&a2_tex_sample(next,0,255,255)==0x3344);a2_tex_release(cache,old);a2_tex_release(cache,next);
 /* Fill wrapping both axes; nativecopy retains sequential overlapping order. */
 old=a2_tex_acquire(cache,GPU_VRAM,287,0);assert(old);old_id=a2_tex_region(old).id;
 for(unsigned y=0;y<20;y++)for(unsigned x=0;x<40;x++)GPU_VRAM[((500+y)&511)*1024+((1010+x)&1023)]=(uint16_t)(x+y*317);
 a2_tex_written(cache,1010,500,40,20);next=a2_tex_acquire(cache,GPU_VRAM,287,0);assert(next&&a2_tex_region(next).id!=old_id);check(next,287,0,0,65536);a2_tex_release(cache,old);a2_tex_release(cache,next);
 old=a2_tex_acquire(cache,GPU_VRAM,287,0);old_id=a2_tex_region(old).id;
 for(unsigned y=0;y<7;y++)for(unsigned x=0;x<64;x++)GPU_VRAM[((509+y)&511)*1024+((995+x)&1023)]=GPU_VRAM[((508+y)&511)*1024+((993+x)&1023)];
 a2_tex_written(cache,995,509,64,7);next=a2_tex_acquire(cache,GPU_VRAM,287,0);assert(next&&a2_tex_region(next).id!=old_id);check(next,287,0,0,65536);a2_tex_release(cache,old);a2_tex_release(cache,next);
 a2_tex_destroy(cache);
}
static void bounded_capacity(void){
 assert(!a2_tex_create(0,4)&&!a2_tex_create(4096,0)&&!a2_tex_create(4096,4097));
 A2TexCache *c=a2_tex_create(131072,2);assert(c);
 const A2TexVersion *a=a2_tex_acquire(c,GPU_VRAM,256,0);assert(a);uint16_t before=a2_tex_sample(a,0,0,0);
 assert(!a2_tex_acquire(c,GPU_VRAM,257,0));assert(a2_tex_sample(a,0,0,0)==before);
 a2_tex_release(c,a);a=a2_tex_acquire(c,GPU_VRAM,257,0);assert(a);assert(a2_tex_stats(c).peak_bytes==131072);a2_tex_release(c,a);a2_tex_destroy(c);
 c=a2_tex_create(1048576,2);a=a2_tex_acquire(c,GPU_VRAM,256,0);const A2TexVersion *b=a2_tex_acquire(c,GPU_VRAM,257,0);assert(a&&b);
 assert(!a2_tex_acquire(c,GPU_VRAM,258,0));a2_tex_release(c,b);b=a2_tex_acquire(c,GPU_VRAM,258,0);assert(b);a2_tex_release(c,b);a2_tex_release(c,a);a2_tex_destroy(c);
 c=a2_tex_create(16,2);assert(!a2_tex_acquire(c,GPU_VRAM,0,0));a2_tex_destroy(c);
}
int main(void){all_formats();invalidation_and_leases();bounded_capacity();printf("PASS: %llu native texture samples, formats/pages/window/wrap, invalidation, immutable leases, reset/epoch overflow and capacity\n",(unsigned long long)samples);}
