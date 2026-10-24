#define _POSIX_C_SOURCE 200809L
#ifdef __APPLE__
#define _DARWIN_C_SOURCE
#endif
#include "menu_sdl.h"
#include "settings.h"
#include "game_profiles.h"
#include "voice_assets.h"
#include "save_browser_model.h"
#include "text_raster.h"
#include <assert.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
A2Settings a2s;
void settings_default_keys(int out[16]) { memset(out,0,sizeof(int)*16);out[14]=SDL_SCANCODE_X; }
int a2_profile_available(int language){return language>=0&&language<3;}
const char *a2_profile_reason(int language){(void)language;return "";}
int a2_profile_voice_path(int language,char *out,size_t size){(void)language;snprintf(out,size,"fixture");return 1;}
int a2_voice_available_for_language(const char *path,int language){(void)path;(void)language;return 1;}
static const char *mode="display";
static SDL_Joystick *joystick;
static SDL_Window *window;
static SDL_Renderer *pointer_renderer;
static int physical_pointer(void){return strstr(mode,"physical")!=NULL;}
static int viewport_test(void) { return !strncmp(mode,"viewport",8); }
/* The next game frame must survive a modal round trip, not just the queried
 * logical dimensions. This catches effective scale being applied twice. */
static SDL_Surface *game_frame(SDL_Renderer *r,SDL_Texture *frame) {
    int w,h;assert(!SDL_GetRendererOutputSize(r,&w,&h));
    SDL_Surface *s=SDL_CreateRGBSurfaceWithFormat(0,w,h,32,SDL_PIXELFORMAT_ARGB8888);assert(s);
    assert(!SDL_SetRenderDrawColor(r,0,0,0,255));assert(!SDL_RenderClear(r));
    assert(!SDL_RenderCopy(r,frame,NULL,NULL));
    assert(!SDL_RenderFlush(r));
    /* Read the already drawn pixels in physical coordinates. A corrupt
     * viewport must not turn the diagnostic itself into an out-of-bounds
     * SDL2-compat readback. Nothing is redrawn after this normalization. */
    int lw,lh;SDL_RenderGetLogicalSize(r,&lw,&lh);
    assert(!SDL_RenderSetLogicalSize(r,0,0));assert(!SDL_RenderSetScale(r,1,1));
    assert(!SDL_RenderSetViewport(r,NULL));
    SDL_Rect bounds={0,0,w,h};
    int read_result=SDL_RenderReadPixels(r,&bounds,SDL_PIXELFORMAT_ARGB8888,s->pixels,s->pitch);
    if(read_result)fprintf(stderr,"frame capture failed: %s\n",SDL_GetError());
    assert(!read_result);
    assert(!SDL_RenderSetLogicalSize(r,lw,lh));assert(!SDL_RenderSetViewport(r,NULL));
    return s;
}
static void click(int x,int y) { SDL_Event e={0};e.type=SDL_MOUSEBUTTONDOWN;e.button.button=SDL_BUTTON_LEFT;e.button.x=x;e.button.y=y;
    if(physical_pointer()){SDL_RenderLogicalToWindow(pointer_renderer,(float)x,(float)y,&e.button.x,&e.button.y);e.button.windowID=SDL_GetWindowID(window);}
    assert(SDL_PushEvent(&e)==1);SDL_Delay(60); }
