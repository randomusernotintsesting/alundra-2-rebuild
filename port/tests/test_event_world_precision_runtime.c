/* EVENT world/actor camera arithmetic through actual AL22 setup, packing
 * and RTPS instructions. Controlled position inputs isolate lost camera
 * fractions; this is not a full entity animation or packet-emission replay.
 * Catch: rejecting EVENT identity/sites, accepting stale source/code, or
 * changing guest arithmetic while attaching host precision provenance. */
#define main game_precision_fixture_main
#include "test_world_precision_runtime.c"
#undef main

static world_precision_vertex event_camera_case(const uint8_t *base,int actor,
                                                       int32_t camera_x,int fault,int enabled) {
    static uint8_t native_ram[PSX_RAM_SIZE],native_scratch[0x400];
    static uint32_t native_registers[32],native_gte[64];
    memcpy(PSX_RAM,base,PSX_RAM_SIZE);memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);
    memset(R,0,sizeof R);world_precision_configure(1);world_camera_configure(enabled);
    setup_projection();fixture_wide=0;
    const uint32_t object=0x80002000,matrix=0x80003000,context=0x80015ea0;
    memset(PSX_RAM+0x2000,0,0x100);memset(PSX_RAM+0x3000,0,20);
    sh_(matrix,4096);sh_(matrix+8,4096);sh_(matrix+16,4096);
    if(fault==16)sw_(matrix+16,0x1234f000); /* NegativeR33, nonzero unused padding. */
    sw_(object+0x1c,matrix);sw_(object+0x2c,(uint32_t)camera_x);
    R[4]=object;R[29]=0x80007000;
    uint32_t begin=actor?0x80012ef8:0x800100a8;
    uint32_t last=actor?0x80012f9c:0x80010170;
    for(uint32_t pc=begin;pc<=last;pc+=4)exec1(pc,fetch(pc));
    R[4]=context;R[5]=0x1f800000;R[30]=0x80004000;
    sw_(context+0x5cc,0);
    exec1(actor?0x8001322c:0x80010c3c,fetch(actor?0x8001322c:0x80010c3c));
    if(fault==17 || fault==18) {
        /* Refresh the camera setup while a previous object generation is
         * still current. Only the real following object entry may reuse it. */
        R[4]=object;
        for(uint32_t pc=begin;pc<=last;pc+=4)exec1(pc,fetch(pc));
        R[4]=context;R[5]=0x1f800000;R[30]=0x80004000;
        if(fault==18)exec1(actor?0x8001322c:0x80010c3c,fetch(actor?0x8001322c:0x80010c3c));
    }
    int32_t whole=camera_x/4096-(camera_x<0 && camera_x%4096!=0);
    R[8]=(uint32_t)(100-whole);R[9]=100;R[10]=600;
    if(fault==16)R[10]=(uint32_t)-600;
    R[2]=0x80004000;R[6]=0x1f800000;
    for(unsigned i=0;i<5;i++)R[11+i]=lw_(matrix+i*4);
    if(!actor)for(uint32_t pc=0x80010d10;pc<=0x80010d20;pc+=4)exec1(pc,fetch(pc));
    switch(fault) {
    case 1:sw_(object+0x2c,(uint32_t)camera_x-1);break; /* Fraction changes within same integer cell. */
    case 2:sw_(context+4,1);break;
    case 3:sw_(context+0x68,object+4);break;
    case 4:sw_(matrix,lw_(matrix)^1);break;
    case 5:R[8]=32768;break; /* X would silently truncate into int16. */
    case 6:R[10]=65536+600;break; /* Z wraps to the same plausible native600. */
    case 7:sw_(context+0x5cc,0x100);break;
    case 8:exec1(actor?0x80010c3c:0x8001322c,fetch(actor?0x80010c3c:0x8001322c));break;
    case 9:sw_(0x80010000,lw_(0x80010000)^1);break;
    case 21:sw_(context,lw_(context));break; /* Mutable context retains camera precision. */
    case 19:sw_(0x80015d00,lw_(0x80015d00)^1);break; /* EVENT-only code tail. */
    case 20:sw_(0x80015d00,lw_(0x80015d00));break;
    case 10:sw_(0x80010000,lw_(0x80010000));break; /* Same code write changes source epoch. */
    }
    uint32_t pack_begin=actor?0x800133e8:0x80010d30;
    uint32_t project=actor?0x80013424:0x80010d54;
    for(uint32_t pc=pack_begin;pc<project;pc+=4)exec1(pc,fetch(pc));
    if(fault==11)gte_ctrl_write(0,gte_ctrl_read(0)^1);
    if(fault==12)gte_data_write(0,pack(120,100));
    if(fault==13)exec1(actor?0x8001322c:0x80010c3c,fetch(actor?0x8001322c:0x80010c3c));
    if(fault==14)exec1(actor?0x80013158:0x80010424,fetch(actor?0x80013158:0x80010424));
    if(fault==15)project=0x800104ac; /* Another RTPS is not an implied producer. */
    exec1(project,fetch(project));
    world_precision_vertex value={0};
    int valid=world_precision_gte_read(14,gte_data_read(14),&value);
    if(enabled && (!fault || fault==16 || fault==18 || fault==21)) {
        assert(valid && value.projection_kind==WORLD_PROJECTION_CAMERA);
        assert(value.camera_generation==wp_object);
        assert(value.producer_pc==(actor?0x80013424u:0x80010d54u));
    } else if(valid)assert(value.projection_kind==WORLD_PROJECTION_NATIVE_Q16);
    for(unsigned i=0;i<64;i++) {
        uint32_t word=i<32?gte_data_read(i):gte_ctrl_read(i-32);
        if(!enabled)native_gte[i]=word;else assert(word==native_gte[i]);
    }
    if(!enabled) {
        memcpy(native_ram,PSX_RAM,sizeof native_ram);memcpy(native_scratch,PSX_SCRATCH,sizeof native_scratch);
        memcpy(native_registers,R,sizeof R);
    } else {
        assert(!memcmp(native_ram,PSX_RAM,sizeof native_ram));
        assert(!memcmp(native_scratch,PSX_SCRATCH,sizeof native_scratch));
        assert(!memcmp(native_registers,R,sizeof R));
    }
    return value;
}
static void event_actor_project(unsigned index,uint32_t destination,uint32_t duplicate) {
    R[6]=destination;R[22]=duplicate;
    gte_data_write(0,pack(actor_input[index][0],actor_input[index][1]));
    gte_data_write(1,actor_input[index][2]);
    exec1(0x80013424,fetch(0x80013424));
    exec1(0x80013494,fetch(0x80013494));
    exec1(0x80013498,fetch(0x80013498));
    exec1(0x8001349c,fetch(0x8001349c));
    exec1(0x800134a0,fetch(0x800134a0));
    exec1(0x800134a4,fetch(0x800134a4));
    exec1(0x800134a8,fetch(0x800134a8));
    exec1(0x800134b0,fetch(0x800134b0)); /* real branch delay slot */
    if(duplicate) {
        exec1(0x800134b4,fetch(0x800134b4));
        exec1(0x800134b8,fetch(0x800134b8));
        exec1(0x800134c0,fetch(0x800134c0));
        assert(lw_(duplicate)==lw_(destination));
    }
    assert(lw_(destination)==pack(actor_xy[index][0],actor_xy[index][1]));
}

