#ifndef _FILE_OFFSET_BITS
#define _FILE_OFFSET_BITS 64
#endif
#define _POSIX_C_SOURCE 200809L
#include "platform_file.h"
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

_Static_assert(sizeof(off_t) >= 8, "File backend requires 64-bit off_t");
_Static_assert(SIZE_MAX <= UINT64_MAX, "File lengths must fit uint64_t");

struct A2File { int fd; uint64_t size; };

static void clear_error(char *error, size_t size) {
    if (error && size) error[0] = 0;
}
static int failure(char *error, size_t size, const char *message) {
    if (error && size) snprintf(error, size, "%s", message);
    return 0;
}
static int os_failure(char *error, size_t size, const char *message, int code) {
    if (error && size) snprintf(error, size, "%s: %s", message, strerror(code));
    return 0;
}

int a2_file_open_read(const char *path, A2File **out, char *error, size_t size) {
    clear_error(error, size);
    if (!path || !*path || !out) return failure(error, size, "Invalid file-open arguments");
    /* Reject FIFOs via fstat without waiting for a writer during open. This
     * flag has no effect on regular-file pread operations. */
    int flags = O_RDONLY | O_NONBLOCK;
#ifdef O_CLOEXEC
    flags |= O_CLOEXEC;
#endif
    int fd;
    do { fd = open(path, flags); } while (fd < 0 && errno == EINTR);
    if (fd < 0) return os_failure(error, size, "Cannot open read-only file", errno);
    struct stat st;
    int status;
    do { status = fstat(fd, &st); } while (status < 0 && errno == EINTR);
    if (status < 0) {
        int code = errno;
        close(fd);
        return os_failure(error, size, "Cannot determine file size", code);
    }
    if (!S_ISREG(st.st_mode) || st.st_size < 0 || (uint64_t)st.st_size > INT64_MAX) {
        close(fd);
        return failure(error, size, "Expected a regular file with a signed 64-bit size");
    }
    A2File *file = malloc(sizeof *file);
    if (!file) { close(fd); return failure(error, size, "Cannot allocate file handle"); }
    file->fd = fd;
    file->size = (uint64_t)st.st_size;
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
    while (length) {
        size_t amount = length > (size_t)SSIZE_MAX ? (size_t)SSIZE_MAX : length;
        ssize_t count = pread(file->fd, p, amount, (off_t)offset);
        if (count < 0 && errno == EINTR) continue;
        if (count < 0) return os_failure(error, size, "Cannot read file", errno);
        if (!count) return failure(error, size, "Unexpected end of file during exact read");
        p += (size_t)count;
        length -= (size_t)count;
        offset += (uint64_t)count;
    }
    return 1;
}

void a2_file_close(A2File *file) {
    if (!file) return;
    /* Do not retry close(EINTR): the descriptor may already have been released. */
    close(file->fd);
    free(file);
}
