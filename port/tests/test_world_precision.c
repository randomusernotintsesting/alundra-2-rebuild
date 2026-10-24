/* CPU-only provenance contract: no SDL, replay, disc, save or card access. */
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "../src/world_precision.h"

static const uint32_t word = 0x005400b5;
static world_precision_vertex project(void) {
    world_precision_vertex v;
    world_precision_producer_pc = 0x80010d4c;
    world_precision_gte_push(word, 11926912, 5557744, 943.25, 1);
    assert(world_precision_gte_read(14, word, &v));
    assert(v.x == 181.990234375 && v.y == 84.804443359375);
    assert(v.producer_pc == 0x80010d4c && v.projection_id);
    return v;
}

static void aliases_and_packet_lifetime(void) {
    world_precision_configure(1);
    uint64_t object = world_precision_begin_object();
    world_precision_vertex v = project(), got;
    uint32_t src[] = {0x1f800090,0x1f80009c,0x1f8000a8,0x1f8000b4};
    uint32_t dst[] = {0x800f790c,0x800f7918,0x800f7924,0x800f7930};
    uint32_t words[] = {word,word,word,word};
    for (unsigned i=0; i<4; i++) world_precision_record(src[i],word,object,&v);
    assert(world_precision_emit(dst,words,src,4,object));
    uint64_t packet_generation = 0;
    for (unsigned i=0; i<4; i++) {
        assert(world_precision_packet(dst[i]&0x1fffff,word,&got));
        assert(world_precision_packet(dst[i]+0x20200000,word,&got));
        assert(got.source_address==src[i]);
        if (i) assert(got.generation==packet_generation);
        packet_generation=got.generation;
    }
    assert(!world_precision_packet(0x1f800090,word,&got)); /* record isn't packet */
    assert(!world_precision_packet(0x80000090,word,&got)); /* scratch isn't RAM */
    assert(!world_precision_packet(dst[0]+4,word,&got)); /* XY equality isn't identity */
    assert(!world_precision_packet(dst[0],word+1,&got));
    uint64_t next_object=world_precision_begin_object();
    world_precision_invalidate(0xbf800090,4);
    world_precision_record(src[0],word,next_object,&v);
    assert(world_precision_packet(dst[0],word,&got)); /* OT consumes old buffer later */
    assert(!world_precision_emit(dst,words,src,4,next_object));
    for (unsigned i=0; i<4; i++) assert(!world_precision_packet(dst[i],word,&got));
}

static void invalidation_and_complete_fallback(void) {
    uint32_t src[]={0x80000200,0x8000020c,0x80000218,0x80000224};
    uint32_t dst[]={0x8001000c,0x80010018,0x80010024,0x80010030};
    uint32_t words[]={word,word,word,word};
    for (unsigned lane=0; lane<4; lane++) {
        world_precision_configure(1);
        uint64_t object=world_precision_begin_object();
        world_precision_vertex v=project(),got;
        for(unsigned i=0;i<4;i++) world_precision_record(src[i],word,object,&v);
        assert(world_precision_emit(dst,words,src,4,object));
        /* Even an identical byte overwrite revokes the old provenance. */
        world_precision_invalidate(dst[0]+lane,1);
        assert(!world_precision_packet(dst[0],word,&got));
        assert(world_precision_packet(dst[1],word,&got));
        world_precision_invalidate(src[2]+3,2);
        assert(!world_precision_emit(dst,words,src,4,object));
        for(unsigned i=0;i<4;i++) assert(!world_precision_packet(dst[i],word,&got));
    }
    world_precision_vertex v=project(),got;
    uint64_t object=world_precision_begin_object();
    for(unsigned i=0;i<4;i++) world_precision_record(src[i],word,object,&v);
    assert(world_precision_emit(dst,words,src,4,object));
    world_precision_invalidate(dst[0]-1,64); /* bulk range and partial overlap */
    for(unsigned i=0;i<4;i++) assert(!world_precision_packet(dst[i],word,&got));
    for(unsigned i=0;i<4;i++) world_precision_record(src[i],word,object,&v);
    assert(world_precision_emit(dst,words,src,4,object));
    world_precision_reset();
    assert(!world_precision_packet(dst[0],word,&got));
    assert(!world_precision_gte_read(14,word,&got));
    for(unsigned i=0;i<4;i++) world_precision_record(src[i],word,object,&v);
    assert(!world_precision_emit(dst,words,src,4,object)); /* stale host snapshots */
    world_precision_configure(0);
    world_precision_gte_push(word,1,1,1,1);
    assert(!world_precision_gte_read(14,word,&got));
}

