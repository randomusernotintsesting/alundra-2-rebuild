#include "world_precision.h"
#include "display_layout.h"
static int output_aspect_width=16,output_aspect_height=9;
void world_precision_set_output_aspect(int w,int h) {
    world_precision_set_projection(w,h,240);
}
/* rows: guest canvas rows shown at the full output height (gameplay 216,
 * otherwise 240). The squeeze keeps world pixels square on the output:
 * (320/rows)*(h/w), i.e. 4h/(3w) for 240 rows. Stored as an equivalent
 * width/height pair for the integer GTE path. */
static int output_raw_width=16,output_raw_height=9;
void world_precision_set_projection(int w,int h,int rows) {
    if(w>0&&w<=16384&&h>0&&h<=16384&&rows>=160&&rows<=240){output_aspect_width=w*rows;output_aspect_height=h*240;
        output_raw_width=w;output_raw_height=h;}
    else {output_aspect_width=16;output_aspect_height=9;output_raw_width=16;output_raw_height=9;}
}
int64_t world_precision_wide_x(int64_t x) {
    return x*(4*output_aspect_height)/(3*output_aspect_width);
}
/* The ordinary 320x216 HUD always fills the output height: (320/216)*(h/w),
 * exactly 5/6 at 16:9. */
double world_precision_hud_scale(void) {
    return (320.0*output_raw_height)/(216.0*output_raw_width);
}
double world_precision_wide_scale(void) {
    return a2_display_wide_scale(output_aspect_width,output_aspect_height);
}
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Separate exact-address maps for source records and completed packets: an
 * emitted face must not evict a source still needed by later faces. Within
 * each map collisions force fallback, never substitute another address. */
#define TAG_COUNT 32768u
typedef struct {
    world_precision_vertex value;
    uint32_t address;
    unsigned kind; /* 0 invalid, 1 vertex record, 2 packet XY */
    uint64_t shared_scope;
} tag;
static tag tags[2][TAG_COUNT];
static world_precision_vertex fifo[3];
static uint64_t serial;
static uint64_t reset_generation;
int world_precision_enabled;
int world_camera_enabled;
int world_precision_raster_scale;
uint32_t world_precision_producer_pc;
uint64_t world_precision_code_version;
uint32_t world_precision_code_end=WORLD_PRECISION_EVENT_CODE_END;
uint64_t world_precision_write_version;
static uint32_t shared_watch_begin=UINT32_MAX,shared_watch_end;
static struct {
    uint32_t producer;
    int32_t remainder[3];
    uint64_t generation, code_version;
} camera;

static uint64_t next_generation(void) {
    if (++serial == 0) {
        memset(tags,0,sizeof tags);
        memset(fifo,0,sizeof fifo);
        shared_watch_begin=UINT32_MAX;shared_watch_end=0;
        serial=1;
    }
    return serial;
}

/* Canonical RAM mirrors plus separate scratchpad; unsupported/MMIO addresses
 * cannot acquire render provenance even though some runtime loads alias RAM. */
static int canonical(uint32_t address, uint32_t *out) {
    uint32_t p=address&0x1fffffff;
    if (p<0x800000) { *out=p&0x1fffff; return 1; }
    if (p>=0x1f800000 && p<0x1f800400) { *out=p; return 1; }
    return 0;
}
static tag *slot(uint32_t address, unsigned kind) {
    return &tags[kind-1][((address>>2)^(address>>17))&(TAG_COUNT-1)];
}
static tag *lookup(uint32_t address, uint32_t word, unsigned kind) {
    uint32_t p;
    if (!world_precision_enabled || (address&3) || !canonical(address,&p)) return NULL;
    tag *t=slot(p,kind);
    return t->kind==kind && t->address==p && t->value.generation &&
           t->value.native_word==word ? t : NULL;
}

