/* Real GTE, memory helpers and retained low-RAM instructions, without a game
 * replay. Optional argv[1] is the retained ram_18000.bin instruction fixture. */
#define A2_WORLD_PRECISION 1
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/psx_rt.h"
#include "../src/world_precision.h"
#include "../src/gte.c"
#include "../src/interp.c"

uint8_t PSX_RAM[PSX_RAM_SIZE] __attribute__((aligned(16)));
uint8_t PSX_SCRATCH[0x400];
uint32_t R[32],HI,LO,psx_next,psx_work,psx_frame_no,a2_ramwatch;
int psx_bb_budget=1000000;
void a2_ramwatch_hit(uint32_t p,uint32_t v,int n) {(void)p;(void)v;(void)n;}
uint32_t psx_mmio_read(uint32_t p,int n) {(void)p;(void)n;return 0;}
void psx_mmio_write(uint32_t p,uint32_t v,int n) {(void)p;(void)v;(void)n;}
uint32_t psx_cop0_read(int r) {(void)r;return 0;}
void psx_cop0_write(int r,uint32_t v) {(void)r;(void)v;}
void psx_rfe(void) {}
void psx_syscall_at(uint32_t pc) {(void)pc;abort();}
void psx_break(uint32_t code) {(void)code;abort();}
void psx_bb_fire(void) {psx_bb_budget=1000000;}
static int fixture_wide;
int a2_wide(void) {return fixture_wide;}

static uint32_t pack(int x,int y) {return (uint16_t)x|((uint32_t)(uint16_t)y<<16);}
static void accumulator44(void) {
    static const struct {int64_t input,output;int overflow;} cases[]={
        {-268116,-268116,0}, /* observed actor-lighting UBSan input */
        {0,0,0},{1,1,0},{-1,-1,0},
        {INT64_C(8796093022207),INT64_C(8796093022207),0},
        {INT64_C(8796093022208),-INT64_C(8796093022208),1},
        {INT64_C(8796093022209),-INT64_C(8796093022207),1},
        {-INT64_C(8796093022208),-INT64_C(8796093022208),0},
        {-INT64_C(8796093022209),INT64_C(8796093022207),-1},
        {INT64_C(17592186044416),0,1},
        {-INT64_C(17592186044416),0,-1},
        {INT64_MAX,-1,1},{INT64_MIN,0,-1}
    };
    for(int channel=1;channel<=3;channel++) {
        for(unsigned i=0;i<sizeof cases/sizeof cases[0];i++) {
            const uint32_t sticky=1u<<12;
            uint32_t expected=sticky;
            if(cases[i].overflow>0)expected|=1u<<(31-channel);
            if(cases[i].overflow<0)expected|=1u<<(28-channel);
            FLAG=sticky;
            assert(A(channel,cases[i].input)==cases[i].output);
            assert(FLAG==expected);
        }
    }
    puts("PASS: exact signed44 accumulator boundaries, wrapping and per-channel sticky overflow flags");
}
static void memory_writes(void) {
    const uint32_t bases[]={0x80000200,0xbf800090};
    for(unsigned b=0;b<2;b++) for(unsigned op=0;op<5;op++) for(unsigned lane=0;lane<4;lane++) {
        world_precision_configure(1);
        uint64_t object=world_precision_begin_object();
        world_precision_vertex v,got;
        uint32_t word=pack(181,84),src=bases[b],dst[]={0x8010000c,0x80100018,0x80100024};
        uint32_t sources[]={src,src+12,src+24},words[]={word,word,word};
        world_precision_gte_push(word,11926912,5557744,943.25,1);
        assert(world_precision_gte_read(14,word,&v));
        for(unsigned i=0;i<3;i++) {sw_(sources[i],word);world_precision_record(sources[i],word,object,&v);}
        assert(world_precision_emit(dst,words,sources,3,object));
        uint32_t a=src+lane;
        switch(op) {
        case 0: sb_(a,lb_(a));break;
        case 1: sh_(a,lh_(a));break;
        case 2: sw_(a,lw_(a));break;
        case 3: swl_(a,lwl_(a,0));break;
        case 4: swr_(a,lwr_(a,0));break;
        }
        assert(!world_precision_emit(dst,words,sources,3,object));
        assert(!world_precision_packet(dst[0],word,&got));
    }
}

static void setup_projection(void) {
    const int16_t rotation[]={11560,0,11556,8160,11532,-8157,-2045,2892,2044,0};
    for(int r=0;r<32;r++) {gte_data_write(r,0);gte_ctrl_write(r,0);}
    for(int i=0;i<5;i++) gte_ctrl_write(i,pack(rotation[i*2],rotation[i*2+1]));
    gte_ctrl_write(24,160<<16); gte_ctrl_write(25,124<<16); gte_ctrl_write(26,96);
}
static const int16_t input[8][3]={
    {-582,600,559},{-582,600,659},{-482,600,559},{-482,600,659},
    {-582,600,459},{-482,600,459},{-416,600,659},{-416,600,509}};
static const int16_t projected[8][2]={
    {153,67},{179,51},{181,84},{208,67},{124,84},{152,104},{228,78},{188,107}};