static void event_draw_actor(const uint32_t source[4],unsigned command,
                                uint32_t caller,int wanted) {
    uint32_t face=0x8017672c,material=face+(command&4?0x2c:8);
    int count=command&8?4:3,stride=command&4?12:8;
    const unsigned quad_order[]={0,1,3,2};
    for(unsigned i=0;i<4;i++) {
        sw_(R[5]+0x3b8+i*4,source[i]);
        sw_(R[5]+0x3a8+i*4,lw_(source[i]+4));
        R[16+i*2]=(uint32_t)(int32_t)actor_xy[i][0];
        R[17+i*2]=(uint32_t)(int32_t)actor_xy[i][1];
    }
    for(unsigned i=0;i<4;i++)R[8+i]=lw_(material+i*4);
    R[8]=(R[8]&0xffffffu)|(command<<24);
    R[14]=lw_(material+16);R[15]=lw_(material+20);R[24]=lw_(material+24);
    R[12]=R[15]>>16;R[13]=R[14]>>16;R[25]=R[24]>>16;
    R[1]=lw_(material+28);R[2]=0x800f9000;R[4]=0x80015ea0;
    R[7]=0x80008000;R[30]=0;R[31]=caller;
    sw_(R[4]+0x64,0x80110000);sw_(R[4]+0x5f8,0);
    sh_(R[5]+0x3d0,0xffff);sh_(R[5]+0x3d2,0);
    int wrapped=caller==0x800137b4 || caller==0x80013840 || caller==0x800138f4;
    if(wrapped) {
        R[25]=0x80007000;
        for(unsigned i=0;i<20;i+=4)sw_(R[25]+i,0);
        sw_(R[4]+0x5e8,0x80007400);sw_(R[4]+0x5ec,0x80007800);
    }
    psx_interp(wrapped?0x80013960:0x80013d50);
    uint64_t generation=0;
    for(int i=0;i<count;i++) {
        unsigned n=count==4?quad_order[i]:(unsigned)i;
        uint32_t address=0x800f900c+(unsigned)i*stride;
        assert(lw_(address)==pack(actor_xy[n][0],actor_xy[n][1]));
        world_precision_vertex got;
        int valid=world_precision_packet(address,lw_(address),&got);
        assert(valid==wanted);
        if(!valid)continue;
        assert(got.source_address==(source[n]&0x1fffffff));
        assert(got.producer_pc==0x80013424);
        if(i)assert(got.generation==generation);generation=got.generation;
    }
}

