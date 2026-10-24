/* The same contract fixture runs against every host backend. Test files are
 * prepared in a private working directory by scripts/test_platform_file.py. */
#include "platform_file.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    static const unsigned char binary[] = {0, 10, 13, 26, 255};
    const uint64_t high = UINT64_C(0x100000000) + 123;
    A2File *file = NULL, *large = NULL;
    char error[160];
    assert(a2_file_open_read("данные 日本 space.bin", &file, error, sizeof error));
    assert(file && !error[0]);
    uint64_t size = 999;
    assert(a2_file_size(file, &size, error, sizeof error) && size == sizeof binary);
    unsigned char bytes[8];
    memset(bytes, 0xA5, sizeof bytes);
    assert(a2_file_read_at(file, 3, bytes, 2, error, sizeof error));
    assert(bytes[0] == 26 && bytes[1] == 255 && bytes[2] == 0xA5);
    assert(a2_file_read_at(file, 0, bytes, sizeof binary, error, sizeof error));
    assert(!memcmp(bytes, binary, sizeof binary) && bytes[5] == 0xA5);
    assert(a2_file_read_at(file, 3, bytes, 2, error, sizeof error));
    assert(bytes[0] == 26 && bytes[1] == 255);
    assert(a2_file_read_at(file, size, NULL, 0, error, sizeof error));
    assert(a2_file_read_at(file, 0, NULL, 0, NULL, 0));

    const struct { uint64_t offset; size_t length; } invalid[] = {
        {5, 1}, {6, 0}, {4, 2}, {UINT64_MAX, 0}, {UINT64_MAX, 2},
        {UINT64_C(0x8000000000000000), 0}, {1, SIZE_MAX}
    };
    for (size_t i = 0; i < sizeof invalid / sizeof *invalid; ++i) {
        memset(bytes, 0xA5, sizeof bytes);
        assert(!a2_file_read_at(file, invalid[i].offset, bytes, invalid[i].length,
                                error, sizeof error));
        assert(error[0]);
        for (size_t j = 0; j < sizeof bytes; ++j) assert(bytes[j] == 0xA5);
    }
    assert(!a2_file_read_at(file, 0, NULL, 1, NULL, 0));
    assert(!a2_file_read_at(NULL, 0, bytes, 1, NULL, 0));
    size = 123;
    assert(!a2_file_size(NULL, &size, error, sizeof error) && size == 123);
    assert(!a2_file_size(file, NULL, error, sizeof error));

    /* A failed replacement must never lose the caller's existing handle. */
    A2File *unchanged = file;
    assert(!a2_file_open_read("missing.bin", &unchanged, error, sizeof error));
    assert(unchanged == file && error[0]);
    assert(!a2_file_open_read(".", &unchanged, error, sizeof error));
    assert(unchanged == file);
#ifndef _WIN32
    /* Opening a FIFO must not wait for a writer before rejecting its type. */
    assert(!a2_file_open_read("not-regular.fifo", &unchanged, error, sizeof error));
    assert(unchanged == file);
#endif
    assert(!a2_file_open_read(NULL, &unchanged, NULL, 0) && unchanged == file);
    assert(!a2_file_open_read("", &unchanged, NULL, 0) && unchanged == file);
    assert(!a2_file_open_read("large.bin", NULL, NULL, 0));
    char one = 'x';
    assert(!a2_file_open_read("missing.bin", &unchanged, &one, 1) && one == 0);

    assert(a2_file_open_read("large.bin", &large, error, sizeof error));
    assert(a2_file_size(large, &size, error, sizeof error) && size == high + sizeof binary);
    assert(a2_file_read_at(large, high, bytes, sizeof binary, error, sizeof error));
    assert(!memcmp(bytes, binary, sizeof binary));
    assert(a2_file_read_at(large, 0, bytes, 3, error, sizeof error));
    assert(bytes[0] == 0 && bytes[1] == 0 && bytes[2] == 0);
    assert(a2_file_read_at(large, high, bytes, sizeof binary, error, sizeof error));
    assert(!memcmp(bytes, binary, sizeof binary));
    assert(a2_file_read_at(large, size, NULL, 0, error, sizeof error));
    assert(!a2_file_read_at(large, size, bytes, 1, error, sizeof error));
    a2_file_close(large);
    a2_file_close(file);
    a2_file_close(NULL);
    puts("platform file contract: PASS");
    return 0;
}
