#include "voice_subtitles.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
int main(void){
    assert(!a2_english_subtitle(NULL,6000));
    assert(!a2_english_subtitle("UNKNOWN",6000));
    assert(!a2_english_subtitle("002AM",0));
    assert(!a2_english_subtitle("002AM",75000));
    const char *line=a2_english_subtitle("002AM",6200);
    assert(line && strstr(line,"can't stand it anymore"));
    assert(!a2_english_subtitle("002am",6200));
    assert(!a2_english_subtitle("141AS",6200)); // no English audio exists
    const char *ru=a2_voice_subtitle("002AM",6200,0);
    assert(ru && strstr(ru,"терпеть") && strcmp(ru,line));
    assert(!a2_voice_subtitle("002AM",6200,1));
    assert(a2_voice_subtitle_language(0,0)==0);
    assert(a2_voice_subtitle_language(0,1)==2);
    assert(a2_voice_subtitle_language(0,2)==2);
    for(int text=0;text<3;text++){
        assert(a2_voice_subtitle_language(1,text)==0);
        assert(a2_voice_subtitle_language(2,text)==2);
    }
    puts("Subtitle lookup: named English cue, silence, end, case and missing audio passed");
}
