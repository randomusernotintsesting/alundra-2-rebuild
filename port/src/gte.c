/* PS1 GTE (cop2) — fixed-point geometry coprocessor.
 * Semantics per psx-spx; saturation flags for the common paths. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef A2_WORLD_PRECISION
#include "world_precision.h"
#endif

static int32_t D[32];                  /* data regs */
static int32_t C[32];                  /* ctrl regs */
static uint32_t FLAG;

#define VXY(n) D[(n) * 2]
#define VZ(n)  D[(n) * 2 + 1]
#define IR0 D[8]
#define IR1 D[9]
#define IR2 D[10]
#define IR3 D[11]
#define MAC0 D[24]
#define MAC1 D[25]
#define MAC2 D[26]
#define MAC3 D[27]

#define TRX C[5]
#define TRY C[6]
#define TRZ C[7]
#define OFX C[24]
#define OFY C[25]
#define H   C[26]
#define DQA C[27]
#define DQB C[28]
#define ZSF3 C[29]
#define ZSF4 C[30]

static inline int16_t mx(int m, int r, int c_) {
    /* matrix m: 0=rotation(C0-4) 1=light(C8-12) 2=color(C16-20) */
    int base = m == 0 ? 0 : m == 1 ? 8 : 16;
    int idx = r * 3 + c_;
    int32_t w = C[base + idx / 2];
    return (int16_t)(idx & 1 ? w >> 16 : w);
}

static inline int64_t A(int ch, int64_t v) {       /* MAC1-3 44-bit check */
    if (v >= ((int64_t)1 << 43)) FLAG |= 1u << (30 - (ch - 1));
    if (v < -((int64_t)1 << 43)) FLAG |= 1u << (27 - (ch - 1));
    /* Retain low44 bits and sign-extend without shifting a negative value.
     * Both cast and subtraction remain inside their signed64 ranges. */
    uint64_t low=(uint64_t)v & ((UINT64_C(1)<<44)-1);
    return (int64_t)(low ^ (UINT64_C(1)<<43)) - (INT64_C(1)<<43);
}

static inline int32_t limB(int ch, int32_t v, int lm) {  /* IR1-3 */
    int32_t mn = lm ? 0 : -0x8000;
    if (v < mn) { FLAG |= 1u << (24 - (ch - 1)); return mn; }
    if (v > 0x7FFF) { FLAG |= 1u << (24 - (ch - 1)); return 0x7FFF; }
    return v;
}

static inline int32_t limC(int ch, int32_t v) {    /* color fifo 0..255 */
    if (v < 0) { FLAG |= 1u << (21 - (ch - 1)); return 0; }
    if (v > 255) { FLAG |= 1u << (21 - (ch - 1)); return 255; }
    return v;
}

static inline int32_t limD(int64_t v) {            /* SZ3/OTZ 0..FFFF */
    if (v < 0) { FLAG |= 1u << 18; return 0; }
    if (v > 0xFFFF) { FLAG |= 1u << 18; return 0xFFFF; }
    return (int32_t)v;
}

static inline int32_t limG(int axis, int64_t v) {  /* SX/SY -400..3FF */
    if (v < -0x400) { FLAG |= axis ? 1u << 13 : 1u << 14; return -0x400; }
    if (v > 0x3FF) { FLAG |= axis ? 1u << 13 : 1u << 14; return 0x3FF; }
    return (int32_t)v;
}

static inline int32_t limH(int64_t v) {            /* IR0 0..1000 */
    if (v < 0) { FLAG |= 1u << 12; return 0; }
    if (v > 0x1000) { FLAG |= 1u << 12; return 0x1000; }
    return (int32_t)v;
}

static uint32_t gte_div(uint32_t h, uint32_t sz3) {
    if (sz3 == 0 || h >= sz3 * 2) { FLAG |= 1u << 17; return 0x1FFFF; }
    uint32_t n = ((uint64_t)h * 0x20000 / sz3 + 1) / 2;
    return n > 0x1FFFF ? 0x1FFFF : n;
}

