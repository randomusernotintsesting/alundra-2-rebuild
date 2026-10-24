/* PS1 GPU: GP0/GP1 command decode + software rasterizer into 1MB VRAM.
 * Affine texturing (authentic), gouraud, semi-transparency, CLUT 4/8/15bpp.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef A2_WORLD_PRECISION
#include <math.h>
#endif
#include "psx_rt.h"
#ifdef A2_NATIVE_BILLBOARD
#include "native_billboard.h"
#endif
#include "phase_timing.h"
#ifdef A2_NATIVE_MESH
#include "native_mesh_live.h"
extern uint32_t psx_frame_no;
static uint64_t fifo_mesh_token,mesh_pixel_owner;
#ifdef A2_DIALOGUE_PACKETS
#include "dialogue_packets.h"
static uint64_t fifo_dialogue_token;
#endif
#ifdef A2_NATIVE_BILLBOARD
#include "native_billboard.h"
static uint64_t fifo_billboard_token;
#endif
static double mesh_billboard_depth;
static A2CompositeKind mesh_pixel_kind;
static int mesh_depth_valid,mesh_fallback_projection_valid;
static double mesh_depth_plane[3],mesh_vertex_depth[3];
/* Native command order is the explicit fallback for samples whose physical
 * depth was not exported. It never changes the selected model resource. */
static A2CompositeKind mesh_kind_at(int x,int y,float *depth){
    A2CompositeKind kind=mesh_pixel_kind;*depth=0;
    if(kind==A2_COMPOSITE_WORLD){
        if(mesh_depth_valid)*depth=(float)(mesh_depth_plane[0]*x+mesh_depth_plane[1]*y+mesh_depth_plane[2]);
        if(!mesh_depth_valid||!isfinite(*depth)||*depth<0||*depth>1)kind=A2_COMPOSITE_ORDERED;
    }
    return kind==A2_COMPOSITE_UNKNOWN?A2_COMPOSITE_ORDERED:kind;
}
static void mesh_depth_setup(double,double,double,double,double,double);

#endif
#ifdef A2_CINEMA_EXPANSION
static void cinema_invalidate(void);
#endif
#ifdef A2_HUD_PRESENT
#include "hud_present.h"
static int hud_anchor=-1, ir1_mirror;
static uint64_t fifo_hud_token;
#endif
#ifdef A2_INPUT_PROMPTS
#include "input_prompts.h"
#endif
#ifdef A2_HD_FONTS
#include "hd_font.h"
#include "hd_ui.h"
static const A2HDPlate *hd_plates[128];
static unsigned hd_plate_count;
#ifdef A2_HD_ART
#include "hd_art.h"
#ifndef A2_HD_ART_TEST
#include "../assets/hd_art_data.h"
#endif
static const A2HDArt *hd_art[128];
static unsigned hd_art_count;
#endif
#ifdef A2_HD_PORTRAITS
#include "hd_portraits.h"
#ifndef A2_HD_PORTRAITS_TEST
#include "../assets/hd_portraits_data.h"
#endif
static const A2HDPortrait *hd_portrait;
#endif
static void hd_matches_reset(void) {
    hd_plate_count=0;
#ifdef A2_HD_ART
    hd_art_count=0;
#endif
#ifdef A2_HD_PORTRAITS
    hd_portrait=NULL;
#endif
}
static int hd_matches_active(void) {
    return hd_plate_count
#ifdef A2_HD_ART
        || hd_art_count
#endif
#ifdef A2_HD_PORTRAITS
        || hd_portrait
#endif
        ;
}
#endif

uint16_t GPU_VRAM[512 * 1024];

static struct {
    int dax1, day1, dax2, day2;        /* draw area */
    int ofx, ofy;                      /* draw offset */
    uint32_t texpage;                  /* E1 bits */
    uint32_t texwin;                   /* E2 bits (mask/offset, 8px units) */
    int disp_x, disp_y, disp_w, disp_h;
    int vrange_lines;                  /* GP1(07): visible scanlines */
    int vrange_y1;                     /* GP1(07): first visible scanline */
    int hrange_x1, hrange_x2;          /* GP1(06): horizontal display range */
    int display_on;
    uint32_t stat_extra;
    int odd;
} g = {.disp_w = 320, .disp_h = 240};

/* GP0 packet assembly */
static uint32_t fifo[64];
#if defined(A2_WORLD_PRECISION) || defined(A2_HUD_PRESENT)
static uint32_t fifo_source[64];
#endif
#ifdef A2_WORLD_PRECISION
static world_precision_vertex fifo_world[64];
static world_precision_vertex world_vertices[4];
static int world_primitive_valid;
static uint64_t world_consumer_sequence;
static int world_raster_enabled;
void gpu_set_world_raster(int enabled);
#endif
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
#include "world_shadow.h"
#endif
static int model_depth_enabled;
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
/* Depth belongs to the opaque model which last wrote each pixel in this
 * DMA pass. Sealed models in the same physical camera share visibility.
 * Unknown/other-camera writes retire their coverage; bulk writers and
 * pass boundaries retire the entire surface. */
typedef struct {double inverse_z;uint64_t owner;uint32_t stamp,face;} ModelDepthPixel;
typedef struct {
    int32_t origin_q12[3],h,ofx,ofy;
    int16_t rotation_q12[9];
    unsigned source_family;
} ModelDepthCamera;
static ModelDepthCamera model_depth_camera;
/* Opaque camera-projected WORLD faces share the surface under this owner.
 * PS1 orders a model against WORLD by whole-face average depth; a large
 * near face can then sort behind small far model faces. WORLD-WORLD order
 * stays original (authored decals/layers); only WORLD-model pairs compare. */
#define MODEL_DEPTH_WORLD_OWNER UINT64_MAX
/* Camera units. Authored contacts (feet on floors, backs against walls)
 * keep their original order inside this band. */
#define WORLD_DEPTH_CONTACT 8.0
/* Ground shadows: legacy policy (32 units, model only, retires depth) unless
 * WORLD depth is on, which also enables the physical decal rules. */

static int world_depth_enabled=-1,model_depth_world;
static double shadow_model_margin=32.0,shadow_world_margin=1e30;static int shadow_keep_depth;
static int world_depth_on(void) {
    if(world_depth_enabled<0){const char *v=getenv("A2_WORLD_DEPTH");world_depth_enabled=v&&!strcmp(v,"1");
        if(world_depth_enabled){shadow_model_margin=4.0;shadow_world_margin=16.0;shadow_keep_depth=1;
            const char *m=getenv("A2_SHADOW_MODEL_MARGIN"),*w=getenv("A2_SHADOW_WORLD_MARGIN");
            if(m)shadow_model_margin=atof(m);if(w)shadow_world_margin=atof(w);}}
    return world_depth_enabled==1;
}
static uint64_t world_depth_admitted,world_depth_rejected_model;
/* Models read WORLD depth only where they draw. Record WORLD depth only near
 * this frame's models so far and the previous frame's models (native, page-
 * local), grown for camera/actor motion. Outside it WORLD keeps native order. */
#define WORLD_DEPTH_ROI_MARGIN 48
static struct {int valid,x0,y0,x1,y1;} model_roi_now,model_roi_last;
static uint32_t model_roi_frame;
static int world_roi_x0,world_roi_y0,world_roi_x1,world_roi_y1; /* fine, full surface */
static void model_roi_roll(void) {
    if(model_roi_frame==psx_frame_no)return;
    model_roi_frame=psx_frame_no;
    if(model_roi_now.valid){model_roi_last=model_roi_now;model_roi_now.valid=0;}
}
static void model_roi_write(int x,int y) {
    if(!model_roi_now.valid){model_roi_now.valid=1;model_roi_now.x0=model_roi_now.x1=x;model_roi_now.y0=model_roi_now.y1=y;return;}
    if(x<model_roi_now.x0)model_roi_now.x0=x;if(x>model_roi_now.x1)model_roi_now.x1=x;
    if(y<model_roi_now.y0)model_roi_now.y0=y;if(y>model_roi_now.y1)model_roi_now.y1=y;
}
/* Experimental texture minification requires an actual opaque base write,
 * not merely the same owner/face depth left by a previous material layer. */
static int model_minify_enabled=-1;
static uint64_t model_minify_word,model_minify_prefix_word;
static uint32_t model_minify_prefix_value,model_minify_prefix_address;
static uint64_t model_minify_write,model_minify_pair;
static uint64_t *model_minify_keys;
static size_t model_minify_key_count;
static int model_minify_tracking;
static struct {
    uint64_t word,camera_generation;
    A2ActorPacket packet;
    int64_t xy[3][2];double z[3];
    ModelDepthCamera camera;
    uint32_t stamp;int scale;
} model_minify_base;
static int32_t model_depth_root_q12[3];
static uint64_t model_depth_other_owner;
static int model_depth_other_camera_matches;
static ModelDepthPixel *model_depth_pixels;
static size_t model_depth_count;
static unsigned model_depth_scale;
static uint32_t model_depth_stamp=1,model_depth_face;
static uint64_t model_depth_owner,model_depth_admitted,model_depth_rejected;
static int model_depth_plane_valid,model_depth_has_samples;
/* Conservative bounds of every successful opaque write in this stamp epoch.
 * Retired pixels need not shrink them; outside both boxes no stamp can be live. */
static struct {int valid,x0,y0,x1,y1;} model_depth_bounds[2];
static void model_depth_bound_write(int page,int x,int y) {
    unsigned i=page!=0;
    if(!model_depth_bounds[i].valid) {
        model_depth_bounds[i].valid=1;
        model_depth_bounds[i].x0=model_depth_bounds[i].x1=x;
        model_depth_bounds[i].y0=model_depth_bounds[i].y1=y;
    } else {
        if(x<model_depth_bounds[i].x0)model_depth_bounds[i].x0=x;
        if(x>model_depth_bounds[i].x1)model_depth_bounds[i].x1=x;
        if(y<model_depth_bounds[i].y0)model_depth_bounds[i].y0=y;
        if(y>model_depth_bounds[i].y1)model_depth_bounds[i].y1=y;
    }
}
static double model_depth_plane[3];
static int model_depth_ground_shadow,model_shadow_camera_matches;
static uint64_t model_shadow_camera_owner,model_shadow_seen,model_shadow_admitted,model_shadow_rejected,model_shadow_camera_misses;
static A2WorldShadowGeometry model_shadow_geometry;
static struct {int valid;double barycentric[2][3],plane[3];} model_shadow_triangles[2];
static int model_depth_same_camera(uint64_t handle) {
    /* Registry mutation cannot interleave a synchronous primitive raster.
     * Cache only within that primitive; re-query sealed lifetime next time. */
    if(model_depth_other_owner!=handle) {
        model_depth_other_owner=handle;
        const A2ActorPacketOwner *owner=a2_native_actor_packets_owner(handle);
        model_depth_other_camera_matches=owner &&
            /* Separate submissions can form authored contact layers at a
             * shared renderer root. Keep their original cross-owner order.
             * Different roots are an admission policy, not attachment proof. */
            memcmp(owner->instance.renderer_root_q12,model_depth_root_q12,sizeof model_depth_root_q12) &&
            owner->instance.source_family==model_depth_camera.source_family &&
            owner->projection_h==model_depth_camera.h && owner->projection_ofx==model_depth_camera.ofx &&
            owner->projection_ofy==model_depth_camera.ofy &&
            !memcmp(owner->camera_origin_q12,model_depth_camera.origin_q12,sizeof model_depth_camera.origin_q12) &&
            !memcmp(owner->camera_rotation_q12,model_depth_camera.rotation_q12,sizeof model_depth_camera.rotation_q12);
    }
    return model_depth_other_camera_matches;
}
static double model_shadow_inverse_z(double x,double y) {
 double nearest=0;
 for(unsigned i=0;i<2;i++)if(model_shadow_triangles[i].valid) {
  const double (*bary)[3]=model_shadow_triangles[i].barycentric;
  double a=bary[0][0]*x+bary[0][1]*y+bary[0][2];
  double b=bary[1][0]*x+bary[1][1]*y+bary[1][2];
  if(a < -1e-10 || b < -1e-10 || a+b > 1+1e-10)continue;
  const double *plane=model_shadow_triangles[i].plane;
  double q=plane[0]*x+plane[1]*y+plane[2];
  /* Folded quads can overlap: only reject when even their nearest
   * physical surface is behind the model. Never extrapolate a half. */
  if(!isfinite(q)||q<=0||q>1)return 0;
  if(q>nearest)nearest=q;
 }
 return nearest;
}
static int model_shadow_same_camera(uint64_t handle) {
 if(model_shadow_camera_owner!=handle) {
  model_shadow_camera_owner=handle;
  const A2ActorPacketOwner *owner=a2_native_actor_packets_owner(handle);
  model_shadow_camera_matches=owner &&
    !memcmp(owner->camera_origin_q12,model_shadow_geometry.origin_q12,sizeof owner->camera_origin_q12) &&
    !memcmp(owner->camera_rotation_q12,model_shadow_geometry.rotation_q12,sizeof owner->camera_rotation_q12) &&
    owner->projection_h==model_shadow_geometry.h && owner->projection_ofx==model_shadow_geometry.ofx &&
    owner->projection_ofy==model_shadow_geometry.ofy;
  if(!model_shadow_camera_matches && ++model_shadow_camera_misses<=4 && getenv("A2_MODEL_DEPTH_LOG") && owner)
   fprintf(stderr,"model-shadow-camera: owner=%llu actor_origin=%d,%d,%d shadow_origin=%d,%d,%d actor_hof=%d,%d,%d shadow_hof=%d,%d,%d\n",
    (unsigned long long)handle,owner->camera_origin_q12[0],owner->camera_origin_q12[1],owner->camera_origin_q12[2],model_shadow_geometry.origin_q12[0],model_shadow_geometry.origin_q12[1],model_shadow_geometry.origin_q12[2],owner->projection_h,owner->projection_ofx,owner->projection_ofy,model_shadow_geometry.h,model_shadow_geometry.ofx,model_shadow_geometry.ofy);
 }
 return model_shadow_camera_matches;
}
static void model_depth_stats(void) {
    if(getenv("A2_MODEL_DEPTH_LOG"))fprintf(stderr,"model-depth: admitted=%llu rejected_pixels=%llu\n",
        (unsigned long long)model_depth_admitted,(unsigned long long)model_depth_rejected);
    if(getenv("A2_MODEL_DEPTH_LOG"))fprintf(stderr,"world-depth: admitted=%llu rejected_model_pixels=%llu\n",
        (unsigned long long)world_depth_admitted,(unsigned long long)world_depth_rejected_model);
    if(getenv("A2_MODEL_DEPTH_LOG"))fprintf(stderr,"model-shadow: candidates=%llu admitted=%llu rejected_pixels=%llu camera_misses=%llu\n",
        (unsigned long long)model_shadow_seen,(unsigned long long)model_shadow_admitted,(unsigned long long)model_shadow_rejected,(unsigned long long)model_shadow_camera_misses);
}
#endif
void gpu_model_depth_barrier(void) {
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
    model_minify_base.word=model_minify_write=model_minify_pair=0;model_minify_tracking=0;
    model_depth_owner=0;model_depth_plane_valid=0;model_depth_has_samples=0;model_depth_ground_shadow=0;
    model_depth_bounds[0].valid=model_depth_bounds[1].valid=0;
    model_depth_other_owner=0;model_depth_other_camera_matches=0;
    if(++model_depth_stamp==0) {
        if(model_depth_pixels)memset(model_depth_pixels,0,model_depth_count*sizeof *model_depth_pixels);
        model_depth_stamp=1;
    }
#endif
}
void gpu_model_depth_configure(int enabled) {
    model_depth_enabled=!!enabled;gpu_model_depth_barrier();
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
    static int registered;
    if(enabled&&!registered){atexit(model_depth_stats);registered=1;}
#endif
}
static int fifo_n, fifo_need;
static int in_vram_write;
static int vw_x, vw_y, vw_w, vw_h, vw_cx, vw_cy;
static int in_vram_read;
static int vr_x, vr_y, vr_w, vr_h, vr_cx, vr_cy;
static int in_polyline;

int gpu_frames;
int gpu_prim_log;
uint32_t gpu_ll_node;

/* A2_XFERLOG=N: log VRAM transfers (A0/C0/80/02) from frame N for 600 ops */
static int xferlog_from = -2, xferlog_left;
static int xferlog_armed(void) {
    if (xferlog_from == -2) {
        const char *e = getenv("A2_XFERLOG");
        xferlog_from = e ? atoi(e) : -1;
        e = getenv("A2_XFERMAX");           /* debug: raise the line cap */
        xferlog_left = e ? atoi(e) : 4000;
    }
    if (xferlog_from < 0 || gpu_frames < xferlog_from) return 0;
    return xferlog_left-- > 0 ? 1 : 0;
}

/* A2_PLANLOG=N: log game-side planned uploads (LoadImage & co; hooks in
 * gen/) from frame N.  Debug only. */
static int planlog_from = -2;
static int planlog_armed(void) {
    if (planlog_from == -2) {
        const char *e = getenv("A2_PLANLOG");
        planlog_from = e ? atoi(e) : -1;
    }
    return planlog_from >= 0 && gpu_frames >= planlog_from;
}
void a2_plan_rect(const char *tag, uint32_t rect, uint32_t src, uint32_t extra)
{
    if (!planlog_armed()) return;
    fprintf(stderr, "plan@%d: %s rect=%d,%d %dx%d src=%08X x=%08X\n",
            gpu_frames, tag,
            (int16_t)lh_(rect), (int16_t)lh_(rect + 2),
            (int16_t)lh_(rect + 4), (int16_t)lh_(rect + 6), src, extra);
}

/* ---------- raster helpers ---------- */
static inline uint16_t *vram_px(int x, int y) {
    return &GPU_VRAM[(y & 511) * 1024 + (x & 1023)];
}


static inline int sext11(uint32_t v) { return ((int32_t)(v << 21)) >> 21; }

typedef struct { int x, y, r, gr, b, u, v; } Vtx;

static uint32_t cur_clut, cur_tpage;
#ifdef A2_NATIVE_MESH
static int mesh_sample_direct,mesh_sample_x,mesh_sample_y;
#endif
#ifdef A2_GPU_RECT_TEST
static int gpu_rect_test_reference;
static unsigned long gpu_rect_test_samples;
#endif

static inline uint16_t sample_tex(int u, int v) {
#ifdef A2_GPU_RECT_TEST
    gpu_rect_test_samples++;
#endif
    int tpx = (cur_tpage & 0xF) * 64, tpy = ((cur_tpage >> 4) & 1) * 256;
    int mode = (cur_tpage >> 7) & 3;
#ifdef A2_NATIVE_MESH
    if(a2_mesh_live_enabled)mesh_sample_direct=0;
#endif
    u &= 255; v &= 255;
    if (g.texwin) {                   /* GP0(E2) texture window repeat */
        int mw = (g.texwin & 0x1F) * 8, mh = ((g.texwin >> 5) & 0x1F) * 8;
        int ox = ((g.texwin >> 10) & 0x1F) * 8, oy = ((g.texwin >> 15) & 0x1F) * 8;
        u = (u & ~mw) | (ox & mw);
        v = (v & ~mh) | (oy & mh);
    }
    if (mode == 0) {                  /* 4bpp */
        uint16_t w = *vram_px(tpx + u / 4, tpy + v);
        int idx = (w >> ((u & 3) * 4)) & 0xF;
        return *vram_px((cur_clut & 0x3F) * 16 + idx, (cur_clut >> 6) & 511);
    }
    if (mode == 1) {                  /* 8bpp */
        uint16_t w = *vram_px(tpx + u / 2, tpy + v);
        int idx = (w >> ((u & 1) * 8)) & 0xFF;
        return *vram_px((cur_clut & 0x3F) * 16 + idx, (cur_clut >> 6) & 511);
    }
#ifdef A2_NATIVE_MESH
    if(a2_mesh_live_enabled){mesh_sample_direct=1;mesh_sample_x=(tpx+u)&1023;mesh_sample_y=(tpy+v)&511;}
#endif
    return *vram_px(tpx + u, tpy + v);  /* 15bpp */
}

/* Internal-resolution shadow framebuffer (A2_IRSCALE = 1|2|3|4, default 3).
 * All rasterization additionally runs on an IRx fine grid into SHADOW;
 * VRAM stays the 1x-authoritative surface for game logic (texture
 * sampling, readbacks, feedback effects).  present() displays SHADOW. */
#include "display_color.h"
static uint16_t *SHADOW;
/* Optional8bit display plane. SHADOW remains the exact legacy555 surface. */
static uint32_t *SHADOW_RGB;
static int display_color_requested(void) {
    const char *e=getenv("A2_COLOR_PRECISION");return e&&atoi(e)!=0;
}
static int IR, IR_W, IR_H;
#ifdef A2_GPU_FINE
#include "gpu_fine.h"
#include <unistd.h>
static A2FineGpu *fine_gpu;
static int fine_gpu_pending,fine_gpu_requested=-1,fine_gpu_failed;
static uint64_t fine_gpu_attempts,fine_gpu_fallbacks[4],fine_gpu_bbox_pixels,fine_gpu_depth_counts[2],fine_gpu_depth_bbox[2];
static int fine_gpu_wanted(void) {
    if(fine_gpu_requested<0){const char *v=getenv("A2_GPU_FINE");fine_gpu_requested=v&&!strcmp(v,"1");}
    return fine_gpu_requested&&!fine_gpu_failed;
}
static void fine_gpu_sync(void) {
    if(!fine_gpu_pending)return;
    char error[1024];
    if(!a2_fine_gpu_sync(fine_gpu,error,sizeof error)) {
        fine_gpu_pending=0;fine_gpu_failed=1; /* Cleanup must not retry failed work. */
        fprintf(stderr,"fine-gpu: ordered raster failed: %s\n",error);exit(2);
    }
    fine_gpu_pending=0;
}
static void fine_gpu_close(void) {
    if(!fine_gpu)return;
    fine_gpu_sync();
    if(getenv("A2_GPU_FINE_PROFILE")) {
        A2FineGpuStats x=a2_fine_gpu_stats(fine_gpu);
        fprintf(stderr,"fine-gpu-stat: triangles=%llu submissions=%llu waits=%llu texture_requests=%llu texture_hits=%llu texture_bytes=%llu allocations=%llu capacity=%llu prepare_ms=%.3f encode_ms=%.3f wait_ms=%.3f gpu_ms=%.3f peak_pool=%llu\n",
            (unsigned long long)x.triangles,(unsigned long long)x.submissions,(unsigned long long)x.waits,
            (unsigned long long)x.texture_requests,(unsigned long long)x.texture_hits,(unsigned long long)x.texture_uploaded_bytes,
            (unsigned long long)x.buffer_allocations,(unsigned long long)x.capacity_rejections,
            x.prepare_ms,x.encode_ms,x.wait_ms,x.gpu_ms,(unsigned long long)x.peak_texture_pool_bytes);
        fprintf(stderr,"fine-gpu-admission: attempts=%llu mesh=%llu depth=%llu shading=%llu capacity=%llu accepted_bbox_pixels=%llu\n",
            (unsigned long long)fine_gpu_attempts,(unsigned long long)fine_gpu_fallbacks[0],
            (unsigned long long)fine_gpu_fallbacks[1],(unsigned long long)fine_gpu_fallbacks[2],
            (unsigned long long)fine_gpu_fallbacks[3],(unsigned long long)fine_gpu_bbox_pixels);
    }
    if(getenv("A2_GPU_FINE_PROFILE"))fprintf(stderr,"fine-gpu-depth: planes=%llu bounds=%llu plane_bbox=%llu bounds_bbox=%llu\n",(unsigned long long)fine_gpu_depth_counts[0],(unsigned long long)fine_gpu_depth_counts[1],(unsigned long long)fine_gpu_depth_bbox[0],(unsigned long long)fine_gpu_depth_bbox[1]);
    a2_fine_gpu_destroy(fine_gpu);fine_gpu=NULL;
}
static void fine_gpu_start(void) {
    if(fine_gpu||!fine_gpu_wanted()||IR<2||!SHADOW||!SHADOW_RGB)return;
    char error[1024];fine_gpu=a2_fine_gpu_create(IR_W,IR_H,SHADOW,SHADOW_RGB,error,sizeof error);
    if(!fine_gpu){fine_gpu_failed=1;fprintf(stderr,"fine-gpu: using CPU raster: %s\n",error);return;}
    static int registered;if(!registered){atexit(fine_gpu_close);registered=1;}
    fprintf(stderr,"fine-gpu: ordered Metal raster IR=%d surface=%dx%d\n",IR,IR_W,IR_H);
}
static void fine_gpu_written(int x,int y,int w,int h) {
    if(fine_gpu)a2_fine_gpu_written(fine_gpu,x,y,w,h);
}
static void *fine_surface_alloc(size_t count,size_t unit) {
    if(fine_gpu_wanted()) {
        long page=sysconf(_SC_PAGESIZE);void *p=NULL;
        if(page<=0||count>SIZE_MAX/unit||posix_memalign(&p,(size_t)page,count*unit))return NULL;
        memset(p,0,count*unit);return p;
    }
    return calloc(count,unit);
}
#else
static void fine_gpu_sync(void) {}
static void fine_gpu_close(void) {}
static void fine_gpu_written(int x,int y,int w,int h){(void)x;(void)y;(void)w;(void)h;}
static void *fine_surface_alloc(size_t count,size_t unit){return calloc(count,unit);}
#endif

static int ir_surface_enabled(int scale) {
#ifdef A2_HUD_PRESENT
    (void)scale;
    return SHADOW!=NULL;
#else
    return scale>1;
#endif
}
static int ir_init(void) {
    if (IR) return IR;
    /* default 3x (960x648): visibly sharper than 2x and the software
     * rasterizer still holds a steady 63 vblank/s.  4x (1280x864) is
     * available but halves the wall framerate on this machine, which
     * drags music/gameplay — so it is opt-in, not the default. */
    const char *e = getenv("A2_IRSCALE");
    IR = e ? atoi(e) : 3;
    if (IR >= 4) IR = 4;
    else if (IR == 3) IR = 3;
    else if (IR == 2) IR = 2;
    else IR = 1;
    IR_W = 1024 * IR; IR_H = 512 * IR;
    if (IR > 1
#ifdef A2_HUD_PRESENT
        || IR == 1
#endif
    ) {
        SHADOW = fine_surface_alloc((size_t)IR_W * IR_H, 2);
        if (!SHADOW) {IR = 1;IR_W=1024;IR_H=512;}
#ifdef A2_HUD_PRESENT
        else for(int y=0;y<512;y++)for(int x=0;x<1024;x++)
            for(int oy=0;oy<IR;oy++)for(int ox=0;ox<IR;ox++)
                SHADOW[(size_t)(y*IR+oy)*IR_W+x*IR+ox]=GPU_VRAM[y*1024+x];
#endif
    }
    if(SHADOW && IR>1 && display_color_requested()) {
        size_t count=(size_t)IR_W*IR_H;
        SHADOW_RGB=fine_surface_alloc(count,sizeof *SHADOW_RGB);
        if(SHADOW_RGB)for(size_t i=0;i<count;i++)SHADOW_RGB[i]=display_from_555(SHADOW[i]);
        else fprintf(stderr,"GPU: cannot allocate full-color display; using RGB555.\n");
    }
    #ifdef A2_WORLD_PRECISION
    world_precision_raster_scale=world_raster_enabled?IR:0;
    #endif
    return IR;
}
int gpu_ir(void) { return ir_init(); }
#ifdef A2_WORLD_PRECISION
void gpu_set_world_raster(int enabled) {
    world_raster_enabled=enabled!=0;
    world_precision_raster_scale=world_raster_enabled?ir_init():0;
}
#endif

/* Runtime IR switch: seed the new fine surface from authoritative VRAM.
 * Cached/uploaded display content may not be redrawn after a settings change. */
void gpu_set_ir(int n) {
    if (n < 1) n = 1;
    if (n > 4) n = 4;
    if (ir_init() == n) return;
    int next_w = 1024 * n, next_h = 512 * n;
    uint16_t *next_shadow = NULL;
    if (n > 1
#ifdef A2_HUD_PRESENT
        || n == 1
#endif
    ) {
        next_shadow = fine_surface_alloc((size_t)next_w * next_h, 2);
        if (!next_shadow) {
            fprintf(stderr, "GPU: cannot allocate IR %dx surface; keeping IR %dx.\n", n, IR);
            return;
        }
        for (int y = 0; y < 512; y++)
            for (int x = 0; x < 1024; x++) {
                uint16_t px = GPU_VRAM[y * 1024 + x];
                for (int oy = 0; oy < n; oy++)
                    for (int ox = 0; ox < n; ox++)
                        next_shadow[(size_t)(y * n + oy) * next_w + x * n + ox] = px;
            }
    }
    uint32_t *next_rgb=NULL;
    if(n>1 && display_color_requested()) {
        size_t count=(size_t)next_w*next_h;
        next_rgb=fine_surface_alloc(count,sizeof *next_rgb);
        if(!next_rgb) {
            free(next_shadow);
            fprintf(stderr,"GPU: cannot allocate IR %dx full-color surface; keeping IR %dx.\n",n,IR);
            return;
        }
        for(size_t i=0;i<count;i++)next_rgb[i]=display_from_555(next_shadow[i]);
    }
    gpu_model_depth_barrier();
#ifdef A2_NATIVE_MESH
    a2_mesh_live_reset();
#endif
    fine_gpu_close(); /* Metal borrows the old allocations; drain before free. */
    free(SHADOW_RGB);SHADOW_RGB=next_rgb;
    free(SHADOW);
    SHADOW = next_shadow;
    IR = n;
    IR_W = next_w; IR_H = next_h;
#ifdef A2_WORLD_PRECISION
    world_precision_raster_scale=world_raster_enabled?IR:0;
#endif
#ifdef A2_CINEMA_EXPANSION
    cinema_invalidate();
#endif
}
/* wrap to the shadow extent — general (IR need not be a power of two,
 * so no bit-mask); the branch is skipped for in-range coords, which is
 * the common case since fine writes are clipped to the draw area */
