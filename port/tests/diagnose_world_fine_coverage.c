/* Read-only replay of captured tracked polygon coverage, no game/SDL/files
 * written. Build/run only outside the root's paced native measurements. */
#define main transport_test_main
#include "test_world_precision_gpu.c"
#undef main
#include <math.h>

typedef struct {uint32_t word;double x,y;} CapturedVertex;
typedef struct {unsigned frame;unsigned long long consumer;int complete,dx,dy,n;
                CapturedVertex v[4];} CapturedPrimitive;
static uint16_t before[1024*512*9];
static unsigned primitive_count,lost_total,gained_total;
static double largest_distance;

static double edge_distance(double x,double y,double ax,double ay,double bx,double by) {
    double dx=bx-ax,dy=by-ay,d=dx*dx+dy*dy;
    double t=d?((x-ax)*dx+(y-ay)*dy)/d:0;
    if(t<0)t=0;if(t>1)t=1;
    return hypot(x-ax-t*dx,y-ay-t*dy);
}
static void replay_coverage(CapturedPrimitive *p) {
    if(p->frame!=16996 || p->dx || p->dy || !p->complete || (p->n!=3&&p->n!=4))return;
    int nx[4],ny[4],minx=1024,miny=512,maxx=0,maxy=0;
    for(int i=0;i<p->n;i++) {
        nx[i]=sext11(p->v[i].word);ny[i]=sext11(p->v[i].word>>16);
        assert(nx[i]==(int16_t)p->v[i].word && ny[i]==(int16_t)(p->v[i].word>>16));
        if(nx[i]<minx)minx=nx[i];if(nx[i]>maxx)maxx=nx[i];
        if(ny[i]<miny)miny=ny[i];if(ny[i]>maxy)maxy=ny[i];
    }
    minx=(minx-2)*3;miny=(miny-2)*3;maxx=(maxx+2)*3;maxy=(maxy+2)*3;
    if(minx<0)minx=0;if(miny<0)miny=0;if(maxx>960)maxx=960;if(maxy>672)maxy=672;
    if(minx>=maxx || miny>=maxy)return;
    for(int enabled=0;enabled<=1;enabled++) {
        for(int y=miny;y<maxy;y++)memset(SHADOW+(size_t)y*3072+minx,0,(maxx-minx)*2);
        world_precision_configure(1);gpu_set_world_raster(enabled);
        uint64_t object=world_precision_begin_object();uint32_t dst[4],src[4],words[4];
        for(int i=0;i<p->n;i++) {
            world_precision_vertex value;words[i]=p->v[i].word;
            dst[i]=0x80090004+i*4;src[i]=0x1f800000+i*12;
            world_precision_gte_push(words[i],llround(p->v[i].x*65536),llround(p->v[i].y*65536),900,1);
            assert(world_precision_gte_read(14,words[i],&value));
            world_precision_record(src[i],words[i],object,&value);
        }
        assert(world_precision_emit(dst,words,src,p->n,object));
        gpu_gp0_at(p->n==4?0x280000f8:0x200000f8,0x80090000);
        for(int i=0;i<p->n;i++)gpu_gp0_at(words[i],dst[i]);
        assert(world_primitive_valid);
        if(!enabled)for(int y=miny;y<maxy;y++)
            memcpy(before+(size_t)y*3072+minx,SHADOW+(size_t)y*3072+minx,(maxx-minx)*2);
    }
    unsigned lost=0,gained=0;double max_distance=0;
    const unsigned quad_order[4]={0,1,3,2},tri_order[3]={0,1,2};
    const unsigned *order=p->n==4?quad_order:tri_order;
    for(int y=miny;y<maxy;y++)for(int x=minx;x<maxx;x++) {
        uint16_t a=before[(size_t)y*3072+x],b=SHADOW[(size_t)y*3072+x];
        gained+=!a&&b;
        if(!a||b)continue;
        lost++;double distance=1e9;
        for(int i=0;i<p->n;i++) {
            unsigned j=order[i],k=order[(i+1)%p->n];
            double d=edge_distance(x/3.0,y/3.0,nx[j],ny[j],nx[k],ny[k]);
            if(d<distance)distance=d;
        }
        if(distance>max_distance)max_distance=distance;
    }
    primitive_count++;lost_total+=lost;gained_total+=gained;
    if(max_distance>largest_distance)largest_distance=max_distance;
    printf("consumer=%llu coverage lost=%u gained=%u max_lost_distance=%.6f_native_px\n",
           p->consumer,lost,gained,max_distance);
}
int main(int argc,char **argv) {
    assert(argc==2);FILE *file=fopen(argv[1],"r");assert(file);
    gpu_set_ir(3);gpu_gp1(0);gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|319|(223<<10));
    CapturedPrimitive p={0};char line[1024];
    while(fgets(line,sizeof line,file)) {
        CapturedPrimitive next={0};int disp_x,disp_y;
        if(sscanf(line,"world-precision f=%u primitive consumer=%llu complete=%d draw_x=%d draw_y=%d disp_x=%d disp_y=%d",
                  &next.frame,&next.consumer,&next.complete,&next.dx,&next.dy,&disp_x,&disp_y)==7) {
            replay_coverage(&p);p=next;
        } else if(strstr(line," consume ") && p.complete && p.n<4) {
            char *word=strstr(line,"word="),*point=strstr(line,"xy=");
            assert(word&&point);
            assert(sscanf(word,"word=%x",&p.v[p.n].word)==1);
            assert(sscanf(point,"xy=%lf,%lf",&p.v[p.n].x,&p.v[p.n].y)==2);p.n++;
        }
    }
    replay_coverage(&p);fclose(file);
    printf("ROI x[0,320) y[0,224), per-primitive sums (not unique frame pixels): "
           "primitives=%u coverage_lost=%u gained=%u max_distance=%.9f_native_px\n",
           primitive_count,lost_total,gained_total,largest_distance);
    return 0;
}
