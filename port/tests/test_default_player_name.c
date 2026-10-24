/* Exercise the real default-name initializer and all three {NAME} consumers.
 * clang -std=c11 -O1 -g -UNDEBUG -Iport/src -Iport/gen
 *   port/tests/test_default_player_name.c port/gen/scps_005.c
 *   port/gen/scps_007.c port/src/game_locale.c -o /tmp/a2-default-player-name
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "scps_decls.h"
#include "game_locale.h"

uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t R[32], HI, LO, psx_next, psx_work, a2_ramwatch;
int psx_bb_budget = 1000000;
void psx_break(uint32_t n) {(void)n; abort();}
void psx_bb_fire(void) {abort();}
void psx_trap(uint32_t n) {(void)n; abort();}
void a2_ramwatch_hit(uint32_t p,uint32_t v,int s) {(void)p;(void)v;(void)s;abort();}
uint32_t psx_mmio_read(uint32_t p,int s) {(void)p;(void)s;abort();}
void psx_mmio_write(uint32_t p,uint32_t v,int s) {(void)p;(void)v;(void)s;abort();}
void a2_plan_rect(const char *t,uint32_t r,uint32_t s,uint32_t e) {(void)t;(void)r;(void)s;(void)e;abort();}

static int expansion_path;

static void check_expansion(const uint16_t *name,unsigned count) {
    if(expansion_path==1) {
        /* Animated dialogue, reached by NAME in the original 0x80021DFC
         * message control dispatch. Stop at its first real glyph draw call. */
        R[18]=0x80065600; R[17]=R[18]+14; R[30]=0x8005e6c8;
        R[16]=0x80110000; R[29]=0x801ff000;
        sh_(R[18]+2,2); sh_(R[18]+12,0);
        f_80021F60();
        for(unsigned i=0;i<count;i++) assert(lh_(0x80065a10+i*2)==name[i]);
        assert(lh_(0x80065a10+count*2)==9);
        assert(lw_(R[18]+28)==0x80110000);
        assert(psx_next==0x80021dfc);
        f_80021DFC();
        assert(R[16]==0x80065a10 && R[4]==name[0] && psx_next==0x80020510);
        return;
    }
    if(expansion_path==2) {
        /* Centered text computes width through a separate NAME expander.
         * Stop at the first real glyph-width call. */
        R[23]=R[21]=0x80060000; R[20]=R[19]=0;
        R[16]=0x80110000; R[29]=0x801ff000;
        f_800214E8();
        for(unsigned i=0;i<count;i++) assert(lh_(0x80065a10+i*2)==name[i]);
        assert(lh_(0x80065a10+count*2)==9);
        assert(psx_next==0x80021490);
        f_80021490();
        assert(R[17]==0x80110000 && R[16]==0x80065a12);
        assert(R[4]==name[0] && psx_next==0x8001f9f4);
        return;
    }
    R[18]=0x80100000; R[22]=0x80060000; R[16]=0x80110000;
    R[17]=0xff55; R[19]=0; R[29]=0x801ff000;
    f_8002086C();
    for(unsigned i=0;i<count;i++) assert(lh_(0x80065a10+i*2)==name[i]);
    assert(lh_(0x80065a10+count*2)==9); /* return-to-message control */
    assert(lw_(0x80100000+28)==0x80110000);
    assert(R[16]==0x80065a10 && psx_next==0x8002078c);
}

static void check_default(int language,int voice,const uint16_t *name,unsigned count) {
    a2_game_text_language=language;a2_game_voice_language=voice;
    memset(PSX_RAM,0xa5,sizeof PSX_RAM);
    for(unsigned i=0;i<32;i++) R[i]=0x12340000+i;
    R[0]=0; R[31]=0xffaaffaa; HI=0xabcdef01; LO=0x12345678;
    uint32_t before[32]; memcpy(before,R,sizeof before);
    f_8001CFD4();
    for(unsigned i=0;i<count;i++) assert(lh_(0x80063ea4+i*2)==name[i]);
    assert(lh_(0x80063ea4+count*2)==0);
    for(unsigned i=0;i<PSX_RAM_SIZE;i++)
        if(i<0x63ea4 || i>=0x63ea4+(count+1)*2) assert(PSX_RAM[i]==0xa5);
    /* The original routine clobbers only v0/v1 with these exact values. */
    for(unsigned i=0;i<32;i++)
        assert(R[i]==(i==2?0x80063388u:i==3?157u:before[i]));
    assert(HI==0xabcdef01 && LO==0x12345678 && psx_next==before[31]);
    check_expansion(name,count);
}

