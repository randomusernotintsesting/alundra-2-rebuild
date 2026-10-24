/* Independent integer edge/interpolation/texture/blend oracle for the real
 * GP0 triangle parser. No SDL, guest execution, media or user data. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
static uint32_t random_state=0x91b4e72du;
static uint32_t random_word(void) {
    random_state^=random_state<<13;random_state^=random_state>>17;
    random_state^=random_state<<5;return random_state;
}
typedef struct {int x,y;unsigned channel[3],uv[2];} Point;
static unsigned reference_uv_min[2],reference_uv_max[2];
static void reference_polygon_region(const Point *p,unsigned count) {
    for(unsigned axis=0;axis<2;axis++) {
        reference_uv_min[axis]=255;reference_uv_max[axis]=0;
        for(unsigned i=0;i<count;i++) {
            if(p[i].uv[axis]<reference_uv_min[axis])reference_uv_min[axis]=p[i].uv[axis];
            if(p[i].uv[axis]>reference_uv_max[axis])reference_uv_max[axis]=p[i].uv[axis];
        }
    }
}
static int64_t edge(Point a,Point b,int x,int y) {
    return (int64_t)(b.x-a.x)*(y-a.y)-(int64_t)(b.y-a.y)*(x-a.x);
}
static int owns(Point a,Point b) {return a.y>b.y||(a.y==b.y&&a.x<b.x);}
static uint16_t source_texel(unsigned u,unsigned v,unsigned page,unsigned window) {
    unsigned coords[2]={u&255,v&255};
    for(unsigned a=0;a<2;a++) {
        unsigned mask=(window>>(a*5))&31,offset=(window>>(10+a*5))&31;
        for(unsigned bit=0;bit<5;bit++)if(mask&(1u<<bit))
            coords[a]=(coords[a]&~(1u<<(bit+3)))|(((offset>>bit)&1u)<<(bit+3));
    }
    unsigned mode=(page>>7)&3,bits=mode==0?4:mode==1?8:16;
    unsigned x=((page&15)*64+coords[0]*bits/16)&1023;
    unsigned y=(((page>>4)&1)*256+coords[1])&511;
    uint16_t word=GPU_VRAM[y*1024+x];
    if(bits==16)return word;
    unsigned index=(word>>(coords[0]*bits%16))&((1u<<bits)-1);
    return GPU_VRAM[480*1024+index];
}
/* Clamp each integer tap independently, before page/window address mapping.
 * Native nearest sampling remains entirely outside this filter rule. */
static uint16_t bounded_source_texel(int u,int v,unsigned page,unsigned window) {
    int coords[2]={u,v};
    for(unsigned axis=0;axis<2;axis++) {
        if(coords[axis]<(int)reference_uv_min[axis])coords[axis]=(int)reference_uv_min[axis];
        if(coords[axis]>(int)reference_uv_max[axis])coords[axis]=(int)reference_uv_max[axis];
    }
    return source_texel((unsigned)coords[0],(unsigned)coords[1],page,window);
}
/* Scalar four-tap oracle also exercises the fine triangle footprint cache:
 * separate bit-address reads and channel sums never use renderer helpers. */
