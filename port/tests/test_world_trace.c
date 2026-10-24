/* Exercise real GTE/interpreter provenance while counting only the reads
 * those callers request. The wrappers delegate to the real implementation. */
#define A2_WORLD_PRECISION 1
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/world_precision.h"
static unsigned gte_reads,packet_reads;
static int counted_gte_read(int reg,uint32_t word,world_precision_vertex *out);
static int counted_packet(uint32_t address,uint32_t word,world_precision_vertex *out);
#define world_precision_gte_read counted_gte_read
#define world_precision_packet counted_packet
#include "../src/gte.c"
#include "../src/interp.c"
#undef world_precision_gte_read
#undef world_precision_packet
#include "../src/world_precision.c"

uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
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
int a2_wide(void) {return 0;}
static int counted_gte_read(int reg,uint32_t word,world_precision_vertex *out) {
    gte_reads++;return world_precision_gte_read(reg,word,out);
}
static int counted_packet(uint32_t address,uint32_t word,world_precision_vertex *out) {
    packet_reads++;return world_precision_packet(address,word,out);
}
static void setup(void) {
    world_precision_configure(1);world_camera_configure(1);
    for(int r=0;r<32;r++) {gte_data_write(r,0);gte_ctrl_write(r,0);}
    gte_ctrl_write(0,4096);gte_ctrl_write(2,4096);gte_ctrl_write(4,4096);
    gte_ctrl_write(24,160u<<16);gte_ctrl_write(25,124u<<16);gte_ctrl_write(26,96);
    /* This fixture isolates trace preparation, not code fingerprinting.
     * Retained-instruction identity is exercised by world_precision_runtime. */
    wp_code_checked=world_precision_code_version;wp_code_valid=1;
}
static void drive(uint32_t frame,int expected,int check) {
    setup();psx_frame_no=frame;
    wp_kind=WP_WORLD;wp_object=world_precision_begin_object();
    uint32_t remainder[]={1,4095,2048};
    gte_data_write(0,100u|(100u<<16));gte_data_write(1,600);
    world_precision_producer_pc=0x80010d4c;
    world_precision_camera_arm(world_precision_producer_pc,remainder,wp_object);
    gte_reads=packet_reads=0;gte_cmd(0x180001);
    if(check)assert(gte_reads==(expected?2u:0u));
    uint32_t word=gte_data_read(14);
    world_precision_vertex vertex;
    assert(world_precision_gte_read(14,word,&vertex));
    assert(vertex.projection_kind==WORLD_PROJECTION_CAMERA);
    unsigned before=gte_reads;
    wp_mfc2(0x80010d98,14,word);
    assert(gte_reads==before+1); /* This read is semantic even with tracing off. */
    assert(wp_pending.projection_id==vertex.projection_id);
    uint32_t source=0x1f800000;
    sw_(source,word);wp_after_store(0x80010dac,0xacd30000,source,word);
    assert(!wp_pending.projection_id);
    for(unsigned i=0;i<4;i++) {
        wp_sources[i]=source+i*12;
        sw_(wp_sources[i],word);world_precision_record(wp_sources[i],word,wp_object,&vertex);
    }
    for(int actor=0;actor<2;actor++) {
        wp_emit_active=1;wp_emit_kind=wp_kind=actor?WP_ACTOR:WP_WORLD;
        wp_emit_object=wp_object;wp_emit_count=4;wp_emit_stride=12;
        wp_emit_base=R[2]=0x80100000u+(unsigned)actor*0x100;
        wp_emit_finish=actor?0x80014140u:0x800128acu;wp_emit_format=0x3c;
        sw_(wp_emit_base+8,0x3c808080);
        for(unsigned i=0;i<4;i++)sw_(wp_emit_base+0xc+i*12,word);
        packet_reads=0;
        wp_after_store(wp_emit_finish,0xac570020,wp_emit_base+0x20,word);
        if(check)assert(packet_reads==(expected?4u:0u));
        assert(!wp_emit_active);
        for(unsigned i=0;i<4;i++) {
            world_precision_vertex output;
            assert(world_precision_packet(wp_emit_base+0xc+i*12,word,&output));
            assert(output.projection_id==vertex.projection_id && output.x==vertex.x &&
                   output.y==vertex.y && output.z==vertex.z);
        }
    }
}
/* RTPT's FLAG is sticky across its vertices. An off-screen first vertex
 * (saturated SX) must not remove provenance from its on-screen siblings,
 * while the guest still observes the accumulated FLAG. */
static void rtpt_per_vertex_flag(void) {
    setup();psx_frame_no=1;
    wp_kind=WP_WORLD;wp_object=world_precision_begin_object();world_precision_producer_pc=0x800155d8;
    gte_data_write(0,20000u|(0u<<16));gte_data_write(1,600);
    gte_data_write(2,100u|(100u<<16));gte_data_write(3,600);
    gte_data_write(4,(uint16_t)-50|(20u<<16));gte_data_write(5,600);
    gte_cmd(0x280030);
    assert(gte_ctrl_read(31)&(1u<<14));
    world_precision_vertex v;
    assert(!world_precision_gte_read(12,gte_data_read(12),&v));
    assert(world_precision_gte_read(13,gte_data_read(13),&v));
    assert(world_precision_gte_read(14,gte_data_read(14),&v));
}
int main(int argc,char **argv) {
    rtpt_per_vertex_flag();
    const char *mode=argc>1?argv[1]:"off";
    if(!strcmp(mode,"journal")) {
        for(uint32_t frame=9;frame<13;frame++)drive(frame,0,0);
    } else if(!strcmp(mode,"cap")) {
        world_precision_configure(1);
        for(unsigned i=0;i<29999;i++)world_precision_trace_miss(10,"padding",0,i,0);
#ifndef A2_TRACE_TEST_LEGACY
        for(unsigned i=0;i<100;i++)assert(world_precision_trace_active(10));
#endif
        /* Only project-native fits. Later vertex copies/packet reads are
         * unnecessary, while semantic projection and publication must work. */
        drive(10,0,0);
#ifndef A2_TRACE_TEST_LEGACY
        assert(!world_precision_trace_active(10));
        drive(10,0,1);
#else
        drive(10,0,0);
#endif
    } else {
        int active=!strcmp(mode,"on");
        uint32_t frame=!strcmp(mode,"before")?9u:!strcmp(mode,"after")?11u:10u;
#ifndef A2_TRACE_TEST_LEGACY
        world_precision_configure(1);
        for(unsigned i=0;i<100;i++)assert(world_precision_trace_active(frame)==active);
#endif
        drive(frame,active,1);
    }
    puts("PASS: trace preparation, semantic MFC2/publication, and journal limits");
    return 0;
}
