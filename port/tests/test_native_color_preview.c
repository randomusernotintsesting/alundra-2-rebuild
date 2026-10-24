#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "native_color_preview.h"
/* Compile the unchanged current GTE implementation as the behavioral oracle. */
#include "../src/gte.c"
int a2_wide(void) { return 0; }
uint32_t psx_frame_no;

static uint32_t oracle(const uint32_t data[32],const uint32_t control[32],uint32_t rgb) {
    int32_t old_d[32],old_c[32]; uint32_t old_flag=FLAG;
    memcpy(old_d,D,sizeof D);memcpy(old_c,C,sizeof C);
    memcpy(D,data,sizeof D);memcpy(C,control,sizeof C);
    D[6]=(int32_t)((data[6]&0xff000000u)|(rgb&0xffffffu));
    gte_cmd(0x00e80413u);
    uint32_t result=(uint32_t)D[22];
    memcpy(D,old_d,sizeof D);memcpy(C,old_c,sizeof C);FLAG=old_flag;
    return result;
}
#ifdef A2_TEST_ORIGINAL_COLOR
/* The current renderer keeps the native result from the original base RGB. */
int a2_color_preview_ncds(const uint32_t data[32],const uint32_t control[32],
                          uint32_t base_rgb,uint32_t *result) {
    (void)base_rgb;
    if(!data||!control||!result)return 0;
    *result=oracle(data,control,data[6]);return 1;
}
#endif

static uint32_t rng_state=0x438ad057u;
static uint32_t random_word(void) {
    rng_state^=rng_state<<13;rng_state^=rng_state>>17;rng_state^=rng_state<<5;return rng_state;
}
static void identity_light(uint32_t c[32],int brightness) {
    memset(c,0,32*sizeof *c);
    c[8]=4096;c[10]=4096;c[12]=4096;
    c[16]=(uint16_t)brightness;
    c[17]=(uint32_t)(uint16_t)brightness<<16;
    c[19]=(uint16_t)brightness;
}
static void check(const uint32_t data[32],const uint32_t control[32],uint32_t rgb) {
    uint32_t d_copy[32],c_copy[32],result=0;
    int32_t guest_d[32],guest_c[32];uint32_t guest_flag=FLAG;
    memcpy(d_copy,data,sizeof d_copy);memcpy(c_copy,control,sizeof c_copy);
    memcpy(guest_d,D,sizeof D);memcpy(guest_c,C,sizeof C);
    assert(a2_color_preview_ncds(data,control,rgb,&result));
    assert(!memcmp(data,d_copy,sizeof d_copy)&&!memcmp(control,c_copy,sizeof c_copy));
    assert(!memcmp(D,guest_d,sizeof D)&&!memcmp(C,guest_c,sizeof C)&&FLAG==guest_flag);
    uint32_t expected=oracle(data,control,rgb);
    if(result!=expected) {
        fprintf(stderr,"NCDS mismatch: new base=%08x expected=%08x actual=%08x\n",rgb,expected,result);
        assert(result==expected);
    }
}
int main(void) {
    uint32_t d[32]={0},c[32],result=0;
    d[0]=4096;d[6]=0x3000004e;identity_light(c,2048);
    assert(oracle(d,c,0x00051472)==0x30020a39u); /* 1/2 * (114,20,5), integer floor. */
    check(d,c,0x00051472u); /* Original red result lacks the new green component. */
    identity_light(c,4096);check(d,c,0x00ffffffu);check(d,c,0);
    assert(a2_color_preview_ncds(d,c,0x00553311u,&result)&&result==0x30553311u);
    d[8]=4096;c[21]=16*23;c[22]=16*45;c[23]=16*67;
    assert(oracle(d,c,0)==0x30432d17u);check(d,c,0);
    d[8]=0;identity_light(c,8192);check(d,c,0x00f0ffedu);
    for(unsigned test=0;test<12000;test++) {
        for(unsigned i=0;i<32;i++){d[i]=random_word();c[i]=random_word();}
        d[6]=(d[6]&0xffffffu)|0x30000000u;
        d[8]=test%2?(uint32_t)(int32_t)(int16_t)random_word():random_word()%4097;
        if(test<6000)for(unsigned i=13;i<=23;i++)if(i<16||i>20)c[i]=random_word()%8193;
        check(d,c,random_word());
    }
    result=0xdecafbad;
    assert(!a2_color_preview_ncds(NULL,c,0,&result)&&result==0xdecafbadu);
    assert(!a2_color_preview_ncds(d,NULL,0,&result)&&result==0xdecafbadu);
    assert(!a2_color_preview_ncds(d,c,0,NULL));
    puts("PASS: analytical light/depth-cue cases, 12000 legacy-GTE comparisons, input and guest-state preservation");
    return 0;
}
