#ifndef A2_VOICE_ASSETS_H
#define A2_VOICE_ASSETS_H
#include <stddef.h>
#include <stdint.h>
/* Voice language is an explicit startup option. Changes require restart. */
int a2_voice_available(const char *pack_path);
/* 0=Japanese (all183 clips required), 1=English. Never infer from a path. */
int a2_voice_available_for_language(const char *pack_path, int language);
int a2_voice_open_for_language(const char *pack_path, const char *image_path,
    uint8_t *ram, size_t ram_size, int language);
int a2_voice_open(const char *pack_path, const char *image_path, uint8_t *ram, size_t ram_size);
const char *a2_voice_error(void);
void a2_voice_close(void);
/* CD integration: read returns 0 outside overlay, 1 audio, 2 silent padding.
 * Padding advances physical time but produces neither decoded PCM nor CPU data. */
void a2_voice_begin(uint32_t target_lba, uint8_t file, uint8_t channel);
void a2_voice_stop(const char *reason);
int a2_voice_read_sector(uint32_t lba, uint8_t raw[2352]);
void a2_voice_observe(uint32_t lba, size_t frames);
void a2_voice_event(const char *reason);
#endif
