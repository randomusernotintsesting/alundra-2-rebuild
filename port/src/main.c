/* Alundra 2 native port runner.
 *
 * Modes:
 *   alundra2 [--boot]                       run from the native archive
 *   alundra2 <disc_root> --boot image.bin    legacy transport diagnostics
 *   alundra2 <disc_root> --atlas [--screenshot f.bmp]  atlas diagnostics
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include "psx_rt.h"
#include "cd_hle.h"
#include "settings.h"
#include "startup_qol.h"
#include "hd_ui.h"
#include "paths.h"
#include "spu.h"
#include "memcard.h"
#include "replay_control.h"
#include "frame_compose.h"
#include "input.h"
#ifdef A2_INPUT_PROMPTS
#include "input_prompts.h"
#ifdef A2_VOICE_SUBTITLES
#include "voice_subtitles.h"
#include "subtitle_panel.h"
#endif
#endif
#ifdef A2_HUD_PRESENT
#include "hud_present.h"
#endif
#include "phase_timing.h"
#include "frame_wait.h"
#include "frame_pacer.h"
#include "game_profiles.h"
#include "game_locale.h"
#ifdef A2_HD_FONTS
#include "hd_art.h"
#endif
#ifdef A2_NATIVE_RESOURCES
#include "native_resources_guest.h"
#include "native_voice.h"
#endif
#ifdef A2_NATIVE_MENU
#include "host_ui.h"
#endif
#include "render_capture.h"
#ifdef __APPLE__
#include "antialias.h"
#include "gpu_present.h"
static A2Antialias *presentation_aa;
static void presentation_aa_close(void) {
    a2_antialias_destroy(presentation_aa);presentation_aa=NULL;
}
static void presentation_antialias(uint32_t *pixels,int width,int height,int stride) {
    static int failed,registered;
    if(!a2s.antialias)return;
    if(failed){a2s.antialias=0;return;}
    char error[1024];
    if(!registered){atexit(presentation_aa_close);registered=1;}
    if(!presentation_aa)presentation_aa=a2_antialias_create(error,sizeof error);
    if(!presentation_aa||!a2_antialias_apply(presentation_aa,pixels,width,height,stride,error,sizeof error)) {
        fprintf(stderr,"antialias: disabled after failure: %s\n",error);
        presentation_aa_close();failed=1;a2s.antialias=0;
    }
}
#endif
#ifdef A2_VOICE_ASSETS
#include "voice_assets.h"
#endif
#ifdef A2_NATIVE_SAVES
#include "native_save_guest.h"
#include "native_save_store.h"
#include "host_ui.h"
#endif
#ifdef A2_WORLD_PRECISION
#include "world_precision.h"
#endif
#ifdef A2_NATIVE_ACTOR_SNAPSHOT
#include "native_actor_snapshot.h"
#endif
#ifdef A2_NATIVE_MESH
#include "native_mesh_live.h"
#include "native_billboard.h"
#include "dialogue_packets.h"
static A2Resources *mesh_resource_store;
static int mesh_runtime_initialized,mesh_runtime_available;
static int mesh_runtime_selection=-1,mesh_runtime_source_visibility;
static void mesh_runtime_close(void) {
    if(!mesh_runtime_initialized)return;
    a2_native_billboard_configure(0);a2_dialogue_packets_close();
    a2_mesh_live_close();a2_resources_close(mesh_resource_store);mesh_resource_store=NULL;
    mesh_runtime_initialized=mesh_runtime_available=0;mesh_runtime_selection=-1;
}
/* Settings update the diagnostic environment before platform_reset_fb. Keep
 * source/packet observers and loaded resources alive across either selection. */
static void mesh_runtime_sync(void) {
    if(!mesh_runtime_initialized)return;
    const char *on=getenv("A2_NATIVE_MESH");
    int requested=on?(!strcmp(on,"1")):!!a2s.hd_models;
    int enabled=mesh_runtime_available&&requested;
    if(requested&&!mesh_runtime_available)
        fprintf(stderr,"nativemesh-mode: original (updated model resource unavailable)\n");
    a2s.hd_models=enabled;
    SDL_setenv("A2_NATIVE_MESH",enabled?"1":"0",1);
    /* enabled also covers an older front page retained through a switch;
     * compare requests, not that page-lifetime flag. */
    if(mesh_runtime_selection!=enabled){
        a2_world_shadow_configure(enabled||mesh_runtime_source_visibility);
        a2_mesh_live_set_enabled(enabled);mesh_runtime_selection=enabled;
        fprintf(stderr,"nativemesh-mode: %s\n",enabled?"updated":"original");
    }
}
static void mesh_runtime_init(void) {
    if(mesh_runtime_initialized)return;
    mesh_runtime_initialized=1;atexit(mesh_runtime_close);
    A2Resources *store=a2_profile_resources();
    const char *path=getenv("A2_MODEL_ARCHIVE");
    if(path&&*path) {
        char error[256];
        if(!a2_resources_open(path,&mesh_resource_store,error,sizeof error))
            fprintf(stderr,"nativemesh: %s\n",error);
        store=mesh_resource_store;
    }
    /* Normal archives can legitimately contain no updated models. Probe
     * once rather than attempting a failing load on each frame or toggle. */
    if(a2s.hd_models&&store&&(a2_resource_find(store,a2s.text_language,"MODELS/T02.A2M")||
               a2_resource_find(store,a2s.text_language,"MODELS/PC00.A2M")))
        mesh_runtime_available=a2_mesh_live_open(store,a2s.text_language);
#ifdef A2_NATIVE_ACTOR_SNAPSHOT
    const char *capture=getenv("A2_ACTOR_CAPTURE");
    const char *depth_option=getenv("A2_MODEL_DEPTH");
    int source_visibility=depth_option && !strcmp(depth_option,"1");
    void gpu_model_depth_configure(int enabled);
    gpu_model_depth_configure(source_visibility);mesh_runtime_source_visibility=source_visibility;
    a2_native_actor_snapshot_configure(mesh_runtime_available||source_visibility||(capture&&*capture));
#else
    int source_visibility=0;
#endif
    a2_native_actor_sources_init(PSX_RAM,sizeof PSX_RAM);
    a2_native_actor_packets_init(PSX_RAM,sizeof PSX_RAM);
    a2_native_actor_sources_configure(mesh_runtime_available||source_visibility);
    a2_native_actor_packets_configure(mesh_runtime_available||source_visibility);
    a2_native_billboard_init(PSX_RAM,sizeof PSX_RAM);
    a2_native_billboard_configure(mesh_runtime_available);
    a2_dialogue_packets_init(mesh_runtime_available?PSX_RAM:NULL,mesh_runtime_available?sizeof PSX_RAM:0);
    mesh_runtime_sync();
}
static void mesh_runtime_check(SDL_Window *window) {
    if(!a2_mesh_live_failed)return;
    extern uint32_t psx_frame_no;
    const char *message=a2s.text_language==1?
        "実験的なモデルの描画に失敗しました。診断オーバーライドなしで再起動してください。":
        a2s.text_language==2?
        "Experimental model rendering failed. Restart without the diagnostic override.":
        "Не удалось отрисовать экспериментальные модели. Перезапустите игру без диагностического переключателя.";
    fprintf(stderr,"nativemesh-fatal: frame=%u %s\n",psx_frame_no,message);
    const char *driver=SDL_GetCurrentVideoDriver();
    if(driver&&strcmp(driver,"dummy"))
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Alundra 2: Rebuild",message,window);
    exit(1);
}
#endif

extern uint16_t GPU_VRAM[512 * 1024];
void gpu_get_display(int *x, int *y, int *w, int *h, int *on);
int gpu_ir(void);
void gpu_set_ir(int n);
void gpu_set_filter(int on);
#ifdef A2_WORLD_PRECISION
void gpu_set_world_raster(int on);
#endif
void a2_wide_set(int on);
int cd_open_image(const char *path);
void cd_boot_handoff(void);
void psx_irq_set(int bit);
void psx_irq_dispatch(void);
void psx_pad_update(void);
void psx_deliver_event(uint32_t cls, uint32_t spec);
extern int kernel_log, cd_log, mmio_log;

