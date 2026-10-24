#ifndef A2_NATIVE_SAVE_STORE_H
#define A2_NATIVE_SAVE_STORE_H

#include <stddef.h>
#include <stdint.h>

#define A2_SAVE_PAYLOAD_SIZE 8192u
#define A2_SAVE_HEADER_SIZE 48u
#define A2_SAVE_VERSION 1u
#define A2_SAVE_FREE_VERSION 2u
#define A2_SAVE_EXTENSION ".a2save"

enum {
    A2_SAVE_FAILED = 0,
    A2_SAVE_OK = 1,
    A2_SAVE_PUBLISHED_UNCERTAIN = 2
};

typedef struct A2SaveMetadata {
    uint64_t utc_seconds; /* Unix epoch seconds, UTC. */
    uint32_t payload_crc32;
    uint16_t scene;
    uint16_t location_index;
} A2SaveMetadata;

/* Read returns 1 on success, 0 on failure. Error is optional; nonzero capacity is
 * always NUL-terminated. Read leaves payload and metadata unchanged on error.
 * Writes validate before replacing; the parent directory must already exist.
 * Symlink targets and nonregular files are rejected. Cooperating writers use
 * a persistent <filename>.lock; a busy target fails immediately.
 * Write returns 2 when already published but directory sync failed: callers
 * must commit the saved state and present the error as a durability warning,
 * not report an uncommitted failure. Canonical card-import filenames are
 * immutable snapshots; save progress under a new ordinary filename. */
int a2_save_read(const char *path, uint8_t payload[A2_SAVE_PAYLOAD_SIZE],
                 A2SaveMetadata *metadata, char *error, size_t error_size);
int a2_save_write(const char *path, const uint8_t payload[A2_SAVE_PAYLOAD_SIZE],
                  char *error, size_t error_size);

/* Create an ordinary save with atomic no-replace publication. Existing
 * destinations fail without changing bytes, including a racing creation.
 * The same published-but-uncertain result applies after publication. */
int a2_save_write_new(const char *path, const uint8_t payload[A2_SAVE_PAYLOAD_SIZE],
                      char *error, size_t error_size);

/* Read only user_directory/memcard1.mcr and memcard2.mcr. Missing cards are
 * allowed. Existing cards are never modified or opened for writing. Creates
 * saves_directory if absent (its parent must exist). Import is idempotent;
 * valid earlier imports remain if another entry fails. Only allocated own
 * single-block SCPS-10115 files are imported, preserving all 8192 bytes.
 * Returns 2 with a warning if an import was published with uncertain directory
 * durability; subsequent valid entries are still imported. */
int a2_save_import_cards(const char *user_directory, const char *saves_directory,
                         char *error, size_t error_size);

#endif