static void actual_gte(void) {
    world_precision_vertex v[8];
    uint32_t native[8][64];
    for(int enabled=0;enabled<=1;enabled++) {
        world_precision_configure(enabled);setup_projection();
        for(int i=0;i<8;i++) {
            gte_data_write(0,pack(input[i][0],input[i][1]));
            gte_data_write(1,(uint16_t)input[i][2]);
            gte_cmd(0x180001);
            uint32_t word=gte_data_read(14);
            assert(word==pack(projected[i][0],projected[i][1]));
            for(int r=0;r<64;r++) {
                uint32_t value=r<32?gte_data_read(r):gte_ctrl_read(r-32);
                if(!enabled) native[i][r]=value;else assert(value==native[i][r]);
            }
            if(enabled) assert(world_precision_gte_read(14,word,&v[i]));
        }
    }
    double dx=v[3].x-v[5].x,dy=v[3].y-v[5].y;
    double distance=fabs(dx*(v[2].y-v[5].y)-dy*(v[2].x-v[5].x))/hypot(dx,dy);
    assert(distance<0.001);
    printf("Captured GTE T-junction residual %.9f native pixels; native registers identical\n",distance);
    gte_data_write(14,gte_data_read(14));
    assert(!world_precision_gte_read(14,gte_data_read(14),&v[0]));
    for(int i=0;i<3;i++) {
        gte_data_write(i*2,pack(input[i][0],input[i][1]));
        gte_data_write(i*2+1,input[i][2]);
    }
    gte_cmd(0x180030); /* RTPT must preserve FIFO order for all three vertices. */
    for(int i=0;i<3;i++) {
        assert(world_precision_gte_read(12+i,gte_data_read(12+i),&v[i]));
        assert(v[i].native_word==pack(projected[i][0],projected[i][1]));
    }
    gte_data_write(15,gte_data_read(14));
    assert(world_precision_gte_read(12,gte_data_read(12),&v[0]));
    assert(!world_precision_gte_read(14,gte_data_read(14),&v[0]));
    gte_data_write(0,0);gte_data_write(1,0);gte_cmd(0x180001);
    assert(!world_precision_gte_read(14,gte_data_read(14),&v[0])); /* divide overflow */
    const uint32_t far_z[]={32768,40000,65535};
    for(unsigned i=0;i<sizeof far_z/sizeof far_z[0];i++) {
        gte_ctrl_write(7,far_z[i]);gte_cmd(0x180001);
        assert(gte_ctrl_read(31)==0x00400000); /* Isolated IR3 saturation. */
        assert(gte_data_read(14)==pack(160,124));
        assert(world_precision_gte_read(14,gte_data_read(14),&v[0]));
        assert(v[0].x==160 && v[0].y==124 && v[0].z==far_z[i]);
    }
}

/* Real RTPS admission: saturated coordinate intermediates still produce
 * valid screen XY. Catch rejecting them before camera/packet transport,
 * and compare all guest GTE registers with host precision disabled. */
static void saturated_projection(void) {
    static const struct {int32_t x,y,z;int64_t xq,yq;} cases[]={
        {40000,0,40000,15639563,8126464},
        {-40000,0,40000,5331799,8126464},
        {0,40000,40000,10485760,13280267},
        {0,-40000,40000,10485760,2972503},
        {40000,-40000,40000,15639563,2972503},
    };
    for(unsigned i=0;i<sizeof cases/sizeof cases[0];i++) {
        uint32_t native[64];
        for(int enabled=0;enabled<2;enabled++) {
            world_precision_configure(enabled);world_camera_configure(enabled);
            for(int r=0;r<32;r++){gte_data_write(r,0);gte_ctrl_write(r,0);}
            gte_ctrl_write(0,4096);gte_ctrl_write(2,4096);gte_ctrl_write(4,4096);
            gte_ctrl_write(5,(uint32_t)cases[i].x);gte_ctrl_write(6,(uint32_t)cases[i].y);
            gte_ctrl_write(7,(uint32_t)cases[i].z);
            gte_ctrl_write(24,160*65536);gte_ctrl_write(25,124*65536);gte_ctrl_write(26,96);
            fixture_wide=0;
            const uint32_t remainder[3]={0,0,0};
            world_precision_producer_pc=0x80010d54;
            world_precision_camera_arm(0x80010d54,remainder,world_precision_begin_object());
            gte_cmd(0x180001);
            for(unsigned r=0;r<64;r++) {
                uint32_t value=r<32?gte_data_read(r):gte_ctrl_read(r-32);
                if(!enabled)native[r]=value;else assert(native[r]==value);
            }
            if(enabled) {
                world_precision_vertex got;
                assert(world_precision_gte_read(14,gte_data_read(14),&got));
                assert(got.projection_kind==WORLD_PROJECTION_CAMERA);
                assert(got.x*65536==cases[i].xq && got.y*65536==cases[i].yq);
                assert(got.z==cases[i].z);
            }
        }
    }
    puts("PASS: saturated RTPS retains clamped camera projection and all native GTE registers");
}

