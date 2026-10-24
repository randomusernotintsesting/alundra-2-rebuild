/* Replay complete captured DrawEnv + DrawOTag lists through the CPU GPU.
 * cc -O3 -UNDEBUG -Iport/src port/tests/diagnose_gpu_capture.c -o /tmp/a2-capture
 * /tmp/a2-capture RAM VRAM WORLD_ROOT SECONDARY_ROOT ENV_TAG IR FILTER ITERATIONS
 * Example roots for the retained frame11000: 0x8011546c 0x801133f0 0x800f62e4.
 * Optional A2_TRIANGLE_GPU_SOURCE selects an explicit frozen renderer source.
 * Source texture state is a captured post-frame VRAM snapshot; this is an exact
 * A/B workload, not an assertion that it regenerates the native HD screenshot.
 */
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef A2_TRIANGLE_GPU_SOURCE
#define A2_TRIANGLE_GPU_SOURCE "../src/gpu.c"
#endif
#include A2_TRIANGLE_GPU_SOURCE
uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
uint32_t psx_frame_no,gpu_flips;
void psx_vblank_tick(void) {}
uint32_t psx_mmio_read(uint32_t p,int n) {(void)p;(void)n;return 0;}
int a2_modelcap_active(void) {return 0;}
FILE *a2_modelcap_file(void) {return NULL;}
static uint16_t seed[1024*512];
static double now(void) {struct timespec t;clock_gettime(CLOCK_MONOTONIC,&t);return t.tv_sec+t.tv_nsec*1e-9;}
/* Process CPU time separates renderer cost from host scheduling pauses. */
static double cpu_now(void) {struct timespec t;clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&t);return t.tv_sec+t.tv_nsec*1e-9;}
static uint64_t hash(const uint16_t *p,size_t n) {uint64_t h=1469598103934665603ull;for(size_t i=0;i<n;i++)h=(h^p[i])*1099511628211ull;return h;}
static void read_exact(const char *name,void *dst,size_t n) {FILE *f=fopen(name,"rb");assert(f);assert(fread(dst,1,n,f)==n);assert(fgetc(f)==EOF);fclose(f);}
static void list(uint32_t addr) {
 unsigned guard=0;
 while((addr&0xffffff)!=0xffffff) {
  assert(++guard<100000);addr&=0x1ffffc;uint32_t head=lw_(addr),n=head>>24;
  assert(addr+4+n*4<=PSX_RAM_SIZE);gpu_ll_node=addr;
  for(unsigned i=1;i<=n;i++)gpu_gp0_at(lw_(addr+4*i),addr+4*i);
  addr=head&0xffffff;if(!addr)break;
 }
}
int main(int argc,char **argv) {
 assert(argc==9);read_exact(argv[1],PSX_RAM,sizeof PSX_RAM);read_exact(argv[2],seed,sizeof seed);
 unsigned a=strtoul(argv[3],0,0),b=strtoul(argv[4],0,0);unsigned env=strtoul(argv[5],0,0);int scale=atoi(argv[6]),filter=atoi(argv[7]),n=atoi(argv[8]);assert(n>0&&n<100);
 gpu_set_ir(scale);gpu_set_filter(filter);
 double total=0,cpu_total=0;uint64_t native=0,fine=0;
 for(int i=0;i<n;i++) {
  gpu_gp1(0);memcpy(GPU_VRAM,seed,sizeof seed);if(scale>1)memset(SHADOW,0,(size_t)IR_W*IR_H*2);
  double t=now(),cpu=cpu_now();list(env);list(a);list(b);cpu_total+=cpu_now()-cpu;total+=now()-t;
  uint64_t hn=hash(GPU_VRAM,1024*512),hf=scale>1?hash(SHADOW,(size_t)IR_W*IR_H):hn;
  if(i){assert(hn==native);assert(hf==fine);}native=hn;fine=hf;
 }
 printf("IR%d filter%d captured-OT n%d mean_ms=%.6f native=%016llx fine=%016llx cpu_ms=%.6f\n",scale,filter,n,total*1000/n,(unsigned long long)native,(unsigned long long)fine,cpu_total*1000/n);
 gpu_set_ir(1);return 0;
}
