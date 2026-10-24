#include "xa_audio.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    uint8_t raw[2352] = {0};
    int16_t pcm[4032 * 2];
    XaDecoder d = {0};
    unsigned rate = 0;
    raw[15] = 2; raw[18] = raw[22] = 0x64;
    raw[19] = raw[23] = 1; /* 4-bit stereo, 37800 Hz */
    for (int g = 0; g < 18; g++) {
        uint8_t *p = raw + 24 + g * 128;
        memset(p, 12, 16);
        for (int i = 16; i < 128; i++) p[i] = 0xe3;
    }
    assert(xa_decode_sector(&d, raw, sizeof raw, pcm, 4032, &rate) == 2016);
    assert(rate == 37800);
    for (int i = 0; i < 2016; i++) assert(pcm[2*i] == 3 && pcm[2*i+1] == -2);
    /* Unit headers 4..11, not 0..7: unit 4 has a different scale. */
    raw[24 + 8] = 11;
    assert(xa_decode_sector(&d, raw, sizeof raw, pcm, 4032, &rate) == 2016);
    assert(pcm[56*2] == 6);
    raw[24 + 8] = 12;
    raw[19] = raw[23] = 4; /* mono, 18900 */
    assert(xa_decode_sector(&d, raw, sizeof raw, pcm, 4032, &rate) == 4032);
    assert(rate == 18900 && pcm[0] == 3 && pcm[1] == 3 && pcm[56] == -2);
    raw[19] = raw[23] = 0x11; /* 8-bit stereo */
    for (int g = 0; g < 18; g++) memset(raw + 24 + g*128, 8, 16);
    assert(xa_decode_sector(&d, raw, sizeof raw, pcm, 4032, &rate) == 1008);
    assert(pcm[0] == -29 && pcm[1] == -29);
    XaDecoder saved = d;
    assert(!xa_decode_sector(&d, raw, 2351, pcm, 4032, &rate));
    assert(!xa_decode_sector(&d, raw, 2352, pcm, 10, &rate));
    assert(memcmp(&saved, &d, sizeof d) == 0);
    raw[19] = raw[23] = 1;
    memset(raw + 24, 0, 128);
    raw[28] = raw[29] = 0x1c;
    d = (XaDecoder){{{64,0},{-64,0}}};
    assert(xa_decode_sector(&d, raw, sizeof raw, pcm, 4032, &rate) == 2016);
    assert(pcm[0] == 60 && pcm[1] == -60 && pcm[2] == 56);
    raw[19] = raw[23] = 0x22; /* reserved channel/bit depth */
    assert(!xa_decode_sector(&d, raw, sizeof raw, pcm, 4032, &rate));
    if (argc > 1) {
        FILE *disc = fopen(argv[1], "rb"); assert(disc);
        unsigned sectors = 0, audio = 0, nonzero = 0;
        XaDecoder streams[256] = {0};
        while (fread(raw, 1, sizeof raw, disc) == sizeof raw) {
            sectors++;
            if (raw[15] != 2 || (raw[18] & 0x44) != 0x44) continue;
            size_t n = xa_decode_sector(&streams[raw[17]], raw, sizeof raw, pcm, 4032, &rate);
            assert(n != 0);
            audio++;
            for (size_t i = 0; i < n*2; i++) if (pcm[i]) { nonzero++; break; }
        }
        assert(!ferror(disc)); fclose(disc);
        assert(audio && nonzero);
        printf("real disc: %u sectors, %u XA sectors, %u nonzero decoded sectors\n", sectors, audio, nonzero);
    }
    puts("XA decode vectors passed");
}
