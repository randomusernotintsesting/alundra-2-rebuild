/* Exact source-region replacement, independently of the original palette. */
#include "hd_font.h"
#include "hd_ui.h"
#include "../assets/hd_ui_data.h"
#include "../assets/hd_ui_en_data.h"
#include "../assets/hd_ui_shop_data.h"
static int ui_language;
void a2_hd_ui_set_language(int language) {ui_language=language;}

unsigned a2_hd_ui_prepare(const uint16_t *vram,uint32_t tpage,
                         int u0,int v0,int u1,int v1,
                         const A2HDPlate **out,unsigned capacity) {
    int mode=(tpage>>7)&3;
    if (!a2_hd_font_enabled() || mode>1 || u0<0 || v0<0 ||
        u1>255 || v1>255 || u1<u0 || v1<v0) return 0;
    if(ui_language==1)return 0;
    const A2HDPlate *plates=ui_language==2?a2_hd_en_plates:a2_hd_plates;
    unsigned plate_count=ui_language==2?a2_hd_en_plate_count:a2_hd_plate_count;
    unsigned count=0;
    int tx=(tpage&15)*64,ty=((tpage>>4)&1)*256;
    for(unsigned i=0;i<plate_count+3 && count<capacity;i++) {
        const A2HDPlate *p=i<plate_count?&plates[i]:&a2_hd_shop_plates[(ui_language==2?3:0)+i-plate_count];
        if (p->u>u1 || p->v>v1 || p->u+p->width<=u0 || p->v+p->height<=v0) continue;
        int matches=1;
        for(unsigned y=0;y<p->height && matches;y++)for(unsigned x=0;x<p->width;x++) {
            unsigned u=p->u+x;
            unsigned word=vram[((ty+p->v+y)&511)*1024+((tx+(u>>(mode?1:2)))&1023)];
            unsigned index=mode?((word>>((u&1)*8))&255):((word>>((u&3)*4))&15);
            if(index!=p->source[y*p->width+x]) {matches=0;break;}
        }
        if(matches)out[count++]=p;
    }
    return count;
}

static uint16_t palette(const uint16_t *vram,uint32_t clut,unsigned index) {
    return vram[((clut>>6)&511)*1024+(((clut&63)*16+index)&1023)];
}

int a2_hd_ui_bounds(const A2HDPlate *const *plates,unsigned count,int bounds[4]) {
    if(!count)return 0;
    bounds[0]=bounds[1]=65535;bounds[2]=bounds[3]=0;
    for(unsigned i=0;i<count;i++) {
        const A2HDPlate *p=plates[i];
        if(p->u<bounds[0])bounds[0]=p->u;
        if(p->v<bounds[1])bounds[1]=p->v;
        if(p->u+p->width>bounds[2])bounds[2]=p->u+p->width;
        if(p->v+p->height>bounds[3])bounds[3]=p->v+p->height;
    }
    return 1;
}

int a2_hd_ui_sample(const A2HDPlate *const *plates,unsigned count,
                   const uint16_t *vram,uint32_t clut,int u_fp,int v_fp,
                   A2HDUISample *out) {
    for(unsigned i=0;i<count;i++) {
        const A2HDPlate *p=plates[i];
        int x=u_fp-p->u*256,y=v_fp-p->v*256;
        if(x<0 || y<0 || x>=p->width*256 || y>=p->height*256)continue;
        unsigned px=(unsigned)x>>6,py=(unsigned)y>>6,stride=p->width*4;
        out->background=palette(vram,clut,p->background[(y>>8)*p->width+(x>>8)]);
        out->ink=palette(vram,clut,p->ink_index);
        out->shadow=palette(vram,clut,p->shadow_index);
        out->alpha=p->alpha[py*stride+px];
        out->shadow_alpha=px && py?p->alpha[(py-1)*stride+px-1]:0;
        return 1;
    }
    return 0;
}

int a2_hd_ui_sample_indices(const A2HDPlate *const *plates,unsigned count,
                           int u_fp,int v_fp,A2HDUIIndices *out) {
    for(unsigned i=0;i<count;i++) {
        const A2HDPlate *p=plates[i];
        int x=u_fp-p->u*256,y=v_fp-p->v*256;
        if(x<0 || y<0 || x>=p->width*256 || y>=p->height*256)continue;
        unsigned px=(unsigned)x>>6,py=(unsigned)y>>6,stride=p->width*4;
        out->background=p->background[(y>>8)*p->width+(x>>8)];
        out->ink=p->ink_index;out->shadow=p->shadow_index;
        out->alpha=p->alpha[py*stride+px];
        out->shadow_alpha=px && py?p->alpha[(py-1)*stride+px-1]:0;
        return 1;
    }
    return 0;
}
