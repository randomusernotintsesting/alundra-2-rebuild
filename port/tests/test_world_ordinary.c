/* Bounded production-feature fine-raster benchmark and exact frozen oracle.
 * cc -O3 -UNDEBUG -Isrc tests/test_world_ordinary.c src/world_precision.c
 * Run: executable [iterations, default 12]. No game, SDL or user data. */
#define main unused_mesh_fixture_main
#include "test_gpu_native_mesh.c"
#undef main
#include "reference_world_fine.inc"
#include <time.h>
#include <fenv.h>
static double ordinary_now(void) {
    struct timespec ts;clock_gettime(CLOCK_MONOTONIC,&ts);
    return ts.tv_sec+ts.tv_nsec*1e-9;
}
static uint64_t ordinary_hash(const void *p,size_t bytes) {
    const unsigned char *data=p;uint64_t h=UINT64_C(1469598103934665603);
    for(size_t i=0;i<bytes;i++)h=(h^data[i])*UINT64_C(1099511628211);
    return h;
}
int main(int argc,char **argv) {
    unsigned iterations=argc>1?(unsigned)atoi(argv[1]):12;assert(iterations&&iterations<=100);
    assert(!fesetround(FE_TONEAREST));setenv("A2_COLOR_PRECISION","1",1);
    setenv("A2_FINE_PARALLEL","0",1);gpu_set_ir(4);gpu_gp1(0);gpu_set_filter(1);
    assert(gpu_display_argb_row(0));
    a2_mesh_live_enabled=a2_mesh_live_active=a2_mesh_live_writes_watched=0;
    mesh_pixel_kind=A2_COMPOSITE_UNKNOWN;gpu_model_depth_configure(1);
    hd_matches_reset();art_fixture=portrait_fixture=hd_sample_fixture=0;
    g.dax1=0;g.day1=0;
    size_t n=(size_t)IR_W*IR_H;
    uint16_t *native=malloc(sizeof GPU_VRAM),*fine=malloc(n*2);uint32_t *rgb=malloc(n*4);
    uint8_t *ram=malloc(sizeof PSX_RAM);assert(native&&fine&&rgb&&ram);
    memcpy(ram,PSX_RAM,sizeof PSX_RAM);
    for(unsigned small=0;small<2;small++)for(unsigned mode=0;mode<3;mode++)for(unsigned semi=0;semi<2;semi++) {
        g.dax2=small?15:159;g.day2=small?11:119;
        cur_tpage=15|(mode<<7)|((mode%4)<<5);cur_clut=63;g.texwin=mode==1?0x32867:0;
        for(unsigned i=0;i<1024*512;i++)GPU_VRAM[i]=i%13?(uint16_t)(i*9173u+0x582bu):0;
        memcpy(native,GPU_VRAM,sizeof GPU_VRAM);
        for(size_t i=0;i<n;i++){SHADOW[i]=0x1931;SHADOW_RGB[i]=0xff352719u;}
        Vtx v[3]={{0,0,7,19,37,2,1},{0,0,253,231,197,247,9},{0,0,83,127,179,5,237}};
        WorldFineTriangle t={{{-16384,32768},{159*65536+8192,32768},{-16384,119*65536+16384}}};
        if(small){t.p[1].x=15*65536+8192;t.p[2].y=11*65536+16384;
            for(unsigned i=0;i<3;i++){v[i].u/=10;v[i].v/=10;}}
        fine_uv_polygon(v,3);
        reference_world_fine(v[0],v[1],v[2],t,1,1,semi,4,NULL);
        memcpy(fine,SHADOW,n*2);memcpy(rgb,SHADOW_RGB,n*4);
        for(size_t i=0;i<n;i++){SHADOW[i]=0x1931;SHADOW_RGB[i]=0xff352719u;}
        raster_tri_world_fine(v[0],v[1],v[2],t,1,1,semi,4,NULL);
        assert(!memcmp(native,GPU_VRAM,sizeof GPU_VRAM));
        assert(!memcmp(fine,SHADOW,n*2));assert(!memcmp(rgb,SHADOW_RGB,n*4));
        uint64_t fh=ordinary_hash(SHADOW,n*2),rh=ordinary_hash(SHADOW_RGB,n*4);
        unsigned repeats=iterations*(small?20:1);double start=ordinary_now();
        for(unsigned i=0;i<repeats;i++)raster_tri_world_fine(v[0],v[1],v[2],t,1,1,semi,4,NULL);
        printf("small=%u mode=%u semi=%u ms=%.6f fine=%016llx rgb=%016llx\n",small,mode,semi,
            (ordinary_now()-start)*1000/repeats,(unsigned long long)fh,(unsigned long long)rh);
        assert(!memcmp(native,GPU_VRAM,sizeof GPU_VRAM));
        assert(!memcmp(ram,PSX_RAM,sizeof PSX_RAM));
    }
    free(native);free(fine);free(rgb);free(ram);gpu_set_ir(1);
    puts("PASS: production-feature filtered affine fixture preserves native/555/888 against frozen oracle");
}