static void check_matrix(void) {
    /* Independently encoded expected names: both voice spellings plus the
     * original Japanese text profile, which remains Japanese for either voice. */
    const uint16_t russian_us[]={0xff55,0xff6c,0xff69,0xff6e,0xff73};
    const uint16_t russian_jp[]={0xff55,0xff6c,0xff69,0xff73};
    const uint16_t japanese[]={165,177,214,157};
    const uint16_t english_us[]={0xff46,0xff6c,0xff69,0xff6e,0xff74};
    const uint16_t english_jp[]={0xff46,0xff6c,0xff69,0xff74};
    const uint16_t *shown[3][2]={{russian_jp,russian_us},{japanese,japanese},{english_jp,english_us}};
    const unsigned lengths[3][2]={{4,5},{4,4},{4,5}};
    /* Screenshot regression: RU text + US voice + a checkpoint whose default
     * is still フリット must draw Флинт through every text consumer. */
    memset(PSX_RAM,0,sizeof PSX_RAM); memset(R,0,sizeof R);
    for(unsigned i=0;i<4;i++)sh_(0x80063ea4+i*2,japanese[i]);
    a2_game_text_language=0; a2_game_voice_language=1;
    check_expansion(russian_us,5);
    for(int language=0;language<3;language++)for(int voice=0;voice<2;voice++)
        check_default(language,voice,shown[language][voice],lengths[language][voice]);
    /* Old and newly shipped defaults follow actual voice on expansion, but
     * neither the saved name nor any other persistent checkpoint byte changes. */
    const uint16_t *defaults[]={russian_us,japanese,english_us,russian_jp,english_jp};
    const unsigned stored_lengths[]={5,4,5,4,4};
    for(unsigned stored=0;stored<5;stored++)for(int language=0;language<3;language++)for(int voice=0;voice<2;voice++) {
        for(unsigned i=0;i<stored_lengths[stored];i++)sh_(0x80063ea4+i*2,defaults[stored][i]);
        sh_(0x80063ea4+stored_lengths[stored]*2,0);
        uint8_t saved_checkpoint[0xc8c];memcpy(saved_checkpoint,PSX_RAM+0x63388,sizeof saved_checkpoint);
        a2_game_text_language=language;a2_game_voice_language=voice;
        check_expansion(shown[language][voice],lengths[language][voice]);
        assert(!memcmp(saved_checkpoint,PSX_RAM+0x63388,sizeof saved_checkpoint));
    }
    /* Ordinary custom names and prefix/suffix/case near-matches remain exact. */
    const uint16_t custom[][7]={
        {0xff4c,0xff65,0xff72,0xff61,0},       /* Lera */
        {0xff46,0xff6c,0xff69,0xff6e,0xff74,0xff79,0}, /* Flinty */
        {0xff46,0xff6c,0xff69,0},             /* Fli */
        {0xff66,0xff6c,0xff69,0xff6e,0xff74,0}, /* flint */
        {0xff55,0xff6c,0xff69,0xff73,0xff21,0} /* Флит! */
    };
    const unsigned custom_lengths[]={4,6,3,5,5};
    for(unsigned c=0;c<5;c++)for(int language=0;language<3;language++)for(int voice=0;voice<2;voice++) {
        for(unsigned i=0;i<=custom_lengths[c];i++)sh_(0x80063ea4+i*2,custom[c][i]);
        uint8_t saved_checkpoint[0xc8c];memcpy(saved_checkpoint,PSX_RAM+0x63388,sizeof saved_checkpoint);
        a2_game_text_language=language;a2_game_voice_language=voice;
        check_expansion(custom[c],custom_lengths[c]);
        assert(!memcmp(saved_checkpoint,PSX_RAM+0x63388,sizeof saved_checkpoint));
    }
    printf("PASS path %d: six text/voice defaults, all five saved defaults, exact custom names and unchanged checkpoints\n", expansion_path);
}

int main(int argc,char **argv) {
    if(argc>1) {
        expansion_path=atoi(argv[1]);
        assert(expansion_path>=0 && expansion_path<=2);
        check_matrix();
    } else {
        for(expansion_path=0;expansion_path<3;expansion_path++)check_matrix();
    }
    return 0;
}
