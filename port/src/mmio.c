/* PS1 I/O space: IRQ ctrl, DMA, timers, SPU stubs; GPU/CD in gpu.c/cdrom.c */
#ifdef A2_HAVE_EXECINFO_H
#include <execinfo.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include "psx_rt.h"
#include "spu.h"
#include "phase_timing.h"
#ifdef A2_NATIVE_MESH
#include "native_mesh_live.h"
#ifdef A2_WORLD_PRECISION
void gpu_model_depth_barrier(void);
#endif
#endif

void gpu_gp0(uint32_t w);
#if defined(A2_WORLD_PRECISION) || defined(A2_HUD_PRESENT)
void gpu_gp0_at(uint32_t w, uint32_t address);
#endif
void gpu_gp1(uint32_t w);
uint32_t gpu_stat(void);
uint32_t gpu_read(void);
uint8_t cd_read_reg(int r);
void cd_write_reg(int r, uint8_t v);
void cd_dma_read(uint32_t madr, uint32_t words);
void psx_irq_dispatch(void);
void psx_vblank_tick(void);

int mmio_log;

/* ---- IRQ ---- */
static uint32_t i_stat, i_mask;
static int istat_polls;

void psx_irq_set(int bit) { i_stat |= 1u << bit; }
int psx_irq_pending(int bit) { return (i_stat >> bit) & 1; }
uint32_t psx_irq_active(void) { return i_stat & i_mask; }

/* cooperative interrupt delivery for pure-RAM busy loops:
 * every backward-branch budget expiry raises timer IRQs (and every 4th
 * time a full vblank) so recompiled IRQ handlers can make progress */
int psx_bb_budget = 25000;
uint32_t psx_work;
uint32_t gpu_flips;
/* Work quantum = emulated CPU time per vblank period.  The real R3000A at
 * 33.87MHz fit only so much work into one 16.6ms frame; recompiled code
 * runs instantly, so heavy game frames must be stretched across several
 * vblank ticks or game logic runs 2-3x too fast (user-visible: fast
 * animations).  One unit ~ one dispatch hop / backward branch.  Default
 * calibrated against DuckStation game-fps: title/gameplay 30, cutscenes
 * ~20, menus 60.  Override: A2_WORKQ=<units>. */
static int workq(void) {
    static int q = -1;
    if (q < 0) q = getenv("A2_WORKQ") ? atoi(getenv("A2_WORKQ")) : 32000;
    return q > 1000 ? q : 32000;
}
void psx_bb_fire(void) {
    psx_bb_budget = workq();
    /* timers only here: raising VBLANK here ran the game's VSync chain
     * (sound update f_8002C52C) ~3x per presented frame -> music x3.  The
     * real vblank IRQ is raised exactly once per frame by psx_vblank_tick
     * (main.c). */
    i_stat |= (i_mask & 0x70);          /* timer0/1/2 if enabled */
    psx_irq_dispatch();
    psx_vblank_tick();
}

/* ---- DMA ---- */
static uint32_t dma_madr[7], dma_bcr[7], dma_chcr[7];
static uint32_t dpcr = 0x07654321, dicr;

