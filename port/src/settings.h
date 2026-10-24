/* Settings layer: persistent config (a2settings.ini in the user data directory)
 * + in-game overlay menu (F1).  См. settings.c. */
#ifndef A2_SETTINGS_H
#define A2_SETTINGS_H
#include <SDL.h>
#include "input.h"

typedef struct {
    int window_w, window_h;        /* 0,0 = keep current */
    int fullscreen;
    int wide;                      /* fixed1; legacy ini/API compatibility */
    int irscale;                   /* internal resolution 1..4 */
    int filter;                    /* bilinear texture filter */
    int antialias;                 /* Metal spatial edge AA; presentation only */
    int sound;
    int master_volume;             /* host output gain, 0..100 */
    int text_language;             /* 0 Russian, 1 Japanese, 2 English */
    int voice_language;            /* 0 Japanese, 1 English */
    int hd_models;                 /* developer diagnostic only; never persisted */
    int hd_portraits;              /* standard original or existing HD artwork */
    /* SDL scancodes for the PS1 pad, order matches pad bit numbers:
     * 0 select, 3 start, 4 up, 5 right, 6 down, 7 left,
     * 12 triangle, 13 circle, 14 cross, 15 square */
    int key[16];
    A2PadBinding pad[16][2];        /* primary and alternate controller sources */
    int pad_deadzone;              /* stick/trigger activation threshold, 2048..30000 */
    int fill_screen;               /* fill gameplay output; adapt 3D aspect */
    int subtitles;                 /* 0 automatic, 1 on, 2 off (EVENT only) */
    int english_subtitle_language; /* English voice captions: 0 follow text, 1 Russian, 2 English */
    int skip_intro;                /* automatically skip initial logos/movies */
    int cinema;                    /* native cinematic framing */
} A2Settings;

extern A2Settings a2s;

void settings_load(void);          /* defaults -> ini -> env overrides */
void settings_save(void);
void settings_apply_changes(void); /* apply current values and persist atomically */
void settings_apply_startup(void); /* output/portrait settings before first frame */
void settings_apply_window(SDL_Window *win, SDL_Renderer *ren);
void settings_controller_event(void);
void settings_default_keys(int out[16]);

/* overlay */
extern int settings_menu_open;
void settings_toggle_menu(void);
int settings_handle_key(SDL_Scancode sc);   /* 1 = consumed */
void settings_draw(SDL_Renderer *ren);
int settings_ir_restart_pending(void); /* desired IR crosses live HD font mode */

/* pad state from bindings (+ game controller), active-low bits */
Uint16 settings_pad_buttons(void);
/* Configured controller only, for native modal UI (no duplicate keyboard input). */
Uint16 settings_controller_buttons(void);

#endif
