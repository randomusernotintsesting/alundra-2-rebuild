#ifndef A2_HUD_PRESENT_H
#define A2_HUD_PRESENT_H
#include <stddef.h>
#include <stdint.h>

/* Guest packet provenance only; no RAM or VRAM is changed by this module. */
void a2_hud_present_init(const uint8_t *ram, size_t bytes);
void a2_hud_present_close(void);
void a2_hud_present_reset(void);
void a2_hud_present_begin(uint32_t start, uint32_t ot, unsigned mode, uint32_t ra);
void a2_hud_present_group(uint32_t start, int anchor);
void a2_hud_present_descriptor(uint32_t start, uint32_t ra);
void a2_hud_present_end(uint32_t end);
uint64_t a2_hud_present_packet_token(uint32_t address, uint32_t command);
int a2_hud_present_consume(uint32_t address, uint64_t token,
                           const uint32_t *words, unsigned count, int *anchor);

/* Canonical physical RAM envelope, empty when begin >= end. Inline stores
 * call invalidate only for possible overlap; identical writes revoke tags. */
extern uint32_t a2_hud_present_watch_begin, a2_hud_present_watch_end;
void a2_hud_present_invalidate(uint32_t address, size_t bytes);
typedef struct {
    uint64_t begins, accepted_builds, produced_packets, consumed_packets;
    uint64_t rejected_builds, invalidated_packets;
} A2HudPresentStats;
void a2_hud_present_stats(A2HudPresentStats *out);
#endif
