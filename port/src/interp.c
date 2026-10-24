/* MIPS R3000A interpreter — fallback for psx_call misses and trap stubs.
 *
 * Executes instructions straight out of PSX_RAM with the same register
 * file and memory helpers as recompiled code, so it is always correct,
 * just slower.  Calls (jal/jalr) go through psx_call, so compiled code
 * keeps running compiled; returns follow the same continuation rules as
 * the recompiler (`jr` to the entry ra = return, anything else = tail
 * dispatch).
 */
#include <stdio.h>
#include <stdlib.h>
#include "psx_rt.h"

int interp_log;

static inline uint32_t fetch(uint32_t pc) {
    uint32_t v;
    memcpy(&v, PSX_RAM + (pc & 0x1FFFFCu), 4);
    return v;
}

#ifdef A2_WORLD_PRECISION
extern uint32_t psx_frame_no;
static uint64_t wp_object,wp_code_checked=UINT64_MAX,wp_emit_object;
static uint64_t wp_code_hash;
static int wp_code_valid,wp_emit_active;
static unsigned wp_emit_count;
static uint32_t wp_emit_base,wp_sources[4];
static world_precision_vertex wp_pending;
enum { WP_NONE, WP_WORLD, WP_ACTOR };
static unsigned wp_kind,wp_emit_kind,wp_emit_stride,wp_emit_format;
static uint32_t wp_emit_finish,wp_actor_overflow,wp_actor_copy;
static uint64_t wp_shared_scope(void);
/* Sharing never extends the lifetime of local scratch. Every actual RTPS in
 * a consumer part must use one owner camera; a transient H/OF/wide mismatch
 * poisons loans for that part even when controls are restored before emit. */
static uint64_t wp_shared_part_scope;
static unsigned wp_shared_part_bad;
static struct {
    uint64_t scope,projection_id,object;
    uint32_t copy,word;
} wp_shared_projection;
static struct {
    uint64_t scope,projection_id,object,write_version;
    uint32_t address,word,tail[3];
    unsigned phase;
} wp_shared_stage;
static uint64_t wp_shared_consumer_scope(void) {
    uint64_t scope=wp_shared_scope();
    return !wp_shared_part_bad && scope==wp_shared_part_scope?scope:0;
}
static void wp_shared_clear(void) {
    memset(&wp_shared_projection,0,sizeof wp_shared_projection);
    memset(&wp_shared_stage,0,sizeof wp_shared_stage);
    wp_shared_part_scope=0;wp_shared_part_bad=0;
}
static struct {
    unsigned wanted,kind,valid;
    uint32_t object,raw[3],whole[3],matrix_address,matrix[5];
    uint64_t code_version,prior_object;
} wp_camera;
static struct {
    uint64_t object;
    uint32_t producer,xy,z,pose_remainder[3];
    int pose_valid;
} wp_camera_input;

/* One bit per aligned instruction in the proven low-RAM renderer. Keep
 * these dispatch sets separate from the guards below: membership only
 * decides whether a hook can have work, never whether provenance is valid.
 * GTE commands at every PC also enter wp_before to retire staged inputs. */
#define WP_HOOK_BIT(offset) (1u<<(((offset)>>2)&7u))
#define WP_HOOK_BYTE(offset) [(offset)>>5]=WP_HOOK_BIT(offset)
static const uint8_t wp_before_sites[0x5740/32]={
    WP_HOOK_BYTE(0x00a8),WP_HOOK_BYTE(0x011c),WP_HOOK_BYTE(0x041c),
    WP_HOOK_BYTE(0x0c34),WP_HOOK_BYTE(0x0d28),WP_HOOK_BYTE(0x0d4c),
    WP_HOOK_BYTE(0x26c8),WP_HOOK_BYTE(0x2e68),WP_HOOK_BYTE(0x2edc),
    WP_HOOK_BYTE(0x30c0),WP_HOOK_BYTE(0x30f8),WP_HOOK_BYTE(0x3194),
    WP_HOOK_BYTE(0x3350),WP_HOOK_BYTE(0x338c),WP_HOOK_BYTE(0x38b8),
    WP_HOOK_BYTE(0x3cbc),WP_HOOK_BYTE(0x5454),WP_HOOK_BYTE(0x554c),
    WP_HOOK_BYTE(0x5614),WP_HOOK_BYTE(0x5700)
};
static const uint8_t wp_store_sites[0x5740/32]={
    WP_HOOK_BYTE(0x0dac),WP_HOOK_BYTE(0x28ac),WP_HOOK_BYTE(0x2988),
    [0x3408>>5]=WP_HOOK_BIT(0x3408)|WP_HOOK_BIT(0x341c),
    WP_HOOK_BYTE(0x3f04),WP_HOOK_BYTE(0x3ff8),WP_HOOK_BYTE(0x4140),
    WP_HOOK_BYTE(0x4248),
    [0x56b0>>5]=WP_HOOK_BIT(0x56b0)|WP_HOOK_BIT(0x56b8),
    WP_HOOK_BYTE(0x56c0),
    [0x56e8>>5]=WP_HOOK_BIT(0x56e8)|WP_HOOK_BIT(0x56f0)|WP_HOOK_BIT(0x56f8)
};
#undef WP_HOOK_BYTE
#undef WP_HOOK_BIT
static inline int wp_hook_site(uint32_t pc,const uint8_t *sites) {
    uint32_t offset=pc-0x80010000u;
    return offset<0x5740u && !(offset&3u) &&
           (sites[offset>>5]&(1u<<((offset>>2)&7u)));
}

static int wp_actor_source(uint32_t address) {
    uint32_t physical=address&0x1fffffffu;
    if(physical>=0x1f800000u && physical<0x1f8003c0u)
        return (physical-0x1f800000u)%16==0;
    if(physical>=0x800000u || !wp_actor_overflow)return 0;
    physical&=0x1fffffu;
    /* Face indices are bytes; indices60..255 use the part's overflow bank. */
    return physical>=wp_actor_overflow && physical-wp_actor_overflow<196u*16u &&
           (physical-wp_actor_overflow)%16==0;
}

static int wp_code_matches(void) {
    if (wp_code_checked!=world_precision_code_version) {
        /* GAME and EVENT have different immutable AL22 extents. Select
         * the mutable context boundary only after matching a complete image. */
        uint64_t hash=UINT64_C(14695981039346656037);
        for(uint32_t p=WORLD_PRECISION_CODE_BEGIN;p<WORLD_PRECISION_CODE_END;p++)
            hash=(hash^PSX_RAM[p])*UINT64_C(1099511628211);
        wp_code_valid=hash==WORLD_PRECISION_CODE_HASH?1:0;
        world_precision_code_end=WORLD_PRECISION_CODE_END;
        if(!wp_code_valid) {
            for(uint32_t p=WORLD_PRECISION_CODE_END;p<WORLD_PRECISION_EVENT_CODE_END;p++)
                hash=(hash^PSX_RAM[p])*UINT64_C(1099511628211);
            wp_code_valid=hash==WORLD_PRECISION_EVENT_CODE_HASH?2:0;
            world_precision_code_end=WORLD_PRECISION_EVENT_CODE_END;
        }
        wp_code_hash=hash;
        wp_code_checked=world_precision_code_version;
        if(!wp_code_valid) {
            wp_object=0;wp_emit_active=0;wp_pending.projection_id=0;
            wp_kind=WP_NONE;
        }
    }
    return wp_code_valid;
}
/* Only observer sites and verified return PCs are normalized. Guest PC,
 * code and control flow are never rewritten; provenance retains native PCs.
 * EVENT's extra emitter paths make a single relocation delta incorrect. */