static SDL_Window *win;
static int active_text_language,active_voice_language;
static SDL_Renderer *ren;
static SDL_Texture *tex;
static uint32_t *framebuf;             /* 1024*S x 512*S, S = gpu_ir() */
static int fb_w, fb_h;
static int composed_width, composed_height;
#ifdef __APPLE__
static A2GpuPresent *presentation_gpu;
static int gpu_frame_ready,gpu_frame_materialized,gpu_present_failed;
static void presentation_gpu_close(void) {
    a2_gpu_present_destroy(presentation_gpu);presentation_gpu=NULL;gpu_frame_ready=0;
}
static void presentation_materialize(void) {
    if(!gpu_frame_ready||gpu_frame_materialized)return;
    char error[1024];
    if(!a2_gpu_present_readback(presentation_gpu,framebuf,fb_w,error,sizeof error)) {
        fprintf(stderr,"gpu-present: explicit frame readback failed: %s\n",error);exit(2);
    }
    gpu_frame_materialized=1;
}
static void presentation_host_context(void) {
    if(!presentation_gpu)return;
    char error[1024];presentation_materialize();
    if(!a2_gpu_present_suspend(presentation_gpu,error,sizeof error)) {
        fprintf(stderr,"gpu-present: SDL handover failed: %s\n",error);exit(2);
    }
    if(gpu_frame_ready&&tex) {
        SDL_Rect src={0,0,composed_width,composed_height};
        SDL_UpdateTexture(tex,&src,framebuf,fb_w*4);
    }
}
typedef struct {int ok;char error[1024];} GpuPanelContext;
#ifdef A2_INPUT_PROMPTS
static void presentation_panel(const A2PromptPixels *panel,void *opaque) {
    GpuPanelContext *context=opaque;
    if(context->ok)context->ok=a2_gpu_present_panel(presentation_gpu,panel,context->error,sizeof context->error);
}
#endif
static int presentation_gpu_requested(void) {
    static int requested=-1;
    if(requested<0) {const char *value=getenv("A2_GPU_PRESENT");requested=value&&!strcmp(value,"1");}
    return requested&&!gpu_present_failed&&!settings_menu_open;
}
static int presentation_frame_view_enabled(void) {
    static int enabled=-1;
    if(enabled<0){const char *value=getenv("A2_FRAME_VIEW");enabled=!value||strcmp(value,"0");}
    return enabled&&presentation_gpu_requested();
}
static int presentation_gpu_prepare(int scale,const A2CinemaRaster *raster,
                                    const uint32_t *pixels,int stride) {
    static int registered;
    gpu_frame_ready=gpu_frame_materialized=0;
    if(!presentation_gpu_requested())return 0;
    char error[1024]={0};
    /* SDL owns the layer. Drain its queued commands before using our queue;
     * this also covers returning from native host menus/settings. */
    if(SDL_RenderFlush(ren))snprintf(error,sizeof error,"SDL flush: %s",SDL_GetError());
    else if(!presentation_gpu) {
        void *layer=SDL_RenderGetMetalLayer(ren);
        if(layer)presentation_gpu=a2_gpu_present_create(layer,error,sizeof error);
        else snprintf(error,sizeof error,"SDL renderer has no Metal layer: %s",SDL_GetError());
        if(presentation_gpu&&!registered){atexit(presentation_gpu_close);registered=1;}
    }
    if(!error[0]&&presentation_gpu&&a2_gpu_present_prepare(presentation_gpu,pixels,
            composed_width,composed_height,stride,a2s.antialias,error,sizeof error)) {
        GpuPanelContext context={.ok=1};
#ifdef A2_INPUT_PROMPTS
        a2_input_prompts_visit(scale,raster,0,presentation_panel,&context);
#endif
#ifdef A2_VOICE_SUBTITLES
        const A2PromptPixels *subtitle=a2_subtitle_panel_get();
        if(subtitle)presentation_panel(subtitle,&context);
#endif
        if(context.ok){gpu_frame_ready=1;return 1;}
        snprintf(error,sizeof error,"%s",context.error);
    }
    fprintf(stderr,"gpu-present: falling back to SDL: %s\n",error);
    gpu_present_failed=1;presentation_gpu_close();return 0;
}
#else
static void presentation_materialize(void) {}
static void presentation_host_context(void) {}
#endif
static uint64_t next_frame_ticks;
static uint64_t last_present_ticks;
static uint32_t frames;
uint32_t psx_frame_no;
static ReplayControl replay_control;
static int replay_control_enabled;
static int show_startup_menu;
static int select_saved_profile;
#ifdef A2_NATIVE_ACTOR_SNAPSHOT
static FILE *actor_capture_output;
static uint64_t actor_capture_clock(void) {
    uint64_t ticks=SDL_GetPerformanceCounter(), frequency=SDL_GetPerformanceFrequency();
    if(!frequency) return 0;
    return (ticks/frequency)*1000000000ull +
        (uint64_t)((long double)(ticks%frequency)*1000000000.0L/frequency);
}
static void actor_capture_close(void) {
    if(!actor_capture_output) return;
    A2ActorSnapshotStats stats;
    a2_native_actor_snapshot_stats(&stats);
    int failed=a2_native_actor_snapshot_output_error();
    a2_native_actor_snapshot_set_output(NULL);
    if(fclose(actor_capture_output)) failed=1;
    actor_capture_output=NULL;
    fprintf(stderr,"actorcapture: published=%llu rejected=%llu output_error=%d\n",
        (unsigned long long)stats.published,(unsigned long long)stats.rejected,failed);
}
static int actor_capture_init(void) {
    const char *path=getenv("A2_ACTOR_CAPTURE");
    a2_native_actor_snapshot_init(PSX_RAM,sizeof PSX_RAM);
    int enabled=path&&*path;
#ifdef A2_NATIVE_MESH
    /* Resource availability is resolved immediately afterward. Start enabled
     * so Original -> Updated never requires a later registry reload. */
    enabled=1;
#endif
    a2_native_actor_snapshot_configure(enabled);
    if(!path || !*path) return 1;
    actor_capture_output=fopen(path,"wbx");
    if(!actor_capture_output) {
        fprintf(stderr,"actorcapture: cannot create a new output file: %s\n",path);
        return 0;
    }
    a2_native_actor_snapshot_set_clock(actor_capture_clock);
    a2_native_actor_snapshot_set_output(actor_capture_output);
    atexit(actor_capture_close);
    return 1;
}
#endif
#ifdef A2_NATIVE_SAVES
static int native_input_release;

uint16_t platform_native_menu_buttons(void) {
    a2_input_sync_controller_events();
    return a2_input_menu_buttons();
}

static void native_dialog_end(void) {
    SDL_PumpEvents();
    SDL_FlushEvents(SDL_KEYDOWN, SDL_KEYUP);
    a2_input_set_menu_active(0);
    native_input_release = 1;
    SDL_RaiseWindow(win);
    spu_set_sound(a2s.sound);
    next_frame_ticks = 0;
    last_present_ticks = 0;
}

int platform_native_save_dialog(int saving, uint8_t *payload, char *error, size_t size) {
    a2_input_set_menu_active(1);
    spu_set_sound(0);
    presentation_host_context();
    a2_host_ui_set_context(win,ren,tex,composed_width,composed_height);
    int result=0;
    const char *test_name=getenv(saving ? "A2_TEST_NATIVE_SAVE" : "A2_TEST_NATIVE_LOAD");
    const char *cancel=getenv("A2_TEST_NATIVE_CANCEL");
    int quick=a2_native_quick_action_active();
    if (quick) { test_name="quick.a2save"; cancel=NULL; }
    if (quick || ((test_name || cancel) && getenv("A2_USER_DIR"))) {
        /* Diagnostics select at the real operation boundary, never fake a load
         * result or automate the old card browser. Paths stay within the profile. */
        char directory[4096], path[4096];
        if (snprintf(directory,sizeof directory,"%s/Saves",a2_paths.user)>=(int)sizeof directory)
            snprintf(error,size,"Путь к сохранениям слишком длинный.");
        else if (cancel && !strcmp(cancel,"1")) { if (size) error[0]=0; }
        else if (!test_name || !*test_name || strchr(test_name,'/') || test_name[0]=='.' ||
                 snprintf(path,sizeof path,"%s/%s",directory,test_name)>=(int)sizeof path)
            snprintf(error,size,"Неверное имя тестового сохранения.");
        else if (a2_save_import_cards(a2_paths.user,directory,error,size)) {
            result=saving ? a2_save_write(path,payload,error,size) :
                           a2_save_read(path,payload,NULL,error,size);
            fprintf(stderr,"native-save-file: %s result=%d %s\n",saving?"write":"read",result,path);
            if (result==A2_SAVE_PUBLISHED_UNCERTAIN) {
                fprintf(stderr,"native-save-durability-warning: %s\n",error);
                /* The published save is committed. Keep a real quick-save
                 * durability warning for the host alert after applying it. */
                if (!quick && size) error[0]=0;
            }
        }
    } else if (SDL_GetCurrentVideoDriver() && !strcmp(SDL_GetCurrentVideoDriver(),"dummy")) {
        snprintf(error,size,"Для теста без окна укажите профиль и файл сохранения.");
    } else result=a2_host_save_browser(a2_paths.user,saving,payload,error,size);
    native_dialog_end();
    return result;
}

void platform_native_save_error(const char *message) {
    fprintf(stderr,"native-save-error: %s\n",message);
    if (SDL_GetCurrentVideoDriver() && !strcmp(SDL_GetCurrentVideoDriver(),"dummy")) return;
    a2_input_set_menu_active(1);
    spu_set_sound(0);
    presentation_host_context();
    a2_host_ui_set_context(win,ren,tex,composed_width,composed_height);
    a2_host_save_error(message);
    native_dialog_end();
}

static int stage_startup_load(void) {
    uint8_t payload[A2_SAVE_PAYLOAD_SIZE];char error[512]={0};
    int selected=platform_native_save_dialog(0,payload,error,sizeof error);
    int ready=selected && a2_native_stage_startup_load(payload,error,sizeof error);
    if(error[0])platform_native_save_error(error);
    return ready;
}
#endif

#ifdef A2_NATIVE_MENU
void platform_show_game_menu(void) {
    if (SDL_GetCurrentVideoDriver() && !strcmp(SDL_GetCurrentVideoDriver(), "dummy")) return;
    spu_set_sound(0);
    settings_menu_open = 1;
    presentation_host_context();
    a2_host_ui_set_context(win,ren,tex,composed_width,composed_height);
    int action = a2_host_game_menu(0, a2_native_quick_save_available(),
                                      a2_native_quick_load_available());
    settings_menu_open = 0;
    settings_apply_changes();
    native_dialog_end();
    if (action == A2_MENU_QUIT) exit(0);
    if (action == A2_MENU_SAVE_SLOT || action == A2_MENU_LOAD_SLOT) {
        if (!a2_native_request_save_action(action == A2_MENU_SAVE_SLOT))
            platform_native_save_error("Сейчас это действие недоступно. Вернитесь к обычной игре и повторите попытку.");
    }
}
#endif

static int platform_init(void) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) != 0) {
        fprintf(stderr, "Cannot initialize SDL: %s\n", SDL_GetError());
        return 0;
    }
    a2_input_init();
    atexit(a2_input_shutdown);
