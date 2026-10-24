/* -finstrument-functions observes the real dispatch calls, including inlined
 * calls. The release contains no counters or instrumentation. */
#define main trace_fixture_main
#include "test_world_trace.c"
#undef main
static unsigned before_calls,store_calls;
void __attribute__((no_instrument_function))
__cyg_profile_func_enter(void *function,void *caller) {
    (void)caller;
    if(function==(void *)wp_before)before_calls++;
    if(function==(void *)wp_after_store)store_calls++;
}
void __attribute__((no_instrument_function))
__cyg_profile_func_exit(void *function,void *caller) {(void)function;(void)caller;}
static int listed(uint32_t pc,const uint32_t *sites,size_t count) {
    for(size_t i=0;i<count;i++)if(sites[i]==pc)return 1;
    return 0;
}
int main(void) {
    /* Independent instruction contracts, including NOP/delay-slot hooks. */
    static const uint32_t before[]={
        0x800100a8,0x8001011c,0x8001041c,0x80010c34,0x80010d28,0x80010d4c,
        0x800126c8,0x80012e68,0x80012edc,0x800130c0,0x800130f8,0x80013194,
        0x80013350,0x8001338c,0x800138b8,0x80013cbc};
    static const uint32_t stores[]={
        0x80010dac,0x800128ac,0x80012988,0x80013408,0x8001341c,
        0x80013f04,0x80013ff8,0x80014140,0x80014248};
    setup();
    before_calls=0;exec1(0x80011000,0);
    assert(before_calls==0); /* RED: original unconditional before dispatch. */
    for(uint32_t pc=0x8000fff0;pc<0x80014310;pc++) {
        before_calls=0;exec1(pc,0);
        assert(before_calls==(unsigned)listed(pc,before,sizeof before/sizeof before[0]));
        store_calls=0;exec1(pc,0xac000000); /* SW zero,0(zero), benign real write. */
        assert(store_calls==(unsigned)listed(pc,stores,sizeof stores/sizeof stores[0]));
    }
    const uint32_t aliases[]={0,0x100a8,0xa00100a8,0x80020000,UINT32_MAX};
    for(unsigned i=0;i<sizeof aliases/sizeof aliases[0];i++) {
        before_calls=store_calls=0;exec1(aliases[i],0);exec1(aliases[i],0xac000000);
        assert(before_calls==0 && store_calls==0);
    }
    /* 1041C is executed before the terminal call overwrites shared scratch. */
    wp_camera.valid=1;wp_camera_input.object=99;
    before_calls=0;exec1(0x8001041c,0);
    assert(before_calls==1 && !wp_camera.valid && !wp_camera_input.object);
    const uint32_t producers[]={0,0x80008000,0x80011000,0x80014300,0xa0010000,UINT32_MAX};
    for(unsigned i=0;i<sizeof producers/sizeof producers[0];i++) {
        wp_camera_input.object=99;before_calls=0;
        exec1(producers[i],0x4a000006); /* Intervening NCLIP, any PC. */
        assert(before_calls==1 && !wp_camera_input.object);
    }
    wp_camera_input.object=99;before_calls=0;
    exec1(0x80011000,0x4a180001); /* Unknown RTPS must also retire staged input. */
    assert(before_calls==1 && !wp_camera_input.object);
    wp_pending.projection_id=777;before_calls=0;
    exec1(0x80011000,0x02609825); /* OR s3,s3,zero: identical SET still revokes. */
    assert(before_calls==0 && !wp_pending.projection_id);
    uint32_t source=0x80002000,word=0;
    world_precision_vertex value={.projection_id=world_precision_begin_object(),.native_word=word};
    uint64_t object=world_precision_begin_object();
    world_precision_record(source,word,object,&value);
    assert(lookup(source,word,1));R[8]=source;R[9]=word;
    store_calls=0;exec1(0x80011000,0xad090000); /* Identical SW outside known hook PCs. */
    assert(!lookup(source,word,1) && store_calls==0);
    puts("PASS: exact before/store dispatch, NOP fences, all-PC GTE fences and native write invalidation");
    return 0;
}
