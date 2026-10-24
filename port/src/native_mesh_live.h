#ifndef A2_NATIVE_MESH_LIVE_H
#define A2_NATIVE_MESH_LIVE_H
#include "a2_resources.h"
#include "native_mesh_composite.h"
void a2_mesh_live_dma_begin(const uint8_t *,size_t,uint32_t,uint64_t,int);
void a2_mesh_live_dma_end(void);

/* Model choice is committed at a draw-page clear. Guest VRAM remains native;
 * selected source geometry is excluded from the presentation surface. */
int a2_mesh_live_open(A2Resources *,int language);
void a2_mesh_live_set_enabled(int enabled);
void a2_mesh_live_close(void);
void a2_mesh_live_reset(void);
extern int a2_mesh_live_enabled,a2_mesh_live_active;
/* An internal rendering contract failure stops presentation; it must never
 * silently select source geometry. Reset/load may clear the failure. */
extern int a2_mesh_live_failed;
/* Cached protection need across both pages, including clean pre-start proof
 * and published pixels after active composition has ended. */
extern int a2_mesh_live_writes_watched;
extern int a2_mesh_live_x0,a2_mesh_live_y0,a2_mesh_live_x1,a2_mesh_live_y1;
void a2_mesh_live_clear(uint32_t frame,int scale,int x,int y,int w,int h);
void a2_mesh_live_start(uint32_t frame,int scale,int page,const uint16_t *shadow,size_t stride,int wide);
void a2_mesh_live_start_view(uint32_t frame,int scale,int page,const uint16_t *shadow,size_t stride,int wide,int view_height);
int a2_mesh_live_owns(uint64_t owner);
/* Classify every occurrence of a selected source packet and insert its
 * native-order anchor, independently of one-time submission accounting. */
int a2_mesh_live_claim(uint64_t owner);
int a2_mesh_live_claim_part(uint64_t owner,unsigned source_part);
void a2_mesh_live_pixel(int x,int y,A2CompositePixel pixel);
/* Immediate destination for a source-proven covered HD sample. NULL means
 * clipped, occluded, suppressed, inactive or invalid. Never retain pointer. */
uint16_t *a2_mesh_live_destination(int x,int y,A2CompositeKind kind,float depth);
void a2_mesh_live_invalidate_rect(int x,int y,int w,int h);
/* Actual presentation transfers, with absolute wrapped fine coordinates.
 * These work after publication and without a current draw page. */
uint16_t a2_mesh_live_read(int x,int y,uint16_t original);
void a2_mesh_live_store(int x,int y,uint16_t value);
void a2_mesh_live_finalize(void);
/* Same finalization; source/frame labels are diagnostic only. */
void a2_mesh_live_finalize_at(uint32_t frame,const char *source);
void a2_mesh_live_trace_display(uint32_t frame,int source_y);
const uint16_t *a2_mesh_live_row(int y,const uint16_t *original,size_t width);
#endif
