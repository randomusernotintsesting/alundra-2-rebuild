/* User gain must scale finished PCM, preserve source progression and clamp. */
#include <assert.h>
#include <stdio.h>
#include "../src/spu.c"
static void render(int percent,int expected) {
    spu_set_master_volume(percent);
    cd_read=0;cd_count=1;cd_pcm[0][0]=4096;cd_pcm[0][1]=-4096;
    int16_t out[2];audio_cb(NULL,(Uint8 *)out,sizeof out);
    assert(out[0]==expected);assert(out[1]==(percent<=0?0:(percent>=100?-4096:-2048)));
    assert(cd_count==0); // Muting never pauses the CD or the emulated mixer.
}
int main(void) {
    spu_write(0x1aa,0xc001);spu_write(0x1b0,32767);spu_write(0x1b2,32767);
    spu_write(0x180,0x3fff);spu_write(0x182,0x3fff);
    render(100,4094);render(50,2047);render(0,0);render(-7,0);render(140,4094);
    puts("User volume PCM scaling, clamp and muted source progression passed");
}
