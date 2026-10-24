#include "text_raster.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
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
int main(void) {
    title("Сохранить игру");title("ゲームを保存");title("Save game");
    check("Загрузка",0);check("設定 日本語",0);check("Resume game",0);
    check("Язык и переход между 1× и HD применятся при следующем запуске.",260);
    check("日本語のテキストと音声は個別に選択できます。",160);
    A2TextRaster x={0},old=x;assert(!a2_text_rasterize("\xff",20,100,0,&x));assert(!memcmp(&old,&x,sizeof x));
    assert(!a2_text_rasterize("a",0,100,0,&x));assert(!a2_text_rasterize("a",20,-1,0,&x));
    puts("text raster: pass");return 0;
}
