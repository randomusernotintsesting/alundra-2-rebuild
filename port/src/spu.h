#ifndef A2_SPU_H
#define A2_SPU_H
#include <stddef.h>
#include <stdint.h>
/* All SPU entrypoints run on the emulation thread. */
void spu_init_audio(void);
void spu_set_sound(int on);
void spu_set_master_volume(int percent);
void spu_vblank(void);
void spu_write(uint32_t off, uint16_t value);
uint16_t spu_read(uint32_t off);
void spu_dma_write(const uint8_t *src, uint32_t bytes);
void spu_push_cd_audio(const int16_t *pcm, size_t frames, unsigned rate);
void spu_reset_cd_audio(void);
void spu_set_cd_mix(uint8_t ll, uint8_t lr, uint8_t rl, uint8_t rr, int muted);
#endif
