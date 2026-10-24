#ifndef A2_NATIVE_ACTOR_SNAPSHOT_H
#define A2_NATIVE_ACTOR_SNAPSHOT_H
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

/* AnimationBridge v1. Copied native values, no guest-memory pointers for a
 * consumer to dereference. All addresses below are diagnostic identities.
 * Matrices are row-major signed Q12; translations/pretranslation retain the
 * native integer units. actor_world_q12 is separate from renderer_root_q12
 * (the latter includes offsets and the guest Y convention). */
#define A2_ACTOR_MAX_INSTANCES 128
#define A2_ACTOR_MAX_PARTS 256
#define A2_ACTOR_SOURCE_KEY_SIZE 64
enum { A2_ACTOR_GAME00=0u, A2_ACTOR_EVENT00=1u };
enum {
    A2_ACTOR_UNBOUND_SOURCE=1u, A2_ACTOR_DEFORMED_SOURCE=2u,
    A2_ACTOR_MISSING_ROOT=4u, A2_ACTOR_UNKNOWN_LIFETIME=8u,
    A2_ACTOR_BAD_RECORD=16u, A2_ACTOR_FRAME_OVERFLOW=32u,
    A2_ACTOR_UNKNOWN_ANIMATION=64u, A2_ACTOR_UNKNOWN_SOURCE_CODE=128u,
    A2_ACTOR_DIFFERENT_PART_SOURCE=256u
};
typedef struct {
    uint32_t address, registry_address, vertex_override_address;
    uint16_t source_mesh_index, flags;
    int16_t matrix_q12[9], pretranslation[3];
    int32_t translation0[3], translation1[3];
    uint32_t fallback;
    unsigned valid, visible;
    uint64_t source_generation;
    char source_key[A2_ACTOR_SOURCE_KEY_SIZE];
    uint8_t source_sha256[32], raw[80];
} A2ActorPart;
typedef struct {
    uint32_t entity_address, marker_address, registry_address;
    unsigned source_family;
    uint64_t instance_generation;
    unsigned generation_known, valid, selected_for_draw;
    uint32_t fallback;
    int32_t actor_world_q12[3], actor_offset_q12[3], renderer_root_q12[3];
    int16_t orientation[3];
    uint16_t entity_flags, action_id, previous_action_id;
    uint32_t animation_state_address, animation_registry_address, clip_address;
    uint32_t animation_selector;
    /* Actual calls, not time in seconds: pose reconstruction may invoke
     * several advances during one ordinary entity update. */
    uint64_t clip_generation, animation_update_tick, entity_update_calls;
    unsigned animation_clock_known;
    uint16_t animation_flags, clip_frame, clip_length, clip_loops;
    unsigned first_part, part_count;
} A2ActorInstance;
typedef struct {
    uint64_t sequence, build_generation, capture_monotonic_ns;
    unsigned clock_known;
    uint32_t guest_frame, draw_object_address, draw_flags;
    unsigned valid, shadow_pass, instance_count, part_count;
    unsigned source_family;
    uint32_t fallback;
    int32_t camera_origin_q12[3], projection_h, projection_ofx, projection_ofy;
    int16_t camera_rotation_q12[9];
    A2ActorInstance instances[A2_ACTOR_MAX_INSTANCES];
    A2ActorPart parts[A2_ACTOR_MAX_PARTS];
} A2ActorFrame;
typedef struct {
    uint64_t begin_hooks, instance_hooks, root_hooks, capture_hooks;
    uint64_t animation_select_hooks, animation_update_hooks, published, rejected;
} A2ActorSnapshotStats;

extern int a2_native_actor_snapshot_enabled;
void a2_native_actor_snapshot_init(const uint8_t *ram, size_t size);
void a2_native_actor_snapshot_configure(int enabled);
void a2_native_actor_snapshot_reset(void);
/* Only the host asset loader may bind a proven pre-relocation source. A bind
 * never discovers a model name from guest addresses or mesh similarity. */
int a2_native_actor_snapshot_source_bind(uint32_t registry, const char *key,
                                       const uint8_t sha256[32], uint64_t generation);
void a2_native_actor_snapshot_source_unbind(uint32_t registry);
/* Borrowed stream: owner closes it after set_output(NULL). JSONL is emitted
 * synchronously at completed draw submissions; an error disables output.
 * No implicit files, environment variables, game-clock or timing changes. */
void a2_native_actor_snapshot_set_output(FILE *stream);
void a2_native_actor_snapshot_set_clock(uint64_t (*monotonic_ns)(void));
int a2_native_actor_snapshot_output_error(void);
/* The current immutable copy expires at the next capture/reset. It can be a
 * rejected frame; callers must check valid and each part's fallback. */
const A2ActorFrame *a2_native_actor_snapshot_current(void);
void a2_native_actor_snapshot_stats(A2ActorSnapshotStats *out);

/* Exact generated-PC observations, safe with precision OFF. */
void a2_native_actor_snapshot_begin(uint32_t frame, uint32_t arena, uint32_t ra);
void a2_native_actor_snapshot_instance(uint32_t entity, uint32_t marker);
void a2_native_actor_snapshot_root(uint32_t entity, const int32_t root_q12[3]);
void a2_native_actor_snapshot_animation_select(uint32_t state, uint32_t selector,
                                             uint32_t registry);
void a2_native_actor_snapshot_animation_update(uint32_t state);
void a2_native_actor_snapshot_entity_update(uint32_t entity);
void a2_native_actor_snapshot_entity_reset(uint32_t entity);
void a2_native_actor_snapshot_capture(uint32_t frame, uint32_t object,
                                     int32_t h, int32_t ofx, int32_t ofy);
/* EVENT00 has a separate entity lifetime and a sparse arena. These hooks
 * observe native construction; missing channels retain identity, never pose. */
void a2_native_actor_snapshot_event_begin(uint32_t frame, uint32_t arena);
void a2_native_actor_snapshot_event_reset(uint32_t entity);
void a2_native_actor_snapshot_event_instance(uint32_t entity, uint32_t first_record);
void a2_native_actor_snapshot_event_part(uint32_t entity, unsigned channel,
                                       uint32_t record);
#endif
