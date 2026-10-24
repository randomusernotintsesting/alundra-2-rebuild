/* Differential GP0 test: preserve native and both presentation planes. */
#define A2_HD_RECT_TEST 1
#define A2_HD_PALETTE_TEST 1
static int hd_rect_reference;
static unsigned hd_rect_fast_calls;
static unsigned hd_rect_shading_calls;
static unsigned hd_rect_palette_calls;
#define main original_hd_main
#include "test_hd_art_gpu.c"
#undef main
static uint16_t saved_native[1024*512], saved_fine[64*64];
static uint32_t saved_rgb[64*64];
static unsigned seed=123456789;
static unsigned random_word(void) { seed=seed*1664525u+1013904223u;return seed; }
static void snapshot(int compare) {
 if(compare)assert(!memcmp(saved_native,GPU_VRAM,sizeof GPU_VRAM));
 else memcpy(saved_native,GPU_VRAM,sizeof GPU_VRAM);
 for(int y=0;y<64;y++)for(int x=0;x<64;x++) {
  uint16_t a=gpu_display_px(x,y);const uint32_t *row=gpu_display_argb_row(y);
  if(compare){assert(saved_fine[y*64+x]==a);if(row)assert(saved_rgb[y*64+x]==row[x]);}
  else {saved_fine[y*64+x]=a;if(row)saved_rgb[y*64+x]=row[x];}
 }
}
static void repeated_and_wrapped(void) {
 uint16_t *ref16=malloc(1024*512*16*2);uint32_t *ref32=malloc(1024*512*16*4);assert(ref16&&ref32);
 static uint8_t indices[512];for(unsigned i=0;i<512;i++)indices[i]=i%16;
 for(unsigned i=0;i<8192;i++)large_pixels[i]=random_word();
 for(int scale=2;scale<=4;scale+=2)for(unsigned trial=0;trial<16;trial++) {
  gpu_set_ir(scale);size_t count=(size_t)IR_W*IR_H;
  for(int pass=0;pass<2;pass++) {
   hd_rect_reference=!pass;setup(1,4,trial%4);
   unsigned prior=hd_rect_fast_calls;
   if(trial&1) {a2_hd_art_assets[0]=(A2HDArt){8,16,8,8,4,indices,large_pixels};upload(&a2_hd_art_assets[0],10|((trial%4)<<5));gpu_gp0(0xe2000000|31|(31<<5)|(1<<10)|(2<<15));}
   else {a2_hd_art_assets[0]=(A2HDArt){0,16,256,2,4,indices,large_pixels};upload(&a2_hd_art_assets[0],10|((trial%4)<<5));}
   if(trial&2)gpu_gp0(0xe3000000|12|(9<<10));
   if(trial&8) {
    for(unsigned i=0;i<256;i++)GPU_VRAM[500*1024+((1008+i)&1023)]=colors[i];
    gpu_gp0((trial&4?0x66000000:0x64000000)|0xe49729);gpu_gp0(xy(8,8));
    gpu_gp0((((500u<<6)|63)<<16)|(16<<8)|250);gpu_gp0(xy(40,(trial&1)?70:2));
   } else rect(250,16,40,(trial&1)?70:2,0xe49729,trial&4);
   if(!pass){memcpy(saved_native,GPU_VRAM,sizeof GPU_VRAM);memcpy(ref16,SHADOW,count*2);memcpy(ref32,SHADOW_RGB,count*4);}
   else {assert(!memcmp(saved_native,GPU_VRAM,sizeof GPU_VRAM));assert(!memcmp(ref16,SHADOW,count*2));assert(!memcmp(ref32,SHADOW_RGB,count*4));assert(hd_rect_fast_calls>prior);}
  }
 }
 /* Horizontally empty clipping must not form pointers using an out-of-asset
    starting X while the Y loop would otherwise remain nonempty. */
 for(int side=0;side<2;side++)for(int pass=0;pass<2;pass++) {
  hd_rect_reference=!pass;setup(1,4,0);
  gpu_gp0(0xe3000000|40);gpu_gp0(0xe4000000|63|(127<<10));
  gpu_gp0(0x64808080);gpu_gp0(xy(side?90:8,8));gpu_gp0((500u<<22)|(16<<8)|8);gpu_gp0(xy(2,2));
  snapshot(pass);
 }
 free(ref16);free(ref32);
}
static void large_panel_palette_changes(void) {
 static uint8_t indices[16*16];
 static uint16_t before16[128*128];static uint32_t before32[128*128];
 for(unsigned i=0;i<sizeof indices;i++)indices[i]=(uint8_t)i;
 for(unsigned i=0;i<16*16*16;i++)large_pixels[i]=random_word();
 gpu_set_ir(4);
 for(unsigned trial=0;trial<24;trial++) {
  for(unsigned i=0;i<256;i++)colors[i]=(uint16_t)random_word();
  colors[0]=0;colors[1]=0x8000;
  unsigned col=random_word()&0xffffff,mode=trial&3,semi=(trial>>2)&1;
  for(int pass=0;pass<2;pass++) {
   hd_rect_reference=!pass;setup(1,8,mode);
   a2_hd_art_assets[0]=(A2HDArt){8,16,16,16,8,indices,large_pixels};
   upload(&a2_hd_art_assets[0],10|0x80|(mode<<5));
   hd_rect_shading_calls=hd_rect_palette_calls=0;
   rect(8,16,16,16,col,semi);
   /* Change both CLUT and vertex color between commands. A cross-command
      prepared palette would produce stale colors on this second blend. */
   for(unsigned i=0;i<256;i++)GPU_VRAM[500*1024+i]^=(uint16_t)(0x8421u+i*17u);
   rect(8,16,16,16,col^0x948163,semi);
   unsigned work=hd_rect_shading_calls+hd_rect_palette_calls;
   if(pass)assert(!memcmp(saved_native,GPU_VRAM,sizeof GPU_VRAM));
   else memcpy(saved_native,GPU_VRAM,sizeof GPU_VRAM);
   for(int y=0;y<128;y++)for(int x=0;x<128;x++) {
    size_t n=(size_t)y*IR_W+x,k=(size_t)y*128+x;
    if(pass){assert(SHADOW[n]==before16[k]);assert(SHADOW_RGB[n]==before32[k]);}
    else {before16[k]=SHADOW[n];before32[k]=SHADOW_RGB[n];}
   }
   if(pass&&work>512) {
    fprintf(stderr,"large HD panels repeat scalar shading/preparation: %u calls (budget512)\n",work);
    exit(1);
   }
  }
 }
}
/* Catches stale command palettes, reordered/recursive semi blends, lost words
 * over uncovered art and repeated modulation beneath actual authored letters. */
