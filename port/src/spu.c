/* PS1 SPU: 24 ADPCM voices + 512KB sample RAM, mixed via SDL audio.
 * ADPCM loops, programmable ADSR, CD/XA input and deterministic 44.1kHz mixing.
 * Shared hardware noise, adjacent-voice pitch modulation and signed volume
 * sweeps use documented register arithmetic. Reverb includes work-RAM filters
 * and39-tap resampling. Gaussian voice interpolation is not yet modeled;
 * exact envelope/reverb operation ordering and startup quirks remain approximate.
 */
#include <SDL.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "spu.h"
#include "phase_timing.h"

#include "xa_zigzag.h"

uint8_t SPU_RAM[512 * 1024];

static int16_t vol_main_l = 0x7FFE, vol_main_r = 0x7FFE;
static uint16_t main_sweep_l, main_sweep_r;
static uint32_t main_counter_l, main_counter_r;
static uint32_t xfer_addr;             /* current transfer address (bytes) */
static uint16_t spu_ctrl;
static uint32_t keyon_latch, keyoff_latch, endx;
static uint32_t pitch_mod, noise_enable;
static uint16_t noise_level;
static int32_t noise_timer;
static uint16_t register_readback[0x200];
static uint32_t reverb_base, reverb_cursor, reverb_voices;
static int16_t reverb_volume[2];
static int32_t clip16(int64_t n) {
    return n < -32768 ? -32768 : n > 32767 ? 32767 : (int32_t)n;
}
static int32_t mul15(int32_t a, int32_t b) { return (int32_t)(((int64_t)a*b) >> 15); }
static uint32_t reverb_address(int32_t offset) {
    int32_t size = (int32_t)sizeof SPU_RAM - (int32_t)reverb_base;
    int32_t relative = ((int32_t)(reverb_cursor-reverb_base) + offset) % size;
    if (relative < 0) relative += size;
    return reverb_base + (uint32_t)relative;
}
static int32_t reverb_read(int32_t offset) {
    uint32_t a = reverb_address(offset);
    return (int16_t)(SPU_RAM[a] | (uint16_t)SPU_RAM[a+1] << 8);
}
static void reverb_write(int32_t offset, int32_t value) {
    uint32_t a = reverb_address(offset);
    uint16_t s = (uint16_t)clip16(value);
    SPU_RAM[a] = (uint8_t)s; SPU_RAM[a+1] = (uint8_t)(s >> 8);
}

/* Stereo tick at22.05kHz. The algebra is from PSX-SPX, not an emulator.
 * Quantization/saturation is explicit; exact silicon operation order is unknown. */
static void reverb_process(int32_t left, int32_t right, int32_t wet[2]) {
    const uint16_t *r = register_readback + 0x1c0/2;
    int write_enable = !!(spu_ctrl & 0x80);
    int32_t input[2] = {mul15(clip16(left), (int16_t)r[30]),
                        mul15(clip16(right), (int16_t)r[31])};
    if (write_enable) {
        for (int ch = 0; ch < 2; ch++) {
            int32_t address = r[10+ch]*8;
            int32_t old = reverb_read(address-2);
            int32_t reflection = clip16(input[ch] + mul15(reverb_read(r[16+ch]*8), (int16_t)r[7]) - old);
            int32_t value = mul15(reflection, (int16_t)r[2]) + old;
            if (r[2] == 0x8000) value = -value; /* measured vIIR sign quirk */
            reverb_write(address, value);
        }
        for (int ch = 0; ch < 2; ch++) {
            int32_t address = r[18+ch]*8;
            int32_t old = reverb_read(address-2);
            int32_t reflection = clip16(input[ch] + mul15(reverb_read(r[24+(ch^1)]*8), (int16_t)r[7]) - old);
            int32_t value = mul15(reflection, (int16_t)r[2]) + old;
            if (r[2] == 0x8000) value = -value;
            reverb_write(address, value);
        }
    }
    int32_t value[2];
    for (int ch = 0; ch < 2; ch++) {
        value[ch] = clip16(mul15(reverb_read(r[12+ch]*8), (int16_t)r[3]) +
                              mul15(reverb_read(r[14+ch]*8), (int16_t)r[4]) +
                              mul15(reverb_read(r[20+ch]*8), (int16_t)r[5]) +
                              mul15(reverb_read(r[22+ch]*8), (int16_t)r[6]));
    }
    for (int stage = 0; stage < 2; stage++) {
        for (int ch = 0; ch < 2; ch++) {
            int32_t address = r[26+stage*2+ch]*8;
            int32_t delayed = address-r[stage]*8;
            int32_t gain = (int16_t)r[8+stage];
            value[ch] = clip16(value[ch]-mul15(reverb_read(delayed), gain));
            if (write_enable) reverb_write(address, value[ch]);
            value[ch] = clip16(mul15(value[ch], gain)+reverb_read(delayed));
        }
    }
    wet[0] = value[0]; wet[1] = value[1];
    reverb_cursor += 2;
    if (reverb_cursor >= sizeof SPU_RAM) reverb_cursor = reverb_base;
}