#ifdef A2_HUD_PRESENT
    a2_hud_present_init(PSX_RAM,sizeof PSX_RAM);
    atexit(a2_hud_present_close);
#endif
#ifdef A2_INPUT_PROMPTS
    a2_input_prompts_init(PSX_RAM,sizeof PSX_RAM);
    atexit(a2_input_prompts_close);
#endif
#ifdef A2_VOICE_SUBTITLES
    atexit(a2_subtitle_panel_close);
#endif
    /* Menus/cinema retain 16:9; gameplay can fill the selected display. */
    settings_load();
    if (getenv("A2_CONTROL_FILE")) {
        if (!getenv("A2_USER_DIR") || !*getenv("A2_USER_DIR") ||
            !replay_control_load(getenv("A2_CONTROL_FILE"), &replay_control)) {
            fprintf(stderr, "A2_CONTROL_FILE requires a valid control file and explicit A2_USER_DIR\n");
            return 0;
        }
        replay_control_enabled = 1;
    }
    a2_wide_set(a2s.wide);
    gpu_set_ir(a2s.irscale);
    gpu_set_filter(a2s.filter);
    win = SDL_CreateWindow("Alundra 2: Rebuild",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1280, 720,
        SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE);
    if (!win) { fprintf(stderr, "Cannot create game window: %s\n", SDL_GetError()); return 0; }
    const char *present_vsync_override = getenv("A2_PRESENT_VSYNC");
    int renderer_flags = getenv("A2_FAST") ||
        (present_vsync_override && !strcmp(present_vsync_override, "0")) ?
        0 : SDL_RENDERER_PRESENTVSYNC;
    ren = SDL_CreateRenderer(win, -1, renderer_flags);
    if (!ren) { fprintf(stderr, "Cannot create renderer: %s\n", SDL_GetError()); return 0; }
    if (getenv("A2_TIMING") || getenv("A2_AUDIOSTAT")) {
        SDL_RendererInfo info;
        int query_result = SDL_GetRendererInfo(ren, &info);
        fprintf(stderr, "rendererdiag: present_vsync_override=%s requested_flags=0x%x "
                "query_result=%d name=%s flags=0x%x\n",
                present_vsync_override ? present_vsync_override : "unset", renderer_flags,
                query_result, query_result == 0 && info.name ? info.name : "unknown",
                query_result == 0 ? info.flags : 0);
    }
    SDL_RenderSetLogicalSize(ren, 960, 540);
    settings_apply_window(win, ren);
#ifdef A2_NATIVE_MENU
    a2_host_ui_set_context(win,ren,NULL,0,0);
    if (show_startup_menu && strcmp(SDL_GetCurrentVideoDriver(), "dummy")) {
        for (;;) {
            int action = a2_host_game_menu(1, 0, a2_native_save_enabled());
            if (action == A2_MENU_QUIT) return 0;
            if (action != A2_MENU_LOAD || stage_startup_load()) break;
            /* Cancel/error returns to the launcher, before any guest boot. */
        }
        settings_save();
        select_saved_profile = 1;
        /* No guest has started; controls/size can be applied without a frame. */
        a2_wide_set(a2s.wide);
        gpu_set_ir(a2s.irscale);
        gpu_set_filter(a2s.filter);
        settings_apply_window(win, ren);
        SDL_PumpEvents();
        SDL_FlushEvents(SDL_KEYDOWN, SDL_KEYUP);
        native_input_release = 1;
        SDL_RaiseWindow(win);
    }
#ifdef A2_NATIVE_SAVES
    /* Exercise the same staged selection with an isolated diagnostic profile. */
    if(getenv("A2_TEST_STARTUP_LOAD") && getenv("A2_USER_DIR") &&
       !a2_native_startup_load_pending() && !stage_startup_load())return 0;
#endif
#endif
    if (select_saved_profile) {
        if (!a2_profile_select(a2s.text_language)) {
            fprintf(stderr, "Requested text profile unavailable: %s\n", a2_profile_reason(a2s.text_language));
            if (strcmp(SDL_GetCurrentVideoDriver(), "dummy"))
                a2_host_save_error(a2_profile_reason(a2s.text_language));
            return 0;
        }
        cd_set_root(a2_paths.disc);
    }
    a2_game_text_language = a2s.text_language;
    a2_game_voice_language = a2s.voice_language;
#ifdef A2_HD_FONTS
    a2_hd_art_set_language(a2s.text_language);
    a2_hd_ui_set_language(a2s.text_language);
    active_text_language=a2s.text_language;active_voice_language=a2s.voice_language;
#endif
#ifdef A2_NATIVE_RESOURCES
    if(a2_profile_resources() && !a2_resources_set_name_voice(a2_profile_resources(),a2s.voice_language)) {
        fprintf(stderr,"Incomplete voice-dependent name resources\n");
        a2_host_save_error(a2s.text_language==0?"Не удалось загрузить варианты имён для выбранной озвучки.":
                           "Could not load the name variants for the selected voice.");
        return 0;
    }
    cd_set_resource_store(a2_profile_resources(),a2s.text_language);
#endif
    SDL_SetWindowTitle(win, "Alundra 2: Rebuild");
    settings_apply_startup();
    return 1;
}

/* settings runtime hook: drop framebuf/texture so present() rebuilds
 * them for the new internal resolution */
void platform_reset_fb(void) {
#ifdef __APPLE__
    if(presentation_gpu) {
        char error[1024];
        if(!a2_gpu_present_suspend(presentation_gpu,error,sizeof error)) {
            fprintf(stderr,"gpu-present: reset fallback: %s\n",error);
            gpu_present_failed=1;presentation_gpu_close();
        }
    }
    gpu_frame_ready=gpu_frame_materialized=0;
#endif
#ifdef A2_NATIVE_MESH
    mesh_runtime_check(win);
    mesh_runtime_sync();
#endif
    free(framebuf); framebuf = NULL;
    if (tex) { SDL_DestroyTexture(tex); tex = NULL; }
}

uint16_t psx_pad_buttons(void) {
    const Uint8 *k = SDL_GetKeyboardState(NULL);
    (void)k;
    uint16_t b = settings_pad_buttons();   /* bindings + gamepad */
#ifdef A2_NATIVE_SAVES
    if (native_input_release) {
        if (b != 0xFFFF) {
            if(!a2_native_startup_load_active())return 0xFFFF;
        } else native_input_release = 0;
    }
#endif
    /* A2_MASH=1: press Start+Cross 5 frames out of every 200 (headless
     * input smoke test: skips cutscenes, picks menu defaults) */
    if (getenv("A2_MASH") && frames % 200 < 5)
        b &= ~((1 << 3) | (1 << 14));
    /* A2_AUTO: overlay-aware autopilot — press Start/Circle while the
     * frontend overlay (GAME00, id 4) is active, hands off during
     * cutscenes (EVENT00) so the prologue plays through to gameplay */
    if (getenv("A2_AUTO")) {
        uint32_t ovl;
        memcpy(&ovl, PSX_RAM + 0x0811D8, 4);
        if (ovl == 4) {
            /* new-game choreography: wait for title to settle, then
             * UP (cursor defaults to Continue) and CIRCLE (confirm).
             * A2_AUTO=2: skip the UP — confirms CONTINUE (the default
             * cursor position, i.e. what a user pressing X gets). */
            static uint32_t g4_since;
            if (!g4_since) g4_since = frames;
            uint32_t ph = frames - g4_since;
            int cont = atoi(getenv("A2_AUTO")) == 2;
            if (!cont && ph >= 600 && ph < 605) b &= ~(1 << 4); /* up */
            else if (ph >= 700 && ph < 705) b &= ~(1 << 13);    /* circle */
        }
    }
    /* A2_TAP=frame:bit[:duration][,...] — deterministic pad replay.
     * Omitted duration keeps the original four-frame tap behavior. */
    if (getenv("A2_TAP")) {
        const char *p = getenv("A2_TAP");
        while (*p) {
            unsigned tf, tb, duration = 4;
            if (sscanf(p, "%u:%u:%u", &tf, &tb, &duration) >= 2 && tb < 16 &&
                frames >= tf && frames - tf < duration)
                b &= (uint16_t)~(1u << tb);
            p = strchr(p, ',');
            if (!p) break;
            p++;
        }
    }
    /* A2_SKIP: press Start periodically during cutscenes (EVENT00) to
     * skip them — cuts minutes off every headless run */
    if (getenv("A2_SKIP")) {
        uint32_t ovl;
        memcpy(&ovl, PSX_RAM + 0x0811D8, 4);
        if (ovl == 5 && frames % 100 < 4)
            b &= ~(1 << 3);                       /* start */
    }
    /* A2_PLAY: gameplay probe — once past the AUTO menu phase, drive the
     * character (cycle d-pad) and tap cross/circle to advance dialogs
     * and area triggers */
    if (getenv("A2_PLAY")) {
        uint32_t ovl;
        memcpy(&ovl, PSX_RAM + 0x0811D8, 4);
        if (ovl == 4) {
            static uint32_t g4p_since;
            if (!g4p_since) g4p_since = frames;
            uint32_t ph = frames - g4p_since;
            if (ph > 900) {
                static const int dirs[4] = {4, 5, 6, 7};
                b &= ~(1 << dirs[(ph / 150) & 3]);
                if (ph % 47 < 3) b &= ~(1 << 14);   /* cross */
                if (ph % 83 < 3) b &= ~(1 << 13);   /* circle */
            }
        }
    }
    if (replay_control_enabled)
        b &= replay_control_buttons(&replay_control, frames);
#ifdef A2_NATIVE_SAVES
    if(a2_native_startup_load_active())return 0xffff;
#endif
    int held=b!=0xffff || SDL_GetMouseState(NULL,NULL)!=0;
    int key_count=0;const Uint8 *keys=SDL_GetKeyboardState(&key_count);
    for(int i=0;i<key_count&&!held;i++)if(keys[i]&&!a2_input_key_reserved(i))held=1;
    return a2_startup_pad(frames,(int)lw_(0x800811D8u),b,held);
}

