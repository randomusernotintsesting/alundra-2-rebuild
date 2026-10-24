#ifndef A2_REPLAY_CONTROL_H
#define A2_REPLAY_CONTROL_H

#include <stddef.h>
#include <stdint.h>

#define REPLAY_CONTROL_MAX_TAPS 128

typedef struct {
    uint32_t start_frame;
    uint32_t duration;
    unsigned bit;
} ReplayTap;

typedef struct {
    uint32_t until_frame;
    size_t tap_count;
    ReplayTap taps[REPLAY_CONTROL_MAX_TAPS];
} ReplayControl;

/* File: positive uint32 until_frame, then start:bit[:duration] per line.
 * Duration defaults to four frames. Leading/trailing whitespace is accepted;
 * empty records, signs, extra fields, overlong lines and end overflow fail.
 * Returns 1 on success; any failure returns 0 without changing *control. */
int replay_control_load(const char *path, ReplayControl *control);

/* Combine active taps into a PS1 active-low button mask; no time/state changes. */
uint16_t replay_control_buttons(const ReplayControl *control, uint32_t frame);

#endif
