/* Real CPU rasterizer, independent scalar sampler oracle and bounded benchmark.
 * cc -O3 -UNDEBUG -Iport/src port/tests/test_gpu_filter.c -o /tmp/a2-filter-test
 * /tmp/a2-filter-test [contract | bench ITERATIONS]
 * For timings compile with -DA2_GPU_FILTER_BENCH to omit tap-count instrumentation.
 * No SDL, disc, save files, generated guest code, or live application. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef A2_GPU_FILTER_BENCH
#define A2_GPU_RECT_TEST 1
#endif
#include "../src/gpu.c"

uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t psx_frame_no, gpu_flips;
void psx_vblank_tick(void) {}
uint32_t psx_mmio_read(uint32_t p,int n) {(void)p;(void)n;return 0;}
int a2_modelcap_active(void) {return 0;}
FILE *a2_modelcap_file(void) {return NULL;}
static uint16_t initial[1024*512], native_before[1024*512];

static int floor256(int value) { return value / 256 - (value < 0 && value % 256 != 0); }
/* Separate bit-address oracle: no production sampler, window helper, channel
 * mixer or cached page state computes the expected result. */
static uint16_t reference_texel(int u,int v) {
    unsigned coords[2] = {(unsigned)u & 255u, (unsigned)v & 255u};
    for (unsigned axis=0;axis<2;axis++) {
        unsigned mask=(g.texwin>>(axis*5))&31u;
        unsigned offset=(g.texwin>>(10+axis*5))&31u;
        for (unsigned bit=0;bit<5;bit++) if(mask&(1u<<bit)) {
            coords[axis]&=~(1u<<(bit+3));
            coords[axis]|=((offset>>bit)&1u)<<(bit+3);
        }
    }
    unsigned bits=(cur_tpage>>7)&3u;
    bits=bits==0?4:bits==1?8:16;
    unsigned x=((cur_tpage&15u)*64+coords[0]*bits/16)&1023u;
    unsigned y=(((cur_tpage>>4)&1u)*256+coords[1])&511u;
    uint16_t packed=GPU_VRAM[y*1024+x];
    if(bits==16)return packed;
    unsigned index=(packed>>(coords[0]*bits%16))&((1u<<bits)-1);
    x=((cur_clut&63u)*16+index)&1023u; y=(cur_clut>>6)&511u;
    return GPU_VRAM[y*1024+x];
}
/* Independent tap clamp, unlike production's fractional-coordinate clamp.
 * The full-image fixture below has logical UV extrema0..255 on both axes. */
