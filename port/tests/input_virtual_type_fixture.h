#ifndef A2_INPUT_VIRTUAL_TYPE_FIXTURE_H
#define A2_INPUT_VIRTUAL_TYPE_FIXTURE_H
#include <SDL.h>
#include <assert.h>
#ifdef A2_INPUT_TEST_VIRTUAL_TYPES
/* Injected hardware metadata, real SDL virtual transport/events. This cannot
 * establish that a physical DualSense or Xbox controller was connected. */
SDL_GameControllerType a2_input_test_controller_type(SDL_GameController *pad) {
    SDL_GameControllerType actual=SDL_GameControllerGetType(pad);
    assert(actual==SDL_CONTROLLER_TYPE_VIRTUAL);
    Uint16 vendor=SDL_GameControllerGetVendor(pad),product=SDL_GameControllerGetProduct(pad);
    if(vendor==0x054c && product==0x0ce6)return SDL_CONTROLLER_TYPE_PS5;
    if(vendor==0x045e && product==0x028e)return SDL_CONTROLLER_TYPE_XBOX360;
    if(vendor==0x045e && product==0x02ea)return SDL_CONTROLLER_TYPE_XBOXONE;
    return actual;
}
#endif
#endif
