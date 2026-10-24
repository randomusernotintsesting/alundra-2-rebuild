/* Compile with ARC. AppKit runs on the existing SDL application's main thread.
 * This file never advances the guest or polls SDL keyboard events. */
#import <AppKit/AppKit.h>
#include "native_save_macos.h"
#include "settings.h"
#include "native_save_store.h"
#include <stdio.h>
#include <sys/stat.h>

extern uint16_t platform_native_menu_buttons(void);

static NSString *A2SaveL(NSString *ru,NSString *ja,NSString *en) {
    return a2s.text_language==1?ja:a2s.text_language==2?en:ru;
}
static NSString *A2String(const char *s) {
    return s ? ([NSString stringWithUTF8String:s] ?: @"") : @"";
}
/* PACK0 entry 378, p0.e378.0..39 in translations/pack0_text.json.
 * 800C5E88 selects this table using the stored whitelist index, not scene ID
 * (some scenes have more than one named save location). */
static NSString *A2Location(uint16_t index) {
    NSArray<NSString *> *ru = @[
        @"Каюта", @"Пако", @"Каюта 2", @"Пако 2", @"Гю-Йорк", @"Бык 2",
        @"Уэброк 1", @"Гавань", @"Пуэрто", @"Мерседес 1", @"Пещера", @"Ванилла",
        @"Гвабакакао", @"Салон", @"Обломки", @"Чайка 2", @"Эдем 1", @"Эдем 2",
        @"Церковь", @"Огнедрак", @"Дракон 1", @"Гробница 2", @"Нунуги", @"Ключ 1",
        @"Ключ 2", @"Кит 2", @"Эдем", @"Церковь 2", @"Мерседес 2", @"Темница",
        @"Кит 1", @"Чайка 1", @"Мерседес 3", @"Бык 1", @"Гробница 1", @"Уэброк 2",
        @"Тёмный остров", @"Озеро", @"Дракон 2", @"Тёмный остров"
    ];
    NSArray<NSString *> *ja = @[
        @"飛空艇船長室",
        @"パコの村",
        @"墜落飛空艇船長室",
        @"砲撃後のパコの村",
        @"ギューヨークの町",
        @"牛怒戦車最上部",
        @"ウェブロック",
        @"ヤギンの港",
        @"プエルトメデューサ",
        @"メルセデス邸地下入口",
        @"海底洞窟",
        @"バニラ王都",
        @"グアバカカオの町",
        @"海賊船休憩室",
        @"沈没船",
        @"ユラレカモメ遺跡深部",
        @"楽園の遺跡",
        @"楽園の遺跡最深部",
        @"教会地下",
        @"ドラゴン火山",
        @"ドラゴンドック最上部",
        @"古代バニラ遺跡",
        @"ユーギ島",
        @"スターツイスター入口",
        @"スターツイスター中央",
        @"魔甲クジラ胃エリア",
        @"楽園の村",
        @"魔ドール教会地下",
        @"メルセデス邸地下",
        @"地下牢",
        @"魔甲クジラ潮吹き口",
        @"ユラレカモメ遺跡",
        @"メルセデス寝室",
        @"牛怒戦車休憩室",
        @"古代バニラ遺跡入口",
        @"ウェブロック地下坑道",
        @"魔の島",
        @"地底湖",
        @"ドラゴンドック内部",
        @"魔の島"
    ];
    NSArray<NSString *> *en = @[
        @"Cabin",
        @"Paco",
        @"Cabin 2",
        @"Paco 2",
        @"Toroledo",
        @"Ox Tank 2",
        @"Dun Webb 1",
        @"Harbor",
        @"Puerto",
        @"Milena 1",
        @"Ocean Cave",
        @"Varuna",
        @"Gwaba",
        @"Lounge",
        @"Sunk Ship",
        @"Seagull 2",
        @"Eden 1",
        @"Eden 2",
        @"Church",
        @"Firedrake",
        @"Dragonia 1",
        @"Tomb 2",
        @"Gamar Isle",
        @"Star Key 1",
        @"Star Key 2",
        @"Whale 2",
        @"Eden Villa",
        @"Church 2",
        @"Milena 2",
        @"Dungeon",
        @"Whale 1",
        @"Seagull 1",
        @"Milena 3",
        @"Ox Tank 1",
        @"Tomb 1",
        @"Dun Webb 2",
        @"Dark Isle",
        @"Lake",
        @"Dragonia 2",
        @"Dark Isle"
    ];
    NSArray<NSString *> *names=a2s.text_language==1?ja:a2s.text_language==2?en:ru;
    return index < names.count ? names[index] : A2SaveL(@"Место неизвестно",@"場所不明",@"Unknown location");
}
static NSString *A2Playtime(const uint8_t *payload) {
    /* 80022690: +8 counts 3600 ticks/minute, +6 rolls at 60, +4 caps at 99.
     * Persistent block 80063388 is copied to payload+0x100 by 800C5F98. */
    unsigned hours = payload[0x104] | ((unsigned)payload[0x105] << 8);
    unsigned minutes = payload[0x106] | ((unsigned)payload[0x107] << 8);
    unsigned ticks = payload[0x108] | ((unsigned)payload[0x109] << 8);
    if (hours > 99 || minutes > 59 || ticks >= 3600) return A2SaveL(@"Неизвестно",@"不明",@"Unknown");
    return [NSString stringWithFormat:A2SaveL(@"%u ч %u мин",@"%u時間%u分",@"%u h %u min"), hours, minutes];
}
static void A2Error(char *out, size_t size, NSString *message) {
    if (out && size) snprintf(out, size, "%s", message.UTF8String);
}
static NSTextField *A2Label(NSString *text, CGFloat size) {
    NSTextField *label = [NSTextField wrappingLabelWithString:text];
    label.font = [NSFont systemFontOfSize:size];
    label.selectable = YES;
    label.translatesAutoresizingMaskIntoConstraints = NO;
    return label;
}

