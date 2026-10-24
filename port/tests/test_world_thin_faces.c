/* A native zero-area face still has HD coverage. This fixture catches
 * discarding that coverage or rounding the neighboring half of a quad. */
#define main world_transport_existing_main
#include "test_world_precision_gpu.c"
#undef main

static uint16_t raster_native[1024*512],raster_fine[1024*512*16];

typedef struct {
    int x,y;
    int64_t qx,qy;
    uint32_t color;
    unsigned u,v;
} RasterPoint;

static uint32_t raster_pack(int x,int y) {return (uint16_t)x|((uint32_t)(uint16_t)y<<16);}
static void raster_clear(int scale) {
    world_precision_configure(1);gpu_set_ir(scale);gpu_gp1(0);gpu_set_filter(0);
    memset(GPU_VRAM,0,sizeof GPU_VRAM);
    if(scale>1)memset(SHADOW,0,(size_t)1024*512*scale*scale*sizeof *SHADOW);
    gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|319|(223<<10));
    gpu_gp0(0x02ffffff);gpu_gp0(0);gpu_gp0(raster_pack(320,224));
}
static void raster_snapshot(int scale) {
    memcpy(raster_native,GPU_VRAM,sizeof raster_native);
    if(scale>1)memcpy(raster_fine,SHADOW,(size_t)1024*512*scale*scale*sizeof *SHADOW);
}
static void raster_unchanged(int scale,int fine) {
    assert(!memcmp(raster_native,GPU_VRAM,sizeof raster_native));
    if(fine && scale>1)
        assert(!memcmp(raster_fine,SHADOW,(size_t)1024*512*scale*scale*sizeof *SHADOW));
}
static int camera_fixture;
static void raster_submit(const RasterPoint *p,unsigned count,unsigned command,int missing) {
    uint32_t packet[16],source[4],dest[4],words[4],base=0x800b0000;
    unsigned length=0;int tex=(command>>2)&1,gou=(command>>4)&1;
    uint64_t object=world_precision_begin_object();
    packet[length++]=(command<<24)|(p[0].color&0xffffff);
    for(unsigned i=0;i<count;i++) {
        if(gou&&i)packet[length++]=p[i].color;
        words[i]=raster_pack(p[i].x,p[i].y);
        source[i]=0x1f800000+i*12;dest[i]=base+length*4;
        packet[length++]=words[i];
        if(tex)packet[length++]=p[i].u|(p[i].v<<8)|(i==1?0x01040000:0);
        world_precision_vertex value;
        world_precision_gte_push(words[i],p[i].qx,p[i].qy,900,1);
        assert(world_precision_gte_read(14,words[i],&value));
        if(camera_fixture) {
            value.x-=1.0; /* Proven camera coordinate outside its native cell. */
            value.z=900+100*i;
            value.projection_kind=WORLD_PROJECTION_CAMERA;
            value.camera_generation=object;
        }
        world_precision_record(source[i],words[i],object,&value);
    }
    assert(world_precision_emit(dest,words,source,count,object));
    for(unsigned i=0;i<length;i++) {
        if(missing>=0 && base+i*4==dest[missing])gpu_gp0(packet[i]);
        else gpu_gp0_at(packet[i],base+i*4);
    }
    assert(world_primitive_valid==(missing<0));
}
static RasterPoint raster_point(int x,int y,int fraction,uint32_t color) {
    RasterPoint p={x,y,(int64_t)x*65536+fraction,(int64_t)y*65536+fraction,color,0,0};
    return p;
}


static void thin_triangle(void) {
    /* At IR4 the exact triangle is (41,41),(59,41),(41,43).
     * (42,42) lies strictly inside all three edges; native Y is always10. */
    RasterPoint p[3]={raster_point(10,10,16384,0x0000ff),
                      raster_point(14,10,16384,0x0000ff),
                      raster_point(10,10,16384,0x0000ff)};
    p[1].qx+=32768;p[2].qy+=32768;
    for(int scale=1;scale<=4;scale++)for(int reversed=0;reversed<2;reversed++) {
        if(reversed){RasterPoint t=p[1];p[1]=p[2];p[2]=t;}
        for(int enabled=0;enabled<=1;enabled++) {
            raster_clear(scale);gpu_set_world_raster(enabled);
            raster_submit(p,3,0x20,-1);
            if(!enabled)raster_snapshot(scale);else raster_unchanged(scale,scale==1);
            if(scale==4)assert(gpu_display_px(42,42)==(enabled?0x001f:0x7fff));
        }
        if(reversed){RasterPoint t=p[1];p[1]=p[2];p[2]=t;}
    }
}
static void flat_quad_half(void) {
    /* One exact zero-area half must not round the other half's boundary.
     * Triangle0 is a repeated vertex. Triangle1 has Q16 .25 translation. */
    RasterPoint p[4]={raster_point(10,10,16384,0x0000ff),
                      raster_point(10,10,16384,0x0000ff),
                      raster_point(14,10,16384,0x0000ff),
                      raster_point(10,14,16384,0x0000ff)};
    for(int enabled=0;enabled<=1;enabled++) {
        raster_clear(4);gpu_set_world_raster(enabled);raster_submit(p,4,0x28,-1);
        if(!enabled)raster_snapshot(4);else raster_unchanged(4,0);
        assert(gpu_display_px(40,42)==(enabled?0x7fff:0x001f));
        assert(gpu_display_px(42,42)==0x001f);
    }
}
static void camera_texture_coverage(void) {
    RasterPoint p[3]={raster_point(10,10,16384,0x808080),
                      raster_point(14,10,16384,0x808080),
                      raster_point(10,10,16384,0x808080)};
    p[1].qx+=32768;p[2].qy+=32768;
    for(int i=0;i<3;i++)p[i].u=p[i].v=1;
    camera_fixture=1;
    /* Camera moves the IR4 test sample from42 to38. Constant UV gives
     * exact red for affine/perspective, flat/Gouraud, filtered/nearest.
     * STP red over white averages to 31,15,15, retaining STP: 0xbdff. */
    for(int filter=0;filter<2;filter++)for(int gouraud=0;gouraud<2;gouraud++)
        for(int mode=0;mode<3;mode++)for(int enabled=0;enabled<2;enabled++) {
            raster_clear(4);gpu_set_filter(filter);gpu_set_world_raster(enabled);
            for(int y=0;y<4;y++)for(int x=0;x<4;x++)
                GPU_VRAM[y*1024+256+x]=mode==2?0:mode==1?0x801f:0x001f;
            raster_submit(p,3,(gouraud?0x34:0x24)|(mode==1?2:0),-1);
            if(!enabled)raster_snapshot(4);else raster_unchanged(4,0);
            uint16_t expected=!enabled||mode==2?0x7fff:mode==1?0xbdff:0x001f;
            assert(gpu_display_px(38,42)==expected);
        }
    camera_fixture=0;
}
int main(void) {
    thin_triangle();flat_quad_half();camera_texture_coverage();
    puts("PASS: subpixel thin triangle coverage, degenerate quad half, both windings, IR1..4 and unchanged native VRAM");
    return 0;
}
