#ifndef A2_TEXT_RASTER_H
#define A2_TEXT_RASTER_H
#include <stdint.h>
typedef struct { uint32_t *pixels; int width,height; double advance; unsigned missing_glyphs; } A2TextRaster;
/* UTF-8, logical pixel size and maximum width. Returns straight-alpha ARGB8888
 * white ink, row zero at top; caller owns pixels. Invalid UTF-8/ranges fail and
 * leave output unchanged. max_width=0 means one unwrapped line. */
int a2_text_rasterize(const char *utf8,double size,int max_width,int bold,A2TextRaster *out);
/* Game-menu headings; separate from subtitle and control-label typography. */
int a2_text_rasterize_title(const char *utf8,double size,int max_width,int bold,A2TextRaster *out);
/* Immutable image data, same ARGB layout; used for the menu branding asset. */
int a2_image_raster_load(const char *utf8_path,A2TextRaster *out);
/* Diagnostic export, exact opaque ARGB input; no UI side effects. */
int a2_image_raster_write_png(const char *utf8_path,const uint32_t *pixels,int width,int height,int pitch);
void a2_text_raster_free(A2TextRaster *raster);
#endif