static void event_actor_route(const uint8_t *base,int enabled) {
    static uint8_t native_ram[PSX_RAM_SIZE],native_scratch[0x400];
    static uint32_t native_registers[32],native_gte[64];
    memcpy(PSX_RAM,base,sizeof PSX_RAM);
    memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);memset(R,0,sizeof R);
    world_precision_configure(enabled);setup_projection();
    /* Materials and screen inputs are controlled; the executed emitters are EVENT AL22. */
    R[4]=0x80015ea0;R[5]=0x1f800000;R[30]=0x80002000;
    sw_(R[4]+0x5cc,0);sh_(R[4]+0xab0,0);
    exec1(0x80013190,fetch(0x80013190));
    exec1(0x8001322c,fetch(0x8001322c));
    uint32_t source[4];
    for(unsigned i=0;i<4;i++) {
        source[i]=R[5]+actor_indices[i]*16;
        event_actor_project(i,source[i],0);
    }
    event_draw_actor(source,0x3c,0x80013878,enabled);
    event_draw_actor(source,0x38,0x8001392c,enabled);
    event_draw_actor(source,0x34,0x800137ec,enabled);
    event_draw_actor(source,0x30,0x800137ec,enabled);
    event_draw_actor(source,0x3f,0x800137b4,enabled); /* real UV/color wrapper */
    event_draw_actor(source,0x33,0x80013840,enabled);
    event_draw_actor(source,0x3c,0x800138f4,enabled);
    event_draw_actor(source,0x74,0x800137ec,0); /* invalid high command bits */
    event_draw_actor(source,0x3c,0x80011400,0); /* unrelated caller */
    sh_(R[4]+0xab0,0x0800);
    event_draw_actor(source,0x3c,0x80013878,0); /* different screen-feedback path */
    sh_(R[4]+0xab0,0);
    uint16_t saved_depth=(uint16_t)lh_(source[0]+4);
    sh_(source[0]+4,0);
    event_draw_actor(source,0x3c,0x80013878,0);
    sh_(source[0]+4,saved_depth);
    event_draw_actor(source,0x3c,0x80013878,enabled);
    sb_(source[1],lb_(source[1]));
    event_draw_actor(source,0x3c,0x80013878,0); /* identical overwrite */
    event_actor_project(1,source[1],0);
    event_draw_actor(source,0x3c,0x80013878,enabled);
    /* The branch's optional copy shares a projection, but has independent
     * address lifetime. Exercise the first and final byte-index overflow slots. */
    for(unsigned slot=0;slot<=195;slot+=195) {
        uint32_t alternate[4];memcpy(alternate,source,sizeof alternate);
        R[23]=0x80006000;alternate[3]=R[23]+slot*16;
        event_actor_project(3,source[3],alternate[3]);
        event_draw_actor(alternate,0x3c,0x80013878,enabled);
        sw_(alternate[3],lw_(alternate[3]));
        event_draw_actor(alternate,0x3c,0x80013878,0);
        event_draw_actor(source,0x3c,0x80013878,enabled);
    }
    {
        uint32_t alternate[4];memcpy(alternate,source,sizeof alternate);
        /* A corrupt overflow-bank pointer must not grant a second scratch
         * record the provenance reserved for the part's explicit RAM bank. */
        R[23]=0x1f800000;alternate[3]=0x1f8000a0;
        event_actor_project(3,source[3],alternate[3]);
        event_draw_actor(alternate,0x3c,0x80013878,0);
        event_draw_actor(source,0x3c,0x80013878,enabled);
    }
    /* A same-value register rewrite after MFC2 is not the same producer. */
    R[6]=source[0];R[22]=0;
    gte_data_write(0,pack(actor_input[0][0],actor_input[0][1]));gte_data_write(1,actor_input[0][2]);
    exec1(0x80013424,fetch(0x80013424));exec1(0x80013498,fetch(0x80013498));
    exec1(0x80020000,0x26730000);exec1(0x800134a0,fetch(0x800134a0));
    event_draw_actor(source,0x3c,0x80013878,0);
    event_actor_project(0,source[0],0);
    /* New part, terminal return, early return and world entry all fence off
     * the old actor records, even when every visible/native word is equal. */
    const uint32_t fences[]={0x8001322c,0x80013950,0x80013190,0x80010c3c};
    for(unsigned f=0;f<sizeof fences/sizeof fences[0];f++) {
        exec1(fences[f],fetch(fences[f]));
        event_draw_actor(source,0x3c,0x80013878,0);
        R[30]=0x80002000;exec1(0x8001322c,fetch(0x8001322c));
        for(unsigned i=0;i<4;i++)event_actor_project(i,source[i],0);
        event_draw_actor(source,0x3c,0x80013878,enabled);
    }
    uint32_t original=lw_(0x80010000);sw_(0x80010000,original^1);
    event_draw_actor(source,0x3c,0x80013878,0); /* immutable-code identity */
    sw_(0x80010000,original);
    for(unsigned i=0;i<64;i++) {
        uint32_t value=i<32?gte_data_read(i):gte_ctrl_read(i-32);
        if(!enabled)native_gte[i]=value;else assert(value==native_gte[i]);
    }
    if(!enabled) {
        memcpy(native_ram,PSX_RAM,sizeof native_ram);memcpy(native_scratch,PSX_SCRATCH,sizeof native_scratch);
        memcpy(native_registers,R,sizeof R);
    } else {
        assert(!memcmp(native_ram,PSX_RAM,sizeof native_ram));
        assert(!memcmp(native_scratch,PSX_SCRATCH,sizeof native_scratch));
        assert(!memcmp(native_registers,R,sizeof R));
        puts("PASS: EVENT actor RTPS/MFC2/SW and four direct/wrapped emit layouts; native RAM/scratch/GPR/GTE identical");
    }
}

