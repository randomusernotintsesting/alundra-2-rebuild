/* PS1 CD-ROM controller over a 2352-byte/sector .bin image.
 *
 * Deferred-delivery model (matches real drive timing semantics):
 * commands only QUEUE their responses; INTs are delivered from
 * cd_vblank() — never inside the command write — so the game finishes
 * its post-command setup before the first INT arrives, exactly as on
 * hardware where responses take ~1ms+. Data sectors are loaded into
 * the buffer at DELIVERY time of their INT1 (acking does not clobber
 * data the handler hasn't fetched yet). XA audio is decoded separately
 * and sent to the SPU CD input, without raising a data interrupt.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "psx_rt.h"
#include "spu.h"
#include "xa_audio.h"
#ifdef A2_NATIVE_VOICE
#include "native_voice.h"
#endif
#ifdef A2_VOICE_ASSETS
#include "voice_assets.h"
#else
#define a2_voice_read_sector(lba, raw) 0
#define a2_voice_observe(lba, frames) ((void)0)
#define a2_voice_event(reason) ((void)0)
#define a2_voice_begin(lba, file, channel) ((void)0)
#define a2_voice_stop(reason) ((void)0)
#endif

void psx_irq_set(int bit);
void psx_irq_dispatch(void);

int cd_log;

static FILE *img;
static uint32_t img_sectors;

static uint8_t param[16], resp[16], data[2340];
static int param_n, resp_n, resp_i, data_n, data_i;
static int sector_len;                 /* loaded sector size (FIFO armed by BFRD) */
static int index_reg;
static uint8_t irq_en, irq_fl;

static uint32_t cur_lba, target_lba;
static int reading, mode;
static uint8_t filter_file, filter_channel;
static XaDecoder xa_decoder;
static unsigned xa_clock;
static int xa_stream = -1, xa_muted, xa_adp_muted;
static uint8_t xa_volume[4] = {128, 0, 0, 128}; /* LL,LR,RL,RR */
static uint8_t xa_pending_volume[4] = {128, 0, 0, 128};
static struct {
    uint64_t ticks, advanced, selected, frames, filtered, wrong_stream;
    uint64_t decode_failed, nonzero, blocked, critical, irq, budget, data_overrun;
    uint64_t native_raw_attempts,native_dma_attempts,native_fifo_attempts;
    unsigned rate;
} cd_stats;
static int cd_stats_enabled(void) {
    static int enabled = -1;
    if (enabled < 0) {
        const char *v = getenv("A2_AUDIOSTAT");
        enabled = v && *v && strcmp(v, "0");
    }
    return enabled;
}

static void reset_xa(void) {
    memset(&xa_decoder, 0, sizeof xa_decoder);
    xa_stream = -1; xa_clock = 0;
    spu_reset_cd_audio();
}
static void apply_xa_mix(void) {
    spu_set_cd_mix(xa_volume[0], xa_volume[1], xa_volume[2], xa_volume[3],
                   xa_muted || xa_adp_muted);
}

/* pending INT queue; lba >= 0 marks a data INT1 whose sector is loaded
 * at delivery time */
static struct { int num; uint8_t resp[8]; int n; int64_t lba; } pend[8];
static int pend_n;
static void cd_stats_report(void) {
    if (!cd_stats_enabled() || cd_stats.ticks % 60) return;
    fprintf(stderr, "cdstat: tick=%llu advanced=%llu xa_selected=%llu xa_frames=%llu "
            "xa_rate=%u xa_nonzero=%llu filtered=%llu wrong_stream=%llu decode_failed=%llu "
            "budget=%llu blocked=%llu critical=%llu irq=%llu reading=%d mode=%02X "
            "filter=%u,%u stream=%d lba=%u pending=%d irq_fl=%02X data_overrun=%llu\n",
            (unsigned long long)cd_stats.ticks, (unsigned long long)cd_stats.advanced,
            (unsigned long long)cd_stats.selected, (unsigned long long)cd_stats.frames,
            cd_stats.rate, (unsigned long long)cd_stats.nonzero,
            (unsigned long long)cd_stats.filtered, (unsigned long long)cd_stats.wrong_stream,
            (unsigned long long)cd_stats.decode_failed, (unsigned long long)cd_stats.budget,
            (unsigned long long)cd_stats.blocked, (unsigned long long)cd_stats.critical,
            (unsigned long long)cd_stats.irq, reading, mode, filter_file, filter_channel,
            xa_stream, cur_lba, pend_n, irq_fl, (unsigned long long)cd_stats.data_overrun);
}

