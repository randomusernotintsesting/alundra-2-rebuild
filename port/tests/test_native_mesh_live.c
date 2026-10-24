/* Real live/composite lifecycle with deterministic scene and packet providers.
 * In particular: guest memory may retire AFTER completed DMA submission but
 * BEFORE VBlank; pixels already validated at submission must remain usable. */
#include "native_mesh_live.h"
#include "native_mesh_scene.h"
#include "world_precision.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint32_t psx_frame_no=40;
static A2NativeModel fixture_model;
static A2NativeModel flint_model;
static unsigned available_models=1,registered_models;
static A2ActorPacketOwner owner={.handle=7};
static A2ActorPacketOwner unsupported_owner={.handle=8};
static A2ActorPacket packet;
static int alive,consumed,fail_draw,mixed_resources,source_failed,caption_test;
int a2_flint_owner_supported(const A2ActorPacketOwner *o,const A2NativeModel *m){
    return o==&owner&&m==&flint_model&&o->instance.source_family==A2_ACTOR_EVENT00;
}
int a2_flint_source_part_replaced(const A2ActorPacketOwner *o,unsigned part){return o==&owner&&!strcmp(o->parts[0].source_key,"FRITTO")&&part<16;}
void a2_mesh_live_dma_begin(const uint8_t *,size_t,uint32_t,uint64_t,int);
void a2_mesh_live_dma_end(void);
#ifdef A2_SUBMISSION_NEGATIVE_CONTROL
/* Frozen old live module has no current-command-list filter. */
void a2_mesh_live_dma_begin(const uint8_t *m,size_t n,uint32_t a,uint64_t w,int ll){(void)m;(void)n;(void)a;(void)w;(void)ll;}
void a2_mesh_live_dma_end(void){}
#endif
extern int a2_mesh_live_writes_watched;
static uint16_t shadow[2048*1024],original[2048];
struct A2MeshScene { unsigned width,height; };
A2ResourceId a2_resource_find(const A2Resources *s,int l,const char *n){
    (void)s;assert(l==0);
    if(!strcmp(n,"MODELS/T02.A2M"))return available_models&1?1:0;
    assert(!strcmp(n,"MODELS/PC00.A2M"));return available_models&2?2:0;
}
int a2_native_model_load(A2Resources *s,A2ResourceId id,A2NativeModel **out,char *e,size_t n){
    (void)s;(void)e;(void)n;assert(id==1||id==2);*out=id==1?&fixture_model:&flint_model;return 1;
}
void a2_native_model_destroy(A2NativeModel *m){assert(m==NULL||m==&fixture_model||m==&flint_model);}
A2MeshScene *a2_mesh_scene_create(unsigned w,unsigned h,char *e,size_t n){
    (void)e;(void)n;A2MeshScene *s=malloc(sizeof *s);assert(s);s->width=w;s->height=h;registered_models=0;return s;
}
void a2_mesh_scene_destroy(A2MeshScene *s){free(s);}
int a2_mesh_scene_add(A2MeshScene *s,const A2NativeModel *m){assert(s&&(m==&fixture_model||m==&flint_model));registered_models|=m==&fixture_model?1:2;return 1;}
/* The real decoded-resource plan has its own scene test. This seam returns
 * only the fixture's drawable resource; unsupported owners still represent
 * ordinary native geometry in the caller's packet list. */