static void push_sxy(int32_t x, int32_t y) {
    D[12] = D[13]; D[13] = D[14];
    D[14] = (int32_t)((x & 0xFFFF) | (y << 16));
}
static void push_sz(int32_t z) {
    D[16] = D[17]; D[17] = D[18]; D[18] = D[19]; D[19] = z;
}
static int a2_rgbprobe = -1;
static void push_rgb(int r, int g, int b, int c_) {
    if (a2_rgbprobe < 0) a2_rgbprobe = getenv("A2_RGBPROBE") ? 1 : 0;
    if (a2_rgbprobe) {
        uint32_t d6t = ((uint32_t)D[6] >> 24) & 0xFF;
        if (d6t >= 0x20 && d6t <= 0x3F) {   /* poly-code in RGBC = model draw */
            static int n;
            if (n++ < 20)
                fprintf(stderr, "pushrgb: c_=%02X D6=%08X -> rgb=%02X,%02X,%02X"
                        " D22out=%08X\n", c_, (uint32_t)D[6],
                        r & 0xFF, g & 0xFF, b & 0xFF,
                        (uint32_t)((uint32_t)(r&0xFF) | ((g&0xFF)<<8) |
                                   ((b&0xFF)<<16) | ((uint32_t)c_<<24)));
        }
    }
    D[20] = D[21]; D[21] = D[22];
    D[22] = (int32_t)((uint32_t)r | ((uint32_t)g << 8) |
                      ((uint32_t)b << 16) | ((uint32_t)c_ << 24));
}

static void rtp(int n, int sf, int last) {
#ifdef A2_WORLD_PRECISION
    /* RTPT's FLAG is sticky across its three vertices. Provenance must judge
     * each vertex by its own flags: an off-screen first vertex must not void
     * on-screen siblings. The guest-visible FLAG is the same OR afterwards. */
    uint32_t sticky_flag = FLAG; FLAG = 0;
#endif
    int16_t vx = (int16_t)VXY(n), vy = (int16_t)(VXY(n) >> 16),
            vz = (int16_t)VZ(n);
    int64_t m1 = A(1, ((int64_t)TRX * 4096) + mx(0,0,0)*vx + mx(0,0,1)*vy + mx(0,0,2)*vz);
    int64_t m2 = A(2, ((int64_t)TRY * 4096) + mx(0,1,0)*vx + mx(0,1,1)*vy + mx(0,1,2)*vz);
    int64_t m3 = A(3, ((int64_t)TRZ * 4096) + mx(0,2,0)*vx + mx(0,2,1)*vy + mx(0,2,2)*vz);
    MAC1 = (int32_t)(m1 >> (sf * 12));
    MAC2 = (int32_t)(m2 >> (sf * 12));
    MAC3 = (int32_t)(m3 >> (sf * 12));
    IR1 = limB(1, MAC1, 0);
    IR2 = limB(2, MAC2, 0);
    IR3 = limB(3, MAC3, 0);
    int32_t sz3 = limD(m3 >> 12);
    push_sz(sz3);
    uint32_t q = gte_div((uint32_t)H, (uint32_t)sz3);
    int64_t xt = (int64_t)q * IR1;
    /* A2_WIDE: squeeze the projected X around the screen center; the
     * 16:9 presentation stretch (main.c) restores proportions -> the
     * 3D FOV widens while CPU-authored 2D stays untouched here */
    { int a2_wide(void); if (a2_wide()) {
#ifdef A2_WORLD_PRECISION
        xt = world_precision_wide_x(xt);
#else
        xt = xt * 3 / 4;
#endif
    } }
    int64_t x = xt + OFX;
    int64_t y = (int64_t)q * IR2 + OFY;
    MAC0 = (int32_t)y;
    push_sxy(limG(0, x >> 16), limG(1, y >> 16));
#ifdef A2_WORLD_PRECISION
    if (world_precision_enabled) {
        extern uint32_t psx_frame_no;
        /* IR1/IR2 saturation is part of the defined screen projection;
         * IR3 saturation does not alter its unsigned SZ3 divisor. Neither
         * invalidates exact XY provenance. Reject accumulator overflow,
         * depth/divide clipping and saturated screen coordinates as before. */
        world_precision_gte_push((uint32_t)D[14],x,y,(double)m3/4096.0,
                                 sf==1 && H>0 && !(FLAG&0x7e07e000u));
        if(world_camera_enabled && world_precision_camera_pending()) {
            if(world_precision_trace_active(psx_frame_no)) {
                world_precision_vertex native;
                int native_valid=world_precision_gte_read(14,(uint32_t)D[14],&native);
                world_precision_trace(psx_frame_no,"project-native",world_precision_producer_pc,0,
                                      native_valid?&native:NULL);
            }
            int16_t rotation[9];
            for(int row=0;row<3;row++)for(int col=0;col<3;col++)
                rotation[row*3+col]=mx(0,row,col);
            const int64_t mac[3]={m1,m2,m3};
            int a2_wide(void);
            world_precision_camera_project(mac,rotation,H,OFX,OFY,a2_wide());
        }
        if(world_precision_trace_active(psx_frame_no)) {
            world_precision_vertex v;
            int valid=world_precision_gte_read(14,(uint32_t)D[14],&v);
            world_precision_trace(psx_frame_no,"project",world_precision_producer_pc,0,
                                  valid?&v:NULL);
        }
    }
    FLAG |= sticky_flag;
#endif
    if (last) {
        int64_t dq = (int64_t)q * DQA + DQB;
        MAC0 = (int32_t)dq;
        IR0 = limH(dq >> 12);
    }
}

