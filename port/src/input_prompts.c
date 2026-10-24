/* Device-aware captions over verified UI contexts; never modifies guest data. */
#include "input_prompts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(__APPLE__) && !defined(A2_PROMPTS_PORTABLE)
#include <CoreText/CoreText.h>
#include <CoreGraphics/CoreGraphics.h>
#else
#include "font8x8.h"
#endif

typedef struct {
    unsigned kind,language,u,v,width,height,bpp;const uint8_t *pixels,*palette;
} PromptTextureSource;
#include "../assets/input_prompt_sources.h"
#define COUNT(a) (sizeof(a)/sizeof((a)[0]))
static const uint8_t *guest;
static size_t guest_size;
static int language;
static int8_t proofs[COUNT(prompt_texture_sources)];
typedef struct {
    int present,x,y,w,h;
    int watch_x,watch_y,watch_w,watch_h;
    A2CinemaRaster raster;
} ObservedSprite;
static ObservedSprite observed[4];
static unsigned retained_mask;
typedef struct {
    A2PromptPanel panel;
    int scale,tall,canvas_width,canvas_height;
    uint32_t *pixels;
    uint64_t generation;
} PanelCache;
static PanelCache caches[3];
static uint64_t panel_generation;
#ifdef A2_INPUT_PROMPTS_TEST
static unsigned raster_count;
unsigned a2_input_prompts_test_raster_count(void) { return raster_count; }
#endif

static unsigned offset(uint32_t address) { return address&0x1fffffffu; }
static int valid(uint32_t address,size_t size) {
    unsigned at=offset(address);return guest && at<=guest_size && size<=guest_size-at;
}
static unsigned half(uint32_t address) {
    unsigned at=offset(address);return valid(address,2)?guest[at]|(unsigned)guest[at+1]<<8:0;
}
void a2_input_prompts_close(void) {
    for(unsigned i=0;i<COUNT(caches);i++) { free(caches[i].pixels);memset(caches+i,0,sizeof caches[i]); }
    memset(observed,0,sizeof observed);retained_mask=0;
    memset(proofs,0,sizeof proofs);guest=NULL;guest_size=0;
}
void a2_input_prompts_init(const uint8_t *ram,size_t size) {
    a2_input_prompts_close();guest=ram;guest_size=size;
}
void a2_input_prompts_configure(int locale) {
    if(locale>=0 && locale<=2 && locale!=language) {
        language=locale;memset(proofs,0,sizeof proofs);memset(observed,0,sizeof observed);retained_mask=0;
    }
}
int a2_input_prompts_preview_bit(unsigned action) {
    if(action>=9)return -1;
    static const unsigned bits[9]={13,14,12,15,10,8,11,9,0};
    unsigned matches=0;int result=-1;
    for(unsigned i=0;i<9;i++)if(half(0x80143a88u+2*i)==action) { result=(int)bits[i];matches++; }
    return matches==1?result:-1;
}
void a2_input_prompts_vram_changed(int x,int y,int width,int height) {
    if(width<=0 || height<=0)return;
    /* The four proven candidates occupy only this native atlas rectangle.
     * Wrapped writes conservatively invalidate it. No per-pixel observer. */
    if(x<0 || y<0 || x>1024-width || y>512-height ||
       (x<704 && x+width>576 && y<511 && y+height>256) ||
       (x<1024 && x+width>768 && y<=480 && y+height>480)) {
        memset(proofs,0,sizeof proofs);memset(observed,0,sizeof observed);retained_mask=0;
        return;
    }
    /* A display may repeat without another guest draw (captured KeyConfig).
     * Retain only its untouched native surface. Fresh sprites remain pending
     * through the same draw's original leader-label polygons. This watch is
     * installed after presentation and never adds work to pixel loops. */
    if(retained_mask)for(unsigned i=0;i<COUNT(observed);i++)if(retained_mask&(1u<<i)) {
        ObservedSprite *o=observed+i;
        if(x<o->watch_x+o->watch_w && x+width>o->watch_x &&
           y<o->watch_y+o->watch_h && y+height>o->watch_y)retained_mask&=~(1u<<i);
    }
}
void a2_input_prompts_sprite(const uint16_t *vram,uint32_t tpage,uint32_t clut,
                             int x,int y,int width,int height,int u,int v) {
    if(!guest || !vram || (tpage&31)!=25)return;
    unsigned mode=(tpage>>7)&3;if(mode>1)return;
    for(unsigned i=0;i<COUNT(prompt_texture_sources);i++) {
        const PromptTextureSource *s=prompt_texture_sources+i;
        if((s->language!=3 && s->language!=(unsigned)language) ||
           width!=(int)s->width || height!=(int)s->height || u!=(int)s->u || v!=(int)s->v ||
           s->bpp!=(mode?8u:4u))continue;
        /* Match the complete steady-state CLUT too. During original palette
         * fades the native replacement stays hidden, preserving that fade. */
        unsigned bank=s->kind==A2_PROMPT_CONTROLLER?0:s->kind+8;
        if((clut&63)!=48+bank || (clut>>6)!=480)continue;
        if(!proofs[i]) {
            int same=1;
            for(unsigned row=0;row<s->height && same;row++)for(unsigned col=0;col<s->width;col++) {
                unsigned su=s->u+col;
                unsigned texel=vram[(256+s->v+row)*1024+576+(su>>(mode?1:2))];
                unsigned index=(texel>>((su&(mode?1:3))*(mode?8:4)))&(mode?255:15);
                if(index!=s->pixels[row*s->width+col]) { same=0;break; }
            }
            for(unsigned color=0;color<(1u<<s->bpp) && same;color++) {
                unsigned expected=s->palette[color*2]|(unsigned)s->palette[color*2+1]<<8;
                if(vram[480*1024+(clut&63)*16+color]!=expected)same=0;
            }
            proofs[i]=same?1:-1;
        }
        if(proofs[i]>0) {
            observed[s->kind]=(ObservedSprite){.present=1,.x=x,.y=y,.w=width,.h=height};
            retained_mask&=~(1u<<s->kind);
        }
        return;
    }
}

