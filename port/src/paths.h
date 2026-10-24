#ifndef A2_PATHS_H
#define A2_PATHS_H

typedef struct {
    char disc[4096], image[4096], user[4096], settings[4096];
    char legacy_settings[4096], error[512];
    char resources[4096];
} A2Paths;
extern A2Paths a2_paths;
/* Explicit arguments, environment, bundle resources, then development assets. */
int a2_paths_init(const char *disc_override, const char *image_override);

#endif
