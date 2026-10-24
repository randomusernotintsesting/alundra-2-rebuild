#ifndef A2_CINEMA_H
#define A2_CINEMA_H

#include <stddef.h>
#include <stdint.h>

/* Native, unscaled display/raster coordinates from the current presentation. */
typedef struct {
    int dx, dy, dw, dh;
    int xo, yo, cw, ch;
    int on, overlay;
} A2CinemaRaster;

/* Source rows are relative to the displayed VRAM origin; destination rows
 * are relative to the complete TV canvas. Preserve X and the integer scale. */
typedef struct {
    int picture_src_y, picture_rows, picture_dst_y;
    int subtitle_src_y, subtitle_rows, subtitle_dst_y;
} A2CinemaLayout;

/* Read-only, allocation-free EVENT00 recognition. Returns 1 for the verified
 * picture/subtitle layout. Unknown or unsafe state returns 0 and clears out.
 * No-subtitle frames still center the complete picture. */
int a2_cinema_show_subtitles(int setting,int text_language,int voice_language);

int a2_cinema_layout(const uint8_t *ram, size_t ram_bytes,
                     const A2CinemaRaster *raster, A2CinemaLayout *out);

#endif
