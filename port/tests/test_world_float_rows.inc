#include <fenv.h>

static void fp_check_row(__int128 numerator,__int128 delta,int64_t area,unsigned width) {
    WorldFloatCold cold={numerator,delta};
    WorldFineStep exact=world_fine_step(delta,area);
    WorldFloatStep step=world_float_step(delta,area,exact);
    WorldFloatValue value=world_float_value(numerator,delta,area,step,width);
    for(unsigned x=0;x<width;x++) {
        __int128 current=numerator+(__int128)x*delta;
        assert(current>=0&&current<=(__int128)65280*area);
        int expected=(int)(current/area);
        int actual=world_float_sample(&value,&cold,x,area);
        if(actual!=expected)fprintf(stderr,"FP row mismatch width%u x%u expected%d actual%d value%.17g\n",width,x,expected,actual,value.value);
        assert(actual==expected);
        if(value.guard>=0)assert(fabs(value.value-(double)current/(double)area)<0x1p-22);
        if(x+1<width)value.value+=value.increment;
    }
}
static void fp_row_tests(void) {
    /* The production contract is nearest rounding. Establish it explicitly
     * for this proof fixture, then restore the caller's process mode. */
    int saved_rounding=fegetround();
    assert(saved_rounding!=-1&&fesetround(FE_TONEAREST)==0);
    const int64_t areas[]={1,2,3,65535,65536,65537,
        (INT64_C(1)<<53)-1,(INT64_C(1)<<53)+1,(INT64_C(1)<<59)-1};
    for(unsigned ai=0;ai<sizeof areas/sizeof areas[0];ai++) {
        int64_t area=areas[ai];
        for(unsigned width=1;width<=4096;width=width==1?2:width==2?4095:width+1) {
            /* Maximal owned gradient, both signs, integral and near-integer
             * starting values on both sides of representable boundaries. */
            __int128 end=(__int128)65280*area;
            __int128 gradient=width>1?end/(width-1):end;
            fp_check_row(0,gradient,area,width);
            fp_check_row(end,-gradient,area,width);
            fp_check_row((__int128)32000*area,0,area,width);
            if(area>1) {
                fp_check_row((__int128)32000*area-1,1,area,width);
                fp_check_row((__int128)32000*area+1,-1,area,width);
            }
            if(width>1) {
                fp_check_row((__int128)10000*area,area,area,width);
                fp_check_row((__int128)10000*area,-area,area,width);
            }
        }
    }
    /* Exactly representable fractional crossings must use the guarded
     * correction; integer gradients bypass it without losing fractional a0. */
#ifdef A2_WORLD_FP_STATS
    uint64_t before=world_fp_guarded;
    fp_check_row(20001,2,2,4096);
    assert(world_fp_guarded==before);
    fp_check_row(20000,1,2,4096);
    assert(world_fp_guarded-before==2048);
    before=world_fp_guarded;
    fp_check_row(((__int128)1<<59)-2,0,(INT64_C(1)<<59)-1,1);
    assert(world_fp_guarded==before); /* Width-one exact evaluator. */
#endif
    for(int denominator=2;denominator<=4;denominator*=2) {
        fp_check_row(10000*denominator,1,denominator,4096);
        fp_check_row(10000*denominator,-1,denominator,4096);
        fp_check_row(10000*denominator+1,denominator,denominator,4096);
        fp_check_row(10000*denominator-1,-denominator,denominator,4096);
    }
    for(unsigned row=0;row<10000;row++) {
        int64_t area=(int64_t)(exact_random()%((UINT64_C(1)<<59)-1))+1;
        unsigned width=(unsigned)(exact_random()%4096)+1;
        __int128 first=(__int128)(exact_random()%65280)*area+exact_random()%(uint64_t)area;
        __int128 end=(__int128)(exact_random()%65280)*area+exact_random()%(uint64_t)area;
        __int128 delta=width>1?(end-first)/(width-1):end-first;
        fp_check_row(first,delta,area,width);
    }
    assert(fesetround(saved_rounding)==0);
    puts("PASS: guarded FP UV row quotient/boundary oracle, 10000 random rows plus exact crossings and widths1/4096");
}
