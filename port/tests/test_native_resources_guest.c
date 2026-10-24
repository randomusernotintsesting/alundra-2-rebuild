#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "psx_rt.h"
#include "native_resources_guest.h"
uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t R[32], HI, LO, psx_next, a2_ramwatch, psx_work;
int psx_bb_budget=1000000;
int psx_in_irq,psx_critical;
void psx_bb_fire(void) { assert(!"unexpected wait"); }
void psx_mmio_write(uint32_t p,uint32_t v,int n) {(void)p;(void)v;(void)n;assert(!"CD/MMIO write");}
uint32_t psx_mmio_read(uint32_t p,int n) {(void)p;(void)n;assert(!"CD/MMIO read");return 0;}
void a2_ramwatch_hit(uint32_t p,uint32_t v,int n) {(void)p;(void)v;(void)n;assert(0);}
/* Genuine name/range caller, including its stack argument and continuation. */
#include "../gen/scps_005.c"
static struct {uint32_t address;void (*fn)(void);} hooks[32];
static unsigned hook_count,pause_calls,read_calls;
static int corrupt_read;
void psx_register_hle(uint32_t address,void (*fn)(void)) {
    assert(hook_count<32);hooks[hook_count].address=address;hooks[hook_count++].fn=fn;
}
static void invoke(uint32_t address) {
    for(unsigned i=0;i<hook_count;i++)if(hooks[i].address==address){hooks[i].fn();return;}
    if(address==0x8001BC34u){f_8001BC34();return;}
    if(address==0x8001BC54u){f_8001BC54();return;}
    assert(!"unhandled guest continuation");
}
void psx_call(uint32_t address) {
    assert(address==0x8002FAA4u);pause_calls++;
    memset(R,0xCC,sizeof R);HI=LO=123;psx_next=0;
}
A2ResourceId a2_resource_find(const A2Resources *s,int lang,const char *name) {
    (void)s;assert(lang==0);return !strcmp(name,"DATA/PACK0.PAK")?1:0;
}
uint64_t a2_resource_size(const A2Resources *s,A2ResourceId id){(void)s;assert(id==1);return 6000;}
int a2_resource_pread(A2Resources *s,A2ResourceId id,uint64_t off,void *dst,size_t len,char *err,size_t size){
    (void)s;assert(id==1 && off+len<=6000);read_calls++;
    for(size_t i=0;i<len;i++)((uint8_t*)dst)[i]=(uint8_t)((off+i)*37);
    if(corrupt_read){snprintf(err,size,"bad payload CRC");return 0;}return 1;
}
static void call(uint32_t addr,uint32_t a,uint32_t b,uint32_t c,uint32_t d,int mode){
    for(unsigned i=0;i<32;i++)R[i]=i+100;
    R[0]=0;R[4]=a;R[5]=b;R[6]=c;R[7]=d;R[29]=0x801FF000;R[31]=0x80000100;
    HI=456;LO=789;sw_(R[29]+16,mode);uint32_t regs[32];memcpy(regs,R,sizeof R);
    invoke(addr);unsigned steps=0;
    while(psx_next!=0x80000100){assert(++steps<8);invoke(psx_next);}
    for(unsigned i=16;i<32;i++)assert(R[i]==regs[i]);
    assert(HI==456 && LO==789);
}
static void expect(uint32_t dst,unsigned off,unsigned length){
    for(unsigned i=0;i<length;i++)assert(PSX_RAM[(dst&0x1fffff)+i]==(uint8_t)((off+i)*37));
}
int main(void){
    char err[256];
    const uint32_t guards[][2]={{0x8001AD68,0x27BDFF58},{0x8001B0CC,0x27BDFFA0},
        {0x8001B298,0x27BDFFC0},{0x8001B30C,0x00804021},{0x8001B640,0x27BDFED8},
        {0x80042228,0x27BDFFB0}};
    for(unsigned i=0;i<sizeof guards/sizeof guards[0];i++)sw_(guards[i][0],guards[i][1]);
    assert(a2_native_resources_install((A2Resources*)1,0,err,sizeof err));
    strcpy((char*)PSX_RAM+0x1000,"data\\pack0.pak");sw_(0x8005E6B8,1);
    /* Original wrapper must preserve length, offset and fifth stack argument. */
    call(0x8001BC34,0x80001000,0x80070000,2011,2157,0);
    assert(R[2]==2157 && lh_(0x8005D8C0)==1);expect(0x80070000,2011,2157);
    assert(pause_calls==1 && read_calls==1);
    memset(PSX_RAM+0x70000,0xA5,6000);
    call(0x8001BC34,0x80001000,0x80070000,0,UINT32_MAX,1);
    assert(R[2]==0 && lh_(0x8005D8C0)==0 && PSX_RAM[0x70000]==0xA5);
    psx_critical=1;a2_native_resources_tick();assert(PSX_RAM[0x70000]==0xA5);
    psx_critical=0;psx_in_irq=1;a2_native_resources_tick();assert(PSX_RAM[0x70000]==0xA5);
    psx_in_irq=0;
    a2_native_resources_tick();expect(0x80070000,0,6000);assert(lh_(0x8005D8C0)==1);
    /* A late archive error may dirty host scratch, never guest destination. */
    corrupt_read=1;memset(PSX_RAM+0x70000,0xA5,6000);
    call(0x8001BC34,0x80001000,0x80070000,0,6000,0);
    assert(R[2]==UINT32_MAX && lh_(0x8005D8C0)==2);
    for(unsigned i=0;i<6000;i++)assert(PSX_RAM[0x70000+i]==0xA5);
    corrupt_read=0;unsigned previous=read_calls;
    call(0x8001BC34,0x80001000,0x801FFFF0,0,100,0);
    assert(R[2]==UINT32_MAX && read_calls==previous);
    call(0x8001BC34,0x80001000,0x80070000,5990,100,0);
    assert(R[2]==UINT32_MAX && read_calls==previous);
    /* Queue carries full byte offsets across requests and commits on a tick. */
    call(0x8001B30C,0x80071000,17,100,0,0);
    call(0x8001B30C,0x80072000,4113,500,0,0);
    assert(lh_(0x8005D8DA)==2);
    call(0x8001B640,0x80001000,1,0,0,0);
    assert(R[2]==0 && lh_(0x8005D8DC)==0);
    a2_native_resources_tick();expect(0x80071000,17,100);expect(0x80072000,4113,500);
    assert(lh_(0x8005D8DC)==1 && lh_(0x8005D8DA)==0);
    strcpy((char*)PSX_RAM+0x1100,"\\DATA\\PACK0.PAK;1");
    call(0x80042228,0x80001200,0x80001100,0,0,0);
    assert(R[2]==0x80001200 && lw_(0x80001204)==6000);
    strcpy((char*)PSX_RAM+0x1100,"../DATA/PACK0.PAK");
    call(0x80042228,0x80001200,0x80001100,0,0,0);assert(R[2]==0);
    a2_native_resources_close();puts("native guest resource boundaries: passed");return 0;
}
