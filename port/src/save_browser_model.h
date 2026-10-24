#ifndef A2_SAVE_BROWSER_MODEL_H
#define A2_SAVE_BROWSER_MODEL_H
#include "native_save_store.h"

/* Host-independent save-list data. Strings are owned by the browser. */
typedef struct A2SaveBrowserRow {
    char *path;
    char *filename;
    A2SaveMetadata metadata;
    uint16_t hours, minutes, ticks;
    int valid, imported, fresh;
} A2SaveBrowserRow;

typedef struct A2SaveBrowser {
    A2SaveBrowserRow *rows;
    size_t count;
    char *directory;
    int saving;
    int import_result;
    char import_warning[1024];
} A2SaveBrowser;

/* Initialize with {0}. Open imports the previous cards through the native
 * store, then lists valid and unavailable rows; save mode adds New save first.
 * Import warnings do not hide earlier valid saves. Dispose before reopening. */
int a2_save_browser_open(A2SaveBrowser *browser, const char *user_directory,
                         int saving, char *error, size_t error_size);
void a2_save_browser_dispose(A2SaveBrowser *browser);

/* The UI confirms replacement or imported-copy creation before this call.
 * Returns the store's FAILED / OK / PUBLISHED_UNCERTAIN result. A failed load
 * leaves payload unchanged. Imported snapshots always create a new file. */
int a2_save_browser_accept(A2SaveBrowser *browser, size_t index,
                           uint8_t payload[A2_SAVE_PAYLOAD_SIZE],
                           char *error, size_t error_size);

/* Language 0=RU, 1=JA, 2=EN. Other values select RU. All output buffers with
 * nonzero capacity are NUL-terminated. Date uses the local timezone. */
const char *a2_save_browser_location(uint16_t index, int language);
void a2_save_browser_title(const A2SaveBrowserRow *row, int language,
                           char *out, size_t size);
void a2_save_browser_date(const A2SaveBrowserRow *row, int language,
                          char *out, size_t size);
void a2_save_browser_playtime(const A2SaveBrowserRow *row, int language,
                              char *out, size_t size);
/* Existing quick-save validation strings are translated here so every host
 * presents the same detail. Unknown nonempty messages remain intact. */
int a2_save_browser_durability_warning(const char *message);
void a2_save_browser_error_text(const char *message, int language,
                                char *out, size_t size);
#endif