static int16_t reverb_input_history[39][2], reverb_output_history[39][2];
static unsigned reverb_filter_pos, reverb_phase;
static const int16_t reverb_fir[39] = {
    -1,0,2,0,-10,0,35,0,-103,0,266,0,-616,0,1332,0,-2960,0,
    10246,16384,10246,0,-2960,0,1332,0,-616,0,266,0,-103,0,35,0,-10,0,2,0,-1
};
static int32_t reverb_filter(int16_t history[39][2], int ch, int gain) {
    int64_t sum = 0;
    for (unsigned i = 0; i < 39; i++)
        sum += (int32_t)history[(reverb_filter_pos+39-i)%39][ch] * reverb_fir[i];
    return clip16((sum*gain) >> 15);
}
static void reverb_sample(int32_t left, int32_t right, int32_t wet[2]) {
    reverb_input_history[reverb_filter_pos][0] = (int16_t)clip16(left);
    reverb_input_history[reverb_filter_pos][1] = (int16_t)clip16(right);
    int32_t half_rate[2] = {0,0};
    if (!reverb_phase) {
        reverb_process(reverb_filter(reverb_input_history, 0, 1),
                       reverb_filter(reverb_input_history, 1, 1), half_rate);
    }
    /* Zero insertion + gain2 is the 22.05 ->44.1kHz polyphase interpolator.
     * The two causal39-tap filters together delay wet audio by38 samples. */
    for (int ch = 0; ch < 2; ch++) {
        reverb_output_history[reverb_filter_pos][ch] = (int16_t)half_rate[ch];
        wet[ch] = mul15(reverb_filter(reverb_output_history, ch, 2), reverb_volume[ch]);
    }
    reverb_filter_pos = (reverb_filter_pos+1)%39;
    reverb_phase ^= 1;
}
enum { CD_FRAMES = 32768 };
static int16_t cd_pcm[CD_FRAMES][2];
static unsigned cd_read, cd_count, cd_phase, cd_rate;
static int16_t cd_history[32][2];
static unsigned cd_history_write;
static int16_t cd_vol_l, cd_vol_r;
static uint8_t cd_ll = 128, cd_lr, cd_rl, cd_rr = 128;
static int cd_muted;
/* Opt-in cumulative source/output diagnostics. They never alter PCM or clocks. */
static struct {
    uint64_t tick, cd_consumed, cd_missing, cd_nonzero, cd_mixed_nonzero;
    uint64_t voice_nonzero, pcm_nonzero, cd_dropped, cd_resets, cd_energy;
    uint64_t host_starve, host_overflow, host_fail, host_resume;
    uint64_t last_clock, max_gap;
    Uint32 queue_min, queue_max;
} audio_stats;
typedef struct {
    uint64_t frames, energy[2], over[2], rails[2];
    uint32_t peak[2];
} MixLevel;
static struct {
    MixLevel cd_source, cd_mix, dry, wet, pre_master, post_master, voice[24];
    uint64_t ticks;
} mix_stats;
static int mix_stats_mode = -1;
static int audio_mix_stats_enabled(void) {
    if (mix_stats_mode < 0) {
        const char *setting = getenv("A2_MIXSTAT");
        mix_stats_mode = setting && *setting && strcmp(setting,"0");
    }
    return mix_stats_mode;
}
static void mix_level_record(MixLevel *level, int32_t left, int32_t right) {
    const int32_t values[2] = {left,right};
    level->frames++;
    for (unsigned ch=0;ch<2;ch++) {
        int64_t value=values[ch];
        uint32_t magnitude=(uint32_t)(value<0?-value:value);
        if(magnitude>level->peak[ch])level->peak[ch]=magnitude;
        level->energy[ch]+=(uint64_t)(value*value);
        level->over[ch]+=value < -32768 || value > 32767;
        level->rails[ch]+=value == -32768 || value == 32767;
    }
}
static void mix_level_report(const char *stage,const MixLevel *level) {
    fprintf(stderr,"mixstat: tick=%llu stage=%s frames=%llu peak_l=%u peak_r=%u "
            "energy_l=%llu energy_r=%llu over_l=%llu over_r=%llu rails_l=%llu rails_r=%llu\n",
            (unsigned long long)mix_stats.ticks,stage,(unsigned long long)level->frames,
            level->peak[0],level->peak[1],(unsigned long long)level->energy[0],
            (unsigned long long)level->energy[1],(unsigned long long)level->over[0],
            (unsigned long long)level->over[1],(unsigned long long)level->rails[0],
            (unsigned long long)level->rails[1]);
}
static void audio_mix_stats_report(void) {
    mix_level_report("cd_source",&mix_stats.cd_source);
    mix_level_report("cd_mix",&mix_stats.cd_mix);
    mix_level_report("dry",&mix_stats.dry);
    mix_level_report("wet",&mix_stats.wet);
    mix_level_report("pre_master",&mix_stats.pre_master);
    mix_level_report("post_master",&mix_stats.post_master);
    for(unsigned vi=0;vi<24;vi++)if(mix_stats.voice[vi].frames) {
        char stage[16];snprintf(stage,sizeof stage,"voice_%02u",vi);
        mix_level_report(stage,&mix_stats.voice[vi]);
    }
    fprintf(stderr,"mixgain: tick=%llu main_l=%d main_r=%d cd_l=%d cd_r=%d "
            "matrix=%u,%u,%u,%u wet_l=%d wet_r=%d\n",
            (unsigned long long)mix_stats.ticks,vol_main_l,vol_main_r,cd_vol_l,cd_vol_r,
            cd_ll,cd_lr,cd_rl,cd_rr,reverb_volume[0],reverb_volume[1]);
    /* Energy is bounded to one second of emulated audio, not cumulative
     * across an arbitrarily long play session. This changes no SPU state. */
    uint64_t ticks=mix_stats.ticks;
    memset(&mix_stats,0,sizeof mix_stats);mix_stats.ticks=ticks;
}
static int audio_stats_enabled(void) {
    static int enabled = -1;
    if (enabled < 0) {
        const char *v = getenv("A2_AUDIOSTAT");
        enabled = v && *v && strcmp(v, "0");
    }
    return enabled;
}
static void cd_enqueue(int16_t left,int16_t right) {
    if (cd_count == CD_FRAMES) {
        if (audio_stats_enabled()) audio_stats.cd_dropped++;
        cd_read = (cd_read + 1) % CD_FRAMES;
        cd_count--;
    }
    unsigned w = (cd_read + cd_count++) % CD_FRAMES;
    cd_pcm[w][0]=left;cd_pcm[w][1]=right;
}
void spu_push_cd_audio(const int16_t *pcm, size_t frames, unsigned rate) {
    if (!pcm || !frames || (rate != 37800 && rate != 18900)) return;
    if (cd_rate != rate) {
        cd_phase = cd_history_write = 0; cd_rate = rate;
        memset(cd_history,0,sizeof cd_history);
    }
    /* Keep the existing18.9kHz rational hold until its separate reconstruction
     * is validated. Duplicating input into this37.8kHz FIR can add a16kHz
     * artifact (documented in DuckStation's ResampleXAADPCM18900Hz). */
    if(rate==18900) {
        for(size_t i=0;i<frames;i++) {
            while(cd_phase<44100) {cd_enqueue(pcm[2*i],pcm[2*i+1]);cd_phase+=rate;}
            cd_phase-=44100;
        }
        return;
    }
    /* Six37.8kHz samples produce seven44.1kHz samples. History and phase survive normal
     * sector/call boundaries; whole XA sectors always complete a group.
     * A rate switch clears the filter, but preserves PCM already queued. */
    for (size_t i = 0; i < frames; i++) {
            cd_history[cd_history_write][0]=pcm[i*2];
            cd_history[cd_history_write][1]=pcm[i*2+1];
            cd_history_write=(cd_history_write+1)&31;
            if(++cd_phase<6)continue;
            cd_phase=0;
            for(unsigned phase=0;phase<7;phase++) {
                int32_t sum[2]={0,0};
                for(unsigned lag=1;lag<=29;lag++) {
                    unsigned h=(cd_history_write-lag)&31;
                    for(unsigned ch=0;ch<2;ch++) {
                        /* Quantize each product before summation, including
                         * negative products. The bounded sum fits int32. */
                        int32_t product=(int32_t)cd_history[h][ch]*xa_zigzag[lag-1][phase];
                        sum[ch]+=product>=0?product/32768:-((-(int64_t)product+32767)/32768);
                    }
                }
                cd_enqueue((int16_t)clip16(sum[0]),(int16_t)clip16(sum[1]));
            }
    }
}
void spu_reset_cd_audio(void) {
    if (audio_stats_enabled()) audio_stats.cd_resets++;
    cd_read = cd_count = cd_phase = cd_rate = 0;
    cd_history_write=0;memset(cd_history,0,sizeof cd_history);
}
void spu_set_cd_mix(uint8_t ll, uint8_t lr, uint8_t rl, uint8_t rr, int muted) {
    cd_ll = ll; cd_lr = lr; cd_rl = rl; cd_rr = rr; cd_muted = muted;
}

