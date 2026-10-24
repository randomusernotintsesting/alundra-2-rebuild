#ifndef A2_HD_ART_H
#define A2_HD_ART_H
#include <stdint.h>

/* Native indexed source, four-times authored coverage. Pixel words store
 * palette indexA/indexB/mix/coverage, low to high byte. No fixed RGB colors. */
typedef struct {
    uint16_t u,v,width,height;
    uint8_t bpp;
    const uint8_t *source;
    const uint32_t *pixels;
    /* Bits 0/1/2 select RU/JA/EN. Zero preserves shared legacy assets. */
    uint8_t language_mask;
} A2HDArt;
typedef struct {
    uint16_t first,second;
    uint8_t mix,coverage;
} A2HDArtSample;

/* Select before guest loading-frame composition. Invalid values are ignored. */
void a2_hd_art_set_language(int language);
unsigned a2_hd_art_prepare(const A2HDArt *assets,unsigned asset_count,
                          const uint16_t *vram,uint32_t tpage,
                          int u0,int v0,int u1,int v1,
                          const A2HDArt **out,unsigned capacity);
int a2_hd_art_sample(const A2HDArt *const *assets,unsigned count,
                     const uint16_t *vram,uint32_t clut,
                     int u_fp,int v_fp,A2HDArtSample *out);
/* Applies the PS1 texture window to integer UV bits, preserving 8-bit fraction. */
void a2_hd_art_window_uv(uint32_t window,int *u_fp,int *v_fp);
#endif
