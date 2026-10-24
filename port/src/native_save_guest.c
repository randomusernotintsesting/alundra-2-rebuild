#include "native_save_guest.h"
#include "save_location.h"
#include "psx_rt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef A2_WORLD_PRECISION
#include "world_precision.h"
#endif

static unsigned read16(const uint8_t *p) { return p[0] | (unsigned)p[1] << 8; }
static void write16(uint8_t *p, unsigned v) { p[0]=(uint8_t)v; p[1]=(uint8_t)(v>>8); }
static unsigned payload_sum(const uint8_t *p) {
    unsigned sum=0;
    for(unsigned i=0;i<0xD8C;i+=2) sum+=read16(p+i);
    return sum & 0xFFFF;
}
static int fail(char *error,size_t size,const char *message) {
    if(error && size) snprintf(error,size,"%s",message);
    return 0;
}
int a2_checkpoint_prepare(const uint8_t *ram, uint8_t *payload, char *error, size_t size) {
    if(read16(ram+0x633AA)>=16 || read16(ram+0x633AC)>=16)
        return fail(error,size,"Не удалось сохранить настройки звука. Проверьте их в игровом меню и повторите попытку.");
    unsigned scene=read16(ram+0x63E9C), index=a2_save_location_index(scene);
    if(!a2_save_location_valid(index,scene))
        return fail(error,size,"Сейчас это действие недоступно. Вернитесь к обычной игре и повторите попытку.");
    /* Card artwork is presentation-only. The native format uses a deterministic
     * compatible header; do not read uninitialized original menu scratch art. */
    memset(payload,0,A2_CHECKPOINT_PAYLOAD_SIZE);
    memcpy(payload,"SC\x11\x01",4);
    memcpy(payload+4,"Alundra 2",9);
    memcpy(payload+0x100,ram+0x63388,A2_CHECKPOINT_SIZE);
    unsigned count=read16(payload+0x100);
    if(count<999) count++;
    write16(payload+0x100,count); write16(payload+0x102,index);
    write16(payload+0xD8C,payload_sum(payload));
    if(error && size) error[0]=0;
    return 1;
}
static int checkpoint_validate(const uint8_t *payload, char *error, size_t size) {
    if(memcmp(payload,"SC\x11\x01",4) || payload_sum(payload)!=read16(payload+0xD8C))
        return fail(error,size,"Файл сохранения повреждён. Выберите другое сохранение.");
    unsigned index=read16(payload+0x102), scene=read16(payload+0xC14);
    if(!a2_save_location_valid(index,scene))
        return fail(error,size,"Это сохранение не подходит к текущей версии игры. Выберите другое.");
    /* Original 8002DCC8 indexes two 16-entry volume tables directly. Validate
     * before copying either block or invoking that complete guest helper. */
    if(read16(payload+0x122)>=16 || read16(payload+0x124)>=16)
        return fail(error,size,"В сохранении повреждены настройки звука. Выберите другое сохранение.");
    return 1;
}
int a2_checkpoint_apply(uint8_t *ram, const uint8_t *payload, char *error, size_t size) {
    if(!checkpoint_validate(payload,error,size))return 0;
    memcpy(ram+0x63388,payload+0x100,A2_CHECKPOINT_SIZE);
    memcpy(ram+0x626F8,payload+0x100,A2_CHECKPOINT_SIZE);
    if(error && size) error[0]=0;
    return 1;
}
int a2_native_save_enabled(void) {
    const char *value=getenv("A2_NATIVE_SAVES");
    /* Opt-in until native-window and semantic replay acceptance is complete. */
    return value && !strcmp(value,"1");
}
static int action_pending, action_active, action_quick;
static int startup_pending, startup_active;
static int title_resume;
static uint8_t startup_payload[A2_CHECKPOINT_PAYLOAD_SIZE];
int a2_native_stage_startup_load(const uint8_t *payload,char *error,size_t size) {
    if(!a2_native_save_enabled() || !checkpoint_validate(payload,error,size))return 0;
    memcpy(startup_payload,payload,sizeof startup_payload);
    startup_pending=1;startup_active=1;
    return 1;
}
int a2_native_startup_load_pending(void) {return startup_pending!=0;}
int a2_native_startup_load_active(void) {return startup_active!=0;}
static int quick_idle(void) {
    /* GAME00 is also the title frontend, with clear flags and map ID zero.
     * It has no ordinary per-frame save/load dispatcher to consume a request. */
    return a2_native_save_enabled() && lw_(0x800811D8u)==4 &&
        lh_(0x8012789Cu)!=0 &&
        lw_(0x800F6220u)==0 && lb_(0x800F621Cu)==0 &&
        lb_(0x8011752Au)==0 && lb_(0x80064018u)==0;
}
static int original_start_pending(void) {
    /* GAME00 80085494..800854D8 can replace the menu request with inventory.
     * quick_idle has already established its other two conditions. */
    return (lh_(0x8005E6CCu)&0x800) && (int16_t)lh_(0x80128C52u)<100;
}
int a2_native_quick_load_available(void) {
    return !startup_active && !action_pending && !action_active && quick_idle();
}
int a2_native_quick_save_available(void) {
    return a2_native_quick_load_available();
}
static int request_action(int saving,int quick) {
    if(saving!=0 && saving!=1) return 0;
    if(!(saving ? a2_native_quick_save_available() : a2_native_quick_load_available())) return 0;
    action_pending=saving?1:2;
    action_quick=quick;
    return 1;
}
int a2_native_request_quick_action(int saving) { return request_action(saving,1); }
int a2_native_request_save_action(int saving) { return request_action(saving,0); }
int a2_native_quick_action_active(void) { return action_active!=0 && action_quick; }

