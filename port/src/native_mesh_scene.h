#ifndef A2_NATIVE_MESH_SCENE_H
#define A2_NATIVE_MESH_SCENE_H
#include "native_actor_packets.h"
#include "native_mesh_backend.h"
#include "native_model.h"

/* Pure row-major pose/projection bridge. World axes are the native renderer
 * axes; camera Q12 rotation may contain scale and is never orthonormalized. */
int a2_mesh_pose(const A2ActorPacketOwner *,const A2NativeModel *,
                 A2MeshMat4 *actor,A2MeshMat4 *skin,size_t capacity);
int a2_mesh_camera(const A2ActorPacketOwner *,unsigned width,unsigned height,
                   unsigned scale,int wide,A2MeshMat4 *view_projection);

typedef struct A2MeshScene A2MeshScene;
A2MeshScene *a2_mesh_scene_create(unsigned width,unsigned height,char *error,size_t error_size);
void a2_mesh_scene_destroy(A2MeshScene *);
/* Copies mesh/texture data into persistent GPU buffers. Model ownership is
 * retained by caller until scene destruction; no per-frame resource upload. */
int a2_mesh_scene_add(A2MeshScene *,const A2NativeModel *);
/* Pure, stable selection by loaded key/variant/source identity and supported
 * opaque materials. Skipped owners retain their original display packets.
 * No pose/camera selection, drawing or ownership mutation occurs here. Returns
 * zero without writing selected on invalid arguments or insufficient capacity.
 * Models remain immutable while registered. Input/output arrays may overlap. */
size_t a2_mesh_scene_plan(const A2MeshScene *,const A2ActorPacketOwner *const *,size_t count,
                          const A2ActorPacketOwner **selected,size_t capacity);
/* All selected owners must share one camera and have valid poses. The current
 * opaque material contract excludes cooked translucent T03 independently of
 * its name; missing/unsupported resources must be removed with scene_plan. */
int a2_mesh_scene_draw(A2MeshScene *,const A2ActorPacketOwner *const *,size_t count,
                       unsigned scale,int wide,uint8_t *rgba,size_t rgba_size,
                       float *depth,size_t depth_size);
/* Last completed scene target, aligned with draw's RGBA/depth. Tight uint32
 * rows; 0 is clear and i+1 identifies owners[i] in that submitted scene draw.
 * All visible submeshes of an owner share its tag. */
int a2_mesh_scene_read_owners(A2MeshScene *,uint32_t *owners,size_t owners_size);
#endif