/* Test-only live stepping. The game remains on its real call stack while
 * paused; no emulator state is restored or guest script execution bypassed.
 * Change the control file to a larger until_frame to resume. */
static void replay_dump(const char *name, const void *data, size_t size) {
    char path[4096];
    if (snprintf(path, sizeof path, "%s/%s_%05u.bin", a2_paths.user, name, frames) >= (int)sizeof path) {
        fprintf(stderr, "control: capture path too long\n"); exit(2);
    }
    FILE *file = fopen(path, "wb");
    if (!file) { fprintf(stderr, "control: cannot create %s\n", path); exit(2); }
    int failed = fwrite(data, 1, size, file) != size;
    if (fclose(file)) failed = 1;
    if (failed) { fprintf(stderr, "control: incomplete capture %s\n", path); exit(2); }
}

static void replay_checkpoint(void) {
    if (!replay_control_enabled || frames < replay_control.until_frame) return;
    presentation_materialize();
    char path[4096];
    if (snprintf(path, sizeof path, "%s/frame_%05u.bmp", a2_paths.user, frames) < (int)sizeof path) {
        SDL_Surface *surface = SDL_CreateRGBSurfaceWithFormatFrom(
            framebuf, composed_width, composed_height, 32, fb_w * 4, SDL_PIXELFORMAT_ARGB8888);
        if (!surface || SDL_SaveBMP(surface, path)) {
            fprintf(stderr, "control: cannot capture frame: %s\n", SDL_GetError());
            exit(2);
        }
        SDL_FreeSurface(surface);
    }
    replay_dump("ram", PSX_RAM, PSX_RAM_SIZE);
    replay_dump("vram", GPU_VRAM, sizeof GPU_VRAM);
    fprintf(stderr, "control: paused frame=%u overlay=%u map_id=%u pos=%d,%d,%d flags=%X\n",
            frames, lw_(0x800811D8u), lh_(0x8012789Cu),
            (int32_t)lw_(0x80119728u) >> 12, (int32_t)lw_(0x8011972Cu) >> 12,
            (int32_t)lw_(0x80119730u) >> 12, lw_(0x800F6220u));
    fflush(stderr);
    spu_set_sound(0);
    uint64_t waiting_since = SDL_GetTicks64();
    for (;;) {
        ReplayControl next;
        if (replay_control_load(getenv("A2_CONTROL_FILE"), &next) && next.until_frame > frames) {
            replay_control = next;
            spu_set_sound(a2s.sound);
            next_frame_ticks = 0;
            last_present_ticks = 0;
            return;
        }
        SDL_Event event;
        while (SDL_PollEvent(&event))
            if (event.type == SDL_QUIT) exit(0);
        if (SDL_GetTicks64() - waiting_since > 15 * 60 * 1000) {
            fprintf(stderr, "control: no valid resume command for 15 minutes\n");
            exit(2);
        }
        SDL_Delay(50);
    }
}

static void present(void) {
    int startup_loading=0;
#ifdef A2_NATIVE_SAVES
    startup_loading=a2_native_startup_load_active();
#endif
#ifdef A2_NATIVE_MESH
    mesh_runtime_check(win); /* Before any compose, screenshot, upload or present. */
#endif
    A2Phase previous_phase = a2_phase_enter(A2_PHASE_COMPOSE);
    static int profile = -1;
    static uint64_t profile_totals[4];
    static unsigned profile_frames,profile_views;
    static unsigned profile_presented, profile_skipped;
    static uint64_t profile_max_gap, profile_max_present, profile_present_ticks;
    if (profile < 0) profile = getenv("A2_PROFILE_PRESENT") != NULL;
    uint64_t stamps[5] = {0};
    if (profile) stamps[0] = SDL_GetPerformanceCounter();
    int dx, dy, dw, dh, on;
    void gpu_get_raster(int *, int *, int *, int *);
    int xo, yo, cw, ch;
    gpu_get_display(&dx, &dy, &dw, &dh, &on);
    gpu_get_raster(&xo, &yo, &cw, &ch);
    if (dw <= 0 || dw > 1024) dw = 320;
    if (dh <= 0 || dh > 512) dh = 240;
    if (cw <= 0 || cw > 1024) cw = dw;
    if (ch <= 0 || ch > 512) ch = dh;
    /* clamp the picture into the canvas */
    if (xo + dw > cw) xo = cw > dw ? cw - dw : 0;
    if (yo + dh > ch) yo = ch > dh ? ch - dh : 0;
    int S = gpu_ir();
    if (!framebuf) {
        fb_w = 1024 * S; fb_h = 512 * S;
        framebuf = malloc((size_t)fb_w * fb_h * 4);
    }
    if (!tex) {
        tex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_ARGB8888,
                                SDL_TEXTUREACCESS_STREAMING, fb_w, fb_h);
    }
    /* compose the picture onto the TV raster (black borders around);
     * everything below works on the fine (S-scaled) grid */
    A2CinemaRaster cinematic_raster={dx,dy,dw,dh,xo,yo,cw,ch,on,
                                    (int)lw_(0x800811D8u)};
    /* Projection follows the guest's real canvas, even while the startup
     * loader hides it, so the first gameplay frame is already square. */
    A2CinemaRaster projection_raster=cinematic_raster;
    int projection_gameplay=a2_gameplay_canvas(&projection_raster);
    if(startup_loading)cinematic_raster.overlay=0;
    int gameplay_canvas=a2_gameplay_canvas(&cinematic_raster);
    if(gameplay_canvas) { yo=cinematic_raster.yo; ch=cinematic_raster.ch; }
    int fill_game=a2s.fill_screen&&gameplay_canvas;
    int logical_w,logical_h;SDL_RenderGetLogicalSize(ren,&logical_w,&logical_h);
    if(logical_w!=(fill_game?0:960)||logical_h!=(fill_game?0:540))
        SDL_RenderSetLogicalSize(ren,fill_game?0:960,fill_game?0:540);
#ifdef __APPLE__
    a2_gpu_present_set_fill(presentation_gpu,fill_game);
#endif
    int output_w=16,output_h=9;
    if(a2s.fill_screen&&projection_gameplay)SDL_GetRendererOutputSize(ren,&output_w,&output_h);
    world_precision_set_projection(output_w,output_h,projection_gameplay?216:240);
    A2CinemaLayout cinematic_layout;
    int cinematic=!startup_loading&&a2_cinema_layout(PSX_RAM,sizeof PSX_RAM,&cinematic_raster,&cinematic_layout);
    int show_subtitles=a2_cinema_show_subtitles(a2s.subtitles,active_text_language,active_voice_language);
    int voice_subtitles=0;
#ifdef A2_VOICE_SUBTITLES
    voice_subtitles=active_voice_language==1;
    int subtitle_language=a2_voice_subtitle_language(a2s.english_subtitle_language,active_text_language);
    A2VoicePosition voice_position={0};const char *caption=NULL;
    if(cinematic&&show_subtitles&&voice_subtitles&&a2_native_voice_position(&voice_position)&&voice_position.origin==1)
        caption=a2_voice_subtitle(voice_position.name,voice_position.milliseconds,subtitle_language);
    a2_subtitle_panel_set(caption,S,cw,ch,a2s.cinema?239:218);
    if(getenv("A2_SUBTITLELOG")){
        static const char *previous_caption;
        if(caption!=previous_caption){
            fprintf(stderr,"subtitle: frame=%u name=%s ms=%u text=%s\n",frames,
                voice_position.name?voice_position.name:"-",voice_position.milliseconds,caption?caption:"<clear>");
            previous_caption=caption;
        }
    }
#endif
    if(cinematic&&!a2s.cinema) {
        cinematic_layout.picture_dst_y=yo;
        cinematic_layout.subtitle_dst_y=yo+cinematic_layout.subtitle_src_y;
        if(show_subtitles&&!voice_subtitles)cinematic=0;
    }
    if(cinematic&&(!show_subtitles||voice_subtitles))cinematic_layout.subtitle_rows=0;
    int cinematic_expanded=0;
    A2FrameView frame_view={0};
#ifdef A2_NATIVE_MESH
    a2_mesh_live_trace_display(frames,dy);
#endif
    if(startup_loading) {
        /* Required engine initialization remains live, with a neutral frame
         * until the selected checkpoint reaches ordinary gameplay. Retain
         * normal presentation, event pacing and diagnostic capture paths. */
        for(int y=0;y<ch*S;y++)for(int x=0;x<cw*S;x++)framebuf[(size_t)y*fb_w+x]=0xff000000u;
    } else if(cinematic) {
#ifdef A2_CINEMA_EXPANSION
        cinematic_expanded=a2_compose_cinema_expanded(framebuf,fb_w,S,&cinematic_raster,&cinematic_layout);
#endif
        if(!cinematic_expanded)
            a2_compose_cinema(framebuf,fb_w,S,&cinematic_raster,&cinematic_layout);
    }
    else {
#ifdef __APPLE__
        if(presentation_frame_view_enabled())
            a2_frame_view(&frame_view,S,dx,dy,dw,dh,xo,yo,cw,ch);
#endif
        if(!frame_view.pixels)
            a2_compose_frame(framebuf,fb_w,S,dx,dy,dw,dh,xo,yo,cw,ch);
    }
    if(profile&&frame_view.pixels)profile_views++;
#ifdef A2_NATIVE_MESH
    mesh_runtime_check(win); /* A row consumer can detect a late contract failure. */
