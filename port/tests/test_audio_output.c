/* Deterministic SDL output boundary; synthesis and all SPU APIs remain real.
 * This catches playing-empty transitions, stale PCM and callback-dependent
 * emulated progression without depending on an OS audio thread's schedule. */
#include <assert.h>
#include <SDL.h>
#include <string.h>
static unsigned char queue[100000];
static Uint32 queued;
static int paused=1, fail_init, fail_open, fail_queue;
static Uint16 period=1024;
static int host_init(Uint32 flags) { assert(flags==SDL_INIT_AUDIO); return fail_init ? -1 : 0; }
static SDL_AudioDeviceID host_open(const char *name,int capture,const SDL_AudioSpec *want,SDL_AudioSpec *have,int changes) {
    assert(!name && !capture && !changes);
    assert(want->freq==44100 && want->format==AUDIO_S16SYS && want->channels==2);
    *have=*want; have->samples=period; have->size=period*4;
    paused=1; return fail_open ? 0 : 1;
}
static void host_pause(SDL_AudioDeviceID d,int p) { assert(d==1); paused=p; }
static void host_clear(SDL_AudioDeviceID d) { assert(d==1); queued=0; }
static Uint32 host_size(SDL_AudioDeviceID d) { assert(d==1); return queued; }
static int host_queue(SDL_AudioDeviceID d,const void *p,Uint32 n) {
    assert(d==1 && n==2940); if(fail_queue) return -1;
    assert(queued+n<=sizeof queue); memcpy(queue+queued,p,n); queued+=n; return 0;
}
static const char *host_error(void) { return "injected failure"; }
#define SDL_InitSubSystem host_init
#define SDL_OpenAudioDevice host_open
#define SDL_PauseAudioDevice host_pause
#define SDL_ClearQueuedAudio host_clear
#define SDL_GetQueuedAudioSize host_size
#define SDL_QueueAudio host_queue
#define SDL_GetError host_error
#include "../src/spu.c"

static void consume(unsigned bytes) {
    if(paused) return;
    if(bytes>queued) bytes=queued;
    memmove(queue,queue+bytes,queued-bytes); queued-=bytes;
}
static void reset_host(Uint16 samples) {
    spu_set_sound(0); spu_dev=0; queued=0; paused=1; period=samples;
    fail_init=fail_open=fail_queue=0;
}
static void prime(void) {
    for(int i=0;i<4;i++) { spu_vblank(); assert(paused); }
    spu_vblank(); assert(!paused && queued==14700);
}
static void enqueue_output_cd(const int16_t *pcm) {
    /* Exactly one tick of already-resampled source PCM. Output queue/mute
     * tests must not depend on XA reconstruction's startup impulse. */
    assert(cd_count == 0);
    memcpy(cd_pcm,pcm,735*2*sizeof *pcm);
    cd_read=0;cd_count=735;
}
static void startup_and_pcm(void) {
    reset_host(1024); spu_set_sound(1); assert(paused && !queued);
    /* 4096 * 128 * 32767 >>22 =4095, then main32766 >>15 =4094. */
    spu_write(0x1aa,0xc001); spu_write(0x1b0,32767); spu_write(0x1b2,32767);
    spu_write(0x180,0x3fff); spu_write(0x182,0x3fff);
    int16_t input[735*2]; for(unsigned i=0;i<1470;i++) input[i]=4096;
    enqueue_output_cd(input); assert(cd_count==735); spu_vblank();
    assert(paused && queued==2940 && cd_count==0);
    for(unsigned i=0;i<1470;i++) { int16_t v; memcpy(&v,queue+i*2,2); assert(v==4094); }
    spu_set_sound(1); assert(paused && queued==2940);
    for(int i=0;i<3;i++) { spu_vblank(); assert(paused); }
    spu_vblank(); assert(!paused && queued==14700);
    spu_set_sound(1); assert(!paused && queued==14700);
    for(int i=0;i<120;i++) { consume(2940); spu_vblank(); assert(!paused && queued==14700); }
}
static void stall_and_overflow(void) {
    reset_host(1024); spu_set_sound(1); prime();
    consume(13230); /* 75ms: three-period priming reserve can bridge this. */
    spu_vblank(); assert(!paused && queued==4410);
    consume(4410); spu_vblank(); assert(paused && queued==2940);
    for(int i=0;i<3;i++) { spu_vblank(); assert(paused); }
    spu_vblank(); assert(!paused && queued==14700);
    for(int i=0;i<8;i++) spu_vblank();
    assert(queued==38220);
    spu_vblank(); assert(paused && queued==2940);
}
static void mute_and_failures(void) {
    reset_host(1024); spu_set_sound(1); prime();
    int16_t input[1470]; for(unsigned i=0;i<1470;i++) input[i]=4096;
    enqueue_output_cd(input); spu_vblank();
    int16_t tail; memcpy(&tail,queue+queued-2,2); assert(tail==4094);
    spu_set_sound(0); assert(paused && queued==0);
    enqueue_output_cd(input); assert(cd_count==735);
    spu_vblank(); assert(cd_count==0 && queued==0 && paused);
    spu_set_sound(1); assert(paused && queued==0); prime();
    for(unsigned i=0;i<queued;i++) assert(queue[i]==0); /* No stale or muted PCM. */
    consume(14700); fail_queue=1; spu_vblank(); assert(paused && queued==0);
    fail_queue=0; prime();
    fail_queue=1; spu_vblank(); assert(paused && queued==0); /* Nonempty failure. */
    fail_queue=0; prime();
    reset_host(1024); fail_open=1; spu_set_sound(1); spu_vblank(); assert(!spu_dev && !queued);
    fail_open=0; spu_set_sound(1); prime();
    reset_host(1024); fail_init=1; spu_set_sound(1); spu_vblank(); assert(!spu_dev && !queued);
    fail_init=0; spu_set_sound(1); prime();
}
static void period_bounds(void) {
    reset_host(0); spu_set_sound(1); prime();
    reset_host(65535); spu_set_sound(1);
    for(int i=0;i<5;i++) { spu_vblank(); assert(paused); }
    spu_vblank(); assert(!paused && queued==17640);
}
int main(void) {
    startup_and_pcm(); stall_and_overflow(); mute_and_failures(); period_bounds();
    puts("audio output transitions and real PCM passed"); return 0;
}