void world_precision_reset(void) {
    memset(tags,0,sizeof tags);
    memset(fifo,0,sizeof fifo);
    shared_watch_begin=UINT32_MAX;shared_watch_end=0;
    ++world_precision_write_version;
    world_precision_producer_pc=0;
    reset_generation=next_generation();
    world_precision_code_version++;
    world_precision_code_end=WORLD_PRECISION_EVENT_CODE_END;
    world_precision_camera_disarm();
}
void world_precision_configure(int enabled) {
    world_precision_enabled=enabled!=0;
    world_camera_enabled=0;
    world_precision_reset();
}
void world_camera_configure(int enabled) {
    world_camera_enabled=world_precision_enabled && enabled!=0;
    world_precision_reset();
}
void world_precision_camera_disarm(void) {
    memset(&camera,0,sizeof camera);
}
int world_precision_camera_pending(void) {
    return world_camera_enabled && camera.generation!=0;
}
void world_precision_camera_arm(uint32_t producer,const uint32_t remainder[3],
                                uint64_t generation) {
    world_precision_camera_disarm();
    if(!world_camera_enabled || !world_precision_enabled || !remainder ||
       generation<=reset_generation ||
       (producer!=0x80010d4cu && producer!=0x8001338cu &&
        producer!=0x80010d54u && producer!=0x80013424u))return;
    for(unsigned i=0;i<3;i++)if(remainder[i]>=4096)return;
    camera.producer=producer;camera.generation=generation;
    camera.code_version=world_precision_code_version;
    memcpy(camera.remainder,remainder,sizeof camera.remainder);
}
void world_precision_camera_arm_pose(uint32_t producer,const uint32_t camera_remainder[3],
                                     const uint32_t pose_remainder[3],uint64_t generation) {
    world_precision_camera_disarm();
    if((producer!=0x8001338cu && producer!=0x80013424u) || !pose_remainder)return;
    for(unsigned i=0;i<3;i++)if(pose_remainder[i]>=4096)return;
    world_precision_camera_arm(producer,camera_remainder,generation);
    if(camera.generation)for(unsigned i=0;i<3;i++)
        camera.remainder[i]-=(int32_t)pose_remainder[i];
}
void world_precision_camera_project(const int64_t mac[3],const int16_t rotation[9],
                                    int32_t h,int32_t ofx,int32_t ofy,int wide) {
    uint64_t generation=camera.generation,version=camera.code_version;
    uint32_t producer=camera.producer;
    int32_t remainder[3];
    memcpy(remainder,camera.remainder,sizeof remainder);
    world_precision_camera_disarm(); /* One arm cannot reach a later RTPS. */
    world_precision_vertex *v=&fifo[2];
    if(!world_camera_enabled || !world_precision_enabled ||
       !generation || generation<=reset_generation || version!=world_precision_code_version ||
       producer!=world_precision_producer_pc || producer!=v->producer_pc ||
       v->projection_id<=reset_generation || v->projection_kind!=WORLD_PROJECTION_NATIVE_Q16 ||
       !mac || !rotation || h<=0 || h>65535)return;
    int64_t transformed[3];
    for(unsigned row=0;row<3;row++) {
        /* Native FLAG validation precedes this call. Keep an independent
         * bound here before multiplying a signed44 accumulator by4096. */
        if(mac[row]<-(INT64_C(1)<<43) || mac[row]>=(INT64_C(1)<<43))return;
        transformed[row]=mac[row]*4096;
        for(unsigned col=0;col<3;col++)
            transformed[row]-=(int64_t)rotation[row*3+col]*remainder[col];
    }
    double z=(double)transformed[2]/16777216.0;
    if(!(z>=1.0/4096.0 && z<65536.0) || h>=2.0*z)return;
    /* RTPS projects saturated IR1/IR2, whereas its divisor uses unsigned
     * SZ3, not saturated IR3. Preserve that continuous coordinate clamp in
     * the camera projection; distant faces must not lose provenance merely
     * because a shared source exceeds the signed16 intermediate range. */
    for(unsigned axis=0;axis<2;axis++) {
        const int64_t low=INT64_C(-32768)*16777216,high=INT64_C(32767)*16777216;
        if(transformed[axis]<low)transformed[axis]=low;
        if(transformed[axis]>high)transformed[axis]=high;
    }
    /* Full transformed XYZ recover both the discarded camera fraction and
     * the earlier IR/SZ truncation. The original native word remains the
     * exact FIFO/packet identity; corrected XY need not occupy its cell. */
    double ratio=(double)h/(double)transformed[2];
    double x=(double)transformed[0]*ratio*(wide?a2_display_wide_scale(output_aspect_width,output_aspect_height):1.0)+(double)ofx/65536.0;
    double y=(double)transformed[1]*ratio+(double)ofy/65536.0;
    if(!isfinite(x) || !isfinite(y) || x< -1024 || x>=1024 || y< -1024 || y>=1024)return;
    v->x=floor(x*65536.0)/65536.0;
    v->y=floor(y*65536.0)/65536.0;
    v->z=z;v->projection_kind=WORLD_PROJECTION_CAMERA;
    v->camera_generation=generation;
}
uint64_t world_precision_begin_object(void) {
    return world_precision_enabled ? next_generation() : 0;
}