static const unsigned quads[3][4]={{0,1,2,3},{4,0,5,2},{3,6,5,7}};
static void draw_retained_quad(int q,const uint32_t source[8],uint32_t caller,int wanted) {
    const unsigned map[]={0,1,3,2};
    for(int i=0;i<4;i++) {
        unsigned n=quads[q][map[i]];
        sw_(R[5]+0x3b8+i*4,source[n]);
        R[16+i*2]=(uint32_t)(int32_t)projected[n][0];
        R[17+i*2]=(uint32_t)(int32_t)projected[n][1];
    }
    R[2]=0x800f7900+q*0x38;R[4]=0x800157b0;R[7]=0x80008000;
    R[8]=0x3c808080;R[9]=R[10]=R[11]=0x808080;R[30]=0;
    R[31]=caller;R[1]=0xe1000006;
    sw_(R[4]+0x64,0x80110000);sw_(R[5]+0x3d4,0);
    sh_(R[5]+0x3d0,0xffff);sh_(R[5]+0x3d2,0);
    psx_interp(0x800126c4);
    uint64_t generation=0;
    for(int i=0;i<4;i++) {
        uint32_t addr=0x800f790c+q*0x38+i*12;
        world_precision_vertex got;
        int valid=world_precision_packet(addr,lw_(addr),&got);
        assert(valid==wanted);
        if(!valid) continue;
        assert(got.source_address==source[quads[q][i]]);
        assert(got.producer_pc==0x80010d4c);
        if(i) assert(got.generation==generation);
        generation=got.generation;
    }
}
static void retained_world_route(const char *path,int enabled) {
    static uint8_t native_ram[PSX_RAM_SIZE],native_scratch[0x400];
    static uint32_t native_registers[32];
    FILE *f=fopen(path,"rb");assert(f);
    assert(fread(PSX_RAM,1,sizeof PSX_RAM,f)==sizeof PSX_RAM);fclose(f);
    memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);memset(R,0,sizeof R);
    world_precision_configure(enabled);setup_projection();
    /* AL22's real entry100AC/100B0 sets a0 to this mutable context, directly
     * after the final instruction at157AC. Hashing context bytes rejects
     * every live object when10C34 saves ra at context+7C. */
    R[4]=0x800157b0;R[5]=0x1f800000;R[31]=0;
    exec1(0x80010c34,fetch(0x80010c34)); /* real object entry */
    uint32_t source[8];
    for(int i=0;i<8;i++) {
        source[i]=0x1f800000+i*12;
        R[6]=source[i];R[2]=0x80004000;
        gte_data_write(0,pack(input[i][0],input[i][1]));gte_data_write(1,input[i][2]);
        for(uint32_t pc=0x80010d4c;pc<=0x80010db4;pc+=4) exec1(pc,fetch(pc));
        assert(lw_(source[i])==pack(projected[i][0],projected[i][1]));
    }
    for(int q=0;q<3;q++) draw_retained_quad(q,source,0x800111b4,enabled);
    draw_retained_quad(0,source,0x80011400,0); /* unknown/near caller */
    sh_(source[0]+4,180);
    draw_retained_quad(0,source,0x800111b4,0); /* unsupported near depth */
    sh_(source[0]+4,993);
    R[6]=source[0];
    gte_data_write(0,pack(input[0][0],input[0][1]));gte_data_write(1,input[0][2]);
    exec1(0x80010d4c,fetch(0x80010d4c));
    exec1(0x80010d98,fetch(0x80010d98));
    exec1(0x80020000,0x26730000); /* addiu s3,s3,0: identical write is still new provenance */
    exec1(0x80010dac,fetch(0x80010dac));
    draw_retained_quad(0,source,0x800111b4,0);
    uint32_t original=lw_(0x80010000);
    sw_(0x80010000,original^1); /* Different code, even outside executed sites. */
    exec1(0x80010c34,fetch(0x80010c34));
    draw_retained_quad(2,source,0x800111b4,0);
    sw_(0x80010000,original);
    exec1(0x80010c34,fetch(0x80010c34));
    draw_retained_quad(2,source,0x800111b4,0); /* previous object's records */
    if(!enabled) {
        memcpy(native_ram,PSX_RAM,sizeof native_ram);memcpy(native_scratch,PSX_SCRATCH,sizeof native_scratch);
        memcpy(native_registers,R,sizeof R);
    } else {
        assert(!memcmp(native_ram,PSX_RAM,sizeof native_ram));
        assert(!memcmp(native_scratch,PSX_SCRATCH,sizeof native_scratch));
        assert(!memcmp(native_registers,R,sizeof R));
        puts("PASS: retained world RTPS/MFC2/SW and far-quad interpreter route, all 12 target vertices; native RAM/scratch/GPR identical");
    }
}

/* Original face33 of model801AEC88 is cmd34, indices50/52/54/54.
 * Its real far dispatcher126C4 branches12794→128B8, writes XY at
 * packet+0C/+18/+24 and finishes at12988. It shares source edge50–52
 * with tracked quad face29; this is source topology, not screen-XY lookup. */
