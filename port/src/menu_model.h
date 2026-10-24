#ifndef A2_MENU_MODEL_H
#define A2_MENU_MODEL_H
#include "settings.h"
#include "host_ui.h"
typedef enum { A2_MENU_TEXT, A2_MENU_VOICE, A2_MENU_PORTRAITS, A2_MENU_MODELS, /* retired, no-op */
    A2_MENU_DISPLAY, A2_MENU_IR, A2_MENU_FILTER, A2_MENU_CINEMA,
    A2_MENU_SOUND, A2_MENU_VOLUME, A2_MENU_THRESHOLD, A2_MENU_ANTIALIAS, A2_MENU_FILL_SCREEN, A2_MENU_SUBTITLES, A2_MENU_SKIP_INTRO,
    A2_MENU_ENGLISH_SUBTITLE_LANGUAGE } A2MenuSetting;
typedef struct {
    A2Settings original, draft;
    int startup, can_save, can_load;
    unsigned text_available, voice_available;
} A2MenuModel;
void a2_menu_model_init(A2MenuModel *,const A2Settings *,int startup,int can_save,int can_load,
                        unsigned text_available,unsigned voice_available);
int a2_menu_model_available(const A2MenuModel *);
int a2_menu_model_restart(const A2MenuModel *);
int a2_menu_model_change(A2MenuModel *,A2MenuSetting,int direction);
int a2_menu_model_key(A2MenuModel *,int bit,int scancode);
int a2_menu_model_pad(A2MenuModel *,int bit,int slot,A2PadBinding);
/* Returns false for unavailable actions; never modifies output on rejection. */
int a2_menu_model_finish(const A2MenuModel *,int action,A2Settings *out);
#endif
