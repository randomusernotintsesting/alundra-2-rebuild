#include <stdlib.h>
/* libpad HLE: replace the SIO-timing-sensitive PSY-Q pad library with
 * direct buffer writes (PadInitDirect buffer format, digital pad).
 * Addresses from PSY-Q 4.50 signature match (analysis/psyq_names.json).
 */
#include <stdio.h>
#include "psx_rt.h"

void psx_register_hle(uint32_t addr, void (*fn)(void));
uint16_t psx_pad_buttons(void);        /* platform layer */

static uint32_t pad_buf[2];

static void fill(uint32_t buf, int connected) {
    if (!buf) return;
    if (!connected) { sb_(buf, 0xFF); return; }
    uint16_t btn = psx_pad_buttons();
    sb_(buf + 0, 0x00);                /* ok */
    sb_(buf + 1, 0x41);                /* digital pad, 1 word of data */
    sb_(buf + 2, btn & 0xFF);
    sb_(buf + 3, btn >> 8);
}

static void hle_PadInitDirect(void) {  /* (buf1, buf2) */
    pad_buf[0] = R[4];
    pad_buf[1] = R[5];
    fill(pad_buf[0], 1);
    fill(pad_buf[1], 0);
    R[2] = 0;
}

static void hle_PadChkVsync(void) {    /* per-frame poll */
    uint16_t btn = psx_pad_buttons();
    if (btn != 0xFFFF) {
        static int n;
        if (n++ < 10)
            fprintf(stderr, "padhle: ChkVsync btn=%04X buf=%08X\n",
                    btn, pad_buf[0]);
    }
    fill(pad_buf[0], 1);
    fill(pad_buf[1], 0);
    R[2] = 1;
}

static void hle_PadGetState(void) {    /* (port) -> PadStateStable */
    R[2] = (R[4] & 0xF0) ? 0 : 6;      /* port 2 disconnected */
}

static void hle_PadInfoMode(void) {    /* (port, term, idx) */
    R[2] = 4;                          /* digital controller */
}

static void hle_ret1(void) { R[2] = 1; }
static void hle_ret0(void) { R[2] = 0; }

/* the game's single VBlank chain handler (0x800437F4) does the libpad
 * SIO dance AND drives the SsSeq command queue; replace it wholesale:
 * fill pad buffers directly, drain the SsSeq flag the boot waits on */
static void hle_vblank_chain(void) {
    uint16_t btn = psx_pad_buttons();
    if (btn != 0xFFFF) {
        static int n;
        if (n++ < 8)
            fprintf(stderr, "padhle: chain btn=%04X buf=%08X\n",
                    btn, pad_buf[0]);
    }
    fill(pad_buf[0], 1);
    fill(pad_buf[1], 0);
    sh_(0x80081190u, 0);
    R[2] = 0;
}

/* called from the platform vblank tick: keep buffers fresh regardless
 * of which path the game uses to poll */
void pad_hle_tick(void) {
    fill(pad_buf[0], 1);
    fill(pad_buf[1], 0);
}

/* the real chain handler's SIO pad dance burns the whole frame budget
 * in timer-paced retry loops; keep it overridden. A2_SND=1 additionally
 * calls the SsSeq sequencer tick (f_8004B14C) so the recompiled music
 * driver programs our SPU — experimental. */
uint32_t seq_ticks;                   /* A2_TICKSTAT: sequencer ticks */
static void hle_vblank_chain2(void) {
    /* run the REAL SsSeq tick first: it PROCESSES the queued sound
     * commands (SsSeqOpen/Play live in that queue — just clearing the
     * flag drops them and scripts wait on "is the jingle playing"
     * forever); A2_NOSND=1 reverts to flag-drain only */
    if (!getenv("A2_NOSND")) {
        void psx_call(uint32_t);
        psx_call(0x8004B14Cu);
    } else {
        sh_(0x80081190u, 0);
    }
    /* NO unconditional flag drain: commands queued between the tick
     * and end-of-frame set the flag for the NEXT tick — clearing it
     * here eats one-shot sound commands (the scene's XA-music start
     * was lost exactly this way: engine extrapolates the playback
     * position forever waiting for music that never started) */
    fill(pad_buf[0], 1);
    fill(pad_buf[1], 0);
    R[2] = 0;
}

void pad_hle_install(void) {
    psx_register_hle(0x800437F4u, hle_vblank_chain2);
    psx_register_hle(0x80045648u, hle_PadInitDirect);
    psx_register_hle(0x80043188u, hle_PadChkVsync);
    psx_register_hle(0x80043984u, hle_PadChkVsync);  /* _padChkVsync (the
        vblank chain handler calls the internal one, not the wrapper) */
    psx_register_hle(0x80043234u, hle_PadGetState);
    psx_register_hle(0x80043300u, hle_PadInfoMode);
    psx_register_hle(0x800431A8u, hle_ret1);   /* PadStartCom */
    psx_register_hle(0x800431C8u, hle_ret1);   /* PadStopCom */
    psx_register_hle(0x80043648u, hle_ret1);   /* PadEnableCom */
    psx_register_hle(0x800435ACu, hle_ret1);   /* PadSetMainMode */
    psx_register_hle(0x80043574u, hle_ret0);   /* PadSetActAlign */
    psx_register_hle(0x800435F4u, hle_ret0);   /* PadSetAct */
}
