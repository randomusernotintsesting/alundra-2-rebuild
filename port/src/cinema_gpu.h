#ifndef A2_CINEMA_GPU_H
#define A2_CINEMA_GPU_H
#include <stdint.h>
void gpu_set_cinema_expansion(int enabled);
int gpu_cinema_expansion_ready(int buffer_y);
/* Virtual fine y is relative to the original picture: [-22*S,0) or
 * [172*S,194*S). Rows contain320*S pixels and live until the next GPU write. */
const uint16_t *gpu_cinema_extra_row(int buffer_y,int virtual_fine_y);
/* Fine row0..32*S-1 relative to the original two-line slot at y174. */
const uint8_t *gpu_cinema_subtitle_alpha_row(int buffer_y,int fine_row);
#endif
