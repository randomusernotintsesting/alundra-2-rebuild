/* Replay a validated complete OT workload with restored per-packet provenance.
 * Preparation and exact-address restoration are outside renderer timings.
 * cc -O3 -UNDEBUG -Iport/src port/tests/diagnose_world_capture.c -lm -o /tmp/a2-world-capture
 * /tmp/a2-world-capture RAM VRAM WORKLOAD off|q16|perspective IR FILTER ITERATIONS [FINE.ppm]
 * ITERATIONS=0 validates/restores tags only; it does not render or benchmark.
 * This intentionally excludes optional HD/HUD/cinema modules: it measures
 * CPU geometry/texture raster workload, not complete production frame time.
 * Post-frame VRAM is not a historical pre-render texture/frame snapshot.
 */
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define A2_WORLD_PRECISION 1
#define fifo capture_gte_fifo
#include "../src/world_precision.c"
#undef fifo
#include "../src/gpu.c"

uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
uint32_t psx_frame_no,gpu_flips,a2_ramwatch;
void psx_vblank_tick(void) {}
uint32_t psx_mmio_read(uint32_t p,int n) {(void)p;(void)n;return 0;}
void psx_mmio_write(uint32_t p,uint32_t v,int n) {(void)p;(void)v;(void)n;abort();}
void a2_ramwatch_hit(uint32_t p,uint32_t v,int n) {(void)p;(void)v;(void)n;}
int a2_modelcap_active(void) {return 0;}
FILE *a2_modelcap_file(void) {return NULL;}

typedef struct {
    uint32_t address,word,node;
    world_precision_vertex vertex;
} CaptureWord;
static uint16_t capture_seed[1024*512],capture_reference[1024*512];
static CaptureWord *capture_words;
static uint32_t capture_count,capture_polygons,capture_complete;
static uint64_t capture_ram_hash;
static unsigned capture_tags;

