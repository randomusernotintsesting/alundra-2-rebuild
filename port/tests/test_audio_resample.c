/* Real CD input path. Literal oracles from the measured PSX-SPX coefficient
 * table, not from the production resampler or a duplicate implementation.
 * https://psx-spx.consoledev.net/cdromformat/#25-point-zigzag-interpolation */
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../src/spu.c"

static void impulse(void) {
    int16_t input[30*2]={0};input[0]=16384;input[1]=-16384;
    static const int16_t left[35]={
        -1,1,-3,2,5,13,-34,
        4,153,-463,1244,-3008,10736,10736,
        -3008,1244,-463,153,4,-34,13,
        5,2,-3,1,-1,0,0,
        0,0,0,0,0,0,0
    };
    static const int16_t right[35]={
        1,-2,2,-3,-5,-13,34,
        -5,-153,463,-1244,3008,-10736,-10736,
        3008,-1244,463,-153,-5,34,-13,
        -5,-3,2,-2,0,0,0,
        0,0,0,0,0,0,0
    };
    spu_reset_cd_audio();spu_push_cd_audio(input,30,37800);
    assert(cd_count==35);
    for(unsigned i=0;i<35;i++) {
        if(cd_pcm[(cd_read+i)%CD_FRAMES][0]!=left[i] ||
           cd_pcm[(cd_read+i)%CD_FRAMES][1]!=right[i]) {
            fprintf(stderr,"impulse[%u] got %d,%d expected %d,%d\n",i,
                    cd_pcm[(cd_read+i)%CD_FRAMES][0],cd_pcm[(cd_read+i)%CD_FRAMES][1],
                    left[i],right[i]);
            assert(0);
        }
    }
}

static void copy_queue(int16_t *out) {
    for(unsigned i=0;i<cd_count;i++) {
        out[2*i]=cd_pcm[(cd_read+i)%CD_FRAMES][0];
        out[2*i+1]=cd_pcm[(cd_read+i)%CD_FRAMES][1];
    }
}

static void legacy_half_rate(void) {
    const int16_t in[6]={100,-100,200,-200,300,-300};
    const int16_t expected[14]={100,-100,100,-100,100,-100,200,-200,
                                200,-200,300,-300,300,-300};
    spu_reset_cd_audio();spu_push_cd_audio(in,3,18900);
    assert(cd_count==7 && !memcmp(cd_pcm,expected,sizeof expected));
}

static void split_and_rates(void) {
    int16_t input[4032*2],reference[9408*2],split[9408*2];
    uint32_t seed=17;
    for(unsigned i=0;i<4032*2;i++) {
        seed=1664525u*seed+1013904223u;
        input[i]=(int16_t)((int32_t)(seed%32001)-16000);
    }
    for(unsigned rate=18900;rate<=37800;rate*=2) {
        spu_reset_cd_audio();spu_push_cd_audio(input,4032,rate);
        unsigned frames=rate==37800?4704:9408;
        assert(cd_count==frames && cd_phase==0);copy_queue(reference);
        const unsigned chunks[]={1,5,7,31,511,2016};
        for(unsigned c=0;c<sizeof chunks/sizeof chunks[0];c++) {
            spu_reset_cd_audio();
            for(unsigned offset=0;offset<4032;) {
                unsigned n=4032-offset;if(n>chunks[c])n=chunks[c];
                spu_push_cd_audio(input+offset*2,n,rate);offset+=n;
                assert(cd_count==(rate==37800?(offset/6)*7:(offset*7+2)/3));
            }
            assert(cd_count==frames);copy_queue(split);
            assert(!memcmp(reference,split,frames*2*sizeof(int16_t)));
        }
    }
}

