#ifndef A2_NATIVE_MESH_COMPOSITE_H
#define A2_NATIVE_MESH_COMPOSITE_H
#include <stddef.h>
#include <stdint.h>

/* Diagnostic/opt-in opaque-model bridge. No guest VRAM or GPU ownership.
 * Coordinates passed to pixel() are LOCAL to a caller-proven union ROI.
 * All image rows are top-down; stride and size are bytes. */
typedef struct A2MeshComposite A2MeshComposite;
typedef struct { const void *data; size_t size, stride; } A2CompositeImage;
typedef enum {
    A2_COMPOSITE_UNKNOWN=0, A2_COMPOSITE_WORLD=1,
    A2_COMPOSITE_OWNED=2, A2_COMPOSITE_HUD=3,
    A2_COMPOSITE_ORDERED=4 /* actual native command order, no physical Z */
} A2CompositeKind;
typedef struct {
    A2CompositeKind kind;
    float depth; /* normalized model-compatible depth [0,1], smaller nearer */
    uint8_t r,g,b; /* resolved/modulated source RGB8, BEFORE quantization */
    uint8_t semi,textured,blend_mode;
    uint16_t texel; /* only zero transparency/STP; RGB is already resolved */
} A2CompositePixel;

/* Persistent allocation; dimensions 1..4096, at most 4M pixels. */
A2MeshComposite *a2_mesh_composite_create(uint32_t width,uint32_t height);
void a2_mesh_composite_destroy(A2MeshComposite *c);
/* Begin copies inputs. Clean RGB555 background MUST precede all world draws;
 * caller proves full clear, union bounds, opaque-only model and same camera.
 * model: RGB555; depth: float32; coverage: uint8 0/1. Uncovered depth ignored.
 * Failure invalidates the previous frame; no stale image can be selected. */
int a2_mesh_composite_begin(A2MeshComposite *c,int clean_background_proven,
    A2CompositeImage background,A2CompositeImage model,
    A2CompositeImage depth,A2CompositeImage coverage);
/* Model owner tags are 1..count (max64), zero outside model coverage.
 * Native-order pixels before that owner's first source packet are behind
 * its opaque replacement; pixels after it retain the original stream order.
 * WORLD-depth and HUD semantics remain independent of these anchors. */
int a2_mesh_composite_owners(A2MeshComposite *c,A2CompositeImage tags,unsigned count);
int a2_mesh_composite_anchor(A2MeshComposite *c,unsigned tag);
/* A literal framebuffer write replaces the displayed sample and retires
 * model-depth metadata at that sample. It is not a new world fragment. */
void a2_mesh_composite_store(A2MeshComposite *c,int x,int y,uint16_t value);
/* Feed each actually sampled legacy pixel in original OT order, independently
 * of the original renderer (which MUST still render normally). Outside-ROI
 * events and fully transparent PSX texels do nothing. Unknown covered events
 * invalidate the entire ROI. OWNED suppresses only exactly proven old model
 * packets, including old-only silhouette; HUD draws in front without depth.
 * At model-covered pixels discard every farther WORLD sample, opaque or
 * semi. Fold nearer/equal WORLD and HUD in original OT order over the model;
 * WORLD samples do not update the fixed model depth. With no model coverage,
 * retain ordinary legacy OT rendering. HUD bypasses the depth test but keeps
 * its original position in that stream.
 * Unsupported HD coverage/masks/blend semantics require invalidate(). */
void a2_mesh_composite_pixel(A2MeshComposite *c,int x,int y,A2CompositePixel p);
/* For one actually covered HD sample: same ownership/depth gate as pixel().
 * Apply the renderer's pure color transform immediately; never retain pointer. */
uint16_t *a2_mesh_composite_destination(A2MeshComposite *c,int x,int y,A2CompositeKind kind,float depth);
void a2_mesh_composite_invalidate(A2MeshComposite *c);
int a2_mesh_composite_valid(const A2MeshComposite *c);
/* First rejection cause: 0 none,1 external write,2 bad input,3 unknown
 * coverage,4 incompatible depth;5 reserved (former order guard). Diagnostic only. */
unsigned a2_mesh_composite_failure(const A2MeshComposite *c);
/* Select ONLY after the complete frame and caller lifetime checks. On any
 * failure returns the caller's untouched original ROI row. Borrowed result
 * remains owned by c and is valid only until the next begin/destroy. */
const uint16_t *a2_mesh_composite_row(const A2MeshComposite *c,uint32_t y,
                                     const uint16_t *original);
#endif
