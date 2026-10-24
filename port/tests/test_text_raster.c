#include "text_raster.h"
#include <assert.h>
#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
static void check(const char *s,int w) {
    A2TextRaster r={0};assert(a2_text_rasterize(s,20,w,0,&r));
    assert(r.width>0&&r.height>0&&r.width<= (w?w:4096));assert(!r.missing_glyphs);
    unsigned ink=0;for(int i=0;i<r.width*r.height;i++)if(r.pixels[i]>>24) {++ink;assert((r.pixels[i]&0xffffff)==0xffffff);}
    assert(ink>10);a2_text_raster_free(&r);assert(!r.pixels);
}
static void title(const char *s) {
    for(int bold=0;bold<2;bold++){
        A2TextRaster r={0};assert(a2_text_rasterize_title(s,50,880,bold,&r));
        assert(r.width>0&&r.width<=880&&r.height>0&&!r.missing_glyphs);
        unsigned ink=0;for(int i=0;i<r.width*r.height;i++)ink+=(r.pixels[i]>>24)!=0;
        assert(ink>100);a2_text_raster_free(&r);
    }
}
static void image_roundtrip(void) {
    const uint32_t pixels[]={0xffff0000,0xff00ff00,0xff0000ff,0xffffffff};
    A2TextRaster image={0}, old=image;
    assert(!a2_image_raster_load("a2-does-not-exist.png",&image));
    assert(!memcmp(&old,&image,sizeof image));
    assert(!a2_image_raster_write_png("unused.png",pixels,2,2,1));
#ifdef _WIN32
    wchar_t directory[MAX_PATH], unique[MAX_PATH], filename[MAX_PATH];
    assert(GetTempPathW(MAX_PATH,directory));
    assert(GetTempFileNameW(directory,L"a2t",0,unique));
    assert(DeleteFileW(unique));
    assert(CreateDirectoryW(unique,NULL));
    assert(swprintf(filename,MAX_PATH,L"%ls\\Текст 日本語.png",unique)>0);
    char path[4096];
    assert(WideCharToMultiByte(CP_UTF8,WC_ERR_INVALID_CHARS,filename,-1,path,sizeof path,NULL,NULL));
    assert(a2_image_raster_write_png(path,pixels,2,2,2));
    assert(a2_image_raster_load(path,&image));
    assert(image.width==2 && image.height==2);
    assert(!memcmp(pixels,image.pixels,sizeof pixels));
    a2_text_raster_free(&image);
    assert(DeleteFileW(filename));
    assert(RemoveDirectoryW(unique));
#endif
}
int main(void) {
    title("Сохранить игру");title("ゲームを保存");title("Save game");
    check("Загрузка",0);check("設定 日本語",0);check("Resume game",0);
    check("Язык и переход между 1× и HD применятся при следующем запуске.",260);
    check("日本語のテキストと音声は個別に選択できます。",160);
    A2TextRaster x={0},old=x;assert(!a2_text_rasterize("\xff",20,100,0,&x));assert(!memcmp(&old,&x,sizeof x));
    assert(!a2_text_rasterize("a",0,100,0,&x));assert(!a2_text_rasterize("a",20,-1,0,&x));
    assert(!a2_text_rasterize("a",NAN,100,0,&x));
    assert(!a2_text_rasterize("a",129,100,0,&x));
    assert(!a2_text_rasterize("a",20,4097,0,&x));
    assert(!a2_text_rasterize("\xc0\xaf",20,100,0,&x));
    assert(!a2_text_rasterize("\xed\xa0\x80",20,100,0,&x));
    A2TextRaster short_line={0},wrapped={0};
    assert(a2_text_rasterize("Wrapped text test",20,0,0,&short_line));
    assert(a2_text_rasterize("Wrapped text test",20,60,0,&wrapped));
    assert(wrapped.height>short_line.height);
    a2_text_raster_free(&short_line);a2_text_raster_free(&wrapped);
    assert(!memcmp(&old,&x,sizeof x));
    image_roundtrip();
    puts("text raster: pass");return 0;
}