static void draw_retained_triangle(const uint32_t source[3],uint32_t caller,int wanted,
                                   int poison_fourth,uint32_t command_bits) {
    const int xy[3][2]={{152,149},{181,151},{185,162}};
    uint32_t face=0x801af384;
    for(unsigned i=0;i<4;i++) {
        unsigned n=i<3?i:2;
        sw_(R[5]+0x3b8+i*4,source[n]);sw_(R[5]+0x3a8+i*4,lw_(source[n]+4));
        R[16+i*2]=xy[n][0];R[17+i*2]=xy[n][1];
    }
    if(poison_fourth) {
        /* The real triangle branch never consumes fourth XY/depth. Neither
         * a quad's source0/1/3 order nor phantom fourth provenance is valid. */
        sw_(R[5]+0x3c4,0x1f800300);sw_(R[5]+0x3b4,0);
        R[22]=0x123;R[23]=0x124;
    }
    for(unsigned i=0;i<4;i++)R[8+i]=lw_(face+8+i*4);
    R[8]|=command_bits;
    R[14]=lw_(face+0x18);R[15]=lw_(face+0x1c);R[24]=lw_(face+0x20);
    R[12]=R[15]>>16;R[13]=R[14]>>16;R[25]=R[24]>>16;
    R[1]=lw_(face+0x24);R[2]=0x800f79d8;R[4]=0x800157b0;
    R[7]=0x80008000;R[30]=0;R[31]=caller;
    sw_(R[4]+0x64,0x80110000);sw_(R[5]+0x3d4,lw_(face));
    sh_(R[5]+0x3d0,0xffff);sh_(R[5]+0x3d2,0);
    psx_interp(0x800126c4);
    uint64_t generation=0;
    assert(lw_(0x800f79e0)==(0x34356195|command_bits));
    for(unsigned i=0;i<3;i++) {
        uint32_t address=0x800f79e4+i*12;
        assert(lw_(address)==pack(xy[i][0],xy[i][1]));
        world_precision_vertex value;int valid=world_precision_packet(address,lw_(address),&value);
        assert(valid==wanted);
        if(!valid)continue;
        assert(value.source_address==source[i]);assert(value.producer_pc==0x80010d4c);
        if(i)assert(value.generation==generation);generation=value.generation;
    }
}
static void retained_triangle_route(const char *path,int enabled) {
    static uint8_t native_ram[PSX_RAM_SIZE],native_scratch[0x400];
    static uint32_t native_registers[32],native_gte[64];
    FILE *file=fopen(path,"rb");assert(file);
    assert(fread(PSX_RAM,1,sizeof PSX_RAM,file)==sizeof PSX_RAM);fclose(file);
    memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);memset(R,0,sizeof R);
    world_precision_configure(enabled);setup_projection();
    R[4]=0x800157b0;R[5]=0x1f800000;R[31]=0;
    exec1(0x80010c34,fetch(0x80010c34));
    const unsigned indices[]={50,52,54};
    const int16_t inputs[3][3]={{-382,600,359},{-337,600,399},{-309,600,383}};
    uint32_t source[3];
    for(unsigned i=0;i<3;i++) {
        uint32_t raw=0x801af568+indices[i]*12;
        /* This retained model has identity local rotation and translation
         * (-482,451,509) into the RTPS input space. Assert original vertex
         * data as well as its projected word; equal XY is not identity. */
        assert((int16_t)lh_(raw)+(int16_t)lh_(raw+2)-482==inputs[i][0]);
        assert((int16_t)lh_(raw+4)+(int16_t)lh_(raw+6)+451==inputs[i][1]);
        assert((int16_t)lh_(raw+8)+(int16_t)lh_(raw+10)+509==inputs[i][2]);
        source[i]=0x1f800000+indices[i]*12;R[6]=source[i];R[2]=0x80004000;
        gte_data_write(0,pack(inputs[i][0],inputs[i][1]));gte_data_write(1,inputs[i][2]);
        for(uint32_t pc=0x80010d4c;pc<=0x80010dbc;pc+=4)exec1(pc,fetch(pc));
    }
    draw_retained_triangle(source,0x800111b4,enabled,0,0);
    draw_retained_triangle(source,0x800111b4,enabled,1,0);
    /* Raw/semi flags are polygon variants, but high opcode bits are not. */
    draw_retained_triangle(source,0x800111b4,enabled,1,0x03000000);
    draw_retained_triangle(source,0x800111b4,0,1,0x40000000);
    draw_retained_triangle(source,0x800111b4,0,1,0x80000000);
    draw_retained_triangle(source,0x80011400,0,0,0); /* Unsupported caller. */
    sb_(source[1],lb_(source[1])); /* Identical source overwrite revokes all3. */
    draw_retained_triangle(source,0x800111b4,0,0,0);
    for(unsigned i=0;i<64;i++) {
        uint32_t value=i<32?gte_data_read(i):gte_ctrl_read(i-32);
        if(!enabled)native_gte[i]=value;else assert(value==native_gte[i]);
    }
    if(!enabled) {
        memcpy(native_ram,PSX_RAM,sizeof native_ram);memcpy(native_scratch,PSX_SCRATCH,sizeof native_scratch);
        memcpy(native_registers,R,sizeof R);
    } else {
        assert(!memcmp(native_ram,PSX_RAM,sizeof native_ram));
        assert(!memcmp(native_scratch,PSX_SCRATCH,sizeof native_scratch));
        assert(!memcmp(native_registers,R,sizeof R));
        puts("PASS: actual far-triangle original indices0/1/2, all3 tags and complete fallback; native RAM/scratch/GPR/GTE identical");
    }
}

/* Retained actor PART8011763C, FACE8017672C: original indices45/20/7/35.
 * modelcap.txt lines710..758 independently records these four RTPS inputs;
 * two distinct source vertices deliberately round to the same (163,67).
 * This fixture follows source addresses through actual actor instructions. */
static const unsigned actor_indices[4]={45,20,7,35};
static const int16_t actor_input[4][3]={
    {-456,477,454},{-447,477,458},{-447,475,458},{-457,476,454}};
static const int16_t actor_xy[4][2]={{159,66},{163,67},{163,67},{158,66}};

static void actor_project(unsigned index,uint32_t destination,uint32_t duplicate) {
    R[6]=destination;R[22]=duplicate;
    gte_data_write(0,pack(actor_input[index][0],actor_input[index][1]));
    gte_data_write(1,actor_input[index][2]);
    exec1(0x8001338c,fetch(0x8001338c));
    exec1(0x800133fc,fetch(0x800133fc));
    exec1(0x80013400,fetch(0x80013400));
    exec1(0x80013404,fetch(0x80013404));
    exec1(0x80013408,fetch(0x80013408));
    exec1(0x8001340c,fetch(0x8001340c));
    exec1(0x80013410,fetch(0x80013410));
    exec1(0x80013418,fetch(0x80013418)); /* real branch delay slot */
    if(duplicate) {
        exec1(0x8001341c,fetch(0x8001341c));
        exec1(0x80013420,fetch(0x80013420));
        exec1(0x80013428,fetch(0x80013428));
        assert(lw_(duplicate)==lw_(destination));
    }
    assert(lw_(destination)==pack(actor_xy[index][0],actor_xy[index][1]));
}

