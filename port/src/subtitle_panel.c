#include "subtitle_panel.h"
#include "text_raster.h"
#include <stdlib.h>
#include <string.h>

static struct {
    char text[512];
    int scale,width,height,bottom,visible;
    uint64_t generation;
    A2PromptPixels panel;
} cache;

const A2PromptPixels *a2_subtitle_panel_get(void){return cache.visible?&cache.panel:NULL;}
void a2_subtitle_panel_close(void){
    free((void *)cache.panel.pixels);memset(&cache,0,sizeof cache);
}
const A2PromptPixels *a2_subtitle_panel_set(const char *text,int scale,int width,int height,int bottom){
    cache.visible=0;
    if(!text||!*text||strlen(text)>=sizeof cache.text||scale<1||scale>4||
       width<64||width>1024||height<64||height>512||bottom<32||bottom>height)return NULL;
    if(cache.panel.pixels&&cache.scale==scale&&cache.width==width&&cache.height==height&&
       cache.bottom==bottom&&!strcmp(cache.text,text)){
        cache.visible=1;return &cache.panel;
    }
    char lines[512];strcpy(lines,text);char *second=strchr(lines,'\n');
    if(second){*second++=0;if(strchr(second,'\n'))return NULL;}
    A2TextRaster runs[2]={{0}};int count=second?2:1,w=0,h=0,pad=2*scale,ok=0;
    /* Subtitle authoring wraps at word boundaries. Fit unusual wide glyphs
     * by measuring real ink; never clip a caption into a third line. */
    for(double size=10.5;size>=8.0;size-=.5){
        w=h=0;ok=1;
        for(int i=0;i<count;i++){
            a2_text_raster_free(runs+i);
            if(!a2_text_rasterize(i?second:lines,size*scale,0,0,runs+i)||runs[i].missing_glyphs){ok=0;break;}
            if(runs[i].width>w)w=runs[i].width;
            h+=runs[i].height;
        }
        if(ok&&w+2*pad<=(width-12)*scale&&h+2*pad<=32*scale)break;
        ok=0;
    }
    if(!ok){for(int i=0;i<2;i++)a2_text_raster_free(runs+i);return NULL;}
    w+=2*pad;h+=2*pad;
    uint32_t *pixels=calloc((size_t)w*h,4);uint8_t *ink=calloc((size_t)w*h,1);
    if(!pixels||!ink){free(pixels);free(ink);for(int i=0;i<2;i++)a2_text_raster_free(runs+i);return NULL;}
    int y=pad;
    for(int i=0;i<count;i++){
        A2TextRaster *r=runs+i;int x=(w-r->width)/2;
        for(int yy=0;yy<r->height;yy++)for(int xx=0;xx<r->width;xx++)
            ink[(size_t)(y+yy)*w+x+xx]=(uint8_t)(r->pixels[(size_t)yy*r->width+xx]>>24);
        y+=r->height;a2_text_raster_free(r);
    }
    int radius=scale>1?(scale+1)/2:1;
    for(int yy=0;yy<h;yy++)for(int xx=0;xx<w;xx++){
        unsigned outline=0,a=ink[(size_t)yy*w+xx];
        for(int dy=-radius;dy<=radius;dy++)for(int dx=-radius;dx<=radius;dx++){
            int sy=yy+dy,sx=xx+dx;
            if(sy>=0&&sy<h&&sx>=0&&sx<w&&ink[(size_t)sy*w+sx]>outline)outline=ink[(size_t)sy*w+sx];
        }
        unsigned alpha=a+(outline*(255-a)+127)/255;
        pixels[(size_t)yy*w+xx]=(alpha<<24)|(a<<16)|(a<<8)|a;
    }
    free(ink);free((void *)cache.panel.pixels);
    strcpy(cache.text,text);cache.scale=scale;cache.width=width;cache.height=height;cache.bottom=bottom;
    /* Prompt panels use the low namespace. A shared GPU slot must upload
     * again when transitioning between a menu prompt and a caption. */
    cache.generation=(cache.generation+1)|UINT64_C(0x8000000000000000);
    cache.panel=(A2PromptPixels){pixels,(width*scale-w)/2,bottom*scale-h,w,h,cache.generation};
    cache.visible=1;return &cache.panel;
}
void a2_subtitle_panel_compose(uint32_t *pixels,int pitch,int width,int height){
    const A2PromptPixels *p=a2_subtitle_panel_get();
    if(!p||!pixels||pitch<width||width<1||height<1)return;
    for(int y=0;y<p->height;y++)for(int x=0;x<p->width;x++){
        int dx=p->x+x,dy=p->y+y;if(dx<0||dx>=width||dy<0||dy>=height)continue;
        uint32_t source=p->pixels[(size_t)y*p->width+x],a=source>>24;if(!a)continue;
        uint32_t *dst=pixels+(size_t)dy*pitch+dx,value=0xff000000u;
        for(unsigned shift=0;shift<24;shift+=8){
            unsigned v=((source>>shift)&255)+(((*dst>>shift)&255)*(255-a)+127)/255;
            value|=(v>255?255:v)<<shift;
        }
        *dst=value;
    }
}
