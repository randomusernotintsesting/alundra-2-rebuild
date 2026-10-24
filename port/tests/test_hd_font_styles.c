/* Source variants use the same outlines while retaining exact upload identity.
 * argv[1] contains pristine bankNNN.bin fixtures extracted by the Python test. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/hd_font.c"

uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t a2_ramwatch;
static int test_ir=3;
int gpu_ir(void) { return test_ir; }
uint32_t psx_mmio_read(uint32_t p,int size) {(void)p;(void)size;abort();}
void psx_mmio_write(uint32_t p,uint32_t v,int size) {(void)p;(void)v;(void)size;abort();}
void a2_ramwatch_hit(uint32_t p,uint32_t v,int size) {(void)p;(void)v;(void)size;abort();}
static uint16_t actual_vram[1024*512];
/* Exact captured first 'M' in native-en-speech-final frame30000, x896/y256.
 * This independently retains the native cache bytes behind the reported bug. */
static const uint16_t captured_event_m[16*3]={
    0x0000,0x0000,0x0000, 0x0000,0x0000,0x0000,
    0x0000,0x0000,0x0000, 0x0000,0x0000,0x0000,
    0x0003,0x0003,0x0000, 0x0013,0x0003,0x0000,
    0x2023,0x0003,0x0000, 0x3033,0x0003,0x0000,
    0x2123,0x0003,0x0000, 0x2323,0x0003,0x0000,
    0x2323,0x0003,0x0000, 0x1313,0x0003,0x0000,
    0x0303,0x0003,0x0000, 0x0303,0x0003,0x0000,
    0x0000,0x0000,0x0000, 0x0000,0x0000,0x0000
};

static size_t load_bank(const char *directory,int slot,uint8_t out[7008]) {
    char path[4096];assert(snprintf(path,sizeof path,"%s/bank%d.bin",directory,slot)<(int)sizeof path);
    FILE *f=fopen(path,"rb");assert(f);
    size_t n=fread(out,1,7008,f);assert(fgetc(f)==EOF);assert(!fclose(f));
    assert(n==4704 || n==7008);return n;
}
static void upload(const uint8_t *bank,int height) {
    const uint8_t *record=bank+('M'-32)*(height*3+1);
    for(int y=0;y<height;y++)for(int x=0;x<3;x++) {
        unsigned b=record[y*3+x];
        actual_vram[(256+y)*1024+896+x]=((b>>6)&3)|(((b>>4)&3)<<4)|
                                     (((b>>2)&3)<<8)|((b&3)<<12);
    }
}
static const A2HDGlyph *match(int height) {
    return a2_hd_font_match(actual_vram,0x23e,0,0,12,height);
}

int main(int argc,char **argv) {
    assert(argc==2);assert(!setenv("A2_HDUI","1",1));
    const int slots[2][5]={{536,540,544,548,551},{537,541,545,549,552}};
    for(int family=0;family<2;family++)for(int style=0;style<5;style++) {
        int height=family?24:16;unsigned address=family?0x180000:0x65b60;
        uint8_t bank[7008];size_t size=load_bank(argv[1],slots[family][style],bank);
        assert(size==(size_t)(height*3+1)*96);
        sw_(0x800640f0,family?2:0);sw_(0x8014c880,0x80180000);
        memcpy(PSX_RAM+address,bank,size);a2_hd_font_reset();upload(bank,height);
        if(family==0 && style==0)
            for(unsigned y=0;y<16;y++) {
                assert(!memcmp(actual_vram+(256+y)*1024+896,captured_event_m+y*3,6));
                memcpy(actual_vram+(256+y)*1024+896,captured_event_m+y*3,6);
            }
        a2_hd_guest_note(0xff4d,896,0,0);
        const A2HDGlyph *glyph=match(height);
        assert(glyph && glyph->codepoint=='M');
        assert(a2_hd_guest_advance(0xff4d,1)==glyph->advance);
        assert(!memcmp(PSX_RAM+address,bank,size)); /* Source stays native. */
        assert(a2_hd_guest_advance(0x004d,12)==12); /* Japanese token remains original. */
        a2_hd_guest_note(0x004d,896,0,0);assert(!match(height));
        a2_hd_guest_note(0xff4d,896,0,0);assert(match(height)==glyph);
        actual_vram[260*1024+897]^=1;assert(!match(height));
        upload(bank,height);assert(match(height)==glyph);
        /* A short dispatch fingerprint is never sufficient: a distant byte
         * change in RAM must invalidate a fresh upload annotation. */
        PSX_RAM[address+size-20]^=1;
        assert(a2_hd_guest_advance(0xff4d,1)==1);
        a2_hd_guest_note(0xff4d,896,0,0);assert(!match(height));
        memcpy(PSX_RAM+address,bank,size);a2_hd_guest_note(0xff4d,896,0,0);
        test_ir=1;assert(!match(height));assert(a2_hd_guest_advance(0xff4d,1)==1);test_ir=3;
    }
    /* The observed EVENT caption uses bank536 and cache (896,256). A later
     * bank548 upload without a corresponding note cannot inherit that source.
     * Conversely, switching the RAM bank alone must not invalidate old VRAM. */
    uint8_t original[7008],other[7008];
    size_t size=load_bank(argv[1],536,original);load_bank(argv[1],548,other);
    sw_(0x800640f0,0);memcpy(PSX_RAM+0x65b60,original,size);upload(original,16);
    a2_hd_font_reset();a2_hd_guest_note(0xff4d,896,0,0);assert(match(16));
    memcpy(PSX_RAM+0x65b60,other,size);assert(match(16));
    upload(other,16);assert(!match(16));
    a2_hd_guest_note(0xff4d,896,0,0);assert(match(16));
    a2_hd_font_reset();assert(!match(16));
    puts("All ten original Latin style banks: exact RAM/VRAM identity, stale-source and Japanese-token protection passed");
    return 0;
}
