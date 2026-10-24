#define _POSIX_C_SOURCE 200809L
#ifdef __APPLE__
#define _DARWIN_C_SOURCE
#endif
#include "save_browser_model.h"
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

static const char *const locations_ru[40] = {
    "Каюта",
    "Пако",
    "Каюта 2",
    "Пако 2",
    "Гю-Йорк",
    "Бык 2",
    "Уэброк 1",
    "Гавань",
    "Пуэрто",
    "Мерседес 1",
    "Пещера",
    "Ванилла",
    "Гвабакакао",
    "Салон",
    "Обломки",
    "Чайка 2",
    "Эдем 1",
    "Эдем 2",
    "Церковь",
    "Огнедрак",
    "Дракон 1",
    "Гробница 2",
    "Нунуги",
    "Ключ 1",
    "Ключ 2",
    "Кит 2",
    "Эдем",
    "Церковь 2",
    "Мерседес 2",
    "Темница",
    "Кит 1",
    "Чайка 1",
    "Мерседес 3",
    "Бык 1",
    "Гробница 1",
    "Уэброк 2",
    "Тёмный остров",
    "Озеро",
    "Дракон 2",
    "Тёмный остров"
};
static const char *const locations_ja[40] = {
    "飛空艇船長室",
    "パコの村",
    "墜落飛空艇船長室",
    "砲撃後のパコの村",
    "ギューヨークの町",
    "牛怒戦車最上部",
    "ウェブロック",
    "ヤギンの港",
    "プエルトメデューサ",
    "メルセデス邸地下入口",
    "海底洞窟",
    "バニラ王都",
    "グアバカカオの町",
    "海賊船休憩室",
    "沈没船",
    "ユラレカモメ遺跡深部",
    "楽園の遺跡",
    "楽園の遺跡最深部",
    "教会地下",
    "ドラゴン火山",
    "ドラゴンドック最上部",
    "古代バニラ遺跡",
    "ユーギ島",
    "スターツイスター入口",
    "スターツイスター中央",
    "魔甲クジラ胃エリア",
    "楽園の村",
    "魔ドール教会地下",
    "メルセデス邸地下",
    "地下牢",
    "魔甲クジラ潮吹き口",
    "ユラレカモメ遺跡",
    "メルセデス寝室",
    "牛怒戦車休憩室",
    "古代バニラ遺跡入口",
    "ウェブロック地下坑道",
    "魔の島",
    "地底湖",
    "ドラゴンドック内部",
    "魔の島"
};
static const char *const locations_en[40] = {
    "Cabin",
    "Paco",
    "Cabin 2",
    "Paco 2",
    "Toroledo",
    "Ox Tank 2",
    "Dun Webb 1",
    "Harbor",
    "Puerto",
    "Milena 1",
    "Ocean Cave",
    "Varuna",
    "Gwaba",
    "Lounge",
    "Sunk Ship",
    "Seagull 2",
    "Eden 1",
    "Eden 2",
    "Church",
    "Firedrake",
    "Dragonia 1",
    "Tomb 2",
    "Gamar Isle",
    "Star Key 1",
    "Star Key 2",
    "Whale 2",
    "Eden Villa",
    "Church 2",
    "Milena 2",
    "Dungeon",
    "Whale 1",
    "Seagull 1",
    "Milena 3",
    "Ox Tank 1",
    "Tomb 1",
    "Dun Webb 2",
    "Dark Isle",
    "Lake",
    "Dragonia 2",
    "Dark Isle"
};

