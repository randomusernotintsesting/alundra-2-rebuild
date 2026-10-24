/* Real GP0 + fine raster. The sealed packet API has its own retained-emitter
 * tests; here its immutable records describe a fully specified material pair. */
#include <stdlib.h>
static void *test_key_calloc(size_t,size_t);
#define A2_MODEL_MINIFY_CALLOC test_key_calloc
#define main native_mesh_fixture_main
#include "test_gpu_native_mesh.c"
#undef main
static int key_allocation_fails;
static void *test_key_calloc(size_t count,size_t size) {
    assert(count==model_depth_count && size==sizeof(uint64_t));
    return key_allocation_fails?NULL:calloc(count,size);
}

static int pair_quad;
static unsigned pair_draws;
static uint64_t pair_object;
static unsigned fault,pattern,uv_slope=16;
static int occluder;
static int gradient_case=-1;
static const int gradients[6][6]={{64,96,3,0,0,0},{64,96,0,3,0,1},
    {64,96,3,1,1,6},{64,96,6,2,-2,6},{192,192,-6,2,2,-6},{128,64,3,-2,2,3}};
#include "model_minify_expected.inc"
enum {QUAD=1,BASE_SEMI,BASE_TEXTURED,OVERLAY_SEMI,OWNER,SUBMISSION,ENTITY,PART,FACE,
      LINK,PREFIX_VALUE,PREFIX_ADDRESS,NO_PREFIX,NOP,ACK,STREAM,POLYLINE,SUBMIT,VBLANK,
      STALE_XY,SHIFT_XY,DIFFERENT_Z,NO_BASE,NO_DEPTH,NO_FILTER,REPLAY,MAGNIFY,
      OPAQUE_FRONT,BARRIER,FIFO_RESET,TEXTURE_WINDOW,LAST_FAULT,
      DIRECT_SEMI,DIRECT_OPAQUE,DIRECT_TRANSPARENT};
