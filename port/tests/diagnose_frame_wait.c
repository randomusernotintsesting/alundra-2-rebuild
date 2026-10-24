/* Isolated timer comparison: no window, audio device, game data or saves.
 * Build on macOS with the production SDL2 flags, then schedule exclusively:
 *   diagnose_frame_wait [pairs=120]
 * CSV goes to stdout. The two wait APIs alternate order in every pair.
 * This measures the probe's inherited thread QoS/task role; it cannot infer
 * the state of a different GUI game process. No scheduling policy is changed.
 */
#include <SDL.h>
#include <mach/mach.h>
#include <mach/mach_time.h>
#include <mach/task_policy.h>
#include <pthread.h>
#include <pthread/qos.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static uint64_t stamp_ns(clockid_t id) {
    struct timespec value;
    if (clock_gettime(id, &value)) {
        perror("clock_gettime");
        exit(1);
    }
    return (uint64_t)value.tv_sec * 1000000000u + (uint64_t)value.tv_nsec;
}

static const char *qos_name(qos_class_t qos) {
    switch (qos) {
    case QOS_CLASS_USER_INTERACTIVE: return "user_interactive";
    case QOS_CLASS_USER_INITIATED: return "user_initiated";
    case QOS_CLASS_DEFAULT: return "default";
    case QOS_CLASS_UTILITY: return "utility";
    case QOS_CLASS_BACKGROUND: return "background";
    default: return "unspecified";
    }
}

int main(int argc, char **argv) {
    unsigned pairs = 120;
    if (argc > 2 || (argc == 2 && (sscanf(argv[1], "%u", &pairs) != 1 ||
                                  !pairs || pairs > 500))) {
        fprintf(stderr, "usage: %s [pairs from 1 to 500]\n", argv[0]);
        return 2;
    }
    if (SDL_Init(SDL_INIT_TIMER)) {
        fprintf(stderr, "SDL timer init failed: %s\n", SDL_GetError());
        return 1;
    }
    mach_timebase_info_data_t timebase;
    if (mach_timebase_info(&timebase) != KERN_SUCCESS || !timebase.numer ||
        !timebase.denom) {
        fprintf(stderr, "mach timebase unavailable\n");
        SDL_Quit();
        return 1;
    }
    SDL_version version;
    SDL_GetVersion(&version);
    task_category_policy_data_t category = {0};
    mach_msg_type_number_t count = TASK_CATEGORY_POLICY_COUNT;
    boolean_t get_default = FALSE;
    kern_return_t category_result = task_policy_get(mach_task_self(),
        TASK_CATEGORY_POLICY, (task_policy_t)&category, &count, &get_default);
    fprintf(stderr, "waitprobe: pid=%d mode=timer_only pairs=%u SDL=%u.%u.%u "
            "SDL_frequency=%llu mach_numer=%u mach_denom=%u "
            "task_role_result=%d task_role=%d\n", getpid(), pairs,
            version.major, version.minor, version.patch,
            (unsigned long long)SDL_GetPerformanceFrequency(),
            timebase.numer, timebase.denom, category_result, category.role);
    puts("pair,order,api,request_ms,wall_ms,cpu_ms,sdl_counter_ms,qos,qos_relative,interruptions");
    uint64_t started = stamp_ns(CLOCK_MONOTONIC);
    const unsigned requests[] = {1, 2, 5, 10, 15};
    for (unsigned pair = 0; pair < pairs; pair++) {
        for (unsigned order = 0; order < 2; order++) {
            if (stamp_ns(CLOCK_MONOTONIC) - started > 60000000000u) {
                fprintf(stderr, "waitprobe: stopped at explicit60second safety bound\n");
                SDL_Quit();
                return 2;
            }
            int native = (pair + order) & 1;
            unsigned ms = requests[pair % (sizeof requests / sizeof requests[0])];
            int relative = 0;
            qos_class_t qos = QOS_CLASS_UNSPECIFIED;
            int qos_result = pthread_get_qos_class_np(pthread_self(), &qos, &relative);
            if (qos_result) {
                fprintf(stderr, "pthread_get_qos_class_np failed: %d\n", qos_result);
                SDL_Quit();
                return 1;
            }
            unsigned interruptions = 0;
            uint64_t wall0 = stamp_ns(CLOCK_MONOTONIC);
            uint64_t cpu0 = stamp_ns(CLOCK_THREAD_CPUTIME_ID);
            uint64_t counter0 = SDL_GetPerformanceCounter();
            if (native) {
                uint64_t ns = (uint64_t)ms * 1000000u;
                uint64_t ticks = (ns * timebase.denom + timebase.numer - 1) /
                                 timebase.numer;
                uint64_t deadline = mach_absolute_time() + ticks;
                kern_return_t result;
                while ((result = mach_wait_until(deadline)) == KERN_ABORTED)
                    interruptions++;
                if (result != KERN_SUCCESS) {
                    fprintf(stderr, "mach_wait_until failed: %d\n", result);
                    SDL_Quit();
                    return 1;
                }
            } else {
                SDL_Delay(ms);
            }
            uint64_t counter1 = SDL_GetPerformanceCounter();
            uint64_t cpu1 = stamp_ns(CLOCK_THREAD_CPUTIME_ID);
            uint64_t wall1 = stamp_ns(CLOCK_MONOTONIC);
            printf("%u,%u,%s,%u,%.6f,%.6f,%.6f,%s,%d,%u\n", pair, order,
                   native ? "mach_absolute" : "SDL_relative", ms,
                   (wall1 - wall0)/1e6, (cpu1 - cpu0)/1e6,
                   1000.0 * (counter1 - counter0) / SDL_GetPerformanceFrequency(),
                   qos_name(qos), relative, interruptions);
        }
    }
    SDL_Quit();
    return 0;
}
