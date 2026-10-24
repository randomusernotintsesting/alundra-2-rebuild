/* Fine-only subpixel coverage using the real GP0 parser and provenance map.
 * Literal Q16 comes from core-diag3 Gate1 f16996 target consumers. */
#define main world_transport_existing_main
#include "test_world_precision_gpu.c"
#undef main

static const int ship_xy[8][2]={{153,67},{179,51},{181,84},{208,67},
                               {124,84},{152,104},{228,78},{188,107}};
static const int64_t ship_q16[8][2]={{10067584,4426240},{11788672,3403408},
    {11926912,5557744},{13641088,4426240},{8163904,5557744},
    {10020790,6816094},{14975250,5164056},{12341209,7031678}};
static const unsigned ship_faces[3][4]={{0,1,2,3},{4,0,5,2},{3,6,5,7}};
static uint16_t raster_native[1024*512],raster_fine[1024*512*16];

typedef struct {
    int x,y;
    int64_t qx,qy;
    uint32_t color;
    unsigned u,v;
} RasterPoint;

static uint32_t raster_pack(int x,int y) {return (uint16_t)x|((uint32_t)(uint16_t)y<<16);}
static int wedge_cross(int ax,int ay,int bx,int by,int x,int y) {
    return (bx-ax)*(y-ay)-(by-ay)*(x-ax);
}
static void raster_clear(int scale) {
    world_precision_configure(1);gpu_set_ir(scale);gpu_gp1(0);gpu_set_filter(0);
    memset(GPU_VRAM,0,sizeof GPU_VRAM);
    if(scale>1)memset(SHADOW,0,(size_t)1024*512*scale*scale*sizeof *SHADOW);
    gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|319|(223<<10));
    gpu_gp0(0x02ffffff);gpu_gp0(0);gpu_gp0(raster_pack(320,224));
}
static void raster_snapshot(int scale) {
    memcpy(raster_native,GPU_VRAM,sizeof raster_native);
    if(scale>1)memcpy(raster_fine,SHADOW,(size_t)1024*512*scale*scale*sizeof *SHADOW);
}
static void raster_unchanged(int scale,int fine) {
    assert(!memcmp(raster_native,GPU_VRAM,sizeof raster_native));
    if(fine && scale>1)
        assert(!memcmp(raster_fine,SHADOW,(size_t)1024*512*scale*scale*sizeof *SHADOW));
}
static void raster_submit(const RasterPoint *p,unsigned count,unsigned command,int missing) {
    uint32_t packet[16],source[4],dest[4],words[4],base=0x800b0000;
    unsigned length=0;int tex=(command>>2)&1,gou=(command>>4)&1;
    uint64_t object=world_precision_begin_object();
    packet[length++]=(command<<24)|(p[0].color&0xffffff);
    for(unsigned i=0;i<count;i++) {
        if(gou&&i)packet[length++]=p[i].color;
        words[i]=raster_pack(p[i].x,p[i].y);
        source[i]=0x1f800000+i*12;dest[i]=base+length*4;
        packet[length++]=words[i];
        if(tex)packet[length++]=p[i].u|(p[i].v<<8)|(i==1?0x01040000:0);
        world_precision_vertex value;
        world_precision_gte_push(words[i],p[i].qx,p[i].qy,900,1);
        assert(world_precision_gte_read(14,words[i],&value));
        world_precision_record(source[i],words[i],object,&value);
    }
    assert(world_precision_emit(dest,words,source,count,object));
    for(unsigned i=0;i<length;i++) {
        if(missing>=0 && base+i*4==dest[missing])gpu_gp0(packet[i]);
        else gpu_gp0_at(packet[i],base+i*4);
    }
    assert(world_primitive_valid==(missing<0));
}
static RasterPoint raster_point(int x,int y,int fraction,uint32_t color) {
    RasterPoint p={x,y,(int64_t)x*65536+fraction,(int64_t)y*65536+fraction,color,0,0};
    return p;
}
static void rectangle(int scale,int reversed,int translated,int clipping) {
    RasterPoint p[4];
    const int dx[4]={0,4,0,4},dy[4]={0,0,4,4};
    int bx=translated?-2:1,by=translated?-1:1;
    for(unsigned i=0;i<4;i++)p[i]=raster_point(bx+dx[i],by+dy[i],16384,0);
    if(reversed) {RasterPoint point=p[1];p[1]=p[2];p[2]=point;}
    for(int enabled=0;enabled<=1;enabled++) {
        raster_clear(scale);gpu_set_world_raster(enabled);
        if(translated)gpu_gp0(0xe5000000|3|(2<<11));
        if(clipping) {
            gpu_gp0(0xe3000000|(clipping==2?5:2)|(2<<10));
            gpu_gp0(0xe4000000|(clipping==2?2:4)|(4<<10));
        }
        raster_submit(p,4,0x2a,-1);
        if(!enabled)raster_snapshot(scale);else raster_unchanged(scale,0);
        if(!enabled)continue;
        /* Hand-derived integer sample ownership for [1.25,5.25)^2.
         * IR1 stays native [1,5), including its original top/left edge. */
        const int first[5]={0,1,3,4,5},last[5]={0,5,11,16,21};
        for(int y=0;y<8*scale;y++)for(int x=0;x<8*scale;x++) {
            int inside=x>=first[scale]&&x<last[scale]&&y>=first[scale]&&y<last[scale];
            if(clipping)inside=inside&&x>=2*scale&&x<5*scale&&y>=2*scale&&y<5*scale;
            if(clipping==2)inside=0;
            assert(gpu_display_px(x,y)==(inside?0x3def:0x7fff));
        }
    }
}
static void integer_texture_equivalence(int scale,int semi,int filter,int reversed) {
    RasterPoint p[4]={raster_point(1,1,0,0x4080c0),raster_point(7,1,0,0xc04080),
                      raster_point(1,7,0,0x80c040),raster_point(7,7,0,0x808080)};
    p[1].u=p[3].u=4;p[2].v=p[3].v=4;
    if(reversed) {RasterPoint point=p[1];p[1]=p[2];p[2]=point;}
    for(int enabled=0;enabled<=1;enabled++) {
        raster_clear(scale);gpu_set_world_raster(enabled);gpu_set_filter(filter);
        for(int v=0;v<5;v++)for(int u=0;u<5;u++)
            GPU_VRAM[v*1024+256+u]=(u==v)?0:(uint16_t)(0x001f|(u*5<<5)|(v*6<<10)|((u&1)?0x8000:0));
        raster_submit(p,4,semi?0x3e:0x3c,-1);
        if(!enabled)raster_snapshot(scale);else raster_unchanged(scale,1);
    }
}
static void fractional_attribute_translation(int semi,int filter,int reversed) {
    const int scale=4;
    RasterPoint p[4]={raster_point(1,1,0,0x4080c0),raster_point(7,1,0,0xc04080),
                      raster_point(1,7,0,0x80c040),raster_point(7,7,0,0x808080)};
    p[1].u=p[3].u=4;p[2].v=p[3].v=4;
    if(reversed) {RasterPoint point=p[1];p[1]=p[2];p[2]=point;}
    for(int enabled=0;enabled<=1;enabled++) {
        raster_clear(scale);gpu_set_world_raster(enabled);gpu_set_filter(filter);
        for(int v=0;v<5;v++)for(int u=0;u<5;u++)
            GPU_VRAM[v*1024+256+u]=(u==v)?0:(uint16_t)(0x001f|(u*5<<5)|(v*6<<10)|((u&1)?0x8000:0));
        if(enabled)for(int i=0;i<4;i++) {p[i].qx+=16384;p[i].qy+=32768;}
        raster_submit(p,4,semi?0x3e:0x3c,-1);
        if(!enabled)raster_snapshot(scale);
        else {
            raster_unchanged(scale,0);
            /* Uniform (+1/4,+1/2) native translation is exactly(+1,+2)
             * fine pixels atIR4. UV/color/STP must translate with coverage. */
            for(int y=0;y<10*scale;y++)for(int x=0;x<10*scale;x++) {
                uint16_t expected=(x>=1&&y>=2)?raster_fine[(y-2)*1024*scale+x-1]:0x7fff;
                assert(gpu_display_px(x,y)==expected);
            }
        }
    }
}
static void texture_mask_anchors(int scale) {
    RasterPoint p[4]={raster_point(1,1,16384,0x808080),raster_point(5,1,16384,0x808080),
                      raster_point(1,5,16384,0x808080),raster_point(5,5,16384,0x808080)};
    const uint16_t texels[]={0,0x001f,0x801f,0x8000};
    const uint16_t expected[]={0x7fff,0x001f,0xbdff,0xbdef};
    for(unsigned t=0;t<4;t++) {
        for(int enabled=0;enabled<=1;enabled++) {
            raster_clear(scale);gpu_set_world_raster(enabled);
            GPU_VRAM[256]=texels[t];
            raster_submit(p,4,0x2f,-1); /* Raw textured semi quad, constant UV. */
            if(!enabled)raster_snapshot(scale);else raster_unchanged(scale,0);
            assert(gpu_display_px(3*scale,3*scale)==expected[t]);
        }
    }
}
static void exact_tjunction(int scale,int reversed,int mixed) {
    RasterPoint p[5]={raster_point(1,1,16384,0),raster_point(7,1,16384,0),
                      raster_point(1,5,16384,0),raster_point(7,5,16384,0),
                      raster_point(2,2,16384,0)};
    p[4].qx=2*65536+49152; /* M=(2.75,2.25), exactly1/4 along A→D. */
    const unsigned faces[3][3]={{0,1,3},{0,4,2},{4,3,2}};
    for(int enabled=0;enabled<=1;enabled++) {
        raster_clear(scale);gpu_set_world_raster(enabled);
        for(unsigned t=0;t<3;t++) {
            RasterPoint tri[3]={p[faces[t][0]],p[faces[t][1]],p[faces[t][2]]};
            if(reversed) {RasterPoint point=tri[1];tri[1]=tri[2];tri[2]=point;}
            raster_submit(tri,3,0x22,mixed&&t==1?0:-1);
        }
        if(!enabled)raster_snapshot(scale);else raster_unchanged(scale,scale==1);
        if(!enabled || scale==1)continue;
        const int first[5]={0,1,3,4,5},last_x[5]={0,7,15,22,29},last_y[5]={0,5,11,16,21};
        int wrong=0;
        for(int y=0;y<8*scale;y++)for(int x=0;x<10*scale;x++) {
            int inside=x>=first[scale]&&x<last_x[scale]&&y>=first[scale]&&y<last_y[scale];
            wrong+=gpu_display_px(x,y)!=(inside?0x3def:0x7fff);
        }
        if(mixed) {
            /* A release gate, not a promised property of primitive fallback:
             * adjacent unsupported faces still follow rounded boundaries. */
            fprintf(stderr,"IR%d mixed T-junction winding%d: %d boundary pixels differ\n",scale,reversed,wrong);
            assert(wrong>0);
        } else assert(wrong==0);
    }
}
static void fallback_equivalence(int scale,int mode) {
    RasterPoint p[4]={raster_point(1,1,16384,0x8080ff),raster_point(5,1,16384,0x8080ff),
                      raster_point(1,5,16384,0x8080ff),raster_point(5,5,16384,0x8080ff)};
    unsigned count=4,command=0x28;
    if(mode==1) { /* Native-zero first half; fractional geometry is not zero. */
        p[1]=raster_point(2,2,49152,0x8080ff);p[2]=raster_point(3,3,16384,0x8080ff);
        p[2].qy+=8192;
        p[3]=raster_point(5,4,16384,0x8080ff); /* Second half has native area. */
    }
    if(mode==2) { /* Native width1025 exceeds the existing reject threshold. */
        p[0]=raster_point(-1024,1,16384,0x8080ff);
        p[1]=raster_point(1,1,16384,0x8080ff);
        count=3;command=0x20;
    }
    for(int missing=0;missing<(mode==0?4:1);missing++)
        for(int enabled=0;enabled<=1;enabled++) {
            raster_clear(scale);gpu_set_world_raster(enabled);
            raster_submit(p,count,command,mode==0?missing:-1);
            if(!enabled)raster_snapshot(scale);
            else raster_unchanged(scale,mode!=1 || scale==1);
        }
}
static void ship_quad(unsigned face) {
    uint32_t src[4],dst[4],words[4],base=0x800a0000+face*32;
    uint64_t object=world_precision_begin_object();
    for(unsigned i=0;i<4;i++) {
        unsigned n=ship_faces[face][i];world_precision_vertex p;
        words[i]=raster_pack(ship_xy[n][0],ship_xy[n][1]);
        src[i]=0x1f800000+i*12;dst[i]=base+4+i*4;
        world_precision_gte_push(words[i],ship_q16[n][0],ship_q16[n][1],900,1);
        assert(world_precision_gte_read(14,words[i],&p));
        world_precision_record(src[i],words[i],object,&p);
    }
    assert(world_precision_emit(dst,words,src,4,object));
    gpu_gp0_at(0x280000f8,base);
    for(unsigned i=0;i<4;i++)gpu_gp0_at(words[i],dst[i]);
    assert(world_primitive_valid);
}
static void captured_wedge(int scale) {
    for(int enabled=0;enabled<=1;enabled++) {
        raster_clear(scale);gpu_set_world_raster(enabled);
        gpu_gp0(0x02f80000);gpu_gp0(0);gpu_gp0(raster_pack(320,224));
        for(unsigned q=0;q<3;q++)ship_quad(q);
        int gaps=0,total=0;
        for(int y=67*scale;y<104*scale;y++)for(int x=152*scale;x<208*scale;x++) {
            if(wedge_cross(152*scale,104*scale,208*scale,67*scale,x,y)<0 &&
               wedge_cross(208*scale,67*scale,181*scale,84*scale,x,y)<0 &&
               wedge_cross(181*scale,84*scale,152*scale,104*scale,x,y)<0) {
                total++;gaps+=gpu_display_px(x,y)==0x7c00;
            }
        }
        fprintf(stderr,"IR%d retained tracked wedge raster%d: %d/%d uncovered\n",scale,enabled,gaps,total);
        assert(total>0);
        if(enabled && scale>1)assert(gaps==0);else assert(gaps==total);
        if(!enabled)raster_snapshot(scale);else raster_unchanged(scale,scale==1);
    }
}
/* Retained model801AEC88 face29 (indices50/48/51/52) and face33
 * (50/52/54) share ORIGINAL edge50–52. Object7240141's f16994 records
 * give these literal Q16 values; f16996 consumes face33 atF79E4 and
 * face29 atF7904. Before far-triangle transport, only face29 was tracked. */
