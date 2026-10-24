#ifndef WORLD_PRECISION_H
#define WORLD_PRECISION_H
#include <stddef.h>
#include <stdint.h>
void world_precision_set_output_aspect(int width,int height);
void world_precision_set_projection(int width,int height,int rows);
int64_t world_precision_wide_x(int64_t x);
double world_precision_wide_scale(void);
double world_precision_hud_scale(void);

/* GAME00 AL22 ends with the return delay slot at157AC; its mutable
 * context begins at157B0. EVENT00 uses the corresponding boundary15EA0. */
#define WORLD_PRECISION_CODE_BEGIN 0x10000u
#define WORLD_PRECISION_CODE_END   0x157b0u
#define WORLD_PRECISION_CODE_HASH  UINT64_C(0x5e1437c3f76cfa12)
#define WORLD_PRECISION_EVENT_CODE_END  0x15ea0u
#define WORLD_PRECISION_EVENT_CODE_HASH UINT64_C(0x6b8b62a2245699dd)

/* Host-only provenance. Guest words and native rasterization stay unchanged. */
enum { WORLD_PROJECTION_NATIVE_Q16, WORLD_PROJECTION_CAMERA };
typedef struct {
    double x, y, z;
    uint64_t projection_id, generation;
    uint32_t native_word, producer_pc, source_address;
    unsigned projection_kind;
    uint64_t camera_generation;
} world_precision_vertex;

extern int world_precision_enabled;
extern int world_camera_enabled;
/* Actual fine-raster scale, maintained by GPU allocation/settings. Zero
 * means that precision-aware visibility must retain native decisions. */
extern int world_precision_raster_scale;
extern uint32_t world_precision_producer_pc;
extern uint64_t world_precision_code_version;
/* Conservative maximum until the interpreter verifies a complete profile. */
extern uint32_t world_precision_code_end;
/* Any guest-memory write/reset retires a partially constructed shared record.
 * The retained duplicate has only two expected SH completions after its SW. */
extern uint64_t world_precision_write_version;
void world_precision_configure(int enabled);
void world_camera_configure(int enabled);
/* The retained WORLD/ACTOR interpreter paths arm one verified RTPS only.
 * Camera remainders are Q12 in [0,4095], including negative raw positions. */
void world_precision_camera_arm(uint32_t producer_pc, const uint32_t remainder[3],
                                uint64_t source_generation);
/* Verified actor source contributes a local MVMVA Q12 remainder. */
void world_precision_camera_arm_pose(uint32_t producer_pc, const uint32_t camera_remainder[3],
                                     const uint32_t pose_remainder[3], uint64_t source_generation);
void world_precision_camera_disarm(void);
int world_precision_camera_pending(void);
void world_precision_camera_project(const int64_t mac[3], const int16_t rotation[9],
                                    int32_t h, int32_t ofx, int32_t ofy, int wide);
void world_precision_reset(void);
void world_precision_invalidate(uint32_t address, size_t bytes);
uint64_t world_precision_begin_object(void);
void world_precision_gte_push(uint32_t word, int64_t x_fp, int64_t y_fp,
                              double depth, int valid);
void world_precision_gte_write(int reg);
int world_precision_gte_read(int reg, uint32_t word, world_precision_vertex *out);
void world_precision_record(uint32_t address, uint32_t word,
                            uint64_t object, const world_precision_vertex *value);
int world_precision_emit(const uint32_t *destinations, const uint32_t *words,
                         const uint32_t *sources, unsigned count, uint64_t object);
/* Only the retained actor observer can supply a nonzero lifetime/camera scope.
 * Mark a completed16-byte RAM duplicate; ordinary local records stay strict. */
int world_precision_share_record(uint32_t address,uint32_t word,uint64_t object,
                                 uint64_t projection_id,uint64_t scope);
int world_precision_emit_actor(const uint32_t *destinations,const uint32_t *words,
                               const uint32_t *sources,unsigned count,uint64_t object,
                               uint64_t scope);
int world_precision_frontface_actor(const uint32_t sources[4],const uint32_t words[4],
                                    uint64_t object,unsigned triangle,uint64_t scope,int *front);
int world_precision_packet(uint32_t address, uint32_t word,
                           world_precision_vertex *out);
/* Exact source-record orientation for the two retained actor NCLIP tests.
 * All four corners must belong to this object and camera projection. */
int world_precision_frontface(const uint32_t sources[4],const uint32_t words[4],
                              uint64_t object,unsigned triangle,int *front);
/* Shared GPU/culling eligibility, in emitted packet order. */
int world_precision_raster_extent(const uint32_t *words,unsigned count);

/* Diagnostic output is bounded to A2_WORLD_TRACE_FROM / A2_WORLD_TRACE_TO.
 * Records go to stderr; the host supplies its existing frame number. */
/* Non-consuming predicate for callers' diagnostic-only preparation. */
int world_precision_trace_active(uint32_t frame);
void world_precision_trace(uint32_t frame, const char *stage, uint32_t pc,
                           uint32_t address, const world_precision_vertex *value);
void world_precision_trace_miss(uint32_t frame, const char *stage, uint32_t pc,
                                uint32_t address, uint32_t native_word);
void world_precision_trace_primitive(uint32_t frame, uint64_t consumer, int complete,
                                     int draw_x, int draw_y, int disp_x, int disp_y);
void world_precision_trace_display(uint32_t frame, int x, int y, int w, int h);
void world_precision_trace_object(uint32_t frame, uint64_t object, uint64_t code_version,
                                  uint64_t code_hash, int code_valid,
                                  uint32_t context, uint32_t scratch);
#endif
