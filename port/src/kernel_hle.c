/* HLE of the PS1 BIOS kernel — exactly the 40 syscalls Alundra 2 uses
 * (port/analysis/hle_boundary.md), plus the interrupt-chain dispatch
 * (SysEnqIntRP) that PSY-Q libs rely on.
 *
 * Cooperative interrupt model: no preemption; pending IRQ work runs
 * inside psx_irq_dispatch(), called by the CD/DMA engines after they
 * change state, and from the VBlank wait path.
 */
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "psx_rt.h"
#include "memcard.h"

void psx_vblank_tick(void);            /* platform layer (main) */
void gpu_gp0(uint32_t w);              /* gpu.c */

int kernel_log;

/* ---- events ---- */
#define MAX_EV 64
static struct {
    uint32_t cls, spec, mode, func;
    int open, enabled, occurred;
} ev[MAX_EV];

static int ev_is_vblankish(uint32_t cls) {
    return cls == 0xF2000003 ||        /* HwVBLANK */
           cls == 0xF0000001;          /* HwVBLANK (event class alt) */
}

static void deliver(uint32_t cls, uint32_t spec) {
    for (int i = 0; i < MAX_EV; i++) {
        if (!ev[i].open || !ev[i].enabled) continue;
        if (ev[i].cls != cls || ev[i].spec != spec) continue;
        if ((ev[i].mode & 0xFFFF) == 0x1000 && ev[i].func) {  /* EvMdINTR */
            uint32_t save_R[32], save_hi = HI, save_lo = LO;
            memcpy(save_R, R, sizeof save_R);
            psx_call(ev[i].func);
            memcpy(R, save_R, sizeof save_R);
            HI = save_hi; LO = save_lo;
        } else {
            ev[i].occurred = 1;
        }
    }
}

void psx_deliver_event(uint32_t cls, uint32_t spec) { deliver(cls, spec); }

/* ---- interrupt delivery ---- */
static uint32_t irq_chain[4];          /* SysEnqIntRP chains */
static uint32_t custom_exit;           /* SetCustomExitFromException buf */
static jmp_buf irq_jmp;
int psx_in_irq;
#define in_irq psx_in_irq
uint32_t psx_irq_active(void);         /* mmio.c: i_stat & i_mask */

void psx_irq_dispatch(void) {
    extern int psx_critical;
    if (in_irq || psx_critical) return;
    in_irq = 1;
    /* real interrupts save the full CPU context; so must we — handlers
     * are recompiled code and clobber the global register file */
    extern int psx_call_depth;
    int save_depth = psx_call_depth;
    uint32_t save_R[32], save_hi = HI, save_lo = LO;
    memcpy(save_R, R, sizeof save_R);
    for (int prio = 0; prio < 4; prio++) {
        uint32_t el = irq_chain[prio];
        int guard = 0;
        while (el && (el & 0x1FFFFFFF) && guard++ < 16) {
            uint32_t handler = lw_(el + 4);   /* func2 */
            uint32_t verifier = lw_(el + 8);  /* func1 */
            if (verifier) {
                if (!setjmp(irq_jmp)) {
                    psx_call(verifier);
                    if (kernel_log) {
                        static int n;
                        if (n++ < 40)
                            fprintf(stderr, "irqchain: prio%d verify "
                                    "0x%08X -> %u (handler 0x%08X)\n",
                                    prio, verifier, R[2], handler);
                    }
                    if (R[2] != 0 && handler) {
                        R[4] = R[2];
                        psx_call(handler);
                    }
                }
            }
            el = lw_(el);
        }
    }
    /* PSY-Q libetc replaces the BIOS exception exit with its own
     * dispatcher (jmp_buf via B0:19): emulate "exception occurred" by
     * jumping there with the saved context; it reads I_STAT, runs the
     * registered callbacks and ends with ReturnFromException (B0:17),
     * which longjmps back here. */
    if (custom_exit && psx_irq_active()) {
        static int delivery_n;
        delivery_n++;
        if (kernel_log)
            fprintf(stderr, "kernel: deliver #%d active=%02X\n",
                    delivery_n, psx_irq_active());
        uint32_t buf = custom_exit;
        if (!setjmp(irq_jmp)) {
            R[31] = lw_(buf + 0);
            R[29] = lw_(buf + 4);
            R[30] = lw_(buf + 8);
            for (int i = 0; i < 8; i++) R[16 + i] = lw_(buf + 12 + i * 4);
            R[28] = lw_(buf + 44);
            R[2] = 1;                  /* longjmp(buf, 1) semantics */
            psx_call(lw_(buf + 0));
        }
    }
    memcpy(R, save_R, sizeof save_R);
    HI = save_hi; LO = save_lo;
    psx_call_depth = save_depth;       /* longjmp skips the decrements */
    in_irq = 0;
}