@interface A2SaveRow : NSObject
@property(copy) NSString *path;
@property(copy) NSString *title;
@property(copy) NSString *dateText;
@property(copy) NSString *playtime;
@property(strong) NSDate *date;
@property BOOL valid;
@property BOOL imported;
@end
@implementation A2SaveRow
@end

@interface A2SaveTable : NSTableView
@end
@implementation A2SaveTable
- (void)keyDown:(NSEvent *)event {
    if (event.keyCode == 36 || event.keyCode == 76) {
        [NSApp sendAction:self.doubleAction to:self.target from:self];
    } else {
        [super keyDown:event];
    }
}
@end

@interface A2SaveBrowser : NSObject <NSTableViewDataSource, NSTableViewDelegate, NSWindowDelegate>
@property(strong) NSPanel *panel;
@property(strong) A2SaveTable *table;
@property(strong) NSButton *acceptButton;
@property(strong) NSMutableArray<A2SaveRow *> *rows;
@property(strong) NSTimer *timer;
@property(strong) NSAlert *alert;
@property(copy) NSString *directory;
@property BOOL saving;
@property BOOL armed;
@property uint16_t previousButtons;
@property uint8_t *payload;
@property int result;
@property NSTimeInterval diagnosticStart;
@property BOOL diagnosticCaptured;
- (void)accept:(id)sender;
- (void)cancel:(id)sender;
@end

