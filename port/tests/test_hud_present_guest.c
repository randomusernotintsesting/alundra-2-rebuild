/* The genuine ordinary HUD builder and all numeric/descriptor/OT helpers
 * execute against retained native gameplay state. No mock emits a packet. */
#include "psx_rt.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "fixtures/hud_present_packets.h"
#include "fixtures/hud_present_guest_state.h"
#include "../gen/game00_021.c"
#include "../gen/game00_022.c"
#include "../gen/game00_004.c"
#include "../gen/scps_005.c"
#include "../gen/scps_008.c"
#include "../gen/scps_016.c"
static const psx_func_entry functions[]={
#include "fixtures/hud_present_guest_table.inc"
};
uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
uint32_t R[32],HI,LO,psx_work,psx_next,a2_ramwatch;
int psx_bb_budget=1000000;
void psx_bb_fire(void){assert(!"Unexpected busy wait");}
void psx_break(uint32_t n){(void)n;assert(!"Unexpected guest break");}
void a2_ramwatch_hit(uint32_t p,uint32_t v,int n){(void)p;(void)v;(void)n;assert(0);}
void psx_syscall_at(uint32_t p){(void)p;assert(0);}
uint32_t psx_mmio_read(uint32_t p,int n){(void)p;(void)n;assert(0);return 0;}
void psx_mmio_write(uint32_t p,uint32_t v,int n){(void)p;(void)v;(void)n;assert(0);}

static void setup(void) {
    a2_hud_present_close();memset(PSX_RAM,0,sizeof PSX_RAM);memset(R,0,sizeof R);
    for(unsigned i=0;i<sizeof hud_code_sources/sizeof *hud_code_sources;i++)
        memcpy(PSX_RAM+hud_code_sources[i].address,hud_code_sources[i].data,hud_code_sources[i].bytes);
    for(unsigned i=0;i<sizeof hud_state_regions/sizeof *hud_state_regions;i++)
        memcpy(PSX_RAM+hud_state_regions[i].address,hud_state_regions[i].data,hud_state_regions[i].bytes);
    a2_hud_present_init(PSX_RAM,sizeof PSX_RAM);
    R[29]=0x801ff000;R[31]=0x8008606c;
    R[4]=0x80160000;R[5]=0x80150000;R[6]=0;
    R[16]=0x8010e3b8; /* Real parent allocation-cursor base. */
    sw_(R[5],0xffffff);
}
static void execute(void) {
    psx_next=0x800A9510;
    for(unsigned step=0;psx_next!=0x800A46F0;step++) {
        assert(step<2000);int found=0;
        for(unsigned i=0;i<sizeof functions/sizeof *functions;i++)
            if(functions[i].addr==psx_next){functions[i].fn();found=1;break;}
        if(!found){fprintf(stderr,"Unexpected HUD continuation %08x\n",psx_next);abort();}
    }
}
static unsigned check_packets(int expect) {
    uint32_t a=lw_(0x80150000)&0xffffff;
    unsigned count=0,variants=0;
    while(a!=0xffffff) {
        uint32_t h=lw_(a),n=h>>24,w[12];assert(n==9||n==12);
        for(unsigned j=0;j<n;j++)w[j]=lw_(a+4+4*j);
        uint64_t token=a2_hud_present_packet_token(a+4,w[0]);int anchor=-1;
        if(expect){assert(token);assert(a2_hud_present_consume(a+4,token,w,n,&anchor));
            /* Saved-packet oracle gives exact payload and anchor in draw order. */
            if(expect==1){assert(count<20);const struct HudFixturePacket *p=&hud_fixture_packets[count];
            assert(n==p->count&&anchor==p->anchor);
            /* Unused high16 bits of UV2/3 in GT4/FT4 contain old allocator
             * bytes; visible fields and colors are what original GPU reads. */
            for(unsigned j=0;j<n;j++){
                uint32_t mask=(n==9&&(j==6||j==8))||(n==12&&(j==8||j==11))?0xffff:0xffffffff;
                assert((w[j]&mask)==(p->words[j+1]&mask));
            }
            }else {
                /* Every command from genuine optional MP/item paths belongs
                 * to the same side as its destination in this fixed fixture. */
                assert(anchor==((int16_t)w[1]<160?0:320));
                unsigned clut=w[2]>>16,x=w[1]&0xffff,y=w[1]>>16;
                if(clut==0x7eb0) variants|=1;
                if(clut==0x7e37 && y==52) variants|=2;
                if(clut==0x7e37 && y==61) variants|=4;
                if(x==274 && y==14 && (w[2]&0xffff)==0x8000) variants|=8;
                if(x==302 && y==38 && clut==0x7e37) variants|=16;
            }
        }else assert(!token);
        count++;assert(count<64);a=h&0xffffff;
    }
    if(expect==2) assert(variants==31);
    return count;
}
int main(void) {
    setup();execute();assert(check_packets(1)==20);
    A2HudPresentStats stats;a2_hud_present_stats(&stats);
    assert(stats.accepted_builds==1&&stats.produced_packets==20&&stats.consumed_packets==20);
    /* Actual inline guest stores revoke identical-value packet writes. */
    setup();execute();uint32_t a=lw_(0x80150000)&0xffffff;
    uint64_t token=a2_hud_present_packet_token(a+4,lw_(a+4));assert(token);
    sb_(0xa0000000|(a+8),lb_(a+8));assert(!a2_hud_present_packet_token(a+4,lw_(a+4)));
    setup();execute();a=lw_(0x80150000)&0xffffff;
    assert(a2_hud_present_packet_token(a+4,lw_(a+4)));
    psx_precision_invalidate(0x1ffffc,0x170000);
    assert(!a2_hud_present_packet_token(a+4,lw_(a+4)));
    /* Mode1 follows the genuine inventory HUD path, never native HUD tags. */
    setup();R[6]=1;execute();assert(check_packets(0)>0);
    /* Guest-state fixture variants enable later acquired MP meter and an
     * equipped consumable; the genuine helpers select UVs, palettes/counts. */
    setup();sb_(0x80063be5,1);sh_(0x80063ea2,0);
    sb_(0x80063c24,4);sb_(0x80063bd0,3);
    execute();assert(check_packets(2)==32);
    a2_hud_present_close();
    puts("hud present: genuine guest builder matches retained 20-packet oracle; menu and identical store excluded");
}
