#include "native_actor_snapshot.h"
#include "native_actor_source_code.h"
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int a2_native_actor_snapshot_enabled;
static const uint8_t *memory;
static size_t memory_size;
static A2ActorFrame building, published;
static A2ActorSnapshotStats stats;
static uint64_t serial, build_serial;
static int building_valid;
static unsigned captured_passes;
static uint32_t pass_capture_frame[2];
static FILE *output;
static int output_error;
static uint64_t (*clock_ns)(void);
typedef struct {
    uint32_t registry;
    uint64_t generation;
    char key[A2_ACTOR_SOURCE_KEY_SIZE];
    uint8_t hash[32];
} Source;
static Source sources[A2_ACTOR_MAX_INSTANCES];
typedef struct {
    uint32_t state, registry, selector, clip;
    uint64_t selection, advances;
} Clock;
static Clock clocks[A2_ACTOR_MAX_INSTANCES];
typedef struct { uint32_t registry; uint64_t generation, updates; unsigned known; } Lifetime;
static Lifetime lifetimes[60];
static Lifetime event_lifetimes[16];

static const uint8_t *span(uint32_t a,size_t n) {
    uint32_t high=a&0xe0000000u;
    if(high!=0&&high!=0x80000000u&&high!=0xa0000000u)return NULL;
    a&=0x1fffffffu;
    if(!memory||a>=memory_size||n>memory_size-a)return NULL;
    return memory+a;
}
static uint16_t u16(const uint8_t *p){return (uint16_t)(p[0]|p[1]<<8);}
static uint32_t u32(const uint8_t *p){return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
/* No observer behavior depends on this bounded diagnostic state. */
static void trace_snapshot(const char *phase,uint32_t frame,uint32_t object,const uint8_t *o,const char *reason){
    static unsigned initialized,enabled,lines,captures;
    static uint32_t first_frame;static uint64_t generation;
    if(!initialized){const char *s=getenv("A2_MESH_TRACE");enabled=s!=NULL;
        first_frame=s?(uint32_t)strtoul(s,NULL,10):UINT32_MAX;initialized=1;}
    if(!enabled||frame<first_frame||lines>=2048)return;
    if(generation!=building.build_generation){generation=building.build_generation;captures=0;}
    if(!strcmp(phase,"capture"))++captures;
    fprintf(stderr,"nativeactor-trace: phase=%s frame=%u build_generation=%"PRIu64" begin_frame=%u capture_in_build=%u object=%08x flags_known=%u raw_flags=%08x building_valid=%u instances=%u parts=%u published_valid=%u published_instances=%u reason=%s line=%u\n",
        phase,frame,building.build_generation,building.guest_frame,captures,object,o!=NULL,o?u32(o):0,
        (unsigned)building_valid,building.instance_count,building.part_count,published.valid,published.instance_count,reason,++lines);
}
static void trace_bad_record(const char *hook,uint32_t entity,uint32_t marker,uint32_t expected,int slot,const uint8_t *e){
    static unsigned lines;
    const char *t=getenv("A2_MESH_TRACE");
    if(!t||building.guest_frame<(uint32_t)strtoul(t,NULL,10)||lines>=128)return;
    fprintf(stderr,"nativeactor-bad-record: frame=%u hook=%s entity=%08x marker=%08x expected=%08x slot=%d raw_slot=%u count=%u type=%u flags=%04x registry=%08x preceding_instances=%u line=%u\n",
        building.guest_frame,hook,entity,marker,expected,slot,e?u16(e+2):0,e?e[97]:0,e?u16(e+12):0,e?u16(e):0,e?u32(e+64):0,
        building.instance_count,++lines);
}
static int slot_for(uint32_t a) {
    uint32_t p=a&0x1fffffffu;
    if(!span(a,804)||p<0x119710u||(p-0x119710u)%804)return -1;
    unsigned slot=(p-0x119710u)/804;return slot<60?(int)slot:-1;
}
static int source_code(void) {
    const uint8_t *id=span(0x800811d8,4);
    if(!id||u32(id)!=4)return 0;
    for(unsigned j=0;j<sizeof a2_actor_code_regions/sizeof *a2_actor_code_regions;j++){
        const A2ActorCodeRegion *r=&a2_actor_code_regions[j];const uint8_t *p=span(r->address,r->bytes);
        if(!p||memcmp(p,r->data,r->bytes))return 0;
    }
    return 1;
}
static int event_source_code(void) {
    const uint8_t *id=span(0x800811d8,4);
    if(!id||u32(id)!=5)return 0;
    static const struct {uint32_t begin,end;uint64_t hash;} regions[]={
        {0x88a04,0x8a190,UINT64_C(0x10054bc46f92a79a)},
        {0x8bb04,0x8c328,UINT64_C(0x8ab81663924ed9bb)}
    };
    for(unsigned j=0;j<sizeof regions/sizeof *regions;j++){
        const uint8_t *p=span(regions[j].begin,regions[j].end-regions[j].begin);
        uint64_t hash=UINT64_C(14695981039346656037);if(!p)return 0;
        for(uint32_t k=0;k<regions[j].end-regions[j].begin;k++)hash=(hash^p[k])*UINT64_C(1099511628211);
        if(hash!=regions[j].hash)return 0;
    }
    /* The shared resident camera submission contract remains byte exact. */
    return !memcmp(span(0x2568c,sizeof a2_actor_code_1),a2_actor_code_1,sizeof a2_actor_code_1);
}
static int event_slot(uint32_t entity){
    uint32_t p=entity&0x1fffffffu;
    if(p<0xce028u||(p-0xce028u)%1728u||!span(entity,1728))return -1;
    unsigned slot=(p-0xce028u)/1728u;return slot<16?(int)slot:-1;
}
static Clock *clock_for(uint32_t state,int create) {
    if(!span(state,28))return NULL;
    state&=0x1fffffffu;if(!state)return NULL;
    for(unsigned j=0;j<A2_ACTOR_MAX_INSTANCES;j++)if(clocks[j].state==state)return &clocks[j];
    if(create)for(unsigned j=0;j<A2_ACTOR_MAX_INSTANCES;j++)if(!clocks[j].state){clocks[j].state=state;return &clocks[j];}
    return NULL;
}
static A2ActorInstance *instance_for(uint32_t entity) {
    for(unsigned j=0;j<building.instance_count;j++)if(building.instances[j].entity_address==entity)return &building.instances[j];
    return NULL;
}
void a2_native_actor_snapshot_reset(void) {
    memset(&building,0,sizeof building);memset(&published,0,sizeof published);
    memset(sources,0,sizeof sources);memset(clocks,0,sizeof clocks);memset(lifetimes,0,sizeof lifetimes);
    memset(event_lifetimes,0,sizeof event_lifetimes);
    building_valid=0;captured_passes=0;++serial;
}
void a2_native_actor_snapshot_init(const uint8_t *ram,size_t size) {
    memory=size==0x200000?ram:NULL;memory_size=memory?size:0;
    a2_native_actor_snapshot_enabled=0;a2_native_actor_snapshot_reset();memset(&stats,0,sizeof stats);
}
void a2_native_actor_snapshot_configure(int enabled) {
    if(!!enabled!=a2_native_actor_snapshot_enabled)a2_native_actor_snapshot_reset();
    a2_native_actor_snapshot_enabled=!!enabled;
}
void a2_native_actor_snapshot_source_unbind(uint32_t registry) {
    registry&=0x1fffffffu;
    for(unsigned j=0;j<A2_ACTOR_MAX_INSTANCES;j++)if(sources[j].registry==registry)memset(&sources[j],0,sizeof sources[j]);
}
int a2_native_actor_snapshot_source_bind(uint32_t registry,const char *key,const uint8_t hash[32],uint64_t generation) {
    if(!span(registry,32)||!key||!hash||!generation)return 0;
    size_t n=0;for(;key[n];n++){
        unsigned char c=(unsigned char)key[n];
        if(n+1>=A2_ACTOR_SOURCE_KEY_SIZE||!((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')||c=='_'||c=='-'||c=='.'||c=='/'||c==':'))return 0;
    }
    if(!n)return 0;
    registry&=0x1fffffffu;a2_native_actor_snapshot_source_unbind(registry);
    for(unsigned j=0;j<A2_ACTOR_MAX_INSTANCES;j++)if(!sources[j].registry){
        sources[j].registry=registry;sources[j].generation=generation;
        memcpy(sources[j].key,key,n+1);memcpy(sources[j].hash,hash,32);return 1;
    }
    return 0;
}
void a2_native_actor_snapshot_set_output(FILE *stream){output=stream;output_error=0;}
void a2_native_actor_snapshot_set_clock(uint64_t (*fn)(void)){clock_ns=fn;}
int a2_native_actor_snapshot_output_error(void){return output_error;}
const A2ActorFrame *a2_native_actor_snapshot_current(void){return &published;}
void a2_native_actor_snapshot_stats(A2ActorSnapshotStats *out){if(out)*out=stats;}

void a2_native_actor_snapshot_begin(uint32_t frame,uint32_t arena,uint32_t ra) {
    if(!a2_native_actor_snapshot_enabled)return;
    ++stats.begin_hooks;memset(&building,0,sizeof building);captured_passes=0;
    building.guest_frame=frame;building.build_generation=++build_serial;
    building_valid=arena==0x801ec000u&&ra==0x80090228u&&source_code();
    if(!building_valid)building.fallback|=A2_ACTOR_UNKNOWN_SOURCE_CODE;
    trace_snapshot("begin",frame,0,NULL,building_valid?"begin":"invalid-build");
}
void a2_native_actor_snapshot_instance(uint32_t entity,uint32_t marker) {
    if(!a2_native_actor_snapshot_enabled)return;
    ++stats.instance_hooks;if(!building_valid)return;
    int slot=slot_for(entity);const uint8_t *e=span(entity,804);uint32_t expected=0x801ec000;
    if(building.instance_count){const A2ActorInstance *last=&building.instances[building.instance_count-1];expected=last->marker_address+80*(last->part_count+1);}
    if(slot<0||u16(e+2)!=(unsigned)slot||marker!=expected||instance_for(entity))goto bad;
    unsigned count=e[97];
    if(building.instance_count==A2_ACTOR_MAX_INSTANCES||count>A2_ACTOR_MAX_PARTS-building.part_count){building.fallback|=A2_ACTOR_FRAME_OVERFLOW;goto bad;}
    /* GAME00 8FDB4 permits marker-only actors, including the item created
     * when a chest opens. Preserve their80-byte slot in the arena traversal;
     * they own no parts and cannot qualify as a replacement mesh. */
    if(!span(marker,80*(count+1)))goto bad;
    A2ActorInstance *i=&building.instances[building.instance_count++];
    i->entity_address=entity;i->marker_address=marker;i->registry_address=u32(e+64);
    i->first_part=building.part_count;i->part_count=count;building.part_count+=count;
    i->entity_flags=u16(e);i->action_id=u16(e+20);i->previous_action_id=u16(e+22);
    i->valid=1;i->selected_for_draw=1;i->fallback=A2_ACTOR_MISSING_ROOT;
    for(unsigned k=0;k<3;k++){
        i->actor_world_q12[k]=(int32_t)u32(e+24+4*k);i->actor_offset_q12[k]=(int32_t)u32(e+36+4*k);
        i->orientation[k]=(int16_t)u16(e+48+2*k);
    }
    Lifetime *life=&lifetimes[slot];
    if(!life->generation){life->registry=i->registry_address;life->generation=++serial;}
    i->instance_generation=life->generation;i->generation_known=life->known;i->entity_update_calls=life->updates;
    if(!life->known)i->fallback|=A2_ACTOR_UNKNOWN_LIFETIME;
    i->animation_state_address=u32(e+72);const uint8_t *s=span(i->animation_state_address,28);
    if(u32(e+68)&&!s)i->fallback|=A2_ACTOR_UNKNOWN_ANIMATION;
    if(u32(e+68)&&s){
        i->animation_flags=u16(s);i->clip_length=u16(s+2);i->clip_frame=u16(s+4);i->clip_loops=u16(s+24);
        i->animation_registry_address=u32(s+12);i->clip_address=u32(s+16);Clock *c=clock_for(i->animation_state_address,0);
        if(c&&c->registry==i->animation_registry_address&&c->clip==i->clip_address){
            i->animation_clock_known=1;i->animation_selector=c->selector;i->clip_generation=c->selection;i->animation_update_tick=c->advances;
        }else i->fallback|=A2_ACTOR_UNKNOWN_ANIMATION;
    }
    return;
bad:trace_bad_record("instance",entity,marker,expected,slot,e);building_valid=0;building.fallback|=A2_ACTOR_BAD_RECORD;
}
void a2_native_actor_snapshot_root(uint32_t entity,const int32_t root[3]) {
    if(!a2_native_actor_snapshot_enabled)return;
    ++stats.root_hooks;if(!building_valid||!root)return;
    A2ActorInstance *i=instance_for(entity);if(!i){trace_bad_record("root",entity,0,0,slot_for(entity),span(entity,804));building_valid=0;building.fallback|=A2_ACTOR_BAD_RECORD;return;}
    memcpy(i->renderer_root_q12,root,sizeof i->renderer_root_q12);i->fallback&=~A2_ACTOR_MISSING_ROOT;
    const uint8_t *e=span(entity,804);
    if(e)for(unsigned k=0;k<3;k++)i->orientation[k]=(int16_t)u16(e+(i->source_family==A2_ACTOR_EVENT00?132:48)+2*k);
}
void a2_native_actor_snapshot_animation_select(uint32_t state,uint32_t selector,uint32_t registry) {
    if(!a2_native_actor_snapshot_enabled)return;
    ++stats.animation_select_hooks;if(!span(registry,32)||selector>(0x200000-32)/4)return;
    uint64_t addr=(uint64_t)registry+32+4*(uint64_t)selector;
    const uint8_t *p=addr<=UINT32_MAX?span((uint32_t)addr,4):NULL;Clock *c=clock_for(state,1);if(!c||!p)return;
    c->registry=registry;c->selector=selector;c->clip=u32(p);c->selection=++serial;
}
void a2_native_actor_snapshot_animation_update(uint32_t state) {
    if(!a2_native_actor_snapshot_enabled)return;
    ++stats.animation_update_hooks;Clock *c=clock_for(state,1);if(c)++c->advances;
}
void a2_native_actor_snapshot_entity_update(uint32_t entity) {
    if(!a2_native_actor_snapshot_enabled)return;
    int slot=slot_for(entity);if(slot>=0)++lifetimes[slot].updates;
}
void a2_native_actor_snapshot_entity_reset(uint32_t entity) {
    if(!a2_native_actor_snapshot_enabled)return;
    int slot=slot_for(entity);if(slot<0)return;
    Lifetime *life=&lifetimes[slot];memset(life,0,sizeof *life);life->generation=++serial;life->known=1;
    Clock *c=clock_for(0x8012c868u+304u*(unsigned)slot,0);if(c)memset(c,0,sizeof *c);
    /* A clear during a pending submission retires it immediately. */
    if(instance_for(entity)){trace_bad_record("reset",entity,0,0,slot,span(entity,804));building_valid=0;building.fallback|=A2_ACTOR_BAD_RECORD;}
}
static void bind_part(A2ActorPart *p) {
    p->fallback|=A2_ACTOR_UNBOUND_SOURCE;
    for(unsigned j=0;j<A2_ACTOR_MAX_INSTANCES;j++)if(sources[j].registry==(p->registry_address&0x1fffffffu)){
        p->source_generation=sources[j].generation;memcpy(p->source_key,sources[j].key,sizeof p->source_key);
        memcpy(p->source_sha256,sources[j].hash,32);p->fallback&=~A2_ACTOR_UNBOUND_SOURCE;return;
    }
}
void a2_native_actor_snapshot_event_begin(uint32_t frame,uint32_t arena){
    if(!a2_native_actor_snapshot_enabled)return;
    ++stats.begin_hooks;memset(&building,0,sizeof building);captured_passes=0;
    building.guest_frame=frame;building.build_generation=++build_serial;
    building.source_family=A2_ACTOR_EVENT00;
    building_valid=arena==0x800d9428u&&event_source_code();
    if(!building_valid)building.fallback|=A2_ACTOR_UNKNOWN_SOURCE_CODE;
    trace_snapshot("event-begin",frame,0,NULL,building_valid?"begin":"invalid-build");
}
void a2_native_actor_snapshot_event_reset(uint32_t entity){
    if(!a2_native_actor_snapshot_enabled)return;
    int slot=event_slot(entity);if(slot<0||!event_source_code())return;
    Lifetime *life=&event_lifetimes[slot];memset(life,0,sizeof *life);
    life->generation=++serial;life->known=1;
    Clock *c=clock_for(entity+260,0);if(c)memset(c,0,sizeof *c);
    if(building.source_family==A2_ACTOR_EVENT00&&instance_for(entity)){
        building_valid=0;building.fallback|=A2_ACTOR_BAD_RECORD;
    }
}
void a2_native_actor_snapshot_event_instance(uint32_t entity,uint32_t first){
    if(!a2_native_actor_snapshot_enabled)return;
    ++stats.instance_hooks;if(!building_valid||building.source_family!=A2_ACTOR_EVENT00)return;
    int slot=event_slot(entity);const uint8_t *e=span(entity,1728);
    if(slot<0||u32(e+8)!=(unsigned)slot||instance_for(entity)||
       first<0x800d9428u||first>=0x800de3d8u||(first-0x800d9428u)%80)goto bad;
    unsigned count=u16(e+266);
    if(building.instance_count==A2_ACTOR_MAX_INSTANCES||count>A2_ACTOR_MAX_PARTS-building.part_count){building.fallback|=A2_ACTOR_FRAME_OVERFLOW;goto bad;}
    A2ActorInstance *i=&building.instances[building.instance_count++];
    i->entity_address=entity;i->source_family=A2_ACTOR_EVENT00;
    i->marker_address=first>=0x800d9478u?first-80:first;
    i->registry_address=u32(e+248);i->part_count=count;i->first_part=building.part_count;building.part_count+=count;
    i->entity_flags=u16(e);i->valid=i->selected_for_draw=1;i->fallback=A2_ACTOR_MISSING_ROOT;
    if(u32(e+252)!=i->registry_address)i->fallback|=A2_ACTOR_DIFFERENT_PART_SOURCE;
    Lifetime *life=&event_lifetimes[slot];i->generation_known=life->known;i->instance_generation=life->generation;
    if(!life->known)i->fallback|=A2_ACTOR_UNKNOWN_LIFETIME;
    for(unsigned k=0;k<3;k++){
        i->actor_world_q12[k]=(int32_t)u32(e+108+4*k);i->actor_offset_q12[k]=(int32_t)u32(e+120+4*k);
        i->renderer_root_q12[k]=(int32_t)(u32(e+108+4*k)+u32(e+120+4*k));
        i->orientation[k]=(int16_t)u16(e+132+2*k);
    }
    i->animation_state_address=entity+260;i->animation_registry_address=u32(e+272);i->clip_address=u32(e+276);
    i->animation_flags=u16(e+260);i->clip_length=u16(e+262);i->clip_frame=u16(e+264);i->clip_loops=u16(e+284);
    Clock *c=clock_for(i->animation_state_address,0);
    if(c&&c->registry==i->animation_registry_address&&c->clip==i->clip_address){
        i->animation_clock_known=1;i->animation_selector=c->selector;i->clip_generation=c->selection;i->animation_update_tick=c->advances;
    }else i->fallback|=A2_ACTOR_UNKNOWN_ANIMATION;
    for(unsigned k=0;k<count;k++){
        A2ActorPart *p=&building.parts[i->first_part+k];p->source_mesh_index=k;p->registry_address=i->registry_address;
        p->flags=0x200;p->fallback=A2_ACTOR_BAD_RECORD|(i->fallback&A2_ACTOR_UNKNOWN_LIFETIME);bind_part(p);
    }
    return;
bad:building_valid=0;building.fallback|=A2_ACTOR_BAD_RECORD;
}
void a2_native_actor_snapshot_event_part(uint32_t entity,unsigned channel,uint32_t record){
    if(!a2_native_actor_snapshot_enabled||!building_valid||building.source_family!=A2_ACTOR_EVENT00)return;
    A2ActorInstance *i=instance_for(entity);const uint8_t *r=span(record,80);
    if(!i||channel>=i->part_count||!r||record<0x800d9428u||record>=0x800de3d8u||(record-0x800d9428u)%80)goto bad;
    A2ActorPart *p=&building.parts[i->first_part+channel];if(p->address)goto bad;
    p->address=record;p->flags=u16(r);p->registry_address=u32(r+60);
    p->vertex_override_address=(p->flags&0x1000)?u32(r+4):0;
    p->fallback=i->fallback&(A2_ACTOR_UNKNOWN_LIFETIME|A2_ACTOR_MISSING_ROOT);
    if(u16(r+2)!=channel||p->registry_address!=i->registry_address||u32(r+64)!=p->registry_address){
        p->fallback|=A2_ACTOR_DIFFERENT_PART_SOURCE;i->fallback|=A2_ACTOR_DIFFERENT_PART_SOURCE;
    }
    memcpy(p->raw,r,80);p->visible=!(p->flags&(7|0x200|0x8000));p->valid=p->visible&&!(i->fallback&A2_ACTOR_MISSING_ROOT);
    if(!p->visible)p->fallback|=A2_ACTOR_BAD_RECORD;
    if(p->flags&0x1000)p->fallback|=A2_ACTOR_DEFORMED_SOURCE;
    for(unsigned k=0;k<3;k++){
        p->translation0[k]=(int32_t)u32(r+8+4*k);p->translation1[k]=(int32_t)u32(r+20+4*k);
        p->pretranslation[k]=(int16_t)u16(r+52+2*k);
    }
    for(unsigned k=0;k<9;k++)p->matrix_q12[k]=(int16_t)u16(r+32+2*k);
    bind_part(p);return;
bad:building_valid=0;building.fallback|=A2_ACTOR_BAD_RECORD;
}
static int event_arena_valid(void){
    unsigned seen[A2_ACTOR_MAX_PARTS]={0};uint32_t address=0x800d9428u;
    for(;address<=0x800de3d8u;address+=80){
        const uint8_t *r=span(address,80);if(!r)return 0;
        if(u16(r)&0x8000)break;
        unsigned owned=0;
        for(unsigned k=0;k<published.part_count;k++)if(published.parts[k].address==address){
            if(seen[k]||memcmp(published.parts[k].raw,r,80))return 0;seen[k]=1;owned=1;
        }
        /* A missing observation must not masquerade as a skipped channel.
         * Light markers use the same +60 field but own no source geometry. */
        if(!owned&&!(u16(r)&7))for(unsigned k=0;k<A2_ACTOR_MAX_INSTANCES;k++)
            if(sources[k].registry&&sources[k].registry==(u32(r+60)&0x1fffffffu))return 0;
    }
    if(address>0x800de3d8u)return 0;
    for(unsigned k=0;k<published.part_count;k++)if(published.parts[k].address&&!seen[k])return 0;
    return 1;
}
static void ints(FILE *f,const int32_t *p,unsigned n){fputc('[',f);for(unsigned j=0;j<n;j++)fprintf(f,"%s%d",j?",":"",p[j]);fputc(']',f);}
static void shorts(FILE *f,const int16_t *p,unsigned n){fputc('[',f);for(unsigned j=0;j<n;j++)fprintf(f,"%s%d",j?",":"",p[j]);fputc(']',f);}
static void hex(FILE *f,const uint8_t *p,unsigned n){fputc('"',f);for(unsigned j=0;j<n;j++)fprintf(f,"%02x",p[j]);fputc('"',f);}
static void write_json(void) {
    FILE *f=output;if(!f)return;const A2ActorFrame *s=&published;
    fprintf(f,"{\"schema\":\"a2.animation_bridge.v1\",\"sequence\":%"PRIu64",\"build_generation\":%"PRIu64",\"guest_frame\":%u,\"capture_monotonic_ns\":%"PRIu64",\"clock_known\":%u,\"valid\":%u,\"fallback\":%u,\"draw_object_address\":%u,\"draw_flags\":%u,\"shadow_pass\":%u,\"camera\":{\"origin_q12\":",s->sequence,s->build_generation,s->guest_frame,s->capture_monotonic_ns,s->clock_known,s->valid,s->fallback,s->draw_object_address,s->draw_flags,s->shadow_pass);
    ints(f,s->camera_origin_q12,3);fputs(",\"rotation_q12\":",f);shorts(f,s->camera_rotation_q12,9);
    fprintf(f,",\"h\":%d,\"ofx\":%d,\"ofy\":%d},\"instances\":[",s->projection_h,s->projection_ofx,s->projection_ofy);
    for(unsigned j=0;j<s->instance_count;j++){
        const A2ActorInstance *i=&s->instances[j];
        fprintf(f,"%s{\"entity_address\":%u,\"instance_generation\":%"PRIu64",\"generation_known\":%u,\"valid\":%u,\"selected_for_draw\":%u,\"fallback\":%u,\"actor_world_q12\":",j?",":"",i->entity_address,i->instance_generation,i->generation_known,i->valid,i->selected_for_draw,i->fallback);
        ints(f,i->actor_world_q12,3);fputs(",\"actor_offset_q12\":",f);ints(f,i->actor_offset_q12,3);
        fputs(",\"renderer_root_q12\":",f);ints(f,i->renderer_root_q12,3);fputs(",\"orientation\":",f);shorts(f,i->orientation,3);
        fprintf(f,",\"action_id\":%u,\"previous_action_id\":%u,\"animation\":{\"state_address\":%u,\"registry_address\":%u,\"clip_address\":%u,\"selector\":%u,\"selection_generation\":%"PRIu64",\"advance_calls\":%"PRIu64",\"entity_update_calls\":%"PRIu64",\"clock_known\":%u,\"flags\":%u,\"frame\":%u,\"length\":%u,\"loops\":%u},\"parts\":[",i->action_id,i->previous_action_id,i->animation_state_address,i->animation_registry_address,i->clip_address,i->animation_selector,i->clip_generation,i->animation_update_tick,i->entity_update_calls,i->animation_clock_known,i->animation_flags,i->clip_frame,i->clip_length,i->clip_loops);
        for(unsigned k=0;k<i->part_count;k++){
            const A2ActorPart *p=&s->parts[i->first_part+k];
            fprintf(f,"%s{\"address\":%u,\"registry_address\":%u,\"source_mesh_index\":%u,\"flags\":%u,\"matrix_q12\":",k?",":"",p->address,p->registry_address,p->source_mesh_index,p->flags);
            shorts(f,p->matrix_q12,9);fputs(",\"pretranslation\":",f);shorts(f,p->pretranslation,3);
            fputs(",\"translation0\":",f);ints(f,p->translation0,3);fputs(",\"translation1\":",f);ints(f,p->translation1,3);
            fprintf(f,",\"source_key\":\"%s\",\"source_sha256\":",p->source_key);hex(f,p->source_sha256,32);
            fprintf(f,",\"source_generation\":%"PRIu64",\"valid\":%u,\"visible\":%u,\"fallback\":%u,\"vertex_override_address\":%u,\"raw_hex\":",p->source_generation,p->valid,p->visible,p->fallback,p->vertex_override_address);hex(f,p->raw,80);fputc('}',f);
        }
        fprintf(f,"],\"source_family\":%u}",i->source_family);
    }
    fprintf(f,"],\"source_family\":%u}\n",s->source_family);if(ferror(f)){output_error=1;output=NULL;}
}
void a2_native_actor_snapshot_capture(uint32_t frame,uint32_t object,int32_t h,int32_t ofx,int32_t ofy) {
    if(!a2_native_actor_snapshot_enabled)return;
    ++stats.capture_hooks;published=building;published.sequence=++serial;published.guest_frame=frame;
    if(clock_ns){published.capture_monotonic_ns=clock_ns();published.clock_known=1;}
    published.draw_object_address=object;published.projection_h=h;published.projection_ofx=ofx;published.projection_ofy=ofy;
    const uint8_t *o=span(object,64);const char *reject="record";
    if(!building_valid){reject="invalid-build";goto bad;}
    unsigned event=published.source_family==A2_ACTOR_EVENT00;
    if(object!=(event?0x800d76f0u:0x8011763cu)){reject="object";goto bad;}
    if(!o){reject="object-span";goto bad;}
    if(u32(o+20)!=(event?0x800d9428u:0x801ec000u)){reject="arena";goto bad;}
    if(!(event?event_source_code():source_code())){reject="source-code";goto bad;}
    /* The source-proven arena build is the pose epoch. Its first main and
     * shadow captures can cross VBlank; a later-tick repeat of a completed
     * pass must not turn old arena contents into a fresh pose. */
    unsigned pass=!!(u32(o)&0x100u);
    if(!pass&&(captured_passes&2u)){reject="main-after-shadow";goto bad;}
    if((captured_passes&(1u<<pass))&&frame!=pass_capture_frame[pass]){
        reject="stale-completed-build";goto bad;
    }
    published.draw_flags=u32(o);published.shadow_pass=!!(published.draw_flags&0x100);
    const uint8_t *matrix=span(u32(o+28),20);if(!matrix)goto bad;
    for(unsigned k=0;k<3;k++)published.camera_origin_q12[k]=(int32_t)u32(o+44+4*k);
    for(unsigned k=0;k<9;k++)published.camera_rotation_q12[k]=(int16_t)u16(matrix+2*k);
    if(event){if(!event_arena_valid())goto bad;goto accepted;}
    uint32_t end=0x801ec000;
    for(unsigned j=0;j<published.instance_count;j++){
        A2ActorInstance *i=&published.instances[j];
        if(i->marker_address!=end||!span(end,80)||!(u16(span(end,2))&7))goto bad;
        end+=80;
        for(unsigned k=0;k<i->part_count;k++,end+=80){
            A2ActorPart *p=&published.parts[i->first_part+k];const uint8_t *r=span(end,80);
            if(!r||(u16(r)&0x8000))goto bad;
            p->address=end;p->flags=u16(r);p->source_mesh_index=u16(r+2);
            p->registry_address=u32(r+60);p->vertex_override_address=(p->flags&0x1000)?u32(r+4):0;
            if(!span(p->registry_address,32)||p->source_mesh_index!=k)goto bad;
            memcpy(p->raw,r,80);p->visible=!(p->flags&(7|0x200));
            /* 277FC skips all pose writes when the channel is disabled.
             * Hidden records may therefore contain an earlier pose. */
            p->valid=p->visible&&!(i->fallback&A2_ACTOR_MISSING_ROOT);
            if(!p->valid)p->fallback|=A2_ACTOR_BAD_RECORD;
            if(p->registry_address!=i->registry_address)p->fallback|=A2_ACTOR_DIFFERENT_PART_SOURCE;
            for(unsigned axis=0;axis<3;axis++){
                p->translation0[axis]=(int32_t)u32(r+8+4*axis);p->translation1[axis]=(int32_t)u32(r+20+4*axis);p->pretranslation[axis]=(int16_t)u16(r+52+2*axis);
            }
            for(unsigned v=0;v<9;v++)p->matrix_q12[v]=(int16_t)u16(r+32+2*v);
            if(p->flags&0x1000)p->fallback|=A2_ACTOR_DEFORMED_SOURCE;
            p->fallback|=i->fallback&(A2_ACTOR_MISSING_ROOT|A2_ACTOR_UNKNOWN_LIFETIME);bind_part(p);
        }
    }
    if(!span(end,2)||!(u16(span(end,2))&0x8000))goto bad;
accepted:
    captured_passes|=1u<<pass;pass_capture_frame[pass]=frame;
    published.valid=1;++stats.published;
    trace_snapshot("capture",frame,object,o,"accepted");write_json();return;
bad:
    published.valid=0;published.fallback|=A2_ACTOR_BAD_RECORD;
    published.instance_count=0;published.part_count=0;++stats.rejected;
    trace_snapshot("capture",frame,object,o,reject);write_json();
}
