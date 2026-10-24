/* Execute the real retained emitter used by the packet fixture. The Python
 * driver compares complete native-state digests across trace OFF/ON/ranges. */
#define main packet_semantics_fixture_main
#include "test_native_actor_packets.c"
#undef main

static uint64_t digest(uint64_t h,const void *bytes,size_t n){
 const unsigned char *p=bytes;while(n--)h=(h^*p++)*UINT64_C(1099511628211);return h;
}
int main(void){
 for(unsigned scenario=0;scenario<5;scenario++){
  psx_frame_no=scenario==0?9:scenario==4?11:10;
  setup(scenario==2);psx_work=0;
  if(scenario==2){
   snapshot.sequence++;snapshot.shadow_pass=1;
   R[4]=snapshot.draw_object_address;a2_native_actor_packets_before(0x80012e68,R);
   R[4]=0x800157b0;sw_(R[4]+0x5cc,0x100);
  }
  if(scenario==3){snapshot.parts[1].fallback=A2_ACTOR_UNBOUND_SOURCE;restart();}
  unsigned count=all_faces();assert(count==27);seal();
  uint64_t h=UINT64_C(14695981039346656037);
  h=digest(h,PSX_RAM,sizeof PSX_RAM);h=digest(h,PSX_SCRATCH,sizeof PSX_SCRATCH);
  h=digest(h,R,sizeof R);h=digest(h,&psx_work,sizeof psx_work);h=digest(h,&psx_next,sizeof psx_next);
  printf("scenario=%u frame=%u digest=%016llx\n",scenario,psx_frame_no,(unsigned long long)h);
 }
 return 0;
}