typedef struct {
    int on;
    uint32_t start, repeat, cur;       /* byte addresses in SPU RAM */
    uint32_t frac;                     /* 12.20 fixed sample position */
    uint16_t pitch;
    int16_t vol_l, vol_r;
    uint16_t sweep_l, sweep_r;
    uint32_t sweep_counter_l, sweep_counter_r;
    int16_t prev1, prev2;              /* ADPCM history */
    int16_t block[28];
    int block_pos;
    int block_flags;
    int phase;                        /* attack, decay, sustain, release */
    uint16_t adsr_lo, adsr_hi;
    uint32_t env_counter;
    int32_t level;                     /* 0..0x7fff envelope */
} Voice;
static Voice voices[24];

static const int pos_tab[5] = {0, 60, 115, 98, 122};
static const int neg_tab[5] = {0, 0, -52, -55, -60};

static void volume_write(int16_t *level, uint16_t *control, uint32_t *counter,
                         uint16_t value) {
    *control = value;
    *counter = 0;
    if (!(value & 0x8000)) *level = (int16_t)(value << 1);
}

/* Same documented shift/step generator as ADSR, with signed sweep phase.
 * Fixed volume becomes signed Q15; entering sweep retains that current level. */
static void volume_step(int16_t *current, uint16_t control, uint32_t *counter) {
    if (!(control & 0x8000)) return;
    unsigned rate = control & 0x7f;
    if (rate == 0x7f) return;
    unsigned shift = rate >> 2;
    int decrease = !!(control & 0x2000), exponential = !!(control & 0x4000);
    int negative = !!(control & 0x1000);
    if (exponential && decrease) negative = 0;
    int step = 7 - (rate & 3);
    if (decrease ^ negative) step = ~step;
    step *= 1 << (shift < 11 ? 11 - shift : 0);
    unsigned increment = 0x8000u >> (shift > 11 ? shift - 11 : 0);
    int level = *current;
    if (exponential && !decrease && level > 0x6000) {
        if (shift < 10) step /= 4;
        else if (shift >= 11) increment /= 4;
        else { step /= 2; increment /= 2; }
    } else if (exponential && decrease) step = (step * level) >> 15;
    if (!increment) increment = 1;
    *counter += increment;
    if (!(*counter & 0x8000)) return;
    *counter &= 0x7fff;
    level += step;
    if (level < -32768) level = -32768;
    if (level > 32767) level = 32767;
    if (decrease) {
        if (negative && level > 0) level = 0;
        if (!negative && level < 0) level = 0;
    }
    *current = (int16_t)level;
}