#define WP_EVENT_SITES(X) \
    X(0x800100a8u,0x800100a8u) \
    X(0x8001011cu,0x8001011cu) \
    X(0x8001041cu,0x80010424u) \
    X(0x80010c34u,0x80010c3cu) \
    X(0x80010d28u,0x80010d30u) \
    X(0x80010d4cu,0x80010d54u) \
    X(0x80010d98u,0x80010da0u) \
    X(0x80010dacu,0x80010db4u) \
    X(0x800126c8u,0x800125b8u) \
    X(0x800128acu,0x8001293cu) \
    X(0x80012988u,0x80012a18u) \
    X(0x80012e68u,0x80012ef8u) \
    X(0x80012edcu,0x80012f6cu) \
    X(0x800130c0u,0x80013158u) \
    X(0x800130f8u,0x80013190u) \
    X(0x80013194u,0x8001322cu) \
    X(0x800132dcu,0x80013374u) \
    X(0x80013304u,0x8001339cu) \
    X(0x80013350u,0x800133e8u) \
    X(0x8001338cu,0x80013424u) \
    X(0x80013400u,0x80013498u) \
    X(0x80013408u,0x800134a0u) \
    X(0x8001341cu,0x800134b4u) \
    X(0x80013420u,0x800134b8u) \
    X(0x80013428u,0x800134c0u) \
    X(0x8001354cu,0x800135e4u) \
    X(0x8001357cu,0x80013614u) \
    X(0x800138b8u,0x80013950u) \
    X(0x80013cbcu,0x80013d54u) \
    X(0x80013f04u,0x8001413cu) \
    X(0x80013ff8u,0x80014230u) \
    X(0x80014140u,0x80014378u) \
    X(0x80014248u,0x80014480u) \
    X(0x800111b4u,0x800111bcu) \
    X(0x800111f4u,0x800111fcu) \
    X(0x80011240u,0x80011248u) \
    X(0x80011280u,0x80011288u) \
    X(0x800112f4u,0x800112fcu) \
    X(0x80011334u,0x8001133cu) \
    X(0x80013754u,0x800137ecu) \
    X(0x800137e0u,0x80013878u) \
    X(0x80013894u,0x8001392cu) \
    X(0x8001371cu,0x800137b4u) \
    X(0x800137a8u,0x80013840u) \
    X(0x8001385cu,0x800138f4u)
static uint32_t wp_canonical_pc(uint32_t pc) {
    if(wp_code_matches()!=2)return pc;
    switch(pc) {
#define WP_FROM_EVENT(game,event) case event:return game;
        WP_EVENT_SITES(WP_FROM_EVENT)
#undef WP_FROM_EVENT
    default:return 0;
    }
}
static uint32_t wp_native_pc(uint32_t pc) {
    if(wp_code_valid!=2)return pc;
    switch(pc) {
#define WP_TO_EVENT(game,event) case game:return event;
        WP_EVENT_SITES(WP_TO_EVENT)
#undef WP_TO_EVENT
    default:return 0;
    }
}
#undef WP_EVENT_SITES
static uint32_t wp_context(void) {
    return wp_code_valid==2?WORLD_PRECISION_EVENT_CODE_END:WORLD_PRECISION_CODE_END;
}
/* Opt-in precise actor visibility. This changes emitted draw packets and
 * their allocation, unlike projection-only precision. Native NCLIP/GTE
 * arithmetic remains intact; the proven branch uses the matching HD face. */
#define A2_PRECISE_CULL_IMPLEMENTED 1
static int wp_precise_cull_mode=-1;
static struct { int mode,have;uint32_t frame,attempts,rejected;int64_t minimum; } wp_budget={.mode=-1};
static void wp_budget_flush(void) {
    if(!wp_budget.have)return;
    fprintf(stderr,"actor-packet-budget f=%u attempts=%u rejected=%u min_remaining=%lld\n",
            wp_budget.frame,wp_budget.attempts,wp_budget.rejected,(long long)wp_budget.minimum);
    wp_budget.have=0;
}
static void wp_budget_observe(unsigned bytes) {
    if(wp_budget.mode<0) {
        const char *value=getenv("A2_PACKET_BUDGET_LOG");
        wp_budget.mode=value && !strcmp(value,"1");
        if(wp_budget.mode)atexit(wp_budget_flush);
    }
    if(!wp_budget.mode)return;
    if(wp_budget.have && wp_budget.frame!=psx_frame_no)wp_budget_flush();
    if(!wp_budget.have) {
        wp_budget.have=1;wp_budget.frame=psx_frame_no;wp_budget.attempts=wp_budget.rejected=0;
        wp_budget.minimum=INT64_MAX;
    }
    uint32_t limit=lw_(R[4]+0x64);int64_t remaining=(int64_t)limit-R[2]-bytes;
    wp_budget.attempts++;wp_budget.rejected+=R[2]>=limit;
    if(remaining<wp_budget.minimum)wp_budget.minimum=remaining;
}
static int wp_precise_cull_condition(uint32_t pc,uint32_t opcode,int native) {
    if(wp_precise_cull_mode<0) {
        const char *mode=getenv("A2_PRECISE_CULL"),*raster=getenv("A2_WORLD_RASTER");
        wp_precise_cull_mode=mode && raster && !strcmp(raster,"1")?
                             (!strcmp(mode,"2")?2:!strcmp(mode,"1")):0;
    }
    /* Mode1 preserves G's zero-area rescue. Mode2 uses the proven exact
     * orientation also when integer rounding reverses the native sign. */
    if(wp_precise_cull_mode==1 && (native || (int32_t)R[1]!=0))return native;
    if(!wp_precise_cull_mode || world_precision_raster_scale<2 || !world_camera_enabled || wp_kind!=WP_ACTOR || !wp_object ||
       !wp_code_matches() || R[4]!=(0x80000000u|wp_context()) || R[5]!=0x1f800000u ||
       (lh_(R[4]+0xab0)&0x800u) ||
       (pc==0x8001354cu?opcode!=0x1c200011u:pc!=0x8001357cu || opcode!=0x1c200007u))return native;
    uint32_t sources[4],words[4];
    for(unsigned i=0;i<4;i++) {
        sources[i]=R[8+i];words[i]=R[16+i*2];
        if(!wp_actor_source(sources[i]) || lw_(sources[i])!=words[i])return native;
    }
    uint32_t face=R[3]&0x1fffffffu;
    if((face&3u) || face>PSX_RAM_SIZE-80u)return native;
    unsigned layers=(lh_(R[3])&4u)?2:1,count=0;
    for(unsigned layer=0;layer<layers;layer++) {
        unsigned command=lw_(R[3]+8+36*layer)>>24,format=command&0xfcu;
        if(format!=0x30 && format!=0x34 && format!=0x38 && format!=0x3c)return native;
        unsigned final=(command&((uint16_t)lh_(R[5]+0x3d0)>>8))|
                       ((uint16_t)lh_(R[5]+0x3d2)>>8);
        if((final&0xfcu)!=format || (count && count!=((format&8)?4u:3u)))return native;
        count=(format&8)?4:3;
    }
    const uint32_t packet_words[4]={words[0],words[1],words[count==4?3:2],words[2]};
    if(!world_precision_raster_extent(packet_words,count))return native;
    int front;
    if(!world_precision_frontface_actor(sources,words,wp_object,pc==0x8001357cu,wp_shared_consumer_scope(),&front))return native;
    if(front!=native && world_precision_trace_active(psx_frame_no))
        fprintf(stderr,"precise-cull f=%u pc=%08X face=%08X native=%d precise=%d\n",psx_frame_no,wp_native_pc(pc),R[3],native,front);
    return front;
}
static int wp_camera_ram(uint32_t address,uint32_t bytes) {
    uint32_t p=address&0x1fffffffu;
    return !(address&3) && p<0x800000u && (p&0x1fffffu)<=PSX_RAM_SIZE-bytes;
}
static void wp_camera_clear(void) {
    memset(&wp_camera,0,sizeof wp_camera);
    wp_camera_input.object=0;
    world_precision_camera_disarm();
}
static int wp_camera_source_matches(void) {
    if(!wp_camera.valid || wp_object<=wp_camera.prior_object || wp_kind!=wp_camera.kind ||
       wp_camera.code_version!=world_precision_code_version || !wp_code_matches() ||
       (R[4]&0x1fffffffu)!=wp_context() || (R[5]&0x1fffffffu)!=0x1f800000u ||
       lw_(R[4]+0x68)!=wp_camera.object ||
       lw_(wp_camera.object+0x1c)!=wp_camera.matrix_address)return 0;
    for(unsigned i=0;i<3;i++)
        if(lw_(wp_camera.object+0x2c+i*4)!=wp_camera.raw[i] ||
           lw_(R[4]+i*4)!=wp_camera.whole[i])return 0;
    for(unsigned i=0;i<5;i++)
        if(lw_(wp_camera.matrix_address+i*4)!=wp_camera.matrix[i])return 0;
    return wp_kind!=WP_ACTOR || !(lw_(R[4]+0x5cc)&0x100u);
}
/* Recheck the same copied owner and camera at projection, completion and
 * use. H/OF are certified at the actual RTPS, never inferred from late state. */
