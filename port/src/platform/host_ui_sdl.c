/* SDL view adapter. Guest suspension and release gating stay in main.c.
 * Platform text rasterization is selected separately by the build. */
#include "host_ui.h"
#include "menu_sdl.h"
#include <stdio.h>

void a2_host_ui_set_context(SDL_Window *window, SDL_Renderer *renderer,
                            SDL_Texture *last_frame, int width, int height) {
    char logo[4096] = {0};
    char *base = SDL_GetBasePath();
    static const char *candidates[] = {
        "../Resources/branding/alundra-2-rebuild.png",
        "../../assets/branding/alundra-2-rebuild.png",
        "../assets/branding/alundra-2-rebuild.png",
        "branding/alundra-2-rebuild.png"
    };
    for (unsigned i=0; base && i<sizeof candidates/sizeof candidates[0]; i++) {
        int length=snprintf(logo,sizeof logo,"%s%s",base,candidates[i]);
        if (length<0 || length>=(int)sizeof logo) { logo[0]=0; continue; }
        SDL_RWops *file=SDL_RWFromFile(logo,"rb");
        if (file) { SDL_RWclose(file); break; }
        logo[0]=0;
    }
    SDL_free(base);
    a2_menu_sdl_set_context(window,renderer,last_frame,width,height,logo);
}

int a2_host_game_menu(int startup, int can_save, int can_load) {
    return a2_menu_sdl_game(startup, can_save, can_load);
}
int a2_host_save_browser(const char *userdir, int saving, uint8_t payload[8192],
                         char *error, size_t size) {
    return a2_menu_sdl_save_browser(userdir, saving, payload, error, size);
}
void a2_host_save_error(const char *message) { a2_menu_sdl_error(message); }
