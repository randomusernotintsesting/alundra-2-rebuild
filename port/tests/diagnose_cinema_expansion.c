/* Offline renderer experiment only: no guest execution or production hooks.
 * cc -O2 -UNDEBUG -Iport/src port/tests/diagnose_cinema_expansion.c -o PROBE
 * PROBE RAM VRAM OUTPUT_PREFIX
 * Captured post-frame textures are replay inputs, not proof of live equality.
 * PPM files contain direct unfiltered IR1 GPU output, not edited screenshots. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/gpu.c"
uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
uint32_t psx_frame_no,gpu_flips;
void psx_vblank_tick(void) {}
uint32_t psx_mmio_read(uint32_t p,int n) {(void)p;(void)n;return 0;}
int a2_modelcap_active(void) {return 0;}
FILE *a2_modelcap_file(void) {return NULL;}
static uint16_t seed[1024*512], original[320*172], expanded[320*216];
static uint32_t words[100000];
static void read_exact(const char *name,void *dst,size_t n) {
    FILE *f=fopen(name,"rb");assert(f);assert(fread(dst,1,n,f)==n);
    assert(fgetc(f)==EOF);fclose(f);
}
static size_t collect(void) {
    uint32_t a=lw_(0xb7758)&0xffffff;size_t count=0;unsigned nodes=0;
    while(a!=0xffffff) {
        assert(++nodes<100000 && a && !(a&3) && a+4<PSX_RAM_SIZE);
        uint32_t tag=lw_(a),n=tag>>24;assert(a+4+n*4<=PSX_RAM_SIZE);
        assert(count+n<sizeof words/sizeof *words);
        for(unsigned i=0;i<n;i++)words[count++]=lw_(a+4+4*i);
        a=tag&0xffffff;
    }
    fprintf(stderr,"capture nodes=%u words=%zu\n",nodes,count);return count;
}
static void ppm(const char *prefix,const char *suffix,const uint16_t *pixels,int h) {
    char path[4096];assert(snprintf(path,sizeof path,"%s-%s.ppm",prefix,suffix)<(int)sizeof path);
    FILE *f=fopen(path,"wb");assert(f);fprintf(f,"P6\n320 %d\n255\n",h);
    for(int i=0;i<320*h;i++) {
        uint16_t c=pixels[i];unsigned char rgb[3]={(c&31)<<3,((c>>5)&31)<<3,((c>>10)&31)<<3};
        assert(fwrite(rgb,1,3,f)==3);
    }
    assert(fclose(f)==0);
}
static void render(size_t count,int grow,uint16_t *out) {
    gpu_gp1(0);memcpy(GPU_VRAM,seed,sizeof seed);gpu_set_ir(1);gpu_set_filter(0);
    int top=-1,bottom=-1,buffer=-1,picture=0;unsigned polygons=0;
    /* Only scene primitives are re-rendered. Existing framebuffer contents
     * and subtitle clear/text are excluded from the diagnostic destination. */
    for(size_t i=0;i<count;) {
        uint32_t p[64];int n=gp0_len(words[i]);assert(n>0&&n<=64&&i+(size_t)n<=count);
        memcpy(p,words+i,(size_t)n*4);unsigned c=p[0]>>24;i+=(size_t)n;
        if(c==0xe3) {assert((p[0]&1023)==0);top=(p[0]>>10)&511;picture=0;continue;}
        if(c==0xe4) {
            assert((p[0]&1023)==319);bottom=(p[0]>>10)&511;
            picture=bottom-top==171;
            if(picture) {
                assert(top==0||top==256);buffer=top;
                g.dax1=0;g.dax2=319;g.day1=buffer;g.day2=buffer+171+grow;
                g.ofx=0;g.ofy=buffer+grow/2;
                for(int y=buffer;y<=g.day2;y++)memset(GPU_VRAM+y*1024,0,320*2);
            }
            continue;
        }
        if(c==0xe1||c==0xe2||c==0xe6) {
            for(int j=0;j<n;j++)gpu_gp0(p[j]);continue;
        }
        assert(c!=0xe5); /* No unknown captured coordinate transformation. */
        if(!picture)continue;
        /* No uploads/copies inside the captured picture pass are supported. */
        assert(c>=0x20&&c<0x80);
        if(c<0x40)polygons++;
        for(int j=0;j<n;j++)gpu_gp0(p[j]);
    }
    assert(buffer==0||buffer==256);
    for(int y=0;y<172+grow;y++)memcpy(out+y*320,GPU_VRAM+(buffer+y)*1024,320*2);
    fprintf(stderr,"grow=%d picture-buffer=%d scene-polygons=%u\n",grow,buffer,polygons);
    if(!grow) {
        unsigned diff=0;
        for(int y=0;y<172;y++)for(int x=0;x<320;x++)diff+=out[y*320+x]!=seed[(buffer+y)*1024+x];
        fprintf(stderr,"original scene reraster vs retained VRAM differing pixels=%u/55040\n",diff);
    }
}
int main(int argc,char **argv) {
    assert(argc==4);read_exact(argv[1],PSX_RAM,sizeof PSX_RAM);read_exact(argv[2],seed,sizeof seed);
    size_t count=collect();render(count,0,original);render(count,44,expanded);
    unsigned diff=0;
    for(int y=0;y<172;y++)for(int x=0;x<320;x++)diff+=original[y*320+x]!=expanded[(y+22)*320+x];
    fprintf(stderr,"expanded core vs original reraster differing pixels=%u/55040\n",diff);
    ppm(argv[3],"original",original,172);ppm(argv[3],"expanded",expanded,216);
    return 0;
}