static const char *const action_labels[3][9]={
    {"Атака","Действие","Прыжок","Предмет","Карманы","Бег","Камера вправо","Камера влево","Ракурс"},
    {"アタック","アクション","ジャンプ","アイテム","ポケット","ダッシュ","右回転","左回転","カメラ"},
    {"Attack","Action","Jump","Item","Pocket","Run","Camera right","Camera left","Camera angle"}
};
static const char *localized(const char *ru,const char *ja,const char *en) { return language==0?ru:language==1?ja:en; }
static A2PromptItem *item(A2PromptPanel *panel,const char *label) {
    if(panel->count>=COUNT(panel->items))return NULL;
    A2PromptItem *p=panel->items+panel->count++;snprintf(p->label,sizeof p->label,"%s",label);return p;
}
static void bit_binding(A2PromptItem *p,int bit) {
    if(!p || p->binding_count>=COUNT(p->bindings))return;
    if(bit<0) {
        A2InputPrompt *b=p->bindings+p->binding_count++;b->glyph=A2_GLYPH_NONE;
        snprintf(b->label,sizeof b->label,"—");return;
    }
    A2InputPrompt values[2];int count=a2_input_prompts_for_bit(bit,values);
    if(count<0 || count>2)return;
    for(int i=0;i<count && p->binding_count<COUNT(p->bindings);i++)p->bindings[p->binding_count++]=values[i];
}
static void action_item(A2PromptPanel *panel,unsigned action) {
    bit_binding(item(panel,action_labels[language][action]),a2_input_prompts_preview_bit(action));
}
static void controls_item(A2PromptPanel *panel) {
    A2PromptItem *p=item(panel,localized("Управление","操作設定","Controls"));if(!p)return;
    if(a2_input_source()==A2_INPUT_KEYBOARD) {
        p->binding_count=2;
        for(unsigned i=0;i<2;i++)p->bindings[i].glyph=A2_GLYPH_KEY;
        snprintf(p->bindings[0].label,sizeof p->bindings[0].label,"Esc");
        snprintf(p->bindings[1].label,sizeof p->bindings[1].label,"F1");
    } else {
        p->binding_count=1;p->bindings[0].glyph=A2_GLYPH_TEXT;
        p->bindings[0].source=A2_INPUT_CONTROLLER;
        a2_input_menu_chord_prompt(p->bindings[0].label,sizeof p->bindings[0].label);
    }
}
static void physical_item(A2PromptPanel *panel,const char *label,unsigned mask) {
    A2PromptItem *p=item(panel,label);
    for(int bit=0;bit<16;bit++)if(mask&(1u<<bit))bit_binding(p,bit);
}
static void retain_panel(unsigned kind,const A2PromptPanel *p,const A2CinemaRaster *r) {
    ObservedSprite *o=observed+kind;o->present=0;o->raster=*r;
    o->watch_x=p->x-r->xo+r->dx;o->watch_y=p->y-r->yo+r->dy;
    o->watch_w=p->width;o->watch_h=p->height;retained_mask|=1u<<kind;
}
void a2_input_prompts_frame(const A2CinemaRaster *r,int hidden,A2PromptFrame *out) {
    memset(out,0,sizeof *out);
    if(!guest || guest_size<2*1024*1024 || !r || hidden || !r->on || r->overlay!=4 ||
       r->dw<240 || r->cw<240 || r->ch<200) {
        memset(observed,0,sizeof observed);retained_mask=0;return;
    }
    int present[4];for(unsigned i=0;i<COUNT(observed);i++) {
        ObservedSprite *o=observed+i;
        int contained=o->x>=r->dx && o->y>=r->dy &&
            o->x+o->w<=r->dx+r->dw && o->y+o->h<=r->dy+r->dh;
        present[i]=contained && (o->present ||
            ((retained_mask&(1u<<i)) && !memcmp(&o->raster,r,sizeof *r)));
        if(!present[i]) { memset(o,0,sizeof *o);retained_mask&=~(1u<<i); }
    }
    if(present[A2_PROMPT_CONTROLLER]) {
        A2PromptPanel *p=out->panels+out->count++;p->kind=A2_PROMPT_CONTROLLER;
        /* Covers the diagram and its nine old leader labels, preserving
         * the heading and original Type A/B/C/Custom selection below. */
        p->x=r->xo+8;p->y=r->yo+50;p->width=r->dw-16;p->height=264;
        for(unsigned i=0;i<9;i++)action_item(p,i);
        controls_item(p);retain_panel(A2_PROMPT_CONTROLLER,p,r);
        for(unsigned i=0;i<A2_PROMPT_CONTROLLER;i++)memset(observed+i,0,sizeof observed[i]);
        retained_mask=1u<<A2_PROMPT_CONTROLLER;return;
    }
    for(unsigned kind=A2_PROMPT_CONFIRM;kind<=A2_PROMPT_RESET;kind++)if(present[kind]) {
        A2PromptPanel *p=out->panels+out->count++;p->kind=(int)kind;
        p->x=observed[kind].x-r->dx+r->xo;p->y=observed[kind].y-r->dy+r->yo;
        p->width=observed[kind].w;p->height=observed[kind].h;
        physical_item(p,kind==A2_PROMPT_CONFIRM?localized("Выбрать","決定","Confirm"):
            kind==A2_PROMPT_CANCEL?localized("Отмена","戻る","Cancel"):localized("Сброс","初期化","Reset"),
            kind==A2_PROMPT_CONFIRM?((1u<<13)|(1u<<15)):kind==A2_PROMPT_CANCEL?(1u<<14):(1u<<3));
        retain_panel(kind,p,r);
    }
    /* Ordinary gameplay, tutorial/dialogue and unknown sprites add nothing.
     * Only existing, exactly identified menu legends may change presentation. */
}