static void draw_retained_actor(const uint32_t source[4],unsigned command,
                                uint32_t caller,int wanted) {
    uint32_t face=0x8017672c,material=face+(command&4?0x2c:8);
    int count=command&8?4:3,stride=command&4?12:8;
    const unsigned quad_order[]={0,1,3,2};
    for(unsigned i=0;i<4;i++) {
        sw_(R[5]+0x3b8+i*4,source[i]);
        sw_(R[5]+0x3a8+i*4,lw_(source[i]+4));
        R[16+i*2]=(uint32_t)(int32_t)actor_xy[i][0];
        R[17+i*2]=(uint32_t)(int32_t)actor_xy[i][1];
    }
    for(unsigned i=0;i<4;i++)R[8+i]=lw_(material+i*4);
    R[8]=(R[8]&0xffffffu)|(command<<24);
    R[14]=lw_(material+16);R[15]=lw_(material+20);R[24]=lw_(material+24);
    R[12]=R[15]>>16;R[13]=R[14]>>16;R[25]=R[24]>>16;
    R[1]=lw_(material+28);R[2]=0x800f9000;R[4]=0x800157b0;
    R[7]=0x80008000;R[30]=0;R[31]=caller;
    sw_(R[4]+0x64,0x80110000);sw_(R[4]+0x5f8,0);
    sh_(R[5]+0x3d0,0xffff);sh_(R[5]+0x3d2,0);
    int wrapped=caller==0x8001371c || caller==0x800137a8 || caller==0x8001385c;
    if(wrapped) {
        R[25]=0x80007000;
        for(unsigned i=0;i<20;i+=4)sw_(R[25]+i,0);
        sw_(R[4]+0x5e8,0x80007400);sw_(R[4]+0x5ec,0x80007800);
    }
    psx_interp(wrapped?0x800138c8:0x80013cb8);
    uint64_t generation=0;
    for(int i=0;i<count;i++) {
        unsigned n=count==4?quad_order[i]:(unsigned)i;
        uint32_t address=0x800f900c+(unsigned)i*stride;
        assert(lw_(address)==pack(actor_xy[n][0],actor_xy[n][1]));
        world_precision_vertex got;
        int valid=world_precision_packet(address,lw_(address),&got);
        assert(valid==wanted);
        if(!valid)continue;
        assert(got.source_address==(source[n]&0x1fffffff));
        assert(got.producer_pc==0x8001338c);
        if(i)assert(got.generation==generation);generation=got.generation;
    }
}

static void retained_actor_route(const char *path,int enabled) {
    static uint8_t native_ram[PSX_RAM_SIZE],native_scratch[0x400];
    static uint32_t native_registers[32],native_gte[64];
    FILE *file=fopen(path,"rb");assert(file);
    assert(fread(PSX_RAM,1,sizeof PSX_RAM,file)==sizeof PSX_RAM);fclose(file);
    memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);memset(R,0,sizeof R);
    world_precision_configure(enabled);setup_projection();
    assert(lw_(0x80176730)==0x2307142d); /* original face topology */
    R[4]=0x800157b0;R[5]=0x1f800000;R[30]=0x80002000;
    sw_(R[4]+0x5cc,0);sh_(R[4]+0xab0,0);
    exec1(0x800130f8,fetch(0x800130f8));
    exec1(0x80013194,fetch(0x80013194));
    uint32_t source[4];
    for(unsigned i=0;i<4;i++) {
        source[i]=R[5]+actor_indices[i]*16;
        actor_project(i,source[i],0);
    }
    draw_retained_actor(source,0x3c,0x800137e0,enabled);
    draw_retained_actor(source,0x38,0x80013894,enabled);
    draw_retained_actor(source,0x34,0x80013754,enabled);
    draw_retained_actor(source,0x30,0x80013754,enabled);
    draw_retained_actor(source,0x3f,0x8001371c,enabled); /* real UV/color wrapper */
    draw_retained_actor(source,0x33,0x800137a8,enabled);
    draw_retained_actor(source,0x3c,0x8001385c,enabled);
    draw_retained_actor(source,0x74,0x80013754,0); /* invalid high command bits */
    draw_retained_actor(source,0x3c,0x80011400,0); /* unrelated caller */
    sh_(R[4]+0xab0,0x0800);
    draw_retained_actor(source,0x3c,0x800137e0,0); /* different screen-feedback path */
    sh_(R[4]+0xab0,0);
    uint16_t saved_depth=(uint16_t)lh_(source[0]+4);
    sh_(source[0]+4,0);
    draw_retained_actor(source,0x3c,0x800137e0,0);
    sh_(source[0]+4,saved_depth);
    draw_retained_actor(source,0x3c,0x800137e0,enabled);
    sb_(source[1],lb_(source[1]));
    draw_retained_actor(source,0x3c,0x800137e0,0); /* identical overwrite */
    actor_project(1,source[1],0);
    draw_retained_actor(source,0x3c,0x800137e0,enabled);
    /* The branch's optional copy shares a projection, but has independent
     * address lifetime. Exercise the first and final byte-index overflow slots. */
    for(unsigned slot=0;slot<=195;slot+=195) {
        uint32_t alternate[4];memcpy(alternate,source,sizeof alternate);
        R[23]=0x80006000;alternate[3]=R[23]+slot*16;
        actor_project(3,source[3],alternate[3]);
        draw_retained_actor(alternate,0x3c,0x800137e0,enabled);
        sw_(alternate[3],lw_(alternate[3]));
        draw_retained_actor(alternate,0x3c,0x800137e0,0);
        draw_retained_actor(source,0x3c,0x800137e0,enabled);
    }
    {
        uint32_t alternate[4];memcpy(alternate,source,sizeof alternate);
        /* A corrupt overflow-bank pointer must not grant a second scratch
         * record the provenance reserved for the part's explicit RAM bank. */
        R[23]=0x1f800000;alternate[3]=0x1f8000a0;
        actor_project(3,source[3],alternate[3]);
        draw_retained_actor(alternate,0x3c,0x800137e0,0);
        draw_retained_actor(source,0x3c,0x800137e0,enabled);
    }
    /* A same-value register rewrite after MFC2 is not the same producer. */
    R[6]=source[0];R[22]=0;
    gte_data_write(0,pack(actor_input[0][0],actor_input[0][1]));gte_data_write(1,actor_input[0][2]);
    exec1(0x8001338c,fetch(0x8001338c));exec1(0x80013400,fetch(0x80013400));
    exec1(0x80020000,0x26730000);exec1(0x80013408,fetch(0x80013408));
    draw_retained_actor(source,0x3c,0x800137e0,0);
    actor_project(0,source[0],0);
    /* New part, terminal return, early return and world entry all fence off
     * the old actor records, even when every visible/native word is equal. */
    const uint32_t fences[]={0x80013194,0x800138b8,0x800130f8,0x80010c34};
    for(unsigned f=0;f<sizeof fences/sizeof fences[0];f++) {
        exec1(fences[f],fetch(fences[f]));
        draw_retained_actor(source,0x3c,0x800137e0,0);
        R[30]=0x80002000;exec1(0x80013194,fetch(0x80013194));
        for(unsigned i=0;i<4;i++)actor_project(i,source[i],0);
        draw_retained_actor(source,0x3c,0x800137e0,enabled);
    }
    uint32_t original=lw_(0x80010000);sw_(0x80010000,original^1);
    draw_retained_actor(source,0x3c,0x800137e0,0); /* immutable-code identity */
    sw_(0x80010000,original);
    for(unsigned i=0;i<64;i++) {
        uint32_t value=i<32?gte_data_read(i):gte_ctrl_read(i-32);
        if(!enabled)native_gte[i]=value;else assert(value==native_gte[i]);
    }
    if(!enabled) {
        memcpy(native_ram,PSX_RAM,sizeof native_ram);memcpy(native_scratch,PSX_SCRATCH,sizeof native_scratch);
        memcpy(native_registers,R,sizeof R);
    } else {
        assert(!memcmp(native_ram,PSX_RAM,sizeof native_ram));
        assert(!memcmp(native_scratch,PSX_SCRATCH,sizeof native_scratch));
        assert(!memcmp(native_registers,R,sizeof R));
        puts("PASS: actual actor RTPS/MFC2/SW and four normal emit layouts; native RAM/scratch/GPR/GTE identical");
    }
}

