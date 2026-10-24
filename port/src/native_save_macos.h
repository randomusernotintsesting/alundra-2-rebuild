#ifndef A2_NATIVE_SAVE_MACOS_H
#define A2_NATIVE_SAVE_MACOS_H
#include <stddef.h>
#include <stdint.h>
/* Main-thread modal UI. Caller owns guest/audio suspension and focus restore.
 * Payload is changed only after a successful read. Cancel clears error. */
int a2_macos_save_browser(const char *userdir, int saving, uint8_t payload[8192],
                          char *error, size_t error_size);
void a2_macos_save_error(const char *message);
#endif
