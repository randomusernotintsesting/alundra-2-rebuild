/* Catches inclusive/double counting and treating time off CPU as CPU work. */
#include "phase_timing.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    A2PhaseAccounting state = {0};
    a2_phase_reset_at(&state, (A2PhaseStamp){0, 0});
    A2Phase outer = a2_phase_switch_at(&state, A2_PHASE_GPU,
                                     (A2PhaseStamp){10, 5});
    A2Phase nested = a2_phase_switch_at(&state, A2_PHASE_GPU,
                                      (A2PhaseStamp){15, 9});
    assert(outer == A2_PHASE_GUEST && nested == A2_PHASE_GPU);
    a2_phase_switch_at(&state, nested, (A2PhaseStamp){25, 17});
    a2_phase_switch_at(&state, outer, (A2PhaseStamp){40, 25});
    a2_phase_switch_at(&state, A2_PHASE_WAIT, (A2PhaseStamp){50, 33});
    a2_phase_switch_at(&state, A2_PHASE_WAIT, (A2PhaseStamp){150, 35});
    assert(state.elapsed[A2_PHASE_GUEST].wall_ns == 20);
    assert(state.elapsed[A2_PHASE_GUEST].cpu_ns == 13);
    assert(state.elapsed[A2_PHASE_GPU].wall_ns == 30);
    assert(state.elapsed[A2_PHASE_GPU].cpu_ns == 20);
    assert(state.elapsed[A2_PHASE_WAIT].wall_ns == 100);
    assert(state.elapsed[A2_PHASE_WAIT].cpu_ns == 2);
    uint64_t wall = 0, cpu = 0;
    for (int i = 0; i < A2_PHASE_COUNT; i++) {
        wall += state.elapsed[i].wall_ns;
        cpu += state.elapsed[i].cpu_ns;
    }
    assert(wall == 150 && cpu == 35 && state.switches == 6);

    /* Frame rollover preserves a scope spanning a vblank. */
    a2_phase_reset_at(&state, (A2PhaseStamp){150, 35});
    assert(state.current == A2_PHASE_WAIT && state.switches == 0);
    a2_phase_switch_at(&state, A2_PHASE_GUEST, (A2PhaseStamp){160, 35});
    assert(state.elapsed[A2_PHASE_WAIT].wall_ns == 10);
    assert(state.elapsed[A2_PHASE_WAIT].cpu_ns == 0);
    assert(state.elapsed[A2_PHASE_GPU].wall_ns == 0);

    /* Event polling is exclusive of handling, including nested polls, and
     * pad update begins only after the handler has returned to HOST. */
    state = (A2PhaseAccounting){0};
    a2_phase_reset_at(&state, (A2PhaseStamp){0, 0});
    A2Phase guest = a2_phase_switch_at(&state, A2_PHASE_HOST,
                                      (A2PhaseStamp){5, 2});
    A2Phase host = a2_phase_switch_at(&state, A2_PHASE_EVENT_POLL,
                                     (A2PhaseStamp){10, 4});
    A2Phase handler = a2_phase_switch_at(&state, A2_PHASE_EVENT,
                                        (A2PhaseStamp){14, 6});
    A2Phase handler_outer = a2_phase_switch_at(&state, A2_PHASE_EVENT_POLL,
                                              (A2PhaseStamp){20, 10});
    a2_phase_switch_at(&state, handler_outer, (A2PhaseStamp){23, 11});
    a2_phase_switch_at(&state, host, (A2PhaseStamp){30, 15});
    A2Phase pad_outer = a2_phase_switch_at(&state, A2_PHASE_PAD,
                                          (A2PhaseStamp){32, 16});
    a2_phase_switch_at(&state, pad_outer, (A2PhaseStamp){39, 20});
    a2_phase_switch_at(&state, A2_PHASE_WAIT, (A2PhaseStamp){40, 21});
    assert(guest == A2_PHASE_GUEST);
    assert(host == A2_PHASE_HOST);
    assert(handler == A2_PHASE_EVENT_POLL);
    assert(handler_outer == A2_PHASE_EVENT);
    assert(pad_outer == A2_PHASE_HOST);
    assert(state.elapsed[A2_PHASE_GUEST].wall_ns == 5);
    assert(state.elapsed[A2_PHASE_GUEST].cpu_ns == 2);
    assert(state.elapsed[A2_PHASE_HOST].wall_ns == 8);
    assert(state.elapsed[A2_PHASE_HOST].cpu_ns == 4);
    assert(state.elapsed[A2_PHASE_EVENT_POLL].wall_ns == 7);
    assert(state.elapsed[A2_PHASE_EVENT_POLL].cpu_ns == 3);
    assert(state.elapsed[A2_PHASE_EVENT].wall_ns == 13);
    assert(state.elapsed[A2_PHASE_EVENT].cpu_ns == 8);
    assert(state.elapsed[A2_PHASE_PAD].wall_ns == 7);
    assert(state.elapsed[A2_PHASE_PAD].cpu_ns == 4);

    /* Rollover retains a new subphase without charging pre-reset time twice. */
    a2_phase_reset_at(&state, (A2PhaseStamp){40, 21});
    assert(state.current == A2_PHASE_WAIT && state.switches == 0);
    a2_phase_switch_at(&state, A2_PHASE_EVENT_POLL, (A2PhaseStamp){50, 22});
    a2_phase_switch_at(&state, A2_PHASE_EVENT, (A2PhaseStamp){54, 24});
    a2_phase_reset_at(&state, (A2PhaseStamp){60, 27});
    assert(state.current == A2_PHASE_EVENT && state.switches == 0);
    a2_phase_switch_at(&state, A2_PHASE_HOST, (A2PhaseStamp){65, 29});
    assert(state.elapsed[A2_PHASE_EVENT].wall_ns == 5);
    assert(state.elapsed[A2_PHASE_EVENT].cpu_ns == 2);
    assert(state.elapsed[A2_PHASE_EVENT_POLL].wall_ns == 0);
    assert(state.elapsed[A2_PHASE_WAIT].wall_ns == 0);
    /* Catches command duration loss, inclusive starts and max-vs-sum mistakes. */
    A2PhaseCommand command = {0};
    a2_phase_command_at(&command, (A2PhaseStamp){100, 50}, (A2PhaseStamp){110, 55});
    a2_phase_command_at(&command, (A2PhaseStamp){1000, 500}, (A2PhaseStamp){1050, 530});
    assert(command.calls == 2);
    assert(command.total.wall_ns == 60 && command.total.cpu_ns == 35);
    assert(command.maximum.wall_ns == 50 && command.maximum.cpu_ns == 30);
    puts("phase timing: exclusive scopes, waits, rollover and command totals passed");
    return 0;
}
