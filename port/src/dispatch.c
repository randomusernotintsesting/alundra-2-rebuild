/* Runtime dispatch: PSX address -> recompiled C function.
 * Handles BIOS entry stubs (0xA0/0xB0/0xC0) and HLE overrides. */
#ifdef A2_HAVE_EXECINFO_H
#include <execinfo.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include "psx_rt.h"
#ifdef A2_NATIVE_SAVES
#include "native_save_guest.h"
#endif

uint8_t PSX_RAM[PSX_RAM_SIZE];
uint8_t PSX_SCRATCH[0x400];
uint32_t R[32];
uint32_t HI, LO;

extern const psx_func_entry scps_table[];
extern const int scps_table_n;
extern const psx_func_entry game00_table[], game01_table[], game02_table[],
    game03_table[], event00_table[];
extern const int game00_table_n, game01_table_n, game02_table_n,
    game03_table_n, event00_table_n;

/* overlays all load at 0x800811D8; the first word of the loaded image
 * is the overlay ID (GAME00=4 EVENT00=5 GAME01=6 GAME02=7 GAME03=8) */
#define OVERLAY_BASE 0x800811D8u

void kernel_syscall(uint32_t table, uint32_t num);   /* kernel_hle.c */

#define MAX_OVR 256
static struct { uint32_t addr; void (*fn)(void); } ovr[MAX_OVR];
static int n_ovr;

/* Guest tables are immutable, but overlays reuse the same addresses and HLE
 * registrations can replace a resolved target. Keep exact address/overlay
 * tags; never fold RAM aliases here (psx_call owns its two lookup attempts).
 * Only successful resolutions are cached so misses retain their diagnostics
 * and interpreter fallback. A collision simply replaces one bounded slot. */
#define DISPATCH_CACHE_SIZE 4096u
static struct {
    uint32_t addr, overlay_id;
    void (*fn)(void);
} dispatch_cache[DISPATCH_CACHE_SIZE];

void psx_register_hle(uint32_t addr, void (*fn)(void)) {
    ovr[n_ovr].addr = addr;
    ovr[n_ovr].fn = fn;
    n_ovr++;
    memset(dispatch_cache, 0, sizeof dispatch_cache);
}

static void (*bsearch_table(const psx_func_entry *t, int n,
                            uint32_t addr))(void) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (t[mid].addr == addr) return t[mid].fn;
        if (t[mid].addr < addr) lo = mid + 1; else hi = mid - 1;
    }
    return 0;
}

static void (*lookup_uncached(uint32_t addr, uint32_t id))(void) {
    for (int i = 0; i < n_ovr; i++)
        if (ovr[i].addr == addr) return ovr[i].fn;
    if (addr >= OVERLAY_BASE) {
        switch (id) {
        case 4: return bsearch_table(game00_table, game00_table_n, addr);
        case 5: return bsearch_table(event00_table, event00_table_n, addr);
        case 6: return bsearch_table(game01_table, game01_table_n, addr);
        case 7: return bsearch_table(game02_table, game02_table_n, addr);
        case 8: return bsearch_table(game03_table, game03_table_n, addr);
        default:
            fprintf(stderr, "psx_call: overlay addr 0x%08X but no overlay "
                    "loaded (id word=%u)\n", addr, id);
            return 0;
        }
    }
    return bsearch_table(scps_table, scps_table_n, addr);
}

static void (*lookup(uint32_t addr))(void) {
    uint32_t id = 0;
    if (addr >= OVERLAY_BASE)
        memcpy(&id, PSX_RAM + (OVERLAY_BASE & 0x1FFFFFu), sizeof id);
    uint32_t slot = ((addr >> 2) ^ (addr >> 14) ^ (id * 2654435761u)) &
                    (DISPATCH_CACHE_SIZE - 1u);
    if (dispatch_cache[slot].fn && dispatch_cache[slot].addr == addr &&
        dispatch_cache[slot].overlay_id == id)
        return dispatch_cache[slot].fn;
    void (*fn)(void) = lookup_uncached(addr, id);
    if (fn) {
        dispatch_cache[slot].addr = addr;
        dispatch_cache[slot].overlay_id = id;
        dispatch_cache[slot].fn = fn;
    }
    return fn;
}

int psx_call_depth;
#define call_depth psx_call_depth
uint32_t psx_ring[32];
int psx_hotlog;
int psx_dslog;

/* Stack-relief trampoline: threaded code (jr-chains between functions)
 * and game-level longjmp grow the HOST stack without bound, but the
 * whole MIPS machine state lives in the global R[]/RAM — host frames
 * are only a cache of return continuations, and the universal-return
 * rule (jr ra != entry ra -> forward dispatch) reconstructs control
 * flow from machine state alone.  So when nesting gets deep we cut the
 * host stack back to the boot anchor and resume at the pending address
 * with a clean stack. */
#include <setjmp.h>
static jmp_buf run_anchor;
static uint32_t run_pending;
static int anchor_set;
extern int psx_in_irq;                 /* kernel_hle.c */

void psx_run(uint32_t entry) {
    void a2_ramwatch_init(void);
    a2_ramwatch_init();
    (void)run_anchor; (void)anchor_set;
    run_pending = entry;
    psx_call(run_pending);
}