static void event_draw_quad(int q,const uint32_t source[8],uint32_t caller,int wanted) {
    const unsigned map[]={0,1,3,2};
    for(int i=0;i<4;i++) {
        unsigned n=quads[q][map[i]];
        sw_(R[5]+0x3b8+i*4,source[n]);
        R[16+i*2]=(uint32_t)(int32_t)projected[n][0];
        R[17+i*2]=(uint32_t)(int32_t)projected[n][1];
    }
    R[2]=0x800f7900+q*0x38;R[4]=0x80015ea0;R[7]=0x80008000;
    R[8]=0x3c808080;R[9]=R[10]=R[11]=0x808080;R[30]=0;
    R[31]=caller;R[1]=0xe1000006;
    sw_(R[4]+0x64,0x80110000);sw_(R[5]+0x3d4,0);
    sh_(R[5]+0x3d0,0xffff);sh_(R[5]+0x3d2,0);
    psx_interp(0x800125b4);
    uint64_t generation=0;
    for(int i=0;i<4;i++) {
        uint32_t addr=0x800f790c+q*0x38+i*12;
        world_precision_vertex got;
        int valid=world_precision_packet(addr,lw_(addr),&got);
        assert(valid==wanted);
        if(!valid) continue;
        assert(got.source_address==source[quads[q][i]]);
        assert(got.producer_pc==0x80010d54);
        if(i) assert(got.generation==generation);
        generation=got.generation;
    }
}
static void event_world_route(const uint8_t *base,int enabled) {
    static uint8_t native_ram[PSX_RAM_SIZE],native_scratch[0x400];
    static uint32_t native_registers[32];
    memcpy(PSX_RAM,base,sizeof PSX_RAM);
    memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);memset(R,0,sizeof R);
    world_precision_configure(enabled);setup_projection();
    /* AL22's real entry100AC/100B0 sets a0 to this mutable context, directly
     * after the final instruction at157AC. Hashing context bytes rejects
     * every live object when10C34 saves ra at context+7C. */
    R[4]=0x80015ea0;R[5]=0x1f800000;R[31]=0;
    exec1(0x80010c3c,fetch(0x80010c3c)); /* real object entry */
    uint32_t source[8];
    for(int i=0;i<8;i++) {
        source[i]=0x1f800000+i*12;
        R[6]=source[i];R[2]=0x80004000;
        gte_data_write(0,pack(input[i][0],input[i][1]));gte_data_write(1,input[i][2]);
        for(uint32_t pc=0x80010d54;pc<=0x80010dbc;pc+=4) exec1(pc,fetch(pc));
        assert(lw_(source[i])==pack(projected[i][0],projected[i][1]));
    }
    for(int q=0;q<3;q++) event_draw_quad(q,source,0x800111bc,enabled);
    event_draw_quad(0,source,0x80011408,0); /* unknown/near caller */
    sh_(source[0]+4,180);
    event_draw_quad(0,source,0x800111bc,0); /* unsupported near depth */
    sh_(source[0]+4,993);
    R[6]=source[0];
    gte_data_write(0,pack(input[0][0],input[0][1]));gte_data_write(1,input[0][2]);
    exec1(0x80010d54,fetch(0x80010d54));
    exec1(0x80010da0,fetch(0x80010da0));
    exec1(0x80020000,0x26730000); /* addiu s3,s3,0: identical write is still new provenance */
    exec1(0x80010db4,fetch(0x80010db4));
    event_draw_quad(0,source,0x800111bc,0);
    uint32_t original=lw_(0x80010000);
    sw_(0x80010000,original^1); /* Different code, even outside executed sites. */
    exec1(0x80010c3c,fetch(0x80010c3c));
    event_draw_quad(2,source,0x800111bc,0);
    sw_(0x80010000,original);
    exec1(0x80010c3c,fetch(0x80010c3c));
    event_draw_quad(2,source,0x800111bc,0); /* previous object's records */
    if(!enabled) {
        memcpy(native_ram,PSX_RAM,sizeof native_ram);memcpy(native_scratch,PSX_SCRATCH,sizeof native_scratch);
        memcpy(native_registers,R,sizeof R);
    } else {
        assert(!memcmp(native_ram,PSX_RAM,sizeof native_ram));
        assert(!memcmp(native_scratch,PSX_SCRATCH,sizeof native_scratch));
        assert(!memcmp(native_registers,R,sizeof R));
        puts("PASS: EVENT world RTPS/MFC2/SW and far-quad interpreter route, all 12 target vertices; native RAM/scratch/GPR identical");
    }
}

