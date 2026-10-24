/* Native settings share the SDL main thread. No guest/audio work runs here. */
#import <AppKit/AppKit.h>
#include <IOKit/hidsystem/IOLLEvent.h>
#include "native_menu_macos.h"
#include "settings.h"
#include "game_profiles.h"
#include "voice_assets.h"
#ifdef A2_NATIVE_RESOURCES
#include "native_voice.h"
#endif
#include <stdio.h>
extern uint16_t platform_native_menu_buttons(void);

static NSColor *Gold(void) { return [NSColor colorWithRed:.83 green:.70 blue:.43 alpha:1]; }
static NSColor *Ink(void) { return [NSColor colorWithRed:.067 green:.095 blue:.14 alpha:1]; }
static NSString *L(NSString *ru,NSString *ja,NSString *en) {
    return a2s.text_language==1?ja:a2s.text_language==2?en:ru;
}
static NSTextField *Label(NSString *text,CGFloat size,NSColor *color) {
    NSTextField *v=[NSTextField wrappingLabelWithString:text];
    v.font=[NSFont systemFontOfSize:size];v.textColor=color;
    v.translatesAutoresizingMaskIntoConstraints=NO;v.selectable=NO;
    return v;
}
static NSStackView *Stack(NSArray<NSView *> *views,NSUserInterfaceLayoutOrientation orientation,CGFloat spacing) {
    NSStackView *s=[NSStackView stackViewWithViews:views];s.orientation=orientation;s.spacing=spacing;
    s.alignment=orientation==NSUserInterfaceLayoutOrientationVertical?NSLayoutAttributeLeading:NSLayoutAttributeCenterY;
    s.translatesAutoresizingMaskIntoConstraints=NO;return s;
}
static NSView *Row(NSString *text,NSView *control) {
    NSTextField *label=Label(text,14,NSColor.labelColor);
    [label.widthAnchor constraintEqualToConstant:200].active=YES;
    control.translatesAutoresizingMaskIntoConstraints=NO;
    [control.widthAnchor constraintGreaterThanOrEqualToConstant:330].active=YES;
    NSStackView *row=Stack(@[label,control],NSUserInterfaceLayoutOrientationHorizontal,20);
    [row.heightAnchor constraintGreaterThanOrEqualToConstant:34].active=YES;
    control.accessibilityLabel=text;return row;
}
@interface A2MenuButton : NSButton @end
@implementation A2MenuButton
- (BOOL)acceptsFirstResponder { return YES; }
@end

static NSButton *Button(NSString *title,id target,SEL action,NSString *identifier) {
    NSButton *b=[A2MenuButton buttonWithTitle:title target:target action:action];
    b.identifier=identifier;b.controlSize=NSControlSizeRegular;
    [b.heightAnchor constraintGreaterThanOrEqualToConstant:32].active=YES;return b;
}

@interface A2MenuBackdrop : NSView
@property BOOL hasBrand;
@end
@implementation A2MenuBackdrop
- (void)drawRect:(NSRect)rect {
    (void)rect;[Ink() setFill];NSRectFill(self.bounds);
    if(self.hasBrand) { [NSColor.blackColor setFill];NSRectFill(NSMakeRect(0,NSHeight(self.bounds)-140,NSWidth(self.bounds),140)); }
    NSRect b=NSInsetRect(self.bounds,12,12);
    [[Gold() colorWithAlphaComponent:.52] setStroke];NSBezierPath *frame=[NSBezierPath bezierPathWithRoundedRect:b xRadius:7 yRadius:7];frame.lineWidth=1;[frame stroke];
    [[Gold() colorWithAlphaComponent:.13] setStroke];NSFrameRect(NSInsetRect(b,4,4));
}
@end

@protocol A2CaptureOwner
- (BOOL)isCapturing;
- (BOOL)cancelCapture;
@end
@interface A2MenuPanel : NSPanel @end
@implementation A2MenuPanel
- (BOOL)canBecomeKeyWindow { return YES; }
- (void)sendEvent:(NSEvent *)event {
    if(event.type==NSEventTypeKeyDown && !event.isARepeat)a2_input_note_menu_keyboard();
    [super sendEvent:event];
}
- (void)cancelOperation:(id)sender { [(id)self.delegate cancel:sender]; }
- (BOOL)performKeyEquivalent:(NSEvent *)event {
    if(event.type==NSEventTypeKeyDown && [(id<A2CaptureOwner>)self.delegate isCapturing]) {
        [self.firstResponder keyDown:event];return YES;
    }
    if(event.type==NSEventTypeKeyDown && event.keyCode==122) {
        [self.delegate performSelector:@selector(cancel:) withObject:nil];return YES;
    }
    return [super performKeyEquivalent:event];
}
@end

