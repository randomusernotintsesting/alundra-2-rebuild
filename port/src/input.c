#include "input.h"
#include <stdio.h>
#include <string.h>

static SDL_GameController *controller;
static SDL_GameControllerType controller_type;
static A2InputDevice device;
static int initialized, keymap[16], threshold=16000;
static A2PadBinding bindings[16][2];
static A2InputSource source=A2_INPUT_KEYBOARD;
static uint32_t generation=1, raw_buttons, activity_buttons;
static int16_t raw_axes[SDL_CONTROLLER_AXIS_MAX], activity_axes[SDL_CONTROLLER_AXIS_MAX];
static uint16_t raw_latch, activity_latch, keyboard_pad=0xffff, controller_pad=0xffff, menu_pad=0xffff;
static int menu_request, chord_latched, capture_active, capture_armed;
static int menu_active;
static SDL_GameControllerType get_type(SDL_GameController *pad) {
#ifdef A2_INPUT_TEST_VIRTUAL_TYPES
    /* Only test targets replace this external hardware-metadata boundary.
     * SDL2-compat labels every owned virtual device VIRTUAL, unconditionally. */
    extern SDL_GameControllerType a2_input_test_controller_type(SDL_GameController *);
    return a2_input_test_controller_type(pad);
#else
    return SDL_GameControllerGetType(pad);
#endif
}