void world_precision_invalidate(uint32_t address, size_t bytes) {
    uint32_t p;
    if (!world_precision_enabled || !bytes || !canonical(address,&p)) return;
    if(++world_precision_write_version==0)world_precision_reset();
    if (bytes>=0x200000 || (uint64_t)p+bytes>0x100000000ull) {
        world_precision_reset();
        return;
    }
    /* Low-RAM renderer identity must be rechecked after any possible code
     * write, including identical-value DMA or CPU overwrites. */
    if (p<0x200000 && ((uint64_t)p+bytes>0x200000 ||
        (p<world_precision_code_end &&
         (uint64_t)p+bytes>WORLD_PRECISION_CODE_BEGIN))) world_precision_code_version++;
    uint32_t end=(uint32_t)((uint64_t)p+bytes-1)&~3u;
    for (uint32_t a=p&~3u;;a+=4) {
        uint32_t q=p<0x200000 ? a&0x1fffff : a;
        for(unsigned kind=1;kind<=2;kind++) {
            tag *t=slot(q,kind);
            if (t->address==q) t->kind=0;
        }
        /* Shared banks are4-aligned, not necessarily16-aligned. A write to
         * any byte of a completed record revokes its XY provenance. Check
         * only addresses in the bounded RAM watch span; scratch stays local. */
        if(q<0x200000u && q>=shared_watch_begin && q<shared_watch_end)
            for(unsigned back=4;back<=12 && back<=q;back+=4) {
                uint32_t start=q-back;tag *prior=slot(start,1);
                if(prior->address==start && prior->kind==1 && prior->shared_scope)
                    prior->kind=0;
            }
        if (a==end) break;
    }
}

