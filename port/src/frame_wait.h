#ifndef A2_FRAME_WAIT_H
#define A2_FRAME_WAIT_H
#include <stdint.h>

/* Normal operation forwards positive coarse waits unchanged to SDL.
 * A2_WAIT_PROBE=1 enables a macOS-only diagnostic comparison in this process.
 * It changes no thread/task policy and never spins for the requested interval.
 */
void a2_frame_wait_init(void);
void a2_frame_wait(uint32_t milliseconds, uint32_t frame);
#endif