#endif
    if(getenv("A2_CINEMALOG")) {
        static int previous=-1;
        int mode=cinematic+2*gameplay_canvas+4*cinematic_expanded;
        if(previous!=mode) {
            fprintf(stderr,"cinema: frame=%u centered=%d gameplay_canvas=%d overlay=%d display=%d,%d,%d,%d raster=%d,%d,%d,%d expanded=%d\n",
                    frames,cinematic,gameplay_canvas,cinematic_raster.overlay,dx,dy,dw,dh,xo,yo,cw,ch,cinematic_expanded);
            previous=mode;
        }
    }
    composed_width=cw*S; composed_height=ch*S;
#ifdef A2_INPUT_PROMPTS
    a2_input_prompts_configure(a2s.text_language);
#endif
    int gpu_output=0;
#ifdef __APPLE__
    gpu_output=presentation_gpu_prepare(S,&cinematic_raster,
        frame_view.pixels?frame_view.pixels:framebuf,frame_view.pixels?frame_view.stride:fb_w);
    a2_gpu_present_set_fill(presentation_gpu,fill_game);
#endif
    if(!gpu_output) {
        if(frame_view.pixels)
            a2_compose_frame(framebuf,fb_w,S,dx,dy,dw,dh,xo,yo,cw,ch);
#ifdef __APPLE__
        presentation_antialias(framebuf,composed_width,composed_height,fb_w);
#endif
#ifdef A2_INPUT_PROMPTS
        a2_input_prompts_compose(framebuf,fb_w,S,&cinematic_raster,settings_menu_open);
#endif
#ifdef A2_VOICE_SUBTITLES
        a2_subtitle_panel_compose(framebuf,fb_w,composed_width,composed_height);
#endif
    }
    /* IRQ may change the display before a replay checkpoint. Captures must
     * retain the dimensions of this composed frame, not query the next one. */
    composed_width=cw*S; composed_height=ch*S;
    SDL_Rect src = {0, 0, composed_width, composed_height};
    if (getenv("A2_SHOT") && frames == (uint32_t)atoi(getenv("A2_SHOT"))) {
        presentation_materialize();
        SDL_Surface *s = SDL_CreateRGBSurfaceWithFormatFrom(
            framebuf, cw * S, ch * S, 32, fb_w * 4, SDL_PIXELFORMAT_ARGB8888);
        SDL_SaveBMP(s, "/tmp/window_shot.bmp");
        SDL_FreeSurface(s);
        fprintf(stderr, "window content dumped at frame %u\n", frames);
    }
    /* A2_SHOTDIR overrides the hardcoded /tmp shot directory;
     * A2_SHOTEVERY=N overrides the 2000-frame interval */
    {
        static int every = -1;
        if (every < 0)
            every = getenv("A2_SHOTEVERY") ? atoi(getenv("A2_SHOTEVERY"))
                                           : 2000;
        if (getenv("A2_SHOTS") && every > 0 && frames % every == 0 && frames) {
            presentation_materialize();
            char p[512];
            const char *dir = getenv("A2_SHOTDIR");
            snprintf(p, sizeof p, "%s/shot_%05u.bmp", dir ? dir : "/tmp",
                     frames);
            SDL_Surface *s = SDL_CreateRGBSurfaceWithFormatFrom(
                framebuf, cw * S, ch * S, 32, fb_w * 4,
                SDL_PIXELFORMAT_ARGB8888);
            SDL_SaveBMP(s, p);
            SDL_FreeSurface(s);
        }
    }
    if (profile) stamps[1] = SDL_GetPerformanceCounter();
    (void)a2_phase_enter(A2_PHASE_UPLOAD);
    if(!gpu_output)SDL_UpdateTexture(tex, &src, framebuf, fb_w * 4);
    /* The TV raster and the drawable have different pixel aspect/size. Nearest
     * resampling here reintroduces stairs after AA, especially during resize. */
    SDL_SetTextureScaleMode(tex,a2s.antialias?SDL_ScaleModeLinear:SDL_ScaleModeNearest);
    if (profile) stamps[2] = SDL_GetPerformanceCounter();
    (void)a2_phase_enter(A2_PHASE_DRAW);
    if(!gpu_output) {
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, tex, &src, NULL);
        settings_draw(ren);
    }
    /* A2_UISHOT=frame: dump the composed renderer output (including
     * the settings overlay) — A2_SHOT captures only the game framebuf */
    int ui_capture=getenv("A2_UISHOT")&&frames==(uint32_t)atoi(getenv("A2_UISHOT"));
    if (!gpu_output&&ui_capture) {
        SDL_Surface *s = a2_render_capture_window(ren);
        if (s) {
            const char *ui_path=getenv("A2_UISHOT_PATH");
            if(!ui_path || !*ui_path) ui_path="/tmp/ui_shot.bmp";
            if(SDL_SaveBMP(s, ui_path))
                fprintf(stderr,"ui shot failed: %s\n",SDL_GetError());
            else fprintf(stderr, "ui shot dumped at frame %u\n", frames);
        } else fprintf(stderr,"ui shot failed: %s\n",SDL_GetError());
        if (s) SDL_FreeSurface(s);
    }
    if (profile) stamps[3] = SDL_GetPerformanceCounter();
    (void)a2_phase_enter(A2_PHASE_PRESENT);
    int skip_present = 0;
    uint64_t present_freq = 0, present_lateness = 0;
    if (!getenv("A2_FAST")) {
        present_freq = SDL_GetPerformanceFrequency();
        uint64_t now = SDL_GetPerformanceCounter();
        skip_present = a2_frame_pacer_skip_present(next_frame_ticks, now, present_freq,
                                                  last_present_ticks);
        if (skip_present) present_lateness = now - next_frame_ticks;
    }
    if (!skip_present||gpu_output) {
        uint64_t began = profile ? SDL_GetPerformanceCounter() : 0;
        int submitted=!skip_present;
#ifdef __APPLE__
        if(gpu_output) {
            char error[1024];submitted=a2_gpu_present_commit(presentation_gpu,!skip_present,ui_capture,error,sizeof error);
            if(submitted<0) {
                /* A borrowed input left framebuf untouched. Recompose it before
                 * CPU fallback unless an explicit readback already filled it. */
                fprintf(stderr,"gpu-present: frame fallback to SDL: %s\n",error);
                if(ui_capture) {
                    fprintf(stderr,"gpu-present: requested window capture failed during commit; no substitute image saved\n");
                    exit(2);
                }
                if(!gpu_frame_materialized) {
                    if(frame_view.pixels)
                        a2_compose_frame(framebuf,fb_w,S,dx,dy,dw,dh,xo,yo,cw,ch);
                    presentation_antialias(framebuf,composed_width,composed_height,fb_w);
#ifdef A2_INPUT_PROMPTS
                    a2_input_prompts_compose(framebuf,fb_w,S,&cinematic_raster,settings_menu_open);
#endif
#ifdef A2_VOICE_SUBTITLES
                    a2_subtitle_panel_compose(framebuf,fb_w,composed_width,composed_height);
#endif
                }
                gpu_present_failed=1;presentation_gpu_close();gpu_output=0;
                SDL_UpdateTexture(tex,&src,framebuf,fb_w*4);SDL_RenderClear(ren);SDL_RenderCopy(ren,tex,&src,NULL);
                submitted=!skip_present;if(submitted)SDL_RenderPresent(ren);
            }
        } else
#endif
        SDL_RenderPresent(ren);
        uint64_t completed = SDL_GetPerformanceCounter();
        if (profile&&submitted) {
            uint64_t gap = last_present_ticks && completed >= last_present_ticks ?
                           completed - last_present_ticks : 0;
            uint64_t elapsed = completed - began;
            if (gap > profile_max_gap) profile_max_gap = gap;
            if (elapsed > profile_max_present) profile_max_present = elapsed;
            profile_present_ticks += elapsed;
            profile_presented++;
        }
        if(submitted)last_present_ticks = completed;
        else if(profile)profile_skipped++;
    } else if (profile) profile_skipped++;
#ifdef __APPLE__
    if(gpu_output&&ui_capture) {
        int width,height,stride;char error[1024];
        const uint32_t *pixels=a2_gpu_present_window_pixels(presentation_gpu,&width,&height,&stride,error,sizeof error);
        if(!pixels){fprintf(stderr,"gpu-present: window capture failed: %s\n",error);exit(2);}
        SDL_Surface *surface=SDL_CreateRGBSurfaceWithFormatFrom((void *)pixels,width,height,32,stride*4,SDL_PIXELFORMAT_ARGB8888);
        const char *path=getenv("A2_UISHOT_PATH");if(!path||!*path)path="/tmp/ui_shot.bmp";
        if(!surface||SDL_SaveBMP(surface,path)){fprintf(stderr,"gpu-present: window capture write failed: %s\n",SDL_GetError());exit(2);}
        SDL_FreeSurface(surface);fprintf(stderr,"ui shot dumped from GPU drawable at frame %u\n",frames);
    }
