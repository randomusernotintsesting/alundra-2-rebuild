#ifndef A2_PLATFORM_FILE_H
#define A2_PLATFORM_FILE_H

#include <stddef.h>
#include <stdint.h>

/* Read-only regular files, addressed by UTF-8 paths and absolute byte offsets.
 * Open captures the file size. The caller must keep its contents immutable;
 * later truncation/read failures still fail exact reads. There is no shared
 * seek cursor. Concurrent reads are allowed; close requires no active reads.
 * Failures leave output handles/sizes unchanged. A failed read may have copied
 * a prefix into the host buffer. Error buffers are optional and NUL-terminated.
 * Zero-length reads succeed only at offsets within the captured size, including
 * EOF. All ranges must also fit signed 64-bit OS offsets. */
typedef struct A2File A2File;

int a2_file_open_read(const char *utf8_path, A2File **out,
                      char *error, size_t error_size);
int a2_file_size(A2File *file, uint64_t *out, char *error, size_t error_size);
int a2_file_read_at(A2File *file, uint64_t offset, void *out, size_t size,
                    char *error, size_t error_size);
void a2_file_close(A2File *file);

#endif
