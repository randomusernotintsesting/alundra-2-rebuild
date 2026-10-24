/* The row API must expose the same pixels/wrap as the existing scalar API. */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/gpu.c"
uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t psx_frame_no, gpu_flips;
void psx_vblank_tick(void) {}
uint32_t psx_mmio_read(uint32_t p,int n) {(void)p;(void)n;return 0;}
int a2_modelcap_active(void) {return 0;}
FILE *a2_modelcap_file(void) {return NULL;}
extern const uint16_t *gpu_display_row(int fy);
int main(void) {
    const int ys[]={-4097,-1,0,1,511,512,1535,1536,2047,2048,9999};
    const int xs[]={-4097,-1,0,1,1023,1024,3071,3072,4095,4096,9999};
    for(int scale=1;scale<=4;scale++) {
        gpu_set_ir(scale);
        for(unsigned i=0;i<512*1024;i++)GPU_VRAM[i]=(uint16_t)(i*73u+(i>>7));
        if(scale>1)for(size_t i=0;i<(size_t)IR_W*IR_H;i++)SHADOW[i]=(uint16_t)(i*37u+(i>>5));
        for(unsigned y=0;y<sizeof ys/sizeof ys[0];y++) {
            const uint16_t *row=gpu_display_row(ys[y]);
            for(unsigned x=0;x<sizeof xs/sizeof xs[0];x++) {
                int wrapped=xs[x]%IR_W;if(wrapped<0)wrapped+=IR_W;
                assert(row[wrapped]==gpu_display_px(xs[x],ys[y]));
            }
        }
    }
    gpu_set_ir(1);
    puts("GPU display rows match scalar pixels at IR1–4, negative and wrapped coordinates");
    return 0;
}
