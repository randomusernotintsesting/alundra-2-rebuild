#define _POSIX_C_SOURCE 200809L
#ifdef __APPLE__
#define _DARWIN_C_SOURCE
#endif
#include "save_browser_model.h"
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

static char root[] = "/tmp/a2-save-browser-test.XXXXXX";
static char error[1024];
static void join(char out[1024], const char *a, const char *b) {
    assert(snprintf(out, 1024, "%s/%s", a, b) < 1024);
}
static void user_directory(char out[1024], const char *name) {
    join(out, root, name); assert(!mkdir(out, 0700));
}
static void put16(uint8_t *p, unsigned value) { p[0] = value; p[1] = value >> 8; }
static void fixture_payload(uint8_t out[8192], unsigned marker) {
    memset(out, 0, 8192); memcpy(out, "SC\x11\x01", 4);
    out[4] = marker; out[0xc14] = 14;
    put16(out + 0x104, 12); put16(out + 0x106, 34); put16(out + 0x108, 3599);
    put16(out + 0xd8c, 0x4472 + marker + 12 + 34 + 3599);
    out[8191] = marker ^ 0x5a;
}
static void bytes_write(const char *path, const void *bytes, size_t size) {
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0600); assert(fd >= 0);
    assert(write(fd, bytes, size) == (ssize_t)size); assert(!close(fd));
}
static void timestamp(const char *path, uint64_t seconds) {
    uint8_t bytes[8]; for (unsigned i = 0; i < 8; i++) bytes[i] = seconds >> (i * 8);
    int fd = open(path, O_WRONLY); assert(fd >= 0);
    assert(pwrite(fd, bytes, sizeof bytes, 24) == sizeof bytes); assert(!close(fd));
}
static void cleanup(const char *path) {
    struct stat st; assert(!lstat(path, &st));
    if (!S_ISDIR(st.st_mode)) { assert(!unlink(path)); return; }
    DIR *directory = opendir(path); assert(directory); struct dirent *entry;
    while ((entry = readdir(directory))) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) continue;
        char child[1024]; join(child, path, entry->d_name); cleanup(child);
    }
    assert(!closedir(directory)); assert(!rmdir(path));
}
static size_t row_index(const A2SaveBrowser *browser, const char *name) {
    for (size_t i = 0; i < browser->count; i++) if (!strcmp(browser->rows[i].filename, name)) return i;
    assert(!"Missing expected save-list entry"); return 0;
}
static void empty_lists_and_new_save(void) {
    char directory[1024], text[1024]; user_directory(directory, "empty");
    A2SaveBrowser browser = {0};
    assert(a2_save_browser_open(&browser, directory, 0, error, sizeof error));
    assert(browser.count == 0 && browser.import_result == A2_SAVE_OK);
    a2_save_browser_dispose(&browser);
    assert(a2_save_browser_open(&browser, directory, 1, error, sizeof error));
    assert(browser.count == 1 && browser.rows[0].fresh && browser.rows[0].valid);
    a2_save_browser_title(browser.rows, 2, text, sizeof text); assert(!strcmp(text, "New save"));
    uint8_t payload[8192], got[8192]; fixture_payload(payload, 17);
    assert(a2_save_browser_accept(&browser, 0, payload, error, sizeof error) == A2_SAVE_OK);
    assert(a2_save_browser_accept(&browser, 0, payload, error, sizeof error) == A2_SAVE_OK);
    a2_save_browser_dispose(&browser);
    assert(a2_save_browser_open(&browser, directory, 0, error, sizeof error));
    assert(browser.count == 2 && strcmp(browser.rows[0].filename, browser.rows[1].filename));
    for (size_t i = 0; i < browser.count; i++) {
        assert(browser.rows[i].valid && !browser.rows[i].fresh && !browser.rows[i].imported);
        assert(strlen(browser.rows[i].filename) == 43);
        assert(a2_save_browser_accept(&browser, i, got, error, sizeof error) == A2_SAVE_OK);
        assert(!memcmp(payload, got, sizeof got));
    }
    a2_save_browser_dispose(&browser); a2_save_browser_dispose(&browser);
}
static void enumeration_sorting_and_unavailable_rows(void) {
    char directory[1024], saves[1024], path[1024], target[1024]; user_directory(directory, "sorting");
    join(saves, directory, "Saves"); assert(!mkdir(saves, 0700));
    uint8_t payload[8192]; fixture_payload(payload, 3);
    const char *names[] = {"c.a2save", "a.a2save", "b.A2SAVE"};
    for (unsigned i = 0; i < 3; i++) {
        join(path, saves, names[i]); assert(a2_save_write(path, payload, error, sizeof error));
        timestamp(path, i == 1 ? 1 : 2);
    }
    join(path, saves, "bad.a2save"); bytes_write(path, "broken", 6);
    join(path, saves, "named-directory.a2save"); assert(!mkdir(path, 0700));
    join(path, saves, "pipe.a2save"); assert(!mkfifo(path, 0600));
    join(path, saves, "link.a2save"); join(target, saves, "a.a2save"); assert(!symlink(target, path));
    join(path, saves, "ignored.txt"); bytes_write(path, "ignored", 7);
    A2SaveBrowser browser = {0};
    assert(a2_save_browser_open(&browser, directory, 0, error, sizeof error));
    assert(browser.count == 7);
    assert(!strcmp(browser.rows[0].filename, "b.A2SAVE"));
    assert(!strcmp(browser.rows[1].filename, "c.a2save"));
    assert(!strcmp(browser.rows[2].filename, "a.a2save"));
    for (size_t i = 3; i < browser.count; i++) assert(!browser.rows[i].valid);
    uint8_t sentinel[8192], got[8192]; memset(sentinel, 0xa5, sizeof sentinel);
    memcpy(got, sentinel, sizeof got);
    assert(!a2_save_browser_accept(&browser, row_index(&browser, "bad.a2save"), got, error, sizeof error));
    assert(!memcmp(got, sentinel, sizeof got));
    size_t index = row_index(&browser, "a.a2save");
    bytes_write(target, "changed", 7);
    assert(!a2_save_browser_accept(&browser, index, got, error, sizeof error));
    assert(error[0] && !memcmp(got, sentinel, sizeof got));
    a2_save_browser_dispose(&browser);
    /* A card warning must not hide already valid independent saves. */
    join(path, directory, "memcard1.mcr"); bytes_write(path, "bad", 3);
    assert(a2_save_browser_open(&browser, directory, 0, error, sizeof error));
    assert(browser.import_result == A2_SAVE_FAILED && browser.import_warning[0]);
    assert(browser.count == 7 && browser.rows[0].valid);
    a2_save_browser_dispose(&browser);
}
static void imported_snapshot_creates_copy_and_overwrite_is_explicit(void) {
    char directory[1024], card_path[1024]; user_directory(directory, "imports");
    uint8_t *card = calloc(131072, 1); assert(card);
    memcpy(card, "MC", 2); card[127] = 'M' ^ 'C';
    uint8_t *entry = card + 128;
    entry[0] = 0x51; entry[5] = 0x20; entry[8] = entry[9] = 0xff;
    memcpy(entry + 10, "BISCPS-1011500", 14);
    for (unsigned i = 0; i < 127; i++) entry[127] ^= entry[i];
    fixture_payload(card + 8192, 9); join(card_path, directory, "memcard1.mcr");
    bytes_write(card_path, card, 131072);
    A2SaveBrowser browser = {0};
    assert(a2_save_browser_open(&browser, directory, 1, error, sizeof error));
    assert(browser.count == 2 && browser.rows[0].fresh && browser.rows[1].imported && browser.rows[1].valid);
    char snapshot[1024]; assert(strlen(browser.rows[1].path) < sizeof snapshot); strcpy(snapshot, browser.rows[1].path);
    uint8_t second[8192], third[8192], got[8192]; fixture_payload(second, 19); fixture_payload(third, 29);
    assert(a2_save_browser_accept(&browser, 1, second, error, sizeof error) == A2_SAVE_OK);
    assert(a2_save_read(snapshot, got, NULL, error, sizeof error));
    assert(!memcmp(got, card + 8192, sizeof got));
    int fd = open(card_path, O_RDONLY); assert(fd >= 0);
    uint8_t *readback = malloc(131072); assert(readback);
    assert(read(fd, readback, 131072) == 131072 && !memcmp(card, readback, 131072)); assert(!close(fd));
    free(readback); free(card);
    a2_save_browser_dispose(&browser);
    assert(a2_save_browser_open(&browser, directory, 1, error, sizeof error));
    assert(browser.count == 3);
    size_t ordinary = browser.rows[1].imported ? 2 : 1;
    assert(!browser.rows[ordinary].imported && !browser.rows[ordinary].fresh);
    assert(a2_save_browser_accept(&browser, ordinary, third, error, sizeof error) == A2_SAVE_OK);
    assert(a2_save_read(browser.rows[ordinary].path, got, NULL, error, sizeof error));
    assert(!memcmp(third, got, sizeof got));
    assert(a2_save_read(snapshot, got, NULL, error, sizeof error));
    assert(got[4] == 9);
    a2_save_browser_dispose(&browser);
}
static void localized_metadata_and_boundaries(void) {
    assert(!setenv("TZ", "UTC", 1)); tzset();
    A2SaveBrowserRow row = {0}; row.valid = 1; row.hours = 12; row.minutes = 34; row.ticks = 3599;
    char text[1024];
    assert(!strcmp(a2_save_browser_location(0, 0), "Каюта"));
    assert(!strcmp(a2_save_browser_location(0, 1), "飛空艇船長室"));
    assert(!strcmp(a2_save_browser_location(0, 2), "Cabin"));
    assert(!strcmp(a2_save_browser_location(40, 2), "Unknown location"));
    for (unsigned language = 0; language < 3; language++)
        for (unsigned i = 0; i < 40; i++) assert(*a2_save_browser_location(i, language));
    a2_save_browser_playtime(&row, 2, text, sizeof text); assert(!strcmp(text, "12 h 34 min"));
    a2_save_browser_playtime(&row, 1, text, sizeof text); assert(!strcmp(text, "12時間34分"));
    row.ticks = 3600; a2_save_browser_playtime(&row, 0, text, sizeof text); assert(!strcmp(text, "Неизвестно"));
    row.ticks = 0; row.minutes = 60; a2_save_browser_playtime(&row, 2, text, sizeof text); assert(!strcmp(text, "Unknown"));
    row.minutes = 0; row.hours = 100; a2_save_browser_playtime(&row, 2, text, sizeof text); assert(!strcmp(text, "Unknown"));
    row.imported = 1;
    a2_save_browser_title(&row, 2, text, sizeof text); assert(!strcmp(text, "Cabin\nPrevious save"));
    a2_save_browser_date(&row, 2, text, sizeof text); assert(!strcmp(text, "Imported Jan 1, 1970, 00:00"));
    a2_save_browser_date(&row, 1, text, sizeof text); assert(!strcmp(text, "移行日時: 1970年1月1日 00:00"));
    row.metadata.utc_seconds = UINT64_MAX;
    a2_save_browser_date(&row, 2, text, sizeof text); assert(!strcmp(text, "Unknown date"));
    row.metadata.location_index=0xffff;row.metadata.scene=410;row.filename="quick.a2save";
    a2_save_browser_title(&row,2,text,sizeof text);assert(!strcmp(text,"Quick save"));
    a2_save_browser_title(&row,0,text,sizeof text);assert(!strcmp(text,"Быстрое сохранение"));
    row.filename="named.a2save";
    a2_save_browser_title(&row,2,text,sizeof text);assert(!strcmp(text,"Saved game"));
    char tiny[2] = {'x','z'}; a2_save_browser_title(&row, 0, tiny, 1); assert(!tiny[0] && tiny[1] == 'z');
    row.valid = 0; row.filename = "broken.a2save";
    a2_save_browser_title(&row, 2, text, sizeof text); assert(!strcmp(text, "Unavailable save"));
    a2_save_browser_date(&row, 2, text, sizeof text); assert(!strcmp(text, "broken.a2save"));
}
static void localized_save_errors(void) {
    char text[1024];
    a2_save_browser_error_text("В сохранении повреждены настройки звука.", 2, text, sizeof text);
    assert(!strcmp(text, "The save contains damaged sound settings. Choose another save."));
    a2_save_browser_error_text("Сейчас действие недоступно. Подробность.", 1, text, sizeof text);
    assert(strstr(text, "今はこの操作を利用できません。"));
    assert(a2_save_browser_durability_warning("Save was published, but directory sync failed: IO"));
    assert(a2_save_browser_durability_warning("Save was published, but temporary cleanup failed: IO"));
    a2_save_browser_error_text("Save was published, but directory sync failed: IO", 2, text, sizeof text);
    assert(strstr(text, "The save is available to load"));
    a2_save_browser_error_text("Сохранение доступно у точек сохранения. Дополнение.", 0, text, sizeof text);
    assert(!strcmp(text, "Сохранение доступно у точек сохранения. Дополнение."));
    a2_save_browser_error_text(NULL, 2, text, sizeof text);
    assert(!strcmp(text, "The save operation could not be completed."));
    a2_save_browser_error_text("Unknown detail", 2, text, sizeof text);
    assert(!strcmp(text, "Unknown detail"));
}
static void directory_symlinks_are_rejected(void) {
    char directory[1024], actual[1024], linked[1024]; user_directory(directory, "symlink-parent");
    join(actual, directory, "real"); assert(!mkdir(actual, 0700));
    join(linked, directory, "Saves"); assert(!symlink(actual, linked));
    A2SaveBrowser browser = {0};
    assert(!a2_save_browser_open(&browser, directory, 0, error, sizeof error));
    assert(error[0] && !browser.rows && !browser.directory);
}
int main(void) {
    assert(mkdtemp(root));
    empty_lists_and_new_save();
    enumeration_sorting_and_unavailable_rows();
    imported_snapshot_creates_copy_and_overwrite_is_explicit();
    localized_metadata_and_boundaries();
    localized_save_errors();
    directory_symlinks_are_rejected();
    cleanup(root);
    puts("save browser: native import, deterministic list, safe acceptance and localized metadata passed");
    return 0;
}
