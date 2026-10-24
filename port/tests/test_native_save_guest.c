#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "psx_rt.h"
#include "native_save_guest.h"
uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t R[32], HI, LO, psx_next;
uint32_t a2_ramwatch,psx_work;
int psx_bb_budget=1000000;
void psx_bb_fire(void) { assert(!"unexpected guest wait"); }
void psx_mmio_write(uint32_t p,uint32_t v,int n) {(void)p;(void)v;(void)n;assert(!"unexpected MMIO write");}
void a2_ramwatch_hit(uint32_t p,uint32_t v,int n) {(void)p;(void)v;(void)n;assert(!"unexpected RAM watch");}
/* Exercise the actual original Start branch which follows the deferred hook. */
#include "../gen/game00_003.c"
static uint8_t original[PSX_RAM_SIZE], payload[8192], chosen[8192];
static int dialog_result, dialog_calls, settings_calls, error_calls;
static int dialog_quick, dialog_saving, dialog_probe_reentry;
static uint32_t settings_args[3];
uint32_t psx_mmio_read(uint32_t address, int size) {
    (void)address; (void)size; assert(!"unexpected MMIO read"); return 0;
}
static const uint16_t maps[40] = {14,20,10,24,59,331,28,297,106,121,418,422,185,142,152,89,163,174,472,222,286,350,414,490,178,450,412,472,118,424,430,75,243,311,489,305,271,232,281,271};
static void put16(uint8_t *p, unsigned v) { p[0]=v; p[1]=v>>8; }
static unsigned get16(const uint8_t *p) { return p[0]|p[1]<<8; }
static void checksum(uint8_t *p) {
    unsigned sum=0; for(unsigned i=0;i<0xD8C;i+=2) sum+=get16(p+i);
    put16(p+0xD8C,sum);
}
static void reset(void) {
    memset(PSX_RAM,0xA5,sizeof PSX_RAM);
    for(unsigned i=0;i<40;i++) put16(PSX_RAM+0xEEF10+i*2,maps[i]);
    for(unsigned i=0;i<A2_CHECKPOINT_SIZE;i++) PSX_RAM[0x63388+i]=(uint8_t)(i*37);
    put16(PSX_RAM+0x63388,7); put16(PSX_RAM+0x6338A,0);
    put16(PSX_RAM+0x63E9C,14);
    put16(PSX_RAM+0x633A8,0); put16(PSX_RAM+0x633AA,10); put16(PSX_RAM+0x633AC,15);
    memcpy(original,PSX_RAM,sizeof original);
    dialog_result=0; dialog_calls=settings_calls=error_calls=0;
    dialog_quick=dialog_saving=-1; dialog_probe_reentry=0;
}
void psx_call(uint32_t address) {
    assert(address==0x8002DCC8u);
    settings_calls++; memcpy(settings_args,R+4,sizeof settings_args);
    memset(R,0xDA,sizeof R); HI=9; LO=10; psx_next=0x12345678;
}
int platform_native_save_dialog(int saving,uint8_t *p,char *e,size_t n) {
    dialog_calls++;
    dialog_quick=a2_native_quick_action_active(); dialog_saving=saving;
    if(dialog_probe_reentry) {
        /* Even if the guest command is cleared while the host dialog owns
         * control, an active manual operation must reject both request kinds. */
        uint8_t command=PSX_RAM[0xF621C]; PSX_RAM[0xF621C]=0;
        assert(!a2_native_quick_save_available() && !a2_native_quick_load_available());
        assert(!a2_native_request_quick_action(0) && !a2_native_request_quick_action(1));
        assert(!a2_native_request_save_action(0) && !a2_native_request_save_action(1));
        PSX_RAM[0xF621C]=command;
    }
    if(dialog_result==2)snprintf(e,n,"Save was published, but directory sync failed: test");
    if(dialog_result && !saving) memcpy(p,chosen,8192);
    if(saving) memcpy(chosen,p,8192);
    return dialog_result;
}
void platform_native_save_error(const char *e) { assert(e && *e); error_calls++; }
static void prepare_call(int saving) {
    for(unsigned i=0;i<32;i++) R[i]=0xBA000000+i;
    R[0]=0; R[4]=saving; R[31]=0x800862F8; HI=0xABC; LO=0xDEF;
    PSX_RAM[0x811D8]=4; PSX_RAM[0x811D9]=PSX_RAM[0x811DA]=PSX_RAM[0x811DB]=0;
    memcpy(original,PSX_RAM,sizeof original);
}
static void prepare_idle_call(int saving) {
    reset(); prepare_call(saving);
    memset(PSX_RAM+0xF621C,0,8); PSX_RAM[0x11752A]=0; PSX_RAM[0x64018]=0;
    put16(PSX_RAM+0x12789C,14); put16(PSX_RAM+0x5E6CC,0);
    const uint32_t menu_entry=0x3C02800Fu;
    memcpy(PSX_RAM+0x85474,&menu_entry,sizeof menu_entry);
    memcpy(original,PSX_RAM,sizeof original);
}
static void test_manual_and_quick_dialog_routing(void) {
    for(int quick=0;quick<2;quick++) for(int saving=0;saving<2;saving++) {
        char error[512]; prepare_idle_call(saving);
        assert(a2_checkpoint_prepare(PSX_RAM,chosen,error,sizeof error));
        put16(chosen+0x100,19); checksum(chosen);
        assert(quick ? a2_native_request_quick_action(saving) : a2_native_request_save_action(saving));
        assert(!a2_native_request_quick_action(0) && !a2_native_request_save_action(1));
        assert(!memcmp(original,PSX_RAM,sizeof original));
        assert(!a2_native_quick_action_active());
        assert(!a2_native_save_handle(0x80085470u));
        assert(!memcmp(original,PSX_RAM,sizeof original));
        assert(!a2_native_save_handle(0x80085474u));
        assert(PSX_RAM[0xF621C]==(saving?3:4));
        /* The guest snapshot precedes the save entry. Stage what it left,
         * rather than a copy taken when the host originally queued Save. */
        if(saving)put16(PSX_RAM+0x63388,42);
        dialog_result=1; dialog_probe_reentry=1;
        assert(a2_native_save_handle(0x800C8738u));
        assert(dialog_calls==1 && dialog_saving==saving);
        assert(dialog_quick==quick);
        assert(R[2]==1 && settings_calls==!saving);
        assert(get16(PSX_RAM+0x63388)==(saving?43:19));
        assert(!memcmp(PSX_RAM+0x626F8,chosen+0x100,A2_CHECKPOINT_SIZE));
        assert(!a2_native_quick_action_active());
        PSX_RAM[0xF621C]=0;
        assert(a2_native_quick_save_available() && a2_native_quick_load_available());
    }
}
static void test_manual_cancel_preserves_ram_and_releases_operation(void) {
    for(int saving=0;saving<2;saving++) {
        prepare_idle_call(saving);
        assert(a2_native_request_save_action(saving));
        assert(!a2_native_save_handle(0x80085474u));
        memcpy(original,PSX_RAM,sizeof original);
        uint32_t saved[32]; memcpy(saved,R,sizeof saved);
        dialog_probe_reentry=1;
        assert(a2_native_save_handle(0x800C8738u));
        assert(dialog_quick==0 && dialog_calls==1 && settings_calls==0 && error_calls==0);
        assert(!memcmp(original,PSX_RAM,sizeof original));
        saved[2]=0;
        assert(!memcmp(saved,R,sizeof saved) && HI==0xABC && LO==0xDEF && psx_next==saved[31]);
        PSX_RAM[0xF621C]=0;
        assert(a2_native_request_quick_action(saving));
        assert(!a2_native_save_handle(0x80085474u));
        assert(a2_native_save_handle(0x800C8738u));
        assert(dialog_quick==1 && dialog_calls==2 && R[2]==0);
        assert(!a2_native_quick_action_active());
        PSX_RAM[0xF621C]=0;
    }
}
static void test_manual_eligibility_and_pending_cancellation(void) {
    prepare_idle_call(1);
    assert(!a2_native_request_save_action(-1) && !a2_native_request_save_action(2));
    for(unsigned variant=0;variant<7;variant++) {
        prepare_idle_call(1);
        assert(a2_native_request_save_action(1));
        if(variant==0)PSX_RAM[0x811D8]=5;
        if(variant==1)PSX_RAM[0x11752A]=1;
        if(variant==2)PSX_RAM[0xF6220]=1;
        if(variant==3)put16(PSX_RAM+0x12789C,0);
        if(variant==4)setenv("A2_NATIVE_SAVES","0",1);
        if(variant==5)PSX_RAM[0x64018]=1;
        if(variant==6)PSX_RAM[0xF621C]=5;
        assert(!a2_native_save_handle(0x80090000u));
        assert(!a2_native_request_save_action(0) && !a2_native_request_save_action(1));
        setenv("A2_NATIVE_SAVES","1",1);
        prepare_idle_call(1);
        assert(!a2_native_save_handle(0x80085474u));
        assert(PSX_RAM[0xF621C]==0 && dialog_calls==0 && !a2_native_quick_action_active());
        assert(a2_native_quick_save_available() && a2_native_quick_load_available());
    }
    /* Keep both exact dispatcher signature and original Start precedence. */
    for(unsigned variant=0;variant<2;variant++) {
        prepare_idle_call(1);
        assert(a2_native_request_save_action(1));
        if(variant==0)PSX_RAM[0x85474]^=1;
        else {put16(PSX_RAM+0x5E6CC,0x800);put16(PSX_RAM+0x128C52,0);}
        memcpy(original,PSX_RAM,sizeof original);
        assert(!a2_native_save_handle(0x80085474u));
        assert(!memcmp(original,PSX_RAM,sizeof original) && dialog_calls==0);
        assert(a2_native_quick_load_available());
    }
}
static void test_manual_active_abandonment(void) {
    for(unsigned variant=0;variant<4;variant++) {
        prepare_idle_call(0);
        assert(a2_native_request_save_action(0));
        assert(!a2_native_save_handle(0x80085474u));
        assert(PSX_RAM[0xF621C]==4 && !a2_native_quick_action_active());
        /* Observe the operation guard independently of the guest menu byte. */
        PSX_RAM[0xF621C]=0;
        assert(!a2_native_request_save_action(0) && !a2_native_request_quick_action(1));
        PSX_RAM[0xF621C]=4;
        if(variant==0)PSX_RAM[0xF621C]=5;
        if(variant==1)PSX_RAM[0x811D8]=5;
        if(variant==3)setenv("A2_NATIVE_SAVES","0",1);
        assert(!a2_native_save_handle(variant==2?0x80085474u:0x80090000u));
        setenv("A2_NATIVE_SAVES","1",1);
        PSX_RAM[0x811D8]=4; PSX_RAM[0xF621C]=0;
        assert(a2_native_quick_load_available());
        assert(a2_native_request_quick_action(0));
        assert(!a2_native_save_handle(0x80085474u));
        assert(a2_native_save_handle(0x800C8738u));
        assert(dialog_quick==1 && dialog_calls==1);
        PSX_RAM[0xF621C]=0;
    }
}
int main(void) {
    char error[512]={0}; reset();
    assert(a2_checkpoint_prepare(PSX_RAM,payload,error,sizeof error));
    assert(!memcmp(PSX_RAM,original,sizeof original));
    assert(!memcmp(payload,"SC\x11\x01",4));
    assert(get16(payload+0x100)==8 && get16(payload+0x102)==0);
    assert(!memcmp(payload+0x104,PSX_RAM+0x6338C,A2_CHECKPOINT_SIZE-4));
    assert(a2_checkpoint_apply(PSX_RAM,payload,error,sizeof error));
    assert(!memcmp(PSX_RAM+0x63388,payload+0x100,A2_CHECKPOINT_SIZE));
    assert(!memcmp(PSX_RAM+0x626F8,payload+0x100,A2_CHECKPOINT_SIZE));
    memcpy(original+0x63388,payload+0x100,A2_CHECKPOINT_SIZE);
    memcpy(original+0x626F8,payload+0x100,A2_CHECKPOINT_SIZE);
    assert(!memcmp(original,PSX_RAM,sizeof original));
    for(unsigned field=0x122;field<=0x124;field+=2) {
        uint8_t invalid[8192]; memcpy(invalid,payload,sizeof invalid);
        put16(invalid+field,16); checksum(invalid);
        assert(!a2_checkpoint_apply(PSX_RAM,invalid,error,sizeof error));
        assert(!memcmp(original,PSX_RAM,sizeof original));
    }
    payload[0x500]^=1;
    assert(!a2_checkpoint_apply(PSX_RAM,payload,error,sizeof error));
    assert(!memcmp(original,PSX_RAM,sizeof original));
    payload[0x500]^=1; put16(payload+0x102,1); checksum(payload);
    assert(!a2_checkpoint_apply(PSX_RAM,payload,error,sizeof error));
    assert(!memcmp(original,PSX_RAM,sizeof original));
    reset(); put16(PSX_RAM+0x63E9C,21); /* ordinary map without a save point */
    assert(a2_checkpoint_prepare(PSX_RAM,payload,error,sizeof error));
    assert(get16(payload+0x102)==0xffff && get16(payload+0xc14)==21);
    assert(a2_checkpoint_apply(PSX_RAM,payload,error,sizeof error));
    reset(); put16(PSX_RAM+0x63E9C,0);
    assert(!a2_checkpoint_prepare(PSX_RAM,payload,error,sizeof error));
    reset(); put16(PSX_RAM+0x63388,999);
    assert(a2_checkpoint_prepare(PSX_RAM,payload,error,sizeof error));
    assert(get16(payload+0x100)==999);
    reset(); put16(PSX_RAM+0x63E9C,472);
    assert(a2_checkpoint_prepare(PSX_RAM,payload,error,sizeof error));
    assert(get16(payload+0x102)==18); /* first original whitelist match */
    setenv("A2_NATIVE_SAVES","1",1);
    reset(); prepare_call(1); uint32_t saved[32]; memcpy(saved,R,sizeof saved);
    assert(!a2_native_save_handle(0x800C873Cu));
    assert(a2_native_save_handle(0x800C8738u)); /* cancel */
    saved[2]=0; assert(!memcmp(R,saved,sizeof R));
    assert(HI==0xABC && LO==0xDEF && psx_next==saved[31]);
    assert(!memcmp(original,PSX_RAM,sizeof original));
    assert(dialog_calls==1 && settings_calls==0);
    reset(); prepare_call(1); dialog_result=1;
    assert(a2_native_save_handle(0x800C8738u));
    assert(R[2]==1 && get16(PSX_RAM+0x63388)==8);
    assert(!memcmp(PSX_RAM+0x626F8,chosen+0x100,A2_CHECKPOINT_SIZE));
    reset(); prepare_call(1); dialog_result=2;
    assert(a2_native_save_handle(0x800C8738u));
    assert(R[2]==1 && get16(PSX_RAM+0x63388)==8 && error_calls==1);
    reset(); prepare_call(0); memcpy(saved,R,sizeof saved); dialog_result=1;
    assert(a2_native_save_handle(0x800C8738u));
    saved[2]=1; assert(!memcmp(R,saved,sizeof R));
    assert(HI==0xABC && LO==0xDEF && psx_next==saved[31]);
    assert(settings_calls==1 && settings_args[0]==10 && settings_args[1]==15 && settings_args[2]==0);
    assert(!memcmp(PSX_RAM+0x63388,chosen+0x100,A2_CHECKPOINT_SIZE));
    /* Caller-owned scene/continuation flags must not be fabricated. */
    assert(!memcmp(PSX_RAM+0x63384,original+0x63384,4));
    assert(!memcmp(PSX_RAM+0x5D058,original+0x5D058,4));
    reset(); prepare_call(0); dialog_result=1; chosen[0x600]^=1;
    assert(a2_native_save_handle(0x800C8738u));
    assert(R[2]==0 && error_calls==1 && settings_calls==0);
    assert(!memcmp(PSX_RAM,original,sizeof original));
    /* Host requests cannot mutate RAM until the original menu dispatch entry.
     * A request becoming unsafe before that boundary must be cancelled. */
    reset(); prepare_call(1);
    memset(PSX_RAM+0xF621C,0,8); PSX_RAM[0x11752A]=0; PSX_RAM[0x64018]=0;
    put16(PSX_RAM+0x12789C,14);
    PSX_RAM[0x85474]=0x0F; PSX_RAM[0x85475]=0x80;
    PSX_RAM[0x85476]=0x02; PSX_RAM[0x85477]=0x3C;
    /* The title also runs overlay4 with clear flags, but has no loaded map.
     * Reject there; a title key must not queue a load for the later game. */
    put16(PSX_RAM+0x12789C,0);
    memcpy(original,PSX_RAM,sizeof original);
    assert(!a2_native_quick_save_available() && !a2_native_quick_load_available());
    assert(!a2_native_request_quick_action(0));
    assert(!memcmp(original,PSX_RAM,sizeof original));
    put16(PSX_RAM+0x12789C,14);
    assert(!a2_native_save_handle(0x80085474u));
    assert(PSX_RAM[0xF621C]==0 && !a2_native_quick_action_active());
    memcpy(original,PSX_RAM,sizeof original);
    assert(a2_native_quick_save_available() && a2_native_quick_load_available());
    assert(a2_native_request_quick_action(1));
    assert(!a2_native_request_quick_action(1));
    assert(!memcmp(original,PSX_RAM,sizeof original));
    assert(!a2_native_save_handle(0x80085470u));
    assert(PSX_RAM[0xF621C]==0 && !a2_native_quick_action_active());
    assert(!a2_native_save_handle(0x80085474u));
    assert(PSX_RAM[0xF621C]==3 && a2_native_quick_action_active());
    assert(!a2_native_quick_save_available());
    dialog_result=0; assert(a2_native_save_handle(0x800C8738u));
    assert(!a2_native_quick_action_active());
    PSX_RAM[0xF621C]=0; assert(a2_native_request_quick_action(0));
    PSX_RAM[0x11752A]=1; /* dialogue began after opening host menu */
    assert(!a2_native_save_handle(0x80085474u));
    assert(PSX_RAM[0xF621C]==0 && !a2_native_quick_action_active());
    PSX_RAM[0x11752A]=0; put16(PSX_RAM+0x12789C,2);
    assert(a2_native_quick_save_available() && a2_native_quick_load_available());
    assert(a2_native_request_quick_action(1));
    assert(!a2_native_save_handle(0x80085474u));
    assert(PSX_RAM[0xF621C]==3 && a2_native_quick_action_active());
    R[4]=1; dialog_result=0; assert(a2_native_save_handle(0x800C8738u));
    PSX_RAM[0xF621C]=0;
    assert(a2_native_request_quick_action(0));
    assert(!a2_native_save_handle(0x80085474u));
    assert(PSX_RAM[0xF621C]==4 && a2_native_quick_action_active());
    R[4]=0; dialog_result=0; assert(a2_native_save_handle(0x800C8738u));

    /* A Start edge arriving after the host request takes its ordinary guest
     * path. It must not overwrite an active quick command and orphan it. */
    PSX_RAM[0xF621C]=0;
    assert(a2_native_request_quick_action(0));
    put16(PSX_RAM+0x5E6CC,0x800);put16(PSX_RAM+0x128C52,0);
    R[29]=0x801FFF00; memcpy(saved,R,sizeof saved);
    uint32_t old_next=psx_next;
    assert(!a2_native_save_handle(0x80085474u));
    assert(!a2_native_quick_action_active() && PSX_RAM[0xF621C]==0);
    assert(!memcmp(saved,R,sizeof saved) && HI==0xABC && LO==0xDEF && psx_next==old_next);
    g0_80085474();g0_8008547C();
    assert(PSX_RAM[0xF621C]==5 && !a2_native_quick_action_active());
    assert(psx_next==0x8001D6D8u); /* The original menu fade continuation. */

    /* Cancel when the guest changes before reaching the expected boundary,
     * even if that boundary is not encountered until a later idle scene. */
    memset(PSX_RAM+0xF621C,0,8);put16(PSX_RAM+0x5E6CC,0);
    assert(a2_native_request_quick_action(0));
    PSX_RAM[0x811D8]=5;
    assert(!a2_native_save_handle(0x80090000u));
    PSX_RAM[0x811D8]=4;
    assert(!a2_native_save_handle(0x80085474u));
    assert(!a2_native_quick_action_active() && PSX_RAM[0xF621C]==0);

    /* Unexpected command replacement and re-entry cannot leave quick mode
     * attached to a later ordinary save/load browser operation. */
    for(unsigned variant=0;variant<3;variant++) {
        assert(a2_native_request_quick_action(0));
        assert(!a2_native_save_handle(0x80085474u));
        assert(a2_native_quick_action_active());
        if(variant==0)PSX_RAM[0xF621C]=5;
        if(variant==1)PSX_RAM[0x811D8]=5;
        assert(!a2_native_save_handle(variant==2?0x80085474u:0x80090000u));
        assert(!a2_native_quick_action_active());
        PSX_RAM[0x811D8]=4;PSX_RAM[0xF621C]=0;
        assert(a2_native_quick_load_available());
    }
    test_manual_and_quick_dialog_routing();
    test_manual_cancel_preserves_ram_and_releases_operation();
    test_manual_eligibility_and_pending_cancellation();
    test_manual_active_abandonment();
    /* Startup selection never touches RAM and is consumed exactly once.
     * Mismatching title code / caller cannot redirect the guest. */
    reset();put16(PSX_RAM+0x63E9C,213);
    assert(a2_checkpoint_prepare(PSX_RAM,payload,error,sizeof error));
    prepare_call(0);R[29]=0x801fff00;
    payload[0x800]^=1;
    assert(!a2_native_stage_startup_load(payload,error,sizeof error));
    assert(!a2_native_startup_load_pending() && !a2_native_startup_load_active());
    payload[0x800]^=1;
    memcpy(original,PSX_RAM,sizeof original);
    assert(a2_native_stage_startup_load(payload,error,sizeof error));
    assert(a2_native_startup_load_active());
    assert(!a2_native_request_save_action(0) && !a2_native_request_save_action(1));
    assert(!memcmp(original,PSX_RAM,sizeof original));
    /* Staging must bypass the optional complete presentations, never run a
     * title confirm/fade while waiting to consume the chosen checkpoint. */
    const uint32_t logos[]={0x27bdffd8,0x00002021,0xafbf0024,0xafb20020};
    const uint32_t opening[]={0x3c028006,0x8c42e6b8,0,0x10400011};
    const uint32_t title[]={0x3c028006,0x8c43e6b8,0x3c028006,0x14600004};
    memcpy(PSX_RAM+0x1a540,logos,sizeof logos);
    memcpy(PSX_RAM+0x1ab14,opening,sizeof opening);
    memcpy(PSX_RAM+0x146578,title,sizeof title);
    R[31]=0x8001aa64;memcpy(saved,R,sizeof saved);
    assert(a2_native_save_handle(0x8001a540u));
    assert(psx_next==0x8001aa64u && !memcmp(saved,R,sizeof saved));
    assert(a2_native_save_handle(0x8001ab14u));
    assert(psx_next==0x8001ab68u && R[2]==0);
    assert(!a2_native_save_handle(0x80146578u)); /* wrong caller */
    sw_(R[29]+0x5c,0x80085ac4);
    R[19]=2250;
    assert(a2_native_save_handle(0x80146578u));
    assert(psx_next==0x80146938u && R[18]==1 && R[19]==2250);
    assert(lh_(0x80063384u)==0);
    assert(!a2_native_save_handle(0x80146824u)); /* no selection-loop detour */
    R[4]=0;R[31]=0x80146978;
    assert(a2_native_save_handle(0x800C8738u));
    assert(R[2]==1 && dialog_calls==0 && settings_calls==1);
    assert(!a2_native_startup_load_pending());
    /* Copying the payload precedes the scene loader: do not expose a stale
     * frame or release host input until the genuine saved scene is ready. */
    assert(a2_native_startup_load_active());
    assert(!memcmp(PSX_RAM+0x626f8,payload+0x100,A2_CHECKPOINT_SIZE));
    assert(a2_native_save_handle(0x80146984u));
    assert(psx_next==0x801469ccu && R[16]==0x80063388u);
    assert(!a2_native_save_handle(0x80146984u)); /* one-shot */
    assert(!a2_native_save_handle(0x80146824u));
    memset(PSX_RAM+0xF621C,0,8);PSX_RAM[0x11752A]=0;PSX_RAM[0x64018]=0;
    put16(PSX_RAM+0x12789C,14);
    assert(!a2_native_quick_load_available());
    assert(!a2_native_save_handle(0x80085474u)); /* not the saved scene */
    assert(a2_native_startup_load_active());
    put16(PSX_RAM+0x12789C,213);PSX_RAM[0x11752A]=1;
    assert(!a2_native_save_handle(0x80085474u)); /* scene still blocked */
    assert(a2_native_startup_load_active());
    PSX_RAM[0x11752A]=0;
    assert(!a2_native_save_handle(0x80085474u));
    assert(!a2_native_startup_load_active());
    assert(a2_native_quick_load_available());
    assert(!a2_native_save_handle(0x8001a540u)); /* later boot routes untouched */
    assert(!a2_native_save_handle(0x8001ab14u));
    assert(!a2_native_save_handle(0x80146578u));
    setenv("A2_NATIVE_SAVES","0",1);
    assert(!a2_native_quick_save_available() && !a2_native_quick_load_available());
    assert(!a2_native_save_handle(0x800C8738u));
    puts("native checkpoint staging, validation, manual/quick routing and entry/return contracts passed");
}
