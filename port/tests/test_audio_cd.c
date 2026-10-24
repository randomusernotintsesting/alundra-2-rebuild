#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../src/spu.c"
#include "../src/cdrom.c"
uint8_t PSX_RAM[PSX_RAM_SIZE];
int psx_in_irq, psx_critical;
uint32_t psx_frame_no;
void psx_irq_set(int bit) { (void)bit; }
void psx_irq_dispatch(void) { irq_fl = 0; }
void a2_ramwatch_blk(uint32_t dst, uint32_t len, const char *tag) {
    (void)dst; (void)len; (void)tag;
}
int main(void) {
    img = tmpfile(); assert(img);
    uint8_t raw[2352] = {0};
    raw[15] = 2; raw[16] = raw[20] = 1;
    raw[18] = raw[22] = 0x64; raw[19] = raw[23] = 1;
    for (int g = 0; g < 18; g++) {
        memset(raw + 24 + 128*g, 0, 16);
        memset(raw + 40 + 128*g, 0x21, 112);
    }
    /* One selected XA sector every eight sectors at double speed. */
    for (int i = 0; i < 160; i++) {
        raw[17] = raw[21] = i % 8 == 0 ? 0 : 1;
        assert(fwrite(raw, 1, 2352, img) == 2352);
    }
    fflush(img); img_sectors = 160;
    mode = 0xc8; reading = 1; irq_en = 0x1f;
    param[0] = 1; param[1] = 0; cd_command(0x0d);
    spu_write(0x1aa, 0xc001);
    spu_write(0x1b0, 0x7fff); spu_write(0x1b2, 0x7fff);
    for (int i = 0; i < 60; i++) { cd_vblank(); spu_vblank(); }
    assert(cur_lba == 150);
    assert(cd_count < 2352 * 2); /* bounded lead, no seconds of backlog */
    assert(cd_count > 0);
    /* Stop flushes already decoded audio as well as data interrupts. */
    cd_command(0x09);
    assert(cd_count == 0);
    fclose(img);
    puts("CD XA filtering and pacing passed");
}
