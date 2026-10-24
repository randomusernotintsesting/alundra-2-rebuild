/* Settings layer: a2settings.ini + F1 overlay menu.
 *
 * The overlay is drawn straight onto the SDL renderer after the game
 * frame (present() calls settings_draw), with an embedded 8x8 font —
 * no game code involved, so it works in every scene including boot.
 * While the menu is open the game receives an idle pad.
 *
 * Runtime-applied: window size/fullscreen, internal
 * resolution, texture filter, sound, key bindings. Env vars (
 * A2_IRSCALE, A2_FILTER, A2_SOUND) still override the ini at startup —
 * they remain the debugging interface. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "settings.h"
#include "paths.h"
#include "font8x8.h"
#ifdef A2_CINEMA_EXPANSION
#include "cinema_gpu.h"
#endif

A2Settings a2s;
int settings_menu_open;

static SDL_Window *s_win;
static SDL_Renderer *s_ren;

/* plumbing into the other modules */
void gpu_set_ir(int n);            /* gpu.c */
int gpu_ir(void);
extern int gpu_frames;
void gpu_set_filter(int on);       /* gpu.c */
void a2_wide_set(int on);          /* dispatch.c */
void spu_set_sound(int on);        /* spu.c */
void spu_set_master_volume(int percent);
void platform_reset_fb(void);      /* main.c: drop framebuf+texture */

/* ---------------- pad bits / labels ---------------- */
typedef struct { int bit; const char *name; } PadBtn;
static const PadBtn PAD[] = {
    {4,  "Up"}, {6,  "Down"}, {7,  "Left"}, {5,  "Right"},
    {14, "Cross"}, {13, "Circle"}, {15, "Square"}, {12, "Triangle"},
    {3,  "Start"}, {0,  "Select"},
    {10, "L1"}, {11, "R1"}, {8, "L2"}, {9, "R2"},
};
#define NPAD ((int)(sizeof PAD / sizeof PAD[0]))

static const int DEFKEY[16] = {
    /* bit: 0 select */ SDL_SCANCODE_RSHIFT, 0, 0,
    /* 3 start   */ SDL_SCANCODE_RETURN,
    /* 4 up      */ SDL_SCANCODE_UP,
    /* 5 right   */ SDL_SCANCODE_RIGHT,
    /* 6 down    */ SDL_SCANCODE_DOWN,
    /* 7 left    */ SDL_SCANCODE_LEFT,
    /* 8 L2, 9 R2, 10 L1, 11 R1 */
    SDL_SCANCODE_1, SDL_SCANCODE_2, SDL_SCANCODE_Q, SDL_SCANCODE_W,
    /* 12 triangle */ SDL_SCANCODE_S,
    /* 13 circle   */ SDL_SCANCODE_X,
    /* 14 cross    */ SDL_SCANCODE_Z,
    /* 15 square   */ SDL_SCANCODE_A,
};

/* ---------------- ini ---------------- */
void settings_default_keys(int out[16]) { memcpy(out,DEFKEY,sizeof DEFKEY); }
static const char *ini_path(void) {
    return a2_paths.settings;
}

