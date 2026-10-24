/* Exact integer interpolation oracle, with full888/555/native planes and
 * alternating HD word hits/misses inside a Gouraud scanline. */
#define main unused_mesh_fixture_main
#include "test_gpu_native_mesh.c"
#undef main
#include "reference_world_fine.inc"
#include <fenv.h>
static unsigned checks,hd_checks;
static void differential(unsigned scale,unsigned code,unsigned constant) {
    gpu_set_ir((int)scale);gpu_gp1(0);gpu_set_filter((int)(code&1));
    assert(gpu_display_argb_row(0));
    a2_mesh_live_enabled=a2_mesh_live_active=a2_mesh_live_writes_watched=0;
    mesh_pixel_kind=A2_COMPOSITE_UNKNOWN;gpu_model_depth_configure((code&64)!=0);
    assert(!model_depth_plane_valid&&!model_depth_has_samples);
    g.dax1=g.day1=0;g.dax2=g.day2=31;
    cur_tpage=0x100|(((code/2)%4)<<5);cur_clut=0;g.texwin=0;
    hd_matches_reset();art_fixture=portrait_fixture=0;
    int hd=(code&8)!=0,perspective=(code&16)!=0;
    hd_sample_fixture=hd?2:0;hd_plate_count=hd?1:0;
    hd_sample_value=(A2HDUISample){.background=0x9c7b,.ink=0x852f,
        .alpha=173,.shadow=0x8000,.shadow_alpha=97};
    for(unsigned i=0;i<1024*512;i++)GPU_VRAM[i]=i%13?(uint16_t)(i*9173u+0x582bu):0;
    size_t count=(size_t)IR_W*IR_H;
    uint16_t *native=malloc(sizeof GPU_VRAM),*fine=malloc(count*sizeof *fine);
    uint32_t *rgb=malloc(count*sizeof *rgb);assert(native&&fine&&rgb);
    memcpy(native,GPU_VRAM,sizeof GPU_VRAM);
    for(size_t i=0;i<count;i++){SHADOW[i]=0x1931;SHADOW_RGB[i]=0xff352719u;}
    Vtx vertices[3]={{0,0,7,19,37,0,0},{0,0,253,231,197,31,0},
                     {0,0,83,127,179,0,31}};
    for(unsigned i=1;i<3;i++) {
        if(constant&1)vertices[i].r=vertices[0].r;
        if(constant&2)vertices[i].gr=vertices[0].gr;
        if(constant&4)vertices[i].b=vertices[0].b;
    }
    WorldFineTriangle triangle={{{-16384,32768},{31*65536+8192,32768},{-16384,31*65536+16384}}};
    if(code&32){Vtx v=vertices[1];vertices[1]=vertices[2];vertices[2]=v;
        WorldFinePoint p=triangle.p[1];triangle.p[1]=triangle.p[2];triangle.p[2]=p;}
    fine_uv_polygon(vertices,3);
    double z[3]={1.0/37,1.0/613,1.0/971};
    const double *depth=perspective?z:NULL;
    mixed_hd_hits=mixed_hd_misses=0;
    int semi=code%5!=0;
    reference_world_fine(vertices[0],vertices[1],vertices[2],triangle,1,1,semi,(int)scale,depth);
    unsigned hits=mixed_hd_hits,misses=mixed_hd_misses;
    if(hd&&!perspective){assert(hits&&misses);hd_checks++;}
    memcpy(fine,SHADOW,count*sizeof *fine);memcpy(rgb,SHADOW_RGB,count*sizeof *rgb);
    assert(!memcmp(native,GPU_VRAM,sizeof GPU_VRAM));
    /* Restore all three surfaces, including the precise background for blend. */
    memcpy(GPU_VRAM,native,sizeof GPU_VRAM);
    for(size_t i=0;i<count;i++){SHADOW[i]=0x1931;SHADOW_RGB[i]=0xff352719u;}
    mixed_hd_hits=mixed_hd_misses=0;
    raster_tri_world_fine(vertices[0],vertices[1],vertices[2],triangle,1,1,semi,(int)scale,depth);
    if(memcmp(rgb,SHADOW_RGB,count*sizeof *rgb))fprintf(stderr,"888 mismatch IR%u code%u\n",scale,code);
    assert(!memcmp(rgb,SHADOW_RGB,count*sizeof *rgb));
    assert(!memcmp(fine,SHADOW,count*sizeof *fine));
    assert(!memcmp(native,GPU_VRAM,sizeof GPU_VRAM));
    assert(hits==mixed_hd_hits&&misses==mixed_hd_misses);
    free(rgb);free(fine);free(native);checks++;
}
int main(void) {
    int old_round=fegetround();assert(!fesetround(FE_TONEAREST));
    setenv("A2_COLOR_PRECISION","1",1);
    for(unsigned scale=2;scale<=4;scale++) {
        for(unsigned code=0;code<128;code++)differential(scale,code,(code/4)&7);
        /* Separate the channel mask from HD/perspective mode bits: all
         * three channels must vary in these two additional cases. */
        differential(scale,8,0);
        differential(scale,16,0);
        differential(scale,72,0);
        differential(scale,80,0);
    }
    assert(!fesetround(old_round));
    printf("PASS: %u full888/555/native frozen-raster comparisons; %u alternatingHD Gouraud cases, depth disabled/enabled-after-barrier, all constant-channel masks, perspective, winding, filter and blend modes\n",checks,hd_checks);
    return 0;
}
