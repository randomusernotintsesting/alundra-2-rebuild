/* Independent8bit oracle through real HD-art GP0 sampling/composition. */
#define main legacy_hd_art_main
#include "test_hd_art_gpu.c"
#undef main
static uint32_t shade8(uint32_t before,uint16_t texel,unsigned col,int semi,unsigned mode) {
 if(!texel)return before;
 uint32_t out=0xff000000u;
 for(unsigned c=0;c<3;c++) {
  unsigned shift=16-8*c;
  int a=(before>>shift)&255,z=(((texel>>(5*c))&31)*8)*((col>>(8*c))&255)/128;
  if(z>255)z=255;
  if(semi&&(texel&0x8000)) {
   if(mode==0)z=(a+z)/2;else if(mode==1)z=a+z;else if(mode==2)z=a-z;else z=a+z/4;
  }
  if(z<0)z=0;if(z>255)z=255;out|=(unsigned)z<<shift;
 }
 return out;
}
static uint32_t cover8(uint32_t a,uint32_t b,unsigned coverage) {
 uint32_t result=0xff000000u;
 for(unsigned shift=0;shift<24;shift+=8)
  result|=(((((a>>shift)&255)*(255-coverage)+((b>>shift)&255)*coverage+127)/255)<<shift);
 return result;
}
static uint32_t art8(uint32_t before,uint32_t pixel,unsigned col,int semi,unsigned mode) {
 uint32_t first=shade8(before,colors[pixel&255],col,semi,mode),second=shade8(before,colors[(pixel>>8)&255],col,semi,mode);
 return cover8(before,cover8(first,second,(pixel>>16)&255),pixel>>24);
}
int main(void) {
 setenv("A2_COLOR_PRECISION","1",1);setenv("A2_IRSCALE","4",1);gpu_ir();pattern();
 const uint32_t before=0xff172533u,col=0x91634b;
 for(unsigned bpp=4;bpp<=8;bpp+=4)for(unsigned mode=0;mode<4;mode++)
 for(int semi=0;semi<=1;semi++)for(unsigned state=0;state<4;state++) {
  colors[4]=state&1?0:0x819f;colors[5]=state&2?0x8000:0xfc00;
  setup(1,bpp,mode);
  gpu_gp0(0x60332517);gpu_gp0(xy(8,8));gpu_gp0(xy(2,2));
  rect(8,16,2,2,col,semi);
  for(unsigned y=0;y<8;y++)for(unsigned x=0;x<8;x++) {
   uint32_t actual=gpu_display_argb_row(32+y)[32+x],wanted=art8(before,pixels[y*8+x],col,semi,mode);
   if(actual!=wanted)fprintf(stderr,"HD ARGB bpp=%u mode=%u semi=%d state=%u xy=%u,%u got=%08x want=%08x\n",bpp,mode,semi,state,x,y,actual,wanted);
   assert(actual==wanted);
  }
 }
 /* Direct font coverage shares the same original RGB background. */
 for(unsigned mode=0;mode<4;mode++)for(int semi=0;semi<2;semi++)for(unsigned a=0;a<=255;a+=17) {
  setup(0,4,mode);gpu_gp0(0x60332517);gpu_gp0(xy(8,8));gpu_gp0(xy(2,2));
  put_font_coverage(32,32,75,99,145,semi,0x879f,a);
  assert(gpu_display_argb_row(32)[32]==cover8(before,shade8(before,0x879f,col,semi,mode),a));
 }
 puts("PASS: HD art RGB against independent oracle,4/8bpp,all blendmodes,STP black,transparent texels,mixture/coverage and font alpha");
 return 0;
}
