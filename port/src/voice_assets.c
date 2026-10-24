/* Explicit language source overlay. No source disc writes. */
#include "voice_assets.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VOICE_COUNT 183u
#define RAW_SIZE 2352u
#define METADATA_SIZE (32u + VOICE_COUNT * 64u)
typedef struct {
    char name[16];
    uint32_t address, old_offset, old_channel, old_sectors;
    uint32_t offset, channel, sectors, pack_sector, origin, stride;
} VoiceClip;
static struct {
    FILE *file;
    VoiceClip clips[VOICE_COUNT];
    uint32_t base[2], extent[2], payload;
    int active, selected;
    uint32_t consumed, first_lba, last_lba;
    uint64_t frames;
} voice = {.active = -1, .selected = -1};
static char error[192];
static uint32_t le32(const uint8_t *p) {
    return (uint32_t)p[0] | (uint32_t)p[1]<<8 | (uint32_t)p[2]<<16 | (uint32_t)p[3]<<24;
}
static void put32(uint8_t *p,uint32_t x) { p[0]=x;p[1]=x>>8;p[2]=x>>16;p[3]=x>>24; }
static int fail(const char *message) { snprintf(error,sizeof error,"%s",message);return 0; }
const char *a2_voice_error(void) { return error; }
static int header(FILE *f,uint8_t h[32]) {
    if (fseek(f,0,SEEK_SET) || fread(h,1,32,f)!=32 || memcmp(h,"A2VOICE1",8) ||
        le32(h+8)!=1 || le32(h+12)!=VOICE_COUNT || le32(h+28)!=METADATA_SIZE ||
        !le32(h+16) || !le32(h+20) || le32(h+24)>400000) return 0;
    if(fseek(f,0,SEEK_END)) return 0;
    long size=ftell(f);
    return size>=0 && (uint64_t)size==METADATA_SIZE+(uint64_t)le32(h+24)*RAW_SIZE;
}
int a2_voice_available(const char *path) {
    if(!path || !*path) return 0;
    FILE *f=fopen(path,"rb");if(!f)return 0;
    uint8_t h[32];int ok=header(f,h);fclose(f);return ok;
}
int a2_voice_available_for_language(const char *path,int language) {
    if(!path || !*path || (language!=0 && language!=1))return 0;
    FILE *f=fopen(path,"rb");if(!f)return 0;
    uint8_t h[32];int ok=header(f,h);unsigned found=0;
    if(ok && !fseek(f,32,SEEK_SET)) {
        for(unsigned i=0;i<VOICE_COUNT;i++) {
            uint8_t r[64];
            if(fread(r,1,64,f)!=64){ok=0;break;}
            uint32_t origin=le32(r+48);
            if(origin && origin!=(language==0?3u:1u)){ok=0;break;}
            found+=origin!=0;
        }
    } else ok=0;
    fclose(f);
    return ok && (language==0?found==VOICE_COUNT:found>0);
}
int a2_voice_open_for_language(const char *path,const char *image,uint8_t *ram,
                             size_t ram_size,int language) {
    if(!a2_voice_available_for_language(path,language)) {
        a2_voice_close();
        return fail(language==0?"A complete Japanese voice pack is required":
                               "The selected pack does not contain English voices");
    }
    return a2_voice_open(path,image,ram,ram_size);
}
static int raw_read(FILE *f,uint32_t lba,uint8_t raw[2352]) {
    return !fseek(f,(long)lba*RAW_SIZE,SEEK_SET) && fread(raw,1,RAW_SIZE,f)==RAW_SIZE;
}
static int iso_both(const uint8_t *p,uint32_t *out) {
    *out=le32(p);return p[4]==p[3]&&p[5]==p[2]&&p[6]==p[1]&&p[7]==p[0];
}
static int extents(const char *path,uint32_t base[2],uint32_t size[2]) {
    FILE *f=fopen(path,"rb");if(!f)return 0;
    uint8_t raw[2352];uint32_t root,bytes;int found=0;
    if(!raw_read(f,16,raw) || memcmp(raw+24,"\1CD001\1",7) ||
       memcmp(raw+24+128,"\0\10\10\0",4) ||
       !iso_both(raw+24+158,&root)||!iso_both(raw+24+166,&bytes)||bytes>65536) {
        fclose(f);return 0;
    }
    for(uint32_t sector=0;sector<(bytes+2047)/2048;sector++) {
        if(!raw_read(f,root+sector,raw))break;
        for(unsigned p=24;p<2072 && raw[p];p+=raw[p]) {
            const uint8_t *r=raw+p;unsigned n=r[0];
            if(n<34 || p+n>2072 || r[32]>n-33) { fclose(f);return 0; }
            int t=-1;
            if(r[32]==11&&!memcmp(r+33,"STEREO.XA;1",11))t=0;
            if(r[32]==9&&!memcmp(r+33,"MONO.XA;1",9))t=1;
            if(t>=0) {
                uint32_t extent_bytes;
                if((found&(1<<t))||!iso_both(r+2,&base[t])||!iso_both(r+10,&extent_bytes)) {
                    fclose(f);return 0;
                }
                size[t]=(extent_bytes+2047)/2048;found|=1<<t;
            }
        }
    }
    if (fseek(f,0,SEEK_END)) { fclose(f);return 0; }
    long total=ftell(f);fclose(f);
    return found==3 && total>=0 && (uint64_t)base[0]+size[0]<=(uint64_t)total/RAW_SIZE &&
        (uint64_t)base[1]+size[1]<=(uint64_t)total/RAW_SIZE &&
        ((uint64_t)base[0]+size[0]<=base[1]||(uint64_t)base[1]+size[1]<=base[0]);
}
void a2_voice_event(const char *reason) {
    if(voice.active<0)return;
    VoiceClip *c=voice.clips+voice.active;
    fprintf(stderr,"voicecue: end name=%s reason=%s consumed=%u expected=%u frames=%llu "
                   "first_lba=%u last_lba=%u complete=%d\n",c->name,reason,
        voice.consumed,c->sectors,(unsigned long long)voice.frames,voice.first_lba,voice.last_lba,
        voice.consumed==c->sectors);
    voice.active=-1;
}
void a2_voice_stop(const char *reason) {
    a2_voice_event(reason);
    voice.selected=-1;
}
void a2_voice_begin(uint32_t target_lba,uint8_t file,uint8_t channel) {
    a2_voice_stop("ReadN");
    if(!voice.file || file!=1)return;
    for(unsigned i=0;i<VOICE_COUNT;i++) {
        VoiceClip *c=voice.clips+i;
        if(c->channel==channel && voice.base[c->stride==16]+c->offset==target_lba) {
            voice.selected=(int)i;
            return;
        }
    }
}
void a2_voice_close(void) {
    a2_voice_event("close");
    if(voice.file)fclose(voice.file);
    memset(&voice,0,sizeof voice);voice.active=voice.selected=-1;
}
int a2_voice_open(const char *path,const char *image,uint8_t *ram,size_t ram_size) {
    a2_voice_close();error[0]=0;
    if(!path||!image||!ram||ram_size<0x200000)return fail("Invalid voice overlay arguments");
    FILE *f=fopen(path,"rb");if(!f)return fail("Cannot open the selected voice pack");
    uint8_t h[32];
    if(!header(f,h)) { fclose(f);return fail("Voice pack header or length is invalid"); }
    uint32_t base[2],sizes[2];
    if(!extents(image,base,sizes)||le32(h+16)>sizes[0]||le32(h+20)>sizes[1]) {
        fclose(f);return fail("Voice pack does not fit the disc audio extents");
    }
    if(fseek(f,32,SEEK_SET)) { fclose(f);return fail("Cannot seek voice clip records"); }
    VoiceClip clips[VOICE_COUNT];uint32_t expected_sector=0;
    for(unsigned i=0;i<VOICE_COUNT;i++) {
        uint8_t r[64];VoiceClip *c=clips+i;
        if(fread(r,1,64,f)!=64){fclose(f);return fail("Truncated voice clip record");}
        memcpy(c->name,r,16);c->address=le32(r+16);
        c->old_offset=le32(r+20);c->old_channel=le32(r+24);c->old_sectors=le32(r+28);
        c->offset=le32(r+32);c->channel=le32(r+36);c->sectors=le32(r+40);
        c->pack_sector=le32(r+44);c->origin=le32(r+48);c->stride=le32(r+52);
        uint32_t address=i<126 ? 0x80054758+i*16 : 0x80054f38+(i-126)*16;
        unsigned t=i<126?0:1,stride=t?16:8;uint32_t slot=address&0x1fffff;
        uint32_t pointer=le32(ram+slot+12)&0x1fffff;
        if(c->address!=address||!memchr(c->name,0,16)||!c->name[0]||
           pointer>ram_size-16||strncmp((const char *)ram+pointer,c->name,16)||
           c->stride!=stride||c->origin>3||c->origin==2||c->channel>=stride||c->old_channel>=stride||
           c->offset%stride||c->old_offset%stride||!c->sectors||!c->old_sectors||
           c->sectors>400000||c->offset+(uint64_t)c->sectors*stride>le32(h+16+t*4)||
           le32(ram+slot)!=c->old_offset||le32(ram+slot+4)!=c->old_channel||
           le32(ram+slot+8)!=c->old_sectors||c->pack_sector!=expected_sector||
           le32(r+56)||le32(r+60)) {
            fclose(f);return fail("Voice clip table does not match the loaded Japanese executable");
        }
        if(c->origin)expected_sector+=c->sectors;
        if(expected_sector>le32(h+24)){fclose(f);return fail("Voice clip exceeds pack payload");}
        for(unsigned j=0;j<i;j++) {
            VoiceClip *p=clips+j;
            if(!strcmp(c->name,p->name) || (c->stride==p->stride && c->channel==p->channel &&
               c->offset<(uint64_t)p->offset+p->sectors*p->stride &&
               p->offset<(uint64_t)c->offset+c->sectors*c->stride)) {
                fclose(f);return fail("Duplicate or overlapping voice clip records");
            }
        }
    }
    if(expected_sector!=le32(h+24)){fclose(f);return fail("Unreferenced voice payload");}
    // Commit only after every record, source extent and payload bound validates.
    memcpy(voice.clips,clips,sizeof clips);memcpy(voice.base,base,sizeof base);
    memcpy(voice.extent,sizes,sizeof sizes);voice.payload=METADATA_SIZE;voice.file=f;
    unsigned available=0;
    for(unsigned i=0;i<VOICE_COUNT;i++) {
        VoiceClip *c=clips+i;uint32_t slot=c->address&0x1fffff;
        put32(ram+slot,c->offset);put32(ram+slot+4,c->channel);put32(ram+slot+8,c->sectors);
        available+=c->origin!=0;
    }
    const char *language="English";
    for(unsigned i=0;i<VOICE_COUNT;i++)if(clips[i].origin==3){language="Japanese";break;}
    fprintf(stderr,"voices: %s overlay loaded clips=%u missing=%u full_duration=1 path=%s\n",
        language,available,VOICE_COUNT-available,path);
    return 1;
}
static int lookup(uint32_t lba,uint32_t *sample) {
    for(unsigned t=0;t<2;t++) {
        if(lba<voice.base[t]||(uint64_t)lba>=voice.base[t]+(uint64_t)voice.extent[t])continue;
        uint32_t relative=lba-voice.base[t];
        for(unsigned i=t?126:0;i<(t?183:126);i++) {
            VoiceClip *c=voice.clips+i;
            if(relative%c->stride!=c->channel||relative<c->offset)continue;
            uint32_t s=(relative-c->offset)/c->stride;
            if(s<c->sectors){*sample=s;return (int)i;}
        }
    }
    return -1;
}
int a2_voice_read_sector(uint32_t lba,uint8_t raw[2352]) {
    if(!voice.file)return 0;
    if(!((lba>=voice.base[0]&&(uint64_t)lba<voice.base[0]+(uint64_t)voice.extent[0])||
         (lba>=voice.base[1]&&(uint64_t)lba<voice.base[1]+(uint64_t)voice.extent[1])))return 0;
    memset(raw,0,2352);uint32_t sample;int index=lookup(lba,&sample);
    // The guest polls end-of-cue and may issue Mute several sectors late.
    // Keep reading silence after this request's end, even if another packed
    // performance shares its channel. Only a new ReadN selects another cue.
    if(index<0||index!=voice.selected||!voice.clips[index].origin)return 2;
    VoiceClip *c=voice.clips+index;
    if(fseek(voice.file,(long)(voice.payload+(uint64_t)(c->pack_sector+sample)*RAW_SIZE),SEEK_SET)||
       fread(raw,1,2352,voice.file)!=2352) {
        memset(raw,0,2352);fail("Cannot read the selected voice sector");
    }
    return 1;
}
void a2_voice_observe(uint32_t lba,size_t frames) {
    if(!voice.file)return;
    uint32_t sample;int index=lookup(lba,&sample);if(index<0||index!=voice.selected)return;
    VoiceClip *c=voice.clips+index;
    if(voice.active!=index) {
        a2_voice_event("next-cue");voice.active=index;voice.consumed=0;voice.frames=0;
        voice.first_lba=lba;
        fprintf(stderr,"voicecue: start name=%s origin=%s sectors=%u original_sectors=%u "
                       "first_sample=%u first_lba=%u expected_last_lba=%u\n",c->name,
            c->origin==3?"jp-japanese":"us-english",c->sectors,c->old_sectors,sample,lba,
            voice.base[c->stride==16]+c->offset+c->channel+(c->sectors-1)*c->stride);
    }
    voice.consumed++;voice.frames+=frames;voice.last_lba=lba;
    if(sample+1==c->sectors)a2_voice_event("complete");
}
