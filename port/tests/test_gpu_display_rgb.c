/* End-to-end GP0 contracts for optional full-precision presentation. */
#define main old_display_fixture_main
#include "test_gpu_display_row.c"
#undef main
#include "../src/frame_compose.h"
static uint32_t rgba(unsigned r,unsigned g,unsigned b){return 0xff000000u|(r<<16)|(g<<8)|b;}
static void setup(int scale) {
 gpu_set_ir(scale);gpu_gp1(0);gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|1023u|(511u<<10));
 assert(gpu_display_argb_row(0));
}
static void rect(unsigned color,int x,int y,int w,int h,int semi) {
 gpu_gp0((semi?0x62000000u:0x60000000u)|color);gpu_gp0((unsigned)x|((unsigned)y<<16));gpu_gp0((unsigned)w|((unsigned)h<<16));
}
static unsigned blend_ref(unsigned before,unsigned fg,unsigned mode) {
 int value=mode==0?(int)(before+fg)/2:mode==1?(int)(before+fg):mode==2?(int)before-(int)fg:(int)(before+fg/4);
 return value<0?0:value>255?255:(unsigned)value;
}
int main(int argc,char **argv) {
 setenv("A2_COLOR_PRECISION","1",1);
 if(argc>1 && !strcmp(argv[1],"cold")) {
  setenv("A2_IRSCALE","4",1);gpu_gp1(0);
  rect(17,0,0,1,1,1);assert(gpu_display_argb_row(0)[0]==rgba(8,0,0));
  rect(17,0,0,1,1,1);assert(gpu_display_argb_row(0)[0]==rgba(12,0,0));
  puts("PASS: cold first semitransparent GP0 initializes before native write");return 0;
 }
 for(int scale=2;scale<=4;scale++) {
  setup(scale);rect(0x010509,4,5,2,2,0);
  for(int y=5*scale;y<7*scale;y++)for(int x=4*scale;x<6*scale;x++)assert(gpu_display_argb_row(y)[x]==rgba(9,5,1));
  assert(GPU_VRAM[5*1024+4]==1);assert(gpu_display_px(4*scale,5*scale)==1);
  for(unsigned mode=0;mode<4;mode++) {
   gpu_gp0(0xe1000000|(mode<<5));rect(0x8d7b69,4,5,2,2,0);
   unsigned rgb[3]={105,123,141},fg[3]={17,23,37};
   for(int repeat=0;repeat<21;repeat++) {
    rect(17|(23u<<8)|(37u<<16),4,5,2,2,1);
    for(unsigned c=0;c<3;c++)rgb[c]=blend_ref(rgb[c],fg[c],mode);
    assert(gpu_display_argb_row(5*scale)[4*scale]==rgba(rgb[0],rgb[1],rgb[2]));
   }
  }
  /* Upload destroys previous fine precision and mirrors source555 at every subpixel. */
  gpu_gp0(0xa0000000);gpu_gp0(4|(5u<<16));gpu_gp0(2|(1u<<16));gpu_gp0(0x83e0801f);
  for(int y=5*scale;y<6*scale;y++)for(int x=4*scale;x<5*scale;x++)assert(gpu_display_argb_row(y)[x]==rgba(248,0,0));
  /* Copy preserves full precision and the existing forward overlap order. */
  rect(0x030507,4,5,1,1,0);rect(0x0b0d0f,5,5,1,1,0);
  gpu_gp0(0x80000000);gpu_gp0(4|(5u<<16));gpu_gp0(5|(5u<<16));gpu_gp0(2|(1u<<16));
  for(int x=5*scale;x<7*scale;x++)assert(gpu_display_argb_row(5*scale)[x]==rgba(7,5,3));
  /* Fill takes its8bit command color while native VRAM still receives555. */
  gpu_gp0(0x02030507);gpu_gp0(32|(20u<<16));gpu_gp0(16|(1u<<16));
  assert(gpu_display_argb_row(20*scale)[32*scale]==rgba(7,5,3));
  assert(GPU_VRAM[20*1024+32]==0);
  assert(gpu_display_argb_row(-1)==gpu_display_argb_row(512*scale-1));
 }
 setup(4);gpu_gp0(0xe1000000);
 gpu_gp0(0x30000000);gpu_gp0(0);gpu_gp0(0x000000ff);gpu_gp0(256);gpu_gp0(0);gpu_gp0(32u<<16);
 unsigned seen[256]={0},levels=0;for(int x=0;x<1020;x++)seen[(gpu_display_argb_row(0)[x]>>16)&255]=1;
 for(int i=0;i<256;i++)levels+=seen[i];assert(levels>=254);
 uint32_t frame[4096];a2_compose_frame(frame,1024,4,0,0,256,1,0,0,256,1);
 assert(!memcmp(frame,gpu_display_argb_row(0),1024*sizeof *frame));
 gpu_set_ir(1);assert(!gpu_display_argb_row(0));gpu_set_ir(2);
 assert(gpu_display_argb_row(0)[0]==rgba((GPU_VRAM[0]&31)*8,((GPU_VRAM[0]>>5)&31)*8,((GPU_VRAM[0]>>10)&31)*8));
 puts("PASS: full RGB gradient, all blends, native555, uploads, overlap copies, fills, wrapping, resize and composition");
 return 0;
}