static void captured_quad_triangle_boundary(int scale,int mixed,int reversed) {
    RasterPoint p[5]={
        {152,149,9962116,9816406,0,0,0},
        {184,125,12097768,8230946,0,0,0},
        {191,143,12530932,9383230,0,0,0},
        {181,151,11871496,9902436,0,0,0},
        {185,162,12187408,10662574,0,0,0}};
    for(int enabled=0;enabled<=1;enabled++) {
        RasterPoint quad[4]={p[0],p[1],p[3],p[2]},tri[3]={p[0],p[3],p[4]};
        if(reversed) {
            RasterPoint value=quad[1];quad[1]=quad[2];quad[2]=value;
            value=tri[1];tri[1]=tri[2];tri[2]=value;
        }
        raster_clear(scale);gpu_set_world_raster(enabled);
        raster_submit(tri,3,0x22,mixed?0:-1);
        raster_submit(quad,4,0x2a,-1);
        if(!enabled)raster_snapshot(scale);else raster_unchanged(scale,scale==1);
        if(!enabled || scale==1)continue;
        int wrong=0;
        /* Independent scanline oracle for the five-vertex exterior. Its
         * concave outline excludes the shared edge entirely: any hole or
         * second blend there is wrong, without borrowing triangle edges. */
        for(int y=120*scale;y<166*scale;y++)for(int x=148*scale;x<196*scale;x++) {
            int inside=0;
            long double sx=(long double)x*65536/scale,sy=(long double)y*65536/scale;
            for(unsigned i=0,j=4;i<5;j=i++) {
                if((p[i].qy>sy)!=(p[j].qy>sy)) {
                    long double intersection=p[i].qx+
                        (sy-p[i].qy)*(p[j].qx-p[i].qx)/(p[j].qy-p[i].qy);
                    if(sx<intersection)inside=!inside;
                }
            }
            wrong+=gpu_display_px(x,y)!=(inside?0x3def:0x7fff);
        }
        fprintf(stderr,"IR%d captured quad29/triangle33 mixed%d winding%d: %d boundary pixels differ\n",
                scale,mixed,reversed,wrong);
        if(mixed)assert(wrong>0);else assert(wrong==0);
    }
}
int main(void) {
    assert(!world_raster_enabled); /* Separate opt-in, not metadata activation. */
    for(int scale=1;scale<=4;scale++) {
        captured_wedge(scale);
        for(int reversed=0;reversed<=1;reversed++)for(int translated=0;translated<=1;translated++)
            for(int clipping=0;clipping<=2;clipping++)rectangle(scale,reversed,translated,clipping);
        for(int semi=0;semi<=1;semi++)for(int filter=0;filter<=1;filter++)
            for(int reversed=0;reversed<=1;reversed++)
                integer_texture_equivalence(scale,semi,filter,reversed);
        texture_mask_anchors(scale);
        for(int reversed=0;reversed<=1;reversed++)for(int mixed=0;mixed<=1;mixed++)
            exact_tjunction(scale,reversed,mixed);
        for(int mode=0;mode<3;mode++)fallback_equivalence(scale,mode);
        for(int mixed=0;mixed<=1;mixed++)for(int reversed=0;reversed<=1;reversed++)
            captured_quad_triangle_boundary(scale,mixed,reversed);
    }
    for(int semi=0;semi<=1;semi++)for(int filter=0;filter<=1;filter++)
        for(int reversed=0;reversed<=1;reversed++)fractional_attribute_translation(semi,filter,reversed);
    puts("PASS: captured fine seams, exact shared-edge ownership, native equality, texture/Gouraud and complete fallback");
    return 0;
}
