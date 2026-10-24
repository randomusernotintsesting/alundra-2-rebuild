#ifndef A2_HD_FONT_H
#define A2_HD_FONT_H
#include <stdint.h>
typedef struct A2HDGlyph A2HDGlyph;
int a2_hd_font_enabled(void);
int a2_hd_guest_advance(uint32_t token, int original);
void a2_hd_guest_note(uint32_t token, uint32_t base_x, uint32_t u, uint32_t v);
const A2HDGlyph *a2_hd_font_match(const uint16_t *vram, uint32_t tpage,
                               int u, int v, int width, int height);
unsigned a2_hd_font_alpha(const A2HDGlyph *glyph, int x, int y, int scale);
enum { A2_HD_FONT_COVERAGE_STRIDE = 48 };
/* Embedded glyphs only; NULL for mutable/synthetic glyphs or invalid scales.
 * Read 12*scale columns and 24*scale rows at the fixed stride. The view is
 * valid until coverage is requested at a different scale; do not retain it. */
const uint8_t *a2_hd_font_coverage(const A2HDGlyph *glyph, int scale);
void a2_hd_font_reset(void);
#endif
