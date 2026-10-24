/* Perspective diagnostic through real GP0 provenance and rasterization.
 * Run once with A2_WORLD_PERSPECTIVE=1 and once with it absent. */
#define main world_transport_existing_main
#include "test_world_precision_gpu.c"
#undef main
#include <math.h>

typedef struct { int x,y,u,v; double z; } PerspectivePoint;
static uint16_t saved_native[1024*512],saved_shadow[1024*512*16];
static unsigned texture_page=0x104,texture_clut;
static int varied_colors;

static uint32_t pword(int x,int y) {return (uint16_t)x|((uint32_t)(uint16_t)y<<16);}
static uint16_t pattern(int u,int v) {return (uint16_t)(0x4000|(u&31)|((v&31)<<5));}
static void pclear(int scale,int filter) {
    world_precision_configure(1);gpu_set_ir(scale);gpu_gp1(0);gpu_set_world_raster(1);gpu_set_filter(filter);
    memset(GPU_VRAM,0,sizeof GPU_VRAM);
    if(scale>1)memset(SHADOW,0,(size_t)1024*512*scale*scale*sizeof *SHADOW);
    gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|63|(63<<10));
    for(int y=0;y<256;y++)for(int x=0;x<256;x++)GPU_VRAM[y*1024+256+x]=pattern(x,y);
    texture_page=0x104;texture_clut=0;varied_colors=0;
}
static void psubmit(const PerspectivePoint *p,unsigned count,unsigned command,int missing) {
    uint32_t packet[16],src[4],dst[4],words[4],base=0x800b0000;
    unsigned n=0;uint64_t object=world_precision_begin_object();
    const unsigned colors[]={0x808040,0x408080,0x804080,0x606060};
    packet[n++]=(command<<24)|(varied_colors?colors[0]:0x808080);
    for(unsigned i=0;i<count;i++) {
        if(i)packet[n++]=varied_colors?colors[i]:0x808080;
        words[i]=pword(p[i].x,p[i].y);src[i]=0x1f800100+i*16;dst[i]=base+n*4;
        packet[n++]=words[i];packet[n++]=(uint32_t)p[i].u|((uint32_t)p[i].v<<8)|
            (i==1?texture_page<<16:i==0?texture_clut<<16:0);
        world_precision_vertex value;
        world_precision_gte_push(words[i],(int64_t)p[i].x*65536,(int64_t)p[i].y*65536,900,1);
        assert(world_precision_gte_read(14,words[i],&value));
        /* Inject malformed depth after valid projection, preserving valid XY
         * provenance. The UV gate must independently reject this metadata. */
        value.z=p[i].z;world_precision_record(src[i],words[i],object,&value);
    }
    assert(world_precision_emit(dst,words,src,count,object));
    for(unsigned i=0;i<n;i++) {
        if(missing>=0&&base+i*4==dst[missing])gpu_gp0(packet[i]);
        else gpu_gp0_at(packet[i],base+i*4);
    }
}
static void centroid(int scale,int filter,int reversed,int enabled) {
    PerspectivePoint p[]={{4,4,0,0,1},{28,4,255,0,2},{4,28,0,255,4}};
    if(reversed){PerspectivePoint t=p[1];p[1]=p[2];p[2]=t;}
    pclear(scale,filter);psubmit(p,3,0x35,-1);
    assert(world_primitive_valid);
    assert(GPU_VRAM[12*1024+12]==pattern(85,85));
    if(scale==1)return;
    /* At the screen centroid, independent rational result is U=510/7,
     * V=255/7. Quantized Q8 values are18651 and9325, not affine85/85. */
    uint16_t expected=enabled?(filter?sample_tex_fine(18651-128,9325-128):pattern(72,36)):
        (filter?sample_tex_fine(85*256-128,85*256-128):pattern(85,85));
    uint16_t got=gpu_display_px(12*scale,12*scale);
    if(got!=expected)fprintf(stderr,"centroid IR%d filter%d reverse%d: got%04x expected%04x\n",scale,filter,reversed,got,expected);
    assert(got==expected);
}
static void quad_fallback_and_equal(int scale,int filter) {
    PerspectivePoint p[]={{4,4,0,0,900},{28,4,255,0,900},{4,28,0,255,900},{28,28,255,255,900}};
    pclear(scale,filter);psubmit(p,4,0x3d,-1);
    memcpy(saved_native,GPU_VRAM,sizeof saved_native);
    if(scale>1)memcpy(saved_shadow,SHADOW,(size_t)1024*512*scale*scale*sizeof *SHADOW);
    const double bad[]={0,-1,NAN,INFINITY,1e-300,65536};
    for(unsigned b=0;b<sizeof bad/sizeof bad[0];b++)for(unsigned corner=0;corner<4;corner++) {
        p[0].z=1;p[1].z=2;p[2].z=4;p[3].z=8;p[corner].z=bad[b];
        pclear(scale,filter);psubmit(p,4,0x3d,-1);
        assert(world_primitive_valid); /* Bad Z must not discard valid fine XY. */
        assert(!memcmp(saved_native,GPU_VRAM,sizeof saved_native));
        if(scale>1)assert(!memcmp(saved_shadow,SHADOW,(size_t)1024*512*scale*scale*sizeof *SHADOW));
    }
    /* A missing fourth source is whole-primitive fallback, including the
     * first half whose three provenance entries happen to be valid. */
    p[0].z=1;p[1].z=2;p[2].z=4;p[3].z=8;
    pclear(scale,filter);psubmit(p,4,0x3d,3);
    assert(!world_primitive_valid);assert(!memcmp(saved_native,GPU_VRAM,sizeof saved_native));
    if(scale>1)assert(!memcmp(saved_shadow,SHADOW,(size_t)1024*512*scale*scale*sizeof *SHADOW));
}
static void planar_quad(int scale,int reversed,int enabled) {
    /* Perspective projection of a planar tilted rectangle. At screen(16,16),
     * homogeneous UV is(1/2,1/2), whereas affine V is2/3. */
    PerspectivePoint p[]={{4,4,0,0,1},{28,4,240,0,1},{10,22,0,240,2},{22,22,240,240,2}};
    if(reversed){PerspectivePoint t=p[1];p[1]=p[2];p[2]=t;}
    pclear(scale,0);psubmit(p,4,0x3d,-1);
    uint16_t got=gpu_display_px(16*scale,16*scale);
    if(enabled&&scale>1)assert(got==pattern(120,120));
    else assert(got!=pattern(120,120));
}
static void texture_formats(int mode,int filter,int enabled,int window) {
    PerspectivePoint p[]={{4,4,0,0,1},{28,4,255,0,2},{4,28,0,255,4}};
    pclear(3,filter);
    if(mode<2) {
        texture_page=4|((unsigned)mode<<7);texture_clut=300<<6;
        unsigned entries=mode==0?16:256;
        for(unsigned i=0;i<entries;i++)GPU_VRAM[300*1024+i]=(uint16_t)(0x4000|i);
        for(unsigned y=0;y<256;y++)for(unsigned x=0;x<(mode==0?64u:128u);x++) {
            unsigned value=0;
            for(unsigned k=0;k<(mode==0?4u:2u);k++) {
                unsigned index=(x*(mode==0?4u:2u)+k+y*3)&(entries-1);
                value|=index<<(k*(mode==0?4u:8u));
            }
            GPU_VRAM[y*1024+256+x]=(uint16_t)value;
        }
    }
    if(window)gpu_gp0(0xe2000000|1|(2<<5)|(1<<10)|(2<<15));
    psubmit(p,3,0x35,-1);
    uint16_t expected=enabled?(filter?sample_tex_fine(18651-128,9325-128):sample_tex(72,36)):
        (filter?sample_tex_fine(85*256-128,85*256-128):sample_tex(85,85));
    assert(gpu_display_px(36,36)==expected);
}
static void constant_uv_color_and_semi(int mode) {
    PerspectivePoint p[]={{4,4,32,32,900},{28,4,32,32,900},{4,28,32,32,900},{28,28,32,32,900}};
    for(int pass=0;pass<2;pass++) {
        pclear(4,0);varied_colors=1;texture_page=0x104|((unsigned)mode<<5);
        GPU_VRAM[32*1024+256+32]=0xbdef; /* Genuine STP texel. */
        for(int y=0;y<64;y++)for(int x=0;x<64;x++) {
            GPU_VRAM[y*1024+x]=0x2108;
            for(int dy=0;dy<4;dy++)for(int dx=0;dx<4;dx++)*shadow_px(x*4+dx,y*4+dy)=0x2108;
        }
        psubmit(p,4,0x3e,-1);
        if(!pass) {memcpy(saved_native,GPU_VRAM,sizeof saved_native);memcpy(saved_shadow,SHADOW,sizeof saved_shadow);}
        else {assert(!memcmp(saved_native,GPU_VRAM,sizeof saved_native));assert(!memcmp(saved_shadow,SHADOW,sizeof saved_shadow));}
        p[0].z=1;p[1].z=2;p[2].z=4;p[3].z=8;
    }
}
int main(void) {
    int enabled=getenv("A2_WORLD_PERSPECTIVE")&&!strcmp(getenv("A2_WORLD_PERSPECTIVE"),"1");
    for(int scale=1;scale<=4;scale++)for(int filter=0;filter<=1;filter++) {
        for(int reversed=0;reversed<=1;reversed++)centroid(scale,filter,reversed,enabled);
        quad_fallback_and_equal(scale,filter);
    }
    for(int scale=1;scale<=4;scale++)for(int reversed=0;reversed<=1;reversed++)planar_quad(scale,reversed,enabled);
    for(int mode=0;mode<3;mode++)for(int filter=0;filter<2;filter++)for(int window=0;window<2;window++)texture_formats(mode,filter,enabled,window);
    for(int mode=0;mode<4;mode++)constant_uv_color_and_semi(mode);
    puts("PASS: analytical perspective centroid/planar quad, affine default, native VRAM, equal/invalid depth, palette formats/window, constant-UV Gouraud and STP blending");
    return 0;
}