void world_precision_gte_push(uint32_t word, int64_t x_fp, int64_t y_fp,
                              double depth, int valid) {
    if (!world_precision_enabled) return;
    fifo[0]=fifo[1]; fifo[1]=fifo[2];
    memset(&fifo[2],0,sizeof fifo[2]);
    double x=(double)x_fp/65536.0, y=(double)y_fp/65536.0;
    if (!valid || !isfinite(depth) || depth<=0 || x< -1024 || x>=1024 ||
        y< -1024 || y>=1024 || (int16_t)word!=(int)floor(x) ||
        (int16_t)(word>>16)!=(int)floor(y)) return;
    fifo[2]=(world_precision_vertex){.x=x,.y=y,.z=depth,
        .projection_id=next_generation(),.native_word=word,
        .producer_pc=world_precision_producer_pc};
}
void world_precision_gte_write(int reg) {
    if (!world_precision_enabled) return;
    if(world_camera_enabled)world_precision_camera_disarm();
    if (reg==15) {
        fifo[0]=fifo[1]; fifo[1]=fifo[2];
        memset(&fifo[2],0,sizeof fifo[2]);
    } else if (reg>=12 && reg<=14) memset(&fifo[reg-12],0,sizeof fifo[0]);
}
int world_precision_gte_read(int reg, uint32_t word, world_precision_vertex *out) {
    if (!world_precision_enabled || !out || reg<12 || reg>15) return 0;
    const world_precision_vertex *v=&fifo[reg==15?2:reg-12];
    if (!v->projection_id || v->native_word!=word) return 0;
    *out=*v;
    return 1;
}
void world_precision_record(uint32_t address, uint32_t word,
                            uint64_t object, const world_precision_vertex *value) {
    uint32_t p;
    if (!world_precision_enabled || !canonical(address,&p) || (address&3)) return;
    tag *t=slot(p,1);
    t->kind=0;t->shared_scope=0;
    if (object<=reset_generation || !value || value->projection_id<=reset_generation ||
        value->native_word!=word ||
        (value->projection_kind==WORLD_PROJECTION_CAMERA && value->camera_generation!=object) ||
        value->projection_kind>WORLD_PROJECTION_CAMERA) return;
    t->address=p; t->value=*value; t->kind=1;
    t->value.generation=object;
    t->value.source_address=p;
}
int world_precision_share_record(uint32_t address,uint32_t word,uint64_t object,
                                 uint64_t projection_id,uint64_t scope) {
    tag *t=lookup(address,word,1);
    if(!world_camera_enabled || !scope || !t || t->address>0x200000u-16 ||
       t->value.generation!=object || t->value.projection_id!=projection_id ||
       t->value.camera_generation!=object ||
       t->value.projection_kind!=WORLD_PROJECTION_CAMERA ||
       (t->value.producer_pc!=0x8001338cu && t->value.producer_pc!=0x80013424u))return 0;
    t->shared_scope=scope;
    if(t->address<shared_watch_begin)shared_watch_begin=t->address;
    if(t->address+16>shared_watch_end)shared_watch_end=t->address+16;
    return 1;
}
static int record_value(uint32_t source,uint32_t word,uint64_t object,uint64_t scope,
                        world_precision_vertex *out) {
    tag *t=lookup(source,word,1);
    if(!t || object<=reset_generation)return 0;
    if(t->value.generation!=object) {
        if(!world_camera_enabled || !scope || t->shared_scope!=scope ||
           t->value.projection_kind!=WORLD_PROJECTION_CAMERA ||
           t->value.camera_generation!=t->value.generation ||
           (t->value.producer_pc!=0x8001338cu && t->value.producer_pc!=0x80013424u))return 0;
        *out=t->value;out->camera_generation=object;
    }else *out=t->value;
    return 1;
}
int world_precision_emit_actor(const uint32_t *destinations,const uint32_t *words,
                               const uint32_t *sources,unsigned count,uint64_t object,
                               uint64_t scope) {
    world_precision_vertex values[4];
    uint32_t physical[4];
    if (!world_precision_enabled || !destinations || !words || !sources ||
        (count!=3 && count!=4)) return 0;
    /* Revoke all old XY tags before checking anything: failed rebuilds must
     * not leave a previously valid primitive attached to identical words. */
    for (unsigned i=0;i<count;i++) world_precision_invalidate(destinations[i],4);
    for (unsigned i=0;i<count;i++) {
        if (!record_value(sources[i],words[i],object,scope,&values[i]) ||
            (destinations[i]&3) || !canonical(destinations[i],&physical[i])) return 0;
        if(i && values[i].projection_kind!=values[0].projection_kind)return 0;
        for (unsigned j=0;j<i;j++) if (physical[j]==physical[i]) return 0;
    }
    uint64_t generation=next_generation();
    for (unsigned i=0;i<count;i++) {
        tag *t=slot(physical[i],2);
        t->address=physical[i]; t->kind=2; t->value=values[i];t->shared_scope=0;
        t->value.generation=generation;
    }
    /* A direct-map collision among destinations fails the whole operation. */
    for (unsigned i=0;i<count;i++) if (!lookup(destinations[i],words[i],2)) {
        for (unsigned j=0;j<count;j++) world_precision_invalidate(destinations[j],4);
        return 0;
    }
    return 1;
}
int world_precision_emit(const uint32_t *destinations,const uint32_t *words,
                         const uint32_t *sources,unsigned count,uint64_t object) {
    return world_precision_emit_actor(destinations,words,sources,count,object,0);
}
int world_precision_packet(uint32_t address, uint32_t word,
                           world_precision_vertex *out) {
    tag *t=lookup(address,word,2);
    if (!t || !out) return 0;
    *out=t->value;
    return 1;
}

int world_precision_raster_extent(const uint32_t *words,unsigned count) {
    if(!words || (count!=3 && count!=4))return 0;
    int x[4],y[4];
    for(unsigned i=0;i<count;i++) {
        x[i]=(int16_t)words[i];y[i]=(int16_t)(words[i]>>16);
        if(x[i]<-1024 || x[i]>=1024 || y[i]<-1024 || y[i]>=1024)return 0;
    }
    for(unsigned t=0;t<count-2;t++) {
        int minx=x[t],maxx=x[t],miny=y[t],maxy=y[t];
        for(unsigned i=t+1;i<t+3;i++) {
            if(x[i]<minx)minx=x[i];if(x[i]>maxx)maxx=x[i];
            if(y[i]<miny)miny=y[i];if(y[i]>maxy)maxy=y[i];
        }
        if(maxx-minx>1024 || maxy-miny>512)return 0;
    }
    return 1;
}

