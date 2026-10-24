/* Compare the real parser's optimized path with the retained old fine loop. */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define A2_GPU_RECT_TEST 1
#include "../src/gpu.c"
uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t psx_frame_no, gpu_flips;
void psx_vblank_tick(void) {}
uint32_t psx_mmio_read(uint32_t p,int n) {(void)p;(void)n;return 0;}
int a2_modelcap_active(void) {return 0;}
FILE *a2_modelcap_file(void) {return NULL;}
static uint16_t initial_vram[512*1024], expected_vram[512*1024];

static void draw(int mode,int blend_mode,int variant) {
    static const int origins[][2]={{4,5},{-9,-7},{1018,506},{90,90}};
    int x=origins[variant][0],y=origins[variant][1];
    gpu_gp1(0);
    gpu_gp0(0xe3000000|(variant==1?3:0)|((variant==1?2:0)<<10));
    gpu_gp0(0xe4000000|(variant==3?31:1023)|((variant==3?31:511)<<10));
    gpu_gp0(0xe1000000|((mode<0?0:mode)<<7)|(blend_mode<<5)|31);
    gpu_gp0(0xe2000000|(variant==1?0x731c:0));
    unsigned cmd=0x60|(mode>=0?4:0)|(variant&1?2:0);
    gpu_gp0((cmd<<24)|0xb070f8);
    gpu_gp0(((unsigned)x&0x7ff)|(((unsigned)y&0x7ff)<<16));
    if(mode>=0)gpu_gp0((480U<<22)|250|(250<<8));
    gpu_gp0(24|(20<<16));
}

/* Every16-bit background and every8-bit foreground value for each channel,
 * including mask-bit clearing and the seven discarded fractional values. */
static void additive_channel_contract(void) {
    gpu_set_ir(2);gpu_rect_test_reference=0;
    for(unsigned color=0;color<256;color++) {
        unsigned channels[3]={color,(color*73)&255,(color*151)&255};
        gpu_gp1(0);gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|127|(127<<10));gpu_gp0(0xe1000020);
        for(unsigned y=0;y<256;y++)for(unsigned x=0;x<256;x++)SHADOW[(size_t)y*IR_W+x]=(uint16_t)(y*256+x);
        gpu_gp0(0x62000000|channels[0]|(channels[1]<<8)|(channels[2]<<16));gpu_gp0(0);gpu_gp0(128|(128<<16));
        for(unsigned y=0;y<256;y++)for(unsigned x=0;x<256;x++) {
            unsigned before=y*256+x,expected=0;
            for(unsigned channel=0;channel<3;channel++) {
                unsigned sum=(((before>>(channel*5))&31)*8)+channels[channel];
                if(sum>255)sum=255;
                expected|=(sum/8)<<(channel*5);
            }
            assert(SHADOW[(size_t)y*IR_W+x]==expected);
        }
    }
}

int main(void) {
    for(unsigned i=0;i<512*1024;i++)initial_vram[i]=(uint16_t)(i*73u+(i>>7));
    /* Zero/opaque/STP palette entries interleaved. */
    for(int i=0;i<256;i++)initial_vram[480*1024+i]=i%3==0?0:(uint16_t)(i*97u|(i%3==1?0x8000:0));
    for(int scale=2;scale<=4;scale++) {
        gpu_set_ir(scale);
        size_t bytes=(size_t)IR_W*IR_H*sizeof(uint16_t);
        uint16_t *seed=malloc(bytes),*wanted=malloc(bytes);
        assert(seed&&wanted);
        for(size_t i=0;i<bytes/2;i++)seed[i]=(uint16_t)(i*37u+(i>>5));
        for(int mode=-1;mode<=2;mode++)for(int blend_mode=0;blend_mode<4;blend_mode++)
            for(int variant=0;variant<4;variant++) {
                memcpy(GPU_VRAM,initial_vram,sizeof GPU_VRAM);memcpy(SHADOW,seed,bytes);
                gpu_rect_test_reference=1;draw(mode,blend_mode,variant);
                memcpy(expected_vram,GPU_VRAM,sizeof GPU_VRAM);memcpy(wanted,SHADOW,bytes);
                memcpy(GPU_VRAM,initial_vram,sizeof GPU_VRAM);memcpy(SHADOW,seed,bytes);
                gpu_rect_test_reference=0;gpu_rect_test_samples=0;draw(mode,blend_mode,variant);
                assert(!memcmp(expected_vram,GPU_VRAM,sizeof GPU_VRAM));
                assert(!memcmp(wanted,SHADOW,bytes));
                /* Original native pass + at most one sample per native fine block. */
                if(mode>=0)assert(gpu_rect_test_samples<=2*24*20);
            }
        free(seed);free(wanted);
    }
    additive_channel_contract();gpu_set_ir(1);
    puts("GPU native rect blocks: reference pixels and bounded texture samples passed");
    return 0;
}
