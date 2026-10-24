#include "antialias.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

enum { W=96,H=80,P=103 };
static uint32_t pixels[P*H], before[P*H];
static double coverage(int x,int y,double slope,double intercept) {
    unsigned covered=0;
    for(int sy=0;sy<32;sy++)for(int sx=0;sx<32;sx++)
        covered+=(y+(sy+.5)/32.0)>slope*(x+(sx+.5)/32.0)+intercept;
    return covered/1024.0;
}
int main(void) {
    char error[1024];
    A2Antialias *aa=a2_antialias_create(error,sizeof error);
    if(!aa){fprintf(stderr,"Metal AA unavailable: %s\n",error);return 77;}
    for(unsigned j=0;j<P*H;j++)pixels[j]=0xff395babu;
    memcpy(before,pixels,sizeof pixels);
    assert(a2_antialias_apply(aa,pixels,W,H,P,error,sizeof error));
    assert(!memcmp(before,pixels,sizeof pixels));
    assert(!a2_antialias_apply(aa,pixels,W,H,W-1,error,sizeof error));
    assert(!memcmp(before,pixels,sizeof pixels));
    for(int angle=0;angle<3;angle++)for(int orientation=0;orientation<2;orientation++) {
        double slope=(double[]){.37,.0625,.75}[angle];
        for(int y=0;y<H;y++)for(int x=0;x<P;x++) {
            int light=orientation ? (x+.5)>slope*(y+.5)+21.17 : (y+.5)>slope*(x+.5)+21.17;
            pixels[y*P+x]=x<W?(light?0xffffffffu:0xff000000u):0xdeadbeefu;
        }
        memcpy(before,pixels,sizeof pixels);
        assert(a2_antialias_apply(aa,pixels,W,H,P,error,sizeof error));
        double original_error=0,aa_error=0;unsigned soft=0;
        for(int y=8;y<H-8;y++)for(int x=8;x<W-8;x++) {
            double ideal=orientation?coverage(y,x,slope,21.17):coverage(x,y,slope,21.17);
            double a=(before[y*P+x]&255)/255.0,b=(pixels[y*P+x]&255)/255.0;
            original_error+=(a-ideal)*(a-ideal);aa_error+=(b-ideal)*(b-ideal);
            soft+=b>0&&b<1;
            assert((pixels[y*P+x]>>24)==255);
        }
        for(int y=0;y<H;y++)for(int x=W;x<P;x++)assert(pixels[y*P+x]==0xdeadbeefu);
        printf("slope=%.4f orientation=%d analytic coverage MSE ratio=%.4f soft=%u\n",slope,orientation,aa_error/original_error,soft);
        /* Near-diagonal staircases have less recoverable edge length; require
         * at least a halving of error there, and 75% on the longer runs. */
        assert(soft>20 && aa_error<original_error*(angle==2?.5:.25));
    }
    /* Repeated static menu pixels must not synchronously dispatch another
     * GPU job. Padding/stride are not part of the displayed image. */
    uint32_t expected[P*H], repacked[(P+3)*H];
    memcpy(expected,pixels,sizeof expected);
    uint64_t dispatched=a2_antialias_stats(aa).gpu_dispatches;
    for(int y=0;y<H;y++)for(int x=0;x<P+3;x++)
        repacked[y*(P+3)+x]=x<W?before[y*P+x]:0xdeadbeefu;
    assert(a2_antialias_apply(aa,repacked,W,H,P+3,error,sizeof error));
    assert(a2_antialias_stats(aa).gpu_dispatches==dispatched);
    assert(a2_antialias_stats(aa).reused_frames>0);
    for(int y=0;y<H;y++)for(int x=0;x<P+3;x++)
        assert(repacked[y*(P+3)+x]==(x<W?expected[y*P+x]:0xdeadbeefu));
    /* A single changed visible pixel, even late in a row, invalidates reuse. */
    memcpy(pixels,before,sizeof pixels);pixels[(H-1)*P+W-1]^=0x00ffffffu;
    assert(a2_antialias_apply(aa,pixels,W,H,P,error,sizeof error));
    assert(a2_antialias_stats(aa).gpu_dispatches==dispatched+1);
    /* Resizing, one-pixel inputs and allocation reuse must stay bounded. */
    pixels[0]=0xff123456u;
    assert(a2_antialias_apply(aa,pixels,1,1,P,error,sizeof error));
    assert(pixels[0]==0xff123456u);
    a2_antialias_destroy(aa);
    puts("Metal antialias: analytic edge coverage, constant color, stride and resize pass");
}
