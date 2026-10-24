#ifndef A2_NATIVE_MENU_MACOS_H
#define A2_NATIVE_MENU_MACOS_H
#include "host_ui.h"
/* Main-thread modal; caller suspends guest/audio and handles input release.
 * a2s is updated only when the panel closes; values are persisted by caller. */
int a2_macos_game_menu(int startup,int can_save,int can_load);
#endif
