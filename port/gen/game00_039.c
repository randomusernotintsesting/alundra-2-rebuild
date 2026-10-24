#include "game00_decls.h"

void g0_800CFAB8(void) {
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

void g0_800CFB48(void) {
    R[2] = R[0] + 4;  /* 0x800CFB48 */
    sh_(R[17] + 582, R[16]);  /* 0x800CFB4C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFB50 */
    R[2] = R[0] + 3;  /* 0x800CFB54 */
    { sb_(R[17] + 786, R[2]); goto L_800CFDE0; }  /* 0x800CFB58 j */
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

void g0_800CFB90(void) {
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

void g0_800CFB98(void) {
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

void g0_800CFBA8(void) {
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

void g0_800CFBBC(void) {
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

void g0_800CFBE0(void) {
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

void g0_800CFC00(void) {
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

void g0_800CFC38(void) {
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

void g0_800CFCA4(void) {
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

void g0_800CFD00(void) {
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_800CFDE0; } }  /* 0x800CFD00 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 596);  /* 0x800CFD08 */
    { uint32_t _c = ((int32_t)R[4] <= 0); R[2] = R[0] + 4; if (_c) { goto L_800CFD24; } }  /* 0x800CFD10 */
    { R[31] = 0x800CFD20u; psx_next = 0x8001D0DCu; return; }  /* 0x800CFD18 jal */
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

void g0_800CFD20(void) {
    R[2] = R[0] + 4;  /* 0x800CFD20 */
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

void g0_800CFDB8(void) {
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800CFDB8 */
    R[4] = R[17] + R[0];  /* 0x800CFDBC */
    R[3] = R[2] + R[0];  /* 0x800CFDC0 */
    sh_(R[4] + 60, R[2]);  /* 0x800CFDC4 */
    { R[31] = 0x800CFDD0u; sh_(R[4] + 62, R[3]); psx_next = 0x800CDCACu; return; }  /* 0x800CFDC8 jal */
    { goto L_800CFDE0; }  /* 0x800CFDD0 j */
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

void g0_800CFDD0(void) {
    { goto L_800CFDE0; }  /* 0x800CFDD0 j */
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

void g0_800CFDE0(void) {
    R[31] = lw_(R[29] + 52);  /* 0x800CFDE0 */
    R[20] = lw_(R[29] + 48);  /* 0x800CFDE4 */
    R[19] = lw_(R[29] + 44);  /* 0x800CFDE8 */
    R[18] = lw_(R[29] + 40);  /* 0x800CFDEC */
    R[17] = lw_(R[29] + 36);  /* 0x800CFDF0 */
    R[16] = lw_(R[29] + 32);  /* 0x800CFDF4 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800CFDF8 jr ra */
}

void g0_800CFE00(void) {
    R[29] = R[29] - 32;  /* 0x800CFE00 */
    sw_(R[29] + 20, R[17]);  /* 0x800CFE04 */
    R[17] = R[4] + R[0];  /* 0x800CFE08 */
    sw_(R[29] + 28, R[31]);  /* 0x800CFE0C */
    sw_(R[29] + 24, R[18]);  /* 0x800CFE10 */
    sw_(R[29] + 16, R[16]);  /* 0x800CFE14 */
    R[2] = lh_(R[17] + 2);  /* 0x800CFE18 */
    R[3] = R[2] << 3;  /* 0x800CFE20 */
    R[3] = R[3] + R[2];  /* 0x800CFE24 */
    R[3] = R[3] << 3;  /* 0x800CFE28 */
    R[2] = 0x8013u << 16;  /* 0x800CFE2C */
    R[2] = R[2] - 23304;  /* 0x800CFE30 */
    R[16] = R[3] + R[2];  /* 0x800CFE34 */
    R[2] = R[0] + 2;  /* 0x800CFE38 */
    { uint32_t _c = (R[5] == R[2]); R[2] = ((int32_t)R[5] < 3); if (_c) { goto L_800D0130; } }  /* 0x800CFE3C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800CFE5C; } }  /* 0x800CFE44 */
    { uint32_t _c = (R[5] == R[0]); if (_c) { goto L_800CFEE4; } }  /* 0x800CFE4C */
    { goto L_800D0214; }  /* 0x800CFE54 j */
L_800CFE5C:;
    R[2] = R[0] + 5;  /* 0x800CFE5C */
    { uint32_t _c = (R[5] != R[2]); R[5] = R[16] + R[0]; if (_c) { goto L_800D0214; } }  /* 0x800CFE60 */
    R[4] = R[0] + R[0];  /* 0x800CFE68 */
    R[6] = 0x800Fu << 16;  /* 0x800CFE6C */
    R[6] = R[6] - 372;  /* 0x800CFE70 */
    R[7] = R[17] + 24;  /* 0x800CFE74 */
    R[2] = R[0] + 1;  /* 0x800CFE78 */
    sb_(R[17] + 688, R[2]);  /* 0x800CFE7C */
    { R[31] = 0x800CFE88u; sb_(R[17] + 690, R[2]); psx_next = 0x800A5964u; return; }  /* 0x800CFE80 jal */
    R[4] = R[17] + R[0];  /* 0x800CFE88 */
    R[5] = 0x800Fu << 16;  /* 0x800CFE8C */
    R[5] = R[5] - 396;  /* 0x800CFE90 */
    R[2] = R[0] + 25;  /* 0x800CFE94 */
    sb_(R[16] + 52, R[2]);  /* 0x800CFE98 */
    sb_(R[16] + 53, R[2]);  /* 0x800CFE9C */
    R[2] = 0x800Bu << 16;  /* 0x800CFEA0 */
    R[2] = R[2] - 8012;  /* 0x800CFEA4 */
    sw_(R[4] + 232, R[2]);  /* 0x800CFEA8 */
    R[2] = R[0] + 6400;  /* 0x800CFEAC */
    sw_(R[4] + 124, R[2]);  /* 0x800CFEB0 */
    R[2] = 0x800Fu << 16;  /* 0x800CFEB4 */
    R[2] = R[2] - 496;  /* 0x800CFEB8 */
    sw_(R[4] + 84, R[2]);  /* 0x800CFEBC */
    R[2] = R[0] + 40;  /* 0x800CFEC0 */
    sh_(R[4] + 582, R[2]);  /* 0x800CFEC4 */
    R[2] = R[0] | 0xA000;  /* 0x800CFEC8 */
    sw_(R[4] + 600, R[2]);  /* 0x800CFECC */
    R[2] = 0x32u << 16;  /* 0x800CFED0 */
    { R[31] = 0x800CFEDCu; sw_(R[4] + 604, R[2]); psx_next = 0x800CD894u; return; }  /* 0x800CFED4 jal */
    { goto L_800D0214; }  /* 0x800CFEDC j */
L_800CFEE4:;
    R[2] = lh_(R[17] + 582);  /* 0x800CFEE4 */
    R[2] = R[2] - 1;  /* 0x800CFEEC */
    sh_(R[17] + 582, R[2]);  /* 0x800CFEF0 */
    R[2] = R[2] << 16;  /* 0x800CFEF4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[4] = R[0] - 128; if (_c) { goto L_800CFF80; } }  /* 0x800CFEF8 */
    R[16] = R[0] + 8;  /* 0x800CFF00 */
    psx_div((int32_t)R[4], (int32_t)R[16]);  /* 0x800CFF04 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CFF14; } }  /* 0x800CFF08 */
    psx_break(7168);  /* 0x800CFF10 */
L_800CFF14:;
    R[1] = R[0] - 1;  /* 0x800CFF14 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CFF2C; } }  /* 0x800CFF18 */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CFF2C; } }  /* 0x800CFF20 */
    psx_break(6144);  /* 0x800CFF28 */
L_800CFF2C:;
    R[4] = LO;  /* 0x800CFF2C */
    R[3] = lw_(R[17] + 604);  /* 0x800CFF30 */
    psx_div((int32_t)R[3], (int32_t)R[16]);  /* 0x800CFF38 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CFF48; } }  /* 0x800CFF3C */
    psx_break(7168);  /* 0x800CFF44 */
L_800CFF48:;
    R[1] = R[0] - 1;  /* 0x800CFF48 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CFF60; } }  /* 0x800CFF4C */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CFF60; } }  /* 0x800CFF54 */
    psx_break(6144);  /* 0x800CFF5C */
L_800CFF60:;
    R[3] = LO;  /* 0x800CFF60 */
    sb_(R[17] + 584, R[0]);  /* 0x800CFF64 */
    sh_(R[17] + 582, R[16]);  /* 0x800CFF68 */
    R[2] = R[0] + 4;  /* 0x800CFF6C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFF70 */
    sh_(R[17] + 592, R[4]);  /* 0x800CFF74 */
    { sw_(R[17] + 600, R[3]); goto L_800D0214; }  /* 0x800CFF78 j */
L_800CFF80:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 218);  /* 0x800CFF80 */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[4] = R[17] + R[0]; if (_c) { goto L_800D0024; } }  /* 0x800CFF88 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFF90 */
    R[5] = R[0] + 1;  /* 0x800CFF94 */
    R[2] = 0x8014u << 16;  /* 0x800CFF98 */
    R[2] = R[2] + 15136;  /* 0x800CFF9C */
    R[3] = R[3] << 2;  /* 0x800CFFA0 */
    R[16] = R[3] + R[2];  /* 0x800CFFA4 */
    { R[31] = 0x800CFFB0u; R[6] = R[16] + R[0]; psx_next = 0x800CE504u; return; }  /* 0x800CFFA8 jal */
    R[18] = R[2] + R[0];  /* 0x800CFFB0 */
    { uint32_t _c = ((int32_t)R[18] <= 0); if (_c) { goto L_800D0034; } }  /* 0x800CFFB4 */
    R[4] = lw_(R[16]);  /* 0x800CFFBC */
    { R[31] = 0x800CFFC8u; psx_next = 0x800D0CC4u; return; }  /* 0x800CFFC0 jal */
    { uint32_t _c = ((int32_t)R[2] < 0); if (_c) { goto L_800D0034; } }  /* 0x800CFFC8 */
    { R[31] = 0x800CFFD8u; R[4] = R[0] + 59; psx_next = 0x8002DB10u; return; }  /* 0x800CFFD0 jal */
    R[2] = R[0] + 1;  /* 0x800CFFD8 */
    R[5] = 0x800Fu << 16;  /* 0x800CFFDC */
    sb_(R[17] + 584, R[2]);  /* 0x800CFFE0 */
    R[4] = lw_(R[16]);  /* 0x800CFFE4 */
    R[6] = lb_(R[17] + 585);  /* 0x800CFFE8 */
    { R[31] = 0x800CFFF4u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CFFEC jal */
    R[3] = lw_(R[16]);  /* 0x800CFFF4 */
    R[2] = lb_(R[3] + 789);  /* 0x800CFFFC */
    R[2] = R[2] | 0x2;  /* 0x800D0004 */
    sb_(R[3] + 789, R[2]);  /* 0x800D0008 */
    R[3] = lw_(R[16]);  /* 0x800D000C */
    R[2] = R[0] + 150;  /* 0x800D0010 */
    sw_(R[17] + 608, R[18]);  /* 0x800D0014 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0018 */
    { sw_(R[17] + 588, R[3]); goto L_800D0058; }  /* 0x800D001C j */
L_800D0024:;
    R[2] = lb_(R[17] + 785);  /* 0x800D0024 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_800D006C; } }  /* 0x800D002C */
L_800D0034:;
    R[16] = R[0] + 8;  /* 0x800D0034 */
    R[4] = R[17] + R[0];  /* 0x800D0038 */
    R[5] = 0x800Fu << 16;  /* 0x800D003C */
    R[5] = R[5] - 372;  /* 0x800D0040 */
    R[6] = R[16] + R[0];  /* 0x800D0044 */
    R[2] = R[0] + 2;  /* 0x800D0048 */
    { R[31] = 0x800D0054u; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800D004C jal */
    sh_(R[17] + 582, R[16]);  /* 0x800D0054 */
L_800D0058:;
    R[2] = R[0] + 3;  /* 0x800D0058 */
    sb_(R[17] + 786, R[2]);  /* 0x800D005C */
    R[2] = R[0] + 4;  /* 0x800D0060 */
    { sb_(R[17] + 790, R[2]); goto L_800D0214; }  /* 0x800D0064 j */
L_800D006C:;
    sb_(R[16] + 3, R[2]);  /* 0x800D006C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0070 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0074 */
    R[2] = R[2] - R[3];  /* 0x800D007C */
    sw_(R[17] + 604, R[2]);  /* 0x800D0080 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0084 */
    sb_(R[16] + 52, R[2]);  /* 0x800D0088 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D008C */
    sb_(R[16] + 53, R[2]);  /* 0x800D0094 */
    R[2] = lh_(R[17] + 582);  /* 0x800D0098 */
    R[2] = R[2] & 0x3;  /* 0x800D00A0 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] + 8; if (_c) { goto L_800D00EC; } }  /* 0x800D00A4 */
    R[3] = lb_(R[17] + 585);  /* 0x800D00AC */
    R[5] = R[0] + 15;  /* 0x800D00B0 */
    R[4] = 0x8014u << 16;  /* 0x800D00B4 */
    R[4] = R[4] + 15160;  /* 0x800D00B8 */
    R[2] = R[3] << 3;  /* 0x800D00BC */
    R[2] = R[2] + R[3];  /* 0x800D00C0 */
    R[2] = R[2] << 7;  /* 0x800D00C4 */
    { R[31] = 0x800D00D0u; R[4] = R[2] + R[4]; psx_next = 0x800BDFDCu; return; }  /* 0x800D00C8 jal */
    R[4] = R[2] + R[0];  /* 0x800D00D0 */
    R[5] = R[17] + 24;  /* 0x800D00D4 */
    R[6] = R[0] + 25;  /* 0x800D00D8 */
    R[7] = 0x800Fu << 16;  /* 0x800D00DC */
    { R[31] = 0x800D00E8u; R[7] = R[7] - 372; psx_next = 0x800CDD84u; return; }  /* 0x800D00E0 jal */
    R[5] = R[0] + 8;  /* 0x800D00E8 */
L_800D00EC:;
    R[3] = lb_(R[17] + 585);  /* 0x800D00EC */
    R[6] = R[0] + 16384;  /* 0x800D00F0 */
    R[4] = 0x8014u << 16;  /* 0x800D00F4 */
    R[4] = R[4] + 15160;  /* 0x800D00F8 */
    R[2] = R[3] << 3;  /* 0x800D00FC */
    R[2] = R[2] + R[3];  /* 0x800D0100 */
    R[2] = R[2] << 7;  /* 0x800D0104 */
    { R[31] = 0x800D0110u; R[4] = R[2] + R[4]; psx_next = 0x800CDE50u; return; }  /* 0x800D0108 jal */
    { R[31] = 0x800D0118u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D0110 jal */
    R[4] = R[17] + R[0];  /* 0x800D0118 */
    R[5] = R[0] + 5;  /* 0x800D011C */
    { R[31] = 0x800D0128u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D0120 jal */
    { goto L_800D0214; }  /* 0x800D0128 j */
L_800D0130:;
    R[2] = lh_(R[17] + 582);  /* 0x800D0130 */
    R[2] = R[2] - 1;  /* 0x800D0138 */
    sh_(R[17] + 582, R[2]);  /* 0x800D013C */
    R[2] = R[2] << 16;  /* 0x800D0140 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800D0174; } }  /* 0x800D0144 */
    R[3] = 0x8014u << 16;  /* 0x800D014C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0150 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D0154 */
    R[2] = R[2] - 1;  /* 0x800D015C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D0214; } }  /* 0x800D0160 */
    R[2] = 0x8013u << 16;  /* 0x800D0168 */
    { sh_(R[2] + -29614, R[0]); goto L_800D0214; }  /* 0x800D016C j */
L_800D0174:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D0174 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D01D0; } }  /* 0x800D017C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0184 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0188 */
    R[2] = R[2] - R[3];  /* 0x800D0190 */
    sw_(R[17] + 604, R[2]);  /* 0x800D0194 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0198 */
    sb_(R[16] + 52, R[2]);  /* 0x800D019C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01A0 */
    sb_(R[16] + 53, R[2]);  /* 0x800D01A8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800D01AC */
    { R[31] = 0x800D01B8u; R[4] = R[16] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800D01B0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01B8 */
    R[3] = R[2] + R[0];  /* 0x800D01C0 */
    sh_(R[17] + 60, R[2]);  /* 0x800D01C4 */
    { sh_(R[17] + 62, R[3]); goto L_800D0214; }  /* 0x800D01C8 j */
L_800D01D0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D0214; } }  /* 0x800D01D0 */
    R[6] = R[0] + 1;  /* 0x800D01D8 */
    R[4] = 0x8014u << 16;  /* 0x800D01DC */
    R[2] = lb_(R[17] + 585);  /* 0x800D01E0 */
    R[4] = R[4] + 15136;  /* 0x800D01E4 */
    R[2] = R[2] << 2;  /* 0x800D01E8 */
    { R[31] = 0x800D01F4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D01EC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D0200; } }  /* 0x800D01F4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D01FC */
L_800D0200:;
    { R[31] = 0x800D0208u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800D0200 jal */
    R[5] = lw_(R[17] + 588);  /* 0x800D0208 */
    { R[31] = 0x800D0214u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D020C jal */
L_800D0214:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800CFE88(void) {
    R[4] = R[17] + R[0];  /* 0x800CFE88 */
    R[5] = 0x800Fu << 16;  /* 0x800CFE8C */
    R[5] = R[5] - 396;  /* 0x800CFE90 */
    R[2] = R[0] + 25;  /* 0x800CFE94 */
    sb_(R[16] + 52, R[2]);  /* 0x800CFE98 */
    sb_(R[16] + 53, R[2]);  /* 0x800CFE9C */
    R[2] = 0x800Bu << 16;  /* 0x800CFEA0 */
    R[2] = R[2] - 8012;  /* 0x800CFEA4 */
    sw_(R[4] + 232, R[2]);  /* 0x800CFEA8 */
    R[2] = R[0] + 6400;  /* 0x800CFEAC */
    sw_(R[4] + 124, R[2]);  /* 0x800CFEB0 */
    R[2] = 0x800Fu << 16;  /* 0x800CFEB4 */
    R[2] = R[2] - 496;  /* 0x800CFEB8 */
    sw_(R[4] + 84, R[2]);  /* 0x800CFEBC */
    R[2] = R[0] + 40;  /* 0x800CFEC0 */
    sh_(R[4] + 582, R[2]);  /* 0x800CFEC4 */
    R[2] = R[0] | 0xA000;  /* 0x800CFEC8 */
    sw_(R[4] + 600, R[2]);  /* 0x800CFECC */
    R[2] = 0x32u << 16;  /* 0x800CFED0 */
    { R[31] = 0x800CFEDCu; sw_(R[4] + 604, R[2]); psx_next = 0x800CD894u; return; }  /* 0x800CFED4 jal */
    { goto L_800D0214; }  /* 0x800CFEDC j */
    R[2] = lh_(R[17] + 582);  /* 0x800CFEE4 */
    R[2] = R[2] - 1;  /* 0x800CFEEC */
    sh_(R[17] + 582, R[2]);  /* 0x800CFEF0 */
    R[2] = R[2] << 16;  /* 0x800CFEF4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[4] = R[0] - 128; if (_c) { goto L_800CFF80; } }  /* 0x800CFEF8 */
    R[16] = R[0] + 8;  /* 0x800CFF00 */
    psx_div((int32_t)R[4], (int32_t)R[16]);  /* 0x800CFF04 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CFF14; } }  /* 0x800CFF08 */
    psx_break(7168);  /* 0x800CFF10 */
L_800CFF14:;
    R[1] = R[0] - 1;  /* 0x800CFF14 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CFF2C; } }  /* 0x800CFF18 */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CFF2C; } }  /* 0x800CFF20 */
    psx_break(6144);  /* 0x800CFF28 */
L_800CFF2C:;
    R[4] = LO;  /* 0x800CFF2C */
    R[3] = lw_(R[17] + 604);  /* 0x800CFF30 */
    psx_div((int32_t)R[3], (int32_t)R[16]);  /* 0x800CFF38 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CFF48; } }  /* 0x800CFF3C */
    psx_break(7168);  /* 0x800CFF44 */
L_800CFF48:;
    R[1] = R[0] - 1;  /* 0x800CFF48 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CFF60; } }  /* 0x800CFF4C */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CFF60; } }  /* 0x800CFF54 */
    psx_break(6144);  /* 0x800CFF5C */
L_800CFF60:;
    R[3] = LO;  /* 0x800CFF60 */
    sb_(R[17] + 584, R[0]);  /* 0x800CFF64 */
    sh_(R[17] + 582, R[16]);  /* 0x800CFF68 */
    R[2] = R[0] + 4;  /* 0x800CFF6C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFF70 */
    sh_(R[17] + 592, R[4]);  /* 0x800CFF74 */
    { sw_(R[17] + 600, R[3]); goto L_800D0214; }  /* 0x800CFF78 j */
L_800CFF80:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 218);  /* 0x800CFF80 */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[4] = R[17] + R[0]; if (_c) { goto L_800D0024; } }  /* 0x800CFF88 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFF90 */
    R[5] = R[0] + 1;  /* 0x800CFF94 */
    R[2] = 0x8014u << 16;  /* 0x800CFF98 */
    R[2] = R[2] + 15136;  /* 0x800CFF9C */
    R[3] = R[3] << 2;  /* 0x800CFFA0 */
    R[16] = R[3] + R[2];  /* 0x800CFFA4 */
    { R[31] = 0x800CFFB0u; R[6] = R[16] + R[0]; psx_next = 0x800CE504u; return; }  /* 0x800CFFA8 jal */
    R[18] = R[2] + R[0];  /* 0x800CFFB0 */
    { uint32_t _c = ((int32_t)R[18] <= 0); if (_c) { goto L_800D0034; } }  /* 0x800CFFB4 */
    R[4] = lw_(R[16]);  /* 0x800CFFBC */
    { R[31] = 0x800CFFC8u; psx_next = 0x800D0CC4u; return; }  /* 0x800CFFC0 jal */
    { uint32_t _c = ((int32_t)R[2] < 0); if (_c) { goto L_800D0034; } }  /* 0x800CFFC8 */
    { R[31] = 0x800CFFD8u; R[4] = R[0] + 59; psx_next = 0x8002DB10u; return; }  /* 0x800CFFD0 jal */
    R[2] = R[0] + 1;  /* 0x800CFFD8 */
    R[5] = 0x800Fu << 16;  /* 0x800CFFDC */
    sb_(R[17] + 584, R[2]);  /* 0x800CFFE0 */
    R[4] = lw_(R[16]);  /* 0x800CFFE4 */
    R[6] = lb_(R[17] + 585);  /* 0x800CFFE8 */
    { R[31] = 0x800CFFF4u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CFFEC jal */
    R[3] = lw_(R[16]);  /* 0x800CFFF4 */
    R[2] = lb_(R[3] + 789);  /* 0x800CFFFC */
    R[2] = R[2] | 0x2;  /* 0x800D0004 */
    sb_(R[3] + 789, R[2]);  /* 0x800D0008 */
    R[3] = lw_(R[16]);  /* 0x800D000C */
    R[2] = R[0] + 150;  /* 0x800D0010 */
    sw_(R[17] + 608, R[18]);  /* 0x800D0014 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0018 */
    { sw_(R[17] + 588, R[3]); goto L_800D0058; }  /* 0x800D001C j */
L_800D0024:;
    R[2] = lb_(R[17] + 785);  /* 0x800D0024 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_800D006C; } }  /* 0x800D002C */
L_800D0034:;
    R[16] = R[0] + 8;  /* 0x800D0034 */
    R[4] = R[17] + R[0];  /* 0x800D0038 */
    R[5] = 0x800Fu << 16;  /* 0x800D003C */
    R[5] = R[5] - 372;  /* 0x800D0040 */
    R[6] = R[16] + R[0];  /* 0x800D0044 */
    R[2] = R[0] + 2;  /* 0x800D0048 */
    { R[31] = 0x800D0054u; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800D004C jal */
    sh_(R[17] + 582, R[16]);  /* 0x800D0054 */
L_800D0058:;
    R[2] = R[0] + 3;  /* 0x800D0058 */
    sb_(R[17] + 786, R[2]);  /* 0x800D005C */
    R[2] = R[0] + 4;  /* 0x800D0060 */
    { sb_(R[17] + 790, R[2]); goto L_800D0214; }  /* 0x800D0064 j */
L_800D006C:;
    sb_(R[16] + 3, R[2]);  /* 0x800D006C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0070 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0074 */
    R[2] = R[2] - R[3];  /* 0x800D007C */
    sw_(R[17] + 604, R[2]);  /* 0x800D0080 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0084 */
    sb_(R[16] + 52, R[2]);  /* 0x800D0088 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D008C */
    sb_(R[16] + 53, R[2]);  /* 0x800D0094 */
    R[2] = lh_(R[17] + 582);  /* 0x800D0098 */
    R[2] = R[2] & 0x3;  /* 0x800D00A0 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] + 8; if (_c) { goto L_800D00EC; } }  /* 0x800D00A4 */
    R[3] = lb_(R[17] + 585);  /* 0x800D00AC */
    R[5] = R[0] + 15;  /* 0x800D00B0 */
    R[4] = 0x8014u << 16;  /* 0x800D00B4 */
    R[4] = R[4] + 15160;  /* 0x800D00B8 */
    R[2] = R[3] << 3;  /* 0x800D00BC */
    R[2] = R[2] + R[3];  /* 0x800D00C0 */
    R[2] = R[2] << 7;  /* 0x800D00C4 */
    { R[31] = 0x800D00D0u; R[4] = R[2] + R[4]; psx_next = 0x800BDFDCu; return; }  /* 0x800D00C8 jal */
    R[4] = R[2] + R[0];  /* 0x800D00D0 */
    R[5] = R[17] + 24;  /* 0x800D00D4 */
    R[6] = R[0] + 25;  /* 0x800D00D8 */
    R[7] = 0x800Fu << 16;  /* 0x800D00DC */
    { R[31] = 0x800D00E8u; R[7] = R[7] - 372; psx_next = 0x800CDD84u; return; }  /* 0x800D00E0 jal */
    R[5] = R[0] + 8;  /* 0x800D00E8 */
L_800D00EC:;
    R[3] = lb_(R[17] + 585);  /* 0x800D00EC */
    R[6] = R[0] + 16384;  /* 0x800D00F0 */
    R[4] = 0x8014u << 16;  /* 0x800D00F4 */
    R[4] = R[4] + 15160;  /* 0x800D00F8 */
    R[2] = R[3] << 3;  /* 0x800D00FC */
    R[2] = R[2] + R[3];  /* 0x800D0100 */
    R[2] = R[2] << 7;  /* 0x800D0104 */
    { R[31] = 0x800D0110u; R[4] = R[2] + R[4]; psx_next = 0x800CDE50u; return; }  /* 0x800D0108 jal */
    { R[31] = 0x800D0118u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D0110 jal */
    R[4] = R[17] + R[0];  /* 0x800D0118 */
    R[5] = R[0] + 5;  /* 0x800D011C */
    { R[31] = 0x800D0128u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D0120 jal */
    { goto L_800D0214; }  /* 0x800D0128 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D0130 */
    R[2] = R[2] - 1;  /* 0x800D0138 */
    sh_(R[17] + 582, R[2]);  /* 0x800D013C */
    R[2] = R[2] << 16;  /* 0x800D0140 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800D0174; } }  /* 0x800D0144 */
    R[3] = 0x8014u << 16;  /* 0x800D014C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0150 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D0154 */
    R[2] = R[2] - 1;  /* 0x800D015C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D0214; } }  /* 0x800D0160 */
    R[2] = 0x8013u << 16;  /* 0x800D0168 */
    { sh_(R[2] + -29614, R[0]); goto L_800D0214; }  /* 0x800D016C j */
L_800D0174:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D0174 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D01D0; } }  /* 0x800D017C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0184 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0188 */
    R[2] = R[2] - R[3];  /* 0x800D0190 */
    sw_(R[17] + 604, R[2]);  /* 0x800D0194 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0198 */
    sb_(R[16] + 52, R[2]);  /* 0x800D019C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01A0 */
    sb_(R[16] + 53, R[2]);  /* 0x800D01A8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800D01AC */
    { R[31] = 0x800D01B8u; R[4] = R[16] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800D01B0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01B8 */
    R[3] = R[2] + R[0];  /* 0x800D01C0 */
    sh_(R[17] + 60, R[2]);  /* 0x800D01C4 */
    { sh_(R[17] + 62, R[3]); goto L_800D0214; }  /* 0x800D01C8 j */
L_800D01D0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D0214; } }  /* 0x800D01D0 */
    R[6] = R[0] + 1;  /* 0x800D01D8 */
    R[4] = 0x8014u << 16;  /* 0x800D01DC */
    R[2] = lb_(R[17] + 585);  /* 0x800D01E0 */
    R[4] = R[4] + 15136;  /* 0x800D01E4 */
    R[2] = R[2] << 2;  /* 0x800D01E8 */
    { R[31] = 0x800D01F4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D01EC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D0200; } }  /* 0x800D01F4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D01FC */
L_800D0200:;
    { R[31] = 0x800D0208u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800D0200 jal */
    R[5] = lw_(R[17] + 588);  /* 0x800D0208 */
    { R[31] = 0x800D0214u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D020C jal */
L_800D0214:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800CFEDC(void) {
    { goto L_800D0214; }  /* 0x800CFEDC j */
    R[2] = lh_(R[17] + 582);  /* 0x800CFEE4 */
    R[2] = R[2] - 1;  /* 0x800CFEEC */
    sh_(R[17] + 582, R[2]);  /* 0x800CFEF0 */
    R[2] = R[2] << 16;  /* 0x800CFEF4 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[4] = R[0] - 128; if (_c) { goto L_800CFF80; } }  /* 0x800CFEF8 */
    R[16] = R[0] + 8;  /* 0x800CFF00 */
    psx_div((int32_t)R[4], (int32_t)R[16]);  /* 0x800CFF04 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CFF14; } }  /* 0x800CFF08 */
    psx_break(7168);  /* 0x800CFF10 */
L_800CFF14:;
    R[1] = R[0] - 1;  /* 0x800CFF14 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CFF2C; } }  /* 0x800CFF18 */
    { uint32_t _c = (R[4] != R[1]); if (_c) { goto L_800CFF2C; } }  /* 0x800CFF20 */
    psx_break(6144);  /* 0x800CFF28 */
L_800CFF2C:;
    R[4] = LO;  /* 0x800CFF2C */
    R[3] = lw_(R[17] + 604);  /* 0x800CFF30 */
    psx_div((int32_t)R[3], (int32_t)R[16]);  /* 0x800CFF38 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800CFF48; } }  /* 0x800CFF3C */
    psx_break(7168);  /* 0x800CFF44 */
L_800CFF48:;
    R[1] = R[0] - 1;  /* 0x800CFF48 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800CFF60; } }  /* 0x800CFF4C */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_800CFF60; } }  /* 0x800CFF54 */
    psx_break(6144);  /* 0x800CFF5C */
L_800CFF60:;
    R[3] = LO;  /* 0x800CFF60 */
    sb_(R[17] + 584, R[0]);  /* 0x800CFF64 */
    sh_(R[17] + 582, R[16]);  /* 0x800CFF68 */
    R[2] = R[0] + 4;  /* 0x800CFF6C */
    sb_(R[17] + 790, R[2]);  /* 0x800CFF70 */
    sh_(R[17] + 592, R[4]);  /* 0x800CFF74 */
    { sw_(R[17] + 600, R[3]); goto L_800D0214; }  /* 0x800CFF78 j */
L_800CFF80:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 218);  /* 0x800CFF80 */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[4] = R[17] + R[0]; if (_c) { goto L_800D0024; } }  /* 0x800CFF88 */
    R[3] = lb_(R[17] + 585);  /* 0x800CFF90 */
    R[5] = R[0] + 1;  /* 0x800CFF94 */
    R[2] = 0x8014u << 16;  /* 0x800CFF98 */
    R[2] = R[2] + 15136;  /* 0x800CFF9C */
    R[3] = R[3] << 2;  /* 0x800CFFA0 */
    R[16] = R[3] + R[2];  /* 0x800CFFA4 */
    { R[31] = 0x800CFFB0u; R[6] = R[16] + R[0]; psx_next = 0x800CE504u; return; }  /* 0x800CFFA8 jal */
    R[18] = R[2] + R[0];  /* 0x800CFFB0 */
    { uint32_t _c = ((int32_t)R[18] <= 0); if (_c) { goto L_800D0034; } }  /* 0x800CFFB4 */
    R[4] = lw_(R[16]);  /* 0x800CFFBC */
    { R[31] = 0x800CFFC8u; psx_next = 0x800D0CC4u; return; }  /* 0x800CFFC0 jal */
    { uint32_t _c = ((int32_t)R[2] < 0); if (_c) { goto L_800D0034; } }  /* 0x800CFFC8 */
    { R[31] = 0x800CFFD8u; R[4] = R[0] + 59; psx_next = 0x8002DB10u; return; }  /* 0x800CFFD0 jal */
    R[2] = R[0] + 1;  /* 0x800CFFD8 */
    R[5] = 0x800Fu << 16;  /* 0x800CFFDC */
    sb_(R[17] + 584, R[2]);  /* 0x800CFFE0 */
    R[4] = lw_(R[16]);  /* 0x800CFFE4 */
    R[6] = lb_(R[17] + 585);  /* 0x800CFFE8 */
    { R[31] = 0x800CFFF4u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CFFEC jal */
    R[3] = lw_(R[16]);  /* 0x800CFFF4 */
    R[2] = lb_(R[3] + 789);  /* 0x800CFFFC */
    R[2] = R[2] | 0x2;  /* 0x800D0004 */
    sb_(R[3] + 789, R[2]);  /* 0x800D0008 */
    R[3] = lw_(R[16]);  /* 0x800D000C */
    R[2] = R[0] + 150;  /* 0x800D0010 */
    sw_(R[17] + 608, R[18]);  /* 0x800D0014 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0018 */
    { sw_(R[17] + 588, R[3]); goto L_800D0058; }  /* 0x800D001C j */
L_800D0024:;
    R[2] = lb_(R[17] + 785);  /* 0x800D0024 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_800D006C; } }  /* 0x800D002C */
L_800D0034:;
    R[16] = R[0] + 8;  /* 0x800D0034 */
    R[4] = R[17] + R[0];  /* 0x800D0038 */
    R[5] = 0x800Fu << 16;  /* 0x800D003C */
    R[5] = R[5] - 372;  /* 0x800D0040 */
    R[6] = R[16] + R[0];  /* 0x800D0044 */
    R[2] = R[0] + 2;  /* 0x800D0048 */
    { R[31] = 0x800D0054u; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800D004C jal */
    sh_(R[17] + 582, R[16]);  /* 0x800D0054 */
L_800D0058:;
    R[2] = R[0] + 3;  /* 0x800D0058 */
    sb_(R[17] + 786, R[2]);  /* 0x800D005C */
    R[2] = R[0] + 4;  /* 0x800D0060 */
    { sb_(R[17] + 790, R[2]); goto L_800D0214; }  /* 0x800D0064 j */
L_800D006C:;
    sb_(R[16] + 3, R[2]);  /* 0x800D006C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0070 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0074 */
    R[2] = R[2] - R[3];  /* 0x800D007C */
    sw_(R[17] + 604, R[2]);  /* 0x800D0080 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0084 */
    sb_(R[16] + 52, R[2]);  /* 0x800D0088 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D008C */
    sb_(R[16] + 53, R[2]);  /* 0x800D0094 */
    R[2] = lh_(R[17] + 582);  /* 0x800D0098 */
    R[2] = R[2] & 0x3;  /* 0x800D00A0 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] + 8; if (_c) { goto L_800D00EC; } }  /* 0x800D00A4 */
    R[3] = lb_(R[17] + 585);  /* 0x800D00AC */
    R[5] = R[0] + 15;  /* 0x800D00B0 */
    R[4] = 0x8014u << 16;  /* 0x800D00B4 */
    R[4] = R[4] + 15160;  /* 0x800D00B8 */
    R[2] = R[3] << 3;  /* 0x800D00BC */
    R[2] = R[2] + R[3];  /* 0x800D00C0 */
    R[2] = R[2] << 7;  /* 0x800D00C4 */
    { R[31] = 0x800D00D0u; R[4] = R[2] + R[4]; psx_next = 0x800BDFDCu; return; }  /* 0x800D00C8 jal */
    R[4] = R[2] + R[0];  /* 0x800D00D0 */
    R[5] = R[17] + 24;  /* 0x800D00D4 */
    R[6] = R[0] + 25;  /* 0x800D00D8 */
    R[7] = 0x800Fu << 16;  /* 0x800D00DC */
    { R[31] = 0x800D00E8u; R[7] = R[7] - 372; psx_next = 0x800CDD84u; return; }  /* 0x800D00E0 jal */
    R[5] = R[0] + 8;  /* 0x800D00E8 */
L_800D00EC:;
    R[3] = lb_(R[17] + 585);  /* 0x800D00EC */
    R[6] = R[0] + 16384;  /* 0x800D00F0 */
    R[4] = 0x8014u << 16;  /* 0x800D00F4 */
    R[4] = R[4] + 15160;  /* 0x800D00F8 */
    R[2] = R[3] << 3;  /* 0x800D00FC */
    R[2] = R[2] + R[3];  /* 0x800D0100 */
    R[2] = R[2] << 7;  /* 0x800D0104 */
    { R[31] = 0x800D0110u; R[4] = R[2] + R[4]; psx_next = 0x800CDE50u; return; }  /* 0x800D0108 jal */
    { R[31] = 0x800D0118u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D0110 jal */
    R[4] = R[17] + R[0];  /* 0x800D0118 */
    R[5] = R[0] + 5;  /* 0x800D011C */
    { R[31] = 0x800D0128u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D0120 jal */
    { goto L_800D0214; }  /* 0x800D0128 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D0130 */
    R[2] = R[2] - 1;  /* 0x800D0138 */
    sh_(R[17] + 582, R[2]);  /* 0x800D013C */
    R[2] = R[2] << 16;  /* 0x800D0140 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800D0174; } }  /* 0x800D0144 */
    R[3] = 0x8014u << 16;  /* 0x800D014C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0150 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D0154 */
    R[2] = R[2] - 1;  /* 0x800D015C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D0214; } }  /* 0x800D0160 */
    R[2] = 0x8013u << 16;  /* 0x800D0168 */
    { sh_(R[2] + -29614, R[0]); goto L_800D0214; }  /* 0x800D016C j */
L_800D0174:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D0174 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D01D0; } }  /* 0x800D017C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0184 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0188 */
    R[2] = R[2] - R[3];  /* 0x800D0190 */
    sw_(R[17] + 604, R[2]);  /* 0x800D0194 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0198 */
    sb_(R[16] + 52, R[2]);  /* 0x800D019C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01A0 */
    sb_(R[16] + 53, R[2]);  /* 0x800D01A8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800D01AC */
    { R[31] = 0x800D01B8u; R[4] = R[16] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800D01B0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01B8 */
    R[3] = R[2] + R[0];  /* 0x800D01C0 */
    sh_(R[17] + 60, R[2]);  /* 0x800D01C4 */
    { sh_(R[17] + 62, R[3]); goto L_800D0214; }  /* 0x800D01C8 j */
L_800D01D0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D0214; } }  /* 0x800D01D0 */
    R[6] = R[0] + 1;  /* 0x800D01D8 */
    R[4] = 0x8014u << 16;  /* 0x800D01DC */
    R[2] = lb_(R[17] + 585);  /* 0x800D01E0 */
    R[4] = R[4] + 15136;  /* 0x800D01E4 */
    R[2] = R[2] << 2;  /* 0x800D01E8 */
    { R[31] = 0x800D01F4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D01EC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D0200; } }  /* 0x800D01F4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D01FC */
L_800D0200:;
    { R[31] = 0x800D0208u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800D0200 jal */
    R[5] = lw_(R[17] + 588);  /* 0x800D0208 */
    { R[31] = 0x800D0214u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D020C jal */
L_800D0214:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800CFFB0(void) {
    R[18] = R[2] + R[0];  /* 0x800CFFB0 */
    { uint32_t _c = ((int32_t)R[18] <= 0); if (_c) { goto L_800D0034; } }  /* 0x800CFFB4 */
    R[4] = lw_(R[16]);  /* 0x800CFFBC */
    { R[31] = 0x800CFFC8u; psx_next = 0x800D0CC4u; return; }  /* 0x800CFFC0 jal */
    { uint32_t _c = ((int32_t)R[2] < 0); if (_c) { goto L_800D0034; } }  /* 0x800CFFC8 */
    { R[31] = 0x800CFFD8u; R[4] = R[0] + 59; psx_next = 0x8002DB10u; return; }  /* 0x800CFFD0 jal */
    R[2] = R[0] + 1;  /* 0x800CFFD8 */
    R[5] = 0x800Fu << 16;  /* 0x800CFFDC */
    sb_(R[17] + 584, R[2]);  /* 0x800CFFE0 */
    R[4] = lw_(R[16]);  /* 0x800CFFE4 */
    R[6] = lb_(R[17] + 585);  /* 0x800CFFE8 */
    { R[31] = 0x800CFFF4u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CFFEC jal */
    R[3] = lw_(R[16]);  /* 0x800CFFF4 */
    R[2] = lb_(R[3] + 789);  /* 0x800CFFFC */
    R[2] = R[2] | 0x2;  /* 0x800D0004 */
    sb_(R[3] + 789, R[2]);  /* 0x800D0008 */
    R[3] = lw_(R[16]);  /* 0x800D000C */
    R[2] = R[0] + 150;  /* 0x800D0010 */
    sw_(R[17] + 608, R[18]);  /* 0x800D0014 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0018 */
    { sw_(R[17] + 588, R[3]); goto L_800D0058; }  /* 0x800D001C j */
    R[2] = lb_(R[17] + 785);  /* 0x800D0024 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_800D006C; } }  /* 0x800D002C */
L_800D0034:;
    R[16] = R[0] + 8;  /* 0x800D0034 */
    R[4] = R[17] + R[0];  /* 0x800D0038 */
    R[5] = 0x800Fu << 16;  /* 0x800D003C */
    R[5] = R[5] - 372;  /* 0x800D0040 */
    R[6] = R[16] + R[0];  /* 0x800D0044 */
    R[2] = R[0] + 2;  /* 0x800D0048 */
    { R[31] = 0x800D0054u; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800D004C jal */
    sh_(R[17] + 582, R[16]);  /* 0x800D0054 */
L_800D0058:;
    R[2] = R[0] + 3;  /* 0x800D0058 */
    sb_(R[17] + 786, R[2]);  /* 0x800D005C */
    R[2] = R[0] + 4;  /* 0x800D0060 */
    { sb_(R[17] + 790, R[2]); goto L_800D0214; }  /* 0x800D0064 j */
L_800D006C:;
    sb_(R[16] + 3, R[2]);  /* 0x800D006C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0070 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0074 */
    R[2] = R[2] - R[3];  /* 0x800D007C */
    sw_(R[17] + 604, R[2]);  /* 0x800D0080 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0084 */
    sb_(R[16] + 52, R[2]);  /* 0x800D0088 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D008C */
    sb_(R[16] + 53, R[2]);  /* 0x800D0094 */
    R[2] = lh_(R[17] + 582);  /* 0x800D0098 */
    R[2] = R[2] & 0x3;  /* 0x800D00A0 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] + 8; if (_c) { goto L_800D00EC; } }  /* 0x800D00A4 */
    R[3] = lb_(R[17] + 585);  /* 0x800D00AC */
    R[5] = R[0] + 15;  /* 0x800D00B0 */
    R[4] = 0x8014u << 16;  /* 0x800D00B4 */
    R[4] = R[4] + 15160;  /* 0x800D00B8 */
    R[2] = R[3] << 3;  /* 0x800D00BC */
    R[2] = R[2] + R[3];  /* 0x800D00C0 */
    R[2] = R[2] << 7;  /* 0x800D00C4 */
    { R[31] = 0x800D00D0u; R[4] = R[2] + R[4]; psx_next = 0x800BDFDCu; return; }  /* 0x800D00C8 jal */
    R[4] = R[2] + R[0];  /* 0x800D00D0 */
    R[5] = R[17] + 24;  /* 0x800D00D4 */
    R[6] = R[0] + 25;  /* 0x800D00D8 */
    R[7] = 0x800Fu << 16;  /* 0x800D00DC */
    { R[31] = 0x800D00E8u; R[7] = R[7] - 372; psx_next = 0x800CDD84u; return; }  /* 0x800D00E0 jal */
    R[5] = R[0] + 8;  /* 0x800D00E8 */
L_800D00EC:;
    R[3] = lb_(R[17] + 585);  /* 0x800D00EC */
    R[6] = R[0] + 16384;  /* 0x800D00F0 */
    R[4] = 0x8014u << 16;  /* 0x800D00F4 */
    R[4] = R[4] + 15160;  /* 0x800D00F8 */
    R[2] = R[3] << 3;  /* 0x800D00FC */
    R[2] = R[2] + R[3];  /* 0x800D0100 */
    R[2] = R[2] << 7;  /* 0x800D0104 */
    { R[31] = 0x800D0110u; R[4] = R[2] + R[4]; psx_next = 0x800CDE50u; return; }  /* 0x800D0108 jal */
    { R[31] = 0x800D0118u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D0110 jal */
    R[4] = R[17] + R[0];  /* 0x800D0118 */
    R[5] = R[0] + 5;  /* 0x800D011C */
    { R[31] = 0x800D0128u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D0120 jal */
    { goto L_800D0214; }  /* 0x800D0128 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D0130 */
    R[2] = R[2] - 1;  /* 0x800D0138 */
    sh_(R[17] + 582, R[2]);  /* 0x800D013C */
    R[2] = R[2] << 16;  /* 0x800D0140 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800D0174; } }  /* 0x800D0144 */
    R[3] = 0x8014u << 16;  /* 0x800D014C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0150 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D0154 */
    R[2] = R[2] - 1;  /* 0x800D015C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D0214; } }  /* 0x800D0160 */
    R[2] = 0x8013u << 16;  /* 0x800D0168 */
    { sh_(R[2] + -29614, R[0]); goto L_800D0214; }  /* 0x800D016C j */
L_800D0174:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D0174 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D01D0; } }  /* 0x800D017C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0184 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0188 */
    R[2] = R[2] - R[3];  /* 0x800D0190 */
    sw_(R[17] + 604, R[2]);  /* 0x800D0194 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0198 */
    sb_(R[16] + 52, R[2]);  /* 0x800D019C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01A0 */
    sb_(R[16] + 53, R[2]);  /* 0x800D01A8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800D01AC */
    { R[31] = 0x800D01B8u; R[4] = R[16] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800D01B0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01B8 */
    R[3] = R[2] + R[0];  /* 0x800D01C0 */
    sh_(R[17] + 60, R[2]);  /* 0x800D01C4 */
    { sh_(R[17] + 62, R[3]); goto L_800D0214; }  /* 0x800D01C8 j */
L_800D01D0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D0214; } }  /* 0x800D01D0 */
    R[6] = R[0] + 1;  /* 0x800D01D8 */
    R[4] = 0x8014u << 16;  /* 0x800D01DC */
    R[2] = lb_(R[17] + 585);  /* 0x800D01E0 */
    R[4] = R[4] + 15136;  /* 0x800D01E4 */
    R[2] = R[2] << 2;  /* 0x800D01E8 */
    { R[31] = 0x800D01F4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D01EC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D0200; } }  /* 0x800D01F4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D01FC */
L_800D0200:;
    { R[31] = 0x800D0208u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800D0200 jal */
    R[5] = lw_(R[17] + 588);  /* 0x800D0208 */
    { R[31] = 0x800D0214u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D020C jal */
L_800D0214:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800CFFC8(void) {
    { uint32_t _c = ((int32_t)R[2] < 0); if (_c) { goto L_800D0034; } }  /* 0x800CFFC8 */
    { R[31] = 0x800CFFD8u; R[4] = R[0] + 59; psx_next = 0x8002DB10u; return; }  /* 0x800CFFD0 jal */
    R[2] = R[0] + 1;  /* 0x800CFFD8 */
    R[5] = 0x800Fu << 16;  /* 0x800CFFDC */
    sb_(R[17] + 584, R[2]);  /* 0x800CFFE0 */
    R[4] = lw_(R[16]);  /* 0x800CFFE4 */
    R[6] = lb_(R[17] + 585);  /* 0x800CFFE8 */
    { R[31] = 0x800CFFF4u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CFFEC jal */
    R[3] = lw_(R[16]);  /* 0x800CFFF4 */
    R[2] = lb_(R[3] + 789);  /* 0x800CFFFC */
    R[2] = R[2] | 0x2;  /* 0x800D0004 */
    sb_(R[3] + 789, R[2]);  /* 0x800D0008 */
    R[3] = lw_(R[16]);  /* 0x800D000C */
    R[2] = R[0] + 150;  /* 0x800D0010 */
    sw_(R[17] + 608, R[18]);  /* 0x800D0014 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0018 */
    { sw_(R[17] + 588, R[3]); goto L_800D0058; }  /* 0x800D001C j */
    R[2] = lb_(R[17] + 785);  /* 0x800D0024 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_800D006C; } }  /* 0x800D002C */
L_800D0034:;
    R[16] = R[0] + 8;  /* 0x800D0034 */
    R[4] = R[17] + R[0];  /* 0x800D0038 */
    R[5] = 0x800Fu << 16;  /* 0x800D003C */
    R[5] = R[5] - 372;  /* 0x800D0040 */
    R[6] = R[16] + R[0];  /* 0x800D0044 */
    R[2] = R[0] + 2;  /* 0x800D0048 */
    { R[31] = 0x800D0054u; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800D004C jal */
    sh_(R[17] + 582, R[16]);  /* 0x800D0054 */
L_800D0058:;
    R[2] = R[0] + 3;  /* 0x800D0058 */
    sb_(R[17] + 786, R[2]);  /* 0x800D005C */
    R[2] = R[0] + 4;  /* 0x800D0060 */
    { sb_(R[17] + 790, R[2]); goto L_800D0214; }  /* 0x800D0064 j */
L_800D006C:;
    sb_(R[16] + 3, R[2]);  /* 0x800D006C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0070 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0074 */
    R[2] = R[2] - R[3];  /* 0x800D007C */
    sw_(R[17] + 604, R[2]);  /* 0x800D0080 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0084 */
    sb_(R[16] + 52, R[2]);  /* 0x800D0088 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D008C */
    sb_(R[16] + 53, R[2]);  /* 0x800D0094 */
    R[2] = lh_(R[17] + 582);  /* 0x800D0098 */
    R[2] = R[2] & 0x3;  /* 0x800D00A0 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] + 8; if (_c) { goto L_800D00EC; } }  /* 0x800D00A4 */
    R[3] = lb_(R[17] + 585);  /* 0x800D00AC */
    R[5] = R[0] + 15;  /* 0x800D00B0 */
    R[4] = 0x8014u << 16;  /* 0x800D00B4 */
    R[4] = R[4] + 15160;  /* 0x800D00B8 */
    R[2] = R[3] << 3;  /* 0x800D00BC */
    R[2] = R[2] + R[3];  /* 0x800D00C0 */
    R[2] = R[2] << 7;  /* 0x800D00C4 */
    { R[31] = 0x800D00D0u; R[4] = R[2] + R[4]; psx_next = 0x800BDFDCu; return; }  /* 0x800D00C8 jal */
    R[4] = R[2] + R[0];  /* 0x800D00D0 */
    R[5] = R[17] + 24;  /* 0x800D00D4 */
    R[6] = R[0] + 25;  /* 0x800D00D8 */
    R[7] = 0x800Fu << 16;  /* 0x800D00DC */
    { R[31] = 0x800D00E8u; R[7] = R[7] - 372; psx_next = 0x800CDD84u; return; }  /* 0x800D00E0 jal */
    R[5] = R[0] + 8;  /* 0x800D00E8 */
L_800D00EC:;
    R[3] = lb_(R[17] + 585);  /* 0x800D00EC */
    R[6] = R[0] + 16384;  /* 0x800D00F0 */
    R[4] = 0x8014u << 16;  /* 0x800D00F4 */
    R[4] = R[4] + 15160;  /* 0x800D00F8 */
    R[2] = R[3] << 3;  /* 0x800D00FC */
    R[2] = R[2] + R[3];  /* 0x800D0100 */
    R[2] = R[2] << 7;  /* 0x800D0104 */
    { R[31] = 0x800D0110u; R[4] = R[2] + R[4]; psx_next = 0x800CDE50u; return; }  /* 0x800D0108 jal */
    { R[31] = 0x800D0118u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D0110 jal */
    R[4] = R[17] + R[0];  /* 0x800D0118 */
    R[5] = R[0] + 5;  /* 0x800D011C */
    { R[31] = 0x800D0128u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D0120 jal */
    { goto L_800D0214; }  /* 0x800D0128 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D0130 */
    R[2] = R[2] - 1;  /* 0x800D0138 */
    sh_(R[17] + 582, R[2]);  /* 0x800D013C */
    R[2] = R[2] << 16;  /* 0x800D0140 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800D0174; } }  /* 0x800D0144 */
    R[3] = 0x8014u << 16;  /* 0x800D014C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0150 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D0154 */
    R[2] = R[2] - 1;  /* 0x800D015C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D0214; } }  /* 0x800D0160 */
    R[2] = 0x8013u << 16;  /* 0x800D0168 */
    { sh_(R[2] + -29614, R[0]); goto L_800D0214; }  /* 0x800D016C j */
L_800D0174:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D0174 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D01D0; } }  /* 0x800D017C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0184 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0188 */
    R[2] = R[2] - R[3];  /* 0x800D0190 */
    sw_(R[17] + 604, R[2]);  /* 0x800D0194 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0198 */
    sb_(R[16] + 52, R[2]);  /* 0x800D019C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01A0 */
    sb_(R[16] + 53, R[2]);  /* 0x800D01A8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800D01AC */
    { R[31] = 0x800D01B8u; R[4] = R[16] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800D01B0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01B8 */
    R[3] = R[2] + R[0];  /* 0x800D01C0 */
    sh_(R[17] + 60, R[2]);  /* 0x800D01C4 */
    { sh_(R[17] + 62, R[3]); goto L_800D0214; }  /* 0x800D01C8 j */
L_800D01D0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D0214; } }  /* 0x800D01D0 */
    R[6] = R[0] + 1;  /* 0x800D01D8 */
    R[4] = 0x8014u << 16;  /* 0x800D01DC */
    R[2] = lb_(R[17] + 585);  /* 0x800D01E0 */
    R[4] = R[4] + 15136;  /* 0x800D01E4 */
    R[2] = R[2] << 2;  /* 0x800D01E8 */
    { R[31] = 0x800D01F4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D01EC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D0200; } }  /* 0x800D01F4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D01FC */
L_800D0200:;
    { R[31] = 0x800D0208u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800D0200 jal */
    R[5] = lw_(R[17] + 588);  /* 0x800D0208 */
    { R[31] = 0x800D0214u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D020C jal */
L_800D0214:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800CFFD8(void) {
    R[2] = R[0] + 1;  /* 0x800CFFD8 */
    R[5] = 0x800Fu << 16;  /* 0x800CFFDC */
    sb_(R[17] + 584, R[2]);  /* 0x800CFFE0 */
    R[4] = lw_(R[16]);  /* 0x800CFFE4 */
    R[6] = lb_(R[17] + 585);  /* 0x800CFFE8 */
    { R[31] = 0x800CFFF4u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800CFFEC jal */
    R[3] = lw_(R[16]);  /* 0x800CFFF4 */
    R[2] = lb_(R[3] + 789);  /* 0x800CFFFC */
    R[2] = R[2] | 0x2;  /* 0x800D0004 */
    sb_(R[3] + 789, R[2]);  /* 0x800D0008 */
    R[3] = lw_(R[16]);  /* 0x800D000C */
    R[2] = R[0] + 150;  /* 0x800D0010 */
    sw_(R[17] + 608, R[18]);  /* 0x800D0014 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0018 */
    { sw_(R[17] + 588, R[3]); goto L_800D0058; }  /* 0x800D001C j */
    R[2] = lb_(R[17] + 785);  /* 0x800D0024 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_800D006C; } }  /* 0x800D002C */
    R[16] = R[0] + 8;  /* 0x800D0034 */
    R[4] = R[17] + R[0];  /* 0x800D0038 */
    R[5] = 0x800Fu << 16;  /* 0x800D003C */
    R[5] = R[5] - 372;  /* 0x800D0040 */
    R[6] = R[16] + R[0];  /* 0x800D0044 */
    R[2] = R[0] + 2;  /* 0x800D0048 */
    { R[31] = 0x800D0054u; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800D004C jal */
    sh_(R[17] + 582, R[16]);  /* 0x800D0054 */
L_800D0058:;
    R[2] = R[0] + 3;  /* 0x800D0058 */
    sb_(R[17] + 786, R[2]);  /* 0x800D005C */
    R[2] = R[0] + 4;  /* 0x800D0060 */
    { sb_(R[17] + 790, R[2]); goto L_800D0214; }  /* 0x800D0064 j */
L_800D006C:;
    sb_(R[16] + 3, R[2]);  /* 0x800D006C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0070 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0074 */
    R[2] = R[2] - R[3];  /* 0x800D007C */
    sw_(R[17] + 604, R[2]);  /* 0x800D0080 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0084 */
    sb_(R[16] + 52, R[2]);  /* 0x800D0088 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D008C */
    sb_(R[16] + 53, R[2]);  /* 0x800D0094 */
    R[2] = lh_(R[17] + 582);  /* 0x800D0098 */
    R[2] = R[2] & 0x3;  /* 0x800D00A0 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] + 8; if (_c) { goto L_800D00EC; } }  /* 0x800D00A4 */
    R[3] = lb_(R[17] + 585);  /* 0x800D00AC */
    R[5] = R[0] + 15;  /* 0x800D00B0 */
    R[4] = 0x8014u << 16;  /* 0x800D00B4 */
    R[4] = R[4] + 15160;  /* 0x800D00B8 */
    R[2] = R[3] << 3;  /* 0x800D00BC */
    R[2] = R[2] + R[3];  /* 0x800D00C0 */
    R[2] = R[2] << 7;  /* 0x800D00C4 */
    { R[31] = 0x800D00D0u; R[4] = R[2] + R[4]; psx_next = 0x800BDFDCu; return; }  /* 0x800D00C8 jal */
    R[4] = R[2] + R[0];  /* 0x800D00D0 */
    R[5] = R[17] + 24;  /* 0x800D00D4 */
    R[6] = R[0] + 25;  /* 0x800D00D8 */
    R[7] = 0x800Fu << 16;  /* 0x800D00DC */
    { R[31] = 0x800D00E8u; R[7] = R[7] - 372; psx_next = 0x800CDD84u; return; }  /* 0x800D00E0 jal */
    R[5] = R[0] + 8;  /* 0x800D00E8 */
L_800D00EC:;
    R[3] = lb_(R[17] + 585);  /* 0x800D00EC */
    R[6] = R[0] + 16384;  /* 0x800D00F0 */
    R[4] = 0x8014u << 16;  /* 0x800D00F4 */
    R[4] = R[4] + 15160;  /* 0x800D00F8 */
    R[2] = R[3] << 3;  /* 0x800D00FC */
    R[2] = R[2] + R[3];  /* 0x800D0100 */
    R[2] = R[2] << 7;  /* 0x800D0104 */
    { R[31] = 0x800D0110u; R[4] = R[2] + R[4]; psx_next = 0x800CDE50u; return; }  /* 0x800D0108 jal */
    { R[31] = 0x800D0118u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D0110 jal */
    R[4] = R[17] + R[0];  /* 0x800D0118 */
    R[5] = R[0] + 5;  /* 0x800D011C */
    { R[31] = 0x800D0128u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D0120 jal */
    { goto L_800D0214; }  /* 0x800D0128 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D0130 */
    R[2] = R[2] - 1;  /* 0x800D0138 */
    sh_(R[17] + 582, R[2]);  /* 0x800D013C */
    R[2] = R[2] << 16;  /* 0x800D0140 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800D0174; } }  /* 0x800D0144 */
    R[3] = 0x8014u << 16;  /* 0x800D014C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0150 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D0154 */
    R[2] = R[2] - 1;  /* 0x800D015C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D0214; } }  /* 0x800D0160 */
    R[2] = 0x8013u << 16;  /* 0x800D0168 */
    { sh_(R[2] + -29614, R[0]); goto L_800D0214; }  /* 0x800D016C j */
L_800D0174:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D0174 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D01D0; } }  /* 0x800D017C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0184 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0188 */
    R[2] = R[2] - R[3];  /* 0x800D0190 */
    sw_(R[17] + 604, R[2]);  /* 0x800D0194 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0198 */
    sb_(R[16] + 52, R[2]);  /* 0x800D019C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01A0 */
    sb_(R[16] + 53, R[2]);  /* 0x800D01A8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800D01AC */
    { R[31] = 0x800D01B8u; R[4] = R[16] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800D01B0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01B8 */
    R[3] = R[2] + R[0];  /* 0x800D01C0 */
    sh_(R[17] + 60, R[2]);  /* 0x800D01C4 */
    { sh_(R[17] + 62, R[3]); goto L_800D0214; }  /* 0x800D01C8 j */
L_800D01D0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D0214; } }  /* 0x800D01D0 */
    R[6] = R[0] + 1;  /* 0x800D01D8 */
    R[4] = 0x8014u << 16;  /* 0x800D01DC */
    R[2] = lb_(R[17] + 585);  /* 0x800D01E0 */
    R[4] = R[4] + 15136;  /* 0x800D01E4 */
    R[2] = R[2] << 2;  /* 0x800D01E8 */
    { R[31] = 0x800D01F4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D01EC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D0200; } }  /* 0x800D01F4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D01FC */
L_800D0200:;
    { R[31] = 0x800D0208u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800D0200 jal */
    R[5] = lw_(R[17] + 588);  /* 0x800D0208 */
    { R[31] = 0x800D0214u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D020C jal */
L_800D0214:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800CFFF4(void) {
    R[3] = lw_(R[16]);  /* 0x800CFFF4 */
    R[2] = lb_(R[3] + 789);  /* 0x800CFFFC */
    R[2] = R[2] | 0x2;  /* 0x800D0004 */
    sb_(R[3] + 789, R[2]);  /* 0x800D0008 */
    R[3] = lw_(R[16]);  /* 0x800D000C */
    R[2] = R[0] + 150;  /* 0x800D0010 */
    sw_(R[17] + 608, R[18]);  /* 0x800D0014 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0018 */
    { sw_(R[17] + 588, R[3]); goto L_800D0058; }  /* 0x800D001C j */
    R[2] = lb_(R[17] + 785);  /* 0x800D0024 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_800D006C; } }  /* 0x800D002C */
    R[16] = R[0] + 8;  /* 0x800D0034 */
    R[4] = R[17] + R[0];  /* 0x800D0038 */
    R[5] = 0x800Fu << 16;  /* 0x800D003C */
    R[5] = R[5] - 372;  /* 0x800D0040 */
    R[6] = R[16] + R[0];  /* 0x800D0044 */
    R[2] = R[0] + 2;  /* 0x800D0048 */
    { R[31] = 0x800D0054u; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800D004C jal */
    sh_(R[17] + 582, R[16]);  /* 0x800D0054 */
L_800D0058:;
    R[2] = R[0] + 3;  /* 0x800D0058 */
    sb_(R[17] + 786, R[2]);  /* 0x800D005C */
    R[2] = R[0] + 4;  /* 0x800D0060 */
    { sb_(R[17] + 790, R[2]); goto L_800D0214; }  /* 0x800D0064 j */
L_800D006C:;
    sb_(R[16] + 3, R[2]);  /* 0x800D006C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0070 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0074 */
    R[2] = R[2] - R[3];  /* 0x800D007C */
    sw_(R[17] + 604, R[2]);  /* 0x800D0080 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0084 */
    sb_(R[16] + 52, R[2]);  /* 0x800D0088 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D008C */
    sb_(R[16] + 53, R[2]);  /* 0x800D0094 */
    R[2] = lh_(R[17] + 582);  /* 0x800D0098 */
    R[2] = R[2] & 0x3;  /* 0x800D00A0 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] + 8; if (_c) { goto L_800D00EC; } }  /* 0x800D00A4 */
    R[3] = lb_(R[17] + 585);  /* 0x800D00AC */
    R[5] = R[0] + 15;  /* 0x800D00B0 */
    R[4] = 0x8014u << 16;  /* 0x800D00B4 */
    R[4] = R[4] + 15160;  /* 0x800D00B8 */
    R[2] = R[3] << 3;  /* 0x800D00BC */
    R[2] = R[2] + R[3];  /* 0x800D00C0 */
    R[2] = R[2] << 7;  /* 0x800D00C4 */
    { R[31] = 0x800D00D0u; R[4] = R[2] + R[4]; psx_next = 0x800BDFDCu; return; }  /* 0x800D00C8 jal */
    R[4] = R[2] + R[0];  /* 0x800D00D0 */
    R[5] = R[17] + 24;  /* 0x800D00D4 */
    R[6] = R[0] + 25;  /* 0x800D00D8 */
    R[7] = 0x800Fu << 16;  /* 0x800D00DC */
    { R[31] = 0x800D00E8u; R[7] = R[7] - 372; psx_next = 0x800CDD84u; return; }  /* 0x800D00E0 jal */
    R[5] = R[0] + 8;  /* 0x800D00E8 */
L_800D00EC:;
    R[3] = lb_(R[17] + 585);  /* 0x800D00EC */
    R[6] = R[0] + 16384;  /* 0x800D00F0 */
    R[4] = 0x8014u << 16;  /* 0x800D00F4 */
    R[4] = R[4] + 15160;  /* 0x800D00F8 */
    R[2] = R[3] << 3;  /* 0x800D00FC */
    R[2] = R[2] + R[3];  /* 0x800D0100 */
    R[2] = R[2] << 7;  /* 0x800D0104 */
    { R[31] = 0x800D0110u; R[4] = R[2] + R[4]; psx_next = 0x800CDE50u; return; }  /* 0x800D0108 jal */
    { R[31] = 0x800D0118u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D0110 jal */
    R[4] = R[17] + R[0];  /* 0x800D0118 */
    R[5] = R[0] + 5;  /* 0x800D011C */
    { R[31] = 0x800D0128u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D0120 jal */
    { goto L_800D0214; }  /* 0x800D0128 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D0130 */
    R[2] = R[2] - 1;  /* 0x800D0138 */
    sh_(R[17] + 582, R[2]);  /* 0x800D013C */
    R[2] = R[2] << 16;  /* 0x800D0140 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800D0174; } }  /* 0x800D0144 */
    R[3] = 0x8014u << 16;  /* 0x800D014C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0150 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D0154 */
    R[2] = R[2] - 1;  /* 0x800D015C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D0214; } }  /* 0x800D0160 */
    R[2] = 0x8013u << 16;  /* 0x800D0168 */
    { sh_(R[2] + -29614, R[0]); goto L_800D0214; }  /* 0x800D016C j */
L_800D0174:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D0174 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D01D0; } }  /* 0x800D017C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0184 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0188 */
    R[2] = R[2] - R[3];  /* 0x800D0190 */
    sw_(R[17] + 604, R[2]);  /* 0x800D0194 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0198 */
    sb_(R[16] + 52, R[2]);  /* 0x800D019C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01A0 */
    sb_(R[16] + 53, R[2]);  /* 0x800D01A8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800D01AC */
    { R[31] = 0x800D01B8u; R[4] = R[16] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800D01B0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01B8 */
    R[3] = R[2] + R[0];  /* 0x800D01C0 */
    sh_(R[17] + 60, R[2]);  /* 0x800D01C4 */
    { sh_(R[17] + 62, R[3]); goto L_800D0214; }  /* 0x800D01C8 j */
L_800D01D0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D0214; } }  /* 0x800D01D0 */
    R[6] = R[0] + 1;  /* 0x800D01D8 */
    R[4] = 0x8014u << 16;  /* 0x800D01DC */
    R[2] = lb_(R[17] + 585);  /* 0x800D01E0 */
    R[4] = R[4] + 15136;  /* 0x800D01E4 */
    R[2] = R[2] << 2;  /* 0x800D01E8 */
    { R[31] = 0x800D01F4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D01EC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D0200; } }  /* 0x800D01F4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D01FC */
L_800D0200:;
    { R[31] = 0x800D0208u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800D0200 jal */
    R[5] = lw_(R[17] + 588);  /* 0x800D0208 */
    { R[31] = 0x800D0214u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D020C jal */
L_800D0214:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800D0010(void) {
    R[2] = R[0] + 150;  /* 0x800D0010 */
    sw_(R[17] + 608, R[18]);  /* 0x800D0014 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0018 */
    { sw_(R[17] + 588, R[3]); goto L_800D0058; }  /* 0x800D001C j */
    R[2] = lb_(R[17] + 785);  /* 0x800D0024 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_800D006C; } }  /* 0x800D002C */
    R[16] = R[0] + 8;  /* 0x800D0034 */
    R[4] = R[17] + R[0];  /* 0x800D0038 */
    R[5] = 0x800Fu << 16;  /* 0x800D003C */
    R[5] = R[5] - 372;  /* 0x800D0040 */
    R[6] = R[16] + R[0];  /* 0x800D0044 */
    R[2] = R[0] + 2;  /* 0x800D0048 */
    { R[31] = 0x800D0054u; sb_(R[17] + 584, R[2]); psx_next = 0x800CDECCu; return; }  /* 0x800D004C jal */
    sh_(R[17] + 582, R[16]);  /* 0x800D0054 */
L_800D0058:;
    R[2] = R[0] + 3;  /* 0x800D0058 */
    sb_(R[17] + 786, R[2]);  /* 0x800D005C */
    R[2] = R[0] + 4;  /* 0x800D0060 */
    { sb_(R[17] + 790, R[2]); goto L_800D0214; }  /* 0x800D0064 j */
L_800D006C:;
    sb_(R[16] + 3, R[2]);  /* 0x800D006C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0070 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0074 */
    R[2] = R[2] - R[3];  /* 0x800D007C */
    sw_(R[17] + 604, R[2]);  /* 0x800D0080 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0084 */
    sb_(R[16] + 52, R[2]);  /* 0x800D0088 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D008C */
    sb_(R[16] + 53, R[2]);  /* 0x800D0094 */
    R[2] = lh_(R[17] + 582);  /* 0x800D0098 */
    R[2] = R[2] & 0x3;  /* 0x800D00A0 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] + 8; if (_c) { goto L_800D00EC; } }  /* 0x800D00A4 */
    R[3] = lb_(R[17] + 585);  /* 0x800D00AC */
    R[5] = R[0] + 15;  /* 0x800D00B0 */
    R[4] = 0x8014u << 16;  /* 0x800D00B4 */
    R[4] = R[4] + 15160;  /* 0x800D00B8 */
    R[2] = R[3] << 3;  /* 0x800D00BC */
    R[2] = R[2] + R[3];  /* 0x800D00C0 */
    R[2] = R[2] << 7;  /* 0x800D00C4 */
    { R[31] = 0x800D00D0u; R[4] = R[2] + R[4]; psx_next = 0x800BDFDCu; return; }  /* 0x800D00C8 jal */
    R[4] = R[2] + R[0];  /* 0x800D00D0 */
    R[5] = R[17] + 24;  /* 0x800D00D4 */
    R[6] = R[0] + 25;  /* 0x800D00D8 */
    R[7] = 0x800Fu << 16;  /* 0x800D00DC */
    { R[31] = 0x800D00E8u; R[7] = R[7] - 372; psx_next = 0x800CDD84u; return; }  /* 0x800D00E0 jal */
    R[5] = R[0] + 8;  /* 0x800D00E8 */
L_800D00EC:;
    R[3] = lb_(R[17] + 585);  /* 0x800D00EC */
    R[6] = R[0] + 16384;  /* 0x800D00F0 */
    R[4] = 0x8014u << 16;  /* 0x800D00F4 */
    R[4] = R[4] + 15160;  /* 0x800D00F8 */
    R[2] = R[3] << 3;  /* 0x800D00FC */
    R[2] = R[2] + R[3];  /* 0x800D0100 */
    R[2] = R[2] << 7;  /* 0x800D0104 */
    { R[31] = 0x800D0110u; R[4] = R[2] + R[4]; psx_next = 0x800CDE50u; return; }  /* 0x800D0108 jal */
    { R[31] = 0x800D0118u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D0110 jal */
    R[4] = R[17] + R[0];  /* 0x800D0118 */
    R[5] = R[0] + 5;  /* 0x800D011C */
    { R[31] = 0x800D0128u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D0120 jal */
    { goto L_800D0214; }  /* 0x800D0128 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D0130 */
    R[2] = R[2] - 1;  /* 0x800D0138 */
    sh_(R[17] + 582, R[2]);  /* 0x800D013C */
    R[2] = R[2] << 16;  /* 0x800D0140 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800D0174; } }  /* 0x800D0144 */
    R[3] = 0x8014u << 16;  /* 0x800D014C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0150 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D0154 */
    R[2] = R[2] - 1;  /* 0x800D015C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D0214; } }  /* 0x800D0160 */
    R[2] = 0x8013u << 16;  /* 0x800D0168 */
    { sh_(R[2] + -29614, R[0]); goto L_800D0214; }  /* 0x800D016C j */
L_800D0174:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D0174 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D01D0; } }  /* 0x800D017C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0184 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0188 */
    R[2] = R[2] - R[3];  /* 0x800D0190 */
    sw_(R[17] + 604, R[2]);  /* 0x800D0194 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0198 */
    sb_(R[16] + 52, R[2]);  /* 0x800D019C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01A0 */
    sb_(R[16] + 53, R[2]);  /* 0x800D01A8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800D01AC */
    { R[31] = 0x800D01B8u; R[4] = R[16] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800D01B0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01B8 */
    R[3] = R[2] + R[0];  /* 0x800D01C0 */
    sh_(R[17] + 60, R[2]);  /* 0x800D01C4 */
    { sh_(R[17] + 62, R[3]); goto L_800D0214; }  /* 0x800D01C8 j */
L_800D01D0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D0214; } }  /* 0x800D01D0 */
    R[6] = R[0] + 1;  /* 0x800D01D8 */
    R[4] = 0x8014u << 16;  /* 0x800D01DC */
    R[2] = lb_(R[17] + 585);  /* 0x800D01E0 */
    R[4] = R[4] + 15136;  /* 0x800D01E4 */
    R[2] = R[2] << 2;  /* 0x800D01E8 */
    { R[31] = 0x800D01F4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D01EC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D0200; } }  /* 0x800D01F4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D01FC */
L_800D0200:;
    { R[31] = 0x800D0208u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800D0200 jal */
    R[5] = lw_(R[17] + 588);  /* 0x800D0208 */
    { R[31] = 0x800D0214u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D020C jal */
L_800D0214:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800D0054(void) {
    sh_(R[17] + 582, R[16]);  /* 0x800D0054 */
    R[2] = R[0] + 3;  /* 0x800D0058 */
    sb_(R[17] + 786, R[2]);  /* 0x800D005C */
    R[2] = R[0] + 4;  /* 0x800D0060 */
    { sb_(R[17] + 790, R[2]); goto L_800D0214; }  /* 0x800D0064 j */
    sb_(R[16] + 3, R[2]);  /* 0x800D006C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0070 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0074 */
    R[2] = R[2] - R[3];  /* 0x800D007C */
    sw_(R[17] + 604, R[2]);  /* 0x800D0080 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0084 */
    sb_(R[16] + 52, R[2]);  /* 0x800D0088 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D008C */
    sb_(R[16] + 53, R[2]);  /* 0x800D0094 */
    R[2] = lh_(R[17] + 582);  /* 0x800D0098 */
    R[2] = R[2] & 0x3;  /* 0x800D00A0 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] + 8; if (_c) { goto L_800D00EC; } }  /* 0x800D00A4 */
    R[3] = lb_(R[17] + 585);  /* 0x800D00AC */
    R[5] = R[0] + 15;  /* 0x800D00B0 */
    R[4] = 0x8014u << 16;  /* 0x800D00B4 */
    R[4] = R[4] + 15160;  /* 0x800D00B8 */
    R[2] = R[3] << 3;  /* 0x800D00BC */
    R[2] = R[2] + R[3];  /* 0x800D00C0 */
    R[2] = R[2] << 7;  /* 0x800D00C4 */
    { R[31] = 0x800D00D0u; R[4] = R[2] + R[4]; psx_next = 0x800BDFDCu; return; }  /* 0x800D00C8 jal */
    R[4] = R[2] + R[0];  /* 0x800D00D0 */
    R[5] = R[17] + 24;  /* 0x800D00D4 */
    R[6] = R[0] + 25;  /* 0x800D00D8 */
    R[7] = 0x800Fu << 16;  /* 0x800D00DC */
    { R[31] = 0x800D00E8u; R[7] = R[7] - 372; psx_next = 0x800CDD84u; return; }  /* 0x800D00E0 jal */
    R[5] = R[0] + 8;  /* 0x800D00E8 */
L_800D00EC:;
    R[3] = lb_(R[17] + 585);  /* 0x800D00EC */
    R[6] = R[0] + 16384;  /* 0x800D00F0 */
    R[4] = 0x8014u << 16;  /* 0x800D00F4 */
    R[4] = R[4] + 15160;  /* 0x800D00F8 */
    R[2] = R[3] << 3;  /* 0x800D00FC */
    R[2] = R[2] + R[3];  /* 0x800D0100 */
    R[2] = R[2] << 7;  /* 0x800D0104 */
    { R[31] = 0x800D0110u; R[4] = R[2] + R[4]; psx_next = 0x800CDE50u; return; }  /* 0x800D0108 jal */
    { R[31] = 0x800D0118u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D0110 jal */
    R[4] = R[17] + R[0];  /* 0x800D0118 */
    R[5] = R[0] + 5;  /* 0x800D011C */
    { R[31] = 0x800D0128u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D0120 jal */
    { goto L_800D0214; }  /* 0x800D0128 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D0130 */
    R[2] = R[2] - 1;  /* 0x800D0138 */
    sh_(R[17] + 582, R[2]);  /* 0x800D013C */
    R[2] = R[2] << 16;  /* 0x800D0140 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800D0174; } }  /* 0x800D0144 */
    R[3] = 0x8014u << 16;  /* 0x800D014C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0150 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D0154 */
    R[2] = R[2] - 1;  /* 0x800D015C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D0214; } }  /* 0x800D0160 */
    R[2] = 0x8013u << 16;  /* 0x800D0168 */
    { sh_(R[2] + -29614, R[0]); goto L_800D0214; }  /* 0x800D016C j */
L_800D0174:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D0174 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D01D0; } }  /* 0x800D017C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0184 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0188 */
    R[2] = R[2] - R[3];  /* 0x800D0190 */
    sw_(R[17] + 604, R[2]);  /* 0x800D0194 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0198 */
    sb_(R[16] + 52, R[2]);  /* 0x800D019C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01A0 */
    sb_(R[16] + 53, R[2]);  /* 0x800D01A8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800D01AC */
    { R[31] = 0x800D01B8u; R[4] = R[16] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800D01B0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01B8 */
    R[3] = R[2] + R[0];  /* 0x800D01C0 */
    sh_(R[17] + 60, R[2]);  /* 0x800D01C4 */
    { sh_(R[17] + 62, R[3]); goto L_800D0214; }  /* 0x800D01C8 j */
L_800D01D0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D0214; } }  /* 0x800D01D0 */
    R[6] = R[0] + 1;  /* 0x800D01D8 */
    R[4] = 0x8014u << 16;  /* 0x800D01DC */
    R[2] = lb_(R[17] + 585);  /* 0x800D01E0 */
    R[4] = R[4] + 15136;  /* 0x800D01E4 */
    R[2] = R[2] << 2;  /* 0x800D01E8 */
    { R[31] = 0x800D01F4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D01EC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D0200; } }  /* 0x800D01F4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D01FC */
L_800D0200:;
    { R[31] = 0x800D0208u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800D0200 jal */
    R[5] = lw_(R[17] + 588);  /* 0x800D0208 */
    { R[31] = 0x800D0214u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D020C jal */
L_800D0214:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800D0080(void) {
    sw_(R[17] + 604, R[2]);  /* 0x800D0080 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0084 */
    sb_(R[16] + 52, R[2]);  /* 0x800D0088 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D008C */
    sb_(R[16] + 53, R[2]);  /* 0x800D0094 */
    R[2] = lh_(R[17] + 582);  /* 0x800D0098 */
    R[2] = R[2] & 0x3;  /* 0x800D00A0 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] + 8; if (_c) { goto L_800D00EC; } }  /* 0x800D00A4 */
    R[3] = lb_(R[17] + 585);  /* 0x800D00AC */
    R[5] = R[0] + 15;  /* 0x800D00B0 */
    R[4] = 0x8014u << 16;  /* 0x800D00B4 */
    R[4] = R[4] + 15160;  /* 0x800D00B8 */
    R[2] = R[3] << 3;  /* 0x800D00BC */
    R[2] = R[2] + R[3];  /* 0x800D00C0 */
    R[2] = R[2] << 7;  /* 0x800D00C4 */
    { R[31] = 0x800D00D0u; R[4] = R[2] + R[4]; psx_next = 0x800BDFDCu; return; }  /* 0x800D00C8 jal */
    R[4] = R[2] + R[0];  /* 0x800D00D0 */
    R[5] = R[17] + 24;  /* 0x800D00D4 */
    R[6] = R[0] + 25;  /* 0x800D00D8 */
    R[7] = 0x800Fu << 16;  /* 0x800D00DC */
    { R[31] = 0x800D00E8u; R[7] = R[7] - 372; psx_next = 0x800CDD84u; return; }  /* 0x800D00E0 jal */
    R[5] = R[0] + 8;  /* 0x800D00E8 */
L_800D00EC:;
    R[3] = lb_(R[17] + 585);  /* 0x800D00EC */
    R[6] = R[0] + 16384;  /* 0x800D00F0 */
    R[4] = 0x8014u << 16;  /* 0x800D00F4 */
    R[4] = R[4] + 15160;  /* 0x800D00F8 */
    R[2] = R[3] << 3;  /* 0x800D00FC */
    R[2] = R[2] + R[3];  /* 0x800D0100 */
    R[2] = R[2] << 7;  /* 0x800D0104 */
    { R[31] = 0x800D0110u; R[4] = R[2] + R[4]; psx_next = 0x800CDE50u; return; }  /* 0x800D0108 jal */
    { R[31] = 0x800D0118u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D0110 jal */
    R[4] = R[17] + R[0];  /* 0x800D0118 */
    R[5] = R[0] + 5;  /* 0x800D011C */
    { R[31] = 0x800D0128u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D0120 jal */
    { goto L_800D0214; }  /* 0x800D0128 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D0130 */
    R[2] = R[2] - 1;  /* 0x800D0138 */
    sh_(R[17] + 582, R[2]);  /* 0x800D013C */
    R[2] = R[2] << 16;  /* 0x800D0140 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800D0174; } }  /* 0x800D0144 */
    R[3] = 0x8014u << 16;  /* 0x800D014C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0150 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D0154 */
    R[2] = R[2] - 1;  /* 0x800D015C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D0214; } }  /* 0x800D0160 */
    R[2] = 0x8013u << 16;  /* 0x800D0168 */
    { sh_(R[2] + -29614, R[0]); goto L_800D0214; }  /* 0x800D016C j */
L_800D0174:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D0174 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D01D0; } }  /* 0x800D017C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0184 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0188 */
    R[2] = R[2] - R[3];  /* 0x800D0190 */
    sw_(R[17] + 604, R[2]);  /* 0x800D0194 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0198 */
    sb_(R[16] + 52, R[2]);  /* 0x800D019C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01A0 */
    sb_(R[16] + 53, R[2]);  /* 0x800D01A8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800D01AC */
    { R[31] = 0x800D01B8u; R[4] = R[16] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800D01B0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01B8 */
    R[3] = R[2] + R[0];  /* 0x800D01C0 */
    sh_(R[17] + 60, R[2]);  /* 0x800D01C4 */
    { sh_(R[17] + 62, R[3]); goto L_800D0214; }  /* 0x800D01C8 j */
L_800D01D0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D0214; } }  /* 0x800D01D0 */
    R[6] = R[0] + 1;  /* 0x800D01D8 */
    R[4] = 0x8014u << 16;  /* 0x800D01DC */
    R[2] = lb_(R[17] + 585);  /* 0x800D01E0 */
    R[4] = R[4] + 15136;  /* 0x800D01E4 */
    R[2] = R[2] << 2;  /* 0x800D01E8 */
    { R[31] = 0x800D01F4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D01EC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D0200; } }  /* 0x800D01F4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D01FC */
L_800D0200:;
    { R[31] = 0x800D0208u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800D0200 jal */
    R[5] = lw_(R[17] + 588);  /* 0x800D0208 */
    { R[31] = 0x800D0214u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D020C jal */
L_800D0214:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800D00D0(void) {
    R[4] = R[2] + R[0];  /* 0x800D00D0 */
    R[5] = R[17] + 24;  /* 0x800D00D4 */
    R[6] = R[0] + 25;  /* 0x800D00D8 */
    R[7] = 0x800Fu << 16;  /* 0x800D00DC */
    { R[31] = 0x800D00E8u; R[7] = R[7] - 372; psx_next = 0x800CDD84u; return; }  /* 0x800D00E0 jal */
    R[5] = R[0] + 8;  /* 0x800D00E8 */
    R[3] = lb_(R[17] + 585);  /* 0x800D00EC */
    R[6] = R[0] + 16384;  /* 0x800D00F0 */
    R[4] = 0x8014u << 16;  /* 0x800D00F4 */
    R[4] = R[4] + 15160;  /* 0x800D00F8 */
    R[2] = R[3] << 3;  /* 0x800D00FC */
    R[2] = R[2] + R[3];  /* 0x800D0100 */
    R[2] = R[2] << 7;  /* 0x800D0104 */
    { R[31] = 0x800D0110u; R[4] = R[2] + R[4]; psx_next = 0x800CDE50u; return; }  /* 0x800D0108 jal */
    { R[31] = 0x800D0118u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D0110 jal */
    R[4] = R[17] + R[0];  /* 0x800D0118 */
    R[5] = R[0] + 5;  /* 0x800D011C */
    { R[31] = 0x800D0128u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D0120 jal */
    { goto L_800D0214; }  /* 0x800D0128 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D0130 */
    R[2] = R[2] - 1;  /* 0x800D0138 */
    sh_(R[17] + 582, R[2]);  /* 0x800D013C */
    R[2] = R[2] << 16;  /* 0x800D0140 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800D0174; } }  /* 0x800D0144 */
    R[3] = 0x8014u << 16;  /* 0x800D014C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0150 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D0154 */
    R[2] = R[2] - 1;  /* 0x800D015C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D0214; } }  /* 0x800D0160 */
    R[2] = 0x8013u << 16;  /* 0x800D0168 */
    { sh_(R[2] + -29614, R[0]); goto L_800D0214; }  /* 0x800D016C j */
L_800D0174:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D0174 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D01D0; } }  /* 0x800D017C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0184 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0188 */
    R[2] = R[2] - R[3];  /* 0x800D0190 */
    sw_(R[17] + 604, R[2]);  /* 0x800D0194 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0198 */
    sb_(R[16] + 52, R[2]);  /* 0x800D019C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01A0 */
    sb_(R[16] + 53, R[2]);  /* 0x800D01A8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800D01AC */
    { R[31] = 0x800D01B8u; R[4] = R[16] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800D01B0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01B8 */
    R[3] = R[2] + R[0];  /* 0x800D01C0 */
    sh_(R[17] + 60, R[2]);  /* 0x800D01C4 */
    { sh_(R[17] + 62, R[3]); goto L_800D0214; }  /* 0x800D01C8 j */
L_800D01D0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D0214; } }  /* 0x800D01D0 */
    R[6] = R[0] + 1;  /* 0x800D01D8 */
    R[4] = 0x8014u << 16;  /* 0x800D01DC */
    R[2] = lb_(R[17] + 585);  /* 0x800D01E0 */
    R[4] = R[4] + 15136;  /* 0x800D01E4 */
    R[2] = R[2] << 2;  /* 0x800D01E8 */
    { R[31] = 0x800D01F4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D01EC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D0200; } }  /* 0x800D01F4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D01FC */
L_800D0200:;
    { R[31] = 0x800D0208u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800D0200 jal */
    R[5] = lw_(R[17] + 588);  /* 0x800D0208 */
    { R[31] = 0x800D0214u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D020C jal */
L_800D0214:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800D00E8(void) {
    R[5] = R[0] + 8;  /* 0x800D00E8 */
    R[3] = lb_(R[17] + 585);  /* 0x800D00EC */
    R[6] = R[0] + 16384;  /* 0x800D00F0 */
    R[4] = 0x8014u << 16;  /* 0x800D00F4 */
    R[4] = R[4] + 15160;  /* 0x800D00F8 */
    R[2] = R[3] << 3;  /* 0x800D00FC */
    R[2] = R[2] + R[3];  /* 0x800D0100 */
    R[2] = R[2] << 7;  /* 0x800D0104 */
    { R[31] = 0x800D0110u; R[4] = R[2] + R[4]; psx_next = 0x800CDE50u; return; }  /* 0x800D0108 jal */
    { R[31] = 0x800D0118u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D0110 jal */
    R[4] = R[17] + R[0];  /* 0x800D0118 */
    R[5] = R[0] + 5;  /* 0x800D011C */
    { R[31] = 0x800D0128u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D0120 jal */
    { goto L_800D0214; }  /* 0x800D0128 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D0130 */
    R[2] = R[2] - 1;  /* 0x800D0138 */
    sh_(R[17] + 582, R[2]);  /* 0x800D013C */
    R[2] = R[2] << 16;  /* 0x800D0140 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800D0174; } }  /* 0x800D0144 */
    R[3] = 0x8014u << 16;  /* 0x800D014C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0150 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D0154 */
    R[2] = R[2] - 1;  /* 0x800D015C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D0214; } }  /* 0x800D0160 */
    R[2] = 0x8013u << 16;  /* 0x800D0168 */
    { sh_(R[2] + -29614, R[0]); goto L_800D0214; }  /* 0x800D016C j */
L_800D0174:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D0174 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D01D0; } }  /* 0x800D017C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0184 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0188 */
    R[2] = R[2] - R[3];  /* 0x800D0190 */
    sw_(R[17] + 604, R[2]);  /* 0x800D0194 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0198 */
    sb_(R[16] + 52, R[2]);  /* 0x800D019C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01A0 */
    sb_(R[16] + 53, R[2]);  /* 0x800D01A8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800D01AC */
    { R[31] = 0x800D01B8u; R[4] = R[16] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800D01B0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01B8 */
    R[3] = R[2] + R[0];  /* 0x800D01C0 */
    sh_(R[17] + 60, R[2]);  /* 0x800D01C4 */
    { sh_(R[17] + 62, R[3]); goto L_800D0214; }  /* 0x800D01C8 j */
L_800D01D0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D0214; } }  /* 0x800D01D0 */
    R[6] = R[0] + 1;  /* 0x800D01D8 */
    R[4] = 0x8014u << 16;  /* 0x800D01DC */
    R[2] = lb_(R[17] + 585);  /* 0x800D01E0 */
    R[4] = R[4] + 15136;  /* 0x800D01E4 */
    R[2] = R[2] << 2;  /* 0x800D01E8 */
    { R[31] = 0x800D01F4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D01EC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D0200; } }  /* 0x800D01F4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D01FC */
L_800D0200:;
    { R[31] = 0x800D0208u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800D0200 jal */
    R[5] = lw_(R[17] + 588);  /* 0x800D0208 */
    { R[31] = 0x800D0214u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D020C jal */
L_800D0214:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800D0110(void) {
    { R[31] = 0x800D0118u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D0110 jal */
    R[4] = R[17] + R[0];  /* 0x800D0118 */
    R[5] = R[0] + 5;  /* 0x800D011C */
    { R[31] = 0x800D0128u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D0120 jal */
    { goto L_800D0214; }  /* 0x800D0128 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D0130 */
    R[2] = R[2] - 1;  /* 0x800D0138 */
    sh_(R[17] + 582, R[2]);  /* 0x800D013C */
    R[2] = R[2] << 16;  /* 0x800D0140 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800D0174; } }  /* 0x800D0144 */
    R[3] = 0x8014u << 16;  /* 0x800D014C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0150 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D0154 */
    R[2] = R[2] - 1;  /* 0x800D015C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D0214; } }  /* 0x800D0160 */
    R[2] = 0x8013u << 16;  /* 0x800D0168 */
    { sh_(R[2] + -29614, R[0]); goto L_800D0214; }  /* 0x800D016C j */
L_800D0174:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D0174 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D01D0; } }  /* 0x800D017C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0184 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0188 */
    R[2] = R[2] - R[3];  /* 0x800D0190 */
    sw_(R[17] + 604, R[2]);  /* 0x800D0194 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0198 */
    sb_(R[16] + 52, R[2]);  /* 0x800D019C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01A0 */
    sb_(R[16] + 53, R[2]);  /* 0x800D01A8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800D01AC */
    { R[31] = 0x800D01B8u; R[4] = R[16] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800D01B0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01B8 */
    R[3] = R[2] + R[0];  /* 0x800D01C0 */
    sh_(R[17] + 60, R[2]);  /* 0x800D01C4 */
    { sh_(R[17] + 62, R[3]); goto L_800D0214; }  /* 0x800D01C8 j */
L_800D01D0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D0214; } }  /* 0x800D01D0 */
    R[6] = R[0] + 1;  /* 0x800D01D8 */
    R[4] = 0x8014u << 16;  /* 0x800D01DC */
    R[2] = lb_(R[17] + 585);  /* 0x800D01E0 */
    R[4] = R[4] + 15136;  /* 0x800D01E4 */
    R[2] = R[2] << 2;  /* 0x800D01E8 */
    { R[31] = 0x800D01F4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D01EC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D0200; } }  /* 0x800D01F4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D01FC */
L_800D0200:;
    { R[31] = 0x800D0208u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800D0200 jal */
    R[5] = lw_(R[17] + 588);  /* 0x800D0208 */
    { R[31] = 0x800D0214u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D020C jal */
L_800D0214:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800D0118(void) {
    R[4] = R[17] + R[0];  /* 0x800D0118 */
    R[5] = R[0] + 5;  /* 0x800D011C */
    { R[31] = 0x800D0128u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D0120 jal */
    { goto L_800D0214; }  /* 0x800D0128 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D0130 */
    R[2] = R[2] - 1;  /* 0x800D0138 */
    sh_(R[17] + 582, R[2]);  /* 0x800D013C */
    R[2] = R[2] << 16;  /* 0x800D0140 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800D0174; } }  /* 0x800D0144 */
    R[3] = 0x8014u << 16;  /* 0x800D014C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0150 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D0154 */
    R[2] = R[2] - 1;  /* 0x800D015C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D0214; } }  /* 0x800D0160 */
    R[2] = 0x8013u << 16;  /* 0x800D0168 */
    { sh_(R[2] + -29614, R[0]); goto L_800D0214; }  /* 0x800D016C j */
L_800D0174:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D0174 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D01D0; } }  /* 0x800D017C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0184 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0188 */
    R[2] = R[2] - R[3];  /* 0x800D0190 */
    sw_(R[17] + 604, R[2]);  /* 0x800D0194 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0198 */
    sb_(R[16] + 52, R[2]);  /* 0x800D019C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01A0 */
    sb_(R[16] + 53, R[2]);  /* 0x800D01A8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800D01AC */
    { R[31] = 0x800D01B8u; R[4] = R[16] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800D01B0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01B8 */
    R[3] = R[2] + R[0];  /* 0x800D01C0 */
    sh_(R[17] + 60, R[2]);  /* 0x800D01C4 */
    { sh_(R[17] + 62, R[3]); goto L_800D0214; }  /* 0x800D01C8 j */
L_800D01D0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D0214; } }  /* 0x800D01D0 */
    R[6] = R[0] + 1;  /* 0x800D01D8 */
    R[4] = 0x8014u << 16;  /* 0x800D01DC */
    R[2] = lb_(R[17] + 585);  /* 0x800D01E0 */
    R[4] = R[4] + 15136;  /* 0x800D01E4 */
    R[2] = R[2] << 2;  /* 0x800D01E8 */
    { R[31] = 0x800D01F4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D01EC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D0200; } }  /* 0x800D01F4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D01FC */
L_800D0200:;
    { R[31] = 0x800D0208u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800D0200 jal */
    R[5] = lw_(R[17] + 588);  /* 0x800D0208 */
    { R[31] = 0x800D0214u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D020C jal */
L_800D0214:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800D0128(void) {
    { goto L_800D0214; }  /* 0x800D0128 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D0130 */
    R[2] = R[2] - 1;  /* 0x800D0138 */
    sh_(R[17] + 582, R[2]);  /* 0x800D013C */
    R[2] = R[2] << 16;  /* 0x800D0140 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[0] + 3; if (_c) { goto L_800D0174; } }  /* 0x800D0144 */
    R[3] = 0x8014u << 16;  /* 0x800D014C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0150 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D0154 */
    R[2] = R[2] - 1;  /* 0x800D015C */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D0214; } }  /* 0x800D0160 */
    R[2] = 0x8013u << 16;  /* 0x800D0168 */
    { sh_(R[2] + -29614, R[0]); goto L_800D0214; }  /* 0x800D016C j */
L_800D0174:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D0174 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D01D0; } }  /* 0x800D017C */
    R[2] = lw_(R[17] + 604);  /* 0x800D0184 */
    R[3] = lw_(R[17] + 600);  /* 0x800D0188 */
    R[2] = R[2] - R[3];  /* 0x800D0190 */
    sw_(R[17] + 604, R[2]);  /* 0x800D0194 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800D0198 */
    sb_(R[16] + 52, R[2]);  /* 0x800D019C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01A0 */
    sb_(R[16] + 53, R[2]);  /* 0x800D01A8 */
    R[5] = (uint32_t)(int16_t)lh_(R[17] + 592);  /* 0x800D01AC */
    { R[31] = 0x800D01B8u; R[4] = R[16] + R[0]; psx_next = 0x800A72F8u; return; }  /* 0x800D01B0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01B8 */
    R[3] = R[2] + R[0];  /* 0x800D01C0 */
    sh_(R[17] + 60, R[2]);  /* 0x800D01C4 */
    { sh_(R[17] + 62, R[3]); goto L_800D0214; }  /* 0x800D01C8 j */
L_800D01D0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D0214; } }  /* 0x800D01D0 */
    R[6] = R[0] + 1;  /* 0x800D01D8 */
    R[4] = 0x8014u << 16;  /* 0x800D01DC */
    R[2] = lb_(R[17] + 585);  /* 0x800D01E0 */
    R[4] = R[4] + 15136;  /* 0x800D01E4 */
    R[2] = R[2] << 2;  /* 0x800D01E8 */
    { R[31] = 0x800D01F4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D01EC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D0200; } }  /* 0x800D01F4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D01FC */
L_800D0200:;
    { R[31] = 0x800D0208u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800D0200 jal */
    R[5] = lw_(R[17] + 588);  /* 0x800D0208 */
    { R[31] = 0x800D0214u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D020C jal */
L_800D0214:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800D01B8(void) {
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 606);  /* 0x800D01B8 */
    R[3] = R[2] + R[0];  /* 0x800D01C0 */
    sh_(R[17] + 60, R[2]);  /* 0x800D01C4 */
    { sh_(R[17] + 62, R[3]); goto L_800D0214; }  /* 0x800D01C8 j */
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D0214; } }  /* 0x800D01D0 */
    R[6] = R[0] + 1;  /* 0x800D01D8 */
    R[4] = 0x8014u << 16;  /* 0x800D01DC */
    R[2] = lb_(R[17] + 585);  /* 0x800D01E0 */
    R[4] = R[4] + 15136;  /* 0x800D01E4 */
    R[2] = R[2] << 2;  /* 0x800D01E8 */
    { R[31] = 0x800D01F4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D01EC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D0200; } }  /* 0x800D01F4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D01FC */
L_800D0200:;
    { R[31] = 0x800D0208u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800D0200 jal */
    R[5] = lw_(R[17] + 588);  /* 0x800D0208 */
    { R[31] = 0x800D0214u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D020C jal */
L_800D0214:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800D01F4(void) {
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D0200; } }  /* 0x800D01F4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D01FC */
L_800D0200:;
    { R[31] = 0x800D0208u; R[4] = R[17] + R[0]; psx_next = 0x800CE118u; return; }  /* 0x800D0200 jal */
    R[5] = lw_(R[17] + 588);  /* 0x800D0208 */
    { R[31] = 0x800D0214u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D020C jal */
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800D0208(void) {
    R[5] = lw_(R[17] + 588);  /* 0x800D0208 */
    { R[31] = 0x800D0214u; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D020C jal */
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800D0214(void) {
    R[31] = lw_(R[29] + 28);  /* 0x800D0214 */
    R[18] = lw_(R[29] + 24);  /* 0x800D0218 */
    R[17] = lw_(R[29] + 20);  /* 0x800D021C */
    R[16] = lw_(R[29] + 16);  /* 0x800D0220 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0224 jr ra */
}

void g0_800D022C(void) {
    R[29] = R[29] - 32;  /* 0x800D022C */
    sw_(R[29] + 24, R[16]);  /* 0x800D0230 */
    R[16] = R[4] + R[0];  /* 0x800D0234 */
    R[2] = R[0] + 2;  /* 0x800D0238 */
    { uint32_t _c = (R[5] == R[2]); sw_(R[29] + 28, R[31]); if (_c) { goto L_800D0338; } }  /* 0x800D023C */
    R[2] = ((int32_t)R[5] < 3);  /* 0x800D0244 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800D0260; } }  /* 0x800D0248 */
    { uint32_t _c = (R[5] == R[0]); if (_c) { goto L_800D0290; } }  /* 0x800D0250 */
    { goto L_800D0380; }  /* 0x800D0258 j */
L_800D0260:;
    R[2] = R[0] + 5;  /* 0x800D0260 */
    { uint32_t _c = (R[5] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800D0380; } }  /* 0x800D0264 */
    sb_(R[16] + 688, R[2]);  /* 0x800D026C */
    sb_(R[16] + 690, R[2]);  /* 0x800D0270 */
    R[2] = 0x800Bu << 16;  /* 0x800D0274 */
    R[2] = R[2] - 4620;  /* 0x800D0278 */
    sw_(R[16] + 232, R[2]);  /* 0x800D027C */
    R[2] = 0x800Fu << 16;  /* 0x800D0280 */
    R[2] = R[2] - 496;  /* 0x800D0284 */
    { sw_(R[16] + 84, R[2]); goto L_800D0380; }  /* 0x800D0288 j */
L_800D0290:;
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 218);  /* 0x800D0290 */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_800D02B8; } }  /* 0x800D0298 */
    R[2] = lb_(R[16] + 784);  /* 0x800D02A0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800D0380; } }  /* 0x800D02A8 */
    { goto L_800D0300; }  /* 0x800D02B0 j */
L_800D02B8:;
    R[2] = lw_(R[16] + 484);  /* 0x800D02B8 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800D02CC; } }  /* 0x800D02C0 */
    R[2] = R[2] + 4095;  /* 0x800D02C8 */
L_800D02CC:;
    R[3] = lw_(R[16] + 492);  /* 0x800D02CC */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800D02D0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[2] << 16; if (_c) { goto L_800D02E0; } }  /* 0x800D02D4 */
    R[3] = R[3] + 4095;  /* 0x800D02DC */
L_800D02E0:;
    R[2] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x800D02E0 */
    R[2] = R[4] | R[2];  /* 0x800D02E4 */
    sw_(R[29] + 16, R[2]);  /* 0x800D02E8 */
    R[5] = lw_(R[16] + 24);  /* 0x800D02EC */
    R[6] = lw_(R[16] + 28);  /* 0x800D02F0 */
    R[7] = lw_(R[16] + 32);  /* 0x800D02F4 */
    { R[31] = 0x800D0300u; R[4] = R[0] + 32; psx_next = 0x800A7290u; return; }  /* 0x800D02F8 jal */
L_800D0300:;
    R[3] = lw_(R[16] + 588);  /* 0x800D0300 */
    R[2] = lb_(R[3] + 789);  /* 0x800D0308 */
    R[2] = R[2] & 0xFD;  /* 0x800D0310 */
    sb_(R[3] + 789, R[2]);  /* 0x800D0314 */
    R[2] = R[0] + 2;  /* 0x800D0318 */
    sb_(R[16] + 786, R[2]);  /* 0x800D031C */
    sb_(R[16] + 790, R[2]);  /* 0x800D0320 */
    R[2] = lw_(R[16] + 16);  /* 0x800D0324 */
    R[3] = R[0] - 17;  /* 0x800D0328 */
    R[2] = R[2] & R[3];  /* 0x800D032C */
    { sw_(R[16] + 16, R[2]); goto L_800D0380; }  /* 0x800D0330 j */
L_800D0338:;
    { R[31] = 0x800D0340u; R[4] = R[16] + R[0]; psx_next = 0x800B1570u; return; }  /* 0x800D0338 jal */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[0] - 897; if (_c) { goto L_800D0380; } }  /* 0x800D0340 */
    R[4] = lw_(R[16] + 588);  /* 0x800D0348 */
    R[2] = lw_(R[4] + 16);  /* 0x800D0350 */
    R[2] = R[2] & R[3];  /* 0x800D0358 */
    sw_(R[4] + 16, R[2]);  /* 0x800D035C */
    R[3] = lw_(R[16] + 588);  /* 0x800D0360 */
    R[2] = lw_(R[3] + 16);  /* 0x800D0368 */
    R[2] = R[2] | 0x80;  /* 0x800D0370 */
    sw_(R[3] + 16, R[2]);  /* 0x800D0374 */
    R[2] = R[0] + 3;  /* 0x800D0378 */
    sb_(R[16] + 790, R[2]);  /* 0x800D037C */
L_800D0380:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0380 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0384 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0388 jr ra */
}

void g0_800D0300(void) {
    R[3] = lw_(R[16] + 588);  /* 0x800D0300 */
    R[2] = lb_(R[3] + 789);  /* 0x800D0308 */
    R[2] = R[2] & 0xFD;  /* 0x800D0310 */
    sb_(R[3] + 789, R[2]);  /* 0x800D0314 */
    R[2] = R[0] + 2;  /* 0x800D0318 */
    sb_(R[16] + 786, R[2]);  /* 0x800D031C */
    sb_(R[16] + 790, R[2]);  /* 0x800D0320 */
    R[2] = lw_(R[16] + 16);  /* 0x800D0324 */
    R[3] = R[0] - 17;  /* 0x800D0328 */
    R[2] = R[2] & R[3];  /* 0x800D032C */
    { sw_(R[16] + 16, R[2]); goto L_800D0380; }  /* 0x800D0330 j */
    { R[31] = 0x800D0340u; R[4] = R[16] + R[0]; psx_next = 0x800B1570u; return; }  /* 0x800D0338 jal */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[0] - 897; if (_c) { goto L_800D0380; } }  /* 0x800D0340 */
    R[4] = lw_(R[16] + 588);  /* 0x800D0348 */
    R[2] = lw_(R[4] + 16);  /* 0x800D0350 */
    R[2] = R[2] & R[3];  /* 0x800D0358 */
    sw_(R[4] + 16, R[2]);  /* 0x800D035C */
    R[3] = lw_(R[16] + 588);  /* 0x800D0360 */
    R[2] = lw_(R[3] + 16);  /* 0x800D0368 */
    R[2] = R[2] | 0x80;  /* 0x800D0370 */
    sw_(R[3] + 16, R[2]);  /* 0x800D0374 */
    R[2] = R[0] + 3;  /* 0x800D0378 */
    sb_(R[16] + 790, R[2]);  /* 0x800D037C */
L_800D0380:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0380 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0384 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0388 jr ra */
}

void g0_800D0340(void) {
    { uint32_t _c = (R[2] == R[0]); R[3] = R[0] - 897; if (_c) { goto L_800D0380; } }  /* 0x800D0340 */
    R[4] = lw_(R[16] + 588);  /* 0x800D0348 */
    R[2] = lw_(R[4] + 16);  /* 0x800D0350 */
    R[2] = R[2] & R[3];  /* 0x800D0358 */
    sw_(R[4] + 16, R[2]);  /* 0x800D035C */
    R[3] = lw_(R[16] + 588);  /* 0x800D0360 */
    R[2] = lw_(R[3] + 16);  /* 0x800D0368 */
    R[2] = R[2] | 0x80;  /* 0x800D0370 */
    sw_(R[3] + 16, R[2]);  /* 0x800D0374 */
    R[2] = R[0] + 3;  /* 0x800D0378 */
    sb_(R[16] + 790, R[2]);  /* 0x800D037C */
L_800D0380:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0380 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0384 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0388 jr ra */
}

void g0_800D0390(void) {
    R[29] = R[29] - 40;  /* 0x800D0390 */
    sw_(R[29] + 28, R[17]);  /* 0x800D0394 */
    R[17] = R[4] + R[0];  /* 0x800D0398 */
    R[2] = R[0] + 2;  /* 0x800D039C */
    sw_(R[29] + 36, R[31]);  /* 0x800D03A0 */
    sw_(R[29] + 32, R[18]);  /* 0x800D03A4 */
    { uint32_t _c = (R[5] == R[2]); sw_(R[29] + 24, R[16]); if (_c) { goto L_800D05FC; } }  /* 0x800D03A8 */
    R[2] = ((int32_t)R[5] < 3);  /* 0x800D03B0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800D03CC; } }  /* 0x800D03B4 */
    { uint32_t _c = (R[5] == R[0]); if (_c) { goto L_800D0420; } }  /* 0x800D03BC */
    { goto L_800D06DC; }  /* 0x800D03C4 j */
L_800D03CC:;
    R[2] = R[0] + 5;  /* 0x800D03CC */
    { uint32_t _c = (R[5] != R[2]); R[5] = 0x800Fu << 16; if (_c) { goto L_800D06DC; } }  /* 0x800D03D0 */
    R[4] = R[17] + R[0];  /* 0x800D03D8 */
    R[5] = R[5] - 396;  /* 0x800D03DC */
    R[2] = R[0] + 1;  /* 0x800D03E0 */
    sb_(R[4] + 688, R[2]);  /* 0x800D03E4 */
    sb_(R[4] + 690, R[2]);  /* 0x800D03E8 */
    R[2] = 0x800Du << 16;  /* 0x800D03EC */
    R[2] = R[2] - 10416;  /* 0x800D03F0 */
    sw_(R[4] + 232, R[2]);  /* 0x800D03F4 */
    R[2] = R[0] + 6400;  /* 0x800D03F8 */
    sw_(R[4] + 124, R[2]);  /* 0x800D03FC */
    R[2] = 0x800Fu << 16;  /* 0x800D0400 */
    R[2] = R[2] - 496;  /* 0x800D0404 */
    sw_(R[4] + 84, R[2]);  /* 0x800D0408 */
    R[2] = R[0] + 40;  /* 0x800D040C */
    { R[31] = 0x800D0418u; sh_(R[4] + 582, R[2]); psx_next = 0x800CD894u; return; }  /* 0x800D0410 jal */
    { goto L_800D06DC; }  /* 0x800D0418 j */
L_800D0420:;
    R[2] = lh_(R[17] + 582);  /* 0x800D0420 */
    R[2] = R[2] - 1;  /* 0x800D0428 */
    sh_(R[17] + 582, R[2]);  /* 0x800D042C */
    R[2] = R[2] << 16;  /* 0x800D0430 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[4] = R[17] + R[0]; if (_c) { goto L_800D048C; } }  /* 0x800D0434 */
    R[2] = R[0] + 4;  /* 0x800D043C */
    sb_(R[17] + 584, R[0]);  /* 0x800D0440 */
    { R[31] = 0x800D044Cu; sb_(R[17] + 790, R[2]); psx_next = 0x800A9EB4u; return; }  /* 0x800D0444 jal */
    R[4] = R[0] + 8;  /* 0x800D044C */
    R[2] = R[0] + 25;  /* 0x800D0450 */
    psx_div((int32_t)R[2], (int32_t)R[4]);  /* 0x800D0454 */
    { uint32_t _c = (R[4] != R[0]); if (_c) { goto L_800D0464; } }  /* 0x800D0458 */
    psx_break(7168);  /* 0x800D0460 */
L_800D0464:;
    R[1] = R[0] - 1;  /* 0x800D0464 */
    { uint32_t _c = (R[4] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800D047C; } }  /* 0x800D0468 */
    { uint32_t _c = (R[2] != R[1]); if (_c) { goto L_800D047C; } }  /* 0x800D0470 */
    psx_break(6144);  /* 0x800D0478 */
L_800D047C:;
    R[2] = LO;  /* 0x800D047C */
    sh_(R[17] + 582, R[4]);  /* 0x800D0480 */
    { sh_(R[17] + 594, R[2]); goto L_800D06DC; }  /* 0x800D0484 j */
L_800D048C:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 218);  /* 0x800D048C */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[5] = R[0] + R[0]; if (_c) { goto L_800D05A4; } }  /* 0x800D0494 */
    R[3] = lb_(R[17] + 585);  /* 0x800D049C */
    R[6] = R[0] + 4;  /* 0x800D04A0 */
    R[2] = 0x8014u << 16;  /* 0x800D04A4 */
    R[2] = R[2] + 15136;  /* 0x800D04A8 */
    R[3] = R[3] << 2;  /* 0x800D04AC */
    R[16] = R[3] + R[2];  /* 0x800D04B0 */
    { R[31] = 0x800D04BCu; R[4] = R[16] + R[0]; psx_next = 0x80030E58u; return; }  /* 0x800D04B4 jal */
    R[4] = R[17] + R[0];  /* 0x800D04BC */
    R[5] = R[0] + 1;  /* 0x800D04C0 */
    { R[31] = 0x800D04CCu; R[6] = R[16] + R[0]; psx_next = 0x800CE504u; return; }  /* 0x800D04C4 jal */
    R[18] = R[2] + R[0];  /* 0x800D04CC */
    { uint32_t _c = ((int32_t)R[18] <= 0); R[4] = R[0] + 8; if (_c) { goto L_800D05B4; } }  /* 0x800D04D0 */
    R[4] = lw_(R[16]);  /* 0x800D04D8 */
    { R[31] = 0x800D04E4u; psx_next = 0x800D0F94u; return; }  /* 0x800D04DC jal */
    { uint32_t _c = ((int32_t)R[2] < 0); R[4] = R[0] + 8; if (_c) { goto L_800D05B4; } }  /* 0x800D04E4 */
    R[5] = lh_(R[17] + 2);  /* 0x800D04EC */
    { R[31] = 0x800D04F8u; R[4] = R[0] + 58; psx_next = 0x8002DAE8u; return; }  /* 0x800D04F0 jal */
    R[3] = lw_(R[16]);  /* 0x800D04F8 */
    R[2] = lb_(R[3] + 789);  /* 0x800D0500 */
    R[5] = 0x800Fu << 16;  /* 0x800D0504 */
    R[2] = R[2] | 0x2;  /* 0x800D0508 */
    sb_(R[3] + 789, R[2]);  /* 0x800D050C */
    R[4] = lw_(R[16]);  /* 0x800D0510 */
    R[6] = lb_(R[17] + 585);  /* 0x800D0514 */
    { R[31] = 0x800D0520u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800D0518 jal */
    R[2] = lw_(R[16]);  /* 0x800D0520 */
    sw_(R[17] + 608, R[18]);  /* 0x800D0524 */
    sw_(R[17] + 588, R[2]);  /* 0x800D0528 */
    R[2] = lw_(R[16]);  /* 0x800D052C */
    R[4] = (uint32_t)(int16_t)lh_(R[2] + 10);  /* 0x800D0534 */
    { R[31] = 0x800D0540u; psx_next = 0x800A3028u; return; }  /* 0x800D0538 jal */
    R[4] = R[0] + 25;  /* 0x800D0540 */
    { R[31] = 0x800D054Cu; R[16] = R[2] + R[0]; psx_next = 0x80023E24u; return; }  /* 0x800D0544 jal */
    R[2] = R[2] + 1;  /* 0x800D054C */
    R[3] = R[2] << 1;  /* 0x800D0550 */
    R[3] = R[3] + R[2];  /* 0x800D0554 */
    R[2] = R[3] << 4;  /* 0x800D0558 */
    R[3] = R[2] - R[3];  /* 0x800D055C */
    R[2] = R[3] << 1;  /* 0x800D0560 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0564 */
    R[4] = lb_(R[16]);  /* 0x800D0568 */
    R[2] = R[0] + 1;  /* 0x800D056C */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[3] << 17; if (_c) { goto L_800D0580; } }  /* 0x800D0570 */
    { R[2] = (uint32_t)((int32_t)R[2] >> 17); goto L_800D0594; }  /* 0x800D0578 j */
L_800D0580:;
    R[2] = R[0] + 3;  /* 0x800D0580 */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800D059C; } }  /* 0x800D0584 */
    R[2] = R[3] << 17;  /* 0x800D058C */
    R[2] = (uint32_t)((int32_t)R[2] >> 15);  /* 0x800D0590 */
L_800D0594:;
    sh_(R[17] + 582, R[2]);  /* 0x800D0594 */
    R[2] = R[0] + 1;  /* 0x800D0598 */
L_800D059C:;
    { sb_(R[17] + 584, R[2]); goto L_800D05C0; }  /* 0x800D059C j */
L_800D05A4:;
    R[2] = lb_(R[17] + 785);  /* 0x800D05A4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 8; if (_c) { goto L_800D05DC; } }  /* 0x800D05AC */
L_800D05B4:;
    R[2] = R[0] + 2;  /* 0x800D05B4 */
    sb_(R[17] + 584, R[2]);  /* 0x800D05B8 */
    sh_(R[17] + 582, R[4]);  /* 0x800D05BC */
L_800D05C0:;
    R[4] = R[17] + R[0];  /* 0x800D05C0 */
    R[2] = R[0] + 3;  /* 0x800D05C4 */
    { R[31] = 0x800D05D0u; sb_(R[17] + 786, R[2]); psx_next = 0x800A9EB4u; return; }  /* 0x800D05C8 jal */
    R[2] = R[0] + 4;  /* 0x800D05D0 */
    { sb_(R[17] + 790, R[2]); goto L_800D06DC; }  /* 0x800D05D4 j */
L_800D05DC:;
    { R[31] = 0x800D05E4u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D05DC jal */
    R[4] = R[17] + R[0];  /* 0x800D05E4 */
    R[5] = R[0] + 5;  /* 0x800D05E8 */
    { R[31] = 0x800D05F4u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D05EC jal */
    { goto L_800D06DC; }  /* 0x800D05F4 j */
L_800D05FC:;
    R[2] = lh_(R[17] + 582);  /* 0x800D05FC */
    R[2] = R[2] - 1;  /* 0x800D0604 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0608 */
    R[2] = R[2] << 16;  /* 0x800D060C */
    { uint32_t _c = ((int32_t)R[2] > 0); R[4] = R[0] + 58; if (_c) { goto L_800D066C; } }  /* 0x800D0610 */
    R[5] = lh_(R[17] + 2);  /* 0x800D0618 */
    R[2] = R[0] + 3;  /* 0x800D061C */
    { R[31] = 0x800D0628u; sb_(R[17] + 790, R[2]); psx_next = 0x8002CF6Cu; return; }  /* 0x800D0620 jal */
    R[5] = R[0] + 1;  /* 0x800D0628 */
    R[6] = R[5] + R[0];  /* 0x800D062C */
    R[4] = 0x8014u << 16;  /* 0x800D0630 */
    R[2] = lb_(R[17] + 585);  /* 0x800D0634 */
    R[4] = R[4] + 15136;  /* 0x800D0638 */
    R[2] = R[2] << 2;  /* 0x800D063C */
    { R[31] = 0x800D0648u; R[4] = R[2] + R[4]; psx_next = 0x800CD028u; return; }  /* 0x800D0640 jal */
    R[3] = 0x8014u << 16;  /* 0x800D0648 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D064C */
    R[2] = R[2] - 1;  /* 0x800D0654 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D06DC; } }  /* 0x800D0658 */
    R[2] = 0x8013u << 16;  /* 0x800D0660 */
    { sh_(R[2] + -29614, R[0]); goto L_800D06DC; }  /* 0x800D0664 j */
L_800D066C:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D066C */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D06A0; } }  /* 0x800D0674 */
    R[2] = lh_(R[17] + 60);  /* 0x800D067C */
    R[4] = lh_(R[17] + 594);  /* 0x800D0680 */
    R[3] = lh_(R[17] + 62);  /* 0x800D0684 */
    R[5] = R[4] + R[0];  /* 0x800D0688 */
    R[2] = R[2] - R[4];  /* 0x800D068C */
    R[3] = R[3] - R[5];  /* 0x800D0690 */
    sh_(R[17] + 60, R[2]);  /* 0x800D0694 */
    { sh_(R[17] + 62, R[3]); goto L_800D06DC; }  /* 0x800D0698 j */
L_800D06A0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D06DC; } }  /* 0x800D06A0 */
    R[6] = R[0] + 1;  /* 0x800D06A8 */
    R[4] = 0x8014u << 16;  /* 0x800D06AC */
    R[2] = lb_(R[17] + 585);  /* 0x800D06B0 */
    R[4] = R[4] + 15136;  /* 0x800D06B4 */
    R[2] = R[2] << 2;  /* 0x800D06B8 */
    { R[31] = 0x800D06C4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D06BC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D06D0; } }  /* 0x800D06C4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D06CC */
L_800D06D0:;
    R[5] = lw_(R[17] + 588);  /* 0x800D06D0 */
    { R[31] = 0x800D06DCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D06D4 jal */
L_800D06DC:;
    R[31] = lw_(R[29] + 36);  /* 0x800D06DC */
    R[18] = lw_(R[29] + 32);  /* 0x800D06E0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D06E4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D06E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D06EC jr ra */
}

void g0_800D0418(void) {
    { goto L_800D06DC; }  /* 0x800D0418 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D0420 */
    R[2] = R[2] - 1;  /* 0x800D0428 */
    sh_(R[17] + 582, R[2]);  /* 0x800D042C */
    R[2] = R[2] << 16;  /* 0x800D0430 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[4] = R[17] + R[0]; if (_c) { goto L_800D048C; } }  /* 0x800D0434 */
    R[2] = R[0] + 4;  /* 0x800D043C */
    sb_(R[17] + 584, R[0]);  /* 0x800D0440 */
    { R[31] = 0x800D044Cu; sb_(R[17] + 790, R[2]); psx_next = 0x800A9EB4u; return; }  /* 0x800D0444 jal */
    R[4] = R[0] + 8;  /* 0x800D044C */
    R[2] = R[0] + 25;  /* 0x800D0450 */
    psx_div((int32_t)R[2], (int32_t)R[4]);  /* 0x800D0454 */
    { uint32_t _c = (R[4] != R[0]); if (_c) { goto L_800D0464; } }  /* 0x800D0458 */
    psx_break(7168);  /* 0x800D0460 */
L_800D0464:;
    R[1] = R[0] - 1;  /* 0x800D0464 */
    { uint32_t _c = (R[4] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800D047C; } }  /* 0x800D0468 */
    { uint32_t _c = (R[2] != R[1]); if (_c) { goto L_800D047C; } }  /* 0x800D0470 */
    psx_break(6144);  /* 0x800D0478 */
L_800D047C:;
    R[2] = LO;  /* 0x800D047C */
    sh_(R[17] + 582, R[4]);  /* 0x800D0480 */
    { sh_(R[17] + 594, R[2]); goto L_800D06DC; }  /* 0x800D0484 j */
L_800D048C:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 218);  /* 0x800D048C */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[5] = R[0] + R[0]; if (_c) { goto L_800D05A4; } }  /* 0x800D0494 */
    R[3] = lb_(R[17] + 585);  /* 0x800D049C */
    R[6] = R[0] + 4;  /* 0x800D04A0 */
    R[2] = 0x8014u << 16;  /* 0x800D04A4 */
    R[2] = R[2] + 15136;  /* 0x800D04A8 */
    R[3] = R[3] << 2;  /* 0x800D04AC */
    R[16] = R[3] + R[2];  /* 0x800D04B0 */
    { R[31] = 0x800D04BCu; R[4] = R[16] + R[0]; psx_next = 0x80030E58u; return; }  /* 0x800D04B4 jal */
    R[4] = R[17] + R[0];  /* 0x800D04BC */
    R[5] = R[0] + 1;  /* 0x800D04C0 */
    { R[31] = 0x800D04CCu; R[6] = R[16] + R[0]; psx_next = 0x800CE504u; return; }  /* 0x800D04C4 jal */
    R[18] = R[2] + R[0];  /* 0x800D04CC */
    { uint32_t _c = ((int32_t)R[18] <= 0); R[4] = R[0] + 8; if (_c) { goto L_800D05B4; } }  /* 0x800D04D0 */
    R[4] = lw_(R[16]);  /* 0x800D04D8 */
    { R[31] = 0x800D04E4u; psx_next = 0x800D0F94u; return; }  /* 0x800D04DC jal */
    { uint32_t _c = ((int32_t)R[2] < 0); R[4] = R[0] + 8; if (_c) { goto L_800D05B4; } }  /* 0x800D04E4 */
    R[5] = lh_(R[17] + 2);  /* 0x800D04EC */
    { R[31] = 0x800D04F8u; R[4] = R[0] + 58; psx_next = 0x8002DAE8u; return; }  /* 0x800D04F0 jal */
    R[3] = lw_(R[16]);  /* 0x800D04F8 */
    R[2] = lb_(R[3] + 789);  /* 0x800D0500 */
    R[5] = 0x800Fu << 16;  /* 0x800D0504 */
    R[2] = R[2] | 0x2;  /* 0x800D0508 */
    sb_(R[3] + 789, R[2]);  /* 0x800D050C */
    R[4] = lw_(R[16]);  /* 0x800D0510 */
    R[6] = lb_(R[17] + 585);  /* 0x800D0514 */
    { R[31] = 0x800D0520u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800D0518 jal */
    R[2] = lw_(R[16]);  /* 0x800D0520 */
    sw_(R[17] + 608, R[18]);  /* 0x800D0524 */
    sw_(R[17] + 588, R[2]);  /* 0x800D0528 */
    R[2] = lw_(R[16]);  /* 0x800D052C */
    R[4] = (uint32_t)(int16_t)lh_(R[2] + 10);  /* 0x800D0534 */
    { R[31] = 0x800D0540u; psx_next = 0x800A3028u; return; }  /* 0x800D0538 jal */
    R[4] = R[0] + 25;  /* 0x800D0540 */
    { R[31] = 0x800D054Cu; R[16] = R[2] + R[0]; psx_next = 0x80023E24u; return; }  /* 0x800D0544 jal */
    R[2] = R[2] + 1;  /* 0x800D054C */
    R[3] = R[2] << 1;  /* 0x800D0550 */
    R[3] = R[3] + R[2];  /* 0x800D0554 */
    R[2] = R[3] << 4;  /* 0x800D0558 */
    R[3] = R[2] - R[3];  /* 0x800D055C */
    R[2] = R[3] << 1;  /* 0x800D0560 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0564 */
    R[4] = lb_(R[16]);  /* 0x800D0568 */
    R[2] = R[0] + 1;  /* 0x800D056C */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[3] << 17; if (_c) { goto L_800D0580; } }  /* 0x800D0570 */
    { R[2] = (uint32_t)((int32_t)R[2] >> 17); goto L_800D0594; }  /* 0x800D0578 j */
L_800D0580:;
    R[2] = R[0] + 3;  /* 0x800D0580 */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800D059C; } }  /* 0x800D0584 */
    R[2] = R[3] << 17;  /* 0x800D058C */
    R[2] = (uint32_t)((int32_t)R[2] >> 15);  /* 0x800D0590 */
L_800D0594:;
    sh_(R[17] + 582, R[2]);  /* 0x800D0594 */
    R[2] = R[0] + 1;  /* 0x800D0598 */
L_800D059C:;
    { sb_(R[17] + 584, R[2]); goto L_800D05C0; }  /* 0x800D059C j */
L_800D05A4:;
    R[2] = lb_(R[17] + 785);  /* 0x800D05A4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 8; if (_c) { goto L_800D05DC; } }  /* 0x800D05AC */
L_800D05B4:;
    R[2] = R[0] + 2;  /* 0x800D05B4 */
    sb_(R[17] + 584, R[2]);  /* 0x800D05B8 */
    sh_(R[17] + 582, R[4]);  /* 0x800D05BC */
L_800D05C0:;
    R[4] = R[17] + R[0];  /* 0x800D05C0 */
    R[2] = R[0] + 3;  /* 0x800D05C4 */
    { R[31] = 0x800D05D0u; sb_(R[17] + 786, R[2]); psx_next = 0x800A9EB4u; return; }  /* 0x800D05C8 jal */
    R[2] = R[0] + 4;  /* 0x800D05D0 */
    { sb_(R[17] + 790, R[2]); goto L_800D06DC; }  /* 0x800D05D4 j */
L_800D05DC:;
    { R[31] = 0x800D05E4u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D05DC jal */
    R[4] = R[17] + R[0];  /* 0x800D05E4 */
    R[5] = R[0] + 5;  /* 0x800D05E8 */
    { R[31] = 0x800D05F4u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D05EC jal */
    { goto L_800D06DC; }  /* 0x800D05F4 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D05FC */
    R[2] = R[2] - 1;  /* 0x800D0604 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0608 */
    R[2] = R[2] << 16;  /* 0x800D060C */
    { uint32_t _c = ((int32_t)R[2] > 0); R[4] = R[0] + 58; if (_c) { goto L_800D066C; } }  /* 0x800D0610 */
    R[5] = lh_(R[17] + 2);  /* 0x800D0618 */
    R[2] = R[0] + 3;  /* 0x800D061C */
    { R[31] = 0x800D0628u; sb_(R[17] + 790, R[2]); psx_next = 0x8002CF6Cu; return; }  /* 0x800D0620 jal */
    R[5] = R[0] + 1;  /* 0x800D0628 */
    R[6] = R[5] + R[0];  /* 0x800D062C */
    R[4] = 0x8014u << 16;  /* 0x800D0630 */
    R[2] = lb_(R[17] + 585);  /* 0x800D0634 */
    R[4] = R[4] + 15136;  /* 0x800D0638 */
    R[2] = R[2] << 2;  /* 0x800D063C */
    { R[31] = 0x800D0648u; R[4] = R[2] + R[4]; psx_next = 0x800CD028u; return; }  /* 0x800D0640 jal */
    R[3] = 0x8014u << 16;  /* 0x800D0648 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D064C */
    R[2] = R[2] - 1;  /* 0x800D0654 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D06DC; } }  /* 0x800D0658 */
    R[2] = 0x8013u << 16;  /* 0x800D0660 */
    { sh_(R[2] + -29614, R[0]); goto L_800D06DC; }  /* 0x800D0664 j */
L_800D066C:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D066C */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D06A0; } }  /* 0x800D0674 */
    R[2] = lh_(R[17] + 60);  /* 0x800D067C */
    R[4] = lh_(R[17] + 594);  /* 0x800D0680 */
    R[3] = lh_(R[17] + 62);  /* 0x800D0684 */
    R[5] = R[4] + R[0];  /* 0x800D0688 */
    R[2] = R[2] - R[4];  /* 0x800D068C */
    R[3] = R[3] - R[5];  /* 0x800D0690 */
    sh_(R[17] + 60, R[2]);  /* 0x800D0694 */
    { sh_(R[17] + 62, R[3]); goto L_800D06DC; }  /* 0x800D0698 j */
L_800D06A0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D06DC; } }  /* 0x800D06A0 */
    R[6] = R[0] + 1;  /* 0x800D06A8 */
    R[4] = 0x8014u << 16;  /* 0x800D06AC */
    R[2] = lb_(R[17] + 585);  /* 0x800D06B0 */
    R[4] = R[4] + 15136;  /* 0x800D06B4 */
    R[2] = R[2] << 2;  /* 0x800D06B8 */
    { R[31] = 0x800D06C4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D06BC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D06D0; } }  /* 0x800D06C4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D06CC */
L_800D06D0:;
    R[5] = lw_(R[17] + 588);  /* 0x800D06D0 */
    { R[31] = 0x800D06DCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D06D4 jal */
L_800D06DC:;
    R[31] = lw_(R[29] + 36);  /* 0x800D06DC */
    R[18] = lw_(R[29] + 32);  /* 0x800D06E0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D06E4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D06E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D06EC jr ra */
}

void g0_800D044C(void) {
    R[4] = R[0] + 8;  /* 0x800D044C */
    R[2] = R[0] + 25;  /* 0x800D0450 */
    psx_div((int32_t)R[2], (int32_t)R[4]);  /* 0x800D0454 */
    { uint32_t _c = (R[4] != R[0]); if (_c) { goto L_800D0464; } }  /* 0x800D0458 */
    psx_break(7168);  /* 0x800D0460 */
L_800D0464:;
    R[1] = R[0] - 1;  /* 0x800D0464 */
    { uint32_t _c = (R[4] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800D047C; } }  /* 0x800D0468 */
    { uint32_t _c = (R[2] != R[1]); if (_c) { goto L_800D047C; } }  /* 0x800D0470 */
    psx_break(6144);  /* 0x800D0478 */
L_800D047C:;
    R[2] = LO;  /* 0x800D047C */
    sh_(R[17] + 582, R[4]);  /* 0x800D0480 */
    { sh_(R[17] + 594, R[2]); goto L_800D06DC; }  /* 0x800D0484 j */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 218);  /* 0x800D048C */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[5] = R[0] + R[0]; if (_c) { goto L_800D05A4; } }  /* 0x800D0494 */
    R[3] = lb_(R[17] + 585);  /* 0x800D049C */
    R[6] = R[0] + 4;  /* 0x800D04A0 */
    R[2] = 0x8014u << 16;  /* 0x800D04A4 */
    R[2] = R[2] + 15136;  /* 0x800D04A8 */
    R[3] = R[3] << 2;  /* 0x800D04AC */
    R[16] = R[3] + R[2];  /* 0x800D04B0 */
    { R[31] = 0x800D04BCu; R[4] = R[16] + R[0]; psx_next = 0x80030E58u; return; }  /* 0x800D04B4 jal */
    R[4] = R[17] + R[0];  /* 0x800D04BC */
    R[5] = R[0] + 1;  /* 0x800D04C0 */
    { R[31] = 0x800D04CCu; R[6] = R[16] + R[0]; psx_next = 0x800CE504u; return; }  /* 0x800D04C4 jal */
    R[18] = R[2] + R[0];  /* 0x800D04CC */
    { uint32_t _c = ((int32_t)R[18] <= 0); R[4] = R[0] + 8; if (_c) { goto L_800D05B4; } }  /* 0x800D04D0 */
    R[4] = lw_(R[16]);  /* 0x800D04D8 */
    { R[31] = 0x800D04E4u; psx_next = 0x800D0F94u; return; }  /* 0x800D04DC jal */
    { uint32_t _c = ((int32_t)R[2] < 0); R[4] = R[0] + 8; if (_c) { goto L_800D05B4; } }  /* 0x800D04E4 */
    R[5] = lh_(R[17] + 2);  /* 0x800D04EC */
    { R[31] = 0x800D04F8u; R[4] = R[0] + 58; psx_next = 0x8002DAE8u; return; }  /* 0x800D04F0 jal */
    R[3] = lw_(R[16]);  /* 0x800D04F8 */
    R[2] = lb_(R[3] + 789);  /* 0x800D0500 */
    R[5] = 0x800Fu << 16;  /* 0x800D0504 */
    R[2] = R[2] | 0x2;  /* 0x800D0508 */
    sb_(R[3] + 789, R[2]);  /* 0x800D050C */
    R[4] = lw_(R[16]);  /* 0x800D0510 */
    R[6] = lb_(R[17] + 585);  /* 0x800D0514 */
    { R[31] = 0x800D0520u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800D0518 jal */
    R[2] = lw_(R[16]);  /* 0x800D0520 */
    sw_(R[17] + 608, R[18]);  /* 0x800D0524 */
    sw_(R[17] + 588, R[2]);  /* 0x800D0528 */
    R[2] = lw_(R[16]);  /* 0x800D052C */
    R[4] = (uint32_t)(int16_t)lh_(R[2] + 10);  /* 0x800D0534 */
    { R[31] = 0x800D0540u; psx_next = 0x800A3028u; return; }  /* 0x800D0538 jal */
    R[4] = R[0] + 25;  /* 0x800D0540 */
    { R[31] = 0x800D054Cu; R[16] = R[2] + R[0]; psx_next = 0x80023E24u; return; }  /* 0x800D0544 jal */
    R[2] = R[2] + 1;  /* 0x800D054C */
    R[3] = R[2] << 1;  /* 0x800D0550 */
    R[3] = R[3] + R[2];  /* 0x800D0554 */
    R[2] = R[3] << 4;  /* 0x800D0558 */
    R[3] = R[2] - R[3];  /* 0x800D055C */
    R[2] = R[3] << 1;  /* 0x800D0560 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0564 */
    R[4] = lb_(R[16]);  /* 0x800D0568 */
    R[2] = R[0] + 1;  /* 0x800D056C */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[3] << 17; if (_c) { goto L_800D0580; } }  /* 0x800D0570 */
    { R[2] = (uint32_t)((int32_t)R[2] >> 17); goto L_800D0594; }  /* 0x800D0578 j */
L_800D0580:;
    R[2] = R[0] + 3;  /* 0x800D0580 */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800D059C; } }  /* 0x800D0584 */
    R[2] = R[3] << 17;  /* 0x800D058C */
    R[2] = (uint32_t)((int32_t)R[2] >> 15);  /* 0x800D0590 */
L_800D0594:;
    sh_(R[17] + 582, R[2]);  /* 0x800D0594 */
    R[2] = R[0] + 1;  /* 0x800D0598 */
L_800D059C:;
    { sb_(R[17] + 584, R[2]); goto L_800D05C0; }  /* 0x800D059C j */
L_800D05A4:;
    R[2] = lb_(R[17] + 785);  /* 0x800D05A4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 8; if (_c) { goto L_800D05DC; } }  /* 0x800D05AC */
L_800D05B4:;
    R[2] = R[0] + 2;  /* 0x800D05B4 */
    sb_(R[17] + 584, R[2]);  /* 0x800D05B8 */
    sh_(R[17] + 582, R[4]);  /* 0x800D05BC */
L_800D05C0:;
    R[4] = R[17] + R[0];  /* 0x800D05C0 */
    R[2] = R[0] + 3;  /* 0x800D05C4 */
    { R[31] = 0x800D05D0u; sb_(R[17] + 786, R[2]); psx_next = 0x800A9EB4u; return; }  /* 0x800D05C8 jal */
    R[2] = R[0] + 4;  /* 0x800D05D0 */
    { sb_(R[17] + 790, R[2]); goto L_800D06DC; }  /* 0x800D05D4 j */
L_800D05DC:;
    { R[31] = 0x800D05E4u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D05DC jal */
    R[4] = R[17] + R[0];  /* 0x800D05E4 */
    R[5] = R[0] + 5;  /* 0x800D05E8 */
    { R[31] = 0x800D05F4u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D05EC jal */
    { goto L_800D06DC; }  /* 0x800D05F4 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D05FC */
    R[2] = R[2] - 1;  /* 0x800D0604 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0608 */
    R[2] = R[2] << 16;  /* 0x800D060C */
    { uint32_t _c = ((int32_t)R[2] > 0); R[4] = R[0] + 58; if (_c) { goto L_800D066C; } }  /* 0x800D0610 */
    R[5] = lh_(R[17] + 2);  /* 0x800D0618 */
    R[2] = R[0] + 3;  /* 0x800D061C */
    { R[31] = 0x800D0628u; sb_(R[17] + 790, R[2]); psx_next = 0x8002CF6Cu; return; }  /* 0x800D0620 jal */
    R[5] = R[0] + 1;  /* 0x800D0628 */
    R[6] = R[5] + R[0];  /* 0x800D062C */
    R[4] = 0x8014u << 16;  /* 0x800D0630 */
    R[2] = lb_(R[17] + 585);  /* 0x800D0634 */
    R[4] = R[4] + 15136;  /* 0x800D0638 */
    R[2] = R[2] << 2;  /* 0x800D063C */
    { R[31] = 0x800D0648u; R[4] = R[2] + R[4]; psx_next = 0x800CD028u; return; }  /* 0x800D0640 jal */
    R[3] = 0x8014u << 16;  /* 0x800D0648 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D064C */
    R[2] = R[2] - 1;  /* 0x800D0654 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D06DC; } }  /* 0x800D0658 */
    R[2] = 0x8013u << 16;  /* 0x800D0660 */
    { sh_(R[2] + -29614, R[0]); goto L_800D06DC; }  /* 0x800D0664 j */
L_800D066C:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D066C */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D06A0; } }  /* 0x800D0674 */
    R[2] = lh_(R[17] + 60);  /* 0x800D067C */
    R[4] = lh_(R[17] + 594);  /* 0x800D0680 */
    R[3] = lh_(R[17] + 62);  /* 0x800D0684 */
    R[5] = R[4] + R[0];  /* 0x800D0688 */
    R[2] = R[2] - R[4];  /* 0x800D068C */
    R[3] = R[3] - R[5];  /* 0x800D0690 */
    sh_(R[17] + 60, R[2]);  /* 0x800D0694 */
    { sh_(R[17] + 62, R[3]); goto L_800D06DC; }  /* 0x800D0698 j */
L_800D06A0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D06DC; } }  /* 0x800D06A0 */
    R[6] = R[0] + 1;  /* 0x800D06A8 */
    R[4] = 0x8014u << 16;  /* 0x800D06AC */
    R[2] = lb_(R[17] + 585);  /* 0x800D06B0 */
    R[4] = R[4] + 15136;  /* 0x800D06B4 */
    R[2] = R[2] << 2;  /* 0x800D06B8 */
    { R[31] = 0x800D06C4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D06BC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D06D0; } }  /* 0x800D06C4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D06CC */
L_800D06D0:;
    R[5] = lw_(R[17] + 588);  /* 0x800D06D0 */
    { R[31] = 0x800D06DCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D06D4 jal */
L_800D06DC:;
    R[31] = lw_(R[29] + 36);  /* 0x800D06DC */
    R[18] = lw_(R[29] + 32);  /* 0x800D06E0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D06E4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D06E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D06EC jr ra */
}

void g0_800D04BC(void) {
    R[4] = R[17] + R[0];  /* 0x800D04BC */
    R[5] = R[0] + 1;  /* 0x800D04C0 */
    { R[31] = 0x800D04CCu; R[6] = R[16] + R[0]; psx_next = 0x800CE504u; return; }  /* 0x800D04C4 jal */
    R[18] = R[2] + R[0];  /* 0x800D04CC */
    { uint32_t _c = ((int32_t)R[18] <= 0); R[4] = R[0] + 8; if (_c) { goto L_800D05B4; } }  /* 0x800D04D0 */
    R[4] = lw_(R[16]);  /* 0x800D04D8 */
    { R[31] = 0x800D04E4u; psx_next = 0x800D0F94u; return; }  /* 0x800D04DC jal */
    { uint32_t _c = ((int32_t)R[2] < 0); R[4] = R[0] + 8; if (_c) { goto L_800D05B4; } }  /* 0x800D04E4 */
    R[5] = lh_(R[17] + 2);  /* 0x800D04EC */
    { R[31] = 0x800D04F8u; R[4] = R[0] + 58; psx_next = 0x8002DAE8u; return; }  /* 0x800D04F0 jal */
    R[3] = lw_(R[16]);  /* 0x800D04F8 */
    R[2] = lb_(R[3] + 789);  /* 0x800D0500 */
    R[5] = 0x800Fu << 16;  /* 0x800D0504 */
    R[2] = R[2] | 0x2;  /* 0x800D0508 */
    sb_(R[3] + 789, R[2]);  /* 0x800D050C */
    R[4] = lw_(R[16]);  /* 0x800D0510 */
    R[6] = lb_(R[17] + 585);  /* 0x800D0514 */
    { R[31] = 0x800D0520u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800D0518 jal */
    R[2] = lw_(R[16]);  /* 0x800D0520 */
    sw_(R[17] + 608, R[18]);  /* 0x800D0524 */
    sw_(R[17] + 588, R[2]);  /* 0x800D0528 */
    R[2] = lw_(R[16]);  /* 0x800D052C */
    R[4] = (uint32_t)(int16_t)lh_(R[2] + 10);  /* 0x800D0534 */
    { R[31] = 0x800D0540u; psx_next = 0x800A3028u; return; }  /* 0x800D0538 jal */
    R[4] = R[0] + 25;  /* 0x800D0540 */
    { R[31] = 0x800D054Cu; R[16] = R[2] + R[0]; psx_next = 0x80023E24u; return; }  /* 0x800D0544 jal */
    R[2] = R[2] + 1;  /* 0x800D054C */
    R[3] = R[2] << 1;  /* 0x800D0550 */
    R[3] = R[3] + R[2];  /* 0x800D0554 */
    R[2] = R[3] << 4;  /* 0x800D0558 */
    R[3] = R[2] - R[3];  /* 0x800D055C */
    R[2] = R[3] << 1;  /* 0x800D0560 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0564 */
    R[4] = lb_(R[16]);  /* 0x800D0568 */
    R[2] = R[0] + 1;  /* 0x800D056C */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[3] << 17; if (_c) { goto L_800D0580; } }  /* 0x800D0570 */
    { R[2] = (uint32_t)((int32_t)R[2] >> 17); goto L_800D0594; }  /* 0x800D0578 j */
L_800D0580:;
    R[2] = R[0] + 3;  /* 0x800D0580 */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800D059C; } }  /* 0x800D0584 */
    R[2] = R[3] << 17;  /* 0x800D058C */
    R[2] = (uint32_t)((int32_t)R[2] >> 15);  /* 0x800D0590 */
L_800D0594:;
    sh_(R[17] + 582, R[2]);  /* 0x800D0594 */
    R[2] = R[0] + 1;  /* 0x800D0598 */
L_800D059C:;
    { sb_(R[17] + 584, R[2]); goto L_800D05C0; }  /* 0x800D059C j */
    R[2] = lb_(R[17] + 785);  /* 0x800D05A4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 8; if (_c) { goto L_800D05DC; } }  /* 0x800D05AC */
L_800D05B4:;
    R[2] = R[0] + 2;  /* 0x800D05B4 */
    sb_(R[17] + 584, R[2]);  /* 0x800D05B8 */
    sh_(R[17] + 582, R[4]);  /* 0x800D05BC */
L_800D05C0:;
    R[4] = R[17] + R[0];  /* 0x800D05C0 */
    R[2] = R[0] + 3;  /* 0x800D05C4 */
    { R[31] = 0x800D05D0u; sb_(R[17] + 786, R[2]); psx_next = 0x800A9EB4u; return; }  /* 0x800D05C8 jal */
    R[2] = R[0] + 4;  /* 0x800D05D0 */
    { sb_(R[17] + 790, R[2]); goto L_800D06DC; }  /* 0x800D05D4 j */
L_800D05DC:;
    { R[31] = 0x800D05E4u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D05DC jal */
    R[4] = R[17] + R[0];  /* 0x800D05E4 */
    R[5] = R[0] + 5;  /* 0x800D05E8 */
    { R[31] = 0x800D05F4u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D05EC jal */
    { goto L_800D06DC; }  /* 0x800D05F4 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D05FC */
    R[2] = R[2] - 1;  /* 0x800D0604 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0608 */
    R[2] = R[2] << 16;  /* 0x800D060C */
    { uint32_t _c = ((int32_t)R[2] > 0); R[4] = R[0] + 58; if (_c) { goto L_800D066C; } }  /* 0x800D0610 */
    R[5] = lh_(R[17] + 2);  /* 0x800D0618 */
    R[2] = R[0] + 3;  /* 0x800D061C */
    { R[31] = 0x800D0628u; sb_(R[17] + 790, R[2]); psx_next = 0x8002CF6Cu; return; }  /* 0x800D0620 jal */
    R[5] = R[0] + 1;  /* 0x800D0628 */
    R[6] = R[5] + R[0];  /* 0x800D062C */
    R[4] = 0x8014u << 16;  /* 0x800D0630 */
    R[2] = lb_(R[17] + 585);  /* 0x800D0634 */
    R[4] = R[4] + 15136;  /* 0x800D0638 */
    R[2] = R[2] << 2;  /* 0x800D063C */
    { R[31] = 0x800D0648u; R[4] = R[2] + R[4]; psx_next = 0x800CD028u; return; }  /* 0x800D0640 jal */
    R[3] = 0x8014u << 16;  /* 0x800D0648 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D064C */
    R[2] = R[2] - 1;  /* 0x800D0654 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D06DC; } }  /* 0x800D0658 */
    R[2] = 0x8013u << 16;  /* 0x800D0660 */
    { sh_(R[2] + -29614, R[0]); goto L_800D06DC; }  /* 0x800D0664 j */
L_800D066C:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D066C */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D06A0; } }  /* 0x800D0674 */
    R[2] = lh_(R[17] + 60);  /* 0x800D067C */
    R[4] = lh_(R[17] + 594);  /* 0x800D0680 */
    R[3] = lh_(R[17] + 62);  /* 0x800D0684 */
    R[5] = R[4] + R[0];  /* 0x800D0688 */
    R[2] = R[2] - R[4];  /* 0x800D068C */
    R[3] = R[3] - R[5];  /* 0x800D0690 */
    sh_(R[17] + 60, R[2]);  /* 0x800D0694 */
    { sh_(R[17] + 62, R[3]); goto L_800D06DC; }  /* 0x800D0698 j */
L_800D06A0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D06DC; } }  /* 0x800D06A0 */
    R[6] = R[0] + 1;  /* 0x800D06A8 */
    R[4] = 0x8014u << 16;  /* 0x800D06AC */
    R[2] = lb_(R[17] + 585);  /* 0x800D06B0 */
    R[4] = R[4] + 15136;  /* 0x800D06B4 */
    R[2] = R[2] << 2;  /* 0x800D06B8 */
    { R[31] = 0x800D06C4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D06BC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D06D0; } }  /* 0x800D06C4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D06CC */
L_800D06D0:;
    R[5] = lw_(R[17] + 588);  /* 0x800D06D0 */
    { R[31] = 0x800D06DCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D06D4 jal */
L_800D06DC:;
    R[31] = lw_(R[29] + 36);  /* 0x800D06DC */
    R[18] = lw_(R[29] + 32);  /* 0x800D06E0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D06E4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D06E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D06EC jr ra */
}

void g0_800D04CC(void) {
    R[18] = R[2] + R[0];  /* 0x800D04CC */
    { uint32_t _c = ((int32_t)R[18] <= 0); R[4] = R[0] + 8; if (_c) { goto L_800D05B4; } }  /* 0x800D04D0 */
    R[4] = lw_(R[16]);  /* 0x800D04D8 */
    { R[31] = 0x800D04E4u; psx_next = 0x800D0F94u; return; }  /* 0x800D04DC jal */
    { uint32_t _c = ((int32_t)R[2] < 0); R[4] = R[0] + 8; if (_c) { goto L_800D05B4; } }  /* 0x800D04E4 */
    R[5] = lh_(R[17] + 2);  /* 0x800D04EC */
    { R[31] = 0x800D04F8u; R[4] = R[0] + 58; psx_next = 0x8002DAE8u; return; }  /* 0x800D04F0 jal */
    R[3] = lw_(R[16]);  /* 0x800D04F8 */
    R[2] = lb_(R[3] + 789);  /* 0x800D0500 */
    R[5] = 0x800Fu << 16;  /* 0x800D0504 */
    R[2] = R[2] | 0x2;  /* 0x800D0508 */
    sb_(R[3] + 789, R[2]);  /* 0x800D050C */
    R[4] = lw_(R[16]);  /* 0x800D0510 */
    R[6] = lb_(R[17] + 585);  /* 0x800D0514 */
    { R[31] = 0x800D0520u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800D0518 jal */
    R[2] = lw_(R[16]);  /* 0x800D0520 */
    sw_(R[17] + 608, R[18]);  /* 0x800D0524 */
    sw_(R[17] + 588, R[2]);  /* 0x800D0528 */
    R[2] = lw_(R[16]);  /* 0x800D052C */
    R[4] = (uint32_t)(int16_t)lh_(R[2] + 10);  /* 0x800D0534 */
    { R[31] = 0x800D0540u; psx_next = 0x800A3028u; return; }  /* 0x800D0538 jal */
    R[4] = R[0] + 25;  /* 0x800D0540 */
    { R[31] = 0x800D054Cu; R[16] = R[2] + R[0]; psx_next = 0x80023E24u; return; }  /* 0x800D0544 jal */
    R[2] = R[2] + 1;  /* 0x800D054C */
    R[3] = R[2] << 1;  /* 0x800D0550 */
    R[3] = R[3] + R[2];  /* 0x800D0554 */
    R[2] = R[3] << 4;  /* 0x800D0558 */
    R[3] = R[2] - R[3];  /* 0x800D055C */
    R[2] = R[3] << 1;  /* 0x800D0560 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0564 */
    R[4] = lb_(R[16]);  /* 0x800D0568 */
    R[2] = R[0] + 1;  /* 0x800D056C */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[3] << 17; if (_c) { goto L_800D0580; } }  /* 0x800D0570 */
    { R[2] = (uint32_t)((int32_t)R[2] >> 17); goto L_800D0594; }  /* 0x800D0578 j */
L_800D0580:;
    R[2] = R[0] + 3;  /* 0x800D0580 */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800D059C; } }  /* 0x800D0584 */
    R[2] = R[3] << 17;  /* 0x800D058C */
    R[2] = (uint32_t)((int32_t)R[2] >> 15);  /* 0x800D0590 */
L_800D0594:;
    sh_(R[17] + 582, R[2]);  /* 0x800D0594 */
    R[2] = R[0] + 1;  /* 0x800D0598 */
L_800D059C:;
    { sb_(R[17] + 584, R[2]); goto L_800D05C0; }  /* 0x800D059C j */
    R[2] = lb_(R[17] + 785);  /* 0x800D05A4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 8; if (_c) { goto L_800D05DC; } }  /* 0x800D05AC */
L_800D05B4:;
    R[2] = R[0] + 2;  /* 0x800D05B4 */
    sb_(R[17] + 584, R[2]);  /* 0x800D05B8 */
    sh_(R[17] + 582, R[4]);  /* 0x800D05BC */
L_800D05C0:;
    R[4] = R[17] + R[0];  /* 0x800D05C0 */
    R[2] = R[0] + 3;  /* 0x800D05C4 */
    { R[31] = 0x800D05D0u; sb_(R[17] + 786, R[2]); psx_next = 0x800A9EB4u; return; }  /* 0x800D05C8 jal */
    R[2] = R[0] + 4;  /* 0x800D05D0 */
    { sb_(R[17] + 790, R[2]); goto L_800D06DC; }  /* 0x800D05D4 j */
L_800D05DC:;
    { R[31] = 0x800D05E4u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D05DC jal */
    R[4] = R[17] + R[0];  /* 0x800D05E4 */
    R[5] = R[0] + 5;  /* 0x800D05E8 */
    { R[31] = 0x800D05F4u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D05EC jal */
    { goto L_800D06DC; }  /* 0x800D05F4 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D05FC */
    R[2] = R[2] - 1;  /* 0x800D0604 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0608 */
    R[2] = R[2] << 16;  /* 0x800D060C */
    { uint32_t _c = ((int32_t)R[2] > 0); R[4] = R[0] + 58; if (_c) { goto L_800D066C; } }  /* 0x800D0610 */
    R[5] = lh_(R[17] + 2);  /* 0x800D0618 */
    R[2] = R[0] + 3;  /* 0x800D061C */
    { R[31] = 0x800D0628u; sb_(R[17] + 790, R[2]); psx_next = 0x8002CF6Cu; return; }  /* 0x800D0620 jal */
    R[5] = R[0] + 1;  /* 0x800D0628 */
    R[6] = R[5] + R[0];  /* 0x800D062C */
    R[4] = 0x8014u << 16;  /* 0x800D0630 */
    R[2] = lb_(R[17] + 585);  /* 0x800D0634 */
    R[4] = R[4] + 15136;  /* 0x800D0638 */
    R[2] = R[2] << 2;  /* 0x800D063C */
    { R[31] = 0x800D0648u; R[4] = R[2] + R[4]; psx_next = 0x800CD028u; return; }  /* 0x800D0640 jal */
    R[3] = 0x8014u << 16;  /* 0x800D0648 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D064C */
    R[2] = R[2] - 1;  /* 0x800D0654 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D06DC; } }  /* 0x800D0658 */
    R[2] = 0x8013u << 16;  /* 0x800D0660 */
    { sh_(R[2] + -29614, R[0]); goto L_800D06DC; }  /* 0x800D0664 j */
L_800D066C:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D066C */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D06A0; } }  /* 0x800D0674 */
    R[2] = lh_(R[17] + 60);  /* 0x800D067C */
    R[4] = lh_(R[17] + 594);  /* 0x800D0680 */
    R[3] = lh_(R[17] + 62);  /* 0x800D0684 */
    R[5] = R[4] + R[0];  /* 0x800D0688 */
    R[2] = R[2] - R[4];  /* 0x800D068C */
    R[3] = R[3] - R[5];  /* 0x800D0690 */
    sh_(R[17] + 60, R[2]);  /* 0x800D0694 */
    { sh_(R[17] + 62, R[3]); goto L_800D06DC; }  /* 0x800D0698 j */
L_800D06A0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D06DC; } }  /* 0x800D06A0 */
    R[6] = R[0] + 1;  /* 0x800D06A8 */
    R[4] = 0x8014u << 16;  /* 0x800D06AC */
    R[2] = lb_(R[17] + 585);  /* 0x800D06B0 */
    R[4] = R[4] + 15136;  /* 0x800D06B4 */
    R[2] = R[2] << 2;  /* 0x800D06B8 */
    { R[31] = 0x800D06C4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D06BC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D06D0; } }  /* 0x800D06C4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D06CC */
L_800D06D0:;
    R[5] = lw_(R[17] + 588);  /* 0x800D06D0 */
    { R[31] = 0x800D06DCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D06D4 jal */
L_800D06DC:;
    R[31] = lw_(R[29] + 36);  /* 0x800D06DC */
    R[18] = lw_(R[29] + 32);  /* 0x800D06E0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D06E4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D06E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D06EC jr ra */
}

void g0_800D04E4(void) {
    { uint32_t _c = ((int32_t)R[2] < 0); R[4] = R[0] + 8; if (_c) { goto L_800D05B4; } }  /* 0x800D04E4 */
    R[5] = lh_(R[17] + 2);  /* 0x800D04EC */
    { R[31] = 0x800D04F8u; R[4] = R[0] + 58; psx_next = 0x8002DAE8u; return; }  /* 0x800D04F0 jal */
    R[3] = lw_(R[16]);  /* 0x800D04F8 */
    R[2] = lb_(R[3] + 789);  /* 0x800D0500 */
    R[5] = 0x800Fu << 16;  /* 0x800D0504 */
    R[2] = R[2] | 0x2;  /* 0x800D0508 */
    sb_(R[3] + 789, R[2]);  /* 0x800D050C */
    R[4] = lw_(R[16]);  /* 0x800D0510 */
    R[6] = lb_(R[17] + 585);  /* 0x800D0514 */
    { R[31] = 0x800D0520u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800D0518 jal */
    R[2] = lw_(R[16]);  /* 0x800D0520 */
    sw_(R[17] + 608, R[18]);  /* 0x800D0524 */
    sw_(R[17] + 588, R[2]);  /* 0x800D0528 */
    R[2] = lw_(R[16]);  /* 0x800D052C */
    R[4] = (uint32_t)(int16_t)lh_(R[2] + 10);  /* 0x800D0534 */
    { R[31] = 0x800D0540u; psx_next = 0x800A3028u; return; }  /* 0x800D0538 jal */
    R[4] = R[0] + 25;  /* 0x800D0540 */
    { R[31] = 0x800D054Cu; R[16] = R[2] + R[0]; psx_next = 0x80023E24u; return; }  /* 0x800D0544 jal */
    R[2] = R[2] + 1;  /* 0x800D054C */
    R[3] = R[2] << 1;  /* 0x800D0550 */
    R[3] = R[3] + R[2];  /* 0x800D0554 */
    R[2] = R[3] << 4;  /* 0x800D0558 */
    R[3] = R[2] - R[3];  /* 0x800D055C */
    R[2] = R[3] << 1;  /* 0x800D0560 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0564 */
    R[4] = lb_(R[16]);  /* 0x800D0568 */
    R[2] = R[0] + 1;  /* 0x800D056C */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[3] << 17; if (_c) { goto L_800D0580; } }  /* 0x800D0570 */
    { R[2] = (uint32_t)((int32_t)R[2] >> 17); goto L_800D0594; }  /* 0x800D0578 j */
L_800D0580:;
    R[2] = R[0] + 3;  /* 0x800D0580 */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800D059C; } }  /* 0x800D0584 */
    R[2] = R[3] << 17;  /* 0x800D058C */
    R[2] = (uint32_t)((int32_t)R[2] >> 15);  /* 0x800D0590 */
L_800D0594:;
    sh_(R[17] + 582, R[2]);  /* 0x800D0594 */
    R[2] = R[0] + 1;  /* 0x800D0598 */
L_800D059C:;
    { sb_(R[17] + 584, R[2]); goto L_800D05C0; }  /* 0x800D059C j */
    R[2] = lb_(R[17] + 785);  /* 0x800D05A4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 8; if (_c) { goto L_800D05DC; } }  /* 0x800D05AC */
L_800D05B4:;
    R[2] = R[0] + 2;  /* 0x800D05B4 */
    sb_(R[17] + 584, R[2]);  /* 0x800D05B8 */
    sh_(R[17] + 582, R[4]);  /* 0x800D05BC */
L_800D05C0:;
    R[4] = R[17] + R[0];  /* 0x800D05C0 */
    R[2] = R[0] + 3;  /* 0x800D05C4 */
    { R[31] = 0x800D05D0u; sb_(R[17] + 786, R[2]); psx_next = 0x800A9EB4u; return; }  /* 0x800D05C8 jal */
    R[2] = R[0] + 4;  /* 0x800D05D0 */
    { sb_(R[17] + 790, R[2]); goto L_800D06DC; }  /* 0x800D05D4 j */
L_800D05DC:;
    { R[31] = 0x800D05E4u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D05DC jal */
    R[4] = R[17] + R[0];  /* 0x800D05E4 */
    R[5] = R[0] + 5;  /* 0x800D05E8 */
    { R[31] = 0x800D05F4u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D05EC jal */
    { goto L_800D06DC; }  /* 0x800D05F4 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D05FC */
    R[2] = R[2] - 1;  /* 0x800D0604 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0608 */
    R[2] = R[2] << 16;  /* 0x800D060C */
    { uint32_t _c = ((int32_t)R[2] > 0); R[4] = R[0] + 58; if (_c) { goto L_800D066C; } }  /* 0x800D0610 */
    R[5] = lh_(R[17] + 2);  /* 0x800D0618 */
    R[2] = R[0] + 3;  /* 0x800D061C */
    { R[31] = 0x800D0628u; sb_(R[17] + 790, R[2]); psx_next = 0x8002CF6Cu; return; }  /* 0x800D0620 jal */
    R[5] = R[0] + 1;  /* 0x800D0628 */
    R[6] = R[5] + R[0];  /* 0x800D062C */
    R[4] = 0x8014u << 16;  /* 0x800D0630 */
    R[2] = lb_(R[17] + 585);  /* 0x800D0634 */
    R[4] = R[4] + 15136;  /* 0x800D0638 */
    R[2] = R[2] << 2;  /* 0x800D063C */
    { R[31] = 0x800D0648u; R[4] = R[2] + R[4]; psx_next = 0x800CD028u; return; }  /* 0x800D0640 jal */
    R[3] = 0x8014u << 16;  /* 0x800D0648 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D064C */
    R[2] = R[2] - 1;  /* 0x800D0654 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D06DC; } }  /* 0x800D0658 */
    R[2] = 0x8013u << 16;  /* 0x800D0660 */
    { sh_(R[2] + -29614, R[0]); goto L_800D06DC; }  /* 0x800D0664 j */
L_800D066C:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D066C */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D06A0; } }  /* 0x800D0674 */
    R[2] = lh_(R[17] + 60);  /* 0x800D067C */
    R[4] = lh_(R[17] + 594);  /* 0x800D0680 */
    R[3] = lh_(R[17] + 62);  /* 0x800D0684 */
    R[5] = R[4] + R[0];  /* 0x800D0688 */
    R[2] = R[2] - R[4];  /* 0x800D068C */
    R[3] = R[3] - R[5];  /* 0x800D0690 */
    sh_(R[17] + 60, R[2]);  /* 0x800D0694 */
    { sh_(R[17] + 62, R[3]); goto L_800D06DC; }  /* 0x800D0698 j */
L_800D06A0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D06DC; } }  /* 0x800D06A0 */
    R[6] = R[0] + 1;  /* 0x800D06A8 */
    R[4] = 0x8014u << 16;  /* 0x800D06AC */
    R[2] = lb_(R[17] + 585);  /* 0x800D06B0 */
    R[4] = R[4] + 15136;  /* 0x800D06B4 */
    R[2] = R[2] << 2;  /* 0x800D06B8 */
    { R[31] = 0x800D06C4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D06BC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D06D0; } }  /* 0x800D06C4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D06CC */
L_800D06D0:;
    R[5] = lw_(R[17] + 588);  /* 0x800D06D0 */
    { R[31] = 0x800D06DCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D06D4 jal */
L_800D06DC:;
    R[31] = lw_(R[29] + 36);  /* 0x800D06DC */
    R[18] = lw_(R[29] + 32);  /* 0x800D06E0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D06E4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D06E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D06EC jr ra */
}

void g0_800D04F8(void) {
    R[3] = lw_(R[16]);  /* 0x800D04F8 */
    R[2] = lb_(R[3] + 789);  /* 0x800D0500 */
    R[5] = 0x800Fu << 16;  /* 0x800D0504 */
    R[2] = R[2] | 0x2;  /* 0x800D0508 */
    sb_(R[3] + 789, R[2]);  /* 0x800D050C */
    R[4] = lw_(R[16]);  /* 0x800D0510 */
    R[6] = lb_(R[17] + 585);  /* 0x800D0514 */
    { R[31] = 0x800D0520u; R[5] = R[5] - 396; psx_next = 0x800CDA50u; return; }  /* 0x800D0518 jal */
    R[2] = lw_(R[16]);  /* 0x800D0520 */
    sw_(R[17] + 608, R[18]);  /* 0x800D0524 */
    sw_(R[17] + 588, R[2]);  /* 0x800D0528 */
    R[2] = lw_(R[16]);  /* 0x800D052C */
    R[4] = (uint32_t)(int16_t)lh_(R[2] + 10);  /* 0x800D0534 */
    { R[31] = 0x800D0540u; psx_next = 0x800A3028u; return; }  /* 0x800D0538 jal */
    R[4] = R[0] + 25;  /* 0x800D0540 */
    { R[31] = 0x800D054Cu; R[16] = R[2] + R[0]; psx_next = 0x80023E24u; return; }  /* 0x800D0544 jal */
    R[2] = R[2] + 1;  /* 0x800D054C */
    R[3] = R[2] << 1;  /* 0x800D0550 */
    R[3] = R[3] + R[2];  /* 0x800D0554 */
    R[2] = R[3] << 4;  /* 0x800D0558 */
    R[3] = R[2] - R[3];  /* 0x800D055C */
    R[2] = R[3] << 1;  /* 0x800D0560 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0564 */
    R[4] = lb_(R[16]);  /* 0x800D0568 */
    R[2] = R[0] + 1;  /* 0x800D056C */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[3] << 17; if (_c) { goto L_800D0580; } }  /* 0x800D0570 */
    { R[2] = (uint32_t)((int32_t)R[2] >> 17); goto L_800D0594; }  /* 0x800D0578 j */
L_800D0580:;
    R[2] = R[0] + 3;  /* 0x800D0580 */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800D059C; } }  /* 0x800D0584 */
    R[2] = R[3] << 17;  /* 0x800D058C */
    R[2] = (uint32_t)((int32_t)R[2] >> 15);  /* 0x800D0590 */
L_800D0594:;
    sh_(R[17] + 582, R[2]);  /* 0x800D0594 */
    R[2] = R[0] + 1;  /* 0x800D0598 */
L_800D059C:;
    { sb_(R[17] + 584, R[2]); goto L_800D05C0; }  /* 0x800D059C j */
    R[2] = lb_(R[17] + 785);  /* 0x800D05A4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 8; if (_c) { goto L_800D05DC; } }  /* 0x800D05AC */
    R[2] = R[0] + 2;  /* 0x800D05B4 */
    sb_(R[17] + 584, R[2]);  /* 0x800D05B8 */
    sh_(R[17] + 582, R[4]);  /* 0x800D05BC */
L_800D05C0:;
    R[4] = R[17] + R[0];  /* 0x800D05C0 */
    R[2] = R[0] + 3;  /* 0x800D05C4 */
    { R[31] = 0x800D05D0u; sb_(R[17] + 786, R[2]); psx_next = 0x800A9EB4u; return; }  /* 0x800D05C8 jal */
    R[2] = R[0] + 4;  /* 0x800D05D0 */
    { sb_(R[17] + 790, R[2]); goto L_800D06DC; }  /* 0x800D05D4 j */
L_800D05DC:;
    { R[31] = 0x800D05E4u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D05DC jal */
    R[4] = R[17] + R[0];  /* 0x800D05E4 */
    R[5] = R[0] + 5;  /* 0x800D05E8 */
    { R[31] = 0x800D05F4u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D05EC jal */
    { goto L_800D06DC; }  /* 0x800D05F4 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D05FC */
    R[2] = R[2] - 1;  /* 0x800D0604 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0608 */
    R[2] = R[2] << 16;  /* 0x800D060C */
    { uint32_t _c = ((int32_t)R[2] > 0); R[4] = R[0] + 58; if (_c) { goto L_800D066C; } }  /* 0x800D0610 */
    R[5] = lh_(R[17] + 2);  /* 0x800D0618 */
    R[2] = R[0] + 3;  /* 0x800D061C */
    { R[31] = 0x800D0628u; sb_(R[17] + 790, R[2]); psx_next = 0x8002CF6Cu; return; }  /* 0x800D0620 jal */
    R[5] = R[0] + 1;  /* 0x800D0628 */
    R[6] = R[5] + R[0];  /* 0x800D062C */
    R[4] = 0x8014u << 16;  /* 0x800D0630 */
    R[2] = lb_(R[17] + 585);  /* 0x800D0634 */
    R[4] = R[4] + 15136;  /* 0x800D0638 */
    R[2] = R[2] << 2;  /* 0x800D063C */
    { R[31] = 0x800D0648u; R[4] = R[2] + R[4]; psx_next = 0x800CD028u; return; }  /* 0x800D0640 jal */
    R[3] = 0x8014u << 16;  /* 0x800D0648 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D064C */
    R[2] = R[2] - 1;  /* 0x800D0654 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D06DC; } }  /* 0x800D0658 */
    R[2] = 0x8013u << 16;  /* 0x800D0660 */
    { sh_(R[2] + -29614, R[0]); goto L_800D06DC; }  /* 0x800D0664 j */
L_800D066C:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D066C */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D06A0; } }  /* 0x800D0674 */
    R[2] = lh_(R[17] + 60);  /* 0x800D067C */
    R[4] = lh_(R[17] + 594);  /* 0x800D0680 */
    R[3] = lh_(R[17] + 62);  /* 0x800D0684 */
    R[5] = R[4] + R[0];  /* 0x800D0688 */
    R[2] = R[2] - R[4];  /* 0x800D068C */
    R[3] = R[3] - R[5];  /* 0x800D0690 */
    sh_(R[17] + 60, R[2]);  /* 0x800D0694 */
    { sh_(R[17] + 62, R[3]); goto L_800D06DC; }  /* 0x800D0698 j */
L_800D06A0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D06DC; } }  /* 0x800D06A0 */
    R[6] = R[0] + 1;  /* 0x800D06A8 */
    R[4] = 0x8014u << 16;  /* 0x800D06AC */
    R[2] = lb_(R[17] + 585);  /* 0x800D06B0 */
    R[4] = R[4] + 15136;  /* 0x800D06B4 */
    R[2] = R[2] << 2;  /* 0x800D06B8 */
    { R[31] = 0x800D06C4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D06BC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D06D0; } }  /* 0x800D06C4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D06CC */
L_800D06D0:;
    R[5] = lw_(R[17] + 588);  /* 0x800D06D0 */
    { R[31] = 0x800D06DCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D06D4 jal */
L_800D06DC:;
    R[31] = lw_(R[29] + 36);  /* 0x800D06DC */
    R[18] = lw_(R[29] + 32);  /* 0x800D06E0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D06E4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D06E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D06EC jr ra */
}

void g0_800D0520(void) {
    R[2] = lw_(R[16]);  /* 0x800D0520 */
    sw_(R[17] + 608, R[18]);  /* 0x800D0524 */
    sw_(R[17] + 588, R[2]);  /* 0x800D0528 */
    R[2] = lw_(R[16]);  /* 0x800D052C */
    R[4] = (uint32_t)(int16_t)lh_(R[2] + 10);  /* 0x800D0534 */
    { R[31] = 0x800D0540u; psx_next = 0x800A3028u; return; }  /* 0x800D0538 jal */
    R[4] = R[0] + 25;  /* 0x800D0540 */
    { R[31] = 0x800D054Cu; R[16] = R[2] + R[0]; psx_next = 0x80023E24u; return; }  /* 0x800D0544 jal */
    R[2] = R[2] + 1;  /* 0x800D054C */
    R[3] = R[2] << 1;  /* 0x800D0550 */
    R[3] = R[3] + R[2];  /* 0x800D0554 */
    R[2] = R[3] << 4;  /* 0x800D0558 */
    R[3] = R[2] - R[3];  /* 0x800D055C */
    R[2] = R[3] << 1;  /* 0x800D0560 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0564 */
    R[4] = lb_(R[16]);  /* 0x800D0568 */
    R[2] = R[0] + 1;  /* 0x800D056C */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[3] << 17; if (_c) { goto L_800D0580; } }  /* 0x800D0570 */
    { R[2] = (uint32_t)((int32_t)R[2] >> 17); goto L_800D0594; }  /* 0x800D0578 j */
L_800D0580:;
    R[2] = R[0] + 3;  /* 0x800D0580 */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800D059C; } }  /* 0x800D0584 */
    R[2] = R[3] << 17;  /* 0x800D058C */
    R[2] = (uint32_t)((int32_t)R[2] >> 15);  /* 0x800D0590 */
L_800D0594:;
    sh_(R[17] + 582, R[2]);  /* 0x800D0594 */
    R[2] = R[0] + 1;  /* 0x800D0598 */
L_800D059C:;
    { sb_(R[17] + 584, R[2]); goto L_800D05C0; }  /* 0x800D059C j */
    R[2] = lb_(R[17] + 785);  /* 0x800D05A4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 8; if (_c) { goto L_800D05DC; } }  /* 0x800D05AC */
    R[2] = R[0] + 2;  /* 0x800D05B4 */
    sb_(R[17] + 584, R[2]);  /* 0x800D05B8 */
    sh_(R[17] + 582, R[4]);  /* 0x800D05BC */
L_800D05C0:;
    R[4] = R[17] + R[0];  /* 0x800D05C0 */
    R[2] = R[0] + 3;  /* 0x800D05C4 */
    { R[31] = 0x800D05D0u; sb_(R[17] + 786, R[2]); psx_next = 0x800A9EB4u; return; }  /* 0x800D05C8 jal */
    R[2] = R[0] + 4;  /* 0x800D05D0 */
    { sb_(R[17] + 790, R[2]); goto L_800D06DC; }  /* 0x800D05D4 j */
L_800D05DC:;
    { R[31] = 0x800D05E4u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D05DC jal */
    R[4] = R[17] + R[0];  /* 0x800D05E4 */
    R[5] = R[0] + 5;  /* 0x800D05E8 */
    { R[31] = 0x800D05F4u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D05EC jal */
    { goto L_800D06DC; }  /* 0x800D05F4 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D05FC */
    R[2] = R[2] - 1;  /* 0x800D0604 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0608 */
    R[2] = R[2] << 16;  /* 0x800D060C */
    { uint32_t _c = ((int32_t)R[2] > 0); R[4] = R[0] + 58; if (_c) { goto L_800D066C; } }  /* 0x800D0610 */
    R[5] = lh_(R[17] + 2);  /* 0x800D0618 */
    R[2] = R[0] + 3;  /* 0x800D061C */
    { R[31] = 0x800D0628u; sb_(R[17] + 790, R[2]); psx_next = 0x8002CF6Cu; return; }  /* 0x800D0620 jal */
    R[5] = R[0] + 1;  /* 0x800D0628 */
    R[6] = R[5] + R[0];  /* 0x800D062C */
    R[4] = 0x8014u << 16;  /* 0x800D0630 */
    R[2] = lb_(R[17] + 585);  /* 0x800D0634 */
    R[4] = R[4] + 15136;  /* 0x800D0638 */
    R[2] = R[2] << 2;  /* 0x800D063C */
    { R[31] = 0x800D0648u; R[4] = R[2] + R[4]; psx_next = 0x800CD028u; return; }  /* 0x800D0640 jal */
    R[3] = 0x8014u << 16;  /* 0x800D0648 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D064C */
    R[2] = R[2] - 1;  /* 0x800D0654 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D06DC; } }  /* 0x800D0658 */
    R[2] = 0x8013u << 16;  /* 0x800D0660 */
    { sh_(R[2] + -29614, R[0]); goto L_800D06DC; }  /* 0x800D0664 j */
L_800D066C:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D066C */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D06A0; } }  /* 0x800D0674 */
    R[2] = lh_(R[17] + 60);  /* 0x800D067C */
    R[4] = lh_(R[17] + 594);  /* 0x800D0680 */
    R[3] = lh_(R[17] + 62);  /* 0x800D0684 */
    R[5] = R[4] + R[0];  /* 0x800D0688 */
    R[2] = R[2] - R[4];  /* 0x800D068C */
    R[3] = R[3] - R[5];  /* 0x800D0690 */
    sh_(R[17] + 60, R[2]);  /* 0x800D0694 */
    { sh_(R[17] + 62, R[3]); goto L_800D06DC; }  /* 0x800D0698 j */
L_800D06A0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D06DC; } }  /* 0x800D06A0 */
    R[6] = R[0] + 1;  /* 0x800D06A8 */
    R[4] = 0x8014u << 16;  /* 0x800D06AC */
    R[2] = lb_(R[17] + 585);  /* 0x800D06B0 */
    R[4] = R[4] + 15136;  /* 0x800D06B4 */
    R[2] = R[2] << 2;  /* 0x800D06B8 */
    { R[31] = 0x800D06C4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D06BC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D06D0; } }  /* 0x800D06C4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D06CC */
L_800D06D0:;
    R[5] = lw_(R[17] + 588);  /* 0x800D06D0 */
    { R[31] = 0x800D06DCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D06D4 jal */
L_800D06DC:;
    R[31] = lw_(R[29] + 36);  /* 0x800D06DC */
    R[18] = lw_(R[29] + 32);  /* 0x800D06E0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D06E4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D06E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D06EC jr ra */
}

void g0_800D0540(void) {
    R[4] = R[0] + 25;  /* 0x800D0540 */
    { R[31] = 0x800D054Cu; R[16] = R[2] + R[0]; psx_next = 0x80023E24u; return; }  /* 0x800D0544 jal */
    R[2] = R[2] + 1;  /* 0x800D054C */
    R[3] = R[2] << 1;  /* 0x800D0550 */
    R[3] = R[3] + R[2];  /* 0x800D0554 */
    R[2] = R[3] << 4;  /* 0x800D0558 */
    R[3] = R[2] - R[3];  /* 0x800D055C */
    R[2] = R[3] << 1;  /* 0x800D0560 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0564 */
    R[4] = lb_(R[16]);  /* 0x800D0568 */
    R[2] = R[0] + 1;  /* 0x800D056C */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[3] << 17; if (_c) { goto L_800D0580; } }  /* 0x800D0570 */
    { R[2] = (uint32_t)((int32_t)R[2] >> 17); goto L_800D0594; }  /* 0x800D0578 j */
L_800D0580:;
    R[2] = R[0] + 3;  /* 0x800D0580 */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800D059C; } }  /* 0x800D0584 */
    R[2] = R[3] << 17;  /* 0x800D058C */
    R[2] = (uint32_t)((int32_t)R[2] >> 15);  /* 0x800D0590 */
L_800D0594:;
    sh_(R[17] + 582, R[2]);  /* 0x800D0594 */
    R[2] = R[0] + 1;  /* 0x800D0598 */
L_800D059C:;
    { sb_(R[17] + 584, R[2]); goto L_800D05C0; }  /* 0x800D059C j */
    R[2] = lb_(R[17] + 785);  /* 0x800D05A4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 8; if (_c) { goto L_800D05DC; } }  /* 0x800D05AC */
    R[2] = R[0] + 2;  /* 0x800D05B4 */
    sb_(R[17] + 584, R[2]);  /* 0x800D05B8 */
    sh_(R[17] + 582, R[4]);  /* 0x800D05BC */
L_800D05C0:;
    R[4] = R[17] + R[0];  /* 0x800D05C0 */
    R[2] = R[0] + 3;  /* 0x800D05C4 */
    { R[31] = 0x800D05D0u; sb_(R[17] + 786, R[2]); psx_next = 0x800A9EB4u; return; }  /* 0x800D05C8 jal */
    R[2] = R[0] + 4;  /* 0x800D05D0 */
    { sb_(R[17] + 790, R[2]); goto L_800D06DC; }  /* 0x800D05D4 j */
L_800D05DC:;
    { R[31] = 0x800D05E4u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D05DC jal */
    R[4] = R[17] + R[0];  /* 0x800D05E4 */
    R[5] = R[0] + 5;  /* 0x800D05E8 */
    { R[31] = 0x800D05F4u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D05EC jal */
    { goto L_800D06DC; }  /* 0x800D05F4 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D05FC */
    R[2] = R[2] - 1;  /* 0x800D0604 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0608 */
    R[2] = R[2] << 16;  /* 0x800D060C */
    { uint32_t _c = ((int32_t)R[2] > 0); R[4] = R[0] + 58; if (_c) { goto L_800D066C; } }  /* 0x800D0610 */
    R[5] = lh_(R[17] + 2);  /* 0x800D0618 */
    R[2] = R[0] + 3;  /* 0x800D061C */
    { R[31] = 0x800D0628u; sb_(R[17] + 790, R[2]); psx_next = 0x8002CF6Cu; return; }  /* 0x800D0620 jal */
    R[5] = R[0] + 1;  /* 0x800D0628 */
    R[6] = R[5] + R[0];  /* 0x800D062C */
    R[4] = 0x8014u << 16;  /* 0x800D0630 */
    R[2] = lb_(R[17] + 585);  /* 0x800D0634 */
    R[4] = R[4] + 15136;  /* 0x800D0638 */
    R[2] = R[2] << 2;  /* 0x800D063C */
    { R[31] = 0x800D0648u; R[4] = R[2] + R[4]; psx_next = 0x800CD028u; return; }  /* 0x800D0640 jal */
    R[3] = 0x8014u << 16;  /* 0x800D0648 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D064C */
    R[2] = R[2] - 1;  /* 0x800D0654 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D06DC; } }  /* 0x800D0658 */
    R[2] = 0x8013u << 16;  /* 0x800D0660 */
    { sh_(R[2] + -29614, R[0]); goto L_800D06DC; }  /* 0x800D0664 j */
L_800D066C:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D066C */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D06A0; } }  /* 0x800D0674 */
    R[2] = lh_(R[17] + 60);  /* 0x800D067C */
    R[4] = lh_(R[17] + 594);  /* 0x800D0680 */
    R[3] = lh_(R[17] + 62);  /* 0x800D0684 */
    R[5] = R[4] + R[0];  /* 0x800D0688 */
    R[2] = R[2] - R[4];  /* 0x800D068C */
    R[3] = R[3] - R[5];  /* 0x800D0690 */
    sh_(R[17] + 60, R[2]);  /* 0x800D0694 */
    { sh_(R[17] + 62, R[3]); goto L_800D06DC; }  /* 0x800D0698 j */
L_800D06A0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D06DC; } }  /* 0x800D06A0 */
    R[6] = R[0] + 1;  /* 0x800D06A8 */
    R[4] = 0x8014u << 16;  /* 0x800D06AC */
    R[2] = lb_(R[17] + 585);  /* 0x800D06B0 */
    R[4] = R[4] + 15136;  /* 0x800D06B4 */
    R[2] = R[2] << 2;  /* 0x800D06B8 */
    { R[31] = 0x800D06C4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D06BC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D06D0; } }  /* 0x800D06C4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D06CC */
L_800D06D0:;
    R[5] = lw_(R[17] + 588);  /* 0x800D06D0 */
    { R[31] = 0x800D06DCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D06D4 jal */
L_800D06DC:;
    R[31] = lw_(R[29] + 36);  /* 0x800D06DC */
    R[18] = lw_(R[29] + 32);  /* 0x800D06E0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D06E4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D06E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D06EC jr ra */
}

void g0_800D054C(void) {
    R[2] = R[2] + 1;  /* 0x800D054C */
    R[3] = R[2] << 1;  /* 0x800D0550 */
    R[3] = R[3] + R[2];  /* 0x800D0554 */
    R[2] = R[3] << 4;  /* 0x800D0558 */
    R[3] = R[2] - R[3];  /* 0x800D055C */
    R[2] = R[3] << 1;  /* 0x800D0560 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0564 */
    R[4] = lb_(R[16]);  /* 0x800D0568 */
    R[2] = R[0] + 1;  /* 0x800D056C */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[3] << 17; if (_c) { goto L_800D0580; } }  /* 0x800D0570 */
    { R[2] = (uint32_t)((int32_t)R[2] >> 17); goto L_800D0594; }  /* 0x800D0578 j */
L_800D0580:;
    R[2] = R[0] + 3;  /* 0x800D0580 */
    { uint32_t _c = (R[4] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800D059C; } }  /* 0x800D0584 */
    R[2] = R[3] << 17;  /* 0x800D058C */
    R[2] = (uint32_t)((int32_t)R[2] >> 15);  /* 0x800D0590 */
L_800D0594:;
    sh_(R[17] + 582, R[2]);  /* 0x800D0594 */
    R[2] = R[0] + 1;  /* 0x800D0598 */
L_800D059C:;
    { sb_(R[17] + 584, R[2]); goto L_800D05C0; }  /* 0x800D059C j */
    R[2] = lb_(R[17] + 785);  /* 0x800D05A4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 8; if (_c) { goto L_800D05DC; } }  /* 0x800D05AC */
    R[2] = R[0] + 2;  /* 0x800D05B4 */
    sb_(R[17] + 584, R[2]);  /* 0x800D05B8 */
    sh_(R[17] + 582, R[4]);  /* 0x800D05BC */
L_800D05C0:;
    R[4] = R[17] + R[0];  /* 0x800D05C0 */
    R[2] = R[0] + 3;  /* 0x800D05C4 */
    { R[31] = 0x800D05D0u; sb_(R[17] + 786, R[2]); psx_next = 0x800A9EB4u; return; }  /* 0x800D05C8 jal */
    R[2] = R[0] + 4;  /* 0x800D05D0 */
    { sb_(R[17] + 790, R[2]); goto L_800D06DC; }  /* 0x800D05D4 j */
L_800D05DC:;
    { R[31] = 0x800D05E4u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D05DC jal */
    R[4] = R[17] + R[0];  /* 0x800D05E4 */
    R[5] = R[0] + 5;  /* 0x800D05E8 */
    { R[31] = 0x800D05F4u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D05EC jal */
    { goto L_800D06DC; }  /* 0x800D05F4 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D05FC */
    R[2] = R[2] - 1;  /* 0x800D0604 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0608 */
    R[2] = R[2] << 16;  /* 0x800D060C */
    { uint32_t _c = ((int32_t)R[2] > 0); R[4] = R[0] + 58; if (_c) { goto L_800D066C; } }  /* 0x800D0610 */
    R[5] = lh_(R[17] + 2);  /* 0x800D0618 */
    R[2] = R[0] + 3;  /* 0x800D061C */
    { R[31] = 0x800D0628u; sb_(R[17] + 790, R[2]); psx_next = 0x8002CF6Cu; return; }  /* 0x800D0620 jal */
    R[5] = R[0] + 1;  /* 0x800D0628 */
    R[6] = R[5] + R[0];  /* 0x800D062C */
    R[4] = 0x8014u << 16;  /* 0x800D0630 */
    R[2] = lb_(R[17] + 585);  /* 0x800D0634 */
    R[4] = R[4] + 15136;  /* 0x800D0638 */
    R[2] = R[2] << 2;  /* 0x800D063C */
    { R[31] = 0x800D0648u; R[4] = R[2] + R[4]; psx_next = 0x800CD028u; return; }  /* 0x800D0640 jal */
    R[3] = 0x8014u << 16;  /* 0x800D0648 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D064C */
    R[2] = R[2] - 1;  /* 0x800D0654 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D06DC; } }  /* 0x800D0658 */
    R[2] = 0x8013u << 16;  /* 0x800D0660 */
    { sh_(R[2] + -29614, R[0]); goto L_800D06DC; }  /* 0x800D0664 j */
L_800D066C:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D066C */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D06A0; } }  /* 0x800D0674 */
    R[2] = lh_(R[17] + 60);  /* 0x800D067C */
    R[4] = lh_(R[17] + 594);  /* 0x800D0680 */
    R[3] = lh_(R[17] + 62);  /* 0x800D0684 */
    R[5] = R[4] + R[0];  /* 0x800D0688 */
    R[2] = R[2] - R[4];  /* 0x800D068C */
    R[3] = R[3] - R[5];  /* 0x800D0690 */
    sh_(R[17] + 60, R[2]);  /* 0x800D0694 */
    { sh_(R[17] + 62, R[3]); goto L_800D06DC; }  /* 0x800D0698 j */
L_800D06A0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D06DC; } }  /* 0x800D06A0 */
    R[6] = R[0] + 1;  /* 0x800D06A8 */
    R[4] = 0x8014u << 16;  /* 0x800D06AC */
    R[2] = lb_(R[17] + 585);  /* 0x800D06B0 */
    R[4] = R[4] + 15136;  /* 0x800D06B4 */
    R[2] = R[2] << 2;  /* 0x800D06B8 */
    { R[31] = 0x800D06C4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D06BC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D06D0; } }  /* 0x800D06C4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D06CC */
L_800D06D0:;
    R[5] = lw_(R[17] + 588);  /* 0x800D06D0 */
    { R[31] = 0x800D06DCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D06D4 jal */
L_800D06DC:;
    R[31] = lw_(R[29] + 36);  /* 0x800D06DC */
    R[18] = lw_(R[29] + 32);  /* 0x800D06E0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D06E4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D06E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D06EC jr ra */
}

void g0_800D05D0(void) {
    R[2] = R[0] + 4;  /* 0x800D05D0 */
    { sb_(R[17] + 790, R[2]); goto L_800D06DC; }  /* 0x800D05D4 j */
    { R[31] = 0x800D05E4u; R[4] = R[17] + R[0]; psx_next = 0x800CD900u; return; }  /* 0x800D05DC jal */
    R[4] = R[17] + R[0];  /* 0x800D05E4 */
    R[5] = R[0] + 5;  /* 0x800D05E8 */
    { R[31] = 0x800D05F4u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D05EC jal */
    { goto L_800D06DC; }  /* 0x800D05F4 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D05FC */
    R[2] = R[2] - 1;  /* 0x800D0604 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0608 */
    R[2] = R[2] << 16;  /* 0x800D060C */
    { uint32_t _c = ((int32_t)R[2] > 0); R[4] = R[0] + 58; if (_c) { goto L_800D066C; } }  /* 0x800D0610 */
    R[5] = lh_(R[17] + 2);  /* 0x800D0618 */
    R[2] = R[0] + 3;  /* 0x800D061C */
    { R[31] = 0x800D0628u; sb_(R[17] + 790, R[2]); psx_next = 0x8002CF6Cu; return; }  /* 0x800D0620 jal */
    R[5] = R[0] + 1;  /* 0x800D0628 */
    R[6] = R[5] + R[0];  /* 0x800D062C */
    R[4] = 0x8014u << 16;  /* 0x800D0630 */
    R[2] = lb_(R[17] + 585);  /* 0x800D0634 */
    R[4] = R[4] + 15136;  /* 0x800D0638 */
    R[2] = R[2] << 2;  /* 0x800D063C */
    { R[31] = 0x800D0648u; R[4] = R[2] + R[4]; psx_next = 0x800CD028u; return; }  /* 0x800D0640 jal */
    R[3] = 0x8014u << 16;  /* 0x800D0648 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D064C */
    R[2] = R[2] - 1;  /* 0x800D0654 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D06DC; } }  /* 0x800D0658 */
    R[2] = 0x8013u << 16;  /* 0x800D0660 */
    { sh_(R[2] + -29614, R[0]); goto L_800D06DC; }  /* 0x800D0664 j */
L_800D066C:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D066C */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D06A0; } }  /* 0x800D0674 */
    R[2] = lh_(R[17] + 60);  /* 0x800D067C */
    R[4] = lh_(R[17] + 594);  /* 0x800D0680 */
    R[3] = lh_(R[17] + 62);  /* 0x800D0684 */
    R[5] = R[4] + R[0];  /* 0x800D0688 */
    R[2] = R[2] - R[4];  /* 0x800D068C */
    R[3] = R[3] - R[5];  /* 0x800D0690 */
    sh_(R[17] + 60, R[2]);  /* 0x800D0694 */
    { sh_(R[17] + 62, R[3]); goto L_800D06DC; }  /* 0x800D0698 j */
L_800D06A0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D06DC; } }  /* 0x800D06A0 */
    R[6] = R[0] + 1;  /* 0x800D06A8 */
    R[4] = 0x8014u << 16;  /* 0x800D06AC */
    R[2] = lb_(R[17] + 585);  /* 0x800D06B0 */
    R[4] = R[4] + 15136;  /* 0x800D06B4 */
    R[2] = R[2] << 2;  /* 0x800D06B8 */
    { R[31] = 0x800D06C4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D06BC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D06D0; } }  /* 0x800D06C4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D06CC */
L_800D06D0:;
    R[5] = lw_(R[17] + 588);  /* 0x800D06D0 */
    { R[31] = 0x800D06DCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D06D4 jal */
L_800D06DC:;
    R[31] = lw_(R[29] + 36);  /* 0x800D06DC */
    R[18] = lw_(R[29] + 32);  /* 0x800D06E0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D06E4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D06E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D06EC jr ra */
}

void g0_800D05E4(void) {
    R[4] = R[17] + R[0];  /* 0x800D05E4 */
    R[5] = R[0] + 5;  /* 0x800D05E8 */
    { R[31] = 0x800D05F4u; R[6] = R[0] | 0xA000; psx_next = 0x800CE35Cu; return; }  /* 0x800D05EC jal */
    { goto L_800D06DC; }  /* 0x800D05F4 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D05FC */
    R[2] = R[2] - 1;  /* 0x800D0604 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0608 */
    R[2] = R[2] << 16;  /* 0x800D060C */
    { uint32_t _c = ((int32_t)R[2] > 0); R[4] = R[0] + 58; if (_c) { goto L_800D066C; } }  /* 0x800D0610 */
    R[5] = lh_(R[17] + 2);  /* 0x800D0618 */
    R[2] = R[0] + 3;  /* 0x800D061C */
    { R[31] = 0x800D0628u; sb_(R[17] + 790, R[2]); psx_next = 0x8002CF6Cu; return; }  /* 0x800D0620 jal */
    R[5] = R[0] + 1;  /* 0x800D0628 */
    R[6] = R[5] + R[0];  /* 0x800D062C */
    R[4] = 0x8014u << 16;  /* 0x800D0630 */
    R[2] = lb_(R[17] + 585);  /* 0x800D0634 */
    R[4] = R[4] + 15136;  /* 0x800D0638 */
    R[2] = R[2] << 2;  /* 0x800D063C */
    { R[31] = 0x800D0648u; R[4] = R[2] + R[4]; psx_next = 0x800CD028u; return; }  /* 0x800D0640 jal */
    R[3] = 0x8014u << 16;  /* 0x800D0648 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D064C */
    R[2] = R[2] - 1;  /* 0x800D0654 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D06DC; } }  /* 0x800D0658 */
    R[2] = 0x8013u << 16;  /* 0x800D0660 */
    { sh_(R[2] + -29614, R[0]); goto L_800D06DC; }  /* 0x800D0664 j */
L_800D066C:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D066C */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D06A0; } }  /* 0x800D0674 */
    R[2] = lh_(R[17] + 60);  /* 0x800D067C */
    R[4] = lh_(R[17] + 594);  /* 0x800D0680 */
    R[3] = lh_(R[17] + 62);  /* 0x800D0684 */
    R[5] = R[4] + R[0];  /* 0x800D0688 */
    R[2] = R[2] - R[4];  /* 0x800D068C */
    R[3] = R[3] - R[5];  /* 0x800D0690 */
    sh_(R[17] + 60, R[2]);  /* 0x800D0694 */
    { sh_(R[17] + 62, R[3]); goto L_800D06DC; }  /* 0x800D0698 j */
L_800D06A0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D06DC; } }  /* 0x800D06A0 */
    R[6] = R[0] + 1;  /* 0x800D06A8 */
    R[4] = 0x8014u << 16;  /* 0x800D06AC */
    R[2] = lb_(R[17] + 585);  /* 0x800D06B0 */
    R[4] = R[4] + 15136;  /* 0x800D06B4 */
    R[2] = R[2] << 2;  /* 0x800D06B8 */
    { R[31] = 0x800D06C4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D06BC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D06D0; } }  /* 0x800D06C4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D06CC */
L_800D06D0:;
    R[5] = lw_(R[17] + 588);  /* 0x800D06D0 */
    { R[31] = 0x800D06DCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D06D4 jal */
L_800D06DC:;
    R[31] = lw_(R[29] + 36);  /* 0x800D06DC */
    R[18] = lw_(R[29] + 32);  /* 0x800D06E0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D06E4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D06E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D06EC jr ra */
}

void g0_800D05F4(void) {
    { goto L_800D06DC; }  /* 0x800D05F4 j */
    R[2] = lh_(R[17] + 582);  /* 0x800D05FC */
    R[2] = R[2] - 1;  /* 0x800D0604 */
    sh_(R[17] + 582, R[2]);  /* 0x800D0608 */
    R[2] = R[2] << 16;  /* 0x800D060C */
    { uint32_t _c = ((int32_t)R[2] > 0); R[4] = R[0] + 58; if (_c) { goto L_800D066C; } }  /* 0x800D0610 */
    R[5] = lh_(R[17] + 2);  /* 0x800D0618 */
    R[2] = R[0] + 3;  /* 0x800D061C */
    { R[31] = 0x800D0628u; sb_(R[17] + 790, R[2]); psx_next = 0x8002CF6Cu; return; }  /* 0x800D0620 jal */
    R[5] = R[0] + 1;  /* 0x800D0628 */
    R[6] = R[5] + R[0];  /* 0x800D062C */
    R[4] = 0x8014u << 16;  /* 0x800D0630 */
    R[2] = lb_(R[17] + 585);  /* 0x800D0634 */
    R[4] = R[4] + 15136;  /* 0x800D0638 */
    R[2] = R[2] << 2;  /* 0x800D063C */
    { R[31] = 0x800D0648u; R[4] = R[2] + R[4]; psx_next = 0x800CD028u; return; }  /* 0x800D0640 jal */
    R[3] = 0x8014u << 16;  /* 0x800D0648 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D064C */
    R[2] = R[2] - 1;  /* 0x800D0654 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D06DC; } }  /* 0x800D0658 */
    R[2] = 0x8013u << 16;  /* 0x800D0660 */
    { sh_(R[2] + -29614, R[0]); goto L_800D06DC; }  /* 0x800D0664 j */
L_800D066C:;
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D066C */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D06A0; } }  /* 0x800D0674 */
    R[2] = lh_(R[17] + 60);  /* 0x800D067C */
    R[4] = lh_(R[17] + 594);  /* 0x800D0680 */
    R[3] = lh_(R[17] + 62);  /* 0x800D0684 */
    R[5] = R[4] + R[0];  /* 0x800D0688 */
    R[2] = R[2] - R[4];  /* 0x800D068C */
    R[3] = R[3] - R[5];  /* 0x800D0690 */
    sh_(R[17] + 60, R[2]);  /* 0x800D0694 */
    { sh_(R[17] + 62, R[3]); goto L_800D06DC; }  /* 0x800D0698 j */
L_800D06A0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D06DC; } }  /* 0x800D06A0 */
    R[6] = R[0] + 1;  /* 0x800D06A8 */
    R[4] = 0x8014u << 16;  /* 0x800D06AC */
    R[2] = lb_(R[17] + 585);  /* 0x800D06B0 */
    R[4] = R[4] + 15136;  /* 0x800D06B4 */
    R[2] = R[2] << 2;  /* 0x800D06B8 */
    { R[31] = 0x800D06C4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D06BC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D06D0; } }  /* 0x800D06C4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D06CC */
L_800D06D0:;
    R[5] = lw_(R[17] + 588);  /* 0x800D06D0 */
    { R[31] = 0x800D06DCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D06D4 jal */
L_800D06DC:;
    R[31] = lw_(R[29] + 36);  /* 0x800D06DC */
    R[18] = lw_(R[29] + 32);  /* 0x800D06E0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D06E4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D06E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D06EC jr ra */
}

void g0_800D0628(void) {
    R[5] = R[0] + 1;  /* 0x800D0628 */
    R[6] = R[5] + R[0];  /* 0x800D062C */
    R[4] = 0x8014u << 16;  /* 0x800D0630 */
    R[2] = lb_(R[17] + 585);  /* 0x800D0634 */
    R[4] = R[4] + 15136;  /* 0x800D0638 */
    R[2] = R[2] << 2;  /* 0x800D063C */
    { R[31] = 0x800D0648u; R[4] = R[2] + R[4]; psx_next = 0x800CD028u; return; }  /* 0x800D0640 jal */
    R[3] = 0x8014u << 16;  /* 0x800D0648 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D064C */
    R[2] = R[2] - 1;  /* 0x800D0654 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D06DC; } }  /* 0x800D0658 */
    R[2] = 0x8013u << 16;  /* 0x800D0660 */
    { sh_(R[2] + -29614, R[0]); goto L_800D06DC; }  /* 0x800D0664 j */
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D066C */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D06A0; } }  /* 0x800D0674 */
    R[2] = lh_(R[17] + 60);  /* 0x800D067C */
    R[4] = lh_(R[17] + 594);  /* 0x800D0680 */
    R[3] = lh_(R[17] + 62);  /* 0x800D0684 */
    R[5] = R[4] + R[0];  /* 0x800D0688 */
    R[2] = R[2] - R[4];  /* 0x800D068C */
    R[3] = R[3] - R[5];  /* 0x800D0690 */
    sh_(R[17] + 60, R[2]);  /* 0x800D0694 */
    { sh_(R[17] + 62, R[3]); goto L_800D06DC; }  /* 0x800D0698 j */
L_800D06A0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D06DC; } }  /* 0x800D06A0 */
    R[6] = R[0] + 1;  /* 0x800D06A8 */
    R[4] = 0x8014u << 16;  /* 0x800D06AC */
    R[2] = lb_(R[17] + 585);  /* 0x800D06B0 */
    R[4] = R[4] + 15136;  /* 0x800D06B4 */
    R[2] = R[2] << 2;  /* 0x800D06B8 */
    { R[31] = 0x800D06C4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D06BC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D06D0; } }  /* 0x800D06C4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D06CC */
L_800D06D0:;
    R[5] = lw_(R[17] + 588);  /* 0x800D06D0 */
    { R[31] = 0x800D06DCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D06D4 jal */
L_800D06DC:;
    R[31] = lw_(R[29] + 36);  /* 0x800D06DC */
    R[18] = lw_(R[29] + 32);  /* 0x800D06E0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D06E4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D06E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D06EC jr ra */
}

void g0_800D0648(void) {
    R[3] = 0x8014u << 16;  /* 0x800D0648 */
    R[2] = lw_(R[3] + 15016);  /* 0x800D064C */
    R[2] = R[2] - 1;  /* 0x800D0654 */
    { uint32_t _c = ((int32_t)R[2] > 0); sw_(R[3] + 15016, R[2]); if (_c) { goto L_800D06DC; } }  /* 0x800D0658 */
    R[2] = 0x8013u << 16;  /* 0x800D0660 */
    { sh_(R[2] + -29614, R[0]); goto L_800D06DC; }  /* 0x800D0664 j */
    R[3] = (uint32_t)(int8_t)lb_(R[17] + 584);  /* 0x800D066C */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_800D06A0; } }  /* 0x800D0674 */
    R[2] = lh_(R[17] + 60);  /* 0x800D067C */
    R[4] = lh_(R[17] + 594);  /* 0x800D0680 */
    R[3] = lh_(R[17] + 62);  /* 0x800D0684 */
    R[5] = R[4] + R[0];  /* 0x800D0688 */
    R[2] = R[2] - R[4];  /* 0x800D068C */
    R[3] = R[3] - R[5];  /* 0x800D0690 */
    sh_(R[17] + 60, R[2]);  /* 0x800D0694 */
    { sh_(R[17] + 62, R[3]); goto L_800D06DC; }  /* 0x800D0698 j */
L_800D06A0:;
    { uint32_t _c = (R[3] != R[2]); R[5] = R[2] + R[0]; if (_c) { goto L_800D06DC; } }  /* 0x800D06A0 */
    R[6] = R[0] + 1;  /* 0x800D06A8 */
    R[4] = 0x8014u << 16;  /* 0x800D06AC */
    R[2] = lb_(R[17] + 585);  /* 0x800D06B0 */
    R[4] = R[4] + 15136;  /* 0x800D06B4 */
    R[2] = R[2] << 2;  /* 0x800D06B8 */
    { R[31] = 0x800D06C4u; R[4] = R[2] + R[4]; psx_next = 0x800CCF94u; return; }  /* 0x800D06BC jal */
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D06D0; } }  /* 0x800D06C4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D06CC */
L_800D06D0:;
    R[5] = lw_(R[17] + 588);  /* 0x800D06D0 */
    { R[31] = 0x800D06DCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D06D4 jal */
L_800D06DC:;
    R[31] = lw_(R[29] + 36);  /* 0x800D06DC */
    R[18] = lw_(R[29] + 32);  /* 0x800D06E0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D06E4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D06E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D06EC jr ra */
}

void g0_800D06C4(void) {
    { uint32_t _c = (R[2] != R[0]); sw_(R[17] + 608, R[2]); if (_c) { goto L_800D06D0; } }  /* 0x800D06C4 */
    sh_(R[17] + 582, R[0]);  /* 0x800D06CC */
L_800D06D0:;
    R[5] = lw_(R[17] + 588);  /* 0x800D06D0 */
    { R[31] = 0x800D06DCu; R[4] = R[17] + R[0]; psx_next = 0x800CDB10u; return; }  /* 0x800D06D4 jal */
    R[31] = lw_(R[29] + 36);  /* 0x800D06DC */
    R[18] = lw_(R[29] + 32);  /* 0x800D06E0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D06E4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D06E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D06EC jr ra */
}

void g0_800D06DC(void) {
    R[31] = lw_(R[29] + 36);  /* 0x800D06DC */
    R[18] = lw_(R[29] + 32);  /* 0x800D06E0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D06E4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D06E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D06EC jr ra */
}

void g0_800D06F4(void) {
    R[29] = R[29] - 32;  /* 0x800D06F4 */
    sw_(R[29] + 20, R[17]);  /* 0x800D06F8 */
    R[17] = R[4] + R[0];  /* 0x800D06FC */
    R[2] = R[0] + 2;  /* 0x800D0700 */
    sw_(R[29] + 28, R[31]);  /* 0x800D0704 */
    sw_(R[29] + 24, R[18]);  /* 0x800D0708 */
    sw_(R[29] + 16, R[16]);  /* 0x800D070C */
    R[18] = lw_(R[17] + 588);  /* 0x800D0710 */
    { uint32_t _c = (R[5] == R[2]); R[2] = ((int32_t)R[5] < 3); if (_c) { goto L_800D084C; } }  /* 0x800D0714 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 5; if (_c) { goto L_800D0734; } }  /* 0x800D071C */
    { uint32_t _c = (R[5] == R[0]); R[16] = 0x8001u << 16; if (_c) { goto L_800D0754; } }  /* 0x800D0724 */
    { goto L_800D0874; }  /* 0x800D072C j */
L_800D0734:;
    { uint32_t _c = (R[5] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800D0874; } }  /* 0x800D0734 */
    sb_(R[17] + 688, R[2]);  /* 0x800D073C */
    sb_(R[17] + 690, R[2]);  /* 0x800D0740 */
    R[2] = 0x800Du << 16;  /* 0x800D0744 */
    R[2] = R[2] - 10416;  /* 0x800D0748 */
    { sw_(R[17] + 232, R[2]); goto L_800D0874; }  /* 0x800D074C j */
L_800D0754:;
    R[2] = lh_(R[17] + 4);  /* 0x800D0754 */
    R[3] = lh_(R[17] + 584);  /* 0x800D0758 */
    R[2] = R[2] + 30;  /* 0x800D075C */
    R[2] = R[2] & 0x1FF;  /* 0x800D0760 */
    R[3] = R[3] + 330;  /* 0x800D0764 */
    R[3] = R[3] & 0xFFF;  /* 0x800D0768 */
    sh_(R[17] + 4, R[2]);  /* 0x800D076C */
    sh_(R[17] + 584, R[3]);  /* 0x800D0770 */
    R[2] = lw_(R[18] + 24);  /* 0x800D0774 */
    sw_(R[17] + 24, R[2]);  /* 0x800D077C */
    R[3] = lw_(R[18] + 488);  /* 0x800D0780 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 584);  /* 0x800D0784 */
    R[2] = R[3] >> 31;  /* 0x800D0788 */
    R[3] = R[3] + R[2];  /* 0x800D078C */
    R[2] = lw_(R[18] + 28);  /* 0x800D0790 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x800D0794 */
    R[2] = R[2] + R[3];  /* 0x800D0798 */
    sw_(R[17] + 28, R[2]);  /* 0x800D079C */
    R[2] = lw_(R[18] + 32);  /* 0x800D07A0 */
    R[16] = R[16] | 0x28;  /* 0x800D07A4 */
    { R[31] = 0x800D07B0u; sw_(R[17] + 32, R[2]); psx_next = 0x80035B18u; return; }  /* 0x800D07A8 jal */
    R[5] = lw_(R[17] + 592);  /* 0x800D07B0 */
    { uint32_t _t = R[16]; R[31] = 0x800D07BCu; R[4] = R[2] + R[0]; psx_next = _t; return; }  /* 0x800D07B4 jalr */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 584);  /* 0x800D07BC */
    { R[31] = 0x800D07C8u; sw_(R[17] + 36, R[2]); psx_next = 0x80035A48u; return; }  /* 0x800D07C0 jal */
    R[5] = lw_(R[17] + 592);  /* 0x800D07C8 */
    { uint32_t _t = R[16]; R[31] = 0x800D07D4u; R[4] = R[2] + R[0]; psx_next = _t; return; }  /* 0x800D07CC jalr */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 586);  /* 0x800D07D4 */
    sw_(R[17] + 44, R[2]);  /* 0x800D07D8 */
    R[2] = lw_(R[17] + 600);  /* 0x800D07DC */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 586);  /* 0x800D07E0 */
    R[3] = R[3] << 12;  /* 0x800D07E4 */
    R[3] = R[2] + R[3];  /* 0x800D07E8 */
    { uint32_t _c = ((int32_t)R[4] <= 0); sw_(R[17] + 600, R[3]); if (_c) { goto L_800D0808; } }  /* 0x800D07EC */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 598);  /* 0x800D07F4 */
    R[2] = R[2] << 12;  /* 0x800D07FC */
    { R[2] = ((int32_t)R[3] < (int32_t)R[2]); goto L_800D0818; }  /* 0x800D0800 j */
L_800D0808:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 596);  /* 0x800D0808 */
    R[2] = R[2] << 12;  /* 0x800D0810 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x800D0814 */
L_800D0818:;
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] - R[4]; if (_c) { goto L_800D0824; } }  /* 0x800D0818 */
    sh_(R[17] + 586, R[2]);  /* 0x800D0820 */
L_800D0824:;
    R[2] = lw_(R[17] + 600);  /* 0x800D0824 */
    sw_(R[17] + 40, R[2]);  /* 0x800D082C */
    R[2] = lb_(R[18] + 789);  /* 0x800D0830 */
    R[2] = R[2] & 0x2;  /* 0x800D0838 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 4; if (_c) { goto L_800D0874; } }  /* 0x800D083C */
    { sb_(R[17] + 790, R[2]); goto L_800D0874; }  /* 0x800D0844 j */
L_800D084C:;
    { R[31] = 0x800D0854u; R[4] = R[17] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x800D084C jal */
    R[2] = lw_(R[18] + 16);  /* 0x800D0854 */
    R[3] = R[0] - 897;  /* 0x800D0858 */
    sh_(R[18] + 694, R[0]);  /* 0x800D085C */
    R[2] = R[2] & R[3];  /* 0x800D0860 */
    R[2] = R[2] | 0x80;  /* 0x800D0864 */
    sw_(R[18] + 16, R[2]);  /* 0x800D0868 */
    R[2] = R[0] + 3;  /* 0x800D086C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0870 */
L_800D0874:;
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 694);  /* 0x800D0874 */
    R[2] = R[0] + 19;  /* 0x800D0878 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800D08E8; } }  /* 0x800D087C */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 584);  /* 0x800D0884 */
    { R[31] = 0x800D0890u; psx_next = 0x80035B18u; return; }  /* 0x800D0888 jal */
    R[3] = R[2] << 2;  /* 0x800D0890 */
    R[3] = R[3] + R[2];  /* 0x800D0894 */
    R[2] = R[3] << 4;  /* 0x800D0898 */
    R[2] = R[2] - R[3];  /* 0x800D089C */
    R[3] = lw_(R[18] + 24);  /* 0x800D08A0 */
    R[2] = R[2] << 2;  /* 0x800D08A4 */
    R[3] = R[3] + R[2];  /* 0x800D08A8 */
    sw_(R[18] + 700, R[3]);  /* 0x800D08AC */
    R[2] = lw_(R[17] + 28);  /* 0x800D08B0 */
    sw_(R[18] + 704, R[2]);  /* 0x800D08B8 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 584);  /* 0x800D08BC */
    { R[31] = 0x800D08C8u; psx_next = 0x80035A48u; return; }  /* 0x800D08C0 jal */
    R[3] = R[2] << 2;  /* 0x800D08C8 */
    R[3] = R[3] + R[2];  /* 0x800D08CC */
    R[2] = R[3] << 4;  /* 0x800D08D0 */
    R[2] = R[2] - R[3];  /* 0x800D08D4 */
    R[3] = lw_(R[18] + 32);  /* 0x800D08D8 */
    R[2] = R[2] << 2;  /* 0x800D08DC */
    R[3] = R[3] + R[2];  /* 0x800D08E0 */
    sw_(R[18] + 708, R[3]);  /* 0x800D08E4 */
L_800D08E8:;
    R[31] = lw_(R[29] + 28);  /* 0x800D08E8 */
    R[18] = lw_(R[29] + 24);  /* 0x800D08EC */
    R[17] = lw_(R[29] + 20);  /* 0x800D08F0 */
    R[16] = lw_(R[29] + 16);  /* 0x800D08F4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D08F8 jr ra */
}

void g0_800D07B0(void) {
    R[5] = lw_(R[17] + 592);  /* 0x800D07B0 */
    { uint32_t _t = R[16]; R[31] = 0x800D07BCu; R[4] = R[2] + R[0]; psx_next = _t; return; }  /* 0x800D07B4 jalr */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 584);  /* 0x800D07BC */
    { R[31] = 0x800D07C8u; sw_(R[17] + 36, R[2]); psx_next = 0x80035A48u; return; }  /* 0x800D07C0 jal */
    R[5] = lw_(R[17] + 592);  /* 0x800D07C8 */
    { uint32_t _t = R[16]; R[31] = 0x800D07D4u; R[4] = R[2] + R[0]; psx_next = _t; return; }  /* 0x800D07CC jalr */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 586);  /* 0x800D07D4 */
    sw_(R[17] + 44, R[2]);  /* 0x800D07D8 */
    R[2] = lw_(R[17] + 600);  /* 0x800D07DC */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 586);  /* 0x800D07E0 */
    R[3] = R[3] << 12;  /* 0x800D07E4 */
    R[3] = R[2] + R[3];  /* 0x800D07E8 */
    { uint32_t _c = ((int32_t)R[4] <= 0); sw_(R[17] + 600, R[3]); if (_c) { goto L_800D0808; } }  /* 0x800D07EC */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 598);  /* 0x800D07F4 */
    R[2] = R[2] << 12;  /* 0x800D07FC */
    { R[2] = ((int32_t)R[3] < (int32_t)R[2]); goto L_800D0818; }  /* 0x800D0800 j */
L_800D0808:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 596);  /* 0x800D0808 */
    R[2] = R[2] << 12;  /* 0x800D0810 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x800D0814 */
L_800D0818:;
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] - R[4]; if (_c) { goto L_800D0824; } }  /* 0x800D0818 */
    sh_(R[17] + 586, R[2]);  /* 0x800D0820 */
L_800D0824:;
    R[2] = lw_(R[17] + 600);  /* 0x800D0824 */
    sw_(R[17] + 40, R[2]);  /* 0x800D082C */
    R[2] = lb_(R[18] + 789);  /* 0x800D0830 */
    R[2] = R[2] & 0x2;  /* 0x800D0838 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 4; if (_c) { goto L_800D0874; } }  /* 0x800D083C */
    { sb_(R[17] + 790, R[2]); goto L_800D0874; }  /* 0x800D0844 j */
    { R[31] = 0x800D0854u; R[4] = R[17] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x800D084C jal */
    R[2] = lw_(R[18] + 16);  /* 0x800D0854 */
    R[3] = R[0] - 897;  /* 0x800D0858 */
    sh_(R[18] + 694, R[0]);  /* 0x800D085C */
    R[2] = R[2] & R[3];  /* 0x800D0860 */
    R[2] = R[2] | 0x80;  /* 0x800D0864 */
    sw_(R[18] + 16, R[2]);  /* 0x800D0868 */
    R[2] = R[0] + 3;  /* 0x800D086C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0870 */
L_800D0874:;
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 694);  /* 0x800D0874 */
    R[2] = R[0] + 19;  /* 0x800D0878 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800D08E8; } }  /* 0x800D087C */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 584);  /* 0x800D0884 */
    { R[31] = 0x800D0890u; psx_next = 0x80035B18u; return; }  /* 0x800D0888 jal */
    R[3] = R[2] << 2;  /* 0x800D0890 */
    R[3] = R[3] + R[2];  /* 0x800D0894 */
    R[2] = R[3] << 4;  /* 0x800D0898 */
    R[2] = R[2] - R[3];  /* 0x800D089C */
    R[3] = lw_(R[18] + 24);  /* 0x800D08A0 */
    R[2] = R[2] << 2;  /* 0x800D08A4 */
    R[3] = R[3] + R[2];  /* 0x800D08A8 */
    sw_(R[18] + 700, R[3]);  /* 0x800D08AC */
    R[2] = lw_(R[17] + 28);  /* 0x800D08B0 */
    sw_(R[18] + 704, R[2]);  /* 0x800D08B8 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 584);  /* 0x800D08BC */
    { R[31] = 0x800D08C8u; psx_next = 0x80035A48u; return; }  /* 0x800D08C0 jal */
    R[3] = R[2] << 2;  /* 0x800D08C8 */
    R[3] = R[3] + R[2];  /* 0x800D08CC */
    R[2] = R[3] << 4;  /* 0x800D08D0 */
    R[2] = R[2] - R[3];  /* 0x800D08D4 */
    R[3] = lw_(R[18] + 32);  /* 0x800D08D8 */
    R[2] = R[2] << 2;  /* 0x800D08DC */
    R[3] = R[3] + R[2];  /* 0x800D08E0 */
    sw_(R[18] + 708, R[3]);  /* 0x800D08E4 */
L_800D08E8:;
    R[31] = lw_(R[29] + 28);  /* 0x800D08E8 */
    R[18] = lw_(R[29] + 24);  /* 0x800D08EC */
    R[17] = lw_(R[29] + 20);  /* 0x800D08F0 */
    R[16] = lw_(R[29] + 16);  /* 0x800D08F4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D08F8 jr ra */
}

void g0_800D07BC(void) {
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 584);  /* 0x800D07BC */
    { R[31] = 0x800D07C8u; sw_(R[17] + 36, R[2]); psx_next = 0x80035A48u; return; }  /* 0x800D07C0 jal */
    R[5] = lw_(R[17] + 592);  /* 0x800D07C8 */
    { uint32_t _t = R[16]; R[31] = 0x800D07D4u; R[4] = R[2] + R[0]; psx_next = _t; return; }  /* 0x800D07CC jalr */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 586);  /* 0x800D07D4 */
    sw_(R[17] + 44, R[2]);  /* 0x800D07D8 */
    R[2] = lw_(R[17] + 600);  /* 0x800D07DC */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 586);  /* 0x800D07E0 */
    R[3] = R[3] << 12;  /* 0x800D07E4 */
    R[3] = R[2] + R[3];  /* 0x800D07E8 */
    { uint32_t _c = ((int32_t)R[4] <= 0); sw_(R[17] + 600, R[3]); if (_c) { goto L_800D0808; } }  /* 0x800D07EC */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 598);  /* 0x800D07F4 */
    R[2] = R[2] << 12;  /* 0x800D07FC */
    { R[2] = ((int32_t)R[3] < (int32_t)R[2]); goto L_800D0818; }  /* 0x800D0800 j */
L_800D0808:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 596);  /* 0x800D0808 */
    R[2] = R[2] << 12;  /* 0x800D0810 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x800D0814 */
L_800D0818:;
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] - R[4]; if (_c) { goto L_800D0824; } }  /* 0x800D0818 */
    sh_(R[17] + 586, R[2]);  /* 0x800D0820 */
L_800D0824:;
    R[2] = lw_(R[17] + 600);  /* 0x800D0824 */
    sw_(R[17] + 40, R[2]);  /* 0x800D082C */
    R[2] = lb_(R[18] + 789);  /* 0x800D0830 */
    R[2] = R[2] & 0x2;  /* 0x800D0838 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 4; if (_c) { goto L_800D0874; } }  /* 0x800D083C */
    { sb_(R[17] + 790, R[2]); goto L_800D0874; }  /* 0x800D0844 j */
    { R[31] = 0x800D0854u; R[4] = R[17] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x800D084C jal */
    R[2] = lw_(R[18] + 16);  /* 0x800D0854 */
    R[3] = R[0] - 897;  /* 0x800D0858 */
    sh_(R[18] + 694, R[0]);  /* 0x800D085C */
    R[2] = R[2] & R[3];  /* 0x800D0860 */
    R[2] = R[2] | 0x80;  /* 0x800D0864 */
    sw_(R[18] + 16, R[2]);  /* 0x800D0868 */
    R[2] = R[0] + 3;  /* 0x800D086C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0870 */
L_800D0874:;
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 694);  /* 0x800D0874 */
    R[2] = R[0] + 19;  /* 0x800D0878 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800D08E8; } }  /* 0x800D087C */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 584);  /* 0x800D0884 */
    { R[31] = 0x800D0890u; psx_next = 0x80035B18u; return; }  /* 0x800D0888 jal */
    R[3] = R[2] << 2;  /* 0x800D0890 */
    R[3] = R[3] + R[2];  /* 0x800D0894 */
    R[2] = R[3] << 4;  /* 0x800D0898 */
    R[2] = R[2] - R[3];  /* 0x800D089C */
    R[3] = lw_(R[18] + 24);  /* 0x800D08A0 */
    R[2] = R[2] << 2;  /* 0x800D08A4 */
    R[3] = R[3] + R[2];  /* 0x800D08A8 */
    sw_(R[18] + 700, R[3]);  /* 0x800D08AC */
    R[2] = lw_(R[17] + 28);  /* 0x800D08B0 */
    sw_(R[18] + 704, R[2]);  /* 0x800D08B8 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 584);  /* 0x800D08BC */
    { R[31] = 0x800D08C8u; psx_next = 0x80035A48u; return; }  /* 0x800D08C0 jal */
    R[3] = R[2] << 2;  /* 0x800D08C8 */
    R[3] = R[3] + R[2];  /* 0x800D08CC */
    R[2] = R[3] << 4;  /* 0x800D08D0 */
    R[2] = R[2] - R[3];  /* 0x800D08D4 */
    R[3] = lw_(R[18] + 32);  /* 0x800D08D8 */
    R[2] = R[2] << 2;  /* 0x800D08DC */
    R[3] = R[3] + R[2];  /* 0x800D08E0 */
    sw_(R[18] + 708, R[3]);  /* 0x800D08E4 */
L_800D08E8:;
    R[31] = lw_(R[29] + 28);  /* 0x800D08E8 */
    R[18] = lw_(R[29] + 24);  /* 0x800D08EC */
    R[17] = lw_(R[29] + 20);  /* 0x800D08F0 */
    R[16] = lw_(R[29] + 16);  /* 0x800D08F4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D08F8 jr ra */
}

void g0_800D07C8(void) {
    R[5] = lw_(R[17] + 592);  /* 0x800D07C8 */
    { uint32_t _t = R[16]; R[31] = 0x800D07D4u; R[4] = R[2] + R[0]; psx_next = _t; return; }  /* 0x800D07CC jalr */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 586);  /* 0x800D07D4 */
    sw_(R[17] + 44, R[2]);  /* 0x800D07D8 */
    R[2] = lw_(R[17] + 600);  /* 0x800D07DC */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 586);  /* 0x800D07E0 */
    R[3] = R[3] << 12;  /* 0x800D07E4 */
    R[3] = R[2] + R[3];  /* 0x800D07E8 */
    { uint32_t _c = ((int32_t)R[4] <= 0); sw_(R[17] + 600, R[3]); if (_c) { goto L_800D0808; } }  /* 0x800D07EC */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 598);  /* 0x800D07F4 */
    R[2] = R[2] << 12;  /* 0x800D07FC */
    { R[2] = ((int32_t)R[3] < (int32_t)R[2]); goto L_800D0818; }  /* 0x800D0800 j */
L_800D0808:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 596);  /* 0x800D0808 */
    R[2] = R[2] << 12;  /* 0x800D0810 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x800D0814 */
L_800D0818:;
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] - R[4]; if (_c) { goto L_800D0824; } }  /* 0x800D0818 */
    sh_(R[17] + 586, R[2]);  /* 0x800D0820 */
L_800D0824:;
    R[2] = lw_(R[17] + 600);  /* 0x800D0824 */
    sw_(R[17] + 40, R[2]);  /* 0x800D082C */
    R[2] = lb_(R[18] + 789);  /* 0x800D0830 */
    R[2] = R[2] & 0x2;  /* 0x800D0838 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 4; if (_c) { goto L_800D0874; } }  /* 0x800D083C */
    { sb_(R[17] + 790, R[2]); goto L_800D0874; }  /* 0x800D0844 j */
    { R[31] = 0x800D0854u; R[4] = R[17] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x800D084C jal */
    R[2] = lw_(R[18] + 16);  /* 0x800D0854 */
    R[3] = R[0] - 897;  /* 0x800D0858 */
    sh_(R[18] + 694, R[0]);  /* 0x800D085C */
    R[2] = R[2] & R[3];  /* 0x800D0860 */
    R[2] = R[2] | 0x80;  /* 0x800D0864 */
    sw_(R[18] + 16, R[2]);  /* 0x800D0868 */
    R[2] = R[0] + 3;  /* 0x800D086C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0870 */
L_800D0874:;
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 694);  /* 0x800D0874 */
    R[2] = R[0] + 19;  /* 0x800D0878 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800D08E8; } }  /* 0x800D087C */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 584);  /* 0x800D0884 */
    { R[31] = 0x800D0890u; psx_next = 0x80035B18u; return; }  /* 0x800D0888 jal */
    R[3] = R[2] << 2;  /* 0x800D0890 */
    R[3] = R[3] + R[2];  /* 0x800D0894 */
    R[2] = R[3] << 4;  /* 0x800D0898 */
    R[2] = R[2] - R[3];  /* 0x800D089C */
    R[3] = lw_(R[18] + 24);  /* 0x800D08A0 */
    R[2] = R[2] << 2;  /* 0x800D08A4 */
    R[3] = R[3] + R[2];  /* 0x800D08A8 */
    sw_(R[18] + 700, R[3]);  /* 0x800D08AC */
    R[2] = lw_(R[17] + 28);  /* 0x800D08B0 */
    sw_(R[18] + 704, R[2]);  /* 0x800D08B8 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 584);  /* 0x800D08BC */
    { R[31] = 0x800D08C8u; psx_next = 0x80035A48u; return; }  /* 0x800D08C0 jal */
    R[3] = R[2] << 2;  /* 0x800D08C8 */
    R[3] = R[3] + R[2];  /* 0x800D08CC */
    R[2] = R[3] << 4;  /* 0x800D08D0 */
    R[2] = R[2] - R[3];  /* 0x800D08D4 */
    R[3] = lw_(R[18] + 32);  /* 0x800D08D8 */
    R[2] = R[2] << 2;  /* 0x800D08DC */
    R[3] = R[3] + R[2];  /* 0x800D08E0 */
    sw_(R[18] + 708, R[3]);  /* 0x800D08E4 */
L_800D08E8:;
    R[31] = lw_(R[29] + 28);  /* 0x800D08E8 */
    R[18] = lw_(R[29] + 24);  /* 0x800D08EC */
    R[17] = lw_(R[29] + 20);  /* 0x800D08F0 */
    R[16] = lw_(R[29] + 16);  /* 0x800D08F4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D08F8 jr ra */
}

void g0_800D07D4(void) {
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 586);  /* 0x800D07D4 */
    sw_(R[17] + 44, R[2]);  /* 0x800D07D8 */
    R[2] = lw_(R[17] + 600);  /* 0x800D07DC */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 586);  /* 0x800D07E0 */
    R[3] = R[3] << 12;  /* 0x800D07E4 */
    R[3] = R[2] + R[3];  /* 0x800D07E8 */
    { uint32_t _c = ((int32_t)R[4] <= 0); sw_(R[17] + 600, R[3]); if (_c) { goto L_800D0808; } }  /* 0x800D07EC */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 598);  /* 0x800D07F4 */
    R[2] = R[2] << 12;  /* 0x800D07FC */
    { R[2] = ((int32_t)R[3] < (int32_t)R[2]); goto L_800D0818; }  /* 0x800D0800 j */
L_800D0808:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 596);  /* 0x800D0808 */
    R[2] = R[2] << 12;  /* 0x800D0810 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x800D0814 */
L_800D0818:;
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] - R[4]; if (_c) { goto L_800D0824; } }  /* 0x800D0818 */
    sh_(R[17] + 586, R[2]);  /* 0x800D0820 */
L_800D0824:;
    R[2] = lw_(R[17] + 600);  /* 0x800D0824 */
    sw_(R[17] + 40, R[2]);  /* 0x800D082C */
    R[2] = lb_(R[18] + 789);  /* 0x800D0830 */
    R[2] = R[2] & 0x2;  /* 0x800D0838 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 4; if (_c) { goto L_800D0874; } }  /* 0x800D083C */
    { sb_(R[17] + 790, R[2]); goto L_800D0874; }  /* 0x800D0844 j */
    { R[31] = 0x800D0854u; R[4] = R[17] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x800D084C jal */
    R[2] = lw_(R[18] + 16);  /* 0x800D0854 */
    R[3] = R[0] - 897;  /* 0x800D0858 */
    sh_(R[18] + 694, R[0]);  /* 0x800D085C */
    R[2] = R[2] & R[3];  /* 0x800D0860 */
    R[2] = R[2] | 0x80;  /* 0x800D0864 */
    sw_(R[18] + 16, R[2]);  /* 0x800D0868 */
    R[2] = R[0] + 3;  /* 0x800D086C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0870 */
L_800D0874:;
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 694);  /* 0x800D0874 */
    R[2] = R[0] + 19;  /* 0x800D0878 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800D08E8; } }  /* 0x800D087C */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 584);  /* 0x800D0884 */
    { R[31] = 0x800D0890u; psx_next = 0x80035B18u; return; }  /* 0x800D0888 jal */
    R[3] = R[2] << 2;  /* 0x800D0890 */
    R[3] = R[3] + R[2];  /* 0x800D0894 */
    R[2] = R[3] << 4;  /* 0x800D0898 */
    R[2] = R[2] - R[3];  /* 0x800D089C */
    R[3] = lw_(R[18] + 24);  /* 0x800D08A0 */
    R[2] = R[2] << 2;  /* 0x800D08A4 */
    R[3] = R[3] + R[2];  /* 0x800D08A8 */
    sw_(R[18] + 700, R[3]);  /* 0x800D08AC */
    R[2] = lw_(R[17] + 28);  /* 0x800D08B0 */
    sw_(R[18] + 704, R[2]);  /* 0x800D08B8 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 584);  /* 0x800D08BC */
    { R[31] = 0x800D08C8u; psx_next = 0x80035A48u; return; }  /* 0x800D08C0 jal */
    R[3] = R[2] << 2;  /* 0x800D08C8 */
    R[3] = R[3] + R[2];  /* 0x800D08CC */
    R[2] = R[3] << 4;  /* 0x800D08D0 */
    R[2] = R[2] - R[3];  /* 0x800D08D4 */
    R[3] = lw_(R[18] + 32);  /* 0x800D08D8 */
    R[2] = R[2] << 2;  /* 0x800D08DC */
    R[3] = R[3] + R[2];  /* 0x800D08E0 */
    sw_(R[18] + 708, R[3]);  /* 0x800D08E4 */
L_800D08E8:;
    R[31] = lw_(R[29] + 28);  /* 0x800D08E8 */
    R[18] = lw_(R[29] + 24);  /* 0x800D08EC */
    R[17] = lw_(R[29] + 20);  /* 0x800D08F0 */
    R[16] = lw_(R[29] + 16);  /* 0x800D08F4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D08F8 jr ra */
}

void g0_800D0854(void) {
    R[2] = lw_(R[18] + 16);  /* 0x800D0854 */
    R[3] = R[0] - 897;  /* 0x800D0858 */
    sh_(R[18] + 694, R[0]);  /* 0x800D085C */
    R[2] = R[2] & R[3];  /* 0x800D0860 */
    R[2] = R[2] | 0x80;  /* 0x800D0864 */
    sw_(R[18] + 16, R[2]);  /* 0x800D0868 */
    R[2] = R[0] + 3;  /* 0x800D086C */
    sb_(R[17] + 790, R[2]);  /* 0x800D0870 */
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 694);  /* 0x800D0874 */
    R[2] = R[0] + 19;  /* 0x800D0878 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800D08E8; } }  /* 0x800D087C */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 584);  /* 0x800D0884 */
    { R[31] = 0x800D0890u; psx_next = 0x80035B18u; return; }  /* 0x800D0888 jal */
    R[3] = R[2] << 2;  /* 0x800D0890 */
    R[3] = R[3] + R[2];  /* 0x800D0894 */
    R[2] = R[3] << 4;  /* 0x800D0898 */
    R[2] = R[2] - R[3];  /* 0x800D089C */
    R[3] = lw_(R[18] + 24);  /* 0x800D08A0 */
    R[2] = R[2] << 2;  /* 0x800D08A4 */
    R[3] = R[3] + R[2];  /* 0x800D08A8 */
    sw_(R[18] + 700, R[3]);  /* 0x800D08AC */
    R[2] = lw_(R[17] + 28);  /* 0x800D08B0 */
    sw_(R[18] + 704, R[2]);  /* 0x800D08B8 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 584);  /* 0x800D08BC */
    { R[31] = 0x800D08C8u; psx_next = 0x80035A48u; return; }  /* 0x800D08C0 jal */
    R[3] = R[2] << 2;  /* 0x800D08C8 */
    R[3] = R[3] + R[2];  /* 0x800D08CC */
    R[2] = R[3] << 4;  /* 0x800D08D0 */
    R[2] = R[2] - R[3];  /* 0x800D08D4 */
    R[3] = lw_(R[18] + 32);  /* 0x800D08D8 */
    R[2] = R[2] << 2;  /* 0x800D08DC */
    R[3] = R[3] + R[2];  /* 0x800D08E0 */
    sw_(R[18] + 708, R[3]);  /* 0x800D08E4 */
L_800D08E8:;
    R[31] = lw_(R[29] + 28);  /* 0x800D08E8 */
    R[18] = lw_(R[29] + 24);  /* 0x800D08EC */
    R[17] = lw_(R[29] + 20);  /* 0x800D08F0 */
    R[16] = lw_(R[29] + 16);  /* 0x800D08F4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D08F8 jr ra */
}

void g0_800D0890(void) {
    R[3] = R[2] << 2;  /* 0x800D0890 */
    R[3] = R[3] + R[2];  /* 0x800D0894 */
    R[2] = R[3] << 4;  /* 0x800D0898 */
    R[2] = R[2] - R[3];  /* 0x800D089C */
    R[3] = lw_(R[18] + 24);  /* 0x800D08A0 */
    R[2] = R[2] << 2;  /* 0x800D08A4 */
    R[3] = R[3] + R[2];  /* 0x800D08A8 */
    sw_(R[18] + 700, R[3]);  /* 0x800D08AC */
    R[2] = lw_(R[17] + 28);  /* 0x800D08B0 */
    sw_(R[18] + 704, R[2]);  /* 0x800D08B8 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 584);  /* 0x800D08BC */
    { R[31] = 0x800D08C8u; psx_next = 0x80035A48u; return; }  /* 0x800D08C0 jal */
    R[3] = R[2] << 2;  /* 0x800D08C8 */
    R[3] = R[3] + R[2];  /* 0x800D08CC */
    R[2] = R[3] << 4;  /* 0x800D08D0 */
    R[2] = R[2] - R[3];  /* 0x800D08D4 */
    R[3] = lw_(R[18] + 32);  /* 0x800D08D8 */
    R[2] = R[2] << 2;  /* 0x800D08DC */
    R[3] = R[3] + R[2];  /* 0x800D08E0 */
    sw_(R[18] + 708, R[3]);  /* 0x800D08E4 */
    R[31] = lw_(R[29] + 28);  /* 0x800D08E8 */
    R[18] = lw_(R[29] + 24);  /* 0x800D08EC */
    R[17] = lw_(R[29] + 20);  /* 0x800D08F0 */
    R[16] = lw_(R[29] + 16);  /* 0x800D08F4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D08F8 jr ra */
}

void g0_800D08C8(void) {
    R[3] = R[2] << 2;  /* 0x800D08C8 */
    R[3] = R[3] + R[2];  /* 0x800D08CC */
    R[2] = R[3] << 4;  /* 0x800D08D0 */
    R[2] = R[2] - R[3];  /* 0x800D08D4 */
    R[3] = lw_(R[18] + 32);  /* 0x800D08D8 */
    R[2] = R[2] << 2;  /* 0x800D08DC */
    R[3] = R[3] + R[2];  /* 0x800D08E0 */
    sw_(R[18] + 708, R[3]);  /* 0x800D08E4 */
    R[31] = lw_(R[29] + 28);  /* 0x800D08E8 */
    R[18] = lw_(R[29] + 24);  /* 0x800D08EC */
    R[17] = lw_(R[29] + 20);  /* 0x800D08F0 */
    R[16] = lw_(R[29] + 16);  /* 0x800D08F4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D08F8 jr ra */
}

void g0_800D0900(void) {
    R[29] = R[29] - 32;  /* 0x800D0900 */
    R[3] = 0x6u << 16;  /* 0x800D0904 */
    R[3] = R[3] | 0x4000;  /* 0x800D0908 */
    R[2] = 0x8012u << 16;  /* 0x800D090C */
    sw_(R[29] + 24, R[16]);  /* 0x800D0910 */
    R[16] = R[2] - 26864;  /* 0x800D0914 */
    R[2] = 0x800Fu << 16;  /* 0x800D0918 */
    sw_(R[29] + 28, R[31]);  /* 0x800D091C */
    R[5] = lw_(R[16] + 28);  /* 0x800D0920 */
    R[2] = R[2] - 172;  /* 0x800D0924 */
    sw_(R[29] + 16, R[2]);  /* 0x800D0928 */
    R[7] = (uint32_t)(int16_t)lh_(R[16] + 4);  /* 0x800D092C */
    R[4] = lw_(R[16] + 24);  /* 0x800D0930 */
    R[6] = lw_(R[16] + 32);  /* 0x800D0934 */
    { R[31] = 0x800D0940u; R[5] = R[5] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0938 jal */
    R[4] = R[2] + R[0];  /* 0x800D0940 */
    { uint32_t _c = ((int32_t)R[4] < 0); R[2] = R[0] + R[0]; if (_c) { goto L_800D0994; } }  /* 0x800D0944 */
    R[3] = R[4] << 1;  /* 0x800D094C */
    R[3] = R[3] + R[4];  /* 0x800D0950 */
    R[3] = R[3] << 3;  /* 0x800D0954 */
    R[3] = R[3] + R[4];  /* 0x800D0958 */
    R[3] = R[3] << 3;  /* 0x800D095C */
    R[3] = R[3] + R[4];  /* 0x800D0960 */
    R[3] = R[3] << 2;  /* 0x800D0964 */
    R[3] = R[3] + R[16];  /* 0x800D0968 */
    R[5] = 0x8014u << 16;  /* 0x800D096C */
    R[6] = lh_(R[16] + 4);  /* 0x800D0970 */
    R[4] = R[0] + 1;  /* 0x800D0974 */
    sb_(R[3] + 585, R[0]);  /* 0x800D0978 */
    sb_(R[3] + 580, R[0]);  /* 0x800D097C */
    sb_(R[3] + 581, R[0]);  /* 0x800D0980 */
    sw_(R[5] + 15016, R[4]);  /* 0x800D0984 */
    sh_(R[3] + 4, R[6]);  /* 0x800D0988 */
    { sh_(R[3] + 6, R[6]); goto L_800D0998; }  /* 0x800D098C j */
L_800D0994:;
    R[2] = R[0] - 1;  /* 0x800D0994 */
L_800D0998:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0998 */
    R[16] = lw_(R[29] + 24);  /* 0x800D099C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D09A0 jr ra */
}

void g0_800D0940(void) {
    R[4] = R[2] + R[0];  /* 0x800D0940 */
    { uint32_t _c = ((int32_t)R[4] < 0); R[2] = R[0] + R[0]; if (_c) { goto L_800D0994; } }  /* 0x800D0944 */
    R[3] = R[4] << 1;  /* 0x800D094C */
    R[3] = R[3] + R[4];  /* 0x800D0950 */
    R[3] = R[3] << 3;  /* 0x800D0954 */
    R[3] = R[3] + R[4];  /* 0x800D0958 */
    R[3] = R[3] << 3;  /* 0x800D095C */
    R[3] = R[3] + R[4];  /* 0x800D0960 */
    R[3] = R[3] << 2;  /* 0x800D0964 */
    R[3] = R[3] + R[16];  /* 0x800D0968 */
    R[5] = 0x8014u << 16;  /* 0x800D096C */
    R[6] = lh_(R[16] + 4);  /* 0x800D0970 */
    R[4] = R[0] + 1;  /* 0x800D0974 */
    sb_(R[3] + 585, R[0]);  /* 0x800D0978 */
    sb_(R[3] + 580, R[0]);  /* 0x800D097C */
    sb_(R[3] + 581, R[0]);  /* 0x800D0980 */
    sw_(R[5] + 15016, R[4]);  /* 0x800D0984 */
    sh_(R[3] + 4, R[6]);  /* 0x800D0988 */
    { sh_(R[3] + 6, R[6]); goto L_800D0998; }  /* 0x800D098C j */
L_800D0994:;
    R[2] = R[0] - 1;  /* 0x800D0994 */
L_800D0998:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0998 */
    R[16] = lw_(R[29] + 24);  /* 0x800D099C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D09A0 jr ra */
}

void g0_800D09A8(void) {
    R[29] = R[29] - 48;  /* 0x800D09A8 */
    sw_(R[29] + 32, R[18]);  /* 0x800D09AC */
    R[18] = R[0] + R[0];  /* 0x800D09B0 */
    R[2] = 0x800Fu << 16;  /* 0x800D09B4 */
    sw_(R[29] + 40, R[20]);  /* 0x800D09B8 */
    R[20] = R[2] - 128;  /* 0x800D09BC */
    R[2] = 0x8012u << 16;  /* 0x800D09C0 */
    sw_(R[29] + 28, R[17]);  /* 0x800D09C4 */
    R[17] = R[2] - 26864;  /* 0x800D09C8 */
    sw_(R[29] + 36, R[19]);  /* 0x800D09CC */
    R[19] = R[17] + R[0];  /* 0x800D09D0 */
    sw_(R[29] + 44, R[31]);  /* 0x800D09D4 */
    sw_(R[29] + 24, R[16]);  /* 0x800D09D8 */
L_800D09DC:;
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_800D0A0C; } }  /* 0x800D09DC */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D09E4 */
    { R[31] = 0x800D09F0u; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D09E8 jal */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D09F0 */
    R[16] = R[2] << 5;  /* 0x800D09F4 */
    { R[31] = 0x800D0A00u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D09F8 jal */
    R[2] = R[2] << 5;  /* 0x800D0A00 */
    { R[3] = R[0] - R[2]; goto L_800D0A30; }  /* 0x800D0A04 j */
L_800D0A0C:;
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0A0C */
    { R[31] = 0x800D0A18u; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D0A10 jal */
    R[2] = R[2] << 5;  /* 0x800D0A18 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0A1C */
    R[16] = R[0] - R[2];  /* 0x800D0A20 */
    { R[31] = 0x800D0A2Cu; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0A24 jal */
    R[3] = R[2] << 5;  /* 0x800D0A2C */
L_800D0A30:;
    R[2] = 0x6u << 16;  /* 0x800D0A30 */
    R[2] = R[2] | 0x4000;  /* 0x800D0A34 */
    sw_(R[29] + 16, R[20]);  /* 0x800D0A38 */
    R[4] = lw_(R[17] + 24);  /* 0x800D0A3C */
    R[5] = lw_(R[17] + 28);  /* 0x800D0A40 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0A44 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0A48 */
    R[4] = R[4] + R[16];  /* 0x800D0A4C */
    R[5] = R[5] + R[2];  /* 0x800D0A50 */
    { R[31] = 0x800D0A5Cu; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0A54 jal */
    R[3] = R[2] + R[0];  /* 0x800D0A5C */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0AC0; } }  /* 0x800D0A60 */
    R[2] = R[3] << 1;  /* 0x800D0A68 */
    R[2] = R[2] + R[3];  /* 0x800D0A6C */
    R[2] = R[2] << 3;  /* 0x800D0A70 */
    R[2] = R[2] + R[3];  /* 0x800D0A74 */
    R[2] = R[2] << 3;  /* 0x800D0A78 */
    R[2] = R[2] + R[3];  /* 0x800D0A7C */
    R[2] = R[2] << 2;  /* 0x800D0A80 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0A84 */
    R[2] = R[2] + R[19];  /* 0x800D0A88 */
    sb_(R[2] + 585, R[18]);  /* 0x800D0A8C */
    R[18] = R[18] + 1;  /* 0x800D0A90 */
    R[3] = R[0] + 1;  /* 0x800D0A94 */
    sb_(R[2] + 580, R[0]);  /* 0x800D0A98 */
    sb_(R[2] + 581, R[3]);  /* 0x800D0A9C */
    sh_(R[2] + 4, R[4]);  /* 0x800D0AA0 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0AA4 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0AA8 */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_bb(); goto L_800D09DC; } }  /* 0x800D0AAC */
    R[2] = R[0] + 2;  /* 0x800D0AB4 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0AB8 */
    R[2] = R[0] + R[0];  /* 0x800D0ABC */
L_800D0AC0:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0AC0 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0AC4 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0AC8 */
    R[18] = lw_(R[29] + 32);  /* 0x800D0ACC */
    R[17] = lw_(R[29] + 28);  /* 0x800D0AD0 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0AD4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0AD8 jr ra */
}

void g0_800D09DC(void) {
L_800D09DC:;
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_800D0A0C; } }  /* 0x800D09DC */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D09E4 */
    { R[31] = 0x800D09F0u; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D09E8 jal */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D09F0 */
    R[16] = R[2] << 5;  /* 0x800D09F4 */
    { R[31] = 0x800D0A00u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D09F8 jal */
    R[2] = R[2] << 5;  /* 0x800D0A00 */
    { R[3] = R[0] - R[2]; goto L_800D0A30; }  /* 0x800D0A04 j */
L_800D0A0C:;
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0A0C */
    { R[31] = 0x800D0A18u; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D0A10 jal */
    R[2] = R[2] << 5;  /* 0x800D0A18 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0A1C */
    R[16] = R[0] - R[2];  /* 0x800D0A20 */
    { R[31] = 0x800D0A2Cu; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0A24 jal */
    R[3] = R[2] << 5;  /* 0x800D0A2C */
L_800D0A30:;
    R[2] = 0x6u << 16;  /* 0x800D0A30 */
    R[2] = R[2] | 0x4000;  /* 0x800D0A34 */
    sw_(R[29] + 16, R[20]);  /* 0x800D0A38 */
    R[4] = lw_(R[17] + 24);  /* 0x800D0A3C */
    R[5] = lw_(R[17] + 28);  /* 0x800D0A40 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0A44 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0A48 */
    R[4] = R[4] + R[16];  /* 0x800D0A4C */
    R[5] = R[5] + R[2];  /* 0x800D0A50 */
    { R[31] = 0x800D0A5Cu; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0A54 jal */
    R[3] = R[2] + R[0];  /* 0x800D0A5C */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0AC0; } }  /* 0x800D0A60 */
    R[2] = R[3] << 1;  /* 0x800D0A68 */
    R[2] = R[2] + R[3];  /* 0x800D0A6C */
    R[2] = R[2] << 3;  /* 0x800D0A70 */
    R[2] = R[2] + R[3];  /* 0x800D0A74 */
    R[2] = R[2] << 3;  /* 0x800D0A78 */
    R[2] = R[2] + R[3];  /* 0x800D0A7C */
    R[2] = R[2] << 2;  /* 0x800D0A80 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0A84 */
    R[2] = R[2] + R[19];  /* 0x800D0A88 */
    sb_(R[2] + 585, R[18]);  /* 0x800D0A8C */
    R[18] = R[18] + 1;  /* 0x800D0A90 */
    R[3] = R[0] + 1;  /* 0x800D0A94 */
    sb_(R[2] + 580, R[0]);  /* 0x800D0A98 */
    sb_(R[2] + 581, R[3]);  /* 0x800D0A9C */
    sh_(R[2] + 4, R[4]);  /* 0x800D0AA0 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0AA4 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0AA8 */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_bb(); goto L_800D09DC; } }  /* 0x800D0AAC */
    R[2] = R[0] + 2;  /* 0x800D0AB4 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0AB8 */
    R[2] = R[0] + R[0];  /* 0x800D0ABC */
L_800D0AC0:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0AC0 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0AC4 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0AC8 */
    R[18] = lw_(R[29] + 32);  /* 0x800D0ACC */
    R[17] = lw_(R[29] + 28);  /* 0x800D0AD0 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0AD4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0AD8 jr ra */
}

void g0_800D09F0(void) {
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D09F0 */
    R[16] = R[2] << 5;  /* 0x800D09F4 */
    { R[31] = 0x800D0A00u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D09F8 jal */
    R[2] = R[2] << 5;  /* 0x800D0A00 */
    { R[3] = R[0] - R[2]; goto L_800D0A30; }  /* 0x800D0A04 j */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0A0C */
    { R[31] = 0x800D0A18u; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D0A10 jal */
    R[2] = R[2] << 5;  /* 0x800D0A18 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0A1C */
    R[16] = R[0] - R[2];  /* 0x800D0A20 */
    { R[31] = 0x800D0A2Cu; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0A24 jal */
    R[3] = R[2] << 5;  /* 0x800D0A2C */
L_800D0A30:;
    R[2] = 0x6u << 16;  /* 0x800D0A30 */
    R[2] = R[2] | 0x4000;  /* 0x800D0A34 */
    sw_(R[29] + 16, R[20]);  /* 0x800D0A38 */
    R[4] = lw_(R[17] + 24);  /* 0x800D0A3C */
    R[5] = lw_(R[17] + 28);  /* 0x800D0A40 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0A44 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0A48 */
    R[4] = R[4] + R[16];  /* 0x800D0A4C */
    R[5] = R[5] + R[2];  /* 0x800D0A50 */
    { R[31] = 0x800D0A5Cu; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0A54 jal */
    R[3] = R[2] + R[0];  /* 0x800D0A5C */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0AC0; } }  /* 0x800D0A60 */
    R[2] = R[3] << 1;  /* 0x800D0A68 */
    R[2] = R[2] + R[3];  /* 0x800D0A6C */
    R[2] = R[2] << 3;  /* 0x800D0A70 */
    R[2] = R[2] + R[3];  /* 0x800D0A74 */
    R[2] = R[2] << 3;  /* 0x800D0A78 */
    R[2] = R[2] + R[3];  /* 0x800D0A7C */
    R[2] = R[2] << 2;  /* 0x800D0A80 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0A84 */
    R[2] = R[2] + R[19];  /* 0x800D0A88 */
    sb_(R[2] + 585, R[18]);  /* 0x800D0A8C */
    R[18] = R[18] + 1;  /* 0x800D0A90 */
    R[3] = R[0] + 1;  /* 0x800D0A94 */
    sb_(R[2] + 580, R[0]);  /* 0x800D0A98 */
    sb_(R[2] + 581, R[3]);  /* 0x800D0A9C */
    sh_(R[2] + 4, R[4]);  /* 0x800D0AA0 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0AA4 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0AA8 */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_next = 0x800D09DCu; return; } }  /* 0x800D0AAC b extern */
    R[2] = R[0] + 2;  /* 0x800D0AB4 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0AB8 */
    R[2] = R[0] + R[0];  /* 0x800D0ABC */
L_800D0AC0:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0AC0 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0AC4 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0AC8 */
    R[18] = lw_(R[29] + 32);  /* 0x800D0ACC */
    R[17] = lw_(R[29] + 28);  /* 0x800D0AD0 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0AD4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0AD8 jr ra */
}

void g0_800D0A00(void) {
    R[2] = R[2] << 5;  /* 0x800D0A00 */
    { R[3] = R[0] - R[2]; goto L_800D0A30; }  /* 0x800D0A04 j */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0A0C */
    { R[31] = 0x800D0A18u; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D0A10 jal */
    R[2] = R[2] << 5;  /* 0x800D0A18 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0A1C */
    R[16] = R[0] - R[2];  /* 0x800D0A20 */
    { R[31] = 0x800D0A2Cu; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0A24 jal */
    R[3] = R[2] << 5;  /* 0x800D0A2C */
L_800D0A30:;
    R[2] = 0x6u << 16;  /* 0x800D0A30 */
    R[2] = R[2] | 0x4000;  /* 0x800D0A34 */
    sw_(R[29] + 16, R[20]);  /* 0x800D0A38 */
    R[4] = lw_(R[17] + 24);  /* 0x800D0A3C */
    R[5] = lw_(R[17] + 28);  /* 0x800D0A40 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0A44 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0A48 */
    R[4] = R[4] + R[16];  /* 0x800D0A4C */
    R[5] = R[5] + R[2];  /* 0x800D0A50 */
    { R[31] = 0x800D0A5Cu; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0A54 jal */
    R[3] = R[2] + R[0];  /* 0x800D0A5C */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0AC0; } }  /* 0x800D0A60 */
    R[2] = R[3] << 1;  /* 0x800D0A68 */
    R[2] = R[2] + R[3];  /* 0x800D0A6C */
    R[2] = R[2] << 3;  /* 0x800D0A70 */
    R[2] = R[2] + R[3];  /* 0x800D0A74 */
    R[2] = R[2] << 3;  /* 0x800D0A78 */
    R[2] = R[2] + R[3];  /* 0x800D0A7C */
    R[2] = R[2] << 2;  /* 0x800D0A80 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0A84 */
    R[2] = R[2] + R[19];  /* 0x800D0A88 */
    sb_(R[2] + 585, R[18]);  /* 0x800D0A8C */
    R[18] = R[18] + 1;  /* 0x800D0A90 */
    R[3] = R[0] + 1;  /* 0x800D0A94 */
    sb_(R[2] + 580, R[0]);  /* 0x800D0A98 */
    sb_(R[2] + 581, R[3]);  /* 0x800D0A9C */
    sh_(R[2] + 4, R[4]);  /* 0x800D0AA0 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0AA4 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0AA8 */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_next = 0x800D09DCu; return; } }  /* 0x800D0AAC b extern */
    R[2] = R[0] + 2;  /* 0x800D0AB4 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0AB8 */
    R[2] = R[0] + R[0];  /* 0x800D0ABC */
L_800D0AC0:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0AC0 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0AC4 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0AC8 */
    R[18] = lw_(R[29] + 32);  /* 0x800D0ACC */
    R[17] = lw_(R[29] + 28);  /* 0x800D0AD0 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0AD4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0AD8 jr ra */
}

void g0_800D0A18(void) {
    R[2] = R[2] << 5;  /* 0x800D0A18 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0A1C */
    R[16] = R[0] - R[2];  /* 0x800D0A20 */
    { R[31] = 0x800D0A2Cu; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0A24 jal */
    R[3] = R[2] << 5;  /* 0x800D0A2C */
    R[2] = 0x6u << 16;  /* 0x800D0A30 */
    R[2] = R[2] | 0x4000;  /* 0x800D0A34 */
    sw_(R[29] + 16, R[20]);  /* 0x800D0A38 */
    R[4] = lw_(R[17] + 24);  /* 0x800D0A3C */
    R[5] = lw_(R[17] + 28);  /* 0x800D0A40 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0A44 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0A48 */
    R[4] = R[4] + R[16];  /* 0x800D0A4C */
    R[5] = R[5] + R[2];  /* 0x800D0A50 */
    { R[31] = 0x800D0A5Cu; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0A54 jal */
    R[3] = R[2] + R[0];  /* 0x800D0A5C */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0AC0; } }  /* 0x800D0A60 */
    R[2] = R[3] << 1;  /* 0x800D0A68 */
    R[2] = R[2] + R[3];  /* 0x800D0A6C */
    R[2] = R[2] << 3;  /* 0x800D0A70 */
    R[2] = R[2] + R[3];  /* 0x800D0A74 */
    R[2] = R[2] << 3;  /* 0x800D0A78 */
    R[2] = R[2] + R[3];  /* 0x800D0A7C */
    R[2] = R[2] << 2;  /* 0x800D0A80 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0A84 */
    R[2] = R[2] + R[19];  /* 0x800D0A88 */
    sb_(R[2] + 585, R[18]);  /* 0x800D0A8C */
    R[18] = R[18] + 1;  /* 0x800D0A90 */
    R[3] = R[0] + 1;  /* 0x800D0A94 */
    sb_(R[2] + 580, R[0]);  /* 0x800D0A98 */
    sb_(R[2] + 581, R[3]);  /* 0x800D0A9C */
    sh_(R[2] + 4, R[4]);  /* 0x800D0AA0 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0AA4 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0AA8 */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_next = 0x800D09DCu; return; } }  /* 0x800D0AAC b extern */
    R[2] = R[0] + 2;  /* 0x800D0AB4 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0AB8 */
    R[2] = R[0] + R[0];  /* 0x800D0ABC */
L_800D0AC0:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0AC0 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0AC4 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0AC8 */
    R[18] = lw_(R[29] + 32);  /* 0x800D0ACC */
    R[17] = lw_(R[29] + 28);  /* 0x800D0AD0 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0AD4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0AD8 jr ra */
}

void g0_800D0A2C(void) {
    R[3] = R[2] << 5;  /* 0x800D0A2C */
    R[2] = 0x6u << 16;  /* 0x800D0A30 */
    R[2] = R[2] | 0x4000;  /* 0x800D0A34 */
    sw_(R[29] + 16, R[20]);  /* 0x800D0A38 */
    R[4] = lw_(R[17] + 24);  /* 0x800D0A3C */
    R[5] = lw_(R[17] + 28);  /* 0x800D0A40 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0A44 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0A48 */
    R[4] = R[4] + R[16];  /* 0x800D0A4C */
    R[5] = R[5] + R[2];  /* 0x800D0A50 */
    { R[31] = 0x800D0A5Cu; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0A54 jal */
    R[3] = R[2] + R[0];  /* 0x800D0A5C */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0AC0; } }  /* 0x800D0A60 */
    R[2] = R[3] << 1;  /* 0x800D0A68 */
    R[2] = R[2] + R[3];  /* 0x800D0A6C */
    R[2] = R[2] << 3;  /* 0x800D0A70 */
    R[2] = R[2] + R[3];  /* 0x800D0A74 */
    R[2] = R[2] << 3;  /* 0x800D0A78 */
    R[2] = R[2] + R[3];  /* 0x800D0A7C */
    R[2] = R[2] << 2;  /* 0x800D0A80 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0A84 */
    R[2] = R[2] + R[19];  /* 0x800D0A88 */
    sb_(R[2] + 585, R[18]);  /* 0x800D0A8C */
    R[18] = R[18] + 1;  /* 0x800D0A90 */
    R[3] = R[0] + 1;  /* 0x800D0A94 */
    sb_(R[2] + 580, R[0]);  /* 0x800D0A98 */
    sb_(R[2] + 581, R[3]);  /* 0x800D0A9C */
    sh_(R[2] + 4, R[4]);  /* 0x800D0AA0 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0AA4 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0AA8 */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_next = 0x800D09DCu; return; } }  /* 0x800D0AAC b extern */
    R[2] = R[0] + 2;  /* 0x800D0AB4 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0AB8 */
    R[2] = R[0] + R[0];  /* 0x800D0ABC */
L_800D0AC0:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0AC0 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0AC4 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0AC8 */
    R[18] = lw_(R[29] + 32);  /* 0x800D0ACC */
    R[17] = lw_(R[29] + 28);  /* 0x800D0AD0 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0AD4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0AD8 jr ra */
}

void g0_800D0A5C(void) {
    R[3] = R[2] + R[0];  /* 0x800D0A5C */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0AC0; } }  /* 0x800D0A60 */
    R[2] = R[3] << 1;  /* 0x800D0A68 */
    R[2] = R[2] + R[3];  /* 0x800D0A6C */
    R[2] = R[2] << 3;  /* 0x800D0A70 */
    R[2] = R[2] + R[3];  /* 0x800D0A74 */
    R[2] = R[2] << 3;  /* 0x800D0A78 */
    R[2] = R[2] + R[3];  /* 0x800D0A7C */
    R[2] = R[2] << 2;  /* 0x800D0A80 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0A84 */
    R[2] = R[2] + R[19];  /* 0x800D0A88 */
    sb_(R[2] + 585, R[18]);  /* 0x800D0A8C */
    R[18] = R[18] + 1;  /* 0x800D0A90 */
    R[3] = R[0] + 1;  /* 0x800D0A94 */
    sb_(R[2] + 580, R[0]);  /* 0x800D0A98 */
    sb_(R[2] + 581, R[3]);  /* 0x800D0A9C */
    sh_(R[2] + 4, R[4]);  /* 0x800D0AA0 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0AA4 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0AA8 */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_next = 0x800D09DCu; return; } }  /* 0x800D0AAC b extern */
    R[2] = R[0] + 2;  /* 0x800D0AB4 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0AB8 */
    R[2] = R[0] + R[0];  /* 0x800D0ABC */
L_800D0AC0:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0AC0 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0AC4 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0AC8 */
    R[18] = lw_(R[29] + 32);  /* 0x800D0ACC */
    R[17] = lw_(R[29] + 28);  /* 0x800D0AD0 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0AD4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0AD8 jr ra */
}

void g0_800D0AE0(void) {
    R[29] = R[29] - 32;  /* 0x800D0AE0 */
    R[3] = 0x6u << 16;  /* 0x800D0AE4 */
    R[3] = R[3] | 0x4000;  /* 0x800D0AE8 */
    R[2] = 0x8012u << 16;  /* 0x800D0AEC */
    sw_(R[29] + 24, R[16]);  /* 0x800D0AF0 */
    R[16] = R[2] - 26864;  /* 0x800D0AF4 */
    R[2] = 0x800Fu << 16;  /* 0x800D0AF8 */
    sw_(R[29] + 28, R[31]);  /* 0x800D0AFC */
    R[5] = lw_(R[16] + 28);  /* 0x800D0B00 */
    R[2] = R[2] - 84;  /* 0x800D0B04 */
    sw_(R[29] + 16, R[2]);  /* 0x800D0B08 */
    R[7] = (uint32_t)(int16_t)lh_(R[16] + 4);  /* 0x800D0B0C */
    R[4] = lw_(R[16] + 24);  /* 0x800D0B10 */
    R[6] = lw_(R[16] + 32);  /* 0x800D0B14 */
    { R[31] = 0x800D0B20u; R[5] = R[5] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0B18 jal */
    R[4] = R[2] + R[0];  /* 0x800D0B20 */
    { uint32_t _c = ((int32_t)R[4] < 0); R[2] = R[0] + R[0]; if (_c) { goto L_800D0B78; } }  /* 0x800D0B24 */
    R[3] = R[4] << 1;  /* 0x800D0B2C */
    R[3] = R[3] + R[4];  /* 0x800D0B30 */
    R[3] = R[3] << 3;  /* 0x800D0B34 */
    R[3] = R[3] + R[4];  /* 0x800D0B38 */
    R[3] = R[3] << 3;  /* 0x800D0B3C */
    R[3] = R[3] + R[4];  /* 0x800D0B40 */
    R[3] = R[3] << 2;  /* 0x800D0B44 */
    R[3] = R[3] + R[16];  /* 0x800D0B48 */
    R[4] = R[0] + 1;  /* 0x800D0B4C */
    R[6] = lh_(R[16] + 4);  /* 0x800D0B50 */
    R[5] = 0x8014u << 16;  /* 0x800D0B54 */
    sb_(R[3] + 580, R[4]);  /* 0x800D0B58 */
    R[4] = R[0] + 1;  /* 0x800D0B5C */
    sb_(R[3] + 585, R[0]);  /* 0x800D0B60 */
    sb_(R[3] + 581, R[0]);  /* 0x800D0B64 */
    sw_(R[5] + 15016, R[4]);  /* 0x800D0B68 */
    sh_(R[3] + 4, R[6]);  /* 0x800D0B6C */
    { sh_(R[3] + 6, R[6]); goto L_800D0B7C; }  /* 0x800D0B70 j */
L_800D0B78:;
    R[2] = R[0] - 1;  /* 0x800D0B78 */
L_800D0B7C:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0B7C */
    R[16] = lw_(R[29] + 24);  /* 0x800D0B80 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0B84 jr ra */
}

void g0_800D0B20(void) {
    R[4] = R[2] + R[0];  /* 0x800D0B20 */
    { uint32_t _c = ((int32_t)R[4] < 0); R[2] = R[0] + R[0]; if (_c) { goto L_800D0B78; } }  /* 0x800D0B24 */
    R[3] = R[4] << 1;  /* 0x800D0B2C */
    R[3] = R[3] + R[4];  /* 0x800D0B30 */
    R[3] = R[3] << 3;  /* 0x800D0B34 */
    R[3] = R[3] + R[4];  /* 0x800D0B38 */
    R[3] = R[3] << 3;  /* 0x800D0B3C */
    R[3] = R[3] + R[4];  /* 0x800D0B40 */
    R[3] = R[3] << 2;  /* 0x800D0B44 */
    R[3] = R[3] + R[16];  /* 0x800D0B48 */
    R[4] = R[0] + 1;  /* 0x800D0B4C */
    R[6] = lh_(R[16] + 4);  /* 0x800D0B50 */
    R[5] = 0x8014u << 16;  /* 0x800D0B54 */
    sb_(R[3] + 580, R[4]);  /* 0x800D0B58 */
    R[4] = R[0] + 1;  /* 0x800D0B5C */
    sb_(R[3] + 585, R[0]);  /* 0x800D0B60 */
    sb_(R[3] + 581, R[0]);  /* 0x800D0B64 */
    sw_(R[5] + 15016, R[4]);  /* 0x800D0B68 */
    sh_(R[3] + 4, R[6]);  /* 0x800D0B6C */
    { sh_(R[3] + 6, R[6]); goto L_800D0B7C; }  /* 0x800D0B70 j */
L_800D0B78:;
    R[2] = R[0] - 1;  /* 0x800D0B78 */
L_800D0B7C:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0B7C */
    R[16] = lw_(R[29] + 24);  /* 0x800D0B80 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0B84 jr ra */
}

void g0_800D0B8C(void) {
    R[29] = R[29] - 48;  /* 0x800D0B8C */
    sw_(R[29] + 32, R[18]);  /* 0x800D0B90 */
    R[18] = R[0] + R[0];  /* 0x800D0B94 */
    R[2] = 0x800Fu << 16;  /* 0x800D0B98 */
    sw_(R[29] + 40, R[20]);  /* 0x800D0B9C */
    R[20] = R[2] - 40;  /* 0x800D0BA0 */
    R[2] = 0x8012u << 16;  /* 0x800D0BA4 */
    sw_(R[29] + 28, R[17]);  /* 0x800D0BA8 */
    R[17] = R[2] - 26864;  /* 0x800D0BAC */
    sw_(R[29] + 36, R[19]);  /* 0x800D0BB0 */
    R[19] = R[17] + R[0];  /* 0x800D0BB4 */
    sw_(R[29] + 44, R[31]);  /* 0x800D0BB8 */
    sw_(R[29] + 24, R[16]);  /* 0x800D0BBC */
L_800D0BC0:;
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_800D0BF0; } }  /* 0x800D0BC0 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0BC8 */
    { R[31] = 0x800D0BD4u; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D0BCC jal */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0BD4 */
    R[16] = R[2] << 5;  /* 0x800D0BD8 */
    { R[31] = 0x800D0BE4u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0BDC jal */
    R[2] = R[2] << 5;  /* 0x800D0BE4 */
    { R[3] = R[0] - R[2]; goto L_800D0C14; }  /* 0x800D0BE8 j */
L_800D0BF0:;
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0BF0 */
    { R[31] = 0x800D0BFCu; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D0BF4 jal */
    R[2] = R[2] << 5;  /* 0x800D0BFC */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0C00 */
    R[16] = R[0] - R[2];  /* 0x800D0C04 */
    { R[31] = 0x800D0C10u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0C08 jal */
    R[3] = R[2] << 5;  /* 0x800D0C10 */
L_800D0C14:;
    R[2] = 0x6u << 16;  /* 0x800D0C14 */
    R[2] = R[2] | 0x4000;  /* 0x800D0C18 */
    sw_(R[29] + 16, R[20]);  /* 0x800D0C1C */
    R[4] = lw_(R[17] + 24);  /* 0x800D0C20 */
    R[5] = lw_(R[17] + 28);  /* 0x800D0C24 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0C28 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0C2C */
    R[4] = R[4] + R[16];  /* 0x800D0C30 */
    R[5] = R[5] + R[2];  /* 0x800D0C34 */
    { R[31] = 0x800D0C40u; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0C38 jal */
    R[3] = R[2] + R[0];  /* 0x800D0C40 */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0CA4; } }  /* 0x800D0C44 */
    R[2] = R[3] << 1;  /* 0x800D0C4C */
    R[2] = R[2] + R[3];  /* 0x800D0C50 */
    R[2] = R[2] << 3;  /* 0x800D0C54 */
    R[2] = R[2] + R[3];  /* 0x800D0C58 */
    R[2] = R[2] << 3;  /* 0x800D0C5C */
    R[2] = R[2] + R[3];  /* 0x800D0C60 */
    R[2] = R[2] << 2;  /* 0x800D0C64 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0C68 */
    R[2] = R[2] + R[19];  /* 0x800D0C6C */
    sb_(R[2] + 585, R[18]);  /* 0x800D0C70 */
    R[18] = R[18] + 1;  /* 0x800D0C74 */
    R[3] = R[0] + 1;  /* 0x800D0C78 */
    sb_(R[2] + 580, R[3]);  /* 0x800D0C7C */
    sb_(R[2] + 581, R[3]);  /* 0x800D0C80 */
    sh_(R[2] + 4, R[4]);  /* 0x800D0C84 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0C88 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0C8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_bb(); goto L_800D0BC0; } }  /* 0x800D0C90 */
    R[2] = R[0] + 2;  /* 0x800D0C98 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0C9C */
    R[2] = R[0] + R[0];  /* 0x800D0CA0 */
L_800D0CA4:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0CA4 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0CA8 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0CAC */
    R[18] = lw_(R[29] + 32);  /* 0x800D0CB0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D0CB4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0CB8 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0CBC jr ra */
}

void g0_800D0BC0(void) {
L_800D0BC0:;
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_800D0BF0; } }  /* 0x800D0BC0 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0BC8 */
    { R[31] = 0x800D0BD4u; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D0BCC jal */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0BD4 */
    R[16] = R[2] << 5;  /* 0x800D0BD8 */
    { R[31] = 0x800D0BE4u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0BDC jal */
    R[2] = R[2] << 5;  /* 0x800D0BE4 */
    { R[3] = R[0] - R[2]; goto L_800D0C14; }  /* 0x800D0BE8 j */
L_800D0BF0:;
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0BF0 */
    { R[31] = 0x800D0BFCu; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D0BF4 jal */
    R[2] = R[2] << 5;  /* 0x800D0BFC */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0C00 */
    R[16] = R[0] - R[2];  /* 0x800D0C04 */
    { R[31] = 0x800D0C10u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0C08 jal */
    R[3] = R[2] << 5;  /* 0x800D0C10 */
L_800D0C14:;
    R[2] = 0x6u << 16;  /* 0x800D0C14 */
    R[2] = R[2] | 0x4000;  /* 0x800D0C18 */
    sw_(R[29] + 16, R[20]);  /* 0x800D0C1C */
    R[4] = lw_(R[17] + 24);  /* 0x800D0C20 */
    R[5] = lw_(R[17] + 28);  /* 0x800D0C24 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0C28 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0C2C */
    R[4] = R[4] + R[16];  /* 0x800D0C30 */
    R[5] = R[5] + R[2];  /* 0x800D0C34 */
    { R[31] = 0x800D0C40u; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0C38 jal */
    R[3] = R[2] + R[0];  /* 0x800D0C40 */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0CA4; } }  /* 0x800D0C44 */
    R[2] = R[3] << 1;  /* 0x800D0C4C */
    R[2] = R[2] + R[3];  /* 0x800D0C50 */
    R[2] = R[2] << 3;  /* 0x800D0C54 */
    R[2] = R[2] + R[3];  /* 0x800D0C58 */
    R[2] = R[2] << 3;  /* 0x800D0C5C */
    R[2] = R[2] + R[3];  /* 0x800D0C60 */
    R[2] = R[2] << 2;  /* 0x800D0C64 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0C68 */
    R[2] = R[2] + R[19];  /* 0x800D0C6C */
    sb_(R[2] + 585, R[18]);  /* 0x800D0C70 */
    R[18] = R[18] + 1;  /* 0x800D0C74 */
    R[3] = R[0] + 1;  /* 0x800D0C78 */
    sb_(R[2] + 580, R[3]);  /* 0x800D0C7C */
    sb_(R[2] + 581, R[3]);  /* 0x800D0C80 */
    sh_(R[2] + 4, R[4]);  /* 0x800D0C84 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0C88 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0C8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_bb(); goto L_800D0BC0; } }  /* 0x800D0C90 */
    R[2] = R[0] + 2;  /* 0x800D0C98 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0C9C */
    R[2] = R[0] + R[0];  /* 0x800D0CA0 */
L_800D0CA4:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0CA4 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0CA8 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0CAC */
    R[18] = lw_(R[29] + 32);  /* 0x800D0CB0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D0CB4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0CB8 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0CBC jr ra */
}

void g0_800D0BD4(void) {
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0BD4 */
    R[16] = R[2] << 5;  /* 0x800D0BD8 */
    { R[31] = 0x800D0BE4u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0BDC jal */
    R[2] = R[2] << 5;  /* 0x800D0BE4 */
    { R[3] = R[0] - R[2]; goto L_800D0C14; }  /* 0x800D0BE8 j */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0BF0 */
    { R[31] = 0x800D0BFCu; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D0BF4 jal */
    R[2] = R[2] << 5;  /* 0x800D0BFC */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0C00 */
    R[16] = R[0] - R[2];  /* 0x800D0C04 */
    { R[31] = 0x800D0C10u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0C08 jal */
    R[3] = R[2] << 5;  /* 0x800D0C10 */
L_800D0C14:;
    R[2] = 0x6u << 16;  /* 0x800D0C14 */
    R[2] = R[2] | 0x4000;  /* 0x800D0C18 */
    sw_(R[29] + 16, R[20]);  /* 0x800D0C1C */
    R[4] = lw_(R[17] + 24);  /* 0x800D0C20 */
    R[5] = lw_(R[17] + 28);  /* 0x800D0C24 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0C28 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0C2C */
    R[4] = R[4] + R[16];  /* 0x800D0C30 */
    R[5] = R[5] + R[2];  /* 0x800D0C34 */
    { R[31] = 0x800D0C40u; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0C38 jal */
    R[3] = R[2] + R[0];  /* 0x800D0C40 */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0CA4; } }  /* 0x800D0C44 */
    R[2] = R[3] << 1;  /* 0x800D0C4C */
    R[2] = R[2] + R[3];  /* 0x800D0C50 */
    R[2] = R[2] << 3;  /* 0x800D0C54 */
    R[2] = R[2] + R[3];  /* 0x800D0C58 */
    R[2] = R[2] << 3;  /* 0x800D0C5C */
    R[2] = R[2] + R[3];  /* 0x800D0C60 */
    R[2] = R[2] << 2;  /* 0x800D0C64 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0C68 */
    R[2] = R[2] + R[19];  /* 0x800D0C6C */
    sb_(R[2] + 585, R[18]);  /* 0x800D0C70 */
    R[18] = R[18] + 1;  /* 0x800D0C74 */
    R[3] = R[0] + 1;  /* 0x800D0C78 */
    sb_(R[2] + 580, R[3]);  /* 0x800D0C7C */
    sb_(R[2] + 581, R[3]);  /* 0x800D0C80 */
    sh_(R[2] + 4, R[4]);  /* 0x800D0C84 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0C88 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0C8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_next = 0x800D0BC0u; return; } }  /* 0x800D0C90 b extern */
    R[2] = R[0] + 2;  /* 0x800D0C98 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0C9C */
    R[2] = R[0] + R[0];  /* 0x800D0CA0 */
L_800D0CA4:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0CA4 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0CA8 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0CAC */
    R[18] = lw_(R[29] + 32);  /* 0x800D0CB0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D0CB4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0CB8 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0CBC jr ra */
}

void g0_800D0BE4(void) {
    R[2] = R[2] << 5;  /* 0x800D0BE4 */
    { R[3] = R[0] - R[2]; goto L_800D0C14; }  /* 0x800D0BE8 j */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0BF0 */
    { R[31] = 0x800D0BFCu; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D0BF4 jal */
    R[2] = R[2] << 5;  /* 0x800D0BFC */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0C00 */
    R[16] = R[0] - R[2];  /* 0x800D0C04 */
    { R[31] = 0x800D0C10u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0C08 jal */
    R[3] = R[2] << 5;  /* 0x800D0C10 */
L_800D0C14:;
    R[2] = 0x6u << 16;  /* 0x800D0C14 */
    R[2] = R[2] | 0x4000;  /* 0x800D0C18 */
    sw_(R[29] + 16, R[20]);  /* 0x800D0C1C */
    R[4] = lw_(R[17] + 24);  /* 0x800D0C20 */
    R[5] = lw_(R[17] + 28);  /* 0x800D0C24 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0C28 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0C2C */
    R[4] = R[4] + R[16];  /* 0x800D0C30 */
    R[5] = R[5] + R[2];  /* 0x800D0C34 */
    { R[31] = 0x800D0C40u; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0C38 jal */
    R[3] = R[2] + R[0];  /* 0x800D0C40 */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0CA4; } }  /* 0x800D0C44 */
    R[2] = R[3] << 1;  /* 0x800D0C4C */
    R[2] = R[2] + R[3];  /* 0x800D0C50 */
    R[2] = R[2] << 3;  /* 0x800D0C54 */
    R[2] = R[2] + R[3];  /* 0x800D0C58 */
    R[2] = R[2] << 3;  /* 0x800D0C5C */
    R[2] = R[2] + R[3];  /* 0x800D0C60 */
    R[2] = R[2] << 2;  /* 0x800D0C64 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0C68 */
    R[2] = R[2] + R[19];  /* 0x800D0C6C */
    sb_(R[2] + 585, R[18]);  /* 0x800D0C70 */
    R[18] = R[18] + 1;  /* 0x800D0C74 */
    R[3] = R[0] + 1;  /* 0x800D0C78 */
    sb_(R[2] + 580, R[3]);  /* 0x800D0C7C */
    sb_(R[2] + 581, R[3]);  /* 0x800D0C80 */
    sh_(R[2] + 4, R[4]);  /* 0x800D0C84 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0C88 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0C8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_next = 0x800D0BC0u; return; } }  /* 0x800D0C90 b extern */
    R[2] = R[0] + 2;  /* 0x800D0C98 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0C9C */
    R[2] = R[0] + R[0];  /* 0x800D0CA0 */
L_800D0CA4:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0CA4 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0CA8 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0CAC */
    R[18] = lw_(R[29] + 32);  /* 0x800D0CB0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D0CB4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0CB8 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0CBC jr ra */
}

void g0_800D0BFC(void) {
    R[2] = R[2] << 5;  /* 0x800D0BFC */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0C00 */
    R[16] = R[0] - R[2];  /* 0x800D0C04 */
    { R[31] = 0x800D0C10u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0C08 jal */
    R[3] = R[2] << 5;  /* 0x800D0C10 */
    R[2] = 0x6u << 16;  /* 0x800D0C14 */
    R[2] = R[2] | 0x4000;  /* 0x800D0C18 */
    sw_(R[29] + 16, R[20]);  /* 0x800D0C1C */
    R[4] = lw_(R[17] + 24);  /* 0x800D0C20 */
    R[5] = lw_(R[17] + 28);  /* 0x800D0C24 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0C28 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0C2C */
    R[4] = R[4] + R[16];  /* 0x800D0C30 */
    R[5] = R[5] + R[2];  /* 0x800D0C34 */
    { R[31] = 0x800D0C40u; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0C38 jal */
    R[3] = R[2] + R[0];  /* 0x800D0C40 */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0CA4; } }  /* 0x800D0C44 */
    R[2] = R[3] << 1;  /* 0x800D0C4C */
    R[2] = R[2] + R[3];  /* 0x800D0C50 */
    R[2] = R[2] << 3;  /* 0x800D0C54 */
    R[2] = R[2] + R[3];  /* 0x800D0C58 */
    R[2] = R[2] << 3;  /* 0x800D0C5C */
    R[2] = R[2] + R[3];  /* 0x800D0C60 */
    R[2] = R[2] << 2;  /* 0x800D0C64 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0C68 */
    R[2] = R[2] + R[19];  /* 0x800D0C6C */
    sb_(R[2] + 585, R[18]);  /* 0x800D0C70 */
    R[18] = R[18] + 1;  /* 0x800D0C74 */
    R[3] = R[0] + 1;  /* 0x800D0C78 */
    sb_(R[2] + 580, R[3]);  /* 0x800D0C7C */
    sb_(R[2] + 581, R[3]);  /* 0x800D0C80 */
    sh_(R[2] + 4, R[4]);  /* 0x800D0C84 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0C88 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0C8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_next = 0x800D0BC0u; return; } }  /* 0x800D0C90 b extern */
    R[2] = R[0] + 2;  /* 0x800D0C98 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0C9C */
    R[2] = R[0] + R[0];  /* 0x800D0CA0 */
L_800D0CA4:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0CA4 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0CA8 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0CAC */
    R[18] = lw_(R[29] + 32);  /* 0x800D0CB0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D0CB4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0CB8 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0CBC jr ra */
}

void g0_800D0C10(void) {
    R[3] = R[2] << 5;  /* 0x800D0C10 */
    R[2] = 0x6u << 16;  /* 0x800D0C14 */
    R[2] = R[2] | 0x4000;  /* 0x800D0C18 */
    sw_(R[29] + 16, R[20]);  /* 0x800D0C1C */
    R[4] = lw_(R[17] + 24);  /* 0x800D0C20 */
    R[5] = lw_(R[17] + 28);  /* 0x800D0C24 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0C28 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0C2C */
    R[4] = R[4] + R[16];  /* 0x800D0C30 */
    R[5] = R[5] + R[2];  /* 0x800D0C34 */
    { R[31] = 0x800D0C40u; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0C38 jal */
    R[3] = R[2] + R[0];  /* 0x800D0C40 */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0CA4; } }  /* 0x800D0C44 */
    R[2] = R[3] << 1;  /* 0x800D0C4C */
    R[2] = R[2] + R[3];  /* 0x800D0C50 */
    R[2] = R[2] << 3;  /* 0x800D0C54 */
    R[2] = R[2] + R[3];  /* 0x800D0C58 */
    R[2] = R[2] << 3;  /* 0x800D0C5C */
    R[2] = R[2] + R[3];  /* 0x800D0C60 */
    R[2] = R[2] << 2;  /* 0x800D0C64 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0C68 */
    R[2] = R[2] + R[19];  /* 0x800D0C6C */
    sb_(R[2] + 585, R[18]);  /* 0x800D0C70 */
    R[18] = R[18] + 1;  /* 0x800D0C74 */
    R[3] = R[0] + 1;  /* 0x800D0C78 */
    sb_(R[2] + 580, R[3]);  /* 0x800D0C7C */
    sb_(R[2] + 581, R[3]);  /* 0x800D0C80 */
    sh_(R[2] + 4, R[4]);  /* 0x800D0C84 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0C88 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0C8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_next = 0x800D0BC0u; return; } }  /* 0x800D0C90 b extern */
    R[2] = R[0] + 2;  /* 0x800D0C98 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0C9C */
    R[2] = R[0] + R[0];  /* 0x800D0CA0 */
L_800D0CA4:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0CA4 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0CA8 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0CAC */
    R[18] = lw_(R[29] + 32);  /* 0x800D0CB0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D0CB4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0CB8 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0CBC jr ra */
}

void g0_800D0C40(void) {
    R[3] = R[2] + R[0];  /* 0x800D0C40 */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0CA4; } }  /* 0x800D0C44 */
    R[2] = R[3] << 1;  /* 0x800D0C4C */
    R[2] = R[2] + R[3];  /* 0x800D0C50 */
    R[2] = R[2] << 3;  /* 0x800D0C54 */
    R[2] = R[2] + R[3];  /* 0x800D0C58 */
    R[2] = R[2] << 3;  /* 0x800D0C5C */
    R[2] = R[2] + R[3];  /* 0x800D0C60 */
    R[2] = R[2] << 2;  /* 0x800D0C64 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0C68 */
    R[2] = R[2] + R[19];  /* 0x800D0C6C */
    sb_(R[2] + 585, R[18]);  /* 0x800D0C70 */
    R[18] = R[18] + 1;  /* 0x800D0C74 */
    R[3] = R[0] + 1;  /* 0x800D0C78 */
    sb_(R[2] + 580, R[3]);  /* 0x800D0C7C */
    sb_(R[2] + 581, R[3]);  /* 0x800D0C80 */
    sh_(R[2] + 4, R[4]);  /* 0x800D0C84 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0C88 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0C8C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_next = 0x800D0BC0u; return; } }  /* 0x800D0C90 b extern */
    R[2] = R[0] + 2;  /* 0x800D0C98 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0C9C */
    R[2] = R[0] + R[0];  /* 0x800D0CA0 */
L_800D0CA4:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0CA4 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0CA8 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0CAC */
    R[18] = lw_(R[29] + 32);  /* 0x800D0CB0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D0CB4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0CB8 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0CBC jr ra */
}

void g0_800D0CC4(void) {
    R[29] = R[29] - 56;  /* 0x800D0CC4 */
    sw_(R[29] + 44, R[17]);  /* 0x800D0CC8 */
    R[17] = R[4] + R[0];  /* 0x800D0CCC */
    R[8] = 0x1Fu << 16;  /* 0x800D0CD0 */
    R[3] = 0x800Fu << 16;  /* 0x800D0CD4 */
    R[2] = 0x8013u << 16;  /* 0x800D0CD8 */
    R[2] = lw_(R[2] + -29424);  /* 0x800D0CDC */
    R[3] = R[3] + 4;  /* 0x800D0CE0 */
    sw_(R[29] + 48, R[31]);  /* 0x800D0CE4 */
    sw_(R[29] + 40, R[16]);  /* 0x800D0CE8 */
    sw_(R[3] + 28, R[2]);  /* 0x800D0CEC */
    R[5] = lw_(R[17] + 28);  /* 0x800D0CF0 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0CF4 */
    R[8] = R[8] | 0x4000;  /* 0x800D0CF8 */
    sw_(R[29] + 16, R[3]);  /* 0x800D0CFC */
    R[4] = lw_(R[17] + 24);  /* 0x800D0D00 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0D04 */
    { R[31] = 0x800D0D10u; R[5] = R[5] + R[8]; psx_next = 0x800889DCu; return; }  /* 0x800D0D08 jal */
    R[16] = R[2] + R[0];  /* 0x800D0D10 */
    { uint32_t _c = ((int32_t)R[16] < 0); R[6] = 0x12u << 16; if (_c) { goto L_800D0D94; } }  /* 0x800D0D14 */
    R[6] = R[6] | 0xC000;  /* 0x800D0D1C */
    R[2] = R[16] << 1;  /* 0x800D0D20 */
    R[2] = R[2] + R[16];  /* 0x800D0D24 */
    R[2] = R[2] << 3;  /* 0x800D0D28 */
    R[2] = R[2] + R[16];  /* 0x800D0D2C */
    R[2] = R[2] << 3;  /* 0x800D0D30 */
    R[2] = R[2] + R[16];  /* 0x800D0D34 */
    R[2] = R[2] << 2;  /* 0x800D0D38 */
    R[3] = 0x8012u << 16;  /* 0x800D0D3C */
    R[3] = R[3] - 26864;  /* 0x800D0D40 */
    R[2] = R[2] + R[3];  /* 0x800D0D44 */
    sw_(R[2] + 588, R[17]);  /* 0x800D0D48 */
    R[3] = lw_(R[17] + 24);  /* 0x800D0D4C */
    R[4] = R[0] + 18;  /* 0x800D0D50 */
    sw_(R[29] + 24, R[3]);  /* 0x800D0D54 */
    R[2] = lw_(R[2] + 28);  /* 0x800D0D58 */
    R[5] = R[17] + R[0];  /* 0x800D0D5C */
    R[2] = R[2] + R[6];  /* 0x800D0D60 */
    sw_(R[29] + 28, R[2]);  /* 0x800D0D64 */
    R[2] = lw_(R[17] + 32);  /* 0x800D0D68 */
    R[6] = R[29] + 24;  /* 0x800D0D6C */
    { R[31] = 0x800D0D78u; sw_(R[29] + 32, R[2]); psx_next = 0x800AC93Cu; return; }  /* 0x800D0D70 jal */
    R[2] = R[16] + R[0];  /* 0x800D0D78 */
    R[3] = lw_(R[17] + 16);  /* 0x800D0D7C */
    R[4] = R[0] - 897;  /* 0x800D0D80 */
    R[3] = R[3] & R[4];  /* 0x800D0D84 */
    R[3] = R[3] | 0x300;  /* 0x800D0D88 */
    { sw_(R[17] + 16, R[3]); goto L_800D0D98; }  /* 0x800D0D8C j */
L_800D0D94:;
    R[2] = R[0] - 1;  /* 0x800D0D94 */
L_800D0D98:;
    R[31] = lw_(R[29] + 48);  /* 0x800D0D98 */
    R[17] = lw_(R[29] + 44);  /* 0x800D0D9C */
    R[16] = lw_(R[29] + 40);  /* 0x800D0DA0 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800D0DA4 jr ra */
}

void g0_800D0D10(void) {
    R[16] = R[2] + R[0];  /* 0x800D0D10 */
    { uint32_t _c = ((int32_t)R[16] < 0); R[6] = 0x12u << 16; if (_c) { goto L_800D0D94; } }  /* 0x800D0D14 */
    R[6] = R[6] | 0xC000;  /* 0x800D0D1C */
    R[2] = R[16] << 1;  /* 0x800D0D20 */
    R[2] = R[2] + R[16];  /* 0x800D0D24 */
    R[2] = R[2] << 3;  /* 0x800D0D28 */
    R[2] = R[2] + R[16];  /* 0x800D0D2C */
    R[2] = R[2] << 3;  /* 0x800D0D30 */
    R[2] = R[2] + R[16];  /* 0x800D0D34 */
    R[2] = R[2] << 2;  /* 0x800D0D38 */
    R[3] = 0x8012u << 16;  /* 0x800D0D3C */
    R[3] = R[3] - 26864;  /* 0x800D0D40 */
    R[2] = R[2] + R[3];  /* 0x800D0D44 */
    sw_(R[2] + 588, R[17]);  /* 0x800D0D48 */
    R[3] = lw_(R[17] + 24);  /* 0x800D0D4C */
    R[4] = R[0] + 18;  /* 0x800D0D50 */
    sw_(R[29] + 24, R[3]);  /* 0x800D0D54 */
    R[2] = lw_(R[2] + 28);  /* 0x800D0D58 */
    R[5] = R[17] + R[0];  /* 0x800D0D5C */
    R[2] = R[2] + R[6];  /* 0x800D0D60 */
    sw_(R[29] + 28, R[2]);  /* 0x800D0D64 */
    R[2] = lw_(R[17] + 32);  /* 0x800D0D68 */
    R[6] = R[29] + 24;  /* 0x800D0D6C */
    { R[31] = 0x800D0D78u; sw_(R[29] + 32, R[2]); psx_next = 0x800AC93Cu; return; }  /* 0x800D0D70 jal */
    R[2] = R[16] + R[0];  /* 0x800D0D78 */
    R[3] = lw_(R[17] + 16);  /* 0x800D0D7C */
    R[4] = R[0] - 897;  /* 0x800D0D80 */
    R[3] = R[3] & R[4];  /* 0x800D0D84 */
    R[3] = R[3] | 0x300;  /* 0x800D0D88 */
    { sw_(R[17] + 16, R[3]); goto L_800D0D98; }  /* 0x800D0D8C j */
L_800D0D94:;
    R[2] = R[0] - 1;  /* 0x800D0D94 */
L_800D0D98:;
    R[31] = lw_(R[29] + 48);  /* 0x800D0D98 */
    R[17] = lw_(R[29] + 44);  /* 0x800D0D9C */
    R[16] = lw_(R[29] + 40);  /* 0x800D0DA0 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800D0DA4 jr ra */
}

void g0_800D0D78(void) {
    R[2] = R[16] + R[0];  /* 0x800D0D78 */
    R[3] = lw_(R[17] + 16);  /* 0x800D0D7C */
    R[4] = R[0] - 897;  /* 0x800D0D80 */
    R[3] = R[3] & R[4];  /* 0x800D0D84 */
    R[3] = R[3] | 0x300;  /* 0x800D0D88 */
    { sw_(R[17] + 16, R[3]); goto L_800D0D98; }  /* 0x800D0D8C j */
    R[2] = R[0] - 1;  /* 0x800D0D94 */
L_800D0D98:;
    R[31] = lw_(R[29] + 48);  /* 0x800D0D98 */
    R[17] = lw_(R[29] + 44);  /* 0x800D0D9C */
    R[16] = lw_(R[29] + 40);  /* 0x800D0DA0 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800D0DA4 jr ra */
}

void g0_800D0DAC(void) {
    R[29] = R[29] - 32;  /* 0x800D0DAC */
    R[3] = 0x6u << 16;  /* 0x800D0DB0 */
    R[3] = R[3] | 0x4000;  /* 0x800D0DB4 */
    R[2] = 0x8012u << 16;  /* 0x800D0DB8 */
    sw_(R[29] + 24, R[16]);  /* 0x800D0DBC */
    R[16] = R[2] - 26864;  /* 0x800D0DC0 */
    R[2] = 0x800Fu << 16;  /* 0x800D0DC4 */
    sw_(R[29] + 28, R[31]);  /* 0x800D0DC8 */
    R[5] = lw_(R[16] + 28);  /* 0x800D0DCC */
    R[2] = R[2] + 48;  /* 0x800D0DD0 */
    sw_(R[29] + 16, R[2]);  /* 0x800D0DD4 */
    R[7] = (uint32_t)(int16_t)lh_(R[16] + 4);  /* 0x800D0DD8 */
    R[4] = lw_(R[16] + 24);  /* 0x800D0DDC */
    R[6] = lw_(R[16] + 32);  /* 0x800D0DE0 */
    { R[31] = 0x800D0DECu; R[5] = R[5] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0DE4 jal */
    R[4] = R[2] + R[0];  /* 0x800D0DEC */
    { uint32_t _c = ((int32_t)R[4] < 0); R[2] = R[0] + R[0]; if (_c) { goto L_800D0E44; } }  /* 0x800D0DF0 */
    R[3] = R[4] << 1;  /* 0x800D0DF8 */
    R[3] = R[3] + R[4];  /* 0x800D0DFC */
    R[3] = R[3] << 3;  /* 0x800D0E00 */
    R[3] = R[3] + R[4];  /* 0x800D0E04 */
    R[3] = R[3] << 3;  /* 0x800D0E08 */
    R[3] = R[3] + R[4];  /* 0x800D0E0C */
    R[3] = R[3] << 2;  /* 0x800D0E10 */
    R[3] = R[3] + R[16];  /* 0x800D0E14 */
    R[4] = R[0] + 3;  /* 0x800D0E18 */
    R[6] = lh_(R[16] + 4);  /* 0x800D0E1C */
    R[5] = 0x8014u << 16;  /* 0x800D0E20 */
    sb_(R[3] + 580, R[4]);  /* 0x800D0E24 */
    R[4] = R[0] + 1;  /* 0x800D0E28 */
    sb_(R[3] + 585, R[0]);  /* 0x800D0E2C */
    sb_(R[3] + 581, R[0]);  /* 0x800D0E30 */
    sw_(R[5] + 15016, R[4]);  /* 0x800D0E34 */
    sh_(R[3] + 4, R[6]);  /* 0x800D0E38 */
    { sh_(R[3] + 6, R[6]); goto L_800D0E48; }  /* 0x800D0E3C j */
L_800D0E44:;
    R[2] = R[0] - 1;  /* 0x800D0E44 */
L_800D0E48:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0E48 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0E4C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0E50 jr ra */
}

void g0_800D0DEC(void) {
    R[4] = R[2] + R[0];  /* 0x800D0DEC */
    { uint32_t _c = ((int32_t)R[4] < 0); R[2] = R[0] + R[0]; if (_c) { goto L_800D0E44; } }  /* 0x800D0DF0 */
    R[3] = R[4] << 1;  /* 0x800D0DF8 */
    R[3] = R[3] + R[4];  /* 0x800D0DFC */
    R[3] = R[3] << 3;  /* 0x800D0E00 */
    R[3] = R[3] + R[4];  /* 0x800D0E04 */
    R[3] = R[3] << 3;  /* 0x800D0E08 */
    R[3] = R[3] + R[4];  /* 0x800D0E0C */
    R[3] = R[3] << 2;  /* 0x800D0E10 */
    R[3] = R[3] + R[16];  /* 0x800D0E14 */
    R[4] = R[0] + 3;  /* 0x800D0E18 */
    R[6] = lh_(R[16] + 4);  /* 0x800D0E1C */
    R[5] = 0x8014u << 16;  /* 0x800D0E20 */
    sb_(R[3] + 580, R[4]);  /* 0x800D0E24 */
    R[4] = R[0] + 1;  /* 0x800D0E28 */
    sb_(R[3] + 585, R[0]);  /* 0x800D0E2C */
    sb_(R[3] + 581, R[0]);  /* 0x800D0E30 */
    sw_(R[5] + 15016, R[4]);  /* 0x800D0E34 */
    sh_(R[3] + 4, R[6]);  /* 0x800D0E38 */
    { sh_(R[3] + 6, R[6]); goto L_800D0E48; }  /* 0x800D0E3C j */
L_800D0E44:;
    R[2] = R[0] - 1;  /* 0x800D0E44 */
L_800D0E48:;
    R[31] = lw_(R[29] + 28);  /* 0x800D0E48 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0E4C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D0E50 jr ra */
}

void g0_800D0E58(void) {
    R[29] = R[29] - 48;  /* 0x800D0E58 */
    sw_(R[29] + 32, R[18]);  /* 0x800D0E5C */
    R[18] = R[0] + R[0];  /* 0x800D0E60 */
    R[2] = 0x800Fu << 16;  /* 0x800D0E64 */
    sw_(R[29] + 40, R[20]);  /* 0x800D0E68 */
    R[20] = R[2] + 92;  /* 0x800D0E6C */
    R[2] = 0x8012u << 16;  /* 0x800D0E70 */
    sw_(R[29] + 28, R[17]);  /* 0x800D0E74 */
    R[17] = R[2] - 26864;  /* 0x800D0E78 */
    sw_(R[29] + 36, R[19]);  /* 0x800D0E7C */
    R[19] = R[17] + R[0];  /* 0x800D0E80 */
    sw_(R[29] + 44, R[31]);  /* 0x800D0E84 */
    sw_(R[29] + 24, R[16]);  /* 0x800D0E88 */
L_800D0E8C:;
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_800D0EBC; } }  /* 0x800D0E8C */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0E94 */
    { R[31] = 0x800D0EA0u; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D0E98 jal */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0EA0 */
    R[16] = R[2] << 5;  /* 0x800D0EA4 */
    { R[31] = 0x800D0EB0u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0EA8 jal */
    R[2] = R[2] << 5;  /* 0x800D0EB0 */
    { R[3] = R[0] - R[2]; goto L_800D0EE0; }  /* 0x800D0EB4 j */
L_800D0EBC:;
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0EBC */
    { R[31] = 0x800D0EC8u; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D0EC0 jal */
    R[2] = R[2] << 5;  /* 0x800D0EC8 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0ECC */
    R[16] = R[0] - R[2];  /* 0x800D0ED0 */
    { R[31] = 0x800D0EDCu; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0ED4 jal */
    R[3] = R[2] << 5;  /* 0x800D0EDC */
L_800D0EE0:;
    R[2] = 0x6u << 16;  /* 0x800D0EE0 */
    R[2] = R[2] | 0x4000;  /* 0x800D0EE4 */
    sw_(R[29] + 16, R[20]);  /* 0x800D0EE8 */
    R[4] = lw_(R[17] + 24);  /* 0x800D0EEC */
    R[5] = lw_(R[17] + 28);  /* 0x800D0EF0 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0EF4 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0EF8 */
    R[4] = R[4] + R[16];  /* 0x800D0EFC */
    R[5] = R[5] + R[2];  /* 0x800D0F00 */
    { R[31] = 0x800D0F0Cu; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0F04 jal */
    R[3] = R[2] + R[0];  /* 0x800D0F0C */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0F74; } }  /* 0x800D0F10 */
    R[2] = R[3] << 1;  /* 0x800D0F18 */
    R[2] = R[2] + R[3];  /* 0x800D0F1C */
    R[2] = R[2] << 3;  /* 0x800D0F20 */
    R[2] = R[2] + R[3];  /* 0x800D0F24 */
    R[2] = R[2] << 3;  /* 0x800D0F28 */
    R[2] = R[2] + R[3];  /* 0x800D0F2C */
    R[2] = R[2] << 2;  /* 0x800D0F30 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0F34 */
    R[2] = R[2] + R[19];  /* 0x800D0F38 */
    sb_(R[2] + 585, R[18]);  /* 0x800D0F3C */
    R[18] = R[18] + 1;  /* 0x800D0F40 */
    R[3] = R[0] + 3;  /* 0x800D0F44 */
    sb_(R[2] + 580, R[3]);  /* 0x800D0F48 */
    R[3] = R[0] + 1;  /* 0x800D0F4C */
    sb_(R[2] + 581, R[3]);  /* 0x800D0F50 */
    sh_(R[2] + 4, R[4]);  /* 0x800D0F54 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0F58 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0F5C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_bb(); goto L_800D0E8C; } }  /* 0x800D0F60 */
    R[2] = R[0] + 2;  /* 0x800D0F68 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0F6C */
    R[2] = R[0] + R[0];  /* 0x800D0F70 */
L_800D0F74:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0F74 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0F78 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0F7C */
    R[18] = lw_(R[29] + 32);  /* 0x800D0F80 */
    R[17] = lw_(R[29] + 28);  /* 0x800D0F84 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0F88 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0F8C jr ra */
}

void g0_800D0E8C(void) {
L_800D0E8C:;
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_800D0EBC; } }  /* 0x800D0E8C */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0E94 */
    { R[31] = 0x800D0EA0u; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D0E98 jal */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0EA0 */
    R[16] = R[2] << 5;  /* 0x800D0EA4 */
    { R[31] = 0x800D0EB0u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0EA8 jal */
    R[2] = R[2] << 5;  /* 0x800D0EB0 */
    { R[3] = R[0] - R[2]; goto L_800D0EE0; }  /* 0x800D0EB4 j */
L_800D0EBC:;
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0EBC */
    { R[31] = 0x800D0EC8u; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D0EC0 jal */
    R[2] = R[2] << 5;  /* 0x800D0EC8 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0ECC */
    R[16] = R[0] - R[2];  /* 0x800D0ED0 */
    { R[31] = 0x800D0EDCu; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0ED4 jal */
    R[3] = R[2] << 5;  /* 0x800D0EDC */
L_800D0EE0:;
    R[2] = 0x6u << 16;  /* 0x800D0EE0 */
    R[2] = R[2] | 0x4000;  /* 0x800D0EE4 */
    sw_(R[29] + 16, R[20]);  /* 0x800D0EE8 */
    R[4] = lw_(R[17] + 24);  /* 0x800D0EEC */
    R[5] = lw_(R[17] + 28);  /* 0x800D0EF0 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0EF4 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0EF8 */
    R[4] = R[4] + R[16];  /* 0x800D0EFC */
    R[5] = R[5] + R[2];  /* 0x800D0F00 */
    { R[31] = 0x800D0F0Cu; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0F04 jal */
    R[3] = R[2] + R[0];  /* 0x800D0F0C */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0F74; } }  /* 0x800D0F10 */
    R[2] = R[3] << 1;  /* 0x800D0F18 */
    R[2] = R[2] + R[3];  /* 0x800D0F1C */
    R[2] = R[2] << 3;  /* 0x800D0F20 */
    R[2] = R[2] + R[3];  /* 0x800D0F24 */
    R[2] = R[2] << 3;  /* 0x800D0F28 */
    R[2] = R[2] + R[3];  /* 0x800D0F2C */
    R[2] = R[2] << 2;  /* 0x800D0F30 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0F34 */
    R[2] = R[2] + R[19];  /* 0x800D0F38 */
    sb_(R[2] + 585, R[18]);  /* 0x800D0F3C */
    R[18] = R[18] + 1;  /* 0x800D0F40 */
    R[3] = R[0] + 3;  /* 0x800D0F44 */
    sb_(R[2] + 580, R[3]);  /* 0x800D0F48 */
    R[3] = R[0] + 1;  /* 0x800D0F4C */
    sb_(R[2] + 581, R[3]);  /* 0x800D0F50 */
    sh_(R[2] + 4, R[4]);  /* 0x800D0F54 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0F58 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0F5C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_bb(); goto L_800D0E8C; } }  /* 0x800D0F60 */
    R[2] = R[0] + 2;  /* 0x800D0F68 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0F6C */
    R[2] = R[0] + R[0];  /* 0x800D0F70 */
L_800D0F74:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0F74 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0F78 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0F7C */
    R[18] = lw_(R[29] + 32);  /* 0x800D0F80 */
    R[17] = lw_(R[29] + 28);  /* 0x800D0F84 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0F88 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0F8C jr ra */
}

void g0_800D0EA0(void) {
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0EA0 */
    R[16] = R[2] << 5;  /* 0x800D0EA4 */
    { R[31] = 0x800D0EB0u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0EA8 jal */
    R[2] = R[2] << 5;  /* 0x800D0EB0 */
    { R[3] = R[0] - R[2]; goto L_800D0EE0; }  /* 0x800D0EB4 j */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0EBC */
    { R[31] = 0x800D0EC8u; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D0EC0 jal */
    R[2] = R[2] << 5;  /* 0x800D0EC8 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0ECC */
    R[16] = R[0] - R[2];  /* 0x800D0ED0 */
    { R[31] = 0x800D0EDCu; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0ED4 jal */
    R[3] = R[2] << 5;  /* 0x800D0EDC */
L_800D0EE0:;
    R[2] = 0x6u << 16;  /* 0x800D0EE0 */
    R[2] = R[2] | 0x4000;  /* 0x800D0EE4 */
    sw_(R[29] + 16, R[20]);  /* 0x800D0EE8 */
    R[4] = lw_(R[17] + 24);  /* 0x800D0EEC */
    R[5] = lw_(R[17] + 28);  /* 0x800D0EF0 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0EF4 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0EF8 */
    R[4] = R[4] + R[16];  /* 0x800D0EFC */
    R[5] = R[5] + R[2];  /* 0x800D0F00 */
    { R[31] = 0x800D0F0Cu; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0F04 jal */
    R[3] = R[2] + R[0];  /* 0x800D0F0C */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0F74; } }  /* 0x800D0F10 */
    R[2] = R[3] << 1;  /* 0x800D0F18 */
    R[2] = R[2] + R[3];  /* 0x800D0F1C */
    R[2] = R[2] << 3;  /* 0x800D0F20 */
    R[2] = R[2] + R[3];  /* 0x800D0F24 */
    R[2] = R[2] << 3;  /* 0x800D0F28 */
    R[2] = R[2] + R[3];  /* 0x800D0F2C */
    R[2] = R[2] << 2;  /* 0x800D0F30 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0F34 */
    R[2] = R[2] + R[19];  /* 0x800D0F38 */
    sb_(R[2] + 585, R[18]);  /* 0x800D0F3C */
    R[18] = R[18] + 1;  /* 0x800D0F40 */
    R[3] = R[0] + 3;  /* 0x800D0F44 */
    sb_(R[2] + 580, R[3]);  /* 0x800D0F48 */
    R[3] = R[0] + 1;  /* 0x800D0F4C */
    sb_(R[2] + 581, R[3]);  /* 0x800D0F50 */
    sh_(R[2] + 4, R[4]);  /* 0x800D0F54 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0F58 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0F5C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_next = 0x800D0E8Cu; return; } }  /* 0x800D0F60 b extern */
    R[2] = R[0] + 2;  /* 0x800D0F68 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0F6C */
    R[2] = R[0] + R[0];  /* 0x800D0F70 */
L_800D0F74:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0F74 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0F78 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0F7C */
    R[18] = lw_(R[29] + 32);  /* 0x800D0F80 */
    R[17] = lw_(R[29] + 28);  /* 0x800D0F84 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0F88 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0F8C jr ra */
}

void g0_800D0EB0(void) {
    R[2] = R[2] << 5;  /* 0x800D0EB0 */
    { R[3] = R[0] - R[2]; goto L_800D0EE0; }  /* 0x800D0EB4 j */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0EBC */
    { R[31] = 0x800D0EC8u; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D0EC0 jal */
    R[2] = R[2] << 5;  /* 0x800D0EC8 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0ECC */
    R[16] = R[0] - R[2];  /* 0x800D0ED0 */
    { R[31] = 0x800D0EDCu; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0ED4 jal */
    R[3] = R[2] << 5;  /* 0x800D0EDC */
L_800D0EE0:;
    R[2] = 0x6u << 16;  /* 0x800D0EE0 */
    R[2] = R[2] | 0x4000;  /* 0x800D0EE4 */
    sw_(R[29] + 16, R[20]);  /* 0x800D0EE8 */
    R[4] = lw_(R[17] + 24);  /* 0x800D0EEC */
    R[5] = lw_(R[17] + 28);  /* 0x800D0EF0 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0EF4 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0EF8 */
    R[4] = R[4] + R[16];  /* 0x800D0EFC */
    R[5] = R[5] + R[2];  /* 0x800D0F00 */
    { R[31] = 0x800D0F0Cu; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0F04 jal */
    R[3] = R[2] + R[0];  /* 0x800D0F0C */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0F74; } }  /* 0x800D0F10 */
    R[2] = R[3] << 1;  /* 0x800D0F18 */
    R[2] = R[2] + R[3];  /* 0x800D0F1C */
    R[2] = R[2] << 3;  /* 0x800D0F20 */
    R[2] = R[2] + R[3];  /* 0x800D0F24 */
    R[2] = R[2] << 3;  /* 0x800D0F28 */
    R[2] = R[2] + R[3];  /* 0x800D0F2C */
    R[2] = R[2] << 2;  /* 0x800D0F30 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0F34 */
    R[2] = R[2] + R[19];  /* 0x800D0F38 */
    sb_(R[2] + 585, R[18]);  /* 0x800D0F3C */
    R[18] = R[18] + 1;  /* 0x800D0F40 */
    R[3] = R[0] + 3;  /* 0x800D0F44 */
    sb_(R[2] + 580, R[3]);  /* 0x800D0F48 */
    R[3] = R[0] + 1;  /* 0x800D0F4C */
    sb_(R[2] + 581, R[3]);  /* 0x800D0F50 */
    sh_(R[2] + 4, R[4]);  /* 0x800D0F54 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0F58 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0F5C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_next = 0x800D0E8Cu; return; } }  /* 0x800D0F60 b extern */
    R[2] = R[0] + 2;  /* 0x800D0F68 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0F6C */
    R[2] = R[0] + R[0];  /* 0x800D0F70 */
L_800D0F74:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0F74 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0F78 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0F7C */
    R[18] = lw_(R[29] + 32);  /* 0x800D0F80 */
    R[17] = lw_(R[29] + 28);  /* 0x800D0F84 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0F88 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0F8C jr ra */
}

void g0_800D0EC8(void) {
    R[2] = R[2] << 5;  /* 0x800D0EC8 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0ECC */
    R[16] = R[0] - R[2];  /* 0x800D0ED0 */
    { R[31] = 0x800D0EDCu; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D0ED4 jal */
    R[3] = R[2] << 5;  /* 0x800D0EDC */
    R[2] = 0x6u << 16;  /* 0x800D0EE0 */
    R[2] = R[2] | 0x4000;  /* 0x800D0EE4 */
    sw_(R[29] + 16, R[20]);  /* 0x800D0EE8 */
    R[4] = lw_(R[17] + 24);  /* 0x800D0EEC */
    R[5] = lw_(R[17] + 28);  /* 0x800D0EF0 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0EF4 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0EF8 */
    R[4] = R[4] + R[16];  /* 0x800D0EFC */
    R[5] = R[5] + R[2];  /* 0x800D0F00 */
    { R[31] = 0x800D0F0Cu; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0F04 jal */
    R[3] = R[2] + R[0];  /* 0x800D0F0C */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0F74; } }  /* 0x800D0F10 */
    R[2] = R[3] << 1;  /* 0x800D0F18 */
    R[2] = R[2] + R[3];  /* 0x800D0F1C */
    R[2] = R[2] << 3;  /* 0x800D0F20 */
    R[2] = R[2] + R[3];  /* 0x800D0F24 */
    R[2] = R[2] << 3;  /* 0x800D0F28 */
    R[2] = R[2] + R[3];  /* 0x800D0F2C */
    R[2] = R[2] << 2;  /* 0x800D0F30 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0F34 */
    R[2] = R[2] + R[19];  /* 0x800D0F38 */
    sb_(R[2] + 585, R[18]);  /* 0x800D0F3C */
    R[18] = R[18] + 1;  /* 0x800D0F40 */
    R[3] = R[0] + 3;  /* 0x800D0F44 */
    sb_(R[2] + 580, R[3]);  /* 0x800D0F48 */
    R[3] = R[0] + 1;  /* 0x800D0F4C */
    sb_(R[2] + 581, R[3]);  /* 0x800D0F50 */
    sh_(R[2] + 4, R[4]);  /* 0x800D0F54 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0F58 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0F5C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_next = 0x800D0E8Cu; return; } }  /* 0x800D0F60 b extern */
    R[2] = R[0] + 2;  /* 0x800D0F68 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0F6C */
    R[2] = R[0] + R[0];  /* 0x800D0F70 */
L_800D0F74:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0F74 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0F78 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0F7C */
    R[18] = lw_(R[29] + 32);  /* 0x800D0F80 */
    R[17] = lw_(R[29] + 28);  /* 0x800D0F84 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0F88 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0F8C jr ra */
}

void g0_800D0EDC(void) {
    R[3] = R[2] << 5;  /* 0x800D0EDC */
    R[2] = 0x6u << 16;  /* 0x800D0EE0 */
    R[2] = R[2] | 0x4000;  /* 0x800D0EE4 */
    sw_(R[29] + 16, R[20]);  /* 0x800D0EE8 */
    R[4] = lw_(R[17] + 24);  /* 0x800D0EEC */
    R[5] = lw_(R[17] + 28);  /* 0x800D0EF0 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0EF4 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D0EF8 */
    R[4] = R[4] + R[16];  /* 0x800D0EFC */
    R[5] = R[5] + R[2];  /* 0x800D0F00 */
    { R[31] = 0x800D0F0Cu; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D0F04 jal */
    R[3] = R[2] + R[0];  /* 0x800D0F0C */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0F74; } }  /* 0x800D0F10 */
    R[2] = R[3] << 1;  /* 0x800D0F18 */
    R[2] = R[2] + R[3];  /* 0x800D0F1C */
    R[2] = R[2] << 3;  /* 0x800D0F20 */
    R[2] = R[2] + R[3];  /* 0x800D0F24 */
    R[2] = R[2] << 3;  /* 0x800D0F28 */
    R[2] = R[2] + R[3];  /* 0x800D0F2C */
    R[2] = R[2] << 2;  /* 0x800D0F30 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0F34 */
    R[2] = R[2] + R[19];  /* 0x800D0F38 */
    sb_(R[2] + 585, R[18]);  /* 0x800D0F3C */
    R[18] = R[18] + 1;  /* 0x800D0F40 */
    R[3] = R[0] + 3;  /* 0x800D0F44 */
    sb_(R[2] + 580, R[3]);  /* 0x800D0F48 */
    R[3] = R[0] + 1;  /* 0x800D0F4C */
    sb_(R[2] + 581, R[3]);  /* 0x800D0F50 */
    sh_(R[2] + 4, R[4]);  /* 0x800D0F54 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0F58 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0F5C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_next = 0x800D0E8Cu; return; } }  /* 0x800D0F60 b extern */
    R[2] = R[0] + 2;  /* 0x800D0F68 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0F6C */
    R[2] = R[0] + R[0];  /* 0x800D0F70 */
L_800D0F74:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0F74 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0F78 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0F7C */
    R[18] = lw_(R[29] + 32);  /* 0x800D0F80 */
    R[17] = lw_(R[29] + 28);  /* 0x800D0F84 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0F88 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0F8C jr ra */
}

void g0_800D0F0C(void) {
    R[3] = R[2] + R[0];  /* 0x800D0F0C */
    { uint32_t _c = ((int32_t)R[3] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D0F74; } }  /* 0x800D0F10 */
    R[2] = R[3] << 1;  /* 0x800D0F18 */
    R[2] = R[2] + R[3];  /* 0x800D0F1C */
    R[2] = R[2] << 3;  /* 0x800D0F20 */
    R[2] = R[2] + R[3];  /* 0x800D0F24 */
    R[2] = R[2] << 3;  /* 0x800D0F28 */
    R[2] = R[2] + R[3];  /* 0x800D0F2C */
    R[2] = R[2] << 2;  /* 0x800D0F30 */
    R[4] = lh_(R[17] + 4);  /* 0x800D0F34 */
    R[2] = R[2] + R[19];  /* 0x800D0F38 */
    sb_(R[2] + 585, R[18]);  /* 0x800D0F3C */
    R[18] = R[18] + 1;  /* 0x800D0F40 */
    R[3] = R[0] + 3;  /* 0x800D0F44 */
    sb_(R[2] + 580, R[3]);  /* 0x800D0F48 */
    R[3] = R[0] + 1;  /* 0x800D0F4C */
    sb_(R[2] + 581, R[3]);  /* 0x800D0F50 */
    sh_(R[2] + 4, R[4]);  /* 0x800D0F54 */
    sh_(R[2] + 6, R[4]);  /* 0x800D0F58 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D0F5C */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8014u << 16; if (_c) { psx_next = 0x800D0E8Cu; return; } }  /* 0x800D0F60 b extern */
    R[2] = R[0] + 2;  /* 0x800D0F68 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D0F6C */
    R[2] = R[0] + R[0];  /* 0x800D0F70 */
L_800D0F74:;
    R[31] = lw_(R[29] + 44);  /* 0x800D0F74 */
    R[20] = lw_(R[29] + 40);  /* 0x800D0F78 */
    R[19] = lw_(R[29] + 36);  /* 0x800D0F7C */
    R[18] = lw_(R[29] + 32);  /* 0x800D0F80 */
    R[17] = lw_(R[29] + 28);  /* 0x800D0F84 */
    R[16] = lw_(R[29] + 24);  /* 0x800D0F88 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D0F8C jr ra */
}

void g0_800D0F94(void) {
    R[29] = R[29] - 56;  /* 0x800D0F94 */
    sw_(R[29] + 44, R[17]);  /* 0x800D0F98 */
    R[17] = R[4] + R[0];  /* 0x800D0F9C */
    R[3] = 0x800Fu << 16;  /* 0x800D0FA0 */
    R[2] = 0x8013u << 16;  /* 0x800D0FA4 */
    R[2] = R[2] - 29480;  /* 0x800D0FA8 */
    sw_(R[29] + 52, R[31]);  /* 0x800D0FAC */
    sw_(R[29] + 48, R[18]);  /* 0x800D0FB0 */
    sw_(R[29] + 40, R[16]);  /* 0x800D0FB4 */
    R[4] = lw_(R[2] + 60);  /* 0x800D0FB8 */
    R[2] = lw_(R[2] + 64);  /* 0x800D0FBC */
    R[3] = R[3] + 136;  /* 0x800D0FC0 */
    sw_(R[3] + 28, R[4]);  /* 0x800D0FC4 */
    sw_(R[3] + 32, R[2]);  /* 0x800D0FC8 */
    R[5] = lw_(R[17] + 488);  /* 0x800D0FCC */
    R[7] = lw_(R[17] + 28);  /* 0x800D0FD0 */
    sw_(R[29] + 16, R[3]);  /* 0x800D0FD4 */
    R[4] = lw_(R[17] + 24);  /* 0x800D0FD8 */
    R[6] = lw_(R[17] + 32);  /* 0x800D0FDC */
    R[2] = R[5] >> 31;  /* 0x800D0FE0 */
    R[5] = R[5] + R[2];  /* 0x800D0FE4 */
    R[5] = (uint32_t)((int32_t)R[5] >> 1);  /* 0x800D0FE8 */
    R[5] = R[7] + R[5];  /* 0x800D0FEC */
    { R[31] = 0x800D0FF8u; R[7] = R[0] + R[0]; psx_next = 0x800889DCu; return; }  /* 0x800D0FF0 jal */
    R[18] = R[2] + R[0];  /* 0x800D0FF8 */
    { uint32_t _c = ((int32_t)R[18] < 0); R[2] = R[0] - 1; if (_c) { psx_next = 0x800D1174u; return; } }  /* 0x800D0FFC b extern */
    psx_next = 0x800D1004u; return;  /* fallthrough */
}

void g0_800D0FF8(void) {
    R[18] = R[2] + R[0];  /* 0x800D0FF8 */
    { uint32_t _c = ((int32_t)R[18] < 0); R[2] = R[0] - 1; if (_c) { psx_next = 0x800D1174u; return; } }  /* 0x800D0FFC b extern */
    psx_next = 0x800D1004u; return;  /* fallthrough */
}

void g0_800D1004(void) {
    R[2] = R[18] << 1;  /* 0x800D1004 */
    R[2] = R[2] + R[18];  /* 0x800D1008 */
    R[2] = R[2] << 3;  /* 0x800D100C */
    R[2] = R[2] + R[18];  /* 0x800D1010 */
    R[2] = R[2] << 3;  /* 0x800D1014 */
    R[2] = R[2] + R[18];  /* 0x800D1018 */
    R[2] = R[2] << 2;  /* 0x800D101C */
    R[3] = 0x8012u << 16;  /* 0x800D1020 */
    R[3] = R[3] - 26864;  /* 0x800D1024 */
    R[16] = R[2] + R[3];  /* 0x800D1028 */
    R[4] = R[16] + R[0];  /* 0x800D102C */
    { R[31] = 0x800D1038u; R[5] = R[0] + 7; psx_next = 0x800A9E2Cu; return; }  /* 0x800D1030 jal */
    sw_(R[16] + 588, R[17]);  /* 0x800D1038 */
    sh_(R[16] + 584, R[0]);  /* 0x800D103C */
    R[2] = lw_(R[17] + 484);  /* 0x800D1040 */
    R[3] = R[0] + 2;  /* 0x800D1044 */
    sh_(R[16] + 586, R[3]);  /* 0x800D1048 */
    R[3] = R[2] >> 31;  /* 0x800D104C */
    R[2] = R[2] + R[3];  /* 0x800D1050 */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x800D1054 */
    sw_(R[16] + 592, R[2]);  /* 0x800D1058 */
    R[2] = lw_(R[17] + 488);  /* 0x800D105C */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800D1070; } }  /* 0x800D1064 */
    R[2] = R[2] + 3;  /* 0x800D106C */
L_800D1070:;
    R[2] = (uint32_t)((int32_t)R[2] >> 2);  /* 0x800D1070 */
    R[2] = R[0] - R[2];  /* 0x800D1074 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800D1084; } }  /* 0x800D1078 */
    R[2] = R[2] + 4095;  /* 0x800D1080 */
L_800D1084:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800D1084 */
    sh_(R[16] + 596, R[2]);  /* 0x800D1088 */
    R[2] = lw_(R[17] + 488);  /* 0x800D108C */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800D10A0; } }  /* 0x800D1094 */
    R[2] = R[2] + 16383;  /* 0x800D109C */
L_800D10A0:;
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 584);  /* 0x800D10A0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 14);  /* 0x800D10A4 */
    sh_(R[16] + 598, R[2]);  /* 0x800D10A8 */
    R[2] = R[0] + 1;  /* 0x800D10AC */
    sh_(R[16] + 604, R[2]);  /* 0x800D10B0 */
    { R[31] = 0x800D10BCu; sw_(R[16] + 600, R[0]); psx_next = 0x80035B18u; return; }  /* 0x800D10B4 jal */
    R[3] = lw_(R[16] + 592);  /* 0x800D10BC */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800D10C4 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 584);  /* 0x800D10C8 */
    R[8] = LO;  /* 0x800D10CC */
    { R[31] = 0x800D10D8u; sw_(R[16] + 36, R[8]); psx_next = 0x80035A48u; return; }  /* 0x800D10D0 jal */
    R[3] = lw_(R[16] + 592);  /* 0x800D10D8 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800D10E0 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 584);  /* 0x800D10E4 */
    R[8] = LO;  /* 0x800D10E8 */
    { R[31] = 0x800D10F4u; sw_(R[16] + 44, R[8]); psx_next = 0x80035B18u; return; }  /* 0x800D10EC jal */
    R[3] = R[2] << 2;  /* 0x800D10F4 */
    R[3] = R[3] + R[2];  /* 0x800D10F8 */
    R[2] = R[3] << 4;  /* 0x800D10FC */
    R[2] = R[2] - R[3];  /* 0x800D1100 */
    R[3] = lw_(R[17] + 24);  /* 0x800D1104 */
    R[2] = R[2] << 2;  /* 0x800D1108 */
    R[3] = R[3] + R[2];  /* 0x800D110C */
    sw_(R[29] + 24, R[3]);  /* 0x800D1110 */
    R[2] = lw_(R[16] + 28);  /* 0x800D1114 */
    sw_(R[29] + 28, R[2]);  /* 0x800D111C */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 584);  /* 0x800D1120 */
    { R[31] = 0x800D112Cu; psx_next = 0x80035A48u; return; }  /* 0x800D1124 jal */
    R[4] = R[0] + 19;  /* 0x800D112C */
    R[5] = R[17] + R[0];  /* 0x800D1130 */
    R[6] = R[29] + 24;  /* 0x800D1134 */
    R[3] = R[2] << 2;  /* 0x800D1138 */
    R[3] = R[3] + R[2];  /* 0x800D113C */
    R[2] = R[3] << 4;  /* 0x800D1140 */
    R[2] = R[2] - R[3];  /* 0x800D1144 */
    R[3] = lw_(R[17] + 32);  /* 0x800D1148 */
    R[2] = R[2] << 2;  /* 0x800D114C */
    R[3] = R[3] + R[2];  /* 0x800D1150 */
    { R[31] = 0x800D115Cu; sw_(R[29] + 32, R[3]); psx_next = 0x800AC93Cu; return; }  /* 0x800D1154 jal */
    R[2] = R[18] + R[0];  /* 0x800D115C */
    R[3] = lw_(R[17] + 16);  /* 0x800D1160 */
    R[4] = R[0] - 897;  /* 0x800D1164 */
    R[3] = R[3] & R[4];  /* 0x800D1168 */
    R[3] = R[3] | 0x280;  /* 0x800D116C */
    sw_(R[17] + 16, R[3]);  /* 0x800D1170 */
    R[31] = lw_(R[29] + 52);  /* 0x800D1174 */
    R[18] = lw_(R[29] + 48);  /* 0x800D1178 */
    R[17] = lw_(R[29] + 44);  /* 0x800D117C */
    R[16] = lw_(R[29] + 40);  /* 0x800D1180 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800D1184 jr ra */
}

void g0_800D1038(void) {
    sw_(R[16] + 588, R[17]);  /* 0x800D1038 */
    sh_(R[16] + 584, R[0]);  /* 0x800D103C */
    R[2] = lw_(R[17] + 484);  /* 0x800D1040 */
    R[3] = R[0] + 2;  /* 0x800D1044 */
    sh_(R[16] + 586, R[3]);  /* 0x800D1048 */
    R[3] = R[2] >> 31;  /* 0x800D104C */
    R[2] = R[2] + R[3];  /* 0x800D1050 */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x800D1054 */
    sw_(R[16] + 592, R[2]);  /* 0x800D1058 */
    R[2] = lw_(R[17] + 488);  /* 0x800D105C */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800D1070; } }  /* 0x800D1064 */
    R[2] = R[2] + 3;  /* 0x800D106C */
L_800D1070:;
    R[2] = (uint32_t)((int32_t)R[2] >> 2);  /* 0x800D1070 */
    R[2] = R[0] - R[2];  /* 0x800D1074 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800D1084; } }  /* 0x800D1078 */
    R[2] = R[2] + 4095;  /* 0x800D1080 */
L_800D1084:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800D1084 */
    sh_(R[16] + 596, R[2]);  /* 0x800D1088 */
    R[2] = lw_(R[17] + 488);  /* 0x800D108C */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800D10A0; } }  /* 0x800D1094 */
    R[2] = R[2] + 16383;  /* 0x800D109C */
L_800D10A0:;
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 584);  /* 0x800D10A0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 14);  /* 0x800D10A4 */
    sh_(R[16] + 598, R[2]);  /* 0x800D10A8 */
    R[2] = R[0] + 1;  /* 0x800D10AC */
    sh_(R[16] + 604, R[2]);  /* 0x800D10B0 */
    { R[31] = 0x800D10BCu; sw_(R[16] + 600, R[0]); psx_next = 0x80035B18u; return; }  /* 0x800D10B4 jal */
    R[3] = lw_(R[16] + 592);  /* 0x800D10BC */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800D10C4 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 584);  /* 0x800D10C8 */
    R[8] = LO;  /* 0x800D10CC */
    { R[31] = 0x800D10D8u; sw_(R[16] + 36, R[8]); psx_next = 0x80035A48u; return; }  /* 0x800D10D0 jal */
    R[3] = lw_(R[16] + 592);  /* 0x800D10D8 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800D10E0 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 584);  /* 0x800D10E4 */
    R[8] = LO;  /* 0x800D10E8 */
    { R[31] = 0x800D10F4u; sw_(R[16] + 44, R[8]); psx_next = 0x80035B18u; return; }  /* 0x800D10EC jal */
    R[3] = R[2] << 2;  /* 0x800D10F4 */
    R[3] = R[3] + R[2];  /* 0x800D10F8 */
    R[2] = R[3] << 4;  /* 0x800D10FC */
    R[2] = R[2] - R[3];  /* 0x800D1100 */
    R[3] = lw_(R[17] + 24);  /* 0x800D1104 */
    R[2] = R[2] << 2;  /* 0x800D1108 */
    R[3] = R[3] + R[2];  /* 0x800D110C */
    sw_(R[29] + 24, R[3]);  /* 0x800D1110 */
    R[2] = lw_(R[16] + 28);  /* 0x800D1114 */
    sw_(R[29] + 28, R[2]);  /* 0x800D111C */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 584);  /* 0x800D1120 */
    { R[31] = 0x800D112Cu; psx_next = 0x80035A48u; return; }  /* 0x800D1124 jal */
    R[4] = R[0] + 19;  /* 0x800D112C */
    R[5] = R[17] + R[0];  /* 0x800D1130 */
    R[6] = R[29] + 24;  /* 0x800D1134 */
    R[3] = R[2] << 2;  /* 0x800D1138 */
    R[3] = R[3] + R[2];  /* 0x800D113C */
    R[2] = R[3] << 4;  /* 0x800D1140 */
    R[2] = R[2] - R[3];  /* 0x800D1144 */
    R[3] = lw_(R[17] + 32);  /* 0x800D1148 */
    R[2] = R[2] << 2;  /* 0x800D114C */
    R[3] = R[3] + R[2];  /* 0x800D1150 */
    { R[31] = 0x800D115Cu; sw_(R[29] + 32, R[3]); psx_next = 0x800AC93Cu; return; }  /* 0x800D1154 jal */
    R[2] = R[18] + R[0];  /* 0x800D115C */
    R[3] = lw_(R[17] + 16);  /* 0x800D1160 */
    R[4] = R[0] - 897;  /* 0x800D1164 */
    R[3] = R[3] & R[4];  /* 0x800D1168 */
    R[3] = R[3] | 0x280;  /* 0x800D116C */
    sw_(R[17] + 16, R[3]);  /* 0x800D1170 */
    R[31] = lw_(R[29] + 52);  /* 0x800D1174 */
    R[18] = lw_(R[29] + 48);  /* 0x800D1178 */
    R[17] = lw_(R[29] + 44);  /* 0x800D117C */
    R[16] = lw_(R[29] + 40);  /* 0x800D1180 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800D1184 jr ra */
}

void g0_800D10BC(void) {
    R[3] = lw_(R[16] + 592);  /* 0x800D10BC */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800D10C4 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 584);  /* 0x800D10C8 */
    R[8] = LO;  /* 0x800D10CC */
    { R[31] = 0x800D10D8u; sw_(R[16] + 36, R[8]); psx_next = 0x80035A48u; return; }  /* 0x800D10D0 jal */
    R[3] = lw_(R[16] + 592);  /* 0x800D10D8 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800D10E0 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 584);  /* 0x800D10E4 */
    R[8] = LO;  /* 0x800D10E8 */
    { R[31] = 0x800D10F4u; sw_(R[16] + 44, R[8]); psx_next = 0x80035B18u; return; }  /* 0x800D10EC jal */
    R[3] = R[2] << 2;  /* 0x800D10F4 */
    R[3] = R[3] + R[2];  /* 0x800D10F8 */
    R[2] = R[3] << 4;  /* 0x800D10FC */
    R[2] = R[2] - R[3];  /* 0x800D1100 */
    R[3] = lw_(R[17] + 24);  /* 0x800D1104 */
    R[2] = R[2] << 2;  /* 0x800D1108 */
    R[3] = R[3] + R[2];  /* 0x800D110C */
    sw_(R[29] + 24, R[3]);  /* 0x800D1110 */
    R[2] = lw_(R[16] + 28);  /* 0x800D1114 */
    sw_(R[29] + 28, R[2]);  /* 0x800D111C */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 584);  /* 0x800D1120 */
    { R[31] = 0x800D112Cu; psx_next = 0x80035A48u; return; }  /* 0x800D1124 jal */
    R[4] = R[0] + 19;  /* 0x800D112C */
    R[5] = R[17] + R[0];  /* 0x800D1130 */
    R[6] = R[29] + 24;  /* 0x800D1134 */
    R[3] = R[2] << 2;  /* 0x800D1138 */
    R[3] = R[3] + R[2];  /* 0x800D113C */
    R[2] = R[3] << 4;  /* 0x800D1140 */
    R[2] = R[2] - R[3];  /* 0x800D1144 */
    R[3] = lw_(R[17] + 32);  /* 0x800D1148 */
    R[2] = R[2] << 2;  /* 0x800D114C */
    R[3] = R[3] + R[2];  /* 0x800D1150 */
    { R[31] = 0x800D115Cu; sw_(R[29] + 32, R[3]); psx_next = 0x800AC93Cu; return; }  /* 0x800D1154 jal */
    R[2] = R[18] + R[0];  /* 0x800D115C */
    R[3] = lw_(R[17] + 16);  /* 0x800D1160 */
    R[4] = R[0] - 897;  /* 0x800D1164 */
    R[3] = R[3] & R[4];  /* 0x800D1168 */
    R[3] = R[3] | 0x280;  /* 0x800D116C */
    sw_(R[17] + 16, R[3]);  /* 0x800D1170 */
    R[31] = lw_(R[29] + 52);  /* 0x800D1174 */
    R[18] = lw_(R[29] + 48);  /* 0x800D1178 */
    R[17] = lw_(R[29] + 44);  /* 0x800D117C */
    R[16] = lw_(R[29] + 40);  /* 0x800D1180 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800D1184 jr ra */
}

void g0_800D10D8(void) {
    R[3] = lw_(R[16] + 592);  /* 0x800D10D8 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800D10E0 */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 584);  /* 0x800D10E4 */
    R[8] = LO;  /* 0x800D10E8 */
    { R[31] = 0x800D10F4u; sw_(R[16] + 44, R[8]); psx_next = 0x80035B18u; return; }  /* 0x800D10EC jal */
    R[3] = R[2] << 2;  /* 0x800D10F4 */
    R[3] = R[3] + R[2];  /* 0x800D10F8 */
    R[2] = R[3] << 4;  /* 0x800D10FC */
    R[2] = R[2] - R[3];  /* 0x800D1100 */
    R[3] = lw_(R[17] + 24);  /* 0x800D1104 */
    R[2] = R[2] << 2;  /* 0x800D1108 */
    R[3] = R[3] + R[2];  /* 0x800D110C */
    sw_(R[29] + 24, R[3]);  /* 0x800D1110 */
    R[2] = lw_(R[16] + 28);  /* 0x800D1114 */
    sw_(R[29] + 28, R[2]);  /* 0x800D111C */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 584);  /* 0x800D1120 */
    { R[31] = 0x800D112Cu; psx_next = 0x80035A48u; return; }  /* 0x800D1124 jal */
    R[4] = R[0] + 19;  /* 0x800D112C */
    R[5] = R[17] + R[0];  /* 0x800D1130 */
    R[6] = R[29] + 24;  /* 0x800D1134 */
    R[3] = R[2] << 2;  /* 0x800D1138 */
    R[3] = R[3] + R[2];  /* 0x800D113C */
    R[2] = R[3] << 4;  /* 0x800D1140 */
    R[2] = R[2] - R[3];  /* 0x800D1144 */
    R[3] = lw_(R[17] + 32);  /* 0x800D1148 */
    R[2] = R[2] << 2;  /* 0x800D114C */
    R[3] = R[3] + R[2];  /* 0x800D1150 */
    { R[31] = 0x800D115Cu; sw_(R[29] + 32, R[3]); psx_next = 0x800AC93Cu; return; }  /* 0x800D1154 jal */
    R[2] = R[18] + R[0];  /* 0x800D115C */
    R[3] = lw_(R[17] + 16);  /* 0x800D1160 */
    R[4] = R[0] - 897;  /* 0x800D1164 */
    R[3] = R[3] & R[4];  /* 0x800D1168 */
    R[3] = R[3] | 0x280;  /* 0x800D116C */
    sw_(R[17] + 16, R[3]);  /* 0x800D1170 */
    R[31] = lw_(R[29] + 52);  /* 0x800D1174 */
    R[18] = lw_(R[29] + 48);  /* 0x800D1178 */
    R[17] = lw_(R[29] + 44);  /* 0x800D117C */
    R[16] = lw_(R[29] + 40);  /* 0x800D1180 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800D1184 jr ra */
}

void g0_800D10F4(void) {
    R[3] = R[2] << 2;  /* 0x800D10F4 */
    R[3] = R[3] + R[2];  /* 0x800D10F8 */
    R[2] = R[3] << 4;  /* 0x800D10FC */
    R[2] = R[2] - R[3];  /* 0x800D1100 */
    R[3] = lw_(R[17] + 24);  /* 0x800D1104 */
    R[2] = R[2] << 2;  /* 0x800D1108 */
    R[3] = R[3] + R[2];  /* 0x800D110C */
    sw_(R[29] + 24, R[3]);  /* 0x800D1110 */
    R[2] = lw_(R[16] + 28);  /* 0x800D1114 */
    sw_(R[29] + 28, R[2]);  /* 0x800D111C */
    R[4] = (uint32_t)(int16_t)lh_(R[16] + 584);  /* 0x800D1120 */
    { R[31] = 0x800D112Cu; psx_next = 0x80035A48u; return; }  /* 0x800D1124 jal */
    R[4] = R[0] + 19;  /* 0x800D112C */
    R[5] = R[17] + R[0];  /* 0x800D1130 */
    R[6] = R[29] + 24;  /* 0x800D1134 */
    R[3] = R[2] << 2;  /* 0x800D1138 */
    R[3] = R[3] + R[2];  /* 0x800D113C */
    R[2] = R[3] << 4;  /* 0x800D1140 */
    R[2] = R[2] - R[3];  /* 0x800D1144 */
    R[3] = lw_(R[17] + 32);  /* 0x800D1148 */
    R[2] = R[2] << 2;  /* 0x800D114C */
    R[3] = R[3] + R[2];  /* 0x800D1150 */
    { R[31] = 0x800D115Cu; sw_(R[29] + 32, R[3]); psx_next = 0x800AC93Cu; return; }  /* 0x800D1154 jal */
    R[2] = R[18] + R[0];  /* 0x800D115C */
    R[3] = lw_(R[17] + 16);  /* 0x800D1160 */
    R[4] = R[0] - 897;  /* 0x800D1164 */
    R[3] = R[3] & R[4];  /* 0x800D1168 */
    R[3] = R[3] | 0x280;  /* 0x800D116C */
    sw_(R[17] + 16, R[3]);  /* 0x800D1170 */
    R[31] = lw_(R[29] + 52);  /* 0x800D1174 */
    R[18] = lw_(R[29] + 48);  /* 0x800D1178 */
    R[17] = lw_(R[29] + 44);  /* 0x800D117C */
    R[16] = lw_(R[29] + 40);  /* 0x800D1180 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800D1184 jr ra */
}

void g0_800D112C(void) {
    R[4] = R[0] + 19;  /* 0x800D112C */
    R[5] = R[17] + R[0];  /* 0x800D1130 */
    R[6] = R[29] + 24;  /* 0x800D1134 */
    R[3] = R[2] << 2;  /* 0x800D1138 */
    R[3] = R[3] + R[2];  /* 0x800D113C */
    R[2] = R[3] << 4;  /* 0x800D1140 */
    R[2] = R[2] - R[3];  /* 0x800D1144 */
    R[3] = lw_(R[17] + 32);  /* 0x800D1148 */
    R[2] = R[2] << 2;  /* 0x800D114C */
    R[3] = R[3] + R[2];  /* 0x800D1150 */
    { R[31] = 0x800D115Cu; sw_(R[29] + 32, R[3]); psx_next = 0x800AC93Cu; return; }  /* 0x800D1154 jal */
    R[2] = R[18] + R[0];  /* 0x800D115C */
    R[3] = lw_(R[17] + 16);  /* 0x800D1160 */
    R[4] = R[0] - 897;  /* 0x800D1164 */
    R[3] = R[3] & R[4];  /* 0x800D1168 */
    R[3] = R[3] | 0x280;  /* 0x800D116C */
    sw_(R[17] + 16, R[3]);  /* 0x800D1170 */
    R[31] = lw_(R[29] + 52);  /* 0x800D1174 */
    R[18] = lw_(R[29] + 48);  /* 0x800D1178 */
    R[17] = lw_(R[29] + 44);  /* 0x800D117C */
    R[16] = lw_(R[29] + 40);  /* 0x800D1180 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800D1184 jr ra */
}

void g0_800D115C(void) {
    R[2] = R[18] + R[0];  /* 0x800D115C */
    R[3] = lw_(R[17] + 16);  /* 0x800D1160 */
    R[4] = R[0] - 897;  /* 0x800D1164 */
    R[3] = R[3] & R[4];  /* 0x800D1168 */
    R[3] = R[3] | 0x280;  /* 0x800D116C */
    sw_(R[17] + 16, R[3]);  /* 0x800D1170 */
    R[31] = lw_(R[29] + 52);  /* 0x800D1174 */
    R[18] = lw_(R[29] + 48);  /* 0x800D1178 */
    R[17] = lw_(R[29] + 44);  /* 0x800D117C */
    R[16] = lw_(R[29] + 40);  /* 0x800D1180 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800D1184 jr ra */
}

void g0_800D1174(void) {
    R[31] = lw_(R[29] + 52);  /* 0x800D1174 */
    R[18] = lw_(R[29] + 48);  /* 0x800D1178 */
    R[17] = lw_(R[29] + 44);  /* 0x800D117C */
    R[16] = lw_(R[29] + 40);  /* 0x800D1180 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800D1184 jr ra */
}

void g0_800D118C(void) {
    R[29] = R[29] - 40;  /* 0x800D118C */
    R[7] = 0x6u << 16;  /* 0x800D1190 */
    R[7] = R[7] | 0x4000;  /* 0x800D1194 */
    R[2] = 0x8012u << 16;  /* 0x800D1198 */
    sw_(R[29] + 28, R[17]);  /* 0x800D119C */
    R[17] = R[2] - 26864;  /* 0x800D11A0 */
    R[3] = 0x800Fu << 16;  /* 0x800D11A4 */
    R[3] = R[3] + 180;  /* 0x800D11A8 */
    R[2] = 0x8013u << 16;  /* 0x800D11AC */
    sw_(R[29] + 32, R[31]);  /* 0x800D11B0 */
    sw_(R[29] + 24, R[16]);  /* 0x800D11B4 */
    R[4] = lw_(R[17] + 24);  /* 0x800D11B8 */
    R[2] = R[2] - 29480;  /* 0x800D11BC */
    sw_(R[29] + 16, R[3]);  /* 0x800D11C0 */
    R[6] = lw_(R[2] + 48);  /* 0x800D11C4 */
    R[5] = lw_(R[17] + 28);  /* 0x800D11C8 */
    R[2] = lw_(R[2] + 52);  /* 0x800D11CC */
    R[5] = R[5] + R[7];  /* 0x800D11D0 */
    sw_(R[3] + 28, R[6]);  /* 0x800D11D4 */
    sw_(R[3] + 32, R[2]);  /* 0x800D11D8 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D11DC */
    R[6] = lw_(R[17] + 32);  /* 0x800D11E0 */
    { R[31] = 0x800D11ECu; psx_next = 0x800889DCu; return; }  /* 0x800D11E4 jal */
    { uint32_t _c = ((int32_t)R[2] < 0); R[16] = R[2] << 1; if (_c) { goto L_800D1250; } }  /* 0x800D11EC */
    R[16] = R[16] + R[2];  /* 0x800D11F4 */
    R[16] = R[16] << 3;  /* 0x800D11F8 */
    R[16] = R[16] + R[2];  /* 0x800D11FC */
    R[16] = R[16] << 3;  /* 0x800D1200 */
    R[16] = R[16] + R[2];  /* 0x800D1204 */
    R[16] = R[16] << 2;  /* 0x800D1208 */
    R[16] = R[16] + R[17];  /* 0x800D120C */
    R[4] = R[16] + R[0];  /* 0x800D1210 */
    { R[31] = 0x800D121Cu; R[5] = R[0] + 7; psx_next = 0x800A9E2Cu; return; }  /* 0x800D1214 jal */
    R[2] = R[0] + R[0];  /* 0x800D121C */
    R[3] = R[0] + 2;  /* 0x800D1220 */
    R[5] = lh_(R[17] + 4);  /* 0x800D1224 */
    R[4] = 0x8014u << 16;  /* 0x800D1228 */
    sb_(R[16] + 580, R[3]);  /* 0x800D122C */
    R[3] = R[0] + 1;  /* 0x800D1230 */
    sb_(R[16] + 585, R[0]);  /* 0x800D1234 */
    sb_(R[16] + 581, R[0]);  /* 0x800D1238 */
    sh_(R[16] + 604, R[0]);  /* 0x800D123C */
    sw_(R[4] + 15016, R[3]);  /* 0x800D1240 */
    sh_(R[16] + 4, R[5]);  /* 0x800D1244 */
    { sh_(R[16] + 6, R[5]); goto L_800D1254; }  /* 0x800D1248 j */
L_800D1250:;
    R[2] = R[0] - 1;  /* 0x800D1250 */
L_800D1254:;
    R[31] = lw_(R[29] + 32);  /* 0x800D1254 */
    R[17] = lw_(R[29] + 28);  /* 0x800D1258 */
    R[16] = lw_(R[29] + 24);  /* 0x800D125C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D1260 jr ra */
}

void g0_800D11EC(void) {
    { uint32_t _c = ((int32_t)R[2] < 0); R[16] = R[2] << 1; if (_c) { goto L_800D1250; } }  /* 0x800D11EC */
    R[16] = R[16] + R[2];  /* 0x800D11F4 */
    R[16] = R[16] << 3;  /* 0x800D11F8 */
    R[16] = R[16] + R[2];  /* 0x800D11FC */
    R[16] = R[16] << 3;  /* 0x800D1200 */
    R[16] = R[16] + R[2];  /* 0x800D1204 */
    R[16] = R[16] << 2;  /* 0x800D1208 */
    R[16] = R[16] + R[17];  /* 0x800D120C */
    R[4] = R[16] + R[0];  /* 0x800D1210 */
    { R[31] = 0x800D121Cu; R[5] = R[0] + 7; psx_next = 0x800A9E2Cu; return; }  /* 0x800D1214 jal */
    R[2] = R[0] + R[0];  /* 0x800D121C */
    R[3] = R[0] + 2;  /* 0x800D1220 */
    R[5] = lh_(R[17] + 4);  /* 0x800D1224 */
    R[4] = 0x8014u << 16;  /* 0x800D1228 */
    sb_(R[16] + 580, R[3]);  /* 0x800D122C */
    R[3] = R[0] + 1;  /* 0x800D1230 */
    sb_(R[16] + 585, R[0]);  /* 0x800D1234 */
    sb_(R[16] + 581, R[0]);  /* 0x800D1238 */
    sh_(R[16] + 604, R[0]);  /* 0x800D123C */
    sw_(R[4] + 15016, R[3]);  /* 0x800D1240 */
    sh_(R[16] + 4, R[5]);  /* 0x800D1244 */
    { sh_(R[16] + 6, R[5]); goto L_800D1254; }  /* 0x800D1248 j */
L_800D1250:;
    R[2] = R[0] - 1;  /* 0x800D1250 */
L_800D1254:;
    R[31] = lw_(R[29] + 32);  /* 0x800D1254 */
    R[17] = lw_(R[29] + 28);  /* 0x800D1258 */
    R[16] = lw_(R[29] + 24);  /* 0x800D125C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D1260 jr ra */
}

void g0_800D121C(void) {
    R[2] = R[0] + R[0];  /* 0x800D121C */
    R[3] = R[0] + 2;  /* 0x800D1220 */
    R[5] = lh_(R[17] + 4);  /* 0x800D1224 */
    R[4] = 0x8014u << 16;  /* 0x800D1228 */
    sb_(R[16] + 580, R[3]);  /* 0x800D122C */
    R[3] = R[0] + 1;  /* 0x800D1230 */
    sb_(R[16] + 585, R[0]);  /* 0x800D1234 */
    sb_(R[16] + 581, R[0]);  /* 0x800D1238 */
    sh_(R[16] + 604, R[0]);  /* 0x800D123C */
    sw_(R[4] + 15016, R[3]);  /* 0x800D1240 */
    sh_(R[16] + 4, R[5]);  /* 0x800D1244 */
    { sh_(R[16] + 6, R[5]); goto L_800D1254; }  /* 0x800D1248 j */
    R[2] = R[0] - 1;  /* 0x800D1250 */
L_800D1254:;
    R[31] = lw_(R[29] + 32);  /* 0x800D1254 */
    R[17] = lw_(R[29] + 28);  /* 0x800D1258 */
    R[16] = lw_(R[29] + 24);  /* 0x800D125C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D1260 jr ra */
}

void g0_800D1268(void) {
    R[29] = R[29] - 48;  /* 0x800D1268 */
    sw_(R[29] + 32, R[18]);  /* 0x800D126C */
    R[18] = R[0] + R[0];  /* 0x800D1270 */
    R[2] = 0x800Fu << 16;  /* 0x800D1274 */
    R[2] = R[2] + 224;  /* 0x800D1278 */
    sw_(R[29] + 36, R[19]);  /* 0x800D127C */
    R[19] = R[2] + R[0];  /* 0x800D1280 */
    R[2] = 0x8013u << 16;  /* 0x800D1284 */
    R[2] = R[2] - 29480;  /* 0x800D1288 */
    R[3] = 0x8012u << 16;  /* 0x800D128C */
    sw_(R[29] + 28, R[17]);  /* 0x800D1290 */
    R[17] = R[3] - 26864;  /* 0x800D1294 */
    sw_(R[29] + 44, R[31]);  /* 0x800D1298 */
    sw_(R[29] + 40, R[20]);  /* 0x800D129C */
    sw_(R[29] + 24, R[16]);  /* 0x800D12A0 */
    R[3] = lw_(R[2] + 48);  /* 0x800D12A4 */
    R[2] = lw_(R[2] + 52);  /* 0x800D12A8 */
    R[20] = R[17] + R[0];  /* 0x800D12AC */
    sw_(R[19] + 28, R[3]);  /* 0x800D12B0 */
    sw_(R[19] + 32, R[2]);  /* 0x800D12B4 */
L_800D12B8:;
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_800D12E8; } }  /* 0x800D12B8 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D12C0 */
    { R[31] = 0x800D12CCu; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D12C4 jal */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D12CC */
    R[16] = R[2] << 5;  /* 0x800D12D0 */
    { R[31] = 0x800D12DCu; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D12D4 jal */
    R[2] = R[2] << 5;  /* 0x800D12DC */
    { R[3] = R[0] - R[2]; goto L_800D130C; }  /* 0x800D12E0 j */
L_800D12E8:;
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D12E8 */
    { R[31] = 0x800D12F4u; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D12EC jal */
    R[2] = R[2] << 5;  /* 0x800D12F4 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D12F8 */
    R[16] = R[0] - R[2];  /* 0x800D12FC */
    { R[31] = 0x800D1308u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D1300 jal */
    R[3] = R[2] << 5;  /* 0x800D1308 */
L_800D130C:;
    R[2] = 0x6u << 16;  /* 0x800D130C */
    R[2] = R[2] | 0x4000;  /* 0x800D1310 */
    sw_(R[29] + 16, R[19]);  /* 0x800D1314 */
    R[4] = lw_(R[17] + 24);  /* 0x800D1318 */
    R[5] = lw_(R[17] + 28);  /* 0x800D131C */
    R[6] = lw_(R[17] + 32);  /* 0x800D1320 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D1324 */
    R[4] = R[4] + R[16];  /* 0x800D1328 */
    R[5] = R[5] + R[2];  /* 0x800D132C */
    { R[31] = 0x800D1338u; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D1330 jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[16] = R[2] << 1; if (_c) { goto L_800D1348; } }  /* 0x800D1338 */
    { R[2] = R[0] - 1; goto L_800D13B0; }  /* 0x800D1340 j */
L_800D1348:;
    R[16] = R[16] + R[2];  /* 0x800D1348 */
    R[16] = R[16] << 3;  /* 0x800D134C */
    R[16] = R[16] + R[2];  /* 0x800D1350 */
    R[16] = R[16] << 3;  /* 0x800D1354 */
    R[16] = R[16] + R[2];  /* 0x800D1358 */
    R[16] = R[16] << 2;  /* 0x800D135C */
    R[16] = R[16] + R[20];  /* 0x800D1360 */
    R[4] = R[16] + R[0];  /* 0x800D1364 */
    { R[31] = 0x800D1370u; R[5] = R[0] + 7; psx_next = 0x800A9E2Cu; return; }  /* 0x800D1368 jal */
    R[3] = lh_(R[17] + 4);  /* 0x800D1370 */
    sb_(R[16] + 585, R[18]);  /* 0x800D1374 */
    R[18] = R[18] + 1;  /* 0x800D1378 */
    R[2] = R[0] + 2;  /* 0x800D137C */
    sb_(R[16] + 580, R[2]);  /* 0x800D1380 */
    R[2] = R[0] + 1;  /* 0x800D1384 */
    sb_(R[16] + 581, R[2]);  /* 0x800D1388 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D138C */
    sh_(R[16] + 604, R[0]);  /* 0x800D1390 */
    sh_(R[16] + 4, R[3]);  /* 0x800D1394 */
    { uint32_t _c = (R[2] != R[0]); sh_(R[16] + 6, R[3]); if (_c) { psx_bb(); goto L_800D12B8; } }  /* 0x800D1398 */
    R[3] = 0x8014u << 16;  /* 0x800D13A0 */
    R[2] = R[0] + 2;  /* 0x800D13A4 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D13A8 */
    R[2] = R[0] + R[0];  /* 0x800D13AC */
L_800D13B0:;
    R[31] = lw_(R[29] + 44);  /* 0x800D13B0 */
    R[20] = lw_(R[29] + 40);  /* 0x800D13B4 */
    R[19] = lw_(R[29] + 36);  /* 0x800D13B8 */
    R[18] = lw_(R[29] + 32);  /* 0x800D13BC */
    R[17] = lw_(R[29] + 28);  /* 0x800D13C0 */
    R[16] = lw_(R[29] + 24);  /* 0x800D13C4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D13C8 jr ra */
}

void g0_800D12B8(void) {
L_800D12B8:;
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_800D12E8; } }  /* 0x800D12B8 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D12C0 */
    { R[31] = 0x800D12CCu; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D12C4 jal */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D12CC */
    R[16] = R[2] << 5;  /* 0x800D12D0 */
    { R[31] = 0x800D12DCu; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D12D4 jal */
    R[2] = R[2] << 5;  /* 0x800D12DC */
    { R[3] = R[0] - R[2]; goto L_800D130C; }  /* 0x800D12E0 j */
L_800D12E8:;
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D12E8 */
    { R[31] = 0x800D12F4u; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D12EC jal */
    R[2] = R[2] << 5;  /* 0x800D12F4 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D12F8 */
    R[16] = R[0] - R[2];  /* 0x800D12FC */
    { R[31] = 0x800D1308u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D1300 jal */
    R[3] = R[2] << 5;  /* 0x800D1308 */
L_800D130C:;
    R[2] = 0x6u << 16;  /* 0x800D130C */
    R[2] = R[2] | 0x4000;  /* 0x800D1310 */
    sw_(R[29] + 16, R[19]);  /* 0x800D1314 */
    R[4] = lw_(R[17] + 24);  /* 0x800D1318 */
    R[5] = lw_(R[17] + 28);  /* 0x800D131C */
    R[6] = lw_(R[17] + 32);  /* 0x800D1320 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D1324 */
    R[4] = R[4] + R[16];  /* 0x800D1328 */
    R[5] = R[5] + R[2];  /* 0x800D132C */
    { R[31] = 0x800D1338u; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D1330 jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[16] = R[2] << 1; if (_c) { goto L_800D1348; } }  /* 0x800D1338 */
    { R[2] = R[0] - 1; goto L_800D13B0; }  /* 0x800D1340 j */
L_800D1348:;
    R[16] = R[16] + R[2];  /* 0x800D1348 */
    R[16] = R[16] << 3;  /* 0x800D134C */
    R[16] = R[16] + R[2];  /* 0x800D1350 */
    R[16] = R[16] << 3;  /* 0x800D1354 */
    R[16] = R[16] + R[2];  /* 0x800D1358 */
    R[16] = R[16] << 2;  /* 0x800D135C */
    R[16] = R[16] + R[20];  /* 0x800D1360 */
    R[4] = R[16] + R[0];  /* 0x800D1364 */
    { R[31] = 0x800D1370u; R[5] = R[0] + 7; psx_next = 0x800A9E2Cu; return; }  /* 0x800D1368 jal */
    R[3] = lh_(R[17] + 4);  /* 0x800D1370 */
    sb_(R[16] + 585, R[18]);  /* 0x800D1374 */
    R[18] = R[18] + 1;  /* 0x800D1378 */
    R[2] = R[0] + 2;  /* 0x800D137C */
    sb_(R[16] + 580, R[2]);  /* 0x800D1380 */
    R[2] = R[0] + 1;  /* 0x800D1384 */
    sb_(R[16] + 581, R[2]);  /* 0x800D1388 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D138C */
    sh_(R[16] + 604, R[0]);  /* 0x800D1390 */
    sh_(R[16] + 4, R[3]);  /* 0x800D1394 */
    { uint32_t _c = (R[2] != R[0]); sh_(R[16] + 6, R[3]); if (_c) { psx_bb(); goto L_800D12B8; } }  /* 0x800D1398 */
    R[3] = 0x8014u << 16;  /* 0x800D13A0 */
    R[2] = R[0] + 2;  /* 0x800D13A4 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D13A8 */
    R[2] = R[0] + R[0];  /* 0x800D13AC */
L_800D13B0:;
    R[31] = lw_(R[29] + 44);  /* 0x800D13B0 */
    R[20] = lw_(R[29] + 40);  /* 0x800D13B4 */
    R[19] = lw_(R[29] + 36);  /* 0x800D13B8 */
    R[18] = lw_(R[29] + 32);  /* 0x800D13BC */
    R[17] = lw_(R[29] + 28);  /* 0x800D13C0 */
    R[16] = lw_(R[29] + 24);  /* 0x800D13C4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D13C8 jr ra */
}

void g0_800D12CC(void) {
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D12CC */
    R[16] = R[2] << 5;  /* 0x800D12D0 */
    { R[31] = 0x800D12DCu; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D12D4 jal */
    R[2] = R[2] << 5;  /* 0x800D12DC */
    { R[3] = R[0] - R[2]; goto L_800D130C; }  /* 0x800D12E0 j */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D12E8 */
    { R[31] = 0x800D12F4u; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D12EC jal */
    R[2] = R[2] << 5;  /* 0x800D12F4 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D12F8 */
    R[16] = R[0] - R[2];  /* 0x800D12FC */
    { R[31] = 0x800D1308u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D1300 jal */
    R[3] = R[2] << 5;  /* 0x800D1308 */
L_800D130C:;
    R[2] = 0x6u << 16;  /* 0x800D130C */
    R[2] = R[2] | 0x4000;  /* 0x800D1310 */
    sw_(R[29] + 16, R[19]);  /* 0x800D1314 */
    R[4] = lw_(R[17] + 24);  /* 0x800D1318 */
    R[5] = lw_(R[17] + 28);  /* 0x800D131C */
    R[6] = lw_(R[17] + 32);  /* 0x800D1320 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D1324 */
    R[4] = R[4] + R[16];  /* 0x800D1328 */
    R[5] = R[5] + R[2];  /* 0x800D132C */
    { R[31] = 0x800D1338u; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D1330 jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[16] = R[2] << 1; if (_c) { goto L_800D1348; } }  /* 0x800D1338 */
    { R[2] = R[0] - 1; goto L_800D13B0; }  /* 0x800D1340 j */
L_800D1348:;
    R[16] = R[16] + R[2];  /* 0x800D1348 */
    R[16] = R[16] << 3;  /* 0x800D134C */
    R[16] = R[16] + R[2];  /* 0x800D1350 */
    R[16] = R[16] << 3;  /* 0x800D1354 */
    R[16] = R[16] + R[2];  /* 0x800D1358 */
    R[16] = R[16] << 2;  /* 0x800D135C */
    R[16] = R[16] + R[20];  /* 0x800D1360 */
    R[4] = R[16] + R[0];  /* 0x800D1364 */
    { R[31] = 0x800D1370u; R[5] = R[0] + 7; psx_next = 0x800A9E2Cu; return; }  /* 0x800D1368 jal */
    R[3] = lh_(R[17] + 4);  /* 0x800D1370 */
    sb_(R[16] + 585, R[18]);  /* 0x800D1374 */
    R[18] = R[18] + 1;  /* 0x800D1378 */
    R[2] = R[0] + 2;  /* 0x800D137C */
    sb_(R[16] + 580, R[2]);  /* 0x800D1380 */
    R[2] = R[0] + 1;  /* 0x800D1384 */
    sb_(R[16] + 581, R[2]);  /* 0x800D1388 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D138C */
    sh_(R[16] + 604, R[0]);  /* 0x800D1390 */
    sh_(R[16] + 4, R[3]);  /* 0x800D1394 */
    { uint32_t _c = (R[2] != R[0]); sh_(R[16] + 6, R[3]); if (_c) { psx_next = 0x800D12B8u; return; } }  /* 0x800D1398 b extern */
    R[3] = 0x8014u << 16;  /* 0x800D13A0 */
    R[2] = R[0] + 2;  /* 0x800D13A4 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D13A8 */
    R[2] = R[0] + R[0];  /* 0x800D13AC */
L_800D13B0:;
    R[31] = lw_(R[29] + 44);  /* 0x800D13B0 */
    R[20] = lw_(R[29] + 40);  /* 0x800D13B4 */
    R[19] = lw_(R[29] + 36);  /* 0x800D13B8 */
    R[18] = lw_(R[29] + 32);  /* 0x800D13BC */
    R[17] = lw_(R[29] + 28);  /* 0x800D13C0 */
    R[16] = lw_(R[29] + 24);  /* 0x800D13C4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D13C8 jr ra */
}

void g0_800D12DC(void) {
    R[2] = R[2] << 5;  /* 0x800D12DC */
    { R[3] = R[0] - R[2]; goto L_800D130C; }  /* 0x800D12E0 j */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D12E8 */
    { R[31] = 0x800D12F4u; R[4] = R[4] << 3; psx_next = 0x80035A48u; return; }  /* 0x800D12EC jal */
    R[2] = R[2] << 5;  /* 0x800D12F4 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D12F8 */
    R[16] = R[0] - R[2];  /* 0x800D12FC */
    { R[31] = 0x800D1308u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D1300 jal */
    R[3] = R[2] << 5;  /* 0x800D1308 */
L_800D130C:;
    R[2] = 0x6u << 16;  /* 0x800D130C */
    R[2] = R[2] | 0x4000;  /* 0x800D1310 */
    sw_(R[29] + 16, R[19]);  /* 0x800D1314 */
    R[4] = lw_(R[17] + 24);  /* 0x800D1318 */
    R[5] = lw_(R[17] + 28);  /* 0x800D131C */
    R[6] = lw_(R[17] + 32);  /* 0x800D1320 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D1324 */
    R[4] = R[4] + R[16];  /* 0x800D1328 */
    R[5] = R[5] + R[2];  /* 0x800D132C */
    { R[31] = 0x800D1338u; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D1330 jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[16] = R[2] << 1; if (_c) { goto L_800D1348; } }  /* 0x800D1338 */
    { R[2] = R[0] - 1; goto L_800D13B0; }  /* 0x800D1340 j */
L_800D1348:;
    R[16] = R[16] + R[2];  /* 0x800D1348 */
    R[16] = R[16] << 3;  /* 0x800D134C */
    R[16] = R[16] + R[2];  /* 0x800D1350 */
    R[16] = R[16] << 3;  /* 0x800D1354 */
    R[16] = R[16] + R[2];  /* 0x800D1358 */
    R[16] = R[16] << 2;  /* 0x800D135C */
    R[16] = R[16] + R[20];  /* 0x800D1360 */
    R[4] = R[16] + R[0];  /* 0x800D1364 */
    { R[31] = 0x800D1370u; R[5] = R[0] + 7; psx_next = 0x800A9E2Cu; return; }  /* 0x800D1368 jal */
    R[3] = lh_(R[17] + 4);  /* 0x800D1370 */
    sb_(R[16] + 585, R[18]);  /* 0x800D1374 */
    R[18] = R[18] + 1;  /* 0x800D1378 */
    R[2] = R[0] + 2;  /* 0x800D137C */
    sb_(R[16] + 580, R[2]);  /* 0x800D1380 */
    R[2] = R[0] + 1;  /* 0x800D1384 */
    sb_(R[16] + 581, R[2]);  /* 0x800D1388 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D138C */
    sh_(R[16] + 604, R[0]);  /* 0x800D1390 */
    sh_(R[16] + 4, R[3]);  /* 0x800D1394 */
    { uint32_t _c = (R[2] != R[0]); sh_(R[16] + 6, R[3]); if (_c) { psx_next = 0x800D12B8u; return; } }  /* 0x800D1398 b extern */
    R[3] = 0x8014u << 16;  /* 0x800D13A0 */
    R[2] = R[0] + 2;  /* 0x800D13A4 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D13A8 */
    R[2] = R[0] + R[0];  /* 0x800D13AC */
L_800D13B0:;
    R[31] = lw_(R[29] + 44);  /* 0x800D13B0 */
    R[20] = lw_(R[29] + 40);  /* 0x800D13B4 */
    R[19] = lw_(R[29] + 36);  /* 0x800D13B8 */
    R[18] = lw_(R[29] + 32);  /* 0x800D13BC */
    R[17] = lw_(R[29] + 28);  /* 0x800D13C0 */
    R[16] = lw_(R[29] + 24);  /* 0x800D13C4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D13C8 jr ra */
}

void g0_800D12F4(void) {
    R[2] = R[2] << 5;  /* 0x800D12F4 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D12F8 */
    R[16] = R[0] - R[2];  /* 0x800D12FC */
    { R[31] = 0x800D1308u; R[4] = R[4] << 3; psx_next = 0x80035B18u; return; }  /* 0x800D1300 jal */
    R[3] = R[2] << 5;  /* 0x800D1308 */
    R[2] = 0x6u << 16;  /* 0x800D130C */
    R[2] = R[2] | 0x4000;  /* 0x800D1310 */
    sw_(R[29] + 16, R[19]);  /* 0x800D1314 */
    R[4] = lw_(R[17] + 24);  /* 0x800D1318 */
    R[5] = lw_(R[17] + 28);  /* 0x800D131C */
    R[6] = lw_(R[17] + 32);  /* 0x800D1320 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D1324 */
    R[4] = R[4] + R[16];  /* 0x800D1328 */
    R[5] = R[5] + R[2];  /* 0x800D132C */
    { R[31] = 0x800D1338u; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D1330 jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[16] = R[2] << 1; if (_c) { goto L_800D1348; } }  /* 0x800D1338 */
    { R[2] = R[0] - 1; goto L_800D13B0; }  /* 0x800D1340 j */
L_800D1348:;
    R[16] = R[16] + R[2];  /* 0x800D1348 */
    R[16] = R[16] << 3;  /* 0x800D134C */
    R[16] = R[16] + R[2];  /* 0x800D1350 */
    R[16] = R[16] << 3;  /* 0x800D1354 */
    R[16] = R[16] + R[2];  /* 0x800D1358 */
    R[16] = R[16] << 2;  /* 0x800D135C */
    R[16] = R[16] + R[20];  /* 0x800D1360 */
    R[4] = R[16] + R[0];  /* 0x800D1364 */
    { R[31] = 0x800D1370u; R[5] = R[0] + 7; psx_next = 0x800A9E2Cu; return; }  /* 0x800D1368 jal */
    R[3] = lh_(R[17] + 4);  /* 0x800D1370 */
    sb_(R[16] + 585, R[18]);  /* 0x800D1374 */
    R[18] = R[18] + 1;  /* 0x800D1378 */
    R[2] = R[0] + 2;  /* 0x800D137C */
    sb_(R[16] + 580, R[2]);  /* 0x800D1380 */
    R[2] = R[0] + 1;  /* 0x800D1384 */
    sb_(R[16] + 581, R[2]);  /* 0x800D1388 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D138C */
    sh_(R[16] + 604, R[0]);  /* 0x800D1390 */
    sh_(R[16] + 4, R[3]);  /* 0x800D1394 */
    { uint32_t _c = (R[2] != R[0]); sh_(R[16] + 6, R[3]); if (_c) { psx_next = 0x800D12B8u; return; } }  /* 0x800D1398 b extern */
    R[3] = 0x8014u << 16;  /* 0x800D13A0 */
    R[2] = R[0] + 2;  /* 0x800D13A4 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D13A8 */
    R[2] = R[0] + R[0];  /* 0x800D13AC */
L_800D13B0:;
    R[31] = lw_(R[29] + 44);  /* 0x800D13B0 */
    R[20] = lw_(R[29] + 40);  /* 0x800D13B4 */
    R[19] = lw_(R[29] + 36);  /* 0x800D13B8 */
    R[18] = lw_(R[29] + 32);  /* 0x800D13BC */
    R[17] = lw_(R[29] + 28);  /* 0x800D13C0 */
    R[16] = lw_(R[29] + 24);  /* 0x800D13C4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D13C8 jr ra */
}

void g0_800D1308(void) {
    R[3] = R[2] << 5;  /* 0x800D1308 */
    R[2] = 0x6u << 16;  /* 0x800D130C */
    R[2] = R[2] | 0x4000;  /* 0x800D1310 */
    sw_(R[29] + 16, R[19]);  /* 0x800D1314 */
    R[4] = lw_(R[17] + 24);  /* 0x800D1318 */
    R[5] = lw_(R[17] + 28);  /* 0x800D131C */
    R[6] = lw_(R[17] + 32);  /* 0x800D1320 */
    R[7] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x800D1324 */
    R[4] = R[4] + R[16];  /* 0x800D1328 */
    R[5] = R[5] + R[2];  /* 0x800D132C */
    { R[31] = 0x800D1338u; R[6] = R[6] + R[3]; psx_next = 0x800889DCu; return; }  /* 0x800D1330 jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[16] = R[2] << 1; if (_c) { goto L_800D1348; } }  /* 0x800D1338 */
    { R[2] = R[0] - 1; goto L_800D13B0; }  /* 0x800D1340 j */
L_800D1348:;
    R[16] = R[16] + R[2];  /* 0x800D1348 */
    R[16] = R[16] << 3;  /* 0x800D134C */
    R[16] = R[16] + R[2];  /* 0x800D1350 */
    R[16] = R[16] << 3;  /* 0x800D1354 */
    R[16] = R[16] + R[2];  /* 0x800D1358 */
    R[16] = R[16] << 2;  /* 0x800D135C */
    R[16] = R[16] + R[20];  /* 0x800D1360 */
    R[4] = R[16] + R[0];  /* 0x800D1364 */
    { R[31] = 0x800D1370u; R[5] = R[0] + 7; psx_next = 0x800A9E2Cu; return; }  /* 0x800D1368 jal */
    R[3] = lh_(R[17] + 4);  /* 0x800D1370 */
    sb_(R[16] + 585, R[18]);  /* 0x800D1374 */
    R[18] = R[18] + 1;  /* 0x800D1378 */
    R[2] = R[0] + 2;  /* 0x800D137C */
    sb_(R[16] + 580, R[2]);  /* 0x800D1380 */
    R[2] = R[0] + 1;  /* 0x800D1384 */
    sb_(R[16] + 581, R[2]);  /* 0x800D1388 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D138C */
    sh_(R[16] + 604, R[0]);  /* 0x800D1390 */
    sh_(R[16] + 4, R[3]);  /* 0x800D1394 */
    { uint32_t _c = (R[2] != R[0]); sh_(R[16] + 6, R[3]); if (_c) { psx_next = 0x800D12B8u; return; } }  /* 0x800D1398 b extern */
    R[3] = 0x8014u << 16;  /* 0x800D13A0 */
    R[2] = R[0] + 2;  /* 0x800D13A4 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D13A8 */
    R[2] = R[0] + R[0];  /* 0x800D13AC */
L_800D13B0:;
    R[31] = lw_(R[29] + 44);  /* 0x800D13B0 */
    R[20] = lw_(R[29] + 40);  /* 0x800D13B4 */
    R[19] = lw_(R[29] + 36);  /* 0x800D13B8 */
    R[18] = lw_(R[29] + 32);  /* 0x800D13BC */
    R[17] = lw_(R[29] + 28);  /* 0x800D13C0 */
    R[16] = lw_(R[29] + 24);  /* 0x800D13C4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D13C8 jr ra */
}

void g0_800D1338(void) {
    { uint32_t _c = ((int32_t)R[2] >= 0); R[16] = R[2] << 1; if (_c) { goto L_800D1348; } }  /* 0x800D1338 */
    { R[2] = R[0] - 1; goto L_800D13B0; }  /* 0x800D1340 j */
L_800D1348:;
    R[16] = R[16] + R[2];  /* 0x800D1348 */
    R[16] = R[16] << 3;  /* 0x800D134C */
    R[16] = R[16] + R[2];  /* 0x800D1350 */
    R[16] = R[16] << 3;  /* 0x800D1354 */
    R[16] = R[16] + R[2];  /* 0x800D1358 */
    R[16] = R[16] << 2;  /* 0x800D135C */
    R[16] = R[16] + R[20];  /* 0x800D1360 */
    R[4] = R[16] + R[0];  /* 0x800D1364 */
    { R[31] = 0x800D1370u; R[5] = R[0] + 7; psx_next = 0x800A9E2Cu; return; }  /* 0x800D1368 jal */
    R[3] = lh_(R[17] + 4);  /* 0x800D1370 */
    sb_(R[16] + 585, R[18]);  /* 0x800D1374 */
    R[18] = R[18] + 1;  /* 0x800D1378 */
    R[2] = R[0] + 2;  /* 0x800D137C */
    sb_(R[16] + 580, R[2]);  /* 0x800D1380 */
    R[2] = R[0] + 1;  /* 0x800D1384 */
    sb_(R[16] + 581, R[2]);  /* 0x800D1388 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D138C */
    sh_(R[16] + 604, R[0]);  /* 0x800D1390 */
    sh_(R[16] + 4, R[3]);  /* 0x800D1394 */
    { uint32_t _c = (R[2] != R[0]); sh_(R[16] + 6, R[3]); if (_c) { psx_next = 0x800D12B8u; return; } }  /* 0x800D1398 b extern */
    R[3] = 0x8014u << 16;  /* 0x800D13A0 */
    R[2] = R[0] + 2;  /* 0x800D13A4 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D13A8 */
    R[2] = R[0] + R[0];  /* 0x800D13AC */
L_800D13B0:;
    R[31] = lw_(R[29] + 44);  /* 0x800D13B0 */
    R[20] = lw_(R[29] + 40);  /* 0x800D13B4 */
    R[19] = lw_(R[29] + 36);  /* 0x800D13B8 */
    R[18] = lw_(R[29] + 32);  /* 0x800D13BC */
    R[17] = lw_(R[29] + 28);  /* 0x800D13C0 */
    R[16] = lw_(R[29] + 24);  /* 0x800D13C4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D13C8 jr ra */
}

void g0_800D1370(void) {
    R[3] = lh_(R[17] + 4);  /* 0x800D1370 */
    sb_(R[16] + 585, R[18]);  /* 0x800D1374 */
    R[18] = R[18] + 1;  /* 0x800D1378 */
    R[2] = R[0] + 2;  /* 0x800D137C */
    sb_(R[16] + 580, R[2]);  /* 0x800D1380 */
    R[2] = R[0] + 1;  /* 0x800D1384 */
    sb_(R[16] + 581, R[2]);  /* 0x800D1388 */
    R[2] = ((int32_t)R[18] < 2);  /* 0x800D138C */
    sh_(R[16] + 604, R[0]);  /* 0x800D1390 */
    sh_(R[16] + 4, R[3]);  /* 0x800D1394 */
    { uint32_t _c = (R[2] != R[0]); sh_(R[16] + 6, R[3]); if (_c) { psx_next = 0x800D12B8u; return; } }  /* 0x800D1398 b extern */
    R[3] = 0x8014u << 16;  /* 0x800D13A0 */
    R[2] = R[0] + 2;  /* 0x800D13A4 */
    sw_(R[3] + 15016, R[2]);  /* 0x800D13A8 */
    R[2] = R[0] + R[0];  /* 0x800D13AC */
    R[31] = lw_(R[29] + 44);  /* 0x800D13B0 */
    R[20] = lw_(R[29] + 40);  /* 0x800D13B4 */
    R[19] = lw_(R[29] + 36);  /* 0x800D13B8 */
    R[18] = lw_(R[29] + 32);  /* 0x800D13BC */
    R[17] = lw_(R[29] + 28);  /* 0x800D13C0 */
    R[16] = lw_(R[29] + 24);  /* 0x800D13C4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D13C8 jr ra */
}

void g0_800D13D0(void) {
    R[29] = R[29] - 48;  /* 0x800D13D0 */
    sw_(R[29] + 32, R[16]);  /* 0x800D13D4 */
    R[16] = R[4] + R[0];  /* 0x800D13D8 */
    R[2] = R[0] + 2;  /* 0x800D13DC */
    sw_(R[29] + 40, R[31]);  /* 0x800D13E0 */
    { uint32_t _c = (R[5] == R[2]); sw_(R[29] + 36, R[17]); if (_c) { goto L_800D14C8; } }  /* 0x800D13E4 */
    R[2] = ((int32_t)R[5] < 3);  /* 0x800D13EC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 5; if (_c) { goto L_800D1408; } }  /* 0x800D13F0 */
    { uint32_t _c = (R[5] == R[0]); R[3] = 0x8006u << 16; if (_c) { goto L_800D1488; } }  /* 0x800D13F8 */
    { R[2] = R[3] - 12296; goto L_800D1508; }  /* 0x800D1400 j */
L_800D1408:;
    { uint32_t _c = (R[5] != R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_800D1504; } }  /* 0x800D1408 */
    R[4] = 0x8014u << 16;  /* 0x800D1410 */
    R[4] = R[4] + 15160;  /* 0x800D1414 */
    R[5] = R[0] + 64;  /* 0x800D1418 */
    R[2] = R[0] + 1;  /* 0x800D141C */
    sb_(R[16] + 688, R[2]);  /* 0x800D1420 */
    sb_(R[16] + 690, R[2]);  /* 0x800D1424 */
    R[2] = 0x800Bu << 16;  /* 0x800D1428 */
    R[2] = R[2] - 6404;  /* 0x800D142C */
    R[3] = 0x8014u << 16;  /* 0x800D1430 */
    sw_(R[16] + 232, R[2]);  /* 0x800D1434 */
    R[2] = R[0] - 1;  /* 0x800D1438 */
    sh_(R[3] + 15132, R[2]);  /* 0x800D143C */
    { R[31] = 0x800D1448u; sh_(R[16] + 584, R[0]); psx_next = 0x800CD6CCu; return; }  /* 0x800D1440 jal */
    R[2] = 0x8012u << 16;  /* 0x800D1448 */
    R[5] = R[2] + 30872;  /* 0x800D144C */
    R[6] = lh_(R[5] + 192);  /* 0x800D1450 */
    { uint32_t _c = (R[6] == R[0]); R[3] = 0x8014u << 16; if (_c) { goto L_800D14B8; } }  /* 0x800D1458 */
    R[2] = lh_(R[5] + 194);  /* 0x800D1460 */
    R[4] = lh_(R[5] + 196);  /* 0x800D1464 */
    sh_(R[3] + 15008, R[6]);  /* 0x800D1468 */
    R[3] = R[3] + 15008;  /* 0x800D146C */
    sh_(R[5] + 192, R[0]);  /* 0x800D1470 */
    sh_(R[5] + 194, R[0]);  /* 0x800D1474 */
    sh_(R[5] + 196, R[0]);  /* 0x800D1478 */
    sh_(R[3] + 2, R[2]);  /* 0x800D147C */
    { sh_(R[3] + 4, R[4]); goto L_800D14B8; }  /* 0x800D1480 j */
L_800D1488:;
    R[3] = 0x800Fu << 16;  /* 0x800D1488 */
    R[3] = R[3] + 268;  /* 0x800D148C */
    R[2] = lb_(R[16] + 580);  /* 0x800D1490 */
    R[4] = lb_(R[16] + 581);  /* 0x800D1494 */
    R[2] = R[2] << 1;  /* 0x800D1498 */
    R[2] = R[2] + R[4];  /* 0x800D149C */
    R[2] = R[2] << 2;  /* 0x800D14A0 */
    R[2] = R[2] + R[3];  /* 0x800D14A4 */
    R[2] = lw_(R[2]);  /* 0x800D14A8 */
    { uint32_t _t = R[2]; R[31] = 0x800D14B8u; R[4] = R[16] + R[0]; psx_next = _t; return; }  /* 0x800D14B0 jalr */
L_800D14B8:;
    { R[31] = 0x800D14C0u; psx_next = 0x800CD33Cu; return; }  /* 0x800D14B8 jal */
    { R[3] = 0x8006u << 16; goto L_800D1504; }  /* 0x800D14C0 j */
L_800D14C8:;
    { R[31] = 0x800D14D0u; psx_next = 0x800D30D0u; return; }  /* 0x800D14C8 jal */
    R[3] = 0x8012u << 16;  /* 0x800D14D0 */
    R[2] = 0x8014u << 16;  /* 0x800D14D4 */
    R[4] = R[2] + 15008;  /* 0x800D14D8 */
    R[2] = lh_(R[2] + 15008);  /* 0x800D14DC */
    R[5] = lh_(R[4] + 2);  /* 0x800D14E0 */
    R[4] = lh_(R[4] + 4);  /* 0x800D14E4 */
    R[3] = R[3] + 30872;  /* 0x800D14E8 */
    sh_(R[3] + 192, R[2]);  /* 0x800D14EC */
    R[2] = R[0] + 3;  /* 0x800D14F0 */
    sh_(R[3] + 194, R[5]);  /* 0x800D14F4 */
    sh_(R[3] + 196, R[4]);  /* 0x800D14F8 */
    sb_(R[16] + 790, R[2]);  /* 0x800D14FC */
    R[3] = 0x8006u << 16;  /* 0x800D1500 */
L_800D1504:;
    R[2] = R[3] - 12296;  /* 0x800D1504 */
L_800D1508:;
    R[2] = lb_(R[2] + 2);  /* 0x800D1508 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800D1528; } }  /* 0x800D1510 */
    R[2] = lb_(R[3] + -12296);  /* 0x800D1518 */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8014u << 16; if (_c) { goto L_800D1588; } }  /* 0x800D1520 */
L_800D1528:;
    R[3] = 0x1u << 16;  /* 0x800D1528 */
    R[3] = R[3] | 0x8000;  /* 0x800D152C */
    R[4] = R[29] + 24;  /* 0x800D1530 */
    R[5] = 0x8008u << 16;  /* 0x800D1534 */
    R[2] = 0x8014u << 16;  /* 0x800D1538 */
    R[17] = 0x800Fu << 16;  /* 0x800D153C */
    R[17] = R[17] + 25528;  /* 0x800D1540 */
    R[17] = R[17] + R[3];  /* 0x800D1544 */
    R[6] = lw_(R[2] + 15148);  /* 0x800D1548 */
    R[16] = lw_(R[17] + 20496);  /* 0x800D154C */
    { R[31] = 0x800D1558u; R[5] = R[5] + 12616; psx_next = 0x80031BF8u; return; }  /* 0x800D1550 jal */
    R[4] = R[29] + 24;  /* 0x800D1558 */
    R[5] = R[0] + 34;  /* 0x800D155C */
    R[2] = 0x8011u << 16;  /* 0x800D1560 */
    R[6] = R[0] + 12;  /* 0x800D1564 */
    R[2] = lw_(R[2] + 29968);  /* 0x800D1568 */
    R[7] = R[0] + 1;  /* 0x800D156C */
    sw_(R[29] + 16, R[16]);  /* 0x800D1570 */
    R[2] = R[2] + 36;  /* 0x800D1574 */
    { R[31] = 0x800D1580u; sw_(R[29] + 20, R[2]); psx_next = 0x80019994u; return; }  /* 0x800D1578 jal */
    sw_(R[17] + 20496, R[2]);  /* 0x800D1580 */
    R[3] = 0x8014u << 16;  /* 0x800D1584 */
L_800D1588:;
    R[2] = lw_(R[3] + 15148);  /* 0x800D1588 */
    R[31] = lw_(R[29] + 40);  /* 0x800D158C */
    R[17] = lw_(R[29] + 36);  /* 0x800D1590 */
    R[16] = lw_(R[29] + 32);  /* 0x800D1594 */
    R[2] = R[2] + 1;  /* 0x800D1598 */
    sw_(R[3] + 15148, R[2]);  /* 0x800D159C */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D15A0 jr ra */
}

void g0_800D1448(void) {
    R[2] = 0x8012u << 16;  /* 0x800D1448 */
    R[5] = R[2] + 30872;  /* 0x800D144C */
    R[6] = lh_(R[5] + 192);  /* 0x800D1450 */
    { uint32_t _c = (R[6] == R[0]); R[3] = 0x8014u << 16; if (_c) { goto L_800D14B8; } }  /* 0x800D1458 */
    R[2] = lh_(R[5] + 194);  /* 0x800D1460 */
    R[4] = lh_(R[5] + 196);  /* 0x800D1464 */
    sh_(R[3] + 15008, R[6]);  /* 0x800D1468 */
    R[3] = R[3] + 15008;  /* 0x800D146C */
    sh_(R[5] + 192, R[0]);  /* 0x800D1470 */
    sh_(R[5] + 194, R[0]);  /* 0x800D1474 */
    sh_(R[5] + 196, R[0]);  /* 0x800D1478 */
    sh_(R[3] + 2, R[2]);  /* 0x800D147C */
    { sh_(R[3] + 4, R[4]); goto L_800D14B8; }  /* 0x800D1480 j */
    R[3] = 0x800Fu << 16;  /* 0x800D1488 */
    R[3] = R[3] + 268;  /* 0x800D148C */
    R[2] = lb_(R[16] + 580);  /* 0x800D1490 */
    R[4] = lb_(R[16] + 581);  /* 0x800D1494 */
    R[2] = R[2] << 1;  /* 0x800D1498 */
    R[2] = R[2] + R[4];  /* 0x800D149C */
    R[2] = R[2] << 2;  /* 0x800D14A0 */
    R[2] = R[2] + R[3];  /* 0x800D14A4 */
    R[2] = lw_(R[2]);  /* 0x800D14A8 */
    { uint32_t _t = R[2]; R[31] = 0x800D14B8u; R[4] = R[16] + R[0]; psx_next = _t; return; }  /* 0x800D14B0 jalr */
L_800D14B8:;
    { R[31] = 0x800D14C0u; psx_next = 0x800CD33Cu; return; }  /* 0x800D14B8 jal */
    { R[3] = 0x8006u << 16; goto L_800D1504; }  /* 0x800D14C0 j */
    { R[31] = 0x800D14D0u; psx_next = 0x800D30D0u; return; }  /* 0x800D14C8 jal */
    R[3] = 0x8012u << 16;  /* 0x800D14D0 */
    R[2] = 0x8014u << 16;  /* 0x800D14D4 */
    R[4] = R[2] + 15008;  /* 0x800D14D8 */
    R[2] = lh_(R[2] + 15008);  /* 0x800D14DC */
    R[5] = lh_(R[4] + 2);  /* 0x800D14E0 */
    R[4] = lh_(R[4] + 4);  /* 0x800D14E4 */
    R[3] = R[3] + 30872;  /* 0x800D14E8 */
    sh_(R[3] + 192, R[2]);  /* 0x800D14EC */
    R[2] = R[0] + 3;  /* 0x800D14F0 */
    sh_(R[3] + 194, R[5]);  /* 0x800D14F4 */
    sh_(R[3] + 196, R[4]);  /* 0x800D14F8 */
    sb_(R[16] + 790, R[2]);  /* 0x800D14FC */
    R[3] = 0x8006u << 16;  /* 0x800D1500 */
L_800D1504:;
    R[2] = R[3] - 12296;  /* 0x800D1504 */
    R[2] = lb_(R[2] + 2);  /* 0x800D1508 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800D1528; } }  /* 0x800D1510 */
    R[2] = lb_(R[3] + -12296);  /* 0x800D1518 */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8014u << 16; if (_c) { goto L_800D1588; } }  /* 0x800D1520 */
L_800D1528:;
    R[3] = 0x1u << 16;  /* 0x800D1528 */
    R[3] = R[3] | 0x8000;  /* 0x800D152C */
    R[4] = R[29] + 24;  /* 0x800D1530 */
    R[5] = 0x8008u << 16;  /* 0x800D1534 */
    R[2] = 0x8014u << 16;  /* 0x800D1538 */
    R[17] = 0x800Fu << 16;  /* 0x800D153C */
    R[17] = R[17] + 25528;  /* 0x800D1540 */
    R[17] = R[17] + R[3];  /* 0x800D1544 */
    R[6] = lw_(R[2] + 15148);  /* 0x800D1548 */
    R[16] = lw_(R[17] + 20496);  /* 0x800D154C */
    { R[31] = 0x800D1558u; R[5] = R[5] + 12616; psx_next = 0x80031BF8u; return; }  /* 0x800D1550 jal */
    R[4] = R[29] + 24;  /* 0x800D1558 */
    R[5] = R[0] + 34;  /* 0x800D155C */
    R[2] = 0x8011u << 16;  /* 0x800D1560 */
    R[6] = R[0] + 12;  /* 0x800D1564 */
    R[2] = lw_(R[2] + 29968);  /* 0x800D1568 */
    R[7] = R[0] + 1;  /* 0x800D156C */
    sw_(R[29] + 16, R[16]);  /* 0x800D1570 */
    R[2] = R[2] + 36;  /* 0x800D1574 */
    { R[31] = 0x800D1580u; sw_(R[29] + 20, R[2]); psx_next = 0x80019994u; return; }  /* 0x800D1578 jal */
    sw_(R[17] + 20496, R[2]);  /* 0x800D1580 */
    R[3] = 0x8014u << 16;  /* 0x800D1584 */
L_800D1588:;
    R[2] = lw_(R[3] + 15148);  /* 0x800D1588 */
    R[31] = lw_(R[29] + 40);  /* 0x800D158C */
    R[17] = lw_(R[29] + 36);  /* 0x800D1590 */
    R[16] = lw_(R[29] + 32);  /* 0x800D1594 */
    R[2] = R[2] + 1;  /* 0x800D1598 */
    sw_(R[3] + 15148, R[2]);  /* 0x800D159C */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D15A0 jr ra */
}

void g0_800D14B8(void) {
    { R[31] = 0x800D14C0u; psx_next = 0x800CD33Cu; return; }  /* 0x800D14B8 jal */
    { R[3] = 0x8006u << 16; goto L_800D1504; }  /* 0x800D14C0 j */
    { R[31] = 0x800D14D0u; psx_next = 0x800D30D0u; return; }  /* 0x800D14C8 jal */
    R[3] = 0x8012u << 16;  /* 0x800D14D0 */
    R[2] = 0x8014u << 16;  /* 0x800D14D4 */
    R[4] = R[2] + 15008;  /* 0x800D14D8 */
    R[2] = lh_(R[2] + 15008);  /* 0x800D14DC */
    R[5] = lh_(R[4] + 2);  /* 0x800D14E0 */
    R[4] = lh_(R[4] + 4);  /* 0x800D14E4 */
    R[3] = R[3] + 30872;  /* 0x800D14E8 */
    sh_(R[3] + 192, R[2]);  /* 0x800D14EC */
    R[2] = R[0] + 3;  /* 0x800D14F0 */
    sh_(R[3] + 194, R[5]);  /* 0x800D14F4 */
    sh_(R[3] + 196, R[4]);  /* 0x800D14F8 */
    sb_(R[16] + 790, R[2]);  /* 0x800D14FC */
    R[3] = 0x8006u << 16;  /* 0x800D1500 */
L_800D1504:;
    R[2] = R[3] - 12296;  /* 0x800D1504 */
    R[2] = lb_(R[2] + 2);  /* 0x800D1508 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800D1528; } }  /* 0x800D1510 */
    R[2] = lb_(R[3] + -12296);  /* 0x800D1518 */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8014u << 16; if (_c) { goto L_800D1588; } }  /* 0x800D1520 */
L_800D1528:;
    R[3] = 0x1u << 16;  /* 0x800D1528 */
    R[3] = R[3] | 0x8000;  /* 0x800D152C */
    R[4] = R[29] + 24;  /* 0x800D1530 */
    R[5] = 0x8008u << 16;  /* 0x800D1534 */
    R[2] = 0x8014u << 16;  /* 0x800D1538 */
    R[17] = 0x800Fu << 16;  /* 0x800D153C */
    R[17] = R[17] + 25528;  /* 0x800D1540 */
    R[17] = R[17] + R[3];  /* 0x800D1544 */
    R[6] = lw_(R[2] + 15148);  /* 0x800D1548 */
    R[16] = lw_(R[17] + 20496);  /* 0x800D154C */
    { R[31] = 0x800D1558u; R[5] = R[5] + 12616; psx_next = 0x80031BF8u; return; }  /* 0x800D1550 jal */
    R[4] = R[29] + 24;  /* 0x800D1558 */
    R[5] = R[0] + 34;  /* 0x800D155C */
    R[2] = 0x8011u << 16;  /* 0x800D1560 */
    R[6] = R[0] + 12;  /* 0x800D1564 */
    R[2] = lw_(R[2] + 29968);  /* 0x800D1568 */
    R[7] = R[0] + 1;  /* 0x800D156C */
    sw_(R[29] + 16, R[16]);  /* 0x800D1570 */
    R[2] = R[2] + 36;  /* 0x800D1574 */
    { R[31] = 0x800D1580u; sw_(R[29] + 20, R[2]); psx_next = 0x80019994u; return; }  /* 0x800D1578 jal */
    sw_(R[17] + 20496, R[2]);  /* 0x800D1580 */
    R[3] = 0x8014u << 16;  /* 0x800D1584 */
L_800D1588:;
    R[2] = lw_(R[3] + 15148);  /* 0x800D1588 */
    R[31] = lw_(R[29] + 40);  /* 0x800D158C */
    R[17] = lw_(R[29] + 36);  /* 0x800D1590 */
    R[16] = lw_(R[29] + 32);  /* 0x800D1594 */
    R[2] = R[2] + 1;  /* 0x800D1598 */
    sw_(R[3] + 15148, R[2]);  /* 0x800D159C */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D15A0 jr ra */
}

void g0_800D14C0(void) {
    { R[3] = 0x8006u << 16; goto L_800D1504; }  /* 0x800D14C0 j */
    { R[31] = 0x800D14D0u; psx_next = 0x800D30D0u; return; }  /* 0x800D14C8 jal */
    R[3] = 0x8012u << 16;  /* 0x800D14D0 */
    R[2] = 0x8014u << 16;  /* 0x800D14D4 */
    R[4] = R[2] + 15008;  /* 0x800D14D8 */
    R[2] = lh_(R[2] + 15008);  /* 0x800D14DC */
    R[5] = lh_(R[4] + 2);  /* 0x800D14E0 */
    R[4] = lh_(R[4] + 4);  /* 0x800D14E4 */
    R[3] = R[3] + 30872;  /* 0x800D14E8 */
    sh_(R[3] + 192, R[2]);  /* 0x800D14EC */
    R[2] = R[0] + 3;  /* 0x800D14F0 */
    sh_(R[3] + 194, R[5]);  /* 0x800D14F4 */
    sh_(R[3] + 196, R[4]);  /* 0x800D14F8 */
    sb_(R[16] + 790, R[2]);  /* 0x800D14FC */
    R[3] = 0x8006u << 16;  /* 0x800D1500 */
L_800D1504:;
    R[2] = R[3] - 12296;  /* 0x800D1504 */
    R[2] = lb_(R[2] + 2);  /* 0x800D1508 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800D1528; } }  /* 0x800D1510 */
    R[2] = lb_(R[3] + -12296);  /* 0x800D1518 */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8014u << 16; if (_c) { goto L_800D1588; } }  /* 0x800D1520 */
L_800D1528:;
    R[3] = 0x1u << 16;  /* 0x800D1528 */
    R[3] = R[3] | 0x8000;  /* 0x800D152C */
    R[4] = R[29] + 24;  /* 0x800D1530 */
    R[5] = 0x8008u << 16;  /* 0x800D1534 */
    R[2] = 0x8014u << 16;  /* 0x800D1538 */
    R[17] = 0x800Fu << 16;  /* 0x800D153C */
    R[17] = R[17] + 25528;  /* 0x800D1540 */
    R[17] = R[17] + R[3];  /* 0x800D1544 */
    R[6] = lw_(R[2] + 15148);  /* 0x800D1548 */
    R[16] = lw_(R[17] + 20496);  /* 0x800D154C */
    { R[31] = 0x800D1558u; R[5] = R[5] + 12616; psx_next = 0x80031BF8u; return; }  /* 0x800D1550 jal */
    R[4] = R[29] + 24;  /* 0x800D1558 */
    R[5] = R[0] + 34;  /* 0x800D155C */
    R[2] = 0x8011u << 16;  /* 0x800D1560 */
    R[6] = R[0] + 12;  /* 0x800D1564 */
    R[2] = lw_(R[2] + 29968);  /* 0x800D1568 */
    R[7] = R[0] + 1;  /* 0x800D156C */
    sw_(R[29] + 16, R[16]);  /* 0x800D1570 */
    R[2] = R[2] + 36;  /* 0x800D1574 */
    { R[31] = 0x800D1580u; sw_(R[29] + 20, R[2]); psx_next = 0x80019994u; return; }  /* 0x800D1578 jal */
    sw_(R[17] + 20496, R[2]);  /* 0x800D1580 */
    R[3] = 0x8014u << 16;  /* 0x800D1584 */
L_800D1588:;
    R[2] = lw_(R[3] + 15148);  /* 0x800D1588 */
    R[31] = lw_(R[29] + 40);  /* 0x800D158C */
    R[17] = lw_(R[29] + 36);  /* 0x800D1590 */
    R[16] = lw_(R[29] + 32);  /* 0x800D1594 */
    R[2] = R[2] + 1;  /* 0x800D1598 */
    sw_(R[3] + 15148, R[2]);  /* 0x800D159C */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D15A0 jr ra */
}

void g0_800D14D0(void) {
    R[3] = 0x8012u << 16;  /* 0x800D14D0 */
    R[2] = 0x8014u << 16;  /* 0x800D14D4 */
    R[4] = R[2] + 15008;  /* 0x800D14D8 */
    R[2] = lh_(R[2] + 15008);  /* 0x800D14DC */
    R[5] = lh_(R[4] + 2);  /* 0x800D14E0 */
    R[4] = lh_(R[4] + 4);  /* 0x800D14E4 */
    R[3] = R[3] + 30872;  /* 0x800D14E8 */
    sh_(R[3] + 192, R[2]);  /* 0x800D14EC */
    R[2] = R[0] + 3;  /* 0x800D14F0 */
    sh_(R[3] + 194, R[5]);  /* 0x800D14F4 */
    sh_(R[3] + 196, R[4]);  /* 0x800D14F8 */
    sb_(R[16] + 790, R[2]);  /* 0x800D14FC */
    R[3] = 0x8006u << 16;  /* 0x800D1500 */
    R[2] = R[3] - 12296;  /* 0x800D1504 */
    R[2] = lb_(R[2] + 2);  /* 0x800D1508 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800D1528; } }  /* 0x800D1510 */
    R[2] = lb_(R[3] + -12296);  /* 0x800D1518 */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8014u << 16; if (_c) { goto L_800D1588; } }  /* 0x800D1520 */
L_800D1528:;
    R[3] = 0x1u << 16;  /* 0x800D1528 */
    R[3] = R[3] | 0x8000;  /* 0x800D152C */
    R[4] = R[29] + 24;  /* 0x800D1530 */
    R[5] = 0x8008u << 16;  /* 0x800D1534 */
    R[2] = 0x8014u << 16;  /* 0x800D1538 */
    R[17] = 0x800Fu << 16;  /* 0x800D153C */
    R[17] = R[17] + 25528;  /* 0x800D1540 */
    R[17] = R[17] + R[3];  /* 0x800D1544 */
    R[6] = lw_(R[2] + 15148);  /* 0x800D1548 */
    R[16] = lw_(R[17] + 20496);  /* 0x800D154C */
    { R[31] = 0x800D1558u; R[5] = R[5] + 12616; psx_next = 0x80031BF8u; return; }  /* 0x800D1550 jal */
    R[4] = R[29] + 24;  /* 0x800D1558 */
    R[5] = R[0] + 34;  /* 0x800D155C */
    R[2] = 0x8011u << 16;  /* 0x800D1560 */
    R[6] = R[0] + 12;  /* 0x800D1564 */
    R[2] = lw_(R[2] + 29968);  /* 0x800D1568 */
    R[7] = R[0] + 1;  /* 0x800D156C */
    sw_(R[29] + 16, R[16]);  /* 0x800D1570 */
    R[2] = R[2] + 36;  /* 0x800D1574 */
    { R[31] = 0x800D1580u; sw_(R[29] + 20, R[2]); psx_next = 0x80019994u; return; }  /* 0x800D1578 jal */
    sw_(R[17] + 20496, R[2]);  /* 0x800D1580 */
    R[3] = 0x8014u << 16;  /* 0x800D1584 */
L_800D1588:;
    R[2] = lw_(R[3] + 15148);  /* 0x800D1588 */
    R[31] = lw_(R[29] + 40);  /* 0x800D158C */
    R[17] = lw_(R[29] + 36);  /* 0x800D1590 */
    R[16] = lw_(R[29] + 32);  /* 0x800D1594 */
    R[2] = R[2] + 1;  /* 0x800D1598 */
    sw_(R[3] + 15148, R[2]);  /* 0x800D159C */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D15A0 jr ra */
}

void g0_800D1558(void) {
    R[4] = R[29] + 24;  /* 0x800D1558 */
    R[5] = R[0] + 34;  /* 0x800D155C */
    R[2] = 0x8011u << 16;  /* 0x800D1560 */
    R[6] = R[0] + 12;  /* 0x800D1564 */
    R[2] = lw_(R[2] + 29968);  /* 0x800D1568 */
    R[7] = R[0] + 1;  /* 0x800D156C */
    sw_(R[29] + 16, R[16]);  /* 0x800D1570 */
    R[2] = R[2] + 36;  /* 0x800D1574 */
    { R[31] = 0x800D1580u; sw_(R[29] + 20, R[2]); psx_next = 0x80019994u; return; }  /* 0x800D1578 jal */
    sw_(R[17] + 20496, R[2]);  /* 0x800D1580 */
    R[3] = 0x8014u << 16;  /* 0x800D1584 */
    R[2] = lw_(R[3] + 15148);  /* 0x800D1588 */
    R[31] = lw_(R[29] + 40);  /* 0x800D158C */
    R[17] = lw_(R[29] + 36);  /* 0x800D1590 */
    R[16] = lw_(R[29] + 32);  /* 0x800D1594 */
    R[2] = R[2] + 1;  /* 0x800D1598 */
    sw_(R[3] + 15148, R[2]);  /* 0x800D159C */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D15A0 jr ra */
}

void g0_800D1580(void) {
    sw_(R[17] + 20496, R[2]);  /* 0x800D1580 */
    R[3] = 0x8014u << 16;  /* 0x800D1584 */
    R[2] = lw_(R[3] + 15148);  /* 0x800D1588 */
    R[31] = lw_(R[29] + 40);  /* 0x800D158C */
    R[17] = lw_(R[29] + 36);  /* 0x800D1590 */
    R[16] = lw_(R[29] + 32);  /* 0x800D1594 */
    R[2] = R[2] + 1;  /* 0x800D1598 */
    sw_(R[3] + 15148, R[2]);  /* 0x800D159C */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800D15A0 jr ra */
}

void g0_800D15A8(void) {
    R[29] = R[29] - 24;  /* 0x800D15A8 */
    { uint32_t _c = (R[5] == R[0]); sw_(R[29] + 16, R[31]); if (_c) { goto L_800D15D4; } }  /* 0x800D15AC */
    R[2] = R[0] + 5;  /* 0x800D15B4 */
    { uint32_t _c = (R[5] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800D15F8; } }  /* 0x800D15B8 */
    sb_(R[4] + 688, R[2]);  /* 0x800D15C0 */
    R[2] = 0x800Bu << 16;  /* 0x800D15C4 */
    R[2] = R[2] - 6404;  /* 0x800D15C8 */
    { sw_(R[4] + 232, R[2]); goto L_800D15F8; }  /* 0x800D15CC j */
L_800D15D4:;
    R[2] = 0x800Fu << 16;  /* 0x800D15D4 */
    R[3] = lb_(R[4] + 580);  /* 0x800D15D8 */
    R[2] = R[2] + 300;  /* 0x800D15DC */
    R[3] = R[3] << 2;  /* 0x800D15E0 */
    R[3] = R[3] + R[2];  /* 0x800D15E4 */
    R[2] = lw_(R[3]);  /* 0x800D15E8 */
    { uint32_t _t = R[2]; R[31] = 0x800D15F8u; psx_next = _t; return; }  /* 0x800D15F0 jalr */
L_800D15F8:;
    R[31] = lw_(R[29] + 16);  /* 0x800D15F8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800D1600 jr ra */
}

void g0_800D15F8(void) {
    R[31] = lw_(R[29] + 16);  /* 0x800D15F8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800D1600 jr ra */
}

void g0_800D1608(void) {
    R[29] = R[29] - 24;  /* 0x800D1608 */
    { uint32_t _c = (R[5] == R[0]); sw_(R[29] + 16, R[31]); if (_c) { goto L_800D1668; } }  /* 0x800D160C */
    R[2] = R[0] + 5;  /* 0x800D1614 */
    { uint32_t _c = (R[5] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800D168C; } }  /* 0x800D1618 */
    R[3] = lb_(R[4] + 580);  /* 0x800D1620 */
    { uint32_t _c = (R[3] == R[0]); sb_(R[4] + 688, R[2]); if (_c) { goto L_800D164C; } }  /* 0x800D1628 */
    R[2] = R[0] + 6;  /* 0x800D1630 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 8; if (_c) { goto L_800D164C; } }  /* 0x800D1634 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 10; if (_c) { goto L_800D164C; } }  /* 0x800D163C */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_800D165C; } }  /* 0x800D1644 */
L_800D164C:;
    R[2] = 0x800Bu << 16;  /* 0x800D164C */
    R[2] = R[2] - 4620;  /* 0x800D1650 */
    { sw_(R[4] + 232, R[2]); goto L_800D168C; }  /* 0x800D1654 j */
L_800D165C:;
    R[2] = R[2] - 6404;  /* 0x800D165C */
    { sw_(R[4] + 232, R[2]); goto L_800D168C; }  /* 0x800D1660 j */
L_800D1668:;
    R[2] = 0x800Fu << 16;  /* 0x800D1668 */
    R[3] = lb_(R[4] + 580);  /* 0x800D166C */
    R[2] = R[2] + 340;  /* 0x800D1670 */
    R[3] = R[3] << 2;  /* 0x800D1674 */
    R[3] = R[3] + R[2];  /* 0x800D1678 */
    R[2] = lw_(R[3]);  /* 0x800D167C */
    { uint32_t _t = R[2]; R[31] = 0x800D168Cu; psx_next = _t; return; }  /* 0x800D1684 jalr */
L_800D168C:;
    R[31] = lw_(R[29] + 16);  /* 0x800D168C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800D1694 jr ra */
}

void g0_800D168C(void) {
    R[31] = lw_(R[29] + 16);  /* 0x800D168C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800D1694 jr ra */
}

void g0_800D169C(void) {
    R[29] = R[29] - 24;  /* 0x800D169C */
    { uint32_t _c = (R[5] == R[0]); sw_(R[29] + 16, R[31]); if (_c) { goto L_800D16EC; } }  /* 0x800D16A0 */
    R[2] = R[0] + 5;  /* 0x800D16A8 */
    { uint32_t _c = (R[5] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800D1710; } }  /* 0x800D16AC */
    R[3] = lb_(R[4] + 580);  /* 0x800D16B4 */
    sb_(R[4] + 688, R[2]);  /* 0x800D16B8 */
    R[2] = R[0] + 4;  /* 0x800D16BC */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 8; if (_c) { goto L_800D16D0; } }  /* 0x800D16C0 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_800D16E0; } }  /* 0x800D16C8 */
L_800D16D0:;
    R[2] = 0x800Bu << 16;  /* 0x800D16D0 */
    R[2] = R[2] - 4620;  /* 0x800D16D4 */
    { sw_(R[4] + 232, R[2]); goto L_800D1710; }  /* 0x800D16D8 j */
L_800D16E0:;
    R[2] = R[2] - 6404;  /* 0x800D16E0 */
    { sw_(R[4] + 232, R[2]); goto L_800D1710; }  /* 0x800D16E4 j */
L_800D16EC:;
    R[2] = 0x800Fu << 16;  /* 0x800D16EC */
    R[3] = lb_(R[4] + 580);  /* 0x800D16F0 */
    R[2] = R[2] + 392;  /* 0x800D16F4 */
    R[3] = R[3] << 2;  /* 0x800D16F8 */
    R[3] = R[3] + R[2];  /* 0x800D16FC */
    R[2] = lw_(R[3]);  /* 0x800D1700 */
    { uint32_t _t = R[2]; R[31] = 0x800D1710u; psx_next = _t; return; }  /* 0x800D1708 jalr */
L_800D1710:;
    R[31] = lw_(R[29] + 16);  /* 0x800D1710 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800D1718 jr ra */
}

void g0_800D1710(void) {
    R[31] = lw_(R[29] + 16);  /* 0x800D1710 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800D1718 jr ra */
}

void g0_800D1720(void) {
    R[29] = R[29] - 24;  /* 0x800D1720 */
    { uint32_t _c = (R[5] == R[0]); sw_(R[29] + 16, R[31]); if (_c) { goto L_800D1768; } }  /* 0x800D1724 */
    R[2] = R[0] + 5;  /* 0x800D172C */
    { uint32_t _c = (R[5] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800D178C; } }  /* 0x800D1730 */
    R[3] = lb_(R[4] + 580);  /* 0x800D1738 */
    sb_(R[4] + 688, R[2]);  /* 0x800D173C */
    R[2] = R[0] + 6;  /* 0x800D1740 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_800D175C; } }  /* 0x800D1744 */
    R[2] = 0x800Bu << 16;  /* 0x800D174C */
    R[2] = R[2] - 4620;  /* 0x800D1750 */
    { sw_(R[4] + 232, R[2]); goto L_800D178C; }  /* 0x800D1754 j */
L_800D175C:;
    R[2] = R[2] - 6404;  /* 0x800D175C */
    { sw_(R[4] + 232, R[2]); goto L_800D178C; }  /* 0x800D1760 j */
L_800D1768:;
    R[2] = 0x800Fu << 16;  /* 0x800D1768 */
    R[3] = lb_(R[4] + 580);  /* 0x800D176C */
    R[2] = R[2] + 428;  /* 0x800D1770 */
    R[3] = R[3] << 2;  /* 0x800D1774 */
    R[3] = R[3] + R[2];  /* 0x800D1778 */
    R[2] = lw_(R[3]);  /* 0x800D177C */
    { uint32_t _t = R[2]; R[31] = 0x800D178Cu; psx_next = _t; return; }  /* 0x800D1784 jalr */
L_800D178C:;
    R[31] = lw_(R[29] + 16);  /* 0x800D178C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800D1794 jr ra */
}

void g0_800D178C(void) {
    R[31] = lw_(R[29] + 16);  /* 0x800D178C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800D1794 jr ra */
}

void g0_800D179C(void) {
    R[29] = R[29] - 32;  /* 0x800D179C */
    sw_(R[29] + 24, R[18]);  /* 0x800D17A0 */
    R[18] = R[4] + R[0];  /* 0x800D17A4 */
    sw_(R[29] + 28, R[31]);  /* 0x800D17A8 */
    sw_(R[29] + 20, R[17]);  /* 0x800D17AC */
    { R[31] = 0x800D17B8u; sw_(R[29] + 16, R[16]); psx_next = 0x80023DC4u; return; }  /* 0x800D17B0 jal */
    R[17] = R[2] + R[0];  /* 0x800D17B8 */
    { uint32_t _c = ((int32_t)R[17] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D1858; } }  /* 0x800D17BC */
    { R[31] = 0x800D17CCu; R[4] = R[17] + R[0]; psx_next = 0x80023E24u; return; }  /* 0x800D17C4 jal */
    R[16] = R[2] + R[0];  /* 0x800D17CC */
    { uint32_t _c = ((int32_t)R[16] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D1858; } }  /* 0x800D17D0 */
    { uint32_t _c = (R[18] != R[0]); R[17] = R[17] - 23; if (_c) { goto L_800D17F4; } }  /* 0x800D17D8 */
    { R[31] = 0x800D17E8u; R[4] = R[0] + 74; psx_next = 0x80023CE8u; return; }  /* 0x800D17E0 jal */
    R[2] = ~(R[0] | R[2]);  /* 0x800D17E8 */
    { R[16] = R[2] >> 31; goto L_800D1828; }  /* 0x800D17EC j */
L_800D17F4:;
    R[16] = R[16] - 1;  /* 0x800D17F4 */
    R[16] = R[16] & 0x1;  /* 0x800D17F8 */
    R[2] = 0x800Fu << 16;  /* 0x800D17FC */
    R[2] = R[2] - 568;  /* 0x800D1800 */
    R[3] = R[17] << 1;  /* 0x800D1804 */
    R[3] = R[3] + R[16];  /* 0x800D1808 */
    R[3] = R[3] << 2;  /* 0x800D180C */
    R[3] = R[3] + R[2];  /* 0x800D1810 */
    R[4] = lw_(R[3]);  /* 0x800D1814 */
    { R[31] = 0x800D1820u; psx_next = 0x80093890u; return; }  /* 0x800D1818 jal */
    R[2] = 0x8014u << 16;  /* 0x800D1820 */
    sw_(R[2] + 15148, R[0]);  /* 0x800D1824 */
L_800D1828:;
    R[4] = 0x800Fu << 16;  /* 0x800D1828 */
    R[4] = R[4] + 480;  /* 0x800D182C */
    R[2] = R[17] << 2;  /* 0x800D1830 */
    R[3] = R[18] << 1;  /* 0x800D1834 */
    R[2] = R[2] + R[3];  /* 0x800D1838 */
    R[2] = R[2] + R[16];  /* 0x800D183C */
    R[2] = R[2] << 2;  /* 0x800D1840 */
    R[2] = R[2] + R[4];  /* 0x800D1844 */
    R[2] = lw_(R[2]);  /* 0x800D1848 */
    { uint32_t _t = R[2]; R[31] = 0x800D1858u; psx_next = _t; return; }  /* 0x800D1850 jalr */
L_800D1858:;
    R[31] = lw_(R[29] + 28);  /* 0x800D1858 */
    R[18] = lw_(R[29] + 24);  /* 0x800D185C */
    R[17] = lw_(R[29] + 20);  /* 0x800D1860 */
    R[16] = lw_(R[29] + 16);  /* 0x800D1864 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D1868 jr ra */
}

void g0_800D17B8(void) {
    R[17] = R[2] + R[0];  /* 0x800D17B8 */
    { uint32_t _c = ((int32_t)R[17] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D1858; } }  /* 0x800D17BC */
    { R[31] = 0x800D17CCu; R[4] = R[17] + R[0]; psx_next = 0x80023E24u; return; }  /* 0x800D17C4 jal */
    R[16] = R[2] + R[0];  /* 0x800D17CC */
    { uint32_t _c = ((int32_t)R[16] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D1858; } }  /* 0x800D17D0 */
    { uint32_t _c = (R[18] != R[0]); R[17] = R[17] - 23; if (_c) { goto L_800D17F4; } }  /* 0x800D17D8 */
    { R[31] = 0x800D17E8u; R[4] = R[0] + 74; psx_next = 0x80023CE8u; return; }  /* 0x800D17E0 jal */
    R[2] = ~(R[0] | R[2]);  /* 0x800D17E8 */
    { R[16] = R[2] >> 31; goto L_800D1828; }  /* 0x800D17EC j */
L_800D17F4:;
    R[16] = R[16] - 1;  /* 0x800D17F4 */
    R[16] = R[16] & 0x1;  /* 0x800D17F8 */
    R[2] = 0x800Fu << 16;  /* 0x800D17FC */
    R[2] = R[2] - 568;  /* 0x800D1800 */
    R[3] = R[17] << 1;  /* 0x800D1804 */
    R[3] = R[3] + R[16];  /* 0x800D1808 */
    R[3] = R[3] << 2;  /* 0x800D180C */
    R[3] = R[3] + R[2];  /* 0x800D1810 */
    R[4] = lw_(R[3]);  /* 0x800D1814 */
    { R[31] = 0x800D1820u; psx_next = 0x80093890u; return; }  /* 0x800D1818 jal */
    R[2] = 0x8014u << 16;  /* 0x800D1820 */
    sw_(R[2] + 15148, R[0]);  /* 0x800D1824 */
L_800D1828:;
    R[4] = 0x800Fu << 16;  /* 0x800D1828 */
    R[4] = R[4] + 480;  /* 0x800D182C */
    R[2] = R[17] << 2;  /* 0x800D1830 */
    R[3] = R[18] << 1;  /* 0x800D1834 */
    R[2] = R[2] + R[3];  /* 0x800D1838 */
    R[2] = R[2] + R[16];  /* 0x800D183C */
    R[2] = R[2] << 2;  /* 0x800D1840 */
    R[2] = R[2] + R[4];  /* 0x800D1844 */
    R[2] = lw_(R[2]);  /* 0x800D1848 */
    { uint32_t _t = R[2]; R[31] = 0x800D1858u; psx_next = _t; return; }  /* 0x800D1850 jalr */
L_800D1858:;
    R[31] = lw_(R[29] + 28);  /* 0x800D1858 */
    R[18] = lw_(R[29] + 24);  /* 0x800D185C */
    R[17] = lw_(R[29] + 20);  /* 0x800D1860 */
    R[16] = lw_(R[29] + 16);  /* 0x800D1864 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D1868 jr ra */
}

void g0_800D17CC(void) {
    R[16] = R[2] + R[0];  /* 0x800D17CC */
    { uint32_t _c = ((int32_t)R[16] < 0); R[2] = R[0] - 1; if (_c) { goto L_800D1858; } }  /* 0x800D17D0 */
    { uint32_t _c = (R[18] != R[0]); R[17] = R[17] - 23; if (_c) { goto L_800D17F4; } }  /* 0x800D17D8 */
    { R[31] = 0x800D17E8u; R[4] = R[0] + 74; psx_next = 0x80023CE8u; return; }  /* 0x800D17E0 jal */
    R[2] = ~(R[0] | R[2]);  /* 0x800D17E8 */
    { R[16] = R[2] >> 31; goto L_800D1828; }  /* 0x800D17EC j */
L_800D17F4:;
    R[16] = R[16] - 1;  /* 0x800D17F4 */
    R[16] = R[16] & 0x1;  /* 0x800D17F8 */
    R[2] = 0x800Fu << 16;  /* 0x800D17FC */
    R[2] = R[2] - 568;  /* 0x800D1800 */
    R[3] = R[17] << 1;  /* 0x800D1804 */
    R[3] = R[3] + R[16];  /* 0x800D1808 */
    R[3] = R[3] << 2;  /* 0x800D180C */
    R[3] = R[3] + R[2];  /* 0x800D1810 */
    R[4] = lw_(R[3]);  /* 0x800D1814 */
    { R[31] = 0x800D1820u; psx_next = 0x80093890u; return; }  /* 0x800D1818 jal */
    R[2] = 0x8014u << 16;  /* 0x800D1820 */
    sw_(R[2] + 15148, R[0]);  /* 0x800D1824 */
L_800D1828:;
    R[4] = 0x800Fu << 16;  /* 0x800D1828 */
    R[4] = R[4] + 480;  /* 0x800D182C */
    R[2] = R[17] << 2;  /* 0x800D1830 */
    R[3] = R[18] << 1;  /* 0x800D1834 */
    R[2] = R[2] + R[3];  /* 0x800D1838 */
    R[2] = R[2] + R[16];  /* 0x800D183C */
    R[2] = R[2] << 2;  /* 0x800D1840 */
    R[2] = R[2] + R[4];  /* 0x800D1844 */
    R[2] = lw_(R[2]);  /* 0x800D1848 */
    { uint32_t _t = R[2]; R[31] = 0x800D1858u; psx_next = _t; return; }  /* 0x800D1850 jalr */
L_800D1858:;
    R[31] = lw_(R[29] + 28);  /* 0x800D1858 */
    R[18] = lw_(R[29] + 24);  /* 0x800D185C */
    R[17] = lw_(R[29] + 20);  /* 0x800D1860 */
    R[16] = lw_(R[29] + 16);  /* 0x800D1864 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D1868 jr ra */
}

void g0_800D17E8(void) {
    R[2] = ~(R[0] | R[2]);  /* 0x800D17E8 */
    { R[16] = R[2] >> 31; goto L_800D1828; }  /* 0x800D17EC j */
    R[16] = R[16] - 1;  /* 0x800D17F4 */
    R[16] = R[16] & 0x1;  /* 0x800D17F8 */
    R[2] = 0x800Fu << 16;  /* 0x800D17FC */
    R[2] = R[2] - 568;  /* 0x800D1800 */
    R[3] = R[17] << 1;  /* 0x800D1804 */
    R[3] = R[3] + R[16];  /* 0x800D1808 */
    R[3] = R[3] << 2;  /* 0x800D180C */
    R[3] = R[3] + R[2];  /* 0x800D1810 */
    R[4] = lw_(R[3]);  /* 0x800D1814 */
    { R[31] = 0x800D1820u; psx_next = 0x80093890u; return; }  /* 0x800D1818 jal */
    R[2] = 0x8014u << 16;  /* 0x800D1820 */
    sw_(R[2] + 15148, R[0]);  /* 0x800D1824 */
L_800D1828:;
    R[4] = 0x800Fu << 16;  /* 0x800D1828 */
    R[4] = R[4] + 480;  /* 0x800D182C */
    R[2] = R[17] << 2;  /* 0x800D1830 */
    R[3] = R[18] << 1;  /* 0x800D1834 */
    R[2] = R[2] + R[3];  /* 0x800D1838 */
    R[2] = R[2] + R[16];  /* 0x800D183C */
    R[2] = R[2] << 2;  /* 0x800D1840 */
    R[2] = R[2] + R[4];  /* 0x800D1844 */
    R[2] = lw_(R[2]);  /* 0x800D1848 */
    { uint32_t _t = R[2]; R[31] = 0x800D1858u; psx_next = _t; return; }  /* 0x800D1850 jalr */
    R[31] = lw_(R[29] + 28);  /* 0x800D1858 */
    R[18] = lw_(R[29] + 24);  /* 0x800D185C */
    R[17] = lw_(R[29] + 20);  /* 0x800D1860 */
    R[16] = lw_(R[29] + 16);  /* 0x800D1864 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D1868 jr ra */
}

void g0_800D1820(void) {
    R[2] = 0x8014u << 16;  /* 0x800D1820 */
    sw_(R[2] + 15148, R[0]);  /* 0x800D1824 */
    R[4] = 0x800Fu << 16;  /* 0x800D1828 */
    R[4] = R[4] + 480;  /* 0x800D182C */
    R[2] = R[17] << 2;  /* 0x800D1830 */
    R[3] = R[18] << 1;  /* 0x800D1834 */
    R[2] = R[2] + R[3];  /* 0x800D1838 */
    R[2] = R[2] + R[16];  /* 0x800D183C */
    R[2] = R[2] << 2;  /* 0x800D1840 */
    R[2] = R[2] + R[4];  /* 0x800D1844 */
    R[2] = lw_(R[2]);  /* 0x800D1848 */
    { uint32_t _t = R[2]; R[31] = 0x800D1858u; psx_next = _t; return; }  /* 0x800D1850 jalr */
    R[31] = lw_(R[29] + 28);  /* 0x800D1858 */
    R[18] = lw_(R[29] + 24);  /* 0x800D185C */
    R[17] = lw_(R[29] + 20);  /* 0x800D1860 */
    R[16] = lw_(R[29] + 16);  /* 0x800D1864 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D1868 jr ra */
}

void g0_800D1858(void) {
    R[31] = lw_(R[29] + 28);  /* 0x800D1858 */
    R[18] = lw_(R[29] + 24);  /* 0x800D185C */
    R[17] = lw_(R[29] + 20);  /* 0x800D1860 */
    R[16] = lw_(R[29] + 16);  /* 0x800D1864 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D1868 jr ra */
}

void g0_800D1870(void) {
    R[2] = 0x8014u << 16;  /* 0x800D1870 */
    { sh_(R[2] + 19768, R[0]); psx_next = R[31]; return; }  /* 0x800D1874 jr ra */
}

void g0_800D187C(void) {
    R[29] = R[29] - 32;  /* 0x800D187C */
    R[3] = 0x8014u << 16;  /* 0x800D1880 */
    sw_(R[29] + 24, R[16]);  /* 0x800D1884 */
    R[16] = R[3] + 19768;  /* 0x800D1888 */
    sw_(R[29] + 28, R[31]);  /* 0x800D188C */
    sw_(R[16] + 8, R[5]);  /* 0x800D1890 */
    R[5] = 0x800Fu << 16;  /* 0x800D1894 */
    R[5] = R[5] - 516;  /* 0x800D1898 */
    R[2] = R[0] + 1;  /* 0x800D189C */
    sw_(R[16] + 4, R[4]);  /* 0x800D18A0 */
    sh_(R[3] + 19768, R[2]);  /* 0x800D18A4 */
    R[2] = R[0] + 64;  /* 0x800D18A8 */
    sb_(R[16] + 2, R[6]);  /* 0x800D18AC */
    R[6] = 0x800Fu << 16;  /* 0x800D18B0 */
    R[6] = R[6] - 512;  /* 0x800D18B4 */
    sb_(R[16] + 3, R[7]);  /* 0x800D18B8 */
    R[7] = R[0] + R[0];  /* 0x800D18BC */
    { R[31] = 0x800D18C8u; sw_(R[29] + 16, R[2]); psx_next = 0x80022730u; return; }  /* 0x800D18C0 jal */
    R[4] = lw_(R[16] + 8);  /* 0x800D18C8 */
    { R[31] = 0x800D18D4u; R[5] = R[0] + 32; psx_next = 0x80024FA4u; return; }  /* 0x800D18CC jal */
    R[5] = R[16] + 12;  /* 0x800D18D4 */
    R[3] = R[16] + 140;  /* 0x800D18D8 */
    R[4] = R[0] + R[0];  /* 0x800D18DC */
    R[16] = R[16] + 154;  /* 0x800D18E0 */
L_800D18E4:;
    sh_(R[3], R[0]);  /* 0x800D18E4 */
    sh_(R[16] + -8, R[0]);  /* 0x800D18E8 */
    sh_(R[16] + -10, R[0]);  /* 0x800D18EC */
    sh_(R[16] + -2, R[0]);  /* 0x800D18F0 */
    sh_(R[16] + -4, R[0]);  /* 0x800D18F4 */
    sh_(R[16] + -6, R[0]);  /* 0x800D18F8 */
    sh_(R[16] + 2, R[0]);  /* 0x800D18FC */
    sh_(R[16], R[0]);  /* 0x800D1900 */
    R[16] = R[16] + 28;  /* 0x800D1904 */
    sw_(R[5], R[3]);  /* 0x800D1908 */
    R[3] = R[3] + 28;  /* 0x800D190C */
    R[4] = R[4] + 1;  /* 0x800D1910 */
    R[2] = ((int32_t)R[4] < 8);  /* 0x800D1914 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[5] + 4; if (_c) { psx_bb(); goto L_800D18E4; } }  /* 0x800D1918 */
    R[31] = lw_(R[29] + 28);  /* 0x800D1920 */
    R[16] = lw_(R[29] + 24);  /* 0x800D1924 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D1928 jr ra */
}

void g0_800D18C8(void) {
    R[4] = lw_(R[16] + 8);  /* 0x800D18C8 */
    { R[31] = 0x800D18D4u; R[5] = R[0] + 32; psx_next = 0x80024FA4u; return; }  /* 0x800D18CC jal */
    R[5] = R[16] + 12;  /* 0x800D18D4 */
    R[3] = R[16] + 140;  /* 0x800D18D8 */
    R[4] = R[0] + R[0];  /* 0x800D18DC */
    R[16] = R[16] + 154;  /* 0x800D18E0 */
L_800D18E4:;
    sh_(R[3], R[0]);  /* 0x800D18E4 */
    sh_(R[16] + -8, R[0]);  /* 0x800D18E8 */
    sh_(R[16] + -10, R[0]);  /* 0x800D18EC */
    sh_(R[16] + -2, R[0]);  /* 0x800D18F0 */
    sh_(R[16] + -4, R[0]);  /* 0x800D18F4 */
    sh_(R[16] + -6, R[0]);  /* 0x800D18F8 */
    sh_(R[16] + 2, R[0]);  /* 0x800D18FC */
    sh_(R[16], R[0]);  /* 0x800D1900 */
    R[16] = R[16] + 28;  /* 0x800D1904 */
    sw_(R[5], R[3]);  /* 0x800D1908 */
    R[3] = R[3] + 28;  /* 0x800D190C */
    R[4] = R[4] + 1;  /* 0x800D1910 */
    R[2] = ((int32_t)R[4] < 8);  /* 0x800D1914 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[5] + 4; if (_c) { psx_bb(); goto L_800D18E4; } }  /* 0x800D1918 */
    R[31] = lw_(R[29] + 28);  /* 0x800D1920 */
    R[16] = lw_(R[29] + 24);  /* 0x800D1924 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D1928 jr ra */
}

void g0_800D18D4(void) {
    R[5] = R[16] + 12;  /* 0x800D18D4 */
    R[3] = R[16] + 140;  /* 0x800D18D8 */
    R[4] = R[0] + R[0];  /* 0x800D18DC */
    R[16] = R[16] + 154;  /* 0x800D18E0 */
L_800D18E4:;
    sh_(R[3], R[0]);  /* 0x800D18E4 */
    sh_(R[16] + -8, R[0]);  /* 0x800D18E8 */
    sh_(R[16] + -10, R[0]);  /* 0x800D18EC */
    sh_(R[16] + -2, R[0]);  /* 0x800D18F0 */
    sh_(R[16] + -4, R[0]);  /* 0x800D18F4 */
    sh_(R[16] + -6, R[0]);  /* 0x800D18F8 */
    sh_(R[16] + 2, R[0]);  /* 0x800D18FC */
    sh_(R[16], R[0]);  /* 0x800D1900 */
    R[16] = R[16] + 28;  /* 0x800D1904 */
    sw_(R[5], R[3]);  /* 0x800D1908 */
    R[3] = R[3] + 28;  /* 0x800D190C */
    R[4] = R[4] + 1;  /* 0x800D1910 */
    R[2] = ((int32_t)R[4] < 8);  /* 0x800D1914 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[5] + 4; if (_c) { psx_bb(); goto L_800D18E4; } }  /* 0x800D1918 */
    R[31] = lw_(R[29] + 28);  /* 0x800D1920 */
    R[16] = lw_(R[29] + 24);  /* 0x800D1924 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D1928 jr ra */
}

void g0_800D1930(void) {
    R[29] = R[29] - 40;  /* 0x800D1930 */
    sw_(R[29] + 32, R[20]);  /* 0x800D1934 */
    R[20] = R[4] + R[0];  /* 0x800D1938 */
    R[5] = 0x8014u << 16;  /* 0x800D193C */
    sw_(R[29] + 28, R[19]);  /* 0x800D1940 */
    R[19] = R[5] + 19768;  /* 0x800D1944 */
    sw_(R[29] + 16, R[16]);  /* 0x800D1948 */
    R[16] = R[0] + R[0];  /* 0x800D194C */
    sw_(R[29] + 36, R[31]);  /* 0x800D1950 */
    sw_(R[29] + 24, R[18]);  /* 0x800D1954 */
    sw_(R[29] + 20, R[17]);  /* 0x800D1958 */
    R[2] = lb_(R[19] + 2);  /* 0x800D195C */
    R[4] = lw_(R[19] + 8);  /* 0x800D1960 */
    R[2] = R[2] << 2;  /* 0x800D1964 */
    R[3] = R[2] + 12;  /* 0x800D1968 */
    R[18] = R[3] + R[19];  /* 0x800D196C */
    R[17] = R[4] + R[2];  /* 0x800D1970 */
    R[2] = lh_(R[5] + 19768);  /* 0x800D1974 */
    R[3] = lb_(R[19] + 3);  /* 0x800D1978 */
    R[2] = R[2] | 0x2;  /* 0x800D197C */
    { uint32_t _c = (R[3] == R[0]); sh_(R[5] + 19768, R[2]); if (_c) { goto L_800D19B4; } }  /* 0x800D1980 */
L_800D1988:;
    R[4] = lw_(R[18]);  /* 0x800D1988 */
    R[18] = R[18] + 4;  /* 0x800D198C */
    R[5] = lw_(R[17]);  /* 0x800D1990 */
    R[17] = R[17] + 4;  /* 0x800D1994 */
    { R[31] = 0x800D19A0u; R[6] = R[20] + R[0]; psx_next = 0x80024FDCu; return; }  /* 0x800D1998 jal */
    R[2] = lb_(R[19] + 3);  /* 0x800D19A0 */
    R[16] = R[16] + 1;  /* 0x800D19A4 */
    R[2] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800D19A8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_bb(); goto L_800D1988; } }  /* 0x800D19AC */
L_800D19B4:;
    R[31] = lw_(R[29] + 36);  /* 0x800D19B4 */
    R[20] = lw_(R[29] + 32);  /* 0x800D19B8 */
    R[19] = lw_(R[29] + 28);  /* 0x800D19BC */
    R[18] = lw_(R[29] + 24);  /* 0x800D19C0 */
    R[17] = lw_(R[29] + 20);  /* 0x800D19C4 */
    R[16] = lw_(R[29] + 16);  /* 0x800D19C8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D19CC jr ra */
}

void g0_800D1988(void) {
L_800D1988:;
    R[4] = lw_(R[18]);  /* 0x800D1988 */
    R[18] = R[18] + 4;  /* 0x800D198C */
    R[5] = lw_(R[17]);  /* 0x800D1990 */
    R[17] = R[17] + 4;  /* 0x800D1994 */
    { R[31] = 0x800D19A0u; R[6] = R[20] + R[0]; psx_next = 0x80024FDCu; return; }  /* 0x800D1998 jal */
    R[2] = lb_(R[19] + 3);  /* 0x800D19A0 */
    R[16] = R[16] + 1;  /* 0x800D19A4 */
    R[2] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800D19A8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_bb(); goto L_800D1988; } }  /* 0x800D19AC */
    R[31] = lw_(R[29] + 36);  /* 0x800D19B4 */
    R[20] = lw_(R[29] + 32);  /* 0x800D19B8 */
    R[19] = lw_(R[29] + 28);  /* 0x800D19BC */
    R[18] = lw_(R[29] + 24);  /* 0x800D19C0 */
    R[17] = lw_(R[29] + 20);  /* 0x800D19C4 */
    R[16] = lw_(R[29] + 16);  /* 0x800D19C8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D19CC jr ra */
}

void g0_800D19A0(void) {
    R[2] = lb_(R[19] + 3);  /* 0x800D19A0 */
    R[16] = R[16] + 1;  /* 0x800D19A4 */
    R[2] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800D19A8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x800D1988u; return; } }  /* 0x800D19AC b extern */
    R[31] = lw_(R[29] + 36);  /* 0x800D19B4 */
    R[20] = lw_(R[29] + 32);  /* 0x800D19B8 */
    R[19] = lw_(R[29] + 28);  /* 0x800D19BC */
    R[18] = lw_(R[29] + 24);  /* 0x800D19C0 */
    R[17] = lw_(R[29] + 20);  /* 0x800D19C4 */
    R[16] = lw_(R[29] + 16);  /* 0x800D19C8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D19CC jr ra */
}

void g0_800D19D4(void) {
    R[3] = 0x8014u << 16;  /* 0x800D19D4 */
    R[2] = lh_(R[3] + 19768);  /* 0x800D19D8 */
    psx_next = 0x800D19DCu; return;  /* fallthrough */
}

void g0_800D19DC(void) {
    R[29] = R[29] - 32;  /* 0x800D19DC */
    sw_(R[29] + 24, R[18]);  /* 0x800D19E0 */
    R[18] = R[3] + 19768;  /* 0x800D19E4 */
    sw_(R[29] + 28, R[31]);  /* 0x800D19E8 */
    sw_(R[29] + 20, R[17]);  /* 0x800D19EC */
    R[2] = R[2] & 0x1;  /* 0x800D19F0 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[29] + 16, R[16]); if (_c) { goto L_800D1A38; } }  /* 0x800D19F4 */
    R[16] = R[0] + R[0];  /* 0x800D19FC */
    R[2] = lb_(R[18] + 2);  /* 0x800D1A00 */
    R[3] = lb_(R[18] + 3);  /* 0x800D1A04 */
    R[2] = R[2] << 2;  /* 0x800D1A08 */
    R[2] = R[2] + 12;  /* 0x800D1A0C */
    { uint32_t _c = (R[3] == R[0]); R[17] = R[2] + R[18]; if (_c) { goto L_800D1A38; } }  /* 0x800D1A10 */
L_800D1A18:;
    R[4] = lw_(R[17]);  /* 0x800D1A18 */
    { R[31] = 0x800D1A24u; R[17] = R[17] + 4; psx_next = 0x8002508Cu; return; }  /* 0x800D1A1C jal */
    R[2] = lb_(R[18] + 3);  /* 0x800D1A24 */
    R[16] = R[16] + 1;  /* 0x800D1A28 */
    R[2] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800D1A2C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_bb(); goto L_800D1A18; } }  /* 0x800D1A30 */
L_800D1A38:;
    R[31] = lw_(R[29] + 28);  /* 0x800D1A38 */
    R[18] = lw_(R[29] + 24);  /* 0x800D1A3C */
    R[17] = lw_(R[29] + 20);  /* 0x800D1A40 */
    R[16] = lw_(R[29] + 16);  /* 0x800D1A44 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D1A48 jr ra */
}

void g0_800D1A18(void) {
L_800D1A18:;
    R[4] = lw_(R[17]);  /* 0x800D1A18 */
    { R[31] = 0x800D1A24u; R[17] = R[17] + 4; psx_next = 0x8002508Cu; return; }  /* 0x800D1A1C jal */
    R[2] = lb_(R[18] + 3);  /* 0x800D1A24 */
    R[16] = R[16] + 1;  /* 0x800D1A28 */
    R[2] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800D1A2C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_bb(); goto L_800D1A18; } }  /* 0x800D1A30 */
    R[31] = lw_(R[29] + 28);  /* 0x800D1A38 */
    R[18] = lw_(R[29] + 24);  /* 0x800D1A3C */
    R[17] = lw_(R[29] + 20);  /* 0x800D1A40 */
    R[16] = lw_(R[29] + 16);  /* 0x800D1A44 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D1A48 jr ra */
}

void g0_800D1A24(void) {
    R[2] = lb_(R[18] + 3);  /* 0x800D1A24 */
    R[16] = R[16] + 1;  /* 0x800D1A28 */
    R[2] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800D1A2C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x800D1A18u; return; } }  /* 0x800D1A30 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x800D1A38 */
    R[18] = lw_(R[29] + 24);  /* 0x800D1A3C */
    R[17] = lw_(R[29] + 20);  /* 0x800D1A40 */
    R[16] = lw_(R[29] + 16);  /* 0x800D1A44 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800D1A48 jr ra */
}

void g0_800D1A50(void) {
    R[29] = R[29] - 40;  /* 0x800D1A50 */
    sw_(R[29] + 28, R[17]);  /* 0x800D1A54 */
    R[17] = R[6] + R[0];  /* 0x800D1A58 */
    sw_(R[29] + 32, R[18]);  /* 0x800D1A5C */
    R[18] = R[7] + R[0];  /* 0x800D1A60 */
    R[3] = R[4] << 1;  /* 0x800D1A64 */
    R[3] = R[3] + R[4];  /* 0x800D1A68 */
    R[3] = R[3] << 2;  /* 0x800D1A6C */
    R[2] = 0x8014u << 16;  /* 0x800D1A70 */
    R[2] = R[2] + 20136;  /* 0x800D1A74 */
    sw_(R[29] + 24, R[16]);  /* 0x800D1A78 */
    R[16] = R[3] + R[2];  /* 0x800D1A7C */
    sw_(R[29] + 36, R[31]);  /* 0x800D1A80 */
    sw_(R[16], R[5]);  /* 0x800D1A84 */
    R[5] = 0x800Fu << 16;  /* 0x800D1A88 */
    R[5] = R[5] - 296;  /* 0x800D1A8C */
    R[6] = 0x800Fu << 16;  /* 0x800D1A90 */
    R[6] = R[6] - 292;  /* 0x800D1A94 */
    sw_(R[29] + 16, R[0]);  /* 0x800D1A98 */
    R[4] = lw_(R[16]);  /* 0x800D1A9C */
    { R[31] = 0x800D1AA8u; R[7] = R[0] + R[0]; psx_next = 0x8002492Cu; return; }  /* 0x800D1AA0 jal */
    { uint32_t _c = (R[17] == R[0]); sw_(R[16] + 4, R[17]); if (_c) { goto L_800D1AB8; } }  /* 0x800D1AA8 */
    { R[31] = 0x800D1AB8u; R[4] = R[17] + R[0]; psx_next = 0x80024F10u; return; }  /* 0x800D1AB0 jal */
L_800D1AB8:;
    { uint32_t _c = (R[18] == R[0]); sw_(R[16] + 8, R[18]); if (_c) { goto L_800D1ACC; } }  /* 0x800D1AB8 */
    R[4] = R[18] + R[0];  /* 0x800D1AC0 */
    { R[31] = 0x800D1ACCu; R[5] = R[0] + 32; psx_next = 0x80024FA4u; return; }  /* 0x800D1AC4 jal */
L_800D1ACC:;
    R[31] = lw_(R[29] + 36);  /* 0x800D1ACC */
    R[18] = lw_(R[29] + 32);  /* 0x800D1AD0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D1AD4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D1AD8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D1ADC jr ra */
}

void g0_800D1AA8(void) {
    { uint32_t _c = (R[17] == R[0]); sw_(R[16] + 4, R[17]); if (_c) { goto L_800D1AB8; } }  /* 0x800D1AA8 */
    { R[31] = 0x800D1AB8u; R[4] = R[17] + R[0]; psx_next = 0x80024F10u; return; }  /* 0x800D1AB0 jal */
L_800D1AB8:;
    { uint32_t _c = (R[18] == R[0]); sw_(R[16] + 8, R[18]); if (_c) { goto L_800D1ACC; } }  /* 0x800D1AB8 */
    R[4] = R[18] + R[0];  /* 0x800D1AC0 */
    { R[31] = 0x800D1ACCu; R[5] = R[0] + 32; psx_next = 0x80024FA4u; return; }  /* 0x800D1AC4 jal */
L_800D1ACC:;
    R[31] = lw_(R[29] + 36);  /* 0x800D1ACC */
    R[18] = lw_(R[29] + 32);  /* 0x800D1AD0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D1AD4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D1AD8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D1ADC jr ra */
}

void g0_800D1AB8(void) {
    { uint32_t _c = (R[18] == R[0]); sw_(R[16] + 8, R[18]); if (_c) { goto L_800D1ACC; } }  /* 0x800D1AB8 */
    R[4] = R[18] + R[0];  /* 0x800D1AC0 */
    { R[31] = 0x800D1ACCu; R[5] = R[0] + 32; psx_next = 0x80024FA4u; return; }  /* 0x800D1AC4 jal */
L_800D1ACC:;
    R[31] = lw_(R[29] + 36);  /* 0x800D1ACC */
    R[18] = lw_(R[29] + 32);  /* 0x800D1AD0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D1AD4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D1AD8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D1ADC jr ra */
}

void g0_800D1ACC(void) {
    R[31] = lw_(R[29] + 36);  /* 0x800D1ACC */
    R[18] = lw_(R[29] + 32);  /* 0x800D1AD0 */
    R[17] = lw_(R[29] + 28);  /* 0x800D1AD4 */
    R[16] = lw_(R[29] + 24);  /* 0x800D1AD8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800D1ADC jr ra */
}

void g0_800D1AE4(void) {
    R[29] = R[29] - 24;  /* 0x800D1AE4 */
    sw_(R[29] + 20, R[31]);  /* 0x800D1AE8 */
    { R[31] = 0x800D1AF4u; sw_(R[29] + 16, R[16]); psx_next = 0x80023DC4u; return; }  /* 0x800D1AEC jal */
    R[16] = R[2] + R[0];  /* 0x800D1AF4 */
    { uint32_t _c = ((int32_t)R[16] < 0); if (_c) { goto L_800D1B38; } }  /* 0x800D1AF8 */
    { R[31] = 0x800D1B08u; R[4] = R[16] + R[0]; psx_next = 0x80023E24u; return; }  /* 0x800D1B00 jal */
    R[2] = R[2] - 1;  /* 0x800D1B08 */
    R[2] = R[2] & 0x1;  /* 0x800D1B0C */
    R[3] = R[16] - 23;  /* 0x800D1B10 */
    R[3] = R[3] << 1;  /* 0x800D1B14 */
    R[3] = R[3] + R[2];  /* 0x800D1B18 */
    R[2] = 0x800Fu << 16;  /* 0x800D1B1C */
    R[2] = R[2] - 568;  /* 0x800D1B20 */
    R[3] = R[3] << 2;  /* 0x800D1B24 */
    R[3] = R[3] + R[2];  /* 0x800D1B28 */
    R[4] = lw_(R[3]);  /* 0x800D1B2C */
    { R[31] = 0x800D1B38u; psx_next = 0x800302E4u; return; }  /* 0x800D1B30 jal */
L_800D1B38:;
    R[31] = lw_(R[29] + 20);  /* 0x800D1B38 */
    R[16] = lw_(R[29] + 16);  /* 0x800D1B3C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800D1B40 jr ra */
}
