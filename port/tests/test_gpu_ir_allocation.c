/* Real GPU, with only the allocator boundary fault-injected. */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
static int fail_allocation,allocation_calls,fail_at;
static void *fault_calloc(size_t count, size_t size) {
    ++allocation_calls;
    return fail_allocation || (fail_at && allocation_calls==fail_at) ? NULL : calloc(count, size);
}
#define calloc fault_calloc
#include "../src/gpu.c"
#undef calloc

uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t psx_frame_no, gpu_flips;
void psx_vblank_tick(void) {}
uint32_t psx_mmio_read(uint32_t p, int size) { (void)p; (void)size; return 0; }
int a2_modelcap_active(void) { return 0; }
FILE *a2_modelcap_file(void) { return NULL; }

int main(void) {
    setenv("A2_IRSCALE", "1", 1);
    gpu_set_ir(3);
    assert(gpu_ir() == 3);
    GPU_VRAM[0] = 0x001f;
    SHADOW[0] = 0x03e0; /* Fine detail must survive failed replacement. */
    uint16_t *original = SHADOW;
    fail_allocation = 1;
    gpu_set_ir(4);
    assert(gpu_ir() == 3);
    assert(SHADOW == original && IR_W == 3072 && IR_H == 1536);
    assert(gpu_display_px(0, 0) == 0x03e0 && GPU_VRAM[0] == 0x001f);
    gpu_set_ir(2);
    assert(gpu_ir() == 3 && SHADOW == original && SHADOW[0] == 0x03e0);

    fail_allocation = 0;
    gpu_set_ir(4);
    assert(gpu_ir() == 4 && IR_W == 4096 && IR_H == 2048);
    for (int y = 0; y < 4; y++) for (int x = 0; x < 4; x++)
        assert(gpu_display_px(x, y) == 0x001f);
    fail_allocation = 1;
    gpu_set_ir(1); /* Native mode needs no allocation. */
    assert(gpu_ir() == 1 && SHADOW == NULL);
    gpu_set_ir(2);
    assert(gpu_ir() == 1 && SHADOW == NULL && IR_W == 1024 && IR_H == 512);
    assert(gpu_display_px(0, 0) == 0x001f);
    fail_allocation=0;setenv("A2_COLOR_PRECISION","1",1);gpu_set_ir(3);
    assert(SHADOW_RGB);uint32_t *original_rgb=SHADOW_RGB;original=SHADOW;
    SHADOW_RGB[0]=0xff070503;SHADOW[0]=0x03e0;
    fail_at=allocation_calls+2;gpu_set_ir(4);
    assert(IR==3 && IR_W==3072 && IR_H==1536 && SHADOW==original && SHADOW_RGB==original_rgb);
    assert(SHADOW_RGB[0]==0xff070503 && SHADOW[0]==0x03e0 && GPU_VRAM[0]==0x001f);
    fail_at=0;gpu_set_ir(4);assert(gpu_display_argb_row(0)[0]==0xfff80000);
    gpu_set_ir(1);assert(!SHADOW && !SHADOW_RGB);
    puts("GPU IR allocation failure preserves active resolution and both555/ARGB surfaces, including second allocation failure");
    return 0;
}
