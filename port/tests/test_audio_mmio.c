#include <assert.h>
#include <stdio.h>
#include "../src/spu.c"
#include "../src/mmio.c"
uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t R[32], HI, LO, gpu_ll_node, a2_ramwatch;
void gpu_gp0(uint32_t w) { (void)w; }
void gpu_gp1(uint32_t w) { (void)w; }
uint32_t gpu_stat(void) { return 0; }
uint32_t gpu_read(void) { return 0; }
uint8_t cd_read_reg(int r) { (void)r; return 0; }
void cd_write_reg(int r, uint8_t v) { (void)r; (void)v; }
void cd_dma_read(uint32_t a, uint32_t n) { (void)a; (void)n; }
void cd_dump_state(void) {}
void psx_irq_dispatch(void) {}
void psx_vblank_tick(void) {}
uint16_t psx_pad_buttons(void) { return 0xffff; }
void a2_ramwatch_hit(uint32_t a,uint32_t v,int n) { (void)a; (void)v; (void)n; }
int main(void) {
    psx_mmio_write(0x1f801daa, 0xc000, 2);
    /* Software may write ENDX, but hardware status must still read zero. */
    psx_mmio_write(0x1f801d9c, 0xffffffff, 4);
    assert(psx_mmio_read(0x1f801d9c, 4) == 0);
    /* ADSR readback follows live envelope, including a zero high halfword. */
    psx_mmio_write(0x1f801c0c, 0x1234, 2);
    psx_mmio_write(0x1f801d88, 1, 2);
    assert(psx_mmio_read(0x1f801c0c, 2) == 0);
    assert(psx_mmio_read(0x1f801c0a, 4) == 0);
    /* Unmodeled reverb registers retain ordinary write/readback. */
    psx_mmio_write(0x1f801dc0, 0x87651234, 4);
    assert(psx_mmio_read(0x1f801dc0, 4) == 0x87651234);
    /* RAM source crosses its physical mirror boundary during SPU DMA. */
    for (int i = 0; i < 4; i++) { PSX_RAM[0x1ffffc+i] = (uint8_t)(10+i); PSX_RAM[i] = (uint8_t)(20+i); }
    psx_mmio_write(0x1f801da6, 0, 2);
    psx_mmio_write(0x1f8010c0, 0x1ffffc, 4);
    psx_mmio_write(0x1f8010c4, 0x10002, 4);
    psx_mmio_write(0x1f8010c8, 0x01000201, 4);
    assert(SPU_RAM[0] == 10 && SPU_RAM[3] == 13 && SPU_RAM[4] == 20 && SPU_RAM[7] == 23);
    psx_mmio_write(0x1f801da6, 0, 2);
    psx_mmio_write(0x1f8010c0, 0, 4);
    psx_mmio_write(0x1f8010c8, 0x01000203, 4);
    assert(SPU_RAM[0] == 20 && SPU_RAM[4] == 10); /* decrement wraps */
    PSX_RAM[0x180000] = 77;
    psx_mmio_write(0x1f801da6, 0, 2);
    psx_mmio_write(0x1f8010c4, 0xffffffff, 4);
    psx_mmio_write(0x1f8010c8, 0x01000201, 4);
    assert(SPU_RAM[0] == 77 && xfer_addr == 4); /* maximum BCR bounded work */
    puts("SPU MMIO dynamic readback and DMA wrapping passed");
}
