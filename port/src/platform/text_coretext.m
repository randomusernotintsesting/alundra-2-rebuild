/* No AppKit objects or windows: Unicode shaping and immutable bitmap decoding. */
#include "text_raster.h"
#include <CoreText/CoreText.h>
#include <CoreGraphics/CoreGraphics.h>
#include <ImageIO/ImageIO.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void a2_text_raster_free(A2TextRaster *r) { if(r){free(r->pixels);memset(r,0,sizeof *r);} }
static CGContextRef bitmap(A2TextRaster *r) {
    r->pixels=calloc((size_t)r->width*r->height,4);if(!r->pixels)return NULL;
    CGColorSpaceRef space=CGColorSpaceCreateDeviceRGB();
    CGContextRef c=CGBitmapContextCreate(r->pixels,r->width,r->height,8,r->width*4,space,kCGImageAlphaPremultipliedFirst|kCGBitmapByteOrder32Little);
    CGColorSpaceRelease(space);if(!c)a2_text_raster_free(r);return c;
}
static int rasterize(const char *s,double size,int max_width,int bold,int title,A2TextRaster *out) {
    if(!s||!out||!isfinite(size)||size<6||size>128||max_width<0||max_width>4096||strlen(s)>16384)return 0;
    CFStringRef str=CFStringCreateWithBytes(NULL,(const UInt8*)s,strlen(s),kCFStringEncodingUTF8,false);if(!str)return 0;
    CTFontRef font=title?CTFontCreateWithName(bold?CFSTR("Georgia-Bold"):CFSTR("Georgia"),size,NULL):
        CTFontCreateUIFontForLanguage(bold?kCTFontUIFontEmphasizedSystem:kCTFontUIFontSystem,size,NULL);
    const void *keys[]={kCTFontAttributeName,kCTForegroundColorFromContextAttributeName};
    const void *values[]={font,kCFBooleanTrue};CFDictionaryRef attrs=CFDictionaryCreate(NULL,keys,values,2,&kCFTypeDictionaryKeyCallBacks,&kCFTypeDictionaryValueCallBacks);
    CFAttributedStringRef text=CFAttributedStringCreate(NULL,str,attrs);CFRelease(str);CFRelease(attrs);CFRelease(font);
    CTFramesetterRef setter=CTFramesetterCreateWithAttributedString(text);CFRelease(text);
    CGSize measured=CTFramesetterSuggestFrameSizeWithConstraints(setter,CFRangeMake(0,0),NULL,CGSizeMake(max_width?max_width:4092,4092),NULL);
    A2TextRaster r={0};r.width=max_width?max_width:(int)ceil(measured.width)+4;r.height=(int)ceil(measured.height)+4;r.advance=measured.width;
    if(r.width<1)r.width=1;if(r.height<1)r.height=1;
    if(r.width>4096||r.height>4096){CFRelease(setter);return 0;}
    CGMutablePathRef path=CGPathCreateMutable();CGPathAddRect(path,NULL,CGRectMake(0,0,r.width,r.height));
    CTFrameRef frame=CTFramesetterCreateFrame(setter,CFRangeMake(0,0),path,NULL);CGPathRelease(path);CFRelease(setter);
    CFArrayRef lines=CTFrameGetLines(frame);
    for(CFIndex i=0;i<CFArrayGetCount(lines);i++){
        CFArrayRef runs=CTLineGetGlyphRuns(CFArrayGetValueAtIndex(lines,i));
        for(CFIndex j=0;j<CFArrayGetCount(runs);j++){
            CTRunRef run=CFArrayGetValueAtIndex(runs,j);CFIndex count=CTRunGetGlyphCount(run);
            const CGGlyph *g=CTRunGetGlyphsPtr(run);CGGlyph *owned=NULL;
            if(!g&&count){owned=malloc((size_t)count*sizeof *owned);if(owned){CTRunGetGlyphs(run,CFRangeMake(0,0),owned);g=owned;}}
            if(g)for(CFIndex k=0;k<count;k++)if(!g[k])r.missing_glyphs++;
            free(owned);
        }
    }
    CGContextRef c=bitmap(&r);if(!c){CFRelease(frame);return 0;}
    CGContextSetRGBFillColor(c,1,1,1,1);CGContextSetTextMatrix(c,CGAffineTransformIdentity);CTFrameDraw(frame,c);
    CGContextRelease(c);CFRelease(frame);
    for(size_t i=0;i<(size_t)r.width*r.height;i++)r.pixels[i]=(r.pixels[i]&0xff000000u)|0xffffffu;
    *out=r;return 1;
}
int a2_text_rasterize(const char *s,double size,int width,int bold,A2TextRaster *out) {
    return rasterize(s,size,width,bold,0,out);
}
int a2_text_rasterize_title(const char *s,double size,int width,int bold,A2TextRaster *out) {
    return rasterize(s,size,width,bold,1,out);
}
int a2_image_raster_load(const char *path,A2TextRaster *out) {
    if(!path||!out)return 0;CFURLRef url=CFURLCreateFromFileSystemRepresentation(NULL,(const UInt8*)path,strlen(path),false);if(!url)return 0;
    CGImageSourceRef source=CGImageSourceCreateWithURL(url,NULL);CFRelease(url);if(!source)return 0;
    CGImageRef im=CGImageSourceCreateImageAtIndex(source,0,NULL);CFRelease(source);if(!im)return 0;
    size_t w=CGImageGetWidth(im),h=CGImageGetHeight(im);if(!w||!h||w>8192||h>8192){CGImageRelease(im);return 0;}
    A2TextRaster r={0};r.width=(int)w;r.height=(int)h;CGContextRef c=bitmap(&r);if(!c){CGImageRelease(im);return 0;}
    CGContextDrawImage(c,CGRectMake(0,0,w,h),im);CGContextRelease(c);CGImageRelease(im);
    for(size_t i=0;i<w*h;i++){uint32_t p=r.pixels[i],a=p>>24;if(a&&a<255){uint32_t rgb=0;for(int s=0;s<24;s+=8){unsigned v=((p>>s)&255)*255/a;if(v>255)v=255;rgb|=v<<s;}r.pixels[i]=(a<<24)|rgb;}}
    *out=r;return 1;
}
int a2_image_raster_write_png(const char *path,const uint32_t *pixels,int w,int h,int pitch) {
    if(!path||!pixels||w<1||h<1||w>8192||h>8192||pitch<w)return 0;
    A2TextRaster r={0};r.width=w;r.height=h;CGContextRef c=bitmap(&r);if(!c)return 0;
    for(int y=0;y<h;y++)for(int x=0;x<w;x++){
        uint32_t p=pixels[(size_t)y*pitch+x],a=p>>24,rgb=0;
        for(int shift=0;shift<24;shift+=8)rgb|=((((p>>shift)&255)*a+127)/255)<<shift;
        r.pixels[(size_t)y*w+x]=(a<<24)|rgb;
    }
    CGImageRef im=CGBitmapContextCreateImage(c);CGContextRelease(c);
    CFURLRef url=CFURLCreateFromFileSystemRepresentation(NULL,(const UInt8*)path,strlen(path),false);
    CGImageDestinationRef dst=url?CGImageDestinationCreateWithURL(url,CFSTR("public.png"),1,NULL):NULL;
    int ok=0;if(dst&&im){CGImageDestinationAddImage(dst,im,NULL);ok=CGImageDestinationFinalize(dst);}
    if(dst)CFRelease(dst);if(url)CFRelease(url);if(im)CGImageRelease(im);a2_text_raster_free(&r);return ok;
}