static void envelope(Voice *v) {
    unsigned shift, step_value = 0;
    int decrease = 0, exponential = 0;
    switch (v->phase) {
    case 0:
        shift = (v->adsr_lo >> 10) & 31;
        step_value = (v->adsr_lo >> 8) & 3;
        exponential = v->adsr_lo >> 15;
        break;
    case 1:
        shift = (v->adsr_lo >> 4) & 15;
        decrease = exponential = 1; break;
    case 2:
        shift = (v->adsr_hi >> 8) & 31;
        step_value = (v->adsr_hi >> 6) & 3;
        decrease = (v->adsr_hi >> 14) & 1;
        exponential = v->adsr_hi >> 15; break;
    default:
        shift = v->adsr_hi & 31;
        decrease = 1; exponential = (v->adsr_hi >> 5) & 1;
        break;
    }
    int step = decrease ? -8 + (int)step_value : 7 - (int)step_value;
    step *= 1 << (shift < 11 ? 11 - shift : 0);
    unsigned increment = 0x8000u >> (shift > 11 ? shift - 11 : 0);
    if (exponential && !decrease && v->level > 0x6000) {
        if (shift < 10) step /= 4;
        else if (shift >= 11) increment /= 4;
        else { step /= 2; increment /= 2; }
    } else if (exponential && decrease) step = (step * v->level) >> 15;
    int frozen = shift == 31 && (v->phase == 3 || step_value == 3);
    if (!increment && !frozen) increment = 1;
    v->env_counter += increment;
    if (!(v->env_counter & 0x8000)) return;
    v->env_counter &= 0x7fff;
    v->level += step;
    if (v->level < 0) v->level = 0;
    if (v->level > 0x7fff) v->level = 0x7fff;
    if (v->phase == 0 && v->level == 0x7fff) {
        v->phase = 1; v->env_counter = 0;
    } else if (v->phase == 1 && v->level <= ((v->adsr_lo & 15) + 1)*0x800) {
        v->phase = 2; v->env_counter = 0;
    } else if (v->phase == 3 && !v->level) v->on = 0;
}