static void dc_gain(void) {
    int16_t input[60];for(unsigned i=0;i<30;i++){input[2*i]=10000;input[2*i+1]=-10000;}
    /* Independently evaluated all29 documented taps; preserve their gain,
     * not a renormalized/boosted filter or unfiltered DC pass-through. */
    const int16_t expected[14]={9044,-9068,9059,-9083,9042,-9067,9059,-9083,
                                9044,-9069,9052,-9075,9052,-9075};
    spu_reset_cd_audio();spu_push_cd_audio(input,30,37800);
    assert(cd_count==35 && !memcmp(cd_pcm[28],expected,sizeof expected));
}

static void reset_and_saturation(void) {
    int16_t input[60]={0};
    /* Align the signs of a full30-frame history with output phase3's
     * documented coefficients: it exceeds int16, and must saturate, not wrap. */
    static const int sign[29]={0,-1,1,-1,1,1,-1,1,-1,1,-1,1,-1,1,1,
                              -1,-1,1,-1,1,-1,1,-1,1,1,-1,1,-1,0};
    for(unsigned lag=1;lag<=29;lag++) {
        input[2*(30-lag)]=(int16_t)(sign[lag-1]*32767);
        input[2*(30-lag)+1]=(int16_t)(sign[lag-1]*-32767);
    }
    spu_reset_cd_audio();spu_push_cd_audio(input,30,37800);
    assert(cd_pcm[31][0]==32767 && cd_pcm[31][1]==-32768);
    spu_reset_cd_audio();memset(input,0,sizeof input);spu_push_cd_audio(input,30,37800);
    for(unsigned i=0;i<35;i++)assert(cd_pcm[i][0]==0 && cd_pcm[i][1]==0);
    input[0]=16384;
    spu_reset_cd_audio();spu_push_cd_audio(input,11,37800);
    assert(cd_count==7 && cd_phase==5);
    int16_t first[14];copy_queue(first);
    memset(input,0,sizeof input);spu_push_cd_audio(input,3,18900);
    assert(cd_count==14 && cd_phase==0 && cd_rate==18900);
    assert(!memcmp(first,cd_pcm,sizeof first));
    for(unsigned i=7;i<14;i++)assert(cd_pcm[i][0]==0 && cd_pcm[i][1]==0);
    spu_push_cd_audio(NULL,30,37800);spu_push_cd_audio(input,0,37800);
    spu_push_cd_audio(input,30,44100);
    assert(cd_count==14 && cd_phase==0 && cd_rate==18900);
}

static void wrap_and_drop(void) {
    enum { INPUT=30000, OUTPUT=35000 };
    static int16_t source[INPUT*2],reference[OUTPUT*2];
    for(unsigned i=0;i<INPUT;i++) {source[2*i]=(int16_t)((int)(i%2001)-1000);source[2*i+1]=0;}
    spu_reset_cd_audio();
    for(unsigned start=0;start<INPUT;start+=600) {
        spu_push_cd_audio(source+2*start,600,37800);assert(cd_count==700);
        copy_queue(reference+(start/6*7)*2);
        cd_read=(cd_read+cd_count)%CD_FRAMES;cd_count=0;
    }
    spu_reset_cd_audio();uint64_t before=audio_stats.cd_dropped;
    spu_push_cd_audio(source,INPUT,37800);
    assert(cd_count==CD_FRAMES && audio_stats.cd_dropped-before==OUTPUT-CD_FRAMES);
    for(unsigned i=0;i<CD_FRAMES;i++) {
        assert(cd_pcm[(cd_read+i)%CD_FRAMES][0]==reference[2*(OUTPUT-CD_FRAMES+i)]);
        assert(cd_pcm[(cd_read+i)%CD_FRAMES][1]==0);
    }
}

int main(void) {
    assert(setenv("A2_AUDIOSTAT","1",1)==0);
    legacy_half_rate();
    impulse();
    split_and_rates();dc_gain();reset_and_saturation();wrap_and_drop();
    puts("PASS: CD reconstruction, signed rounding, both rates, chunk/sector continuity, reset and FIFO bounds");
    return 0;
}
