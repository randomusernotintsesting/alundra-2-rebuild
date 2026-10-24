#ifndef A2_FRAME_PACER_H
#define A2_FRAME_PACER_H
#include <stdint.h>

typedef struct {
    uint64_t next_frame_ticks;
    uint64_t discarded_lateness_ticks;
    int rebased;
} A2FramePacerAdvance;

/* Pure policy for the existing absolute end-of-tick deadline. Zero requests
 * startup/replay reseeding. A frequency from SDL (at least 60 Hz) is expected;
 * retain the existing integer frequency / 60 period. */
static inline A2FramePacerAdvance a2_frame_pacer_advance(
        uint64_t deadline, uint64_t now, uint64_t frequency) {
    A2FramePacerAdvance step = {deadline, 0, 0};
    uint64_t lateness = deadline && now > deadline ? now - deadline : 0;
    /* Keep short stalls as recoverable debt; only a >250 ms discontinuity
     * seeds a new epoch. Advance exactly once, even during overload. */
    if (!deadline || lateness > frequency / 4) {
        step.rebased = 1;
        step.discarded_lateness_ticks = lateness;
        step.next_frame_ticks = now;
    }
    step.next_frame_ticks += frequency / 60;
    return step;
}

static inline int a2_frame_pacer_skip_present(
        uint64_t deadline, uint64_t now, uint64_t frequency,
        uint64_t last_present_ticks) {
    /* Debt alone can persist forever at exactly 60 Hz after a short stall.
     * Omit only redundant catch-up output while a completed presentation is
     * still less than one period old. Startup/reset and clock regression
     * always show the available frame. The caller records completion only
     * after SDL_RenderPresent, never after a skipped attempt. */
    if (!last_present_ticks || now < last_present_ticks ||
        now - last_present_ticks >= frequency / 60) return 0;
    if (!deadline || now <= deadline) return 0;
    uint64_t lateness = now - deadline;
    /* Ordinary jitter and long suspensions still present. The caller keeps
     * all compose/upload/draw/capture work and omits only the present call. */
    return lateness >= frequency / 60 && lateness <= frequency / 4;
}
#endif