#endif
    (void)a2_phase_enter(A2_PHASE_DIAG);
    if (profile) stamps[4] = SDL_GetPerformanceCounter();
    if (skip_present && getenv("A2_TIMING")) {
        fprintf(stderr, "presentcatchup: frame=%u lateness_ticks=%llu lateness_ms=%.3f\n",
                frames, (unsigned long long)present_lateness,
                1000.0 * present_lateness / present_freq);
    }
    if (profile) {
        for (int i = 0; i < 4; i++) profile_totals[i] += stamps[i+1] - stamps[i];
        if (++profile_frames == 60) {
            double factor = 1000.0 / (SDL_GetPerformanceFrequency() * (double)profile_frames);
            fprintf(stderr, "presentstat: frame=%u canvas=%dx%d IR=%d compose_ms=%.3f upload_ms=%.3f draw_ms=%.3f present_ms=%.3f\n",
                    frames, cw, ch, S, profile_totals[0]*factor, profile_totals[1]*factor,
                    profile_totals[2]*factor, profile_totals[3]*factor);
            fprintf(stderr,"frameviewstat: frame=%u borrowed=%u composed=%u\n",
                    frames,profile_views,profile_frames-profile_views);
            profile_views=0;
            double ticks_ms = 1000.0 / SDL_GetPerformanceFrequency();
            fprintf(stderr, "displaystat: first_frame=%u frame=%u attempts=%u presented=%u skipped=%u "
                    "max_gap_ms=%.3f max_present_ms=%.3f present_wall_ms=%.3f\n",
                    frames + 1 - profile_frames, frames, profile_frames,
                    profile_presented, profile_skipped, profile_max_gap*ticks_ms,
                    profile_max_present*ticks_ms, profile_present_ticks*ticks_ms);
            memset(profile_totals, 0, sizeof profile_totals);
            profile_frames = 0;
            profile_presented = profile_skipped = 0;
            profile_max_gap = profile_max_present = profile_present_ticks = 0;
        }
    }
    a2_phase_leave(previous_phase);
}

void gpu_vblank(void);

static int poll_event(SDL_Event *event) {
    A2Phase previous_phase = a2_phase_enter(A2_PHASE_EVENT_POLL);
    int result = SDL_PollEvent(event);
    a2_phase_leave(previous_phase);
    return result;
}

void psx_vblank_tick(void) {
    static int in_tick;
    if (in_tick) return;
    in_tick = 1;
    A2Phase previous_phase = a2_phase_enter(A2_PHASE_HOST);
    frames++;
    psx_frame_no = frames;
    gpu_vblank();
    void mmio_timers_vblank(void);
    mmio_timers_vblank();
    SDL_Event e;
    while (poll_event(&e)) {
        A2Phase event_phase = a2_phase_enter(A2_PHASE_EVENT);
        a2_input_handle_event(&e);
        if (e.type == SDL_QUIT) {
            fprintf(stderr, "quit after %u frames\n", frames);
            exit(0);
        }
        if ((e.type==SDL_KEYDOWN&&!e.key.repeat&&!a2_input_key_reserved(e.key.keysym.scancode)) ||
            e.type==SDL_CONTROLLERBUTTONDOWN || e.type==SDL_MOUSEBUTTONDOWN)
            a2_startup_request();
        if (e.type == SDL_KEYDOWN) {
            SDL_Scancode sc = e.key.keysym.scancode;
            if (e.key.repeat) { a2_phase_leave(event_phase); continue; }
#ifdef A2_NATIVE_MENU
            if (sc == SDL_SCANCODE_F5 || sc == SDL_SCANCODE_F9) {
                if (!a2_native_request_quick_action(sc == SDL_SCANCODE_F5))
                    platform_native_save_error("Сейчас это действие недоступно. Вернитесь к обычной игре и повторите попытку.");
                a2_phase_leave(event_phase);
                continue;
            }
#endif
            /* Native Escape/F1 pauses the guest at this host boundary. */
            if (settings_handle_key(sc)) {
                a2_phase_leave(event_phase);
                continue;
            }
            if (sc == SDL_SCANCODE_ESCAPE) {
                fprintf(stderr, "quit after %u frames\n", frames);
                exit(0);
            }
        }
        a2_phase_leave(event_phase);
    }
    A2Phase pad_phase = a2_phase_enter(A2_PHASE_PAD);
    a2_input_poll();
    if(a2_input_take_menu_request()) {
#ifdef A2_NATIVE_MENU
        platform_show_game_menu();
#else
        settings_toggle_menu();
#endif
    }
    psx_pad_update();
    a2_phase_leave(pad_phase);
    void cd_vblank(void);
    (void)a2_phase_enter(A2_PHASE_CD);
#ifdef A2_NATIVE_RESOURCES
    a2_native_resources_tick();
#endif
    cd_vblank();
#ifdef A2_NATIVE_RESOURCES
    if(a2_profile_resources() && a2_native_voice_error()[0]) {
        fprintf(stderr,"Native playback failed: %s\n",a2_native_voice_error());
        exit(1);
    }
#endif
    (void)a2_phase_enter(A2_PHASE_HOST);
    present();
    (void)a2_phase_enter(A2_PHASE_DIAG);
    {
        static uint32_t last_ovl = ~0u;
        uint32_t ovl;
        memcpy(&ovl, PSX_RAM + 0x0811D8, 4);
        if (ovl != last_ovl && ovl <= 16) {
            static const char *names[] = {"?", "?", "?", "?", "GAME00",
                "EVENT00", "GAME01", "GAME02", "GAME03"};
            fprintf(stderr, "overlay -> %s (id=%u) at frame %u\n",
                    ovl <= 8 ? names[ovl] : "?", ovl, frames);
            last_ovl = ovl;
        }
    }
    if (getenv("A2_STATELOG") && frames % 300 == 0) {
        uint32_t ovl = lw_(0x800811D8u);
        if (ovl == 4) {
            char map[5];
            memcpy(map, PSX_RAM + 0x1310A0, 4); map[4] = 0;
            for (int i = 0; i < 4; i++)
                if ((unsigned char)map[i] < 32 || (unsigned char)map[i] > 126) map[i] = '_';
            fprintf(stderr, "state: frame=%u overlay=%u map=%s pos=%d,%d,%d flags=%X map_id=%u\n",
                    frames, ovl, map, (int32_t)lw_(0x80119728u) >> 12,
                    (int32_t)lw_(0x8011972Cu) >> 12,
                    (int32_t)lw_(0x80119730u) >> 12, lw_(0x800F6220u),
                    lh_(0x8012789Cu));
        }
    }
#ifdef A2_NATIVE_SAVES
    /* Private-profile replay of the same API used by F5/F9. No map mutation. */
    if(getenv("A2_USER_DIR")) {
        static unsigned quick_test_done;
        const char *names[]={"A2_TEST_QUICK_SAVE_AT","A2_TEST_QUICK_LOAD_AT"};
        for(unsigned i=0;i<2;i++) {
            const char *value=getenv(names[i]);unsigned at=0;
            if(value && !(quick_test_done&(1u<<i)) && sscanf(value,"%u",&at)==1 && at>0 && frames>=at) {
                quick_test_done|=1u<<i;
                int accepted=a2_native_request_quick_action(i==0);
                fprintf(stderr,"test-quick: %s frame=%u accepted=%d map=%u\n",i?"load":"save",frames,accepted,lh_(0x8012789Cu));
            }
        }
    }
#endif
    /* Isolated save/load integration probe. This is the same menu request
     * written by the save-point entity at GAME00:800AF328; the game performs
     * its own snapshot, serialization, checksum and card writes. Never used
     * by normal gameplay, and requires an explicit test profile directory. */
    if (getenv("A2_TEST_SAVE_AT") && getenv("A2_USER_DIR") &&
        *getenv("A2_USER_DIR")) {
        static int requested;
        unsigned at = 0;
        if (!requested && sscanf(getenv("A2_TEST_SAVE_AT"), "%u", &at) == 1 &&
            at > 0 && frames >= at && lw_(0x800811D8u) == 4 &&
            !(lw_(0x800F6220u) & 0x10) && lb_(0x8011752Au) == 0 &&
            lb_(0x800F621Cu) == 0) {
            /* Same allowed-location lookup as GAME00:800C55BC. Saving on
             * tutorial maps creates a file the original loader rejects. */
            unsigned map_id = lh_(0x8012789Cu);
            for (unsigned i = 0; i < 40; i++) {
                if (lh_(0x800EEF10u + i * 2) != map_id) continue;
                sb_(0x800F621Cu, 3);
                requested = 1;
                fprintf(stderr, "test-save: requested at frame %u map_id=%u\n",
                        frames, map_id);
                break;
            }
        }
    }
    {
        extern int psx_dslog;
        if (getenv("A2_DSLOG")) psx_dslog = 1;
    }
    /* A2_DUMPMEM=frame:hexaddr:hexlen — dump a PSX RAM slice to the file
     * named by A2_DUMPOUT (default /tmp/memdump.bin) */
    if (getenv("A2_DUMPMEM")) {
        static uint32_t df, da, dl; static int dp = -1;
        if (dp < 0)
            dp = sscanf(getenv("A2_DUMPMEM"), "%u:%x:%x", &df, &da, &dl) == 3;
        if (dp == 1 && frames == df) {
            dp = 2;
            const char *p = getenv("A2_DUMPOUT");
            if (!p) p = "/tmp/memdump.bin";
            FILE *f = fopen(p, "wb");
            if (f) {
                fwrite(PSX_RAM + (da & 0x1FFFFF), 1, dl, f);
                fclose(f);
                fprintf(stderr, "memdump: f%u %08X+%X -> %s\n",
                        frames, da, dl, p);
            }
        }
    }
    if (getenv("A2_PRIMLOG") && frames == (uint32_t)atoi(getenv("A2_PRIMLOG"))) {
        extern int gpu_prim_log;
        gpu_prim_log = getenv("A2_PRIMN") ? atoi(getenv("A2_PRIMN")) : 300;
    }
    if (getenv("A2_HOT") && frames == 8500) {
        extern int psx_hotlog;
        psx_hotlog = atoi(getenv("A2_HOT")) > 1 ? atoi(getenv("A2_HOT")) : 400;
    }
    if (getenv("A2_GTESTAT") && frames % 4000 == 0 && frames) {
        extern uint32_t gte_op_hist[64];
        fprintf(stderr, "gte@%u:", frames);
        for (int i = 0; i < 64; i++)
            if (gte_op_hist[i]) fprintf(stderr, " %02X=%u", i, gte_op_hist[i]);
        fprintf(stderr, "\n");
    }
    /* A2_MOCAP=frame: experiment — force the scripted-walk/camera
     * mocap playback mode (lh 0x80117528 = 1) at that frame to test
     * whether the path-playback integrator g0_80086DC8 drives the
     * prologue intro walk (player + camera together) */
    if (getenv("A2_MOCAP") && frames == (uint32_t)atoi(getenv("A2_MOCAP"))) {
        uint16_t one = 1;
#ifdef A2_WORLD_PRECISION
        world_precision_invalidate(0x80117528u, 2);
#endif
        memcpy(PSX_RAM + 0x117528, &one, 2);
        fprintf(stderr, "mocap: forced mode 1 at frame %u\n", frames);
    }
    /* Scene movement remains entirely under the original game code.
     * The former a09 replay-mode workaround interfered with normal entity
     * integration (8008BEC0); independent old/new runtime comparisons show
     * the unmodified prologue completes with camera mode zero. */
    /* deliver VBlank to the game: IRQ chain + kernel events */
    (void)a2_phase_enter(A2_PHASE_IRQ);
    psx_irq_set(0);
    psx_irq_dispatch();
    psx_deliver_event(0xF2000003, 2);
    /* refill pad buffers AFTER the chain handler (the real handler's
     * dead SIO dance overwrites them with disconnected status) */
    void pad_hle_tick(void);
    pad_hle_tick();
    spu_vblank();
    (void)a2_phase_enter(A2_PHASE_WAIT);
    /* 60 Hz wall-clock pacing, including displays with higher refresh.
     * A 16 ms interval is 62.5 Hz and speeds up both logic and sound. */
    if (!getenv("A2_FAST")) {
        uint64_t freq = SDL_GetPerformanceFrequency();
        uint64_t now = SDL_GetPerformanceCounter();
        uint64_t delay_ms = next_frame_ticks > now ?
            (next_frame_ticks - now) * 1000 / freq : 0;
        unsigned tail_calls = 0;
        a2_phase_pace_plan(freq, now, next_frame_ticks, (Uint32)delay_ms);
        if (next_frame_ticks > now) {
            if (delay_ms) {
                (void)a2_phase_enter(A2_PHASE_WAIT_COARSE);
                a2_frame_wait((Uint32)delay_ms, frames);
            }
            (void)a2_phase_enter(A2_PHASE_WAIT_TAIL);
            while (SDL_GetPerformanceCounter() < next_frame_ticks) {
                tail_calls++;
                SDL_Delay(0);
            }
            now = SDL_GetPerformanceCounter();
            (void)a2_phase_enter(A2_PHASE_WAIT);
        }
        a2_phase_pace_end(now, tail_calls);
        A2FramePacerAdvance pace = a2_frame_pacer_advance(next_frame_ticks, now, freq);
        if (pace.rebased) {
            if (getenv("A2_TIMING")) {
                uint64_t discarded_lateness = pace.discarded_lateness_ticks;
                fprintf(stderr, "pacerebase: frame=%u discarded_lateness_ticks=%llu "
                        "discarded_lateness_ms=%.3f\n", frames,
                        (unsigned long long)discarded_lateness,
                        1000.0 * discarded_lateness / freq);
            }
        }
        next_frame_ticks = pace.next_frame_ticks;
    }
    (void)a2_phase_enter(A2_PHASE_DIAG);
    /* A2_TICKSTAT: per-second rates — guest VBlanks, sequencer ticks,
     * game logic fps (framebuffer flips), emulated work units */
    if (getenv("A2_TICKSTAT")) {
        extern uint32_t seq_ticks, gpu_flips, psx_work;
        static uint64_t t0; static uint32_t f0, s0, g0, w0;
        uint64_t now = SDL_GetTicks64();
        if (!t0) { t0 = now; f0 = frames; s0 = seq_ticks; g0 = gpu_flips;
                   w0 = psx_work; }
        if (now - t0 >= 1000) {
            fprintf(stderr, "tickstat: frames/s=%u seqticks/s=%u gamefps=%u "
                    "work/s=%u\n", frames - f0, seq_ticks - s0,
                    gpu_flips - g0, psx_work - w0);
            t0 = now; f0 = frames; s0 = seq_ticks; g0 = gpu_flips;
            w0 = psx_work;
        }
    }
    a2_phase_frame(frames);
    /* A2_TIMEOUT=N: hard wall-clock suicide after N seconds — debug
     * runs can never orphan into a 100%-CPU zombie again */
    if (getenv("A2_TIMEOUT")) {
        static uint64_t t0;
        if (!t0) t0 = SDL_GetTicks64();
        if (SDL_GetTicks64() - t0 >
            (uint64_t)atoi(getenv("A2_TIMEOUT")) * 1000) {
            fprintf(stderr, "A2_TIMEOUT reached, exiting\n");
            exit(2);
        }
    }
    if (getenv("A2_MAXFRAMES") &&
        frames >= (uint32_t)atoi(getenv("A2_MAXFRAMES"))) {
        fprintf(stderr, "frame limit reached (%u frames)\n", frames);
        if (getenv("A2_VRAMDUMP")) {
            static uint32_t buf[1024 * 512];
            for (int i = 0; i < 1024 * 512; i++) {
                uint16_t c = GPU_VRAM[i];
                /* bit15 (STP/index msb) goes to alpha so the dump stays
                 * lossless; use A2_RAWDUMP (gpu.c) for exact halfwords */
                buf[i] = ((c & 0x8000) ? 0x80000000u : 0xFF000000u) |
                         ((uint32_t)(c & 31) << 19) |
                         ((uint32_t)((c >> 5) & 31) << 11) |
                         ((uint32_t)((c >> 10) & 31) << 3);
            }
            SDL_Surface *s = SDL_CreateRGBSurfaceWithFormatFrom(
                buf, 1024, 512, 32, 1024 * 4, SDL_PIXELFORMAT_ARGB8888);
            SDL_SaveBMP(s, getenv("A2_VRAMDUMP"));
            fprintf(stderr, "vram dumped to %s\n", getenv("A2_VRAMDUMP"));
        }
        exit(0);
    }
    replay_checkpoint();
    a2_phase_leave(previous_phase);
    in_tick = 0;
}

