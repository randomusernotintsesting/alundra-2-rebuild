#include "menu_model.h"
#include <string.h>
static int clamp(int n,int lo,int hi) { return n<lo?lo:n>hi?hi:n; }
void a2_menu_model_init(A2MenuModel *m,const A2Settings *s,int startup,int save,int load,unsigned texts,unsigned voices) {
    memset(m,0,sizeof *m);m->original=m->draft=*s;m->draft.wide=1;
    m->startup=!!startup;m->can_save=!!save;m->can_load=!!load;m->text_available=texts&7;m->voice_available=voices&3;
}
int a2_menu_model_available(const A2MenuModel *m) {
    return m->draft.text_language>=0&&m->draft.text_language<3&&m->draft.voice_language>=0&&m->draft.voice_language<2&&
        (m->text_available&(1u<<m->draft.text_language))&&(m->voice_available&(1u<<m->draft.voice_language));
}
int a2_menu_model_restart(const A2MenuModel *m) {
    return !m->startup&&(m->original.text_language!=m->draft.text_language||m->original.voice_language!=m->draft.voice_language||
        ((m->original.irscale==1)!=(m->draft.irscale==1)));
}
static int next_available(int value,int n,int d,unsigned mask) {
    for(int i=0;i<n;i++){value=(value+d+n)%n;if(mask&(1u<<value))return value;}return value;
}
int a2_menu_model_change(A2MenuModel *m,A2MenuSetting what,int direction) {
    if(!direction)return 0;int d=direction<0?-1:1;A2Settings old=m->draft,*s=&m->draft;
    switch(what) {
    case A2_MENU_TEXT:
        s->text_language=next_available(s->text_language,3,d,m->text_available);
        if(s->text_language!=old.text_language){int voice=s->text_language==1?0:1;if(m->voice_available&(1u<<voice))s->voice_language=voice;}break;
    case A2_MENU_VOICE:s->voice_language=next_available(s->voice_language,2,d,m->voice_available);break;
    case A2_MENU_PORTRAITS:s->hd_portraits=!s->hd_portraits;break;
    case A2_MENU_MODELS:return 0;
    case A2_MENU_DISPLAY: {
        int i=s->fullscreen?4:s->window_w==1920?3:s->window_w==1280?2:s->window_w==960?1:0;i=(i+d+5)%5;
        s->fullscreen=i==4;
        if(i<4){const int widths[]={0,960,1280,1920},heights[]={0,540,720,1080};s->window_w=widths[i];s->window_h=heights[i];}break;}
    case A2_MENU_IR:s->irscale=clamp(s->irscale+d,1,4);break;
    case A2_MENU_FILTER:s->filter=!s->filter;break;
    case A2_MENU_ANTIALIAS:s->antialias=!s->antialias;break;
    case A2_MENU_FILL_SCREEN:s->fill_screen=!s->fill_screen;break;
    case A2_MENU_SUBTITLES:s->subtitles=(s->subtitles+d+3)%3;break;
    case A2_MENU_ENGLISH_SUBTITLE_LANGUAGE:s->english_subtitle_language=(s->english_subtitle_language+d+3)%3;break;
    case A2_MENU_SKIP_INTRO:s->skip_intro=!s->skip_intro;break;
    case A2_MENU_CINEMA:s->cinema=!s->cinema;break;
    case A2_MENU_SOUND:s->sound=!s->sound;break;
    case A2_MENU_VOLUME:s->master_volume=clamp(s->master_volume+d*5,0,100);break;
    case A2_MENU_THRESHOLD:s->pad_deadzone=clamp(s->pad_deadzone+d*1024,2048,30000);break;
    default:return 0;
    }
    return memcmp(&old,s,sizeof old)!=0;
}
int a2_menu_model_key(A2MenuModel *m,int bit,int sc) {
    if(!a2_input_pad_bit_valid(bit)||sc<0||sc>=SDL_NUM_SCANCODES||a2_input_key_reserved(sc))return 0;
    for(int i=0;i<16;i++)if(m->draft.key[i]==sc)m->draft.key[i]=0;
    m->draft.key[bit]=sc;return 1;
}
int a2_menu_model_pad(A2MenuModel *m,int bit,int slot,A2PadBinding b) { return a2_input_bind_pad(m->draft.pad,bit,slot,b); }
int a2_menu_model_finish(const A2MenuModel *m,int action,A2Settings *out) {
    if(!out||action<A2_MENU_RESUME||action>A2_MENU_QUIT)return 0;
    if((action==A2_MENU_SAVE&&(m->startup||!m->can_save))||(action==A2_MENU_LOAD&&!m->can_load))return 0;
    if((action==A2_MENU_RESUME||action==A2_MENU_LOAD)&&m->startup&&!a2_menu_model_available(m))return 0;
    *out=m->startup&&action==A2_MENU_QUIT?m->original:m->draft;return 1;
}