void settings_load(void) {
    a2s.window_w = 0; a2s.window_h = 0;
    a2s.fullscreen = 1;
    a2s.wide = 1;                  /* the remake look: 16:9 + 3x */
    a2s.irscale = 3;
    a2s.filter = 0;
#ifdef __APPLE__
    a2s.antialias = 1;
#else
    a2s.antialias = 0;
#endif
    a2s.sound = 1;
    a2s.master_volume = 100;
    a2s.text_language = 0;
    a2s.voice_language = 1;
    a2s.hd_portraits = 1;
    a2s.hd_models = 0; /* Modern model experiments are parked. */
    a2s.pad_deadzone = 16000;
    a2s.cinema = 1;
    a2s.fill_screen = 1; a2s.subtitles = 0; a2s.skip_intro = 0;
    a2s.english_subtitle_language = 0;
    a2_input_default_pad(a2s.pad);
    memcpy(a2s.key, DEFKEY, sizeof DEFKEY);

    FILE *f = fopen(ini_path(), "r");
    if (!f && a2_paths.legacy_settings[0])
        f = fopen(a2_paths.legacy_settings, "r");
    if (f) {
        char line[256], k[64]; int v;
        while (fgets(line, sizeof line, f)) {
            if (sscanf(line, " %63[^= \n]=%d", k, &v) != 2) continue;
            if (!strcmp(k, "window_w")) a2s.window_w = v;
            else if (!strcmp(k, "window_h")) a2s.window_h = v;
            else if (!strcmp(k, "fullscreen")) a2s.fullscreen = v;
            else if (!strcmp(k, "irscale")) a2s.irscale = v;
            else if (!strcmp(k, "filter")) a2s.filter = v;
            else if (!strcmp(k, "antialias")) a2s.antialias = v;
            else if (!strcmp(k, "sound")) a2s.sound = v;
            else if (!strcmp(k, "master_volume")) a2s.master_volume = v;
            else if (!strcmp(k, "text_language")) a2s.text_language = v;
            else if (!strcmp(k, "voice_language")) a2s.voice_language = v;
            else if (!strcmp(k, "hd_portraits")) a2s.hd_portraits = v;
            /* Ignore retired preview model preferences; original is default. */
            else if (!strcmp(k, "pad_deadzone")) a2s.pad_deadzone = v;
            else if (!strcmp(k, "cinema")) a2s.cinema = v;
            else if (!strcmp(k, "fill_screen")) a2s.fill_screen = v;
            else if (!strcmp(k, "subtitles")) a2s.subtitles = v;
            else if (!strcmp(k, "english_subtitle_language")) a2s.english_subtitle_language = v;
            else if (!strcmp(k, "skip_intro")) a2s.skip_intro = v;
            else if (!strncmp(k, "pad_", 4)) {
                int bit,slot,end=0;char field[16];
                if(sscanf(k,"pad_%d_%d_%15s%n",&bit,&slot,field,&end)==3 && !k[end] &&
                   a2_input_pad_bit_valid(bit) && slot>=0 && slot<2) {
                    if(!strcmp(field,"kind"))a2s.pad[bit][slot].kind=v;
                    else if(!strcmp(field,"code"))a2s.pad[bit][slot].code=v;
                }
            }
            else if (!strncmp(k, "key_", 4)) {
                int bit,end=0;
                if (sscanf(k,"key_%d%n",&bit,&end)==1 && !k[end] &&
                    bit >= 0 && bit < 16 && v >= 0 && v < SDL_NUM_SCANCODES)
                    a2s.key[bit] = v;
            }
        }
        fclose(f);
    }
    /* env still wins (debug interface) */
    if (getenv("A2_IRSCALE")) a2s.irscale = atoi(getenv("A2_IRSCALE"));
    if (getenv("A2_FILTER")) a2s.filter = atoi(getenv("A2_FILTER")) != 0;
    if (getenv("A2_ANTIALIAS")) a2s.antialias = atoi(getenv("A2_ANTIALIAS")) != 0;
    if (getenv("A2_SOUND")) a2s.sound = atoi(getenv("A2_SOUND")) != 0;
    if (getenv("A2_HD_PORTRAITS")) a2s.hd_portraits = atoi(getenv("A2_HD_PORTRAITS")) != 0;
    const char *models = getenv("A2_NATIVE_MESH");
    if (models && (!strcmp(models,"0") || !strcmp(models,"1"))) a2s.hd_models = models[0]=='1';
    if (getenv("A2_VOLUME")) a2s.master_volume = atoi(getenv("A2_VOLUME"));
    if (getenv("A2_TEXT_LANGUAGE")) a2s.text_language = atoi(getenv("A2_TEXT_LANGUAGE"));
    if (getenv("A2_VOICE_LANGUAGE")) a2s.voice_language = atoi(getenv("A2_VOICE_LANGUAGE"));
    if (a2s.text_language < 0 || a2s.text_language > 2) a2s.text_language = 0;
    if (a2s.voice_language < 0 || a2s.voice_language > 1) a2s.voice_language = 1;
    if (a2s.master_volume < 0) a2s.master_volume = 0;
    if (a2s.master_volume > 100) a2s.master_volume = 100;
    a2s.hd_portraits = !!a2s.hd_portraits;
    a2s.hd_models = !!a2s.hd_models;
    a2s.wide = 1; /* Old wide=0 profiles and A2_WIDE=0 cannot alter presentation. */
    a2s.sound = !!a2s.sound;
    a2s.fullscreen = !!a2s.fullscreen;
    a2s.filter = !!a2s.filter;
    a2s.antialias = !!a2s.antialias;
#ifndef __APPLE__
    a2s.antialias = 0; /* Metal backend currently available on macOS. */
#endif
    a2s.cinema = !!a2s.cinema;
    a2s.fill_screen = !!a2s.fill_screen; a2s.skip_intro = !!a2s.skip_intro;
    if(a2s.subtitles<0||a2s.subtitles>2)a2s.subtitles=0;
    if(a2s.english_subtitle_language<0||a2s.english_subtitle_language>2)a2s.english_subtitle_language=0;
    if(a2s.pad_deadzone<2048)a2s.pad_deadzone=2048;
    if(a2s.pad_deadzone>30000)a2s.pad_deadzone=30000;
    for(int bit=0;bit<16;bit++)for(int slot=0;slot<2;slot++)
        if(!a2_input_pad_bit_valid(bit) || !a2_input_binding_valid(a2s.pad[bit][slot]))
            a2s.pad[bit][slot]=(A2PadBinding){0,0};
    if (a2s.window_w < 320 || a2s.window_w > 16384 ||
        a2s.window_h < 240 || a2s.window_h > 16384)
        a2s.window_w = a2s.window_h = 0;
    if (a2s.irscale < 1) a2s.irscale = 1;
    if (a2s.irscale > 4) a2s.irscale = 4;
    if (getenv("A2_MENU")) settings_menu_open = 1;   /* debug: open at boot */
    FILE *probe = fopen(ini_path(), "r");
    if (probe) fclose(probe);
    else settings_save();          /* materialize defaults on first run */
}

