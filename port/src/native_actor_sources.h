#ifndef A2_NATIVE_ACTOR_SOURCES_H
#define A2_NATIVE_ACTOR_SOURCES_H
#include <stddef.h>
#include <stdint.h>
/* Generated original mesh identities from typed PAK/VCAST/GRP resource spans,
 * before resident2492C relocation. Full original resource hashes and bounded
 * native layouts establish identity; model names alone never do. Equivalent
 * GRP bodies may use the identical complete original PAK resource identity.
 * Unknown/modified geometry
 * remain unbound. Every subsequent overlapping write retires the binding. */
extern int a2_native_actor_sources_enabled;
extern uint32_t a2_native_actor_sources_watch_begin,a2_native_actor_sources_watch_end;
void a2_native_actor_sources_init(const uint8_t *ram,size_t bytes);
void a2_native_actor_sources_configure(int enabled);
void a2_native_actor_sources_reset(void);
void a2_native_actor_sources_invalidate(uint32_t address,size_t bytes);
/* Exact generated entry2492C and epilogue24D00, before R20 is restored. */
void a2_native_actor_sources_before_relocation(uint32_t registry);
void a2_native_actor_sources_after_relocation(uint32_t registry,uint32_t result);
#endif
