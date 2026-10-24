/* HUD provenance wins even if a packet also has complete, valid world GTE
 * provenance. The world subpixel extension must never bypass HUD placement. */
#define A2_WORLD_PRECISION 1
#define A2_HUD_TEST_NO_MAIN 1
#include "test_gpu_hud_present.c"
static void mixed_packet(void) {
    const int x[4]={270,306,270,306},y[4]={10,10,46,46};
    uint32_t words[5]={0x28f08040},source[4],dest[4],native[4];
    uint64_t object=world_precision_begin_object();
    for(unsigned i=0;i<4;i++) {
        native[i]=(unsigned)x[i]|((unsigned)y[i]<<16);words[i+1]=native[i];
        source[i]=0x1f800000+i*12;dest[i]=0x80110008+i*4;
        world_precision_vertex value;
        world_precision_gte_push(native[i],(int64_t)x[i]*65536+16384,(int64_t)y[i]*65536+8192,900,1);
        assert(world_precision_gte_read(14,native[i],&value));
        world_precision_record(source[i],native[i],object,&value);
    }
    assert(world_precision_emit(dest,native,source,4,object));
    injected_anchor=320;injected_token=123;
    for(unsigned i=0;i<5;i++)gpu_gp0_at(words[i],0x80110004+i*4);
    assert(world_primitive_valid);
}
int main(void) {
    setenv("A2_IRSCALE","1",1);world_precision_configure(1);
    for(int scale=1;scale<=4;scale++) {
        gpu_set_ir(scale);size_t bytes=(size_t)IR_W*IR_H*2;
        uint16_t *wanted=malloc(bytes);assert(wanted);
        environment(0,0);seed(scale,0);gpu_set_world_raster(0);mixed_packet();
        memcpy(wanted,SHADOW,bytes);memcpy(native_expected,GPU_VRAM,sizeof GPU_VRAM);
        environment(0,0);seed(scale,0);gpu_set_world_raster(1);mixed_packet();
        assert(!memcmp(native_expected,GPU_VRAM,sizeof GPU_VRAM));
        assert(!memcmp(wanted,SHADOW,bytes));free(wanted);
    }
    puts("PASS: valid world GTE provenance cannot bypass HUD geometry at IR1–4");
}
