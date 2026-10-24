#include "frame_wait.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifdef __APPLE__
#include <errno.h>
#include <libproc.h>
#include <mach/mach.h>
#include <mach/mach_time.h>
#include <mach/task_policy.h>
#include <pthread.h>
#include <pthread/qos.h>
#include <sys/proc_info.h>
#include <unistd.h>

static int probe_enabled;
static uint64_t coarse_calls;
static mach_timebase_info_data_t probe_timebase;

static uint64_t clock_ns(clockid_t id) {
    struct timespec stamp;
    if (clock_gettime(id, &stamp)) {
        perror("gamewait clock_gettime");
        exit(2);
    }
    return (uint64_t)stamp.tv_sec * 1000000000u + (uint64_t)stamp.tv_nsec;
}

static const char *requested_qos_name(qos_class_t qos) {
    switch (qos) {
    case QOS_CLASS_USER_INTERACTIVE: return "user_interactive";
    case QOS_CLASS_USER_INITIATED: return "user_initiated";
    case QOS_CLASS_DEFAULT: return "default";
    case QOS_CLASS_UTILITY: return "utility";
    case QOS_CLASS_BACKGROUND: return "background";
    default: return "unspecified";
    }
}
#endif

void a2_frame_wait_init(void) {
    const char *setting = getenv("A2_WAIT_PROBE");
    const char *audio_stats = getenv("A2_AUDIOSTAT");
    int log_backends = audio_stats && *audio_stats && strcmp(audio_stats, "0");
#ifdef __APPLE__
    probe_enabled = setting && !strcmp(setting, "1");
    log_backends |= probe_enabled;
    coarse_calls = 0;
    if (probe_enabled && (mach_timebase_info(&probe_timebase) != KERN_SUCCESS ||
                          !probe_timebase.numer || !probe_timebase.denom)) {
        fprintf(stderr, "gamewait: Mach timebase unavailable\n");
        exit(2);
    }
#else
    if (setting && !strcmp(setting, "1"))
        fprintf(stderr, "gamewait: A2_WAIT_PROBE is only supported on macOS\n");
#endif
    if (log_backends) {
        const char *video = SDL_GetCurrentVideoDriver();
        const char *audio = SDL_GetCurrentAudioDriver();
        fprintf(stderr, "gamewait_backend: video_driver=%s audio_driver=%s\n",
                video ? video : "uninitialized", audio ? audio : "uninitialized");
    }
}

void a2_frame_wait(uint32_t milliseconds, uint32_t frame) {
    (void)frame;
    if (!milliseconds) return;
#ifdef __APPLE__
    if (probe_enabled) {
        uint64_t call = coarse_calls++;
        int native = call & 1;
        int relative = 0;
        qos_class_t qos = QOS_CLASS_UNSPECIFIED;
        int qos_result = pthread_get_qos_class_np(pthread_self(), &qos, &relative);
        task_category_policy_data_t category = {0};
        mach_msg_type_number_t count = TASK_CATEGORY_POLICY_COUNT;
        boolean_t get_default = FALSE;
        kern_return_t role_result = task_policy_get(mach_task_self(),
            TASK_CATEGORY_POLICY, (task_policy_t)&category, &count, &get_default);
        /* The 64-bit flavor takes the unique thread ID returned by
         * pthread_threadid_np, not a pthread_t or a Mach port name.
         * Observe only this process/thread; a short/failed result is unknown,
         * never an all-clear flag or a zero priority. */
        struct proc_bsdshortinfo process_info = {0};
        errno = 0;
        int process_bytes = proc_pidinfo(getpid(), PROC_PIDT_SHORTBSDINFO, 0,
            &process_info, sizeof process_info);
        int process_error = errno;
        int process_valid = process_bytes == (int)sizeof process_info;
        uint64_t thread_id = 0;
        int thread_id_result = pthread_threadid_np(NULL, &thread_id);
        struct proc_threadinfo thread_info = {0};
        int thread_bytes = -1, thread_error = 0;
        if (!thread_id_result) {
            errno = 0;
            thread_bytes = proc_pidinfo(getpid(), PROC_PIDTHREADID64INFO, thread_id,
                &thread_info, sizeof thread_info);
            thread_error = errno;
        }
        int thread_valid = !thread_id_result && thread_bytes == (int)sizeof thread_info;
        unsigned interruptions = 0;
        uint64_t wall0 = clock_ns(CLOCK_MONOTONIC);
        uint64_t cpu0 = clock_ns(CLOCK_THREAD_CPUTIME_ID);
        uint64_t counter0 = SDL_GetPerformanceCounter();
        if (native) {
            uint64_t ns = (uint64_t)milliseconds * 1000000u;
            __uint128_t ticks = ((__uint128_t)ns * probe_timebase.denom +
                                 probe_timebase.numer - 1) / probe_timebase.numer;
            uint64_t now = mach_absolute_time();
            if (ticks > UINT64_MAX - now) {
                fprintf(stderr, "gamewait: absolute deadline overflow\n");
                exit(2);
            }
            uint64_t deadline = now + (uint64_t)ticks;
            kern_return_t result;
            while ((result = mach_wait_until(deadline)) == KERN_ABORTED)
                interruptions++;
            if (result != KERN_SUCCESS) {
                fprintf(stderr, "gamewait: mach_wait_until failed: %d\n", result);
                exit(2);
            }
        } else {
            SDL_Delay(milliseconds);
        }
        uint64_t counter1 = SDL_GetPerformanceCounter();
        uint64_t cpu1 = clock_ns(CLOCK_THREAD_CPUTIME_ID);
        uint64_t wall1 = clock_ns(CLOCK_MONOTONIC);
        fprintf(stderr, "gamewait: frame=%u coarse_call=%llu api=%s request_ms=%u "
                "wall_ms=%.6f cpu_ms=%.6f sdl_counter_ms=%.6f frequency=%llu "
                "requested_qos=%s qos_relative=%d qos_result=%d task_role=%d "
                "role_result=%d interruptions=%u "
                "proc_info_bytes=%d proc_info_errno=%d proc_flags=%lld "
                "suppressed=%d darwinbg=%d ext_darwinbg=%d "
                "thread_id_result=%d thread_info_bytes=%d thread_info_errno=%d "
                "thread_curpri=%d thread_priority=%d thread_policy=%d\n",
                frame, (unsigned long long)call,
                native ? "mach_absolute" : "SDL_relative", milliseconds,
                (wall1 - wall0)/1e6, (cpu1 - cpu0)/1e6,
                1000.0 * (counter1 - counter0) / SDL_GetPerformanceFrequency(),
                (unsigned long long)SDL_GetPerformanceFrequency(),
                qos_result ? "unknown" : requested_qos_name(qos), relative, qos_result,
                role_result == KERN_SUCCESS ? category.role : -1, role_result, interruptions,
                process_bytes, process_error,
                process_valid ? (long long)process_info.pbsi_flags : -1ll,
                process_valid ? !!(process_info.pbsi_flags & PROC_FLAG_SUPPRESSED) : -1,
                process_valid ? !!(process_info.pbsi_flags & PROC_FLAG_DARWINBG) : -1,
                process_valid ? !!(process_info.pbsi_flags & PROC_FLAG_EXT_DARWINBG) : -1,
                thread_id_result, thread_bytes, thread_error,
                thread_valid ? thread_info.pth_curpri : -1,
                thread_valid ? thread_info.pth_priority : -1,
                thread_valid ? thread_info.pth_policy : -1);
        return;
    }
#endif
    SDL_Delay(milliseconds);
}