static void fifo_and_clamps(void) {
    world_precision_configure(1);
    world_precision_vertex a=project(), b=project(), c=project(),got;
    assert(a.projection_id < b.projection_id && b.projection_id < c.projection_id);
    assert(world_precision_gte_read(12,word,&got) && got.projection_id==a.projection_id);
    assert(world_precision_gte_read(13,word,&got) && got.projection_id==b.projection_id);
    assert(world_precision_gte_read(14,word,&got) && got.projection_id==c.projection_id);
    world_precision_gte_write(14);
    assert(!world_precision_gte_read(14,word,&got));
    assert(world_precision_gte_read(13,word,&got));
    world_precision_gte_write(15);
    assert(world_precision_gte_read(12,word,&got) && got.projection_id==b.projection_id);
    assert(!world_precision_gte_read(13,word,&got));
    assert(!world_precision_gte_read(14,word,&got));
    (void)project();
    world_precision_gte_write(12);
    assert(!world_precision_gte_read(12,word,&got));
    world_precision_gte_push(word,0,0,1,0); /* saturated/native overflow */
    assert(!world_precision_gte_read(14,word,&got));
    world_precision_gte_push(word,0,0,NAN,1);
    assert(!world_precision_gte_read(14,word,&got));
    world_precision_gte_push(word,0,0,-1,1);
    assert(!world_precision_gte_read(14,word,&got));
}

static void wrapped_bulk_and_collisions(void) {
    world_precision_configure(1);
    uint64_t object=world_precision_begin_object();
    world_precision_vertex v=project(),got;
    uint32_t src[]={0x80000200,0x8000020c,0x80000218};
    uint32_t words[]={word,word,word};
    uint32_t dst[]={0x801ffffc,0x80000000,0x80000004};
    for(unsigned i=0;i<3;i++) world_precision_record(src[i],word,object,&v);
    assert(world_precision_emit(dst,words,src,3,object));
    world_precision_invalidate(0xa07ffffe,6); /* DMA crosses a 2 MiB RAM mirror */
    assert(!world_precision_packet(dst[0],word,&got));
    assert(!world_precision_packet(dst[1],word,&got));
    assert(world_precision_packet(dst[2],word,&got));
    uint32_t collision[]={0x8001000c,0x80030008,0x80010024};
    assert(!world_precision_emit(collision,words,src,3,object));
    for(unsigned i=0;i<3;i++) assert(!world_precision_packet(collision[i],word,&got));
}

static void immutable_code_range_excludes_renderer_context(void) {
    /* The standalone provenance unit receives the selected code boundary.
     * Interpreter tests verify selection against the actual GAME/EVENT images. */
    const uint32_t contexts[]={0x157b0u,0x15ea0u};
    for(unsigned profile=0;profile<2;profile++) {
        world_precision_configure(1);
        world_precision_code_end=contexts[profile];
        uint64_t object=world_precision_begin_object();
        world_precision_vertex v=project(),got;
        uint32_t src[]={0x80000200,0x8000020c,0x80000218};
        uint32_t context=0x80000000u|contexts[profile];
        uint32_t dst[]={context,context+12,context+24};
        uint32_t words[]={word,word,word};
        for(unsigned i=0;i<3;i++)world_precision_record(src[i],word,object,&v);
        assert(world_precision_emit(dst,words,src,3,object));
        uint64_t version=world_precision_code_version;
        world_precision_invalidate(context,4);
        assert(world_precision_code_version==version); /* Mutable data. */
        assert(!world_precision_packet(dst[0],word,&got));
        world_precision_invalidate(context-1,1);
        assert(world_precision_code_version==version+1); /* Last code byte. */
    }
    world_precision_reset();
    uint64_t version=world_precision_code_version;
    world_precision_invalidate(0x80015d00,4);
    assert(world_precision_code_version==version+1); /* Unknown image: full extent. */
}

/* Observed EVENT frame6000: a packet XY at00103E70 hashes onto the
 * still-live scratch vertex1F800150, despite distinct native addresses.
 * Emitting one face must not remove a vertex needed by the next face. */
static void source_and_packet_collision_keeps_both_lifetimes(void) {
    world_precision_configure(1);
    uint64_t object=world_precision_begin_object();
    world_precision_vertex v=project(),got;
    const uint32_t src[]={0x1f800150,0x1f800160,0x1f800170};
    const uint32_t first[]={0x80103e70,0x80103e7c,0x80103e88};
    const uint32_t later[]={0x8009000c,0x80090018,0x80090024};
    const uint32_t words[]={word,word,word};
    for(unsigned i=0;i<3;i++)world_precision_record(src[i],word,object,&v);
    assert(world_precision_emit(first,words,src,3,object));
    assert(world_precision_emit(later,words,src,3,object));
    for(unsigned i=0;i<3;i++) {
        assert(world_precision_packet(first[i],word,&got));
        assert(got.source_address==src[i]);
        assert(world_precision_packet(later[i],word,&got));
    }
    /* A new source record cannot evict an already-built unrelated packet. */
    world_precision_record(src[0],word,object,&v);
    assert(world_precision_packet(first[0],word,&got));
    world_precision_invalidate(src[0],4);
    assert(world_precision_packet(first[0],word,&got));
    assert(!world_precision_emit(later,words,src,3,object));
    /* A true write to a packet's own address still retires it. */
    world_precision_invalidate(first[0],4);
    assert(!world_precision_packet(first[0],word,&got));
}
int main(void) {
    source_and_packet_collision_keeps_both_lifetimes();
    aliases_and_packet_lifetime();
    invalidation_and_complete_fallback();
    fifo_and_clamps();
    wrapped_bulk_and_collisions();
    immutable_code_range_excludes_renderer_context();
    puts("PASS: address/generation provenance, packet lifetime, invalidation, complete fallback and GTE FIFO");
}
