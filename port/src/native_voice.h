#ifndef A2_NATIVE_VOICE_H
#define A2_NATIVE_VOICE_H
#include <stddef.h>
#include <stdint.h>
#include "a2_resources.h"
/* A positive logical clock anchor, independent of every source/disc/archive
 * address. The resident manager uses this number only for its time queries. */
#define A2_NATIVE_VOICE_CLOCK_BASE 1024u
int a2_native_voice_available(A2Resources *store, int language);
int a2_native_voice_open(A2Resources *store, int language, uint8_t *ram,
                         size_t ram_size, char *error, size_t error_size);
void a2_native_voice_install(void);
void a2_native_voice_close(void);
int a2_native_voice_enabled(void);
typedef struct {
    const char *name; /* immutable until the native voice store closes */
    uint32_t milliseconds,origin;
} A2VoicePosition;
/* Read-only 37800-Hz source clock, after channel phase. Returns zero before
 * audio starts, after its end, on stop/seek/close, or for absent source audio.
 * Mute and disabled sound retain the same clock; a paused game cannot advance it. */
int a2_native_voice_position(A2VoicePosition *out);
const char *a2_native_voice_error(void);
void a2_native_voice_transport_error(const char *operation);
/* Compatibility command facade. These arguments describe time and requested
 * channel phase; they never address stored data. Only a named guest hook can
 * choose a clip. No raw CD sector is constructed or read. */
int a2_native_voice_begin(uint32_t clock, uint8_t file, uint8_t channel);
int a2_native_voice_advance(unsigned clock_units, int decode_enabled);
void a2_native_voice_stop(const char *reason);
void a2_native_voice_event(const char *reason);
#endif