static void nc_core(int n, int sf, int lm, int depth, int color) {
    /* NCS/NCCS/NCDS family: light matrix * V -> IR, then color matrix */
    int16_t vx = (int16_t)VXY(n), vy = (int16_t)(VXY(n) >> 16),
            vz = (int16_t)VZ(n);
    int64_t m1 = A(1, (int64_t)mx(1,0,0)*vx + mx(1,0,1)*vy + mx(1,0,2)*vz);
    int64_t m2 = A(2, (int64_t)mx(1,1,0)*vx + mx(1,1,1)*vy + mx(1,1,2)*vz);
    int64_t m3 = A(3, (int64_t)mx(1,2,0)*vx + mx(1,2,1)*vy + mx(1,2,2)*vz);
    MAC1 = (int32_t)(m1 >> (sf * 12));
    MAC2 = (int32_t)(m2 >> (sf * 12));
    MAC3 = (int32_t)(m3 >> (sf * 12));
    IR1 = limB(1, MAC1, lm); IR2 = limB(2, MAC2, lm); IR3 = limB(3, MAC3, lm);
    /* color matrix * IR + BK */
    m1 = A(1, ((int64_t)C[13] << 12) + mx(2,0,0)*IR1 + mx(2,0,1)*IR2 + mx(2,0,2)*IR3);
    m2 = A(2, ((int64_t)C[14] << 12) + mx(2,1,0)*IR1 + mx(2,1,1)*IR2 + mx(2,1,2)*IR3);
    m3 = A(3, ((int64_t)C[15] << 12) + mx(2,2,0)*IR1 + mx(2,2,1)*IR2 + mx(2,2,2)*IR3);
    MAC1 = (int32_t)(m1 >> (sf * 12));
    MAC2 = (int32_t)(m2 >> (sf * 12));
    MAC3 = (int32_t)(m3 >> (sf * 12));
    IR1 = limB(1, MAC1, lm); IR2 = limB(2, MAC2, lm); IR3 = limB(3, MAC3, lm);
    if (color) {                       /* NCCx/NCDx: multiply by RGBC */
        int r = D[6] & 0xFF, g = (D[6] >> 8) & 0xFF, b = (D[6] >> 16) & 0xFF;
        int64_t c1 = ((int64_t)r * IR1) << 4;
        int64_t c2 = ((int64_t)g * IR2) << 4;
        int64_t c3 = ((int64_t)b * IR3) << 4;
        if (depth) {                   /* NCDx: interpolate toward FC */
            c1 += ((int64_t)C[21] << 12) - c1 >= 0 ?
                  (int64_t)IR0 * limB(1, (int32_t)((((int64_t)C[21] << 12) - c1) >> (sf * 12)), 0) :
                  (int64_t)IR0 * limB(1, (int32_t)((((int64_t)C[21] << 12) - c1) >> (sf * 12)), 0);
            c2 += (int64_t)IR0 * limB(2, (int32_t)((((int64_t)C[22] << 12) - c2) >> (sf * 12)), 0);
            c3 += (int64_t)IR0 * limB(3, (int32_t)((((int64_t)C[23] << 12) - c3) >> (sf * 12)), 0);
        }
        MAC1 = (int32_t)(c1 >> (sf * 12));
        MAC2 = (int32_t)(c2 >> (sf * 12));
        MAC3 = (int32_t)(c3 >> (sf * 12));
        IR1 = limB(1, MAC1, lm); IR2 = limB(2, MAC2, lm); IR3 = limB(3, MAC3, lm);
    }
    push_rgb(limC(1, MAC1 >> 4), limC(2, MAC2 >> 4), limC(3, MAC3 >> 4),
             (D[6] >> 24) & 0xFF);
}