/* ---- pad ---- */
static uint32_t pad_buf1, pad_buf2;
static int pad_started;
uint16_t psx_pad_buttons(void);        /* platform layer: active-low bits */

void psx_pad_update(void) {
    if (!pad_started) return;
    uint16_t btn = psx_pad_buttons();
    {
        /* A2_HOLD=from:to:hexmask — clear (press) mask bits in the
         * given frame range; diagnostic input injection */
        static int parsed; static uint32_t hf, ht, hm, hp;
        if (!parsed) {
            parsed = 1;
            const char *h = getenv("A2_HOLD");
            if (h) sscanf(h, "%u:%u:%x:%u", &hf, &ht, &hm, &hp);
        }
        extern uint32_t psx_frame_no;
        if (hm && psx_frame_no >= hf && psx_frame_no < ht &&
            (!hp || psx_frame_no % hp < 3))
            btn &= (uint16_t)~hm;
    }
    if (kernel_log) {
        static int n;
        if (btn != 0xFFFF && n++ < 10)
            fprintf(stderr, "pad: buf1=0x%08X btn=%04X started=%d\n",
                    pad_buf1, btn, pad_started);
    }
    if (pad_buf1) {
        sb_(pad_buf1 + 0, 0x00);              /* ok */
        sb_(pad_buf1 + 1, 0x41);              /* digital pad, 1 word */
        sb_(pad_buf1 + 2, btn & 0xFF);
        sb_(pad_buf1 + 3, btn >> 8);
    }
    if (pad_buf2) {
        sb_(pad_buf2 + 0, 0xFF);              /* not connected */
        sb_(pad_buf2 + 1, 0xFF);
        sb_(pad_buf2 + 2, 0xFF);
        sb_(pad_buf2 + 3, 0xFF);
    }
}

