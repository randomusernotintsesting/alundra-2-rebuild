#ifndef A2_NATIVE_FLINT_H
#define A2_NATIVE_FLINT_H
#include "native_actor_packets.h"
#include "native_mesh_backend.h"
#include "native_model.h"

/* Approved PC00 variant 0, reference 2999, 16 native + 3 authored drivers.
 * actor = actor_to_world * approved grounded contact translation. All skin
 * matrices are actor-space deltas, with no camera or presentation transform.
 * Unsupported actions retain native motion (feet use native 10/13, no floor
 * correction). Failure leaves both output arrays untouched. */
int a2_flint_pose(const A2ActorPacketOwner *,const A2NativeModel *,
                  A2MeshMat4 *actor,A2MeshMat4 *skin,size_t capacity);
/* Immutable, cooked contract qualification, including exact bind records. */
int a2_flint_model_supported(const A2NativeModel *);
/* Exact GAME00 PC00 or explicit measured EVENT00 FRITTO cross-source contract. */
int a2_flint_owner_supported(const A2ActorPacketOwner *,const A2NativeModel *);
/* Source-index consumption for sparse EVENT models: extra meshes stay native. */
int a2_flint_source_part_replaced(const A2ActorPacketOwner *,unsigned source_part);
/* Uses generated per-submesh dependency masks: no per-frame vertex traversal.
 * 1 visible, 0 hidden dependency, -1 invalid owner/model/submesh. Derived
 * drivers inherit the visibility of every native input they require. Shield
 * equipment additionally follows native15; its shared glove/arm mount does not. */
int a2_flint_submesh_visible(const A2ActorPacketOwner *,const A2NativeModel *,unsigned submesh);
#endif