static void dpc(int64_t r0, int64_t g0, int64_t b0, int sf, int lm) {
    /* depth cue: MAC = color + IR0*(FC - color) */
    int64_t f1 = ((int64_t)C[21] << 12) - r0;
    int64_t f2 = ((int64_t)C[22] << 12) - g0;
    int64_t f3 = ((int64_t)C[23] << 12) - b0;
    int32_t t1 = limB(1, (int32_t)(f1 >> (sf * 12)), 0);
    int32_t t2 = limB(2, (int32_t)(f2 >> (sf * 12)), 0);
    int32_t t3 = limB(3, (int32_t)(f3 >> (sf * 12)), 0);
    MAC1 = (int32_t)((r0 + (int64_t)IR0 * t1) >> (sf * 12));
    MAC2 = (int32_t)((g0 + (int64_t)IR0 * t2) >> (sf * 12));
    MAC3 = (int32_t)((b0 + (int64_t)IR0 * t3) >> (sf * 12));
    IR1 = limB(1, MAC1, lm); IR2 = limB(2, MAC2, lm); IR3 = limB(3, MAC3, lm);
    push_rgb(limC(1, MAC1 >> 4), limC(2, MAC2 >> 4), limC(3, MAC3 >> 4),
             (D[6] >> 24) & 0xFF);
}

uint32_t gte_op_hist[64];

/* A2_MODELCAP=frame: for one frame, log every RTPS/RTPT input vertex
 * set together with the current rotation matrix + translation to
 * A2_MODELCAP_OUT (default /tmp/a2_modelcap.txt). Offline tooling
 * reconstructs posed meshes from these lines (scripts/a2/model_rip.py). */
static FILE *mcap_f;
static int mcap_from = -2;
extern uint32_t psx_frame_no;
int a2_modelcap_active(void) {
    static int span = -1;
    if (mcap_from == -2) {
        const char *e = getenv("A2_MODELCAP");
        mcap_from = e ? atoi(e) : -1;
        const char *n = getenv("A2_MODELCAP_N");
        span = n ? atoi(n) : 2;        /* OT is drawn 1 frame after build */
        if (span < 1) span = 1;
    }
    return mcap_from >= 0 && psx_frame_no >= (uint32_t)mcap_from &&
           psx_frame_no < (uint32_t)mcap_from + span;
}
FILE *a2_modelcap_file(void) {
    if (!mcap_f) {
        const char *p = getenv("A2_MODELCAP_OUT");
        mcap_f = fopen(p ? p : "/tmp/a2_modelcap.txt", "w");
    }
    return mcap_f;
}
/* input verts captured pre-execution; screen coords logged post */
static int mcap_nv;
static int16_t mcap_in[3][3];
static void mcap_grab(int nv) {
    mcap_nv = nv;
    for (int i = 0; i < nv; i++) {
        mcap_in[i][0] = (int16_t)D[i * 2];
        mcap_in[i][1] = (int16_t)(D[i * 2] >> 16);
        mcap_in[i][2] = (int16_t)D[i * 2 + 1];
    }
}
static void mcap_emit(void) {
    FILE *f = a2_modelcap_file();
    if (!f) return;
    int nv = mcap_nv;
    fprintf(f, "RTP f%u n%d", psx_frame_no, nv);
    for (int i = 0; i < nv; i++)
        fprintf(f, " v%d=%d,%d,%d", i, mcap_in[i][0], mcap_in[i][1],
                mcap_in[i][2]);
    /* screen output: SXY FIFO holds the last-pushed results.  For RTPS
     * (nv=1) the result is SXY2=D[14]; for RTPT the three are
     * D[12],D[13],D[14].  Log them so the offline tool maps each emitted
     * GPU primitive vertex (screen coords) back to a model vertex. */
    for (int i = 0; i < nv; i++) {
        uint32_t sxy = D[12 + (3 - nv) + i];
        fprintf(f, " s%d=%d,%d", i, (int16_t)sxy, (int16_t)(sxy >> 16));
    }
    fprintf(f, " R=%d,%d,%d,%d,%d,%d,%d,%d,%d TR=%d,%d,%d\n",
            (int16_t)C[0], (int16_t)(C[0] >> 16), (int16_t)C[1],
            (int16_t)(C[1] >> 16), (int16_t)C[2], (int16_t)(C[2] >> 16),
            (int16_t)C[3], (int16_t)(C[3] >> 16), (int16_t)C[4],
            (int32_t)C[5], (int32_t)C[6], (int32_t)C[7]);
}

