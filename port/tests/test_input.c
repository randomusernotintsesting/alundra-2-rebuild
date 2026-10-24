#include "input.h"
#include "input_virtual_type_fixture.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

static A2PadBinding pad[16][2];
static int keys[16];
static void pure_configuration(void) {
    a2_input_default_pad(pad);
    assert(pad[14][0].kind==A2_BIND_BUTTON && pad[14][0].code==SDL_CONTROLLER_BUTTON_A);
    assert(pad[4][0].code==SDL_CONTROLLER_BUTTON_DPAD_UP);
    assert(pad[4][1].kind==A2_BIND_AXIS_NEG && pad[4][1].code==SDL_CONTROLLER_AXIS_LEFTY);
    assert(a2_input_key_reserved(SDL_SCANCODE_F5));
    assert(a2_input_key_reserved(SDL_SCANCODE_F9));
    assert(!a2_input_key_reserved(SDL_SCANCODE_Z));
    A2PadBinding invalid={A2_BIND_BUTTON,SDL_CONTROLLER_BUTTON_MAX};
    assert(!a2_input_binding_valid(invalid));
    assert(!a2_input_binding_valid((A2PadBinding){A2_BIND_AXIS_NEG,SDL_CONTROLLER_AXIS_TRIGGERLEFT}));
    assert(!a2_input_bind_pad(pad,2,0,pad[14][0]));
    assert(!a2_input_bind_pad(pad,14,0,invalid));
    A2PadBinding b=pad[14][0];
    assert(a2_input_bind_pad(pad,13,1,b));
    assert(pad[14][0].kind==A2_BIND_NONE);
    assert(pad[13][1].kind==A2_BIND_BUTTON && pad[13][1].code==b.code);
    assert(a2_input_bind_pad(pad,13,1,(A2PadBinding){0,0}));
    assert(!pad[13][1].kind);
    int16_t axes[SDL_CONTROLLER_AXIS_MAX]={0};
    axes[0]=16000;assert(!a2_input_axis_latch(0,axes,16000));
    axes[0]=16001;uint16_t latch=a2_input_axis_latch(0,axes,16000);assert(latch==1);
    axes[0]=15000;assert(a2_input_axis_latch(latch,axes,16000)==1);
    axes[0]=13952;assert(!a2_input_axis_latch(latch,axes,16000));
    axes[0]=-32768;assert(a2_input_axis_latch(0,axes,16000)==2);
    A2InputPrompt p;
    a2_input_describe_binding(b,SDL_CONTROLLER_TYPE_PS5,1,&p);
    assert(p.glyph==A2_GLYPH_CROSS && p.family==A2_PAD_PLAYSTATION);
    a2_input_describe_binding(b,SDL_CONTROLLER_TYPE_NINTENDO_SWITCH_PRO,1,&p);
    assert(!strcmp(p.label,"A"));
    a2_input_describe_binding(b,SDL_CONTROLLER_TYPE_NINTENDO_SWITCH_PRO,0,&p);
    assert(!strcmp(p.label,"B"));
}
static void pump(void) {
    SDL_Event e;while(SDL_PollEvent(&e))a2_input_handle_event(&e);
    a2_input_poll();
}
static void key(SDL_Scancode sc,int repeat) {
    SDL_Event e={0};e.type=SDL_KEYDOWN;e.key.keysym.scancode=sc;e.key.repeat=repeat;
    a2_input_handle_event(&e);
}
static void button(SDL_Joystick *j,int b,int down) {
    assert(!SDL_JoystickSetVirtualButton(j,b,down));pump();
}
static void virtual_controller(void) {
    /* Disable physical macOS drivers: this proves software event/device paths,
     * not detection or operation of any attached physical controller. */
    SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI,"0");
    SDL_SetHint(SDL_HINT_JOYSTICK_IOKIT,"0");
    SDL_SetHint(SDL_HINT_JOYSTICK_MFI,"0");
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS,"1");
    assert(!SDL_Init(SDL_INIT_VIDEO|SDL_INIT_GAMECONTROLLER));
    a2_input_init();a2_input_default_pad(pad);keys[14]=SDL_SCANCODE_Z;
    a2_input_configure(keys,pad,16000);pump();
    assert(!a2_input_device()->connected && a2_input_pad_buttons()==0xffff);
    SDL_VirtualJoystickDesc d={0};d.version=SDL_VIRTUAL_JOYSTICK_DESC_VERSION;
    d.type=SDL_JOYSTICK_TYPE_GAMECONTROLLER;d.naxes=SDL_CONTROLLER_AXIS_MAX;
    d.nbuttons=SDL_CONTROLLER_BUTTON_MAX;d.name="Owned Alundra Input Fixture";
    d.vendor_id=0x1209;d.product_id=0xa202;
    d.button_mask=(1u<<SDL_CONTROLLER_BUTTON_MAX)-1;
    d.axis_mask=(1u<<SDL_CONTROLLER_AXIS_MAX)-1;
    int index=SDL_JoystickAttachVirtualEx(&d);assert(index>=0);
    SDL_Joystick *j=SDL_JoystickOpen(index);assert(j);
    assert(!SDL_JoystickSetVirtualAxis(j,SDL_CONTROLLER_AXIS_TRIGGERLEFT,-32768));
    assert(!SDL_JoystickSetVirtualAxis(j,SDL_CONTROLLER_AXIS_TRIGGERRIGHT,-32768));
    pump();assert(a2_input_device()->connected);
    assert(strstr(a2_input_device()->name,"Owned Alundra"));
    assert(a2_input_source()==A2_INPUT_KEYBOARD); /* connection alone never steals hints */
    uint32_t gen=a2_input_prompt_generation();
    assert(!SDL_JoystickSetVirtualAxis(j,SDL_CONTROLLER_AXIS_LEFTX,1000));pump();
    assert(a2_input_source()==A2_INPUT_KEYBOARD && a2_input_prompt_generation()==gen);
    button(j,SDL_CONTROLLER_BUTTON_A,1);
    assert(a2_input_source()==A2_INPUT_CONTROLLER);
    assert(!(a2_input_pad_buttons()&(1u<<14)));
    gen=a2_input_prompt_generation();for(int i=0;i<5;i++)assert(!(a2_input_pad_buttons()&(1u<<14)));
    assert(a2_input_prompt_generation()==gen); /* HLE reads are idempotent */
    key(SDL_SCANCODE_E,0);assert(a2_input_source()==A2_INPUT_CONTROLLER);
    key(SDL_SCANCODE_Z,1);assert(a2_input_source()==A2_INPUT_CONTROLLER);
    key(SDL_SCANCODE_Z,0);assert(a2_input_source()==A2_INPUT_KEYBOARD);
    button(j,SDL_CONTROLLER_BUTTON_A,0);
    assert(a2_input_bind_pad(pad,13,1,pad[14][0]));
    a2_input_configure(keys,pad,16000);
    button(j,SDL_CONTROLLER_BUTTON_A,1);
    assert(!(a2_input_controller_buttons()&(1u<<13)));
    assert(a2_input_controller_buttons()&(1u<<14));
    assert(!(a2_input_menu_buttons()&(1u<<14))); /* fixed navigation survives reassignment */
    A2InputPrompt prompts[2];assert(a2_input_prompts_for_bit(13,prompts)==2);
    a2_input_capture_begin();A2PadBinding captured;
    assert(!a2_input_capture_poll(&captured)); /* opening press must release */
    button(j,SDL_CONTROLLER_BUTTON_A,0);assert(!a2_input_capture_poll(&captured));
    button(j,SDL_CONTROLLER_BUTTON_X,1);assert(a2_input_capture_poll(&captured));
    assert(captured.kind==A2_BIND_BUTTON && captured.code==SDL_CONTROLLER_BUTTON_X);
    button(j,SDL_CONTROLLER_BUTTON_X,0);
    button(j,SDL_CONTROLLER_BUTTON_BACK,1);assert(!a2_input_take_menu_request());
    button(j,SDL_CONTROLLER_BUTTON_START,1);assert(a2_input_take_menu_request());
    assert(!a2_input_take_menu_request());
    assert((a2_input_controller_buttons()&((1u<<0)|(1u<<3)))==((1u<<0)|(1u<<3)));
    pump();assert(!a2_input_take_menu_request());
    button(j,SDL_CONTROLLER_BUTTON_START,0);button(j,SDL_CONTROLLER_BUTTON_START,1);
    assert(!a2_input_take_menu_request()); /* both buttons must release */
    button(j,SDL_CONTROLLER_BUTTON_START,0);button(j,SDL_CONTROLLER_BUTTON_BACK,0);
    button(j,SDL_CONTROLLER_BUTTON_START,1);button(j,SDL_CONTROLLER_BUTTON_BACK,1);
    assert(a2_input_take_menu_request());
    button(j,SDL_CONTROLLER_BUTTON_START,0);button(j,SDL_CONTROLLER_BUTTON_BACK,0);
    memset(pad,0,sizeof pad);a2_input_configure(keys,pad,16000);
    a2_input_set_menu_active(1);key(SDL_SCANCODE_Z,0);
    button(j,SDL_CONTROLLER_BUTTON_DPAD_DOWN,1);
    assert(a2_input_source()==A2_INPUT_CONTROLLER); /* fixed navigation even with no game bindings */
    a2_input_note_menu_keyboard();assert(a2_input_source()==A2_INPUT_KEYBOARD);
    button(j,SDL_CONTROLLER_BUTTON_DPAD_DOWN,0);
    assert(!SDL_JoystickSetVirtualButton(j,SDL_CONTROLLER_BUTTON_DPAD_UP,1));
    SDL_GameControllerUpdate(); /* an older real SDL device event remains queued */
    a2_input_note_menu_keyboard();pump();
    assert(a2_input_source()==A2_INPUT_KEYBOARD); /* later AppKit key wins over old queued controller event */
    button(j,SDL_CONTROLLER_BUTTON_DPAD_UP,0);
    button(j,SDL_CONTROLLER_BUTTON_BACK,1);button(j,SDL_CONTROLLER_BUTTON_START,1);
    assert(!a2_input_take_menu_request());
    a2_input_set_menu_active(0);pump();assert(!a2_input_take_menu_request());
    button(j,SDL_CONTROLLER_BUTTON_START,0);button(j,SDL_CONTROLLER_BUTTON_BACK,0);
    SDL_JoystickClose(j);assert(!SDL_JoystickDetachVirtual(index));pump();
    assert(!a2_input_device()->connected);
    assert(a2_input_source()==A2_INPUT_KEYBOARD && a2_input_controller_buttons()==0xffff);
    a2_input_shutdown();SDL_Quit();
}
static void typed_controllers(void) {
#ifdef A2_INPUT_TEST_VIRTUAL_TYPES
    const struct { Uint16 vendor,product;const char *name;SDL_GameControllerType type;A2PadFamily family;const char *label; } cases[]={
        {0x054c,0x0ce6,"Owned DualSense fixture",SDL_CONTROLLER_TYPE_PS5,A2_PAD_PLAYSTATION,"×"},
        {0x045e,0x028e,"Owned Xbox 360 fixture",SDL_CONTROLLER_TYPE_XBOX360,A2_PAD_XBOX,"A"},
        {0x045e,0x02ea,"Owned Xbox One fixture",SDL_CONTROLLER_TYPE_XBOXONE,A2_PAD_XBOX,"A"}
    };
    assert(!SDL_Init(SDL_INIT_VIDEO|SDL_INIT_GAMECONTROLLER));
    a2_input_init();a2_input_default_pad(pad);a2_input_configure(keys,pad,16000);
    for(unsigned c=0;c<sizeof cases/sizeof cases[0];c++) {
        SDL_VirtualJoystickDesc d={0};d.version=SDL_VIRTUAL_JOYSTICK_DESC_VERSION;
        d.type=SDL_JOYSTICK_TYPE_GAMECONTROLLER;d.naxes=SDL_CONTROLLER_AXIS_MAX;d.nbuttons=SDL_CONTROLLER_BUTTON_MAX;
        d.vendor_id=cases[c].vendor;d.product_id=cases[c].product;d.name=cases[c].name;
        d.axis_mask=(1u<<SDL_CONTROLLER_AXIS_MAX)-1;d.button_mask=(1u<<SDL_CONTROLLER_BUTTON_MAX)-1;
        int index=SDL_JoystickAttachVirtualEx(&d);assert(index>=0);
        SDL_Joystick *j=SDL_JoystickOpen(index);assert(j);
        SDL_JoystickSetVirtualAxis(j,SDL_CONTROLLER_AXIS_TRIGGERLEFT,-32768);
        SDL_JoystickSetVirtualAxis(j,SDL_CONTROLLER_AXIS_TRIGGERRIGHT,-32768);
        SDL_GameController *opened=SDL_GameControllerOpen(index);assert(opened);
        SDL_GameControllerType detected=SDL_GameControllerGetType(opened);
        printf("typed virtual %s: actual SDL type=%d; injected hardware metadata=%d\n",cases[c].name,detected,cases[c].type);
        assert(detected==SDL_CONTROLLER_TYPE_VIRTUAL);
        assert(a2_input_test_controller_type(opened)==cases[c].type);
        pump();assert(a2_input_device()->family==cases[c].family);
        assert(a2_input_source()==A2_INPUT_KEYBOARD);
        button(j,SDL_CONTROLLER_BUTTON_A,1);
        A2InputPrompt p[2];assert(a2_input_prompts_for_bit(14,p)==1);
        assert(p[0].family==cases[c].family && !strcmp(p[0].label,cases[c].label));
        assert(p[0].glyph==(c?A2_GLYPH_TEXT:A2_GLYPH_CROSS));
        key(SDL_SCANCODE_Z,0);assert(a2_input_prompts_for_bit(14,p)==1 && p[0].glyph==A2_GLYPH_KEY);
        SDL_GameControllerClose(opened);SDL_JoystickClose(j);assert(!SDL_JoystickDetachVirtual(index));pump();
        assert(!a2_input_device()->connected && a2_input_source()==A2_INPUT_KEYBOARD);
    }
    a2_input_shutdown();SDL_Quit();
#endif
}
int main(void) {
    pure_configuration();virtual_controller();typed_controllers();
    puts("input: pure binding/axis/label contracts and isolated SDL virtual hotplug/source/capture/menu tests passed");
    return 0;
}
