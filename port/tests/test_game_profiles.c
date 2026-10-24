#include "game_profiles.h"
#include "paths.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
A2Paths a2_paths;
static void fixture(const char *root, const char *language, unsigned pc) {
    char p[4096];
    snprintf(p,sizeof p,"%s/profiles/%s",root,language);assert(mkdir(p,0700)==0);
    snprintf(p,sizeof p,"%s/profiles/%s/disc",root,language);assert(mkdir(p,0700)==0);
    snprintf(p,sizeof p,"%s/profiles/%s/disc/SCPS_101.15",root,language);
    FILE *f=fopen(p,"wb");assert(f);unsigned char data[0x800]={0};
    memcpy(data,"PS-X EXE",8);memcpy(data+0x10,&pc,4);
    unsigned load=0x80017000,size=0x46000;memcpy(data+0x18,&load,4);memcpy(data+0x1c,&size,4);
    assert(fwrite(data,1,sizeof data,f)==sizeof data);assert(ftruncate(fileno(f),0x46800)==0);assert(fclose(f)==0);
    snprintf(p,sizeof p,"%s/profiles/%s/disc.bin",root,language);f=fopen(p,"wb");assert(f);fputs("owned fixture",f);assert(fclose(f)==0);
}
int main(int argc,char **argv) {
    assert(argc==2);const char *root=argv[1];char p[4096],disc[4096],image[4096];
    snprintf(p,sizeof p,"%s/profiles",root);assert(mkdir(p,0700)==0);
    fixture(root,"ru",0x80039bfc);fixture(root,"en",0x8003cf4c); /* US EXE disguised as SCPS */
    snprintf(disc,sizeof disc,"%s/profiles/ru/disc",root);
    snprintf(image,sizeof image,"%s/profiles/ru/disc.bin",root);
    setenv("A2_PROFILE_ROOT",root,1);a2_profiles_init(disc,image);
    assert(a2_profile_available(0));assert(!a2_profile_available(1));assert(!a2_profile_available(2));
    strcpy(a2_paths.disc,"sentinel-disc");strcpy(a2_paths.image,"sentinel-image");
    assert(!a2_profile_select(2));assert(!strcmp(a2_paths.disc,"sentinel-disc"));assert(!strcmp(a2_paths.image,"sentinel-image"));
    assert(a2_profile_select(0));assert(!strcmp(a2_paths.disc,disc));assert(!strcmp(a2_paths.image,image));
    fixture(root,"ja",0x80039bfc);a2_profiles_init(disc,image);assert(a2_profile_available(1));
    assert(a2_profile_select(1));assert(strstr(a2_paths.disc,"/profiles/ja/disc"));
    assert(a2_profile_voice_path(1,p,sizeof p));char expected[4096];snprintf(expected,sizeof expected,"%s/voices/en/voices.a2v",root);assert(!strcmp(p,expected));
    assert(!a2_profile_voice_path(1,p,4));
    assert(a2_profile_voice_path(0,p,sizeof p));assert(strstr(p,"/voices/ja/voices.a2v"));
    assert(!a2_profile_voice_path(2,p,sizeof p));
    puts("profiles: availability, JP compatibility, independent voice path and atomic selection passed");
    return 0;
}
