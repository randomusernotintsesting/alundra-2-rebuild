#ifndef A2_WORLD_SHADOW_H
#define A2_WORLD_SHADOW_H
#include <stdint.h>
#include "world_precision.h"
/* Modern-model depth transport is opt-in. Every configuration change clears
 * any pending shadow batch without touching ordinary world/actor precision. */
void a2_world_shadow_configure(int enabled);
void a2_world_shadow_begin(const uint32_t regs[32]);
void a2_world_shadow_before(uint32_t pc,const uint32_t regs[32],int code_valid);
void a2_world_shadow_project(uint32_t pc,const uint32_t regs[32]);
void a2_world_shadow_store(uint32_t pc,uint32_t address,uint32_t word,const uint32_t regs[32]);
void a2_world_shadow_emit(const uint32_t regs[32]);
/* Physical source plane for occlusion only. Native shadow XY/UV transport
 * stays unchanged. A bounded copied batch certificate may expire safely. */
typedef struct {
 double x[4],y[4],z[4];
 int32_t origin_q12[3],h,ofx,ofy;
 int16_t rotation_q12[9];
} A2WorldShadowGeometry;
int a2_world_shadow_geometry(const world_precision_vertex *vertices,unsigned count,
                            int wide,uint32_t address,const uint32_t *words,unsigned word_count,
                            A2WorldShadowGeometry *out);
#endif
