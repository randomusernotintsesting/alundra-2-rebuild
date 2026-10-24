/* Exercise the real GP0 parser and both raster surfaces, without SDL/game code. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/gpu.c"

uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t psx_frame_no, gpu_flips;
static unsigned vblank_calls;
void psx_vblank_tick(void) { ++vblank_calls; gpu_vblank(); }
uint32_t psx_mmio_read(uint32_t p, int size) { (void)p; (void)size; return 0; }
int a2_modelcap_active(void) { return 0; }
FILE *a2_modelcap_file(void) { return NULL; }

static uint32_t xy(unsigned x, unsigned y) { return x | y << 16; }

static void pixel(int x, int y, uint16_t wanted) {
    uint16_t got = gpu_display_px(x, y);
    if (got != wanted) {
        fprintf(stderr, "GPU pixel (%d,%d), IR%d: got %04X, expected %04X\n",
                x, y, gpu_ir(), got, wanted);
        abort();
    }
}

static void quad_edges(int scale, int reversed) {
    gpu_set_ir(scale);
    gpu_gp1(0);
    gpu_gp0(0xe3000000);
    gpu_gp0(0xe4000000 | 1023 | (511 << 10));
    gpu_gp0(0xe1000000); /* half background + half foreground */
    gpu_gp0(0x02ffffff); gpu_gp0(0); gpu_gp0(xy(16, 16));
    gpu_gp0(0x2a000000); /* black semi-transparent quad */
    gpu_gp0(xy(1, 1));
    gpu_gp0(reversed ? xy(1, 5) : xy(5, 1));
    gpu_gp0(reversed ? xy(5, 1) : xy(1, 5));
    gpu_gp0(xy(5, 5));
    pixel(3 * scale, 3 * scale, 0x3def); /* shared-diagonal interior */
    for (int y = 0; y < 7 * scale; y++)
        for (int x = 0; x < 7 * scale; x++)
            /* Exactly four native pixels wide/high, including the top/left
             * edges but not bottom/right; shared diagonal blends only once. */
            pixel(x, y, x >= scale && x < 5 * scale &&
                        y >= scale && y < 5 * scale ? 0x3def : 0x7fff);
    assert(GPU_VRAM[3 * 1024 + 3] == 0x3def);
    assert(GPU_VRAM[1 * 1024 + 5] == 0x7fff);
}

static void preserve_resolution_change(void) {
    gpu_set_ir(1);
    gpu_gp1(0);
    memset(GPU_VRAM, 0, sizeof GPU_VRAM);
    gpu_gp0(0xa0000000); gpu_gp0(xy(37, 42)); gpu_gp0(xy(2, 1));
    gpu_gp0(0x03e0001f); /* uploaded display content, not a redrawable polygon */
    gpu_gp0(0xa0000000); gpu_gp0(xy(1023, 511)); gpu_gp0(xy(1, 1));
    gpu_gp0(0x00007c00);
    const int scales[] = {1, 2, 4, 3, 1};
    for (unsigned i = 0; i < sizeof scales / sizeof scales[0]; i++) {
        int scale = scales[i];
        gpu_set_ir(scale);
        for (int y = 0; y < scale; y++)
            for (int x = 0; x < scale; x++) {
                pixel(37 * scale + x, 42 * scale + y, 0x001f);
                pixel(38 * scale + x, 42 * scale + y, 0x03e0);
                pixel(1023 * scale + x, 511 * scale + y, 0x7c00);
                pixel(x, y, 0);
            }
        assert(GPU_VRAM[42 * 1024 + 37] == 0x001f);
    }
}

static void display_geometry(int height, int canvas_height, int yoffset) {
    int x, y, w, h, on, xo, yo, cw, ch;
    gpu_get_display(&x, &y, &w, &h, &on);
    gpu_get_raster(&xo, &yo, &cw, &ch);
    if (x != 37 || y != 0 || w != 320 || h != height || !on ||
        xo != 8 || yo != yoffset || cw != 320 || ch != canvas_height) {
        fprintf(stderr, "GPU display IR%d: image=%d,%d %dx%d on=%d, "
                "canvas=%dx%d offset=%d,%d; wanted height=%d canvas=%d offsetY=%d\n",
                gpu_ir(), x, y, w, h, on, cw, ch, xo, yo,
                height, canvas_height, yoffset);
        abort();
    }
}

