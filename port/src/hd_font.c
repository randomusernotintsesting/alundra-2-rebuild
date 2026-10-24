/* Identity-checked HD text. Original uploads and world textures stay native. */
#include <stdlib.h>
#include <string.h>
#include "psx_rt.h"
#include "hd_font.h"
#include "../assets/hd_font_data.h"
#include "../assets/hd_font_en_data.h"
#include "../assets/hd_font_sources.h"
int gpu_ir(void);

/* Only the two original text-cache pages are eligible. Tokens accompany
   uploads; a full cell comparison below also rejects stale annotations. */
static uint16_t cache_token[256 * 128];
static uint8_t cache_height[256 * 128];
static uint8_t cache_source[256 * 128];

int a2_hd_font_enabled(void) {
    const char *e = getenv("A2_HDUI");
    return (!e || strcmp(e, "0")) && gpu_ir() > 1;
}

void a2_hd_font_reset(void) {
    memset(cache_token, 0, sizeof cache_token);
    memset(cache_height, 0, sizeof cache_height);
    memset(cache_source, 0, sizeof cache_source);
}

static int font_profile(uint32_t token, const uint8_t **bank, int *height, unsigned *source) {
    if (!a2_hd_font_enabled()) return -1;
    uint32_t mode = lw_(0x800640f0);
    if (mode > 3) return -1;
    if ((mode == 0 || mode == 2) && (token & 0xff00) != 0xff00) return -1;
    unsigned cell = token & 255;
    if (cell < 32 || cell > 127) return -1;
    *height = mode < 2 ? 16 : 24;
    uint32_t address = mode < 2 ? 0x80065b60 : lw_(0x8014c880);
    unsigned offset = address & 0x1fffffff;
    size_t size = mode < 2 ? sizeof a2_hd_bank16 : sizeof a2_hd_bank24;
    if (offset > PSX_RAM_SIZE - size) return -1;
    const A2HDFontSource *sources=mode<2?a2_hd_sources16:a2_hd_sources24;
    unsigned key_offset=mode<2?A2_HD_FONT_KEY_OFFSET16:A2_HD_FONT_KEY_OFFSET24;
    const uint8_t *key_bytes=PSX_RAM+offset+key_offset;
    uint32_t key=(uint32_t)key_bytes[0]|(uint32_t)key_bytes[1]<<8|
                 (uint32_t)key_bytes[2]<<16|(uint32_t)key_bytes[3]<<24;
    /* The generated keys are unique across RU and the five Latin styles.
     * Choose with four bytes, then perform exactly one full identity check. */
    for(unsigned i=0;i<A2_HD_FONT_SOURCE_COUNT;i++) {
        if(key!=sources[i].key)continue;
        if(memcmp(PSX_RAM+offset,sources[i].bank,size))return -1;
        *bank=sources[i].bank;*source=i;
        return (i?96:0)+(int)cell-32;
    }
    return -1;
}

static const A2HDGlyph *profile_glyph(int cell,int height) {
    if(cell>=96)return height==16?&a2_hd_en_glyphs16[cell-96]:&a2_hd_en_glyphs24[cell-96];
    return height==16?&a2_hd_glyphs16[cell]:&a2_hd_glyphs24[cell];
}

int a2_hd_guest_advance(uint32_t token, int original) {
    const uint8_t *bank;
    int height;
    unsigned source;
    int cell = font_profile(token, &bank, &height, &source);
    if (cell < 0) return original;
    const A2HDGlyph *glyph = profile_glyph(cell,height);
    return glyph->advance >= 1 && glyph->advance <= 12 ? glyph->advance : original;
}

void a2_hd_guest_note(uint32_t token, uint32_t base_x, uint32_t u, uint32_t v) {
    unsigned x = base_x + ((u & 255) / 4), y = v & 255;
    if (x < 896 || x > 1021) return;
    unsigned pos = y * 128 + x - 896;
    cache_token[pos] = 0;
    cache_height[pos] = 0;
    cache_source[pos] = 0;
    const uint8_t *bank;
    int height;
    unsigned source;
    int cell = font_profile(token, &bank, &height, &source);
    if (cell < 0 || y + height > 256) return;
    cache_token[pos] = (uint16_t)(cell + 1);
    cache_height[pos] = (uint8_t)height;
    cache_source[pos] = (uint8_t)source;
}

