/* Original TA11 vertices/faces through real AL22 MVMVA/RTPS, duplicate
 * stores and packet emitter. Copied source-bound ownership and part poses
 * are synthetic; this is an instruction/lifetime test, not a scene replay. */
#define A2_NATIVE_ACTOR_PACKETS 1
#define main retained_runtime_existing_main
#include "test_world_precision_runtime.c"
#undef main
#include "native_actor_source_layout.h"
static A2ActorFrame shared_snapshot;
const A2ActorFrame *a2_native_actor_snapshot_current(void){return &shared_snapshot;}
static const uint32_t registry=0x80180000,parts=0x801d0000,bank=0x80160004;
static const uint32_t camera_address=0x8011763c,camera_matrix=0x80003000,context=0x800157b0;
static const A2ActorSourceLayout *layout;
static unsigned char blob[4164];
static world_precision_vertex exported[8],local_projected[4];
static void initialize(const uint8_t *base,int sharing,int wide,unsigned pose) {
    a2_native_actor_packets_configure(0);world_precision_configure(1);world_camera_configure(1);
    memset(PSX_RAM,0,sizeof PSX_RAM);memcpy(PSX_RAM+0x10000,base+0x10000,0x57b0);
    memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);memset(R,0,sizeof R);memset(&shared_snapshot,0,sizeof shared_snapshot);
    memset(exported,0,sizeof exported);HI=LO=psx_next=psx_work=0;psx_bb_budget=1000000;
    for(unsigned j=0;j<32;j++){gte_data_write(j,0);gte_ctrl_write(j,0);}
    setup_projection();fixture_wide=wide;wp_local_pose_mode=1;
    memcpy(PSX_RAM+(registry&0x1fffff),blob,sizeof blob);
    A2ActorFrame *s=&shared_snapshot;
    s->valid=1;s->sequence=1;s->build_generation=1;s->guest_frame=50;
    s->draw_object_address=camera_address;s->instance_count=1;s->part_count=7;
    s->projection_h=96;s->projection_ofx=160<<16;s->projection_ofy=124<<16;
    s->camera_origin_q12[0]=1024;s->camera_origin_q12[1]=-2048;s->camera_origin_q12[2]=3072;
    for(unsigned j=0;j<3;j++){
        s->camera_rotation_q12[j*4]=4096;
        sh_(camera_matrix+8*j,4096);sw_(camera_address+0x2c+4*j,(uint32_t)s->camera_origin_q12[j]);
    }
    sw_(camera_address+0x1c,camera_matrix);
    A2ActorInstance *i=&s->instances[0];i->valid=i->generation_known=i->selected_for_draw=1;
    i->instance_generation=77;i->entity_address=0x80140000;i->registry_address=registry;i->part_count=7;
    for(unsigned j=0;j<7;j++){
        uint32_t h=registry+layout->header[j],a=parts+80*j;
        sw_(registry+32+4*j,h);sw_(h+20,registry+layout->face_end[j]);
        sh_(a,0x2000);sh_(a+2,j);sw_(a+8,100);sw_(a+12,100);sw_(a+16,600);
        sw_(a+60,registry);sw_(a+72,bank);
        /* Shared corners must retain the producer's transform even when
         * adjacent parts move independently. These poses are synthetic. */
        static const int16_t rotations[][9]={
            {2896,0,2896,0,4096,0,-2896,0,2896},
            {4096,0,0,0,2896,-2896,0,2896,2896},
            {2896,-2896,0,2896,2896,0,0,0,4096},
            {2896,0,-2896,0,4096,0,2896,0,2896}
        };
        const int16_t *rotation=rotations[pose?(pose+j)%4:0];
        if(pose){
            sw_(a+8,(uint32_t)(100+((int)j-3)*(int)pose*7));
            sw_(a+12,(uint32_t)(100+((int)j-4)*(int)pose*3));
            sw_(a+16,600+j*pose*5);
        }
        for(unsigned k=0;k<9;k++)sh_(a+32+2*k,(uint16_t)rotation[k]);
        A2ActorPart *p=&s->parts[j];p->address=a;p->registry_address=registry;p->source_mesh_index=j;
        p->flags=0x2000;p->valid=p->visible=1;p->source_generation=91;
        strcpy(p->source_key,layout->key);memcpy(p->source_sha256,layout->hash,32);
        memcpy(p->raw,PSX_RAM+(a&0x1fffff),80);memcpy(p->matrix_q12,rotation,sizeof p->matrix_q12);
        memcpy(p->translation0,p->raw+8,12);
    }
    a2_native_actor_packets_init(PSX_RAM,sizeof PSX_RAM);a2_native_actor_packets_configure(sharing);
    R[4]=camera_address;R[29]=0x80007000;
    for(uint32_t pc=0x80012e68;pc<=0x80012f0c;pc+=4)exec1(pc,fetch(pc));
    R[4]=context;R[5]=0x1f800000;
    sw_(context+0x64,0x80110000);sw_(context+0x5cc,0);sw_(context+0x5f8,0);
    sh_(R[5]+0x3d0,0xffff);sh_(R[5]+0x3d2,0);
}
static void project_part(unsigned part,unsigned fault) {
    R[4]=context;R[5]=0x1f800000;R[30]=parts+part*80;R[3]=registry+layout->header[part];
    sw_(context+0x70,R[30]);
    /* All selected parts have flags2000: the native override/shadow branches
     * are untaken; below retains each real branch delay instruction. */
    for(uint32_t pc=0x80013194;pc<0x800132b0;pc+=4){
        if(pc==0x800131f8 || pc==0x80013264)continue;
        exec1(pc,fetch(pc));
    }
    assert(R[24]==4);
    for(unsigned vertex=0;vertex<4;vertex++){
        uint32_t source=R[2],destination=R[6];unsigned slot=lb_(source+12);
        for(uint32_t pc=0x800132b4;pc<=0x80013428;pc+=4){
            if(pc==0x8001330c || pc==0x80013314 || pc==0x80013330 ||
               pc==0x8001339c || pc==0x80013414 || pc==0x80013424)continue;
            if(!slot && ((pc>=0x80013338 && pc<=0x80013340) ||
                         (pc>=0x800133a4 && pc<=0x800133ac) || pc>=0x8001341c))continue;
            if(part==3 && vertex==1){
                unsigned reg=fault==12?26:fault==13?24:25;
                if(pc==0x8001338c && fault>=12 && fault<=14)gte_ctrl_write(reg,fault==12?48:0);
                if(pc==0x80013390 && fault>=12 && fault<=14)gte_ctrl_write(reg,fault==12?96:(fault==13?160:124)<<16);
                if((pc==0x8001338c || pc==0x80013390) && fault==15)fixture_wide=!fixture_wide;
            }
            if(part==2 && vertex==1){
                if(pc==0x8001338c && fault==1)gte_ctrl_write(26,48);
                if(pc==0x8001338c && fault==2)gte_ctrl_write(24,(159<<16)+1);
                if(pc==0x8001338c && fault==16)gte_ctrl_write(25,123<<16);
                if(pc==0x8001338c && fault==3)fixture_wide=!fixture_wide;
                if(pc==0x80013390 && fault==1)gte_ctrl_write(26,96);
                if(pc==0x80013390 && fault==2)gte_ctrl_write(24,160<<16);
                if(pc==0x80013390 && fault==16)gte_ctrl_write(25,124<<16);
                if(pc==0x80013390 && fault==3)fixture_wide=!fixture_wide;
                if(pc==0x80013420 && fault==4)sh_(R[22]+8,lh_(R[22]+8));
                if(pc==0x80013428 && fault==5)sh_(R[22]+14,lh_(R[22]+14));
                if(pc==0x80013420 && fault==6)continue;
                if(pc==0x80013428 && fault==7)continue;
                if(pc==0x80013428 && fault==8)exec1(0x80013420,fetch(0x80013420));
                if(pc==0x80013420 && fault==9)sw_(0x80050000,0);
                if(pc==0x80013428 && fault==10)world_precision_reset();
                if(pc==0x80013428 && fault==11){
                    world_precision_vertex v;assert(world_precision_gte_read(14,R[19],&v));
                    world_precision_gte_push(v.native_word,((int64_t)(int16_t)v.native_word*65536)+16384,((int64_t)(int16_t)(v.native_word>>16)*65536)+16384,v.z,1);
                    assert(world_precision_gte_read(14,R[19],&v));v.projection_kind=WORLD_PROJECTION_CAMERA;v.camera_generation=wp_object;
                    world_precision_record(R[22],R[19],wp_object,&v);
                }
            }
            exec1(pc,fetch(pc));
        }
        (void)world_precision_gte_read(14,lw_(destination),&local_projected[vertex]);
        if(slot>=60 && slot<68){
            assert(lw_(bank+16*(slot-60))==lw_(destination));
            (void)world_precision_gte_read(14,lw_(destination),&exported[slot-60]);
        }
    }
}
/* The retained branch consumes native NCLIP's boolean. Exercise its source
 * and camera gate on original TA11 faces, including an opposite native sign
 * to prove this is a precision decision rather than an unchanged fallback. */