static void dma_run(int ch) {
    uint32_t chcr = dma_chcr[ch];
    if (!(chcr & 0x01000000)) return;
    uint32_t madr = dma_madr[ch] & 0x1FFFFC;
    uint32_t bcr = dma_bcr[ch];
    if (ch == 2) {
#if defined(A2_NATIVE_MESH) && defined(A2_WORLD_PRECISION)
        gpu_model_depth_barrier();
#endif
        A2Phase previous = a2_phase_enter(A2_PHASE_GPU);
        if ((chcr & 0x601) == 0x401) {                /* GP0 linked list */
#ifdef A2_NATIVE_MESH
            a2_mesh_live_dma_begin(PSX_RAM,PSX_RAM_SIZE,madr,0,1);
#endif
            extern uint32_t gpu_ll_node;     /* for upload-source tracing */
            uint32_t addr = madr;
            int guard = 0;
            while ((addr & 0xFFFFFF) != 0xFFFFFF && guard++ < 1000000) {
                uint32_t hdr = lw_(addr);
                uint32_t n = hdr >> 24;
                gpu_ll_node = addr;
                for (uint32_t i = 1; i <= n; i++)
#if defined(A2_WORLD_PRECISION) || defined(A2_HUD_PRESENT)
                    gpu_gp0_at(lw_(addr + i * 4), addr + i * 4);
#else
                    gpu_gp0(lw_(addr + i * 4));
#endif
                addr = hdr & 0xFFFFFF;
                if (!addr) break;
            }
#ifdef A2_NATIVE_MESH
            a2_mesh_live_dma_end();
#ifdef A2_WORLD_PRECISION
            gpu_model_depth_barrier();
#endif
#endif
        } else if (chcr & 1) {                        /* block write to GP0 */
            uint32_t bs = bcr & 0xFFFF, num = bcr >> 16;
            if (!bs) bs = 0x10000;
            if (!num) num = 1;
#ifdef A2_NATIVE_MESH
            a2_mesh_live_dma_begin(PSX_RAM,PSX_RAM_SIZE,madr,(uint64_t)bs*num,0);
#endif
            for (uint32_t i = 0; i < bs * num; i++)
#if defined(A2_WORLD_PRECISION) || defined(A2_HUD_PRESENT)
                gpu_gp0_at(lw_(madr + i * 4), madr + i * 4);
#else
                gpu_gp0(lw_(madr + i * 4));
#endif
#ifdef A2_NATIVE_MESH
            a2_mesh_live_dma_end();
#ifdef A2_WORLD_PRECISION
            gpu_model_depth_barrier();
#endif
#endif
        } else {                                      /* VRAM -> CPU */
            uint32_t bs = bcr & 0xFFFF, num = bcr >> 16;
            if (!bs) bs = 0x10000;
            if (!num) num = 1;
            for (uint32_t i = 0; i < bs * num; i++)
                sw_(madr + i * 4, gpu_read());
        }
        a2_phase_leave(previous);
    } else if (ch == 6) {                             /* OTC */
        uint32_t n = bcr & 0xFFFF;
        if (!n) n = 0x10000;
        uint32_t cur = madr;
        for (uint32_t i = 0; i + 1 < n; i++) {
            sw_(cur, (cur - 4) & 0xFFFFFF);
            cur -= 4;
        }
        sw_(cur, 0xFFFFFF);
    } else if (ch == 3) {                             /* CDROM -> RAM */
        uint32_t n = (bcr & 0xFFFF) * ((bcr >> 16) ? (bcr >> 16) : 1);
        cd_dma_read(madr, n);
    } else if (ch == 4) {
        if (chcr & 1) {                               /* RAM -> SPU */
            uint64_t n = (uint64_t)(bcr & 0xFFFF) *
                         ((bcr >> 16) ? (bcr >> 16) : 1) * 4;
            /* Both memories repeat after a full 2 MiB RAM traversal.
             * Retain the last full traversal plus tail: identical final SPU
             * RAM/address, without billions of copies for a huge BCR. */
            if (n > PSX_RAM_SIZE) n = PSX_RAM_SIZE + n % PSX_RAM_SIZE;
            while (n) {
                uint32_t bytes = (chcr & 2) ? 4 : PSX_RAM_SIZE - madr;
                if (bytes > n) bytes = (uint32_t)n;
                spu_dma_write(PSX_RAM + madr, bytes);
                madr = (madr + ((chcr & 2) ? -4u : bytes)) & (PSX_RAM_SIZE - 1);
                n -= bytes;
            }
        }
    }
    dma_chcr[ch] = chcr & ~0x11000000;                /* done */
    if (dicr & (1u << (16 + ch))) {
        dicr |= 1u << (24 + ch);
        if (dicr & 0x800000) { psx_irq_set(3); psx_irq_dispatch(); }
    }
}

/* ---- timers: crude free-running counters ---- */
static uint32_t tmr_ticks[3];
static uint32_t tmr_mode[3], tmr_target[3];

/* per-frame timer progression (called from psx_vblank_tick) */
void mmio_timers_vblank(void) {
    tmr_ticks[0] += 0x1FFF;            /* dotclock/frame ~ 113k, scaled */
    tmr_ticks[1] += 263;               /* hblanks per NTSC frame */
    tmr_ticks[2] += 70000;             /* sysclk/8 per NTSC frame (real) */
}

/* ---- SIO0: digital pad protocol (libpad does raw port access) ----
 * Transaction: 0x01 (select) -> idle, 0x42 (poll) -> 0x41 (digital id),
 * 0x00 (TAP) -> 0x5A, 0x00 -> buttons lo, 0x00 -> buttons hi.
 * Each byte raises ACK + IRQ7 so libpad's handler advances. */
uint16_t psx_pad_buttons(void);
static int sio_phase = -1;             /* -1 idle, else byte index */
static uint8_t sio_rx;
static int sio_rx_full, sio_ack;
static int sio_ack_delay;
int sio_dbg_reads;
static uint16_t sio_ctrl, sio_mode, sio_baud;

