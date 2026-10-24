/* Real AppKit controls; run manually with an owned profile root and output dir.
 * No game window, user settings, saves, or real controller state is touched. */
#import <AppKit/AppKit.h>
#include "native_menu_macos.h"
#include "settings.h"
#include "game_profiles.h"
#include "paths.h"
#include "input_virtual_type_fixture.h"
#include <assert.h>
#include <stdio.h>
A2Settings a2s;
A2Paths a2_paths;
static uint16_t fixture_navigation=0xffff;
static NSString *SouthLabel(void) {
#ifdef A2_INPUT_TEST_VIRTUAL_TYPES
    return @"×";
#else
    return @"A";
#endif
}
uint16_t platform_native_menu_buttons(void) {
    SDL_PumpEvents();SDL_Event event;
    while(SDL_PeepEvents(&event,1,SDL_GETEVENT,SDL_CONTROLLERAXISMOTION,SDL_CONTROLLERDEVICEREMAPPED)>0)a2_input_handle_event(&event);
    a2_input_poll();return fixture_navigation&a2_input_menu_buttons();
}
void settings_default_keys(int out[16]) {
    const int defaults[16]={SDL_SCANCODE_RSHIFT,0,0,SDL_SCANCODE_RETURN,
        SDL_SCANCODE_UP,SDL_SCANCODE_RIGHT,SDL_SCANCODE_DOWN,SDL_SCANCODE_LEFT,
        SDL_SCANCODE_1,SDL_SCANCODE_2,SDL_SCANCODE_Q,SDL_SCANCODE_W,
        SDL_SCANCODE_S,SDL_SCANCODE_X,SDL_SCANCODE_Z,SDL_SCANCODE_A};
    memcpy(out,defaults,sizeof defaults);
}
static NSView *Find(NSView *view,NSString *identifier) {
    if([view.identifier isEqualToString:identifier])return view;
    for(NSView *sub in view.subviews) { NSView *found=Find(sub,identifier);if(found)return found; }
    return nil;
}
static void Capture(NSWindow *window,NSString *path) {
    [window.contentView layoutSubtreeIfNeeded];
    NSBitmapImageRep *bitmap=[window.contentView bitmapImageRepForCachingDisplayInRect:window.contentView.bounds];
    [window.contentView cacheDisplayInRect:window.contentView.bounds toBitmapImageRep:bitmap];
    assert([[bitmap representationUsingType:NSBitmapImageFileTypePNG properties:@{}] writeToFile:path atomically:YES]);
}
int main(int argc,char **argv) {
    assert(argc==3);
    SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI,"0");SDL_SetHint(SDL_HINT_JOYSTICK_IOKIT,"0");SDL_SetHint(SDL_HINT_JOYSTICK_MFI,"0");
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS,"1");
    assert(!SDL_Init(SDL_INIT_GAMECONTROLLER));
    SDL_VirtualJoystickDesc descriptor={0};descriptor.version=SDL_VIRTUAL_JOYSTICK_DESC_VERSION;
    descriptor.type=SDL_JOYSTICK_TYPE_GAMECONTROLLER;descriptor.naxes=SDL_CONTROLLER_AXIS_MAX;descriptor.nbuttons=SDL_CONTROLLER_BUTTON_MAX;
    descriptor.name="Owned DualSense menu fixture";descriptor.vendor_id=0x054c;descriptor.product_id=0x0ce6;
    descriptor.axis_mask=(1u<<SDL_CONTROLLER_AXIS_MAX)-1;descriptor.button_mask=(1u<<SDL_CONTROLLER_BUTTON_MAX)-1;
    __block int device=SDL_JoystickAttachVirtualEx(&descriptor);assert(device>=0);
    __block SDL_Joystick *pad=SDL_JoystickOpen(device);assert(pad);
    SDL_JoystickID original_instance=SDL_JoystickInstanceID(pad);
    SDL_JoystickSetVirtualAxis(pad,SDL_CONTROLLER_AXIS_TRIGGERLEFT,-32768);SDL_JoystickSetVirtualAxis(pad,SDL_CONTROLLER_AXIS_TRIGGERRIGHT,-32768);
    a2_input_init();
    @autoreleasepool {
        [NSApplication sharedApplication];[NSApp setActivationPolicy:NSApplicationActivationPolicyAccessory];[NSApp finishLaunching];
        NSString *root=[NSString stringWithUTF8String:argv[1]],*output=[NSString stringWithUTF8String:argv[2]];
        setenv("A2_PROFILE_ROOT",argv[1],1);
        a2_profiles_init([[root stringByAppendingPathComponent:@"profiles/ru/disc"] UTF8String],[[root stringByAppendingPathComponent:@"profiles/ru/disc.bin"] UTF8String]);
        a2s=(A2Settings){.irscale=3,.wide=1,.sound=1,.master_volume=80,.text_language=0,.voice_language=1,.hd_portraits=1};
        for(int i=0;i<16;i++)a2s.key[i]=SDL_SCANCODE_A+i;
        a2_input_default_pad(a2s.pad);a2s.pad_deadzone=16000;a2s.cinema=1;
        a2_input_configure(a2s.key,a2s.pad,a2s.pad_deadzone);
        NSTimer *loadTimer=[NSTimer timerWithTimeInterval:.15 repeats:NO block:^(NSTimer *t) {
            (void)t;NSWindow *w=NSApp.modalWindow;
            NSButton *load=(NSButton *)Find(w.contentView,@"startup-load");
            assert(load && load.enabled && [load.title isEqualToString:@"Загрузить сохранение"]);
            assert(!Find(w.contentView,@"quick-save"));
            Capture(w,[output stringByAppendingPathComponent:@"startup-load.png"]);
            [load performClick:nil];
        }];
        [NSRunLoop.mainRunLoop addTimer:loadTimer forMode:NSModalPanelRunLoopMode];
        assert(a2_macos_game_menu(1,0,1)==A2_MENU_LOAD);
        __block int step=0;
        NSTimer *timer=[NSTimer timerWithTimeInterval:.12 repeats:YES block:^(NSTimer *t) {
            NSWindow *w=NSApp.modalWindow;if(!w)return;
            NSPopUpButton *text=(NSPopUpButton *)Find(w.contentView,@"text-language");
            NSPopUpButton *voice=(NSPopUpButton *)Find(w.contentView,@"voice-language");
            NSPopUpButton *subtitles=(NSPopUpButton *)Find(w.contentView,@"english-subtitle-language");
            NSButton *start=(NSButton *)Find(w.contentView,@"resume-game");assert(start);
            if(step==0) {
                assert(text&&voice);assert(start.enabled);assert(voice.numberOfItems==2);
                assert(subtitles&&subtitles.numberOfItems==3&&subtitles.selectedTag==0);
                [subtitles selectItemWithTag:1];[subtitles sendAction:subtitles.action to:subtitles.target];
                assert(text.selectedTag==0&&voice.selectedTag==1);
                Capture(w,[output stringByAppendingPathComponent:@"launcher.png"]);
                [text selectItemWithTag:1];[text sendAction:text.action to:text.target];
                assert(voice.selectedTag==0); /* edition presets original audio */
                [voice selectItemWithTag:1];[voice sendAction:voice.action to:voice.target];
                assert(text.selectedTag==1 && voice.selectedTag==1); /* independent override */
                assert(subtitles.selectedTag==1); /* Text changes preserve an explicit subtitle choice. */
            } else if(step==1) {
                NSSegmentedControl *tabs=(NSSegmentedControl *)Find(w.contentView,@"settings-tabs");
                tabs.selectedSegment=1;[tabs sendAction:tabs.action to:tabs.target];
                assert(Find(w.contentView,@"render-resolution"));
                assert(!Find(w.contentView,@"widescreen")); /* fixed16:9, no aspect switch */
                Capture(w,[output stringByAppendingPathComponent:@"display.png"]);
                tabs.selectedSegment=2;[tabs sendAction:tabs.action to:tabs.target];
                NSSlider *volume=(NSSlider *)Find(w.contentView,@"master-volume");volume.integerValue=37;[volume sendAction:volume.action to:volume.target];
                Capture(w,[output stringByAppendingPathComponent:@"sound.png"]);
            } else if(step==2) {
                NSSegmentedControl *tabs=(NSSegmentedControl *)Find(w.contentView,@"settings-tabs");tabs.selectedSegment=3;[tabs sendAction:tabs.action to:tabs.target];
                assert([((NSButton *)Find(w.contentView,@"controller-binding-14-0")).title isEqualToString:SouthLabel()]);
                NSButton *binding=(NSButton *)Find(w.contentView,@"binding-14");[binding performClick:nil];
                NSEvent *key=[NSEvent keyEventWithType:NSEventTypeKeyDown location:NSZeroPoint modifierFlags:0 timestamp:0 windowNumber:w.windowNumber context:nil characters:@"z" charactersIgnoringModifiers:@"z" isARepeat:NO keyCode:6];
                [w.firstResponder keyDown:key];
                [binding performClick:nil];[w cancelOperation:nil];assert(NSApp.modalWindow==w);
                assert([binding.title isEqualToString:@"Z"]);
                [binding performClick:nil];
                NSEvent *release=[NSEvent keyEventWithType:NSEventTypeFlagsChanged location:NSZeroPoint modifierFlags:0 timestamp:0 windowNumber:w.windowNumber context:nil characters:@"" charactersIgnoringModifiers:@"" isARepeat:NO keyCode:56];
                [w.firstResponder flagsChanged:release];
                assert([[binding valueForKey:@"listening"] boolValue]); /* a modifier release is not a new assignment */
                NSEvent *reserved=[NSEvent keyEventWithType:NSEventTypeKeyDown location:NSZeroPoint modifierFlags:0 timestamp:0 windowNumber:w.windowNumber context:nil characters:@"" charactersIgnoringModifiers:@"" isARepeat:NO keyCode:96];
                [w.firstResponder keyDown:reserved];assert([[binding valueForKey:@"listening"] boolValue]);
                NSEvent *clear=[NSEvent keyEventWithType:NSEventTypeKeyDown location:NSZeroPoint modifierFlags:0 timestamp:0 windowNumber:w.windowNumber context:nil characters:@"" charactersIgnoringModifiers:@"" isARepeat:NO keyCode:51];
                [w.firstResponder keyDown:clear];assert([binding.title isEqualToString:@"—"]);
                [binding performClick:nil];[w.firstResponder keyDown:key];
                assert(Find(w.contentView,@"controller-binding-14-0"));
                assert(Find(w.contentView,@"controller-binding-14-1"));
                assert(Find(w.contentView,@"controller-status"));
                NSSlider *threshold=(NSSlider *)Find(w.contentView,@"controller-threshold");assert(threshold);
                threshold.integerValue=22000;[threshold sendAction:threshold.action to:threshold.target];
                assert(!Find(w.contentView,@"input-hints")); /* controls belong to menus only */
                NSScrollView *grid=(NSScrollView *)Find(w.contentView,@"control-bindings");assert(grid&&grid.hasVerticalScroller);
                assert(grid.frame.size.height>=250); /* removed row gives bindings more space */
                Capture(w,[output stringByAppendingPathComponent:@"controls.png"]);
            } else if(step==3) {
                NSSlider *threshold=(NSSlider *)Find(w.contentView,@"controller-threshold");
                [w makeFirstResponder:threshold];fixture_navigation=(uint16_t)~(1u<<5);
            } else if(step==4) {
                fixture_navigation=0xffff;
                NSSlider *threshold=(NSSlider *)Find(w.contentView,@"controller-threshold");
                assert(threshold.integerValue>22000 && threshold.integerValue<=30000);
                threshold.integerValue=22000;[threshold sendAction:threshold.action to:threshold.target];
                NSButton *binding=(NSButton *)Find(w.contentView,@"controller-binding-13-1");assert(binding.enabled);[binding performClick:nil];
            } else if(step==5) {
                SDL_JoystickSetVirtualButton(pad,SDL_CONTROLLER_BUTTON_A,1);
            } else if(step==6) {
                SDL_JoystickSetVirtualButton(pad,SDL_CONTROLLER_BUTTON_A,0);
                assert([((NSButton *)Find(w.contentView,@"controller-binding-14-0")).title isEqualToString:@"—"]);
                assert([((NSButton *)Find(w.contentView,@"controller-binding-13-1")).title isEqualToString:SouthLabel()]);
                NSView *last=Find(w.contentView,@"binding-9");[w makeFirstResponder:last];
                NSScrollView *grid=(NSScrollView *)Find(w.contentView,@"control-bindings");
                assert(NSIntersectsRect([last convertRect:last.bounds toView:grid.documentView],grid.documentVisibleRect));
                Capture(w,[output stringByAppendingPathComponent:@"controls-bottom.png"]);
                [((NSButton *)Find(w.contentView,@"reset-keyboard")) performClick:nil];
                assert([((NSButton *)Find(w.contentView,@"binding-4")).title isEqualToString:@"Up"]);
                [((NSButton *)Find(w.contentView,@"reset-gamepad")) performClick:nil];
                assert([((NSButton *)Find(w.contentView,@"controller-binding-14-0")).title isEqualToString:SouthLabel()]);
            } else if(step==7) {
                SDL_JoystickClose(pad);pad=NULL;assert(!SDL_JoystickDetachVirtual(device));
            } else if(step==8) {
                assert(!((NSButton *)Find(w.contentView,@"controller-binding-14-0")).enabled);
                assert(!a2_input_device()->connected);
                SDL_VirtualJoystickDesc next=descriptor;next.name="Owned Xbox One menu fixture";next.vendor_id=0x045e;next.product_id=0x02ea;
                device=SDL_JoystickAttachVirtualEx(&next);assert(device>=0);pad=SDL_JoystickOpen(device);assert(pad);
                SDL_JoystickSetVirtualAxis(pad,SDL_CONTROLLER_AXIS_TRIGGERLEFT,-32768);SDL_JoystickSetVirtualAxis(pad,SDL_CONTROLLER_AXIS_TRIGGERRIGHT,-32768);
            } else if(step==9) {
                assert(a2_input_device()->connected && a2_input_device()->instance!=original_instance);
#ifdef A2_INPUT_TEST_VIRTUAL_TYPES
                assert(a2_input_device()->family==A2_PAD_XBOX);
#endif
                assert([((NSButton *)Find(w.contentView,@"controller-binding-14-0")).title isEqualToString:@"A"]);
                assert([((NSButton *)Find(w.contentView,@"controller-binding-13-0")).title isEqualToString:@"B"]);
                NSScrollView *grid=(NSScrollView *)Find(w.contentView,@"control-bindings");[grid.contentView scrollToPoint:NSZeroPoint];[grid reflectScrolledClipView:grid.contentView];
                [w makeFirstResponder:Find(w.contentView,@"controller-threshold")];
                SDL_JoystickSetVirtualButton(pad,SDL_CONTROLLER_BUTTON_A,1);
            } else if(step==10) {
                assert(a2_input_source()==A2_INPUT_CONTROLLER);
                Capture(w,[output stringByAppendingPathComponent:@"controls-xbox.png"]);
                SDL_JoystickSetVirtualButton(pad,SDL_CONTROLLER_BUTTON_A,0);
            } else { [start performClick:nil];[t invalidate]; }
            step++;
        }];
        [NSRunLoop.mainRunLoop addTimer:timer forMode:NSModalPanelRunLoopMode];
        assert(a2_macos_game_menu(1,0,0)==A2_MENU_RESUME);
        assert(a2s.text_language==1&&a2s.voice_language==1&&a2s.master_volume==37);
        assert(a2s.english_subtitle_language==1);
        assert(a2s.key[14]==SDL_SCANCODE_Z);
        assert(a2s.pad_deadzone==22000);
        assert(a2s.pad[14][0].kind==A2_BIND_BUTTON && !a2s.pad[13][1].kind);
        a2s.text_language=0;
        timer=[NSTimer timerWithTimeInterval:.15 repeats:NO block:^(NSTimer *t) {
            (void)t;NSWindow *w=NSApp.modalWindow;
            assert(!((NSButton *)Find(w.contentView,@"quick-save")).enabled);
            assert(!((NSButton *)Find(w.contentView,@"quick-load")).enabled);
            NSPopUpButton *subtitles=(NSPopUpButton *)Find(w.contentView,@"english-subtitle-language");
            assert(subtitles.selectedTag==1);
            [subtitles selectItemWithTag:2];[subtitles sendAction:subtitles.action to:subtitles.target];
            Capture(w,[output stringByAppendingPathComponent:@"pause.png"]);
            [w cancelOperation:nil];
        }];
        [NSRunLoop.mainRunLoop addTimer:timer forMode:NSModalPanelRunLoopMode];
        assert(a2_macos_game_menu(0,0,0)==A2_MENU_RESUME);
        assert(a2s.english_subtitle_language==2&&a2s.text_language==0&&a2s.voice_language==1);
        puts("native menu: edition presets, independent voice, volume, rebinding, disabled save actions and Escape passed");
    }
    a2_input_shutdown();SDL_JoystickClose(pad);SDL_JoystickDetachVirtual(device);SDL_Quit();
    return 0;
}