int world_precision_frontface_actor(const uint32_t sources[4],const uint32_t words[4],
                                    uint64_t object,unsigned triangle,uint64_t scope,int *front) {
    if(!world_camera_enabled || !sources || !words || !object || triangle>1 || !front)return 0;
    int64_t x[4],y[4];
    for(unsigned i=0;i<4;i++) {
        world_precision_vertex v;
        if(!record_value(sources[i],words[i],object,scope,&v) || v.camera_generation!=object ||
           v.projection_kind!=WORLD_PROJECTION_CAMERA)return 0;
        double fx=v.x*65536,fy=v.y*65536,z=v.z;
        if(!isfinite(fx) || !isfinite(fy) || !isfinite(z) ||
           fx< -1024.0*65536 || fx>=1024.0*65536 ||
           fy< -1024.0*65536 || fy>=1024.0*65536 || z<1.0/4096 || z>=65536)return 0;
        x[i]=(int64_t)fx;y[i]=(int64_t)fy;
        if((double)x[i]!=fx || (double)y[i]!=fy)return 0;
    }
    unsigned b=triangle?2:1,c=triangle?3:2;
    /* Coordinates are bounded Q16. Differences <2^27, so this exact
     * determinant fits int64 and does not flip on floating cancellation. */
    int64_t area=(x[b]-x[0])*(y[c]-y[0])-(y[b]-y[0])*(x[c]-x[0]);
    *front=area>0;
    return 1;
}
int world_precision_frontface(const uint32_t sources[4],const uint32_t words[4],
                              uint64_t object,unsigned triangle,int *front) {
    return world_precision_frontface_actor(sources,words,object,triangle,0,front);
}

static uint32_t trace_lines;
int world_precision_trace_active(uint32_t frame) {
    static int initialized;
    static uint32_t first,last;
    if (!initialized) {
        const char *from=getenv("A2_WORLD_TRACE_FROM"),*to=getenv("A2_WORLD_TRACE_TO");
        first=from?(uint32_t)strtoul(from,NULL,0):UINT32_MAX;
        last=to?(uint32_t)strtoul(to,NULL,0):first+2;
        initialized=1;
    }
    return world_precision_enabled && frame>=first && frame<last && trace_lines<30000;
}
static int trace_allowed(uint32_t frame) {
    if (!world_precision_trace_active(frame)) return 0;
    trace_lines++;
    return 1;
}
void world_precision_trace_primitive(uint32_t frame, uint64_t consumer, int complete,
                                     int draw_x, int draw_y, int disp_x, int disp_y) {
    if (!trace_allowed(frame)) return;
    fprintf(stderr,"world-precision f=%u primitive consumer=%llu complete=%d "
            "draw_x=%d draw_y=%d disp_x=%d disp_y=%d\n",
            frame,(unsigned long long)consumer,complete!=0,draw_x,draw_y,disp_x,disp_y);
}
void world_precision_trace_display(uint32_t frame, int x, int y, int w, int h) {
    if (!trace_allowed(frame)) return;
    fprintf(stderr,"world-precision f=%u display x=%d y=%d w=%d h=%d\n",frame,x,y,w,h);
}
void world_precision_trace_miss(uint32_t frame, const char *stage, uint32_t pc,
                                uint32_t address, uint32_t native_word) {
    if (!trace_allowed(frame)) return;
    fprintf(stderr,"world-precision f=%u %s pc=%08X addr=%08X word=%08X miss\n",
            frame,stage,pc,address,native_word);
}
void world_precision_trace_object(uint32_t frame, uint64_t object, uint64_t code_version,
                                  uint64_t code_hash, int code_valid,
                                  uint32_t context, uint32_t scratch) {
    if (!trace_allowed(frame)) return;
    fprintf(stderr,"world-precision f=%u object pc=80010C34 object=%llu "
        "code_version=%llu code_hash=%016llX code_valid=%d context=%08X scratch=%08X\n",
        frame,(unsigned long long)object,(unsigned long long)code_version,
        (unsigned long long)code_hash,code_valid!=0,context,scratch);
}
void world_precision_trace(uint32_t frame, const char *stage, uint32_t pc,
                           uint32_t address, const world_precision_vertex *value) {
    if (!trace_allowed(frame)) return;
    if (!value) {
        fprintf(stderr,"world-precision f=%u %s pc=%08X addr=%08X miss\n",frame,stage,pc,address);
        return;
    }
    fprintf(stderr,"world-precision f=%u %s pc=%08X addr=%08X src=%08X "
        "word=%08X projection=%llu generation=%llu producer=%08X xy=%.9f,%.9f z=%.9f "
        "kind=%u camera=%llu\n",
        frame,stage,pc,address,value->source_address,value->native_word,
        (unsigned long long)value->projection_id,(unsigned long long)value->generation,
        value->producer_pc,value->x,value->y,value->z,value->projection_kind,
        (unsigned long long)value->camera_generation);
}
