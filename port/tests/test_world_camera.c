/* Independent analytical camera crossing and native-proof contract. */
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "../src/world_precision.h"

static uint32_t word(int x,int y) {
    return (uint16_t)x | ((uint32_t)(uint16_t)y<<16);
}
static const int16_t identity[9]={4096,0,0,0,4096,0,0,0,4096};

#ifdef A2_CAMERA_BASELINE
/* Run the same arithmetic assertions against the pre-feature projection. */
static void baseline_configure(int enabled) {(void)enabled;}
static void baseline_arm(uint32_t pc,const uint32_t rem[3],uint64_t gen) {
    (void)pc;(void)rem;(void)gen;
}
static void baseline_project(const int64_t mac[3],const int16_t rot[9],
                             int32_t h,int32_t x,int32_t y,int wide) {
    (void)mac;(void)rot;(void)h;(void)x;(void)y;(void)wide;
}
#define world_camera_configure baseline_configure
#define world_precision_camera_arm baseline_arm
#define world_precision_camera_project baseline_project
#endif

static world_precision_vertex position(int raw_camera,uint32_t producer) {
    world_precision_configure(1);world_camera_configure(1);
    uint64_t generation=world_precision_begin_object();
    int integer=raw_camera/4096-(raw_camera<0 && raw_camera%4096!=0);
    uint32_t remainder[3]={(uint32_t)(raw_camera-integer*4096),0,0};
    int vx=10-integer;
    int64_t mac[3]={(int64_t)vx*4096,0,1000*4096};
    /* H100/Z1000 rounds to native GTE divisor6554. */
    int64_t native_x=160*65536+(int64_t)6554*vx;
    uint32_t native=word((int)(native_x/65536),124);
    world_precision_producer_pc=producer;
    world_precision_camera_arm(producer,remainder,generation);
    world_precision_gte_push(native,native_x,124*65536,1000,1);
    world_precision_camera_project(mac,identity,100,160*65536,124*65536,0);
    world_precision_vertex got;
    assert(world_precision_gte_read(14,native,&got));
    assert(got.native_word==native);
    assert(got.projection_kind==WORLD_PROJECTION_CAMERA);
    assert(got.camera_generation==generation);
    return got;
}

static void camera_crossings(void) {
    const int cameras[]={-1024,3072,4096,5120};
    /* Independent rational X160+(10-camera)/10, rounded down at Q16. */
    const int expected[]={10552934,10546380,10544742,10543104};
    for(unsigned i=0;i<4;i++) {
        world_precision_vertex world=position(cameras[i],0x80010d4c);
        world_precision_vertex actor=position(cameras[i],0x8001338c);
        assert(world.x*65536==expected[i]);
        assert(world.y==124 && world.z==1000);
        assert(actor.x==world.x && actor.y==world.y && actor.z==world.z);
        if(i==1)assert(floor(world.x)!=(int16_t)world.native_word);
    }
}

static void one_shot_and_rejections(void) {
    world_precision_vertex got;
    uint32_t native=word(161,124),remainder[]={3072,0,0};
    const int64_t mac[]={10*4096,0,1000*4096};
    for(unsigned bad=0;bad<7;bad++) {
        world_precision_configure(1);world_camera_configure(1);
        uint64_t gen=world_precision_begin_object();
        world_precision_producer_pc=0x80010d4c;
        uint32_t rem[3]={remainder[0],0,0};
        if(bad==0)rem[0]=4096;
        world_precision_camera_arm(bad==1?0x80010000:0x80010d4c,rem,bad==2?0:gen);
        if(bad==3)world_precision_reset();
        if(bad==4)world_precision_producer_pc=0x8001338c;
        if(bad==5)world_precision_gte_write(0);
        world_precision_gte_push(native,161*65536,124*65536,1000,1);
        int64_t values[3]={mac[0],mac[1],bad==6?0:mac[2]};
        world_precision_camera_project(values,identity,100,160*65536,124*65536,0);
        assert(world_precision_gte_read(14,native,&got));
        assert(got.projection_kind==WORLD_PROJECTION_NATIVE_Q16);
    }
    (void)position(3072,0x80010d4c);
    world_precision_gte_push(native,161*65536,124*65536,1000,1);
    world_precision_camera_project(mac,identity,100,160*65536,124*65536,0);
    assert(world_precision_gte_read(14,native,&got));
    assert(got.projection_kind==WORLD_PROJECTION_NATIVE_Q16);
}

static void rotated_depth_and_wide(void) {
    /* Rotation maps (X,Y,Z) to (Y,-Z,X), with all camera fractions nonzero.
     * Corrected camera-space XYZ=(19.5,-29.25,999.75). */
    const int16_t rotation[]={0,4096,0,0,0,-4096,4096,0,0};
    const int64_t mac[]={20*4096,-30*4096,1000*4096};
    const uint32_t remainder[]={1024,2048,3072};
    const int64_t expected_x[]={10613587,10581630};
    for(int wide=0;wide<2;wide++) {
        world_precision_configure(1);world_camera_configure(1);
        uint64_t gen=world_precision_begin_object();
        world_precision_producer_pc=0x80010d4c;
        world_precision_camera_arm(0x80010d4c,remainder,gen);
        uint32_t native=word(162,121);
        world_precision_gte_push(native,162*65536,121*65536,1000,1);
        world_precision_camera_project(mac,rotation,100,160*65536,124*65536,wide);
        world_precision_vertex got;
        assert(world_precision_gte_read(14,native,&got));
        assert(got.projection_kind==WORLD_PROJECTION_CAMERA);
        assert(got.z==999.75);
        assert(got.x*65536==expected_x[wide]);
        assert(got.y*65536==7934723);
    }
}

