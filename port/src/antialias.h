#ifndef A2_ANTIALIAS_H
#define A2_ANTIALIAS_H
#include <stdint.h>
#include <stddef.h>
typedef struct A2Antialias A2Antialias;
typedef struct { uint64_t gpu_dispatches, reused_frames; } A2AntialiasStats;
A2Antialias *a2_antialias_create(char *error,size_t error_size);
/* In-place host ARGB8888 presentation only. Padding and input on failure stay
 * untouched. No access to guest memory, VRAM or renderer provenance. */
int a2_antialias_apply(A2Antialias *,uint32_t *pixels,int width,int height,
                       int stride,char *error,size_t error_size);
void a2_antialias_destroy(A2Antialias *);
A2AntialiasStats a2_antialias_stats(const A2Antialias *);
#endif
