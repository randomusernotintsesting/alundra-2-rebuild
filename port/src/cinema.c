#include "cinema.h"
#include <string.h>

/* EVENT00 ev_800842C0 sets the resident lifetime flag, then clears it on
 * return. ev_80084F20 clips the picture to 172 rows and the full output to216.
 * ev_8008A2D0 clears the subtitle band172..215. ev_8008C304 sets text Y174
 * and stores its parent at800ACBF8. All offsets below are physical RAM. */
enum {
    EVENT_ACTIVE = 0x79e9c,
    SUBTITLE_PARENT = 0xacbf8,
    FONT_MODE = 0x640f0,
    GLYPHS = 0x64100,
    GLYPH_CAPACITY = 0x65a00,
    TEXT_OBJECTS = 0x65600,
    TEXT_OBJECTS_END = 0x65a00,
    NODE_BYTES = 32,
    MAX_GLYPHS = 168
};
_Static_assert(GLYPHS + MAX_GLYPHS*NODE_BYTES == TEXT_OBJECTS,
               "Glyph storage ends before the parent text objects");
_Static_assert(TEXT_OBJECTS_END <= SUBTITLE_PARENT,
               "The marker size guard covers all text reads");

int a2_cinema_show_subtitles(int setting,int text,int voice) {
    (void)text;(void)voice;
    return setting!=2;
}

static unsigned read16(const uint8_t *ram, unsigned offset) {
    return (unsigned)ram[offset] | ((unsigned)ram[offset+1]<<8);
}
static uint32_t read32(const uint8_t *ram, unsigned offset) {
    return read16(ram,offset) | ((uint32_t)read16(ram,offset+2)<<16);
}
static int valid_parent(const uint8_t *ram, uint32_t pointer) {
    uint32_t segment=pointer&0xe0000000u;
    if(segment!=0 && segment!=0x80000000u && segment!=0xa0000000u) return 0;
    unsigned offset=pointer&0x1fffffffu;
    if(offset<TEXT_OBJECTS || offset>=TEXT_OBJECTS_END ||
       (offset-TEXT_OBJECTS)%NODE_BYTES) return 0;
    return read16(ram,offset+16)==0 && read16(ram,offset+18)==174;
}

int a2_cinema_layout(const uint8_t *ram, size_t ram_bytes,
                     const A2CinemaRaster *raster, A2CinemaLayout *out) {
    if(!out) return 0;
    memset(out,0,sizeof *out);
    if(!raster || raster->overlay!=5 || raster->on!=1 ||
       raster->dx!=0 || (raster->dy!=0 && raster->dy!=256) ||
       raster->dw!=320 || raster->dh!=216 || raster->xo!=0 || raster->yo!=12 ||
       raster->cw!=320 || raster->ch!=240) return 0;
    if(!ram || ram_bytes<SUBTITLE_PARENT+4u || read32(ram,EVENT_ACTIVE)!=1) return 0;

    unsigned capacity=read32(ram,GLYPH_CAPACITY);
    if(capacity>MAX_GLYPHS) return 0;
    uint32_t parent=read32(ram,SUBTITLE_PARENT);
    if(parent && (!valid_parent(ram,parent) || read32(ram,FONT_MODE)!=0)) return 0;

    /* Inspect every still-active glyph, including an old parent's fade after
     * the current subtitle pointer has cleared. No string parsing/reflow:
     * the existing reveal, palette, outlines and fades are already composed.
     * Native80020140 emits exactly node Y/height, without an outer shadow. */
    for(unsigned i=0;i<capacity;i++) {
        unsigned node=GLYPHS+i*NODE_BYTES, state=read16(ram,node);
        if(!state) continue;
        if(state>3 || read32(ram,FONT_MODE)!=0 ||
           !valid_parent(ram,read32(ram,node+28))) return 0;
        unsigned width=read16(ram,node+20), height=read16(ram,node+22);
        if(width>320 || height!=16 || read16(ram,node+18)!=16) return 0;
        if(!width) continue;
        unsigned y=read16(ram,node+14);
        if((y!=174 && y!=190) || y+height>206) return 0;
    }

    /* Fixed two-line slot avoids moving the first line during text reveal.
     * 34+172+34=240; two16px lines fit the lower bar with one row each side.
     * Source rows retain the original native/fine pixels, including outlines. */
    *out=(A2CinemaLayout){0,172,34,174,32,207};
    return 1;
}
