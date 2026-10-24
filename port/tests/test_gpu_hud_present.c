/* Real GP0 parser/rasterizer; independent edge/texture oracle from the
 * ordinary triangle contract. Provenance is injected only at its API boundary;
 * test_hud_present separately exercises actual guest RAM lifetime and hooks. */
#define A2_HUD_PRESENT 1
#define main ordinary_triangle_test_main
#include "test_gpu_triangle_pixels.c"
#undef main

#ifndef A2_HUD_TEST_REAL_PROVENANCE
uint32_t a2_hud_present_watch_begin, a2_hud_present_watch_end;
static int injected_anchor=-1;
static uint64_t injected_token;
void a2_hud_present_invalidate(uint32_t address,size_t size) {(void)address;(void)size;}
void a2_hud_present_reset(void) {injected_anchor=-1;injected_token=0;}
uint64_t a2_hud_present_packet_token(uint32_t address,uint32_t command) {
    return address==0x80110004 && (command>>24)>=0x20 && injected_anchor>=0 ? injected_token : 0;
}
int a2_hud_present_consume(uint32_t address,uint64_t token,const uint32_t *words,unsigned count,int *anchor) {
    (void)words;(void)count;
    if(address!=0x80110004 || !token || token!=injected_token || injected_anchor<0)return 0;
    *anchor=injected_anchor;injected_token=0;return 1;
}
#endif
static uint16_t native_expected[512*1024];
static void environment(int page,int y) {
    gpu_gp1(0);gpu_gp0(0xe3000000u|((unsigned)y<<10));
    gpu_gp0(0xe4000000u|319u|((unsigned)(y+215)<<10));
    gpu_gp0(0xe5000000u|((unsigned)y<<11));gpu_gp0(0xe1000000u|(unsigned)page);
}
static void submit(Point p[4],int textured,int gouraud,int semi,unsigned page,int anchor) {
    uint32_t words[13];unsigned count=0,cmd=0x28|(textured?4:0)|(gouraud?16:0)|(semi?2:0);
    for(unsigned i=0;i<4;i++) {
        if(!i||gouraud)words[count++]=(!i?cmd<<24:0)|p[i].channel[0]|p[i].channel[1]<<8|p[i].channel[2]<<16;
        words[count++]=(uint16_t)p[i].x|((uint32_t)(uint16_t)p[i].y<<16);
        if(textured)words[count++]=p[i].uv[0]|p[i].uv[1]<<8|(i==0?480u<<22:i==1?page<<16:0);
    }
#ifndef A2_HUD_TEST_REAL_PROVENANCE
    injected_anchor=anchor;injected_token=123;
#else
    (void)anchor;
#endif
    for(unsigned i=0;i<count;i++)gpu_gp0_at(words[i],0x80110004+4*i);
}
static uint16_t world_pixel(int x,int y) {return (uint16_t)(x*31+y*73+0x9243);}
static void seed(int scale,int offset) {
    for(int y=0;y<216;y++)for(int x=0;x<320;x++)GPU_VRAM[(offset+y)*1024+x]=world_pixel(x,y);
    if(SHADOW)for(int y=0;y<216*scale;y++)for(int x=0;x<320*scale;x++)SHADOW[(offset*scale+y)*IR_W+x]=world_pixel(x,y);
}
static void transformed_quad(int scale,int anchor,int offset,unsigned variant,int filtered) {
    int x=anchor?253:7,y=8,w=36,h=36;
    if(variant&8){x+=anchor?34:-24;y=-7;}
    Point p[4]={0};
    for(unsigned i=0;i<4;i++) {
        p[i].x=x+(i&1?w:0);p[i].y=y+(i&2?h:0);
        for(unsigned c=0;c<3;c++)p[i].channel[c]=80+((i*73+c*41+variant*13)%176);
        p[i].uv[0]=8+(i&1?36:0);p[i].uv[1]=8+(i&2?36:0);
    }
    reference_polygon_region(p,4);
    int textured=variant&1,gouraud=(variant>>1)&1,semi=(variant>>2)&1;
    if(!gouraud)for(unsigned i=1;i<4;i++)memcpy(p[i].channel,p[0].channel,sizeof p[i].channel);
    unsigned page=24|(((variant/4)%3)<<7)|(((variant/8)%4)<<5);
    environment((int)page,offset);gpu_set_filter(filtered);seed(scale,offset);
    submit(p,textured,gouraud,semi,page,-1);memcpy(native_expected,GPU_VRAM,sizeof GPU_VRAM);
    environment((int)page,offset);seed(scale,offset);submit(p,textured,gouraud,semi,page,anchor);
    assert(!memcmp(native_expected,GPU_VRAM,sizeof GPU_VRAM));
    assert(SHADOW!=NULL);
    for(unsigned i=0;i<4;i++){p[i].x=(5*p[i].x+anchor)*scale;p[i].y*=6*scale;}
    for(int fy=0;fy<216*scale;fy++)for(int fx=0;fx<320*scale;fx++) {
        uint16_t wanted=world_pixel(fx,fy);
        Point first[3]={p[0],p[1],p[2]},second[3]={p[1],p[2],p[3]};
        wanted=reference(first,fx*6,fy*6,wanted,textured,gouraud,semi,page,0,filtered);
        wanted=reference(second,fx*6,fy*6,wanted,textured,gouraud,semi,page,0,filtered);
        uint16_t got=SHADOW[(offset*scale+fy)*IR_W+fx];
        if(got!=wanted){fprintf(stderr,"HUD IR%d anchor%d offset%d case%u filter%d @%d,%d got%04x expected%04x\n",scale,anchor,offset,variant,filtered,fx,fy,got,wanted);abort();}
    }
}
#ifndef A2_HUD_TEST_NO_MAIN
int main(void) {
    setenv("A2_IRSCALE","1",1);
    for(unsigned i=0;i<1024*512;i++)GPU_VRAM[i]=(uint16_t)random_word();
    for(unsigned i=0;i<256;i++)GPU_VRAM[480*1024+i]=i%5?((uint16_t)random_word()):0;
    for(int scale=1;scale<=4;scale++) {
        gpu_set_ir(scale);
        for(int anchor=0;anchor<=320;anchor+=320)for(int filtered=0;filtered<2;filtered++)
            for(unsigned variant=0;variant<16;variant++)transformed_quad(scale,anchor,0,variant,filtered);
        /* Native second framebuffer has the same placement; avoid test texture
         * source overlap by using an untextured case for its retained rows. */
        transformed_quad(scale,320,256,6,0);
    }
    ordinary_triangle_test_main();
    puts("PASS: HUD 5/6 horizontal transform IR1–4, both anchors, offscreen clipping, UV/CLUT, transparency, shading; native VRAM unchanged");
}
#endif
