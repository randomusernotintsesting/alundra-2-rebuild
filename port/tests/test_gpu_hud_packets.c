/* Real provenance + real GP0 decoder on all 20 retained GAME00 HUD packets.
 * The separate generated-builder test proves these are the actual emitted
 * commands. This checks their lifetime through the GPU FIFO and display pass. */
#define A2_HUD_TEST_REAL_PROVENANCE 1
#define A2_HUD_TEST_NO_MAIN 1
#include "test_gpu_hud_present.c"
#include "fixtures/hud_present_packets.h"
static uint16_t initial[512*1024];
static uint8_t original_ram[PSX_RAM_SIZE];
static void tags(unsigned mode) {
    a2_hud_present_begin(0x80110c54,0x801154c8,mode,0x8008606c);
    a2_hud_present_group(0x80110cf4,0);
    a2_hud_present_group(0x80110e34,320);
    a2_hud_present_descriptor(0x80110f3c,0x800a96b0);
    a2_hud_present_descriptor(0x80110ff4,0x800a9728);
    uint32_t head=0x110ff4;memcpy(PSX_RAM+0x1154c8,&head,4);
    a2_hud_present_end(0x80111028);
}
static void prepare(int scale,unsigned mode) {
    environment(0,0);gpu_set_filter(1);memcpy(GPU_VRAM,initial,sizeof initial);
    for(int y=0;y<512*scale;y++)for(int x=0;x<1024*scale;x++)SHADOW[(size_t)y*IR_W+x]=initial[(y/scale)*1024+x/scale];
    memset(PSX_RAM,0,sizeof PSX_RAM);
    for(unsigned i=0;i<sizeof hud_fixture_code/sizeof *hud_fixture_code;i++)
        memcpy(PSX_RAM+hud_fixture_code[i].address,hud_fixture_code[i].data,hud_fixture_code[i].bytes);
    for(unsigned i=0;i<20;i++)memcpy(PSX_RAM+hud_fixture_packets[i].address,hud_fixture_packets[i].words,(hud_fixture_packets[i].count+1)*4);
    uint32_t old=0x1154c4;memcpy(PSX_RAM+0x1154c8,&old,4);
    a2_hud_present_init(PSX_RAM,sizeof PSX_RAM);tags(mode);
    memcpy(original_ram,PSX_RAM,sizeof PSX_RAM);
}
static void draw(unsigned count,int direct,int broken_address,int stale) {
    for(unsigned i=0;i<count;i++) {
        const struct HudFixturePacket *p=&hud_fixture_packets[i];
        for(unsigned j=0;j<p->count;j++) {
            if(direct)gpu_gp0(p->words[j+1]);
            else gpu_gp0_at(p->words[j+1],p->address+4+j*4+(broken_address&&j==2?4:0));
            if(stale && !j) {
                uint32_t old=0x1154c4;memcpy(PSX_RAM+0x1154c8,&old,4);tags(0);
            }
        }
    }
    assert(!memcmp(original_ram,PSX_RAM,sizeof PSX_RAM));
}
int main(void) {
    setenv("A2_IRSCALE","1",1);
    for(unsigned i=0;i<512*1024;i++)initial[i]=(uint16_t)((i%7)?(i*97u+0x8000):0);
    for(int scale=1;scale<=4;scale++) {
        gpu_set_ir(scale);size_t bytes=(size_t)IR_W*IR_H*2;
        uint16_t *normal=malloc(bytes);assert(normal);
        prepare(scale,0);draw(20,1,0,0);memcpy(native_expected,GPU_VRAM,sizeof GPU_VRAM);memcpy(normal,SHADOW,bytes);
        prepare(scale,0);draw(20,0,0,0);
        A2HudPresentStats stats;a2_hud_present_stats(&stats);
        assert(stats.produced_packets==20&&stats.consumed_packets==20);
        assert(!memcmp(native_expected,GPU_VRAM,sizeof GPU_VRAM));assert(memcmp(normal,SHADOW,bytes));
        prepare(scale,1);draw(20,0,0,0);a2_hud_present_stats(&stats);
        assert(stats.consumed_packets==0);assert(!memcmp(normal,SHADOW,bytes));
        /* FIFO words must all belong to one original packet and generation. */
        prepare(scale,0);draw(1,1,0,0);memcpy(normal,SHADOW,bytes);
        prepare(scale,0);draw(1,0,1,0);assert(!memcmp(normal,SHADOW,bytes));
        prepare(scale,0);draw(1,0,0,1);assert(!memcmp(normal,SHADOW,bytes));
        /* Unsupported display environment consumes provenance but never moves
         * arbitrary menu/transition geometry. */
        prepare(scale,0);gpu_gp0(0xe4000000u|319u|(239u<<10));draw(1,0,0,0);assert(!memcmp(normal,SHADOW,bytes));
        free(normal);
    }
    a2_hud_present_close();
    puts("PASS: all 20 genuine HUD packets transform, native RAM/VRAM stay exact; mode1, FIFO source discontinuity, stale generations and unknown raster stay unchanged");
}
