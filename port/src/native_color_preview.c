#include "native_color_preview.h"
#include <stddef.h>

static int16_t matrix(const uint32_t *c,unsigned base,unsigned row,unsigned col) {
    unsigned index=3*row+col;
    return (int16_t)(c[base+index/2]>>((index&1u)*16));
}
static int64_t wrap44(int64_t value) {
    uint64_t low=(uint64_t)value&((UINT64_C(1)<<44)-1);
    return (int64_t)(low^(UINT64_C(1)<<43))-(INT64_C(1)<<43);
}
static int32_t ir(int32_t value,int32_t lower) {
    return value<lower?lower:value>32767?32767:value;
}
static unsigned channel(int32_t value) {
    return value<0?0u:value>255?255u:(unsigned)value;
}
int a2_color_preview_ncds(const uint32_t data[32],const uint32_t control[32],
                          uint32_t base_rgb,uint32_t *result) {
    if(!data||!control||!result)return 0;
    const int16_t normal[3]={(int16_t)data[0],(int16_t)(data[0]>>16),(int16_t)data[1]};
    int32_t light[3],color[3];
    for(unsigned row=0;row<3;row++) {
        int64_t value=0;
        for(unsigned col=0;col<3;col++)value+=(int64_t)matrix(control,8,row,col)*normal[col];
        light[row]=ir((int32_t)(wrap44(value)>>12),0);
    }
    for(unsigned row=0;row<3;row++) {
        int64_t value=(int64_t)(int32_t)control[13+row]*4096;
        for(unsigned col=0;col<3;col++)value+=(int64_t)matrix(control,16,row,col)*light[col];
        color[row]=ir((int32_t)(wrap44(value)>>12),0);
    }
    uint32_t rgb=data[6]&0xff000000u;
    for(unsigned row=0;row<3;row++) {
        int64_t value=(int64_t)((base_rgb>>(8*row))&255u)*color[row]*16;
        int64_t difference=(int64_t)(int32_t)control[21+row]*4096-value;
        int32_t cue=ir((int32_t)(difference>>12),-32768);
        value+=(int64_t)(int32_t)data[8]*cue;
        int32_t mac=(int32_t)(value>>12);
        rgb|=channel(mac>>4)<<(8*row);
    }
    *result=rgb;
    return 1;
}
