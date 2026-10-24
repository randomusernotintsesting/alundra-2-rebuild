#ifndef A2_NATIVE_COLOR_PREVIEW_H
#define A2_NATIVE_COLOR_PREVIEW_H
#include <stdint.h>
/* Pure RGB result of native NCDS sf=1,lm=1 with a replacement base color.
 * Does not read or mutate the guest GTE, FIFO, flags, RAM or commands. */
int a2_color_preview_ncds(const uint32_t data[32], const uint32_t control[32],
                          uint32_t base_rgb, uint32_t *result);
#endif
