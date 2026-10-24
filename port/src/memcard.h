#ifndef A2_MEMCARD_H
#define A2_MEMCARD_H
#include <stdint.h>
/* Two raw 128 KiB .mcr images. Directory must already exist. Returns 1 if
 * both slots are available, 0 otherwise; unavailable slots report I/O errors.
 * NULL uses A2_USER_DIR; no implicit current-directory or volatile saves. */
int memcard_init(const char *directory);
void memcard_shutdown(void);
/* Handles only memory-card BIOS functions; result is written to R[2]. */
int memcard_bios(uint32_t table, uint32_t num);
#endif