static void cull_part(unsigned part,int admitted) {
    uint32_t face=registry+layout->header[part]+24,sources[4],words[4];
    int64_t x[4],y[4];
    R[3]=face;world_precision_raster_scale=4;wp_precise_cull_mode=2;
    for(unsigned j=0;j<4;j++){
        unsigned index=lb_(face+4+j);
        sources[j]=index<60?0x1f800000+16*index:bank+16*(index-60);words[j]=lw_(sources[j]);
        R[8+j]=sources[j];R[16+2*j]=words[j];
        const world_precision_vertex *v=index<60?&local_projected[index]:&exported[index-60];
        x[j]=(int64_t)(v->x*65536);y[j]=(int64_t)(v->y*65536);
    }
    for(unsigned triangle=0;triangle<2;triangle++){
        unsigned b=triangle?2:1,c=triangle?3:2;
        int front=(x[b]-x[0])*(y[c]-y[0])-(y[b]-y[0])*(x[c]-x[0])>0;
        uint32_t pc=triangle?0x8001357cu:0x8001354cu;
        /* Preserve actual guest registers through the observer call. */
        R[1]=front?(uint32_t)-1:1;
        uint32_t before[32];memcpy(before,R,sizeof before);
        int observed=wp_precise_cull_condition(pc,fetch(pc),!front);
        assert(observed==(admitted?front:!front));assert(!memcmp(before,R,sizeof before));
    }
}
static unsigned emit_part(unsigned part,int wanted) {
    uint32_t face=registry+layout->header[part]+24,mat=face+8;
    unsigned command=lw_(mat)>>24,count=command&8?4:3,stride=command&4?12:8;
    assert(count==4 && !(lh_(face)&4));
    uint32_t sources[4];
    for(unsigned j=0;j<4;j++){
        unsigned index=lb_(face+4+j);sources[j]=index<60?0x1f800000+16*index:bank+16*(index-60);
        uint32_t xy=lw_(sources[j]);R[16+j*2]=(uint32_t)(int32_t)(int16_t)xy;
        R[17+j*2]=(uint32_t)(int32_t)(int16_t)(xy>>16);
        sw_(R[5]+0x3b8+j*4,sources[j]);sw_(R[5]+0x3a8+j*4,lw_(sources[j]+4));
        R[8+j]=lw_(mat+4*j);
    }
    R[14]=lw_(mat+16);R[15]=lw_(mat+20);R[24]=lw_(mat+24);
    R[12]=R[15]>>16;R[13]=R[14]>>16;R[25]=R[24]>>16;
    R[1]=lw_(mat+28);R[2]=0x80060000+part*80;R[3]=face;R[7]=0x80008000;R[30]=0;R[31]=0x80013754;
    psx_interp(0x80013cb8);
    const unsigned order[]={0,1,3,2};unsigned complete=0;
    for(unsigned j=0;j<4;j++){
        uint32_t address=0x8006000c+part*80+j*stride;world_precision_vertex v;
        int valid=world_precision_packet(address,lw_(address),&v);assert(valid==wanted);complete+=valid;
        if(!valid)continue;
        assert(v.camera_generation==wp_object && v.projection_kind==WORLD_PROJECTION_CAMERA);
        assert(v.source_address==(sources[order[j]]&0x1fffffff));
        unsigned index=lb_(face+4+order[j]);
        if(index>=60){
            const world_precision_vertex *original=&exported[index-60];
            assert(v.x==original->x && v.y==original->y && v.z==original->z && v.projection_id==original->projection_id);
        }
    }
    return complete;
}
#ifndef A2_SHARED_RUNTIME_MAIN
#define A2_SHARED_RUNTIME_MAIN main
#endif
int A2_SHARED_RUNTIME_MAIN(int argc,char **argv){
    if(argc!=3){puts("SKIP: retained AL22 RAM fixture required");return 77;}static uint8_t base[PSX_RAM_SIZE];FILE *f=fopen(argv[1],"rb");assert(f);
    assert(fread(base,1,sizeof base,f)==sizeof base);fclose(f);f=fopen(argv[2],"rb");assert(f);
    assert(fread(blob,1,sizeof blob,f)==sizeof blob && fgetc(f)==EOF);fclose(f);
    unsigned n=a2_actor_source_lower_bound("TA11");assert(n<A2_ACTOR_SOURCE_COUNT);layout=&a2_actor_source_layouts[n];
    assert(!strcmp(layout->key,"TA11") && layout->bytes==sizeof blob);
    static uint8_t native_ram[PSX_RAM_SIZE],native_scratch[0x400];
    uint32_t native_regs[32],native_gte[64],native_state[5];
    for(unsigned pose=0;pose<4;pose++)for(unsigned wide=0;wide<2;wide++)for(unsigned sharing=0;sharing<2;sharing++){
        initialize(base,sharing,wide,pose);
        if(pose)for(unsigned part=3;part<7;part++){
            const A2ActorPart *a=&shared_snapshot.parts[part-1],*b=&shared_snapshot.parts[part];
            assert(memcmp(a->matrix_q12,b->matrix_q12,sizeof a->matrix_q12));
            assert(memcmp(a->translation0,b->translation0,sizeof a->translation0));
        }
        for(unsigned part=2;part<7;part++){
            project_part(part,0);cull_part(part,part==2 || sharing);emit_part(part,part==2 || sharing);
        }
        if(!sharing){
            memcpy(native_ram,PSX_RAM,sizeof native_ram);memcpy(native_scratch,PSX_SCRATCH,sizeof native_scratch);
            memcpy(native_regs,R,sizeof R);
            for(unsigned j=0;j<64;j++)native_gte[j]=j<32?gte_data_read(j):gte_ctrl_read(j-32);
            native_state[0]=HI;native_state[1]=LO;native_state[2]=psx_next;native_state[3]=psx_work;native_state[4]=psx_bb_budget;
        }else{
            assert(!memcmp(native_ram,PSX_RAM,sizeof native_ram) && !memcmp(native_scratch,PSX_SCRATCH,sizeof native_scratch));
            assert(!memcmp(native_regs,R,sizeof R));
            for(unsigned j=0;j<64;j++)assert(native_gte[j]==(j<32?gte_data_read(j):gte_ctrl_read(j-32)));
            assert(native_state[0]==HI && native_state[1]==LO && native_state[2]==psx_next &&
                   native_state[3]==psx_work && native_state[4]==(uint32_t)psx_bb_budget);
        }
    }
    for(unsigned fault=1;fault<=16;fault++){
        initialize(base,1,0,0);project_part(2,fault);project_part(3,fault);cull_part(3,0);emit_part(3,0);
    }
    for(unsigned fault=0;fault<8;fault++){
        initialize(base,1,0,0);project_part(2,0);project_part(3,0);
        uint32_t address=fault==0?registry+100:fault==1?parts+80*2+8:
                         fault==2?shared_snapshot.instances[0].entity_address:bank+16*5+14;
        if(fault<4)sb_(address,lb_(address));
        if(fault==4)a2_native_actor_packets_before(0x800130c0,R); /* sealed owners cannot lend during construction */
        if(fault==5){shared_snapshot.sequence++;R[4]=camera_address;
            a2_native_actor_packets_before(0x80012e68,R);project_part(3,0);}
        if(fault==6)a2_native_actor_packets_reset();
        if(fault==7){sw_(context+0x70,0x1f801000);}
        emit_part(3,0);
    }
    puts("TA11 shared source: four cross-part faces, four synthetic poses including distinct adjacent transforms, two wide modes, exact native state,16 projection/completion faults and8 owner/source lifetime faults pass");return 0;
}