/* ---- syscall entry ---- */
void kernel_syscall(uint32_t table, uint32_t num) {
    uint32_t a0 = R[4], a1 = R[5], a2 = R[6], a3 = R[7];
    if (kernel_log)
        fprintf(stderr, "bios %02X:%02X(%08X,%08X,%08X,%08X)\n",
                table, num, a0, a1, a2, a3);
    R[2] = 0;
    if (memcard_bios(table, num)) return;
    if (table == 0xA0) switch (num) {
        case 0x39: return;                       /* InitHeap */
        case 0x44: return;                       /* FlushCache */
        case 0x49: gpu_gp0(a0); return;          /* GPU_cw */
        case 0x72: return;                       /* CdRemove */
        default: goto unhandled;
    }
    if (table == 0xB0) switch (num) {
        case 0x07: deliver(a0, a1); return;      /* DeliverEvent */
        case 0x08: {                             /* OpenEvent */
            for (int i = 0; i < MAX_EV; i++) if (!ev[i].open) {
                ev[i] = (typeof(ev[0])){a0, a1, a2, a3, 1, 0, 0};
                R[2] = 0xF1000000u | i;
                return;
            }
            R[2] = 0xFFFFFFFFu; return;
        }
        case 0x09: {                             /* CloseEvent */
            uint32_t i = a0 & 0xFFFF;
            if (i < MAX_EV) ev[i].open = 0;
            R[2] = 1; return;
        }
        case 0x0B: {                             /* TestEvent */
            uint32_t i = a0 & 0xFFFF;
            if (i >= MAX_EV || !ev[i].open) { R[2] = 0; return; }
            if (ev_is_vblankish(ev[i].cls)) {
                psx_vblank_tick();
                R[2] = 1; return;
            }
            R[2] = ev[i].occurred;
            ev[i].occurred = 0;
            return;
        }
        case 0x0C: {                             /* EnableEvent */
            uint32_t i = a0 & 0xFFFF;
            if (i < MAX_EV) { ev[i].enabled = 1; ev[i].occurred = 0; }
            R[2] = 1; return;
        }
        case 0x0D: {                             /* DisableEvent */
            uint32_t i = a0 & 0xFFFF;
            if (i < MAX_EV) ev[i].enabled = 0;
            R[2] = 1; return;
        }
        case 0x12:                               /* InitPad */
            pad_buf1 = a0; pad_buf2 = a2;
            if (pad_buf1) sb_(pad_buf1, 0xFF);
            if (pad_buf2) sb_(pad_buf2, 0xFF);
            R[2] = 1; return;
        case 0x13: pad_started = 1; R[2] = 1; return;   /* StartPad */
        case 0x14: pad_started = 0; R[2] = 1; return;   /* StopPad */
        case 0x15: pad_started = 1; R[2] = 1; return;   /* OutdatedPadInitAndStart */
        case 0x17:                               /* ReturnFromException */
            if (in_irq) longjmp(irq_jmp, 1);
            fprintf(stderr, "kernel: ReturnFromException outside irq!\n");
            return;
        case 0x18: custom_exit = 0; return;      /* SetDefaultExit... */
        case 0x19: custom_exit = a0; return;     /* SetCustomExitFromException */
        case 0x35:                               /* FileWrite */
            if (a0 == 1 || a0 == 2) {            /* game debug output */
                fprintf(stderr, "[game] ");
                for (uint32_t i = 0; i < a2 && i < 512; i++)
                    fputc((int)lb_(a1 + i), stderr);
                if (a2 == 0 || lb_(a1 + (a2 > 512 ? 511 : a2 - 1)) != '\n')
                    fputc('\n', stderr);
                R[2] = a2;
                return;
            }
            R[2] = 0xFFFFFFFFu; return;
        case 0x38: R[2] = 0; return;             /* FileGetc? -> EOF */
        case 0x51: R[2] = 1; return;             /* Krom2RawAdd (font; not card I/O) */
        case 0x56: R[2] = 0xC80; return;         /* GetC0Table */
        case 0x57: R[2] = 0x874; return;         /* GetB0Table */
        case 0x5B: return;                       /* ChangeClearPad */
        default: goto unhandled;
    }
    if (table == 0xC0) switch (num) {
        case 0x02:                               /* SysEnqIntRP(prio, elem) */
            if (a0 < 4) {
                sw_(a1, irq_chain[a0]);          /* elem->next = old head */
                irq_chain[a0] = a1;
            }
            return;
        case 0x03:                               /* SysDeqIntRP(prio, elem) */
            if (a0 < 4) {
                if (irq_chain[a0] == a1) irq_chain[a0] = lw_(a1);
                else {
                    uint32_t el = irq_chain[a0];
                    int g = 0;
                    while (el && g++ < 16) {
                        if (lw_(el) == a1) { sw_(el, lw_(a1)); break; }
                        el = lw_(el);
                    }
                }
            }
            return;
        case 0x0A: R[2] = 0; return;             /* ChangeClearRCnt */
        default: goto unhandled;
    }
unhandled:
    fprintf(stderr, "kernel: unhandled syscall %02X:%02X "
            "(a0=%08X a1=%08X)\n", table, num, a0, a1);
    exit(24);
}
