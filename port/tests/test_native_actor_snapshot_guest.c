/* Real generated entry calls: prove observations are not dispatcher-only.
 * Metadata builders run natively. Final poses are the retained PART2999 rows;
 * this bounded fixture does not claim to run every skeletal callback. */
#define A2_NATIVE_ACTOR_SNAPSHOT 1
#include "psx_rt.h"
#include "native_actor_source_code.h"
#include "fixtures/native_actor_state.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../gen/game00_005.c"
#include "../gen/game00_007.c"
#include "../gen/game00_008.c"
#include "../gen/scps_009.c"
uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
uint32_t R[32],HI,LO,psx_next,psx_work,psx_frame_no,a2_ramwatch;
int psx_bb_budget=1000000;
void psx_bb_fire(void){assert(!"Unexpected long guest loop");}
void psx_break(uint32_t x){(void)x;abort();}
void psx_syscall_at(uint32_t x){(void)x;abort();}
void a2_ramwatch_hit(uint32_t a,uint32_t b,int c){(void)a;(void)b;(void)c;abort();}
uint32_t psx_mmio_read(uint32_t a,int n){(void)a;(void)n;abort();}
void psx_mmio_write(uint32_t a,uint32_t b,int n){(void)a;(void)b;(void)n;abort();}
static uint32_t ctrl[32];
uint32_t gte_ctrl_read(int r){return ctrl[r&31];}
void gte_ctrl_write(int r,uint32_t n){ctrl[r&31]=n;}
void gte_cmd(uint32_t n){(void)n;abort();}
uint32_t gte_data_read(int r){(void)r;abort();}
void gte_data_write(int r,uint32_t n){(void)r;(void)n;abort();}
static uint8_t before_ram[PSX_RAM_SIZE];
static uint32_t before_regs[32],before_ctrl[32],before_next,before_work;
static uint8_t before_scratch[0x400];
static uint32_t before_hi,before_lo;static int before_budget;
static void setup(int enabled){
    memset(PSX_RAM,0,sizeof PSX_RAM);memset(R,0,sizeof R);memset(ctrl,0,sizeof ctrl);
    memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);HI=0x12345678;LO=0x87654321;
    psx_work=0;psx_next=0;psx_frame_no=2999;psx_bb_budget=1000000;
    for(unsigned j=0;j<sizeof a2_actor_code_regions/sizeof *a2_actor_code_regions;j++){
        const A2ActorCodeRegion *r=&a2_actor_code_regions[j];memcpy(PSX_RAM+r->address,r->data,r->bytes);
    }
    for(unsigned j=0;j<sizeof actor_fixture_regions/sizeof *actor_fixture_regions;j++){
        const ActorFixtureRegion *r=&actor_fixture_regions[j];memcpy(PSX_RAM+r->address,r->data,r->bytes);
    }
    sw_(0x800811d8,4);a2_native_actor_snapshot_init(PSX_RAM,sizeof PSX_RAM);
    a2_native_actor_snapshot_configure(enabled);
}
static void route(void){
    static const uint32_t entity[]={0x80119710,0x80119a34,0x8011a07c,0x8011a3a0};
    static const uint32_t marker[]={0x801ec000,0x801ec550,0x801ec780,0x801ec8c0};
    R[4]=0x801ec000;R[31]=0x80090228;g0_8008FC54();assert(psx_next==0x8008fc5c);
    for(unsigned j=0;j<4;j++){
        memset(R,0,sizeof R);R[29]=0x801f0000;R[5]=entity[j];R[16]=marker[j];R[17]=marker[j]+60;
        R[7]=lh_(entity[j]+2);R[11]=1;R[22]=99;R[23]=256;
        g0_8008FD48();assert(psx_next==0x8008fcbc);
        assert(lw_(marker[j]+80+60)==lw_(entity[j]+64));
    }
    /* Final recorded callback output is independent of observer code. */
    memcpy(PSX_RAM+0x1ec000,actor_fixture_1,sizeof actor_fixture_1);
    for(unsigned j=0;j<4;j++){
        memset(R,0,sizeof R);R[29]=0x801f0000;R[16]=entity[j];
        sw_(R[29]+1296,lw_(entity[j]+24));sw_(R[29]+1300,0u-lw_(entity[j]+28));sw_(R[29]+1304,lw_(entity[j]+32));
        g0_800903B4();assert(psx_next==0x80025c58||psx_next==0x80090430);
    }
    memset(R,0,sizeof R);R[19]=0x8011763c;ctrl[26]=256;ctrl[24]=160<<16;ctrl[25]=108<<16;
    f_80025844();assert(psx_next==0x80010040&&R[4]==0x8011763c&&R[31]==0x80025854);
}
static void marker_only_route(unsigned insertion,unsigned fault){
    static const uint32_t entity[]={0x80119710,0x80119a34,0x8011a07c,0x8011a3a0};
    static const uint32_t old_marker[]={0x801ec000,0x801ec550,0x801ec780,0x801ec8c0};
    const uint32_t empty=0x8011fb90;uint32_t entities[5],markers[5],cursor=0x801ec000;
    /* Observed opening actor slot32: valid entity, type11, registry0, count0. */
    memset(PSX_RAM+(empty&0x1fffff),0,804);sh_(empty+2,32);sh_(empty+12,11);
    assert(lb_(empty+97)==0&&lw_(empty+64)==0);
    R[4]=cursor;R[31]=0x80090228;g0_8008FC54();assert(psx_next==0x8008fc5c);
    unsigned normal=0;
    for(unsigned j=0;j<5;j++){
        entities[j]=j==insertion?empty:entity[normal++];markers[j]=cursor;
        unsigned count=lb_(entities[j]+97);assert(count<=16);
        memset(R,0,sizeof R);R[29]=0x801f0000;R[5]=entities[j];R[16]=cursor;R[17]=cursor+60;
        R[7]=lh_(entities[j]+2);R[11]=1;R[22]=99;R[23]=256;
        /* Actual writer always emits the marker. Its native count==0 branch
         * skips the part loop and advances the cursor by exactly80. */
        g0_8008FD48();assert(psx_next==0x8008fcbc);
        assert((lh_(cursor)&7)&&R[16]==cursor+80*(count+1));
        cursor=R[16];
    }
    normal=0;
    for(unsigned j=0;j<5;j++){
        if(j!=insertion){
            unsigned count=lb_(entities[j]+97);
            /* Retained real callback output, relocated by exact record index;
             * no synthesis of a skeletal pose or screen-position inference. */
            memcpy(PSX_RAM+(markers[j]&0x1fffff)+80,
                   actor_fixture_1+(old_marker[normal]-0x801ec000)+80,80*count);normal++;
        }
        memset(R,0,sizeof R);R[29]=0x801f0000;R[16]=entities[j];
        sw_(R[29]+1296,lw_(entities[j]+24));sw_(R[29]+1300,0u-lw_(entities[j]+28));sw_(R[29]+1304,lw_(entities[j]+32));
        g0_800903B4();assert(psx_next==0x80025c58||psx_next==0x80090430);
    }
    /* Actual end-of-list continuation writes the terminal0x8000 record. */
    memset(R,0,sizeof R);R[29]=0x801f0000;R[18]=cursor;R[19]=4;R[23]=5;
    g0_80090424();assert(psx_next==0x80037d98&&lh_(cursor)==0x8000);
    if(fault==1)sh_(markers[insertion],0); /* malformed marker */
    if(fault==2)sh_(cursor,0); /* missing sentinel */
    if(fault==3)sh_(markers[insertion?0:1]+80,0x8000); /* early sentinel in a real part */
    memset(R,0,sizeof R);R[19]=0x8011763c;ctrl[26]=256;ctrl[24]=160<<16;ctrl[25]=108<<16;
    f_80025844();assert(psx_next==0x80010040&&R[4]==0x8011763c&&R[31]==0x80025854);
}
static void marker_only_cases(void){
    static A2ActorFrame reference;
    setup(1);route();reference=*a2_native_actor_snapshot_current();assert(reference.valid);
    const unsigned placements[]={0,2,4};
    for(unsigned j=0;j<3;j++)for(unsigned fault=0;fault<4;fault++){
        unsigned insertion=placements[j];
        setup(0);marker_only_route(insertion,fault);
        memcpy(before_ram,PSX_RAM,sizeof before_ram);memcpy(before_scratch,PSX_SCRATCH,sizeof before_scratch);
        memcpy(before_regs,R,sizeof R);memcpy(before_ctrl,ctrl,sizeof ctrl);
        before_next=psx_next;before_work=psx_work;before_hi=HI;before_lo=LO;before_budget=psx_bb_budget;
        setup(1);marker_only_route(insertion,fault);
        assert(!memcmp(before_ram,PSX_RAM,sizeof before_ram)&&!memcmp(before_scratch,PSX_SCRATCH,sizeof before_scratch));
        assert(!memcmp(before_regs,R,sizeof R)&&!memcmp(before_ctrl,ctrl,sizeof ctrl));
        assert(before_next==psx_next&&before_work==psx_work&&before_hi==HI&&before_lo==LO&&before_budget==psx_bb_budget);
        const A2ActorFrame *f=a2_native_actor_snapshot_current();
        if(fault){assert(!f->valid&&(f->fallback&A2_ACTOR_BAD_RECORD));continue;}
        assert(f->valid&&f->instance_count==5&&f->part_count==reference.part_count);
        const A2ActorInstance *empty=&f->instances[insertion];
        assert(empty->entity_address==0x8011fb90&&empty->valid&&empty->part_count==0&&empty->registry_address==0);
        assert(!(empty->fallback&A2_ACTOR_MISSING_ROOT));
        unsigned normal=0;
        for(unsigned k=0;k<5;k++)if(k!=insertion){
            const A2ActorInstance *actual=&f->instances[k],*old=&reference.instances[normal++];
            assert(actual->entity_address==old->entity_address&&actual->part_count==old->part_count&&actual->valid==old->valid);
            assert(actual->action_id==old->action_id&&!memcmp(actual->renderer_root_q12,old->renderer_root_q12,sizeof old->renderer_root_q12));
            for(unsigned q=0;q<old->part_count;q++){
                A2ActorPart expected=reference.parts[old->first_part+q];
                const A2ActorPart *part=&f->parts[actual->first_part+q];expected.address=part->address;
                assert(!memcmp(&expected,part,sizeof expected));
            }
        }
        A2ActorSnapshotStats s;a2_native_actor_snapshot_stats(&s);
        assert(s.begin_hooks==1&&s.instance_hooks==5&&s.root_hooks==5&&s.capture_hooks==1);
    }
}
int main(void){
    marker_only_cases();
    setup(0);route();memcpy(before_ram,PSX_RAM,sizeof before_ram);memcpy(before_regs,R,sizeof R);
    memcpy(before_ctrl,ctrl,sizeof ctrl);before_next=psx_next;before_work=psx_work;
    setup(1);route();assert(!memcmp(before_ram,PSX_RAM,sizeof before_ram));assert(!memcmp(before_regs,R,sizeof R));
    assert(!memcmp(before_ctrl,ctrl,sizeof ctrl)&&before_next==psx_next&&before_work==psx_work);
    const A2ActorFrame *f=a2_native_actor_snapshot_current();assert(f->valid&&f->instance_count==4&&f->part_count==27);
    A2ActorSnapshotStats s;a2_native_actor_snapshot_stats(&s);
    assert(s.begin_hooks==1&&s.instance_hooks==4&&s.root_hooks==4&&s.capture_hooks==1);
    /* Exact active advance increments the native frame; disabled does not. */
    setup(1);uint32_t state=0x80160000;sh_(state,0x8000);sh_(state+2,10);sh_(state+4,2);sh_(state+6,0);
    sb_(state+285,2);R[4]=state;R[29]=0x801f0000;R[31]=0x80088888;f_80025EFC();
    assert(lh_(state+4)==3&&psx_next==0x80088888);a2_native_actor_snapshot_stats(&s);assert(s.animation_update_hooks==1);
    sh_(state,0);R[4]=state;R[29]=0x801f0000;R[31]=0x80088888;f_80025EFC();
    a2_native_actor_snapshot_stats(&s);assert(s.animation_update_hooks==1&&lh_(state+4)==3);
    /* Actual native slot clearing retires exactly one allocation lifetime. */
    setup(1);R[4]=0x80119710;R[31]=0x800aad40;g0_80088380();assert(psx_next==0x800aad40);
    for(unsigned j=0;j<804;j++)assert(PSX_RAM[0x119710+j]==0);
    puts("actor snapshot: real generated begin/metadata/root/submit/advance/clear entries; native state unchanged");
}