static uint8_t stat_byte(void) {
    return 0x02 | (reading ? 0x20 : 0);   /* motor on, reading */
}

static void push_int(int num, const uint8_t *r, int n) {
    if (pend_n >= 8 && num != 1) {
        /* A stalled CPU may fill the bounded queue with streaming data.
         * Preserve command completions by sacrificing the newest pending
         * data sector, never the active FIFO or an older command response.
         * Removing just that entry preserves the remaining delivery order. */
        for (int i = pend_n - 1; i >= 0; i--) {
            if (pend[i].lba < 0) continue;
            memmove(pend + i, pend + i + 1, sizeof(pend[0]) * (pend_n - i - 1));
            pend_n--;
            if (cd_stats_enabled()) cd_stats.data_overrun++;
            break;
        }
    }
    if (pend_n >= 8) return;
    pend[pend_n].num = num;
    memcpy(pend[pend_n].resp, r, n);
    pend[pend_n].n = n;
    pend[pend_n].lba = -1;
    pend_n++;
}

static void flush_data_ints(void) {
    int w = 0;
    for (int i = 0; i < pend_n; i++)
        if (pend[i].lba < 0)
            pend[w++] = pend[i];
    pend_n = w;
}

uint64_t cd_native_raw_read_attempts(void){return cd_stats.native_raw_attempts;}
uint64_t cd_native_dma_attempts(void){return cd_stats.native_dma_attempts;}
#ifdef A2_NATIVE_VOICE
static void native_transport_report(void){
    fprintf(stderr,"nativecd: raw_read_attempts=%llu data_dma_attempts=%llu fifo_attempts=%llu\n",
        (unsigned long long)cd_stats.native_raw_attempts,(unsigned long long)cd_stats.native_dma_attempts,
        (unsigned long long)cd_stats.native_fifo_attempts);
}
static int reject_native_transport(const char *operation,unsigned kind){
    if(!a2_native_voice_enabled())return 0;
    if(kind==0)cd_stats.native_raw_attempts++;
    else if(kind==1)cd_stats.native_dma_attempts++;
    else cd_stats.native_fifo_attempts++;
    a2_native_voice_transport_error(operation);reading=0;flush_data_ints();return 1;
}
#endif
static int load_sector(uint32_t lba) {
#ifdef A2_NATIVE_VOICE
    if(reject_native_transport("raw resource sector",0))return 0;
#endif
    static uint32_t nloads;
    if (cd_log && (++nloads & 0x7FF) == 1)
        fprintf(stderr, "cd: progress load#%u lba=%u\n", nloads, lba);
    memset(data, 0, sizeof data);
    sector_len = (mode & 0x20) ? 2340 : 2048;
    if (!img || lba >= img_sectors) return 1;
    uint8_t raw[2352];
    fseek(img, (long)lba * 2352, SEEK_SET);
    if (fread(raw, 1, 2352, img) != 2352) return 1;
    if (mode & 0x20) memcpy(data, raw + 12, 2340);
    else memcpy(data, raw + 24, 2048);
    data_i = data_n = 0;               /* fifo armed by BFRD write */
    return 1;
}

