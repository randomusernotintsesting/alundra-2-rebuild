/* PSX recompiler runtime: CPU context + memory access.
 * Little-endian host assumed (x86_64 / arm64). */
#ifndef PSX_RT_H
#define PSX_RT_H
#include <stdint.h>
#include <string.h>
#ifdef A2_DIALOGUE_PACKETS
#include "dialogue_packets.h"
#endif
#ifdef A2_NATIVE_BILLBOARD
#include "native_billboard.h"
#endif
#ifdef A2_NATIVE_ACTOR_SOURCES
#include "native_actor_sources.h"
#endif
#ifdef A2_NATIVE_ACTOR_PACKETS
#include "native_actor_packets.h"
#endif
#ifdef A2_NATIVE_ACTOR_SNAPSHOT
#include "native_actor_snapshot.h"
extern uint32_t psx_frame_no;
#endif
#ifdef A2_HUD_PRESENT
#include "hud_present.h"
#endif
#ifdef A2_WORLD_PRECISION
#include "world_precision.h"
#include "world_shadow.h"
#endif

static inline void psx_precision_invalidate(uint32_t address, size_t bytes) {
#ifdef A2_DIALOGUE_PACKETS
    uint32_t dialogue_physical=address&0x1fffffffu;
    if(dialogue_physical<0x800000u){
        dialogue_physical&=0x1fffffu;
        uint64_t dialogue_end=(uint64_t)dialogue_physical+bytes;
        if((dialogue_physical<a2_dialogue_packets_watch_end&&dialogue_end>a2_dialogue_packets_watch_begin)||
           (dialogue_physical<0x1edecu&&dialogue_end>0x1e294u)||
           (dialogue_physical<0x1f2fcu&&dialogue_end>0x1f0ccu)||
           (dialogue_physical<0x35a3cu&&dialogue_end>0x359a8u)||
           (dialogue_physical<0x2037cu&&dialogue_end>0x20140u)||
           (dialogue_physical<0x2220cu&&dialogue_end>0x21d20u)||
           (dialogue_physical<0x860a8u&&dialogue_end>0x86090u)||bytes>0x200000u-dialogue_physical)
            a2_dialogue_packets_invalidate(dialogue_physical,bytes);
    }
#endif

#ifdef A2_NATIVE_BILLBOARD
    uint32_t billboard_physical=address&0x1fffffffu;
    if(a2_native_billboard_enabled && billboard_physical<0x800000u) {
        billboard_physical&=0x1fffffu;
        if((billboard_physical<a2_native_billboard_watch_end &&
            (uint64_t)billboard_physical+bytes>a2_native_billboard_watch_begin) ||
           bytes>0x200000u-billboard_physical)
            a2_native_billboard_invalidate(billboard_physical,bytes);
    }
#endif
#ifdef A2_NATIVE_ACTOR_SOURCES
    uint32_t source_physical=address&0x1fffffffu;
    if (a2_native_actor_sources_enabled && source_physical<0x800000u) {
        source_physical&=0x1fffffu;
        if ((source_physical<0x24d2cu && (uint64_t)source_physical+bytes>0x2492cu) ||
            (source_physical<a2_native_actor_sources_watch_end &&
             (uint64_t)source_physical+bytes>a2_native_actor_sources_watch_begin) ||
            bytes>0x200000u-source_physical)
            a2_native_actor_sources_invalidate(source_physical,bytes);
    }
#endif
#ifdef A2_NATIVE_ACTOR_PACKETS
    uint32_t actor_physical=address&0x1fffffffu;
    if (a2_native_actor_packets_enabled && actor_physical<0x800000u) {
        actor_physical&=0x1fffffu;
        if ((actor_physical<a2_native_actor_packets_code_end && (uint64_t)actor_physical+bytes>0x10000u) ||
            (actor_physical<a2_native_actor_packets_watch_end &&
             (uint64_t)actor_physical+bytes>a2_native_actor_packets_watch_begin) ||
            bytes>0x200000u-actor_physical)
            a2_native_actor_packets_invalidate(actor_physical,bytes);
    }
#endif
#ifdef A2_HUD_PRESENT
    uint32_t hud_physical=address&0x1fffffffu;
    if (hud_physical<0x800000u) {
        hud_physical&=0x1fffffu;
        if (__builtin_expect((hud_physical<a2_hud_present_watch_end &&
            (uint64_t)hud_physical+bytes>a2_hud_present_watch_begin) ||
            bytes>0x200000u-hud_physical,0))
            a2_hud_present_invalidate(hud_physical,bytes);
    }
#endif
#ifdef A2_WORLD_PRECISION
    if (__builtin_expect(world_precision_enabled!=0,0))
        world_precision_invalidate(address,bytes);
#else
    (void)address; (void)bytes;
#endif
}

#define PSX_RAM_SIZE 0x200000
extern uint8_t PSX_RAM[PSX_RAM_SIZE];
extern uint8_t PSX_SCRATCH[0x400];
extern uint32_t R[32];
extern uint32_t HI, LO;

