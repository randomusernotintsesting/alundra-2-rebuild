#ifndef A2_NATIVE_MESH_BACKEND_H
#define A2_NATIVE_MESH_BACKEND_H
#include <stddef.h>
#include <stdint.h>
#include "native_scene_light.h"

/* Diagnostic offscreen backend; no SDL/window/guest memory dependency.
 * Single-threaded owner. All matrices are ROW-MAJOR, multiply COLUMN vectors.
 * clip = view_projection * model * skin * position. Clip depth is [0,w].
 * RGBA8 and depth readback rows start at the TOP; UV (0,0) is texture top-left.
 * Metal implementation transposes matrix storage explicitly at upload.
 * PLAIN/LAYERED_ATLAS retain the original unlit pass. The optional LIT passes
 * use a fixed world light, ambient and GGX response (not Blender studio light).
 * Textures are linear RGBA8; no implicit sorting, culling or mipmapping. Color inputs and
 * clear color are linear. texture_srgb explicitly decodes sampled RGB; frame
 * encode_srgb selects hardware output encoding (including linear blending).
 */
#define A2_MESH_MAX_DRAWS 128
#define A2_MESH_MAX_JOINTS 64
typedef struct A2MeshBackend A2MeshBackend;
typedef uint64_t A2MeshHandle;
typedef struct { float m[16]; } A2MeshMat4;
typedef struct {
    float position[3], normal[3], uv[2], uv1[2], color[4], color1[4];
    uint16_t joints[4];
    float weights[4];
} A2MeshVertex;
typedef enum { A2_MESH_INDEX_U16=2, A2_MESH_INDEX_U32=4 } A2MeshIndexType;
typedef enum { A2_MESH_OPAQUE=0, A2_MESH_MASK=1, A2_MESH_BLEND=2 } A2MeshAlpha;
typedef enum { A2_MESH_PLAIN=0, A2_MESH_LAYERED_ATLAS=1,
               A2_MESH_LIT_CONSTANT=2, A2_MESH_LIT_SHIELD=3 } A2MeshShader;
typedef enum { A2_MESH_NEAREST=0, A2_MESH_LINEAR=1 } A2MeshFilter;
typedef enum { A2_MESH_CLAMP=0, A2_MESH_REPEAT=1, A2_MESH_CLIP=2 } A2MeshAddress;
typedef struct {
    float base_color[4], roughness, metallic, alpha_cutoff;
    A2MeshAlpha alpha;
    A2MeshHandle texture; /* 0 = white; other handles must belong to backend. */
    A2MeshShader shader;
    unsigned texture_srgb;
    A2MeshFilter filter;
    A2MeshAddress address;
    float specular, bump_strength, bump_distance; /* distance in world units */
    unsigned bump_invert;
    /* LAYERED_ATLAS samples uv1 (plain samples uv), computes
     * mix(color.rgb, 2*color1.rgb*decoded_texture.rgb, texture.a)*base_color.rgb.
     * Atlas alpha is the MIX FACTOR, so alpha mode must be OPAQUE. */
    /* LIT_CONSTANT ignores corner colors/textures. LIT_SHIELD uses the same
     * layered albedo in UV1, plus alpha-height bump. Both are opaque. CLIP
     * samples transparent black beyond the image, including filter borders.
     * Lit normals use inverse transpose of the blended skin and model linear
     * transform; a singular/zero normal uses the actual triangle normal.
     * Corner RGB is finite [-16,16]; alpha is [0,1]. No pre-light RGB clamp. */
} A2MeshMaterial;
typedef struct {
    A2MeshHandle mesh;
    uint32_t first_index, index_count; /* triangle list, count multiple of 3 */
    A2MeshMat4 model;
    const A2MeshMat4 *joints; /* final skin matrices, NOT joint world poses */
    uint32_t joint_count; /* 0 = unskinned; otherwise all used IDs must fit */
    A2MeshMaterial material;
    unsigned depth_test, depth_write, color_write; /* each exactly 0 or 1 */
    uint32_t owner_tag; /* Exact fragment ownership; 0 is untagged. */
    A2NativeSceneLight native_light; /* known1 replaces fixed preview lighting
        with the copied actor NCDS scene response; known0 preserves old output. */
} A2MeshDraw;
typedef struct {
    A2MeshMat4 view_projection;
    float clear_rgba[4], clear_depth; /* finite, each [0,1] */
    unsigned encode_srgb;
    float camera_world[3]; /* finite world-space eye for optional lit materials */
} A2MeshFrame;
typedef struct { uint32_t meshes, textures; uint64_t submissions; } A2MeshStats;

/* Returns NULL with a bounded error string if Metal is unavailable or setup
 * fails. Offscreen dimensions are fixed for this backend lifetime (1..4096).
 * Non-Metal builds may omit this backend; callers must preserve old fallback.
 */
A2MeshBackend *a2_mesh_backend_create(uint32_t width, uint32_t height,
                                    char *error, size_t error_size);
void a2_mesh_backend_destroy(A2MeshBackend *backend); /* NULL is safe */
const char *a2_mesh_backend_name(const A2MeshBackend *backend);
void a2_mesh_backend_stats(const A2MeshBackend *backend, A2MeshStats *out);

/* Copies input at creation into persistent GPU resources. Zero is failure.
 * IDs are backend-owned, reject foreign/stale handles. Resource destruction
 * is synchronous and safe after render returns; backend destroy frees all.
 * Each vertex has finite attributes, nonnegative weights summing to 1 within
 * 1e-4 (binary32 values accumulated in double, matching A2M2 validation).
 */
A2MeshHandle a2_mesh_create(A2MeshBackend *, const A2MeshVertex *, uint32_t vertices,
                          const void *indices, uint32_t count, A2MeshIndexType);
int a2_mesh_destroy(A2MeshBackend *, A2MeshHandle);
A2MeshHandle a2_mesh_texture_create(A2MeshBackend *, uint32_t width, uint32_t height,
                                  const uint8_t *rgba, size_t bytes_per_row);
int a2_mesh_texture_destroy(A2MeshBackend *, A2MeshHandle);

/* Validates the entire batch before encoding; invalid input leaves the last
 * completed image untouched. Draw order is caller order; depth compare LESS.
 * BLEND uses straight-alpha source-over. Completion/error is synchronous.
 * Does not allocate mesh/texture resources per draw. On GPU failure readback
 * is unavailable until a successful new render. Empty batches clear targets.
 */
int a2_mesh_render(A2MeshBackend *, const A2MeshFrame *, const A2MeshDraw *, size_t count);
/* Copies the last completed targets, without rendering. Both outputs required;
 * size/stride checks occur before writes. RGBA8 and float32 depth, no padding
 * written. Pure diagnostic: readback cost is not production performance.
 */
int a2_mesh_readback(A2MeshBackend *, uint8_t *rgba, size_t rgba_bytes, size_t rgba_stride,
                     float *depth, size_t depth_bytes, size_t depth_stride);
/* Independent uint32 readback from that same completed render, top-down.
 * Clear pixels are 0. The tag follows the last surviving color-writing
 * fragment, including tag 0; MASK discard and depth rejection write no tag.
 * Tags never blend. Opaque depth-testing/depth-writing draws therefore report
 * the nearest owner (LESS retains the first equal-depth fragment). For BLEND
 * this identifies the latest fragment, even at zero alpha, not a set of
 * contributors to the blended color.
 * Validation/lifetime match a2_mesh_readback; row padding is left untouched. */
int a2_mesh_readback_owners(A2MeshBackend *,uint32_t *owners,size_t owners_bytes,
                            size_t owners_stride);
#endif
