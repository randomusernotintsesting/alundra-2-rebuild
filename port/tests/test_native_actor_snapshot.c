#include "native_actor_snapshot.h"
#include "native_actor_source_code.h"
#include "fixtures/native_actor_state.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
static uint8_t ram[0x200000];
static unsigned clock_calls;
static uint64_t fake_clock(void){++clock_calls;return UINT64_C(1234567890123);}
static const uint32_t entities[]={0x80119710,0x80119a34,0x8011a07c,0x8011a3a0};
static const uint32_t markers[]={0x801ec000,0x801ec550,0x801ec780,0x801ec8c0};
static void store32(uint32_t a,uint32_t v){memcpy(ram+(a&0x1fffff),&v,4);}
static void setup(void){
    memset(ram,0,sizeof ram);
    for(unsigned j=0;j<sizeof a2_actor_code_regions/sizeof *a2_actor_code_regions;j++) {
        const A2ActorCodeRegion *r=&a2_actor_code_regions[j];memcpy(ram+r->address,r->data,r->bytes);
    }
    for(unsigned j=0;j<sizeof actor_fixture_regions/sizeof *actor_fixture_regions;j++) {
        const ActorFixtureRegion *r=&actor_fixture_regions[j];memcpy(ram+r->address,r->data,r->bytes);
    }
    store32(0x800811d8,4);
    a2_native_actor_snapshot_init(ram,sizeof ram);
    a2_native_actor_snapshot_configure(1);
    a2_native_actor_snapshot_set_clock(NULL);
}
static void build_records(void){
    a2_native_actor_snapshot_begin(2999,0x801ec000,0x80090228);
    for(unsigned j=0;j<4;j++){
        a2_native_actor_snapshot_instance(entities[j],markers[j]);
        int32_t q[3];memcpy(q,ram+(entities[j]&0x1fffff)+24,sizeof q);
        q[1]=-q[1];a2_native_actor_snapshot_root(entities[j],q);
    }
}
static void build(void){
    build_records();
    a2_native_actor_snapshot_capture(2999,0x8011763c,256,160<<16,108<<16);
}
/* GAME00 8FDB4 explicitly permits an entity with only its80-byte marker.
 * The item created by opening T02 is such an actor (slot32, no mesh). */
