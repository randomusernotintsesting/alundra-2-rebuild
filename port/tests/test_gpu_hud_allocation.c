/* Allocation fault at the only newly required surface (IR1) must preserve the
 * prior usable resolution. Initial failure falls back to native presentation. */
#include <stdlib.h>
static int fail_calloc;
static void *hud_calloc(size_t count,size_t size){return fail_calloc?NULL:calloc(count,size);}
#define calloc hud_calloc
#define A2_HUD_TEST_NO_MAIN 1
#include "test_gpu_hud_present.c"
#undef calloc
int main(void) {
    setenv("A2_IRSCALE","1",1);GPU_VRAM[0]=0x1357;
    fail_calloc=1;assert(gpu_ir()==1 && SHADOW==NULL);
    assert(IR_W==1024&&IR_H==512&&gpu_display_px(0,0)==0x1357);
    fail_calloc=0;gpu_set_ir(4);assert(IR==4&&SHADOW);SHADOW[0]=0x2468;
    uint16_t *before=SHADOW;fail_calloc=1;gpu_set_ir(1);
    assert(IR==4&&SHADOW==before&&gpu_display_px(0,0)==0x2468);
    fail_calloc=0;gpu_set_ir(1);assert(IR==1&&SHADOW&&SHADOW[0]==0x1357);
    before=SHADOW;SHADOW[0]=0x5678;fail_calloc=1;gpu_set_ir(2);
    assert(IR==1&&SHADOW==before&&gpu_display_px(0,0)==0x5678);
    puts("PASS: IR1 allocation failure preserves the active display, initial failure retains native fallback");
}
