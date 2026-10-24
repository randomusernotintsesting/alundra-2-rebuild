#include "replay_control.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char path[] = "/tmp/alundra-replay-control-XXXXXX";

static void write_control(const char *text) {
    FILE *file = fopen(path, "w");
    assert(file);
    assert(fputs(text, file) >= 0);
    assert(fclose(file) == 0);
}

static void reject_unchanged(const char *text, ReplayControl *control) {
    ReplayControl previous;
    memcpy(&previous, control, sizeof previous);
    write_control(text);
    assert(replay_control_load(path, control) == 0);
    assert(memcmp(&previous, control, sizeof previous) == 0);
}

int main(void) {
    int fd = mkstemp(path);
    assert(fd >= 0 && close(fd) == 0);
    ReplayControl control = {0};
    write_control("32");
    assert(replay_control_load(path, &control) == 1);
    assert(control.until_frame == 32 && control.tap_count == 0);
    assert(replay_control_buttons(&control, 12) == UINT16_MAX);

    write_control(" 100 \r\n10:4\n12:15:6\n12:4:1\n0:0:1\n");
    assert(replay_control_load(path, &control) == 1);
    assert(control.until_frame == 100 && control.tap_count == 4);
    assert(replay_control_buttons(&control, 0) == 0xfffe);
    assert(replay_control_buttons(&control, 9) == 0xffff);
    assert(replay_control_buttons(&control, 10) == 0xffef);
    assert(replay_control_buttons(&control, 12) == 0x7fef);
    assert(replay_control_buttons(&control, 13) == 0x7fef);
    assert(replay_control_buttons(&control, 14) == 0x7fff);
    assert(replay_control_buttons(&control, 17) == 0x7fff);
    assert(replay_control_buttons(&control, 18) == 0xffff);

    const char *invalid[] = {
        "", "\n", "0\n", "-1\n", "+1\n", "4294967296\n",
        "9999999999999999999999999999999\n", "1oops\n", "10:1\n",
        "50\n\n", "50\n1:16\n", "50\n1:-1\n", "50\n-1:1\n",
        "50\n1\n", "50\n1:1:\n", "50\n1:1:0\n", "50\n1:1:-2\n",
        "50\n1:1:4:5\n", "50\n1:1 extra\n", "50\n4294967296:1\n",
        "50\n1:1:4294967296\n", "50\n4294967292:1\n",
        "50\n4294967295:1:1\n"
    };
    for (size_t i = 0; i < sizeof invalid / sizeof invalid[0]; i++)
        reject_unchanged(invalid[i], &control);

    write_control("4294967295\n4294967291:15\n");
    assert(replay_control_load(path, &control) == 1);
    assert(control.until_frame == UINT32_MAX);
    assert(replay_control_buttons(&control, UINT32_MAX - 1) == 0x7fff);
    assert(replay_control_buttons(&control, UINT32_MAX) == 0xffff);

    FILE *file = fopen(path, "w");
    assert(file && fputs("50\n", file) >= 0);
    for (unsigned i = 0; i < REPLAY_CONTROL_MAX_TAPS; i++)
        assert(fputs("1:0\n", file) >= 0);
    assert(fclose(file) == 0);
    assert(replay_control_load(path, &control) == 1);
    assert(control.tap_count == REPLAY_CONTROL_MAX_TAPS);
    ReplayControl previous;
    memcpy(&previous, &control, sizeof previous);
    file = fopen(path, "a");
    assert(file && fputs("1:1\n", file) >= 0 && fclose(file) == 0);
    assert(replay_control_load(path, &control) == 0);
    assert(memcmp(&previous, &control, sizeof previous) == 0);

    char long_line[512];
    memset(long_line, ' ', sizeof long_line);
    memcpy(long_line, "50", 2);
    long_line[sizeof long_line - 1] = 0;
    reject_unchanged(long_line, &control);
    file = fopen(path, "w");
    const char embedded_nul[] = {'5', '0', 0, 'x'};
    assert(file && fwrite(embedded_nul, 1, sizeof embedded_nul, file) == sizeof embedded_nul);
    assert(fclose(file) == 0);
    assert(replay_control_load(path, &control) == 0);
    assert(memcmp(&previous, &control, sizeof previous) == 0);
    assert(replay_control_load(NULL, &control) == 0);
    assert(replay_control_load(path, NULL) == 0);
    assert(replay_control_buttons(NULL, 1) == UINT16_MAX);
    assert(unlink(path) == 0);
    assert(replay_control_load(path, &control) == 0);
    assert(memcmp(&previous, &control, sizeof previous) == 0);
    puts("replay control parsing, button intervals, bounds and transactional reload passed");
    return 0;
}