/* Cached platform typography. Pixel storage is premultiplied ARGB; only
 * changed descriptors/layouts allocate. Composition is bounded small panels. */
#if defined(__APPLE__) && !defined(A2_PROMPTS_PORTABLE)
typedef struct { CTLineRef line;double width; } TextRun;
static TextRun text_run(const char *value,double size) {
    TextRun out={0};
    CFStringRef string=CFStringCreateWithCString(NULL,value,kCFStringEncodingUTF8);
    CTFontRef font=CTFontCreateWithName(CFSTR("Helvetica"),size,NULL);
    const void *keys[]={kCTFontAttributeName,kCTForegroundColorFromContextAttributeName};
    const void *values[]={font,kCFBooleanTrue};
    CFDictionaryRef attributes=CFDictionaryCreate(NULL,keys,values,2,&kCFTypeDictionaryKeyCallBacks,&kCFTypeDictionaryValueCallBacks);
    CFAttributedStringRef attributed=string?CFAttributedStringCreate(NULL,string,attributes):NULL;
    out.line=attributed?CTLineCreateWithAttributedString(attributed):NULL;
    if(out.line)out.width=CTLineGetTypographicBounds(out.line,NULL,NULL,NULL);
    if(attributed)CFRelease(attributed);if(string)CFRelease(string);
    CFRelease(attributes);CFRelease(font);return out;
}
static void draw_run(CGContextRef context,TextRun run,double x,double baseline,double fit) {
    if(!run.line)return;
    CGContextSaveGState(context);CGContextTranslateCTM(context,x,baseline);
    CGContextScaleCTM(context,fit,fit);CGContextSetTextMatrix(context,CGAffineTransformIdentity);
    CGContextSetTextPosition(context,0,0);CTLineDraw(run.line,context);CGContextRestoreGState(context);
}
static void release_run(TextRun run) { if(run.line)CFRelease(run.line); }
static int shape_glyph(A2InputGlyph glyph) {
    return glyph>=A2_GLYPH_CROSS && glyph<=A2_GLYPH_TRIANGLE;
}
static void draw_shape(CGContextRef c,A2InputGlyph glyph,double x,double baseline,double size,double fit) {
    /* PlayStation face symbols are geometry, independent of font fallback. */
    CGContextSaveGState(c);CGContextTranslateCTM(c,x,baseline);
    CGContextScaleCTM(c,fit,fit);CGContextTranslateCTM(c,0,size*.02);
    CGContextSetRGBStrokeColor(c,.98,.90,.65,1);
    CGContextSetLineWidth(c,size*.085);CGContextSetLineJoin(c,kCGLineJoinRound);
    double inset=size*.10,edge=size*.70;
    if(glyph==A2_GLYPH_CIRCLE)CGContextStrokeEllipseInRect(c,CGRectMake(inset,0,edge,edge));
    else if(glyph==A2_GLYPH_SQUARE)CGContextStrokeRect(c,CGRectMake(inset,0,edge,edge));
    else if(glyph==A2_GLYPH_TRIANGLE) {
        CGContextMoveToPoint(c,inset,0);CGContextAddLineToPoint(c,inset+edge,0);
        CGContextAddLineToPoint(c,inset+edge*.5,edge);CGContextClosePath(c);CGContextStrokePath(c);
    } else {
        CGContextMoveToPoint(c,inset,0);CGContextAddLineToPoint(c,inset+edge,edge);
        CGContextMoveToPoint(c,inset,edge);CGContextAddLineToPoint(c,inset+edge,0);CGContextStrokePath(c);
    }
    CGContextRestoreGState(c);
}
static void raster_panel(PanelCache *cache) {
    const A2PromptPanel *p=&cache->panel;int s=cache->scale,pixelw=p->width*s,pixelh=p->height*s;
    CGColorSpaceRef space=CGColorSpaceCreateDeviceRGB();
    CGContextRef c=CGBitmapContextCreate(cache->pixels,pixelw,pixelh,8,pixelw*4,space,kCGImageAlphaPremultipliedFirst|kCGBitmapByteOrder32Little);
    CGColorSpaceRelease(space);if(!c)return;
    /* Paint in physical units before mapping back to the original panel.
     * The fixed16:9 window scales the complete canvas, not each legend.
     * Thus320x480 menus need3/8 in X, while320x216 would need5/6.
     * The panel still covers exactly its native rectangle. Font contours,
     * cap padding, rounded corners and strokes all share this one transform. */
    double aspect=(9.0*cache->canvas_width)/(16.0*cache->canvas_height);
    double w=pixelw/aspect,h=pixelh;
    CGContextScaleCTM(c,aspect,1);
    CGContextSetRGBFillColor(c,.025,.035,.055,.93);CGContextFillRect(c,CGRectMake(0,0,w,h));
    CGContextSetRGBStrokeColor(c,.62,.55,.34,.85);CGContextSetLineWidth(c,s*.45);
    CGContextStrokeRect(c,CGRectMake(s*.3,s*.3,w-s*.6,h-s*.6));
    unsigned columns=p->kind==A2_PROMPT_CONTROLLER?2:p->count>4?4:p->count;
    if(!columns)columns=1;unsigned rows=(p->count+columns-1)/columns;
    double cellw=(double)w/columns,cellh=(double)h/rows;
    for(unsigned i=0;i<p->count;i++) {
        const A2PromptItem *item=p->items+i;double x=(i%columns)*cellw+4*s/aspect;
        double top=(i/columns)*cellh,available=cellw-8*s/aspect;
        double keysize=(cache->tall?14:8)*s,labelsize=(cache->tall?12:7)*s;
        if(p->kind==A2_PROMPT_CONTROLLER) { keysize=20*s;labelsize=17*s; }
        double keybase=h-top-cellh*.47,labelbase=h-top-cellh*.89;
        TextRun runs[4]={{0}},separator=text_run("/",keysize);
        double total=0,padding=2*s,gap=3*s;
        for(unsigned j=0;j<item->binding_count;j++) {
            runs[j]=shape_glyph(item->bindings[j].glyph)?(TextRun){NULL,keysize*.90}:
                text_run(item->bindings[j].label,keysize);
            total+=runs[j].width+2*padding;
            if(j)total+=gap*2+separator.width;
        }
        /* Fit by shaped glyph advances, never UTF-8 byte count. Only changed
         * panels create CoreText objects; steady composition is a pixel copy. */
        double fit=total>available?available/total:1,cursor=x;
        CGContextSaveGState(c);CGContextClipToRect(c,CGRectMake(x,h-top-cellh,available,cellh));
        for(unsigned j=0;j<item->binding_count;j++) {
            if(j) {
                cursor+=gap*fit;CGContextSetRGBFillColor(c,.65,.69,.76,1);
                draw_run(c,separator,cursor,keybase,fit);
                cursor+=(separator.width+gap)*fit;
            }
            double capw=(runs[j].width+2*padding)*fit;
            CGRect cap=CGRectMake(cursor,keybase-keysize*.18*fit,capw,keysize*1.13*fit);
            CGPathRef path=CGPathCreateWithRoundedRect(cap,1.4*s*fit,1.4*s*fit,NULL);
            CGContextAddPath(c,path);CGContextSetRGBFillColor(c,.12,.15,.20,1);
            CGContextSetRGBStrokeColor(c,.46,.49,.53,1);CGContextSetLineWidth(c,.4*s*fit);
            CGContextDrawPath(c,kCGPathFillStroke);CGPathRelease(path);
            CGContextSetRGBFillColor(c,.98,.90,.65,1);
            if(shape_glyph(item->bindings[j].glyph))
                draw_shape(c,item->bindings[j].glyph,cursor+padding*fit,keybase,keysize,fit);
            else draw_run(c,runs[j],cursor+padding*fit,keybase,fit);
            cursor+=capw;
            release_run(runs[j]);
        }
        TextRun label=text_run(item->label,labelsize);
        double label_fit=label.width>available?available/label.width:1;
        CGContextSetRGBFillColor(c,.94,.95,.98,1);
        draw_run(c,label,x,labelbase,label_fit);release_run(label);release_run(separator);
        CGContextRestoreGState(c);
    }
    CGContextRelease(c);
}
#else
static void raster_panel(PanelCache *cache) {
    const A2PromptPanel *p=&cache->panel;int s=cache->scale,w=p->width*s,h=p->height*s;
    for(int i=0;i<w*h;i++)cache->pixels[i]=0xee080c12u;
    /* A bounded readable ASCII fallback for non-macOS diagnostic builds. */
    int x=3*s,y=2*s;
    for(unsigned i=0;i<p->count;i++) {
        char value[128];snprintf(value,sizeof value,"%.48s %.48s",p->items[i].bindings[0].label,p->items[i].label);
        if(x+(int)strlen(value)*6*s>w-3*s){x=3*s;y+=10*s;}
        for(const unsigned char *t=(const unsigned char*)value;*t;t++) {
            if((*t&0xc0)==0x80)continue;unsigned ch=*t>=32 && *t<128?*t:'?';
            for(int row=0;row<8;row++)for(int col=0;col<6;col++)if(font8x8[ch-32][row]&(1u<<col))
                for(int yy=0;yy<s;yy++)for(int xx=0;xx<s;xx++) {
                    int px=x+col*s+xx,py=y+row*s+yy;
                    if(px>=0 && px<w && py>=0 && py<h)cache->pixels[py*w+px]=0xffeeeeeeu;
                }
            x+=6*s;
        }
        x+=8*s;
    }
}
#endif
static int prompt_layout_valid(int scale,const A2CinemaRaster *r) {
    return r&&scale>=1&&scale<=4&&r->cw>=1&&r->ch>=1&&r->cw<=1024&&r->ch<=512;
}
void a2_input_prompts_visit(int scale,const A2CinemaRaster *r,int hidden,
                           A2PromptVisitor visitor,void *context) {
    A2PromptFrame frame;a2_input_prompts_frame(r,hidden,&frame);
    if(!visitor||!prompt_layout_valid(scale,r))return;
    for(unsigned i=0;i<frame.count;i++) {
        A2PromptPanel *p=frame.panels+i;PanelCache *cache=caches+i;
        if(p->width<=0 || p->height<=0 || p->width>1024 || p->height>512)continue;
        int tall=r->dh>=400;
        if(!cache->pixels || cache->scale!=scale || cache->tall!=tall ||
           cache->canvas_width!=r->cw || cache->canvas_height!=r->ch || memcmp(&cache->panel,p,sizeof *p)) {
            free(cache->pixels);cache->pixels=NULL;cache->panel=*p;cache->scale=scale;cache->tall=tall;
            cache->canvas_width=r->cw;cache->canvas_height=r->ch;
            cache->pixels=calloc((size_t)p->width*p->height*scale*scale,4);
            if(!cache->pixels)continue;
#ifdef A2_INPUT_PROMPTS_TEST
            raster_count++;
#endif
            raster_panel(cache);
            if(!++panel_generation)++panel_generation;
            cache->generation=panel_generation;
        }
        A2PromptPixels view={cache->pixels,p->x*scale,p->y*scale,p->width*scale,
                             p->height*scale,cache->generation};
        visitor(&view,context);
    }
}
typedef struct {uint32_t *pixels;int pitch,width,height;} PromptDestination;
static void compose_panel(const A2PromptPixels *p,void *context) {
    PromptDestination *dst=context;
    for(int y=0;y<p->height;y++) {
        int dy=p->y+y;if(dy<0||dy>=dst->height)continue;
        for(int x=0;x<p->width;x++) {
            int dx=p->x+x;if(dx<0||dx>=dst->width)continue;
            uint32_t source=p->pixels[y*p->width+x],alpha=source>>24;
            if(!alpha)continue;
            uint32_t *target=dst->pixels+(size_t)dy*dst->pitch+dx,d=*target,result=0xff000000u;
            for(unsigned shift=0;shift<24;shift+=8) {
                unsigned v=((source>>shift)&255)+((((d>>shift)&255)*(255-alpha)+127)/255);
                result|=(v>255?255:v)<<shift;
            }
            *target=result;
        }
    }
}
void a2_input_prompts_compose(uint32_t *dst,int pitch,int scale,const A2CinemaRaster *r,int hidden) {
    if(!dst||!prompt_layout_valid(scale,r)||pitch<r->cw*scale) {
        a2_input_prompts_visit(scale,r,hidden,NULL,NULL);return;
    }
    PromptDestination target={dst,pitch,r->cw*scale,r->ch*scale};
    a2_input_prompts_visit(scale,r,hidden,compose_panel,&target);
}
