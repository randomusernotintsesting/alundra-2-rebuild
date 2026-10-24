#ifndef A2_INPUT_H
#define A2_INPUT_H
#include <SDL.h>
#include <stdint.h>

enum { A2_BIND_NONE, A2_BIND_BUTTON, A2_BIND_AXIS_POS, A2_BIND_AXIS_NEG };
typedef struct { int kind, code; } A2PadBinding;
typedef enum { A2_INPUT_KEYBOARD, A2_INPUT_CONTROLLER } A2InputSource;
typedef enum { A2_PAD_GENERIC, A2_PAD_PLAYSTATION, A2_PAD_XBOX, A2_PAD_NINTENDO } A2PadFamily;
typedef enum {
    A2_GLYPH_NONE, A2_GLYPH_KEY, A2_GLYPH_TEXT,
    A2_GLYPH_CROSS, A2_GLYPH_CIRCLE, A2_GLYPH_SQUARE, A2_GLYPH_TRIANGLE,
    A2_GLYPH_UP, A2_GLYPH_RIGHT, A2_GLYPH_DOWN, A2_GLYPH_LEFT
} A2InputGlyph;
typedef struct {
    A2InputSource source;
    A2PadFamily family;
    A2InputGlyph glyph;
    char label[64];                 /* bounded UTF-8, always terminated */
} A2InputPrompt;
typedef struct {
    int connected;
    SDL_JoystickID instance;
    A2PadFamily family;
    char name[128], guid[33];
} A2InputDevice;

/* The host owns SDL initialization/event pumping. All calls are main-thread.
 * Poll once after the event pump, and from the native modal timer. Guest
 * reads below are snapshots: repeated pad-HLE polls cannot change activity. */
void a2_input_init(void);
void a2_input_shutdown(void);
void a2_input_configure(const int key[16], const A2PadBinding pad[16][2], int threshold);
void a2_input_handle_event(const SDL_Event *event);
void a2_input_poll(void);
uint16_t a2_input_pad_buttons(void);         /* active-low keyboard + configured pad */
uint16_t a2_input_controller_buttons(void);  /* active-low configured pad only */
uint16_t a2_input_menu_buttons(void);        /* fixed menu navigation, ignores remaps */
int a2_input_take_menu_request(void);        /* one-shot Back+Start; consumes chord */
void a2_input_set_menu_active(int active);   /* fixed-menu activity; clears queued chord */
void a2_input_note_menu_keyboard(void);      /* AppKit keydown, outside SDL's event loop */
void a2_input_sync_controller_events(void);  /* drain queued controller events, then snapshot */
const A2InputDevice *a2_input_device(void);   /* borrowed copied metadata, no SDL handle */
A2InputSource a2_input_source(void);
uint32_t a2_input_prompt_generation(void);

/* Renderers consume descriptors; this module never draws or accesses guest RAM.
 * Keyboard yields one descriptor, controller up to two. Unbound yields one
 * A2_GLYPH_NONE descriptor. A caller can combine these with a guest action's
 * current PS bit without assuming the original KeyConfig defaults. */
int a2_input_prompts_for_bit(int bit, A2InputPrompt out[2]);
void a2_input_key_prompt(int scancode, A2InputPrompt *out);
void a2_input_binding_prompt(A2PadBinding binding, A2InputPrompt *out);
void a2_input_menu_chord_prompt(char *out, size_t size);

/* A capture is raw controller input, independent of current assignments.
 * It arms after neutral, reports one new button/axis direction and stops.
 * Modal keyboard cancellation/clear are handled by the native controls UI. */
void a2_input_capture_begin(void);
int a2_input_capture_poll(A2PadBinding *out);
void a2_input_capture_cancel(void);

/* Pure configuration helpers, also used by settings migration and fixtures. */
void a2_input_default_pad(A2PadBinding out[16][2]);
int a2_input_binding_valid(A2PadBinding binding);
int a2_input_pad_bit_valid(int bit);
int a2_input_key_reserved(int scancode);
int a2_input_bind_pad(A2PadBinding pad[16][2], int bit, int slot, A2PadBinding binding);
/* Pure axis Schmitt trigger: bit 2*a is positive, bit 2*a+1 negative. */
uint16_t a2_input_axis_latch(uint16_t previous, const int16_t axes[SDL_CONTROLLER_AXIS_MAX], int threshold);
void a2_input_describe_binding(A2PadBinding binding, SDL_GameControllerType type,
                               int button_labels, A2InputPrompt *out);

#endif
