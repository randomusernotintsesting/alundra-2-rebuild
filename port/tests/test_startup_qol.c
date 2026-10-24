#include "startup_qol.h"
#include <assert.h>
#include <stdio.h>
int main(void) {
 a2_startup_reset(0); a2_startup_request();
 assert(!a2_startup_skip_requested()); /* No game input before startup. */
 a2_startup_logo_begin(); assert(!a2_startup_skip_requested());
 a2_startup_request(); assert(a2_startup_skip_requested());
 uint32_t phase=1,brightness=128; a2_startup_logo_fade(&phase,&brightness);
 assert(phase==2 && brightness==16);
 phase=2;brightness=8;a2_startup_logo_fade(&phase,&brightness);assert(brightness==8);
 a2_startup_movies_begin();
 assert(a2_startup_pad(60,5,0xbfff,1)==0xfff7);
 assert(a2_startup_pad(65,5,0xbfff,1)==0xffff);
 assert(a2_startup_pad(80,4,0xbfff,1)==0xffff);
 assert(a2_startup_pad(81,4,0xbfff,1)==0xffff);
 assert(a2_startup_pad(82,4,0xffff,0)==0xffff);
 assert(a2_startup_pad(83,4,0xbfff,1)==0xbfff);
 a2_startup_request();assert(!a2_startup_skip_requested());
 assert(a2_startup_pad(90,5,0xbfff,1)==0xbfff); /* Later story untouched. */
 a2_startup_reset(1);a2_startup_logo_begin();assert(a2_startup_skip_requested());
 a2_startup_movies_begin();assert(a2_startup_pad(0,5,0xffff,0)==0xfff7);
 a2_startup_reset(0);a2_startup_logo_begin();a2_startup_movies_begin();
 assert(a2_startup_pad(0,5,0xffff,0)==0xffff);
 assert(a2_startup_pad(2,4,0xffff,0)==0xffff);
 puts("Startup skip, bounded fade, title release and later-story isolation passed");
}
