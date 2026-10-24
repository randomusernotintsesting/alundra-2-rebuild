#ifndef A2_INPUT_PROMPTS_H
#define A2_INPUT_PROMPTS_H
#include <stddef.h>
#include <stdint.h>
#include "input.h"
#include "cinema.h"

enum { A2_PROMPT_CONFIRM, A2_PROMPT_CANCEL, A2_PROMPT_RESET, A2_PROMPT_CONTROLLER };
typedef struct {
    char label[64];
    A2InputPrompt bindings[4];
    unsigned binding_count;
} A2PromptItem;
typedef struct {
    int kind,x,y,width,height;
    unsigned count;
    A2PromptItem items[10];
} A2PromptPanel;
typedef struct { unsigned count; A2PromptPanel panels[3]; } A2PromptFrame;

/* All calls are on the game thread. RAM and VRAM remain read-only. */
void a2_input_prompts_init(const uint8_t *ram,size_t ram_size);
void a2_input_prompts_close(void);
void a2_input_prompts_configure(int language);
/* Exact candidate sprites only. Dirty rectangles invalidate source proofs
 * and already-presented destination panels; unchanged displays may repeat. */
void a2_input_prompts_vram_changed(int x,int y,int width,int height);
void a2_input_prompts_sprite(const uint16_t *vram,uint32_t tpage,uint32_t clut,
                             int x,int y,int width,int height,int u,int v);
/* Read only the KeyConfig preview assignment after exact menu recognition.
 * Physical bit order matches input.h; missing/duplicate actions return -1. */
int a2_input_prompts_preview_bit(unsigned action);
void a2_input_prompts_frame(const A2CinemaRaster *raster,int hidden,A2PromptFrame *out);
#define A2_INPUT_PROMPTS_VISITOR 1
typedef struct {
    const uint32_t *pixels; /* contiguous premultiplied ARGB8888 */
    int x,y,width,height;  /* fine-raster coordinates; caller clips */
    uint64_t generation;  /* nonzero; changes whenever pixels are regenerated */
} A2PromptPixels;
typedef void (*A2PromptVisitor)(const A2PromptPixels *,void *);
/* Consume during the callback, in presentation order. Pixel storage is owned
 * by the prompt cache and can change on a later prompt call or close. A null
 * visitor still retires invalid observations but does not rasterize panels. */
void a2_input_prompts_visit(int scale,const A2CinemaRaster *raster,int hidden,
                           A2PromptVisitor visitor,void *context);
/* Call once after frame composition, before native captures and upload. */
void a2_input_prompts_compose(uint32_t *dst,int pitch,int scale,
                              const A2CinemaRaster *raster,int hidden);
#ifdef A2_INPUT_PROMPTS_TEST
unsigned a2_input_prompts_test_raster_count(void);
#endif
#endif
