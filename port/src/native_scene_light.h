#ifndef A2_NATIVE_SCENE_LIGHT_H
#define A2_NATIVE_SCENE_LIGHT_H
#include <stdint.h>
/* Copied original NCDS controls. The actor projector rotates source normals
 * into renderer WORLD axes before the color instruction; these matrices must
 * not be rotated by the camera or actor again. No guest pointers survive.
 * known=0 disables this optional bridge (legacy/chest behavior unchanged).
 * background/far_color preserve GTE control units, not normalized colors. */
typedef struct {
    uint32_t known;
    int16_t light_q12[9],color_q12[9];
    int32_t background[3],far_color[3];
    int32_t dqa,dqb;
    uint32_t projection_h;
} A2NativeSceneLight;
/* Takes raw GTE C[0..31]; uses only C8..23,C26..28. Unused halfwords and
 * unrelated camera/FLAG controls are deliberately ignored. Returns0 without
 * modifying out on invalid H. Equality compares semantic fields, no padding. */
int a2_native_scene_light_decode(const uint32_t control[32],A2NativeSceneLight *out);
int a2_native_scene_light_equal(const A2NativeSceneLight *,const A2NativeSceneLight *);
int a2_native_scene_light_valid(const A2NativeSceneLight *);
#endif
