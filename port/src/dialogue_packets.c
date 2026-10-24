#include "dialogue_packets.h"
#include <string.h>

#define RAM_BYTES 0x200000u
#define BUILD_BYTES 252u
#define MAX_WINDOWS 4u
#define RECTANGLES 9u
#define MAX_GLYPHS 168u
#define TEXT_BYTES (MAX_GLYPHS*20u+16u)
/* SCPS_101.15 resident sources, also verified against live RAM. See the
 * source-proof report for SHA256 identities and exact emitter offsets. */
static const struct {uint32_t first,last;uint64_t hash;} sources[]={
    {0x1e294,0x1edec,UINT64_C(0x2b70159db330cf6e)},
    {0x1f0cc,0x1f2fc,UINT64_C(0x808a629479afa91b)},
    {0x359a8,0x35a3c,UINT64_C(0x89bfbb16443a3edb)},
    {0x20140,0x2037c,UINT64_C(0xf493ac2e705555b0)},
    {0x21d20,0x2220c,UINT64_C(0x3c7803acf32b4954)},
    {0x86090,0x860a8,UINT64_C(0x8039bda9f7e17a0e)}
};
/* Fixed allocation boundaries of the verified original program. These are
 * packet identities, never screen coordinates, colors, UVs or atlas matches. */
static const unsigned nodes[]={0,20,40,60,80,92,112,124,144,156,176,188,208,220,240};
static const unsigned rectangles[]={4,24,44,64,96,128,160,192,224};
typedef struct {
    uint32_t address,words[BUILD_BYTES/4];
    uint64_t tokens[RECTANGLES];
} Window;
static const uint8_t *memory;
static size_t memory_bytes;
static Window windows[MAX_WINDOWS];
static unsigned window_count,active,slots;
static uint32_t arena_start,arena_limit,bucket;
static uint64_t serial;
static struct {unsigned active;uint32_t start,old_head;} pending;
static struct {
    unsigned armed,pending,valid,count,bytes,capacity,halves[2],prefix[2];
    uint32_t arena,start,ot,limit,old_head,words[TEXT_BYTES/4],parents[256];
    uint8_t cache[MAX_GLYPHS*32];
    unsigned offsets[MAX_GLYPHS];
    uint8_t eligible[MAX_GLYPHS];
    uint64_t tokens[MAX_GLYPHS];
} text;
uint32_t a2_dialogue_packets_watch_begin=UINT32_MAX,a2_dialogue_packets_watch_end;