void gte_cmd(uint32_t op) {
#ifdef A2_WORLD_PRECISION
    if(world_camera_enabled && (op&0x3f)!=0x01)world_precision_camera_disarm();
#endif
    gte_op_hist[op & 0x3F]++;
    int cap = a2_modelcap_active();
    if (cap) {
        int o = op & 0x3F;
        if (o == 0x01) mcap_grab(1);
        else if (o == 0x30) mcap_grab(3);
        else cap = 0;
    }
    int sf = (op >> 19) & 1;
    int lm = (op >> 10) & 1;
    FLAG = 0;
    switch (op & 0x3F) {
    case 0x01: rtp(0, sf, 1); break;                       /* RTPS */
    case 0x06: {                                           /* NCLIP */
        int16_t x0 = (int16_t)D[12], y0 = (int16_t)(D[12] >> 16);
        int16_t x1 = (int16_t)D[13], y1 = (int16_t)(D[13] >> 16);
        int16_t x2 = (int16_t)D[14], y2 = (int16_t)(D[14] >> 16);
        MAC0 = (int32_t)((int64_t)x0 * (y1 - y2) + (int64_t)x1 * (y2 - y0)
                       + (int64_t)x2 * (y0 - y1));
        break;
    }
    case 0x0C: {                                           /* OP */
        int16_t d1 = (int16_t)C[0], d2 = (int16_t)C[2], d3 = (int16_t)C[4];
        MAC1 = (int32_t)(((int64_t)IR3 * d2 - (int64_t)IR2 * d3) >> (sf * 12));
        MAC2 = (int32_t)(((int64_t)IR1 * d3 - (int64_t)IR3 * d1) >> (sf * 12));
        MAC3 = (int32_t)(((int64_t)IR2 * d1 - (int64_t)IR1 * d2) >> (sf * 12));
        IR1 = limB(1, MAC1, lm); IR2 = limB(2, MAC2, lm); IR3 = limB(3, MAC3, lm);
        break;
    }
    case 0x10:                                             /* DPCS */
        dpc(((int64_t)(D[6] & 0xFF)) << 16,
            ((int64_t)((D[6] >> 8) & 0xFF)) << 16,
            ((int64_t)((D[6] >> 16) & 0xFF)) << 16, sf, lm);
        break;
    case 0x11:                                             /* INTPL */
        dpc((int64_t)IR1 << 12, (int64_t)IR2 << 12, (int64_t)IR3 << 12, sf, lm);
        break;
    case 0x12: {                                           /* MVMVA */
        int m = (op >> 17) & 3, vsel = (op >> 15) & 3, tsel = (op >> 13) & 3;
        int16_t vx, vy, vz;
        if (vsel < 3) {
            vx = (int16_t)VXY(vsel); vy = (int16_t)(VXY(vsel) >> 16);
            vz = (int16_t)VZ(vsel);
        } else { vx = (int16_t)IR1; vy = (int16_t)IR2; vz = (int16_t)IR3; }
        int64_t tx = 0, ty = 0, tz = 0;
        if (tsel == 0) { tx = TRX; ty = TRY; tz = TRZ; }
        else if (tsel == 1) { tx = C[13]; ty = C[14]; tz = C[15]; }
        else if (tsel == 2) { tx = C[21]; ty = C[22]; tz = C[23]; }
        int mm = m == 3 ? 0 : m;       /* m==3 is buggy on HW; use rot */
        int64_t m1 = A(1, (tx << 12) + mx(mm,0,0)*vx + mx(mm,0,1)*vy + mx(mm,0,2)*vz);
        int64_t m2 = A(2, (ty << 12) + mx(mm,1,0)*vx + mx(mm,1,1)*vy + mx(mm,1,2)*vz);
        int64_t m3 = A(3, (tz << 12) + mx(mm,2,0)*vx + mx(mm,2,1)*vy + mx(mm,2,2)*vz);
        MAC1 = (int32_t)(m1 >> (sf * 12));
        MAC2 = (int32_t)(m2 >> (sf * 12));
        MAC3 = (int32_t)(m3 >> (sf * 12));
        IR1 = limB(1, MAC1, lm); IR2 = limB(2, MAC2, lm); IR3 = limB(3, MAC3, lm);
        break;
    }
    case 0x13: nc_core(0, sf, lm, 1, 1); break;            /* NCDS */
    case 0x14: nc_core(0, sf, lm, 1, 1); break;            /* CDP-ish */
    case 0x16: for (int i = 0; i < 3; i++) nc_core(i, sf, lm, 1, 1); break; /* NCDT */
    case 0x1B: nc_core(0, sf, lm, 0, 1); break;            /* NCCS */
    case 0x1C: nc_core(0, sf, lm, 0, 1); break;            /* CC */
    case 0x1E: nc_core(0, sf, lm, 0, 0); break;            /* NCS */
    case 0x20: for (int i = 0; i < 3; i++) nc_core(i, sf, lm, 0, 0); break; /* NCT */
    case 0x28:                                             /* SQR */
        MAC1 = (int32_t)(((int64_t)IR1 * IR1) >> (sf * 12));
        MAC2 = (int32_t)(((int64_t)IR2 * IR2) >> (sf * 12));
        MAC3 = (int32_t)(((int64_t)IR3 * IR3) >> (sf * 12));
        IR1 = limB(1, MAC1, 1); IR2 = limB(2, MAC2, 1); IR3 = limB(3, MAC3, 1);
        break;
    case 0x29:                                             /* DCPL */
        dpc((int64_t)(D[6] & 0xFF) * IR1 << 4,
            (int64_t)((D[6] >> 8) & 0xFF) * IR2 << 4,
            (int64_t)((D[6] >> 16) & 0xFF) * IR3 << 4, sf, lm);
        break;
    case 0x2A:                                             /* DPCT */
        for (int i = 0; i < 3; i++) {
            uint32_t c0 = (uint32_t)D[20];
            dpc(((int64_t)(c0 & 0xFF)) << 16,
                ((int64_t)((c0 >> 8) & 0xFF)) << 16,
                ((int64_t)((c0 >> 16) & 0xFF)) << 16, sf, lm);
        }
        break;
    case 0x2D:                                             /* AVSZ3 */
        MAC0 = (int32_t)(((int64_t)ZSF3 * (((uint32_t)D[17] & 0xFFFF) +
               ((uint32_t)D[18] & 0xFFFF) + ((uint32_t)D[19] & 0xFFFF))));
        D[7] = limD(MAC0 >> 12);
        break;
    case 0x2E:                                             /* AVSZ4 */
        MAC0 = (int32_t)(((int64_t)ZSF4 * (((uint32_t)D[16] & 0xFFFF) +
               ((uint32_t)D[17] & 0xFFFF) + ((uint32_t)D[18] & 0xFFFF) +
               ((uint32_t)D[19] & 0xFFFF))));
        D[7] = limD(MAC0 >> 12);
        break;
    case 0x30: rtp(0, sf, 0); rtp(1, sf, 0); rtp(2, sf, 1); break;  /* RTPT */
    case 0x3D:                                             /* GPF */
        MAC1 = (int32_t)(((int64_t)IR0 * IR1) >> (sf * 12));
        MAC2 = (int32_t)(((int64_t)IR0 * IR2) >> (sf * 12));
        MAC3 = (int32_t)(((int64_t)IR0 * IR3) >> (sf * 12));
        IR1 = limB(1, MAC1, lm); IR2 = limB(2, MAC2, lm); IR3 = limB(3, MAC3, lm);
        push_rgb(limC(1, MAC1 >> 4), limC(2, MAC2 >> 4), limC(3, MAC3 >> 4),
                 (D[6] >> 24) & 0xFF);
        break;
    case 0x3E:                                             /* GPL */
        MAC1 = (int32_t)((((int64_t)MAC1 << (sf * 12)) + (int64_t)IR0 * IR1) >> (sf * 12));
        MAC2 = (int32_t)((((int64_t)MAC2 << (sf * 12)) + (int64_t)IR0 * IR2) >> (sf * 12));
        MAC3 = (int32_t)((((int64_t)MAC3 << (sf * 12)) + (int64_t)IR0 * IR3) >> (sf * 12));
        IR1 = limB(1, MAC1, lm); IR2 = limB(2, MAC2, lm); IR3 = limB(3, MAC3, lm);
        push_rgb(limC(1, MAC1 >> 4), limC(2, MAC2 >> 4), limC(3, MAC3 >> 4),
                 (D[6] >> 24) & 0xFF);
        break;
    case 0x3F: for (int i = 0; i < 3; i++) nc_core(i, sf, lm, 0, 1); break; /* NCCT */
    default: break;                    /* unimplemented op: leave regs */
    }
    if (FLAG & 0x7F87E000) FLAG |= 0x80000000u;
    C[31] = (int32_t)FLAG;
    if (cap) mcap_emit();
#ifdef A2_WORLD_PRECISION
    if(world_camera_enabled)world_precision_camera_disarm();
    world_precision_producer_pc=0;
#endif
}

