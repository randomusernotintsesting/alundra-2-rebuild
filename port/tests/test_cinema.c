#include "cinema.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { unsigned offset, size; uint8_t bytes[32]; } CapturedField;
#include "fixtures/cinema_retained_fields.h"

static uint8_t ram[2*1024*1024], unchanged[sizeof ram];
static const A2CinemaRaster normal = {0,0,320,216,0,12,320,240,1,5};
static const A2CinemaLayout wanted = {0,172,34,174,32,207};

static void write16(unsigned p, unsigned value) {
    ram[p]=(uint8_t)value; ram[p+1]=(uint8_t)(value>>8);
}
static void write32(unsigned p, uint32_t value) {
    write16(p,value); write16(p+2,value>>16);
}
static void capture(const CapturedField *fields, size_t count) {
    memset(ram,0,sizeof ram);
    for(size_t i=0;i<count;i++) {
        assert(fields[i].size<=32 && fields[i].offset+fields[i].size<=sizeof ram);
        memcpy(ram+fields[i].offset,fields[i].bytes,fields[i].size);
    }
}
#define CAPTURE(name) capture(name,sizeof(name)/sizeof(name[0]))
static void accepted(A2CinemaRaster raster) {
    A2CinemaLayout got;
    memcpy(unchanged,ram,sizeof ram);
    assert(a2_cinema_layout(ram,sizeof ram,&raster,&got)==1);
    assert(!memcmp(&got,&wanted,sizeof got));
    assert(!memcmp(ram,unchanged,sizeof ram));
    /* Every picture row survives; both 16px subtitle lines fit in the lower
       34px bar without touching picture rows or the end of the canvas. */
    assert(got.picture_dst_y==240-got.picture_dst_y-got.picture_rows);
    assert(got.subtitle_dst_y>got.picture_dst_y+got.picture_rows);
    assert(got.subtitle_dst_y+got.subtitle_rows<240);
}
static void rejected(const uint8_t *bytes,size_t size,A2CinemaRaster raster) {
    A2CinemaLayout got; memset(&got,0x55,sizeof got);
    assert(a2_cinema_layout(bytes,size,&raster,&got)==0);
    A2CinemaLayout zero={0}; assert(!memcmp(&got,&zero,sizeof got));
}

static void retained_contract(void) {
    CAPTURE(en_subtitle); accepted(normal);
    CAPTURE(ja_subtitle); A2CinemaRaster other=normal;other.dy=256;accepted(other);
    CAPTURE(no_subtitle); accepted(normal);
    /* A normal gameplay frame can use the same display range, but is not a
       cinematic. The resident EVENT lifetime is also required. */
    other=normal;other.overlay=4;rejected(ram,sizeof ram,other);
    write32(0x79e9c,0);rejected(ram,sizeof ram,normal);
}
static void subtitle_contract(void) {
    CAPTURE(en_subtitle);
    /* Genuine one-line fixture plus a second-line node using the same native
       16px height. Outline/ink remain inside the emitted sprite rectangle. */
    memcpy(ram+0x64120,ram+0x64100,32);write16(0x64120+14,190);accepted(normal);
    write16(0x64120+14,206);rejected(ram,sizeof ram,normal);
    CAPTURE(en_subtitle);write16(0x64100+22,24);rejected(ram,sizeof ram,normal);
    CAPTURE(en_subtitle);write16(0x64100+18,24);rejected(ram,sizeof ram,normal);
    CAPTURE(en_subtitle);write16(0x64100+14,173);rejected(ram,sizeof ram,normal);
    CAPTURE(en_subtitle);write32(0x640f0,2);rejected(ram,sizeof ram,normal);
    CAPTURE(en_subtitle);write16(0x65600+18,190);rejected(ram,sizeof ram,normal);
    /* Parent can be cleared while the last emitted glyphs fade. Do not lose
       their pixels; validate their own parent rather than require equality. */
    CAPTURE(en_subtitle);write32(0xacbf8,0);write16(0x64100,3);accepted(normal);
    CAPTURE(no_subtitle);write32(0x65a00,0);accepted(normal);
    write32(0x640f0,2);accepted(normal); /* no text yet: font mode is irrelevant */
}
static void aliases_and_bounds(void) {
    CAPTURE(en_subtitle);
    const uint32_t aliases[]={0x00065600u,0x80065600u,0xa0065600u};
    for(unsigned i=0;i<3;i++) {
        write32(0xacbf8,aliases[i]);
        for(unsigned n=0;n<168;n++)if(ram[0x64100+n*32])write32(0x64100+n*32+28,aliases[i]);
        accepted(normal);
    }
    const uint32_t bad[]={0xe0065600u,0x40065600u,0x80065601u,0x80265600u,0x80065a00u};
    for(unsigned i=0;i<sizeof bad/sizeof bad[0];i++) {
        CAPTURE(en_subtitle);write32(0xacbf8,bad[i]);rejected(ram,sizeof ram,normal);
        CAPTURE(en_subtitle);write32(0x64100+28,bad[i]);rejected(ram,sizeof ram,normal);
    }
    CAPTURE(en_subtitle);write32(0x65a00,169);rejected(ram,sizeof ram,normal);
    const size_t sizes[]={0,1,0x640f0,0x65a03,0x79e9f,0xacbfb};
    for(unsigned i=0;i<sizeof sizes/sizeof sizes[0];i++) {
        uint8_t *short_ram=malloc(sizes[i]?sizes[i]:1);assert(short_ram);
        if(sizes[i])memcpy(short_ram,ram,sizes[i]);
        rejected(short_ram,sizes[i],normal);free(short_ram);
    }
    rejected(NULL,sizeof ram,normal);
    A2CinemaLayout got;memset(&got,0x55,sizeof got);
    assert(!a2_cinema_layout(ram,sizeof ram,NULL,&got));
    A2CinemaLayout zero={0};assert(!memcmp(&got,&zero,sizeof got));
    assert(!a2_cinema_layout(ram,sizeof ram,&normal,NULL));
}
static void raster_contract(void) {
    CAPTURE(no_subtitle);
    A2CinemaRaster variants[10];
    for(unsigned i=0;i<10;i++)variants[i]=normal;
    variants[0].dx=1; variants[1].dy=128; variants[2].dw=256;
    variants[3].dh=172;variants[4].xo=1;variants[5].yo=0;
    variants[6].cw=368;variants[7].ch=480;variants[8].on=0;variants[9].overlay=10;
    for(unsigned i=0;i<10;i++)rejected(ram,sizeof ram,variants[i]);
}
int main(void) {
    for(int text=0;text<3;text++)for(int voice=0;voice<2;voice++) {
        assert(a2_cinema_show_subtitles(0,text,voice));
        assert(a2_cinema_show_subtitles(1,text,voice));
        assert(!a2_cinema_show_subtitles(2,text,voice));
    }
    retained_contract(); subtitle_contract(); aliases_and_bounds(); raster_contract();
    puts("Cinema: retained EN/JA/no-text fields, whole picture, two lines, aliases and safe fallback passed");
    return 0;
}