static inline uint16_t *shadow_px(int fx, int fy) {
    if ((unsigned)fx >= (unsigned)IR_W) { fx %= IR_W; if (fx < 0) fx += IR_W; }
    if ((unsigned)fy >= (unsigned)IR_H) { fy %= IR_H; if (fy < 0) fy += IR_H; }
    return &SHADOW[(size_t)fy * IR_W + fx];
}
/* Fill one or two contiguous spans per wrapped row. Mesh observers need the
 * original per-sample notification order and retain the generic writer. */
static int shadow_fill_rows(int x,int y,int width,int height,uint16_t value,uint32_t rgb) {
#ifdef A2_GPU_FILL_ROWS_TEST
    if(fill_rows_reference)return 0;
#endif
#ifdef A2_NATIVE_MESH
    if(a2_mesh_live_writes_watched)return 0;
#endif
#ifdef A2_GPU_FILL_ROWS_TEST
    fill_rows_uses++;
#endif
    for(int j=0;j<height;j++) {
        int row=(y+j)%IR_H,left=width,start=x;
        while(left>0) {
            int n=IR_W-start;if(n>left)n=left;
            size_t offset=(size_t)row*IR_W+start;
            uint16_t *dst=SHADOW+offset;
            for(int i=0;i<n;i++)dst[i]=value;
            if(SHADOW_RGB) {
                uint32_t *color=SHADOW_RGB+offset;
                for(int i=0;i<n;i++)color[i]=rgb;
            }
            left-=n;start=0;
        }
    }
    return 1;
}
uint16_t gpu_display_px(int fx, int fy) {      /* present() fetch */
    fine_gpu_sync();
    if (ir_surface_enabled(ir_init())) {
        uint16_t value=*shadow_px(fx,fy);
#ifdef A2_NATIVE_MESH
        return a2_mesh_live_read(fx,fy,value);
#else
        return value;
#endif
    }
    return GPU_VRAM[(size_t)(fy & 511) * 1024 + (fx & 1023)];
}
/* Read-only row, valid until the next IR change. X remains caller-bounded to
 * [0,1024*gpu_ir()); vertical wrapping matches gpu_display_px exactly. */
const uint16_t *gpu_display_row(int fy) {
    fine_gpu_sync();
    if (ir_surface_enabled(ir_init())) {
        fy %= IR_H;
        if (fy < 0) fy += IR_H;
        const uint16_t *original=SHADOW + (size_t)fy * IR_W;
#ifdef A2_NATIVE_MESH
        return a2_mesh_live_row(fy,original,(size_t)IR_W);
#else
        return original;
#endif
    }
    return GPU_VRAM + (size_t)(fy & 511) * 1024;
}

/* Nullable row lets every existing555 consumer retain its contract. The
 * mesh flag includes retained published pages after a user toggles it off. */
const uint32_t *gpu_display_argb_row(int fy) {
    fine_gpu_sync();
    (void)ir_init();
    if(!SHADOW_RGB)return NULL;
#ifdef A2_NATIVE_MESH
    if(a2_mesh_live_enabled)return NULL;
#endif
    fy%=IR_H;if(fy<0)fy+=IR_H;
    return SHADOW_RGB+(size_t)fy*IR_W;
}

static inline uint16_t blend(uint16_t bg, int r, int grn, int b, int mode) {
    int br = (bg & 31) << 3, bgc = ((bg >> 5) & 31) << 3, bb = ((bg >> 10) & 31) << 3;
    switch (mode) {
    case 0: r = (br + r) / 2; grn = (bgc + grn) / 2; b = (bb + b) / 2; break;
    case 1: r = br + r; grn = bgc + grn; b = bb + b; break;
    case 2: r = br - r; grn = bgc - grn; b = bb - b; break;
    default: r = br + r / 4; grn = bgc + grn / 4; b = bb + b / 4; break;
    }
    if (r < 0) r = 0; if (r > 255) r = 255;
    if (grn < 0) grn = 0; if (grn > 255) grn = 255;
    if (b < 0) b = 0; if (b > 255) b = 255;
    return (uint16_t)((r >> 3) | ((grn >> 3) << 5) | ((b >> 3) << 10));
}

/* A2_PXWATCH=x,y[,frame] debug: log every write to one VRAM pixel */
static int wpx = -3, wpy, wpf;
int gpu_cur_cmd;
static void pxwatch_init(void) {
    const char *e = getenv("A2_PXWATCH");
    wpx = -1;
    if (e) {
        wpf = 0;
        if (sscanf(e, "%d,%d,%d", &wpx, &wpy, &wpf) < 2) wpx = -1;
    }
}

/* Framebuffer feedback has two consumers: native game logic reads VRAM,
 * presentation reads the chosen image, including copied replacement pixels.
 * Ordinary uploaded 15-bit textures have identical native/display texels. */
#ifdef A2_NATIVE_MESH
static inline uint16_t mesh_display_texel(int x,int y,uint16_t native){
    if(!a2_mesh_live_enabled||!SHADOW)return native;
    int fx=(x&1023)*IR+IR/2,fy=(y&511)*IR+IR/2;
    return a2_mesh_live_read(fx,fy,SHADOW[(size_t)fy*IR_W+fx]);
}
#endif
static inline uint16_t sample_tex_present(int u,int v){
    uint16_t value=sample_tex(u,v);
#ifdef A2_NATIVE_MESH
    if(mesh_sample_direct)value=mesh_display_texel(mesh_sample_x,mesh_sample_y,value);
#endif
    return value;
}

static inline void put_px(int x, int y, int r, int grn, int b,
                          int semi, int tex, uint16_t texel) {
    if (wpx == -3) pxwatch_init();
    if (wpx >= 0 && x == wpx && y == wpy && (!wpf || (gpu_frames >= wpf &&
                                                      gpu_frames < wpf + 6))) {
        fprintf(stderr, "pxw: f=%d put(%d,%d) c=%02X tex=%d semi=%d "
                "texel=%04X rgb=%02X,%02X,%02X tpage=%03X clut=%04X "
                "clip=%d\n", gpu_frames, x, y, gpu_cur_cmd, tex, semi,
                texel, r, grn, b, (unsigned)(cur_tpage & 0xFFF),
                (unsigned)cur_clut,
                (x < g.dax1 || x > g.dax2 || y < g.day1 || y > g.day2));
    }
    if (x < g.dax1 || x > g.dax2 || y < g.day1 || y > g.day2) return;
#ifdef A2_HUD_PRESENT
    if(ir1_mirror){
        uint16_t dt=texel;
#ifdef A2_NATIVE_MESH
        if(tex&&mesh_sample_direct)dt=mesh_display_texel(mesh_sample_x,mesh_sample_y,dt);
#endif
        if(!tex||dt){
            int dr=r,dg=grn,db=b,ds=semi;
            if(tex){
                dr=(((dt&31)<<3)*dr)>>7;dg=((((dt>>5)&31)<<3)*dg)>>7;db=((((dt>>10)&31)<<3)*db)>>7;
                if(dr>255)dr=255;if(dg>255)dg=255;if(db>255)db=255;
                if(ds&&!(dt&0x8000))ds=0;
            }
            uint16_t msb=tex?(dt&0x8000):0;
#ifdef A2_NATIVE_MESH
            if(a2_mesh_live_active&&x>=a2_mesh_live_x0&&x<a2_mesh_live_x1&&y>=a2_mesh_live_y0&&y<a2_mesh_live_y1){
                float z;A2CompositeKind kind=mesh_kind_at(x,y,&z);
                a2_mesh_live_pixel(x,y,(A2CompositePixel){kind,z,(uint8_t)dr,(uint8_t)dg,(uint8_t)db,
                    (uint8_t)ds,(uint8_t)tex,(uint8_t)((cur_tpage>>5)&3),dt});
            }
            if(mesh_pixel_kind!=A2_COMPOSITE_OWNED)
#endif
            {
                uint16_t *display=shadow_px(x,y);
                if(ds)*display=blend(*display,dr,dg,db,(cur_tpage>>5)&3)|msb;
                else *display=(uint16_t)((dr>>3)|((dg>>3)<<5)|((db>>3)<<10))|msb;
            }
        }
    }
#endif
    if (tex) {
        if (texel == 0) return;       /* fully transparent texel */
        int tr = (texel & 31) << 3, tg = ((texel >> 5) & 31) << 3,
            tb = ((texel >> 10) & 31) << 3;
        r = (tr * r) >> 7; grn = (tg * grn) >> 7; b = (tb * b) >> 7;
        if (r > 255) r = 255; if (grn > 255) grn = 255; if (b > 255) b = 255;
        if (semi && !(texel & 0x8000)) semi = 0;   /* STP bit gates blending */
    }
    uint16_t *px = vram_px(x, y);
    /* real GPU writes the texel STP bit into the framebuffer mask bit */
    uint16_t msb = tex ? (texel & 0x8000) : 0;
    if (semi) *px = blend(*px, r, grn, b, (cur_tpage >> 5) & 3) | msb;
    else *px = (uint16_t)((r >> 3) | ((grn >> 3) << 5) | ((b >> 3) << 10)) | msb;
}

/* A2_FILTER=1 (default OFF): bilinear texture sampling for the fine
 * pass. u_fp/v_fp are 24.8 fixed-point texcoords. Transparent texels
 * (0) are skipped and weights renormalized so sprite/cutout edges
 * don't bleed black; STP comes from the nearest tap. The 1x VRAM pass
 * keeps exact nearest sampling for game feedback effects.
 * Polygon samples stay inside the complete primitive's inclusive UV
 * range before texture-window remapping. This keeps the half-texel
 * footprint from reading unrelated atlas entries across its border. */
static int filter_v = -1;
/* Full int32 bounds make inactive sampling an identity without testing an
 * active flag at every fine pixel. GP0 entry/exit restores this neutral range. */
static int fine_uv_low[2]={INT32_MIN,INT32_MIN},fine_uv_high[2]={INT32_MAX,INT32_MAX};
static void fine_uv_reset(void) {
    fine_uv_low[0]=fine_uv_low[1]=INT32_MIN;
    fine_uv_high[0]=fine_uv_high[1]=INT32_MAX;
}
static void fine_uv_polygon(const Vtx *v,int count) {
    int lo[2]={v[0].u,v[0].v},hi[2]={v[0].u,v[0].v};
    for(int i=1;i<count;i++) {
        if(v[i].u<lo[0])lo[0]=v[i].u;if(v[i].u>hi[0])hi[0]=v[i].u;
        if(v[i].v<lo[1])lo[1]=v[i].v;if(v[i].v>hi[1])hi[1]=v[i].v;
    }
    for(unsigned axis=0;axis<2;axis++) {
        fine_uv_low[axis]=lo[axis]*256;fine_uv_high[axis]=hi[axis]*256;
    }
}
static inline int32_t fine_uv_coordinate(int32_t value,unsigned axis) {
    if(value<fine_uv_low[axis])value=fine_uv_low[axis];
    if(value>fine_uv_high[axis])value=fine_uv_high[axis];
    return value;
}
static int fine_filter_debug=-1;
static void fine_filter_debug_init(void){if(fine_filter_debug<0)fine_filter_debug=getenv("A2_FILTDBG")?30:0;}
static int filter_on(void) {
    if (filter_v < 0) {
        const char *e = getenv("A2_FILTER");
        filter_v = e ? atoi(e) != 0 : 0;
    }
    return filter_v;
}
void gpu_set_filter(int on) {
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
    model_minify_base.word=model_minify_write=model_minify_pair=0;model_minify_tracking=0;
#endif
    filter_v = on ? 1 : 0;
}
/* Same four integer weights for cached and uncached footprints. */
#if defined(__GNUC__)
__attribute__((always_inline))
#endif
static inline uint16_t filter_footprint(uint16_t t00,uint16_t t10,uint16_t t01,uint16_t t11,int fu,int fv) {
    uint16_t near=t00;
    int w00 = (256 - fu) * (256 - fv), w10 = fu * (256 - fv),
        w01 = (256 - fu) * fv,         w11 = fu * fv;
    if (!t00) w00 = 0;
    if (!t10) w10 = 0;
    if (!t01) w01 = 0;
    if (!t11) w11 = 0;
    int wsum = w00 + w10 + w01 + w11;
    if (!wsum) return near;
    /* Three 21-bit lanes hold weighted 5-bit RGB sums without carries:
     * each sum is at most 31*65536. The multiply spreads the original
     * 5-bit channels, then a single weighted multiply handles all three. */
    const uint64_t spread=UINT64_C(0x100010001);
    const uint64_t lanes=UINT64_C(31)|(UINT64_C(31)<<21)|(UINT64_C(31)<<42);
    uint64_t sums=(((uint64_t)t00*spread)&lanes)*(unsigned)w00
                 +(((uint64_t)t10*spread)&lanes)*(unsigned)w10
                 +(((uint64_t)t01*spread)&lanes)*(unsigned)w01
                 +(((uint64_t)t11*spread)&lanes)*(unsigned)w11;
    unsigned r=(unsigned)(sums&0x1fffff),g=(unsigned)((sums>>21)&0x1fffff),b=(unsigned)(sums>>42);
    /* Fully covered footprints have exactly 65536 weight. Positive RGB sums
     * make shifts bit-identical to division, without three variable divides. */
    if(wsum==65536) {r>>=16;g>>=16;b>>=16;}
    else {r/=(unsigned)wsum;g/=(unsigned)wsum;b/=(unsigned)wsum;}
    uint16_t px = (uint16_t)(r | (g << 5) | (b << 10)) | (near & 0x8000);
    return px ? px : near;             /* never collapse to transparent */
}

/* Keep the fine sampler inside the polygon loop: an out-of-line call spills
 * its UV/raster registers for every high-resolution pixel. */
#if defined(__GNUC__)
__attribute__((always_inline))
#endif
#ifdef A2_WORLD_PRECISION
/* Ground-shadow decals: the authored 4bpp ramp has seven octagonal steps that
 * read as a faceted blob once upscaled. Sample its luminance (transparent=0;
 * subtractive blending makes 0 an identity) with a 3x3 tent of bilinear taps
 * and fade to zero at the primitive's UV rectangle. u_fp/v_fp are texel-centre
 * 8.8 coordinates, as passed to the filtered samplers. */
static int soft_shadow_active;
static void soft_shadow_tap(float x,float y,float weight,float sum[3]) {
    int x0=(int)floorf(x),y0=(int)floorf(y);float fx=x-x0,fy=y-y0;
    for(int j=0;j<2;j++)for(int i=0;i<2;i++) {
        int tu=x0+i,tv=y0+j;
        if(tu*256<fine_uv_low[0]||tu*256>fine_uv_high[0]||tv*256<fine_uv_low[1]||tv*256>fine_uv_high[1])continue;
        uint16_t t=sample_tex(tu,tv);if(!t)continue;
        float w=weight*(i?fx:1-fx)*(j?fy:1-fy);
        sum[0]+=w*(t&31);sum[1]+=w*((t>>5)&31);sum[2]+=w*((t>>10)&31);
    }
}
static uint16_t soft_shadow_texel(int u_fp,int v_fp) {
    float x=u_fp/256.0f,y=v_fp/256.0f,sum[3]={0,0,0};
    static const float offset[3]={-0.75f,0,0.75f},weight[3]={0.25f,0.5f,0.25f};
    for(int j=0;j<3;j++)for(int i=0;i<3;i++)soft_shadow_tap(x+offset[i],y+offset[j],weight[i]*weight[j],sum);
    float edge=fminf(fminf(x-fine_uv_low[0]/256.0f+0.5f,fine_uv_high[0]/256.0f+0.5f-x),
                     fminf(y-fine_uv_low[1]/256.0f+0.5f,fine_uv_high[1]/256.0f+0.5f-y));
    if(edge<=0)return 0;if(edge<1)for(int c=0;c<3;c++)sum[c]*=edge;
    int r=(int)(sum[0]+0.5f),g=(int)(sum[1]+0.5f),b=(int)(sum[2]+0.5f);
    if(!(r|g|b))return 0;
    return (uint16_t)(r|(g<<5)|(b<<10)|0x8000);
}
/* Replacement is keyed by the shadow textures' exact 24x24 content (round
 * and rounded-square ramps), so every draw path of the same texture is
 * replaced, with or without physical provenance. */
#define SHADOW_TEXTURE_ROUND  UINT64_C(0xf1c40a3ac4ffedff)
#define SHADOW_TEXTURE_SQUARE UINT64_C(0x6b6859f612b0e435)
static uint64_t shadow_texture_hash(const Vtx *v,int count) {
    int u0=v[0].u,u1=v[0].u,v0=v[0].v,v1=v[0].v;
    for(int i=1;i<count;i++){if(v[i].u<u0)u0=v[i].u;if(v[i].u>u1)u1=v[i].u;if(v[i].v<v0)v0=v[i].v;if(v[i].v>v1)v1=v[i].v;}
    if(u1-u0!=23||v1-v0!=23)return 0;
    uint64_t hash=UINT64_C(0xcbf29ce484222325);
    for(int y=v0;y<=v1;y++)for(int x=u0;x<=u1;x++){hash^=sample_tex(x,y);hash*=UINT64_C(0x100000001b3);}
    return hash;
}
static int shadow_texture_replaced(const Vtx *v,int count) {
    uint64_t hash=shadow_texture_hash(v,count);
    return hash&&(hash==SHADOW_TEXTURE_ROUND||hash==SHADOW_TEXTURE_SQUARE);
}
#else
static const int soft_shadow_active=0;
static inline uint16_t soft_shadow_texel(int u_fp,int v_fp){(void)u_fp;(void)v_fp;return 0;}
#endif
static inline uint16_t sample_tex_fine(int32_t u_fp, int32_t v_fp) {
    u_fp=fine_uv_coordinate(u_fp,0);v_fp=fine_uv_coordinate(v_fp,1);
    { fine_filter_debug_init();
      if (fine_filter_debug > 0) { fine_filter_debug--;
          fprintf(stderr, "filt: u_fp=%d v_fp=%d t00=%04X near-guess=%04X "
                  "tpage=%03X clut=%04X\n", u_fp, v_fp,
                  sample_tex(u_fp >> 8, v_fp >> 8),
                  sample_tex((u_fp + 128) >> 8, (v_fp + 128) >> 8),
                  cur_tpage & 0xFFF, cur_clut); } }
    int u = u_fp >> 8, v = v_fp >> 8;
    int fu = u_fp & 0xFF, fv = v_fp & 0xFF;
    unsigned u0=(unsigned)u&255,u1=((unsigned)u+1)&255;
    unsigned v0=(unsigned)v&255,v1=((unsigned)v+1)&255;
    /* Put the nearest corner first. Reflecting the fractions with its axes
     * only permutes the same four integer weights; STP and coverage are exact.
     * Scalars keep the hot footprint in registers instead of indexed arrays. */
    if(fu>=128) {unsigned t=u0;u0=u1;u1=t;fu=256-fu;}
    if(fv>=128) {unsigned t=v0;v0=v1;v1=t;fv=256-fv;}
    if(g.texwin) {
        unsigned mw=(g.texwin&31)*8,mh=((g.texwin>>5)&31)*8;
        unsigned ox=((g.texwin>>10)&31)*8,oy=((g.texwin>>15)&31)*8;
        u0=(u0&~mw)|(ox&mw);u1=(u1&~mw)|(ox&mw);
        v0=(v0&~mh)|(oy&mh);v1=(v1&~mh)|(oy&mh);
    }
    unsigned page_x=(cur_tpage&15)*64,page_y=((cur_tpage>>4)&1)*256;
    unsigned mode=(cur_tpage>>7)&3;
    const uint16_t *row0=GPU_VRAM+((page_y+v0)&511)*1024;
    const uint16_t *row1=GPU_VRAM+((page_y+v1)&511)*1024;
    uint16_t t00,t10,t01,t11;
#ifdef A2_GPU_RECT_TEST
    gpu_rect_test_samples++;
#endif
    if(mode<2) {
        unsigned packed_shift=mode?1:2,bits=mode?8:4;
        const uint16_t *palette=GPU_VRAM+((cur_clut>>6)&511)*1024;
        unsigned clut_x=(cur_clut&63)*16,index_mask=mode?255:15;
        unsigned x0=(page_x+(u0>>packed_shift))&1023,x1=(page_x+(u1>>packed_shift))&1023;
        unsigned shift0=(u0&((1u<<packed_shift)-1))*bits,shift1=(u1&((1u<<packed_shift)-1))*bits;
        t00=palette[(clut_x+((row0[x0]>>shift0)&index_mask))&1023];
        if(!t00)return 0;
        t10=palette[(clut_x+((row0[x1]>>shift1)&index_mask))&1023];
        t01=palette[(clut_x+((row1[x0]>>shift0)&index_mask))&1023];
        t11=palette[(clut_x+((row1[x1]>>shift1)&index_mask))&1023];
    } else {
        unsigned x0=(page_x+u0)&1023,x1=(page_x+u1)&1023;
        t00=row0[x0];t10=row0[x1];t01=row1[x0];t11=row1[x1];
#ifdef A2_NATIVE_MESH
        t00=mesh_display_texel(x0,page_y+v0,t00);t10=mesh_display_texel(x1,page_y+v0,t10);
        t01=mesh_display_texel(x0,page_y+v1,t01);t11=mesh_display_texel(x1,page_y+v1,t11);
#endif
        if(!t00)return 0;
    }
#ifdef A2_GPU_RECT_TEST
    gpu_rect_test_samples+=3;
#endif
    uint16_t near=t00;
    if(t00==t10 && t00==t01 && t00==t11)return near;
    return filter_footprint(t00,t10,t01,t11,fu,fv);
}

/* VRAM is stable after this triangle's authoritative native pass; the fine
 * pass writes only SHADOW. Reuse four-texel footprints while magnifying, and
 * discard every entry before the next triangle can write native VRAM. */
typedef struct {
    unsigned key,kind;
    uint16_t texels[4];
    uint64_t base,dx,dy,cross;
} FineTexCell;
typedef struct {FineTexCell cells[64];} FineTexCache;
/* A cache miss needs all four native taps, including transparent ones that
 * may become the nearest tap later. Share their window/page/palette address
 * work; each axis still wraps before applying the texture window. */
static void sample_tex_footprint(unsigned u,unsigned v,uint16_t texels[4]) {
    unsigned u0=u&255,u1=(u+1)&255,v0=v&255,v1=(v+1)&255;
    if(g.texwin) {
        unsigned mw=(g.texwin&31)*8,mh=((g.texwin>>5)&31)*8;
        unsigned ox=((g.texwin>>10)&31)*8,oy=((g.texwin>>15)&31)*8;
        u0=(u0&~mw)|(ox&mw);u1=(u1&~mw)|(ox&mw);
        v0=(v0&~mh)|(oy&mh);v1=(v1&~mh)|(oy&mh);
    }
    unsigned page_x=(cur_tpage&15)*64,page_y=((cur_tpage>>4)&1)*256;
    unsigned mode=(cur_tpage>>7)&3;
    const uint16_t *row0=GPU_VRAM+((page_y+v0)&511)*1024;
    const uint16_t *row1=GPU_VRAM+((page_y+v1)&511)*1024;
#ifdef A2_GPU_RECT_TEST
    gpu_rect_test_samples+=4;
#endif
#ifdef A2_NATIVE_MESH
    if(a2_mesh_live_enabled)mesh_sample_direct=0;
#endif
    if(mode<2) {
        unsigned packed_shift=mode?1:2,bits=mode?8:4;
        const uint16_t *palette=GPU_VRAM+((cur_clut>>6)&511)*1024;
        unsigned clut_x=(cur_clut&63)*16,index_mask=mode?255:15;
        unsigned x0=(page_x+(u0>>packed_shift))&1023,x1=(page_x+(u1>>packed_shift))&1023;
        unsigned shift0=(u0&((1u<<packed_shift)-1))*bits,shift1=(u1&((1u<<packed_shift)-1))*bits;
        texels[0]=palette[(clut_x+((row0[x0]>>shift0)&index_mask))&1023];
        texels[1]=palette[(clut_x+((row0[x1]>>shift1)&index_mask))&1023];
        texels[2]=palette[(clut_x+((row1[x0]>>shift0)&index_mask))&1023];
        texels[3]=palette[(clut_x+((row1[x1]>>shift1)&index_mask))&1023];
    } else {
        unsigned x0=(page_x+u0)&1023,x1=(page_x+u1)&1023;
        texels[0]=row0[x0];texels[1]=row0[x1];texels[2]=row1[x0];texels[3]=row1[x1];
#ifdef A2_NATIVE_MESH
        /* Match the final scalar tap's bookkeeping. Published mesh feedback
         * takes the uncached sampler before reaching this helper. */
        if(a2_mesh_live_enabled){mesh_sample_direct=1;mesh_sample_x=(int)x1;mesh_sample_y=(int)((page_y+v1)&511);}
#endif
    }
}
#if defined(__GNUC__)
__attribute__((always_inline))
#endif
static inline uint16_t sample_tex_cached_impl(int32_t u_fp,int32_t v_fp,FineTexCache *cache,int stable) {
    (void)stable;
    u_fp=fine_uv_coordinate(u_fp,0);v_fp=fine_uv_coordinate(v_fp,1);
#ifdef A2_NATIVE_MESH
    /* Presentation feedback can change during the fine pass itself. */
    if(!stable&&a2_mesh_live_enabled&&((cur_tpage>>7)&3)>=2)return sample_tex_fine(u_fp,v_fp);
#endif
    unsigned u=(unsigned)(u_fp>>8)&255,v=(unsigned)(v_fp>>8)&255;
    unsigned key=u|(v<<8),slot=(u+17*v)&63;
    FineTexCell *cell=&cache->cells[slot];
    if(cell->key!=key) {
        cell->key=key;
        sample_tex_footprint(u,v,cell->texels);
        cell->kind=cell->texels[0]&&cell->texels[1]&&cell->texels[2]&&cell->texels[3];
        if(cell->texels[0]==cell->texels[1]&&cell->texels[0]==cell->texels[2]&&cell->texels[0]==cell->texels[3])cell->kind=2;
        if(cell->kind==1) {
            const uint64_t spread=UINT64_C(0x100010001);
            const uint64_t lanes=UINT64_C(31)|(UINT64_C(31)<<21)|(UINT64_C(31)<<42);
            uint64_t p0=((uint64_t)cell->texels[0]*spread)&lanes;
            uint64_t p1=((uint64_t)cell->texels[1]*spread)&lanes;
            uint64_t p2=((uint64_t)cell->texels[2]*spread)&lanes;
            uint64_t p3=((uint64_t)cell->texels[3]*spread)&lanes;
            cell->base=p0;cell->dx=p1-p0;cell->dy=p2-p0;cell->cross=p3-p1-p2+p0;
        }
    }
    int fu=u_fp&255,fv=v_fp&255;
    unsigned nearest=(fu>=128?1:0)|(fv>=128?2:0);
    uint16_t t00=cell->texels[nearest];if(!t00)return 0;
    if(cell->kind==2)return t00;
    if(cell->kind==1) {
        /* Unsigned modular arithmetic permits negative coefficient differences.
         * The polynomial equals the original positive four-weight sum; its
         * final three 21-bit lanes fit below bit63, including white/checkerboards. */
        uint64_t sums=(cell->base<<16)+((cell->dx*(unsigned)fu)<<8)
                     +((cell->dy<<8)+cell->cross*(unsigned)fu)*(unsigned)fv;
        uint16_t pixel=(uint16_t)(((sums>>16)&31)|((sums>>32)&0x3e0)|((sums>>48)&0x7c00))|(t00&0x8000);
        return pixel?pixel:t00;
    }
    uint16_t t10=cell->texels[nearest^1],t01=cell->texels[nearest^2],t11=cell->texels[nearest^3];
    if(t00==t10&&t00==t01&&t00==t11)return t00;
    if(fu>=128)fu=256-fu;if(fv>=128)fv=256-fv;
    return filter_footprint(t00,t10,t01,t11,fu,fv);
}
static inline uint16_t sample_tex_cached(int32_t u_fp,int32_t v_fp,FineTexCache *cache) {
    return sample_tex_cached_impl(u_fp,v_fp,cache,0);
}

#ifdef A2_NATIVE_MESH
/* Diagnostic only: actual covered OWNED fine samples, including samples which
 * never reach the ROI compositor. No packet role or pixel value is changed. */
