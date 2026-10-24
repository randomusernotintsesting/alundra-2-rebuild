#include "frame_compose.h"
#include <stddef.h>
#include <string.h>
#ifdef A2_CINEMA_EXPANSION
#include "cinema_gpu.h"
int gpu_ir(void);
#endif

const uint16_t *gpu_display_row(int fy);
const uint32_t *gpu_display_argb_row(int fy);

int a2_gameplay_canvas(A2CinemaRaster *raster) {
    if(raster->overlay!=4 || raster->on!=1 || raster->dx!=0 ||
       (raster->dy!=0 && raster->dy!=256) || raster->dw!=320 || raster->dh!=216 ||
       raster->xo!=0 || raster->yo!=12 || raster->cw!=320 || raster->ch!=240)
        return 0;
    raster->yo=0;
    raster->ch=216;
    return 1;
}

int a2_frame_view(A2FrameView *out,int scale,
                  int dx,int dy,int dw,int dh,int xo,int yo,int cw,int ch) {
    if(!out)return 0;
    *out=(A2FrameView){0};
    if(scale<1||scale>4||cw<1||cw>1024||ch<1||ch>512||
       xo>0||yo>0||(int64_t)xo+dw<cw||(int64_t)yo+dh<ch)return 0;
    int source_w=1024*scale,source_h=512*scale;
    int width=cw*scale,height=ch*scale;
    int sx=(int)(((int64_t)dx-xo)*scale%source_w);
    int sy=(int)(((int64_t)dy-yo)*scale%source_h);
    if(sx<0)sx+=source_w;
    if(sy<0)sy+=source_h;
    if(sx+width>source_w||sy+height>source_h)return 0;
    const uint32_t *first=gpu_display_argb_row(sy);
    if(!first)return 0;
    uintptr_t address=(uintptr_t)first;
    size_t last=(size_t)(height-1)*source_w*sizeof *first;
    if(last>UINTPTR_MAX-address)return 0;
    /* Check actual row providers, including mesh overrides; never infer a
     * contiguous surface merely from the first row or display coordinates. */
    for(int y=1;y<height;y++)
        if((uintptr_t)gpu_display_argb_row(sy+y)!=address+(size_t)y*source_w*sizeof *first)return 0;
    *out=(A2FrameView){first+sx,width,height,source_w};
    return 1;
}

static void black(uint32_t *dst, int count) {
    for (int i=0; i<count; i++) dst[i]=0xff000000u;
}
static void convert(uint32_t *restrict dst, const uint16_t *restrict src, int count) {
    for (int i=0; i<count; i++) {
        uint32_t c=src[i];
        dst[i]=0xff000000u | ((c&31u)<<19) | ((c&992u)<<6) | ((c&31744u)>>7);
    }
}
void a2_compose_frame(uint32_t *dst, int pitch, int scale,
                      int dx, int dy, int dw, int dh,
                      int xo, int yo, int cw, int ch) {
    int w=cw*scale, h=ch*scale, source_w=1024*scale;
    int left=xo*scale, top=yo*scale;
    int right=left+dw*scale, bottom=top+dh*scale;
    int x0=left>0?left:0, x1=right<w?right:w;
    int y0=top>0?top:0, y1=bottom<h?bottom:h;
    if (x0>=x1 || y0>=y1) {
        for (int y=0;y<h;y++) black(dst+(size_t)y*pitch,w);
        return;
    }
    int sx=(dx*scale+x0-left)%source_w;
    if (sx<0) sx+=source_w;
    int first=x1-x0;
    if (first>source_w-sx) first=source_w-sx;
    for (int y=0;y<h;y++) {
        uint32_t *row=dst+(size_t)y*pitch;
        if (y<y0 || y>=y1) { black(row,w); continue; }
        black(row,x0);
        int fy=dy*scale+y-top;
        const uint32_t *rgb=gpu_display_argb_row(fy);
        if(rgb) {
            memcpy(row+x0,rgb+sx,(size_t)first*sizeof *row);
            memcpy(row+x0+first,rgb,(size_t)(x1-x0-first)*sizeof *row);
        } else {
            const uint16_t *source=gpu_display_row(fy);
            convert(row+x0,source+sx,first);
            convert(row+x0+first,source,x1-x0-first);
        }
        black(row+x1,w-x1);
    }
}

