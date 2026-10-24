#include "input_prompts.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct { unsigned kind,language,u,v,width,height,bpp;const uint8_t *pixels,*palette; } PromptTextureSource;
#include "../assets/input_prompt_sources.h"
static uint8_t ram[2*1024*1024];
static uint16_t vram[1024*512];
static A2InputSource input_source=A2_INPUT_KEYBOARD;
static const char *key="Space";
static A2InputGlyph controller_glyph=A2_GLYPH_CROSS;
A2InputSource a2_input_source(void) { return input_source; }
uint32_t a2_input_prompt_generation(void) { return 1; }
int a2_input_prompts_for_bit(int bit,A2InputPrompt out[2]) {
    memset(out,0,2*sizeof *out);out[0].source=input_source;
    out[0].glyph=input_source==A2_INPUT_KEYBOARD?A2_GLYPH_KEY:controller_glyph;
    snprintf(out[0].label,sizeof out[0].label,"%s",input_source==A2_INPUT_CONTROLLER?"×":bit==14?key:"K");
    return 1;
}
void a2_input_menu_chord_prompt(char *out,size_t size) { snprintf(out,size,"Create + Options"); }
static void half(unsigned at,unsigned value) { ram[at]=(uint8_t)value;ram[at+1]=(uint8_t)(value>>8); }
static void load_texture(const PromptTextureSource *s) {
    memset(vram,0,sizeof vram);
    unsigned per_word=16/s->bpp;
    for(unsigned y=0;y<s->height;y++)for(unsigned x=0;x<s->width;x++) {
        unsigned u=s->u+x;
        vram[(256+s->v+y)*1024+576+u/per_word]|=
            (uint16_t)s->pixels[y*s->width+x]<<((u%per_word)*s->bpp);
    }
    unsigned bank=s->kind==A2_PROMPT_CONTROLLER?0:s->kind+8;
    for(unsigned i=0;i<(1u<<s->bpp);i++)
        vram[480*1024+768+bank*16+i]=s->palette[i*2]|s->palette[i*2+1]<<8;
    a2_input_prompts_vram_changed(0,0,1024,512);
}
static void observe(const PromptTextureSource *s) {
    unsigned bank=s->kind==A2_PROMPT_CONTROLLER?0:s->kind+8;
    a2_input_prompts_sprite(vram,s->bpp==8?0x2b9:0x39,0x7830+bank,
        s->kind==A2_PROMPT_CONTROLLER?57:40,s->kind==A2_PROMPT_CONTROLLER?50:388,
        s->width,s->height,s->u,s->v);
}
static void unchanged_gameplay(void) {
    enum { W=640,H=480 };
    uint32_t *pixels=malloc(W*H*4);assert(pixels);
    for(unsigned i=0;i<W*H;i++)pixels[i]=0xff304050u;
    unsigned before=a2_input_prompts_test_raster_count();A2PromptFrame frame;
    A2CinemaRaster raster={0,0,320,216,0,12,320,240,1,4};
    half(0x12789c,213); /* Ordinary gameplay, then visible original tutorial. */
    for(unsigned state=0;state<7;state++) {
        half(0x65600,state);a2_input_prompts_frame(&raster,0,&frame);assert(!frame.count);
        for(unsigned i=0;i<100;i++)a2_input_prompts_compose(pixels,W,2,&raster,0);
        for(unsigned i=0;i<W*H;i++)assert(pixels[i]==0xff304050u);
    }
    raster.overlay=5;a2_input_prompts_compose(pixels,W,2,&raster,0);
    assert(a2_input_prompts_test_raster_count()==before);
    free(pixels);
}

