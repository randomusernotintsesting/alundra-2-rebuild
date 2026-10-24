#ifndef A2_GPU_PRESENT_H
#define A2_GPU_PRESENT_H
#include "input_prompts.h"
#ifndef A2_GPU_API
#define A2_GPU_API
#endif
typedef struct A2GpuPresent A2GpuPresent;
typedef struct {
    uint64_t prepared, aa_dispatches, aa_reuses, panel_uploads, composites;
    uint64_t commits, presented, readbacks, window_readbacks, previous_waits;
} A2GpuPresentStats;
/* Game-thread API. layer is the SDL-owned CAMetalLayer, or NULL for a real
 * Metal offscreen test. Caller must flush SDL before custom rendering, and
 * suspend this backend before SDL takes over the layer. */
A2_GPU_API A2GpuPresent *a2_gpu_present_create(void *layer,char *error,size_t size);
/* Raw host ARGB8888 is copied, never modified/retained. Width/height1..4096.
 * The previous submission is drained before any resource is overwritten. */
A2_GPU_API void a2_gpu_present_set_fill(A2GpuPresent *,int fill);
A2_GPU_API int a2_gpu_present_prepare(A2GpuPresent *,const uint32_t *pixels,
    int width,int height,int stride,int antialias,char *error,size_t size);
/* Add at most3 ordered premultiplied panels during their visitor callbacks.
 * Pixels are consumed immediately, never retained. Nonzero generations must
 * change when panel pixels change. Coordinates must be within±16384. */
A2_GPU_API int a2_gpu_present_panel(A2GpuPresent *,const A2PromptPixels *,char *error,size_t size);
/* Seals panels. Returns1 when a drawable is submitted,0 for compute-only or
 * unavailable drawable,-1 on failure. This is submission, not display time.
 * Ordinary submission never waits for nextDrawable. window_capture is an
 * explicit synchronous acquisition, even when show=0; no present then. */
A2_GPU_API int a2_gpu_present_commit(A2GpuPresent *,int show,int window_capture,char *error,size_t size);
/* Explicit synchronous GPU captures. Input-grid readback writes visible
 * pixels only; padding remains unchanged. May run before or after commit. */
A2_GPU_API int a2_gpu_present_readback(A2GpuPresent *,uint32_t *,int stride,char *error,size_t size);
A2_GPU_API const uint32_t *a2_gpu_present_window_pixels(A2GpuPresent *,int *width,int *height,int *stride,char *error,size_t size);
A2_GPU_API int a2_gpu_present_flush(A2GpuPresent *,char *error,size_t size);
/* Stop/drain drawable acquisition before SDL takeover or teardown.
 * prepare resumes acquisition. flush drains GPU commands only. */
A2_GPU_API int a2_gpu_present_suspend(A2GpuPresent *,char *error,size_t size);
A2_GPU_API A2GpuPresentStats a2_gpu_present_stats(const A2GpuPresent *);
A2_GPU_API void a2_gpu_present_destroy(A2GpuPresent *);
#endif