void psx_break(uint32_t code);
void psx_syscall(void);
void psx_syscall_at(uint32_t pc);
void psx_call(uint32_t addr);          /* runtime dispatch by PSX address */
void psx_trap(uint32_t addr);          /* untranslatable function entered */

/* backward-branch hook: cooperative interrupt delivery in busy loops.
 * psx_work approximates emulated CPU time (one unit per dispatch hop /
 * backward branch) — used to pace game-visible vblanks to ~33.87MHz. */
extern int psx_bb_budget;
extern uint32_t psx_work;
void psx_bb_fire(void);
static inline void psx_bb(void) {
    psx_work++;
    if (--psx_bb_budget <= 0) psx_bb_fire();
}

/* flat dispatcher: segments park their successor address here and
 * return; guest control flow never uses the host stack */
extern uint32_t psx_next;

typedef struct { uint32_t addr; void (*fn)(void); } psx_func_entry;

/* cop0 / GTE hooks (gte.c, dispatch.c) */
uint32_t psx_cop0_read(int reg);
void psx_cop0_write(int reg, uint32_t v);
void psx_rfe(void);
void gte_cmd(uint32_t op);
uint32_t gte_data_read(int reg);
void gte_data_write(int reg, uint32_t v);
uint32_t gte_ctrl_read(int reg);
void gte_ctrl_write(int reg, uint32_t v);

/* MMIO (mmio.c) */
uint32_t psx_mmio_read(uint32_t phys, int size);
void psx_mmio_write(uint32_t phys, uint32_t v, int size);

/* debug: planned-upload trace (gpu.c, A2_PLANLOG=N; hooks live in gen/) */
void a2_plan_rect(const char *tag, uint32_t rect, uint32_t src, uint32_t extra);

/* A2_60 experimental 60fps gameplay (dispatch.c; hooks live in gen/):
 * main-loop VSync(2) clamped to 0 (=wait next vsync), per-frame deltas
 * halved at hooks */
int a2_60fps(void);

/* A2_RAMWATCH=hexaddr (dispatch.c): print every store touching that
 * word — recompiled inline stores and bulk copies both report here */
extern uint32_t a2_ramwatch;               /* phys addr | 1 when armed */
void a2_ramwatch_hit(uint32_t phys, uint32_t v, int size);
static inline void a2_rw_chk(uint32_t p, uint32_t v, int size) {
    if (__builtin_expect(a2_ramwatch != 0, 0) &&
        ((p & 0x1FFFFCu) == (a2_ramwatch & 0x1FFFFCu)))
        a2_ramwatch_hit(p & 0x1FFFFFu, v, size);
}

/* A2_WIDE experimental widescreen (dispatch.c): GTE projection X-term
 * scaled by 3/4 (gte.c rtp) + 16:9 presentation (main.c) */
int a2_wide(void);

#define PSX_ADDR(a) ((a) & 0x1FFFFFu)

/* phys ranges: RAM 0x00000000-0x007FFFFF (2MB mirrored),
 * scratchpad 0x1F800000-0x1F8003FF, I/O 0x1F801000-0x1F802FFF */
static inline int psx_io_p(uint32_t p) { return (p - 0x1F800000u) < 0x10000u; }

static inline uint32_t lb_(uint32_t a) {
    uint32_t p = a & 0x1FFFFFFFu;
    if (psx_io_p(p)) {
        if (p < 0x1F800400u) return PSX_SCRATCH[p & 0x3FF];
        return psx_mmio_read(p, 1);
    }
    return PSX_RAM[p & 0x1FFFFFu];
}
static inline uint32_t lh_(uint32_t a) {
    uint32_t p = a & 0x1FFFFFFFu;
    if (psx_io_p(p)) {
        if (p < 0x1F800400u) {
            uint16_t v; memcpy(&v, PSX_SCRATCH + (p & 0x3FF), 2); return v;
        }
        return psx_mmio_read(p, 2);
    }
    uint16_t v; memcpy(&v, PSX_RAM + (p & 0x1FFFFFu), 2); return v;
}
static inline uint32_t lw_(uint32_t a) {
    uint32_t p = a & 0x1FFFFFFFu;
    if (psx_io_p(p)) {
        if (p < 0x1F800400u) {
            uint32_t v; memcpy(&v, PSX_SCRATCH + (p & 0x3FF), 4); return v;
        }
        return psx_mmio_read(p, 4);
    }
    uint32_t v; memcpy(&v, PSX_RAM + (p & 0x1FFFFFu), 4); return v;
}
static inline void sb_(uint32_t a, uint32_t v) {
    uint32_t p = a & 0x1FFFFFFFu;
    if (psx_io_p(p)) {
        if (p < 0x1F800400u) {
            psx_precision_invalidate(p,1);
            PSX_SCRATCH[p & 0x3FF] = (uint8_t)v; return;
        }
        psx_mmio_write(p, v & 0xFF, 1); return;
    }
    a2_rw_chk(p, v, 1);
    psx_precision_invalidate(p & 0x1FFFFFu,1);
    PSX_RAM[p & 0x1FFFFFu] = (uint8_t)v;
}
static inline void sh_(uint32_t a, uint32_t v) {
    uint32_t p = a & 0x1FFFFFFFu;
    if (psx_io_p(p)) {
        if (p < 0x1F800400u) {
            psx_precision_invalidate(p,2);
            uint16_t x = (uint16_t)v; memcpy(PSX_SCRATCH + (p & 0x3FF), &x, 2); return;
        }
        psx_mmio_write(p, v & 0xFFFF, 2); return;
    }
    a2_rw_chk(p, v, 2);
    psx_precision_invalidate(p & 0x1FFFFFu,2);
    uint16_t x = (uint16_t)v; memcpy(PSX_RAM + (p & 0x1FFFFFu), &x, 2);
}
static inline void sw_(uint32_t a, uint32_t v) {
    uint32_t p = a & 0x1FFFFFFFu;
    if (psx_io_p(p)) {
        if (p < 0x1F800400u) {
            psx_precision_invalidate(p,4);
            memcpy(PSX_SCRATCH + (p & 0x3FF), &v, 4); return;
        }
        psx_mmio_write(p, v, 4); return;
    }
    a2_rw_chk(p, v, 4);
    psx_precision_invalidate(p & 0x1FFFFFu,4);
    memcpy(PSX_RAM + (p & 0x1FFFFFu), &v, 4);
}

