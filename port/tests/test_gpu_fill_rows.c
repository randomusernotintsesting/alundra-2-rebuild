/* Full-plane GP0 fill contract, including native VRAM wrapping. */
#define A2_GPU_FILL_ROWS_TEST 1
static int fill_rows_reference;
static unsigned fill_rows_uses;
#define main old_display_main
#include "test_gpu_display_row.c"
#undef main
static uint16_t ref_native[1024*512];
static const unsigned fills[][4]={
 {0,0,320,480},{1007,509,33,8},{17,255,1023,511},
 {1023,511,1,1},{0,0,0,10},{0,0,16,0},{1008,510,1023,511}
};
static void fill_draw(const unsigned *a) {
 gpu_gp0(0x021d476b);gpu_gp0(a[0]|(a[1]<<16));gpu_gp0(a[2]|(a[3]<<16));
}
#ifndef A2_FILL_ROWS_FIXTURE_ONLY
int main(void) {
 setenv("A2_COLOR_PRECISION","1",1);setenv("A2_IRSCALE","4",1);gpu_ir();unsigned cases=0;
 for(int scale=2;scale<=4;scale++)for(int rgb=0;rgb<2;rgb++) {
  gpu_set_ir(scale);size_t count=(size_t)IR_W*IR_H;
  uint16_t *fine=malloc(count*2);uint32_t *color=malloc(count*4),*plane=SHADOW_RGB;assert(fine&&color);
  if(!rgb)SHADOW_RGB=NULL;
  for(unsigned c=0;c<sizeof fills/sizeof fills[0];c++) {
   for(int pass=0;pass<2;pass++) {
    gpu_gp1(0);gpu_gp0(0xe3000000|40|(40<<10));gpu_gp0(0xe4000000|41|(41<<10));gpu_gp0(0xe5000000|100|(100<<11));gpu_gp0(0xe6000003);
    for(size_t i=0;i<1024*512;i++)GPU_VRAM[i]=(uint16_t)(i*71);
    for(size_t i=0;i<count;i++){SHADOW[i]=(uint16_t)(i*97);if(rgb)SHADOW_RGB[i]=0xff000000u|((i*1234567)&0xffffff);}
    fill_rows_reference=!pass;unsigned prior=fill_rows_uses;fill_draw(fills[c]);
    if(!pass){memcpy(ref_native,GPU_VRAM,sizeof GPU_VRAM);memcpy(fine,SHADOW,count*2);if(rgb)memcpy(color,SHADOW_RGB,count*4);}
    else {assert(!memcmp(ref_native,GPU_VRAM,sizeof GPU_VRAM));assert(!memcmp(fine,SHADOW,count*2));if(rgb)assert(!memcmp(color,SHADOW_RGB,count*4));assert(fill_rows_uses>prior);}
   }
   cases++;
  }
  SHADOW_RGB=plane;free(fine);free(color);
 }
 printf("PASS: %u complete native/555/888 GP0 fill pairs, IR2-4,RGBoff/on,wrap,zero areas,rounded width,ignored masks/clip/offset\n",cases);return 0;
}
#endif
