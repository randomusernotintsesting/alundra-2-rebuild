#ifndef A2_GAME_LOCALE_H
#define A2_GAME_LOCALE_H
#include <stdint.h>
/* Active profiles, fixed before starting the guest: text RU=0/JA=1/EN=2, voice JA=0/EN=1. */
extern int a2_game_text_language;
extern int a2_game_voice_language;
/* Recognize complete shipped defaults only; return the active spelling without
 * changing stored bytes. Other custom names return zero. */
unsigned a2_locale_default_name(const uint8_t stored[12], uint16_t output[6]);
#endif