static int consume_xa_audio(uint32_t lba) {
#ifdef A2_NATIVE_VOICE
    if(reject_native_transport("raw XA sector",0))return 0;
#endif
    if (!img || lba >= img_sectors) return 0;
    uint8_t raw[2352];
    int overlay = a2_voice_read_sector(lba, raw);
    if (overlay == 2) return 1; /* silent overlay is neither XA nor CPU data */
    if (!overlay &&
        (fseek(img, (long)lba * 2352, SEEK_SET) ||
         fread(raw, 1, sizeof raw, img) != sizeof raw)) return 0;
    if (raw[15] != 2 || (raw[18] & 0x44) != 0x44) return 0;
    if ((mode & 8) && (raw[16] != filter_file || raw[17] != filter_channel)) {
        if (cd_stats_enabled()) cd_stats.filtered++;
        return 1; /* filtered XA is neither audio nor CPU data */
    }
    if (!(mode & 0x40)) return 0;
    int stream = raw[16]*256 + raw[17];
    /* Without an explicit filter, latch the first channel of the stream. */
    if (xa_stream >= 0 && xa_stream != stream) {
        if (cd_stats_enabled()) cd_stats.wrong_stream++;
        return 1;
    }
    int16_t pcm[4032 * 2];
    unsigned rate;
    size_t frames = xa_decode_sector(&xa_decoder, raw, sizeof raw, pcm, 4032, &rate);
    if (frames) {
        if (cd_stats_enabled()) {
            cd_stats.selected++; cd_stats.frames += frames; cd_stats.rate = rate;
            unsigned peak = 0, nonzero = 0;
            for (size_t i = 0; i < frames; i++) {
                if (pcm[i*2] || pcm[i*2+1]) nonzero++;
                for (unsigned c = 0; c < 2; c++) {
                    unsigned a = (unsigned)abs((int)pcm[i*2+c]);
                    if (a > peak) peak = a;
                }
            }
            cd_stats.nonzero += nonzero;
            if (xa_stream < 0 || cd_stats.selected % 64 == 0) {
                extern uint32_t psx_frame_no;
                fprintf(stderr, "xasource: frame=%u lba=%u file=%u channel=%u coding=%02X "
                        "rate=%u frames=%zu nonzero=%u peak=%u\n",
                        psx_frame_no, lba, raw[16], raw[17], raw[19], rate, frames, nonzero, peak);
            }
        }
        xa_stream = stream;
        a2_voice_observe(lba, frames);
        spu_push_cd_audio(pcm, frames, rate);
    } else if (cd_stats_enabled()) cd_stats.decode_failed++;
    return 1;
}

/* deliver the next queued INT if the previous one was acknowledged;
 * returns 1 if something was delivered */
static int deliver_next(void) {
    if (!pend_n || irq_fl) return 0;
    if (pend[0].lba >= 0 && !load_sector((uint32_t)pend[0].lba))return 0;
    irq_fl = (uint8_t)pend[0].num;
    memcpy(resp, pend[0].resp, pend[0].n);
    resp_n = pend[0].n;
    resp_i = 0;
    memmove(pend, pend + 1, sizeof(pend[0]) * --pend_n);
    if (cd_log) {
        static int n;
        if (n++ < 200)
            { extern uint32_t psx_frame_no;
              fprintf(stderr, "cd: f%u deliver INT%d resp0=%02X\n",
                    psx_frame_no, irq_fl, resp[0]); }
    }
    if (irq_en & irq_fl & 7) {
        psx_irq_set(2);
        psx_irq_dispatch();
    }
    return 1;
}

static void queue_read_int(uint32_t lba) {
    uint8_t r[1] = {stat_byte()};
    push_int(1, r, 1);
    pend[pend_n - 1].lba = lba;
}

/* called every vblank: real-drive pacing, a few sectors per frame.
 * XA streaming is paced at 75/150 sectors per second. Legacy data-only
 * reads retain their existing batching for the native loader. */
