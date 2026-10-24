#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "settings.h"
#include "paths.h"
#ifdef _WIN32
#include "platform/storage_windows.h"
#include <direct.h>
static FILE *utf8_fopen(const char *path,const char *mode) {
    wchar_t *p=a2w_utf16(path),*m=a2w_utf16(mode);
    FILE *f=p&&m?_wfopen(p,m):NULL;free(p);free(m);return f;
}
static int utf8_rename(const char *from,const char *to) {
    wchar_t *a=a2w_utf16(from),*b=a2w_utf16(to);
    int r=a&&b?_wrename(a,b):-1;free(a);free(b);return r;
}
static int utf8_unlink(const char *path) {wchar_t *p=a2w_utf16(path);int r=p?_wunlink(p):-1;free(p);return r;}
static int utf8_mkdir(const char *path,int mode) {(void)mode;wchar_t *p=a2w_utf16(path);int r=p?_wmkdir(p):-1;free(p);return r;}
static int utf8_rmdir(const char *path) {wchar_t *p=a2w_utf16(path);int r=p?_wrmdir(p):-1;free(p);return r;}
#define fopen utf8_fopen
#define rename utf8_rename
#define unlink utf8_unlink
#define mkdir utf8_mkdir
#define rmdir utf8_rmdir
#define SDL_setenv a2w_setenv
#define unsetenv(name) a2w_setenv(name,NULL,1)
#endif

int gpu_frames;
static int actual_ir=3;
int gpu_ir(void) { return actual_ir; }
void gpu_set_ir(int n) { actual_ir=n; }
void gpu_set_filter(int n) { (void)n; }
void a2_wide_set(int n) { (void)n; }
void spu_set_sound(int n) { (void)n; }
void spu_set_master_volume(int n) { (void)n; }
void platform_reset_fb(void) {}
static int native_menu_calls;
void platform_show_game_menu(void) { native_menu_calls++; }

static void expect_no_saved_models(void) {
    FILE *f=fopen(a2_paths.settings,"r");assert(f);
    char line[256];
    while(fgets(line,sizeof line,f))assert(strncmp(line,"hd_models=",10));
    assert(!fclose(f));
}

static int saved_english_subtitle_language(void) {
    FILE *f=fopen(a2_paths.settings,"r");assert(f);
    char line[256];int value=-1;
    while(fgets(line,sizeof line,f))
        if(sscanf(line,"english_subtitle_language=%d",&value)==1)break;
    assert(!fclose(f));return value;
}

static void change_ir(int delta) {
#ifdef A2_NATIVE_MENU
    a2s.irscale += delta;
    settings_apply_changes();
#else
    settings_handle_key(delta < 0 ? SDL_SCANCODE_LEFT : SDL_SCANCODE_RIGHT);
#endif
}