@class A2NativeMenu;
@interface A2BindingButton : NSButton
@property int padBit;
@property int padSlot;
@property BOOL controllerBinding;
@property BOOL listening;
@property (weak) A2NativeMenu *owner;
@end
@interface A2NativeMenu : NSObject<NSWindowDelegate,A2CaptureOwner>
@property A2MenuPanel *panel;
@property NSTabView *tabs;
@property NSSegmentedControl *segments;
@property NSPopUpButton *textChoice;
@property NSPopUpButton *voiceChoice;
@property NSPopUpButton *portraits;
@property NSPopUpButton *display;
@property NSPopUpButton *resolution;
@property NSButton *filter;
@property NSButton *antialias;
@property NSButton *sound;
@property NSButton *cinema;
@property NSButton *fillScreen;
@property NSButton *skipIntro;
@property NSPopUpButton *subtitles;
@property NSPopUpButton *englishSubtitleLanguage;
@property NSSlider *threshold;
@property NSTextField *thresholdLabel;
@property NSTextField *controllerStatus;
@property NSTextField *controlHint;
@property uint32_t inputGeneration;
@property NSSlider *volume;
@property NSTextField *volumeLabel;
@property NSTextField *status;
@property NSButton *primary;
@property NSButton *startupLoad;
@property BOOL canLoad;
@property BOOL englishAvailable;
@property BOOL japaneseAvailable;
@property NSTimer *timer;
@property NSMutableArray<A2BindingButton *> *bindings;
@property int result;
@property BOOL startup;
@property uint16_t previousPad;
@property BOOL padArmed;
@property A2Settings draft;
- (void)cancel:(id)sender;
- (void)keyChanged:(A2BindingButton *)button scancode:(int)scancode;
- (void)refreshBindings;
@end
@implementation A2BindingButton
- (BOOL)acceptsFirstResponder { return YES; }
- (BOOL)becomeFirstResponder {
    BOOL accepted=[super becomeFirstResponder];
    if(accepted)[self scrollRectToVisible:NSInsetRect(self.bounds,-4,-4)];
    return accepted;
}
- (void)keyDown:(NSEvent *)event {
    if(!self.listening) { [super keyDown:event];return; }
    if(event.isARepeat)return;
    a2_input_note_menu_keyboard();
    if(event.keyCode==53 || event.keyCode==122) { self.listening=NO;[self.owner keyChanged:self scancode:-1];return; }
    if(event.keyCode==51 || event.keyCode==117) { self.listening=NO;[self.owner keyChanged:self scancode:0];return; }
    if(self.controllerBinding)return;
    if(event.keyCode==96 || event.keyCode==101 || (event.modifierFlags&NSEventModifierFlagCommand)) { NSBeep();return; }
    /* SDL translates the active keyboard layout into its physical scancode.
     * The native key table below uses macOS hardware codes, matching SDL's
     * physical-position mapping including arrows and modifiers. */
    static const struct { unsigned short mac; int sdl; } map[]={
        {0,SDL_SCANCODE_A},{1,SDL_SCANCODE_S},{2,SDL_SCANCODE_D},{3,SDL_SCANCODE_F},
        {4,SDL_SCANCODE_H},{5,SDL_SCANCODE_G},{6,SDL_SCANCODE_Z},{7,SDL_SCANCODE_X},
        {8,SDL_SCANCODE_C},{9,SDL_SCANCODE_V},{11,SDL_SCANCODE_B},{12,SDL_SCANCODE_Q},
        {13,SDL_SCANCODE_W},{14,SDL_SCANCODE_E},{15,SDL_SCANCODE_R},{16,SDL_SCANCODE_Y},
        {17,SDL_SCANCODE_T},{18,SDL_SCANCODE_1},{19,SDL_SCANCODE_2},{20,SDL_SCANCODE_3},
        {21,SDL_SCANCODE_4},{22,SDL_SCANCODE_6},{23,SDL_SCANCODE_5},{24,SDL_SCANCODE_EQUALS},
        {25,SDL_SCANCODE_9},{26,SDL_SCANCODE_7},{27,SDL_SCANCODE_MINUS},{28,SDL_SCANCODE_8},
        {29,SDL_SCANCODE_0},{30,SDL_SCANCODE_RIGHTBRACKET},{31,SDL_SCANCODE_O},{32,SDL_SCANCODE_U},
        {33,SDL_SCANCODE_LEFTBRACKET},{34,SDL_SCANCODE_I},{35,SDL_SCANCODE_P},{36,SDL_SCANCODE_RETURN},
        {37,SDL_SCANCODE_L},{38,SDL_SCANCODE_J},{39,SDL_SCANCODE_APOSTROPHE},{40,SDL_SCANCODE_K},
        {41,SDL_SCANCODE_SEMICOLON},{42,SDL_SCANCODE_BACKSLASH},{43,SDL_SCANCODE_COMMA},
        {44,SDL_SCANCODE_SLASH},{45,SDL_SCANCODE_N},{46,SDL_SCANCODE_M},{47,SDL_SCANCODE_PERIOD},
        {48,SDL_SCANCODE_TAB},{49,SDL_SCANCODE_SPACE},{50,SDL_SCANCODE_GRAVE},{51,SDL_SCANCODE_BACKSPACE},
        {123,SDL_SCANCODE_LEFT},{124,SDL_SCANCODE_RIGHT},{125,SDL_SCANCODE_DOWN},{126,SDL_SCANCODE_UP},
        {120,SDL_SCANCODE_F2},{99,SDL_SCANCODE_F3},{118,SDL_SCANCODE_F4},
        {97,SDL_SCANCODE_F6},{98,SDL_SCANCODE_F7},{100,SDL_SCANCODE_F8},
        {109,SDL_SCANCODE_F10},{103,SDL_SCANCODE_F11},{111,SDL_SCANCODE_F12},
        {71,SDL_SCANCODE_NUMLOCKCLEAR},{65,SDL_SCANCODE_KP_PERIOD},{67,SDL_SCANCODE_KP_MULTIPLY},
        {69,SDL_SCANCODE_KP_PLUS},{75,SDL_SCANCODE_KP_DIVIDE},{76,SDL_SCANCODE_KP_ENTER},
        {78,SDL_SCANCODE_KP_MINUS},{81,SDL_SCANCODE_KP_EQUALS},{82,SDL_SCANCODE_KP_0},
        {83,SDL_SCANCODE_KP_1},{84,SDL_SCANCODE_KP_2},{85,SDL_SCANCODE_KP_3},
        {86,SDL_SCANCODE_KP_4},{87,SDL_SCANCODE_KP_5},{88,SDL_SCANCODE_KP_6},
        {89,SDL_SCANCODE_KP_7},{91,SDL_SCANCODE_KP_8},{92,SDL_SCANCODE_KP_9},
        {115,SDL_SCANCODE_HOME},{119,SDL_SCANCODE_END},{116,SDL_SCANCODE_PAGEUP},{121,SDL_SCANCODE_PAGEDOWN},
        {10,SDL_SCANCODE_NONUSBACKSLASH},{93,SDL_SCANCODE_INTERNATIONAL3},{94,SDL_SCANCODE_INTERNATIONAL1},
        {95,SDL_SCANCODE_KP_COMMA}
    };
    for(unsigned i=0;i<sizeof map/sizeof map[0];i++)if(map[i].mac==event.keyCode) {
        self.listening=NO;[self.owner keyChanged:self scancode:map[i].sdl];return;
    }
    NSBeep();
}
- (void)flagsChanged:(NSEvent *)event {
    if(!self.listening || self.controllerBinding)return;
    int sc=event.keyCode==56?SDL_SCANCODE_LSHIFT:event.keyCode==60?SDL_SCANCODE_RSHIFT:
        event.keyCode==58?SDL_SCANCODE_LALT:event.keyCode==61?SDL_SCANCODE_RALT:
        event.keyCode==59?SDL_SCANCODE_LCTRL:event.keyCode==62?SDL_SCANCODE_RCTRL:0;
    NSUInteger mask=event.keyCode==56?NX_DEVICELSHIFTKEYMASK:event.keyCode==60?NX_DEVICERSHIFTKEYMASK:
        event.keyCode==58?NX_DEVICELALTKEYMASK:event.keyCode==61?NX_DEVICERALTKEYMASK:
        event.keyCode==59?NX_DEVICELCTLKEYMASK:event.keyCode==62?NX_DEVICERCTLKEYMASK:0;
    if(!(event.modifierFlags&mask))return; /* release, including the other Shift still held */
    if(sc) { a2_input_note_menu_keyboard();self.listening=NO;[self.owner keyChanged:self scancode:sc]; }
}
@end