uint32_t gte_data_read(int reg) {
    switch (reg) {
    case 7: case 16: case 17: case 18: case 19:
        return (uint32_t)D[reg] & 0xFFFF;
    case 28: case 29: {                /* ORGB from IR1-3 */
        int r = (IR1 >> 7) < 0 ? 0 : (IR1 >> 7) > 31 ? 31 : (IR1 >> 7);
        int g = (IR2 >> 7) < 0 ? 0 : (IR2 >> 7) > 31 ? 31 : (IR2 >> 7);
        int b = (IR3 >> 7) < 0 ? 0 : (IR3 >> 7) > 31 ? 31 : (IR3 >> 7);
        return (uint32_t)(r | (g << 5) | (b << 10));
    }
    case 31: return (uint32_t)D[31];
    default: return (uint32_t)D[reg];
    }
}

void gte_data_write(int reg, uint32_t v) {
#ifdef A2_WORLD_PRECISION
    if (world_precision_enabled) world_precision_gte_write(reg);
#endif
    switch (reg) {
    case 1: case 3: case 5: case 8: case 9: case 10: case 11:
        D[reg] = (int16_t)v; break;
    case 7: case 16: case 17: case 18: case 19:
        D[reg] = (int32_t)(v & 0xFFFF); break;
    case 14:                           /* SXY2: plain store, no FIFO move */
        D[14] = (int32_t)v;
        break;
    case 15:                           /* SXYP: pushes the SXY FIFO */
        push_sxy((int16_t)v, (int16_t)(v >> 16));
        break;
    case 28:                           /* IRGB */
        D[28] = (int32_t)(v & 0x7FFF);
        IR1 = (int32_t)((v & 31) << 7);
        IR2 = (int32_t)(((v >> 5) & 31) << 7);
        IR3 = (int32_t)(((v >> 10) & 31) << 7);
        break;
    case 30: {                         /* LZCS -> LZCR */
        D[30] = (int32_t)v;
        uint32_t x = (int32_t)v < 0 ? ~v : v;
        int n = 0;
        if (x == 0) n = 32;
        else while (!(x & 0x80000000u)) { x <<= 1; n++; }
        D[31] = n;
        break;
    }
    case 29: case 31: break;           /* read-only */
    default: D[reg] = (int32_t)v;
    }
}

uint32_t gte_ctrl_read(int reg) { return (uint32_t)C[reg]; }

void gte_ctrl_write(int reg, uint32_t v) {
#ifdef A2_WORLD_PRECISION
    if(world_camera_enabled)world_precision_camera_disarm();
#endif
    switch (reg) {
    case 4: case 12: case 20: case 26: case 27: case 29: case 30:
        C[reg] = (int16_t)v; break;    /* sign-extended 16-bit ctrl regs */
    case 31: break;
    default: C[reg] = (int32_t)v;
    }
}
