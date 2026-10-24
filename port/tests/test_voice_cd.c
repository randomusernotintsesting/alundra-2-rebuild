/* Integrate the real pack reader, CD command filter, decoder and SPU input. */
#define main voice_asset_fixture_main
#include "test_voice_assets.c"
#undef main
#include "../src/spu.c"
#define A2_VOICE_ASSETS 1
#include "../src/cdrom.c"
uint8_t PSX_RAM[PSX_RAM_SIZE];
int psx_in_irq,psx_critical;
uint32_t psx_frame_no;
void psx_irq_set(int bit){(void)bit;}
static unsigned data_interrupts;
void psx_irq_dispatch(void){data_interrupts+=irq_fl==1;irq_fl=0;}
void a2_ramwatch_blk(uint32_t dst,uint32_t len,const char *tag){(void)dst;(void)len;(void)tag;}
int main(void) {
    assert(!setenv("A2_AUDIOSTAT","1",1));
    char ip[]="/tmp/a2-voice-cd-image-XXXXXX",pp[]="/tmp/a2-voice-cd-pack-XXXXXX";
    int id=mkstemp(ip),pd=mkstemp(pp);assert(id>=0&&pd>=0);
    FILE *source=fdopen(id,"w+b"),*pack=fdopen(pd,"w+b");assert(source&&pack);
    image_fixture(source);pack_fixture_language(pack,1);
    assert(a2_voice_open(pp,ip,ram,sizeof ram));assert(cd_open_image(ip));
    mode=0xc8;irq_en=0x1f;
    param[0]=1;param[1]=0;cd_command(0x0d);
    target_lba=40;cd_command(0x06);
    for(int i=0;i<23;i++){psx_frame_no++;cd_vblank();}
    assert(cur_lba==97);assert(cd_stats.selected==7);assert(cd_stats.frames==14112);
    assert(cd_stats.decode_failed==0);assert(cd_count>0);
    // The guest's delayed Mute must not decode the next packed same-channel cue.
    for(int i=0;i<8;i++){psx_frame_no++;cd_vblank();}
    assert(cur_lba>=104);assert(cd_stats.selected==7);assert(cd_stats.frames==14112);
    assert(data_interrupts==0);
    cd_command(0x09);assert(!reading);assert(cd_count==0);
    // A fresh explicit request can play that adjacent cue normally.
    target_lba=104;cd_command(0x06);
    for(int i=0;i<4;i++){psx_frame_no++;cd_vblank();}
    assert(cd_stats.selected==8);assert(cd_stats.frames==16128);
    cd_command(0x15);assert(!reading);assert(cd_count==0);
    a2_voice_close();fclose(img);img=NULL;fclose(source);fclose(pack);unlink(ip);unlink(pp);
    puts("Voice CD integration: exact cue full duration, real filter, decoder, pacing and pause passed");
}