@implementation A2SaveBrowser
- (NSInteger)numberOfRowsInTableView:(NSTableView *)tableView {
    (void)tableView;
    return (NSInteger)self.rows.count;
}
- (NSView *)tableView:(NSTableView *)tableView viewForTableColumn:(NSTableColumn *)column row:(NSInteger)row {
    (void)tableView;
    A2SaveRow *entry = self.rows[(NSUInteger)row];
    NSString *text = [column.identifier isEqualToString:@"place"] ? entry.title
        : [column.identifier isEqualToString:@"time"] ? (entry.playtime ?: @"") : entry.dateText;
    NSTableCellView *cell = [[NSTableCellView alloc] initWithFrame:NSZeroRect];
    NSTextField *label = A2Label(text, 14);
    label.selectable = NO;
    label.maximumNumberOfLines = 2;
    label.lineBreakMode = NSLineBreakByTruncatingMiddle;
    label.toolTip = text;
    cell.textField = label;
    [cell addSubview:label];
    [NSLayoutConstraint activateConstraints:@[
        [label.leadingAnchor constraintEqualToAnchor:cell.leadingAnchor constant:8],
        [label.trailingAnchor constraintEqualToAnchor:cell.trailingAnchor constant:-8],
        [label.centerYAnchor constraintEqualToAnchor:cell.centerYAnchor]
    ]];
    return cell;
}
- (void)tableViewSelectionDidChange:(NSNotification *)notification {
    (void)notification;
    NSInteger row = self.table.selectedRow;
    self.acceptButton.enabled = row >= 0 && (NSUInteger)row < self.rows.count;
    if (self.saving && self.acceptButton.enabled)
        self.acceptButton.title = self.rows[(NSUInteger)row].imported ? A2SaveL(@"Сохранить копию",@"コピーを保存",@"Save a copy") : A2SaveL(@"Сохранить",@"保存",@"Save");
}
- (BOOL)windowShouldClose:(NSWindow *)sender {
    (void)sender;
    [self cancel:nil];
    return NO;
}
- (void)cancel:(id)sender {
    (void)sender;
    self.result = 0;
    [NSApp stopModal];
}
- (NSModalResponse)showAlert:(NSString *)title message:(NSString *)message action:(NSString *)action {
    NSAlert *alert = [[NSAlert alloc] init];
    alert.messageText = title;
    alert.informativeText = message;
    alert.alertStyle = NSAlertStyleWarning;
    [alert addButtonWithTitle:action ? A2SaveL(@"Отмена",@"キャンセル",@"Cancel") : A2SaveL(@"Закрыть",@"閉じる",@"Close")];
    if (action) [alert addButtonWithTitle:action];
    /* Explicit Escape works regardless of the user's macOS language. */
    if (action) alert.buttons[1].keyEquivalent = @"\r";
    else alert.window.defaultButtonCell = alert.buttons[0].cell;
    /* Setting defaultButtonCell resets its key equivalent to Return. Apply
     * Escape afterwards so one-button error alerts remain dismissible. */
    alert.buttons[0].keyEquivalent = @"\e";
    self.alert = alert;
    self.armed = NO;
    NSModalResponse response = [alert runModal];
    self.alert = nil;
    self.armed = NO;
    return response;
}
- (void)accept:(id)sender {
    (void)sender;
    NSInteger index = self.table.selectedRow;
    if (index < 0 || (NSUInteger)index >= self.rows.count || self.alert) return;
    A2SaveRow *row = self.rows[(NSUInteger)index];
    if (!row.valid) {
        [self showAlert:A2SaveL(@"Сохранение недоступно",@"保存データを利用できません",@"Save unavailable")
                message:A2SaveL(@"Файл повреждён, имеет неподдерживаемый формат или недоступен для чтения. Он оставлен без изменений. Выберите другое сохранение.",@"ファイルが破損しているか、未対応の形式か、読み取れません。ファイルは変更されていません。別の保存データを選んでください。",@"This file is damaged, unsupported, or unreadable. It has not been changed. Choose another save.")
              action:nil];
        return;
    }
    NSString *path = row.path;
    if (self.saving) {
        if (row.imported) {
            if ([self showAlert:A2SaveL(@"Сохранить текущий прогресс отдельно?",@"現在の進行状況を別に保存しますか？",@"Save current progress separately?")
                         message:A2SaveL(@"Будет создан новый файл с текущим прогрессом. Прежнее сохранение останется без изменений.",@"現在の進行状況を新しいファイルに保存します。以前の保存データは変更されません。",@"A new file will contain your current progress. The previous save will be kept.")
                          action:A2SaveL(@"Сохранить копию",@"コピーを保存",@"Save a copy")] != NSAlertSecondButtonReturn) return;
            path = @"";
        } else if (path.length) {
            if ([self showAlert:A2SaveL(@"Заменить сохранение?",@"保存データを上書きしますか？",@"Replace this save?")
                         message:[NSString stringWithFormat:A2SaveL(@"%@\n%@\n\nТекущий прогресс заменит выбранное сохранение.",@"%@\n%@\n\n選択した保存データを現在の進行状況で上書きします。",@"%@\n%@\n\nYour current progress will replace this save."), row.title, row.dateText]
                          action:A2SaveL(@"Заменить сохранение",@"上書き",@"Replace save")] != NSAlertSecondButtonReturn) return;
        }
        if (!path.length) {
            path = [self.directory stringByAppendingPathComponent:
                    [NSUUID.UUID.UUIDString stringByAppendingString:@".a2save"]];
        }
    }
    char detail[1024] = {0};
    uint8_t incoming[A2_SAVE_PAYLOAD_SIZE];
    int ok = self.saving
        ? a2_save_write(path.fileSystemRepresentation, self.payload, detail, sizeof detail)
        : a2_save_read(path.fileSystemRepresentation, incoming, NULL, detail, sizeof detail);
    if (!ok) {
        fprintf(stderr, "native-save: %s\n", detail);
        [self showAlert:self.saving ? A2SaveL(@"Не удалось сохранить игру",@"保存できませんでした",@"Could not save the game") : A2SaveL(@"Не удалось загрузить сохранение",@"読み込めませんでした",@"Could not load the save")
                message:self.saving
                    ? A2SaveL(@"Проверьте свободное место и доступ к папке сохранений, затем повторите попытку. Выбранный файл не удалён.",@"空き容量と保存フォルダへのアクセス権を確認し、もう一度お試しください。選択したファイルは削除されていません。",@"Check free disk space and access to the save folder, then try again. The selected file has not been deleted.")
                    : A2SaveL(@"Файл изменился, повреждён или недоступен для чтения. Выберите другое сохранение или восстановите файл из резервной копии.",@"ファイルが変更・破損しているか、読み取れません。別の保存データを選ぶか、バックアップから復元してください。",@"The file has changed, is damaged, or cannot be read. Choose another save or restore a backup.")
              action:nil];
        return;
    }
    /* Store's published-but-directory-sync-uncertain result. */
    if (self.saving && ok == A2_SAVE_PUBLISHED_UNCERTAIN) {
        fprintf(stderr, "native-save: %s\n", detail);
        [self showAlert:A2SaveL(@"Сохранение записано, но надёжность записи не подтверждена",@"保存されましたが、書き込みの完了を確認できません",@"Save written; disk confirmation unavailable")
                message:A2SaveL(@"Новый файл уже доступен. Системе не удалось подтвердить запись папки на диск, поэтому при сбое питания последние изменения могут потеряться. По возможности сохраните игру ещё раз перед выходом.",@"新しいファイルは利用できますが、フォルダのディスクへの書き込み完了を確認できませんでした。停電すると最新の変更が失われる可能性があります。終了前にもう一度保存してください。",@"The new file is available, but the system could not confirm the folder was written to disk. A power failure could lose the latest changes. Save again before quitting if possible.")
                 action:nil];
    }
    if (!self.saving) memcpy(self.payload, incoming, sizeof incoming);
    self.result = 1;
    [NSApp stopModal];
}
- (void)pollController:(NSTimer *)timer {
    (void)timer;
    if (self.diagnosticStart && getenv("A2_USER_DIR") && *getenv("A2_USER_DIR")) {
        NSTimeInterval elapsed = NSDate.timeIntervalSinceReferenceDate - self.diagnosticStart;
        const char *capture = getenv("A2_NATIVE_UI_CAPTURE");
        if (!self.diagnosticCaptured && elapsed >= 0.2 && capture && *capture && !self.alert) {
            self.diagnosticCaptured = YES;
            NSView *view = self.panel.contentView;
            [view layoutSubtreeIfNeeded];
            [view displayIfNeeded];
            NSBitmapImageRep *bitmap = [view bitmapImageRepForCachingDisplayInRect:view.bounds];
            if (bitmap) {
                [view cacheDisplayInRect:view.bounds toBitmapImageRep:bitmap];
                /* A content-view cache excludes the window-owned background.
                 * Preserve control/text alpha by compositing onto that actual
                 * background, not by forcing an appearance or recoloring UI. */
                NSBitmapImageRep *opaque = [[NSBitmapImageRep alloc]
                    initWithBitmapDataPlanes:NULL pixelsWide:bitmap.pixelsWide pixelsHigh:bitmap.pixelsHigh
                    bitsPerSample:8 samplesPerPixel:3 hasAlpha:NO isPlanar:NO
                    colorSpaceName:NSCalibratedRGBColorSpace bytesPerRow:0 bitsPerPixel:0];
                if (!opaque) return;
                [self.panel.effectiveAppearance performAsCurrentDrawingAppearance:^{
                    [NSGraphicsContext saveGraphicsState];
                    NSGraphicsContext.currentContext = [NSGraphicsContext graphicsContextWithBitmapImageRep:opaque];
                    NSRect pixels = NSMakeRect(0, 0, bitmap.pixelsWide, bitmap.pixelsHigh);
                    [self.panel.backgroundColor setFill];
                    NSRectFill(pixels);
                    [bitmap drawInRect:pixels];
                    [NSGraphicsContext restoreGraphicsState];
                }];
                NSData *png = [opaque representationUsingType:NSBitmapImageFileTypePNG properties:@{}];
                NSError *captureError = nil;
                BOOL ok = [png writeToFile:A2String(capture) options:NSDataWritingAtomic error:&captureError];
                fprintf(stderr, "native-save-ui-capture: %s\n", ok ? "written" : "failed");
            }
        }
        const char *timeout = getenv("A2_NATIVE_UI_AUTOCLOSE");
        double milliseconds = timeout ? strtod(timeout, NULL) : 0;
        if (milliseconds > 0 && elapsed * 1000 >= milliseconds && !self.alert) {
            [self cancel:nil];
            return;
        }
    }
    uint16_t buttons = platform_native_menu_buttons();
    const uint16_t mask = (1u << 4) | (1u << 6) | (1u << 13) | (1u << 14);
    NSWindow *activeWindow = self.alert ? self.alert.window : self.panel;
    if (!NSApp.active || !activeWindow.keyWindow) {
        self.armed = NO;
        self.previousButtons = buttons;
        return;
    }
    if (!self.armed) {
        self.previousButtons = buttons;
        if ((buttons & mask) == mask) self.armed = YES;
        return;
    }
    uint16_t pressed = self.previousButtons & (uint16_t)~buttons & mask;
    self.previousButtons = buttons;
    if (self.alert) {
        if (pressed & (1u << 14)) [self.alert.buttons[0] performClick:nil];
        else if (pressed & (1u << 13)) [self.alert.buttons.lastObject performClick:nil];
        return;
    }
    if (pressed & (1u << 14)) { [self cancel:nil]; return; }
    if ((pressed & ((1u << 4) | (1u << 6))) && self.rows.count) {
        NSInteger index = self.table.selectedRow;
        index += (pressed & (1u << 4)) ? -1 : 1;
        index = MAX(0, MIN(index, (NSInteger)self.rows.count - 1));
        [self.table selectRowIndexes:[NSIndexSet indexSetWithIndex:(NSUInteger)index] byExtendingSelection:NO];
        [self.table scrollRowToVisible:index];
    }
    if (pressed & (1u << 13)) [self accept:nil];
}
@end