/* ---------- boot ---------- */
void psx_register_hle(uint32_t addr, void (*fn)(void));

static int boot(const char *root, const char *image) {
    void pad_hle_install(void);
    pad_hle_install();
    if (!platform_init()) return 1;
    a2_startup_reset(a2s.skip_intro);
#ifdef A2_NATIVE_ACTOR_SNAPSHOT
    if (!actor_capture_init()) return 1;
#endif
#ifdef A2_NATIVE_MESH
    mesh_runtime_init();
#endif
    spu_init_audio();
    spu_set_sound(a2s.sound);
    if (
#ifdef A2_NATIVE_SAVES
        !a2_native_save_enabled() &&
#endif
        !memcard_init(a2_paths.user)) {
        fprintf(stderr, "A memory card could not be opened; see the card error above.\n");
        if (!getenv("SDL_VIDEODRIVER"))
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Alundra 2",
                "A memory card could not be opened. Another copy of the game may be using it, "
                "or the save directory may be unavailable. Check the log before saving.", win);
    }
    atexit(memcard_shutdown);
    if (
#ifdef A2_NATIVE_RESOURCES
        !a2_profile_resources() &&
#endif
        !cd_open_image(image)) {
        fprintf(stderr, "cannot open disc image %s\n", image);
        return 1;
    }
    cd_boot_handoff();
    long n = 0;
    uint8_t *exe = cd_read_file("SCPS_101.15", &n);
    if (!exe || n < 0x800 || memcmp(exe, "PS-X EXE", 8) != 0) {
        fprintf(stderr, "Invalid or missing SCPS_101.15 in %s\n", root);
        free(exe);
        return 1;
    }
    uint32_t pc0, gp0, t_addr, t_size, sp;
    memcpy(&pc0, exe + 0x10, 4);
    memcpy(&gp0, exe + 0x14, 4);
    memcpy(&t_addr, exe + 0x18, 4);
    memcpy(&t_size, exe + 0x1C, 4);
    memcpy(&sp, exe + 0x30, 4);
    uint32_t load_size = t_size > (uint32_t)n - 0x800 ? (uint32_t)n - 0x800 : t_size;
    if (load_size > PSX_RAM_SIZE - (t_addr & 0x1FFFFF)) {
        fprintf(stderr, "Game executable exceeds PS1 RAM\n");
        free(exe);
        return 1;
    }
    if (!sp) sp = 0x801FFF00;
    memcpy(PSX_RAM + (t_addr & 0x1FFFFF), exe + 0x800,
           load_size);
    free(exe);
#ifdef A2_NATIVE_RESOURCES
    if(a2_profile_resources()) {
        char error[512];
        if(!a2_native_resources_install(a2_profile_resources(),a2s.text_language,error,sizeof error) ||
           !a2_native_voice_open(a2_profile_resources(),a2s.voice_language,
                                 PSX_RAM,PSX_RAM_SIZE,error,sizeof error)) {
            fprintf(stderr,"Native game data: %s\n",error);return 1;
        }
        a2_native_voice_install();
        atexit(a2_native_resources_close);atexit(a2_native_voice_close);
    } else