static void marker_only(unsigned position,int malformed){
    setup();
    uint8_t original[0xA00];memcpy(original,ram+0x1ec000,sizeof original);
    const uint32_t item=0x8011fb90;
    memset(ram+(item&0x1fffff),0,804);ram[(item&0x1fffff)]=1;ram[(item&0x1fffff)+2]=32;
    unsigned next=0;uint32_t cursor=0x801ec000;
    a2_native_actor_snapshot_begin(2999,0x801ec000,0x80090228);
    for(unsigned n=0;n<5;n++){
        uint32_t entity;unsigned count;
        if(n==position){entity=item;count=0;memset(ram+(cursor&0x1fffff),0,80);ram[cursor&0x1fffff]=1;}
        else{entity=entities[next];count=ram[(entity&0x1fffff)+97];
            memcpy(ram+(cursor&0x1fffff),original+(markers[next]-0x801ec000),80*(count+1));++next;}
        a2_native_actor_snapshot_instance(entity,cursor);
        int32_t root[3];memcpy(root,ram+(entity&0x1fffff)+24,sizeof root);root[1]=-root[1];
        a2_native_actor_snapshot_root(entity,root);cursor+=80*(count+1);
    }
    store32(cursor,malformed?0:0x8000);
    a2_native_actor_snapshot_capture(2999,0x8011763c,256,160<<16,108<<16);
    const A2ActorFrame *f=a2_native_actor_snapshot_current();
    if(malformed){assert(!f->valid);return;}
    assert(f->valid&&f->instance_count==5&&f->part_count==27);
    assert(f->instances[position].entity_address==item&&f->instances[position].part_count==0);
    assert(f->instances[position].registry_address==0&&f->instances[position].valid);
    next=0;
    for(unsigned n=0;n<5;n++)if(n!=position){
        const A2ActorInstance *i=&f->instances[n];assert(i->entity_address==entities[next]);
        for(unsigned j=0;j<i->part_count;j++)assert(!memcmp(f->parts[i->first_part+j].raw,
            original+(markers[next]-0x801ec000)+80*(j+1),80));
        ++next;
    }
}
int main(int argc,char **argv){
    for(unsigned position=0;position<5;position++){marker_only(position,0);marker_only(position,1);}
    setup();build();const A2ActorFrame *f=a2_native_actor_snapshot_current();
    assert(f&&f->valid&&f->instance_count==4&&f->part_count==27);
    assert(f->instances[0].part_count==16&&f->instances[3].part_count==2);
    for(unsigned j=0;j<16;j++){
        const A2ActorPart *p=&f->parts[j];assert(p->source_mesh_index==j);
        assert(p->valid&&p->visible&&(p->fallback&A2_ACTOR_UNBOUND_SOURCE));
        assert(!memcmp(p->raw,ram+0x1ec050+80*j,80));
    }
    assert(f->instances[0].actor_world_q12[0]==-716768);
    assert(f->parts[0].translation0[0]==-174);
    assert(!f->instances[0].generation_known&&!f->instances[0].animation_clock_known);
    assert(f->instances[0].fallback&A2_ACTOR_UNKNOWN_ANIMATION);
    /* A configured skeletal registry with an invalid state pointer is
     * explicitly unsupported even though its clock already stays unknown. */
    uint32_t old_state;memcpy(&old_state,ram+0x119710+72,4);
    store32(0x80119710+72,0x1f801000);build();f=a2_native_actor_snapshot_current();
    assert(!f->instances[0].animation_clock_known&&(f->instances[0].fallback&A2_ACTOR_UNKNOWN_ANIMATION));
    store32(0x80119710+72,old_state);build();f=a2_native_actor_snapshot_current();
    /* A copy is immutable even after its native source was overwritten. */
    uint8_t saved=f->parts[0].raw[8];ram[0x1ec058]^=0xff;
    assert(f->parts[0].raw[8]==saved);
    setup();uint8_t hash[32]={1};
    assert(a2_native_actor_snapshot_source_bind(0x80175cb4,"PC00",hash,7));
    build();f=a2_native_actor_snapshot_current();assert(!strcmp(f->parts[0].source_key,"PC00"));
    assert(f->parts[0].source_generation==7&&!(f->parts[0].fallback&A2_ACTOR_UNBOUND_SOURCE));
    if(argc==2){FILE *sample=fopen(argv[1],"wb");assert(sample);a2_native_actor_snapshot_set_output(sample);build();a2_native_actor_snapshot_set_output(NULL);assert(!fclose(sample));}
    /* Output exposes all separate native transforms, not reconstructed floats. */
    FILE *out=tmpfile();assert(out);a2_native_actor_snapshot_set_output(out);build();
    a2_native_actor_snapshot_set_output(NULL);rewind(out);char text[65536];
    size_t n=fread(text,1,sizeof text-1,out);text[n]=0;fclose(out);
    assert(strstr(text,"a2.animation_bridge.v1")&&strstr(text,"\"pretranslation\""));
    assert(strstr(text,"\"actor_world_q12\"")&&strstr(text,"\"translation1\""));
    /* Raw deformation flags survive; validity and replacement eligibility differ. */
    setup();ram[0x1ec051]|=0x10;build();f=a2_native_actor_snapshot_current();
    assert(f->parts[0].valid&&(f->parts[0].fallback&A2_ACTOR_DEFORMED_SOURCE));
    setup();ram[0x1ec051]|=2;build();f=a2_native_actor_snapshot_current();
    assert(!f->parts[0].valid&&!f->parts[0].visible&&(f->parts[0].fallback&A2_ACTOR_BAD_RECORD));
    setup();store32(0x801ec050+60,0x801ae648);build();
    assert(a2_native_actor_snapshot_current()->parts[0].fallback&A2_ACTOR_DIFFERENT_PART_SOURCE);
    /* Genuine clear observations retire reused entity and animation slots. */
    setup();a2_native_actor_snapshot_entity_reset(entities[0]);build();
    f=a2_native_actor_snapshot_current();assert(f->instances[0].generation_known);
    uint64_t generation=f->instances[0].instance_generation;
    a2_native_actor_snapshot_entity_reset(entities[0]);build();
    assert(a2_native_actor_snapshot_current()->instances[0].instance_generation>generation);
    /* Multiple native advances during one entity update remain separate. */
    uint32_t state,registry,clip;memcpy(&state,ram+0x119710+72,4);
    memcpy(&registry,ram+(state&0x1fffff)+12,4);memcpy(&clip,ram+(state&0x1fffff)+16,4);
    store32(registry+32,clip);a2_native_actor_snapshot_animation_select(state,0,registry);
    a2_native_actor_snapshot_entity_update(entities[0]);
    for(unsigned j=0;j<3;j++)a2_native_actor_snapshot_animation_update(state);
    build();f=a2_native_actor_snapshot_current();
    assert(f->instances[0].animation_clock_known&&f->instances[0].animation_update_tick==3&&f->instances[0].entity_update_calls==1);
    a2_native_actor_snapshot_entity_reset(entities[0]);build();
    assert(!a2_native_actor_snapshot_current()->instances[0].animation_clock_known);
    /* Main/shadow submissions stay distinct and carry a measured timestamp. */
    setup();clock_calls=0;a2_native_actor_snapshot_set_clock(fake_clock);build();
    f=a2_native_actor_snapshot_current();assert(f->clock_known&&f->capture_monotonic_ns==UINT64_C(1234567890123)&&clock_calls==1);
    uint64_t sequence=f->sequence;ram[0x11763d]|=1;
    a2_native_actor_snapshot_capture(2999,0x8011763c,256,0,0);
    f=a2_native_actor_snapshot_current();assert(f->valid&&f->shadow_pass&&f->sequence>sequence&&clock_calls==2);
    /* A real pose build may cross VBlank before its first main capture.
     * Each proven main/shadow pass has one capture tick in this build. */
    setup();build_records();
    a2_native_actor_snapshot_capture(3000,0x8011763c,256,160<<16,108<<16);
    f=a2_native_actor_snapshot_current();assert(f->valid&&f->guest_frame==3000&&f->part_count==27);
    uint64_t epoch=f->build_generation;
    a2_native_actor_snapshot_capture(3000,0x8011763c,256,160<<16,108<<16);
    assert(a2_native_actor_snapshot_current()->valid); /* same-pass same-tick repeat */
    a2_native_actor_snapshot_capture(3001,0x8011763c,256,160<<16,108<<16);
    assert(!a2_native_actor_snapshot_current()->valid); /* completed main is stale */
    ram[0x11763d]|=1;
    a2_native_actor_snapshot_capture(3001,0x8011763c,256,160<<16,108<<16);
    f=a2_native_actor_snapshot_current();assert(f->valid&&f->shadow_pass&&f->build_generation==epoch);
    a2_native_actor_snapshot_capture(3002,0x8011763c,256,160<<16,108<<16);
    assert(!a2_native_actor_snapshot_current()->valid); /* completed shadow is stale */
    ram[0x11763d]&=(uint8_t)~1u;
    build_records();a2_native_actor_snapshot_capture(3002,0x8011763c,256,0,0);
    assert(a2_native_actor_snapshot_current()->valid&&a2_native_actor_snapshot_current()->build_generation!=epoch);
    /* Main cannot reuse a shadow-overwritten arena, even in the same tick. */
    setup();build();ram[0x11763d]|=1;
    a2_native_actor_snapshot_capture(2999,0x8011763c,256,0,0);
    assert(a2_native_actor_snapshot_current()->valid);
    ram[0x11763d]&=(uint8_t)~1u;store32(0x801ec058,999);
    a2_native_actor_snapshot_capture(2999,0x8011763c,256,0,0);
    assert(!a2_native_actor_snapshot_current()->valid);
    /* Cross-tick timing cannot waive record or source identity. */
    setup();build_records();store32(0x801ec000,0);
    a2_native_actor_snapshot_capture(3000,0x8011763c,256,0,0);
    assert(!a2_native_actor_snapshot_current()->valid);
    setup();build_records();ram[0x8fd48]^=1;
    a2_native_actor_snapshot_capture(3000,0x8011763c,256,0,0);
    assert(!a2_native_actor_snapshot_current()->valid);
    /* Forged/missing ownership, stale frame and changed source code fail closed. */
    setup();a2_native_actor_snapshot_begin(2999,0x801ec000,0x80090228);
    a2_native_actor_snapshot_instance(entities[0],markers[1]);
    a2_native_actor_snapshot_capture(2999,0x8011763c,256,0,0);
    assert(!a2_native_actor_snapshot_current()->valid);
    setup();build();a2_native_actor_snapshot_capture(3000,0x8011763c,256,0,0);
    assert(!a2_native_actor_snapshot_current()->valid);
    setup();ram[0x8fd48]^=1;build();assert(!a2_native_actor_snapshot_current()->valid);
    setup();ram[0x88380]^=1;build();assert(!a2_native_actor_snapshot_current()->valid);
    setup();a2_native_actor_snapshot_begin(2999,0x801ec000,0x80090228);
    for(unsigned j=0;j<4;j++)a2_native_actor_snapshot_instance(entities[j],markers[j]);
    a2_native_actor_snapshot_capture(2999,0x8011763c,256,0,0);
    f=a2_native_actor_snapshot_current();assert(f->valid&&!f->parts[0].valid&&(f->parts[0].fallback&A2_ACTOR_MISSING_ROOT));
    /* Overflow rejects the whole submission, never publishes a truncated pose. */
    setup();ram[0x119710+97]=255;
    a2_native_actor_snapshot_begin(2999,0x801ec000,0x80090228);
    a2_native_actor_snapshot_instance(entities[0],0x801ec000);
    a2_native_actor_snapshot_instance(entities[1],0x801f1000);
    a2_native_actor_snapshot_capture(2999,0x8011763c,256,0,0);
    f=a2_native_actor_snapshot_current();assert(!f->valid&&!f->part_count&&(f->fallback&A2_ACTOR_FRAME_OVERFLOW));
    /* A stream error is contained in the observer; never changes guest RAM. */
    setup();FILE *readonly=fopen(__FILE__,"rb");assert(readonly);
    a2_native_actor_snapshot_set_output(readonly);build();assert(a2_native_actor_snapshot_output_error());
    a2_native_actor_snapshot_set_output(NULL);fclose(readonly);
    setup();a2_native_actor_snapshot_configure(0);build();
    assert(!a2_native_actor_snapshot_current()->valid);
    clock_calls=0;a2_native_actor_snapshot_set_clock(fake_clock);build();assert(!clock_calls);
    puts("actor snapshot: retained 27 parts, typed roots, immutable data, explicit fallback and JSONL pass");
}
