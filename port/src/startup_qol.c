#include "startup_qol.h"
/* Scoped to the boot sequence: no later EVENT scene inherits auto-skip. */
static int stage,automatic,requested,release;
void a2_startup_reset(int skip) {stage=0;automatic=!!skip;requested=release=0;}
void a2_startup_logo_begin(void) {stage=1;if(automatic)requested=1;}
void a2_startup_movies_begin(void) {if(stage==1)stage=2;}
void a2_startup_request(void) {if(stage==1||stage==2){requested=1;release=1;}}
int a2_startup_skip_requested(void) {return stage>0&&stage<3&&requested;}
void a2_startup_logo_fade(uint32_t *phase,uint32_t *brightness) {
 if(!a2_startup_skip_requested()||!phase||!brightness||*phase>=3)return;
 *phase=2;if(*brightness>16)*brightness=16;
}
uint16_t a2_startup_pad(unsigned frame,int overlay,uint16_t buttons,int held) {
 if(stage==2&&overlay==4){stage=3;requested=0;}
 if((stage==1||(stage==2&&overlay==5))&&buttons!=0xffff)a2_startup_request();
 if(stage==2&&overlay==5&&requested)return frame%30<4?0xfff7:0xffff;
 if(release){if(!held)release=0;return 0xffff;}
 return buttons;
}
