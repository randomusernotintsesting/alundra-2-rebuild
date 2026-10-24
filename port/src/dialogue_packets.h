#ifndef A2_DIALOGUE_PACKETS_H
#define A2_DIALOGUE_PACKETS_H
#include <stddef.h>
#include <stdint.h>

/* Source-proven dialogue rectangles are ordered 2D. No layout/anchor change. */
void a2_dialogue_packets_init(const uint8_t *ram,size_t bytes);
void a2_dialogue_packets_reset(void);
void a2_dialogue_packets_close(void);
void a2_dialogue_packets_before(uint32_t pc,const uint32_t *r);
uint64_t a2_dialogue_packets_token(uint32_t address,uint32_t command);
int a2_dialogue_packets_consume(uint32_t address,uint64_t token,
                               const uint32_t *words,unsigned count);
extern uint32_t a2_dialogue_packets_watch_begin,a2_dialogue_packets_watch_end;
void a2_dialogue_packets_invalidate(uint32_t address,size_t bytes);
#endif
