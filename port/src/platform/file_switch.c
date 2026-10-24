/* libnx fsdev must already be mounted and remain mounted until close. The
 * archive lives on sdmc (or another fsdev filesystem), not romfs devoptab. */
#include <switch.h>
#include "platform_file.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

_Static_assert(sizeof(s64) == 8, "libnx file offsets must be signed 64-bit");
_Static_assert(SIZE_MAX <= UINT64_MAX, "File lengths must fit uint64_t");
struct A2File { FsFile handle; uint64_t size; };

static void clear_error(char *error, size_t size) {
    if (error && size) error[0] = 0;
}
static int failure(char *error, size_t size, const char *message) {
    if (error && size) snprintf(error, size, "%s", message);
    return 0;
}
static int fs_failure(char *error, size_t size, const char *message, Result code) {
    if (error && size) snprintf(error, size, "%s (libnx result 0x%08lx)", message, (unsigned long)code);
    return 0;
}

int a2_file_open_read(const char *path, A2File **out, char *error, size_t size) {
    clear_error(error, size);
    if (!path || !*path || !out) return failure(error, size, "Invalid file-open arguments");
    FsFileSystem *device = NULL;
    char translated[FS_MAX_PATH] = {0};
    /* TranslatePath validates UTF-8 and path bounds using the mounted fsdev;
     * the service requires a full FS_MAX_PATH input buffer. */
    if (fsdevTranslatePath(path, &device, translated) < 0 || !device) {
        if (error && size) snprintf(error, size, "Cannot resolve mounted file path: %s", strerror(errno));
        return 0;
    }
    FsDirEntryType type;
    Result result = fsFsGetEntryType(device, translated, &type);
    if (R_FAILED(result)) return fs_failure(error, size, "Cannot inspect file", result);
    if (type != FsDirEntryType_File) return failure(error, size, "Expected a regular file");
    FsFile handle;
    result = fsFsOpenFile(device, translated, FsOpenMode_Read, &handle);
    if (R_FAILED(result)) return fs_failure(error, size, "Cannot open read-only file", result);
    s64 length;
    result = fsFileGetSize(&handle, &length);
    if (R_FAILED(result)) {
        fsFileClose(&handle);
        return fs_failure(error, size, "Cannot determine file size", result);
    }
    if (length < 0) {
        fsFileClose(&handle);
        return failure(error, size, "Expected a signed 64-bit file size");
    }
    A2File *file = malloc(sizeof *file);
    if (!file) { fsFileClose(&handle); return failure(error, size, "Cannot allocate file handle"); }
    file->handle = handle;
    file->size = (uint64_t)length;
    *out = file;
    return 1;
}

int a2_file_size(A2File *file, uint64_t *out, char *error, size_t size) {
    clear_error(error, size);
    if (!file || !out) return failure(error, size, "Invalid file-size arguments");
    *out = file->size;
    return 1;
}

int a2_file_read_at(A2File *file, uint64_t offset, void *out, size_t length,
                    char *error, size_t size) {
    clear_error(error, size);
    if (!file || (!out && length)) return failure(error, size, "Invalid file-read arguments");
    if (offset > INT64_MAX || (uint64_t)length > (uint64_t)INT64_MAX - offset ||
        offset > file->size || (uint64_t)length > file->size - offset)
        return failure(error, size, "File-read range exceeds file or signed 64-bit offsets");
    unsigned char *p = out;
    unsigned char staging[0x1000];
    int use_staging = 0;
    while (length) {
        size_t limit = use_staging ? sizeof staging : 1024u * 1024u;
        size_t amount = length > limit ? limit : length;
        u64 count = 0;
        Result result = fsFileRead(&file->handle, (s64)offset, use_staging ? staging : p,
                                   (u64)amount, FsReadOption_None, &count);
        /* libnx fsdev_read uses the same bounded stack-buffer recovery when
         * the service cannot map a destination memory region (0xD401). */
        if (!use_staging && R_VALUE(result) == 0xD401) { use_staging = 1; continue; }
        if (R_FAILED(result)) return fs_failure(error, size, "Cannot read file", result);
        if (!count || count > amount) return failure(error, size, "Unexpected byte count during exact file read");
        if (use_staging) memcpy(p, staging, (size_t)count);
        p += (size_t)count;
        length -= (size_t)count;
        offset += count;
    }
    return 1;
}

void a2_file_close(A2File *file) {
    if (!file) return;
    fsFileClose(&file->handle);
    free(file);
}