static uint16_t source_filtered(int uf,int vf,unsigned page,unsigned window) {
    int u=uf/256-(uf<0&&uf%256!=0),v=vf/256-(vf<0&&vf%256!=0);
    unsigned fu=(unsigned)(uf-u*256),fv=(unsigned)(vf-v*256);
    uint16_t nearest=bounded_source_texel(u+(fu>=128),v+(fv>=128),page,window);
    if(!nearest)return 0;
    unsigned sums[3]={0},total=0;
    for(unsigned y=0;y<2;y++)for(unsigned x=0;x<2;x++) {
        uint16_t tap=bounded_source_texel(u+(int)x,v+(int)y,page,window);
        if(!tap)continue;
        unsigned weight=(x?fu:256-fu)*(y?fv:256-fv);total+=weight;
        for(unsigned c=0;c<3;c++)sums[c]+=((tap>>(5*c))&31)*weight;
    }
    if(!total)return nearest;
    uint16_t result=nearest&0x8000;
    for(unsigned c=0;c<3;c++)result|=(uint16_t)((sums[c]/total)<<(5*c));
    return result?result:nearest;
}
static uint16_t reference(Point p[3],int x,int y,uint16_t before,int textured,
                          int gouraud,int semi,unsigned page,unsigned window,int filtered) {
    int64_t area=edge(p[0],p[1],p[2].x,p[2].y);
    if(!area)return before;
    if(area<0){Point t=p[1];p[1]=p[2];p[2]=t;area=-area;}
    int64_t weights[3]={edge(p[1],p[2],x,y),edge(p[2],p[0],x,y),edge(p[0],p[1],x,y)};
    for(unsigned i=0;i<3;i++)
        if(weights[i]<0||(!weights[i]&&!owns(p[(i+1)%3],p[(i+2)%3])))return before;
    unsigned rgb[3];
    for(unsigned c=0;c<3;c++) {
        uint64_t sum=0;
        for(unsigned i=0;i<3;i++)sum+=(uint64_t)weights[i]*p[gouraud?i:0].channel[c];
        rgb[c]=(unsigned)(sum/(uint64_t)area);
    }
    uint16_t texel=0;
    if(textured) {
        unsigned uv[2];
        for(unsigned a=0;a<2;a++) {
            uint64_t sum=0;for(unsigned i=0;i<3;i++)sum+=(uint64_t)weights[i]*p[i].uv[a];
            uv[a]=(unsigned)(sum*(filtered?256:1)/(uint64_t)area);
        }
        texel=filtered?source_filtered((int)uv[0]-128,(int)uv[1]-128,page,window):source_texel(uv[0],uv[1],page,window);
        if(!texel)return before;
        for(unsigned c=0;c<3;c++) {
            rgb[c]=rgb[c]*(((texel>>(c*5))&31)*8)/128;
            if(rgb[c]>255)rgb[c]=255;
        }
        if(!(texel&0x8000))semi=0;
    }
    uint16_t result=textured?(texel&0x8000):0;
    for(unsigned c=0;c<3;c++) {
        int channel=(int)rgb[c],background=((before>>(c*5))&31)*8;
        if(semi)switch((page>>5)&3) {
            case 0:channel=(background+channel)/2;break;
            case 1:channel=background+channel;break;
            case 2:channel=background-channel;break;
            default:channel=background+channel/4;break;
        }
        if(channel<0)channel=0;if(channel>255)channel=255;
        result|=(uint16_t)((channel/8)<<(c*5));
    }
    return result;
}
static void run_case(int scale,unsigned number,int filtered) {
    Point points[3];
    for(unsigned i=0;i<3;i++) {
        points[i].x=(int)(random_word()%96)-16;
        points[i].y=(int)(random_word()%96)-16;
        for(unsigned c=0;c<3;c++)points[i].channel[c]=random_word()&255;
        for(unsigned a=0;a<2;a++)points[i].uv[a]=random_word()&255;
    }
    if(number%17==0)points[2]=points[1];
    reference_polygon_region(points,3);
    int textured=number&1,gouraud=(number>>1)&1,semi=(number>>2)&1;
    unsigned mode=(number/8)%3,page=24|(mode<<7)|(((number/24)%4)<<5);
    unsigned window=number%3==0?0x735acu:0;
    int left=number%3==1?7:0,top=number%3==1?5:0,right=number%5==0?47:63,bottom=59;
    gpu_gp1(0);gpu_set_filter(filtered);
    gpu_gp0(0xe3000000|left|(top<<10));gpu_gp0(0xe4000000|right|(bottom<<10));
    gpu_gp0(0xe1000000|page);gpu_gp0(0xe2000000|window);
    for(int y=0;y<64;y++)for(int x=0;x<64;x++)
        GPU_VRAM[y*1024+x]=(uint16_t)(x*97+y*59+0x9243);
    if(scale>1)for(int y=0;y<64*scale;y++)for(int x=0;x<64*scale;x++)
        SHADOW[y*IR_W+x]=(uint16_t)(x*97+y*59+0x9243);
    unsigned cmd=0x20|(textured?4:0)|(gouraud?16:0)|(semi?2:0);
    for(unsigned i=0;i<3;i++) {
        if(!i||gouraud)gpu_gp0((!i?cmd<<24:0)|points[i].channel[0]|
            (points[i].channel[1]<<8)|(points[i].channel[2]<<16));
        gpu_gp0((uint16_t)points[i].x|((uint32_t)(uint16_t)points[i].y<<16));
        if(textured)gpu_gp0(points[i].uv[0]|(points[i].uv[1]<<8)|
            (i==0?480u<<22:i==1?page<<16:0));
    }
    /* Texture/CLUT pages are outside this 64x64 target, so the independent
     * oracle can read the same immutable source while checking native VRAM.
     * Native sampling stays nearest even when the fine filter is enabled. */
    for(int y=0;y<64;y++)for(int x=0;x<64;x++) {
        uint16_t before=(uint16_t)(x*97+y*59+0x9243),wanted=before;
        if(x>=left&&x<=right&&y>=top&&y<=bottom) {
            Point copy[3];memcpy(copy,points,sizeof copy);
            wanted=reference(copy,x,y,before,textured,gouraud,semi,page,window,0);
        }
        uint16_t got=GPU_VRAM[y*1024+x];
        if(got!=wanted) {
            fprintf(stderr,"native case%u IR%d pixel%d,%d got%04x expected%04x\n",number,scale,x,y,got,wanted);abort();
        }
    }
    if(scale==1)return;
    for(unsigned i=0;i<3;i++){points[i].x*=scale;points[i].y*=scale;}
    for(int y=0;y<64*scale;y++)for(int x=0;x<64*scale;x++) {
        uint16_t before=(uint16_t)(x*97+y*59+0x9243),wanted=before;
        if(x>=left*scale&&x<(right+1)*scale&&y>=top*scale&&y<(bottom+1)*scale) {
            Point copy[3];memcpy(copy,points,sizeof copy);
            wanted=reference(copy,x,y,before,textured,gouraud,semi,page,window,filtered);
        }
        uint16_t got=SHADOW[y*IR_W+x];
        if(got!=wanted) {
            fprintf(stderr,"case%u IR%d pixel%d,%d got%04x expected%04x\n",number,scale,x,y,got,wanted);abort();
        }
    }
}
int main(void) {
    for(unsigned i=0;i<1024*512;i++)GPU_VRAM[i]=(uint16_t)random_word();
    for(unsigned i=0;i<256;i++)GPU_VRAM[480*1024+i]=i%5?((uint16_t)random_word()):0;
    for(int scale=1;scale<=4;scale++) {
        gpu_set_ir(scale);
        for(int filtered=0;filtered<2;filtered++)for(unsigned i=0;i<192;i++)run_case(scale,i,filtered);
    }
    gpu_set_ir(1);
    puts("PASS: 1536 native and 1152 fine triangle oracles, clipping, winding, color, UV, CLUT and four blend modes");
    return 0;
}
