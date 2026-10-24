#ifndef A2_HD_PORTRAITS_H
#define A2_HD_PORTRAITS_H
#include <stdint.h>

/* The original 8bpp cell is always UV (64,40), 40x48. Artwork dimensions
 * describe the supplied image independently of the internal render scale. */
typedef struct {
    uint16_t width,height;
    const uint8_t *source;       /* 40x48 native indices */
    const uint16_t *palette;     /* complete 256-entry original CLUT */
    const uint8_t *rgba;         /* row-major straight RGBA, explicit alpha */
} A2HDPortrait;
typedef struct { uint8_t r,g,b,a; } A2HDPortraitSample;

/* Full immutable source/CLUT comparison once per intersecting primitive. */
const A2HDPortrait *a2_hd_portrait_prepare(const A2HDPortrait *assets,unsigned count,
    const uint16_t *vram,uint32_t tpage,uint32_t clut,int u0,int v0,int u1,int v1);
int a2_hd_portrait_sample(const A2HDPortrait *asset,uint32_t window,
    int u_fp,int v_fp,A2HDPortraitSample *out);
#endif
