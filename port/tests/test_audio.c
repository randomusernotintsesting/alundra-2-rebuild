#include <assert.h>
#include <stdio.h>
#include <string.h>
/* Include the real mixer to inspect deterministic sample/state transitions. */
#include "../src/spu.c"

static void constant_voice(int vi, int16_t sample, uint16_t pitch) {
    memset(&voices[vi], 0, sizeof voices[vi]);
    spu_write(vi*16, 0x3fff); spu_write(vi*16+2, 0x3fff);
    spu_write(vi*16+4, pitch); spu_write(vi*16+10, 0x7fc0);
    voices[vi].on = 1; voices[vi].phase = 2; voices[vi].level = 0x4000;
    voices[vi].block_flags = 3;
    for (int i = 0; i < 28; i++) voices[vi].block[i] = sample;
}
static void put_sample(uint32_t address, int16_t value) {
    SPU_RAM[address] = (uint8_t)value;
    SPU_RAM[address+1] = (uint8_t)((uint16_t)value >> 8);
}
static void clear_reverb_test(uint16_t base) {
    memset(SPU_RAM, 0, sizeof SPU_RAM);
    memset(reverb_input_history, 0, sizeof reverb_input_history);
    memset(reverb_output_history, 0, sizeof reverb_output_history);
    reverb_filter_pos = reverb_phase = 0;
    spu_write(0x1a2, base);
    for (unsigned off = 0x1c0; off < 0x200; off += 2) spu_write(off, 0);
}
static void enqueue_mixer_cd(const int16_t *pcm, unsigned frames) {
    /* Mixer/routing fixtures start after XA reconstruction. Its impulse,
     * rate conversion and history are tested separately in audio_resample. */
    assert(cd_count == 0 && frames <= CD_FRAMES);
    memcpy(cd_pcm, pcm, frames * 2 * sizeof *pcm);
    cd_read = 0; cd_count = frames;
}