static void retained_presentations(const PromptTextureSource *source) {
    /* Actual KeyConfig5900/5901 retains identical native VRAM across two
     * presentations. The verified native surface must retain its captions. */
    A2CinemaRaster r={0,0,320,460,0,20,320,480,1,4};A2PromptFrame first,again;
    load_texture(source);observe(source);
    a2_input_prompts_frame(&r,0,&first);assert(first.count==1);
    for(unsigned i=0;i<100;i++) {
        a2_input_prompts_frame(&r,0,&again);
        assert(!memcmp(&first,&again,sizeof first));
    }
    a2_input_prompts_vram_changed(400,0,1,1); /* unrelated offscreen write */
    a2_input_prompts_frame(&r,0,&again);assert(again.count==1);
    /* Even an identical write inside the larger replacement panel expires
     * the retained observation, including native leader-label areas. */
    a2_input_prompts_vram_changed(8,50,1,1);
    a2_input_prompts_frame(&r,0,&again);assert(!again.count);
    observe(source);a2_input_prompts_frame(&r,0,&again);assert(again.count==1);
    a2_input_prompts_vram_changed(576,256,1,1);
    a2_input_prompts_frame(&r,0,&again);assert(!again.count);
    observe(source);a2_input_prompts_frame(&r,0,&again);assert(again.count==1);
    r.dy=1;a2_input_prompts_frame(&r,0,&again);assert(!again.count);
    r.dy=0;a2_input_prompts_frame(&r,0,&again);assert(!again.count);
    observe(source);a2_input_prompts_frame(&r,0,&again);assert(again.count==1);
    a2_input_prompts_frame(&r,1,&again);assert(!again.count);
    a2_input_prompts_frame(&r,0,&again);assert(!again.count);
    observe(source);a2_input_prompts_frame(&r,0,&again);assert(again.count==1);
    r.overlay=5;a2_input_prompts_frame(&r,0,&again);assert(!again.count);
    r.overlay=4;a2_input_prompts_frame(&r,0,&again);assert(!again.count);
    observe(source);a2_input_prompts_frame(&r,0,&again);assert(again.count==1);
    r.on=0;a2_input_prompts_frame(&r,0,&again);assert(!again.count);
    r.on=1;a2_input_prompts_frame(&r,0,&again);assert(!again.count);
    observe(source);a2_input_prompts_frame(&r,0,&again);assert(again.count==1);
    r.dh=216;r.ch=216;r.yo=0;
    a2_input_prompts_frame(&r,0,&again);assert(!again.count);
    unchanged_gameplay();
}

