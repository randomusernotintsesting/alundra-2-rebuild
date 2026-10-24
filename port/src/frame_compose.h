#ifndef A2_FRAME_COMPOSE_H
#define A2_FRAME_COMPOSE_H
#include <stdint.h>
#include "cinema.h"
/* Remove only the canonical GAME00 TV overscan margins. No picture is cut. */
int a2_gameplay_canvas(A2CinemaRaster *raster);
typedef struct {
    const uint32_t *pixels;
    int width,height,stride;
} A2FrameView;
/* Borrow an exact complete ARGB canvas until the next source mutation.
 * No conversion, border fill or wrap is performed. Returns 0 and clears out
 * if any row is unavailable/non-contiguous or composition is required. */
int a2_frame_view(A2FrameView *out,int scale,
                  int dx,int dy,int dw,int dh,int xo,int yo,int cw,int ch);
/* Native-coordinate picture/canvas; destination pitch is in fine-grid pixels.
 * Requires scale1..4, positive canvas <=1024x512 and sufficient destination.
 * Clips the picture to the canvas and leaves destination padding untouched. */
void a2_compose_frame(uint32_t *dst, int pitch, int scale,
                      int dx, int dy, int dw, int dh,
                      int xo, int yo, int cw, int ch);
/* A layout accepted by a2_cinema_layout; retains the complete fine picture. */
void a2_compose_cinema(uint32_t *dst, int pitch, int scale,
                       const A2CinemaRaster *raster, const A2CinemaLayout *layout);
/* Returns0 without touching dst if extra scene storage is unavailable.
 * Original172 scene rows retain their exact pixels and destination position. */
int a2_compose_cinema_expanded(uint32_t *dst,int pitch,int scale,
                              const A2CinemaRaster *raster,const A2CinemaLayout *layout);
#endif