static struct {
    unsigned initialized,enabled,lines,identity_lines;
    uint32_t first,frame,source,command;
    uint64_t pixels,outside,identity_misses,count,owner;
    int x,y,minx,miny,maxx,maxy,roi[4];
} mesh_coverage_trace;
static int mesh_coverage_tracing(void) {
    if(!mesh_coverage_trace.initialized) {
        mesh_coverage_trace.initialized=1;
        const char *e=getenv("A2_MESH_TRACE");
        if(e){mesh_coverage_trace.enabled=1;mesh_coverage_trace.first=(uint32_t)strtoul(e,NULL,10);}
    }
    return mesh_coverage_trace.enabled&&psx_frame_no>=mesh_coverage_trace.first;
}
static void mesh_coverage_flush(void) {
    if(!mesh_coverage_trace.count)return;
    if(mesh_coverage_trace.lines<256) {
        fprintf(stderr,"nativemesh-owned-outside: frame=%u src=%08x cmd=%08x owner=%llu xy=%d,%d bounds=%d,%d,%d,%d roi=%d,%d,%d,%d pixels=%llu\n",
            mesh_coverage_trace.frame,mesh_coverage_trace.source,mesh_coverage_trace.command,
            (unsigned long long)mesh_coverage_trace.owner,mesh_coverage_trace.x,mesh_coverage_trace.y,
            mesh_coverage_trace.minx,mesh_coverage_trace.miny,mesh_coverage_trace.maxx,mesh_coverage_trace.maxy,
            mesh_coverage_trace.roi[0],mesh_coverage_trace.roi[1],mesh_coverage_trace.roi[2],mesh_coverage_trace.roi[3],
            (unsigned long long)mesh_coverage_trace.count);
        if(++mesh_coverage_trace.lines==256)fputs("nativemesh-owned-outside-limit: details=256 cumulative_counters_continue=1\n",stderr);
    }
    mesh_coverage_trace.count=0;
}
static void mesh_coverage_pixel(int x,int y) {
    if(mesh_pixel_kind!=A2_COMPOSITE_OWNED||!mesh_pixel_owner||!mesh_coverage_tracing())return;
    ++mesh_coverage_trace.pixels;
    if(x>=a2_mesh_live_x0&&x<a2_mesh_live_x1&&y>=a2_mesh_live_y0&&y<a2_mesh_live_y1)return;
    ++mesh_coverage_trace.outside;
    if(!mesh_coverage_trace.count) {
        mesh_coverage_trace.frame=psx_frame_no;mesh_coverage_trace.source=fifo_source[0];mesh_coverage_trace.command=fifo[0];
        mesh_coverage_trace.owner=mesh_pixel_owner;mesh_coverage_trace.x=mesh_coverage_trace.minx=mesh_coverage_trace.maxx=x;
        mesh_coverage_trace.y=mesh_coverage_trace.miny=mesh_coverage_trace.maxy=y;
        mesh_coverage_trace.roi[0]=a2_mesh_live_x0;mesh_coverage_trace.roi[1]=a2_mesh_live_y0;
        mesh_coverage_trace.roi[2]=a2_mesh_live_x1;mesh_coverage_trace.roi[3]=a2_mesh_live_y1;
    }
    if(x<mesh_coverage_trace.minx)mesh_coverage_trace.minx=x;if(x>mesh_coverage_trace.maxx)mesh_coverage_trace.maxx=x;
    if(y<mesh_coverage_trace.miny)mesh_coverage_trace.miny=y;if(y>mesh_coverage_trace.maxy)mesh_coverage_trace.maxy=y;
    ++mesh_coverage_trace.count;
}
static void mesh_coverage_identity(const A2ActorPacket *consumed) {
    if(!a2_mesh_live_enabled||!mesh_coverage_tracing()||mesh_pixel_kind==A2_COMPOSITE_OWNED||
       (fifo[0]>>24)<0x20||(fifo[0]>>24)>=0x40)return;
    const A2ActorPacket *candidate=consumed;
    if(!candidate) {
        const A2ActorPacketOwner *owners[A2_ACTOR_PACKET_OWNER_LIMIT];
        size_t count=a2_native_actor_packets_owners_latest(owners,A2_ACTOR_PACKET_OWNER_LIMIT);
        for(size_t i=0;i<count&&!candidate;i++) {
            const A2ActorPacket *packets[A2_ACTOR_PACKET_LIMIT];
            size_t n=a2_native_actor_packets_owner_packets(owners[i]->handle,packets,A2_ACTOR_PACKET_LIMIT);
            for(size_t j=0;j<n;j++) {
                const A2ActorPacket *q=packets[j];
                if((fifo_source[0]&0x1fffffu)==q->command_address&&q->polygon_word_count==(unsigned)fifo_n&&
                   q->dma_word_count<14&&q->dma_base<=PSX_RAM_SIZE-4*(q->dma_word_count+1)&&
                   !memcmp(fifo,q->words+2,(size_t)fifo_n*4)&&
                   !memcmp(PSX_RAM+q->dma_base,q->words,4*(q->dma_word_count+1))) {candidate=q;break;}
            }
        }
    }
    if(!candidate)return;
    ++mesh_coverage_trace.identity_misses;
    if(mesh_coverage_trace.identity_lines++<128)fprintf(stderr,
        "nativemesh-owned-dispatch-miss: frame=%u src=%08x cmd=%08x owner=%llu token=%llu consumed=%d selected=%d active=%d kind=%u\n",
        psx_frame_no,fifo_source[0],fifo[0],(unsigned long long)candidate->owner_handle,
        (unsigned long long)fifo_mesh_token,consumed!=NULL,a2_mesh_live_owns(candidate->owner_handle),a2_mesh_live_active,(unsigned)mesh_pixel_kind);
}
#endif

/* Fine triangle spans are already clipped; keep their write pointer and
 * primitive blend mode outside the per-pixel address/bounds calculation. */
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
static int model_depth_sample(const uint16_t *pixel,int semi) {
#ifdef A2_MODEL_DEPTH_BOUNDS_TEST
    ++depth_bounds_sample_calls;
#endif
    /* No pixel in this pass can own depth until an opaque model sample
     * actually writes. Avoid touching the depth surface for earlier world
     * polygons and for draws after a bulk barrier. */
    if(!model_depth_plane_valid&&!model_depth_has_samples)return 1;
    if(!model_depth_pixels||model_depth_scale!=(unsigned)IR)return 1;
    size_t offset=(size_t)(pixel-SHADOW);
    int y=(int)(offset/(unsigned)IR_W),x=(int)(offset%(unsigned)IR_W);
    int page=y>=(int)(256*model_depth_scale)?256:0;
    int local_y=y-page*(int)model_depth_scale;
    if(x<0||x>=(int)(320*model_depth_scale)||local_y<0||local_y>=(int)(216*model_depth_scale))return 1;
    size_t index=(size_t)(local_y+(page?216*(int)model_depth_scale:0))*320*model_depth_scale+x;
    ModelDepthPixel *prior=&model_depth_pixels[index];
    if(!model_depth_plane_valid){prior->stamp=0;return 1;}
    if(model_depth_ground_shadow) {
        /* This is a physical source plane in the actor's exact camera,
         * independent of the retained shadow color/UV raster. A ground decal
         * never darkens a surface in front of its plane: models (the actor's
         * own boots) beyond a precision band, WORLD faces (walls, fences)
         * beyond the shadow's lift above uneven ground. It never occludes
         * and keeps the depth it darkens, so later faces still sort. */
        double z=model_shadow_inverse_z(x,y);
        if(z>0 && semi && prior->stamp==model_depth_stamp) {
            if(prior->owner==MODEL_DEPTH_WORLD_OWNER) {
                if(1.0/z>1.0/prior->inverse_z+shadow_world_margin) {
                    ++model_depth_rejected;++model_shadow_rejected;return 0;
                }
            } else if(model_shadow_same_camera(prior->owner) &&
                      1.0/z>1.0/prior->inverse_z+shadow_model_margin) {
                ++model_depth_rejected;++model_shadow_rejected;return 0;
            }
        }
        if(!shadow_keep_depth)prior->stamp=0;
        return 1;
    }
    double z=model_depth_plane[0]*x+model_depth_plane[1]*y+model_depth_plane[2];
    if(!isfinite(z)||z<=0||z>1){prior->stamp=0;return 1;}
    int prior_world=prior->stamp==model_depth_stamp&&prior->owner==MODEL_DEPTH_WORLD_OWNER;
    if(model_depth_world) {
        /* WORLD always draws in its original order and records its depth.
         * A later WORLD face over a nearer model is authored: Paco's tree
         * crowns cover actors from 16..256 units behind them. */
        /* Per-pixel only: row slices may run in parallel. world_depth_bounds
         * already published has_samples and this triangle's bounds. */
        if(x<world_roi_x0||x>world_roi_x1||y<world_roi_y0||y>world_roi_y1){prior->stamp=0;return 1;}
        *prior=(ModelDepthPixel){z,MODEL_DEPTH_WORLD_OWNER,model_depth_stamp,0};
        return 1;
    }
    if(prior_world&&1.0/prior->inverse_z+WORLD_DEPTH_CONTACT<1.0/z) {
        ++model_depth_rejected;++world_depth_rejected_model;return 0;
    }
    /* Coincident material layers preserve their order through equal depth.
     * One source face can contain overlapping, noncoplanar quad halves:
     * face identity alone must not let its farther half replace the nearer.
     * The tolerance covers only floating error in physical depth. */
    int same_owner=prior->stamp==model_depth_stamp&&prior->owner==model_depth_owner;
    if(prior->stamp==model_depth_stamp && !prior_world &&
       z<prior->inverse_z-1e-12*(z+prior->inverse_z) &&
       (same_owner || model_depth_same_camera(prior->owner))) {
        ++model_depth_rejected;return 0;
    }
    if(!semi){
        *prior=(ModelDepthPixel){z,model_depth_owner,model_depth_stamp,model_depth_face};
        model_depth_has_samples=1;
        model_depth_bound_write(page,x,y);
        model_roi_write(x/(int)model_depth_scale,local_y/(int)model_depth_scale);
    }
    else if(!same_owner)prior->stamp=0;
    if(model_minify_tracking)model_minify_keys[index]=model_minify_write;
    return 1;
}
#endif
typedef enum { FINE_PIXEL_EXTERNAL, FINE_PIXEL_TRACKED, FINE_PIXEL_ORDINARY } FinePixelRoute;
#if defined(__GNUC__)
__attribute__((always_inline))
#endif
static inline void put_fine_pixel_impl(uint16_t *px,int r,int grn,int b,
                                  int semi,int tex,uint16_t texel,int blend_mode,FinePixelRoute route) {
    (void)route;
    if (tex) {
        if (texel == 0) return;
        int tr = (texel & 31) << 3, tg = ((texel >> 5) & 31) << 3,
            tb = ((texel >> 10) & 31) << 3;
        r = (tr * r) >> 7; grn = (tg * grn) >> 7; b = (tb * b) >> 7;
        if (r > 255) r = 255; if (grn > 255) grn = 255; if (b > 255) b = 255;
        if (semi && !(texel & 0x8000)) semi = 0;
    }
    uint16_t msb = tex ? (texel & 0x8000) : 0;
#ifdef A2_NATIVE_MESH
    if(route==FINE_PIXEL_TRACKED&&a2_mesh_live_active) {
        size_t offset=(size_t)(px-SHADOW);int y=(int)(offset/(unsigned)IR_W),x=(int)(offset%(unsigned)IR_W);
        if(mesh_pixel_kind==A2_COMPOSITE_OWNED)mesh_coverage_pixel(x,y);
        if(x>=a2_mesh_live_x0&&x<a2_mesh_live_x1&&y>=a2_mesh_live_y0&&y<a2_mesh_live_y1) {
            float z;A2CompositeKind kind=mesh_kind_at(x,y,&z);
            A2CompositePixel sample={kind,z,(uint8_t)r,(uint8_t)grn,(uint8_t)b,
                (uint8_t)semi,(uint8_t)tex,(uint8_t)blend_mode,texel};
            a2_mesh_live_pixel(x,y,sample);
            if(!a2_mesh_live_active&&getenv("A2_MESH_TRACE")) {
                static unsigned rejected_examples;
                if(rejected_examples++<16) {
                    fprintf(stderr,"nativemesh-rejected-packet: frame=%u src=%08x kind=%u xy=%d,%d z=%.9g words=",
                        psx_frame_no,fifo_source[0],(unsigned)kind,x,y,z);
                    for(int i=0;i<fifo_n;i++)fprintf(stderr,"%08x,",fifo[i]);
                    fputc('\n',stderr);
                }
            }
        }
    }
#endif
#ifdef A2_NATIVE_MESH
    /* Source-owned faces never enter the displayed SHADOW, including pixels
     * outside the replacement silhouette and repeated render passes. */
    if(route!=FINE_PIXEL_ORDINARY&&mesh_pixel_kind==A2_COMPOSITE_OWNED)return;
#endif
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
    /* Only actual SHADOW writes own or retire depth. Transparent texels and
     * replacement-owned native pixels have already returned; STP determines
     * whether this sample blends. Native put_px never enters this path. */
    if(route==FINE_PIXEL_TRACKED&&model_depth_enabled&&!model_depth_sample(px,semi))return;
#endif
    if (semi) *px = blend(*px, r, grn, b, blend_mode) | msb;
    else *px = (uint16_t)((r >> 3) | ((grn >> 3) << 5) | ((b >> 3) << 10)) | msb;
    if(route!=FINE_PIXEL_EXTERNAL && SHADOW_RGB) {
        uint32_t *dst=SHADOW_RGB+(px-SHADOW);
        *dst=semi?display_blend(*dst,r,grn,b,blend_mode):display_rgb(r,grn,b);
    }
}
static inline void put_fine_pixel(uint16_t *px,int r,int grn,int b,
                                  int semi,int tex,uint16_t texel,int blend_mode) {
    put_fine_pixel_impl(px,r,grn,b,semi,tex,texel,blend_mode,FINE_PIXEL_TRACKED);
}
/* Submission is synchronous. With no model plane and no prior samples,
 * this triangle cannot acquire depth; with no mesh it cannot start coverage
 * or suppress a source-owned pixel. HD substitutions preserve these facts. */
static int fine_pixel_ordinary(void) {
#ifdef A2_NATIVE_MESH
    if(a2_mesh_live_enabled||a2_mesh_live_active||mesh_pixel_kind==A2_COMPOSITE_OWNED)return 0;
#ifdef A2_WORLD_PRECISION
    if(model_depth_enabled&&(model_depth_plane_valid||model_depth_has_samples))return 0;
#endif
#endif
    return 1;
}
/* Called once for a clipped fine row, never for individual world pixels.
 * Unknown writes outside the epoch's bounds cannot retire a current sample.
 * Current model/shadow planes and every mesh route keep their existing path. */
static int fine_pixel_ordinary_span(int first,int y,int last) {
#ifdef A2_MODEL_DEPTH_BOUNDS_TEST
    if(depth_bounds_reference)return 0;
#endif
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
    if(a2_mesh_live_enabled||a2_mesh_live_active||mesh_pixel_kind==A2_COMPOSITE_OWNED)return 0;
    if(!model_depth_enabled)return 1;
    if(model_depth_plane_valid)return 0;
    for(unsigned i=0;i<2;i++)
        if(model_depth_bounds[i].valid && y>=model_depth_bounds[i].y0 &&
           y<=model_depth_bounds[i].y1 && first<=model_depth_bounds[i].x1 &&
           last>=model_depth_bounds[i].x0)return 0;
    return 1;
#else
    (void)first;(void)y;(void)last;
    return fine_pixel_ordinary();
#endif
}
#ifdef A2_CINEMA_EXPANSION
/* Separate allocations have no SHADOW coordinates. The constant argument
 * removes all mesh coordinate/provenance work from these color-only writes. */
static inline void put_fine_external_pixel(uint16_t *px,int r,int grn,int b,
                                  int semi,int tex,uint16_t texel,int blend_mode) {
    put_fine_pixel_impl(px,r,grn,b,semi,tex,texel,blend_mode,FINE_PIXEL_EXTERNAL);
}
#endif

#ifdef A2_NATIVE_MESH
static void mesh_trace_writer(unsigned site,int x,int y,int w,int h){
    static uint32_t last[8];static unsigned lines;
    const char *t=getenv("A2_MESH_TRACE");
    if(!t||!a2_mesh_live_active||psx_frame_no<(uint32_t)strtoul(t,NULL,10)||site>=8||last[site]==psx_frame_no||lines>=128||
       x>=a2_mesh_live_x1||y>=a2_mesh_live_y1||x+w<=a2_mesh_live_x0||y+h<=a2_mesh_live_y0)return;
    last[site]=psx_frame_no;++lines;
    fprintf(stderr,"nativemesh-writer: frame=%u site=%u src=%08x cmd=%08x kind=%u xywh=%d,%d,%d,%d hud=%d words=",
        psx_frame_no,site,fifo_source[0],fifo[0],(unsigned)mesh_pixel_kind,x,y,w,h,
#ifdef A2_HUD_PRESENT
        hud_anchor
#else
        -1
#endif
    );
    for(int i=0;i<fifo_n;i++)fprintf(stderr,"%08x,",fifo[i]);fputc('\n',stderr);
}
#endif
/* Direct HD writes evaluate the same color operation against each background.
 * The returned alternate pointer is consumed immediately, never retained. */
#ifdef A2_NATIVE_MESH
static uint16_t *mesh_direct_destination(int x,int y,unsigned site) {
    if(!a2_mesh_live_writes_watched)return NULL;
    if(!a2_mesh_live_active)return NULL;
    float depth;A2CompositeKind kind=mesh_kind_at(x,y,&depth);
    if(kind==A2_COMPOSITE_OWNED)mesh_coverage_pixel(x,y);
    (void)site;
    return a2_mesh_live_destination(x,y,kind,depth);
}
#endif
#ifdef A2_HD_FONTS
static uint16_t fine_color(uint16_t before,int r,int grn,int b,int semi,uint16_t texel) {
#ifdef A2_HD_PALETTE_TEST
    hd_rect_shading_calls++;
#endif
    if(!texel)return before;
    r=(((texel&31)<<3)*r)>>7;grn=((((texel>>5)&31)<<3)*grn)>>7;
    b=((((texel>>10)&31)<<3)*b)>>7;
    if(r>255)r=255;if(grn>255)grn=255;if(b>255)b=255;
    if(semi && (texel&0x8000))return blend(before,r,grn,b,(cur_tpage>>5)&3)|(texel&0x8000);
    return (uint16_t)((r>>3)|((grn>>3)<<5)|((b>>3)<<10))|(texel&0x8000);
}
#endif
static inline void put_fine(int fx,int fy,int r,int grn,int b,int semi,int tex,uint16_t texel) {
    if(fx<g.dax1*IR || fx>(g.dax2+1)*IR-1 || fy<g.day1*IR || fy>(g.day2+1)*IR-1)return;
    put_fine_pixel(shadow_px(fx,fy),r,grn,b,semi,tex,texel,(cur_tpage>>5)&3);
}

/* Nearest native sprites have one texel per S×S fine block. The original
 * 1x pass has finished, so sampling VRAM once here is stable. */
static void rect_fine_blocks(int x,int y,int w,int h,int u,int v,
                             int r,int grn,int b,int semi,int tex,int S) {
    int ix0=g.dax1-x,iy0=g.day1-y,ix1=g.dax2-x+1,iy1=g.day2-y+1;
    if(ix0<0)ix0=0;if(iy0<0)iy0=0;
    if(ix1>w)ix1=w;if(iy1>h)iy1=h;
    if(ix0>=ix1||iy0>=iy1)return;
    if(!tex&&semi&&((cur_tpage>>5)&3)==1) {
        /* Additive untextured rectangles (including the storm flash) have
         * constant foreground channels. Saturate in5-bit units directly:
         * min(255,background5*8+foreground8)>>3 == min(31,background5+foreground8/8).
         * Contiguous clipped rows allow the compiler to vectorize the blend. */
        unsigned r5=(unsigned)r>>3,g5=(unsigned)grn>>3,b5=(unsigned)b>>3;
        int width=(ix1-ix0)*S;
        if(SHADOW_RGB)for(int fy=(y+iy0)*S;fy<(y+iy1)*S;fy++) {
            uint32_t *dst=SHADOW_RGB+(size_t)fy*IR_W+(x+ix0)*S;
            for(int i=0;i<width;i++)dst[i]=display_blend(dst[i],r,grn,b,1);
        }
        for(int fy=(y+iy0)*S;fy<(y+iy1)*S;fy++) {
            uint16_t *dst=SHADOW+(size_t)fy*IR_W+(x+ix0)*S;
            for(int i=0;i<width;i++) {
                unsigned bg=dst[i],red=(bg&31)+r5,green=((bg>>5)&31)+g5,blue=((bg>>10)&31)+b5;
                if(red>31)red=31;if(green>31)green=31;if(blue>31)blue=31;
                dst[i]=(uint16_t)(red|(green<<5)|(blue<<10));
            }
        }
#ifdef A2_NATIVE_MESH
        if(a2_mesh_live_active) {
            int x0=(x+ix0)*S,x1=(x+ix1)*S,y0=(y+iy0)*S,y1=(y+iy1)*S;
            if(x0<a2_mesh_live_x0)x0=a2_mesh_live_x0;if(x1>a2_mesh_live_x1)x1=a2_mesh_live_x1;
            if(y0<a2_mesh_live_y0)y0=a2_mesh_live_y0;if(y1>a2_mesh_live_y1)y1=a2_mesh_live_y1;
            for(int fy=y0;fy<y1;fy++)for(int fx=x0;fx<x1;fx++) {
                uint16_t *dst=mesh_direct_destination(fx,fy,4);if(!dst)continue;
                unsigned bg=*dst,red=(bg&31)+r5,green=((bg>>5)&31)+g5,blue=((bg>>10)&31)+b5;
                if(red>31)red=31;if(green>31)green=31;if(blue>31)blue=31;
                *dst=(uint16_t)(red|(green<<5)|(blue<<10));
            }
        }
#endif
        return;
    }
    for(int j=iy0;j<iy1;j++)for(int i=ix0;i<ix1;i++) {
        uint16_t texel=tex?sample_tex_present(u+i,v+j):0;
        if(tex&&!texel)continue;
        int fx=(x+i)*S,fy=(y+j)*S;
        if(!semi || (tex && !(texel&0x8000))) {
            put_fine(fx,fy,r,grn,b,semi,tex,texel);
            uint16_t color=SHADOW[(size_t)fy*IR_W+fx];
            if(SHADOW_RGB) {
                uint32_t rgb=SHADOW_RGB[(size_t)fy*IR_W+fx];
                for(int oy=0;oy<S;oy++) {
                    uint32_t *row=SHADOW_RGB+(size_t)(fy+oy)*IR_W+fx;
                    for(int ox=0;ox<S;ox++)row[ox]=rgb;
                }
            }
            for(int oy=0;oy<S;oy++) {
                uint16_t *dst=SHADOW+(size_t)(fy+oy)*IR_W+fx;
                for(int ox=0;ox<S;ox++)dst[ox]=color;
#ifdef A2_NATIVE_MESH
                if(a2_mesh_live_active)for(int ox=0;ox<S;ox++)if(ox||oy) {
                    uint16_t *alternate=mesh_direct_destination(fx+ox,fy+oy,4);
                    if(alternate)*alternate=color;
                }
#endif
            }
        } else {
            for(int oy=0;oy<S;oy++)for(int ox=0;ox<S;ox++)
                put_fine(fx+ox,fy+oy,r,grn,b,semi,tex,texel);
        }
    }
}

#ifdef A2_HD_FONTS
static uint16_t coverage_mix(uint16_t before,uint16_t after,unsigned coverage) {
    if (!coverage) return before;
    if (coverage==255) return after;
    uint16_t color=0;
    for(int shift=0;shift<15;shift+=5) {
        unsigned a=(before>>shift)&31,z=(after>>shift)&31;
        color|=(uint16_t)(((a*(255-coverage)+z*coverage+127)/255)<<shift);
    }
    return color | (after&0x8000);
}
static void put_font_coverage(int fx, int fy, int r, int grn, int b,
                              int semi, uint16_t ink, unsigned coverage) {
    if (!coverage || !ink || fx < g.dax1*IR || fx >= (g.dax2+1)*IR ||
        fy < g.day1*IR || fy >= (g.day2+1)*IR) return;
    uint16_t *dst=shadow_px(fx,fy);
#ifdef A2_NATIVE_MESH
    uint16_t *alternate=mesh_direct_destination(fx,fy,1);
    if(alternate)*alternate=coverage_mix(*alternate,fine_color(*alternate,r,grn,b,semi,ink),coverage);
    if(mesh_pixel_kind==A2_COMPOSITE_OWNED)return;
#endif
    *dst=coverage_mix(*dst,fine_color(*dst,r,grn,b,semi,ink),coverage);
    if(SHADOW_RGB) {
        uint32_t *rgb=SHADOW_RGB+(dst-SHADOW),before=*rgb;
        *rgb=display_coverage(before,display_tex_color(before,r,grn,b,semi,ink,(cur_tpage>>5)&3),coverage);
    }
}
#ifdef A2_HD_TEST_COUNT
static unsigned long hd_ui_test_calls;
static unsigned long hd_span_test_calls;
#endif
#if defined(A2_HD_ART) || defined(A2_HD_PORTRAITS)
static void hd_art_axis_bounds(int first,int last,unsigned mask,unsigned offset,
                               int *lo,int *hi) {
    unsigned forced=offset&mask;
    if (last-first>=255) {
        *lo=(int)forced;*hi=(int)(forced|(255u&~mask));
        return;
    }
    *lo=255;*hi=0;
    for (int p=first;p<=last;p++) {
        int value=(int)((((unsigned)p&255u)&~mask)|forced);
        if(value<*lo)*lo=value;
        if(value>*hi)*hi=value;
    }
}
#ifdef A2_HD_ART
static void prepare_hd_art(int u0,int v0,int u1,int v1) {
    if (!a2_hd_font_enabled()) {
#ifdef A2_HUD_PRESENT
        /* The 1x display plane still needs the canonical round HUD artwork.
         * Text caches and all untagged/menu assets retain their existing gate. */
        const char *enabled=getenv("A2_HDUI");
        if(hud_anchor<0 || IR!=1 || (enabled && !strcmp(enabled,"0")))return;
#else
        return;
#endif
    }
    /* Bound reachable integer texels after wrap/E2, independently per axis.
       Expanding a repeated background to the entire atlas would match
       unrelated art and disable its ordinary native-block fine renderer.
       Bounds may include holes from partial masks, but never exclude a
       reachable texel. Fractional UV sampling and full source checks stay
       unchanged. At most 256 values per axis need inspection. */
    if (g.texwin || u0<0 || v0<0 || u1>255 || v1>255) {
        hd_art_axis_bounds(u0,u1,(g.texwin&31)*8,((g.texwin>>10)&31)*8,&u0,&u1);
        hd_art_axis_bounds(v0,v1,((g.texwin>>5)&31)*8,((g.texwin>>15)&31)*8,&v0,&v1);
    }
    hd_art_count=a2_hd_art_prepare(a2_hd_art_assets,a2_hd_art_asset_count,
                                  GPU_VRAM,cur_tpage,u0,v0,u1,v1,hd_art,128);
}
#endif
#ifdef A2_HD_PORTRAITS
static void prepare_hd_portrait(int u0,int v0,int u1,int v1) {
    const char *e=getenv("A2_HD_PORTRAITS");
    if(!a2_hd_font_enabled() || (e && !strcmp(e,"0"))) return;
    if(g.texwin || u0<0 || v0<0 || u1>255 || v1>255) {
        hd_art_axis_bounds(u0,u1,(g.texwin&31)*8,((g.texwin>>10)&31)*8,&u0,&u1);
        hd_art_axis_bounds(v0,v1,((g.texwin>>5)&31)*8,((g.texwin>>15)&31)*8,&v0,&v1);
    }
    hd_portrait=a2_hd_portrait_prepare(a2_hd_portraits_assets,a2_hd_portraits_asset_count,
                                      GPU_VRAM,cur_tpage,cur_clut,u0,v0,u1,v1);
}
static int put_hd_portrait(int fx,int fy,int r,int grn,int b,int u_fp,int v_fp) {
    A2HDPortraitSample p;
    if(!a2_hd_portrait_sample(hd_portrait,g.texwin,u_fp,v_fp,&p)) return 0;
    if(!p.a || fx<g.dax1*IR || fx>=(g.dax2+1)*IR || fy<g.day1*IR || fy>=(g.day2+1)*IR) return 1;
    uint16_t *destinations[2]={shadow_px(fx,fy),NULL};
#ifdef A2_NATIVE_MESH
    destinations[1]=mesh_direct_destination(fx,fy,2);
    if(mesh_pixel_kind==A2_COMPOSITE_OWNED)destinations[0]=NULL;
#endif
    int rgb[3]={p.r*r/128,p.g*grn/128,p.b*b/128};
    if(SHADOW_RGB && destinations[0]) {
        uint32_t *dst=SHADOW_RGB+(destinations[0]-SHADOW);
        *dst=display_coverage(*dst,display_rgb(display_clamp(rgb[0]),display_clamp(rgb[1]),display_clamp(rgb[2])),p.a);
    }
    for(unsigned d=0;d<2;d++) {
    uint16_t *dst=destinations[d];if(!dst)continue;
    uint16_t before=*dst,result=0;
    /* Canonical source palettes have STP clear. Command semi does not halve
       these portraits. Straight PNG alpha is the only coverage, and zero
       RGB is an opaque color when alpha is 255. Quantize only at the end. */
    for(unsigned c=0;c<3;c++) {
        unsigned color=(unsigned)(rgb[c]>255?255:rgb[c]);
        unsigned previous=((before>>(c*5))&31)*8;
        color=(color*p.a+previous*(255-p.a)+127)/255;
        result|=(uint16_t)((color>>3)<<(c*5));
    }
    *dst=result;
    }
    return 1;
}
#endif
#endif
static int put_hd_ui(int fx,int fy,int r,int grn,int b,int semi,int u_fp,int v_fp) {
#ifdef A2_HD_TEST_COUNT
    hd_ui_test_calls++;
#endif
#ifdef A2_HD_PORTRAITS
    if(hd_portrait && put_hd_portrait(fx,fy,r,grn,b,u_fp,v_fp)) return 1;
#endif
    A2HDUISample s;
    int word=hd_plate_count &&
        a2_hd_ui_sample(hd_plates,hd_plate_count,GPU_VRAM,cur_clut,u_fp,v_fp,&s);
#ifdef A2_HD_ART
    A2HDArtSample art;
    int au=u_fp,av=v_fp;
    a2_hd_art_window_uv(g.texwin,&au,&av);
    int artwork=hd_art_count &&
        a2_hd_art_sample(hd_art,hd_art_count,GPU_VRAM,cur_clut,au,av,&art);
    if (!word && !artwork) return 0;
    /* No covered sample exists, so neither destination nor provenance is touched. */
    if (!word && !art.coverage) return 1;
#else
    if (!word) return 0;
#endif
    if (fx<g.dax1*IR || fx>=(g.dax2+1)*IR || fy<g.day1*IR || fy>=(g.day2+1)*IR) return 1;
    uint16_t *destinations[2]={shadow_px(fx,fy),NULL};
#ifdef A2_NATIVE_MESH
    destinations[1]=mesh_direct_destination(fx,fy,3);
    if(mesh_pixel_kind==A2_COMPOSITE_OWNED)destinations[0]=NULL;
#endif
    if(SHADOW_RGB && destinations[0]) {
        uint32_t *dst=SHADOW_RGB+(destinations[0]-SHADOW),before=*dst,base;
        int mode=(cur_tpage>>5)&3;
#ifdef A2_HD_ART
        if(artwork) {
            if(!art.coverage)base=before;
            else if(!art.mix || art.mix==255)
                base=display_coverage(before,display_tex_color(before,r,grn,b,semi,art.mix?art.second:art.first,mode),art.coverage);
            else {
                uint32_t first=display_tex_color(before,r,grn,b,semi,art.first,mode);
                uint32_t second=display_tex_color(before,r,grn,b,semi,art.second,mode);
                base=display_coverage(before,display_coverage(first,second,art.mix),art.coverage);
            }
        } else
#endif
            base=display_tex_color(before,r,grn,b,semi,s.background,mode);
        if(word && s.shadow_alpha && s.shadow)
            base=display_coverage(base,display_tex_color(before,r,grn,b,semi,s.shadow,mode),s.shadow_alpha);
        if(word && s.alpha && s.ink)
            base=display_coverage(base,display_tex_color(before,r,grn,b,semi,s.ink,mode),s.alpha);
        *dst=base;
    }
    for(unsigned d=0;d<2;d++) {
    uint16_t *dst=destinations[d];if(!dst)continue;
    uint16_t before=*dst;
    uint16_t base;
#ifdef A2_HD_ART
    if (artwork) {
        if (!art.coverage) base=before;
        else if (art.mix==0 || art.mix==255) {
            /* Endpoint mixtures use only one alternative. Keep its STP and
               blend against the original destination, as in the full mix. */
            *dst=fine_color(before,r,grn,b,semi,art.mix?art.second:art.first);
            base=coverage_mix(before,*dst,art.coverage);
        } else {
            *dst=fine_color(before,r,grn,b,semi,art.first);
            uint16_t first=*dst;
            *dst=before;*dst=fine_color(before,r,grn,b,semi,art.second);
            base=coverage_mix(before,coverage_mix(first,*dst,art.mix),art.coverage);
        }
    } else
#endif
    {
        *dst=fine_color(before,r,grn,b,semi,s.background);
        base=*dst;
    }
    /* All alternatives blend against the same destination. This avoids
       applying PS1 semitransparency twice beneath an antialiased letter. */
    if (word && s.shadow_alpha && s.shadow) {
        *dst=before;*dst=fine_color(before,r,grn,b,semi,s.shadow);
        base=coverage_mix(base,*dst,s.shadow_alpha);
    }
    if (word && s.alpha && s.ink) {
        *dst=before;*dst=fine_color(before,r,grn,b,semi,s.ink);
        base=coverage_mix(base,*dst,s.alpha);
    }
    *dst=base;
    }
    return 1;
}
#endif