@implementation A2NativeMenu
- (BOOL)windowShouldClose:(NSWindow *)sender { (void)sender;[self cancel:nil];return NO; }
- (BOOL)isCapturing { for(A2BindingButton *b in self.bindings)if(b.listening)return YES;return NO; }
- (BOOL)cancelCapture {
    BOOL had=[self isCapturing];for(A2BindingButton *b in self.bindings)b.listening=NO;
    a2_input_capture_cancel();[self refreshBindings];return had;
}
- (void)finish:(int)result { [self cancelCapture];self.result=result;[NSApp stopModal]; }
- (void)cancel:(id)sender { (void)sender;if([self cancelCapture])return;[self finish:self.startup?A2_MENU_QUIT:A2_MENU_RESUME]; }
- (void)resume:(id)sender { (void)sender;[self finish:A2_MENU_RESUME]; }
- (void)save:(id)sender { (void)sender;[self finish:A2_MENU_SAVE]; }
- (void)load:(id)sender { (void)sender;[self finish:A2_MENU_LOAD]; }
- (void)quit:(id)sender {
    (void)sender;
    NSAlert *alert=[[NSAlert alloc] init];
    alert.messageText=L(@"Выйти из игры?",@"ゲームを終了しますか？",@"Quit the game?");
    alert.informativeText=L(@"Несохранённый прогресс будет потерян.",@"保存されていない進行状況は失われます。",@"Unsaved progress will be lost.");
    [alert addButtonWithTitle:L(@"Продолжить игру",@"ゲームに戻る",@"Keep playing")];
    [alert addButtonWithTitle:L(@"Выйти",@"終了",@"Quit")];
    if([alert runModal]==NSAlertSecondButtonReturn)[self finish:A2_MENU_QUIT];
}
- (void)tab:(id)sender { (void)sender;[self cancelCapture];[self.tabs selectTabViewItemAtIndex:self.segments.selectedSegment]; }
- (void)changed:(id)sender {
    if(sender==self.textChoice) {
        /* Version presets follow the source edition; voice remains editable. */
        [self.voiceChoice selectItemWithTag:self.textChoice.selectedTag==1?0:1];
    }
    A2Settings d=self.draft;
    d.text_language=(int)self.textChoice.selectedTag;
    d.voice_language=(int)self.voiceChoice.selectedTag;
    d.hd_portraits=(int)self.portraits.selectedTag;
    d.wide=1;
    d.filter=self.filter.state==NSControlStateValueOn;
    d.antialias=self.antialias.state==NSControlStateValueOn;
    d.sound=self.sound.state==NSControlStateValueOn;
    d.cinema=self.cinema.state==NSControlStateValueOn;
    d.fill_screen=self.fillScreen.state==NSControlStateValueOn;
    d.skip_intro=self.skipIntro.state==NSControlStateValueOn;
    d.subtitles=(int)self.subtitles.selectedTag;
    d.english_subtitle_language=(int)self.englishSubtitleLanguage.selectedTag;
    d.pad_deadzone=(int)self.threshold.integerValue;
    d.master_volume=(int)self.volume.integerValue;
    d.irscale=(int)self.resolution.selectedTag;
    int mode=(int)self.display.selectedTag;
    d.fullscreen=mode==3;
    if(mode==1) { d.window_w=960;d.window_h=720; }
    else if(mode==2) { d.window_w=1280;d.window_h=720; }
    else if(mode==4) { d.window_w=1920;d.window_h=1080; }
    self.draft=d;
    self.volumeLabel.stringValue=[NSString stringWithFormat:@"%d%%",d.master_volume];
    self.thresholdLabel.stringValue=[NSString stringWithFormat:@"%d%%",(d.pad_deadzone*100+16383)/32767];
    self.volume.enabled=d.sound;
    BOOL language=d.text_language!=a2s.text_language || d.voice_language!=a2s.voice_language;
    BOOL ir=((d.irscale==1)!=(a2s.irscale==1));
    BOOL available=a2_profile_available(d.text_language) && (d.voice_language==0 ? self.japaneseAvailable : self.englishAvailable);
    self.primary.enabled=!self.startup || available;
    self.startupLoad.enabled=self.canLoad && available;
    if(self.startup && !available) {
        self.status.stringValue=L(@"Данные выбранной версии или озвучки не установлены. Выберите доступный вариант.",@"選択したテキストまたは音声データがありません。利用可能なものを選んでください。",@"The selected edition or voice data is not installed. Choose an available option.");
        return;
    }
    self.status.stringValue=!self.startup && (language || ir)
        ? L(@"Язык и переход между 1× и HD применятся при следующем запуске.",@"言語と1×・HDの切り替えは次回起動時に適用されます。",@"Language and changes between 1× and HD apply next launch.")
        : L(@"Настройки сохраняются автоматически.",@"設定は自動的に保存されます。",@"Settings are saved automatically.");
}
- (void)bind:(A2BindingButton *)button {
    [self cancelCapture];
    button.listening=YES;button.title=button.controllerBinding
        ? L(@"Отпустите, затем нажмите…",@"離してから入力…",@"Release, then press…")
        : L(@"Нажмите клавишу…",@"キーを押してください…",@"Press a key…");
    if(button.controllerBinding)a2_input_capture_begin();
    [self.panel makeFirstResponder:button];
}
- (void)keyChanged:(A2BindingButton *)button scancode:(int)scancode {
    A2Settings d=self.draft;
    if(button.controllerBinding && scancode==0) {
        a2_input_bind_pad(d.pad,button.padBit,button.padSlot,(A2PadBinding){0,0});
    } else if(!button.controllerBinding && scancode>=0 && !a2_input_key_reserved(scancode)) {
        for(int i=0;i<16;i++)if(d.key[i]==scancode)d.key[i]=0;
        d.key[button.padBit]=scancode;
    }
    self.draft=d;
    a2_input_capture_cancel();[self refreshBindings];
}
- (void)resetKeys:(id)sender {
    (void)sender;[self cancelCapture];A2Settings d=self.draft;settings_default_keys(d.key);self.draft=d;[self refreshBindings];
}
- (void)resetPad:(id)sender {
    (void)sender;[self cancelCapture];A2Settings d=self.draft;a2_input_default_pad(d.pad);self.draft=d;[self refreshBindings];
}
- (void)refreshBindings {
    A2Settings d=self.draft;const A2InputDevice *device=a2_input_device();
    for(A2BindingButton *b in self.bindings) {
        if(b.controllerBinding)b.enabled=device->connected;
        if(b.listening)continue;
        A2InputPrompt p;
        if(b.controllerBinding)a2_input_binding_prompt(d.pad[b.padBit][b.padSlot],&p);
        else a2_input_key_prompt(d.key[b.padBit],&p);
        b.title=[NSString stringWithUTF8String:p.label]?:@"—";
    }
    NSString *input=a2_input_source()==A2_INPUT_KEYBOARD?L(@"Клавиатура",@"キーボード",@"Keyboard"):L(@"Геймпад",@"コントローラー",@"Gamepad");
    NSString *pad=device->connected?([NSString stringWithUTF8String:device->name]?:L(@"Геймпад",@"コントローラー",@"Gamepad")):
        L(@"Геймпад не подключён",@"コントローラー未接続",@"No gamepad connected");
    self.controllerStatus.stringValue=[NSString stringWithFormat:@"%@ · %@",input,pad];
    char chord[160];a2_input_menu_chord_prompt(chord,sizeof chord);
    NSString *shortcut=[NSString stringWithUTF8String:chord];
    self.controlHint.stringValue=[NSString stringWithFormat:L(@"Esc — отменить назначение · Delete — очистить · Пауза: F1 / Esc или %@",@"Esc: 割り当て取消 · Delete: 解除 · ポーズ: F1 / Esc または %@",@"Esc cancels assignment · Delete clears · Pause: F1 / Esc or %@"),shortcut];
    self.inputGeneration=a2_input_prompt_generation();
}
- (void)pollController:(NSTimer *)timer {
    (void)timer;uint16_t down=(uint16_t)~platform_native_menu_buttons();
    if(self.inputGeneration!=a2_input_prompt_generation())[self refreshBindings];
    for(A2BindingButton *b in self.bindings)if(b.listening) {
        if(b.controllerBinding) {
            A2PadBinding captured;
            if(!a2_input_device()->connected) { [self cancelCapture]; }
            else if(a2_input_capture_poll(&captured)) {
                A2Settings d=self.draft;a2_input_bind_pad(d.pad,b.padBit,b.padSlot,captured);self.draft=d;
                [self cancelCapture];
            }
        }
        self.padArmed=NO;self.previousPad=down;return;
    }
    if(!self.padArmed) { if(!down)self.padArmed=YES;self.previousPad=down;return; }
    uint16_t edge=down & (uint16_t)~self.previousPad;self.previousPad=down;
    if(NSApp.modalWindow!=self.panel)return;
    if(edge & (1u<<13)) { [self cancel:nil];return; }
    if(edge & (1u<<3)) { if(self.primary.enabled)[self resume:nil];return; }
    if(edge & ((1u<<4)|(1u<<10))) [self.panel selectPreviousKeyView:nil];
    if(edge & ((1u<<6)|(1u<<11))) [self.panel selectNextKeyView:nil];
    NSResponder *responder=self.panel.firstResponder;
    if(edge & ((1u<<7)|(1u<<5))) {
        int direction=(edge & (1u<<5))?1:-1;
        if([responder isKindOfClass:NSPopUpButton.class]) {
            NSPopUpButton *p=(NSPopUpButton *)responder;NSInteger n=p.numberOfItems,i=p.indexOfSelectedItem;
            for(NSInteger tries=0;tries<n;tries++) { i=(i+direction+n)%n;if([p itemAtIndex:i].enabled)break; }
            [p selectItemAtIndex:i];[p sendAction:p.action to:p.target];
        } else if([responder isKindOfClass:NSSlider.class]) {
            NSSlider *s=(NSSlider *)responder;double step=s==self.threshold?1024:5;
            s.doubleValue=MAX(s.minValue,MIN(s.maxValue,s.doubleValue+direction*step));[s sendAction:s.action to:s.target];
        } else if([responder isKindOfClass:NSSegmentedControl.class]) {
            self.segments.selectedSegment=(self.segments.selectedSegment+direction+4)%4;[self tab:nil];
        }
    }
    if(edge & (1u<<14)) {
        if([responder isKindOfClass:NSButton.class])[(NSButton *)responder performClick:nil];
        else if([responder isKindOfClass:NSPopUpButton.class])[(NSPopUpButton *)responder performClick:nil];
    }
}
@end

