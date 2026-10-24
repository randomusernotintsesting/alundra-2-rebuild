# Shared production sources. Platform adapters are selected by the root target.
# Generated modules/assets are immutable build inputs, never regenerated per OS.
file(GLOB A2_GENERATED_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/../gen/*.c")
set(A2_CORE_SOURCES
    src/dispatch.c src/interp.c src/pad_hle.c src/kernel_hle.c src/mmio.c
    src/gpu.c src/gte.c src/world_precision.c src/world_shadow.c src/hud_present.c src/native_actor_snapshot.c
    src/native_model.c src/native_actor_packets.c src/native_actor_sources.c src/native_billboard.c src/dialogue_packets.c
    src/hd_font.c src/hd_ui.c src/hd_art.c src/hd_portraits.c
    src/a2_resources.c src/native_resources_guest.c src/native_voice.c
    src/voice_assets.c src/xa_audio.c src/cdrom.c src/cd_hle.c
    src/game_profiles.c src/game_locale.c src/startup_qol.c src/native_save_guest.c
    src/native_save_store.c ${A2_GENERATED_SOURCES})
set(A2_HOST_SDL_SOURCES
    src/frame_compose.c src/cinema.c src/input.c src/input_prompts.c
    src/menu_sdl.c src/menu_model.c src/save_browser_model.c src/render_capture.c
    src/phase_timing.c src/frame_wait.c src/settings.c src/paths.c
    src/memcard.c src/replay_control.c src/spu.c)

if(A2_PLATFORM_SWITCH)
    list(APPEND A2_CORE_SOURCES src/platform/file_switch.c)
elseif(WIN32)
    list(APPEND A2_CORE_SOURCES src/platform/file_windows.c)
elseif(UNIX)
    list(APPEND A2_CORE_SOURCES src/platform/file_posix.c)
else()
    message(FATAL_ERROR "No read-only file backend for this platform")
endif()