static void paired_polygon(int layer) {
    const uint32_t address=layer?0x80091008u:0x80090008u;
    const unsigned corners=pair_quad?4:3;
    const int xs[4]={4,16,4,16},ys[4]={4,4,16,16};
    uint32_t words[12],src[4],dst[4],native[4];unsigned n=0;
    const uint32_t rgb=layer?(gradient_case<0?0x808080u:0x5a93c8u):occluder?0x0010e0u:0x6850c8u;
    unsigned command=(layer?0x34u:0x30u)+(pair_quad?8u:0u);
    if((layer&&fault==OVERLAY_SEMI)||(!layer&&fault==BASE_SEMI))command|=2;
    if(!layer&&fault==BASE_TEXTURED)command|=4;
    words[n++]=command<<24|rgb;
    if(!layer)pair_object=world_precision_begin_object();
    uint64_t object=pair_object;
    for(unsigned j=0;j<corners;j++) {
        if(j)words[n++]=rgb;
        native[j]=xy(xs[j],ys[j]);src[j]=0x1f800100u+16*j;
        dst[j]=address+4*n;words[n++]=native[j];
        if(command&4) {
            unsigned u=32+uv_slope*(xs[j]-4),v=32;
            if(gradient_case>=0) {
                const int *g2=gradients[gradient_case];int dx=(xs[j]-4)*IR,dy=(ys[j]-4)*IR;
                u=(unsigned)(g2[0]+(g2[2]*dx+g2[3]*dy)/2);v=(unsigned)(g2[1]+(g2[4]*dx+g2[5]*dy)/2);
            }
            assert(u<=255&&v<=255);words[n++]=(j==1?0x104u<<16:0u)|u|(v<<8);
        }
        world_precision_vertex vertex={.x=xs[j]+(layer&&fault==SHIFT_XY?.25:0),.y=ys[j],
            .z=occluder?50:layer&&fault==DIFFERENT_Z?101:100,
            .projection_id=1000+object*4+j,.native_word=native[j],
            .producer_pc=0x8001338cu,.projection_kind=WORLD_PROJECTION_CAMERA,
            .camera_generation=object};
        world_precision_record(src[j],native[j],object,&vertex);
    }
    assert(world_precision_emit(dst,native,src,corners,object));
    if(layer&&fault==STALE_XY)world_precision_invalidate(dst[2],4);
    owned=(A2ActorPacket){.owner_handle=77,.submission_sequence=29,.entity_generation=11,
        .dma_base=address&0x1fffffu,.command_address=address&0x1fffffu,
        .previous_head=layer?0xffffffu:0x91000u,.prefix_word=0xe1000104u,
        .source_mesh_index=2,.native_face_index=1,.material_layer=(unsigned)layer,
        .polygon_word_count=n,.dma_word_count=n+1};
    owned.dma_base-=8;
    if(occluder)owned.owner_handle=88;
    if(!layer&&fault==LINK)owned.previous_head+=4;
    if(layer) {
        if(fault==OWNER)owned.owner_handle++;
        if(fault==SUBMISSION)owned.submission_sequence++;
        if(fault==ENTITY)owned.entity_generation++;
        if(fault==PART)owned.source_mesh_index++;
        if(fault==FACE)owned.native_face_index++;
        if(fault==PREFIX_VALUE)owned.prefix_word^=1;
    }
    owned.words[0]=(n+1)<<24|owned.previous_head;owned.words[1]=owned.prefix_word;
    memcpy(owned.words+2,words,4*n);
    owned_token=99;owned_address=address;owned_count=n;memcpy(owned_words,words,4*n);
    if(!(layer&&fault==NO_PREFIX))gpu_gp0_at(layer&&fault==PREFIX_VALUE?owned.prefix_word^1:owned.prefix_word,
        address-4+(layer&&fault==PREFIX_ADDRESS?4:0));
    for(unsigned j=0;j<n;j++)gpu_gp0_at(words[j],address+4*j);
    pair_draws++;
}
typedef struct {uint16_t native[1024*512],fine[80*80];uint32_t rgb[80*80];
    ModelDepthPixel before,after;} Snapshot;
