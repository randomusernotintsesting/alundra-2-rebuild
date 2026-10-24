/* Output-boundary experiment. Dummy by default; drain-coreaudio submits zeros only. */
#include <stdio.h>
#include <stdlib.h>
#include "../src/spu.c"

static Uint64 origin, frequency;
static double now_ms(void) {
    return (SDL_GetPerformanceCounter() - origin) * 1000.0 / frequency;
}
static void observe(const char *phase, int frame) {
    printf("%s,%d,%.3f,%u,%d\n", phase, frame, now_ms(),
           SDL_GetQueuedAudioSize(spu_dev), SDL_GetAudioDeviceStatus(spu_dev));
}
static void wait_until(double deadline) {
    while (now_ms() < deadline) SDL_Delay(1);
}
static void supply(const char *phase, int count) {
    double start = now_ms();
    for (int i = 0; i < count; i++) {
        wait_until(start + i * 1000.0 / 60);
        observe(phase, i);
        spu_vblank();
        if (!strcmp(phase, "steady") && i % 60 == 0)
            observe("steady_after", i);
    }
}
int main(int argc, char **argv) {
    int silent_coreaudio = argc > 1 && !strcmp(argv[1], "drain-coreaudio");
    SDL_setenv("SDL_AUDIODRIVER", silent_coreaudio ? "coreaudio" : "dummy", 1);
    spu_init_audio();
    frequency = SDL_GetPerformanceFrequency(); origin = SDL_GetPerformanceCounter();
    if (silent_coreaudio || (argc > 1 && !strcmp(argv[1], "drain"))) {
        if (SDL_InitSubSystem(SDL_INIT_AUDIO)) { fprintf(stderr,"%s\n",SDL_GetError()); return 2; }
        SDL_AudioSpec want = {0}, have;
        want.freq=44100; want.format=AUDIO_S16SYS; want.channels=2; want.samples=1024;
        spu_dev=SDL_OpenAudioDevice(NULL,0,&want,&have,0);
        if (!spu_dev) { fprintf(stderr,"%s\n",SDL_GetError()); return 2; }
        fprintf(stderr,"have freq=%d format=%u channels=%u samples=%u size=%u backend=%s\n",
                have.freq,have.format,have.channels,have.samples,have.size,SDL_GetCurrentAudioDriver());
        static int16_t second[44100*2];
        if (SDL_QueueAudio(spu_dev,second,sizeof second)) return 2;
        puts("phase,frame,time_ms,queued_bytes,status"); observe("prefill",0);
        SDL_PauseAudioDevice(spu_dev,0);
        double start=now_ms();
        for (int i=0;i<=240;i++) { wait_until(start+i*5); observe("drain",i); }
        SDL_CloseAudioDevice(spu_dev); SDL_Quit(); return 0;
    }
    spu_set_sound(1);
    if (!spu_dev) return 2;
    SDL_version v; SDL_GetVersion(&v);
    fprintf(stderr, "SDL=%u.%u.%u backend=%s clock=SDL_GetPerformanceCounter frequency=%llu requested=44100Hz/stereo/S16/1024frames\n",
            v.major,v.minor,v.patch,SDL_GetCurrentAudioDriver(),(unsigned long long)frequency);
    puts("phase,frame,time_ms,queued_bytes,status");
    observe("enable",0);
    supply("steady",480);
    observe("stall_begin",0);
    double start = now_ms();
    for (int i=1;i<=15;i++) { wait_until(start+i*5); observe("stall",i); }
    supply("recovery",120);
    spu_set_sound(0); observe("mute",0);
    for (int i=0;i<3;i++) { spu_vblank(); SDL_Delay(17); observe("muted",i); }
    spu_set_sound(1); observe("resume",0);
    supply("resumed",120);
    spu_set_sound(0); SDL_CloseAudioDevice(spu_dev); SDL_Quit();
    return 0;
}
