/* Manual, foreground AppKit acceptance test; deliberately not a headless CTest.
 * Compile with ARC and link native_save_store.c plus Cocoa. Including the real
 * browser exposes its controller to the driver without production test hooks.
 * Every fixture is beneath a fresh mkdtemp; no real game/profile/card is used.
 * Optional argv[1] retains panel.png and fixtures in the printed temp directory.
 */
#include <assert.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "settings.h"
A2Settings a2s;
#import "../src/native_save_macos.m"

static uint16_t controllerButtons = UINT16_MAX;
uint16_t platform_native_menu_buttons(void) { return controllerButtons; }

static void deadline(int signalNumber) {
    (void)signalNumber;
    static const char text[] = "FAIL: native AppKit case exceeded 10 seconds\n";
    (void)write(STDERR_FILENO, text, sizeof text - 1);
    _exit(124);
}
static void put16(uint8_t *p, unsigned v) { p[0] = v; p[1] = v >> 8; }
static void fixture(uint8_t p[8192], unsigned marker) {
    memset(p, 0, 8192); memcpy(p, "SC\x11\x01", 4);
    p[4] = (uint8_t)marker; p[0xc14] = 14;
    put16(p + 0xd8c, 0x4472 + marker);
    p[8191] = (uint8_t)(marker ^ 0x5a);
}
static NSData *readFile(NSString *path) {
    NSData *data = [NSData dataWithContentsOfFile:path]; assert(data); return data;
}
static void writeFixture(NSString *path, unsigned marker) {
    uint8_t bytes[8192]; char error[512]; fixture(bytes, marker);
    assert(a2_save_write(path.fileSystemRepresentation, bytes, error, sizeof error) == A2_SAVE_OK);
}
static void assertPayload(NSString *path, unsigned marker) {
    uint8_t expected[8192], actual[8192]; char error[512]; fixture(expected, marker);
    assert(a2_save_read(path.fileSystemRepresentation, actual, NULL, error, sizeof error));
    assert(!memcmp(actual, expected, sizeof actual));
}
static NSSet<NSString *> *saveNames(NSString *directory) {
    NSError *error = nil;
    NSArray<NSString *> *names = [NSFileManager.defaultManager contentsOfDirectoryAtPath:directory error:&error];
    assert(names && !error);
    NSMutableSet<NSString *> *result = [NSMutableSet set];
    for (NSString *name in names) if ([name.pathExtension isEqualToString:@"a2save"]) [result addObject:name];
    return result;
}
static NSString *newSave(NSSet<NSString *> *before, NSString *directory) {
    NSMutableSet<NSString *> *added = [saveNames(directory) mutableCopy]; [added minusSet:before];
    assert(added.count == 1);
    NSString *name = added.anyObject;
    assert([[NSUUID alloc] initWithUUIDString:name.stringByDeletingPathExtension]);
    return [directory stringByAppendingPathComponent:name];
}
static void cardFixture(NSString *path) {
    NSMutableData *data = [NSMutableData dataWithLength:131072];
    uint8_t *p = data.mutableBytes; memcpy(p, "MC", 2); p[127] = 'M' ^ 'C';
    uint8_t *entry = p + 128;
    entry[0] = 0x51; put16(entry + 4, 8192); put16(entry + 8, 0xffff);
    memcpy(entry + 10, "BISCPS-1011500", 15);
    for (unsigned i = 0; i < 127; i++) entry[127] ^= entry[i];
    fixture(p + 8192, 17);
    assert([data writeToFile:path atomically:YES]);
}

/* Literal location expectations are from PACK0 e378 translations. Native UI
 * expands the texture-only abbreviations for Tomb/Dark Island and spacing. */
