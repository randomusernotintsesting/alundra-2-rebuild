#ifndef A2_GAME_PROFILES_H
#define A2_GAME_PROFILES_H
#include <stddef.h>
/* Text: Russian=0, Japanese=1, English=2. All profiles use the JP native engine. */
void a2_profiles_init(const char *disc, const char *image);
int a2_profile_available(int language);
const char *a2_profile_reason(int language);
int a2_profile_select(int language); /* update a2_paths only on complete success */
const char *a2_profile_root(void);
int a2_profile_voice_path(int language, char *out, size_t size); /* voice: 0 ja, 1 en */
#ifdef A2_NATIVE_RESOURCES
#include "a2_resources.h"
int a2_profiles_open_native(const char *path,char *error,size_t size);
A2Resources *a2_profile_resources(void);
void a2_profiles_close_native(void);
#endif
#endif