#if defined(A2_HD_FONTS) && defined(A2_HD_ART)
/* Command-local modulated palette. Coverage and semitransparency still use
 * each destination's own background, independently in the two color planes. */
typedef struct {uint32_t rgb;uint16_t fine;uint8_t transparent,semi;} HDArtColor;
static HDArtColor hd_art_color(uint16_t texel,int r,int grn,int b,int semi) {
#ifdef A2_HD_PALETTE_TEST
    hd_rect_palette_calls++;
#endif
    uint32_t rgb=display_tex_color(0,r,grn,b,0,texel,0);
    uint16_t fine=(uint16_t)(((rgb>>19)&31)|((rgb>>6)&0x3e0)|((rgb<<7)&0x7c00))|(texel&0x8000);
    return (HDArtColor){rgb,fine,!texel,semi&&(texel&0x8000)};
}
static inline uint16_t hd_art_color_fine(uint16_t before,HDArtColor color,int mode) {
    if(color.transparent)return before;
    if(!color.semi)return color.fine;
    return blend(before,(color.rgb>>16)&255,(color.rgb>>8)&255,color.rgb&255,mode)|(color.fine&0x8000);
}
static inline uint32_t hd_art_color_rgb(uint32_t before,HDArtColor color,int mode) {
    if(color.transparent)return before;
    if(!color.semi)return color.rgb;
    return display_blend(before,(color.rgb>>16)&255,(color.rgb>>8)&255,color.rgb&255,mode);
}
/* A prepared, fully covering asset gives rectangular sprites a contiguous
 * authored-pixel span. Keep all source identity checks in prepare_hd_art;
 * only the repeated per-pixel lookup is removed here. */
static int hd_art_rect_span(int x,int y,int w,int h,int u,int v,
                            int r,int grn,int b,int semi,int S,
                            int fi0,int fj0,int fi1,int fj1) {
#ifdef A2_HD_RECT_TEST
    if(hd_rect_reference)return 0;
#endif
#ifdef A2_GPU_RECT_TEST
    if(gpu_rect_test_reference)return 0;
#endif
    if((S!=2&&S!=4)||hd_art_count!=1)return 0;
#ifdef A2_HD_PORTRAITS
    if(hd_portrait)return 0;
#endif
#ifdef A2_NATIVE_MESH
    if(a2_mesh_live_active||a2_mesh_live_writes_watched||mesh_pixel_kind==A2_COMPOSITE_OWNED)return 0;
#endif
    if(fi0>=fi1||fj0>=fj1)return 1;
    int word_bounds[4];
    int words=a2_hd_ui_bounds(hd_plates,hd_plate_count,word_bounds);
    if(words)for(int i=0;i<4;i++)word_bounds[i]=(word_bounds[i]-(i&1?v:u))*S;
    const A2HDArt *a=hd_art[0];
    int direct=!g.texwin && u>=a->u && v>=a->v && u+w<=a->u+a->width && v+h<=a->v+a->height;
    int columns[1024],rows[512];
    unsigned shift=S==4?2:1;
    if(!direct) {
        /* Texture windows can repeat a small source tile across a wide menu
         * panel. Resolve each native coordinate once, preserving fractional
         * authored samples. Validate all reachable coordinates before writing. */
        unsigned mu=(g.texwin&31)*8,mv=((g.texwin>>5)&31)*8;
        unsigned ou=((g.texwin>>10)&31)*8,ov=((g.texwin>>15)&31)*8;
        for(int i=fi0>>shift;i<((fi1+S-1)>>shift);i++) {
            unsigned uv=(((unsigned)(u+i)&255)&~mu)|(ou&mu);
            if(uv<a->u||uv>=a->u+a->width)return 0;
            columns[i]=(int)(uv-a->u)*4;
        }
        for(int j=fj0>>shift;j<((fj1+S-1)>>shift);j++) {
            unsigned uv=(((unsigned)(v+j)&255)&~mv)|(ov&mv);
            if(uv<a->v||uv>=a->v+a->height)return 0;
            rows[j]=(int)(uv-a->v)*4;
        }
    }
#ifdef A2_HD_RECT_TEST
    hd_rect_fast_calls++;
#endif
#ifdef A2_HD_TEST_COUNT
    hd_span_test_calls++;
#endif
    unsigned cy=((cur_clut>>6)&511)*1024,cx=(cur_clut&63)*16;
    int step=4/S,mode=(cur_tpage>>5)&3;
    /* The native pass is complete and this span only writes presentation
     * memory. Read the current CLUT again for every command, including live
     * palette changes, wrapping and repeated blends. Amortize256 entries
     * only on large clipped spans; smaller spans keep scalar word shading. */
    HDArtColor palette[256];
    int prepared=(fi1-fi0)*(fj1-fj0)>=1024;
    if(prepared)for(unsigned i=0;i<256;i++)
        palette[i]=hd_art_color(GPU_VRAM[cy+((cx+i)&1023)],r,grn,b,semi);
    for(int fj=fj0;fj<fj1;fj++) {
        int word_row=words && fj>=word_bounds[1] && fj<word_bounds[3];
        int ay=direct?(v-a->v)*4+fj*step:rows[fj>>shift]+(fj&(S-1))*step;
        const uint32_t *row=a->pixels+ay*(a->width*4);
        const uint32_t *src=direct?row+(u-a->u)*4+fi0*step:row;
        size_t offset=(size_t)(y*S+fj)*IR_W+x*S+fi0;
        uint16_t *dst=SHADOW+offset;
        uint32_t *rgb=SHADOW_RGB?SHADOW_RGB+offset:NULL;
        for(int fi=fi0;fi<fi1;fi++,dst++) {
            uint32_t pixel=direct?*src:row[columns[fi>>shift]+(fi&(S-1))*step];
            unsigned alpha=pixel>>24,mix=(pixel>>16)&255;
            if(direct)src+=step;
            A2HDUIIndices word;
            int has_word=0;
            if(word_row && fi>=word_bounds[0] && fi<word_bounds[2]) {
                if(prepared)has_word=a2_hd_ui_sample_indices(hd_plates,hd_plate_count,
                    u*256+fi*256/S,v*256+fj*256/S,&word);
                else {
                    put_hd_ui(x*S+fi,y*S+fj,r,grn,b,semi,u*256+fi*256/S,v*256+fj*256/S);
                    continue;
                }
            }
            /* A word can cover a transparent art sample. Its alternatives
             * still blend against the original destination, then cover the
             * art, shadow and ink in that order, separately in each plane. */
            if(!alpha && !has_word)continue;
            if(prepared) {
                HDArtColor first=palette[pixel&255],second=palette[(pixel>>8)&255];
                uint16_t before=*dst,after;
                if(!mix||mix==255)after=hd_art_color_fine(before,mix?second:first,mode);
                else after=coverage_mix(hd_art_color_fine(before,first,mode),hd_art_color_fine(before,second,mode),mix);
                after=coverage_mix(before,after,alpha);
                if(has_word) {
                    HDArtColor shadow=palette[word.shadow],ink=palette[word.ink];
                    if(word.shadow_alpha && !shadow.transparent)
                        after=coverage_mix(after,hd_art_color_fine(before,shadow,mode),word.shadow_alpha);
                    if(word.alpha && !ink.transparent)
                        after=coverage_mix(after,hd_art_color_fine(before,ink,mode),word.alpha);
                }
                *dst=after;
                if(rgb) {
                    uint32_t prev=rgb[fi-fi0],next;
                    if(!mix||mix==255)next=hd_art_color_rgb(prev,mix?second:first,mode);
                    else next=display_coverage(hd_art_color_rgb(prev,first,mode),hd_art_color_rgb(prev,second,mode),mix);
                    next=display_coverage(prev,next,alpha);
                    if(has_word) {
                        HDArtColor shadow=palette[word.shadow],ink=palette[word.ink];
                        if(word.shadow_alpha && !shadow.transparent)
                            next=display_coverage(next,hd_art_color_rgb(prev,shadow,mode),word.shadow_alpha);
                        if(word.alpha && !ink.transparent)
                            next=display_coverage(next,hd_art_color_rgb(prev,ink,mode),word.alpha);
                    }
                    rgb[fi-fi0]=next;
                }
                continue;
            }
            uint16_t first=GPU_VRAM[cy+((cx+(pixel&255))&1023)];
            uint16_t second=GPU_VRAM[cy+((cx+((pixel>>8)&255))&1023)];
            uint16_t before=*dst,after;
            if(!mix||mix==255)after=fine_color(before,r,grn,b,semi,mix?second:first);
            else after=coverage_mix(fine_color(before,r,grn,b,semi,first),fine_color(before,r,grn,b,semi,second),mix);
            *dst=coverage_mix(before,after,alpha);
            if(rgb) {
                uint32_t prev=rgb[fi-fi0],next;
                if(!mix||mix==255)next=display_tex_color(prev,r,grn,b,semi,mix?second:first,mode);
                else next=display_coverage(display_tex_color(prev,r,grn,b,semi,first,mode),display_tex_color(prev,r,grn,b,semi,second,mode),mix);
                rgb[fi-fi0]=display_coverage(prev,next,alpha);
            }
        }
    }
    return 1;
}
#endif

int gpu_tri_total, gpu_tri_rejected;

typedef struct { int64_t x,y; } WorldFinePoint;
typedef struct { WorldFinePoint p[3]; } WorldFineTriangle;

#ifdef A2_WORLD_PRECISION
static int64_t world_edge(WorldFinePoint a,WorldFinePoint b,WorldFinePoint p) {
    return (b.x-a.x)*(p.y-a.y)-(b.y-a.y)*(p.x-a.x);
}
static int world_top_left(WorldFinePoint a,WorldFinePoint b) {
    return a.y>b.y || (a.y==b.y && a.x<b.x);
}
/* Validate the entire primitive before either quad half changes fine path.
 * Legacy GTE fractions remain inside their native integer cell. A separately
 * proven camera projection may leave that cell but retains the native word,
 * complete source generation and independent Q16/depth/coordinate bounds. */
/* Diagnostic (A2_PROJECTION_AUDIT): host geometry versus the native GTE
 * word it replaces, per producer. Camera recovery moves points by sub-pixel
 * amounts; anything larger means two projections disagree. */
static int projection_audit=-1;
static struct {uint32_t pc;uint64_t n,over2,over4;double max,sx,sy;} projection_stats[32];
static void projection_audit_report(void) {
    for(unsigned i=0;i<32&&projection_stats[i].n;i++)fprintf(stderr,"projection-audit: pc=%08x n=%llu max=%.2f over2=%llu over4=%llu\n",
        projection_stats[i].pc,(unsigned long long)projection_stats[i].n,projection_stats[i].max,
        (unsigned long long)projection_stats[i].over2,(unsigned long long)projection_stats[i].over4),
        fprintf(stderr,"projection-bias: pc=%08x mean_dx=%.3f mean_dy=%.3f\n",projection_stats[i].pc,projection_stats[i].sx/projection_stats[i].n,projection_stats[i].sy/projection_stats[i].n);
}
static void projection_audit_point(uint32_t pc,double x,double y,uint32_t word) {
    if(projection_audit<0){projection_audit=getenv("A2_PROJECTION_AUDIT")!=NULL;if(projection_audit)atexit(projection_audit_report);}
    if(!projection_audit)return;
    double dx=x-((int16_t)word+0.5),dy=y-((int16_t)(word>>16)+0.5),d=sqrt(dx*dx+dy*dy);
    unsigned i=0;while(i<31&&projection_stats[i].n&&projection_stats[i].pc!=pc)i++;
    projection_stats[i].pc=pc;projection_stats[i].n++;projection_stats[i].sx+=dx;projection_stats[i].sy+=dy;if(d>projection_stats[i].max)projection_stats[i].max=d;
    if(d>2){projection_stats[i].over2++;int nx=(int16_t)word,ny=(int16_t)(word>>16);
        if(nx>=0&&nx<320&&ny>=0&&ny<240){static unsigned on;if(on++<20)fprintf(stderr,"projection-onscreen2: pc=%08x native=%d,%d host=%.2f,%.2f\n",pc,nx,ny,x,y);}}
    if(d>4){projection_stats[i].over4++;static unsigned shown;if(shown++<30)fprintf(stderr,"projection-outlier: pc=%08x native=%d,%d host=%.2f,%.2f\n",pc,(int16_t)word,(int16_t)(word>>16),x,y);}
}
static int world_fine_projection_points(WorldFinePoint *out,const Vtx *v,int count) {
    if(count!=3 && count!=4)return 0;
    unsigned kind=world_vertices[0].projection_kind;
    uint64_t camera_generation=world_vertices[0].camera_generation;
    if(kind>WORLD_PROJECTION_CAMERA)return 0;
    for(int i=0;i<count;i++) {
        int nx=v[i].x-g.ofx,ny=v[i].y-g.ofy;
        double x=world_vertices[i].x*65536.0,y=world_vertices[i].y*65536.0;
        if(nx< -1024 || nx>=1024 || ny< -1024 || ny>=1024 ||
           world_vertices[i].projection_kind!=kind ||
           (int16_t)world_vertices[i].native_word!=nx ||
           (int16_t)(world_vertices[i].native_word>>16)!=ny)return 0;
        if(kind==WORLD_PROJECTION_CAMERA) {
            projection_audit_point(world_vertices[i].producer_pc,world_vertices[i].x,world_vertices[i].y,world_vertices[i].native_word);
            double z=world_vertices[i].z;
            if(!camera_generation || world_vertices[i].camera_generation!=camera_generation ||
               !isfinite(x) || !isfinite(y) || !isfinite(z) ||
               x< -1024.0*65536 || x>=1024.0*65536 ||
               y< -1024.0*65536 || y>=1024.0*65536 ||
               !(z>=1.0/4096.0 && z<65536.0))return 0;
        } else if(!(x>=(double)nx*65536 && x<(double)(nx+1)*65536) ||
                  !(y>=(double)ny*65536 && y<(double)(ny+1)*65536))return 0;
        int64_t ix=(int64_t)x,iy=(int64_t)y;
        if((double)ix!=x || (double)iy!=y) return 0;
        out[i]=(WorldFinePoint){ix+(int64_t)g.ofx*65536,iy+(int64_t)g.ofy*65536};
    }
    return 1;
}
static int world_fine_points(WorldFinePoint *out,const Vtx *v,int count) {
    if(!world_fine_projection_points(out,v,count))return 0;
    /* Keep culling and raster eligibility identical. Degeneracy belongs
     * to each raster's own coordinates, not the primitive's identity. */
    uint32_t words[4];
    for(int i=0;i<count;i++)words[i]=world_vertices[i].native_word;
    return world_precision_raster_extent(words,(unsigned)count);
}
#ifdef A2_NATIVE_MESH
static int model_depth_admit(const A2ActorPacket *packet,int count) {
    model_depth_plane_valid=0;model_depth_world=0;model_roi_roll();
    model_depth_other_owner=0;model_depth_other_camera_matches=0;
    if(!model_depth_enabled)return 0;
    const A2ActorPacketOwner *owner=packet?a2_native_actor_packets_owner(packet->owner_handle):NULL;
    /* Immutable original owners identify the projection convention. EVENT
     * models use their own emitter and a 172-row view; they otherwise share
     * GAME's same-camera depth surface and material/coverage retirement. */
    uint32_t producer_pc=0;int view_height=0;
    if(owner)switch(owner->instance.source_family) {
        case A2_ACTOR_GAME00:producer_pc=0x8001338cu;view_height=216;break;
        case A2_ACTOR_EVENT00:producer_pc=0x80013424u;view_height=172;break;
        default:break;
    }
    int valid=owner && producer_pc && !a2_mesh_live_active &&
        mesh_pixel_kind!=A2_COMPOSITE_OWNED &&
        IR>=2 && IR<=4 && world_camera_enabled && g.ofx==0 && (g.ofy==0||g.ofy==256) &&
        g.dax1==0 && g.dax2==319 && g.day1==g.ofy && g.day2==g.ofy+view_height-1 &&
        packet->source_mesh_index<32 && packet->native_face_index<65536;
#ifdef A2_HD_FONTS
    if(hd_matches_active())valid=0;
#endif
    for(int i=0;valid&&i<count;i++)valid=world_vertices[i].producer_pc==producer_pc &&
        world_vertices[i].projection_kind==WORLD_PROJECTION_CAMERA &&
        isfinite(world_vertices[i].z) && world_vertices[i].z>=1 && world_vertices[i].z<65536;
    if(!valid)return 0;
    if(model_depth_scale!=(unsigned)IR) {
        size_t n=(size_t)320*432*IR*IR;
        ModelDepthPixel *next=calloc(n,sizeof *next);
        if(!next){gpu_model_depth_barrier();return 0;}
        free(model_depth_pixels);model_depth_pixels=next;model_depth_count=n;model_depth_scale=(unsigned)IR;
        gpu_model_depth_barrier();
    }
    model_depth_owner=packet->owner_handle;
    /* Keep copied camera data, never a registry pointer across commands. */
    memcpy(model_depth_root_q12,owner->instance.renderer_root_q12,sizeof model_depth_root_q12);
    memcpy(model_depth_camera.origin_q12,owner->camera_origin_q12,sizeof model_depth_camera.origin_q12);
    memcpy(model_depth_camera.rotation_q12,owner->camera_rotation_q12,sizeof model_depth_camera.rotation_q12);
    model_depth_camera.h=owner->projection_h;model_depth_camera.ofx=owner->projection_ofx;
    model_depth_camera.ofy=owner->projection_ofy;model_depth_camera.source_family=owner->instance.source_family;
    model_depth_face=(packet->source_mesh_index<<16)|packet->native_face_index;
    ++model_depth_admitted;return 1;
}
/* Opaque WORLD faces in the same full gameplay/EVENT view as admitted
 * models. Actor and shadow producers are never WORLD occluders. */
static int world_depth_admit(int count,int semi) {
    model_depth_world=0;
    world_depth_on();
    if(!world_depth_enabled||!model_depth_enabled||semi)return 0;
    model_roi_roll();
    if(!model_roi_now.valid&&!model_roi_last.valid)return 0;
    int valid=!a2_mesh_live_active && mesh_pixel_kind!=A2_COMPOSITE_OWNED &&
        IR>=2 && IR<=4 && world_camera_enabled && g.ofx==0 && (g.ofy==0||g.ofy==256) &&
        g.dax1==0 && g.dax2==319 && g.day1==g.ofy && (g.day2==g.ofy+215||g.day2==g.ofy+171);
#ifdef A2_HD_FONTS
    if(hd_matches_active())valid=0;
#endif
    for(int i=0;valid&&i<count;i++)valid=world_vertices[i].projection_kind==WORLD_PROJECTION_CAMERA &&
        world_vertices[i].producer_pc!=0x8001338cu && world_vertices[i].producer_pc!=0x80013424u &&
        world_vertices[i].producer_pc!=0x800155d8u &&
        isfinite(world_vertices[i].z) && world_vertices[i].z>=1 && world_vertices[i].z<65536;
    if(!valid)return 0;
    /* Union of current and previous model regions, grown by the margin. */
    int rx0=1<<30,ry0=1<<30,rx1=-(1<<30),ry1=-(1<<30);
    if(model_roi_now.valid){rx0=model_roi_now.x0;ry0=model_roi_now.y0;rx1=model_roi_now.x1;ry1=model_roi_now.y1;}
    if(model_roi_last.valid){if(model_roi_last.x0<rx0)rx0=model_roi_last.x0;if(model_roi_last.y0<ry0)ry0=model_roi_last.y0;
        if(model_roi_last.x1>rx1)rx1=model_roi_last.x1;if(model_roi_last.y1>ry1)ry1=model_roi_last.y1;}
    rx0-=WORLD_DEPTH_ROI_MARGIN;ry0-=WORLD_DEPTH_ROI_MARGIN;rx1+=WORLD_DEPTH_ROI_MARGIN;ry1+=WORLD_DEPTH_ROI_MARGIN;
    double vx0=world_vertices[0].x,vx1=vx0,vy0=world_vertices[0].y,vy1=vy0;
    for(int i=1;i<count;i++){double vx=world_vertices[i].x,vy=world_vertices[i].y;
        if(vx<vx0)vx0=vx;if(vx>vx1)vx1=vx;if(vy<vy0)vy0=vy;if(vy>vy1)vy1=vy;}
    if(vx1<rx0||vx0>rx1+1||vy1<ry0||vy0>ry1+1)return 0;
    if(model_depth_scale!=(unsigned)IR) {
        size_t n=(size_t)320*432*IR*IR;
        ModelDepthPixel *next=calloc(n,sizeof *next);
        if(!next){gpu_model_depth_barrier();return 0;}
        free(model_depth_pixels);model_depth_pixels=next;model_depth_count=n;model_depth_scale=(unsigned)IR;
        gpu_model_depth_barrier();
    }
    int page_y=g.ofy?256*IR:0;
    world_roi_x0=rx0*IR;world_roi_x1=(rx1+1)*IR-1;world_roi_y0=page_y+ry0*IR;world_roi_y1=page_y+(ry1+1)*IR-1;
    model_depth_owner=MODEL_DEPTH_WORLD_OWNER;model_depth_face=0;model_depth_world=1;
    ++world_depth_admitted;return 1;
}
/* Publish a WORLD triangle's conservative pixel bounds before rasterizing,
 * so its per-pixel depth writes share no state across row slices. */
static void world_depth_bounds(const WorldFinePoint *p) {
    int64_t minx=p[0].x,maxx=p[0].x,miny=p[0].y,maxy=p[0].y;
    for(int i=1;i<3;i++) {
        if(p[i].x<minx)minx=p[i].x;if(p[i].x>maxx)maxx=p[i].x;
        if(p[i].y<miny)miny=p[i].y;if(p[i].y>maxy)maxy=p[i].y;
    }
    int x0=(int)((minx*IR)>>16),x1=(int)((maxx*IR)>>16)+1,y0=(int)((miny*IR)>>16),y1=(int)((maxy*IR)>>16)+1;
    if(x0<g.dax1*IR)x0=g.dax1*IR;if(x1>(g.dax2+1)*IR-1)x1=(g.dax2+1)*IR-1;
    if(y0<g.day1*IR)y0=g.day1*IR;if(y1>(g.day2+1)*IR-1)y1=(g.day2+1)*IR-1;
    if(x0<world_roi_x0)x0=world_roi_x0;if(x1>world_roi_x1)x1=world_roi_x1;
    if(y0<world_roi_y0)y0=world_roi_y0;if(y1>world_roi_y1)y1=world_roi_y1;
    if(x0>x1||y0>y1)return;
    int page=g.ofy?256:0;
    model_depth_bound_write(page,x0,y0);model_depth_bound_write(page,x1,y1);
    model_depth_has_samples=1;
}
static void model_depth_triangle(const WorldFinePoint *p,const world_precision_vertex *v) {
    model_depth_plane_valid=0;
    double ax=(double)p[0].x*IR/65536,ay=(double)p[0].y*IR/65536;
    double bx=(double)p[1].x*IR/65536,by=(double)p[1].y*IR/65536;
    double cx=(double)p[2].x*IR/65536,cy=(double)p[2].y*IR/65536;
    double az=1/v[0].z,bz=1/v[1].z,cz=1/v[2].z;
    double d=(bx-ax)*(cy-ay)-(by-ay)*(cx-ax);
    if(!isfinite(d)||d==0)return;
    model_depth_plane[0]=((bz-az)*(cy-ay)-(cz-az)*(by-ay))/d;
    model_depth_plane[1]=((bx-ax)*(cz-az)-(cx-ax)*(bz-az))/d;
    model_depth_plane[2]=az-model_depth_plane[0]*ax-model_depth_plane[1]*ay;
    model_depth_plane_valid=isfinite(model_depth_plane[0])&&isfinite(model_depth_plane[1])&&isfinite(model_depth_plane[2]);
}
#endif
#ifdef A2_NATIVE_MESH
static int original_shadow_raster(int count,int command) {
    (void)command;
    if(!model_depth_enabled || a2_mesh_live_enabled || (count!=3&&count!=4) ||
       !world_primitive_valid)return 0;
    for(unsigned i=0;i<(unsigned)count;i++)if(world_vertices[i].producer_pc!=0x800155d8u ||
       world_vertices[i].projection_kind!=WORLD_PROJECTION_NATIVE_Q16)return 0;
    ++model_shadow_seen;
    return 1;
}
static int model_shadow_admit(void) {
    if(g.texwin || (fifo[0]>>24)!=0x2e || IR<2 || IR>4 || !world_camera_enabled || g.ofx!=0 || (g.ofy!=0&&g.ofy!=256) ||
       g.dax1!=0 || g.dax2!=319 || g.day1!=g.ofy || g.day2!=g.ofy+215)return 0;
#ifdef A2_HD_FONTS
    if(hd_matches_active())return 0;
#endif
    for(int i=1;i<fifo_n;i++)if(fifo_source[i]!=fifo_source[0]+4u*i)return 0;
    model_shadow_camera_owner=0;model_shadow_camera_matches=0;
    int valid=a2_world_shadow_geometry(world_vertices,4,a2_wide(),fifo_source[0],fifo,(unsigned)fifo_n,&model_shadow_geometry);
    if(valid)++model_shadow_admitted;
    return valid;
}
static int model_shadow_fine_points(WorldFinePoint out[4]) {
    WorldFinePoint points[4];
    const A2WorldShadowGeometry *s=&model_shadow_geometry;
    uint32_t words[4];
    for(unsigned i=0;i<4;i++) {
        double x=s->x[i],y=s->y[i],z=s->z[i];
        if(!isfinite(x)||!isfinite(y)||!isfinite(z)||x< -1024||x>=1024||
           y< -1024||y>=1024||z<1||z>=65536)return 0;
        points[i]=(WorldFinePoint){(int64_t)floor(x*65536),(int64_t)floor(y*65536)};
        words[i]=world_vertices[i].native_word;
    }
    if(!world_precision_raster_extent(words,4))return 0;
    for(unsigned i=0;i<4;i++)projection_audit_point(0x800155d8u,s->x[i],s->y[i],words[i]);
    /* Coverage and depth containment must use exactly the same Q16 edges.
     * Otherwise a rounded fringe has no physical plane and shades models. */
    for(unsigned i=0;i<4;i++) {
        model_shadow_geometry.x[i]=(double)points[i].x/65536;
        model_shadow_geometry.y[i]=(double)points[i].y/65536;
        out[i]=(WorldFinePoint){points[i].x+(int64_t)g.ofx*65536,
                               points[i].y+(int64_t)g.ofy*65536};
    }
    return 1;
}
static void model_shadow_triangle(unsigned first) {
    /* The legacy and physical split diagonals need not coincide. Build
     * the entire certified quad once; both native halves query it. */
    if(first)return;
    model_depth_plane_valid=0;
    memset(model_shadow_triangles,0,sizeof model_shadow_triangles);
    const A2WorldShadowGeometry *s=&model_shadow_geometry;
    for(first=0;first<2;first++) {
    double ax=(s->x[first]+g.ofx)*IR,ay=(s->y[first]+g.ofy)*IR;
    double bx=(s->x[first+1]+g.ofx)*IR,by=(s->y[first+1]+g.ofy)*IR;
    double cx=(s->x[first+2]+g.ofx)*IR,cy=(s->y[first+2]+g.ofy)*IR;
    double az=1/s->z[first],bz=1/s->z[first+1],cz=1/s->z[first+2];
    double d=(bx-ax)*(cy-ay)-(by-ay)*(cx-ax);
    if(!isfinite(d)||fabs(d)<1e-8)continue;
    /* Preserve native edge coverage, but never use an extrapolated
     * physical plane to reject a sample outside the source triangle. */
    double (*model_shadow_barycentric)[3]=model_shadow_triangles[first].barycentric;
    double *model_depth_plane=model_shadow_triangles[first].plane;
    model_shadow_barycentric[0][0]=(cy-ay)/d;
    model_shadow_barycentric[0][1]=(ax-cx)/d;
    model_shadow_barycentric[0][2]=-(model_shadow_barycentric[0][0]*ax+model_shadow_barycentric[0][1]*ay);
    model_shadow_barycentric[1][0]=(ay-by)/d;
    model_shadow_barycentric[1][1]=(bx-ax)/d;
    model_shadow_barycentric[1][2]=-(model_shadow_barycentric[1][0]*ax+model_shadow_barycentric[1][1]*ay);
    model_depth_plane[0]=((bz-az)*(cy-ay)-(cz-az)*(by-ay))/d;
    model_depth_plane[1]=((bx-ax)*(cz-az)-(cx-ax)*(bz-az))/d;
    model_depth_plane[2]=az-model_depth_plane[0]*ax-model_depth_plane[1]*ay;
    model_shadow_triangles[first].valid=isfinite(model_depth_plane[0])&&isfinite(model_depth_plane[1])&&isfinite(model_depth_plane[2]);
    model_depth_plane_valid|=model_shadow_triangles[first].valid;
    }
}
#endif
static int world_floor_q16(int64_t value) {
    return (int)(value/65536-(value<0 && value%65536!=0));
}
static double world_estimate(__int128 numerator,double inverse_area) {
    /* Avoid the costly __floattidf runtime conversion on arm64. */
    unsigned __int128 magnitude=numerator<0?(unsigned __int128)-numerator:(unsigned __int128)numerator;
    double estimate=((double)(uint64_t)(magnitude>>64)*0x1p64+(double)(uint64_t)magnitude)*inverse_area;
    return numerator<0?-estimate:estimate;
}
static int world_quotient_correct(__int128 numerator,int64_t area,int quotient) {
    /* Owned-edge interpolation has |quotient|<=65280 and area<2^60.
     * Double's rounding error is far below one quotient unit. Estimate
     * without __divti3, then correct against the exact signed remainder;
     * this preserves C truncation even immediately beside an integer. */
    __int128 remainder=numerator-(__int128)quotient*area;
    if(numerator>=0) {
        if(remainder<0)--quotient;
        else if(remainder>=area)++quotient;
    } else {
        if(remainder>0)++quotient;
        else if(remainder<=-(__int128)area)--quotient;
    }
    return quotient;
}
typedef struct {int64_t quotient,remainder;} WorldFineValue,WorldFineStep;
static WorldFineStep world_fine_step(__int128 delta,int64_t area) {
    /* One signed division per triangle/attribute, never per covered pixel.
     * Use floor for the gradient, leaving its remainder in[0,area). The
     * Q16 coordinate/attribute bounds keep |delta|<2^61. */
    int64_t quotient=(int64_t)(delta/area);
    int64_t remainder=(int64_t)(delta-(__int128)quotient*area);
    if(remainder<0){--quotient;remainder+=area;}
    return (WorldFineStep){quotient,remainder};
}
static WorldFineValue world_fine_value(__int128 numerator,int64_t area,double inverse_area) {
    int quotient=world_quotient_correct(numerator,area,(int)world_estimate(numerator,inverse_area));
    return (WorldFineValue){quotient,(int64_t)(numerator-(__int128)quotient*area)};
}
static void world_fine_advance(WorldFineValue *value,WorldFineStep step,int64_t area) {
    /* Owned attributes are nonnegative, so floor equals the old truncation.
     * Both remainders are below area: one carry suffices and fits int64. */
    value->quotient+=step.quotient;value->remainder+=step.remainder;
    if(value->remainder>=area){value->remainder-=area;++value->quotient;}
}

