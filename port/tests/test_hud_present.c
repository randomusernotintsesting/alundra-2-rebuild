#include "hud_present.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "fixtures/hud_present_packets.h"

static uint8_t ram[0x200000];
static uint32_t word(uint32_t p) { uint32_t v; memcpy(&v,ram+p,4); return v; }
static void put(uint32_t p,uint32_t v) { memcpy(ram+p,&v,4); }
static const uint32_t start=0x110c54, end=0x111028, ot=0x1154c8, old_head=0x1154c4;

static void prepare(unsigned mode, uint32_t ra) {
    memset(ram,0,sizeof ram);
    for (unsigned i=0;i<sizeof hud_fixture_code/sizeof *hud_fixture_code;i++)
        memcpy(ram+hud_fixture_code[i].address,hud_fixture_code[i].data,hud_fixture_code[i].bytes);
    a2_hud_present_init(ram,sizeof ram);
    put(ot,old_head);
    a2_hud_present_begin(0x80000000|start,0x80000000|ot,mode,ra);
    /* These boundaries are the genuine retained packet allocation, including
     * each number renderer's unused 40 bytes and glass's unused 40 bytes. */
    a2_hud_present_group(0x80110cf4,0);
    a2_hud_present_group(0x80110e34,320);
    a2_hud_present_descriptor(0x80110f3c,0x800A96B0);
    a2_hud_present_descriptor(0x80110ff4,0x800A9728);
    for (unsigned i=0;i<20;i++) {
        const struct HudFixturePacket *p=&hud_fixture_packets[i];
        memcpy(ram+p->address,p->words,(p->count+1)*4);
    }
    put(ot,0x110ff4);
}
static int take(unsigned i,uint64_t token) {
    const struct HudFixturePacket *p=&hud_fixture_packets[i];
    int anchor=-1;
    int ok=a2_hud_present_consume(p->address+4,token,p->words+1,p->count,&anchor);
    if(ok) assert(anchor==p->anchor);
    return ok;
}
static uint64_t token(unsigned i) {
    const struct HudFixturePacket *p=&hud_fixture_packets[i];
    return a2_hud_present_packet_token(0xA0000000|(p->address+4),p->words[1]);
}
static void finish(void) { a2_hud_present_end(0x80000000|end); }
int main(void) {
    prepare(0,0x8008606c);finish();
    for(unsigned i=0;i<20;i++) { uint64_t t=token(i);assert(t);assert(take(i,t));assert(!take(i,t)); }
    A2HudPresentStats stats;a2_hud_present_stats(&stats);
    assert(stats.accepted_builds==1 && stats.produced_packets==20 && stats.consumed_packets==20);
    /* Same textures and positions in another producer never gain a token. */
    prepare(1,0x8008606c);finish();assert(!token(0));
    prepare(0,0x800BB1FC);finish();assert(!token(0));
    prepare(0,0x8008606c);a2_hud_present_end(start);assert(!token(0));
    prepare(0,0x8008606c);put(0x110ff4,0x0c110ff4);finish();assert(!token(0));
    prepare(0,0x8008606c);put(0x110c54,0x09100000);finish();assert(!token(0));
    prepare(0,0x8008606c);put(0x110ff4,0x09110fc0);finish();assert(!token(0));
    /* A forged older node begins inside a newer node's payload envelope. */
    prepare(0,0x8008606c);put(0x110ff4,0x0c110fec);
    put(0x110fec,0x091154c4);put(0x110ff0,0x2c808080);finish();assert(!token(0));
    /* A snapshot is tied to the first queued command and this exact build. */
    prepare(0,0x8008606c);finish();uint64_t stale=token(0);assert(stale);
    a2_hud_present_begin(start,ot,0,0x8008606c);assert(!take(0,stale));
    prepare(0,0x8008606c);finish();assert(!take(0,stale));assert(take(0,token(0)));
    prepare(0,0x8008606c);finish();
    uint32_t a=hud_fixture_packets[0].address;
    uint64_t t=token(0);put(a+8,word(a+8)^1);assert(!take(0,t));
    prepare(0,0x8008606c);finish();t=token(0);
    a2_hud_present_invalidate(0xA0000000|(a+9),1);assert(!take(0,t));
    assert(token(1)); /* Unrelated packet survives a narrow write. */
    prepare(0,0x8008606c);finish();t=token(0);
    a2_hud_present_invalidate(0x80000000|a,4);assert(!take(0,t));
    prepare(0,0x8008606c);finish();t=token(0);
    a2_hud_present_invalidate(0x1f800000,1024);assert(take(0,t));
    prepare(0,0x8008606c);finish();t=token(0);
    a2_hud_present_invalidate(0,0x200000);assert(!take(0,t));
    /* Opcode modification must invalidate producer identity, even when its
     * entry signature still matches. */
    prepare(0,0x8008606c);ram[0xa8400]^=1;
    a2_hud_present_begin(start,ot,0,0x8008606c);finish();assert(!token(0));
    a2_hud_present_close();assert(!token(0));
    puts("hud present: retained 20-packet HUD, holes, producer, generation and overwrite guards passed");
    return 0;
}