int a2_macos_save_browser(const char *userdir, int saving, uint8_t payload[8192],
                          char *error, size_t error_size) {
    @autoreleasepool {
        A2Error(error, error_size, @"");
        if (![NSThread isMainThread] || !userdir || !*userdir || !payload) {
            A2Error(error, error_size, A2SaveL(@"Не удалось открыть список сохранений.",@"保存データ一覧を開けませんでした。",@"Could not open the save list."));
            return 0;
        }
        A2SaveBrowser *browser = [[A2SaveBrowser alloc] init];
        browser.saving = saving != 0;
        browser.payload = payload;
        browser.directory = [A2String(userdir) stringByAppendingPathComponent:@"Saves"];
        browser.rows = [NSMutableArray array];
        char importError[1024] = {0};
        int imported = a2_save_import_cards(userdir, browser.directory.fileSystemRepresentation,
                                            importError, sizeof importError);
        struct stat st;
        if (lstat(browser.directory.fileSystemRepresentation, &st) || !S_ISDIR(st.st_mode)) {
            A2Error(error, error_size, A2SaveL(@"Не удалось открыть папку сохранений. Проверьте доступ к папке игры.",@"保存フォルダを開けませんでした。ゲームフォルダへのアクセス権を確認してください。",@"Could not open the save folder. Check access to the game folder."));
            return 0;
        }
        NSError *listingError = nil;
        NSArray<NSString *> *files = [NSFileManager.defaultManager contentsOfDirectoryAtPath:browser.directory error:&listingError];
        if (!files) {
            A2Error(error, error_size, A2SaveL(@"Не удалось прочитать список сохранений. Проверьте доступ к папке игры.",@"保存データ一覧を読み取れませんでした。ゲームフォルダへのアクセス権を確認してください。",@"Could not read the save list. Check access to the game folder."));
            return 0;
        }
        NSDateFormatter *dates = [[NSDateFormatter alloc] init];
        dates.locale = [[NSLocale alloc] initWithLocaleIdentifier:A2SaveL(@"ru_RU",@"ja_JP",@"en_US")];
        dates.dateFormat = A2SaveL(@"d MMMM yyyy, HH:mm",@"yyyy年M月d日 HH:mm",@"MMM d, yyyy, HH:mm");
        for (NSString *file in files) {
            if ([file.pathExtension caseInsensitiveCompare:@"a2save"] != NSOrderedSame) continue;
            A2SaveRow *row = [[A2SaveRow alloc] init];
            row.path = [browser.directory stringByAppendingPathComponent:file];
            row.imported = [file rangeOfString:@"^card[12]-BISCPS-10115[0-9]{2}-[0-9A-Fa-f]{8}\\.a2save$"
                                       options:NSRegularExpressionSearch | NSCaseInsensitiveSearch].location != NSNotFound;
            A2SaveMetadata metadata = {0};
            uint8_t checked[A2_SAVE_PAYLOAD_SIZE];
            char detail[1024] = {0};
            row.valid = a2_save_read(row.path.fileSystemRepresentation, checked, &metadata, detail, sizeof detail) != 0;
            if (row.valid) {
                row.title = metadata.location_index==0xffff ? ([file isEqualToString:@"quick.a2save"] ? A2SaveL(@"Быстрое сохранение",@"クイックセーブ",@"Quick save") : A2SaveL(@"Сохранение",@"セーブデータ",@"Saved game")) : A2Location(metadata.location_index);
                row.playtime = A2Playtime(checked);
                row.date = [NSDate dateWithTimeIntervalSince1970:(NSTimeInterval)metadata.utc_seconds];
                row.dateText = [dates stringFromDate:row.date] ?: A2SaveL(@"Дата неизвестна",@"日時不明",@"Unknown date");
                if (row.imported) {
                    row.title = [row.title stringByAppendingString:A2SaveL(@"\nПрежнее сохранение",@"\n以前の保存データ",@"\nPrevious save")];
                    row.dateText = [A2SaveL(@"Перенесено ",@"移行日時: ",@"Imported ") stringByAppendingString:row.dateText];
                }
            } else {
                row.title = A2SaveL(@"Недоступное сохранение",@"利用できない保存データ",@"Unavailable save");
                row.date = [NSDate distantPast];
                row.dateText = file;
                fprintf(stderr, "native-save: unreadable entry: %s\n", detail);
            }
            [browser.rows addObject:row];
        }
        [browser.rows sortUsingComparator:^NSComparisonResult(A2SaveRow *a, A2SaveRow *b) {
            NSComparisonResult order = [b.date compare:a.date];
            return order == NSOrderedSame ? [a.path compare:b.path] : order;
        }];
        if (saving) {
            A2SaveRow *fresh = [[A2SaveRow alloc] init];
            fresh.path = @""; fresh.title = A2SaveL(@"Новое сохранение",@"新しい保存データ",@"New save");
            fresh.dateText = A2SaveL(@"Создать отдельный файл",@"別のファイルを作成",@"Create a separate file"); fresh.valid = YES;
            [browser.rows insertObject:fresh atIndex:0];
        }
        NSPanel *panel = [[NSPanel alloc] initWithContentRect:NSMakeRect(0, 0, 780, 450)
            styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable
            backing:NSBackingStoreBuffered defer:NO];
        browser.panel = panel;
        panel.title = saving ? A2SaveL(@"Сохранить игру",@"ゲームを保存",@"Save game") : A2SaveL(@"Загрузить игру",@"ゲームをロード",@"Load game");
        panel.contentMinSize = NSMakeSize(740, 420);
        panel.releasedWhenClosed = NO;
        panel.delegate = browser;
        NSView *content = panel.contentView;
        NSTextField *heading = A2Label(panel.title, 22);
        heading.font = [NSFont systemFontOfSize:22 weight:NSFontWeightSemibold];
        NSTextField *hint = A2Label(saving
            ? A2SaveL(@"Создайте новое сохранение или выберите, какое заменить.",@"新しく保存するか、上書きする保存データを選んでください。",@"Create a new save or choose one to replace.")
            : browser.rows.count ? A2SaveL(@"Выберите сохранение, чтобы продолжить игру.",@"続ける保存データを選んでください。",@"Choose a save to continue your adventure.")
              : A2SaveL(@"Сохранений пока нет. Во время игры нажмите F5, чтобы сохранить прогресс.",@"保存データはありません。プレイ中にF5を押すと保存できます。",@"No saves yet. Press F5 during gameplay to save your progress."), 14);
        NSScrollView *scroll = [[NSScrollView alloc] init];
        scroll.translatesAutoresizingMaskIntoConstraints = NO;
        scroll.hasVerticalScroller = YES;
        scroll.borderType = NSBezelBorder;
        A2SaveTable *table = [[A2SaveTable alloc] init];
        browser.table = table;
        table.rowHeight = 48;
        table.usesAlternatingRowBackgroundColors = YES;
        table.allowsMultipleSelection = NO;
        table.allowsEmptySelection = NO;
        table.accessibilityLabel = A2SaveL(@"Сохранения",@"保存データ",@"Saved games");
        table.columnAutoresizingStyle = NSTableViewUniformColumnAutoresizingStyle;
        NSTableColumn *place = [[NSTableColumn alloc] initWithIdentifier:@"place"];
        place.title = A2SaveL(@"Место",@"場所",@"Location"); place.width = 265; place.minWidth = 210;
        NSTableColumn *date = [[NSTableColumn alloc] initWithIdentifier:@"date"];
        date.title = A2SaveL(@"Дата",@"日時",@"Date"); date.width = 305; date.minWidth = 280;
        NSTableColumn *time = [[NSTableColumn alloc] initWithIdentifier:@"time"];
        time.title = A2SaveL(@"Время в игре",@"プレイ時間",@"Play time"); time.width = 140; time.minWidth = 130;
        [table addTableColumn:place]; [table addTableColumn:date]; [table addTableColumn:time];
        table.dataSource = browser; table.delegate = browser;
        table.target = browser; table.doubleAction = @selector(accept:);
        scroll.documentView = table;
        NSButton *cancel = [NSButton buttonWithTitle:A2SaveL(@"Отмена",@"キャンセル",@"Cancel") target:browser action:@selector(cancel:)];
        cancel.keyEquivalent = @"\e";
        NSButton *accept = [NSButton buttonWithTitle:saving ? A2SaveL(@"Сохранить",@"保存",@"Save") : A2SaveL(@"Загрузить",@"ロード",@"Load") target:browser action:@selector(accept:)];
        accept.keyEquivalent = @"\r";
        browser.acceptButton = accept;
        accept.enabled = browser.rows.count != 0;
        NSStackView *buttons = [NSStackView stackViewWithViews:@[cancel, accept]];
        buttons.spacing = 12;
        buttons.translatesAutoresizingMaskIntoConstraints = NO;
        for (NSView *view in @[heading, hint, scroll, buttons]) [content addSubview:view];
        [NSLayoutConstraint activateConstraints:@[
            [heading.topAnchor constraintEqualToAnchor:content.topAnchor constant:22],
            [heading.leadingAnchor constraintEqualToAnchor:content.leadingAnchor constant:24],
            [heading.trailingAnchor constraintEqualToAnchor:content.trailingAnchor constant:-24],
            [hint.topAnchor constraintEqualToAnchor:heading.bottomAnchor constant:8],
            [hint.leadingAnchor constraintEqualToAnchor:heading.leadingAnchor],
            [hint.trailingAnchor constraintEqualToAnchor:heading.trailingAnchor],
            [scroll.topAnchor constraintEqualToAnchor:hint.bottomAnchor constant:20],
            [scroll.leadingAnchor constraintEqualToAnchor:heading.leadingAnchor],
            [scroll.trailingAnchor constraintEqualToAnchor:heading.trailingAnchor],
            [scroll.bottomAnchor constraintEqualToAnchor:buttons.topAnchor constant:-20],
            [buttons.trailingAnchor constraintEqualToAnchor:heading.trailingAnchor],
            [buttons.bottomAnchor constraintEqualToAnchor:content.bottomAnchor constant:-20]
        ]];
        table.nextKeyView = cancel; cancel.nextKeyView = accept; accept.nextKeyView = table;
        [table reloadData];
        if (browser.rows.count) [table selectRowIndexes:[NSIndexSet indexSetWithIndex:0] byExtendingSelection:NO];
        [panel center];
        [panel makeKeyAndOrderFront:nil];
        [panel makeFirstResponder:table];
        browser.timer = [NSTimer timerWithTimeInterval:0.025 target:browser selector:@selector(pollController:) userInfo:nil repeats:YES];
        [NSRunLoop.mainRunLoop addTimer:browser.timer forMode:NSModalPanelRunLoopMode];
        [NSRunLoop.mainRunLoop addTimer:browser.timer forMode:NSRunLoopCommonModes];
        if (imported == A2_SAVE_PUBLISHED_UNCERTAIN) {
            fprintf(stderr, "native-save: import: %s\n", importError);
            [browser showAlert:A2SaveL(@"Прежние сохранения перенесены, но надёжность записи не подтверждена",@"以前のデータを移行しましたが、書き込み完了を確認できません",@"Previous saves imported; disk confirmation unavailable")
                       message:A2SaveL(@"Копии уже доступны в списке. Системе не удалось подтвердить запись папки на диск, поэтому при сбое питания копии могут потеряться. Исходные карты памяти оставлены без изменений; перенос можно повторить при следующем открытии списка.",@"コピーは一覧から利用できますが、ディスクへの書き込み完了を確認できませんでした。停電するとコピーが失われる可能性があります。元のメモリーカードは変更されていません。次に一覧を開くときに移行を再試行できます。",@"Copies are available in the list, but the system could not confirm the folder was written to disk. A power failure could lose them. Original memory cards remain unchanged; import can be retried next time.")
                        action:nil];
        } else if (imported == A2_SAVE_FAILED) {
            fprintf(stderr, "native-save: import: %s\n", importError);
            [browser showAlert:A2SaveL(@"Не все прежние сохранения удалось перенести",@"一部の保存データを移行できませんでした",@"Some previous saves could not be imported")
                       message:A2SaveL(@"Исходные карты памяти оставлены без изменений. Доступные сохранения показаны в списке. Проверьте свободное место и доступ к папке игры; повреждённые файлы можно восстановить из резервной копии.",@"元のメモリーカードは変更されていません。利用できるデータは一覧に表示されています。空き容量とゲームフォルダへのアクセス権を確認してください。破損したファイルはバックアップから復元できます。",@"Original memory cards remain unchanged. Available saves are shown in the list. Check free space and access to the game folder; damaged files can be restored from a backup.")
                      action:nil];
        }
        browser.diagnosticStart = NSDate.timeIntervalSinceReferenceDate;
        [NSApp runModalForWindow:panel];
        [browser.timer invalidate]; browser.timer = nil;
        [panel orderOut:nil];
        panel.delegate = nil;
        return browser.result;
    }
}