static void decode_block(Voice *v) {
    v->cur &= sizeof SPU_RAM - 1;
    uint8_t b[16];
    for (unsigned i = 0; i < sizeof b; i++)
        b[i] = SPU_RAM[(v->cur + i) & (sizeof SPU_RAM - 1)];
    int shift = b[0] & 0x0F, filter = (b[0] >> 4) & 7;
    if (filter > 4) filter = 0;
    int flags = v->block_flags = b[1];
    if (shift > 12) shift = 9;
    for (int i = 0; i < 28; i++) {
        int nib = (b[2 + i / 2] >> ((i & 1) * 4)) & 0xF;
        int32_t s = (int16_t)(nib << 12) >> shift;
        s += (v->prev1 * pos_tab[filter] + v->prev2 * neg_tab[filter]) >> 6;
        if (s > 32767) s = 32767;
        if (s < -32768) s = -32768;
        v->block[i] = (int16_t)s;
        v->prev2 = v->prev1;
        v->prev1 = (int16_t)s;
    }
    v->block_pos = 0;
    if (flags & 0x04)                  /* loop start */
        v->repeat = v->cur;
    v->cur += 16;
}

static int user_master_volume = 100;
void spu_set_master_volume(int percent) {
    user_master_volume = percent < 0 ? 0 : (percent > 100 ? 100 : percent);
}

static void audio_cb(void *ud, Uint8 *stream, int len) {
    (void)ud;
    int16_t *out = (int16_t *)stream;
    int n = len / 4;
    int stats = audio_stats_enabled();
    int mix = audio_mix_stats_enabled();
    for (int i = 0; i < n; i++) {
        int32_t l = 0, r = 0;
        int32_t send_l = 0, send_r = 0;
        int32_t previous_voice = 0;
        noise_timer -= 4 + ((spu_ctrl >> 8) & 3);
        if (noise_timer < 0) {
            unsigned parity = ((noise_level >> 15) ^ (noise_level >> 12) ^
                               (noise_level >> 11) ^ (noise_level >> 10) ^ 1) & 1;
            noise_level = (uint16_t)(noise_level * 2 + parity);
            int32_t reload = 0x20000 >> ((spu_ctrl >> 10) & 15);
            noise_timer += reload;
            if (noise_timer < 0) noise_timer += reload;
        }
        for (int vi = 0; vi < 24; vi++) {
            Voice *v = &voices[vi];
            volume_step(&v->vol_l, v->sweep_l, &v->sweep_counter_l);
            volume_step(&v->vol_r, v->sweep_r, &v->sweep_counter_r);
            int32_t modulation = previous_voice;
            previous_voice = 0;
            if (!(spu_ctrl & 0x8000)) { v->level = 0; continue; }
            if (!v->on) continue;
            envelope(v);
            if (!v->on) continue;
            int32_t s = (noise_enable & (1u << vi)) ? (int16_t)noise_level
                                                    : v->block[v->block_pos];
            s = (s * v->level) >> 15;
            previous_voice = s;
            int32_t vl = (s * v->vol_l) >> 15, vr = (s * v->vol_r) >> 15;
            if(mix)mix_level_record(&mix_stats.voice[vi],vl,vr);
            l += vl; r += vr;
            if (reverb_voices & (1u << vi)) { send_l += vl; send_r += vr; }
            /* step (pitch 0x1000 = 44100Hz); 4.12 fixed point */
            uint32_t step = v->pitch;
            if (vi && (pitch_mod & (1u << vi)))
                step = (uint16_t)(((int32_t)(int16_t)step * (modulation + 0x8000)) >> 15);
            if (step > 0x3fff) step = 0x4000;
            v->frac += step << 4;
            while (v->frac >= 0x10000) {
                v->frac -= 0x10000;
                v->block_pos++;
                if (v->block_pos >= 28) {
                    if (v->block_flags & 1) {
                        endx |= 1u << vi;
                        v->cur = v->repeat;
                        if (!(v->block_flags & 2)) { v->on = 0; v->level = 0; break; }
                    }
                    decode_block(v);
                }
                if (!v->on) break;
            }
        }
        if (!(spu_ctrl & 0x4000)) l = r = send_l = send_r = 0;
        if(mix)mix_level_record(&mix_stats.dry,l,r);
        if (stats && (l || r)) audio_stats.voice_nonzero++;
        if (cd_count) {
            int32_t cl = cd_pcm[cd_read][0], cr = cd_pcm[cd_read][1];
            if(mix)mix_level_record(&mix_stats.cd_source,cl,cr);
            if (stats) {
                audio_stats.cd_consumed++;
                if (cl || cr) audio_stats.cd_nonzero++;
                audio_stats.cd_energy += (uint64_t)((int64_t)cl*cl + (int64_t)cr*cr);
            }
            cd_read = (cd_read + 1) % CD_FRAMES; cd_count--;
            if ((spu_ctrl & 1) && !cd_muted) {
                int32_t cdl = (int32_t)(((int64_t)(cl*cd_ll + cr*cd_rl) * cd_vol_l) >> 22);
                int32_t cdr = (int32_t)(((int64_t)(cl*cd_lr + cr*cd_rr) * cd_vol_r) >> 22);
                if(mix)mix_level_record(&mix_stats.cd_mix,cdl,cdr);
                if (stats && (cdl || cdr)) audio_stats.cd_mixed_nonzero++;
                l += cdl; r += cdr;
                if (spu_ctrl & 4) { send_l += cdl; send_r += cdr; }
            }
        } else if (stats && cd_rate) audio_stats.cd_missing++;
        int32_t wet[2];
        reverb_sample(send_l, send_r, wet);
        if(mix)mix_level_record(&mix_stats.wet,wet[0],wet[1]);
        l += wet[0]; r += wet[1];
        if(mix)mix_level_record(&mix_stats.pre_master,l,r);
        /* Saturate the combined dry/CD/wet bus before signed main gain. */
        l = clip16(l); r = clip16(r);
        volume_step(&vol_main_l, main_sweep_l, &main_counter_l);
        volume_step(&vol_main_r, main_sweep_r, &main_counter_r);
        l = (int32_t)(((int64_t)l * vol_main_l) >> 15);
        r = (int32_t)(((int64_t)r * vol_main_r) >> 15);
        if(mix)mix_level_record(&mix_stats.post_master,l,r);
        if (l > 32767) l = 32767;
        if (l < -32768) l = -32768;
        if (r > 32767) r = 32767;
        if (r < -32768) r = -32768;
        l = l * user_master_volume / 100;
        r = r * user_master_volume / 100;
        out[i * 2] = (int16_t)l;
        out[i * 2 + 1] = (int16_t)r;
        if (stats && (l || r)) audio_stats.pcm_nonzero++;
    }
}

