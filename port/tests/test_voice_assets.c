#define _POSIX_C_SOURCE 200809L
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../src/voice_assets.h"
#include "../src/xa_audio.h"
static uint8_t ram[0x200000], original[0x200000];
static void u32(uint8_t *p, uint32_t x) { p[0]=x; p[1]=x>>8; p[2]=x>>16; p[3]=x>>24; }
static uint32_t get32(uint8_t *p) { return p[0]|p[1]<<8|p[2]<<16|(uint32_t)p[3]<<24; }
static void both(uint8_t *p, uint32_t x) { u32(p,x); p[4]=x>>24;p[5]=x>>16;p[6]=x>>8;p[7]=x; }
static unsigned entry(uint8_t *p, const char *name, unsigned lba, unsigned bytes) {
    unsigned n=34+(unsigned)strlen(name); p[0]=n; both(p+2,lba); both(p+10,bytes);
    p[32]=strlen(name); memcpy(p+33,name,strlen(name)); return n;
}
static void image_fixture(FILE *f) {
    uint8_t raw[2352]={0}; raw[15]=2;
    uint8_t *p=raw+24; memcpy(p,"\1CD001\1",7);p[128]=0;p[129]=8;p[130]=8;p[131]=0;
    both(p+158,20);both(p+166,2048);
    assert(!fseek(f,16*2352,SEEK_SET));assert(fwrite(raw,1,2352,f)==2352);
    memset(raw,0,sizeof raw);p=raw+24;
    unsigned n=entry(p,"STEREO.XA;1",40,256*2048);entry(p+n,"MONO.XA;1",296,64*2048);
    assert(!fseek(f,20*2352,SEEK_SET));assert(fwrite(raw,1,2352,f)==2352);
    assert(!fseek(f,360*2352-1,SEEK_SET));fputc(0,f);fflush(f);
}
static void pack_fixture_language(FILE *f,int japanese) {
    uint8_t h[32]={0};memcpy(h,"A2VOICE1",8);u32(h+8,1);u32(h+12,183);
    u32(h+16,256);u32(h+20,64);u32(h+24,japanese?189:7);u32(h+28,32+183*64);
    assert(fwrite(h,1,32,f)==32);
    for(unsigned i=0;i<183;i++) {
        uint8_t r[64]={0};snprintf((char *)r,16,"C%03u",i);
        unsigned addr=i<126 ? 0x54758+i*16 : 0x54f38+(i-126)*16;
        unsigned stride=i<126 ? 8 : 16;
        u32(r+16,addr|0x80000000);u32(r+28,i==0?2:1);
        // Fixture unavailable cues may overlap: the loader must reject overlap.
        // Give each a distinct slot inside sufficiently large original extents.
        u32(r+32,i==0?0:(i<126?8*((i-1)/8+8):16*((i-126)/16)));
        u32(r+36,i==0?0:(i<126?(i-1)%8:(i-126)%16));
        u32(r+40,i==0?7:1);u32(r+44,i==0?0:(japanese?i+6:7));u32(r+48,japanese?3:(i==0?1:0));u32(r+52,stride);
        u32(ram+addr,0);u32(ram+addr+4,0);u32(ram+addr+8,i==0?2:1);
        u32(ram+addr+12,0x80060000+i*16);memcpy(ram+0x60000+i*16,r,16);
        assert(fwrite(r,1,64,f)==64);
    }
    for(unsigned i=0;i<(japanese?189u:7u);i++) {
        uint8_t raw[2352]={0};raw[15]=2;raw[16]=raw[20]=1;raw[18]=raw[22]=0x64;raw[19]=raw[23]=1;
        for(unsigned g=0;g<18;g++) memset(raw+40+g*128,(int)(0x11+i),112);
        assert(fwrite(raw,1,2352,f)==2352);
    }
    fflush(f);
}
static void pack_fixture(FILE *f) { pack_fixture_language(f,0); }
int main(void) {
    char ip[]="/tmp/a2-voice-image-XXXXXX", pp[]="/tmp/a2-voice-pack-XXXXXX";
    int id=mkstemp(ip),pd=mkstemp(pp);assert(id>=0&&pd>=0);
    FILE *im=fdopen(id,"w+b"),*pack=fdopen(pd,"w+b");assert(im&&pack);
    image_fixture(im);pack_fixture(pack);memcpy(original,ram,sizeof ram);
    assert(a2_voice_available(pp));
    assert(a2_voice_available_for_language(pp,1));
    assert(!a2_voice_available_for_language(pp,0));
    assert(!a2_voice_open_for_language(pp,ip,ram,sizeof ram,0));
    assert(!memcmp(ram,original,sizeof ram));
    assert(a2_voice_open(pp,ip,ram,sizeof ram));
    assert(get32(ram+0x54758+8)==7);assert(!memcmp(ram+0x54758+12,original+0x54758+12,4));
    a2_voice_begin(40,1,0);
    XaDecoder decoder={0};size_t total=0;unsigned rate=0;uint8_t raw[2352];int16_t pcm[8064];
    for(unsigned i=0;i<7;i++) {
        assert(a2_voice_read_sector(40+i*8,raw));
        size_t frames=xa_decode_sector(&decoder,raw,sizeof raw,pcm,4032,&rate);
        assert(frames==2016&&rate==37800);total+=frames;a2_voice_observe(40+i*8,frames);
        assert(raw[40]==0x11+i);
    }
    assert(total==14112);assert(a2_voice_read_sector(40+7*8,raw));
    for(unsigned i=0;i<2352;i++) assert(raw[i]==0);
    assert(!a2_voice_read_sector(39,raw));assert(!a2_voice_read_sector(360,raw));
    a2_voice_close();assert(!a2_voice_read_sector(40,raw));
    memcpy(ram,original,sizeof ram);ram[0x60000]='X';
    assert(!a2_voice_open(pp,ip,ram,sizeof ram));assert(get32(ram+0x54758+8)==2);
    memcpy(ram,original,sizeof ram);assert(!ftruncate(pd,32+183*64+2352));
    assert(!a2_voice_available(pp));assert(!a2_voice_open(pp,ip,ram,sizeof ram));
    assert(!memcmp(ram,original,sizeof ram));
    pack=freopen(pp,"w+b",pack);assert(pack);pack_fixture_language(pack,1);
    assert(a2_voice_available_for_language(pp,0));assert(!a2_voice_available_for_language(pp,1));
    assert(a2_voice_open_for_language(pp,ip,ram,sizeof ram,0));a2_voice_close();
    // A mixed-origin record cannot masquerade as a Japanese performance.
    uint8_t en_origin[4]={1,0,0,0};assert(!fseek(pack,32+48,SEEK_SET));
    assert(fwrite(en_origin,1,4,pack)==4);fflush(pack);
    assert(!a2_voice_available_for_language(pp,0));assert(!a2_voice_available_for_language(pp,1));
    fclose(im);fclose(pack);unlink(ip);unlink(pp);
    puts("Voice assets: exact cue mapping, full duration, decoding, guard and fail-closed validation passed");
    return 0;
}
