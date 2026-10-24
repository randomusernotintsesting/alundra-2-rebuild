#ifndef A2_STARTUP_QOL_H
#define A2_STARTUP_QOL_H
#include <stdint.h>
void a2_startup_reset(int automatic);
void a2_startup_logo_begin(void);
void a2_startup_movies_begin(void);
void a2_startup_request(void);
int a2_startup_skip_requested(void);
void a2_startup_logo_fade(uint32_t *phase,uint32_t *brightness);
uint16_t a2_startup_pad(unsigned frame,int overlay,uint16_t buttons,int held);
#endif
