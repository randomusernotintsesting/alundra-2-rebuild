#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include "platform_file.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

_Static_assert(SIZE_MAX <= UINT64_MAX, "File lengths must fit uint64_t");
struct A2File { HANDLE handle; uint64_t size; };

static void clear_error(char *error, size_t size) {
    if (error && size) error[0] = 0;
}
static int failure(char *error, size_t size, const char *message) {
    if (error && size) snprintf(error, size, "%s", message);
    return 0;
}
static int os_failure(char *error, size_t size, const char *message, DWORD code) {
    if (error && size) snprintf(error, size, "%s (Windows error %lu)", message, (unsigned long)code);
    return 0;
}

int a2_file_open_read(const char *path, A2File **out, char *error, size_t size) {
    clear_error(error, size);
    if (!path || !*path || !out) return failure(error, size, "Invalid file-open arguments");
    size_t length = strlen(path);
    if (length >= INT_MAX) return failure(error, size, "File path is too long");
    int count = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, path, (int)length + 1, NULL, 0);
    if (!count) return os_failure(error, size, "Cannot decode UTF-8 file path", GetLastError());
    if ((size_t)count > SIZE_MAX / sizeof(WCHAR)) return failure(error, size, "File path is too long");
    WCHAR *wide = malloc((size_t)count * sizeof *wide);
    if (!wide) return failure(error, size, "Cannot allocate file path");
    if (MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, path, (int)length + 1, wide, count) != count) {
        DWORD code = GetLastError();
        free(wide);
        return os_failure(error, size, "Cannot decode UTF-8 file path", code);
    }
    /* Explicit OVERLAPPED offsets never share or move a file cursor. Sharing
     * modes mirror POSIX: the immutable-resource contract belongs to callers;
     * an external truncation still produces a failed exact read. */
    HANDLE handle = CreateFileW(wide, GENERIC_READ,
                                FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                                NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
    DWORD open_code = GetLastError();
    free(wide);
    if (handle == INVALID_HANDLE_VALUE) return os_failure(error, size, "Cannot open read-only file", open_code);
    BY_HANDLE_FILE_INFORMATION info;
    LARGE_INTEGER length64;
    if (GetFileType(handle) != FILE_TYPE_DISK) {
        CloseHandle(handle);
        return failure(error, size, "Expected a regular disk file");
    }
    if (!GetFileInformationByHandle(handle, &info) || !GetFileSizeEx(handle, &length64)) {
        DWORD code = GetLastError();
        CloseHandle(handle);
        return os_failure(error, size, "Cannot determine file size", code);
    }
    if ((info.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) || length64.QuadPart < 0) {
        CloseHandle(handle);
        return failure(error, size, "Expected a regular file with a signed 64-bit size");
    }
    A2File *file = malloc(sizeof *file);
    if (!file) { CloseHandle(handle); return failure(error, size, "Cannot allocate file handle"); }
    file->handle = handle;
    file->size = (uint64_t)length64.QuadPart;
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
    if (!length) return 1;
    HANDLE event = CreateEventW(NULL, TRUE, FALSE, NULL);
    if (!event) return os_failure(error, size, "Cannot create file-read event", GetLastError());
    unsigned char *p = out;
    while (length) {
        /* Bounded OS requests also avoid narrowing an arbitrary size_t to DWORD. */
        DWORD amount = length > 1024u * 1024u ? 1024u * 1024u : (DWORD)length;
        OVERLAPPED operation = {0};
        operation.Offset = (DWORD)offset;
        operation.OffsetHigh = (DWORD)(offset >> 32);
        operation.hEvent = event;
        if (!ResetEvent(event)) {
            DWORD code = GetLastError();
            CloseHandle(event);
            return os_failure(error, size, "Cannot reset file-read event", code);
        }
        BOOL submitted = ReadFile(file->handle, p, amount, NULL, &operation);
        DWORD code = submitted ? ERROR_SUCCESS : GetLastError();
        if (!submitted && code != ERROR_IO_PENDING) {
            CloseHandle(event);
            return os_failure(error, size, "Cannot read file", code);
        }
        DWORD count = 0;
        /* Complete every accepted operation before reusing its stack/buffer or
         * returning, including the immediate-success case. */
        if (!GetOverlappedResult(file->handle, &operation, &count, TRUE)) {
            code = GetLastError();
            CloseHandle(event);
            return os_failure(error, size, "Cannot complete file read", code);
        }
        if (!count || count > amount) {
            CloseHandle(event);
            return failure(error, size, "Unexpected byte count during exact file read");
        }
        p += count;
        length -= count;
        offset += count;
    }
    CloseHandle(event);
    return 1;
}

void a2_file_close(A2File *file) {
    if (!file) return;
    CloseHandle(file->handle);
    free(file);
}
