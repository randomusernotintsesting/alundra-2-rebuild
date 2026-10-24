#include "game_profiles.h"
#include "paths.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

typedef struct { char disc[4096], image[4096]; int available; const char *reason; } Profile;
static Profile profiles[3];
static char profile_root[4096];
#ifdef A2_NATIVE_RESOURCES
static A2Resources *native_store;
A2Resources *a2_profile_resources(void) {return native_store;}
void a2_profiles_close_native(void) {a2_resources_close(native_store);native_store=NULL;}
#endif
static int regular(const char *p) { struct stat s;return p && *p && !stat(p,&s) && S_ISREG(s.st_mode) && s.st_size>0; }
static uint32_t le32(const unsigned char *p) { return p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24; }
static int compatible(const char *disc) {
    char path[4096];
    if(snprintf(path,sizeof path,"%s/SCPS_101.15",disc)>=(int)sizeof path)return 0;
    struct stat st;if(stat(path,&st) || st.st_size!=0x46800)return 0;
    FILE *f=fopen(path,"rb");if(!f)return 0;
    unsigned char h[0x34];int ok=fread(h,1,sizeof h,f)==sizeof h;fclose(f);
    /* Generated dispatch addresses target this JP binary layout. The US
     * entry point/segment length differ: never accept it by filename alone. */
    return ok && !memcmp(h,"PS-X EXE",8) && le32(h+0x10)==0x80039bfcu &&
           le32(h+0x18)==0x80017000u && le32(h+0x1c)==0x46000u;
}
static void validate(Profile *p) {
    p->available=0;
    p->reason="Данные этой версии не установлены.";
    if(!regular(p->image))return;
    if(!compatible(p->disc)) { p->reason="Данные несовместимы с этой сборкой игры.";return; }
    p->available=1;p->reason="";
}
static void parent(char *path) {
    size_t len=strlen(path);while(len>1 && path[len-1]=='/')path[--len]=0;
    char *slash=strrchr(path,'/');if(slash) { if(slash==path)slash[1]=0;else *slash=0; }
    else strcpy(path,".");
}
#ifdef A2_NATIVE_RESOURCES
int a2_profiles_open_native(const char *path,char *error,size_t size) {
    if(native_store || !a2_resources_open(path,&native_store,error,size))return 0;
    snprintf(profile_root,sizeof profile_root,"%s",path);parent(profile_root);
    static const char *required[]={"DATA/PACK0.PAK","DATA/PACK1.PAK","DATA/PAKVCAST.PAK",
        "DATA/PAKOMAKE.PAK","DATA/GRP.GP","GAME00.BIN","EVENT00.BIN","GAME01.BIN","GAME02.BIN","GAME03.BIN"};
    for(int lang=0;lang<3;lang++) {
        Profile *p=profiles+lang;memset(p,0,sizeof *p);
        p->reason="Данные этой версии не установлены.";
        if(!(a2_resources_profiles(native_store)&(1u<<lang)))continue;
        p->reason="Данные несовместимы с этой сборкой игры.";
        A2ResourceId exe=a2_resource_find(native_store,lang,"SCPS_101.15");
        unsigned char h[0x34];
        int ok=exe && a2_resource_size(native_store,exe)==0x46800 &&
            a2_resource_pread(native_store,exe,0,h,sizeof h,error,size) &&
            !memcmp(h,"PS-X EXE",8) && le32(h+0x10)==0x80039BFC &&
            le32(h+0x18)==0x80017000 && le32(h+0x1c)==0x46000;
        for(unsigned i=0;ok && i<sizeof required/sizeof required[0];i++) {
            A2ResourceId id=a2_resource_find(native_store,lang,required[i]);
            ok=id && a2_resource_size(native_store,id)>0;
        }
        if(ok){p->available=1;p->reason="";}
    }
    if(!profiles[0].available && !profiles[1].available && !profiles[2].available) {
        if(error && size)snprintf(error,size,"No compatible game edition in native archive");
        a2_profiles_close_native();return 0;
    }
    if(error && size)error[0]=0;return 1;
}
#endif
void a2_profiles_init(const char *disc,const char *image) {
    memset(profiles,0,sizeof profiles);
    snprintf(profiles[0].disc,sizeof profiles[0].disc,"%s",disc?disc:"");
    snprintf(profiles[0].image,sizeof profiles[0].image,"%s",image?image:"");
    validate(&profiles[0]);
    const char *override=getenv("A2_PROFILE_ROOT");
    if(override && *override)snprintf(profile_root,sizeof profile_root,"%s",override);
    else {
        snprintf(profile_root,sizeof profile_root,"%s",disc?disc:"");parent(profile_root);
        /* Reinitialization from an already selected edition preserves its
         * common game-data root, and therefore independent voice assets. */
        char *marker=strstr(profile_root,"/profiles/");if(marker)*marker=0;
    }
    static const char *code[]={"ru","ja","en"};
    for(int i=0;i<3;i++) {
        Profile p={0};
        int n=snprintf(p.disc,sizeof p.disc,"%s/profiles/%s/disc",profile_root,code[i]);
        int m=snprintf(p.image,sizeof p.image,"%s/profiles/%s/disc.bin",profile_root,code[i]);
        if(n<0 || n>=(int)sizeof p.disc || m<0 || m>=(int)sizeof p.image) {
            p.reason="Путь к данным слишком длинный.";
        } else validate(&p);
        if(i || p.available)profiles[i]=p;
    }
}
int a2_profile_available(int language) { return language>=0 && language<3 && profiles[language].available; }
const char *a2_profile_reason(int language) { return language>=0 && language<3 && profiles[language].reason ? profiles[language].reason : "Неизвестная версия игры."; }
int a2_profile_select(int language) {
    if(!a2_profile_available(language))return 0;
#ifdef A2_NATIVE_RESOURCES
    if(native_store)return 1;
#endif
    strcpy(a2_paths.disc,profiles[language].disc);strcpy(a2_paths.image,profiles[language].image);return 1;
}
const char *a2_profile_root(void) { return profile_root; }
int a2_profile_voice_path(int language,char *out,size_t size) {
    if(language<0 || language>1)return 0;
    const char *override=getenv(language==0?"A2_JAPANESE_VOICE_PACK":"A2_VOICE_PACK");
    int n=override && *override ? snprintf(out,size,"%s",override) : snprintf(out,size,"%s/voices/%s/voices.a2v",profile_root,language==0?"ja":"en");
    return n>=0 && (size_t)n<size;
}