static int clamp_threshold(int value) { return value<2048?2048:value>30000?30000:value; }
static void changed(void) { if(!++generation)generation=1; }
static void set_source(A2InputSource value) { if(source!=value) { source=value;changed(); } }
int a2_input_pad_bit_valid(int bit) { return bit==0 || (bit>=3 && bit<16); }
int a2_input_key_reserved(int sc) {
    return sc==SDL_SCANCODE_ESCAPE || sc==SDL_SCANCODE_F1 || sc==SDL_SCANCODE_F5 || sc==SDL_SCANCODE_F9;
}
int a2_input_binding_valid(A2PadBinding b) {
    if(b.kind==A2_BIND_NONE)return b.code==0;
    if(b.kind==A2_BIND_BUTTON)return b.code>=0 && b.code<SDL_CONTROLLER_BUTTON_MAX && b.code!=SDL_CONTROLLER_BUTTON_GUIDE;
    if(b.kind==A2_BIND_AXIS_POS)return b.code>=0 && b.code<SDL_CONTROLLER_AXIS_MAX;
    if(b.kind==A2_BIND_AXIS_NEG)return b.code>=0 && b.code<SDL_CONTROLLER_AXIS_TRIGGERLEFT;
    return 0;
}
int a2_input_bind_pad(A2PadBinding pad[16][2],int bit,int slot,A2PadBinding b) {
    if(!pad || !a2_input_pad_bit_valid(bit) || slot<0 || slot>1 || !a2_input_binding_valid(b))return 0;
    if(b.kind)for(int i=0;i<16;i++)for(int j=0;j<2;j++)
        if(pad[i][j].kind==b.kind && pad[i][j].code==b.code)pad[i][j]=(A2PadBinding){0,0};
    pad[bit][slot]=b;return 1;
}
void a2_input_default_pad(A2PadBinding out[16][2]) {
    static const struct { int bit,button; } map[]={
        {0,SDL_CONTROLLER_BUTTON_BACK},{3,SDL_CONTROLLER_BUTTON_START},
        {4,SDL_CONTROLLER_BUTTON_DPAD_UP},{5,SDL_CONTROLLER_BUTTON_DPAD_RIGHT},
        {6,SDL_CONTROLLER_BUTTON_DPAD_DOWN},{7,SDL_CONTROLLER_BUTTON_DPAD_LEFT},
        {10,SDL_CONTROLLER_BUTTON_LEFTSHOULDER},{11,SDL_CONTROLLER_BUTTON_RIGHTSHOULDER},
        {12,SDL_CONTROLLER_BUTTON_Y},{13,SDL_CONTROLLER_BUTTON_B},
        {14,SDL_CONTROLLER_BUTTON_A},{15,SDL_CONTROLLER_BUTTON_X}
    };
    memset(out,0,sizeof(A2PadBinding)*32);
    for(unsigned i=0;i<sizeof map/sizeof map[0];i++)out[map[i].bit][0]=(A2PadBinding){A2_BIND_BUTTON,map[i].button};
    out[8][0]=(A2PadBinding){A2_BIND_AXIS_POS,SDL_CONTROLLER_AXIS_TRIGGERLEFT};
    out[9][0]=(A2PadBinding){A2_BIND_AXIS_POS,SDL_CONTROLLER_AXIS_TRIGGERRIGHT};
    out[4][1]=(A2PadBinding){A2_BIND_AXIS_NEG,SDL_CONTROLLER_AXIS_LEFTY};
    out[5][1]=(A2PadBinding){A2_BIND_AXIS_POS,SDL_CONTROLLER_AXIS_LEFTX};
    out[6][1]=(A2PadBinding){A2_BIND_AXIS_POS,SDL_CONTROLLER_AXIS_LEFTY};
    out[7][1]=(A2PadBinding){A2_BIND_AXIS_NEG,SDL_CONTROLLER_AXIS_LEFTX};
}
uint16_t a2_input_axis_latch(uint16_t previous,const int16_t axes[SDL_CONTROLLER_AXIS_MAX],int value) {
    int press=clamp_threshold(value),release=press-2048;
    uint16_t next=0;
    for(int a=0;a<SDL_CONTROLLER_AXIS_MAX;a++)for(int sign=0;sign<2;sign++) {
        if(sign && a>=SDL_CONTROLLER_AXIS_TRIGGERLEFT)continue;
        int magnitude=sign?-(int)axes[a]:(int)axes[a];
        unsigned bit=1u<<(2*a+sign);
        if(magnitude>((previous&bit)?release:press))next|=bit;
    }
    return next;
}
static int active(A2PadBinding b,uint32_t buttons,uint16_t axes) {
    if(!a2_input_binding_valid(b) || !b.kind)return 0;
    if(b.kind==A2_BIND_BUTTON)return !!(buttons&(1u<<b.code));
    return !!(axes&(1u<<(2*b.code+(b.kind==A2_BIND_AXIS_NEG))));
}
static uint16_t map_pad(const A2PadBinding map[16][2],uint32_t buttons,uint16_t axes) {
    uint16_t result=0xffff;
    for(int bit=0;bit<16;bit++)if(a2_input_pad_bit_valid(bit))
        if(active(map[bit][0],buttons,axes)||active(map[bit][1],buttons,axes))result&=~(1u<<bit);
    return result;
}
static A2PadFamily family(SDL_GameControllerType type) {
    switch(type) {
    case SDL_CONTROLLER_TYPE_PS3:case SDL_CONTROLLER_TYPE_PS4:case SDL_CONTROLLER_TYPE_PS5:return A2_PAD_PLAYSTATION;
    case SDL_CONTROLLER_TYPE_XBOX360:case SDL_CONTROLLER_TYPE_XBOXONE:return A2_PAD_XBOX;
    case SDL_CONTROLLER_TYPE_NINTENDO_SWITCH_PRO:case SDL_CONTROLLER_TYPE_NINTENDO_SWITCH_JOYCON_LEFT:
    case SDL_CONTROLLER_TYPE_NINTENDO_SWITCH_JOYCON_RIGHT:case SDL_CONTROLLER_TYPE_NINTENDO_SWITCH_JOYCON_PAIR:return A2_PAD_NINTENDO;
    default:return A2_PAD_GENERIC;
    }
}
static void read_sample(uint32_t *buttons,int16_t axes[SDL_CONTROLLER_AXIS_MAX]) {
    *buttons=0;memset(axes,0,sizeof(int16_t)*SDL_CONTROLLER_AXIS_MAX);
    if(!controller)return;
    for(int i=0;i<SDL_CONTROLLER_BUTTON_MAX;i++)if(SDL_GameControllerGetButton(controller,(SDL_GameControllerButton)i))*buttons|=1u<<i;
    for(int i=0;i<SDL_CONTROLLER_AXIS_MAX;i++)axes[i]=SDL_GameControllerGetAxis(controller,(SDL_GameControllerAxis)i);
}
static void activity(uint32_t buttons,const int16_t axes[SDL_CONTROLLER_AXIS_MAX]) {
    uint16_t next=a2_input_axis_latch(activity_latch,axes,threshold);
    uint32_t pressed=buttons&~activity_buttons;
    uint16_t moved=next&~activity_latch;
    int meaningful=map_pad(bindings,pressed,moved)!=0xffff;
    if(menu_active) {
        A2PadBinding fixed[16][2];a2_input_default_pad(fixed);
        meaningful|=map_pad(fixed,pressed,moved)!=0xffff;
    }
    if(meaningful)set_source(A2_INPUT_CONTROLLER);
    activity_buttons=buttons;activity_latch=next;
    memcpy(activity_axes,axes,sizeof activity_axes);
}
static void devices(void) {
    if(controller && !SDL_GameControllerGetAttached(controller)) {
        SDL_GameControllerClose(controller);controller=NULL;
        memset(&device,0,sizeof device);device.instance=-1;
        raw_buttons=activity_buttons=raw_latch=activity_latch=0;
        controller_pad=menu_pad=0xffff;menu_request=chord_latched=0;
        capture_active=capture_armed=0;set_source(A2_INPUT_KEYBOARD);changed();
    }
    if(controller)return;
    for(int i=0;i<SDL_NumJoysticks();i++) {
        if(!SDL_IsGameController(i))continue;
        controller=SDL_GameControllerOpen(i);if(!controller)continue;
        controller_type=get_type(controller);
        device.connected=1;device.family=family(controller_type);
        device.instance=SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(controller));
        SDL_JoystickGetGUIDString(SDL_JoystickGetGUID(SDL_GameControllerGetJoystick(controller)),device.guid,sizeof device.guid);
        const char *name=SDL_GameControllerName(controller);snprintf(device.name,sizeof device.name,"%s",name?name:"Gamepad");
        read_sample(&activity_buttons,activity_axes);
        activity_latch=a2_input_axis_latch(0,activity_axes,threshold);
        changed();break;
    }
}
void a2_input_init(void) {
    if(initialized)return;initialized=1;device.instance=-1;
    a2_input_default_pad(bindings);devices();
}
void a2_input_shutdown(void) {
    if(controller)SDL_GameControllerClose(controller);controller=NULL;initialized=0;
    memset(&device,0,sizeof device);device.instance=-1;
    raw_buttons=activity_buttons=raw_latch=activity_latch=0;
    keyboard_pad=controller_pad=menu_pad=0xffff;
    capture_active=capture_armed=menu_request=chord_latched=menu_active=0;set_source(A2_INPUT_KEYBOARD);changed();
}
void a2_input_configure(const int key[16],const A2PadBinding pad[16][2],int value) {
    int validkeys[16]={0};A2PadBinding validpad[16][2]={0};
    for(int bit=0;bit<16;bit++)if(a2_input_pad_bit_valid(bit)) {
        if(key[bit]>=0 && key[bit]<SDL_NUM_SCANCODES)validkeys[bit]=key[bit];
        for(int slot=0;slot<2;slot++)if(a2_input_binding_valid(pad[bit][slot]))validpad[bit][slot]=pad[bit][slot];
    }
    value=clamp_threshold(value);
    if(memcmp(keymap,validkeys,sizeof keymap)||memcmp(bindings,validpad,sizeof bindings)||threshold!=value) {
        memcpy(keymap,validkeys,sizeof keymap);memcpy(bindings,validpad,sizeof bindings);threshold=value;
        raw_latch=activity_latch=0;changed();
    }
}
void a2_input_handle_event(const SDL_Event *e) {
    if(!e)return;
    if(e->type==SDL_CONTROLLERDEVICEADDED || e->type==SDL_CONTROLLERDEVICEREMOVED) { devices();return; }
    if(e->type==SDL_CONTROLLERDEVICEREMAPPED) { if(controller) { controller_type=get_type(controller);device.family=family(controller_type);changed(); }return; }
    if(e->type==SDL_KEYMAPCHANGED) { changed();return; }
    if(e->type==SDL_KEYDOWN && !e->key.repeat && !a2_input_key_reserved(e->key.keysym.scancode)) {
        for(int i=0;i<16;i++)if(keymap[i]>0 && keymap[i]==e->key.keysym.scancode) { set_source(A2_INPUT_KEYBOARD);break; }
    } else if(device.connected && (e->type==SDL_CONTROLLERBUTTONDOWN || e->type==SDL_CONTROLLERBUTTONUP) && e->cbutton.which==device.instance && e->cbutton.button<SDL_CONTROLLER_BUTTON_MAX) {
        uint32_t buttons=activity_buttons,bit=1u<<e->cbutton.button;
        if(e->type==SDL_CONTROLLERBUTTONDOWN)buttons|=bit;else buttons&=~bit;
        activity(buttons,activity_axes);
    } else if(device.connected && e->type==SDL_CONTROLLERAXISMOTION && e->caxis.which==device.instance && e->caxis.axis<SDL_CONTROLLER_AXIS_MAX) {
        int16_t axes[SDL_CONTROLLER_AXIS_MAX];memcpy(axes,activity_axes,sizeof axes);axes[e->caxis.axis]=e->caxis.value;
        activity(activity_buttons,axes);
    }
}
void a2_input_poll(void) {
    if(!initialized)a2_input_init();
    SDL_GameControllerUpdate();devices();
    keyboard_pad=0xffff;int count=0;const Uint8 *keys=SDL_GetKeyboardState(&count);
    for(int bit=0;bit<16;bit++)if(keymap[bit]>0 && keymap[bit]<count && keys[keymap[bit]])keyboard_pad&=~(1u<<bit);
    read_sample(&raw_buttons,raw_axes);activity(raw_buttons,raw_axes);
    raw_latch=a2_input_axis_latch(raw_latch,raw_axes,threshold);
    const uint32_t chord=(1u<<SDL_CONTROLLER_BUTTON_BACK)|(1u<<SDL_CONTROLLER_BUTTON_START);
    if(!(raw_buttons&chord))chord_latched=0;
    if((raw_buttons&chord)==chord && !chord_latched && !capture_active) { if(!menu_active)menu_request=1;chord_latched=1; }
    uint32_t game_buttons=raw_buttons;if(chord_latched)game_buttons&=~chord;
    controller_pad=map_pad(bindings,game_buttons,raw_latch);
    A2PadBinding menu[16][2];a2_input_default_pad(menu);menu_pad=map_pad(menu,game_buttons,raw_latch);
}
uint16_t a2_input_pad_buttons(void) { return keyboard_pad&controller_pad; }
uint16_t a2_input_controller_buttons(void) { return controller_pad; }
uint16_t a2_input_menu_buttons(void) { return menu_pad; }
int a2_input_take_menu_request(void) { int result=menu_request;menu_request=0;return result; }
void a2_input_set_menu_active(int value) {
    if(!value && initialized)a2_input_sync_controller_events();
    menu_active=!!value;menu_request=0;
    if(!menu_active) {
        capture_active=capture_armed=0;
        if(raw_buttons&((1u<<SDL_CONTROLLER_BUTTON_BACK)|(1u<<SDL_CONTROLLER_BUTTON_START)))chord_latched=1;
    }
}
void a2_input_sync_controller_events(void) {
    SDL_GameControllerUpdate();SDL_Event event;
    while(SDL_PeepEvents(&event,1,SDL_GETEVENT,SDL_CONTROLLERAXISMOTION,SDL_CONTROLLERDEVICEREMAPPED)>0)
        a2_input_handle_event(&event);
    a2_input_poll();
}
void a2_input_note_menu_keyboard(void) {
    if(menu_active) { a2_input_sync_controller_events();set_source(A2_INPUT_KEYBOARD); }
}
const A2InputDevice *a2_input_device(void) { return &device; }
A2InputSource a2_input_source(void) { return source; }
uint32_t a2_input_prompt_generation(void) { return generation; }
void a2_input_capture_begin(void) { capture_active=1;capture_armed=0;menu_request=0; }
void a2_input_capture_cancel(void) { capture_active=capture_armed=0; }
int a2_input_capture_poll(A2PadBinding *out) {
    if(!capture_active || !out || !device.connected)return 0;
    if(!capture_armed) { if(!raw_buttons && !raw_latch)capture_armed=1;return 0; }
    for(int i=0;i<SDL_CONTROLLER_BUTTON_MAX;i++)if(i!=SDL_CONTROLLER_BUTTON_GUIDE && (raw_buttons&(1u<<i))) {
        *out=(A2PadBinding){A2_BIND_BUTTON,i};capture_active=0;return 1;
    }
    for(int i=0;i<SDL_CONTROLLER_AXIS_MAX*2;i++)if(raw_latch&(1u<<i)) {
        *out=(A2PadBinding){i&1?A2_BIND_AXIS_NEG:A2_BIND_AXIS_POS,i/2};capture_active=0;return 1;
    }
    return 0;
}
void a2_input_key_prompt(int sc,A2InputPrompt *out) {
    if(!out)return;memset(out,0,sizeof *out);out->source=A2_INPUT_KEYBOARD;
    const char *name=NULL;
    if(sc>0 && sc<SDL_NUM_SCANCODES) {
        SDL_Keycode key=SDL_GetKeyFromScancode((SDL_Scancode)sc);
        if(key!=SDLK_UNKNOWN)name=SDL_GetKeyName(key);
        if(!name || !*name)name=SDL_GetScancodeName((SDL_Scancode)sc);
    }
    out->glyph=name&&*name?A2_GLYPH_KEY:A2_GLYPH_NONE;
    snprintf(out->label,sizeof out->label,"%s",name&&*name?name:"—");
}
void a2_input_describe_binding(A2PadBinding b,SDL_GameControllerType type,int labels,A2InputPrompt *out) {
    if(!out)return;memset(out,0,sizeof *out);out->source=A2_INPUT_CONTROLLER;out->family=family(type);
    const char *name="—";out->glyph=A2_GLYPH_NONE;
    if(!a2_input_binding_valid(b) || !b.kind) { snprintf(out->label,sizeof out->label,"%s",name);return; }
    out->glyph=A2_GLYPH_TEXT;
    if(b.kind==A2_BIND_BUTTON) {
        static const char *face[]={"A","B","X","Y"};
        if(b.code<=SDL_CONTROLLER_BUTTON_Y) {
            if(out->family==A2_PAD_PLAYSTATION) {
                static const char *ps[]={"×","○","□","△"};name=ps[b.code];out->glyph=(A2InputGlyph)(A2_GLYPH_CROSS+b.code);
            } else if(out->family==A2_PAD_NINTENDO && !labels)name=face[b.code^1];
            else name=face[b.code];
        } else switch(b.code) {
        case SDL_CONTROLLER_BUTTON_BACK:name=out->family==A2_PAD_NINTENDO?"−":out->family==A2_PAD_XBOX?"View":type==SDL_CONTROLLER_TYPE_PS5?"Create":type==SDL_CONTROLLER_TYPE_PS4?"Share":"Select";break;
        case SDL_CONTROLLER_BUTTON_START:name=out->family==A2_PAD_NINTENDO?"+":out->family==A2_PAD_XBOX?"Menu":out->family==A2_PAD_PLAYSTATION && type!=SDL_CONTROLLER_TYPE_PS3?"Options":"Start";break;
        case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:name=out->family==A2_PAD_PLAYSTATION?"L1":out->family==A2_PAD_NINTENDO?"L":"LB";break;
        case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:name=out->family==A2_PAD_PLAYSTATION?"R1":out->family==A2_PAD_NINTENDO?"R":"RB";break;
        case SDL_CONTROLLER_BUTTON_LEFTSTICK:name=out->family==A2_PAD_PLAYSTATION?"L3":"LS";break;
        case SDL_CONTROLLER_BUTTON_RIGHTSTICK:name=out->family==A2_PAD_PLAYSTATION?"R3":"RS";break;
        case SDL_CONTROLLER_BUTTON_DPAD_UP:name="↑";out->glyph=A2_GLYPH_UP;break;
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:name="→";out->glyph=A2_GLYPH_RIGHT;break;
        case SDL_CONTROLLER_BUTTON_DPAD_DOWN:name="↓";out->glyph=A2_GLYPH_DOWN;break;
        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:name="←";out->glyph=A2_GLYPH_LEFT;break;
        default:name=SDL_GameControllerGetStringForButton((SDL_GameControllerButton)b.code);break;
        }
    } else if(b.code==SDL_CONTROLLER_AXIS_TRIGGERLEFT)name=out->family==A2_PAD_PLAYSTATION?"L2":out->family==A2_PAD_NINTENDO?"ZL":"LT";
    else if(b.code==SDL_CONTROLLER_AXIS_TRIGGERRIGHT)name=out->family==A2_PAD_PLAYSTATION?"R2":out->family==A2_PAD_NINTENDO?"ZR":"RT";
    else {
        const char *arrow=b.code%2?(b.kind==A2_BIND_AXIS_NEG?"↑":"↓"):(b.kind==A2_BIND_AXIS_NEG?"←":"→");
        snprintf(out->label,sizeof out->label,"%s %s",b.code<2?"LS":"RS",arrow);return;
    }
    snprintf(out->label,sizeof out->label,"%s",name&&*name?name:"Button");
}
void a2_input_binding_prompt(A2PadBinding b,A2InputPrompt *out) {
    a2_input_describe_binding(b,device.connected?controller_type:SDL_CONTROLLER_TYPE_UNKNOWN,
                             SDL_GetHintBoolean(SDL_HINT_GAMECONTROLLER_USE_BUTTON_LABELS,SDL_TRUE),out);
}
int a2_input_prompts_for_bit(int bit,A2InputPrompt out[2]) {
    if(!out || !a2_input_pad_bit_valid(bit))return 0;
    if(source==A2_INPUT_KEYBOARD || !device.connected) { a2_input_key_prompt(keymap[bit],out);return 1; }
    int count=0;
    for(int slot=0;slot<2;slot++)if(bindings[bit][slot].kind)a2_input_binding_prompt(bindings[bit][slot],out+count++);
    if(!count) { a2_input_binding_prompt((A2PadBinding){0,0},out);count=1; }
    return count;
}
void a2_input_menu_chord_prompt(char *out,size_t size) {
    if(!out || !size)return;
    A2InputPrompt a,b;a2_input_binding_prompt((A2PadBinding){A2_BIND_BUTTON,SDL_CONTROLLER_BUTTON_BACK},&a);
    a2_input_binding_prompt((A2PadBinding){A2_BIND_BUTTON,SDL_CONTROLLER_BUTTON_START},&b);
    snprintf(out,size,"%s + %s",a.label,b.label);
}
