#ifndef A2_GPU_FINE_H
#define A2_GPU_FINE_H
#include <stddef.h>
#include <stdint.h>
/* H30 affine ABI. Coordinates are fine-surface signed Q16; attributes 0..255.
 * state = tpage, clut, texwin, flags (gouraud=1, texture=2, semi=4, filter=8).
 * clip is inclusive x0,y0,x1,y1; uv is the CPU's Q8 filtering clamp. */
typedef struct { int64_t x,y; uint32_t r,g,b,u,v,pad; } A2FineVertex;
typedef struct { A2FineVertex p[3]; int32_t clip[4]; uint32_t state[4];
                 int32_t uv[4]; uint32_t width,height; } A2FineParams;
_Static_assert(sizeof(A2FineVertex)==40,"fine vertex ABI");
_Static_assert(sizeof(A2FineParams)==176,"fine params ABI");
typedef struct A2FineGpu A2FineGpu;
/* Exact CPU-floor sample offsets in Q8 units; active offsets are in ±65280. */
typedef struct { uint32_t count; int32_t offsets[16][2]; } A2FineMinify;
_Static_assert(sizeof(A2FineMinify)==132,"fine minify ABI");
typedef struct {
    uint64_t triangles,submissions,waits,uploaded_bytes,texture_uploaded_bytes;
    uint64_t buffer_allocations,capacity_rejections,unsupported_rejections;
    uint64_t texture_requests,texture_hits,texture_misses,texture_copied_bytes;
    uint64_t queued_triangles,peak_queued_triangles,peak_texture_pool_bytes;
    uint64_t masked_triangles,mask_uploaded_bytes,peak_mask_pool_bytes,minified_triangles;
    double prepare_ms,encode_ms,wait_ms,gpu_ms;
} A2FineGpuStats;
/* Single CPU owner. low/rgb allocations must be page-aligned AND sized up to
 * whole pages. Metal borrows them without a deallocator: destroy before free.
 * No CPU fine-surface access between accepted enqueue and successful sync. */
A2FineGpu *a2_fine_gpu_create(unsigned width,unsigned height,uint16_t *low,
    uint32_t *rgb,char *error,size_t error_size);
/* Takes an immutable native texture snapshot immediately. Call AFTER the
 * primitive's native raster and its written() notification. Never submits or
 * waits. 0 means this command was not accepted; sync prior work before fallback. */
int a2_fine_gpu_enqueue(A2FineGpu *,const A2FineParams *,const uint16_t *native,
    char *error,size_t error_size);
/* Zeroed visibility bits relative to inclusive params.clip. Requires a nonempty
 * clip inside the surface; stride=(clip[2]-clip[0]+8)/8 bytes, low bit first.
 * Accepted1 returns writable memory valid until the next backend call. Fill it
 * immediately; later enqueues preserve those bits until sync retires the batch.
 * Rejected0 sets *mask=NULL and accepts no command. No allocation/failure occurs
 * after acceptance while the caller fills the mask. */
int a2_fine_gpu_enqueue_masked(A2FineGpu *,const A2FineParams *,const uint16_t *native,
    uint8_t **mask,char *error,size_t error_size);
/* Two contiguous zeroed planes with the same clip origin/stride as above.
 * A minify bit takes precedence; otherwise an allow bit selects normal shade.
 * Requires textured+filtered params and count 2,4,8 or16. Copies footprint now.
 * Both returned pointers are valid until the next backend call; every rejection
 * sets both NULL and accepts no command. CPU remains responsible for depth and
 * minify certificates. Transparent taps preserve the ordered destination. */
int a2_fine_gpu_enqueue_minified(A2FineGpu *,const A2FineParams *,const uint16_t *native,
    const A2FineMinify *,uint8_t **allow,uint8_t **minify,char *error,size_t error_size);
void a2_fine_gpu_written(A2FineGpu *,int x,int y,int width,int height);
/* Submits one ordered tile batch, then waits. Empty sync is cheap. A 0 return
 * means execution is unusable: caller must terminate rather than CPU fallback. */
int a2_fine_gpu_sync(A2FineGpu *,char *error,size_t error_size);
A2FineGpuStats a2_fine_gpu_stats(const A2FineGpu *);
void a2_fine_gpu_destroy(A2FineGpu *);
#endif
