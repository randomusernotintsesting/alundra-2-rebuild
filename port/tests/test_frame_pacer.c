/* Real pure pacing policy with a controlled clock. The literal timelines catch
 * discarded debt, premature presentation skipping, and multiple deadline
 * advances per tick. No renderer or guest work is replaced in production. */
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include "frame_pacer.h"

static unsigned failures;

static void check(const char *name, const char *field, uint64_t got, uint64_t want) {
    if (got == want) return;
    fprintf(stderr, "%s: %s got=%" PRIu64 " want=%" PRIu64 "\n",
            name, field, got, want);
    failures++;
}

static void check_advance(const char *name, uint64_t deadline, uint64_t now,
                          uint64_t frequency, uint64_t next, int rebased,
                          uint64_t discarded) {
    A2FramePacerAdvance step = a2_frame_pacer_advance(deadline, now, frequency);
    check(name, "next deadline", step.next_frame_ticks, next);
    check(name, "rebase", step.rebased, rebased);
    check(name, "discarded debt", step.discarded_lateness_ticks, discarded);
}

static void test_deadline_boundaries(void) {
    /* 60 kHz makes one frame 1000 ticks and the suspension bound 15000. */
    check_advance("startup", 0, 60000, 60000, 61000, 1, 0);
    check_advance("zero clock startup", 0, 0, 60000, 1000, 1, 0);
    check_advance("on time", 61000, 61000, 60000, 62000, 0, 0);
    check_advance("sub-frame jitter", 61000, 61999, 60000, 62000, 0, 0);
    check_advance("one frame late", 61000, 62000, 60000, 62000, 0, 0);
    check_advance("recoverable debt", 61000, 62001, 60000, 62000, 0, 0);
    check_advance("exact suspension bound", 61000, 76000, 60000, 62000, 0, 0);
    check_advance("over suspension bound", 61000, 76001, 60000, 77001, 1, 15001);
    check_advance("long suspension", 61000, 661000, 60000, 662000, 1, 600000);
    check_advance("explicit replay reset", 0, 96000, 60000, 97000, 1, 0);
    check_advance("frequency division remains floored", 10000, 10000, 1001,
                  10016, 0, 0);
    check_advance("fractional frequency exact bound", 10016, 10266, 1001,
                  10032, 0, 0);
    check_advance("fractional frequency over bound", 10016, 10267, 1001,
                  10283, 1, 251);
}

static void test_presentation_boundaries(void) {
    /* A just-completed present isolates the original debt thresholds below. */
    static const struct {
        const char *name;
        uint64_t deadline, now, frequency;
        int skip;
    } cases[] = {
        {"unseeded presentation", 0, 60000, 60000, 0},
        {"ahead of deadline", 61000, 60000, 60000, 0},
        {"on deadline", 61000, 61000, 60000, 0},
        {"below one period", 61000, 61999, 60000, 0},
        {"exact one period", 61000, 62000, 60000, 1},
        {"over one period", 61000, 62001, 60000, 1},
        {"exact 250 ms", 61000, 76000, 60000, 1},
        {"over 250 ms", 61000, 76001, 60000, 0},
        {"long suspend presents", 61000, 661000, 60000, 0},
        {"replay reset presents", 0, 96000, 60000, 0},
        {"floored period below boundary", 10016, 10031, 1001, 0},
        {"floored period exact boundary", 10016, 10032, 1001, 1},
        {"floored suspension exact boundary", 10016, 10266, 1001, 1},
        {"floored suspension over boundary", 10016, 10267, 1001, 0},
    };
    for (unsigned i = 0; i < sizeof cases / sizeof cases[0]; i++) {
        check(cases[i].name, "skip presentation",
              a2_frame_pacer_skip_present(cases[i].deadline, cases[i].now,
                                          cases[i].frequency, cases[i].now), cases[i].skip);
    }
}

