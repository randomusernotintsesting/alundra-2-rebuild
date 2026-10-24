#ifndef A2_XA_AUDIO_H
#define A2_XA_AUDIO_H
#include <stddef.h>
#include <stdint.h>
typedef struct { int32_t prev[2][2]; } XaDecoder;
/* Native assets contain exactly eighteen 128-byte sound groups plus coding
 * metadata. This is the original ADPCM, without CD transport headers. */
size_t xa_decode_groups(XaDecoder *decoder, const uint8_t *groups, size_t bytes,
                       unsigned coding, int16_t *pcm, size_t capacity, unsigned *rate);
/* Decode a raw 2352-byte Mode 2 XA sector to interleaved stereo PCM.
 * Returns frames, or zero for malformed input / insufficient capacity.
 * Maximum output is 4032 frames. History belongs to one file/channel. */
size_t xa_decode_sector(XaDecoder *decoder, const uint8_t *raw, size_t bytes,
                       int16_t *pcm, size_t capacity, unsigned *rate);
#endif
