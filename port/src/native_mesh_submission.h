#ifndef A2_NATIVE_MESH_SUBMISSION_H
#define A2_NATIVE_MESH_SUBMISSION_H
#include "native_actor_packets.h"
/* An exact read-only view of the currently executing DMA command stream.
 * A retained source owner alone does not prove the game is drawing it again. */
typedef struct {
    uint8_t words[65536],visited[65536];
    const uint8_t *ram;
    unsigned known,valid;
} A2MeshSubmission;
void a2_mesh_submission_begin(A2MeshSubmission *,const uint8_t *,size_t,uint32_t,uint64_t,int);
void a2_mesh_submission_end(A2MeshSubmission *);
int a2_mesh_submission_contains(const A2MeshSubmission *,const A2ActorPacket *);
#endif