static uint16_t reference_filter_tap(int u,int v,int bounded) {
    if(bounded) {if(u<0)u=0;if(u>255)u=255;if(v<0)v=0;if(v>255)v=255;}
    return reference_texel(u,v);
}
static uint16_t reference_filter_rect(int uf,int vf,int bounded) {
    int u=floor256(uf),v=floor256(vf);
    unsigned fraction[2]={(unsigned)(uf-u*256),(unsigned)(vf-v*256)};
    uint16_t near=reference_filter_tap(u+(fraction[0]>=128),v+(fraction[1]>=128),bounded);
    if(!near)return 0;
    unsigned channels[3]={0},weight=0;
    for(unsigned y=0;y<2;y++)for(unsigned x=0;x<2;x++) {
        uint16_t pixel=reference_filter_tap(u+(int)x,v+(int)y,bounded);
        if(!pixel)continue;
        unsigned w=(x?fraction[0]:256-fraction[0])*(y?fraction[1]:256-fraction[1]);
        weight+=w;
        for(unsigned channel=0;channel<3;channel++)channels[channel]+=((pixel>>(5*channel))&31u)*w;
    }
    if(!weight)return near;
    unsigned result=near&0x8000;
    for(unsigned channel=0;channel<3;channel++)result|=(channels[channel]/weight)<<(5*channel);
    return result?(uint16_t)result:near;
}
static uint16_t reference_filter(int uf,int vf) {return reference_filter_rect(uf,vf,0);}
static FineTexCache checked_cache;
static void reset_checked_cache(void) {
    for(unsigned i=0;i<64;i++)checked_cache.cells[i].key=UINT32_MAX;
}
static void compare_sample(int u,int v) {
    uint16_t expected=reference_filter(u,v),got=sample_tex_fine(u,v);
    uint16_t cached=sample_tex_cached(u,v,&checked_cache);
    if(cached!=expected){fprintf(stderr,"cached filter UV%d,%d got%04x expected%04x\n",u,v,cached,expected);abort();}
    if(got!=expected) {
        fprintf(stderr,"filter UV%d,%d page%x clut%x window%x: got%04x expected%04x\n",
                u,v,cur_tpage,cur_clut,g.texwin,got,expected);abort();
    }
    assert(sample_tex(floor256(u),floor256(v))==reference_texel(floor256(u),floor256(v)));
}
static void random_reference_contract(void) {
    uint32_t random=0x4a26c357;
    for(unsigned i=0;i<1024*512;i++) {
        random^=random<<13;random^=random>>17;random^=random<<5;
        GPU_VRAM[i]=i%7?(uint16_t)random:0;
    }
    const unsigned windows[]={0,0x731c,0xfffff,0x54321,0x7c01f,0x10842};
    const unsigned pages[]={0,15,16,31},cluts[]={0,0x7fff,0x7e30,0x43f};
    const int boundary[]={-65793,-65537,-65536,-257,-256,-255,-129,-128,-1,0,1,127,128,255,
                          256,65407,65408,65535,65536,65537,131071};
    for(unsigned mode=0;mode<4;mode++)for(unsigned win=0;win<6;win++)
        for(unsigned page=0;page<4;page++) {
            cur_tpage=pages[page]|(mode<<7);cur_clut=cluts[page];g.texwin=windows[win];reset_checked_cache();
            for(unsigned i=0;i<sizeof boundary/sizeof boundary[0];i++)
                for(unsigned j=0;j<sizeof boundary/sizeof boundary[0];j++)compare_sample(boundary[i],boundary[j]);
            for(unsigned i=0;i<4000;i++) {
                random=random*1664525u+1013904223u;int u=(int)(random%196609u)-65537;
                random=random*1664525u+1013904223u;int v=(int)(random%196609u)-65537;
                compare_sample(u,v);
            }
        }
}
static void transparent_and_stp_contract(void) {
    const unsigned fractions[]={0,1,127,128,129,255};
    const uint16_t colors[]={1,0x001f,0x03e0,0x7c00};
    cur_tpage=2u<<7;cur_clut=0;g.texwin=0;
    for(unsigned zeros=0;zeros<16;zeros++)for(unsigned stp=0;stp<16;stp++) {
        for(unsigned tap=0;tap<4;tap++)GPU_VRAM[(tap/2)*1024+tap%2]=
            zeros&(1u<<tap)?0:colors[tap]|(stp&(1u<<tap)?0x8000:0);
        reset_checked_cache();
        for(unsigned y=0;y<6;y++)for(unsigned x=0;x<6;x++)compare_sample(fractions[x],fractions[y]);
    }
    for(unsigned color=0;color<=65535;color+=257) {
        GPU_VRAM[0]=GPU_VRAM[1]=GPU_VRAM[1024]=GPU_VRAM[1025]=(uint16_t)color;
        reset_checked_cache();compare_sample(73,219);
    }
}
/* Opposite opaque black/white corners exercise coefficient intermediates
 * beyond signed64 range while the exact final packed sum remains in range. */
static void opaque_checkerboard_contract(void) {
    const unsigned fractions[]={0,1,127,128,129,254,255};
    cur_tpage=2u<<7;cur_clut=0;g.texwin=0;
    for(unsigned flip=0;flip<2;flip++)for(unsigned stp=0;stp<16;stp++) {
        for(unsigned i=0;i<4;i++) {
            int white=((i==1||i==2)?1:0)^(int)flip;
            GPU_VRAM[(i/2)*1024+i%2]=white?(uint16_t)(0x7fff|(stp&(1u<<i)?0x8000:0)):0x8000;
        }
        reset_checked_cache();
        for(unsigned y=0;y<7;y++)for(unsigned x=0;x<7;x++)compare_sample(fractions[x],fractions[y]);
    }
}
/* This performance contract fails when transparent cutouts fetch all four
 * taps even though the nearest tap alone determines the unchanged zero result. */