void settings_save(void) {
    char tmp[4096];
    if (snprintf(tmp, sizeof tmp, "%s.tmp.XXXXXX", ini_path()) >= (int)sizeof tmp) return;
    /* Each process owns its temporary inode until the atomic replacement. */
    int fd = mkstemp(tmp);
    if (fd < 0) { fprintf(stderr, "Cannot save settings: %s\n", ini_path()); return; }
    FILE *f = fdopen(fd, "w");
    if (!f) {
        close(fd);
        remove(tmp);
        fprintf(stderr, "Cannot save settings: %s\n", ini_path());
        return;
    }
    fprintf(f, "window_w=%d\nwindow_h=%d\nfullscreen=%d\n"
            "wide=%d\nirscale=%d\nfilter=%d\nsound=%d\n",
            a2s.window_w, a2s.window_h, a2s.fullscreen,
            a2s.wide, a2s.irscale, a2s.filter, a2s.sound);
    fprintf(f, "master_volume=%d\ntext_language=%d\nvoice_language=%d\nhd_portraits=%d\n",
            a2s.master_volume, a2s.text_language, a2s.voice_language, a2s.hd_portraits);
    fprintf(f,"antialias=%d\n",a2s.antialias);
    fprintf(f,"fill_screen=%d\nsubtitles=%d\nskip_intro=%d\n",a2s.fill_screen,a2s.subtitles,a2s.skip_intro);
    fprintf(f,"english_subtitle_language=%d\n",a2s.english_subtitle_language);
    for (int i = 0; i < 16; i++)
        fprintf(f, "key_%d=%d\n", i, a2s.key[i]);
    fprintf(f,"input_version=1\npad_deadzone=%d\ncinema=%d\n",
            a2s.pad_deadzone,a2s.cinema);
    for(int bit=0;bit<16;bit++)for(int slot=0;slot<2;slot++)
        fprintf(f,"pad_%d_%d_kind=%d\npad_%d_%d_code=%d\n",
            bit,slot,a2s.pad[bit][slot].kind,bit,slot,a2s.pad[bit][slot].code);
    int failed = ferror(f);
    if (fclose(f)) failed = 1;
    if (!failed && rename(tmp, ini_path()) == 0) return;
    fprintf(stderr, "Cannot save settings: %s\n", ini_path());
    remove(tmp);
}

/* ---------------- runtime apply ---------------- */
void settings_apply_window(SDL_Window *win, SDL_Renderer *ren) {
    s_win = win; s_ren = ren;
    if (a2s.fullscreen)
        SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN_DESKTOP);
    else {
        SDL_SetWindowFullscreen(win, 0);
        if (a2s.window_w && a2s.window_h)
            SDL_SetWindowSize(win, a2s.window_w, a2s.window_h);
    }
    SDL_RenderSetLogicalSize(ren, 960, 540);
    a2_input_init();
    a2_input_configure(a2s.key,a2s.pad,a2s.pad_deadzone);
    a2_input_poll();
}

void settings_controller_event(void) {
    a2_input_poll();
}