static uint64_t capture_hash(const void *pointer,size_t count) {
    const uint8_t *p=pointer;
    uint64_t value=UINT64_C(14695981039346656037);
    for(size_t i=0;i<count;i++)value=(value^p[i])*UINT64_C(1099511628211);
    return value;
}
static double capture_clock(clockid_t clock) {
    struct timespec value;assert(clock_gettime(clock,&value)==0);
    return value.tv_sec+value.tv_nsec*1e-9;
}
static uint64_t capture_integer(FILE *file,unsigned bytes) {
    uint64_t value=0;
    for(unsigned i=0;i<bytes;i++) {int c=fgetc(file);assert(c!=EOF);value|=(uint64_t)c<<(8*i);}
    return value;
}
static void capture_read_exact(const char *path,void *destination,size_t size) {
    FILE *file=fopen(path,"rb");assert(file);
    assert(fread(destination,1,size,file)==size);assert(fgetc(file)==EOF);assert(!fclose(file));
}
static void capture_load(const char *path) {
    FILE *file=fopen(path,"rb");assert(file);char magic[8];
    assert(fread(magic,1,8,file)==8);
    int camera_format=!memcmp(magic,"A2OTC24\n",8);
    assert(camera_format || !memcmp(magic,"A2OTQ16\n",8));
    capture_count=(uint32_t)capture_integer(file,4);
    capture_ram_hash=capture_integer(file,8);
    capture_polygons=(uint32_t)capture_integer(file,4);
    capture_complete=(uint32_t)capture_integer(file,4);
    assert(capture_count&&capture_count<1000000&&capture_complete<=capture_polygons);
    assert(capture_ram_hash==capture_hash(PSX_RAM,sizeof PSX_RAM));
    assert(capture_hash(PSX_RAM+WORLD_PRECISION_CODE_BEGIN,
                        WORLD_PRECISION_CODE_END-WORLD_PRECISION_CODE_BEGIN)==WORLD_PRECISION_CODE_HASH);
    capture_words=calloc(capture_count,sizeof *capture_words);assert(capture_words);
    for(unsigned i=0;i<capture_count;i++) {
        CaptureWord *word=&capture_words[i];
        word->address=(uint32_t)capture_integer(file,4);
        word->word=(uint32_t)capture_integer(file,4);
        word->node=(uint32_t)capture_integer(file,4);
        /* Bit-copy signed and floating fields, keeping the file format
         * independent of struct packing and host integer conversion rules. */
        uint64_t bits=capture_integer(file,8);int64_t qx;memcpy(&qx,&bits,8);
        bits=capture_integer(file,8);int64_t qy;memcpy(&qy,&bits,8);
        bits=capture_integer(file,8);memcpy(&word->vertex.z,&bits,8);
        word->vertex.projection_id=capture_integer(file,8);
        word->vertex.generation=capture_integer(file,8);
        word->vertex.producer_pc=(uint32_t)capture_integer(file,4);
        word->vertex.source_address=(uint32_t)capture_integer(file,4);
        if(camera_format) {
            word->vertex.projection_kind=(unsigned)capture_integer(file,4);
            word->vertex.camera_generation=capture_integer(file,8);
        }
        word->vertex.native_word=word->word;
        assert(!(word->address&3)&&word->address<=PSX_RAM_SIZE-4);
        assert(!(word->node&3)&&word->node<=PSX_RAM_SIZE-4);
        assert(lw_(word->address)==word->word);
        unsigned node_count=lw_(word->node)>>24;
        assert(word->address>word->node&&word->address<=word->node+4*node_count);
        if(word->vertex.generation) {
            assert(word->vertex.projection_id&&isfinite(word->vertex.z)&&word->vertex.z>0);
            assert(qx>=-1024LL*65536&&qx<1024LL*65536&&qy>=-1024LL*65536&&qy<1024LL*65536);
            word->vertex.x=(double)qx/65536;word->vertex.y=(double)qy/65536;
            if(word->vertex.projection_kind==WORLD_PROJECTION_CAMERA) {
                assert(word->vertex.camera_generation &&
                       word->vertex.camera_generation<word->vertex.projection_id &&
                       word->vertex.projection_id<word->vertex.generation);
                assert(word->vertex.z>=1.0/4096.0&&word->vertex.z<65536.0);
            } else {
                assert(word->vertex.projection_kind==WORLD_PROJECTION_NATIVE_Q16 &&
                       !word->vertex.camera_generation);
                assert((int)floor(word->vertex.x)==(int16_t)word->word);
                assert((int)floor(word->vertex.y)==(int16_t)(word->word>>16));
            }
            assert(word->vertex.producer_pc==0x80010d4c||word->vertex.producer_pc==0x8001338c);
            uint32_t source;assert(canonical(word->vertex.source_address,&source));
            assert(source==word->vertex.source_address);
            capture_tags++;
        } else assert(!word->vertex.projection_id&&!qx&&!qy&&!word->vertex.z&&
                      !word->vertex.projection_kind&&!word->vertex.camera_generation);
    }
    assert(fgetc(file)==EOF);assert(!fclose(file));
}

static void capture_restore_tags(void) {
    world_precision_configure(1);
    /* Diagnostic-only exact cache restoration. The preparer has already
     * proved each original generation and its complete live source chain.
     * Public emit would allocate new generations and require replaying GTE;
     * this restores the captured kind-2 cache values verbatim instead. */
    for(unsigned i=0;i<capture_count;i++) {
        const CaptureWord *word=&capture_words[i];
        if(!word->vertex.generation)continue;
        tag *entry=slot(word->address);
        assert(!entry->kind||entry->address==word->address);
        entry->address=word->address;entry->kind=2;entry->value=word->vertex;
    }
    for(unsigned i=0;i<capture_count;i++) {
        const CaptureWord *word=&capture_words[i];
        if(!word->vertex.generation)continue;
        world_precision_vertex restored;
        assert(world_precision_packet(word->address,word->word,&restored));
        assert(restored.generation==word->vertex.generation&&restored.projection_id==word->vertex.projection_id);
    }
}