static const char *localized(int language, const char *ru, const char *ja, const char *en) {
    return language == 1 ? ja : language == 2 ? en : ru;
}
static int fail(char *error, size_t size, const char *message) {
    if (error && size) snprintf(error, size, "%s", message);
    return 0;
}
static char *join_path(const char *directory, const char *name) {
    size_t a = strlen(directory), b = strlen(name);
    if (a > SIZE_MAX - b - 2) return NULL;
    char *path = malloc(a + b + 2);
    if (path) snprintf(path, a + b + 2, "%s/%s", directory, name);
    return path;
}
static int imported_name(const char *name) {
    if (strlen(name) != 36 || strncasecmp(name, "card", 4) ||
        (name[4] != '1' && name[4] != '2') ||
        strncasecmp(name + 5, "-BISCPS-10115", 13) ||
        name[18] < '0' || name[18] > '9' || name[19] < '0' || name[19] > '9' ||
        name[20] != '-' || strcasecmp(name + 29, A2_SAVE_EXTENSION)) return 0;
    for (unsigned i = 21; i < 29; i++)
        if (!((name[i] >= '0' && name[i] <= '9') ||
              (name[i] >= 'A' && name[i] <= 'F') ||
              (name[i] >= 'a' && name[i] <= 'f'))) return 0;
    return 1;
}
static void dispose_row(A2SaveBrowserRow *row) {
    free(row->path); free(row->filename);
}
void a2_save_browser_dispose(A2SaveBrowser *browser) {
    if (!browser) return;
    for (size_t i = 0; i < browser->count; i++) dispose_row(browser->rows + i);
    free(browser->rows); free(browser->directory);
    memset(browser, 0, sizeof *browser);
}
static int append_row(A2SaveBrowser *browser, A2SaveBrowserRow row) {
    if (browser->count == SIZE_MAX / sizeof row) return 0;
    A2SaveBrowserRow *rows = realloc(browser->rows, (browser->count + 1) * sizeof row);
    if (!rows) return 0;
    browser->rows = rows; rows[browser->count++] = row;
    return 1;
}
static int row_order(const void *a, const void *b) {
    const A2SaveBrowserRow *left = a, *right = b;
    if (left->fresh != right->fresh) return left->fresh ? -1 : 1;
    if (left->valid != right->valid) return left->valid ? -1 : 1;
    if (left->metadata.utc_seconds != right->metadata.utc_seconds)
        return left->metadata.utc_seconds > right->metadata.utc_seconds ? -1 : 1;
    return strcmp(left->filename, right->filename);
}
static uint16_t read16(const uint8_t *p) { return p[0] | (uint16_t)p[1] << 8; }

int a2_save_browser_open(A2SaveBrowser *browser, const char *user_directory,
                         int saving, char *error, size_t error_size) {
    if (error && error_size) error[0] = 0;
    if (!browser || browser->rows || browser->directory || !user_directory || !*user_directory)
        return fail(error, error_size, "Invalid save-browser state or user directory");
    A2SaveBrowser opened = {0};
    opened.saving = saving != 0;
    opened.directory = join_path(user_directory, "Saves");
    if (!opened.directory) return fail(error, error_size, "Cannot allocate save-directory path");
    opened.import_result = a2_save_import_cards(user_directory, opened.directory,
                                               opened.import_warning, sizeof opened.import_warning);
    int descriptor = open(opened.directory, O_RDONLY | O_DIRECTORY | O_NOFOLLOW | O_CLOEXEC);
    DIR *directory = descriptor < 0 ? NULL : fdopendir(descriptor);
    if (!directory) {
        if (descriptor >= 0) close(descriptor);
        a2_save_browser_dispose(&opened);
        return fail(error, error_size, "Cannot open save directory");
    }
    int ok = 1;
    if (opened.saving) {
        A2SaveBrowserRow row = {0}; row.valid = row.fresh = 1;
        row.path = strdup(""); row.filename = strdup("");
        if (!row.path || !row.filename || !append_row(&opened, row)) {
            dispose_row(&row); ok = fail(error, error_size, "Cannot allocate save-list row");
        }
    }
    while (ok) {
        errno = 0;
        struct dirent *entry = readdir(directory);
        if (!entry) {
            if (errno) ok = fail(error, error_size, "Cannot read save-directory entries");
            break;
        }
        size_t length = strlen(entry->d_name);
        if (length < strlen(A2_SAVE_EXTENSION) ||
            strcasecmp(entry->d_name + length - strlen(A2_SAVE_EXTENSION), A2_SAVE_EXTENSION)) continue;
        A2SaveBrowserRow row = {0};
        row.filename = strdup(entry->d_name); row.path = join_path(opened.directory, entry->d_name);
        if (!row.filename || !row.path) {
            dispose_row(&row); ok = fail(error, error_size, "Cannot allocate save-list path"); break;
        }
        row.imported = imported_name(entry->d_name);
        uint8_t payload[A2_SAVE_PAYLOAD_SIZE]; char detail[1024];
        row.valid = a2_save_read(row.path, payload, &row.metadata, detail, sizeof detail);
        if (row.valid) {
            row.hours = read16(payload + 0x104); row.minutes = read16(payload + 0x106);
            row.ticks = read16(payload + 0x108);
        }
        if (!append_row(&opened, row)) {
            dispose_row(&row); ok = fail(error, error_size, "Cannot allocate save-list row");
        }
    }
    if (closedir(directory) && ok) ok = fail(error, error_size, "Cannot close save directory");
    if (!ok) { a2_save_browser_dispose(&opened); return 0; }
    if (opened.count > 1) qsort(opened.rows, opened.count, sizeof *opened.rows, row_order);
    *browser = opened;
    return 1;
}