@interface A2ControlsDocument : NSView @end
@implementation A2ControlsDocument
- (BOOL)isFlipped { return YES; }
@end

static NSPopUpButton *Popup(A2NativeMenu *menu,NSArray<NSString *> *titles,NSArray<NSNumber *> *values,int selected,NSString *identifier) {
    NSPopUpButton *p=[[NSPopUpButton alloc] initWithFrame:NSZeroRect pullsDown:NO];
    [p addItemsWithTitles:titles];for(NSUInteger i=0;i<values.count;i++)[p itemAtIndex:i].tag=values[i].integerValue;
    [p selectItemWithTag:selected];p.target=menu;p.action=@selector(changed:);p.identifier=identifier;return p;
}
static NSButton *Check(A2NativeMenu *menu,NSString *title,BOOL on,NSString *identifier) {
    NSButton *b=[A2MenuButton checkboxWithTitle:title target:menu action:@selector(changed:)];
    b.state=on?NSControlStateValueOn:NSControlStateValueOff;b.identifier=identifier;return b;
}
static void AddTab(A2NativeMenu *menu,NSString *name,NSArray<NSView *> *rows) {
    NSTabViewItem *tab=[[NSTabViewItem alloc] initWithIdentifier:name];tab.label=name;
    NSView *v=[[NSView alloc] init];NSStackView *body=Stack(rows,NSUserInterfaceLayoutOrientationVertical,12);[v addSubview:body];
    [NSLayoutConstraint activateConstraints:@[
        [body.leadingAnchor constraintEqualToAnchor:v.leadingAnchor constant:24],
        [body.trailingAnchor constraintLessThanOrEqualToAnchor:v.trailingAnchor constant:-24],
        [body.topAnchor constraintEqualToAnchor:v.topAnchor constant:22],
        [body.bottomAnchor constraintLessThanOrEqualToAnchor:v.bottomAnchor constant:-16]
    ]];tab.view=v;[menu.tabs addTabViewItem:tab];
}

