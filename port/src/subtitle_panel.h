#ifndef A2_SUBTITLE_PANEL_H
#define A2_SUBTITLE_PANEL_H
#include "input_prompts.h"
/* Two prewrapped UTF-8 lines at most. bottom is an exclusive logical row.
 * Returns a cached premultiplied panel, or NULL for hidden/invalid captions.
 * Called on the game thread; no guest state or full-frame GPU reads. */
const A2PromptPixels *a2_subtitle_panel_set(const char *text,int scale,int width,int height,int bottom);
const A2PromptPixels *a2_subtitle_panel_get(void);
void a2_subtitle_panel_compose(uint32_t *pixels,int pitch,int width,int height);
void a2_subtitle_panel_close(void);
#endif