static uint64_t wp_shared_scope(void) {
#ifdef A2_NATIVE_ACTOR_PACKETS
    if(!world_camera_enabled || wp_kind!=WP_ACTOR || !wp_camera_source_matches())return 0;
    uint32_t part=lw_(R[4]+0x70);
    if(!wp_camera_ram(part,80))return 0;
    const A2ActorPacketOwner *o=a2_native_actor_packets_projecting(R[4],part,lw_(part+72));
    if(!o || o->handle>UINT64_MAX/2 || o->projection_h!=(int32_t)gte_ctrl_read(26) ||
       o->projection_ofx!=(int32_t)gte_ctrl_read(24) ||
       o->projection_ofy!=(int32_t)gte_ctrl_read(25))return 0;
    for(unsigned i=0;i<3;i++)if((uint32_t)o->camera_origin_q12[i]!=wp_camera.raw[i])return 0;
    for(unsigned i=0;i<9;i++)
        if(o->camera_rotation_q12[i]!=(int16_t)(wp_camera.matrix[i/2]>>(16*(i%2))))return 0;
    return 2*o->handle+!!a2_wide();
#else
    return 0;
#endif
}
static void wp_shared_project_before(void) {
    memset(&wp_shared_projection,0,sizeof wp_shared_projection);
    memset(&wp_shared_stage,0,sizeof wp_shared_stage);
    uint64_t scope=world_precision_camera_pending()?wp_shared_scope():0;
    /* Every local consumer corner also needs a camera certified at its RTPS.
     * Validate its original part/header/source before publishing that scope. */
    uint32_t h=R[3],source=R[2]-16,base;
    if(!scope || R[30]!=lw_(R[4]+0x70) || !wp_camera_ram(R[30],80) ||
       !wp_camera_ram(h,24) || !wp_camera_ram(source,16)) {wp_shared_part_bad=1;return;}
    uint32_t registry=lw_(R[30]+60);unsigned mesh=(uint16_t)lh_(R[30]+2);
    if(!wp_camera_ram(registry,32+4*(mesh+1)) || lw_(registry+32+4*mesh)!=h) {
        wp_shared_part_bad=1;return;
    }
    unsigned count=(uint16_t)lh_(h+16);base=lw_(h+20);
    if(!count || count>256 || !wp_camera_ram(base,count*16) ||
       source<base || source-base>=count*16 || (source-base)%16) {wp_shared_part_bad=1;return;}
    if(wp_shared_part_scope && wp_shared_part_scope!=scope)wp_shared_part_bad=1;
    if(!wp_shared_part_scope)wp_shared_part_scope=scope;
    /* The original source byte publishes exactly this overflow slot. */
    unsigned exported=lb_(source+12);
    if(exported<60 || (R[23]&0x1fffffu)!=(lw_(R[30]+72)&0x1fffffu) ||
       R[22]!=R[23]+16u*(exported-60))return;
    wp_shared_projection.scope=scope;wp_shared_projection.object=wp_object;
    wp_shared_projection.copy=R[22];
}
static void wp_shared_project_after(void) {
    world_precision_vertex v;
    if(!wp_shared_projection.scope || wp_shared_projection.scope!=wp_shared_scope() ||
       !world_precision_gte_read(14,gte_data_read(14),&v) ||
       v.projection_kind!=WORLD_PROJECTION_CAMERA || v.camera_generation!=wp_object ||
       v.producer_pc!=wp_native_pc(0x8001338cu)) {wp_shared_projection.scope=0;return;}
    wp_shared_projection.projection_id=v.projection_id;
    wp_shared_projection.word=v.native_word;
}
/* Only the two native completion stores may advance this construction. Any
 * other write, even an identical value elsewhere, conservatively retires it. */
static int wp_shared_half_before(uint32_t pc,uint32_t opcode,uint32_t address,uint32_t value) {
    if(!wp_shared_stage.phase)return 0;
    unsigned phase=wp_shared_stage.phase;
    if(wp_shared_stage.write_version==UINT64_MAX ||
       world_precision_write_version!=wp_shared_stage.write_version ||
       wp_object!=wp_shared_stage.object || wp_shared_scope()!=wp_shared_stage.scope ||
       pc!=(phase==1?0x80013420u:0x80013428u) ||
       opcode!=(phase==1?0xa6d40004u:0xa6c10006u) ||
       address!=wp_shared_stage.address+(phase==1?4u:6u) ||
       (uint16_t)value!=(uint16_t)(wp_shared_stage.tail[0]>>(phase==1?0:16))) {
        wp_shared_stage.phase=0;return 0;
    }
    return 1;
}
static void wp_shared_half_after(void) {
    if(world_precision_write_version!=wp_shared_stage.write_version+1) {
        wp_shared_stage.phase=0;return;
    }
    wp_shared_stage.write_version=world_precision_write_version;
    if(wp_shared_stage.phase++==1)return;
    wp_shared_stage.phase=0;
    if(wp_shared_scope()!=wp_shared_stage.scope || lw_(wp_shared_stage.address)!=wp_shared_stage.word)return;
    for(unsigned i=0;i<3;i++)if(lw_(wp_shared_stage.address+4+4*i)!=wp_shared_stage.tail[i])return;
    (void)world_precision_share_record(wp_shared_stage.address,wp_shared_stage.word,
        wp_shared_stage.object,wp_shared_stage.projection_id,wp_shared_stage.scope);
}
/* Diagnostic local-pose precision. The actual position MVMVA132DC
 * owns this snapshot; normal MVMVA13304 cannot supply its input or lifetime. */