static void capture_reset(int scale,int raster) {
    gpu_gp1(0);gpu_set_world_raster(raster);
    memcpy(GPU_VRAM,capture_seed,sizeof capture_seed);
    if(scale>1)memset(SHADOW,0,(size_t)IR_W*IR_H*2);
    capture_restore_tags();
}
static void capture_replay(void) {
    unsigned polygons=0,complete=0;
    for(unsigned i=0;i<capture_count;i++) {
        const CaptureWord *word=&capture_words[i];
        uint64_t before=world_consumer_sequence;
        gpu_ll_node=word->node;gpu_gp0_at(word->word,word->address);
        if(world_consumer_sequence!=before) {polygons++;complete+=world_primitive_valid!=0;}
    }
    assert(!fifo_n&&!in_polyline&&!in_vram_write);
    assert(polygons==capture_polygons&&complete==capture_complete);
}
static void capture_ppm(const char *path,int scale) {
    FILE *file=fopen(path,"wbx");assert(file);
    /* Raw entire VRAM atlas, not an inferred displayed frame/crop. */
    fprintf(file,"P6\n%d %d\n255\n",1024*scale,512*scale);
    for(int y=0;y<512*scale;y++)for(int x=0;x<1024*scale;x++) {
        uint16_t p=scale>1?SHADOW[y*IR_W+x]:GPU_VRAM[y*1024+x];
        unsigned char rgb[3];
        for(int channel=0;channel<3;channel++) {unsigned v=(p>>(channel*5))&31;rgb[channel]=(unsigned char)((v<<3)|(v>>2));}
        assert(fwrite(rgb,1,3,file)==3);
    }
    assert(!fclose(file));
}
int main(int argc,char **argv) {
    assert(argc==8||argc==9);
    const char *mode=argv[4];
    assert(!strcmp(mode,"off")||!strcmp(mode,"q16")||!strcmp(mode,"perspective"));
    int scale=atoi(argv[5]),filter=atoi(argv[6]),iterations=atoi(argv[7]);
    assert(scale>=1&&scale<=4&&(filter==0||filter==1)&&iterations>=0&&iterations<=30);
    assert(!setenv("A2_WORLD_PERSPECTIVE",!strcmp(mode,"perspective")?"1":"0",1));
    /* Do not inherit trace/debug logging into a CPU measurement. */
    assert(!unsetenv("A2_WORLD_TRACE_FROM"));assert(!unsetenv("A2_WORLD_TRACE_TO"));
    capture_read_exact(argv[1],PSX_RAM,sizeof PSX_RAM);
    capture_read_exact(argv[2],capture_seed,sizeof capture_seed);
    capture_load(argv[3]);capture_restore_tags();
    if(!iterations) {
        printf("{\"validated\":true,\"words\":%u,\"polygons\":%u,\"complete\":%u,\"seeded_words\":%u}\n",
               capture_count,capture_polygons,capture_complete,capture_tags);
        free(capture_words);return 0;
    }
    gpu_set_ir(scale);assert(gpu_ir()==scale);gpu_set_filter(filter);
    capture_reset(scale,0);capture_replay();
    memcpy(capture_reference,GPU_VRAM,sizeof capture_reference);
    uint64_t reference=capture_hash(GPU_VRAM,sizeof GPU_VRAM),native=0,fine=0;
    double cpu_total=0,wall_total=0;
    for(int iteration=0;iteration<iterations;iteration++) {
        capture_reset(scale,strcmp(mode,"off")!=0);
        double wall=capture_clock(CLOCK_MONOTONIC),cpu=capture_clock(CLOCK_PROCESS_CPUTIME_ID);
        capture_replay();
        cpu_total+=capture_clock(CLOCK_PROCESS_CPUTIME_ID)-cpu;
        wall_total+=capture_clock(CLOCK_MONOTONIC)-wall;
        assert(!memcmp(GPU_VRAM,capture_reference,sizeof capture_reference));
        assert(capture_hash(PSX_RAM,sizeof PSX_RAM)==capture_ram_hash);
        uint64_t hn=capture_hash(GPU_VRAM,sizeof GPU_VRAM);
        uint64_t hf=scale>1?capture_hash(SHADOW,(size_t)IR_W*IR_H*2):hn;
        if(iteration)assert(hn==native&&hf==fine);
        native=hn;fine=hf;
    }
    if(argc==9)capture_ppm(argv[8],scale);
    printf("{\"mode\":\"%s\",\"ir\":%d,\"filter\":%d,\"iterations\":%d,\"words\":%u,"
           "\"polygons\":%u,\"complete\":%u,\"cpu_mean_ms\":%.6f,\"wall_mean_ms\":%.6f,"
           "\"native_fnv64\":\"%016" PRIx64 "\",\"fine_fnv64\":\"%016" PRIx64 "\","
           "\"affine_native_fnv64\":\"%016" PRIx64 "\",\"ram_unchanged\":true}\n",
           mode,scale,filter,iterations,capture_count,capture_polygons,capture_complete,
           cpu_total*1000/iterations,wall_total*1000/iterations,native,fine,reference);
    gpu_set_ir(1);free(capture_words);return 0;
}