#ifndef A2_GPU_FILTER_BENCH
static void transparent_nearest_short_circuits(void) {
    cur_tpage=2u<<7;g.texwin=0;
    GPU_VRAM[0]=0;GPU_VRAM[1]=31;GPU_VRAM[1024]=0x83e0;GPU_VRAM[1025]=0x7c00;
    gpu_rect_test_samples=0;
    assert(sample_tex_fine(64,64)==0);
    assert(gpu_rect_test_samples==1);
}
#endif
static uint32_t xy(unsigned x,unsigned y) {return x|(y<<16);}
static void polygon(unsigned mode,int semi) {
    gpu_gp0((semi?0x3e000000u:0x3c000000u)|0x4080c0);
    gpu_gp0(xy(0,0));gpu_gp0(0x7fe00000u);
    gpu_gp0(0xc04080);gpu_gp0(xy(319,0));gpu_gp0(((24u|(mode<<7))<<16)|255);
    gpu_gp0(0x80c040);gpu_gp0(xy(0,224));gpu_gp0(255u<<8);
    gpu_gp0(0x808080);gpu_gp0(xy(319,224));gpu_gp0(0xffff);
}
static void scene(unsigned mode,int cutout,int filter) {
    gpu_set_ir(3);gpu_gp1(0);gpu_set_filter(filter);
    for(unsigned i=0;i<1024*512;i++)initial[i]=(uint16_t)(((i*73u+(i>>7))&0x7fff)|0x8000);
    for(unsigned i=0;i<256;i++)initial[511*1024+512+i]=cutout&&i%5==0?0:(uint16_t)(i*97u|0x8000);
    if(mode>=2&&cutout)for(unsigned y=256;y<512;y++)for(unsigned x=512;x<768;x++)
        if((x+y)%5==0)initial[y*1024+x]=0;
    memcpy(GPU_VRAM,initial,sizeof initial);
    memset(SHADOW,0,(size_t)IR_W*IR_H*sizeof *SHADOW);
    gpu_gp0(0xe3000000);gpu_gp0(0xe4000000|319|(223<<10));
}
static uint64_t hash(const uint16_t *p,size_t n) {
    uint64_t h=1469598103934665603ull;
    for(size_t i=0;i<n;i++)h=(h^p[i])*1099511628211ull;
    return h;
}
/* Independent axis-aligned two-triangle oracle. Integer right-triangle
 * distances derive every expected output channel; no raster/put_px helper is
 * reused. This checks every SHADOW word, including untouched exterior pixels. */
static void polygon_pixels_contract(int filter,int semi) {
    const unsigned width=319*3,height=224*3,area=width*height;
    const unsigned colors[]={0x4080c0,0xc04080,0x80c040,0x808080};
    for(unsigned y=0;y<(unsigned)IR_H;y++)for(unsigned x=0;x<(unsigned)IR_W;x++) {
        unsigned expected=0;
        if(x<width&&y<height) {
            uint16_t texel=filter?reference_filter_rect((int)(x*255u*256/width)-128,(int)(y*255u*256/height)-128,1)
                                 :reference_texel((int)(x*255u/width),(int)(y*255u/height));
            if(texel) {
                unsigned weights[4]={0};
                if(x*height+y*width<=area) {
                    weights[1]=x*height;weights[2]=y*width;weights[0]=area-weights[1]-weights[2];
                } else {
                    weights[1]=(height-y)*width;weights[2]=(width-x)*height;weights[3]=area-weights[1]-weights[2];
                }
                expected=texel&0x8000;
                for(unsigned channel=0;channel<3;channel++) {
                    unsigned shade=0;
                    for(unsigned vertex=0;vertex<4;vertex++)shade+=weights[vertex]*((colors[vertex]>>(8*channel))&255u);
                    shade/=area;
                    unsigned component=(((texel>>(channel*5))&31u)*8*shade)/128;
                    if(component>255)component=255;
                    if(semi&&(texel&0x8000))component/=2;
                    expected|=(component/8)<<(channel*5);
                }
            }
        }
        if(SHADOW[(size_t)y*IR_W+x]!=expected) {
            fprintf(stderr,"polygon filter%d semi%d (%u,%u): got%04x expected%04x\n",filter,semi,x,y,
                    SHADOW[(size_t)y*IR_W+x],expected);abort();
        }
    }
}
static void polygon_native_contract(void) {
    for(unsigned mode=0;mode<3;mode++)for(int cutout=0;cutout<2;cutout++)for(int semi=0;semi<2;semi++) {
        scene(mode,cutout,0);polygon(mode,semi);memcpy(native_before,GPU_VRAM,sizeof native_before);
        polygon_pixels_contract(0,semi);
        scene(mode,cutout,1);polygon(mode,semi);
        assert(!memcmp(native_before,GPU_VRAM,sizeof native_before));
        polygon_pixels_contract(1,semi);
    }
}
/* A high-resolution border must not borrow a contrasting atlas neighbour.
 * This exercises real GP0 decode, both quad halves, the filter and native VRAM.
 * Disabling the primitive bounds or applying them after wrapping must fail. */
