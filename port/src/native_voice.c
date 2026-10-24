#include "native_voice.h"
#include "psx_rt.h"
#include "spu.h"
#include "xa_audio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CUES 183u
#define INDEX_BYTES (32u + 64u*CUES)
#define GROUP_BYTES 2304u
typedef struct {
    char name[16];
    uint32_t address,old_offset,old_phase,old_blocks,clock,phase,blocks,origin,coding,stride;
    A2ResourceId resource;
} NativeCue;
static struct {
    A2Resources *store;
    NativeCue cues[CUES];
    uint8_t *ram;
    size_t ram_size;
    int pending,selected,reported;
    uint32_t blocks;
    uint64_t samples,frames;
    XaDecoder decoder;
} voice={.pending=-1,.selected=-1};
static char last_error[256];
/* Verified native-compatible SCPS entry instructions, before any metadata
 * mutation. A different executable must never receive these resident hooks. */
static const struct {uint32_t address,words[6];} entries[]={
    {0x8002fcf0,{0x3c028005,0x8c424754,0x27bdffd0,0xafbf002c,0x10400003,0xafb00028}},
    {0x8002ff90,{0x3c028005,0x8c424754,0x27bdfed0,0xafb10124,0x00808821,0xafbf0128}},
    {0x800301b8,{0x3c028005,0x8c424754,0x27bdfec8,0xafb1012c,0x00808821,0xafbf0130}},
    {0x800302e4,{0x3c028005,0x8c424754,0x27bdfed0,0xafb10124,0x00808821,0xafbf0128}},
    {0x8002fdb4,{0x27bdffd0,0xafb3001c,0x00809821,0xafb20018,0x00a09021,0xafb40020}},
};
static uint32_t get32(const uint8_t *p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
static void put32(uint8_t *p,uint32_t n){p[0]=n;p[1]=n>>8;p[2]=n>>16;p[3]=n>>24;}
static int fail(char *error,size_t size,const char *message){if(error&&size)snprintf(error,size,"%s",message);return 0;}
const char *a2_native_voice_error(void){return last_error;}
void a2_native_voice_transport_error(const char *operation){
    if(!last_error[0])snprintf(last_error,sizeof last_error,"Unexpected disc transport on native resource path: %s",operation);
    fprintf(stderr,"voices: %s\n",last_error);
}
int a2_native_voice_enabled(void){return voice.store!=NULL;}
int a2_native_voice_position(A2VoicePosition *out){
    if(!out)return 0;
    memset(out,0,sizeof *out);
    if(voice.selected<0)return 0;
    const NativeCue *c=voice.cues+voice.selected;
    uint64_t start=(uint64_t)c->phase*252;
    uint64_t length=(uint64_t)c->blocks*(c->coding?2016:4032);
    if(!c->origin||voice.samples<=start||voice.samples-start>=length)return 0;
    *out=(A2VoicePosition){c->name,(uint32_t)((voice.samples-start)*1000/37800),c->origin};
    return 1;
}

static int read_index(A2Resources *store,int language,NativeCue cues[CUES],char *error,size_t size){
    if(!store || (language!=0&&language!=1))return fail(error,size,"Invalid native voice language");
    const char *locale=language==0?"ja":"en";char path[64];
    snprintf(path,sizeof path,"VOICE/%s/index.a2v",locale);
    A2ResourceId index=a2_resource_find(store,3,path);
    uint8_t bytes[INDEX_BYTES];
    if(!index || a2_resource_size(store,index)!=sizeof bytes ||
       !a2_resource_pread(store,index,0,bytes,sizeof bytes,error,size))
        return fail(error,size,"The selected native voice index is unavailable");
    if(memcmp(bytes,"A2NVOC01",8)||get32(bytes+8)!=1||get32(bytes+12)!=CUES||
       get32(bytes+16)!=(uint32_t)language||get32(bytes+20)!=(language==0?183u:177u)||
       get32(bytes+24)!=INDEX_BYTES||get32(bytes+28))
        return fail(error,size,"Invalid native voice index header or source language");
    unsigned available=0;
    for(unsigned i=0;i<CUES;i++){
        const uint8_t *r=bytes+32+64*i;NativeCue *c=cues+i;
        memset(c,0,sizeof *c);memcpy(c->name,r,16);
        c->address=get32(r+16);c->old_offset=get32(r+20);c->old_phase=get32(r+24);
        c->old_blocks=get32(r+28);c->clock=get32(r+32);c->phase=get32(r+36);
        c->blocks=get32(r+40);c->origin=get32(r+44);c->coding=get32(r+48);c->stride=get32(r+52);
        uint32_t address=i<126?0x80054758+i*16:0x80054f38+(i-126)*16;
        unsigned stride=i<126?8:16;
        if(!memchr(c->name,0,16)||!c->name[0])return fail(error,size,"Invalid native cue name");
        for(unsigned n=0;c->name[n];n++)
            if(!((c->name[n]>='A'&&c->name[n]<='Z')||(c->name[n]>='a'&&c->name[n]<='z')||
                 (c->name[n]>='0'&&c->name[n]<='9')||c->name[n]=='_'))
                return fail(error,size,"Unsafe native cue name");
        if(c->address!=address||c->stride!=stride||c->coding!=(i<126?1u:0u)||
           c->old_offset%stride||c->clock%stride||c->phase>=stride||c->old_phase>=stride||
           !c->old_blocks||!c->blocks||c->blocks>400000||get32(r+56)||get32(r+60)||
           (uint64_t)c->clock+c->blocks*(uint64_t)stride+A2_NATIVE_VOICE_CLOCK_BASE>=445350||
           (c->origin && c->origin!=(language==0?3u:1u)))
            return fail(error,size,"Invalid native cue metadata");
        for(unsigned j=0;j<i;j++)if(!strcmp(c->name,cues[j].name))
            return fail(error,size,"Duplicate native cue name");
        if(c->origin){
            snprintf(path,sizeof path,"VOICE/%s/%s.adpcm",locale,c->name);
            c->resource=a2_resource_find(store,3,path);
            if(!c->resource||a2_resource_size(store,c->resource)!=(uint64_t)c->blocks*GROUP_BYTES)
                return fail(error,size,"Native voice payload missing or wrong length");
            available++;
        }
    }
    return available==(language==0?183u:177u)?1:fail(error,size,"Incomplete native voice source coverage");
}
int a2_native_voice_available(A2Resources *store,int language){
    NativeCue cues[CUES];char error[256];return read_index(store,language,cues,error,sizeof error);
}
void a2_native_voice_event(const char *reason){
    if(voice.selected<0||!voice.reported)return;
    NativeCue *c=voice.cues+voice.selected;
    fprintf(stderr,"voicecue: end name=%s reason=%s consumed=%u expected=%u frames=%llu complete=%d native=1\n",
        c->name,reason,voice.blocks,c->blocks,(unsigned long long)voice.frames,voice.blocks==c->blocks);
    voice.reported=0;
}
void a2_native_voice_stop(const char *reason){
    a2_native_voice_event(reason);voice.selected=-1;voice.samples=voice.frames=0;voice.blocks=0;
    memset(&voice.decoder,0,sizeof voice.decoder);
    if(!strcmp(reason,"Init"))voice.pending=-1;
}
void a2_native_voice_close(void){
    a2_native_voice_stop("close");memset(&voice,0,sizeof voice);voice.pending=voice.selected=-1;
}
int a2_native_voice_open(A2Resources *store,int language,uint8_t *ram,size_t ram_size,char *error,size_t size){
    a2_native_voice_close();last_error[0]=0;NativeCue cues[CUES];
    if(!ram||ram_size<PSX_RAM_SIZE)return fail(error,size,"Invalid native voice RAM");
    for(unsigned i=0;i<sizeof entries/sizeof entries[0];i++)
        for(unsigned word=0;word<6;word++)
            if(get32(ram+(entries[i].address&0x1fffff)+word*4)!=entries[i].words[word])
                return fail(error,size,"Native voice hook instructions do not match SCPS executable");
    if(!read_index(store,language,cues,error,size))return 0;
    for(unsigned i=0;i<CUES;i++){
        NativeCue *c=cues+i;const uint8_t *slot=ram+(c->address&0x1fffff);
        uint32_t ptr=get32(slot+12)&0x1fffff;
        if(ptr>ram_size-16||strncmp((const char*)ram+ptr,c->name,16)||get32(slot)!=c->old_offset||
           get32(slot+4)!=c->old_phase||get32(slot+8)!=c->old_blocks)
            return fail(error,size,"Native voice index does not match loaded SCPS executable");
    }
    memcpy(voice.cues,cues,sizeof cues);voice.store=store;voice.ram=ram;voice.ram_size=ram_size;
    for(unsigned i=0;i<CUES;i++){
        NativeCue *c=cues+i;uint8_t *slot=ram+(c->address&0x1fffff);
        psx_precision_invalidate(c->address,12);
        put32(slot,c->clock);put32(slot+4,c->phase);put32(slot+8,c->blocks);
    }
    fprintf(stderr,"voices: native %s archive ready clips=%u image_required=0\n",language==0?"Japanese":"English",language==0?183:177);
    return 1;
}
static void capture_name(void){
    if(!voice.store||get32(voice.ram+0x54754))return;
    uint32_t address=R[4]&0x1fffff;
    if(address>voice.ram_size-16)return;
    for(unsigned i=0;i<CUES;i++)if(!strncmp((const char*)voice.ram+address,voice.cues[i].name,16)){
        voice.pending=(int)i;return;
    }
}
extern void f_8002FDB4(void);
static void resolve_requested_name(void){
    /* The original three named APIs first wait for the manager's busy guard.
     * Capturing at their entries would let a blocked request replace the cue
     * that still owns that guard. These exact call continuations occur after
     * the wait. Queries from other callers must not change playback state. */
    if(R[31]==0x8002FFD0u||R[31]==0x800301F8u||R[31]==0x80030324u)capture_name();
    f_8002FDB4();
}
static void initialize_guest(void){
    if(!voice.store){R[2]=0;psx_next=R[31];return;}
    if(!get32(voice.ram+0x54754)){
        put32(voice.ram+0x54748,0);
        put32(voice.ram+0x79eb0,A2_NATIVE_VOICE_CLOCK_BASE);
        put32(voice.ram+0x79eb4,A2_NATIVE_VOICE_CLOCK_BASE);
        R[4]=R[5]=1;psx_call(0x8004D868u); // original SPU CD mixing enable
        R[4]=11;R[5]=R[6]=0;psx_call(0x80041CA8u); // original blocking Mute
        put32(voice.ram+0x79ed8,0);put32(voice.ram+0x79ecc,127);put32(voice.ram+0x79edc,127);
    }
    R[2]=1;psx_next=R[31];
}
void a2_native_voice_install(void){
    static int installed;if(installed||!voice.store)return;installed=1;
    void psx_register_hle(uint32_t address,void(*fn)(void));
    psx_register_hle(0x8002FDB4u,resolve_requested_name);
    psx_register_hle(0x8002FCF0u,initialize_guest);
}
int a2_native_voice_begin(uint32_t clock,uint8_t file,uint8_t channel){
    a2_native_voice_stop("ReadN");
    if(!voice.store)return 0;
    if(voice.pending<0){snprintf(last_error,sizeof last_error,"Native playback requested without a named cue");return 0;}
    NativeCue *c=voice.cues+voice.pending;
    if(file!=1||channel!=c->phase||clock!=A2_NATIVE_VOICE_CLOCK_BASE+c->clock){
        snprintf(last_error,sizeof last_error,"Native playback clock/filter does not match cue %s",c->name);return 0;
    }
    voice.selected=voice.pending;
    if(!c->origin)fprintf(stderr,"voices: no English source for requested cue %s; preserving silent timeline\n",c->name);
    return 1;
}
int a2_native_voice_advance(unsigned clock_units,int decode_enabled){
    if(voice.selected<0)return 1;
    NativeCue *c=voice.cues+voice.selected;
    // All accepted sources are original 37800-Hz four-bit ADPCM. Advance in
    // source-sample units; 252 samples equal one unit of the resident 150-Hz clock.
    voice.samples+=(uint64_t)clock_units*252;
    unsigned block_frames=c->coding?2016:4032;
    while(voice.blocks<c->blocks && (uint64_t)c->phase*252+(uint64_t)voice.blocks*block_frames<voice.samples){
        if(c->origin&&decode_enabled){
            uint8_t groups[GROUP_BYTES];int16_t pcm[8064];unsigned rate;
            if(!a2_resource_pread(voice.store,c->resource,(uint64_t)voice.blocks*GROUP_BYTES,
                                  groups,sizeof groups,last_error,sizeof last_error)){
                if(!last_error[0])snprintf(last_error,sizeof last_error,"Cannot read native cue %s",c->name);
                fprintf(stderr,"voices: %s\n",last_error);a2_native_voice_stop("read-error");return 0;
            }
            size_t frames=xa_decode_groups(&voice.decoder,groups,sizeof groups,c->coding,pcm,4032,&rate);
            if(!frames){snprintf(last_error,sizeof last_error,"Cannot decode native cue %s",c->name);a2_native_voice_stop("decode-error");return 0;}
            if(!voice.reported){
                extern uint32_t psx_frame_no;
                fprintf(stderr,"voicecue: start frame=%u name=%s origin=%u sectors=%u first_sample=%u native=1\n",
                    psx_frame_no,c->name,c->origin,c->blocks,voice.blocks);voice.reported=1;
            }
            voice.frames+=frames;spu_push_cd_audio(pcm,frames,rate);
        }
        voice.blocks++;
    }
    return 1;
}