static int fresh_name(char name[44], char *error, size_t error_size) {
    /* Entropy names avoid collisions; the store's no-replace publication is
     * the actual protection for existing saves, including racing writers. */
    uint8_t bytes[16]; size_t offset = 0;
    int descriptor = open("/dev/urandom", O_RDONLY | O_CLOEXEC);
    if (descriptor < 0) return fail(error, error_size, "Cannot generate a new save filename");
    while (offset < sizeof bytes) {
        ssize_t got = read(descriptor, bytes + offset, sizeof bytes - offset);
        if (got < 0 && errno == EINTR) continue;
        if (got <= 0) { close(descriptor); return fail(error, error_size, "Cannot read save-filename entropy"); }
        offset += (size_t)got;
    }
    if (close(descriptor)) return fail(error, error_size, "Cannot close save-filename entropy source");
    bytes[6] = (bytes[6] & 15) | 0x40; bytes[8] = (bytes[8] & 63) | 0x80;
    snprintf(name, 44, "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x.a2save",
             bytes[0], bytes[1], bytes[2], bytes[3], bytes[4], bytes[5], bytes[6], bytes[7],
             bytes[8], bytes[9], bytes[10], bytes[11], bytes[12], bytes[13], bytes[14], bytes[15]);
    return 1;
}
int a2_save_browser_accept(A2SaveBrowser *browser, size_t index,
                           uint8_t payload[A2_SAVE_PAYLOAD_SIZE], char *error, size_t error_size) {
    if (error && error_size) error[0] = 0;
    if (!browser || !browser->directory || !payload || index >= browser->count || !browser->rows[index].valid)
        return fail(error, error_size, "Selected save is unavailable");
    A2SaveBrowserRow *row = browser->rows + index;
    if (!browser->saving) {
        if (row->fresh) return fail(error, error_size, "Select an existing save");
        uint8_t incoming[A2_SAVE_PAYLOAD_SIZE];
        int result = a2_save_read(row->path, incoming, NULL, error, error_size);
        if (result) memcpy(payload, incoming, sizeof incoming);
        return result;
    }
    if (row->fresh || row->imported) {
        char name[44];
        if (!fresh_name(name, error, error_size)) return 0;
        char *path = join_path(browser->directory, name);
        if (!path) return fail(error, error_size, "Cannot allocate new save path");
        int result = a2_save_write_new(path, payload, error, error_size);
        free(path); return result;
    }
    return a2_save_write(row->path, payload, error, error_size);
}

const char *a2_save_browser_location(uint16_t index, int language) {
    if (index >= 40) return localized(language, "Место неизвестно", "場所不明", "Unknown location");
    return language == 1 ? locations_ja[index] : language == 2 ? locations_en[index] : locations_ru[index];
}
void a2_save_browser_title(const A2SaveBrowserRow *row, int language, char *out, size_t size) {
    if (!out || !size) return;
    if (!row || !row->valid) snprintf(out, size, "%s", localized(language, "Недоступное сохранение", "利用できない保存データ", "Unavailable save"));
    else if (row->fresh) snprintf(out, size, "%s", localized(language, "Новое сохранение", "新しい保存データ", "New save"));
    else if(row->metadata.location_index==0xffff) snprintf(out,size,"%s",
        row->filename && !strcmp(row->filename,"quick.a2save") ? localized(language,"Быстрое сохранение","クイックセーブ","Quick save") : localized(language,"Сохранение","セーブデータ","Saved game"));
    else snprintf(out, size, "%s%s", a2_save_browser_location(row->metadata.location_index, language),
                  row->imported ? localized(language, "\nПрежнее сохранение", "\n以前の保存データ", "\nPrevious save") : "");
}
void a2_save_browser_playtime(const A2SaveBrowserRow *row, int language, char *out, size_t size) {
    if (!out || !size) return;
    out[0] = 0;
    if (!row || !row->valid || row->fresh) return;
    if (row->hours > 99 || row->minutes > 59 || row->ticks >= 3600)
        snprintf(out, size, "%s", localized(language, "Неизвестно", "不明", "Unknown"));
    else snprintf(out, size, localized(language, "%u ч %u мин", "%u時間%u分", "%u h %u min"),
                  (unsigned)row->hours, (unsigned)row->minutes);
}
void a2_save_browser_date(const A2SaveBrowserRow *row, int language, char *out, size_t size) {
    if (!out || !size) return;
    out[0] = 0;
    if (!row) return;
    if (row->fresh) { snprintf(out, size, "%s", localized(language, "Создать отдельный файл", "別のファイルを作成", "Create a separate file")); return; }
    if (!row->valid) { snprintf(out, size, "%s", row->filename ? row->filename : ""); return; }
    time_t seconds = (time_t)row->metadata.utc_seconds;
    struct tm date;
    if (seconds < 0 || (uint64_t)seconds != row->metadata.utc_seconds || !localtime_r(&seconds, &date)) {
        snprintf(out, size, "%s", localized(language, "Дата неизвестна", "日時不明", "Unknown date")); return;
    }
    const char *prefix = row->imported ? localized(language, "Перенесено ", "移行日時: ", "Imported ") : "";
    static const char *const ru_months[] = {"января","февраля","марта","апреля","мая","июня","июля","августа","сентября","октября","ноября","декабря"};
    static const char *const en_months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    if (language == 1) snprintf(out, size, "%s%d年%d月%d日 %02d:%02d", prefix, date.tm_year + 1900, date.tm_mon + 1, date.tm_mday, date.tm_hour, date.tm_min);
    else if (language == 2) snprintf(out, size, "%s%s %d, %d, %02d:%02d", prefix, en_months[date.tm_mon], date.tm_mday, date.tm_year + 1900, date.tm_hour, date.tm_min);
    else snprintf(out, size, "%s%d %s %d, %02d:%02d", prefix, date.tm_mday, ru_months[date.tm_mon], date.tm_year + 1900, date.tm_hour, date.tm_min);
}

