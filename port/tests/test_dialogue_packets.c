/* Execute the genuine resident window builder and SetDrawMode. Fixture state
 * selects the logged opening top edge and completed reward-window interior. */
#define A2_DIALOGUE_PACKETS 1
#include "dialogue_packets.h"
#include "psx_rt.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "fixtures/dialogue_code.h"
#include "../gen/scps_006.c"
#include "../gen/scps_007.c"
#include "../gen/scps_016.c"
uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
uint32_t R[32],HI,LO,psx_work,psx_next,a2_ramwatch;
int psx_bb_budget=1000000;
void psx_bb_fire(void){assert(!"Unexpected busy wait");}
void psx_break(uint32_t n){(void)n;abort();}
void a2_ramwatch_hit(uint32_t p,uint32_t v,int n){(void)p;(void)v;(void)n;abort();}
void psx_syscall_at(uint32_t p){(void)p;abort();}
uint32_t psx_mmio_read(uint32_t p,int n){(void)p;(void)n;abort();}
void psx_mmio_write(uint32_t p,uint32_t v,int n){(void)p;(void)v;(void)n;abort();}
static const psx_func_entry functions[]={
    {0x8001e294,f_8001E294},{0x8001e6e0,f_8001E6E0},
    {0x8001e834,f_8001E834},{0x8001e988,f_8001E988},
    {0x8001ead4,f_8001EAD4},{0x8001ec2c,f_8001EC2C},
    {0x8001ed80,f_8001ED80},{0x800359a8,f_800359A8},
    {0x80020140,f_80020140},{0x80020160,f_80020160},{0x80020184,f_80020184},
    {0x800202c8,f_800202C8},{0x800202f4,f_800202F4},{0x80020318,f_80020318}
};
static void setup(void){
    a2_dialogue_packets_close();memset(PSX_RAM,0,sizeof PSX_RAM);memset(R,0,sizeof R);
    for(unsigned i=0;i<sizeof dialogue_code_regions/sizeof *dialogue_code_regions;i++)
        memcpy(PSX_RAM+dialogue_code_regions[i].address,dialogue_code_regions[i].data,
               dialogue_code_regions[i].bytes);
    a2_dialogue_packets_init(PSX_RAM,sizeof PSX_RAM);
    /* Actual gameplay byte limit from user-cocoa-final RAM4200. The
     * original builder compares allocation end against this unaligned bound. */
    R[4]=0x80102810;R[5]=0x80150000;R[6]=0x80104b86;
    sw_(R[5],0xffffff);sh_(0x800633a6,1);
    a2_dialogue_packets_before(0x8001f0cc,R);
}
static void emit(unsigned slot,uint32_t base,int width,int height,int x,int y,uint32_t caller){
    uint32_t d=0x80064070+24*slot;
    sw_(d,11);sh_(d+6,2);sh_(d+8,width);sh_(d+10,height);
    sh_(d+12,x);sh_(d+14,y);
    R[4]=d;R[5]=base;R[6]=0x80150000;R[7]=0x80104b86;
    R[29]=0x801ff000;R[31]=caller;
    psx_next=0x8001e294;
    for(unsigned step=0;psx_next!=caller;step++){
        assert(step<32);int found=0;
        for(unsigned i=0;i<sizeof functions/sizeof *functions;i++)
            if(functions[i].addr==psx_next){functions[i].fn();found=1;break;}
        assert(found);
    }
    assert(R[2]==base+252);
    if(caller==0x8001f2ac)f_8001F2AC();
    else a2_dialogue_packets_before(caller,R);
}
static uint64_t token(uint32_t a){return a2_dialogue_packets_token(a,lw_(a));}
static int consume(uint32_t a,uint64_t t){
    return a2_dialogue_packets_consume(a,t,(const uint32_t *)(PSX_RAM+(a&0x1fffff)),4);
}
static void emit_text(uint32_t caller){
    R[4]=0x80103000;R[5]=0x80150004;R[6]=0x80104b86;R[31]=caller;
    sw_(R[5],0xffffff);
    a2_dialogue_packets_before(0x80021d20,R);
    R[31]=0x800221ac;
    psx_next=0x80020140;
    for(unsigned step=0;psx_next!=0x800221ac;step++){
        assert(step<1000);int found=0;
        for(unsigned i=0;i<sizeof functions/sizeof *functions;i++)
            if(functions[i].addr==psx_next){functions[i].fn();found=1;break;}
        assert(found);
    }
    assert(R[2]==0x8010304c); /* Three active glyphs and two original E1 nodes. */
    f_800221AC();
}
static void text_nodes(void){
    sw_(0x80065a00,168);
    const unsigned indices[]={0,1,84};
    for(unsigned j=0;j<3;j++){
        uint32_t a=0x80064100+32*indices[j];
        sh_(a,1);sb_(a+6,128);sh_(a+8,0x757e);
        sh_(a+12,97);sh_(a+14,156);sh_(a+20,6);sh_(a+22,16);
        sw_(a+28,j==1?0x80066100:0x80065600);
    }
    sh_(0x80065600,3);
}
int main(void){
    setup();emit(0,0x80102810,304,16,160,172,0x8001f2ac);
    /* Independent live frame4437 top-edge oracle, command address102870. */
    const uint32_t opening[]={0x66707070,0x00a40010,0x757e9008,0x00080120};
    assert(!memcmp(PSX_RAM+0x102870,opening,sizeof opening));
    uint64_t t=token(0x80102870);assert(t);
    assert(consume(0xa0102870,t));assert(!token(0x80102870));assert(!consume(0x80102870,t));
    setup();emit(0,0x80102810,304,64,160,180,0x8001f2ac);
    /* Independent live frame4441 interior oracle, command address1028D0. */
    const uint32_t interior[]={0x66707070,0x009c0010,0x757e9808,0x00300120};
    assert(!memcmp(PSX_RAM+0x1028d0,interior,sizeof interior));assert(token(0x801028d0));
    /* All four simultaneous windows retain tags, independent of position/style. */
    setup();
    for(unsigned i=0;i<4;i++)emit(i,0x80102810+i*252,111+i*4,37+i*2,-91+i*103,42+i*51,0x8001f2ac);
    uint32_t node=lw_(0x80150000)&0xffffff;unsigned rects=0,states=0;
    while(node!=0xffffff){
        unsigned n=lw_(node)>>24;
        if(n==4){assert(token(node+4));assert(consume(node+4,token(node+4)));rects++;}
        else {assert(n==2);assert(!token(node+4));assert(!token(node+8));states++;}
        node=lw_(node)&0xffffff;
    }
    assert(rects==36&&states==24);
    setup();emit(0,0x80102810,304,16,160,172,0x8001f2ac);t=token(0x80102870);assert(t);
    a2_dialogue_packets_reset();assert(!consume(0x80102870,t));
    setup();emit(0,0x80102810,304,16,160,172,0x8001f2ac);assert(token(0x80102870)!=t);
    /* Same-value packet, draw-state or producer-code stores revoke the group. */
    const uint32_t writes[]={0x80102810,0x80102870,0x80102864,0x8001e294,0x8001f2a4,0x800359a8};
    for(unsigned i=0;i<sizeof writes/sizeof *writes;i++){
        setup();emit(0,0x80102810,304,16,160,172,0x8001f2ac);assert(token(0x80102870));
        sb_(writes[i],lb_(writes[i]));assert(!token(0x80102870));
    }
    setup();emit(0,0x80102810,304,16,160,172,0x8001f2ac);
    psx_precision_invalidate(0x801ffffc,0x170000);assert(!token(0x80102870));
    /* Byte-identical copies and stale caller/code observations never gain tags. */
    setup();emit(0,0x80102810,304,16,160,172,0x8001f2ac);
    memcpy(PSX_RAM+0x170000,PSX_RAM+0x102810,252);assert(!token(0x80170060));
    setup();emit(0,0x80102810,304,16,160,172,0x8001f2b0);assert(!token(0x80102870));
    setup();PSX_RAM[0x1e294]^=1;emit(0,0x80102810,304,16,160,172,0x8001f2ac);assert(!token(0x80102870));
    setup();emit(0,0x80102810,304,16,160,172,0x8001f2ac);t=token(0x80102870);
    uint32_t bad[4];memcpy(bad,opening,sizeof bad);bad[1]^=1;
    assert(!a2_dialogue_packets_consume(0x80102870,t,bad,4));assert(!consume(0x80102870,t));
    setup();emit(0,0x80102810,304,16,160,172,0x8001f2ac);
    PSX_RAM[0x102814]^=1;assert(!token(0x80102870));
    /* Only the gameplay typewriter's typed parents gain glyph tokens.
     * Another text parent with identical payload stays unclassified. */
    setup();emit(0,0x80102810,304,16,160,172,0x8001f2ac);text_nodes();emit_text(0x800860a8);
    assert(token(0x80102870)); /* Text emission does not retire the window. */
    assert(token(0x80103004));assert(!token(0x80103018));assert(token(0x80103034));
    assert(!token(0x8010302c));assert(!token(0x80103048)); /* E1 prefixes. */
    assert(consume(0x80103004,token(0x80103004)));assert(!token(0x80103004));
    setup();text_nodes();emit_text(0x800860ac);assert(!token(0x80103004));
    setup();text_nodes();emit_text(0x800860a8);t=token(0x80103004);assert(t);
    sb_(0x8010302c,lb_(0x8010302c));assert(!token(0x80103004));assert(!consume(0x80103004,t));
    setup();text_nodes();emit_text(0x800860a8);assert(token(0x80103004));
    sb_(0x80020140,lb_(0x80020140));assert(!token(0x80103004));
    a2_dialogue_packets_close();puts("dialogue packets: genuine resident output, independent live oracles and provenance lifetime pass");
}
