/* Exact GAME00/EVENT00 scene-return boundaries, after psx_rt memory helpers.
 * No guest register, RAM, MMIO write or scheduler work is performed here. */
#ifndef A2_SCENE_SUBMIT_H
#define A2_SCENE_SUBMIT_H
void gpu_scene_submit_complete(void);
static inline void psx_scene_submit_complete(void) {
    /* Retained original GAME00 86A00..86A30: both DrawOTag calls and the
     * continuation instruction. Do not accept an overlaid/modified caller. */
    static const uint32_t prefix[] = {
        0x27bdffe0u,0xafb00010u,0x3c108011u,0x261033d0u,0xafbf0018u,
        0xafb10014u,0x8e114140u,0x0c00cbbau,0x2624209cu,0x8e044148u,
        0x0c00cbbau,0x24840020u,0x3c020001u
    };
    /* EVENT00 has two separate single-OT display paths. Each prefix includes
     * its PutDispEnv, PutDrawEnv, DrawOTag and continuation load; notification
     * precedes the native buffer swap and ClearOTag of the next frame. */
    static const uint32_t event_prefix[] = {
        0x27bdffe0u,0xafb10014u,0x3c11800bu,0x3c04800fu,0x8e237754u,
        0x2484e788u,0xafbf0018u,0xafb00010u,0x00031080u,0x00431021u,
        0x00021080u,0x0c00cc49u,0x00442021u,0x8e227754u,0x00000000u,
        0x00022040u,0x00822021u,0x000420c0u,0x00822023u,0x00042080u,
        0x3c02800fu,0x2442e6d0u,0x0c00cbd6u,0x00822021u,0x3c10800bu,
        0x8e227754u,0x26107668u,0x00022100u,0x00822021u,0x00042080u,
        0x0c00cbbau,0x00902021u,0x8e227754u
    };
    static const uint32_t event_alt_prefix[] = {
        0x27bdffe0u,0xafbf0018u,0xafb10014u,0x14800006u,0xafb00010u,
        0x3c02800fu,0x2442ffc8u,0xa0400018u,0x080266f5u,0xa0400074u,
        0x3c02800fu,0x2442ffc8u,0x24030001u,0xa0430018u,0xa0430074u,
        0x3c10800fu,0x3c04800fu,0x9203f700u,0x24840080u,0x00031080u,
        0x00431021u,0x00021080u,0x0c00cc49u,0x00442021u,0x9202f700u,
        0x00000000u,0x00022040u,0x00822021u,0x000420c0u,0x00822023u,
        0x00042080u,0x3c02800fu,0x2442ffc8u,0x0c00cbd6u,0x00822021u,
        0x3c11800bu,0x9203f700u,0x8e243308u,0x000310c0u,0x00431023u,
        0x00021080u,0x00431023u,0x00021080u,0x00431023u,0x00021140u,
        0x00431021u,0x000210c0u,0x00822021u,0x0c00cbbau,0x24846a04u,
        0x9202f700u
    };
    if (R[2] != 0) return;
    uint32_t module = lw_(0x800811d8u);
    if (module == 4 && R[31] == 0x80086a30u) {
        if (memcmp(PSX_RAM + 0x86a00, prefix, sizeof prefix)) return;
    } else if (module == 5 && R[31] == 0x80093648u) {
        if (memcmp(PSX_RAM + 0x935c8, event_prefix, sizeof event_prefix)) return;
    } else if (module == 5 && R[31] == 0x80099c60u) {
        if (memcmp(PSX_RAM + 0x99b98, event_alt_prefix, sizeof event_alt_prefix)) return;
    } else return;
    /* DrawOTag can enqueue. Recognize the original SDK queue/callback table,
     * then require its queue empty and DMA2 idle. dma_run(2) consumes every
     * GP0 word synchronously before clearing CHCR. A pending/foreign route
     * keeps the ordinary later GPU finalization fallback. */
    if (lw_(0x800553dcu) != 0x8005539cu ||
        lw_(0x800553a4u) != 0x8003468cu ||
        lw_(0x800553b4u) != 0x800345f0u ||
        lw_(0x800554f8u) != 0x1f8010a8u ||
        lw_(0x8005550cu) != lw_(0x80055510u)) return;
    if (lw_(0x1f8010a8u) & 0x01000000u) return;
    gpu_scene_submit_complete();
}
#endif
