/* Bit-exact optimized Q16 comparison with a frozen pre-optimization raster.
 * The independent integer division oracle intentionally remains slow. */
#define A2_WORLD_FP_STATS 1
#define main world_transport_existing_main
#include "test_world_precision_gpu.c"
#undef main
#include "reference_world_fine.inc"

static uint64_t exact_random_state=UINT64_C(0x91ed983c55a3271b);
static uint64_t exact_random(void) {
    uint64_t x=exact_random_state;x^=x<<13;x^=x>>7;x^=x<<17;
    return exact_random_state=x;
}
static void exact_quotients(void) {
    const int64_t denominators[]={1,2,3,65535,65536,65537,
        (INT64_C(1)<<53)-1,(INT64_C(1)<<53)+1,(INT64_C(1)<<59)-1};
    for(unsigned i=0;i<sizeof denominators/sizeof denominators[0];i++) {
        int64_t area=denominators[i];
        for(int quotient=-65280;quotient<=65280;quotient+=255) {
            const int64_t rem[]={-area+1,-1,0,1,area-1};
            for(unsigned r=0;r<5;r++) {
                __int128 numerator=(__int128)area*quotient+rem[r];
                assert(world_quotient_correct(numerator,area,(int)world_estimate(numerator,1.0/(double)area))==(int)(numerator/area));
            }
        }
    }
    for(unsigned i=0;i<200000;i++) {
        int64_t area=(int64_t)(exact_random()%((UINT64_C(1)<<59)-1))+1;
        int quotient=(int)(exact_random()%130561)-65280;
        __int128 numerator=(__int128)area*quotient+(int64_t)(exact_random()%(uint64_t)area);
        assert(world_quotient_correct(numerator,area,(int)world_estimate(numerator,1.0/(double)area))==(int)(numerator/area));
    }
}
static uint16_t exact_native[1024*512],exact_surface[1024*512*16];
static void exact_attribute_rows(void) {
    for(unsigned row=0;row<1000;row++) {
        int64_t area=(int64_t)(exact_random()%((UINT64_C(1)<<59)-1))+1;
        unsigned width=row<2?4096:(unsigned)(exact_random()%4096)+1;
        __int128 first=(__int128)area*(exact_random()%65281);
        __int128 end=(__int128)area*(exact_random()%65281);
        __int128 delta=width>1?(end-first)/(width-1):0;
        WorldFineStep step=world_fine_step(delta,area);
        WorldFineValue value=world_fine_value(first,area,1.0/(double)area);
        for(unsigned x=0;x<width;x++) {
            assert(value.quotient==(int)((first+delta*x)/area));
            assert(value.remainder>=0&&value.remainder<area);
            world_fine_advance(&value,step,area);
        }
    }
}
static void exact_rasters(void) {
    for(int scale=2;scale<=4;scale++)for(int sample=0;sample<160;sample++) {
        gpu_set_ir(scale);gpu_gp1(0);gpu_set_filter(sample<32?(sample&1):((sample-32)>>6));
        g.dax1=g.day1=0;g.dax2=g.day2=31;
        cur_tpage=0x104|((sample&3)<<5);cur_clut=0;
        for(unsigned i=0;i<1024*512;i++)GPU_VRAM[i]=(uint16_t)(i*9173u+0x582bu);
        memcpy(exact_native,GPU_VRAM,sizeof exact_native);
        size_t bytes=(size_t)IR_W*IR_H*2;
        memset(SHADOW,0x31,bytes);
        Vtx vertices[3];WorldFineTriangle triangle;
        for(int v=0;v<3;v++) {
            vertices[v]=(Vtx){0,0,(int)(exact_random()&255),(int)(exact_random()&255),
                (int)(exact_random()&255),(int)(exact_random()&255),(int)(exact_random()&255)};
            triangle.p[v]=(WorldFinePoint){(int64_t)(exact_random()%(64*65536))-16*65536,
                                          (int64_t)(exact_random()%(64*65536))-16*65536};
        }
        /* Exercise every constant/varying RGB mask and independent U/V
         * constants explicitly; random colors almost never make these. */
        if(sample>=32) {
            unsigned mask=(unsigned)(sample-32)&7,uv_mask=(unsigned)(sample-32)>>3;
            for(int v=1;v<3;v++) {
                if(mask&1)vertices[v].r=vertices[0].r;
                if(mask&2)vertices[v].gr=vertices[0].gr;
                if(mask&4)vertices[v].b=vertices[0].b;
                if(uv_mask&1)vertices[v].u=vertices[0].u;
                if(uv_mask&2)vertices[v].v=vertices[0].v;
            }
        }
        if(sample==0)triangle=(WorldFineTriangle){{{-1024LL*65536,-1024LL*65536},
                           {1023LL*65536,1023LL*65536+1},{1023LL*65536+1,1023LL*65536+2}}};
        if(sample==1)triangle=(WorldFineTriangle){{{0,0},{31*65536,0},{0,31*65536}}};
        if(sample==2)triangle=(WorldFineTriangle){{{0,0},{0,31*65536},{31*65536,0}}};
        if(sample==3)triangle=(WorldFineTriangle){{{10*65536,10*65536},{10*65536+1,10*65536},
                                                    {10*65536,10*65536+1}}};
        if((sample>=4&&sample<=7)||(sample>=20&&sample<=23)) {
            g.dax2=1023;g.day2=1;
            triangle=(WorldFineTriangle){{{0,0},{1024LL*65536-1,0},{1024LL*65536-1,2*65536}}};
        }
        int gouraud=(sample>>1)&1,tex=(sample>>2)&1,semi=(sample>>3)&1;
        double depths[]={1.0/33,1.0/611,1.0/974};
        const double *inverse=sample&16?depths:NULL;
        if(sample>=32){gouraud=tex=1;inverse=(sample-32)&32?depths:NULL;}
        reference_world_fine(vertices[0],vertices[1],vertices[2],triangle,gouraud,tex,semi,scale,inverse);
        memcpy(exact_surface,SHADOW,bytes);memset(SHADOW,0x31,bytes);
        raster_tri_world_fine(vertices[0],vertices[1],vertices[2],triangle,gouraud,tex,semi,scale,inverse);
        if(memcmp(exact_surface,SHADOW,bytes))fprintf(stderr,"fine reference mismatch IR%d case%d\n",scale,sample);
        assert(!memcmp(exact_surface,SHADOW,bytes));
        assert(!memcmp(exact_native,GPU_VRAM,sizeof exact_native));
    }
}
#include "test_world_float_rows.inc"

int main(void) {
    fp_row_tests();exact_quotients();exact_attribute_rows();exact_rasters();
    puts("PASS: signed quotient oracle,1000 exact long attribute rows and480 full fine/native surface comparisons");
    return 0;
}