static void large_panel_words(void) {
 const A2HDPlate *p=&a2_hd_plates[0];
 uint16_t *ref16=malloc(1024*512*16*2);
 uint32_t *ref32=malloc(1024*512*16*4);assert(ref16&&ref32);
 assert(p->width==72&&p->height==24);
 for(int scale=2;scale<=4;scale+=2)for(unsigned trial=0;trial<16;trial++) {
  gpu_set_ir(scale);size_t count=(size_t)IR_W*IR_H;
  for(unsigned i=0;i<256;i++)colors[i]=(uint16_t)random_word();
  colors[p->ink_index]=(trial&8)?0:0x8000;
  colors[p->shadow_index]=(trial&8)?0x83e0:0;
  for(unsigned i=0;i<p->width*p->height*16;i++) {
   unsigned alpha=i%4==0?0:i%4==1?255:(random_word()&255);
   unsigned mix=i%4==2?0:i%4==3?255:(random_word()&255);
   large_pixels[i]=(alpha<<24)|(mix<<16)|(random_word()&65535);
  }
  unsigned col=random_word()&0xffffff,mode=trial&3,semi=(trial>>2)&1;
  for(int pass=0;pass<2;pass++) {
   hd_rect_reference=!pass;setup(1,4,mode);
   a2_hd_art_assets[0]=(A2HDArt){p->u,p->v,p->width,p->height,4,p->source,large_pixels};
   upload(&a2_hd_art_assets[0],10|(mode<<5));
   if(trial&8)gpu_gp0(0xe3000000|13|(10<<10));
   hd_rect_shading_calls=hd_rect_palette_calls=0;
   rect(p->u,p->v,p->width,p->height,col,semi);
   const A2HDPlate *found[128];
   assert(a2_hd_ui_prepare(GPU_VRAM,10|(mode<<5),p->u,p->v,p->u+p->width-1,p->v+p->height-1,found,128)>0);
   for(unsigned i=0;i<256;i++)GPU_VRAM[500*1024+i]^=(uint16_t)(0x8421u+i*17u);
   rect(p->u,p->v,p->width,p->height,col^0x948163,semi);
   unsigned work=hd_rect_shading_calls+hd_rect_palette_calls;
   if(!pass){memcpy(saved_native,GPU_VRAM,sizeof GPU_VRAM);memcpy(ref16,SHADOW,count*2);memcpy(ref32,SHADOW_RGB,count*4);}
   else {
    assert(!memcmp(saved_native,GPU_VRAM,sizeof GPU_VRAM));
    assert(!memcmp(ref16,SHADOW,count*2));assert(!memcmp(ref32,SHADOW_RGB,count*4));
    if(work>512){fprintf(stderr,"HD panel words repeat shading: %u calls (budget512)\n",work);exit(1);}
   }
  }
 }
 free(ref16);free(ref32);
}
int main(void) {
 setenv("A2_COLOR_PRECISION","1",1);setenv("A2_IRSCALE","4",1);gpu_ir();
 for(int scale=2;scale<=4;scale++) {
  gpu_set_ir(scale);assert(gpu_ir()==scale);
  for(unsigned trial=0;trial<192;trial++) {
   for(unsigned i=0;i<64;i++)pixels[i]=random_word();
   for(unsigned i=0;i<256;i++)colors[i]=(uint16_t)random_word();
   colors[0]=0;colors[1]=0x8000;
   unsigned col=random_word()&0xffffff,bpp=(trial&1)?4:8,mode=(trial>>1)&3;
   int semi=(trial>>3)&1;
   for(int pass=0;pass<2;pass++) {
    unsigned prior=hd_rect_fast_calls;hd_rect_reference=!pass;setup(1,bpp,mode);
    if(trial%8==0)GPU_VRAM[500*1024+7]^=0x8421; /* live palette changes */
    if(trial%8==1)GPU_VRAM[17*1024+642]^=1; /* whole-source guard */
    if(trial%8==2)gpu_gp0(0xe4000000|8|(8<<10));
    if(trial%8==3)gpu_gp0(0xe2000000|1|(2<<5)|(1<<10)|(2<<15));
    if(trial%8==4)a2_hd_art_assets[1]=a2_hd_art_assets[0]; /* priority/fallback */
    unsigned u=trial%8==3?0:trial%8==5?255:8,v=trial%8==3?0:16;
    rect(u,v,trial%8==6?1:2,2,col,semi);
    rect(u,v,2,1,col^0x332211,semi); /* repeated blending on varied background */
    snapshot(pass);
    if(pass && trial%8==3 && scale!=3)assert(hd_rect_fast_calls>prior);
   }
  }
 }
 repeated_and_wrapped();
 large_panel_palette_changes();
 large_panel_words();
 assert(hd_rect_fast_calls>0); /* Baseline must fail: no optimized spans yet. */
 printf("PASS: %u optimized spans; 576 paired GP0 cases,32 full-buffer tiled/wrapped cases,24 large-panel live-palette cases,32 real-word panels; IR2-4, source rejection, clipping, windows, UV wrap, overlap priority, repeated blend; modulation/preparation budget512 for two large panels\n",hd_rect_fast_calls);
 return 0;
}
