#include "native_scene_light.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
int main(void){
    uint32_t c[32]={0};c[8]=0x80007fff;c[12]=0xdeadfffe;
    c[16]=0x1234fedc;c[20]=0xbeef8001;c[13]=0x80000001;c[15]=4096;
    c[21]=2048;c[23]=0xffffffff;c[26]=0xffff0060;c[27]=0x12348000;c[28]=0x87654321;
    A2NativeSceneLight a,b;memset(&a,0x4a,sizeof a);
    assert(a2_native_scene_light_decode(c,&a));assert(a2_native_scene_light_valid(&a));
    assert(a.known==1&&a.light_q12[0]==32767&&a.light_q12[1]==-32768&&a.light_q12[8]==-2);
    assert(a.color_q12[0]==-292&&a.color_q12[1]==4660&&a.color_q12[8]==-32767);
    assert(a.background[0]==INT32_MIN+1&&a.background[2]==4096&&a.far_color[0]==2048&&a.far_color[2]==-1);
    assert(a.projection_h==96&&a.dqa==-32768&&a.dqb==(int32_t)-2023406815);
    /* Different padding and all unrelated controls cannot change identity. */
    memset(&b,0xc3,sizeof b);for(unsigned i=0;i<8;i++)c[i]=~c[i];
    c[12]^=0xffff0000;c[20]^=0xffff0000;c[24]=123;c[25]=456;c[29]=789;c[30]=9;c[31]=UINT32_MAX;
    assert(a2_native_scene_light_decode(c,&b)&&a2_native_scene_light_equal(&a,&b));
    c[22]=1;assert(a2_native_scene_light_decode(c,&b)&&!a2_native_scene_light_equal(&a,&b));
    b=a;c[26]=0;assert(!a2_native_scene_light_decode(c,&b)&&a2_native_scene_light_equal(&a,&b));
    b=a;b.dqa=32768;assert(!a2_native_scene_light_valid(&b));b=a;b.known=2;assert(!a2_native_scene_light_valid(&b));
    puts("PASS: copied native light controls, signed units, ignored non-light controls, semantic equality, invalid output preservation");
    return 0;
}
