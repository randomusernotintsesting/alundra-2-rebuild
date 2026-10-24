/* Decode every packed performance using the production XA decoder. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/xa_audio.h"
static uint32_t le32(const uint8_t *p) {
    return p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;
}
int main(int argc,char **argv) {
    if(argc!=2){fprintf(stderr,"Usage: verify_voice_pack voices.a2v\n");return 2;}
    FILE *f=fopen(argv[1],"rb");if(!f)return 2;
    uint8_t h[32],records[183][64];
    if(fread(h,1,32,f)!=32||memcmp(h,"A2VOICE1",8)||le32(h+8)!=1||le32(h+12)!=183||
       fread(records,64,183,f)!=183){fclose(f);return 2;}
    unsigned clips=0,missing=0;uint64_t sectors=0,frames=0,nonzero=0;
    puts("name,sectors,frames,rate,duration_seconds,nonzero_frames,peak,decode_failures");
    for(unsigned i=0;i<183;i++) {
        const uint8_t *r=records[i];if(!memchr(r,0,16)){fclose(f);return 2;}
        if(!le32(r+48)){missing++;continue;}
        XaDecoder decoder={0};uint64_t cf=0,cn=0;unsigned rate=0,peak=0,failures=0;
        uint32_t count=le32(r+40),start=le32(r+44);
        if(fseek(f,(long)(le32(h+28)+(uint64_t)start*2352),SEEK_SET)){fclose(f);return 2;}
        for(unsigned s=0;s<count;s++) {
            uint8_t raw[2352];int16_t pcm[8064];unsigned sample_rate;
            if(fread(raw,1,2352,f)!=2352){fclose(f);return 2;}
            size_t n=xa_decode_sector(&decoder,raw,sizeof raw,pcm,4032,&sample_rate);
            if(!n||(rate&&rate!=sample_rate)){failures++;continue;}
            rate=sample_rate;cf+=n;
            for(size_t p=0;p<n;p++) {
                cn+=pcm[p*2]!=0||pcm[p*2+1]!=0;
                for(unsigned ch=0;ch<2;ch++) {
                    unsigned magnitude=(unsigned)abs((int)pcm[p*2+ch]);
                    if(magnitude>peak)peak=magnitude;
                }
            }
        }
        printf("%s,%u,%llu,%u,%.9f,%llu,%u,%u\n",r,count,(unsigned long long)cf,rate,
               rate?(double)cf/rate:0,(unsigned long long)cn,peak,failures);
        if(failures||!cn){fclose(f);return 1;}
        clips++;sectors+=count;frames+=cf;nonzero+=cn;
    }
    fprintf(stderr,"Voice decode verified: clips=%u unavailable=%u sectors=%llu frames=%llu "
                   "nonzero_frames=%llu failures=0\n",clips,missing,(unsigned long long)sectors,
                   (unsigned long long)frames,(unsigned long long)nonzero);
    fclose(f);return 0;
}