/* Guarded affine UV recurrence. Requires IEEE binary64 round-to-nearest
 * without fast-math/reassociation; see reports/q16-uv-floating-proof-2026-09-06.md.
 * Owned rows have at most4096 pixels and UV in[0,65280]. Accumulated
 * error is <3e-8; values within2^-20 of an integer use exact correction.
 * Keep cold numerators separate so only their addresses escape the loop. */
typedef struct { double increment; int integral; } WorldFloatStep;
typedef struct { __int128 numerator,delta; } WorldFloatCold;
typedef struct { double value,increment,guard; } WorldFloatValue;
#ifdef A2_WORLD_FP_STATS
static uint64_t world_fp_samples,world_fp_guarded,world_fp_integral;
#endif
static WorldFloatStep world_float_step(__int128 delta,int64_t area,WorldFineStep exact) {
    return (WorldFloatStep){exact.remainder?(double)delta/(double)area:(double)exact.quotient,
                            exact.remainder==0};
}
static WorldFloatValue world_float_value(__int128 numerator,__int128 delta,int64_t area,
                                        WorldFloatStep step,unsigned width) {
    int integral=step.integral||width==1;
    double value=integral?world_fine_value(numerator,area,1.0/(double)area).quotient:
                          (double)numerator/(double)area;
    (void)delta;
    return (WorldFloatValue){value,step.increment,integral?-1.0:0x1p-20};
}
__attribute__((noinline))
static int world_float_correct(const WorldFloatCold *value,unsigned x,int64_t area,int candidate) {
    return world_quotient_correct(value->numerator+(__int128)x*value->delta,area,candidate);
}
static inline int world_float_sample(const WorldFloatValue *value,const WorldFloatCold *cold,unsigned x,int64_t area) {
    int candidate=(int)value->value;
    double fraction=value->value-candidate;
#ifdef A2_WORLD_FP_STATS
    world_fp_samples++;world_fp_integral+=value->guard<0;
#endif
    if(fraction<=value->guard||fraction>=1.0-value->guard) {
#ifdef A2_WORLD_FP_STATS
        world_fp_guarded++;
#endif
        return world_float_correct(cold,x,area,candidate);
    }
    return candidate;
}

/* A separately compiled ordinary opaque row keeps the common affine loop's
 * live registers independent of HD, depth, minification and blend machinery.
 * Admission is per row; its cache and guarded UV recurrence are unchanged.
 * Every call is synchronous and no native VRAM write occurs in this loop. */
__attribute__((noinline))
static void world_fine_opaque_row(uint16_t *destination,unsigned width,int64_t area,
    WorldFineValue vr,WorldFineValue vg,WorldFineValue vb,
    WorldFineStep sr,WorldFineStep sg,WorldFineStep sb,
    WorldFloatValue vu,WorldFloatValue vv,const WorldFloatCold *cu,const WorldFloatCold *cv,
    FineTexCache *cache) {
    for(unsigned x=0;x<width;x++,destination++) {
        int red=(int)vr.quotient,green=(int)vg.quotient,blue=(int)vb.quotient;
        int u=world_float_sample(&vu,cu,x,area),v=world_float_sample(&vv,cv,x,area);
        world_fine_advance(&vr,sr,area);world_fine_advance(&vg,sg,area);world_fine_advance(&vb,sb,area);
        if(x+1<width){vu.value+=vu.increment;vv.value+=vv.increment;}
        uint16_t texel=sample_tex_cached_impl(u-128,v-128,cache,1);
        put_fine_pixel_impl(destination,red,green,blue,0,1,texel,0,FINE_PIXEL_ORDINARY);
    }
}

static int world_span_edge(int64_t weight,int64_t step,int owns,int *left,int *right) {
    int threshold=owns?0:1;
    if(step>0) {
        if(weight<threshold) {
            int64_t first=(threshold-weight+step-1)/step;
            if(first>*right)return 0;
            if(first>*left)*left=(int)first;
        }
    } else if(step<0) {
        if(weight<threshold)return 0;
        int64_t last=(weight-threshold)/-step;
        if(last<*left)return 0;
        if(last<*right)*right=(int)last;
    } else if(weight<threshold)return 0;
    return *left<=*right;
}
/* Diagnostic only. The complete primitive is checked before either quad
 * half renders. Keep the default and all untracked/2D paths affine. Depth
 * comes from the validated GTE sidecar, never from a screen-XY lookup. */
static int world_perspective_depths(double *inverse,int count,int tex) {
    static int enabled=-1;
    if(enabled<0) {
        const char *value=getenv("A2_WORLD_PERSPECTIVE");
        enabled=value&&!strcmp(value,"1");
    }
    if(!enabled || !tex || ir_init()<2)return 0;
#ifdef A2_HD_FONTS
    if(hd_matches_active())return 0;
#endif
    int equal=1;
    for(int i=0;i<count;i++) {
        double z=world_vertices[i].z;
        /* RTPS supplies an unsaturated positive Q12 depth. These bounds
         * also keep every weighted reciprocal/product finite even if a
         * diagnostic or malformed tag supplied an extreme double. */
        if(!isfinite(z) || z<1.0/4096.0 || z>=65536.0)return 0;
        inverse[i]=1.0/z;
        if(i&&z!=world_vertices[0].z)equal=0;
    }
    return !equal; /* Exact old integer interpolation for constant depth. */
}
#ifdef A2_NATIVE_MESH
/* Depth follows the actual raster coordinates. A validated quad can use the
 * integer fine raster when one native half degenerates; its surviving half
 * still has proven camera depth. Never reuse another half's plane. */
static void mesh_depth_setup(double ax,double ay,double bx,double by,double cx,double cy) {
    mesh_depth_valid=0;
    if(!a2_mesh_live_active||mesh_pixel_kind!=A2_COMPOSITE_WORLD)return;
    if(mesh_billboard_depth>=1 && mesh_billboard_depth<65536 && isfinite(mesh_billboard_depth)) {
        mesh_depth_plane[0]=mesh_depth_plane[1]=0;
        mesh_depth_plane[2]=65536.0/65535.0-(65536.0/65535.0)/mesh_billboard_depth;
        mesh_depth_valid=1;return;
    }
    double z[3];
    for(unsigned i=0;i<3;i++) {
        double camera_z=mesh_vertex_depth[i];
        if(!isfinite(camera_z)||camera_z<1||camera_z>=65536)return;
        z[i]=65536.0/65535.0-(65536.0/65535.0)/camera_z;
    }
    double determinant=(bx-ax)*(cy-ay)-(cx-ax)*(by-ay);
    if(!isfinite(determinant)||fabs(determinant)<=1e-12)return;
    mesh_depth_plane[0]=((z[1]-z[0])*(cy-ay)-(z[2]-z[0])*(by-ay))/determinant;
    mesh_depth_plane[1]=((bx-ax)*(z[2]-z[0])-(cx-ax)*(z[1]-z[0]))/determinant;
    mesh_depth_plane[2]=z[0]-mesh_depth_plane[0]*ax-mesh_depth_plane[1]*ay;
    mesh_depth_valid=1;
}
#endif
#ifdef A2_NATIVE_MESH
#include "model_minify.inc"
#endif
#define A2_FINE_PARALLEL_SUPPORT 1
#ifdef __APPLE__
#include <dispatch/dispatch.h>
#endif
static uint64_t fine_parallel_dispatches,fine_parallel_slices;
static int fine_parallel_enabled=-1;
static void fine_parallel_stats(void) {
    fprintf(stderr,"fine-parallel: dispatches=%llu slices=%llu\n",
        (unsigned long long)fine_parallel_dispatches,(unsigned long long)fine_parallel_slices);
}
static int fine_parallel_admit(int width,int height,int hd_active) {
#if defined(__APPLE__) && !defined(A2_GPU_RECT_TEST) && !defined(A2_WORLD_FP_STATS) && !defined(A2_MODEL_DEPTH_BOUNDS_TEST)
    if(fine_parallel_enabled<0) {
        const char *v=getenv("A2_FINE_PARALLEL");fine_parallel_enabled=v&&!strcmp(v,"1");
        if(getenv("A2_FINE_PARALLEL_PROFILE"))atexit(fine_parallel_stats);
    }
    if(!fine_parallel_enabled||width<1||height<32||(int64_t)width*height<65536||hd_active)return 0;
#ifdef A2_NATIVE_MESH
    if(a2_mesh_live_enabled||a2_mesh_live_active||mesh_pixel_kind==A2_COMPOSITE_OWNED)return 0;
    /* WORLD depth writes are per-pixel; model tests mutate shared counters. */
    if((model_depth_plane_valid&&!model_depth_world)||model_minify_pair)return 0;
#endif
    /* Every worker must see an initialized read-only diagnostic setting.
     * Active logging and mutable test counters retain serial execution. */
    fine_filter_debug_init();if(fine_filter_debug>0)return 0;
    return 1;
#else
    (void)width;(void)height;(void)hd_active;return 0;
#endif
}
#ifdef A2_GPU_FINE
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
static int fine_gpu_minify_offsets(const ModelMinifyFootprint *source,A2FineMinify *out) {
    *out=(A2FineMinify){0};
    for(unsigned i=0;i<source->count;i++)for(unsigned axis=0;axis<2;axis++) {
        double value=axis?source->v[i]:source->u[i];
        if(!isfinite(value))return 0;
        if(value<=-65280)out->offsets[i][axis]=-65280;
        else if(value>=65280)out->offsets[i][axis]=65280;
        else {
            double integral=floor(value),fraction=value-integral;
            /* uQ8 is an integer in [0,65280]. Addition has error <=2^-37
             * below 2^17; these margins prove floor(u+offset)==u+floor(offset).
             * Exact integer offsets need no margin. Ambiguous cases stay CPU. */
            if(fraction!=0 && !(fraction>0x1p-36&&fraction<1.0-0x1p-36))return 0;
            out->offsets[i][axis]=(int32_t)integral;
        }
    }
    out->count=source->count;return 1;
}
static int fine_gpu_minify_certificate(int x,int y,size_t *index) {
    if(!model_depth_plane_valid||!model_depth_pixels||!model_minify_keys||model_minify_key_count!=model_depth_count)return 0;
    int page=y>=256*IR?256:0,local_y=y-page*IR;
    if(x>=320*IR||local_y<0||local_y>=216*IR)return 0;
    *index=(size_t)(local_y+(page?216*IR:0))*320*IR+x;
    const ModelDepthPixel *prior=&model_depth_pixels[*index];
    return prior->stamp==model_depth_stamp&&model_minify_keys[*index]==model_minify_pair&&
        prior->owner==model_depth_owner&&prior->face==model_depth_face;
}
/* Visibility does not read fine color. Keep the established CPU double-depth
 * and camera ownership rules, while color commands stay ordered on the GPU.
 * Filtering's nearest native texel determines both transparency and STP;
 * four-tap color, RGB interpolation and blending are unnecessary here. */
static void fine_gpu_visibility(Vtx a,Vtx b,Vtx c,WorldFinePoint p,WorldFinePoint q,WorldFinePoint r,
    int x0,int y0,int x1,int y1,int tex,int semi,int filtered,uint8_t *mask,
    const A2FineMinify *minify,uint8_t *minify_mask,const double *iz) {
    int64_t area=world_edge(p,q,r);
    double za=iz?iz[0]:0,zb=iz?iz[1]:0,zc=iz?iz[2]:0;
    if(area<0){WorldFinePoint point=q;q=r;r=point;Vtx v=b;b=c;c=v;area=-area;double z=zb;zb=zc;zc=z;}
    if(!area)return;
    size_t stride=((size_t)(x1-x0+1)+7)/8;
    /* Mask is in caller clip coordinates, including pixels outside geometric
     * coverage. The GPU's exact edge test still excludes those pixels. */
    if(mask)memset(mask,255,stride*(size_t)(y1-y0+1));
    if(!model_depth_plane_valid&&!model_depth_has_samples)return;
    int own0=world_top_left(p,q),own1=world_top_left(q,r),own2=world_top_left(r,p);
    int64_t dx0=(p.y-q.y)*65536,dx1=(q.y-r.y)*65536,dx2=(r.y-p.y)*65536;
    int64_t dy0=(q.x-p.x)*65536,dy1=(r.x-q.x)*65536,dy2=(p.x-r.x)*65536;
    WorldFinePoint origin={(int64_t)x0*65536,(int64_t)y0*65536};
    int64_t row0=world_edge(p,q,origin),row1=world_edge(q,r,origin),row2=world_edge(r,p,origin);
    __int128 uv_scale=filtered?256:1;
    __int128 du=((__int128)dx1*a.u+(__int128)dx2*b.u+(__int128)dx0*c.u)*uv_scale;
    __int128 dv=((__int128)dx1*a.v+(__int128)dx2*b.v+(__int128)dx0*c.v)*uv_scale;
    WorldFloatStep step_u={0,1},step_v={0,1};
    if(tex){step_u=world_float_step(du,area,world_fine_step(du,area));step_v=world_float_step(dv,area,world_fine_step(dv,area));}
    for(int y=y0;y<=y1;y++,row0+=dy0,row1+=dy1,row2+=dy2) {
        int first=0,last=x1-x0;
        if(!world_span_edge(row0,dx0,own0,&first,&last)||!world_span_edge(row1,dx1,own1,&first,&last)||
           !world_span_edge(row2,dx2,own2,&first,&last))continue;
        /* Only retirement may use old bounds. A current plane can acquire
         * new depth anywhere, even where no earlier model has written. */
        if(!model_depth_plane_valid) {
            int left=x1+1,right=x0-1;
            for(unsigned i=0;i<2;i++)if(model_depth_bounds[i].valid&&y>=model_depth_bounds[i].y0&&y<=model_depth_bounds[i].y1) {
                if(left>model_depth_bounds[i].x0)left=model_depth_bounds[i].x0;
                if(right<model_depth_bounds[i].x1)right=model_depth_bounds[i].x1;
            }
            if(first<left-x0)first=left-x0;if(last>right-x0)last=right-x0;
            if(first>last)continue;
        }
        int64_t w0=row0+dx0*first,w1=row1+dx1*first,w2=row2+dx2*first;
        unsigned width=(unsigned)(last-first+1);
        WorldFloatCold cold_u={((__int128)w1*a.u+(__int128)w2*b.u+(__int128)w0*c.u)*uv_scale,du};
        WorldFloatCold cold_v={((__int128)w1*a.v+(__int128)w2*b.v+(__int128)w0*c.v)*uv_scale,dv};
        WorldFloatValue vu={0},vv={0};
        if(tex){vu=world_float_value(cold_u.numerator,du,area,step_u,width);vv=world_float_value(cold_v.numerator,dv,area,step_v,width);}
        for(int x=x0+first;x<=x0+last;x++) {
            uint16_t texel=0;int actual_semi=semi;
            if(tex) {
                unsigned offset=(unsigned)(x-x0-first);
                int u=world_float_sample(&vu,&cold_u,offset,area),v=world_float_sample(&vv,&cold_v,offset,area);
                if(x<x0+last){vu.value+=vu.increment;vv.value+=vv.increment;}
                if(iz) { /* Same perspective UV as the CPU/GPU raster. */
                    double ww0=(double)(w0+dx0*(int64_t)offset),ww1=(double)(w1+dx1*(int64_t)offset),ww2=(double)(w2+dx2*(int64_t)offset);
                    double wa=ww1*za,wb=ww2*zb,wc=ww0*zc,reciprocal=1.0/(wa+wb+wc);
                    double pu=(a.u==b.u&&b.u==c.u)?a.u:(wa*a.u+wb*b.u+wc*c.u)*reciprocal;
                    double pv=(a.v==b.v&&b.v==c.v)?a.v:(wa*a.v+wb*b.v+wc*c.v)*reciprocal;
                    u=filtered?(int)(pu*256.0):(int)pu;v=filtered?(int)(pv*256.0):(int)pv;
                }
                size_t key_index;
                /* A certified minified overlay consumes its opaque base even
                 * with a transparent center or with no contributing taps.
                 * Inspect it before ordinary alpha/depth; color stays queued. */
                if(minify->count&&fine_gpu_minify_certificate(x,y,&key_index)) {
                    minify_mask[(size_t)(y-y0)*stride+(unsigned)(x-x0)/8]|=(uint8_t)(1u<<((unsigned)(x-x0)&7));
                    for(unsigned i=0;i<minify->count;i++) {
                        int su=u+minify->offsets[i][0],sv=v+minify->offsets[i][1];
                        if(su<0)su=0;if(su>65280)su=65280;if(sv<0)sv=0;if(sv>65280)sv=65280;
                        su=(fine_uv_coordinate(su-128,0)+128)>>8;sv=(fine_uv_coordinate(sv-128,1)+128)>>8;
                        if(sample_tex(su,sv)){model_minify_keys[key_index]=0;break;}
                    }
                    continue;
                }
                if(filtered&&soft_shadow_active){texel=soft_shadow_texel(u-128,v-128);if(!texel)continue;}
                else {
                if(filtered){u=(fine_uv_coordinate(u-128,0)+128)>>8;v=(fine_uv_coordinate(v-128,1)+128)>>8;}
                texel=sample_tex(u,v);if(!texel)continue;
                }
                if(!(texel&0x8000))actual_semi=0;
            }
            if(!model_depth_sample(SHADOW+(size_t)y*IR_W+x,actual_semi)&&mask)
                mask[(size_t)(y-y0)*stride+(unsigned)(x-x0)/8]&=(uint8_t)~(1u<<((unsigned)(x-x0)&7));
        }
    }
}
#endif
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
/* WORLD depth recording has only per-pixel writes (see model_depth_sample):
 * large faces split into disjoint row bands. Texture reads are VRAM-only. */
typedef struct {Vtx a,b,c;WorldFinePoint p,q,r;int x0,y0,x1,y1,tex,filtered;double iz[3];int perspective;} WorldDepthWork;
static void world_depth_band(void *opaque,size_t index) {
    const WorldDepthWork *w=opaque;int rows=w->y1-w->y0+1;
    int y0=w->y0+(int)(rows*index/8),y1=w->y0+(int)(rows*(index+1)/8)-1;
    A2FineMinify none={0};
    if(y0<=y1)fine_gpu_visibility(w->a,w->b,w->c,w->p,w->q,w->r,w->x0,y0,w->x1,y1,w->tex,0,w->filtered,NULL,&none,NULL,w->perspective?w->iz:NULL);
}
static void world_gpu_depth(Vtx a,Vtx b,Vtx c,WorldFinePoint p,WorldFinePoint q,WorldFinePoint r,
                            int x0,int y0,int x1,int y1,int tex,int filtered,const double *iz) {
    if(x0<world_roi_x0)x0=world_roi_x0;if(x1>world_roi_x1)x1=world_roi_x1;
    if(y0<world_roi_y0)y0=world_roi_y0;if(y1>world_roi_y1)y1=world_roi_y1;
    if(x0>x1||y0>y1)return;
    WorldDepthWork work={a,b,c,p,q,r,x0,y0,x1,y1,tex,filtered,{0,0,0},iz!=NULL};
    if(iz)memcpy(work.iz,iz,sizeof work.iz);
#ifdef __APPLE__
    if((int64_t)(x1-x0+1)*(y1-y0+1)>=65536&&y1-y0>=32) {
        dispatch_apply_f(8,dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),&work,world_depth_band);
        return;
    }
#endif
    world_depth_band(&work,0);world_depth_band(&work,1);world_depth_band(&work,2);world_depth_band(&work,3);
    world_depth_band(&work,4);world_depth_band(&work,5);world_depth_band(&work,6);world_depth_band(&work,7);
}
#endif
static int fine_gpu_triangle(Vtx a,Vtx b,Vtx c,WorldFinePoint p,WorldFinePoint q,WorldFinePoint r,
                             int x0,int y0,int x1,int y1,int gouraud,int tex,int semi,int filtered,
                             int perspective,int hd_active,int precise,const double *iz) {
    fine_gpu_start();if(!fine_gpu)return 0;
    fine_gpu_attempts++;int depth_visibility=0,depth_mask=0;A2FineMinify minify={0};
#ifdef A2_NATIVE_MESH
    if(a2_mesh_live_enabled||a2_mesh_live_active||a2_mesh_live_writes_watched||mesh_pixel_kind==A2_COMPOSITE_OWNED) {
        fine_gpu_fallbacks[0]++;return 0;
    }
#ifdef A2_WORLD_PRECISION
    if(model_depth_enabled) {
        /* WORLD faces only record depth and are never rejected: no mask. */
        /* A physical ground shadow can be rejected per pixel (decal rules):
         * the GPU must receive that mask, as for model faces. */
        if(model_depth_ground_shadow){depth_visibility=depth_mask=1;}
        if(model_depth_plane_valid){depth_visibility=1;depth_mask=!model_depth_world;fine_gpu_depth_counts[0]++;fine_gpu_depth_bbox[0]+=(uint64_t)(x1-x0+1)*(y1-y0+1);}
        for(unsigned i=0;i<2;i++)if(model_depth_bounds[i].valid&&y0<=model_depth_bounds[i].y1&&
            y1>=model_depth_bounds[i].y0&&x0<=model_depth_bounds[i].x1&&x1>=model_depth_bounds[i].x0) {
            depth_visibility=1;
            if(!depth_mask){fine_gpu_depth_counts[1]++;fine_gpu_depth_bbox[1]+=(uint64_t)(x1-x0+1)*(y1-y0+1);}break;
        }
    }
    /* Pair identity only enables the experiment. The CPU actually changes
     * shading only for opaque, filtered, precise texture footprints >1 texel. */
    if(precise&&model_depth_enabled&&model_depth_plane_valid&&model_minify_pair&&tex&&filtered&&!semi&&!perspective&&!hd_active) {
        WorldFinePoint mp=p,mq=q,mr=r;Vtx ma=a,mb=b,mc=c;
        int64_t area=world_edge(mp,mq,mr);
        if(area<0){WorldFinePoint point=mq;mq=mr;mr=point;Vtx vertex=mb;mb=mc;mc=vertex;area=-area;}
        if(area) {
            int64_t dx0=(mp.y-mq.y)*65536,dx1=(mq.y-mr.y)*65536,dx2=(mr.y-mp.y)*65536;
            int64_t dy0=(mq.x-mp.x)*65536,dy1=(mr.x-mq.x)*65536,dy2=(mp.x-mr.x)*65536;
            __int128 du=((__int128)dx1*ma.u+(__int128)dx2*mb.u+(__int128)dx0*mc.u)*256;
            __int128 dv=((__int128)dx1*ma.v+(__int128)dx2*mb.v+(__int128)dx0*mc.v)*256;
            ModelMinifyFootprint footprint=model_minify_footprint((double)du/(double)area/256,
                ((double)dy1*ma.u+(double)dy2*mb.u+(double)dy0*mc.u)/(double)area,
                (double)dv/(double)area/256,
                ((double)dy1*ma.v+(double)dy2*mb.v+(double)dy0*mc.v)/(double)area);
            if(footprint.count&&!fine_gpu_minify_offsets(&footprint,&minify)){fine_gpu_fallbacks[2]++;return 0;}
        }
    }
#endif
#endif
    if(hd_active||(perspective&&!iz)){fine_gpu_fallbacks[2]++;return 0;}
    A2FineParams params={0};Vtx v[3]={a,b,c};WorldFinePoint point[3]={p,q,r};
    for(unsigned i=0;i<3;i++)params.p[i]=(A2FineVertex){point[i].x,point[i].y,v[i].r,v[i].gr,v[i].b,v[i].u,v[i].v,0};
    params.clip[0]=x0;params.clip[1]=y0;params.clip[2]=x1;params.clip[3]=y1;
    params.state[0]=cur_tpage;params.state[1]=cur_clut;params.state[2]=g.texwin;
    params.state[3]=gouraud|(tex<<1)|(semi<<2)|(filtered<<3)|((soft_shadow_active&&tex&&filtered)?16u:0u);
    params.uv[0]=fine_uv_low[0];params.uv[1]=fine_uv_low[1];params.uv[2]=fine_uv_high[0];params.uv[3]=fine_uv_high[1];
    params.width=IR_W;params.height=IR_H;
    if(perspective&&tex) { /* Perspective-correct UV: per-vertex 1/z travels as float bits. */
        params.state[3]|=32u;
        for(unsigned i=0;i<3;i++){float f=(float)iz[i];memcpy(&params.p[i].pad,&f,sizeof f);}
    }
    char error[1024];uint8_t *mask=NULL,*minify_mask=NULL;int accepted=0;
    for(unsigned attempt=0;attempt<2&&!accepted;attempt++) {
        if(attempt)fine_gpu_sync();
        accepted=minify.count?a2_fine_gpu_enqueue_minified(fine_gpu,&params,GPU_VRAM,&minify,&mask,&minify_mask,error,sizeof error):
            depth_mask?a2_fine_gpu_enqueue_masked(fine_gpu,&params,GPU_VRAM,&mask,error,sizeof error):
            a2_fine_gpu_enqueue(fine_gpu,&params,GPU_VRAM,error,sizeof error);
    }
    if(!accepted){fine_gpu_fallbacks[3]++;return 0;}
    fine_gpu_pending=1;
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
    /* No backend call while filling its borrowed mask. Capacity/failure
     * checks precede all depth mutation; fallback never repeats a depth pass. */
    const double *vis_iz=perspective&&tex?iz:NULL;
    if(depth_visibility&&model_depth_plane_valid&&model_depth_world)world_gpu_depth(a,b,c,p,q,r,x0,y0,x1,y1,tex,filtered,vis_iz);
    else if(depth_visibility)fine_gpu_visibility(a,b,c,p,q,r,x0,y0,x1,y1,tex,semi,filtered,mask,&minify,minify_mask,vis_iz);
#endif
    fine_gpu_bbox_pixels+=(uint64_t)(x1-x0+1)*(y1-y0+1);return 1;
}
#endif
static void raster_tri_world_fine_slice(Vtx a,Vtx b,Vtx c,WorldFineTriangle triangle,
    int gouraud,int tex,int semi,int scale,const double *inverse_depth,int slice_y0,int slice_y1);
