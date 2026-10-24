/* Real retained position MVMVA, normal MVMVA and actor RTPS. A fractional
 * position must reach the host projection without changing guest state. */
#define main retained_runtime_existing_main
#include "test_world_precision_runtime.c"
#undef main

static world_precision_vertex local_case(const uint8_t *base,int enabled,int fault,int variant) {
    static uint8_t native_ram[PSX_RAM_SIZE],native_scratch[0x400];
    static uint32_t native_regs[32],native_gte[64];
    static world_precision_vertex baseline;
    memcpy(PSX_RAM,base,PSX_RAM_SIZE);memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);memset(R,0,sizeof R);
    world_precision_configure(1);world_camera_configure(1);setup_projection();
#ifdef A2_LOCAL_POSE_IMPLEMENTED
    wp_local_pose_mode=enabled;
#else
    (void)enabled;
#endif
    const uint32_t camera=0x80002000,matrix=0x80003000,part=0x80004000;
    const uint32_t registry=0x80009000,header=0x8000a000,vertex=0x8000b000,context=0x800157b0;
    memset(PSX_RAM+0x2000,0,0x40);memset(PSX_RAM+0x3000,0,20);memset(PSX_RAM+0x4000,0,80);
    sh_(matrix,4096);sh_(matrix+8,4096);sh_(matrix+16,4096);sw_(camera+0x1c,matrix);
    if(variant==1) {
        /* Quarter-turn camera and signed camera fractions, combined with a
         * non-diagonal local rotation below. */
        sh_(matrix,0);sh_(matrix+2,(uint16_t)-4096);sh_(matrix+6,4096);sh_(matrix+8,0);
        sw_(camera+0x2c,1024);sw_(camera+0x30,(uint32_t)-2048);sw_(camera+0x34,3072);
    }
    R[4]=camera;R[29]=0x80007000;
    for(uint32_t pc=0x80012e68;pc<=0x80012f0c;pc+=4)exec1(pc,fetch(pc));
    sw_(part+8,100);sw_(part+12,100);sw_(part+16,600);sw_(part+60,registry);
    for(int i=0;i<9;i++)sh_(part+32+i*2,i%4==0?2048:0);
    sw_(registry+32,header);sh_(header+16,1);sw_(header+20,vertex);
    sh_(vertex,1);sh_(vertex+2,(uint16_t)-1);sh_(vertex+4,1);
    if(variant==1) {
        const int16_t rotated[9]={2896,-2896,0,2896,2896,0,0,0,4096};
        for(unsigned i=0;i<9;i++)sh_(part+32+i*2,(uint16_t)rotated[i]);
        sh_(vertex+2,2);sh_(vertex+4,(uint16_t)-3);
    }
    if(variant==2) {sh_(part,0x1000);sw_(part+4,vertex);sw_(header+20,0);}
    /* Deliberately different normal: its intervening MVMVA must not supply
     * the positional remainder. Zero duplication byte takes the direct path. */
    sh_(vertex+6,23);sw_(vertex+8,pack(17,-19));sb_(vertex+12,0);
    R[4]=context;R[5]=0x1f800000;R[30]=part;R[3]=header;sw_(context+0x5cc,0);
    for(uint32_t pc=0x80013194;pc<=0x8001338c;pc+=4) {
        /* Execute exactly the untaken/taken branches for flags=0 and
         * duplication=0, with every real delay slot retained. */
        if(pc==0x800131f8 || pc==0x80013264 || pc==0x800132b0 ||
           pc==0x8001330c || pc==0x80013314 || pc==0x80013330 ||
           (pc>=0x80013338&&pc<=0x80013340))continue;
        if(variant==2 && (pc==0x80013200 || pc==0x80013204))continue;
        if(pc==0x80013350) {
            if(fault==9)sh_(vertex,0);             /* Same rounded position, different remainder. */
            if(fault==1)sh_(vertex,3);             /* Source changed since MVMVA. */
            if(fault==2)sh_(part+32,2047);         /* Source matrix changed. */
            if(fault==3)R[2]++;                   /* Unaligned source. */
            if(fault==4)sh_(header+16,0);          /* No source vertex exists. */
            if(fault==5)R[8]+=65536;              /* Same int16, unsafe packing. */
            if(fault==7)sw_(context+0x5cc,0x100);  /* Flattened path unsupported. */
        }
        if(pc==0x8001338c && fault==10)sh_(vertex,0); /* Changed after the packing check. */
        if(pc==0x8001338c && fault==6)R[2]+=16;    /* Cannot lend to another source. */
        if(pc==0x8001338c && fault==8)exec1(0x80013304,fetch(0x80013304));
        exec1(pc,fetch(pc));
    }
    world_precision_vertex value;
    assert(world_precision_gte_read(14,gte_data_read(14),&value));
    if(!fault)assert(value.projection_kind==WORLD_PROJECTION_CAMERA);
    if(enabled && !fault && variant!=1) {
        /* Exact camera XYZ=(100.5,99.5,600.5), H96, offset(160,124). */
        assert(value.x*65536==11538701);
        assert(value.y*65536==9168928);
        assert(value.z==600.5);
    }
    if(enabled && !fault && variant==1) {
        /* Independent exact rational result: camera XYZ equals
         * (-26271/256,25355/256,2385/4). */
        assert(value.x*65536==9402932);assert(value.y*65536==9171536);
        assert(value.z==596.25);
    }
    if(!enabled)baseline=value;
    else if(fault)assert(value.x==baseline.x && value.y==baseline.y && value.z==baseline.z && value.projection_kind==baseline.projection_kind);
    for(int i=0;i<64;i++) {
        uint32_t v=i<32?gte_data_read(i):gte_ctrl_read(i-32);
        if(!enabled)native_gte[i]=v;else assert(v==native_gte[i]);
    }
    if(!enabled) {
        memcpy(native_ram,PSX_RAM,sizeof native_ram);memcpy(native_scratch,PSX_SCRATCH,sizeof native_scratch);memcpy(native_regs,R,sizeof native_regs);
    } else {
        assert(!memcmp(native_ram,PSX_RAM,sizeof native_ram));assert(!memcmp(native_scratch,PSX_SCRATCH,sizeof native_scratch));assert(!memcmp(native_regs,R,sizeof native_regs));
    }
    return value;
}
int main(int argc,char **argv) {
    if(argc!=2){puts("SKIP: retained game RAM fixture required");return 77;}FILE *f=fopen(argv[1],"rb");assert(f);static uint8_t base[PSX_RAM_SIZE];
    assert(fread(base,1,sizeof base,f)==sizeof base);fclose(f);
    for(int fault=0;fault<=10;fault++){local_case(base,0,fault,0);local_case(base,1,fault,0);}
    for(int variant=1;variant<=2;variant++){local_case(base,0,0,variant);local_case(base,1,0,variant);}
    puts("PASS: retained local/normal MVMVA to RTPS fractional pose, exact signed rational projection and identical native RAM/scratch/GPR/GTE");
    return 0;
}
