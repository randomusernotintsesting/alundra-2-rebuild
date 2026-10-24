#include "xa_audio.h"
#include <string.h>
size_t xa_decode_sector(XaDecoder *d, const uint8_t *raw, size_t bytes,
                       int16_t *pcm, size_t capacity, unsigned *rate) {
    if (!d || !raw || !pcm || !rate || bytes != 2352 || raw[15] != 2 ||
        (raw[18] & 0x44) != 0x44 || memcmp(raw + 16, raw + 20, 4)) return 0;
    return xa_decode_groups(d, raw + 24, 2304, raw[19], pcm, capacity, rate);
}
size_t xa_decode_groups(XaDecoder *d, const uint8_t *groups, size_t bytes,
                       unsigned coding, int16_t *pcm, size_t capacity, unsigned *rate) {
    if (!d || !groups || !pcm || !rate || bytes != 2304 || coding > 255) return 0;
    if ((coding & 0x03) > 1 || (coding & 0x0c) > 4 ||
        (coding & 0x30) > 0x10 || (coding & 0x80)) return 0;
    unsigned channels = (coding & 1) ? 2 : 1;
    unsigned bits = (coding & 0x10) ? 8 : 4;
    unsigned units = 32 / bits;
    size_t frames = 18 * units * 28 / channels;
    if (capacity < frames) return 0;
    static const int pos[4] = {0,60,115,98}, neg[4] = {0,0,-52,-55};
    for (unsigned g = 0; g < 18; g++) {
        const uint8_t *p = groups + g * 128;
        for (unsigned u = 0; u < units; u++) {
            unsigned ch = u % channels;
            unsigned header = p[4 + u];
            unsigned shift = header & 15, filter = (header >> 4) & 3;
            if (shift > 12) shift = 9;
            for (unsigned i = 0; i < 28; i++) {
                unsigned packed = p[16 + i*4 + (bits == 4 ? u/2 : u)];
                int sample;
                if (bits == 4) {
                    sample = (packed >> ((u & 1)*4)) & 15;
                    if (sample >= 8) sample -= 16;
                    sample *= 4096;
                } else sample = (int8_t)packed * 256;
                sample >>= shift;
                sample += (d->prev[ch][0]*pos[filter] + d->prev[ch][1]*neg[filter] + 32) >> 6;
                if (sample > 32767) sample = 32767;
                if (sample < -32768) sample = -32768;
                d->prev[ch][1] = d->prev[ch][0];
                d->prev[ch][0] = sample;
                size_t frame = g*(units/channels)*28 + (u/channels)*28 + i;
                pcm[frame*2 + ch] = (int16_t)sample;
                if (channels == 1) pcm[frame*2 + 1] = (int16_t)sample;
            }
        }
    }
    *rate = (coding & 4) ? 18900 : 37800;
    return frames;
}
