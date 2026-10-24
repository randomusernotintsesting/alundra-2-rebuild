/* Real routing/absolute-deadline code; only asynchronous wait APIs are fake.
 * Catches enabling the experiment by default, alternating by frame parity,
 * changing requested milliseconds, or moving a deadline after interruption.
 */
#include <assert.h>
#include <SDL.h>
#include <mach/mach.h>
#include <mach/mach_time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
static unsigned sdl_calls, native_calls, interruptions;
static Uint32 last_ms;
static uint64_t deadlines[8];
static const char *observed_video = "observed-video";
static const char *observed_audio = "observed-audio";
/* Discover backend state without opening a real window/audio device. */
const char *host_current_video(void) { return observed_video; }
const char *host_current_audio(void) { return observed_audio; }
static void host_sdl_delay(Uint32 ms) { sdl_calls++; last_ms = ms; }
static uint64_t host_absolute_time(void) { return 1000000u; }
static kern_return_t host_timebase(mach_timebase_info_t result) {
    result->numer = 125; result->denom = 3; return KERN_SUCCESS;
}
static kern_return_t host_wait_until(uint64_t deadline) {
    assert(native_calls < 8);
    deadlines[native_calls++] = deadline;
    if (interruptions) { interruptions--; return KERN_ABORTED; }
    return KERN_SUCCESS;
}
#define SDL_Delay host_sdl_delay
#define SDL_GetCurrentVideoDriver host_current_video
#define SDL_GetCurrentAudioDriver host_current_audio
#define mach_absolute_time host_absolute_time
#define mach_timebase_info host_timebase
#define mach_wait_until host_wait_until
#include "../src/frame_wait.c"

static void capture_init(char *buffer, size_t capacity) {
    FILE *capture = tmpfile();
    assert(capture);
    fflush(stderr);
    int saved = dup(STDERR_FILENO);
    assert(saved >= 0 && dup2(fileno(capture), STDERR_FILENO) >= 0);
    a2_frame_wait_init();
    fflush(stderr);
    assert(dup2(saved, STDERR_FILENO) >= 0);
    close(saved);
    rewind(capture);
    size_t used = fread(buffer, 1, capacity - 1, capture);
    buffer[used] = '\0';
    assert(!ferror(capture));
    fclose(capture);
}

int main(void) {
    char metadata[512];
    unsetenv("A2_WAIT_PROBE");
    unsetenv("A2_AUDIOSTAT");
    capture_init(metadata, sizeof metadata);
    assert(!metadata[0]);
    for (unsigned frame = 0; frame < 4; frame++) a2_frame_wait(7, frame);
    assert(sdl_calls == 4 && native_calls == 0 && last_ms == 7);
    assert(setenv("A2_WAIT_PROBE", "0", 1) == 0);
    capture_init(metadata, sizeof metadata);
    assert(!metadata[0]);
    a2_frame_wait(3, 4);
    assert(sdl_calls == 5 && native_calls == 0 && last_ms == 3);

    assert(setenv("A2_WAIT_PROBE", "1", 1) == 0);
    /* Requested environment must not be reported as the observed backend. */
    assert(setenv("SDL_VIDEODRIVER", "requested-video", 1) == 0);
    assert(setenv("SDL_AUDIODRIVER", "requested-audio", 1) == 0);
    capture_init(metadata, sizeof metadata);
    assert(strstr(metadata, "video_driver=observed-video"));
    assert(strstr(metadata, "audio_driver=observed-audio"));
    assert(!strstr(metadata, "requested-"));
    a2_frame_wait(7, 100);
    assert(sdl_calls == 6 && native_calls == 0 && last_ms == 7);
    /* Both frames even: routing must follow coarse-call index, not frames. */
    a2_frame_wait(10, 102);
    assert(sdl_calls == 6 && native_calls == 1);
    assert(deadlines[0] == 1240000u); /* 10ms *24MHz plus1000000 */
    a2_frame_wait(0, 103);
    a2_frame_wait(2, 104);
    assert(sdl_calls == 7 && native_calls == 1 && last_ms == 2);
    interruptions = 1;
    a2_frame_wait(5, 106);
    assert(native_calls == 3 && deadlines[1] == 1120000u && deadlines[2] == 1120000u);
    /* A new process initialization starts with the SDL control again. */
    observed_video = observed_audio = NULL;
    capture_init(metadata, sizeof metadata);
    assert(strstr(metadata, "video_driver=uninitialized"));
    assert(strstr(metadata, "audio_driver=uninitialized"));
    a2_frame_wait(1, 108);
    assert(sdl_calls == 8 && native_calls == 3 && last_ms == 1);
    /* Normal audio telemetry observes backends without changing wait routing. */
    unsetenv("A2_WAIT_PROBE");
    assert(setenv("A2_AUDIOSTAT", "1", 1) == 0);
    observed_video = "dummy";
    observed_audio = "coreaudio";
    capture_init(metadata, sizeof metadata);
    assert(strstr(metadata, "video_driver=dummy"));
    assert(strstr(metadata, "audio_driver=coreaudio"));
    a2_frame_wait(6, 110);
    a2_frame_wait(9, 112);
    assert(sdl_calls == 10 && native_calls == 3 && last_ms == 9);
    assert(setenv("A2_AUDIOSTAT", "0", 1) == 0);
    capture_init(metadata, sizeof metadata);
    assert(!metadata[0]);
    puts("frame wait: default SDL, coarse-call alternation and absolute retry passed");
    return 0;
}