static void run_pair(unsigned scale,unsigned page,int enabled,Snapshot *out) {
    fresh((int)scale,(int)page,0);world_camera_configure(1);
    gpu_model_depth_configure(fault!=NO_DEPTH);gpu_set_filter(fault!=NO_FILTER);
    model_minify_enabled=enabled;pair_draws=0;pair_quad=fault==QUAD;
    for(unsigned y=0;y<80;y++)for(unsigned x=0;x<80;x++)
        SHADOW_RGB[shadow_px((int)x,(int)(page*scale+y))-SHADOW]=display_rgb(0,0,0);
    uv_slope=fault==MAGNIFY?scale:4*scale;
    for(int u=0;u<256;u++)seed_texel(256+u,32,
        pattern==1?0:pattern==2?0x8000:pattern==3?0xffff:(u&1)?0:0x7fff);
    if(gradient_case>=0)for(unsigned v=0;v<256;v++)for(unsigned u=0;u<256;u++)
        seed_texel(256+(int)u,(int)v,(u+3*v)%5==0?0:(uint16_t)((u%32)|((v%32)<<5)|(((u+v)%32)<<10)|0x8000));
    if(fault==OPAQUE_FRONT) {occluder=1;paired_polygon(0);occluder=0;}
    if(fault==NO_BASE)pair_object=world_precision_begin_object();else paired_polygon(0);
    if(fault==NOP)gpu_gp0(0);
    if(fault==ACK)gpu_gp1(0x02000000);
    if(fault==FIFO_RESET)gpu_gp1(0x01000000);
    if(fault==SUBMIT)gpu_scene_submit_complete();
    if(fault==VBLANK)gpu_vblank();
    if(fault==BARRIER)gpu_model_depth_barrier();
    if(fault==TEXTURE_WINDOW)gpu_gp0(0xe2000001);
    if(fault==STREAM) {
        gpu_gp0(0xa0000000);gpu_gp0(xy(900,400));gpu_gp0(xy(1,1));gpu_gp0(0x1111);
    }
    if(fault==POLYLINE) {
        gpu_gp0(0x48001020);gpu_gp0(xy(24,24));gpu_gp0(xy(25,24));gpu_gp0(0x50005000);
    }
    /* The actual fine-writer boundary must invalidate a successful color
     * write even when no additional GP0 command supplies a serial guard. */
    if(fault==DIRECT_SEMI||fault==DIRECT_OPAQUE||fault==DIRECT_TRANSPARENT)
        put_fine_pixel(shadow_px(8*scale,(page+8)*scale),16,200,32,
            fault==DIRECT_SEMI,fault==DIRECT_TRANSPARENT,0,0);
    size_t depth_index=(size_t)((page?216:0)+8)*scale*320*scale+8*scale;
    out->before=model_depth_pixels?model_depth_pixels[depth_index]:(ModelDepthPixel){0};
    paired_polygon(1);
    out->after=model_depth_pixels?model_depth_pixels[depth_index]:(ModelDepthPixel){0};
    if(fault==REPLAY) {
        model_minify_enabled=enabled;
        paired_polygon(1);
    }
    memcpy(out->native,GPU_VRAM,sizeof GPU_VRAM);
    for(unsigned y=0;y<80;y++)for(unsigned x=0;x<80;x++) {
        size_t i=y*80+x,offset=shadow_px((int)x,(int)(page*scale+y))-SHADOW;
        out->fine[i]=SHADOW[offset];out->rgb[i]=SHADOW_RGB[offset];
    }
}
static void two_dimensional_cases(void) {
    static Snapshot off,on;fault=pattern=0;
    for(gradient_case=0;gradient_case<6;gradient_case++)
    for(unsigned scale=2;scale<=4;scale++)for(unsigned page=0;page<=256;page+=256) {
        run_pair(scale,page,0,&off);run_pair(scale,page,1,&on);
        assert(!memcmp(off.native,on.native,sizeof on.native));
        unsigned i=8*scale*80+8*scale;const unsigned *expected=expected_2d[gradient_case][scale-2];
        if(on.fine[i]!=expected[0]||on.rgb[i]!=expected[1])
            fprintf(stderr,"2D case%d IR%u: %04x/%08x expected%04x/%08x\n",gradient_case,scale,on.fine[i],on.rgb[i],expected[0],expected[1]);
        assert(on.fine[i]==expected[0] && on.rgb[i]==expected[1]);
        assert(on.before.owner==77 && on.before.inverse_z>0 && on.before.inverse_z==on.after.inverse_z &&
            on.before.owner==on.after.owner && on.before.stamp==on.after.stamp && on.before.face==on.after.face);
    }
    gradient_case=-1;
}
static void exact_average(void) {
    static Snapshot off,on;
    for(unsigned scale=2;scale<=4;scale++)for(unsigned page=0;page<=256;page+=256)
    for(pattern=0;pattern<4;pattern++) {
        fault=0;run_pair(scale,page,0,&off);run_pair(scale,page,1,&on);
        assert(!memcmp(off.native,on.native,sizeof on.native));
        unsigned index=8*scale*80+8*scale;
        uint16_t expected=pattern==0?(28u|(21u<<5)|(22u<<10)):
            pattern==1?(25u|(10u<<5)|(13u<<10)):pattern==2?0x8000:0xffff;
        uint32_t rgb=pattern==0?display_rgb(224,164,176):pattern==1?display_rgb(200,80,104):
            pattern==2?display_rgb(0,0,0):display_rgb(248,248,248);
        assert(on.fine[index]==expected && on.rgb[index]==rgb);
        if(pattern)assert(!memcmp(off.fine,on.fine,sizeof on.fine)&&!memcmp(off.rgb,on.rgb,sizeof on.rgb));
    }
}
static void fallback_cases(void) {
    static Snapshot off,on;
    pattern=0;
    for(unsigned scale=2;scale<=4;scale++)for(unsigned page=0;page<=256;page+=256)
    for(fault=1;fault<LAST_FAULT;fault++) {
        /* A second texture replay must overwrite the first filtered color.
         * The old path is opaque at some taps and transparent at others;
         * compare the actually overwritten center separately below. */
        if(fault==REPLAY)continue;
        run_pair(scale,page,0,&off);run_pair(scale,page,1,&on);
        if(memcmp(off.fine,on.fine,sizeof on.fine)||memcmp(off.rgb,on.rgb,sizeof on.rgb))
            fprintf(stderr,"fallback mismatch fault=%u IR=%u page=%u\n",fault,scale,page);
        assert(!memcmp(off.native,on.native,sizeof on.native));
        assert(!memcmp(off.fine,on.fine,sizeof on.fine));assert(!memcmp(off.rgb,on.rgb,sizeof on.rgb));
    }
    fault=REPLAY;run_pair(4,0,1,&on);assert(on.fine[32*80+32]==0x7fff);
    for(fault=DIRECT_SEMI;fault<=DIRECT_TRANSPARENT;fault++) {
        run_pair(4,0,1,&on);
        assert(on.fine[32*80+32]==(fault==DIRECT_TRANSPARENT?(28u|(21u<<5)|(22u<<10)):0x7fff));
    }
}
static void allocation_cases(void) {
    static Snapshot off,on;fault=pattern=0;gradient_case=-1;
    const unsigned scales[3]={4,2,4};
    for(unsigned i=0;i<3;i++) {
        run_pair(scales[i],0,1,&on);
        assert(model_minify_key_count==model_depth_count && model_minify_keys && sizeof(ModelDepthPixel)==24);
        assert(on.fine[8*scales[i]*80+8*scales[i]]==(28u|(21u<<5)|(22u<<10)));
    }
    free(model_minify_keys);model_minify_keys=NULL;model_minify_key_count=0;
    key_allocation_fails=1;run_pair(4,0,0,&off);run_pair(4,0,1,&on);
    assert(!model_minify_keys && !model_minify_tracking);
    assert(!memcmp(off.native,on.native,sizeof on.native));
    assert(!memcmp(off.fine,on.fine,sizeof on.fine));assert(!memcmp(off.rgb,on.rgb,sizeof on.rgb));
    key_allocation_fails=0;run_pair(4,0,1,&on);
    assert(on.fine[32*80+32]==(28u|(21u<<5)|(22u<<10)));
    /* A new unrelated GP0 command ends the live certificate immediately. */
    paired_polygon(0);assert(model_minify_tracking);
    gpu_gp0(0);assert(!model_minify_tracking && !model_minify_base.word);
}
int main(void) {
    setenv("A2_COLOR_PRECISION","1",1);setenv("A2_MODEL_MINIFY","1",1);
    static Snapshot image;
    run_pair(4,0,0,&image);assert(!model_minify_keys && !model_minify_key_count);
    run_pair(4,0,1,&image);
    /* At fine(32,32), UV=(96,32), dU/dx=4, dU/dy=0. Four samples
     * (94.5,95.5,96.5,97.5) see two opaque white and two transparent
     * texels. Average independently shaded RGB, not alpha as PS1 semi. */
    uint16_t got=image.fine[32*80+32];
    uint16_t expected=(uint16_t)(28u|(21u<<5)|(22u<<10));
    fprintf(stderr,"material minify RED/GREEN: actual555=%04x expected=%04x draws=%u\n",got,expected,pair_draws);
    assert(got==expected);
    assert(image.rgb[32*80+32]==display_rgb(224,164,176));
    exact_average();fallback_cases();two_dimensional_cases();allocation_cases();
    puts("model_minify: PASS24 color/native,36 independent2D/depth,180 fallback,replay/directwriter; OFF/noallocation,IR4/2/4,allocationfailure/recovery,unrelatedcommandretirement");
    return 0;
}