/* Audio output is a runtime toggle (settings menu / A2_SOUND); SPU
 * state always advances on the emulation thread, never on an SDL callback.
 * SDL owns only a copy of finished PCM, so register/DMA writes cannot race. */
static SDL_AudioDeviceID spu_dev;
static int sound_enabled;
static int output_priming;
static Uint32 output_prime_bytes;

void spu_set_sound(int on) {
    /* Settings may reapply an unchanged value: don't interrupt live PCM. */
    if (on && sound_enabled && spu_dev) return;
    sound_enabled = !!on;
    if (on && !spu_dev) {
        if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0) {
            fprintf(stderr, "audio: SDL init failed: %s\n", SDL_GetError());
            return;
        }
        SDL_AudioSpec want = {0}, have;
        want.freq = 44100;
        want.format = AUDIO_S16SYS;
        want.channels = 2;
        want.samples = 1024;
        spu_dev = SDL_OpenAudioDevice(NULL, 0, &want, &have, 0);
        if (!spu_dev) fprintf(stderr, "audio: device open failed: %s\n", SDL_GetError());
        else {
            unsigned frames = 3u * (have.samples ? have.samples : want.samples);
            /* Never prime beyond 100ms, even with an unusually large device
             * period; the separate overflow cap is approximately 200ms. */
            if (frames > 4410) frames = 4410;
            output_prime_bytes = frames * 4;
        }
    }
    if (spu_dev) {
        SDL_PauseAudioDevice(spu_dev, 1);
        SDL_ClearQueuedAudio(spu_dev);
        output_priming = !!on;
    }
}

void spu_init_audio(void) {
    /* actual device state applied by settings_load caller (main.c);
     * A2_SOUND=1 keeps working as the env override */
}

