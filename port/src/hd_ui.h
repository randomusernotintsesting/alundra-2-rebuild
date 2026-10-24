#ifndef A2_HD_UI_H
#define A2_HD_UI_H
#include <stdint.h>
typedef struct A2HDPlate A2HDPlate;
void a2_hd_ui_set_language(int language);
typedef struct {
    uint16_t background,ink,shadow;
    uint8_t alpha,shadow_alpha;
} A2HDUISample;
/* Authored indices before CLUT lookup, for command-local prepared palettes. */
typedef struct {
    uint8_t background,ink,shadow,alpha,shadow_alpha;
} A2HDUIIndices;
int a2_hd_ui_sample_indices(const A2HDPlate *const *plates,unsigned count,
                           int u_fp,int v_fp,A2HDUIIndices *out);
unsigned a2_hd_ui_prepare(const uint16_t *vram,uint32_t tpage,
                         int u0,int v0,int u1,int v1,
                         const A2HDPlate **out,unsigned capacity);
int a2_hd_ui_sample(const A2HDPlate *const *plates,unsigned count,
                   const uint16_t *vram,uint32_t clut,int u_fp,int v_fp,
                   A2HDUISample *out);
/* Union of prepared word regions, in native UV; upper bounds are exclusive.
 * Sampling outside this union cannot contain either ink or its shadow. */
int a2_hd_ui_bounds(const A2HDPlate *const *plates,unsigned count,int bounds[4]);
#endif