/* Original face33 of model801AEC88 is cmd34, indices50/52/54/54.
 * Its real far dispatcher126C4 branches12794→128B8, writes XY at
 * packet+0C/+18/+24 and finishes at12988. It shares source edge50–52
 * with tracked quad face29; this is source topology, not screen-XY lookup. */
static void event_draw_triangle(const uint32_t source[3],uint32_t caller,int wanted,
                                   int poison_fourth,uint32_t command_bits) {
    const int xy[3][2]={{152,149},{181,151},{185,162}};
    uint32_t face=0x801af384;
    for(unsigned i=0;i<4;i++) {
        unsigned n=i<3?i:2;
        sw_(R[5]+0x3b8+i*4,source[n]);sw_(R[5]+0x3a8+i*4,lw_(source[n]+4));
        R[16+i*2]=xy[n][0];R[17+i*2]=xy[n][1];
    }
    if(poison_fourth) {
        /* The real triangle branch never consumes fourth XY/depth. Neither
         * a quad's source0/1/3 order nor phantom fourth provenance is valid. */
        sw_(R[5]+0x3c4,0x1f800300);sw_(R[5]+0x3b4,0);
        R[22]=0x123;R[23]=0x124;
    }
    for(unsigned i=0;i<4;i++)R[8+i]=lw_(face+8+i*4);
    R[8]|=command_bits;
    R[14]=lw_(face+0x18);R[15]=lw_(face+0x1c);R[24]=lw_(face+0x20);
    R[12]=R[15]>>16;R[13]=R[14]>>16;R[25]=R[24]>>16;
    R[1]=lw_(face+0x24);R[2]=0x800f79d8;R[4]=0x80015ea0;
    R[7]=0x80008000;R[30]=0;R[31]=caller;
    sw_(R[4]+0x64,0x80110000);sw_(R[5]+0x3d4,lw_(face));
    sh_(R[5]+0x3d0,0xffff);sh_(R[5]+0x3d2,0);
    psx_interp(0x800125b4);
    uint64_t generation=0;
    assert(lw_(0x800f79e0)==(0x34356195|command_bits));
    for(unsigned i=0;i<3;i++) {
        uint32_t address=0x800f79e4+i*12;
        assert(lw_(address)==pack(xy[i][0],xy[i][1]));
        world_precision_vertex value;int valid=world_precision_packet(address,lw_(address),&value);
        assert(valid==wanted);
        if(!valid)continue;
        assert(value.source_address==source[i]);assert(value.producer_pc==0x80010d54);
        if(i)assert(value.generation==generation);generation=value.generation;
    }
}
static void event_triangle_route(const uint8_t *base,int enabled) {
    static uint8_t native_ram[PSX_RAM_SIZE],native_scratch[0x400];
    static uint32_t native_registers[32],native_gte[64];
    memcpy(PSX_RAM,base,sizeof PSX_RAM);
    sw_(0x801af38c,0x34356195); /* Controlled triangle material. */
    memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);memset(R,0,sizeof R);
    world_precision_configure(enabled);setup_projection();
    R[4]=0x80015ea0;R[5]=0x1f800000;R[31]=0;
    exec1(0x80010c3c,fetch(0x80010c3c));
    const unsigned indices[]={50,52,54};
    const int16_t inputs[3][3]={{-382,600,359},{-337,600,399},{-309,600,383}};
    uint32_t source[3];
    for(unsigned i=0;i<3;i++) {
        /* Controlled positional input; geometry extraction is tested separately. */
        source[i]=0x1f800000+indices[i]*12;R[6]=source[i];R[2]=0x80004000;
        gte_data_write(0,pack(inputs[i][0],inputs[i][1]));gte_data_write(1,inputs[i][2]);
        for(uint32_t pc=0x80010d54;pc<=0x80010dc4;pc+=4)exec1(pc,fetch(pc));
    }
    event_draw_triangle(source,0x800111bc,enabled,0,0);
    event_draw_triangle(source,0x800111bc,enabled,1,0);
    /* Raw/semi flags are polygon variants, but high opcode bits are not. */
    event_draw_triangle(source,0x800111bc,enabled,1,0x03000000);
    event_draw_triangle(source,0x800111bc,0,1,0x40000000);
    event_draw_triangle(source,0x800111bc,0,1,0x80000000);
    event_draw_triangle(source,0x80011408,0,0,0); /* Unsupported caller. */
    sb_(source[1],lb_(source[1])); /* Identical source overwrite revokes all3. */
    event_draw_triangle(source,0x800111bc,0,0,0);
    for(unsigned i=0;i<64;i++) {
        uint32_t value=i<32?gte_data_read(i):gte_ctrl_read(i-32);
        if(!enabled)native_gte[i]=value;else assert(value==native_gte[i]);
    }
    if(!enabled) {
        memcpy(native_ram,PSX_RAM,sizeof native_ram);memcpy(native_scratch,PSX_SCRATCH,sizeof native_scratch);
        memcpy(native_registers,R,sizeof R);
    } else {
        assert(!memcmp(native_ram,PSX_RAM,sizeof native_ram));
        assert(!memcmp(native_scratch,PSX_SCRATCH,sizeof native_scratch));
        assert(!memcmp(native_registers,R,sizeof R));
        puts("PASS: EVENT far-triangle source indices0/1/2, all3 tags and complete fallback; native RAM/scratch/GPR/GTE identical");
    }
}

