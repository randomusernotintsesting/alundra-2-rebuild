#ifndef A2_NATIVE_BILLBOARD_H
#define A2_NATIVE_BILLBOARD_H
#include <stddef.h>
#include <stdint.h>
#include "world_precision.h"

/* Exact AL22 14318 reward and WORLD 100A8 ->14CD8 billboard provenance.
 * WORLD records use six direct/wrapped single/double-layer GT3/GT4 callers;
 * the 8000 feedback/raw-UV branch remains unsupported.
 * Guest packets retain their integer XY. Optional fine-raster corners use
 * the verified camera/source before integer center and screen rounding.
 * These are mixed components of two diagonal corners, not four independent
 * RTPT vertices. E1/E2 at DMA+4 always remains native.
 * Immutable tokens cover complete 44-byte FT4/GT3 or56-byte GT4 DMA packets. */
extern int a2_native_billboard_enabled;
extern uint32_t a2_native_billboard_watch_begin, a2_native_billboard_watch_end;
void a2_native_billboard_init(const uint8_t *ram, size_t bytes);
void a2_native_billboard_configure(int enabled);
void a2_native_billboard_reset(void);
void a2_native_billboard_invalidate(uint32_t address, size_t bytes);
void a2_native_billboard_before(uint32_t pc, const uint32_t registers[32], int code_valid);
void a2_native_billboard_after_store(uint32_t pc, uint32_t address,
                                    uint32_t word, const uint32_t registers[32]);
uint64_t a2_native_billboard_token(uint32_t command_address, uint32_t command);
int a2_native_billboard_consume(uint32_t command_address, uint64_t token,
                              const uint32_t *words, unsigned count, double *depth);
/* Immutable whole-packet proof, rechecked both when queued and consumed.
 * Depth consumption does not retire XY; packet writes/reset still do. */
int a2_native_billboard_vertex(uint32_t address,uint32_t word,world_precision_vertex *out);
#endif
