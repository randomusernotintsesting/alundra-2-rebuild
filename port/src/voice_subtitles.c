#include "voice_subtitles.h"
#include <stddef.h>
#include <string.h>
typedef struct {uint32_t start,end;const char *text,*russian;} SubtitleEntry;
typedef struct {const char *name;unsigned first,count;} SubtitleClip;
#include "voice_subtitles_data.inc"

int a2_voice_subtitle_language(int setting,int text_language){
    return setting==1?0:setting==2?2:text_language==0?0:2;
}
const char *a2_english_subtitle(const char *name,uint32_t milliseconds){
    return a2_voice_subtitle(name,milliseconds,2);
}
const char *a2_voice_subtitle(const char *name,uint32_t milliseconds,int language){
    if(!name||(language!=0&&language!=2))return NULL;
    size_t lo=0,hi=sizeof subtitle_clips/sizeof subtitle_clips[0];
    const SubtitleClip *clip=NULL;
    while(lo<hi){
        size_t mid=lo+(hi-lo)/2;int order=strcmp(name,subtitle_clips[mid].name);
        if(!order){clip=subtitle_clips+mid;break;}
        if(order<0)hi=mid;else lo=mid+1;
    }
    if(!clip)return NULL;
    lo=clip->first;hi=lo+clip->count;
    while(lo<hi){
        size_t mid=lo+(hi-lo)/2;const SubtitleEntry *entry=subtitle_entries+mid;
        if(milliseconds<entry->start)hi=mid;
        else if(milliseconds>=entry->end)lo=mid+1;
        else return language==0?entry->russian:entry->text;
    }
    return NULL;
}
