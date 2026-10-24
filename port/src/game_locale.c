#include "game_locale.h"
int a2_game_text_language;
int a2_game_voice_language = 1;

unsigned a2_locale_default_name(const uint8_t stored[12], uint16_t output[6]) {
    static const uint16_t names[5][6]={
        {0xff55,0xff6c,0xff69,0xff6e,0xff73,0},
        {165,177,214,157,0,0},
        {0xff46,0xff6c,0xff69,0xff6e,0xff74,0},
        {0xff55,0xff6c,0xff69,0xff73,0,0},
        {0xff46,0xff6c,0xff69,0xff74,0,0}
    };
    static const unsigned lengths[]={5,4,5,4,4};
    if(a2_game_text_language<0 || a2_game_text_language>2 ||
       a2_game_voice_language<0 || a2_game_voice_language>1)return 0;
    for(unsigned source=0;source<5;source++) {
        unsigned i=0;
        for(;i<=lengths[source];i++)
            if((stored[i*2]|(uint16_t)stored[i*2+1]<<8)!=names[source][i])break;
        if(i<=lengths[source])continue;
        unsigned selected=(unsigned)a2_game_text_language;
        /* Japanese text stays original. RU/EN use the active voice's spelling,
         * even when an older checkpoint stores a different shipped default. */
        if(selected!=1 && a2_game_voice_language==0)selected=selected==0?3:4;
        for(i=0;i<=lengths[selected];i++)output[i]=names[selected][i];
        return lengths[selected];
    }
    return 0;
}
