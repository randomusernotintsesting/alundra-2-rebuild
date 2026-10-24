#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../src/native_voice.h"
#include "../src/psx_rt.h"
#define A2_NATIVE_VOICE 1
#include "../src/cdrom.c"

struct A2Resources { int dummy; };
static struct A2Resources store;
static uint8_t voice_index[11744];
static unsigned pushes,frames_pushed,data_interrupts,reset_count;
static int force_read_error,mix_muted;
uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[1024];
uint32_t R[32],HI,LO,psx_next,psx_frame_no;
int psx_in_irq,psx_critical;
static struct {uint32_t address;void(*fn)(void);} hooks[8];
static unsigned hook_count;
static void put(uint8_t *p,uint32_t v){p[0]=v;p[1]=v>>8;p[2]=v>>16;p[3]=v>>24;}
void psx_register_hle(uint32_t address,void(*fn)(void)){hooks[hook_count].address=address;hooks[hook_count++].fn=fn;}
#ifndef A2_NATIVE_REAL_GUEST
void psx_call(uint32_t address){(void)address;R[2]=1;}
void f_8002FF90(void){psx_next=R[31];}
void f_800301B8(void){psx_next=R[31];}
void f_800302E4(void){psx_next=R[31];}
void f_8002FDB4(void){psx_next=R[31];}
#endif
void psx_irq_set(int bit){(void)bit;}
void psx_irq_dispatch(void){data_interrupts+=irq_fl==1;irq_fl=0;}
void a2_ramwatch_blk(uint32_t dst,uint32_t len,const char *tag){(void)dst;(void)len;(void)tag;}
void spu_reset_cd_audio(void){reset_count++;}
void spu_set_cd_mix(uint8_t ll,uint8_t lr,uint8_t rl,uint8_t rr,int mute){(void)ll;(void)lr;(void)rl;(void)rr;mix_muted=mute;}
void spu_push_cd_audio(const int16_t *pcm,size_t frames,unsigned rate){assert(rate==37800);assert(pcm[0] || pcm[2]);pushes++;frames_pushed+=(unsigned)frames;}
A2ResourceId a2_resource_find(const A2Resources *s,int language,const char *name){
    assert(s==&store&&language==3);
    if(!strcmp(name,"VOICE/ja/index.a2v"))return 1;
    if(!strcmp(name,"VOICE/ja/MX_09s.adpcm"))return 119;
    unsigned i;char suffix[16];
    if(sscanf(name,"VOICE/ja/C%3u%15s",&i,suffix)==2 && !strcmp(suffix,".adpcm") && i<183)return i+2;
    return 0;
}
uint64_t a2_resource_size(const A2Resources *s,A2ResourceId id){assert(s==&store);return id==1?11744:(id==2?3:1)*2304;}
int a2_resource_pread(A2Resources *s,A2ResourceId id,uint64_t offset,void *out,size_t len,char *error,size_t cap){
    assert(s==&store);(void)error;(void)cap;
    if(id==1){assert(offset+len<=11744);memcpy(out,voice_index+offset,len);return 1;}
    if(force_read_error)return 0;
    assert(offset+len<=a2_resource_size(s,id));
    uint8_t payload[2304]={0};for(unsigned g=0;g<18;g++)memset(payload+g*128+16,0x11,112);
    assert(len==2304 && offset%2304==0);memcpy(out,payload,len);return 1;
}
static void fixture(void){
    const uint32_t guards[][7]={
        {0x2fcf0,0x3c028005,0x8c424754,0x27bdffd0,0xafbf002c,0x10400003,0xafb00028},
        {0x2ff90,0x3c028005,0x8c424754,0x27bdfed0,0xafb10124,0x00808821,0xafbf0128},
        {0x301b8,0x3c028005,0x8c424754,0x27bdfec8,0xafb1012c,0x00808821,0xafbf0130},
        {0x302e4,0x3c028005,0x8c424754,0x27bdfed0,0xafb10124,0x00808821,0xafbf0128},
        {0x2fdb4,0x27bdffd0,0xafb3001c,0x00809821,0xafb20018,0x00a09021,0xafb40020}};
    for(unsigned i=0;i<5;i++)for(unsigned j=0;j<6;j++)put(PSX_RAM+guards[i][0]+j*4,guards[i][j+1]);
    memcpy(voice_index,"A2NVOC01",8);put(voice_index+8,1);put(voice_index+12,183);
    put(voice_index+20,183);put(voice_index+24,sizeof voice_index);
    for(unsigned i=0;i<183;i++){
        uint8_t *row=voice_index+32+i*64;snprintf((char*)row,16,"C%03u",i);
        if(i==117)memcpy(row,"MX_09s",7);
        uint32_t address=i<126?0x80054758+i*16:0x80054f38+(i-126)*16;
        put(row+16,address);put(row+28,1);put(row+32,i*64);put(row+36,i?0:5);
        put(row+40,i?1:3);put(row+44,3);put(row+48,i<126);put(row+52,i<126?8:16);
        uint8_t *slot=PSX_RAM+(address&0x1fffff);put(slot+8,1);put(slot+12,0x80060000+i*16);
        memcpy(PSX_RAM+0x60000+i*16,row,16);
    }
}
static void select_name(unsigned i){
    R[4]=0x80060000+i*16;R[31]=0x8002FFD0;
    for(unsigned h=0;h<hook_count;h++)if(hooks[h].address==0x8002FDB4){hooks[h].fn();assert(psx_next==R[31]);return;}
    assert(!"Missing named guest hook");
}
static void ticks(unsigned n){while(n--){psx_frame_no++;cd_vblank();}}
int main(void){
    fixture();char error[192];
    assert(a2_native_voice_available(&store,0));assert(!a2_native_voice_available(&store,1));
    uint8_t unchanged[0x200000];memcpy(unchanged,PSX_RAM,sizeof unchanged);
    PSX_RAM[0x2ff90]^=1;
    assert(!a2_native_voice_open(&store,0,PSX_RAM,sizeof PSX_RAM,error,sizeof error));
    assert(strstr(error,"instructions"));PSX_RAM[0x2ff90]^=1;
    assert(!memcmp(unchanged,PSX_RAM,sizeof unchanged));
    voice_index[32+16]^=1;
    assert(!a2_native_voice_open(&store,0,PSX_RAM,sizeof PSX_RAM,error,sizeof error));
    assert(!memcmp(unchanged,PSX_RAM,sizeof unchanged));voice_index[32+16]^=1;
    assert(a2_native_voice_open(&store,0,PSX_RAM,sizeof PSX_RAM,error,sizeof error));
    a2_native_voice_install();assert(a2_native_voice_enabled());
    A2VoicePosition position;
    assert(!a2_native_voice_position(&position));
    assert(img==NULL);cd_boot_handoff();irq_en=0x1f;mode=0xc8;
    select_name(0);param[0]=1;param[1]=5;cd_command(0x0d);
    // A resolver used for a query must not replace the accepted play request.
    for(unsigned h=0;h<hook_count;h++)if(hooks[h].address==0x8002FDB4){
        R[4]=0x80060010;R[31]=0x87654321;hooks[h].fn();
    }
    target_lba=A2_NATIVE_VOICE_CLOCK_BASE;cd_command(0x06);
    assert(!a2_native_voice_position(&position)); // phase has not reached the audio
    ticks(2);assert(pushes==0);
    assert(!a2_native_voice_position(&position));
    ticks(1);assert(pushes==1); // phase5 at the third frame
    assert(a2_native_voice_position(&position));
    assert(!strcmp(position.name,"C000") && position.origin==3 && position.milliseconds==13);
    A2VoicePosition frozen=position;
    assert(a2_native_voice_position(&position));
    assert(position.milliseconds==frozen.milliseconds); // reads never advance the clock
    param[0]=1;param[1]=5;cd_command(0x0d); // identical filter keeps the request
    cd_command(0x0b);assert(mix_muted);ticks(3);assert(pushes==2);
    assert(a2_native_voice_position(&position) && position.milliseconds==66); // mute retains timing
    cd_command(0x0c);assert(!mix_muted);ticks(4);assert(pushes==3 && frames_pushed==6048);
    ticks(60);assert(pushes==3 && data_interrupts==0); // no adjacent playback or data IRQ
    assert(!a2_native_voice_position(&position)); // fully elapsed audio cannot retain a caption
    cd_command(0x09);assert(!reading && reset_count);
    assert(!a2_native_voice_position(&position));
    select_name(1);param[0]=1;param[1]=0;cd_command(0x0d);
    target_lba=A2_NATIVE_VOICE_CLOCK_BASE+64;cd_command(0x06);ticks(1);assert(pushes==4);
    assert(a2_native_voice_position(&position) && !strcmp(position.name,"C001"));
    select_name(0);param[0]=1;param[1]=5;cd_command(0x0d);
    target_lba=A2_NATIVE_VOICE_CLOCK_BASE;cd_command(0x06);ticks(3);assert(pushes==5);
    param[0]=1;param[1]=4;cd_command(0x0d);ticks(15);assert(pushes==5);
    assert(!a2_native_voice_position(&position));
    cd_command(0x15);assert(!reading);
    param[0]=1;param[1]=5;cd_command(0x0d);cd_command(0x06);
    force_read_error=1;ticks(10);assert(pushes==5);
    assert(!a2_native_voice_position(&position));
    assert(data_interrupts==0 && cd_native_raw_read_attempts()==0 && cd_native_dma_attempts()==0);
    // A stray old loader cannot silently publish zero/stale data without an image.
    memset(PSX_RAM+0x10000,0xa5,32);cd_dma_read(0x10000,8);
    for(unsigned i=0;i<32;i++)assert(PSX_RAM[0x10000+i]==0xa5);
    assert(cd_native_dma_attempts()==1);
    assert(!load_sector(123) && cd_native_raw_read_attempts()==1);
    a2_native_voice_close();assert(!a2_native_voice_enabled());
    puts("No-image named playback: phase, full duration, mute, same/changed filter, pause, seek, padding and read failure passed");
    return 0;
}
