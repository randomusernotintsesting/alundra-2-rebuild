#ifndef A2_NATIVE_MESH_MATERIAL_H
#define A2_NATIVE_MESH_MATERIAL_H
#include "native_model.h"
#include "native_mesh_backend.h"
/* Pure checked recipe translation. No GPU calls. A texture-bearing material
 * requires a nonzero caller-owned handle (a placeholder is valid for planning).
 * PC00 semantics are bound to the qualified source SHA/variant and exact
 * material records. Unknown recipes fail without changing *out. */
int a2_mesh_material(const A2NativeModel *model,uint32_t index,
                     A2MeshHandle texture,A2MeshMaterial *out);
#endif