void cd_vblank(void) {
    int stats = cd_stats_enabled();
    if (stats) cd_stats.ticks++;
    /* never deliver from inside another IRQ handler or a critical
     * section: libds manipulates its command queue there and a nested
     * completion desyncs its state machine (stuck DsSync) */
    extern int psx_in_irq, psx_critical;
    if (psx_in_irq || psx_critical) {
        if (stats) { cd_stats.irq += !!psx_in_irq; cd_stats.critical += !!psx_critical; }
        cd_stats_report();
        return;
    }
    int sector_budget = 6;
    if (mode & 0x40) {
        xa_clock += (mode & 0x80) ? 150 : 75;
        sector_budget = xa_clock / 60;
        xa_clock %= 60;
    }
    if (stats && reading) cd_stats.budget += sector_budget;
#ifdef A2_NATIVE_VOICE
    if (a2_native_voice_enabled()) {
        static int report_installed;
        if(!report_installed){atexit(native_transport_report);report_installed=1;}
        /* Only command/status compatibility remains on the native path. File
         * transfers bypass this controller, and the named sound stream reads
         * ADPCM groups directly. No sector FIFO, image, ISO or DMA is involved. */
        for (int i = 0; i < 4; i++) if (!deliver_next()) break;
        if (reading) {
            if (!a2_native_voice_advance((unsigned)sector_budget, !!(mode & 0x40)))
                reading = 0;
            else {
                cur_lba += (unsigned)sector_budget; /* guest compatibility clock only */
                if (stats) cd_stats.advanced += (unsigned)sector_budget;
            }
        }
        for (int i = 0; i < 4; i++) if (!deliver_next()) break;
        cd_stats_report();
        return;
    }
#endif
    if (mode & 0x40) {
        /* Physical XA time continues while the CPU holds a data interrupt.
         * Otherwise each unspent tick budget disappears and a perfectly
         * paced host plays gaps from an underfed CD PCM source.
         * Command/data INTs retain FIFO order and are still deferred until
         * this tick. The eight pending slots bound CPU data buffering: a
         * full queue discards new CPU sectors, or its newest pending data
         * sector to make room for a command completion. Neither the active
         * FIFO nor an older command response is overwritten. */
        for (int i = 0; i < 4; i++) if (!deliver_next()) break;
        while (reading && (mode & 0x40) && sector_budget > 0) {
            if (cur_lba >= img_sectors) { reading = 0; break; }
            uint32_t lba = cur_lba++;
            sector_budget--;
            if (stats) cd_stats.advanced++;
            if (!consume_xa_audio(lba)) {
                if (pend_n < (int)(sizeof pend / sizeof pend[0])) queue_read_int(lba);
                else if (stats) cd_stats.data_overrun++;
            }
            for (int i = 0; i < 4; i++) if (!deliver_next()) break;
        }
        cd_stats_report();
        return;
    }
    /* two passes so a sector queued this tick is also DELIVERED this
     * tick: real hardware returns data within ~half a frame and the
     * game's streaming engine timeouts are tuned to that (it re-tries
     * the chunk forever if data arrives 2+ frames late) */
    for (int pass = 0; pass < 2; pass++) {
        if (reading && pend_n == 0) {
            for (int i = 0; i < 3 && pend_n < 2 && sector_budget; i++, sector_budget--) {
                if (cur_lba >= img_sectors) { reading = 0; break; }
                if ((mode & 0x48) && consume_xa_audio(cur_lba)) {
                    cur_lba++;
                    if (stats) cd_stats.advanced++;
                    continue;
                }
                queue_read_int(cur_lba++);
                if (stats) cd_stats.advanced++;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (!deliver_next()) break;
        }
    }
    if (stats && reading) cd_stats.blocked += sector_budget;
    cd_stats_report();
}

static void cd_command(uint8_t cmd) {
    uint8_t r1[8] = {stat_byte()};
    if (cd_stats_enabled() && cmd != 1 && cmd != 0x10 && cmd != 0x11) {
        extern uint32_t psx_frame_no;
        fprintf(stderr, "cdcommand: frame=%u cmd=%02X params=%u:%02X,%02X,%02X "
                "mode=%02X filter=%u,%u target=%u current=%u reading=%d\n",
                psx_frame_no, cmd, param_n, param[0], param[1], param[2],
                mode, filter_file, filter_channel, target_lba, cur_lba, reading);
    }
    if (cd_log)
        { extern uint32_t psx_frame_no;
          fprintf(stderr, "cd: f%u cmd %02X params=%02X %02X %02X\n",
                psx_frame_no, cmd, param[0], param[1], param[2]); }
    switch (cmd) {
    case 0x01: push_int(3, r1, 1); break;                       /* Getstat */
    case 0x02: {                                                /* Setloc */
        int mm = (param[0] >> 4) * 10 + (param[0] & 15);
        int ss = (param[1] >> 4) * 10 + (param[1] & 15);
        int ff = (param[2] >> 4) * 10 + (param[2] & 15);
        target_lba = (uint32_t)((mm * 60 + ss) * 75 + ff) - 150;
        push_int(3, r1, 1);
        break;
    }
    case 0x06: case 0x1B:                                       /* ReadN/S */
#ifdef A2_NATIVE_VOICE
        if (a2_native_voice_enabled()) {
            flush_data_ints();reset_xa();cur_lba=target_lba;
            reading=a2_native_voice_begin(target_lba,filter_file,filter_channel);
            r1[0]=stat_byte();
            push_int(reading?3:5,r1,1);
            break;
        }
#endif
        a2_voice_begin(target_lba, filter_file, filter_channel);
        flush_data_ints();
        reset_xa();
        cur_lba = target_lba;
        reading = 1;
        r1[0] = stat_byte();
        push_int(3, r1, 1);
        break;
    case 0x08: case 0x09:                                       /* Stop/Pause */
#ifdef A2_NATIVE_VOICE
        a2_native_voice_stop(cmd == 0x08 ? "Stop" : "Pause");
#endif
        a2_voice_stop(cmd == 0x08 ? "Stop" : "Pause");
        flush_data_ints();
        reset_xa();
        reading = 0;
        push_int(3, r1, 1);
        r1[0] = stat_byte();
        push_int(2, r1, 1);
        break;
    case 0x0A:                                                  /* Init */
#ifdef A2_NATIVE_VOICE
        a2_native_voice_stop("Init");
#endif
        a2_voice_stop("Init");
        flush_data_ints();
        reading = 0; mode = 0;
        reset_xa();
        filter_file = filter_channel = 0;
        xa_muted = xa_adp_muted = 0; apply_xa_mix();
        push_int(3, r1, 1);
        push_int(2, r1, 1);
        break;
    case 0x0B: case 0x0C:
#ifdef A2_NATIVE_VOICE
        if (cmd == 0x0b) a2_native_voice_event("Mute");
#endif
        if (cmd == 0x0b) a2_voice_event("Mute");
        xa_muted = cmd == 0x0b; apply_xa_mix();
        push_int(3, r1, 1); break;
    case 0x0D:
        if (filter_file != param[0] || filter_channel != param[1]) {
#ifdef A2_NATIVE_VOICE
            a2_native_voice_stop("Setfilter");
#endif
            a2_voice_stop("Setfilter"); reset_xa();
        }
        filter_file = param[0]; filter_channel = param[1];
        push_int(3, r1, 1); break;
    case 0x0E: mode = param[0]; push_int(3, r1, 1); break;      /* Setmode */
    case 0x10: {                                                /* GetlocL */
        /* [amm,ass,aff,mode,file,channel,sm,ci] of last read header */
        uint8_t r[8] = {0};
        uint32_t l = cur_lba + 150;
        int mm = l / (75 * 60), ss = (l / 75) % 60, ff = l % 75;
        r[0] = (uint8_t)(((mm / 10) << 4) | (mm % 10));
        r[1] = (uint8_t)(((ss / 10) << 4) | (ss % 10));
        r[2] = (uint8_t)(((ff / 10) << 4) | (ff % 10));
        r[3] = 2;
        push_int(3, r, 8);
        break;
    }
    case 0x11: {                                                /* GetlocP */
        /* [track,index, mm,ss,ff (relative), amm,ass,aff (absolute)] */
        uint8_t r[8];
        /* EXPERIMENT (A2_CLOCKHACK): scene scripts use the playback
         * position as a clock; if the drive sits idle, advance the
         * reported position anyway to test the stuck-clock theory */
        static uint32_t idle_ticks;
        uint32_t l;
        if (getenv("A2_CLOCKHACK") && !reading) {
            idle_ticks += 2;
            l = cur_lba + idle_ticks + 150;
        } else {
            idle_ticks = 0;
            l = cur_lba + 150;
        }
        int mm = l / (75 * 60), ss = (l / 75) % 60, ff = l % 75;
        uint8_t bmm = (uint8_t)(((mm / 10) << 4) | (mm % 10));
        uint8_t bss = (uint8_t)(((ss / 10) << 4) | (ss % 10));
        uint8_t bff = (uint8_t)(((ff / 10) << 4) | (ff % 10));
        r[0] = 0x01; r[1] = 0x01;
        r[2] = bmm; r[3] = bss; r[4] = bff;     /* relative ~ absolute */
        r[5] = bmm; r[6] = bss; r[7] = bff;
        push_int(3, r, 8);
        break;
    }
    case 0x13: {                                                /* GetTN */
        uint8_t r[3] = {stat_byte(), 0x01, 0x01};
        push_int(3, r, 3);
        break;
    }
    case 0x14: {                                                /* GetTD */
        uint32_t l = img_sectors + 150;
        int mm = l / (75 * 60), ss = (l / 75) % 60;
        uint8_t r[3] = {stat_byte(),
                        (uint8_t)(((mm / 10) << 4) | (mm % 10)),
                        (uint8_t)(((ss / 10) << 4) | (ss % 10))};
        push_int(3, r, 3);
        break;
    }
    case 0x15: case 0x16:                                       /* SeekL/P */
#ifdef A2_NATIVE_VOICE
        a2_native_voice_stop("Seek");
#endif
        a2_voice_stop("Seek");
        flush_data_ints();
        reset_xa();
        cur_lba = target_lba;
        reading = 0;
        push_int(3, r1, 1);
        r1[0] = stat_byte();
        push_int(2, r1, 1);
        break;
    case 0x19:                                                  /* Test */
        if (param[0] == 0x20) {
            uint8_t r[4] = {0x98, 0x06, 0x10, 0xC3};
            push_int(3, r, 4);
        } else push_int(3, r1, 1);
        break;
    case 0x1A: {                                                /* GetID */
        push_int(3, r1, 1);
        uint8_t r[8] = {0x02, 0x00, 0x20, 0x00, 'S', 'C', 'E', 'I'};
        push_int(2, r, 8);
        break;
    }
    case 0x07: push_int(3, r1, 1); push_int(2, r1, 1); break;   /* MotorOn */
    default:
        fprintf(stderr, "cd: unknown cmd %02X\n", cmd);
        push_int(5, r1, 1);
    }
    param_n = 0;
}

uint8_t cd_read_reg(int r) {
    switch (r) {
    case 0: {
        uint8_t st = (uint8_t)index_reg;
        if (param_n == 0) st |= 0x08;          /* param fifo empty */
        if (param_n < 16) st |= 0x10;          /* param fifo not full */
        if (resp_i < resp_n) st |= 0x20;       /* response available */
        if (data_i < data_n) st |= 0x40;       /* data available */
        return st;
    }
    case 1:
        return resp_i < resp_n ? resp[resp_i++] : 0;
    case 2:
#ifdef A2_NATIVE_VOICE
        if(reject_native_transport("CPU data FIFO",2))return 0;
#endif
        return data_i < data_n ? data[data_i++] : 0;
    case 3:
        if (index_reg & 1) return irq_fl | 0xE0;
        return irq_en | 0xE0;
    }
    return 0;
}

void cd_write_reg(int r, uint8_t v) {
    if (cd_log)
        fprintf(stderr, "cd: write reg%d idx%d = %02X\n", r, index_reg, v);
    switch (r) {
    case 0: index_reg = v & 3; return;
    case 1:
        if (index_reg == 0) { cd_command(v); return; }
        if (index_reg == 3) xa_pending_volume[3] = v;
        return;
    case 2:
        if (index_reg == 0) { if (param_n < 16) param[param_n++] = v; return; }
        if (index_reg == 1) { irq_en = v & 0x1F; return; }
        if (index_reg == 2) xa_pending_volume[0] = v;
        if (index_reg == 3) xa_pending_volume[2] = v;
        return;
    case 3:
        if (index_reg == 2) { xa_pending_volume[1] = v; return; }
        if (index_reg == 3) {
            xa_adp_muted = !!(v & 1);
            if (v & 0x20) memcpy(xa_volume, xa_pending_volume, sizeof xa_volume);
            apply_xa_mix(); return;
        }
        if (index_reg == 0) {                  /* request register */
            if (v & 0x80) {                    /* BFRD=1: arm fifo; the read
                                                * position PERSISTS if already
                                                * armed (games peek the 12-byte
                                                * header then DMA the data) */
                if (data_n == 0) { data_i = 0; data_n = sector_len; }
            } else data_i = data_n = 0;
            return;
        }
        if (index_reg == 1) {                  /* IRQ flag ack */
            irq_fl &= ~(v & 0x1F);
            if (v & 0x40) param_n = 0;
            return;
        }
        return;
    }
}

void cd_dma_read(uint32_t madr, uint32_t words) {
#ifdef A2_NATIVE_VOICE
    if(reject_native_transport("CD data DMA",1))return;
#endif
    if (sector_len == 2340) {
        extern uint32_t psx_frame_no;
        static int n;
        if (psx_frame_no > 7000 && n++ < 12) {
            fprintf(stderr, "cd: f%u dma2340 %u words -> %08X fifo@%d "
                    "first %02X %02X %02X %02X %02X %02X %02X %02X\n",
                    psx_frame_no, words, madr, data_i,
                    data[data_i], data[data_i+1], data[data_i+2],
                    data[data_i+3], data[data_i+4], data[data_i+5],
                    data[data_i+6], data[data_i+7]);
        }
    }
    if (cd_log) {
        static int n;
        if (n++ < 8)
            fprintf(stderr, "cd: dma %u words -> %08X, fifo %d/%d, "
                    "first: %02X %02X %02X %02X %02X %02X %02X %02X "
                    "%02X %02X %02X %02X %02X %02X %02X %02X\n",
                    words, madr, data_i, data_n,
                    data[data_i], data[data_i+1], data[data_i+2], data[data_i+3],
                    data[data_i+4], data[data_i+5], data[data_i+6], data[data_i+7],
                    data[data_i+8], data[data_i+9], data[data_i+10], data[data_i+11],
                    data[data_i+12], data[data_i+13], data[data_i+14], data[data_i+15]);
    }
    void a2_ramwatch_blk(uint32_t dst, uint32_t len, const char *tag);
    a2_ramwatch_blk(madr, words * 4, "cd-dma");
    for (uint32_t i = 0; i < words * 4; i++) {
        uint8_t b = data_i < data_n ? data[data_i++] : 0;
        PSX_RAM[(madr + i) & 0x1FFFFF] = b;
    }
}

void cd_dump_state(void) {
    fprintf(stderr, "cd state: idx=%d irq_en=%02X irq_fl=%02X pend=%d "
            "resp %d/%d data %d/%d reading=%d param_n=%d cur_lba=%u\n",
            index_reg, irq_en, irq_fl, pend_n, resp_i, resp_n,
            data_i, data_n, reading, param_n, cur_lba);
}

int cd_open_image(const char *path) {
    img = fopen(path, "rb");
    if (!img) return 0;
    fseek(img, 0, SEEK_END);
    img_sectors = (uint32_t)(ftell(img) / 2352);
    fseek(img, 0, SEEK_SET);
    return 1;
}

void cd_boot_handoff(void) {
    /* Native execution enters the EXE after the BIOS stage. The guest's
     * CD_init skips its IRQ-enable write when no stale flags need clearing,
     * assuming the BIOS already enabled completion IRQs. Set only that
     * handoff state; cold controller state and midgame commands stay intact. */
    irq_en = 7;
}
