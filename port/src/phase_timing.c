#ifndef A2_PHASE_TIMING
#define A2_PHASE_TIMING 1
#endif
#include "phase_timing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

A2Phase a2_phase_switch_at(A2PhaseAccounting *state, A2Phase next,
                         A2PhaseStamp now) {
    A2Phase previous = state->current;
    if (state->started) {
        state->elapsed[previous].wall_ns += now.wall_ns - state->last.wall_ns;
        state->elapsed[previous].cpu_ns += now.cpu_ns - state->last.cpu_ns;
    }
    state->last = now;
    state->current = next;
    state->started = 1;
    state->switches++;
    return previous;
}

void a2_phase_reset_at(A2PhaseAccounting *state, A2PhaseStamp now) {
    memset(state->elapsed, 0, sizeof state->elapsed);
    state->last = now;
    state->switches = 0;
    state->started = 1;
}

void a2_phase_command_at(A2PhaseCommand *command, A2PhaseStamp start,
                         A2PhaseStamp end) {
    A2PhaseStamp elapsed = {end.wall_ns - start.wall_ns, end.cpu_ns - start.cpu_ns};
    command->calls++;
    command->total.wall_ns += elapsed.wall_ns;
    command->total.cpu_ns += elapsed.cpu_ns;
    if (elapsed.wall_ns > command->maximum.wall_ns)
        command->maximum.wall_ns = elapsed.wall_ns;
    if (elapsed.cpu_ns > command->maximum.cpu_ns)
        command->maximum.cpu_ns = elapsed.cpu_ns;
}

int a2_phase_enabled;
static A2PhaseAccounting runtime;
static A2PhaseStamp totals[A2_PHASE_COUNT], maxima[A2_PHASE_COUNT];
static uint64_t process_last, process_total, switches_total;
static unsigned window_frames;
static uint32_t first_frame;
static A2PhaseCommand commands[256];
static struct {
    uint64_t frequency, before, deadline, after;
    uint32_t delay_ms;
    unsigned tail_calls;
} pace;
static const char *const names[A2_PHASE_COUNT] = {
    "guest", "host", "event_poll", "event", "pad", "cd", "gpu", "compose",
    "upload", "draw", "present", "irq", "spu_mix", "spu_queue", "wait",
    "wait_coarse", "wait_tail", "diag"
};

static int read_clock(clockid_t id, uint64_t *result) {
    struct timespec stamp;
    if (clock_gettime(id, &stamp)) {
        fprintf(stderr, "phasestat: required clock unavailable; timing disabled\n");
        a2_phase_enabled = 0;
        return 0;
    }
    *result = (uint64_t)stamp.tv_sec * 1000000000u + (uint64_t)stamp.tv_nsec;
    return 1;
}

static int read_stamp(A2PhaseStamp *stamp) {
    return read_clock(CLOCK_MONOTONIC, &stamp->wall_ns) &&
           read_clock(CLOCK_THREAD_CPUTIME_ID, &stamp->cpu_ns);
}

void a2_phase_init(void) {
    a2_phase_enabled = getenv("A2_TIMING") != NULL;
    if (!a2_phase_enabled) return;
    A2PhaseStamp now;
    if (!read_stamp(&now) || !read_clock(CLOCK_PROCESS_CPUTIME_ID, &process_last))
        return;
    memset(&runtime, 0, sizeof runtime);
    memset(totals, 0, sizeof totals);
    memset(maxima, 0, sizeof maxima);
    memset(commands, 0, sizeof commands);
    memset(&pace, 0, sizeof pace);
    process_total = switches_total = window_frames = 0;
    a2_phase_reset_at(&runtime, now);
}

A2Phase a2_phase_switch(A2Phase next) {
    A2PhaseStamp now;
    if (!read_stamp(&now)) return runtime.current;
    return a2_phase_switch_at(&runtime, next, now);
}

A2PhaseStamp a2_phase_clock(void) {
    A2PhaseStamp now = {0, 0};
    (void)read_stamp(&now);
    return now;
}

void a2_phase_record_gpu(unsigned command, A2PhaseStamp start) {
    A2PhaseStamp end;
    if (command < 256 && read_stamp(&end))
        a2_phase_command_at(&commands[command], start, end);
}

void a2_phase_record_pace_plan(uint64_t frequency, uint64_t before,
                              uint64_t deadline, uint32_t delay_ms) {
    pace.frequency = frequency;
    pace.before = before;
    pace.deadline = deadline;
    pace.delay_ms = delay_ms;
}

void a2_phase_record_pace_end(uint64_t after, unsigned tail_calls) {
    pace.after = after;
    pace.tail_calls = tail_calls;
}

