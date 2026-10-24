/* Exercise the real mixer, not a second implementation of its arithmetic.
 * Reference order is mixed dry + CD + wet -> signed16 clamp -> main volume:
 * https://github.com/stenzek/duckstation/blob/master/src/core/spu.cpp
 * https://github.com/libretro/beetle-psx-libretro/blob/master/mednafen/psx/spu.c
 * Both apply main volume after saturating the aggregate mix. */
#define main existing_audio_test_main
#include "test_audio.c"
#undef main

static void clip_scene(unsigned count, uint16_t master) {
    memset(voices, 0, sizeof voices);
    clear_reverb_test(0);
    spu_reset_cd_audio();
    spu_set_cd_mix(128, 0, 0, 128, 0);
    mix_stats_mode = 0;
    spu_write(0x1aa, 0xc001);
    spu_write(0x180, master); spu_write(0x182, master);
    spu_write(0x184, 0); spu_write(0x186, 0);
    spu_write(0x1b0, 0x4000); spu_write(0x1b2, 0x4000);
    spu_write(0x190, 0); spu_write(0x192, 0);
    spu_write(0x194, 0); spu_write(0x196, 0);
    spu_write(0x198, 0); spu_write(0x19a, 0);
    for (unsigned vi = 0; vi < count; vi++) {
        constant_voice((int)vi, 20000, 0);
        /* Half envelope, then +half/-half pan: exactly +5000/-5000. */
        spu_write(vi * 16, 0x2000);
        spu_write(vi * 16 + 2, 0x6000);
    }
}

static unsigned check_pcm(const char *name, int16_t left, int16_t right) {
    int16_t pcm[8];
    audio_cb(NULL, (Uint8 *)pcm, sizeof pcm);
    for (unsigned frame = 0; frame < 4; frame++) {
        if (pcm[frame * 2] != left || pcm[frame * 2 + 1] != right) {
            fprintf(stderr, "%s: frame %u got %d,%d; expected %d,%d\n",
                    name, frame, pcm[frame * 2], pcm[frame * 2 + 1], left, right);
            return 1;
        }
    }
    return 0;
}

int main(void) {
    unsigned failures = 0;
    /* No audio device or SDL initialization is needed for deterministic PCM. */
    clip_scene(4, 0x2000);
    failures += check_pcm("unclipped +/-20000, half main", 10000, -10000);

    clip_scene(8, 0x2000);
    /* +/-40000 first saturates to 32767/-32768. Signed half-volume then
     * yields these literals; applying half-volume first incorrectly gives
     * 20000/-20000 and hides the required clipping. */
    failures += check_pcm("clipped +/-40000, half main", 16383, -16384);

    clip_scene(8, 0x6000);
    failures += check_pcm("clipped +/-40000, negative half main", -16384, 16384);

    clip_scene(8, 0x4000);
    /* A -1 main volume turns -32768 into +32768: final saturation is still
     * required, independently of the pre-master saturation. */
    failures += check_pcm("clipped +/-40000, negative unity main", -32767, 32767);

    clip_scene(8, 0);
    failures += check_pcm("clipped mix with zero main", 0, 0);

    clip_scene(16, 0x2000);
    for (unsigned vi = 8; vi < 16; vi++)
        for (unsigned sample = 0; sample < 28; sample++)
            voices[vi].block[sample] = -20000;
    failures += check_pcm("opposing voices cancel before aggregate clamp", 0, 0);

    clip_scene(4, 0x2000);
    const int16_t cd[8] = {30000, -30000, 30000, -30000,
                           30000, -30000, 30000, -30000};
    /* Already-resampled FIFO samples isolate mixing from XA filter startup. */
    memcpy(cd_pcm, cd, sizeof cd);
    cd_read = 0; cd_count = 4;
    /* Dry +/-20000 plus half-volume CD +/-15000 overloads only the combined
     * bus; clamping dry voices alone is not sufficient. */
    failures += check_pcm("combined voice and CD bus before main", 16383, -16384);

    if (failures) return 1;
    puts("PASS: aggregate signed16 clipping precedes signed main volume");
    return 0;
}