#define A2_LOCAL_POSE_IMPLEMENTED 1
static int wp_local_pose_mode=-1;
static struct {
    uint64_t object,code_version;
    uint32_t part,source,header,registry_entry;
    uint32_t part_words[20],source_words[4],header_words[6];
    uint32_t input_xy,input_z,control[8];
} wp_pose_source;
static int wp_pose_enabled(void) {
    if(wp_local_pose_mode<0) {
        const char *value=getenv("A2_LOCAL_POSE");
        wp_local_pose_mode=value && !strcmp(value,"1");
    }
    return wp_local_pose_mode;
}
static void wp_pose_capture(uint32_t opcode) {
    wp_pose_source.object=0;
    if(!wp_pose_enabled() || opcode!=0x4a480012u || wp_kind!=WP_ACTOR ||
       !wp_camera_source_matches())return;
    uint32_t part=R[30],source=R[2],header=R[3];
    if(!wp_camera_ram(part,80) || !wp_camera_ram(source,16) || !wp_camera_ram(header,24))return;
    unsigned mesh=(uint16_t)lh_(part+2);uint32_t registry=lw_(part+60);
    if(!wp_camera_ram(registry,32u+(mesh+1u)*4u) || lw_(registry+32+mesh*4)!=header)return;
    wp_pose_source.part=part;wp_pose_source.source=source;wp_pose_source.header=header;
    wp_pose_source.registry_entry=registry+32+mesh*4;
    for(unsigned i=0;i<20;i++)wp_pose_source.part_words[i]=lw_(part+i*4);
    for(unsigned i=0;i<4;i++)wp_pose_source.source_words[i]=lw_(source+i*4);
    for(unsigned i=0;i<6;i++)wp_pose_source.header_words[i]=lw_(header+i*4);
    wp_pose_source.input_xy=gte_data_read(0);wp_pose_source.input_z=gte_data_read(1);
    for(unsigned i=0;i<8;i++)wp_pose_source.control[i]=gte_ctrl_read((int)i);
    wp_pose_source.code_version=world_precision_code_version;wp_pose_source.object=wp_object;
}
static int wp_pose_snapshot_matches(unsigned advance) {
    if(!wp_pose_source.object || wp_pose_source.object!=wp_object || wp_kind!=WP_ACTOR ||
       wp_pose_source.code_version!=world_precision_code_version || R[30]!=wp_pose_source.part ||
       R[3]!=wp_pose_source.header || R[2]!=wp_pose_source.source+advance ||
       lw_(wp_pose_source.registry_entry)!=wp_pose_source.header)return 0;
    for(unsigned i=0;i<20;i++)if(lw_(wp_pose_source.part+i*4)!=wp_pose_source.part_words[i])return 0;
    for(unsigned i=0;i<4;i++)if(lw_(wp_pose_source.source+i*4)!=wp_pose_source.source_words[i])return 0;
    for(unsigned i=0;i<6;i++)if(lw_(wp_pose_source.header+i*4)!=wp_pose_source.header_words[i])return 0;
    return 1;
}
static int wp_pose_fraction_checked(uint32_t remainder[3]) {
    if(!wp_pose_enabled() || !wp_pose_snapshot_matches(0) || !wp_camera_source_matches())return 0;
    uint32_t part=R[30],source=R[2],header=R[3];
    if(!wp_camera_ram(part,80) || !wp_camera_ram(source,16) || !wp_camera_ram(header,24))return 0;
    unsigned flags=(uint16_t)lh_(part),mesh=(uint16_t)lh_(part+2);
    if(flags&(0x8000u|0x0200u|7u))return 0;
    uint32_t registry=lw_(part+60);
    if(!wp_camera_ram(registry,32u+(mesh+1u)*4u) || lw_(registry+32+mesh*4)!=header)return 0;
    uint32_t vertex_base=lw_(flags&0x1000u?part+4:header+20);
    unsigned count=(uint16_t)lh_(header+16);
    if(!count || count>256 || !wp_camera_ram(vertex_base,count*16) || source<vertex_base ||
       source-vertex_base>=count*16 || (source-vertex_base)%16)return 0;
    int16_t local[3],matrix[9];
    for(unsigned i=0;i<3;i++)local[i]=(int16_t)((uint16_t)lh_(source+i*2)+(uint16_t)lh_(part+52+i*2));
    for(unsigned i=0;i<9;i++)matrix[i]=(int16_t)lh_(part+32+i*2);
    if(wp_pose_source.input_xy!=((uint16_t)local[0]|((uint32_t)(uint16_t)local[1]<<16)) ||
       (int16_t)wp_pose_source.input_z!=local[2])return 0;
    for(unsigned i=0;i<8;i++)if(gte_ctrl_read((int)i)!=wp_pose_source.control[i])return 0;
    for(unsigned i=0;i<5;i++) {
        uint32_t expected=i==4?(uint32_t)(int32_t)matrix[8]:lw_(part+32+i*4);
        if(gte_ctrl_read((int)i)!=expected)return 0;
    }
    for(unsigned i=0;i<3;i++)if(gte_ctrl_read(5+(int)i))return 0;
    for(unsigned row=0;row<3;row++) {
        int64_t sum=0;
        for(unsigned col=0;col<3;col++)sum+=(int64_t)matrix[row*3+col]*local[col];
        int64_t whole=sum/4096-(sum<0 && sum%4096!=0);
        int64_t translation=(int32_t)lw_(part+8+row*4)+(int64_t)(int32_t)lw_(part+20+row*4)-
                            (int32_t)lw_(R[4]+row*4);
        int64_t posed=whole+translation;
        if(posed<INT16_MIN || posed>INT16_MAX || (int32_t)R[8+row]!=posed)return 0;
        remainder[row]=(uint32_t)(sum-whole*4096);
    }
    return 1;
}
static int wp_pose_fraction(uint32_t remainder[3]) {
    int valid=wp_pose_fraction_checked(remainder);
    if(wp_local_pose_mode && world_precision_trace_active(psx_frame_no))
        fprintf(stderr,"local-pose f=%u part=%08X source=%08X valid=%d remainder=%u,%u,%u\n",
                psx_frame_no,R[30],R[2],valid,valid?remainder[0]:0,
                valid?remainder[1]:0,valid?remainder[2]:0);
    return valid;
}
static void wp_camera_before(uint32_t pc,uint32_t opcode) {
    if(pc==0x800132dcu)wp_pose_capture(opcode);
    else if((opcode&0xfe000000u)==0x4a000000u && pc!=0x80013304u && pc!=0x8001338cu)
        wp_pose_source.object=0;
    if(pc==0x800100a8u || pc==0x80012e68u) {
        wp_camera_clear();
        if(wp_camera_ram(R[4],0x5c)) {
            wp_camera.wanted=pc==0x800100a8u?WP_WORLD:WP_ACTOR;
            wp_camera.object=R[4];
        }
    } else if(pc==0x8001041cu || pc==0x800130c0u) {
        /*1041C is the terminal JAL's delay slot, before14CD8 replaces
         * the shared matrix scratch.130C0 begins the actor epilogue. */
        wp_camera_clear();
    } else if(pc==0x8001011cu || pc==0x80012edcu) {
        unsigned kind=pc==0x8001011cu?WP_WORLD:WP_ACTOR;
        unsigned wanted=wp_camera.wanted;wp_camera.wanted=0;wp_camera.valid=0;
        if(wanted!=kind || R[2]!=wp_camera.object || !wp_code_matches() ||
           (R[4]&0x1fffffffu)!=wp_context() || (R[5]&0x1fffffffu)!=0x1f800000u ||
           lw_(R[4]+0x68)!=wp_camera.object)return;
        uint32_t matrix=lw_(wp_camera.object+0x1c);
        if(!wp_camera_ram(matrix,20))return;
        for(unsigned i=0;i<3;i++) {
            uint32_t raw=lw_(wp_camera.object+0x2c+i*4);
            int32_t value=(int32_t)raw;
            uint32_t whole=(uint32_t)(value/4096-(value<0 && value%4096!=0));
            if(lw_(R[4]+i*4)!=whole)return;
            wp_camera.raw[i]=raw;wp_camera.whole[i]=whole;
        }
        for(unsigned i=0;i<5;i++)wp_camera.matrix[i]=lw_(matrix+i*4);
        wp_camera.matrix_address=matrix;wp_camera.kind=kind;
        /* A setup cannot lend its camera to the previous object's source
         * records. Require a real10C34/13194 begin after this snapshot. */
        wp_camera.prior_object=wp_object;
        wp_camera.code_version=world_precision_code_version;wp_camera.valid=1;
    } else if(pc==0x80010d28u || pc==0x80013350u) {
        /* Full32 posed XYZ still exist before ANDffff/SLL16. ACTOR has
         * the camera matrix in t3..t7 here; CTC2 loads it later13368..78. */
        wp_camera_input.object=0;wp_camera_input.pose_valid=0;world_precision_camera_disarm();
        if(!wp_camera_source_matches() ||
           wp_kind!=(pc==0x80010d28u?WP_WORLD:WP_ACTOR))return;
        for(unsigned i=0;i<3;i++)
            if((int32_t)R[8+i]<INT16_MIN || (int32_t)R[8+i]>INT16_MAX)return;
        for(unsigned i=0;i<5;i++)if(R[11+i]!=wp_camera.matrix[i])return;
        wp_camera_input.pose_valid=pc==0x80013350u && wp_pose_fraction(wp_camera_input.pose_remainder);
        wp_camera_input.object=wp_object;
        wp_camera_input.producer=wp_native_pc(pc==0x80010d28u?0x80010d4cu:0x8001338cu);
        wp_camera_input.xy=(uint16_t)R[8]|((uint32_t)(uint16_t)R[9]<<16);
        wp_camera_input.z=(uint32_t)(int32_t)(int16_t)R[10];
    } else if(pc==0x80010d4cu || pc==0x8001338cu) {
        world_precision_camera_disarm();
        int valid=wp_camera_input.object && wp_camera_input.object==wp_object &&
                  wp_camera_input.producer==wp_native_pc(pc) && wp_camera_source_matches() &&
                  gte_data_read(0)==wp_camera_input.xy &&
                  (uint32_t)(int32_t)(int16_t)gte_data_read(1)==wp_camera_input.z;
        for(unsigned i=0;valid && i<5;i++) {
            /* C4 is a signed16 control register; its source word contains
             * a padding halfword that CTC2 deliberately discards. */
            uint32_t expected=i==4?(uint32_t)(int32_t)(int16_t)wp_camera.matrix[i]:wp_camera.matrix[i];
            if(gte_ctrl_read(i)!=expected)valid=0;
        }
        if(valid) {
            uint32_t remainder[3];
            for(unsigned i=0;i<3;i++)remainder[i]=wp_camera.raw[i]&4095u;
            if(wp_camera_input.pose_valid && wp_pose_snapshot_matches(16))
                world_precision_camera_arm_pose(wp_native_pc(pc),remainder,wp_camera_input.pose_remainder,wp_object);
            else world_precision_camera_arm(wp_native_pc(pc),remainder,wp_object);
        }
        wp_pose_source.object=0;
        wp_camera_input.object=0;
    } else if(pc==0x80010c34u || pc==0x800130f8u || pc==0x80013194u ||
              pc==0x800138b8u || (opcode&0xfe000000u)==0x4a000000u) {
        /* A different object or an intervening GTE command cannot reuse
         * a previously verified posed input, even if native XY coincide. */
        wp_camera_input.object=0;world_precision_camera_disarm();
    }
}
static void wp_before(uint32_t pc,uint32_t opcode) {
    if(pc==0x80010c34u || pc==0x800130f8u || pc==0x80013194u ||
       pc==0x800138b8u || pc==0x80012e68u || pc==0x800130c0u)wp_shared_clear();
    else if((opcode&0xfe000000u)==0x4a000000u) {
        wp_shared_projection.scope=0;wp_shared_stage.phase=0;
    }
    if(world_camera_enabled)wp_camera_before(pc,opcode);
    if(pc==0x8001338cu)wp_shared_project_before();
    if(pc==0x80015454u||pc==0x8001554cu||pc==0x80015614u||pc==0x80015700u){
        a2_world_shadow_before(pc,R,wp_code_matches()==1);return;
    }
    if(pc==0x800130f8 || pc==0x800138b8) {
        /* Actor/part entry and final return fence off reused scratch records.
         * Early filter/model-missing returns occur before the13194 begin. */
        wp_object=0;wp_kind=WP_NONE;wp_emit_active=0;wp_pending.projection_id=0;
        wp_actor_overflow=0;wp_actor_copy=0;
    } else if(pc==0x80013194) {
        wp_pending.projection_id=0;wp_emit_active=0;
        wp_object=wp_code_matches() && (R[5]&0x1fffffffu)==0x1f800000u?
                  world_precision_begin_object():0;
        wp_kind=wp_object?WP_ACTOR:WP_NONE;
        wp_actor_overflow=0;wp_actor_copy=0;
    } else if(pc==0x80010c34) {
        wp_pending.projection_id=0;wp_emit_active=0;
        wp_object=wp_code_matches()?world_precision_begin_object():0;
        wp_kind=wp_object?WP_WORLD:WP_NONE;
        world_precision_trace_object(psx_frame_no,wp_object,wp_code_checked,
                                     wp_code_hash,wp_code_valid,R[4],R[5]);
    } else if(pc==0x800126c8) {
        wp_emit_active=0;
        /* Direct126C4 and material12A78 paths converge here before XY
         * packing. The wrapper changes UV/color/tpage/CLUT, then jumps
         * from12E60 to126C8 with the same source pointers and s0..s7 XY.
         * Only these six far-world callers are proven; near subdivision,
         * actors and alternative emitters retain native fallback. */
        if(wp_kind!=WP_WORLD || !wp_object || !wp_code_matches() || (R[5]&0x1fffffff)!=0x1f800000 ||
            (wp_canonical_pc(R[31])!=0x800111b4 && wp_canonical_pc(R[31])!=0x80011240 && wp_canonical_pc(R[31])!=0x800112f4 &&
             wp_canonical_pc(R[31])!=0x800111f4 && wp_canonical_pc(R[31])!=0x80011280 && wp_canonical_pc(R[31])!=0x80011334)) return;
        /* The same far dispatcher routes cmd3C quads to127AC and cmd34
         * triangles to128B8. Triangles consume original indices0/1/2;
         * their fourth scratch slot/register pair is not a vertex. */
        uint32_t format=R[8]&0xfc000000u;
        if(format!=0x3c000000u && format!=0x34000000u) return;
        wp_emit_count=format==0x3c000000u?4:3;
        const unsigned quad_order[]={0,1,3,2};
        for(unsigned i=0;i<wp_emit_count;i++) {
            unsigned source_index=wp_emit_count==4?quad_order[i]:i;
            uint32_t source=lw_(R[5]+0x3b8+source_index*4);
            uint32_t phys=source&0x1fffffff;
            uint32_t xy=(R[16+source_index*2]&0xffff)|
                        ((R[17+source_index*2]&0xffff)<<16);
            if(phys<0x1f800000 || phys>=0x1f8003a8 ||
               (phys-0x1f800000)%12 || lw_(source)!=xy || lh_(source+4)<384) return;
            wp_sources[i]=source;
        }
        wp_emit_base=R[2];wp_emit_object=wp_object;wp_emit_kind=WP_WORLD;wp_emit_active=1;
    } else if(pc==0x80013cbc) {
        /*13CB8 direct and138C8 material-wrapper entries converge here before
         * XY repacking. The wrapper changes UV/color, never source geometry. */
        wp_emit_active=0;
        if(wp_kind!=WP_ACTOR || !wp_object || !wp_code_matches() ||
           (R[5]&0x1fffffffu)!=0x1f800000u ||
           (wp_canonical_pc(R[31])!=0x80013754u && wp_canonical_pc(R[31])!=0x800137e0u && wp_canonical_pc(R[31])!=0x80013894u &&
            wp_canonical_pc(R[31])!=0x8001371cu && wp_canonical_pc(R[31])!=0x800137a8u && wp_canonical_pc(R[31])!=0x8001385cu) ||
           (lh_(R[4]+0xab0)&0x0800))return;
        unsigned format=(R[8]>>24)&0xfcu;
        if(format!=0x30 && format!=0x34 && format!=0x38 && format!=0x3c)return;
        wp_emit_count=format&8?4:3;wp_emit_stride=format&4?12:8;
        wp_budget_observe(8+wp_emit_count*wp_emit_stride);
        const unsigned quad_order[]={0,1,3,2};
        for(unsigned i=0;i<wp_emit_count;i++) {
            unsigned index=wp_emit_count==4?quad_order[i]:i;
            uint32_t source=lw_(R[5]+0x3b8+index*4);
            uint32_t xy=(R[16+index*2]&0xffff)|((R[17+index*2]&0xffff)<<16);
            if(!wp_actor_source(source) || lw_(source)!=xy || !lh_(source+4))return;
            wp_sources[i]=source;
        }
        wp_emit_finish=format==0x30?0x80013ff8u:format==0x34?0x80014248u:
                       format==0x38?0x80013f04u:0x80014140u;
        wp_emit_base=R[2];wp_emit_object=wp_object;wp_emit_format=format;
        wp_emit_kind=WP_ACTOR;wp_emit_active=1;
    }
}
static void wp_mfc2(uint32_t pc,int reg,uint32_t word) {
    uint32_t producer=wp_kind==WP_WORLD && pc==0x80010d98?0x80010d4cu:
                      wp_kind==WP_ACTOR && pc==0x80013400?0x8001338cu:0;
    if(!producer || reg!=14 || !wp_object || !wp_code_matches()) return;
    if(!world_precision_gte_read(reg,word,&wp_pending) ||
       wp_pending.producer_pc!=wp_native_pc(producer)) wp_pending.projection_id=0;
    if(wp_kind==WP_ACTOR) {
        uint32_t overflow=R[23]&0x1fffffffu;
        wp_actor_overflow=overflow<0x800000u?(overflow&0x1fffffu):0;
        if(!wp_actor_overflow || wp_actor_overflow>PSX_RAM_SIZE-196u*16u ||
           (wp_actor_overflow&3))wp_actor_overflow=0;
        wp_actor_copy=(R[22]&0x1fffffffu)<0x800000u &&
                      wp_actor_source(R[22])?R[22]:0;
    }
    world_precision_trace(psx_frame_no,"mfc2",wp_native_pc(pc),0,
                         wp_pending.projection_id?&wp_pending:NULL);
}
static void wp_after_store(uint32_t pc,uint32_t opcode,uint32_t address,uint32_t word) {
    if(pc==0x80010dac && opcode==0xacd30000 && wp_kind==WP_WORLD && wp_object && wp_code_matches()) {
        if(wp_pending.projection_id && wp_pending.native_word==word) {
            world_precision_record(address,word,wp_object,&wp_pending);
            if(world_precision_trace_active(psx_frame_no)) {
                world_precision_vertex trace=wp_pending;
                trace.generation=wp_object;trace.source_address=address&0x1fffffff;
                world_precision_trace(psx_frame_no,"record",wp_native_pc(pc),address,&trace);
            }
        } else world_precision_trace(psx_frame_no,"record",wp_native_pc(pc),address,NULL);
        wp_pending.projection_id=0;
    } else if(wp_kind==WP_ACTOR &&
              ((pc==0x80013408 && opcode==0xacd30000) ||
               (pc==0x8001341c && opcode==0xaed30000))) {
        if(wp_object && wp_code_matches() && wp_actor_source(address) &&
           (pc==0x80013408 || address==wp_actor_copy) &&
           wp_pending.projection_id && wp_pending.native_word==word) {
            world_precision_record(address,word,wp_object,&wp_pending);
            if(pc==0x8001341cu) {
                wp_shared_stage.phase=0;
                if(wp_shared_projection.scope && wp_shared_projection.scope==wp_shared_scope() &&
                   wp_shared_projection.object==wp_object && wp_shared_projection.copy==address &&
                   wp_shared_projection.projection_id==wp_pending.projection_id &&
                   wp_shared_projection.word==word) {
                    wp_shared_stage.scope=wp_shared_projection.scope;
                    wp_shared_stage.object=wp_object;
                    wp_shared_stage.projection_id=wp_pending.projection_id;
                    wp_shared_stage.address=address;wp_shared_stage.word=word;
                    wp_shared_stage.tail[0]=(uint16_t)R[20]|((uint32_t)(uint16_t)R[1]<<16);
                    wp_shared_stage.tail[1]=lw_(address+8);wp_shared_stage.tail[2]=lw_(address+12);
                    wp_shared_stage.write_version=world_precision_write_version;
                    wp_shared_stage.phase=1;
                }
            }
            if(world_precision_trace_active(psx_frame_no)) {
                world_precision_vertex trace=wp_pending;
                trace.generation=wp_object;trace.source_address=address&0x1fffffffu;
                world_precision_trace(psx_frame_no,"record",wp_native_pc(pc),address,&trace);
            }
        } else world_precision_trace(psx_frame_no,"record",wp_native_pc(pc),address,NULL);
        /* The exact branch delay slot increments a2 before the optional copy;
         * the second store still belongs to the same projected vertex. */
        if(pc==0x8001341c || !wp_actor_copy)wp_pending.projection_id=0;
    } else if(wp_emit_active && wp_emit_kind==WP_ACTOR && pc==wp_emit_finish &&
              opcode==(wp_emit_stride==12?0xac570020u:0xac570018u)) {
        if(wp_kind!=WP_ACTOR || wp_object!=wp_emit_object || R[2]!=wp_emit_base ||
           ((lw_(wp_emit_base+8)>>24)&0xfcu)!=wp_emit_format || !wp_code_matches()) {
            wp_emit_active=0;return;
        }
        uint32_t destinations[4],words[4];
        for(unsigned i=0;i<wp_emit_count;i++) {
            destinations[i]=wp_emit_base+0xc+i*wp_emit_stride;
            words[i]=lw_(destinations[i]);
        }
        int complete=world_precision_emit_actor(destinations,words,wp_sources,wp_emit_count,wp_emit_object,wp_shared_consumer_scope());
        if(world_precision_trace_active(psx_frame_no))for(unsigned i=0;i<wp_emit_count;i++) {
            world_precision_vertex v;
            int valid=complete && world_precision_packet(destinations[i],words[i],&v);
            world_precision_trace(psx_frame_no,"packet",wp_native_pc(pc),destinations[i],valid?&v:NULL);
        }
        wp_emit_active=0;
    } else if((pc==0x800128ac || pc==0x80012988) && opcode==0xac570020) {
        if(!wp_emit_active || wp_emit_kind!=WP_WORLD || wp_object!=wp_emit_object || R[2]!=wp_emit_base ||
           wp_emit_count!=(pc==0x800128ac?4u:3u) ||
           address!=wp_emit_base+0x20 || !wp_code_matches()) return;
        uint32_t destinations[4],words[4];
        for(unsigned i=0;i<wp_emit_count;i++) {
            destinations[i]=wp_emit_base+0xc+i*12;words[i]=lw_(destinations[i]);
        }
        int complete=world_precision_emit(destinations,words,wp_sources,wp_emit_count,wp_emit_object);
        if(world_precision_trace_active(psx_frame_no))for(unsigned i=0;i<wp_emit_count;i++) {
            world_precision_vertex v;
            int valid=complete && world_precision_packet(destinations[i],words[i],&v);
            world_precision_trace(psx_frame_no,"packet",wp_native_pc(pc),destinations[i],valid?&v:NULL);
        }
        wp_emit_active=0;
    }
}
#endif

