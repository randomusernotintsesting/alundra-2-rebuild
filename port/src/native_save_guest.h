#ifndef A2_NATIVE_SAVE_GUEST_H
#define A2_NATIVE_SAVE_GUEST_H
#include <stddef.h>
#include <stdint.h>
#define A2_CHECKPOINT_SIZE 0xC8Cu
#define A2_CHECKPOINT_PAYLOAD_SIZE 8192u
/* Pure staging; does not mutate RAM. Caller already ran original snapshot. */
int a2_checkpoint_prepare(const uint8_t *ram, uint8_t *payload, char *error, size_t size);
/* Validate completely, then copy persistent data and its backup. */
int a2_checkpoint_apply(uint8_t *ram, const uint8_t *payload, char *error, size_t size);
int a2_native_save_enabled(void);
/* Host-owned, validated selection. Consumed once by the original title load. */
int a2_native_stage_startup_load(const uint8_t *payload,char *error,size_t size);
int a2_native_startup_load_pending(void);
/* From accepted host selection through the first playable scene boundary. */
int a2_native_startup_load_active(void);
int a2_native_quick_save_available(void);
int a2_native_quick_load_available(void);
/* Queue only. The original GAME00 menu boundary consumes the operation. */
int a2_native_request_quick_action(int saving);
/* Same guest boundary and eligibility; open the manual slot browser. */
int a2_native_request_save_action(int saving);
/* Routing only. A manual operation still blocks requests while it is active. */
int a2_native_quick_action_active(void);
/* Observes the menu boundary; handles the full save entry when dispatched. */
int a2_native_save_handle(uint32_t address);
/* Platform dialog: 1 success, 0 cancel/error. Payload is staged for saving. */
int platform_native_save_dialog(int saving, uint8_t *payload, char *error, size_t size);
void platform_native_save_error(const char *message);
#endif
