/* Real production GP0/fine paths against the same CPU path, including
 * deferred ordering and native post-pass texture snapshots. */
#define A2_GPU_FINE 1
#define main unused_mesh_fixture_main
#include "test_gpu_native_mesh.c"
#undef main
static int runtime_xoff,runtime_yoff,runtime_textured=1,runtime_divisor=1,runtime_uvscale=1;
static void seed_surfaces(void) {
    fine_gpu_sync();
    for(unsigned i=0;i<1024*512;i++)GPU_VRAM[i]=(i%13)?(uint16_t)(i*9173u+0x582bu):0;
    for(size_t i=0;i<(size_t)IR_W*IR_H;i++){SHADOW[i]=0x1931;SHADOW_RGB[i]=0xff352719u;}
    fine_gpu_written(0,0,1024,512);
    gpu_model_depth_barrier();mesh_pixel_kind=A2_COMPOSITE_UNKNOWN;
    hd_matches_reset();g.dax1=g.day1=0;g.dax2=95;g.day2=71;g.ofx=g.ofy=0;
    runtime_xoff=runtime_yoff=0;runtime_textured=runtime_divisor=runtime_uvscale=1;
}
static void runtime_triangle(int precise,int semi,int reverse) {
    Vtx a={2,3,31,83,127,1,2},b={90,8,239,113,71,35,3},c={7,67,79,223,157,3,47};
    WorldFineTriangle t={{{2*65536+16384,3*65536+32768},{90*65536+8192,8*65536},{7*65536,67*65536+8192}}};
    a.x/=runtime_divisor;b.x/=runtime_divisor;c.x/=runtime_divisor;
    a.y/=runtime_divisor;b.y/=runtime_divisor;c.y/=runtime_divisor;
    a.u*=runtime_uvscale;b.u*=runtime_uvscale;c.u*=runtime_uvscale;
    a.v*=runtime_uvscale;b.v*=runtime_uvscale;c.v*=runtime_uvscale;
    for(unsigned i=0;i<3;i++){t.p[i].x/=runtime_divisor;t.p[i].y/=runtime_divisor;}
    a.x+=runtime_xoff;b.x+=runtime_xoff;c.x+=runtime_xoff;
    a.y+=runtime_yoff;b.y+=runtime_yoff;c.y+=runtime_yoff;
    for(unsigned i=0;i<3;i++){t.p[i].x+=(int64_t)runtime_xoff*65536;t.p[i].y+=(int64_t)runtime_yoff*65536;}
    fine_uv_polygon((Vtx[]){a,b,c},3);
    if(reverse){Vtx v=b;b=c;c=v;WorldFinePoint p=t.p[1];t.p[1]=t.p[2];t.p[2]=p;}
    raster_tri_internal(a,b,c,1,runtime_textured,semi,precise?&t:NULL,NULL,NULL);
}
static void sequence(unsigned mode,int precise,int filtered) {
    cur_tpage=12|(mode<<7)|((mode%4)<<5);cur_clut=63;g.texwin=mode==1?0x32867:0;gpu_set_filter(filtered);
    runtime_triangle(precise,0,0);runtime_triangle(precise,1,1);
    /* Overwrite the whole texture source while older snapshots are leased. */
    for(unsigned y=0;y<256;y++)for(unsigned x=768;x<1024;x++)GPU_VRAM[y*1024+x]^=0x5294;
    fine_gpu_written(768,0,256,256);
    runtime_triangle(precise,1,0);
    /* A real ordered sprite forces previous triangles before its CPU write. */
    gpu_gp0(0x62172941);gpu_gp0((19u<<16)|13u);gpu_gp0((11u<<16)|27u);
    cur_tpage=12|(mode<<7)|((mode%4)<<5);cur_clut=63;
    runtime_triangle(precise,1,1);
    (void)gpu_display_argb_row(0); /* Public consumer drains pending raster. */
    runtime_triangle(precise,1,0);
    gpu_gp0(0x02372b19);gpu_gp0((21u<<16)|16u);gpu_gp0((9u<<16)|32u);
    runtime_triangle(precise,1,1);
    gpu_gp0(0x80000000);gpu_gp0((4u<<16)|3u);gpu_gp0(768u);gpu_gp0((16u<<16)|32u);
    runtime_triangle(precise,1,0);
    gpu_gp0(0xa0000000);gpu_gp0((12u<<16)|780u);gpu_gp0((2u<<16)|4u);
    for(unsigned i=0;i<4;i++)gpu_gp0(0x81239487u+i);
    runtime_triangle(precise,1,1);
    /* A partial upload must remain dirty if GP1 aborts its payload. */
    gpu_gp0(0xa0000000);gpu_gp0((15u<<16)|790u);gpu_gp0((2u<<16)|4u);
    gpu_gp0(0xf781def3);gpu_gp1(0);
    g.dax1=g.day1=0;g.dax2=95;g.day2=71;g.ofx=g.ofy=0;
    cur_tpage=(mode<<7);cur_clut=63;
    /* Feedback texture page overlaps both consecutive native destinations:
     * the second fine pass must use its own post-native snapshot. */
    runtime_triangle(precise,0,0);runtime_triangle(precise,1,1);
    (void)gpu_display_row(0);
}
static void minify_sequence(unsigned mode,int transparent) {
    /* A GPU base supplies color to the exact existing minified material.
     * Use both zero and patterned sources; a transparent footprint must
     * preserve its certificate for the following queued overlay. */
    gpu_set_filter(1);gpu_model_depth_barrier();model_depth_stamp=109;
    memset(model_depth_pixels,0,model_depth_count*sizeof *model_depth_pixels);
    if(model_minify_key_count!=model_depth_count){free(model_minify_keys);model_minify_keys=calloc(model_depth_count,sizeof *model_minify_keys);assert(model_minify_keys);model_minify_key_count=model_depth_count;}
    memset(model_minify_keys,0,model_minify_key_count*sizeof *model_minify_keys);
    if(transparent){memset(GPU_VRAM,0,sizeof GPU_VRAM);fine_gpu_written(0,0,1024,512);}
    runtime_divisor=2;runtime_uvscale=5;runtime_xoff=runtime_yoff=0;
    g.dax1=g.day1=0;g.dax2=95;g.day2=71;
    cur_tpage=12|(mode<<7);cur_clut=63;g.texwin=0;
    model_depth_plane[0]=model_depth_plane[1]=0;model_depth_plane[2]=1.0/40;
    model_depth_plane_valid=1;model_depth_owner=77;model_depth_face=19;
    model_minify_tracking=1;model_minify_write=7;model_minify_pair=0;
    runtime_textured=0;runtime_triangle(1,0,0);
    model_minify_pair=7;model_minify_write=0;runtime_textured=1;
    runtime_triangle(1,0,0);runtime_triangle(1,0,0);
    (void)gpu_display_row(0);model_minify_pair=0;model_minify_tracking=0;
}
static void depth_sequence(unsigned mode,int precise,int filtered) {
    size_t count=(size_t)320*432*IR*IR;
    if(model_depth_count!=count){free(model_depth_pixels);model_depth_pixels=calloc(count,sizeof *model_depth_pixels);assert(model_depth_pixels);}
    model_depth_count=count;model_depth_scale=IR;
    memset(model_depth_pixels,0,count*sizeof *model_depth_pixels);
    gpu_model_depth_barrier();model_depth_stamp=101;
    model_depth_owner=77;model_depth_face=19;model_depth_camera=(ModelDepthCamera){0};
    model_depth_camera.source_family=A2_ACTOR_GAME00;model_depth_root_q12[0]=77;
    memset(&fixture_owner,0,sizeof fixture_owner);
    runtime_yoff=mode==1?256:0;runtime_xoff=mode==2?280:0;
    g.day1=runtime_yoff;g.day2=runtime_yoff+71;g.dax1=runtime_xoff;g.dax2=runtime_xoff+95;
    cur_tpage=12|(mode<<7)|((mode%4)<<5);cur_clut=63;g.texwin=mode==1?0x32867:0;gpu_set_filter(filtered);
    model_depth_plane[0]=1e-8;model_depth_plane[1]=-1e-8;model_depth_plane[2]=1.0/40;
    model_depth_plane_valid=1;runtime_triangle(precise,0,0);
    model_depth_plane[2]=1.0/90;runtime_triangle(precise,1,1);
    /* Different native alpha after the original owner: only actual writes
     * retire coverage, even while all fine color remains queued. */
    for(unsigned y=0;y<256;y++)for(unsigned x=768;x<1024;x++)GPU_VRAM[y*1024+x]^=0x5294;
    fine_gpu_written(768,0,256,256);
    model_depth_plane_valid=0;runtime_triangle(precise,1,0);
    model_depth_plane_valid=1;model_depth_plane[2]=1.0/110;runtime_triangle(precise,0,1);
    /* Same-camera ground shadows use the unchanged physical-plane oracle. */
    memset(model_shadow_triangles,0,sizeof model_shadow_triangles);
    model_shadow_triangles[0].valid=1;model_shadow_triangles[0].plane[2]=1.0/200;
    memset(&model_shadow_geometry,0,sizeof model_shadow_geometry);
    model_shadow_camera_owner=0;model_depth_ground_shadow=1;runtime_triangle(precise,1,0);
    model_depth_ground_shadow=0;model_depth_plane[2]=1.0/30;runtime_triangle(precise,0,0);
    model_minify_pair=7; /* Pair metadata alone does not imply minified shading. */
    runtime_textured=0;model_depth_plane[2]=1.0/60;runtime_triangle(precise,1,1);
    model_depth_plane[2]=NAN;runtime_triangle(precise,0,0);
    runtime_textured=1;
    model_minify_pair=0;
    (void)gpu_display_row(0);
}
int main(void) {
    const double offsets[]={0,0.5,-0.5,1,-1,2.75,-2.75,65280,-65280,1e20,-1e20,1+0x1p-40,-1-0x1p-40,NAN};
    for(unsigned i=0;i<sizeof offsets/sizeof *offsets;i++) {
        ModelMinifyFootprint source={.count=2};source.u[0]=source.v[0]=source.u[1]=source.v[1]=offsets[i];
        A2FineMinify converted;
        int accepted=fine_gpu_minify_offsets(&source,&converted);
        if(i>=11){assert(!accepted);continue;}assert(accepted);
        for(int u=0;u<=65280;u++) {
            double original=u+offsets[i];if(original<0)original=0;if(original>65280)original=65280;
            int actual=u+converted.offsets[0][0];if(actual<0)actual=0;if(actual>65280)actual=65280;
            assert(actual==(int)floor(original));
        }
    }
    setenv("A2_GPU_FINE","1",1);setenv("A2_COLOR_PRECISION","1",1);
    setenv("A2_IRSCALE","2",1);setenv("A2_FINE_PARALLEL","0",1);
    gpu_ir();fine_gpu_start();if(!fine_gpu){fputs("Metal fine backend unavailable\n",stderr);return 77;}
    a2_mesh_live_enabled=a2_mesh_live_active=a2_mesh_live_writes_watched=0;
    gpu_model_depth_configure(1);art_fixture=portrait_fixture=hd_sample_fixture=0;
    unsigned cases=0;
    for(int scale=2;scale<=4;scale++) {
        gpu_set_ir(scale);fine_gpu_start();assert(fine_gpu);
        size_t n=(size_t)IR_W*IR_H;
        uint16_t *fine=malloc(n*2),*native=malloc(sizeof GPU_VRAM);uint32_t *rgb=malloc(n*4);assert(fine&&rgb&&native);
        for(unsigned mode=0;mode<3;mode++)for(int precise=0;precise<=1;precise++)for(int filtered=0;filtered<=1;filtered++) {
            seed_surfaces();A2FineGpu *saved=fine_gpu;fine_gpu=NULL;fine_gpu_requested=0;
            sequence(mode,precise,filtered);
            memcpy(fine,SHADOW,n*2);memcpy(rgb,SHADOW_RGB,n*4);memcpy(native,GPU_VRAM,sizeof GPU_VRAM);
            assert(!fine_gpu&&!fine_gpu_pending);fine_gpu_requested=1;fine_gpu=saved;seed_surfaces();A2FineGpuStats before=a2_fine_gpu_stats(fine_gpu);
            sequence(mode,precise,filtered);A2FineGpuStats after=a2_fine_gpu_stats(fine_gpu);
            if(after.triangles!=before.triangles+10||after.submissions!=before.submissions+7+after.capacity_rejections-before.capacity_rejections)
                fprintf(stderr,"ordinary queue scale=%d mode=%u precise=%d filter=%d triangles=%llu submissions=%llu capacity=%llu\n",scale,mode,precise,filtered,(unsigned long long)(after.triangles-before.triangles),(unsigned long long)(after.submissions-before.submissions),(unsigned long long)(after.capacity_rejections-before.capacity_rejections));
            assert(after.triangles==before.triangles+10 && after.submissions==before.submissions+7+after.capacity_rejections-before.capacity_rejections);
            assert(!memcmp(native,GPU_VRAM,sizeof GPU_VRAM));
            if(memcmp(fine,SHADOW,n*2)||memcmp(rgb,SHADOW_RGB,n*4)) {
                for(size_t i=0;i<n;i++)if(fine[i]!=SHADOW[i]||rgb[i]!=SHADOW_RGB[i]) {
                    fprintf(stderr,"fine mismatch scale=%d mode=%u precise=%d filter=%d xy=%zu,%zu 555=%04x/%04x rgb=%08x/%08x\n",scale,mode,precise,filtered,i%IR_W,i/IR_W,fine[i],SHADOW[i],rgb[i],SHADOW_RGB[i]);break;
                }
                abort();
            }
            cases++;
            seed_surfaces();saved=fine_gpu;fine_gpu=NULL;fine_gpu_requested=0;
            model_depth_rejected=0;depth_sequence(mode,precise,filtered);
            memcpy(fine,SHADOW,n*2);memcpy(rgb,SHADOW_RGB,n*4);memcpy(native,GPU_VRAM,sizeof GPU_VRAM);
            ModelDepthPixel *depth=malloc(model_depth_count*sizeof *depth);assert(depth);
            memcpy(depth,model_depth_pixels,model_depth_count*sizeof *depth);
            uint64_t rejected=model_depth_rejected;int has_samples=model_depth_has_samples;
            assert(!fine_gpu&&!fine_gpu_pending);fine_gpu_requested=1;fine_gpu=saved;seed_surfaces();
            before=a2_fine_gpu_stats(fine_gpu);model_depth_rejected=0;
            depth_sequence(mode,precise,filtered);after=a2_fine_gpu_stats(fine_gpu);
            uint64_t batches=1+after.capacity_rejections-before.capacity_rejections;
            if(after.triangles!=before.triangles+8||after.submissions!=before.submissions+batches)
                fprintf(stderr,"depth queue scale=%d mode=%u precise=%d filter=%d triangles=%llu submissions=%llu fallbacks=%llu/%llu/%llu/%llu\n",scale,mode,precise,filtered,
                    (unsigned long long)(after.triangles-before.triangles),(unsigned long long)(after.submissions-before.submissions),
                    (unsigned long long)fine_gpu_fallbacks[0],(unsigned long long)fine_gpu_fallbacks[1],(unsigned long long)fine_gpu_fallbacks[2],(unsigned long long)fine_gpu_fallbacks[3]);
            assert(after.triangles==before.triangles+8 && after.submissions==before.submissions+batches);
            assert(!memcmp(native,GPU_VRAM,sizeof GPU_VRAM));
            assert(!memcmp(fine,SHADOW,n*2)&&!memcmp(rgb,SHADOW_RGB,n*4));
            assert(!memcmp(depth,model_depth_pixels,model_depth_count*sizeof *depth));
            assert(has_samples==model_depth_has_samples&&rejected==model_depth_rejected);
            free(depth);cases++;
            if(precise&&filtered)for(int transparent=0;transparent<2;transparent++) {
                seed_surfaces();saved=fine_gpu;fine_gpu=NULL;fine_gpu_requested=0;
                minify_sequence(mode,transparent);
                memcpy(fine,SHADOW,n*2);memcpy(rgb,SHADOW_RGB,n*4);memcpy(native,GPU_VRAM,sizeof GPU_VRAM);
                uint64_t *keys=malloc(model_minify_key_count*sizeof *keys);assert(keys);
                memcpy(keys,model_minify_keys,model_minify_key_count*sizeof *keys);
                depth=malloc(model_depth_count*sizeof *depth);assert(depth);
                memcpy(depth,model_depth_pixels,model_depth_count*sizeof *depth);
                assert(!fine_gpu&&!fine_gpu_pending);fine_gpu_requested=1;fine_gpu=saved;seed_surfaces();before=a2_fine_gpu_stats(fine_gpu);
                minify_sequence(mode,transparent);after=a2_fine_gpu_stats(fine_gpu);
                assert(after.triangles==before.triangles+3);
                assert(after.submissions==before.submissions+1+after.capacity_rejections-before.capacity_rejections);
                assert(!memcmp(native,GPU_VRAM,sizeof GPU_VRAM));
                assert(!memcmp(fine,SHADOW,n*2)&&!memcmp(rgb,SHADOW_RGB,n*4));
                assert(!memcmp(keys,model_minify_keys,model_minify_key_count*sizeof *keys));free(keys);
                assert(!memcmp(depth,model_depth_pixels,model_depth_count*sizeof *depth));free(depth);cases++;
            }
        }
        free(fine);free(rgb);free(native);
    }
    gpu_set_ir(1);assert(!fine_gpu);
    printf("PASS %u complete real GP0/fine CPU-vs-Metal surfaces: IR2-4, affine/legacy, versions, native feedback, blending, depth masks, paired minification, filters, sprites/fill/copy/upload/abort/display/resize\n",cases);
}
