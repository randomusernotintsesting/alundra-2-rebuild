#ifndef A2_RENDER_CAPTURE_H
#define A2_RENDER_CAPTURE_H
#include <SDL.h>
/* Capture already-issued drawing from the window before Present. Returns an
 * owned ARGB8888 surface at physical output size, or NULL + SDL_GetError().
 * Host contract: window target, automatic viewport, no custom scale/clip;
 * logical size may be positive or disabled. Logical/integer presentation is
 * preserved, with a fresh automatic viewport for the current output size.
 * Queued drawing is flushed BEFORE normalization: this can safely record a
 * malformed frame without silently correcting its pixels. Never calls a raw
 * ReadPixels(NULL), whose implicit viewport may exceed the output buffer. */
SDL_Surface *a2_render_capture_window(SDL_Renderer *renderer);
#endif
