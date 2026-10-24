/* Full-surface oracle inherited from H30: real CPU raster versus Metal across
 * all texture modes, blend modes, filters, clipping, winding and large areas.
 * Override A2_FINE_ORACLE_SOURCE to validate against a frozen pre-integration CPU. */
#define main frozen_transport_fixture_main
#ifndef A2_FINE_ORACLE_SOURCE
#define A2_FINE_ORACLE_SOURCE "test_world_precision_gpu.c"
#endif
#include A2_FINE_ORACLE_SOURCE
#undef main
#include "gpu_fine.h"
#include <unistd.h>
typedef struct {A2FineParams params;uint32_t texture_version;} OracleCommand;
static uint64_t rng=0x5f263abe78921439ull;
static uint64_t random64(void){rng^=rng<<13;rng^=rng>>7;rng^=rng<<17;return rng;}
static uint16_t textures[2][1024*512],*actual555;
static uint32_t *actual_rgb;
static A2FineGpu *metal;
static unsigned metal_width;
static char metal_error[2048];
static int render(const OracleCommand *commands,unsigned count,const uint16_t *textures,unsigned width,unsigned height,double *gpu_ms){
 if(metal_width!=width){a2_fine_gpu_destroy(metal);metal=a2_fine_gpu_create(width,height,actual555,actual_rgb,metal_error,sizeof metal_error);metal_width=width;}
 if(!metal){fprintf(stderr,"Metal create: %s\n",metal_error);return 0;}
 A2FineGpuStats before=a2_fine_gpu_stats(metal);
 unsigned previous=~0u;
 for(unsigned i=0;i<count;i++){
  unsigned version=commands[i].texture_version;
  if(version!=previous)a2_fine_gpu_written(metal,0,0,1024,512);
  uint64_t submits=a2_fine_gpu_stats(metal).submissions;
  int accepted=a2_fine_gpu_enqueue(metal,&commands[i].params,textures+(size_t)version*1024*512,metal_error,sizeof metal_error);
  assert(a2_fine_gpu_stats(metal).submissions==submits);
  if(!accepted){
   if(!a2_fine_gpu_sync(metal,metal_error,sizeof metal_error)||
      !a2_fine_gpu_enqueue(metal,&commands[i].params,textures+(size_t)version*1024*512,metal_error,sizeof metal_error)){
    fprintf(stderr,"Metal enqueue/retry: %s\n",metal_error);return 0;
   }
  }
  previous=version;
 }
 if(!a2_fine_gpu_sync(metal,metal_error,sizeof metal_error)){fprintf(stderr,"Metal sync: %s\n",metal_error);return 0;}
 *gpu_ms=a2_fine_gpu_stats(metal).gpu_ms-before.gpu_ms;return 1;
}
static void fill_textures(unsigned test){
 for(unsigned v=0;v<2;v++)for(unsigned i=0;i<1024*512;i++)
  textures[v][i]=(i+v*3+test)%7?(uint16_t)(i*9173u+0x582bu+v*8317+test*37):0;
}
static int run_case(int scale,unsigned test,double *gpu_ms){
 unsigned width=64*scale,height=64*scale;
 gpu_set_ir(scale);gpu_gp1(0);assert(SHADOW&&SHADOW_RGB);
 g.dax1=test%3==0?7:0;g.day1=test%5==0?3:0;g.dax2=63;g.day2=test%7==0?57:63;
 for(unsigned y=0;y<height;y++)for(unsigned x=0;x<width;x++){
  size_t k=(size_t)y*width+x;uint16_t low=(uint16_t)(x*97+y*59+0x9243u);
  uint32_t high=0xff000000u|((x*73+y*23+test*71)&0xffffffu);
  actual555[k]=SHADOW[(size_t)y*IR_W+x]=low;actual_rgb[k]=SHADOW_RGB[(size_t)y*IR_W+x]=high;
 }
 fill_textures(test);OracleCommand cmds[8];memset(cmds,0,sizeof cmds);
 Vtx previous[3];WorldFineTriangle previous_tri;
 int gouraud=test&1,filtered=(test>>1)&1,semi=(test>>2)&1,mode=(test>>3)&3,bpp=(test>>5)&3;
 int tex=test%11!=0;uint32_t window=test&128?0x735ac:0;
 for(unsigned j=0;j<8;j++){
  unsigned version=j>=5;memcpy(GPU_VRAM,textures[version],sizeof GPU_VRAM);
  cur_tpage=(test%3==0?15:4)|(bpp<<7)|(mode<<5)|((test&4)?16:0);cur_clut=500*64+63;
  g.texwin=window;gpu_set_filter(filtered);
  Vtx v[3];WorldFineTriangle tri;
  for(unsigned k=0;k<3;k++){
   v[k]=(Vtx){0,0,(int)(random64()&255),(int)(random64()&255),(int)(random64()&255),(int)(random64()&255),(int)(random64()&255)};
   tri.p[k]=(WorldFinePoint){(int64_t)(random64()%(96*65536))-16*65536,(int64_t)(random64()%(96*65536))-16*65536};
  }
  if(j<2||j==5){
   const int corners[4][2]={{4,6},{52,6},{4,50},{52,50}};const int ids[2][3]={{0,1,2},{1,3,2}};
   for(unsigned k=0;k<3;k++){unsigned id=ids[j==1][k];tri.p[k]=(WorldFinePoint){corners[id][0]*65536ll+16384,corners[id][1]*65536ll+32768};v[k].r=81;v[k].gr=123;v[k].b=207;v[k].u=(id&1)?255:0;v[k].v=(id&2)?255:0;}
  }
  if(j==2){memcpy(previous,v,sizeof v);previous_tri=tri;}
  if(j==3){memcpy(v,previous,sizeof v);tri=previous_tri;Vtx t=v[1];v[1]=v[2];v[2]=t;WorldFinePoint p=tri.p[1];tri.p[1]=tri.p[2];tri.p[2]=p;}
  if(j==4)tri.p[2]=tri.p[1];
  if(j==6&&test%4==0)tri=(WorldFineTriangle){{{-1024ll*65536,-1024ll*65536},{1023ll*65536,1023ll*65536+1},{1023ll*65536+1,1023ll*65536+2}}};
  if(j==6&&test%4!=0){
   tri=(WorldFineTriangle){{{-1024ll*65536,-1024ll*65536},{1023ll*65536+1,-1024ll*65536+7},{3,1023ll*65536+11}}};
   const unsigned color[3][5]={{15,231,79,0,255},{201,13,240,255,0},{72,114,5,127,191}};
   for(unsigned k=0;k<3;k++){v[k].r=color[k][0];v[k].gr=color[k][1];v[k].b=color[k][2];v[k].u=color[k][3];v[k].v=color[k][4];}
   WorldFinePoint visible={32*65536ll,32*65536ll};
   assert(world_edge(tri.p[0],tri.p[1],tri.p[2])*(int64_t)scale*scale>(1ll<<55));
   assert(world_edge(tri.p[0],tri.p[1],visible)>0&&world_edge(tri.p[1],tri.p[2],visible)>0&&world_edge(tri.p[2],tri.p[0],visible)>0);
  }
  if(j==7)for(unsigned k=1;k<3;k++){v[k].u=v[0].u;v[k].v=v[0].v;if(test%3==0)v[k].r=v[0].r;}
  fine_uv_polygon(v,3);A2FineParams *p=&cmds[j].params;
  for(unsigned k=0;k<3;k++)p->p[k]=(A2FineVertex){tri.p[k].x*scale,tri.p[k].y*scale,v[k].r,v[k].gr,v[k].b,v[k].u,v[k].v,0};
  p->clip[0]=g.dax1*scale;p->clip[1]=g.day1*scale;p->clip[2]=(g.dax2+1)*scale-1;p->clip[3]=(g.day2+1)*scale-1;
  p->state[0]=cur_tpage;p->state[1]=cur_clut;p->state[2]=window;p->state[3]=gouraud|(tex<<1)|(semi<<2)|(filtered<<3);
  p->uv[0]=fine_uv_low[0];p->uv[1]=fine_uv_low[1];p->uv[2]=fine_uv_high[0];p->uv[3]=fine_uv_high[1];
  p->width=width;p->height=height;cmds[j].texture_version=version;
  raster_tri_world_fine(v[0],v[1],v[2],tri,gouraud,tex,semi,scale,NULL);
  assert(!memcmp(GPU_VRAM,textures[version],sizeof GPU_VRAM));
 }
 assert(render(cmds,8,&textures[0][0],width,height,gpu_ms));
 for(unsigned y=0;y<height;y++)for(unsigned x=0;x<width;x++){
  size_t k=(size_t)y*width+x,s=(size_t)y*IR_W+x;
  if(actual555[k]!=SHADOW[s]||actual_rgb[k]!=SHADOW_RGB[s]){
   fprintf(stderr,"IR%d case%u pixel%u,%u GPU555=%04x CPU555=%04x GPUrgb=%08x CPUrgb=%08x\n",scale,test,x,y,actual555[k],SHADOW[s],actual_rgb[k],SHADOW_RGB[s]);return 0;
  }
 }
 return 1;
}
int main(int argc,char **argv){
 setenv("A2_COLOR_PRECISION","1",1);setenv("A2_IRSCALE","2",1);
 size_t page=(size_t)sysconf(_SC_PAGESIZE);
 assert(!posix_memalign((void **)&actual555,page,256*256*2));
 assert(!posix_memalign((void **)&actual_rgb,page,256*256*4));
 unsigned cases=argc>1?(unsigned)atoi(argv[1]):256;if(cases>256)cases=256;
 unsigned count=0;double milliseconds=0;
 for(int scale=2;scale<=4;scale++)for(unsigned test=0;test<cases;test++){
  double ms=0;if(!run_case(scale,test,&ms)){a2_fine_gpu_destroy(metal);return 1;}count++;milliseconds+=ms;
 }
 a2_fine_gpu_destroy(metal);free(actual555);free(actual_rgb);
 printf("{\"surface_cases\":%u,\"triangles\":%u,\"mismatches\":0,\"gpu_total_ms\":%.6f,\"scope\":\"H30 full 555/RGB888 CPU surfaces, H31 local region pool\"}\n",count,count*8,milliseconds);
}
