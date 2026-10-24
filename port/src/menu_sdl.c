/* In-window host UI. The guest and audio are suspended by the caller. */
#include "menu_sdl.h"
#include "menu_model.h"
#include "text_raster.h"
#include "render_capture.h"
#include "save_browser_model.h"
#include "game_profiles.h"
#include "voice_assets.h"
#ifdef A2_NATIVE_RESOURCES
#include "native_voice.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct { SDL_Window *window;SDL_Renderer *renderer;SDL_Texture *frame;int fw,fh;char logo[4096]; } Context;
static Context context;
void a2_menu_sdl_set_context(SDL_Window *w,SDL_Renderer *r,SDL_Texture *frame,int fw,int fh,const char *logo) {
    context.window=w;context.renderer=r;context.frame=frame;context.fw=fw;context.fh=fh;
    snprintf(context.logo,sizeof context.logo,"%s",logo?logo:"");
}
typedef struct { char *text;int size,width,bold,w,h,dpi;SDL_Texture *texture;unsigned age; } CachedText;
typedef struct {
    Context ctx;int language,logicalw,logicalh,clip_enabled,integer_scale,lost,armed,quit;
    SDL_Rect clip;SDL_Texture *target,*logo;int logo_w,logo_h,dpi;
    SDL_BlendMode blend;Uint8 red,green,blue,alpha;uint16_t previous;
    CachedText cache[192];unsigned clock;uint64_t started;int captured;
} View;
static SDL_Color gold={225,192,117,255},white={244,237,218,255},muted={173,162,142,255};
static const char *loc(int l,const char *ru,const char *ja,const char *en) { return l==1?ja:l==2?en:ru; }
#define L(v,ru,ja,en) loc((v)->language,ru,ja,en)
static void fill(View *v,SDL_Rect r,SDL_Color c) { SDL_SetRenderDrawColor(v->ctx.renderer,c.r,c.g,c.b,c.a);SDL_RenderFillRect(v->ctx.renderer,&r); }
static void border(View *v,SDL_Rect r,SDL_Color c) { SDL_SetRenderDrawColor(v->ctx.renderer,c.r,c.g,c.b,c.a);SDL_RenderDrawRect(v->ctx.renderer,&r); }
static SDL_Texture *texture(View *v,A2TextRaster *r) {
    SDL_Texture *t=SDL_CreateTexture(v->ctx.renderer,SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STATIC,r->width,r->height);
    if(t){SDL_UpdateTexture(t,NULL,r->pixels,r->width*4);SDL_SetTextureBlendMode(t,SDL_BLENDMODE_BLEND);SDL_SetTextureScaleMode(t,SDL_ScaleModeLinear);}return t;
}
static CachedText *cached(View *v,const char *s,int size,int width,int bold) {
    int ow,oh;SDL_GetRendererOutputSize(v->ctx.renderer,&ow,&oh);
    int dpi=(int)ceil(fmin(ow/960.0,oh/540.0));if(dpi<2)dpi=2;if(dpi>4)dpi=4;
    CachedText *slot=NULL;
    for(unsigned i=0;i<192;i++) { CachedText *c=v->cache+i;
        if(c->text&&c->size==size&&c->width==width&&c->bold==bold&&c->dpi==dpi&&!strcmp(c->text,s)){c->age=++v->clock;return c;}
        if(!slot||!c->text||(slot->text&&c->age<slot->age))slot=c;
    }
    SDL_DestroyTexture(slot->texture);free(slot->text);memset(slot,0,sizeof *slot);
    A2TextRaster r={0};int ok=size>=23?a2_text_rasterize_title(s,size*dpi,width*dpi,bold,&r):a2_text_rasterize(s,size*dpi,width*dpi,bold,&r);
    if(!ok)return NULL;
    slot->texture=texture(v,&r);slot->w=(r.width+dpi-1)/dpi;slot->h=(r.height+dpi-1)/dpi;a2_text_raster_free(&r);
    if(!slot->texture)return NULL;
    slot->text=malloc(strlen(s)+1);if(!slot->text){SDL_DestroyTexture(slot->texture);memset(slot,0,sizeof *slot);return NULL;}
    strcpy(slot->text,s);slot->size=size;slot->width=width;slot->dpi=dpi;slot->bold=bold;slot->age=++v->clock;return slot;
}
static int text(View *v,const char *s,int x,int y,int size,int width,SDL_Color color,int bold) {
    CachedText *c=cached(v,s,size,width,bold);if(!c)return 0;
    SDL_SetTextureColorMod(c->texture,color.r,color.g,color.b);SDL_SetTextureAlphaMod(c->texture,color.a);
    SDL_Rect dst={x,y,c->w,c->h};SDL_RenderCopy(v->ctx.renderer,c->texture,NULL,&dst);return c->h;
}
/* Save metadata is a single line. Model annotations belong in the detail
 * line; long names are clipped with an ellipsis instead of wrapping into it. */