static void sio_write_data(uint8_t v) {
    static int n;
    if (n++ < 16) {
        fprintf(stderr, "sio: tx %02X (phase %d)\n", v, sio_phase);
    }
    uint16_t btn = psx_pad_buttons();
    uint8_t resp = 0xFF;
    if (sio_phase < 0) {
        if (v == 0x01) { sio_phase = 0; resp = 0xFF; }
    } else {
        switch (sio_phase) {
        case 0: resp = (v == 0x42) ? 0x41 : 0xFF; break;  /* digital pad */
        case 1: resp = 0x5A; break;
        case 2: resp = btn & 0xFF; break;
        case 3: resp = btn >> 8; sio_phase = -2; break;   /* last byte */
        }
        sio_phase = sio_phase == -2 ? -1 : sio_phase + 1;
    }
    sio_rx = resp;
    sio_rx_full = 1;
    sio_ack = 1;
    /* /ACK arrives ~100us after the byte on real HW; libpad clears the
     * stale IRQ7 latch right after writing, so the pulse must land
     * AFTER that — delay it a few I_STAT reads */
    sio_ack_delay = 3;
    sio_dbg_reads = 6;
}

/* ---- SPU ---- */
static uint16_t spu_regs[0x300];

static uint32_t last_read_addr, last_read_count;

uint32_t psx_mmio_read(uint32_t p, int size) {
    if (p == last_read_addr) {
        if (++last_read_count == 2000000) {
            fprintf(stderr, "mmio: spinning on read %08X (value %02X)\n",
                    p, cd_read_reg(p & 3));
            void cd_dump_state(void);
            if (p >= 0x1F801800 && p < 0x1F801804) cd_dump_state();
            exit(25);
        }
    } else { last_read_addr = p; last_read_count = 0; }
    if (p >= 0x1F801C00 && p < 0x1F802000) {          /* SPU */
        static int nospu = -1;
        if (nospu < 0) nospu = getenv("A2_NOSPU") != 0;
        uint32_t off = p - 0x1F801C00;
        uint32_t r = off / 2;
        uint16_t v;
        if (nospu) {
            v = (p == 0x1F801DAE) ? (spu_regs[(0x1DAA-0x1C00)/2] & 0x3F)
                                  : spu_regs[r];
        } else v = spu_read(off & ~1u);
        if (size == 1) return (v >> ((off & 1)*8)) & 0xff;
        if (size == 4) {
            uint16_t hi = nospu ? spu_regs[r + 1] : spu_read((off & ~1u) + 2);
            return (uint32_t)v | ((uint32_t)hi << 16);
        }
        return v;
    }
    switch (p) {
    case 0x1F801070:
        if (sio_ack_delay && --sio_ack_delay == 0)
            i_stat |= 0x80;            /* delayed /ACK pulse */
        {
            static int rn;
            extern int sio_dbg_reads;
            if (sio_dbg_reads > 0) {
                sio_dbg_reads--;
                if (rn++ < 30)
                    fprintf(stderr, "istat read: %04X (delay %d)\n",
                            i_stat, sio_ack_delay);
            }
        }
        /* poll heuristic: a tight wait on vblank with no other activity */
        if (!(i_stat & 1) && ++istat_polls > 128) {
            istat_polls = 0;
            psx_vblank_tick();
            i_stat |= 1;
        }
        return i_stat;
    case 0x1F801074: return i_mask;
    case 0x1F8010F0: return dpcr;
    case 0x1F8010F4: return dicr;
    case 0x1F801810: return gpu_read();
    case 0x1F801814: return gpu_stat();
    case 0x1F801040: {                                /* JOY data */
        uint8_t v = sio_rx_full ? sio_rx : 0xFF;
        sio_rx_full = 0;
        return v;
    }
    case 0x1F801044: {                                /* JOY stat */
        static int n;
        if (n++ < 5) fprintf(stderr, "sio: stat read #%d\n", n);
        uint32_t st = 0x05;            /* TX ready 1+2 */
        if (sio_rx_full) st |= 0x02;   /* RX fifo not empty */
        if (sio_ack) { st |= 0x80; }   /* /ACK input level */
        if (sio_ack && (sio_ctrl & 0x1000)) st |= 0x200;  /* IRQ */
        return st;
    }
    case 0x1F801048: return sio_mode;
    case 0x1F80104A: return sio_ctrl;
    case 0x1F80104E: return sio_baud;
    }
    if (p >= 0x1F801800 && p < 0x1F801804) return cd_read_reg(p & 3);
    if (p >= 0x1F801080 && p < 0x1F8010F0) {
        int ch = (p - 0x1F801080) / 16, r = (p >> 2) & 3;
        if (r == 0) return dma_madr[ch];
        if (r == 1) return dma_bcr[ch];
        if (r == 2) return dma_chcr[ch];
        return 0;
    }
    if (p >= 0x1F801100 && p < 0x1F801130) {
        int t = (p - 0x1F801100) / 16, r = (p >> 2) & 3;
        if (r == 0) {                                  /* counter value */
            /* advance slowly: double-reads must usually agree (PSY-Q
             * reads twice for 16-bit stability) yet time must pass */
            static uint32_t reads;
            if ((++reads & 7) == 0) tmr_ticks[t]++;
            /* wrap at target ONLY in reset-at-target mode (mode bit3),
             * otherwise free-run to 0xFFFF */
            uint32_t lim = ((tmr_mode[t] & 8) && tmr_target[t])
                         ? tmr_target[t] : 0xFFFF;
            return tmr_ticks[t] % (lim + 1);
        }
        if (r == 1) { uint32_t m = tmr_mode[t]; tmr_mode[t] &= ~0x1800; return m; }
        return tmr_target[t];
    }
    if (mmio_log) fprintf(stderr, "mmio: read%d %08X\n", size * 8, p);
    return 0;
}