void a2_compose_cinema(uint32_t *dst, int pitch, int scale,
                       const A2CinemaRaster *r, const A2CinemaLayout *layout) {
    int w=r->cw*scale,h=r->ch*scale;
    int picture_top=layout->picture_dst_y*scale;
    int picture_end=picture_top+layout->picture_rows*scale;
    int subtitle_top=layout->subtitle_dst_y*scale;
    int subtitle_end=subtitle_top+layout->subtitle_rows*scale;
    /* The resolver admits a complete 320-wide display only. Each fine row
     * is converted once; the ordinary renderer keeps its existing fast path. */
    for(int y=0;y<h;y++) {
        uint32_t *row=dst+(size_t)y*pitch;
        int source_y;
        if(y>=picture_top && y<picture_end)
            source_y=(r->dy+layout->picture_src_y)*scale+y-picture_top;
        else if(y>=subtitle_top && y<subtitle_end)
            source_y=(r->dy+layout->subtitle_src_y)*scale+y-subtitle_top;
        else { black(row,w);continue; }
        const uint32_t *rgb=gpu_display_argb_row(source_y);
        if(rgb)memcpy(row,rgb+r->dx*scale,(size_t)w*sizeof *row);
        else convert(row,gpu_display_row(source_y)+r->dx*scale,w);
    }
}

int a2_compose_cinema_expanded(uint32_t *dst,int pitch,int scale,
                              const A2CinemaRaster *r,const A2CinemaLayout *layout) {
#ifdef A2_CINEMA_EXPANSION
    if(!r||!layout||scale<1||scale>4||pitch<320*scale||r->cw!=320||r->ch!=240||
       r->dx!=0||(r->dy!=0&&r->dy!=256)||layout->picture_src_y!=0||
       layout->picture_rows!=172||layout->picture_dst_y!=34||
       layout->subtitle_src_y!=174||layout->subtitle_rows!=32||layout->subtitle_dst_y!=207||
       gpu_ir()!=scale||!gpu_cinema_expansion_ready(r->dy))return 0;
    int width=320*scale;
    for(int y=0;y<240*scale;y++) {
        uint32_t *row=dst+(size_t)y*pitch;
        if(y>=34*scale&&y<206*scale)
            convert(row,gpu_display_row(r->dy*scale+y-34*scale),width);
        else if(y>=12*scale&&y<228*scale)
            convert(row,gpu_cinema_extra_row(r->dy,y-34*scale),width);
        else black(row,width);
        if(y>=207*scale&&y<239*scale) {
            int text_y=y-207*scale;
            const uint8_t *alpha=gpu_cinema_subtitle_alpha_row(r->dy,text_y);
            const uint16_t *source=gpu_display_row((r->dy+174)*scale+text_y);
            for(int x=0;x<width;x++) {
                unsigned c=source[x],a=alpha[x],before=row[x],result=0xff000000u;
                /* Source glyph pixels are already composited on black.
                 * Add the uncovered scene rather than multiplying ink twice. */
                for(int k=0;k<3;k++) {
                    int shift=16-k*8;
                    unsigned foreground=((c>>(k*5))&31)*8;
                    unsigned color=foreground+(((before>>shift)&255)*(255-a)+127)/255;
                    if(color>255)color=255;
                    result|=color<<shift;
                }
                row[x]=result;
            }
        }
    }
    return 1;
#else
    (void)dst;(void)pitch;(void)scale;(void)r;(void)layout;return 0;
#endif
}
