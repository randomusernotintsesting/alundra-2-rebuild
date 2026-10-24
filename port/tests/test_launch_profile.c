#include "launch_profile.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

static void environment(const char *name, const char *value) {
#ifdef _WIN32
    assert(_putenv_s(name, value ? value : "") == 0);
    assert(SetEnvironmentVariableA(name, value));
#else
    assert((value ? setenv(name, value, 1) : unsetenv(name)) == 0);
#endif
}

int main(void) {
    static const char *const names[] = {
        "A2_LOCAL_POSE", "A2_COLOR_PRECISION", "A2_PRECISE_CULL", "A2_WORLD_CAMERA",
        "A2_WORLD_PERSPECTIVE", "A2_WORLD_PRECISION", "A2_WORLD_RASTER"
    };
    static const char *const unsupported[] = {
        "A2_COLOR_CONTINUITY", "A2_MODEL_DEPTH", "A2_MODEL_MINIFY", "A2_WORLD_DEPTH",
        "A2_FINE_PARALLEL", "A2_GPU_FINE", "A2_GPU_PRESENT"
    };
    for (size_t i = 0; i < sizeof names / sizeof names[0]; i++) environment(names[i], NULL);
    for (size_t i = 0; i < sizeof unsupported / sizeof unsupported[0]; i++) environment(unsupported[i], NULL);
    environment("A2_USER_DIR", "disposable-test-profile-not-a-personal-directory");
    FILE *log = tmpfile();
    assert(log);
    assert(a2_windows_launch_profile(log));
    for (size_t i = 0; i < sizeof names / sizeof names[0]; i++) {
        assert(getenv(names[i]));
        assert(!strcmp(getenv(names[i]), !strcmp(names[i], "A2_PRECISE_CULL") ? "2" : "1"));
#ifdef _WIN32
        char value[16];
        assert(GetEnvironmentVariableA(names[i], value, sizeof value));
        assert(!strcmp(value, getenv(names[i])));
#endif
    }
    for (size_t i = 0; i < sizeof unsupported / sizeof unsupported[0]; i++) assert(!getenv(unsupported[i]));
    environment("A2_LOCAL_POSE", "0");
    environment("A2_PRECISE_CULL", "1");
    environment("A2_GPU_FINE", "1");
    assert(a2_windows_launch_profile(log));
    assert(!strcmp(getenv("A2_LOCAL_POSE"), "0"));
    assert(!strcmp(getenv("A2_PRECISE_CULL"), "1"));
    assert(!strcmp(getenv("A2_GPU_FINE"), "1"));
    assert(!strcmp(getenv("A2_USER_DIR"), "disposable-test-profile-not-a-personal-directory"));
    rewind(log);
    char contents[8192];
    size_t bytes = fread(contents, 1, sizeof contents - 1, log);
    assert(!ferror(log)); contents[bytes] = 0;
    assert(strstr(contents, "A2_LOCAL_POSE=1 (default)"));
    assert(strstr(contents, "A2_LOCAL_POSE=0 (override)"));
    assert(strstr(contents, "A2_PRECISE_CULL=2 (default)"));
    assert(strstr(contents, "A2_GPU_FINE: unavailable in Windows CPU/SDL build (environment=1)"));
    assert(fclose(log) == 0);
    puts("launch profile: shared defaults, explicit overrides, unavailable paths and user-dir preservation passed");
    return 0;
}
