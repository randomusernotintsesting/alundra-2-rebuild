#include "render_capture.h"
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

/* Restore the host's automatic presentation, never a derived physical scale
 * or a cached viewport: both would apply the logical scaling a second time. */
static int restore_presentation(SDL_Renderer *renderer, int width, int height,
                                SDL_bool integer_scale) {
    int failed = 0;
    if (SDL_RenderSetIntegerScale(renderer, integer_scale) < 0) failed = 1;
    if (SDL_RenderSetLogicalSize(renderer, width, height) < 0) failed = 1;
    if (SDL_RenderSetViewport(renderer, NULL) < 0) failed = 1;
    if (SDL_RenderSetClipRect(renderer, NULL) < 0) failed = 1;
    return failed ? -1 : 0;
}

SDL_Surface *a2_render_capture_window(SDL_Renderer *renderer) {
    int logical_width, logical_height, width, height, final_width, final_height;
    char error[512] = "";
    if (!renderer) {
        SDL_SetError("Window capture requires a renderer");
        return NULL;
    }
    if (SDL_GetRenderTarget(renderer)) {
        SDL_SetError("Window capture does not accept a texture render target");
        return NULL;
    }
    SDL_RenderGetLogicalSize(renderer, &logical_width, &logical_height);
    SDL_bool integer_scale = SDL_RenderGetIntegerScale(renderer);

    /* Do not move this below normalization: queued drawing must retain the
     * exact state under which it was issued, including a malformed viewport. */
    if (SDL_RenderFlush(renderer) < 0) return NULL;
    if (SDL_GetRendererOutputSize(renderer, &width, &height) < 0) return NULL;
    if (width <= 0 || height <= 0 || width > INT_MAX / 4 ||
        (size_t)height > SIZE_MAX / ((size_t)width * 4)) {
        SDL_SetError("Window capture output dimensions are invalid");
        return NULL;
    }
    SDL_Surface *surface = SDL_CreateRGBSurfaceWithFormat(
        0, width, height, 32, SDL_PIXELFORMAT_ARGB8888);
    if (!surface) return NULL;
    SDL_FillRect(surface, NULL, 0);

    if (SDL_RenderSetLogicalSize(renderer, 0, 0) < 0 ||
        SDL_RenderSetScale(renderer, 1.0f, 1.0f) < 0 ||
        SDL_RenderSetViewport(renderer, NULL) < 0 ||
        SDL_RenderSetClipRect(renderer, NULL) < 0) {
        snprintf(error, sizeof(error), "%s", SDL_GetError());
    } else {
        /* SDL2-compat forwards this rectangle to SDL3. A NULL rectangle can
         * select an oversized stale viewport and overflow the caller buffer. */
        SDL_Rect bounds = {0, 0, width, height};
        if (SDL_RenderReadPixels(renderer, &bounds, SDL_PIXELFORMAT_ARGB8888,
                                 surface->pixels, surface->pitch) < 0 ||
            SDL_GetRendererOutputSize(renderer, &final_width, &final_height) < 0) {
            snprintf(error, sizeof(error), "%s", SDL_GetError());
        } else if (width != final_width || height != final_height) {
            snprintf(error, sizeof(error), "Window output changed during capture");
        }
    }
    if (restore_presentation(renderer, logical_width, logical_height,
                             integer_scale) < 0 && !error[0]) {
        snprintf(error, sizeof(error), "Could not restore window presentation: %s",
                 SDL_GetError());
    }
    if (error[0]) {
        SDL_FreeSurface(surface);
        SDL_SetError("%s", error);
        return NULL;
    }
    return surface;
}