void psx_mmio_write(uint32_t p, uint32_t v, int size) {
    if (p >= 0x1F801C00 && p < 0x1F802000) {
        void spu_write(uint32_t off, uint16_t hv);
        uint32_t off = p - 0x1F801C00;
        uint32_t r = off / 2;
        spu_regs[r] = (uint16_t)v;
        spu_write(off, (uint16_t)v);
        if (size == 4) {
            spu_regs[r + 1] = (uint16_t)(v >> 16);
            spu_write(off + 2, (uint16_t)(v >> 16));
        }
        return;
    }
    switch (p) {
    case 0x1F801070:
        if ((i_stat & 0x80) && !(v & 0x80)) {
            static int an;
            if (an++ < 8) fprintf(stderr, "istat: ack clears bit7 (v=%04X)\n",
                                  (unsigned)v);
        }
        i_stat &= v; istat_polls = 0; return;     /* ack */
    case 0x1F801074: i_mask = v; return;
    case 0x1F8010F0: dpcr = v; return;
    case 0x1F8010F4:
        dicr = (dicr & 0x7F000000 & ~(v & 0x7F000000)) | (v & 0xFFFFFF);
        return;
    case 0x1F801810: gpu_gp0(v); return;
    case 0x1F801814: gpu_gp1(v); return;
    case 0x1F801040: sio_write_data((uint8_t)v); return;
    case 0x1F801048: sio_mode = (uint16_t)v; return;
    case 0x1F80104A: {
        static int cn;
        if (cn++ < 24) fprintf(stderr, "sio: ctrl=%04X (phase %d)\n",
                               (unsigned)v, sio_phase);
        sio_ctrl = (uint16_t)v; }
        if (v & 0x10) sio_ack = 0;                    /* ack IRQ */
        if (v & 0x40) { sio_phase = -1; sio_rx_full = 0; sio_ack = 0; }
        if (!(v & 0x02)) sio_phase = -1;              /* deselect ends txn */
        return;
    case 0x1F80104E: sio_baud = (uint16_t)v; return;
    }
    if (p >= 0x1F801800 && p < 0x1F801804) { cd_write_reg(p & 3, v); return; }
    if (p >= 0x1F801080 && p < 0x1F8010F0) {
        int ch = (p - 0x1F801080) / 16, r = (p >> 2) & 3;
        if (r == 0) dma_madr[ch] = v;
        else if (r == 1) dma_bcr[ch] = v;
        else if (r == 2) { dma_chcr[ch] = v; dma_run(ch); }
        return;
    }
    if (p >= 0x1F801100 && p < 0x1F801130) {
        int t = (p - 0x1F801100) / 16, r = (p >> 2) & 3;
        if (r == 0) tmr_ticks[t] = v & 0xFFFF;
        else if (r == 1) { tmr_mode[t] = v; tmr_ticks[t] = 0; }
        else tmr_target[t] = v & 0xFFFF;
        return;
    }
    if (p >= 0x1F801000 && p < 0x1F801064) return;    /* memctrl/ram size */
    if (mmio_log) fprintf(stderr, "mmio: write%d %08X = %08X\n", size * 8, p, v);
}
