/* Real HD compositor, former two-shade oracle, full-buffer comparison.
 * Instrument function entries to count actual pixel-shading calls without adding
 * counters or test branches to production code.
 * cc -O2 -finstrument-functions -Isrc tests/test_hd_art_shade_endpoints.c src/hd_art.c -o /tmp/a2-art-endpoints
 */
#define main existing_hd_art_gpu_main
#include "test_hd_art_gpu.c"
#undef main

static unsigned long shade_calls;
void __attribute__((no_instrument_function))
__cyg_profile_func_enter(void *fn,void *caller) {
    (void)caller;
    /* The reference writes through put_fine; HD now evaluates the same
     * shading through pure fine_color for each independent destination. */
    if(fn==(void *)put_fine || fn==(void *)fine_color)shade_calls++;
}
void __attribute__((no_instrument_function))
__cyg_profile_func_exit(void *fn,void *caller) {(void)fn;(void)caller;}

/* Retain the original compositing order, including both art alternatives
 * against the same original destination and subsequent word layers. */
static int original_hd(int fx,int fy,int r,int grn,int b,int semi,int u,int v) {
    A2HDUISample word;
    int has_word=hd_plate_count && a2_hd_ui_sample(hd_plates,hd_plate_count,GPU_VRAM,cur_clut,u,v,&word);
    A2HDArtSample art;
    a2_hd_art_window_uv(g.texwin,&u,&v);
    int has_art=hd_art_count && a2_hd_art_sample(hd_art,hd_art_count,GPU_VRAM,cur_clut,u,v,&art);
    if(!has_word && !has_art)return 0;
    if(fx<g.dax1*IR || fx>=(g.dax2+1)*IR || fy<g.day1*IR || fy>=(g.day2+1)*IR)return 1;
    uint16_t *dst=shadow_px(fx,fy),before=*dst,base;
    if(has_art) {
        put_fine(fx,fy,r,grn,b,semi,1,art.first);
        uint16_t first=*dst;
        *dst=before;put_fine(fx,fy,r,grn,b,semi,1,art.second);
        base=coverage_mix(before,coverage_mix(first,*dst,art.mix),art.coverage);
    } else {
        put_fine(fx,fy,r,grn,b,semi,1,word.background);base=*dst;
    }
    if(has_word && word.shadow_alpha && word.shadow) {
        *dst=before;put_fine(fx,fy,r,grn,b,semi,1,word.shadow);
        base=coverage_mix(base,*dst,word.shadow_alpha);
    }
    if(has_word && word.alpha && word.ink) {
        *dst=before;put_fine(fx,fy,r,grn,b,semi,1,word.ink);
        base=coverage_mix(base,*dst,word.alpha);
    }
    *dst=base;return 1;
}

static uint8_t word_alpha[64],word_background[4]={6,6,6,6};
static const A2HDPlate word_plate={8,16,2,2,6,7,source4,word_background,word_alpha};
static unsigned long draw_endpoints(int reference,int words,unsigned bpp,unsigned mode,int semi,unsigned state) {
    setup(1,bpp,mode);
    colors[4]=state&1?0:0x93df;colors[5]=state&2?0:0x03e0;
    colors[6]=0x8c63;colors[7]=0x4210;
    for(unsigned i=0;i<256;i++)GPU_VRAM[500*1024+i]=colors[i];
    memset(SHADOW,0x5a,(size_t)IR_W*IR_H*sizeof *SHADOW);
    cur_clut=500u<<6;cur_tpage=g.texpage;
    hd_art_count=a2_hd_art_prepare(a2_hd_art_assets,2,GPU_VRAM,cur_tpage,8,16,9,17,hd_art,128);
    assert(hd_art_count==1);
    hd_plate_count=words;hd_plates[0]=&word_plate;
    unsigned long wanted=0;
    shade_calls=0;
    const unsigned alpha[]={0,173,255},mix[]={0,109,255};
    for(unsigned a=0;a<3;a++)for(unsigned m=0;m<3;m++) {
        for(unsigned i=0;i<64;i++)pixels[i]=(alpha[a]<<24)|(mix[m]<<16)|(5u<<8)|4u;
        for(int y=0;y<2*IR;y++)for(int x=0;x<2*IR;x++) {
            int u=8*256+x*256/IR,v=16*256+y*256/IR;
            /* Independent destination tiles: a later opaque combination must
               never erase an earlier endpoint mismatch before comparison. */
            int fx=(8+(int)m*3)*IR+x,fy=(8+(int)a*3)*IR+y;
            wanted+=alpha[a]?(mix[m]==0 || mix[m]==255?1:2):0;
            if(words) {
                /* The fixture uses nonzero ink/shadow and constant alpha. */
                wanted++;
                if((x*256/IR)>=64 && (y*256/IR)>=64)wanted++;
            }
            assert((reference?original_hd:put_hd_ui)(fx,fy,0x48,0x60,0x90,semi,u,v));
        }
        /* Clipped pixels must produce no shade calls for either compositor. */
        assert((reference?original_hd:put_hd_ui)(-1,-1,0x48,0x60,0x90,semi,8*256,16*256));
    }
    return wanted;
}

int main(void) {
    memset(word_alpha,137,sizeof word_alpha);
    uint16_t *expected=malloc(1024*512*16*sizeof *expected);assert(expected);
    unsigned cases=0,failures=0;
    unsigned long old_total=0,new_total=0;
    for(int scale=2;scale<=4;scale++) {
        gpu_set_ir(scale);
        for(unsigned bpp=4;bpp<=8;bpp+=4)for(unsigned mode=0;mode<4;mode++)
        for(int semi=0;semi<=1;semi++)for(unsigned state=0;state<4;state++)for(int words=0;words<=1;words++) {
            draw_endpoints(1,words,bpp,mode,semi,state);
            unsigned long old=shade_calls;
            assert(old>=2ul*9*4*scale*scale);
            save_native();memcpy(expected,SHADOW,(size_t)IR_W*IR_H*sizeof *SHADOW);
            unsigned long wanted=draw_endpoints(0,words,bpp,mode,semi,state);
            same_native();assert(!memcmp(expected,SHADOW,(size_t)IR_W*IR_H*sizeof *SHADOW));
            if(shade_calls!=wanted) {
                if(!failures)fprintf(stderr,"excess shading: IR%d bpp%u mode%u semi%d state%u words%d got=%lu wanted=%lu; full buffers identical\n",
                    scale,bpp,mode,semi,state,words,shade_calls,wanted);
                failures++;
            }
            old_total+=old;new_total+=shade_calls;cases++;
        }
    }
    free(expected);gpu_set_ir(1);
    printf("HD art endpoints: %u full-buffer cases, %u excess-shading failures; actual pixel-shading calls %lu -> %lu\n",cases,failures,old_total,new_total);
    return failures?1:0;
}