int settings_ir_restart_pending(void) {
    const char *hd = getenv("A2_HDUI");
    return gpu_frames > 0 && (!hd || strcmp(hd, "0")) &&
           ((gpu_ir() == 1) != (a2s.irscale == 1));
}

void settings_apply_startup(void) {
#ifdef A2_CINEMA_EXPANSION
    gpu_set_cinema_expansion(a2s.cinema);
#endif
    SDL_setenv("A2_HD_PORTRAITS", a2s.hd_portraits ? "1" : "0", 1);
    SDL_setenv("A2_NATIVE_MESH", a2s.hd_models ? "1" : "0", 1);
    spu_set_master_volume(a2s.master_volume);
    a2_input_configure(a2s.key,a2s.pad,a2s.pad_deadzone);
}

void settings_apply_changes(void) {
    settings_apply_startup();
    a2s.wide = 1;
    a2_wide_set(a2s.wide);
    /* Existing guest text nodes retain their measured advances. Crossing
     * native/HD font modes mid-scene would mix layouts; keep the requested
     * value persisted for startup, without reparsing/revealing guest text. */
    if (!settings_ir_restart_pending()) gpu_set_ir(a2s.irscale);
    gpu_set_filter(a2s.filter);
    spu_set_sound(a2s.sound);
    platform_reset_fb();
    if (s_win) settings_apply_window(s_win, s_ren);
    settings_save();
}

/* ---------------- pad from bindings ---------------- */
Uint16 settings_pad_buttons(void) {
    return settings_menu_open?0xffff:a2_input_pad_buttons();
}

Uint16 settings_controller_buttons(void) {
    return a2_input_controller_buttons();
}

/* ---------------- overlay model ---------------- */
enum { IT_WINDOW, IT_IR, IT_FILTER, IT_SOUND, IT_KEYS_START };
static int sel;                        /* selected row */
static int rebinding = -1;             /* pad-bit waiting for a key */

static const struct { int w, h; const char *label; } WINSZ[] = {
    {0, 0, "keep"}, {960, 720, "960x720"}, {1280, 720, "1280x720"},
    {1280, 960, "1280x960"}, {1440, 1080, "1440x1080"},
    {1920, 1080, "1920x1080"}, {-1, -1, "FULLSCREEN"},
};
#define NWINSZ ((int)(sizeof WINSZ / sizeof WINSZ[0]))
static int winsz_cur(void) {
    if (a2s.fullscreen) return NWINSZ - 1;
    for (int i = 0; i < NWINSZ - 1; i++)
        if (WINSZ[i].w == a2s.window_w && WINSZ[i].h == a2s.window_h)
            return i;
    return 0;
}

#define NROWS (IT_KEYS_START + NPAD)

static void row_change(int row, int dir) {
    switch (row) {
    case IT_WINDOW: {
        int i = (winsz_cur() + dir + NWINSZ) % NWINSZ;
        a2s.fullscreen = (WINSZ[i].w == -1);
        if (!a2s.fullscreen) { a2s.window_w = WINSZ[i].w; a2s.window_h = WINSZ[i].h; }
        break;
    }
    case IT_IR:
        a2s.irscale += dir;
        if (a2s.irscale < 1) a2s.irscale = 4;
        if (a2s.irscale > 4) a2s.irscale = 1;
        break;
    case IT_FILTER: a2s.filter = !a2s.filter; break;
    case IT_SOUND: a2s.sound = !a2s.sound; break;
    default:
        rebinding = PAD[row - IT_KEYS_START].bit;
        return;
    }
    settings_apply_changes();
}

void settings_toggle_menu(void) {
    settings_menu_open = !settings_menu_open;
    rebinding = -1;
    if (!settings_menu_open) settings_save();
}

