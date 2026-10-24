#include "native_mesh_live.h"
#include "native_mesh_scene.h"
#include "native_mesh_submission.h"
#include "native_flint.h"
#include "native_actor_source_layout.h"
#include "world_precision.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    uint32_t clear_frame;
    int clean,started,pending,published,shown,x,y,w,h,scale,view_height;
    size_t owner_count;
    uint64_t owners[A2_ACTOR_PACKET_OWNER_LIMIT];
    A2MeshComposite *composite;
} LivePage;
static LivePage pages[2];
static LivePage *current;
enum { LIVE_MODELS=2 };
static A2NativeModel *models[LIVE_MODELS];
static unsigned model_count;
static A2MeshSubmission submission;
void a2_mesh_live_dma_begin(const uint8_t *ram,size_t bytes,uint32_t head,uint64_t words,int linked){
    if(a2_mesh_live_enabled)a2_mesh_submission_begin(&submission,ram,bytes,head,words,linked);
}
void a2_mesh_live_dma_end(void){a2_mesh_submission_end(&submission);}
static A2MeshScene *scene;
static unsigned scene_scale;
static uint8_t *rgba,*coverage;
static uint16_t *color,*row;
static float *depth;
static uint32_t *owner_tags;
static int selected;
static uint64_t prepared,published,rejected,displayed;
static uint64_t draw_failed,surface_failed,compose_failed[6],lifetime_failed;
static uint32_t trace_first_frame=UINT32_MAX;
static unsigned transition_lines;
enum { TRANSITION_TRACE_LIMIT = 32768 };
extern uint32_t psx_frame_no;
int a2_mesh_live_enabled,a2_mesh_live_active,a2_mesh_live_writes_watched,a2_mesh_live_failed;
int a2_mesh_live_x0,a2_mesh_live_y0,a2_mesh_live_x1,a2_mesh_live_y1;
static void trace_page(uint32_t frame,const LivePage *p,const char *event,const char *source,int complete){
    if(!a2_mesh_live_enabled||frame<trace_first_frame||transition_lines>=TRANSITION_TRACE_LIMIT)return;
    ++transition_lines;
    fprintf(stderr,"nativemesh-transition: frame=%u event=%s source=%s page=%u clear=%u clean=%d started=%d pending=%d published=%d owners=%zu complete=%d line=%u limit=%u\n",
        frame,event,source,(unsigned)(p-pages),p->clear_frame,p->clean,p->started,p->pending,p->published,p->owner_count,complete,transition_lines,(unsigned)TRANSITION_TRACE_LIMIT);
}
static void refresh_write_watch(void){
    a2_mesh_live_writes_watched=0;
    a2_mesh_live_enabled=selected;
    for(unsigned i=0;i<2;i++){
        const LivePage *p=&pages[i];
        if((p->clean&&!p->started)||p->pending||p->published){
            a2_mesh_live_writes_watched=a2_mesh_live_enabled=1;
        }
    }
}
void a2_mesh_live_set_enabled(int enabled){
    selected=!!enabled&&model_count!=0;
    /* The last complete front page retains its choice until overwritten.
     * New clears commit the requested choice to each new draw page. */
    refresh_write_watch();
}
static void fail(const char *reason){
    if(!a2_mesh_live_failed)fprintf(stderr,"nativemesh-fatal: frame=%u %s; presentation stopped, source models are not substituted\n",psx_frame_no,reason);
    a2_mesh_live_failed=1;a2_mesh_live_active=0;
}
static void retire(LivePage *p){
    p->pending=p->published=p->shown=p->clean=p->started=0;
    p->owner_count=0;
    p->x=p->y=p->w=p->h=0;
    if(p->composite)a2_mesh_composite_invalidate(p->composite);
    refresh_write_watch();
}
void a2_mesh_live_reset(void){
    a2_mesh_live_dma_end();
    for(unsigned i=0;i<2;i++){
        if(pages[i].clean||pages[i].pending||pages[i].published)trace_page(psx_frame_no,&pages[i],"reset","reset",-1);
        retire(&pages[i]);
    }current=NULL;a2_mesh_live_active=0;a2_mesh_live_failed=0;
}
void a2_mesh_live_close(void){
    a2_mesh_live_reset();
    for(unsigned i=0;i<2;i++)a2_mesh_composite_destroy(pages[i].composite);
    memset(pages,0,sizeof pages);a2_mesh_scene_destroy(scene);scene=NULL;scene_scale=0;
    for(unsigned i=0;i<model_count;i++){a2_native_model_destroy(models[i]);models[i]=NULL;}
    model_count=0;
    free(rgba);free(coverage);free(color);free(depth);free(row);rgba=coverage=NULL;color=row=NULL;depth=NULL;
    free(owner_tags);owner_tags=NULL;
    if(a2_mesh_live_enabled)fprintf(stderr,"nativemesh: prepared=%llu published=%llu rejected=%llu\n",
        (unsigned long long)prepared,(unsigned long long)published,(unsigned long long)rejected);
    if(a2_mesh_live_enabled)fprintf(stderr,"nativemesh-display: frames=%llu\n",(unsigned long long)displayed);
    if(a2_mesh_live_enabled)fprintf(stderr,"nativemesh-reasons: draw=%llu surface=%llu lifetime=%llu compose=%llu,%llu,%llu,%llu,%llu,%llu\n",
        (unsigned long long)draw_failed,(unsigned long long)surface_failed,(unsigned long long)lifetime_failed,
        (unsigned long long)compose_failed[0],(unsigned long long)compose_failed[1],(unsigned long long)compose_failed[2],
        (unsigned long long)compose_failed[3],(unsigned long long)compose_failed[4],(unsigned long long)compose_failed[5]);
    selected=a2_mesh_live_enabled=0;
}
int a2_mesh_live_open(A2Resources *store,int language){
    a2_mesh_live_close();char error[256];
    static const char *const names[LIVE_MODELS]={"T02","PC00"};
    for(unsigned i=0;i<LIVE_MODELS;i++){
        char path[64];snprintf(path,sizeof path,"MODELS/%s.A2M",names[i]);
        A2ResourceId id=a2_resource_find(store,language,path);
        if(!id)continue;
        A2NativeModel *m=NULL;
        if(!a2_native_model_load(store,id,&m,error,sizeof error)||strcmp(m->source_key,names[i])){
            fprintf(stderr,"nativemesh: cannot load %s (%s)\n",path,m?"resource identity mismatch":error);
            a2_native_model_destroy(m);a2_mesh_live_close();return 0;
        }
        models[model_count++]=m;
        fprintf(stderr,"nativemesh-resource: key=%s vertices=%u triangles=%u joints=%u\n",m->source_key,m->vertex_count,m->index_count/3,m->joint_count);
    }
    if(!model_count)return 0;
    selected=a2_mesh_live_enabled=1;prepared=published=rejected=displayed=draw_failed=surface_failed=lifetime_failed=0;
    const char *trace=getenv("A2_MESH_TRACE");
    trace_first_frame=trace?(uint32_t)strtoul(trace,NULL,10):UINT32_MAX;transition_lines=0;
    memset(compose_failed,0,sizeof compose_failed);return 1;
}
static int storage(unsigned scale){
    if(scene&&scene_scale==scale)return 1;
    for(unsigned i=0;i<2;i++){
        retire(&pages[i]);a2_mesh_composite_destroy(pages[i].composite);pages[i].composite=NULL;
    }
    a2_mesh_scene_destroy(scene);scene=NULL;scene_scale=0;
    free(rgba);free(coverage);free(color);free(depth);free(row);rgba=coverage=NULL;color=row=NULL;depth=NULL;
    free(owner_tags);owner_tags=NULL;
    size_t n=(size_t)320*216*scale*scale;
    rgba=malloc(n*4);coverage=malloc(n);color=malloc(n*2);depth=malloc(n*sizeof(float));row=malloc((size_t)1024*scale*2);
    owner_tags=malloc(n*sizeof *owner_tags);
    if(!rgba||!coverage||!color||!depth||!row)return 0;
    if(!owner_tags)return 0;
    char error[256];scene=a2_mesh_scene_create(320*scale,216*scale,error,sizeof error);
    if(!scene)return 0;
    for(unsigned i=0;i<model_count;i++)if(!a2_mesh_scene_add(scene,models[i]))return 0;
    for(unsigned i=0;i<2;i++){
        pages[i].composite=a2_mesh_composite_create(320*scale,216*scale);
        if(!pages[i].composite)return 0;
    }
    scene_scale=scale;return 1;
}
void a2_mesh_live_clear(uint32_t frame,int scale,int x,int y,int w,int h){
    if(scale<1||scale>4)return;
    /* Storage is established at clear so initialization cannot erase the
     * very clean-background proof used by the first world command. */
    if((y==0||y==256)&&x==0&&w==320&&h>=216&&h<=256){
        if(!selected){retire(&pages[y/256]);current=NULL;a2_mesh_live_active=0;return;}
        if(!storage((unsigned)scale)){fail("model surface allocation failed");return;}
        LivePage *p=&pages[y/256];retire(p);p->clean=1;p->clear_frame=frame;p->scale=scale;
        p->view_height=h<216?h:216;
        current=NULL;a2_mesh_live_active=0;refresh_write_watch();
        trace_page(frame,p,"clear","gp0-clear",-1);
    }else a2_mesh_live_invalidate_rect(x*scale,y*scale,w*scale,h*scale);
}
static int signed11(uint32_t v){return (int)(v<<21)>>21;}
void a2_mesh_live_start(uint32_t frame,int scale,int page,const uint16_t *shadow,size_t stride,int wide){
    a2_mesh_live_start_view(frame,scale,page,shadow,stride,wide,216);
}
void a2_mesh_live_start_view(uint32_t frame,int scale,int page,const uint16_t *shadow,size_t stride,int wide,int view_height){
    a2_mesh_live_active=0;current=NULL;
    if(view_height!=172&&view_height!=216)return;
    if(!a2_mesh_live_enabled||!scene||scene_scale!=(unsigned)scale||(page!=0&&page!=256)||!shadow)return;
    LivePage *p=&pages[page/256];current=p;
    if(p->clean)for(unsigned i=0;i<model_count;i++)
        if(a2_native_actor_packets_source_failed(models[i]->source_key,models[i]->source_sha256)){
            fail("emitted selected source lost verified packet ownership");return;
        }
    if(p->clean)for(unsigned i=0;i<model_count;i++)if(!strcmp(models[i]->source_key,"PC00"))
        for(unsigned j=0;j<A2_ACTOR_SOURCE_COUNT;j++){
            const A2ActorSourceLayout *source=&a2_actor_source_layouts[j];
            if(!strcmp(source->key,"FRITTO")&&a2_native_actor_packets_source_failed(source->key,source->hash)){
                fail("emitted selected cinematic source lost verified packet ownership");return;
            }
        }
    if(p->started){
        a2_mesh_live_active=(p->pending||p->published)&&a2_mesh_composite_valid(p->composite);
        if(a2_mesh_live_active)p->pending=1;
        a2_mesh_live_x0=p->x;a2_mesh_live_y0=p->y;a2_mesh_live_x1=p->x+p->w;a2_mesh_live_y1=p->y+p->h;
        refresh_write_watch();return;
    }
    if(!p->clean)return; /* this draw page was cleared in Original mode */
    /* A VBlank may separate clear from the first polygon without changing
     * the background. Actual writes/reset/new clears retire this proof. */
    if(!p->clean){trace_page(frame,p,"start-dirty","polygon",-1);return;}
    const A2ActorPacketOwner *available[A2_ACTOR_PACKET_OWNER_LIMIT];
    const A2ActorPacketOwner *owners[A2_ACTOR_PACKET_OWNER_LIMIT];
    size_t available_count=a2_native_actor_packets_owners_latest(available,A2_ACTOR_PACKET_OWNER_LIMIT);
    /* A scene fade can submit new 2D lists while retaining the last actor
     * snapshot. Only owners actually present in this DMA may start a fresh
     * replacement page. Already-started pages still survive split/repeated
     * submissions and continue receiving the real fade/blit pixels. */
    if(submission.known){
        size_t used=0;
        for(size_t i=0;i<available_count;i++){
            const A2ActorPacket *packets[A2_ACTOR_PACKET_LIMIT];
            size_t n=a2_native_actor_packets_owner_packets(available[i]->handle,packets,A2_ACTOR_PACKET_LIMIT);
            int present=0;
            for(size_t j=0;j<n&&!present;j++){
                if(available[i]->instance.source_family==A2_ACTOR_EVENT00&&
                   !strcmp(available[i]->parts[0].source_key,"FRITTO")&&
                   !a2_flint_source_part_replaced(available[i],packets[j]->source_mesh_index))continue;
                present=a2_mesh_submission_contains(&submission,packets[j]);
            }
            if(present)available[used++]=available[i];
        }
        available_count=used;
    }
    /* Source recognition is broader than the currently loaded material
     * contract. Unsupported resources remain native; they must not enter
     * the suppression plan or cancel another instance's drawable mesh. */
    size_t count=a2_mesh_scene_plan(scene,available,available_count,
                                    owners,A2_ACTOR_PACKET_OWNER_LIMIT);
    if(!count){trace_page(frame,p,"start-no-owners","polygon",-1);return;}
    p->view_height=view_height;p->started=1;refresh_write_watch();
    trace_page(frame,p,"start-owners","polygon",-1);
    ++prepared;
    size_t n=(size_t)320*216*scale*scale;
    if(!a2_mesh_scene_draw(scene,owners,count,(unsigned)scale,wide,rgba,n*4,depth,n*sizeof(float))||
       !a2_mesh_scene_read_owners(scene,owner_tags,n*sizeof *owner_tags)){
        ++rejected;++draw_failed;trace_page(frame,p,"start-draw-failed","scene",-1);fail("model pose/render/readback failed");return;
    }
    int width=320*scale,height=216*scale,view_pixels=p->view_height*scale,x0=width,y0=height,x1=-1,y1=-1;
    for(int y=0;y<height;y++)for(int x=0;x<width;x++){
        size_t k=(size_t)y*width+x;unsigned alpha=rgba[k*4+3];
        if(y>=view_pixels){alpha=0;owner_tags[k]=0;}
        /* This bridge has exactly one opaque surface per pixel. */
        if(alpha!=0&&alpha!=255){++rejected;++surface_failed;trace_page(frame,p,"start-invalid-alpha","scene",-1);fail("non-opaque replacement surface");return;}
        coverage[k]=alpha!=0;
        color[k]=(uint16_t)((rgba[k*4]>>3)|((rgba[k*4+1]>>3)<<5)|((rgba[k*4+2]>>3)<<10));
        if(alpha){if(x<x0)x0=x;if(y<y0)y0=y;if(x>x1)x1=x;if(y>y1)y1=y;}
    }
    /* Include old-only silhouette: deleting original polygons must reveal
     * real background even where the new silhouette is narrower. */
    for(size_t i=0;i<count;i++){
        const A2ActorPacket *packets[A2_ACTOR_PACKET_LIMIT];
        size_t np=a2_native_actor_packets_owner_packets(owners[i]->handle,packets,A2_ACTOR_PACKET_LIMIT);
        if(!np){++rejected;++surface_failed;trace_page(frame,p,"start-no-packets","scene",-1);fail("selected source has no immutable packets");return;}
        for(size_t j=0;j<np;j++){
            const uint32_t *w=packets[j]->words+2;unsigned cmd=w[0]>>24,nv=(cmd&8)?4:3,at=1;
            for(unsigned v=0;v<nv;v++){
                if(v&&(cmd&16))at++;
                int x=signed11(w[at])*scale,y=signed11(w[at]>>16)*scale;
                world_precision_vertex refined;
                if(world_precision_packet(packets[j]->command_address+4*at,w[at],&refined)&&
                   isfinite(refined.x)&&isfinite(refined.y)&&refined.x>=-1024&&refined.x<1024&&refined.y>=-1024&&refined.y<1024){
                    int rx=(int)floor(refined.x*scale),ry=(int)floor(refined.y*scale);
                    if(rx<x0)x0=rx;if(ry<y0)y0=ry;if(rx>x1)x1=rx;if(ry>y1)y1=ry;
                }
                at++;
                if(cmd&4)at++;
                if(x<x0)x0=x;if(y<y0)y0=y;if(x>x1)x1=x;if(y>y1)y1=y;
            }
        }
    }
    /* Union includes both native and exact tracked Q16 endpoints. A single
     * fine cell covers inclusive raster endpoint rounding on either path. */
    x0--;y0--;x1++;y1++;
    if(x0<0)x0=0;if(y0<0)y0=0;if(x1>=width)x1=width-1;if(y1>=view_pixels)y1=view_pixels-1;
    if(x0>x1||y0>y1){x0=y0=0;x1=y1=-1;} /* fully clipped, still source-owned */
    int rw=x1-x0+1,rh=y1-y0+1;
    p->x=x0;p->y=y0+page*scale;p->w=rw;p->h=rh;p->owner_count=count;
    A2CompositeImage bg={shadow+(size_t)page*scale*stride,((size_t)(height-1)*stride+width)*2,stride*2};
    A2CompositeImage image={color,n*2,(size_t)width*2};
    A2CompositeImage z={depth,n*sizeof(float),(size_t)width*sizeof(float)};
    A2CompositeImage mask={coverage,n,(size_t)width};
    A2CompositeImage tags={owner_tags,n*sizeof *owner_tags,(size_t)width*sizeof *owner_tags};
    if(!a2_mesh_composite_begin(p->composite,1,bg,image,z,mask)||
       !a2_mesh_composite_owners(p->composite,tags,(unsigned)count)){
        ++rejected;++compose_failed[2];trace_page(frame,p,"start-invalid-composite","scene",-1);fail("invalid model composition inputs");return;
    }
    for(size_t i=0;i<count;i++)p->owners[i]=owners[i]->handle;
    p->pending=1;a2_mesh_live_active=1;refresh_write_watch();
    trace_page(frame,p,"start-ready","polygon",-1);
    a2_mesh_live_x0=p->x;a2_mesh_live_y0=p->y;a2_mesh_live_x1=p->x+p->w;a2_mesh_live_y1=p->y+p->h;
}
int a2_mesh_live_owns(uint64_t owner){
    if(current&&(current->pending||current->published))for(size_t i=0;i<current->owner_count;i++)if(current->owners[i]==owner)return 1;
    return 0;
}
int a2_mesh_live_claim(uint64_t owner){
    if(a2_mesh_live_owns(owner)){
        for(size_t i=0;i<current->owner_count;i++)if(current->owners[i]==owner)
            if(!a2_mesh_composite_anchor(current->composite,(unsigned)i+1))fail("invalid source insertion anchor");
        return 1;
    }
    /* Never turn a selected resource into native geometry because a plan
     * became incomplete. Unsupported resources keep their own original. */
    const A2ActorPacketOwner *o=a2_native_actor_packets_owner(owner);
    if(current&&current->clean&&o)for(unsigned i=0;i<model_count;i++)
        if((!strncmp(o->parts[0].source_key,models[i]->source_key,32)&&
           !memcmp(o->parts[0].source_sha256,models[i]->source_sha256,32))||
           (!strcmp(models[i]->source_key,"PC00")&&a2_flint_owner_supported(o,models[i]))){
            fail("selected source absent from draw-page plan");return 1;
        }
    return 0;
}
int a2_mesh_live_claim_part(uint64_t owner,unsigned source_part){
    const A2ActorPacketOwner *o=a2_native_actor_packets_owner(owner);
    /* Certain cutscenes attach additional props after the mapped body parts.
     * These have no replacement geometry and retain their original packets. */
    if(o&&o->instance.source_family==A2_ACTOR_EVENT00&&!strcmp(o->parts[0].source_key,"FRITTO")&&
       !a2_flint_source_part_replaced(o,source_part))return 0;
    return a2_mesh_live_claim(owner);
}
void a2_mesh_live_pixel(int x,int y,A2CompositePixel pixel){
    if(!a2_mesh_live_active||!current)return;
    if(x<current->x||x>=current->x+current->w||y<current->y||y>=current->y+current->h)return;
    int page=(current==&pages[1])?256:0;
    a2_mesh_composite_pixel(current->composite,x,y-page*current->scale,pixel);
    if(!a2_mesh_composite_valid(current->composite)){
        unsigned why=a2_mesh_composite_failure(current->composite);
        if(rejected<5)fprintf(stderr,"nativemesh-pixel-reject: why=%u xy=%d,%d kind=%u z=%.8g\n",why,x,y,(unsigned)pixel.kind,pixel.depth);
        trace_page(psx_frame_no,current,"pixel-reject","coverage",-1);
        fail("invalid model pixel composition");refresh_write_watch();
    }
}
uint16_t *a2_mesh_live_destination(int x,int y,A2CompositeKind kind,float depth){
    if(!a2_mesh_live_active||!current||!current->pending)return NULL;
    if(x<current->x||x>=current->x+current->w||y<current->y||y>=current->y+current->h)return NULL;
    int page=(current==&pages[1])?256:0;
    uint16_t *dst=a2_mesh_composite_destination(current->composite,x,y-page*current->scale,kind,depth);
    if(!a2_mesh_composite_valid(current->composite)){
        trace_page(psx_frame_no,current,"pixel-reject","hd-coverage",-1);
        fail("invalid model HD composition");refresh_write_watch();
    }
    return dst;
}
void a2_mesh_live_invalidate_rect(int x,int y,int w,int h){
    if(!a2_mesh_live_writes_watched||w<=0||h<=0)return;
    for(unsigned i=0;i<2;i++){
        LivePage *p=&pages[i];
        if((p->published||p->pending)&&x<p->x+p->w&&(int64_t)x+w>p->x&&
           y<p->y+p->h&&(int64_t)y+h>p->y){
            trace_page(psx_frame_no,p,"unhandled-write","write",-1);
            fail("presentation write missing its actual pixel value");
        }
    }
}
uint16_t a2_mesh_live_read(int x,int y,uint16_t original){
    if(!scene_scale)return original;
    int width=1024*(int)scene_scale,height=512*(int)scene_scale;
    x%=width;y%=height;if(x<0)x+=width;if(y<0)y+=height;
    for(unsigned i=0;i<2;i++){
        LivePage *p=&pages[i];
        if((p->published||p->pending)&&x>=p->x&&x<p->x+p->w&&y>=p->y&&y<p->y+p->h){
            const uint16_t *pixels=a2_mesh_composite_row(p->composite,(unsigned)(y-(int)i*256*p->scale),NULL);
            if(pixels)return pixels[x];
        }
    }
    return original;
}
void a2_mesh_live_store(int x,int y,uint16_t value){
    if(!scene_scale)return;
    int width=1024*(int)scene_scale,height=512*(int)scene_scale;
    x%=width;y%=height;if(x<0)x+=width;if(y<0)y+=height;
    for(unsigned i=0;i<2;i++){
        LivePage *p=&pages[i];
        if((p->published||p->pending)&&x>=p->x&&x<p->x+p->w&&y>=p->y&&y<p->y+p->h)
            a2_mesh_composite_store(p->composite,x,y-(int)i*256*p->scale,value);
    }
}
void a2_mesh_live_finalize_at(uint32_t frame,const char *source){
    if(!source)source="unspecified";
    for(unsigned i=0;i<2;i++){
        LivePage *p=&pages[i];if(!p->pending)continue;
        int valid=a2_mesh_composite_valid(p->composite);
        int complete=1;
        /* Completion is an audit of the current guest submission. It does
         * not revoke copied pose data or an already displayed model when a
         * VBlank splits DMA, or a later build reuses guest packet storage. */
        for(size_t j=0;j<p->owner_count;j++)if(!a2_native_actor_packets_owner_complete(p->owners[j]))complete=0;
        if(valid){p->published=1;++published;}
        else {++rejected;fail("invalid selected draw page");}
        trace_page(frame,p,valid?"finalize-publish":"finalize-error",source,complete);
        p->pending=0;
    }
    current=NULL;a2_mesh_live_active=0;refresh_write_watch();
}
void a2_mesh_live_finalize(void){
    a2_mesh_live_finalize_at(psx_frame_no,"unspecified");
}
const uint16_t *a2_mesh_live_row(int y,const uint16_t *original,size_t width){
    if(!a2_mesh_live_enabled||!row||width!=(size_t)1024*scene_scale)return original;
    for(unsigned i=0;i<2;i++){
        LivePage *p=&pages[i];
        if(p->published&&y>=p->y&&y<p->y+p->h){
            if(!p->shown){p->shown=1;++displayed;}
            const uint16_t *pixels=a2_mesh_composite_row(p->composite,(unsigned)(y-(int)i*256*p->scale),NULL);
            if(!pixels){fail("invalid selected display row");return original;}
            memcpy(row,original,width*2);memcpy(row+p->x,pixels+p->x,(size_t)p->w*2);return row;
        }
    }
    return original;
}
void a2_mesh_live_trace_display(uint32_t frame,int source_y){
    if(!a2_mesh_live_enabled||frame<trace_first_frame)return;
    fprintf(stderr,"nativemesh-compose: frame=%u dy=%d",frame,source_y);
    for(unsigned i=0;i<2;i++){
        const LivePage *p=&pages[i];
        fprintf(stderr," page%u=%u,%d,%d,%d,%d roi%u=%d,%d,%d,%d",i,
            p->clear_frame,p->published,p->pending,p->started,p->clean,i,p->x,p->y,p->w,p->h);
    }
    fputc('\n',stderr);
}
