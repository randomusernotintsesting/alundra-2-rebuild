#ifndef A2_RESOURCES_H
#define A2_RESOURCES_H
#include <stddef.h>
#include <stdint.h>

typedef struct A2Resources A2Resources;
typedef uint32_t A2ResourceId; /* Zero is invalid; IDs belong to their store. */

int a2_resources_open(const char *path, A2Resources **out, char *error, size_t size);
void a2_resources_close(A2Resources *store);
unsigned a2_resources_profiles(const A2Resources *store);
/* Select before boot. Names follow actual audio; existing resource IDs remain
 * valid. Legacy archives are accepted, incomplete name variants are rejected. */
int a2_resources_set_name_voice(A2Resources *store, int voice_language);
A2ResourceId a2_resource_find(const A2Resources *store, int language, const char *name);
uint64_t a2_resource_size(const A2Resources *store, A2ResourceId id);
/* Exact range, including an empty read at EOF. On error destination may contain
 * a prefix: adapters must read into host scratch before committing guest RAM.
 * Store/cache operations are confined to the owning emulation thread. */
int a2_resource_pread(A2Resources *store, A2ResourceId id, uint64_t offset,
                      void *destination, size_t length, char *error, size_t size);
#endif