/* RAM18080/modelcap18076 from room-movement-metadata: model801DD5A8,
 * vertexbase801DDEC4, face801DDB6C. The source indices are58/56/63/64;
 * GPU ordering is58/56/64/63. The first material uses modifier80128078
 * (U+96), the second is direct. Run the real double-material dispatcher,
 * not a second synthetic emitter pretending to be the wrapper. */
static void retained_world_materials(const char *path,int enabled) {
    static const uint32_t face[20]={
        0x00000406,0x403f383a,0x3c504e35,0x003f4031,0x002a2b25,
        0x0027271d,0x0032003c,0x00032f3c,0x00202f20,0xe2000000,
        0xffffff10,0x3eb5c3c6,0x00d0e4e8,0x00e9ffff,0x00cadce0,
        0x7bf5a7ca,0x006680ca,0xa7e380e3,0xe2000000,0xffffff00};
    static const unsigned indices[4]={58,56,63,64},order[4]={0,1,3,2};
    static const int16_t posed[4][3]={
        {-409,555,23},{-409,555,165},{-323,555,165},{-323,555,23}};
    static const int16_t xy[4][2]={{30,234},{86,183},{109,213},{51,272}};
    static uint8_t native_ram[PSX_RAM_SIZE],native_scratch[0x400];
    static uint32_t native_registers[32],native_gte[64];
    FILE *file=fopen(path,"rb");assert(file);
    assert(fread(PSX_RAM,1,sizeof PSX_RAM,file)==sizeof PSX_RAM);fclose(file);
    memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);memset(R,0,sizeof R);
    world_precision_configure(enabled);setup_projection();fixture_wide=1;
    R[4]=0x800157b0;R[5]=0x1f800000;R[31]=0;
    exec1(0x80010c34,fetch(0x80010c34));
    uint32_t sources[4];
    for(unsigned i=0;i<4;i++) {
        sources[i]=R[5]+indices[i]*12;R[6]=sources[i];R[2]=0x80004000;
        gte_data_write(0,pack(posed[i][0],posed[i][1]));gte_data_write(1,posed[i][2]);
        for(uint32_t pc=0x80010d4c;pc<=0x80010dbc;pc+=4)exec1(pc,fetch(pc));
        assert(lw_(sources[i])==pack(xy[i][0],xy[i][1]));
    }
    for(unsigned i=0;i<20;i++)sw_(0x80005000+i*4,face[i]);
    for(unsigned i=0;i<20;i++)sb_(0x80006000+i,0);
    sh_(0x80006000,0xa001);sh_(0x80006002,1);sh_(0x80006004,96);
    sw_(0x80006210,0x80006000);sw_(R[5]+0x3cc,0x80006200);
    sw_(R[4]+0x5e8,0x80007000);sw_(R[4]+0x5ec,0x80007100);
    sh_(0x80007006,8);sh_(0x80007164,0x7af2);
    sw_(R[4]+0x64,0x80110000);sw_(R[4]+0x5f8,0);
    sh_(R[5]+0x3d0,0xffff);sh_(R[5]+0x3d2,0);
    sh_(R[5]+0x3d4,0x0406);sh_(R[5]+0x3d6,0);
    for(unsigned i=0;i<4;i++) {
        sw_(R[5]+0x3b8+i*4,sources[i]);sw_(R[5]+0x3a8+i*4,lw_(sources[i]+4));
        R[16+i*2]=(uint32_t)(int32_t)xy[i][0];R[17+i*2]=(uint32_t)(int32_t)xy[i][1];
    }
    R[2]=0x800f7900;R[3]=0x80005000;R[7]=0x80008000;R[30]=700;
    psx_next=0x800111fc;
    for(unsigned segments=0;psx_next;segments++) {
        assert(segments<16);psx_interp(psx_next);
    }
    world_precision_vertex first[4];
    for(unsigned layer=0;layer<2;layer++) {
        uint32_t packet=0x800f7900+layer*0x38;
        assert(((lw_(packet+8)>>24)&0xfc)==0x3c);
        assert(lh_(packet+0x12)==(layer?0x7af2:0x7bf5));
        assert(lh_(packet+0x1e)==(layer?8:0x66));
        for(unsigned i=0;i<4;i++) {
            uint32_t address=packet+0xc+i*12;world_precision_vertex value;
            assert(lw_(address)==pack(xy[order[i]][0],xy[order[i]][1]));
            assert(world_precision_packet(address,lw_(address),&value)==enabled);
            if(!enabled)continue;
            assert(value.source_address==sources[order[i]]);
            assert(value.producer_pc==0x80010d4c);
            if(!layer)first[i]=value;
            else {
                assert(value.projection_id==first[i].projection_id);
                assert(value.x==first[i].x && value.y==first[i].y && value.z==first[i].z);
                assert(value.generation!=first[i].generation);
            }
        }
    }
    /* The common entry must not turn an unknown/near wrapper caller, or a
     * same-value rewrite of one original source, into usable metadata. */
    for(unsigned negative=0;negative<2;negative++) {
        if(negative)sb_(sources[1],lb_(sources[1]));
        for(unsigned i=0;i<4;i++) {
            R[16+i*2]=(uint32_t)(int32_t)xy[i][0];
            R[17+i*2]=(uint32_t)(int32_t)xy[i][1];
        }
        R[2]=0x800f7900;R[30]=700;
        for(unsigned i=0;i<4;i++)R[8+i]=face[2+i];
        R[14]=face[6];R[15]=face[7];R[24]=face[8];R[1]=face[9];
        R[12]=face[7]>>16;R[13]=face[6]>>16;R[25]=0x80006000;
        R[31]=negative?0x80011334:0x80011400;
        psx_interp(0x80012a78);
        for(unsigned i=0;i<4;i++) {
            uint32_t address=0x800f790c+i*12;world_precision_vertex value;
            assert(!world_precision_packet(address,lw_(address),&value));
        }
    }
    for(unsigned i=0;i<64;i++) {
        uint32_t value=i<32?gte_data_read(i):gte_ctrl_read(i-32);
        if(!enabled)native_gte[i]=value;else assert(value==native_gte[i]);
    }
    if(!enabled) {
        memcpy(native_ram,PSX_RAM,sizeof native_ram);memcpy(native_scratch,PSX_SCRATCH,sizeof native_scratch);
        memcpy(native_registers,R,sizeof R);
    } else {
        assert(!memcmp(native_ram,PSX_RAM,sizeof native_ram));
        assert(!memcmp(native_scratch,PSX_SCRATCH,sizeof native_scratch));
        assert(!memcmp(native_registers,R,sizeof R));
        puts("PASS: captured two-material floor, full direct/wrapper dispatcher, shared source projection IDs; native RAM/scratch/GPR/GTE identical");
    }
    fixture_wide=0;
}