int psx_ring_i;

/* Flat dispatcher.  MIPS control flow lives entirely in machine state
 * (R[31] + the game's own stack); segments execute until their first
 * call/jump, park the next address in psx_next and return.  The host
 * stack is never used for guest control flow, so threaded code, longjmp
 * and coroutine tricks cannot grow it.
 *
 * psx_call(entry) runs a guest call to completion: it plants a sentinel
 * return address, dispatches from `entry` until control returns to the
 * sentinel.  Nestable (kernel callbacks, IRQ handlers). */
uint32_t psx_next;

uint32_t mover_hits, tick_hits;   /* A2_PROBE: player mover/tick reach counters */
uint32_t setpoly_n[6];            /* GT4,G4,G3,GT3,FT4,F4 init call counts */

void psx_call(uint32_t addr) {
    static uint32_t exec_depth;
    uint32_t sentinel = 0xFFAA0000u | (++exec_depth << 2);
    uint32_t save_ra = R[31];
    uint32_t save_next = psx_next;
    R[31] = sentinel;
    psx_next = addr;
    while (psx_next != sentinel) {
        uint32_t t = psx_next;
        psx_next = 0;
        psx_ring[psx_ring_i++ & 31] = t;
        { void a2_ramwatch_seg(uint32_t); a2_ramwatch_seg(t); }
        if (t == 0x8002C52Cu) { extern uint32_t seq_ticks; seq_ticks++; }
        psx_bb();                      /* time passes on every dispatch hop */
        {
            extern int psx_hotlog;
int psx_dslog;
            if (psx_hotlog > 0) {
                psx_hotlog--;
                fprintf(stderr, "seg: %08X\n", t);
            }
        }
        {
            /* A2_PROBE=1: once per frame dump key stream/scene state words */
            static int probe_en = -1;
            if (probe_en < 0) probe_en = getenv("A2_PROBE") ? 1 : 0;
            /* A2_HOTF/A2_HOTN: open a segment-log window at any frame */
            static int hotf = -1, hotn;
            if (hotf < 0) {
                hotf = getenv("A2_HOTF") ? atoi(getenv("A2_HOTF")) : 0;
                hotn = getenv("A2_HOTN") ? atoi(getenv("A2_HOTN")) : 30000;
            }
            if (hotf > 0) {
                extern uint32_t psx_frame_no;
                if (psx_frame_no == (uint32_t)hotf) {
                    psx_hotlog = hotn;
                    hotf = 0;
                }
            }
            if (probe_en) {
                extern uint32_t psx_frame_no;
                static int dumped;
                if (!dumped && psx_frame_no == 8000) {
                    dumped = 1;
                    fprintf(stderr, "bases: %08X %08X %08X %08X\n",
                            lw_(0x80079EB0u), lw_(0x80079EB4u),
                            lw_(0x80079EB8u), lw_(0x80079EBCu));
                    for (int k = 0; k < 24; k++) {
                        uint32_t e = 0x80054758u + k * 16;
                        fprintf(stderr, "seg0[%02d]: off=%X b4=%02X "
                                "len=%X w12=%X\n", k, lw_(e),
                                lb_(e + 4), lw_(e + 8), lw_(e + 12));
                    }
                    for (int k = 0; k < 8; k++) {
                        uint32_t e = 0x80054F38u + k * 16;
                        fprintf(stderr, "seg1[%02d]: off=%X b4=%02X "
                                "len=%X w12=%X\n", k, lw_(e),
                                lb_(e + 4), lw_(e + 8), lw_(e + 12));
                    }
                }
                /* A2_FORCE=frame:addr:hexval — one-shot halfword poke */
                static int fparsed; static uint32_t ff, fa, fv;
                if (!fparsed) {
                    fparsed = 1;
                    const char *fs = getenv("A2_FORCE");
                    if (fs) sscanf(fs, "%u:%x:%x", &ff, &fa, &fv);
                }
                if (ff && psx_frame_no >= ff && psx_frame_no < ff + 10) {
                    static uint32_t lff;
                    sh_(fa, fv);
                    if (psx_frame_no != lff) {
                        lff = psx_frame_no;
                        fprintf(stderr, "force: f%u [%08X]=%X (was=%X)\n",
                                psx_frame_no, fa, fv, lh_(fa));
                    }
                }
                /* A2_TPZ=frame — from that frame on, pin player Z
                 * (0x80119730) to the box center (-3300 in Q12) so the
                 * op0x36 arrival test can be probed independent of the
                 * player-walk path */
                static int tpz = -1;
                if (tpz < 0) tpz = getenv("A2_TPZ") ? atoi(getenv("A2_TPZ")) : 0;
                if (tpz && psx_frame_no >= (uint32_t)tpz) {
                    sw_(0x80119730u, (uint32_t)(-3300 << 12));
                    sw_(0x80119728u, (uint32_t)(-890 << 12));
                }
                /* A2_NOEND=1: at f7000 push the stream end-sector to
                 * infinity — test "premature end-of-clip stop" theory */
                static int ne = -1;
                if (ne < 0) ne = getenv("A2_NOEND") ? 1 : 0;
                if (ne == 1 && psx_frame_no == 7000) {
                    ne = 2;
                    fprintf(stderr, "noend: f%u end was %X (start %X cur %X)\n",
                            psx_frame_no, lw_(0x80079ED0u),
                            lw_(0x80079EDCu), lw_(0x80079ED4u));
                    sw_(0x80079ED0u, 0x7FFFFFFu);
                }
                static uint32_t lpf2;
                if (psx_frame_no != lpf2 && psx_frame_no % 25 == 0 &&
                    lw_(OVERLAY_BASE) == 4) {
                    lpf2 = psx_frame_no;
                    /* scene gates: cutscene-block word, dialog state,
                     * scene-thread enable, s1/s9/s11 thread pcs,
                     * villager1/2 AI sub-state + counter + alive */
                    fprintf(stderr, "gates: f%u blk=%X dlg=%X en=%X "
                            "s1=%X s9=%X s11=%X "
                            "v1=(%d,%d,%d,%02X) v2=(%d,%d,%d,%02X)\n",
                            psx_frame_no,
                            lw_(0x800F6220u), lh_(0x801284F2u),
                            lw_(0x80131034u),
                            lw_(0x80128590u), lw_(0x80128750u),
                            lw_(0x801287C0u),
                            (int16_t)lh_(0x80119A34u), (int16_t)lh_(0x80119C78u),
                            (int16_t)lh_(0x80119C7Cu), lb_(0x80119D4Au),
                            (int16_t)lh_(0x80119D58u), (int16_t)lh_(0x80119F9Cu),
                            (int16_t)lh_(0x80119FA0u), lb_(0x8011A06Eu));
                }
                static uint32_t lpm;
                if (psx_frame_no != lpm && psx_frame_no % 25 == 0 &&
                    lw_(OVERLAY_BASE) == 4) {
                    lpm = psx_frame_no;
                    /* entity0 (player/camera actor) pos + move state,
                     * scene-thread s1 ctx (slot1 @0x80128560): +6 done,
                     * +44 substream pc, +48 pc */
                    uint32_t e0 = 0x80119710u, s1 = 0x80128560u;
                    (void)s1;
                    extern uint32_t mover_hits, tick_hits;
                    fprintf(stderr, "mv: f%u e0z=%d gate=%08X(&07=%X &4C=%X) "
                            "p789=%02X p791=%02X p124=%d tick=%u mover=%u\n",
                            psx_frame_no, (int)lw_(e0 + 32),
                            lw_(0x800F6220u), lw_(0x800F6220u) & 7,
                            lw_(0x800F6220u) & 0x4C,
                            lb_(e0 + 789), lb_(e0 + 791),
                            (int16_t)lh_(e0 + 124), tick_hits, mover_hits);
                    mover_hits = tick_hits = 0;
                }
                static uint32_t lpf;
                if (psx_frame_no != lpf && psx_frame_no % 25 == 0) {
                    lpf = psx_frame_no;
                    fprintf(stderr, "probe: f%u sub=%X mode=%X sm=%X "
                            "map=%X", psx_frame_no,
                            lw_(0x8005474Cu), lw_(0x8005D058u),
                            lw_(0x8005D0A0u), lw_(0x80127898u));
                    for (int e = 0; e < 4; e++) {
                        uint32_t b = 0x80119710u + e * 0x324;
                        fprintf(stderr, " e%d[%d]=(%d,%d,%d)", e,
                                (int16_t)lh_(b),
                                (int)lw_(b + 0x18), (int)lw_(b + 0x1C),
                                (int)lw_(b + 0x20));
                    }
                    fprintf(stderr, "\n");
                }
            }
        }
        {
            /* A2_WWATCH=hexaddr — dispatch-hop watchpoint on a word; logs the
             * segment + value each time the word changes (finds the builder) */
            static int wwparsed; static uint32_t wwa, wwf;
            if (!wwparsed) { wwparsed = 1;
                const char *e = getenv("A2_WWATCH");
                if (e) sscanf(e, "%x@%u", &wwa, &wwf); }
            if (wwa) {
                extern uint32_t psx_frame_no;
                static uint32_t lastw = 0xDEADBEEF; static int wwn;
                uint32_t v = lw_(wwa);
                if (v != lastw && wwn < 40 && psx_frame_no >= wwf) {
                    wwn++;
                    fprintf(stderr, "wwatch: f%u [%08X] %08X->%08X after seg "
                            "%08X ra=%08X\n", psx_frame_no, wwa, lastw, v, t,
                            R[31]);
                }
                lastw = v;
            }
        }
        {
            /* A2_POSWATCH=1: dispatch-granularity watchpoint on player Z
             * (0x80119730) — logs the segment that changed it */
            static int pw = -1;
            if (pw < 0) pw = getenv("A2_POSWATCH") ? 1 : 0;
            if (pw) {
                extern uint32_t psx_frame_no;
                static uint32_t lastz; static int pwn;
                uint32_t z = lw_(0x80119730u);
                if (z != lastz && pwn < 120 && psx_frame_no > 3300 &&
                    lw_(OVERLAY_BASE) == 4) {
                    pwn++;
                    fprintf(stderr, "posz: f%u %d->%d after seg %08X "
                            "ra=%08X\n", psx_frame_no,
                            (int)lastz >> 12, (int)z >> 12, t, R[31]);
                }
                lastz = z;
            }
        }
        {
            /* A2_FLAGWATCH=1: dispatch-granularity watchpoint on the script
             * flag byte 0x800633C8 — logs the segment that changed it */
            static int fw = -1;
            if (fw < 0) fw = getenv("A2_FLAGWATCH") ? 1 : 0;
            if (fw) {
                static uint32_t lastv = ~0u; static int fwn;
                uint32_t v = lb_(0x800633C8u);
                if (v != lastv && fwn++ < 200) {
                    extern uint32_t psx_frame_no;
                    fprintf(stderr, "flagbyte: f%u %02X->%02X after seg "
                            "%08X ra=%08X\n", psx_frame_no, lastv, v, t,
                            R[31]);
                }
                lastv = v;
            }
        }
        {
            extern int psx_dslog;
            if (psx_dslog) {
                const char *nm = 0;
                switch (t) {
                case 0x8003E488: nm = "DsCommand"; break;
                case 0x80041C40: nm = "DsControl"; break;
                case 0x80041C18: nm = "DsControlF"; break;
                case 0x80041BC0: nm = "DsLastPos"; break;
                case 0x80041A28: nm = "DsIntToPos"; break;
                case 0x80041B2C: {
                    static int pn;
                    if (pn++ < 30)
                        fprintf(stderr, "ds: PosToInt bytes=%02X %02X %02X "
                                "%02X ra=%08X\n", lb_(R[4]), lb_(R[4]+1),
                                lb_(R[4]+2), lb_(R[4]+3), R[31]);
                    break;
                }
                case 0x80041D18: nm = "DsRead"; break;
                case 0x8002FF90: {
                    static int cn;
                    if (cn++ < 30) {
                        char buf[12];
                        for (int i = 0; i < 11; i++) {
                            buf[i] = (char)lb_(R[4] + i);
                            if (buf[i] < 0x20 || buf[i] > 0x7E) { buf[i] = 0; break; }
                        }
                        buf[11] = 0;
                        extern uint32_t psx_frame_no;
                        fprintf(stderr, "clip: f%u PLAY a0=%08X '%s' ra=%08X\n",
                                psx_frame_no, R[4], buf, R[31]);
                    }
                    break;
                }
                case 0x8002FCA0: {
                    static int cn2;
                    if (cn2++ < 30) {
                        extern uint32_t psx_frame_no;
                        fprintf(stderr, "clip: f%u API_FCA0 a0=%08X a1=%08X "
                                "ra=%08X\n", psx_frame_no, R[4], R[5], R[31]);
                    }
                    break;
                }
                case 0x8002FC4C: {
                    static uint32_t last = ~0u;
                    /* log only when the busy-state flips */
                    uint32_t busy = (lw_(0x80054754u) == 0 &&
                                     lw_(0x8005474Cu) != 0);
                    if (busy != last) {
                        last = busy;
                        extern uint32_t psx_frame_no;
                        fprintf(stderr, "clip: f%u BUSY->%u ra=%08X\n",
                                psx_frame_no, busy, R[31]);
                    }
                    break;
                }
                case 0x8002FE88: {
                    static int vn;
                    if (vn++ < 24) {
                        char buf[12];
                        for (int i = 0; i < 11; i++) {
                            buf[i] = (char)lb_(R[4] + i);
                            if (!buf[i]) break;
                        }
                        buf[11] = 0;
                        fprintf(stderr, "verdict: name='%s' ra=%08X\n",
                                buf, R[31]);
                    }
                    break;
                }
                case 0x8002FB78: {
                    static int fn2; static uint32_t lf;
                    extern uint32_t psx_frame_no;
                    uint32_t ss = lw_(0x8005474Cu);
                    if ((ss || psx_frame_no != lf) && fn2++ < 40) {
                        lf = psx_frame_no;
                        fprintf(stderr, "stop!: f%u substate=%X ra=%08X\n",
                                psx_frame_no, ss, R[31]);
                    }
                    break;
                }
                case 0x80030C00: {
                    static int rn;
                    extern uint32_t psx_frame_no;
                    if (rn++ < 20)
                        fprintf(stderr, "restart: f%u ra=%08X\n",
                                psx_frame_no, R[31]);
                    break;
                }
                case 0x8004CE70: {
                    static int sn; static uint32_t lra, la0;
                    extern uint32_t psx_frame_no;
                    if ((R[31] != lra || R[4] != la0) && sn++ < 40) {
                        lra = R[31]; la0 = R[4];
                        fprintf(stderr, "seqst: f%u a0=%X ra=%08X\n",
                                psx_frame_no, R[4], R[31]);
                    }
                    break;
                }
                case 0x8002FB20: {        /* stream start (flag=2 writer) */
                    static int bn;
                    extern uint32_t psx_frame_no;
                    if (bn++ < 30)
                        fprintf(stderr, "strt: f%u a0=%X a1=%X ra=%08X\n",
                                psx_frame_no, R[4], R[5], R[31]);
                    break;
                }
                case 0x800302E4: {        /* alt clip-play path */
                    static int an;
                    extern uint32_t psx_frame_no;
                    if (an++ < 30) {
                        char buf[12];
                        for (int i = 0; i < 11; i++) {
                            buf[i] = (char)lb_(R[4] + i);
                            if (buf[i] < 0x20 || buf[i] > 0x7E) { buf[i] = 0; break; }
                        }
                        buf[11] = 0;
                        fprintf(stderr, "alt!: f%u a0=%08X '%s' ra=%08X\n",
                                psx_frame_no, R[4], buf, R[31]);
                    }
                    break;
                }
                case 0x80093890: {        /* GAME00 PLAY wrapper (gated) */
                    static int wn;
                    extern uint32_t psx_frame_no;
                    if (wn++ < 40) {
                        char buf[12];
                        for (int i = 0; i < 11; i++) {
                            buf[i] = (char)lb_(R[4] + i);
                            if (buf[i] < 0x20 || buf[i] > 0x7E) { buf[i] = 0; break; }
                        }
                        buf[11] = 0;
                        fprintf(stderr, "wrap: f%u a0=%08X '%s' gateA=%X "
                                "gateB=%X ra=%08X\n", psx_frame_no, R[4], buf,
                                lw_(0x8005E6B8u), lb_(0x8005CFFFu), R[31]);
                    }
                    break;
                }
                case 0x80030CD0: {        /* stream fade-stop API */
                    static int fn3;
                    extern uint32_t psx_frame_no;
                    if (fn3++ < 20)
                        fprintf(stderr, "fadestop: f%u ra=%08X ovl=%u "
                                "sub=%X\n", psx_frame_no, R[31],
                                lw_(OVERLAY_BASE), lw_(0x8005474Cu));
                    break;
                }
                case 0x8009A98C: {        /* entity-script interpreter step */
                    extern uint32_t psx_frame_no;
                    /* A2_SCRLOG=frame: full step trace from that frame
                     * (legacy: any value <= 1 keeps the old 7400 gate) */
                    static int scrfrom = -2;
                    if (scrfrom == -2)
                        scrfrom = getenv("A2_SCRLOG") ? atoi(getenv("A2_SCRLOG")) : -1;
                    if (lw_(OVERLAY_BASE) == 4 &&
                        psx_frame_no > (uint32_t)(scrfrom > 1 ? scrfrom : 7400)) {
                        /* A2_SCRLOG=1: every step (a0 = entity), no dedup */
                        static int scrlog = -1;
                        if (scrlog < 0) scrlog = getenv("A2_SCRLOG") ? 1 : 0;
                        if (scrlog) {
                            static int sc;
                            if (sc++ < 4000)
                                fprintf(stderr, "script: f%u ent=%08X "
                                        "pc=%08X op=%02X\n", psx_frame_no,
                                        R[4], R[16], lb_(R[16]));
                            break;
                        }
                        static uint32_t seen[64]; static int ns;
                        uint32_t pc = R[16], key = pc;
                        int f = 0;
                        for (int i = 0; i < ns; i++) if (seen[i] == key) f = 1;
                        if (!f && ns < 64) {
                            seen[ns++] = key;
                            fprintf(stderr, "script: f%u pc=%08X op=%02X\n",
                                    psx_frame_no, pc, lb_(pc));
                        }
                    }
                    break;
                }
                case 0x800942B4: {        /* entity-script: wait-for-flag */
                    extern uint32_t psx_frame_no;
                    if (lw_(OVERLAY_BASE) == 4 && psx_frame_no > 7400) {
                        static uint32_t lastid = ~0u; static int wn2;
                        uint32_t id = lb_(R[5]+1) | (lb_(R[5]+2) << 8);
                        if (id != lastid && wn2++ < 30) {
                            lastid = id;
                            fprintf(stderr, "waitflag: f%u id=%03X pc=%08X "
                                    "byte=%02X\n", psx_frame_no, id, R[5],
                                    lb_(0x800633C8u + (id >> 3)));
                        }
                    }
                    break;
                }
                case 0x800357D8: case 0x800357B8: case 0x80035758:
                case 0x80035798: case 0x80035778: {
                    /* SetPoly* init counters: [GT4tex,G4flat,G3flat,FT4tex,F4flat] */
                    extern uint32_t setpoly_n[6];
                    static const uint32_t a[5] = {0x800357D8,0x800357B8,
                        0x80035758,0x80035798,0x80035778};
                    for (int i = 0; i < 5; i++) if (t == a[i]) setpoly_n[i]++;
                    break;
                }
                case 0x800A14A8: mover_hits++; break;  /* player mover */
                case 0x8008D97C: tick_hits++; break;   /* player tick */
                case 0x80086C74: {  /* scripted-move integrator (0x80117528) */
                    extern uint32_t psx_frame_no;
                    static uint32_t lsm;
                    if (lw_(OVERLAY_BASE) == 4 && psx_frame_no >= 7700 &&
                        psx_frame_no != lsm && psx_frame_no % 25 == 0) {
                        lsm = psx_frame_no;
                        uint32_t s = 0x80117528u;
                        fprintf(stderr, "spath: f%u mode=%d cnt=%d tbl=%08X "
                                "tgt=(%d,%d,%d) st=(%d,%d,%d)\n", psx_frame_no,
                                (int16_t)lh_(s), (int)lw_(s + 436),
                                lw_(s + 440),
                                (int)lw_(s + 172) >> 12, (int)lw_(s + 176) >> 12,
                                (int)lw_(s + 180) >> 12,
                                (int)lw_(s + 128) >> 12, (int)lw_(s + 132) >> 12,
                                (int)lw_(s + 136) >> 12);
                    }
                    break;
                }
                case 0x800A113C: {  /* collision-clip + commit: R5,R6,R7=new xyz */
                    extern uint32_t psx_frame_no;
                    static uint32_t lc;
                    if (lw_(OVERLAY_BASE) == 4 && psx_frame_no >= 7700 &&
                        psx_frame_no != lc && psx_frame_no % 25 == 0) {
                        lc = psx_frame_no;
                        uint32_t e = 0x80119710u;
                        uint32_t p84 = lw_(e + 84);
                        uint32_t scn = lw_(0x80131038u);
                        uint32_t ctab = scn ? lw_(scn + 532) : 0;
                        fprintf(stderr, "commit: f%u cur=(%d,%d,%d) new=(%d,%d,%d) "
                                "face=(%d,%d,%d) p84=%08X scn=%08X ctab=%08X "
                                "p84type=%d ncell=%d\n", psx_frame_no,
                                (int)lw_(e+24)>>12, (int)lw_(e+28)>>12,
                                (int)lw_(e+32)>>12, (int)R[5], (int)R[6],
                                (int)R[7], (int16_t)lh_(e+48),
                                (int16_t)lh_(e+50), (int16_t)lh_(e+52),
                                p84, scn, ctab,
                                p84 ? (int16_t)lh_(p84) : -999,
                                ctab ? (int)lw_(ctab) : -999);
                    }
                    break;
                }
                case 0x8001D3A8: case 0x8001D3E8: {  /* script flag set/clear */
                    extern uint32_t psx_frame_no;
                    static int fsn;
                    if (fsn++ < 400)
                        fprintf(stderr, "flag%s: f%u id=%03X ra=%08X\n",
                                t == 0x8001D3A8u ? "set" : "clr",
                                psx_frame_no, R[4], R[31]);
                    break;
                }
                case 0x800AB6EC: case 0x800AB830: case 0x800AC2C4:
                case 0x8009B4E4: case 0x8009B97C: case 0x80085A78:
                case 0x80085D60: case 0x80085ADC:
                    if (lw_(OVERLAY_BASE) == 4) {   /* GAME00 only */
                        switch (t) {
                        case 0x800AB6EC: nm = "EvState"; break;
                        case 0x800AB830: nm = "EvRun"; break;
                        case 0x800AC2C4: nm = "EvTick"; break;
                        case 0x8009B4E4: nm = "EvLoad1"; break;
                        case 0x8009B97C: nm = "EvLoad2"; break;
                        case 0x80085A78: nm = "ENTRY_scene"; break;
                        case 0x80085D60: nm = "ENTRY_game"; break;
                        case 0x80085ADC: nm = "ENTRY_scene2"; break;
                        }
                    }
                    break;
                case 0x80040CE4: {
                    nm = "CD_cw";
                    /* Setloc: decode the BCD target so read ranges are
                     * visible in the log */
                    if (R[4] == 2 && R[5]) {
                        static int sln;
                        extern uint32_t psx_frame_no;
                        if (sln++ < 300)
                            fprintf(stderr, "setloc: f%u %02X:%02X:%02X "
                                    "ra=%08X\n", psx_frame_no, lb_(R[5]),
                                    lb_(R[5] + 1), lb_(R[5] + 2), R[31]);
                    }
                    break;
                }
                case 0x8003ECF4: nm = "DsFlush"; break;
                case 0x8003E35C: nm = "DsReset"; break;
                default:
                    if (t >= 0x80140000u && t < 0x80150000u) {
                        static int hn; static uint32_t lhf;
                        extern uint32_t psx_frame_no;
                        if (psx_frame_no != lhf && hn++ < 60) {
                            lhf = psx_frame_no;
                            fprintf(stderr, "blob: f%u seg=%08X ra=%08X\n",
                                    psx_frame_no, t, R[31]);
                        }
                    }
                    break;
                }
                if (nm) {
                    static int n, n2;
                    extern uint32_t psx_frame_no;
                    if (n++ < 120 || (psx_frame_no > 7300 && n2++ < 1500))
                        fprintf(stderr, "ds: f%u %s(a0=%X a1=%X a2=%X) "
                                "ra=%08X\n", psx_frame_no,
                                nm, R[4], R[5], R[6], R[31]);
                }
            }
        }
        if (t >= 0x80043C00 && t <= 0x80044D00 && getenv("A2_TRACE_PAD")) {
            static int tn;
            if (tn++ < 100) fprintf(stderr, "padseg: %08X\n", t);
        }
        /* A2_60: the game locks gameplay to 30fps with VSync(2) at the
         * end of its main loop (ra=800867E0; cutscenes use other a0).
         * In this libetc build a0==1 is a NON-blocking elapsed query and
         * a0==0 means "wait for the next vsync", so 60fps = clamp 2 -> 0.
         * Speed hooks in gen/ (a2_60fps()) halve per-frame deltas. */
        if (t == 0x80037D98u && a2_60fps() && R[4] == 2)
            R[4] = 0;
        /* A2_VSYNCLOG=frame: from that frame on, trace VSync(a0) calls
         * (400 max) to map the frame pacing per game mode */
        if (t == 0x80037D98u) {
            static int vfrom = -2, vn = 400;
            if (vfrom == -2)
                vfrom = getenv("A2_VSYNCLOG") ? atoi(getenv("A2_VSYNCLOG")) : -1;
            extern uint32_t psx_frame_no;
            if (vfrom >= 0 && psx_frame_no >= (uint32_t)vfrom && vn > 0) {
                vn--;
                fprintf(stderr, "vsync: f%u a0=%d ra=%08X\n",
                        psx_frame_no, (int)R[4], R[31]);
            }
        }
        /* A2_MODELCAP: mark part boundaries — f_8002568C(OBJ) is the
         * per-part GTE setup before the AL22 blob draw call */
        if (t == 0x8002568Cu) {
            int a2_modelcap_active(void);
            FILE *a2_modelcap_file(void);
            if (a2_modelcap_active()) {
                FILE *f = a2_modelcap_file();
                if (f) {
                    extern uint32_t psx_frame_no;
                    fprintf(f, "PART f%u obj=%08X flag=%u raw=",
                            psx_frame_no, R[4], R[5]);
                    for (int i = 0; i < 0x40; i++)
                        fprintf(f, "%02X", (unsigned)lb_(R[4] + i) & 0xFF);
                    fprintf(f, "\n");
                }
            }
        }
        /* A2_60 speed compensation at the collision gate: every entity
         * move request (player, NPCs, enemies) funnels through
         * 0x800A113C(entity, newX, newY, newZ). At 60Hz logic, halving
         * the requested step keeps world speed identical to 30fps.
         * Large deltas (teleports, scene warps) pass through untouched.
         * Rounding dithers on frame parity so odd deltas don't drift. */
        if (t == 0x800A113Cu && a2_60fps()) {
            extern uint32_t psx_frame_no;
            int cur[3] = { (int32_t)lw_(R[4] + 24) >> 12,
                           (int32_t)lw_(R[4] + 28) >> 12,
                           (int32_t)lw_(R[4] + 32) >> 12 };
            for (int i = 0; i < 3; i++) {
                int d = (int32_t)R[5 + i] - cur[i];
                if (d > 512 || d < -512) { cur[0] = INT32_MIN; break; }
            }
            if (cur[0] != INT32_MIN)
                for (int i = 0; i < 3; i++) {
                    int d = (int32_t)R[5 + i] - cur[i];
                    int h = d / 2;
                    if ((d & 1) && (psx_frame_no & 1)) h += (d < 0) ? -1 : 1;
                    R[5 + i] = (uint32_t)(cur[i] + h);
                }
        }
        /* A2_MOVELOG=frame: from that frame, trace collision-gate moves
         * (entity, cur -> requested, delta) to map movement integrators */
        if (t == 0x800A113Cu) {
            static int mfrom = -2, mn = 500;
            if (mfrom == -2)
                mfrom = getenv("A2_MOVELOG") ? atoi(getenv("A2_MOVELOG")) : -1;
            extern uint32_t psx_frame_no;
            if (mfrom >= 0 && psx_frame_no >= (uint32_t)mfrom && mn > 0) {
                mn--;
                int cx = (int32_t)lw_(R[4] + 24) >> 12,
                    cy = (int32_t)lw_(R[4] + 28) >> 12,
                    cz = (int32_t)lw_(R[4] + 32) >> 12;
                uint32_t scn = lw_(0x80131038u);
                uint32_t ctab = scn ? lw_(scn + 532) : 0;
                fprintf(stderr, "move: f%u e=%08X cur=%d,%d,%d req=%d,%d,%d "
                        "d=%d,%d,%d ra=%08X scn=%08X ctab=%08X cnt=%u\n",
                        psx_frame_no, R[4],
                        cx, cy, cz, (int32_t)R[5], (int32_t)R[6], (int32_t)R[7],
                        (int32_t)R[5] - cx, (int32_t)R[6] - cy,
                        (int32_t)R[7] - cz, R[31], scn, ctab,
                        ctab ? lw_(ctab) : 0);
            }
        }
        /* A2_NOCLIP: diagnostic — when the room collision grid is empty
         * (count word 0, a scene-load bug that aborts g0_800A113C before
         * it commits the moved position), commit the requested position
         * directly so we can validate that movement is the last blocker.
         * R4=entity, R5/6/7 = new X/Y/Z in world units (stored as Q12). */
        if (t == 0x800A113Cu) {
            static int nc = -1;
            if (nc < 0) nc = getenv("A2_NOCLIP") ? 1 : 0;
            if (nc) {
                uint32_t scn = lw_(0x80131038u);
                uint32_t ctab = scn ? lw_(scn + 532) : 0;
                if (!ctab || lw_(ctab) == 0) {
                    sw_(R[4] + 24, R[5] << 12);
                    sw_(R[4] + 28, R[6] << 12);
                    sw_(R[4] + 32, R[7] << 12);
                    psx_next = R[31];
                    continue;
                }
            }
        }
        uint32_t p = t & 0x1FFFFFFFu;
        if (p == 0xA0 || p == 0xB0 || p == 0xC0) {
            kernel_syscall(p, R[9]);
            psx_next = R[31];          /* BIOS stubs return to ra */
            continue;
        }
#ifdef A2_NATIVE_SAVES
        if (a2_native_save_handle(t | 0x80000000u)) continue;
#endif
        void (*fn)(void) = lookup(t | 0x80000000u);
        if (!fn) fn = lookup(t);
        if (fn) {
            fn();
            if (!psx_next) psx_next = R[31];   /* C-level HLE returned */
            continue;
        }
        /* not recompiled (runtime-copied code, missed segmentation, …):
         * interpret one segment straight from PSX RAM */
        void psx_interp(uint32_t entry);
        psx_interp(t);
    }
    exec_depth--;
    R[31] = save_ra;
    psx_next = save_next;
}