static int starts_with(const char *text, const char *prefix) {
    return text && !strncmp(text, prefix, strlen(prefix));
}
int a2_save_browser_durability_warning(const char *message) {
    return starts_with(message, "Save was published, but directory sync failed:") ||
           starts_with(message, "Save was published, but temporary cleanup failed:");
}
void a2_save_browser_error_text(const char *message, int language, char *out, size_t size) {
    if (!out || !size) return;
    const char *text = message ? message : "";
    if (a2_save_browser_durability_warning(text))
        text = localized(language, "Сохранение уже записано и доступно для загрузки. Система не смогла подтвердить запись папки на диск. При сбое питания последние изменения могут потеряться.", "保存データを作成しました。ロードできますが、フォルダのディスク書き込み完了を確認できませんでした。停電すると最新の変更が失われる可能性があります。", "The save is available to load, but the system could not confirm the folder was written to disk. A power failure could lose the latest changes.");
    else if (starts_with(text, "Сохранение доступно у точек сохранения."))
        text = localized(language, text, "セーブポイントで保存できます。ロードは通常のプレイ中に利用できます。", "Saving is available at save points. Loading is available during normal play.");
    else if (starts_with(text, "Сейчас это действие недоступно.") || starts_with(text, "Сейчас действие недоступно."))
        text = localized(language, text, "今はこの操作を利用できません。通常のプレイに戻ってから、もう一度お試しください。", "This action is unavailable right now. Return to normal play and try again.");
    else if (starts_with(text, "В этом месте нельзя сохранить игру."))
        text = localized(language, text, "ここでは保存できません。セーブポイントを利用してください。", "You cannot save here. Use a save point.");
    else if (starts_with(text, "Файл сохранения повреждён."))
        text = localized(language, text, "保存ファイルが破損しています。別の保存データを選んでください。", "The save file is damaged. Choose another save.");
    else if (starts_with(text, "Это сохранение не подходит к текущей версии игры."))
        text = localized(language, text, "この保存データは現在のゲームバージョンに対応していません。別の保存データを選んでください。", "This save is incompatible with the current game version. Choose another save.");
    else if (starts_with(text, "В сохранении повреждены настройки звука."))
        text = localized(language, text, "保存データの音声設定が破損しています。別の保存データを選んでください。", "The save contains damaged sound settings. Choose another save.");
    else if (starts_with(text, "Неизвестный режим сохранения."))
        text = localized(language, text, "不明な保存モードです。ゲームの状態は変更されていません。", "Unknown save mode. The game state has not changed.");
    else if (!*text)
        text = localized(language, "Не удалось выполнить действие с сохранением.", "保存データの操作に失敗しました。", "The save operation could not be completed.");
    snprintf(out, size, "%s", text);
}