int a2_native_save_handle(uint32_t address) {
    /* Payload application is earlier than scene construction. Keep the host
     * loading presentation/input gate until the saved scene reaches the real
     * ordinary gameplay dispatcher with its usual idle flags. */
    if(startup_active && !startup_pending && !title_resume &&
       address==0x80085474u && quick_idle() &&
       lh_(0x8012789Cu)==read16(startup_payload+0xC14)) {
        startup_active=0;
        fprintf(stderr,"native-save: startup ready scene=%u\n",(unsigned)lh_(0x8012789Cu));
    }
    if(startup_pending==1 && a2_native_save_enabled()) {
        /* This optional complete presenter is called only after global boot
         * initialization. The original caller already omits it on its own
         * no-opening branch; a staged save needs none of its logo/movie work. */
        if(address==0x8001A540u && R[31]==0x8001AA64u &&
           lw_(address)==0x27BDFFD8u && lw_(address+4)==0x00002021u &&
           lw_(address+8)==0xAFBF0024u && lw_(address+12)==0xAFB20020u) {
            psx_next=R[31];
            fprintf(stderr,"native-save: startup bypass presentations\n");
            return 1;
        }
        /* Follow SCPS's existing no-opening branch. Leave the common audio,
         * persistent-data and overlay setup at 8001AB68..8001ABA0 intact. */
        if(address==0x8001AB14u && lw_(address)==0x3C028006u &&
           lw_(address+4)==0x8C42E6B8u && lw_(address+8)==0 &&
           lw_(address+12)==0x10400011u) {
            R[2]=0;psx_next=0x8001AB68u;
            fprintf(stderr,"native-save: startup bypass opening scene\n");
            return 1;
        }
        /* TITLE00 has completed shared graphics/allocator initialization,
         * but has not submitted title artwork, loaded its music or started
         * its selection/fade loop. Enter its ordinary Continue load branch.
         * Retain the caller-owned stack and original post-load continuation. */
        if(address==0x80146578u && lw_(0x800811D8u)==4 &&
           lw_(R[29]+0x5c)==0x80085AC4u &&
           lw_(address)==0x3C028006u && lw_(address+4)==0x8C43E6B8u &&
           lw_(address+8)==0x3C028006u && lw_(address+12)==0x14600004u) {
            sh_(0x80063384u,0); /* Original pre-title loaded-game flag. */
            startup_pending=2;R[18]=1;psx_next=0x80146938u;
            fprintf(stderr,"native-save: startup direct load\n");
            return 1;
        }
    }
    if(title_resume && address==0x80146984u && lw_(0x800811D8u)==4) {
        title_resume=0;
        /* The original title treats map 213 as a New Game marker and erases
         * that checkpoint. Native free-position saves may legitimately be on
         * this tutorial map. Use the successful ordinary load continuation. */
        R[2]=0x80060000u;R[16]=0x80063388u;psx_next=0x801469CCu;
        return 1;
    }
    /* An operation belongs only to the continuously idle state in which it
     * was requested. Do not carry it through an intervening scene/dialogue.
     * Once dispatched, a changed menu command, overlay or next ordinary menu
     * boundary means the original guest abandoned that operation. */
    if(action_pending && !quick_idle())action_pending=0;
    if(action_active && (!a2_native_save_enabled() || lw_(0x800811D8u)!=4 ||
       lb_(0x800F621Cu)!=(action_active==1?3:4) || address==0x80085474u))action_active=0;
    if(action_pending && address==0x80085474u) {
        int action=action_pending; action_pending=0;
        /* Exact entry of the original per-frame menu dispatcher. It performs
         * the snapshot, then its complete ordinary save/load continuation.
         * Recheck after host UI: never inject into dialogue or a scene change. */
        if(quick_idle() && !original_start_pending() &&
           lw_(address)==0x3C02800Fu) {
            PSX_RAM[0xF621C]=(uint8_t)(action==1?3:4);
#ifdef A2_WORLD_PRECISION
            world_precision_invalidate(0x800F621Cu,1);
#endif
            action_active=action;
        }
        return 0;
    }
    if(address!=0x800C8738u || lw_(0x800811D8u)!=4 || !a2_native_save_enabled()) return 0;
    uint32_t saved[32], saved_hi=HI, saved_lo=LO;
    memcpy(saved,R,sizeof saved);
    uint8_t payload[A2_CHECKPOINT_PAYLOAD_SIZE];
    char error[512]={0};
    int saving=R[4]==1, ok=0;
    if(R[4]>1) fail(error,sizeof error,"Неизвестный режим сохранения. Игра не была изменена.");
    else if(!saving || a2_checkpoint_prepare(PSX_RAM,payload,error,sizeof error)) {
        int selected=0;
        if(!saving && startup_pending==2 && R[31]==0x80146978u) {
            memcpy(payload,startup_payload,sizeof payload);startup_pending=0;selected=1;
        } else selected=platform_native_save_dialog(saving,payload,error,sizeof error);
        if(selected) {
            char warning[sizeof error];
            memcpy(warning,error,sizeof warning);
            ok=a2_checkpoint_apply(PSX_RAM,payload,error,sizeof error);
            if(ok) {
                /* Successful publication can carry a durability warning.
                 * Applying the checkpoint must not erase that host message. */
                memcpy(error,warning,sizeof error);
#ifdef A2_WORLD_PRECISION
                world_precision_invalidate(0x80063388u,A2_CHECKPOINT_SIZE);
                world_precision_invalidate(0x800626F8u,A2_CHECKPOINT_SIZE);
#endif
                /* Native indices never enter the old two-card preference. */
                if(!saving) {
                    R[4]=(uint32_t)(int16_t)lh_(0x800633AAu);
                    R[5]=(uint32_t)(int16_t)lh_(0x800633ACu);
                    R[6]=(uint32_t)(int16_t)lh_(0x800633A8u);
                    psx_call(0x8002DCC8u);
                    if(saved[31]==0x80146978u)title_resume=1;
                }
            }
        }
    }
    if(error[0]) platform_native_save_error(error);
    action_active=0;
    memcpy(R,saved,sizeof saved); HI=saved_hi; LO=saved_lo;
    R[2]=(uint32_t)ok; psx_next=R[31];
    fprintf(stderr,"native-save: %s result=%d scene=%u\n",saving?"save":"load",ok,
            (unsigned)lh_(0x80063E9Cu));
    return 1;
}