void psx_trap(uint32_t addr) {
    /* untranslatable at recompile time (data misdetected as code, odd
     * delay slots) — if really executed, interpret one segment; the
     * interpreter sets psx_next and the dispatcher continues */
    void psx_interp(uint32_t entry);
    static int n;
    if (n++ < 20)
        fprintf(stderr, "psx_trap: interpreting 0x%08X (ra=0x%08X)\n",
                addr, R[31]);
    psx_interp(addr);
}

void psx_break(uint32_t code) {
    fprintf(stderr, "psx: break %u\n", code);
    exit(23);
}

int psx_critical;
void psx_irq_dispatch(void);
uint32_t psx_irq_active(void);

void psx_syscall(void) { psx_syscall_at(0); }
void psx_syscall_at(uint32_t pc) {
    /* syscall(a0): 1=EnterCriticalSection, 2=ExitCriticalSection */
    if (R[4] == 1) {
        /* PSY-Q card cleanup restores IRQs only if this returns exactly 1.
         * Return the previous gate state, never the caller's stale v0. */
        R[2] = psx_critical ? 0 : 1;
        psx_critical = 1;
        return;
    }
    if (R[4] == 2) {
        psx_critical = 0;
        if (psx_irq_active()) psx_irq_dispatch();   /* latched IRQs fire now */
        return;
    }
    fprintf(stderr, "psx: syscall a0=%u at 0x%08X\n", R[4], pc);
}

