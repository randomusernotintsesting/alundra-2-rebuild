#include "subtitle_panel.h"
#include "voice_subtitles.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
typedef struct {uint32_t start,end;const char *text,*russian;} SubtitleEntry;
typedef struct {const char *name;unsigned first,count;} SubtitleClip;
#include "voice_subtitles_data.inc"
int main(void){
    unsigned captions=0,rasters=0;
    for(unsigned i=0;i<sizeof subtitle_clips/sizeof subtitle_clips[0];i++){
        const SubtitleClip *clip=subtitle_clips+i;uint32_t previous=0;
        if(i)assert(strcmp(subtitle_clips[i-1].name,clip->name)<0);
        for(unsigned j=0;j<clip->count;j++){
            const SubtitleEntry *entry=subtitle_entries+clip->first+j;
            assert(entry->start>=previous&&entry->end>entry->start);
            assert(entry->text&&*entry->text&&entry->russian&&*entry->russian);
            for(int language=0;language<=2;language+=2){
                const char *wanted=language==0?entry->russian:entry->text;
                assert(!strcmp(a2_voice_subtitle(clip->name,entry->start,language),wanted));
                assert(!strcmp(a2_voice_subtitle(clip->name,entry->end-1,language),wanted));
                if(entry->start>previous)assert(!a2_voice_subtitle(clip->name,entry->start-1,language));
                for(int scale=1;scale<=4;scale++){
                    const A2PromptPixels *panel=a2_subtitle_panel_set(wanted,scale,320,240,239);
                    if(!panel){fprintf(stderr,"Unrenderable %s at %u language%d scale%d: %s\n",clip->name,entry->start,language,scale,wanted);return 1;}
                    assert(panel->x>=0&&panel->x+panel->width<=320*scale);
                    assert(panel->y>=207*scale&&panel->y+panel->height<240*scale);
                    rasters++;
                }
            }
            previous=entry->end;captions++;
        }
        assert(!a2_voice_subtitle(clip->name,previous,0));
        assert(!a2_voice_subtitle(clip->name,previous,2));
    }
    a2_subtitle_panel_close();printf("Catalog: %u timed captions, both languages, %u real font rasters, all boundaries/gaps/end passed\n",captions,rasters);
}
