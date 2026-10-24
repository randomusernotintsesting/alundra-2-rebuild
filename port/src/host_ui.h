#ifndef A2_HOST_UI_H
#define A2_HOST_UI_H
#include <stddef.h>
#include <stdint.h>
#include <SDL.h>
enum { A2_MENU_RESUME=0, A2_MENU_SAVE=1, A2_MENU_LOAD=2, A2_MENU_QUIT=3,
       A2_MENU_SAVE_SLOT=4, A2_MENU_LOAD_SLOT=5 };
/* Borrow the paused game's window, renderer and last composed texture.
 * Refresh before each modal; the view never destroys these objects. */
void a2_host_ui_set_context(SDL_Window *window, SDL_Renderer *renderer,
                            SDL_Texture *last_frame, int width, int height);
/* Main-thread modal view; caller suspends guest/audio and gates held input.
 * Save read failure/cancel preserves payload; cancel clears error. */
int a2_host_game_menu(int startup, int can_save, int can_load);
int a2_host_save_browser(const char *userdir, int saving, uint8_t payload[8192],
                         char *error, size_t size);
void a2_host_save_error(const char *message);
#endif