#ifdef __APPLE__
typedef struct {
    Vtx vertices[3];WorldFineTriangle triangle;
    int gouraud,tex,semi,scale,y0,y1;double inverse_depth[3];int perspective;
} FineRowWork;
static void fine_row_work(void *opaque,size_t index) {
    const FineRowWork *w=opaque;int rows=w->y1-w->y0+1;
    int y0=w->y0+(int)(rows*index/4),y1=w->y0+(int)(rows*(index+1)/4)-1;
    raster_tri_world_fine_slice(w->vertices[0],w->vertices[1],w->vertices[2],w->triangle,
        w->gouraud,w->tex,w->semi,w->scale,w->perspective?w->inverse_depth:NULL,y0,y1);
}
#endif
static void raster_tri_world_fine(Vtx a,Vtx b,Vtx c,WorldFineTriangle triangle,
    int gouraud,int tex,int semi,int scale,const double *inverse_depth) {
    raster_tri_world_fine_slice(a,b,c,triangle,gouraud,tex,semi,scale,inverse_depth,-1,-1);
}
static void raster_tri_world_fine_slice(Vtx a,Vtx b,Vtx c,WorldFineTriangle triangle,
    int gouraud,int tex,int semi,int scale,const double *inverse_depth,int slice_y0,int slice_y1) {
    const Vtx original[3]={a,b,c};const WorldFineTriangle source_triangle=triangle;

    /* Source coordinates lie in [-1024,1024), offsets in [-1024,1024),
     * and scale<=4. Every difference is <2^30 Q16 units, so two products
     * and their subtraction fit int64. Attribute products require128 bits. */
    if(scale<2 || scale>4) return;
    for(int i=0;i<3;i++) {triangle.p[i].x*=scale;triangle.p[i].y*=scale;}
#ifdef A2_NATIVE_MESH
    if(slice_y0<0)mesh_depth_setup((double)triangle.p[0].x/65536,(double)triangle.p[0].y/65536,
                     (double)triangle.p[1].x/65536,(double)triangle.p[1].y/65536,
                     (double)triangle.p[2].x/65536,(double)triangle.p[2].y/65536);
#endif
    WorldFinePoint p=triangle.p[0],q=triangle.p[1],r=triangle.p[2];
    double za=0,zb=0,zc=0;
    if(inverse_depth) {
        za=inverse_depth[0];zb=inverse_depth[1];zc=inverse_depth[2];
        if(za==zb&&zb==zc)inverse_depth=NULL;
    }
    int64_t area=world_edge(p,q,r);
    if(area<0) {
        WorldFinePoint point=q;q=r;r=point;Vtx v=b;b=c;c=v;area=-area;
        double z=zb;zb=zc;zc=z;
    }
    if(!area) return;
    double inverse_area=1.0/(double)area;
    int64_t minx=p.x,maxx=p.x,miny=p.y,maxy=p.y;
    const WorldFinePoint others[2]={q,r};
    for(int i=0;i<2;i++) {
        if(others[i].x<minx)minx=others[i].x;if(others[i].x>maxx)maxx=others[i].x;
        if(others[i].y<miny)miny=others[i].y;if(others[i].y>maxy)maxy=others[i].y;
    }
    int x0=world_floor_q16(minx),x1=world_floor_q16(maxx);
    int y0=world_floor_q16(miny),y1=world_floor_q16(maxy);
    if(x0<g.dax1*scale)x0=g.dax1*scale;
    if(x1>=(g.dax2+1)*scale)x1=(g.dax2+1)*scale-1;
    if(y0<g.day1*scale)y0=g.day1*scale;
    if(y1>=(g.day2+1)*scale)y1=(g.day2+1)*scale-1;
    if(x0>x1||y0>y1)return;
    /* Resolve lazy settings before publishing immutable primitive state. */
    int filtered=filter_on(),uv_shift=filtered?8:0,hd_active=0;
#ifdef A2_HD_FONTS
    hd_active=hd_matches_active();if(hd_active)uv_shift=8;
#endif
#ifdef A2_GPU_FINE
    double gpu_iz[3]={za,zb,zc};
    if(slice_y0<0&&fine_gpu_triangle(a,b,c,p,q,r,x0,y0,x1,y1,gouraud,tex,semi,filtered,
                                    tex&&inverse_depth!=NULL,hd_active,1,gpu_iz))return;
#endif
    if(slice_y0<0)fine_gpu_sync(); /* CPU fallback, before publishing worker slices. */
#ifdef __APPLE__
    if(slice_y0<0&&fine_parallel_admit(x1-x0+1,y1-y0+1,hd_active)) {
        FineRowWork work={{original[0],original[1],original[2]},source_triangle,
            gouraud,tex,semi,scale,y0,y1,{0,0,0},inverse_depth!=NULL};
        if(inverse_depth)memcpy(work.inverse_depth,inverse_depth,sizeof work.inverse_depth);
        ++fine_parallel_dispatches;fine_parallel_slices+=4;
        /* Synchronous and bounded: the next native polygon/VRAM write cannot
         * start until all four disjoint row slices have completed. */
        dispatch_apply_f(4,dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),&work,fine_row_work);
        return;
    }
#endif
    if(slice_y0>=0){if(y0<slice_y0)y0=slice_y0;if(y1>slice_y1)y1=slice_y1;if(y0>y1)return;}
    int own0=world_top_left(p,q),own1=world_top_left(q,r),own2=world_top_left(r,p);
    int64_t dx0=(p.y-q.y)*65536,dx1=(q.y-r.y)*65536,dx2=(r.y-p.y)*65536;
    int64_t dy0=(q.x-p.x)*65536,dy1=(r.x-q.x)*65536,dy2=(p.x-r.x)*65536;
    WorldFinePoint origin={(int64_t)x0*65536,(int64_t)y0*65536};
    int64_t row0=world_edge(p,q,origin),row1=world_edge(q,r,origin),row2=world_edge(r,p,origin);
    int perspective=tex&&inverse_depth!=NULL;
    int need_r=gouraud&&(a.r!=b.r||b.r!=c.r);
    int need_g=gouraud&&(a.gr!=b.gr||b.gr!=c.gr);
    int need_b=gouraud&&(a.b!=b.b||b.b!=c.b);
    int need_u=tex&&!perspective&&(a.u!=b.u||b.u!=c.u);
    int need_v=tex&&!perspective&&(a.v!=b.v||b.v!=c.v);
    __int128 uv_scale=(__int128)1<<uv_shift;
    __int128 dr=need_r?(__int128)dx1*a.r+(__int128)dx2*b.r+(__int128)dx0*c.r:0;
    __int128 dg=need_g?(__int128)dx1*a.gr+(__int128)dx2*b.gr+(__int128)dx0*c.gr:0;
    __int128 db=need_b?(__int128)dx1*a.b+(__int128)dx2*b.b+(__int128)dx0*c.b:0;
    __int128 du=need_u?((__int128)dx1*a.u+(__int128)dx2*b.u+(__int128)dx0*c.u)*uv_scale:0;
    __int128 dv=need_v?((__int128)dx1*a.v+(__int128)dx2*b.v+(__int128)dx0*c.v)*uv_scale:0;
#ifdef A2_NATIVE_MESH
    ModelMinifyFootprint minify={0};
    if(tex && filtered && !perspective && !semi && model_minify_pair
#ifdef A2_HD_FONTS
       && !hd_active
#endif
    )minify=model_minify_footprint((double)du/(double)area/256,
        ((double)dy1*a.u+(double)dy2*b.u+(double)dy0*c.u)/(double)area,
        (double)dv/(double)area/256,
        ((double)dy1*a.v+(double)dy2*b.v+(double)dy0*c.v)/(double)area);
#endif
    WorldFineStep zero_step={0,0};
    WorldFineStep step_r=need_r?world_fine_step(dr,area):zero_step;
    WorldFineStep step_g=need_g?world_fine_step(dg,area):zero_step;
    WorldFineStep step_b=need_b?world_fine_step(db,area):zero_step;
    WorldFineStep step_u=need_u?world_fine_step(du,area):zero_step;
    WorldFineStep step_v=need_v?world_fine_step(dv,area):zero_step;
    WorldFloatStep float_u={0,1},float_v={0,1};
    if(need_u)float_u=world_float_step(du,area,step_u);
    if(need_v)float_v=world_float_step(dv,area,step_v);
    FineTexCache cache;
    __int128 texel_step=(__int128)area*uv_scale;
    int cache_enabled=tex&&filtered&&!perspective&&du>-texel_step&&du<texel_step&&dv>-texel_step&&dv<texel_step;
    if(cache_enabled)for(unsigned i=0;i<64;i++)cache.cells[i].key=UINT32_MAX;
    int blend_mode=(cur_tpage>>5)&3;
    int ordinary=fine_pixel_ordinary();
    for(int y=y0;y<=y1;y++,row0+=dy0,row1+=dy1,row2+=dy2) {
        int first=0,last=x1-x0;
        if(!world_span_edge(row0,dx0,own0,&first,&last)||
           !world_span_edge(row1,dx1,own1,&first,&last)||
           !world_span_edge(row2,dx2,own2,&first,&last))continue;
        int64_t w0=row0+dx0*first,w1=row1+dx1*first,w2=row2+dx2*first;
        WorldFineValue vr={a.r,0},vg={a.gr,0},vb={a.b,0};
        if(need_r)vr=world_fine_value((__int128)w1*a.r+(__int128)w2*b.r+(__int128)w0*c.r,area,inverse_area);
        if(need_g)vg=world_fine_value((__int128)w1*a.gr+(__int128)w2*b.gr+(__int128)w0*c.gr,area,inverse_area);
        if(need_b)vb=world_fine_value((__int128)w1*a.b+(__int128)w2*b.b+(__int128)w0*c.b,area,inverse_area);
        uint16_t *destination=SHADOW+(size_t)y*IR_W+x0+first;
        int row_ordinary=ordinary||fine_pixel_ordinary_span(x0+first,y,x0+last);
        /* Select once per row. The ordinary affine loop carries neither
         * depth nor evolving edge weights; perspective needs no affine UV
         * steppers. Constant/unused channels require no gradient or advance. */
        if(perspective) {
            for(int x=x0+first;x<=x0+last;x++,destination++,w0+=dx0,w1+=dx1,w2+=dx2) {
                int red=(int)vr.quotient,green=(int)vg.quotient,blue=(int)vb.quotient;
                if(need_r)world_fine_advance(&vr,step_r,area);
                if(need_g)world_fine_advance(&vg,step_g,area);
                if(need_b)world_fine_advance(&vb,step_b,area);
                /* Positive owned-edge weights make D strictly positive.
                 * The primitive-wide GTE depth bounds keep all products
                 * finite. One reciprocal serves both UV attributes. */
                double wa=(double)w1*za,wb=(double)w2*zb,wc=(double)w0*zc;
                double reciprocal=1.0/(wa+wb+wc);
                /* A constant attribute is exact; a reciprocal roundoff just
                 * below its integer value must not select a different texel. */
                double u=(a.u==b.u&&b.u==c.u)?a.u:(wa*a.u+wb*b.u+wc*c.u)*reciprocal;
                double v=(a.v==b.v&&b.v==c.v)?a.v:(wa*a.v+wb*b.v+wc*c.v)*reciprocal;
                uint16_t texel;
                if(filtered)texel=sample_tex_fine((int)(u*256.0)-128,(int)(v*256.0)-128);
                else texel=sample_tex_present((int)u,(int)v);
                if(row_ordinary)put_fine_pixel_impl(destination,red,green,blue,semi,1,texel,blend_mode,FINE_PIXEL_ORDINARY);
                else put_fine_pixel(destination,red,green,blue,semi,1,texel,blend_mode);
            }
        } else {
            unsigned width=(unsigned)(last-first+1);
            WorldFloatValue vu={0},vv={0};
            WorldFloatCold cold_u={0},cold_v={0};
            if(tex) {
                cold_u=(WorldFloatCold){((__int128)w1*a.u+(__int128)w2*b.u+(__int128)w0*c.u)*uv_scale,du};
                cold_v=(WorldFloatCold){((__int128)w1*a.v+(__int128)w2*b.v+(__int128)w0*c.v)*uv_scale,dv};
                vu=world_float_value(cold_u.numerator,du,area,float_u,width);
                vv=world_float_value(cold_v.numerator,dv,area,float_v,width);
            }
            if(cache_enabled&&row_ordinary&&!semi&&!hd_active
#ifdef A2_NATIVE_MESH
               &&!minify.count
#endif
            ) {
                world_fine_opaque_row(destination,width,area,vr,vg,vb,step_r,step_g,step_b,
                    vu,vv,&cold_u,&cold_v,&cache);
                continue;
            }
            /* Constants at each call site let the compiler remove unused
             * attribute recurrence and texture work without five dynamic
             * per-pixel tests. Partly constant RGB retains zero steppers. */
#ifdef A2_HD_FONTS
#define WORLD_FINE_HD_PIXEL if(hd_active) { \
    if(put_hd_ui(x,y,red,green,blue,semi,u,v))continue; \
    if(!filtered){u/=256;v/=256;} \
}
#else
#define WORLD_FINE_HD_PIXEL ((void)0)
#endif
#ifdef A2_NATIVE_MESH
#define WORLD_FINE_MINIFY_PIXEL if(minify.count && model_minify_pixel(destination,red,green,blue,u,v,&minify))continue
#else
#define WORLD_FINE_MINIFY_PIXEL ((void)0)
#endif
#define WORLD_FINE_AFFINE_ROW(ADVANCE_RGB,TEXTURED) \
            for(int x=x0+first;x<=x0+last;x++,destination++) { \
                int red=(int)vr.quotient,green=(int)vg.quotient,blue=(int)vb.quotient; \
                int u=TEXTURED?world_float_sample(&vu,&cold_u,(unsigned)(x-x0-first),area):0, \
                    v=TEXTURED?world_float_sample(&vv,&cold_v,(unsigned)(x-x0-first),area):0; \
                /* Advance before an HD substitution can continue the loop; \
                 * the values above still belong to this exact pixel. */ \
                if(ADVANCE_RGB)world_fine_advance(&vr,step_r,area); \
                if(ADVANCE_RGB)world_fine_advance(&vg,step_g,area); \
                if(ADVANCE_RGB)world_fine_advance(&vb,step_b,area); \
                if(TEXTURED&&x<x0+last)vu.value+=vu.increment; \
                if(TEXTURED&&x<x0+last)vv.value+=vv.increment; \
                uint16_t texel=0; \
                if(TEXTURED) { \
                    WORLD_FINE_HD_PIXEL; \
                    WORLD_FINE_MINIFY_PIXEL; \
                    if(filtered&&soft_shadow_active)texel=soft_shadow_texel(u-128,v-128); \
                    else if(filtered)texel=cache_enabled?sample_tex_cached(u-128,v-128,&cache):sample_tex_fine(u-128,v-128); \
                    else texel=sample_tex_present(u,v); \
                } \
                if(row_ordinary)put_fine_pixel_impl(destination,red,green,blue,semi,TEXTURED,texel,blend_mode,FINE_PIXEL_ORDINARY); \
                else put_fine_pixel(destination,red,green,blue,semi,TEXTURED,texel,blend_mode); \
            }
            if(tex) {
                if(need_r||need_g||need_b) {WORLD_FINE_AFFINE_ROW(1,1)}
                else {WORLD_FINE_AFFINE_ROW(0,1)}
            } else {
                if(need_r||need_g||need_b) {WORLD_FINE_AFFINE_ROW(1,0)}
                else {WORLD_FINE_AFFINE_ROW(0,0)}
            }
#undef WORLD_FINE_AFFINE_ROW
#undef WORLD_FINE_MINIFY_PIXEL
#undef WORLD_FINE_HD_PIXEL
        }
    }
}
#endif

/* Intersect one exact top/left edge with a scanline. Coordinates are offsets
 * from that row's clipped left bound, so every performed divide has a
 * nonnegative numerator and a positive denominator. */
static inline int fine_span_edge(int64_t weight,int step,int owns,int *left,int *right) {
    int threshold=owns?0:1;
    if(step>0) {
        if(weight<threshold) {
            int first=(int)((threshold-weight+step-1)/step);
            if(first>*left)*left=first;
        }
    } else if(step<0) {
        if(weight<threshold)return 0;
        int last=(int)((weight-threshold)/-step);
        if(last<*right)*right=last;
    } else if(weight<threshold)return 0;
    return *left<=*right;
}

static void fine_vertex_rgb(Vtx *a,Vtx *b,Vtx *c,const uint32_t rgb[3]) {
    if(!rgb)return;
    Vtx *v[3]={a,b,c};
    for(unsigned i=0;i<3;i++) {
        v[i]->r=rgb[i]&255;v[i]->gr=(rgb[i]>>8)&255;v[i]->b=(rgb[i]>>16)&255;
    }
}
static void raster_tri_internal(Vtx a, Vtx b, Vtx c, int gouraud, int tex, int semi,
                                const WorldFineTriangle *precision,const double *inverse_depth,
                                const uint32_t *fine_rgb) {
    uint32_t colors[3];
    if(fine_rgb){memcpy(colors,fine_rgb,sizeof colors);fine_rgb=colors;}
#ifdef A2_NATIVE_MESH
    mesh_depth_valid=0;
#endif
#ifdef A2_WORLD_PRECISION
    WorldFineTriangle fine;
    double depth[3];
    if(precision)fine=*precision;
    if(inverse_depth)memcpy(depth,inverse_depth,sizeof depth);
#else
    (void)precision;
    (void)inverse_depth;
#endif
    int minx = a.x, maxx = a.x, miny = a.y, maxy = a.y;
    if (b.x < minx) minx = b.x; if (b.x > maxx) maxx = b.x;
    if (c.x < minx) minx = c.x; if (c.x > maxx) maxx = c.x;
    if (b.y < miny) miny = b.y; if (b.y > maxy) maxy = b.y;
    if (c.y < miny) miny = c.y; if (c.y > maxy) maxy = c.y;
#ifdef A2_INPUT_PROMPTS
    a2_input_prompts_vram_changed(minx,miny,maxx-minx+1,maxy-miny+1);
#endif
    gpu_tri_total++;
    if (maxx - minx > 1024 || maxy - miny > 512) {         /* GPU size limit */
        gpu_tri_rejected++;
        if (gpu_prim_log > 0) {
            gpu_prim_log--;
            fprintf(stderr, "REJ tri (%d,%d)(%d,%d)(%d,%d) tex=%d tpage=%03X\n",
                    a.x, a.y, b.x, b.y, c.x, c.y, tex,
                    (unsigned)(cur_tpage & 0xFFF));
        }
        return;
    }
    if (minx < g.dax1) minx = g.dax1;
    if (maxx > g.dax2) maxx = g.dax2;
    if (miny < g.day1) miny = g.day1;
    if (maxy > g.day2) maxy = g.day2;
    int64_t area = (int64_t)(b.x - a.x) * (c.y - a.y)
                 - (int64_t)(b.y - a.y) * (c.x - a.x);
    if (area == 0) {
#ifdef A2_WORLD_PRECISION
        /* Native VRAM has no coverage, but proven subpixel coordinates
         * can cover HD samples. Keep the native early return unchanged. */
        int scale=ir_init();
        if(precision && ir_surface_enabled(scale)) {
            if(scale>1)fine_vertex_rgb(&a,&b,&c,fine_rgb);
            raster_tri_world_fine(a,b,c,fine,gouraud,tex,semi,scale,
                                  inverse_depth?depth:NULL);
        }
#endif
        return;
    }
    if (area < 0) {
        Vtx t = b; b = c; c = t; area = -area;
        if(fine_rgb){uint32_t rgb=colors[1];colors[1]=colors[2];colors[2]=rgb;}
#ifdef A2_WORLD_PRECISION
        if(precision) {
            WorldFinePoint p=fine.p[1];fine.p[1]=fine.p[2];fine.p[2]=p;
            if(inverse_depth){double z=depth[1];depth[1]=depth[2];depth[2]=z;}
        }
#endif
#ifdef A2_NATIVE_MESH
        if(a2_mesh_live_active){double z=mesh_vertex_depth[1];mesh_vertex_depth[1]=mesh_vertex_depth[2];mesh_vertex_depth[2]=z;}
#endif
    }
    /* PS1 polygon coverage excludes bottom/right edges. With positive area
     * in screen coordinates, an upward or rightward horizontal edge owns
     * its boundary. Opposite shared edges therefore shade each pixel once,
     * including the internal diagonal of semi-transparent quads. */
    int edge0 = a.y > b.y || (a.y == b.y && a.x < b.x);
    int edge1 = b.y > c.y || (b.y == c.y && b.x < c.x);
    int edge2 = c.y > a.y || (c.y == a.y && c.x < a.x);
#ifdef A2_NATIVE_MESH
    if(IR==1&&(precision||mesh_fallback_projection_valid||mesh_billboard_depth>0))
        mesh_depth_setup(a.x,a.y,b.x,b.y,c.x,c.y);
#endif
    /* Native VRAM remains authoritative, including texture feedback. Walk
     * covered pixels in the original y/x order; exact owned-edge spans skip
     * only pixels the old bounding-box loop rejected. */
    int dx0=a.y-b.y,dx1=b.y-c.y,dx2=c.y-a.y;
    int64_t dr=(int64_t)dx1*a.r+(int64_t)dx2*b.r+(int64_t)dx0*c.r;
    int64_t dg=(int64_t)dx1*a.gr+(int64_t)dx2*b.gr+(int64_t)dx0*c.gr;
    int64_t db=(int64_t)dx1*a.b+(int64_t)dx2*b.b+(int64_t)dx0*c.b;
    int64_t du=(int64_t)dx1*a.u+(int64_t)dx2*b.u+(int64_t)dx0*c.u;
    int64_t dv=(int64_t)dx1*a.v+(int64_t)dx2*b.v+(int64_t)dx0*c.v;
    for (int y = miny; y <= maxy; y++) {
        int64_t w0=(int64_t)(b.x-a.x)*(y-a.y)+(int64_t)dx0*(minx-a.x);
        int64_t w1=(int64_t)(c.x-b.x)*(y-b.y)+(int64_t)dx1*(minx-b.x);
        int64_t w2=(int64_t)(a.x-c.x)*(y-c.y)+(int64_t)dx2*(minx-c.x);
        int first=0,last=maxx-minx;
        if(!fine_span_edge(w0,dx0,edge0,&first,&last)||
           !fine_span_edge(w1,dx1,edge1,&first,&last)||
           !fine_span_edge(w2,dx2,edge2,&first,&last))continue;
        w0+=(int64_t)dx0*first;w1+=(int64_t)dx1*first;w2+=(int64_t)dx2*first;
        int64_t nr=w1*a.r+w2*b.r+w0*c.r,ng=w1*a.gr+w2*b.gr+w0*c.gr;
        int64_t nb=w1*a.b+w2*b.b+w0*c.b;
        int64_t nu=w1*a.u+w2*b.u+w0*c.u,nv=w1*a.v+w2*b.v+w0*c.v;
        for(int x=minx+first;x<=minx+last;x++,nr+=dr,ng+=dg,nb+=db,nu+=du,nv+=dv) {
            int r = a.r, grn = a.gr, bl = a.b;
            if (gouraud) {
                r=(int)(nr/area);grn=(int)(ng/area);bl=(int)(nb/area);
            }
            uint16_t texel = 0;
            if (tex) {
                int u=(int)(nu/area),v=(int)(nv/area);
                texel = sample_tex(u, v);
            }
            put_px(x, y, r, grn, bl, semi, tex, texel);
        }
    }
    fine_gpu_written(minx,miny,maxx-minx+1,maxy-miny+1);
    /* fine pass into the shadow buffer (scaled vertices, same semantics) */
    int S = ir_init();
    if (S > 1
#ifdef A2_HUD_PRESENT
        || (SHADOW && hud_anchor>=0)
#endif
    ) {
#ifdef A2_WORLD_PRECISION
        if(precision) {
            if(S>1)fine_vertex_rgb(&a,&b,&c,fine_rgb);
            raster_tri_world_fine(a,b,c,fine,gouraud,tex,semi,S,inverse_depth?depth:NULL);return;
        }
#endif
        int axs = a.x * S, ays = a.y * S, bxs = b.x * S, bys = b.y * S,
            cxs = c.x * S, cys = c.y * S;
#ifdef A2_NATIVE_MESH
        if(mesh_fallback_projection_valid||mesh_billboard_depth>0)mesh_depth_setup(axs,ays,bxs,bys,cxs,cys);
#endif
        int64_t farea = area * S * S;
        int fminx = minx * S, fmaxx = maxx * S + S - 1;
        int fminy = miny * S, fmaxy = maxy * S + S - 1;
        int grid=1;
#ifdef A2_HUD_PRESENT
        if(hud_anchor>=0) {
            /* Exact 48ths: undo the display stretch around the proven
             * left/right group anchor with the world's own horizontal squeeze
             * (5/6 = 40/48 at 16:9; fill-screen aspects follow the window).
             * Guest geometry/VRAM remain unchanged. */
            int den=48,num=40;
#ifdef A2_WORLD_PRECISION
            num=(int)lround(48.0*world_precision_hud_scale());
#endif
            if(num<1)num=1;if(num>den)num=den;
            grid=den;
            axs=(num*a.x+(den-num)*hud_anchor)*S;bxs=(num*b.x+(den-num)*hud_anchor)*S;cxs=(num*c.x+(den-num)*hud_anchor)*S;
            ays*=den;bys*=den;cys*=den;farea*=(int64_t)num*den;
            int xmin=axs<bxs?axs:bxs,xmax=axs>bxs?axs:bxs;
            if(cxs<xmin)xmin=cxs;if(cxs>xmax)xmax=cxs;
            fminx=xmin/den-(xmin<0&&xmin%den!=0);
            fmaxx=xmax/den+(xmax>0&&xmax%den!=0);
            if(fminx<g.dax1*S)fminx=g.dax1*S;
            if(fmaxx>(g.dax2+1)*S-1)fmaxx=(g.dax2+1)*S-1;
        }
#endif
#ifdef A2_GPU_FINE
        int hd_active=0;
#ifdef A2_HD_FONTS
        hd_active=hd_matches_active();
#endif
        if(grid==1 && fminx<=fmaxx && fminy<=fmaxy && fine_gpu_triangle(a,b,c,
            (WorldFinePoint){(int64_t)axs*65536,(int64_t)ays*65536},
            (WorldFinePoint){(int64_t)bxs*65536,(int64_t)bys*65536},
            (WorldFinePoint){(int64_t)cxs*65536,(int64_t)cys*65536},
            fminx,fminy,fmaxx,fmaxy,gouraud,tex,semi,filter_on(),0,hd_active,0,NULL))return;
#endif
        fine_gpu_sync();
        int edge_dx0=ays-bys,edge_dx1=bys-cys,edge_dx2=cys-ays;
        int step0=edge_dx0*grid,step1=edge_dx1*grid,step2=edge_dx2*grid;
        int blend_mode=(cur_tpage>>5)&3;
        int64_t dr=(int64_t)step1*a.r+(int64_t)step2*b.r+(int64_t)step0*c.r;
        int64_t dg=(int64_t)step1*a.gr+(int64_t)step2*b.gr+(int64_t)step0*c.gr;
        int64_t db=(int64_t)step1*a.b+(int64_t)step2*b.b+(int64_t)step0*c.b;
        int64_t du=(int64_t)step1*a.u+(int64_t)step2*b.u+(int64_t)step0*c.u;
        int64_t dv=(int64_t)step1*a.v+(int64_t)step2*b.v+(int64_t)step0*c.v;
        FineTexCache cache;
        int cache_enabled=tex&&filter_on()&&du>-farea&&du<farea&&dv>-farea&&dv<farea;
        if(cache_enabled)for(unsigned i=0;i<64;i++)cache.cells[i].key=UINT32_MAX;
        int ordinary=fine_pixel_ordinary();
        for (int fy = fminy; fy <= fmaxy; fy++) {
            int64_t w0=(int64_t)(bxs-axs)*(fy*grid-ays)+(int64_t)edge_dx0*(fminx*grid-axs);
            int64_t w1=(int64_t)(cxs-bxs)*(fy*grid-bys)+(int64_t)edge_dx1*(fminx*grid-bxs);
            int64_t w2=(int64_t)(axs-cxs)*(fy*grid-cys)+(int64_t)edge_dx2*(fminx*grid-cxs);
            int first=0,last=fmaxx-fminx;
            if(!fine_span_edge(w0,step0,edge0,&first,&last)||
               !fine_span_edge(w1,step1,edge1,&first,&last)||
               !fine_span_edge(w2,step2,edge2,&first,&last))continue;
            w0+=(int64_t)step0*first;w1+=(int64_t)step1*first;w2+=(int64_t)step2*first;
            int64_t nr=w1*a.r+w2*b.r+w0*c.r,ng=w1*a.gr+w2*b.gr+w0*c.gr;
            int64_t nb=w1*a.b+w2*b.b+w0*c.b;
            int64_t nu=w1*a.u+w2*b.u+w0*c.u,nv=w1*a.v+w2*b.v+w0*c.v;
            uint16_t *dst=SHADOW+(size_t)fy*IR_W+fminx+first;
            int row_ordinary=ordinary||fine_pixel_ordinary_span(fminx+first,fy,fminx+last);
            for(int fx=fminx+first;fx<=fminx+last;fx++,dst++,nr+=dr,ng+=dg,nb+=db,nu+=du,nv+=dv) {
                int r = a.r, grn = a.gr, bl = a.b;
                if (gouraud) {
                    r=(int)(nr/farea);grn=(int)(ng/farea);bl=(int)(nb/farea);
                }
                uint16_t texel = 0;
                if (tex) {
#ifdef A2_HD_FONTS
                    if (hd_matches_active()) {
                        int32_t u_fp=(int32_t)((nu*256)/farea);
                        int32_t v_fp=(int32_t)((nv*256)/farea);
                        if (put_hd_ui(fx,fy,r,grn,bl,semi,u_fp,v_fp)) continue;
                    }
#endif
                    if (filter_on()) {
                        int32_t u_fp=(int32_t)((nu*256)/farea);
                        int32_t v_fp=(int32_t)((nv*256)/farea);
                        texel = soft_shadow_active?soft_shadow_texel(u_fp-128,v_fp-128):cache_enabled?sample_tex_cached(u_fp-128,v_fp-128,&cache):sample_tex_fine(u_fp-128,v_fp-128);
                    } else {
                        int u=(int)(nu/farea),v=(int)(nv/farea);
                        texel = sample_tex_present(u, v);
                    }
                }
                if(row_ordinary)put_fine_pixel_impl(dst,r,grn,bl,semi,tex,texel,blend_mode,FINE_PIXEL_ORDINARY);
                else put_fine_pixel(dst,r,grn,bl,semi,tex,texel,blend_mode);
            }
        }
    }
}

