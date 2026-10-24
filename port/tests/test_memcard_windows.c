/* Synthetic PSX RAM, real BIOS card implementation and Windows filesystem. */
#include "psx_rt.h"
#include "memcard.h"
#include "platform/storage_windows.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
uint32_t R[32],HI,LO,a2_ramwatch,psx_frame_no;
static unsigned completions;
void psx_deliver_event(uint32_t cls,uint32_t spec){(void)cls;assert(spec);completions++;}
uint32_t psx_mmio_read(uint32_t p,int s){(void)p;(void)s;return 0;}
void psx_mmio_write(uint32_t p,uint32_t v,int s){(void)p;(void)v;(void)s;}
void a2_ramwatch_hit(uint32_t p,uint32_t v,int s){(void)p;(void)v;(void)s;}
static uint32_t bios(uint32_t table,uint32_t n,uint32_t a,uint32_t b,uint32_t c){
    R[4]=a;R[5]=b;R[6]=c;assert(memcard_bios(table,n));return R[2];
}
int wmain(int argc,wchar_t **argv) {
    assert(argc==3);char *command=a2w_utf8(argv[1]),*dir=a2w_utf8(argv[2]);assert(command&&dir);
    if(!strcmp(command,"unavailable")){
        assert(!memcard_init(dir));memcard_shutdown();
    } else if(!strcmp(command,"probe-env")){
        assert(SetEnvironmentVariableW(L"A2_USER_DIR",argv[2]));assert(memcard_init(NULL));memcard_shutdown();
    } else {
        assert(memcard_init(dir));bios(0xb0,0x4a,1,0,0);bios(0xb0,0x4b,0,0,0);
        strcpy((char *)PSX_RAM+0x1000,"bu00:BISCPS-1011500");
        uint32_t fd=bios(0xb0,0x32,0x1000,0x10202,0);assert(fd>=2&&fd<16);
        memset(PSX_RAM+0x2000,0x5a,8192);assert(bios(0xb0,0x35,fd,0x2000,8192)==8192);
        assert(bios(0xb0,0x36,fd,0,0)==fd);memcard_shutdown();assert(memcard_init(dir));bios(0xb0,0x4b,0,0,0);
        fd=bios(0xb0,0x32,0x1000,1,0);assert(fd>=2&&fd<16);
        assert(bios(0xb0,0x34,fd,0x5000,8192)==8192);
        assert(!memcmp(PSX_RAM+0x2000,PSX_RAM+0x5000,8192));bios(0xb0,0x36,fd,0,0);
        char path[4096];assert(snprintf(path,sizeof path,"%s/memcard1.mcr",dir)<(int)sizeof path);
        wchar_t *wide=a2w_utf16(path);HANDLE reader=CreateFileW(wide,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);free(wide);assert(reader!=INVALID_HANDLE_VALUE);
        fd=bios(0xb0,0x32,0x1000,2,0);assert(fd>=2&&fd<16);
        memset(PSX_RAM+0x2000,0x77,128);assert(bios(0xb0,0x35,fd,0x2000,128)==UINT32_MAX);
        assert(bios(0xb0,0x34,fd,0x7000,128)==128&&PSX_RAM[0x7000]==0x5a);
        CloseHandle(reader);memcard_shutdown();assert(memcard_init(dir));bios(0xb0,0x4b,0,0,0);
        fd=bios(0xb0,0x32,0x1000,1,0);assert(fd>=2&&fd<16);
        assert(bios(0xb0,0x34,fd,0x7000,128)==128&&PSX_RAM[0x7000]==0x5a);
        assert(bios(0xa0,0xab,0,0,0)==1);assert(completions>0);memcard_shutdown();
        puts("PASS native Unicode BIOS card format/create/write/read/restart; sharing failure leaves RAM+disk unchanged; completion signals");
    }
    free(command);free(dir);return 0;
}