static void test_presentation_age(void) {
    static const struct {
        const char *name;
        uint64_t deadline,now,frequency,last;
        int skip;
    } cases[] = {
        {"first presentation despite debt",61000,66000,60000,0,0},
        {"recent output permits catch-up",61000,66000,60000,65500,1},
        {"one tick before output due",61000,66000,60000,65001,1},
        {"exact period must present",61000,66000,60000,65000,0},
        {"older output must present",61000,66000,60000,64000,0},
        {"clock regression must present",61000,66000,60000,66001,0},
        {"reset deadline must present",0,66000,60000,65900,0},
        {"nondivisible recent output",10016,10200,1001,10185,1},
        {"nondivisible due output",10016,10200,1001,10184,0},
        {"no floored period cannot skip",100,102,1,102,0},
        {"large clock recent output",UINT64_MAX-6000,UINT64_MAX-1,60000,UINT64_MAX-501,1},
        {"large clock due output",UINT64_MAX-6000,UINT64_MAX-1,60000,UINT64_MAX-1001,0},
    };
    for(unsigned i=0;i<sizeof cases/sizeof cases[0];i++)
        check(cases[i].name,"skip presentation",
              a2_frame_pacer_skip_present(cases[i].deadline,cases[i].now,
                                         cases[i].frequency,cases[i].last),cases[i].skip);
}

static void test_accumulated_debt(void) {
    static const uint64_t now[] = {62001, 64002, 66003};
    static const uint64_t next[] = {62000, 63000, 64000};
    uint64_t deadline = 61000;
    for (unsigned i = 0; i < 3; i++) {
        A2FramePacerAdvance step = a2_frame_pacer_advance(deadline, now[i], 60000);
        check("accumulated debt", "next deadline", step.next_frame_ticks, next[i]);
        check("accumulated debt", "rebase", step.rebased, 0);
        check("accumulated debt", "discarded debt", step.discarded_lateness_ticks, 0);
        deadline = step.next_frame_ticks;
    }
}

typedef struct {
    uint64_t work_ticks, end_ticks, next_ticks;
    int skip, rebased;
    uint64_t discarded_ticks;
} Tick;

static void run_timeline(const char *name, const Tick *ticks, unsigned count,
                         uint64_t presentation_ticks) {
    uint64_t now = 60000, deadline = 61000, last_present = 60000;
    for (unsigned i = 0; i < count; i++) {
        char label[128];
        snprintf(label, sizeof label, "%s tick %u", name, i + 1);
        now += ticks[i].work_ticks;
        int skip = a2_frame_pacer_skip_present(deadline, now, 60000, last_present);
        check(label, "skip presentation", skip, ticks[i].skip);
        if (!skip) { now += presentation_ticks; last_present = now; }
        if (now < deadline) now = deadline; /* The unchanged end-of-tick wait. */
        A2FramePacerAdvance step = a2_frame_pacer_advance(deadline, now, 60000);
        check(label, "end time", now, ticks[i].end_ticks);
        check(label, "next deadline", step.next_frame_ticks, ticks[i].next_ticks);
        check(label, "rebase", step.rebased, ticks[i].rebased);
        check(label, "discarded debt", step.discarded_lateness_ticks,
              ticks[i].discarded_ticks);
        deadline = step.next_frame_ticks;
    }
}

static void test_stall_recovery(void) {
    /* A 50 ms work stall and three 2 ms ticks recover the original epoch. */
    static const Tick ticks[] = {
        {3000, 63000, 62000, 0, 0, 0},
        { 120, 63120, 63000, 1, 0, 0},
        { 120, 63240, 64000, 0, 0, 0},
        { 120, 64000, 65000, 0, 0, 0},
    };
    run_timeline("50 ms stall recovery", ticks, sizeof ticks / sizeof ticks[0], 0);
}

