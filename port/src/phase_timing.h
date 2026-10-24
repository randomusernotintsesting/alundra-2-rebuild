#ifndef A2_PHASE_TIMING_H
#define A2_PHASE_TIMING_H

#include <stdint.h>

typedef enum {
    A2_PHASE_GUEST, A2_PHASE_HOST, A2_PHASE_EVENT_POLL, A2_PHASE_EVENT,
    A2_PHASE_PAD, A2_PHASE_CD, A2_PHASE_GPU,
    A2_PHASE_COMPOSE, A2_PHASE_UPLOAD, A2_PHASE_DRAW, A2_PHASE_PRESENT,
    A2_PHASE_IRQ, A2_PHASE_SPU_MIX, A2_PHASE_SPU_QUEUE, A2_PHASE_WAIT,
    A2_PHASE_WAIT_COARSE, A2_PHASE_WAIT_TAIL, A2_PHASE_DIAG, A2_PHASE_COUNT
} A2Phase;

typedef struct { uint64_t wall_ns, cpu_ns; } A2PhaseStamp;
typedef struct {
    A2PhaseStamp elapsed[A2_PHASE_COUNT];
    A2PhaseStamp last;
    A2Phase current;
    uint64_t switches;
    int started;
} A2PhaseAccounting;
typedef struct {
    A2PhaseStamp total, maximum;
    uint64_t calls;
} A2PhaseCommand;

/* Explicit stamps keep the exclusive accounting independently testable. */
A2Phase a2_phase_switch_at(A2PhaseAccounting *state, A2Phase next,
                         A2PhaseStamp now);
void a2_phase_reset_at(A2PhaseAccounting *state, A2PhaseStamp now);
void a2_phase_command_at(A2PhaseCommand *command, A2PhaseStamp start,
                         A2PhaseStamp end);

#ifdef A2_PHASE_TIMING
extern int a2_phase_enabled;
void a2_phase_init(void);
void a2_phase_frame(uint32_t frame);
A2Phase a2_phase_switch(A2Phase next);
A2PhaseStamp a2_phase_clock(void);
void a2_phase_record_gpu(unsigned command, A2PhaseStamp start);
void a2_phase_record_pace_plan(uint64_t frequency, uint64_t before,
                              uint64_t deadline, uint32_t delay_ms);
void a2_phase_record_pace_end(uint64_t after, unsigned tail_calls);
static inline A2PhaseStamp a2_phase_now(void) {
    return a2_phase_enabled ? a2_phase_clock() : (A2PhaseStamp){0, 0};
}
static inline void a2_phase_gpu_command(unsigned command, A2PhaseStamp start) {
    if (a2_phase_enabled) a2_phase_record_gpu(command, start);
}
static inline void a2_phase_pace_plan(uint64_t frequency, uint64_t before,
                                     uint64_t deadline, uint32_t delay_ms) {
    if (a2_phase_enabled)
        a2_phase_record_pace_plan(frequency, before, deadline, delay_ms);
}
static inline void a2_phase_pace_end(uint64_t after, unsigned tail_calls) {
    if (a2_phase_enabled) a2_phase_record_pace_end(after, tail_calls);
}
static inline A2Phase a2_phase_enter(A2Phase next) {
    return a2_phase_enabled ? a2_phase_switch(next) : A2_PHASE_GUEST;
}
static inline void a2_phase_leave(A2Phase previous) {
    if (a2_phase_enabled) (void)a2_phase_switch(previous);
}
#else
static inline void a2_phase_init(void) { }
static inline void a2_phase_frame(uint32_t frame) { (void)frame; }
static inline A2PhaseStamp a2_phase_now(void) { return (A2PhaseStamp){0, 0}; }
static inline void a2_phase_gpu_command(unsigned command, A2PhaseStamp start) {
    (void)command; (void)start;
}
static inline void a2_phase_pace_plan(uint64_t frequency, uint64_t before,
                                     uint64_t deadline, uint32_t delay_ms) {
    (void)frequency; (void)before; (void)deadline; (void)delay_ms;
}
static inline void a2_phase_pace_end(uint64_t after, unsigned tail_calls) {
    (void)after; (void)tail_calls;
}
static inline A2Phase a2_phase_enter(A2Phase next) {
    (void)next; return A2_PHASE_GUEST;
}
static inline void a2_phase_leave(A2Phase previous) { (void)previous; }
#endif
#endif
