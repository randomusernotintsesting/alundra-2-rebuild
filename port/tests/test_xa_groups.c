#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "../src/xa_audio.h"
int main(void) {
    uint32_t random=7;
    for(unsigned coding=0;coding<0x16;coding++) {
        if((coding&3)>1 || (coding&12)>4)continue;
        XaDecoder a={0},b={0};
        for(unsigned block=0;block<9;block++) {
            uint8_t raw[2352]={0};raw[15]=2;raw[16]=raw[20]=1;
            raw[18]=raw[22]=0x64;raw[19]=raw[23]=(uint8_t)coding;
            for(unsigned i=24;i<2328;i++){random=random*1664525+1013904223;raw[i]=(uint8_t)(random>>24);}
            int16_t before[8064],after[8064];unsigned r0,r1;
            size_t n=xa_decode_sector(&a,raw,sizeof raw,before,4032,&r0);
            size_t m=xa_decode_groups(&b,raw+24,2304,coding,after,4032,&r1);
            assert(n && n==m && r0==r1 && !memcmp(before,after,n*4));
        }
    }
    XaDecoder d={0};uint8_t payload[2304]={0};int16_t pcm[8064];unsigned rate;
    assert(!xa_decode_groups(&d,payload,2303,0,pcm,4032,&rate));
    assert(!xa_decode_groups(&d,payload,2304,0x80,pcm,4032,&rate));
    assert(!xa_decode_groups(&d,payload,2304,0,pcm,1,&rate));
    puts("Direct XA sound groups match sector decoder over continued histories and all supported coding modes");
}