static BOOL A2SaveDurabilityWarning(NSString *text) {
    return [text hasPrefix:@"Save was published, but directory sync failed:"];
}

static NSString *A2SaveErrorDetail(NSString *text) {
    if (A2SaveDurabilityWarning(text))
        return A2SaveL(@"Сохранение уже записано и доступно для загрузки. Система не смогла подтвердить запись папки на диск. При сбое питания последние изменения могут потеряться.",@"保存データを作成しました。ロードできますが、フォルダのディスク書き込み完了を確認できませんでした。停電すると最新の変更が失われる可能性があります。",@"The save is available to load, but the system could not confirm the folder was written to disk. A power failure could lose the latest changes.");
    if ([text hasPrefix:@"Сохранение доступно у точек сохранения."])
        return A2SaveL(text,@"セーブポイントで保存できます。ロードは通常のプレイ中に利用できます。",@"Saving is available at save points. Loading is available during normal play.");
    if ([text hasPrefix:@"Сейчас это действие недоступно."] || [text hasPrefix:@"Сейчас действие недоступно."])
        return A2SaveL(text,@"今はこの操作を利用できません。通常のプレイに戻ってから、もう一度お試しください。",@"This action is unavailable right now. Return to normal play and try again.");
    if ([text hasPrefix:@"В этом месте нельзя сохранить игру."])
        return A2SaveL(text,@"ここでは保存できません。セーブポイントを利用してください。",@"You cannot save here. Use a save point.");
    if ([text hasPrefix:@"Файл сохранения повреждён."])
        return A2SaveL(text,@"保存ファイルが破損しています。別の保存データを選んでください。",@"The save file is damaged. Choose another save.");
    if ([text hasPrefix:@"Это сохранение не подходит к текущей версии игры."])
        return A2SaveL(text,@"この保存データは現在のゲームバージョンに対応していません。別の保存データを選んでください。",@"This save is incompatible with the current game version. Choose another save.");
    if ([text hasPrefix:@"В сохранении повреждены настройки звука."])
        return A2SaveL(text,@"保存データの音声設定が破損しています。別の保存データを選んでください。",@"The save contains damaged sound settings. Choose another save.");
    if ([text hasPrefix:@"Неизвестный режим сохранения."])
        return A2SaveL(text,@"不明な保存モードです。ゲームの状態は変更されていません。",@"Unknown save mode. The game state has not changed.");
    return text.length ? text : A2SaveL(@"Не удалось выполнить действие с сохранением.",@"保存データの操作に失敗しました。",@"The save operation could not be completed.");
}

