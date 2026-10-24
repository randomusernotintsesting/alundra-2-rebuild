#include "replay_control.h"
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

/* Bounded text records, including a final record without a newline. Reject
 * embedded NULs rather than silently treating a binary suffix as absent. */
static int read_line(FILE *file, char line[128]) {
    size_t length = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') { line[length] = 0; return 1; }
        if (ch == 0 || length == 127) return -1;
        line[length++] = (char)ch;
    }
    if (ferror(file)) return -1;
    line[length] = 0;
    return length ? 1 : 0;
}

static void whitespace(const char **cursor) {
    while (isspace((unsigned char)**cursor)) (*cursor)++;
}

static int number(const char **cursor, uint32_t *value) {
    whitespace(cursor);
    if (**cursor < '0' || **cursor > '9') return 0;
    errno = 0;
    char *end;
    unsigned long parsed = strtoul(*cursor, &end, 10);
    if (errno == ERANGE || parsed > UINT32_MAX) return 0;
    *cursor = end;
    whitespace(cursor);
    *value = (uint32_t)parsed;
    return 1;
}

static int tap(const char *cursor, ReplayTap *out) {
    uint32_t start, bit, duration = 4;
    if (!number(&cursor, &start) || *cursor++ != ':' ||
        !number(&cursor, &bit) || bit > 15) return 0;
    if (*cursor == ':') {
        cursor++;
        if (!number(&cursor, &duration)) return 0;
    }
    if (*cursor || !duration || start > UINT32_MAX - duration) return 0;
    out->start_frame = start;
    out->duration = duration;
    out->bit = bit;
    return 1;
}

int replay_control_load(const char *path, ReplayControl *control) {
    if (!path || !control) return 0;
    FILE *file = fopen(path, "r");
    if (!file) return 0;
    ReplayControl pending = {0};
    char line[128];
    const char *cursor = line;
    int ok = read_line(file, line) == 1 &&
             number(&cursor, &pending.until_frame) &&
             pending.until_frame != 0 && *cursor == 0;
    while (ok) {
        int status = read_line(file, line);
        if (!status) break;
        if (status < 0 || pending.tap_count == REPLAY_CONTROL_MAX_TAPS ||
            !tap(line, &pending.taps[pending.tap_count])) {
            ok = 0;
            break;
        }
        pending.tap_count++;
    }
    if (fclose(file) != 0) ok = 0;
    if (ok) *control = pending;
    return ok;
}

uint16_t replay_control_buttons(const ReplayControl *control, uint32_t frame) {
    uint16_t buttons = UINT16_MAX;
    if (!control) return buttons;
    for (size_t i = 0; i < control->tap_count && i < REPLAY_CONTROL_MAX_TAPS; i++) {
        const ReplayTap *press = &control->taps[i];
        if (press->bit < 16 && frame >= press->start_frame &&
            frame - press->start_frame < press->duration)
            buttons &= (uint16_t)~(1u << press->bit);
    }
    return buttons;
}