static void key(SDL_Scancode sc) { SDL_Event e={0};e.type=SDL_KEYDOWN;e.key.keysym.scancode=sc;e.key.keysym.sym=SDL_GetKeyFromScancode(sc);assert(SDL_PushEvent(&e)==1);SDL_Delay(50); }
static void pulse(int b) { assert(!SDL_JoystickSetVirtualButton(joystick,b,1));SDL_Delay(65);assert(!SDL_JoystickSetVirtualButton(joystick,b,0));SDL_Delay(65); }
static int input_thread(void *unused) {
    (void)unused;SDL_Delay(100);
    if(!strncmp(mode,"hub-",4)){
        SDL_Delay(200);
        if(!strcmp(mode,"hub-event-batch")){ /* queued before opening the view */ }
        else if(!strcmp(mode,"hub-pad-save")){
            assert(!SDL_JoystickSetVirtualButton(joystick,SDL_CONTROLLER_BUTTON_A,0));SDL_Delay(100);
            pulse(SDL_CONTROLLER_BUTTON_DPAD_DOWN);pulse(SDL_CONTROLLER_BUTTON_A);
        }else if(!strcmp(mode,"hub-physical-load"))click(210,330);
        else if(!strcmp(mode,"hub-settings")){
            for(int i=0;i<3;i++)key(SDL_SCANCODE_DOWN);key(SDL_SCANCODE_RETURN);
            click(375,150);key(SDL_SCANCODE_DOWN);key(SDL_SCANCODE_DOWN);key(SDL_SCANCODE_RIGHT);
            key(SDL_SCANCODE_ESCAPE);key(SDL_SCANCODE_ESCAPE);
        }else if(!strcmp(mode,"hub-quit-cancel")){
            key(SDL_SCANCODE_UP);key(SDL_SCANCODE_RETURN);key(SDL_SCANCODE_ESCAPE);key(SDL_SCANCODE_ESCAPE);
        }else {
            int down=!strcmp(mode,"hub-save")||!strcmp(mode,"hub-disabled-save")?1:!strcmp(mode,"hub-load")?2:!strcmp(mode,"hub-startup-load")?1:0;
            for(int i=0;i<down;i++)key(SDL_SCANCODE_DOWN);key(SDL_SCANCODE_RETURN);
            if(!strcmp(mode,"hub-disabled-save"))key(SDL_SCANCODE_ESCAPE);
        }
    }
    else if(!strcmp(mode,"viewport-startup")){key(SDL_SCANCODE_ESCAPE);}
    else if(viewport_test()){key(SDL_SCANCODE_ESCAPE);}
    else if(!strcmp(mode,"menu-save"))click(200,378);
    else if(!strcmp(mode,"menu-load"))click(200,406);
    else if(!strncmp(mode,"english-subtitles",17)){
        if(strstr(mode,"mouse")){click(740,349);click(740,349);}
        else if(strstr(mode,"pad")){
            assert(!SDL_JoystickSetVirtualButton(joystick,SDL_CONTROLLER_BUTTON_A,0));SDL_Delay(100);
            for(int i=0;i<4;i++)pulse(SDL_CONTROLLER_BUTTON_DPAD_DOWN);
            pulse(SDL_CONTROLLER_BUTTON_DPAD_RIGHT);pulse(SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
            pulse(SDL_CONTROLLER_BUTTON_START);return 0;
        } else {
            for(int i=0;i<4;i++)key(SDL_SCANCODE_DOWN);
            key(SDL_SCANCODE_RIGHT);key(SDL_SCANCODE_RIGHT);
        }
        SDL_Delay(150);
        if(strstr(mode,"startup"))click(760,493);else key(SDL_SCANCODE_ESCAPE);
    }
    else if(!strcmp(mode,"startup-load")){key(SDL_SCANCODE_UP);key(SDL_SCANCODE_LEFT);key(SDL_SCANCODE_RETURN);}
    else if(!strcmp(mode,"startup-load-pad")){
        assert(!SDL_JoystickSetVirtualButton(joystick,SDL_CONTROLLER_BUTTON_A,0));SDL_Delay(100);
        pulse(SDL_CONTROLLER_BUTTON_RIGHTSHOULDER);pulse(SDL_CONTROLLER_BUTTON_DPAD_UP);
        pulse(SDL_CONTROLLER_BUTTON_DPAD_LEFT);pulse(SDL_CONTROLLER_BUTTON_A);
    }
    else if(!strcmp(mode,"startup-load-physical")){click(505,150);click(550,493);}
    else if(!strncmp(mode,"startup-load-mouse",18)){
        int tab=mode[18]?atoi(mode+18):0;click(150+208*tab,150);click(550,493);
    }
    else if(!strncmp(mode,"no-models",9)){
        if(!strcmp(mode,"no-models-mouse"))click(740,378);
        else {
            int count=!strcmp(mode,"no-models-startup")?8:6;
            for(int i=0;i<count;i++)key(SDL_SCANCODE_DOWN);
            key(SDL_SCANCODE_RETURN);
        }
    }
    else if(!strcmp(mode,"display")){click(375,150);click(760,279);SDL_Delay(120);key(SDL_SCANCODE_ESCAPE);}
    else if(!strcmp(mode,"controls")){click(750,150);SDL_Delay(250);key(SDL_SCANCODE_ESCAPE);}
    else if(!strcmp(mode,"keys")){
        click(750,150);click(290,235);key(SDL_SCANCODE_F5);key(SDL_SCANCODE_C);
        click(290,260);key(SDL_SCANCODE_BACKSPACE);key(SDL_SCANCODE_ESCAPE);
    } else if(!strcmp(mode,"pad")){
        assert(!SDL_JoystickSetVirtualButton(joystick,SDL_CONTROLLER_BUTTON_B,0));SDL_Delay(80);
        pulse(SDL_CONTROLLER_BUTTON_RIGHTSHOULDER);pulse(SDL_CONTROLLER_BUTTON_DPAD_DOWN);pulse(SDL_CONTROLLER_BUTTON_DPAD_DOWN);
        pulse(SDL_CONTROLLER_BUTTON_A);pulse(SDL_CONTROLLER_BUTTON_START);
    } else if(!strcmp(mode,"padcapture")){
        click(750,150);click(700,235);SDL_Delay(120);
        assert(!SDL_JoystickSetVirtualButton(joystick,SDL_CONTROLLER_BUTTON_A,0));SDL_Delay(80);
        pulse(SDL_CONTROLLER_BUTTON_Y);pulse(SDL_CONTROLLER_BUTTON_START);
    } else if(!strcmp(mode,"resize")){
        SDL_SetWindowSize(window,1280,720);SDL_Delay(180);key(SDL_SCANCODE_ESCAPE);
    } else if(!strcmp(mode,"overwrite-cancel")){key(SDL_SCANCODE_DOWN);key(SDL_SCANCODE_RETURN);key(SDL_SCANCODE_ESCAPE);key(SDL_SCANCODE_ESCAPE);}
    else if(!strcmp(mode,"save")||!strcmp(mode,"load")){SDL_Delay(200);key(SDL_SCANCODE_RETURN);}
    else if(!strcmp(mode,"error")||!strcmp(mode,"longerror")){SDL_Delay(200);key(SDL_SCANCODE_RETURN);}
    else if(!strcmp(mode,"errorscroll")){for(int i=0;i<8;i++)key(SDL_SCANCODE_DOWN);key(SDL_SCANCODE_RETURN);}
    else {SDL_Delay(200);key(SDL_SCANCODE_ESCAPE);}
    return 0;
}
static void payload(uint8_t out[8192]) {
    memset(out,0,8192);memcpy(out,"SC\x11\x01",4);out[0xc14]=14;out[4]=17;
    unsigned check=0x4472+17;out[0xd8c]=check;out[0xd8d]=check>>8;out[8191]=0x71;
}
static void cleanup(const char *path) {
    struct stat st;assert(!lstat(path,&st));if(!S_ISDIR(st.st_mode)){assert(!unlink(path));return;}
    DIR *d=opendir(path);assert(d);struct dirent *e;while((e=readdir(d))){if(!strcmp(e->d_name,".")||!strcmp(e->d_name,".."))continue;char p[4096];assert(snprintf(p,sizeof p,"%s/%s",path,e->d_name)<(int)sizeof p);cleanup(p);}assert(!closedir(d));assert(!rmdir(path));
}
int main(int argc,char **argv) {
    if(argc>3)mode=argv[3];if(argc>1&&strcmp(argv[1],"-"))setenv("A2_NATIVE_UI_CAPTURE",argv[1],1);
    char private_dir[]="/tmp/a2-menu-sdl.XXXXXX";assert(mkdtemp(private_dir));setenv("A2_USER_DIR",private_dir,1);setenv("A2_NATIVE_UI_AUTOCLOSE","2500",1);
    SDL_SetHint(SDL_HINT_RENDER_DRIVER,"software");SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI,"0");SDL_SetHint(SDL_HINT_JOYSTICK_IOKIT,"0");SDL_SetHint(SDL_HINT_JOYSTICK_MFI,"0");SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS,"1");
    assert(!SDL_Init(SDL_INIT_VIDEO|SDL_INIT_GAMECONTROLLER));
    int windoww=physical_pointer()?1280:viewport_test()?(argc>5?atoi(argv[5]):1512):960;
    int windowh=physical_pointer()?720:viewport_test()?(argc>6?atoi(argv[6]):982):540;
    window=SDL_CreateWindow("SDL menu fixture",0,0,windoww,windowh,SDL_WINDOW_HIDDEN|SDL_WINDOW_RESIZABLE|SDL_WINDOW_ALLOW_HIGHDPI);assert(window);
    SDL_Renderer *r=SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);assert(r);pointer_renderer=r;
    SDL_Texture *frame=SDL_CreateTexture(r,SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STATIC,2,2);assert(frame);
    uint32_t bg[]={0xff305040,0xffa02030,0xff2040a0,0xffd0b040};SDL_UpdateTexture(frame,NULL,bg,8);
    int logicalw=viewport_test()?960:640,logicalh=viewport_test()?540:480;
    SDL_RenderSetLogicalSize(r,logicalw,logicalh);
    SDL_Surface *before=viewport_test()?game_frame(r,frame):NULL;
    SDL_SetRenderDrawBlendMode(r,SDL_BLENDMODE_ADD);SDL_SetRenderDrawColor(r,1,2,3,4);
    a2s.hd_models=1;
    a2s.irscale=4;a2s.wide=1;a2s.sound=1;a2s.master_volume=100;a2s.pad_deadzone=16384;a2s.text_language=argc>4?atoi(argv[4]):0;
    if(!strncmp(mode,"english-subtitles",17))a2s.voice_language=1;
    a2s.key[14]=SDL_SCANCODE_X;a2s.key[13]=SDL_SCANCODE_C;a2s.key[6]=SDL_SCANCODE_D;
    a2_input_init();a2_input_configure(a2s.key,a2s.pad,a2s.pad_deadzone);
    int virtual_index=-1;
    if(!strcmp(mode,"pad")||!strcmp(mode,"padcapture")||!strcmp(mode,"startup-load-pad")||!strcmp(mode,"english-subtitles-pad")||!strcmp(mode,"hub-pad-save")){
        SDL_VirtualJoystickDesc d={0};d.version=SDL_VIRTUAL_JOYSTICK_DESC_VERSION;d.type=SDL_JOYSTICK_TYPE_GAMECONTROLLER;
        d.naxes=SDL_CONTROLLER_AXIS_MAX;d.nbuttons=SDL_CONTROLLER_BUTTON_MAX;d.name="Owned menu controller";
        d.button_mask=(1u<<SDL_CONTROLLER_BUTTON_MAX)-1;d.axis_mask=(1u<<SDL_CONTROLLER_AXIS_MAX)-1;
        virtual_index=SDL_JoystickAttachVirtualEx(&d);assert(virtual_index>=0);joystick=SDL_JoystickOpen(virtual_index);assert(joystick);
        assert(!SDL_JoystickSetVirtualAxis(joystick,SDL_CONTROLLER_AXIS_TRIGGERLEFT,-32768));assert(!SDL_JoystickSetVirtualAxis(joystick,SDL_CONTROLLER_AXIS_TRIGGERRIGHT,-32768));
        SDL_PumpEvents();a2_input_poll();assert(a2_input_device()->connected);
        assert(!SDL_JoystickSetVirtualButton(joystick,!strcmp(mode,"pad")?SDL_CONTROLLER_BUTTON_B:SDL_CONTROLLER_BUTTON_A,1));SDL_PumpEvents();a2_input_poll();
    }
    uint8_t data[8192],expected[8192];payload(data);memcpy(expected,data,sizeof data);char error[1024]={0};
    if(!strcmp(mode,"load")||!strcmp(mode,"overwrite-cancel")){A2SaveBrowser b={0};assert(a2_save_browser_open(&b,private_dir,1,error,sizeof error));assert(a2_save_browser_accept(&b,0,data,error,sizeof error)==1);a2_save_browser_dispose(&b);if(!strcmp(mode,"load"))memset(data,0x5a,sizeof data);else {data[8191]=0x45;memcpy(expected,data,sizeof data);}}
    if(!strcmp(mode,"imported")){
        uint8_t *card=calloc(131072,1);assert(card);memcpy(card,"MC",2);card[127]='M'^'C';
        uint8_t *entry=card+128;entry[0]=0x51;entry[5]=0x20;entry[8]=entry[9]=0xff;
        memcpy(entry+10,"BISCPS-1011500",14);for(unsigned i=0;i<127;i++)entry[127]^=entry[i];
        payload(card+8192);char path[1024];snprintf(path,sizeof path,"%s/memcard1.mcr",private_dir);
        FILE *f=fopen(path,"wb");assert(f);assert(fwrite(card,1,131072,f)==131072);assert(!fclose(f));free(card);
    }
    a2_menu_sdl_set_context(window,r,frame,2,2,argc>2?argv[2]:NULL);
    if(!strcmp(mode,"hub-event-batch")){
        SDL_PumpEvents();SDL_FlushEvents(SDL_FIRSTEVENT,SDL_LASTEVENT);
        SDL_Event events[3]={{0}};events[0].type=events[1].type=SDL_KEYDOWN;
        events[0].key.keysym.scancode=SDL_SCANCODE_DOWN;events[1].key.keysym.scancode=SDL_SCANCODE_RETURN;
        events[2].type=SDL_MOUSEMOTION;events[2].motion.x=100;events[2].motion.y=240;
        assert(SDL_PeepEvents(events,3,SDL_ADDEVENT,SDL_FIRSTEVENT,SDL_LASTEVENT)==3);
    }
    SDL_Thread *thread=SDL_CreateThread(input_thread,"fixture-input",NULL);assert(thread);int result;
    if(!strcmp(mode,"save")||!strcmp(mode,"load")||!strcmp(mode,"cancel")||!strcmp(mode,"imported")||!strcmp(mode,"overwrite-cancel")){
        result=a2_menu_sdl_save_browser(private_dir,strcmp(mode,"load")!=0,data,error,sizeof error);
        if(!strcmp(mode,"cancel")||!strcmp(mode,"imported")||!strcmp(mode,"overwrite-cancel")){assert(!result);assert(!memcmp(data,expected,sizeof data));assert(!error[0]);
            if(!strcmp(mode,"overwrite-cancel")){
                A2SaveBrowser b={0};assert(a2_save_browser_open(&b,private_dir,0,error,sizeof error));assert(b.count==1);
                uint8_t got[8192],original[8192];payload(original);assert(a2_save_browser_accept(&b,0,got,error,sizeof error)==1);
                assert(!memcmp(got,original,sizeof got));a2_save_browser_dispose(&b);
            }}
        else {assert(result==1);assert(!memcmp(data,expected,sizeof data));A2SaveBrowser b={0};assert(a2_save_browser_open(&b,private_dir,0,error,sizeof error));assert(b.count==1);uint8_t got[8192];assert(a2_save_browser_accept(&b,0,got,error,sizeof error)==1);assert(!memcmp(got,expected,sizeof got));a2_save_browser_dispose(&b);}
    } else if(!strcmp(mode,"error")||!strcmp(mode,"longerror")||!strcmp(mode,"errorscroll")||!strcmp(mode,"viewport-error")){
        char long_message[1800]={0};for(int i=0;i<20;i++)strcat(long_message,"Long storage diagnostic with a deeply nested save directory and full error detail. ");
        a2_menu_sdl_error(!strcmp(mode,"error")?"Файл сохранения повреждён.":long_message);result=0;
    }
    else if(!strcmp(mode,"viewport-pause")){result=a2_menu_sdl_game(0,1,1);assert(result==A2_MENU_RESUME);}
    else if(!strncmp(mode,"hub-",4)){
        A2Settings original=a2s;
        result=a2_menu_sdl_game(!strncmp(mode,"hub-startup",11),strcmp(mode,"hub-disabled-save")!=0,1);
        assert(result==((!strcmp(mode,"hub-save")||!strcmp(mode,"hub-pad-save")||!strcmp(mode,"hub-event-batch"))?A2_MENU_SAVE_SLOT:(!strcmp(mode,"hub-load")||!strcmp(mode,"hub-physical-load"))?A2_MENU_LOAD_SLOT:!strcmp(mode,"hub-startup-load")?A2_MENU_LOAD:A2_MENU_RESUME));
        if(!strcmp(mode,"hub-settings"))original.filter=1;
        assert(!memcmp(&original,&a2s,sizeof a2s));
    }
    else {int startup=!strncmp(mode,"startup-load",12)||!strcmp(mode,"viewport-startup")||!strcmp(mode,"no-models-startup")||!strcmp(mode,"no-models-cancel")||!strcmp(mode,"english-subtitles-startup");
        result=a2_menu_sdl_settings(startup,1,1);assert(result==(!strcmp(mode,"no-models-cancel")?A2_MENU_QUIT:(!strcmp(mode,"menu-save")||!strcmp(mode,"no-models")||!strcmp(mode,"no-models-mouse"))?A2_MENU_SAVE:(!strcmp(mode,"menu-load")||!strncmp(mode,"startup-load",12))?A2_MENU_LOAD:A2_MENU_RESUME));}
    if(!strncmp(mode,"no-models",9))assert(a2s.hd_models==1);
    if(!strncmp(mode,"english-subtitles",17)){
        assert(a2s.english_subtitle_language==2);
        assert(a2s.text_language==(argc>4?atoi(argv[4]):0)&&a2s.voice_language==1);
        assert(a2s.subtitles==0&&!a2s.skip_intro&&!a2s.hd_portraits);
    }
    SDL_WaitThread(thread,NULL);
    if((!strcmp(mode,"longerror")||!strcmp(mode,"errorscroll"))&&argc>1&&strcmp(argv[1],"-")){
        A2TextRaster captured={0};assert(a2_image_raster_load(argv[1],&captured));assert(captured.width==960&&captured.height==540);
        for(int y=347;y<366;y++)for(int x=140;x<810;x++)assert(captured.pixels[y*captured.width+x]==0xff120f0cu);
        a2_text_raster_free(&captured);
    }
    if(!strcmp(mode,"display")||!strcmp(mode,"pad"))assert(a2s.filter==1);
    if(!strcmp(mode,"keys")){assert(a2s.key[4]==SDL_SCANCODE_C);assert(a2s.key[13]==0);assert(a2s.key[6]==0);assert(a2s.key[14]==SDL_SCANCODE_X);}
    if(!strcmp(mode,"padcapture"))assert(a2s.pad[4][1].kind==A2_BIND_BUTTON&&a2s.pad[4][1].code==SDL_CONTROLLER_BUTTON_Y);
    int lw,lh;SDL_RenderGetLogicalSize(r,&lw,&lh);assert(lw==logicalw&&lh==logicalh);
    if(!strcmp(mode,"resize")){
        SDL_Rect actual,expected_viewport;float actual_x,actual_y,expected_x,expected_y;
        SDL_RenderGetViewport(r,&actual);SDL_RenderGetScale(r,&actual_x,&actual_y);
        assert(!SDL_RenderSetLogicalSize(r,0,0));assert(!SDL_RenderSetLogicalSize(r,640,480));
        SDL_RenderGetViewport(r,&expected_viewport);SDL_RenderGetScale(r,&expected_x,&expected_y);
        assert(!memcmp(&actual,&expected_viewport,sizeof actual));assert(actual_x==expected_x&&actual_y==expected_y);
    }
    SDL_BlendMode blend;SDL_GetRenderDrawBlendMode(r,&blend);assert(blend==SDL_BLENDMODE_ADD);
    Uint8 red,green,blue,alpha;SDL_GetRenderDrawColor(r,&red,&green,&blue,&alpha);assert(red==1&&green==2&&blue==3&&alpha==4);
    if(viewport_test()){
      for(int round=0;round<4;round++){
        if(round){
            thread=SDL_CreateThread(input_thread,"fixture-input",NULL);assert(thread);
            if(!strcmp(mode,"viewport-error"))a2_menu_sdl_error("Файл сохранения повреждён.");
            else if(!strcmp(mode,"viewport-pause"))assert(a2_menu_sdl_game(0,1,1)==A2_MENU_RESUME);
            else assert(a2_menu_sdl_settings(!strcmp(mode,"viewport-startup"),1,1)==A2_MENU_RESUME);
            SDL_WaitThread(thread,NULL);
        }
        /* Startup and settings apply the window preferences after the modal;
         * save/error returns directly to the next game frame. Exercise both. */
        if(strcmp(mode,"viewport-error"))assert(!SDL_RenderSetLogicalSize(r,logicalw,logicalh));
        SDL_Surface *after=game_frame(r,frame);assert(before->w==after->w&&before->h==after->h&&before->pitch==after->pitch);
        size_t bytes=(size_t)before->pitch*before->h;
        if(memcmp(before->pixels,after->pixels,bytes)){
            fprintf(stderr,"game frame changed after closing %s menu\n",mode);
            SDL_SaveBMP(before,"/tmp/a2-menu-viewport-before.bmp");SDL_SaveBMP(after,"/tmp/a2-menu-viewport-after.bmp");
        }
        assert(!memcmp(before->pixels,after->pixels,bytes));SDL_FreeSurface(after);
      }
    }
    SDL_FreeSurface(before);
    assert(SDL_GetWindowFromID(SDL_GetWindowID(window))==window);
    assert(!a2_input_take_menu_request());
    if(joystick){SDL_JoystickClose(joystick);assert(!SDL_JoystickDetachVirtual(virtual_index));}
    a2_input_shutdown();SDL_DestroyTexture(frame);SDL_DestroyRenderer(r);SDL_DestroyWindow(window);SDL_Quit();cleanup(private_dir);
    printf("same-window SDL menu %s language%d: pass\n",mode,a2s.text_language);return 0;
}