size_t a2_mesh_scene_plan(const A2MeshScene *s,const A2ActorPacketOwner *const *in,
                         size_t count,const A2ActorPacketOwner **out,size_t capacity){
    assert(s&&in&&out&&capacity);
    size_t n=0;for(size_t i=0;i<count;i++)if(in[i]==&owner){assert(n<capacity);out[n++]=in[i];}
    return n;
}
int a2_mesh_scene_draw(A2MeshScene *s,const A2ActorPacketOwner *const *o,size_t count,
        unsigned scale,int wide,uint8_t *rgba,size_t bytes,float *z,size_t zbytes){
    assert(s&&scale==2&&wide==1);
    if(count!=1||o[0]!=&owner)return 0;
    assert(bytes==(size_t)s->width*s->height*4&&zbytes==bytes);
    if(fail_draw)return 0;
    memset(rgba,0,bytes);memset(z,0,zbytes);
    size_t pixel=(size_t)20*s->width+20;
    rgba[4*pixel]=255;rgba[4*pixel+3]=255;z[pixel]=.5f;
    if(caption_test){pixel=(size_t)360*s->width+20;rgba[4*pixel]=255;rgba[4*pixel+3]=255;z[pixel]=.5f;}
    return 1;
}
int a2_mesh_scene_read_owners(A2MeshScene *s,uint32_t *tags,size_t bytes){
    assert(bytes==(size_t)s->width*s->height*4);memset(tags,0,bytes);
    tags[(size_t)20*s->width+20]=1;
    if(caption_test)tags[(size_t)360*s->width+20]=1;
    return 1;
}
const A2ActorPacketOwner *a2_native_actor_packets_owner(uint64_t h){
    return h==7?&owner:h==8?&unsupported_owner:NULL;
}
int a2_native_actor_packets_source_failed(const char *key,const uint8_t hash[32]){
    (void)hash;assert(!strcmp(key,"T02")||!strcmp(key,"PC00")||!strcmp(key,"FRITTO"));
    return source_failed&(!strcmp(key,"T02")?1:!strcmp(key,"PC00")?2:4);
}
size_t a2_native_actor_packets_owners_latest(const A2ActorPacketOwner **out,size_t n){
    assert(n>=2);if(!alive)return 0;
    if(mixed_resources){out[0]=&unsupported_owner;out[1]=&owner;return 2;}
    out[0]=&owner;return 1;
}
size_t a2_native_actor_packets_owner_packets(uint64_t h,const A2ActorPacket **out,size_t n){
    assert(h==7&&n);if(!alive)return 0;out[0]=&packet;return 1;
}
int a2_native_actor_packets_owner_complete(uint64_t h){assert(h==7);return alive&&consumed;}
int world_precision_packet(uint32_t a,uint32_t w,world_precision_vertex *out){
    (void)a;(void)w;(void)out;return 0;
}
static uint32_t xy(unsigned x,unsigned y){return x|(y<<16);}
static void begin(int page){
    alive=consumed=1;
    a2_mesh_live_clear(40,2,0,page,320,216);
    a2_mesh_live_start(40,2,page,shadow,2048,1);
    assert(a2_mesh_live_active&&a2_mesh_live_owns(7));
}
static void expect_model(int page,int present){
    const uint16_t *p=a2_mesh_live_row(page*2+20,original,2048);
    assert(p[20]==(present?31:original[20]));
    assert(p[0]==original[0]&&p[2047]==original[2047]);
}
static void exclusive_lifecycle(void){
    for(int page=0;page<=256;page+=256){
        begin(page);assert(a2_mesh_live_claim(7));
        a2_mesh_live_finalize();expect_model(page,1);
        alive=0; /* completed guest data can retire before a later overlay */
        a2_mesh_live_start(41,2,page,shadow,2048,1);
        assert(a2_mesh_live_active&&a2_mesh_live_claim(7));
        a2_mesh_live_pixel(20,page*2+20,(A2CompositePixel){.kind=A2_COMPOSITE_OWNED,.g=255});
        a2_mesh_live_finalize();expect_model(page,1);
        a2_mesh_live_start(41,2,page,shadow,2048,1);
        a2_mesh_live_pixel(20,page*2+20,(A2CompositePixel){.kind=A2_COMPOSITE_HUD,.b=255});
        a2_mesh_live_finalize();assert(a2_mesh_live_row(page*2+20,original,2048)[20]==(31<<10));
        assert(!a2_mesh_live_failed);
        begin(page);a2_mesh_live_finalize();
        assert(a2_mesh_live_read(20,page*2+20,123)==31);
        a2_mesh_live_store(20,page*2+20,321);
        assert(a2_mesh_live_read(20,page*2+20,123)==321);
        assert(a2_mesh_live_row(page*2+20,original,2048)[20]==321);
        assert(a2_mesh_live_read(900,page*2+20,123)==123);
        /* Literal upload retires model depth; a later world draw is real. */
        a2_mesh_live_start(42,2,page,shadow,2048,1);
        a2_mesh_live_pixel(20,page*2+20,(A2CompositePixel){.kind=A2_COMPOSITE_WORLD,.depth=.8f,.g=255});
        a2_mesh_live_finalize();assert(a2_mesh_live_read(20,page*2+20,123)==(31<<5));
    }
    a2_mesh_live_reset();
}
static void choices(void){
    begin(0);a2_mesh_live_finalize();expect_model(0,1);
    a2_mesh_live_set_enabled(0);
    /* Keep the last complete front frame until the next complete draw;
     * don't remove its model while the player is still looking at it. */
    expect_model(0,1);
    a2_mesh_live_clear(50,2,0,256,320,216);
    a2_mesh_live_start(50,2,256,shadow,2048,1);
    assert(!a2_mesh_live_claim(7));a2_mesh_live_finalize();expect_model(256,0);
    expect_model(0,1);
    a2_mesh_live_clear(51,2,0,0,320,216);
    a2_mesh_live_start(51,2,0,shadow,2048,1);
    assert(!a2_mesh_live_claim(7));expect_model(0,0);
    assert(!a2_mesh_live_enabled);
    a2_mesh_live_set_enabled(1);begin(0);assert(a2_mesh_live_claim(7));
    a2_mesh_live_finalize();expect_model(0,1);
}
static void current_submission(void){
    static uint8_t ram[0x200000];
    uint32_t *list=(uint32_t *)(ram+0x4000);
    /* Last complete owner is still source-valid, but this fresh draw page
     * contains only a fade/2D command. It must not resurrect the old model. */
    memset(ram,0,sizeof ram);list[0]=0x03ffffff;list[1]=0x60000000;list[2]=0;list[3]=0x00d80140;
    alive=consumed=1;a2_mesh_live_dma_begin(ram,sizeof ram,0x4000,0,1);
    a2_mesh_live_clear(60,2,0,0,320,216);
    a2_mesh_live_start(60,2,0,shadow,2048,1);
    assert(!a2_mesh_live_active);a2_mesh_live_finalize();expect_model(0,0);
    a2_mesh_live_dma_end();
    /* The exact same already-consumed model packet may legitimately be
     * submitted again. Presence, not packet age/observed state, admits it. */
    packet.dma_base=0x5000;packet.command_address=0x5008;packet.dma_word_count=5;packet.polygon_word_count=4;
    packet.words[0]=0x05ffffff;packet.words[1]=0xe1000000;
    memcpy(ram+0x5000,packet.words,24);list[0]=0x00005000;
    a2_mesh_live_dma_begin(ram,sizeof ram,0x4000,0,1);
    a2_mesh_live_start(60,2,0,shadow,2048,1);
    assert(a2_mesh_live_active&&a2_mesh_live_claim(7));a2_mesh_live_finalize();expect_model(0,1);
    a2_mesh_live_dma_end();
    /* Same packet address but changed payload is not verified membership. */
    ram[0x5008]^=1;a2_mesh_live_dma_begin(ram,sizeof ram,0x4000,0,1);
    a2_mesh_live_clear(61,2,0,256,320,216);a2_mesh_live_start(61,2,256,shadow,2048,1);
    assert(!a2_mesh_live_active);a2_mesh_live_finalize();expect_model(256,0);a2_mesh_live_dma_end();
    ram[0x5008]^=1;
    /* Bounded block transfers require the whole contiguous GP0 polygon. */
    a2_mesh_live_dma_begin(ram,sizeof ram,0x5008,4,0);
    a2_mesh_live_start(61,2,256,shadow,2048,1);assert(a2_mesh_live_active);
    assert(a2_mesh_live_claim(7));a2_mesh_live_finalize();expect_model(256,1);a2_mesh_live_dma_end();
    /* A native-only cutscene prop cannot summon the modern body. */
    char key[32];memcpy(key,owner.parts[0].source_key,32);
    strcpy(owner.parts[0].source_key,"FRITTO");owner.instance.source_family=A2_ACTOR_EVENT00;
    packet.source_mesh_index=16;
    a2_mesh_live_dma_begin(ram,sizeof ram,0x5008,4,0);
    a2_mesh_live_clear(62,2,0,0,320,216);a2_mesh_live_start(62,2,0,shadow,2048,1);
    assert(!a2_mesh_live_active&&!a2_mesh_live_claim_part(7,16));
    packet.source_mesh_index=0;a2_mesh_live_start(62,2,0,shadow,2048,1);
    assert(a2_mesh_live_active&&a2_mesh_live_claim_part(7,0));
    strcpy(owner.parts[0].source_key,"T02");assert(a2_mesh_live_claim_part(7,0));
    a2_mesh_live_finalize();
    memcpy(owner.parts[0].source_key,key,32);owner.instance.source_family=A2_ACTOR_GAME00;
    a2_mesh_live_dma_end();
    a2_mesh_live_reset();
}
int main(void){
    packet.words[2]=0x20000000;packet.words[3]=xy(10,10);
    packet.words[4]=xy(12,10);packet.words[5]=xy(10,12);
    for(size_t i=0;i<sizeof shadow/sizeof *shadow;i++)shadow[i]=0x1234;
    for(size_t i=0;i<2048;i++)original[i]=0x4567;
    strcpy(fixture_model.source_key,"T02");strcpy(owner.parts[0].source_key,"T02");
    strcpy(unsupported_owner.parts[0].source_key,"T03");
    assert(a2_mesh_live_open(NULL,0));
    exclusive_lifecycle();choices();current_submission();
    a2_mesh_live_reset();
    mixed_resources=1;begin(0);assert(!a2_mesh_live_claim(8));
    a2_mesh_live_finalize();expect_model(0,1);mixed_resources=0;
    /* Native command order does not depend on old polygon pixel coverage. */
    begin(0);
    a2_mesh_live_pixel(20,20,(A2CompositePixel){.kind=A2_COMPOSITE_ORDERED,.g=255});
    assert(a2_mesh_live_claim(7));assert(a2_mesh_live_claim(7));
    a2_mesh_live_pixel(20,20,(A2CompositePixel){.kind=A2_COMPOSITE_WORLD,.depth=.8f,.g=255});
    a2_mesh_live_finalize();expect_model(0,1);
    a2_mesh_live_start(41,2,0,shadow,2048,1);
    a2_mesh_live_pixel(20,20,(A2CompositePixel){.kind=A2_COMPOSITE_ORDERED,.b=255});
    a2_mesh_live_finalize();assert(a2_mesh_live_read(20,20,0)==(31<<10));
    /* A partially submitted frame remains selected and accepts the rest. */
    begin(0);consumed=0;a2_mesh_live_finalize();expect_model(0,1);
    consumed=1;a2_mesh_live_start(41,2,0,shadow,2048,1);a2_mesh_live_finalize();expect_model(0,1);
    /* Unknown API input is still an error; runtime maps native-order inputs
     * explicitly. It may not become an automatic old-model frame. */
    begin(0);a2_mesh_live_pixel(20,20,(A2CompositePixel){.kind=A2_COMPOSITE_UNKNOWN});
    assert(a2_mesh_live_failed);
    a2_mesh_live_reset();assert(!a2_mesh_live_failed);
    fail_draw=1;alive=1;a2_mesh_live_clear(45,2,0,0,320,216);
    a2_mesh_live_start(45,2,0,shadow,2048,1);assert(a2_mesh_live_failed);fail_draw=0;
    a2_mesh_live_reset();
    source_failed=1;alive=0;a2_mesh_live_clear(48,2,0,0,320,216);
    a2_mesh_live_start(48,2,0,shadow,2048,1);
    assert(a2_mesh_live_failed); /* emitted source lost owner: never old fallback */
    source_failed=0;a2_mesh_live_reset();alive=1;
    /* Clear + actual pre-draw uploads form a valid background. */
    a2_mesh_live_clear(46,2,0,0,320,216);a2_mesh_live_store(20,20,123);
    a2_mesh_live_finalize();a2_mesh_live_start(47,2,0,shadow,2048,1);
    a2_mesh_live_finalize();expect_model(0,1);
    a2_mesh_live_close();assert(!a2_mesh_live_writes_watched);
    strcpy(flint_model.source_key,"PC00");
    strcpy(owner.parts[0].source_key,"PC00");
    for(available_models=2;available_models<=3;available_models++){
        assert(a2_mesh_live_open(NULL,0));
        begin(0);assert(registered_models==available_models&&a2_mesh_live_claim(7));
        owner.instance.source_family=A2_ACTOR_EVENT00;
        strcpy(owner.parts[0].source_key,"FRITTO");
        assert(a2_mesh_live_claim_part(7,15));
        assert(!a2_mesh_live_claim_part(7,16)&&!a2_mesh_live_claim_part(7,17));
        owner.instance.source_family=A2_ACTOR_GAME00;
        strcpy(owner.parts[0].source_key,"PC00");
        assert(a2_mesh_live_claim_part(7,0));
        caption_test=1;a2_mesh_live_clear(40,2,0,0,320,216);
        a2_mesh_live_start_view(40,2,0,shadow,2048,1,172);
        assert(a2_mesh_live_active);a2_mesh_live_finalize();expect_model(0,1);
        assert(a2_mesh_live_row(360,original,2048)[20]==original[20]);
        a2_mesh_live_clear(40,2,0,0,320,216);
        a2_mesh_live_start_view(40,2,0,shadow,2048,1,216);
        a2_mesh_live_finalize();assert(a2_mesh_live_row(360,original,2048)[20]==31);
        caption_test=0;begin(0);
        a2_mesh_live_finalize();expect_model(0,1);choices();
        source_failed=2;alive=0;a2_mesh_live_clear(51,2,0,0,320,216);
        a2_mesh_live_start(51,2,0,shadow,2048,1);assert(a2_mesh_live_failed);
        source_failed=0;a2_mesh_live_reset();
        source_failed=4;alive=0;a2_mesh_live_clear(52,2,0,0,320,216);
        a2_mesh_live_start(52,2,0,shadow,2048,1);assert(a2_mesh_live_failed);
        source_failed=0;a2_mesh_live_close();
    }
    puts("exclusive model pages and independent PC00/T02 resources: passed");
}
