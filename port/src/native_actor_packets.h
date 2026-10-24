#ifndef A2_NATIVE_ACTOR_PACKETS_H
#define A2_NATIVE_ACTOR_PACKETS_H
#include "native_actor_snapshot.h"
#include "native_scene_light.h"

#define A2_ACTOR_PACKET_LIMIT 4096u
#define A2_ACTOR_PACKET_PART_LIMIT 32u
#define A2_ACTOR_PACKET_OWNER_LIMIT 64u
/* All arrays are copied host data. Address fields are identities only.
 * A handle/token is never reused, including across reset. An owner is valid
 * only after its entire submission seals; any invalidated packet retires the
 * whole owner. Source identity does not imply pose eligibility: hidden parts
 * retain valid=0 and their copied stale pose must never be rendered. Sealed
 * submissions survive later source/entity/arena writes, but not packet/code
 * writes or a new build/reset. Neither observer nor consume suppresses drawing.
 * Inserting a replacement at an OT slot does NOT establish world occlusion. */
typedef struct {
    uint64_t handle, submission_sequence;
    uint32_t guest_frame;
    A2ActorInstance instance;
    A2ActorPart parts[A2_ACTOR_PACKET_PART_LIMIT];
    int32_t camera_origin_q12[3], projection_h, projection_ofx, projection_ofy;
    int16_t camera_rotation_q12[9];
    A2NativeSceneLight light;
    unsigned packet_count;
} A2ActorPacketOwner;
typedef struct {
    uint64_t owner_handle, submission_sequence, entity_generation;
    uint32_t dma_base, command_address, ot_bucket, previous_head, prefix_word;
    unsigned source_mesh_index, native_face_index, material_layer;
    unsigned polygon_word_count, dma_word_count;
    /* DMA header + E1/E2 prefix + original polygon (maximum GT4). */
    uint32_t words[14];
    /* Optional source-stable, native-lit G3 colors for presentation only.
     * words remain the original payload; the full packet lifetime applies. */
    unsigned fine_rgb_valid;
    uint32_t fine_rgb[3];
} A2ActorPacket;
extern int a2_native_actor_packets_enabled;
extern uint32_t a2_native_actor_packets_watch_begin, a2_native_actor_packets_watch_end;
/* Selected immutable AL22 extent; conservative maximum while unverified. */
extern uint32_t a2_native_actor_packets_code_end;
void a2_native_actor_packets_init(const uint8_t *ram, size_t bytes);
void a2_native_actor_packets_configure(int enabled);
void a2_native_actor_packets_reset(void);
void a2_native_actor_packets_invalidate(uint32_t address, size_t bytes);
/* A token identifies this immutable source packet throughout its lifetime.
 * Repeated identical dispatches keep the same token/owner and undergo the
 * same full payload/lifetime checks. Queries do not mark it observed;
 * successful consume marks observation once without erasing its identity. */
uint64_t a2_native_actor_packets_token(uint32_t command_address, uint32_t command);
int a2_native_actor_packets_consume(uint32_t command_address, uint64_t token,
                                   const uint32_t *words, unsigned count,
                                   const A2ActorPacket **out);
const A2ActorPacketOwner *a2_native_actor_packets_owner(uint64_t handle);
/* Narrow read-only gate for the CURRENT unsealed GAME00/EVENT00 part. This is not
 * an owner-consumption API and cannot expose arbitrary partial submissions. */
const A2ActorPacketOwner *a2_native_actor_packets_projecting(uint32_t context,
                                                            uint32_t part,uint32_t shared_bank);
/* No partial result: inadequate capacity returns0 without writing out.
 * Query pointers expire at the next build/reset. complete requires successful
 * consume at least once of every captured original polygon and continued
 * owner validity; repeated dispatch cannot complete an unobserved sibling. */
size_t a2_native_actor_packets_owners(uint32_t guest_frame,const A2ActorPacketOwner **out,size_t capacity);
/* Latest retained build frame, which may precede the GPU's current VBlank.
 * All returned owners still require exact packet/lifetime completion gates. */
size_t a2_native_actor_packets_owners_latest(const A2ActorPacketOwner **out,size_t capacity);
size_t a2_native_actor_packets_owner_packets(uint64_t handle,const A2ActorPacket **out,size_t capacity);
int a2_native_actor_packets_owner_complete(uint64_t handle);
/* A source-qualified main emission lost its immutable packet ownership.
 * Cleared only by reset/new arena build; skipped actors/shadows do not fail.
 * Fully observed copied submissions survive later guest invalidation until
 * another polygon attempts their retired address/token. Partial submissions
 * cannot lose a packet silently. This query does not admit/suppress drawing. */
int a2_native_actor_packets_source_failed(const char *key,const uint8_t sha256[32]);
/* Exact retained AL22 observation sites. before sees native registers before
 * the instruction; after_store sees the completed final payload write.
 * Always forward both prefix GP0 words E1/E2: token starts at dma_base+8. */
void a2_native_actor_packets_before(uint32_t pc, const uint32_t registers[32]);
/* Copied native controls at the exact emitter entry. No GTE operation or
 * register write is performed by this observer. */
void a2_native_actor_packets_before_gte(uint32_t pc, const uint32_t registers[32],
                                      const uint32_t control[32]);
/* Only a certified active G3 requests copied inputs before its exact NCDS.
 * Neither function executes or mutates guest state. */
int a2_native_actor_packets_color_site(uint32_t pc,uint32_t instruction);
void a2_native_actor_packets_color_gte(uint32_t pc,const uint32_t data[32],
                                      const uint32_t control[32]);
void a2_native_actor_packets_after_store(uint32_t pc, uint32_t instruction,
                                       uint32_t address, const uint32_t registers[32]);
#endif