static void transport_and_invalid_projection(void) {
    world_precision_vertex camera_value=position(3072,0x80010d4c),got;
    uint64_t object=camera_value.camera_generation;
    uint32_t words[3]={camera_value.native_word,camera_value.native_word,camera_value.native_word};
    uint32_t sources[3]={0x1f800000,0x1f80000c,0x1f800018};
    uint32_t dest[3]={0x80090004,0x80090008,0x8009000c};
    for(int i=0;i<3;i++)world_precision_record(sources[i],words[i],object,&camera_value);
    assert(world_precision_emit(dest,words,sources,3,object));
    assert(world_precision_packet(dest[0],words[0],&got));
    assert(got.projection_kind==WORLD_PROJECTION_CAMERA && got.x==camera_value.x);
    /* A stale camera cannot be reused as another source object. */
    uint64_t next=world_precision_begin_object();
    world_precision_record(sources[1],words[1],next,&camera_value);
    assert(!world_precision_emit(dest,words,sources,3,object));
    for(int i=0;i<3;i++)assert(!world_precision_packet(dest[i],words[i],&got));
    for(int i=0;i<3;i++)world_precision_record(sources[i],words[i],object,&camera_value);
    world_precision_vertex legacy=camera_value;
    legacy.projection_kind=WORLD_PROJECTION_NATIVE_Q16;legacy.camera_generation=0;
    world_precision_record(sources[1],words[1],object,&legacy);
    assert(!world_precision_emit(dest,words,sources,3,object));
    for(int i=0;i<3;i++)assert(!world_precision_packet(dest[i],words[i],&got));

    for(int bad=0;bad<6;bad++) {
        world_precision_configure(1);world_camera_configure(1);
        object=world_precision_begin_object();
        uint32_t remainder[3]={0,0,0};
        int64_t mac[3]={10*4096,0,1000*4096};
        if(bad==1)mac[0]=INT64_C(1)<<43;
        if(bad==2)mac[2]=65536LL*4096;
        if(bad==3)mac[2]=50*4096;
        if(bad==4)mac[0]=1000000LL*4096;
        world_precision_producer_pc=0x80010d4c;
        world_precision_camera_arm(0x80010d4c,remainder,object);
        world_precision_gte_push(words[0],161*65536,124*65536,1000,bad!=0);
        world_precision_camera_project(mac,identity,bad==5?0:100,160*65536,124*65536,0);
        if(bad==0)assert(!world_precision_gte_read(14,words[0],&got));
        else {
            assert(world_precision_gte_read(14,words[0],&got));
            assert(got.projection_kind==WORLD_PROJECTION_NATIVE_Q16);
        }
    }
}

/* A camera coordinate can saturate IR1/IR2 while its screen position and
 * depth remain valid. Recover the shared projection, retaining the actual
 * GTE coordinate clamp, so adjoining complete and saturated faces agree. */
static void saturated_camera_coordinates(void) {
    static const struct { int32_t x,y,z;int64_t xq,yq; } cases[]={
        {40000,0,40000,15639563,8126464},
        {-40000,0,40000,5331799,8126464},
        {0,40000,40000,10485760,13280267},
        {0,-40000,40000,10485760,2972503},
        {40000,-40000,40000,15639563,2972503},
    };
    for(unsigned i=0;i<sizeof cases/sizeof cases[0];i++) {
        world_precision_configure(1);world_camera_configure(1);
        uint64_t gen=world_precision_begin_object();
        world_precision_producer_pc=0x80010d54;
        const uint32_t remainder[3]={0,0,0};
        world_precision_camera_arm(0x80010d54,remainder,gen);
        uint32_t native=word(160,124);
        world_precision_gte_push(native,160*65536,124*65536,cases[i].z,1);
        const int64_t mac[3]={(int64_t)cases[i].x*4096,(int64_t)cases[i].y*4096,(int64_t)cases[i].z*4096};
        world_precision_camera_project(mac,identity,96,160*65536,124*65536,0);
        world_precision_vertex got;
        assert(world_precision_gte_read(14,native,&got));
        assert(got.projection_kind==WORLD_PROJECTION_CAMERA);
        assert(got.x*65536==cases[i].xq && got.y*65536==cases[i].yq);
    }
}

int main(void) {
    saturated_camera_coordinates();
    camera_crossings();
    one_shot_and_rejections();
    rotated_depth_and_wide();
    transport_and_invalid_projection();
    puts("PASS: continuous WORLD/ACTOR camera crossing, native word proof and one-shot rejection");
}