static void metadataContracts(void) {
    NSArray<NSString *> *expected = @[
        @"Каюта", @"Пако", @"Каюта 2", @"Пако 2", @"Гю-Йорк", @"Бык 2",
        @"Уэброк 1", @"Гавань", @"Пуэрто", @"Мерседес 1", @"Пещера", @"Ванилла",
        @"Гвабакакао", @"Салон", @"Обломки", @"Чайка 2", @"Эдем 1", @"Эдем 2",
        @"Церковь", @"Огнедрак", @"Дракон 1", @"Гробница 2", @"Нунуги", @"Ключ 1",
        @"Ключ 2", @"Кит 2", @"Эдем", @"Церковь 2", @"Мерседес 2", @"Темница",
        @"Кит 1", @"Чайка 1", @"Мерседес 3", @"Бык 1", @"Гробница 1", @"Уэброк 2",
        @"Тёмный остров", @"Озеро", @"Дракон 2", @"Тёмный остров"
    ];
    for (uint16_t i = 0; i < 40; i++) assert([A2Location(i) isEqualToString:expected[i]]);
    assert([A2Location(40) isEqualToString:@"Место неизвестно"]);
    assert([A2Location(UINT16_MAX) isEqualToString:@"Место неизвестно"]);
    struct { unsigned hours, minutes, ticks; const char *text; } clocks[] = {
        {0, 0, 0, "0 ч 0 мин"}, {0, 9, 279, "0 ч 9 мин"}, {99, 59, 3599, "99 ч 59 мин"},
        {100, 0, 0, "Неизвестно"}, {0, 60, 0, "Неизвестно"}, {0, 0, 3600, "Неизвестно"}
    };
    uint8_t p[8192] = {0};
    for (unsigned i = 0; i < sizeof clocks / sizeof clocks[0]; i++) {
        put16(p + 0x104, clocks[i].hours); put16(p + 0x106, clocks[i].minutes); put16(p + 0x108, clocks[i].ticks);
        assert([A2Playtime(p) isEqualToString:[NSString stringWithUTF8String:clocks[i].text]]);
    }
    a2s.text_language = 2;
    assert([A2SaveErrorDetail(@"Сохранение доступно у точек сохранения. Загрузка доступна во время обычной игры.") containsString:@"save points"]);
    assert([A2SaveErrorDetail(@"Сейчас это действие недоступно. Вернитесь к обычной игре и повторите попытку.") containsString:@"normal play"]);
    assert([A2SaveErrorDetail(@"Unrecognized save condition") isEqualToString:@"Unrecognized save condition"]);
    assert(A2SaveDurabilityWarning(@"Save was published, but directory sync failed: test"));
    assert([A2SaveErrorDetail(@"Save was published, but directory sync failed: test") containsString:@"available to load"]);
    assert([A2Location(0) isEqualToString:@"Cabin"]);
    assert([A2Location(4) isEqualToString:@"Toroledo"]);
    memset(p, 0, sizeof p); put16(p + 0x104, 2); put16(p + 0x106, 3);
    assert([A2Playtime(p) isEqualToString:@"2 h 3 min"]);
    a2s.text_language = 1;
    assert([A2SaveErrorDetail(@"Сохранение доступно у точек сохранения.") containsString:@"セーブポイント"]);
    assert([A2SaveErrorDetail(@"Save was published, but directory sync failed: test") containsString:@"ロードできます"]);
    assert([A2Location(1) isEqualToString:@"パコの村"]);
    assert([A2Playtime(p) isEqualToString:@"2時間3分"]);
    a2s.text_language = 0;
}