int main(void) {
#ifdef _WIN32
    _set_error_mode(_OUT_TO_STDERR);
#endif
    SDL_SetMainReady();
    assert(SDL_getenv("A2_USER_DIR")); /* runner owns the temporary directory */
    (void)a2_paths_init(NULL, NULL);
    assert(a2_paths.settings[0]);
    /* The presentation is always16:9, including old environment/profile
     * overrides. The independent sound override still accepts false. */
    SDL_setenv("A2_WIDE", "0", 1);
    SDL_setenv("A2_SOUND", "0", 1);
    settings_load();
    assert(saved_english_subtitle_language()==0); /* New profiles follow text. */
    const int subtitle_preferences[]={0,1,2,-1,3,99};
    for(unsigned i=0;i<sizeof subtitle_preferences/sizeof subtitle_preferences[0];i++) {
        int value=subtitle_preferences[i];
        FILE *subtitle_config=fopen(a2_paths.settings,"a");assert(subtitle_config);
        fprintf(subtitle_config,"english_subtitle_language=%d\n",value);
        assert(!fclose(subtitle_config));
        int text=a2s.text_language,voice=a2s.voice_language;
        settings_load();settings_save();
        assert(saved_english_subtitle_language()==(value>=0&&value<=2?value:0));
        assert(a2s.text_language==text&&a2s.voice_language==voice);
    }
#ifdef __APPLE__
    assert(a2s.antialias==1);
    a2s.antialias=0;settings_save();settings_load();assert(!a2s.antialias);
    SDL_setenv("A2_ANTIALIAS","1",1);settings_load();assert(a2s.antialias);
    SDL_setenv("A2_ANTIALIAS","0",1);settings_load();assert(!a2s.antialias);
    unsetenv("A2_ANTIALIAS");a2s.antialias=1;settings_save();settings_load();assert(a2s.antialias);
#endif
    assert(a2s.fill_screen==1 && a2s.subtitles==0 && a2s.skip_intro==0);
    a2s.fill_screen=0;a2s.subtitles=2;a2s.skip_intro=1;settings_save();settings_load();
    assert(!a2s.fill_screen && a2s.subtitles==2 && a2s.skip_intro);
    a2s.fill_screen=1;a2s.subtitles=0;a2s.skip_intro=0;settings_save();
    expect_no_saved_models();
    assert(a2s.hd_models==0);
    /* Experimental preferences from preview builds cannot enable replacements. */
    FILE *legacy_models=fopen(a2_paths.settings,"a");assert(legacy_models);
    fputs("hd_models=1\n",legacy_models);assert(!fclose(legacy_models));
    settings_load();assert(a2s.hd_models==0);
    settings_save();expect_no_saved_models();
    /* Keep the explicit developer diagnostic, without persisting it. */
    SDL_setenv("A2_NATIVE_MESH","1",1);settings_load();assert(a2s.hd_models==1);
    settings_save();expect_no_saved_models();
    SDL_setenv("A2_NATIVE_MESH","0",1);settings_load();assert(a2s.hd_models==0);
    SDL_setenv("A2_NATIVE_MESH","invalid",1);settings_load();assert(a2s.hd_models==0);
    unsetenv("A2_NATIVE_MESH");settings_load();assert(a2s.hd_models==0);
    settings_apply_startup();assert(!strcmp(SDL_getenv("A2_NATIVE_MESH"),"0"));
    a2s.hd_models=1;settings_apply_changes();
    assert(!strcmp(SDL_getenv("A2_NATIVE_MESH"),"1"));expect_no_saved_models();
    unsetenv("A2_NATIVE_MESH");unsetenv("A2_HD_PORTRAITS");settings_load();assert(a2s.hd_models==0);
    assert(a2s.pad_deadzone==16000 && a2s.cinema==1);
    assert(a2s.pad[14][0].kind==A2_BIND_BUTTON && a2s.pad[14][0].code==SDL_CONTROLLER_BUTTON_A);
    assert(a2s.pad[4][1].kind==A2_BIND_AXIS_NEG && a2s.pad[4][1].code==SDL_CONTROLLER_AXIS_LEFTY);
    if (!a2s.wide || a2s.sound) {
        fprintf(stderr, "FAIL: fixed16:9 must ignore A2_WIDE=0, sound must respect A2_SOUND=0\n");
        return 1;
    }
    SDL_setenv("A2_WIDE", "1", 1);
    SDL_setenv("A2_SOUND", "1", 1);
    settings_load();
    assert(a2s.wide == 1 && a2s.sound == 1);
    SDL_setenv("A2_IRSCALE", "9999", 1);
    settings_load();
    assert(a2s.irscale == 4);
    SDL_setenv("A2_IRSCALE", "-20", 1);
    settings_load();
    assert(a2s.irscale == 1);
    for (int bit = 8; bit <= 11; bit++) {
        if (!a2s.key[bit]) {
            fprintf(stderr, "FAIL: PS1 shoulder button %d has no keyboard binding\n", bit);
            return 1;
        }
    }
    /* Losing independently chosen voice or portrait mode on restart is a regression. */
    a2s.text_language = 2;
    a2s.voice_language = 0;
    a2s.hd_portraits = 0;
    a2s.master_volume = 37;
    settings_save();
    a2s.text_language = a2s.voice_language = a2s.hd_portraits = a2s.master_volume = -1;
    settings_load();
    assert(a2s.text_language == 2 && a2s.voice_language == 0);
    assert(a2s.hd_portraits == 0 && a2s.master_volume == 37);
    a2s.pad_deadzone=22000;a2s.cinema=0;
    assert(a2_input_bind_pad(a2s.pad,13,1,a2s.pad[14][0]));
    settings_save();settings_load();
    assert(a2s.pad_deadzone==22000 && !a2s.cinema);
    assert(!a2s.pad[14][0].kind && a2s.pad[13][1].code==SDL_CONTROLLER_BUTTON_A);
    FILE *invalid = fopen(a2_paths.settings, "a");
    assert(invalid);
    fputs("text_language=90\nvoice_language=-1\nmaster_volume=900\nhd_portraits=-5\n"
          "pad_deadzone=999999\ncinema=1\nshow_input_hints=1\nwide=0\n"
          "pad_13_1_kind=1\npad_13_1_code=9999\nkey_not_a_bit=3\n", invalid);
    assert(fclose(invalid) == 0);
    settings_load();
    assert(a2s.text_language == 0 && a2s.voice_language == 1);
    assert(a2s.master_volume == 100 && a2s.hd_portraits == 1);
    assert(a2s.pad_deadzone==30000 && a2s.cinema);
    assert(a2s.wide==1); /* old saved4:3 mode migrates to16:9 */
    assert(a2s.pad[13][1].kind==A2_BIND_NONE);
    assert(a2s.key[0]==SDL_SCANCODE_RSHIFT); /* malformed suffix cannot rewrite Select */
    /* Older private profiles may contain the removed gameplay-hints option.
     * It must load harmlessly and disappear from the next settings write. */
    settings_save();
    FILE *migrated=fopen(a2_paths.settings,"r");assert(migrated);
    char migrated_line[256];
    while(fgets(migrated_line,sizeof migrated_line,migrated)) {
        assert(strncmp(migrated_line,"show_input_hints=",17));
        assert(strcmp(migrated_line,"wide=0\n"));
    }
    assert(fclose(migrated)==0);
    a2s.key[14] = 0;
    a2s.key[13] = SDL_SCANCODE_Z;
    settings_save();
    settings_load();
    if (a2s.key[14] || a2s.key[13] != SDL_SCANCODE_Z) {
        fputs("FAIL: a stolen/disabled binding reappeared after reload\n", stderr);
        return 1;
    }
    /* A second writer may already own the old fixed temporary pathname.
     * Saving must neither truncate that file nor rename it into the ini. */
    char temporary[sizeof a2_paths.settings + 16];
    assert(snprintf(temporary, sizeof temporary, "%s.tmp", a2_paths.settings) > 0);
    FILE *sentinel = fopen(temporary, "w");
    assert(sentinel);
    assert(fputs("another writer owns this file\n", sentinel) >= 0);
    assert(fclose(sentinel) == 0);
    a2s.key[12] = SDL_SCANCODE_D;
    settings_save();
    sentinel = fopen(temporary, "r");
    if (!sentinel) {
        fputs("FAIL: settings_save removed another writer's temporary file\n", stderr);
        return 1;
    }
    char contents[64];
    assert(fgets(contents, sizeof contents, sentinel));
    assert(!strcmp(contents, "another writer owns this file\n"));
    assert(fgetc(sentinel) == EOF && fclose(sentinel) == 0);
    settings_load();
    assert(a2s.key[12] == SDL_SCANCODE_D);
    assert(unlink(temporary) == 0);

    /* A failed rename must remove this save's private temporary file.
     * The runner checks for leftovers in its isolated user directory. */
    char backup[sizeof a2_paths.settings + 16];
    assert(snprintf(backup, sizeof backup, "%s.backup", a2_paths.settings) > 0);
    assert(rename(a2_paths.settings, backup) == 0);
    assert(mkdir(a2_paths.settings, 0700) == 0);
    a2s.key[12] = SDL_SCANCODE_E;
    settings_save();
    assert(rmdir(a2_paths.settings) == 0);
    assert(rename(backup, a2_paths.settings) == 0);
    settings_load();
    assert(a2s.key[12] == SDL_SCANCODE_D);
    /* Native menu keys must be consumed exactly once; ordinary game input
     * must keep reaching the game. The SDL fallback still owns its rows. */
    SDL_setenv("A2_HDUI", "1", 1);
    assert(settings_handle_key(SDL_SCANCODE_F1) == 1);
#ifdef A2_NATIVE_MENU
    assert(native_menu_calls == 1 && !settings_menu_open);
    assert(settings_handle_key(SDL_SCANCODE_ESCAPE) == 1);
    assert(native_menu_calls == 2 && !settings_menu_open);
    assert(settings_handle_key(SDL_SCANCODE_Z) == 0);
    assert(native_menu_calls == 2);
#else
    assert(native_menu_calls == 0 && settings_menu_open);
    settings_handle_key(SDL_SCANCODE_DOWN); /* internal resolution */
#endif
    a2s.irscale=2;actual_ir=3;gpu_frames=100;
    change_ir(-1); /* request1, keep live3 */
    assert(a2s.irscale==1 && actual_ir==3);
    assert(settings_ir_restart_pending());
    FILE *pending=fopen(a2_paths.settings,"r");assert(pending);
    int persisted=0;char saved_line[128];
    while(fgets(saved_line,sizeof saved_line,pending))
        if(!strcmp(saved_line,"irscale=1\n"))persisted=1;
    assert(fclose(pending)==0 && persisted);
    change_ir(1); /* request2, live switch permitted */
    assert(a2s.irscale==2 && actual_ir==2);
    assert(!settings_ir_restart_pending());
    change_ir(1);
    assert(a2s.irscale==3 && actual_ir==3);
    a2s.irscale=1;actual_ir=1;
    change_ir(1); /* request2 from live1, defer */
    assert(a2s.irscale==2 && actual_ir==1);
    assert(settings_ir_restart_pending());
    change_ir(-1); /* cancel pending change */
    assert(a2s.irscale==1 && actual_ir==1 && !settings_ir_restart_pending());
    unsetenv("A2_HDUI"); /* default enabled has identical protection */
    change_ir(1);
    assert(a2s.irscale==2 && actual_ir==1 && settings_ir_restart_pending());
    gpu_frames=0;
    change_ir(1); /* startup must honor3 */
    assert(a2s.irscale==3 && actual_ir==3);
    assert(!settings_ir_restart_pending());
    gpu_frames=100;SDL_setenv("A2_HDUI", "0", 1);
    a2s.irscale=2;
    change_ir(-1);
    assert(a2s.irscale==1 && actual_ir==1);
    assert(!settings_ir_restart_pending());
    change_ir(1);
    assert(a2s.irscale==2 && actual_ir==2);
 #ifndef A2_NATIVE_MENU
    settings_handle_key(SDL_SCANCODE_DOWN); /* filter */
    settings_handle_key(SDL_SCANCODE_DOWN); /* sound */
    settings_handle_key(SDL_SCANCODE_DOWN); /* Up binding */
    settings_handle_key(SDL_SCANCODE_RETURN);
    settings_handle_key(SDL_SCANCODE_E);
    A2InputPrompt prompt[2];assert(a2_input_prompts_for_bit(4,prompt)==1);
    assert(!strcmp(prompt[0].label,"E")); /* fallback rebind must affect cached runtime immediately */
 #endif
    puts("settings: overrides, bindings, atomic saves and HD IR transition policy passed");
    return 0;
}