static void raster_tri(Vtx a,Vtx b,Vtx c,int gouraud,int tex,int semi) {
    raster_tri_internal(a,b,c,gouraud,tex,semi,NULL,NULL,NULL);
}

#ifdef A2_CINEMA_EXPANSION
#include "cinema_gpu.inc"
#endif

static void raster_line(Vtx a, Vtx b, int semi) {
    fine_gpu_sync();
#ifdef A2_INPUT_PROMPTS
    int left=a.x<b.x?a.x:b.x,top=a.y<b.y?a.y:b.y;
    a2_input_prompts_vram_changed(left,top,abs(b.x-a.x)+1,abs(b.y-a.y)+1);
#endif
    int dx = b.x - a.x, dy = b.y - a.y;
    int steps = (dx < 0 ? -dx : dx) > (dy < 0 ? -dy : dy)
              ? (dx < 0 ? -dx : dx) : (dy < 0 ? -dy : dy);
    if (steps == 0) steps = 1;
    if (steps > 1024) return;
    for (int i = 0; i <= steps; i++) {
        int x = a.x + dx * i / steps, y = a.y + dy * i / steps;
        put_px(x, y, a.r, a.gr, a.b, semi, 0, 0);
    }
    int dirty_left=a.x<b.x?a.x:b.x,dirty_top=a.y<b.y?a.y:b.y;
    fine_gpu_written(dirty_left,dirty_top,abs(b.x-a.x)+1,abs(b.y-a.y)+1);
    int S = ir_init();
    if (S > 1) {
        /* semi lines: step at native pitch so overlapping blocks don't
         * double-blend; opaque lines: fine steps for smoother diagonals */
        int fsteps = steps * S, inc = semi ? S : 1;
        for (int i = 0; i <= fsteps; i += inc) {
            int fx = a.x * S + dx * S * i / fsteps,
                fy = a.y * S + dy * S * i / fsteps;
            /* native pixel = S x S fine block, keeps line thickness */
            for (int oy = 0; oy < S; oy++)
                for (int ox = 0; ox < S; ox++)
                    put_fine(fx + ox, fy + oy, a.r, a.gr, a.b, semi, 0, 0);
        }
    }
}

/* ---------- GP0 ---------- */
static int gp0_len(uint32_t cmd) {
    int c = cmd >> 24;
    if (c <= 0x02) return c == 0x02 ? 3 : 1;
    if (c < 0x20) return 1;
    if (c < 0x40) {                   /* polygon */
        int quad = (c >> 3) & 1, tex = (c >> 2) & 1, gou = (c >> 4) & 1;
        int nv = quad ? 4 : 3;
        return 1 + nv * (1 + tex + gou) - gou;
    }
    if (c < 0x60) {                   /* line */
        if (c & 0x08) return -1;      /* polyline: variable */
        return (c & 0x10) ? 4 : 3;    /* gouraud has 2nd color */
    }
    if (c < 0x80) {                   /* rect */
        int tex = (c >> 2) & 1, var = ((c >> 3) & 3) == 0;
        return 2 + tex + var;
    }
    if (c < 0xA0) return 4;           /* vram-vram */
    if (c < 0xC0) return 3;           /* cpu->vram header */
    if (c < 0xE0) return 3;           /* vram->cpu header */
    return 1;                         /* env */
}

static void gp0_exec(void);

static int vw_zeros, vw_total, vw_b15;
static unsigned status_polls;
#ifdef A2_WORLD_PRECISION
static int precise_vertex(uint32_t address,uint32_t word,world_precision_vertex *out) {
    if(world_precision_packet(address,word,out))return 1;
#ifdef A2_NATIVE_BILLBOARD
    return a2_native_billboard_vertex(address,word,out);
#else
    return 0;
#endif
}
#endif

void gpu_gp0_at(uint32_t w, uint32_t address) {
    status_polls=0;
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
    if(model_minify_enabled<0) {
        const char *value=getenv("A2_MODEL_MINIFY");model_minify_enabled=value&&atoi(value)==1;
    }
    if(model_minify_enabled && ++model_minify_word==0) {
        model_minify_enabled=0;model_minify_base.word=model_minify_write=model_minify_pair=0;model_minify_tracking=0;
    }
#endif
#if !defined(A2_WORLD_PRECISION) && !defined(A2_HUD_PRESENT)
    (void)address;
#endif
#ifdef A2_HUD_PRESENT
    (void)ir_init(); /* Allocate/seed before the first native write. */
#else
    if(!IR && display_color_requested())(void)ir_init();
#endif
    if (in_vram_write) {
        for (int half = 0; half < 2; half++) {
            uint16_t px = (uint16_t)(w >> (half * 16));
            if (wpx == -3) pxwatch_init();
            if (wpx >= 0 && vw_x + vw_cx == wpx && vw_y + vw_cy == wpy &&
                (!wpf || (gpu_frames >= wpf && gpu_frames < wpf + 6)))
                fprintf(stderr, "pxw: f=%d A0write(%d,%d) px=%04X "
                        "rect=%d,%d %dx%d\n", gpu_frames, wpx, wpy, px,
                        vw_x, vw_y, vw_w, vw_h);
            *vram_px(vw_x + vw_cx, vw_y + vw_cy) = px;
            /* No texture acquire can interleave this payload stream. Mark
             * its full footprint once, including an interrupted upload. */
            if(!vw_cx&&!vw_cy)fine_gpu_written(vw_x,vw_y,vw_w,vw_h);
            {
                int S = ir_init();
                if (ir_surface_enabled(S)) /* uploads have no finer detail */
                    for (int oy = 0; oy < S; oy++)
                        for (int ox = 0; ox < S; ox++)
                        {
                            int fx=(vw_x+vw_cx)*S+ox,fy=(vw_y+vw_cy)*S+oy;
                            uint16_t *dst=shadow_px(fx,fy);*dst=px;
                            if(SHADOW_RGB)SHADOW_RGB[dst-SHADOW]=display_from_555(px);
#ifdef A2_NATIVE_MESH
                            if(a2_mesh_live_writes_watched)a2_mesh_live_store(fx,fy,px);
#endif
                        }
            }
            vw_total++;
            if (!px) vw_zeros++;
            if (px & 0x8000) vw_b15++;
            if (++vw_cx >= vw_w) { vw_cx = 0; vw_cy++; }
            if (vw_cy >= vw_h) {
                in_vram_write = 0;
                if (xferlog_armed()) {
                    extern uint32_t gpu_ll_node;
                    fprintf(stderr, "xfer@%d: A0-end dst=%d,%d %dx%d "
                            "zeros=%d/%d b15=%d node=%06X\n", gpu_frames,
                            vw_x, vw_y, vw_w, vw_h, vw_zeros, vw_total,
                            vw_b15, gpu_ll_node);
                }
                break;
            }
        }
        return;
    }
    if (in_polyline) {
        fine_gpu_sync(); /* Mesh startup below may copy the fine surface. */
        if ((w & 0xF000F000) == 0x50005000) { in_polyline = 0; fifo_n = 0; return; }
        /* draw segment from last vertex */
        uint32_t col = fifo[0];
        Vtx a = {sext11(fifo[fifo_n - 1]) + g.ofx,
                 sext11(fifo[fifo_n - 1] >> 16) + g.ofy,
                 col & 0xFF, (col >> 8) & 0xFF, (col >> 16) & 0xFF, 0, 0};
        Vtx b = {sext11(w) + g.ofx, sext11(w >> 16) + g.ofy,
                 col & 0xFF, (col >> 8) & 0xFF, (col >> 16) & 0xFF, 0, 0};
#ifdef A2_NATIVE_MESH
        mesh_pixel_kind=A2_COMPOSITE_ORDERED;mesh_depth_valid=mesh_fallback_projection_valid=0;
        mesh_pixel_owner=0;
        if(a2_mesh_live_enabled&&(g.ofy==0||g.ofy==256))
            a2_mesh_live_start(psx_frame_no,IR,g.ofy,SHADOW,(size_t)IR_W,a2_wide());
#endif
        raster_line(a, b, (fifo[0] >> 25) & 1);
#ifdef A2_CINEMA_EXPANSION
        cinema_line(a,b,(fifo[0]>>25)&1);
#endif
        fifo[fifo_n - 1] = w;          /* keep last vertex */
        return;
    }
    if (fifo_n == 0) {
#ifdef A2_NATIVE_MESH
        fifo_mesh_token=a2_native_actor_packets_token(address,w);
#ifdef A2_DIALOGUE_PACKETS
        fifo_dialogue_token=a2_dialogue_packets_token(address,w);
#endif
#ifdef A2_NATIVE_BILLBOARD
        fifo_billboard_token=a2_native_billboard_token(address,w);
#endif
#endif
#ifdef A2_HUD_PRESENT
        hud_anchor=-1;ir1_mirror=IR==1&&SHADOW;
        fifo_hud_token=a2_hud_present_packet_token(address,w);
#endif
        fifo_need = gp0_len(w);
        if (fifo_need == -1) {        /* polyline start: color + first vtx */
            /* Polylines bypass gp0_exec_body; retire the previous model's
             * depth before any segment can reach the fine rasterizer. */
            gpu_model_depth_barrier();
            fifo[0] = w; fifo_n = 1; fifo_need = 2;
            return;
        }
    }
    fifo[fifo_n] = w;
#if defined(A2_WORLD_PRECISION) || defined(A2_HUD_PRESENT)
    fifo_source[fifo_n] = address;
#endif
#ifdef A2_WORLD_PRECISION
    /* Freeze provenance when this word enters GP0. A later identical packet
     * rebuild must not retroactively attach its generation to queued words. */
    fifo_world[fifo_n].generation = 0;
    (void)precise_vertex(address,w,&fifo_world[fifo_n]);
#endif
    fifo_n++;
    if (fifo_n < fifo_need) return;
    int c = fifo[0] >> 24;
    if ((c >= 0x40 && c < 0x60) && (c & 0x08)) {  /* polyline got first vtx */
        in_polyline = 1;
        return;
    }
    gp0_exec();
    fifo_n = 0;
}

/* CPU MMIO/direct submissions have no tracked packet-word address. */
void gpu_gp0(uint32_t w) {
    gpu_gp0_at(w, UINT32_MAX);
}

static void gp0_exec_body(void);
static void gp0_exec(void) {
    A2Phase previous = a2_phase_enter(A2_PHASE_GPU);
    A2PhaseStamp started = a2_phase_now();
    unsigned command = fifo[0] >> 24;
    if(command==0x02 || (command>=0x40 && command<0xc0))fine_gpu_sync();
#ifdef A2_NATIVE_MESH
    if(a2_mesh_live_enabled||a2_mesh_live_active||a2_mesh_live_writes_watched)fine_gpu_sync();
#endif
    /* The body has many early returns. Bound state belongs only to this
     * command, including both halves of a textured quad. */
    fine_uv_reset();
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
    model_minify_write=model_minify_pair=0;
    /* Only an immediate E1/E2 prefix or one complete GT3 can still be the
     * second layer. Full source/payload/geometry validation follows below.
     * Retire unrelated context before its pixels can touch the key surface. */
    if(model_minify_base.word && !(((command==0xe1||command==0xe2) &&
       model_minify_word==model_minify_base.word+1) ||
       (command==0x34 && model_minify_word-model_minify_base.word==10)))model_minify_base.word=0;
    model_minify_tracking=model_minify_base.word!=0;
    if(model_minify_enabled && (command==0xe1 || command==0xe2)) {
        model_minify_prefix_word=model_minify_word;model_minify_prefix_value=fifo[0];
        model_minify_prefix_address=fifo_source[0];
    }
#endif
    gp0_exec_body();
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
    if(!model_minify_write && command!=0xe1 && command!=0xe2)model_minify_base.word=0;
    model_minify_write=model_minify_pair=0;
    model_minify_tracking=model_minify_base.word!=0;
#endif
    fine_uv_reset();
    a2_phase_gpu_command(command, started);
    a2_phase_leave(previous);
}