/* ---- cop0: enough state to satisfy reads ---- */
static uint32_t cop0[32];
uint32_t psx_cop0_read(int reg) { return cop0[reg]; }
void psx_cop0_write(int reg, uint32_t v) { cop0[reg] = v; }
void psx_rfe(void) {
    cop0[12] = (cop0[12] & ~0xFu) | ((cop0[12] >> 2) & 0xF);
}

void vtrace(const char *l) {
    static int n;
    if (n++ < 60) fprintf(stderr, "vsync: %s (a0=%u)\n", l, R[4]);
}

int a2_60fps(void) {
    static int v = -1;
    if (v < 0) v = getenv("A2_60") ? 1 : 0;
    return v;
}

static int a2_wide_v = -1;
int a2_wide(void) {
    if (a2_wide_v < 0) a2_wide_v = getenv("A2_WIDE") ? 1 : 0;
    return a2_wide_v;
}
void a2_wide_set(int on) { a2_wide_v = on ? 1 : 0; }

uint32_t a2_ramwatch;
static uint32_t a2_rw_cur_seg;             /* segment being dispatched */
static uint32_t a2_ramwatch_first_frame;
void a2_ramwatch_init(void) {
    const char *e = getenv("A2_RAMWATCH");
    if (e) a2_ramwatch = (uint32_t)strtoul(e, NULL, 16) | 1;
    e = getenv("A2_RAMWATCH_FROM");
    a2_ramwatch_first_frame = e ? (uint32_t)strtoul(e, NULL, 10) : 0;
}
void a2_ramwatch_seg(uint32_t t) { a2_rw_cur_seg = t; }
void a2_ramwatch_hit(uint32_t phys, uint32_t v, int size) {
    extern uint32_t psx_frame_no;
    static int n;
    if (psx_frame_no < a2_ramwatch_first_frame) return;
    if (n++ < 200)
        fprintf(stderr, "ramw: f%u [%06X]=%0*X sz%d seg=%08X ra=%08X\n",
                psx_frame_no, phys, size * 2, v, size,
                a2_rw_cur_seg, R[31]);
}
/* bulk copies (CD sector delivery, kernel memcpy HLE) call this around
 * their memcpy into PSX_RAM */
void a2_ramwatch_blk(uint32_t dst_phys, uint32_t len, const char *tag) {
    psx_precision_invalidate(dst_phys & 0x1FFFFFu,len);
    if (!a2_ramwatch) return;
    uint32_t w = a2_ramwatch & 0x1FFFFCu;
    if (w >= (dst_phys & 0x1FFFFFu) && w < (dst_phys & 0x1FFFFFu) + len) {
        extern uint32_t psx_frame_no;
        fprintf(stderr, "ramw: f%u [%06X] in %s blk dst=%06X len=%u\n",
                psx_frame_no, w, tag, dst_phys & 0x1FFFFFu, len);
    }
}
