#include "display_layout.h"
#include <assert.h>
#include <math.h>
int main(void) {
 const int sizes[][2]={{1280,720},{1440,900},{1512,982},{1920,1200},{3440,1440},{1024,768}};
 for(unsigned i=0;i<sizeof sizes/sizeof sizes[0];i++) {
  int w=sizes[i][0],h=sizes[i][1];A2DisplayViewport v=a2_display_viewport(w,h,1);
  assert(v.x==0&&v.y==0&&v.width==w&&v.height==h);
  double scale=a2_display_wide_scale(w,h);
  assert(fabs(scale*(double)w/h-4.0/3.0)<1e-12);
  v=a2_display_viewport(w,h,0);assert(v.width<=w&&v.height<=h);
 }
 A2DisplayViewport old=a2_display_viewport(1440,900,0);assert(old.x==0&&old.y==45&&old.width==1440&&old.height==810);
 assert(a2_display_wide_scale(1280,720)==0.75);
 assert(a2_display_wide_scale(0,0)==0.75);
}