static void gp0_exec_body(void) {
#ifdef A2_CINEMA_EXPANSION
    if(cinema_scene>=0 && (g.dax1!=0||g.dax2!=319||g.day1!=cinema_scene*256||
       g.day2!=cinema_scene*256+171||g.ofx||g.ofy!=cinema_scene*256))cinema_invalidate();
    if(cinema_text>=0 && (g.dax1!=0||g.dax2!=319||g.day1!=cinema_text*256||
       g.day2!=cinema_text*256+215||g.ofx||g.ofy!=cinema_text*256))cinema_invalidate();
    if(cinema_text>=0 && (fifo[0]>>24)>=0x20 && (fifo[0]>>24)<0x60)
        cinema_invalidate(); /* Unverified overlay after the scene pass. */
#endif
#ifdef A2_HUD_PRESENT
    hud_anchor=-1;
    int anchor;
    /* Only ordinary 320x216 GAME00 packets qualify. Consuming even rejected
     * layouts prevents a later draw environment from reviving their tag. */
    int tagged=fifo_hud_token && a2_hud_present_consume(fifo_source[0],fifo_hud_token,fifo,(unsigned)fifo_n,&anchor);
    int c_hud=(int)(fifo[0]>>24);
    int sources_contiguous=1;
    if(tagged)for(int i=1;i<fifo_n;i++)if(fifo_source[i]!=fifo_source[0]+(uint32_t)i*4)sources_contiguous=0;
    if(tagged && sources_contiguous && (anchor==0||anchor==320) && c_hud>=0x20 && c_hud<0x40 &&
       g.ofx==0 && (g.ofy==0||g.ofy==256) && g.dax1==0 && g.dax2==319 &&
       g.day1==g.ofy && g.day2==g.ofy+215)hud_anchor=anchor;
    ir1_mirror=IR==1 && SHADOW && hud_anchor<0;
#endif
#ifdef A2_WORLD_PRECISION
    world_primitive_valid = 0;
#endif
#ifdef A2_HD_FONTS
    /* Also covers primitive paths which return early (glyphs, debug, blocks). */
    hd_matches_reset();
#endif
    uint32_t *p = fifo;
    int c = p[0] >> 24;
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
    model_depth_plane_valid=0;model_depth_ground_shadow=0;model_depth_world=0;soft_shadow_active=0;
    if(model_depth_enabled && (c==0x02 || (c>=0x40&&c<0xc0) || (c>=0xe3&&c<=0xe5)))
        gpu_model_depth_barrier();
#endif
#ifdef A2_NATIVE_MESH
    mesh_coverage_flush();mesh_pixel_owner=0;
    const A2ActorPacket *mesh_packet=NULL;
    mesh_pixel_kind=A2_COMPOSITE_UNKNOWN;mesh_depth_valid=mesh_fallback_projection_valid=0;mesh_billboard_depth=0;
#ifdef A2_DIALOGUE_PACKETS
    int dialogue=0;
    if(fifo_dialogue_token) {
        int contiguous=1;
        for(int i=1;i<fifo_n;i++)if(fifo_source[i]!=fifo_source[0]+4u*(unsigned)i)contiguous=0;
        if(contiguous)dialogue=a2_dialogue_packets_consume(fifo_source[0],fifo_dialogue_token,fifo,(unsigned)fifo_n);
    }
#endif
#ifdef A2_NATIVE_BILLBOARD
    if(fifo_billboard_token) {
        int contiguous=1;double z=0;
        for(int i=1;i<fifo_n;i++)if(fifo_source[i]!=fifo_source[0]+4u*(unsigned)i)contiguous=0;
        if(contiguous&&a2_native_billboard_consume(fifo_source[0],fifo_billboard_token,fifo,(unsigned)fifo_n,&z)&&
           isfinite(z)&&z>=1&&z<65536)mesh_billboard_depth=z;
    }
#endif
    if(fifo_mesh_token) {
        int contiguous=1;
        for(int i=1;i<fifo_n;i++)if(fifo_source[i]!=fifo_source[0]+4u*(unsigned)i)contiguous=0;
        if(contiguous)(void)a2_native_actor_packets_consume(fifo_source[0],fifo_mesh_token,fifo,(unsigned)fifo_n,&mesh_packet);
    }
    int mesh_rectangle_clear=0;
    if(a2_mesh_live_enabled&&c==0x60&&fifo_n==3){
        int x=sext11(p[1])+g.ofx,y=sext11(p[1]>>16)+g.ofy;
        int w=p[2]&0x3ff,h=(p[2]>>16)&0x1ff;
        /* EVENT00 clears through an opaque RECT rather than GP0(02).
         * Only complete, actually unclipped page coverage retires the prior
         * model frame. Fades, captions and narrow scissors remain ordered. */
        if(x==0&&(y==0||y==256)&&w==320&&h>=216&&h<=256&&
           g.dax1<=x&&g.day1<=y&&g.dax2>=319&&g.day2>=y+215){
            a2_mesh_live_clear(psx_frame_no,IR,x,y,w,h);
            mesh_rectangle_clear=1;
        }
    }
    if(a2_mesh_live_enabled&&c>=0x20&&c<0x80&&!mesh_rectangle_clear) {
        if(g.ofy==0||g.ofy==256)
            a2_mesh_live_start_view(psx_frame_no,IR,g.ofy,SHADOW,(size_t)IR_W,a2_wide(),
                g.dax1==0&&g.dax2==319&&g.day1==g.ofy&&g.day2==g.ofy+171?172:216);
    }
    if(mesh_packet&&a2_mesh_live_claim_part(mesh_packet->owner_handle,mesh_packet->source_mesh_index)) {
        mesh_pixel_kind=A2_COMPOSITE_OWNED;mesh_pixel_owner=mesh_packet->owner_handle;
    }
#ifdef A2_DIALOGUE_PACKETS
    else if(dialogue)mesh_pixel_kind=A2_COMPOSITE_HUD;
#endif
    else if(mesh_billboard_depth>0)mesh_pixel_kind=A2_COMPOSITE_WORLD;
#ifdef A2_HUD_PRESENT
    else if(hud_anchor>=0)mesh_pixel_kind=A2_COMPOSITE_HUD;
#endif
    mesh_coverage_identity(mesh_packet);
#endif
    uint32_t col = p[0] & 0xFFFFFF;
    { extern int gpu_cur_cmd; gpu_cur_cmd = c; }
    if (c == 0x00 || c == 0x01) return;
    if (c == 0x02) {                   /* fill rect (VRAM coords) */
        int x = p[1] & 0x3F0, y = (p[1] >> 16) & 0x1FF;
        int w = ((p[2] & 0x3FF) + 0xF) & ~0xF, h = (p[2] >> 16) & 0x1FF;
#ifdef A2_CINEMA_EXPANSION
        cinema_vram_write(x,y,w,h);
#endif
#ifdef A2_INPUT_PROMPTS
        a2_input_prompts_vram_changed(x,y,w,h);
#endif
        uint16_t px = (uint16_t)(((col & 0xFF) >> 3) |
                      ((((col >> 8) & 0xFF) >> 3) << 5) |
                      ((((col >> 16) & 0xFF) >> 3) << 10));
        if (wpx == -3) pxwatch_init();
        if (wpx >= 0 && wpx >= x && wpx < x + w && wpy >= y && wpy < y + h &&
            (!wpf || (gpu_frames >= wpf && gpu_frames < wpf + 6)))
            fprintf(stderr, "pxw: f=%d fill02(%d,%d %dx%d) col=%06X\n",
                    gpu_frames, x, y, w, h, col);
        for (int j = 0; j < h; j++)
            for (int i = 0; i < w; i++)
                *vram_px(x + i, y + j) = px;
        fine_gpu_written(x,y,w,h);
        int S = ir_init();
        if (ir_surface_enabled(S) &&
            !shadow_fill_rows(x*S,y*S,w*S,h*S,px,display_rgb(col&255,(col>>8)&255,(col>>16)&255)))
            for (int j = 0; j < h * S; j++)
                for (int i = 0; i < w * S; i++)
                {
                    uint16_t *dst=shadow_px(x*S+i,y*S+j);*dst=px;
                    if(SHADOW_RGB)SHADOW_RGB[dst-SHADOW]=display_rgb(col&255,(col>>8)&255,(col>>16)&255);
#ifdef A2_NATIVE_MESH
                    if(a2_mesh_live_writes_watched)a2_mesh_live_store(x*S+i,y*S+j,px);
#endif
                }
#ifdef A2_NATIVE_MESH
        if((y==0||y==256)&&x==0&&w==320&&h>=216&&h<=256)
            a2_mesh_live_clear(psx_frame_no,S,x,y,w,h);
#endif
        return;
    }
    if (c >= 0x20 && c < 0x40) {       /* polygon */
        int quad = (c >> 3) & 1, tex = (c >> 2) & 1, gou = (c >> 4) & 1;
        int semi = (c >> 1) & 1, raw = c & 1;
        int nv = quad ? 4 : 3;
        Vtx v[4];
        int k = 1;
#ifdef A2_WORLD_PRECISION
        int tracked = world_precision_enabled;
        uint64_t generation = 0;
        uint32_t world_sources[4],world_words[4];
        int world_valid[4];
#endif
        for (int i = 0; i < nv; i++) {
            uint32_t vcol = (i == 0 || !gou) ? col : (p[k++] & 0xFFFFFF);
            if (i == 0 && gou) { /* first color is cmd word */ }
            uint32_t xy = p[k++];
#ifdef A2_WORLD_PRECISION
            const world_precision_vertex *queued = &fifo_world[k-1];
            world_precision_vertex current;
            int valid = queued->generation &&
                precise_vertex(fifo_source[k-1],xy,&current) &&
                current.generation == queued->generation &&
                current.projection_id == queued->projection_id;
            if (valid) world_vertices[i] = *queued;
            world_sources[i] = fifo_source[k-1];
            world_words[i] = xy;
            world_valid[i] = valid;
            if (!valid || (i && world_vertices[i].generation != generation)) tracked = 0;
            if (valid && !i) generation = world_vertices[i].generation;
#endif
            v[i].x = sext11(xy) + g.ofx;
            v[i].y = sext11(xy >> 16) + g.ofy;
            v[i].r = raw && tex ? 0x80 : vcol & 0xFF;
            v[i].gr = raw && tex ? 0x80 : (vcol >> 8) & 0xFF;
            v[i].b = raw && tex ? 0x80 : (vcol >> 16) & 0xFF;
            if (tex) {
                uint32_t uv = p[k++];
                v[i].u = uv & 0xFF; v[i].v = (uv >> 8) & 0xFF;
                if (i == 0) cur_clut = uv >> 16;
                if (i == 1) cur_tpage = uv >> 16;
            } else v[i].u = v[i].v = 0;
        }
        if(tex)fine_uv_polygon(v,nv);
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
        soft_shadow_active=tex&&semi&&model_depth_enabled&&world_depth_on()&&shadow_texture_replaced(v,nv);
#endif
#ifdef A2_WORLD_PRECISION
        world_primitive_valid = tracked;
#ifdef A2_NATIVE_MESH
        if(mesh_pixel_kind==A2_COMPOSITE_UNKNOWN&&tracked)mesh_pixel_kind=A2_COMPOSITE_WORLD;
#endif
        uint64_t consumer = ++world_consumer_sequence;
        if (world_precision_enabled) {
            world_precision_trace_primitive((uint32_t)gpu_frames,consumer,tracked,
                                             g.ofx,g.ofy,g.disp_x,g.disp_y);
            for (int i = 0; i < nv; i++) {
                if (world_valid[i])
                    world_precision_trace((uint32_t)gpu_frames,"consume",0,world_sources[i],
                                          &world_vertices[i]);
                else
                    world_precision_trace_miss((uint32_t)gpu_frames,"consume",0,
                                               world_sources[i],world_words[i]);
            }
        }
#endif
        if (!tex) cur_tpage = g.texpage;   /* semi-trans mode from env */
        {
            static int texdbg = -1;
            if (texdbg < 0) texdbg = getenv("A2_TEXDEBUG")
                                   ? atoi(getenv("A2_TEXDEBUG")) : 0;
            if (texdbg == 1 && !tex)
                for (int i = 0; i < nv; i++) {
                    v[i].r = 0; v[i].gr = 0xFF; v[i].b = 0;
                }
            if (texdbg == 2 && !tex) return;   /* hide untextured polys */
        }
        {
            extern int gpu_prim_log;
            if (gpu_prim_log > 0 && !tex) {
                gpu_prim_log--;
                extern uint32_t gpu_ll_node;
                fprintf(stderr, "uprim: f=%d c=%02X semi=%d col=%06X xy0=%d,%d "
                        "e1=%04X node=%08X w:", gpu_frames, c, semi, col,
                        v[0].x, v[0].y,
                        (unsigned)(g.texpage & 0xFFFF), gpu_ll_node);
                for (int i = 0; i < fifo_need; i++)
                    fprintf(stderr, " %08X", fifo[i]);
                fprintf(stderr, "\n");
            }
            if (gpu_prim_log > 0 && tex) {
                gpu_prim_log--;
                int tpx = (cur_tpage & 0xF) * 64,
                    tpy = ((cur_tpage >> 4) & 1) * 256;
                int nz = 0;
                for (int sy = 0; sy < 8; sy++)
                    for (int sx = 0; sx < 8; sx++)
                        if (*vram_px(tpx + sx * 8, tpy + sy * 8)) nz++;
                /* sample actual texels across the prim's UV bbox */
                int u1 = 255, u2 = 0, vv1 = 255, vv2 = 0;
                for (int i = 0; i < nv; i++) {
                    if (v[i].u < u1) u1 = v[i].u;
                    if (v[i].u > u2) u2 = v[i].u;
                    if (v[i].v < vv1) vv1 = v[i].v;
                    if (v[i].v > vv2) vv2 = v[i].v;
                }
                int tot = 0, zer = 0, blk = 0;
                for (int sv = vv1; sv <= vv2; sv++)
                    for (int su = u1; su <= u2; su++) {
                        uint16_t t = sample_tex(su, sv);
                        tot++;
                        if (t == 0) zer++;
                        else if (!(t & 0x7FFF)) blk++;
                    }
                fprintf(stderr, "prim: poly%d tpage=%03X(%d,%d) clut=%04X "
                        "uv0=%d,%d xy0=%d,%d texnz=%d/64 col=%02X,%02X,%02X "
                        "uvbox=%d,%d..%d,%d tex tot=%d zero=%d blk=%d\n",
                        quad ? 4 : 3,
                        cur_tpage & 0xFFF, tpx, tpy, cur_clut, v[0].u, v[0].v,
                        v[0].x, v[0].y, nz, v[0].r, v[0].gr, v[0].b,
                        u1, vv1, u2, vv2, tot, zer, blk);
                /* debug: full packet + all vertices for footprint mapping */
                fprintf(stderr, "tprim: f=%d c=%02X semi=%d raw=%d xy",
                        gpu_frames, c, semi, raw);
                for (int i = 0; i < nv; i++)
                    fprintf(stderr, " %d,%d", v[i].x, v[i].y);
                fprintf(stderr, " w:");
                for (int i = 0; i < fifo_need; i++)
                    fprintf(stderr, " %08X", fifo[i]);
                fprintf(stderr, "\n");
            }
        }
        /* A2_MODELCAP: log the emitted polygon (screen coords match the
         * RTP s-values; UV/tpage/clut give texturing) so the offline
         * ripper can map faces to model vertices without decoding the
         * opaque on-RAM face records. */
        {
            int a2_modelcap_active(void);
            FILE *a2_modelcap_file(void);
            if (a2_modelcap_active()) {
                FILE *mf = a2_modelcap_file();
                if (mf) {
                    fprintf(mf, "PRIM f%u %s tex=%d gou=%d nv=%d", gpu_frames,
                            quad ? "quad" : "tri", tex, gou, nv);
                    for (int i = 0; i < nv; i++)
                        fprintf(mf, " p%d=%d,%d,%d,%d,%02X%02X%02X", i,
                                v[i].x - g.ofx, v[i].y - g.ofy,
                                v[i].u, v[i].v, v[i].r, v[i].gr, v[i].b);
                    fprintf(mf, " tpage=%03X clut=%04X\n",
                            (unsigned)(tex ? cur_tpage : g.texpage) & 0xFFF,
                            (unsigned)cur_clut);
                }
            }
        }
#ifdef A2_HD_FONTS
        /* Baked UI is emitted as axis-aligned quads, including its small
           selected-tab pulse. Never substitute arbitrary world triangles. */
        if(tex && quad && v[0].x==v[2].x && v[1].x==v[3].x &&
           v[0].y==v[1].y && v[2].y==v[3].y &&
           v[0].u==v[2].u && v[1].u==v[3].u && v[0].v==v[1].v && v[2].v==v[3].v) {
            if (!g.texwin)
                hd_plate_count=a2_hd_ui_prepare(GPU_VRAM,cur_tpage,v[0].u,v[0].v,v[3].u,v[3].v,hd_plates,128);
#if defined(A2_HD_ART) || defined(A2_HD_PORTRAITS)
            int u0=v[0].u<v[3].u?v[0].u:v[3].u,u1=v[0].u>v[3].u?v[0].u:v[3].u;
            int v0=v[0].v<v[3].v?v[0].v:v[3].v,v1=v[0].v>v[3].v?v[0].v:v[3].v;
#ifdef A2_HD_ART
            prepare_hd_art(u0,v0,u1,v1);
#endif
#ifdef A2_HD_PORTRAITS
            prepare_hd_portrait(u0,v0,u1,v1);
#endif
#endif
        }
#ifdef A2_HD_ART
        /* Resident loading GT4s use vertical-first XY and matching UV axes.
           Keep this extension limited to exact-source artwork. */
        else if(tex && quad && v[0].x==v[1].x && v[2].x==v[3].x &&
                v[0].y==v[2].y && v[1].y==v[3].y &&
                v[0].u==v[1].u && v[2].u==v[3].u &&
                v[0].v==v[2].v && v[1].v==v[3].v) {
            int u0=v[0].u<v[3].u?v[0].u:v[3].u,u1=v[0].u>v[3].u?v[0].u:v[3].u;
            int v0=v[0].v<v[3].v?v[0].v:v[3].v,v1=v[0].v>v[3].v?v[0].v:v[3].v;
            prepare_hd_art(u0,v0,u1,v1);
        }
#endif
#endif
#ifdef A2_WORLD_PRECISION
        WorldFinePoint fine_points[4];
        int legacy_shadow=0,physical_shadow=0;
#ifdef A2_NATIVE_MESH
        legacy_shadow=original_shadow_raster(nv,c);
        if(legacy_shadow)model_depth_ground_shadow=model_shadow_admit();
        if(model_depth_ground_shadow && world_raster_enabled)
            physical_shadow=model_shadow_fine_points(fine_points);
#endif
#if defined(A2_NATIVE_MESH) && defined(A2_HD_FONTS)
        /* These substitutions can write SHADOW through direct destinations,
         * bypassing put_fine_pixel. Keep their conservative full barrier. */
        if(model_depth_enabled&&hd_matches_active())gpu_model_depth_barrier();
#endif
        int precise_path=physical_shadow || (!legacy_shadow && world_raster_enabled && world_primitive_valid &&
#ifdef A2_HUD_PRESENT
           hud_anchor<0 &&
#endif
           world_fine_points(fine_points,v,nv));
        if(precise_path) {
#ifdef A2_NATIVE_MESH
            int self_depth=0,world_depth=0;
            if(physical_shadow)model_shadow_triangle(0);
            else self_depth=model_depth_admit(mesh_packet,nv);
            if(!physical_shadow&&!self_depth)world_depth=world_depth_admit(nv,semi);
            if(self_depth||world_depth)model_depth_triangle(fine_points,world_vertices);
            if(world_depth)world_depth_bounds(fine_points);
#endif
            double inverse[4];
            /* Large WORLD faces show the affine kink; models keep minification. */
            int perspective_face=!physical_shadow;
#ifdef A2_NATIVE_MESH
            perspective_face=perspective_face&&!self_depth;
#endif
            int perspective=perspective_face && world_perspective_depths(inverse,nv,tex);
#ifdef A2_NATIVE_MESH
            if(self_depth && !physical_shadow && !perspective)model_minify_prepare(mesh_packet,fine_points,nv);
#endif
            WorldFineTriangle first={{fine_points[0],fine_points[1],fine_points[2]}};
            const uint32_t *fine_rgb=NULL;
#ifdef A2_NATIVE_MESH
            for(unsigned i=0;i<3;i++)mesh_vertex_depth[i]=world_vertices[i].z;
            if(self_depth && !physical_shadow && !quad && !tex && !semi && gou &&
               mesh_packet->fine_rgb_valid)fine_rgb=mesh_packet->fine_rgb;
#endif
            raster_tri_internal(v[0],v[1],v[2],gou,tex,semi,&first,perspective?inverse:NULL,fine_rgb);
            if(quad) {
                WorldFineTriangle second={{fine_points[1],fine_points[2],fine_points[3]}};
#ifdef A2_NATIVE_MESH
                if(self_depth||world_depth)model_depth_triangle(fine_points+1,world_vertices+1);
                if(world_depth)world_depth_bounds(fine_points+1);
                for(unsigned i=0;i<3;i++)mesh_vertex_depth[i]=world_vertices[i+1].z;
#endif
                raster_tri_internal(v[1],v[2],v[3],gou,tex,semi,&second,perspective?inverse+1:NULL,NULL);
            }
        } else
#endif
        {
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
            WorldFinePoint verified_points[4];
            mesh_fallback_projection_valid=a2_mesh_live_active&&mesh_pixel_kind==A2_COMPOSITE_WORLD&&
                world_primitive_valid&&world_fine_projection_points(verified_points,v,nv);
            for(unsigned i=0;i<3;i++)mesh_vertex_depth[i]=world_vertices[i].z;
#endif
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
            if(model_depth_ground_shadow)model_shadow_triangle(0);
#endif
            raster_tri(v[0], v[1], v[2], gou, tex, semi);
            if (quad) {
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
                for(unsigned i=0;i<3;i++)mesh_vertex_depth[i]=world_vertices[i+1].z;
#endif
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
                if(model_depth_ground_shadow)model_shadow_triangle(1);
#endif
                raster_tri(v[1], v[2], v[3], gou, tex, semi);
            }
        }
#ifdef A2_CINEMA_EXPANSION
        if(cinema_scene>=0) {
#ifdef A2_WORLD_PRECISION
            if(!legacy_shadow && IR>1 && world_raster_enabled && world_primitive_valid && world_fine_points(fine_points,v,nv)) {
                WorldFineTriangle first={{fine_points[0],fine_points[1],fine_points[2]}};
                cinema_triangle(v[0],v[1],v[2],gou,tex,semi,&first);
                if(quad) {
                    WorldFineTriangle second={{fine_points[1],fine_points[2],fine_points[3]}};
                    cinema_triangle(v[1],v[2],v[3],gou,tex,semi,&second);
                }
            } else
#endif
            {
                cinema_triangle(v[0],v[1],v[2],gou,tex,semi,NULL);
                if(quad)cinema_triangle(v[1],v[2],v[3],gou,tex,semi,NULL);
            }
        }
#endif
#ifdef A2_HD_FONTS
        hd_matches_reset();
#endif
        return;
    }
    if (c >= 0x40 && c < 0x60) {       /* line (non-poly) */
        int gou = (c >> 4) & 1, semi = (c >> 1) & 1;
        uint32_t c2 = gou ? p[2] : col;
        uint32_t xy1 = p[1], xy2 = gou ? p[3] : p[2];
        Vtx a = {sext11(xy1) + g.ofx, sext11(xy1 >> 16) + g.ofy,
                 col & 0xFF, (col >> 8) & 0xFF, (col >> 16) & 0xFF, 0, 0};
        Vtx b = {sext11(xy2) + g.ofx, sext11(xy2 >> 16) + g.ofy,
                 c2 & 0xFF, (c2 >> 8) & 0xFF, (c2 >> 16) & 0xFF, 0, 0};
        cur_tpage = g.texpage;
        raster_line(a, b, semi);
#ifdef A2_CINEMA_EXPANSION
        cinema_line(a,b,semi);
#endif
        return;
    }
    if (c >= 0x60 && c < 0x80) {       /* rect */
        int tex = (c >> 2) & 1, semi = (c >> 1) & 1, raw = c & 1;
        int sz = (c >> 3) & 3;
        int k = 1;
        uint32_t xy = p[k++];
        int x = sext11(xy) + g.ofx, y = sext11(xy >> 16) + g.ofy;
        int u0 = 0, v0 = 0;
        if (tex) {
            uint32_t uv = p[k++];
            u0 = uv & 0xFF; v0 = (uv >> 8) & 0xFF;
            cur_clut = uv >> 16;
        }
        cur_tpage = g.texpage;
        int w, h;
        if (sz == 0) { w = p[k] & 0x3FF; h = (p[k] >> 16) & 0x1FF; k++; }
        else if (sz == 1) w = h = 1;
        else if (sz == 2) w = h = 8;
        else w = h = 16;
        int r = raw && tex ? 0x80 : col & 0xFF,
            grn = raw && tex ? 0x80 : (col >> 8) & 0xFF,
            b = raw && tex ? 0x80 : (col >> 16) & 0xFF;
#ifdef A2_CINEMA_EXPANSION
        int cinema_caption=cinema_text>=0 && c==0x64 && !g.texwin && h==16 &&
            (y==cinema_text*256+174 || y==cinema_text*256+190) && x>=0 && x+w<=320;
        int cinema_caption_clear=cinema_text>=0 && c==0x60 && !col && x==0 &&
            y==cinema_text*256+172 && w==320 && h==44;
        if(cinema_text>=0 && !cinema_caption && !cinema_caption_clear)
            cinema_invalidate(); /* Source is no longer glyphs on black. */
        if(cinema_caption_clear)
            memset(cinema_alpha[cinema_text],0,(size_t)320*32*cinema_scale*cinema_scale);
        cinema_rect(x,y,w,h,u0,v0,r,grn,b,semi,tex);
#endif
#ifdef A2_INPUT_PROMPTS
        a2_input_prompts_vram_changed(x,y,w,h);
        if(c==0x64 && !g.texwin && col==0x808080 &&
           x>=g.dax1 && y>=g.day1 && x+w-1<=g.dax2 && y+h-1<=g.day2)
            a2_input_prompts_sprite(GPU_VRAM,cur_tpage,cur_clut,x,y,w,h,u0,v0);
#endif
        if (gpu_prim_log > 0) {
            gpu_prim_log--;
            fprintf(stderr, "rect: f=%d c=%02X tex=%d xy=%d,%d wh=%dx%d "
                    "u,v=%d,%d tpage=%03X(mode%d) clut=%04X col=%06X\n",
                    gpu_frames, c, tex, x, y, w, h,
                    u0, v0, cur_tpage & 0xFFF, (cur_tpage >> 7) & 3, cur_clut,
                    col);
        }
        for (int j = 0; j < h; j++)
            for (int i = 0; i < w; i++) {
                uint16_t texel = 0;
                if (tex) texel = sample_tex(u0 + i, v0 + j);
                put_px(x + i, y + j, r, grn, b, semi, tex, texel);
            }
        fine_gpu_written(x,y,w,h);
        int S = ir_init();
#ifdef A2_NATIVE_MESH
        /* Every actual covered rectangle sample follows its native command
         * order; a scissor/overlay never changes resource selection. */
#endif
#ifdef A2_HD_FONTS
        const A2HDGlyph *hd = tex && !g.texwin ?
            a2_hd_font_match(GPU_VRAM,cur_tpage,u0,v0,w,h) : NULL;
        if (S > 1 && hd) {
#ifdef A2_CINEMA_EXPANSION
            if(cinema_caption)cinema_caption_hd(x,y,h,hd);
#endif
            uint16_t ink = *vram_px((cur_clut&63)*16+3,(cur_clut>>6)&511);
            uint16_t shade = *vram_px((cur_clut&63)*16+1,(cur_clut>>6)&511);
            const uint8_t *coverage=NULL;
#ifdef A2_HD_FONT_VIEW_TEST
            if(!font_view_reference)
#endif
                coverage=a2_hd_font_coverage(hd,S);
#ifdef A2_HD_FONT_VIEW_TEST
            if(coverage)font_view_uses++;
#endif
            for (int fj=0;fj<h*S;fj++)
                for (int fi=0;fi<12*S;fi++) {
                    unsigned a=coverage?coverage[fj*A2_HD_FONT_COVERAGE_STRIDE+fi]:a2_hd_font_alpha(hd,fi,fj,S);
                    /* A subtle lower-right shadow follows the current font
                       palette, not a hardcoded white/black text overlay. */
                    unsigned edge=coverage?(fi&&fj?coverage[(fj-1)*A2_HD_FONT_COVERAGE_STRIDE+fi-1]:0):a2_hd_font_alpha(hd,fi-1,fj-1,S);
                    put_font_coverage(x*S+fi,y*S+fj,r,grn,b,semi,shade,edge);
                    put_font_coverage(x*S+fi,y*S+fj,r,grn,b,semi,ink,a);
                }
            return;
        }
#endif
#ifdef A2_CINEMA_EXPANSION
        if(cinema_caption)cinema_caption_native(x,y,w,h,u0,v0);
#endif
#ifdef A2_HD_FONTS
        hd_plate_count=tex && !g.texwin ?
            a2_hd_ui_prepare(GPU_VRAM,cur_tpage,u0,v0,u0+w-1,v0+h-1,hd_plates,128) : 0;
#ifdef A2_HD_ART
        if (tex && w && h) prepare_hd_art(u0,v0,u0+w-1,v0+h-1);
#endif
#ifdef A2_HD_PORTRAITS
        if (tex && w && h) prepare_hd_portrait(u0,v0,u0+w-1,v0+h-1);
#endif
#endif
        if (S > 1
#ifdef A2_HD_FONTS
            && !hd_matches_active()
#endif
#ifdef A2_GPU_RECT_TEST
            && !gpu_rect_test_reference
#endif
        ) {
            rect_fine_blocks(x,y,w,h,u0,v0,r,grn,b,semi,tex,S);
            return;
        }
        if (S > 1) {
            /* HD sampling only reads VRAM; both fine writers discard pixels
               outside the draw area. Clip before sampling, keeping fi/fj
               relative to the original sprite for fractional and wrapped UV. */
            int fi0=0,fj0=0,fi1=w*S,fj1=h*S;
#ifdef A2_GPU_RECT_TEST
            if (!gpu_rect_test_reference)
#endif
            {
                if (g.dax1>x) fi0=(g.dax1-x)*S;
                if (g.day1>y) fj0=(g.day1-y)*S;
                if (g.dax2+1<x+w) fi1=(g.dax2+1-x)*S;
                if (g.day2+1<y+h) fj1=(g.day2+1-y)*S;
            }
#if defined(A2_HD_FONTS) && defined(A2_HD_ART)
            if(hd_art_rect_span(x,y,w,h,u0,v0,r,grn,b,semi,S,fi0,fj0,fi1,fj1)) {
                hd_matches_reset();return;
            }
#endif
            for (int fj = fj0; fj < fj1; fj++)
                for (int fi = fi0; fi < fi1; fi++) {
#ifdef A2_HD_FONTS
                    if (hd_matches_active() && put_hd_ui(x*S+fi,y*S+fj,r,grn,b,semi,u0*256+fi*256/S,v0*256+fj*256/S)) continue;
#endif
                    uint16_t texel = 0;
                    /* rects are UI/sprites: keep nearest sampling — the
                     * game's pixel art reads better unfiltered and 1:1
                     * mapping has no minification to smooth anyway */
                    if (tex) texel = sample_tex_present(u0 + fi / S, v0 + fj / S);
                    put_fine(x * S + fi, y * S + fj, r, grn, b, semi, tex, texel);
                }
        }
#ifdef A2_HD_FONTS
        hd_matches_reset();
#endif
        return;
    }
    if (c >= 0x80 && c < 0xA0) {       /* vram-vram copy */
        int sx = p[1] & 0x3FF, sy = (p[1] >> 16) & 0x1FF;
        int dx = p[2] & 0x3FF, dy = (p[2] >> 16) & 0x1FF;
        int w = ((p[3] - 1) & 0x3FF) + 1, h = (((p[3] >> 16) - 1) & 0x1FF) + 1;
#ifdef A2_CINEMA_EXPANSION
        if(sx!=dx||sy!=dy)cinema_vram_write(dx,dy,w,h);
#endif
#ifdef A2_INPUT_PROMPTS
        a2_input_prompts_vram_changed(dx,dy,w,h);
#endif
        if ((w > 2 || h > 1) && xferlog_armed())
            fprintf(stderr, "xfer@%d: 80 src=%d,%d dst=%d,%d %dx%d\n",
                    gpu_frames, sx, sy, dx, dy, w, h);
        if (wpx == -3) pxwatch_init();
        if (wpx >= 0 && wpx >= dx && wpx < dx + w && wpy >= dy &&
            wpy < dy + h && (!wpf || (gpu_frames >= wpf &&
                                      gpu_frames < wpf + 6)))
            fprintf(stderr, "pxw: f=%d copy80 src=%d,%d dst=%d,%d %dx%d\n",
                    gpu_frames, sx, sy, dx, dy, w, h);
        for (int j = 0; j < h; j++)
            for (int i = 0; i < w; i++)
                *vram_px(dx + i, dy + j) = *vram_px(sx + i, sy + j);
        fine_gpu_written(dx,dy,w,h);
        int S = ir_init();
        if (ir_surface_enabled(S))     /* shadow->shadow keeps fine detail */
            for (int j = 0; j < h * S; j++)
                for (int i = 0; i < w * S; i++)
                {
                    int x=sx*S+i,y=sy*S+j,tx=dx*S+i,ty=dy*S+j;
                    uint16_t value=*shadow_px(x,y);
#ifdef A2_NATIVE_MESH
                    if(a2_mesh_live_writes_watched)value=a2_mesh_live_read(x,y,value);
#endif
                    uint16_t *dst=shadow_px(tx,ty);
                    if(SHADOW_RGB) {
                        uint32_t rgb=SHADOW_RGB[shadow_px(x,y)-SHADOW];
#ifdef A2_NATIVE_MESH
                        if(a2_mesh_live_writes_watched)rgb=display_from_555(value);
#endif
                        SHADOW_RGB[dst-SHADOW]=rgb;
                    }
                    *dst=value;
#ifdef A2_NATIVE_MESH
                    if(a2_mesh_live_writes_watched&&(sx!=dx||sy!=dy))a2_mesh_live_store(tx,ty,value);
#endif
                }
        return;
    }
    if (c >= 0xA0 && c < 0xC0) {       /* cpu -> vram */
        vw_x = fifo[1] & 0x3FF; vw_y = (fifo[1] >> 16) & 0x1FF;
        vw_w = ((fifo[2] - 1) & 0x3FF) + 1;
        vw_h = (((fifo[2] >> 16) - 1) & 0x1FF) + 1;
#ifdef A2_CINEMA_EXPANSION
        cinema_vram_write(vw_x,vw_y,vw_w,vw_h);
#endif
#ifdef A2_INPUT_PROMPTS
        a2_input_prompts_vram_changed(vw_x,vw_y,vw_w,vw_h);
#endif
        vw_cx = vw_cy = 0;
        vw_zeros = vw_total = vw_b15 = 0;
        in_vram_write = 1;
        return;
    }
    if (c >= 0xC0 && c < 0xE0) {       /* vram -> cpu */
        vr_x = fifo[1] & 0x3FF; vr_y = (fifo[1] >> 16) & 0x1FF;
        vr_w = ((fifo[2] - 1) & 0x3FF) + 1;
        vr_h = (((fifo[2] >> 16) - 1) & 0x1FF) + 1;
        vr_cx = vr_cy = 0;
        in_vram_read = 1;
        return;
    }
    switch (c) {
    case 0xE1: g.texpage = p[0] & 0xFFFF; break;
    case 0xE2: g.texwin = p[0] & 0xFFFFF; break;
    case 0xE3: g.dax1 = p[0] & 0x3FF; g.day1 = (p[0] >> 10) & 0x1FF; break;
    case 0xE4:
        g.dax2 = p[0] & 0x3FF; g.day2 = (p[0] >> 10) & 0x1FF;
#ifdef A2_CINEMA_EXPANSION
        cinema_area();
#endif
        break;
    case 0xE5:
        g.ofx = ((int32_t)((p[0] & 0x7FF) << 21)) >> 21;
        g.ofy = ((int32_t)(((p[0] >> 11) & 0x7FF) << 21)) >> 21;
#ifdef A2_CINEMA_EXPANSION
        if((cinema_scene>=0&&(g.ofx||g.ofy!=cinema_scene*256)) ||
           (cinema_text>=0&&(g.ofx||g.ofy!=cinema_text*256))) {
            if(!g.ofx && (g.ofy==0||g.ofy==256)) {
                /* Beginning the back buffer must retain the completed front
                 * surface if presentation occurs before the new scene seals. */
                if(cinema_scene>=0)cinema_ready[cinema_scene]=0;
                cinema_scene=cinema_text=-1;
            } else cinema_invalidate();
        }
#endif
        break;
    case 0xE6: break;                  /* mask */
    }
}

uint32_t gpu_read(void) {
    status_polls=0;
    if (!in_vram_read) return 0;
    uint32_t v = 0;
    for (int half = 0; half < 2; half++) {
        v |= (uint32_t)*vram_px(vr_x + vr_cx, vr_y + vr_cy) << (half * 16);
        if (++vr_cx >= vr_w) { vr_cx = 0; vr_cy++; }
        if (vr_cy >= vr_h) { in_vram_read = 0; break; }
    }
    return v;
}

void gpu_gp1(uint32_t w) {
    status_polls=0;
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
    model_minify_base.word=model_minify_write=model_minify_pair=0;model_minify_tracking=0;
#endif
    int c = (w >> 24) & 0x3F;
    switch (c) {
    case 0x00:                         /* reset */
        fine_gpu_sync();
        gpu_model_depth_barrier();
#ifdef A2_NATIVE_MESH
        mesh_coverage_flush();mesh_pixel_owner=0;
        a2_mesh_live_reset();fifo_mesh_token=0;mesh_billboard_depth=0;
#ifdef A2_DIALOGUE_PACKETS
        a2_dialogue_packets_reset();fifo_dialogue_token=0;
#endif
#ifdef A2_NATIVE_BILLBOARD
        a2_native_billboard_reset();fifo_billboard_token=0;
#endif
#endif
#ifdef A2_CINEMA_EXPANSION
        cinema_invalidate();
#endif
#ifdef A2_HD_FONTS
        a2_hd_font_reset();
        hd_matches_reset();
#endif
#ifdef A2_HUD_PRESENT
        a2_hud_present_reset();fifo_hud_token=0;hud_anchor=-1;ir1_mirror=IR==1&&SHADOW;
#endif
        memset(&g, 0, sizeof g);
        g.disp_w = 320; g.disp_h = 240;
        fifo_n = in_vram_write = in_vram_read = in_polyline = 0;
        break;
    case 0x01: fifo_n = 0; break;
    case 0x02: break;                  /* ack irq */
    case 0x03: g.display_on = !(w & 1); break;
    case 0x04: break;                  /* dma dir */
    case 0x05: {                       /* display address (framebuffer flip) */
        int nx = w & 0x3FF, ny = (w >> 10) & 0x1FF;
        extern uint32_t gpu_flips;
        if (nx != g.disp_x || ny != g.disp_y) gpu_flips++;
        g.disp_x = nx; g.disp_y = ny;
        break;
    }
    case 0x06:                         /* horizontal display range (X1..X2) */
        g.hrange_x1 = w & 0xFFF; g.hrange_x2 = (w >> 12) & 0xFFF;
        if (getenv("A2_DISPLOG"))
            fprintf(stderr, "gp1_06: X1=%d X2=%d (span=%d dotclk)\n",
                    g.hrange_x1, g.hrange_x2, g.hrange_x2 - g.hrange_x1);
        break;
    case 0x07: {                       /* vertical display range */
        int y1 = w & 0x3FF, y2 = (w >> 10) & 0x7FF;
        g.vrange_y1 = y1;
        g.vrange_lines = y2 - y1;
        break;
    }
    case 0x08: {
        static const int wt[8] = {256, 320, 512, 640, 368, 384, 512, 640};
        g.disp_w = wt[(w & 3) | ((w >> 4) & 4)];
        /* 480 source rows require both high vertical resolution and interlace. */
        g.disp_h = (w & 0x24) == 0x24 ? 480 : 240;
        break;
    }
    case 0x10: break;                  /* info -> GPUREAD; rarely checked */
    }
}

void psx_vblank_tick(void);

/* The proven GAME00 return after both synchronous DrawOTag submissions.
 * Validate packet consumption while their guest owners are still alive;
 * next-frame actor/packet memory reuse must not discard finished pixels.
 * Any later GPU write still retires the published alternate display ROI. */
void gpu_scene_submit_complete(void) {
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
    model_minify_base.word=model_minify_write=model_minify_pair=0;model_minify_tracking=0;
#endif
#ifdef A2_NATIVE_MESH
    mesh_coverage_flush();
    if(a2_mesh_live_enabled)a2_mesh_live_finalize_at(psx_frame_no,"scene-submit");
#endif
}

/* A2_RAWDUMP=N: write raw 16bpp VRAM (incl. bit15) at frame N */
void gpu_vblank(void) {
    status_polls=0;
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
    model_minify_base.word=model_minify_write=model_minify_pair=0;model_minify_tracking=0;
#endif
#ifdef A2_NATIVE_MESH
    mesh_coverage_flush();
    if(a2_mesh_live_enabled&&mesh_coverage_tracing()&&psx_frame_no%60==0)fprintf(stderr,
        "nativemesh-owned-coverage: frame=%u pixels=%llu outside=%llu immutable_misses=%llu\n",psx_frame_no,
        (unsigned long long)mesh_coverage_trace.pixels,(unsigned long long)mesh_coverage_trace.outside,
        (unsigned long long)mesh_coverage_trace.identity_misses);
    if(a2_mesh_live_enabled)a2_mesh_live_finalize_at(psx_frame_no,"vblank");
#endif
    g.odd ^= 1;
    gpu_frames++;
    static int rawat = -2;
    if (rawat == -2) {
        const char *e = getenv("A2_RAWDUMP");
        rawat = e ? atoi(e) : -1;
    }
    if (getenv("A2_TRISTAT") && gpu_frames % 100 == 0 && gpu_tri_total) {
        fprintf(stderr, "tristat@%d: total=%d rejected=%d\n",
                gpu_frames, gpu_tri_total, gpu_tri_rejected);
        gpu_tri_total = gpu_tri_rejected = 0;
    }
    if (rawat > 0 && gpu_frames == rawat) {
        FILE *f = fopen("/tmp/vram_raw.bin", "wb");
        if (f) { fwrite(GPU_VRAM, 2, 1024 * 512, f); fclose(f); }
        fprintf(stderr, "raw vram dumped at frame %d\n", gpu_frames);
    }
}

uint32_t gpu_stat(void) {
    /* long GPUSTAT poll loops (interlace-field waits) must observe time
     * passing; advance a frame every N consecutive reads. GPU commands,
     * data reads and an actual vblank reset the wait. Accumulating ordinary
     * DrawSync checks across submissions can present a cleared framebuffer
     * before its redraw (visible as black flashes in single-buffer menus). */
    if (++status_polls >= 256) { status_polls = 0; psx_vblank_tick(); }
    return 0x1C000000u | ((uint32_t)g.odd << 31) |
           (g.display_on ? 0 : 0x00800000u);
}

/* display fetch for the platform layer */
void gpu_get_display(int *x, int *y, int *w, int *h, int *on) {
#ifdef A2_WORLD_PRECISION
    if (world_precision_enabled)
        world_precision_trace_display((uint32_t)gpu_frames,g.disp_x,g.disp_y,g.disp_w,g.disp_h);
#endif
    *x = g.disp_x; *y = g.disp_y; *w = g.disp_w;
    *h = g.disp_h;
    /* Horizontal display range (GP1 06) sets the actually-visible width:
     * visible_px = (X2 - X1) / cycles_per_pixel, where cycles_per_pixel is
     * fixed by the dot-clock (GP1 08 resolution).  The NOW LOADING screen
     * uses a 256-wide framebuffer but a half-width (128px) visible window
     * with two side-by-side buffers; ignoring GP1 06 shows the extra 128px
     * of adjacent VRAM (garbage/doubling). */
    if (g.hrange_x2 > g.hrange_x1) {
        int cyc = *w >= 640 ? 4 : *w >= 512 ? 5 : *w >= 384 ? 7 :
                  *w >= 320 ? 8 : 10;               /* 640/512/368/320/256 */
        int vis = (g.hrange_x2 - g.hrange_x1) / cyc;
        if (vis > 0 && vis < *w) *w = vis;
    }
    /* GP1(07) counts field scanlines. In 480-line interlace each field-line
     * spans two source rows; the platform presents their complete image. */
    int visible_h = g.vrange_lines * (g.disp_h == 480 ? 2 : 1);
    if (visible_h > 0 && visible_h < *h)
        *h = visible_h;
    *on = g.display_on;
    if (getenv("A2_DISPLOG")) {
        static int lw2, lx2, lh2;
        if (*w != lw2 || *x != lx2 || *h != lh2) {   /* log on change */
            lw2 = *w; lx2 = *x; lh2 = *h;
            fprintf(stderr, "disp: x=%d y=%d w=%d h=%d vlines=%d y1=%d "
                    "hrange=%d..%d (hspan=%d) on=%d\n", *x, *y, *w, *h,
                    g.vrange_lines, g.vrange_y1,
                    g.hrange_x1, g.hrange_x2, g.hrange_x2 - g.hrange_x1, *on);
        }
    }
}

/* Position of the picture inside the TV raster (a virtual canvas of
 * standard NTSC visible size).  GP1(06)/(07) place the picture: the
 * standard full-screen range starts at X1=608 dotclk / Y1=16 lines;
 * offsets from those defaults shift the picture on screen (the NOW
 * LOADING overlay uses this to park a 128x32 window bottom-right). */
void gpu_get_raster(int *xoff, int *yoff, int *cw, int *ch) {
    int mode_w = g.disp_w ? g.disp_w : 320;
    int vscale = g.disp_h == 480 ? 2 : 1;
    int cyc = mode_w >= 640 ? 4 : mode_w >= 512 ? 5 : mode_w >= 384 ? 7 :
              mode_w >= 320 ? 8 : 10;
    *cw = 2560 / cyc;                  /* standard visible width in px */
    *ch = 240 * vscale;
    *xoff = 0; *yoff = 0;
    if (g.hrange_x2 > g.hrange_x1) {
        int xo = (g.hrange_x1 - 608) / cyc;
        if (xo > 0) *xoff = xo;
    }
    if (g.vrange_lines > 0) {
        int yo = (g.vrange_y1 - 16) * vscale;
        if (yo > 0) *yoff = yo;
    }
}
