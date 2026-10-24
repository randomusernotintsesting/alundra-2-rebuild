/* Breaks caught: lost/clipped panel pixels, a stale GPU upload after bindings
 * or language change, invalidated native proofs leaking a retained panel. */
#define main retained_prompt_tests
#include "test_input_prompts.c"
#undef main
#ifndef A2_INPUT_PROMPTS_VISITOR
/* Test-only weak contract lets the unchanged CPU implementation run RED. */
typedef struct {const uint32_t *pixels;int x,y,width,height;uint64_t generation;} A2PromptPixels;
typedef void (*A2PromptVisitor)(const A2PromptPixels *,void *);
extern void a2_input_prompts_visit(int,const A2CinemaRaster *,int,A2PromptVisitor,void *) __attribute__((weak_import));
#endif
typedef struct {A2PromptPixels view;uint32_t *upload;unsigned calls;} Consumer;
static void consume(const A2PromptPixels *view,void *opaque) {
    Consumer *c=opaque;assert(view->pixels&&view->width>0&&view->height>0&&view->generation);
    ++c->calls;
    if(c->view.generation!=view->generation) {
        free(c->upload);c->upload=malloc((size_t)view->width*view->height*4);assert(c->upload);
        memcpy(c->upload,view->pixels,(size_t)view->width*view->height*4);
    }
    c->view=*view;
}
static void compose_upload(Consumer *c,uint32_t *dst,int pitch,int width,int height) {
    const A2PromptPixels *p=&c->view;
    /* Independent clipped destination walk, using the exposed premultiplied
     * data. The cached upload intentionally refreshes ONLY on generation. */
    for(int y=0;y<height;y++)for(int x=0;x<width;x++) {
        int sx=x-p->x,sy=y-p->y;
        if(sx<0||sx>=p->width||sy<0||sy>=p->height)continue;
        unsigned src=c->upload[(size_t)sy*p->width+sx],a=src>>24;if(!a)continue;
        unsigned old=dst[(size_t)y*pitch+x],v=0xff000000u;
        for(unsigned shift=0;shift<24;shift+=8) {
            unsigned channel=((src>>shift)&255)+(((old>>shift)&255)*(255-a)+127)/255;
            v|=(channel>255?255:channel)<<shift;
        }
        dst[(size_t)y*pitch+x]=v;
    }
}
static void background(uint32_t *p,int pitch,int width,int height) {
    for(int y=0;y<height;y++)for(int x=0;x<pitch;x++)
        p[(size_t)y*pitch+x]=x<width?(0xff000000u|((x*47+y*13)&0xffffff)):0xdeadbeefu;
}
typedef struct { Consumer panels[3]; unsigned count; } ThreePanels;
static void consume_three(const A2PromptPixels *view,void *opaque) {
    ThreePanels *c=opaque;assert(c->count<3);
    /* Deliberately descending, overlapping positions; callback order must
     * follow confirm/cancel/reset, not coordinates or sprite submission. */
    assert(view->x==(100-20*(int)c->count)*2&&view->y==388*2);
    consume(view,&c->panels[c->count++]);
}
static void ordered_panels(void) {
    a2_input_prompts_init(ram,sizeof ram);a2_input_prompts_configure(2);
    const PromptTextureSource *sources[3]={0};
    memset(vram,0,sizeof vram);
    for(unsigned i=0;i<sizeof prompt_texture_sources/sizeof *prompt_texture_sources;i++) {
        const PromptTextureSource *s=prompt_texture_sources+i;
        if(s->kind>=3||s->language!=2)continue;
        sources[s->kind]=s;unsigned per_word=16/s->bpp,bank=s->kind+8;
        for(unsigned y=0;y<s->height;y++)for(unsigned x=0;x<s->width;x++) {
            unsigned u=s->u+x;
            vram[(256+s->v+y)*1024+576+u/per_word]|=
                (uint16_t)s->pixels[y*s->width+x]<<((u%per_word)*s->bpp);
        }
        for(unsigned n=0;n<(1u<<s->bpp);n++)
            vram[480*1024+768+bank*16+n]=s->palette[n*2]|s->palette[n*2+1]<<8;
    }
    a2_input_prompts_vram_changed(0,0,1024,512);
    for(int i=2;i>=0;i--) {
        const PromptTextureSource *s=sources[i];assert(s);
        a2_input_prompts_sprite(vram,0x39,0x7830+i+8,100-i*20,388,
                               s->width,s->height,s->u,s->v);
    }
    enum {W=640,H=960,P=647};
    uint32_t *expected=malloc(P*H*4),*actual=malloc(P*H*4);assert(expected&&actual);
    background(expected,P,W,H);background(actual,P,W,H);
    A2CinemaRaster r={0,0,320,480,0,0,320,480,1,4};ThreePanels c={0};
    a2_input_prompts_visit(2,&r,0,consume_three,&c);assert(c.count==3);
    for(unsigned i=0;i<3;i++)compose_upload(&c.panels[i],actual,P,W,H);
    a2_input_prompts_compose(expected,P,2,&r,0);assert(!memcmp(actual,expected,P*H*4));
    for(unsigned i=0;i<3;i++)free(c.panels[i].upload);
    free(expected);free(actual);a2_input_prompts_close();
}
int main(void) {
#ifndef A2_INPUT_PROMPTS_VISITOR
    if(!a2_input_prompts_visit){fputs("FAIL: no GPU-readable caption panels; only CPU in-place composition is available\n",stderr);return 1;}
#endif
    assert(retained_prompt_tests()==0);
    a2_input_prompts_init(ram,sizeof ram);a2_input_prompts_configure(2);
    const unsigned assignments[9]={1,2,3,0,7,4,6,5,8};
    for(unsigned i=0;i<9;i++)half(0x143a88+2*i,assignments[i]);
    const PromptTextureSource *controller=NULL;
    for(unsigned i=0;i<sizeof prompt_texture_sources/sizeof *prompt_texture_sources;i++)
        if(prompt_texture_sources[i].kind==A2_PROMPT_CONTROLLER)controller=prompt_texture_sources+i;
    assert(controller);load_texture(controller);
    static uint8_t saved_ram[sizeof ram];static uint16_t saved_vram[sizeof vram/sizeof *vram];
    memcpy(saved_ram,ram,sizeof ram);memcpy(saved_vram,vram,sizeof vram);
    Consumer c={0};input_source=A2_INPUT_KEYBOARD;key="Space";
    for(int scale=2;scale<=4;scale++)for(int clipped=0;clipped<2;clipped++) {
        int width=320*scale,height=480*scale,pitch=width+7;
        uint32_t *expected=malloc((size_t)pitch*height*4),*actual=malloc((size_t)pitch*height*4);
        assert(expected&&actual);A2CinemaRaster raster={0,0,320,480,clipped?-12:0,0,320,480,1,4};
        for(unsigned change=0;change<4;change++) {
            key=change&1?"Enter":"Space";
            a2_input_prompts_configure(change<2?2:0);observe(controller);
            background(expected,pitch,width,height);background(actual,pitch,width,height);
            a2_input_prompts_compose(expected,pitch,scale,&raster,0);
            unsigned rasters=a2_input_prompts_test_raster_count();c.calls=0;
            a2_input_prompts_visit(scale,&raster,0,consume,&c);assert(c.calls==1);
            /* Authored controller rectangle: x8,y50,width304,height264. */
            assert(c.view.x==(clipped?-4:8)*scale&&c.view.y==50*scale);
            assert(c.view.width==304*scale&&c.view.height==264*scale);
            assert(a2_input_prompts_test_raster_count()==rasters);
            uint64_t generation=c.view.generation;uint32_t *upload=c.upload;
            a2_input_prompts_visit(scale,&raster,0,consume,&c);
            assert(c.calls==2&&c.view.generation==generation&&c.upload==upload);
            compose_upload(&c,actual,pitch,width,height);
            assert(!memcmp(expected,actual,(size_t)pitch*height*4));
            assert(!memcmp(saved_ram,ram,sizeof ram)&&!memcmp(saved_vram,vram,sizeof vram));
        }
        c.calls=0;a2_input_prompts_visit(scale,&raster,1,consume,&c);assert(c.calls==0);
        c.calls=0;a2_input_prompts_visit(scale,&raster,0,consume,&c);assert(c.calls==0);
        free(expected);free(actual);
    }
    /* The GPU consumer survives a prompt subsystem restart. A restarted
     * cache must not reuse its old generation and leave old pixels uploaded. */
    A2CinemaRaster r={0,0,320,480,0,0,320,480,1,4};
    observe(controller);a2_input_prompts_visit(2,&r,0,consume,&c);
    uint64_t old_generation=c.view.generation;
    a2_input_prompts_close();a2_input_prompts_init(ram,sizeof ram);
    a2_input_prompts_configure(2);load_texture(controller);key="Changed";observe(controller);
    a2_input_prompts_visit(2,&r,0,consume,&c);assert(c.view.generation!=old_generation);
    assert(!memcmp(c.upload,c.view.pixels,(size_t)c.view.width*c.view.height*4));
    free(c.upload);a2_input_prompts_close();ordered_panels();
    puts("PASS24 cached panel consumers: exact CPU pixels, clipping/padding, binding/language changes, retired proofs and unchanged native RAM/VRAM");
    return 0;
}
