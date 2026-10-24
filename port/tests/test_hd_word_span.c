/* Real GP0 rectangle with a source-checked word plate inside larger HD art. */
#define A2_HD_RECT_TEST 1
static int hd_rect_reference;
static unsigned hd_rect_fast_calls;
#define main original_hd_main
#include "test_hd_art_gpu.c"
#undef main
static uint8_t panel[136*128];
static uint16_t saved_native[1024*512];
int main(void) {
 const A2HDPlate *word=&a2_hd_plates[4];assert(word->u==16&&word->v==56);
 memset(panel,1,sizeof panel);
 for(unsigned y=0;y<word->height;y++)memcpy(panel+y*136+word->u,word->source+y*word->width,word->width);
 for(unsigned i=0;i<136*128*16;i++)large_pixels[i]=((i%3==0?0u:i%3==1?255u:173u)<<24)|((i*37u&255)<<16)|((i%16)<<8)|(i%31);
 for(unsigned i=0;i<256;i++)colors[i]=(uint16_t)(i?i*73u|((i&1)?0x8000:0):0);
 colors[14]=0x8000; /* Black STP text must still execute its coverage. */
 setenv("A2_COLOR_PRECISION","1",1);setenv("A2_IRSCALE","4",1);gpu_ir();
 uint16_t *ref16=malloc(1024*512*16*2);uint32_t *ref32=malloc(1024*512*16*4);assert(ref16&&ref32);
 unsigned cases=0;
 for(int scale=2;scale<=4;scale+=2)for(int rgb=0;rgb<2;rgb++)for(unsigned mode=0;mode<4;mode++)for(int semi=0;semi<2;semi++) {
  gpu_set_ir(scale);size_t count=(size_t)IR_W*IR_H;uint32_t *plane=SHADOW_RGB;if(!rgb)SHADOW_RGB=NULL;
  for(int pass=0;pass<2;pass++) {
   hd_rect_reference=!pass;setup(1,4,mode);
   a2_hd_art_assets[0]=(A2HDArt){0,56,136,128,4,panel,large_pixels};upload(&a2_hd_art_assets[0],10|(mode<<5));
   gpu_gp0(0xe4000000|191|(191<<10));
   for(size_t i=0;i<count;i++){SHADOW[i]=(uint16_t)(i*37u);if(rgb)SHADOW_RGB[i]=0xff000000u|((i*1234567u)&0xffffff);}
   unsigned prior=hd_rect_fast_calls;rect(0,56,136,128,0xa78163,semi);
   if(!pass){memcpy(saved_native,GPU_VRAM,sizeof GPU_VRAM);memcpy(ref16,SHADOW,count*2);if(rgb)memcpy(ref32,SHADOW_RGB,count*4);}
   else {assert(!memcmp(saved_native,GPU_VRAM,sizeof GPU_VRAM));assert(!memcmp(ref16,SHADOW,count*2));if(rgb)assert(!memcmp(ref32,SHADOW_RGB,count*4));assert(hd_rect_fast_calls>prior);}
  }
  SHADOW_RGB=plane;cases++;
 }
 printf("PASS: %u full-buffer word-on-art cases including transparent art, black STP text, RGB off/on and all blend modes\n",cases);
 free(ref16);free(ref32);return 0;
}