void spu_vblank(void) {
    A2Phase previous_phase = a2_phase_enter(A2_PHASE_SPU_MIX);
    int stats = audio_stats_enabled();
    uint64_t tick_gap = 0;
    if (stats) {
        uint64_t now = SDL_GetPerformanceCounter();
        tick_gap = audio_stats.last_clock ? now - audio_stats.last_clock : 0;
        if (tick_gap > audio_stats.max_gap) audio_stats.max_gap = tick_gap;
        audio_stats.last_clock = now;
        if (audio_stats.tick % 60 == 0) audio_stats.queue_min = UINT32_MAX;
        audio_stats.tick++;
    }
    int16_t pcm[735 * 2];
    audio_cb(NULL, (Uint8 *)pcm, sizeof pcm);
    (void)a2_phase_enter(A2_PHASE_SPU_QUEUE);
    if (spu_dev && sound_enabled) {
        Uint32 queued = SDL_GetQueuedAudioSize(spu_dev);
        if (stats) {
            if (queued < audio_stats.queue_min) audio_stats.queue_min = queued;
            if (queued > audio_stats.queue_max) audio_stats.queue_max = queued;
            if (!output_priming && queued == 0) {
                /* One spu_vblank is produced per native frame. Keep this event
                 * self-contained so standalone mixer tests need no host state. */
                fprintf(stderr, "audioqueueempty: frame=%u tick=%llu gap_ticks=%llu "
                        "gap_ms=%.3f prime_bytes=%u\n", (unsigned)audio_stats.tick,
                        (unsigned long long)audio_stats.tick, (unsigned long long)tick_gap,
                        1000.0 * tick_gap / SDL_GetPerformanceFrequency(), output_prime_bytes);
                audio_stats.host_starve++;
            }
            if (queued > 44100 * 4 / 5) audio_stats.host_overflow++;
        }
        /* A starved or fast-forwarded device must rebuild its bounded reserve
         * paused, never repeatedly restart from a single short game frame. */
        if ((!output_priming && queued == 0) || queued > 44100 * 4 / 5) {
            SDL_PauseAudioDevice(spu_dev, 1);
            SDL_ClearQueuedAudio(spu_dev);
            output_priming = 1;
        }
        if (SDL_QueueAudio(spu_dev, pcm, sizeof pcm) < 0) {
            if (stats) audio_stats.host_fail++;
            fprintf(stderr, "audio: queue failed: %s\n", SDL_GetError());
            SDL_PauseAudioDevice(spu_dev, 1);
            SDL_ClearQueuedAudio(spu_dev);
            output_priming = 1;
        } else if (output_priming && SDL_GetQueuedAudioSize(spu_dev) >= output_prime_bytes) {
            if (stats) audio_stats.host_resume++;
            output_priming = 0;
            SDL_PauseAudioDevice(spu_dev, 0);
        }
    }
    (void)a2_phase_enter(A2_PHASE_DIAG);
    if(audio_mix_stats_enabled() && ++mix_stats.ticks%60==0)audio_mix_stats_report();
    if (stats && audio_stats.tick % 60 == 0) {
        unsigned active = 0;
        for (int i = 0; i < 24; i++) if (voices[i].on && voices[i].level) active++;
        fprintf(stderr, "audiostat: tick=%llu cd_consumed=%llu cd_missing=%llu cd_nonzero=%llu "
                "cd_mixed_nonzero=%llu voice_nonzero=%llu pcm_nonzero=%llu "
                "host_starve=%llu host_overflow=%llu host_fail=%llu host_resume=%llu "
                "queue_min=%u queue_max=%u max_gap_ms=%.3f cd_fifo=%u cd_rate=%u "
                "cd_dropped=%llu cd_resets=%llu cd_energy=%llu ctrl=%04X cd_vol=%d,%d matrix=%u,%u,%u,%u "
                "cd_muted=%d voices=%u priming=%d\n",
                (unsigned long long)audio_stats.tick, (unsigned long long)audio_stats.cd_consumed,
                (unsigned long long)audio_stats.cd_missing, (unsigned long long)audio_stats.cd_nonzero,
                (unsigned long long)audio_stats.cd_mixed_nonzero, (unsigned long long)audio_stats.voice_nonzero,
                (unsigned long long)audio_stats.pcm_nonzero, (unsigned long long)audio_stats.host_starve,
                (unsigned long long)audio_stats.host_overflow, (unsigned long long)audio_stats.host_fail,
                (unsigned long long)audio_stats.host_resume,
                audio_stats.queue_min == UINT32_MAX ? 0 : audio_stats.queue_min, audio_stats.queue_max,
                1000.0 * audio_stats.max_gap / SDL_GetPerformanceFrequency(), cd_count, cd_rate,
                (unsigned long long)audio_stats.cd_dropped, (unsigned long long)audio_stats.cd_resets,
                (unsigned long long)audio_stats.cd_energy,
                spu_ctrl, cd_vol_l, cd_vol_r, cd_ll, cd_lr, cd_rl, cd_rr, cd_muted, active, output_priming);
        audio_stats.queue_max = 0; audio_stats.max_gap = 0;
    }
    a2_phase_leave(previous_phase);
}

static void key_on(int vi) {
    Voice *v = &voices[vi];
    v->cur = v->start;
    v->repeat = v->start;
    v->prev1 = v->prev2 = 0;
    v->frac = 0;
    v->level = 0;
    v->phase = 0; v->env_counter = 0;
    v->on = 1;
    endx &= ~(1u << vi);
    decode_block(v);
}

static void key_off(int vi) {
    voices[vi].phase = 3; voices[vi].env_counter = 0;
}