static void text_line(View *v,const char *s,int x,int y,int size,int width,SDL_Color color) {
    char first[512];size_t length=strcspn(s,"\r\n");
    if(length>=sizeof first){length=sizeof first-1;while(length&&((unsigned char)s[length]&0xc0)==0x80)length--;}
    memcpy(first,s,length);first[length]=0;if(!length)return;
    CachedText *c=cached(v,first,size,0,0);if(!c)return;
    if(c->w<=width){text(v,first,x,y,size,0,color,0);return;}
    CachedText *dots=cached(v,"…",size,0,0);int suffix=dots?dots->w:12;
    SDL_Rect old_clip,clip={x,y,width>suffix?width-suffix:0,c->h};
    int had_clip=SDL_RenderIsClipEnabled(v->ctx.renderer);SDL_RenderGetClipRect(v->ctx.renderer,&old_clip);
    if(had_clip)SDL_IntersectRect(&clip,&old_clip,&clip);
    SDL_RenderSetClipRect(v->ctx.renderer,&clip);text(v,first,x,y,size,0,color,0);
    SDL_RenderSetClipRect(v->ctx.renderer,had_clip?&old_clip:NULL);text(v,"…",x+width-suffix,y,size,0,color,0);
}
static int begin(View *v) {
    memset(v,0,sizeof *v);v->ctx=context;v->language=a2s.text_language;if(!v->ctx.window||!v->ctx.renderer)return 0;
    SDL_Renderer *r=v->ctx.renderer;SDL_RenderGetLogicalSize(r,&v->logicalw,&v->logicalh);
    v->clip_enabled=SDL_RenderIsClipEnabled(r);SDL_RenderGetClipRect(r,&v->clip);
    v->integer_scale=SDL_RenderGetIntegerScale(r);v->target=SDL_GetRenderTarget(r);SDL_GetRenderDrawBlendMode(r,&v->blend);
    SDL_GetRenderDrawColor(r,&v->red,&v->green,&v->blue,&v->alpha);
    SDL_SetRenderTarget(r,NULL);SDL_RenderSetIntegerScale(r,SDL_FALSE);SDL_RenderSetLogicalSize(r,960,540);
    SDL_RenderSetViewport(r,NULL);SDL_RenderSetClipRect(r,NULL);SDL_SetRenderDrawBlendMode(r,SDL_BLENDMODE_BLEND);
    if(v->ctx.logo[0]){A2TextRaster im={0};if(a2_image_raster_load(v->ctx.logo,&im)){v->logo=texture(v,&im);v->logo_w=im.width;v->logo_h=im.height;a2_text_raster_free(&im);}}
    a2_input_set_menu_active(1);a2_input_capture_cancel();v->started=SDL_GetTicks64();return 1;
}
static void end(View *v) {
    a2_input_capture_cancel();a2_input_set_menu_active(0);
    for(unsigned i=0;i<192;i++){free(v->cache[i].text);SDL_DestroyTexture(v->cache[i].texture);}SDL_DestroyTexture(v->logo);
    SDL_Renderer *r=v->ctx.renderer;SDL_SetRenderTarget(r,v->target);SDL_RenderSetLogicalSize(r,v->logicalw,v->logicalh);
    SDL_RenderSetIntegerScale(r,v->integer_scale?SDL_TRUE:SDL_FALSE);
    /* The host uses automatic logical presentation. GetScale/GetViewport
     * include computed output/DPI transforms in SDL2-compat; replaying them
     * as explicit transforms scales/offsets the next game frame again.
     * Recompute the automatic viewport, including after a window resize. */
    SDL_RenderSetViewport(r,NULL);
    SDL_RenderSetClipRect(r,v->clip_enabled?&v->clip:NULL);
    SDL_SetRenderDrawBlendMode(r,v->blend);SDL_SetRenderDrawColor(r,v->red,v->green,v->blue,v->alpha);
}
static void backdrop(View *v,int dim) {
    SDL_SetRenderDrawColor(v->ctx.renderer,0,0,0,255);SDL_RenderClear(v->ctx.renderer);
    if(v->ctx.frame&&v->ctx.fw>0&&v->ctx.fh>0){SDL_Rect source={0,0,v->ctx.fw,v->ctx.fh},dst={0,0,960,540};SDL_RenderCopy(v->ctx.renderer,v->ctx.frame,&source,&dst);}
    else for(int y=0;y<540;y+=4){int warmth=8+(270-abs(y-270))/32;fill(v,(SDL_Rect){0,y,960,4},(SDL_Color){warmth,warmth-2,warmth/2,255});}
    fill(v,(SDL_Rect){0,0,960,540},(SDL_Color){0,0,0,dim});
}
static void panel(View *v,SDL_Rect r) {
    fill(v,r,(SDL_Color){9,8,6,235});border(v,r,(SDL_Color){133,105,57,255});
    SDL_Rect inner={r.x+3,r.y+3,r.w-6,r.h-6};border(v,inner,(SDL_Color){62,48,28,255});
    for(int y=0;y<2;y++)for(int x=0;x<2;x++){
        int xx=x?r.x+r.w-15:r.x,yy=y?r.y+r.h-2:r.y;
        fill(v,(SDL_Rect){xx,yy,15,2},gold);
        fill(v,(SDL_Rect){x?r.x+r.w-2:r.x,y?r.y+r.h-15:r.y,2,15},gold);
    }
}
static void marker(View *v,int x,int y,int size) {
    for(int i=-size;i<=size;i++)fill(v,(SDL_Rect){x+abs(i),y+i,2*(size-abs(i))+1,1},gold);
}
static void base(View *v,const char *subtitle) {
    backdrop(v,105);panel(v,(SDL_Rect){44,22,872,496});
    fill(v,(SDL_Rect){49,27,862,103},(SDL_Color){0,0,0,225});
    if(v->logo){SDL_Rect dst={66,32,234,(int)(234.0*v->logo_h/v->logo_w)};SDL_RenderCopy(v->ctx.renderer,v->logo,NULL,&dst);}
    else text(v,"Alundra 2: Rebuild",70,55,28,360,gold,1);
    text(v,subtitle,430,62,25,440,white,0);
    fill(v,(SDL_Rect){68,130,824,1},(SDL_Color){95,83,61,255});
}
static void button(View *v,const char *label,SDL_Rect r,int selected,int enabled) {
    fill(v,r,selected?(SDL_Color){58,44,24,255}:(SDL_Color){19,16,11,235});
    border(v,r,selected?gold:(SDL_Color){81,65,39,255});
    if(selected)fill(v,(SDL_Rect){r.x,r.y,3,r.h},gold);
    text(v,label,r.x+12,r.y+5,16,r.w-24,enabled?(selected?gold:white):(SDL_Color){107,101,88,255},selected);
}
static void present(View *v) {
    const char *path=getenv("A2_NATIVE_UI_CAPTURE"),*profile=getenv("A2_USER_DIR");
    if(!v->captured&&profile&&*profile&&path&&*path&&SDL_GetTicks64()-v->started>=200) {
        v->captured=1;
        SDL_Surface *s=a2_render_capture_window(v->ctx.renderer);
        if(s){
            /* Capture is diagnostic only; it never supplies the frozen backdrop. */
            int ok=a2_image_raster_write_png(path,s->pixels,s->w,s->h,s->pitch/4);fprintf(stderr,"native-sdl-ui-capture: %s (PNG)\n",ok?"written":"failed");
            SDL_FreeSurface(s);
        }else fprintf(stderr,"native-sdl-ui-capture: failed: %s\n",SDL_GetError());
    }
    SDL_RenderPresent(v->ctx.renderer);SDL_Delay(8);
}
static int timed_out(View *v) {
    const char *s=getenv("A2_NATIVE_UI_AUTOCLOSE"),*profile=getenv("A2_USER_DIR");
    if(!s||!profile||!*profile)return 0;double ms=strtod(s,NULL);
    return isfinite(ms)&&ms>0&&SDL_GetTicks64()-v->started>=ms;
}
static int event(View *v,SDL_Event *e) {
    if(e->type==SDL_QUIT){v->quit=1;return 0;}
    if(e->type==SDL_WINDOWEVENT){
        if(e->window.event==SDL_WINDOWEVENT_CLOSE){v->quit=1;return 0;}
        if(e->window.event==SDL_WINDOWEVENT_FOCUS_LOST){v->lost=1;v->armed=0;a2_input_capture_cancel();}
        if(e->window.event==SDL_WINDOWEVENT_FOCUS_GAINED){v->lost=0;v->armed=0;}
    }
    a2_input_handle_event(e);
    if(e->type==SDL_KEYDOWN)a2_input_note_menu_keyboard();
    return !v->lost;
}
static uint16_t pad(View *v) {
    a2_input_poll();uint16_t down=(uint16_t)~a2_input_menu_buttons();
    if(v->lost||!v->armed){v->previous=down;if(!v->lost&&!down)v->armed=1;return 0;}
    uint16_t pressed=down&(uint16_t)~v->previous;v->previous=down;return pressed;
}
static void navigation_hint(View *v,char *out,size_t n,int controls) {
    if(a2_input_source()!=A2_INPUT_CONTROLLER){snprintf(out,n,"%s",controls?L(v,"Enter — назначить · ← → — столбец · Ctrl+Tab — раздел","Enter：割り当て · ← →：列 · Ctrl+Tab：カテゴリ","Enter: assign · ← →: column · Ctrl+Tab: category"):L(v,"↑ ↓ — выбрать · Enter — подтвердить · Esc — отмена","↑ ↓：選択 · Enter：確認 · Esc：取消","↑ ↓: choose · Enter: confirm · Esc: cancel"));return;}
    A2InputPrompt a,b,left,right;
    a2_input_binding_prompt((A2PadBinding){A2_BIND_BUTTON,SDL_CONTROLLER_BUTTON_A},&a);
    a2_input_binding_prompt((A2PadBinding){A2_BIND_BUTTON,SDL_CONTROLLER_BUTTON_B},&b);
    a2_input_binding_prompt((A2PadBinding){A2_BIND_BUTTON,SDL_CONTROLLER_BUTTON_LEFTSHOULDER},&left);
    a2_input_binding_prompt((A2PadBinding){A2_BIND_BUTTON,SDL_CONTROLLER_BUTTON_RIGHTSHOULDER},&right);
    if(controls)snprintf(out,n,L(v,"%s — назначить · %s — назад · %s / %s — раздел","%s：割り当て · %s：戻る · %s / %s：カテゴリ","%s: assign · %s: back · %s / %s: category"),a.label,b.label,left.label,right.label);
    else snprintf(out,n,L(v,"↑ ↓ — выбрать · %s — подтвердить · %s — назад","↑ ↓：選択 · %s：確認 · %s：戻る","↑ ↓: choose · %s: confirm · %s: back"),a.label,b.label);
}
static int inside(int x,int y,SDL_Rect r){return x>=r.x&&y>=r.y&&x<r.x+r.w&&y<r.y+r.h;}
static int confirm(View *v,const char *heading,const char *message,int question) {
    int selected=question?0:1,done=0,accepted=0,scroll=0;v->armed=0;
    CachedText *body=cached(v,message,19,674,0);int maximum=body&&body->h>144?body->h-144:0;
    while(!done&&!v->quit&&!timed_out(v)) {
        SDL_Event e;while(SDL_PollEvent(&e))if(event(v,&e)){
            if(e.type==SDL_KEYDOWN&&!e.key.repeat){int k=e.key.keysym.scancode;
                if(k==SDL_SCANCODE_ESCAPE||k==SDL_SCANCODE_F1){done=1;}
                else if(k==SDL_SCANCODE_LEFT||k==SDL_SCANCODE_RIGHT||k==SDL_SCANCODE_TAB)selected=!selected;
                else if(k==SDL_SCANCODE_UP||k==SDL_SCANCODE_PAGEUP)scroll-=k==SDL_SCANCODE_UP?24:120;
                else if(k==SDL_SCANCODE_DOWN||k==SDL_SCANCODE_PAGEDOWN)scroll+=k==SDL_SCANCODE_DOWN?24:120;
                else if(k==SDL_SCANCODE_RETURN||k==SDL_SCANCODE_SPACE){accepted=selected||!question;done=1;}}
            if(e.type==SDL_MOUSEWHEEL)scroll-=e.wheel.y*24;
            if(e.type==SDL_MOUSEBUTTONDOWN&&e.button.button==SDL_BUTTON_LEFT){
                if(question&&inside(e.button.x,e.button.y,(SDL_Rect){490,367,160,36})){done=1;}
                if(inside(e.button.x,e.button.y,(SDL_Rect){664,367,160,36})){accepted=1;done=1;}}
        }
        uint16_t p=pad(v);if(p&(1u<<13))done=1;if(p&((1u<<7)|(1u<<5)))selected=!selected;
        if(p&(1u<<4))scroll-=24;if(p&(1u<<6))scroll+=24;
        if(scroll<0)scroll=0;if(scroll>maximum)scroll=maximum;
        if(p&(1u<<14)){accepted=selected||!question;done=1;}
        base(v,heading);fill(v,(SDL_Rect){112,181,736,242},(SDL_Color){18,15,12,255});
        SDL_Rect message_clip={140,203,674,144};SDL_RenderSetClipRect(v->ctx.renderer,&message_clip);
        text(v,message,140,203-scroll,19,674,white,0);SDL_RenderSetClipRect(v->ctx.renderer,NULL);
        if(maximum){fill(v,(SDL_Rect){830,203,3,144},muted);fill(v,(SDL_Rect){830,203+scroll*120/maximum,3,24},gold);}
        if(question)button(v,L(v,"Отмена","キャンセル","Cancel"),(SDL_Rect){490,367,160,36},!selected,1);
        button(v,question?L(v,"Подтвердить","確認","Confirm"):L(v,"Понятно","OK","OK"),(SDL_Rect){664,367,160,36},selected||!question,1);
        present(v);
    }
    v->armed=0;return accepted;
}
static const int control_bits[]={4,6,7,5,14,13,15,12,3,0,10,11,8,9};
static const char *control_label(View *v,int row) {
    if(row<4){const char *ru[]={"Вверх","Вниз","Влево","Вправо"},*ja[]={"上","下","左","右"},*en[]={"Up","Down","Left","Right"};return loc(v->language,ru[row],ja[row],en[row]);}
    static const char *names[]={"×","○","□","△","Start","Select","L1","R1","L2","R2"};return names[row-4];
}
enum { GAME_SETTINGS=6 };
static int row_count(int tab,int startup){
#ifdef __APPLE__
    if(tab==1)return 6;
#endif
    (void)startup;return tab==0?GAME_SETTINGS:tab==1?5:tab==2?2:17;
}
static SDL_Rect close_button(int startup){(void)startup;return (SDL_Rect){686,478,186,32};}
static int row_pitch(int tab,int startup){(void)tab;(void)startup;return 36;}
static A2MenuSetting setting(int tab,int row) {
    static const A2MenuSetting game[]={A2_MENU_TEXT,A2_MENU_VOICE,A2_MENU_PORTRAITS,A2_MENU_SUBTITLES,A2_MENU_ENGLISH_SUBTITLE_LANGUAGE,A2_MENU_SKIP_INTRO};
    static const A2MenuSetting display[]={A2_MENU_DISPLAY,A2_MENU_IR,A2_MENU_FILTER,A2_MENU_CINEMA,A2_MENU_FILL_SCREEN,A2_MENU_ANTIALIAS};
    return tab==0?game[row]:tab==1?display[row]:tab==2?(row?A2_MENU_VOLUME:A2_MENU_SOUND):A2_MENU_THRESHOLD;
}
static const char *row_label(View *v,int tab,int row) {
    if(tab==0){const char *ru[]={"Язык текста","Озвучка","Портреты","Субтитры в катсценах","Субтитры английской озвучки","Пропускать заставки"};const char *ja[]={"テキスト言語","音声言語","ポートレート","カットシーンの字幕","英語音声の字幕","起動時の映像をスキップ"};const char *en[]={"Text language","Voice language","Portraits","Cutscene subtitles","English voice subtitles","Skip startup movies"};return loc(v->language,ru[row],ja[row],en[row]);}
    if(tab==1){const char *ru[]={"Окно","Разрешение отрисовки","Сглаживать текстуры","Кадр в катсценах","Заполнять экран в игре","Сглаживание краёв"};const char *ja[]={"ウィンドウ","内部解像度","テクスチャ補間","カットシーンの表示","プレイ中は画面全体に表示","アンチエイリアシング"};const char *en[]={"Window","Render resolution","Smooth textures","Cinematic framing","Fill screen in gameplay","Anti-aliasing"};return loc(v->language,ru[row],ja[row],en[row]);}
    if(tab==2)return row?L(v,"Общая громкость","マスター音量","Master volume"):L(v,"Включить звук","音声を有効にする","Enable sound");
    return row==14?L(v,"Порог стиков и триггеров","スティック・トリガーしきい値","Stick / trigger threshold"):row==15?L(v,"Сбросить клавиатуру","キーを初期化","Reset keyboard"):L(v,"Сбросить геймпад","パッドを初期化","Reset gamepad");
}
static void row_value(View *v,const A2MenuModel *m,int tab,int row,char *out,size_t n) {
    const A2Settings *s=&m->draft;const char *value="";
    if(tab==0){if(row==0)value=s->text_language==1?"日本語":s->text_language==2?"English":"Русский";
        else if(row==1)value=s->voice_language?L(v,"Английская","英語","English"):L(v,"Японская (оригинал)","日本語（オリジナル）","Japanese (original)");
        else if(row==2)value=s->hd_portraits?L(v,"HD-портреты","HDポートレート","HD portraits"):L(v,"Стандартные","オリジナル","Original");
        else if(row==3)value=s->subtitles==0?L(v,"Автоматически","自動","Automatic"):s->subtitles==1?L(v,"Вкл.","オン","On"):L(v,"Выкл.","オフ","Off");
        else if(row==4)value=s->english_subtitle_language==0?L(v,"По языку текста","テキスト言語に合わせる","Follow text language"):s->english_subtitle_language==1?"Русский":"English";
        else if(row==5)value=s->skip_intro?L(v,"Вкл.","オン","On"):L(v,"Выкл.","オフ","Off");}
    else if(tab==1){if(row==0){if(s->fullscreen)value=L(v,"Полный экран","フルスクリーン","Fullscreen");else if(!s->window_w)value=L(v,"Текущий размер","現在のサイズ","Current size");else{snprintf(out,n,"%d × %d",s->window_w,s->window_h);return;}}
        else if(row==1){snprintf(out,n,"%d×%s",s->irscale,s->irscale==1?L(v," — оригинал"," — オリジナル"," — original"):"");return;}
        else value=(row==2?s->filter:row==3?s->cinema:row==4?s->fill_screen:s->antialias)?L(v,"Вкл.","オン","On"):L(v,"Выкл.","オフ","Off");}
    else if(tab==2){if(row){snprintf(out,n,"%d%%",s->master_volume);return;}value=s->sound?L(v,"Вкл.","オン","On"):L(v,"Выкл.","オフ","Off");}
    else if(row==14){snprintf(out,n,"%d%%",(s->pad_deadzone*100+16383)/32767);return;}
    snprintf(out,n,"%s",value);
}
static void draw_menu(View *v,A2MenuModel *m,int tab,int focus,int column,int scroll,int capture) {
    base(v,L(v,"Настройки","設定","Settings"));
    const char *ru[]={"Игра","Изображение","Звук","Управление"},*ja[]={"ゲーム","画面","音声","操作"},*en[]={"Game","Display","Sound","Controls"};
    for(int i=0;i<4;i++)button(v,loc(v->language,ru[i],ja[i],en[i]),(SDL_Rect){68+i*208,140,200,34},tab==i,1);
    int count=row_count(tab,m->startup);
    if(tab==3){const A2InputDevice *dev=a2_input_device();char status[256];snprintf(status,sizeof status,"%s",dev->connected?dev->name:L(v,"Геймпад не подключён","コントローラー未接続","No gamepad connected"));
        text(v,status,80,181,13,795,muted,0);
        text(v,L(v,"Кнопка игры","ゲーム","Game button"),80,204,12,158,muted,0);
        text(v,L(v,"Клавиатура","キーボード","Keyboard"),254,204,12,180,muted,0);
        text(v,L(v,"Геймпад","コントローラー","Gamepad"),454,204,12,190,muted,0);
        text(v,L(v,"Дополнительно","追加の割り当て","Alternate"),658,204,12,190,muted,0);
        for(int i=scroll;i<count&&i<scroll+7;i++){
            int y=227+(i-scroll)*27;if(i==focus)fill(v,(SDL_Rect){74,y,798,26},(SDL_Color){42,34,23,255});
            if(i<14){text(v,control_label(v,i),84,y+3,15,150,white,0);
                for(int col=0;col<3;col++){A2InputPrompt p;if(!col)a2_input_key_prompt(m->draft.key[control_bits[i]],&p);else a2_input_binding_prompt(m->draft.pad[control_bits[i]][col-1],&p);
                    SDL_Rect r={246+col*204,y+1,196,25};if(focus==i&&column==col)border(v,r,gold);
                    text(v,capture&&focus==i&&column==col?L(v,"Нажмите…","入力…","Press…"):p.label,r.x+8,r.y+2,14,180,col&& !dev->connected?muted:white,0);}
            } else {text(v,row_label(v,3,i),84,y+3,15,470,white,0);char value[100];row_value(v,m,3,i,value,sizeof value);text(v,value,750,y+3,15,110,gold,0);}}
        if(count>7){fill(v,(SDL_Rect){882,227,3,187},(SDL_Color){67,53,34,255});fill(v,(SDL_Rect){882,227+scroll*187/count,3,7*187/count},gold);}
    } else for(int i=0;i<count;i++) {
        int y=197+i*row_pitch(tab,m->startup);int enabled=tab!=2||!i||m->draft.sound;
        SDL_Rect row={74,y,798,row_pitch(tab,m->startup)-2};if(i==focus){fill(v,row,(SDL_Color){42,34,23,255});border(v,row,gold);}
        const char *label=row_label(v,tab,i);
        int size=17,inset=7;
        text(v,label,86,y+inset,size,380,enabled?white:muted,0);char value[256];row_value(v,m,tab,i,value,sizeof value);
        text(v,value,484,y+inset,size,360,enabled?gold:muted,0);
    }
    char nav_hint[512];navigation_hint(v,nav_hint,sizeof nav_hint,tab==3);
    const char *hint;
    if(capture)hint=capture==2?L(v,"Отпустите кнопки, затем нажмите. Esc — отмена, Delete — очистить.","ボタンを離してから入力。Esc：取消、Delete：解除。","Release controls, then press. Esc cancels; Delete clears."):L(v,"Нажмите клавишу. Esc — отмена, Delete — очистить. F1/F5/F9 заняты.","キーを入力。Esc：取消、Delete：解除。F1/F5/F9は予約済み。","Press a key. Esc cancels; Delete clears. F1/F5/F9 are reserved.");
    else if(tab==3)hint=nav_hint;
    else if(tab==1)hint=L(v,"1× ↔ HD — после перезапуска. В катсценах субтитры расположены внизу кадра.","1× ↔ HD は再起動後に反映。字幕はカットシーンの下部に表示されます。","1× ↔ HD applies next launch. Subtitles appear at the bottom of cutscenes.");
    else if(tab==2)hint=L(v,"Общая громкость меняет музыку, эффекты и голоса вместе.","マスター音量は音楽・効果音・音声全体に適用されます。","Master volume changes music, effects and voices together.");
    else if(focus==4)hint=L(v,"Язык субтитров английской озвучки можно выбрать независимо от текста игры.","英語音声の字幕言語はゲームのテキストとは別に選択できます。","Choose English voice subtitles independently of the game text.");
    else hint=L(v,"Текст, озвучку и субтитры можно выбирать независимо.","テキスト・音声・字幕は個別に選択できます。","Choose text, voice and subtitles independently.");
    text(v,hint,80,424,12,800,muted,0);
    const char *status=m->startup&&!a2_menu_model_available(m)?L(v,"Выбранные данные не установлены.","選択したデータがありません。","Selected data is not installed."):a2_menu_model_restart(m)?L(v,"Язык и переход 1× ↔ HD применятся при следующем запуске.","言語と1× ↔ HDの切り替えは次回起動時に反映されます。","Language and 1× ↔ HD changes apply next launch."):L(v,"Настройки сохраняются при закрытии меню.","メニューを閉じると設定を保存します。","Settings save when the menu closes.");
    text(v,status,80,450,12,790,muted,0);
    if(tab!=3&&!capture)text(v,nav_hint,80,466,10,790,muted,0);
    button(v,L(v,"Назад","戻る","Back"),close_button(m->startup),focus==count,1);
}
static int activate(View *v,A2MenuModel *m,int tab,int focus,int column,int *capture,int *result) {
    int count=row_count(tab,m->startup);
    if(focus==count){*result=A2_MENU_RESUME;return 1;}
    if(focus<0||focus>=count)return 0;
    if(tab==3){
        if(focus<14){if(column&&!a2_input_device()->connected)return 0;*capture=column?2:1;if(column)a2_input_capture_begin();v->armed=0;}
        else if(focus==15)settings_default_keys(m->draft.key);
        else if(focus==16)a2_input_default_pad(m->draft.pad);
        else a2_menu_model_change(m,A2_MENU_THRESHOLD,1);
        return 0;
    }
    if(tab!=2||!focus||m->draft.sound)a2_menu_model_change(m,setting(tab,focus),1);return 0;
}
int a2_menu_sdl_settings(int startup,int can_save,int can_load) {
    View v;if(!begin(&v))return startup?A2_MENU_QUIT:A2_MENU_RESUME;
    unsigned texts=0,voices=0;for(int i=0;i<3;i++)if(a2_profile_available(i))texts|=1u<<i;
    for(int i=0;i<2;i++){
        char path[4096];int available=a2_profile_voice_path(i,path,sizeof path)&&a2_voice_available_for_language(path,i);
#ifdef A2_NATIVE_RESOURCES
        if(a2_profile_resources())available=a2_native_voice_available(a2_profile_resources(),i);
#endif
        if(available)voices|=1u<<i;
    }
    A2MenuModel m;a2_menu_model_init(&m,&a2s,startup,can_save,can_load,texts,voices);
    int tab=0,focus=0,column=0,scroll=0,capture=0,result=A2_MENU_RESUME,done=0;
    while(!done&&!v.quit&&!timed_out(&v)) {
        SDL_Event e;while(SDL_PollEvent(&e))if(event(&v,&e)){
            if(v.lost){capture=0;continue;}
            if(e.type==SDL_KEYDOWN&&!e.key.repeat){int k=e.key.keysym.scancode;
                if(capture){
                    if(k==SDL_SCANCODE_ESCAPE||k==SDL_SCANCODE_F1){capture=0;a2_input_capture_cancel();v.armed=0;}
                    else if(k==SDL_SCANCODE_DELETE||k==SDL_SCANCODE_BACKSPACE){
                        if(capture==1)a2_menu_model_key(&m,control_bits[focus],0);
                        else a2_menu_model_pad(&m,control_bits[focus],column-1,(A2PadBinding){0,0});
                        capture=0;a2_input_capture_cancel();v.armed=0;
                    } else if(capture==1&&!(e.key.keysym.mod&KMOD_GUI)&&a2_menu_model_key(&m,control_bits[focus],k)){capture=0;v.armed=0;}
                    continue;
                }
                int count=row_count(tab,startup),total=count+1;
                if(k==SDL_SCANCODE_ESCAPE||k==SDL_SCANCODE_F1){done=1;result=A2_MENU_RESUME;}
                else if(k==SDL_SCANCODE_TAB&&(e.key.keysym.mod&KMOD_CTRL)){tab=(tab+((e.key.keysym.mod&KMOD_SHIFT)?3:1))%4;focus=scroll=column=0;}
                else if(k==SDL_SCANCODE_UP){focus=(focus+total-1)%total;}
                else if(k==SDL_SCANCODE_DOWN){focus=(focus+1)%total;}
                else if(k==SDL_SCANCODE_TAB){int d=e.key.keysym.mod&KMOD_SHIFT?-1:1;
                    if(tab==3&&focus<14&&column+d>=0&&column+d<3)column+=d;
                    else {focus=(focus+d+total)%total;column=d<0?2:0;}}
                else if(k==SDL_SCANCODE_LEFT||k==SDL_SCANCODE_RIGHT){int d=k==SDL_SCANCODE_RIGHT?1:-1;
                    if(tab==3&&focus<14)column=(column+d+3)%3;
                    else if(focus>=count)focus=count;
                    else if(!(tab==0&&focus>=GAME_SETTINGS)&&!(tab==3&&focus>14)&&(tab!=2||!focus||m.draft.sound))a2_menu_model_change(&m,setting(tab,focus),d);
                } else if(k==SDL_SCANCODE_RETURN||k==SDL_SCANCODE_KP_ENTER||k==SDL_SCANCODE_SPACE)done=activate(&v,&m,tab,focus,column,&capture,&result);
            }
            if(e.type==SDL_MOUSEWHEEL&&!capture&&tab==3)focus=focus-e.wheel.y<0?0:focus-e.wheel.y>16?16:focus-e.wheel.y;
            if(e.type==SDL_MOUSEBUTTONDOWN&&e.button.button==SDL_BUTTON_LEFT&&!capture){
                int x=e.button.x,y=e.button.y;
                for(int i=0;i<4;i++)if(inside(x,y,(SDL_Rect){68+i*208,140,200,34})){tab=i;focus=scroll=column=0;}
                int count=row_count(tab,startup);
                if(inside(x,y,close_button(startup))){focus=count;done=activate(&v,&m,tab,focus,column,&capture,&result);}
                else if(tab==3&&inside(x,y,(SDL_Rect){74,227,798,189})){
                    int row=scroll+(y-227)/27;if(row<count){focus=row;if(row<14){if(x>=246){column=(x-246)/204;if(column>2)column=2;done=activate(&v,&m,tab,focus,column,&capture,&result);}}
                    else done=activate(&v,&m,tab,focus,column,&capture,&result);}
                } else if(tab!=3&&inside(x,y,(SDL_Rect){74,197,798,count*row_pitch(tab,startup)})){
                    focus=(y-197)/row_pitch(tab,startup);done=activate(&v,&m,tab,focus,column,&capture,&result);
                }
            }
        }
        if(v.lost&&capture){capture=0;a2_input_capture_cancel();}
        if(capture){
            a2_input_poll();v.armed=0;
            if(capture==2){A2PadBinding binding;if(!a2_input_device()->connected){capture=0;a2_input_capture_cancel();}
                else if(a2_input_capture_poll(&binding)){a2_menu_model_pad(&m,control_bits[focus],column-1,binding);capture=0;a2_input_capture_cancel();}}
        } else {
            uint16_t p=pad(&v);int count=row_count(tab,startup),total=count+1;
            if(p&(1u<<13)){done=1;result=A2_MENU_RESUME;}
            else if(p&(1u<<3)){if(!startup||a2_menu_model_available(&m)){done=1;result=A2_MENU_RESUME;}}
            if(p&((1u<<10)|(1u<<11))){tab=(tab+((p&(1u<<11))?1:3))%4;focus=scroll=column=0;}
            else if(p&(1u<<4))focus=(focus+total-1)%total;
            else if(p&(1u<<6))focus=(focus+1)%total;
            else if(p&((1u<<7)|(1u<<5))){int d=p&(1u<<5)?1:-1;
                if(tab==3&&focus<14)column=(column+d+3)%3;
                else if(focus>=count)focus=count;
                else if(!(tab==0&&focus>=GAME_SETTINGS)&&!(tab==3&&focus>14)&&(tab!=2||!focus||m.draft.sound))a2_menu_model_change(&m,setting(tab,focus),d);
            }
            if(p&(1u<<14))done=activate(&v,&m,tab,focus,column,&capture,&result);
        }
        if(tab==3&&focus<17){if(focus<scroll)scroll=focus;if(focus>=scroll+7)scroll=focus-6;}
        draw_menu(&v,&m,tab,focus,column,scroll,capture);present(&v);
    }
    if(v.quit)result=A2_MENU_QUIT;
    a2_menu_model_finish(&m,result,&a2s);end(&v);return result;
}
static SDL_Rect hub_row(int startup,int index) {
    return (SDL_Rect){startup?320:88,228+42*index,312,38};
}
static int hub_enabled(int startup,int index,int save,int load,int available) {
    if(startup)return index==0?available:index==1?load&&available:1;
    return index==1?save:index==2?load:1;
}
static int selected_profile_available(void) {
    char path[4096];int voice=a2_profile_voice_path(a2s.voice_language,path,sizeof path)&&a2_voice_available_for_language(path,a2s.voice_language);
#ifdef A2_NATIVE_RESOURCES
    if(a2_profile_resources())voice=a2_native_voice_available(a2_profile_resources(),a2s.voice_language);
#endif
    return a2_profile_available(a2s.text_language)&&voice;
}
static void draw_hub(View *v,int startup,int focus,int save,int load,int available) {
    backdrop(v,startup?0:65);int x=startup?288:56;
    panel(v,(SDL_Rect){x,32,376,476});
    if(v->logo){SDL_Rect dst={x+65,54,246,(int)(246.0*v->logo_h/v->logo_w)};SDL_RenderCopy(v->ctx.renderer,v->logo,NULL,&dst);}
    else text(v,"Alundra 2",x+40,84,30,296,gold,0);
    fill(v,(SDL_Rect){x+32,170,312,1},(SDL_Color){107,84,45,255});
    text(v,startup?L(v,"Начало приключения","冒険の始まり","Your adventure"):L(v,"Пауза","一時停止","Paused"),x+32,184,26,318,white,0);
    const char *ru[]={"Продолжить","Сохранить игру","Загрузить игру","Настройки","Выйти из игры"};
    const char *ja[]={"再開","ゲームを保存","ゲームをロード","設定","ゲームを終了"};
    const char *en[]={"Resume","Save game","Load game","Settings","Quit game"};
    int count=startup?4:5;
    for(int i=0;i<count;i++){
        int entry=startup&&i?i+1:i;SDL_Rect row=hub_row(startup,i);
        int enabled=hub_enabled(startup,i,save,load,available);
        if(i==focus){fill(v,row,(SDL_Color){54,40,21,240});fill(v,(SDL_Rect){row.x,row.y+row.h-1,row.w,1},(SDL_Color){135,105,56,255});marker(v,row.x+8,row.y+18,4);}
        text(v,startup&&!i?L(v,"Играть","ゲームを始める","Play"):loc(v->language,ru[entry],ja[entry],en[entry]),row.x+29,row.y+6,20,row.w-36,enabled?(focus==i?gold:white):muted,0);
    }
    const char *hint=NULL;char navigation[512];
    if(!hub_enabled(startup,focus,save,load,available))hint=startup?L(v,"Выберите доступные языки в настройках.","設定で利用可能な言語を選んでください。","Choose installed languages in Settings."):L(v,"Доступно после возвращения к обычной игре.","通常のプレイ中に利用できます。","Available during ordinary gameplay.");
    else {navigation_hint(v,navigation,sizeof navigation,0);hint=navigation;}
    text(v,hint,x+32,455,11,312,muted,0);
}
int a2_menu_sdl_game(int startup,int can_save,int can_load) {
    View v;if(!begin(&v))return startup?A2_MENU_QUIT:A2_MENU_RESUME;
    int focus=0,count=startup?4:5,available=selected_profile_available(),done=0,result=startup?A2_MENU_QUIT:A2_MENU_RESUME;
    while(!done&&!v.quit&&!timed_out(&v)){
        int accept=-1;SDL_Event e;
        while(SDL_PollEvent(&e))if(event(&v,&e)){
            if(e.type==SDL_KEYDOWN&&!e.key.repeat){int key=e.key.keysym.scancode;
                if(key==SDL_SCANCODE_ESCAPE||key==SDL_SCANCODE_F1){if(!startup)done=1;else focus=count-1;}
                else if(key==SDL_SCANCODE_DOWN||key==SDL_SCANCODE_TAB)focus=(focus+1)%count;
                else if(key==SDL_SCANCODE_UP)focus=(focus+count-1)%count;
                else if(key==SDL_SCANCODE_RETURN||key==SDL_SCANCODE_KP_ENTER||key==SDL_SCANCODE_SPACE){if(accept<0)accept=focus;}
            }
            if(e.type==SDL_MOUSEMOTION)for(int i=0;i<count;i++)if(inside(e.motion.x,e.motion.y,hub_row(startup,i)))focus=i;
            if(e.type==SDL_MOUSEBUTTONDOWN&&e.button.button==SDL_BUTTON_LEFT)for(int i=0;i<count;i++)if(inside(e.button.x,e.button.y,hub_row(startup,i))){focus=i;if(accept<0)accept=i;}
        }
        uint16_t p=pad(&v);
        if(p&(1u<<13)){if(!startup)done=1;else focus=count-1;}
        if(accept<0&&p&(1u<<3)){if(!startup)done=1;else {focus=0;accept=0;}}
        if(accept<0&&p&(1u<<4))focus=(focus+count-1)%count;
        if(accept<0&&p&(1u<<6))focus=(focus+1)%count;
        if(accept<0&&p&(1u<<14))accept=focus;
        if(accept>=0)focus=accept;
        if(accept>=0&&!done&&hub_enabled(startup,focus,can_save,can_load,available)){
            if(focus==count-2){
                int action=a2_menu_sdl_settings(startup,can_save,can_load);
                if(action==A2_MENU_QUIT){result=action;done=1;}
                v.language=a2s.text_language;v.armed=0;a2_input_set_menu_active(1);available=selected_profile_available();
            }else if(focus==count-1){
                if(startup||confirm(&v,L(&v,"Выйти из игры?","ゲームを終了？","Quit game?"),L(&v,"Несохранённый прогресс будет потерян.","保存していない進行状況は失われます。","Unsaved progress will be lost."),1)){result=A2_MENU_QUIT;done=1;}
            }else {result=focus==0?A2_MENU_RESUME:startup?A2_MENU_LOAD:focus==1?A2_MENU_SAVE_SLOT:A2_MENU_LOAD_SLOT;done=1;}
        }
        draw_hub(&v,startup,focus,can_save,can_load,available);present(&v);
    }
    if(v.quit)result=A2_MENU_QUIT;end(&v);return result;
}
static void error_message(View *v,const char *message) {
    char localized[2048];a2_save_browser_error_text(message,v->language,localized,sizeof localized);
    confirm(v,a2_save_browser_durability_warning(message)?L(v,"Сохранение записано","保存しました","Save created"):L(v,"Действие с сохранением","保存データの操作","Save operation"),localized,0);
}
void a2_menu_sdl_error(const char *message) {
    View v;if(!begin(&v)){fprintf(stderr,"menu: %s\n",message?message:"");return;}
    error_message(&v,message);int quit=v.quit;end(&v);if(quit){SDL_Event e={0};e.type=SDL_QUIT;SDL_PushEvent(&e);}
}
static void draw_saves(View *v,A2SaveBrowser *b,int selected,int scroll) {
    base(v,b->saving?L(v,"Сохранить игру","ゲームを保存","Save game"):L(v,"Загрузить игру","ゲームをロード","Load game"));
    text(v,b->count?(b->saving?L(v,"Создайте новое сохранение или выберите, какое заменить.","新しく保存するか、上書きするデータを選んでください。","Create a new save or choose one to replace."):L(v,"Выберите сохранение, чтобы продолжить игру.","続ける保存データを選んでください。","Choose a save to continue your adventure.")):L(v,"Сохранений пока нет. Выберите «Сохранить игру» в меню паузы.","保存データはありません。ポーズメニューで「ゲームを保存」を選んでください。","No saves yet. Choose Save game in the pause menu."),80,149,16,800,muted,0);
    text(v,L(v,"Место","場所","Location"),88,191,13,340,gold,0);
    text(v,L(v,"Дата","日時","Date"),445,191,13,250,gold,0);
    text(v,L(v,"Время в игре","プレイ時間","Play time"),726,191,13,150,gold,0);
    for(int i=scroll;i<(int)b->count&&i<scroll+4;i++){
        A2SaveBrowserRow *row=b->rows+i;int y=216+(i-scroll)*54;
        fill(v,(SDL_Rect){74,y,798,50},i==selected?(SDL_Color){54,40,21,255}:(SDL_Color){20,17,12,255});
        if(i==selected)border(v,(SDL_Rect){74,y,798,50},gold);
        char title[256],date[256],time[64];a2_save_browser_title(row,v->language,title,sizeof title);a2_save_browser_date(row,v->language,date,sizeof date);a2_save_browser_playtime(row,v->language,time,sizeof time);
        char number[24];snprintf(number,sizeof number,row->fresh?"+":"%02d",i+!b->saving);
        border(v,(SDL_Rect){86,y+10,30,30},(SDL_Color){124,96,48,255});text(v,number,91,y+15,14,24,gold,0);
        text_line(v,title,132,y+4,16,298,row->valid?white:muted);text_line(v,row->fresh?"—":date,445,y+5,14,260,muted);text(v,time,728,y+5,16,140,gold,0);
        const char *detail=row->fresh?L(v,"Не заменяет другие сохранения","ほかの保存データは残ります","Keeps your other saves"):!row->valid?L(v,"Не удалось прочитать","読み取れません","Unavailable"):row->imported?L(v,"Сохранение с карты памяти","メモリーカードの保存","Memory card save"):L(v,"Сохранённый прогресс","保存した進行状況","Saved progress");
        text(v,detail,132,y+28,11,298,muted,0);
    }
    if(b->count>4){fill(v,(SDL_Rect){882,216,3,212},(SDL_Color){67,53,34,255});fill(v,(SDL_Rect){882,216+(int)(scroll*212/b->count),3,(int)(4*212/b->count)},gold);}
    char navigation[512];navigation_hint(v,navigation,sizeof navigation,0);text(v,navigation,80,450,13,790,muted,0);
    button(v,L(v,"Отмена","キャンセル","Cancel"),(SDL_Rect){492,478,180,32},selected==(int)b->count,1);
    button(v,b->saving?L(v,"Сохранить","保存","Save"):L(v,"Загрузить","ロード","Load"),(SDL_Rect){686,478,186,32},selected==(int)b->count+1,b->count!=0);
}
int a2_menu_sdl_save_browser(const char *userdir,int saving,uint8_t payload[8192],char *error,size_t size) {
    if(error&&size)error[0]=0;View v;if(!begin(&v))return 0;
    A2SaveBrowser b={0};int result=0,done=0,selected=0,chosen=0,scroll=0;
    if(!a2_save_browser_open(&b,userdir,saving,error,size)){end(&v);return 0;}
    if(b.import_result!=A2_SAVE_OK&&b.import_warning[0])error_message(&v,b.import_warning);
    while(!done&&!v.quit&&!timed_out(&v)){
        int accept=0;SDL_Event e;while(SDL_PollEvent(&e))if(event(&v,&e)){
            if(e.type==SDL_KEYDOWN&&!e.key.repeat){int k=e.key.keysym.scancode;
                if(k==SDL_SCANCODE_ESCAPE||k==SDL_SCANCODE_F1)done=1;
                else if(k==SDL_SCANCODE_UP)selected=(selected+(int)b.count+1)%((int)b.count+2);
                else if(k==SDL_SCANCODE_DOWN||k==SDL_SCANCODE_TAB)selected=(selected+1)%((int)b.count+2);
                else if(k==SDL_SCANCODE_LEFT||k==SDL_SCANCODE_RIGHT){if(selected>=(int)b.count)selected=(int)b.count+(selected==(int)b.count);}
                else if(k==SDL_SCANCODE_RETURN||k==SDL_SCANCODE_KP_ENTER||k==SDL_SCANCODE_SPACE){if(selected==(int)b.count)done=1;else accept=1;}}
            if(e.type==SDL_MOUSEWHEEL){selected-=e.wheel.y;if(selected<0)selected=0;if(selected>=(int)b.count)selected=b.count?((int)b.count-1):0;}
            if(e.type==SDL_MOUSEBUTTONDOWN&&e.button.button==SDL_BUTTON_LEFT){int x=e.button.x,y=e.button.y;
                if(inside(x,y,(SDL_Rect){74,216,798,216})){int row=scroll+(y-216)/54;if(row<(int)b.count){selected=row;if(e.button.clicks>=2)accept=1;}}
                if(inside(x,y,(SDL_Rect){492,478,180,32}))done=1;
                if(inside(x,y,(SDL_Rect){686,478,186,32}))accept=1;}
        }
        uint16_t p=pad(&v);if(p&(1u<<13))done=1;if(p&(1u<<4))selected=(selected+(int)b.count+1)%((int)b.count+2);
        if(p&(1u<<6))selected=(selected+1)%((int)b.count+2);if(p&((1u<<7)|(1u<<5))&&selected>=(int)b.count)selected=(int)b.count+(selected==(int)b.count);
        if(p&(1u<<14)){if(selected==(int)b.count)done=1;else accept=1;}
        if(selected<(int)b.count){chosen=selected;if(selected<scroll)scroll=selected;if(selected>=scroll+4)scroll=selected-3;}
        if(accept&&!done&&b.count){A2SaveBrowserRow *row=b.rows+chosen;int authorized=1;
            if(saving&&row->valid&&!row->fresh){char title[256],question[768];a2_save_browser_title(row,v.language,title,sizeof title);
                snprintf(question,sizeof question,row->imported?L(&v,"%s\nСоздать отдельную копию? Прежнее сохранение останется без изменений.","%s\n別のコピーを作成しますか？以前の保存データは変更しません。","%s\nCreate a separate copy? The previous save will remain unchanged."):L(&v,"%s\nЗаменить это сохранение текущим прогрессом?", "%s\n現在の進行状況で上書きしますか？","%s\nReplace this save with your current progress?"),title);
                authorized=confirm(&v,row->imported?L(&v,"Сохранить копию?","コピーを保存？","Save a copy?"):L(&v,"Заменить сохранение?","上書きしますか？","Replace save?"),question,1);
            }
            if(authorized&&!v.quit){result=a2_save_browser_accept(&b,(size_t)chosen,payload,error,size);
                if(result){/* Guest commits first and presents result 2 warning once. */done=1;}
                else error_message(&v,error);}
        }
        draw_saves(&v,&b,selected,scroll);present(&v);
    }
    if(!result&&error&&size)error[0]=0;
    a2_save_browser_dispose(&b);int quit=v.quit;end(&v);if(quit){SDL_Event e={0};e.type=SDL_QUIT;SDL_PushEvent(&e);}return result;
}
