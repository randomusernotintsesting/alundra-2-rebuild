/* Compare every native ADPCM group and decoded PCM sample to an accepted pack.
 * This runs only in a root-approved full-media verification slot. */
#include "../src/a2_resources.h"
#include "../src/xa_audio.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>
static uint32_t u32(const uint8_t *p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
int main(int argc,char **argv){
    if(argc!=4 || (strcmp(argv[2],"ja")&&strcmp(argv[2],"en"))){
        fprintf(stderr,"Usage: verify_native_voice game.a2r ja|en accepted-voices.a2v\n");return 2;
    }
    A2Resources *store=NULL;char error[256],path[64];int result=1;
    if(!a2_resources_open(argv[1],&store,error,sizeof error)){fprintf(stderr,"%s\n",error);return 2;}
    FILE *original=fopen(argv[3],"rb");if(!original){a2_resources_close(store);return 2;}
    uint8_t old[11744],index[11744];
    snprintf(path,sizeof path,"VOICE/%s/index.a2v",argv[2]);
    A2ResourceId idx=a2_resource_find(store,3,path);
    if(!idx||a2_resource_size(store,idx)!=sizeof index||
       !a2_resource_pread(store,idx,0,index,sizeof index,error,sizeof error)||
       fread(old,1,sizeof old,original)!=sizeof old||memcmp(old,"A2VOICE1",8)||memcmp(index,"A2NVOC01",8)||
       u32(old+12)!=183||u32(index+12)!=183||u32(old+28)!=sizeof old||u32(index+24)!=sizeof index)goto done;
    unsigned clips=0;uint64_t total_frames=0,total_groups=0;
    puts("name,groups,frames,rate,duration_seconds,nonzero_frames,peak,pcm_crc32,equal_groups,equal_pcm");
    for(unsigned i=0;i<183;i++){
        uint8_t *o=old+32+64*i,*r=index+32+64*i;
        if(memcmp(o,r,16)||!memchr(r,0,16)||u32(o+40)!=u32(r+40)||u32(o+48)!=u32(r+44))goto done;
        if(!u32(r+44))continue;
        unsigned count=u32(r+40),coding=u32(r+48);snprintf(path,sizeof path,"VOICE/%s/%s.adpcm",argv[2],r);
        A2ResourceId id=a2_resource_find(store,3,path);
        if(!id||a2_resource_size(store,id)!=(uint64_t)count*2304||
           fseek(original,(long)(sizeof old+(uint64_t)u32(o+44)*2352),SEEK_SET))goto done;
        XaDecoder before={0},after={0};uint64_t frames=0,nonzero=0;unsigned rate=0,peak=0;
        uLong crc=crc32(0,NULL,0);
        for(unsigned block=0;block<count;block++){
            uint8_t raw[2352],groups[2304];int16_t pcm0[8064],pcm1[8064];unsigned r0,r1;
            if(fread(raw,1,sizeof raw,original)!=sizeof raw||
               !a2_resource_pread(store,id,(uint64_t)block*2304,groups,sizeof groups,error,sizeof error)||
               memcmp(raw+24,groups,sizeof groups)||raw[19]!=coding)goto done;
            size_t n=xa_decode_sector(&before,raw,sizeof raw,pcm0,4032,&r0);
            size_t m=xa_decode_groups(&after,groups,sizeof groups,coding,pcm1,4032,&r1);
            if(!n||n!=m||r0!=r1||(rate&&rate!=r1)||memcmp(pcm0,pcm1,n*4))goto done;
            rate=r1;frames+=n;crc=crc32(crc,(const Bytef*)pcm1,(uInt)(n*4));
            for(size_t p=0;p<n;p++){
                nonzero+=pcm1[p*2]!=0||pcm1[p*2+1]!=0;
                for(unsigned c=0;c<2;c++){unsigned a=(unsigned)abs((int)pcm1[p*2+c]);if(a>peak)peak=a;}
            }
        }
        if(!nonzero)goto done;
        printf("%s,%u,%llu,%u,%.9f,%llu,%u,%08lx,1,1\n",r,count,(unsigned long long)frames,rate,
            (double)frames/rate,(unsigned long long)nonzero,peak,crc);
        clips++;total_frames+=frames;total_groups+=count;
    }
    if(clips!=(strcmp(argv[2],"ja")?177u:183u))goto done;
    fprintf(stderr,"Native voice equality passed: language=%s clips=%u groups=%llu frames=%llu equal_groups=1 equal_pcm=1 image_reads=0\n",
        argv[2],clips,(unsigned long long)total_groups,(unsigned long long)total_frames);result=0;
done:
    if(result)fprintf(stderr,"Native voice equality failed: %s\n",error);
    fclose(original);a2_resources_close(store);return result;
}