static world_precision_vertex event_local_case(const uint8_t *base,int enabled,int fault,int variant) {
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
    const uint32_t registry=0x80009000,header=0x8000a000,vertex=0x8000b000,context=0x80015ea0;
    memset(PSX_RAM+0x2000,0,0x40);memset(PSX_RAM+0x3000,0,20);memset(PSX_RAM+0x4000,0,80);
    sh_(matrix,4096);sh_(matrix+8,4096);sh_(matrix+16,4096);sw_(camera+0x1c,matrix);
    if(variant==1) {
        /* Quarter-turn camera and signed camera fractions, combined with a
         * non-diagonal local rotation below. */
        sh_(matrix,0);sh_(matrix+2,(uint16_t)-4096);sh_(matrix+6,4096);sh_(matrix+8,0);
        sw_(camera+0x2c,1024);sw_(camera+0x30,(uint32_t)-2048);sw_(camera+0x34,3072);
    }
    R[4]=camera;R[29]=0x80007000;
    for(uint32_t pc=0x80012ef8;pc<=0x80012f9c;pc+=4)exec1(pc,fetch(pc));
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
    for(uint32_t pc=0x8001322c;pc<=0x80013424;pc+=4) {
        /* Execute exactly the untaken/taken branches for flags=0 and
         * duplication=0, with every real delay slot retained. */
        if(pc==0x80013290 || pc==0x800132fc || pc==0x80013348 ||
           pc==0x800133a4 || pc==0x800133ac || pc==0x800133c8 ||
           (pc>=0x800133d0&&pc<=0x800133d8))continue;
        if(variant==2 && (pc==0x80013298 || pc==0x8001329c))continue;
        if(pc==0x800133e8) {
            if(fault==9)sh_(vertex,0);             /* Same rounded position, different remainder. */
            if(fault==1)sh_(vertex,3);             /* Source changed since MVMVA. */
            if(fault==2)sh_(part+32,2047);         /* Source matrix changed. */
            if(fault==3)R[2]++;                   /* Unaligned source. */
            if(fault==4)sh_(header+16,0);          /* No source vertex exists. */
            if(fault==5)R[8]+=65536;              /* Same int16, unsafe packing. */
            if(fault==7)sw_(context+0x5cc,0x100);  /* Flattened path unsupported. */
        }
        if(pc==0x80013424 && fault==10)sh_(vertex,0); /* Changed after the packing check. */
        if(pc==0x80013424 && fault==6)R[2]+=16;    /* Cannot lend to another source. */
        if(pc==0x80013424 && fault==8)exec1(0x8001339c,fetch(0x8001339c));
        exec1(pc,fetch(pc));
    }
    world_precision_vertex value;
    assert(world_precision_gte_read(14,gte_data_read(14),&value));
    if(!fault){assert(value.projection_kind==WORLD_PROJECTION_CAMERA);assert(value.producer_pc==0x80013424u);}
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
    assert(argc==2);
    static uint8_t base[PSX_RAM_SIZE];
    FILE *f=fopen(argv[1],"rb");assert(f);
    assert(fread(base+0x10000,1,26968,f)==26968);assert(fgetc(f)==EOF);fclose(f);
    event_world_route(base,0);event_world_route(base,1);
    event_triangle_route(base,0);event_triangle_route(base,1);
    event_actor_route(base,0);event_actor_route(base,1);
    const int32_t raw[]={-4097,-4096,-4095,-1,0,1,4095,4096,4097};
    /* Independently evaluated floor(Q16(160+96*(100-raw/4096)/600)). */
    const int32_t xq[]={11544824,11544821,11544819,11534338,11534336,
                        11534333,11523852,11523850,11523847};
    for(unsigned n=0;n<9;n++)for(int actor=0;actor<2;actor++) {
        event_camera_case(base,actor,raw[n],0,0);
        world_precision_vertex v=event_camera_case(base,actor,raw[n],0,1);
        assert(fabs(v.x-(double)xq[n]/65536)<1.01/65536);
        assert(v.y==140 && v.z==600);
    }
    const int faults[]={1,2,3,4,5,6,8,9,10,11,12,13,14,17,19,20};
    for(unsigned n=0;n<sizeof faults/sizeof faults[0];n++)for(int actor=0;actor<2;actor++) {
        event_camera_case(base,actor,-1,faults[n],0);
        event_camera_case(base,actor,-1,faults[n],1);
    }
    for(int actor=0;actor<2;actor++){event_camera_case(base,actor,-1,21,0);event_camera_case(base,actor,-1,21,1);}
    event_camera_case(base,1,-1,7,0);event_camera_case(base,1,-1,7,1);
    for(int fault=0;fault<=10;fault++){event_local_case(base,0,fault,0);event_local_case(base,1,fault,0);}
    for(int variant=1;variant<=2;variant++){event_local_case(base,0,0,variant);event_local_case(base,1,0,variant);}
    puts("PASS: EVENT local/normal MVMVA separation and exact source/camera fractions; native state identical");
    puts("PASS: EVENT WORLD/ACTOR camera fractions, real producer identity, source/matrix/lifetime and EVENT-tail invalidation; native RAM/scratch/GPR/GTE identical");
    return 0;
}
