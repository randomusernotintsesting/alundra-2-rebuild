/* All untagged 1x writes must keep the original native image, including
 * overlapping texture feedback which a later second pass cannot reproduce. */
#define A2_HUD_TEST_NO_MAIN 1
#include "test_gpu_hud_present.c"
static void same(const char *phase) {
    assert(SHADOW!=NULL);
    if(memcmp(SHADOW,GPU_VRAM,sizeof GPU_VRAM)) {
        for(unsigned i=0;i<512*1024;i++)if(SHADOW[i]!=GPU_VRAM[i]) {
            fprintf(stderr,"IR1 %s differs @%u,%u native%04x display%04x\n",phase,i%1024,i/1024,GPU_VRAM[i],SHADOW[i]);abort();
        }
    }
}
int main(void) {
    setenv("A2_IRSCALE","1",1);
    for(unsigned i=0;i<512*1024;i++)GPU_VRAM[i]=(uint16_t)(i*37u+13);
    gpu_set_ir(1);same("initial seed");gpu_set_filter(1);
    gpu_gp1(0);gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|1023|(511u<<10));
    for(unsigned mode=0;mode<4;mode++) {
        gpu_gp0(0xe1000000|0x100|(mode<<5));
        gpu_gp0(0x020070e0);gpu_gp0(24|(24u<<16));gpu_gp0(32|(19u<<16));same("fill");
        gpu_gp0(0xa0000000);gpu_gp0(1022|(510u<<16));gpu_gp0(4|(3u<<16));
        for(unsigned i=0;i<6;i++)gpu_gp0(0x80000100u+i*0x137921);same("wrapped upload");
        gpu_gp0(0x80000000);gpu_gp0(24|(24u<<16));gpu_gp0(25|(25u<<16));gpu_gp0(32|(19u<<16));same("overlapping copy");
        gpu_gp0(0x62804020);gpu_gp0(22|(29u<<16));gpu_gp0(33|(21u<<16));same("semi rect");
        gpu_gp0(0x66808080);gpu_gp0(24|(31u<<16));gpu_gp0(23|(30u<<8));gpu_gp0(33|(21u<<16));same("feedback rect");
        gpu_gp0(0x4280ff40);gpu_gp0(20|(20u<<16));gpu_gp0(37|(49u<<16));same("semi line");
        gpu_gp0(0x4880ff40);gpu_gp0(20|(20u<<16));gpu_gp0(47|(49u<<16));gpu_gp0(30|(55u<<16));gpu_gp0(0x50005000);same("polyline");
        Point p[4]={0};for(unsigned i=0;i<4;i++) {
            p[i].x=26+(i&1?24:0);p[i].y=34+(i&2?19:0);
            p[i].uv[0]=(unsigned)p[i].x-1;p[i].uv[1]=(unsigned)p[i].y-1;
            p[i].channel[0]=100+i*30;p[i].channel[1]=150;p[i].channel[2]=90;
        }
        submit(p,1,1,1,0x100|(mode<<5),-1);same("feedback Gouraud quad");
        gpu_gp0(0xe6000003);submit(p,0,1,1,0x100|(mode<<5),-1);same("mask command and quad");
    }
    /* A later ordinary fade must blend against the moved HUD/background,
     * never copy back the native HUD at its old position. */
    environment(0,0);gpu_gp0(0x02202020);gpu_gp0(0);gpu_gp0(320|(216u<<16));
    Point p[4]={0};for(unsigned i=0;i<4;i++) {
        p[i].x=12+(i&1?36:0);p[i].y=12+(i&2?36:0);p[i].channel[0]=248;
    }
    submit(p,0,0,0,0,0);
    assert(GPU_VRAM[20*1024+44]!=SHADOW[20*1024+44]);
    uint16_t before=SHADOW[20*1024+44];
    gpu_gp0(0x624080c0);gpu_gp0(0);gpu_gp0(80|(80u<<16));
    unsigned expected=0,foreground[3]={192,128,64};
    for(unsigned channel=0;channel<3;channel++)
        expected|=(((((before>>(channel*5))&31)*8+foreground[channel])/2)/8)<<(channel*5);
    assert(SHADOW[20*1024+44]==expected);
    puts("PASS: IR1 untagged shadow exactly matches native upload/fill/copy/line/polyline/rect/triangle, four blends and self-texture feedback");
}
