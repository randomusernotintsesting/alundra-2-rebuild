#ifndef A2_NATIVE_RESOURCES_GUEST_H
#define A2_NATIVE_RESOURCES_GUEST_H
#include "a2_resources.h"
/* Store ownership remains with the application. Install after loading SCPS. */
int a2_native_resources_install(A2Resources *store, int language,
                                char *error, size_t error_size);
void a2_native_resources_tick(void);
void a2_native_resources_close(void);
#endif