int a2_macos_game_menu(int startup,int can_save,int can_load) {
    @autoreleasepool {
        a2_input_set_menu_active(1);
        A2NativeMenu *menu=[[A2NativeMenu alloc] init];menu.startup=!!startup;menu.draft=a2s;
        menu.result=startup?A2_MENU_QUIT:A2_MENU_RESUME;menu.previousPad=0;menu.canLoad=can_load;
        NSRect rect=NSMakeRect(0,0,800,740);
        A2MenuPanel *panel=[[A2MenuPanel alloc] initWithContentRect:rect
            styleMask:NSWindowStyleMaskTitled|NSWindowStyleMaskClosable backing:NSBackingStoreBuffered defer:NO];
        menu.panel=panel;panel.delegate=menu;panel.releasedWhenClosed=NO;
        panel.title=startup?L(@"Алундра 2",@"アランドラ2",@"Alundra 2"):L(@"Алундра 2 — Пауза",@"アランドラ2 — 一時停止",@"Alundra 2 — Paused");
        panel.appearance=[NSAppearance appearanceNamed:NSAppearanceNameDarkAqua];
        panel.titlebarAppearsTransparent=YES;panel.backgroundColor=Ink();
        A2MenuBackdrop *content=[[A2MenuBackdrop alloc] initWithFrame:rect];panel.contentView=content;
        NSTextField *title=Label(L(@"АЛУНДРА 2",@"アランドラ2",@"ALUNDRA 2"),34,Gold());
        title.font=[NSFont fontWithName:@"Georgia-Bold" size:34]?:[NSFont systemFontOfSize:34 weight:NSFontWeightSemibold];
        NSTextField *subtitle=Label(startup?L(@"Ваше приключение начинается здесь",@"冒険はここから始まる",@"Your adventure begins here"):
            L(@"Игра приостановлена",@"ゲームは一時停止しています",@"The game is paused"),14,NSColor.secondaryLabelColor);
        NSStackView *heading=Stack(@[title,subtitle],NSUserInterfaceLayoutOrientationVertical,7);
        NSString *brand=[[NSString stringWithUTF8String:a2_profile_root()] stringByAppendingPathComponent:@"../branding/alundra2-hd-black.png"];
        NSImage *logo=[[NSImage alloc] initWithContentsOfFile:brand];
        if(logo) {
            content.hasBrand=YES;
            NSImageView *art=[NSImageView imageViewWithImage:logo];art.imageScaling=NSImageScaleProportionallyUpOrDown;
            art.translatesAutoresizingMaskIntoConstraints=NO;art.accessibilityLabel=title.stringValue;
            [art.widthAnchor constraintEqualToConstant:320].active=YES;[art.heightAnchor constraintEqualToConstant:88].active=YES;
            [heading removeArrangedSubview:title];[title removeFromSuperview];[heading insertArrangedSubview:art atIndex:0];
        }
        NSArray *tabNames=@[L(@"Игра",@"ゲーム",@"Game"),L(@"Изображение",@"画面",@"Display"),L(@"Звук",@"音声",@"Sound"),L(@"Управление",@"操作",@"Controls")];
        menu.segments=[NSSegmentedControl segmentedControlWithLabels:tabNames trackingMode:NSSegmentSwitchTrackingSelectOne target:menu action:@selector(tab:)];
        menu.segments.selectedSegment=0;menu.segments.translatesAutoresizingMaskIntoConstraints=NO;
        menu.segments.identifier=@"settings-tabs";menu.segments.accessibilityLabel=L(@"Раздел настроек",@"設定カテゴリ",@"Settings category");
        for(NSInteger i=0;i<4;i++)[menu.segments setWidth:170 forSegment:i];
        menu.tabs=[[NSTabView alloc] init];menu.tabs.tabViewType=NSNoTabsNoBorder;menu.tabs.translatesAutoresizingMaskIntoConstraints=NO;
        menu.tabs.wantsLayer=YES;menu.tabs.layer.backgroundColor=[NSColor colorWithWhite:1 alpha:.035].CGColor;
        menu.tabs.layer.cornerRadius=5;menu.tabs.layer.borderWidth=1;menu.tabs.layer.borderColor=[Gold() colorWithAlphaComponent:.22].CGColor;
        menu.textChoice=Popup(menu,@[@"Русский",@"日本語",@"English"],@[@0,@1,@2],a2s.text_language,@"text-language");
        for(int i=0;i<3;i++)if(!a2_profile_available(i)) {
            NSMenuItem *item=[menu.textChoice.menu itemWithTag:i];item.enabled=NO;
            item.title=[item.title stringByAppendingString:L(@" — не установлено",@" — 未インストール",@" — not installed")];
            item.toolTip=[NSString stringWithUTF8String:a2_profile_reason(i)];
        }
        menu.textChoice.autoenablesItems=NO;
        menu.voiceChoice=Popup(menu,@[L(@"Японская (оригинал)",@"日本語（オリジナル）",@"Japanese (original)"),L(@"Английская",@"英語",@"English")],@[@0,@1],a2s.voice_language,@"voice-language");
        menu.voiceChoice.autoenablesItems=NO;
        char voice[4096];BOOL english=a2_profile_voice_path(1,voice,sizeof voice) && a2_voice_available_for_language(voice,1);
        menu.japaneseAvailable=a2_profile_voice_path(0,voice,sizeof voice) && a2_voice_available_for_language(voice,0);
#ifdef A2_NATIVE_RESOURCES
        if(a2_profile_resources()) {
            english=a2_native_voice_available(a2_profile_resources(),1);
            menu.japaneseAvailable=a2_native_voice_available(a2_profile_resources(),0);
        }
#endif
        [menu.voiceChoice.menu itemWithTag:0].enabled=menu.japaneseAvailable;
        if(!menu.japaneseAvailable)[menu.voiceChoice.menu itemWithTag:0].title=L(@"Японская — нет полного аудиопакета",@"日本語 — 完全な音声パックなし",@"Japanese — complete voice pack missing");
        menu.englishAvailable=english;[menu.voiceChoice.menu itemWithTag:1].enabled=english;
        if(!english)[menu.voiceChoice.menu itemWithTag:1].title=L(@"Английская — не установлена",@"英語 — 未インストール",@"English — not installed");
        menu.subtitles=Popup(menu,@[L(@"Автоматически",@"自動",@"Automatic"),L(@"Включены",@"オン",@"On"),L(@"Выключены",@"オフ",@"Off")],@[@0,@1,@2],a2s.subtitles,@"cutscene-subtitles");
        menu.englishSubtitleLanguage=Popup(menu,@[L(@"По языку текста",@"テキスト言語に合わせる",@"Follow text language"),@"Русский",@"English"],@[@0,@1,@2],a2s.english_subtitle_language,@"english-subtitle-language");
        menu.englishSubtitleLanguage.toolTip=L(@"Язык субтитров английской озвучки можно выбрать независимо от текста игры.",@"英語音声の字幕言語はゲームのテキストとは別に選択できます。",@"Choose English voice subtitles independently of the game text.");
        menu.skipIntro=Check(menu,L(@"Пропускать заставки при запуске",@"起動時の映像をスキップ",@"Skip startup movies"),a2s.skip_intro,@"skip-intro");
        menu.portraits=Popup(menu,@[L(@"Стандартные",@"オリジナル",@"Original"),L(@"HD-портреты",@"HDポートレート",@"HD portraits")],@[@0,@1],a2s.hd_portraits,@"portraits");
        NSTextField *editionHint=Label(menu.japaneseAvailable
            ? L(@"Язык текста и озвучка выбираются независимо.",@"テキストと音声は個別に選択できます。",@"Text and voice can be selected independently.")
            : L(@"Язык текста и озвучка выбираются независимо. Для японской озвучки нужен полный аудиопакет.",@"テキストと音声は個別に選択できます。日本語音声には完全な音声パックが必要です。",@"Text and voice are independent. Japanese voices require a complete voice pack."),13,NSColor.secondaryLabelColor);
        [editionHint.widthAnchor constraintEqualToConstant:640].active=YES;
        NSMutableArray *gameRows=[NSMutableArray arrayWithArray:@[Row(L(@"Язык текста",@"テキスト言語",@"Text language"),menu.textChoice),Row(L(@"Озвучка",@"音声言語",@"Voice language"),menu.voiceChoice),Row(L(@"Портреты",@"ポートレート",@"Portraits"),menu.portraits),Row(L(@"Субтитры в катсценах",@"カットシーンの字幕",@"Cutscene subtitles"),menu.subtitles),Row(L(@"Субтитры английской озвучки",@"英語音声の字幕",@"English voice subtitles"),menu.englishSubtitleLanguage),menu.skipIntro,editionHint]];
        if(startup) {
            menu.startupLoad=Button(L(@"Загрузить сохранение",@"セーブデータをロード",@"Load saved game"),menu,@selector(load:),@"startup-load");
        } else {
            NSButton *save=Button(L(@"Быстро сохранить · F5",@"クイックセーブ · F5",@"Quick save · F5"),menu,@selector(save:),@"quick-save");save.enabled=can_save;
            NSButton *load=Button(L(@"Быстро загрузить · F9",@"クイックロード · F9",@"Quick load · F9"),menu,@selector(load:),@"quick-load");load.enabled=can_load;
            [gameRows addObject:Stack(@[save,load],NSUserInterfaceLayoutOrientationHorizontal,12)];
            NSTextField *saveHint=Label(can_save?L(@"Быстрое сохранение заменяет предыдущее. Остальные сохранения доступны в меню игры.",@"クイックセーブは前回のデータを上書きします。ほかの保存データはゲーム内メニューから利用できます。",@"Quick save replaces the previous quick save. Other saves remain available in the game menu."):
                L(@"Сохранение и загрузка доступны во время обычной игры, вне диалогов и переходов.",@"セーブとロードは通常プレイ中に利用できます。会話や場面切り替えが終わるまでお待ちください。",@"Save and load during normal gameplay, outside dialogue and transitions."),12,NSColor.secondaryLabelColor);
            [saveHint.widthAnchor constraintEqualToConstant:640].active=YES;[gameRows addObject:saveHint];
        }
        AddTab(menu,tabNames[0],gameRows);
        int display=a2s.fullscreen?3:a2s.window_w==1920?4:a2s.window_w==1280?2:a2s.window_w==960?1:0;
        menu.display=Popup(menu,@[L(@"Текущий размер окна",@"現在のウィンドウサイズ",@"Current window size"),@"960 × 720",@"1280 × 720",L(@"Полный экран",@"フルスクリーン",@"Fullscreen"),@"1920 × 1080"],@[@0,@1,@2,@3,@4],display,@"display-mode");
        menu.resolution=Popup(menu,@[L(@"1× — оригинал",@"1× — オリジナル",@"1× — original"),@"2×",@"3×",@"4×"],@[@1,@2,@3,@4],a2s.irscale,@"render-resolution");
        menu.filter=Check(menu,L(@"Сглаживать текстуры",@"テクスチャ補間",@"Smooth textures"),a2s.filter,@"texture-filter");
        menu.antialias=Check(menu,L(@"Сглаживание краёв",@"アンチエイリアシング",@"Anti-aliasing"),a2s.antialias,@"antialias");
        menu.fillScreen=Check(menu,L(@"Заполнять экран во время игры",@"プレイ中は画面全体に表示",@"Fill the screen during gameplay"),a2s.fill_screen,@"fill-screen");
        menu.cinema=Check(menu,L(@"Центрировать кадр в катсценах",@"カットシーンを中央に表示",@"Center the picture in cutscenes"),a2s.cinema,@"cinematic-framing");
        NSTextField *displayHint=Label(L(@"В 1× используются оригинальные портреты. HD-портреты доступны при 2×, 3× и 4×. Переход между 1× и HD требует перезапуска.",@"1×ではオリジナルのポートレートを表示します。HDは2×以上で利用可能です。1×とHDの切り替えには再起動が必要です。",@"1× uses original portraits. HD portraits are available at 2×, 3× and 4×. Switching between 1× and HD requires a restart."),13,NSColor.secondaryLabelColor);
        [displayHint.widthAnchor constraintEqualToConstant:640].active=YES;
        NSTextField *cinemaHint=Label(L(@"Равные чёрные полосы сверху и снизу; субтитры — в нижней полосе.",@"上下の黒帯を同じ高さにし、字幕を下の帯に表示します。",@"Equal black bars above and below, with subtitles in the lower bar."),12,NSColor.secondaryLabelColor);
        [cinemaHint.widthAnchor constraintEqualToConstant:640].active=YES;
        AddTab(menu,tabNames[1],@[Row(L(@"Окно",@"ウィンドウ",@"Window"),menu.display),Row(L(@"Разрешение отрисовки",@"内部解像度",@"Render resolution"),menu.resolution),menu.antialias,menu.filter,menu.fillScreen,menu.cinema,cinemaHint,displayHint]);
        menu.sound=Check(menu,L(@"Включить звук",@"音声を有効にする",@"Enable sound"),a2s.sound,@"sound-enabled");
        menu.volume=[NSSlider sliderWithValue:a2s.master_volume minValue:0 maxValue:100 target:menu action:@selector(changed:)];
        menu.volume.identifier=@"master-volume";menu.volume.accessibilityLabel=L(@"Общая громкость",@"マスター音量",@"Master volume");
        [menu.volume.widthAnchor constraintEqualToConstant:280].active=YES;
        menu.volumeLabel=Label([NSString stringWithFormat:@"%d%%",a2s.master_volume],14,Gold());[menu.volumeLabel.widthAnchor constraintEqualToConstant:50].active=YES;
        NSStackView *volumeRow=Stack(@[menu.volume,menu.volumeLabel],NSUserInterfaceLayoutOrientationHorizontal,12);
        NSTextField *soundHint=Label(L(@"Общая громкость меняет музыку, звуки и голоса вместе. Баланс музыки и эффектов доступен в оригинальном игровом меню.",@"マスター音量は音楽・効果音・音声全体に適用されます。音楽と効果音のバランスはゲーム内メニューで調整できます。",@"Master volume changes music, effects and voices together. Music and effects balance remains available in the original game menu."),13,NSColor.secondaryLabelColor);
        [soundHint.widthAnchor constraintEqualToConstant:640].active=YES;
        AddTab(menu,tabNames[2],@[menu.sound,Row(L(@"Общая громкость",@"マスター音量",@"Master volume"),volumeRow),soundHint]);
        menu.bindings=[NSMutableArray array];NSMutableArray *controlRows=[NSMutableArray array];
        menu.controllerStatus=Label(@"",13,Gold());menu.controllerStatus.identifier=@"controller-status";
        [menu.controllerStatus.widthAnchor constraintEqualToConstant:660].active=YES;
        [controlRows addObject:menu.controllerStatus];
        NSArray *names=@[L(@"Вверх",@"上",@"Up"),L(@"Вниз",@"下",@"Down"),L(@"Влево",@"左",@"Left"),L(@"Вправо",@"右",@"Right"),@"×",@"○",@"□",@"△",@"Start",@"Select",@"L1",@"R1",@"L2",@"R2"];
        const int bits[]={4,6,7,5,14,13,15,12,3,0,10,11,8,9};
        const CGFloat widths[]={80,140,185,185};
        NSArray *headings=@[L(@"Кнопка игры",@"ゲーム",@"Game button"),L(@"Клавиатура",@"キーボード",@"Keyboard"),L(@"Геймпад",@"コントローラー",@"Gamepad"),L(@"Дополнительно",@"追加の割り当て",@"Alternate")];
        NSMutableArray *headingViews=[NSMutableArray array];
        for(int i=0;i<4;i++) { NSTextField *v=Label(headings[i],12,NSColor.secondaryLabelColor);[v.widthAnchor constraintEqualToConstant:widths[i]].active=YES;[headingViews addObject:v]; }
        NSMutableArray *gridRows=[NSMutableArray arrayWithObject:Stack(headingViews,NSUserInterfaceLayoutOrientationHorizontal,10)];
        for(int i=0;i<14;i++) {
            NSTextField *name=Label(names[i],13,NSColor.labelColor);[name.widthAnchor constraintEqualToConstant:widths[0]].active=YES;
            NSMutableArray *row=[NSMutableArray arrayWithObject:name];
            for(int col=1;col<4;col++) {
                A2BindingButton *b=[[A2BindingButton alloc] init];b.bezelStyle=NSBezelStyleRounded;b.padBit=bits[i];b.owner=menu;b.target=menu;b.action=@selector(bind:);
                b.controllerBinding=col>1;b.padSlot=col-2;
                b.identifier=col==1?[NSString stringWithFormat:@"binding-%d",bits[i]]:[NSString stringWithFormat:@"controller-binding-%d-%d",bits[i],col-2];
                b.accessibilityLabel=[NSString stringWithFormat:@"%@: %@",headings[col],names[i]];
                [b.widthAnchor constraintEqualToConstant:widths[col]].active=YES;[b.heightAnchor constraintEqualToConstant:28].active=YES;
                [menu.bindings addObject:b];[row addObject:b];
            }
            [gridRows addObject:Stack(row,NSUserInterfaceLayoutOrientationHorizontal,10)];
        }
        NSScrollView *grid=[[NSScrollView alloc] init];grid.identifier=@"control-bindings";grid.hasVerticalScroller=YES;grid.drawsBackground=NO;
        grid.scrollerStyle=NSScrollerStyleLegacy;grid.autohidesScrollers=NO;
        [grid.widthAnchor constraintEqualToConstant:660].active=YES;[grid.heightAnchor constraintEqualToConstant:256].active=YES;
        A2ControlsDocument *document=[[A2ControlsDocument alloc] initWithFrame:NSMakeRect(0,0,640,530)];
        NSStackView *rows=Stack(gridRows,NSUserInterfaceLayoutOrientationVertical,8);[document addSubview:rows];
        [NSLayoutConstraint activateConstraints:@[[rows.leadingAnchor constraintEqualToAnchor:document.leadingAnchor],
            [rows.topAnchor constraintEqualToAnchor:document.topAnchor constant:4]]];
        grid.documentView=document;[controlRows addObject:grid];
        menu.threshold=[NSSlider sliderWithValue:a2s.pad_deadzone minValue:2048 maxValue:30000 target:menu action:@selector(changed:)];
        menu.threshold.identifier=@"controller-threshold";menu.threshold.accessibilityLabel=L(@"Порог стиков и триггеров",@"スティックとトリガーの反応しきい値",@"Stick and trigger activation threshold");
        [menu.threshold.widthAnchor constraintEqualToConstant:230].active=YES;
        menu.thresholdLabel=Label(@"",13,Gold());[menu.thresholdLabel.widthAnchor constraintEqualToConstant:40].active=YES;
        NSTextField *thresholdText=Label(L(@"Порог стиков и триггеров",@"スティック・トリガーしきい値",@"Stick / trigger threshold"),13,NSColor.labelColor);
        [thresholdText.widthAnchor constraintEqualToConstant:220].active=YES;
        [controlRows addObject:Stack(@[thresholdText,menu.threshold,menu.thresholdLabel],NSUserInterfaceLayoutOrientationHorizontal,12)];
        NSButton *resetKeys=Button(L(@"Сбросить клавиатуру",@"キーを初期化",@"Reset keyboard"),menu,@selector(resetKeys:),@"reset-keyboard");
        NSButton *resetPad=Button(L(@"Сбросить геймпад",@"パッドを初期化",@"Reset gamepad"),menu,@selector(resetPad:),@"reset-gamepad");
        [controlRows addObject:Stack(@[resetKeys,resetPad],NSUserInterfaceLayoutOrientationHorizontal,12)];
        menu.controlHint=Label(@"",11,NSColor.secondaryLabelColor);[menu.controlHint.widthAnchor constraintEqualToConstant:660].active=YES;
        [controlRows addObject:menu.controlHint];[menu refreshBindings];
        AddTab(menu,tabNames[3],controlRows);
        menu.status=Label(@"",12,NSColor.secondaryLabelColor);[menu changed:nil];
        NSButton *resume=Button(startup?L(@"Начать игру",@"ゲームを始める",@"Start game"):L(@"Продолжить",@"ゲームに戻る",@"Resume"),menu,@selector(resume:),@"resume-game");resume.keyEquivalent=@"\r";menu.primary=resume;[menu changed:nil];
        NSButton *quit=Button(startup?L(@"Закрыть",@"閉じる",@"Close"):L(@"Выйти из игры",@"ゲームを終了",@"Quit game"),menu,startup?@selector(cancel:):@selector(quit:),@"quit-game");
        NSButton *escape=Button(@"",menu,@selector(cancel:),@"escape-action");escape.hidden=YES;escape.keyEquivalent=@"\e";[content addSubview:escape];
        NSStackView *buttons=Stack(startup?@[quit,menu.startupLoad,resume]:@[quit,resume],NSUserInterfaceLayoutOrientationHorizontal,12);
        for(NSView *v in @[heading,menu.segments,menu.tabs,menu.status,buttons])[content addSubview:v];
        [NSLayoutConstraint activateConstraints:@[
            [heading.leadingAnchor constraintEqualToAnchor:content.leadingAnchor constant:38],
            [heading.topAnchor constraintEqualToAnchor:content.topAnchor constant:24],
            [heading.trailingAnchor constraintLessThanOrEqualToAnchor:content.trailingAnchor constant:-38],
            [menu.segments.leadingAnchor constraintEqualToAnchor:content.leadingAnchor constant:38],
            [menu.segments.topAnchor constraintEqualToAnchor:content.topAnchor constant:146],
            [menu.tabs.topAnchor constraintEqualToAnchor:menu.segments.bottomAnchor constant:18],
            [menu.tabs.leadingAnchor constraintEqualToAnchor:content.leadingAnchor constant:30],
            [menu.tabs.trailingAnchor constraintEqualToAnchor:content.trailingAnchor constant:-30],
            [menu.tabs.bottomAnchor constraintEqualToAnchor:content.bottomAnchor constant:-102],
            [menu.status.leadingAnchor constraintEqualToAnchor:content.leadingAnchor constant:38],
            [menu.status.trailingAnchor constraintEqualToAnchor:content.trailingAnchor constant:-38],
            [menu.status.topAnchor constraintEqualToAnchor:menu.tabs.bottomAnchor constant:14],
            [buttons.trailingAnchor constraintEqualToAnchor:content.trailingAnchor constant:-38],
            [buttons.bottomAnchor constraintEqualToAnchor:content.bottomAnchor constant:-24]
        ]];
        [panel center];[panel makeKeyAndOrderFront:nil];[panel makeFirstResponder:menu.textChoice];
        menu.timer=[NSTimer timerWithTimeInterval:.025 target:menu selector:@selector(pollController:) userInfo:nil repeats:YES];
        [NSRunLoop.mainRunLoop addTimer:menu.timer forMode:NSModalPanelRunLoopMode];
        [NSRunLoop.mainRunLoop addTimer:menu.timer forMode:NSRunLoopCommonModes];
        [NSApp runModalForWindow:panel];[menu.timer invalidate];menu.timer=nil;
        if(menu.result!=A2_MENU_QUIT || !startup)a2s=menu.draft;
        a2_input_set_menu_active(0);
        [panel orderOut:nil];panel.delegate=nil;return menu.result;
    }
}