static void atlas_patch_setup(unsigned mode,int scale,int page,int low,int stp) {
    gpu_set_ir(scale);gpu_gp1(0);
    cur_tpage=8u|(mode<<7)|((page?0u:1u)<<4);cur_clut=(511u<<6)|16u;
    for(unsigned i=0;i<1024*512;i++)GPU_VRAM[i]=mode<2?0x1111:0x7c1f;
    if(mode<2) {
        GPU_VRAM[511*1024+257]=0x7c1f;
        GPU_VRAM[511*1024+258]=(uint16_t)(0x03e0|(stp?0x8000:0));
    }
    for(unsigned v=(unsigned)low;v<=(unsigned)low+7;v++)
    for(unsigned u=(unsigned)low;u<=(unsigned)low+7;u++) {
        unsigned bits=mode==0?4:mode==1?8:16;
        unsigned xx=512+u*bits/16,yy=(page?0:256)+v,shift=u*bits%16;
        if(mode<2)GPU_VRAM[yy*1024+xx]=(uint16_t)((GPU_VRAM[yy*1024+xx]&~(((1u<<bits)-1)<<shift))|(2u<<shift));
        else GPU_VRAM[yy*1024+xx]=(uint16_t)(0x03e0|(stp?0x8000:0));
    }
    for(int y=page*scale;y<(page+32)*scale;y++)
        memset(SHADOW+(size_t)y*IR_W,0,(size_t)32*scale*sizeof *SHADOW);
    gpu_gp0(0xe3000000u|((unsigned)page<<10));
    gpu_gp0(0xe4000000u|319u|((unsigned)(page+215)<<10));
    gpu_gp0(0xe5000000u|((unsigned)page<<11));
}
static void atlas_patch_draw(unsigned mode,int page,int low,int quad,int semi,int width) {
    unsigned command=0x24u|(quad?8u:0u)|(semi?2u:0u);
    uint32_t uv[4]={(unsigned)low|((unsigned)low<<8),
        (unsigned)(low+7)|((unsigned)low<<8),
        (unsigned)low|((unsigned)(low+7)<<8),(unsigned)(low+7)|((unsigned)(low+7)<<8)};
    const unsigned xx[4]={4,4+(unsigned)width,4,4+(unsigned)width},yy[4]={4,4,28,28};
    gpu_gp0((command<<24)|0x808080);
    for(unsigned i=0;i<(quad?4u:3u);i++) {
        gpu_gp0(xy(xx[i],yy[i]));
        gpu_gp0(uv[i]|(i==0?((511u<<6)|16u)<<16:i==1?(8u|(mode<<7)|((page?0u:1u)<<4))<<16:0));
    }
}
static void polygon_filter_atlas_border_contract(void) {
    for(unsigned mode=0;mode<4;mode++)for(int scale=2;scale<=4;scale++)
    for(int page=0;page<=256;page+=256)for(int low=0;low<=32;low+=32)
    for(int quad=0;quad<2;quad++)for(int semi=0;semi<2;semi++) {
        atlas_patch_setup(mode,scale,page,low,semi);gpu_set_filter(0);
        atlas_patch_draw(mode,page,low,quad,semi,24);memcpy(native_before,GPU_VRAM,sizeof native_before);
        atlas_patch_setup(mode,scale,page,low,semi);gpu_set_filter(1);
        atlas_patch_draw(mode,page,low,quad,semi,24);
        assert(!memcmp(native_before,GPU_VRAM,sizeof native_before));
        uint16_t expected=semi?0x81e0:0x03e0;
        uint16_t left=*shadow_px(4*scale,(page+10)*scale);
        if(left!=expected) {
            fprintf(stderr,"atlas border mode%u IR%d page%d UVmin%d quad%d semi%d: got%04x expected%04x\n",mode,scale,page,low,quad,semi,left,expected);abort();
        }
        assert(*shadow_px(10*scale,(page+4)*scale)==expected);
        assert(*shadow_px(10*scale,(page+10)*scale)==expected);
        if(quad)assert(*shadow_px(24*scale,(page+24)*scale)==expected);
    }
}
/* Seven texels across one native pixel disables the magnification cache.
 * This border must therefore remain green through the direct fine sampler. */