typedef NS_ENUM(NSInteger, TestCase) {
    LoadCancel, LoadValid, SaveNew, ReplaceCancel, ReplaceConfirm, InvalidLoad, ImportCopy, ControllerLoad
};
@interface ModalDriver : NSObject
@property TestCase testCase;
@property unsigned step;
@property unsigned ticks;
@property unsigned events;
@property(strong) A2SaveBrowser *browser;
@property(copy) NSString *capture;
@property BOOL captured;
- (void)tick:(NSTimer *)timer;
@end
@implementation ModalDriver
- (void)selectName:(NSString *)name {
    NSInteger index = -1;
    for (NSUInteger i = 0; i < self.browser.rows.count; i++)
        if ([self.browser.rows[i].path.lastPathComponent isEqualToString:name]) index = (NSInteger)i;
    assert(index >= 0);
    [self.browser.table selectRowIndexes:[NSIndexSet indexSetWithIndex:(NSUInteger)index] byExtendingSelection:NO];
}
- (void)key:(unsigned short)code characters:(NSString *)characters table:(BOOL)table {
    /* A separate one-shot timer lets the driver continue inside nested alerts;
     * a repeating timer cannot recursively fire itself while keyDown blocks. */
    __weak ModalDriver *weakSelf = self;
    NSTimer *eventTimer = [NSTimer timerWithTimeInterval:0.01 repeats:NO block:^(NSTimer *t) {
        (void)t; ModalDriver *self = weakSelf; assert(self);
        NSWindow *window = NSApp.modalWindow; assert(window);
        NSEvent *event = [NSEvent keyEventWithType:NSEventTypeKeyDown location:NSZeroPoint modifierFlags:0
            timestamp:NSProcessInfo.processInfo.systemUptime windowNumber:window.windowNumber context:nil
            characters:characters charactersIgnoringModifiers:characters isARepeat:NO keyCode:code];
        self.events++;
        if (table) [self.browser.table keyDown:event];
        else {
            /* Deliver to this owned modal window. NSApp sendEvent can be
             * redirected if the human switches to another app mid-test. */
            assert([window performKeyEquivalent:event]);
        }
    }];
    [NSRunLoop.mainRunLoop addTimer:eventTimer forMode:NSModalPanelRunLoopMode];
}
- (void)tick:(NSTimer *)timer {
    (void)timer;
    if (!self.browser) {
        id delegate = NSApp.modalWindow.delegate;
        if (![delegate isKindOfClass:A2SaveBrowser.class]) return;
        self.browser = delegate;
    }
    A2SaveBrowser *b = self.browser;
    self.ticks++;
    if (self.capture && !self.captured) {
        NSView *view = b.panel.contentView;
        [view layoutSubtreeIfNeeded]; [view displayIfNeeded];
        NSBitmapImageRep *bitmap = [view bitmapImageRepForCachingDisplayInRect:view.bounds]; assert(bitmap);
        [view cacheDisplayInRect:view.bounds toBitmapImageRep:bitmap];
        NSData *png = [bitmap representationUsingType:NSBitmapImageFileTypePNG properties:@{}];
        assert([png writeToFile:self.capture atomically:YES]); self.captured = YES;
    }
    if (self.testCase == ControllerLoad) {
        if (!NSApp.active || !b.panel.keyWindow) return;
        if (!self.step && self.ticks >= 4) {
            assert(!b.armed && !b.result);
            [self selectName:@"normal.a2save"];
            controllerButtons = UINT16_MAX; self.step = 1; self.ticks = 0;
        } else if (self.step == 1 && self.ticks >= 3) {
            assert(b.armed && !b.result);
            controllerButtons = (uint16_t)(UINT16_MAX & ~(1u << 13)); self.step = 2;
        }
        return;
    }
    if (self.testCase == LoadCancel) {
        if (self.step == 0) {
            assert(b.rows.count >= 2 && b.table.selectedRow == 0);
            self.step = 1; [self key:125 characters:@"\uF701" table:YES];
        } else if (self.step == 1 && self.events >= 1) {
            assert(b.table.selectedRow == 1); self.step = 2;
            [self key:126 characters:@"\uF700" table:YES];
        } else if (self.step == 2 && self.events >= 2) {
            assert(b.table.selectedRow == 0); self.step = 3;
            [self key:53 characters:@"\e" table:NO];
        }
        return;
    }
    if (self.step == 0) {
        if (self.testCase == SaveNew) assert(b.table.selectedRow == 0 && !b.rows[0].path.length);
        else if (self.testCase == ImportCopy) {
            [self selectName:@"card1-BISCPS-1011500-2CAEB1A3.a2save"];
            assert([b.acceptButton.title isEqualToString:@"Сохранить копию"]);
        } else [self selectName:self.testCase == InvalidLoad ? @"bad.a2save" : @"normal.a2save"];
        self.step = 1;
        [self key:36 characters:@"\r" table:YES];
        return;
    }
    if (self.testCase == ReplaceCancel || self.testCase == ReplaceConfirm || self.testCase == ImportCopy) {
        if (self.step == 1 && b.alert) {
            assert(b.alert.buttons.count == 2);
            assert([b.alert.messageText isEqualToString:self.testCase == ImportCopy
                ? @"Сохранить текущий прогресс отдельно?" : @"Заменить сохранение?"]);
            self.step = 2;
            BOOL cancel = self.testCase == ReplaceCancel;
            [self key:cancel ? 53 : 36 characters:cancel ? @"\e" : @"\r" table:NO];
        } else if (self.testCase == ReplaceCancel && self.step == 2 && !b.alert) {
            assert(!b.result && NSApp.modalWindow == b.panel);
            self.step = 3; [self key:53 characters:@"\e" table:NO];
        }
    } else if (self.testCase == InvalidLoad) {
        if (self.step == 1 && b.alert) {
            assert([b.alert.messageText isEqualToString:@"Сохранение недоступно"]);
            assert([b.alert.informativeText containsString:@"без изменений"]);
            self.step = 2; self.ticks = 0;
        } else if (self.step == 2 && self.ticks >= 4) {
            assert(b.alert && !b.result); self.step = 3;
            [self key:53 characters:@"\e" table:NO];
        } else if (self.step == 3 && !b.alert) {
            assert(!b.result && NSApp.modalWindow == b.panel);
            self.step = 4; [self key:53 characters:@"\e" table:NO];
        }
    }
}
@end

