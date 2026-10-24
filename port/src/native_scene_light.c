#include "native_scene_light.h"
#include <string.h>
static int16_t signed16(uint32_t v){v&=65535;return (int16_t)(v&32768?(int32_t)v-65536:(int32_t)v);}
static int32_t signed32(uint32_t v){return (int32_t)((int64_t)v-(v&0x80000000u?INT64_C(4294967296):0));}
int a2_native_scene_light_valid(const A2NativeSceneLight *a){
    return a&&(a->known==0||(a->known==1&&a->projection_h>0&&a->projection_h<=65535&&a->dqa>=-32768&&a->dqa<=32767));
}
int a2_native_scene_light_decode(const uint32_t c[32],A2NativeSceneLight *out){
    if(!c||!out||!(c[26]&65535))return 0;
    A2NativeSceneLight a={0};a.known=1;
    for(unsigned i=0;i<9;i++){
        a.light_q12[i]=signed16(c[8+i/2]>>(16*(i%2)));
        a.color_q12[i]=signed16(c[16+i/2]>>(16*(i%2)));
    }
    for(unsigned i=0;i<3;i++){a.background[i]=signed32(c[13+i]);a.far_color[i]=signed32(c[21+i]);}
    a.projection_h=c[26]&65535;a.dqa=signed16(c[27]);a.dqb=signed32(c[28]);*out=a;return 1;
}
int a2_native_scene_light_equal(const A2NativeSceneLight *a,const A2NativeSceneLight *b){
    if(!a2_native_scene_light_valid(a)||!a2_native_scene_light_valid(b)||a->known!=b->known)return 0;
    if(!a->known)return 1;
    return !memcmp(a->light_q12,b->light_q12,sizeof a->light_q12)&&
        !memcmp(a->color_q12,b->color_q12,sizeof a->color_q12)&&
        !memcmp(a->background,b->background,sizeof a->background)&&
        !memcmp(a->far_color,b->far_color,sizeof a->far_color)&&
        a->dqa==b->dqa&&a->dqb==b->dqb&&a->projection_h==b->projection_h;
}
