#ifndef CD_HLE_H
#define CD_HLE_H
#include <stdint.h>
#ifdef A2_NATIVE_RESOURCES
#include "a2_resources.h"
void cd_set_resource_store(A2Resources *store,int language);
#endif

void cd_set_root(const char *root);
uint8_t *cd_read_file(const char *name, long *size);
uint32_t cd_load_exe(const char *name, uint8_t *ram, uint32_t ram_mask);

#endif
