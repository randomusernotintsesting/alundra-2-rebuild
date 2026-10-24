/* Silent read-only synthesis probe: no audio device is initialized/opened.
 * Includes the real implementation, but changes no production source.
 * clang -std=c11 -O1 -g -fsanitize=undefined -I/opt/homebrew/include/SDL2 \
 *   port/tests/diagnose_spu_sampling.c -L/opt/homebrew/lib -lSDL2 \
 *   -o /tmp/a2-spu-sampling-probe
 */
#include <assert.h>
#include "../src/spu.c"

static void configure_voice(uint16_t pitch) {
    memset(voices, 0, sizeof voices);
    memset(SPU_RAM, 0, sizeof SPU_RAM);
    spu_write(0x1aa, 0xc000);
    spu_write(0, 0x3fff); spu_write(2, 0x3fff);
    spu_write(4, pitch); spu_write(10, 0x7fc0);
    voices[0].on = 1; voices[0].phase = 2; voices[0].level = 0x7fff;
}

int main(void) {
    int16_t out[2];
    configure_voice(0x0800);
    for (int i = 0; i < 28; i++) voices[0].block[i] = (int16_t)(i * 1000);
    int16_t held[8];
    for (int i = 0; i < 8; i++) {
        assert(voices[0].block_pos == i / 2);
        audio_cb(NULL, (Uint8 *)out, sizeof out);
        held[i] = out[0];
    }
    for (int i = 0; i < 8; i += 2) assert(held[i] == held[i+1]);
    printf("pitch0800 sample hold:");
    for (int i = 0; i < 8; i++) printf(" %d", held[i]);
    puts("");

    /* First block ends with decoded112. The next, self-looping filter1
     * block starts at105, retaining predictor history instead of zeroing it. */
    configure_voice(0x1800);
    SPU_RAM[0] = 8;
    memset(SPU_RAM+2, 0x77, 14);
    SPU_RAM[16] = 0x1c; SPU_RAM[17] = 7;
    decode_block(&voices[0]);
    assert(voices[0].prev1 == 112);
    for (int i = 0; i < 19; i++) audio_cb(NULL, (Uint8 *)out, sizeof out);
    assert(voices[0].block[0] == 105);
    assert(voices[0].block_pos == 0 && voices[0].frac == 0x8000);
    int prior = voices[0].prev1;
    for (int i = 0; i < 19; i++) audio_cb(NULL, (Uint8 *)out, sizeof out);
    assert(voices[0].block[0] == (prior * 60 >> 6));
    assert(voices[0].block_pos == 1 && voices[0].frac == 0);
    assert(voices[0].repeat == 16 && (endx & 1));
    puts("pitch1800 block/loop boundaries: phase and predictor history preserved");

    /* Isolate the low-bit predictor difference from pitch/envelope/output.
     * PSX-SPX's documented ADPCM formula adds32 before division by64. */
    Voice v = {0};
    memset(SPU_RAM, 0, 16); SPU_RAM[0] = 0x1c;
    v.prev1 = 1;
    decode_block(&v);
    printf("filter1, zero nibble, previous1: decoder=%d; documented rounded predictor=1\n",
           v.block[0]);
    puts("No device opened. This probe establishes arithmetic/state, not audible causation.");
    return 0;
}