int settings_handle_key(SDL_Scancode sc) {
#ifdef A2_NATIVE_MENU
    extern void platform_show_game_menu(void);
    if (sc == SDL_SCANCODE_F1 || sc == SDL_SCANCODE_ESCAPE) {
        platform_show_game_menu();
        return 1;
    }
#endif
    if (sc == SDL_SCANCODE_F1) { settings_toggle_menu(); return 1; }
    if (!settings_menu_open) return 0;
    if (rebinding >= 0) {
        if (!a2_input_key_reserved(sc)) {
            for (int i = 0; i < 16; i++)      /* steal from old owner */
                if (a2s.key[i] == (int)sc) a2s.key[i] = 0;
            a2s.key[rebinding] = sc;
            a2_input_configure(a2s.key,a2s.pad,a2s.pad_deadzone);
            settings_save();
        }
        rebinding = -1;
        return 1;
    }
    switch (sc) {
    case SDL_SCANCODE_ESCAPE: settings_toggle_menu(); break;
    case SDL_SCANCODE_UP:    sel = (sel + NROWS - 1) % NROWS; break;
    case SDL_SCANCODE_DOWN:  sel = (sel + 1) % NROWS; break;
    case SDL_SCANCODE_LEFT:  row_change(sel, -1); break;
    case SDL_SCANCODE_RIGHT: row_change(sel, +1); break;
    case SDL_SCANCODE_RETURN:
    case SDL_SCANCODE_SPACE: row_change(sel, +1); break;
    default: break;
    }
    return 1;
}

/* ---------------- overlay draw ---------------- */
static void draw_text(SDL_Renderer *r, int x, int y, const char *s,
                      Uint8 cr, Uint8 cg, Uint8 cb) {
    SDL_SetRenderDrawColor(r, cr, cg, cb, 255);
    for (; *s; s++, x += 8) {
        unsigned c = (unsigned char)*s;
        if (c < 32 || c > 127) c = '?';
        const unsigned char *g = font8x8[c - 32];
        for (int gy = 0; gy < 8; gy++)
            for (int gx = 0; gx < 8; gx++)
                if (g[gy] & (1 << gx)) {
                    SDL_Rect px = {x + gx, y + gy, 1, 1};
                    SDL_RenderFillRect(r, &px);
                }
    }
}

void settings_draw(SDL_Renderer *ren) {
    if (!settings_menu_open) return;
    int lw, lh;
    SDL_RenderGetLogicalSize(ren, &lw, &lh);
    if (!lw) { lw = 960; lh = 540; }
    SDL_Rect bg = {lw / 2 - 190, 40, 380, 44 + NROWS * 14 + 30};
    SDL_SetRenderDrawBlendMode(ren, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(ren, 12, 12, 24, 228);
    SDL_RenderFillRect(ren, &bg);
    SDL_SetRenderDrawColor(ren, 200, 170, 60, 255);
    SDL_RenderDrawRect(ren, &bg);

    int x = bg.x + 14, y = bg.y + 10;
    draw_text(ren, x, y, "ALUNDRA 2 - SETTINGS  (F1/ESC close)", 240, 210, 120);
    y += 22;
    char line[96];
    for (int row = 0; row < NROWS; row++) {
        const char *val = "";
        char kv[48];
        const char *name;
        if (row == IT_WINDOW) { name = "Window"; val = WINSZ[winsz_cur()].label; }
        else if (row == IT_IR) {
            static const char *IRL[] = {"", "1x (320x216)", "2x (640x432)",
                                        "3x (960x648)", "4x (1280x864)"};
            name = "Internal res"; val = IRL[a2s.irscale];
        }
        else if (row == IT_FILTER) { name = "Texture filter"; val = a2s.filter ? "ON" : "OFF"; }
        else if (row == IT_SOUND) { name = "Sound"; val = a2s.sound ? "ON" : "OFF"; }
        else {
            const PadBtn *p = &PAD[row - IT_KEYS_START];
            name = p->name;
            if (rebinding == p->bit) val = "<press key>";
            else {
                snprintf(kv, sizeof kv, "%s",
                         a2s.key[p->bit]
                         ? SDL_GetScancodeName((SDL_Scancode)a2s.key[p->bit])
                         : "-");
                val = kv;
            }
        }
        snprintf(line, sizeof line, "%c %-16s %s",
                 row == sel ? '>' : ' ', name, val);
        if (row == IT_KEYS_START) {
            draw_text(ren, x, y, "-- Controls (Enter = rebind) --", 150, 150, 170);
            y += 14;
        }
        draw_text(ren, x, y, line,
                  row == sel ? 255 : 190, row == sel ? 230 : 190,
                  row == sel ? 140 : 200);
        y += 14;
    }
    y += 4;
    if (settings_ir_restart_pending()) {
        snprintf(line, sizeof line, "Restart to apply IR %dx (active %dx).",
                 a2s.irscale, gpu_ir());
        draw_text(ren, x, y, line, 255, 210, 100);
    } else {
        draw_text(ren, x, y, "Arrows: navigate/change. Saved automatically.",
                  140, 140, 160);
    }
}
