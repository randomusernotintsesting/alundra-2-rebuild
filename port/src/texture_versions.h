#ifndef A2_TEXTURE_VERSIONS_H
#define A2_TEXTURE_VERSIONS_H
#include <stddef.h>
#include <stdint.h>
typedef struct A2TexCache A2TexCache;
typedef struct A2TexVersion A2TexVersion;
typedef struct {uint32_t mode,page,clut,width_words,palette_words,word_count;uint64_t id;} A2TexRegion;
typedef struct {uint64_t requests,hits,misses,evictions,copied_bytes,live_bytes,peak_bytes,epoch_resets,write_marks;} A2TexStats;
A2TexCache *a2_tex_create(size_t payload_limit,unsigned slot_limit);
void a2_tex_destroy(A2TexCache *cache);
/* Single CPU owner. Call after every native write before another acquire.
 * Coordinates wrap as nativeVRAM; zero/negative extents have no writes. */
void a2_tex_written(A2TexCache *cache,int x,int y,int width,int height);
void a2_tex_reset(A2TexCache *cache);
/* A returned lease pins immutable words until release. NULL is bounded
 * capacity/allocation failure: retire oldGPU work before retrying. */
const A2TexVersion *a2_tex_acquire(A2TexCache *cache,const uint16_t *native,uint32_t page,uint32_t clut);
void a2_tex_release(A2TexCache *cache,const A2TexVersion *version);
A2TexRegion a2_tex_region(const A2TexVersion *version);
const uint16_t *a2_tex_words(const A2TexVersion *version);
A2TexStats a2_tex_stats(const A2TexCache *cache);
/* Scalar contract oracle for the local raw layout, including nativewindow.
 * GPU implementation must use the same indices; no decoded image required. */
uint16_t a2_tex_sample(const A2TexVersion *version,uint32_t window,int u,int v);
#ifdef A2_TEX_TEST
void a2_tex_test_set_epoch(A2TexCache *cache,uint64_t epoch);
#endif
#endif