int main(void) {
    spu_init_audio();
    spu_write(0x1aa, 0xc000);
    /* The final 16-byte SPU RAM block is valid, not an address wrap. */
    Voice v = {0};
    v.cur = sizeof SPU_RAM - 16;
    SPU_RAM[v.cur] = 12;
    SPU_RAM[v.cur + 2] = 0x71;
    decode_block(&v);
    assert(v.block[0] == 1 && v.block[1] == 7);
    /* Start/repeat registers address 8-byte units, including a split block. */
    v.cur = sizeof SPU_RAM - 8;
    SPU_RAM[v.cur] = 12; SPU_RAM[v.cur + 2] = 0x53;
    SPU_RAM[5] = 0x60;
    decode_block(&v);
    assert(v.block[0] == 3 && v.block[1] == 5 && v.block[23] == 6);
    /* DMA crosses the end of the 512 KiB ring without losing bytes. */
    const uint8_t bytes[] = {1,2,3,4,5,6,7,8,9,10};
    spu_write(0x1a6, 0xffff);
    spu_dma_write(bytes, sizeof bytes);
    assert(SPU_RAM[0] == 9 && SPU_RAM[1] == 10);
    spu_write(0x1a6, 0xffff);
    for (int i = 0; i < 5; i++) spu_write(0x1a8, 0x1234);
    assert(SPU_RAM[0] == 0x34 && SPU_RAM[1] == 0x12);
    /* ENDX belongs to the block boundary, including looped voices. */
    memset(SPU_RAM, 0, sizeof SPU_RAM);
    SPU_RAM[1] = 3;
    spu_write(4, 0x1000);
    spu_write(0x188, 1);
    int16_t out[28 * 2];
    audio_cb(NULL, (Uint8 *)out, sizeof out);
    assert(spu_read(0x19c) & 1);
    spu_set_sound(0);
    spu_write(0x188, 1);
    assert(!(spu_read(0x19c) & 1));
    spu_vblank();
    assert(spu_read(0x19c) & 1); /* muted must still progress */
    memset(voices, 0, sizeof voices);
    spu_write(0x1aa, 0xc001); /* CD input enabled */
    spu_write(0x1b0, 0x7fff); spu_write(0x1b2, 0x7fff);
    int16_t cd[14] = {10000,-10000,10000,-10000,10000,-10000,
                     10000,-10000,10000,-10000,10000,-10000,10000,-10000};
    enqueue_mixer_cd(cd, 7);
    audio_cb(NULL, (Uint8 *)out, 8*4);
    /* Positive: CD32767/Q15 yields9999, main32766/Q15 yields9998.
     * Arithmetic floor keeps the corresponding negative result at-10000. */
    for (unsigned frame = 0; frame < 7; frame++)
        assert(out[frame*2] == 9998 && out[frame*2+1] == -10000);
    assert(out[14] == 0 && out[15] == 0 && cd_count == 0);
    spu_push_cd_audio(cd, 6, 18900); /* exactly fourteen */
    assert(cd_count == 14);
    spu_set_cd_mix(128, 0, 0, 128, 1);
    audio_cb(NULL, (Uint8 *)out, 14*4);
    for (int i = 0; i < 28; i++) assert(out[i] == 0);
    spu_set_cd_mix(128, 0, 0, 128, 0);
    audio_cb(NULL, (Uint8 *)out, 4);
    assert(out[0] == 0); /* muted audio consumed, not deferred */
    spu_write(8, 0x000f); /* fastest attack, full sustain target */
    spu_write(10, 0x7fc0); /* frozen sustain, fastest release */
    spu_write(0x188, 1);
    audio_cb(NULL, (Uint8 *)out, 4);
    assert(spu_read(12) == 14336); /* 7 * 2^11 */
    audio_cb(NULL, (Uint8 *)out, 8);
    assert(spu_read(12) == 32767);
    spu_write(0x18c, 1);
    audio_cb(NULL, (Uint8 *)out, 4);
    assert(spu_read(12) == 16383); /* release -8 * 2^11 */
    audio_cb(NULL, (Uint8 *)out, 4);
    assert(spu_read(12) == 0);
    memset(voices, 0, sizeof voices);
    memset(SPU_RAM, 0, 16);
    SPU_RAM[1] = 1; SPU_RAM[2] = 0x21; SPU_RAM[15] = 0x70;
    spu_write(0, 0x3fff); spu_write(2, 0x3fff); spu_write(4, 0x1000);
    spu_write(10, 0x7fc0); spu_write(0x188, 1);
    voices[0].phase = 2; voices[0].level = 0x7fff;
    audio_cb(NULL, (Uint8 *)out, sizeof out);
    assert(out[0] > 4000 && out[0] < 4100);
    assert(out[54] > 28000); /* last sample must play before END */
    spu_write(0x1aa, 0x8001);
    spu_write(0x188, 1); voices[0].phase = 2; voices[0].level = 0x7fff;
    audio_cb(NULL, (Uint8 *)out, 4);
    assert(out[0] == 0); /* SPUCNT voice mute */
    memset(voices, 0, sizeof voices);
    spu_write(0x1aa, 0xc000);
    constant_voice(0, 0x4000, 0);
    constant_voice(1, 0, 0x1000);
    spu_write(0x190, 3); /* voice0 ignored; voice1 receives voice0's ADSR output */
    spu_write(0, 0); spu_write(2, 0); /* pan/volume must not affect modulation */
    audio_cb(NULL, (Uint8 *)out, 4);
    assert(voices[1].block_pos == 1 && voices[1].frac == 0x4000);
    assert(voices[0].block_pos == 0);
    spu_write(0x190, 0);
    memset(voices, 0, sizeof voices);
    constant_voice(0, 0, 0);
    noise_level = 0; noise_timer = 0;
    spu_write(0x194, 1);
    spu_write(0x1aa, 0xfc00); /* shift15, step4: one noise update per sample */
    audio_cb(NULL, (Uint8 *)out, 16);
    assert(out[6] != 0); /* noise plays even at pitch zero */
    assert(noise_level == 15);
    spu_write(0x194, 0); spu_write(0x1aa, 0xc000);
    memset(voices, 0, sizeof voices);
    spu_write(0, 0x1000); spu_write(0, 0x8000); /* sweep from current +8192 */
    audio_cb(NULL, (Uint8 *)out, 4);
    assert(spu_read(0x200) == 22528);
    spu_write(0, 0xa000); /* fastest linear decrease */
    audio_cb(NULL, (Uint8 *)out, 4);
    assert(spu_read(0x200) == 6144);
    audio_cb(NULL, (Uint8 *)out, 4);
    assert(spu_read(0x200) == 0);
    spu_write(0, 0x3800); spu_write(0, 0xc000); /* exponential rise slows above6000 */
    audio_cb(NULL, (Uint8 *)out, 4);
    assert(spu_read(0x200) == 32256);
    spu_write(0, 0x2000); spu_write(0, 0xe000);
    audio_cb(NULL, (Uint8 *)out, 4);
    assert(spu_read(0x200) == 8192);
    spu_write(0, 0); spu_write(0, 0x9000);
    audio_cb(NULL, (Uint8 *)out, 4);
    assert((int16_t)spu_read(0x200) == -16384);
    spu_write(0, 0x1234); spu_write(0, 0x807f);
    audio_cb(NULL, (Uint8 *)out, sizeof out);
    assert(spu_read(0x200) == 0x2468); /* all-one rate freezes existing volume */
    spu_write(0x180, 0); spu_write(0x180, 0x8000);
    audio_cb(NULL, (Uint8 *)out, 4);
    assert(spu_read(0x1b8) == 14336);
    spu_write(0x180, 0x3fff);
    spu_write(0, 0x6000); spu_write(0, 0xb000);
    audio_cb(NULL, (Uint8 *)out, 4);
    assert((int16_t)spu_read(0x200) == -2048); /* negative linear decrease toward0 */
    audio_cb(NULL, (Uint8 *)out, 4);
    assert(spu_read(0x200) == 0);
    memset(voices, 0, sizeof voices);
    constant_voice(0, -0x4000, 0);
    constant_voice(1, 0, 0x1000);
    spu_write(0x190, 2);
    audio_cb(NULL, (Uint8 *)out, 4);
    assert(voices[1].block_pos == 0 && voices[1].frac == 0xc000);
    spu_write(0x190, 0);
    constant_voice(1, 0, 0x4000);
    audio_cb(NULL, (Uint8 *)out, 4);
    assert(spu_read(0x14) == 0x4000 && voices[1].block_pos == 4);
    memset(voices, 0, sizeof voices);
    constant_voice(0, 0, 0); constant_voice(1, 0, 0x1234);
    spu_write(2, 0); spu_write(16, 0);
    spu_write(0x194, 3); spu_write(0x1aa, 0xfc00);
    noise_level = 0x4000; noise_timer = 0;
    audio_cb(NULL, (Uint8 *)out, 4);
    assert(noise_level == 0x8001 && out[0] < 0 && out[0] == out[1]);
    audio_cb(NULL, (Uint8 *)out, 4);
    assert(noise_level == 2); /* shared LFSR, independent of voice pitch */
    spu_write(0x1aa, 0xc000); noise_level = 0; noise_timer = 0;
    audio_cb(NULL, (Uint8 *)out, 16);
    assert(noise_level == 1); /* low noise rate holds sample across clocks */
    /* Reverb readback keeps playing existing RAM even with write-enable off.
     * vAPF2=0 selects its delayed tap directly, irrespective of prior stages. */
    memset(SPU_RAM, 0, sizeof SPU_RAM);
    spu_write(0x1a2, 0xfff0); /* final128 bytes are the work ring */
    for (unsigned off = 0x1c0; off < 0x200; off += 2) spu_write(off, 0);
    spu_write(0x1f8, 1); spu_write(0x1fa, 2);
    SPU_RAM[0x7ff88] = 0x00; SPU_RAM[0x7ff89] = 0x20;
    SPU_RAM[0x7ff90] = 0x00; SPU_RAM[0x7ff91] = 0xe0;
    spu_write(0x1aa, 0xc000);
    int32_t wet[2];
    reverb_process(1234, 5678, wet);
    assert(wet[0] == 8192 && wet[1] == -8192);
    memset(voices, 0, sizeof voices);
    spu_write(0x184, 0x7fff); spu_write(0x186, 0x7fff);
    spu_write(0x1a2, 0xfff0);
    uint8_t before_reverb[128]; memcpy(before_reverb, SPU_RAM+0x7ff80, 128);
    int16_t reverberated[64*2];
    audio_cb(NULL, (Uint8 *)reverberated, sizeof reverberated);
    int heard = 0;
    for (unsigned i = 0; i < 128; i++) heard |= reverberated[i] != 0;
    assert(heard); /* disabled writes do not silence existing wet buffer */
    assert(memcmp(before_reverb, SPU_RAM+0x7ff80, 128) == 0);
    assert(reverb_cursor == 0x7ffc0); /* 32ticks at half-rate */
    /* Independently worked half-gain reflection/comb/two-APF example.
     * The right APF1 reads an address the left APF2 will later overwrite. */
    memset(SPU_RAM, 0, sizeof SPU_RAM);
    const uint16_t reverb_vector[32] = {
        1,1,0x4000,0x4000,0,0,0,0x4000,0x4000,0x4000,
        1,2,1,2,0,0,3,4,5,6,0,0,0,0,8,7,9,12,11,14,0x4000,0x4000
    };
    for (unsigned i = 0; i < 32; i++) spu_write(0x1c0+2*i, reverb_vector[i]);
    spu_write(0x1a2, 0xfff0); spu_write(0x1aa, 0xc080);
    put_sample(0x7ff86, 4096); put_sample(0x7ff8e, -4096);
    put_sample(0x7ff98, 8192); put_sample(0x7ffa0, -8192);
    put_sample(0x7ffb8, 16384); put_sample(0x7ffc0, -16384);
    reverb_process(16384, -16384, wet);
    assert(wet[0] == -5120 && wet[1] == -1024);
    assert((int16_t)(SPU_RAM[0x7ff88] | SPU_RAM[0x7ff89]<<8) == 8192);
    assert((int16_t)(SPU_RAM[0x7ffa8] | SPU_RAM[0x7ffa9]<<8) == 8192);
    clear_reverb_test(0xfff0);
    spu_write(0x1c4, 0x8000); spu_write(0x1fc, 0x8000);
    spu_write(0x1d4, 1); spu_write(0x1d6, 2);
    spu_write(0x1e4, 3); spu_write(0x1e6, 4);
    reverb_process(1000, 0, wet);
    assert((int16_t)(SPU_RAM[0x7ff88] | SPU_RAM[0x7ff89]<<8) == -1000);
    /* Work region may be just8bytes: positive and negative taps stay inside. */
    spu_write(0x1a2, 0xffff);
    memset(SPU_RAM+0x7fff0, 0x55, 8);
    assert(reverb_address(-2) == 0x7fffe);
    assert(reverb_address(0xffff*8) == 0x7fff8);
    for (int i = 0; i < 4; i++) reverb_process(32767, -32768, wet);
    assert(reverb_cursor == 0x7fff8);
    for (int i = 0; i < 8; i++) assert(SPU_RAM[0x7fff0+i] == 0x55);
    /* Published Room preset: an impulse produces a stereo decaying tail. */
    const uint16_t room[32] = {
        0x7d,0x5b,0x6d80,0x54b8,0xbed0,0,0,0xba80,
        0x5800,0x5300,0x4d6,0x333,0x3f0,0x227,0x374,0x1ef,
        0x334,0x1b5,0,0,0,0,0,0,0,0,0x1b4,0x136,0xb8,0x5c,0x8000,0x8000
    };
    clear_reverb_test((0x80000-0x26c0)/8);
    for (unsigned i = 0; i < 32; i++) spu_write(0x1c0+2*i, room[i]);
    uint64_t early_energy = 0, late_energy = 0;
    unsigned stereo_tail = 0;
    for (int i = 0; i < 12000; i++) {
        reverb_process(i == 0 ? 16000 : 0, i == 0 ? -16000 : 0, wet);
        uint64_t energy = (uint64_t)((int64_t)wet[0]*wet[0]+(int64_t)wet[1]*wet[1]);
        if (i < 6000) early_energy += energy; else late_energy += energy;
        stereo_tail |= wet[1] != 0;
    }
    fprintf(stderr, "Room impulse energy: early=%llu late=%llu stereo=%u\n",
            (unsigned long long)early_energy, (unsigned long long)late_energy, stereo_tail);
    assert(early_energy > 0 && late_energy < early_energy && stereo_tail);
    /* EON routes voices into work RAM; dry-only voices cannot feed reverb. */
    clear_reverb_test(0xfff0);
    spu_write(0x1c4, 0x4000); spu_write(0x1fc, 0x4000); spu_write(0x1fe, 0x4000);
    spu_write(0x1d4, 1); spu_write(0x1d6, 2);
    spu_write(0x1e4, 3); spu_write(0x1e6, 4);
    memset(voices, 0, sizeof voices); spu_write(0x194, 0); spu_write(0x198, 0);
    constant_voice(0, 0x4000, 0);
    audio_cb(NULL, (Uint8 *)reverberated, sizeof reverberated);
    for (int i = 0; i < 128; i++) assert(SPU_RAM[0x7ff80+i] == 0);
    assert(reverberated[0] > 0);
    spu_write(0x198, 1);
    audio_cb(NULL, (Uint8 *)reverberated, sizeof reverberated);
    int fed = 0;
    for (int i = 0; i < 128; i++) fed |= SPU_RAM[0x7ff80+i] != 0;
    assert(fed);
    memset(voices, 0, sizeof voices);
    memset(SPU_RAM, 0, sizeof SPU_RAM);
    memset(reverb_input_history, 0, sizeof reverb_input_history);
    memset(reverb_output_history, 0, sizeof reverb_output_history);
    spu_write(0x1aa, 0xc081); /* CD dry enabled, CD reverb disabled */
    enqueue_mixer_cd(cd, 7);
    audio_cb(NULL, (Uint8 *)reverberated, sizeof reverberated);
    for (int i = 0; i < 128; i++) assert(SPU_RAM[0x7ff80+i] == 0);
    spu_write(0x1aa, 0xc085);
    enqueue_mixer_cd(cd, 7);
    audio_cb(NULL, (Uint8 *)reverberated, sizeof reverberated);
    fed = 0;
    for (int i = 0; i < 128; i++) fed |= SPU_RAM[0x7ff80+i] != 0;
    assert(fed);
    /* Resampler histories and half-rate phase persist across render chunks. */
    int16_t whole[128], split[128];
    for (int pass = 0; pass < 2; pass++) {
        clear_reverb_test(0xfff0); spu_write(0x1aa, 0xc000);
        spu_write(0x1f8, 1); spu_write(0x1fa, 2);
        for (int i = 0; i < 64; i++) put_sample(0x7ff80+2*i, (int16_t)(i*100-3000));
        if (!pass) audio_cb(NULL, (Uint8 *)whole, sizeof whole);
        else {
            audio_cb(NULL, (Uint8 *)split, 7*4);
            audio_cb(NULL, (Uint8 *)(split+14), 57*4);
        }
    }
    assert(memcmp(whole, split, sizeof whole) == 0);
    puts("audio RAM tests passed");
    return 0;
}