void a2_macos_save_error(const char *message) {
    @autoreleasepool {
        fprintf(stderr, "native-save: %s\n", message ? message : "unknown error");
        NSString *text = A2String(message);
        NSAlert *alert = [[NSAlert alloc] init];
        alert.messageText = A2SaveDurabilityWarning(text)
            ? A2SaveL(@"Сохранение записано; требуется внимание",@"保存しました：書き込み確認の警告",@"Save created; disk confirmation warning")
            : A2SaveL(@"Действие с сохранением",@"保存データの操作",@"Save operation");
        alert.informativeText = A2SaveErrorDetail(text);
        [alert addButtonWithTitle:A2SaveL(@"Закрыть",@"閉じる",@"Close")];
        alert.window.defaultButtonCell = alert.buttons[0].cell;
        alert.buttons[0].keyEquivalent = @"\e";
        A2SaveBrowser *controls = [[A2SaveBrowser alloc] init];
        controls.alert = alert;
        controls.timer = [NSTimer timerWithTimeInterval:0.025 target:controls selector:@selector(pollController:) userInfo:nil repeats:YES];
        [NSRunLoop.mainRunLoop addTimer:controls.timer forMode:NSModalPanelRunLoopMode];
        [NSRunLoop.mainRunLoop addTimer:controls.timer forMode:NSRunLoopCommonModes];
        [alert runModal];
        [controls.timer invalidate];
        controls.timer = nil;
        controls.alert = nil;
    }
}
