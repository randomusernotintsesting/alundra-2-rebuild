#ifndef A2_MENU_SDL_H
#define A2_MENU_SDL_H
#include <SDL.h>
#include "host_ui.h"
#include <stdint.h>
#include <stddef.h>
/* Main thread. The renderer/window/frame are borrowed through modal return.
 * frame source is [0,0,width,height]; logo path is copied immediately. */
void a2_menu_sdl_set_context(SDL_Window *,SDL_Renderer *,SDL_Texture *last_frame,int width,int height,const char *logo_path);
int a2_menu_sdl_game(int startup,int can_save,int can_load);
/* Nested settings view; return resumes the caller's menu, not the guest. */
int a2_menu_sdl_settings(int startup,int can_save,int can_load);
int a2_menu_sdl_save_browser(const char *userdir,int saving,uint8_t payload[8192],char *error,size_t size);
void a2_menu_sdl_error(const char *message);
#endif