static void minified_atlas_border_contract(void) {
    for(unsigned mode=0;mode<4;mode++) {
        atlas_patch_setup(mode,4,0,32,0);gpu_set_filter(1);
        atlas_patch_draw(mode,0,32,1,0,1);
        assert(*shadow_px(16,40)==0x03e0);
    }
    atlas_patch_setup(2,4,0,32,0);gpu_set_filter(1);
    for(unsigned y=32;y<=39;y++)for(unsigned x=32;x<=39;x++)
        GPU_VRAM[(256+y)*1024+512+x]=0;
    atlas_patch_draw(2,0,32,1,0,24);
    assert(*shadow_px(16,40)==0); /* A transparent nearest texel stays a hole. */
}
/* A corner of the second half extends the whole quad UV range. A per-half
 * clamp would incorrectly flatten the first half's valid red/green blend. */
static void quad_shared_uv_bounds_contract(void) {
    atlas_patch_setup(2,4,0,32,0);gpu_set_filter(1);
    for(unsigned y=32;y<=39;y++)GPU_VRAM[(256+y)*1024+512+31]=0x001f;
    const unsigned xx[4]={4,28,4,28},yy[4]={4,4,28,28};
    const unsigned uu[4]={32,39,32,16},vv[4]={32,32,39,39};
    gpu_gp0(0x2c808080);
    for(unsigned i=0;i<4;i++) {
        gpu_gp0(xy(xx[i],yy[i]));
        gpu_gp0(uu[i]|(vv[i]<<8)|(i==1?0x118u<<16:0));
    }
    assert(*shadow_px(16,40)==0x01ef); /* Half red31 + half green31. */
    /* The next unrelated direct sample is deliberately outside those bounds.
     * State leaking beyond the GP0 body would substitute the magenta u16. */
    GPU_VRAM[(256+35)*1024+512]=GPU_VRAM[(256+35)*1024+767]=0x001f;
    assert(sample_tex_fine(-128,35*256)==0x001f);
    reset_checked_cache();assert(sample_tex_cached(-128,35*256,&checked_cache)==0x001f);
}
static double now(void) {
    struct timespec t;assert(clock_gettime(CLOCK_MONOTONIC,&t)==0);
    return t.tv_sec+t.tv_nsec*1e-9;
}
static void benchmark(int iterations) {
    assert(iterations>0&&iterations<=100);
    for(unsigned mode=0;mode<3;mode++)for(int cutout=0;cutout<2;cutout++)for(int filter=0;filter<2;filter++) {
        double elapsed[3];uint64_t native=0,fine=0;
        for(unsigned trial=0;trial<3;trial++) {
            scene(mode,cutout,filter);polygon(mode,0);
            double start=now();for(int i=0;i<iterations;i++)polygon(mode,0);
            elapsed[trial]=(now()-start)*1000/iterations;
            native=hash(GPU_VRAM,1024*512);fine=hash(SHADOW,(size_t)IR_W*IR_H);
        }
        if(elapsed[0]>elapsed[1]){double t=elapsed[0];elapsed[0]=elapsed[1];elapsed[1]=t;}
        if(elapsed[1]>elapsed[2]){double t=elapsed[1];elapsed[1]=elapsed[2];elapsed[2]=t;}
        if(elapsed[0]>elapsed[1]){double t=elapsed[0];elapsed[0]=elapsed[1];elapsed[1]=t;}
        printf("IR3 mode%u cutout%d filter%d median_ms=%.6f native=%016llx fine=%016llx\n",mode,cutout,filter,elapsed[1],
               (unsigned long long)native,(unsigned long long)fine);
    }
}
#ifndef A2_GPU_FILTER_BENCH
/* A magnified 4bpp quad needs fewer than one million source fetches. The
 * uncached path does 2,643,872; the pixel oracles above independently prevent
 * meeting this budget by dropping coverage or changing filter output. */
static void magnified_filtered_quad_fetch_budget(void) {
    scene(0,0,1);gpu_rect_test_samples=0;polygon(0,0);
    assert(gpu_rect_test_samples<1000000);
}
#endif
int main(int argc,char **argv) {
    if(argc>1&&!strcmp(argv[1],"bench"))benchmark(argc>2?atoi(argv[2]):5);
    else {
        polygon_filter_atlas_border_contract();minified_atlas_border_contract();quad_shared_uv_bounds_contract();
        random_reference_contract();transparent_and_stp_contract();opaque_checkerboard_contract();polygon_native_contract();
#ifndef A2_GPU_FILTER_BENCH
        if(argc==1){transparent_nearest_short_circuits();magnified_filtered_quad_fetch_budget();}
#endif
        puts("PASS: exact filtered/nearest samplers, transparent/STP/wrap/window modes, Gouraud native VRAM");
    }
    gpu_set_ir(1);return 0;
}
