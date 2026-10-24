/* Whole-file startup/atlas reads; gameplay uses native_resources_guest.c. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "cd_hle.h"
#ifdef A2_WORLD_PRECISION
#include "psx_rt.h"
#endif

static char g_root[1024];
#ifdef A2_NATIVE_RESOURCES
static A2Resources *resource_store;
static int resource_language;
void cd_set_resource_store(A2Resources *store,int language) {
    resource_store=store;resource_language=language;
}
#endif

void cd_set_root(const char *root) {
    snprintf(g_root, sizeof g_root, "%s", root);
}

uint8_t *cd_read_file(const char *name, long *size) {
#ifdef A2_NATIVE_RESOURCES
    if(resource_store) {
        A2ResourceId id=a2_resource_find(resource_store,resource_language,name);
        uint64_t length=id?a2_resource_size(resource_store,id):0;
        if(!id || length>LONG_MAX || length>SIZE_MAX)return NULL;
        uint8_t *data=malloc(length?(size_t)length:1);char error[256];
        if(!data)return NULL;
        if(!a2_resource_pread(resource_store,id,0,data,(size_t)length,error,sizeof error)) {
            fprintf(stderr,"native-resource: %s: %s\n",name,error);free(data);return NULL;
        }
        if(size)*size=(long)length;return data;
    }
#endif
    char path[1280];
    snprintf(path, sizeof path, "%s/%s", g_root, name);
    FILE *f = fopen(path, "rb");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    long n = ftell(f);
    fseek(f, 0, SEEK_SET);
    uint8_t *buf = malloc(n);
    if (fread(buf, 1, n, f) != (size_t)n) { fclose(f); free(buf); return NULL; }
    fclose(f);
    if (size) *size = n;
    return buf;
}

/* Load a PS-X EXE into emulated RAM; returns initial PC (0 on error). */
uint32_t cd_load_exe(const char *name, uint8_t *ram, uint32_t ram_mask) {
    long n = 0;
    uint8_t *exe = cd_read_file(name, &n);
    if (!exe || n < 0x800 || memcmp(exe, "PS-X EXE", 8) != 0) {
        free(exe);
        return 0;
    }
    uint32_t pc0, t_addr, t_size;
    memcpy(&pc0, exe + 0x10, 4);
    memcpy(&t_addr, exe + 0x18, 4);
    memcpy(&t_size, exe + 0x1C, 4);
    if (t_size > n - 0x800) t_size = (uint32_t)(n - 0x800);
#ifdef A2_WORLD_PRECISION
    /* EXE/overlay replacement cannot retain provenance from old RAM. */
    if (ram==PSX_RAM) psx_precision_invalidate(t_addr & ram_mask,t_size);
#endif
    memcpy(ram + (t_addr & ram_mask), exe + 0x800, t_size);
    free(exe);
    return pc0;
}