/* execute one non-branch instruction */
static void exec1(uint32_t pc, uint32_t w) {
#if defined(A2_NATIVE_BILLBOARD) && defined(A2_WORLD_PRECISION)
    if(a2_native_billboard_enabled && pc>=0x800100a8u && pc<=0x800150f4u) {
        switch(pc) {
        case 0x800100a8u:case 0x800126c8u:case 0x80014cd8u:
        case 0x80014d4cu:case 0x80014dc8u:case 0x80014dccu:
        case 0x80014e4cu:case 0x80014e50u:case 0x800150f4u:
        case 0x80014318u:case 0x80014444u:case 0x80014498u:
        case 0x800144c8u:case 0x80014548u:case 0x8001454cu:
        case 0x800146b8u:
            a2_native_billboard_before(pc,R,wp_code_matches()==1);break;
        }
    }
#endif
#ifdef A2_NATIVE_ACTOR_PACKETS
    if(a2_native_actor_packets_enabled && pc>=0x80012e68u && pc<=0x80013d54u) {
        switch(pc) {
        case 0x80012e68u:case 0x800130c0u:case 0x800130f8u:
        case 0x80013194u:case 0x800138b8u:
        case 0x80012ef8u:case 0x80013158u:case 0x80013190u:
        case 0x8001322cu:case 0x80013950u:
            a2_native_actor_packets_before(pc,R);break;
        case 0x80013cbcu:case 0x80013d54u: {
            uint32_t control[32]={0};
            for(unsigned c=8;c<=23;c++)control[c]=gte_ctrl_read((int)c);
            for(unsigned c=26;c<=28;c++)control[c]=gte_ctrl_read((int)c);
            a2_native_actor_packets_before_gte(pc,R,control);break;
        }
        }
    }
#endif
#ifdef A2_WORLD_PRECISION
    uint32_t wp_pc=world_precision_enabled?wp_canonical_pc(pc):0;
    if(world_precision_enabled &&
       ((w&0xfe000000u)==0x4a000000u || wp_hook_site(wp_pc,wp_before_sites)))
        wp_before(wp_pc,w);
#endif
    if (w == 0) return;
    uint32_t op = w >> 26, rs = (w >> 21) & 31, rt = (w >> 16) & 31;
    uint32_t rd = (w >> 11) & 31, sa = (w >> 6) & 31, fn = w & 0x3F;
    uint32_t imm = w & 0xFFFF;
    int32_t simm = (int16_t)imm;
    uint32_t ea = R[rs] + (uint32_t)simm;
#ifdef A2_WORLD_PRECISION
#define SET(r, v) do { uint32_t _v = (v); if (r) { R[r] = _v; \
    if(world_precision_enabled && (r)==19) wp_pending.projection_id=0; } } while (0)