/* register interface (offsets relative to 0x1F801C00, halfword writes) */
void spu_write(uint32_t off, uint16_t v) {
    if (off >= sizeof register_readback || (off & 1)) return;
    register_readback[off / 2] = v;
    if (off < 24 * 16) {
        int vi = off / 16, r = off & 15;
        Voice *vc = &voices[vi];
        switch (r) {
        case 0x0: volume_write(&vc->vol_l, &vc->sweep_l, &vc->sweep_counter_l, v); break;
        case 0x2: volume_write(&vc->vol_r, &vc->sweep_r, &vc->sweep_counter_r, v); break;
        case 0x4: vc->pitch = v; break;
        case 0x6: vc->start = (uint32_t)v << 3; break;
        case 0x8: vc->adsr_lo = v; break;
        case 0xA: vc->adsr_hi = v; break;
        case 0xC: vc->level = (int16_t)v; break;
        case 0xE: vc->repeat = (uint32_t)v << 3; break;
        }
        return;
    }
    switch (off + 0x1C00) {
    case 0x1D80: volume_write(&vol_main_l, &main_sweep_l, &main_counter_l, v); break;
    case 0x1D82: volume_write(&vol_main_r, &main_sweep_r, &main_counter_r, v); break;
    case 0x1D84: reverb_volume[0] = (int16_t)v; break;
    case 0x1D86: reverb_volume[1] = (int16_t)v; break;
    case 0x1D98: reverb_voices = (reverb_voices & 0xff0000u) | v; break;
    case 0x1D9A: reverb_voices = (reverb_voices & 0xffffu) | ((uint32_t)(v & 0xff) << 16); break;
    case 0x1DA2: reverb_cursor = reverb_base = (uint32_t)v << 3; break;
    case 0x1D88: keyon_latch = (keyon_latch & 0xFFFF0000u) | v; goto kon;
    case 0x1D8A: keyon_latch = (keyon_latch & 0xFFFFu) | ((uint32_t)v << 16);
kon:    for (int i = 0; i < 24; i++)
            if (keyon_latch & (1u << i)) key_on(i);
        keyon_latch = 0;
        break;
    case 0x1D8C: keyoff_latch = (keyoff_latch & 0xFFFF0000u) | v; goto koff;
    case 0x1D8E: keyoff_latch = (keyoff_latch & 0xFFFFu) | ((uint32_t)v << 16);
koff:   for (int i = 0; i < 24; i++)
            if (keyoff_latch & (1u << i)) key_off(i);
        keyoff_latch = 0;
        break;
    case 0x1DA6: xfer_addr = (uint32_t)v << 3; break;
    case 0x1D90: pitch_mod = (pitch_mod & 0xff0000u) | (v & 0xfffe); break;
    case 0x1D92: pitch_mod = (pitch_mod & 0xffffu) | ((uint32_t)(v & 0xff) << 16); break;
    case 0x1D94: noise_enable = (noise_enable & 0xff0000u) | v; break;
    case 0x1D96: noise_enable = (noise_enable & 0xffffu) | ((uint32_t)(v & 0xff) << 16); break;
    case 0x1DA8:                        /* manual fifo write */
        SPU_RAM[xfer_addr] = v & 0xFF;
        SPU_RAM[(xfer_addr + 1) & (sizeof SPU_RAM - 1)] = v >> 8;
        xfer_addr = (xfer_addr + 2) & (sizeof SPU_RAM - 1);
        break;
    case 0x1DAA: spu_ctrl = v; break;
    case 0x1DB0: cd_vol_l = (int16_t)v; break;
    case 0x1DB2: cd_vol_r = (int16_t)v; break;
    }
}

uint16_t spu_read(uint32_t off) {
    if (off >= sizeof register_readback || (off & 1)) return 0;
    if (off >= 0x200 && off < 0x260) {
        Voice *vc = &voices[(off - 0x200)/4];
        return (uint16_t)((off & 2) ? vc->vol_r : vc->vol_l);
    }
    if (off < 24 * 16) {
        Voice *vc = &voices[off / 16];
        switch (off & 15) {
        case 4: return vc->pitch;
        case 6: return (uint16_t)(vc->start >> 3);
        case 8: return vc->adsr_lo;
        case 10: return vc->adsr_hi;
        case 12: return (uint16_t)vc->level;
        case 14: return (uint16_t)(vc->repeat >> 3);
        }
    }
    switch (off + 0x1C00) {
    case 0x1DAA: return spu_ctrl;
    case 0x1DAE: return spu_ctrl & 0x3F;   /* STAT mirrors mode bits */
    case 0x1D9C: return (uint16_t)endx;
    case 0x1D9E: return (uint16_t)(endx >> 16);
    case 0x1DA6: return (uint16_t)(xfer_addr >> 3);
    case 0x1DB8: return (uint16_t)vol_main_l;
    case 0x1DBA: return (uint16_t)vol_main_r;
    }
    return register_readback[off / 2];
}

/* DMA channel 4: RAM -> SPU RAM block transfer */
void spu_dma_write(const uint8_t *src, uint32_t bytes) {
    while (bytes) {
        xfer_addr &= sizeof SPU_RAM - 1;
        uint32_t n = sizeof SPU_RAM - xfer_addr;
        if (n > bytes) n = bytes;
        memcpy(SPU_RAM + xfer_addr, src, n);
        src += n;
        bytes -= n;
        xfer_addr = (xfer_addr + n) & (sizeof SPU_RAM - 1);
    }
}
