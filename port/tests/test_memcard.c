/* BIOS-level tests; platform/CPU dependencies are inert, card/filesystem are real. */
#include "psx_rt.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/file.h>
int memcard_init(const char *directory);
void memcard_shutdown(void);

uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t R[32], HI, LO, a2_ramwatch, psx_frame_no;
int psx_critical, psx_call_depth;
static unsigned callback_count;
void psx_call(uint32_t a) {
    assert(a==0x80012340); callback_count++;
    R[4]=0xdeadbeef; R[16]=0xbad; HI=77; LO=88;
}
void psx_vblank_tick(void) {}
void gpu_gp0(uint32_t w) { (void)w; }
uint16_t psx_pad_buttons(void) { return 0xffff; }
uint32_t psx_irq_active(void) { return 0; }
uint32_t psx_mmio_read(uint32_t p, int s) { (void)p; (void)s; return 0; }
void psx_mmio_write(uint32_t p, uint32_t v, int s) { (void)p; (void)v; (void)s; }
void a2_ramwatch_hit(uint32_t p, uint32_t v, int s) { (void)p; (void)v; (void)s; }
void kernel_syscall(uint32_t table, uint32_t num);
static uint32_t bios(uint32_t t, uint32_t n, uint32_t a, uint32_t b, uint32_t c) {
    R[4]=a; R[5]=b; R[6]=c; R[7]=0; kernel_syscall(t,n); return R[2];
}
int main(void) {
    char dir[]="/tmp/alundra-memcard-test-XXXXXX";
    assert(mkdtemp(dir)); assert(setenv("A2_USER_DIR",dir,1)==0);
    bios(0xb0,0x4a,1,0,0); bios(0xb0,0x4b,0,0,0); bios(0xa0,0x70,0,0,0);
    /* SCPS firstfile (8003C568) searches the BIOS DCB table before B42.
     * Without this contract, even a nonempty card appears empty to the game. */
    uint32_t card_device=0;
    for(uint32_t off=0;off+0x50<=lw_(0x154);off+=0x50) {
        uint32_t entry=lw_(0x150)+off, name=lw_(entry);
        if(name && !strcmp((char *)PSX_RAM+(name&0x1fffff),"bu")) card_device=entry;
    }
    assert(card_device!=0);
    assert(lw_(card_device+4)==0x14 && lw_(card_device+8)==128);
    strcpy((char *)PSX_RAM+0x1000,"bu00:BISCPS-1010200");
    uint32_t fd=bios(0xb0,0x32,0x1000,0x10202,0);
    assert(fd>=2 && fd<16); /* Fails with the original FileOpen stub. */
    memset(PSX_RAM+0x2000,0x5a,8192);
    assert(bios(0xb0,0x35,fd,0x2000,8192)==8192);
    assert(bios(0xb0,0x36,fd,0,0)==fd);
    memcard_shutdown(); assert(memcard_init(dir)==1);
    bios(0xb0,0x4b,0,0,0);
    fd=bios(0xb0,0x32,0x1000,1,0); assert(fd>=2 && fd<16);
    memset(PSX_RAM+0x5000,0,8192);
    assert(bios(0xb0,0x34,fd,0x5000,8192)==8192);
    assert(memcmp(PSX_RAM+0x2000,PSX_RAM+0x5000,8192)==0);
    assert(bios(0xb0,0x34,fd,0x5000,128)==0xffffffff);
    assert(bios(0xb0,0x33,fd,1,0)==1);
    assert(bios(0xb0,0x34,fd,0x5000,128)==0xffffffff);
    assert(bios(0xb0,0x33,fd,0,0)==0);
    assert(bios(0xb0,0x34,fd,0x5000,129)==0xffffffff);
    assert(bios(0xb0,0x36,fd,0,0)==fd);
    assert(bios(0xb0,0x36,fd,0,0)==0xffffffff);
    strcpy((char *)PSX_RAM+0x1100,"bu00:BI*");
    assert(bios(0xb0,0x42,0x1100,0x7000,0)==0x7000);
    assert(!strcmp((char *)PSX_RAM+0x7000,"BISCPS-1010200"));
    assert(lw_(0x7014)==0x50 && lw_(0x7018)==8192);
    assert(bios(0xb0,0x43,0x7000,0,0)==0);
    uint32_t done=bios(0xb0,8,0xf0000011,4,0x2000);
    uint32_t changed=bios(0xb0,8,0xf0000011,0x2000,0x2000);
    bios(0xb0,12,done,0,0); bios(0xb0,12,changed,0,0);
    assert(bios(0xa0,0xab,0,0,0)==1);
    assert(bios(0xb0,11,changed,0,0)==1);
    bios(0xb0,0x50,0,0,0);
    assert(bios(0xb0,0x4e,0,63,0)==1); /* Actual game acknowledgement writes RAM 0. */
    assert(bios(0xb0,11,done,0,0)==1);
    assert(bios(0xb0,0x4f,0,64,0x7000)==1);
    assert(PSX_RAM[0x7000]==0x5a);
    assert(bios(0xb0,11,done,0,0)==1);
    assert(bios(0xb0,0x4f,0,1024,0x7000)==0);
    assert(bios(0xb0,0x4f,0,0,0x1f801000)==0);
    uint32_t swdone=bios(0xb0,8,0xf4000001,4,0x2000);
    bios(0xb0,12,swdone,0,0);
    /* MemCardGetDirentry calls _get_card_event_x after an empty firstfile:
     * SCPS 8003BA78 must receive completion, not spin forever. */
    strcpy((char *)PSX_RAM+0x1100,"bu00:MISSING*");
    assert(bios(0xb0,0x42,0x1100,0x7000,0)==0);
    assert(bios(0xb0,11,swdone,0,0)==1);
    assert(bios(0xa0,0xac,0,0,0)==1);
    assert(bios(0xb0,11,swdone,0,0)==1);
    /* Original MemCardCreateFile reads directory sectors with B4F and
     * waits for SW completion at 8003D4EC (not only the hardware event). */
    assert(bios(0xb0,0x4f,0,0,0x7000)==1);
    assert(bios(0xb0,11,swdone,0,0)==1);
    fd=bios(0xb0,0x32,0x1000,0x8001,0);
    assert(fd>=2 && fd<16);
    (void)bios(0xb0,11,done,0,0); /* discard earlier raw-sector completion */
    assert(bios(0xb0,0x34,fd,0x7000,128)==0);
    assert(bios(0xb0,11,swdone,0,0)==1);
    /* SCPS 8003B264 polls HW completion after async file reads. */
    assert(bios(0xb0,11,done,0,0)==1);
    bios(0xb0,0x36,fd,0,0);
    strcpy((char *)PSX_RAM+0x1100,"bu10:SECOND");
    fd=bios(0xb0,0x32,0x1100,0x20202,0); assert(fd>=2 && fd<16);
    memset(PSX_RAM+0x2000,0x3c,16384);
    assert(bios(0xb0,0x35,fd,0x2000,16384)==16384);
    assert(bios(0xb0,0x33,fd,8064,0)==8064);
    assert(bios(0xb0,0x34,fd,0x7000,256)==256);
    for(int i=0;i<256;i++) assert(PSX_RAM[0x7000+i]==0x3c);
    bios(0xb0,0x36,fd,0,0);
    assert(bios(0xb0,0x45,0x1100,0,0)==1);
    assert(bios(0xb0,0x32,0x1100,1,0)==0xffffffff);
    strcpy((char *)PSX_RAM+0x1100,"bu00:TOOBIG");
    assert(bios(0xb0,0x32,0x1100,0xf0202,0)==0xffffffff);
    strcpy((char *)PSX_RAM+0x1100,"bu01:UNSUPPORTED");
    assert(bios(0xb0,0x32,0x1100,0x10202,0)==0xffffffff);
    assert(bios(0xb0,0x32,0x1f801000,1,0)==0xffffffff);
    strcpy((char *)PSX_RAM+0x1100,"bu00:123456789012345678901");
    assert(bios(0xb0,0x32,0x1100,0x10202,0)==0xffffffff);
    /* The actual game uses INTR events, which must preserve its CPU state. */
    R[4]=0xf0000011; R[5]=4; R[6]=0x1000; R[7]=0x80012340;
    kernel_syscall(0xb0,8); uint32_t intr=R[2]; bios(0xb0,12,intr,0,0);
    R[16]=0x123; HI=11; LO=22;
    assert(bios(0xa0,0xab,0,0,0)==1);
    assert(callback_count==1 && R[4]==0 && R[16]==0x123 && HI==11 && LO==22);
    bios(0xb0,9,intr,0,0);
    /* A failed atomic replacement must keep both the in-memory and old disk data. */
    char moved[1024]; snprintf(moved,sizeof moved,"%s-moved",dir);
    assert(rename(dir,moved)==0);
    fd=bios(0xb0,0x32,0x1000,2,0); assert(fd>=2 && fd<16);
    assert(bios(0xb0,0x35,fd,0x2000,128)==0xffffffff);
    assert(bios(0xb0,0x34,fd,0x7000,128)==128);
    assert(PSX_RAM[0x7000]==0x5a);
    assert(rename(moved,dir)==0);
    memcard_shutdown(); assert(memcard_init(dir)==1);
    fd=bios(0xb0,0x32,0x1000,1,0);
    assert(bios(0xb0,0x34,fd,0x7000,128)==128 && PSX_RAM[0x7000]==0x5a);
    memcard_shutdown();
    char path[1024];
    /* Lock conflicts and truncated images must not silently reset saved data. */
    snprintf(path,sizeof path,"%s/memcard1.lock",dir);
    int lock=open(path,O_RDWR); assert(lock>=0 && flock(lock,LOCK_EX|LOCK_NB)==0);
    assert(memcard_init(dir)==0); memcard_shutdown(); close(lock);
    snprintf(path,sizeof path,"%s/memcard2.mcr",dir);
    assert(truncate(path,123)==0);
    assert(memcard_init(dir)==0);
    struct stat broken; assert(stat(path,&broken)==0 && broken.st_size==123);
    fd=bios(0xb0,0x32,0x1000,1,0); assert(fd>=2 && fd<16);
    assert(bios(0xb0,0x34,fd,0x7000,128)==128 && PSX_RAM[0x7000]==0x5a);
    memcard_shutdown();
    for(int s=1;s<=2;s++) {
        snprintf(path,sizeof path,"%s/memcard%d.mcr",dir,s);
        struct stat st; assert(stat(path,&st)==0 && st.st_size==(s==1?131072:123));
        assert(unlink(path)==0);
        snprintf(path,sizeof path,"%s/memcard%d.lock",dir,s); assert(unlink(path)==0);
    }
    assert(rmdir(dir)==0);
    puts("memory card BIOS persistence, directory, sectors, events, bounds and disk failure passed");
    return 0;
}
