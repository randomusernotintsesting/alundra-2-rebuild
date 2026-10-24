/* Real GP0 transport and raster writes exercise prompt source invalidation.
 * No SDL app, guest execution, disc/archive, or original save files. */
#include "input_prompts.h"
#include "psx_rt.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef struct { unsigned kind,language,u,v,width,height,bpp;const uint8_t *pixels,*palette; } PromptTextureSource;
#include "../assets/input_prompt_sources.h"
uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
void gpu_gp0(uint32_t word);
uint32_t psx_frame_no,gpu_flips;
void psx_vblank_tick(void) {}
uint32_t psx_mmio_read(uint32_t address,int width) { (void)address;(void)width;return 0; }
int a2_modelcap_active(void) { return 0; }
FILE *a2_modelcap_file(void) { return NULL; }
A2InputSource a2_input_source(void) { return A2_INPUT_KEYBOARD; }
uint32_t a2_input_prompt_generation(void) { return 1; }
int a2_input_prompts_for_bit(int bit,A2InputPrompt out[2]) {
    memset(out,0,2*sizeof *out);out[0].glyph=A2_GLYPH_KEY;
    snprintf(out[0].label,sizeof out[0].label,"Key %d",bit);return 1;
}
void a2_input_menu_chord_prompt(char *out,size_t size) { snprintf(out,size,"Back + Start"); }
static uint32_t xy(unsigned x,unsigned y) { return x|(uint32_t)y<<16; }
static void upload(unsigned x,unsigned y,unsigned width,unsigned height,const uint16_t *pixels) {
    assert(!(width*height%2));
    gpu_gp0(0xa0000000);gpu_gp0(xy(x,y));gpu_gp0(xy(width,height));
    for(unsigned i=0;i<width*height;i+=2)gpu_gp0(pixels[i]|(uint32_t)pixels[i+1]<<16);
}
static void copy(unsigned sx,unsigned sy,unsigned dx,unsigned dy,unsigned width,unsigned height) {
    gpu_gp0(0x80000000);gpu_gp0(xy(sx,sy));gpu_gp0(xy(dx,dy));gpu_gp0(xy(width,height));
}
static void sprite(unsigned color) {
    gpu_gp0(0x64000000|color);gpu_gp0(xy(40,388));gpu_gp0(0x78380000|0x6000);gpu_gp0(xy(80,32));
}
static void expect(int present) {
    A2CinemaRaster raster={0,0,320,480,0,0,320,480,1,4};A2PromptFrame frame;
    a2_input_prompts_frame(&raster,0,&frame);
    assert((frame.count==1)==present);
    if(present)assert(frame.panels[0].kind==A2_PROMPT_CONFIRM);
}
static void expect_controller(int present) {
    A2CinemaRaster raster={0,0,320,460,0,20,320,480,1,4};A2PromptFrame frame;
    a2_input_prompts_frame(&raster,0,&frame);
    assert((frame.count==1)==present);
    if(present)assert(frame.panels[0].kind==A2_PROMPT_CONTROLLER);
}
static void controller_sprite(void) {
    gpu_gp0(0xe10002b9);
    gpu_gp0(0x64808080);gpu_gp0(xy(57,50));gpu_gp0(0x78300000);gpu_gp0(xy(208,255));
}
static void controller_lifetime(void) {
    const PromptTextureSource *source=NULL;
    for(unsigned i=0;i<sizeof prompt_texture_sources/sizeof *prompt_texture_sources;i++)
        if(prompt_texture_sources[i].kind==A2_PROMPT_CONTROLLER)source=prompt_texture_sources+i;
    assert(source&&source->width==208&&source->height==255&&source->bpp==8);
    uint16_t atlas[104*255]={0},palette[256];
    for(unsigned i=0;i<208*255;i++)atlas[i/2]|=(uint16_t)source->pixels[i]<<((i%2)*8);
    for(unsigned i=0;i<256;i++)palette[i]=source->palette[i*2]|source->palette[i*2+1]<<8;
    upload(576,256,104,255,atlas);upload(768,480,256,1,palette);
    controller_sprite();
    /* Actual KeyConfig's nine original leader boxes follow the controller.
     * Use a GP0 polygon at the retained Attack box134,176..206,200. It must
     * not revoke a fresh observation before the first complete presentation. */
    gpu_gp0(0x28010101);gpu_gp0(xy(134,176));gpu_gp0(xy(206,176));
    gpu_gp0(xy(134,200));gpu_gp0(xy(206,200));
    expect_controller(1);expect_controller(1);expect_controller(1);
    /* Its next destination write expires that presented surface immediately. */
    gpu_gp0(0x4000ff00);gpu_gp0(xy(8,50));gpu_gp0(xy(9,50));
    expect_controller(0);
    controller_sprite();expect_controller(1);
    copy(0,0,16,64,16,2);expect_controller(0);
    controller_sprite();expect_controller(1);
    gpu_gp0(0x02000000);gpu_gp0(xy(16,64));gpu_gp0(xy(16,2));expect_controller(0);
    controller_sprite();expect_controller(1);
    uint16_t unchanged[2]={0,0};upload(16,64,2,1,unchanged);expect_controller(0);
    controller_sprite();expect_controller(1);
    gpu_gp0(0x28010101);gpu_gp0(xy(134,176));gpu_gp0(xy(206,176));
    gpu_gp0(xy(134,200));gpu_gp0(xy(206,200));expect_controller(0);
    controller_sprite();expect_controller(1);
    upload(768,480,256,1,palette);expect_controller(0); /* identical source write */
}
int main(void) {
    a2_input_prompts_init(PSX_RAM,sizeof PSX_RAM);a2_input_prompts_configure(2);
    const PromptTextureSource *source=NULL;
    for(unsigned i=0;i<sizeof prompt_texture_sources/sizeof *prompt_texture_sources;i++) {
        const PromptTextureSource *s=prompt_texture_sources+i;
        if(s->language==2&&s->kind==A2_PROMPT_CONFIRM)source=s;
    }
    assert(source&&source->width==80&&source->height==32&&source->bpp==4);
    uint16_t atlas[20*32]={0},palette[16];
    for(unsigned i=0;i<80*32;i++)atlas[i/4]|=(uint16_t)source->pixels[i]<<((i%4)*4);
    for(unsigned i=0;i<16;i++)palette[i]=source->palette[i*2]|source->palette[i*2+1]<<8;
    gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|1023|(511u<<10));gpu_gp0(0xe1000039);
    upload(576,352,20,32,atlas);upload(896,480,16,1,palette);
    sprite(0x808080);expect(1);expect(1); /* unchanged native display persists */
    sprite(0x404040);expect(0); /* original modulation/fade stays original */
    gpu_gp0(0xe2000001);sprite(0x808080);expect(0);gpu_gp0(0xe2000000);
    gpu_gp0(0xe3000000|41);sprite(0x808080);expect(0);gpu_gp0(0xe3000000);
    sprite(0x808080);expect(1);

    /* Fill, copy and CPU upload all invalidate the observed CLUT identity. */
    gpu_gp0(0x02000000);gpu_gp0(xy(896,480));gpu_gp0(xy(16,1));
    sprite(0x808080);expect(0);upload(896,480,16,1,palette);sprite(0x808080);expect(1);
    copy(0,0,896,480,16,1);sprite(0x808080);expect(0);
    upload(896,480,16,1,palette);sprite(0x808080);expect(1);
    palette[3]^=1;upload(896,480,16,1,palette);sprite(0x808080);expect(0);
    palette[3]^=1;upload(896,480,16,1,palette);sprite(0x808080);expect(1);

    /* A drawn line and triangle may alter palette RAM too. */
    gpu_gp0(0x4000ff00);gpu_gp0(xy(896,480));gpu_gp0(xy(911,480));
    sprite(0x808080);expect(0);upload(896,480,16,1,palette);sprite(0x808080);expect(1);
    gpu_gp0(0x200000ff);gpu_gp0(xy(896,479));gpu_gp0(xy(912,479));gpu_gp0(xy(896,483));
    sprite(0x808080);expect(0);upload(896,480,16,1,palette);sprite(0x808080);expect(1);
    atlas[0]^=1;upload(576,352,20,32,atlas);sprite(0x808080);expect(0);
    atlas[0]^=1;upload(576,352,20,32,atlas);sprite(0x808080);expect(1);
    controller_lifetime();
    a2_input_prompts_close();
    puts("PASS real GP0 exact sprite, modulation/window/clip guards and upload/copy/fill/line/triangle palette+atlas invalidation");
    return 0;
}
