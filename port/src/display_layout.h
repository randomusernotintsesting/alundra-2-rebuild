#ifndef A2_DISPLAY_LAYOUT_H
#define A2_DISPLAY_LAYOUT_H
#include <math.h>
typedef struct { int x,y,width,height; } A2DisplayViewport;
static inline A2DisplayViewport a2_display_viewport(int w,int h,int fill) {
 if(w<=0||h<=0)return (A2DisplayViewport){0,0,0,0};
 if(fill)return (A2DisplayViewport){0,0,w,h};
 float width=w,height=h,vw=width,vh=height,wanted=960.0f/540.0f;
 if(fabsf(wanted-width/height)>=0.0001f) {
  if(wanted>width/height)vh=floorf(540.0f*(width/960.0f));
  else vw=floorf(960.0f*(height/540.0f));
 }
 return (A2DisplayViewport){(int)floorf((width-vw)*.5f),(int)floorf((height-vh)*.5f),(int)vw,(int)vh};
}
static inline double a2_display_wide_scale(int w,int h) {
 return w>0&&h>0?(4.0*h)/(3.0*w):0.75;
}
#endif