/* Keep a fixed world vertex while signed Q12 camera X crosses zero and
 * whole-number boundaries. Exact retained setup/packing/RTPS instructions
 * must carry the remainder; arming from only an integer screen match fails
 * the source, matrix, lifetime and int16-wrap cases below. */
static world_precision_vertex camera_instruction_case(const uint8_t *base,int actor,
                                                       int32_t camera_x,int fault,int enabled) {
    static uint8_t native_ram[PSX_RAM_SIZE],native_scratch[0x400];
    static uint32_t native_registers[32],native_gte[64];
    memcpy(PSX_RAM,base,PSX_RAM_SIZE);memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);
    memset(R,0,sizeof R);world_precision_configure(1);world_camera_configure(enabled);
    setup_projection();fixture_wide=0;
    const uint32_t object=0x80002000,matrix=0x80003000,context=0x800157b0;
    memset(PSX_RAM+0x2000,0,0x100);memset(PSX_RAM+0x3000,0,20);
    sh_(matrix,4096);sh_(matrix+8,4096);sh_(matrix+16,4096);
    if(fault==16)sw_(matrix+16,0x1234f000); /* NegativeR33, nonzero unused padding. */
    sw_(object+0x1c,matrix);sw_(object+0x2c,(uint32_t)camera_x);
    R[4]=object;R[29]=0x80007000;
    uint32_t begin=actor?0x80012e68:0x800100a8;
    uint32_t last=actor?0x80012f0c:0x80010170;
    for(uint32_t pc=begin;pc<=last;pc+=4)exec1(pc,fetch(pc));
    R[4]=context;R[5]=0x1f800000;R[30]=0x80004000;
    sw_(context+0x5cc,0);
    exec1(actor?0x80013194:0x80010c34,fetch(actor?0x80013194:0x80010c34));
    if(fault==17 || fault==18) {
        /* Refresh the camera setup while a previous object generation is
         * still current. Only the real following object entry may reuse it. */
        R[4]=object;
        for(uint32_t pc=begin;pc<=last;pc+=4)exec1(pc,fetch(pc));
        R[4]=context;R[5]=0x1f800000;R[30]=0x80004000;
        if(fault==18)exec1(actor?0x80013194:0x80010c34,fetch(actor?0x80013194:0x80010c34));
    }
    int32_t whole=camera_x/4096-(camera_x<0 && camera_x%4096!=0);
    R[8]=(uint32_t)(100-whole);R[9]=100;R[10]=600;
    if(fault==16)R[10]=(uint32_t)-600;
    R[2]=0x80004000;R[6]=0x1f800000;
    for(unsigned i=0;i<5;i++)R[11+i]=lw_(matrix+i*4);
    if(!actor)for(uint32_t pc=0x80010d08;pc<=0x80010d18;pc+=4)exec1(pc,fetch(pc));
    switch(fault) {
    case 1:sw_(object+0x2c,(uint32_t)camera_x-1);break; /* Fraction changes within same integer cell. */
    case 2:sw_(context+4,1);break;
    case 3:sw_(context+0x68,object+4);break;
    case 4:sw_(matrix,lw_(matrix)^1);break;
    case 5:R[8]=32768;break; /* X would silently truncate into int16. */
    case 6:R[10]=65536+600;break; /* Z wraps to the same plausible native600. */
    case 7:sw_(context+0x5cc,0x100);break;
    case 8:exec1(actor?0x80010c34:0x80013194,fetch(actor?0x80010c34:0x80013194));break;
    case 9:sw_(0x80010000,lw_(0x80010000)^1);break;
    case 10:sw_(0x80010000,lw_(0x80010000));break; /* Same code write changes source epoch. */
    }
    uint32_t pack_begin=actor?0x80013350:0x80010d28;
    uint32_t project=actor?0x8001338c:0x80010d4c;
    for(uint32_t pc=pack_begin;pc<project;pc+=4)exec1(pc,fetch(pc));
    if(fault==11)gte_ctrl_write(0,gte_ctrl_read(0)^1);
    if(fault==12)gte_data_write(0,pack(120,100));
    if(fault==13)exec1(actor?0x80013194:0x80010c34,fetch(actor?0x80013194:0x80010c34));
    if(fault==14)exec1(actor?0x800130c0:0x8001041c,fetch(actor?0x800130c0:0x8001041c));
    if(fault==15)project=0x800104ac; /* Another RTPS is not an implied producer. */
    exec1(project,fetch(project));
    world_precision_vertex value={0};
    int valid=world_precision_gte_read(14,gte_data_read(14),&value);
    if(enabled && (!fault || fault==16 || fault==18)) {
        assert(valid && value.projection_kind==WORLD_PROJECTION_CAMERA);
        assert(value.camera_generation==wp_object);
    } else if(valid)assert(value.projection_kind==WORLD_PROJECTION_NATIVE_Q16);
    for(unsigned i=0;i<64;i++) {
        uint32_t word=i<32?gte_data_read(i):gte_ctrl_read(i-32);
        if(!enabled)native_gte[i]=word;else assert(word==native_gte[i]);
    }
    if(!enabled) {
        memcpy(native_ram,PSX_RAM,sizeof native_ram);memcpy(native_scratch,PSX_SCRATCH,sizeof native_scratch);
        memcpy(native_registers,R,sizeof R);
    } else {
        assert(!memcmp(native_ram,PSX_RAM,sizeof native_ram));
        assert(!memcmp(native_scratch,PSX_SCRATCH,sizeof native_scratch));
        assert(!memcmp(native_registers,R,sizeof R));
    }
    return value;
}
static void retained_camera_route(const char *path) {
    static uint8_t base[PSX_RAM_SIZE];
    FILE *file=fopen(path,"rb");assert(file);
    assert(fread(base,1,sizeof base,file)==sizeof base);fclose(file);
    static const int32_t raw[]={-4097,-4096,-4095,-1,0,1,4095,4096,4097};
    /* Independently evaluated exact rational 160+96*(100-raw/4096)/600,
     * expressed as floor(Q16). Allow one Q16 unit for final quantization. */
    static const int32_t xq[]={11544824,11544821,11544819,11534338,11534336,
                              11534333,11523852,11523850,11523847};
    for(unsigned i=0;i<sizeof raw/sizeof raw[0];i++) {
        world_precision_vertex world={0};
        for(int actor=0;actor<2;actor++) {
            camera_instruction_case(base,actor,raw[i],0,0);
            world_precision_vertex v=camera_instruction_case(base,actor,raw[i],0,1);
            assert(fabs(v.x-(double)xq[i]/65536)<1.01/65536);
            assert(v.y==140 && v.z==600);
            if(!actor)world=v;else assert(v.x==world.x && v.y==world.y && v.z==world.z);
        }
    }
    for(int actor=0;actor<2;actor++)for(int fault=1;fault<=17;fault++) {
        if(fault==16 || (fault==7 && !actor))continue;
        camera_instruction_case(base,actor,-1,fault,0);
        camera_instruction_case(base,actor,-1,fault,1);
    }
    for(int actor=0;actor<2;actor++) {
        camera_instruction_case(base,actor,-1,16,0);
        world_precision_vertex v=camera_instruction_case(base,actor,-1,16,1);
        assert(fabs(v.x-176.0000390625)<1.01/65536 && v.y==140 && v.z==600);
        camera_instruction_case(base,actor,-1,18,0);
        v=camera_instruction_case(base,actor,-1,18,1);
        assert(fabs(v.x-176.0000390625)<1.01/65536 && v.y==140 && v.z==600);
    }
    world_camera_configure(0);
    puts("PASS: retained WORLD/ACTOR camera setup and packing, signed fractional crossings, source/matrix/lifetime rejects; native RAM/scratch/GPR/GTE identical");
}

int main(int argc,char **argv) {
    accumulator44();memory_writes();saturated_projection();actual_gte();
    if(argc>1) {
        retained_world_route(argv[1],0);retained_world_route(argv[1],1);
        retained_triangle_route(argv[1],0);retained_triangle_route(argv[1],1);
        retained_actor_route(argv[1],0);retained_actor_route(argv[1],1);
        retained_world_materials(argv[1],0);retained_world_materials(argv[1],1);
        retained_camera_route(argv[1]);
    }
    puts("PASS: real memory writes and GTE precision/native equivalence");
    return 0;
}