static void test_repeated_bursts(void) {
    /* Every third tick costs 30 ms, the others 2 ms. A controlled 10 ms
     * presentation wait exposes accumulated debt; light catch-up frames
     * can still skip recent output without starving later completed frames. This is a fixture, not an SDL timing model. */
    static const Tick ticks[] = {
        {1800, 62400, 62000, 0, 0, 0},
        { 120, 63120, 63000, 0, 0, 0},
        { 120, 63840, 64000, 0, 0, 0},
        {1800, 66240, 65000, 0, 0, 0},
        { 120, 66360, 66000, 1, 0, 0},
        { 120, 67080, 67000, 0, 0, 0},
        {1800, 69480, 68000, 0, 0, 0},
        { 120, 69600, 69000, 1, 0, 0},
        { 120, 70320, 70000, 0, 0, 0},
        {1800, 72720, 71000, 0, 0, 0},
        { 120, 72840, 72000, 1, 0, 0},
        { 120, 73560, 73000, 0, 0, 0},
        { 120, 74280, 74000, 0, 0, 0},
        { 120, 75000, 75000, 0, 0, 0},
        { 120, 75720, 76000, 0, 0, 0},
        { 120, 76440, 77000, 0, 0, 0},
    };
    run_timeline("one-in-three 30 ms bursts", ticks, sizeof ticks / sizeof ticks[0], 600);
}

static void test_sustained_overload(void) {
    /* No extra guest iterations: advance exactly one period each tick until
     * debt exceeds 250 ms, then seed once and continue the same policy. */
    static const Tick ticks[] = {
        {2000, 62000, 62000, 0, 0, 0},
        {2000, 64000, 63000, 0, 0, 0},
        {2000, 66000, 64000, 0, 0, 0},
        {2000, 68000, 65000, 0, 0, 0},
        {2000, 70000, 66000, 0, 0, 0},
        {2000, 72000, 67000, 0, 0, 0},
        {2000, 74000, 68000, 0, 0, 0},
        {2000, 76000, 69000, 0, 0, 0},
        {2000, 78000, 70000, 0, 0, 0},
        {2000, 80000, 71000, 0, 0, 0},
        {2000, 82000, 72000, 0, 0, 0},
        {2000, 84000, 73000, 0, 0, 0},
        {2000, 86000, 74000, 0, 0, 0},
        {2000, 88000, 75000, 0, 0, 0},
        {2000, 90000, 76000, 0, 0, 0},
        {2000, 92000, 93000, 0, 1, 16000},
        {2000, 94000, 94000, 0, 0, 0},
    };
    run_timeline("sustained overload", ticks, sizeof ticks / sizeof ticks[0], 0);
}

static void test_visible_progress(const char *name, uint64_t work, uint64_t stall) {
    uint64_t now=60000,deadline=61000,last_present=60000;
    unsigned presented=0,starved=0,consecutive=0,longest=0;
    for(unsigned i=0;i<1200;i++) {
        now+=i==0&&stall?stall:work;
        int skip=a2_frame_pacer_skip_present(deadline,now,60000,last_present);
        if(skip) {
            if(now-last_present>=1000)starved++;
            if(++consecutive>longest)longest=consecutive;
        } else {last_present=now;presented++;consecutive=0;}
        if(now<deadline)now=deadline;
        deadline=a2_frame_pacer_advance(deadline,now,60000).next_frame_ticks;
    }
    printf("%s: presented=%u/1200 starved=%u longest_hidden=%u\n",name,presented,starved,longest);
    check(name,"ready frames hidden beyond one period",starved,0);
    check(name,"completed frames presented",presented,1200);
}

int main(void) {
    test_visible_progress("sustained 17 ms work",1020,0);
    test_visible_progress("50 ms stall then exact 60 Hz work",1000,3000);
    test_deadline_boundaries();
    test_presentation_boundaries();
    test_presentation_age();
    test_accumulated_debt();
    test_stall_recovery();
    test_repeated_bursts();
    test_sustained_overload();
    if (failures) {
        fprintf(stderr, "frame pacer: %u failures\n", failures);
        return 1;
    }
    puts("frame pacer: boundaries, retained debt, stall/burst recovery and overload passed");
    return 0;
}
