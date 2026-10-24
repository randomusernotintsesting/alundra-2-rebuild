/* A slow CPU acknowledgement must not stop physical XA-sector time. */
#include <assert.h>
#include <stdio.h>
#include "../src/spu.c"
#include "../src/cdrom.c"
uint8_t PSX_RAM[PSX_RAM_SIZE];
int psx_in_irq, psx_critical;
uint32_t psx_frame_no;
void psx_irq_set(int bit) { assert(bit == 2); }
void psx_irq_dispatch(void) { /* CPU acknowledges explicitly on its next tick. */ }
void a2_ramwatch_blk(uint32_t dst, uint32_t len, const char *tag) {
    (void)dst; (void)len; (void)tag;
}
static void test_commands_with_full_data_queue(void) {
    reset_xa(); cur_lba=0; pend_n=0; mode=0xc8; reading=1; irq_fl=1;
    filter_file=filter_channel=1;
    memset(data, 0x5a, sizeof data); data_n=123; data_i=17;
    resp[0]=0xa5; resp_n=1; resp_i=0;
    for (int i=0; i<10; i++) cd_vblank();
    assert(cur_lba==25 && pend_n==8);
    int64_t oldest[8];
    for (int i=0; i<8; i++) { assert(pend[i].lba>=0); oldest[i]=pend[i].lba; }

    /* Polling and state-changing commands must complete even if an earlier
     * data IRQ is held. Successive commands also exercise eviction behind
     * existing command responses; GetID queues its INT3 before its INT2. */
    const uint8_t commands[]={0x11, 0x01, 0x0d, 0x0e, 0x1a};
    const int lengths[]={8, 1, 1, 1, 1, 8};
    int responses=0;
    for (unsigned c=0; c<sizeof commands; c++) {
        param[0]=commands[c]==0x0e ? 0xc8 : 1; param[1]=1; param_n=2;
        cd_command(commands[c]);
        responses+=commands[c]==0x1a ? 2 : 1;
        assert(pend_n==8);
        for (int i=0; i<8-responses; i++) assert(pend[i].lba==oldest[i]);
        for (int i=0; i<responses; i++) {
            int p=8-responses+i;
            assert(pend[p].lba<0 && pend[p].num==(i==5 ? 2 : 3));
            assert(pend[p].n==lengths[i]);
        }
        /* Enqueuing commands may not acknowledge or overwrite the active
         * response/data FIFO, nor advance the physical sector position. */
        assert(irq_fl==1 && resp[0]==0xa5 && resp_n==1 && resp_i==0);
        assert(data_n==123 && data_i==17 && cur_lba==25);
        for (unsigned i=0; i<sizeof data; i++) assert(data[i]==0x5a);
    }
    for (int i=0; i<8; i++) {
        irq_fl=0; assert(deliver_next());
        assert(irq_fl==(i<2 ? 1 : i==7 ? 2 : 3));
        if (i>=2) assert(resp_n==lengths[i-2]);
    }
    assert(!pend_n);
    cd_command(0x08);
}
int main(void) {
    img = tmpfile(); assert(img);
    uint8_t raw[2352] = {0}; raw[15] = 2;
    for (int i = 0; i < 160; i++) {
        memset(raw+16, 0, 2336);
        if (i % 8 == 1 || i % 8 == 2) {
            raw[16] = raw[20] = 1;
            raw[17] = raw[21] = i % 8;
            raw[18] = raw[22] = 0x64; raw[19] = raw[23] = 1;
            for (int g = 0; g < 18; g++) memset(raw+40+g*128, 0x21, 112);
        }
        assert(fwrite(raw, 1, sizeof raw, img) == sizeof raw);
    }
    fflush(img); img_sectors = 160;
    mode = 0xc8; reading = 1; irq_en = 0x1f;
    filter_file = filter_channel = 1;
    spu_write(0x1aa, 0xc001);
    spu_write(0x1b0, 0x7fff); spu_write(0x1b2, 0x7fff);
    uint8_t response = 0x42; push_int(3, &response, 1);
    for (int i = 0; i < 60; i++) {
        /* Also exercise a ten-frame CPU stall and bounded data overrun. */
        if (i && (i < 20 || i >= 30)) irq_fl = 0;
        psx_frame_no++; cd_vblank();
        if (!i) assert(irq_fl == 3 && resp[0] == 0x42);
        assert(pend_n >= 0 && pend_n <= 8);
        spu_vblank();
    }
    fprintf(stderr, "paced XA: advanced=%u fifo=%u\n", cur_lba, cd_count);
    assert(cur_lba == 150);
    /* Exactly19 selected2016-frame37.8kHz sectors, no rejected-channel PCM.
     * Physical slots1,9,17,25... arrive ticks1,4,8,11...; the resulting
     * frame-granular onset gives441 missing44100Hz samples,1029 retained. */
    assert(cd_count == 1029);
    cd_command(0x09);
    assert(!reading && !cd_count);
    for (int i = 0; i < pend_n; i++) assert(pend[i].lba < 0);
    uint32_t stopped = cur_lba;
    for (int i = 0; i < 10; i++) { irq_fl=0; cd_vblank(); }
    assert(cur_lba == stopped);
    /* The same physical clock contract applies at single speed. */
    irq_fl=0; pend_n=0; mode=0x48; target_lba=0; cd_command(0x06);
    for (int i = 0; i < 60; i++) { irq_fl=0; cd_vblank(); spu_vblank(); }
    assert(cur_lba == 75);
    cd_command(0x08);
    assert(!reading && !cd_count);
    for (int i = 0; i < pend_n; i++) assert(pend[i].lba < 0);
    test_commands_with_full_data_queue();
    fclose(img);
    puts("XA clock, saturated-queue command order, filtering, bounded data overrun and pause passed");
    return 0;
}
