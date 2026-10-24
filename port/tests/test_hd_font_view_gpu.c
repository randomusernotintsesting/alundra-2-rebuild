/* Actual GP0 font path: prepare coverage once without changing any pixel. */
#define A2_HD_FONT_VIEW_TEST 1
static int font_view_reference;
static unsigned font_view_uses;
#define main old_hd_gpu_main
#include "test_hd_gpu.c"
#undef main
static uint16_t ref_native[1024*512],ref_fine[256*256];
static uint32_t ref_rgb[256*256];
static void font_setup(int height,int latin,unsigned mode,int clip) {
 gpu_gp1(0);memset(GPU_VRAM,0,sizeof GPU_VRAM);
 gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|(clip?10:63)|((clip?9:63)<<10));
 unsigned page=(0x23e&~0x60)|(mode<<5);gpu_gp0(0xe1000000|page);
 const uint8_t *bank=(height==16?a2_hd_sources16:a2_hd_sources24)[latin].bank;
 sw_(0x800640f0,height==16?0:2);sw_(0x8014c880,0x8014c888);
 memcpy(PSX_RAM+(height==16?0x65b60:0x14c888),bank,height==16?sizeof a2_hd_bank16:sizeof a2_hd_bank24);
 const uint8_t *record=bank+(0x61-32)*(height*3+1);
 for(int y=0;y<height;y++)for(int w=0;w<3;w++) {
  unsigned b=record[y*3+w];GPU_VRAM[(280+y)*1024+896+w]=((b>>6)&3)|(((b>>4)&3)<<4)|(((b>>2)&3)<<8)|((b&3)<<12);
 }
 unsigned pal=(0x767f>>6)*1024+(0x767f&63)*16;
 GPU_VRAM[pal]=0;GPU_VRAM[pal+1]=0x819f;GPU_VRAM[pal+2]=0x03e0;GPU_VRAM[pal+3]=0x8000;
 a2_hd_guest_note(0xff61,896,0,24);
 assert(a2_hd_font_match(GPU_VRAM,page,0,24,5,height));
 for(int y=0;y<64*IR;y++)for(int x=0;x<64*IR;x++) {
  SHADOW[(size_t)y*IR_W+x]=(uint16_t)((x+y*97)*37u);
  if(SHADOW_RGB)SHADOW_RGB[(size_t)y*IR_W+x]=0xff000000u|(((x+y*97)*123457u)&0xffffff);
 }
}
static void font_draw(int height,int semi) {
 gpu_gp0((semi?0x66000000:0x64000000)|0xa17349);gpu_gp0(xy(8,8));
 gpu_gp0((0x767fu<<16)|(24<<8));gpu_gp0(xy(5,height));
}
#ifndef A2_FONT_VIEW_FIXTURE_ONLY
int main(void) {
 setenv("A2_HDUI","1",1);setenv("A2_COLOR_PRECISION","1",1);setenv("A2_IRSCALE","4",1);gpu_ir();unsigned cases=0;
 for(int scale=2;scale<=4;scale++)for(int rgb=0;rgb<2;rgb++) {
  gpu_set_ir(scale);uint32_t *plane=SHADOW_RGB;if(!rgb)SHADOW_RGB=NULL;
  for(int height=16;height<=24;height+=8)for(int latin=0;latin<2;latin++)for(unsigned mode=0;mode<4;mode++)for(int semi=0;semi<2;semi++)for(int clip=0;clip<2;clip++) {
   for(int pass=0;pass<2;pass++) {
    font_view_reference=!pass;font_setup(height,latin,mode,clip);unsigned prior=font_view_uses;font_draw(height,semi);
    if(!pass)memcpy(ref_native,GPU_VRAM,sizeof GPU_VRAM);else assert(!memcmp(ref_native,GPU_VRAM,sizeof GPU_VRAM));
    for(int y=0;y<64*IR;y++)for(int x=0;x<64*IR;x++) {
     size_t d=(size_t)y*IR_W+x,i=y*256+x;
     if(!pass){ref_fine[i]=SHADOW[d];if(rgb)ref_rgb[i]=SHADOW_RGB[d];}
     else{assert(ref_fine[i]==SHADOW[d]);if(rgb)assert(ref_rgb[i]==SHADOW_RGB[d]);}
    }
    if(pass)assert(font_view_uses>prior);
   }
   cases++;
  }
  SHADOW_RGB=plane;
 }
 printf("PASS: %u GP0 glyph pairs, prepared uses=%u; IR2-4,RU/Latin,16/24px,RGBoff/on,allblends,STPblack andclipping\n",cases,font_view_uses);
 return 0;
}
#endif
