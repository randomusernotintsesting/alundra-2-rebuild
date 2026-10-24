/* Captured GP0 stream through production expansion hooks, isolated from a
 * running game. Exact enabled/disabled native VRAM and central output oracle.
 * cc -O2 -UNDEBUG -Iport/src port/tests/diagnose_cinema_gpu_surface.c -o PROBE
 * PROBE RAM VRAM OUTPUT_PREFIX [IR]
 * Post-frame texture captures limit comparison with original live screenshots. */
#define A2_CINEMA_EXPANSION 1
#define main geometry_diagnostic_main
#include "diagnose_cinema_expansion.c"
#undef main
#include "../src/frame_compose.c"
static uint16_t native_before[1024*512];
static void output_rgb(const char *prefix,const char *mode,uint32_t *data,int w,int h) {
    char path[4096];assert(snprintf(path,sizeof path,"%s-%s.ppm",prefix,mode)<(int)sizeof path);
    FILE *f=fopen(path,"wb");assert(f);fprintf(f,"P6\n%d %d\n255\n",w,h);
    for(int i=0;i<w*h;i++) {
        unsigned char rgb[3]={data[i]>>16,data[i]>>8,data[i]};
        assert(fwrite(rgb,1,3,f)==3);
    }
    assert(fclose(f)==0);
}
int main(int argc,char **argv) {
    assert(argc==4||argc==5);read_exact(argv[1],PSX_RAM,sizeof PSX_RAM);
    read_exact(argv[2],seed,sizeof seed);size_t count=collect();int by=-1;
    for(size_t k=0;k<count;) {
        int n=gp0_len(words[k]);assert(n>0);
        if(words[k]>>24==0xe3){by=(words[k]>>10)&511;break;}k+=n;
    }
    assert(by==0||by==256);int s=argc==5?atoi(argv[4]):1;assert(s>=1&&s<=4);
    uint32_t *before=malloc((size_t)320*240*s*s*4),*after=malloc((size_t)320*240*s*s*4);
    assert(before&&after);gpu_set_ir(s);gpu_set_filter(s>1);
    A2CinemaRaster raster={0,by,320,216,0,12,320,240,1,5};
    A2CinemaLayout layout={0,172,34,174,32,207};
    for(int enabled=0;enabled<=1;enabled++) {
        gpu_gp1(0);gpu_set_cinema_expansion(enabled);memcpy(GPU_VRAM,seed,sizeof seed);
        if(SHADOW)for(int y=0;y<512*s;y++)for(int x=0;x<1024*s;x++)
            SHADOW[y*IR_W+x]=seed[(y/s)*1024+x/s];
        g.dax1=0;g.dax2=319;g.day1=by;g.day2=by+215;g.ofx=0;g.ofy=by;
        for(size_t k=0;k<count;k++)gpu_gp0(words[k]);
        assert(fifo_n==0);
        if(!enabled) {
            memcpy(native_before,GPU_VRAM,sizeof GPU_VRAM);
            a2_compose_cinema(before,320*s,s,&raster,&layout);
        } else {
            assert(!memcmp(native_before,GPU_VRAM,sizeof GPU_VRAM));
            assert(gpu_cinema_expansion_ready(by));
            assert(a2_compose_cinema_expanded(after,320*s,s,&raster,&layout));
        }
    }
    unsigned differences=0;
    for(int y=34*s;y<206*s;y++)for(int x=0;x<320*s;x++)
        differences+=before[y*320*s+x]!=after[y*320*s+x];
    assert(!differences);
    output_rgb(argv[3],"centered",before,320*s,240*s);
    output_rgb(argv[3],"expanded",after,320*s,240*s);
    fprintf(stderr,"production hooks IR%d: full native VRAM equality; %u core RGB differences; buffer=%d\n",s,differences,by);
    free(before);free(after);return 0;
}
