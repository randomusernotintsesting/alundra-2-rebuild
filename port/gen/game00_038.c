#include "game00_decls.h"

void g0_800CCB64(void) {
    R[3] = 0x8013u << 16;  /* 0x800CCB64 */
    R[2] = R[0] + 50;  /* 0x800CCB68 */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCB6C j */
    R[4] = lh_(R[2] + 4);  /* 0x800CCB74 */
    R[2] = R[4] & 0x1000;  /* 0x800CCB7C */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8014u << 16; if (_c) { goto L_800CCBA4; } }  /* 0x800CCB80 */
    R[2] = lw_(R[3] + 14944);  /* 0x800CCB88 */
    R[2] = R[2] - 1;  /* 0x800CCB90 */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[3] + 14944, R[2]); if (_c) { goto L_800CCC7C; } }  /* 0x800CCB94 */
    { sw_(R[3] + 14944, R[0]); goto L_800CCF2C; }  /* 0x800CCB9C j */
L_800CCBA4:;
    R[2] = R[4] & 0x4000;  /* 0x800CCBA4 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[4] & 0x8000; if (_c) { goto L_800CCC00; } }  /* 0x800CCBA8 */
    R[2] = lw_(R[3] + 14944);  /* 0x800CCBB0 */
    R[2] = R[2] + 1;  /* 0x800CCBB8 */
    sw_(R[3] + 14944, R[2]);  /* 0x800CCBBC */
    R[2] = ((int32_t)R[2] < 4);  /* 0x800CCBC0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 3; if (_c) { goto L_800CCBD4; } }  /* 0x800CCBC4 */
    { sw_(R[3] + 14944, R[2]); goto L_800CCBDC; }  /* 0x800CCBCC j */
L_800CCBD4:;
    { R[31] = 0x800CCBDCu; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x800CCBD4 jal */
L_800CCBDC:;
    R[2] = 0x8014u << 16;  /* 0x800CCBDC */
    R[3] = lw_(R[2] + 14944);  /* 0x800CCBE0 */
    R[2] = R[0] + 3;  /* 0x800CCBE4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCBE8 */
    R[3] = 0x8014u << 16;  /* 0x800CCBF0 */
    R[2] = R[0] + 1;  /* 0x800CCBF4 */
    { sw_(R[3] + 14940, R[2]); goto L_800CCF2C; }  /* 0x800CCBF8 j */
L_800CCC00:;
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCC38; } }  /* 0x800CCC00 */
    R[2] = lw_(R[2] + 14944);  /* 0x800CCC08 */
    R[2] = ((int32_t)R[2] < 3);  /* 0x800CCC10 */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8014u << 16; if (_c) { goto L_800CCF2C; } }  /* 0x800CCC14 */
    R[2] = lw_(R[3] + 14940);  /* 0x800CCC1C */
    R[2] = R[2] - 1;  /* 0x800CCC24 */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[3] + 14940, R[2]); if (_c) { goto L_800CCC7C; } }  /* 0x800CCC28 */
    { sw_(R[3] + 14940, R[0]); goto L_800CCF2C; }  /* 0x800CCC30 j */
L_800CCC38:;
    R[2] = R[4] & 0x2000;  /* 0x800CCC38 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCC8C; } }  /* 0x800CCC3C */
    R[2] = lw_(R[2] + 14944);  /* 0x800CCC44 */
    R[2] = ((int32_t)R[2] < 3);  /* 0x800CCC4C */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8014u << 16; if (_c) { goto L_800CCF2C; } }  /* 0x800CCC50 */
    R[2] = lw_(R[3] + 14940);  /* 0x800CCC58 */
    R[2] = R[2] + 1;  /* 0x800CCC60 */
    sw_(R[3] + 14940, R[2]);  /* 0x800CCC64 */
    R[2] = ((int32_t)R[2] < 3);  /* 0x800CCC68 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 2; if (_c) { goto L_800CCC7C; } }  /* 0x800CCC6C */
    { sw_(R[3] + 14940, R[2]); goto L_800CCF2C; }  /* 0x800CCC74 j */
L_800CCC7C:;
    { R[31] = 0x800CCC84u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x800CCC7C jal */
    { R[2] = 0x8014u << 16; goto L_800CCF30; }  /* 0x800CCC84 j */
L_800CCC8C:;
    R[2] = R[4] & 0xC00;  /* 0x800CCC8C */
    { uint32_t _c = (R[2] == R[0]); R[17] = 0x8014u << 16; if (_c) { goto L_800CCCB0; } }  /* 0x800CCC90 */
    { R[31] = 0x800CCCA0u; R[4] = R[0] + 6; psx_next = 0x8002DB10u; return; }  /* 0x800CCC98 jal */
    { R[31] = 0x800CCCA8u; R[4] = R[0] + R[0]; psx_next = 0x800CBC98u; return; }  /* 0x800CCCA0 jal */
    { R[2] = 0x8014u << 16; goto L_800CCF30; }  /* 0x800CCCA8 j */
L_800CCCB0:;
    R[3] = lw_(R[17] + 14944);  /* 0x800CCCB0 */
    R[2] = R[0] + 3;  /* 0x800CCCB4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[4] & 0x1FF; if (_c) { goto L_800CCD24; } }  /* 0x800CCCB8 */
    R[2] = R[4] & 0xA0;  /* 0x800CCCC0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCCC4 */
    { R[31] = 0x800CCCD4u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x800CCCCC jal */
    R[2] = 0x8014u << 16;  /* 0x800CCCD4 */
    R[3] = R[2] + 14984;  /* 0x800CCCD8 */
    R[5] = R[0] + R[0];  /* 0x800CCCDC */
    R[2] = 0x8014u << 16;  /* 0x800CCCE0 */
    R[4] = R[2] + 14952;  /* 0x800CCCE4 */
L_800CCCE8:;
    R[2] = lh_(R[3]);  /* 0x800CCCE8 */
    R[3] = R[3] + 2;  /* 0x800CCCEC */
    R[5] = R[5] + 1;  /* 0x800CCCF0 */
    sh_(R[4], R[2]);  /* 0x800CCCF4 */
    R[2] = ((int32_t)R[5] < 9);  /* 0x800CCCF8 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[4] + 2; if (_c) { psx_bb(); goto L_800CCCE8; } }  /* 0x800CCCFC */
    R[5] = 0x8014u << 16;  /* 0x800CCD04 */
    R[4] = 0x8013u << 16;  /* 0x800CCD08 */
    R[2] = lw_(R[5] + 14936);  /* 0x800CCD0C */
    R[3] = R[0] + 40;  /* 0x800CCD10 */
    sw_(R[4] + 14084, R[3]);  /* 0x800CCD14 */
    R[2] = R[2] | 0x200;  /* 0x800CCD18 */
    { sw_(R[5] + 14936, R[2]); goto L_800CCF2C; }  /* 0x800CCD1C j */
L_800CCD24:;
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCD24 */
    { R[31] = 0x800CCD34u; R[4] = R[4] & 0xFFFF; psx_next = 0x800CBC58u; return; }  /* 0x800CCD2C jal */
    R[16] = R[2] + R[0];  /* 0x800CCD34 */
    { uint32_t _c = ((int32_t)R[16] < 0); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCD38 */
    { R[31] = 0x800CCD48u; R[4] = R[0] + 6; psx_next = 0x8002DB10u; return; }  /* 0x800CCD40 jal */
    R[5] = R[0] + R[0];  /* 0x800CCD48 */
    R[2] = 0x8014u << 16;  /* 0x800CCD4C */
    R[2] = R[2] + 14984;  /* 0x800CCD50 */
    R[7] = R[2] + R[0];  /* 0x800CCD54 */
    R[6] = R[7] + R[0];  /* 0x800CCD58 */
    R[2] = R[16] << 1;  /* 0x800CCD5C */
    R[2] = R[2] + R[7];  /* 0x800CCD60 */
    R[3] = 0x800Fu << 16;  /* 0x800CCD64 */
    R[3] = R[3] - 676;  /* 0x800CCD68 */
    R[4] = 0x8014u << 16;  /* 0x800CCD6C */
    R[8] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CCD70 */
    R[2] = lw_(R[17] + 14944);  /* 0x800CCD74 */
    R[4] = lw_(R[4] + 14940);  /* 0x800CCD78 */
    R[2] = R[2] << 2;  /* 0x800CCD7C */
    R[2] = R[2] + R[4];  /* 0x800CCD80 */
    R[2] = R[2] << 1;  /* 0x800CCD84 */
    R[2] = R[2] + R[3];  /* 0x800CCD88 */
    R[4] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CCD8C */
L_800CCD90:;
    R[3] = R[6] + R[0];  /* 0x800CCD90 */
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800CCD94 */
    { uint32_t _c = (R[4] == R[2]); R[5] = R[5] + 1; if (_c) { goto L_800CCED8; } }  /* 0x800CCD9C */
    R[2] = ((int32_t)R[5] < 9);  /* 0x800CCDA4 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[3] + 2; if (_c) { psx_bb(); goto L_800CCD90; } }  /* 0x800CCDA8 */
    { R[2] = 0x8014u << 16; goto L_800CCF30; }  /* 0x800CCDB0 j */
    R[16] = 0x8014u << 16;  /* 0x800CCDB8 */
    R[3] = lw_(R[16] + 14936);  /* 0x800CCDBC */
    R[2] = R[3] & 0x400;  /* 0x800CCDC4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCF2C; } }  /* 0x800CCDC8 */
    R[5] = R[4] + R[0];  /* 0x800CCDD0 */
    R[6] = 0x800Fu << 16;  /* 0x800CCDD4 */
    R[6] = R[6] - 1504;  /* 0x800CCDD8 */
    R[17] = 0x8014u << 16;  /* 0x800CCDDC */
    R[2] = R[0] - 1025;  /* 0x800CCDE0 */
    R[2] = R[3] & R[2];  /* 0x800CCDE4 */
    R[3] = ~(R[0] | R[2]);  /* 0x800CCDE8 */
    R[3] = R[3] & 0x10;  /* 0x800CCDEC */
    R[8] = R[0] - 17;  /* 0x800CCDF0 */
    R[2] = R[2] & R[8];  /* 0x800CCDF4 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCDF8 */
    R[2] = R[2] | R[3];  /* 0x800CCDFC */
    { R[31] = 0x800CCE08u; sw_(R[16] + 14936, R[2]); psx_next = 0x800B6CA4u; return; }  /* 0x800CCE00 jal */
    R[2] = lw_(R[16] + 14936);  /* 0x800CCE08 */
    R[2] = R[2] & 0x10;  /* 0x800CCE10 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCE44; } }  /* 0x800CCE14 */
    R[5] = R[4] + R[0];  /* 0x800CCE1C */
    R[6] = 0x800Fu << 16;  /* 0x800CCE20 */
    R[6] = R[6] - 1160;  /* 0x800CCE24 */
    R[2] = 0x8014u << 16;  /* 0x800CCE28 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE2C */
    R[3] = R[0] + 1;  /* 0x800CCE30 */
    sw_(R[2] + 14940, R[3]);  /* 0x800CCE34 */
    R[2] = 0x8014u << 16;  /* 0x800CCE38 */
    { sw_(R[2] + 14944, R[3]); goto L_800CCE6C; }  /* 0x800CCE3C j */
L_800CCE44:;
    R[5] = R[4] + R[0];  /* 0x800CCE44 */
    R[6] = 0x800Fu << 16;  /* 0x800CCE48 */
    R[6] = R[6] - 1060;  /* 0x800CCE4C */
    R[3] = 0x8014u << 16;  /* 0x800CCE50 */
    R[2] = R[0] + 1;  /* 0x800CCE54 */
    sw_(R[3] + 14940, R[2]);  /* 0x800CCE58 */
    R[3] = 0x8014u << 16;  /* 0x800CCE5C */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE60 */
    R[2] = R[0] + 3;  /* 0x800CCE64 */
    sw_(R[3] + 14944, R[2]);  /* 0x800CCE68 */
L_800CCE6C:;
    { R[31] = 0x800CCE74u; psx_next = 0x800B6CA4u; return; }  /* 0x800CCE6C jal */
    { R[3] = 0x8013u << 16; goto L_800CCEC4; }  /* 0x800CCE74 j */
    R[2] = 0x8014u << 16;  /* 0x800CCE7C */
    R[3] = lw_(R[2] + 14936);  /* 0x800CCE80 */
    R[2] = R[3] & 0x100;  /* 0x800CCE88 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x10; if (_c) { goto L_800CCF2C; } }  /* 0x800CCE8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800CCEAC; } }  /* 0x800CCE94 */
    R[3] = 0x8013u << 16;  /* 0x800CCE9C */
    R[2] = R[0] + 10;  /* 0x800CCEA0 */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEA4 j */
L_800CCEAC:;
    R[2] = R[0] + 20;  /* 0x800CCEAC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEB0 j */
    { R[31] = 0x800CCEC0u; R[4] = R[0] + 7; psx_next = 0x8001D930u; return; }  /* 0x800CCEB8 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCEC0 */
L_800CCEC4:;
    R[2] = lw_(R[3] + 14084);  /* 0x800CCEC4 */
    R[2] = R[2] + 1;  /* 0x800CCECC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCED0 j */
L_800CCED8:;
    R[2] = R[16] << 1;  /* 0x800CCED8 */
    R[2] = R[2] + R[7];  /* 0x800CCEDC */
    sh_(R[6], R[8]);  /* 0x800CCEE0 */
    { sh_(R[2], R[4]); goto L_800CCF2C; }  /* 0x800CCEE4 j */
    R[2] = 0x8006u << 16;  /* 0x800CCEEC */
    R[3] = lb_(R[2] + 16409);  /* 0x800CCEF0 */
    R[2] = R[0] + 5;  /* 0x800CCEF4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCEF8 */
    R[2] = 0x8014u << 16;  /* 0x800CCF00 */
    R[4] = lw_(R[2] + 14948);  /* 0x800CCF04 */
    R[3] = lh_(R[2] + 14948);  /* 0x800CCF08 */
    R[2] = 0x8006u << 16;  /* 0x800CCF0C */
    { R[31] = 0x800CCF18u; sh_(R[2] + 13234, R[3]); psx_next = 0x800CBD84u; return; }  /* 0x800CCF10 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCF18 */
    R[2] = lw_(R[3] + 14104);  /* 0x800CCF1C */
    R[2] = R[2] | 0x1;  /* 0x800CCF24 */
    sw_(R[3] + 14104, R[2]);  /* 0x800CCF28 */
L_800CCF2C:;
    R[2] = 0x8014u << 16;  /* 0x800CCF2C */
L_800CCF30:;
    R[2] = lw_(R[2] + 14936);  /* 0x800CCF30 */
    R[2] = R[2] & 0x20;  /* 0x800CCF38 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x8013u << 16; if (_c) { goto L_800CCF5C; } }  /* 0x800CCF3C */
    R[2] = 0x8013u << 16;  /* 0x800CCF44 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF48 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF4C */
    { R[31] = 0x800CCF58u; R[5] = R[5] + 512; psx_next = 0x800CBB4Cu; return; }  /* 0x800CCF50 jal */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF58 */
L_800CCF5C:;
    R[16] = 0x8013u << 16;  /* 0x800CCF5C */
    R[2] = 0x8013u << 16;  /* 0x800CCF60 */
    R[3] = 0x8013u << 16;  /* 0x800CCF64 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF68 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF6C */
    R[6] = lw_(R[3] + 14052);  /* 0x800CCF70 */
    { R[31] = 0x800CCF7Cu; R[5] = R[5] + 1792; psx_next = 0x800B673Cu; return; }  /* 0x800CCF74 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCBDC(void) {
    R[2] = 0x8014u << 16;  /* 0x800CCBDC */
    R[3] = lw_(R[2] + 14944);  /* 0x800CCBE0 */
    R[2] = R[0] + 3;  /* 0x800CCBE4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCBE8 */
    R[3] = 0x8014u << 16;  /* 0x800CCBF0 */
    R[2] = R[0] + 1;  /* 0x800CCBF4 */
    { sw_(R[3] + 14940, R[2]); goto L_800CCF2C; }  /* 0x800CCBF8 j */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCC38; } }  /* 0x800CCC00 */
    R[2] = lw_(R[2] + 14944);  /* 0x800CCC08 */
    R[2] = ((int32_t)R[2] < 3);  /* 0x800CCC10 */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8014u << 16; if (_c) { goto L_800CCF2C; } }  /* 0x800CCC14 */
    R[2] = lw_(R[3] + 14940);  /* 0x800CCC1C */
    R[2] = R[2] - 1;  /* 0x800CCC24 */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[3] + 14940, R[2]); if (_c) { goto L_800CCC7C; } }  /* 0x800CCC28 */
    { sw_(R[3] + 14940, R[0]); goto L_800CCF2C; }  /* 0x800CCC30 j */
L_800CCC38:;
    R[2] = R[4] & 0x2000;  /* 0x800CCC38 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCC8C; } }  /* 0x800CCC3C */
    R[2] = lw_(R[2] + 14944);  /* 0x800CCC44 */
    R[2] = ((int32_t)R[2] < 3);  /* 0x800CCC4C */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8014u << 16; if (_c) { goto L_800CCF2C; } }  /* 0x800CCC50 */
    R[2] = lw_(R[3] + 14940);  /* 0x800CCC58 */
    R[2] = R[2] + 1;  /* 0x800CCC60 */
    sw_(R[3] + 14940, R[2]);  /* 0x800CCC64 */
    R[2] = ((int32_t)R[2] < 3);  /* 0x800CCC68 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 2; if (_c) { goto L_800CCC7C; } }  /* 0x800CCC6C */
    { sw_(R[3] + 14940, R[2]); goto L_800CCF2C; }  /* 0x800CCC74 j */
L_800CCC7C:;
    { R[31] = 0x800CCC84u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x800CCC7C jal */
    { R[2] = 0x8014u << 16; goto L_800CCF30; }  /* 0x800CCC84 j */
L_800CCC8C:;
    R[2] = R[4] & 0xC00;  /* 0x800CCC8C */
    { uint32_t _c = (R[2] == R[0]); R[17] = 0x8014u << 16; if (_c) { goto L_800CCCB0; } }  /* 0x800CCC90 */
    { R[31] = 0x800CCCA0u; R[4] = R[0] + 6; psx_next = 0x8002DB10u; return; }  /* 0x800CCC98 jal */
    { R[31] = 0x800CCCA8u; R[4] = R[0] + R[0]; psx_next = 0x800CBC98u; return; }  /* 0x800CCCA0 jal */
    { R[2] = 0x8014u << 16; goto L_800CCF30; }  /* 0x800CCCA8 j */
L_800CCCB0:;
    R[3] = lw_(R[17] + 14944);  /* 0x800CCCB0 */
    R[2] = R[0] + 3;  /* 0x800CCCB4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[4] & 0x1FF; if (_c) { goto L_800CCD24; } }  /* 0x800CCCB8 */
    R[2] = R[4] & 0xA0;  /* 0x800CCCC0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCCC4 */
    { R[31] = 0x800CCCD4u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x800CCCCC jal */
    R[2] = 0x8014u << 16;  /* 0x800CCCD4 */
    R[3] = R[2] + 14984;  /* 0x800CCCD8 */
    R[5] = R[0] + R[0];  /* 0x800CCCDC */
    R[2] = 0x8014u << 16;  /* 0x800CCCE0 */
    R[4] = R[2] + 14952;  /* 0x800CCCE4 */
L_800CCCE8:;
    R[2] = lh_(R[3]);  /* 0x800CCCE8 */
    R[3] = R[3] + 2;  /* 0x800CCCEC */
    R[5] = R[5] + 1;  /* 0x800CCCF0 */
    sh_(R[4], R[2]);  /* 0x800CCCF4 */
    R[2] = ((int32_t)R[5] < 9);  /* 0x800CCCF8 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[4] + 2; if (_c) { psx_bb(); goto L_800CCCE8; } }  /* 0x800CCCFC */
    R[5] = 0x8014u << 16;  /* 0x800CCD04 */
    R[4] = 0x8013u << 16;  /* 0x800CCD08 */
    R[2] = lw_(R[5] + 14936);  /* 0x800CCD0C */
    R[3] = R[0] + 40;  /* 0x800CCD10 */
    sw_(R[4] + 14084, R[3]);  /* 0x800CCD14 */
    R[2] = R[2] | 0x200;  /* 0x800CCD18 */
    { sw_(R[5] + 14936, R[2]); goto L_800CCF2C; }  /* 0x800CCD1C j */
L_800CCD24:;
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCD24 */
    { R[31] = 0x800CCD34u; R[4] = R[4] & 0xFFFF; psx_next = 0x800CBC58u; return; }  /* 0x800CCD2C jal */
    R[16] = R[2] + R[0];  /* 0x800CCD34 */
    { uint32_t _c = ((int32_t)R[16] < 0); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCD38 */
    { R[31] = 0x800CCD48u; R[4] = R[0] + 6; psx_next = 0x8002DB10u; return; }  /* 0x800CCD40 jal */
    R[5] = R[0] + R[0];  /* 0x800CCD48 */
    R[2] = 0x8014u << 16;  /* 0x800CCD4C */
    R[2] = R[2] + 14984;  /* 0x800CCD50 */
    R[7] = R[2] + R[0];  /* 0x800CCD54 */
    R[6] = R[7] + R[0];  /* 0x800CCD58 */
    R[2] = R[16] << 1;  /* 0x800CCD5C */
    R[2] = R[2] + R[7];  /* 0x800CCD60 */
    R[3] = 0x800Fu << 16;  /* 0x800CCD64 */
    R[3] = R[3] - 676;  /* 0x800CCD68 */
    R[4] = 0x8014u << 16;  /* 0x800CCD6C */
    R[8] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CCD70 */
    R[2] = lw_(R[17] + 14944);  /* 0x800CCD74 */
    R[4] = lw_(R[4] + 14940);  /* 0x800CCD78 */
    R[2] = R[2] << 2;  /* 0x800CCD7C */
    R[2] = R[2] + R[4];  /* 0x800CCD80 */
    R[2] = R[2] << 1;  /* 0x800CCD84 */
    R[2] = R[2] + R[3];  /* 0x800CCD88 */
    R[4] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CCD8C */
L_800CCD90:;
    R[3] = R[6] + R[0];  /* 0x800CCD90 */
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800CCD94 */
    { uint32_t _c = (R[4] == R[2]); R[5] = R[5] + 1; if (_c) { goto L_800CCED8; } }  /* 0x800CCD9C */
    R[2] = ((int32_t)R[5] < 9);  /* 0x800CCDA4 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[3] + 2; if (_c) { psx_bb(); goto L_800CCD90; } }  /* 0x800CCDA8 */
    { R[2] = 0x8014u << 16; goto L_800CCF30; }  /* 0x800CCDB0 j */
    R[16] = 0x8014u << 16;  /* 0x800CCDB8 */
    R[3] = lw_(R[16] + 14936);  /* 0x800CCDBC */
    R[2] = R[3] & 0x400;  /* 0x800CCDC4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCF2C; } }  /* 0x800CCDC8 */
    R[5] = R[4] + R[0];  /* 0x800CCDD0 */
    R[6] = 0x800Fu << 16;  /* 0x800CCDD4 */
    R[6] = R[6] - 1504;  /* 0x800CCDD8 */
    R[17] = 0x8014u << 16;  /* 0x800CCDDC */
    R[2] = R[0] - 1025;  /* 0x800CCDE0 */
    R[2] = R[3] & R[2];  /* 0x800CCDE4 */
    R[3] = ~(R[0] | R[2]);  /* 0x800CCDE8 */
    R[3] = R[3] & 0x10;  /* 0x800CCDEC */
    R[8] = R[0] - 17;  /* 0x800CCDF0 */
    R[2] = R[2] & R[8];  /* 0x800CCDF4 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCDF8 */
    R[2] = R[2] | R[3];  /* 0x800CCDFC */
    { R[31] = 0x800CCE08u; sw_(R[16] + 14936, R[2]); psx_next = 0x800B6CA4u; return; }  /* 0x800CCE00 jal */
    R[2] = lw_(R[16] + 14936);  /* 0x800CCE08 */
    R[2] = R[2] & 0x10;  /* 0x800CCE10 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCE44; } }  /* 0x800CCE14 */
    R[5] = R[4] + R[0];  /* 0x800CCE1C */
    R[6] = 0x800Fu << 16;  /* 0x800CCE20 */
    R[6] = R[6] - 1160;  /* 0x800CCE24 */
    R[2] = 0x8014u << 16;  /* 0x800CCE28 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE2C */
    R[3] = R[0] + 1;  /* 0x800CCE30 */
    sw_(R[2] + 14940, R[3]);  /* 0x800CCE34 */
    R[2] = 0x8014u << 16;  /* 0x800CCE38 */
    { sw_(R[2] + 14944, R[3]); goto L_800CCE6C; }  /* 0x800CCE3C j */
L_800CCE44:;
    R[5] = R[4] + R[0];  /* 0x800CCE44 */
    R[6] = 0x800Fu << 16;  /* 0x800CCE48 */
    R[6] = R[6] - 1060;  /* 0x800CCE4C */
    R[3] = 0x8014u << 16;  /* 0x800CCE50 */
    R[2] = R[0] + 1;  /* 0x800CCE54 */
    sw_(R[3] + 14940, R[2]);  /* 0x800CCE58 */
    R[3] = 0x8014u << 16;  /* 0x800CCE5C */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE60 */
    R[2] = R[0] + 3;  /* 0x800CCE64 */
    sw_(R[3] + 14944, R[2]);  /* 0x800CCE68 */
L_800CCE6C:;
    { R[31] = 0x800CCE74u; psx_next = 0x800B6CA4u; return; }  /* 0x800CCE6C jal */
    { R[3] = 0x8013u << 16; goto L_800CCEC4; }  /* 0x800CCE74 j */
    R[2] = 0x8014u << 16;  /* 0x800CCE7C */
    R[3] = lw_(R[2] + 14936);  /* 0x800CCE80 */
    R[2] = R[3] & 0x100;  /* 0x800CCE88 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x10; if (_c) { goto L_800CCF2C; } }  /* 0x800CCE8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800CCEAC; } }  /* 0x800CCE94 */
    R[3] = 0x8013u << 16;  /* 0x800CCE9C */
    R[2] = R[0] + 10;  /* 0x800CCEA0 */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEA4 j */
L_800CCEAC:;
    R[2] = R[0] + 20;  /* 0x800CCEAC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEB0 j */
    { R[31] = 0x800CCEC0u; R[4] = R[0] + 7; psx_next = 0x8001D930u; return; }  /* 0x800CCEB8 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCEC0 */
L_800CCEC4:;
    R[2] = lw_(R[3] + 14084);  /* 0x800CCEC4 */
    R[2] = R[2] + 1;  /* 0x800CCECC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCED0 j */
L_800CCED8:;
    R[2] = R[16] << 1;  /* 0x800CCED8 */
    R[2] = R[2] + R[7];  /* 0x800CCEDC */
    sh_(R[6], R[8]);  /* 0x800CCEE0 */
    { sh_(R[2], R[4]); goto L_800CCF2C; }  /* 0x800CCEE4 j */
    R[2] = 0x8006u << 16;  /* 0x800CCEEC */
    R[3] = lb_(R[2] + 16409);  /* 0x800CCEF0 */
    R[2] = R[0] + 5;  /* 0x800CCEF4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCEF8 */
    R[2] = 0x8014u << 16;  /* 0x800CCF00 */
    R[4] = lw_(R[2] + 14948);  /* 0x800CCF04 */
    R[3] = lh_(R[2] + 14948);  /* 0x800CCF08 */
    R[2] = 0x8006u << 16;  /* 0x800CCF0C */
    { R[31] = 0x800CCF18u; sh_(R[2] + 13234, R[3]); psx_next = 0x800CBD84u; return; }  /* 0x800CCF10 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCF18 */
    R[2] = lw_(R[3] + 14104);  /* 0x800CCF1C */
    R[2] = R[2] | 0x1;  /* 0x800CCF24 */
    sw_(R[3] + 14104, R[2]);  /* 0x800CCF28 */
L_800CCF2C:;
    R[2] = 0x8014u << 16;  /* 0x800CCF2C */
L_800CCF30:;
    R[2] = lw_(R[2] + 14936);  /* 0x800CCF30 */
    R[2] = R[2] & 0x20;  /* 0x800CCF38 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x8013u << 16; if (_c) { goto L_800CCF5C; } }  /* 0x800CCF3C */
    R[2] = 0x8013u << 16;  /* 0x800CCF44 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF48 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF4C */
    { R[31] = 0x800CCF58u; R[5] = R[5] + 512; psx_next = 0x800CBB4Cu; return; }  /* 0x800CCF50 jal */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF58 */
L_800CCF5C:;
    R[16] = 0x8013u << 16;  /* 0x800CCF5C */
    R[2] = 0x8013u << 16;  /* 0x800CCF60 */
    R[3] = 0x8013u << 16;  /* 0x800CCF64 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF68 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF6C */
    R[6] = lw_(R[3] + 14052);  /* 0x800CCF70 */
    { R[31] = 0x800CCF7Cu; R[5] = R[5] + 1792; psx_next = 0x800B673Cu; return; }  /* 0x800CCF74 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCC84(void) {
    { R[2] = 0x8014u << 16; goto L_800CCF30; }  /* 0x800CCC84 j */
    R[2] = R[4] & 0xC00;  /* 0x800CCC8C */
    { uint32_t _c = (R[2] == R[0]); R[17] = 0x8014u << 16; if (_c) { goto L_800CCCB0; } }  /* 0x800CCC90 */
    { R[31] = 0x800CCCA0u; R[4] = R[0] + 6; psx_next = 0x8002DB10u; return; }  /* 0x800CCC98 jal */
    { R[31] = 0x800CCCA8u; R[4] = R[0] + R[0]; psx_next = 0x800CBC98u; return; }  /* 0x800CCCA0 jal */
    { R[2] = 0x8014u << 16; goto L_800CCF30; }  /* 0x800CCCA8 j */
L_800CCCB0:;
    R[3] = lw_(R[17] + 14944);  /* 0x800CCCB0 */
    R[2] = R[0] + 3;  /* 0x800CCCB4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[4] & 0x1FF; if (_c) { goto L_800CCD24; } }  /* 0x800CCCB8 */
    R[2] = R[4] & 0xA0;  /* 0x800CCCC0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCCC4 */
    { R[31] = 0x800CCCD4u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x800CCCCC jal */
    R[2] = 0x8014u << 16;  /* 0x800CCCD4 */
    R[3] = R[2] + 14984;  /* 0x800CCCD8 */
    R[5] = R[0] + R[0];  /* 0x800CCCDC */
    R[2] = 0x8014u << 16;  /* 0x800CCCE0 */
    R[4] = R[2] + 14952;  /* 0x800CCCE4 */
L_800CCCE8:;
    R[2] = lh_(R[3]);  /* 0x800CCCE8 */
    R[3] = R[3] + 2;  /* 0x800CCCEC */
    R[5] = R[5] + 1;  /* 0x800CCCF0 */
    sh_(R[4], R[2]);  /* 0x800CCCF4 */
    R[2] = ((int32_t)R[5] < 9);  /* 0x800CCCF8 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[4] + 2; if (_c) { psx_bb(); goto L_800CCCE8; } }  /* 0x800CCCFC */
    R[5] = 0x8014u << 16;  /* 0x800CCD04 */
    R[4] = 0x8013u << 16;  /* 0x800CCD08 */
    R[2] = lw_(R[5] + 14936);  /* 0x800CCD0C */
    R[3] = R[0] + 40;  /* 0x800CCD10 */
    sw_(R[4] + 14084, R[3]);  /* 0x800CCD14 */
    R[2] = R[2] | 0x200;  /* 0x800CCD18 */
    { sw_(R[5] + 14936, R[2]); goto L_800CCF2C; }  /* 0x800CCD1C j */
L_800CCD24:;
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCD24 */
    { R[31] = 0x800CCD34u; R[4] = R[4] & 0xFFFF; psx_next = 0x800CBC58u; return; }  /* 0x800CCD2C jal */
    R[16] = R[2] + R[0];  /* 0x800CCD34 */
    { uint32_t _c = ((int32_t)R[16] < 0); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCD38 */
    { R[31] = 0x800CCD48u; R[4] = R[0] + 6; psx_next = 0x8002DB10u; return; }  /* 0x800CCD40 jal */
    R[5] = R[0] + R[0];  /* 0x800CCD48 */
    R[2] = 0x8014u << 16;  /* 0x800CCD4C */
    R[2] = R[2] + 14984;  /* 0x800CCD50 */
    R[7] = R[2] + R[0];  /* 0x800CCD54 */
    R[6] = R[7] + R[0];  /* 0x800CCD58 */
    R[2] = R[16] << 1;  /* 0x800CCD5C */
    R[2] = R[2] + R[7];  /* 0x800CCD60 */
    R[3] = 0x800Fu << 16;  /* 0x800CCD64 */
    R[3] = R[3] - 676;  /* 0x800CCD68 */
    R[4] = 0x8014u << 16;  /* 0x800CCD6C */
    R[8] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CCD70 */
    R[2] = lw_(R[17] + 14944);  /* 0x800CCD74 */
    R[4] = lw_(R[4] + 14940);  /* 0x800CCD78 */
    R[2] = R[2] << 2;  /* 0x800CCD7C */
    R[2] = R[2] + R[4];  /* 0x800CCD80 */
    R[2] = R[2] << 1;  /* 0x800CCD84 */
    R[2] = R[2] + R[3];  /* 0x800CCD88 */
    R[4] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CCD8C */
L_800CCD90:;
    R[3] = R[6] + R[0];  /* 0x800CCD90 */
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800CCD94 */
    { uint32_t _c = (R[4] == R[2]); R[5] = R[5] + 1; if (_c) { goto L_800CCED8; } }  /* 0x800CCD9C */
    R[2] = ((int32_t)R[5] < 9);  /* 0x800CCDA4 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[3] + 2; if (_c) { psx_bb(); goto L_800CCD90; } }  /* 0x800CCDA8 */
    { R[2] = 0x8014u << 16; goto L_800CCF30; }  /* 0x800CCDB0 j */
    R[16] = 0x8014u << 16;  /* 0x800CCDB8 */
    R[3] = lw_(R[16] + 14936);  /* 0x800CCDBC */
    R[2] = R[3] & 0x400;  /* 0x800CCDC4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCF2C; } }  /* 0x800CCDC8 */
    R[5] = R[4] + R[0];  /* 0x800CCDD0 */
    R[6] = 0x800Fu << 16;  /* 0x800CCDD4 */
    R[6] = R[6] - 1504;  /* 0x800CCDD8 */
    R[17] = 0x8014u << 16;  /* 0x800CCDDC */
    R[2] = R[0] - 1025;  /* 0x800CCDE0 */
    R[2] = R[3] & R[2];  /* 0x800CCDE4 */
    R[3] = ~(R[0] | R[2]);  /* 0x800CCDE8 */
    R[3] = R[3] & 0x10;  /* 0x800CCDEC */
    R[8] = R[0] - 17;  /* 0x800CCDF0 */
    R[2] = R[2] & R[8];  /* 0x800CCDF4 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCDF8 */
    R[2] = R[2] | R[3];  /* 0x800CCDFC */
    { R[31] = 0x800CCE08u; sw_(R[16] + 14936, R[2]); psx_next = 0x800B6CA4u; return; }  /* 0x800CCE00 jal */
    R[2] = lw_(R[16] + 14936);  /* 0x800CCE08 */
    R[2] = R[2] & 0x10;  /* 0x800CCE10 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCE44; } }  /* 0x800CCE14 */
    R[5] = R[4] + R[0];  /* 0x800CCE1C */
    R[6] = 0x800Fu << 16;  /* 0x800CCE20 */
    R[6] = R[6] - 1160;  /* 0x800CCE24 */
    R[2] = 0x8014u << 16;  /* 0x800CCE28 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE2C */
    R[3] = R[0] + 1;  /* 0x800CCE30 */
    sw_(R[2] + 14940, R[3]);  /* 0x800CCE34 */
    R[2] = 0x8014u << 16;  /* 0x800CCE38 */
    { sw_(R[2] + 14944, R[3]); goto L_800CCE6C; }  /* 0x800CCE3C j */
L_800CCE44:;
    R[5] = R[4] + R[0];  /* 0x800CCE44 */
    R[6] = 0x800Fu << 16;  /* 0x800CCE48 */
    R[6] = R[6] - 1060;  /* 0x800CCE4C */
    R[3] = 0x8014u << 16;  /* 0x800CCE50 */
    R[2] = R[0] + 1;  /* 0x800CCE54 */
    sw_(R[3] + 14940, R[2]);  /* 0x800CCE58 */
    R[3] = 0x8014u << 16;  /* 0x800CCE5C */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE60 */
    R[2] = R[0] + 3;  /* 0x800CCE64 */
    sw_(R[3] + 14944, R[2]);  /* 0x800CCE68 */
L_800CCE6C:;
    { R[31] = 0x800CCE74u; psx_next = 0x800B6CA4u; return; }  /* 0x800CCE6C jal */
    { R[3] = 0x8013u << 16; goto L_800CCEC4; }  /* 0x800CCE74 j */
    R[2] = 0x8014u << 16;  /* 0x800CCE7C */
    R[3] = lw_(R[2] + 14936);  /* 0x800CCE80 */
    R[2] = R[3] & 0x100;  /* 0x800CCE88 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x10; if (_c) { goto L_800CCF2C; } }  /* 0x800CCE8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800CCEAC; } }  /* 0x800CCE94 */
    R[3] = 0x8013u << 16;  /* 0x800CCE9C */
    R[2] = R[0] + 10;  /* 0x800CCEA0 */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEA4 j */
L_800CCEAC:;
    R[2] = R[0] + 20;  /* 0x800CCEAC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEB0 j */
    { R[31] = 0x800CCEC0u; R[4] = R[0] + 7; psx_next = 0x8001D930u; return; }  /* 0x800CCEB8 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCEC0 */
L_800CCEC4:;
    R[2] = lw_(R[3] + 14084);  /* 0x800CCEC4 */
    R[2] = R[2] + 1;  /* 0x800CCECC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCED0 j */
L_800CCED8:;
    R[2] = R[16] << 1;  /* 0x800CCED8 */
    R[2] = R[2] + R[7];  /* 0x800CCEDC */
    sh_(R[6], R[8]);  /* 0x800CCEE0 */
    { sh_(R[2], R[4]); goto L_800CCF2C; }  /* 0x800CCEE4 j */
    R[2] = 0x8006u << 16;  /* 0x800CCEEC */
    R[3] = lb_(R[2] + 16409);  /* 0x800CCEF0 */
    R[2] = R[0] + 5;  /* 0x800CCEF4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCEF8 */
    R[2] = 0x8014u << 16;  /* 0x800CCF00 */
    R[4] = lw_(R[2] + 14948);  /* 0x800CCF04 */
    R[3] = lh_(R[2] + 14948);  /* 0x800CCF08 */
    R[2] = 0x8006u << 16;  /* 0x800CCF0C */
    { R[31] = 0x800CCF18u; sh_(R[2] + 13234, R[3]); psx_next = 0x800CBD84u; return; }  /* 0x800CCF10 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCF18 */
    R[2] = lw_(R[3] + 14104);  /* 0x800CCF1C */
    R[2] = R[2] | 0x1;  /* 0x800CCF24 */
    sw_(R[3] + 14104, R[2]);  /* 0x800CCF28 */
L_800CCF2C:;
    R[2] = 0x8014u << 16;  /* 0x800CCF2C */
L_800CCF30:;
    R[2] = lw_(R[2] + 14936);  /* 0x800CCF30 */
    R[2] = R[2] & 0x20;  /* 0x800CCF38 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x8013u << 16; if (_c) { goto L_800CCF5C; } }  /* 0x800CCF3C */
    R[2] = 0x8013u << 16;  /* 0x800CCF44 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF48 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF4C */
    { R[31] = 0x800CCF58u; R[5] = R[5] + 512; psx_next = 0x800CBB4Cu; return; }  /* 0x800CCF50 jal */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF58 */
L_800CCF5C:;
    R[16] = 0x8013u << 16;  /* 0x800CCF5C */
    R[2] = 0x8013u << 16;  /* 0x800CCF60 */
    R[3] = 0x8013u << 16;  /* 0x800CCF64 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF68 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF6C */
    R[6] = lw_(R[3] + 14052);  /* 0x800CCF70 */
    { R[31] = 0x800CCF7Cu; R[5] = R[5] + 1792; psx_next = 0x800B673Cu; return; }  /* 0x800CCF74 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCCA0(void) {
    { R[31] = 0x800CCCA8u; R[4] = R[0] + R[0]; psx_next = 0x800CBC98u; return; }  /* 0x800CCCA0 jal */
    { R[2] = 0x8014u << 16; goto L_800CCF30; }  /* 0x800CCCA8 j */
    R[3] = lw_(R[17] + 14944);  /* 0x800CCCB0 */
    R[2] = R[0] + 3;  /* 0x800CCCB4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[4] & 0x1FF; if (_c) { goto L_800CCD24; } }  /* 0x800CCCB8 */
    R[2] = R[4] & 0xA0;  /* 0x800CCCC0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCCC4 */
    { R[31] = 0x800CCCD4u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x800CCCCC jal */
    R[2] = 0x8014u << 16;  /* 0x800CCCD4 */
    R[3] = R[2] + 14984;  /* 0x800CCCD8 */
    R[5] = R[0] + R[0];  /* 0x800CCCDC */
    R[2] = 0x8014u << 16;  /* 0x800CCCE0 */
    R[4] = R[2] + 14952;  /* 0x800CCCE4 */
L_800CCCE8:;
    R[2] = lh_(R[3]);  /* 0x800CCCE8 */
    R[3] = R[3] + 2;  /* 0x800CCCEC */
    R[5] = R[5] + 1;  /* 0x800CCCF0 */
    sh_(R[4], R[2]);  /* 0x800CCCF4 */
    R[2] = ((int32_t)R[5] < 9);  /* 0x800CCCF8 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[4] + 2; if (_c) { psx_bb(); goto L_800CCCE8; } }  /* 0x800CCCFC */
    R[5] = 0x8014u << 16;  /* 0x800CCD04 */
    R[4] = 0x8013u << 16;  /* 0x800CCD08 */
    R[2] = lw_(R[5] + 14936);  /* 0x800CCD0C */
    R[3] = R[0] + 40;  /* 0x800CCD10 */
    sw_(R[4] + 14084, R[3]);  /* 0x800CCD14 */
    R[2] = R[2] | 0x200;  /* 0x800CCD18 */
    { sw_(R[5] + 14936, R[2]); goto L_800CCF2C; }  /* 0x800CCD1C j */
L_800CCD24:;
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCD24 */
    { R[31] = 0x800CCD34u; R[4] = R[4] & 0xFFFF; psx_next = 0x800CBC58u; return; }  /* 0x800CCD2C jal */
    R[16] = R[2] + R[0];  /* 0x800CCD34 */
    { uint32_t _c = ((int32_t)R[16] < 0); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCD38 */
    { R[31] = 0x800CCD48u; R[4] = R[0] + 6; psx_next = 0x8002DB10u; return; }  /* 0x800CCD40 jal */
    R[5] = R[0] + R[0];  /* 0x800CCD48 */
    R[2] = 0x8014u << 16;  /* 0x800CCD4C */
    R[2] = R[2] + 14984;  /* 0x800CCD50 */
    R[7] = R[2] + R[0];  /* 0x800CCD54 */
    R[6] = R[7] + R[0];  /* 0x800CCD58 */
    R[2] = R[16] << 1;  /* 0x800CCD5C */
    R[2] = R[2] + R[7];  /* 0x800CCD60 */
    R[3] = 0x800Fu << 16;  /* 0x800CCD64 */
    R[3] = R[3] - 676;  /* 0x800CCD68 */
    R[4] = 0x8014u << 16;  /* 0x800CCD6C */
    R[8] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CCD70 */
    R[2] = lw_(R[17] + 14944);  /* 0x800CCD74 */
    R[4] = lw_(R[4] + 14940);  /* 0x800CCD78 */
    R[2] = R[2] << 2;  /* 0x800CCD7C */
    R[2] = R[2] + R[4];  /* 0x800CCD80 */
    R[2] = R[2] << 1;  /* 0x800CCD84 */
    R[2] = R[2] + R[3];  /* 0x800CCD88 */
    R[4] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CCD8C */
L_800CCD90:;
    R[3] = R[6] + R[0];  /* 0x800CCD90 */
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800CCD94 */
    { uint32_t _c = (R[4] == R[2]); R[5] = R[5] + 1; if (_c) { goto L_800CCED8; } }  /* 0x800CCD9C */
    R[2] = ((int32_t)R[5] < 9);  /* 0x800CCDA4 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[3] + 2; if (_c) { psx_bb(); goto L_800CCD90; } }  /* 0x800CCDA8 */
    { R[2] = 0x8014u << 16; goto L_800CCF30; }  /* 0x800CCDB0 j */
    R[16] = 0x8014u << 16;  /* 0x800CCDB8 */
    R[3] = lw_(R[16] + 14936);  /* 0x800CCDBC */
    R[2] = R[3] & 0x400;  /* 0x800CCDC4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCF2C; } }  /* 0x800CCDC8 */
    R[5] = R[4] + R[0];  /* 0x800CCDD0 */
    R[6] = 0x800Fu << 16;  /* 0x800CCDD4 */
    R[6] = R[6] - 1504;  /* 0x800CCDD8 */
    R[17] = 0x8014u << 16;  /* 0x800CCDDC */
    R[2] = R[0] - 1025;  /* 0x800CCDE0 */
    R[2] = R[3] & R[2];  /* 0x800CCDE4 */
    R[3] = ~(R[0] | R[2]);  /* 0x800CCDE8 */
    R[3] = R[3] & 0x10;  /* 0x800CCDEC */
    R[8] = R[0] - 17;  /* 0x800CCDF0 */
    R[2] = R[2] & R[8];  /* 0x800CCDF4 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCDF8 */
    R[2] = R[2] | R[3];  /* 0x800CCDFC */
    { R[31] = 0x800CCE08u; sw_(R[16] + 14936, R[2]); psx_next = 0x800B6CA4u; return; }  /* 0x800CCE00 jal */
    R[2] = lw_(R[16] + 14936);  /* 0x800CCE08 */
    R[2] = R[2] & 0x10;  /* 0x800CCE10 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCE44; } }  /* 0x800CCE14 */
    R[5] = R[4] + R[0];  /* 0x800CCE1C */
    R[6] = 0x800Fu << 16;  /* 0x800CCE20 */
    R[6] = R[6] - 1160;  /* 0x800CCE24 */
    R[2] = 0x8014u << 16;  /* 0x800CCE28 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE2C */
    R[3] = R[0] + 1;  /* 0x800CCE30 */
    sw_(R[2] + 14940, R[3]);  /* 0x800CCE34 */
    R[2] = 0x8014u << 16;  /* 0x800CCE38 */
    { sw_(R[2] + 14944, R[3]); goto L_800CCE6C; }  /* 0x800CCE3C j */
L_800CCE44:;
    R[5] = R[4] + R[0];  /* 0x800CCE44 */
    R[6] = 0x800Fu << 16;  /* 0x800CCE48 */
    R[6] = R[6] - 1060;  /* 0x800CCE4C */
    R[3] = 0x8014u << 16;  /* 0x800CCE50 */
    R[2] = R[0] + 1;  /* 0x800CCE54 */
    sw_(R[3] + 14940, R[2]);  /* 0x800CCE58 */
    R[3] = 0x8014u << 16;  /* 0x800CCE5C */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE60 */
    R[2] = R[0] + 3;  /* 0x800CCE64 */
    sw_(R[3] + 14944, R[2]);  /* 0x800CCE68 */
L_800CCE6C:;
    { R[31] = 0x800CCE74u; psx_next = 0x800B6CA4u; return; }  /* 0x800CCE6C jal */
    { R[3] = 0x8013u << 16; goto L_800CCEC4; }  /* 0x800CCE74 j */
    R[2] = 0x8014u << 16;  /* 0x800CCE7C */
    R[3] = lw_(R[2] + 14936);  /* 0x800CCE80 */
    R[2] = R[3] & 0x100;  /* 0x800CCE88 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x10; if (_c) { goto L_800CCF2C; } }  /* 0x800CCE8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800CCEAC; } }  /* 0x800CCE94 */
    R[3] = 0x8013u << 16;  /* 0x800CCE9C */
    R[2] = R[0] + 10;  /* 0x800CCEA0 */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEA4 j */
L_800CCEAC:;
    R[2] = R[0] + 20;  /* 0x800CCEAC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEB0 j */
    { R[31] = 0x800CCEC0u; R[4] = R[0] + 7; psx_next = 0x8001D930u; return; }  /* 0x800CCEB8 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCEC0 */
L_800CCEC4:;
    R[2] = lw_(R[3] + 14084);  /* 0x800CCEC4 */
    R[2] = R[2] + 1;  /* 0x800CCECC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCED0 j */
L_800CCED8:;
    R[2] = R[16] << 1;  /* 0x800CCED8 */
    R[2] = R[2] + R[7];  /* 0x800CCEDC */
    sh_(R[6], R[8]);  /* 0x800CCEE0 */
    { sh_(R[2], R[4]); goto L_800CCF2C; }  /* 0x800CCEE4 j */
    R[2] = 0x8006u << 16;  /* 0x800CCEEC */
    R[3] = lb_(R[2] + 16409);  /* 0x800CCEF0 */
    R[2] = R[0] + 5;  /* 0x800CCEF4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCEF8 */
    R[2] = 0x8014u << 16;  /* 0x800CCF00 */
    R[4] = lw_(R[2] + 14948);  /* 0x800CCF04 */
    R[3] = lh_(R[2] + 14948);  /* 0x800CCF08 */
    R[2] = 0x8006u << 16;  /* 0x800CCF0C */
    { R[31] = 0x800CCF18u; sh_(R[2] + 13234, R[3]); psx_next = 0x800CBD84u; return; }  /* 0x800CCF10 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCF18 */
    R[2] = lw_(R[3] + 14104);  /* 0x800CCF1C */
    R[2] = R[2] | 0x1;  /* 0x800CCF24 */
    sw_(R[3] + 14104, R[2]);  /* 0x800CCF28 */
L_800CCF2C:;
    R[2] = 0x8014u << 16;  /* 0x800CCF2C */
L_800CCF30:;
    R[2] = lw_(R[2] + 14936);  /* 0x800CCF30 */
    R[2] = R[2] & 0x20;  /* 0x800CCF38 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x8013u << 16; if (_c) { goto L_800CCF5C; } }  /* 0x800CCF3C */
    R[2] = 0x8013u << 16;  /* 0x800CCF44 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF48 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF4C */
    { R[31] = 0x800CCF58u; R[5] = R[5] + 512; psx_next = 0x800CBB4Cu; return; }  /* 0x800CCF50 jal */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF58 */
L_800CCF5C:;
    R[16] = 0x8013u << 16;  /* 0x800CCF5C */
    R[2] = 0x8013u << 16;  /* 0x800CCF60 */
    R[3] = 0x8013u << 16;  /* 0x800CCF64 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF68 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF6C */
    R[6] = lw_(R[3] + 14052);  /* 0x800CCF70 */
    { R[31] = 0x800CCF7Cu; R[5] = R[5] + 1792; psx_next = 0x800B673Cu; return; }  /* 0x800CCF74 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCCA8(void) {
    { R[2] = 0x8014u << 16; goto L_800CCF30; }  /* 0x800CCCA8 j */
    R[3] = lw_(R[17] + 14944);  /* 0x800CCCB0 */
    R[2] = R[0] + 3;  /* 0x800CCCB4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[4] & 0x1FF; if (_c) { goto L_800CCD24; } }  /* 0x800CCCB8 */
    R[2] = R[4] & 0xA0;  /* 0x800CCCC0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCCC4 */
    { R[31] = 0x800CCCD4u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x800CCCCC jal */
    R[2] = 0x8014u << 16;  /* 0x800CCCD4 */
    R[3] = R[2] + 14984;  /* 0x800CCCD8 */
    R[5] = R[0] + R[0];  /* 0x800CCCDC */
    R[2] = 0x8014u << 16;  /* 0x800CCCE0 */
    R[4] = R[2] + 14952;  /* 0x800CCCE4 */
L_800CCCE8:;
    R[2] = lh_(R[3]);  /* 0x800CCCE8 */
    R[3] = R[3] + 2;  /* 0x800CCCEC */
    R[5] = R[5] + 1;  /* 0x800CCCF0 */
    sh_(R[4], R[2]);  /* 0x800CCCF4 */
    R[2] = ((int32_t)R[5] < 9);  /* 0x800CCCF8 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[4] + 2; if (_c) { psx_bb(); goto L_800CCCE8; } }  /* 0x800CCCFC */
    R[5] = 0x8014u << 16;  /* 0x800CCD04 */
    R[4] = 0x8013u << 16;  /* 0x800CCD08 */
    R[2] = lw_(R[5] + 14936);  /* 0x800CCD0C */
    R[3] = R[0] + 40;  /* 0x800CCD10 */
    sw_(R[4] + 14084, R[3]);  /* 0x800CCD14 */
    R[2] = R[2] | 0x200;  /* 0x800CCD18 */
    { sw_(R[5] + 14936, R[2]); goto L_800CCF2C; }  /* 0x800CCD1C j */
L_800CCD24:;
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCD24 */
    { R[31] = 0x800CCD34u; R[4] = R[4] & 0xFFFF; psx_next = 0x800CBC58u; return; }  /* 0x800CCD2C jal */
    R[16] = R[2] + R[0];  /* 0x800CCD34 */
    { uint32_t _c = ((int32_t)R[16] < 0); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCD38 */
    { R[31] = 0x800CCD48u; R[4] = R[0] + 6; psx_next = 0x8002DB10u; return; }  /* 0x800CCD40 jal */
    R[5] = R[0] + R[0];  /* 0x800CCD48 */
    R[2] = 0x8014u << 16;  /* 0x800CCD4C */
    R[2] = R[2] + 14984;  /* 0x800CCD50 */
    R[7] = R[2] + R[0];  /* 0x800CCD54 */
    R[6] = R[7] + R[0];  /* 0x800CCD58 */
    R[2] = R[16] << 1;  /* 0x800CCD5C */
    R[2] = R[2] + R[7];  /* 0x800CCD60 */
    R[3] = 0x800Fu << 16;  /* 0x800CCD64 */
    R[3] = R[3] - 676;  /* 0x800CCD68 */
    R[4] = 0x8014u << 16;  /* 0x800CCD6C */
    R[8] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CCD70 */
    R[2] = lw_(R[17] + 14944);  /* 0x800CCD74 */
    R[4] = lw_(R[4] + 14940);  /* 0x800CCD78 */
    R[2] = R[2] << 2;  /* 0x800CCD7C */
    R[2] = R[2] + R[4];  /* 0x800CCD80 */
    R[2] = R[2] << 1;  /* 0x800CCD84 */
    R[2] = R[2] + R[3];  /* 0x800CCD88 */
    R[4] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CCD8C */
L_800CCD90:;
    R[3] = R[6] + R[0];  /* 0x800CCD90 */
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800CCD94 */
    { uint32_t _c = (R[4] == R[2]); R[5] = R[5] + 1; if (_c) { goto L_800CCED8; } }  /* 0x800CCD9C */
    R[2] = ((int32_t)R[5] < 9);  /* 0x800CCDA4 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[3] + 2; if (_c) { psx_bb(); goto L_800CCD90; } }  /* 0x800CCDA8 */
    { R[2] = 0x8014u << 16; goto L_800CCF30; }  /* 0x800CCDB0 j */
    R[16] = 0x8014u << 16;  /* 0x800CCDB8 */
    R[3] = lw_(R[16] + 14936);  /* 0x800CCDBC */
    R[2] = R[3] & 0x400;  /* 0x800CCDC4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCF2C; } }  /* 0x800CCDC8 */
    R[5] = R[4] + R[0];  /* 0x800CCDD0 */
    R[6] = 0x800Fu << 16;  /* 0x800CCDD4 */
    R[6] = R[6] - 1504;  /* 0x800CCDD8 */
    R[17] = 0x8014u << 16;  /* 0x800CCDDC */
    R[2] = R[0] - 1025;  /* 0x800CCDE0 */
    R[2] = R[3] & R[2];  /* 0x800CCDE4 */
    R[3] = ~(R[0] | R[2]);  /* 0x800CCDE8 */
    R[3] = R[3] & 0x10;  /* 0x800CCDEC */
    R[8] = R[0] - 17;  /* 0x800CCDF0 */
    R[2] = R[2] & R[8];  /* 0x800CCDF4 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCDF8 */
    R[2] = R[2] | R[3];  /* 0x800CCDFC */
    { R[31] = 0x800CCE08u; sw_(R[16] + 14936, R[2]); psx_next = 0x800B6CA4u; return; }  /* 0x800CCE00 jal */
    R[2] = lw_(R[16] + 14936);  /* 0x800CCE08 */
    R[2] = R[2] & 0x10;  /* 0x800CCE10 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCE44; } }  /* 0x800CCE14 */
    R[5] = R[4] + R[0];  /* 0x800CCE1C */
    R[6] = 0x800Fu << 16;  /* 0x800CCE20 */
    R[6] = R[6] - 1160;  /* 0x800CCE24 */
    R[2] = 0x8014u << 16;  /* 0x800CCE28 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE2C */
    R[3] = R[0] + 1;  /* 0x800CCE30 */
    sw_(R[2] + 14940, R[3]);  /* 0x800CCE34 */
    R[2] = 0x8014u << 16;  /* 0x800CCE38 */
    { sw_(R[2] + 14944, R[3]); goto L_800CCE6C; }  /* 0x800CCE3C j */
L_800CCE44:;
    R[5] = R[4] + R[0];  /* 0x800CCE44 */
    R[6] = 0x800Fu << 16;  /* 0x800CCE48 */
    R[6] = R[6] - 1060;  /* 0x800CCE4C */
    R[3] = 0x8014u << 16;  /* 0x800CCE50 */
    R[2] = R[0] + 1;  /* 0x800CCE54 */
    sw_(R[3] + 14940, R[2]);  /* 0x800CCE58 */
    R[3] = 0x8014u << 16;  /* 0x800CCE5C */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE60 */
    R[2] = R[0] + 3;  /* 0x800CCE64 */
    sw_(R[3] + 14944, R[2]);  /* 0x800CCE68 */
L_800CCE6C:;
    { R[31] = 0x800CCE74u; psx_next = 0x800B6CA4u; return; }  /* 0x800CCE6C jal */
    { R[3] = 0x8013u << 16; goto L_800CCEC4; }  /* 0x800CCE74 j */
    R[2] = 0x8014u << 16;  /* 0x800CCE7C */
    R[3] = lw_(R[2] + 14936);  /* 0x800CCE80 */
    R[2] = R[3] & 0x100;  /* 0x800CCE88 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x10; if (_c) { goto L_800CCF2C; } }  /* 0x800CCE8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800CCEAC; } }  /* 0x800CCE94 */
    R[3] = 0x8013u << 16;  /* 0x800CCE9C */
    R[2] = R[0] + 10;  /* 0x800CCEA0 */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEA4 j */
L_800CCEAC:;
    R[2] = R[0] + 20;  /* 0x800CCEAC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEB0 j */
    { R[31] = 0x800CCEC0u; R[4] = R[0] + 7; psx_next = 0x8001D930u; return; }  /* 0x800CCEB8 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCEC0 */
L_800CCEC4:;
    R[2] = lw_(R[3] + 14084);  /* 0x800CCEC4 */
    R[2] = R[2] + 1;  /* 0x800CCECC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCED0 j */
L_800CCED8:;
    R[2] = R[16] << 1;  /* 0x800CCED8 */
    R[2] = R[2] + R[7];  /* 0x800CCEDC */
    sh_(R[6], R[8]);  /* 0x800CCEE0 */
    { sh_(R[2], R[4]); goto L_800CCF2C; }  /* 0x800CCEE4 j */
    R[2] = 0x8006u << 16;  /* 0x800CCEEC */
    R[3] = lb_(R[2] + 16409);  /* 0x800CCEF0 */
    R[2] = R[0] + 5;  /* 0x800CCEF4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCEF8 */
    R[2] = 0x8014u << 16;  /* 0x800CCF00 */
    R[4] = lw_(R[2] + 14948);  /* 0x800CCF04 */
    R[3] = lh_(R[2] + 14948);  /* 0x800CCF08 */
    R[2] = 0x8006u << 16;  /* 0x800CCF0C */
    { R[31] = 0x800CCF18u; sh_(R[2] + 13234, R[3]); psx_next = 0x800CBD84u; return; }  /* 0x800CCF10 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCF18 */
    R[2] = lw_(R[3] + 14104);  /* 0x800CCF1C */
    R[2] = R[2] | 0x1;  /* 0x800CCF24 */
    sw_(R[3] + 14104, R[2]);  /* 0x800CCF28 */
L_800CCF2C:;
    R[2] = 0x8014u << 16;  /* 0x800CCF2C */
L_800CCF30:;
    R[2] = lw_(R[2] + 14936);  /* 0x800CCF30 */
    R[2] = R[2] & 0x20;  /* 0x800CCF38 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x8013u << 16; if (_c) { goto L_800CCF5C; } }  /* 0x800CCF3C */
    R[2] = 0x8013u << 16;  /* 0x800CCF44 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF48 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF4C */
    { R[31] = 0x800CCF58u; R[5] = R[5] + 512; psx_next = 0x800CBB4Cu; return; }  /* 0x800CCF50 jal */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF58 */
L_800CCF5C:;
    R[16] = 0x8013u << 16;  /* 0x800CCF5C */
    R[2] = 0x8013u << 16;  /* 0x800CCF60 */
    R[3] = 0x8013u << 16;  /* 0x800CCF64 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF68 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF6C */
    R[6] = lw_(R[3] + 14052);  /* 0x800CCF70 */
    { R[31] = 0x800CCF7Cu; R[5] = R[5] + 1792; psx_next = 0x800B673Cu; return; }  /* 0x800CCF74 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCCD4(void) {
    R[2] = 0x8014u << 16;  /* 0x800CCCD4 */
    R[3] = R[2] + 14984;  /* 0x800CCCD8 */
    R[5] = R[0] + R[0];  /* 0x800CCCDC */
    R[2] = 0x8014u << 16;  /* 0x800CCCE0 */
    R[4] = R[2] + 14952;  /* 0x800CCCE4 */
L_800CCCE8:;
    R[2] = lh_(R[3]);  /* 0x800CCCE8 */
    R[3] = R[3] + 2;  /* 0x800CCCEC */
    R[5] = R[5] + 1;  /* 0x800CCCF0 */
    sh_(R[4], R[2]);  /* 0x800CCCF4 */
    R[2] = ((int32_t)R[5] < 9);  /* 0x800CCCF8 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[4] + 2; if (_c) { psx_bb(); goto L_800CCCE8; } }  /* 0x800CCCFC */
    R[5] = 0x8014u << 16;  /* 0x800CCD04 */
    R[4] = 0x8013u << 16;  /* 0x800CCD08 */
    R[2] = lw_(R[5] + 14936);  /* 0x800CCD0C */
    R[3] = R[0] + 40;  /* 0x800CCD10 */
    sw_(R[4] + 14084, R[3]);  /* 0x800CCD14 */
    R[2] = R[2] | 0x200;  /* 0x800CCD18 */
    { sw_(R[5] + 14936, R[2]); goto L_800CCF2C; }  /* 0x800CCD1C j */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCD24 */
    { R[31] = 0x800CCD34u; R[4] = R[4] & 0xFFFF; psx_next = 0x800CBC58u; return; }  /* 0x800CCD2C jal */
    R[16] = R[2] + R[0];  /* 0x800CCD34 */
    { uint32_t _c = ((int32_t)R[16] < 0); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCD38 */
    { R[31] = 0x800CCD48u; R[4] = R[0] + 6; psx_next = 0x8002DB10u; return; }  /* 0x800CCD40 jal */
    R[5] = R[0] + R[0];  /* 0x800CCD48 */
    R[2] = 0x8014u << 16;  /* 0x800CCD4C */
    R[2] = R[2] + 14984;  /* 0x800CCD50 */
    R[7] = R[2] + R[0];  /* 0x800CCD54 */
    R[6] = R[7] + R[0];  /* 0x800CCD58 */
    R[2] = R[16] << 1;  /* 0x800CCD5C */
    R[2] = R[2] + R[7];  /* 0x800CCD60 */
    R[3] = 0x800Fu << 16;  /* 0x800CCD64 */
    R[3] = R[3] - 676;  /* 0x800CCD68 */
    R[4] = 0x8014u << 16;  /* 0x800CCD6C */
    R[8] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CCD70 */
    R[2] = lw_(R[17] + 14944);  /* 0x800CCD74 */
    R[4] = lw_(R[4] + 14940);  /* 0x800CCD78 */
    R[2] = R[2] << 2;  /* 0x800CCD7C */
    R[2] = R[2] + R[4];  /* 0x800CCD80 */
    R[2] = R[2] << 1;  /* 0x800CCD84 */
    R[2] = R[2] + R[3];  /* 0x800CCD88 */
    R[4] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CCD8C */
L_800CCD90:;
    R[3] = R[6] + R[0];  /* 0x800CCD90 */
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800CCD94 */
    { uint32_t _c = (R[4] == R[2]); R[5] = R[5] + 1; if (_c) { goto L_800CCED8; } }  /* 0x800CCD9C */
    R[2] = ((int32_t)R[5] < 9);  /* 0x800CCDA4 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[3] + 2; if (_c) { psx_bb(); goto L_800CCD90; } }  /* 0x800CCDA8 */
    { R[2] = 0x8014u << 16; goto L_800CCF30; }  /* 0x800CCDB0 j */
    R[16] = 0x8014u << 16;  /* 0x800CCDB8 */
    R[3] = lw_(R[16] + 14936);  /* 0x800CCDBC */
    R[2] = R[3] & 0x400;  /* 0x800CCDC4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCF2C; } }  /* 0x800CCDC8 */
    R[5] = R[4] + R[0];  /* 0x800CCDD0 */
    R[6] = 0x800Fu << 16;  /* 0x800CCDD4 */
    R[6] = R[6] - 1504;  /* 0x800CCDD8 */
    R[17] = 0x8014u << 16;  /* 0x800CCDDC */
    R[2] = R[0] - 1025;  /* 0x800CCDE0 */
    R[2] = R[3] & R[2];  /* 0x800CCDE4 */
    R[3] = ~(R[0] | R[2]);  /* 0x800CCDE8 */
    R[3] = R[3] & 0x10;  /* 0x800CCDEC */
    R[8] = R[0] - 17;  /* 0x800CCDF0 */
    R[2] = R[2] & R[8];  /* 0x800CCDF4 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCDF8 */
    R[2] = R[2] | R[3];  /* 0x800CCDFC */
    { R[31] = 0x800CCE08u; sw_(R[16] + 14936, R[2]); psx_next = 0x800B6CA4u; return; }  /* 0x800CCE00 jal */
    R[2] = lw_(R[16] + 14936);  /* 0x800CCE08 */
    R[2] = R[2] & 0x10;  /* 0x800CCE10 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCE44; } }  /* 0x800CCE14 */
    R[5] = R[4] + R[0];  /* 0x800CCE1C */
    R[6] = 0x800Fu << 16;  /* 0x800CCE20 */
    R[6] = R[6] - 1160;  /* 0x800CCE24 */
    R[2] = 0x8014u << 16;  /* 0x800CCE28 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE2C */
    R[3] = R[0] + 1;  /* 0x800CCE30 */
    sw_(R[2] + 14940, R[3]);  /* 0x800CCE34 */
    R[2] = 0x8014u << 16;  /* 0x800CCE38 */
    { sw_(R[2] + 14944, R[3]); goto L_800CCE6C; }  /* 0x800CCE3C j */
L_800CCE44:;
    R[5] = R[4] + R[0];  /* 0x800CCE44 */
    R[6] = 0x800Fu << 16;  /* 0x800CCE48 */
    R[6] = R[6] - 1060;  /* 0x800CCE4C */
    R[3] = 0x8014u << 16;  /* 0x800CCE50 */
    R[2] = R[0] + 1;  /* 0x800CCE54 */
    sw_(R[3] + 14940, R[2]);  /* 0x800CCE58 */
    R[3] = 0x8014u << 16;  /* 0x800CCE5C */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE60 */
    R[2] = R[0] + 3;  /* 0x800CCE64 */
    sw_(R[3] + 14944, R[2]);  /* 0x800CCE68 */
L_800CCE6C:;
    { R[31] = 0x800CCE74u; psx_next = 0x800B6CA4u; return; }  /* 0x800CCE6C jal */
    { R[3] = 0x8013u << 16; goto L_800CCEC4; }  /* 0x800CCE74 j */
    R[2] = 0x8014u << 16;  /* 0x800CCE7C */
    R[3] = lw_(R[2] + 14936);  /* 0x800CCE80 */
    R[2] = R[3] & 0x100;  /* 0x800CCE88 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x10; if (_c) { goto L_800CCF2C; } }  /* 0x800CCE8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800CCEAC; } }  /* 0x800CCE94 */
    R[3] = 0x8013u << 16;  /* 0x800CCE9C */
    R[2] = R[0] + 10;  /* 0x800CCEA0 */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEA4 j */
L_800CCEAC:;
    R[2] = R[0] + 20;  /* 0x800CCEAC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEB0 j */
    { R[31] = 0x800CCEC0u; R[4] = R[0] + 7; psx_next = 0x8001D930u; return; }  /* 0x800CCEB8 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCEC0 */
L_800CCEC4:;
    R[2] = lw_(R[3] + 14084);  /* 0x800CCEC4 */
    R[2] = R[2] + 1;  /* 0x800CCECC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCED0 j */
L_800CCED8:;
    R[2] = R[16] << 1;  /* 0x800CCED8 */
    R[2] = R[2] + R[7];  /* 0x800CCEDC */
    sh_(R[6], R[8]);  /* 0x800CCEE0 */
    { sh_(R[2], R[4]); goto L_800CCF2C; }  /* 0x800CCEE4 j */
    R[2] = 0x8006u << 16;  /* 0x800CCEEC */
    R[3] = lb_(R[2] + 16409);  /* 0x800CCEF0 */
    R[2] = R[0] + 5;  /* 0x800CCEF4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCEF8 */
    R[2] = 0x8014u << 16;  /* 0x800CCF00 */
    R[4] = lw_(R[2] + 14948);  /* 0x800CCF04 */
    R[3] = lh_(R[2] + 14948);  /* 0x800CCF08 */
    R[2] = 0x8006u << 16;  /* 0x800CCF0C */
    { R[31] = 0x800CCF18u; sh_(R[2] + 13234, R[3]); psx_next = 0x800CBD84u; return; }  /* 0x800CCF10 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCF18 */
    R[2] = lw_(R[3] + 14104);  /* 0x800CCF1C */
    R[2] = R[2] | 0x1;  /* 0x800CCF24 */
    sw_(R[3] + 14104, R[2]);  /* 0x800CCF28 */
L_800CCF2C:;
    R[2] = 0x8014u << 16;  /* 0x800CCF2C */
L_800CCF30:;
    R[2] = lw_(R[2] + 14936);  /* 0x800CCF30 */
    R[2] = R[2] & 0x20;  /* 0x800CCF38 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x8013u << 16; if (_c) { goto L_800CCF5C; } }  /* 0x800CCF3C */
    R[2] = 0x8013u << 16;  /* 0x800CCF44 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF48 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF4C */
    { R[31] = 0x800CCF58u; R[5] = R[5] + 512; psx_next = 0x800CBB4Cu; return; }  /* 0x800CCF50 jal */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF58 */
L_800CCF5C:;
    R[16] = 0x8013u << 16;  /* 0x800CCF5C */
    R[2] = 0x8013u << 16;  /* 0x800CCF60 */
    R[3] = 0x8013u << 16;  /* 0x800CCF64 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF68 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF6C */
    R[6] = lw_(R[3] + 14052);  /* 0x800CCF70 */
    { R[31] = 0x800CCF7Cu; R[5] = R[5] + 1792; psx_next = 0x800B673Cu; return; }  /* 0x800CCF74 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCD34(void) {
    R[16] = R[2] + R[0];  /* 0x800CCD34 */
    { uint32_t _c = ((int32_t)R[16] < 0); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCD38 */
    { R[31] = 0x800CCD48u; R[4] = R[0] + 6; psx_next = 0x8002DB10u; return; }  /* 0x800CCD40 jal */
    R[5] = R[0] + R[0];  /* 0x800CCD48 */
    R[2] = 0x8014u << 16;  /* 0x800CCD4C */
    R[2] = R[2] + 14984;  /* 0x800CCD50 */
    R[7] = R[2] + R[0];  /* 0x800CCD54 */
    R[6] = R[7] + R[0];  /* 0x800CCD58 */
    R[2] = R[16] << 1;  /* 0x800CCD5C */
    R[2] = R[2] + R[7];  /* 0x800CCD60 */
    R[3] = 0x800Fu << 16;  /* 0x800CCD64 */
    R[3] = R[3] - 676;  /* 0x800CCD68 */
    R[4] = 0x8014u << 16;  /* 0x800CCD6C */
    R[8] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CCD70 */
    R[2] = lw_(R[17] + 14944);  /* 0x800CCD74 */
    R[4] = lw_(R[4] + 14940);  /* 0x800CCD78 */
    R[2] = R[2] << 2;  /* 0x800CCD7C */
    R[2] = R[2] + R[4];  /* 0x800CCD80 */
    R[2] = R[2] << 1;  /* 0x800CCD84 */
    R[2] = R[2] + R[3];  /* 0x800CCD88 */
    R[4] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CCD8C */
L_800CCD90:;
    R[3] = R[6] + R[0];  /* 0x800CCD90 */
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800CCD94 */
    { uint32_t _c = (R[4] == R[2]); R[5] = R[5] + 1; if (_c) { goto L_800CCED8; } }  /* 0x800CCD9C */
    R[2] = ((int32_t)R[5] < 9);  /* 0x800CCDA4 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[3] + 2; if (_c) { psx_bb(); goto L_800CCD90; } }  /* 0x800CCDA8 */
    { R[2] = 0x8014u << 16; goto L_800CCF30; }  /* 0x800CCDB0 j */
    R[16] = 0x8014u << 16;  /* 0x800CCDB8 */
    R[3] = lw_(R[16] + 14936);  /* 0x800CCDBC */
    R[2] = R[3] & 0x400;  /* 0x800CCDC4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCF2C; } }  /* 0x800CCDC8 */
    R[5] = R[4] + R[0];  /* 0x800CCDD0 */
    R[6] = 0x800Fu << 16;  /* 0x800CCDD4 */
    R[6] = R[6] - 1504;  /* 0x800CCDD8 */
    R[17] = 0x8014u << 16;  /* 0x800CCDDC */
    R[2] = R[0] - 1025;  /* 0x800CCDE0 */
    R[2] = R[3] & R[2];  /* 0x800CCDE4 */
    R[3] = ~(R[0] | R[2]);  /* 0x800CCDE8 */
    R[3] = R[3] & 0x10;  /* 0x800CCDEC */
    R[8] = R[0] - 17;  /* 0x800CCDF0 */
    R[2] = R[2] & R[8];  /* 0x800CCDF4 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCDF8 */
    R[2] = R[2] | R[3];  /* 0x800CCDFC */
    { R[31] = 0x800CCE08u; sw_(R[16] + 14936, R[2]); psx_next = 0x800B6CA4u; return; }  /* 0x800CCE00 jal */
    R[2] = lw_(R[16] + 14936);  /* 0x800CCE08 */
    R[2] = R[2] & 0x10;  /* 0x800CCE10 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCE44; } }  /* 0x800CCE14 */
    R[5] = R[4] + R[0];  /* 0x800CCE1C */
    R[6] = 0x800Fu << 16;  /* 0x800CCE20 */
    R[6] = R[6] - 1160;  /* 0x800CCE24 */
    R[2] = 0x8014u << 16;  /* 0x800CCE28 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE2C */
    R[3] = R[0] + 1;  /* 0x800CCE30 */
    sw_(R[2] + 14940, R[3]);  /* 0x800CCE34 */
    R[2] = 0x8014u << 16;  /* 0x800CCE38 */
    { sw_(R[2] + 14944, R[3]); goto L_800CCE6C; }  /* 0x800CCE3C j */
L_800CCE44:;
    R[5] = R[4] + R[0];  /* 0x800CCE44 */
    R[6] = 0x800Fu << 16;  /* 0x800CCE48 */
    R[6] = R[6] - 1060;  /* 0x800CCE4C */
    R[3] = 0x8014u << 16;  /* 0x800CCE50 */
    R[2] = R[0] + 1;  /* 0x800CCE54 */
    sw_(R[3] + 14940, R[2]);  /* 0x800CCE58 */
    R[3] = 0x8014u << 16;  /* 0x800CCE5C */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE60 */
    R[2] = R[0] + 3;  /* 0x800CCE64 */
    sw_(R[3] + 14944, R[2]);  /* 0x800CCE68 */
L_800CCE6C:;
    { R[31] = 0x800CCE74u; psx_next = 0x800B6CA4u; return; }  /* 0x800CCE6C jal */
    { R[3] = 0x8013u << 16; goto L_800CCEC4; }  /* 0x800CCE74 j */
    R[2] = 0x8014u << 16;  /* 0x800CCE7C */
    R[3] = lw_(R[2] + 14936);  /* 0x800CCE80 */
    R[2] = R[3] & 0x100;  /* 0x800CCE88 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x10; if (_c) { goto L_800CCF2C; } }  /* 0x800CCE8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800CCEAC; } }  /* 0x800CCE94 */
    R[3] = 0x8013u << 16;  /* 0x800CCE9C */
    R[2] = R[0] + 10;  /* 0x800CCEA0 */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEA4 j */
L_800CCEAC:;
    R[2] = R[0] + 20;  /* 0x800CCEAC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEB0 j */
    { R[31] = 0x800CCEC0u; R[4] = R[0] + 7; psx_next = 0x8001D930u; return; }  /* 0x800CCEB8 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCEC0 */
L_800CCEC4:;
    R[2] = lw_(R[3] + 14084);  /* 0x800CCEC4 */
    R[2] = R[2] + 1;  /* 0x800CCECC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCED0 j */
L_800CCED8:;
    R[2] = R[16] << 1;  /* 0x800CCED8 */
    R[2] = R[2] + R[7];  /* 0x800CCEDC */
    sh_(R[6], R[8]);  /* 0x800CCEE0 */
    { sh_(R[2], R[4]); goto L_800CCF2C; }  /* 0x800CCEE4 j */
    R[2] = 0x8006u << 16;  /* 0x800CCEEC */
    R[3] = lb_(R[2] + 16409);  /* 0x800CCEF0 */
    R[2] = R[0] + 5;  /* 0x800CCEF4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCEF8 */
    R[2] = 0x8014u << 16;  /* 0x800CCF00 */
    R[4] = lw_(R[2] + 14948);  /* 0x800CCF04 */
    R[3] = lh_(R[2] + 14948);  /* 0x800CCF08 */
    R[2] = 0x8006u << 16;  /* 0x800CCF0C */
    { R[31] = 0x800CCF18u; sh_(R[2] + 13234, R[3]); psx_next = 0x800CBD84u; return; }  /* 0x800CCF10 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCF18 */
    R[2] = lw_(R[3] + 14104);  /* 0x800CCF1C */
    R[2] = R[2] | 0x1;  /* 0x800CCF24 */
    sw_(R[3] + 14104, R[2]);  /* 0x800CCF28 */
L_800CCF2C:;
    R[2] = 0x8014u << 16;  /* 0x800CCF2C */
L_800CCF30:;
    R[2] = lw_(R[2] + 14936);  /* 0x800CCF30 */
    R[2] = R[2] & 0x20;  /* 0x800CCF38 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x8013u << 16; if (_c) { goto L_800CCF5C; } }  /* 0x800CCF3C */
    R[2] = 0x8013u << 16;  /* 0x800CCF44 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF48 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF4C */
    { R[31] = 0x800CCF58u; R[5] = R[5] + 512; psx_next = 0x800CBB4Cu; return; }  /* 0x800CCF50 jal */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF58 */
L_800CCF5C:;
    R[16] = 0x8013u << 16;  /* 0x800CCF5C */
    R[2] = 0x8013u << 16;  /* 0x800CCF60 */
    R[3] = 0x8013u << 16;  /* 0x800CCF64 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF68 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF6C */
    R[6] = lw_(R[3] + 14052);  /* 0x800CCF70 */
    { R[31] = 0x800CCF7Cu; R[5] = R[5] + 1792; psx_next = 0x800B673Cu; return; }  /* 0x800CCF74 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCD48(void) {
    R[5] = R[0] + R[0];  /* 0x800CCD48 */
    R[2] = 0x8014u << 16;  /* 0x800CCD4C */
    R[2] = R[2] + 14984;  /* 0x800CCD50 */
    R[7] = R[2] + R[0];  /* 0x800CCD54 */
    R[6] = R[7] + R[0];  /* 0x800CCD58 */
    R[2] = R[16] << 1;  /* 0x800CCD5C */
    R[2] = R[2] + R[7];  /* 0x800CCD60 */
    R[3] = 0x800Fu << 16;  /* 0x800CCD64 */
    R[3] = R[3] - 676;  /* 0x800CCD68 */
    R[4] = 0x8014u << 16;  /* 0x800CCD6C */
    R[8] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CCD70 */
    R[2] = lw_(R[17] + 14944);  /* 0x800CCD74 */
    R[4] = lw_(R[4] + 14940);  /* 0x800CCD78 */
    R[2] = R[2] << 2;  /* 0x800CCD7C */
    R[2] = R[2] + R[4];  /* 0x800CCD80 */
    R[2] = R[2] << 1;  /* 0x800CCD84 */
    R[2] = R[2] + R[3];  /* 0x800CCD88 */
    R[4] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CCD8C */
L_800CCD90:;
    R[3] = R[6] + R[0];  /* 0x800CCD90 */
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800CCD94 */
    { uint32_t _c = (R[4] == R[2]); R[5] = R[5] + 1; if (_c) { goto L_800CCED8; } }  /* 0x800CCD9C */
    R[2] = ((int32_t)R[5] < 9);  /* 0x800CCDA4 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[3] + 2; if (_c) { psx_bb(); goto L_800CCD90; } }  /* 0x800CCDA8 */
    { R[2] = 0x8014u << 16; goto L_800CCF30; }  /* 0x800CCDB0 j */
    R[16] = 0x8014u << 16;  /* 0x800CCDB8 */
    R[3] = lw_(R[16] + 14936);  /* 0x800CCDBC */
    R[2] = R[3] & 0x400;  /* 0x800CCDC4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCF2C; } }  /* 0x800CCDC8 */
    R[5] = R[4] + R[0];  /* 0x800CCDD0 */
    R[6] = 0x800Fu << 16;  /* 0x800CCDD4 */
    R[6] = R[6] - 1504;  /* 0x800CCDD8 */
    R[17] = 0x8014u << 16;  /* 0x800CCDDC */
    R[2] = R[0] - 1025;  /* 0x800CCDE0 */
    R[2] = R[3] & R[2];  /* 0x800CCDE4 */
    R[3] = ~(R[0] | R[2]);  /* 0x800CCDE8 */
    R[3] = R[3] & 0x10;  /* 0x800CCDEC */
    R[8] = R[0] - 17;  /* 0x800CCDF0 */
    R[2] = R[2] & R[8];  /* 0x800CCDF4 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCDF8 */
    R[2] = R[2] | R[3];  /* 0x800CCDFC */
    { R[31] = 0x800CCE08u; sw_(R[16] + 14936, R[2]); psx_next = 0x800B6CA4u; return; }  /* 0x800CCE00 jal */
    R[2] = lw_(R[16] + 14936);  /* 0x800CCE08 */
    R[2] = R[2] & 0x10;  /* 0x800CCE10 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCE44; } }  /* 0x800CCE14 */
    R[5] = R[4] + R[0];  /* 0x800CCE1C */
    R[6] = 0x800Fu << 16;  /* 0x800CCE20 */
    R[6] = R[6] - 1160;  /* 0x800CCE24 */
    R[2] = 0x8014u << 16;  /* 0x800CCE28 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE2C */
    R[3] = R[0] + 1;  /* 0x800CCE30 */
    sw_(R[2] + 14940, R[3]);  /* 0x800CCE34 */
    R[2] = 0x8014u << 16;  /* 0x800CCE38 */
    { sw_(R[2] + 14944, R[3]); goto L_800CCE6C; }  /* 0x800CCE3C j */
L_800CCE44:;
    R[5] = R[4] + R[0];  /* 0x800CCE44 */
    R[6] = 0x800Fu << 16;  /* 0x800CCE48 */
    R[6] = R[6] - 1060;  /* 0x800CCE4C */
    R[3] = 0x8014u << 16;  /* 0x800CCE50 */
    R[2] = R[0] + 1;  /* 0x800CCE54 */
    sw_(R[3] + 14940, R[2]);  /* 0x800CCE58 */
    R[3] = 0x8014u << 16;  /* 0x800CCE5C */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE60 */
    R[2] = R[0] + 3;  /* 0x800CCE64 */
    sw_(R[3] + 14944, R[2]);  /* 0x800CCE68 */
L_800CCE6C:;
    { R[31] = 0x800CCE74u; psx_next = 0x800B6CA4u; return; }  /* 0x800CCE6C jal */
    { R[3] = 0x8013u << 16; goto L_800CCEC4; }  /* 0x800CCE74 j */
    R[2] = 0x8014u << 16;  /* 0x800CCE7C */
    R[3] = lw_(R[2] + 14936);  /* 0x800CCE80 */
    R[2] = R[3] & 0x100;  /* 0x800CCE88 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x10; if (_c) { goto L_800CCF2C; } }  /* 0x800CCE8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800CCEAC; } }  /* 0x800CCE94 */
    R[3] = 0x8013u << 16;  /* 0x800CCE9C */
    R[2] = R[0] + 10;  /* 0x800CCEA0 */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEA4 j */
L_800CCEAC:;
    R[2] = R[0] + 20;  /* 0x800CCEAC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEB0 j */
    { R[31] = 0x800CCEC0u; R[4] = R[0] + 7; psx_next = 0x8001D930u; return; }  /* 0x800CCEB8 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCEC0 */
L_800CCEC4:;
    R[2] = lw_(R[3] + 14084);  /* 0x800CCEC4 */
    R[2] = R[2] + 1;  /* 0x800CCECC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCED0 j */
L_800CCED8:;
    R[2] = R[16] << 1;  /* 0x800CCED8 */
    R[2] = R[2] + R[7];  /* 0x800CCEDC */
    sh_(R[6], R[8]);  /* 0x800CCEE0 */
    { sh_(R[2], R[4]); goto L_800CCF2C; }  /* 0x800CCEE4 j */
    R[2] = 0x8006u << 16;  /* 0x800CCEEC */
    R[3] = lb_(R[2] + 16409);  /* 0x800CCEF0 */
    R[2] = R[0] + 5;  /* 0x800CCEF4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCEF8 */
    R[2] = 0x8014u << 16;  /* 0x800CCF00 */
    R[4] = lw_(R[2] + 14948);  /* 0x800CCF04 */
    R[3] = lh_(R[2] + 14948);  /* 0x800CCF08 */
    R[2] = 0x8006u << 16;  /* 0x800CCF0C */
    { R[31] = 0x800CCF18u; sh_(R[2] + 13234, R[3]); psx_next = 0x800CBD84u; return; }  /* 0x800CCF10 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCF18 */
    R[2] = lw_(R[3] + 14104);  /* 0x800CCF1C */
    R[2] = R[2] | 0x1;  /* 0x800CCF24 */
    sw_(R[3] + 14104, R[2]);  /* 0x800CCF28 */
L_800CCF2C:;
    R[2] = 0x8014u << 16;  /* 0x800CCF2C */
L_800CCF30:;
    R[2] = lw_(R[2] + 14936);  /* 0x800CCF30 */
    R[2] = R[2] & 0x20;  /* 0x800CCF38 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x8013u << 16; if (_c) { goto L_800CCF5C; } }  /* 0x800CCF3C */
    R[2] = 0x8013u << 16;  /* 0x800CCF44 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF48 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF4C */
    { R[31] = 0x800CCF58u; R[5] = R[5] + 512; psx_next = 0x800CBB4Cu; return; }  /* 0x800CCF50 jal */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF58 */
L_800CCF5C:;
    R[16] = 0x8013u << 16;  /* 0x800CCF5C */
    R[2] = 0x8013u << 16;  /* 0x800CCF60 */
    R[3] = 0x8013u << 16;  /* 0x800CCF64 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF68 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF6C */
    R[6] = lw_(R[3] + 14052);  /* 0x800CCF70 */
    { R[31] = 0x800CCF7Cu; R[5] = R[5] + 1792; psx_next = 0x800B673Cu; return; }  /* 0x800CCF74 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCDB8(void) {
    R[16] = 0x8014u << 16;  /* 0x800CCDB8 */
    R[3] = lw_(R[16] + 14936);  /* 0x800CCDBC */
    R[2] = R[3] & 0x400;  /* 0x800CCDC4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCF2C; } }  /* 0x800CCDC8 */
    R[5] = R[4] + R[0];  /* 0x800CCDD0 */
    R[6] = 0x800Fu << 16;  /* 0x800CCDD4 */
    R[6] = R[6] - 1504;  /* 0x800CCDD8 */
    R[17] = 0x8014u << 16;  /* 0x800CCDDC */
    R[2] = R[0] - 1025;  /* 0x800CCDE0 */
    R[2] = R[3] & R[2];  /* 0x800CCDE4 */
    R[3] = ~(R[0] | R[2]);  /* 0x800CCDE8 */
    R[3] = R[3] & 0x10;  /* 0x800CCDEC */
    R[8] = R[0] - 17;  /* 0x800CCDF0 */
    R[2] = R[2] & R[8];  /* 0x800CCDF4 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCDF8 */
    R[2] = R[2] | R[3];  /* 0x800CCDFC */
    { R[31] = 0x800CCE08u; sw_(R[16] + 14936, R[2]); psx_next = 0x800B6CA4u; return; }  /* 0x800CCE00 jal */
    R[2] = lw_(R[16] + 14936);  /* 0x800CCE08 */
    R[2] = R[2] & 0x10;  /* 0x800CCE10 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCE44; } }  /* 0x800CCE14 */
    R[5] = R[4] + R[0];  /* 0x800CCE1C */
    R[6] = 0x800Fu << 16;  /* 0x800CCE20 */
    R[6] = R[6] - 1160;  /* 0x800CCE24 */
    R[2] = 0x8014u << 16;  /* 0x800CCE28 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE2C */
    R[3] = R[0] + 1;  /* 0x800CCE30 */
    sw_(R[2] + 14940, R[3]);  /* 0x800CCE34 */
    R[2] = 0x8014u << 16;  /* 0x800CCE38 */
    { sw_(R[2] + 14944, R[3]); goto L_800CCE6C; }  /* 0x800CCE3C j */
L_800CCE44:;
    R[5] = R[4] + R[0];  /* 0x800CCE44 */
    R[6] = 0x800Fu << 16;  /* 0x800CCE48 */
    R[6] = R[6] - 1060;  /* 0x800CCE4C */
    R[3] = 0x8014u << 16;  /* 0x800CCE50 */
    R[2] = R[0] + 1;  /* 0x800CCE54 */
    sw_(R[3] + 14940, R[2]);  /* 0x800CCE58 */
    R[3] = 0x8014u << 16;  /* 0x800CCE5C */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE60 */
    R[2] = R[0] + 3;  /* 0x800CCE64 */
    sw_(R[3] + 14944, R[2]);  /* 0x800CCE68 */
L_800CCE6C:;
    { R[31] = 0x800CCE74u; psx_next = 0x800B6CA4u; return; }  /* 0x800CCE6C jal */
    { R[3] = 0x8013u << 16; goto L_800CCEC4; }  /* 0x800CCE74 j */
    R[2] = 0x8014u << 16;  /* 0x800CCE7C */
    R[3] = lw_(R[2] + 14936);  /* 0x800CCE80 */
    R[2] = R[3] & 0x100;  /* 0x800CCE88 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x10; if (_c) { goto L_800CCF2C; } }  /* 0x800CCE8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800CCEAC; } }  /* 0x800CCE94 */
    R[3] = 0x8013u << 16;  /* 0x800CCE9C */
    R[2] = R[0] + 10;  /* 0x800CCEA0 */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEA4 j */
L_800CCEAC:;
    R[2] = R[0] + 20;  /* 0x800CCEAC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEB0 j */
    { R[31] = 0x800CCEC0u; R[4] = R[0] + 7; psx_next = 0x8001D930u; return; }  /* 0x800CCEB8 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCEC0 */
L_800CCEC4:;
    R[2] = lw_(R[3] + 14084);  /* 0x800CCEC4 */
    R[2] = R[2] + 1;  /* 0x800CCECC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCED0 j */
    R[2] = R[16] << 1;  /* 0x800CCED8 */
    R[2] = R[2] + R[7];  /* 0x800CCEDC */
    sh_(R[6], R[8]);  /* 0x800CCEE0 */
    { sh_(R[2], R[4]); goto L_800CCF2C; }  /* 0x800CCEE4 j */
    R[2] = 0x8006u << 16;  /* 0x800CCEEC */
    R[3] = lb_(R[2] + 16409);  /* 0x800CCEF0 */
    R[2] = R[0] + 5;  /* 0x800CCEF4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCEF8 */
    R[2] = 0x8014u << 16;  /* 0x800CCF00 */
    R[4] = lw_(R[2] + 14948);  /* 0x800CCF04 */
    R[3] = lh_(R[2] + 14948);  /* 0x800CCF08 */
    R[2] = 0x8006u << 16;  /* 0x800CCF0C */
    { R[31] = 0x800CCF18u; sh_(R[2] + 13234, R[3]); psx_next = 0x800CBD84u; return; }  /* 0x800CCF10 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCF18 */
    R[2] = lw_(R[3] + 14104);  /* 0x800CCF1C */
    R[2] = R[2] | 0x1;  /* 0x800CCF24 */
    sw_(R[3] + 14104, R[2]);  /* 0x800CCF28 */
L_800CCF2C:;
    R[2] = 0x8014u << 16;  /* 0x800CCF2C */
L_800CCF30:;
    R[2] = lw_(R[2] + 14936);  /* 0x800CCF30 */
    R[2] = R[2] & 0x20;  /* 0x800CCF38 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x8013u << 16; if (_c) { goto L_800CCF5C; } }  /* 0x800CCF3C */
    R[2] = 0x8013u << 16;  /* 0x800CCF44 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF48 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF4C */
    { R[31] = 0x800CCF58u; R[5] = R[5] + 512; psx_next = 0x800CBB4Cu; return; }  /* 0x800CCF50 jal */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF58 */
L_800CCF5C:;
    R[16] = 0x8013u << 16;  /* 0x800CCF5C */
    R[2] = 0x8013u << 16;  /* 0x800CCF60 */
    R[3] = 0x8013u << 16;  /* 0x800CCF64 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF68 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF6C */
    R[6] = lw_(R[3] + 14052);  /* 0x800CCF70 */
    { R[31] = 0x800CCF7Cu; R[5] = R[5] + 1792; psx_next = 0x800B673Cu; return; }  /* 0x800CCF74 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCE08(void) {
    R[2] = lw_(R[16] + 14936);  /* 0x800CCE08 */
    R[2] = R[2] & 0x10;  /* 0x800CCE10 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_800CCE44; } }  /* 0x800CCE14 */
    R[5] = R[4] + R[0];  /* 0x800CCE1C */
    R[6] = 0x800Fu << 16;  /* 0x800CCE20 */
    R[6] = R[6] - 1160;  /* 0x800CCE24 */
    R[2] = 0x8014u << 16;  /* 0x800CCE28 */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE2C */
    R[3] = R[0] + 1;  /* 0x800CCE30 */
    sw_(R[2] + 14940, R[3]);  /* 0x800CCE34 */
    R[2] = 0x8014u << 16;  /* 0x800CCE38 */
    { sw_(R[2] + 14944, R[3]); goto L_800CCE6C; }  /* 0x800CCE3C j */
L_800CCE44:;
    R[5] = R[4] + R[0];  /* 0x800CCE44 */
    R[6] = 0x800Fu << 16;  /* 0x800CCE48 */
    R[6] = R[6] - 1060;  /* 0x800CCE4C */
    R[3] = 0x8014u << 16;  /* 0x800CCE50 */
    R[2] = R[0] + 1;  /* 0x800CCE54 */
    sw_(R[3] + 14940, R[2]);  /* 0x800CCE58 */
    R[3] = 0x8014u << 16;  /* 0x800CCE5C */
    R[7] = lw_(R[17] + 14672);  /* 0x800CCE60 */
    R[2] = R[0] + 3;  /* 0x800CCE64 */
    sw_(R[3] + 14944, R[2]);  /* 0x800CCE68 */
L_800CCE6C:;
    { R[31] = 0x800CCE74u; psx_next = 0x800B6CA4u; return; }  /* 0x800CCE6C jal */
    { R[3] = 0x8013u << 16; goto L_800CCEC4; }  /* 0x800CCE74 j */
    R[2] = 0x8014u << 16;  /* 0x800CCE7C */
    R[3] = lw_(R[2] + 14936);  /* 0x800CCE80 */
    R[2] = R[3] & 0x100;  /* 0x800CCE88 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x10; if (_c) { goto L_800CCF2C; } }  /* 0x800CCE8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800CCEAC; } }  /* 0x800CCE94 */
    R[3] = 0x8013u << 16;  /* 0x800CCE9C */
    R[2] = R[0] + 10;  /* 0x800CCEA0 */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEA4 j */
L_800CCEAC:;
    R[2] = R[0] + 20;  /* 0x800CCEAC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEB0 j */
    { R[31] = 0x800CCEC0u; R[4] = R[0] + 7; psx_next = 0x8001D930u; return; }  /* 0x800CCEB8 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCEC0 */
L_800CCEC4:;
    R[2] = lw_(R[3] + 14084);  /* 0x800CCEC4 */
    R[2] = R[2] + 1;  /* 0x800CCECC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCED0 j */
    R[2] = R[16] << 1;  /* 0x800CCED8 */
    R[2] = R[2] + R[7];  /* 0x800CCEDC */
    sh_(R[6], R[8]);  /* 0x800CCEE0 */
    { sh_(R[2], R[4]); goto L_800CCF2C; }  /* 0x800CCEE4 j */
    R[2] = 0x8006u << 16;  /* 0x800CCEEC */
    R[3] = lb_(R[2] + 16409);  /* 0x800CCEF0 */
    R[2] = R[0] + 5;  /* 0x800CCEF4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCEF8 */
    R[2] = 0x8014u << 16;  /* 0x800CCF00 */
    R[4] = lw_(R[2] + 14948);  /* 0x800CCF04 */
    R[3] = lh_(R[2] + 14948);  /* 0x800CCF08 */
    R[2] = 0x8006u << 16;  /* 0x800CCF0C */
    { R[31] = 0x800CCF18u; sh_(R[2] + 13234, R[3]); psx_next = 0x800CBD84u; return; }  /* 0x800CCF10 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCF18 */
    R[2] = lw_(R[3] + 14104);  /* 0x800CCF1C */
    R[2] = R[2] | 0x1;  /* 0x800CCF24 */
    sw_(R[3] + 14104, R[2]);  /* 0x800CCF28 */
L_800CCF2C:;
    R[2] = 0x8014u << 16;  /* 0x800CCF2C */
L_800CCF30:;
    R[2] = lw_(R[2] + 14936);  /* 0x800CCF30 */
    R[2] = R[2] & 0x20;  /* 0x800CCF38 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x8013u << 16; if (_c) { goto L_800CCF5C; } }  /* 0x800CCF3C */
    R[2] = 0x8013u << 16;  /* 0x800CCF44 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF48 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF4C */
    { R[31] = 0x800CCF58u; R[5] = R[5] + 512; psx_next = 0x800CBB4Cu; return; }  /* 0x800CCF50 jal */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF58 */
L_800CCF5C:;
    R[16] = 0x8013u << 16;  /* 0x800CCF5C */
    R[2] = 0x8013u << 16;  /* 0x800CCF60 */
    R[3] = 0x8013u << 16;  /* 0x800CCF64 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF68 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF6C */
    R[6] = lw_(R[3] + 14052);  /* 0x800CCF70 */
    { R[31] = 0x800CCF7Cu; R[5] = R[5] + 1792; psx_next = 0x800B673Cu; return; }  /* 0x800CCF74 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCE74(void) {
    { R[3] = 0x8013u << 16; goto L_800CCEC4; }  /* 0x800CCE74 j */
    R[2] = 0x8014u << 16;  /* 0x800CCE7C */
    R[3] = lw_(R[2] + 14936);  /* 0x800CCE80 */
    R[2] = R[3] & 0x100;  /* 0x800CCE88 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x10; if (_c) { goto L_800CCF2C; } }  /* 0x800CCE8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800CCEAC; } }  /* 0x800CCE94 */
    R[3] = 0x8013u << 16;  /* 0x800CCE9C */
    R[2] = R[0] + 10;  /* 0x800CCEA0 */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEA4 j */
L_800CCEAC:;
    R[2] = R[0] + 20;  /* 0x800CCEAC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEB0 j */
    { R[31] = 0x800CCEC0u; R[4] = R[0] + 7; psx_next = 0x8001D930u; return; }  /* 0x800CCEB8 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCEC0 */
L_800CCEC4:;
    R[2] = lw_(R[3] + 14084);  /* 0x800CCEC4 */
    R[2] = R[2] + 1;  /* 0x800CCECC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCED0 j */
    R[2] = R[16] << 1;  /* 0x800CCED8 */
    R[2] = R[2] + R[7];  /* 0x800CCEDC */
    sh_(R[6], R[8]);  /* 0x800CCEE0 */
    { sh_(R[2], R[4]); goto L_800CCF2C; }  /* 0x800CCEE4 j */
    R[2] = 0x8006u << 16;  /* 0x800CCEEC */
    R[3] = lb_(R[2] + 16409);  /* 0x800CCEF0 */
    R[2] = R[0] + 5;  /* 0x800CCEF4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCEF8 */
    R[2] = 0x8014u << 16;  /* 0x800CCF00 */
    R[4] = lw_(R[2] + 14948);  /* 0x800CCF04 */
    R[3] = lh_(R[2] + 14948);  /* 0x800CCF08 */
    R[2] = 0x8006u << 16;  /* 0x800CCF0C */
    { R[31] = 0x800CCF18u; sh_(R[2] + 13234, R[3]); psx_next = 0x800CBD84u; return; }  /* 0x800CCF10 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCF18 */
    R[2] = lw_(R[3] + 14104);  /* 0x800CCF1C */
    R[2] = R[2] | 0x1;  /* 0x800CCF24 */
    sw_(R[3] + 14104, R[2]);  /* 0x800CCF28 */
L_800CCF2C:;
    R[2] = 0x8014u << 16;  /* 0x800CCF2C */
L_800CCF30:;
    R[2] = lw_(R[2] + 14936);  /* 0x800CCF30 */
    R[2] = R[2] & 0x20;  /* 0x800CCF38 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x8013u << 16; if (_c) { goto L_800CCF5C; } }  /* 0x800CCF3C */
    R[2] = 0x8013u << 16;  /* 0x800CCF44 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF48 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF4C */
    { R[31] = 0x800CCF58u; R[5] = R[5] + 512; psx_next = 0x800CBB4Cu; return; }  /* 0x800CCF50 jal */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF58 */
L_800CCF5C:;
    R[16] = 0x8013u << 16;  /* 0x800CCF5C */
    R[2] = 0x8013u << 16;  /* 0x800CCF60 */
    R[3] = 0x8013u << 16;  /* 0x800CCF64 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF68 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF6C */
    R[6] = lw_(R[3] + 14052);  /* 0x800CCF70 */
    { R[31] = 0x800CCF7Cu; R[5] = R[5] + 1792; psx_next = 0x800B673Cu; return; }  /* 0x800CCF74 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCE7C(void) {
    R[2] = 0x8014u << 16;  /* 0x800CCE7C */
    R[3] = lw_(R[2] + 14936);  /* 0x800CCE80 */
    R[2] = R[3] & 0x100;  /* 0x800CCE88 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x10; if (_c) { goto L_800CCF2C; } }  /* 0x800CCE8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800CCEAC; } }  /* 0x800CCE94 */
    R[3] = 0x8013u << 16;  /* 0x800CCE9C */
    R[2] = R[0] + 10;  /* 0x800CCEA0 */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEA4 j */
L_800CCEAC:;
    R[2] = R[0] + 20;  /* 0x800CCEAC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCEB0 j */
    { R[31] = 0x800CCEC0u; R[4] = R[0] + 7; psx_next = 0x8001D930u; return; }  /* 0x800CCEB8 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCEC0 */
    R[2] = lw_(R[3] + 14084);  /* 0x800CCEC4 */
    R[2] = R[2] + 1;  /* 0x800CCECC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCED0 j */
    R[2] = R[16] << 1;  /* 0x800CCED8 */
    R[2] = R[2] + R[7];  /* 0x800CCEDC */
    sh_(R[6], R[8]);  /* 0x800CCEE0 */
    { sh_(R[2], R[4]); goto L_800CCF2C; }  /* 0x800CCEE4 j */
    R[2] = 0x8006u << 16;  /* 0x800CCEEC */
    R[3] = lb_(R[2] + 16409);  /* 0x800CCEF0 */
    R[2] = R[0] + 5;  /* 0x800CCEF4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCEF8 */
    R[2] = 0x8014u << 16;  /* 0x800CCF00 */
    R[4] = lw_(R[2] + 14948);  /* 0x800CCF04 */
    R[3] = lh_(R[2] + 14948);  /* 0x800CCF08 */
    R[2] = 0x8006u << 16;  /* 0x800CCF0C */
    { R[31] = 0x800CCF18u; sh_(R[2] + 13234, R[3]); psx_next = 0x800CBD84u; return; }  /* 0x800CCF10 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCF18 */
    R[2] = lw_(R[3] + 14104);  /* 0x800CCF1C */
    R[2] = R[2] | 0x1;  /* 0x800CCF24 */
    sw_(R[3] + 14104, R[2]);  /* 0x800CCF28 */
L_800CCF2C:;
    R[2] = 0x8014u << 16;  /* 0x800CCF2C */
L_800CCF30:;
    R[2] = lw_(R[2] + 14936);  /* 0x800CCF30 */
    R[2] = R[2] & 0x20;  /* 0x800CCF38 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x8013u << 16; if (_c) { goto L_800CCF5C; } }  /* 0x800CCF3C */
    R[2] = 0x8013u << 16;  /* 0x800CCF44 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF48 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF4C */
    { R[31] = 0x800CCF58u; R[5] = R[5] + 512; psx_next = 0x800CBB4Cu; return; }  /* 0x800CCF50 jal */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF58 */
L_800CCF5C:;
    R[16] = 0x8013u << 16;  /* 0x800CCF5C */
    R[2] = 0x8013u << 16;  /* 0x800CCF60 */
    R[3] = 0x8013u << 16;  /* 0x800CCF64 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF68 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF6C */
    R[6] = lw_(R[3] + 14052);  /* 0x800CCF70 */
    { R[31] = 0x800CCF7Cu; R[5] = R[5] + 1792; psx_next = 0x800B673Cu; return; }  /* 0x800CCF74 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCEB8(void) {
    { R[31] = 0x800CCEC0u; R[4] = R[0] + 7; psx_next = 0x8001D930u; return; }  /* 0x800CCEB8 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCEC0 */
    R[2] = lw_(R[3] + 14084);  /* 0x800CCEC4 */
    R[2] = R[2] + 1;  /* 0x800CCECC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCED0 j */
    R[2] = R[16] << 1;  /* 0x800CCED8 */
    R[2] = R[2] + R[7];  /* 0x800CCEDC */
    sh_(R[6], R[8]);  /* 0x800CCEE0 */
    { sh_(R[2], R[4]); goto L_800CCF2C; }  /* 0x800CCEE4 j */
    R[2] = 0x8006u << 16;  /* 0x800CCEEC */
    R[3] = lb_(R[2] + 16409);  /* 0x800CCEF0 */
    R[2] = R[0] + 5;  /* 0x800CCEF4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCEF8 */
    R[2] = 0x8014u << 16;  /* 0x800CCF00 */
    R[4] = lw_(R[2] + 14948);  /* 0x800CCF04 */
    R[3] = lh_(R[2] + 14948);  /* 0x800CCF08 */
    R[2] = 0x8006u << 16;  /* 0x800CCF0C */
    { R[31] = 0x800CCF18u; sh_(R[2] + 13234, R[3]); psx_next = 0x800CBD84u; return; }  /* 0x800CCF10 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCF18 */
    R[2] = lw_(R[3] + 14104);  /* 0x800CCF1C */
    R[2] = R[2] | 0x1;  /* 0x800CCF24 */
    sw_(R[3] + 14104, R[2]);  /* 0x800CCF28 */
L_800CCF2C:;
    R[2] = 0x8014u << 16;  /* 0x800CCF2C */
L_800CCF30:;
    R[2] = lw_(R[2] + 14936);  /* 0x800CCF30 */
    R[2] = R[2] & 0x20;  /* 0x800CCF38 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x8013u << 16; if (_c) { goto L_800CCF5C; } }  /* 0x800CCF3C */
    R[2] = 0x8013u << 16;  /* 0x800CCF44 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF48 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF4C */
    { R[31] = 0x800CCF58u; R[5] = R[5] + 512; psx_next = 0x800CBB4Cu; return; }  /* 0x800CCF50 jal */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF58 */
L_800CCF5C:;
    R[16] = 0x8013u << 16;  /* 0x800CCF5C */
    R[2] = 0x8013u << 16;  /* 0x800CCF60 */
    R[3] = 0x8013u << 16;  /* 0x800CCF64 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF68 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF6C */
    R[6] = lw_(R[3] + 14052);  /* 0x800CCF70 */
    { R[31] = 0x800CCF7Cu; R[5] = R[5] + 1792; psx_next = 0x800B673Cu; return; }  /* 0x800CCF74 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCEC0(void) {
    R[3] = 0x8013u << 16;  /* 0x800CCEC0 */
    R[2] = lw_(R[3] + 14084);  /* 0x800CCEC4 */
    R[2] = R[2] + 1;  /* 0x800CCECC */
    { sw_(R[3] + 14084, R[2]); goto L_800CCF2C; }  /* 0x800CCED0 j */
    R[2] = R[16] << 1;  /* 0x800CCED8 */
    R[2] = R[2] + R[7];  /* 0x800CCEDC */
    sh_(R[6], R[8]);  /* 0x800CCEE0 */
    { sh_(R[2], R[4]); goto L_800CCF2C; }  /* 0x800CCEE4 j */
    R[2] = 0x8006u << 16;  /* 0x800CCEEC */
    R[3] = lb_(R[2] + 16409);  /* 0x800CCEF0 */
    R[2] = R[0] + 5;  /* 0x800CCEF4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCEF8 */
    R[2] = 0x8014u << 16;  /* 0x800CCF00 */
    R[4] = lw_(R[2] + 14948);  /* 0x800CCF04 */
    R[3] = lh_(R[2] + 14948);  /* 0x800CCF08 */
    R[2] = 0x8006u << 16;  /* 0x800CCF0C */
    { R[31] = 0x800CCF18u; sh_(R[2] + 13234, R[3]); psx_next = 0x800CBD84u; return; }  /* 0x800CCF10 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCF18 */
    R[2] = lw_(R[3] + 14104);  /* 0x800CCF1C */
    R[2] = R[2] | 0x1;  /* 0x800CCF24 */
    sw_(R[3] + 14104, R[2]);  /* 0x800CCF28 */
L_800CCF2C:;
    R[2] = 0x8014u << 16;  /* 0x800CCF2C */
L_800CCF30:;
    R[2] = lw_(R[2] + 14936);  /* 0x800CCF30 */
    R[2] = R[2] & 0x20;  /* 0x800CCF38 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x8013u << 16; if (_c) { goto L_800CCF5C; } }  /* 0x800CCF3C */
    R[2] = 0x8013u << 16;  /* 0x800CCF44 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF48 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF4C */
    { R[31] = 0x800CCF58u; R[5] = R[5] + 512; psx_next = 0x800CBB4Cu; return; }  /* 0x800CCF50 jal */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF58 */
L_800CCF5C:;
    R[16] = 0x8013u << 16;  /* 0x800CCF5C */
    R[2] = 0x8013u << 16;  /* 0x800CCF60 */
    R[3] = 0x8013u << 16;  /* 0x800CCF64 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF68 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF6C */
    R[6] = lw_(R[3] + 14052);  /* 0x800CCF70 */
    { R[31] = 0x800CCF7Cu; R[5] = R[5] + 1792; psx_next = 0x800B673Cu; return; }  /* 0x800CCF74 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCEEC(void) {
    R[2] = 0x8006u << 16;  /* 0x800CCEEC */
    R[3] = lb_(R[2] + 16409);  /* 0x800CCEF0 */
    R[2] = R[0] + 5;  /* 0x800CCEF4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8014u << 16; if (_c) { goto L_800CCF30; } }  /* 0x800CCEF8 */
    R[2] = 0x8014u << 16;  /* 0x800CCF00 */
    R[4] = lw_(R[2] + 14948);  /* 0x800CCF04 */
    R[3] = lh_(R[2] + 14948);  /* 0x800CCF08 */
    R[2] = 0x8006u << 16;  /* 0x800CCF0C */
    { R[31] = 0x800CCF18u; sh_(R[2] + 13234, R[3]); psx_next = 0x800CBD84u; return; }  /* 0x800CCF10 jal */
    R[3] = 0x8013u << 16;  /* 0x800CCF18 */
    R[2] = lw_(R[3] + 14104);  /* 0x800CCF1C */
    R[2] = R[2] | 0x1;  /* 0x800CCF24 */
    sw_(R[3] + 14104, R[2]);  /* 0x800CCF28 */
    R[2] = 0x8014u << 16;  /* 0x800CCF2C */
L_800CCF30:;
    R[2] = lw_(R[2] + 14936);  /* 0x800CCF30 */
    R[2] = R[2] & 0x20;  /* 0x800CCF38 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x8013u << 16; if (_c) { goto L_800CCF5C; } }  /* 0x800CCF3C */
    R[2] = 0x8013u << 16;  /* 0x800CCF44 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF48 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF4C */
    { R[31] = 0x800CCF58u; R[5] = R[5] + 512; psx_next = 0x800CBB4Cu; return; }  /* 0x800CCF50 jal */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF58 */
L_800CCF5C:;
    R[16] = 0x8013u << 16;  /* 0x800CCF5C */
    R[2] = 0x8013u << 16;  /* 0x800CCF60 */
    R[3] = 0x8013u << 16;  /* 0x800CCF64 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF68 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF6C */
    R[6] = lw_(R[3] + 14052);  /* 0x800CCF70 */
    { R[31] = 0x800CCF7Cu; R[5] = R[5] + 1792; psx_next = 0x800B673Cu; return; }  /* 0x800CCF74 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCF18(void) {
    R[3] = 0x8013u << 16;  /* 0x800CCF18 */
    R[2] = lw_(R[3] + 14104);  /* 0x800CCF1C */
    R[2] = R[2] | 0x1;  /* 0x800CCF24 */
    sw_(R[3] + 14104, R[2]);  /* 0x800CCF28 */
    R[2] = 0x8014u << 16;  /* 0x800CCF2C */
    R[2] = lw_(R[2] + 14936);  /* 0x800CCF30 */
    R[2] = R[2] & 0x20;  /* 0x800CCF38 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x8013u << 16; if (_c) { goto L_800CCF5C; } }  /* 0x800CCF3C */
    R[2] = 0x8013u << 16;  /* 0x800CCF44 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF48 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF4C */
    { R[31] = 0x800CCF58u; R[5] = R[5] + 512; psx_next = 0x800CBB4Cu; return; }  /* 0x800CCF50 jal */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF58 */
L_800CCF5C:;
    R[16] = 0x8013u << 16;  /* 0x800CCF5C */
    R[2] = 0x8013u << 16;  /* 0x800CCF60 */
    R[3] = 0x8013u << 16;  /* 0x800CCF64 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF68 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF6C */
    R[6] = lw_(R[3] + 14052);  /* 0x800CCF70 */
    { R[31] = 0x800CCF7Cu; R[5] = R[5] + 1792; psx_next = 0x800B673Cu; return; }  /* 0x800CCF74 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCF2C(void) {
    R[2] = 0x8014u << 16;  /* 0x800CCF2C */
    R[2] = lw_(R[2] + 14936);  /* 0x800CCF30 */
    R[2] = R[2] & 0x20;  /* 0x800CCF38 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x8013u << 16; if (_c) { goto L_800CCF5C; } }  /* 0x800CCF3C */
    R[2] = 0x8013u << 16;  /* 0x800CCF44 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF48 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF4C */
    { R[31] = 0x800CCF58u; R[5] = R[5] + 512; psx_next = 0x800CBB4Cu; return; }  /* 0x800CCF50 jal */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF58 */
L_800CCF5C:;
    R[16] = 0x8013u << 16;  /* 0x800CCF5C */
    R[2] = 0x8013u << 16;  /* 0x800CCF60 */
    R[3] = 0x8013u << 16;  /* 0x800CCF64 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF68 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF6C */
    R[6] = lw_(R[3] + 14052);  /* 0x800CCF70 */
    { R[31] = 0x800CCF7Cu; R[5] = R[5] + 1792; psx_next = 0x800B673Cu; return; }  /* 0x800CCF74 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCF58(void) {
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF58 */
    R[16] = 0x8013u << 16;  /* 0x800CCF5C */
    R[2] = 0x8013u << 16;  /* 0x800CCF60 */
    R[3] = 0x8013u << 16;  /* 0x800CCF64 */
    R[4] = lw_(R[16] + 14080);  /* 0x800CCF68 */
    R[5] = lw_(R[2] + 14396);  /* 0x800CCF6C */
    R[6] = lw_(R[3] + 14052);  /* 0x800CCF70 */
    { R[31] = 0x800CCF7Cu; R[5] = R[5] + 1792; psx_next = 0x800B673Cu; return; }  /* 0x800CCF74 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCF7C(void) {
    R[31] = lw_(R[29] + 24);  /* 0x800CCF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CCF80 */
    sw_(R[16] + 14080, R[2]);  /* 0x800CCF84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CCF88 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CCF8C jr ra */
}

void g0_800CCF94(void) {
    R[8] = R[0] + R[0];  /* 0x800CCF94 */
    { uint32_t _c = ((int32_t)R[5] <= 0); R[7] = R[8] + R[0]; if (_c) { goto L_800CD020; } }  /* 0x800CCF98 */
    R[9] = R[0] - 897;  /* 0x800CCFA0 */
L_800CCFA4:;
    R[3] = lw_(R[4]);  /* 0x800CCFA4 */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_800CD010; } }  /* 0x800CCFAC */
    R[2] = lb_(R[3] + 789);  /* 0x800CCFB4 */
    R[2] = R[2] & 0x2;  /* 0x800CCFBC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CCFD0; } }  /* 0x800CCFC0 */
    { R[7] = R[7] + 1; goto L_800CD010; }  /* 0x800CCFC8 j */
L_800CCFD0:;
    { uint32_t _c = (R[6] == R[0]); if (_c) { goto L_800CD00C; } }  /* 0x800CCFD0 */
    sh_(R[3] + 694, R[0]);  /* 0x800CCFD8 */
    R[3] = lw_(R[4]);  /* 0x800CCFDC */
    R[2] = lw_(R[3] + 16);  /* 0x800CCFE4 */
    R[2] = R[2] & R[9];  /* 0x800CCFEC */
    sw_(R[3] + 16, R[2]);  /* 0x800CCFF0 */
    R[3] = lw_(R[4]);  /* 0x800CCFF4 */
    R[2] = lw_(R[3] + 16);  /* 0x800CCFFC */
    R[2] = R[2] | 0x80;  /* 0x800CD004 */
    sw_(R[3] + 16, R[2]);  /* 0x800CD008 */
L_800CD00C:;
    sw_(R[4], R[0]);  /* 0x800CD00C */
L_800CD010:;
    R[8] = R[8] + 1;  /* 0x800CD010 */
    R[2] = ((int32_t)R[8] < (int32_t)R[5]);  /* 0x800CD014 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[4] + 4; if (_c) { psx_bb(); goto L_800CCFA4; } }  /* 0x800CD018 */
L_800CD020:;
    { R[2] = R[7] + R[0]; psx_next = R[31]; return; }  /* 0x800CD020 jr ra */
}

void g0_800CD028(void) {
    { uint32_t _c = ((int32_t)R[5] <= 0); R[8] = R[0] + R[0]; if (_c) { goto L_800CD0B0; } }  /* 0x800CD028 */
    R[9] = R[0] - 897;  /* 0x800CD030 */
L_800CD034:;
    R[3] = lw_(R[4]);  /* 0x800CD034 */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_800CD0A0; } }  /* 0x800CD03C */
    R[7] = lb_(R[3] + 789);  /* 0x800CD044 */
    R[2] = R[7] & 0x2;  /* 0x800CD04C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[7] & 0xFD; if (_c) { goto L_800CD0A0; } }  /* 0x800CD050 */
    { uint32_t _c = (R[6] == R[0]); sb_(R[3] + 789, R[2]); if (_c) { goto L_800CD09C; } }  /* 0x800CD058 */
    R[2] = lw_(R[4]);  /* 0x800CD060 */
    sh_(R[2] + 694, R[0]);  /* 0x800CD068 */
    R[3] = lw_(R[4]);  /* 0x800CD06C */
    R[2] = lw_(R[3] + 16);  /* 0x800CD074 */
    R[2] = R[2] & R[9];  /* 0x800CD07C */
    sw_(R[3] + 16, R[2]);  /* 0x800CD080 */
    R[3] = lw_(R[4]);  /* 0x800CD084 */
    R[2] = lw_(R[3] + 16);  /* 0x800CD08C */
    R[2] = R[2] | 0x80;  /* 0x800CD094 */
    sw_(R[3] + 16, R[2]);  /* 0x800CD098 */
L_800CD09C:;
    sw_(R[4], R[0]);  /* 0x800CD09C */
L_800CD0A0:;
    R[8] = R[8] + 1;  /* 0x800CD0A0 */
    R[2] = ((int32_t)R[8] < (int32_t)R[5]);  /* 0x800CD0A4 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[4] + 4; if (_c) { psx_bb(); goto L_800CD034; } }  /* 0x800CD0A8 */
L_800CD0B0:;
    { psx_next = R[31]; return; }  /* 0x800CD0B0 jr ra */
    R[2] = lw_(R[4] + 72);  /* 0x800CD0B8 */
    R[6] = 0x8014u << 16;  /* 0x800CD0BC */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x800CD0C0 */
    R[2] = (uint32_t)(int16_t)lh_(R[6] + 15132);  /* 0x800CD0C4 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[5] + R[3]; if (_c) { goto L_800CD0E8; } }  /* 0x800CD0CC */
    sh_(R[6] + 15132, R[3]);  /* 0x800CD0D4 */
    R[2] = lb_(R[2]);  /* 0x800CD0D8 */
    R[2] = R[2] - 1;  /* 0x800CD0E0 */
    sh_(R[4] + 216, R[2]);  /* 0x800CD0E4 */
L_800CD0E8:;
    { psx_next = R[31]; return; }  /* 0x800CD0E8 jr ra */
}

void g0_800CD0F0(void) {
    R[2] = lw_(R[4] + 72);  /* 0x800CD0F0 */
    R[6] = 0x8014u << 16;  /* 0x800CD0F4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x800CD0F8 */
    R[2] = (uint32_t)(int16_t)lh_(R[6] + 15132);  /* 0x800CD0FC */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[5] - 1; if (_c) { goto L_800CD114; } }  /* 0x800CD104 */
    sh_(R[6] + 15132, R[3]);  /* 0x800CD10C */
    sh_(R[4] + 216, R[2]);  /* 0x800CD110 */
L_800CD114:;
    { psx_next = R[31]; return; }  /* 0x800CD114 jr ra */
}

void g0_800CD11C(void) {
    R[3] = 0x8014u << 16;  /* 0x800CD11C */
    R[7] = R[3] + 15024;  /* 0x800CD120 */
    R[2] = lh_(R[3] + 15024);  /* 0x800CD124 */
    R[4] = R[4] & 0xFFF;  /* 0x800CD128 */
    sh_(R[7] + 52, R[4]);  /* 0x800CD12C */
    sw_(R[7] + 56, R[5]);  /* 0x800CD130 */
    R[2] = R[2] | 0x1;  /* 0x800CD134 */
    sh_(R[3] + 15024, R[2]);  /* 0x800CD138 */
    R[3] = (uint32_t)(int16_t)lh_(R[7] + 2);  /* 0x800CD13C */
    R[2] = lh_(R[7] + 2);  /* 0x800CD140 */
    { uint32_t _c = (R[3] != R[4]); if (_c) { goto L_800CD154; } }  /* 0x800CD144 */
    { R[3] = R[0] + 4096; goto L_800CD164; }  /* 0x800CD14C j */
L_800CD154:;
    { uint32_t _c = (R[3] != R[0]); R[3] = R[2] - R[4]; if (_c) { goto L_800CD164; } }  /* 0x800CD154 */
    R[2] = R[0] + 4096;  /* 0x800CD15C */
    R[3] = R[2] - R[4];  /* 0x800CD160 */
L_800CD164:;
    { uint32_t _c = (R[6] != R[0]); R[2] = R[3] << 16; if (_c) { goto L_800CD180; } }  /* 0x800CD164 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CD16C */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CD190; } }  /* 0x800CD170 */
    { R[3] = R[0] - R[2]; goto L_800CD190; }  /* 0x800CD178 j */
L_800CD180:;
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CD180 */
    { uint32_t _c = ((int32_t)R[2] <= 0); if (_c) { goto L_800CD190; } }  /* 0x800CD184 */
    R[3] = R[0] - R[2];  /* 0x800CD18C */
L_800CD190:;
    R[2] = R[3] << 16;  /* 0x800CD190 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CD194 */
    psx_div((int32_t)R[2], (int32_t)R[5]);  /* 0x800CD198 */
    { uint32_t _c = (R[5] != R[0]); if (_c) { goto L_800CD1A8; } }  /* 0x800CD19C */
    psx_break(7168);  /* 0x800CD1A4 */
L_800CD1A8:;
    R[1] = R[0] - 1;  /* 0x800CD1A8 */
    { uint32_t _c = (R[5] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CD1C0; } }  /* 0x800CD1AC */
    { uint32_t _c = (R[2] != R[1]); if (_c) { goto L_800CD1C0; } }  /* 0x800CD1B4 */
    psx_break(6144);  /* 0x800CD1BC */
L_800CD1C0:;
    R[2] = LO;  /* 0x800CD1C0 */
    { sh_(R[7] + 54, R[2]); psx_next = R[31]; return; }  /* 0x800CD1C4 jr ra */
}

void g0_800CD1CC(void) {
    R[7] = 0x8014u << 16;  /* 0x800CD1CC */
    R[6] = R[7] + 15024;  /* 0x800CD1D0 */
    R[3] = lw_(R[6] + 4);  /* 0x800CD1D4 */
    R[3] = R[4] - R[3];  /* 0x800CD1DC */
    psx_div((int32_t)R[3], (int32_t)R[5]);  /* 0x800CD1E0 */
    { uint32_t _c = (R[5] != R[0]); if (_c) { goto L_800CD1F0; } }  /* 0x800CD1E4 */
    psx_break(7168);  /* 0x800CD1EC */
L_800CD1F0:;
    R[1] = R[0] - 1;  /* 0x800CD1F0 */
    { uint32_t _c = (R[5] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CD208; } }  /* 0x800CD1F4 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CD208; } }  /* 0x800CD1FC */
    psx_break(6144);  /* 0x800CD204 */
L_800CD208:;
    R[3] = LO;  /* 0x800CD208 */
    R[2] = lh_(R[7] + 15024);  /* 0x800CD20C */
    sw_(R[6] + 60, R[4]);  /* 0x800CD210 */
    sw_(R[6] + 68, R[5]);  /* 0x800CD214 */
    R[2] = R[2] | 0x2;  /* 0x800CD218 */
    sh_(R[7] + 15024, R[2]);  /* 0x800CD21C */
    { sw_(R[6] + 64, R[3]); psx_next = R[31]; return; }  /* 0x800CD220 jr ra */
}

void g0_800CD228(void) {
    R[7] = 0x8014u << 16;  /* 0x800CD228 */
    R[6] = R[7] + 15024;  /* 0x800CD22C */
    R[3] = lw_(R[6] + 12);  /* 0x800CD230 */
    R[3] = R[4] - R[3];  /* 0x800CD238 */
    psx_div((int32_t)R[3], (int32_t)R[5]);  /* 0x800CD23C */
    { uint32_t _c = (R[5] != R[0]); if (_c) { goto L_800CD24C; } }  /* 0x800CD240 */
    psx_break(7168);  /* 0x800CD248 */
L_800CD24C:;
    R[1] = R[0] - 1;  /* 0x800CD24C */
    { uint32_t _c = (R[5] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CD264; } }  /* 0x800CD250 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CD264; } }  /* 0x800CD258 */
    psx_break(6144);  /* 0x800CD260 */
L_800CD264:;
    R[3] = LO;  /* 0x800CD264 */
    R[2] = lh_(R[7] + 15024);  /* 0x800CD268 */
    sw_(R[6] + 72, R[4]);  /* 0x800CD26C */
    sw_(R[6] + 80, R[5]);  /* 0x800CD270 */
    R[2] = R[2] | 0x4;  /* 0x800CD274 */
    sh_(R[7] + 15024, R[2]);  /* 0x800CD278 */
    { sw_(R[6] + 76, R[3]); psx_next = R[31]; return; }  /* 0x800CD27C jr ra */
}

void g0_800CD284(void) {
    R[7] = 0x8014u << 16;  /* 0x800CD284 */
    R[6] = R[7] + 15024;  /* 0x800CD288 */
    R[3] = lw_(R[6] + 24);  /* 0x800CD28C */
    R[3] = R[4] - R[3];  /* 0x800CD294 */
    psx_div((int32_t)R[3], (int32_t)R[5]);  /* 0x800CD298 */
    { uint32_t _c = (R[5] != R[0]); if (_c) { goto L_800CD2A8; } }  /* 0x800CD29C */
    psx_break(7168);  /* 0x800CD2A4 */
L_800CD2A8:;
    R[1] = R[0] - 1;  /* 0x800CD2A8 */
    { uint32_t _c = (R[5] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CD2C0; } }  /* 0x800CD2AC */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CD2C0; } }  /* 0x800CD2B4 */
    psx_break(6144);  /* 0x800CD2BC */
L_800CD2C0:;
    R[3] = LO;  /* 0x800CD2C0 */
    R[2] = lh_(R[7] + 15024);  /* 0x800CD2C4 */
    sw_(R[6] + 84, R[4]);  /* 0x800CD2C8 */
    sw_(R[6] + 92, R[5]);  /* 0x800CD2CC */
    R[2] = R[2] | 0x8;  /* 0x800CD2D0 */
    sh_(R[7] + 15024, R[2]);  /* 0x800CD2D4 */
    { sw_(R[6] + 88, R[3]); psx_next = R[31]; return; }  /* 0x800CD2D8 jr ra */
}

void g0_800CD2E0(void) {
    R[7] = 0x8014u << 16;  /* 0x800CD2E0 */
    R[6] = R[7] + 15024;  /* 0x800CD2E4 */
    R[3] = lw_(R[6] + 28);  /* 0x800CD2E8 */
    R[3] = R[4] - R[3];  /* 0x800CD2F0 */
    psx_div((int32_t)R[3], (int32_t)R[5]);  /* 0x800CD2F4 */
    { uint32_t _c = (R[5] != R[0]); if (_c) { goto L_800CD304; } }  /* 0x800CD2F8 */
    psx_break(7168);  /* 0x800CD300 */
L_800CD304:;
    R[1] = R[0] - 1;  /* 0x800CD304 */
    { uint32_t _c = (R[5] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CD31C; } }  /* 0x800CD308 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CD31C; } }  /* 0x800CD310 */
    psx_break(6144);  /* 0x800CD318 */
L_800CD31C:;
    R[3] = LO;  /* 0x800CD31C */
    R[2] = lh_(R[7] + 15024);  /* 0x800CD320 */
    sw_(R[6] + 96, R[4]);  /* 0x800CD324 */
    sw_(R[6] + 104, R[5]);  /* 0x800CD328 */
    R[2] = R[2] | 0x10;  /* 0x800CD32C */
    sh_(R[7] + 15024, R[2]);  /* 0x800CD330 */
    { sw_(R[6] + 100, R[3]); psx_next = R[31]; return; }  /* 0x800CD334 jr ra */
}

void g0_800CD33C(void) {
    R[5] = 0x8014u << 16;  /* 0x800CD33C */
    R[4] = lh_(R[5] + 15024);  /* 0x800CD340 */
    psx_next = 0x800CD344u; return;  /* fallthrough */
}

void g0_800CD344(void) {
    R[29] = R[29] - 24;  /* 0x800CD344 */
    sw_(R[29] + 16, R[16]);  /* 0x800CD348 */
    R[16] = R[5] + 15024;  /* 0x800CD34C */
    R[2] = R[4] & 0x1F;  /* 0x800CD350 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[29] + 20, R[31]); if (_c) { goto L_800CD57C; } }  /* 0x800CD354 */
    R[2] = R[4] & 0x3;  /* 0x800CD35C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[4] & 0x1; if (_c) { goto L_800CD46C; } }  /* 0x800CD360 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CD3AC; } }  /* 0x800CD368 */
    R[2] = lw_(R[16] + 56);  /* 0x800CD370 */
    R[2] = R[2] - 1;  /* 0x800CD378 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[16] + 56, R[2]); if (_c) { goto L_800CD398; } }  /* 0x800CD37C */
    R[3] = lh_(R[16] + 52);  /* 0x800CD384 */
    R[2] = R[4] & 0xFFFE;  /* 0x800CD388 */
    sh_(R[5] + 15024, R[2]);  /* 0x800CD38C */
    { sh_(R[16] + 2, R[3]); goto L_800CD3AC; }  /* 0x800CD390 j */
L_800CD398:;
    R[2] = lh_(R[16] + 2);  /* 0x800CD398 */
    R[3] = lh_(R[16] + 54);  /* 0x800CD39C */
    R[2] = R[2] + R[3];  /* 0x800CD3A4 */
    sh_(R[16] + 2, R[2]);  /* 0x800CD3A8 */
L_800CD3AC:;
    R[2] = lh_(R[16]);  /* 0x800CD3AC */
    R[2] = R[2] & 0x2;  /* 0x800CD3B4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CD400; } }  /* 0x800CD3B8 */
    R[2] = lw_(R[16] + 68);  /* 0x800CD3C0 */
    R[2] = R[2] - 1;  /* 0x800CD3C8 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[16] + 68, R[2]); if (_c) { goto L_800CD3EC; } }  /* 0x800CD3CC */
    R[2] = lh_(R[16]);  /* 0x800CD3D4 */
    R[3] = lw_(R[16] + 60);  /* 0x800CD3D8 */
    R[2] = R[2] & 0xFFFD;  /* 0x800CD3DC */
    sw_(R[16] + 4, R[3]);  /* 0x800CD3E0 */
    { sh_(R[16], R[2]); goto L_800CD400; }  /* 0x800CD3E4 j */
L_800CD3EC:;
    R[2] = lw_(R[16] + 4);  /* 0x800CD3EC */
    R[3] = lw_(R[16] + 64);  /* 0x800CD3F0 */
    R[2] = R[2] + R[3];  /* 0x800CD3F8 */
    sw_(R[16] + 4, R[2]);  /* 0x800CD3FC */
L_800CD400:;
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 2);  /* 0x800CD400 */
    { R[31] = 0x800CD40Cu; psx_next = 0x80035B18u; return; }  /* 0x800CD404 jal */
    R[3] = lw_(R[16] + 4);  /* 0x800CD40C */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[2] + R[0]; if (_c) { goto L_800CD420; } }  /* 0x800CD414 */
    R[3] = R[3] + 4095;  /* 0x800CD41C */
L_800CD420:;
    R[2] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x800CD420 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CD424 */
    R[2] = lw_(R[16] + 20);  /* 0x800CD428 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 2);  /* 0x800CD42C */
    R[8] = LO;  /* 0x800CD430 */
    R[2] = R[2] + R[8];  /* 0x800CD434 */
    { R[31] = 0x800CD440u; sw_(R[16] + 8, R[2]); psx_next = 0x80035A48u; return; }  /* 0x800CD438 jal */
    R[3] = lw_(R[16] + 4);  /* 0x800CD440 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[2] + R[0]; if (_c) { goto L_800CD454; } }  /* 0x800CD448 */
    R[3] = R[3] + 4095;  /* 0x800CD450 */
L_800CD454:;
    R[2] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x800CD454 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CD458 */
    R[2] = lw_(R[16] + 28);  /* 0x800CD45C */
    R[8] = LO;  /* 0x800CD460 */
    R[2] = R[2] + R[8];  /* 0x800CD464 */
    sw_(R[16] + 16, R[2]);  /* 0x800CD468 */
L_800CD46C:;
    R[2] = lh_(R[16]);  /* 0x800CD46C */
    R[2] = R[2] & 0x4;  /* 0x800CD474 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CD4C0; } }  /* 0x800CD478 */
    R[2] = lw_(R[16] + 80);  /* 0x800CD480 */
    R[2] = R[2] - 1;  /* 0x800CD488 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[16] + 80, R[2]); if (_c) { goto L_800CD4AC; } }  /* 0x800CD48C */
    R[2] = lh_(R[16]);  /* 0x800CD494 */
    R[3] = lw_(R[16] + 72);  /* 0x800CD498 */
    R[2] = R[2] & 0xFFFB;  /* 0x800CD49C */
    sw_(R[16] + 12, R[3]);  /* 0x800CD4A0 */
    { sh_(R[16], R[2]); goto L_800CD4C0; }  /* 0x800CD4A4 j */
L_800CD4AC:;
    R[2] = lw_(R[16] + 12);  /* 0x800CD4AC */
    R[3] = lw_(R[16] + 76);  /* 0x800CD4B0 */
    R[2] = R[2] + R[3];  /* 0x800CD4B8 */
    sw_(R[16] + 12, R[2]);  /* 0x800CD4BC */
L_800CD4C0:;
    R[2] = lh_(R[16]);  /* 0x800CD4C0 */
    R[2] = R[2] & 0x8;  /* 0x800CD4C8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CD514; } }  /* 0x800CD4CC */
    R[2] = lw_(R[16] + 92);  /* 0x800CD4D4 */
    R[2] = R[2] - 1;  /* 0x800CD4DC */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[16] + 92, R[2]); if (_c) { goto L_800CD500; } }  /* 0x800CD4E0 */
    R[2] = lh_(R[16]);  /* 0x800CD4E8 */
    R[3] = lw_(R[16] + 84);  /* 0x800CD4EC */
    R[2] = R[2] & 0xFFF7;  /* 0x800CD4F0 */
    sw_(R[16] + 24, R[3]);  /* 0x800CD4F4 */
    { sh_(R[16], R[2]); goto L_800CD514; }  /* 0x800CD4F8 j */
L_800CD500:;
    R[2] = lw_(R[16] + 24);  /* 0x800CD500 */
    R[3] = lw_(R[16] + 88);  /* 0x800CD504 */
    R[2] = R[2] + R[3];  /* 0x800CD50C */
    sw_(R[16] + 24, R[2]);  /* 0x800CD510 */
L_800CD514:;
    R[2] = lh_(R[16]);  /* 0x800CD514 */
    R[2] = R[2] & 0x10;  /* 0x800CD51C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + 8; if (_c) { goto L_800CD56C; } }  /* 0x800CD520 */
    R[2] = lw_(R[16] + 104);  /* 0x800CD528 */
    R[2] = R[2] - 1;  /* 0x800CD530 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[16] + 104, R[2]); if (_c) { goto L_800CD554; } }  /* 0x800CD534 */
    R[2] = lh_(R[16]);  /* 0x800CD53C */
    R[3] = lw_(R[16] + 96);  /* 0x800CD540 */
    R[2] = R[2] & 0xFFEF;  /* 0x800CD544 */
    sw_(R[16] + 28, R[3]);  /* 0x800CD548 */
    { sh_(R[16], R[2]); goto L_800CD56C; }  /* 0x800CD54C j */
L_800CD554:;
    R[2] = lw_(R[16] + 28);  /* 0x800CD554 */
    R[3] = lw_(R[16] + 100);  /* 0x800CD558 */
    R[2] = R[2] + R[3];  /* 0x800CD560 */
    sw_(R[16] + 28, R[2]);  /* 0x800CD564 */
    R[4] = R[16] + 8;  /* 0x800CD568 */
L_800CD56C:;
    R[5] = R[16] + 20;  /* 0x800CD56C */
    R[6] = R[16] + 32;  /* 0x800CD570 */
    { R[31] = 0x800CD57Cu; R[7] = R[0] + R[0]; psx_next = 0x800268E4u; return; }  /* 0x800CD574 jal */
L_800CD57C:;
    R[31] = lw_(R[29] + 20);  /* 0x800CD57C */
    R[16] = lw_(R[29] + 16);  /* 0x800CD580 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800CD584 jr ra */
}

void g0_800CD40C(void) {
    R[3] = lw_(R[16] + 4);  /* 0x800CD40C */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[2] + R[0]; if (_c) { goto L_800CD420; } }  /* 0x800CD414 */
    R[3] = R[3] + 4095;  /* 0x800CD41C */
L_800CD420:;
    R[2] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x800CD420 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CD424 */
    R[2] = lw_(R[16] + 20);  /* 0x800CD428 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 2);  /* 0x800CD42C */
    R[8] = LO;  /* 0x800CD430 */
    R[2] = R[2] + R[8];  /* 0x800CD434 */
    { R[31] = 0x800CD440u; sw_(R[16] + 8, R[2]); psx_next = 0x80035A48u; return; }  /* 0x800CD438 jal */
    R[3] = lw_(R[16] + 4);  /* 0x800CD440 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[2] + R[0]; if (_c) { goto L_800CD454; } }  /* 0x800CD448 */
    R[3] = R[3] + 4095;  /* 0x800CD450 */
L_800CD454:;
    R[2] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x800CD454 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CD458 */
    R[2] = lw_(R[16] + 28);  /* 0x800CD45C */
    R[8] = LO;  /* 0x800CD460 */
    R[2] = R[2] + R[8];  /* 0x800CD464 */
    sw_(R[16] + 16, R[2]);  /* 0x800CD468 */
    R[2] = lh_(R[16]);  /* 0x800CD46C */
    R[2] = R[2] & 0x4;  /* 0x800CD474 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CD4C0; } }  /* 0x800CD478 */
    R[2] = lw_(R[16] + 80);  /* 0x800CD480 */
    R[2] = R[2] - 1;  /* 0x800CD488 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[16] + 80, R[2]); if (_c) { goto L_800CD4AC; } }  /* 0x800CD48C */
    R[2] = lh_(R[16]);  /* 0x800CD494 */
    R[3] = lw_(R[16] + 72);  /* 0x800CD498 */
    R[2] = R[2] & 0xFFFB;  /* 0x800CD49C */
    sw_(R[16] + 12, R[3]);  /* 0x800CD4A0 */
    { sh_(R[16], R[2]); goto L_800CD4C0; }  /* 0x800CD4A4 j */
L_800CD4AC:;
    R[2] = lw_(R[16] + 12);  /* 0x800CD4AC */
    R[3] = lw_(R[16] + 76);  /* 0x800CD4B0 */
    R[2] = R[2] + R[3];  /* 0x800CD4B8 */
    sw_(R[16] + 12, R[2]);  /* 0x800CD4BC */
L_800CD4C0:;
    R[2] = lh_(R[16]);  /* 0x800CD4C0 */
    R[2] = R[2] & 0x8;  /* 0x800CD4C8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CD514; } }  /* 0x800CD4CC */
    R[2] = lw_(R[16] + 92);  /* 0x800CD4D4 */
    R[2] = R[2] - 1;  /* 0x800CD4DC */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[16] + 92, R[2]); if (_c) { goto L_800CD500; } }  /* 0x800CD4E0 */
    R[2] = lh_(R[16]);  /* 0x800CD4E8 */
    R[3] = lw_(R[16] + 84);  /* 0x800CD4EC */
    R[2] = R[2] & 0xFFF7;  /* 0x800CD4F0 */
    sw_(R[16] + 24, R[3]);  /* 0x800CD4F4 */
    { sh_(R[16], R[2]); goto L_800CD514; }  /* 0x800CD4F8 j */
L_800CD500:;
    R[2] = lw_(R[16] + 24);  /* 0x800CD500 */
    R[3] = lw_(R[16] + 88);  /* 0x800CD504 */
    R[2] = R[2] + R[3];  /* 0x800CD50C */
    sw_(R[16] + 24, R[2]);  /* 0x800CD510 */
L_800CD514:;
    R[2] = lh_(R[16]);  /* 0x800CD514 */
    R[2] = R[2] & 0x10;  /* 0x800CD51C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + 8; if (_c) { goto L_800CD56C; } }  /* 0x800CD520 */
    R[2] = lw_(R[16] + 104);  /* 0x800CD528 */
    R[2] = R[2] - 1;  /* 0x800CD530 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[16] + 104, R[2]); if (_c) { goto L_800CD554; } }  /* 0x800CD534 */
    R[2] = lh_(R[16]);  /* 0x800CD53C */
    R[3] = lw_(R[16] + 96);  /* 0x800CD540 */
    R[2] = R[2] & 0xFFEF;  /* 0x800CD544 */
    sw_(R[16] + 28, R[3]);  /* 0x800CD548 */
    { sh_(R[16], R[2]); goto L_800CD56C; }  /* 0x800CD54C j */
L_800CD554:;
    R[2] = lw_(R[16] + 28);  /* 0x800CD554 */
    R[3] = lw_(R[16] + 100);  /* 0x800CD558 */
    R[2] = R[2] + R[3];  /* 0x800CD560 */
    sw_(R[16] + 28, R[2]);  /* 0x800CD564 */
    R[4] = R[16] + 8;  /* 0x800CD568 */
L_800CD56C:;
    R[5] = R[16] + 20;  /* 0x800CD56C */
    R[6] = R[16] + 32;  /* 0x800CD570 */
    { R[31] = 0x800CD57Cu; R[7] = R[0] + R[0]; psx_next = 0x800268E4u; return; }  /* 0x800CD574 jal */
    R[31] = lw_(R[29] + 20);  /* 0x800CD57C */
    R[16] = lw_(R[29] + 16);  /* 0x800CD580 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800CD584 jr ra */
}

void g0_800CD440(void) {
    R[3] = lw_(R[16] + 4);  /* 0x800CD440 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[2] + R[0]; if (_c) { goto L_800CD454; } }  /* 0x800CD448 */
    R[3] = R[3] + 4095;  /* 0x800CD450 */
L_800CD454:;
    R[2] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x800CD454 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CD458 */
    R[2] = lw_(R[16] + 28);  /* 0x800CD45C */
    R[8] = LO;  /* 0x800CD460 */
    R[2] = R[2] + R[8];  /* 0x800CD464 */
    sw_(R[16] + 16, R[2]);  /* 0x800CD468 */
    R[2] = lh_(R[16]);  /* 0x800CD46C */
    R[2] = R[2] & 0x4;  /* 0x800CD474 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CD4C0; } }  /* 0x800CD478 */
    R[2] = lw_(R[16] + 80);  /* 0x800CD480 */
    R[2] = R[2] - 1;  /* 0x800CD488 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[16] + 80, R[2]); if (_c) { goto L_800CD4AC; } }  /* 0x800CD48C */
    R[2] = lh_(R[16]);  /* 0x800CD494 */
    R[3] = lw_(R[16] + 72);  /* 0x800CD498 */
    R[2] = R[2] & 0xFFFB;  /* 0x800CD49C */
    sw_(R[16] + 12, R[3]);  /* 0x800CD4A0 */
    { sh_(R[16], R[2]); goto L_800CD4C0; }  /* 0x800CD4A4 j */
L_800CD4AC:;
    R[2] = lw_(R[16] + 12);  /* 0x800CD4AC */
    R[3] = lw_(R[16] + 76);  /* 0x800CD4B0 */
    R[2] = R[2] + R[3];  /* 0x800CD4B8 */
    sw_(R[16] + 12, R[2]);  /* 0x800CD4BC */
L_800CD4C0:;
    R[2] = lh_(R[16]);  /* 0x800CD4C0 */
    R[2] = R[2] & 0x8;  /* 0x800CD4C8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CD514; } }  /* 0x800CD4CC */
    R[2] = lw_(R[16] + 92);  /* 0x800CD4D4 */
    R[2] = R[2] - 1;  /* 0x800CD4DC */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[16] + 92, R[2]); if (_c) { goto L_800CD500; } }  /* 0x800CD4E0 */
    R[2] = lh_(R[16]);  /* 0x800CD4E8 */
    R[3] = lw_(R[16] + 84);  /* 0x800CD4EC */
    R[2] = R[2] & 0xFFF7;  /* 0x800CD4F0 */
    sw_(R[16] + 24, R[3]);  /* 0x800CD4F4 */
    { sh_(R[16], R[2]); goto L_800CD514; }  /* 0x800CD4F8 j */
L_800CD500:;
    R[2] = lw_(R[16] + 24);  /* 0x800CD500 */
    R[3] = lw_(R[16] + 88);  /* 0x800CD504 */
    R[2] = R[2] + R[3];  /* 0x800CD50C */
    sw_(R[16] + 24, R[2]);  /* 0x800CD510 */
L_800CD514:;
    R[2] = lh_(R[16]);  /* 0x800CD514 */
    R[2] = R[2] & 0x10;  /* 0x800CD51C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + 8; if (_c) { goto L_800CD56C; } }  /* 0x800CD520 */
    R[2] = lw_(R[16] + 104);  /* 0x800CD528 */
    R[2] = R[2] - 1;  /* 0x800CD530 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[16] + 104, R[2]); if (_c) { goto L_800CD554; } }  /* 0x800CD534 */
    R[2] = lh_(R[16]);  /* 0x800CD53C */
    R[3] = lw_(R[16] + 96);  /* 0x800CD540 */
    R[2] = R[2] & 0xFFEF;  /* 0x800CD544 */
    sw_(R[16] + 28, R[3]);  /* 0x800CD548 */
    { sh_(R[16], R[2]); goto L_800CD56C; }  /* 0x800CD54C j */
L_800CD554:;
    R[2] = lw_(R[16] + 28);  /* 0x800CD554 */
    R[3] = lw_(R[16] + 100);  /* 0x800CD558 */
    R[2] = R[2] + R[3];  /* 0x800CD560 */
    sw_(R[16] + 28, R[2]);  /* 0x800CD564 */
    R[4] = R[16] + 8;  /* 0x800CD568 */
L_800CD56C:;
    R[5] = R[16] + 20;  /* 0x800CD56C */
    R[6] = R[16] + 32;  /* 0x800CD570 */
    { R[31] = 0x800CD57Cu; R[7] = R[0] + R[0]; psx_next = 0x800268E4u; return; }  /* 0x800CD574 jal */
    R[31] = lw_(R[29] + 20);  /* 0x800CD57C */
    R[16] = lw_(R[29] + 16);  /* 0x800CD580 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800CD584 jr ra */
}

void g0_800CD57C(void) {
    R[31] = lw_(R[29] + 20);  /* 0x800CD57C */
    R[16] = lw_(R[29] + 16);  /* 0x800CD580 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800CD584 jr ra */
}

void g0_800CD58C(void) {
    R[29] = R[29] - 24;  /* 0x800CD58C */
    sw_(R[29] + 16, R[16]);  /* 0x800CD590 */
    R[16] = 0x8014u << 16;  /* 0x800CD594 */
    sh_(R[16] + 15024, R[0]);  /* 0x800CD598 */
    R[16] = R[16] + 15024;  /* 0x800CD59C */
    R[4] = R[16] + 8;  /* 0x800CD5A0 */
    R[5] = R[16] + 20;  /* 0x800CD5A4 */
    R[6] = R[16] + 32;  /* 0x800CD5A8 */
    R[7] = R[0] + R[0];  /* 0x800CD5AC */
    sw_(R[29] + 20, R[31]);  /* 0x800CD5B0 */
    sh_(R[16] + 2, R[0]);  /* 0x800CD5B4 */
    sw_(R[16] + 4, R[0]);  /* 0x800CD5B8 */
    sw_(R[16] + 8, R[0]);  /* 0x800CD5BC */
    sw_(R[16] + 12, R[0]);  /* 0x800CD5C0 */
    sw_(R[16] + 16, R[0]);  /* 0x800CD5C4 */
    sw_(R[16] + 20, R[0]);  /* 0x800CD5C8 */
    sw_(R[16] + 24, R[0]);  /* 0x800CD5CC */
    { R[31] = 0x800CD5D8u; sw_(R[16] + 28, R[0]); psx_next = 0x800268E4u; return; }  /* 0x800CD5D0 jal */
    sh_(R[16] + 52, R[0]);  /* 0x800CD5D8 */
    sh_(R[16] + 54, R[0]);  /* 0x800CD5DC */
    sw_(R[16] + 56, R[0]);  /* 0x800CD5E0 */
    sw_(R[16] + 60, R[0]);  /* 0x800CD5E4 */
    sw_(R[16] + 64, R[0]);  /* 0x800CD5E8 */
    sw_(R[16] + 68, R[0]);  /* 0x800CD5EC */
    sw_(R[16] + 72, R[0]);  /* 0x800CD5F0 */
    sw_(R[16] + 76, R[0]);  /* 0x800CD5F4 */
    sw_(R[16] + 80, R[0]);  /* 0x800CD5F8 */
    sw_(R[16] + 84, R[0]);  /* 0x800CD5FC */
    sw_(R[16] + 88, R[0]);  /* 0x800CD600 */
    sw_(R[16] + 92, R[0]);  /* 0x800CD604 */
    sw_(R[16] + 96, R[0]);  /* 0x800CD608 */
    sw_(R[16] + 100, R[0]);  /* 0x800CD60C */
    sw_(R[16] + 104, R[0]);  /* 0x800CD610 */
    R[31] = lw_(R[29] + 20);  /* 0x800CD614 */
    R[16] = lw_(R[29] + 16);  /* 0x800CD618 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800CD61C jr ra */
    R[3] = R[4] << 3;  /* 0x800CD624 */
    R[3] = R[3] + R[4];  /* 0x800CD628 */
    R[3] = R[3] << 3;  /* 0x800CD62C */
    R[2] = 0x8014u << 16;  /* 0x800CD630 */
    R[2] = R[2] + 15160;  /* 0x800CD634 */
    R[3] = R[3] + R[2];  /* 0x800CD638 */
    { uint32_t _c = ((int32_t)R[5] <= 0); R[4] = R[0] + R[0]; if (_c) { goto L_800CD66C; } }  /* 0x800CD63C */
    R[6] = R[0] + 4;  /* 0x800CD644 */
L_800CD648:;
    R[2] = lh_(R[3]);  /* 0x800CD648 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CD65C; } }  /* 0x800CD650 */
    sb_(R[3] + 3, R[6]);  /* 0x800CD658 */
L_800CD65C:;
    R[4] = R[4] + 1;  /* 0x800CD65C */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800CD660 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_800CD648; } }  /* 0x800CD664 */
L_800CD66C:;
    { psx_next = R[31]; return; }  /* 0x800CD66C jr ra */
    R[2] = 0x8014u << 16;  /* 0x800CD674 */
    R[5] = R[2] + 15160;  /* 0x800CD678 */
    R[6] = R[0] + R[0];  /* 0x800CD67C */
    R[4] = R[4] & 0xFF;  /* 0x800CD680 */
    R[7] = R[0] + 4;  /* 0x800CD684 */
    R[3] = R[5] + 3;  /* 0x800CD688 */
L_800CD68C:;
    R[2] = lh_(R[5]);  /* 0x800CD68C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CD6B0; } }  /* 0x800CD694 */
    R[2] = lb_(R[3] + 61);  /* 0x800CD69C */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_800CD6B0; } }  /* 0x800CD6A4 */
    sb_(R[3], R[7]);  /* 0x800CD6AC */
L_800CD6B0:;
    R[3] = R[3] + 72;  /* 0x800CD6B0 */
    R[6] = R[6] + 1;  /* 0x800CD6B4 */
    R[2] = ((int32_t)R[6] < 64);  /* 0x800CD6B8 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[5] + 72; if (_c) { psx_bb(); goto L_800CD68C; } }  /* 0x800CD6BC */
    { psx_next = R[31]; return; }  /* 0x800CD6C4 jr ra */
}

void g0_800CD5D8(void) {
    sh_(R[16] + 52, R[0]);  /* 0x800CD5D8 */
    sh_(R[16] + 54, R[0]);  /* 0x800CD5DC */
    sw_(R[16] + 56, R[0]);  /* 0x800CD5E0 */
    sw_(R[16] + 60, R[0]);  /* 0x800CD5E4 */
    sw_(R[16] + 64, R[0]);  /* 0x800CD5E8 */
    sw_(R[16] + 68, R[0]);  /* 0x800CD5EC */
    sw_(R[16] + 72, R[0]);  /* 0x800CD5F0 */
    sw_(R[16] + 76, R[0]);  /* 0x800CD5F4 */
    sw_(R[16] + 80, R[0]);  /* 0x800CD5F8 */
    sw_(R[16] + 84, R[0]);  /* 0x800CD5FC */
    sw_(R[16] + 88, R[0]);  /* 0x800CD600 */
    sw_(R[16] + 92, R[0]);  /* 0x800CD604 */
    sw_(R[16] + 96, R[0]);  /* 0x800CD608 */
    sw_(R[16] + 100, R[0]);  /* 0x800CD60C */
    sw_(R[16] + 104, R[0]);  /* 0x800CD610 */
    R[31] = lw_(R[29] + 20);  /* 0x800CD614 */
    R[16] = lw_(R[29] + 16);  /* 0x800CD618 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800CD61C jr ra */
    R[3] = R[4] << 3;  /* 0x800CD624 */
    R[3] = R[3] + R[4];  /* 0x800CD628 */
    R[3] = R[3] << 3;  /* 0x800CD62C */
    R[2] = 0x8014u << 16;  /* 0x800CD630 */
    R[2] = R[2] + 15160;  /* 0x800CD634 */
    R[3] = R[3] + R[2];  /* 0x800CD638 */
    { uint32_t _c = ((int32_t)R[5] <= 0); R[4] = R[0] + R[0]; if (_c) { goto L_800CD66C; } }  /* 0x800CD63C */
    R[6] = R[0] + 4;  /* 0x800CD644 */
L_800CD648:;
    R[2] = lh_(R[3]);  /* 0x800CD648 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CD65C; } }  /* 0x800CD650 */
    sb_(R[3] + 3, R[6]);  /* 0x800CD658 */
L_800CD65C:;
    R[4] = R[4] + 1;  /* 0x800CD65C */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800CD660 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_800CD648; } }  /* 0x800CD664 */
L_800CD66C:;
    { psx_next = R[31]; return; }  /* 0x800CD66C jr ra */
    R[2] = 0x8014u << 16;  /* 0x800CD674 */
    R[5] = R[2] + 15160;  /* 0x800CD678 */
    R[6] = R[0] + R[0];  /* 0x800CD67C */
    R[4] = R[4] & 0xFF;  /* 0x800CD680 */
    R[7] = R[0] + 4;  /* 0x800CD684 */
    R[3] = R[5] + 3;  /* 0x800CD688 */
L_800CD68C:;
    R[2] = lh_(R[5]);  /* 0x800CD68C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CD6B0; } }  /* 0x800CD694 */
    R[2] = lb_(R[3] + 61);  /* 0x800CD69C */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_800CD6B0; } }  /* 0x800CD6A4 */
    sb_(R[3], R[7]);  /* 0x800CD6AC */
L_800CD6B0:;
    R[3] = R[3] + 72;  /* 0x800CD6B0 */
    R[6] = R[6] + 1;  /* 0x800CD6B4 */
    R[2] = ((int32_t)R[6] < 64);  /* 0x800CD6B8 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[5] + 72; if (_c) { psx_bb(); goto L_800CD68C; } }  /* 0x800CD6BC */
    { psx_next = R[31]; return; }  /* 0x800CD6C4 jr ra */
}

void g0_800CD6CC(void) {
    R[6] = R[4] + R[0];  /* 0x800CD6CC */
    { uint32_t _c = ((int32_t)R[5] <= 0); R[3] = R[0] + R[0]; if (_c) { goto L_800CD6FC; } }  /* 0x800CD6D0 */
    R[4] = R[4] + 3;  /* 0x800CD6D8 */
L_800CD6DC:;
    sh_(R[6], R[0]);  /* 0x800CD6DC */
    sb_(R[4] + -1, R[0]);  /* 0x800CD6E0 */
    sb_(R[4], R[0]);  /* 0x800CD6E4 */
    R[4] = R[4] + 72;  /* 0x800CD6E8 */
    R[3] = R[3] + 1;  /* 0x800CD6EC */
    R[2] = ((int32_t)R[3] < (int32_t)R[5]);  /* 0x800CD6F0 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[6] + 72; if (_c) { psx_bb(); goto L_800CD6DC; } }  /* 0x800CD6F4 */
L_800CD6FC:;
    { psx_next = R[31]; return; }  /* 0x800CD6FC jr ra */
}

void g0_800CD704(void) {
    R[2] = 0x8014u << 16;  /* 0x800CD704 */
    R[5] = R[2] + 15160;  /* 0x800CD708 */
    R[6] = R[0] + R[0];  /* 0x800CD70C */
    R[4] = R[4] & 0xFF;  /* 0x800CD710 */
    R[3] = R[5] + 3;  /* 0x800CD714 */
L_800CD718:;
    R[2] = lb_(R[3] + 61);  /* 0x800CD718 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_800CD734; } }  /* 0x800CD720 */
    sh_(R[5], R[0]);  /* 0x800CD728 */
    sb_(R[3] + -1, R[0]);  /* 0x800CD72C */
    sb_(R[3], R[0]);  /* 0x800CD730 */
L_800CD734:;
    R[3] = R[3] + 72;  /* 0x800CD734 */
    R[6] = R[6] + 1;  /* 0x800CD738 */
    R[2] = ((int32_t)R[6] < 64);  /* 0x800CD73C */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[5] + 72; if (_c) { psx_bb(); goto L_800CD718; } }  /* 0x800CD740 */
    { psx_next = R[31]; return; }  /* 0x800CD748 jr ra */
}

void g0_800CD750(void) {
    R[29] = R[29] - 64;  /* 0x800CD750 */
    sw_(R[29] + 48, R[22]);  /* 0x800CD754 */
    R[22] = R[4] + R[0];  /* 0x800CD758 */
    sw_(R[29] + 40, R[20]);  /* 0x800CD75C */
    R[20] = R[0] + R[0];  /* 0x800CD760 */
    R[4] = R[7] + R[0];  /* 0x800CD764 */
    R[2] = 0x800Fu << 16;  /* 0x800CD768 */
    R[2] = R[2] - 276;  /* 0x800CD76C */
    sw_(R[29] + 24, R[16]);  /* 0x800CD770 */
    R[16] = R[6] + R[0];  /* 0x800CD774 */
    sw_(R[29] + 52, R[23]);  /* 0x800CD778 */
    R[23] = 0x1F80u << 16;  /* 0x800CD77C */
    sw_(R[29] + 56, R[31]);  /* 0x800CD780 */
    sw_(R[29] + 44, R[21]);  /* 0x800CD784 */
    sw_(R[29] + 36, R[19]);  /* 0x800CD788 */
    sw_(R[29] + 32, R[18]);  /* 0x800CD78C */
    sw_(R[29] + 28, R[17]);  /* 0x800CD790 */
    R[3] = (uint32_t)(int16_t)lh_(R[22] + 604);  /* 0x800CD794 */
    R[21] = lb_(R[22] + 97);  /* 0x800CD798 */
    R[3] = R[3] << 4;  /* 0x800CD79C */
    { uint32_t _c = (R[21] == R[0]); R[17] = R[3] + R[2]; if (_c) { goto L_800CD864; } }  /* 0x800CD7A0 */
    R[19] = R[4] + R[0];  /* 0x800CD7A8 */
    R[18] = R[5] + R[0];  /* 0x800CD7AC */
L_800CD7B0:;
    R[2] = lw_(R[22] + 72);  /* 0x800CD7B0 */
    R[2] = lh_(R[2]);  /* 0x800CD7B8 */
    R[2] = R[2] & 0x8000;  /* 0x800CD7C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_800CD84C; } }  /* 0x800CD7C4 */
    R[2] = (uint32_t)(int16_t)lh_(R[18] + 18);  /* 0x800CD7CC */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[22] + R[0]; if (_c) { goto L_800CD848; } }  /* 0x800CD7D4 */
    R[2] = lh_(R[17]);  /* 0x800CD7DC */
    sh_(R[16] + 24, R[2]);  /* 0x800CD7E4 */
    R[2] = lh_(R[17] + 2);  /* 0x800CD7E8 */
    sh_(R[16] + 26, R[2]);  /* 0x800CD7F0 */
    R[2] = lh_(R[17] + 4);  /* 0x800CD7F4 */
    sh_(R[16] + 28, R[2]);  /* 0x800CD7FC */
    R[2] = lh_(R[17] + 8);  /* 0x800CD800 */
    R[5] = R[18] + R[0];  /* 0x800CD804 */
    sh_(R[16] + 32, R[2]);  /* 0x800CD808 */
    R[2] = lh_(R[17] + 10);  /* 0x800CD80C */
    R[6] = R[16] + 24;  /* 0x800CD810 */
    sh_(R[16] + 34, R[2]);  /* 0x800CD814 */
    R[2] = lh_(R[17] + 12);  /* 0x800CD818 */
    R[7] = R[16] + R[0];  /* 0x800CD81C */
    sh_(R[16] + 36, R[2]);  /* 0x800CD820 */
    { R[31] = 0x800CD82Cu; sw_(R[29] + 16, R[23]); psx_next = 0x800AA0ECu; return; }  /* 0x800CD824 jal */
    R[4] = R[19] + R[0];  /* 0x800CD82C */
    R[5] = R[18] + R[0];  /* 0x800CD830 */
    R[6] = R[0] + R[0];  /* 0x800CD834 */
    { R[31] = 0x800CD840u; R[7] = R[23] + R[0]; psx_next = 0x800277D4u; return; }  /* 0x800CD838 jal */
    { R[2] = R[0] + 8192; goto L_800CD84C; }  /* 0x800CD840 j */
L_800CD848:;
    R[2] = R[0] + 1;  /* 0x800CD848 */
L_800CD84C:;
    sh_(R[19], R[2]);  /* 0x800CD84C */
    R[19] = R[19] + 80;  /* 0x800CD850 */
    R[20] = R[20] + 1;  /* 0x800CD854 */
    R[2] = ((int32_t)R[20] < (int32_t)R[21]);  /* 0x800CD858 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 20; if (_c) { psx_bb(); goto L_800CD7B0; } }  /* 0x800CD85C */
L_800CD864:;
    R[2] = R[20] + R[0];  /* 0x800CD864 */
    R[31] = lw_(R[29] + 56);  /* 0x800CD868 */
    R[23] = lw_(R[29] + 52);  /* 0x800CD86C */
    R[22] = lw_(R[29] + 48);  /* 0x800CD870 */
    R[21] = lw_(R[29] + 44);  /* 0x800CD874 */
    R[20] = lw_(R[29] + 40);  /* 0x800CD878 */
    R[19] = lw_(R[29] + 36);  /* 0x800CD87C */
    R[18] = lw_(R[29] + 32);  /* 0x800CD880 */
    R[17] = lw_(R[29] + 28);  /* 0x800CD884 */
    R[16] = lw_(R[29] + 24);  /* 0x800CD888 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800CD88C jr ra */
}

void g0_800CD7B0(void) {
L_800CD7B0:;
    R[2] = lw_(R[22] + 72);  /* 0x800CD7B0 */
    R[2] = lh_(R[2]);  /* 0x800CD7B8 */
    R[2] = R[2] & 0x8000;  /* 0x800CD7C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_800CD84C; } }  /* 0x800CD7C4 */
    R[2] = (uint32_t)(int16_t)lh_(R[18] + 18);  /* 0x800CD7CC */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[22] + R[0]; if (_c) { goto L_800CD848; } }  /* 0x800CD7D4 */
    R[2] = lh_(R[17]);  /* 0x800CD7DC */
    sh_(R[16] + 24, R[2]);  /* 0x800CD7E4 */
    R[2] = lh_(R[17] + 2);  /* 0x800CD7E8 */
    sh_(R[16] + 26, R[2]);  /* 0x800CD7F0 */
    R[2] = lh_(R[17] + 4);  /* 0x800CD7F4 */
    sh_(R[16] + 28, R[2]);  /* 0x800CD7FC */
    R[2] = lh_(R[17] + 8);  /* 0x800CD800 */
    R[5] = R[18] + R[0];  /* 0x800CD804 */
    sh_(R[16] + 32, R[2]);  /* 0x800CD808 */
    R[2] = lh_(R[17] + 10);  /* 0x800CD80C */
    R[6] = R[16] + 24;  /* 0x800CD810 */
    sh_(R[16] + 34, R[2]);  /* 0x800CD814 */
    R[2] = lh_(R[17] + 12);  /* 0x800CD818 */
    R[7] = R[16] + R[0];  /* 0x800CD81C */
    sh_(R[16] + 36, R[2]);  /* 0x800CD820 */
    { R[31] = 0x800CD82Cu; sw_(R[29] + 16, R[23]); psx_next = 0x800AA0ECu; return; }  /* 0x800CD824 jal */
    R[4] = R[19] + R[0];  /* 0x800CD82C */
    R[5] = R[18] + R[0];  /* 0x800CD830 */
    R[6] = R[0] + R[0];  /* 0x800CD834 */
    { R[31] = 0x800CD840u; R[7] = R[23] + R[0]; psx_next = 0x800277D4u; return; }  /* 0x800CD838 jal */
    { R[2] = R[0] + 8192; goto L_800CD84C; }  /* 0x800CD840 j */
L_800CD848:;
    R[2] = R[0] + 1;  /* 0x800CD848 */
L_800CD84C:;
    sh_(R[19], R[2]);  /* 0x800CD84C */
    R[19] = R[19] + 80;  /* 0x800CD850 */
    R[20] = R[20] + 1;  /* 0x800CD854 */
    R[2] = ((int32_t)R[20] < (int32_t)R[21]);  /* 0x800CD858 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 20; if (_c) { psx_bb(); goto L_800CD7B0; } }  /* 0x800CD85C */
    R[2] = R[20] + R[0];  /* 0x800CD864 */
    R[31] = lw_(R[29] + 56);  /* 0x800CD868 */
    R[23] = lw_(R[29] + 52);  /* 0x800CD86C */
    R[22] = lw_(R[29] + 48);  /* 0x800CD870 */
    R[21] = lw_(R[29] + 44);  /* 0x800CD874 */
    R[20] = lw_(R[29] + 40);  /* 0x800CD878 */
    R[19] = lw_(R[29] + 36);  /* 0x800CD87C */
    R[18] = lw_(R[29] + 32);  /* 0x800CD880 */
    R[17] = lw_(R[29] + 28);  /* 0x800CD884 */
    R[16] = lw_(R[29] + 24);  /* 0x800CD888 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800CD88C jr ra */
}

void g0_800CD82C(void) {
    R[4] = R[19] + R[0];  /* 0x800CD82C */
    R[5] = R[18] + R[0];  /* 0x800CD830 */
    R[6] = R[0] + R[0];  /* 0x800CD834 */
    { R[31] = 0x800CD840u; R[7] = R[23] + R[0]; psx_next = 0x800277D4u; return; }  /* 0x800CD838 jal */
    { R[2] = R[0] + 8192; goto L_800CD84C; }  /* 0x800CD840 j */
    R[2] = R[0] + 1;  /* 0x800CD848 */
L_800CD84C:;
    sh_(R[19], R[2]);  /* 0x800CD84C */
    R[19] = R[19] + 80;  /* 0x800CD850 */
    R[20] = R[20] + 1;  /* 0x800CD854 */
    R[2] = ((int32_t)R[20] < (int32_t)R[21]);  /* 0x800CD858 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 20; if (_c) { psx_next = 0x800CD7B0u; return; } }  /* 0x800CD85C b extern */
    R[2] = R[20] + R[0];  /* 0x800CD864 */
    R[31] = lw_(R[29] + 56);  /* 0x800CD868 */
    R[23] = lw_(R[29] + 52);  /* 0x800CD86C */
    R[22] = lw_(R[29] + 48);  /* 0x800CD870 */
    R[21] = lw_(R[29] + 44);  /* 0x800CD874 */
    R[20] = lw_(R[29] + 40);  /* 0x800CD878 */
    R[19] = lw_(R[29] + 36);  /* 0x800CD87C */
    R[18] = lw_(R[29] + 32);  /* 0x800CD880 */
    R[17] = lw_(R[29] + 28);  /* 0x800CD884 */
    R[16] = lw_(R[29] + 24);  /* 0x800CD888 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800CD88C jr ra */
}

void g0_800CD840(void) {
    { R[2] = R[0] + 8192; goto L_800CD84C; }  /* 0x800CD840 j */
    R[2] = R[0] + 1;  /* 0x800CD848 */
L_800CD84C:;
    sh_(R[19], R[2]);  /* 0x800CD84C */
    R[19] = R[19] + 80;  /* 0x800CD850 */
    R[20] = R[20] + 1;  /* 0x800CD854 */
    R[2] = ((int32_t)R[20] < (int32_t)R[21]);  /* 0x800CD858 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 20; if (_c) { psx_next = 0x800CD7B0u; return; } }  /* 0x800CD85C b extern */
    R[2] = R[20] + R[0];  /* 0x800CD864 */
    R[31] = lw_(R[29] + 56);  /* 0x800CD868 */
    R[23] = lw_(R[29] + 52);  /* 0x800CD86C */
    R[22] = lw_(R[29] + 48);  /* 0x800CD870 */
    R[21] = lw_(R[29] + 44);  /* 0x800CD874 */
    R[20] = lw_(R[29] + 40);  /* 0x800CD878 */
    R[19] = lw_(R[29] + 36);  /* 0x800CD87C */
    R[18] = lw_(R[29] + 32);  /* 0x800CD880 */
    R[17] = lw_(R[29] + 28);  /* 0x800CD884 */
    R[16] = lw_(R[29] + 24);  /* 0x800CD888 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800CD88C jr ra */
}

void g0_800CD894(void) {
    R[29] = R[29] - 32;  /* 0x800CD894 */
    sw_(R[29] + 20, R[17]);  /* 0x800CD898 */
    R[17] = R[4] + R[0];  /* 0x800CD89C */
    R[6] = R[5] + R[0];  /* 0x800CD8A0 */
    R[4] = R[0] + R[0];  /* 0x800CD8A4 */
    sw_(R[29] + 24, R[31]);  /* 0x800CD8A8 */
    sw_(R[29] + 16, R[16]);  /* 0x800CD8AC */
    R[2] = lb_(R[17] + 585);  /* 0x800CD8B0 */
    R[7] = R[17] + 24;  /* 0x800CD8B4 */
    R[16] = R[2] << 3;  /* 0x800CD8B8 */
    R[16] = R[16] + R[2];  /* 0x800CD8BC */
    R[16] = R[16] << 3;  /* 0x800CD8C0 */
    R[2] = 0x8014u << 16;  /* 0x800CD8C4 */
    R[2] = R[2] + 19552;  /* 0x800CD8C8 */
    R[16] = R[16] + R[2];  /* 0x800CD8CC */
    { R[31] = 0x800CD8D8u; R[5] = R[16] + R[0]; psx_next = 0x800A5964u; return; }  /* 0x800CD8D0 jal */
    R[2] = R[0] + 75;  /* 0x800CD8D8 */
    sb_(R[16] + 52, R[2]);  /* 0x800CD8DC */
    sb_(R[16] + 53, R[2]);  /* 0x800CD8E0 */
    R[2] = R[0] + 25;  /* 0x800CD8E4 */
    sh_(R[17] + 598, R[2]);  /* 0x800CD8E8 */
    R[31] = lw_(R[29] + 24);  /* 0x800CD8EC */
    R[17] = lw_(R[29] + 20);  /* 0x800CD8F0 */
    R[16] = lw_(R[29] + 16);  /* 0x800CD8F4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CD8F8 jr ra */
}

void g0_800CD8D8(void) {
    R[2] = R[0] + 75;  /* 0x800CD8D8 */
    sb_(R[16] + 52, R[2]);  /* 0x800CD8DC */
    sb_(R[16] + 53, R[2]);  /* 0x800CD8E0 */
    R[2] = R[0] + 25;  /* 0x800CD8E4 */
    sh_(R[17] + 598, R[2]);  /* 0x800CD8E8 */
    R[31] = lw_(R[29] + 24);  /* 0x800CD8EC */
    R[17] = lw_(R[29] + 20);  /* 0x800CD8F0 */
    R[16] = lw_(R[29] + 16);  /* 0x800CD8F4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CD8F8 jr ra */
}

void g0_800CD900(void) {
    R[6] = R[4] + R[0];  /* 0x800CD900 */
    R[2] = lb_(R[6] + 585);  /* 0x800CD904 */
    R[3] = R[2] << 3;  /* 0x800CD90C */
    R[3] = R[3] + R[2];  /* 0x800CD910 */
    R[3] = R[3] << 3;  /* 0x800CD914 */
    R[2] = 0x8014u << 16;  /* 0x800CD918 */
    R[2] = R[2] + 19552;  /* 0x800CD91C */
    R[5] = R[3] + R[2];  /* 0x800CD920 */
    R[2] = R[0] + 2;  /* 0x800CD924 */
    sb_(R[5] + 3, R[2]);  /* 0x800CD928 */
    R[2] = 0x8008u << 16;  /* 0x800CD92C */
    R[3] = (uint32_t)(int16_t)lh_(R[6] + 6);  /* 0x800CD930 */
    R[2] = R[2] + 5492;  /* 0x800CD934 */
    R[3] = R[3] << 1;  /* 0x800CD938 */
    R[3] = R[3] + R[2];  /* 0x800CD93C */
    R[2] = lw_(R[6] + 128);  /* 0x800CD940 */
    R[3] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800CD944 */
    R[2] = R[2] << 4;  /* 0x800CD948 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CD94C */
    R[3] = LO;  /* 0x800CD950 */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800CD960; } }  /* 0x800CD954 */
    R[3] = R[3] + 255;  /* 0x800CD95C */
L_800CD960:;
    R[2] = lw_(R[6] + 24);  /* 0x800CD960 */
    R[3] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800CD964 */
    R[2] = R[2] + R[3];  /* 0x800CD968 */
    sw_(R[5] + 8, R[2]);  /* 0x800CD96C */
    R[4] = lw_(R[6] + 28);  /* 0x800CD970 */
    R[2] = lw_(R[6] + 200);  /* 0x800CD974 */
    R[3] = lh_(R[6] + 598);  /* 0x800CD978 */
    R[4] = R[4] + R[2];  /* 0x800CD97C */
    R[3] = R[3] << 16;  /* 0x800CD980 */
    R[2] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800CD984 */
    R[3] = R[3] >> 31;  /* 0x800CD988 */
    R[2] = R[2] + R[3];  /* 0x800CD98C */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x800CD990 */
    R[2] = R[2] << 12;  /* 0x800CD994 */
    R[2] = R[2] - R[4];  /* 0x800CD998 */
    sw_(R[5] + 12, R[2]);  /* 0x800CD99C */
    R[2] = 0x8008u << 16;  /* 0x800CD9A0 */
    R[3] = (uint32_t)(int16_t)lh_(R[6] + 6);  /* 0x800CD9A4 */
    R[2] = R[2] + 6516;  /* 0x800CD9A8 */
    R[3] = R[3] << 1;  /* 0x800CD9AC */
    R[3] = R[3] + R[2];  /* 0x800CD9B0 */
    R[2] = lw_(R[6] + 128);  /* 0x800CD9B4 */
    R[3] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800CD9B8 */
    R[2] = R[2] << 4;  /* 0x800CD9BC */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CD9C0 */
    R[3] = LO;  /* 0x800CD9C4 */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800CD9D4; } }  /* 0x800CD9C8 */
    R[3] = R[3] + 255;  /* 0x800CD9D0 */
L_800CD9D4:;
    R[2] = lw_(R[6] + 32);  /* 0x800CD9D4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800CD9D8 */
    R[2] = R[2] + R[3];  /* 0x800CD9DC */
    R[3] = lw_(R[5] + 44);  /* 0x800CD9E0 */
    sw_(R[5] + 16, R[2]);  /* 0x800CD9E4 */
    R[2] = 0xFF00u << 16;  /* 0x800CD9E8 */
    R[4] = R[3] & R[2];  /* 0x800CD9EC */
    sw_(R[5] + 44, R[4]);  /* 0x800CD9F0 */
    R[2] = lh_(R[6] + 582);  /* 0x800CD9F4 */
    R[2] = R[2] & 0x1;  /* 0x800CD9FC */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Fu << 16; if (_c) { goto L_800CDA28; } }  /* 0x800CDA00 */
    R[3] = 0x800Fu << 16;  /* 0x800CDA08 */
    R[2] = lb_(R[6] + 580);  /* 0x800CDA0C */
    R[3] = R[3] - 348;  /* 0x800CDA10 */
    R[2] = R[2] << 3;  /* 0x800CDA14 */
    R[2] = R[2] + R[3];  /* 0x800CDA18 */
    R[2] = lw_(R[2]);  /* 0x800CDA1C */
    { R[2] = R[4] | R[2]; goto L_800CDA48; }  /* 0x800CDA20 j */
L_800CDA28:;
    R[3] = lb_(R[6] + 580);  /* 0x800CDA28 */
    R[2] = R[2] - 348;  /* 0x800CDA2C */
    R[3] = R[3] << 3;  /* 0x800CDA30 */
    R[3] = R[3] | 0x4;  /* 0x800CDA34 */
    R[3] = R[3] + R[2];  /* 0x800CDA38 */
    R[2] = lw_(R[3]);  /* 0x800CDA3C */
    R[2] = R[4] | R[2];  /* 0x800CDA44 */
L_800CDA48:;
    { sw_(R[5] + 44, R[2]); psx_next = R[31]; return; }  /* 0x800CDA48 jr ra */
}

void g0_800CDA50(void) {
    R[29] = R[29] - 48;  /* 0x800CDA50 */
    sw_(R[29] + 32, R[16]);  /* 0x800CDA54 */
    R[16] = R[4] + R[0];  /* 0x800CDA58 */
    sw_(R[29] + 40, R[31]);  /* 0x800CDA5C */
    sw_(R[29] + 36, R[17]);  /* 0x800CDA60 */
    R[2] = lw_(R[16] + 24);  /* 0x800CDA64 */
    R[7] = R[5] + R[0];  /* 0x800CDA68 */
    sw_(R[29] + 16, R[2]);  /* 0x800CDA6C */
    R[2] = lw_(R[16] + 488);  /* 0x800CDA70 */
    R[4] = R[0] + R[0];  /* 0x800CDA74 */
    R[3] = R[2] >> 31;  /* 0x800CDA78 */
    R[2] = R[2] + R[3];  /* 0x800CDA7C */
    R[3] = lw_(R[16] + 28);  /* 0x800CDA80 */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x800CDA84 */
    R[3] = R[3] + R[2];  /* 0x800CDA88 */
    sw_(R[29] + 20, R[3]);  /* 0x800CDA8C */
    R[3] = R[6] << 3;  /* 0x800CDA90 */
    R[3] = R[3] + R[6];  /* 0x800CDA94 */
    R[3] = R[3] << 3;  /* 0x800CDA98 */
    R[6] = R[7] + R[0];  /* 0x800CDA9C */
    R[2] = lw_(R[16] + 32);  /* 0x800CDAA0 */
    R[7] = R[29] + 16;  /* 0x800CDAA4 */
    sw_(R[29] + 24, R[2]);  /* 0x800CDAA8 */
    R[2] = 0x8014u << 16;  /* 0x800CDAAC */
    R[2] = R[2] + 19552;  /* 0x800CDAB0 */
    R[17] = R[3] + R[2];  /* 0x800CDAB4 */
    { R[31] = 0x800CDAC0u; R[5] = R[17] + R[0]; psx_next = 0x800A5964u; return; }  /* 0x800CDAB8 jal */
    R[2] = lw_(R[16] + 488);  /* 0x800CDAC0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CDAD4; } }  /* 0x800CDAC8 */
    R[2] = R[2] + 4095;  /* 0x800CDAD0 */
L_800CDAD4:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CDAD4 */
    R[3] = R[2] + R[0];  /* 0x800CDAD8 */
    R[2] = R[2] << 16;  /* 0x800CDADC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CDAE0 */
    R[2] = ((int32_t)R[2] < 256);  /* 0x800CDAE4 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CDAF4; } }  /* 0x800CDAE8 */
    R[3] = R[0] + 255;  /* 0x800CDAF0 */
L_800CDAF4:;
    sb_(R[17] + 53, R[3]);  /* 0x800CDAF4 */
    sb_(R[17] + 52, R[3]);  /* 0x800CDAF8 */
    R[31] = lw_(R[29] + 40);  /* 0x800CDAFC */
    R[17] = lw_(R[29] + 36);  /* 0x800CDB00 */
    R[16] = lw_(R[29] + 32);  /* 0x800CDB04 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800CDB08 jr ra */
}

void g0_800CDAC0(void) {
    R[2] = lw_(R[16] + 488);  /* 0x800CDAC0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CDAD4; } }  /* 0x800CDAC8 */
    R[2] = R[2] + 4095;  /* 0x800CDAD0 */
L_800CDAD4:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CDAD4 */
    R[3] = R[2] + R[0];  /* 0x800CDAD8 */
    R[2] = R[2] << 16;  /* 0x800CDADC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CDAE0 */
    R[2] = ((int32_t)R[2] < 256);  /* 0x800CDAE4 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CDAF4; } }  /* 0x800CDAE8 */
    R[3] = R[0] + 255;  /* 0x800CDAF0 */
L_800CDAF4:;
    sb_(R[17] + 53, R[3]);  /* 0x800CDAF4 */
    sb_(R[17] + 52, R[3]);  /* 0x800CDAF8 */
    R[31] = lw_(R[29] + 40);  /* 0x800CDAFC */
    R[17] = lw_(R[29] + 36);  /* 0x800CDB00 */
    R[16] = lw_(R[29] + 32);  /* 0x800CDB04 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800CDB08 jr ra */
}

void g0_800CDB10(void) {
    R[2] = lb_(R[4] + 585);  /* 0x800CDB10 */
    R[3] = R[2] << 3;  /* 0x800CDB18 */
    R[3] = R[3] + R[2];  /* 0x800CDB1C */
    R[3] = R[3] << 3;  /* 0x800CDB20 */
    R[2] = 0x8014u << 16;  /* 0x800CDB24 */
    R[2] = R[2] + 19552;  /* 0x800CDB28 */
    R[6] = R[3] + R[2];  /* 0x800CDB2C */
    R[3] = lw_(R[6] + 44);  /* 0x800CDB30 */
    R[2] = R[0] + 2;  /* 0x800CDB34 */
    sb_(R[6] + 3, R[2]);  /* 0x800CDB38 */
    R[2] = 0xFF00u << 16;  /* 0x800CDB3C */
    R[7] = R[3] & R[2];  /* 0x800CDB40 */
    sw_(R[6] + 44, R[7]);  /* 0x800CDB44 */
    R[2] = lh_(R[4] + 582);  /* 0x800CDB48 */
    R[2] = R[2] & 0x1;  /* 0x800CDB50 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Fu << 16; if (_c) { goto L_800CDB7C; } }  /* 0x800CDB54 */
    R[3] = 0x800Fu << 16;  /* 0x800CDB5C */
    R[2] = lb_(R[4] + 580);  /* 0x800CDB60 */
    R[3] = R[3] - 348;  /* 0x800CDB64 */
    R[2] = R[2] << 3;  /* 0x800CDB68 */
    R[2] = R[2] + R[3];  /* 0x800CDB6C */
    R[2] = lw_(R[2]);  /* 0x800CDB70 */
    { R[2] = R[7] | R[2]; goto L_800CDB9C; }  /* 0x800CDB74 j */
L_800CDB7C:;
    R[3] = lb_(R[4] + 580);  /* 0x800CDB7C */
    R[2] = R[2] - 348;  /* 0x800CDB80 */
    R[3] = R[3] << 3;  /* 0x800CDB84 */
    R[3] = R[3] | 0x4;  /* 0x800CDB88 */
    R[3] = R[3] + R[2];  /* 0x800CDB8C */
    R[2] = lw_(R[3]);  /* 0x800CDB90 */
    R[2] = R[7] | R[2];  /* 0x800CDB98 */
L_800CDB9C:;
    sw_(R[6] + 44, R[2]);  /* 0x800CDB9C */
    R[2] = lw_(R[5] + 24);  /* 0x800CDBA0 */
    sw_(R[6] + 8, R[2]);  /* 0x800CDBA8 */
    R[3] = lw_(R[5] + 488);  /* 0x800CDBAC */
    R[2] = R[3] >> 31;  /* 0x800CDBB4 */
    R[3] = R[3] + R[2];  /* 0x800CDBB8 */
    R[2] = lw_(R[5] + 28);  /* 0x800CDBBC */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x800CDBC0 */
    R[2] = R[2] + R[3];  /* 0x800CDBC4 */
    R[2] = R[0] - R[2];  /* 0x800CDBC8 */
    sw_(R[6] + 12, R[2]);  /* 0x800CDBCC */
    R[2] = lw_(R[5] + 32);  /* 0x800CDBD0 */
    { sw_(R[6] + 16, R[2]); psx_next = R[31]; return; }  /* 0x800CDBD4 jr ra */
}

void g0_800CDBDC(void) {
    R[29] = R[29] - 56;  /* 0x800CDBDC */
    sw_(R[29] + 36, R[21]);  /* 0x800CDBE0 */
    R[21] = R[4] + R[0];  /* 0x800CDBE4 */
    sw_(R[29] + 40, R[22]);  /* 0x800CDBE8 */
    R[22] = R[5] + R[0];  /* 0x800CDBEC */
    sw_(R[29] + 44, R[23]);  /* 0x800CDBF0 */
    R[23] = R[0] + 6;  /* 0x800CDBF4 */
    sw_(R[29] + 24, R[18]);  /* 0x800CDBF8 */
    R[18] = R[0] + 44;  /* 0x800CDBFC */
    sw_(R[29] + 32, R[20]);  /* 0x800CDC00 */
    R[20] = R[0] - 16;  /* 0x800CDC04 */
    sw_(R[29] + 48, R[31]);  /* 0x800CDC08 */
    sw_(R[29] + 28, R[19]);  /* 0x800CDC0C */
    sw_(R[29] + 20, R[17]);  /* 0x800CDC10 */
    sw_(R[29] + 16, R[16]);  /* 0x800CDC14 */
    R[2] = lb_(R[21] + 585);  /* 0x800CDC18 */
    R[19] = R[0] + 1;  /* 0x800CDC1C */
    R[3] = R[2] << 3;  /* 0x800CDC20 */
    R[3] = R[3] + R[2];  /* 0x800CDC24 */
    R[3] = R[3] << 7;  /* 0x800CDC28 */
    R[2] = 0x8014u << 16;  /* 0x800CDC2C */
    R[2] = R[2] + 15160;  /* 0x800CDC30 */
    R[16] = R[3] + R[2];  /* 0x800CDC34 */
    R[17] = R[16] + 53;  /* 0x800CDC38 */
L_800CDC3C:;
    R[4] = R[0] + R[0];  /* 0x800CDC3C */
    R[5] = R[16] + R[0];  /* 0x800CDC40 */
    R[6] = R[22] + R[0];  /* 0x800CDC44 */
    { R[31] = 0x800CDC50u; R[7] = R[21] + 24; psx_next = 0x800A5964u; return; }  /* 0x800CDC48 jal */
    R[4] = R[16] + R[0];  /* 0x800CDC50 */
    R[5] = R[20] + R[0];  /* 0x800CDC54 */
    sb_(R[17] + -1, R[18]);  /* 0x800CDC58 */
    { R[31] = 0x800CDC64u; sb_(R[17], R[18]); psx_next = 0x800A72F8u; return; }  /* 0x800CDC5C jal */
    R[18] = R[18] - R[23];  /* 0x800CDC64 */
    R[20] = R[20] - 16;  /* 0x800CDC68 */
    R[17] = R[17] + 72;  /* 0x800CDC6C */
    R[19] = R[19] + 1;  /* 0x800CDC70 */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800CDC74 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 72; if (_c) { psx_bb(); goto L_800CDC3C; } }  /* 0x800CDC78 */
    R[31] = lw_(R[29] + 48);  /* 0x800CDC80 */
    R[23] = lw_(R[29] + 44);  /* 0x800CDC84 */
    R[22] = lw_(R[29] + 40);  /* 0x800CDC88 */
    R[21] = lw_(R[29] + 36);  /* 0x800CDC8C */
    R[20] = lw_(R[29] + 32);  /* 0x800CDC90 */
    R[19] = lw_(R[29] + 28);  /* 0x800CDC94 */
    R[18] = lw_(R[29] + 24);  /* 0x800CDC98 */
    R[17] = lw_(R[29] + 20);  /* 0x800CDC9C */
    R[16] = lw_(R[29] + 16);  /* 0x800CDCA0 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CDCA4 jr ra */
}

void g0_800CDC3C(void) {
L_800CDC3C:;
    R[4] = R[0] + R[0];  /* 0x800CDC3C */
    R[5] = R[16] + R[0];  /* 0x800CDC40 */
    R[6] = R[22] + R[0];  /* 0x800CDC44 */
    { R[31] = 0x800CDC50u; R[7] = R[21] + 24; psx_next = 0x800A5964u; return; }  /* 0x800CDC48 jal */
    R[4] = R[16] + R[0];  /* 0x800CDC50 */
    R[5] = R[20] + R[0];  /* 0x800CDC54 */
    sb_(R[17] + -1, R[18]);  /* 0x800CDC58 */
    { R[31] = 0x800CDC64u; sb_(R[17], R[18]); psx_next = 0x800A72F8u; return; }  /* 0x800CDC5C jal */
    R[18] = R[18] - R[23];  /* 0x800CDC64 */
    R[20] = R[20] - 16;  /* 0x800CDC68 */
    R[17] = R[17] + 72;  /* 0x800CDC6C */
    R[19] = R[19] + 1;  /* 0x800CDC70 */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800CDC74 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 72; if (_c) { psx_bb(); goto L_800CDC3C; } }  /* 0x800CDC78 */
    R[31] = lw_(R[29] + 48);  /* 0x800CDC80 */
    R[23] = lw_(R[29] + 44);  /* 0x800CDC84 */
    R[22] = lw_(R[29] + 40);  /* 0x800CDC88 */
    R[21] = lw_(R[29] + 36);  /* 0x800CDC8C */
    R[20] = lw_(R[29] + 32);  /* 0x800CDC90 */
    R[19] = lw_(R[29] + 28);  /* 0x800CDC94 */
    R[18] = lw_(R[29] + 24);  /* 0x800CDC98 */
    R[17] = lw_(R[29] + 20);  /* 0x800CDC9C */
    R[16] = lw_(R[29] + 16);  /* 0x800CDCA0 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CDCA4 jr ra */
}

void g0_800CDC50(void) {
    R[4] = R[16] + R[0];  /* 0x800CDC50 */
    R[5] = R[20] + R[0];  /* 0x800CDC54 */
    sb_(R[17] + -1, R[18]);  /* 0x800CDC58 */
    { R[31] = 0x800CDC64u; sb_(R[17], R[18]); psx_next = 0x800A72F8u; return; }  /* 0x800CDC5C jal */
    R[18] = R[18] - R[23];  /* 0x800CDC64 */
    R[20] = R[20] - 16;  /* 0x800CDC68 */
    R[17] = R[17] + 72;  /* 0x800CDC6C */
    R[19] = R[19] + 1;  /* 0x800CDC70 */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800CDC74 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 72; if (_c) { psx_next = 0x800CDC3Cu; return; } }  /* 0x800CDC78 b extern */
    R[31] = lw_(R[29] + 48);  /* 0x800CDC80 */
    R[23] = lw_(R[29] + 44);  /* 0x800CDC84 */
    R[22] = lw_(R[29] + 40);  /* 0x800CDC88 */
    R[21] = lw_(R[29] + 36);  /* 0x800CDC8C */
    R[20] = lw_(R[29] + 32);  /* 0x800CDC90 */
    R[19] = lw_(R[29] + 28);  /* 0x800CDC94 */
    R[18] = lw_(R[29] + 24);  /* 0x800CDC98 */
    R[17] = lw_(R[29] + 20);  /* 0x800CDC9C */
    R[16] = lw_(R[29] + 16);  /* 0x800CDCA0 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CDCA4 jr ra */
}

void g0_800CDC64(void) {
    R[18] = R[18] - R[23];  /* 0x800CDC64 */
    R[20] = R[20] - 16;  /* 0x800CDC68 */
    R[17] = R[17] + 72;  /* 0x800CDC6C */
    R[19] = R[19] + 1;  /* 0x800CDC70 */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800CDC74 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 72; if (_c) { psx_next = 0x800CDC3Cu; return; } }  /* 0x800CDC78 b extern */
    R[31] = lw_(R[29] + 48);  /* 0x800CDC80 */
    R[23] = lw_(R[29] + 44);  /* 0x800CDC84 */
    R[22] = lw_(R[29] + 40);  /* 0x800CDC88 */
    R[21] = lw_(R[29] + 36);  /* 0x800CDC8C */
    R[20] = lw_(R[29] + 32);  /* 0x800CDC90 */
    R[19] = lw_(R[29] + 28);  /* 0x800CDC94 */
    R[18] = lw_(R[29] + 24);  /* 0x800CDC98 */
    R[17] = lw_(R[29] + 20);  /* 0x800CDC9C */
    R[16] = lw_(R[29] + 16);  /* 0x800CDCA0 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CDCA4 jr ra */
}

void g0_800CDCAC(void) {
    R[3] = lw_(R[4] + 604);  /* 0x800CDCAC */
    psx_next = 0x800CDCB0u; return;  /* fallthrough */
}

void g0_800CDCB0(void) {
    R[29] = R[29] - 32;  /* 0x800CDCB0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[5] = R[3] + R[0]; if (_c) { goto L_800CDCC0; } }  /* 0x800CDCB4 */
    R[5] = R[3] + 7;  /* 0x800CDCBC */
L_800CDCC0:;
    R[2] = lw_(R[4] + 24);  /* 0x800CDCC0 */
    R[8] = (uint32_t)((int32_t)R[5] >> 3);  /* 0x800CDCC4 */
    sw_(R[29], R[2]);  /* 0x800CDCC8 */
    R[2] = lw_(R[4] + 28);  /* 0x800CDCCC */
    R[7] = R[3] - R[8];  /* 0x800CDCD0 */
    R[2] = R[0] - R[2];  /* 0x800CDCD4 */
    sw_(R[29] + 4, R[2]);  /* 0x800CDCD8 */
    R[2] = lw_(R[4] + 32);  /* 0x800CDCDC */
    R[6] = R[0] + 1;  /* 0x800CDCE0 */
    sw_(R[29] + 8, R[2]);  /* 0x800CDCE4 */
    R[3] = lb_(R[4] + 585);  /* 0x800CDCE8 */
    R[9] = R[0] + 4;  /* 0x800CDCEC */
    R[2] = R[3] << 3;  /* 0x800CDCF0 */
    R[2] = R[2] + R[3];  /* 0x800CDCF4 */
    R[2] = R[2] << 7;  /* 0x800CDCF8 */
    R[3] = 0x8014u << 16;  /* 0x800CDCFC */
    R[3] = R[3] + 15160;  /* 0x800CDD00 */
    R[2] = R[2] + R[3];  /* 0x800CDD04 */
    R[5] = R[2] + 16;  /* 0x800CDD08 */
L_800CDD0C:;
    R[3] = lw_(R[5] + -8);  /* 0x800CDD0C */
    R[2] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800CDD10 */
    sb_(R[5] + -13, R[9]);  /* 0x800CDD14 */
    sb_(R[5] + 36, R[2]);  /* 0x800CDD18 */
    sb_(R[5] + 37, R[2]);  /* 0x800CDD1C */
    sw_(R[29] + 16, R[3]);  /* 0x800CDD20 */
    R[2] = lw_(R[5] + -4);  /* 0x800CDD24 */
    R[3] = lw_(R[29]);  /* 0x800CDD28 */
    sw_(R[29] + 20, R[2]);  /* 0x800CDD2C */
    R[2] = lw_(R[5]);  /* 0x800CDD30 */
    sw_(R[29] + 24, R[2]);  /* 0x800CDD38 */
    sw_(R[5] + -8, R[3]);  /* 0x800CDD3C */
    R[2] = lw_(R[29] + 4);  /* 0x800CDD40 */
    R[7] = R[7] - R[8];  /* 0x800CDD44 */
    sw_(R[5] + -4, R[2]);  /* 0x800CDD48 */
    R[2] = lw_(R[29] + 8);  /* 0x800CDD4C */
    R[6] = R[6] + 1;  /* 0x800CDD50 */
    sw_(R[5], R[2]);  /* 0x800CDD54 */
    R[2] = lw_(R[29] + 16);  /* 0x800CDD58 */
    R[3] = lw_(R[29] + 20);  /* 0x800CDD5C */
    R[4] = lw_(R[29] + 24);  /* 0x800CDD60 */
    R[5] = R[5] + 72;  /* 0x800CDD64 */
    sw_(R[29], R[2]);  /* 0x800CDD68 */
    R[2] = ((int32_t)R[6] < 8);  /* 0x800CDD6C */
    sw_(R[29] + 4, R[3]);  /* 0x800CDD70 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[29] + 8, R[4]); if (_c) { psx_bb(); goto L_800CDD0C; } }  /* 0x800CDD74 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CDD7C jr ra */
}

void g0_800CDD84(void) {
    R[29] = R[29] - 40;  /* 0x800CDD84 */
    sw_(R[29] + 28, R[19]);  /* 0x800CDD88 */
    R[19] = R[4] + R[0];  /* 0x800CDD8C */
    R[2] = R[5] + R[0];  /* 0x800CDD90 */
    sw_(R[29] + 32, R[20]);  /* 0x800CDD94 */
    R[20] = R[6] + R[0];  /* 0x800CDD98 */
    R[6] = R[7] + R[0];  /* 0x800CDD9C */
    sw_(R[29] + 16, R[16]);  /* 0x800CDDA0 */
    R[16] = R[20] + R[0];  /* 0x800CDDA4 */
    sw_(R[29] + 36, R[31]);  /* 0x800CDDA8 */
    sw_(R[29] + 24, R[18]);  /* 0x800CDDAC */
    { uint32_t _c = (R[19] == R[0]); sw_(R[29] + 20, R[17]); if (_c) { goto L_800CDE30; } }  /* 0x800CDDB0 */
    R[4] = R[0] + R[0];  /* 0x800CDDB8 */
    R[5] = R[19] + R[0];  /* 0x800CDDBC */
    { R[31] = 0x800CDDC8u; R[7] = R[2] + R[0]; psx_next = 0x800A5964u; return; }  /* 0x800CDDC0 jal */
    { R[31] = 0x800CDDD0u; R[17] = 0x8001u << 16; psx_next = 0x80030E88u; return; }  /* 0x800CDDC8 jal */
    R[4] = R[16] & 0xFF;  /* 0x800CDDD0 */
    R[4] = R[4] << 1;  /* 0x800CDDD4 */
    { R[31] = 0x800CDDE0u; R[16] = R[2] & 0xFFF; psx_next = 0x800908F4u; return; }  /* 0x800CDDD8 jal */
    R[4] = R[16] + R[0];  /* 0x800CDDE0 */
    { R[31] = 0x800CDDECu; R[18] = R[2] << 12; psx_next = 0x80035B18u; return; }  /* 0x800CDDE4 jal */
    R[17] = R[17] | 0x28;  /* 0x800CDDEC */
    R[4] = R[2] + R[0];  /* 0x800CDDF0 */
    { uint32_t _t = R[17]; R[31] = 0x800CDDFCu; R[5] = R[18] + R[0]; psx_next = _t; return; }  /* 0x800CDDF4 jalr */
    R[3] = lw_(R[19] + 8);  /* 0x800CDDFC */
    R[4] = R[16] + R[0];  /* 0x800CDE00 */
    R[3] = R[3] + R[2];  /* 0x800CDE04 */
    { R[31] = 0x800CDE10u; sw_(R[19] + 8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CDE08 jal */
    R[4] = R[2] + R[0];  /* 0x800CDE10 */
    { uint32_t _t = R[17]; R[31] = 0x800CDE1Cu; R[5] = R[18] + R[0]; psx_next = _t; return; }  /* 0x800CDE14 jalr */
    R[3] = lw_(R[19] + 16);  /* 0x800CDE1C */
    sb_(R[19] + 52, R[20]);  /* 0x800CDE20 */
    sb_(R[19] + 53, R[20]);  /* 0x800CDE24 */
    R[3] = R[3] + R[2];  /* 0x800CDE28 */
    sw_(R[19] + 16, R[3]);  /* 0x800CDE2C */
L_800CDE30:;
    R[31] = lw_(R[29] + 36);  /* 0x800CDE30 */
    R[20] = lw_(R[29] + 32);  /* 0x800CDE34 */
    R[19] = lw_(R[29] + 28);  /* 0x800CDE38 */
    R[18] = lw_(R[29] + 24);  /* 0x800CDE3C */
    R[17] = lw_(R[29] + 20);  /* 0x800CDE40 */
    R[16] = lw_(R[29] + 16);  /* 0x800CDE44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CDE48 jr ra */
}

void g0_800CDDC8(void) {
    { R[31] = 0x800CDDD0u; R[17] = 0x8001u << 16; psx_next = 0x80030E88u; return; }  /* 0x800CDDC8 jal */
    R[4] = R[16] & 0xFF;  /* 0x800CDDD0 */
    R[4] = R[4] << 1;  /* 0x800CDDD4 */
    { R[31] = 0x800CDDE0u; R[16] = R[2] & 0xFFF; psx_next = 0x800908F4u; return; }  /* 0x800CDDD8 jal */
    R[4] = R[16] + R[0];  /* 0x800CDDE0 */
    { R[31] = 0x800CDDECu; R[18] = R[2] << 12; psx_next = 0x80035B18u; return; }  /* 0x800CDDE4 jal */
    R[17] = R[17] | 0x28;  /* 0x800CDDEC */
    R[4] = R[2] + R[0];  /* 0x800CDDF0 */
    { uint32_t _t = R[17]; R[31] = 0x800CDDFCu; R[5] = R[18] + R[0]; psx_next = _t; return; }  /* 0x800CDDF4 jalr */
    R[3] = lw_(R[19] + 8);  /* 0x800CDDFC */
    R[4] = R[16] + R[0];  /* 0x800CDE00 */
    R[3] = R[3] + R[2];  /* 0x800CDE04 */
    { R[31] = 0x800CDE10u; sw_(R[19] + 8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CDE08 jal */
    R[4] = R[2] + R[0];  /* 0x800CDE10 */
    { uint32_t _t = R[17]; R[31] = 0x800CDE1Cu; R[5] = R[18] + R[0]; psx_next = _t; return; }  /* 0x800CDE14 jalr */
    R[3] = lw_(R[19] + 16);  /* 0x800CDE1C */
    sb_(R[19] + 52, R[20]);  /* 0x800CDE20 */
    sb_(R[19] + 53, R[20]);  /* 0x800CDE24 */
    R[3] = R[3] + R[2];  /* 0x800CDE28 */
    sw_(R[19] + 16, R[3]);  /* 0x800CDE2C */
    R[31] = lw_(R[29] + 36);  /* 0x800CDE30 */
    R[20] = lw_(R[29] + 32);  /* 0x800CDE34 */
    R[19] = lw_(R[29] + 28);  /* 0x800CDE38 */
    R[18] = lw_(R[29] + 24);  /* 0x800CDE3C */
    R[17] = lw_(R[29] + 20);  /* 0x800CDE40 */
    R[16] = lw_(R[29] + 16);  /* 0x800CDE44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CDE48 jr ra */
}

void g0_800CDDD0(void) {
    R[4] = R[16] & 0xFF;  /* 0x800CDDD0 */
    R[4] = R[4] << 1;  /* 0x800CDDD4 */
    { R[31] = 0x800CDDE0u; R[16] = R[2] & 0xFFF; psx_next = 0x800908F4u; return; }  /* 0x800CDDD8 jal */
    R[4] = R[16] + R[0];  /* 0x800CDDE0 */
    { R[31] = 0x800CDDECu; R[18] = R[2] << 12; psx_next = 0x80035B18u; return; }  /* 0x800CDDE4 jal */
    R[17] = R[17] | 0x28;  /* 0x800CDDEC */
    R[4] = R[2] + R[0];  /* 0x800CDDF0 */
    { uint32_t _t = R[17]; R[31] = 0x800CDDFCu; R[5] = R[18] + R[0]; psx_next = _t; return; }  /* 0x800CDDF4 jalr */
    R[3] = lw_(R[19] + 8);  /* 0x800CDDFC */
    R[4] = R[16] + R[0];  /* 0x800CDE00 */
    R[3] = R[3] + R[2];  /* 0x800CDE04 */
    { R[31] = 0x800CDE10u; sw_(R[19] + 8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CDE08 jal */
    R[4] = R[2] + R[0];  /* 0x800CDE10 */
    { uint32_t _t = R[17]; R[31] = 0x800CDE1Cu; R[5] = R[18] + R[0]; psx_next = _t; return; }  /* 0x800CDE14 jalr */
    R[3] = lw_(R[19] + 16);  /* 0x800CDE1C */
    sb_(R[19] + 52, R[20]);  /* 0x800CDE20 */
    sb_(R[19] + 53, R[20]);  /* 0x800CDE24 */
    R[3] = R[3] + R[2];  /* 0x800CDE28 */
    sw_(R[19] + 16, R[3]);  /* 0x800CDE2C */
    R[31] = lw_(R[29] + 36);  /* 0x800CDE30 */
    R[20] = lw_(R[29] + 32);  /* 0x800CDE34 */
    R[19] = lw_(R[29] + 28);  /* 0x800CDE38 */
    R[18] = lw_(R[29] + 24);  /* 0x800CDE3C */
    R[17] = lw_(R[29] + 20);  /* 0x800CDE40 */
    R[16] = lw_(R[29] + 16);  /* 0x800CDE44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CDE48 jr ra */
}

void g0_800CDDE0(void) {
    R[4] = R[16] + R[0];  /* 0x800CDDE0 */
    { R[31] = 0x800CDDECu; R[18] = R[2] << 12; psx_next = 0x80035B18u; return; }  /* 0x800CDDE4 jal */
    R[17] = R[17] | 0x28;  /* 0x800CDDEC */
    R[4] = R[2] + R[0];  /* 0x800CDDF0 */
    { uint32_t _t = R[17]; R[31] = 0x800CDDFCu; R[5] = R[18] + R[0]; psx_next = _t; return; }  /* 0x800CDDF4 jalr */
    R[3] = lw_(R[19] + 8);  /* 0x800CDDFC */
    R[4] = R[16] + R[0];  /* 0x800CDE00 */
    R[3] = R[3] + R[2];  /* 0x800CDE04 */
    { R[31] = 0x800CDE10u; sw_(R[19] + 8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CDE08 jal */
    R[4] = R[2] + R[0];  /* 0x800CDE10 */
    { uint32_t _t = R[17]; R[31] = 0x800CDE1Cu; R[5] = R[18] + R[0]; psx_next = _t; return; }  /* 0x800CDE14 jalr */
    R[3] = lw_(R[19] + 16);  /* 0x800CDE1C */
    sb_(R[19] + 52, R[20]);  /* 0x800CDE20 */
    sb_(R[19] + 53, R[20]);  /* 0x800CDE24 */
    R[3] = R[3] + R[2];  /* 0x800CDE28 */
    sw_(R[19] + 16, R[3]);  /* 0x800CDE2C */
    R[31] = lw_(R[29] + 36);  /* 0x800CDE30 */
    R[20] = lw_(R[29] + 32);  /* 0x800CDE34 */
    R[19] = lw_(R[29] + 28);  /* 0x800CDE38 */
    R[18] = lw_(R[29] + 24);  /* 0x800CDE3C */
    R[17] = lw_(R[29] + 20);  /* 0x800CDE40 */
    R[16] = lw_(R[29] + 16);  /* 0x800CDE44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CDE48 jr ra */
}

void g0_800CDDEC(void) {
    R[17] = R[17] | 0x28;  /* 0x800CDDEC */
    R[4] = R[2] + R[0];  /* 0x800CDDF0 */
    { uint32_t _t = R[17]; R[31] = 0x800CDDFCu; R[5] = R[18] + R[0]; psx_next = _t; return; }  /* 0x800CDDF4 jalr */
    R[3] = lw_(R[19] + 8);  /* 0x800CDDFC */
    R[4] = R[16] + R[0];  /* 0x800CDE00 */
    R[3] = R[3] + R[2];  /* 0x800CDE04 */
    { R[31] = 0x800CDE10u; sw_(R[19] + 8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CDE08 jal */
    R[4] = R[2] + R[0];  /* 0x800CDE10 */
    { uint32_t _t = R[17]; R[31] = 0x800CDE1Cu; R[5] = R[18] + R[0]; psx_next = _t; return; }  /* 0x800CDE14 jalr */
    R[3] = lw_(R[19] + 16);  /* 0x800CDE1C */
    sb_(R[19] + 52, R[20]);  /* 0x800CDE20 */
    sb_(R[19] + 53, R[20]);  /* 0x800CDE24 */
    R[3] = R[3] + R[2];  /* 0x800CDE28 */
    sw_(R[19] + 16, R[3]);  /* 0x800CDE2C */
    R[31] = lw_(R[29] + 36);  /* 0x800CDE30 */
    R[20] = lw_(R[29] + 32);  /* 0x800CDE34 */
    R[19] = lw_(R[29] + 28);  /* 0x800CDE38 */
    R[18] = lw_(R[29] + 24);  /* 0x800CDE3C */
    R[17] = lw_(R[29] + 20);  /* 0x800CDE40 */
    R[16] = lw_(R[29] + 16);  /* 0x800CDE44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CDE48 jr ra */
}

void g0_800CDDFC(void) {
    R[3] = lw_(R[19] + 8);  /* 0x800CDDFC */
    R[4] = R[16] + R[0];  /* 0x800CDE00 */
    R[3] = R[3] + R[2];  /* 0x800CDE04 */
    { R[31] = 0x800CDE10u; sw_(R[19] + 8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CDE08 jal */
    R[4] = R[2] + R[0];  /* 0x800CDE10 */
    { uint32_t _t = R[17]; R[31] = 0x800CDE1Cu; R[5] = R[18] + R[0]; psx_next = _t; return; }  /* 0x800CDE14 jalr */
    R[3] = lw_(R[19] + 16);  /* 0x800CDE1C */
    sb_(R[19] + 52, R[20]);  /* 0x800CDE20 */
    sb_(R[19] + 53, R[20]);  /* 0x800CDE24 */
    R[3] = R[3] + R[2];  /* 0x800CDE28 */
    sw_(R[19] + 16, R[3]);  /* 0x800CDE2C */
    R[31] = lw_(R[29] + 36);  /* 0x800CDE30 */
    R[20] = lw_(R[29] + 32);  /* 0x800CDE34 */
    R[19] = lw_(R[29] + 28);  /* 0x800CDE38 */
    R[18] = lw_(R[29] + 24);  /* 0x800CDE3C */
    R[17] = lw_(R[29] + 20);  /* 0x800CDE40 */
    R[16] = lw_(R[29] + 16);  /* 0x800CDE44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CDE48 jr ra */
}

void g0_800CDE10(void) {
    R[4] = R[2] + R[0];  /* 0x800CDE10 */
    { uint32_t _t = R[17]; R[31] = 0x800CDE1Cu; R[5] = R[18] + R[0]; psx_next = _t; return; }  /* 0x800CDE14 jalr */
    R[3] = lw_(R[19] + 16);  /* 0x800CDE1C */
    sb_(R[19] + 52, R[20]);  /* 0x800CDE20 */
    sb_(R[19] + 53, R[20]);  /* 0x800CDE24 */
    R[3] = R[3] + R[2];  /* 0x800CDE28 */
    sw_(R[19] + 16, R[3]);  /* 0x800CDE2C */
    R[31] = lw_(R[29] + 36);  /* 0x800CDE30 */
    R[20] = lw_(R[29] + 32);  /* 0x800CDE34 */
    R[19] = lw_(R[29] + 28);  /* 0x800CDE38 */
    R[18] = lw_(R[29] + 24);  /* 0x800CDE3C */
    R[17] = lw_(R[29] + 20);  /* 0x800CDE40 */
    R[16] = lw_(R[29] + 16);  /* 0x800CDE44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CDE48 jr ra */
}

void g0_800CDE1C(void) {
    R[3] = lw_(R[19] + 16);  /* 0x800CDE1C */
    sb_(R[19] + 52, R[20]);  /* 0x800CDE20 */
    sb_(R[19] + 53, R[20]);  /* 0x800CDE24 */
    R[3] = R[3] + R[2];  /* 0x800CDE28 */
    sw_(R[19] + 16, R[3]);  /* 0x800CDE2C */
    R[31] = lw_(R[29] + 36);  /* 0x800CDE30 */
    R[20] = lw_(R[29] + 32);  /* 0x800CDE34 */
    R[19] = lw_(R[29] + 28);  /* 0x800CDE38 */
    R[18] = lw_(R[29] + 24);  /* 0x800CDE3C */
    R[17] = lw_(R[29] + 20);  /* 0x800CDE40 */
    R[16] = lw_(R[29] + 16);  /* 0x800CDE44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CDE48 jr ra */
}

void g0_800CDE50(void) {
    R[8] = R[4] + R[0];  /* 0x800CDE50 */
    { uint32_t _c = ((int32_t)R[5] <= 0); R[7] = R[0] + R[0]; if (_c) { goto L_800CDEC4; } }  /* 0x800CDE54 */
    R[9] = R[0] + 2;  /* 0x800CDE5C */
    R[4] = R[4] + 2;  /* 0x800CDE60 */
L_800CDE64:;
    R[2] = lb_(R[4]);  /* 0x800CDE64 */
    R[2] = R[2] & 0x1;  /* 0x800CDE6C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CDEB0; } }  /* 0x800CDE70 */
    R[2] = lw_(R[4] + 22);  /* 0x800CDE78 */
    R[3] = lb_(R[4] + 50);  /* 0x800CDE7C */
    sb_(R[4] + 1, R[9]);  /* 0x800CDE80 */
    R[2] = R[2] + R[6];  /* 0x800CDE84 */
    sw_(R[4] + 22, R[2]);  /* 0x800CDE88 */
    R[2] = lb_(R[4] + 51);  /* 0x800CDE8C */
    R[3] = R[3] - 1;  /* 0x800CDE90 */
    sb_(R[4] + 50, R[3]);  /* 0x800CDE94 */
    R[3] = R[3] & 0xFF;  /* 0x800CDE98 */
    R[2] = R[2] - 1;  /* 0x800CDE9C */
    { uint32_t _c = (R[3] != R[0]); sb_(R[4] + 51, R[2]); if (_c) { goto L_800CDEB0; } }  /* 0x800CDEA0 */
    sh_(R[8], R[0]);  /* 0x800CDEA8 */
    sb_(R[4], R[0]);  /* 0x800CDEAC */
L_800CDEB0:;
    R[4] = R[4] + 72;  /* 0x800CDEB0 */
    R[7] = R[7] + 1;  /* 0x800CDEB4 */
    R[2] = ((int32_t)R[7] < (int32_t)R[5]);  /* 0x800CDEB8 */
    { uint32_t _c = (R[2] != R[0]); R[8] = R[8] + 72; if (_c) { psx_bb(); goto L_800CDE64; } }  /* 0x800CDEBC */
L_800CDEC4:;
    { psx_next = R[31]; return; }  /* 0x800CDEC4 jr ra */
}

void g0_800CDECC(void) {
    R[29] = R[29] - 56;  /* 0x800CDECC */
    sw_(R[29] + 48, R[30]);  /* 0x800CDED0 */
    R[30] = R[4] + R[0];  /* 0x800CDED4 */
    sw_(R[29] + 40, R[22]);  /* 0x800CDED8 */
    R[22] = R[6] + R[0];  /* 0x800CDEDC */
    R[4] = R[0] + 512;  /* 0x800CDEE0 */
    sw_(R[29] + 52, R[31]);  /* 0x800CDEE4 */
    sw_(R[29] + 44, R[23]);  /* 0x800CDEE8 */
    sw_(R[29] + 36, R[21]);  /* 0x800CDEEC */
    sw_(R[29] + 32, R[20]);  /* 0x800CDEF0 */
    sw_(R[29] + 28, R[19]);  /* 0x800CDEF4 */
    sw_(R[29] + 24, R[18]);  /* 0x800CDEF8 */
    sw_(R[29] + 20, R[17]);  /* 0x800CDEFC */
    sw_(R[29] + 16, R[16]);  /* 0x800CDF00 */
    sw_(R[29] + 60, R[5]);  /* 0x800CDF04 */
    R[2] = lb_(R[30] + 585);  /* 0x800CDF08 */
    R[23] = R[0] + R[0];  /* 0x800CDF0C */
    R[3] = R[2] << 3;  /* 0x800CDF10 */
    R[3] = R[3] + R[2];  /* 0x800CDF14 */
    R[3] = R[3] << 7;  /* 0x800CDF18 */
    R[2] = 0x8014u << 16;  /* 0x800CDF1C */
    R[2] = R[2] + 15160;  /* 0x800CDF20 */
    { R[31] = 0x800CDF2Cu; R[20] = R[3] + R[2]; psx_next = 0x800908F4u; return; }  /* 0x800CDF24 jal */
    R[21] = R[2] + R[0];  /* 0x800CDF2C */
    R[17] = R[20] + 40;  /* 0x800CDF30 */
L_800CDF34:;
    R[4] = R[0] + R[0];  /* 0x800CDF34 */
    R[5] = R[20] + R[0];  /* 0x800CDF38 */
    R[6] = lw_(R[29] + 60);  /* 0x800CDF3C */
    { R[31] = 0x800CDF48u; R[7] = R[30] + 24; psx_next = 0x800A5964u; return; }  /* 0x800CDF40 jal */
    R[4] = R[0] + 8192;  /* 0x800CDF48 */
    R[2] = R[0] + 8;  /* 0x800CDF4C */
    sb_(R[17] + -37, R[2]);  /* 0x800CDF50 */
    R[2] = R[0] + 25;  /* 0x800CDF54 */
    sb_(R[17] + 12, R[2]);  /* 0x800CDF58 */
    { R[31] = 0x800CDF64u; sb_(R[17] + 13, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800CDF5C jal */
    R[4] = R[21] << 1;  /* 0x800CDF64 */
    R[8] = 0x8008u << 16;  /* 0x800CDF68 */
    R[8] = R[8] + 5492;  /* 0x800CDF6C */
    R[3] = R[4] + R[8];  /* 0x800CDF70 */
    R[18] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800CDF74 */
    R[16] = R[2] + R[0];  /* 0x800CDF78 */
    { int64_t _p = (int64_t)(int32_t)R[18] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CDF7C */
    R[3] = LO;  /* 0x800CDF80 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[8] = 0x8008u << 16; if (_c) { goto L_800CDF90; } }  /* 0x800CDF84 */
    R[3] = R[3] + 255;  /* 0x800CDF8C */
L_800CDF90:;
    R[8] = R[8] + 6516;  /* 0x800CDF90 */
    R[2] = R[4] + R[8];  /* 0x800CDF94 */
    R[19] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CDF98 */
    { int64_t _p = (int64_t)(int32_t)R[19] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CDFA0 */
    R[2] = lw_(R[17] + -32);  /* 0x800CDFA4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800CDFA8 */
    R[2] = R[2] + R[3];  /* 0x800CDFAC */
    R[5] = LO;  /* 0x800CDFB0 */
    { uint32_t _c = ((int32_t)R[5] >= 0); sw_(R[17] + -32, R[2]); if (_c) { goto L_800CDFC0; } }  /* 0x800CDFB4 */
    R[5] = R[5] + 255;  /* 0x800CDFBC */
L_800CDFC0:;
    R[4] = R[0] + 24576;  /* 0x800CDFC0 */
    R[2] = lw_(R[17] + -24);  /* 0x800CDFC4 */
    R[3] = (uint32_t)((int32_t)R[5] >> 8);  /* 0x800CDFC8 */
    R[2] = R[2] + R[3];  /* 0x800CDFCC */
    { R[31] = 0x800CDFD8u; sw_(R[17] + -24, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800CDFD0 jal */
    R[16] = R[2] + 8192;  /* 0x800CDFD8 */
    { int64_t _p = (int64_t)(int32_t)R[18] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CDFDC */
    R[2] = LO;  /* 0x800CDFE0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[4] = R[22] >> 31; if (_c) { goto L_800CDFF0; } }  /* 0x800CDFE4 */
    R[2] = R[2] + 255;  /* 0x800CDFEC */
L_800CDFF0:;
    R[4] = R[22] + R[4];  /* 0x800CDFF0 */
    R[4] = (uint32_t)((int32_t)R[4] >> 1);  /* 0x800CDFF4 */
    R[4] = R[4] << 12;  /* 0x800CDFF8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 8);  /* 0x800CDFFC */
    { R[31] = 0x800CE008u; sw_(R[17] + -8, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800CE000 jal */
    { int64_t _p = (int64_t)(int32_t)R[19] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CE008 */
    R[2] = R[0] - R[2];  /* 0x800CE00C */
    R[3] = LO;  /* 0x800CE010 */
    { uint32_t _c = ((int32_t)R[3] >= 0); sw_(R[17] + -4, R[2]); if (_c) { goto L_800CE020; } }  /* 0x800CE014 */
    R[3] = R[3] + 255;  /* 0x800CE01C */
L_800CE020:;
    R[2] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800CE020 */
    sw_(R[17], R[2]);  /* 0x800CE024 */
    R[2] = R[21] + 64;  /* 0x800CE028 */
    R[21] = R[2] & 0x1FF;  /* 0x800CE02C */
    R[17] = R[17] + 72;  /* 0x800CE030 */
    R[23] = R[23] + 1;  /* 0x800CE034 */
    R[2] = ((int32_t)R[23] < 8);  /* 0x800CE038 */
    { uint32_t _c = (R[2] != R[0]); R[20] = R[20] + 72; if (_c) { psx_bb(); goto L_800CDF34; } }  /* 0x800CE03C */
    R[4] = R[0] - 128;  /* 0x800CE044 */
    psx_div((int32_t)R[4], (int32_t)R[22]);  /* 0x800CE048 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE058; } }  /* 0x800CE04C */
    psx_break(7168);  /* 0x800CE054 */
L_800CE058:;
    R[1] = R[0] - 1;  /* 0x800CE058 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE070; } }  /* 0x800CE05C */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CE070; } }  /* 0x800CE064 */
    psx_break(6144);  /* 0x800CE06C */
L_800CE070:;
    R[4] = LO;  /* 0x800CE070 */
    R[3] = R[0] + 25;  /* 0x800CE074 */
    psx_div((int32_t)R[3], (int32_t)R[22]);  /* 0x800CE07C */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE08C; } }  /* 0x800CE080 */
    psx_break(7168);  /* 0x800CE088 */
L_800CE08C:;
    R[1] = R[0] - 1;  /* 0x800CE08C */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE0A4; } }  /* 0x800CE090 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CE0A4; } }  /* 0x800CE098 */
    psx_break(6144);  /* 0x800CE0A0 */
L_800CE0A4:;
    R[3] = LO;  /* 0x800CE0A4 */
    R[2] = R[0] - 8192;  /* 0x800CE0A8 */
    psx_div((int32_t)R[2], (int32_t)R[22]);  /* 0x800CE0B0 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE0C0; } }  /* 0x800CE0B4 */
    psx_break(7168);  /* 0x800CE0BC */
L_800CE0C0:;
    R[1] = R[0] - 1;  /* 0x800CE0C0 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE0D8; } }  /* 0x800CE0C4 */
    { uint32_t _c = (R[2] != R[1]); if (_c) { goto L_800CE0D8; } }  /* 0x800CE0CC */
    psx_break(6144);  /* 0x800CE0D4 */
L_800CE0D8:;
    R[2] = LO;  /* 0x800CE0D8 */
    sh_(R[30] + 592, R[4]);  /* 0x800CE0DC */
    sh_(R[30] + 594, R[3]);  /* 0x800CE0E0 */
    sw_(R[30] + 588, R[2]);  /* 0x800CE0E4 */
    R[31] = lw_(R[29] + 52);  /* 0x800CE0E8 */
    R[30] = lw_(R[29] + 48);  /* 0x800CE0EC */
    R[23] = lw_(R[29] + 44);  /* 0x800CE0F0 */
    R[22] = lw_(R[29] + 40);  /* 0x800CE0F4 */
    R[21] = lw_(R[29] + 36);  /* 0x800CE0F8 */
    R[20] = lw_(R[29] + 32);  /* 0x800CE0FC */
    R[19] = lw_(R[29] + 28);  /* 0x800CE100 */
    R[18] = lw_(R[29] + 24);  /* 0x800CE104 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE108 */
    R[16] = lw_(R[29] + 16);  /* 0x800CE10C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CE110 jr ra */
}

void g0_800CDF2C(void) {
    R[21] = R[2] + R[0];  /* 0x800CDF2C */
    R[17] = R[20] + 40;  /* 0x800CDF30 */
L_800CDF34:;
    R[4] = R[0] + R[0];  /* 0x800CDF34 */
    R[5] = R[20] + R[0];  /* 0x800CDF38 */
    R[6] = lw_(R[29] + 60);  /* 0x800CDF3C */
    { R[31] = 0x800CDF48u; R[7] = R[30] + 24; psx_next = 0x800A5964u; return; }  /* 0x800CDF40 jal */
    R[4] = R[0] + 8192;  /* 0x800CDF48 */
    R[2] = R[0] + 8;  /* 0x800CDF4C */
    sb_(R[17] + -37, R[2]);  /* 0x800CDF50 */
    R[2] = R[0] + 25;  /* 0x800CDF54 */
    sb_(R[17] + 12, R[2]);  /* 0x800CDF58 */
    { R[31] = 0x800CDF64u; sb_(R[17] + 13, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800CDF5C jal */
    R[4] = R[21] << 1;  /* 0x800CDF64 */
    R[8] = 0x8008u << 16;  /* 0x800CDF68 */
    R[8] = R[8] + 5492;  /* 0x800CDF6C */
    R[3] = R[4] + R[8];  /* 0x800CDF70 */
    R[18] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800CDF74 */
    R[16] = R[2] + R[0];  /* 0x800CDF78 */
    { int64_t _p = (int64_t)(int32_t)R[18] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CDF7C */
    R[3] = LO;  /* 0x800CDF80 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[8] = 0x8008u << 16; if (_c) { goto L_800CDF90; } }  /* 0x800CDF84 */
    R[3] = R[3] + 255;  /* 0x800CDF8C */
L_800CDF90:;
    R[8] = R[8] + 6516;  /* 0x800CDF90 */
    R[2] = R[4] + R[8];  /* 0x800CDF94 */
    R[19] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CDF98 */
    { int64_t _p = (int64_t)(int32_t)R[19] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CDFA0 */
    R[2] = lw_(R[17] + -32);  /* 0x800CDFA4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800CDFA8 */
    R[2] = R[2] + R[3];  /* 0x800CDFAC */
    R[5] = LO;  /* 0x800CDFB0 */
    { uint32_t _c = ((int32_t)R[5] >= 0); sw_(R[17] + -32, R[2]); if (_c) { goto L_800CDFC0; } }  /* 0x800CDFB4 */
    R[5] = R[5] + 255;  /* 0x800CDFBC */
L_800CDFC0:;
    R[4] = R[0] + 24576;  /* 0x800CDFC0 */
    R[2] = lw_(R[17] + -24);  /* 0x800CDFC4 */
    R[3] = (uint32_t)((int32_t)R[5] >> 8);  /* 0x800CDFC8 */
    R[2] = R[2] + R[3];  /* 0x800CDFCC */
    { R[31] = 0x800CDFD8u; sw_(R[17] + -24, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800CDFD0 jal */
    R[16] = R[2] + 8192;  /* 0x800CDFD8 */
    { int64_t _p = (int64_t)(int32_t)R[18] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CDFDC */
    R[2] = LO;  /* 0x800CDFE0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[4] = R[22] >> 31; if (_c) { goto L_800CDFF0; } }  /* 0x800CDFE4 */
    R[2] = R[2] + 255;  /* 0x800CDFEC */
L_800CDFF0:;
    R[4] = R[22] + R[4];  /* 0x800CDFF0 */
    R[4] = (uint32_t)((int32_t)R[4] >> 1);  /* 0x800CDFF4 */
    R[4] = R[4] << 12;  /* 0x800CDFF8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 8);  /* 0x800CDFFC */
    { R[31] = 0x800CE008u; sw_(R[17] + -8, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800CE000 jal */
    { int64_t _p = (int64_t)(int32_t)R[19] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CE008 */
    R[2] = R[0] - R[2];  /* 0x800CE00C */
    R[3] = LO;  /* 0x800CE010 */
    { uint32_t _c = ((int32_t)R[3] >= 0); sw_(R[17] + -4, R[2]); if (_c) { goto L_800CE020; } }  /* 0x800CE014 */
    R[3] = R[3] + 255;  /* 0x800CE01C */
L_800CE020:;
    R[2] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800CE020 */
    sw_(R[17], R[2]);  /* 0x800CE024 */
    R[2] = R[21] + 64;  /* 0x800CE028 */
    R[21] = R[2] & 0x1FF;  /* 0x800CE02C */
    R[17] = R[17] + 72;  /* 0x800CE030 */
    R[23] = R[23] + 1;  /* 0x800CE034 */
    R[2] = ((int32_t)R[23] < 8);  /* 0x800CE038 */
    { uint32_t _c = (R[2] != R[0]); R[20] = R[20] + 72; if (_c) { psx_bb(); goto L_800CDF34; } }  /* 0x800CE03C */
    R[4] = R[0] - 128;  /* 0x800CE044 */
    psx_div((int32_t)R[4], (int32_t)R[22]);  /* 0x800CE048 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE058; } }  /* 0x800CE04C */
    psx_break(7168);  /* 0x800CE054 */
L_800CE058:;
    R[1] = R[0] - 1;  /* 0x800CE058 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE070; } }  /* 0x800CE05C */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CE070; } }  /* 0x800CE064 */
    psx_break(6144);  /* 0x800CE06C */
L_800CE070:;
    R[4] = LO;  /* 0x800CE070 */
    R[3] = R[0] + 25;  /* 0x800CE074 */
    psx_div((int32_t)R[3], (int32_t)R[22]);  /* 0x800CE07C */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE08C; } }  /* 0x800CE080 */
    psx_break(7168);  /* 0x800CE088 */
L_800CE08C:;
    R[1] = R[0] - 1;  /* 0x800CE08C */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE0A4; } }  /* 0x800CE090 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CE0A4; } }  /* 0x800CE098 */
    psx_break(6144);  /* 0x800CE0A0 */
L_800CE0A4:;
    R[3] = LO;  /* 0x800CE0A4 */
    R[2] = R[0] - 8192;  /* 0x800CE0A8 */
    psx_div((int32_t)R[2], (int32_t)R[22]);  /* 0x800CE0B0 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE0C0; } }  /* 0x800CE0B4 */
    psx_break(7168);  /* 0x800CE0BC */
L_800CE0C0:;
    R[1] = R[0] - 1;  /* 0x800CE0C0 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE0D8; } }  /* 0x800CE0C4 */
    { uint32_t _c = (R[2] != R[1]); if (_c) { goto L_800CE0D8; } }  /* 0x800CE0CC */
    psx_break(6144);  /* 0x800CE0D4 */
L_800CE0D8:;
    R[2] = LO;  /* 0x800CE0D8 */
    sh_(R[30] + 592, R[4]);  /* 0x800CE0DC */
    sh_(R[30] + 594, R[3]);  /* 0x800CE0E0 */
    sw_(R[30] + 588, R[2]);  /* 0x800CE0E4 */
    R[31] = lw_(R[29] + 52);  /* 0x800CE0E8 */
    R[30] = lw_(R[29] + 48);  /* 0x800CE0EC */
    R[23] = lw_(R[29] + 44);  /* 0x800CE0F0 */
    R[22] = lw_(R[29] + 40);  /* 0x800CE0F4 */
    R[21] = lw_(R[29] + 36);  /* 0x800CE0F8 */
    R[20] = lw_(R[29] + 32);  /* 0x800CE0FC */
    R[19] = lw_(R[29] + 28);  /* 0x800CE100 */
    R[18] = lw_(R[29] + 24);  /* 0x800CE104 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE108 */
    R[16] = lw_(R[29] + 16);  /* 0x800CE10C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CE110 jr ra */
}

void g0_800CDF34(void) {
L_800CDF34:;
    R[4] = R[0] + R[0];  /* 0x800CDF34 */
    R[5] = R[20] + R[0];  /* 0x800CDF38 */
    R[6] = lw_(R[29] + 60);  /* 0x800CDF3C */
    { R[31] = 0x800CDF48u; R[7] = R[30] + 24; psx_next = 0x800A5964u; return; }  /* 0x800CDF40 jal */
    R[4] = R[0] + 8192;  /* 0x800CDF48 */
    R[2] = R[0] + 8;  /* 0x800CDF4C */
    sb_(R[17] + -37, R[2]);  /* 0x800CDF50 */
    R[2] = R[0] + 25;  /* 0x800CDF54 */
    sb_(R[17] + 12, R[2]);  /* 0x800CDF58 */
    { R[31] = 0x800CDF64u; sb_(R[17] + 13, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800CDF5C jal */
    R[4] = R[21] << 1;  /* 0x800CDF64 */
    R[8] = 0x8008u << 16;  /* 0x800CDF68 */
    R[8] = R[8] + 5492;  /* 0x800CDF6C */
    R[3] = R[4] + R[8];  /* 0x800CDF70 */
    R[18] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800CDF74 */
    R[16] = R[2] + R[0];  /* 0x800CDF78 */
    { int64_t _p = (int64_t)(int32_t)R[18] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CDF7C */
    R[3] = LO;  /* 0x800CDF80 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[8] = 0x8008u << 16; if (_c) { goto L_800CDF90; } }  /* 0x800CDF84 */
    R[3] = R[3] + 255;  /* 0x800CDF8C */
L_800CDF90:;
    R[8] = R[8] + 6516;  /* 0x800CDF90 */
    R[2] = R[4] + R[8];  /* 0x800CDF94 */
    R[19] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CDF98 */
    { int64_t _p = (int64_t)(int32_t)R[19] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CDFA0 */
    R[2] = lw_(R[17] + -32);  /* 0x800CDFA4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800CDFA8 */
    R[2] = R[2] + R[3];  /* 0x800CDFAC */
    R[5] = LO;  /* 0x800CDFB0 */
    { uint32_t _c = ((int32_t)R[5] >= 0); sw_(R[17] + -32, R[2]); if (_c) { goto L_800CDFC0; } }  /* 0x800CDFB4 */
    R[5] = R[5] + 255;  /* 0x800CDFBC */
L_800CDFC0:;
    R[4] = R[0] + 24576;  /* 0x800CDFC0 */
    R[2] = lw_(R[17] + -24);  /* 0x800CDFC4 */
    R[3] = (uint32_t)((int32_t)R[5] >> 8);  /* 0x800CDFC8 */
    R[2] = R[2] + R[3];  /* 0x800CDFCC */
    { R[31] = 0x800CDFD8u; sw_(R[17] + -24, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800CDFD0 jal */
    R[16] = R[2] + 8192;  /* 0x800CDFD8 */
    { int64_t _p = (int64_t)(int32_t)R[18] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CDFDC */
    R[2] = LO;  /* 0x800CDFE0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[4] = R[22] >> 31; if (_c) { goto L_800CDFF0; } }  /* 0x800CDFE4 */
    R[2] = R[2] + 255;  /* 0x800CDFEC */
L_800CDFF0:;
    R[4] = R[22] + R[4];  /* 0x800CDFF0 */
    R[4] = (uint32_t)((int32_t)R[4] >> 1);  /* 0x800CDFF4 */
    R[4] = R[4] << 12;  /* 0x800CDFF8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 8);  /* 0x800CDFFC */
    { R[31] = 0x800CE008u; sw_(R[17] + -8, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800CE000 jal */
    { int64_t _p = (int64_t)(int32_t)R[19] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CE008 */
    R[2] = R[0] - R[2];  /* 0x800CE00C */
    R[3] = LO;  /* 0x800CE010 */
    { uint32_t _c = ((int32_t)R[3] >= 0); sw_(R[17] + -4, R[2]); if (_c) { goto L_800CE020; } }  /* 0x800CE014 */
    R[3] = R[3] + 255;  /* 0x800CE01C */
L_800CE020:;
    R[2] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800CE020 */
    sw_(R[17], R[2]);  /* 0x800CE024 */
    R[2] = R[21] + 64;  /* 0x800CE028 */
    R[21] = R[2] & 0x1FF;  /* 0x800CE02C */
    R[17] = R[17] + 72;  /* 0x800CE030 */
    R[23] = R[23] + 1;  /* 0x800CE034 */
    R[2] = ((int32_t)R[23] < 8);  /* 0x800CE038 */
    { uint32_t _c = (R[2] != R[0]); R[20] = R[20] + 72; if (_c) { psx_bb(); goto L_800CDF34; } }  /* 0x800CE03C */
    R[4] = R[0] - 128;  /* 0x800CE044 */
    psx_div((int32_t)R[4], (int32_t)R[22]);  /* 0x800CE048 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE058; } }  /* 0x800CE04C */
    psx_break(7168);  /* 0x800CE054 */
L_800CE058:;
    R[1] = R[0] - 1;  /* 0x800CE058 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE070; } }  /* 0x800CE05C */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CE070; } }  /* 0x800CE064 */
    psx_break(6144);  /* 0x800CE06C */
L_800CE070:;
    R[4] = LO;  /* 0x800CE070 */
    R[3] = R[0] + 25;  /* 0x800CE074 */
    psx_div((int32_t)R[3], (int32_t)R[22]);  /* 0x800CE07C */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE08C; } }  /* 0x800CE080 */
    psx_break(7168);  /* 0x800CE088 */
L_800CE08C:;
    R[1] = R[0] - 1;  /* 0x800CE08C */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE0A4; } }  /* 0x800CE090 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CE0A4; } }  /* 0x800CE098 */
    psx_break(6144);  /* 0x800CE0A0 */
L_800CE0A4:;
    R[3] = LO;  /* 0x800CE0A4 */
    R[2] = R[0] - 8192;  /* 0x800CE0A8 */
    psx_div((int32_t)R[2], (int32_t)R[22]);  /* 0x800CE0B0 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE0C0; } }  /* 0x800CE0B4 */
    psx_break(7168);  /* 0x800CE0BC */
L_800CE0C0:;
    R[1] = R[0] - 1;  /* 0x800CE0C0 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE0D8; } }  /* 0x800CE0C4 */
    { uint32_t _c = (R[2] != R[1]); if (_c) { goto L_800CE0D8; } }  /* 0x800CE0CC */
    psx_break(6144);  /* 0x800CE0D4 */
L_800CE0D8:;
    R[2] = LO;  /* 0x800CE0D8 */
    sh_(R[30] + 592, R[4]);  /* 0x800CE0DC */
    sh_(R[30] + 594, R[3]);  /* 0x800CE0E0 */
    sw_(R[30] + 588, R[2]);  /* 0x800CE0E4 */
    R[31] = lw_(R[29] + 52);  /* 0x800CE0E8 */
    R[30] = lw_(R[29] + 48);  /* 0x800CE0EC */
    R[23] = lw_(R[29] + 44);  /* 0x800CE0F0 */
    R[22] = lw_(R[29] + 40);  /* 0x800CE0F4 */
    R[21] = lw_(R[29] + 36);  /* 0x800CE0F8 */
    R[20] = lw_(R[29] + 32);  /* 0x800CE0FC */
    R[19] = lw_(R[29] + 28);  /* 0x800CE100 */
    R[18] = lw_(R[29] + 24);  /* 0x800CE104 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE108 */
    R[16] = lw_(R[29] + 16);  /* 0x800CE10C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CE110 jr ra */
}

void g0_800CDF48(void) {
    R[4] = R[0] + 8192;  /* 0x800CDF48 */
    R[2] = R[0] + 8;  /* 0x800CDF4C */
    sb_(R[17] + -37, R[2]);  /* 0x800CDF50 */
    R[2] = R[0] + 25;  /* 0x800CDF54 */
    sb_(R[17] + 12, R[2]);  /* 0x800CDF58 */
    { R[31] = 0x800CDF64u; sb_(R[17] + 13, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800CDF5C jal */
    R[4] = R[21] << 1;  /* 0x800CDF64 */
    R[8] = 0x8008u << 16;  /* 0x800CDF68 */
    R[8] = R[8] + 5492;  /* 0x800CDF6C */
    R[3] = R[4] + R[8];  /* 0x800CDF70 */
    R[18] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800CDF74 */
    R[16] = R[2] + R[0];  /* 0x800CDF78 */
    { int64_t _p = (int64_t)(int32_t)R[18] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CDF7C */
    R[3] = LO;  /* 0x800CDF80 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[8] = 0x8008u << 16; if (_c) { goto L_800CDF90; } }  /* 0x800CDF84 */
    R[3] = R[3] + 255;  /* 0x800CDF8C */
L_800CDF90:;
    R[8] = R[8] + 6516;  /* 0x800CDF90 */
    R[2] = R[4] + R[8];  /* 0x800CDF94 */
    R[19] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CDF98 */
    { int64_t _p = (int64_t)(int32_t)R[19] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CDFA0 */
    R[2] = lw_(R[17] + -32);  /* 0x800CDFA4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800CDFA8 */
    R[2] = R[2] + R[3];  /* 0x800CDFAC */
    R[5] = LO;  /* 0x800CDFB0 */
    { uint32_t _c = ((int32_t)R[5] >= 0); sw_(R[17] + -32, R[2]); if (_c) { goto L_800CDFC0; } }  /* 0x800CDFB4 */
    R[5] = R[5] + 255;  /* 0x800CDFBC */
L_800CDFC0:;
    R[4] = R[0] + 24576;  /* 0x800CDFC0 */
    R[2] = lw_(R[17] + -24);  /* 0x800CDFC4 */
    R[3] = (uint32_t)((int32_t)R[5] >> 8);  /* 0x800CDFC8 */
    R[2] = R[2] + R[3];  /* 0x800CDFCC */
    { R[31] = 0x800CDFD8u; sw_(R[17] + -24, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800CDFD0 jal */
    R[16] = R[2] + 8192;  /* 0x800CDFD8 */
    { int64_t _p = (int64_t)(int32_t)R[18] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CDFDC */
    R[2] = LO;  /* 0x800CDFE0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[4] = R[22] >> 31; if (_c) { goto L_800CDFF0; } }  /* 0x800CDFE4 */
    R[2] = R[2] + 255;  /* 0x800CDFEC */
L_800CDFF0:;
    R[4] = R[22] + R[4];  /* 0x800CDFF0 */
    R[4] = (uint32_t)((int32_t)R[4] >> 1);  /* 0x800CDFF4 */
    R[4] = R[4] << 12;  /* 0x800CDFF8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 8);  /* 0x800CDFFC */
    { R[31] = 0x800CE008u; sw_(R[17] + -8, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800CE000 jal */
    { int64_t _p = (int64_t)(int32_t)R[19] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CE008 */
    R[2] = R[0] - R[2];  /* 0x800CE00C */
    R[3] = LO;  /* 0x800CE010 */
    { uint32_t _c = ((int32_t)R[3] >= 0); sw_(R[17] + -4, R[2]); if (_c) { goto L_800CE020; } }  /* 0x800CE014 */
    R[3] = R[3] + 255;  /* 0x800CE01C */
L_800CE020:;
    R[2] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800CE020 */
    sw_(R[17], R[2]);  /* 0x800CE024 */
    R[2] = R[21] + 64;  /* 0x800CE028 */
    R[21] = R[2] & 0x1FF;  /* 0x800CE02C */
    R[17] = R[17] + 72;  /* 0x800CE030 */
    R[23] = R[23] + 1;  /* 0x800CE034 */
    R[2] = ((int32_t)R[23] < 8);  /* 0x800CE038 */
    { uint32_t _c = (R[2] != R[0]); R[20] = R[20] + 72; if (_c) { psx_next = 0x800CDF34u; return; } }  /* 0x800CE03C b extern */
    R[4] = R[0] - 128;  /* 0x800CE044 */
    psx_div((int32_t)R[4], (int32_t)R[22]);  /* 0x800CE048 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE058; } }  /* 0x800CE04C */
    psx_break(7168);  /* 0x800CE054 */
L_800CE058:;
    R[1] = R[0] - 1;  /* 0x800CE058 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE070; } }  /* 0x800CE05C */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CE070; } }  /* 0x800CE064 */
    psx_break(6144);  /* 0x800CE06C */
L_800CE070:;
    R[4] = LO;  /* 0x800CE070 */
    R[3] = R[0] + 25;  /* 0x800CE074 */
    psx_div((int32_t)R[3], (int32_t)R[22]);  /* 0x800CE07C */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE08C; } }  /* 0x800CE080 */
    psx_break(7168);  /* 0x800CE088 */
L_800CE08C:;
    R[1] = R[0] - 1;  /* 0x800CE08C */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE0A4; } }  /* 0x800CE090 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CE0A4; } }  /* 0x800CE098 */
    psx_break(6144);  /* 0x800CE0A0 */
L_800CE0A4:;
    R[3] = LO;  /* 0x800CE0A4 */
    R[2] = R[0] - 8192;  /* 0x800CE0A8 */
    psx_div((int32_t)R[2], (int32_t)R[22]);  /* 0x800CE0B0 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE0C0; } }  /* 0x800CE0B4 */
    psx_break(7168);  /* 0x800CE0BC */
L_800CE0C0:;
    R[1] = R[0] - 1;  /* 0x800CE0C0 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE0D8; } }  /* 0x800CE0C4 */
    { uint32_t _c = (R[2] != R[1]); if (_c) { goto L_800CE0D8; } }  /* 0x800CE0CC */
    psx_break(6144);  /* 0x800CE0D4 */
L_800CE0D8:;
    R[2] = LO;  /* 0x800CE0D8 */
    sh_(R[30] + 592, R[4]);  /* 0x800CE0DC */
    sh_(R[30] + 594, R[3]);  /* 0x800CE0E0 */
    sw_(R[30] + 588, R[2]);  /* 0x800CE0E4 */
    R[31] = lw_(R[29] + 52);  /* 0x800CE0E8 */
    R[30] = lw_(R[29] + 48);  /* 0x800CE0EC */
    R[23] = lw_(R[29] + 44);  /* 0x800CE0F0 */
    R[22] = lw_(R[29] + 40);  /* 0x800CE0F4 */
    R[21] = lw_(R[29] + 36);  /* 0x800CE0F8 */
    R[20] = lw_(R[29] + 32);  /* 0x800CE0FC */
    R[19] = lw_(R[29] + 28);  /* 0x800CE100 */
    R[18] = lw_(R[29] + 24);  /* 0x800CE104 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE108 */
    R[16] = lw_(R[29] + 16);  /* 0x800CE10C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CE110 jr ra */
}

void g0_800CDF64(void) {
    R[4] = R[21] << 1;  /* 0x800CDF64 */
    R[8] = 0x8008u << 16;  /* 0x800CDF68 */
    R[8] = R[8] + 5492;  /* 0x800CDF6C */
    R[3] = R[4] + R[8];  /* 0x800CDF70 */
    R[18] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800CDF74 */
    R[16] = R[2] + R[0];  /* 0x800CDF78 */
    { int64_t _p = (int64_t)(int32_t)R[18] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CDF7C */
    R[3] = LO;  /* 0x800CDF80 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[8] = 0x8008u << 16; if (_c) { goto L_800CDF90; } }  /* 0x800CDF84 */
    R[3] = R[3] + 255;  /* 0x800CDF8C */
L_800CDF90:;
    R[8] = R[8] + 6516;  /* 0x800CDF90 */
    R[2] = R[4] + R[8];  /* 0x800CDF94 */
    R[19] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800CDF98 */
    { int64_t _p = (int64_t)(int32_t)R[19] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CDFA0 */
    R[2] = lw_(R[17] + -32);  /* 0x800CDFA4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800CDFA8 */
    R[2] = R[2] + R[3];  /* 0x800CDFAC */
    R[5] = LO;  /* 0x800CDFB0 */
    { uint32_t _c = ((int32_t)R[5] >= 0); sw_(R[17] + -32, R[2]); if (_c) { goto L_800CDFC0; } }  /* 0x800CDFB4 */
    R[5] = R[5] + 255;  /* 0x800CDFBC */
L_800CDFC0:;
    R[4] = R[0] + 24576;  /* 0x800CDFC0 */
    R[2] = lw_(R[17] + -24);  /* 0x800CDFC4 */
    R[3] = (uint32_t)((int32_t)R[5] >> 8);  /* 0x800CDFC8 */
    R[2] = R[2] + R[3];  /* 0x800CDFCC */
    { R[31] = 0x800CDFD8u; sw_(R[17] + -24, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800CDFD0 jal */
    R[16] = R[2] + 8192;  /* 0x800CDFD8 */
    { int64_t _p = (int64_t)(int32_t)R[18] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CDFDC */
    R[2] = LO;  /* 0x800CDFE0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[4] = R[22] >> 31; if (_c) { goto L_800CDFF0; } }  /* 0x800CDFE4 */
    R[2] = R[2] + 255;  /* 0x800CDFEC */
L_800CDFF0:;
    R[4] = R[22] + R[4];  /* 0x800CDFF0 */
    R[4] = (uint32_t)((int32_t)R[4] >> 1);  /* 0x800CDFF4 */
    R[4] = R[4] << 12;  /* 0x800CDFF8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 8);  /* 0x800CDFFC */
    { R[31] = 0x800CE008u; sw_(R[17] + -8, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800CE000 jal */
    { int64_t _p = (int64_t)(int32_t)R[19] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CE008 */
    R[2] = R[0] - R[2];  /* 0x800CE00C */
    R[3] = LO;  /* 0x800CE010 */
    { uint32_t _c = ((int32_t)R[3] >= 0); sw_(R[17] + -4, R[2]); if (_c) { goto L_800CE020; } }  /* 0x800CE014 */
    R[3] = R[3] + 255;  /* 0x800CE01C */
L_800CE020:;
    R[2] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800CE020 */
    sw_(R[17], R[2]);  /* 0x800CE024 */
    R[2] = R[21] + 64;  /* 0x800CE028 */
    R[21] = R[2] & 0x1FF;  /* 0x800CE02C */
    R[17] = R[17] + 72;  /* 0x800CE030 */
    R[23] = R[23] + 1;  /* 0x800CE034 */
    R[2] = ((int32_t)R[23] < 8);  /* 0x800CE038 */
    { uint32_t _c = (R[2] != R[0]); R[20] = R[20] + 72; if (_c) { psx_next = 0x800CDF34u; return; } }  /* 0x800CE03C b extern */
    R[4] = R[0] - 128;  /* 0x800CE044 */
    psx_div((int32_t)R[4], (int32_t)R[22]);  /* 0x800CE048 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE058; } }  /* 0x800CE04C */
    psx_break(7168);  /* 0x800CE054 */
L_800CE058:;
    R[1] = R[0] - 1;  /* 0x800CE058 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE070; } }  /* 0x800CE05C */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CE070; } }  /* 0x800CE064 */
    psx_break(6144);  /* 0x800CE06C */
L_800CE070:;
    R[4] = LO;  /* 0x800CE070 */
    R[3] = R[0] + 25;  /* 0x800CE074 */
    psx_div((int32_t)R[3], (int32_t)R[22]);  /* 0x800CE07C */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE08C; } }  /* 0x800CE080 */
    psx_break(7168);  /* 0x800CE088 */
L_800CE08C:;
    R[1] = R[0] - 1;  /* 0x800CE08C */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE0A4; } }  /* 0x800CE090 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CE0A4; } }  /* 0x800CE098 */
    psx_break(6144);  /* 0x800CE0A0 */
L_800CE0A4:;
    R[3] = LO;  /* 0x800CE0A4 */
    R[2] = R[0] - 8192;  /* 0x800CE0A8 */
    psx_div((int32_t)R[2], (int32_t)R[22]);  /* 0x800CE0B0 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE0C0; } }  /* 0x800CE0B4 */
    psx_break(7168);  /* 0x800CE0BC */
L_800CE0C0:;
    R[1] = R[0] - 1;  /* 0x800CE0C0 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE0D8; } }  /* 0x800CE0C4 */
    { uint32_t _c = (R[2] != R[1]); if (_c) { goto L_800CE0D8; } }  /* 0x800CE0CC */
    psx_break(6144);  /* 0x800CE0D4 */
L_800CE0D8:;
    R[2] = LO;  /* 0x800CE0D8 */
    sh_(R[30] + 592, R[4]);  /* 0x800CE0DC */
    sh_(R[30] + 594, R[3]);  /* 0x800CE0E0 */
    sw_(R[30] + 588, R[2]);  /* 0x800CE0E4 */
    R[31] = lw_(R[29] + 52);  /* 0x800CE0E8 */
    R[30] = lw_(R[29] + 48);  /* 0x800CE0EC */
    R[23] = lw_(R[29] + 44);  /* 0x800CE0F0 */
    R[22] = lw_(R[29] + 40);  /* 0x800CE0F4 */
    R[21] = lw_(R[29] + 36);  /* 0x800CE0F8 */
    R[20] = lw_(R[29] + 32);  /* 0x800CE0FC */
    R[19] = lw_(R[29] + 28);  /* 0x800CE100 */
    R[18] = lw_(R[29] + 24);  /* 0x800CE104 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE108 */
    R[16] = lw_(R[29] + 16);  /* 0x800CE10C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CE110 jr ra */
}

void g0_800CDFD8(void) {
    R[16] = R[2] + 8192;  /* 0x800CDFD8 */
    { int64_t _p = (int64_t)(int32_t)R[18] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CDFDC */
    R[2] = LO;  /* 0x800CDFE0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[4] = R[22] >> 31; if (_c) { goto L_800CDFF0; } }  /* 0x800CDFE4 */
    R[2] = R[2] + 255;  /* 0x800CDFEC */
L_800CDFF0:;
    R[4] = R[22] + R[4];  /* 0x800CDFF0 */
    R[4] = (uint32_t)((int32_t)R[4] >> 1);  /* 0x800CDFF4 */
    R[4] = R[4] << 12;  /* 0x800CDFF8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 8);  /* 0x800CDFFC */
    { R[31] = 0x800CE008u; sw_(R[17] + -8, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800CE000 jal */
    { int64_t _p = (int64_t)(int32_t)R[19] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CE008 */
    R[2] = R[0] - R[2];  /* 0x800CE00C */
    R[3] = LO;  /* 0x800CE010 */
    { uint32_t _c = ((int32_t)R[3] >= 0); sw_(R[17] + -4, R[2]); if (_c) { goto L_800CE020; } }  /* 0x800CE014 */
    R[3] = R[3] + 255;  /* 0x800CE01C */
L_800CE020:;
    R[2] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800CE020 */
    sw_(R[17], R[2]);  /* 0x800CE024 */
    R[2] = R[21] + 64;  /* 0x800CE028 */
    R[21] = R[2] & 0x1FF;  /* 0x800CE02C */
    R[17] = R[17] + 72;  /* 0x800CE030 */
    R[23] = R[23] + 1;  /* 0x800CE034 */
    R[2] = ((int32_t)R[23] < 8);  /* 0x800CE038 */
    { uint32_t _c = (R[2] != R[0]); R[20] = R[20] + 72; if (_c) { psx_next = 0x800CDF34u; return; } }  /* 0x800CE03C b extern */
    R[4] = R[0] - 128;  /* 0x800CE044 */
    psx_div((int32_t)R[4], (int32_t)R[22]);  /* 0x800CE048 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE058; } }  /* 0x800CE04C */
    psx_break(7168);  /* 0x800CE054 */
L_800CE058:;
    R[1] = R[0] - 1;  /* 0x800CE058 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE070; } }  /* 0x800CE05C */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CE070; } }  /* 0x800CE064 */
    psx_break(6144);  /* 0x800CE06C */
L_800CE070:;
    R[4] = LO;  /* 0x800CE070 */
    R[3] = R[0] + 25;  /* 0x800CE074 */
    psx_div((int32_t)R[3], (int32_t)R[22]);  /* 0x800CE07C */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE08C; } }  /* 0x800CE080 */
    psx_break(7168);  /* 0x800CE088 */
L_800CE08C:;
    R[1] = R[0] - 1;  /* 0x800CE08C */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE0A4; } }  /* 0x800CE090 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CE0A4; } }  /* 0x800CE098 */
    psx_break(6144);  /* 0x800CE0A0 */
L_800CE0A4:;
    R[3] = LO;  /* 0x800CE0A4 */
    R[2] = R[0] - 8192;  /* 0x800CE0A8 */
    psx_div((int32_t)R[2], (int32_t)R[22]);  /* 0x800CE0B0 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE0C0; } }  /* 0x800CE0B4 */
    psx_break(7168);  /* 0x800CE0BC */
L_800CE0C0:;
    R[1] = R[0] - 1;  /* 0x800CE0C0 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE0D8; } }  /* 0x800CE0C4 */
    { uint32_t _c = (R[2] != R[1]); if (_c) { goto L_800CE0D8; } }  /* 0x800CE0CC */
    psx_break(6144);  /* 0x800CE0D4 */
L_800CE0D8:;
    R[2] = LO;  /* 0x800CE0D8 */
    sh_(R[30] + 592, R[4]);  /* 0x800CE0DC */
    sh_(R[30] + 594, R[3]);  /* 0x800CE0E0 */
    sw_(R[30] + 588, R[2]);  /* 0x800CE0E4 */
    R[31] = lw_(R[29] + 52);  /* 0x800CE0E8 */
    R[30] = lw_(R[29] + 48);  /* 0x800CE0EC */
    R[23] = lw_(R[29] + 44);  /* 0x800CE0F0 */
    R[22] = lw_(R[29] + 40);  /* 0x800CE0F4 */
    R[21] = lw_(R[29] + 36);  /* 0x800CE0F8 */
    R[20] = lw_(R[29] + 32);  /* 0x800CE0FC */
    R[19] = lw_(R[29] + 28);  /* 0x800CE100 */
    R[18] = lw_(R[29] + 24);  /* 0x800CE104 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE108 */
    R[16] = lw_(R[29] + 16);  /* 0x800CE10C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CE110 jr ra */
}

void g0_800CE008(void) {
    { int64_t _p = (int64_t)(int32_t)R[19] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CE008 */
    R[2] = R[0] - R[2];  /* 0x800CE00C */
    R[3] = LO;  /* 0x800CE010 */
    { uint32_t _c = ((int32_t)R[3] >= 0); sw_(R[17] + -4, R[2]); if (_c) { goto L_800CE020; } }  /* 0x800CE014 */
    R[3] = R[3] + 255;  /* 0x800CE01C */
L_800CE020:;
    R[2] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800CE020 */
    sw_(R[17], R[2]);  /* 0x800CE024 */
    R[2] = R[21] + 64;  /* 0x800CE028 */
    R[21] = R[2] & 0x1FF;  /* 0x800CE02C */
    R[17] = R[17] + 72;  /* 0x800CE030 */
    R[23] = R[23] + 1;  /* 0x800CE034 */
    R[2] = ((int32_t)R[23] < 8);  /* 0x800CE038 */
    { uint32_t _c = (R[2] != R[0]); R[20] = R[20] + 72; if (_c) { psx_next = 0x800CDF34u; return; } }  /* 0x800CE03C b extern */
    R[4] = R[0] - 128;  /* 0x800CE044 */
    psx_div((int32_t)R[4], (int32_t)R[22]);  /* 0x800CE048 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE058; } }  /* 0x800CE04C */
    psx_break(7168);  /* 0x800CE054 */
L_800CE058:;
    R[1] = R[0] - 1;  /* 0x800CE058 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE070; } }  /* 0x800CE05C */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CE070; } }  /* 0x800CE064 */
    psx_break(6144);  /* 0x800CE06C */
L_800CE070:;
    R[4] = LO;  /* 0x800CE070 */
    R[3] = R[0] + 25;  /* 0x800CE074 */
    psx_div((int32_t)R[3], (int32_t)R[22]);  /* 0x800CE07C */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE08C; } }  /* 0x800CE080 */
    psx_break(7168);  /* 0x800CE088 */
L_800CE08C:;
    R[1] = R[0] - 1;  /* 0x800CE08C */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE0A4; } }  /* 0x800CE090 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CE0A4; } }  /* 0x800CE098 */
    psx_break(6144);  /* 0x800CE0A0 */
L_800CE0A4:;
    R[3] = LO;  /* 0x800CE0A4 */
    R[2] = R[0] - 8192;  /* 0x800CE0A8 */
    psx_div((int32_t)R[2], (int32_t)R[22]);  /* 0x800CE0B0 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CE0C0; } }  /* 0x800CE0B4 */
    psx_break(7168);  /* 0x800CE0BC */
L_800CE0C0:;
    R[1] = R[0] - 1;  /* 0x800CE0C0 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CE0D8; } }  /* 0x800CE0C4 */
    { uint32_t _c = (R[2] != R[1]); if (_c) { goto L_800CE0D8; } }  /* 0x800CE0CC */
    psx_break(6144);  /* 0x800CE0D4 */
L_800CE0D8:;
    R[2] = LO;  /* 0x800CE0D8 */
    sh_(R[30] + 592, R[4]);  /* 0x800CE0DC */
    sh_(R[30] + 594, R[3]);  /* 0x800CE0E0 */
    sw_(R[30] + 588, R[2]);  /* 0x800CE0E4 */
    R[31] = lw_(R[29] + 52);  /* 0x800CE0E8 */
    R[30] = lw_(R[29] + 48);  /* 0x800CE0EC */
    R[23] = lw_(R[29] + 44);  /* 0x800CE0F0 */
    R[22] = lw_(R[29] + 40);  /* 0x800CE0F4 */
    R[21] = lw_(R[29] + 36);  /* 0x800CE0F8 */
    R[20] = lw_(R[29] + 32);  /* 0x800CE0FC */
    R[19] = lw_(R[29] + 28);  /* 0x800CE100 */
    R[18] = lw_(R[29] + 24);  /* 0x800CE104 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE108 */
    R[16] = lw_(R[29] + 16);  /* 0x800CE10C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CE110 jr ra */
}

void g0_800CE118(void) {
    R[29] = R[29] - 40;  /* 0x800CE118 */
    sw_(R[29] + 24, R[18]);  /* 0x800CE11C */
    R[18] = R[4] + R[0];  /* 0x800CE120 */
    sw_(R[29] + 32, R[31]);  /* 0x800CE124 */
    sw_(R[29] + 28, R[19]);  /* 0x800CE128 */
    sw_(R[29] + 20, R[17]);  /* 0x800CE12C */
    sw_(R[29] + 16, R[16]);  /* 0x800CE130 */
    R[2] = lb_(R[18] + 585);  /* 0x800CE134 */
    R[19] = R[0] + R[0];  /* 0x800CE138 */
    R[3] = R[2] << 3;  /* 0x800CE13C */
    R[3] = R[3] + R[2];  /* 0x800CE140 */
    R[3] = R[3] << 7;  /* 0x800CE144 */
    R[2] = 0x8014u << 16;  /* 0x800CE148 */
    R[2] = R[2] + 15160;  /* 0x800CE14C */
    R[17] = R[3] + R[2];  /* 0x800CE150 */
    R[16] = R[17] + 40;  /* 0x800CE154 */
L_800CE158:;
    R[2] = lb_(R[16] + 12);  /* 0x800CE158 */
    R[3] = lb_(R[18] + 594);  /* 0x800CE15C */
    R[2] = R[2] - R[3];  /* 0x800CE164 */
    sb_(R[16] + 12, R[2]);  /* 0x800CE168 */
    R[2] = lb_(R[16] + 13);  /* 0x800CE16C */
    R[3] = lb_(R[18] + 594);  /* 0x800CE170 */
    R[2] = R[2] - R[3];  /* 0x800CE178 */
    sb_(R[16] + 13, R[2]);  /* 0x800CE17C */
    R[5] = (uint32_t)(int16_t)lh_(R[18] + 592);  /* 0x800CE180 */
    { R[31] = 0x800CE18Cu; R[4] = R[17] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CE184 jal */
    R[2] = lw_(R[16] + -8);  /* 0x800CE18C */
    R[3] = lw_(R[18] + 588);  /* 0x800CE190 */
    R[17] = R[17] + 72;  /* 0x800CE194 */
    R[2] = R[2] - R[3];  /* 0x800CE198 */
    sw_(R[16] + -8, R[2]);  /* 0x800CE19C */
    R[2] = lw_(R[16]);  /* 0x800CE1A0 */
    R[3] = lw_(R[18] + 588);  /* 0x800CE1A4 */
    R[19] = R[19] + 1;  /* 0x800CE1A8 */
    R[2] = R[2] - R[3];  /* 0x800CE1AC */
    sw_(R[16], R[2]);  /* 0x800CE1B0 */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800CE1B4 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 72; if (_c) { psx_bb(); goto L_800CE158; } }  /* 0x800CE1B8 */
    R[31] = lw_(R[29] + 32);  /* 0x800CE1C0 */
    R[19] = lw_(R[29] + 28);  /* 0x800CE1C4 */
    R[18] = lw_(R[29] + 24);  /* 0x800CE1C8 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE1CC */
    R[16] = lw_(R[29] + 16);  /* 0x800CE1D0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CE1D4 jr ra */
}

void g0_800CE158(void) {
L_800CE158:;
    R[2] = lb_(R[16] + 12);  /* 0x800CE158 */
    R[3] = lb_(R[18] + 594);  /* 0x800CE15C */
    R[2] = R[2] - R[3];  /* 0x800CE164 */
    sb_(R[16] + 12, R[2]);  /* 0x800CE168 */
    R[2] = lb_(R[16] + 13);  /* 0x800CE16C */
    R[3] = lb_(R[18] + 594);  /* 0x800CE170 */
    R[2] = R[2] - R[3];  /* 0x800CE178 */
    sb_(R[16] + 13, R[2]);  /* 0x800CE17C */
    R[5] = (uint32_t)(int16_t)lh_(R[18] + 592);  /* 0x800CE180 */
    { R[31] = 0x800CE18Cu; R[4] = R[17] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CE184 jal */
    R[2] = lw_(R[16] + -8);  /* 0x800CE18C */
    R[3] = lw_(R[18] + 588);  /* 0x800CE190 */
    R[17] = R[17] + 72;  /* 0x800CE194 */
    R[2] = R[2] - R[3];  /* 0x800CE198 */
    sw_(R[16] + -8, R[2]);  /* 0x800CE19C */
    R[2] = lw_(R[16]);  /* 0x800CE1A0 */
    R[3] = lw_(R[18] + 588);  /* 0x800CE1A4 */
    R[19] = R[19] + 1;  /* 0x800CE1A8 */
    R[2] = R[2] - R[3];  /* 0x800CE1AC */
    sw_(R[16], R[2]);  /* 0x800CE1B0 */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800CE1B4 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 72; if (_c) { psx_bb(); goto L_800CE158; } }  /* 0x800CE1B8 */
    R[31] = lw_(R[29] + 32);  /* 0x800CE1C0 */
    R[19] = lw_(R[29] + 28);  /* 0x800CE1C4 */
    R[18] = lw_(R[29] + 24);  /* 0x800CE1C8 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE1CC */
    R[16] = lw_(R[29] + 16);  /* 0x800CE1D0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CE1D4 jr ra */
}

void g0_800CE18C(void) {
    R[2] = lw_(R[16] + -8);  /* 0x800CE18C */
    R[3] = lw_(R[18] + 588);  /* 0x800CE190 */
    R[17] = R[17] + 72;  /* 0x800CE194 */
    R[2] = R[2] - R[3];  /* 0x800CE198 */
    sw_(R[16] + -8, R[2]);  /* 0x800CE19C */
    R[2] = lw_(R[16]);  /* 0x800CE1A0 */
    R[3] = lw_(R[18] + 588);  /* 0x800CE1A4 */
    R[19] = R[19] + 1;  /* 0x800CE1A8 */
    R[2] = R[2] - R[3];  /* 0x800CE1AC */
    sw_(R[16], R[2]);  /* 0x800CE1B0 */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800CE1B4 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 72; if (_c) { psx_next = 0x800CE158u; return; } }  /* 0x800CE1B8 b extern */
    R[31] = lw_(R[29] + 32);  /* 0x800CE1C0 */
    R[19] = lw_(R[29] + 28);  /* 0x800CE1C4 */
    R[18] = lw_(R[29] + 24);  /* 0x800CE1C8 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE1CC */
    R[16] = lw_(R[29] + 16);  /* 0x800CE1D0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CE1D4 jr ra */
}

void g0_800CE1DC(void) {
    R[29] = R[29] - 48;  /* 0x800CE1DC */
    sw_(R[29] + 40, R[22]);  /* 0x800CE1E0 */
    R[22] = R[4] + R[0];  /* 0x800CE1E4 */
    sw_(R[29] + 16, R[16]);  /* 0x800CE1E8 */
    R[16] = R[5] + R[0];  /* 0x800CE1EC */
    sw_(R[29] + 44, R[31]);  /* 0x800CE1F0 */
    sw_(R[29] + 36, R[21]);  /* 0x800CE1F4 */
    sw_(R[29] + 32, R[20]);  /* 0x800CE1F8 */
    sw_(R[29] + 28, R[19]);  /* 0x800CE1FC */
    sw_(R[29] + 24, R[18]);  /* 0x800CE200 */
    { R[31] = 0x800CE20Cu; sw_(R[29] + 20, R[17]); psx_next = 0x80093774u; return; }  /* 0x800CE204 jal */
    R[21] = R[2] + R[0];  /* 0x800CE20C */
    { uint32_t _c = ((int32_t)R[21] <= 0); R[20] = 0x3FFFu << 16; if (_c) { goto L_800CE330; } }  /* 0x800CE210 */
    R[2] = R[16] << 16;  /* 0x800CE218 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CE21C */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[20] = R[20] | 0x1; if (_c) { goto L_800CE230; } }  /* 0x800CE220 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CE228 */
    R[20] = LO;  /* 0x800CE22C */
L_800CE230:;
    R[2] = 0x8013u << 16;  /* 0x800CE230 */
    R[17] = R[2] - 31752;  /* 0x800CE234 */
    R[18] = R[20] + R[0];  /* 0x800CE238 */
    R[19] = R[0] - 1;  /* 0x800CE23C */
    { uint32_t _c = ((int32_t)R[21] <= 0); R[16] = R[0] + R[0]; if (_c) { goto L_800CE310; } }  /* 0x800CE240 */
L_800CE248:;
    R[5] = lw_(R[17]);  /* 0x800CE248 */
    R[2] = lh_(R[5] + 12);  /* 0x800CE250 */
    R[2] = R[2] - 2;  /* 0x800CE258 */
    R[2] = (R[2] < (uint32_t)3u);  /* 0x800CE25C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CE300; } }  /* 0x800CE260 */
    R[2] = lb_(R[5] + 789);  /* 0x800CE268 */
    R[2] = R[2] & 0x1;  /* 0x800CE270 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800CE300; } }  /* 0x800CE274 */
    R[3] = lb_(R[5] + 791);  /* 0x800CE27C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_800CE300; } }  /* 0x800CE284 */
    R[2] = lb_(R[5] + 787);  /* 0x800CE28C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0xFFu << 16; if (_c) { goto L_800CE300; } }  /* 0x800CE294 */
    R[2] = lw_(R[5] + 788);  /* 0x800CE29C */
    R[3] = R[3] | 0xFF;  /* 0x800CE2A0 */
    R[2] = R[2] & R[3];  /* 0x800CE2A4 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE300; } }  /* 0x800CE2A8 */
    R[2] = lh_(R[5] + 88);  /* 0x800CE2B0 */
    R[2] = R[2] & 0x1000;  /* 0x800CE2B8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE300; } }  /* 0x800CE2BC */
    R[2] = lb_(R[5] + 797);  /* 0x800CE2C4 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[22] + 24; if (_c) { goto L_800CE300; } }  /* 0x800CE2CC */
    R[5] = R[5] + 24;  /* 0x800CE2D4 */
    { R[31] = 0x800CE2E0u; R[6] = R[0] + 400; psx_next = 0x800B6A98u; return; }  /* 0x800CE2D8 jal */
    R[3] = R[2] + R[0];  /* 0x800CE2E0 */
    R[2] = (R[20] < R[3]);  /* 0x800CE2E4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = (R[18] < R[3]); if (_c) { goto L_800CE300; } }  /* 0x800CE2E8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE300; } }  /* 0x800CE2F0 */
    R[18] = R[3] + R[0];  /* 0x800CE2F8 */
    R[19] = R[16] + R[0];  /* 0x800CE2FC */
L_800CE300:;
    R[16] = R[16] + 1;  /* 0x800CE300 */
    R[2] = ((int32_t)R[16] < (int32_t)R[21]);  /* 0x800CE304 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 4; if (_c) { psx_bb(); goto L_800CE248; } }  /* 0x800CE308 */
L_800CE310:;
    { uint32_t _c = ((int32_t)R[19] < 0); R[3] = 0x8013u << 16; if (_c) { goto L_800CE330; } }  /* 0x800CE310 */
    R[3] = R[3] - 31752;  /* 0x800CE318 */
    R[2] = R[19] << 2;  /* 0x800CE31C */
    R[2] = R[2] + R[3];  /* 0x800CE320 */
    R[2] = lw_(R[2]);  /* 0x800CE324 */
    { goto L_800CE334; }  /* 0x800CE328 j */
L_800CE330:;
    R[2] = R[0] + R[0];  /* 0x800CE330 */
L_800CE334:;
    R[31] = lw_(R[29] + 44);  /* 0x800CE334 */
    R[22] = lw_(R[29] + 40);  /* 0x800CE338 */
    R[21] = lw_(R[29] + 36);  /* 0x800CE33C */
    R[20] = lw_(R[29] + 32);  /* 0x800CE340 */
    R[19] = lw_(R[29] + 28);  /* 0x800CE344 */
    R[18] = lw_(R[29] + 24);  /* 0x800CE348 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE34C */
    R[16] = lw_(R[29] + 16);  /* 0x800CE350 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800CE354 jr ra */
}

void g0_800CE20C(void) {
    R[21] = R[2] + R[0];  /* 0x800CE20C */
    { uint32_t _c = ((int32_t)R[21] <= 0); R[20] = 0x3FFFu << 16; if (_c) { goto L_800CE330; } }  /* 0x800CE210 */
    R[2] = R[16] << 16;  /* 0x800CE218 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CE21C */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[20] = R[20] | 0x1; if (_c) { goto L_800CE230; } }  /* 0x800CE220 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CE228 */
    R[20] = LO;  /* 0x800CE22C */
L_800CE230:;
    R[2] = 0x8013u << 16;  /* 0x800CE230 */
    R[17] = R[2] - 31752;  /* 0x800CE234 */
    R[18] = R[20] + R[0];  /* 0x800CE238 */
    R[19] = R[0] - 1;  /* 0x800CE23C */
    { uint32_t _c = ((int32_t)R[21] <= 0); R[16] = R[0] + R[0]; if (_c) { goto L_800CE310; } }  /* 0x800CE240 */
L_800CE248:;
    R[5] = lw_(R[17]);  /* 0x800CE248 */
    R[2] = lh_(R[5] + 12);  /* 0x800CE250 */
    R[2] = R[2] - 2;  /* 0x800CE258 */
    R[2] = (R[2] < (uint32_t)3u);  /* 0x800CE25C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CE300; } }  /* 0x800CE260 */
    R[2] = lb_(R[5] + 789);  /* 0x800CE268 */
    R[2] = R[2] & 0x1;  /* 0x800CE270 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800CE300; } }  /* 0x800CE274 */
    R[3] = lb_(R[5] + 791);  /* 0x800CE27C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_800CE300; } }  /* 0x800CE284 */
    R[2] = lb_(R[5] + 787);  /* 0x800CE28C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0xFFu << 16; if (_c) { goto L_800CE300; } }  /* 0x800CE294 */
    R[2] = lw_(R[5] + 788);  /* 0x800CE29C */
    R[3] = R[3] | 0xFF;  /* 0x800CE2A0 */
    R[2] = R[2] & R[3];  /* 0x800CE2A4 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE300; } }  /* 0x800CE2A8 */
    R[2] = lh_(R[5] + 88);  /* 0x800CE2B0 */
    R[2] = R[2] & 0x1000;  /* 0x800CE2B8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE300; } }  /* 0x800CE2BC */
    R[2] = lb_(R[5] + 797);  /* 0x800CE2C4 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[22] + 24; if (_c) { goto L_800CE300; } }  /* 0x800CE2CC */
    R[5] = R[5] + 24;  /* 0x800CE2D4 */
    { R[31] = 0x800CE2E0u; R[6] = R[0] + 400; psx_next = 0x800B6A98u; return; }  /* 0x800CE2D8 jal */
    R[3] = R[2] + R[0];  /* 0x800CE2E0 */
    R[2] = (R[20] < R[3]);  /* 0x800CE2E4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = (R[18] < R[3]); if (_c) { goto L_800CE300; } }  /* 0x800CE2E8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE300; } }  /* 0x800CE2F0 */
    R[18] = R[3] + R[0];  /* 0x800CE2F8 */
    R[19] = R[16] + R[0];  /* 0x800CE2FC */
L_800CE300:;
    R[16] = R[16] + 1;  /* 0x800CE300 */
    R[2] = ((int32_t)R[16] < (int32_t)R[21]);  /* 0x800CE304 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 4; if (_c) { psx_bb(); goto L_800CE248; } }  /* 0x800CE308 */
L_800CE310:;
    { uint32_t _c = ((int32_t)R[19] < 0); R[3] = 0x8013u << 16; if (_c) { goto L_800CE330; } }  /* 0x800CE310 */
    R[3] = R[3] - 31752;  /* 0x800CE318 */
    R[2] = R[19] << 2;  /* 0x800CE31C */
    R[2] = R[2] + R[3];  /* 0x800CE320 */
    R[2] = lw_(R[2]);  /* 0x800CE324 */
    { goto L_800CE334; }  /* 0x800CE328 j */
L_800CE330:;
    R[2] = R[0] + R[0];  /* 0x800CE330 */
L_800CE334:;
    R[31] = lw_(R[29] + 44);  /* 0x800CE334 */
    R[22] = lw_(R[29] + 40);  /* 0x800CE338 */
    R[21] = lw_(R[29] + 36);  /* 0x800CE33C */
    R[20] = lw_(R[29] + 32);  /* 0x800CE340 */
    R[19] = lw_(R[29] + 28);  /* 0x800CE344 */
    R[18] = lw_(R[29] + 24);  /* 0x800CE348 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE34C */
    R[16] = lw_(R[29] + 16);  /* 0x800CE350 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800CE354 jr ra */
}

void g0_800CE248(void) {
L_800CE248:;
    R[5] = lw_(R[17]);  /* 0x800CE248 */
    R[2] = lh_(R[5] + 12);  /* 0x800CE250 */
    R[2] = R[2] - 2;  /* 0x800CE258 */
    R[2] = (R[2] < (uint32_t)3u);  /* 0x800CE25C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CE300; } }  /* 0x800CE260 */
    R[2] = lb_(R[5] + 789);  /* 0x800CE268 */
    R[2] = R[2] & 0x1;  /* 0x800CE270 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800CE300; } }  /* 0x800CE274 */
    R[3] = lb_(R[5] + 791);  /* 0x800CE27C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_800CE300; } }  /* 0x800CE284 */
    R[2] = lb_(R[5] + 787);  /* 0x800CE28C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0xFFu << 16; if (_c) { goto L_800CE300; } }  /* 0x800CE294 */
    R[2] = lw_(R[5] + 788);  /* 0x800CE29C */
    R[3] = R[3] | 0xFF;  /* 0x800CE2A0 */
    R[2] = R[2] & R[3];  /* 0x800CE2A4 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE300; } }  /* 0x800CE2A8 */
    R[2] = lh_(R[5] + 88);  /* 0x800CE2B0 */
    R[2] = R[2] & 0x1000;  /* 0x800CE2B8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE300; } }  /* 0x800CE2BC */
    R[2] = lb_(R[5] + 797);  /* 0x800CE2C4 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[22] + 24; if (_c) { goto L_800CE300; } }  /* 0x800CE2CC */
    R[5] = R[5] + 24;  /* 0x800CE2D4 */
    { R[31] = 0x800CE2E0u; R[6] = R[0] + 400; psx_next = 0x800B6A98u; return; }  /* 0x800CE2D8 jal */
    R[3] = R[2] + R[0];  /* 0x800CE2E0 */
    R[2] = (R[20] < R[3]);  /* 0x800CE2E4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = (R[18] < R[3]); if (_c) { goto L_800CE300; } }  /* 0x800CE2E8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE300; } }  /* 0x800CE2F0 */
    R[18] = R[3] + R[0];  /* 0x800CE2F8 */
    R[19] = R[16] + R[0];  /* 0x800CE2FC */
L_800CE300:;
    R[16] = R[16] + 1;  /* 0x800CE300 */
    R[2] = ((int32_t)R[16] < (int32_t)R[21]);  /* 0x800CE304 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 4; if (_c) { psx_bb(); goto L_800CE248; } }  /* 0x800CE308 */
    { uint32_t _c = ((int32_t)R[19] < 0); R[3] = 0x8013u << 16; if (_c) { goto L_800CE330; } }  /* 0x800CE310 */
    R[3] = R[3] - 31752;  /* 0x800CE318 */
    R[2] = R[19] << 2;  /* 0x800CE31C */
    R[2] = R[2] + R[3];  /* 0x800CE320 */
    R[2] = lw_(R[2]);  /* 0x800CE324 */
    { goto L_800CE334; }  /* 0x800CE328 j */
L_800CE330:;
    R[2] = R[0] + R[0];  /* 0x800CE330 */
L_800CE334:;
    R[31] = lw_(R[29] + 44);  /* 0x800CE334 */
    R[22] = lw_(R[29] + 40);  /* 0x800CE338 */
    R[21] = lw_(R[29] + 36);  /* 0x800CE33C */
    R[20] = lw_(R[29] + 32);  /* 0x800CE340 */
    R[19] = lw_(R[29] + 28);  /* 0x800CE344 */
    R[18] = lw_(R[29] + 24);  /* 0x800CE348 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE34C */
    R[16] = lw_(R[29] + 16);  /* 0x800CE350 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800CE354 jr ra */
}

void g0_800CE2E0(void) {
    R[3] = R[2] + R[0];  /* 0x800CE2E0 */
    R[2] = (R[20] < R[3]);  /* 0x800CE2E4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = (R[18] < R[3]); if (_c) { goto L_800CE300; } }  /* 0x800CE2E8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE300; } }  /* 0x800CE2F0 */
    R[18] = R[3] + R[0];  /* 0x800CE2F8 */
    R[19] = R[16] + R[0];  /* 0x800CE2FC */
L_800CE300:;
    R[16] = R[16] + 1;  /* 0x800CE300 */
    R[2] = ((int32_t)R[16] < (int32_t)R[21]);  /* 0x800CE304 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 4; if (_c) { psx_next = 0x800CE248u; return; } }  /* 0x800CE308 b extern */
    { uint32_t _c = ((int32_t)R[19] < 0); R[3] = 0x8013u << 16; if (_c) { goto L_800CE330; } }  /* 0x800CE310 */
    R[3] = R[3] - 31752;  /* 0x800CE318 */
    R[2] = R[19] << 2;  /* 0x800CE31C */
    R[2] = R[2] + R[3];  /* 0x800CE320 */
    R[2] = lw_(R[2]);  /* 0x800CE324 */
    { goto L_800CE334; }  /* 0x800CE328 j */
L_800CE330:;
    R[2] = R[0] + R[0];  /* 0x800CE330 */
L_800CE334:;
    R[31] = lw_(R[29] + 44);  /* 0x800CE334 */
    R[22] = lw_(R[29] + 40);  /* 0x800CE338 */
    R[21] = lw_(R[29] + 36);  /* 0x800CE33C */
    R[20] = lw_(R[29] + 32);  /* 0x800CE340 */
    R[19] = lw_(R[29] + 28);  /* 0x800CE344 */
    R[18] = lw_(R[29] + 24);  /* 0x800CE348 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE34C */
    R[16] = lw_(R[29] + 16);  /* 0x800CE350 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800CE354 jr ra */
}

void g0_800CE35C(void) {
    R[29] = R[29] - 40;  /* 0x800CE35C */
    sw_(R[29] + 16, R[16]);  /* 0x800CE360 */
    R[16] = R[4] + R[0];  /* 0x800CE364 */
    sw_(R[29] + 24, R[18]);  /* 0x800CE368 */
    R[18] = R[5] + R[0];  /* 0x800CE36C */
    R[5] = R[0] + 120;  /* 0x800CE370 */
    sw_(R[29] + 28, R[19]);  /* 0x800CE374 */
    R[19] = R[6] + R[0];  /* 0x800CE378 */
    sw_(R[29] + 32, R[31]);  /* 0x800CE37C */
    { R[31] = 0x800CE388u; sw_(R[29] + 20, R[17]); psx_next = 0x800CE1DCu; return; }  /* 0x800CE380 jal */
    R[17] = R[2] + R[0];  /* 0x800CE388 */
    { uint32_t _c = (R[17] == R[0]); if (_c) { goto L_800CE4E8; } }  /* 0x800CE38C */
    R[3] = lw_(R[17] + 32);  /* 0x800CE394 */
    R[2] = lw_(R[16] + 32);  /* 0x800CE398 */
    R[4] = R[3] - R[2];  /* 0x800CE3A0 */
    { uint32_t _c = ((int32_t)R[4] >= 0); if (_c) { goto L_800CE3B0; } }  /* 0x800CE3A4 */
    R[4] = R[4] + 4095;  /* 0x800CE3AC */
L_800CE3B0:;
    R[3] = lw_(R[17] + 24);  /* 0x800CE3B0 */
    R[2] = lw_(R[16] + 24);  /* 0x800CE3B4 */
    R[3] = R[3] - R[2];  /* 0x800CE3BC */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = (uint32_t)((int32_t)R[4] >> 12); if (_c) { goto L_800CE3CC; } }  /* 0x800CE3C0 */
    R[3] = R[3] + 4095;  /* 0x800CE3C8 */
L_800CE3CC:;
    { R[31] = 0x800CE3D4u; R[5] = (uint32_t)((int32_t)R[3] >> 12); psx_next = 0x80037B38u; return; }  /* 0x800CE3CC jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CE3E0; } }  /* 0x800CE3D4 */
    R[2] = R[2] + 7;  /* 0x800CE3DC */
L_800CE3E0:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800CE3E0 */
    R[4] = R[2] & 0x1FF;  /* 0x800CE3E4 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 4);  /* 0x800CE3E8 */
    R[3] = lh_(R[16] + 4);  /* 0x800CE3EC */
    R[2] = R[4] - R[2];  /* 0x800CE3F0 */
    { uint32_t _c = ((int32_t)R[2] < 0); R[7] = R[4] + R[0]; if (_c) { goto L_800CE404; } }  /* 0x800CE3F4 */
    { R[6] = R[4] - R[3]; goto L_800CE408; }  /* 0x800CE3FC j */
L_800CE404:;
    R[6] = R[3] - R[4];  /* 0x800CE404 */
L_800CE408:;
    R[2] = R[6] << 16;  /* 0x800CE408 */
    R[3] = R[18] << 16;  /* 0x800CE40C */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x800CE410 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE420; } }  /* 0x800CE414 */
    R[6] = R[18] + R[0];  /* 0x800CE41C */
L_800CE420:;
    R[2] = lh_(R[16] + 4);  /* 0x800CE420 */
    R[3] = R[2] + 256;  /* 0x800CE428 */
    R[2] = R[2] << 16;  /* 0x800CE42C */
    R[5] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CE430 */
    R[2] = ((int32_t)R[5] < 256);  /* 0x800CE434 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[3] & 0x1FF; if (_c) { goto L_800CE474; } }  /* 0x800CE438 */
    R[4] = R[7] + R[0];  /* 0x800CE440 */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800CE444 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[3]); if (_c) { goto L_800CE45C; } }  /* 0x800CE448 */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[2] = R[6] << 16; if (_c) { goto L_800CE48C; } }  /* 0x800CE450 */
    R[2] = ((int32_t)R[4] < (int32_t)R[3]);  /* 0x800CE458 */
L_800CE45C:;
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < 512); if (_c) { goto L_800CE494; } }  /* 0x800CE45C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[6] << 16; if (_c) { goto L_800CE494; } }  /* 0x800CE464 */
    { R[2] = (uint32_t)((int32_t)R[2] >> 16); goto L_800CE490; }  /* 0x800CE46C j */
L_800CE474:;
    R[4] = R[7] + R[0];  /* 0x800CE474 */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800CE478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[3]); if (_c) { goto L_800CE494; } }  /* 0x800CE47C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[6] << 16; if (_c) { goto L_800CE494; } }  /* 0x800CE484 */
L_800CE48C:;
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CE48C */
L_800CE490:;
    R[6] = R[0] - R[2];  /* 0x800CE490 */
L_800CE494:;
    R[2] = lh_(R[16] + 4);  /* 0x800CE494 */
    R[5] = lw_(R[16] + 28);  /* 0x800CE498 */
    R[2] = R[2] + R[6];  /* 0x800CE49C */
    R[2] = R[2] & 0x1FF;  /* 0x800CE4A0 */
    sh_(R[16] + 4, R[2]);  /* 0x800CE4A4 */
    sh_(R[16] + 6, R[2]);  /* 0x800CE4A8 */
    R[4] = lw_(R[17] + 28);  /* 0x800CE4AC */
    { uint32_t _c = (R[5] == R[4]); R[3] = R[4] - R[5]; if (_c) { goto L_800CE4E8; } }  /* 0x800CE4B4 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = ((int32_t)R[3] < (int32_t)R[19]); if (_c) { goto L_800CE4CC; } }  /* 0x800CE4BC */
    R[3] = R[5] - R[4];  /* 0x800CE4C4 */
    R[2] = ((int32_t)R[3] < (int32_t)R[19]);  /* 0x800CE4C8 */
L_800CE4CC:;
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[5]); if (_c) { goto L_800CE4D8; } }  /* 0x800CE4CC */
    R[3] = R[19] + R[0];  /* 0x800CE4D4 */
L_800CE4D8:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CE4E4; } }  /* 0x800CE4D8 */
    R[3] = R[0] - R[3];  /* 0x800CE4E0 */
L_800CE4E4:;
    sw_(R[16] + 200, R[3]);  /* 0x800CE4E4 */
L_800CE4E8:;
    R[31] = lw_(R[29] + 32);  /* 0x800CE4E8 */
    R[19] = lw_(R[29] + 28);  /* 0x800CE4EC */
    R[18] = lw_(R[29] + 24);  /* 0x800CE4F0 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE4F4 */
    R[16] = lw_(R[29] + 16);  /* 0x800CE4F8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CE4FC jr ra */
}

void g0_800CE388(void) {
    R[17] = R[2] + R[0];  /* 0x800CE388 */
    { uint32_t _c = (R[17] == R[0]); if (_c) { goto L_800CE4E8; } }  /* 0x800CE38C */
    R[3] = lw_(R[17] + 32);  /* 0x800CE394 */
    R[2] = lw_(R[16] + 32);  /* 0x800CE398 */
    R[4] = R[3] - R[2];  /* 0x800CE3A0 */
    { uint32_t _c = ((int32_t)R[4] >= 0); if (_c) { goto L_800CE3B0; } }  /* 0x800CE3A4 */
    R[4] = R[4] + 4095;  /* 0x800CE3AC */
L_800CE3B0:;
    R[3] = lw_(R[17] + 24);  /* 0x800CE3B0 */
    R[2] = lw_(R[16] + 24);  /* 0x800CE3B4 */
    R[3] = R[3] - R[2];  /* 0x800CE3BC */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = (uint32_t)((int32_t)R[4] >> 12); if (_c) { goto L_800CE3CC; } }  /* 0x800CE3C0 */
    R[3] = R[3] + 4095;  /* 0x800CE3C8 */
L_800CE3CC:;
    { R[31] = 0x800CE3D4u; R[5] = (uint32_t)((int32_t)R[3] >> 12); psx_next = 0x80037B38u; return; }  /* 0x800CE3CC jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CE3E0; } }  /* 0x800CE3D4 */
    R[2] = R[2] + 7;  /* 0x800CE3DC */
L_800CE3E0:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800CE3E0 */
    R[4] = R[2] & 0x1FF;  /* 0x800CE3E4 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 4);  /* 0x800CE3E8 */
    R[3] = lh_(R[16] + 4);  /* 0x800CE3EC */
    R[2] = R[4] - R[2];  /* 0x800CE3F0 */
    { uint32_t _c = ((int32_t)R[2] < 0); R[7] = R[4] + R[0]; if (_c) { goto L_800CE404; } }  /* 0x800CE3F4 */
    { R[6] = R[4] - R[3]; goto L_800CE408; }  /* 0x800CE3FC j */
L_800CE404:;
    R[6] = R[3] - R[4];  /* 0x800CE404 */
L_800CE408:;
    R[2] = R[6] << 16;  /* 0x800CE408 */
    R[3] = R[18] << 16;  /* 0x800CE40C */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x800CE410 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE420; } }  /* 0x800CE414 */
    R[6] = R[18] + R[0];  /* 0x800CE41C */
L_800CE420:;
    R[2] = lh_(R[16] + 4);  /* 0x800CE420 */
    R[3] = R[2] + 256;  /* 0x800CE428 */
    R[2] = R[2] << 16;  /* 0x800CE42C */
    R[5] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CE430 */
    R[2] = ((int32_t)R[5] < 256);  /* 0x800CE434 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[3] & 0x1FF; if (_c) { goto L_800CE474; } }  /* 0x800CE438 */
    R[4] = R[7] + R[0];  /* 0x800CE440 */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800CE444 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[3]); if (_c) { goto L_800CE45C; } }  /* 0x800CE448 */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[2] = R[6] << 16; if (_c) { goto L_800CE48C; } }  /* 0x800CE450 */
    R[2] = ((int32_t)R[4] < (int32_t)R[3]);  /* 0x800CE458 */
L_800CE45C:;
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < 512); if (_c) { goto L_800CE494; } }  /* 0x800CE45C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[6] << 16; if (_c) { goto L_800CE494; } }  /* 0x800CE464 */
    { R[2] = (uint32_t)((int32_t)R[2] >> 16); goto L_800CE490; }  /* 0x800CE46C j */
L_800CE474:;
    R[4] = R[7] + R[0];  /* 0x800CE474 */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800CE478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[3]); if (_c) { goto L_800CE494; } }  /* 0x800CE47C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[6] << 16; if (_c) { goto L_800CE494; } }  /* 0x800CE484 */
L_800CE48C:;
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CE48C */
L_800CE490:;
    R[6] = R[0] - R[2];  /* 0x800CE490 */
L_800CE494:;
    R[2] = lh_(R[16] + 4);  /* 0x800CE494 */
    R[5] = lw_(R[16] + 28);  /* 0x800CE498 */
    R[2] = R[2] + R[6];  /* 0x800CE49C */
    R[2] = R[2] & 0x1FF;  /* 0x800CE4A0 */
    sh_(R[16] + 4, R[2]);  /* 0x800CE4A4 */
    sh_(R[16] + 6, R[2]);  /* 0x800CE4A8 */
    R[4] = lw_(R[17] + 28);  /* 0x800CE4AC */
    { uint32_t _c = (R[5] == R[4]); R[3] = R[4] - R[5]; if (_c) { goto L_800CE4E8; } }  /* 0x800CE4B4 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = ((int32_t)R[3] < (int32_t)R[19]); if (_c) { goto L_800CE4CC; } }  /* 0x800CE4BC */
    R[3] = R[5] - R[4];  /* 0x800CE4C4 */
    R[2] = ((int32_t)R[3] < (int32_t)R[19]);  /* 0x800CE4C8 */
L_800CE4CC:;
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[5]); if (_c) { goto L_800CE4D8; } }  /* 0x800CE4CC */
    R[3] = R[19] + R[0];  /* 0x800CE4D4 */
L_800CE4D8:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CE4E4; } }  /* 0x800CE4D8 */
    R[3] = R[0] - R[3];  /* 0x800CE4E0 */
L_800CE4E4:;
    sw_(R[16] + 200, R[3]);  /* 0x800CE4E4 */
L_800CE4E8:;
    R[31] = lw_(R[29] + 32);  /* 0x800CE4E8 */
    R[19] = lw_(R[29] + 28);  /* 0x800CE4EC */
    R[18] = lw_(R[29] + 24);  /* 0x800CE4F0 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE4F4 */
    R[16] = lw_(R[29] + 16);  /* 0x800CE4F8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CE4FC jr ra */
}

void g0_800CE3D4(void) {
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CE3E0; } }  /* 0x800CE3D4 */
    R[2] = R[2] + 7;  /* 0x800CE3DC */
L_800CE3E0:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800CE3E0 */
    R[4] = R[2] & 0x1FF;  /* 0x800CE3E4 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 4);  /* 0x800CE3E8 */
    R[3] = lh_(R[16] + 4);  /* 0x800CE3EC */
    R[2] = R[4] - R[2];  /* 0x800CE3F0 */
    { uint32_t _c = ((int32_t)R[2] < 0); R[7] = R[4] + R[0]; if (_c) { goto L_800CE404; } }  /* 0x800CE3F4 */
    { R[6] = R[4] - R[3]; goto L_800CE408; }  /* 0x800CE3FC j */
L_800CE404:;
    R[6] = R[3] - R[4];  /* 0x800CE404 */
L_800CE408:;
    R[2] = R[6] << 16;  /* 0x800CE408 */
    R[3] = R[18] << 16;  /* 0x800CE40C */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x800CE410 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE420; } }  /* 0x800CE414 */
    R[6] = R[18] + R[0];  /* 0x800CE41C */
L_800CE420:;
    R[2] = lh_(R[16] + 4);  /* 0x800CE420 */
    R[3] = R[2] + 256;  /* 0x800CE428 */
    R[2] = R[2] << 16;  /* 0x800CE42C */
    R[5] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CE430 */
    R[2] = ((int32_t)R[5] < 256);  /* 0x800CE434 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[3] & 0x1FF; if (_c) { goto L_800CE474; } }  /* 0x800CE438 */
    R[4] = R[7] + R[0];  /* 0x800CE440 */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800CE444 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[3]); if (_c) { goto L_800CE45C; } }  /* 0x800CE448 */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[2] = R[6] << 16; if (_c) { goto L_800CE48C; } }  /* 0x800CE450 */
    R[2] = ((int32_t)R[4] < (int32_t)R[3]);  /* 0x800CE458 */
L_800CE45C:;
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < 512); if (_c) { goto L_800CE494; } }  /* 0x800CE45C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[6] << 16; if (_c) { goto L_800CE494; } }  /* 0x800CE464 */
    { R[2] = (uint32_t)((int32_t)R[2] >> 16); goto L_800CE490; }  /* 0x800CE46C j */
L_800CE474:;
    R[4] = R[7] + R[0];  /* 0x800CE474 */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800CE478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[3]); if (_c) { goto L_800CE494; } }  /* 0x800CE47C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[6] << 16; if (_c) { goto L_800CE494; } }  /* 0x800CE484 */
L_800CE48C:;
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CE48C */
L_800CE490:;
    R[6] = R[0] - R[2];  /* 0x800CE490 */
L_800CE494:;
    R[2] = lh_(R[16] + 4);  /* 0x800CE494 */
    R[5] = lw_(R[16] + 28);  /* 0x800CE498 */
    R[2] = R[2] + R[6];  /* 0x800CE49C */
    R[2] = R[2] & 0x1FF;  /* 0x800CE4A0 */
    sh_(R[16] + 4, R[2]);  /* 0x800CE4A4 */
    sh_(R[16] + 6, R[2]);  /* 0x800CE4A8 */
    R[4] = lw_(R[17] + 28);  /* 0x800CE4AC */
    { uint32_t _c = (R[5] == R[4]); R[3] = R[4] - R[5]; if (_c) { goto L_800CE4E8; } }  /* 0x800CE4B4 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = ((int32_t)R[3] < (int32_t)R[19]); if (_c) { goto L_800CE4CC; } }  /* 0x800CE4BC */
    R[3] = R[5] - R[4];  /* 0x800CE4C4 */
    R[2] = ((int32_t)R[3] < (int32_t)R[19]);  /* 0x800CE4C8 */
L_800CE4CC:;
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[5]); if (_c) { goto L_800CE4D8; } }  /* 0x800CE4CC */
    R[3] = R[19] + R[0];  /* 0x800CE4D4 */
L_800CE4D8:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CE4E4; } }  /* 0x800CE4D8 */
    R[3] = R[0] - R[3];  /* 0x800CE4E0 */
L_800CE4E4:;
    sw_(R[16] + 200, R[3]);  /* 0x800CE4E4 */
L_800CE4E8:;
    R[31] = lw_(R[29] + 32);  /* 0x800CE4E8 */
    R[19] = lw_(R[29] + 28);  /* 0x800CE4EC */
    R[18] = lw_(R[29] + 24);  /* 0x800CE4F0 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE4F4 */
    R[16] = lw_(R[29] + 16);  /* 0x800CE4F8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CE4FC jr ra */
}

void g0_800CE504(void) {
    R[29] = R[29] - 32;  /* 0x800CE504 */
    sw_(R[29] + 20, R[17]);  /* 0x800CE508 */
    R[17] = R[4] + R[0];  /* 0x800CE50C */
    sw_(R[29] + 24, R[18]);  /* 0x800CE510 */
    R[18] = R[5] + R[0];  /* 0x800CE514 */
    sw_(R[29] + 16, R[16]);  /* 0x800CE518 */
    sw_(R[29] + 28, R[31]);  /* 0x800CE51C */
    { R[31] = 0x800CE528u; R[16] = R[6] + R[0]; psx_next = 0x80093774u; return; }  /* 0x800CE520 jal */
    R[7] = R[2] + R[0];  /* 0x800CE528 */
    { uint32_t _c = ((int32_t)R[7] <= 0); R[2] = R[0] + R[0]; if (_c) { goto L_800CE618; } }  /* 0x800CE52C */
    R[2] = 0x8013u << 16;  /* 0x800CE534 */
    R[6] = R[2] - 31752;  /* 0x800CE538 */
    R[5] = R[0] + R[0];  /* 0x800CE53C */
    { uint32_t _c = ((int32_t)R[7] <= 0); R[4] = R[5] + R[0]; if (_c) { goto L_800CE614; } }  /* 0x800CE540 */
    R[9] = R[0] + 5;  /* 0x800CE548 */
    R[8] = 0xFFu << 16;  /* 0x800CE54C */
    R[8] = R[8] | 0xFF;  /* 0x800CE550 */
L_800CE554:;
    R[3] = lw_(R[6]);  /* 0x800CE554 */
    R[2] = lw_(R[3] + 220);  /* 0x800CE55C */
    { uint32_t _c = (R[17] != R[2]); if (_c) { goto L_800CE604; } }  /* 0x800CE564 */
    R[2] = lh_(R[3] + 12);  /* 0x800CE56C */
    R[2] = R[2] - 2;  /* 0x800CE574 */
    R[2] = (R[2] < (uint32_t)3u);  /* 0x800CE578 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CE604; } }  /* 0x800CE57C */
    R[2] = lb_(R[3] + 789);  /* 0x800CE584 */
    R[2] = R[2] & 0x1;  /* 0x800CE58C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE604; } }  /* 0x800CE590 */
    R[2] = lb_(R[3] + 791);  /* 0x800CE598 */
    { uint32_t _c = (R[2] == R[9]); if (_c) { goto L_800CE604; } }  /* 0x800CE5A0 */
    R[2] = lb_(R[3] + 787);  /* 0x800CE5A8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE604; } }  /* 0x800CE5B0 */
    R[2] = lw_(R[3] + 788);  /* 0x800CE5B8 */
    R[2] = R[2] & R[8];  /* 0x800CE5C0 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE604; } }  /* 0x800CE5C4 */
    R[2] = lh_(R[3] + 88);  /* 0x800CE5CC */
    R[2] = R[2] & 0x1000;  /* 0x800CE5D4 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE604; } }  /* 0x800CE5D8 */
    R[2] = lb_(R[3] + 797);  /* 0x800CE5E0 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE604; } }  /* 0x800CE5E8 */
    sw_(R[16], R[3]);  /* 0x800CE5F0 */
    R[4] = R[4] + 1;  /* 0x800CE5F4 */
    R[2] = ((int32_t)R[4] < (int32_t)R[18]);  /* 0x800CE5F8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = R[16] + 4; if (_c) { goto L_800CE614; } }  /* 0x800CE5FC */
L_800CE604:;
    R[5] = R[5] + 1;  /* 0x800CE604 */
    R[2] = ((int32_t)R[5] < (int32_t)R[7]);  /* 0x800CE608 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[6] + 4; if (_c) { psx_bb(); goto L_800CE554; } }  /* 0x800CE60C */
L_800CE614:;
    R[2] = R[4] + R[0];  /* 0x800CE614 */
L_800CE618:;
    R[31] = lw_(R[29] + 28);  /* 0x800CE618 */
    R[18] = lw_(R[29] + 24);  /* 0x800CE61C */
    R[17] = lw_(R[29] + 20);  /* 0x800CE620 */
    R[16] = lw_(R[29] + 16);  /* 0x800CE624 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CE628 jr ra */
}

void g0_800CE528(void) {
    R[7] = R[2] + R[0];  /* 0x800CE528 */
    { uint32_t _c = ((int32_t)R[7] <= 0); R[2] = R[0] + R[0]; if (_c) { goto L_800CE618; } }  /* 0x800CE52C */
    R[2] = 0x8013u << 16;  /* 0x800CE534 */
    R[6] = R[2] - 31752;  /* 0x800CE538 */
    R[5] = R[0] + R[0];  /* 0x800CE53C */
    { uint32_t _c = ((int32_t)R[7] <= 0); R[4] = R[5] + R[0]; if (_c) { goto L_800CE614; } }  /* 0x800CE540 */
    R[9] = R[0] + 5;  /* 0x800CE548 */
    R[8] = 0xFFu << 16;  /* 0x800CE54C */
    R[8] = R[8] | 0xFF;  /* 0x800CE550 */
L_800CE554:;
    R[3] = lw_(R[6]);  /* 0x800CE554 */
    R[2] = lw_(R[3] + 220);  /* 0x800CE55C */
    { uint32_t _c = (R[17] != R[2]); if (_c) { goto L_800CE604; } }  /* 0x800CE564 */
    R[2] = lh_(R[3] + 12);  /* 0x800CE56C */
    R[2] = R[2] - 2;  /* 0x800CE574 */
    R[2] = (R[2] < (uint32_t)3u);  /* 0x800CE578 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CE604; } }  /* 0x800CE57C */
    R[2] = lb_(R[3] + 789);  /* 0x800CE584 */
    R[2] = R[2] & 0x1;  /* 0x800CE58C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE604; } }  /* 0x800CE590 */
    R[2] = lb_(R[3] + 791);  /* 0x800CE598 */
    { uint32_t _c = (R[2] == R[9]); if (_c) { goto L_800CE604; } }  /* 0x800CE5A0 */
    R[2] = lb_(R[3] + 787);  /* 0x800CE5A8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE604; } }  /* 0x800CE5B0 */
    R[2] = lw_(R[3] + 788);  /* 0x800CE5B8 */
    R[2] = R[2] & R[8];  /* 0x800CE5C0 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE604; } }  /* 0x800CE5C4 */
    R[2] = lh_(R[3] + 88);  /* 0x800CE5CC */
    R[2] = R[2] & 0x1000;  /* 0x800CE5D4 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE604; } }  /* 0x800CE5D8 */
    R[2] = lb_(R[3] + 797);  /* 0x800CE5E0 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE604; } }  /* 0x800CE5E8 */
    sw_(R[16], R[3]);  /* 0x800CE5F0 */
    R[4] = R[4] + 1;  /* 0x800CE5F4 */
    R[2] = ((int32_t)R[4] < (int32_t)R[18]);  /* 0x800CE5F8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = R[16] + 4; if (_c) { goto L_800CE614; } }  /* 0x800CE5FC */
L_800CE604:;
    R[5] = R[5] + 1;  /* 0x800CE604 */
    R[2] = ((int32_t)R[5] < (int32_t)R[7]);  /* 0x800CE608 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[6] + 4; if (_c) { psx_bb(); goto L_800CE554; } }  /* 0x800CE60C */
L_800CE614:;
    R[2] = R[4] + R[0];  /* 0x800CE614 */
L_800CE618:;
    R[31] = lw_(R[29] + 28);  /* 0x800CE618 */
    R[18] = lw_(R[29] + 24);  /* 0x800CE61C */
    R[17] = lw_(R[29] + 20);  /* 0x800CE620 */
    R[16] = lw_(R[29] + 16);  /* 0x800CE624 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CE628 jr ra */
}

void g0_800CE630(void) {
    R[29] = R[29] - 40;  /* 0x800CE630 */
    sw_(R[29] + 16, R[16]);  /* 0x800CE634 */
    R[16] = R[4] + R[0];  /* 0x800CE638 */
    sw_(R[29] + 24, R[18]);  /* 0x800CE63C */
    R[18] = R[5] + R[0];  /* 0x800CE640 */
    R[2] = 0x8012u << 16;  /* 0x800CE644 */
    sw_(R[29] + 20, R[17]);  /* 0x800CE648 */
    R[17] = R[2] - 26864;  /* 0x800CE64C */
    sw_(R[29] + 32, R[31]);  /* 0x800CE650 */
    sw_(R[29] + 28, R[19]);  /* 0x800CE654 */
    R[3] = lw_(R[17] + 32);  /* 0x800CE658 */
    R[2] = lw_(R[16] + 16);  /* 0x800CE65C */
    R[4] = R[3] - R[2];  /* 0x800CE664 */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[19] = R[6] + R[0]; if (_c) { goto L_800CE674; } }  /* 0x800CE668 */
    R[4] = R[4] + 4095;  /* 0x800CE670 */
L_800CE674:;
    R[3] = lw_(R[17] + 24);  /* 0x800CE674 */
    R[2] = lw_(R[16] + 8);  /* 0x800CE678 */
    R[3] = R[3] - R[2];  /* 0x800CE680 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = (uint32_t)((int32_t)R[4] >> 12); if (_c) { goto L_800CE690; } }  /* 0x800CE684 */
    R[3] = R[3] + 4095;  /* 0x800CE68C */
L_800CE690:;
    { R[31] = 0x800CE698u; R[5] = (uint32_t)((int32_t)R[3] >> 12); psx_next = 0x80037B38u; return; }  /* 0x800CE690 jal */
    R[4] = R[2] & 0xFFF;  /* 0x800CE698 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 66);  /* 0x800CE69C */
    R[3] = lh_(R[16] + 66);  /* 0x800CE6A0 */
    R[2] = R[4] - R[2];  /* 0x800CE6A4 */
    { uint32_t _c = ((int32_t)R[2] < 0); R[7] = R[4] + R[0]; if (_c) { goto L_800CE6B8; } }  /* 0x800CE6A8 */
    { R[6] = R[4] - R[3]; goto L_800CE6BC; }  /* 0x800CE6B0 j */
L_800CE6B8:;
    R[6] = R[3] - R[4];  /* 0x800CE6B8 */
L_800CE6BC:;
    R[2] = R[6] << 16;  /* 0x800CE6BC */
    R[3] = (uint32_t)(int16_t)lh_(R[18]);  /* 0x800CE6C0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CE6C4 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x800CE6C8 */
    R[3] = lh_(R[18]);  /* 0x800CE6CC */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE6DC; } }  /* 0x800CE6D0 */
    R[6] = R[3] + R[0];  /* 0x800CE6D8 */
L_800CE6DC:;
    R[2] = lh_(R[16] + 66);  /* 0x800CE6DC */
    R[3] = R[2] + 2048;  /* 0x800CE6E4 */
    R[2] = R[2] << 16;  /* 0x800CE6E8 */
    R[5] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CE6EC */
    R[2] = ((int32_t)R[5] < 2048);  /* 0x800CE6F0 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[3] & 0xFFF; if (_c) { goto L_800CE730; } }  /* 0x800CE6F4 */
    R[4] = R[7] + R[0];  /* 0x800CE6FC */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800CE700 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[3]); if (_c) { goto L_800CE718; } }  /* 0x800CE704 */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[2] = R[6] << 16; if (_c) { goto L_800CE748; } }  /* 0x800CE70C */
    R[2] = ((int32_t)R[4] < (int32_t)R[3]);  /* 0x800CE714 */
L_800CE718:;
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < 4096); if (_c) { goto L_800CE750; } }  /* 0x800CE718 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[6] << 16; if (_c) { goto L_800CE750; } }  /* 0x800CE720 */
    { R[2] = (uint32_t)((int32_t)R[2] >> 16); goto L_800CE74C; }  /* 0x800CE728 j */
L_800CE730:;
    R[4] = R[7] + R[0];  /* 0x800CE730 */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800CE734 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[3]); if (_c) { goto L_800CE750; } }  /* 0x800CE738 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[6] << 16; if (_c) { goto L_800CE750; } }  /* 0x800CE740 */
L_800CE748:;
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CE748 */
L_800CE74C:;
    R[6] = R[0] - R[2];  /* 0x800CE74C */
L_800CE750:;
    R[2] = lh_(R[16] + 66);  /* 0x800CE750 */
    R[2] = R[2] + R[6];  /* 0x800CE758 */
    R[6] = lw_(R[16] + 12);  /* 0x800CE75C */
    R[2] = R[2] & 0xFFF;  /* 0x800CE760 */
    sh_(R[16] + 66, R[2]);  /* 0x800CE764 */
    R[3] = lw_(R[17] + 28);  /* 0x800CE768 */
    { uint32_t _c = (R[6] == R[3]); R[2] = 0x6u << 16; if (_c) { goto L_800CE7C0; } }  /* 0x800CE770 */
    R[2] = R[2] | 0x4000;  /* 0x800CE778 */
    R[2] = R[3] + R[2];  /* 0x800CE77C */
    R[4] = R[0] - R[2];  /* 0x800CE780 */
    R[3] = R[4] - R[6];  /* 0x800CE784 */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800CE794; } }  /* 0x800CE788 */
    R[3] = R[6] - R[4];  /* 0x800CE790 */
L_800CE794:;
    R[5] = lh_(R[19]);  /* 0x800CE794 */
    R[2] = ((int32_t)R[3] < (int32_t)R[5]);  /* 0x800CE79C */
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[6]); if (_c) { goto L_800CE7AC; } }  /* 0x800CE7A0 */
    R[3] = R[5] + R[0];  /* 0x800CE7A8 */
L_800CE7AC:;
    { uint32_t _c = (R[2] == R[0]); R[2] = R[6] + R[3]; if (_c) { goto L_800CE7BC; } }  /* 0x800CE7AC */
    R[3] = R[0] - R[3];  /* 0x800CE7B4 */
    R[2] = R[6] + R[3];  /* 0x800CE7B8 */
L_800CE7BC:;
    sw_(R[16] + 12, R[2]);  /* 0x800CE7BC */
L_800CE7C0:;
    R[2] = (uint32_t)(int16_t)lh_(R[18]);  /* 0x800CE7C0 */
    R[3] = lh_(R[18]);  /* 0x800CE7C4 */
    R[2] = ((int32_t)R[2] < 330);  /* 0x800CE7C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 5; if (_c) { goto L_800CE7D8; } }  /* 0x800CE7CC */
    sh_(R[18], R[2]);  /* 0x800CE7D4 */
L_800CE7D8:;
    R[2] = (uint32_t)(int16_t)lh_(R[19]);  /* 0x800CE7D8 */
    R[3] = lh_(R[19]);  /* 0x800CE7DC */
    { uint32_t _c = ((int32_t)R[2] < 0); R[2] = R[3] + 1024; if (_c) { goto L_800CE7EC; } }  /* 0x800CE7E0 */
    sh_(R[19], R[2]);  /* 0x800CE7E8 */
L_800CE7EC:;
    R[31] = lw_(R[29] + 32);  /* 0x800CE7EC */
    R[19] = lw_(R[29] + 28);  /* 0x800CE7F0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CE7F4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE7F8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CE7FC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CE800 jr ra */
}

void g0_800CE698(void) {
    R[4] = R[2] & 0xFFF;  /* 0x800CE698 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 66);  /* 0x800CE69C */
    R[3] = lh_(R[16] + 66);  /* 0x800CE6A0 */
    R[2] = R[4] - R[2];  /* 0x800CE6A4 */
    { uint32_t _c = ((int32_t)R[2] < 0); R[7] = R[4] + R[0]; if (_c) { goto L_800CE6B8; } }  /* 0x800CE6A8 */
    { R[6] = R[4] - R[3]; goto L_800CE6BC; }  /* 0x800CE6B0 j */
L_800CE6B8:;
    R[6] = R[3] - R[4];  /* 0x800CE6B8 */
L_800CE6BC:;
    R[2] = R[6] << 16;  /* 0x800CE6BC */
    R[3] = (uint32_t)(int16_t)lh_(R[18]);  /* 0x800CE6C0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CE6C4 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x800CE6C8 */
    R[3] = lh_(R[18]);  /* 0x800CE6CC */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CE6DC; } }  /* 0x800CE6D0 */
    R[6] = R[3] + R[0];  /* 0x800CE6D8 */
L_800CE6DC:;
    R[2] = lh_(R[16] + 66);  /* 0x800CE6DC */
    R[3] = R[2] + 2048;  /* 0x800CE6E4 */
    R[2] = R[2] << 16;  /* 0x800CE6E8 */
    R[5] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CE6EC */
    R[2] = ((int32_t)R[5] < 2048);  /* 0x800CE6F0 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[3] & 0xFFF; if (_c) { goto L_800CE730; } }  /* 0x800CE6F4 */
    R[4] = R[7] + R[0];  /* 0x800CE6FC */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800CE700 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[3]); if (_c) { goto L_800CE718; } }  /* 0x800CE704 */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[2] = R[6] << 16; if (_c) { goto L_800CE748; } }  /* 0x800CE70C */
    R[2] = ((int32_t)R[4] < (int32_t)R[3]);  /* 0x800CE714 */
L_800CE718:;
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < 4096); if (_c) { goto L_800CE750; } }  /* 0x800CE718 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[6] << 16; if (_c) { goto L_800CE750; } }  /* 0x800CE720 */
    { R[2] = (uint32_t)((int32_t)R[2] >> 16); goto L_800CE74C; }  /* 0x800CE728 j */
L_800CE730:;
    R[4] = R[7] + R[0];  /* 0x800CE730 */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800CE734 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[3]); if (_c) { goto L_800CE750; } }  /* 0x800CE738 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[6] << 16; if (_c) { goto L_800CE750; } }  /* 0x800CE740 */
L_800CE748:;
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CE748 */
L_800CE74C:;
    R[6] = R[0] - R[2];  /* 0x800CE74C */
L_800CE750:;
    R[2] = lh_(R[16] + 66);  /* 0x800CE750 */
    R[2] = R[2] + R[6];  /* 0x800CE758 */
    R[6] = lw_(R[16] + 12);  /* 0x800CE75C */
    R[2] = R[2] & 0xFFF;  /* 0x800CE760 */
    sh_(R[16] + 66, R[2]);  /* 0x800CE764 */
    R[3] = lw_(R[17] + 28);  /* 0x800CE768 */
    { uint32_t _c = (R[6] == R[3]); R[2] = 0x6u << 16; if (_c) { goto L_800CE7C0; } }  /* 0x800CE770 */
    R[2] = R[2] | 0x4000;  /* 0x800CE778 */
    R[2] = R[3] + R[2];  /* 0x800CE77C */
    R[4] = R[0] - R[2];  /* 0x800CE780 */
    R[3] = R[4] - R[6];  /* 0x800CE784 */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800CE794; } }  /* 0x800CE788 */
    R[3] = R[6] - R[4];  /* 0x800CE790 */
L_800CE794:;
    R[5] = lh_(R[19]);  /* 0x800CE794 */
    R[2] = ((int32_t)R[3] < (int32_t)R[5]);  /* 0x800CE79C */
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[6]); if (_c) { goto L_800CE7AC; } }  /* 0x800CE7A0 */
    R[3] = R[5] + R[0];  /* 0x800CE7A8 */
L_800CE7AC:;
    { uint32_t _c = (R[2] == R[0]); R[2] = R[6] + R[3]; if (_c) { goto L_800CE7BC; } }  /* 0x800CE7AC */
    R[3] = R[0] - R[3];  /* 0x800CE7B4 */
    R[2] = R[6] + R[3];  /* 0x800CE7B8 */
L_800CE7BC:;
    sw_(R[16] + 12, R[2]);  /* 0x800CE7BC */
L_800CE7C0:;
    R[2] = (uint32_t)(int16_t)lh_(R[18]);  /* 0x800CE7C0 */
    R[3] = lh_(R[18]);  /* 0x800CE7C4 */
    R[2] = ((int32_t)R[2] < 330);  /* 0x800CE7C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 5; if (_c) { goto L_800CE7D8; } }  /* 0x800CE7CC */
    sh_(R[18], R[2]);  /* 0x800CE7D4 */
L_800CE7D8:;
    R[2] = (uint32_t)(int16_t)lh_(R[19]);  /* 0x800CE7D8 */
    R[3] = lh_(R[19]);  /* 0x800CE7DC */
    { uint32_t _c = ((int32_t)R[2] < 0); R[2] = R[3] + 1024; if (_c) { goto L_800CE7EC; } }  /* 0x800CE7E0 */
    sh_(R[19], R[2]);  /* 0x800CE7E8 */
L_800CE7EC:;
    R[31] = lw_(R[29] + 32);  /* 0x800CE7EC */
    R[19] = lw_(R[29] + 28);  /* 0x800CE7F0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CE7F4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE7F8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CE7FC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CE800 jr ra */
}

void g0_800CE808(void) {
    R[29] = R[29] - 48;  /* 0x800CE808 */
    sw_(R[29] + 36, R[21]);  /* 0x800CE80C */
    R[21] = R[4] + R[0];  /* 0x800CE810 */
    sw_(R[29] + 20, R[17]);  /* 0x800CE814 */
    R[17] = R[5] + R[0];  /* 0x800CE818 */
    sw_(R[29] + 40, R[31]);  /* 0x800CE81C */
    sw_(R[29] + 32, R[20]);  /* 0x800CE820 */
    sw_(R[29] + 28, R[19]);  /* 0x800CE824 */
    sw_(R[29] + 24, R[18]);  /* 0x800CE828 */
    { R[31] = 0x800CE834u; sw_(R[29] + 16, R[16]); psx_next = 0x80030E88u; return; }  /* 0x800CE82C jal */
    R[19] = R[2] & 0xFFF;  /* 0x800CE834 */
    R[18] = R[0] + R[0];  /* 0x800CE838 */
    R[20] = 0x800Fu << 16;  /* 0x800CE83C */
    R[16] = R[17] + 66;  /* 0x800CE840 */
L_800CE844:;
    R[4] = R[0] + R[0];  /* 0x800CE844 */
    R[5] = R[17] + R[0];  /* 0x800CE848 */
    R[6] = R[20] - 244;  /* 0x800CE84C */
    { R[31] = 0x800CE858u; R[7] = R[21] + R[0]; psx_next = 0x800A5964u; return; }  /* 0x800CE850 jal */
    R[3] = R[18] << 2;  /* 0x800CE858 */
    R[2] = lh_(R[17]);  /* 0x800CE85C */
    R[18] = R[18] + 1;  /* 0x800CE860 */
    R[2] = R[2] & 0x7FFF;  /* 0x800CE864 */
    sh_(R[17], R[2]);  /* 0x800CE868 */
    R[2] = R[19] - 1365;  /* 0x800CE86C */
    sh_(R[16], R[19]);  /* 0x800CE870 */
    R[19] = R[2] & 0xFFF;  /* 0x800CE874 */
    sb_(R[16] + -2, R[0]);  /* 0x800CE878 */
    sb_(R[16] + -1, R[3]);  /* 0x800CE87C */
    R[16] = R[16] + 72;  /* 0x800CE880 */
    R[2] = ((int32_t)R[18] < 3);  /* 0x800CE884 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 72; if (_c) { psx_bb(); goto L_800CE844; } }  /* 0x800CE888 */
    R[31] = lw_(R[29] + 40);  /* 0x800CE890 */
    R[21] = lw_(R[29] + 36);  /* 0x800CE894 */
    R[20] = lw_(R[29] + 32);  /* 0x800CE898 */
    R[19] = lw_(R[29] + 28);  /* 0x800CE89C */
    R[18] = lw_(R[29] + 24);  /* 0x800CE8A0 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE8A4 */
    R[16] = lw_(R[29] + 16);  /* 0x800CE8A8 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800CE8AC jr ra */
}

void g0_800CE834(void) {
    R[19] = R[2] & 0xFFF;  /* 0x800CE834 */
    R[18] = R[0] + R[0];  /* 0x800CE838 */
    R[20] = 0x800Fu << 16;  /* 0x800CE83C */
    R[16] = R[17] + 66;  /* 0x800CE840 */
L_800CE844:;
    R[4] = R[0] + R[0];  /* 0x800CE844 */
    R[5] = R[17] + R[0];  /* 0x800CE848 */
    R[6] = R[20] - 244;  /* 0x800CE84C */
    { R[31] = 0x800CE858u; R[7] = R[21] + R[0]; psx_next = 0x800A5964u; return; }  /* 0x800CE850 jal */
    R[3] = R[18] << 2;  /* 0x800CE858 */
    R[2] = lh_(R[17]);  /* 0x800CE85C */
    R[18] = R[18] + 1;  /* 0x800CE860 */
    R[2] = R[2] & 0x7FFF;  /* 0x800CE864 */
    sh_(R[17], R[2]);  /* 0x800CE868 */
    R[2] = R[19] - 1365;  /* 0x800CE86C */
    sh_(R[16], R[19]);  /* 0x800CE870 */
    R[19] = R[2] & 0xFFF;  /* 0x800CE874 */
    sb_(R[16] + -2, R[0]);  /* 0x800CE878 */
    sb_(R[16] + -1, R[3]);  /* 0x800CE87C */
    R[16] = R[16] + 72;  /* 0x800CE880 */
    R[2] = ((int32_t)R[18] < 3);  /* 0x800CE884 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 72; if (_c) { psx_bb(); goto L_800CE844; } }  /* 0x800CE888 */
    R[31] = lw_(R[29] + 40);  /* 0x800CE890 */
    R[21] = lw_(R[29] + 36);  /* 0x800CE894 */
    R[20] = lw_(R[29] + 32);  /* 0x800CE898 */
    R[19] = lw_(R[29] + 28);  /* 0x800CE89C */
    R[18] = lw_(R[29] + 24);  /* 0x800CE8A0 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE8A4 */
    R[16] = lw_(R[29] + 16);  /* 0x800CE8A8 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800CE8AC jr ra */
}

void g0_800CE844(void) {
L_800CE844:;
    R[4] = R[0] + R[0];  /* 0x800CE844 */
    R[5] = R[17] + R[0];  /* 0x800CE848 */
    R[6] = R[20] - 244;  /* 0x800CE84C */
    { R[31] = 0x800CE858u; R[7] = R[21] + R[0]; psx_next = 0x800A5964u; return; }  /* 0x800CE850 jal */
    R[3] = R[18] << 2;  /* 0x800CE858 */
    R[2] = lh_(R[17]);  /* 0x800CE85C */
    R[18] = R[18] + 1;  /* 0x800CE860 */
    R[2] = R[2] & 0x7FFF;  /* 0x800CE864 */
    sh_(R[17], R[2]);  /* 0x800CE868 */
    R[2] = R[19] - 1365;  /* 0x800CE86C */
    sh_(R[16], R[19]);  /* 0x800CE870 */
    R[19] = R[2] & 0xFFF;  /* 0x800CE874 */
    sb_(R[16] + -2, R[0]);  /* 0x800CE878 */
    sb_(R[16] + -1, R[3]);  /* 0x800CE87C */
    R[16] = R[16] + 72;  /* 0x800CE880 */
    R[2] = ((int32_t)R[18] < 3);  /* 0x800CE884 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 72; if (_c) { psx_bb(); goto L_800CE844; } }  /* 0x800CE888 */
    R[31] = lw_(R[29] + 40);  /* 0x800CE890 */
    R[21] = lw_(R[29] + 36);  /* 0x800CE894 */
    R[20] = lw_(R[29] + 32);  /* 0x800CE898 */
    R[19] = lw_(R[29] + 28);  /* 0x800CE89C */
    R[18] = lw_(R[29] + 24);  /* 0x800CE8A0 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE8A4 */
    R[16] = lw_(R[29] + 16);  /* 0x800CE8A8 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800CE8AC jr ra */
}

void g0_800CE858(void) {
    R[3] = R[18] << 2;  /* 0x800CE858 */
    R[2] = lh_(R[17]);  /* 0x800CE85C */
    R[18] = R[18] + 1;  /* 0x800CE860 */
    R[2] = R[2] & 0x7FFF;  /* 0x800CE864 */
    sh_(R[17], R[2]);  /* 0x800CE868 */
    R[2] = R[19] - 1365;  /* 0x800CE86C */
    sh_(R[16], R[19]);  /* 0x800CE870 */
    R[19] = R[2] & 0xFFF;  /* 0x800CE874 */
    sb_(R[16] + -2, R[0]);  /* 0x800CE878 */
    sb_(R[16] + -1, R[3]);  /* 0x800CE87C */
    R[16] = R[16] + 72;  /* 0x800CE880 */
    R[2] = ((int32_t)R[18] < 3);  /* 0x800CE884 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 72; if (_c) { psx_next = 0x800CE844u; return; } }  /* 0x800CE888 b extern */
    R[31] = lw_(R[29] + 40);  /* 0x800CE890 */
    R[21] = lw_(R[29] + 36);  /* 0x800CE894 */
    R[20] = lw_(R[29] + 32);  /* 0x800CE898 */
    R[19] = lw_(R[29] + 28);  /* 0x800CE89C */
    R[18] = lw_(R[29] + 24);  /* 0x800CE8A0 */
    R[17] = lw_(R[29] + 20);  /* 0x800CE8A4 */
    R[16] = lw_(R[29] + 16);  /* 0x800CE8A8 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800CE8AC jr ra */
}

void g0_800CE8B4(void) {
    R[29] = R[29] - 88;  /* 0x800CE8B4 */
    sw_(R[29] + 68, R[21]);  /* 0x800CE8B8 */
    R[21] = R[4] + R[0];  /* 0x800CE8BC */
    sw_(R[29] + 56, R[18]);  /* 0x800CE8C0 */
    R[18] = R[5] + R[0];  /* 0x800CE8C4 */
    sw_(R[29] + 76, R[23]);  /* 0x800CE8C8 */
    R[23] = R[18] + R[0];  /* 0x800CE8CC */
    sw_(R[29] + 72, R[22]);  /* 0x800CE8D0 */
    R[22] = R[0] + R[0];  /* 0x800CE8D4 */
    sw_(R[29] + 64, R[20]);  /* 0x800CE8D8 */
    R[20] = R[22] + R[0];  /* 0x800CE8DC */
    sw_(R[29] + 80, R[30]);  /* 0x800CE8E0 */
    R[30] = R[0] + 255;  /* 0x800CE8E4 */
    sw_(R[29] + 60, R[19]);  /* 0x800CE8E8 */
    R[19] = 0x8001u << 16;  /* 0x800CE8EC */
    R[19] = R[19] | 0x28;  /* 0x800CE8F0 */
    sw_(R[29] + 48, R[16]);  /* 0x800CE8F4 */
    R[16] = R[18] + 16;  /* 0x800CE8F8 */
    sw_(R[29] + 84, R[31]);  /* 0x800CE8FC */
    sw_(R[29] + 52, R[17]);  /* 0x800CE900 */
L_800CE904:;
    R[2] = lb_(R[16] + -14);  /* 0x800CE904 */
    R[2] = R[2] & 0x1;  /* 0x800CE90C */
    { uint32_t _c = (R[2] == R[0]); R[8] = R[0] + 2; if (_c) { goto L_800CEBC8; } }  /* 0x800CE910 */
    R[3] = lb_(R[16] + 48);  /* 0x800CE918 */
    R[2] = R[0] + 1;  /* 0x800CE91C */
    { uint32_t _c = (R[3] == R[2]); sb_(R[16] + -13, R[8]); if (_c) { goto L_800CE998; } }  /* 0x800CE920 */
    R[2] = ((int32_t)R[3] < 2);  /* 0x800CE928 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_800CE944; } }  /* 0x800CE92C */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_800CE95C; } }  /* 0x800CE934 */
    { R[22] = R[22] + 1; goto L_800CEBC8; }  /* 0x800CE93C j */
L_800CE944:;
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 3; if (_c) { goto L_800CEA3C; } }  /* 0x800CE944 */
    { uint32_t _c = (R[3] == R[2]); R[4] = R[29] + 16; if (_c) { goto L_800CEA6C; } }  /* 0x800CE94C */
    { R[22] = R[22] + 1; goto L_800CEBC8; }  /* 0x800CE954 j */
L_800CE95C:;
    R[2] = lb_(R[16] + 49);  /* 0x800CE95C */
    R[2] = R[2] - 1;  /* 0x800CE964 */
    sb_(R[16] + 49, R[2]);  /* 0x800CE968 */
    R[2] = R[2] & 0xFF;  /* 0x800CE96C */
    { uint32_t _c = (R[2] != R[30]); R[2] = R[0] + 8; if (_c) { goto L_800CEBC4; } }  /* 0x800CE970 */
    sb_(R[16] + 49, R[2]);  /* 0x800CE978 */
    R[2] = lh_(R[18]);  /* 0x800CE97C */
    R[2] = R[2] | 0x8000;  /* 0x800CE984 */
    sh_(R[18], R[2]);  /* 0x800CE988 */
    R[2] = lb_(R[16] + 48);  /* 0x800CE98C */
    { R[2] = R[2] + 1; goto L_800CEA64; }  /* 0x800CE990 j */
L_800CE998:;
    R[2] = lb_(R[16] + 49);  /* 0x800CE998 */
    R[2] = R[2] - 1;  /* 0x800CE9A0 */
    sb_(R[16] + 49, R[2]);  /* 0x800CE9A4 */
    R[2] = R[2] & 0xFF;  /* 0x800CE9A8 */
    { uint32_t _c = (R[2] != R[30]); R[8] = R[0] + 2; if (_c) { goto L_800CE9C4; } }  /* 0x800CE9AC */
    R[2] = lb_(R[16] + 48);  /* 0x800CE9B4 */
    sb_(R[16] + 49, R[8]);  /* 0x800CE9B8 */
    R[2] = R[2] + 1;  /* 0x800CE9BC */
    sb_(R[16] + 48, R[2]);  /* 0x800CE9C0 */
L_800CE9C4:;
    R[2] = lb_(R[16] + 49);  /* 0x800CE9C4 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CE9C8 */
    { R[31] = 0x800CE9D4u; R[17] = R[2] << 14; psx_next = 0x80035B18u; return; }  /* 0x800CE9CC jal */
    R[4] = R[2] + R[0];  /* 0x800CE9D4 */
    { uint32_t _t = R[19]; R[31] = 0x800CE9E0u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CE9D8 jalr */
    R[3] = lw_(R[16] + -8);  /* 0x800CE9E0 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CE9E4 */
    R[3] = R[3] + R[2];  /* 0x800CE9E8 */
    { R[31] = 0x800CE9F4u; sw_(R[16] + -8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CE9EC jal */
    R[4] = R[2] + R[0];  /* 0x800CE9F4 */
    { uint32_t _t = R[19]; R[31] = 0x800CEA00u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CE9F8 jalr */
    R[4] = R[0] + 4096;  /* 0x800CEA00 */
    R[3] = lw_(R[16]);  /* 0x800CEA04 */
    R[5] = R[17] + R[0];  /* 0x800CEA08 */
    R[3] = R[3] + R[2];  /* 0x800CEA0C */
    { uint32_t _t = R[19]; R[31] = 0x800CEA18u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEA10 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_800CEA28; } }  /* 0x800CEA18 */
    R[2] = R[2] + 4095;  /* 0x800CEA20 */
    R[3] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEA24 */
L_800CEA28:;
    R[2] = R[0] + 64;  /* 0x800CEA28 */
    R[2] = R[2] - R[3];  /* 0x800CEA2C */
    sb_(R[16] + 37, R[2]);  /* 0x800CEA30 */
    { sb_(R[16] + 36, R[2]); goto L_800CEBC4; }  /* 0x800CEA34 j */
L_800CEA3C:;
    R[2] = lb_(R[16] + 49);  /* 0x800CEA3C */
    R[2] = R[2] - 1;  /* 0x800CEA44 */
    sb_(R[16] + 49, R[2]);  /* 0x800CEA48 */
    R[2] = R[2] & 0xFF;  /* 0x800CEA4C */
    { uint32_t _c = (R[2] != R[30]); if (_c) { goto L_800CEBC4; } }  /* 0x800CEA50 */
    R[2] = lb_(R[16] + 48);  /* 0x800CEA58 */
    sb_(R[16] + 49, R[0]);  /* 0x800CEA5C */
    R[2] = R[2] + 1;  /* 0x800CEA60 */
L_800CEA64:;
    { sb_(R[16] + 48, R[2]); goto L_800CEBC4; }  /* 0x800CEA64 j */
L_800CEA6C:;
    R[8] = 0x8012u << 16;  /* 0x800CEA6C */
    R[2] = lw_(R[16] + -8);  /* 0x800CEA70 */
    R[8] = R[8] - 26864;  /* 0x800CEA74 */
    sw_(R[29] + 16, R[2]);  /* 0x800CEA78 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEA7C */
    R[5] = R[8] + 24;  /* 0x800CEA80 */
    R[2] = R[0] - R[2];  /* 0x800CEA84 */
    sw_(R[29] + 20, R[2]);  /* 0x800CEA88 */
    R[2] = lw_(R[16]);  /* 0x800CEA8C */
    R[6] = R[0] + 500;  /* 0x800CEA90 */
    { R[31] = 0x800CEA9Cu; sw_(R[29] + 24, R[2]); psx_next = 0x800B6A98u; return; }  /* 0x800CEA94 jal */
    R[2] = (R[2] < (uint32_t)20480u);  /* 0x800CEA9C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_800CEAB4; } }  /* 0x800CEAA0 */
    sh_(R[18], R[0]);  /* 0x800CEAA8 */
    { sb_(R[16] + -14, R[0]); goto L_800CEBC4; }  /* 0x800CEAAC j */
L_800CEAB4:;
    R[5] = R[21] + 592;  /* 0x800CEAB4 */
    { R[31] = 0x800CEAC0u; R[6] = R[21] + 594; psx_next = 0x800CE630u; return; }  /* 0x800CEAB8 jal */
    R[3] = lb_(R[16] + 49);  /* 0x800CEAC0 */
    R[2] = (R[3] < (uint32_t)33u);  /* 0x800CEAC8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] + 1; if (_c) { goto L_800CEAE8; } }  /* 0x800CEACC */
    R[2] = lh_(R[21] + 592);  /* 0x800CEAD4 */
    R[17] = 0x2u << 16;  /* 0x800CEAD8 */
    R[2] = R[2] + 1;  /* 0x800CEADC */
    { sh_(R[21] + 592, R[2]); goto L_800CEAF4; }  /* 0x800CEAE0 j */
L_800CEAE8:;
    sb_(R[16] + 49, R[2]);  /* 0x800CEAE8 */
    R[2] = R[2] & 0xFF;  /* 0x800CEAEC */
    R[17] = R[2] << 12;  /* 0x800CEAF0 */
L_800CEAF4:;
    R[2] = 0x1u << 16;  /* 0x800CEAF4 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEAF8 */
    { R[31] = 0x800CEB04u; R[17] = R[17] + R[2]; psx_next = 0x80035B18u; return; }  /* 0x800CEAFC jal */
    R[4] = R[2] + R[0];  /* 0x800CEB04 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB10u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB08 jalr */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB10 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEB14 */
    R[3] = R[3] + R[2];  /* 0x800CEB18 */
    { R[31] = 0x800CEB24u; sw_(R[16] + -8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CEB1C jal */
    R[4] = R[2] + R[0];  /* 0x800CEB24 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB30u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB28 jalr */
    R[4] = R[0] + 4096;  /* 0x800CEB30 */
    R[3] = lw_(R[16]);  /* 0x800CEB34 */
    R[5] = R[17] + R[0];  /* 0x800CEB38 */
    R[3] = R[3] + R[2];  /* 0x800CEB3C */
    { uint32_t _t = R[19]; R[31] = 0x800CEB48u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEB40 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CEB54; } }  /* 0x800CEB48 */
    R[2] = R[2] + 4095;  /* 0x800CEB50 */
L_800CEB54:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEB54 */
    R[3] = R[0] + 64;  /* 0x800CEB58 */
    R[4] = lb_(R[16] + 49);  /* 0x800CEB5C */
    R[3] = R[3] - R[2];  /* 0x800CEB60 */
    sb_(R[16] + 37, R[3]);  /* 0x800CEB64 */
    R[4] = R[4] & 0x3;  /* 0x800CEB68 */
    { uint32_t _c = (R[4] != R[0]); sb_(R[16] + 36, R[3]); if (_c) { goto L_800CEBB4; } }  /* 0x800CEB6C */
    R[4] = R[23] + 216;  /* 0x800CEB74 */
    { R[31] = 0x800CEB80u; R[5] = R[0] + 16; psx_next = 0x800BDFDCu; return; }  /* 0x800CEB78 jal */
    R[4] = R[2] + R[0];  /* 0x800CEB80 */
    R[5] = R[29] + 32;  /* 0x800CEB84 */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB88 */
    R[6] = R[0] + 32;  /* 0x800CEB8C */
    sw_(R[29] + 32, R[3]);  /* 0x800CEB90 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEB94 */
    R[7] = 0x800Fu << 16;  /* 0x800CEB98 */
    R[2] = R[0] - R[2];  /* 0x800CEB9C */
    sw_(R[29] + 36, R[2]);  /* 0x800CEBA0 */
    R[2] = lw_(R[16]);  /* 0x800CEBA4 */
    R[7] = R[7] - 372;  /* 0x800CEBA8 */
    { R[31] = 0x800CEBB4u; sw_(R[29] + 40, R[2]); psx_next = 0x800CDD84u; return; }  /* 0x800CEBAC jal */
L_800CEBB4:;
    R[4] = R[23] + 216;  /* 0x800CEBB4 */
    R[5] = R[0] + 13;  /* 0x800CEBB8 */
    { R[31] = 0x800CEBC4u; R[6] = R[0] + 24576; psx_next = 0x800CDE50u; return; }  /* 0x800CEBBC jal */
L_800CEBC4:;
    R[22] = R[22] + 1;  /* 0x800CEBC4 */
L_800CEBC8:;
    R[16] = R[16] + 72;  /* 0x800CEBC8 */
    R[20] = R[20] + 1;  /* 0x800CEBCC */
    R[2] = ((int32_t)R[20] < 3);  /* 0x800CEBD0 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_bb(); goto L_800CE904; } }  /* 0x800CEBD4 */
    R[2] = R[22] + R[0];  /* 0x800CEBDC */
    R[31] = lw_(R[29] + 84);  /* 0x800CEBE0 */
    R[30] = lw_(R[29] + 80);  /* 0x800CEBE4 */
    R[23] = lw_(R[29] + 76);  /* 0x800CEBE8 */
    R[22] = lw_(R[29] + 72);  /* 0x800CEBEC */
    R[21] = lw_(R[29] + 68);  /* 0x800CEBF0 */
    R[20] = lw_(R[29] + 64);  /* 0x800CEBF4 */
    R[19] = lw_(R[29] + 60);  /* 0x800CEBF8 */
    R[18] = lw_(R[29] + 56);  /* 0x800CEBFC */
    R[17] = lw_(R[29] + 52);  /* 0x800CEC00 */
    R[16] = lw_(R[29] + 48);  /* 0x800CEC04 */
    { R[29] = R[29] + 88; psx_next = R[31]; return; }  /* 0x800CEC08 jr ra */
}

void g0_800CE904(void) {
L_800CE904:;
    R[2] = lb_(R[16] + -14);  /* 0x800CE904 */
    R[2] = R[2] & 0x1;  /* 0x800CE90C */
    { uint32_t _c = (R[2] == R[0]); R[8] = R[0] + 2; if (_c) { goto L_800CEBC8; } }  /* 0x800CE910 */
    R[3] = lb_(R[16] + 48);  /* 0x800CE918 */
    R[2] = R[0] + 1;  /* 0x800CE91C */
    { uint32_t _c = (R[3] == R[2]); sb_(R[16] + -13, R[8]); if (_c) { goto L_800CE998; } }  /* 0x800CE920 */
    R[2] = ((int32_t)R[3] < 2);  /* 0x800CE928 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_800CE944; } }  /* 0x800CE92C */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_800CE95C; } }  /* 0x800CE934 */
    { R[22] = R[22] + 1; goto L_800CEBC8; }  /* 0x800CE93C j */
L_800CE944:;
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 3; if (_c) { goto L_800CEA3C; } }  /* 0x800CE944 */
    { uint32_t _c = (R[3] == R[2]); R[4] = R[29] + 16; if (_c) { goto L_800CEA6C; } }  /* 0x800CE94C */
    { R[22] = R[22] + 1; goto L_800CEBC8; }  /* 0x800CE954 j */
L_800CE95C:;
    R[2] = lb_(R[16] + 49);  /* 0x800CE95C */
    R[2] = R[2] - 1;  /* 0x800CE964 */
    sb_(R[16] + 49, R[2]);  /* 0x800CE968 */
    R[2] = R[2] & 0xFF;  /* 0x800CE96C */
    { uint32_t _c = (R[2] != R[30]); R[2] = R[0] + 8; if (_c) { goto L_800CEBC4; } }  /* 0x800CE970 */
    sb_(R[16] + 49, R[2]);  /* 0x800CE978 */
    R[2] = lh_(R[18]);  /* 0x800CE97C */
    R[2] = R[2] | 0x8000;  /* 0x800CE984 */
    sh_(R[18], R[2]);  /* 0x800CE988 */
    R[2] = lb_(R[16] + 48);  /* 0x800CE98C */
    { R[2] = R[2] + 1; goto L_800CEA64; }  /* 0x800CE990 j */
L_800CE998:;
    R[2] = lb_(R[16] + 49);  /* 0x800CE998 */
    R[2] = R[2] - 1;  /* 0x800CE9A0 */
    sb_(R[16] + 49, R[2]);  /* 0x800CE9A4 */
    R[2] = R[2] & 0xFF;  /* 0x800CE9A8 */
    { uint32_t _c = (R[2] != R[30]); R[8] = R[0] + 2; if (_c) { goto L_800CE9C4; } }  /* 0x800CE9AC */
    R[2] = lb_(R[16] + 48);  /* 0x800CE9B4 */
    sb_(R[16] + 49, R[8]);  /* 0x800CE9B8 */
    R[2] = R[2] + 1;  /* 0x800CE9BC */
    sb_(R[16] + 48, R[2]);  /* 0x800CE9C0 */
L_800CE9C4:;
    R[2] = lb_(R[16] + 49);  /* 0x800CE9C4 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CE9C8 */
    { R[31] = 0x800CE9D4u; R[17] = R[2] << 14; psx_next = 0x80035B18u; return; }  /* 0x800CE9CC jal */
    R[4] = R[2] + R[0];  /* 0x800CE9D4 */
    { uint32_t _t = R[19]; R[31] = 0x800CE9E0u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CE9D8 jalr */
    R[3] = lw_(R[16] + -8);  /* 0x800CE9E0 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CE9E4 */
    R[3] = R[3] + R[2];  /* 0x800CE9E8 */
    { R[31] = 0x800CE9F4u; sw_(R[16] + -8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CE9EC jal */
    R[4] = R[2] + R[0];  /* 0x800CE9F4 */
    { uint32_t _t = R[19]; R[31] = 0x800CEA00u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CE9F8 jalr */
    R[4] = R[0] + 4096;  /* 0x800CEA00 */
    R[3] = lw_(R[16]);  /* 0x800CEA04 */
    R[5] = R[17] + R[0];  /* 0x800CEA08 */
    R[3] = R[3] + R[2];  /* 0x800CEA0C */
    { uint32_t _t = R[19]; R[31] = 0x800CEA18u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEA10 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_800CEA28; } }  /* 0x800CEA18 */
    R[2] = R[2] + 4095;  /* 0x800CEA20 */
    R[3] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEA24 */
L_800CEA28:;
    R[2] = R[0] + 64;  /* 0x800CEA28 */
    R[2] = R[2] - R[3];  /* 0x800CEA2C */
    sb_(R[16] + 37, R[2]);  /* 0x800CEA30 */
    { sb_(R[16] + 36, R[2]); goto L_800CEBC4; }  /* 0x800CEA34 j */
L_800CEA3C:;
    R[2] = lb_(R[16] + 49);  /* 0x800CEA3C */
    R[2] = R[2] - 1;  /* 0x800CEA44 */
    sb_(R[16] + 49, R[2]);  /* 0x800CEA48 */
    R[2] = R[2] & 0xFF;  /* 0x800CEA4C */
    { uint32_t _c = (R[2] != R[30]); if (_c) { goto L_800CEBC4; } }  /* 0x800CEA50 */
    R[2] = lb_(R[16] + 48);  /* 0x800CEA58 */
    sb_(R[16] + 49, R[0]);  /* 0x800CEA5C */
    R[2] = R[2] + 1;  /* 0x800CEA60 */
L_800CEA64:;
    { sb_(R[16] + 48, R[2]); goto L_800CEBC4; }  /* 0x800CEA64 j */
L_800CEA6C:;
    R[8] = 0x8012u << 16;  /* 0x800CEA6C */
    R[2] = lw_(R[16] + -8);  /* 0x800CEA70 */
    R[8] = R[8] - 26864;  /* 0x800CEA74 */
    sw_(R[29] + 16, R[2]);  /* 0x800CEA78 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEA7C */
    R[5] = R[8] + 24;  /* 0x800CEA80 */
    R[2] = R[0] - R[2];  /* 0x800CEA84 */
    sw_(R[29] + 20, R[2]);  /* 0x800CEA88 */
    R[2] = lw_(R[16]);  /* 0x800CEA8C */
    R[6] = R[0] + 500;  /* 0x800CEA90 */
    { R[31] = 0x800CEA9Cu; sw_(R[29] + 24, R[2]); psx_next = 0x800B6A98u; return; }  /* 0x800CEA94 jal */
    R[2] = (R[2] < (uint32_t)20480u);  /* 0x800CEA9C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_800CEAB4; } }  /* 0x800CEAA0 */
    sh_(R[18], R[0]);  /* 0x800CEAA8 */
    { sb_(R[16] + -14, R[0]); goto L_800CEBC4; }  /* 0x800CEAAC j */
L_800CEAB4:;
    R[5] = R[21] + 592;  /* 0x800CEAB4 */
    { R[31] = 0x800CEAC0u; R[6] = R[21] + 594; psx_next = 0x800CE630u; return; }  /* 0x800CEAB8 jal */
    R[3] = lb_(R[16] + 49);  /* 0x800CEAC0 */
    R[2] = (R[3] < (uint32_t)33u);  /* 0x800CEAC8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] + 1; if (_c) { goto L_800CEAE8; } }  /* 0x800CEACC */
    R[2] = lh_(R[21] + 592);  /* 0x800CEAD4 */
    R[17] = 0x2u << 16;  /* 0x800CEAD8 */
    R[2] = R[2] + 1;  /* 0x800CEADC */
    { sh_(R[21] + 592, R[2]); goto L_800CEAF4; }  /* 0x800CEAE0 j */
L_800CEAE8:;
    sb_(R[16] + 49, R[2]);  /* 0x800CEAE8 */
    R[2] = R[2] & 0xFF;  /* 0x800CEAEC */
    R[17] = R[2] << 12;  /* 0x800CEAF0 */
L_800CEAF4:;
    R[2] = 0x1u << 16;  /* 0x800CEAF4 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEAF8 */
    { R[31] = 0x800CEB04u; R[17] = R[17] + R[2]; psx_next = 0x80035B18u; return; }  /* 0x800CEAFC jal */
    R[4] = R[2] + R[0];  /* 0x800CEB04 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB10u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB08 jalr */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB10 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEB14 */
    R[3] = R[3] + R[2];  /* 0x800CEB18 */
    { R[31] = 0x800CEB24u; sw_(R[16] + -8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CEB1C jal */
    R[4] = R[2] + R[0];  /* 0x800CEB24 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB30u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB28 jalr */
    R[4] = R[0] + 4096;  /* 0x800CEB30 */
    R[3] = lw_(R[16]);  /* 0x800CEB34 */
    R[5] = R[17] + R[0];  /* 0x800CEB38 */
    R[3] = R[3] + R[2];  /* 0x800CEB3C */
    { uint32_t _t = R[19]; R[31] = 0x800CEB48u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEB40 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CEB54; } }  /* 0x800CEB48 */
    R[2] = R[2] + 4095;  /* 0x800CEB50 */
L_800CEB54:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEB54 */
    R[3] = R[0] + 64;  /* 0x800CEB58 */
    R[4] = lb_(R[16] + 49);  /* 0x800CEB5C */
    R[3] = R[3] - R[2];  /* 0x800CEB60 */
    sb_(R[16] + 37, R[3]);  /* 0x800CEB64 */
    R[4] = R[4] & 0x3;  /* 0x800CEB68 */
    { uint32_t _c = (R[4] != R[0]); sb_(R[16] + 36, R[3]); if (_c) { goto L_800CEBB4; } }  /* 0x800CEB6C */
    R[4] = R[23] + 216;  /* 0x800CEB74 */
    { R[31] = 0x800CEB80u; R[5] = R[0] + 16; psx_next = 0x800BDFDCu; return; }  /* 0x800CEB78 jal */
    R[4] = R[2] + R[0];  /* 0x800CEB80 */
    R[5] = R[29] + 32;  /* 0x800CEB84 */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB88 */
    R[6] = R[0] + 32;  /* 0x800CEB8C */
    sw_(R[29] + 32, R[3]);  /* 0x800CEB90 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEB94 */
    R[7] = 0x800Fu << 16;  /* 0x800CEB98 */
    R[2] = R[0] - R[2];  /* 0x800CEB9C */
    sw_(R[29] + 36, R[2]);  /* 0x800CEBA0 */
    R[2] = lw_(R[16]);  /* 0x800CEBA4 */
    R[7] = R[7] - 372;  /* 0x800CEBA8 */
    { R[31] = 0x800CEBB4u; sw_(R[29] + 40, R[2]); psx_next = 0x800CDD84u; return; }  /* 0x800CEBAC jal */
L_800CEBB4:;
    R[4] = R[23] + 216;  /* 0x800CEBB4 */
    R[5] = R[0] + 13;  /* 0x800CEBB8 */
    { R[31] = 0x800CEBC4u; R[6] = R[0] + 24576; psx_next = 0x800CDE50u; return; }  /* 0x800CEBBC jal */
L_800CEBC4:;
    R[22] = R[22] + 1;  /* 0x800CEBC4 */
L_800CEBC8:;
    R[16] = R[16] + 72;  /* 0x800CEBC8 */
    R[20] = R[20] + 1;  /* 0x800CEBCC */
    R[2] = ((int32_t)R[20] < 3);  /* 0x800CEBD0 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_bb(); goto L_800CE904; } }  /* 0x800CEBD4 */
    R[2] = R[22] + R[0];  /* 0x800CEBDC */
    R[31] = lw_(R[29] + 84);  /* 0x800CEBE0 */
    R[30] = lw_(R[29] + 80);  /* 0x800CEBE4 */
    R[23] = lw_(R[29] + 76);  /* 0x800CEBE8 */
    R[22] = lw_(R[29] + 72);  /* 0x800CEBEC */
    R[21] = lw_(R[29] + 68);  /* 0x800CEBF0 */
    R[20] = lw_(R[29] + 64);  /* 0x800CEBF4 */
    R[19] = lw_(R[29] + 60);  /* 0x800CEBF8 */
    R[18] = lw_(R[29] + 56);  /* 0x800CEBFC */
    R[17] = lw_(R[29] + 52);  /* 0x800CEC00 */
    R[16] = lw_(R[29] + 48);  /* 0x800CEC04 */
    { R[29] = R[29] + 88; psx_next = R[31]; return; }  /* 0x800CEC08 jr ra */
}

void g0_800CE9D4(void) {
    R[4] = R[2] + R[0];  /* 0x800CE9D4 */
    { uint32_t _t = R[19]; R[31] = 0x800CE9E0u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CE9D8 jalr */
    R[3] = lw_(R[16] + -8);  /* 0x800CE9E0 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CE9E4 */
    R[3] = R[3] + R[2];  /* 0x800CE9E8 */
    { R[31] = 0x800CE9F4u; sw_(R[16] + -8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CE9EC jal */
    R[4] = R[2] + R[0];  /* 0x800CE9F4 */
    { uint32_t _t = R[19]; R[31] = 0x800CEA00u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CE9F8 jalr */
    R[4] = R[0] + 4096;  /* 0x800CEA00 */
    R[3] = lw_(R[16]);  /* 0x800CEA04 */
    R[5] = R[17] + R[0];  /* 0x800CEA08 */
    R[3] = R[3] + R[2];  /* 0x800CEA0C */
    { uint32_t _t = R[19]; R[31] = 0x800CEA18u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEA10 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_800CEA28; } }  /* 0x800CEA18 */
    R[2] = R[2] + 4095;  /* 0x800CEA20 */
    R[3] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEA24 */
L_800CEA28:;
    R[2] = R[0] + 64;  /* 0x800CEA28 */
    R[2] = R[2] - R[3];  /* 0x800CEA2C */
    sb_(R[16] + 37, R[2]);  /* 0x800CEA30 */
    { sb_(R[16] + 36, R[2]); goto L_800CEBC4; }  /* 0x800CEA34 j */
    R[2] = lb_(R[16] + 49);  /* 0x800CEA3C */
    R[2] = R[2] - 1;  /* 0x800CEA44 */
    sb_(R[16] + 49, R[2]);  /* 0x800CEA48 */
    R[2] = R[2] & 0xFF;  /* 0x800CEA4C */
    { uint32_t _c = (R[2] != R[30]); if (_c) { goto L_800CEBC4; } }  /* 0x800CEA50 */
    R[2] = lb_(R[16] + 48);  /* 0x800CEA58 */
    sb_(R[16] + 49, R[0]);  /* 0x800CEA5C */
    R[2] = R[2] + 1;  /* 0x800CEA60 */
    { sb_(R[16] + 48, R[2]); goto L_800CEBC4; }  /* 0x800CEA64 j */
    R[8] = 0x8012u << 16;  /* 0x800CEA6C */
    R[2] = lw_(R[16] + -8);  /* 0x800CEA70 */
    R[8] = R[8] - 26864;  /* 0x800CEA74 */
    sw_(R[29] + 16, R[2]);  /* 0x800CEA78 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEA7C */
    R[5] = R[8] + 24;  /* 0x800CEA80 */
    R[2] = R[0] - R[2];  /* 0x800CEA84 */
    sw_(R[29] + 20, R[2]);  /* 0x800CEA88 */
    R[2] = lw_(R[16]);  /* 0x800CEA8C */
    R[6] = R[0] + 500;  /* 0x800CEA90 */
    { R[31] = 0x800CEA9Cu; sw_(R[29] + 24, R[2]); psx_next = 0x800B6A98u; return; }  /* 0x800CEA94 jal */
    R[2] = (R[2] < (uint32_t)20480u);  /* 0x800CEA9C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_800CEAB4; } }  /* 0x800CEAA0 */
    sh_(R[18], R[0]);  /* 0x800CEAA8 */
    { sb_(R[16] + -14, R[0]); goto L_800CEBC4; }  /* 0x800CEAAC j */
L_800CEAB4:;
    R[5] = R[21] + 592;  /* 0x800CEAB4 */
    { R[31] = 0x800CEAC0u; R[6] = R[21] + 594; psx_next = 0x800CE630u; return; }  /* 0x800CEAB8 jal */
    R[3] = lb_(R[16] + 49);  /* 0x800CEAC0 */
    R[2] = (R[3] < (uint32_t)33u);  /* 0x800CEAC8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] + 1; if (_c) { goto L_800CEAE8; } }  /* 0x800CEACC */
    R[2] = lh_(R[21] + 592);  /* 0x800CEAD4 */
    R[17] = 0x2u << 16;  /* 0x800CEAD8 */
    R[2] = R[2] + 1;  /* 0x800CEADC */
    { sh_(R[21] + 592, R[2]); goto L_800CEAF4; }  /* 0x800CEAE0 j */
L_800CEAE8:;
    sb_(R[16] + 49, R[2]);  /* 0x800CEAE8 */
    R[2] = R[2] & 0xFF;  /* 0x800CEAEC */
    R[17] = R[2] << 12;  /* 0x800CEAF0 */
L_800CEAF4:;
    R[2] = 0x1u << 16;  /* 0x800CEAF4 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEAF8 */
    { R[31] = 0x800CEB04u; R[17] = R[17] + R[2]; psx_next = 0x80035B18u; return; }  /* 0x800CEAFC jal */
    R[4] = R[2] + R[0];  /* 0x800CEB04 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB10u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB08 jalr */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB10 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEB14 */
    R[3] = R[3] + R[2];  /* 0x800CEB18 */
    { R[31] = 0x800CEB24u; sw_(R[16] + -8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CEB1C jal */
    R[4] = R[2] + R[0];  /* 0x800CEB24 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB30u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB28 jalr */
    R[4] = R[0] + 4096;  /* 0x800CEB30 */
    R[3] = lw_(R[16]);  /* 0x800CEB34 */
    R[5] = R[17] + R[0];  /* 0x800CEB38 */
    R[3] = R[3] + R[2];  /* 0x800CEB3C */
    { uint32_t _t = R[19]; R[31] = 0x800CEB48u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEB40 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CEB54; } }  /* 0x800CEB48 */
    R[2] = R[2] + 4095;  /* 0x800CEB50 */
L_800CEB54:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEB54 */
    R[3] = R[0] + 64;  /* 0x800CEB58 */
    R[4] = lb_(R[16] + 49);  /* 0x800CEB5C */
    R[3] = R[3] - R[2];  /* 0x800CEB60 */
    sb_(R[16] + 37, R[3]);  /* 0x800CEB64 */
    R[4] = R[4] & 0x3;  /* 0x800CEB68 */
    { uint32_t _c = (R[4] != R[0]); sb_(R[16] + 36, R[3]); if (_c) { goto L_800CEBB4; } }  /* 0x800CEB6C */
    R[4] = R[23] + 216;  /* 0x800CEB74 */
    { R[31] = 0x800CEB80u; R[5] = R[0] + 16; psx_next = 0x800BDFDCu; return; }  /* 0x800CEB78 jal */
    R[4] = R[2] + R[0];  /* 0x800CEB80 */
    R[5] = R[29] + 32;  /* 0x800CEB84 */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB88 */
    R[6] = R[0] + 32;  /* 0x800CEB8C */
    sw_(R[29] + 32, R[3]);  /* 0x800CEB90 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEB94 */
    R[7] = 0x800Fu << 16;  /* 0x800CEB98 */
    R[2] = R[0] - R[2];  /* 0x800CEB9C */
    sw_(R[29] + 36, R[2]);  /* 0x800CEBA0 */
    R[2] = lw_(R[16]);  /* 0x800CEBA4 */
    R[7] = R[7] - 372;  /* 0x800CEBA8 */
    { R[31] = 0x800CEBB4u; sw_(R[29] + 40, R[2]); psx_next = 0x800CDD84u; return; }  /* 0x800CEBAC jal */
L_800CEBB4:;
    R[4] = R[23] + 216;  /* 0x800CEBB4 */
    R[5] = R[0] + 13;  /* 0x800CEBB8 */
    { R[31] = 0x800CEBC4u; R[6] = R[0] + 24576; psx_next = 0x800CDE50u; return; }  /* 0x800CEBBC jal */
L_800CEBC4:;
    R[22] = R[22] + 1;  /* 0x800CEBC4 */
    R[16] = R[16] + 72;  /* 0x800CEBC8 */
    R[20] = R[20] + 1;  /* 0x800CEBCC */
    R[2] = ((int32_t)R[20] < 3);  /* 0x800CEBD0 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_next = 0x800CE904u; return; } }  /* 0x800CEBD4 b extern */
    R[2] = R[22] + R[0];  /* 0x800CEBDC */
    R[31] = lw_(R[29] + 84);  /* 0x800CEBE0 */
    R[30] = lw_(R[29] + 80);  /* 0x800CEBE4 */
    R[23] = lw_(R[29] + 76);  /* 0x800CEBE8 */
    R[22] = lw_(R[29] + 72);  /* 0x800CEBEC */
    R[21] = lw_(R[29] + 68);  /* 0x800CEBF0 */
    R[20] = lw_(R[29] + 64);  /* 0x800CEBF4 */
    R[19] = lw_(R[29] + 60);  /* 0x800CEBF8 */
    R[18] = lw_(R[29] + 56);  /* 0x800CEBFC */
    R[17] = lw_(R[29] + 52);  /* 0x800CEC00 */
    R[16] = lw_(R[29] + 48);  /* 0x800CEC04 */
    { R[29] = R[29] + 88; psx_next = R[31]; return; }  /* 0x800CEC08 jr ra */
}

void g0_800CE9E0(void) {
    R[3] = lw_(R[16] + -8);  /* 0x800CE9E0 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CE9E4 */
    R[3] = R[3] + R[2];  /* 0x800CE9E8 */
    { R[31] = 0x800CE9F4u; sw_(R[16] + -8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CE9EC jal */
    R[4] = R[2] + R[0];  /* 0x800CE9F4 */
    { uint32_t _t = R[19]; R[31] = 0x800CEA00u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CE9F8 jalr */
    R[4] = R[0] + 4096;  /* 0x800CEA00 */
    R[3] = lw_(R[16]);  /* 0x800CEA04 */
    R[5] = R[17] + R[0];  /* 0x800CEA08 */
    R[3] = R[3] + R[2];  /* 0x800CEA0C */
    { uint32_t _t = R[19]; R[31] = 0x800CEA18u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEA10 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_800CEA28; } }  /* 0x800CEA18 */
    R[2] = R[2] + 4095;  /* 0x800CEA20 */
    R[3] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEA24 */
L_800CEA28:;
    R[2] = R[0] + 64;  /* 0x800CEA28 */
    R[2] = R[2] - R[3];  /* 0x800CEA2C */
    sb_(R[16] + 37, R[2]);  /* 0x800CEA30 */
    { sb_(R[16] + 36, R[2]); goto L_800CEBC4; }  /* 0x800CEA34 j */
    R[2] = lb_(R[16] + 49);  /* 0x800CEA3C */
    R[2] = R[2] - 1;  /* 0x800CEA44 */
    sb_(R[16] + 49, R[2]);  /* 0x800CEA48 */
    R[2] = R[2] & 0xFF;  /* 0x800CEA4C */
    { uint32_t _c = (R[2] != R[30]); if (_c) { goto L_800CEBC4; } }  /* 0x800CEA50 */
    R[2] = lb_(R[16] + 48);  /* 0x800CEA58 */
    sb_(R[16] + 49, R[0]);  /* 0x800CEA5C */
    R[2] = R[2] + 1;  /* 0x800CEA60 */
    { sb_(R[16] + 48, R[2]); goto L_800CEBC4; }  /* 0x800CEA64 j */
    R[8] = 0x8012u << 16;  /* 0x800CEA6C */
    R[2] = lw_(R[16] + -8);  /* 0x800CEA70 */
    R[8] = R[8] - 26864;  /* 0x800CEA74 */
    sw_(R[29] + 16, R[2]);  /* 0x800CEA78 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEA7C */
    R[5] = R[8] + 24;  /* 0x800CEA80 */
    R[2] = R[0] - R[2];  /* 0x800CEA84 */
    sw_(R[29] + 20, R[2]);  /* 0x800CEA88 */
    R[2] = lw_(R[16]);  /* 0x800CEA8C */
    R[6] = R[0] + 500;  /* 0x800CEA90 */
    { R[31] = 0x800CEA9Cu; sw_(R[29] + 24, R[2]); psx_next = 0x800B6A98u; return; }  /* 0x800CEA94 jal */
    R[2] = (R[2] < (uint32_t)20480u);  /* 0x800CEA9C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_800CEAB4; } }  /* 0x800CEAA0 */
    sh_(R[18], R[0]);  /* 0x800CEAA8 */
    { sb_(R[16] + -14, R[0]); goto L_800CEBC4; }  /* 0x800CEAAC j */
L_800CEAB4:;
    R[5] = R[21] + 592;  /* 0x800CEAB4 */
    { R[31] = 0x800CEAC0u; R[6] = R[21] + 594; psx_next = 0x800CE630u; return; }  /* 0x800CEAB8 jal */
    R[3] = lb_(R[16] + 49);  /* 0x800CEAC0 */
    R[2] = (R[3] < (uint32_t)33u);  /* 0x800CEAC8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] + 1; if (_c) { goto L_800CEAE8; } }  /* 0x800CEACC */
    R[2] = lh_(R[21] + 592);  /* 0x800CEAD4 */
    R[17] = 0x2u << 16;  /* 0x800CEAD8 */
    R[2] = R[2] + 1;  /* 0x800CEADC */
    { sh_(R[21] + 592, R[2]); goto L_800CEAF4; }  /* 0x800CEAE0 j */
L_800CEAE8:;
    sb_(R[16] + 49, R[2]);  /* 0x800CEAE8 */
    R[2] = R[2] & 0xFF;  /* 0x800CEAEC */
    R[17] = R[2] << 12;  /* 0x800CEAF0 */
L_800CEAF4:;
    R[2] = 0x1u << 16;  /* 0x800CEAF4 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEAF8 */
    { R[31] = 0x800CEB04u; R[17] = R[17] + R[2]; psx_next = 0x80035B18u; return; }  /* 0x800CEAFC jal */
    R[4] = R[2] + R[0];  /* 0x800CEB04 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB10u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB08 jalr */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB10 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEB14 */
    R[3] = R[3] + R[2];  /* 0x800CEB18 */
    { R[31] = 0x800CEB24u; sw_(R[16] + -8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CEB1C jal */
    R[4] = R[2] + R[0];  /* 0x800CEB24 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB30u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB28 jalr */
    R[4] = R[0] + 4096;  /* 0x800CEB30 */
    R[3] = lw_(R[16]);  /* 0x800CEB34 */
    R[5] = R[17] + R[0];  /* 0x800CEB38 */
    R[3] = R[3] + R[2];  /* 0x800CEB3C */
    { uint32_t _t = R[19]; R[31] = 0x800CEB48u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEB40 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CEB54; } }  /* 0x800CEB48 */
    R[2] = R[2] + 4095;  /* 0x800CEB50 */
L_800CEB54:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEB54 */
    R[3] = R[0] + 64;  /* 0x800CEB58 */
    R[4] = lb_(R[16] + 49);  /* 0x800CEB5C */
    R[3] = R[3] - R[2];  /* 0x800CEB60 */
    sb_(R[16] + 37, R[3]);  /* 0x800CEB64 */
    R[4] = R[4] & 0x3;  /* 0x800CEB68 */
    { uint32_t _c = (R[4] != R[0]); sb_(R[16] + 36, R[3]); if (_c) { goto L_800CEBB4; } }  /* 0x800CEB6C */
    R[4] = R[23] + 216;  /* 0x800CEB74 */
    { R[31] = 0x800CEB80u; R[5] = R[0] + 16; psx_next = 0x800BDFDCu; return; }  /* 0x800CEB78 jal */
    R[4] = R[2] + R[0];  /* 0x800CEB80 */
    R[5] = R[29] + 32;  /* 0x800CEB84 */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB88 */
    R[6] = R[0] + 32;  /* 0x800CEB8C */
    sw_(R[29] + 32, R[3]);  /* 0x800CEB90 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEB94 */
    R[7] = 0x800Fu << 16;  /* 0x800CEB98 */
    R[2] = R[0] - R[2];  /* 0x800CEB9C */
    sw_(R[29] + 36, R[2]);  /* 0x800CEBA0 */
    R[2] = lw_(R[16]);  /* 0x800CEBA4 */
    R[7] = R[7] - 372;  /* 0x800CEBA8 */
    { R[31] = 0x800CEBB4u; sw_(R[29] + 40, R[2]); psx_next = 0x800CDD84u; return; }  /* 0x800CEBAC jal */
L_800CEBB4:;
    R[4] = R[23] + 216;  /* 0x800CEBB4 */
    R[5] = R[0] + 13;  /* 0x800CEBB8 */
    { R[31] = 0x800CEBC4u; R[6] = R[0] + 24576; psx_next = 0x800CDE50u; return; }  /* 0x800CEBBC jal */
L_800CEBC4:;
    R[22] = R[22] + 1;  /* 0x800CEBC4 */
    R[16] = R[16] + 72;  /* 0x800CEBC8 */
    R[20] = R[20] + 1;  /* 0x800CEBCC */
    R[2] = ((int32_t)R[20] < 3);  /* 0x800CEBD0 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_next = 0x800CE904u; return; } }  /* 0x800CEBD4 b extern */
    R[2] = R[22] + R[0];  /* 0x800CEBDC */
    R[31] = lw_(R[29] + 84);  /* 0x800CEBE0 */
    R[30] = lw_(R[29] + 80);  /* 0x800CEBE4 */
    R[23] = lw_(R[29] + 76);  /* 0x800CEBE8 */
    R[22] = lw_(R[29] + 72);  /* 0x800CEBEC */
    R[21] = lw_(R[29] + 68);  /* 0x800CEBF0 */
    R[20] = lw_(R[29] + 64);  /* 0x800CEBF4 */
    R[19] = lw_(R[29] + 60);  /* 0x800CEBF8 */
    R[18] = lw_(R[29] + 56);  /* 0x800CEBFC */
    R[17] = lw_(R[29] + 52);  /* 0x800CEC00 */
    R[16] = lw_(R[29] + 48);  /* 0x800CEC04 */
    { R[29] = R[29] + 88; psx_next = R[31]; return; }  /* 0x800CEC08 jr ra */
}

void g0_800CE9F4(void) {
    R[4] = R[2] + R[0];  /* 0x800CE9F4 */
    { uint32_t _t = R[19]; R[31] = 0x800CEA00u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CE9F8 jalr */
    R[4] = R[0] + 4096;  /* 0x800CEA00 */
    R[3] = lw_(R[16]);  /* 0x800CEA04 */
    R[5] = R[17] + R[0];  /* 0x800CEA08 */
    R[3] = R[3] + R[2];  /* 0x800CEA0C */
    { uint32_t _t = R[19]; R[31] = 0x800CEA18u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEA10 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_800CEA28; } }  /* 0x800CEA18 */
    R[2] = R[2] + 4095;  /* 0x800CEA20 */
    R[3] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEA24 */
L_800CEA28:;
    R[2] = R[0] + 64;  /* 0x800CEA28 */
    R[2] = R[2] - R[3];  /* 0x800CEA2C */
    sb_(R[16] + 37, R[2]);  /* 0x800CEA30 */
    { sb_(R[16] + 36, R[2]); goto L_800CEBC4; }  /* 0x800CEA34 j */
    R[2] = lb_(R[16] + 49);  /* 0x800CEA3C */
    R[2] = R[2] - 1;  /* 0x800CEA44 */
    sb_(R[16] + 49, R[2]);  /* 0x800CEA48 */
    R[2] = R[2] & 0xFF;  /* 0x800CEA4C */
    { uint32_t _c = (R[2] != R[30]); if (_c) { goto L_800CEBC4; } }  /* 0x800CEA50 */
    R[2] = lb_(R[16] + 48);  /* 0x800CEA58 */
    sb_(R[16] + 49, R[0]);  /* 0x800CEA5C */
    R[2] = R[2] + 1;  /* 0x800CEA60 */
    { sb_(R[16] + 48, R[2]); goto L_800CEBC4; }  /* 0x800CEA64 j */
    R[8] = 0x8012u << 16;  /* 0x800CEA6C */
    R[2] = lw_(R[16] + -8);  /* 0x800CEA70 */
    R[8] = R[8] - 26864;  /* 0x800CEA74 */
    sw_(R[29] + 16, R[2]);  /* 0x800CEA78 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEA7C */
    R[5] = R[8] + 24;  /* 0x800CEA80 */
    R[2] = R[0] - R[2];  /* 0x800CEA84 */
    sw_(R[29] + 20, R[2]);  /* 0x800CEA88 */
    R[2] = lw_(R[16]);  /* 0x800CEA8C */
    R[6] = R[0] + 500;  /* 0x800CEA90 */
    { R[31] = 0x800CEA9Cu; sw_(R[29] + 24, R[2]); psx_next = 0x800B6A98u; return; }  /* 0x800CEA94 jal */
    R[2] = (R[2] < (uint32_t)20480u);  /* 0x800CEA9C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_800CEAB4; } }  /* 0x800CEAA0 */
    sh_(R[18], R[0]);  /* 0x800CEAA8 */
    { sb_(R[16] + -14, R[0]); goto L_800CEBC4; }  /* 0x800CEAAC j */
L_800CEAB4:;
    R[5] = R[21] + 592;  /* 0x800CEAB4 */
    { R[31] = 0x800CEAC0u; R[6] = R[21] + 594; psx_next = 0x800CE630u; return; }  /* 0x800CEAB8 jal */
    R[3] = lb_(R[16] + 49);  /* 0x800CEAC0 */
    R[2] = (R[3] < (uint32_t)33u);  /* 0x800CEAC8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] + 1; if (_c) { goto L_800CEAE8; } }  /* 0x800CEACC */
    R[2] = lh_(R[21] + 592);  /* 0x800CEAD4 */
    R[17] = 0x2u << 16;  /* 0x800CEAD8 */
    R[2] = R[2] + 1;  /* 0x800CEADC */
    { sh_(R[21] + 592, R[2]); goto L_800CEAF4; }  /* 0x800CEAE0 j */
L_800CEAE8:;
    sb_(R[16] + 49, R[2]);  /* 0x800CEAE8 */
    R[2] = R[2] & 0xFF;  /* 0x800CEAEC */
    R[17] = R[2] << 12;  /* 0x800CEAF0 */
L_800CEAF4:;
    R[2] = 0x1u << 16;  /* 0x800CEAF4 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEAF8 */
    { R[31] = 0x800CEB04u; R[17] = R[17] + R[2]; psx_next = 0x80035B18u; return; }  /* 0x800CEAFC jal */
    R[4] = R[2] + R[0];  /* 0x800CEB04 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB10u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB08 jalr */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB10 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEB14 */
    R[3] = R[3] + R[2];  /* 0x800CEB18 */
    { R[31] = 0x800CEB24u; sw_(R[16] + -8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CEB1C jal */
    R[4] = R[2] + R[0];  /* 0x800CEB24 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB30u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB28 jalr */
    R[4] = R[0] + 4096;  /* 0x800CEB30 */
    R[3] = lw_(R[16]);  /* 0x800CEB34 */
    R[5] = R[17] + R[0];  /* 0x800CEB38 */
    R[3] = R[3] + R[2];  /* 0x800CEB3C */
    { uint32_t _t = R[19]; R[31] = 0x800CEB48u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEB40 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CEB54; } }  /* 0x800CEB48 */
    R[2] = R[2] + 4095;  /* 0x800CEB50 */
L_800CEB54:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEB54 */
    R[3] = R[0] + 64;  /* 0x800CEB58 */
    R[4] = lb_(R[16] + 49);  /* 0x800CEB5C */
    R[3] = R[3] - R[2];  /* 0x800CEB60 */
    sb_(R[16] + 37, R[3]);  /* 0x800CEB64 */
    R[4] = R[4] & 0x3;  /* 0x800CEB68 */
    { uint32_t _c = (R[4] != R[0]); sb_(R[16] + 36, R[3]); if (_c) { goto L_800CEBB4; } }  /* 0x800CEB6C */
    R[4] = R[23] + 216;  /* 0x800CEB74 */
    { R[31] = 0x800CEB80u; R[5] = R[0] + 16; psx_next = 0x800BDFDCu; return; }  /* 0x800CEB78 jal */
    R[4] = R[2] + R[0];  /* 0x800CEB80 */
    R[5] = R[29] + 32;  /* 0x800CEB84 */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB88 */
    R[6] = R[0] + 32;  /* 0x800CEB8C */
    sw_(R[29] + 32, R[3]);  /* 0x800CEB90 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEB94 */
    R[7] = 0x800Fu << 16;  /* 0x800CEB98 */
    R[2] = R[0] - R[2];  /* 0x800CEB9C */
    sw_(R[29] + 36, R[2]);  /* 0x800CEBA0 */
    R[2] = lw_(R[16]);  /* 0x800CEBA4 */
    R[7] = R[7] - 372;  /* 0x800CEBA8 */
    { R[31] = 0x800CEBB4u; sw_(R[29] + 40, R[2]); psx_next = 0x800CDD84u; return; }  /* 0x800CEBAC jal */
L_800CEBB4:;
    R[4] = R[23] + 216;  /* 0x800CEBB4 */
    R[5] = R[0] + 13;  /* 0x800CEBB8 */
    { R[31] = 0x800CEBC4u; R[6] = R[0] + 24576; psx_next = 0x800CDE50u; return; }  /* 0x800CEBBC jal */
L_800CEBC4:;
    R[22] = R[22] + 1;  /* 0x800CEBC4 */
    R[16] = R[16] + 72;  /* 0x800CEBC8 */
    R[20] = R[20] + 1;  /* 0x800CEBCC */
    R[2] = ((int32_t)R[20] < 3);  /* 0x800CEBD0 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_next = 0x800CE904u; return; } }  /* 0x800CEBD4 b extern */
    R[2] = R[22] + R[0];  /* 0x800CEBDC */
    R[31] = lw_(R[29] + 84);  /* 0x800CEBE0 */
    R[30] = lw_(R[29] + 80);  /* 0x800CEBE4 */
    R[23] = lw_(R[29] + 76);  /* 0x800CEBE8 */
    R[22] = lw_(R[29] + 72);  /* 0x800CEBEC */
    R[21] = lw_(R[29] + 68);  /* 0x800CEBF0 */
    R[20] = lw_(R[29] + 64);  /* 0x800CEBF4 */
    R[19] = lw_(R[29] + 60);  /* 0x800CEBF8 */
    R[18] = lw_(R[29] + 56);  /* 0x800CEBFC */
    R[17] = lw_(R[29] + 52);  /* 0x800CEC00 */
    R[16] = lw_(R[29] + 48);  /* 0x800CEC04 */
    { R[29] = R[29] + 88; psx_next = R[31]; return; }  /* 0x800CEC08 jr ra */
}

void g0_800CEA00(void) {
    R[4] = R[0] + 4096;  /* 0x800CEA00 */
    R[3] = lw_(R[16]);  /* 0x800CEA04 */
    R[5] = R[17] + R[0];  /* 0x800CEA08 */
    R[3] = R[3] + R[2];  /* 0x800CEA0C */
    { uint32_t _t = R[19]; R[31] = 0x800CEA18u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEA10 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_800CEA28; } }  /* 0x800CEA18 */
    R[2] = R[2] + 4095;  /* 0x800CEA20 */
    R[3] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEA24 */
L_800CEA28:;
    R[2] = R[0] + 64;  /* 0x800CEA28 */
    R[2] = R[2] - R[3];  /* 0x800CEA2C */
    sb_(R[16] + 37, R[2]);  /* 0x800CEA30 */
    { sb_(R[16] + 36, R[2]); goto L_800CEBC4; }  /* 0x800CEA34 j */
    R[2] = lb_(R[16] + 49);  /* 0x800CEA3C */
    R[2] = R[2] - 1;  /* 0x800CEA44 */
    sb_(R[16] + 49, R[2]);  /* 0x800CEA48 */
    R[2] = R[2] & 0xFF;  /* 0x800CEA4C */
    { uint32_t _c = (R[2] != R[30]); if (_c) { goto L_800CEBC4; } }  /* 0x800CEA50 */
    R[2] = lb_(R[16] + 48);  /* 0x800CEA58 */
    sb_(R[16] + 49, R[0]);  /* 0x800CEA5C */
    R[2] = R[2] + 1;  /* 0x800CEA60 */
    { sb_(R[16] + 48, R[2]); goto L_800CEBC4; }  /* 0x800CEA64 j */
    R[8] = 0x8012u << 16;  /* 0x800CEA6C */
    R[2] = lw_(R[16] + -8);  /* 0x800CEA70 */
    R[8] = R[8] - 26864;  /* 0x800CEA74 */
    sw_(R[29] + 16, R[2]);  /* 0x800CEA78 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEA7C */
    R[5] = R[8] + 24;  /* 0x800CEA80 */
    R[2] = R[0] - R[2];  /* 0x800CEA84 */
    sw_(R[29] + 20, R[2]);  /* 0x800CEA88 */
    R[2] = lw_(R[16]);  /* 0x800CEA8C */
    R[6] = R[0] + 500;  /* 0x800CEA90 */
    { R[31] = 0x800CEA9Cu; sw_(R[29] + 24, R[2]); psx_next = 0x800B6A98u; return; }  /* 0x800CEA94 jal */
    R[2] = (R[2] < (uint32_t)20480u);  /* 0x800CEA9C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_800CEAB4; } }  /* 0x800CEAA0 */
    sh_(R[18], R[0]);  /* 0x800CEAA8 */
    { sb_(R[16] + -14, R[0]); goto L_800CEBC4; }  /* 0x800CEAAC j */
L_800CEAB4:;
    R[5] = R[21] + 592;  /* 0x800CEAB4 */
    { R[31] = 0x800CEAC0u; R[6] = R[21] + 594; psx_next = 0x800CE630u; return; }  /* 0x800CEAB8 jal */
    R[3] = lb_(R[16] + 49);  /* 0x800CEAC0 */
    R[2] = (R[3] < (uint32_t)33u);  /* 0x800CEAC8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] + 1; if (_c) { goto L_800CEAE8; } }  /* 0x800CEACC */
    R[2] = lh_(R[21] + 592);  /* 0x800CEAD4 */
    R[17] = 0x2u << 16;  /* 0x800CEAD8 */
    R[2] = R[2] + 1;  /* 0x800CEADC */
    { sh_(R[21] + 592, R[2]); goto L_800CEAF4; }  /* 0x800CEAE0 j */
L_800CEAE8:;
    sb_(R[16] + 49, R[2]);  /* 0x800CEAE8 */
    R[2] = R[2] & 0xFF;  /* 0x800CEAEC */
    R[17] = R[2] << 12;  /* 0x800CEAF0 */
L_800CEAF4:;
    R[2] = 0x1u << 16;  /* 0x800CEAF4 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEAF8 */
    { R[31] = 0x800CEB04u; R[17] = R[17] + R[2]; psx_next = 0x80035B18u; return; }  /* 0x800CEAFC jal */
    R[4] = R[2] + R[0];  /* 0x800CEB04 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB10u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB08 jalr */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB10 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEB14 */
    R[3] = R[3] + R[2];  /* 0x800CEB18 */
    { R[31] = 0x800CEB24u; sw_(R[16] + -8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CEB1C jal */
    R[4] = R[2] + R[0];  /* 0x800CEB24 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB30u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB28 jalr */
    R[4] = R[0] + 4096;  /* 0x800CEB30 */
    R[3] = lw_(R[16]);  /* 0x800CEB34 */
    R[5] = R[17] + R[0];  /* 0x800CEB38 */
    R[3] = R[3] + R[2];  /* 0x800CEB3C */
    { uint32_t _t = R[19]; R[31] = 0x800CEB48u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEB40 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CEB54; } }  /* 0x800CEB48 */
    R[2] = R[2] + 4095;  /* 0x800CEB50 */
L_800CEB54:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEB54 */
    R[3] = R[0] + 64;  /* 0x800CEB58 */
    R[4] = lb_(R[16] + 49);  /* 0x800CEB5C */
    R[3] = R[3] - R[2];  /* 0x800CEB60 */
    sb_(R[16] + 37, R[3]);  /* 0x800CEB64 */
    R[4] = R[4] & 0x3;  /* 0x800CEB68 */
    { uint32_t _c = (R[4] != R[0]); sb_(R[16] + 36, R[3]); if (_c) { goto L_800CEBB4; } }  /* 0x800CEB6C */
    R[4] = R[23] + 216;  /* 0x800CEB74 */
    { R[31] = 0x800CEB80u; R[5] = R[0] + 16; psx_next = 0x800BDFDCu; return; }  /* 0x800CEB78 jal */
    R[4] = R[2] + R[0];  /* 0x800CEB80 */
    R[5] = R[29] + 32;  /* 0x800CEB84 */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB88 */
    R[6] = R[0] + 32;  /* 0x800CEB8C */
    sw_(R[29] + 32, R[3]);  /* 0x800CEB90 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEB94 */
    R[7] = 0x800Fu << 16;  /* 0x800CEB98 */
    R[2] = R[0] - R[2];  /* 0x800CEB9C */
    sw_(R[29] + 36, R[2]);  /* 0x800CEBA0 */
    R[2] = lw_(R[16]);  /* 0x800CEBA4 */
    R[7] = R[7] - 372;  /* 0x800CEBA8 */
    { R[31] = 0x800CEBB4u; sw_(R[29] + 40, R[2]); psx_next = 0x800CDD84u; return; }  /* 0x800CEBAC jal */
L_800CEBB4:;
    R[4] = R[23] + 216;  /* 0x800CEBB4 */
    R[5] = R[0] + 13;  /* 0x800CEBB8 */
    { R[31] = 0x800CEBC4u; R[6] = R[0] + 24576; psx_next = 0x800CDE50u; return; }  /* 0x800CEBBC jal */
L_800CEBC4:;
    R[22] = R[22] + 1;  /* 0x800CEBC4 */
    R[16] = R[16] + 72;  /* 0x800CEBC8 */
    R[20] = R[20] + 1;  /* 0x800CEBCC */
    R[2] = ((int32_t)R[20] < 3);  /* 0x800CEBD0 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_next = 0x800CE904u; return; } }  /* 0x800CEBD4 b extern */
    R[2] = R[22] + R[0];  /* 0x800CEBDC */
    R[31] = lw_(R[29] + 84);  /* 0x800CEBE0 */
    R[30] = lw_(R[29] + 80);  /* 0x800CEBE4 */
    R[23] = lw_(R[29] + 76);  /* 0x800CEBE8 */
    R[22] = lw_(R[29] + 72);  /* 0x800CEBEC */
    R[21] = lw_(R[29] + 68);  /* 0x800CEBF0 */
    R[20] = lw_(R[29] + 64);  /* 0x800CEBF4 */
    R[19] = lw_(R[29] + 60);  /* 0x800CEBF8 */
    R[18] = lw_(R[29] + 56);  /* 0x800CEBFC */
    R[17] = lw_(R[29] + 52);  /* 0x800CEC00 */
    R[16] = lw_(R[29] + 48);  /* 0x800CEC04 */
    { R[29] = R[29] + 88; psx_next = R[31]; return; }  /* 0x800CEC08 jr ra */
}

void g0_800CEA18(void) {
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_800CEA28; } }  /* 0x800CEA18 */
    R[2] = R[2] + 4095;  /* 0x800CEA20 */
    R[3] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEA24 */
L_800CEA28:;
    R[2] = R[0] + 64;  /* 0x800CEA28 */
    R[2] = R[2] - R[3];  /* 0x800CEA2C */
    sb_(R[16] + 37, R[2]);  /* 0x800CEA30 */
    { sb_(R[16] + 36, R[2]); goto L_800CEBC4; }  /* 0x800CEA34 j */
    R[2] = lb_(R[16] + 49);  /* 0x800CEA3C */
    R[2] = R[2] - 1;  /* 0x800CEA44 */
    sb_(R[16] + 49, R[2]);  /* 0x800CEA48 */
    R[2] = R[2] & 0xFF;  /* 0x800CEA4C */
    { uint32_t _c = (R[2] != R[30]); if (_c) { goto L_800CEBC4; } }  /* 0x800CEA50 */
    R[2] = lb_(R[16] + 48);  /* 0x800CEA58 */
    sb_(R[16] + 49, R[0]);  /* 0x800CEA5C */
    R[2] = R[2] + 1;  /* 0x800CEA60 */
    { sb_(R[16] + 48, R[2]); goto L_800CEBC4; }  /* 0x800CEA64 j */
    R[8] = 0x8012u << 16;  /* 0x800CEA6C */
    R[2] = lw_(R[16] + -8);  /* 0x800CEA70 */
    R[8] = R[8] - 26864;  /* 0x800CEA74 */
    sw_(R[29] + 16, R[2]);  /* 0x800CEA78 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEA7C */
    R[5] = R[8] + 24;  /* 0x800CEA80 */
    R[2] = R[0] - R[2];  /* 0x800CEA84 */
    sw_(R[29] + 20, R[2]);  /* 0x800CEA88 */
    R[2] = lw_(R[16]);  /* 0x800CEA8C */
    R[6] = R[0] + 500;  /* 0x800CEA90 */
    { R[31] = 0x800CEA9Cu; sw_(R[29] + 24, R[2]); psx_next = 0x800B6A98u; return; }  /* 0x800CEA94 jal */
    R[2] = (R[2] < (uint32_t)20480u);  /* 0x800CEA9C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_800CEAB4; } }  /* 0x800CEAA0 */
    sh_(R[18], R[0]);  /* 0x800CEAA8 */
    { sb_(R[16] + -14, R[0]); goto L_800CEBC4; }  /* 0x800CEAAC j */
L_800CEAB4:;
    R[5] = R[21] + 592;  /* 0x800CEAB4 */
    { R[31] = 0x800CEAC0u; R[6] = R[21] + 594; psx_next = 0x800CE630u; return; }  /* 0x800CEAB8 jal */
    R[3] = lb_(R[16] + 49);  /* 0x800CEAC0 */
    R[2] = (R[3] < (uint32_t)33u);  /* 0x800CEAC8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] + 1; if (_c) { goto L_800CEAE8; } }  /* 0x800CEACC */
    R[2] = lh_(R[21] + 592);  /* 0x800CEAD4 */
    R[17] = 0x2u << 16;  /* 0x800CEAD8 */
    R[2] = R[2] + 1;  /* 0x800CEADC */
    { sh_(R[21] + 592, R[2]); goto L_800CEAF4; }  /* 0x800CEAE0 j */
L_800CEAE8:;
    sb_(R[16] + 49, R[2]);  /* 0x800CEAE8 */
    R[2] = R[2] & 0xFF;  /* 0x800CEAEC */
    R[17] = R[2] << 12;  /* 0x800CEAF0 */
L_800CEAF4:;
    R[2] = 0x1u << 16;  /* 0x800CEAF4 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEAF8 */
    { R[31] = 0x800CEB04u; R[17] = R[17] + R[2]; psx_next = 0x80035B18u; return; }  /* 0x800CEAFC jal */
    R[4] = R[2] + R[0];  /* 0x800CEB04 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB10u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB08 jalr */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB10 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEB14 */
    R[3] = R[3] + R[2];  /* 0x800CEB18 */
    { R[31] = 0x800CEB24u; sw_(R[16] + -8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CEB1C jal */
    R[4] = R[2] + R[0];  /* 0x800CEB24 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB30u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB28 jalr */
    R[4] = R[0] + 4096;  /* 0x800CEB30 */
    R[3] = lw_(R[16]);  /* 0x800CEB34 */
    R[5] = R[17] + R[0];  /* 0x800CEB38 */
    R[3] = R[3] + R[2];  /* 0x800CEB3C */
    { uint32_t _t = R[19]; R[31] = 0x800CEB48u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEB40 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CEB54; } }  /* 0x800CEB48 */
    R[2] = R[2] + 4095;  /* 0x800CEB50 */
L_800CEB54:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEB54 */
    R[3] = R[0] + 64;  /* 0x800CEB58 */
    R[4] = lb_(R[16] + 49);  /* 0x800CEB5C */
    R[3] = R[3] - R[2];  /* 0x800CEB60 */
    sb_(R[16] + 37, R[3]);  /* 0x800CEB64 */
    R[4] = R[4] & 0x3;  /* 0x800CEB68 */
    { uint32_t _c = (R[4] != R[0]); sb_(R[16] + 36, R[3]); if (_c) { goto L_800CEBB4; } }  /* 0x800CEB6C */
    R[4] = R[23] + 216;  /* 0x800CEB74 */
    { R[31] = 0x800CEB80u; R[5] = R[0] + 16; psx_next = 0x800BDFDCu; return; }  /* 0x800CEB78 jal */
    R[4] = R[2] + R[0];  /* 0x800CEB80 */
    R[5] = R[29] + 32;  /* 0x800CEB84 */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB88 */
    R[6] = R[0] + 32;  /* 0x800CEB8C */
    sw_(R[29] + 32, R[3]);  /* 0x800CEB90 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEB94 */
    R[7] = 0x800Fu << 16;  /* 0x800CEB98 */
    R[2] = R[0] - R[2];  /* 0x800CEB9C */
    sw_(R[29] + 36, R[2]);  /* 0x800CEBA0 */
    R[2] = lw_(R[16]);  /* 0x800CEBA4 */
    R[7] = R[7] - 372;  /* 0x800CEBA8 */
    { R[31] = 0x800CEBB4u; sw_(R[29] + 40, R[2]); psx_next = 0x800CDD84u; return; }  /* 0x800CEBAC jal */
L_800CEBB4:;
    R[4] = R[23] + 216;  /* 0x800CEBB4 */
    R[5] = R[0] + 13;  /* 0x800CEBB8 */
    { R[31] = 0x800CEBC4u; R[6] = R[0] + 24576; psx_next = 0x800CDE50u; return; }  /* 0x800CEBBC jal */
L_800CEBC4:;
    R[22] = R[22] + 1;  /* 0x800CEBC4 */
    R[16] = R[16] + 72;  /* 0x800CEBC8 */
    R[20] = R[20] + 1;  /* 0x800CEBCC */
    R[2] = ((int32_t)R[20] < 3);  /* 0x800CEBD0 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_next = 0x800CE904u; return; } }  /* 0x800CEBD4 b extern */
    R[2] = R[22] + R[0];  /* 0x800CEBDC */
    R[31] = lw_(R[29] + 84);  /* 0x800CEBE0 */
    R[30] = lw_(R[29] + 80);  /* 0x800CEBE4 */
    R[23] = lw_(R[29] + 76);  /* 0x800CEBE8 */
    R[22] = lw_(R[29] + 72);  /* 0x800CEBEC */
    R[21] = lw_(R[29] + 68);  /* 0x800CEBF0 */
    R[20] = lw_(R[29] + 64);  /* 0x800CEBF4 */
    R[19] = lw_(R[29] + 60);  /* 0x800CEBF8 */
    R[18] = lw_(R[29] + 56);  /* 0x800CEBFC */
    R[17] = lw_(R[29] + 52);  /* 0x800CEC00 */
    R[16] = lw_(R[29] + 48);  /* 0x800CEC04 */
    { R[29] = R[29] + 88; psx_next = R[31]; return; }  /* 0x800CEC08 jr ra */
}

void g0_800CEA9C(void) {
    R[2] = (R[2] < (uint32_t)20480u);  /* 0x800CEA9C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_800CEAB4; } }  /* 0x800CEAA0 */
    sh_(R[18], R[0]);  /* 0x800CEAA8 */
    { sb_(R[16] + -14, R[0]); goto L_800CEBC4; }  /* 0x800CEAAC j */
L_800CEAB4:;
    R[5] = R[21] + 592;  /* 0x800CEAB4 */
    { R[31] = 0x800CEAC0u; R[6] = R[21] + 594; psx_next = 0x800CE630u; return; }  /* 0x800CEAB8 jal */
    R[3] = lb_(R[16] + 49);  /* 0x800CEAC0 */
    R[2] = (R[3] < (uint32_t)33u);  /* 0x800CEAC8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] + 1; if (_c) { goto L_800CEAE8; } }  /* 0x800CEACC */
    R[2] = lh_(R[21] + 592);  /* 0x800CEAD4 */
    R[17] = 0x2u << 16;  /* 0x800CEAD8 */
    R[2] = R[2] + 1;  /* 0x800CEADC */
    { sh_(R[21] + 592, R[2]); goto L_800CEAF4; }  /* 0x800CEAE0 j */
L_800CEAE8:;
    sb_(R[16] + 49, R[2]);  /* 0x800CEAE8 */
    R[2] = R[2] & 0xFF;  /* 0x800CEAEC */
    R[17] = R[2] << 12;  /* 0x800CEAF0 */
L_800CEAF4:;
    R[2] = 0x1u << 16;  /* 0x800CEAF4 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEAF8 */
    { R[31] = 0x800CEB04u; R[17] = R[17] + R[2]; psx_next = 0x80035B18u; return; }  /* 0x800CEAFC jal */
    R[4] = R[2] + R[0];  /* 0x800CEB04 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB10u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB08 jalr */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB10 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEB14 */
    R[3] = R[3] + R[2];  /* 0x800CEB18 */
    { R[31] = 0x800CEB24u; sw_(R[16] + -8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CEB1C jal */
    R[4] = R[2] + R[0];  /* 0x800CEB24 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB30u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB28 jalr */
    R[4] = R[0] + 4096;  /* 0x800CEB30 */
    R[3] = lw_(R[16]);  /* 0x800CEB34 */
    R[5] = R[17] + R[0];  /* 0x800CEB38 */
    R[3] = R[3] + R[2];  /* 0x800CEB3C */
    { uint32_t _t = R[19]; R[31] = 0x800CEB48u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEB40 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CEB54; } }  /* 0x800CEB48 */
    R[2] = R[2] + 4095;  /* 0x800CEB50 */
L_800CEB54:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEB54 */
    R[3] = R[0] + 64;  /* 0x800CEB58 */
    R[4] = lb_(R[16] + 49);  /* 0x800CEB5C */
    R[3] = R[3] - R[2];  /* 0x800CEB60 */
    sb_(R[16] + 37, R[3]);  /* 0x800CEB64 */
    R[4] = R[4] & 0x3;  /* 0x800CEB68 */
    { uint32_t _c = (R[4] != R[0]); sb_(R[16] + 36, R[3]); if (_c) { goto L_800CEBB4; } }  /* 0x800CEB6C */
    R[4] = R[23] + 216;  /* 0x800CEB74 */
    { R[31] = 0x800CEB80u; R[5] = R[0] + 16; psx_next = 0x800BDFDCu; return; }  /* 0x800CEB78 jal */
    R[4] = R[2] + R[0];  /* 0x800CEB80 */
    R[5] = R[29] + 32;  /* 0x800CEB84 */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB88 */
    R[6] = R[0] + 32;  /* 0x800CEB8C */
    sw_(R[29] + 32, R[3]);  /* 0x800CEB90 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEB94 */
    R[7] = 0x800Fu << 16;  /* 0x800CEB98 */
    R[2] = R[0] - R[2];  /* 0x800CEB9C */
    sw_(R[29] + 36, R[2]);  /* 0x800CEBA0 */
    R[2] = lw_(R[16]);  /* 0x800CEBA4 */
    R[7] = R[7] - 372;  /* 0x800CEBA8 */
    { R[31] = 0x800CEBB4u; sw_(R[29] + 40, R[2]); psx_next = 0x800CDD84u; return; }  /* 0x800CEBAC jal */
L_800CEBB4:;
    R[4] = R[23] + 216;  /* 0x800CEBB4 */
    R[5] = R[0] + 13;  /* 0x800CEBB8 */
    { R[31] = 0x800CEBC4u; R[6] = R[0] + 24576; psx_next = 0x800CDE50u; return; }  /* 0x800CEBBC jal */
L_800CEBC4:;
    R[22] = R[22] + 1;  /* 0x800CEBC4 */
    R[16] = R[16] + 72;  /* 0x800CEBC8 */
    R[20] = R[20] + 1;  /* 0x800CEBCC */
    R[2] = ((int32_t)R[20] < 3);  /* 0x800CEBD0 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_next = 0x800CE904u; return; } }  /* 0x800CEBD4 b extern */
    R[2] = R[22] + R[0];  /* 0x800CEBDC */
    R[31] = lw_(R[29] + 84);  /* 0x800CEBE0 */
    R[30] = lw_(R[29] + 80);  /* 0x800CEBE4 */
    R[23] = lw_(R[29] + 76);  /* 0x800CEBE8 */
    R[22] = lw_(R[29] + 72);  /* 0x800CEBEC */
    R[21] = lw_(R[29] + 68);  /* 0x800CEBF0 */
    R[20] = lw_(R[29] + 64);  /* 0x800CEBF4 */
    R[19] = lw_(R[29] + 60);  /* 0x800CEBF8 */
    R[18] = lw_(R[29] + 56);  /* 0x800CEBFC */
    R[17] = lw_(R[29] + 52);  /* 0x800CEC00 */
    R[16] = lw_(R[29] + 48);  /* 0x800CEC04 */
    { R[29] = R[29] + 88; psx_next = R[31]; return; }  /* 0x800CEC08 jr ra */
}

void g0_800CEAC0(void) {
    R[3] = lb_(R[16] + 49);  /* 0x800CEAC0 */
    R[2] = (R[3] < (uint32_t)33u);  /* 0x800CEAC8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] + 1; if (_c) { goto L_800CEAE8; } }  /* 0x800CEACC */
    R[2] = lh_(R[21] + 592);  /* 0x800CEAD4 */
    R[17] = 0x2u << 16;  /* 0x800CEAD8 */
    R[2] = R[2] + 1;  /* 0x800CEADC */
    { sh_(R[21] + 592, R[2]); goto L_800CEAF4; }  /* 0x800CEAE0 j */
L_800CEAE8:;
    sb_(R[16] + 49, R[2]);  /* 0x800CEAE8 */
    R[2] = R[2] & 0xFF;  /* 0x800CEAEC */
    R[17] = R[2] << 12;  /* 0x800CEAF0 */
L_800CEAF4:;
    R[2] = 0x1u << 16;  /* 0x800CEAF4 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEAF8 */
    { R[31] = 0x800CEB04u; R[17] = R[17] + R[2]; psx_next = 0x80035B18u; return; }  /* 0x800CEAFC jal */
    R[4] = R[2] + R[0];  /* 0x800CEB04 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB10u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB08 jalr */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB10 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEB14 */
    R[3] = R[3] + R[2];  /* 0x800CEB18 */
    { R[31] = 0x800CEB24u; sw_(R[16] + -8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CEB1C jal */
    R[4] = R[2] + R[0];  /* 0x800CEB24 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB30u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB28 jalr */
    R[4] = R[0] + 4096;  /* 0x800CEB30 */
    R[3] = lw_(R[16]);  /* 0x800CEB34 */
    R[5] = R[17] + R[0];  /* 0x800CEB38 */
    R[3] = R[3] + R[2];  /* 0x800CEB3C */
    { uint32_t _t = R[19]; R[31] = 0x800CEB48u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEB40 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CEB54; } }  /* 0x800CEB48 */
    R[2] = R[2] + 4095;  /* 0x800CEB50 */
L_800CEB54:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEB54 */
    R[3] = R[0] + 64;  /* 0x800CEB58 */
    R[4] = lb_(R[16] + 49);  /* 0x800CEB5C */
    R[3] = R[3] - R[2];  /* 0x800CEB60 */
    sb_(R[16] + 37, R[3]);  /* 0x800CEB64 */
    R[4] = R[4] & 0x3;  /* 0x800CEB68 */
    { uint32_t _c = (R[4] != R[0]); sb_(R[16] + 36, R[3]); if (_c) { goto L_800CEBB4; } }  /* 0x800CEB6C */
    R[4] = R[23] + 216;  /* 0x800CEB74 */
    { R[31] = 0x800CEB80u; R[5] = R[0] + 16; psx_next = 0x800BDFDCu; return; }  /* 0x800CEB78 jal */
    R[4] = R[2] + R[0];  /* 0x800CEB80 */
    R[5] = R[29] + 32;  /* 0x800CEB84 */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB88 */
    R[6] = R[0] + 32;  /* 0x800CEB8C */
    sw_(R[29] + 32, R[3]);  /* 0x800CEB90 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEB94 */
    R[7] = 0x800Fu << 16;  /* 0x800CEB98 */
    R[2] = R[0] - R[2];  /* 0x800CEB9C */
    sw_(R[29] + 36, R[2]);  /* 0x800CEBA0 */
    R[2] = lw_(R[16]);  /* 0x800CEBA4 */
    R[7] = R[7] - 372;  /* 0x800CEBA8 */
    { R[31] = 0x800CEBB4u; sw_(R[29] + 40, R[2]); psx_next = 0x800CDD84u; return; }  /* 0x800CEBAC jal */
L_800CEBB4:;
    R[4] = R[23] + 216;  /* 0x800CEBB4 */
    R[5] = R[0] + 13;  /* 0x800CEBB8 */
    { R[31] = 0x800CEBC4u; R[6] = R[0] + 24576; psx_next = 0x800CDE50u; return; }  /* 0x800CEBBC jal */
    R[22] = R[22] + 1;  /* 0x800CEBC4 */
    R[16] = R[16] + 72;  /* 0x800CEBC8 */
    R[20] = R[20] + 1;  /* 0x800CEBCC */
    R[2] = ((int32_t)R[20] < 3);  /* 0x800CEBD0 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_next = 0x800CE904u; return; } }  /* 0x800CEBD4 b extern */
    R[2] = R[22] + R[0];  /* 0x800CEBDC */
    R[31] = lw_(R[29] + 84);  /* 0x800CEBE0 */
    R[30] = lw_(R[29] + 80);  /* 0x800CEBE4 */
    R[23] = lw_(R[29] + 76);  /* 0x800CEBE8 */
    R[22] = lw_(R[29] + 72);  /* 0x800CEBEC */
    R[21] = lw_(R[29] + 68);  /* 0x800CEBF0 */
    R[20] = lw_(R[29] + 64);  /* 0x800CEBF4 */
    R[19] = lw_(R[29] + 60);  /* 0x800CEBF8 */
    R[18] = lw_(R[29] + 56);  /* 0x800CEBFC */
    R[17] = lw_(R[29] + 52);  /* 0x800CEC00 */
    R[16] = lw_(R[29] + 48);  /* 0x800CEC04 */
    { R[29] = R[29] + 88; psx_next = R[31]; return; }  /* 0x800CEC08 jr ra */
}

void g0_800CEB04(void) {
    R[4] = R[2] + R[0];  /* 0x800CEB04 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB10u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB08 jalr */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB10 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEB14 */
    R[3] = R[3] + R[2];  /* 0x800CEB18 */
    { R[31] = 0x800CEB24u; sw_(R[16] + -8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CEB1C jal */
    R[4] = R[2] + R[0];  /* 0x800CEB24 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB30u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB28 jalr */
    R[4] = R[0] + 4096;  /* 0x800CEB30 */
    R[3] = lw_(R[16]);  /* 0x800CEB34 */
    R[5] = R[17] + R[0];  /* 0x800CEB38 */
    R[3] = R[3] + R[2];  /* 0x800CEB3C */
    { uint32_t _t = R[19]; R[31] = 0x800CEB48u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEB40 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CEB54; } }  /* 0x800CEB48 */
    R[2] = R[2] + 4095;  /* 0x800CEB50 */
L_800CEB54:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEB54 */
    R[3] = R[0] + 64;  /* 0x800CEB58 */
    R[4] = lb_(R[16] + 49);  /* 0x800CEB5C */
    R[3] = R[3] - R[2];  /* 0x800CEB60 */
    sb_(R[16] + 37, R[3]);  /* 0x800CEB64 */
    R[4] = R[4] & 0x3;  /* 0x800CEB68 */
    { uint32_t _c = (R[4] != R[0]); sb_(R[16] + 36, R[3]); if (_c) { goto L_800CEBB4; } }  /* 0x800CEB6C */
    R[4] = R[23] + 216;  /* 0x800CEB74 */
    { R[31] = 0x800CEB80u; R[5] = R[0] + 16; psx_next = 0x800BDFDCu; return; }  /* 0x800CEB78 jal */
    R[4] = R[2] + R[0];  /* 0x800CEB80 */
    R[5] = R[29] + 32;  /* 0x800CEB84 */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB88 */
    R[6] = R[0] + 32;  /* 0x800CEB8C */
    sw_(R[29] + 32, R[3]);  /* 0x800CEB90 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEB94 */
    R[7] = 0x800Fu << 16;  /* 0x800CEB98 */
    R[2] = R[0] - R[2];  /* 0x800CEB9C */
    sw_(R[29] + 36, R[2]);  /* 0x800CEBA0 */
    R[2] = lw_(R[16]);  /* 0x800CEBA4 */
    R[7] = R[7] - 372;  /* 0x800CEBA8 */
    { R[31] = 0x800CEBB4u; sw_(R[29] + 40, R[2]); psx_next = 0x800CDD84u; return; }  /* 0x800CEBAC jal */
L_800CEBB4:;
    R[4] = R[23] + 216;  /* 0x800CEBB4 */
    R[5] = R[0] + 13;  /* 0x800CEBB8 */
    { R[31] = 0x800CEBC4u; R[6] = R[0] + 24576; psx_next = 0x800CDE50u; return; }  /* 0x800CEBBC jal */
    R[22] = R[22] + 1;  /* 0x800CEBC4 */
    R[16] = R[16] + 72;  /* 0x800CEBC8 */
    R[20] = R[20] + 1;  /* 0x800CEBCC */
    R[2] = ((int32_t)R[20] < 3);  /* 0x800CEBD0 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_next = 0x800CE904u; return; } }  /* 0x800CEBD4 b extern */
    R[2] = R[22] + R[0];  /* 0x800CEBDC */
    R[31] = lw_(R[29] + 84);  /* 0x800CEBE0 */
    R[30] = lw_(R[29] + 80);  /* 0x800CEBE4 */
    R[23] = lw_(R[29] + 76);  /* 0x800CEBE8 */
    R[22] = lw_(R[29] + 72);  /* 0x800CEBEC */
    R[21] = lw_(R[29] + 68);  /* 0x800CEBF0 */
    R[20] = lw_(R[29] + 64);  /* 0x800CEBF4 */
    R[19] = lw_(R[29] + 60);  /* 0x800CEBF8 */
    R[18] = lw_(R[29] + 56);  /* 0x800CEBFC */
    R[17] = lw_(R[29] + 52);  /* 0x800CEC00 */
    R[16] = lw_(R[29] + 48);  /* 0x800CEC04 */
    { R[29] = R[29] + 88; psx_next = R[31]; return; }  /* 0x800CEC08 jr ra */
}

void g0_800CEB10(void) {
    R[3] = lw_(R[16] + -8);  /* 0x800CEB10 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 50);  /* 0x800CEB14 */
    R[3] = R[3] + R[2];  /* 0x800CEB18 */
    { R[31] = 0x800CEB24u; sw_(R[16] + -8, R[3]); psx_next = 0x80035A48u; return; }  /* 0x800CEB1C jal */
    R[4] = R[2] + R[0];  /* 0x800CEB24 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB30u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB28 jalr */
    R[4] = R[0] + 4096;  /* 0x800CEB30 */
    R[3] = lw_(R[16]);  /* 0x800CEB34 */
    R[5] = R[17] + R[0];  /* 0x800CEB38 */
    R[3] = R[3] + R[2];  /* 0x800CEB3C */
    { uint32_t _t = R[19]; R[31] = 0x800CEB48u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEB40 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CEB54; } }  /* 0x800CEB48 */
    R[2] = R[2] + 4095;  /* 0x800CEB50 */
L_800CEB54:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEB54 */
    R[3] = R[0] + 64;  /* 0x800CEB58 */
    R[4] = lb_(R[16] + 49);  /* 0x800CEB5C */
    R[3] = R[3] - R[2];  /* 0x800CEB60 */
    sb_(R[16] + 37, R[3]);  /* 0x800CEB64 */
    R[4] = R[4] & 0x3;  /* 0x800CEB68 */
    { uint32_t _c = (R[4] != R[0]); sb_(R[16] + 36, R[3]); if (_c) { goto L_800CEBB4; } }  /* 0x800CEB6C */
    R[4] = R[23] + 216;  /* 0x800CEB74 */
    { R[31] = 0x800CEB80u; R[5] = R[0] + 16; psx_next = 0x800BDFDCu; return; }  /* 0x800CEB78 jal */
    R[4] = R[2] + R[0];  /* 0x800CEB80 */
    R[5] = R[29] + 32;  /* 0x800CEB84 */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB88 */
    R[6] = R[0] + 32;  /* 0x800CEB8C */
    sw_(R[29] + 32, R[3]);  /* 0x800CEB90 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEB94 */
    R[7] = 0x800Fu << 16;  /* 0x800CEB98 */
    R[2] = R[0] - R[2];  /* 0x800CEB9C */
    sw_(R[29] + 36, R[2]);  /* 0x800CEBA0 */
    R[2] = lw_(R[16]);  /* 0x800CEBA4 */
    R[7] = R[7] - 372;  /* 0x800CEBA8 */
    { R[31] = 0x800CEBB4u; sw_(R[29] + 40, R[2]); psx_next = 0x800CDD84u; return; }  /* 0x800CEBAC jal */
L_800CEBB4:;
    R[4] = R[23] + 216;  /* 0x800CEBB4 */
    R[5] = R[0] + 13;  /* 0x800CEBB8 */
    { R[31] = 0x800CEBC4u; R[6] = R[0] + 24576; psx_next = 0x800CDE50u; return; }  /* 0x800CEBBC jal */
    R[22] = R[22] + 1;  /* 0x800CEBC4 */
    R[16] = R[16] + 72;  /* 0x800CEBC8 */
    R[20] = R[20] + 1;  /* 0x800CEBCC */
    R[2] = ((int32_t)R[20] < 3);  /* 0x800CEBD0 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_next = 0x800CE904u; return; } }  /* 0x800CEBD4 b extern */
    R[2] = R[22] + R[0];  /* 0x800CEBDC */
    R[31] = lw_(R[29] + 84);  /* 0x800CEBE0 */
    R[30] = lw_(R[29] + 80);  /* 0x800CEBE4 */
    R[23] = lw_(R[29] + 76);  /* 0x800CEBE8 */
    R[22] = lw_(R[29] + 72);  /* 0x800CEBEC */
    R[21] = lw_(R[29] + 68);  /* 0x800CEBF0 */
    R[20] = lw_(R[29] + 64);  /* 0x800CEBF4 */
    R[19] = lw_(R[29] + 60);  /* 0x800CEBF8 */
    R[18] = lw_(R[29] + 56);  /* 0x800CEBFC */
    R[17] = lw_(R[29] + 52);  /* 0x800CEC00 */
    R[16] = lw_(R[29] + 48);  /* 0x800CEC04 */
    { R[29] = R[29] + 88; psx_next = R[31]; return; }  /* 0x800CEC08 jr ra */
}

void g0_800CEB24(void) {
    R[4] = R[2] + R[0];  /* 0x800CEB24 */
    { uint32_t _t = R[19]; R[31] = 0x800CEB30u; R[5] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800CEB28 jalr */
    R[4] = R[0] + 4096;  /* 0x800CEB30 */
    R[3] = lw_(R[16]);  /* 0x800CEB34 */
    R[5] = R[17] + R[0];  /* 0x800CEB38 */
    R[3] = R[3] + R[2];  /* 0x800CEB3C */
    { uint32_t _t = R[19]; R[31] = 0x800CEB48u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEB40 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CEB54; } }  /* 0x800CEB48 */
    R[2] = R[2] + 4095;  /* 0x800CEB50 */
L_800CEB54:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEB54 */
    R[3] = R[0] + 64;  /* 0x800CEB58 */
    R[4] = lb_(R[16] + 49);  /* 0x800CEB5C */
    R[3] = R[3] - R[2];  /* 0x800CEB60 */
    sb_(R[16] + 37, R[3]);  /* 0x800CEB64 */
    R[4] = R[4] & 0x3;  /* 0x800CEB68 */
    { uint32_t _c = (R[4] != R[0]); sb_(R[16] + 36, R[3]); if (_c) { goto L_800CEBB4; } }  /* 0x800CEB6C */
    R[4] = R[23] + 216;  /* 0x800CEB74 */
    { R[31] = 0x800CEB80u; R[5] = R[0] + 16; psx_next = 0x800BDFDCu; return; }  /* 0x800CEB78 jal */
    R[4] = R[2] + R[0];  /* 0x800CEB80 */
    R[5] = R[29] + 32;  /* 0x800CEB84 */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB88 */
    R[6] = R[0] + 32;  /* 0x800CEB8C */
    sw_(R[29] + 32, R[3]);  /* 0x800CEB90 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEB94 */
    R[7] = 0x800Fu << 16;  /* 0x800CEB98 */
    R[2] = R[0] - R[2];  /* 0x800CEB9C */
    sw_(R[29] + 36, R[2]);  /* 0x800CEBA0 */
    R[2] = lw_(R[16]);  /* 0x800CEBA4 */
    R[7] = R[7] - 372;  /* 0x800CEBA8 */
    { R[31] = 0x800CEBB4u; sw_(R[29] + 40, R[2]); psx_next = 0x800CDD84u; return; }  /* 0x800CEBAC jal */
L_800CEBB4:;
    R[4] = R[23] + 216;  /* 0x800CEBB4 */
    R[5] = R[0] + 13;  /* 0x800CEBB8 */
    { R[31] = 0x800CEBC4u; R[6] = R[0] + 24576; psx_next = 0x800CDE50u; return; }  /* 0x800CEBBC jal */
    R[22] = R[22] + 1;  /* 0x800CEBC4 */
    R[16] = R[16] + 72;  /* 0x800CEBC8 */
    R[20] = R[20] + 1;  /* 0x800CEBCC */
    R[2] = ((int32_t)R[20] < 3);  /* 0x800CEBD0 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_next = 0x800CE904u; return; } }  /* 0x800CEBD4 b extern */
    R[2] = R[22] + R[0];  /* 0x800CEBDC */
    R[31] = lw_(R[29] + 84);  /* 0x800CEBE0 */
    R[30] = lw_(R[29] + 80);  /* 0x800CEBE4 */
    R[23] = lw_(R[29] + 76);  /* 0x800CEBE8 */
    R[22] = lw_(R[29] + 72);  /* 0x800CEBEC */
    R[21] = lw_(R[29] + 68);  /* 0x800CEBF0 */
    R[20] = lw_(R[29] + 64);  /* 0x800CEBF4 */
    R[19] = lw_(R[29] + 60);  /* 0x800CEBF8 */
    R[18] = lw_(R[29] + 56);  /* 0x800CEBFC */
    R[17] = lw_(R[29] + 52);  /* 0x800CEC00 */
    R[16] = lw_(R[29] + 48);  /* 0x800CEC04 */
    { R[29] = R[29] + 88; psx_next = R[31]; return; }  /* 0x800CEC08 jr ra */
}

void g0_800CEB30(void) {
    R[4] = R[0] + 4096;  /* 0x800CEB30 */
    R[3] = lw_(R[16]);  /* 0x800CEB34 */
    R[5] = R[17] + R[0];  /* 0x800CEB38 */
    R[3] = R[3] + R[2];  /* 0x800CEB3C */
    { uint32_t _t = R[19]; R[31] = 0x800CEB48u; sw_(R[16], R[3]); psx_next = _t; return; }  /* 0x800CEB40 jalr */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CEB54; } }  /* 0x800CEB48 */
    R[2] = R[2] + 4095;  /* 0x800CEB50 */
L_800CEB54:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEB54 */
    R[3] = R[0] + 64;  /* 0x800CEB58 */
    R[4] = lb_(R[16] + 49);  /* 0x800CEB5C */
    R[3] = R[3] - R[2];  /* 0x800CEB60 */
    sb_(R[16] + 37, R[3]);  /* 0x800CEB64 */
    R[4] = R[4] & 0x3;  /* 0x800CEB68 */
    { uint32_t _c = (R[4] != R[0]); sb_(R[16] + 36, R[3]); if (_c) { goto L_800CEBB4; } }  /* 0x800CEB6C */
    R[4] = R[23] + 216;  /* 0x800CEB74 */
    { R[31] = 0x800CEB80u; R[5] = R[0] + 16; psx_next = 0x800BDFDCu; return; }  /* 0x800CEB78 jal */
    R[4] = R[2] + R[0];  /* 0x800CEB80 */
    R[5] = R[29] + 32;  /* 0x800CEB84 */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB88 */
    R[6] = R[0] + 32;  /* 0x800CEB8C */
    sw_(R[29] + 32, R[3]);  /* 0x800CEB90 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEB94 */
    R[7] = 0x800Fu << 16;  /* 0x800CEB98 */
    R[2] = R[0] - R[2];  /* 0x800CEB9C */
    sw_(R[29] + 36, R[2]);  /* 0x800CEBA0 */
    R[2] = lw_(R[16]);  /* 0x800CEBA4 */
    R[7] = R[7] - 372;  /* 0x800CEBA8 */
    { R[31] = 0x800CEBB4u; sw_(R[29] + 40, R[2]); psx_next = 0x800CDD84u; return; }  /* 0x800CEBAC jal */
L_800CEBB4:;
    R[4] = R[23] + 216;  /* 0x800CEBB4 */
    R[5] = R[0] + 13;  /* 0x800CEBB8 */
    { R[31] = 0x800CEBC4u; R[6] = R[0] + 24576; psx_next = 0x800CDE50u; return; }  /* 0x800CEBBC jal */
    R[22] = R[22] + 1;  /* 0x800CEBC4 */
    R[16] = R[16] + 72;  /* 0x800CEBC8 */
    R[20] = R[20] + 1;  /* 0x800CEBCC */
    R[2] = ((int32_t)R[20] < 3);  /* 0x800CEBD0 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_next = 0x800CE904u; return; } }  /* 0x800CEBD4 b extern */
    R[2] = R[22] + R[0];  /* 0x800CEBDC */
    R[31] = lw_(R[29] + 84);  /* 0x800CEBE0 */
    R[30] = lw_(R[29] + 80);  /* 0x800CEBE4 */
    R[23] = lw_(R[29] + 76);  /* 0x800CEBE8 */
    R[22] = lw_(R[29] + 72);  /* 0x800CEBEC */
    R[21] = lw_(R[29] + 68);  /* 0x800CEBF0 */
    R[20] = lw_(R[29] + 64);  /* 0x800CEBF4 */
    R[19] = lw_(R[29] + 60);  /* 0x800CEBF8 */
    R[18] = lw_(R[29] + 56);  /* 0x800CEBFC */
    R[17] = lw_(R[29] + 52);  /* 0x800CEC00 */
    R[16] = lw_(R[29] + 48);  /* 0x800CEC04 */
    { R[29] = R[29] + 88; psx_next = R[31]; return; }  /* 0x800CEC08 jr ra */
}

void g0_800CEB48(void) {
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CEB54; } }  /* 0x800CEB48 */
    R[2] = R[2] + 4095;  /* 0x800CEB50 */
L_800CEB54:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CEB54 */
    R[3] = R[0] + 64;  /* 0x800CEB58 */
    R[4] = lb_(R[16] + 49);  /* 0x800CEB5C */
    R[3] = R[3] - R[2];  /* 0x800CEB60 */
    sb_(R[16] + 37, R[3]);  /* 0x800CEB64 */
    R[4] = R[4] & 0x3;  /* 0x800CEB68 */
    { uint32_t _c = (R[4] != R[0]); sb_(R[16] + 36, R[3]); if (_c) { goto L_800CEBB4; } }  /* 0x800CEB6C */
    R[4] = R[23] + 216;  /* 0x800CEB74 */
    { R[31] = 0x800CEB80u; R[5] = R[0] + 16; psx_next = 0x800BDFDCu; return; }  /* 0x800CEB78 jal */
    R[4] = R[2] + R[0];  /* 0x800CEB80 */
    R[5] = R[29] + 32;  /* 0x800CEB84 */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB88 */
    R[6] = R[0] + 32;  /* 0x800CEB8C */
    sw_(R[29] + 32, R[3]);  /* 0x800CEB90 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEB94 */
    R[7] = 0x800Fu << 16;  /* 0x800CEB98 */
    R[2] = R[0] - R[2];  /* 0x800CEB9C */
    sw_(R[29] + 36, R[2]);  /* 0x800CEBA0 */
    R[2] = lw_(R[16]);  /* 0x800CEBA4 */
    R[7] = R[7] - 372;  /* 0x800CEBA8 */
    { R[31] = 0x800CEBB4u; sw_(R[29] + 40, R[2]); psx_next = 0x800CDD84u; return; }  /* 0x800CEBAC jal */
L_800CEBB4:;
    R[4] = R[23] + 216;  /* 0x800CEBB4 */
    R[5] = R[0] + 13;  /* 0x800CEBB8 */
    { R[31] = 0x800CEBC4u; R[6] = R[0] + 24576; psx_next = 0x800CDE50u; return; }  /* 0x800CEBBC jal */
    R[22] = R[22] + 1;  /* 0x800CEBC4 */
    R[16] = R[16] + 72;  /* 0x800CEBC8 */
    R[20] = R[20] + 1;  /* 0x800CEBCC */
    R[2] = ((int32_t)R[20] < 3);  /* 0x800CEBD0 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_next = 0x800CE904u; return; } }  /* 0x800CEBD4 b extern */
    R[2] = R[22] + R[0];  /* 0x800CEBDC */
    R[31] = lw_(R[29] + 84);  /* 0x800CEBE0 */
    R[30] = lw_(R[29] + 80);  /* 0x800CEBE4 */
    R[23] = lw_(R[29] + 76);  /* 0x800CEBE8 */
    R[22] = lw_(R[29] + 72);  /* 0x800CEBEC */
    R[21] = lw_(R[29] + 68);  /* 0x800CEBF0 */
    R[20] = lw_(R[29] + 64);  /* 0x800CEBF4 */
    R[19] = lw_(R[29] + 60);  /* 0x800CEBF8 */
    R[18] = lw_(R[29] + 56);  /* 0x800CEBFC */
    R[17] = lw_(R[29] + 52);  /* 0x800CEC00 */
    R[16] = lw_(R[29] + 48);  /* 0x800CEC04 */
    { R[29] = R[29] + 88; psx_next = R[31]; return; }  /* 0x800CEC08 jr ra */
}

void g0_800CEB80(void) {
    R[4] = R[2] + R[0];  /* 0x800CEB80 */
    R[5] = R[29] + 32;  /* 0x800CEB84 */
    R[3] = lw_(R[16] + -8);  /* 0x800CEB88 */
    R[6] = R[0] + 32;  /* 0x800CEB8C */
    sw_(R[29] + 32, R[3]);  /* 0x800CEB90 */
    R[2] = lw_(R[16] + -4);  /* 0x800CEB94 */
    R[7] = 0x800Fu << 16;  /* 0x800CEB98 */
    R[2] = R[0] - R[2];  /* 0x800CEB9C */
    sw_(R[29] + 36, R[2]);  /* 0x800CEBA0 */
    R[2] = lw_(R[16]);  /* 0x800CEBA4 */
    R[7] = R[7] - 372;  /* 0x800CEBA8 */
    { R[31] = 0x800CEBB4u; sw_(R[29] + 40, R[2]); psx_next = 0x800CDD84u; return; }  /* 0x800CEBAC jal */
    R[4] = R[23] + 216;  /* 0x800CEBB4 */
    R[5] = R[0] + 13;  /* 0x800CEBB8 */
    { R[31] = 0x800CEBC4u; R[6] = R[0] + 24576; psx_next = 0x800CDE50u; return; }  /* 0x800CEBBC jal */
    R[22] = R[22] + 1;  /* 0x800CEBC4 */
    R[16] = R[16] + 72;  /* 0x800CEBC8 */
    R[20] = R[20] + 1;  /* 0x800CEBCC */
    R[2] = ((int32_t)R[20] < 3);  /* 0x800CEBD0 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_next = 0x800CE904u; return; } }  /* 0x800CEBD4 b extern */
    R[2] = R[22] + R[0];  /* 0x800CEBDC */
    R[31] = lw_(R[29] + 84);  /* 0x800CEBE0 */
    R[30] = lw_(R[29] + 80);  /* 0x800CEBE4 */
    R[23] = lw_(R[29] + 76);  /* 0x800CEBE8 */
    R[22] = lw_(R[29] + 72);  /* 0x800CEBEC */
    R[21] = lw_(R[29] + 68);  /* 0x800CEBF0 */
    R[20] = lw_(R[29] + 64);  /* 0x800CEBF4 */
    R[19] = lw_(R[29] + 60);  /* 0x800CEBF8 */
    R[18] = lw_(R[29] + 56);  /* 0x800CEBFC */
    R[17] = lw_(R[29] + 52);  /* 0x800CEC00 */
    R[16] = lw_(R[29] + 48);  /* 0x800CEC04 */
    { R[29] = R[29] + 88; psx_next = R[31]; return; }  /* 0x800CEC08 jr ra */
}

void g0_800CEBB4(void) {
    R[4] = R[23] + 216;  /* 0x800CEBB4 */
    R[5] = R[0] + 13;  /* 0x800CEBB8 */
    { R[31] = 0x800CEBC4u; R[6] = R[0] + 24576; psx_next = 0x800CDE50u; return; }  /* 0x800CEBBC jal */
    R[22] = R[22] + 1;  /* 0x800CEBC4 */
    R[16] = R[16] + 72;  /* 0x800CEBC8 */
    R[20] = R[20] + 1;  /* 0x800CEBCC */
    R[2] = ((int32_t)R[20] < 3);  /* 0x800CEBD0 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_next = 0x800CE904u; return; } }  /* 0x800CEBD4 b extern */
    R[2] = R[22] + R[0];  /* 0x800CEBDC */
    R[31] = lw_(R[29] + 84);  /* 0x800CEBE0 */
    R[30] = lw_(R[29] + 80);  /* 0x800CEBE4 */
    R[23] = lw_(R[29] + 76);  /* 0x800CEBE8 */
    R[22] = lw_(R[29] + 72);  /* 0x800CEBEC */
    R[21] = lw_(R[29] + 68);  /* 0x800CEBF0 */
    R[20] = lw_(R[29] + 64);  /* 0x800CEBF4 */
    R[19] = lw_(R[29] + 60);  /* 0x800CEBF8 */
    R[18] = lw_(R[29] + 56);  /* 0x800CEBFC */
    R[17] = lw_(R[29] + 52);  /* 0x800CEC00 */
    R[16] = lw_(R[29] + 48);  /* 0x800CEC04 */
    { R[29] = R[29] + 88; psx_next = R[31]; return; }  /* 0x800CEC08 jr ra */
}

void g0_800CEBC4(void) {
    R[22] = R[22] + 1;  /* 0x800CEBC4 */
    R[16] = R[16] + 72;  /* 0x800CEBC8 */
    R[20] = R[20] + 1;  /* 0x800CEBCC */
    R[2] = ((int32_t)R[20] < 3);  /* 0x800CEBD0 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_next = 0x800CE904u; return; } }  /* 0x800CEBD4 b extern */
    R[2] = R[22] + R[0];  /* 0x800CEBDC */
    R[31] = lw_(R[29] + 84);  /* 0x800CEBE0 */
    R[30] = lw_(R[29] + 80);  /* 0x800CEBE4 */
    R[23] = lw_(R[29] + 76);  /* 0x800CEBE8 */
    R[22] = lw_(R[29] + 72);  /* 0x800CEBEC */
    R[21] = lw_(R[29] + 68);  /* 0x800CEBF0 */
    R[20] = lw_(R[29] + 64);  /* 0x800CEBF4 */
    R[19] = lw_(R[29] + 60);  /* 0x800CEBF8 */
    R[18] = lw_(R[29] + 56);  /* 0x800CEBFC */
    R[17] = lw_(R[29] + 52);  /* 0x800CEC00 */
    R[16] = lw_(R[29] + 48);  /* 0x800CEC04 */
    { R[29] = R[29] + 88; psx_next = R[31]; return; }  /* 0x800CEC08 jr ra */
}

void g0_800CEC10(void) {
    R[29] = R[29] - 56;  /* 0x800CEC10 */
    sw_(R[29] + 40, R[22]);  /* 0x800CEC14 */
    R[22] = R[4] + R[0];  /* 0x800CEC18 */
    sw_(R[29] + 16, R[16]);  /* 0x800CEC1C */
    R[16] = R[5] + R[0];  /* 0x800CEC20 */
    sw_(R[29] + 44, R[23]);  /* 0x800CEC24 */
    R[23] = R[6] + R[0];  /* 0x800CEC28 */
    sw_(R[29] + 24, R[18]);  /* 0x800CEC2C */
    R[18] = R[7] + R[0];  /* 0x800CEC30 */
    sw_(R[29] + 48, R[31]);  /* 0x800CEC34 */
    sw_(R[29] + 36, R[21]);  /* 0x800CEC38 */
    sw_(R[29] + 32, R[20]);  /* 0x800CEC3C */
    sw_(R[29] + 28, R[19]);  /* 0x800CEC40 */
    { R[31] = 0x800CEC4Cu; sw_(R[29] + 20, R[17]); psx_next = 0x80093774u; return; }  /* 0x800CEC44 jal */
    R[20] = R[2] + R[0];  /* 0x800CEC4C */
    { uint32_t _c = ((int32_t)R[20] <= 0); R[2] = R[0] + R[0]; if (_c) { goto L_800CED68; } }  /* 0x800CEC50 */
    R[2] = R[16] - 1;  /* 0x800CEC58 */
    R[2] = R[2] & 0xFFFF;  /* 0x800CEC5C */
    R[2] = (R[2] < (uint32_t)999u);  /* 0x800CEC60 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[16] << 16; if (_c) { goto L_800CEC78; } }  /* 0x800CEC64 */
    R[21] = 0xFu << 16;  /* 0x800CEC6C */
    { R[21] = R[21] | 0x4240; goto L_800CEC84; }  /* 0x800CEC70 j */
L_800CEC78:;
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CEC78 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CEC7C */
    R[21] = LO;  /* 0x800CEC80 */
L_800CEC84:;
    R[2] = 0x8013u << 16;  /* 0x800CEC84 */
    R[17] = R[2] - 31752;  /* 0x800CEC88 */
    R[19] = R[0] + R[0];  /* 0x800CEC8C */
    { uint32_t _c = ((int32_t)R[20] <= 0); R[16] = R[19] + R[0]; if (_c) { goto L_800CED64; } }  /* 0x800CEC90 */
L_800CEC98:;
    R[5] = lw_(R[17]);  /* 0x800CEC98 */
    R[2] = lh_(R[5] + 12);  /* 0x800CECA0 */
    R[2] = R[2] - 2;  /* 0x800CECA8 */
    R[2] = (R[2] < (uint32_t)3u);  /* 0x800CECAC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CED54; } }  /* 0x800CECB0 */
    R[2] = lb_(R[5] + 789);  /* 0x800CECB8 */
    R[2] = R[2] & 0x1;  /* 0x800CECC0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800CED54; } }  /* 0x800CECC4 */
    R[3] = lb_(R[5] + 791);  /* 0x800CECCC */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_800CED54; } }  /* 0x800CECD4 */
    R[2] = lb_(R[5] + 787);  /* 0x800CECDC */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0xFFu << 16; if (_c) { goto L_800CED54; } }  /* 0x800CECE4 */
    R[2] = lw_(R[5] + 788);  /* 0x800CECEC */
    R[3] = R[3] | 0xFF;  /* 0x800CECF0 */
    R[2] = R[2] & R[3];  /* 0x800CECF4 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CED54; } }  /* 0x800CECF8 */
    R[2] = lh_(R[5] + 88);  /* 0x800CED00 */
    R[2] = R[2] & 0x1000;  /* 0x800CED08 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CED54; } }  /* 0x800CED0C */
    R[2] = lb_(R[5] + 797);  /* 0x800CED14 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[22] + 24; if (_c) { goto L_800CED54; } }  /* 0x800CED1C */
    R[5] = R[5] + 24;  /* 0x800CED24 */
    { R[31] = 0x800CED30u; R[6] = R[0] + 1000; psx_next = 0x800B6A98u; return; }  /* 0x800CED28 jal */
    R[2] = (R[21] < R[2]);  /* 0x800CED30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CED54; } }  /* 0x800CED34 */
    R[2] = lw_(R[17]);  /* 0x800CED3C */
    R[16] = R[16] + 1;  /* 0x800CED40 */
    sw_(R[18], R[2]);  /* 0x800CED44 */
    R[2] = ((int32_t)R[16] < (int32_t)R[23]);  /* 0x800CED48 */
    { uint32_t _c = (R[2] == R[0]); R[18] = R[18] + 4; if (_c) { goto L_800CED64; } }  /* 0x800CED4C */
L_800CED54:;
    R[19] = R[19] + 1;  /* 0x800CED54 */
    R[2] = ((int32_t)R[19] < (int32_t)R[20]);  /* 0x800CED58 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 4; if (_c) { psx_bb(); goto L_800CEC98; } }  /* 0x800CED5C */
L_800CED64:;
    R[2] = R[16] + R[0];  /* 0x800CED64 */
L_800CED68:;
    R[31] = lw_(R[29] + 48);  /* 0x800CED68 */
    R[23] = lw_(R[29] + 44);  /* 0x800CED6C */
    R[22] = lw_(R[29] + 40);  /* 0x800CED70 */
    R[21] = lw_(R[29] + 36);  /* 0x800CED74 */
    R[20] = lw_(R[29] + 32);  /* 0x800CED78 */
    R[19] = lw_(R[29] + 28);  /* 0x800CED7C */
    R[18] = lw_(R[29] + 24);  /* 0x800CED80 */
    R[17] = lw_(R[29] + 20);  /* 0x800CED84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CED88 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CED8C jr ra */
}

void g0_800CEC4C(void) {
    R[20] = R[2] + R[0];  /* 0x800CEC4C */
    { uint32_t _c = ((int32_t)R[20] <= 0); R[2] = R[0] + R[0]; if (_c) { goto L_800CED68; } }  /* 0x800CEC50 */
    R[2] = R[16] - 1;  /* 0x800CEC58 */
    R[2] = R[2] & 0xFFFF;  /* 0x800CEC5C */
    R[2] = (R[2] < (uint32_t)999u);  /* 0x800CEC60 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[16] << 16; if (_c) { goto L_800CEC78; } }  /* 0x800CEC64 */
    R[21] = 0xFu << 16;  /* 0x800CEC6C */
    { R[21] = R[21] | 0x4240; goto L_800CEC84; }  /* 0x800CEC70 j */
L_800CEC78:;
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CEC78 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CEC7C */
    R[21] = LO;  /* 0x800CEC80 */
L_800CEC84:;
    R[2] = 0x8013u << 16;  /* 0x800CEC84 */
    R[17] = R[2] - 31752;  /* 0x800CEC88 */
    R[19] = R[0] + R[0];  /* 0x800CEC8C */
    { uint32_t _c = ((int32_t)R[20] <= 0); R[16] = R[19] + R[0]; if (_c) { goto L_800CED64; } }  /* 0x800CEC90 */
L_800CEC98:;
    R[5] = lw_(R[17]);  /* 0x800CEC98 */
    R[2] = lh_(R[5] + 12);  /* 0x800CECA0 */
    R[2] = R[2] - 2;  /* 0x800CECA8 */
    R[2] = (R[2] < (uint32_t)3u);  /* 0x800CECAC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CED54; } }  /* 0x800CECB0 */
    R[2] = lb_(R[5] + 789);  /* 0x800CECB8 */
    R[2] = R[2] & 0x1;  /* 0x800CECC0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800CED54; } }  /* 0x800CECC4 */
    R[3] = lb_(R[5] + 791);  /* 0x800CECCC */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_800CED54; } }  /* 0x800CECD4 */
    R[2] = lb_(R[5] + 787);  /* 0x800CECDC */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0xFFu << 16; if (_c) { goto L_800CED54; } }  /* 0x800CECE4 */
    R[2] = lw_(R[5] + 788);  /* 0x800CECEC */
    R[3] = R[3] | 0xFF;  /* 0x800CECF0 */
    R[2] = R[2] & R[3];  /* 0x800CECF4 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CED54; } }  /* 0x800CECF8 */
    R[2] = lh_(R[5] + 88);  /* 0x800CED00 */
    R[2] = R[2] & 0x1000;  /* 0x800CED08 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CED54; } }  /* 0x800CED0C */
    R[2] = lb_(R[5] + 797);  /* 0x800CED14 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[22] + 24; if (_c) { goto L_800CED54; } }  /* 0x800CED1C */
    R[5] = R[5] + 24;  /* 0x800CED24 */
    { R[31] = 0x800CED30u; R[6] = R[0] + 1000; psx_next = 0x800B6A98u; return; }  /* 0x800CED28 jal */
    R[2] = (R[21] < R[2]);  /* 0x800CED30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CED54; } }  /* 0x800CED34 */
    R[2] = lw_(R[17]);  /* 0x800CED3C */
    R[16] = R[16] + 1;  /* 0x800CED40 */
    sw_(R[18], R[2]);  /* 0x800CED44 */
    R[2] = ((int32_t)R[16] < (int32_t)R[23]);  /* 0x800CED48 */
    { uint32_t _c = (R[2] == R[0]); R[18] = R[18] + 4; if (_c) { goto L_800CED64; } }  /* 0x800CED4C */
L_800CED54:;
    R[19] = R[19] + 1;  /* 0x800CED54 */
    R[2] = ((int32_t)R[19] < (int32_t)R[20]);  /* 0x800CED58 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 4; if (_c) { psx_bb(); goto L_800CEC98; } }  /* 0x800CED5C */
L_800CED64:;
    R[2] = R[16] + R[0];  /* 0x800CED64 */
L_800CED68:;
    R[31] = lw_(R[29] + 48);  /* 0x800CED68 */
    R[23] = lw_(R[29] + 44);  /* 0x800CED6C */
    R[22] = lw_(R[29] + 40);  /* 0x800CED70 */
    R[21] = lw_(R[29] + 36);  /* 0x800CED74 */
    R[20] = lw_(R[29] + 32);  /* 0x800CED78 */
    R[19] = lw_(R[29] + 28);  /* 0x800CED7C */
    R[18] = lw_(R[29] + 24);  /* 0x800CED80 */
    R[17] = lw_(R[29] + 20);  /* 0x800CED84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CED88 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CED8C jr ra */
}

void g0_800CEC98(void) {
L_800CEC98:;
    R[5] = lw_(R[17]);  /* 0x800CEC98 */
    R[2] = lh_(R[5] + 12);  /* 0x800CECA0 */
    R[2] = R[2] - 2;  /* 0x800CECA8 */
    R[2] = (R[2] < (uint32_t)3u);  /* 0x800CECAC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CED54; } }  /* 0x800CECB0 */
    R[2] = lb_(R[5] + 789);  /* 0x800CECB8 */
    R[2] = R[2] & 0x1;  /* 0x800CECC0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800CED54; } }  /* 0x800CECC4 */
    R[3] = lb_(R[5] + 791);  /* 0x800CECCC */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_800CED54; } }  /* 0x800CECD4 */
    R[2] = lb_(R[5] + 787);  /* 0x800CECDC */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0xFFu << 16; if (_c) { goto L_800CED54; } }  /* 0x800CECE4 */
    R[2] = lw_(R[5] + 788);  /* 0x800CECEC */
    R[3] = R[3] | 0xFF;  /* 0x800CECF0 */
    R[2] = R[2] & R[3];  /* 0x800CECF4 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CED54; } }  /* 0x800CECF8 */
    R[2] = lh_(R[5] + 88);  /* 0x800CED00 */
    R[2] = R[2] & 0x1000;  /* 0x800CED08 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CED54; } }  /* 0x800CED0C */
    R[2] = lb_(R[5] + 797);  /* 0x800CED14 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[22] + 24; if (_c) { goto L_800CED54; } }  /* 0x800CED1C */
    R[5] = R[5] + 24;  /* 0x800CED24 */
    { R[31] = 0x800CED30u; R[6] = R[0] + 1000; psx_next = 0x800B6A98u; return; }  /* 0x800CED28 jal */
    R[2] = (R[21] < R[2]);  /* 0x800CED30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CED54; } }  /* 0x800CED34 */
    R[2] = lw_(R[17]);  /* 0x800CED3C */
    R[16] = R[16] + 1;  /* 0x800CED40 */
    sw_(R[18], R[2]);  /* 0x800CED44 */
    R[2] = ((int32_t)R[16] < (int32_t)R[23]);  /* 0x800CED48 */
    { uint32_t _c = (R[2] == R[0]); R[18] = R[18] + 4; if (_c) { goto L_800CED64; } }  /* 0x800CED4C */
L_800CED54:;
    R[19] = R[19] + 1;  /* 0x800CED54 */
    R[2] = ((int32_t)R[19] < (int32_t)R[20]);  /* 0x800CED58 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 4; if (_c) { psx_bb(); goto L_800CEC98; } }  /* 0x800CED5C */
L_800CED64:;
    R[2] = R[16] + R[0];  /* 0x800CED64 */
    R[31] = lw_(R[29] + 48);  /* 0x800CED68 */
    R[23] = lw_(R[29] + 44);  /* 0x800CED6C */
    R[22] = lw_(R[29] + 40);  /* 0x800CED70 */
    R[21] = lw_(R[29] + 36);  /* 0x800CED74 */
    R[20] = lw_(R[29] + 32);  /* 0x800CED78 */
    R[19] = lw_(R[29] + 28);  /* 0x800CED7C */
    R[18] = lw_(R[29] + 24);  /* 0x800CED80 */
    R[17] = lw_(R[29] + 20);  /* 0x800CED84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CED88 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CED8C jr ra */
}

void g0_800CED30(void) {
    R[2] = (R[21] < R[2]);  /* 0x800CED30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CED54; } }  /* 0x800CED34 */
    R[2] = lw_(R[17]);  /* 0x800CED3C */
    R[16] = R[16] + 1;  /* 0x800CED40 */
    sw_(R[18], R[2]);  /* 0x800CED44 */
    R[2] = ((int32_t)R[16] < (int32_t)R[23]);  /* 0x800CED48 */
    { uint32_t _c = (R[2] == R[0]); R[18] = R[18] + 4; if (_c) { goto L_800CED64; } }  /* 0x800CED4C */
L_800CED54:;
    R[19] = R[19] + 1;  /* 0x800CED54 */
    R[2] = ((int32_t)R[19] < (int32_t)R[20]);  /* 0x800CED58 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 4; if (_c) { psx_next = 0x800CEC98u; return; } }  /* 0x800CED5C b extern */
L_800CED64:;
    R[2] = R[16] + R[0];  /* 0x800CED64 */
    R[31] = lw_(R[29] + 48);  /* 0x800CED68 */
    R[23] = lw_(R[29] + 44);  /* 0x800CED6C */
    R[22] = lw_(R[29] + 40);  /* 0x800CED70 */
    R[21] = lw_(R[29] + 36);  /* 0x800CED74 */
    R[20] = lw_(R[29] + 32);  /* 0x800CED78 */
    R[19] = lw_(R[29] + 28);  /* 0x800CED7C */
    R[18] = lw_(R[29] + 24);  /* 0x800CED80 */
    R[17] = lw_(R[29] + 20);  /* 0x800CED84 */
    R[16] = lw_(R[29] + 16);  /* 0x800CED88 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CED8C jr ra */
}

void g0_800CED94(void) {
    R[29] = R[29] - 32;  /* 0x800CED94 */
    sw_(R[29] + 16, R[16]);  /* 0x800CED98 */
    R[16] = R[4] + R[0];  /* 0x800CED9C */
    sw_(R[29] + 24, R[31]);  /* 0x800CEDA0 */
    sw_(R[29] + 20, R[17]);  /* 0x800CEDA4 */
    R[2] = lh_(R[16] + 592);  /* 0x800CEDA8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[2] - 1; if (_c) { goto L_800CEF78; } }  /* 0x800CEDB0 */
    R[17] = lw_(R[16] + 588);  /* 0x800CEDB8 */
    R[2] = (uint32_t)(int16_t)lh_(R[17]);  /* 0x800CEDC0 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CEDD8; } }  /* 0x800CEDC8 */
    sw_(R[16] + 588, R[0]);  /* 0x800CEDD0 */
    R[17] = R[0] + R[0];  /* 0x800CEDD4 */
L_800CEDD8:;
    { uint32_t _c = (R[17] == R[0]); if (_c) { goto L_800CEF7C; } }  /* 0x800CEDD8 */
    R[3] = lw_(R[17] + 32);  /* 0x800CEDE0 */
    R[2] = lw_(R[16] + 32);  /* 0x800CEDE4 */
    R[4] = R[3] - R[2];  /* 0x800CEDEC */
    { uint32_t _c = ((int32_t)R[4] >= 0); if (_c) { goto L_800CEDFC; } }  /* 0x800CEDF0 */
    R[4] = R[4] + 4095;  /* 0x800CEDF8 */
L_800CEDFC:;
    R[3] = lw_(R[17] + 24);  /* 0x800CEDFC */
    R[2] = lw_(R[16] + 24);  /* 0x800CEE00 */
    R[3] = R[3] - R[2];  /* 0x800CEE08 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = (uint32_t)((int32_t)R[4] >> 12); if (_c) { goto L_800CEE18; } }  /* 0x800CEE0C */
    R[3] = R[3] + 4095;  /* 0x800CEE14 */
L_800CEE18:;
    { R[31] = 0x800CEE20u; R[5] = (uint32_t)((int32_t)R[3] >> 12); psx_next = 0x80037B38u; return; }  /* 0x800CEE18 jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CEE2C; } }  /* 0x800CEE20 */
    R[2] = R[2] + 7;  /* 0x800CEE28 */
L_800CEE2C:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800CEE2C */
    R[4] = R[2] & 0x1FF;  /* 0x800CEE30 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 4);  /* 0x800CEE34 */
    R[3] = lh_(R[16] + 4);  /* 0x800CEE38 */
    R[2] = R[4] - R[2];  /* 0x800CEE3C */
    { uint32_t _c = ((int32_t)R[2] < 0); R[7] = R[4] + R[0]; if (_c) { goto L_800CEE50; } }  /* 0x800CEE40 */
    { R[6] = R[4] - R[3]; goto L_800CEE54; }  /* 0x800CEE48 j */
L_800CEE50:;
    R[6] = R[3] - R[4];  /* 0x800CEE50 */
L_800CEE54:;
    R[2] = R[6] << 16;  /* 0x800CEE54 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 594);  /* 0x800CEE58 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CEE5C */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x800CEE60 */
    R[3] = lh_(R[16] + 594);  /* 0x800CEE64 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CEE74; } }  /* 0x800CEE68 */
    R[6] = R[3] + R[0];  /* 0x800CEE70 */
L_800CEE74:;
    R[2] = lh_(R[16] + 4);  /* 0x800CEE74 */
    R[3] = R[2] + 256;  /* 0x800CEE7C */
    R[2] = R[2] << 16;  /* 0x800CEE80 */
    R[5] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CEE84 */
    R[2] = ((int32_t)R[5] < 256);  /* 0x800CEE88 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[3] & 0x1FF; if (_c) { goto L_800CEEC8; } }  /* 0x800CEE8C */
    R[4] = R[7] + R[0];  /* 0x800CEE94 */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800CEE98 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[3]); if (_c) { goto L_800CEEB0; } }  /* 0x800CEE9C */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[2] = R[6] << 16; if (_c) { goto L_800CEEE0; } }  /* 0x800CEEA4 */
    R[2] = ((int32_t)R[4] < (int32_t)R[3]);  /* 0x800CEEAC */
L_800CEEB0:;
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < 512); if (_c) { goto L_800CEEE8; } }  /* 0x800CEEB0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[6] << 16; if (_c) { goto L_800CEEE8; } }  /* 0x800CEEB8 */
    { R[2] = (uint32_t)((int32_t)R[2] >> 16); goto L_800CEEE4; }  /* 0x800CEEC0 j */
L_800CEEC8:;
    R[4] = R[7] + R[0];  /* 0x800CEEC8 */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800CEECC */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[3]); if (_c) { goto L_800CEEE8; } }  /* 0x800CEED0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[6] << 16; if (_c) { goto L_800CEEE8; } }  /* 0x800CEED8 */
L_800CEEE0:;
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CEEE0 */
L_800CEEE4:;
    R[6] = R[0] - R[2];  /* 0x800CEEE4 */
L_800CEEE8:;
    R[2] = lh_(R[16] + 4);  /* 0x800CEEE8 */
    R[5] = lw_(R[16] + 28);  /* 0x800CEEEC */
    R[2] = R[2] + R[6];  /* 0x800CEEF0 */
    R[2] = R[2] & 0x1FF;  /* 0x800CEEF4 */
    sh_(R[16] + 4, R[2]);  /* 0x800CEEF8 */
    sh_(R[16] + 6, R[2]);  /* 0x800CEEFC */
    R[4] = lw_(R[17] + 28);  /* 0x800CEF00 */
    { uint32_t _c = (R[5] == R[4]); R[3] = R[4] - R[5]; if (_c) { goto L_800CEF44; } }  /* 0x800CEF08 */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800CEF1C; } }  /* 0x800CEF10 */
    R[3] = R[5] - R[4];  /* 0x800CEF18 */
L_800CEF1C:;
    R[6] = lh_(R[16] + 596);  /* 0x800CEF1C */
    R[2] = ((int32_t)R[3] < (int32_t)R[6]);  /* 0x800CEF24 */
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[5]); if (_c) { goto L_800CEF34; } }  /* 0x800CEF28 */
    R[3] = R[6] + R[0];  /* 0x800CEF30 */
L_800CEF34:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CEF40; } }  /* 0x800CEF34 */
    R[3] = R[0] - R[3];  /* 0x800CEF3C */
L_800CEF40:;
    sw_(R[16] + 200, R[3]);  /* 0x800CEF40 */
L_800CEF44:;
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 594);  /* 0x800CEF44 */
    R[3] = lh_(R[16] + 594);  /* 0x800CEF48 */
    R[2] = ((int32_t)R[2] < 15);  /* 0x800CEF4C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_800CEF5C; } }  /* 0x800CEF50 */
    sh_(R[16] + 594, R[2]);  /* 0x800CEF58 */
L_800CEF5C:;
    R[3] = lh_(R[16] + 596);  /* 0x800CEF5C */
    R[2] = (R[3] < (uint32_t)16384u);  /* 0x800CEF64 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1024; if (_c) { goto L_800CEF7C; } }  /* 0x800CEF68 */
    { sh_(R[16] + 596, R[2]); goto L_800CEF7C; }  /* 0x800CEF70 j */
L_800CEF78:;
    sh_(R[16] + 592, R[2]);  /* 0x800CEF78 */
L_800CEF7C:;
    R[31] = lw_(R[29] + 24);  /* 0x800CEF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CEF80 */
    R[16] = lw_(R[29] + 16);  /* 0x800CEF84 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CEF88 jr ra */
}

void g0_800CEE20(void) {
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800CEE2C; } }  /* 0x800CEE20 */
    R[2] = R[2] + 7;  /* 0x800CEE28 */
L_800CEE2C:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800CEE2C */
    R[4] = R[2] & 0x1FF;  /* 0x800CEE30 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 4);  /* 0x800CEE34 */
    R[3] = lh_(R[16] + 4);  /* 0x800CEE38 */
    R[2] = R[4] - R[2];  /* 0x800CEE3C */
    { uint32_t _c = ((int32_t)R[2] < 0); R[7] = R[4] + R[0]; if (_c) { goto L_800CEE50; } }  /* 0x800CEE40 */
    { R[6] = R[4] - R[3]; goto L_800CEE54; }  /* 0x800CEE48 j */
L_800CEE50:;
    R[6] = R[3] - R[4];  /* 0x800CEE50 */
L_800CEE54:;
    R[2] = R[6] << 16;  /* 0x800CEE54 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 594);  /* 0x800CEE58 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CEE5C */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x800CEE60 */
    R[3] = lh_(R[16] + 594);  /* 0x800CEE64 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CEE74; } }  /* 0x800CEE68 */
    R[6] = R[3] + R[0];  /* 0x800CEE70 */
L_800CEE74:;
    R[2] = lh_(R[16] + 4);  /* 0x800CEE74 */
    R[3] = R[2] + 256;  /* 0x800CEE7C */
    R[2] = R[2] << 16;  /* 0x800CEE80 */
    R[5] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CEE84 */
    R[2] = ((int32_t)R[5] < 256);  /* 0x800CEE88 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[3] & 0x1FF; if (_c) { goto L_800CEEC8; } }  /* 0x800CEE8C */
    R[4] = R[7] + R[0];  /* 0x800CEE94 */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800CEE98 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[3]); if (_c) { goto L_800CEEB0; } }  /* 0x800CEE9C */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[2] = R[6] << 16; if (_c) { goto L_800CEEE0; } }  /* 0x800CEEA4 */
    R[2] = ((int32_t)R[4] < (int32_t)R[3]);  /* 0x800CEEAC */
L_800CEEB0:;
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < 512); if (_c) { goto L_800CEEE8; } }  /* 0x800CEEB0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[6] << 16; if (_c) { goto L_800CEEE8; } }  /* 0x800CEEB8 */
    { R[2] = (uint32_t)((int32_t)R[2] >> 16); goto L_800CEEE4; }  /* 0x800CEEC0 j */
L_800CEEC8:;
    R[4] = R[7] + R[0];  /* 0x800CEEC8 */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800CEECC */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[3]); if (_c) { goto L_800CEEE8; } }  /* 0x800CEED0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[6] << 16; if (_c) { goto L_800CEEE8; } }  /* 0x800CEED8 */
L_800CEEE0:;
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CEEE0 */
L_800CEEE4:;
    R[6] = R[0] - R[2];  /* 0x800CEEE4 */
L_800CEEE8:;
    R[2] = lh_(R[16] + 4);  /* 0x800CEEE8 */
    R[5] = lw_(R[16] + 28);  /* 0x800CEEEC */
    R[2] = R[2] + R[6];  /* 0x800CEEF0 */
    R[2] = R[2] & 0x1FF;  /* 0x800CEEF4 */
    sh_(R[16] + 4, R[2]);  /* 0x800CEEF8 */
    sh_(R[16] + 6, R[2]);  /* 0x800CEEFC */
    R[4] = lw_(R[17] + 28);  /* 0x800CEF00 */
    { uint32_t _c = (R[5] == R[4]); R[3] = R[4] - R[5]; if (_c) { goto L_800CEF44; } }  /* 0x800CEF08 */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800CEF1C; } }  /* 0x800CEF10 */
    R[3] = R[5] - R[4];  /* 0x800CEF18 */
L_800CEF1C:;
    R[6] = lh_(R[16] + 596);  /* 0x800CEF1C */
    R[2] = ((int32_t)R[3] < (int32_t)R[6]);  /* 0x800CEF24 */
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[5]); if (_c) { goto L_800CEF34; } }  /* 0x800CEF28 */
    R[3] = R[6] + R[0];  /* 0x800CEF30 */
L_800CEF34:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CEF40; } }  /* 0x800CEF34 */
    R[3] = R[0] - R[3];  /* 0x800CEF3C */
L_800CEF40:;
    sw_(R[16] + 200, R[3]);  /* 0x800CEF40 */
L_800CEF44:;
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 594);  /* 0x800CEF44 */
    R[3] = lh_(R[16] + 594);  /* 0x800CEF48 */
    R[2] = ((int32_t)R[2] < 15);  /* 0x800CEF4C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_800CEF5C; } }  /* 0x800CEF50 */
    sh_(R[16] + 594, R[2]);  /* 0x800CEF58 */
L_800CEF5C:;
    R[3] = lh_(R[16] + 596);  /* 0x800CEF5C */
    R[2] = (R[3] < (uint32_t)16384u);  /* 0x800CEF64 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1024; if (_c) { goto L_800CEF7C; } }  /* 0x800CEF68 */
    { sh_(R[16] + 596, R[2]); goto L_800CEF7C; }  /* 0x800CEF70 j */
    sh_(R[16] + 592, R[2]);  /* 0x800CEF78 */
L_800CEF7C:;
    R[31] = lw_(R[29] + 24);  /* 0x800CEF7C */
    R[17] = lw_(R[29] + 20);  /* 0x800CEF80 */
    R[16] = lw_(R[29] + 16);  /* 0x800CEF84 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800CEF88 jr ra */
}

void g0_800CEF90(void) {
    R[29] = R[29] - 56;  /* 0x800CEF90 */
    sw_(R[29] + 48, R[30]);  /* 0x800CEF94 */
    R[30] = R[4] + R[0];  /* 0x800CEF98 */
    sw_(R[29] + 36, R[21]);  /* 0x800CEF9C */
    R[21] = R[5] + R[0];  /* 0x800CEFA0 */
    sw_(R[29] + 20, R[17]);  /* 0x800CEFA4 */
    R[17] = R[6] + R[0];  /* 0x800CEFA8 */
    sw_(R[29] + 52, R[31]);  /* 0x800CEFAC */
    sw_(R[29] + 44, R[23]);  /* 0x800CEFB0 */
    sw_(R[29] + 40, R[22]);  /* 0x800CEFB4 */
    sw_(R[29] + 32, R[20]);  /* 0x800CEFB8 */
    sw_(R[29] + 28, R[19]);  /* 0x800CEFBC */
    sw_(R[29] + 24, R[18]);  /* 0x800CEFC0 */
    sw_(R[29] + 16, R[16]);  /* 0x800CEFC4 */
    R[2] = lw_(R[21] + 484);  /* 0x800CEFC8 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[22] = R[7] + R[0]; if (_c) { goto L_800CEFDC; } }  /* 0x800CEFD0 */
    R[2] = R[2] + 8191;  /* 0x800CEFD8 */
L_800CEFDC:;
    R[18] = R[0] + R[0];  /* 0x800CEFDC */
    R[19] = R[0] + R[0];  /* 0x800CEFE0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 13);  /* 0x800CEFE4 */
    { uint32_t _c = ((int32_t)R[22] <= 0); R[23] = R[2] + R[0]; if (_c) { goto L_800CF0E0; } }  /* 0x800CEFE8 */
    R[2] = R[2] << 16;  /* 0x800CEFF0 */
    R[20] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CEFF4 */
L_800CEFF8:;
    R[4] = R[17] + R[0];  /* 0x800CEFF8 */
    { R[31] = 0x800CF004u; R[5] = R[0] + 16; psx_next = 0x800BDFDCu; return; }  /* 0x800CEFFC jal */
    R[17] = R[2] + R[0];  /* 0x800CF004 */
    { uint32_t _c = (R[17] == R[0]); R[5] = R[17] + R[0]; if (_c) { goto L_800CF0E0; } }  /* 0x800CF008 */
    R[4] = R[0] + R[0];  /* 0x800CF010 */
    R[6] = R[30] + R[0];  /* 0x800CF014 */
    { R[31] = 0x800CF020u; R[7] = R[21] + 24; psx_next = 0x800A5964u; return; }  /* 0x800CF018 jal */
    R[2] = R[0] + 16;  /* 0x800CF020 */
    sb_(R[17] + 3, R[2]);  /* 0x800CF024 */
    R[2] = lw_(R[21] + 484);  /* 0x800CF028 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[16] = R[18] << 16; if (_c) { goto L_800CF03C; } }  /* 0x800CF030 */
    R[2] = R[2] + 4095;  /* 0x800CF038 */
L_800CF03C:;
    R[16] = (uint32_t)((int32_t)R[16] >> 16);  /* 0x800CF03C */
    R[4] = R[16] + R[0];  /* 0x800CF040 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CF044 */
    sb_(R[17] + 53, R[2]);  /* 0x800CF048 */
    { R[31] = 0x800CF054u; sb_(R[17] + 52, R[2]); psx_next = 0x80035B18u; return; }  /* 0x800CF04C jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CF054 */
    R[4] = R[16] + R[0];  /* 0x800CF058 */
    R[8] = LO;  /* 0x800CF05C */
    { R[31] = 0x800CF068u; sw_(R[17] + 20, R[8]); psx_next = 0x80035A48u; return; }  /* 0x800CF060 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CF068 */
    R[8] = LO;  /* 0x800CF06C */
    sw_(R[17] + 28, R[8]);  /* 0x800CF070 */
    R[3] = lw_(R[21] + 488);  /* 0x800CF074 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[0] + 4096; if (_c) { goto L_800CF088; } }  /* 0x800CF07C */
    R[3] = R[3] + 15;  /* 0x800CF084 */
L_800CF088:;
    psx_div((int32_t)R[4], (int32_t)R[22]);  /* 0x800CF088 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CF098; } }  /* 0x800CF08C */
    psx_break(7168);  /* 0x800CF094 */
L_800CF098:;
    R[1] = R[0] - 1;  /* 0x800CF098 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF0B0; } }  /* 0x800CF09C */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CF0B0; } }  /* 0x800CF0A4 */
    psx_break(6144);  /* 0x800CF0AC */
L_800CF0B0:;
    R[4] = LO;  /* 0x800CF0B0 */
    R[19] = R[19] + 1;  /* 0x800CF0B4 */
    R[2] = (uint32_t)((int32_t)R[3] >> 4);  /* 0x800CF0B8 */
    R[3] = lb_(R[17] + 52);  /* 0x800CF0BC */
    R[2] = R[0] - R[2];  /* 0x800CF0C0 */
    sw_(R[17] + 36, R[2]);  /* 0x800CF0C4 */
    R[2] = ((int32_t)R[19] < (int32_t)R[22]);  /* 0x800CF0C8 */
    sh_(R[17] + 66, R[18]);  /* 0x800CF0CC */
    R[3] = R[3] >> 4;  /* 0x800CF0D0 */
    sh_(R[17] + 64, R[3]);  /* 0x800CF0D4 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + R[4]; if (_c) { psx_bb(); goto L_800CEFF8; } }  /* 0x800CF0D8 */
L_800CF0E0:;
    R[2] = R[23] << 16;  /* 0x800CF0E0 */
    R[31] = lw_(R[29] + 52);  /* 0x800CF0E4 */
    R[30] = lw_(R[29] + 48);  /* 0x800CF0E8 */
    R[23] = lw_(R[29] + 44);  /* 0x800CF0EC */
    R[22] = lw_(R[29] + 40);  /* 0x800CF0F0 */
    R[21] = lw_(R[29] + 36);  /* 0x800CF0F4 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF0F8 */
    R[19] = lw_(R[29] + 28);  /* 0x800CF0FC */
    R[18] = lw_(R[29] + 24);  /* 0x800CF100 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF104 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF108 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF10C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CF110 jr ra */
}

void g0_800CEFF8(void) {
L_800CEFF8:;
    R[4] = R[17] + R[0];  /* 0x800CEFF8 */
    { R[31] = 0x800CF004u; R[5] = R[0] + 16; psx_next = 0x800BDFDCu; return; }  /* 0x800CEFFC jal */
    R[17] = R[2] + R[0];  /* 0x800CF004 */
    { uint32_t _c = (R[17] == R[0]); R[5] = R[17] + R[0]; if (_c) { goto L_800CF0E0; } }  /* 0x800CF008 */
    R[4] = R[0] + R[0];  /* 0x800CF010 */
    R[6] = R[30] + R[0];  /* 0x800CF014 */
    { R[31] = 0x800CF020u; R[7] = R[21] + 24; psx_next = 0x800A5964u; return; }  /* 0x800CF018 jal */
    R[2] = R[0] + 16;  /* 0x800CF020 */
    sb_(R[17] + 3, R[2]);  /* 0x800CF024 */
    R[2] = lw_(R[21] + 484);  /* 0x800CF028 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[16] = R[18] << 16; if (_c) { goto L_800CF03C; } }  /* 0x800CF030 */
    R[2] = R[2] + 4095;  /* 0x800CF038 */
L_800CF03C:;
    R[16] = (uint32_t)((int32_t)R[16] >> 16);  /* 0x800CF03C */
    R[4] = R[16] + R[0];  /* 0x800CF040 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CF044 */
    sb_(R[17] + 53, R[2]);  /* 0x800CF048 */
    { R[31] = 0x800CF054u; sb_(R[17] + 52, R[2]); psx_next = 0x80035B18u; return; }  /* 0x800CF04C jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CF054 */
    R[4] = R[16] + R[0];  /* 0x800CF058 */
    R[8] = LO;  /* 0x800CF05C */
    { R[31] = 0x800CF068u; sw_(R[17] + 20, R[8]); psx_next = 0x80035A48u; return; }  /* 0x800CF060 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CF068 */
    R[8] = LO;  /* 0x800CF06C */
    sw_(R[17] + 28, R[8]);  /* 0x800CF070 */
    R[3] = lw_(R[21] + 488);  /* 0x800CF074 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[0] + 4096; if (_c) { goto L_800CF088; } }  /* 0x800CF07C */
    R[3] = R[3] + 15;  /* 0x800CF084 */
L_800CF088:;
    psx_div((int32_t)R[4], (int32_t)R[22]);  /* 0x800CF088 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CF098; } }  /* 0x800CF08C */
    psx_break(7168);  /* 0x800CF094 */
L_800CF098:;
    R[1] = R[0] - 1;  /* 0x800CF098 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF0B0; } }  /* 0x800CF09C */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CF0B0; } }  /* 0x800CF0A4 */
    psx_break(6144);  /* 0x800CF0AC */
L_800CF0B0:;
    R[4] = LO;  /* 0x800CF0B0 */
    R[19] = R[19] + 1;  /* 0x800CF0B4 */
    R[2] = (uint32_t)((int32_t)R[3] >> 4);  /* 0x800CF0B8 */
    R[3] = lb_(R[17] + 52);  /* 0x800CF0BC */
    R[2] = R[0] - R[2];  /* 0x800CF0C0 */
    sw_(R[17] + 36, R[2]);  /* 0x800CF0C4 */
    R[2] = ((int32_t)R[19] < (int32_t)R[22]);  /* 0x800CF0C8 */
    sh_(R[17] + 66, R[18]);  /* 0x800CF0CC */
    R[3] = R[3] >> 4;  /* 0x800CF0D0 */
    sh_(R[17] + 64, R[3]);  /* 0x800CF0D4 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + R[4]; if (_c) { psx_bb(); goto L_800CEFF8; } }  /* 0x800CF0D8 */
L_800CF0E0:;
    R[2] = R[23] << 16;  /* 0x800CF0E0 */
    R[31] = lw_(R[29] + 52);  /* 0x800CF0E4 */
    R[30] = lw_(R[29] + 48);  /* 0x800CF0E8 */
    R[23] = lw_(R[29] + 44);  /* 0x800CF0EC */
    R[22] = lw_(R[29] + 40);  /* 0x800CF0F0 */
    R[21] = lw_(R[29] + 36);  /* 0x800CF0F4 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF0F8 */
    R[19] = lw_(R[29] + 28);  /* 0x800CF0FC */
    R[18] = lw_(R[29] + 24);  /* 0x800CF100 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF104 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF108 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF10C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CF110 jr ra */
}

void g0_800CF004(void) {
    R[17] = R[2] + R[0];  /* 0x800CF004 */
    { uint32_t _c = (R[17] == R[0]); R[5] = R[17] + R[0]; if (_c) { goto L_800CF0E0; } }  /* 0x800CF008 */
    R[4] = R[0] + R[0];  /* 0x800CF010 */
    R[6] = R[30] + R[0];  /* 0x800CF014 */
    { R[31] = 0x800CF020u; R[7] = R[21] + 24; psx_next = 0x800A5964u; return; }  /* 0x800CF018 jal */
    R[2] = R[0] + 16;  /* 0x800CF020 */
    sb_(R[17] + 3, R[2]);  /* 0x800CF024 */
    R[2] = lw_(R[21] + 484);  /* 0x800CF028 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[16] = R[18] << 16; if (_c) { goto L_800CF03C; } }  /* 0x800CF030 */
    R[2] = R[2] + 4095;  /* 0x800CF038 */
L_800CF03C:;
    R[16] = (uint32_t)((int32_t)R[16] >> 16);  /* 0x800CF03C */
    R[4] = R[16] + R[0];  /* 0x800CF040 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CF044 */
    sb_(R[17] + 53, R[2]);  /* 0x800CF048 */
    { R[31] = 0x800CF054u; sb_(R[17] + 52, R[2]); psx_next = 0x80035B18u; return; }  /* 0x800CF04C jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CF054 */
    R[4] = R[16] + R[0];  /* 0x800CF058 */
    R[8] = LO;  /* 0x800CF05C */
    { R[31] = 0x800CF068u; sw_(R[17] + 20, R[8]); psx_next = 0x80035A48u; return; }  /* 0x800CF060 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CF068 */
    R[8] = LO;  /* 0x800CF06C */
    sw_(R[17] + 28, R[8]);  /* 0x800CF070 */
    R[3] = lw_(R[21] + 488);  /* 0x800CF074 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[0] + 4096; if (_c) { goto L_800CF088; } }  /* 0x800CF07C */
    R[3] = R[3] + 15;  /* 0x800CF084 */
L_800CF088:;
    psx_div((int32_t)R[4], (int32_t)R[22]);  /* 0x800CF088 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CF098; } }  /* 0x800CF08C */
    psx_break(7168);  /* 0x800CF094 */
L_800CF098:;
    R[1] = R[0] - 1;  /* 0x800CF098 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF0B0; } }  /* 0x800CF09C */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CF0B0; } }  /* 0x800CF0A4 */
    psx_break(6144);  /* 0x800CF0AC */
L_800CF0B0:;
    R[4] = LO;  /* 0x800CF0B0 */
    R[19] = R[19] + 1;  /* 0x800CF0B4 */
    R[2] = (uint32_t)((int32_t)R[3] >> 4);  /* 0x800CF0B8 */
    R[3] = lb_(R[17] + 52);  /* 0x800CF0BC */
    R[2] = R[0] - R[2];  /* 0x800CF0C0 */
    sw_(R[17] + 36, R[2]);  /* 0x800CF0C4 */
    R[2] = ((int32_t)R[19] < (int32_t)R[22]);  /* 0x800CF0C8 */
    sh_(R[17] + 66, R[18]);  /* 0x800CF0CC */
    R[3] = R[3] >> 4;  /* 0x800CF0D0 */
    sh_(R[17] + 64, R[3]);  /* 0x800CF0D4 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + R[4]; if (_c) { psx_next = 0x800CEFF8u; return; } }  /* 0x800CF0D8 b extern */
L_800CF0E0:;
    R[2] = R[23] << 16;  /* 0x800CF0E0 */
    R[31] = lw_(R[29] + 52);  /* 0x800CF0E4 */
    R[30] = lw_(R[29] + 48);  /* 0x800CF0E8 */
    R[23] = lw_(R[29] + 44);  /* 0x800CF0EC */
    R[22] = lw_(R[29] + 40);  /* 0x800CF0F0 */
    R[21] = lw_(R[29] + 36);  /* 0x800CF0F4 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF0F8 */
    R[19] = lw_(R[29] + 28);  /* 0x800CF0FC */
    R[18] = lw_(R[29] + 24);  /* 0x800CF100 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF104 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF108 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF10C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CF110 jr ra */
}

void g0_800CF020(void) {
    R[2] = R[0] + 16;  /* 0x800CF020 */
    sb_(R[17] + 3, R[2]);  /* 0x800CF024 */
    R[2] = lw_(R[21] + 484);  /* 0x800CF028 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[16] = R[18] << 16; if (_c) { goto L_800CF03C; } }  /* 0x800CF030 */
    R[2] = R[2] + 4095;  /* 0x800CF038 */
L_800CF03C:;
    R[16] = (uint32_t)((int32_t)R[16] >> 16);  /* 0x800CF03C */
    R[4] = R[16] + R[0];  /* 0x800CF040 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800CF044 */
    sb_(R[17] + 53, R[2]);  /* 0x800CF048 */
    { R[31] = 0x800CF054u; sb_(R[17] + 52, R[2]); psx_next = 0x80035B18u; return; }  /* 0x800CF04C jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CF054 */
    R[4] = R[16] + R[0];  /* 0x800CF058 */
    R[8] = LO;  /* 0x800CF05C */
    { R[31] = 0x800CF068u; sw_(R[17] + 20, R[8]); psx_next = 0x80035A48u; return; }  /* 0x800CF060 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CF068 */
    R[8] = LO;  /* 0x800CF06C */
    sw_(R[17] + 28, R[8]);  /* 0x800CF070 */
    R[3] = lw_(R[21] + 488);  /* 0x800CF074 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[0] + 4096; if (_c) { goto L_800CF088; } }  /* 0x800CF07C */
    R[3] = R[3] + 15;  /* 0x800CF084 */
L_800CF088:;
    psx_div((int32_t)R[4], (int32_t)R[22]);  /* 0x800CF088 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CF098; } }  /* 0x800CF08C */
    psx_break(7168);  /* 0x800CF094 */
L_800CF098:;
    R[1] = R[0] - 1;  /* 0x800CF098 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF0B0; } }  /* 0x800CF09C */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CF0B0; } }  /* 0x800CF0A4 */
    psx_break(6144);  /* 0x800CF0AC */
L_800CF0B0:;
    R[4] = LO;  /* 0x800CF0B0 */
    R[19] = R[19] + 1;  /* 0x800CF0B4 */
    R[2] = (uint32_t)((int32_t)R[3] >> 4);  /* 0x800CF0B8 */
    R[3] = lb_(R[17] + 52);  /* 0x800CF0BC */
    R[2] = R[0] - R[2];  /* 0x800CF0C0 */
    sw_(R[17] + 36, R[2]);  /* 0x800CF0C4 */
    R[2] = ((int32_t)R[19] < (int32_t)R[22]);  /* 0x800CF0C8 */
    sh_(R[17] + 66, R[18]);  /* 0x800CF0CC */
    R[3] = R[3] >> 4;  /* 0x800CF0D0 */
    sh_(R[17] + 64, R[3]);  /* 0x800CF0D4 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + R[4]; if (_c) { psx_next = 0x800CEFF8u; return; } }  /* 0x800CF0D8 b extern */
    R[2] = R[23] << 16;  /* 0x800CF0E0 */
    R[31] = lw_(R[29] + 52);  /* 0x800CF0E4 */
    R[30] = lw_(R[29] + 48);  /* 0x800CF0E8 */
    R[23] = lw_(R[29] + 44);  /* 0x800CF0EC */
    R[22] = lw_(R[29] + 40);  /* 0x800CF0F0 */
    R[21] = lw_(R[29] + 36);  /* 0x800CF0F4 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF0F8 */
    R[19] = lw_(R[29] + 28);  /* 0x800CF0FC */
    R[18] = lw_(R[29] + 24);  /* 0x800CF100 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF104 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF108 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF10C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CF110 jr ra */
}

void g0_800CF054(void) {
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CF054 */
    R[4] = R[16] + R[0];  /* 0x800CF058 */
    R[8] = LO;  /* 0x800CF05C */
    { R[31] = 0x800CF068u; sw_(R[17] + 20, R[8]); psx_next = 0x80035A48u; return; }  /* 0x800CF060 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CF068 */
    R[8] = LO;  /* 0x800CF06C */
    sw_(R[17] + 28, R[8]);  /* 0x800CF070 */
    R[3] = lw_(R[21] + 488);  /* 0x800CF074 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[0] + 4096; if (_c) { goto L_800CF088; } }  /* 0x800CF07C */
    R[3] = R[3] + 15;  /* 0x800CF084 */
L_800CF088:;
    psx_div((int32_t)R[4], (int32_t)R[22]);  /* 0x800CF088 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CF098; } }  /* 0x800CF08C */
    psx_break(7168);  /* 0x800CF094 */
L_800CF098:;
    R[1] = R[0] - 1;  /* 0x800CF098 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF0B0; } }  /* 0x800CF09C */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CF0B0; } }  /* 0x800CF0A4 */
    psx_break(6144);  /* 0x800CF0AC */
L_800CF0B0:;
    R[4] = LO;  /* 0x800CF0B0 */
    R[19] = R[19] + 1;  /* 0x800CF0B4 */
    R[2] = (uint32_t)((int32_t)R[3] >> 4);  /* 0x800CF0B8 */
    R[3] = lb_(R[17] + 52);  /* 0x800CF0BC */
    R[2] = R[0] - R[2];  /* 0x800CF0C0 */
    sw_(R[17] + 36, R[2]);  /* 0x800CF0C4 */
    R[2] = ((int32_t)R[19] < (int32_t)R[22]);  /* 0x800CF0C8 */
    sh_(R[17] + 66, R[18]);  /* 0x800CF0CC */
    R[3] = R[3] >> 4;  /* 0x800CF0D0 */
    sh_(R[17] + 64, R[3]);  /* 0x800CF0D4 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + R[4]; if (_c) { psx_next = 0x800CEFF8u; return; } }  /* 0x800CF0D8 b extern */
    R[2] = R[23] << 16;  /* 0x800CF0E0 */
    R[31] = lw_(R[29] + 52);  /* 0x800CF0E4 */
    R[30] = lw_(R[29] + 48);  /* 0x800CF0E8 */
    R[23] = lw_(R[29] + 44);  /* 0x800CF0EC */
    R[22] = lw_(R[29] + 40);  /* 0x800CF0F0 */
    R[21] = lw_(R[29] + 36);  /* 0x800CF0F4 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF0F8 */
    R[19] = lw_(R[29] + 28);  /* 0x800CF0FC */
    R[18] = lw_(R[29] + 24);  /* 0x800CF100 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF104 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF108 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF10C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CF110 jr ra */
}

void g0_800CF068(void) {
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CF068 */
    R[8] = LO;  /* 0x800CF06C */
    sw_(R[17] + 28, R[8]);  /* 0x800CF070 */
    R[3] = lw_(R[21] + 488);  /* 0x800CF074 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[0] + 4096; if (_c) { goto L_800CF088; } }  /* 0x800CF07C */
    R[3] = R[3] + 15;  /* 0x800CF084 */
L_800CF088:;
    psx_div((int32_t)R[4], (int32_t)R[22]);  /* 0x800CF088 */
    { uint32_t _c = (R[22] != R[0]); if (_c) { goto L_800CF098; } }  /* 0x800CF08C */
    psx_break(7168);  /* 0x800CF094 */
L_800CF098:;
    R[1] = R[0] - 1;  /* 0x800CF098 */
    { uint32_t _c = (R[22] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF0B0; } }  /* 0x800CF09C */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CF0B0; } }  /* 0x800CF0A4 */
    psx_break(6144);  /* 0x800CF0AC */
L_800CF0B0:;
    R[4] = LO;  /* 0x800CF0B0 */
    R[19] = R[19] + 1;  /* 0x800CF0B4 */
    R[2] = (uint32_t)((int32_t)R[3] >> 4);  /* 0x800CF0B8 */
    R[3] = lb_(R[17] + 52);  /* 0x800CF0BC */
    R[2] = R[0] - R[2];  /* 0x800CF0C0 */
    sw_(R[17] + 36, R[2]);  /* 0x800CF0C4 */
    R[2] = ((int32_t)R[19] < (int32_t)R[22]);  /* 0x800CF0C8 */
    sh_(R[17] + 66, R[18]);  /* 0x800CF0CC */
    R[3] = R[3] >> 4;  /* 0x800CF0D0 */
    sh_(R[17] + 64, R[3]);  /* 0x800CF0D4 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + R[4]; if (_c) { psx_next = 0x800CEFF8u; return; } }  /* 0x800CF0D8 b extern */
    R[2] = R[23] << 16;  /* 0x800CF0E0 */
    R[31] = lw_(R[29] + 52);  /* 0x800CF0E4 */
    R[30] = lw_(R[29] + 48);  /* 0x800CF0E8 */
    R[23] = lw_(R[29] + 44);  /* 0x800CF0EC */
    R[22] = lw_(R[29] + 40);  /* 0x800CF0F0 */
    R[21] = lw_(R[29] + 36);  /* 0x800CF0F4 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF0F8 */
    R[19] = lw_(R[29] + 28);  /* 0x800CF0FC */
    R[18] = lw_(R[29] + 24);  /* 0x800CF100 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF104 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF108 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF10C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CF110 jr ra */
}

void g0_800CF118(void) {
    R[29] = R[29] - 40;  /* 0x800CF118 */
    sw_(R[29] + 24, R[18]);  /* 0x800CF11C */
    R[18] = R[4] + R[0];  /* 0x800CF120 */
    sw_(R[29] + 28, R[19]);  /* 0x800CF124 */
    R[19] = R[0] + R[0];  /* 0x800CF128 */
    R[5] = R[5] << 16;  /* 0x800CF12C */
    sw_(R[29] + 32, R[20]);  /* 0x800CF130 */
    R[20] = (uint32_t)((int32_t)R[5] >> 16);  /* 0x800CF134 */
    sw_(R[29] + 20, R[17]);  /* 0x800CF138 */
    R[17] = R[18] + 28;  /* 0x800CF13C */
    sw_(R[29] + 36, R[31]);  /* 0x800CF140 */
    sw_(R[29] + 16, R[16]);  /* 0x800CF144 */
L_800CF148:;
    R[2] = lh_(R[18]);  /* 0x800CF148 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CF1B0; } }  /* 0x800CF150 */
    R[16] = lh_(R[17] + 38);  /* 0x800CF158 */
    R[2] = lb_(R[17] + 24);  /* 0x800CF15C */
    R[5] = lb_(R[17] + 36);  /* 0x800CF160 */
    R[3] = lb_(R[17] + 25);  /* 0x800CF164 */
    R[16] = R[16] + 128;  /* 0x800CF168 */
    R[16] = R[16] & 0xFFF;  /* 0x800CF16C */
    R[4] = R[16] + R[0];  /* 0x800CF170 */
    R[6] = R[5] + R[0];  /* 0x800CF174 */
    R[2] = R[2] - R[5];  /* 0x800CF178 */
    R[3] = R[3] - R[6];  /* 0x800CF17C */
    sb_(R[17] + 24, R[2]);  /* 0x800CF180 */
    sb_(R[17] + 25, R[3]);  /* 0x800CF184 */
    { R[31] = 0x800CF190u; sh_(R[17] + 38, R[16]); psx_next = 0x80035B18u; return; }  /* 0x800CF188 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CF190 */
    R[4] = R[16] + R[0];  /* 0x800CF194 */
    R[7] = LO;  /* 0x800CF198 */
    { R[31] = 0x800CF1A4u; sw_(R[17] + -8, R[7]); psx_next = 0x80035A48u; return; }  /* 0x800CF19C jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CF1A4 */
    R[7] = LO;  /* 0x800CF1A8 */
    sw_(R[17], R[7]);  /* 0x800CF1AC */
L_800CF1B0:;
    R[17] = R[17] + 72;  /* 0x800CF1B0 */
    R[19] = R[19] + 1;  /* 0x800CF1B4 */
    R[2] = ((int32_t)R[19] < 16);  /* 0x800CF1B8 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_bb(); goto L_800CF148; } }  /* 0x800CF1BC */
    R[31] = lw_(R[29] + 36);  /* 0x800CF1C4 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF1C8 */
    R[19] = lw_(R[29] + 28);  /* 0x800CF1CC */
    R[18] = lw_(R[29] + 24);  /* 0x800CF1D0 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF1D4 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF1D8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF1DC jr ra */
}

void g0_800CF148(void) {
L_800CF148:;
    R[2] = lh_(R[18]);  /* 0x800CF148 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CF1B0; } }  /* 0x800CF150 */
    R[16] = lh_(R[17] + 38);  /* 0x800CF158 */
    R[2] = lb_(R[17] + 24);  /* 0x800CF15C */
    R[5] = lb_(R[17] + 36);  /* 0x800CF160 */
    R[3] = lb_(R[17] + 25);  /* 0x800CF164 */
    R[16] = R[16] + 128;  /* 0x800CF168 */
    R[16] = R[16] & 0xFFF;  /* 0x800CF16C */
    R[4] = R[16] + R[0];  /* 0x800CF170 */
    R[6] = R[5] + R[0];  /* 0x800CF174 */
    R[2] = R[2] - R[5];  /* 0x800CF178 */
    R[3] = R[3] - R[6];  /* 0x800CF17C */
    sb_(R[17] + 24, R[2]);  /* 0x800CF180 */
    sb_(R[17] + 25, R[3]);  /* 0x800CF184 */
    { R[31] = 0x800CF190u; sh_(R[17] + 38, R[16]); psx_next = 0x80035B18u; return; }  /* 0x800CF188 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CF190 */
    R[4] = R[16] + R[0];  /* 0x800CF194 */
    R[7] = LO;  /* 0x800CF198 */
    { R[31] = 0x800CF1A4u; sw_(R[17] + -8, R[7]); psx_next = 0x80035A48u; return; }  /* 0x800CF19C jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CF1A4 */
    R[7] = LO;  /* 0x800CF1A8 */
    sw_(R[17], R[7]);  /* 0x800CF1AC */
L_800CF1B0:;
    R[17] = R[17] + 72;  /* 0x800CF1B0 */
    R[19] = R[19] + 1;  /* 0x800CF1B4 */
    R[2] = ((int32_t)R[19] < 16);  /* 0x800CF1B8 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_bb(); goto L_800CF148; } }  /* 0x800CF1BC */
    R[31] = lw_(R[29] + 36);  /* 0x800CF1C4 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF1C8 */
    R[19] = lw_(R[29] + 28);  /* 0x800CF1CC */
    R[18] = lw_(R[29] + 24);  /* 0x800CF1D0 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF1D4 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF1D8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF1DC jr ra */
}

void g0_800CF190(void) {
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CF190 */
    R[4] = R[16] + R[0];  /* 0x800CF194 */
    R[7] = LO;  /* 0x800CF198 */
    { R[31] = 0x800CF1A4u; sw_(R[17] + -8, R[7]); psx_next = 0x80035A48u; return; }  /* 0x800CF19C jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CF1A4 */
    R[7] = LO;  /* 0x800CF1A8 */
    sw_(R[17], R[7]);  /* 0x800CF1AC */
    R[17] = R[17] + 72;  /* 0x800CF1B0 */
    R[19] = R[19] + 1;  /* 0x800CF1B4 */
    R[2] = ((int32_t)R[19] < 16);  /* 0x800CF1B8 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_next = 0x800CF148u; return; } }  /* 0x800CF1BC b extern */
    R[31] = lw_(R[29] + 36);  /* 0x800CF1C4 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF1C8 */
    R[19] = lw_(R[29] + 28);  /* 0x800CF1CC */
    R[18] = lw_(R[29] + 24);  /* 0x800CF1D0 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF1D4 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF1D8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF1DC jr ra */
}

void g0_800CF1A4(void) {
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800CF1A4 */
    R[7] = LO;  /* 0x800CF1A8 */
    sw_(R[17], R[7]);  /* 0x800CF1AC */
    R[17] = R[17] + 72;  /* 0x800CF1B0 */
    R[19] = R[19] + 1;  /* 0x800CF1B4 */
    R[2] = ((int32_t)R[19] < 16);  /* 0x800CF1B8 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 72; if (_c) { psx_next = 0x800CF148u; return; } }  /* 0x800CF1BC b extern */
    R[31] = lw_(R[29] + 36);  /* 0x800CF1C4 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF1C8 */
    R[19] = lw_(R[29] + 28);  /* 0x800CF1CC */
    R[18] = lw_(R[29] + 24);  /* 0x800CF1D0 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF1D4 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF1D8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF1DC jr ra */
}

void g0_800CF1E4(void) {
    R[29] = R[29] - 40;  /* 0x800CF1E4 */
    sw_(R[29] + 20, R[17]);  /* 0x800CF1E8 */
    R[17] = R[4] + R[0];  /* 0x800CF1EC */
    sw_(R[29] + 36, R[31]);  /* 0x800CF1F0 */
    sw_(R[29] + 32, R[20]);  /* 0x800CF1F4 */
    sw_(R[29] + 28, R[19]);  /* 0x800CF1F8 */
    sw_(R[29] + 24, R[18]);  /* 0x800CF1FC */
    sw_(R[29] + 16, R[16]);  /* 0x800CF200 */
    R[2] = lh_(R[17] + 2);  /* 0x800CF204 */
    R[16] = R[0] + 2;  /* 0x800CF208 */
    R[3] = R[2] << 3;  /* 0x800CF20C */
    R[3] = R[3] + R[2];  /* 0x800CF210 */
    R[3] = R[3] << 3;  /* 0x800CF214 */
    R[2] = 0x8013u << 16;  /* 0x800CF218 */
    R[2] = R[2] - 23304;  /* 0x800CF21C */
    { uint32_t _c = (R[5] == R[16]); R[18] = R[3] + R[2]; if (_c) { goto L_800CF6E8; } }  /* 0x800CF220 */
    R[2] = ((int32_t)R[5] < 3);  /* 0x800CF228 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CF244; } }  /* 0x800CF22C */
    { uint32_t _c = (R[5] == R[0]); R[20] = R[0] + 1; if (_c) { goto L_800CF2E0; } }  /* 0x800CF234 */
    { goto L_800CF798; }  /* 0x800CF23C j */
L_800CF244:;
    R[2] = R[0] + 5;  /* 0x800CF244 */
    { uint32_t _c = (R[5] != R[2]); R[5] = R[18] + R[0]; if (_c) { goto L_800CF798; } }  /* 0x800CF248 */
    R[4] = R[0] + R[0];  /* 0x800CF250 */
    R[16] = 0x800Fu << 16;  /* 0x800CF254 */
    R[16] = R[16] - 220;  /* 0x800CF258 */
    R[6] = R[16] + R[0];  /* 0x800CF25C */
    R[7] = R[17] + 24;  /* 0x800CF260 */
    R[2] = R[0] + 1;  /* 0x800CF264 */
    sb_(R[17] + 688, R[2]);  /* 0x800CF268 */
    { R[31] = 0x800CF274u; sb_(R[17] + 690, R[2]); psx_next = 0x800A5964u; return; }  /* 0x800CF26C jal */
    R[4] = R[17] + R[0];  /* 0x800CF274 */
    R[5] = R[16] + R[0];  /* 0x800CF278 */
    R[2] = R[0] + 50;  /* 0x800CF27C */
    sb_(R[18] + 52, R[2]);  /* 0x800CF280 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF284 */
    R[2] = 0x800Bu << 16;  /* 0x800CF288 */
    R[2] = R[2] - 8012;  /* 0x800CF28C */
    sw_(R[17] + 232, R[2]);  /* 0x800CF290 */
    R[2] = 0x800Fu << 16;  /* 0x800CF294 */
    R[2] = R[2] - 496;  /* 0x800CF298 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF29C */
    R[2] = R[0] + 6400;  /* 0x800CF2A0 */
    sw_(R[17] + 124, R[2]);  /* 0x800CF2A4 */
    R[2] = R[0] + 40;  /* 0x800CF2A8 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF2AC */
    R[2] = R[0] | 0xA000;  /* 0x800CF2B0 */
    sw_(R[17] + 600, R[2]);  /* 0x800CF2B4 */
    R[2] = 0x32u << 16;  /* 0x800CF2B8 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF2BC */
    { R[31] = 0x800CF2C8u; sh_(R[17] + 586, R[0]); psx_next = 0x800CDBDCu; return; }  /* 0x800CF2C0 jal */
    R[4] = R[17] + R[0];  /* 0x800CF2C8 */
    R[5] = 0x800Fu << 16;  /* 0x800CF2CC */
    { R[31] = 0x800CF2D8u; R[5] = R[5] - 396; psx_next = 0x800CD894u; return; }  /* 0x800CF2D0 jal */
    { goto L_800CF798; }  /* 0x800CF2D8 j */
L_800CF2E0:;
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 586);  /* 0x800CF2E0 */
    { uint32_t _c = (R[3] == R[20]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_800CF5A0; } }  /* 0x800CF2E8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CF308; } }  /* 0x800CF2F0 */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_800CF318; } }  /* 0x800CF2F8 */
    { goto L_800CF798; }  /* 0x800CF300 j */
L_800CF308:;
    { uint32_t _c = (R[3] == R[16]); if (_c) { goto L_800CF6C4; } }  /* 0x800CF308 */
    { goto L_800CF798; }  /* 0x800CF310 j */
L_800CF318:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF318 */
    R[2] = R[2] - 1;  /* 0x800CF320 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF324 */
    R[2] = R[2] << 16;  /* 0x800CF328 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[16] = R[0] + 8; if (_c) { goto L_800CF3B4; } }  /* 0x800CF32C */
    R[4] = R[0] - 128;  /* 0x800CF334 */
    psx_div((int32_t)R[4], (int32_t)R[16]);  /* 0x800CF338 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CF348; } }  /* 0x800CF33C */
    psx_break(7168);  /* 0x800CF344 */
L_800CF348:;
    R[1] = R[0] - 1;  /* 0x800CF348 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF360; } }  /* 0x800CF34C */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CF360; } }  /* 0x800CF354 */
    psx_break(6144);  /* 0x800CF35C */
L_800CF360:;
    R[4] = LO;  /* 0x800CF360 */
    R[3] = lw_(R[17] + 604);  /* 0x800CF364 */
    psx_div((int32_t)R[3], (int32_t)R[16]);  /* 0x800CF36C */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CF37C; } }  /* 0x800CF370 */
    psx_break(7168);  /* 0x800CF378 */
L_800CF37C:;
    R[1] = R[0] - 1;  /* 0x800CF37C */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF394; } }  /* 0x800CF380 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CF394; } }  /* 0x800CF388 */
    psx_break(6144);  /* 0x800CF390 */
L_800CF394:;
    R[3] = LO;  /* 0x800CF394 */
    sb_(R[17] + 584, R[0]);  /* 0x800CF398 */
    sh_(R[17] + 582, R[16]);  /* 0x800CF39C */
    R[2] = R[0] + 4;  /* 0x800CF3A0 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF3A4 */
    sh_(R[17] + 592, R[4]);  /* 0x800CF3A8 */
    { sw_(R[17] + 600, R[3]); goto L_800CF798; }  /* 0x800CF3AC j */
L_800CF3B4:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 218);  /* 0x800CF3B4 */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[5] = R[0] + 16; if (_c) { goto L_800CF50C; } }  /* 0x800CF3BC */
    R[2] = lb_(R[17] + 585);  /* 0x800CF3C4 */
    R[3] = R[2] << 3;  /* 0x800CF3CC */
    R[3] = R[3] + R[2];  /* 0x800CF3D0 */
    R[3] = R[3] << 7;  /* 0x800CF3D4 */
    R[2] = 0x8014u << 16;  /* 0x800CF3D8 */
    R[2] = R[2] + 15160;  /* 0x800CF3DC */
    R[18] = R[3] + R[2];  /* 0x800CF3E0 */
    { R[31] = 0x800CF3ECu; R[4] = R[18] + R[0]; psx_next = 0x800CD6CCu; return; }  /* 0x800CF3E4 jal */
    R[4] = R[17] + R[0];  /* 0x800CF3EC */
    R[5] = R[0] + 1;  /* 0x800CF3F0 */
    R[2] = 0x8014u << 16;  /* 0x800CF3F4 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF3F8 */
    R[2] = R[2] + 15136;  /* 0x800CF3FC */
    R[3] = R[3] << 2;  /* 0x800CF400 */
    R[16] = R[3] + R[2];  /* 0x800CF404 */
    { R[31] = 0x800CF410u; R[6] = R[16] + R[0]; psx_next = 0x800CE504u; return; }  /* 0x800CF408 jal */
    R[19] = R[2] + R[0];  /* 0x800CF410 */
    { uint32_t _c = ((int32_t)R[19] <= 0); if (_c) { goto L_800CF51C; } }  /* 0x800CF414 */
    { R[31] = 0x800CF424u; R[4] = R[0] + 56; psx_next = 0x8002DB10u; return; }  /* 0x800CF41C jal */
    sb_(R[17] + 584, R[20]);  /* 0x800CF424 */
    sw_(R[17] + 124, R[0]);  /* 0x800CF428 */
    sw_(R[17] + 188, R[0]);  /* 0x800CF42C */
    R[2] = lw_(R[16]);  /* 0x800CF430 */
    R[2] = lw_(R[2] + 24);  /* 0x800CF438 */
    sw_(R[17] + 24, R[2]);  /* 0x800CF440 */
    R[2] = lw_(R[16]);  /* 0x800CF444 */
    R[2] = lw_(R[2] + 28);  /* 0x800CF44C */
    sw_(R[17] + 28, R[2]);  /* 0x800CF454 */
    R[2] = lw_(R[16]);  /* 0x800CF458 */
    R[6] = lb_(R[17] + 585);  /* 0x800CF45C */
    R[2] = lw_(R[2] + 32);  /* 0x800CF460 */
    R[5] = 0x800Fu << 16;  /* 0x800CF464 */
    sw_(R[17] + 32, R[2]);  /* 0x800CF468 */
    R[4] = lw_(R[16]);  /* 0x800CF46C */
    { R[31] = 0x800CF478u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CF470 jal */
    R[4] = 0x800Fu << 16;  /* 0x800CF478 */
    R[4] = R[4] - 220;  /* 0x800CF47C */
    R[6] = R[18] + R[0];  /* 0x800CF480 */
    R[5] = lw_(R[16]);  /* 0x800CF484 */
    { R[31] = 0x800CF490u; R[7] = R[0] + 2; psx_next = 0x800CEF90u; return; }  /* 0x800CF488 jal */
    sh_(R[17] + 594, R[2]);  /* 0x800CF490 */
    R[3] = lw_(R[16]);  /* 0x800CF494 */
    R[4] = R[0] + 16;  /* 0x800CF498 */
    R[2] = lb_(R[3] + 789);  /* 0x800CF49C */
    R[6] = 0x8011u << 16;  /* 0x800CF4A0 */
    R[2] = R[2] | 0x2;  /* 0x800CF4A4 */
    sb_(R[3] + 789, R[2]);  /* 0x800CF4A8 */
    R[5] = lw_(R[16]);  /* 0x800CF4AC */
    { R[31] = 0x800CF4B8u; R[6] = R[6] + 30196; psx_next = 0x800AC93Cu; return; }  /* 0x800CF4B0 jal */
    R[4] = lw_(R[16]);  /* 0x800CF4B8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CF4C0 */
    R[3] = R[0] - 897;  /* 0x800CF4C4 */
    R[2] = R[2] & R[3];  /* 0x800CF4C8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CF4CC */
    R[3] = lw_(R[16]);  /* 0x800CF4D0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CF4D8 */
    R[2] = R[2] | 0x180;  /* 0x800CF4E0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CF4E4 */
    R[2] = R[0] + 15;  /* 0x800CF4E8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CF4EC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF4F0 */
    R[2] = lw_(R[16]);  /* 0x800CF4F4 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF4F8 */
    sw_(R[17] + 608, R[19]);  /* 0x800CF4FC */
    sh_(R[17] + 586, R[20]);  /* 0x800CF500 */
    { sw_(R[17] + 588, R[2]); goto L_800CF548; }  /* 0x800CF504 j */
L_800CF50C:;
    R[2] = lb_(R[17] + 785);  /* 0x800CF50C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800CF554; } }  /* 0x800CF514 */
L_800CF51C:;
    R[16] = R[0] + 8;  /* 0x800CF51C */
    R[4] = R[17] + R[0];  /* 0x800CF520 */
    R[5] = 0x800Fu << 16;  /* 0x800CF524 */
    R[5] = R[5] - 220;  /* 0x800CF528 */
    R[6] = R[16] + R[0];  /* 0x800CF52C */
    R[2] = R[0] + 2;  /* 0x800CF530 */
    { R[31] = 0x800CF53Cu; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CF534 jal */
    R[2] = R[0] + 4;  /* 0x800CF53C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF540 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF544 */
L_800CF548:;
    R[2] = R[0] + 3;  /* 0x800CF548 */
    { sb_(R[17] + 786, R[2]); goto L_800CF798; }  /* 0x800CF54C j */
L_800CF554:;
    R[2] = R[0] + 8;  /* 0x800CF554 */
    sb_(R[18] + 3, R[2]);  /* 0x800CF558 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF55C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF560 */
    R[5] = R[0] + 5;  /* 0x800CF564 */
    R[2] = R[2] - R[3];  /* 0x800CF568 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF56C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF570 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF574 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF578 */
    R[6] = R[0] | 0xA000;  /* 0x800CF57C */
    { R[31] = 0x800CF588u; sb_(R[18] + 53, R[2]); psx_next = 0x800CE35Cu; return; }  /* 0x800CF580 jal */
    { R[31] = 0x800CF590u; R[4] = R[17] + R[0]; psx_next = 0x800CDCACu; return; }  /* 0x800CF588 jal */
    { R[31] = 0x800CF598u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CF590 jal */
    { goto L_800CF798; }  /* 0x800CF598 j */
L_800CF5A0:;
    R[5] = R[0] + 1;  /* 0x800CF5A0 */
    R[6] = R[5] + R[0];  /* 0x800CF5A4 */
    R[2] = 0x8014u << 16;  /* 0x800CF5A8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5AC */
    R[18] = R[2] + 15136;  /* 0x800CF5B0 */
    R[4] = R[4] << 2;  /* 0x800CF5B4 */
    { R[31] = 0x800CF5C0u; R[4] = R[4] + R[18]; psx_next = 0x800CCF94u; return; }  /* 0x800CF5B8 jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CF5CC; } }  /* 0x800CF5C0 */
    sh_(R[17] + 582, R[0]);  /* 0x800CF5C8 */
L_800CF5CC:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF5CC */
    R[2] = R[2] - 1;  /* 0x800CF5D4 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF5D8 */
    R[2] = R[2] << 16;  /* 0x800CF5DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF5E0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[2] = ((int32_t)R[2] < 9); if (_c) { goto L_800CF630; } }  /* 0x800CF5E4 */
    R[5] = R[0] + 1;  /* 0x800CF5EC */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5F0 */
    R[6] = R[5] + R[0];  /* 0x800CF5F4 */
    R[4] = R[4] << 2;  /* 0x800CF5F8 */
    { R[31] = 0x800CF604u; R[4] = R[4] + R[18]; psx_next = 0x800CD028u; return; }  /* 0x800CF5FC jal */
    R[2] = 0x800Fu << 16;  /* 0x800CF604 */
    R[3] = lw_(R[17] + 588);  /* 0x800CF608 */
    R[2] = R[2] - 416;  /* 0x800CF60C */
    sw_(R[17] + 608, R[0]);  /* 0x800CF610 */
    sh_(R[17] + 14, R[0]);  /* 0x800CF614 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF618 */
    R[2] = lb_(R[3] + 2);  /* 0x800CF61C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF620 */
    sh_(R[17] + 586, R[16]);  /* 0x800CF624 */
    { sb_(R[17] + 801, R[2]); goto L_800CF68C; }  /* 0x800CF628 j */
L_800CF630:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF68C; } }  /* 0x800CF630 */
    R[2] = lh_(R[17] + 592);  /* 0x800CF638 */
    R[2] = R[2] + 1;  /* 0x800CF640 */
    sh_(R[17] + 592, R[2]);  /* 0x800CF644 */
    R[2] = R[2] << 16;  /* 0x800CF648 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF64C */
    R[2] = ((int32_t)R[2] < 2);  /* 0x800CF650 */
    { uint32_t _c = (R[2] != R[0]); R[7] = R[0] + 2; if (_c) { goto L_800CF68C; } }  /* 0x800CF654 */
    R[4] = 0x800Fu << 16;  /* 0x800CF65C */
    R[4] = R[4] - 220;  /* 0x800CF660 */
    R[6] = 0x8014u << 16;  /* 0x800CF664 */
    R[5] = lw_(R[17] + 588);  /* 0x800CF668 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF66C */
    R[6] = R[6] + 15160;  /* 0x800CF670 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF674 */
    R[2] = R[3] << 3;  /* 0x800CF678 */
    R[2] = R[2] + R[3];  /* 0x800CF67C */
    R[2] = R[2] << 7;  /* 0x800CF680 */
    { R[31] = 0x800CF68Cu; R[6] = R[2] + R[6]; psx_next = 0x800CEF90u; return; }  /* 0x800CF684 jal */
L_800CF68C:;
    R[5] = lw_(R[17] + 588);  /* 0x800CF68C */
    { R[31] = 0x800CF698u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CF690 jal */
    R[4] = 0x8014u << 16;  /* 0x800CF698 */
    R[4] = R[4] + 15160;  /* 0x800CF69C */
    R[3] = lb_(R[17] + 585);  /* 0x800CF6A0 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 594);  /* 0x800CF6A4 */
    R[2] = R[3] << 3;  /* 0x800CF6A8 */
    R[2] = R[2] + R[3];  /* 0x800CF6AC */
    R[2] = R[2] << 7;  /* 0x800CF6B0 */
    { R[31] = 0x800CF6BCu; R[4] = R[2] + R[4]; psx_next = 0x800CF118u; return; }  /* 0x800CF6B4 jal */
    { goto L_800CF798; }  /* 0x800CF6BC j */
L_800CF6C4:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
L_800CF6E8:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF274(void) {
    R[4] = R[17] + R[0];  /* 0x800CF274 */
    R[5] = R[16] + R[0];  /* 0x800CF278 */
    R[2] = R[0] + 50;  /* 0x800CF27C */
    sb_(R[18] + 52, R[2]);  /* 0x800CF280 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF284 */
    R[2] = 0x800Bu << 16;  /* 0x800CF288 */
    R[2] = R[2] - 8012;  /* 0x800CF28C */
    sw_(R[17] + 232, R[2]);  /* 0x800CF290 */
    R[2] = 0x800Fu << 16;  /* 0x800CF294 */
    R[2] = R[2] - 496;  /* 0x800CF298 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF29C */
    R[2] = R[0] + 6400;  /* 0x800CF2A0 */
    sw_(R[17] + 124, R[2]);  /* 0x800CF2A4 */
    R[2] = R[0] + 40;  /* 0x800CF2A8 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF2AC */
    R[2] = R[0] | 0xA000;  /* 0x800CF2B0 */
    sw_(R[17] + 600, R[2]);  /* 0x800CF2B4 */
    R[2] = 0x32u << 16;  /* 0x800CF2B8 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF2BC */
    { R[31] = 0x800CF2C8u; sh_(R[17] + 586, R[0]); psx_next = 0x800CDBDCu; return; }  /* 0x800CF2C0 jal */
    R[4] = R[17] + R[0];  /* 0x800CF2C8 */
    R[5] = 0x800Fu << 16;  /* 0x800CF2CC */
    { R[31] = 0x800CF2D8u; R[5] = R[5] - 396; psx_next = 0x800CD894u; return; }  /* 0x800CF2D0 jal */
    { goto L_800CF798; }  /* 0x800CF2D8 j */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 586);  /* 0x800CF2E0 */
    { uint32_t _c = (R[3] == R[20]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_800CF5A0; } }  /* 0x800CF2E8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CF308; } }  /* 0x800CF2F0 */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_800CF318; } }  /* 0x800CF2F8 */
    { goto L_800CF798; }  /* 0x800CF300 j */
L_800CF308:;
    { uint32_t _c = (R[3] == R[16]); if (_c) { goto L_800CF6C4; } }  /* 0x800CF308 */
    { goto L_800CF798; }  /* 0x800CF310 j */
L_800CF318:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF318 */
    R[2] = R[2] - 1;  /* 0x800CF320 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF324 */
    R[2] = R[2] << 16;  /* 0x800CF328 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[16] = R[0] + 8; if (_c) { goto L_800CF3B4; } }  /* 0x800CF32C */
    R[4] = R[0] - 128;  /* 0x800CF334 */
    psx_div((int32_t)R[4], (int32_t)R[16]);  /* 0x800CF338 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CF348; } }  /* 0x800CF33C */
    psx_break(7168);  /* 0x800CF344 */
L_800CF348:;
    R[1] = R[0] - 1;  /* 0x800CF348 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF360; } }  /* 0x800CF34C */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CF360; } }  /* 0x800CF354 */
    psx_break(6144);  /* 0x800CF35C */
L_800CF360:;
    R[4] = LO;  /* 0x800CF360 */
    R[3] = lw_(R[17] + 604);  /* 0x800CF364 */
    psx_div((int32_t)R[3], (int32_t)R[16]);  /* 0x800CF36C */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CF37C; } }  /* 0x800CF370 */
    psx_break(7168);  /* 0x800CF378 */
L_800CF37C:;
    R[1] = R[0] - 1;  /* 0x800CF37C */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF394; } }  /* 0x800CF380 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CF394; } }  /* 0x800CF388 */
    psx_break(6144);  /* 0x800CF390 */
L_800CF394:;
    R[3] = LO;  /* 0x800CF394 */
    sb_(R[17] + 584, R[0]);  /* 0x800CF398 */
    sh_(R[17] + 582, R[16]);  /* 0x800CF39C */
    R[2] = R[0] + 4;  /* 0x800CF3A0 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF3A4 */
    sh_(R[17] + 592, R[4]);  /* 0x800CF3A8 */
    { sw_(R[17] + 600, R[3]); goto L_800CF798; }  /* 0x800CF3AC j */
L_800CF3B4:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 218);  /* 0x800CF3B4 */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[5] = R[0] + 16; if (_c) { goto L_800CF50C; } }  /* 0x800CF3BC */
    R[2] = lb_(R[17] + 585);  /* 0x800CF3C4 */
    R[3] = R[2] << 3;  /* 0x800CF3CC */
    R[3] = R[3] + R[2];  /* 0x800CF3D0 */
    R[3] = R[3] << 7;  /* 0x800CF3D4 */
    R[2] = 0x8014u << 16;  /* 0x800CF3D8 */
    R[2] = R[2] + 15160;  /* 0x800CF3DC */
    R[18] = R[3] + R[2];  /* 0x800CF3E0 */
    { R[31] = 0x800CF3ECu; R[4] = R[18] + R[0]; psx_next = 0x800CD6CCu; return; }  /* 0x800CF3E4 jal */
    R[4] = R[17] + R[0];  /* 0x800CF3EC */
    R[5] = R[0] + 1;  /* 0x800CF3F0 */
    R[2] = 0x8014u << 16;  /* 0x800CF3F4 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF3F8 */
    R[2] = R[2] + 15136;  /* 0x800CF3FC */
    R[3] = R[3] << 2;  /* 0x800CF400 */
    R[16] = R[3] + R[2];  /* 0x800CF404 */
    { R[31] = 0x800CF410u; R[6] = R[16] + R[0]; psx_next = 0x800CE504u; return; }  /* 0x800CF408 jal */
    R[19] = R[2] + R[0];  /* 0x800CF410 */
    { uint32_t _c = ((int32_t)R[19] <= 0); if (_c) { goto L_800CF51C; } }  /* 0x800CF414 */
    { R[31] = 0x800CF424u; R[4] = R[0] + 56; psx_next = 0x8002DB10u; return; }  /* 0x800CF41C jal */
    sb_(R[17] + 584, R[20]);  /* 0x800CF424 */
    sw_(R[17] + 124, R[0]);  /* 0x800CF428 */
    sw_(R[17] + 188, R[0]);  /* 0x800CF42C */
    R[2] = lw_(R[16]);  /* 0x800CF430 */
    R[2] = lw_(R[2] + 24);  /* 0x800CF438 */
    sw_(R[17] + 24, R[2]);  /* 0x800CF440 */
    R[2] = lw_(R[16]);  /* 0x800CF444 */
    R[2] = lw_(R[2] + 28);  /* 0x800CF44C */
    sw_(R[17] + 28, R[2]);  /* 0x800CF454 */
    R[2] = lw_(R[16]);  /* 0x800CF458 */
    R[6] = lb_(R[17] + 585);  /* 0x800CF45C */
    R[2] = lw_(R[2] + 32);  /* 0x800CF460 */
    R[5] = 0x800Fu << 16;  /* 0x800CF464 */
    sw_(R[17] + 32, R[2]);  /* 0x800CF468 */
    R[4] = lw_(R[16]);  /* 0x800CF46C */
    { R[31] = 0x800CF478u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CF470 jal */
    R[4] = 0x800Fu << 16;  /* 0x800CF478 */
    R[4] = R[4] - 220;  /* 0x800CF47C */
    R[6] = R[18] + R[0];  /* 0x800CF480 */
    R[5] = lw_(R[16]);  /* 0x800CF484 */
    { R[31] = 0x800CF490u; R[7] = R[0] + 2; psx_next = 0x800CEF90u; return; }  /* 0x800CF488 jal */
    sh_(R[17] + 594, R[2]);  /* 0x800CF490 */
    R[3] = lw_(R[16]);  /* 0x800CF494 */
    R[4] = R[0] + 16;  /* 0x800CF498 */
    R[2] = lb_(R[3] + 789);  /* 0x800CF49C */
    R[6] = 0x8011u << 16;  /* 0x800CF4A0 */
    R[2] = R[2] | 0x2;  /* 0x800CF4A4 */
    sb_(R[3] + 789, R[2]);  /* 0x800CF4A8 */
    R[5] = lw_(R[16]);  /* 0x800CF4AC */
    { R[31] = 0x800CF4B8u; R[6] = R[6] + 30196; psx_next = 0x800AC93Cu; return; }  /* 0x800CF4B0 jal */
    R[4] = lw_(R[16]);  /* 0x800CF4B8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CF4C0 */
    R[3] = R[0] - 897;  /* 0x800CF4C4 */
    R[2] = R[2] & R[3];  /* 0x800CF4C8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CF4CC */
    R[3] = lw_(R[16]);  /* 0x800CF4D0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CF4D8 */
    R[2] = R[2] | 0x180;  /* 0x800CF4E0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CF4E4 */
    R[2] = R[0] + 15;  /* 0x800CF4E8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CF4EC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF4F0 */
    R[2] = lw_(R[16]);  /* 0x800CF4F4 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF4F8 */
    sw_(R[17] + 608, R[19]);  /* 0x800CF4FC */
    sh_(R[17] + 586, R[20]);  /* 0x800CF500 */
    { sw_(R[17] + 588, R[2]); goto L_800CF548; }  /* 0x800CF504 j */
L_800CF50C:;
    R[2] = lb_(R[17] + 785);  /* 0x800CF50C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800CF554; } }  /* 0x800CF514 */
L_800CF51C:;
    R[16] = R[0] + 8;  /* 0x800CF51C */
    R[4] = R[17] + R[0];  /* 0x800CF520 */
    R[5] = 0x800Fu << 16;  /* 0x800CF524 */
    R[5] = R[5] - 220;  /* 0x800CF528 */
    R[6] = R[16] + R[0];  /* 0x800CF52C */
    R[2] = R[0] + 2;  /* 0x800CF530 */
    { R[31] = 0x800CF53Cu; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CF534 jal */
    R[2] = R[0] + 4;  /* 0x800CF53C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF540 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF544 */
L_800CF548:;
    R[2] = R[0] + 3;  /* 0x800CF548 */
    { sb_(R[17] + 786, R[2]); goto L_800CF798; }  /* 0x800CF54C j */
L_800CF554:;
    R[2] = R[0] + 8;  /* 0x800CF554 */
    sb_(R[18] + 3, R[2]);  /* 0x800CF558 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF55C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF560 */
    R[5] = R[0] + 5;  /* 0x800CF564 */
    R[2] = R[2] - R[3];  /* 0x800CF568 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF56C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF570 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF574 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF578 */
    R[6] = R[0] | 0xA000;  /* 0x800CF57C */
    { R[31] = 0x800CF588u; sb_(R[18] + 53, R[2]); psx_next = 0x800CE35Cu; return; }  /* 0x800CF580 jal */
    { R[31] = 0x800CF590u; R[4] = R[17] + R[0]; psx_next = 0x800CDCACu; return; }  /* 0x800CF588 jal */
    { R[31] = 0x800CF598u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CF590 jal */
    { goto L_800CF798; }  /* 0x800CF598 j */
L_800CF5A0:;
    R[5] = R[0] + 1;  /* 0x800CF5A0 */
    R[6] = R[5] + R[0];  /* 0x800CF5A4 */
    R[2] = 0x8014u << 16;  /* 0x800CF5A8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5AC */
    R[18] = R[2] + 15136;  /* 0x800CF5B0 */
    R[4] = R[4] << 2;  /* 0x800CF5B4 */
    { R[31] = 0x800CF5C0u; R[4] = R[4] + R[18]; psx_next = 0x800CCF94u; return; }  /* 0x800CF5B8 jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CF5CC; } }  /* 0x800CF5C0 */
    sh_(R[17] + 582, R[0]);  /* 0x800CF5C8 */
L_800CF5CC:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF5CC */
    R[2] = R[2] - 1;  /* 0x800CF5D4 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF5D8 */
    R[2] = R[2] << 16;  /* 0x800CF5DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF5E0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[2] = ((int32_t)R[2] < 9); if (_c) { goto L_800CF630; } }  /* 0x800CF5E4 */
    R[5] = R[0] + 1;  /* 0x800CF5EC */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5F0 */
    R[6] = R[5] + R[0];  /* 0x800CF5F4 */
    R[4] = R[4] << 2;  /* 0x800CF5F8 */
    { R[31] = 0x800CF604u; R[4] = R[4] + R[18]; psx_next = 0x800CD028u; return; }  /* 0x800CF5FC jal */
    R[2] = 0x800Fu << 16;  /* 0x800CF604 */
    R[3] = lw_(R[17] + 588);  /* 0x800CF608 */
    R[2] = R[2] - 416;  /* 0x800CF60C */
    sw_(R[17] + 608, R[0]);  /* 0x800CF610 */
    sh_(R[17] + 14, R[0]);  /* 0x800CF614 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF618 */
    R[2] = lb_(R[3] + 2);  /* 0x800CF61C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF620 */
    sh_(R[17] + 586, R[16]);  /* 0x800CF624 */
    { sb_(R[17] + 801, R[2]); goto L_800CF68C; }  /* 0x800CF628 j */
L_800CF630:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF68C; } }  /* 0x800CF630 */
    R[2] = lh_(R[17] + 592);  /* 0x800CF638 */
    R[2] = R[2] + 1;  /* 0x800CF640 */
    sh_(R[17] + 592, R[2]);  /* 0x800CF644 */
    R[2] = R[2] << 16;  /* 0x800CF648 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF64C */
    R[2] = ((int32_t)R[2] < 2);  /* 0x800CF650 */
    { uint32_t _c = (R[2] != R[0]); R[7] = R[0] + 2; if (_c) { goto L_800CF68C; } }  /* 0x800CF654 */
    R[4] = 0x800Fu << 16;  /* 0x800CF65C */
    R[4] = R[4] - 220;  /* 0x800CF660 */
    R[6] = 0x8014u << 16;  /* 0x800CF664 */
    R[5] = lw_(R[17] + 588);  /* 0x800CF668 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF66C */
    R[6] = R[6] + 15160;  /* 0x800CF670 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF674 */
    R[2] = R[3] << 3;  /* 0x800CF678 */
    R[2] = R[2] + R[3];  /* 0x800CF67C */
    R[2] = R[2] << 7;  /* 0x800CF680 */
    { R[31] = 0x800CF68Cu; R[6] = R[2] + R[6]; psx_next = 0x800CEF90u; return; }  /* 0x800CF684 jal */
L_800CF68C:;
    R[5] = lw_(R[17] + 588);  /* 0x800CF68C */
    { R[31] = 0x800CF698u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CF690 jal */
    R[4] = 0x8014u << 16;  /* 0x800CF698 */
    R[4] = R[4] + 15160;  /* 0x800CF69C */
    R[3] = lb_(R[17] + 585);  /* 0x800CF6A0 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 594);  /* 0x800CF6A4 */
    R[2] = R[3] << 3;  /* 0x800CF6A8 */
    R[2] = R[2] + R[3];  /* 0x800CF6AC */
    R[2] = R[2] << 7;  /* 0x800CF6B0 */
    { R[31] = 0x800CF6BCu; R[4] = R[2] + R[4]; psx_next = 0x800CF118u; return; }  /* 0x800CF6B4 jal */
    { goto L_800CF798; }  /* 0x800CF6BC j */
L_800CF6C4:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF2C8(void) {
    R[4] = R[17] + R[0];  /* 0x800CF2C8 */
    R[5] = 0x800Fu << 16;  /* 0x800CF2CC */
    { R[31] = 0x800CF2D8u; R[5] = R[5] - 396; psx_next = 0x800CD894u; return; }  /* 0x800CF2D0 jal */
    { goto L_800CF798; }  /* 0x800CF2D8 j */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 586);  /* 0x800CF2E0 */
    { uint32_t _c = (R[3] == R[20]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_800CF5A0; } }  /* 0x800CF2E8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CF308; } }  /* 0x800CF2F0 */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_800CF318; } }  /* 0x800CF2F8 */
    { goto L_800CF798; }  /* 0x800CF300 j */
L_800CF308:;
    { uint32_t _c = (R[3] == R[16]); if (_c) { goto L_800CF6C4; } }  /* 0x800CF308 */
    { goto L_800CF798; }  /* 0x800CF310 j */
L_800CF318:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF318 */
    R[2] = R[2] - 1;  /* 0x800CF320 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF324 */
    R[2] = R[2] << 16;  /* 0x800CF328 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[16] = R[0] + 8; if (_c) { goto L_800CF3B4; } }  /* 0x800CF32C */
    R[4] = R[0] - 128;  /* 0x800CF334 */
    psx_div((int32_t)R[4], (int32_t)R[16]);  /* 0x800CF338 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CF348; } }  /* 0x800CF33C */
    psx_break(7168);  /* 0x800CF344 */
L_800CF348:;
    R[1] = R[0] - 1;  /* 0x800CF348 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF360; } }  /* 0x800CF34C */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CF360; } }  /* 0x800CF354 */
    psx_break(6144);  /* 0x800CF35C */
L_800CF360:;
    R[4] = LO;  /* 0x800CF360 */
    R[3] = lw_(R[17] + 604);  /* 0x800CF364 */
    psx_div((int32_t)R[3], (int32_t)R[16]);  /* 0x800CF36C */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CF37C; } }  /* 0x800CF370 */
    psx_break(7168);  /* 0x800CF378 */
L_800CF37C:;
    R[1] = R[0] - 1;  /* 0x800CF37C */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF394; } }  /* 0x800CF380 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CF394; } }  /* 0x800CF388 */
    psx_break(6144);  /* 0x800CF390 */
L_800CF394:;
    R[3] = LO;  /* 0x800CF394 */
    sb_(R[17] + 584, R[0]);  /* 0x800CF398 */
    sh_(R[17] + 582, R[16]);  /* 0x800CF39C */
    R[2] = R[0] + 4;  /* 0x800CF3A0 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF3A4 */
    sh_(R[17] + 592, R[4]);  /* 0x800CF3A8 */
    { sw_(R[17] + 600, R[3]); goto L_800CF798; }  /* 0x800CF3AC j */
L_800CF3B4:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 218);  /* 0x800CF3B4 */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[5] = R[0] + 16; if (_c) { goto L_800CF50C; } }  /* 0x800CF3BC */
    R[2] = lb_(R[17] + 585);  /* 0x800CF3C4 */
    R[3] = R[2] << 3;  /* 0x800CF3CC */
    R[3] = R[3] + R[2];  /* 0x800CF3D0 */
    R[3] = R[3] << 7;  /* 0x800CF3D4 */
    R[2] = 0x8014u << 16;  /* 0x800CF3D8 */
    R[2] = R[2] + 15160;  /* 0x800CF3DC */
    R[18] = R[3] + R[2];  /* 0x800CF3E0 */
    { R[31] = 0x800CF3ECu; R[4] = R[18] + R[0]; psx_next = 0x800CD6CCu; return; }  /* 0x800CF3E4 jal */
    R[4] = R[17] + R[0];  /* 0x800CF3EC */
    R[5] = R[0] + 1;  /* 0x800CF3F0 */
    R[2] = 0x8014u << 16;  /* 0x800CF3F4 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF3F8 */
    R[2] = R[2] + 15136;  /* 0x800CF3FC */
    R[3] = R[3] << 2;  /* 0x800CF400 */
    R[16] = R[3] + R[2];  /* 0x800CF404 */
    { R[31] = 0x800CF410u; R[6] = R[16] + R[0]; psx_next = 0x800CE504u; return; }  /* 0x800CF408 jal */
    R[19] = R[2] + R[0];  /* 0x800CF410 */
    { uint32_t _c = ((int32_t)R[19] <= 0); if (_c) { goto L_800CF51C; } }  /* 0x800CF414 */
    { R[31] = 0x800CF424u; R[4] = R[0] + 56; psx_next = 0x8002DB10u; return; }  /* 0x800CF41C jal */
    sb_(R[17] + 584, R[20]);  /* 0x800CF424 */
    sw_(R[17] + 124, R[0]);  /* 0x800CF428 */
    sw_(R[17] + 188, R[0]);  /* 0x800CF42C */
    R[2] = lw_(R[16]);  /* 0x800CF430 */
    R[2] = lw_(R[2] + 24);  /* 0x800CF438 */
    sw_(R[17] + 24, R[2]);  /* 0x800CF440 */
    R[2] = lw_(R[16]);  /* 0x800CF444 */
    R[2] = lw_(R[2] + 28);  /* 0x800CF44C */
    sw_(R[17] + 28, R[2]);  /* 0x800CF454 */
    R[2] = lw_(R[16]);  /* 0x800CF458 */
    R[6] = lb_(R[17] + 585);  /* 0x800CF45C */
    R[2] = lw_(R[2] + 32);  /* 0x800CF460 */
    R[5] = 0x800Fu << 16;  /* 0x800CF464 */
    sw_(R[17] + 32, R[2]);  /* 0x800CF468 */
    R[4] = lw_(R[16]);  /* 0x800CF46C */
    { R[31] = 0x800CF478u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CF470 jal */
    R[4] = 0x800Fu << 16;  /* 0x800CF478 */
    R[4] = R[4] - 220;  /* 0x800CF47C */
    R[6] = R[18] + R[0];  /* 0x800CF480 */
    R[5] = lw_(R[16]);  /* 0x800CF484 */
    { R[31] = 0x800CF490u; R[7] = R[0] + 2; psx_next = 0x800CEF90u; return; }  /* 0x800CF488 jal */
    sh_(R[17] + 594, R[2]);  /* 0x800CF490 */
    R[3] = lw_(R[16]);  /* 0x800CF494 */
    R[4] = R[0] + 16;  /* 0x800CF498 */
    R[2] = lb_(R[3] + 789);  /* 0x800CF49C */
    R[6] = 0x8011u << 16;  /* 0x800CF4A0 */
    R[2] = R[2] | 0x2;  /* 0x800CF4A4 */
    sb_(R[3] + 789, R[2]);  /* 0x800CF4A8 */
    R[5] = lw_(R[16]);  /* 0x800CF4AC */
    { R[31] = 0x800CF4B8u; R[6] = R[6] + 30196; psx_next = 0x800AC93Cu; return; }  /* 0x800CF4B0 jal */
    R[4] = lw_(R[16]);  /* 0x800CF4B8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CF4C0 */
    R[3] = R[0] - 897;  /* 0x800CF4C4 */
    R[2] = R[2] & R[3];  /* 0x800CF4C8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CF4CC */
    R[3] = lw_(R[16]);  /* 0x800CF4D0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CF4D8 */
    R[2] = R[2] | 0x180;  /* 0x800CF4E0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CF4E4 */
    R[2] = R[0] + 15;  /* 0x800CF4E8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CF4EC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF4F0 */
    R[2] = lw_(R[16]);  /* 0x800CF4F4 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF4F8 */
    sw_(R[17] + 608, R[19]);  /* 0x800CF4FC */
    sh_(R[17] + 586, R[20]);  /* 0x800CF500 */
    { sw_(R[17] + 588, R[2]); goto L_800CF548; }  /* 0x800CF504 j */
L_800CF50C:;
    R[2] = lb_(R[17] + 785);  /* 0x800CF50C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800CF554; } }  /* 0x800CF514 */
L_800CF51C:;
    R[16] = R[0] + 8;  /* 0x800CF51C */
    R[4] = R[17] + R[0];  /* 0x800CF520 */
    R[5] = 0x800Fu << 16;  /* 0x800CF524 */
    R[5] = R[5] - 220;  /* 0x800CF528 */
    R[6] = R[16] + R[0];  /* 0x800CF52C */
    R[2] = R[0] + 2;  /* 0x800CF530 */
    { R[31] = 0x800CF53Cu; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CF534 jal */
    R[2] = R[0] + 4;  /* 0x800CF53C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF540 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF544 */
L_800CF548:;
    R[2] = R[0] + 3;  /* 0x800CF548 */
    { sb_(R[17] + 786, R[2]); goto L_800CF798; }  /* 0x800CF54C j */
L_800CF554:;
    R[2] = R[0] + 8;  /* 0x800CF554 */
    sb_(R[18] + 3, R[2]);  /* 0x800CF558 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF55C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF560 */
    R[5] = R[0] + 5;  /* 0x800CF564 */
    R[2] = R[2] - R[3];  /* 0x800CF568 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF56C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF570 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF574 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF578 */
    R[6] = R[0] | 0xA000;  /* 0x800CF57C */
    { R[31] = 0x800CF588u; sb_(R[18] + 53, R[2]); psx_next = 0x800CE35Cu; return; }  /* 0x800CF580 jal */
    { R[31] = 0x800CF590u; R[4] = R[17] + R[0]; psx_next = 0x800CDCACu; return; }  /* 0x800CF588 jal */
    { R[31] = 0x800CF598u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CF590 jal */
    { goto L_800CF798; }  /* 0x800CF598 j */
L_800CF5A0:;
    R[5] = R[0] + 1;  /* 0x800CF5A0 */
    R[6] = R[5] + R[0];  /* 0x800CF5A4 */
    R[2] = 0x8014u << 16;  /* 0x800CF5A8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5AC */
    R[18] = R[2] + 15136;  /* 0x800CF5B0 */
    R[4] = R[4] << 2;  /* 0x800CF5B4 */
    { R[31] = 0x800CF5C0u; R[4] = R[4] + R[18]; psx_next = 0x800CCF94u; return; }  /* 0x800CF5B8 jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CF5CC; } }  /* 0x800CF5C0 */
    sh_(R[17] + 582, R[0]);  /* 0x800CF5C8 */
L_800CF5CC:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF5CC */
    R[2] = R[2] - 1;  /* 0x800CF5D4 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF5D8 */
    R[2] = R[2] << 16;  /* 0x800CF5DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF5E0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[2] = ((int32_t)R[2] < 9); if (_c) { goto L_800CF630; } }  /* 0x800CF5E4 */
    R[5] = R[0] + 1;  /* 0x800CF5EC */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5F0 */
    R[6] = R[5] + R[0];  /* 0x800CF5F4 */
    R[4] = R[4] << 2;  /* 0x800CF5F8 */
    { R[31] = 0x800CF604u; R[4] = R[4] + R[18]; psx_next = 0x800CD028u; return; }  /* 0x800CF5FC jal */
    R[2] = 0x800Fu << 16;  /* 0x800CF604 */
    R[3] = lw_(R[17] + 588);  /* 0x800CF608 */
    R[2] = R[2] - 416;  /* 0x800CF60C */
    sw_(R[17] + 608, R[0]);  /* 0x800CF610 */
    sh_(R[17] + 14, R[0]);  /* 0x800CF614 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF618 */
    R[2] = lb_(R[3] + 2);  /* 0x800CF61C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF620 */
    sh_(R[17] + 586, R[16]);  /* 0x800CF624 */
    { sb_(R[17] + 801, R[2]); goto L_800CF68C; }  /* 0x800CF628 j */
L_800CF630:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF68C; } }  /* 0x800CF630 */
    R[2] = lh_(R[17] + 592);  /* 0x800CF638 */
    R[2] = R[2] + 1;  /* 0x800CF640 */
    sh_(R[17] + 592, R[2]);  /* 0x800CF644 */
    R[2] = R[2] << 16;  /* 0x800CF648 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF64C */
    R[2] = ((int32_t)R[2] < 2);  /* 0x800CF650 */
    { uint32_t _c = (R[2] != R[0]); R[7] = R[0] + 2; if (_c) { goto L_800CF68C; } }  /* 0x800CF654 */
    R[4] = 0x800Fu << 16;  /* 0x800CF65C */
    R[4] = R[4] - 220;  /* 0x800CF660 */
    R[6] = 0x8014u << 16;  /* 0x800CF664 */
    R[5] = lw_(R[17] + 588);  /* 0x800CF668 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF66C */
    R[6] = R[6] + 15160;  /* 0x800CF670 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF674 */
    R[2] = R[3] << 3;  /* 0x800CF678 */
    R[2] = R[2] + R[3];  /* 0x800CF67C */
    R[2] = R[2] << 7;  /* 0x800CF680 */
    { R[31] = 0x800CF68Cu; R[6] = R[2] + R[6]; psx_next = 0x800CEF90u; return; }  /* 0x800CF684 jal */
L_800CF68C:;
    R[5] = lw_(R[17] + 588);  /* 0x800CF68C */
    { R[31] = 0x800CF698u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CF690 jal */
    R[4] = 0x8014u << 16;  /* 0x800CF698 */
    R[4] = R[4] + 15160;  /* 0x800CF69C */
    R[3] = lb_(R[17] + 585);  /* 0x800CF6A0 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 594);  /* 0x800CF6A4 */
    R[2] = R[3] << 3;  /* 0x800CF6A8 */
    R[2] = R[2] + R[3];  /* 0x800CF6AC */
    R[2] = R[2] << 7;  /* 0x800CF6B0 */
    { R[31] = 0x800CF6BCu; R[4] = R[2] + R[4]; psx_next = 0x800CF118u; return; }  /* 0x800CF6B4 jal */
    { goto L_800CF798; }  /* 0x800CF6BC j */
L_800CF6C4:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF2D8(void) {
    { goto L_800CF798; }  /* 0x800CF2D8 j */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 586);  /* 0x800CF2E0 */
    { uint32_t _c = (R[3] == R[20]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_800CF5A0; } }  /* 0x800CF2E8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CF308; } }  /* 0x800CF2F0 */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_800CF318; } }  /* 0x800CF2F8 */
    { goto L_800CF798; }  /* 0x800CF300 j */
L_800CF308:;
    { uint32_t _c = (R[3] == R[16]); if (_c) { goto L_800CF6C4; } }  /* 0x800CF308 */
    { goto L_800CF798; }  /* 0x800CF310 j */
L_800CF318:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF318 */
    R[2] = R[2] - 1;  /* 0x800CF320 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF324 */
    R[2] = R[2] << 16;  /* 0x800CF328 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[16] = R[0] + 8; if (_c) { goto L_800CF3B4; } }  /* 0x800CF32C */
    R[4] = R[0] - 128;  /* 0x800CF334 */
    psx_div((int32_t)R[4], (int32_t)R[16]);  /* 0x800CF338 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CF348; } }  /* 0x800CF33C */
    psx_break(7168);  /* 0x800CF344 */
L_800CF348:;
    R[1] = R[0] - 1;  /* 0x800CF348 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF360; } }  /* 0x800CF34C */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CF360; } }  /* 0x800CF354 */
    psx_break(6144);  /* 0x800CF35C */
L_800CF360:;
    R[4] = LO;  /* 0x800CF360 */
    R[3] = lw_(R[17] + 604);  /* 0x800CF364 */
    psx_div((int32_t)R[3], (int32_t)R[16]);  /* 0x800CF36C */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CF37C; } }  /* 0x800CF370 */
    psx_break(7168);  /* 0x800CF378 */
L_800CF37C:;
    R[1] = R[0] - 1;  /* 0x800CF37C */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF394; } }  /* 0x800CF380 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CF394; } }  /* 0x800CF388 */
    psx_break(6144);  /* 0x800CF390 */
L_800CF394:;
    R[3] = LO;  /* 0x800CF394 */
    sb_(R[17] + 584, R[0]);  /* 0x800CF398 */
    sh_(R[17] + 582, R[16]);  /* 0x800CF39C */
    R[2] = R[0] + 4;  /* 0x800CF3A0 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF3A4 */
    sh_(R[17] + 592, R[4]);  /* 0x800CF3A8 */
    { sw_(R[17] + 600, R[3]); goto L_800CF798; }  /* 0x800CF3AC j */
L_800CF3B4:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 218);  /* 0x800CF3B4 */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[5] = R[0] + 16; if (_c) { goto L_800CF50C; } }  /* 0x800CF3BC */
    R[2] = lb_(R[17] + 585);  /* 0x800CF3C4 */
    R[3] = R[2] << 3;  /* 0x800CF3CC */
    R[3] = R[3] + R[2];  /* 0x800CF3D0 */
    R[3] = R[3] << 7;  /* 0x800CF3D4 */
    R[2] = 0x8014u << 16;  /* 0x800CF3D8 */
    R[2] = R[2] + 15160;  /* 0x800CF3DC */
    R[18] = R[3] + R[2];  /* 0x800CF3E0 */
    { R[31] = 0x800CF3ECu; R[4] = R[18] + R[0]; psx_next = 0x800CD6CCu; return; }  /* 0x800CF3E4 jal */
    R[4] = R[17] + R[0];  /* 0x800CF3EC */
    R[5] = R[0] + 1;  /* 0x800CF3F0 */
    R[2] = 0x8014u << 16;  /* 0x800CF3F4 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF3F8 */
    R[2] = R[2] + 15136;  /* 0x800CF3FC */
    R[3] = R[3] << 2;  /* 0x800CF400 */
    R[16] = R[3] + R[2];  /* 0x800CF404 */
    { R[31] = 0x800CF410u; R[6] = R[16] + R[0]; psx_next = 0x800CE504u; return; }  /* 0x800CF408 jal */
    R[19] = R[2] + R[0];  /* 0x800CF410 */
    { uint32_t _c = ((int32_t)R[19] <= 0); if (_c) { goto L_800CF51C; } }  /* 0x800CF414 */
    { R[31] = 0x800CF424u; R[4] = R[0] + 56; psx_next = 0x8002DB10u; return; }  /* 0x800CF41C jal */
    sb_(R[17] + 584, R[20]);  /* 0x800CF424 */
    sw_(R[17] + 124, R[0]);  /* 0x800CF428 */
    sw_(R[17] + 188, R[0]);  /* 0x800CF42C */
    R[2] = lw_(R[16]);  /* 0x800CF430 */
    R[2] = lw_(R[2] + 24);  /* 0x800CF438 */
    sw_(R[17] + 24, R[2]);  /* 0x800CF440 */
    R[2] = lw_(R[16]);  /* 0x800CF444 */
    R[2] = lw_(R[2] + 28);  /* 0x800CF44C */
    sw_(R[17] + 28, R[2]);  /* 0x800CF454 */
    R[2] = lw_(R[16]);  /* 0x800CF458 */
    R[6] = lb_(R[17] + 585);  /* 0x800CF45C */
    R[2] = lw_(R[2] + 32);  /* 0x800CF460 */
    R[5] = 0x800Fu << 16;  /* 0x800CF464 */
    sw_(R[17] + 32, R[2]);  /* 0x800CF468 */
    R[4] = lw_(R[16]);  /* 0x800CF46C */
    { R[31] = 0x800CF478u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CF470 jal */
    R[4] = 0x800Fu << 16;  /* 0x800CF478 */
    R[4] = R[4] - 220;  /* 0x800CF47C */
    R[6] = R[18] + R[0];  /* 0x800CF480 */
    R[5] = lw_(R[16]);  /* 0x800CF484 */
    { R[31] = 0x800CF490u; R[7] = R[0] + 2; psx_next = 0x800CEF90u; return; }  /* 0x800CF488 jal */
    sh_(R[17] + 594, R[2]);  /* 0x800CF490 */
    R[3] = lw_(R[16]);  /* 0x800CF494 */
    R[4] = R[0] + 16;  /* 0x800CF498 */
    R[2] = lb_(R[3] + 789);  /* 0x800CF49C */
    R[6] = 0x8011u << 16;  /* 0x800CF4A0 */
    R[2] = R[2] | 0x2;  /* 0x800CF4A4 */
    sb_(R[3] + 789, R[2]);  /* 0x800CF4A8 */
    R[5] = lw_(R[16]);  /* 0x800CF4AC */
    { R[31] = 0x800CF4B8u; R[6] = R[6] + 30196; psx_next = 0x800AC93Cu; return; }  /* 0x800CF4B0 jal */
    R[4] = lw_(R[16]);  /* 0x800CF4B8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CF4C0 */
    R[3] = R[0] - 897;  /* 0x800CF4C4 */
    R[2] = R[2] & R[3];  /* 0x800CF4C8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CF4CC */
    R[3] = lw_(R[16]);  /* 0x800CF4D0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CF4D8 */
    R[2] = R[2] | 0x180;  /* 0x800CF4E0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CF4E4 */
    R[2] = R[0] + 15;  /* 0x800CF4E8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CF4EC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF4F0 */
    R[2] = lw_(R[16]);  /* 0x800CF4F4 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF4F8 */
    sw_(R[17] + 608, R[19]);  /* 0x800CF4FC */
    sh_(R[17] + 586, R[20]);  /* 0x800CF500 */
    { sw_(R[17] + 588, R[2]); goto L_800CF548; }  /* 0x800CF504 j */
L_800CF50C:;
    R[2] = lb_(R[17] + 785);  /* 0x800CF50C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800CF554; } }  /* 0x800CF514 */
L_800CF51C:;
    R[16] = R[0] + 8;  /* 0x800CF51C */
    R[4] = R[17] + R[0];  /* 0x800CF520 */
    R[5] = 0x800Fu << 16;  /* 0x800CF524 */
    R[5] = R[5] - 220;  /* 0x800CF528 */
    R[6] = R[16] + R[0];  /* 0x800CF52C */
    R[2] = R[0] + 2;  /* 0x800CF530 */
    { R[31] = 0x800CF53Cu; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CF534 jal */
    R[2] = R[0] + 4;  /* 0x800CF53C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF540 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF544 */
L_800CF548:;
    R[2] = R[0] + 3;  /* 0x800CF548 */
    { sb_(R[17] + 786, R[2]); goto L_800CF798; }  /* 0x800CF54C j */
L_800CF554:;
    R[2] = R[0] + 8;  /* 0x800CF554 */
    sb_(R[18] + 3, R[2]);  /* 0x800CF558 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF55C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF560 */
    R[5] = R[0] + 5;  /* 0x800CF564 */
    R[2] = R[2] - R[3];  /* 0x800CF568 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF56C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF570 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF574 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF578 */
    R[6] = R[0] | 0xA000;  /* 0x800CF57C */
    { R[31] = 0x800CF588u; sb_(R[18] + 53, R[2]); psx_next = 0x800CE35Cu; return; }  /* 0x800CF580 jal */
    { R[31] = 0x800CF590u; R[4] = R[17] + R[0]; psx_next = 0x800CDCACu; return; }  /* 0x800CF588 jal */
    { R[31] = 0x800CF598u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CF590 jal */
    { goto L_800CF798; }  /* 0x800CF598 j */
L_800CF5A0:;
    R[5] = R[0] + 1;  /* 0x800CF5A0 */
    R[6] = R[5] + R[0];  /* 0x800CF5A4 */
    R[2] = 0x8014u << 16;  /* 0x800CF5A8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5AC */
    R[18] = R[2] + 15136;  /* 0x800CF5B0 */
    R[4] = R[4] << 2;  /* 0x800CF5B4 */
    { R[31] = 0x800CF5C0u; R[4] = R[4] + R[18]; psx_next = 0x800CCF94u; return; }  /* 0x800CF5B8 jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CF5CC; } }  /* 0x800CF5C0 */
    sh_(R[17] + 582, R[0]);  /* 0x800CF5C8 */
L_800CF5CC:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF5CC */
    R[2] = R[2] - 1;  /* 0x800CF5D4 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF5D8 */
    R[2] = R[2] << 16;  /* 0x800CF5DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF5E0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[2] = ((int32_t)R[2] < 9); if (_c) { goto L_800CF630; } }  /* 0x800CF5E4 */
    R[5] = R[0] + 1;  /* 0x800CF5EC */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5F0 */
    R[6] = R[5] + R[0];  /* 0x800CF5F4 */
    R[4] = R[4] << 2;  /* 0x800CF5F8 */
    { R[31] = 0x800CF604u; R[4] = R[4] + R[18]; psx_next = 0x800CD028u; return; }  /* 0x800CF5FC jal */
    R[2] = 0x800Fu << 16;  /* 0x800CF604 */
    R[3] = lw_(R[17] + 588);  /* 0x800CF608 */
    R[2] = R[2] - 416;  /* 0x800CF60C */
    sw_(R[17] + 608, R[0]);  /* 0x800CF610 */
    sh_(R[17] + 14, R[0]);  /* 0x800CF614 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF618 */
    R[2] = lb_(R[3] + 2);  /* 0x800CF61C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF620 */
    sh_(R[17] + 586, R[16]);  /* 0x800CF624 */
    { sb_(R[17] + 801, R[2]); goto L_800CF68C; }  /* 0x800CF628 j */
L_800CF630:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF68C; } }  /* 0x800CF630 */
    R[2] = lh_(R[17] + 592);  /* 0x800CF638 */
    R[2] = R[2] + 1;  /* 0x800CF640 */
    sh_(R[17] + 592, R[2]);  /* 0x800CF644 */
    R[2] = R[2] << 16;  /* 0x800CF648 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF64C */
    R[2] = ((int32_t)R[2] < 2);  /* 0x800CF650 */
    { uint32_t _c = (R[2] != R[0]); R[7] = R[0] + 2; if (_c) { goto L_800CF68C; } }  /* 0x800CF654 */
    R[4] = 0x800Fu << 16;  /* 0x800CF65C */
    R[4] = R[4] - 220;  /* 0x800CF660 */
    R[6] = 0x8014u << 16;  /* 0x800CF664 */
    R[5] = lw_(R[17] + 588);  /* 0x800CF668 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF66C */
    R[6] = R[6] + 15160;  /* 0x800CF670 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF674 */
    R[2] = R[3] << 3;  /* 0x800CF678 */
    R[2] = R[2] + R[3];  /* 0x800CF67C */
    R[2] = R[2] << 7;  /* 0x800CF680 */
    { R[31] = 0x800CF68Cu; R[6] = R[2] + R[6]; psx_next = 0x800CEF90u; return; }  /* 0x800CF684 jal */
L_800CF68C:;
    R[5] = lw_(R[17] + 588);  /* 0x800CF68C */
    { R[31] = 0x800CF698u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CF690 jal */
    R[4] = 0x8014u << 16;  /* 0x800CF698 */
    R[4] = R[4] + 15160;  /* 0x800CF69C */
    R[3] = lb_(R[17] + 585);  /* 0x800CF6A0 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 594);  /* 0x800CF6A4 */
    R[2] = R[3] << 3;  /* 0x800CF6A8 */
    R[2] = R[2] + R[3];  /* 0x800CF6AC */
    R[2] = R[2] << 7;  /* 0x800CF6B0 */
    { R[31] = 0x800CF6BCu; R[4] = R[2] + R[4]; psx_next = 0x800CF118u; return; }  /* 0x800CF6B4 jal */
    { goto L_800CF798; }  /* 0x800CF6BC j */
L_800CF6C4:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF3EC(void) {
    R[4] = R[17] + R[0];  /* 0x800CF3EC */
    R[5] = R[0] + 1;  /* 0x800CF3F0 */
    R[2] = 0x8014u << 16;  /* 0x800CF3F4 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF3F8 */
    R[2] = R[2] + 15136;  /* 0x800CF3FC */
    R[3] = R[3] << 2;  /* 0x800CF400 */
    R[16] = R[3] + R[2];  /* 0x800CF404 */
    { R[31] = 0x800CF410u; R[6] = R[16] + R[0]; psx_next = 0x800CE504u; return; }  /* 0x800CF408 jal */
    R[19] = R[2] + R[0];  /* 0x800CF410 */
    { uint32_t _c = ((int32_t)R[19] <= 0); if (_c) { goto L_800CF51C; } }  /* 0x800CF414 */
    { R[31] = 0x800CF424u; R[4] = R[0] + 56; psx_next = 0x8002DB10u; return; }  /* 0x800CF41C jal */
    sb_(R[17] + 584, R[20]);  /* 0x800CF424 */
    sw_(R[17] + 124, R[0]);  /* 0x800CF428 */
    sw_(R[17] + 188, R[0]);  /* 0x800CF42C */
    R[2] = lw_(R[16]);  /* 0x800CF430 */
    R[2] = lw_(R[2] + 24);  /* 0x800CF438 */
    sw_(R[17] + 24, R[2]);  /* 0x800CF440 */
    R[2] = lw_(R[16]);  /* 0x800CF444 */
    R[2] = lw_(R[2] + 28);  /* 0x800CF44C */
    sw_(R[17] + 28, R[2]);  /* 0x800CF454 */
    R[2] = lw_(R[16]);  /* 0x800CF458 */
    R[6] = lb_(R[17] + 585);  /* 0x800CF45C */
    R[2] = lw_(R[2] + 32);  /* 0x800CF460 */
    R[5] = 0x800Fu << 16;  /* 0x800CF464 */
    sw_(R[17] + 32, R[2]);  /* 0x800CF468 */
    R[4] = lw_(R[16]);  /* 0x800CF46C */
    { R[31] = 0x800CF478u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CF470 jal */
    R[4] = 0x800Fu << 16;  /* 0x800CF478 */
    R[4] = R[4] - 220;  /* 0x800CF47C */
    R[6] = R[18] + R[0];  /* 0x800CF480 */
    R[5] = lw_(R[16]);  /* 0x800CF484 */
    { R[31] = 0x800CF490u; R[7] = R[0] + 2; psx_next = 0x800CEF90u; return; }  /* 0x800CF488 jal */
    sh_(R[17] + 594, R[2]);  /* 0x800CF490 */
    R[3] = lw_(R[16]);  /* 0x800CF494 */
    R[4] = R[0] + 16;  /* 0x800CF498 */
    R[2] = lb_(R[3] + 789);  /* 0x800CF49C */
    R[6] = 0x8011u << 16;  /* 0x800CF4A0 */
    R[2] = R[2] | 0x2;  /* 0x800CF4A4 */
    sb_(R[3] + 789, R[2]);  /* 0x800CF4A8 */
    R[5] = lw_(R[16]);  /* 0x800CF4AC */
    { R[31] = 0x800CF4B8u; R[6] = R[6] + 30196; psx_next = 0x800AC93Cu; return; }  /* 0x800CF4B0 jal */
    R[4] = lw_(R[16]);  /* 0x800CF4B8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CF4C0 */
    R[3] = R[0] - 897;  /* 0x800CF4C4 */
    R[2] = R[2] & R[3];  /* 0x800CF4C8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CF4CC */
    R[3] = lw_(R[16]);  /* 0x800CF4D0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CF4D8 */
    R[2] = R[2] | 0x180;  /* 0x800CF4E0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CF4E4 */
    R[2] = R[0] + 15;  /* 0x800CF4E8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CF4EC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF4F0 */
    R[2] = lw_(R[16]);  /* 0x800CF4F4 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF4F8 */
    sw_(R[17] + 608, R[19]);  /* 0x800CF4FC */
    sh_(R[17] + 586, R[20]);  /* 0x800CF500 */
    { sw_(R[17] + 588, R[2]); goto L_800CF548; }  /* 0x800CF504 j */
    R[2] = lb_(R[17] + 785);  /* 0x800CF50C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800CF554; } }  /* 0x800CF514 */
L_800CF51C:;
    R[16] = R[0] + 8;  /* 0x800CF51C */
    R[4] = R[17] + R[0];  /* 0x800CF520 */
    R[5] = 0x800Fu << 16;  /* 0x800CF524 */
    R[5] = R[5] - 220;  /* 0x800CF528 */
    R[6] = R[16] + R[0];  /* 0x800CF52C */
    R[2] = R[0] + 2;  /* 0x800CF530 */
    { R[31] = 0x800CF53Cu; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CF534 jal */
    R[2] = R[0] + 4;  /* 0x800CF53C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF540 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF544 */
L_800CF548:;
    R[2] = R[0] + 3;  /* 0x800CF548 */
    { sb_(R[17] + 786, R[2]); goto L_800CF798; }  /* 0x800CF54C j */
L_800CF554:;
    R[2] = R[0] + 8;  /* 0x800CF554 */
    sb_(R[18] + 3, R[2]);  /* 0x800CF558 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF55C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF560 */
    R[5] = R[0] + 5;  /* 0x800CF564 */
    R[2] = R[2] - R[3];  /* 0x800CF568 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF56C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF570 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF574 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF578 */
    R[6] = R[0] | 0xA000;  /* 0x800CF57C */
    { R[31] = 0x800CF588u; sb_(R[18] + 53, R[2]); psx_next = 0x800CE35Cu; return; }  /* 0x800CF580 jal */
    { R[31] = 0x800CF590u; R[4] = R[17] + R[0]; psx_next = 0x800CDCACu; return; }  /* 0x800CF588 jal */
    { R[31] = 0x800CF598u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CF590 jal */
    { goto L_800CF798; }  /* 0x800CF598 j */
    R[5] = R[0] + 1;  /* 0x800CF5A0 */
    R[6] = R[5] + R[0];  /* 0x800CF5A4 */
    R[2] = 0x8014u << 16;  /* 0x800CF5A8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5AC */
    R[18] = R[2] + 15136;  /* 0x800CF5B0 */
    R[4] = R[4] << 2;  /* 0x800CF5B4 */
    { R[31] = 0x800CF5C0u; R[4] = R[4] + R[18]; psx_next = 0x800CCF94u; return; }  /* 0x800CF5B8 jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CF5CC; } }  /* 0x800CF5C0 */
    sh_(R[17] + 582, R[0]);  /* 0x800CF5C8 */
L_800CF5CC:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF5CC */
    R[2] = R[2] - 1;  /* 0x800CF5D4 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF5D8 */
    R[2] = R[2] << 16;  /* 0x800CF5DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF5E0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[2] = ((int32_t)R[2] < 9); if (_c) { goto L_800CF630; } }  /* 0x800CF5E4 */
    R[5] = R[0] + 1;  /* 0x800CF5EC */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5F0 */
    R[6] = R[5] + R[0];  /* 0x800CF5F4 */
    R[4] = R[4] << 2;  /* 0x800CF5F8 */
    { R[31] = 0x800CF604u; R[4] = R[4] + R[18]; psx_next = 0x800CD028u; return; }  /* 0x800CF5FC jal */
    R[2] = 0x800Fu << 16;  /* 0x800CF604 */
    R[3] = lw_(R[17] + 588);  /* 0x800CF608 */
    R[2] = R[2] - 416;  /* 0x800CF60C */
    sw_(R[17] + 608, R[0]);  /* 0x800CF610 */
    sh_(R[17] + 14, R[0]);  /* 0x800CF614 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF618 */
    R[2] = lb_(R[3] + 2);  /* 0x800CF61C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF620 */
    sh_(R[17] + 586, R[16]);  /* 0x800CF624 */
    { sb_(R[17] + 801, R[2]); goto L_800CF68C; }  /* 0x800CF628 j */
L_800CF630:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF68C; } }  /* 0x800CF630 */
    R[2] = lh_(R[17] + 592);  /* 0x800CF638 */
    R[2] = R[2] + 1;  /* 0x800CF640 */
    sh_(R[17] + 592, R[2]);  /* 0x800CF644 */
    R[2] = R[2] << 16;  /* 0x800CF648 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF64C */
    R[2] = ((int32_t)R[2] < 2);  /* 0x800CF650 */
    { uint32_t _c = (R[2] != R[0]); R[7] = R[0] + 2; if (_c) { goto L_800CF68C; } }  /* 0x800CF654 */
    R[4] = 0x800Fu << 16;  /* 0x800CF65C */
    R[4] = R[4] - 220;  /* 0x800CF660 */
    R[6] = 0x8014u << 16;  /* 0x800CF664 */
    R[5] = lw_(R[17] + 588);  /* 0x800CF668 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF66C */
    R[6] = R[6] + 15160;  /* 0x800CF670 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF674 */
    R[2] = R[3] << 3;  /* 0x800CF678 */
    R[2] = R[2] + R[3];  /* 0x800CF67C */
    R[2] = R[2] << 7;  /* 0x800CF680 */
    { R[31] = 0x800CF68Cu; R[6] = R[2] + R[6]; psx_next = 0x800CEF90u; return; }  /* 0x800CF684 jal */
L_800CF68C:;
    R[5] = lw_(R[17] + 588);  /* 0x800CF68C */
    { R[31] = 0x800CF698u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CF690 jal */
    R[4] = 0x8014u << 16;  /* 0x800CF698 */
    R[4] = R[4] + 15160;  /* 0x800CF69C */
    R[3] = lb_(R[17] + 585);  /* 0x800CF6A0 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 594);  /* 0x800CF6A4 */
    R[2] = R[3] << 3;  /* 0x800CF6A8 */
    R[2] = R[2] + R[3];  /* 0x800CF6AC */
    R[2] = R[2] << 7;  /* 0x800CF6B0 */
    { R[31] = 0x800CF6BCu; R[4] = R[2] + R[4]; psx_next = 0x800CF118u; return; }  /* 0x800CF6B4 jal */
    { goto L_800CF798; }  /* 0x800CF6BC j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF410(void) {
    R[19] = R[2] + R[0];  /* 0x800CF410 */
    { uint32_t _c = ((int32_t)R[19] <= 0); if (_c) { goto L_800CF51C; } }  /* 0x800CF414 */
    { R[31] = 0x800CF424u; R[4] = R[0] + 56; psx_next = 0x8002DB10u; return; }  /* 0x800CF41C jal */
    sb_(R[17] + 584, R[20]);  /* 0x800CF424 */
    sw_(R[17] + 124, R[0]);  /* 0x800CF428 */
    sw_(R[17] + 188, R[0]);  /* 0x800CF42C */
    R[2] = lw_(R[16]);  /* 0x800CF430 */
    R[2] = lw_(R[2] + 24);  /* 0x800CF438 */
    sw_(R[17] + 24, R[2]);  /* 0x800CF440 */
    R[2] = lw_(R[16]);  /* 0x800CF444 */
    R[2] = lw_(R[2] + 28);  /* 0x800CF44C */
    sw_(R[17] + 28, R[2]);  /* 0x800CF454 */
    R[2] = lw_(R[16]);  /* 0x800CF458 */
    R[6] = lb_(R[17] + 585);  /* 0x800CF45C */
    R[2] = lw_(R[2] + 32);  /* 0x800CF460 */
    R[5] = 0x800Fu << 16;  /* 0x800CF464 */
    sw_(R[17] + 32, R[2]);  /* 0x800CF468 */
    R[4] = lw_(R[16]);  /* 0x800CF46C */
    { R[31] = 0x800CF478u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CF470 jal */
    R[4] = 0x800Fu << 16;  /* 0x800CF478 */
    R[4] = R[4] - 220;  /* 0x800CF47C */
    R[6] = R[18] + R[0];  /* 0x800CF480 */
    R[5] = lw_(R[16]);  /* 0x800CF484 */
    { R[31] = 0x800CF490u; R[7] = R[0] + 2; psx_next = 0x800CEF90u; return; }  /* 0x800CF488 jal */
    sh_(R[17] + 594, R[2]);  /* 0x800CF490 */
    R[3] = lw_(R[16]);  /* 0x800CF494 */
    R[4] = R[0] + 16;  /* 0x800CF498 */
    R[2] = lb_(R[3] + 789);  /* 0x800CF49C */
    R[6] = 0x8011u << 16;  /* 0x800CF4A0 */
    R[2] = R[2] | 0x2;  /* 0x800CF4A4 */
    sb_(R[3] + 789, R[2]);  /* 0x800CF4A8 */
    R[5] = lw_(R[16]);  /* 0x800CF4AC */
    { R[31] = 0x800CF4B8u; R[6] = R[6] + 30196; psx_next = 0x800AC93Cu; return; }  /* 0x800CF4B0 jal */
    R[4] = lw_(R[16]);  /* 0x800CF4B8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CF4C0 */
    R[3] = R[0] - 897;  /* 0x800CF4C4 */
    R[2] = R[2] & R[3];  /* 0x800CF4C8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CF4CC */
    R[3] = lw_(R[16]);  /* 0x800CF4D0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CF4D8 */
    R[2] = R[2] | 0x180;  /* 0x800CF4E0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CF4E4 */
    R[2] = R[0] + 15;  /* 0x800CF4E8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CF4EC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF4F0 */
    R[2] = lw_(R[16]);  /* 0x800CF4F4 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF4F8 */
    sw_(R[17] + 608, R[19]);  /* 0x800CF4FC */
    sh_(R[17] + 586, R[20]);  /* 0x800CF500 */
    { sw_(R[17] + 588, R[2]); goto L_800CF548; }  /* 0x800CF504 j */
    R[2] = lb_(R[17] + 785);  /* 0x800CF50C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800CF554; } }  /* 0x800CF514 */
L_800CF51C:;
    R[16] = R[0] + 8;  /* 0x800CF51C */
    R[4] = R[17] + R[0];  /* 0x800CF520 */
    R[5] = 0x800Fu << 16;  /* 0x800CF524 */
    R[5] = R[5] - 220;  /* 0x800CF528 */
    R[6] = R[16] + R[0];  /* 0x800CF52C */
    R[2] = R[0] + 2;  /* 0x800CF530 */
    { R[31] = 0x800CF53Cu; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CF534 jal */
    R[2] = R[0] + 4;  /* 0x800CF53C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF540 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF544 */
L_800CF548:;
    R[2] = R[0] + 3;  /* 0x800CF548 */
    { sb_(R[17] + 786, R[2]); goto L_800CF798; }  /* 0x800CF54C j */
L_800CF554:;
    R[2] = R[0] + 8;  /* 0x800CF554 */
    sb_(R[18] + 3, R[2]);  /* 0x800CF558 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF55C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF560 */
    R[5] = R[0] + 5;  /* 0x800CF564 */
    R[2] = R[2] - R[3];  /* 0x800CF568 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF56C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF570 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF574 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF578 */
    R[6] = R[0] | 0xA000;  /* 0x800CF57C */
    { R[31] = 0x800CF588u; sb_(R[18] + 53, R[2]); psx_next = 0x800CE35Cu; return; }  /* 0x800CF580 jal */
    { R[31] = 0x800CF590u; R[4] = R[17] + R[0]; psx_next = 0x800CDCACu; return; }  /* 0x800CF588 jal */
    { R[31] = 0x800CF598u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CF590 jal */
    { goto L_800CF798; }  /* 0x800CF598 j */
    R[5] = R[0] + 1;  /* 0x800CF5A0 */
    R[6] = R[5] + R[0];  /* 0x800CF5A4 */
    R[2] = 0x8014u << 16;  /* 0x800CF5A8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5AC */
    R[18] = R[2] + 15136;  /* 0x800CF5B0 */
    R[4] = R[4] << 2;  /* 0x800CF5B4 */
    { R[31] = 0x800CF5C0u; R[4] = R[4] + R[18]; psx_next = 0x800CCF94u; return; }  /* 0x800CF5B8 jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CF5CC; } }  /* 0x800CF5C0 */
    sh_(R[17] + 582, R[0]);  /* 0x800CF5C8 */
L_800CF5CC:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF5CC */
    R[2] = R[2] - 1;  /* 0x800CF5D4 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF5D8 */
    R[2] = R[2] << 16;  /* 0x800CF5DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF5E0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[2] = ((int32_t)R[2] < 9); if (_c) { goto L_800CF630; } }  /* 0x800CF5E4 */
    R[5] = R[0] + 1;  /* 0x800CF5EC */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5F0 */
    R[6] = R[5] + R[0];  /* 0x800CF5F4 */
    R[4] = R[4] << 2;  /* 0x800CF5F8 */
    { R[31] = 0x800CF604u; R[4] = R[4] + R[18]; psx_next = 0x800CD028u; return; }  /* 0x800CF5FC jal */
    R[2] = 0x800Fu << 16;  /* 0x800CF604 */
    R[3] = lw_(R[17] + 588);  /* 0x800CF608 */
    R[2] = R[2] - 416;  /* 0x800CF60C */
    sw_(R[17] + 608, R[0]);  /* 0x800CF610 */
    sh_(R[17] + 14, R[0]);  /* 0x800CF614 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF618 */
    R[2] = lb_(R[3] + 2);  /* 0x800CF61C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF620 */
    sh_(R[17] + 586, R[16]);  /* 0x800CF624 */
    { sb_(R[17] + 801, R[2]); goto L_800CF68C; }  /* 0x800CF628 j */
L_800CF630:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF68C; } }  /* 0x800CF630 */
    R[2] = lh_(R[17] + 592);  /* 0x800CF638 */
    R[2] = R[2] + 1;  /* 0x800CF640 */
    sh_(R[17] + 592, R[2]);  /* 0x800CF644 */
    R[2] = R[2] << 16;  /* 0x800CF648 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF64C */
    R[2] = ((int32_t)R[2] < 2);  /* 0x800CF650 */
    { uint32_t _c = (R[2] != R[0]); R[7] = R[0] + 2; if (_c) { goto L_800CF68C; } }  /* 0x800CF654 */
    R[4] = 0x800Fu << 16;  /* 0x800CF65C */
    R[4] = R[4] - 220;  /* 0x800CF660 */
    R[6] = 0x8014u << 16;  /* 0x800CF664 */
    R[5] = lw_(R[17] + 588);  /* 0x800CF668 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF66C */
    R[6] = R[6] + 15160;  /* 0x800CF670 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF674 */
    R[2] = R[3] << 3;  /* 0x800CF678 */
    R[2] = R[2] + R[3];  /* 0x800CF67C */
    R[2] = R[2] << 7;  /* 0x800CF680 */
    { R[31] = 0x800CF68Cu; R[6] = R[2] + R[6]; psx_next = 0x800CEF90u; return; }  /* 0x800CF684 jal */
L_800CF68C:;
    R[5] = lw_(R[17] + 588);  /* 0x800CF68C */
    { R[31] = 0x800CF698u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CF690 jal */
    R[4] = 0x8014u << 16;  /* 0x800CF698 */
    R[4] = R[4] + 15160;  /* 0x800CF69C */
    R[3] = lb_(R[17] + 585);  /* 0x800CF6A0 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 594);  /* 0x800CF6A4 */
    R[2] = R[3] << 3;  /* 0x800CF6A8 */
    R[2] = R[2] + R[3];  /* 0x800CF6AC */
    R[2] = R[2] << 7;  /* 0x800CF6B0 */
    { R[31] = 0x800CF6BCu; R[4] = R[2] + R[4]; psx_next = 0x800CF118u; return; }  /* 0x800CF6B4 jal */
    { goto L_800CF798; }  /* 0x800CF6BC j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF424(void) {
    sb_(R[17] + 584, R[20]);  /* 0x800CF424 */
    sw_(R[17] + 124, R[0]);  /* 0x800CF428 */
    sw_(R[17] + 188, R[0]);  /* 0x800CF42C */
    R[2] = lw_(R[16]);  /* 0x800CF430 */
    R[2] = lw_(R[2] + 24);  /* 0x800CF438 */
    sw_(R[17] + 24, R[2]);  /* 0x800CF440 */
    R[2] = lw_(R[16]);  /* 0x800CF444 */
    R[2] = lw_(R[2] + 28);  /* 0x800CF44C */
    sw_(R[17] + 28, R[2]);  /* 0x800CF454 */
    R[2] = lw_(R[16]);  /* 0x800CF458 */
    R[6] = lb_(R[17] + 585);  /* 0x800CF45C */
    R[2] = lw_(R[2] + 32);  /* 0x800CF460 */
    R[5] = 0x800Fu << 16;  /* 0x800CF464 */
    sw_(R[17] + 32, R[2]);  /* 0x800CF468 */
    R[4] = lw_(R[16]);  /* 0x800CF46C */
    { R[31] = 0x800CF478u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CF470 jal */
    R[4] = 0x800Fu << 16;  /* 0x800CF478 */
    R[4] = R[4] - 220;  /* 0x800CF47C */
    R[6] = R[18] + R[0];  /* 0x800CF480 */
    R[5] = lw_(R[16]);  /* 0x800CF484 */
    { R[31] = 0x800CF490u; R[7] = R[0] + 2; psx_next = 0x800CEF90u; return; }  /* 0x800CF488 jal */
    sh_(R[17] + 594, R[2]);  /* 0x800CF490 */
    R[3] = lw_(R[16]);  /* 0x800CF494 */
    R[4] = R[0] + 16;  /* 0x800CF498 */
    R[2] = lb_(R[3] + 789);  /* 0x800CF49C */
    R[6] = 0x8011u << 16;  /* 0x800CF4A0 */
    R[2] = R[2] | 0x2;  /* 0x800CF4A4 */
    sb_(R[3] + 789, R[2]);  /* 0x800CF4A8 */
    R[5] = lw_(R[16]);  /* 0x800CF4AC */
    { R[31] = 0x800CF4B8u; R[6] = R[6] + 30196; psx_next = 0x800AC93Cu; return; }  /* 0x800CF4B0 jal */
    R[4] = lw_(R[16]);  /* 0x800CF4B8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CF4C0 */
    R[3] = R[0] - 897;  /* 0x800CF4C4 */
    R[2] = R[2] & R[3];  /* 0x800CF4C8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CF4CC */
    R[3] = lw_(R[16]);  /* 0x800CF4D0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CF4D8 */
    R[2] = R[2] | 0x180;  /* 0x800CF4E0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CF4E4 */
    R[2] = R[0] + 15;  /* 0x800CF4E8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CF4EC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF4F0 */
    R[2] = lw_(R[16]);  /* 0x800CF4F4 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF4F8 */
    sw_(R[17] + 608, R[19]);  /* 0x800CF4FC */
    sh_(R[17] + 586, R[20]);  /* 0x800CF500 */
    { sw_(R[17] + 588, R[2]); goto L_800CF548; }  /* 0x800CF504 j */
    R[2] = lb_(R[17] + 785);  /* 0x800CF50C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800CF554; } }  /* 0x800CF514 */
    R[16] = R[0] + 8;  /* 0x800CF51C */
    R[4] = R[17] + R[0];  /* 0x800CF520 */
    R[5] = 0x800Fu << 16;  /* 0x800CF524 */
    R[5] = R[5] - 220;  /* 0x800CF528 */
    R[6] = R[16] + R[0];  /* 0x800CF52C */
    R[2] = R[0] + 2;  /* 0x800CF530 */
    { R[31] = 0x800CF53Cu; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CF534 jal */
    R[2] = R[0] + 4;  /* 0x800CF53C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF540 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF544 */
L_800CF548:;
    R[2] = R[0] + 3;  /* 0x800CF548 */
    { sb_(R[17] + 786, R[2]); goto L_800CF798; }  /* 0x800CF54C j */
L_800CF554:;
    R[2] = R[0] + 8;  /* 0x800CF554 */
    sb_(R[18] + 3, R[2]);  /* 0x800CF558 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF55C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF560 */
    R[5] = R[0] + 5;  /* 0x800CF564 */
    R[2] = R[2] - R[3];  /* 0x800CF568 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF56C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF570 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF574 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF578 */
    R[6] = R[0] | 0xA000;  /* 0x800CF57C */
    { R[31] = 0x800CF588u; sb_(R[18] + 53, R[2]); psx_next = 0x800CE35Cu; return; }  /* 0x800CF580 jal */
    { R[31] = 0x800CF590u; R[4] = R[17] + R[0]; psx_next = 0x800CDCACu; return; }  /* 0x800CF588 jal */
    { R[31] = 0x800CF598u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CF590 jal */
    { goto L_800CF798; }  /* 0x800CF598 j */
    R[5] = R[0] + 1;  /* 0x800CF5A0 */
    R[6] = R[5] + R[0];  /* 0x800CF5A4 */
    R[2] = 0x8014u << 16;  /* 0x800CF5A8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5AC */
    R[18] = R[2] + 15136;  /* 0x800CF5B0 */
    R[4] = R[4] << 2;  /* 0x800CF5B4 */
    { R[31] = 0x800CF5C0u; R[4] = R[4] + R[18]; psx_next = 0x800CCF94u; return; }  /* 0x800CF5B8 jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CF5CC; } }  /* 0x800CF5C0 */
    sh_(R[17] + 582, R[0]);  /* 0x800CF5C8 */
L_800CF5CC:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF5CC */
    R[2] = R[2] - 1;  /* 0x800CF5D4 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF5D8 */
    R[2] = R[2] << 16;  /* 0x800CF5DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF5E0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[2] = ((int32_t)R[2] < 9); if (_c) { goto L_800CF630; } }  /* 0x800CF5E4 */
    R[5] = R[0] + 1;  /* 0x800CF5EC */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5F0 */
    R[6] = R[5] + R[0];  /* 0x800CF5F4 */
    R[4] = R[4] << 2;  /* 0x800CF5F8 */
    { R[31] = 0x800CF604u; R[4] = R[4] + R[18]; psx_next = 0x800CD028u; return; }  /* 0x800CF5FC jal */
    R[2] = 0x800Fu << 16;  /* 0x800CF604 */
    R[3] = lw_(R[17] + 588);  /* 0x800CF608 */
    R[2] = R[2] - 416;  /* 0x800CF60C */
    sw_(R[17] + 608, R[0]);  /* 0x800CF610 */
    sh_(R[17] + 14, R[0]);  /* 0x800CF614 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF618 */
    R[2] = lb_(R[3] + 2);  /* 0x800CF61C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF620 */
    sh_(R[17] + 586, R[16]);  /* 0x800CF624 */
    { sb_(R[17] + 801, R[2]); goto L_800CF68C; }  /* 0x800CF628 j */
L_800CF630:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF68C; } }  /* 0x800CF630 */
    R[2] = lh_(R[17] + 592);  /* 0x800CF638 */
    R[2] = R[2] + 1;  /* 0x800CF640 */
    sh_(R[17] + 592, R[2]);  /* 0x800CF644 */
    R[2] = R[2] << 16;  /* 0x800CF648 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF64C */
    R[2] = ((int32_t)R[2] < 2);  /* 0x800CF650 */
    { uint32_t _c = (R[2] != R[0]); R[7] = R[0] + 2; if (_c) { goto L_800CF68C; } }  /* 0x800CF654 */
    R[4] = 0x800Fu << 16;  /* 0x800CF65C */
    R[4] = R[4] - 220;  /* 0x800CF660 */
    R[6] = 0x8014u << 16;  /* 0x800CF664 */
    R[5] = lw_(R[17] + 588);  /* 0x800CF668 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF66C */
    R[6] = R[6] + 15160;  /* 0x800CF670 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF674 */
    R[2] = R[3] << 3;  /* 0x800CF678 */
    R[2] = R[2] + R[3];  /* 0x800CF67C */
    R[2] = R[2] << 7;  /* 0x800CF680 */
    { R[31] = 0x800CF68Cu; R[6] = R[2] + R[6]; psx_next = 0x800CEF90u; return; }  /* 0x800CF684 jal */
L_800CF68C:;
    R[5] = lw_(R[17] + 588);  /* 0x800CF68C */
    { R[31] = 0x800CF698u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CF690 jal */
    R[4] = 0x8014u << 16;  /* 0x800CF698 */
    R[4] = R[4] + 15160;  /* 0x800CF69C */
    R[3] = lb_(R[17] + 585);  /* 0x800CF6A0 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 594);  /* 0x800CF6A4 */
    R[2] = R[3] << 3;  /* 0x800CF6A8 */
    R[2] = R[2] + R[3];  /* 0x800CF6AC */
    R[2] = R[2] << 7;  /* 0x800CF6B0 */
    { R[31] = 0x800CF6BCu; R[4] = R[2] + R[4]; psx_next = 0x800CF118u; return; }  /* 0x800CF6B4 jal */
    { goto L_800CF798; }  /* 0x800CF6BC j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF478(void) {
    R[4] = 0x800Fu << 16;  /* 0x800CF478 */
    R[4] = R[4] - 220;  /* 0x800CF47C */
    R[6] = R[18] + R[0];  /* 0x800CF480 */
    R[5] = lw_(R[16]);  /* 0x800CF484 */
    { R[31] = 0x800CF490u; R[7] = R[0] + 2; psx_next = 0x800CEF90u; return; }  /* 0x800CF488 jal */
    sh_(R[17] + 594, R[2]);  /* 0x800CF490 */
    R[3] = lw_(R[16]);  /* 0x800CF494 */
    R[4] = R[0] + 16;  /* 0x800CF498 */
    R[2] = lb_(R[3] + 789);  /* 0x800CF49C */
    R[6] = 0x8011u << 16;  /* 0x800CF4A0 */
    R[2] = R[2] | 0x2;  /* 0x800CF4A4 */
    sb_(R[3] + 789, R[2]);  /* 0x800CF4A8 */
    R[5] = lw_(R[16]);  /* 0x800CF4AC */
    { R[31] = 0x800CF4B8u; R[6] = R[6] + 30196; psx_next = 0x800AC93Cu; return; }  /* 0x800CF4B0 jal */
    R[4] = lw_(R[16]);  /* 0x800CF4B8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CF4C0 */
    R[3] = R[0] - 897;  /* 0x800CF4C4 */
    R[2] = R[2] & R[3];  /* 0x800CF4C8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CF4CC */
    R[3] = lw_(R[16]);  /* 0x800CF4D0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CF4D8 */
    R[2] = R[2] | 0x180;  /* 0x800CF4E0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CF4E4 */
    R[2] = R[0] + 15;  /* 0x800CF4E8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CF4EC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF4F0 */
    R[2] = lw_(R[16]);  /* 0x800CF4F4 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF4F8 */
    sw_(R[17] + 608, R[19]);  /* 0x800CF4FC */
    sh_(R[17] + 586, R[20]);  /* 0x800CF500 */
    { sw_(R[17] + 588, R[2]); goto L_800CF548; }  /* 0x800CF504 j */
    R[2] = lb_(R[17] + 785);  /* 0x800CF50C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800CF554; } }  /* 0x800CF514 */
    R[16] = R[0] + 8;  /* 0x800CF51C */
    R[4] = R[17] + R[0];  /* 0x800CF520 */
    R[5] = 0x800Fu << 16;  /* 0x800CF524 */
    R[5] = R[5] - 220;  /* 0x800CF528 */
    R[6] = R[16] + R[0];  /* 0x800CF52C */
    R[2] = R[0] + 2;  /* 0x800CF530 */
    { R[31] = 0x800CF53Cu; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CF534 jal */
    R[2] = R[0] + 4;  /* 0x800CF53C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF540 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF544 */
L_800CF548:;
    R[2] = R[0] + 3;  /* 0x800CF548 */
    { sb_(R[17] + 786, R[2]); goto L_800CF798; }  /* 0x800CF54C j */
L_800CF554:;
    R[2] = R[0] + 8;  /* 0x800CF554 */
    sb_(R[18] + 3, R[2]);  /* 0x800CF558 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF55C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF560 */
    R[5] = R[0] + 5;  /* 0x800CF564 */
    R[2] = R[2] - R[3];  /* 0x800CF568 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF56C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF570 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF574 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF578 */
    R[6] = R[0] | 0xA000;  /* 0x800CF57C */
    { R[31] = 0x800CF588u; sb_(R[18] + 53, R[2]); psx_next = 0x800CE35Cu; return; }  /* 0x800CF580 jal */
    { R[31] = 0x800CF590u; R[4] = R[17] + R[0]; psx_next = 0x800CDCACu; return; }  /* 0x800CF588 jal */
    { R[31] = 0x800CF598u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CF590 jal */
    { goto L_800CF798; }  /* 0x800CF598 j */
    R[5] = R[0] + 1;  /* 0x800CF5A0 */
    R[6] = R[5] + R[0];  /* 0x800CF5A4 */
    R[2] = 0x8014u << 16;  /* 0x800CF5A8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5AC */
    R[18] = R[2] + 15136;  /* 0x800CF5B0 */
    R[4] = R[4] << 2;  /* 0x800CF5B4 */
    { R[31] = 0x800CF5C0u; R[4] = R[4] + R[18]; psx_next = 0x800CCF94u; return; }  /* 0x800CF5B8 jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CF5CC; } }  /* 0x800CF5C0 */
    sh_(R[17] + 582, R[0]);  /* 0x800CF5C8 */
L_800CF5CC:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF5CC */
    R[2] = R[2] - 1;  /* 0x800CF5D4 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF5D8 */
    R[2] = R[2] << 16;  /* 0x800CF5DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF5E0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[2] = ((int32_t)R[2] < 9); if (_c) { goto L_800CF630; } }  /* 0x800CF5E4 */
    R[5] = R[0] + 1;  /* 0x800CF5EC */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5F0 */
    R[6] = R[5] + R[0];  /* 0x800CF5F4 */
    R[4] = R[4] << 2;  /* 0x800CF5F8 */
    { R[31] = 0x800CF604u; R[4] = R[4] + R[18]; psx_next = 0x800CD028u; return; }  /* 0x800CF5FC jal */
    R[2] = 0x800Fu << 16;  /* 0x800CF604 */
    R[3] = lw_(R[17] + 588);  /* 0x800CF608 */
    R[2] = R[2] - 416;  /* 0x800CF60C */
    sw_(R[17] + 608, R[0]);  /* 0x800CF610 */
    sh_(R[17] + 14, R[0]);  /* 0x800CF614 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF618 */
    R[2] = lb_(R[3] + 2);  /* 0x800CF61C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF620 */
    sh_(R[17] + 586, R[16]);  /* 0x800CF624 */
    { sb_(R[17] + 801, R[2]); goto L_800CF68C; }  /* 0x800CF628 j */
L_800CF630:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF68C; } }  /* 0x800CF630 */
    R[2] = lh_(R[17] + 592);  /* 0x800CF638 */
    R[2] = R[2] + 1;  /* 0x800CF640 */
    sh_(R[17] + 592, R[2]);  /* 0x800CF644 */
    R[2] = R[2] << 16;  /* 0x800CF648 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF64C */
    R[2] = ((int32_t)R[2] < 2);  /* 0x800CF650 */
    { uint32_t _c = (R[2] != R[0]); R[7] = R[0] + 2; if (_c) { goto L_800CF68C; } }  /* 0x800CF654 */
    R[4] = 0x800Fu << 16;  /* 0x800CF65C */
    R[4] = R[4] - 220;  /* 0x800CF660 */
    R[6] = 0x8014u << 16;  /* 0x800CF664 */
    R[5] = lw_(R[17] + 588);  /* 0x800CF668 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF66C */
    R[6] = R[6] + 15160;  /* 0x800CF670 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF674 */
    R[2] = R[3] << 3;  /* 0x800CF678 */
    R[2] = R[2] + R[3];  /* 0x800CF67C */
    R[2] = R[2] << 7;  /* 0x800CF680 */
    { R[31] = 0x800CF68Cu; R[6] = R[2] + R[6]; psx_next = 0x800CEF90u; return; }  /* 0x800CF684 jal */
L_800CF68C:;
    R[5] = lw_(R[17] + 588);  /* 0x800CF68C */
    { R[31] = 0x800CF698u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CF690 jal */
    R[4] = 0x8014u << 16;  /* 0x800CF698 */
    R[4] = R[4] + 15160;  /* 0x800CF69C */
    R[3] = lb_(R[17] + 585);  /* 0x800CF6A0 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 594);  /* 0x800CF6A4 */
    R[2] = R[3] << 3;  /* 0x800CF6A8 */
    R[2] = R[2] + R[3];  /* 0x800CF6AC */
    R[2] = R[2] << 7;  /* 0x800CF6B0 */
    { R[31] = 0x800CF6BCu; R[4] = R[2] + R[4]; psx_next = 0x800CF118u; return; }  /* 0x800CF6B4 jal */
    { goto L_800CF798; }  /* 0x800CF6BC j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF490(void) {
    sh_(R[17] + 594, R[2]);  /* 0x800CF490 */
    R[3] = lw_(R[16]);  /* 0x800CF494 */
    R[4] = R[0] + 16;  /* 0x800CF498 */
    R[2] = lb_(R[3] + 789);  /* 0x800CF49C */
    R[6] = 0x8011u << 16;  /* 0x800CF4A0 */
    R[2] = R[2] | 0x2;  /* 0x800CF4A4 */
    sb_(R[3] + 789, R[2]);  /* 0x800CF4A8 */
    R[5] = lw_(R[16]);  /* 0x800CF4AC */
    { R[31] = 0x800CF4B8u; R[6] = R[6] + 30196; psx_next = 0x800AC93Cu; return; }  /* 0x800CF4B0 jal */
    R[4] = lw_(R[16]);  /* 0x800CF4B8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CF4C0 */
    R[3] = R[0] - 897;  /* 0x800CF4C4 */
    R[2] = R[2] & R[3];  /* 0x800CF4C8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CF4CC */
    R[3] = lw_(R[16]);  /* 0x800CF4D0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CF4D8 */
    R[2] = R[2] | 0x180;  /* 0x800CF4E0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CF4E4 */
    R[2] = R[0] + 15;  /* 0x800CF4E8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CF4EC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF4F0 */
    R[2] = lw_(R[16]);  /* 0x800CF4F4 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF4F8 */
    sw_(R[17] + 608, R[19]);  /* 0x800CF4FC */
    sh_(R[17] + 586, R[20]);  /* 0x800CF500 */
    { sw_(R[17] + 588, R[2]); goto L_800CF548; }  /* 0x800CF504 j */
    R[2] = lb_(R[17] + 785);  /* 0x800CF50C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800CF554; } }  /* 0x800CF514 */
    R[16] = R[0] + 8;  /* 0x800CF51C */
    R[4] = R[17] + R[0];  /* 0x800CF520 */
    R[5] = 0x800Fu << 16;  /* 0x800CF524 */
    R[5] = R[5] - 220;  /* 0x800CF528 */
    R[6] = R[16] + R[0];  /* 0x800CF52C */
    R[2] = R[0] + 2;  /* 0x800CF530 */
    { R[31] = 0x800CF53Cu; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CF534 jal */
    R[2] = R[0] + 4;  /* 0x800CF53C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF540 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF544 */
L_800CF548:;
    R[2] = R[0] + 3;  /* 0x800CF548 */
    { sb_(R[17] + 786, R[2]); goto L_800CF798; }  /* 0x800CF54C j */
L_800CF554:;
    R[2] = R[0] + 8;  /* 0x800CF554 */
    sb_(R[18] + 3, R[2]);  /* 0x800CF558 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF55C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF560 */
    R[5] = R[0] + 5;  /* 0x800CF564 */
    R[2] = R[2] - R[3];  /* 0x800CF568 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF56C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF570 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF574 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF578 */
    R[6] = R[0] | 0xA000;  /* 0x800CF57C */
    { R[31] = 0x800CF588u; sb_(R[18] + 53, R[2]); psx_next = 0x800CE35Cu; return; }  /* 0x800CF580 jal */
    { R[31] = 0x800CF590u; R[4] = R[17] + R[0]; psx_next = 0x800CDCACu; return; }  /* 0x800CF588 jal */
    { R[31] = 0x800CF598u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CF590 jal */
    { goto L_800CF798; }  /* 0x800CF598 j */
    R[5] = R[0] + 1;  /* 0x800CF5A0 */
    R[6] = R[5] + R[0];  /* 0x800CF5A4 */
    R[2] = 0x8014u << 16;  /* 0x800CF5A8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5AC */
    R[18] = R[2] + 15136;  /* 0x800CF5B0 */
    R[4] = R[4] << 2;  /* 0x800CF5B4 */
    { R[31] = 0x800CF5C0u; R[4] = R[4] + R[18]; psx_next = 0x800CCF94u; return; }  /* 0x800CF5B8 jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CF5CC; } }  /* 0x800CF5C0 */
    sh_(R[17] + 582, R[0]);  /* 0x800CF5C8 */
L_800CF5CC:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF5CC */
    R[2] = R[2] - 1;  /* 0x800CF5D4 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF5D8 */
    R[2] = R[2] << 16;  /* 0x800CF5DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF5E0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[2] = ((int32_t)R[2] < 9); if (_c) { goto L_800CF630; } }  /* 0x800CF5E4 */
    R[5] = R[0] + 1;  /* 0x800CF5EC */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5F0 */
    R[6] = R[5] + R[0];  /* 0x800CF5F4 */
    R[4] = R[4] << 2;  /* 0x800CF5F8 */
    { R[31] = 0x800CF604u; R[4] = R[4] + R[18]; psx_next = 0x800CD028u; return; }  /* 0x800CF5FC jal */
    R[2] = 0x800Fu << 16;  /* 0x800CF604 */
    R[3] = lw_(R[17] + 588);  /* 0x800CF608 */
    R[2] = R[2] - 416;  /* 0x800CF60C */
    sw_(R[17] + 608, R[0]);  /* 0x800CF610 */
    sh_(R[17] + 14, R[0]);  /* 0x800CF614 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF618 */
    R[2] = lb_(R[3] + 2);  /* 0x800CF61C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF620 */
    sh_(R[17] + 586, R[16]);  /* 0x800CF624 */
    { sb_(R[17] + 801, R[2]); goto L_800CF68C; }  /* 0x800CF628 j */
L_800CF630:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF68C; } }  /* 0x800CF630 */
    R[2] = lh_(R[17] + 592);  /* 0x800CF638 */
    R[2] = R[2] + 1;  /* 0x800CF640 */
    sh_(R[17] + 592, R[2]);  /* 0x800CF644 */
    R[2] = R[2] << 16;  /* 0x800CF648 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF64C */
    R[2] = ((int32_t)R[2] < 2);  /* 0x800CF650 */
    { uint32_t _c = (R[2] != R[0]); R[7] = R[0] + 2; if (_c) { goto L_800CF68C; } }  /* 0x800CF654 */
    R[4] = 0x800Fu << 16;  /* 0x800CF65C */
    R[4] = R[4] - 220;  /* 0x800CF660 */
    R[6] = 0x8014u << 16;  /* 0x800CF664 */
    R[5] = lw_(R[17] + 588);  /* 0x800CF668 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF66C */
    R[6] = R[6] + 15160;  /* 0x800CF670 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF674 */
    R[2] = R[3] << 3;  /* 0x800CF678 */
    R[2] = R[2] + R[3];  /* 0x800CF67C */
    R[2] = R[2] << 7;  /* 0x800CF680 */
    { R[31] = 0x800CF68Cu; R[6] = R[2] + R[6]; psx_next = 0x800CEF90u; return; }  /* 0x800CF684 jal */
L_800CF68C:;
    R[5] = lw_(R[17] + 588);  /* 0x800CF68C */
    { R[31] = 0x800CF698u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CF690 jal */
    R[4] = 0x8014u << 16;  /* 0x800CF698 */
    R[4] = R[4] + 15160;  /* 0x800CF69C */
    R[3] = lb_(R[17] + 585);  /* 0x800CF6A0 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 594);  /* 0x800CF6A4 */
    R[2] = R[3] << 3;  /* 0x800CF6A8 */
    R[2] = R[2] + R[3];  /* 0x800CF6AC */
    R[2] = R[2] << 7;  /* 0x800CF6B0 */
    { R[31] = 0x800CF6BCu; R[4] = R[2] + R[4]; psx_next = 0x800CF118u; return; }  /* 0x800CF6B4 jal */
    { goto L_800CF798; }  /* 0x800CF6BC j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF4B8(void) {
    R[4] = lw_(R[16]);  /* 0x800CF4B8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CF4C0 */
    R[3] = R[0] - 897;  /* 0x800CF4C4 */
    R[2] = R[2] & R[3];  /* 0x800CF4C8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CF4CC */
    R[3] = lw_(R[16]);  /* 0x800CF4D0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CF4D8 */
    R[2] = R[2] | 0x180;  /* 0x800CF4E0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CF4E4 */
    R[2] = R[0] + 15;  /* 0x800CF4E8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CF4EC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF4F0 */
    R[2] = lw_(R[16]);  /* 0x800CF4F4 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF4F8 */
    sw_(R[17] + 608, R[19]);  /* 0x800CF4FC */
    sh_(R[17] + 586, R[20]);  /* 0x800CF500 */
    { sw_(R[17] + 588, R[2]); goto L_800CF548; }  /* 0x800CF504 j */
    R[2] = lb_(R[17] + 785);  /* 0x800CF50C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800CF554; } }  /* 0x800CF514 */
    R[16] = R[0] + 8;  /* 0x800CF51C */
    R[4] = R[17] + R[0];  /* 0x800CF520 */
    R[5] = 0x800Fu << 16;  /* 0x800CF524 */
    R[5] = R[5] - 220;  /* 0x800CF528 */
    R[6] = R[16] + R[0];  /* 0x800CF52C */
    R[2] = R[0] + 2;  /* 0x800CF530 */
    { R[31] = 0x800CF53Cu; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CF534 jal */
    R[2] = R[0] + 4;  /* 0x800CF53C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF540 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF544 */
L_800CF548:;
    R[2] = R[0] + 3;  /* 0x800CF548 */
    { sb_(R[17] + 786, R[2]); goto L_800CF798; }  /* 0x800CF54C j */
L_800CF554:;
    R[2] = R[0] + 8;  /* 0x800CF554 */
    sb_(R[18] + 3, R[2]);  /* 0x800CF558 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF55C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF560 */
    R[5] = R[0] + 5;  /* 0x800CF564 */
    R[2] = R[2] - R[3];  /* 0x800CF568 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF56C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF570 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF574 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF578 */
    R[6] = R[0] | 0xA000;  /* 0x800CF57C */
    { R[31] = 0x800CF588u; sb_(R[18] + 53, R[2]); psx_next = 0x800CE35Cu; return; }  /* 0x800CF580 jal */
    { R[31] = 0x800CF590u; R[4] = R[17] + R[0]; psx_next = 0x800CDCACu; return; }  /* 0x800CF588 jal */
    { R[31] = 0x800CF598u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CF590 jal */
    { goto L_800CF798; }  /* 0x800CF598 j */
    R[5] = R[0] + 1;  /* 0x800CF5A0 */
    R[6] = R[5] + R[0];  /* 0x800CF5A4 */
    R[2] = 0x8014u << 16;  /* 0x800CF5A8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5AC */
    R[18] = R[2] + 15136;  /* 0x800CF5B0 */
    R[4] = R[4] << 2;  /* 0x800CF5B4 */
    { R[31] = 0x800CF5C0u; R[4] = R[4] + R[18]; psx_next = 0x800CCF94u; return; }  /* 0x800CF5B8 jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CF5CC; } }  /* 0x800CF5C0 */
    sh_(R[17] + 582, R[0]);  /* 0x800CF5C8 */
L_800CF5CC:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF5CC */
    R[2] = R[2] - 1;  /* 0x800CF5D4 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF5D8 */
    R[2] = R[2] << 16;  /* 0x800CF5DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF5E0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[2] = ((int32_t)R[2] < 9); if (_c) { goto L_800CF630; } }  /* 0x800CF5E4 */
    R[5] = R[0] + 1;  /* 0x800CF5EC */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5F0 */
    R[6] = R[5] + R[0];  /* 0x800CF5F4 */
    R[4] = R[4] << 2;  /* 0x800CF5F8 */
    { R[31] = 0x800CF604u; R[4] = R[4] + R[18]; psx_next = 0x800CD028u; return; }  /* 0x800CF5FC jal */
    R[2] = 0x800Fu << 16;  /* 0x800CF604 */
    R[3] = lw_(R[17] + 588);  /* 0x800CF608 */
    R[2] = R[2] - 416;  /* 0x800CF60C */
    sw_(R[17] + 608, R[0]);  /* 0x800CF610 */
    sh_(R[17] + 14, R[0]);  /* 0x800CF614 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF618 */
    R[2] = lb_(R[3] + 2);  /* 0x800CF61C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF620 */
    sh_(R[17] + 586, R[16]);  /* 0x800CF624 */
    { sb_(R[17] + 801, R[2]); goto L_800CF68C; }  /* 0x800CF628 j */
L_800CF630:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF68C; } }  /* 0x800CF630 */
    R[2] = lh_(R[17] + 592);  /* 0x800CF638 */
    R[2] = R[2] + 1;  /* 0x800CF640 */
    sh_(R[17] + 592, R[2]);  /* 0x800CF644 */
    R[2] = R[2] << 16;  /* 0x800CF648 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF64C */
    R[2] = ((int32_t)R[2] < 2);  /* 0x800CF650 */
    { uint32_t _c = (R[2] != R[0]); R[7] = R[0] + 2; if (_c) { goto L_800CF68C; } }  /* 0x800CF654 */
    R[4] = 0x800Fu << 16;  /* 0x800CF65C */
    R[4] = R[4] - 220;  /* 0x800CF660 */
    R[6] = 0x8014u << 16;  /* 0x800CF664 */
    R[5] = lw_(R[17] + 588);  /* 0x800CF668 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF66C */
    R[6] = R[6] + 15160;  /* 0x800CF670 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF674 */
    R[2] = R[3] << 3;  /* 0x800CF678 */
    R[2] = R[2] + R[3];  /* 0x800CF67C */
    R[2] = R[2] << 7;  /* 0x800CF680 */
    { R[31] = 0x800CF68Cu; R[6] = R[2] + R[6]; psx_next = 0x800CEF90u; return; }  /* 0x800CF684 jal */
L_800CF68C:;
    R[5] = lw_(R[17] + 588);  /* 0x800CF68C */
    { R[31] = 0x800CF698u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CF690 jal */
    R[4] = 0x8014u << 16;  /* 0x800CF698 */
    R[4] = R[4] + 15160;  /* 0x800CF69C */
    R[3] = lb_(R[17] + 585);  /* 0x800CF6A0 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 594);  /* 0x800CF6A4 */
    R[2] = R[3] << 3;  /* 0x800CF6A8 */
    R[2] = R[2] + R[3];  /* 0x800CF6AC */
    R[2] = R[2] << 7;  /* 0x800CF6B0 */
    { R[31] = 0x800CF6BCu; R[4] = R[2] + R[4]; psx_next = 0x800CF118u; return; }  /* 0x800CF6B4 jal */
    { goto L_800CF798; }  /* 0x800CF6BC j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF53C(void) {
    R[2] = R[0] + 4;  /* 0x800CF53C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF540 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF544 */
    R[2] = R[0] + 3;  /* 0x800CF548 */
    { sb_(R[17] + 786, R[2]); goto L_800CF798; }  /* 0x800CF54C j */
    R[2] = R[0] + 8;  /* 0x800CF554 */
    sb_(R[18] + 3, R[2]);  /* 0x800CF558 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF55C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF560 */
    R[5] = R[0] + 5;  /* 0x800CF564 */
    R[2] = R[2] - R[3];  /* 0x800CF568 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF56C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF570 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF574 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF578 */
    R[6] = R[0] | 0xA000;  /* 0x800CF57C */
    { R[31] = 0x800CF588u; sb_(R[18] + 53, R[2]); psx_next = 0x800CE35Cu; return; }  /* 0x800CF580 jal */
    { R[31] = 0x800CF590u; R[4] = R[17] + R[0]; psx_next = 0x800CDCACu; return; }  /* 0x800CF588 jal */
    { R[31] = 0x800CF598u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CF590 jal */
    { goto L_800CF798; }  /* 0x800CF598 j */
    R[5] = R[0] + 1;  /* 0x800CF5A0 */
    R[6] = R[5] + R[0];  /* 0x800CF5A4 */
    R[2] = 0x8014u << 16;  /* 0x800CF5A8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5AC */
    R[18] = R[2] + 15136;  /* 0x800CF5B0 */
    R[4] = R[4] << 2;  /* 0x800CF5B4 */
    { R[31] = 0x800CF5C0u; R[4] = R[4] + R[18]; psx_next = 0x800CCF94u; return; }  /* 0x800CF5B8 jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CF5CC; } }  /* 0x800CF5C0 */
    sh_(R[17] + 582, R[0]);  /* 0x800CF5C8 */
L_800CF5CC:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF5CC */
    R[2] = R[2] - 1;  /* 0x800CF5D4 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF5D8 */
    R[2] = R[2] << 16;  /* 0x800CF5DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF5E0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[2] = ((int32_t)R[2] < 9); if (_c) { goto L_800CF630; } }  /* 0x800CF5E4 */
    R[5] = R[0] + 1;  /* 0x800CF5EC */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5F0 */
    R[6] = R[5] + R[0];  /* 0x800CF5F4 */
    R[4] = R[4] << 2;  /* 0x800CF5F8 */
    { R[31] = 0x800CF604u; R[4] = R[4] + R[18]; psx_next = 0x800CD028u; return; }  /* 0x800CF5FC jal */
    R[2] = 0x800Fu << 16;  /* 0x800CF604 */
    R[3] = lw_(R[17] + 588);  /* 0x800CF608 */
    R[2] = R[2] - 416;  /* 0x800CF60C */
    sw_(R[17] + 608, R[0]);  /* 0x800CF610 */
    sh_(R[17] + 14, R[0]);  /* 0x800CF614 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF618 */
    R[2] = lb_(R[3] + 2);  /* 0x800CF61C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF620 */
    sh_(R[17] + 586, R[16]);  /* 0x800CF624 */
    { sb_(R[17] + 801, R[2]); goto L_800CF68C; }  /* 0x800CF628 j */
L_800CF630:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF68C; } }  /* 0x800CF630 */
    R[2] = lh_(R[17] + 592);  /* 0x800CF638 */
    R[2] = R[2] + 1;  /* 0x800CF640 */
    sh_(R[17] + 592, R[2]);  /* 0x800CF644 */
    R[2] = R[2] << 16;  /* 0x800CF648 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF64C */
    R[2] = ((int32_t)R[2] < 2);  /* 0x800CF650 */
    { uint32_t _c = (R[2] != R[0]); R[7] = R[0] + 2; if (_c) { goto L_800CF68C; } }  /* 0x800CF654 */
    R[4] = 0x800Fu << 16;  /* 0x800CF65C */
    R[4] = R[4] - 220;  /* 0x800CF660 */
    R[6] = 0x8014u << 16;  /* 0x800CF664 */
    R[5] = lw_(R[17] + 588);  /* 0x800CF668 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF66C */
    R[6] = R[6] + 15160;  /* 0x800CF670 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF674 */
    R[2] = R[3] << 3;  /* 0x800CF678 */
    R[2] = R[2] + R[3];  /* 0x800CF67C */
    R[2] = R[2] << 7;  /* 0x800CF680 */
    { R[31] = 0x800CF68Cu; R[6] = R[2] + R[6]; psx_next = 0x800CEF90u; return; }  /* 0x800CF684 jal */
L_800CF68C:;
    R[5] = lw_(R[17] + 588);  /* 0x800CF68C */
    { R[31] = 0x800CF698u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CF690 jal */
    R[4] = 0x8014u << 16;  /* 0x800CF698 */
    R[4] = R[4] + 15160;  /* 0x800CF69C */
    R[3] = lb_(R[17] + 585);  /* 0x800CF6A0 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 594);  /* 0x800CF6A4 */
    R[2] = R[3] << 3;  /* 0x800CF6A8 */
    R[2] = R[2] + R[3];  /* 0x800CF6AC */
    R[2] = R[2] << 7;  /* 0x800CF6B0 */
    { R[31] = 0x800CF6BCu; R[4] = R[2] + R[4]; psx_next = 0x800CF118u; return; }  /* 0x800CF6B4 jal */
    { goto L_800CF798; }  /* 0x800CF6BC j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF588(void) {
    { R[31] = 0x800CF590u; R[4] = R[17] + R[0]; psx_next = 0x800CDCACu; return; }  /* 0x800CF588 jal */
    { R[31] = 0x800CF598u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CF590 jal */
    { goto L_800CF798; }  /* 0x800CF598 j */
    R[5] = R[0] + 1;  /* 0x800CF5A0 */
    R[6] = R[5] + R[0];  /* 0x800CF5A4 */
    R[2] = 0x8014u << 16;  /* 0x800CF5A8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5AC */
    R[18] = R[2] + 15136;  /* 0x800CF5B0 */
    R[4] = R[4] << 2;  /* 0x800CF5B4 */
    { R[31] = 0x800CF5C0u; R[4] = R[4] + R[18]; psx_next = 0x800CCF94u; return; }  /* 0x800CF5B8 jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CF5CC; } }  /* 0x800CF5C0 */
    sh_(R[17] + 582, R[0]);  /* 0x800CF5C8 */
L_800CF5CC:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF5CC */
    R[2] = R[2] - 1;  /* 0x800CF5D4 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF5D8 */
    R[2] = R[2] << 16;  /* 0x800CF5DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF5E0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[2] = ((int32_t)R[2] < 9); if (_c) { goto L_800CF630; } }  /* 0x800CF5E4 */
    R[5] = R[0] + 1;  /* 0x800CF5EC */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5F0 */
    R[6] = R[5] + R[0];  /* 0x800CF5F4 */
    R[4] = R[4] << 2;  /* 0x800CF5F8 */
    { R[31] = 0x800CF604u; R[4] = R[4] + R[18]; psx_next = 0x800CD028u; return; }  /* 0x800CF5FC jal */
    R[2] = 0x800Fu << 16;  /* 0x800CF604 */
    R[3] = lw_(R[17] + 588);  /* 0x800CF608 */
    R[2] = R[2] - 416;  /* 0x800CF60C */
    sw_(R[17] + 608, R[0]);  /* 0x800CF610 */
    sh_(R[17] + 14, R[0]);  /* 0x800CF614 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF618 */
    R[2] = lb_(R[3] + 2);  /* 0x800CF61C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF620 */
    sh_(R[17] + 586, R[16]);  /* 0x800CF624 */
    { sb_(R[17] + 801, R[2]); goto L_800CF68C; }  /* 0x800CF628 j */
L_800CF630:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF68C; } }  /* 0x800CF630 */
    R[2] = lh_(R[17] + 592);  /* 0x800CF638 */
    R[2] = R[2] + 1;  /* 0x800CF640 */
    sh_(R[17] + 592, R[2]);  /* 0x800CF644 */
    R[2] = R[2] << 16;  /* 0x800CF648 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF64C */
    R[2] = ((int32_t)R[2] < 2);  /* 0x800CF650 */
    { uint32_t _c = (R[2] != R[0]); R[7] = R[0] + 2; if (_c) { goto L_800CF68C; } }  /* 0x800CF654 */
    R[4] = 0x800Fu << 16;  /* 0x800CF65C */
    R[4] = R[4] - 220;  /* 0x800CF660 */
    R[6] = 0x8014u << 16;  /* 0x800CF664 */
    R[5] = lw_(R[17] + 588);  /* 0x800CF668 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF66C */
    R[6] = R[6] + 15160;  /* 0x800CF670 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF674 */
    R[2] = R[3] << 3;  /* 0x800CF678 */
    R[2] = R[2] + R[3];  /* 0x800CF67C */
    R[2] = R[2] << 7;  /* 0x800CF680 */
    { R[31] = 0x800CF68Cu; R[6] = R[2] + R[6]; psx_next = 0x800CEF90u; return; }  /* 0x800CF684 jal */
L_800CF68C:;
    R[5] = lw_(R[17] + 588);  /* 0x800CF68C */
    { R[31] = 0x800CF698u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CF690 jal */
    R[4] = 0x8014u << 16;  /* 0x800CF698 */
    R[4] = R[4] + 15160;  /* 0x800CF69C */
    R[3] = lb_(R[17] + 585);  /* 0x800CF6A0 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 594);  /* 0x800CF6A4 */
    R[2] = R[3] << 3;  /* 0x800CF6A8 */
    R[2] = R[2] + R[3];  /* 0x800CF6AC */
    R[2] = R[2] << 7;  /* 0x800CF6B0 */
    { R[31] = 0x800CF6BCu; R[4] = R[2] + R[4]; psx_next = 0x800CF118u; return; }  /* 0x800CF6B4 jal */
    { goto L_800CF798; }  /* 0x800CF6BC j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF590(void) {
    { R[31] = 0x800CF598u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CF590 jal */
    { goto L_800CF798; }  /* 0x800CF598 j */
    R[5] = R[0] + 1;  /* 0x800CF5A0 */
    R[6] = R[5] + R[0];  /* 0x800CF5A4 */
    R[2] = 0x8014u << 16;  /* 0x800CF5A8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5AC */
    R[18] = R[2] + 15136;  /* 0x800CF5B0 */
    R[4] = R[4] << 2;  /* 0x800CF5B4 */
    { R[31] = 0x800CF5C0u; R[4] = R[4] + R[18]; psx_next = 0x800CCF94u; return; }  /* 0x800CF5B8 jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CF5CC; } }  /* 0x800CF5C0 */
    sh_(R[17] + 582, R[0]);  /* 0x800CF5C8 */
L_800CF5CC:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF5CC */
    R[2] = R[2] - 1;  /* 0x800CF5D4 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF5D8 */
    R[2] = R[2] << 16;  /* 0x800CF5DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF5E0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[2] = ((int32_t)R[2] < 9); if (_c) { goto L_800CF630; } }  /* 0x800CF5E4 */
    R[5] = R[0] + 1;  /* 0x800CF5EC */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5F0 */
    R[6] = R[5] + R[0];  /* 0x800CF5F4 */
    R[4] = R[4] << 2;  /* 0x800CF5F8 */
    { R[31] = 0x800CF604u; R[4] = R[4] + R[18]; psx_next = 0x800CD028u; return; }  /* 0x800CF5FC jal */
    R[2] = 0x800Fu << 16;  /* 0x800CF604 */
    R[3] = lw_(R[17] + 588);  /* 0x800CF608 */
    R[2] = R[2] - 416;  /* 0x800CF60C */
    sw_(R[17] + 608, R[0]);  /* 0x800CF610 */
    sh_(R[17] + 14, R[0]);  /* 0x800CF614 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF618 */
    R[2] = lb_(R[3] + 2);  /* 0x800CF61C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF620 */
    sh_(R[17] + 586, R[16]);  /* 0x800CF624 */
    { sb_(R[17] + 801, R[2]); goto L_800CF68C; }  /* 0x800CF628 j */
L_800CF630:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF68C; } }  /* 0x800CF630 */
    R[2] = lh_(R[17] + 592);  /* 0x800CF638 */
    R[2] = R[2] + 1;  /* 0x800CF640 */
    sh_(R[17] + 592, R[2]);  /* 0x800CF644 */
    R[2] = R[2] << 16;  /* 0x800CF648 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF64C */
    R[2] = ((int32_t)R[2] < 2);  /* 0x800CF650 */
    { uint32_t _c = (R[2] != R[0]); R[7] = R[0] + 2; if (_c) { goto L_800CF68C; } }  /* 0x800CF654 */
    R[4] = 0x800Fu << 16;  /* 0x800CF65C */
    R[4] = R[4] - 220;  /* 0x800CF660 */
    R[6] = 0x8014u << 16;  /* 0x800CF664 */
    R[5] = lw_(R[17] + 588);  /* 0x800CF668 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF66C */
    R[6] = R[6] + 15160;  /* 0x800CF670 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF674 */
    R[2] = R[3] << 3;  /* 0x800CF678 */
    R[2] = R[2] + R[3];  /* 0x800CF67C */
    R[2] = R[2] << 7;  /* 0x800CF680 */
    { R[31] = 0x800CF68Cu; R[6] = R[2] + R[6]; psx_next = 0x800CEF90u; return; }  /* 0x800CF684 jal */
L_800CF68C:;
    R[5] = lw_(R[17] + 588);  /* 0x800CF68C */
    { R[31] = 0x800CF698u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CF690 jal */
    R[4] = 0x8014u << 16;  /* 0x800CF698 */
    R[4] = R[4] + 15160;  /* 0x800CF69C */
    R[3] = lb_(R[17] + 585);  /* 0x800CF6A0 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 594);  /* 0x800CF6A4 */
    R[2] = R[3] << 3;  /* 0x800CF6A8 */
    R[2] = R[2] + R[3];  /* 0x800CF6AC */
    R[2] = R[2] << 7;  /* 0x800CF6B0 */
    { R[31] = 0x800CF6BCu; R[4] = R[2] + R[4]; psx_next = 0x800CF118u; return; }  /* 0x800CF6B4 jal */
    { goto L_800CF798; }  /* 0x800CF6BC j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF598(void) {
    { goto L_800CF798; }  /* 0x800CF598 j */
    R[5] = R[0] + 1;  /* 0x800CF5A0 */
    R[6] = R[5] + R[0];  /* 0x800CF5A4 */
    R[2] = 0x8014u << 16;  /* 0x800CF5A8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5AC */
    R[18] = R[2] + 15136;  /* 0x800CF5B0 */
    R[4] = R[4] << 2;  /* 0x800CF5B4 */
    { R[31] = 0x800CF5C0u; R[4] = R[4] + R[18]; psx_next = 0x800CCF94u; return; }  /* 0x800CF5B8 jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CF5CC; } }  /* 0x800CF5C0 */
    sh_(R[17] + 582, R[0]);  /* 0x800CF5C8 */
L_800CF5CC:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF5CC */
    R[2] = R[2] - 1;  /* 0x800CF5D4 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF5D8 */
    R[2] = R[2] << 16;  /* 0x800CF5DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF5E0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[2] = ((int32_t)R[2] < 9); if (_c) { goto L_800CF630; } }  /* 0x800CF5E4 */
    R[5] = R[0] + 1;  /* 0x800CF5EC */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5F0 */
    R[6] = R[5] + R[0];  /* 0x800CF5F4 */
    R[4] = R[4] << 2;  /* 0x800CF5F8 */
    { R[31] = 0x800CF604u; R[4] = R[4] + R[18]; psx_next = 0x800CD028u; return; }  /* 0x800CF5FC jal */
    R[2] = 0x800Fu << 16;  /* 0x800CF604 */
    R[3] = lw_(R[17] + 588);  /* 0x800CF608 */
    R[2] = R[2] - 416;  /* 0x800CF60C */
    sw_(R[17] + 608, R[0]);  /* 0x800CF610 */
    sh_(R[17] + 14, R[0]);  /* 0x800CF614 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF618 */
    R[2] = lb_(R[3] + 2);  /* 0x800CF61C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF620 */
    sh_(R[17] + 586, R[16]);  /* 0x800CF624 */
    { sb_(R[17] + 801, R[2]); goto L_800CF68C; }  /* 0x800CF628 j */
L_800CF630:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF68C; } }  /* 0x800CF630 */
    R[2] = lh_(R[17] + 592);  /* 0x800CF638 */
    R[2] = R[2] + 1;  /* 0x800CF640 */
    sh_(R[17] + 592, R[2]);  /* 0x800CF644 */
    R[2] = R[2] << 16;  /* 0x800CF648 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF64C */
    R[2] = ((int32_t)R[2] < 2);  /* 0x800CF650 */
    { uint32_t _c = (R[2] != R[0]); R[7] = R[0] + 2; if (_c) { goto L_800CF68C; } }  /* 0x800CF654 */
    R[4] = 0x800Fu << 16;  /* 0x800CF65C */
    R[4] = R[4] - 220;  /* 0x800CF660 */
    R[6] = 0x8014u << 16;  /* 0x800CF664 */
    R[5] = lw_(R[17] + 588);  /* 0x800CF668 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF66C */
    R[6] = R[6] + 15160;  /* 0x800CF670 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF674 */
    R[2] = R[3] << 3;  /* 0x800CF678 */
    R[2] = R[2] + R[3];  /* 0x800CF67C */
    R[2] = R[2] << 7;  /* 0x800CF680 */
    { R[31] = 0x800CF68Cu; R[6] = R[2] + R[6]; psx_next = 0x800CEF90u; return; }  /* 0x800CF684 jal */
L_800CF68C:;
    R[5] = lw_(R[17] + 588);  /* 0x800CF68C */
    { R[31] = 0x800CF698u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CF690 jal */
    R[4] = 0x8014u << 16;  /* 0x800CF698 */
    R[4] = R[4] + 15160;  /* 0x800CF69C */
    R[3] = lb_(R[17] + 585);  /* 0x800CF6A0 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 594);  /* 0x800CF6A4 */
    R[2] = R[3] << 3;  /* 0x800CF6A8 */
    R[2] = R[2] + R[3];  /* 0x800CF6AC */
    R[2] = R[2] << 7;  /* 0x800CF6B0 */
    { R[31] = 0x800CF6BCu; R[4] = R[2] + R[4]; psx_next = 0x800CF118u; return; }  /* 0x800CF6B4 jal */
    { goto L_800CF798; }  /* 0x800CF6BC j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF5C0(void) {
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CF5CC; } }  /* 0x800CF5C0 */
    sh_(R[17] + 582, R[0]);  /* 0x800CF5C8 */
L_800CF5CC:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF5CC */
    R[2] = R[2] - 1;  /* 0x800CF5D4 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF5D8 */
    R[2] = R[2] << 16;  /* 0x800CF5DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF5E0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[2] = ((int32_t)R[2] < 9); if (_c) { goto L_800CF630; } }  /* 0x800CF5E4 */
    R[5] = R[0] + 1;  /* 0x800CF5EC */
    R[4] = lb_(R[17] + 585);  /* 0x800CF5F0 */
    R[6] = R[5] + R[0];  /* 0x800CF5F4 */
    R[4] = R[4] << 2;  /* 0x800CF5F8 */
    { R[31] = 0x800CF604u; R[4] = R[4] + R[18]; psx_next = 0x800CD028u; return; }  /* 0x800CF5FC jal */
    R[2] = 0x800Fu << 16;  /* 0x800CF604 */
    R[3] = lw_(R[17] + 588);  /* 0x800CF608 */
    R[2] = R[2] - 416;  /* 0x800CF60C */
    sw_(R[17] + 608, R[0]);  /* 0x800CF610 */
    sh_(R[17] + 14, R[0]);  /* 0x800CF614 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF618 */
    R[2] = lb_(R[3] + 2);  /* 0x800CF61C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF620 */
    sh_(R[17] + 586, R[16]);  /* 0x800CF624 */
    { sb_(R[17] + 801, R[2]); goto L_800CF68C; }  /* 0x800CF628 j */
L_800CF630:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF68C; } }  /* 0x800CF630 */
    R[2] = lh_(R[17] + 592);  /* 0x800CF638 */
    R[2] = R[2] + 1;  /* 0x800CF640 */
    sh_(R[17] + 592, R[2]);  /* 0x800CF644 */
    R[2] = R[2] << 16;  /* 0x800CF648 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF64C */
    R[2] = ((int32_t)R[2] < 2);  /* 0x800CF650 */
    { uint32_t _c = (R[2] != R[0]); R[7] = R[0] + 2; if (_c) { goto L_800CF68C; } }  /* 0x800CF654 */
    R[4] = 0x800Fu << 16;  /* 0x800CF65C */
    R[4] = R[4] - 220;  /* 0x800CF660 */
    R[6] = 0x8014u << 16;  /* 0x800CF664 */
    R[5] = lw_(R[17] + 588);  /* 0x800CF668 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF66C */
    R[6] = R[6] + 15160;  /* 0x800CF670 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF674 */
    R[2] = R[3] << 3;  /* 0x800CF678 */
    R[2] = R[2] + R[3];  /* 0x800CF67C */
    R[2] = R[2] << 7;  /* 0x800CF680 */
    { R[31] = 0x800CF68Cu; R[6] = R[2] + R[6]; psx_next = 0x800CEF90u; return; }  /* 0x800CF684 jal */
L_800CF68C:;
    R[5] = lw_(R[17] + 588);  /* 0x800CF68C */
    { R[31] = 0x800CF698u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CF690 jal */
    R[4] = 0x8014u << 16;  /* 0x800CF698 */
    R[4] = R[4] + 15160;  /* 0x800CF69C */
    R[3] = lb_(R[17] + 585);  /* 0x800CF6A0 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 594);  /* 0x800CF6A4 */
    R[2] = R[3] << 3;  /* 0x800CF6A8 */
    R[2] = R[2] + R[3];  /* 0x800CF6AC */
    R[2] = R[2] << 7;  /* 0x800CF6B0 */
    { R[31] = 0x800CF6BCu; R[4] = R[2] + R[4]; psx_next = 0x800CF118u; return; }  /* 0x800CF6B4 jal */
    { goto L_800CF798; }  /* 0x800CF6BC j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF604(void) {
    R[2] = 0x800Fu << 16;  /* 0x800CF604 */
    R[3] = lw_(R[17] + 588);  /* 0x800CF608 */
    R[2] = R[2] - 416;  /* 0x800CF60C */
    sw_(R[17] + 608, R[0]);  /* 0x800CF610 */
    sh_(R[17] + 14, R[0]);  /* 0x800CF614 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF618 */
    R[2] = lb_(R[3] + 2);  /* 0x800CF61C */
    sh_(R[17] + 582, R[16]);  /* 0x800CF620 */
    sh_(R[17] + 586, R[16]);  /* 0x800CF624 */
    { sb_(R[17] + 801, R[2]); goto L_800CF68C; }  /* 0x800CF628 j */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF68C; } }  /* 0x800CF630 */
    R[2] = lh_(R[17] + 592);  /* 0x800CF638 */
    R[2] = R[2] + 1;  /* 0x800CF640 */
    sh_(R[17] + 592, R[2]);  /* 0x800CF644 */
    R[2] = R[2] << 16;  /* 0x800CF648 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF64C */
    R[2] = ((int32_t)R[2] < 2);  /* 0x800CF650 */
    { uint32_t _c = (R[2] != R[0]); R[7] = R[0] + 2; if (_c) { goto L_800CF68C; } }  /* 0x800CF654 */
    R[4] = 0x800Fu << 16;  /* 0x800CF65C */
    R[4] = R[4] - 220;  /* 0x800CF660 */
    R[6] = 0x8014u << 16;  /* 0x800CF664 */
    R[5] = lw_(R[17] + 588);  /* 0x800CF668 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF66C */
    R[6] = R[6] + 15160;  /* 0x800CF670 */
    sh_(R[17] + 592, R[0]);  /* 0x800CF674 */
    R[2] = R[3] << 3;  /* 0x800CF678 */
    R[2] = R[2] + R[3];  /* 0x800CF67C */
    R[2] = R[2] << 7;  /* 0x800CF680 */
    { R[31] = 0x800CF68Cu; R[6] = R[2] + R[6]; psx_next = 0x800CEF90u; return; }  /* 0x800CF684 jal */
L_800CF68C:;
    R[5] = lw_(R[17] + 588);  /* 0x800CF68C */
    { R[31] = 0x800CF698u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CF690 jal */
    R[4] = 0x8014u << 16;  /* 0x800CF698 */
    R[4] = R[4] + 15160;  /* 0x800CF69C */
    R[3] = lb_(R[17] + 585);  /* 0x800CF6A0 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 594);  /* 0x800CF6A4 */
    R[2] = R[3] << 3;  /* 0x800CF6A8 */
    R[2] = R[2] + R[3];  /* 0x800CF6AC */
    R[2] = R[2] << 7;  /* 0x800CF6B0 */
    { R[31] = 0x800CF6BCu; R[4] = R[2] + R[4]; psx_next = 0x800CF118u; return; }  /* 0x800CF6B4 jal */
    { goto L_800CF798; }  /* 0x800CF6BC j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF68C(void) {
    R[5] = lw_(R[17] + 588);  /* 0x800CF68C */
    { R[31] = 0x800CF698u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CF690 jal */
    R[4] = 0x8014u << 16;  /* 0x800CF698 */
    R[4] = R[4] + 15160;  /* 0x800CF69C */
    R[3] = lb_(R[17] + 585);  /* 0x800CF6A0 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 594);  /* 0x800CF6A4 */
    R[2] = R[3] << 3;  /* 0x800CF6A8 */
    R[2] = R[2] + R[3];  /* 0x800CF6AC */
    R[2] = R[2] << 7;  /* 0x800CF6B0 */
    { R[31] = 0x800CF6BCu; R[4] = R[2] + R[4]; psx_next = 0x800CF118u; return; }  /* 0x800CF6B4 jal */
    { goto L_800CF798; }  /* 0x800CF6BC j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF698(void) {
    R[4] = 0x8014u << 16;  /* 0x800CF698 */
    R[4] = R[4] + 15160;  /* 0x800CF69C */
    R[3] = lb_(R[17] + 585);  /* 0x800CF6A0 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 594);  /* 0x800CF6A4 */
    R[2] = R[3] << 3;  /* 0x800CF6A8 */
    R[2] = R[2] + R[3];  /* 0x800CF6AC */
    R[2] = R[2] << 7;  /* 0x800CF6B0 */
    { R[31] = 0x800CF6BCu; R[4] = R[2] + R[4]; psx_next = 0x800CF118u; return; }  /* 0x800CF6B4 jal */
    { goto L_800CF798; }  /* 0x800CF6BC j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF6BC(void) {
    { goto L_800CF798; }  /* 0x800CF6BC j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6C4 */
    R[2] = R[2] - 1;  /* 0x800CF6CC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6D0 */
    R[2] = R[2] << 16;  /* 0x800CF6D4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 4; if (_c) { goto L_800CF798; } }  /* 0x800CF6D8 */
    { sb_(R[17] + 790, R[2]); goto L_800CF798; }  /* 0x800CF6E0 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CF6E8 */
    R[2] = R[2] - 1;  /* 0x800CF6F0 */
    sh_(R[17] + 582, R[2]);  /* 0x800CF6F4 */
    R[2] = R[2] << 16;  /* 0x800CF6F8 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CF72C; } }  /* 0x800CF6FC */
    R[3] = 0x8014u << 16;  /* 0x800CF704 */
    sb_(R[17] + 790, R[2]);  /* 0x800CF708 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CF70C */
    R[2] = R[2] - 1;  /* 0x800CF714 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CF798; } }  /* 0x800CF718 */
    R[2] = 0x8013u << 16;  /* 0x800CF720 */
    { sh_(R[2] + -29614, R[0]); goto L_800CF798; }  /* 0x800CF724 j */
L_800CF72C:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CF72C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CF790; } }  /* 0x800CF734 */
    R[2] = lw_(R[17] + 604);  /* 0x800CF73C */
    R[3] = lw_(R[17] + 600);  /* 0x800CF740 */
    R[2] = R[2] - R[3];  /* 0x800CF748 */
    sw_(R[17] + 604, R[2]);  /* 0x800CF74C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CF750 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF754 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF758 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF760 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CF764 */
    { R[31] = 0x800CF770u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CF768 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
L_800CF790:;
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF770(void) {
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CF770 */
    R[4] = R[17] + R[0];  /* 0x800CF774 */
    R[3] = R[2] + R[0];  /* 0x800CF778 */
    sh_(R[4] + 60, R[2]);  /* 0x800CF77C */
    { R[31] = 0x800CF788u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CF780 jal */
    { goto L_800CF798; }  /* 0x800CF788 j */
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF788(void) {
    { goto L_800CF798; }  /* 0x800CF788 j */
    { R[31] = 0x800CF798u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CF790 jal */
L_800CF798:;
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF798(void) {
    R[31] = lw_(R[29] + 36);  /* 0x800CF798 */
    R[20] = lw_(R[29] + 32);  /* 0x800CF79C */
    R[19] = lw_(R[29] + 28);  /* 0x800CF7A0 */
    R[18] = lw_(R[29] + 24);  /* 0x800CF7A4 */
    R[17] = lw_(R[29] + 20);  /* 0x800CF7A8 */
    R[16] = lw_(R[29] + 16);  /* 0x800CF7AC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800CF7B0 jr ra */
}

void g0_800CF7B8(void) {
    R[29] = R[29] - 56;  /* 0x800CF7B8 */
    sw_(R[29] + 36, R[17]);  /* 0x800CF7BC */
    R[17] = R[4] + R[0];  /* 0x800CF7C0 */
    sw_(R[29] + 52, R[31]);  /* 0x800CF7C4 */
    sw_(R[29] + 48, R[20]);  /* 0x800CF7C8 */
    sw_(R[29] + 44, R[19]);  /* 0x800CF7CC */
    sw_(R[29] + 40, R[18]);  /* 0x800CF7D0 */
    sw_(R[29] + 32, R[16]);  /* 0x800CF7D4 */
    R[2] = lh_(R[17] + 2);  /* 0x800CF7D8 */
    R[19] = R[0] + 2;  /* 0x800CF7DC */
    R[3] = R[2] << 3;  /* 0x800CF7E0 */
    R[3] = R[3] + R[2];  /* 0x800CF7E4 */
    R[3] = R[3] << 3;  /* 0x800CF7E8 */
    R[2] = 0x8013u << 16;  /* 0x800CF7EC */
    R[2] = R[2] - 23304;  /* 0x800CF7F0 */
    { uint32_t _c = (R[5] == R[19]); R[18] = R[3] + R[2]; if (_c) { goto L_800CFD30; } }  /* 0x800CF7F4 */
    R[2] = ((int32_t)R[5] < 3);  /* 0x800CF7FC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CF818; } }  /* 0x800CF800 */
    { uint32_t _c = (R[5] == R[0]); R[20] = R[0] + 1; if (_c) { goto L_800CF8B4; } }  /* 0x800CF808 */
    { goto L_800CFDE0; }  /* 0x800CF810 j */
L_800CF818:;
    R[2] = R[0] + 5;  /* 0x800CF818 */
    { uint32_t _c = (R[5] != R[2]); R[5] = R[18] + R[0]; if (_c) { goto L_800CFDE0; } }  /* 0x800CF81C */
    R[4] = R[0] + R[0];  /* 0x800CF824 */
    R[16] = 0x800Fu << 16;  /* 0x800CF828 */
    R[16] = R[16] - 196;  /* 0x800CF82C */
    R[6] = R[16] + R[0];  /* 0x800CF830 */
    R[2] = R[0] + 1;  /* 0x800CF834 */
    R[7] = R[17] + 24;  /* 0x800CF838 */
    sb_(R[17] + 688, R[2]);  /* 0x800CF83C */
    { R[31] = 0x800CF848u; sb_(R[17] + 690, R[2]); psx_next = 0x800A5964u; return; }  /* 0x800CF840 jal */
    R[4] = R[17] + R[0];  /* 0x800CF848 */
    R[5] = R[16] + R[0];  /* 0x800CF84C */
    R[2] = R[0] + 25;  /* 0x800CF850 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF854 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF858 */
    R[2] = 0x800Bu << 16;  /* 0x800CF85C */
    R[2] = R[2] - 8012;  /* 0x800CF860 */
    sw_(R[17] + 232, R[2]);  /* 0x800CF864 */
    R[2] = R[0] + 6400;  /* 0x800CF868 */
    sw_(R[17] + 124, R[2]);  /* 0x800CF86C */
    R[2] = 0x800Fu << 16;  /* 0x800CF870 */
    R[2] = R[2] - 496;  /* 0x800CF874 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF878 */
    R[2] = R[0] + 40;  /* 0x800CF87C */
    sh_(R[17] + 582, R[2]);  /* 0x800CF880 */
    R[2] = R[0] | 0xA000;  /* 0x800CF884 */
    sw_(R[17] + 600, R[2]);  /* 0x800CF888 */
    R[2] = 0x32u << 16;  /* 0x800CF88C */
    sw_(R[17] + 604, R[2]);  /* 0x800CF890 */
    { R[31] = 0x800CF89Cu; sh_(R[17] + 586, R[0]); psx_next = 0x800CDBDCu; return; }  /* 0x800CF894 jal */
    R[4] = R[17] + R[0];  /* 0x800CF89C */
    R[5] = 0x800Fu << 16;  /* 0x800CF8A0 */
    { R[31] = 0x800CF8ACu; R[5] = R[5] - 396; psx_next = 0x800CD894u; return; }  /* 0x800CF8A4 jal */
    { goto L_800CFDE0; }  /* 0x800CF8AC j */
L_800CF8B4:;
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 586);  /* 0x800CF8B4 */
    { uint32_t _c = (R[3] == R[20]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_800CFBB0; } }  /* 0x800CF8BC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CF8DC; } }  /* 0x800CF8C4 */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_800CF8F4; } }  /* 0x800CF8CC */
    { goto L_800CFDE0; }  /* 0x800CF8D4 j */
L_800CF8DC:;
    { uint32_t _c = (R[3] == R[19]); R[2] = R[0] + 3; if (_c) { goto L_800CFC68; } }  /* 0x800CF8DC */
    { uint32_t _c = (R[3] == R[2]); R[4] = R[17] + R[0]; if (_c) { goto L_800CFCE0; } }  /* 0x800CF8E4 */
    { goto L_800CFDE0; }  /* 0x800CF8EC j */
L_800CF8F4:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF8F4 */
    R[2] = R[2] - 1;  /* 0x800CF8FC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF900 */
    R[2] = R[2] << 16;  /* 0x800CF904 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[16] = R[0] + 8; if (_c) { goto L_800CF990; } }  /* 0x800CF908 */
    R[4] = R[0] - 128;  /* 0x800CF910 */
    psx_div((int32_t)R[4], (int32_t)R[16]);  /* 0x800CF914 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CF924; } }  /* 0x800CF918 */
    psx_break(7168);  /* 0x800CF920 */
L_800CF924:;
    R[1] = R[0] - 1;  /* 0x800CF924 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF93C; } }  /* 0x800CF928 */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CF93C; } }  /* 0x800CF930 */
    psx_break(6144);  /* 0x800CF938 */
L_800CF93C:;
    R[4] = LO;  /* 0x800CF93C */
    R[3] = lw_(R[17] + 604);  /* 0x800CF940 */
    psx_div((int32_t)R[3], (int32_t)R[16]);  /* 0x800CF948 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CF958; } }  /* 0x800CF94C */
    psx_break(7168);  /* 0x800CF954 */
L_800CF958:;
    R[1] = R[0] - 1;  /* 0x800CF958 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF970; } }  /* 0x800CF95C */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CF970; } }  /* 0x800CF964 */
    psx_break(6144);  /* 0x800CF96C */
L_800CF970:;
    R[3] = LO;  /* 0x800CF970 */
    sb_(R[17] + 584, R[0]);  /* 0x800CF974 */
    sh_(R[17] + 582, R[16]);  /* 0x800CF978 */
    R[2] = R[0] + 4;  /* 0x800CF97C */
    sb_(R[17] + 790, R[2]);  /* 0x800CF980 */
    sh_(R[17] + 592, R[4]);  /* 0x800CF984 */
    { sw_(R[17] + 600, R[3]); goto L_800CFDE0; }  /* 0x800CF988 j */
L_800CF990:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 218);  /* 0x800CF990 */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[5] = R[0] + 16; if (_c) { goto L_800CFB18; } }  /* 0x800CF998 */
    R[2] = lb_(R[17] + 585);  /* 0x800CF9A0 */
    R[3] = R[2] << 3;  /* 0x800CF9A8 */
    R[3] = R[3] + R[2];  /* 0x800CF9AC */
    R[3] = R[3] << 7;  /* 0x800CF9B0 */
    R[2] = 0x8014u << 16;  /* 0x800CF9B4 */
    R[2] = R[2] + 15160;  /* 0x800CF9B8 */
    R[18] = R[3] + R[2];  /* 0x800CF9BC */
    { R[31] = 0x800CF9C8u; R[4] = R[18] + R[0]; psx_next = 0x800CD6CCu; return; }  /* 0x800CF9C0 jal */
    R[4] = R[17] + R[0];  /* 0x800CF9C8 */
    R[5] = R[0] + 1;  /* 0x800CF9CC */
    R[2] = 0x8014u << 16;  /* 0x800CF9D0 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF9D4 */
    R[2] = R[2] + 15136;  /* 0x800CF9D8 */
    R[3] = R[3] << 2;  /* 0x800CF9DC */
    R[16] = R[3] + R[2];  /* 0x800CF9E0 */
    { R[31] = 0x800CF9ECu; R[6] = R[16] + R[0]; psx_next = 0x800CE504u; return; }  /* 0x800CF9E4 jal */
    R[19] = R[2] + R[0];  /* 0x800CF9EC */
    { uint32_t _c = ((int32_t)R[19] <= 0); if (_c) { goto L_800CFB28; } }  /* 0x800CF9F0 */
    { R[31] = 0x800CFA00u; R[4] = R[0] + 57; psx_next = 0x8002DB10u; return; }  /* 0x800CF9F8 jal */
    sb_(R[17] + 584, R[20]);  /* 0x800CFA00 */
    sw_(R[17] + 124, R[0]);  /* 0x800CFA04 */
    sw_(R[17] + 188, R[0]);  /* 0x800CFA08 */
    R[2] = lw_(R[16]);  /* 0x800CFA0C */
    R[2] = lw_(R[2] + 24);  /* 0x800CFA14 */
    sw_(R[29] + 16, R[2]);  /* 0x800CFA1C */
    R[2] = lw_(R[17] + 28);  /* 0x800CFA20 */
    sw_(R[29] + 20, R[2]);  /* 0x800CFA28 */
    R[2] = lw_(R[16]);  /* 0x800CFA2C */
    R[2] = lw_(R[2] + 32);  /* 0x800CFA34 */
    sw_(R[29] + 24, R[2]);  /* 0x800CFA3C */
    R[2] = lw_(R[16]);  /* 0x800CFA40 */
    R[2] = lw_(R[2] + 24);  /* 0x800CFA48 */
    sw_(R[17] + 24, R[2]);  /* 0x800CFA50 */
    R[2] = lw_(R[16]);  /* 0x800CFA54 */
    R[2] = lw_(R[2] + 28);  /* 0x800CFA5C */
    sw_(R[17] + 28, R[2]);  /* 0x800CFA64 */
    R[2] = lw_(R[16]);  /* 0x800CFA68 */
    R[6] = lb_(R[17] + 585);  /* 0x800CFA6C */
    R[2] = lw_(R[2] + 32);  /* 0x800CFA70 */
    R[5] = 0x800Fu << 16;  /* 0x800CFA74 */
    sw_(R[17] + 32, R[2]);  /* 0x800CFA78 */
    R[4] = lw_(R[16]);  /* 0x800CFA7C */
    { R[31] = 0x800CFA88u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CFA80 jal */
    R[4] = R[29] + 16;  /* 0x800CFA88 */
    { R[31] = 0x800CFA94u; R[5] = R[18] + R[0]; psx_next = 0x800CE808u; return; }  /* 0x800CFA8C jal */
    R[3] = lw_(R[16]);  /* 0x800CFA94 */
    R[4] = R[0] + 17;  /* 0x800CFA98 */
    R[2] = lb_(R[3] + 789);  /* 0x800CFA9C */
    R[6] = 0x8011u << 16;  /* 0x800CFAA0 */
    R[2] = R[2] | 0x2;  /* 0x800CFAA4 */
    sb_(R[3] + 789, R[2]);  /* 0x800CFAA8 */
    R[5] = lw_(R[16]);  /* 0x800CFAAC */
    { R[31] = 0x800CFAB8u; R[6] = R[6] + 30196; psx_next = 0x800AC93Cu; return; }  /* 0x800CFAB0 jal */
    R[4] = lw_(R[16]);  /* 0x800CFAB8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CFAC0 */
    R[3] = R[0] - 897;  /* 0x800CFAC4 */
    R[2] = R[2] & R[3];  /* 0x800CFAC8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CFACC */
    R[3] = lw_(R[16]);  /* 0x800CFAD0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CFAD8 */
    R[2] = R[2] | 0x200;  /* 0x800CFAE0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CFAE4 */
    R[2] = R[0] + 15;  /* 0x800CFAE8 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFAEC */
    R[2] = R[0] + 45;  /* 0x800CFAF0 */
    sh_(R[17] + 592, R[2]);  /* 0x800CFAF4 */
    R[2] = R[0] + 8192;  /* 0x800CFAF8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CFAFC */
    sh_(R[17] + 594, R[2]);  /* 0x800CFB00 */
    R[2] = lw_(R[16]);  /* 0x800CFB04 */
    sw_(R[17] + 608, R[19]);  /* 0x800CFB08 */
    sh_(R[17] + 586, R[20]);  /* 0x800CFB0C */
    { sw_(R[17] + 588, R[2]); goto L_800CFB54; }  /* 0x800CFB10 j */
L_800CFB18:;
    R[2] = lb_(R[17] + 785);  /* 0x800CFB18 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_800CFB60; } }  /* 0x800CFB20 */
L_800CFB28:;
    R[16] = R[0] + 8;  /* 0x800CFB28 */
    R[4] = R[17] + R[0];  /* 0x800CFB2C */
    R[5] = 0x800Fu << 16;  /* 0x800CFB30 */
    R[5] = R[5] - 196;  /* 0x800CFB34 */
    R[6] = R[16] + R[0];  /* 0x800CFB38 */
    R[2] = R[0] + 2;  /* 0x800CFB3C */
    { R[31] = 0x800CFB48u; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CFB40 jal */
    R[2] = R[0] + 4;  /* 0x800CFB48 */
    sh_(R[17] + 582, R[16]);  /* 0x800CFB4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFB50 */
L_800CFB54:;
    R[2] = R[0] + 3;  /* 0x800CFB54 */
    { sb_(R[17] + 786, R[2]); goto L_800CFDE0; }  /* 0x800CFB58 j */
L_800CFB60:;
    sb_(R[18] + 3, R[2]);  /* 0x800CFB60 */
    R[2] = lw_(R[17] + 604);  /* 0x800CFB64 */
    R[3] = lw_(R[17] + 600);  /* 0x800CFB68 */
    R[2] = R[2] - R[3];  /* 0x800CFB70 */
    sw_(R[17] + 604, R[2]);  /* 0x800CFB74 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CFB78 */
    sb_(R[18] + 52, R[2]);  /* 0x800CFB7C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFB80 */
    R[4] = R[17] + R[0];  /* 0x800CFB84 */
    { R[31] = 0x800CFB90u; sb_(R[18] + 53, R[2]); psx_next = 0x800CDCACu; return; }  /* 0x800CFB88 jal */
    { R[31] = 0x800CFB98u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CFB90 jal */
    R[4] = R[17] + R[0];  /* 0x800CFB98 */
    R[5] = R[0] + 5;  /* 0x800CFB9C */
    { R[31] = 0x800CFBA8u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800CFBA0 jal */
    { goto L_800CFDE0; }  /* 0x800CFBA8 j */
L_800CFBB0:;
    R[5] = lw_(R[17] + 588);  /* 0x800CFBB0 */
    { R[31] = 0x800CFBBCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CFBB4 jal */
    R[4] = R[17] + R[0];  /* 0x800CFBBC */
    R[5] = 0x8014u << 16;  /* 0x800CFBC0 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFBC4 */
    R[5] = R[5] + 15160;  /* 0x800CFBC8 */
    R[2] = R[3] << 3;  /* 0x800CFBCC */
    R[2] = R[2] + R[3];  /* 0x800CFBD0 */
    R[2] = R[2] << 7;  /* 0x800CFBD4 */
    { R[31] = 0x800CFBE0u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFBD8 jal */
    R[5] = R[0] + 1;  /* 0x800CFBE0 */
    R[6] = R[5] + R[0];  /* 0x800CFBE4 */
    R[2] = 0x8014u << 16;  /* 0x800CFBE8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CFBEC */
    R[16] = R[2] + 15136;  /* 0x800CFBF0 */
    R[4] = R[4] << 2;  /* 0x800CFBF4 */
    { R[31] = 0x800CFC00u; R[4] = R[4] + R[16]; psx_next = 0x800CCF94u; return; }  /* 0x800CFBF8 jal */
    { uint32_t _c = (R[2] == R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CFD20; } }  /* 0x800CFC00 */
    R[2] = lh_(R[17] + 582);  /* 0x800CFC08 */
    R[2] = R[2] - 1;  /* 0x800CFC10 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFC14 */
    R[2] = R[2] << 16;  /* 0x800CFC18 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[5] = R[0] + 1; if (_c) { goto L_800CFDE0; } }  /* 0x800CFC1C */
    R[4] = lb_(R[17] + 585);  /* 0x800CFC24 */
    R[6] = R[5] + R[0];  /* 0x800CFC28 */
    R[4] = R[4] << 2;  /* 0x800CFC2C */
    { R[31] = 0x800CFC38u; R[4] = R[4] + R[16]; psx_next = 0x800CD028u; return; }  /* 0x800CFC30 jal */
    R[2] = 0x800Fu << 16;  /* 0x800CFC38 */
    R[3] = lw_(R[17] + 588);  /* 0x800CFC3C */
    R[2] = R[2] - 416;  /* 0x800CFC40 */
    sw_(R[17] + 608, R[0]);  /* 0x800CFC44 */
    sh_(R[17] + 14, R[0]);  /* 0x800CFC48 */
    sw_(R[17] + 84, R[2]);  /* 0x800CFC4C */
    R[2] = lb_(R[3] + 2);  /* 0x800CFC50 */
    sh_(R[17] + 596, R[0]);  /* 0x800CFC54 */
    sh_(R[17] + 582, R[19]);  /* 0x800CFC58 */
    sh_(R[17] + 586, R[19]);  /* 0x800CFC5C */
    { sb_(R[17] + 801, R[2]); goto L_800CFDE0; }  /* 0x800CFC60 j */
L_800CFC68:;
    R[2] = lw_(R[17] + 588);  /* 0x800CFC68 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 224);  /* 0x800CFC70 */
    R[2] = lh_(R[2] + 224);  /* 0x800CFC74 */
    { uint32_t _c = ((int32_t)R[3] <= 0); R[4] = R[17] + R[0]; if (_c) { goto L_800CFC84; } }  /* 0x800CFC78 */
    sh_(R[17] + 596, R[2]);  /* 0x800CFC80 */
L_800CFC84:;
    R[5] = 0x8014u << 16;  /* 0x800CFC84 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFC88 */
    R[5] = R[5] + 15160;  /* 0x800CFC8C */
    R[2] = R[3] << 3;  /* 0x800CFC90 */
    R[2] = R[2] + R[3];  /* 0x800CFC94 */
    R[2] = R[2] << 7;  /* 0x800CFC98 */
    { R[31] = 0x800CFCA4u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFC9C jal */
    R[3] = lh_(R[17] + 582);  /* 0x800CFCA4 */
    R[3] = R[3] - 1;  /* 0x800CFCAC */
    sh_(R[17] + 582, R[3]);  /* 0x800CFCB0 */
    R[3] = R[3] << 16;  /* 0x800CFCB4 */
    { uint32_t _c = ((int32_t)R[3] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFCB8 */
    { uint32_t _c = ((int32_t)R[2] <= 0); sw_(R[17] + 84, R[0]); if (_c) { goto L_800CFCD4; } }  /* 0x800CFCC0 */
    R[2] = R[0] + 3;  /* 0x800CFCC8 */
    { sh_(R[17] + 586, R[2]); goto L_800CFDE0; }  /* 0x800CFCCC j */
L_800CFCD4:;
    R[2] = R[0] + 4;  /* 0x800CFCD4 */
    { sb_(R[17] + 790, R[2]); goto L_800CFDE0; }  /* 0x800CFCD8 j */
L_800CFCE0:;
    R[3] = lb_(R[17] + 585);  /* 0x800CFCE0 */
    R[5] = 0x8014u << 16;  /* 0x800CFCE4 */
    R[5] = R[5] + 15160;  /* 0x800CFCE8 */
    R[2] = R[3] << 3;  /* 0x800CFCEC */
    R[2] = R[2] + R[3];  /* 0x800CFCF0 */
    R[2] = R[2] << 7;  /* 0x800CFCF4 */
    { R[31] = 0x800CFD00u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFCF8 jal */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD00 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 596);  /* 0x800CFD08 */
    { uint32_t _c = ((int32_t)R[4] <= 0); R[2] = R[0] + 4; if (_c) { goto L_800CFD24; } }  /* 0x800CFD10 */
    { R[31] = 0x800CFD20u; psx_next = 0x8001D0DCu; return; }  /* 0x800CFD18 jal */
L_800CFD20:;
    R[2] = R[0] + 4;  /* 0x800CFD20 */
L_800CFD24:;
    sh_(R[17] + 582, R[0]);  /* 0x800CFD24 */
    { sb_(R[17] + 790, R[2]); goto L_800CFDE0; }  /* 0x800CFD28 j */
L_800CFD30:;
    R[2] = lh_(R[17] + 582);  /* 0x800CFD30 */
    R[2] = R[2] - 1;  /* 0x800CFD38 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFD3C */
    R[2] = R[2] << 16;  /* 0x800CFD40 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CFD74; } }  /* 0x800CFD44 */
    R[3] = 0x8014u << 16;  /* 0x800CFD4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFD50 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CFD54 */
    R[2] = R[2] - 1;  /* 0x800CFD5C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD60 */
    R[2] = 0x8013u << 16;  /* 0x800CFD68 */
    { sh_(R[2] + -29614, R[0]); goto L_800CFDE0; }  /* 0x800CFD6C j */
L_800CFD74:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CFD74 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CFDD8; } }  /* 0x800CFD7C */
    R[2] = lw_(R[17] + 604);  /* 0x800CFD84 */
    R[3] = lw_(R[17] + 600);  /* 0x800CFD88 */
    R[2] = R[2] - R[3];  /* 0x800CFD90 */
    sw_(R[17] + 604, R[2]);  /* 0x800CFD94 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CFD98 */
    sb_(R[18] + 52, R[2]);  /* 0x800CFD9C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDA0 */
    sb_(R[18] + 53, R[2]);  /* 0x800CFDA8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CFDAC */
    { R[31] = 0x800CFDB8u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CFDB0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDB8 */
    R[4] = R[17] + R[0];  /* 0x800CFDBC */
    R[3] = R[2] + R[0];  /* 0x800CFDC0 */
    sh_(R[4] + 60, R[2]);  /* 0x800CFDC4 */
    { R[31] = 0x800CFDD0u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CFDC8 jal */
    { goto L_800CFDE0; }  /* 0x800CFDD0 j */
L_800CFDD8:;
    { R[31] = 0x800CFDE0u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CFDD8 jal */
L_800CFDE0:;
    R[31] = lw_(R[29] + 52);  /* 0x800CFDE0 */
    R[20] = lw_(R[29] + 48);  /* 0x800CFDE4 */
    R[19] = lw_(R[29] + 44);  /* 0x800CFDE8 */
    R[18] = lw_(R[29] + 40);  /* 0x800CFDEC */
    R[17] = lw_(R[29] + 36);  /* 0x800CFDF0 */
    R[16] = lw_(R[29] + 32);  /* 0x800CFDF4 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CFDF8 jr ra */
}

void g0_800CF848(void) {
    R[4] = R[17] + R[0];  /* 0x800CF848 */
    R[5] = R[16] + R[0];  /* 0x800CF84C */
    R[2] = R[0] + 25;  /* 0x800CF850 */
    sb_(R[18] + 52, R[2]);  /* 0x800CF854 */
    sb_(R[18] + 53, R[2]);  /* 0x800CF858 */
    R[2] = 0x800Bu << 16;  /* 0x800CF85C */
    R[2] = R[2] - 8012;  /* 0x800CF860 */
    sw_(R[17] + 232, R[2]);  /* 0x800CF864 */
    R[2] = R[0] + 6400;  /* 0x800CF868 */
    sw_(R[17] + 124, R[2]);  /* 0x800CF86C */
    R[2] = 0x800Fu << 16;  /* 0x800CF870 */
    R[2] = R[2] - 496;  /* 0x800CF874 */
    sw_(R[17] + 84, R[2]);  /* 0x800CF878 */
    R[2] = R[0] + 40;  /* 0x800CF87C */
    sh_(R[17] + 582, R[2]);  /* 0x800CF880 */
    R[2] = R[0] | 0xA000;  /* 0x800CF884 */
    sw_(R[17] + 600, R[2]);  /* 0x800CF888 */
    R[2] = 0x32u << 16;  /* 0x800CF88C */
    sw_(R[17] + 604, R[2]);  /* 0x800CF890 */
    { R[31] = 0x800CF89Cu; sh_(R[17] + 586, R[0]); psx_next = 0x800CDBDCu; return; }  /* 0x800CF894 jal */
    R[4] = R[17] + R[0];  /* 0x800CF89C */
    R[5] = 0x800Fu << 16;  /* 0x800CF8A0 */
    { R[31] = 0x800CF8ACu; R[5] = R[5] - 396; psx_next = 0x800CD894u; return; }  /* 0x800CF8A4 jal */
    { goto L_800CFDE0; }  /* 0x800CF8AC j */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 586);  /* 0x800CF8B4 */
    { uint32_t _c = (R[3] == R[20]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_800CFBB0; } }  /* 0x800CF8BC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CF8DC; } }  /* 0x800CF8C4 */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_800CF8F4; } }  /* 0x800CF8CC */
    { goto L_800CFDE0; }  /* 0x800CF8D4 j */
L_800CF8DC:;
    { uint32_t _c = (R[3] == R[19]); R[2] = R[0] + 3; if (_c) { goto L_800CFC68; } }  /* 0x800CF8DC */
    { uint32_t _c = (R[3] == R[2]); R[4] = R[17] + R[0]; if (_c) { goto L_800CFCE0; } }  /* 0x800CF8E4 */
    { goto L_800CFDE0; }  /* 0x800CF8EC j */
L_800CF8F4:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF8F4 */
    R[2] = R[2] - 1;  /* 0x800CF8FC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF900 */
    R[2] = R[2] << 16;  /* 0x800CF904 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[16] = R[0] + 8; if (_c) { goto L_800CF990; } }  /* 0x800CF908 */
    R[4] = R[0] - 128;  /* 0x800CF910 */
    psx_div((int32_t)R[4], (int32_t)R[16]);  /* 0x800CF914 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CF924; } }  /* 0x800CF918 */
    psx_break(7168);  /* 0x800CF920 */
L_800CF924:;
    R[1] = R[0] - 1;  /* 0x800CF924 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF93C; } }  /* 0x800CF928 */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CF93C; } }  /* 0x800CF930 */
    psx_break(6144);  /* 0x800CF938 */
L_800CF93C:;
    R[4] = LO;  /* 0x800CF93C */
    R[3] = lw_(R[17] + 604);  /* 0x800CF940 */
    psx_div((int32_t)R[3], (int32_t)R[16]);  /* 0x800CF948 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CF958; } }  /* 0x800CF94C */
    psx_break(7168);  /* 0x800CF954 */
L_800CF958:;
    R[1] = R[0] - 1;  /* 0x800CF958 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF970; } }  /* 0x800CF95C */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CF970; } }  /* 0x800CF964 */
    psx_break(6144);  /* 0x800CF96C */
L_800CF970:;
    R[3] = LO;  /* 0x800CF970 */
    sb_(R[17] + 584, R[0]);  /* 0x800CF974 */
    sh_(R[17] + 582, R[16]);  /* 0x800CF978 */
    R[2] = R[0] + 4;  /* 0x800CF97C */
    sb_(R[17] + 790, R[2]);  /* 0x800CF980 */
    sh_(R[17] + 592, R[4]);  /* 0x800CF984 */
    { sw_(R[17] + 600, R[3]); goto L_800CFDE0; }  /* 0x800CF988 j */
L_800CF990:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 218);  /* 0x800CF990 */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[5] = R[0] + 16; if (_c) { goto L_800CFB18; } }  /* 0x800CF998 */
    R[2] = lb_(R[17] + 585);  /* 0x800CF9A0 */
    R[3] = R[2] << 3;  /* 0x800CF9A8 */
    R[3] = R[3] + R[2];  /* 0x800CF9AC */
    R[3] = R[3] << 7;  /* 0x800CF9B0 */
    R[2] = 0x8014u << 16;  /* 0x800CF9B4 */
    R[2] = R[2] + 15160;  /* 0x800CF9B8 */
    R[18] = R[3] + R[2];  /* 0x800CF9BC */
    { R[31] = 0x800CF9C8u; R[4] = R[18] + R[0]; psx_next = 0x800CD6CCu; return; }  /* 0x800CF9C0 jal */
    R[4] = R[17] + R[0];  /* 0x800CF9C8 */
    R[5] = R[0] + 1;  /* 0x800CF9CC */
    R[2] = 0x8014u << 16;  /* 0x800CF9D0 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF9D4 */
    R[2] = R[2] + 15136;  /* 0x800CF9D8 */
    R[3] = R[3] << 2;  /* 0x800CF9DC */
    R[16] = R[3] + R[2];  /* 0x800CF9E0 */
    { R[31] = 0x800CF9ECu; R[6] = R[16] + R[0]; psx_next = 0x800CE504u; return; }  /* 0x800CF9E4 jal */
    R[19] = R[2] + R[0];  /* 0x800CF9EC */
    { uint32_t _c = ((int32_t)R[19] <= 0); if (_c) { goto L_800CFB28; } }  /* 0x800CF9F0 */
    { R[31] = 0x800CFA00u; R[4] = R[0] + 57; psx_next = 0x8002DB10u; return; }  /* 0x800CF9F8 jal */
    sb_(R[17] + 584, R[20]);  /* 0x800CFA00 */
    sw_(R[17] + 124, R[0]);  /* 0x800CFA04 */
    sw_(R[17] + 188, R[0]);  /* 0x800CFA08 */
    R[2] = lw_(R[16]);  /* 0x800CFA0C */
    R[2] = lw_(R[2] + 24);  /* 0x800CFA14 */
    sw_(R[29] + 16, R[2]);  /* 0x800CFA1C */
    R[2] = lw_(R[17] + 28);  /* 0x800CFA20 */
    sw_(R[29] + 20, R[2]);  /* 0x800CFA28 */
    R[2] = lw_(R[16]);  /* 0x800CFA2C */
    R[2] = lw_(R[2] + 32);  /* 0x800CFA34 */
    sw_(R[29] + 24, R[2]);  /* 0x800CFA3C */
    R[2] = lw_(R[16]);  /* 0x800CFA40 */
    R[2] = lw_(R[2] + 24);  /* 0x800CFA48 */
    sw_(R[17] + 24, R[2]);  /* 0x800CFA50 */
    R[2] = lw_(R[16]);  /* 0x800CFA54 */
    R[2] = lw_(R[2] + 28);  /* 0x800CFA5C */
    sw_(R[17] + 28, R[2]);  /* 0x800CFA64 */
    R[2] = lw_(R[16]);  /* 0x800CFA68 */
    R[6] = lb_(R[17] + 585);  /* 0x800CFA6C */
    R[2] = lw_(R[2] + 32);  /* 0x800CFA70 */
    R[5] = 0x800Fu << 16;  /* 0x800CFA74 */
    sw_(R[17] + 32, R[2]);  /* 0x800CFA78 */
    R[4] = lw_(R[16]);  /* 0x800CFA7C */
    { R[31] = 0x800CFA88u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CFA80 jal */
    R[4] = R[29] + 16;  /* 0x800CFA88 */
    { R[31] = 0x800CFA94u; R[5] = R[18] + R[0]; psx_next = 0x800CE808u; return; }  /* 0x800CFA8C jal */
    R[3] = lw_(R[16]);  /* 0x800CFA94 */
    R[4] = R[0] + 17;  /* 0x800CFA98 */
    R[2] = lb_(R[3] + 789);  /* 0x800CFA9C */
    R[6] = 0x8011u << 16;  /* 0x800CFAA0 */
    R[2] = R[2] | 0x2;  /* 0x800CFAA4 */
    sb_(R[3] + 789, R[2]);  /* 0x800CFAA8 */
    R[5] = lw_(R[16]);  /* 0x800CFAAC */
    { R[31] = 0x800CFAB8u; R[6] = R[6] + 30196; psx_next = 0x800AC93Cu; return; }  /* 0x800CFAB0 jal */
    R[4] = lw_(R[16]);  /* 0x800CFAB8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CFAC0 */
    R[3] = R[0] - 897;  /* 0x800CFAC4 */
    R[2] = R[2] & R[3];  /* 0x800CFAC8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CFACC */
    R[3] = lw_(R[16]);  /* 0x800CFAD0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CFAD8 */
    R[2] = R[2] | 0x200;  /* 0x800CFAE0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CFAE4 */
    R[2] = R[0] + 15;  /* 0x800CFAE8 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFAEC */
    R[2] = R[0] + 45;  /* 0x800CFAF0 */
    sh_(R[17] + 592, R[2]);  /* 0x800CFAF4 */
    R[2] = R[0] + 8192;  /* 0x800CFAF8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CFAFC */
    sh_(R[17] + 594, R[2]);  /* 0x800CFB00 */
    R[2] = lw_(R[16]);  /* 0x800CFB04 */
    sw_(R[17] + 608, R[19]);  /* 0x800CFB08 */
    sh_(R[17] + 586, R[20]);  /* 0x800CFB0C */
    { sw_(R[17] + 588, R[2]); goto L_800CFB54; }  /* 0x800CFB10 j */
L_800CFB18:;
    R[2] = lb_(R[17] + 785);  /* 0x800CFB18 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_800CFB60; } }  /* 0x800CFB20 */
L_800CFB28:;
    R[16] = R[0] + 8;  /* 0x800CFB28 */
    R[4] = R[17] + R[0];  /* 0x800CFB2C */
    R[5] = 0x800Fu << 16;  /* 0x800CFB30 */
    R[5] = R[5] - 196;  /* 0x800CFB34 */
    R[6] = R[16] + R[0];  /* 0x800CFB38 */
    R[2] = R[0] + 2;  /* 0x800CFB3C */
    { R[31] = 0x800CFB48u; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CFB40 jal */
    R[2] = R[0] + 4;  /* 0x800CFB48 */
    sh_(R[17] + 582, R[16]);  /* 0x800CFB4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFB50 */
L_800CFB54:;
    R[2] = R[0] + 3;  /* 0x800CFB54 */
    { sb_(R[17] + 786, R[2]); goto L_800CFDE0; }  /* 0x800CFB58 j */
L_800CFB60:;
    sb_(R[18] + 3, R[2]);  /* 0x800CFB60 */
    R[2] = lw_(R[17] + 604);  /* 0x800CFB64 */
    R[3] = lw_(R[17] + 600);  /* 0x800CFB68 */
    R[2] = R[2] - R[3];  /* 0x800CFB70 */
    sw_(R[17] + 604, R[2]);  /* 0x800CFB74 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CFB78 */
    sb_(R[18] + 52, R[2]);  /* 0x800CFB7C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFB80 */
    R[4] = R[17] + R[0];  /* 0x800CFB84 */
    { R[31] = 0x800CFB90u; sb_(R[18] + 53, R[2]); psx_next = 0x800CDCACu; return; }  /* 0x800CFB88 jal */
    { R[31] = 0x800CFB98u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CFB90 jal */
    R[4] = R[17] + R[0];  /* 0x800CFB98 */
    R[5] = R[0] + 5;  /* 0x800CFB9C */
    { R[31] = 0x800CFBA8u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800CFBA0 jal */
    { goto L_800CFDE0; }  /* 0x800CFBA8 j */
L_800CFBB0:;
    R[5] = lw_(R[17] + 588);  /* 0x800CFBB0 */
    { R[31] = 0x800CFBBCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CFBB4 jal */
    R[4] = R[17] + R[0];  /* 0x800CFBBC */
    R[5] = 0x8014u << 16;  /* 0x800CFBC0 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFBC4 */
    R[5] = R[5] + 15160;  /* 0x800CFBC8 */
    R[2] = R[3] << 3;  /* 0x800CFBCC */
    R[2] = R[2] + R[3];  /* 0x800CFBD0 */
    R[2] = R[2] << 7;  /* 0x800CFBD4 */
    { R[31] = 0x800CFBE0u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFBD8 jal */
    R[5] = R[0] + 1;  /* 0x800CFBE0 */
    R[6] = R[5] + R[0];  /* 0x800CFBE4 */
    R[2] = 0x8014u << 16;  /* 0x800CFBE8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CFBEC */
    R[16] = R[2] + 15136;  /* 0x800CFBF0 */
    R[4] = R[4] << 2;  /* 0x800CFBF4 */
    { R[31] = 0x800CFC00u; R[4] = R[4] + R[16]; psx_next = 0x800CCF94u; return; }  /* 0x800CFBF8 jal */
    { uint32_t _c = (R[2] == R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CFD20; } }  /* 0x800CFC00 */
    R[2] = lh_(R[17] + 582);  /* 0x800CFC08 */
    R[2] = R[2] - 1;  /* 0x800CFC10 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFC14 */
    R[2] = R[2] << 16;  /* 0x800CFC18 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[5] = R[0] + 1; if (_c) { goto L_800CFDE0; } }  /* 0x800CFC1C */
    R[4] = lb_(R[17] + 585);  /* 0x800CFC24 */
    R[6] = R[5] + R[0];  /* 0x800CFC28 */
    R[4] = R[4] << 2;  /* 0x800CFC2C */
    { R[31] = 0x800CFC38u; R[4] = R[4] + R[16]; psx_next = 0x800CD028u; return; }  /* 0x800CFC30 jal */
    R[2] = 0x800Fu << 16;  /* 0x800CFC38 */
    R[3] = lw_(R[17] + 588);  /* 0x800CFC3C */
    R[2] = R[2] - 416;  /* 0x800CFC40 */
    sw_(R[17] + 608, R[0]);  /* 0x800CFC44 */
    sh_(R[17] + 14, R[0]);  /* 0x800CFC48 */
    sw_(R[17] + 84, R[2]);  /* 0x800CFC4C */
    R[2] = lb_(R[3] + 2);  /* 0x800CFC50 */
    sh_(R[17] + 596, R[0]);  /* 0x800CFC54 */
    sh_(R[17] + 582, R[19]);  /* 0x800CFC58 */
    sh_(R[17] + 586, R[19]);  /* 0x800CFC5C */
    { sb_(R[17] + 801, R[2]); goto L_800CFDE0; }  /* 0x800CFC60 j */
L_800CFC68:;
    R[2] = lw_(R[17] + 588);  /* 0x800CFC68 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 224);  /* 0x800CFC70 */
    R[2] = lh_(R[2] + 224);  /* 0x800CFC74 */
    { uint32_t _c = ((int32_t)R[3] <= 0); R[4] = R[17] + R[0]; if (_c) { goto L_800CFC84; } }  /* 0x800CFC78 */
    sh_(R[17] + 596, R[2]);  /* 0x800CFC80 */
L_800CFC84:;
    R[5] = 0x8014u << 16;  /* 0x800CFC84 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFC88 */
    R[5] = R[5] + 15160;  /* 0x800CFC8C */
    R[2] = R[3] << 3;  /* 0x800CFC90 */
    R[2] = R[2] + R[3];  /* 0x800CFC94 */
    R[2] = R[2] << 7;  /* 0x800CFC98 */
    { R[31] = 0x800CFCA4u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFC9C jal */
    R[3] = lh_(R[17] + 582);  /* 0x800CFCA4 */
    R[3] = R[3] - 1;  /* 0x800CFCAC */
    sh_(R[17] + 582, R[3]);  /* 0x800CFCB0 */
    R[3] = R[3] << 16;  /* 0x800CFCB4 */
    { uint32_t _c = ((int32_t)R[3] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFCB8 */
    { uint32_t _c = ((int32_t)R[2] <= 0); sw_(R[17] + 84, R[0]); if (_c) { goto L_800CFCD4; } }  /* 0x800CFCC0 */
    R[2] = R[0] + 3;  /* 0x800CFCC8 */
    { sh_(R[17] + 586, R[2]); goto L_800CFDE0; }  /* 0x800CFCCC j */
L_800CFCD4:;
    R[2] = R[0] + 4;  /* 0x800CFCD4 */
    { sb_(R[17] + 790, R[2]); goto L_800CFDE0; }  /* 0x800CFCD8 j */
L_800CFCE0:;
    R[3] = lb_(R[17] + 585);  /* 0x800CFCE0 */
    R[5] = 0x8014u << 16;  /* 0x800CFCE4 */
    R[5] = R[5] + 15160;  /* 0x800CFCE8 */
    R[2] = R[3] << 3;  /* 0x800CFCEC */
    R[2] = R[2] + R[3];  /* 0x800CFCF0 */
    R[2] = R[2] << 7;  /* 0x800CFCF4 */
    { R[31] = 0x800CFD00u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFCF8 jal */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD00 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 596);  /* 0x800CFD08 */
    { uint32_t _c = ((int32_t)R[4] <= 0); R[2] = R[0] + 4; if (_c) { goto L_800CFD24; } }  /* 0x800CFD10 */
    { R[31] = 0x800CFD20u; psx_next = 0x8001D0DCu; return; }  /* 0x800CFD18 jal */
L_800CFD20:;
    R[2] = R[0] + 4;  /* 0x800CFD20 */
L_800CFD24:;
    sh_(R[17] + 582, R[0]);  /* 0x800CFD24 */
    { sb_(R[17] + 790, R[2]); goto L_800CFDE0; }  /* 0x800CFD28 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CFD30 */
    R[2] = R[2] - 1;  /* 0x800CFD38 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFD3C */
    R[2] = R[2] << 16;  /* 0x800CFD40 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CFD74; } }  /* 0x800CFD44 */
    R[3] = 0x8014u << 16;  /* 0x800CFD4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFD50 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CFD54 */
    R[2] = R[2] - 1;  /* 0x800CFD5C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD60 */
    R[2] = 0x8013u << 16;  /* 0x800CFD68 */
    { sh_(R[2] + -29614, R[0]); goto L_800CFDE0; }  /* 0x800CFD6C j */
L_800CFD74:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CFD74 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CFDD8; } }  /* 0x800CFD7C */
    R[2] = lw_(R[17] + 604);  /* 0x800CFD84 */
    R[3] = lw_(R[17] + 600);  /* 0x800CFD88 */
    R[2] = R[2] - R[3];  /* 0x800CFD90 */
    sw_(R[17] + 604, R[2]);  /* 0x800CFD94 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CFD98 */
    sb_(R[18] + 52, R[2]);  /* 0x800CFD9C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDA0 */
    sb_(R[18] + 53, R[2]);  /* 0x800CFDA8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CFDAC */
    { R[31] = 0x800CFDB8u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CFDB0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDB8 */
    R[4] = R[17] + R[0];  /* 0x800CFDBC */
    R[3] = R[2] + R[0];  /* 0x800CFDC0 */
    sh_(R[4] + 60, R[2]);  /* 0x800CFDC4 */
    { R[31] = 0x800CFDD0u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CFDC8 jal */
    { goto L_800CFDE0; }  /* 0x800CFDD0 j */
L_800CFDD8:;
    { R[31] = 0x800CFDE0u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CFDD8 jal */
L_800CFDE0:;
    R[31] = lw_(R[29] + 52);  /* 0x800CFDE0 */
    R[20] = lw_(R[29] + 48);  /* 0x800CFDE4 */
    R[19] = lw_(R[29] + 44);  /* 0x800CFDE8 */
    R[18] = lw_(R[29] + 40);  /* 0x800CFDEC */
    R[17] = lw_(R[29] + 36);  /* 0x800CFDF0 */
    R[16] = lw_(R[29] + 32);  /* 0x800CFDF4 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CFDF8 jr ra */
}

void g0_800CF89C(void) {
    R[4] = R[17] + R[0];  /* 0x800CF89C */
    R[5] = 0x800Fu << 16;  /* 0x800CF8A0 */
    { R[31] = 0x800CF8ACu; R[5] = R[5] - 396; psx_next = 0x800CD894u; return; }  /* 0x800CF8A4 jal */
    { goto L_800CFDE0; }  /* 0x800CF8AC j */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 586);  /* 0x800CF8B4 */
    { uint32_t _c = (R[3] == R[20]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_800CFBB0; } }  /* 0x800CF8BC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CF8DC; } }  /* 0x800CF8C4 */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_800CF8F4; } }  /* 0x800CF8CC */
    { goto L_800CFDE0; }  /* 0x800CF8D4 j */
L_800CF8DC:;
    { uint32_t _c = (R[3] == R[19]); R[2] = R[0] + 3; if (_c) { goto L_800CFC68; } }  /* 0x800CF8DC */
    { uint32_t _c = (R[3] == R[2]); R[4] = R[17] + R[0]; if (_c) { goto L_800CFCE0; } }  /* 0x800CF8E4 */
    { goto L_800CFDE0; }  /* 0x800CF8EC j */
L_800CF8F4:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF8F4 */
    R[2] = R[2] - 1;  /* 0x800CF8FC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF900 */
    R[2] = R[2] << 16;  /* 0x800CF904 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[16] = R[0] + 8; if (_c) { goto L_800CF990; } }  /* 0x800CF908 */
    R[4] = R[0] - 128;  /* 0x800CF910 */
    psx_div((int32_t)R[4], (int32_t)R[16]);  /* 0x800CF914 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CF924; } }  /* 0x800CF918 */
    psx_break(7168);  /* 0x800CF920 */
L_800CF924:;
    R[1] = R[0] - 1;  /* 0x800CF924 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF93C; } }  /* 0x800CF928 */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CF93C; } }  /* 0x800CF930 */
    psx_break(6144);  /* 0x800CF938 */
L_800CF93C:;
    R[4] = LO;  /* 0x800CF93C */
    R[3] = lw_(R[17] + 604);  /* 0x800CF940 */
    psx_div((int32_t)R[3], (int32_t)R[16]);  /* 0x800CF948 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CF958; } }  /* 0x800CF94C */
    psx_break(7168);  /* 0x800CF954 */
L_800CF958:;
    R[1] = R[0] - 1;  /* 0x800CF958 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF970; } }  /* 0x800CF95C */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CF970; } }  /* 0x800CF964 */
    psx_break(6144);  /* 0x800CF96C */
L_800CF970:;
    R[3] = LO;  /* 0x800CF970 */
    sb_(R[17] + 584, R[0]);  /* 0x800CF974 */
    sh_(R[17] + 582, R[16]);  /* 0x800CF978 */
    R[2] = R[0] + 4;  /* 0x800CF97C */
    sb_(R[17] + 790, R[2]);  /* 0x800CF980 */
    sh_(R[17] + 592, R[4]);  /* 0x800CF984 */
    { sw_(R[17] + 600, R[3]); goto L_800CFDE0; }  /* 0x800CF988 j */
L_800CF990:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 218);  /* 0x800CF990 */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[5] = R[0] + 16; if (_c) { goto L_800CFB18; } }  /* 0x800CF998 */
    R[2] = lb_(R[17] + 585);  /* 0x800CF9A0 */
    R[3] = R[2] << 3;  /* 0x800CF9A8 */
    R[3] = R[3] + R[2];  /* 0x800CF9AC */
    R[3] = R[3] << 7;  /* 0x800CF9B0 */
    R[2] = 0x8014u << 16;  /* 0x800CF9B4 */
    R[2] = R[2] + 15160;  /* 0x800CF9B8 */
    R[18] = R[3] + R[2];  /* 0x800CF9BC */
    { R[31] = 0x800CF9C8u; R[4] = R[18] + R[0]; psx_next = 0x800CD6CCu; return; }  /* 0x800CF9C0 jal */
    R[4] = R[17] + R[0];  /* 0x800CF9C8 */
    R[5] = R[0] + 1;  /* 0x800CF9CC */
    R[2] = 0x8014u << 16;  /* 0x800CF9D0 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF9D4 */
    R[2] = R[2] + 15136;  /* 0x800CF9D8 */
    R[3] = R[3] << 2;  /* 0x800CF9DC */
    R[16] = R[3] + R[2];  /* 0x800CF9E0 */
    { R[31] = 0x800CF9ECu; R[6] = R[16] + R[0]; psx_next = 0x800CE504u; return; }  /* 0x800CF9E4 jal */
    R[19] = R[2] + R[0];  /* 0x800CF9EC */
    { uint32_t _c = ((int32_t)R[19] <= 0); if (_c) { goto L_800CFB28; } }  /* 0x800CF9F0 */
    { R[31] = 0x800CFA00u; R[4] = R[0] + 57; psx_next = 0x8002DB10u; return; }  /* 0x800CF9F8 jal */
    sb_(R[17] + 584, R[20]);  /* 0x800CFA00 */
    sw_(R[17] + 124, R[0]);  /* 0x800CFA04 */
    sw_(R[17] + 188, R[0]);  /* 0x800CFA08 */
    R[2] = lw_(R[16]);  /* 0x800CFA0C */
    R[2] = lw_(R[2] + 24);  /* 0x800CFA14 */
    sw_(R[29] + 16, R[2]);  /* 0x800CFA1C */
    R[2] = lw_(R[17] + 28);  /* 0x800CFA20 */
    sw_(R[29] + 20, R[2]);  /* 0x800CFA28 */
    R[2] = lw_(R[16]);  /* 0x800CFA2C */
    R[2] = lw_(R[2] + 32);  /* 0x800CFA34 */
    sw_(R[29] + 24, R[2]);  /* 0x800CFA3C */
    R[2] = lw_(R[16]);  /* 0x800CFA40 */
    R[2] = lw_(R[2] + 24);  /* 0x800CFA48 */
    sw_(R[17] + 24, R[2]);  /* 0x800CFA50 */
    R[2] = lw_(R[16]);  /* 0x800CFA54 */
    R[2] = lw_(R[2] + 28);  /* 0x800CFA5C */
    sw_(R[17] + 28, R[2]);  /* 0x800CFA64 */
    R[2] = lw_(R[16]);  /* 0x800CFA68 */
    R[6] = lb_(R[17] + 585);  /* 0x800CFA6C */
    R[2] = lw_(R[2] + 32);  /* 0x800CFA70 */
    R[5] = 0x800Fu << 16;  /* 0x800CFA74 */
    sw_(R[17] + 32, R[2]);  /* 0x800CFA78 */
    R[4] = lw_(R[16]);  /* 0x800CFA7C */
    { R[31] = 0x800CFA88u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CFA80 jal */
    R[4] = R[29] + 16;  /* 0x800CFA88 */
    { R[31] = 0x800CFA94u; R[5] = R[18] + R[0]; psx_next = 0x800CE808u; return; }  /* 0x800CFA8C jal */
    R[3] = lw_(R[16]);  /* 0x800CFA94 */
    R[4] = R[0] + 17;  /* 0x800CFA98 */
    R[2] = lb_(R[3] + 789);  /* 0x800CFA9C */
    R[6] = 0x8011u << 16;  /* 0x800CFAA0 */
    R[2] = R[2] | 0x2;  /* 0x800CFAA4 */
    sb_(R[3] + 789, R[2]);  /* 0x800CFAA8 */
    R[5] = lw_(R[16]);  /* 0x800CFAAC */
    { R[31] = 0x800CFAB8u; R[6] = R[6] + 30196; psx_next = 0x800AC93Cu; return; }  /* 0x800CFAB0 jal */
    R[4] = lw_(R[16]);  /* 0x800CFAB8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CFAC0 */
    R[3] = R[0] - 897;  /* 0x800CFAC4 */
    R[2] = R[2] & R[3];  /* 0x800CFAC8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CFACC */
    R[3] = lw_(R[16]);  /* 0x800CFAD0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CFAD8 */
    R[2] = R[2] | 0x200;  /* 0x800CFAE0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CFAE4 */
    R[2] = R[0] + 15;  /* 0x800CFAE8 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFAEC */
    R[2] = R[0] + 45;  /* 0x800CFAF0 */
    sh_(R[17] + 592, R[2]);  /* 0x800CFAF4 */
    R[2] = R[0] + 8192;  /* 0x800CFAF8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CFAFC */
    sh_(R[17] + 594, R[2]);  /* 0x800CFB00 */
    R[2] = lw_(R[16]);  /* 0x800CFB04 */
    sw_(R[17] + 608, R[19]);  /* 0x800CFB08 */
    sh_(R[17] + 586, R[20]);  /* 0x800CFB0C */
    { sw_(R[17] + 588, R[2]); goto L_800CFB54; }  /* 0x800CFB10 j */
L_800CFB18:;
    R[2] = lb_(R[17] + 785);  /* 0x800CFB18 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_800CFB60; } }  /* 0x800CFB20 */
L_800CFB28:;
    R[16] = R[0] + 8;  /* 0x800CFB28 */
    R[4] = R[17] + R[0];  /* 0x800CFB2C */
    R[5] = 0x800Fu << 16;  /* 0x800CFB30 */
    R[5] = R[5] - 196;  /* 0x800CFB34 */
    R[6] = R[16] + R[0];  /* 0x800CFB38 */
    R[2] = R[0] + 2;  /* 0x800CFB3C */
    { R[31] = 0x800CFB48u; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CFB40 jal */
    R[2] = R[0] + 4;  /* 0x800CFB48 */
    sh_(R[17] + 582, R[16]);  /* 0x800CFB4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFB50 */
L_800CFB54:;
    R[2] = R[0] + 3;  /* 0x800CFB54 */
    { sb_(R[17] + 786, R[2]); goto L_800CFDE0; }  /* 0x800CFB58 j */
L_800CFB60:;
    sb_(R[18] + 3, R[2]);  /* 0x800CFB60 */
    R[2] = lw_(R[17] + 604);  /* 0x800CFB64 */
    R[3] = lw_(R[17] + 600);  /* 0x800CFB68 */
    R[2] = R[2] - R[3];  /* 0x800CFB70 */
    sw_(R[17] + 604, R[2]);  /* 0x800CFB74 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CFB78 */
    sb_(R[18] + 52, R[2]);  /* 0x800CFB7C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFB80 */
    R[4] = R[17] + R[0];  /* 0x800CFB84 */
    { R[31] = 0x800CFB90u; sb_(R[18] + 53, R[2]); psx_next = 0x800CDCACu; return; }  /* 0x800CFB88 jal */
    { R[31] = 0x800CFB98u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CFB90 jal */
    R[4] = R[17] + R[0];  /* 0x800CFB98 */
    R[5] = R[0] + 5;  /* 0x800CFB9C */
    { R[31] = 0x800CFBA8u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800CFBA0 jal */
    { goto L_800CFDE0; }  /* 0x800CFBA8 j */
L_800CFBB0:;
    R[5] = lw_(R[17] + 588);  /* 0x800CFBB0 */
    { R[31] = 0x800CFBBCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CFBB4 jal */
    R[4] = R[17] + R[0];  /* 0x800CFBBC */
    R[5] = 0x8014u << 16;  /* 0x800CFBC0 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFBC4 */
    R[5] = R[5] + 15160;  /* 0x800CFBC8 */
    R[2] = R[3] << 3;  /* 0x800CFBCC */
    R[2] = R[2] + R[3];  /* 0x800CFBD0 */
    R[2] = R[2] << 7;  /* 0x800CFBD4 */
    { R[31] = 0x800CFBE0u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFBD8 jal */
    R[5] = R[0] + 1;  /* 0x800CFBE0 */
    R[6] = R[5] + R[0];  /* 0x800CFBE4 */
    R[2] = 0x8014u << 16;  /* 0x800CFBE8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CFBEC */
    R[16] = R[2] + 15136;  /* 0x800CFBF0 */
    R[4] = R[4] << 2;  /* 0x800CFBF4 */
    { R[31] = 0x800CFC00u; R[4] = R[4] + R[16]; psx_next = 0x800CCF94u; return; }  /* 0x800CFBF8 jal */
    { uint32_t _c = (R[2] == R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CFD20; } }  /* 0x800CFC00 */
    R[2] = lh_(R[17] + 582);  /* 0x800CFC08 */
    R[2] = R[2] - 1;  /* 0x800CFC10 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFC14 */
    R[2] = R[2] << 16;  /* 0x800CFC18 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[5] = R[0] + 1; if (_c) { goto L_800CFDE0; } }  /* 0x800CFC1C */
    R[4] = lb_(R[17] + 585);  /* 0x800CFC24 */
    R[6] = R[5] + R[0];  /* 0x800CFC28 */
    R[4] = R[4] << 2;  /* 0x800CFC2C */
    { R[31] = 0x800CFC38u; R[4] = R[4] + R[16]; psx_next = 0x800CD028u; return; }  /* 0x800CFC30 jal */
    R[2] = 0x800Fu << 16;  /* 0x800CFC38 */
    R[3] = lw_(R[17] + 588);  /* 0x800CFC3C */
    R[2] = R[2] - 416;  /* 0x800CFC40 */
    sw_(R[17] + 608, R[0]);  /* 0x800CFC44 */
    sh_(R[17] + 14, R[0]);  /* 0x800CFC48 */
    sw_(R[17] + 84, R[2]);  /* 0x800CFC4C */
    R[2] = lb_(R[3] + 2);  /* 0x800CFC50 */
    sh_(R[17] + 596, R[0]);  /* 0x800CFC54 */
    sh_(R[17] + 582, R[19]);  /* 0x800CFC58 */
    sh_(R[17] + 586, R[19]);  /* 0x800CFC5C */
    { sb_(R[17] + 801, R[2]); goto L_800CFDE0; }  /* 0x800CFC60 j */
L_800CFC68:;
    R[2] = lw_(R[17] + 588);  /* 0x800CFC68 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 224);  /* 0x800CFC70 */
    R[2] = lh_(R[2] + 224);  /* 0x800CFC74 */
    { uint32_t _c = ((int32_t)R[3] <= 0); R[4] = R[17] + R[0]; if (_c) { goto L_800CFC84; } }  /* 0x800CFC78 */
    sh_(R[17] + 596, R[2]);  /* 0x800CFC80 */
L_800CFC84:;
    R[5] = 0x8014u << 16;  /* 0x800CFC84 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFC88 */
    R[5] = R[5] + 15160;  /* 0x800CFC8C */
    R[2] = R[3] << 3;  /* 0x800CFC90 */
    R[2] = R[2] + R[3];  /* 0x800CFC94 */
    R[2] = R[2] << 7;  /* 0x800CFC98 */
    { R[31] = 0x800CFCA4u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFC9C jal */
    R[3] = lh_(R[17] + 582);  /* 0x800CFCA4 */
    R[3] = R[3] - 1;  /* 0x800CFCAC */
    sh_(R[17] + 582, R[3]);  /* 0x800CFCB0 */
    R[3] = R[3] << 16;  /* 0x800CFCB4 */
    { uint32_t _c = ((int32_t)R[3] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFCB8 */
    { uint32_t _c = ((int32_t)R[2] <= 0); sw_(R[17] + 84, R[0]); if (_c) { goto L_800CFCD4; } }  /* 0x800CFCC0 */
    R[2] = R[0] + 3;  /* 0x800CFCC8 */
    { sh_(R[17] + 586, R[2]); goto L_800CFDE0; }  /* 0x800CFCCC j */
L_800CFCD4:;
    R[2] = R[0] + 4;  /* 0x800CFCD4 */
    { sb_(R[17] + 790, R[2]); goto L_800CFDE0; }  /* 0x800CFCD8 j */
L_800CFCE0:;
    R[3] = lb_(R[17] + 585);  /* 0x800CFCE0 */
    R[5] = 0x8014u << 16;  /* 0x800CFCE4 */
    R[5] = R[5] + 15160;  /* 0x800CFCE8 */
    R[2] = R[3] << 3;  /* 0x800CFCEC */
    R[2] = R[2] + R[3];  /* 0x800CFCF0 */
    R[2] = R[2] << 7;  /* 0x800CFCF4 */
    { R[31] = 0x800CFD00u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFCF8 jal */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD00 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 596);  /* 0x800CFD08 */
    { uint32_t _c = ((int32_t)R[4] <= 0); R[2] = R[0] + 4; if (_c) { goto L_800CFD24; } }  /* 0x800CFD10 */
    { R[31] = 0x800CFD20u; psx_next = 0x8001D0DCu; return; }  /* 0x800CFD18 jal */
L_800CFD20:;
    R[2] = R[0] + 4;  /* 0x800CFD20 */
L_800CFD24:;
    sh_(R[17] + 582, R[0]);  /* 0x800CFD24 */
    { sb_(R[17] + 790, R[2]); goto L_800CFDE0; }  /* 0x800CFD28 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CFD30 */
    R[2] = R[2] - 1;  /* 0x800CFD38 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFD3C */
    R[2] = R[2] << 16;  /* 0x800CFD40 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CFD74; } }  /* 0x800CFD44 */
    R[3] = 0x8014u << 16;  /* 0x800CFD4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFD50 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CFD54 */
    R[2] = R[2] - 1;  /* 0x800CFD5C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD60 */
    R[2] = 0x8013u << 16;  /* 0x800CFD68 */
    { sh_(R[2] + -29614, R[0]); goto L_800CFDE0; }  /* 0x800CFD6C j */
L_800CFD74:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CFD74 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CFDD8; } }  /* 0x800CFD7C */
    R[2] = lw_(R[17] + 604);  /* 0x800CFD84 */
    R[3] = lw_(R[17] + 600);  /* 0x800CFD88 */
    R[2] = R[2] - R[3];  /* 0x800CFD90 */
    sw_(R[17] + 604, R[2]);  /* 0x800CFD94 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CFD98 */
    sb_(R[18] + 52, R[2]);  /* 0x800CFD9C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDA0 */
    sb_(R[18] + 53, R[2]);  /* 0x800CFDA8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CFDAC */
    { R[31] = 0x800CFDB8u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CFDB0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDB8 */
    R[4] = R[17] + R[0];  /* 0x800CFDBC */
    R[3] = R[2] + R[0];  /* 0x800CFDC0 */
    sh_(R[4] + 60, R[2]);  /* 0x800CFDC4 */
    { R[31] = 0x800CFDD0u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CFDC8 jal */
    { goto L_800CFDE0; }  /* 0x800CFDD0 j */
L_800CFDD8:;
    { R[31] = 0x800CFDE0u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CFDD8 jal */
L_800CFDE0:;
    R[31] = lw_(R[29] + 52);  /* 0x800CFDE0 */
    R[20] = lw_(R[29] + 48);  /* 0x800CFDE4 */
    R[19] = lw_(R[29] + 44);  /* 0x800CFDE8 */
    R[18] = lw_(R[29] + 40);  /* 0x800CFDEC */
    R[17] = lw_(R[29] + 36);  /* 0x800CFDF0 */
    R[16] = lw_(R[29] + 32);  /* 0x800CFDF4 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CFDF8 jr ra */
}

void g0_800CF8AC(void) {
    { goto L_800CFDE0; }  /* 0x800CF8AC j */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 586);  /* 0x800CF8B4 */
    { uint32_t _c = (R[3] == R[20]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_800CFBB0; } }  /* 0x800CF8BC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CF8DC; } }  /* 0x800CF8C4 */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_800CF8F4; } }  /* 0x800CF8CC */
    { goto L_800CFDE0; }  /* 0x800CF8D4 j */
L_800CF8DC:;
    { uint32_t _c = (R[3] == R[19]); R[2] = R[0] + 3; if (_c) { goto L_800CFC68; } }  /* 0x800CF8DC */
    { uint32_t _c = (R[3] == R[2]); R[4] = R[17] + R[0]; if (_c) { goto L_800CFCE0; } }  /* 0x800CF8E4 */
    { goto L_800CFDE0; }  /* 0x800CF8EC j */
L_800CF8F4:;
    R[2] = lh_(R[17] + 582);  /* 0x800CF8F4 */
    R[2] = R[2] - 1;  /* 0x800CF8FC */
    sh_(R[17] + 582, R[2]);  /* 0x800CF900 */
    R[2] = R[2] << 16;  /* 0x800CF904 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[16] = R[0] + 8; if (_c) { goto L_800CF990; } }  /* 0x800CF908 */
    R[4] = R[0] - 128;  /* 0x800CF910 */
    psx_div((int32_t)R[4], (int32_t)R[16]);  /* 0x800CF914 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CF924; } }  /* 0x800CF918 */
    psx_break(7168);  /* 0x800CF920 */
L_800CF924:;
    R[1] = R[0] - 1;  /* 0x800CF924 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF93C; } }  /* 0x800CF928 */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CF93C; } }  /* 0x800CF930 */
    psx_break(6144);  /* 0x800CF938 */
L_800CF93C:;
    R[4] = LO;  /* 0x800CF93C */
    R[3] = lw_(R[17] + 604);  /* 0x800CF940 */
    psx_div((int32_t)R[3], (int32_t)R[16]);  /* 0x800CF948 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CF958; } }  /* 0x800CF94C */
    psx_break(7168);  /* 0x800CF954 */
L_800CF958:;
    R[1] = R[0] - 1;  /* 0x800CF958 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CF970; } }  /* 0x800CF95C */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CF970; } }  /* 0x800CF964 */
    psx_break(6144);  /* 0x800CF96C */
L_800CF970:;
    R[3] = LO;  /* 0x800CF970 */
    sb_(R[17] + 584, R[0]);  /* 0x800CF974 */
    sh_(R[17] + 582, R[16]);  /* 0x800CF978 */
    R[2] = R[0] + 4;  /* 0x800CF97C */
    sb_(R[17] + 790, R[2]);  /* 0x800CF980 */
    sh_(R[17] + 592, R[4]);  /* 0x800CF984 */
    { sw_(R[17] + 600, R[3]); goto L_800CFDE0; }  /* 0x800CF988 j */
L_800CF990:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 218);  /* 0x800CF990 */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[5] = R[0] + 16; if (_c) { goto L_800CFB18; } }  /* 0x800CF998 */
    R[2] = lb_(R[17] + 585);  /* 0x800CF9A0 */
    R[3] = R[2] << 3;  /* 0x800CF9A8 */
    R[3] = R[3] + R[2];  /* 0x800CF9AC */
    R[3] = R[3] << 7;  /* 0x800CF9B0 */
    R[2] = 0x8014u << 16;  /* 0x800CF9B4 */
    R[2] = R[2] + 15160;  /* 0x800CF9B8 */
    R[18] = R[3] + R[2];  /* 0x800CF9BC */
    { R[31] = 0x800CF9C8u; R[4] = R[18] + R[0]; psx_next = 0x800CD6CCu; return; }  /* 0x800CF9C0 jal */
    R[4] = R[17] + R[0];  /* 0x800CF9C8 */
    R[5] = R[0] + 1;  /* 0x800CF9CC */
    R[2] = 0x8014u << 16;  /* 0x800CF9D0 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF9D4 */
    R[2] = R[2] + 15136;  /* 0x800CF9D8 */
    R[3] = R[3] << 2;  /* 0x800CF9DC */
    R[16] = R[3] + R[2];  /* 0x800CF9E0 */
    { R[31] = 0x800CF9ECu; R[6] = R[16] + R[0]; psx_next = 0x800CE504u; return; }  /* 0x800CF9E4 jal */
    R[19] = R[2] + R[0];  /* 0x800CF9EC */
    { uint32_t _c = ((int32_t)R[19] <= 0); if (_c) { goto L_800CFB28; } }  /* 0x800CF9F0 */
    { R[31] = 0x800CFA00u; R[4] = R[0] + 57; psx_next = 0x8002DB10u; return; }  /* 0x800CF9F8 jal */
    sb_(R[17] + 584, R[20]);  /* 0x800CFA00 */
    sw_(R[17] + 124, R[0]);  /* 0x800CFA04 */
    sw_(R[17] + 188, R[0]);  /* 0x800CFA08 */
    R[2] = lw_(R[16]);  /* 0x800CFA0C */
    R[2] = lw_(R[2] + 24);  /* 0x800CFA14 */
    sw_(R[29] + 16, R[2]);  /* 0x800CFA1C */
    R[2] = lw_(R[17] + 28);  /* 0x800CFA20 */
    sw_(R[29] + 20, R[2]);  /* 0x800CFA28 */
    R[2] = lw_(R[16]);  /* 0x800CFA2C */
    R[2] = lw_(R[2] + 32);  /* 0x800CFA34 */
    sw_(R[29] + 24, R[2]);  /* 0x800CFA3C */
    R[2] = lw_(R[16]);  /* 0x800CFA40 */
    R[2] = lw_(R[2] + 24);  /* 0x800CFA48 */
    sw_(R[17] + 24, R[2]);  /* 0x800CFA50 */
    R[2] = lw_(R[16]);  /* 0x800CFA54 */
    R[2] = lw_(R[2] + 28);  /* 0x800CFA5C */
    sw_(R[17] + 28, R[2]);  /* 0x800CFA64 */
    R[2] = lw_(R[16]);  /* 0x800CFA68 */
    R[6] = lb_(R[17] + 585);  /* 0x800CFA6C */
    R[2] = lw_(R[2] + 32);  /* 0x800CFA70 */
    R[5] = 0x800Fu << 16;  /* 0x800CFA74 */
    sw_(R[17] + 32, R[2]);  /* 0x800CFA78 */
    R[4] = lw_(R[16]);  /* 0x800CFA7C */
    { R[31] = 0x800CFA88u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CFA80 jal */
    R[4] = R[29] + 16;  /* 0x800CFA88 */
    { R[31] = 0x800CFA94u; R[5] = R[18] + R[0]; psx_next = 0x800CE808u; return; }  /* 0x800CFA8C jal */
    R[3] = lw_(R[16]);  /* 0x800CFA94 */
    R[4] = R[0] + 17;  /* 0x800CFA98 */
    R[2] = lb_(R[3] + 789);  /* 0x800CFA9C */
    R[6] = 0x8011u << 16;  /* 0x800CFAA0 */
    R[2] = R[2] | 0x2;  /* 0x800CFAA4 */
    sb_(R[3] + 789, R[2]);  /* 0x800CFAA8 */
    R[5] = lw_(R[16]);  /* 0x800CFAAC */
    { R[31] = 0x800CFAB8u; R[6] = R[6] + 30196; psx_next = 0x800AC93Cu; return; }  /* 0x800CFAB0 jal */
    R[4] = lw_(R[16]);  /* 0x800CFAB8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CFAC0 */
    R[3] = R[0] - 897;  /* 0x800CFAC4 */
    R[2] = R[2] & R[3];  /* 0x800CFAC8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CFACC */
    R[3] = lw_(R[16]);  /* 0x800CFAD0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CFAD8 */
    R[2] = R[2] | 0x200;  /* 0x800CFAE0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CFAE4 */
    R[2] = R[0] + 15;  /* 0x800CFAE8 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFAEC */
    R[2] = R[0] + 45;  /* 0x800CFAF0 */
    sh_(R[17] + 592, R[2]);  /* 0x800CFAF4 */
    R[2] = R[0] + 8192;  /* 0x800CFAF8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CFAFC */
    sh_(R[17] + 594, R[2]);  /* 0x800CFB00 */
    R[2] = lw_(R[16]);  /* 0x800CFB04 */
    sw_(R[17] + 608, R[19]);  /* 0x800CFB08 */
    sh_(R[17] + 586, R[20]);  /* 0x800CFB0C */
    { sw_(R[17] + 588, R[2]); goto L_800CFB54; }  /* 0x800CFB10 j */
L_800CFB18:;
    R[2] = lb_(R[17] + 785);  /* 0x800CFB18 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_800CFB60; } }  /* 0x800CFB20 */
L_800CFB28:;
    R[16] = R[0] + 8;  /* 0x800CFB28 */
    R[4] = R[17] + R[0];  /* 0x800CFB2C */
    R[5] = 0x800Fu << 16;  /* 0x800CFB30 */
    R[5] = R[5] - 196;  /* 0x800CFB34 */
    R[6] = R[16] + R[0];  /* 0x800CFB38 */
    R[2] = R[0] + 2;  /* 0x800CFB3C */
    { R[31] = 0x800CFB48u; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CFB40 jal */
    R[2] = R[0] + 4;  /* 0x800CFB48 */
    sh_(R[17] + 582, R[16]);  /* 0x800CFB4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFB50 */
L_800CFB54:;
    R[2] = R[0] + 3;  /* 0x800CFB54 */
    { sb_(R[17] + 786, R[2]); goto L_800CFDE0; }  /* 0x800CFB58 j */
L_800CFB60:;
    sb_(R[18] + 3, R[2]);  /* 0x800CFB60 */
    R[2] = lw_(R[17] + 604);  /* 0x800CFB64 */
    R[3] = lw_(R[17] + 600);  /* 0x800CFB68 */
    R[2] = R[2] - R[3];  /* 0x800CFB70 */
    sw_(R[17] + 604, R[2]);  /* 0x800CFB74 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CFB78 */
    sb_(R[18] + 52, R[2]);  /* 0x800CFB7C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFB80 */
    R[4] = R[17] + R[0];  /* 0x800CFB84 */
    { R[31] = 0x800CFB90u; sb_(R[18] + 53, R[2]); psx_next = 0x800CDCACu; return; }  /* 0x800CFB88 jal */
    { R[31] = 0x800CFB98u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CFB90 jal */
    R[4] = R[17] + R[0];  /* 0x800CFB98 */
    R[5] = R[0] + 5;  /* 0x800CFB9C */
    { R[31] = 0x800CFBA8u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800CFBA0 jal */
    { goto L_800CFDE0; }  /* 0x800CFBA8 j */
L_800CFBB0:;
    R[5] = lw_(R[17] + 588);  /* 0x800CFBB0 */
    { R[31] = 0x800CFBBCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CFBB4 jal */
    R[4] = R[17] + R[0];  /* 0x800CFBBC */
    R[5] = 0x8014u << 16;  /* 0x800CFBC0 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFBC4 */
    R[5] = R[5] + 15160;  /* 0x800CFBC8 */
    R[2] = R[3] << 3;  /* 0x800CFBCC */
    R[2] = R[2] + R[3];  /* 0x800CFBD0 */
    R[2] = R[2] << 7;  /* 0x800CFBD4 */
    { R[31] = 0x800CFBE0u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFBD8 jal */
    R[5] = R[0] + 1;  /* 0x800CFBE0 */
    R[6] = R[5] + R[0];  /* 0x800CFBE4 */
    R[2] = 0x8014u << 16;  /* 0x800CFBE8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CFBEC */
    R[16] = R[2] + 15136;  /* 0x800CFBF0 */
    R[4] = R[4] << 2;  /* 0x800CFBF4 */
    { R[31] = 0x800CFC00u; R[4] = R[4] + R[16]; psx_next = 0x800CCF94u; return; }  /* 0x800CFBF8 jal */
    { uint32_t _c = (R[2] == R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CFD20; } }  /* 0x800CFC00 */
    R[2] = lh_(R[17] + 582);  /* 0x800CFC08 */
    R[2] = R[2] - 1;  /* 0x800CFC10 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFC14 */
    R[2] = R[2] << 16;  /* 0x800CFC18 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[5] = R[0] + 1; if (_c) { goto L_800CFDE0; } }  /* 0x800CFC1C */
    R[4] = lb_(R[17] + 585);  /* 0x800CFC24 */
    R[6] = R[5] + R[0];  /* 0x800CFC28 */
    R[4] = R[4] << 2;  /* 0x800CFC2C */
    { R[31] = 0x800CFC38u; R[4] = R[4] + R[16]; psx_next = 0x800CD028u; return; }  /* 0x800CFC30 jal */
    R[2] = 0x800Fu << 16;  /* 0x800CFC38 */
    R[3] = lw_(R[17] + 588);  /* 0x800CFC3C */
    R[2] = R[2] - 416;  /* 0x800CFC40 */
    sw_(R[17] + 608, R[0]);  /* 0x800CFC44 */
    sh_(R[17] + 14, R[0]);  /* 0x800CFC48 */
    sw_(R[17] + 84, R[2]);  /* 0x800CFC4C */
    R[2] = lb_(R[3] + 2);  /* 0x800CFC50 */
    sh_(R[17] + 596, R[0]);  /* 0x800CFC54 */
    sh_(R[17] + 582, R[19]);  /* 0x800CFC58 */
    sh_(R[17] + 586, R[19]);  /* 0x800CFC5C */
    { sb_(R[17] + 801, R[2]); goto L_800CFDE0; }  /* 0x800CFC60 j */
L_800CFC68:;
    R[2] = lw_(R[17] + 588);  /* 0x800CFC68 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 224);  /* 0x800CFC70 */
    R[2] = lh_(R[2] + 224);  /* 0x800CFC74 */
    { uint32_t _c = ((int32_t)R[3] <= 0); R[4] = R[17] + R[0]; if (_c) { goto L_800CFC84; } }  /* 0x800CFC78 */
    sh_(R[17] + 596, R[2]);  /* 0x800CFC80 */
L_800CFC84:;
    R[5] = 0x8014u << 16;  /* 0x800CFC84 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFC88 */
    R[5] = R[5] + 15160;  /* 0x800CFC8C */
    R[2] = R[3] << 3;  /* 0x800CFC90 */
    R[2] = R[2] + R[3];  /* 0x800CFC94 */
    R[2] = R[2] << 7;  /* 0x800CFC98 */
    { R[31] = 0x800CFCA4u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFC9C jal */
    R[3] = lh_(R[17] + 582);  /* 0x800CFCA4 */
    R[3] = R[3] - 1;  /* 0x800CFCAC */
    sh_(R[17] + 582, R[3]);  /* 0x800CFCB0 */
    R[3] = R[3] << 16;  /* 0x800CFCB4 */
    { uint32_t _c = ((int32_t)R[3] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFCB8 */
    { uint32_t _c = ((int32_t)R[2] <= 0); sw_(R[17] + 84, R[0]); if (_c) { goto L_800CFCD4; } }  /* 0x800CFCC0 */
    R[2] = R[0] + 3;  /* 0x800CFCC8 */
    { sh_(R[17] + 586, R[2]); goto L_800CFDE0; }  /* 0x800CFCCC j */
L_800CFCD4:;
    R[2] = R[0] + 4;  /* 0x800CFCD4 */
    { sb_(R[17] + 790, R[2]); goto L_800CFDE0; }  /* 0x800CFCD8 j */
L_800CFCE0:;
    R[3] = lb_(R[17] + 585);  /* 0x800CFCE0 */
    R[5] = 0x8014u << 16;  /* 0x800CFCE4 */
    R[5] = R[5] + 15160;  /* 0x800CFCE8 */
    R[2] = R[3] << 3;  /* 0x800CFCEC */
    R[2] = R[2] + R[3];  /* 0x800CFCF0 */
    R[2] = R[2] << 7;  /* 0x800CFCF4 */
    { R[31] = 0x800CFD00u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFCF8 jal */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD00 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 596);  /* 0x800CFD08 */
    { uint32_t _c = ((int32_t)R[4] <= 0); R[2] = R[0] + 4; if (_c) { goto L_800CFD24; } }  /* 0x800CFD10 */
    { R[31] = 0x800CFD20u; psx_next = 0x8001D0DCu; return; }  /* 0x800CFD18 jal */
L_800CFD20:;
    R[2] = R[0] + 4;  /* 0x800CFD20 */
L_800CFD24:;
    sh_(R[17] + 582, R[0]);  /* 0x800CFD24 */
    { sb_(R[17] + 790, R[2]); goto L_800CFDE0; }  /* 0x800CFD28 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CFD30 */
    R[2] = R[2] - 1;  /* 0x800CFD38 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFD3C */
    R[2] = R[2] << 16;  /* 0x800CFD40 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CFD74; } }  /* 0x800CFD44 */
    R[3] = 0x8014u << 16;  /* 0x800CFD4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFD50 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CFD54 */
    R[2] = R[2] - 1;  /* 0x800CFD5C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD60 */
    R[2] = 0x8013u << 16;  /* 0x800CFD68 */
    { sh_(R[2] + -29614, R[0]); goto L_800CFDE0; }  /* 0x800CFD6C j */
L_800CFD74:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CFD74 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CFDD8; } }  /* 0x800CFD7C */
    R[2] = lw_(R[17] + 604);  /* 0x800CFD84 */
    R[3] = lw_(R[17] + 600);  /* 0x800CFD88 */
    R[2] = R[2] - R[3];  /* 0x800CFD90 */
    sw_(R[17] + 604, R[2]);  /* 0x800CFD94 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CFD98 */
    sb_(R[18] + 52, R[2]);  /* 0x800CFD9C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDA0 */
    sb_(R[18] + 53, R[2]);  /* 0x800CFDA8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CFDAC */
    { R[31] = 0x800CFDB8u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CFDB0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDB8 */
    R[4] = R[17] + R[0];  /* 0x800CFDBC */
    R[3] = R[2] + R[0];  /* 0x800CFDC0 */
    sh_(R[4] + 60, R[2]);  /* 0x800CFDC4 */
    { R[31] = 0x800CFDD0u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CFDC8 jal */
    { goto L_800CFDE0; }  /* 0x800CFDD0 j */
L_800CFDD8:;
    { R[31] = 0x800CFDE0u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CFDD8 jal */
L_800CFDE0:;
    R[31] = lw_(R[29] + 52);  /* 0x800CFDE0 */
    R[20] = lw_(R[29] + 48);  /* 0x800CFDE4 */
    R[19] = lw_(R[29] + 44);  /* 0x800CFDE8 */
    R[18] = lw_(R[29] + 40);  /* 0x800CFDEC */
    R[17] = lw_(R[29] + 36);  /* 0x800CFDF0 */
    R[16] = lw_(R[29] + 32);  /* 0x800CFDF4 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CFDF8 jr ra */
}

void g0_800CF9C8(void) {
    R[4] = R[17] + R[0];  /* 0x800CF9C8 */
    R[5] = R[0] + 1;  /* 0x800CF9CC */
    R[2] = 0x8014u << 16;  /* 0x800CF9D0 */
    R[3] = lb_(R[17] + 585);  /* 0x800CF9D4 */
    R[2] = R[2] + 15136;  /* 0x800CF9D8 */
    R[3] = R[3] << 2;  /* 0x800CF9DC */
    R[16] = R[3] + R[2];  /* 0x800CF9E0 */
    { R[31] = 0x800CF9ECu; R[6] = R[16] + R[0]; psx_next = 0x800CE504u; return; }  /* 0x800CF9E4 jal */
    R[19] = R[2] + R[0];  /* 0x800CF9EC */
    { uint32_t _c = ((int32_t)R[19] <= 0); if (_c) { goto L_800CFB28; } }  /* 0x800CF9F0 */
    { R[31] = 0x800CFA00u; R[4] = R[0] + 57; psx_next = 0x8002DB10u; return; }  /* 0x800CF9F8 jal */
    sb_(R[17] + 584, R[20]);  /* 0x800CFA00 */
    sw_(R[17] + 124, R[0]);  /* 0x800CFA04 */
    sw_(R[17] + 188, R[0]);  /* 0x800CFA08 */
    R[2] = lw_(R[16]);  /* 0x800CFA0C */
    R[2] = lw_(R[2] + 24);  /* 0x800CFA14 */
    sw_(R[29] + 16, R[2]);  /* 0x800CFA1C */
    R[2] = lw_(R[17] + 28);  /* 0x800CFA20 */
    sw_(R[29] + 20, R[2]);  /* 0x800CFA28 */
    R[2] = lw_(R[16]);  /* 0x800CFA2C */
    R[2] = lw_(R[2] + 32);  /* 0x800CFA34 */
    sw_(R[29] + 24, R[2]);  /* 0x800CFA3C */
    R[2] = lw_(R[16]);  /* 0x800CFA40 */
    R[2] = lw_(R[2] + 24);  /* 0x800CFA48 */
    sw_(R[17] + 24, R[2]);  /* 0x800CFA50 */
    R[2] = lw_(R[16]);  /* 0x800CFA54 */
    R[2] = lw_(R[2] + 28);  /* 0x800CFA5C */
    sw_(R[17] + 28, R[2]);  /* 0x800CFA64 */
    R[2] = lw_(R[16]);  /* 0x800CFA68 */
    R[6] = lb_(R[17] + 585);  /* 0x800CFA6C */
    R[2] = lw_(R[2] + 32);  /* 0x800CFA70 */
    R[5] = 0x800Fu << 16;  /* 0x800CFA74 */
    sw_(R[17] + 32, R[2]);  /* 0x800CFA78 */
    R[4] = lw_(R[16]);  /* 0x800CFA7C */
    { R[31] = 0x800CFA88u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CFA80 jal */
    R[4] = R[29] + 16;  /* 0x800CFA88 */
    { R[31] = 0x800CFA94u; R[5] = R[18] + R[0]; psx_next = 0x800CE808u; return; }  /* 0x800CFA8C jal */
    R[3] = lw_(R[16]);  /* 0x800CFA94 */
    R[4] = R[0] + 17;  /* 0x800CFA98 */
    R[2] = lb_(R[3] + 789);  /* 0x800CFA9C */
    R[6] = 0x8011u << 16;  /* 0x800CFAA0 */
    R[2] = R[2] | 0x2;  /* 0x800CFAA4 */
    sb_(R[3] + 789, R[2]);  /* 0x800CFAA8 */
    R[5] = lw_(R[16]);  /* 0x800CFAAC */
    { R[31] = 0x800CFAB8u; R[6] = R[6] + 30196; psx_next = 0x800AC93Cu; return; }  /* 0x800CFAB0 jal */
    R[4] = lw_(R[16]);  /* 0x800CFAB8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CFAC0 */
    R[3] = R[0] - 897;  /* 0x800CFAC4 */
    R[2] = R[2] & R[3];  /* 0x800CFAC8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CFACC */
    R[3] = lw_(R[16]);  /* 0x800CFAD0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CFAD8 */
    R[2] = R[2] | 0x200;  /* 0x800CFAE0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CFAE4 */
    R[2] = R[0] + 15;  /* 0x800CFAE8 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFAEC */
    R[2] = R[0] + 45;  /* 0x800CFAF0 */
    sh_(R[17] + 592, R[2]);  /* 0x800CFAF4 */
    R[2] = R[0] + 8192;  /* 0x800CFAF8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CFAFC */
    sh_(R[17] + 594, R[2]);  /* 0x800CFB00 */
    R[2] = lw_(R[16]);  /* 0x800CFB04 */
    sw_(R[17] + 608, R[19]);  /* 0x800CFB08 */
    sh_(R[17] + 586, R[20]);  /* 0x800CFB0C */
    { sw_(R[17] + 588, R[2]); goto L_800CFB54; }  /* 0x800CFB10 j */
    R[2] = lb_(R[17] + 785);  /* 0x800CFB18 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_800CFB60; } }  /* 0x800CFB20 */
L_800CFB28:;
    R[16] = R[0] + 8;  /* 0x800CFB28 */
    R[4] = R[17] + R[0];  /* 0x800CFB2C */
    R[5] = 0x800Fu << 16;  /* 0x800CFB30 */
    R[5] = R[5] - 196;  /* 0x800CFB34 */
    R[6] = R[16] + R[0];  /* 0x800CFB38 */
    R[2] = R[0] + 2;  /* 0x800CFB3C */
    { R[31] = 0x800CFB48u; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CFB40 jal */
    R[2] = R[0] + 4;  /* 0x800CFB48 */
    sh_(R[17] + 582, R[16]);  /* 0x800CFB4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFB50 */
L_800CFB54:;
    R[2] = R[0] + 3;  /* 0x800CFB54 */
    { sb_(R[17] + 786, R[2]); goto L_800CFDE0; }  /* 0x800CFB58 j */
L_800CFB60:;
    sb_(R[18] + 3, R[2]);  /* 0x800CFB60 */
    R[2] = lw_(R[17] + 604);  /* 0x800CFB64 */
    R[3] = lw_(R[17] + 600);  /* 0x800CFB68 */
    R[2] = R[2] - R[3];  /* 0x800CFB70 */
    sw_(R[17] + 604, R[2]);  /* 0x800CFB74 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CFB78 */
    sb_(R[18] + 52, R[2]);  /* 0x800CFB7C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFB80 */
    R[4] = R[17] + R[0];  /* 0x800CFB84 */
    { R[31] = 0x800CFB90u; sb_(R[18] + 53, R[2]); psx_next = 0x800CDCACu; return; }  /* 0x800CFB88 jal */
    { R[31] = 0x800CFB98u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CFB90 jal */
    R[4] = R[17] + R[0];  /* 0x800CFB98 */
    R[5] = R[0] + 5;  /* 0x800CFB9C */
    { R[31] = 0x800CFBA8u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800CFBA0 jal */
    { goto L_800CFDE0; }  /* 0x800CFBA8 j */
    R[5] = lw_(R[17] + 588);  /* 0x800CFBB0 */
    { R[31] = 0x800CFBBCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CFBB4 jal */
    R[4] = R[17] + R[0];  /* 0x800CFBBC */
    R[5] = 0x8014u << 16;  /* 0x800CFBC0 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFBC4 */
    R[5] = R[5] + 15160;  /* 0x800CFBC8 */
    R[2] = R[3] << 3;  /* 0x800CFBCC */
    R[2] = R[2] + R[3];  /* 0x800CFBD0 */
    R[2] = R[2] << 7;  /* 0x800CFBD4 */
    { R[31] = 0x800CFBE0u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFBD8 jal */
    R[5] = R[0] + 1;  /* 0x800CFBE0 */
    R[6] = R[5] + R[0];  /* 0x800CFBE4 */
    R[2] = 0x8014u << 16;  /* 0x800CFBE8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CFBEC */
    R[16] = R[2] + 15136;  /* 0x800CFBF0 */
    R[4] = R[4] << 2;  /* 0x800CFBF4 */
    { R[31] = 0x800CFC00u; R[4] = R[4] + R[16]; psx_next = 0x800CCF94u; return; }  /* 0x800CFBF8 jal */
    { uint32_t _c = (R[2] == R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CFD20; } }  /* 0x800CFC00 */
    R[2] = lh_(R[17] + 582);  /* 0x800CFC08 */
    R[2] = R[2] - 1;  /* 0x800CFC10 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFC14 */
    R[2] = R[2] << 16;  /* 0x800CFC18 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[5] = R[0] + 1; if (_c) { goto L_800CFDE0; } }  /* 0x800CFC1C */
    R[4] = lb_(R[17] + 585);  /* 0x800CFC24 */
    R[6] = R[5] + R[0];  /* 0x800CFC28 */
    R[4] = R[4] << 2;  /* 0x800CFC2C */
    { R[31] = 0x800CFC38u; R[4] = R[4] + R[16]; psx_next = 0x800CD028u; return; }  /* 0x800CFC30 jal */
    R[2] = 0x800Fu << 16;  /* 0x800CFC38 */
    R[3] = lw_(R[17] + 588);  /* 0x800CFC3C */
    R[2] = R[2] - 416;  /* 0x800CFC40 */
    sw_(R[17] + 608, R[0]);  /* 0x800CFC44 */
    sh_(R[17] + 14, R[0]);  /* 0x800CFC48 */
    sw_(R[17] + 84, R[2]);  /* 0x800CFC4C */
    R[2] = lb_(R[3] + 2);  /* 0x800CFC50 */
    sh_(R[17] + 596, R[0]);  /* 0x800CFC54 */
    sh_(R[17] + 582, R[19]);  /* 0x800CFC58 */
    sh_(R[17] + 586, R[19]);  /* 0x800CFC5C */
    { sb_(R[17] + 801, R[2]); goto L_800CFDE0; }  /* 0x800CFC60 j */
    R[2] = lw_(R[17] + 588);  /* 0x800CFC68 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 224);  /* 0x800CFC70 */
    R[2] = lh_(R[2] + 224);  /* 0x800CFC74 */
    { uint32_t _c = ((int32_t)R[3] <= 0); R[4] = R[17] + R[0]; if (_c) { goto L_800CFC84; } }  /* 0x800CFC78 */
    sh_(R[17] + 596, R[2]);  /* 0x800CFC80 */
L_800CFC84:;
    R[5] = 0x8014u << 16;  /* 0x800CFC84 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFC88 */
    R[5] = R[5] + 15160;  /* 0x800CFC8C */
    R[2] = R[3] << 3;  /* 0x800CFC90 */
    R[2] = R[2] + R[3];  /* 0x800CFC94 */
    R[2] = R[2] << 7;  /* 0x800CFC98 */
    { R[31] = 0x800CFCA4u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFC9C jal */
    R[3] = lh_(R[17] + 582);  /* 0x800CFCA4 */
    R[3] = R[3] - 1;  /* 0x800CFCAC */
    sh_(R[17] + 582, R[3]);  /* 0x800CFCB0 */
    R[3] = R[3] << 16;  /* 0x800CFCB4 */
    { uint32_t _c = ((int32_t)R[3] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFCB8 */
    { uint32_t _c = ((int32_t)R[2] <= 0); sw_(R[17] + 84, R[0]); if (_c) { goto L_800CFCD4; } }  /* 0x800CFCC0 */
    R[2] = R[0] + 3;  /* 0x800CFCC8 */
    { sh_(R[17] + 586, R[2]); goto L_800CFDE0; }  /* 0x800CFCCC j */
L_800CFCD4:;
    R[2] = R[0] + 4;  /* 0x800CFCD4 */
    { sb_(R[17] + 790, R[2]); goto L_800CFDE0; }  /* 0x800CFCD8 j */
    R[3] = lb_(R[17] + 585);  /* 0x800CFCE0 */
    R[5] = 0x8014u << 16;  /* 0x800CFCE4 */
    R[5] = R[5] + 15160;  /* 0x800CFCE8 */
    R[2] = R[3] << 3;  /* 0x800CFCEC */
    R[2] = R[2] + R[3];  /* 0x800CFCF0 */
    R[2] = R[2] << 7;  /* 0x800CFCF4 */
    { R[31] = 0x800CFD00u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFCF8 jal */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD00 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 596);  /* 0x800CFD08 */
    { uint32_t _c = ((int32_t)R[4] <= 0); R[2] = R[0] + 4; if (_c) { goto L_800CFD24; } }  /* 0x800CFD10 */
    { R[31] = 0x800CFD20u; psx_next = 0x8001D0DCu; return; }  /* 0x800CFD18 jal */
L_800CFD20:;
    R[2] = R[0] + 4;  /* 0x800CFD20 */
L_800CFD24:;
    sh_(R[17] + 582, R[0]);  /* 0x800CFD24 */
    { sb_(R[17] + 790, R[2]); goto L_800CFDE0; }  /* 0x800CFD28 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CFD30 */
    R[2] = R[2] - 1;  /* 0x800CFD38 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFD3C */
    R[2] = R[2] << 16;  /* 0x800CFD40 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CFD74; } }  /* 0x800CFD44 */
    R[3] = 0x8014u << 16;  /* 0x800CFD4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFD50 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CFD54 */
    R[2] = R[2] - 1;  /* 0x800CFD5C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD60 */
    R[2] = 0x8013u << 16;  /* 0x800CFD68 */
    { sh_(R[2] + -29614, R[0]); goto L_800CFDE0; }  /* 0x800CFD6C j */
L_800CFD74:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CFD74 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CFDD8; } }  /* 0x800CFD7C */
    R[2] = lw_(R[17] + 604);  /* 0x800CFD84 */
    R[3] = lw_(R[17] + 600);  /* 0x800CFD88 */
    R[2] = R[2] - R[3];  /* 0x800CFD90 */
    sw_(R[17] + 604, R[2]);  /* 0x800CFD94 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CFD98 */
    sb_(R[18] + 52, R[2]);  /* 0x800CFD9C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDA0 */
    sb_(R[18] + 53, R[2]);  /* 0x800CFDA8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CFDAC */
    { R[31] = 0x800CFDB8u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CFDB0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDB8 */
    R[4] = R[17] + R[0];  /* 0x800CFDBC */
    R[3] = R[2] + R[0];  /* 0x800CFDC0 */
    sh_(R[4] + 60, R[2]);  /* 0x800CFDC4 */
    { R[31] = 0x800CFDD0u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CFDC8 jal */
    { goto L_800CFDE0; }  /* 0x800CFDD0 j */
L_800CFDD8:;
    { R[31] = 0x800CFDE0u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CFDD8 jal */
L_800CFDE0:;
    R[31] = lw_(R[29] + 52);  /* 0x800CFDE0 */
    R[20] = lw_(R[29] + 48);  /* 0x800CFDE4 */
    R[19] = lw_(R[29] + 44);  /* 0x800CFDE8 */
    R[18] = lw_(R[29] + 40);  /* 0x800CFDEC */
    R[17] = lw_(R[29] + 36);  /* 0x800CFDF0 */
    R[16] = lw_(R[29] + 32);  /* 0x800CFDF4 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CFDF8 jr ra */
}

void g0_800CF9EC(void) {
    R[19] = R[2] + R[0];  /* 0x800CF9EC */
    { uint32_t _c = ((int32_t)R[19] <= 0); if (_c) { goto L_800CFB28; } }  /* 0x800CF9F0 */
    { R[31] = 0x800CFA00u; R[4] = R[0] + 57; psx_next = 0x8002DB10u; return; }  /* 0x800CF9F8 jal */
    sb_(R[17] + 584, R[20]);  /* 0x800CFA00 */
    sw_(R[17] + 124, R[0]);  /* 0x800CFA04 */
    sw_(R[17] + 188, R[0]);  /* 0x800CFA08 */
    R[2] = lw_(R[16]);  /* 0x800CFA0C */
    R[2] = lw_(R[2] + 24);  /* 0x800CFA14 */
    sw_(R[29] + 16, R[2]);  /* 0x800CFA1C */
    R[2] = lw_(R[17] + 28);  /* 0x800CFA20 */
    sw_(R[29] + 20, R[2]);  /* 0x800CFA28 */
    R[2] = lw_(R[16]);  /* 0x800CFA2C */
    R[2] = lw_(R[2] + 32);  /* 0x800CFA34 */
    sw_(R[29] + 24, R[2]);  /* 0x800CFA3C */
    R[2] = lw_(R[16]);  /* 0x800CFA40 */
    R[2] = lw_(R[2] + 24);  /* 0x800CFA48 */
    sw_(R[17] + 24, R[2]);  /* 0x800CFA50 */
    R[2] = lw_(R[16]);  /* 0x800CFA54 */
    R[2] = lw_(R[2] + 28);  /* 0x800CFA5C */
    sw_(R[17] + 28, R[2]);  /* 0x800CFA64 */
    R[2] = lw_(R[16]);  /* 0x800CFA68 */
    R[6] = lb_(R[17] + 585);  /* 0x800CFA6C */
    R[2] = lw_(R[2] + 32);  /* 0x800CFA70 */
    R[5] = 0x800Fu << 16;  /* 0x800CFA74 */
    sw_(R[17] + 32, R[2]);  /* 0x800CFA78 */
    R[4] = lw_(R[16]);  /* 0x800CFA7C */
    { R[31] = 0x800CFA88u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CFA80 jal */
    R[4] = R[29] + 16;  /* 0x800CFA88 */
    { R[31] = 0x800CFA94u; R[5] = R[18] + R[0]; psx_next = 0x800CE808u; return; }  /* 0x800CFA8C jal */
    R[3] = lw_(R[16]);  /* 0x800CFA94 */
    R[4] = R[0] + 17;  /* 0x800CFA98 */
    R[2] = lb_(R[3] + 789);  /* 0x800CFA9C */
    R[6] = 0x8011u << 16;  /* 0x800CFAA0 */
    R[2] = R[2] | 0x2;  /* 0x800CFAA4 */
    sb_(R[3] + 789, R[2]);  /* 0x800CFAA8 */
    R[5] = lw_(R[16]);  /* 0x800CFAAC */
    { R[31] = 0x800CFAB8u; R[6] = R[6] + 30196; psx_next = 0x800AC93Cu; return; }  /* 0x800CFAB0 jal */
    R[4] = lw_(R[16]);  /* 0x800CFAB8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CFAC0 */
    R[3] = R[0] - 897;  /* 0x800CFAC4 */
    R[2] = R[2] & R[3];  /* 0x800CFAC8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CFACC */
    R[3] = lw_(R[16]);  /* 0x800CFAD0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CFAD8 */
    R[2] = R[2] | 0x200;  /* 0x800CFAE0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CFAE4 */
    R[2] = R[0] + 15;  /* 0x800CFAE8 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFAEC */
    R[2] = R[0] + 45;  /* 0x800CFAF0 */
    sh_(R[17] + 592, R[2]);  /* 0x800CFAF4 */
    R[2] = R[0] + 8192;  /* 0x800CFAF8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CFAFC */
    sh_(R[17] + 594, R[2]);  /* 0x800CFB00 */
    R[2] = lw_(R[16]);  /* 0x800CFB04 */
    sw_(R[17] + 608, R[19]);  /* 0x800CFB08 */
    sh_(R[17] + 586, R[20]);  /* 0x800CFB0C */
    { sw_(R[17] + 588, R[2]); goto L_800CFB54; }  /* 0x800CFB10 j */
    R[2] = lb_(R[17] + 785);  /* 0x800CFB18 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_800CFB60; } }  /* 0x800CFB20 */
L_800CFB28:;
    R[16] = R[0] + 8;  /* 0x800CFB28 */
    R[4] = R[17] + R[0];  /* 0x800CFB2C */
    R[5] = 0x800Fu << 16;  /* 0x800CFB30 */
    R[5] = R[5] - 196;  /* 0x800CFB34 */
    R[6] = R[16] + R[0];  /* 0x800CFB38 */
    R[2] = R[0] + 2;  /* 0x800CFB3C */
    { R[31] = 0x800CFB48u; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CFB40 jal */
    R[2] = R[0] + 4;  /* 0x800CFB48 */
    sh_(R[17] + 582, R[16]);  /* 0x800CFB4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFB50 */
L_800CFB54:;
    R[2] = R[0] + 3;  /* 0x800CFB54 */
    { sb_(R[17] + 786, R[2]); goto L_800CFDE0; }  /* 0x800CFB58 j */
L_800CFB60:;
    sb_(R[18] + 3, R[2]);  /* 0x800CFB60 */
    R[2] = lw_(R[17] + 604);  /* 0x800CFB64 */
    R[3] = lw_(R[17] + 600);  /* 0x800CFB68 */
    R[2] = R[2] - R[3];  /* 0x800CFB70 */
    sw_(R[17] + 604, R[2]);  /* 0x800CFB74 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CFB78 */
    sb_(R[18] + 52, R[2]);  /* 0x800CFB7C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFB80 */
    R[4] = R[17] + R[0];  /* 0x800CFB84 */
    { R[31] = 0x800CFB90u; sb_(R[18] + 53, R[2]); psx_next = 0x800CDCACu; return; }  /* 0x800CFB88 jal */
    { R[31] = 0x800CFB98u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CFB90 jal */
    R[4] = R[17] + R[0];  /* 0x800CFB98 */
    R[5] = R[0] + 5;  /* 0x800CFB9C */
    { R[31] = 0x800CFBA8u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800CFBA0 jal */
    { goto L_800CFDE0; }  /* 0x800CFBA8 j */
    R[5] = lw_(R[17] + 588);  /* 0x800CFBB0 */
    { R[31] = 0x800CFBBCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CFBB4 jal */
    R[4] = R[17] + R[0];  /* 0x800CFBBC */
    R[5] = 0x8014u << 16;  /* 0x800CFBC0 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFBC4 */
    R[5] = R[5] + 15160;  /* 0x800CFBC8 */
    R[2] = R[3] << 3;  /* 0x800CFBCC */
    R[2] = R[2] + R[3];  /* 0x800CFBD0 */
    R[2] = R[2] << 7;  /* 0x800CFBD4 */
    { R[31] = 0x800CFBE0u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFBD8 jal */
    R[5] = R[0] + 1;  /* 0x800CFBE0 */
    R[6] = R[5] + R[0];  /* 0x800CFBE4 */
    R[2] = 0x8014u << 16;  /* 0x800CFBE8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CFBEC */
    R[16] = R[2] + 15136;  /* 0x800CFBF0 */
    R[4] = R[4] << 2;  /* 0x800CFBF4 */
    { R[31] = 0x800CFC00u; R[4] = R[4] + R[16]; psx_next = 0x800CCF94u; return; }  /* 0x800CFBF8 jal */
    { uint32_t _c = (R[2] == R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CFD20; } }  /* 0x800CFC00 */
    R[2] = lh_(R[17] + 582);  /* 0x800CFC08 */
    R[2] = R[2] - 1;  /* 0x800CFC10 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFC14 */
    R[2] = R[2] << 16;  /* 0x800CFC18 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[5] = R[0] + 1; if (_c) { goto L_800CFDE0; } }  /* 0x800CFC1C */
    R[4] = lb_(R[17] + 585);  /* 0x800CFC24 */
    R[6] = R[5] + R[0];  /* 0x800CFC28 */
    R[4] = R[4] << 2;  /* 0x800CFC2C */
    { R[31] = 0x800CFC38u; R[4] = R[4] + R[16]; psx_next = 0x800CD028u; return; }  /* 0x800CFC30 jal */
    R[2] = 0x800Fu << 16;  /* 0x800CFC38 */
    R[3] = lw_(R[17] + 588);  /* 0x800CFC3C */
    R[2] = R[2] - 416;  /* 0x800CFC40 */
    sw_(R[17] + 608, R[0]);  /* 0x800CFC44 */
    sh_(R[17] + 14, R[0]);  /* 0x800CFC48 */
    sw_(R[17] + 84, R[2]);  /* 0x800CFC4C */
    R[2] = lb_(R[3] + 2);  /* 0x800CFC50 */
    sh_(R[17] + 596, R[0]);  /* 0x800CFC54 */
    sh_(R[17] + 582, R[19]);  /* 0x800CFC58 */
    sh_(R[17] + 586, R[19]);  /* 0x800CFC5C */
    { sb_(R[17] + 801, R[2]); goto L_800CFDE0; }  /* 0x800CFC60 j */
    R[2] = lw_(R[17] + 588);  /* 0x800CFC68 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 224);  /* 0x800CFC70 */
    R[2] = lh_(R[2] + 224);  /* 0x800CFC74 */
    { uint32_t _c = ((int32_t)R[3] <= 0); R[4] = R[17] + R[0]; if (_c) { goto L_800CFC84; } }  /* 0x800CFC78 */
    sh_(R[17] + 596, R[2]);  /* 0x800CFC80 */
L_800CFC84:;
    R[5] = 0x8014u << 16;  /* 0x800CFC84 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFC88 */
    R[5] = R[5] + 15160;  /* 0x800CFC8C */
    R[2] = R[3] << 3;  /* 0x800CFC90 */
    R[2] = R[2] + R[3];  /* 0x800CFC94 */
    R[2] = R[2] << 7;  /* 0x800CFC98 */
    { R[31] = 0x800CFCA4u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFC9C jal */
    R[3] = lh_(R[17] + 582);  /* 0x800CFCA4 */
    R[3] = R[3] - 1;  /* 0x800CFCAC */
    sh_(R[17] + 582, R[3]);  /* 0x800CFCB0 */
    R[3] = R[3] << 16;  /* 0x800CFCB4 */
    { uint32_t _c = ((int32_t)R[3] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFCB8 */
    { uint32_t _c = ((int32_t)R[2] <= 0); sw_(R[17] + 84, R[0]); if (_c) { goto L_800CFCD4; } }  /* 0x800CFCC0 */
    R[2] = R[0] + 3;  /* 0x800CFCC8 */
    { sh_(R[17] + 586, R[2]); goto L_800CFDE0; }  /* 0x800CFCCC j */
L_800CFCD4:;
    R[2] = R[0] + 4;  /* 0x800CFCD4 */
    { sb_(R[17] + 790, R[2]); goto L_800CFDE0; }  /* 0x800CFCD8 j */
    R[3] = lb_(R[17] + 585);  /* 0x800CFCE0 */
    R[5] = 0x8014u << 16;  /* 0x800CFCE4 */
    R[5] = R[5] + 15160;  /* 0x800CFCE8 */
    R[2] = R[3] << 3;  /* 0x800CFCEC */
    R[2] = R[2] + R[3];  /* 0x800CFCF0 */
    R[2] = R[2] << 7;  /* 0x800CFCF4 */
    { R[31] = 0x800CFD00u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFCF8 jal */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD00 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 596);  /* 0x800CFD08 */
    { uint32_t _c = ((int32_t)R[4] <= 0); R[2] = R[0] + 4; if (_c) { goto L_800CFD24; } }  /* 0x800CFD10 */
    { R[31] = 0x800CFD20u; psx_next = 0x8001D0DCu; return; }  /* 0x800CFD18 jal */
L_800CFD20:;
    R[2] = R[0] + 4;  /* 0x800CFD20 */
L_800CFD24:;
    sh_(R[17] + 582, R[0]);  /* 0x800CFD24 */
    { sb_(R[17] + 790, R[2]); goto L_800CFDE0; }  /* 0x800CFD28 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CFD30 */
    R[2] = R[2] - 1;  /* 0x800CFD38 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFD3C */
    R[2] = R[2] << 16;  /* 0x800CFD40 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CFD74; } }  /* 0x800CFD44 */
    R[3] = 0x8014u << 16;  /* 0x800CFD4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFD50 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CFD54 */
    R[2] = R[2] - 1;  /* 0x800CFD5C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD60 */
    R[2] = 0x8013u << 16;  /* 0x800CFD68 */
    { sh_(R[2] + -29614, R[0]); goto L_800CFDE0; }  /* 0x800CFD6C j */
L_800CFD74:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CFD74 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CFDD8; } }  /* 0x800CFD7C */
    R[2] = lw_(R[17] + 604);  /* 0x800CFD84 */
    R[3] = lw_(R[17] + 600);  /* 0x800CFD88 */
    R[2] = R[2] - R[3];  /* 0x800CFD90 */
    sw_(R[17] + 604, R[2]);  /* 0x800CFD94 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CFD98 */
    sb_(R[18] + 52, R[2]);  /* 0x800CFD9C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDA0 */
    sb_(R[18] + 53, R[2]);  /* 0x800CFDA8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CFDAC */
    { R[31] = 0x800CFDB8u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CFDB0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDB8 */
    R[4] = R[17] + R[0];  /* 0x800CFDBC */
    R[3] = R[2] + R[0];  /* 0x800CFDC0 */
    sh_(R[4] + 60, R[2]);  /* 0x800CFDC4 */
    { R[31] = 0x800CFDD0u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CFDC8 jal */
    { goto L_800CFDE0; }  /* 0x800CFDD0 j */
L_800CFDD8:;
    { R[31] = 0x800CFDE0u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CFDD8 jal */
L_800CFDE0:;
    R[31] = lw_(R[29] + 52);  /* 0x800CFDE0 */
    R[20] = lw_(R[29] + 48);  /* 0x800CFDE4 */
    R[19] = lw_(R[29] + 44);  /* 0x800CFDE8 */
    R[18] = lw_(R[29] + 40);  /* 0x800CFDEC */
    R[17] = lw_(R[29] + 36);  /* 0x800CFDF0 */
    R[16] = lw_(R[29] + 32);  /* 0x800CFDF4 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CFDF8 jr ra */
}

void g0_800CFA00(void) {
    sb_(R[17] + 584, R[20]);  /* 0x800CFA00 */
    sw_(R[17] + 124, R[0]);  /* 0x800CFA04 */
    sw_(R[17] + 188, R[0]);  /* 0x800CFA08 */
    R[2] = lw_(R[16]);  /* 0x800CFA0C */
    R[2] = lw_(R[2] + 24);  /* 0x800CFA14 */
    sw_(R[29] + 16, R[2]);  /* 0x800CFA1C */
    R[2] = lw_(R[17] + 28);  /* 0x800CFA20 */
    sw_(R[29] + 20, R[2]);  /* 0x800CFA28 */
    R[2] = lw_(R[16]);  /* 0x800CFA2C */
    R[2] = lw_(R[2] + 32);  /* 0x800CFA34 */
    sw_(R[29] + 24, R[2]);  /* 0x800CFA3C */
    R[2] = lw_(R[16]);  /* 0x800CFA40 */
    R[2] = lw_(R[2] + 24);  /* 0x800CFA48 */
    sw_(R[17] + 24, R[2]);  /* 0x800CFA50 */
    R[2] = lw_(R[16]);  /* 0x800CFA54 */
    R[2] = lw_(R[2] + 28);  /* 0x800CFA5C */
    sw_(R[17] + 28, R[2]);  /* 0x800CFA64 */
    R[2] = lw_(R[16]);  /* 0x800CFA68 */
    R[6] = lb_(R[17] + 585);  /* 0x800CFA6C */
    R[2] = lw_(R[2] + 32);  /* 0x800CFA70 */
    R[5] = 0x800Fu << 16;  /* 0x800CFA74 */
    sw_(R[17] + 32, R[2]);  /* 0x800CFA78 */
    R[4] = lw_(R[16]);  /* 0x800CFA7C */
    { R[31] = 0x800CFA88u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CFA80 jal */
    R[4] = R[29] + 16;  /* 0x800CFA88 */
    { R[31] = 0x800CFA94u; R[5] = R[18] + R[0]; psx_next = 0x800CE808u; return; }  /* 0x800CFA8C jal */
    R[3] = lw_(R[16]);  /* 0x800CFA94 */
    R[4] = R[0] + 17;  /* 0x800CFA98 */
    R[2] = lb_(R[3] + 789);  /* 0x800CFA9C */
    R[6] = 0x8011u << 16;  /* 0x800CFAA0 */
    R[2] = R[2] | 0x2;  /* 0x800CFAA4 */
    sb_(R[3] + 789, R[2]);  /* 0x800CFAA8 */
    R[5] = lw_(R[16]);  /* 0x800CFAAC */
    { R[31] = 0x800CFAB8u; R[6] = R[6] + 30196; psx_next = 0x800AC93Cu; return; }  /* 0x800CFAB0 jal */
    R[4] = lw_(R[16]);  /* 0x800CFAB8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CFAC0 */
    R[3] = R[0] - 897;  /* 0x800CFAC4 */
    R[2] = R[2] & R[3];  /* 0x800CFAC8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CFACC */
    R[3] = lw_(R[16]);  /* 0x800CFAD0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CFAD8 */
    R[2] = R[2] | 0x200;  /* 0x800CFAE0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CFAE4 */
    R[2] = R[0] + 15;  /* 0x800CFAE8 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFAEC */
    R[2] = R[0] + 45;  /* 0x800CFAF0 */
    sh_(R[17] + 592, R[2]);  /* 0x800CFAF4 */
    R[2] = R[0] + 8192;  /* 0x800CFAF8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CFAFC */
    sh_(R[17] + 594, R[2]);  /* 0x800CFB00 */
    R[2] = lw_(R[16]);  /* 0x800CFB04 */
    sw_(R[17] + 608, R[19]);  /* 0x800CFB08 */
    sh_(R[17] + 586, R[20]);  /* 0x800CFB0C */
    { sw_(R[17] + 588, R[2]); goto L_800CFB54; }  /* 0x800CFB10 j */
    R[2] = lb_(R[17] + 785);  /* 0x800CFB18 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_800CFB60; } }  /* 0x800CFB20 */
    R[16] = R[0] + 8;  /* 0x800CFB28 */
    R[4] = R[17] + R[0];  /* 0x800CFB2C */
    R[5] = 0x800Fu << 16;  /* 0x800CFB30 */
    R[5] = R[5] - 196;  /* 0x800CFB34 */
    R[6] = R[16] + R[0];  /* 0x800CFB38 */
    R[2] = R[0] + 2;  /* 0x800CFB3C */
    { R[31] = 0x800CFB48u; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CFB40 jal */
    R[2] = R[0] + 4;  /* 0x800CFB48 */
    sh_(R[17] + 582, R[16]);  /* 0x800CFB4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFB50 */
L_800CFB54:;
    R[2] = R[0] + 3;  /* 0x800CFB54 */
    { sb_(R[17] + 786, R[2]); goto L_800CFDE0; }  /* 0x800CFB58 j */
L_800CFB60:;
    sb_(R[18] + 3, R[2]);  /* 0x800CFB60 */
    R[2] = lw_(R[17] + 604);  /* 0x800CFB64 */
    R[3] = lw_(R[17] + 600);  /* 0x800CFB68 */
    R[2] = R[2] - R[3];  /* 0x800CFB70 */
    sw_(R[17] + 604, R[2]);  /* 0x800CFB74 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CFB78 */
    sb_(R[18] + 52, R[2]);  /* 0x800CFB7C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFB80 */
    R[4] = R[17] + R[0];  /* 0x800CFB84 */
    { R[31] = 0x800CFB90u; sb_(R[18] + 53, R[2]); psx_next = 0x800CDCACu; return; }  /* 0x800CFB88 jal */
    { R[31] = 0x800CFB98u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CFB90 jal */
    R[4] = R[17] + R[0];  /* 0x800CFB98 */
    R[5] = R[0] + 5;  /* 0x800CFB9C */
    { R[31] = 0x800CFBA8u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800CFBA0 jal */
    { goto L_800CFDE0; }  /* 0x800CFBA8 j */
    R[5] = lw_(R[17] + 588);  /* 0x800CFBB0 */
    { R[31] = 0x800CFBBCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CFBB4 jal */
    R[4] = R[17] + R[0];  /* 0x800CFBBC */
    R[5] = 0x8014u << 16;  /* 0x800CFBC0 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFBC4 */
    R[5] = R[5] + 15160;  /* 0x800CFBC8 */
    R[2] = R[3] << 3;  /* 0x800CFBCC */
    R[2] = R[2] + R[3];  /* 0x800CFBD0 */
    R[2] = R[2] << 7;  /* 0x800CFBD4 */
    { R[31] = 0x800CFBE0u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFBD8 jal */
    R[5] = R[0] + 1;  /* 0x800CFBE0 */
    R[6] = R[5] + R[0];  /* 0x800CFBE4 */
    R[2] = 0x8014u << 16;  /* 0x800CFBE8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CFBEC */
    R[16] = R[2] + 15136;  /* 0x800CFBF0 */
    R[4] = R[4] << 2;  /* 0x800CFBF4 */
    { R[31] = 0x800CFC00u; R[4] = R[4] + R[16]; psx_next = 0x800CCF94u; return; }  /* 0x800CFBF8 jal */
    { uint32_t _c = (R[2] == R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CFD20; } }  /* 0x800CFC00 */
    R[2] = lh_(R[17] + 582);  /* 0x800CFC08 */
    R[2] = R[2] - 1;  /* 0x800CFC10 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFC14 */
    R[2] = R[2] << 16;  /* 0x800CFC18 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[5] = R[0] + 1; if (_c) { goto L_800CFDE0; } }  /* 0x800CFC1C */
    R[4] = lb_(R[17] + 585);  /* 0x800CFC24 */
    R[6] = R[5] + R[0];  /* 0x800CFC28 */
    R[4] = R[4] << 2;  /* 0x800CFC2C */
    { R[31] = 0x800CFC38u; R[4] = R[4] + R[16]; psx_next = 0x800CD028u; return; }  /* 0x800CFC30 jal */
    R[2] = 0x800Fu << 16;  /* 0x800CFC38 */
    R[3] = lw_(R[17] + 588);  /* 0x800CFC3C */
    R[2] = R[2] - 416;  /* 0x800CFC40 */
    sw_(R[17] + 608, R[0]);  /* 0x800CFC44 */
    sh_(R[17] + 14, R[0]);  /* 0x800CFC48 */
    sw_(R[17] + 84, R[2]);  /* 0x800CFC4C */
    R[2] = lb_(R[3] + 2);  /* 0x800CFC50 */
    sh_(R[17] + 596, R[0]);  /* 0x800CFC54 */
    sh_(R[17] + 582, R[19]);  /* 0x800CFC58 */
    sh_(R[17] + 586, R[19]);  /* 0x800CFC5C */
    { sb_(R[17] + 801, R[2]); goto L_800CFDE0; }  /* 0x800CFC60 j */
    R[2] = lw_(R[17] + 588);  /* 0x800CFC68 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 224);  /* 0x800CFC70 */
    R[2] = lh_(R[2] + 224);  /* 0x800CFC74 */
    { uint32_t _c = ((int32_t)R[3] <= 0); R[4] = R[17] + R[0]; if (_c) { goto L_800CFC84; } }  /* 0x800CFC78 */
    sh_(R[17] + 596, R[2]);  /* 0x800CFC80 */
L_800CFC84:;
    R[5] = 0x8014u << 16;  /* 0x800CFC84 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFC88 */
    R[5] = R[5] + 15160;  /* 0x800CFC8C */
    R[2] = R[3] << 3;  /* 0x800CFC90 */
    R[2] = R[2] + R[3];  /* 0x800CFC94 */
    R[2] = R[2] << 7;  /* 0x800CFC98 */
    { R[31] = 0x800CFCA4u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFC9C jal */
    R[3] = lh_(R[17] + 582);  /* 0x800CFCA4 */
    R[3] = R[3] - 1;  /* 0x800CFCAC */
    sh_(R[17] + 582, R[3]);  /* 0x800CFCB0 */
    R[3] = R[3] << 16;  /* 0x800CFCB4 */
    { uint32_t _c = ((int32_t)R[3] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFCB8 */
    { uint32_t _c = ((int32_t)R[2] <= 0); sw_(R[17] + 84, R[0]); if (_c) { goto L_800CFCD4; } }  /* 0x800CFCC0 */
    R[2] = R[0] + 3;  /* 0x800CFCC8 */
    { sh_(R[17] + 586, R[2]); goto L_800CFDE0; }  /* 0x800CFCCC j */
L_800CFCD4:;
    R[2] = R[0] + 4;  /* 0x800CFCD4 */
    { sb_(R[17] + 790, R[2]); goto L_800CFDE0; }  /* 0x800CFCD8 j */
    R[3] = lb_(R[17] + 585);  /* 0x800CFCE0 */
    R[5] = 0x8014u << 16;  /* 0x800CFCE4 */
    R[5] = R[5] + 15160;  /* 0x800CFCE8 */
    R[2] = R[3] << 3;  /* 0x800CFCEC */
    R[2] = R[2] + R[3];  /* 0x800CFCF0 */
    R[2] = R[2] << 7;  /* 0x800CFCF4 */
    { R[31] = 0x800CFD00u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFCF8 jal */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD00 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 596);  /* 0x800CFD08 */
    { uint32_t _c = ((int32_t)R[4] <= 0); R[2] = R[0] + 4; if (_c) { goto L_800CFD24; } }  /* 0x800CFD10 */
    { R[31] = 0x800CFD20u; psx_next = 0x8001D0DCu; return; }  /* 0x800CFD18 jal */
L_800CFD20:;
    R[2] = R[0] + 4;  /* 0x800CFD20 */
L_800CFD24:;
    sh_(R[17] + 582, R[0]);  /* 0x800CFD24 */
    { sb_(R[17] + 790, R[2]); goto L_800CFDE0; }  /* 0x800CFD28 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CFD30 */
    R[2] = R[2] - 1;  /* 0x800CFD38 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFD3C */
    R[2] = R[2] << 16;  /* 0x800CFD40 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CFD74; } }  /* 0x800CFD44 */
    R[3] = 0x8014u << 16;  /* 0x800CFD4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFD50 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CFD54 */
    R[2] = R[2] - 1;  /* 0x800CFD5C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD60 */
    R[2] = 0x8013u << 16;  /* 0x800CFD68 */
    { sh_(R[2] + -29614, R[0]); goto L_800CFDE0; }  /* 0x800CFD6C j */
L_800CFD74:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CFD74 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CFDD8; } }  /* 0x800CFD7C */
    R[2] = lw_(R[17] + 604);  /* 0x800CFD84 */
    R[3] = lw_(R[17] + 600);  /* 0x800CFD88 */
    R[2] = R[2] - R[3];  /* 0x800CFD90 */
    sw_(R[17] + 604, R[2]);  /* 0x800CFD94 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CFD98 */
    sb_(R[18] + 52, R[2]);  /* 0x800CFD9C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDA0 */
    sb_(R[18] + 53, R[2]);  /* 0x800CFDA8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CFDAC */
    { R[31] = 0x800CFDB8u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CFDB0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDB8 */
    R[4] = R[17] + R[0];  /* 0x800CFDBC */
    R[3] = R[2] + R[0];  /* 0x800CFDC0 */
    sh_(R[4] + 60, R[2]);  /* 0x800CFDC4 */
    { R[31] = 0x800CFDD0u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CFDC8 jal */
    { goto L_800CFDE0; }  /* 0x800CFDD0 j */
L_800CFDD8:;
    { R[31] = 0x800CFDE0u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CFDD8 jal */
L_800CFDE0:;
    R[31] = lw_(R[29] + 52);  /* 0x800CFDE0 */
    R[20] = lw_(R[29] + 48);  /* 0x800CFDE4 */
    R[19] = lw_(R[29] + 44);  /* 0x800CFDE8 */
    R[18] = lw_(R[29] + 40);  /* 0x800CFDEC */
    R[17] = lw_(R[29] + 36);  /* 0x800CFDF0 */
    R[16] = lw_(R[29] + 32);  /* 0x800CFDF4 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CFDF8 jr ra */
}

void g0_800CFA88(void) {
    R[4] = R[29] + 16;  /* 0x800CFA88 */
    { R[31] = 0x800CFA94u; R[5] = R[18] + R[0]; psx_next = 0x800CE808u; return; }  /* 0x800CFA8C jal */
    R[3] = lw_(R[16]);  /* 0x800CFA94 */
    R[4] = R[0] + 17;  /* 0x800CFA98 */
    R[2] = lb_(R[3] + 789);  /* 0x800CFA9C */
    R[6] = 0x8011u << 16;  /* 0x800CFAA0 */
    R[2] = R[2] | 0x2;  /* 0x800CFAA4 */
    sb_(R[3] + 789, R[2]);  /* 0x800CFAA8 */
    R[5] = lw_(R[16]);  /* 0x800CFAAC */
    { R[31] = 0x800CFAB8u; R[6] = R[6] + 30196; psx_next = 0x800AC93Cu; return; }  /* 0x800CFAB0 jal */
    R[4] = lw_(R[16]);  /* 0x800CFAB8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CFAC0 */
    R[3] = R[0] - 897;  /* 0x800CFAC4 */
    R[2] = R[2] & R[3];  /* 0x800CFAC8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CFACC */
    R[3] = lw_(R[16]);  /* 0x800CFAD0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CFAD8 */
    R[2] = R[2] | 0x200;  /* 0x800CFAE0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CFAE4 */
    R[2] = R[0] + 15;  /* 0x800CFAE8 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFAEC */
    R[2] = R[0] + 45;  /* 0x800CFAF0 */
    sh_(R[17] + 592, R[2]);  /* 0x800CFAF4 */
    R[2] = R[0] + 8192;  /* 0x800CFAF8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CFAFC */
    sh_(R[17] + 594, R[2]);  /* 0x800CFB00 */
    R[2] = lw_(R[16]);  /* 0x800CFB04 */
    sw_(R[17] + 608, R[19]);  /* 0x800CFB08 */
    sh_(R[17] + 586, R[20]);  /* 0x800CFB0C */
    { sw_(R[17] + 588, R[2]); goto L_800CFB54; }  /* 0x800CFB10 j */
    R[2] = lb_(R[17] + 785);  /* 0x800CFB18 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_800CFB60; } }  /* 0x800CFB20 */
    R[16] = R[0] + 8;  /* 0x800CFB28 */
    R[4] = R[17] + R[0];  /* 0x800CFB2C */
    R[5] = 0x800Fu << 16;  /* 0x800CFB30 */
    R[5] = R[5] - 196;  /* 0x800CFB34 */
    R[6] = R[16] + R[0];  /* 0x800CFB38 */
    R[2] = R[0] + 2;  /* 0x800CFB3C */
    { R[31] = 0x800CFB48u; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CFB40 jal */
    R[2] = R[0] + 4;  /* 0x800CFB48 */
    sh_(R[17] + 582, R[16]);  /* 0x800CFB4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFB50 */
L_800CFB54:;
    R[2] = R[0] + 3;  /* 0x800CFB54 */
    { sb_(R[17] + 786, R[2]); goto L_800CFDE0; }  /* 0x800CFB58 j */
L_800CFB60:;
    sb_(R[18] + 3, R[2]);  /* 0x800CFB60 */
    R[2] = lw_(R[17] + 604);  /* 0x800CFB64 */
    R[3] = lw_(R[17] + 600);  /* 0x800CFB68 */
    R[2] = R[2] - R[3];  /* 0x800CFB70 */
    sw_(R[17] + 604, R[2]);  /* 0x800CFB74 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CFB78 */
    sb_(R[18] + 52, R[2]);  /* 0x800CFB7C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFB80 */
    R[4] = R[17] + R[0];  /* 0x800CFB84 */
    { R[31] = 0x800CFB90u; sb_(R[18] + 53, R[2]); psx_next = 0x800CDCACu; return; }  /* 0x800CFB88 jal */
    { R[31] = 0x800CFB98u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CFB90 jal */
    R[4] = R[17] + R[0];  /* 0x800CFB98 */
    R[5] = R[0] + 5;  /* 0x800CFB9C */
    { R[31] = 0x800CFBA8u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800CFBA0 jal */
    { goto L_800CFDE0; }  /* 0x800CFBA8 j */
    R[5] = lw_(R[17] + 588);  /* 0x800CFBB0 */
    { R[31] = 0x800CFBBCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CFBB4 jal */
    R[4] = R[17] + R[0];  /* 0x800CFBBC */
    R[5] = 0x8014u << 16;  /* 0x800CFBC0 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFBC4 */
    R[5] = R[5] + 15160;  /* 0x800CFBC8 */
    R[2] = R[3] << 3;  /* 0x800CFBCC */
    R[2] = R[2] + R[3];  /* 0x800CFBD0 */
    R[2] = R[2] << 7;  /* 0x800CFBD4 */
    { R[31] = 0x800CFBE0u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFBD8 jal */
    R[5] = R[0] + 1;  /* 0x800CFBE0 */
    R[6] = R[5] + R[0];  /* 0x800CFBE4 */
    R[2] = 0x8014u << 16;  /* 0x800CFBE8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CFBEC */
    R[16] = R[2] + 15136;  /* 0x800CFBF0 */
    R[4] = R[4] << 2;  /* 0x800CFBF4 */
    { R[31] = 0x800CFC00u; R[4] = R[4] + R[16]; psx_next = 0x800CCF94u; return; }  /* 0x800CFBF8 jal */
    { uint32_t _c = (R[2] == R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CFD20; } }  /* 0x800CFC00 */
    R[2] = lh_(R[17] + 582);  /* 0x800CFC08 */
    R[2] = R[2] - 1;  /* 0x800CFC10 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFC14 */
    R[2] = R[2] << 16;  /* 0x800CFC18 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[5] = R[0] + 1; if (_c) { goto L_800CFDE0; } }  /* 0x800CFC1C */
    R[4] = lb_(R[17] + 585);  /* 0x800CFC24 */
    R[6] = R[5] + R[0];  /* 0x800CFC28 */
    R[4] = R[4] << 2;  /* 0x800CFC2C */
    { R[31] = 0x800CFC38u; R[4] = R[4] + R[16]; psx_next = 0x800CD028u; return; }  /* 0x800CFC30 jal */
    R[2] = 0x800Fu << 16;  /* 0x800CFC38 */
    R[3] = lw_(R[17] + 588);  /* 0x800CFC3C */
    R[2] = R[2] - 416;  /* 0x800CFC40 */
    sw_(R[17] + 608, R[0]);  /* 0x800CFC44 */
    sh_(R[17] + 14, R[0]);  /* 0x800CFC48 */
    sw_(R[17] + 84, R[2]);  /* 0x800CFC4C */
    R[2] = lb_(R[3] + 2);  /* 0x800CFC50 */
    sh_(R[17] + 596, R[0]);  /* 0x800CFC54 */
    sh_(R[17] + 582, R[19]);  /* 0x800CFC58 */
    sh_(R[17] + 586, R[19]);  /* 0x800CFC5C */
    { sb_(R[17] + 801, R[2]); goto L_800CFDE0; }  /* 0x800CFC60 j */
    R[2] = lw_(R[17] + 588);  /* 0x800CFC68 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 224);  /* 0x800CFC70 */
    R[2] = lh_(R[2] + 224);  /* 0x800CFC74 */
    { uint32_t _c = ((int32_t)R[3] <= 0); R[4] = R[17] + R[0]; if (_c) { goto L_800CFC84; } }  /* 0x800CFC78 */
    sh_(R[17] + 596, R[2]);  /* 0x800CFC80 */
L_800CFC84:;
    R[5] = 0x8014u << 16;  /* 0x800CFC84 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFC88 */
    R[5] = R[5] + 15160;  /* 0x800CFC8C */
    R[2] = R[3] << 3;  /* 0x800CFC90 */
    R[2] = R[2] + R[3];  /* 0x800CFC94 */
    R[2] = R[2] << 7;  /* 0x800CFC98 */
    { R[31] = 0x800CFCA4u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFC9C jal */
    R[3] = lh_(R[17] + 582);  /* 0x800CFCA4 */
    R[3] = R[3] - 1;  /* 0x800CFCAC */
    sh_(R[17] + 582, R[3]);  /* 0x800CFCB0 */
    R[3] = R[3] << 16;  /* 0x800CFCB4 */
    { uint32_t _c = ((int32_t)R[3] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFCB8 */
    { uint32_t _c = ((int32_t)R[2] <= 0); sw_(R[17] + 84, R[0]); if (_c) { goto L_800CFCD4; } }  /* 0x800CFCC0 */
    R[2] = R[0] + 3;  /* 0x800CFCC8 */
    { sh_(R[17] + 586, R[2]); goto L_800CFDE0; }  /* 0x800CFCCC j */
L_800CFCD4:;
    R[2] = R[0] + 4;  /* 0x800CFCD4 */
    { sb_(R[17] + 790, R[2]); goto L_800CFDE0; }  /* 0x800CFCD8 j */
    R[3] = lb_(R[17] + 585);  /* 0x800CFCE0 */
    R[5] = 0x8014u << 16;  /* 0x800CFCE4 */
    R[5] = R[5] + 15160;  /* 0x800CFCE8 */
    R[2] = R[3] << 3;  /* 0x800CFCEC */
    R[2] = R[2] + R[3];  /* 0x800CFCF0 */
    R[2] = R[2] << 7;  /* 0x800CFCF4 */
    { R[31] = 0x800CFD00u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFCF8 jal */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD00 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 596);  /* 0x800CFD08 */
    { uint32_t _c = ((int32_t)R[4] <= 0); R[2] = R[0] + 4; if (_c) { goto L_800CFD24; } }  /* 0x800CFD10 */
    { R[31] = 0x800CFD20u; psx_next = 0x8001D0DCu; return; }  /* 0x800CFD18 jal */
L_800CFD20:;
    R[2] = R[0] + 4;  /* 0x800CFD20 */
L_800CFD24:;
    sh_(R[17] + 582, R[0]);  /* 0x800CFD24 */
    { sb_(R[17] + 790, R[2]); goto L_800CFDE0; }  /* 0x800CFD28 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CFD30 */
    R[2] = R[2] - 1;  /* 0x800CFD38 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFD3C */
    R[2] = R[2] << 16;  /* 0x800CFD40 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CFD74; } }  /* 0x800CFD44 */
    R[3] = 0x8014u << 16;  /* 0x800CFD4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFD50 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CFD54 */
    R[2] = R[2] - 1;  /* 0x800CFD5C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD60 */
    R[2] = 0x8013u << 16;  /* 0x800CFD68 */
    { sh_(R[2] + -29614, R[0]); goto L_800CFDE0; }  /* 0x800CFD6C j */
L_800CFD74:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CFD74 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CFDD8; } }  /* 0x800CFD7C */
    R[2] = lw_(R[17] + 604);  /* 0x800CFD84 */
    R[3] = lw_(R[17] + 600);  /* 0x800CFD88 */
    R[2] = R[2] - R[3];  /* 0x800CFD90 */
    sw_(R[17] + 604, R[2]);  /* 0x800CFD94 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CFD98 */
    sb_(R[18] + 52, R[2]);  /* 0x800CFD9C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDA0 */
    sb_(R[18] + 53, R[2]);  /* 0x800CFDA8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CFDAC */
    { R[31] = 0x800CFDB8u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CFDB0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDB8 */
    R[4] = R[17] + R[0];  /* 0x800CFDBC */
    R[3] = R[2] + R[0];  /* 0x800CFDC0 */
    sh_(R[4] + 60, R[2]);  /* 0x800CFDC4 */
    { R[31] = 0x800CFDD0u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CFDC8 jal */
    { goto L_800CFDE0; }  /* 0x800CFDD0 j */
L_800CFDD8:;
    { R[31] = 0x800CFDE0u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CFDD8 jal */
L_800CFDE0:;
    R[31] = lw_(R[29] + 52);  /* 0x800CFDE0 */
    R[20] = lw_(R[29] + 48);  /* 0x800CFDE4 */
    R[19] = lw_(R[29] + 44);  /* 0x800CFDE8 */
    R[18] = lw_(R[29] + 40);  /* 0x800CFDEC */
    R[17] = lw_(R[29] + 36);  /* 0x800CFDF0 */
    R[16] = lw_(R[29] + 32);  /* 0x800CFDF4 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CFDF8 jr ra */
}

void g0_800CFA94(void) {
    R[3] = lw_(R[16]);  /* 0x800CFA94 */
    R[4] = R[0] + 17;  /* 0x800CFA98 */
    R[2] = lb_(R[3] + 789);  /* 0x800CFA9C */
    R[6] = 0x8011u << 16;  /* 0x800CFAA0 */
    R[2] = R[2] | 0x2;  /* 0x800CFAA4 */
    sb_(R[3] + 789, R[2]);  /* 0x800CFAA8 */
    R[5] = lw_(R[16]);  /* 0x800CFAAC */
    { R[31] = 0x800CFAB8u; R[6] = R[6] + 30196; psx_next = 0x800AC93Cu; return; }  /* 0x800CFAB0 jal */
    R[4] = lw_(R[16]);  /* 0x800CFAB8 */
    R[2] = lw_(R[4] + 16);  /* 0x800CFAC0 */
    R[3] = R[0] - 897;  /* 0x800CFAC4 */
    R[2] = R[2] & R[3];  /* 0x800CFAC8 */
    sw_(R[4] + 16, R[2]);  /* 0x800CFACC */
    R[3] = lw_(R[16]);  /* 0x800CFAD0 */
    R[2] = lw_(R[3] + 16);  /* 0x800CFAD8 */
    R[2] = R[2] | 0x200;  /* 0x800CFAE0 */
    sw_(R[3] + 16, R[2]);  /* 0x800CFAE4 */
    R[2] = R[0] + 15;  /* 0x800CFAE8 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFAEC */
    R[2] = R[0] + 45;  /* 0x800CFAF0 */
    sh_(R[17] + 592, R[2]);  /* 0x800CFAF4 */
    R[2] = R[0] + 8192;  /* 0x800CFAF8 */
    sw_(R[17] + 84, R[0]);  /* 0x800CFAFC */
    sh_(R[17] + 594, R[2]);  /* 0x800CFB00 */
    R[2] = lw_(R[16]);  /* 0x800CFB04 */
    sw_(R[17] + 608, R[19]);  /* 0x800CFB08 */
    sh_(R[17] + 586, R[20]);  /* 0x800CFB0C */
    { sw_(R[17] + 588, R[2]); goto L_800CFB54; }  /* 0x800CFB10 j */
    R[2] = lb_(R[17] + 785);  /* 0x800CFB18 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_800CFB60; } }  /* 0x800CFB20 */
    R[16] = R[0] + 8;  /* 0x800CFB28 */
    R[4] = R[17] + R[0];  /* 0x800CFB2C */
    R[5] = 0x800Fu << 16;  /* 0x800CFB30 */
    R[5] = R[5] - 196;  /* 0x800CFB34 */
    R[6] = R[16] + R[0];  /* 0x800CFB38 */
    R[2] = R[0] + 2;  /* 0x800CFB3C */
    { R[31] = 0x800CFB48u; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800CFB40 jal */
    R[2] = R[0] + 4;  /* 0x800CFB48 */
    sh_(R[17] + 582, R[16]);  /* 0x800CFB4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFB50 */
L_800CFB54:;
    R[2] = R[0] + 3;  /* 0x800CFB54 */
    { sb_(R[17] + 786, R[2]); goto L_800CFDE0; }  /* 0x800CFB58 j */
L_800CFB60:;
    sb_(R[18] + 3, R[2]);  /* 0x800CFB60 */
    R[2] = lw_(R[17] + 604);  /* 0x800CFB64 */
    R[3] = lw_(R[17] + 600);  /* 0x800CFB68 */
    R[2] = R[2] - R[3];  /* 0x800CFB70 */
    sw_(R[17] + 604, R[2]);  /* 0x800CFB74 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CFB78 */
    sb_(R[18] + 52, R[2]);  /* 0x800CFB7C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFB80 */
    R[4] = R[17] + R[0];  /* 0x800CFB84 */
    { R[31] = 0x800CFB90u; sb_(R[18] + 53, R[2]); psx_next = 0x800CDCACu; return; }  /* 0x800CFB88 jal */
    { R[31] = 0x800CFB98u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800CFB90 jal */
    R[4] = R[17] + R[0];  /* 0x800CFB98 */
    R[5] = R[0] + 5;  /* 0x800CFB9C */
    { R[31] = 0x800CFBA8u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800CFBA0 jal */
    { goto L_800CFDE0; }  /* 0x800CFBA8 j */
    R[5] = lw_(R[17] + 588);  /* 0x800CFBB0 */
    { R[31] = 0x800CFBBCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800CFBB4 jal */
    R[4] = R[17] + R[0];  /* 0x800CFBBC */
    R[5] = 0x8014u << 16;  /* 0x800CFBC0 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFBC4 */
    R[5] = R[5] + 15160;  /* 0x800CFBC8 */
    R[2] = R[3] << 3;  /* 0x800CFBCC */
    R[2] = R[2] + R[3];  /* 0x800CFBD0 */
    R[2] = R[2] << 7;  /* 0x800CFBD4 */
    { R[31] = 0x800CFBE0u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFBD8 jal */
    R[5] = R[0] + 1;  /* 0x800CFBE0 */
    R[6] = R[5] + R[0];  /* 0x800CFBE4 */
    R[2] = 0x8014u << 16;  /* 0x800CFBE8 */
    R[4] = lb_(R[17] + 585);  /* 0x800CFBEC */
    R[16] = R[2] + 15136;  /* 0x800CFBF0 */
    R[4] = R[4] << 2;  /* 0x800CFBF4 */
    { R[31] = 0x800CFC00u; R[4] = R[4] + R[16]; psx_next = 0x800CCF94u; return; }  /* 0x800CFBF8 jal */
    { uint32_t _c = (R[2] == R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800CFD20; } }  /* 0x800CFC00 */
    R[2] = lh_(R[17] + 582);  /* 0x800CFC08 */
    R[2] = R[2] - 1;  /* 0x800CFC10 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFC14 */
    R[2] = R[2] << 16;  /* 0x800CFC18 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[5] = R[0] + 1; if (_c) { goto L_800CFDE0; } }  /* 0x800CFC1C */
    R[4] = lb_(R[17] + 585);  /* 0x800CFC24 */
    R[6] = R[5] + R[0];  /* 0x800CFC28 */
    R[4] = R[4] << 2;  /* 0x800CFC2C */
    { R[31] = 0x800CFC38u; R[4] = R[4] + R[16]; psx_next = 0x800CD028u; return; }  /* 0x800CFC30 jal */
    R[2] = 0x800Fu << 16;  /* 0x800CFC38 */
    R[3] = lw_(R[17] + 588);  /* 0x800CFC3C */
    R[2] = R[2] - 416;  /* 0x800CFC40 */
    sw_(R[17] + 608, R[0]);  /* 0x800CFC44 */
    sh_(R[17] + 14, R[0]);  /* 0x800CFC48 */
    sw_(R[17] + 84, R[2]);  /* 0x800CFC4C */
    R[2] = lb_(R[3] + 2);  /* 0x800CFC50 */
    sh_(R[17] + 596, R[0]);  /* 0x800CFC54 */
    sh_(R[17] + 582, R[19]);  /* 0x800CFC58 */
    sh_(R[17] + 586, R[19]);  /* 0x800CFC5C */
    { sb_(R[17] + 801, R[2]); goto L_800CFDE0; }  /* 0x800CFC60 j */
    R[2] = lw_(R[17] + 588);  /* 0x800CFC68 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 224);  /* 0x800CFC70 */
    R[2] = lh_(R[2] + 224);  /* 0x800CFC74 */
    { uint32_t _c = ((int32_t)R[3] <= 0); R[4] = R[17] + R[0]; if (_c) { goto L_800CFC84; } }  /* 0x800CFC78 */
    sh_(R[17] + 596, R[2]);  /* 0x800CFC80 */
L_800CFC84:;
    R[5] = 0x8014u << 16;  /* 0x800CFC84 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFC88 */
    R[5] = R[5] + 15160;  /* 0x800CFC8C */
    R[2] = R[3] << 3;  /* 0x800CFC90 */
    R[2] = R[2] + R[3];  /* 0x800CFC94 */
    R[2] = R[2] << 7;  /* 0x800CFC98 */
    { R[31] = 0x800CFCA4u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFC9C jal */
    R[3] = lh_(R[17] + 582);  /* 0x800CFCA4 */
    R[3] = R[3] - 1;  /* 0x800CFCAC */
    sh_(R[17] + 582, R[3]);  /* 0x800CFCB0 */
    R[3] = R[3] << 16;  /* 0x800CFCB4 */
    { uint32_t _c = ((int32_t)R[3] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFCB8 */
    { uint32_t _c = ((int32_t)R[2] <= 0); sw_(R[17] + 84, R[0]); if (_c) { goto L_800CFCD4; } }  /* 0x800CFCC0 */
    R[2] = R[0] + 3;  /* 0x800CFCC8 */
    { sh_(R[17] + 586, R[2]); goto L_800CFDE0; }  /* 0x800CFCCC j */
L_800CFCD4:;
    R[2] = R[0] + 4;  /* 0x800CFCD4 */
    { sb_(R[17] + 790, R[2]); goto L_800CFDE0; }  /* 0x800CFCD8 j */
    R[3] = lb_(R[17] + 585);  /* 0x800CFCE0 */
    R[5] = 0x8014u << 16;  /* 0x800CFCE4 */
    R[5] = R[5] + 15160;  /* 0x800CFCE8 */
    R[2] = R[3] << 3;  /* 0x800CFCEC */
    R[2] = R[2] + R[3];  /* 0x800CFCF0 */
    R[2] = R[2] << 7;  /* 0x800CFCF4 */
    { R[31] = 0x800CFD00u; R[5] = R[2] + R[5]; psx_next = 0x800CE8B4u; return; }  /* 0x800CFCF8 jal */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD00 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 596);  /* 0x800CFD08 */
    { uint32_t _c = ((int32_t)R[4] <= 0); R[2] = R[0] + 4; if (_c) { goto L_800CFD24; } }  /* 0x800CFD10 */
    { R[31] = 0x800CFD20u; psx_next = 0x8001D0DCu; return; }  /* 0x800CFD18 jal */
L_800CFD20:;
    R[2] = R[0] + 4;  /* 0x800CFD20 */
L_800CFD24:;
    sh_(R[17] + 582, R[0]);  /* 0x800CFD24 */
    { sb_(R[17] + 790, R[2]); goto L_800CFDE0; }  /* 0x800CFD28 j */
    R[2] = lh_(R[17] + 582);  /* 0x800CFD30 */
    R[2] = R[2] - 1;  /* 0x800CFD38 */
    sh_(R[17] + 582, R[2]);  /* 0x800CFD3C */
    R[2] = R[2] << 16;  /* 0x800CFD40 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800CFD74; } }  /* 0x800CFD44 */
    R[3] = 0x8014u << 16;  /* 0x800CFD4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFD50 */
    R[2] = lw_(R[3] + 15016);  /* 0x800CFD54 */
    R[2] = R[2] - 1;  /* 0x800CFD5C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD60 */
    R[2] = 0x8013u << 16;  /* 0x800CFD68 */
    { sh_(R[2] + -29614, R[0]); goto L_800CFDE0; }  /* 0x800CFD6C j */
L_800CFD74:;
    R[2] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800CFD74 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800CFDD8; } }  /* 0x800CFD7C */
    R[2] = lw_(R[17] + 604);  /* 0x800CFD84 */
    R[3] = lw_(R[17] + 600);  /* 0x800CFD88 */
    R[2] = R[2] - R[3];  /* 0x800CFD90 */
    sw_(R[17] + 604, R[2]);  /* 0x800CFD94 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800CFD98 */
    sb_(R[18] + 52, R[2]);  /* 0x800CFD9C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDA0 */
    sb_(R[18] + 53, R[2]);  /* 0x800CFDA8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800CFDAC */
    { R[31] = 0x800CFDB8u; R[4] = R[18] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800CFDB0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDB8 */
    R[4] = R[17] + R[0];  /* 0x800CFDBC */
    R[3] = R[2] + R[0];  /* 0x800CFDC0 */
    sh_(R[4] + 60, R[2]);  /* 0x800CFDC4 */
    { R[31] = 0x800CFDD0u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CFDC8 jal */
    { goto L_800CFDE0; }  /* 0x800CFDD0 j */
L_800CFDD8:;
    { R[31] = 0x800CFDE0u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800CFDD8 jal */
L_800CFDE0:;
    R[31] = lw_(R[29] + 52);  /* 0x800CFDE0 */
    R[20] = lw_(R[29] + 48);  /* 0x800CFDE4 */
    R[19] = lw_(R[29] + 44);  /* 0x800CFDE8 */
    R[18] = lw_(R[29] + 40);  /* 0x800CFDEC */
    R[17] = lw_(R[29] + 36);  /* 0x800CFDF0 */
    R[16] = lw_(R[29] + 32);  /* 0x800CFDF4 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CFDF8 jr ra */
}
