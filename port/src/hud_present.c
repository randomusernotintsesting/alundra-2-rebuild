#include "hud_present.h"
#include "../assets/hud_present_sources.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Ordinary GAME00 HUD, verified producer 800A9510 called by 80086064.
 * Menus call the same producer with mode1 and must retain their own layout.
 * The linked list is essential: number and glass emitters reserve holes. */
#define RAM_BYTES 0x200000u
#define MAX_BYTES 8192u
#define MAX_PACKETS 64u
#define MAX_GROUPS 8u
typedef struct {
    uint32_t address, words[13]; /* DMA header, then unmodified GP0 payload */
    unsigned count;
    int anchor;
    uint64_t token;
} Packet;
typedef struct { uint32_t start; int anchor; } Group;
static const uint8_t *memory;
static size_t memory_bytes;
static Packet packets[MAX_PACKETS];
static unsigned packet_count;
static uint64_t serial;
static A2HudPresentStats stats;
static int log_stats;
static struct {
    int active;
    uint32_t start, ot, old_head;
    unsigned count;
    Group groups[MAX_GROUPS];
} building;
uint32_t a2_hud_present_watch_begin=UINT32_MAX;
uint32_t a2_hud_present_watch_end;

static int canonical(uint32_t address,uint32_t *out) {
    uint32_t p=address&0x1fffffffu;
    if(p>=0x800000u) return 0;
    *out=p&0x1fffffu;
    return 1;
}
static uint32_t read_word(uint32_t address) {
    uint32_t value;memcpy(&value,memory+address,4);return value;
}
static int producer_matches(void) {
    if(!memory || memory_bytes<RAM_BYTES) return 0;
    for(unsigned i=0;i<sizeof hud_code_sources/sizeof *hud_code_sources;i++) {
        const struct HudCodeSource *s=&hud_code_sources[i];
        if(memcmp(memory+s->address,s->data,s->bytes)) return 0;
    }
    return 1;
}
void a2_hud_present_reset(void) {
    memset(&building,0,sizeof building);
    memset(packets,0,sizeof packets);
    packet_count=0;
    a2_hud_present_watch_begin=UINT32_MAX;
    a2_hud_present_watch_end=0;
    /* Never reset serial: queued commands cannot adopt a later generation. */
}
void a2_hud_present_init(const uint8_t *ram,size_t bytes) {
    a2_hud_present_reset();memory=ram;memory_bytes=bytes;
    memset(&stats,0,sizeof stats);
    const char *log=getenv("A2_HUD_LOG");log_stats=log && atoi(log)!=0;
}
void a2_hud_present_close(void) {
    if(memory && log_stats) fprintf(stderr,
        "native-hud: begins=%llu accepted=%llu packets=%llu consumed=%llu rejected=%llu invalidated=%llu\n",
        (unsigned long long)stats.begins,(unsigned long long)stats.accepted_builds,
        (unsigned long long)stats.produced_packets,(unsigned long long)stats.consumed_packets,
        (unsigned long long)stats.rejected_builds,(unsigned long long)stats.invalidated_packets);
    a2_hud_present_reset();memory=NULL;memory_bytes=0;
}
void a2_hud_present_stats(A2HudPresentStats *out) { if(out) *out=stats; }
void a2_hud_present_begin(uint32_t start,uint32_t ot,unsigned mode,uint32_t ra) {
    uint32_t p,o;
    stats.begins++;
    a2_hud_present_reset();
    if(mode || ra!=0x8008606cu || !canonical(start,&p) ||
       !canonical(ot,&o) || (p&3) || (o&3) || p>RAM_BYTES-MAX_BYTES ||
       o>RAM_BYTES-4 || !producer_matches()) { stats.rejected_builds++;return; }
    building.active=1;building.start=p;building.ot=o;
    building.old_head=read_word(o)&0xffffffu;
    building.groups[0]=(Group){p,320};building.count=1;
}
void a2_hud_present_group(uint32_t start,int anchor) {
    uint32_t p;
    if(!building.active) return;
    if((anchor!=0 && anchor!=320) || !canonical(start,&p) || (p&3) ||
       p<building.groups[building.count-1].start ||
       p-building.start>MAX_BYTES) { stats.rejected_builds++;building.active=0;return; }
    Group *last=&building.groups[building.count-1];
    if(p==last->start) { last->anchor=anchor;return; }
    if(last->anchor==anchor) return;
    if(building.count==MAX_GROUPS) { stats.rejected_builds++;building.active=0;return; }
    building.groups[building.count++]=(Group){p,anchor};
}
void a2_hud_present_descriptor(uint32_t start,uint32_t ra) {
    if(!building.active) return;
    if(ra==0x800A9688u || ra==0x800A96B0u) a2_hud_present_group(start,0);
    else if(ra==0x800A9728u) a2_hud_present_group(start,320);
    else { stats.rejected_builds++;building.active=0; }
}
void a2_hud_present_end(uint32_t end) {
    uint32_t e;
    if(!building.active) return;
    building.active=0;
    if(!canonical(end,&e) || (e&3) || e<building.start ||
       e-building.start>MAX_BYTES || building.groups[building.count-1].start>e ||
       !producer_matches()) { stats.rejected_builds++;return; }
    uint32_t address=read_word(building.ot)&0xffffffu, previous=e;
    while(address!=building.old_head) {
        if(packet_count==MAX_PACKETS || (address&3) || address<building.start ||
           address>=previous || e-address<4) goto reject;
        uint32_t header=read_word(address), n=header>>24;
        if((n!=9 && n!=12) || 4*(n+1)>previous-address) goto reject;
        unsigned command=read_word(address+4)>>24;
        if((n==9 && command!=0x2c && command!=0x2e) ||
           (n==12 && command!=0x3c && command!=0x3e)) goto reject;
        Packet *p=&packets[packet_count++];
        p->address=address;p->count=n;
        memcpy(p->words,memory+address,4*(n+1));
        unsigned group=building.count-1;
        while(group && address<building.groups[group].start) group--;
        p->anchor=building.groups[group].anchor;
        if(++serial==0) goto reject;
        p->token=serial;
        previous=address;address=header&0xffffffu;
    }
    if(packet_count) {
        a2_hud_present_watch_begin=building.start;
        a2_hud_present_watch_end=e;
    }
    stats.accepted_builds++;stats.produced_packets+=packet_count;
    return;
reject:
    stats.rejected_builds++;
    a2_hud_present_reset();
}
static Packet *find_packet(uint32_t address) {
    uint32_t p;
    if(!memory || !canonical(address,&p) || (p&3) ||
       p<a2_hud_present_watch_begin || p>=a2_hud_present_watch_end) return NULL;
    for(unsigned i=0;i<packet_count;i++)
        if(p==packets[i].address+4 && packets[i].token) return &packets[i];
    return NULL;
}
uint64_t a2_hud_present_packet_token(uint32_t address,uint32_t command) {
    Packet *p=find_packet(address);
    if(!p || p->words[1]!=command ||
       memcmp(memory+p->address,p->words,4*(p->count+1))) return 0;
    return p->token;
}
int a2_hud_present_consume(uint32_t address,uint64_t token,
                           const uint32_t *words,unsigned count,int *anchor) {
    Packet *p=find_packet(address);
    if(!p || !token || p->token!=token || !words || !anchor || count!=p->count)
        return 0;
    p->token=0; /* A packet is eligible at most once, including failed reads. */
    if(memcmp(words,p->words+1,4*count) ||
       memcmp(memory+p->address,p->words,4*(count+1))) return 0;
    *anchor=p->anchor;
    stats.consumed_packets++;
    return 1;
}
void a2_hud_present_invalidate(uint32_t address,size_t bytes) {
    uint32_t p;
    if(!bytes || !canonical(address,&p)) return;
    if(bytes>=RAM_BYTES || bytes>RAM_BYTES-p) {
        /* Bulk replacement and mirrored wrap cannot preserve old provenance. */
        for(unsigned i=0;i<packet_count;i++) {
            if(packets[i].token) stats.invalidated_packets++;
            packets[i].token=0;
        }
        a2_hud_present_watch_begin=UINT32_MAX;a2_hud_present_watch_end=0;
        return;
    }
    uint32_t end=p+(uint32_t)bytes;
    for(unsigned i=0;i<packet_count;i++) {
        Packet *q=&packets[i];
        if(p<q->address+4*(q->count+1) && end>q->address) {
            if(q->token) stats.invalidated_packets++;
            q->token=0;
        }
    }
}
