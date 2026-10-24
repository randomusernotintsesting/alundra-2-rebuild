/* Captured pelvis face0: both native NCLIP triangles collapse to a line,
 * but exact projected coordinates cover a visible strip at the waist. */
#define main retained_runtime_existing_main
#include "test_world_precision_runtime.c"
#undef main
#include "../src/gpu.c"
uint32_t gpu_flips;
void psx_vblank_tick(void) {}
static int full_emission;

static void waist_face(const uint8_t *base,int enabled,int fault,int reverse,int variant) {
    memcpy(PSX_RAM,base,PSX_RAM_SIZE);memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);memset(R,0,sizeof R);
    world_precision_configure(1);world_camera_configure(1);
    world_precision_raster_scale=4;
    wp_object=world_precision_begin_object();wp_kind=WP_ACTOR;wp_actor_overflow=0;
#ifdef A2_PRECISE_CULL_IMPLEMENTED
    wp_precise_cull_mode=enabled;
#else
    (void)enabled;
#endif
    const uint32_t face=0x80008000,context=0x800157b0;
    const double xy[4][2]={{161.873809814,108.017318726},{158.924026489,107.788375854},
                           {158.898056030,107.235733032},{161.586624146,107.444091797}};
    const int native_x[4]={161,158,158,161};
    const double sign_xy[4][4][2]={
        {{163.636489868,99.900192261},{163.228530884,100.324417114},{162.969421387,102.340011597},{162.969421387,102.340011597}},
        {{169.081253052,94.928283691},{168.171722412,95.664184570},{169.734954834,94.082748413},{169.734954834,94.082748413}},
        {{161,107.5},{158,107.4},{159,107.9},{161,107.0}},
        {{0,513},{1.25,0},{1,0},{.75,1}}};
    const int sign_native[4][4][2]={{{163,99},{163,100},{162,101},{162,101}},{{168,94},{168,95},{169,93},{169,93}},
                                   {{161,107},{158,107},{159,107},{161,107}},{{0,513},{0,0},{1,0},{1,1}}};
    memset(PSX_RAM+0x8000,0,80);sw_(face+4,0x03020100);sw_(face+8,0x38808080);
    for(unsigned i=1;i<4;i++)sw_(face+8+i*4,0x00808080);
    sh_(0x1f8003d0,0xffff); /* Real material command mask keeps its format. */
    if(full_emission==2) {
        sh_(face,4);for(unsigned i=0;i<9;i++)sw_(face+44+i*4,lw_(face+8+i*4));
        sw_(face+44,0x3c808080);
    }
    if(full_emission==3) {
        sb_(face+40,16);sw_(0x1f8003cc,0x80009000);sw_(0x80009010,0x8000b000);
        memset(PSX_RAM+0xb000,0,32);sw_(context+0x5e8,0x80007400);sw_(context+0x5ec,0x80007800);
    }
    for(unsigned i=0;i<4;i++) {
        unsigned j=reverse?3-i:i;int nx=variant?sign_native[variant-1][j][0]:native_x[j],ny=variant?sign_native[variant-1][j][1]:107;
        uint32_t word=pack(nx,ny),source=0x1f800000+i*16;
        sw_(source,word);sw_(source+4,1000);sw_(source+8,0x808080);
        world_precision_gte_push(word,(int64_t)nx*65536,(int64_t)ny*65536,1067,1);
        world_precision_vertex value;assert(world_precision_gte_read(14,word,&value));
        value.x=round((variant?sign_xy[variant-1][j][0]:xy[j][0])*65536)/65536;
        value.y=round((variant?sign_xy[variant-1][j][1]:xy[j][1])*65536)/65536;
        value.projection_kind=WORLD_PROJECTION_CAMERA;
        value.camera_generation=wp_object;
        world_precision_record(source,word,wp_object,&value);
    }
    if(fault==1)sw_(0x1f800010,lw_(0x1f800010)); /* Same word, invalidated generation. */
    if(fault==2)wp_object=world_precision_begin_object();
    if(fault==3)world_camera_configure(0);
    if(fault==4)world_precision_raster_scale=1;
    if(fault==5)sw_(0x80010000,lw_(0x80010000)^1); /* Unsupported renderer overlay. */
    if(fault==6)sh_(face,8); /* Authored two-sided face bypasses NCLIP. */
    if(fault==7)sw_(face+8,0x28808080); /* Unsupported actor packet format. */
    if(fault==8)sh_(0x1f8003d2,0x0400); /* Material mask changes packet format. */
    R[3]=face;R[4]=context;R[5]=0x1f800000;R[2]=0x80100000;
    sw_(context+0x7c,0x80005000);sh_(0x1f8003d6,1);
    psx_interp(0x80013450);
    int should_emit=fault==6||variant==4?1:variant==1?(enabled!=2||fault):variant==2?(enabled==2&&!fault):enabled&&!fault&&!reverse;
    if(should_emit) {
        uint32_t expected=full_emission==3?0x800138c8:0x80013cb8;
        if(psx_next!=expected)fprintf(stderr,"FAIL: visible waist face was discarded before emission (next=%08X)\n",psx_next);
        assert(psx_next==expected);
        assert(R[31]==(full_emission==2?0x800137e0:full_emission==3?0x8001371c:0x80013754));
    } else assert(psx_next==0x80005000);
    if(!variant && fault!=6)assert((int32_t)gte_data_read(24)==0); /* Native NCLIP result is never forged. */
    if(full_emission) {
        assert(should_emit);uint32_t start=R[2];R[7]=0x8000c000;
        for(unsigned i=0;i<0x2000;i+=4)sw_(R[7]+i,0x00ffffff);
        sw_(context+0x64,full_emission==4?start:start+4096);sw_(context+0x5f8,0);sw_(context+0x5cc,0);
        memset(PSX_RAM+(start&0x1fffff),0xcd,128);
        for(unsigned calls=0;psx_next!=0x80005000;calls++) {
            assert(calls<8);psx_interp(psx_next);
        }
        if(full_emission==4) {assert(R[2]==start);assert(lw_(start)==0xcdcdcdcd);return;}
        unsigned expected_bytes=full_emission==2?96:40;assert(R[2]==start+expected_bytes);
        assert(lw_(R[2])==0xcdcdcdcd); /* Original emitter stays inside its exact packet extent. */
        uint32_t head=0xffffff;unsigned heads=0;
        for(unsigned i=0;i<0x2000;i+=4) {
            uint32_t q=lw_(0x8000c000+i)&0xffffff;
            if(q>=(start&0x1fffff)&&q<(R[2]&0x1fffff)){head=q;heads++;}
        }
        assert(heads==1);gpu_set_ir(4);gpu_set_world_raster(1);gpu_gp1(0);
        gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|319|(239<<10));
        memset(GPU_VRAM,0xff,sizeof GPU_VRAM);memset(SHADOW,0xff,(size_t)IR_W*IR_H*2);
        unsigned packets=0;
        while(head!=0xffffff) {
            assert(packets++<2);uint32_t tag=lw_(head),count=tag>>24;assert(count==9||count==13);
            for(unsigned i=1;i<=count;i++)gpu_gp0_at(lw_(head+i*4),head+i*4);
            assert(world_primitive_valid);head=tag&0xffffff;
        }
        assert(packets==(full_emission==2?2u:1u));
        unsigned covered=0;
        for(int y=106*4;y<110*4;y++)for(int x=157*4;x<163*4;x++)covered+=SHADOW[y*IR_W+x]!=0xffff;
        assert(covered>0);
        for(unsigned i=0;i<1024*512;i++)assert(GPU_VRAM[i]==0xffff);
    }
}
int main(int argc,char **argv) {
    if(argc!=2)return 77;FILE *f=fopen(argv[1],"rb");assert(f);static uint8_t base[PSX_RAM_SIZE];
    assert(fread(base,1,sizeof base,f)==sizeof base);fclose(f);
    waist_face(base,0,0,0,0);waist_face(base,1,0,0,0);
    waist_face(base,1,0,1,0);
    for(int mode=1;mode<=2;mode++)for(int fault=1;fault<=5;fault++)waist_face(base,mode,fault,0,0);
    for(int variant=1;variant<=2;variant++)for(int mode=0;mode<=2;mode++)waist_face(base,mode,0,0,variant);
    for(int variant=1;variant<=2;variant++)for(int fault=1;fault<=5;fault++)waist_face(base,2,fault,0,variant);
    for(int mode=0;mode<=2;mode++) {
        waist_face(base,mode,0,0,3); /* Only the second exact NCLIP is positive. */
        waist_face(base,mode,6,1,0); /* Reversed but explicitly two-sided. */
    }
    waist_face(base,2,0,0,4); /* Oversized native quad must retain GPU fallback. */
    waist_face(base,2,7,0,0);waist_face(base,2,8,0,0);
    for(full_emission=1;full_emission<=4;full_emission++)waist_face(base,2,0,0,0);
    puts("PASS: actual AL22 NCLIP, branch, material/layer emitter, OT and GP0 preserve the waist strip; sign, fallback, two-sided, extent and packet-capacity cases pass");
}