static void interlaced_menu_geometry(int scale) {
    gpu_set_ir(scale);
    gpu_gp1(0);
    gpu_gp1(0x03000000);
    gpu_gp1(0x05000025); /* Source VRAM x37, y0; not a mode command. */
    gpu_gp1(0x06000000 | 672 | (3232 << 12)); /* +8 pixels horizontally */
    gpu_gp1(0x07000000 | 24 | (248 << 10)); /* 224 field-lines, +8 from NTSC */
    gpu_gp1(0x08000025); /* Actual Pocket menu: 320 x 480 interlaced. */
    display_geometry(448, 480, 16);

    /* The lower menu rows must be reachable by the existing presentation
     * loop at both native and fine resolution, not merely present in VRAM. */
    gpu_gp0(0xa0000000); gpu_gp0(xy(41, 400)); gpu_gp0(xy(2, 1));
    gpu_gp0(0x001f7c00);
    int x, y, w, h, on, xo, yo, cw, ch;
    gpu_get_display(&x, &y, &w, &h, &on);
    gpu_get_raster(&xo, &yo, &cw, &ch);
    assert(400 < h && yo + 400 < ch);
    for (int sy = 0; sy < scale; sy++)
        for (int sx = 0; sx < scale; sx++)
            pixel((x + 4) * scale + sx, (y + 400) * scale + sy, 0x7c00);

    gpu_gp1(0x08000001); /* Switch back without reset: ordinary gameplay. */
    display_geometry(224, 240, 8);
    gpu_gp1(0x08000021); /* Interlace alone does not double source rows. */
    display_geometry(224, 240, 8);
    gpu_gp1(0x08000005); /* High-resolution bit alone is not 480-line mode. */
    display_geometry(224, 240, 8);
    gpu_gp1(0x08000025);
    display_geometry(448, 480, 16);
    gpu_gp1(0x07000000 | 16 | (256 << 10)); /* Full-height, zero offset. */
    display_geometry(480, 480, 0);
    gpu_gp1(0x08000001);
    display_geometry(240, 240, 0);
    gpu_gp1(0x07000000 | 12 | (236 << 10)); /* Existing negative-offset clamp. */
    display_geometry(224, 240, 0);
    gpu_gp1(0x08000025);
    display_geometry(448, 480, 0);
}

static void status_poll_progress(void) {
    gpu_set_ir(1);
    gpu_gp1(0);
    vblank_calls=0;
    /* DrawSync checks across separate submissions are not a field wait.
     * The old lifetime counter presented the clear before the menu redraw. */
    for(unsigned frame=0;frame<300;frame++) {
        gpu_gp0(0x02000000);gpu_gp0(0);gpu_gp0(xy(320,456));
        (void)gpu_stat();
        gpu_gp0(0x020000ff);gpu_gp0(0);gpu_gp0(xy(320,456));
        (void)gpu_stat();
    }
    assert(vblank_calls==0);
    /* GP1 and GPUREAD activity also interrupt a status-only wait. */
    for(unsigned kind=0;kind<3;kind++)for(unsigned round=0;round<3;round++) {
        if(kind==0)gpu_gp1(0x03000000);
        if(kind==1)(void)gpu_read();
        if(kind==2)gpu_vblank();
        for(unsigned i=0;i<255;i++)(void)gpu_stat();
        assert(vblank_calls==0);
    }
    gpu_gp1(0x03000000);
    uint32_t field=gpu_stat()&0x80000000u;
    for(unsigned i=1;i<256;i++)(void)gpu_stat();
    assert(vblank_calls==1);
    assert((gpu_stat()&0x80000000u)!=field);
    for(unsigned i=1;i<256;i++)(void)gpu_stat();
    assert(vblank_calls==2);
}

int main(int argc, char **argv) {
    assert(setenv("A2_IRSCALE", "1", 1) == 0);
    gpu_set_filter(0);
    if(argc==1 || !strcmp(argv[1],"polls"))status_poll_progress();
    if (argc == 1 || !strcmp(argv[1], "edges")) {
        quad_edges(1, 0); quad_edges(1, 1);
    }
    if (argc == 1 || !strcmp(argv[1], "fine")) {
        quad_edges(3, 0); quad_edges(3, 1);
    }
    if (argc == 1 || !strcmp(argv[1], "resolution"))
        preserve_resolution_change();
    if (argc == 1 || !strcmp(argv[1], "display")) {
        interlaced_menu_geometry(1);
        interlaced_menu_geometry(3);
    }
    gpu_set_ir(1);
    puts("GPU quad edges, resolution, display geometry and status polling passed");
    return 0;
}
