/* Silent actual-resampler comparison, no audio device or files are opened.
 * clang -O2 -std=gnu11 -ffunction-sections -fdata-sections -Wl,-dead_strip \
 *   -I/opt/homebrew/include/SDL2 port/tests/diagnose_xa_spectrum.c \
 *   -o /private/tmp/a2-xa-spectrum
 * The legacy converter below is the previous rational hold algorithm.
 * dBc measures images RELATIVE to the wanted tone, not absolute loudness. */
#include <assert.h>
#include <math.h>
#include "../src/spu.c"
enum { SOURCE=75600, OUTPUT=88200, WINDOW=44100 };
static int16_t held[OUTPUT],filtered[OUTPUT];

static double amplitude(const int16_t *pcm,unsigned hz) {
    double re=0,im=0;
    for(unsigned i=0;i<WINDOW;i++) {
        double a=2*3.14159265358979323846*hz*i/44100;
        re+=pcm[WINDOW+i]*cos(a);im+=pcm[WINDOW+i]*sin(a);
    }
    return 2*hypot(re,im)/WINDOW;
}
int main(void) {
    for(unsigned hz=5000;hz<=10000;hz+=5000) {
        unsigned phase=0,out=0,filtered_out=0;
        spu_reset_cd_audio();
        for(unsigned base=0;base<SOURCE;base+=630) {
            int16_t input[1260];
            for(unsigned i=0;i<630;i++) {
                int16_t v=(int16_t)lrint(8000*sin(2*3.14159265358979323846*hz*(base+i)/37800));
                input[2*i]=v;input[2*i+1]=0;
                while(phase<44100){assert(out<OUTPUT);held[out++]=v;phase+=37800;}
                phase-=44100;
            }
            spu_push_cd_audio(input,630,37800);assert(cd_count==735);
            for(unsigned i=0;i<cd_count;i++)filtered[filtered_out++]=cd_pcm[(cd_read+i)%CD_FRAMES][0];
            cd_read=(cd_read+cd_count)%CD_FRAMES;cd_count=0;
        }
        assert(out==OUTPUT && filtered_out==OUTPUT);
        for(unsigned mode=0;mode<2;mode++) {
            const int16_t *pcm=mode?filtered:held;
            double wanted=amplitude(pcm,hz),worst=0;unsigned worst_hz=0;
            for(unsigned k=1;k<7;k++) {
                unsigned alias=(hz+k*6300)%44100;if(alias>22050)alias=44100-alias;
                double a=amplitude(pcm,alias);
                if(a>worst){worst=a;worst_hz=alias;}
            }
            printf("tone=%u converter=%s gain=%.6f strongest_image=%u image_dBc=%.3f\n",
                   hz,mode?"documented_fir":"legacy_hold",wanted/8000,worst_hz,20*log10(worst/wanted));
        }
    }
    return 0;
}
