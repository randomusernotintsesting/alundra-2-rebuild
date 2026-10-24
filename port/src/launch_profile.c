#include "launch_profile.h"
#include <stdlib.h>
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

static int set_default(const char *name, const char *value) {
    if (getenv(name)) return 1;
#ifdef _WIN32
    return _putenv_s(name, value) == 0 && SetEnvironmentVariableA(name, value);
#else
    return setenv(name, value, 0) == 0;
#endif
}

int a2_windows_launch_profile(FILE *log) {
    static const struct { const char *name, *value; } shared[] = {
        {"A2_LOCAL_POSE", "1"}, {"A2_COLOR_PRECISION", "1"},
        {"A2_PRECISE_CULL", "2"}, {"A2_WORLD_CAMERA", "1"},
        {"A2_WORLD_PERSPECTIVE", "1"}, {"A2_WORLD_PRECISION", "1"},
        {"A2_WORLD_RASTER", "1"}
    };
    static const char *const unavailable[] = {
        "A2_COLOR_CONTINUITY", "A2_MODEL_DEPTH", "A2_MODEL_MINIFY", "A2_WORLD_DEPTH",
        "A2_FINE_PARALLEL", "A2_GPU_FINE", "A2_GPU_PRESENT"
    };
    if (log) fprintf(log, "windows-launch-profile: CPU/SDL shared defaults; explicit overrides retained\n");
    for (size_t i = 0; i < sizeof shared / sizeof shared[0]; i++) {
        int overridden = getenv(shared[i].name) != NULL;
        if (!set_default(shared[i].name, shared[i].value)) {
            if (log) fprintf(log, "Cannot apply Windows launch default %s\n", shared[i].name);
            return 0;
        }
        if (log) fprintf(log, "  %s=%s (%s)\n", shared[i].name, getenv(shared[i].name),
                         overridden ? "override" : "default");
    }
    for (size_t i = 0; log && i < sizeof unavailable / sizeof unavailable[0]; i++) {
        const char *requested = getenv(unavailable[i]);
        fprintf(log, "  %s: unavailable in Windows CPU/SDL build (environment=%s)\n",
                unavailable[i], requested ? requested : "unset");
    }
    return 1;
}