void a2_phase_frame(uint32_t frame) {
    if (!a2_phase_enabled) return;
    A2PhaseStamp now;
    uint64_t process_now;
    if (!read_stamp(&now) || !read_clock(CLOCK_PROCESS_CPUTIME_ID, &process_now))
        return;
    a2_phase_switch_at(&runtime, A2_PHASE_DIAG, now);
    uint64_t wall = 0, cpu = 0;
    uint64_t process = process_now - process_last;
    int largest = 0, second = 1;
    for (int i = 0; i < A2_PHASE_COUNT; i++) {
        A2PhaseStamp value = runtime.elapsed[i];
        wall += value.wall_ns;
        cpu += value.cpu_ns;
        totals[i].wall_ns += value.wall_ns;
        totals[i].cpu_ns += value.cpu_ns;
        if (value.wall_ns > maxima[i].wall_ns) maxima[i].wall_ns = value.wall_ns;
        if (value.cpu_ns > maxima[i].cpu_ns) maxima[i].cpu_ns = value.cpu_ns;
        if (value.wall_ns > runtime.elapsed[largest].wall_ns) largest = i;
    }
    if (largest == second) second = 0;
    for (int i = 0; i < A2_PHASE_COUNT; i++)
        if (i != largest && runtime.elapsed[i].wall_ns > runtime.elapsed[second].wall_ns)
            second = i;
    if (wall > 25000000u) {
        fprintf(stderr, "phaseframe: frame=%u wall_ms=%.3f cpu_ms=%.3f process_cpu_ms=%.3f "
                "first=%s first_wall_ms=%.3f first_cpu_ms=%.3f "
                "second=%s second_wall_ms=%.3f second_cpu_ms=%.3f switches=%llu "
                "pace_frequency=%llu pace_request_ms=%.3f pace_delay_ms=%u "
                "pace_counter_ms=%.3f pace_tail_calls=%u\n",
                frame, wall/1e6, cpu/1e6, process/1e6,
                names[largest], runtime.elapsed[largest].wall_ns/1e6,
                runtime.elapsed[largest].cpu_ns/1e6,
                names[second], runtime.elapsed[second].wall_ns/1e6,
                runtime.elapsed[second].cpu_ns/1e6,
                (unsigned long long)runtime.switches,
                (unsigned long long)pace.frequency,
                pace.frequency && pace.deadline > pace.before ?
                    1000.0 * (pace.deadline - pace.before) / pace.frequency : 0.0,
                pace.delay_ms,
                pace.frequency && pace.after >= pace.before ?
                    1000.0 * (pace.after - pace.before) / pace.frequency : 0.0,
                pace.tail_calls);
    }
    if (!window_frames) first_frame = frame;
    process_total += process;
    switches_total += runtime.switches;
    if (++window_frames == 60) {
        uint64_t total_wall = 0, total_cpu = 0;
        for (int i = 0; i < A2_PHASE_COUNT; i++) {
            total_wall += totals[i].wall_ns;
            total_cpu += totals[i].cpu_ns;
        }
        fprintf(stderr, "phasestat: first_frame=%u frame=%u frames=%u wall_ms=%.3f "
                "cpu_ms=%.3f process_cpu_ms=%.3f switches=%llu",
                first_frame, frame, window_frames, total_wall/1e6, total_cpu/1e6,
                process_total/1e6, (unsigned long long)switches_total);
        for (int i = 0; i < A2_PHASE_COUNT; i++)
            fprintf(stderr, " %s_wall_ms=%.3f %s_cpu_ms=%.3f %s_max_wall_ms=%.3f %s_max_cpu_ms=%.3f",
                    names[i], totals[i].wall_ns/1e6, names[i], totals[i].cpu_ns/1e6,
                    names[i], maxima[i].wall_ns/1e6, names[i], maxima[i].cpu_ns/1e6);
        fputc('\n', stderr);
        /* Command totals are inclusive packet timings, a separate breakdown
         * of GPU work; they must not be added to the exclusive phase totals. */
        for (unsigned i = 0; i < 256; i++) if (commands[i].calls) {
            A2PhaseCommand *c = &commands[i];
            fprintf(stderr, "gpucommandstat: first_frame=%u frame=%u cmd=%02X calls=%llu "
                    "wall_ms=%.3f cpu_ms=%.3f max_wall_ms=%.3f max_cpu_ms=%.3f\n",
                    first_frame, frame, i, (unsigned long long)c->calls,
                    c->total.wall_ns/1e6, c->total.cpu_ns/1e6,
                    c->maximum.wall_ns/1e6, c->maximum.cpu_ns/1e6);
        }
        memset(commands, 0, sizeof commands);
        memset(totals, 0, sizeof totals);
        memset(maxima, 0, sizeof maxima);
        process_total = switches_total = window_frames = 0;
    }
    /* Retain the pre-log stamp: profiler logging is DIAG in the next frame,
     * so the exclusive totals account for all wall/thread CPU time. */
    a2_phase_reset_at(&runtime, now);
    process_last = process_now;
    memset(&pace, 0, sizeof pace);
}