static int physical(uint32_t address,unsigned bytes,uint32_t *out){
    uint32_t p=address&0x1fffffffu;
    if(p>=0x800000u)return 0;
    p&=0x1fffffu;if(bytes>RAM_BYTES-p)return 0;
    *out=p;return 1;
}
static uint32_t read_word(uint32_t p){uint32_t v;memcpy(&v,memory+p,4);return v;}
static int code_matches(unsigned count){
    if(!memory||memory_bytes<RAM_BYTES)return 0;
    for(unsigned i=0;i<count;i++){
        uint64_t h=UINT64_C(14695981039346656037);
        for(uint32_t p=sources[i].first;p<sources[i].last;p++)
            h=(h^memory[p])*UINT64_C(1099511628211);
        if(h!=sources[i].hash)return 0;
    }
    return 1;
}
void a2_dialogue_packets_reset(void){
    memset(windows,0,sizeof windows);
    memset(&text,0,sizeof text);
    window_count=active=slots=pending.active=0;
    a2_dialogue_packets_watch_begin=UINT32_MAX;a2_dialogue_packets_watch_end=0;
    /* Keep serial monotonic: queued commands cannot acquire a new generation. */
}
void a2_dialogue_packets_init(const uint8_t *ram,size_t bytes){
    a2_dialogue_packets_reset();memory=ram;memory_bytes=bytes;
}
void a2_dialogue_packets_close(void){
    a2_dialogue_packets_reset();memory=NULL;memory_bytes=0;
}
static void begin_frame(const uint32_t *r){
    a2_dialogue_packets_reset();
    if(!code_matches(3)||!physical(r[4],0,&arena_start)||
       !physical(r[5],4,&bucket)||!physical(r[6],0,&arena_limit)||
       ((arena_start|bucket)&3)||arena_start>arena_limit)return;
    active=1;
}
static void begin_window(const uint32_t *r){
    pending.active=0;uint32_t descriptor,start,ot,limit;
    if(!active||window_count==MAX_WINDOWS||r[31]!=0x8001f2acu||
       !physical(r[4],24,&descriptor)||descriptor<0x64070u||
       descriptor>=0x640d0u||(descriptor-0x64070u)%24||
       !physical(r[5],BUILD_BYTES,&start)||!physical(r[6],4,&ot)||
       !physical(r[7],0,&limit)||((start|ot)&3)||ot!=bucket||
       limit!=arena_limit||start<arena_start||start>limit||BUILD_BYTES>limit-start||
       (bucket<start+BUILD_BYTES&&bucket+4>start)||!code_matches(3))return;
    unsigned bit=1u<<((descriptor-0x64070u)/24);
    if(slots&bit)return;
    for(unsigned i=0;i<window_count;i++)
        if(start<windows[i].address+BUILD_BYTES&&start+BUILD_BYTES>windows[i].address)return;
    uint32_t old_head=read_word(bucket)&0xffffffu;
    if(old_head>=start&&old_head<start+BUILD_BYTES)return;
    slots|=bit;pending.active=1;pending.start=start;pending.old_head=old_head;
}
static void end_window(const uint32_t *r){
    if(!pending.active)return;
    pending.active=0;uint32_t end,start=pending.start;
    if(!active||r[31]!=0x8001f2acu||!physical(r[2],0,&end)||
       end!=start+BUILD_BYTES||!code_matches(3)||
       (read_word(bucket)&0xffffffu)!=start+240u)return;
    uint32_t previous=pending.old_head;
    for(unsigned i=0;i<sizeof nodes/sizeof *nodes;i++){
        unsigned offset=nodes[i],bytes=(i+1<sizeof nodes/sizeof *nodes?nodes[i+1]:BUILD_BYTES)-offset;
        uint32_t header=read_word(start+offset),command=read_word(start+offset+4);
        if((header&0xffffffu)!=previous||header>>24!=bytes/4-1)return;
        if(bytes==20){if((command>>24&0xfdu)!=0x64u)return;}
        else if(bytes!=12||command>>24!=0xe1u||read_word(start+offset+8)>>24!=0xe2u)return;
        previous=start+offset;
    }
    if(serial>UINT64_MAX-RECTANGLES){a2_dialogue_packets_reset();return;}
    Window *w=&windows[window_count++];w->address=start;
    memcpy(w->words,memory+start,BUILD_BYTES);
    for(unsigned i=0;i<RECTANGLES;i++)w->tokens[i]=++serial;
    if(start<a2_dialogue_packets_watch_begin)a2_dialogue_packets_watch_begin=start;
    if(end>a2_dialogue_packets_watch_end)a2_dialogue_packets_watch_end=end;
}
static void refresh_watch(void){
    uint32_t begin=UINT32_MAX,end=0;
    for(unsigned i=0;i<window_count;i++){
        if(windows[i].address<begin)begin=windows[i].address;
        if(windows[i].address+BUILD_BYTES>end)end=windows[i].address+BUILD_BYTES;
    }
    if(text.valid){
        if(text.start<begin)begin=text.start;
        if(text.start+text.bytes>end)end=text.start+text.bytes;
    }
    if(text.pending){
        if(0x65600u<begin)begin=0x65600u;
        if(0x65a04u>end)end=0x65a04u;
    }
    a2_dialogue_packets_watch_begin=begin;a2_dialogue_packets_watch_end=end;
}
static void begin_typewriter(const uint32_t *r){
    /* The preceding window build belongs to the same draw submission. */
    memset(&text,0,sizeof text);refresh_watch();
    if(r[31]!=0x800860a8u||!code_matches(6)||
       !physical(r[4],0,&text.arena)||!physical(r[5],4,&text.ot)||
       !physical(r[6],0,&text.limit)||((text.arena|text.ot)&3)||
       text.arena>text.limit)return;
    text.armed=1;
}
static void begin_glyphs(const uint32_t *r){
    text.pending=0;uint32_t start,ot,limit;
    if(!text.armed||r[31]!=0x800221acu||!code_matches(6)||
       !physical(r[4],0,&start)||!physical(r[5],4,&ot)||
       !physical(r[6],0,&limit)||((start|ot)&3)||
       ot!=text.ot||limit!=text.limit||start<text.arena||start>limit)return;
    text.armed=0;text.capacity=read_word(0x65a00);
    if(!text.capacity||text.capacity>MAX_GLYPHS||(text.capacity&1))return;
    memcpy(text.parents,memory+0x65600,sizeof text.parents);
    memcpy(text.cache,memory+0x64100,text.capacity*32);
    unsigned cursor=0;
    for(unsigned half=0;half<2;half++){
        for(unsigned j=0;j<text.capacity/2;j++){
            uint32_t node=0x64100+32*(half*(text.capacity/2)+j);
            if(!(read_word(node)&0xffffu))continue;
            unsigned n=text.count++;uint32_t parent;
            text.offsets[n]=cursor+4;
            text.eligible[n]=physical(read_word(node+28),32,&parent)&&
                parent>=0x65600u&&parent<0x65a00u&&!(parent&31);
            text.halves[half]++;cursor+=20;
        }
        text.prefix[half]=cursor;cursor+=8;
    }
    if(cursor>limit-start||cursor>RAM_BYTES-start||
       (ot<start+cursor&&ot+4>start))return;
    text.start=start;text.bytes=cursor;text.old_head=read_word(ot)&0xffffffu;
    if(text.old_head>=start&&text.old_head<start+cursor)return;
    text.pending=1;refresh_watch();
}
static void end_glyphs(const uint32_t *r){
    if(!text.pending)return;
    text.pending=0;uint32_t end;
    if(r[31]!=0x800221acu||!physical(r[2],0,&end)||end!=text.start+text.bytes||
       !code_matches(6)||read_word(0x65a00)!=text.capacity||
       memcmp(text.parents,memory+0x65600,sizeof text.parents)||
       (read_word(text.ot)&0xffffffu)!=text.start+text.prefix[1])goto reject;
    for(unsigned i=0;i<text.capacity;i++){
        const uint8_t *old=text.cache+i*32,*now=memory+0x64100+i*32;
        /* Only state, fade brightness and fade step are mutable in20140.
         * Parent identity, UV, geometry and inactive-node order stay exact. */
        if((!old[0]&&!old[1]&&(now[0]||now[1]))||memcmp(old+2,now+2,4)||
           memcmp(old+7,now+7,19)||memcmp(old+28,now+28,4))goto reject;
    }
    uint32_t previous=text.old_head;unsigned n=0;
    for(unsigned half=0;half<2;half++){
        for(unsigned j=0;j<text.halves[half];j++,n++){
            uint32_t node=text.start+text.offsets[n]-4;
            if(read_word(node)!=(0x04000000u|previous)||read_word(node+4)>>24!=0x64u)goto reject;
            previous=node;
        }
        uint32_t prefix=text.start+text.prefix[half];
        if(read_word(prefix)!=(0x01000000u|previous)||
           read_word(prefix+4)!=(half?0xe100023fu:0xe100023eu))goto reject;
        previous=prefix;
    }
    if(serial>UINT64_MAX-text.count){a2_dialogue_packets_reset();return;}
    memcpy(text.words,memory+text.start,text.bytes);
    for(unsigned i=0;i<text.count;i++)if(text.eligible[i])text.tokens[i]=++serial;
    text.valid=1;
reject:
    refresh_watch();
}
void a2_dialogue_packets_before(uint32_t pc,const uint32_t *r){
    if(!r)return;
    if(pc==0x8001f0ccu)begin_frame(r);
    else if(pc==0x8001e294u)begin_window(r);
    else if(pc==0x8001f2acu)end_window(r);
    else if(pc==0x80021d20u)begin_typewriter(r);
    else if(pc==0x80020140u)begin_glyphs(r);
    else if(pc==0x800221acu)end_glyphs(r);
}
static Window *find(uint32_t address,unsigned *index){
    uint32_t p;
    if(!memory||!physical(address,4,&p)||(p&3)||p<a2_dialogue_packets_watch_begin||
       p>=a2_dialogue_packets_watch_end)return NULL;
    for(unsigned i=0;i<window_count;i++){
        Window *w=&windows[i];
        if(p<w->address||p>=w->address+BUILD_BYTES)continue;
        for(unsigned j=0;j<RECTANGLES;j++)if(p==w->address+rectangles[j]){
            *index=j;return w;
        }
    }
    return NULL;
}
static int find_text(uint32_t address){
    uint32_t p;
    if(!text.valid||!physical(address,4,&p)||(p&3)||p<text.start||
       p>=text.start+text.bytes)return -1;
    for(unsigned i=0;i<text.count;i++)if(p==text.start+text.offsets[i])return (int)i;
    return -1;
}
uint64_t a2_dialogue_packets_token(uint32_t address,uint32_t command){
    unsigned i;Window *w=find(address,&i);
    if(w)return w->tokens[i]&&command==w->words[rectangles[i]/4]&&
        !memcmp(memory+w->address,w->words,BUILD_BYTES)?w->tokens[i]:0;
    int j=find_text(address);
    return j>=0&&text.tokens[j]&&command==text.words[text.offsets[j]/4]&&
        !memcmp(memory+text.start,text.words,text.bytes)?text.tokens[j]:0;
}
int a2_dialogue_packets_consume(uint32_t address,uint64_t token,
                               const uint32_t *words,unsigned count){
    unsigned i;Window *w=find(address,&i);
    if(w){
        if(!token||token!=w->tokens[i]||!words)return 0;
        w->tokens[i]=0;
        return count==4&&!memcmp(words,w->words+rectangles[i]/4,16)&&
               !memcmp(memory+w->address,w->words,BUILD_BYTES);
    }
    int j=find_text(address);
    if(j<0||!token||token!=text.tokens[j]||!words)return 0;
    text.tokens[j]=0;
    return count==4&&!memcmp(words,text.words+text.offsets[j]/4,16)&&
           !memcmp(memory+text.start,text.words,text.bytes);
}
void a2_dialogue_packets_invalidate(uint32_t address,size_t bytes){
    uint32_t p;if(!bytes||!physical(address,0,&p))return;
    if(bytes>RAM_BYTES-p){a2_dialogue_packets_reset();return;}
    uint32_t end=p+(uint32_t)bytes;
    for(unsigned i=0;i<sizeof sources/sizeof *sources;i++)
        if(p<sources[i].last&&end>sources[i].first){a2_dialogue_packets_reset();return;}
    for(unsigned i=0;i<window_count;i++){
        Window *w=&windows[i];
        if(p<w->address+BUILD_BYTES&&end>w->address)memset(w->tokens,0,sizeof w->tokens);
    }
    if(text.valid&&p<text.start+text.bytes&&end>text.start){
        text.valid=0;memset(text.tokens,0,sizeof text.tokens);
    }
    /* After completion the copied parent state is sealed; later text-state
     * animation cannot change provenance of an already completed GP0 list. */
    if(text.pending&&p<0x65a04u&&end>0x65600u)text.pending=0;
}
