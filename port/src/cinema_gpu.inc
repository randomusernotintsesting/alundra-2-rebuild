/* Private GPU presentation implementation; included by gpu.c only. */
#include "cinema_gpu.h"
enum { CINEMA_WIDTH=320,CINEMA_EXTRA=22,CINEMA_ROWS=172,CINEMA_TEXT=32 };
static int cinema_enabled,cinema_scale,cinema_scene=-1,cinema_text=-1;
static int cinema_ready[2],cinema_polygons[2];
static uint16_t *cinema_extra[2];
static uint8_t *cinema_alpha[2];
static int cinema_event(void) {return lw_(0x811d8)==5 && lw_(0x79e9c)==1;}
static int cinema_index(int y) {return y==0?0:y==256?1:-1;}
static void cinema_invalidate(void) {
    cinema_scene=cinema_text=-1;cinema_ready[0]=cinema_ready[1]=0;
}
static int cinema_selected_source(void) {
#ifdef A2_NATIVE_MESH
    /* Replacement color/depth currently covers the main picture only.
     * Fall back to its centered presentation for this event generation;
     * neither original source faces nor holes may enter the extra strips. */
    if(mesh_pixel_kind==A2_COMPOSITE_OWNED){cinema_invalidate();return 1;}
#endif
    return 0;
}
void gpu_set_cinema_expansion(int enabled) {
    enabled=enabled!=0;if(enabled==cinema_enabled)return;
    cinema_enabled=enabled;cinema_invalidate();
}
static int cinema_allocate(void) {
    int s=ir_init();if(cinema_scale==s && cinema_extra[0])return 1;
    uint16_t *extra[2]={0};uint8_t *alpha[2]={0};
    for(int i=0;i<2;i++) {
        extra[i]=calloc((size_t)320*44*s*s,sizeof *extra[i]);
        alpha[i]=calloc((size_t)320*32*s*s,sizeof *alpha[i]);
        if(!extra[i]||!alpha[i]) {
            for(int j=0;j<2;j++){free(extra[j]);free(alpha[j]);}
            cinema_invalidate();return 0;
        }
    }
    for(int i=0;i<2;i++) {
        free(cinema_extra[i]);free(cinema_alpha[i]);
        cinema_extra[i]=extra[i];cinema_alpha[i]=alpha[i];
    }
    cinema_scale=s;cinema_invalidate();return 1;
}
int gpu_cinema_expansion_ready(int buffer_y) {
    int i=cinema_index(buffer_y);
    if(!cinema_event()) {cinema_invalidate();return 0;}
    return cinema_enabled && i>=0 && cinema_scale==ir_init() && cinema_ready[i];
}
const uint16_t *gpu_cinema_extra_row(int buffer_y,int y) {
    if(!gpu_cinema_expansion_ready(buffer_y))return NULL;
    int s=cinema_scale,row;
    if(y>=-22*s && y<0)row=y+22*s;
    else if(y>=172*s && y<194*s)row=y-150*s;
    else return NULL;
    return cinema_extra[buffer_y/256]+(size_t)row*320*s;
}
const uint8_t *gpu_cinema_subtitle_alpha_row(int buffer_y,int y) {
    if(!gpu_cinema_expansion_ready(buffer_y)||y<0||y>=32*cinema_scale)return NULL;
    return cinema_alpha[buffer_y/256]+(size_t)y*320*cinema_scale;
}
static void cinema_area(void) {
    if(!cinema_enabled || !cinema_event()) {cinema_invalidate();return;}
    int i=cinema_index(g.day1);
    if(i<0||g.dax1!=0||g.dax2!=319||g.ofx!=0||g.ofy!=g.day1) {
        cinema_invalidate();return;
    }
    if(g.day2==g.day1+171) {
        if(!cinema_allocate())return;
        cinema_scene=i;cinema_text=-1;cinema_ready[i]=0;cinema_polygons[i]=0;
        memset(cinema_extra[i],0,(size_t)320*44*cinema_scale*cinema_scale*2);
        memset(cinema_alpha[i],0,(size_t)320*32*cinema_scale*cinema_scale);
    } else if(g.day2==g.day1+215) {
        if(cinema_scene==i && cinema_polygons[i])cinema_ready[i]=1;
        cinema_scene=-1;cinema_text=cinema_ready[i]?i:-1;
    } else cinema_invalidate();
}
static void cinema_vram_write(int x,int y,int w,int h) {
    if(!cinema_enabled)return;
    /* GP0 destinations wrap across VRAM boundaries. Conservatively discard
     * both presentation generations when the write has a wrapped part. */
    if(x<0||y<0||x+w>1024||y+h>512) {cinema_invalidate();return;}
    if(x>=320||x+w<=0)return;
    for(int i=0;i<2;i++)if(y<i*256+216&&y+h>i*256) {
        cinema_ready[i]=0;
        if(cinema_scene==i)cinema_scene=-1;
        if(cinema_text==i)cinema_text=-1;
    }
}
static uint16_t *cinema_destination(int i,int x,int y) {
    int s=cinema_scale;y-=i*256*s;
    if(x<0||x>=320*s)return NULL;
    int row;
    if(y>=-22*s&&y<0)row=y+22*s;
    else if(y>=172*s&&y<194*s)row=y-150*s;
    else return NULL;
    return cinema_extra[i]+(size_t)row*320*s+x;
}
static void cinema_line(Vtx a,Vtx b,int semi) {
    int i=cinema_scene;if(i<0)return;
    if(cinema_selected_source())return;
    int dx=b.x-a.x,dy=b.y-a.y,steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
    if(!steps)steps=1;if(steps>1024)return;
    int s=cinema_scale,fs=steps*s,inc=semi?s:1;
    for(int j=0;j<=fs;j+=inc) {
        int x=a.x*s+dx*s*j/fs,y=a.y*s+dy*s*j/fs;
        for(int yy=0;yy<s;yy++)for(int xx=0;xx<s;xx++) {
            uint16_t *dst=cinema_destination(i,x+xx,y+yy);
            if(dst)put_fine_external_pixel(dst,a.r,a.gr,a.b,semi,0,0,(cur_tpage>>5)&3);
        }
    }
}
static void cinema_rect(int x,int y,int w,int h,int u,int v,int red,int green,int blue,int semi,int tex) {
    int i=cinema_scene;
    /* Known full-screen colour/fade primitives act on the complete expanded
     * view. The separate subtitle-band clear is deliberately not a scene fill. */
    int full=!tex && x==0 && w==320 && (h==172||h==216);
    if(i<0 && cinema_text>=0 && full && y==cinema_text*256)i=cinema_text;
    if(i<0)return;
    if(cinema_selected_source())return;
    full=full&&y==i*256;
    int s=cinema_scale;
    for(int strip=0;strip<2;strip++) {
        int first=i*256+(strip?172:-22),last=first+22;
        if(!full) {if(first<y)first=y;if(last>y+h)last=y+h;}
        int x0=x>0?x:0,x1=x+w<320?x+w:320;
        for(int fy=first*s;fy<last*s;fy++)for(int fx=x0*s;fx<x1*s;fx++) {
            uint16_t pixel=tex?sample_tex_present(u+(fx-x*s)/s,v+(fy-y*s)/s):0;
            uint16_t *dst=cinema_destination(i,fx,fy);
            if(dst)put_fine_external_pixel(dst,red,green,blue,semi,tex,pixel,(cur_tpage>>5)&3);
        }
    }
}
static int cinema_span(int64_t weight,int64_t step,int owns,int *left,int *right) {
    int64_t threshold=owns?0:1;
    if(step>0 && weight<threshold) {
        int64_t first=(threshold-weight+step-1)/step;
        if(first>*right)return 0; /* A shallow Q16 edge can cross beyond INT_MAX. */
        if(first>*left)*left=(int)first;
    } else if(step<0) {
        if(weight<threshold)return 0;
        int64_t last=(weight-threshold)/-step;if(last<*right)*right=(int)last;
    } else if(!step && weight<threshold)return 0;
    return *left<=*right;
}
static int cinema_attribute(int64_t n0,int64_t n1,int64_t n2,
                             int a,int b,int c,int64_t area,int shift,int precise) {
    if(precise)return (int)((((__int128)n0*a+(__int128)n1*b+(__int128)n2*c)*((__int128)1<<shift))/area);
    return (int)(((n0*a+n1*b+n2*c)*((int64_t)1<<shift))/area);
}
static int cinema_floor(int64_t v,int64_t unit) {return (int)(v/unit-(v<0&&v%unit));}
static void cinema_triangle(Vtx a,Vtx b,Vtx c,int gouraud,int tex,int semi,
                             const WorldFineTriangle *precision) {
    int i=cinema_scene;if(i<0)return;
    if(cinema_selected_source())return;
    int minx=a.x,maxx=a.x,miny=a.y,maxy=a.y;
    const Vtx other[2]={b,c};
    for(int j=0;j<2;j++) {
        if(other[j].x<minx)minx=other[j].x;if(other[j].x>maxx)maxx=other[j].x;
        if(other[j].y<miny)miny=other[j].y;if(other[j].y>maxy)maxy=other[j].y;
    }
    if(maxx-minx>1024||maxy-miny>512)return;
    cinema_polygons[i]++;
    int s=cinema_scale;int64_t unit=precision?65536:1;
    WorldFinePoint p[3];const Vtx vertex[3]={a,b,c};
    for(int j=0;j<3;j++)p[j]=precision?
        (WorldFinePoint){precision->p[j].x*s,precision->p[j].y*s}:
        (WorldFinePoint){(int64_t)vertex[j].x*s,(int64_t)vertex[j].y*s};
    int64_t area=(p[1].x-p[0].x)*(p[2].y-p[0].y)-(p[1].y-p[0].y)*(p[2].x-p[0].x);
    if(!area)return;
    if(area<0) {area=-area;Vtx v=b;b=c;c=v;WorldFinePoint q=p[1];p[1]=p[2];p[2]=q;}
    int64_t lowx=p[0].x,highx=lowx,lowy=p[0].y,highy=lowy;
    for(int j=1;j<3;j++) {
        if(p[j].x<lowx)lowx=p[j].x;if(p[j].x>highx)highx=p[j].x;
        if(p[j].y<lowy)lowy=p[j].y;if(p[j].y>highy)highy=p[j].y;
    }
    int x0=cinema_floor(lowx,unit),x1=cinema_floor(highx,unit)+(precision?0:s-1);
    int y0=cinema_floor(lowy,unit),y1=cinema_floor(highy,unit)+(precision?0:s-1);
    if(x0<0)x0=0;if(x1>=320*s)x1=320*s-1;
    if(x0>x1)return;
    int64_t step[3];int own[3];
    for(int j=0;j<3;j++) {
        int k=(j+1)%3;step[j]=(p[j].y-p[k].y)*unit;
        own[j]=p[j].y>p[k].y||(p[j].y==p[k].y&&p[j].x<p[k].x);
    }
    int base=i*256*s;
    for(int strip=0;strip<2;strip++) {
        int first=base+(strip?172:-22)*s,last=first+22*s-1;
        if(first<y0)first=y0;if(last>y1)last=y1;
        for(int y=first;y<=last;y++) {
            int64_t weight[3];
            for(int j=0;j<3;j++) {
                int k=(j+1)%3;
                weight[j]=(p[k].x-p[j].x)*((int64_t)y*unit-p[j].y)
                         +(p[j].y-p[k].y)*((int64_t)x0*unit-p[j].x);
            }
            int left=0,right=x1-x0;
            if(!cinema_span(weight[0],step[0],own[0],&left,&right)||
               !cinema_span(weight[1],step[1],own[1],&left,&right)||
               !cinema_span(weight[2],step[2],own[2],&left,&right))continue;
            for(int j=0;j<3;j++)weight[j]+=step[j]*left;
            int row=y-base+(strip?-150*s:22*s);
            uint16_t *dst=cinema_extra[i]+(size_t)row*320*s+x0+left;
            for(int x=x0+left;x<=x0+right;x++,dst++) {
                int red=a.r,green=a.gr,blue=a.b;
                if(gouraud) {
                    red=cinema_attribute(weight[1],weight[2],weight[0],a.r,b.r,c.r,area,0,precision!=NULL);
                    green=cinema_attribute(weight[1],weight[2],weight[0],a.gr,b.gr,c.gr,area,0,precision!=NULL);
                    blue=cinema_attribute(weight[1],weight[2],weight[0],a.b,b.b,c.b,area,0,precision!=NULL);
                }
                uint16_t pixel=0;
                if(tex) {
                    int filtered=s>1&&filter_on(),shift=filtered?8:0;
                    int u=cinema_attribute(weight[1],weight[2],weight[0],a.u,b.u,c.u,area,shift,precision!=NULL);
                    int v=cinema_attribute(weight[1],weight[2],weight[0],a.v,b.v,c.v,area,shift,precision!=NULL);
                    pixel=filtered?sample_tex_fine(u-128,v-128):sample_tex_present(u,v);
                }
                put_fine_external_pixel(dst,red,green,blue,semi,tex,pixel,(cur_tpage>>5)&3);
                for(int j=0;j<3;j++)weight[j]+=step[j];
            }
        }
    }
}
static void cinema_alpha_put(int x,int y,unsigned alpha) {
    int i=cinema_text,s=cinema_scale;if(i<0||!alpha)return;
    if(x<g.dax1*s||x>=(g.dax2+1)*s||y<g.day1*s||y>=(g.day2+1)*s)return;
    y-=(i*256+174)*s;
    if(x<0||x>=320*s||y<0||y>=32*s)return;
    uint8_t *dst=cinema_alpha[i]+(size_t)y*320*s+x;
    *dst=(uint8_t)(alpha+((unsigned)*dst*(255-alpha)+127)/255);
}
static void cinema_caption_native(int x,int y,int w,int h,int u,int v) {
    int s=cinema_scale;
    for(int j=0;j<h;j++)for(int k=0;k<w;k++)if(sample_tex_present(u+k,v+j))
        for(int yy=0;yy<s;yy++)for(int xx=0;xx<s;xx++)cinema_alpha_put((x+k)*s+xx,(y+j)*s+yy,255);
}
#ifdef A2_HD_FONTS
static void cinema_caption_hd(int x,int y,int h,const A2HDGlyph *hd) {
    int s=cinema_scale;
    uint16_t ink=*vram_px((cur_clut&63)*16+3,(cur_clut>>6)&511);
    uint16_t shade=*vram_px((cur_clut&63)*16+1,(cur_clut>>6)&511);
    for(int j=0;j<h*s;j++)for(int k=0;k<12*s;k++) {
        if(shade)cinema_alpha_put(x*s+k,y*s+j,a2_hd_font_alpha(hd,k-1,j-1,s));
        if(ink)cinema_alpha_put(x*s+k,y*s+j,a2_hd_font_alpha(hd,k,j,s));
    }
}
#endif