static int runCase(TestCase which, NSString *userdir, uint8_t *payload, NSString *capture) {
    const char *names[] = {"load cancel/arrows", "load exact", "save new UUID", "replace cancel", "replace confirm",
                           "invalid entry stays open", "import saved as copy", "controller held/release/confirm"};
    fprintf(stderr, "AppKit case: %s\n", names[which]);
    ModalDriver *driver = [[ModalDriver alloc] init]; driver.testCase = which; driver.capture = capture;
    controllerButtons = which == ControllerLoad ? (uint16_t)(UINT16_MAX & ~(1u << 13)) : UINT16_MAX;
    NSTimer *timer = [NSTimer timerWithTimeInterval:0.05 target:driver selector:@selector(tick:) userInfo:nil repeats:YES];
    [NSRunLoop.mainRunLoop addTimer:timer forMode:NSModalPanelRunLoopMode];
    char error[512] = "unchanged";
    alarm(10);
    int saving = which == SaveNew || which == ReplaceCancel || which == ReplaceConfirm || which == ImportCopy;
    int result = a2_macos_save_browser(userdir.fileSystemRepresentation, saving, payload, error, sizeof error);
    alarm(0); [timer invalidate];
    assert(!error[0] && driver.browser);
    if (which == ControllerLoad) assert(driver.step == 2);
    else assert(driver.events > 0);
    if (capture) assert(driver.captured);
    driver.browser = nil;
    fprintf(stderr, "PASS AppKit: %s result=%d\n", names[which], result);
    return result;
}

int main(int argc, const char *argv[]) {
    (void)argv;
    @autoreleasepool {
        metadataContracts();
        assert(signal(SIGALRM, deadline) != SIG_ERR);
        char directory[] = "/private/tmp/a2-native-ui-test.XXXXXX";
        assert(mkdtemp(directory));
        NSString *userdir = [NSString stringWithUTF8String:directory];
        NSString *saves = [userdir stringByAppendingPathComponent:@"Saves"];
        assert(mkdir(saves.fileSystemRepresentation, 0700) == 0);
        fprintf(stderr, "Isolated AppKit fixtures: %s\n", directory);
        NSString *normal = [saves stringByAppendingPathComponent:@"normal.a2save"];
        writeFixture(normal, 17); writeFixture([saves stringByAppendingPathComponent:@"other.a2save"], 23);
        [NSApplication sharedApplication];
        [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
        [NSApp finishLaunching]; [NSApp activateIgnoringOtherApps:YES];
        uint8_t bytes[8192], before[8192], expected[8192];
        memset(bytes, 0xa5, sizeof bytes); memcpy(before, bytes, sizeof bytes);
        assert(!runCase(LoadCancel, userdir, bytes, argc > 1 ? [userdir stringByAppendingPathComponent:@"panel.png"] : nil));
        assert(!memcmp(bytes, before, sizeof bytes));
        assert(runCase(LoadValid, userdir, bytes, nil)); fixture(expected, 17);
        assert(!memcmp(bytes, expected, sizeof bytes));
        NSSet<NSString *> *names = saveNames(saves);
        fixture(bytes, 33); assert(runCase(SaveNew, userdir, bytes, nil));
        assertPayload(newSave(names, saves), 33);
        NSData *original = readFile(normal);
        fixture(bytes, 45); assert(!runCase(ReplaceCancel, userdir, bytes, nil));
        assert([readFile(normal) isEqualToData:original]);
        assert(runCase(ReplaceConfirm, userdir, bytes, nil)); assertPayload(normal, 45);
        NSString *bad = [saves stringByAppendingPathComponent:@"bad.a2save"];
        NSData *corrupt = [@"bad" dataUsingEncoding:NSUTF8StringEncoding];
        assert([corrupt writeToFile:bad atomically:YES]);
        memset(bytes, 0xa5, sizeof bytes); memcpy(before, bytes, sizeof bytes);
        assert(!runCase(InvalidLoad, userdir, bytes, nil));
        assert(!memcmp(bytes, before, sizeof bytes) && [readFile(bad) isEqualToData:corrupt]);
        NSString *card = [userdir stringByAppendingPathComponent:@"memcard1.mcr"]; cardFixture(card);
        NSData *oldCard = readFile(card); char error[512];
        assert(a2_save_import_cards(directory, saves.fileSystemRepresentation, error, sizeof error) == A2_SAVE_OK);
        NSString *imported = [saves stringByAppendingPathComponent:@"card1-BISCPS-1011500-2CAEB1A3.a2save"];
        NSData *oldImport = readFile(imported); names = saveNames(saves);
        fixture(bytes, 65); assert(runCase(ImportCopy, userdir, bytes, nil));
        assertPayload(newSave(names, saves), 65);
        assert([readFile(imported) isEqualToData:oldImport] && [readFile(card) isEqualToData:oldCard]);
        memset(bytes, 0xa5, sizeof bytes);
        assert(runCase(ControllerLoad, userdir, bytes, nil)); fixture(expected, 45);
        assert(!memcmp(bytes, expected, sizeof bytes));
        if (argc < 2) assert([NSFileManager.defaultManager removeItemAtPath:userdir error:NULL]);
        puts("PASS: real AppKit native-save dialogs, keyboard/controller boundary, immutable imports and metadata");
    }
    return 0;
}