const A2HDGlyph *a2_hd_font_match(const uint16_t *vram, uint32_t tpage,
                               int u, int v, int width, int height) {
    if (!a2_hd_font_enabled() ||
        ((tpage >> 7) & 3) != 0 || ((tpage & 31) != 30 && (tpage & 31) != 31) ||
        (u & 3) || u < 0 || u > 244 || v < 0 ||
        (height != 16 && height != 24) || v + height > 256 ||
        width < 1 || width > 12) return NULL;
    unsigned x = (tpage & 15) * 64 + u / 4;
    if (x < 896 || x > 1021) return NULL;
    unsigned pos = v * 128 + x - 896;
    int cell = (int)cache_token[pos] - 1;
    if (cell < 0 || cell >= 192 || cache_height[pos] != height) return NULL;
    unsigned source=cache_source[pos];
    if(source>=A2_HD_FONT_SOURCE_COUNT || (source!=0)!=(cell>=96))return NULL;
    const uint8_t *bank=(height==16?a2_hd_sources16:a2_hd_sources24)[source].bank;
    const uint8_t *record = bank+(cell%96)*(height*3+1);
    for (int y=0; y<height; y++)
        for (int i=0; i<3; i++) {
            unsigned b = record[y*3+i];
            unsigned expected = ((b>>6)&3) | (((b>>4)&3)<<4) |
                                (((b>>2)&3)<<8) | ((b&3)<<12);
            if (vram[(v+256+y)*1024+x+i] != expected) return NULL;
        }
    return profile_glyph(cell,height);
}

static unsigned alpha_reference(const A2HDGlyph *glyph, int x, int y, int scale) {
    if (!glyph || scale < 1 || scale > 4 || x < 0 || y < 0 ||
        x >= 12*scale || y >= 24*scale) return 0;
    /* Exact area integration from the common 4x coverage grid. With integer
       coordinates in 1/(4*scale) cells this also handles 4→3 without drift. */
    int x0 = x*4, x1 = x0+4, y0 = y*4, y1 = y0+4;
    unsigned sum = 0;
    for (int sy = y0/scale; sy < (y1+scale-1)/scale; sy++) {
        int ya = sy*scale > y0 ? sy*scale : y0;
        int yb = (sy+1)*scale < y1 ? (sy+1)*scale : y1;
        for (int sx = x0/scale; sx < (x1+scale-1)/scale; sx++) {
            int xa = sx*scale > x0 ? sx*scale : x0;
            int xb = (sx+1)*scale < x1 ? (sx+1)*scale : x1;
            sum += glyph->alpha[sy*48+sx] * (unsigned)((xb-xa)*(yb-ya));
        }
    }
    return (sum+8)/16;
}

/* Immutable embedded glyphs only. One active IR, filled on first use; less
   than1.7MiB even at4x. No guest-bank or VRAM identity check is cached. */
static uint8_t alpha_cache[384][48*96];
static uint8_t alpha_cache_ready[384];
static int alpha_cache_scale;

static int embedded_glyph_index(const A2HDGlyph *glyph) {
    uintptr_t address=(uintptr_t)glyph;
    const A2HDGlyph *banks[4]={a2_hd_glyphs16,a2_hd_glyphs24,a2_hd_en_glyphs16,a2_hd_en_glyphs24};
    for(int family=0;family<4;family++) {
        uintptr_t base=(uintptr_t)banks[family];
        if(address<base || address-base>=96*sizeof(A2HDGlyph))continue;
        uintptr_t offset=address-base;
        if(offset%sizeof(A2HDGlyph))continue;
        unsigned n=(unsigned)(offset/sizeof(A2HDGlyph));
        if(glyph==&banks[family][n])return family*96+(int)n;
    }
    return -1;
}

static const uint8_t *prepare_alpha(const A2HDGlyph *glyph,int index,int scale) {
    if(alpha_cache_scale!=scale) {
        memset(alpha_cache_ready,0,sizeof alpha_cache_ready);
        alpha_cache_scale=scale;
    }
    if(!alpha_cache_ready[index]) {
        for(int py=0;py<24*scale;py++)for(int px=0;px<12*scale;px++)
            alpha_cache[index][py*48+px]=(uint8_t)alpha_reference(glyph,px,py,scale);
        alpha_cache_ready[index]=1;
    }
    return alpha_cache[index];
}

const uint8_t *a2_hd_font_coverage(const A2HDGlyph *glyph,int scale) {
    if(!glyph||scale<1||scale>4)return NULL;
    int index=embedded_glyph_index(glyph);
    return index<0?NULL:prepare_alpha(glyph,index,scale);
}

unsigned a2_hd_font_alpha(const A2HDGlyph *glyph, int x, int y, int scale) {
    if (!glyph || scale<1 || scale>4 || x<0 || y<0 ||
        x>=12*scale || y>=24*scale)return 0;
    const uint8_t *coverage=a2_hd_font_coverage(glyph,scale);
    /* Mutable synthetic glyphs still bypass the embedded cache. */
    return coverage?coverage[y*A2_HD_FONT_COVERAGE_STRIDE+x]:alpha_reference(glyph,x,y,scale);
}