#if defined(__APPLE__) && !defined(A2_PROMPTS_PORTABLE)
static void physical_menu_shapes(const PromptTextureSource *controller) {
    input_source=A2_INPUT_CONTROLLER;controller_glyph=A2_GLYPH_CIRCLE;
    A2CinemaRaster r={0,0,320,480,0,0,320,480,1,4};
    for(int scale=2;scale<=4;scale++) {
        int pitch=400*scale,height=480*scale;
        uint32_t *pixels=calloc((size_t)pitch*height,4);assert(pixels);
        observe(controller);a2_input_prompts_compose(pixels,pitch,scale,&r,0);
        int bounds[2][4]={{pitch,height,-1,-1},{pitch,height,-1,-1}};
        /* Scan the first keycap, excluding the panel edge and action label.
         * Gold identifies the vector circle; its blue-grey fill/edge is the cap.
         * No formula from the implementation determines these pixel bounds. */
        for(int y=52*scale;y<84*scale;y++)for(int x=10*scale;x<84*scale;x++) {
            uint32_t p=pixels[y*pitch+x];int red=(p>>16)&255,green=(p>>8)&255,blue=p&255;
            int kind=red>100 && red>green+8 && green>blue+15?0:
                     red>20 && red<160 && green>25 && blue>40 && green>red && blue>green?1:-1;
            if(kind<0)continue;
            if(x<bounds[kind][0])bounds[kind][0]=x;
            if(y<bounds[kind][1])bounds[kind][1]=y;
            if(x>bounds[kind][2])bounds[kind][2]=x;
            if(y>bounds[kind][3])bounds[kind][3]=y;
        }
        for(int kind=0;kind<2;kind++) {
            assert(bounds[kind][2]>=bounds[kind][0]);
            double width=(bounds[kind][2]-bounds[kind][0]+1)*960.0/(320*scale);
            double height=(bounds[kind][3]-bounds[kind][1]+1)*540.0/(480*scale);
            if(kind==0) {
                fprintf(stderr,"menu circle IR%d physical %.3fx%.3f\n",scale,width,height);
                assert(fabs(width-height)<=960.0/(320*scale)+540.0/(480*scale));
            } else {
                fprintf(stderr,"menu cap IR%d physical %.3fx%.3f\n",scale,width,height);
                /* Circle cap is authored22x22.6 units, nearly square. The
                 * previous uncorrected padding/outline made it1.5x as wide. */
                assert(width/height>.88 && width/height<1.10);
            }
        }
        unsigned before=a2_input_prompts_test_raster_count();
        r.cw=400; /* same tall flag and menu panel, different physical aspect */
        observe(controller);a2_input_prompts_compose(pixels,pitch,scale,&r,0);
        assert(a2_input_prompts_test_raster_count()==before+1);
        for(int i=0;i<100;i++) { observe(controller);a2_input_prompts_compose(pixels,pitch,scale,&r,0); }
        assert(a2_input_prompts_test_raster_count()==before+1);
        r.cw=320;free(pixels);
    }
    controller_glyph=A2_GLYPH_CROSS;input_source=A2_INPUT_KEYBOARD;
}
#endif
int main(void) {
    a2_input_prompts_init(ram,sizeof ram);a2_input_prompts_configure(2);
    unchanged_gameplay();
    const unsigned assignments[9]={1,2,3,0,7,4,6,5,8};
    for(unsigned i=0;i<9;i++)half(0x143a88+2*i,assignments[i]);
    assert(a2_input_prompts_preview_bit(0)==15);
    assert(a2_input_prompts_preview_bit(2)==14);
    assert(a2_input_prompts_preview_bit(8)==0);
    assert(a2_input_prompts_preview_bit(9)==-1);
    half(0x143a88,2);assert(a2_input_prompts_preview_bit(2)==-1);
    half(0x143a88,1);
    A2CinemaRaster raster={0,0,320,480,0,0,320,480,1,4};A2PromptFrame frame;
    for(unsigned i=0;i<sizeof prompt_texture_sources/sizeof *prompt_texture_sources;i++) {
        const PromptTextureSource *s=prompt_texture_sources+i;
        a2_input_prompts_configure(s->language==3?2:(int)s->language);load_texture(s);observe(s);
        a2_input_prompts_frame(&raster,0,&frame);assert(frame.count==1);
        assert(frame.panels[0].kind==(int)s->kind);
        if(s->kind==A2_PROMPT_CONTROLLER) {
            assert(frame.panels[0].count==10);
            assert(!strcmp(frame.panels[0].items[2].bindings[0].label,"Space"));
            assert(!strcmp(frame.panels[0].items[9].bindings[0].label,"Esc"));
            assert(!strcmp(frame.panels[0].items[9].bindings[1].label,"F1"));
        } else {
            unsigned expected=s->kind==A2_PROMPT_CONFIRM?2:1;
            assert(frame.panels[0].items[0].binding_count==expected);
        }
        a2_input_prompts_frame(&raster,0,&frame);assert(frame.count==1);
        observe(s);a2_input_prompts_frame(&raster,1,&frame);assert(!frame.count);
        unsigned x=768+(s->kind==A2_PROMPT_CONTROLLER?0:s->kind+8)*16;
        vram[480*1024+x+3]^=1;a2_input_prompts_vram_changed(x+3,480,1,1);
        observe(s);a2_input_prompts_frame(&raster,0,&frame);assert(!frame.count);
        vram[480*1024+x+3]^=1;a2_input_prompts_vram_changed(x+3,480,1,1);
        observe(s);a2_input_prompts_frame(&raster,0,&frame);assert(frame.count==1);
    }
    const PromptTextureSource *controller=NULL;
    for(unsigned i=0;i<sizeof prompt_texture_sources/sizeof *prompt_texture_sources;i++)
        if(prompt_texture_sources[i].kind==A2_PROMPT_CONTROLLER)controller=prompt_texture_sources+i;
    assert(controller);load_texture(controller);a2_input_prompts_configure(2);
    retained_presentations(controller);
    enum { W=640,H=960,PITCH=644 };
    uint32_t *before=malloc(PITCH*H*4),*after=malloc(PITCH*H*4);assert(before&&after);
    for(unsigned i=0;i<PITCH*H;i++)before[i]=after[i]=0xff304050u;
    observe(controller);a2_input_prompts_compose(before,PITCH,2,&raster,0);
    unsigned count=a2_input_prompts_test_raster_count();assert(count);
    for(unsigned i=0;i<100;i++)a2_input_prompts_compose(after,PITCH,2,&raster,0);
    assert(a2_input_prompts_test_raster_count()==count);
    input_source=A2_INPUT_CONTROLLER;a2_input_prompts_compose(after,PITCH,2,&raster,0);
    assert(a2_input_prompts_test_raster_count()==count+1);
    input_source=A2_INPUT_KEYBOARD;
    for(unsigned i=0;i<PITCH*H;i++)after[i]=0xff304050u;
    a2_input_prompts_compose(after,PITCH,2,&raster,0);
    assert(a2_input_prompts_test_raster_count()==count+2);
    assert(!memcmp(before,after,PITCH*H*4));
    for(unsigned y=0;y<H;y++)for(unsigned x=0;x<PITCH;x++)
        if(x>=W || y<100 || y>=628)assert(before[y*PITCH+x]==0xff304050u);
    free(before);free(after);
#if defined(__APPLE__) && !defined(A2_PROMPTS_PORTABLE)
    physical_menu_shapes(controller);
#endif
    a2_input_prompts_close();
    puts("PASS menu-only exact sources/palettes, preview maps, input source cache; gameplay and all tutorial states leave every pixel unchanged");
    return 0;
}
