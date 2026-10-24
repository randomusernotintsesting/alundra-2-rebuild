#define main world_transport_previous_main
#include "test_world_precision_gpu.c"
#undef main

static void modern_points(void) {
    WorldFinePoint fine[4];
    Vtx v[4]={{.x=10,.y=10},{.x=20,.y=10},{.x=10,.y=20},{.x=20,.y=20}};
    gpu_gp1(0);
    for(int i=0;i<4;i++)world_vertices[i]=(world_precision_vertex){
        .x=v[i].x-0.75,.y=v[i].y+0.25,.z=1000,
        .native_word=xy[i],.projection_id=10+i,.generation=20,
        .projection_kind=WORLD_PROJECTION_CAMERA,.camera_generation=8};
    assert(world_fine_points(fine,v,4));
    for(int i=0;i<4;i++) {
        assert(fine[i].x==(int64_t)v[i].x*65536-49152);
        assert(fine[i].y==(int64_t)v[i].y*65536+16384);
    }
    world_precision_vertex saved=world_vertices[3];
    for(int bad=0;bad<9;bad++) {
        world_vertices[3]=saved;
        switch(bad) {
        case 0: world_vertices[3].projection_kind=WORLD_PROJECTION_NATIVE_Q16;break;
        case 1: world_vertices[3].projection_kind=99;break;
        case 2: world_vertices[3].camera_generation=0;break;
        case 3: world_vertices[3].camera_generation++;break;
        case 4: world_vertices[3].x=NAN;break;
        case 5: world_vertices[3].x=1024;break;
        case 6: world_vertices[3].z=0;break;
        case 7: world_vertices[3].native_word++;break;
        case 8: world_vertices[3].x+=0.1;break;
        }
        assert(!world_fine_points(fine,v,4));
    }
    world_vertices[3]=saved;
    for(int i=0;i<4;i++) {
        world_vertices[i].projection_kind=WORLD_PROJECTION_NATIVE_Q16;
        world_vertices[i].camera_generation=0;
    }
    assert(!world_fine_points(fine,v,4)); /* Legacy contract still owns its cell. */
    for(int i=0;i<4;i++)world_vertices[i].x=v[i].x+0.25;
    assert(world_fine_points(fine,v,4));
}

int main(void) {
    world_transport_previous_main();
    modern_points();
    puts("PASS: complete modern primitive bounds/identity and unchanged legacy cell contract");
}
