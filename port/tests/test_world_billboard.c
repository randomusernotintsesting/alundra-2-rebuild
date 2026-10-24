/* Real WORLD setup and complete variable-record billboard loop. The retained
 * source/matrices/material wrapper reproduce the failed cabin GP0 payload.
 * Only the unrelated opaque world list and allocator/OT are isolated. */
#define main reward_billboard_main
#include "test_native_billboard.c"
#undef main
#include "fixtures/world_billboard_source.h"
#include "../src/gpu.c"
uint32_t gpu_flips;
void psx_vblank_tick(void) { gpu_vblank(); }
static unsigned mode,opcode=0x3e,seen_callers;
static int precision_mode,camera_nudge;
static uint32_t world_run(int enabled,int fault){
 memset(PSX_RAM,0,sizeof PSX_RAM);memset(PSX_SCRATCH,0,sizeof PSX_SCRATCH);memset(R,0,sizeof R);
 memcpy(PSX_RAM+0x10000,chest_al22,sizeof chest_al22);
 memcpy(PSX_RAM+0x11763c,world_billboard_object,sizeof world_billboard_object);
 memcpy(PSX_RAM+0x66fd8,world_billboard_matrices,sizeof world_billboard_matrices);
 memcpy(PSX_RAM+0x1b0038,world_billboard_header,sizeof world_billboard_header);
 memcpy(PSX_RAM+0x1ba5a0,world_billboard_record,sizeof world_billboard_record);
 memcpy(PSX_RAM+0x127818,world_billboard_material_table,sizeof world_billboard_material_table);
 memcpy(PSX_RAM+0x128024,world_billboard_material,sizeof world_billboard_material);
 memcpy(PSX_RAM+(lw_(0x801b0038+0x208)&0x1fffff),world_billboard_tpages,sizeof world_billboard_tpages);
 memcpy(PSX_RAM+(lw_(0x801b0038+0x20c)&0x1fffff),world_billboard_cluts,sizeof world_billboard_cluts);
 memcpy(PSX_RAM+0x1066a0,world_billboard_packet,56); /* Preserve unused upper UV halfwords. */
 a2_native_billboard_init(PSX_RAM,sizeof PSX_RAM);a2_native_billboard_configure(enabled);
 world_precision_configure(1);world_camera_configure(precision_mode);HI=LO=psx_work=psx_next=0;psx_bb_budget=1000000;
 for(int i=0;i<32;i++){gte_ctrl_write(i,0);gte_data_write(i,0);}
 const uint32_t obj=mode==9?0x80160000:0x8011763c,ctx=0x800157b0,base=0x801066a0;
 const uint32_t record=mode==8?0x80180040:0x801ba5a0;
 if(mode==9)memcpy(PSX_RAM+0x160000,world_billboard_object,sizeof world_billboard_object);
 if(precision_mode)sw_(obj+44,lw_(obj+44)+camera_nudge);
 if(mode==8)memcpy(PSX_RAM+0x180040,world_billboard_record,sizeof world_billboard_record);
 sw_(obj+16,0x801b0038);sw_(0x801b0038,0);sw_(0x801b0038+0x200,record); /* Isolate the billboard list. */
 sw_(record+24,(lw_(record+24)&0xffffffu)|(opcode<<24));
 int two=(mode>=2&&mode<=5)||mode==10;
 if(mode==1||mode==2||mode==4)sb_(record+56,0);
 if(mode==6)sw_(record+52,0xe1000200);
 if(two){
  memcpy(PSX_RAM+((record+60)&0x1fffff),PSX_RAM+((record+24)&0x1fffff),36);
  sh_(record+16,lh_(record+16)|4);sh_(record+96,0);
  sb_(record+92,(mode==3||mode==4)?4:0);
  if(mode==10)sw_(record+60,0x30808080); /* Legal first layer emits nothing. */
 }
 sw_(obj+12,0x80008000);sw_(ctx+0x60,base);sw_(ctx+0x64,base+4096);
 gte_ctrl_write(24,160<<16);gte_ctrl_write(25,124<<16);gte_ctrl_write(26,96);
 if(fault==8)sw_(record+4,32767);
 if(fault==9)sh_(record+20,65535);
 if(fault==10)gte_ctrl_write(26,0);
 if(fault==11)sw_(0x80010000,lw_(0x80010000)^1);
 if(fault==13)sh_(record,lh_(record)|0x4000);
 if(fault==14)sh_(record+16,lh_(record+16)|0x8000);
 if(fault==18)sh_(record+18,4000); /* OT bias must not change physical depth. */
 R[29]=0x801ff000;R[31]=0x80025400;R[4]=obj;
 uint32_t pc=0x800100a8;
 for(unsigned segments=0;pc!=0x80025400;segments++){
  assert(segments<20);psx_interp(pc);pc=psx_next;
  if(pc==0x80014cd8&&fault==12)a2_native_billboard_reset();
  if(pc==0x80012a78||pc==0x800126c4){
   assert(R[3]==record);
   const uint32_t callers[6]={0x80014f40,0x80014f80,0x80014fec,0x8001502c,0x80015090,0x800150d0};
   unsigned j;for(j=0;j<6;j++)if(R[31]==callers[j]){seen_callers|=1u<<j;break;}assert(j<6);
   if(fault==1)sw_(record+4,lw_(record+4));
   if(fault==2)sw_(0x80067018,lw_(0x80067018));
   if(fault==3)sw_(ctx,lw_(ctx));
   if(fault==4)sw_(0x80010000,lw_(0x80010000));
   if(fault==5)gte_ctrl_write(26,97);
   if(fault==6)world_precision_reset();
   if(fault==15)sw_(obj+44,lw_(obj+44));
   if(fault==16)sw_(0x801b0038+0x200,lw_(0x801b0038+0x200));
   if(fault==17)gte_ctrl_write(0,gte_ctrl_read(0)^1);
  }
 }
 if(!precision_mode&&!mode&&opcode==0x3e&&fault<8&&memcmp(PSX_RAM+0x1066a4,world_billboard_packet+4,52)){
  for(unsigned j=0;j<14;j++)fprintf(stderr,"%u got=%08x expected=%08x\n",j,lw_(base+4*j),((const uint32_t*)world_billboard_packet)[j]);
 }
 if(!precision_mode&&!mode&&opcode==0x3e&&fault<8)assert(!memcmp(PSX_RAM+0x1066a4,world_billboard_packet+4,52));
 if(fault==7)sb_(base+55,lb_(base+55));
 uint64_t token=a2_native_billboard_token(base+8,lw_(base+8));
 if(enabled&&(!fault||fault==18)){
  unsigned count=(opcode&8)?12:9,stride=4*(count+2);
  for(unsigned j=0;j<(two&&mode!=10?2u:1u);j++){
   uint32_t command=base+8+j*stride;uint64_t t=a2_native_billboard_token(command,lw_(command));assert(t);
   double z=0;const uint32_t *words=(const uint32_t*)(PSX_RAM+(command&0x1fffff));
   assert(!a2_native_billboard_token(command-4,lw_(command-4)));
   assert(!a2_native_billboard_consume(command,t,words,count==12?9:12,&z));
   assert(a2_native_billboard_consume(command,t,words,count,&z));
   if(!precision_mode)assert(z==773.244140625);
   assert(!a2_native_billboard_consume(command,t,words,count,&z));
  }
 }else assert(!token);
 return token!=0;
}
static void pair(int fault){
 static uint8_t ram[PSX_RAM_SIZE],scratch[0x400];uint32_t regs[32],gte[64],state[5];
  world_run(0,fault);memcpy(ram,PSX_RAM,sizeof ram);memcpy(scratch,PSX_SCRATCH,sizeof scratch);memcpy(regs,R,sizeof regs);
  for(int i=0;i<64;i++)gte[i]=i<32?gte_data_read(i):gte_ctrl_read(i-32);
  state[0]=HI;state[1]=LO;state[2]=psx_next;state[3]=psx_work;state[4]=psx_bb_budget;
  world_run(1,fault);
  assert(!memcmp(ram,PSX_RAM,sizeof ram)&&!memcmp(scratch,PSX_SCRATCH,sizeof scratch)&&!memcmp(regs,R,sizeof regs));
  for(int i=0;i<64;i++)assert(gte[i]==(i<32?gte_data_read(i):gte_ctrl_read(i-32)));
  assert(state[0]==HI&&state[1]==LO&&state[2]==psx_next&&state[3]==psx_work&&state[4]==(uint32_t)psx_bb_budget);
}
int main(void){
 for(int fault=0;fault<=18;fault++)pair(fault);
 const unsigned formats[]={0x34,0x35,0x36,0x37,0x3c,0x3d,0x3e,0x3f};
 for(unsigned op=0;op<8;op++)for(mode=0;mode<11;mode++){opcode=formats[op];pair(0);}
 assert(seen_callers==63);
 precision_mode=1;mode=0;opcode=0x3e;
 double prior=0;uint32_t prior_native=0;unsigned subpixel_steps=0;
 for(camera_nudge=-4096;camera_nudge<=4096;camera_nudge+=128){
  pair(0);
  double center[3]={0};
  const uint32_t obj=0x8011763c,record=0x801ba5a0;
  for(unsigned row=0;row<3;row++)for(unsigned col=0;col<3;col++){
   uint32_t source=lw_(record+4+4*col);
   double relative=(int16_t)source+(double)(source>>16)-(int32_t)lw_(obj+44+4*col)/4096.0;
   center[row]+=(int16_t)lh_(lw_(obj+36)+2*(row*3+col))*relative/4096.0;
  }
  double width=(uint16_t)lh_(record+20),height=(uint16_t)lh_(record+22);
  for(unsigned i=0;i<4;i++){
   uint32_t address=0x801066ac+12*i,word=lw_(address);world_precision_vertex v;
   assert(a2_native_billboard_vertex(address,word,&v));
   double x=160+(center[0]+(i&1?width:-width))*16368.0/(center[2]*4092.0)*96*.75;
   double y=124+(center[1]+(i&2?height:-height))*16368.0/(center[2]*4092.0)*96;
   assert(fabs(v.x-x)<1.0/65536&&fabs(v.y-y)<1.0/65536);
   assert(v.native_word==word&&v.camera_generation&&v.projection_kind==WORLD_PROJECTION_CAMERA);
   if(!i){if(camera_nudge!=-4096&&word==prior_native&&v.x!=prior)subpixel_steps++;prior=v.x;prior_native=word;}
  }
  /* Even an identical material write retires all derived corners. */
  sw_(0x801066b0,lw_(0x801066b0));world_precision_vertex retired;
  assert(!a2_native_billboard_vertex(0x801066ac,lw_(0x801066ac),&retired));
 }
 assert(subpixel_steps>40);
 printf("65 camera positions, %u subpixel steps inside unchanged native cells; native state identical\n",subpixel_steps);
 camera_nudge=0;
 for(unsigned op=0;op<8;op++)for(mode=0;mode<11;mode++){
  opcode=formats[op];pair(0);
  unsigned nv=(opcode&8)?4:3,stride=4*(3*nv+2);
  unsigned two=(mode>=2&&mode<=5);
  for(unsigned layer=0;layer<1+two;layer++){
   world_precision_vertex v[4];
   for(unsigned i=0;i<nv;i++){
    uint32_t a=0x801066ac+layer*stride+12*i;
    assert(a2_native_billboard_vertex(a,lw_(a),&v[i]));
    assert(v[i].native_word==lw_(a)&&v[i].generation==v[0].generation);
   }
   assert(v[0].y==v[1].y&&v[0].x<v[1].x&&v[0].y<v[nv-1].y);
   if(nv==4)assert(v[0].x==v[2].x&&v[1].x==v[3].x&&v[2].y==v[3].y);
   else assert(v[1].x==v[2].x);
  }
 }
 mode=0;opcode=0x3e;
 /* Feed the real emitted packet through the production GPU parser, then
  * invalidate its material after some XY words have already been queued. */
 gpu_set_ir(2);gpu_gp1(0);gpu_set_world_raster(1);camera_nudge=0;
 for(unsigned stale=0;stale<2;stale++){
  world_run(1,0);
  gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|1023u|(511u<<10));
  for(unsigned i=1;i<14;i++){
   uint32_t a=0x801066a0+4*i;
   gpu_gp0_at(lw_(a),a);
   if(stale&&i==5)sw_(0x801066a4,lw_(0x801066a4));
  }
  assert(world_primitive_valid==!stale);
 }
 gpu_set_ir(1);
 puts("WORLD billboard: retained source/RTPT/wrapped GT4 exact live payload and full native equality PASS");return 0;
}