#else
#define SET(r, v) do { uint32_t _v = (v); if (r) R[r] = _v; } while (0)
#endif
    switch (op) {
    case 0:
        switch (fn) {
        case 0x00: SET(rd, R[rt] << sa); return;
        case 0x02: SET(rd, R[rt] >> sa); return;
        case 0x03: SET(rd, (uint32_t)((int32_t)R[rt] >> sa)); return;
        case 0x04: SET(rd, R[rt] << (R[rs] & 31)); return;
        case 0x06: SET(rd, R[rt] >> (R[rs] & 31)); return;
        case 0x07: SET(rd, (uint32_t)((int32_t)R[rt] >> (R[rs] & 31))); return;
        case 0x0C: psx_syscall_at(pc); return;
        case 0x0D: psx_break((w >> 6) & 0xFFFFF); return;
        case 0x10: SET(rd, HI); return;
        case 0x11: HI = R[rs]; return;
        case 0x12: SET(rd, LO); return;
        case 0x13: LO = R[rs]; return;
        case 0x18: {
            int64_t p = (int64_t)(int32_t)R[rs] * (int32_t)R[rt];
            LO = (uint32_t)p; HI = (uint32_t)((uint64_t)p >> 32); return;
        }
        case 0x19: {
            uint64_t p = (uint64_t)R[rs] * R[rt];
            LO = (uint32_t)p; HI = (uint32_t)(p >> 32); return;
        }
        case 0x1A: psx_div((int32_t)R[rs], (int32_t)R[rt]); return;
        case 0x1B: psx_divu(R[rs], R[rt]); return;
        case 0x20: case 0x21: SET(rd, R[rs] + R[rt]); return;
        case 0x22: case 0x23: SET(rd, R[rs] - R[rt]); return;
        case 0x24: SET(rd, R[rs] & R[rt]); return;
        case 0x25: SET(rd, R[rs] | R[rt]); return;
        case 0x26: SET(rd, R[rs] ^ R[rt]); return;
        case 0x27: SET(rd, ~(R[rs] | R[rt])); return;
        case 0x2A: SET(rd, (int32_t)R[rs] < (int32_t)R[rt]); return;
        case 0x2B: SET(rd, R[rs] < R[rt]); return;
        }
        break;
    case 8: case 9: SET(rt, R[rs] + (uint32_t)simm); return;
    case 10: SET(rt, (int32_t)R[rs] < simm); return;
    case 11: SET(rt, R[rs] < (uint32_t)simm); return;
    case 12: SET(rt, R[rs] & imm); return;
    case 13: SET(rt, R[rs] | imm); return;
    case 14: SET(rt, R[rs] ^ imm); return;
    case 15: SET(rt, imm << 16); return;
    case 16:
        if (rs == 0) { SET(rt, psx_cop0_read(rd)); return; }
        if (rs == 4) { psx_cop0_write(rd, R[rt]); return; }
        if (rs == 16 && fn == 16) { psx_rfe(); return; }
        break;
    case 18:
        if (w & (1u << 25)) {
#ifdef A2_NATIVE_ACTOR_PACKETS
            if(a2_native_actor_packets_enabled && w==0x4ae80413u &&
               a2_native_actor_packets_color_site(pc,w)) {
                uint32_t data[32]={0},control[32]={0};
                data[0]=gte_data_read(0);data[1]=gte_data_read(1);
                data[6]=gte_data_read(6);data[8]=gte_data_read(8);
                for(unsigned c=8;c<=23;c++)control[c]=gte_ctrl_read((int)c);
                a2_native_actor_packets_color_gte(pc,data,control);
            }
#endif
#ifdef A2_WORLD_PRECISION
            if(world_precision_enabled) world_precision_producer_pc=pc;
#endif
            gte_cmd(w & 0x1FFFFFF);
#ifdef A2_WORLD_PRECISION
            if(world_precision_enabled&&wp_pc==0x8001338cu)wp_shared_project_after();
            if(world_precision_enabled&&pc==0x800155d8u&&wp_code_matches()==1)a2_world_shadow_project(pc,R);
#endif
            return;
        }
        if (rs == 0) {
            SET(rt, gte_data_read(rd));
#ifdef A2_WORLD_PRECISION
            if(world_precision_enabled && rt==19) wp_mfc2(wp_pc,(int)rd,R[rt]);
#endif
            return;
        }
        if (rs == 2) { SET(rt, gte_ctrl_read(rd)); return; }
        if (rs == 4) { gte_data_write(rd, R[rt]); return; }
        if (rs == 6) { gte_ctrl_write(rd, R[rt]); return; }
        break;
    case 32: SET(rt, (uint32_t)(int8_t)lb_(ea)); return;
    case 33: SET(rt, (uint32_t)(int16_t)lh_(ea)); return;
    case 34: SET(rt, lwl_(ea, R[rt])); return;
    case 35: SET(rt, lw_(ea)); return;
    case 36: SET(rt, lb_(ea)); return;
    case 37: SET(rt, lh_(ea)); return;
    case 38: SET(rt, lwr_(ea, R[rt])); return;
    case 40: sb_(ea, R[rt]); return;
    case 41: {
#ifdef A2_WORLD_PRECISION
        int shared=world_precision_enabled && wp_shared_half_before(wp_pc,w,ea,R[rt]);
#endif
        sh_(ea,R[rt]);
#ifdef A2_WORLD_PRECISION
        if(shared)wp_shared_half_after();
#endif
        return;
    }
    case 42: swl_(ea, R[rt]); return;
    case 43:
        sw_(ea, R[rt]);
#ifdef A2_NATIVE_BILLBOARD
        if(a2_native_billboard_enabled && (pc==0x800147e4u||pc==0x800128acu||pc==0x80012988u))
            a2_native_billboard_after_store(pc,ea,R[rt],R);
#endif
#ifdef A2_NATIVE_ACTOR_PACKETS
        if(a2_native_actor_packets_enabled &&
           (pc==0x80013f04u || pc==0x80013ff8u || pc==0x80014140u || pc==0x80014248u ||
            pc==0x8001413cu || pc==0x80014230u || pc==0x80014378u || pc==0x80014480u))
            a2_native_actor_packets_after_store(pc,w,ea,R);
#endif
#ifdef A2_WORLD_PRECISION
        if(world_precision_enabled && wp_hook_site(wp_pc,wp_store_sites))
            { if(wp_pc>=0x800156b0u) { if(wp_code_matches()==1)a2_world_shadow_store(pc,ea,R[rt],R); }
              else wp_after_store(wp_pc,w,ea,R[rt]); }
#endif
        return;
    case 46: swr_(ea, R[rt]); return;
    case 50: gte_data_write(rt, lw_(ea)); return;
    case 58: sw_(ea, gte_data_read(rt)); return;
    }
    fprintf(stderr, "interp: bad insn %08X at %08X\n", w, pc);
    exit(26);
