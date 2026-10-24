/* Real synthesis: telemetry must reveal pre-master overload without changing PCM. */
#define main existing_audio_test_main
#include "test_audio.c"
#undef main
#include <unistd.h>

static void scene(int enabled) {
    memset(voices,0,sizeof voices);
    clear_reverb_test(0);
    memset(&mix_stats,0,sizeof mix_stats);
    mix_stats_mode=enabled;
    spu_reset_cd_audio();
    spu_set_cd_mix(128,0,0,128,0);
    spu_write(0x1aa,0xc001);
    spu_write(0x180,0x2000);spu_write(0x182,0x2000);
    spu_write(0x1b0,0x4000);spu_write(0x1b2,0x4000);
    spu_write(0x190,0);spu_write(0x192,0);
    spu_write(0x194,0);spu_write(0x196,0);
    spu_write(0x198,0);spu_write(0x19a,0);
    constant_voice(0,30000,0);constant_voice(1,30000,0);
    spu_write(2,0);spu_write(18,0);
    /* This tests levels after reconstruction, independent of filter startup.
     * Supply75 already-resampled frames, the same fixture duration as before. */
    for(unsigned i=0;i<75;i++){cd_pcm[i][0]=16000;cd_pcm[i][1]=-16000;}
    cd_count=75;cd_rate=37800;
}

int main(void) {
    int16_t original[128],observed[128];
    scene(0);audio_cb(NULL,(Uint8*)original,sizeof original);
    assert(mix_stats.pre_master.frames==0);
    scene(1);audio_cb(NULL,(Uint8*)observed,sizeof observed);
    assert(!memcmp(original,observed,sizeof original));
    /* Each voice: 30000 *0.5 envelope, then32766/32768 pan =>14999.
     * Two voices29998 + half-volumeCD8000 =37998 before main gain.
     * Its overload is hidden by the final half-volume master gain. */
    assert(mix_stats.voice[0].peak[0]==14999 && mix_stats.voice[0].peak[1]==0);
    assert(mix_stats.voice[1].peak[0]==14999 && mix_stats.voice[2].frames==0);
    assert(mix_stats.cd_source.peak[0]==16000 && mix_stats.cd_source.peak[1]==16000);
    assert(mix_stats.cd_mix.peak[0]==8000 && mix_stats.cd_mix.peak[1]==8000);
    assert(mix_stats.dry.peak[0]==29998 && mix_stats.dry.peak[1]==0);
    assert(mix_stats.pre_master.frames==64 && mix_stats.pre_master.peak[0]==37998);
    assert(mix_stats.pre_master.over[0]==64 && mix_stats.pre_master.over[1]==0);
    assert(mix_stats.pre_master.energy[0]==UINT64_C(92406272256));
    assert(mix_stats.post_master.over[0]==0 && mix_stats.post_master.over[1]==0);
    assert(mix_stats.wet.peak[0]==0 && mix_stats.wet.peak[1]==0);
    /* Exercise the real periodic report, not only its accumulator helper. */
    FILE *log=tmpfile();assert(log);
    int saved=dup(STDERR_FILENO);assert(saved>=0);
    assert(dup2(fileno(log),STDERR_FILENO)>=0);
    scene(1);
    for(unsigned i=0;i<120;i++)spu_vblank();
    assert(mix_stats.ticks==120 && mix_stats.pre_master.frames==0);
    fflush(stderr);assert(dup2(saved,STDERR_FILENO)>=0);close(saved);
    rewind(log);char text[8192];size_t n=fread(text,1,sizeof text-1,log);text[n]=0;
    assert(strstr(text,"tick=60 stage=pre_master frames=44100"));
    assert(strstr(text,"tick=120 stage=pre_master frames=44100"));
    assert(strstr(text,"tick=60 stage=cd_source frames=75"));
    assert(strstr(text,"tick=120 stage=cd_source frames=0"));
    assert(!strstr(text,"frames=88200"));
    fclose(log);
    puts("PASS: real mixer source levels, hidden pre-master overload and unchanged PCM");
}
