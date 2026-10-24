#ifndef A2_NATIVE_MODEL_H
#define A2_NATIVE_MODEL_H
#include "a2_resources.h"
#include <stddef.h>
#include <stdint.h>

#define A2_MODEL_MAX_BYTES (128u*1024u*1024u)
#define A2_MODEL_MAX_JOINTS 64u
/* Header byte 24 bit 0: finite corner RGB [-16,16]; alpha remains [0,1]. */
#define A2_MODEL_SIGNED_CORNER_RGB 1u
typedef struct {
    float position[3],normal[3],uv[2][2],color[2][4];
    uint16_t joints[4];
    float weights[4];
} A2ModelVertex;
typedef struct {
    uint32_t kind,alpha_mode,texture[2];
    float base_color[4],roughness,metallic,alpha_cutoff,opacity;
    float specular,ior,coat,coat_roughness;
    uint32_t flags;
    float roughness_min,roughness_max;
    char name[32];
} A2ModelMaterial;
typedef struct {
    uint32_t source_id,parent,flags;
    float bind[16],inverse_bind[16];
} A2ModelJoint;
typedef struct {
    uint32_t first_index,index_count,material,source_part;
    float bounds[6];
} A2ModelSubmesh;
typedef struct {
    uint32_t width,height,flags;
    size_t bytes;
    uint8_t *rgba;
} A2ModelTexture;
typedef struct {
    char source_key[32]; uint8_t source_sha256[32]; uint32_t source_variant,file_flags;
    uint32_t vertex_count,index_count,material_count,joint_count,submesh_count,texture_count,index_width;
    float bounds[6];
    A2ModelVertex *vertices;
    void *indices; /* host-endian u16/u32, width above */
    A2ModelMaterial *materials;
    A2ModelJoint *joints;
    A2ModelSubmesh *submeshes;
    A2ModelTexture *textures;
    size_t allocated_bytes;
} A2NativeModel;

/* out must address an empty (NULL) model slot. Failure leaves it unchanged.
 * Data is copied into owned host arrays; caller may free the input bytes.
 * No guest RAM, SDL, GPU or model replacement side effects. */
int a2_native_model_decode(const void *bytes,size_t length,A2NativeModel **out,char *error,size_t error_size);
int a2_native_model_load(A2Resources *,A2ResourceId,A2NativeModel **out,char *error,size_t error_size);
void a2_native_model_destroy(A2NativeModel *model);
#endif
