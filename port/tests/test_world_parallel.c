#define main unused_mesh_fixture_main
#include "test_gpu_native_mesh.c"
#undef main
#include "reference_world_fine.inc"
#include <fenv.h>
#ifndef A2_FINE_PARALLEL_SUPPORT
static uint64_t fine_parallel_dispatches;
#endif
static unsigned checks;
static void differential(unsigned scale,unsigned mode,int filtered,int semi,int reverse,int retained,int perspective) {
    gpu_set_ir(scale);gpu_gp1(0);gpu_set_filter(filtered);assert(gpu_display_argb_row(0));
    a2_mesh_live_enabled=a2_mesh_live_active=a2_mesh_live_writes_watched=0;
    mesh_pixel_kind=A2_COMPOSITE_UNKNOWN;gpu_model_depth_configure(1);
    g.dax1=3;g.day1=5;g.dax2=159;g.day2=119;
    cur_tpage=15|(mode<<7)|((checks%4)<<5);cur_clut=63;g.texwin=checks%2?0x32867:0;
    hd_matches_reset();art_fixture=portrait_fixture=hd_sample_fixture=0;
    for(unsigned i=0;i<1024*512;i++)GPU_VRAM[i]=i%13?(uint16_t)(i*9173u+0x582bu):0;
    size_t count=(size_t)IR_W*IR_H;uint16_t *native=malloc(sizeof GPU_VRAM),*fine=malloc(count*2);uint32_t *rgb=malloc(count*4);assert(native&&fine&&rgb);
    memcpy(native,GPU_VRAM,sizeof GPU_VRAM);
    size_t dn=(size_t)320*432*scale*scale;
    if(model_depth_count<dn){free(model_depth_pixels);model_depth_pixels=calloc(dn,sizeof *model_depth_pixels);model_depth_count=dn;}
    model_depth_scale=scale;model_depth_has_samples=retained;
    model_depth_plane_valid=retained==2;model_depth_owner=123;model_depth_face=5;
    model_depth_plane[0]=model_depth_plane[1]=0;model_depth_plane[2]=.009;
    model_depth_bounds[0]=(typeof(model_depth_bounds[0])){retained,0,0,320*(int)scale-1,216*(int)scale-1};
    model_depth_bounds[1].valid=0;
    ModelDepthPixel *saved=malloc(dn*sizeof *saved);assert(saved);
    Vtx v[3]={{0,0,7,19,37,2,1},{0,0,253,231,197,247,9},{0,0,83,127,179,5,237}};
    WorldFineTriangle t={{{-16384,32768},{159*65536+8192,32768},{-16384,119*65536+16384}}};
    if(reverse){Vtx z=v[1];v[1]=v[2];v[2]=z;WorldFinePoint p=t.p[1];t.p[1]=t.p[2];t.p[2]=p;}
    fine_uv_polygon(v,3);
    double inverse[3]={1.0/37,1.0/613,1.0/971};const double *depth=perspective?inverse:NULL;
    uint64_t dispatched_before=fine_parallel_dispatches;
    for(unsigned pass=0;pass<2;pass++) {
        for(size_t i=0;i<count;i++){SHADOW[i]=0x1931;SHADOW_RGB[i]=0xff352719u;}
        for(size_t i=0;i<dn;i++)model_depth_pixels[i]=(ModelDepthPixel){.inverse_z=.01,.owner=123,.stamp=retained?model_depth_stamp:0,.face=4};
        if(!pass) {
            reference_world_fine(v[0],v[1],v[2],t,1,1,semi,scale,depth);
            memcpy(fine,SHADOW,count*2);memcpy(rgb,SHADOW_RGB,count*4);memcpy(saved,model_depth_pixels,dn*sizeof *saved);
        } else {
            raster_tri_world_fine(v[0],v[1],v[2],t,1,1,semi,scale,depth);
            assert(!memcmp(fine,SHADOW,count*2));assert(!memcmp(rgb,SHADOW_RGB,count*4));
            for(size_t i=0;i<dn;i++)assert(saved[i].stamp==model_depth_pixels[i].stamp);
        }
        assert(!memcmp(native,GPU_VRAM,sizeof GPU_VRAM));
    }
    if(retained==2)assert(fine_parallel_dispatches==dispatched_before);
    free(native);free(fine);free(rgb);free(saved);checks++;
}
int main(void) {
    assert(!fesetround(FE_TONEAREST));setenv("A2_COLOR_PRECISION","1",1);setenv("A2_FINE_PARALLEL","1",1);
    for(unsigned scale=2;scale<=4;scale++)for(unsigned mode=0;mode<4;mode++)for(unsigned f=0;f<2;f++)for(unsigned ret=0;ret<2;ret++)
        differential(scale,mode,f,(checks%3)!=0,checks%2,ret,0);
    for(unsigned scale=2;scale<=4;scale++)for(unsigned f=0;f<2;f++)differential(scale,2,f,1,f,1,1);
    for(unsigned f=0;f<2;f++)differential(4,2,f,0,f,2,0);
    if(!fine_parallel_dispatches){fputs("FAIL: large ordinary polygons never dispatched concurrent row slices\n",stderr);return 1;}
    printf("PASS%u full555/RGB/native/depth-retirement comparisons; %llu parallel dispatches\n",checks,(unsigned long long)fine_parallel_dispatches);return 0;
}
