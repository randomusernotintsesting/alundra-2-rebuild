/* Real resident name resolution, prepare/play continuations and entire manager
 * execute unchanged. Only the SDK boundary is replaced with a bounded command
 * completion shim over the production no-image controller. */
#define A2_NATIVE_REAL_GUEST 1
#define main native_voice_controller_fixture_main
#include "test_native_voice.c"
#undef main
#include "../gen/scps_014.c"
static const psx_func_entry guest_functions[]={
#include "native_voice_guest_table.inc"
};
uint32_t a2_ramwatch,psx_work;
int psx_bb_budget=1000000;
static int wait_resume,inject_reentrant,injected;
static uint32_t injected_api=0x8002ff90;
static uint32_t interrupted[32],completed[32],interrupted_hi,interrupted_lo,manager_sentinel;
static uint32_t completed_hi,completed_lo;
static void dispatch_segment(uint32_t target);
void psx_bb_fire(void){
    assert(wait_resume);wait_resume=0;psx_bb_budget=1000000;
    uint32_t b[32],bh=HI,bl=LO,bn=psx_next;memcpy(b,R,sizeof b);
    memcpy(R,interrupted,sizeof interrupted);HI=interrupted_hi;LO=interrupted_lo;psx_next=0x80030898;
    for(unsigned step=0;psx_next!=manager_sentinel;step++){assert(step<1000);dispatch_segment(psx_next);}
    memcpy(completed,R,sizeof completed);completed_hi=HI;completed_lo=LO;
    memcpy(R,b,sizeof b);HI=bh;LO=bl;psx_next=bn;
}
void a2_ramwatch_hit(uint32_t p,uint32_t v,int n){(void)p;(void)v;(void)n;assert(!"Unexpected RAM watch");}
void psx_break(uint32_t n){(void)n;assert(!"Unexpected resident break");}
void psx_syscall_at(uint32_t p){(void)p;assert(!"Unexpected syscall");}
uint32_t psx_mmio_read(uint32_t p,int n){(void)p;(void)n;assert(!"Unexpected raw MMIO read");return 0;}
void psx_mmio_write(uint32_t p,uint32_t v,int n){(void)p;(void)v;(void)n;assert(!"Unexpected raw MMIO write");}
static unsigned searches,enable_calls,mute_calls,serial,last_command;
static int skip_installed;
static uint8_t bcd(unsigned x){return (uint8_t)((x/10)*16+x%10);}
static uint32_t unbcd(uint8_t x){return (x>>4)*10+(x&15);}
static void position(uint32_t target,uint32_t destination){
    target+=150;uint8_t *p=PSX_RAM+(destination&0x1fffff);
    p[0]=bcd(target/4500);p[1]=bcd(target/75%60);p[2]=bcd(target%75);p[3]=0;
}
static int sdk(uint32_t address){
    switch(address){
    case 0x80042228: searches++;position(A2_NATIVE_VOICE_CLOCK_BASE,R[4]);R[2]=R[4];break;
    case 0x80041A28: position(R[4],R[5]);R[2]=R[5];break;
    case 0x80041B2C: {
        uint8_t *p=PSX_RAM+(R[4]&0x1fffff);R[2]=unbcd(p[0])*4500+unbcd(p[1])*75+unbcd(p[2])-150;break;
    }
    case 0x8004D868: assert(R[4]==1&&R[5]==1);enable_calls++;break;
    case 0x8004D9B0: break; // existing SPU volume writes tested by audio suite
    case 0x80041C18:case 0x80041C40:case 0x80041CA8:{
        unsigned command=R[4];param_n=command==2?3:command==13?2:command==14?1:0;
        for(int i=0;i<param_n;i++)param[i]=PSX_RAM[(R[5]+i)&0x1fffff];
        last_command=command;mute_calls+=command==11;cd_command((uint8_t)command);
        R[2]=address==0x80041C18?++serial:1;break;
    }
    case 0x8003EA70: {
        uint8_t *p=PSX_RAM+(R[5]&0x1fffff);memset(p,0,8);p[0]=2;
        if(last_command==17){p[0]=p[1]=1;position(cur_lba,R[5]+5);}
        R[2]=2;break;
    }
    case 0x8002B958:case 0x8002BB00:break; // sequenced music ducking setters
    default:return 0;
    }
    psx_next=R[31];return 1;
}
static void dispatch_segment(uint32_t target){
    if(!skip_installed)for(unsigned h=0;h<hook_count;h++)if(hooks[h].address==target){hooks[h].fn();return;}
    if(sdk(target))return;
    for(unsigned i=0;i<sizeof guest_functions/sizeof guest_functions[0];i++)
        if(guest_functions[i].addr==target){guest_functions[i].fn();return;}
    fprintf(stderr,"Unexpected guest continuation %08X\n",target);abort();
}
void psx_call(uint32_t address){
    static unsigned depth;uint32_t saved_ra=R[31],saved_next=psx_next;
    uint32_t sentinel=0xffaa0000+(++depth)*4;R[31]=sentinel;psx_next=address;
    for(unsigned step=0;psx_next!=sentinel;step++){
        assert(step<20000);uint32_t target=psx_next;
        if(inject_reentrant&&target==0x80030898){
            inject_reentrant=0;injected++;
            assert(lw_(0x80054748)==1); // lock was set by the actual manager
            memcpy(interrupted,R,sizeof interrupted);interrupted_hi=HI;interrupted_lo=LO;
            manager_sentinel=sentinel;wait_resume=1;psx_bb_budget=0;
            R[4]=0x80060010;psx_call(injected_api); // B waits while A is still preparing
            assert(!wait_resume);memcpy(R,completed,sizeof completed);HI=completed_hi;LO=completed_lo;
            psx_next=sentinel;continue;
        }
        dispatch_segment(target);
    }
    depth--;R[31]=saved_ra;psx_next=saved_next;
}
static void check_callee(const uint32_t before[32]){
    for(unsigned i=16;i<=23;i++)assert(R[i]==before[i]);
    for(unsigned i=28;i<=31;i++)assert(R[i]==before[i]);
}
int main(void){
    fixture();R[29]=0x801fff00;R[31]=0x87654321;
    for(unsigned i=16;i<=23;i++)R[i]=i*123456;
    HI=0xabc;LO=0xdef;uint32_t saved[32];memcpy(saved,R,sizeof saved);
    // Original initializer provides the semantic side-effect oracle.
    skip_installed=1;psx_call(0x8002fcf0);check_callee(saved);
    assert(searches==2&&enable_calls==1&&mute_calls==1&&R[2]==1);
    uint8_t initialized[48];memcpy(initialized,PSX_RAM+0x79eb0,sizeof initialized);
    assert(HI==0xabc&&LO==0xdef);
    char error[256];assert(a2_native_voice_open(&store,0,PSX_RAM,sizeof PSX_RAM,error,sizeof error));
    a2_native_voice_install();skip_installed=0;
    memset(PSX_RAM+0x79eb0,0xa5,sizeof initialized);
    psx_call(0x8002fcf0);check_callee(saved);
    // Only the five fields actually initialized by the original are compared.
    unsigned offsets[]={0,4,28,40,44};
    for(unsigned i=0;i<5;i++)assert(!memcmp(PSX_RAM+0x79eb0+offsets[i],initialized+offsets[i],4));
    assert(searches==2&&enable_calls==2&&mute_calls==2&&HI==0xabc&&LO==0xdef);
    memset(PSX_RAM+0x79eb8,0,4);put(PSX_RAM+0x5474c,0);put(PSX_RAM+0x79ed8,0);
    cd_boot_handoff();irq_en=0x1f;
    R[4]=0x80060000;psx_call(0x800301b8);check_callee(saved);assert(!reading);
    R[4]=0x80060000;psx_call(0x800302e4);check_callee(saved);assert(!reading);
    R[4]=0x80060000;psx_call(0x8002ff90);check_callee(saved);
    assert(lw_(0x80079ec0)==A2_NATIVE_VOICE_CLOCK_BASE);
    assert(lw_(0x80079ed0)==A2_NATIVE_VOICE_CLOCK_BASE+3*8-1);
    for(unsigned frame=0;frame<120;frame++){ticks(1);psx_call(0x800304b8);check_callee(saved);}
    assert(pushes==3&&frames_pushed==6048&&data_interrupts==0);
    assert(lw_(0x8005474c)==0&&!reading&&img==NULL&&!a2_native_voice_error()[0]);
    // A still owns the resident lock immediately before ReadN. B must not
    // replace the native request until B's genuine busy wait has finished.
    uint32_t requests[]={0x8002ff90,0x800301b8,0x800302e4};
    for(unsigned i=0;i<3;i++){
        R[4]=0x80060000;psx_call(0x8002ff90);inject_reentrant=1;injected_api=requests[i];
        for(unsigned frame=0;frame<150;frame++){ticks(1);psx_call(0x800304b8);}
        if(a2_native_voice_error()[0])fprintf(stderr,"Reentrant named request failed: %s\n",a2_native_voice_error());
        assert(injected==(int)i+1&&!a2_native_voice_error()[0]);
        assert(lw_(0x8005474c)==0&&!reading&&data_interrupts==0);
    }
    a2_native_voice_close();
    puts("Genuine resident init/prepare/play/manager continuations finish a complete named cue without ISO or raw data reads");
}