#endif
    {
#ifdef A2_VOICE_ASSETS
    int allow_incomplete_japanese = a2s.voice_language == 0 &&
        getenv("A2_VOICE_LANGUAGE") && !strcmp(getenv("A2_VOICE_LANGUAGE"), "0") &&
        getenv("A2_ALLOW_INCOMPLETE_VOICES") && !strcmp(getenv("A2_ALLOW_INCOMPLETE_VOICES"), "1");
    if (!allow_incomplete_japanese) {
        char voice_path[4096];
        if (!a2_profile_voice_path(a2s.voice_language, voice_path, sizeof voice_path) ||
            !a2_voice_open_for_language(voice_path, image, PSX_RAM, PSX_RAM_SIZE, a2s.voice_language)) {
            fprintf(stderr, "Requested voice data could not be loaded (language=%d): %s\n", a2s.voice_language, a2_voice_error());
            if (strcmp(SDL_GetCurrentVideoDriver(), "dummy"))
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Алундра 2",
                    "Не удалось открыть выбранную озвучку. Проверьте данные игры или выберите доступный аудиопакет при запуске.", win);
            return 1;
        }
        atexit(a2_voice_close);
    }
#endif
    }
    R[28] = gp0;
    R[29] = R[30] = sp;
    R[4] = 1; R[5] = 0;
    printf("boot: pc=0x%08X gp=0x%08X sp=0x%08X\n", pc0, gp0, sp);
    if (getenv("A2_SQRTTEST")) {
        static const uint32_t tv[] = {0, 1, 4, 144, 65536, 0x40000, 1000000};
        for (int i = 0; i < 7; i++) {
            R[29] = 0x801FFF00;
            R[4] = tv[i];
            psx_call(0x80035C48u);
            printf("SquareRoot0(%u) = %u\n", tv[i], R[2]);
        }
        exit(0);
    }

    void psx_run(uint32_t entry);
#ifdef A2_WORLD_PRECISION
    /* Preserve fractional camera motion in ordinary launches as well as the
     * packaged app. Explicit overrides retain the original diagnostic paths. */
    const char *camera_env = getenv("A2_WORLD_CAMERA");
    const char *precision_env = getenv("A2_WORLD_PRECISION");
    const char *raster_env = getenv("A2_WORLD_RASTER");
    int camera_requested = camera_env ? atoi(camera_env) != 0 : 1;
    int precision_requested = precision_env ? atoi(precision_env) != 0 : camera_requested;
    int raster_requested = raster_env ? atoi(raster_env) != 0 : camera_requested;
    world_precision_configure(precision_requested);
    world_camera_configure(camera_requested);
#ifdef A2_NATIVE_BILLBOARD
    int billboard_depth_observer=a2_native_billboard_enabled;
    a2_native_billboard_init(PSX_RAM,sizeof PSX_RAM);
    const char *billboard_env=getenv("A2_BILLBOARD_PRECISION");
    a2_native_billboard_configure(billboard_depth_observer ||
        (world_precision_enabled && camera_requested && (!billboard_env || strcmp(billboard_env,"0"))));
#endif
    gpu_set_world_raster(world_precision_enabled && raster_requested);
    fprintf(stderr, "world-render: precision=%d camera=%d raster=%d\n",
            world_precision_enabled, world_camera_enabled,
            world_precision_enabled && raster_requested);
#endif
    a2_frame_wait_init();
    a2_phase_init();
    psx_run(pc0);
    printf("game main returned after %u frames\n", frames);
    return 0;
}

/* ---------- Phase-0 atlas smoke test (recompiled decoder) ---------- */
#define ATLAS_RAM 0x8004FDD8u
#define DECODE_DST 0x80190000u

static uint32_t rle_out_size(uint32_t stream, uint32_t max_len) {
    uint32_t i = 0, total = 0;
    while (i < max_len) {
        uint8_t c = PSX_RAM[PSX_ADDR(stream + i)]; i++;
        uint32_t ln;
        if (c & 0x40) { ln = (((c & 0x3F) << 8) | PSX_RAM[PSX_ADDR(stream + i)]) + 1; i++; }
        else ln = (c & 0x3F) + 1;
        i += (c & 0x80) ? 1 : ln;
        total += ln;
    }
    return total;
}

static int atlas(const char *root, const char *shot) {
    uint32_t pc = cd_load_exe("SCPS_101.15", PSX_RAM, 0x1FFFFF);
    if (!pc) { fprintf(stderr, "cannot load SCPS_101.15\n"); return 1; }
    uint32_t off = PSX_ADDR(ATLAS_RAM), npal, size0;
    uint16_t w, h;
    memcpy(&npal, PSX_RAM + off + 4, 4);
    memcpy(&w, PSX_RAM + off + 8, 2);
    memcpy(&h, PSX_RAM + off + 10, 2);
    memcpy(&size0, PSX_RAM + off + 12, 4);
    uint32_t clut_ram = ATLAS_RAM + 52, stream_ram = clut_ram + npal * 512;
    R[29] = 0x801FFF00;
    uint32_t out_size = rle_out_size(stream_ram, size0);
    R[4] = stream_ram - 4;
    R[5] = out_size;
    R[6] = DECODE_DST;
    R[7] = 0x801FFE00;
    psx_call(0x8001C26Cu);
    printf("atlas: decoded %u bytes via recompiled code\n", out_size);
    static uint32_t pix[256 * 144];
    uint32_t pal[16];
    for (int i = 0; i < 16; i++) {
        uint16_t c;
        memcpy(&c, PSX_RAM + PSX_ADDR(clut_ram) + i * 2, 2);
        pal[i] = 0xFF000000u | ((uint32_t)(c & 31) << 19) |
                 ((uint32_t)((c >> 5) & 31) << 11) | ((uint32_t)((c >> 10) & 31) << 3);
    }
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x += 2) {
            uint8_t b = PSX_RAM[PSX_ADDR(DECODE_DST) + ((uint32_t)y * w + x) / 2];
            pix[y * w + x] = pal[b & 15];
            pix[y * w + x + 1] = pal[b >> 4];
        }
    if (shot) {
        SDL_Surface *s = SDL_CreateRGBSurfaceWithFormatFrom(
            pix, w, h, 32, w * 4, SDL_PIXELFORMAT_ARGB8888);
        if (!s || SDL_SaveBMP(s, shot) != 0) return 1;
        printf("wrote %s\n", shot);
    }
    return 0;
}

int main(int argc, char **argv) {
    const char *root = NULL;
    const char *image = NULL, *shot = NULL;
    int do_atlas = 0, check = 0;
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--boot")) {
            if (i + 1 < argc && argv[i + 1][0] != '-') image = argv[++i];
        } else if (!strcmp(argv[i], "--atlas")) do_atlas = 1;
        else if (!strcmp(argv[i], "--check-data")) check = 1;
        else if (!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
            puts("Alundra 2 native port\nUsage: alundra2 [--boot]\n"
                 "       alundra2 --check-data\n"
                 "Legacy diagnostics: alundra2 disc_directory --boot image.bin\n"
                 "Escape/F1: pause menu; F5: save; F9: load; arrows: move; X: circle/confirm; Z: cross; Enter: start\n"
                 "A2_RESOURCE_ARCHIVE overrides the native game.a2r archive.\n"
                 "A2_USER_DIR overrides the settings and memory card directory.");
            return 0;
        }
        else if (!strcmp(argv[i], "--screenshot") && i + 1 < argc)
            shot = argv[++i];
        else if (argv[i][0] != '-' && !root) root = argv[i];
        else { fprintf(stderr, "Unknown argument: %s\n", argv[i]); return 1; }
    }
    if (getenv("A2_LOG")) {
        int v = atoi(getenv("A2_LOG"));
        kernel_log = v & 1; cd_log = (v >> 1) & 1; mmio_log = (v >> 2) & 1;
    }
    if (!a2_paths_init(root, image)) {
        fprintf(stderr, "%s\n", a2_paths.error);
        if (argc == 1 && !getenv("SDL_VIDEODRIVER"))
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Alundra 2", a2_paths.error, NULL);
        return 1;
    }
    a2_profiles_init(a2_paths.disc, a2_paths.image);
#ifdef A2_NATIVE_RESOURCES
    if(a2_paths.resources[0]) {
        if(!a2_profiles_open_native(a2_paths.resources,a2_paths.error,sizeof a2_paths.error)) {
            fprintf(stderr,"%s\n",a2_paths.error);return 1;
        }
        atexit(a2_profiles_close_native);
        cd_set_resource_store(a2_profile_resources(),0);
    }
#endif
    const char *disc_environment=getenv("A2_DISC_ROOT");
    select_saved_profile = ((!root || !*root) && (!disc_environment || !*disc_environment)) || getenv("A2_TEXT_LANGUAGE");
    show_startup_menu = argc == 1;
    const char *launcher = getenv("A2_LAUNCHER");
    if (launcher) show_startup_menu = strcmp(launcher, "0") != 0;
    if (getenv("A2_AUTO") || getenv("A2_CONTROL_FILE") || getenv("A2_FRAMES"))
        show_startup_menu = launcher && !strcmp(launcher, "1");
    cd_set_root(a2_paths.disc);
    if (check) {
#ifdef A2_NATIVE_RESOURCES
        if(a2_profile_resources()) {
            printf("Native resources: %s\nText profiles: ru=%d ja=%d en=%d\nVoices: ja=%d en=%d\nSettings and saves: %s\n",
                a2_paths.resources,a2_profile_available(0),a2_profile_available(1),a2_profile_available(2),
                a2_native_voice_available(a2_profile_resources(),0),a2_native_voice_available(a2_profile_resources(),1),a2_paths.user);
            return 0;
        }
#endif
        printf("Game data: %s\nDisc image: %s\nSettings and saves: %s\n",
               a2_paths.disc, a2_paths.image, a2_paths.user);
        return 0;
    }
    if (do_atlas) return atlas(a2_paths.disc, shot);
    int result = boot(a2_paths.disc, a2_paths.image);
    a2_input_shutdown();
    SDL_Quit();
    return result;
}
