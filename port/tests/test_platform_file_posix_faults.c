#define _FILE_OFFSET_BITS 64
#define _POSIX_C_SOURCE 200809L
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int mode, calls;
static off_t offsets[8];
static ssize_t injected_pread(int fd, void *out, size_t size, off_t offset) {
    assert(calls < 8);
    offsets[calls++] = offset;
    if (mode == 1 && calls == 1) { errno = EINTR; return -1; }
    if (mode == 2 && calls == 2) { errno = EIO; return -1; }
    if (mode == 3) return 0;
    return pread(fd, out, size > 2 ? 2 : size, offset);
}
#define pread injected_pread
#include "../src/platform/file_posix.c"
#undef pread

int main(void) {
    A2File *file = NULL;
    char error[160];
    const unsigned char expected[] = {0, 10, 13, 26, 255};
    unsigned char out[8];
    assert(a2_file_open_read("данные 日本 space.bin", &file, error, sizeof error));
    mode = 1; calls = 0;
    assert(a2_file_read_at(file, 0, out, 5, error, sizeof error));
    assert(!memcmp(out, expected, 5));
    assert(calls == 4 && offsets[0] == 0 && offsets[1] == 0 && offsets[2] == 2 && offsets[3] == 4);

    mode = 2; calls = 0; memset(out, 0xA5, sizeof out);
    assert(!a2_file_read_at(file, 0, out, 5, error, sizeof error));
    assert(calls == 2 && offsets[1] == 2 && error[0]);
    assert(!memcmp(out, expected, 2));
    for (unsigned i = 2; i < sizeof out; ++i) assert(out[i] == 0xA5);
    mode = 3; calls = 0;
    assert(!a2_file_read_at(file, 0, out, 5, error, sizeof error) && calls == 1);
    calls = 0;
    assert(!a2_file_read_at(file, UINT64_MAX - 1, out, 5, error, sizeof error));
    assert(!a2_file_read_at(file, 4, out, 2, error, sizeof error));
    assert(a2_file_read_at(file, 5, NULL, 0, error, sizeof error));
    assert(calls == 0);

    /* A real change after open cannot turn a partial read into success. */
    int writer = open("данные 日本 space.bin", O_WRONLY);
    assert(writer >= 0 && ftruncate(writer, 3) == 0);
    close(writer);
    mode = 0; calls = 0; memset(out, 0xA5, sizeof out);
    assert(!a2_file_read_at(file, 0, out, 5, error, sizeof error));
    assert(calls == 3 && !memcmp(out, expected, 3) && out[3] == 0xA5);
    a2_file_close(file);
    puts("POSIX interrupted/short/failed reads: PASS");
    return 0;
}