/* Unaligned memory load/store (LE semantics, PCSX-style tables). The word
 * selected for merging can live in RAM or any mapped scratchpad alias. */
static inline uint32_t lwram_(uint32_t a) {
    uint32_t p = a & 0x1FFFFFFFu;
    if ((p - 0x1F800000u) < sizeof PSX_SCRATCH) {
        uint32_t v; memcpy(&v, PSX_SCRATCH + (p & 0x3FF), 4); return v;
    }
    uint32_t v; memcpy(&v, PSX_RAM + PSX_ADDR(a), 4); return v;
}
static inline void swram_(uint32_t a, uint32_t v) {
    uint32_t p = a & 0x1FFFFFFFu;
    if ((p - 0x1F800000u) < sizeof PSX_SCRATCH) {
        psx_precision_invalidate(p,4);
        memcpy(PSX_SCRATCH + (p & 0x3FF), &v, 4); return;
    }
    a2_rw_chk(a & 0x1FFFFFFFu, v, 4);
    psx_precision_invalidate(PSX_ADDR(a),4);
    memcpy(PSX_RAM + PSX_ADDR(a), &v, 4);
}
static inline uint32_t lwl_(uint32_t a, uint32_t rt) {
    static const uint32_t MASK[4] = {0xFFFFFFu, 0xFFFFu, 0xFFu, 0};
    static const int SHIFT[4] = {24, 16, 8, 0};
    uint32_t b = a & 3, mem = lwram_(a & ~3u);
    return (rt & MASK[b]) | (mem << SHIFT[b]);
}
static inline uint32_t lwr_(uint32_t a, uint32_t rt) {
    static const uint32_t MASK[4] = {0, 0xFF000000u, 0xFFFF0000u, 0xFFFFFF00u};
    static const int SHIFT[4] = {0, 8, 16, 24};
    uint32_t b = a & 3, mem = lwram_(a & ~3u);
    return (rt & MASK[b]) | (mem >> SHIFT[b]);
}
static inline void swl_(uint32_t a, uint32_t rt) {
    static const uint32_t MASK[4] = {0xFFFFFF00u, 0xFFFF0000u, 0xFF000000u, 0};
    static const int SHIFT[4] = {24, 16, 8, 0};
    uint32_t b = a & 3, m = lwram_(a & ~3u);
    swram_(a & ~3u, (m & MASK[b]) | (rt >> SHIFT[b]));
}
static inline void swr_(uint32_t a, uint32_t rt) {
    static const uint32_t MASK[4] = {0, 0xFFu, 0xFFFFu, 0xFFFFFFu};
    static const int SHIFT[4] = {0, 8, 16, 24};
    uint32_t b = a & 3, m = lwram_(a & ~3u);
    swram_(a & ~3u, (m & MASK[b]) | (rt << SHIFT[b]));
}

static inline void psx_div(int32_t n, int32_t d) {
    if (d == 0) { HI = (uint32_t)n; LO = (n >= 0) ? 0xFFFFFFFFu : 1; }
    else if (n == (int32_t)0x80000000 && d == -1) { HI = 0; LO = 0x80000000u; }
    else { HI = (uint32_t)(n % d); LO = (uint32_t)(n / d); }
}
static inline void psx_divu(uint32_t n, uint32_t d) {
    if (d == 0) { HI = n; LO = 0xFFFFFFFFu; }
    else { HI = n % d; LO = n / d; }
}

#include "scene_submit.h"

#endif