#undef SET
}

/* Interpret one SEGMENT: execute from `entry` until the first call or
 * indirect jump, park the next address in psx_next and return to the
 * flat dispatcher.  In-segment branches/j keep interpreting. */
static int a2_faceprobe = -1, a2_tplprobe = -1;
void psx_interp(uint32_t entry) {
    uint32_t pc = entry;
    uint32_t steps = 0;
    if (a2_faceprobe < 0) {
        a2_faceprobe = getenv("A2_FACEPROBE") ? 1 : 0;
        a2_tplprobe = getenv("A2_TPLPROBE") ? 1 : 0;
    }
    for (;;) {
        if (++steps > 200000000u) {
            fprintf(stderr, "interp: runaway at 0x%08X (entry 0x%08X)\n",
                    pc, entry);
            exit(27);
        }
        /* A2_TPLPROBE: trace the packet code byte through the low-RAM model
         * renderer. 0x80013D88 = after the a1+976/978 code-byte mask/or
         * (t0 = final word0-ish); 0x80013E54 = store of s7 (GTE cr22 result)
         * as a per-vertex color+code word. */
        /* A2_FACEPROBE: capture the per-face template word0 (command byte)
         * as loaded from the face record.  In the GAME00 gameplay overlay
         * (frame ~5098) the quad path does `lw t0,8(v1)` at 0x80013818 and
         * the tri path `lw t0,0x2c(v1)` at 0x80013764, then both jal the
         * emit segment at 0x80013cb8.  v1 = fp+0x3c = face-record list. */
        /* A2_MODELCAP: raw face-record dump, correlated with the GTE
         * RTP lines gte.c writes to the same file */
        {
            int a2_modelcap_active(void);
            FILE *a2_modelcap_file(void);
            extern uint32_t psx_frame_no;
            if ((pc == 0x80013764u || pc == 0x80013818u) &&
                a2_modelcap_active()) {
                FILE *f = a2_modelcap_file();
                if (f) {
                    fprintf(f, "FACE f%u %s ptr=%08X raw=", psx_frame_no,
                            pc == 0x80013764u ? "tri" : "quad", R[3]);
                    for (int i = 0; i < 0x60; i++)
                        fprintf(f, "%02X", (unsigned)lb_(R[3] + i) & 0xFF);
                    fprintf(f, "\n");
                }
            }
        }
        if (a2_faceprobe) {
            extern uint32_t psx_frame_no;
            if (pc == 0x80013818u) {          /* lw t0,8(v1): quad word0 */
                static int q; if (q++ < 40)
                    fprintf(stderr, "face-quad: f%u v1=%08X w0@v1+8=%08X "
                            "flags(v1+0x28)=%02X\n", psx_frame_no, R[3],
                            lw_(R[3] + 8), lb_(R[3] + 0x28));
            }
            if (pc == 0x80013764u) {          /* lw t0,0x2c(v1): tri word0 */
                static int t; if (t++ < 40)
                    fprintf(stderr, "face-tri: f%u v1=%08X w0@v1+0x2c=%08X "
                            "flags(v1+0x4c)=%02X\n", psx_frame_no, R[3],
                            lw_(R[3] + 0x2c), lb_(R[3] + 0x4c));
            }
            if (pc == 0x80013cb8u) {          /* emit dispatch entry: t0=word0 */
                static int e; if (e++ < 60)
                    fprintf(stderr, "emit: f%u t0=%08X cmd=%02X "
                            "at(->a1+0x370,word0)=%08X w0cmd=%02X "
                            "a1+0x384=%08X type(a1+0x3d4)=%08X "
                            "mask976=%04X or978=%04X\n",
                            psx_frame_no, R[8], R[8] >> 24,
                            R[1], R[1] >> 24,
                            lw_(0x1F800384u), lw_(0x1F8003D4u),
                            lh_(0x1F8003D0u), lh_(0x1F8003D2u));
            }
        }
        if (a2_tplprobe) {
            extern uint32_t psx_frame_no;
            if (pc == 0x80013C98u) {          /* right after lw t0,900(a1) */
                static int z; if (z++ < 20)
                    fprintf(stderr, "tpl-load: f%u t0=%08X a1=%08X\n",
                            psx_frame_no, R[8], R[5]);
            }
            if (pc == 0x80013CE8u) {          /* inside the &0xFF00 masks: t0=r8 */
                static int y; if (y++ < 20)
                    fprintf(stderr, "tpl-ce8: f%u t0=%08X at=%08X\n",
                            psx_frame_no, R[8], R[1]);
            }
            if (pc == 0x80013D88u) {          /* after mask: t0=r8 */
                static int a; if (a++ < 20)
                    fprintf(stderr, "tpl-mask: f%u t0=%08X (mask976=%04X "
                            "or978=%04X)\n", psx_frame_no, R[8],
                            lh_(R[5] + 976), lh_(R[5] + 978));
            }
            if (pc == 0x80013DEC) {           /* mtc2 t0,cr6: t0=r8 code byte in */
                static int b; if (b++ < 20)
                    fprintf(stderr, "tpl-gtein: f%u t0=%08X\n",
                            psx_frame_no, R[8]);
            }
            if (pc == 0x80013E54u) {          /* sw s7,8(v0): s7=r23 code out */
                static int c; if (c++ < 20)
                    fprintf(stderr, "tpl-gteout: f%u s7=%08X\n",
                            psx_frame_no, R[23]);
            }
        }
        uint32_t w = fetch(pc);
        uint32_t op = w >> 26, rs = (w >> 21) & 31, rt = (w >> 16) & 31;
        uint32_t fn = w & 0x3F;
        int32_t simm = (int16_t)(w & 0xFFFF);
        uint32_t btarget = pc + 4 + ((uint32_t)simm << 2);
        uint32_t jtarget = ((pc + 4) & 0xF0000000u) | ((w & 0x03FFFFFF) << 2);

        int is_jr   = (op == 0 && fn == 8);
        int is_jalr = (op == 0 && fn == 9);
        int is_j    = (op == 2);
        int is_jal  = (op == 3);
        int is_b    = (op >= 4 && op <= 7) ||
                      (op == 1 && (rt == 0 || rt == 1 || rt == 16 || rt == 17));

        if (!(is_jr || is_jalr || is_j || is_jal || is_b)) {
            exec1(pc, w);
            pc += 4;
            continue;
        }

        int cond = 0;
        if (is_b) {
            switch (op) {
            case 4: cond = R[rs] == R[rt]; break;
            case 5: cond = R[rs] != R[rt]; break;
            case 6: cond = (int32_t)R[rs] <= 0; break;
            case 7: cond = (int32_t)R[rs] > 0; break;
            case 1: cond = (rt & 1) ? (int32_t)R[rs] >= 0
                                    : (int32_t)R[rs] < 0; break;
            }
            if (op == 1 && (rt & 16)) R[31] = pc + 8;   /* b*al links always */
#ifdef A2_WORLD_PRECISION
            if(world_precision_enabled && (pc==0x8001354cu || pc==0x8001357cu ||
                                           pc==0x800135e4u || pc==0x80013614u))
                cond=wp_precise_cull_condition(wp_canonical_pc(pc),w,cond);
#endif
        }
        uint32_t jr_target = R[rs];                      /* before delay slot */
        uint32_t d = fetch(pc + 4);
        exec1(pc + 4, d);                                /* delay slot */

        if (is_j) {
            if (jtarget <= pc) psx_bb();
            pc = jtarget;
        } else if (is_jal) {
            R[31] = pc + 8;
            psx_next = jtarget;
            return;
        } else if (is_jalr) {
            uint32_t rd = (w >> 11) & 31;
            if (rd) R[rd] = pc + 8;
            psx_next = jr_target;
            return;
        } else if (is_jr) {
            psx_next = jr_target;
            return;
        } else {                                         /* conditional */
            if (cond) {
                if (op == 1 && (rt & 16)) {              /* bltzal/bgezal */
                    psx_next = btarget;
                    return;
                }
                if (btarget <= pc) psx_bb();
                pc = btarget;
            } else {
                pc += 8;
            }
        }
    }
}
