#include "game00_decls.h"

void g0_8009ECFC(void) {
    R[2] = lw_(R[16] + 72);  /* 0x8009ECFC */
    R[2] = lh_(R[2]);  /* 0x8009ED04 */
    R[2] = R[2] >> 13;  /* 0x8009ED0C */
    R[2] = R[2] & 0x1;  /* 0x8009ED10 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009ED30; } }  /* 0x8009ED14 */
    R[5] = (uint32_t)(int16_t)lh_(R[2] + -29650);  /* 0x8009ED1C */
    { R[31] = 0x8009ED28u; R[4] = R[16] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009ED20 jal */
    { R[31] = 0x8009ED30u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009ED28 jal */
L_8009ED30:;
    R[31] = lw_(R[29] + 20);  /* 0x8009ED30 */
    R[16] = lw_(R[29] + 16);  /* 0x8009ED34 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009ED38 jr ra */
}

void g0_8009ED28(void) {
    { R[31] = 0x8009ED30u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009ED28 jal */
    R[31] = lw_(R[29] + 20);  /* 0x8009ED30 */
    R[16] = lw_(R[29] + 16);  /* 0x8009ED34 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009ED38 jr ra */
}

void g0_8009ED30(void) {
    R[31] = lw_(R[29] + 20);  /* 0x8009ED30 */
    R[16] = lw_(R[29] + 16);  /* 0x8009ED34 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009ED38 jr ra */
}

void g0_8009ED40(void) {
    R[29] = R[29] - 24;  /* 0x8009ED40 */
    sw_(R[29] + 16, R[16]);  /* 0x8009ED44 */
    sw_(R[29] + 20, R[31]);  /* 0x8009ED48 */
    { R[31] = 0x8009ED54u; R[16] = R[4] + R[0]; psx_next = 0x8009D8D0u; return; }  /* 0x8009ED4C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009EDF0; } }  /* 0x8009ED54 */
    R[2] = lw_(R[16] + 72);  /* 0x8009ED5C */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x8009ED64 */
    R[2] = R[0] + 1;  /* 0x8009ED68 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009ED88; } }  /* 0x8009ED6C */
    { R[31] = 0x8009ED7Cu; psx_next = 0x8009BCE8u; return; }  /* 0x8009ED74 jal */
    R[4] = R[16] + R[0];  /* 0x8009ED7C */
    { R[31] = 0x8009ED88u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009ED80 jal */
L_8009ED88:;
    R[2] = lb_(R[16] + 784);  /* 0x8009ED88 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009EDBC; } }  /* 0x8009ED90 */
    { R[31] = 0x8009EDA0u; R[4] = R[0] + 8; psx_next = 0x8009DCB0u; return; }  /* 0x8009ED98 jal */
    R[4] = R[16] + R[0];  /* 0x8009EDA0 */
    R[5] = R[2] + R[0];  /* 0x8009EDA4 */
    R[6] = R[0] + R[0];  /* 0x8009EDA8 */
    { R[31] = 0x8009EDB4u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009EDAC jal */
    { goto L_8009EDE8; }  /* 0x8009EDB4 j */
L_8009EDBC:;
    R[2] = lw_(R[16] + 72);  /* 0x8009EDBC */
    R[2] = lh_(R[2]);  /* 0x8009EDC4 */
    R[2] = R[2] >> 13;  /* 0x8009EDCC */
    R[2] = R[2] & 0x1;  /* 0x8009EDD0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009EDF0; } }  /* 0x8009EDD4 */
    R[5] = (uint32_t)(int16_t)lh_(R[2] + -29650);  /* 0x8009EDDC */
    { R[31] = 0x8009EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EDE0 jal */
L_8009EDE8:;
    { R[31] = 0x8009EDF0u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EDE8 jal */
L_8009EDF0:;
    R[31] = lw_(R[29] + 20);  /* 0x8009EDF0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EDF4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009EDF8 jr ra */
}

void g0_8009ED54(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009EDF0; } }  /* 0x8009ED54 */
    R[2] = lw_(R[16] + 72);  /* 0x8009ED5C */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x8009ED64 */
    R[2] = R[0] + 1;  /* 0x8009ED68 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009ED88; } }  /* 0x8009ED6C */
    { R[31] = 0x8009ED7Cu; psx_next = 0x8009BCE8u; return; }  /* 0x8009ED74 jal */
    R[4] = R[16] + R[0];  /* 0x8009ED7C */
    { R[31] = 0x8009ED88u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009ED80 jal */
L_8009ED88:;
    R[2] = lb_(R[16] + 784);  /* 0x8009ED88 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009EDBC; } }  /* 0x8009ED90 */
    { R[31] = 0x8009EDA0u; R[4] = R[0] + 8; psx_next = 0x8009DCB0u; return; }  /* 0x8009ED98 jal */
    R[4] = R[16] + R[0];  /* 0x8009EDA0 */
    R[5] = R[2] + R[0];  /* 0x8009EDA4 */
    R[6] = R[0] + R[0];  /* 0x8009EDA8 */
    { R[31] = 0x8009EDB4u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009EDAC jal */
    { goto L_8009EDE8; }  /* 0x8009EDB4 j */
L_8009EDBC:;
    R[2] = lw_(R[16] + 72);  /* 0x8009EDBC */
    R[2] = lh_(R[2]);  /* 0x8009EDC4 */
    R[2] = R[2] >> 13;  /* 0x8009EDCC */
    R[2] = R[2] & 0x1;  /* 0x8009EDD0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009EDF0; } }  /* 0x8009EDD4 */
    R[5] = (uint32_t)(int16_t)lh_(R[2] + -29650);  /* 0x8009EDDC */
    { R[31] = 0x8009EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EDE0 jal */
L_8009EDE8:;
    { R[31] = 0x8009EDF0u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EDE8 jal */
L_8009EDF0:;
    R[31] = lw_(R[29] + 20);  /* 0x8009EDF0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EDF4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009EDF8 jr ra */
}

void g0_8009ED7C(void) {
    R[4] = R[16] + R[0];  /* 0x8009ED7C */
    { R[31] = 0x8009ED88u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009ED80 jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009ED88 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009EDBC; } }  /* 0x8009ED90 */
    { R[31] = 0x8009EDA0u; R[4] = R[0] + 8; psx_next = 0x8009DCB0u; return; }  /* 0x8009ED98 jal */
    R[4] = R[16] + R[0];  /* 0x8009EDA0 */
    R[5] = R[2] + R[0];  /* 0x8009EDA4 */
    R[6] = R[0] + R[0];  /* 0x8009EDA8 */
    { R[31] = 0x8009EDB4u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009EDAC jal */
    { goto L_8009EDE8; }  /* 0x8009EDB4 j */
L_8009EDBC:;
    R[2] = lw_(R[16] + 72);  /* 0x8009EDBC */
    R[2] = lh_(R[2]);  /* 0x8009EDC4 */
    R[2] = R[2] >> 13;  /* 0x8009EDCC */
    R[2] = R[2] & 0x1;  /* 0x8009EDD0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009EDF0; } }  /* 0x8009EDD4 */
    R[5] = (uint32_t)(int16_t)lh_(R[2] + -29650);  /* 0x8009EDDC */
    { R[31] = 0x8009EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EDE0 jal */
L_8009EDE8:;
    { R[31] = 0x8009EDF0u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EDE8 jal */
L_8009EDF0:;
    R[31] = lw_(R[29] + 20);  /* 0x8009EDF0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EDF4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009EDF8 jr ra */
}

void g0_8009ED88(void) {
    R[2] = lb_(R[16] + 784);  /* 0x8009ED88 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009EDBC; } }  /* 0x8009ED90 */
    { R[31] = 0x8009EDA0u; R[4] = R[0] + 8; psx_next = 0x8009DCB0u; return; }  /* 0x8009ED98 jal */
    R[4] = R[16] + R[0];  /* 0x8009EDA0 */
    R[5] = R[2] + R[0];  /* 0x8009EDA4 */
    R[6] = R[0] + R[0];  /* 0x8009EDA8 */
    { R[31] = 0x8009EDB4u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009EDAC jal */
    { goto L_8009EDE8; }  /* 0x8009EDB4 j */
L_8009EDBC:;
    R[2] = lw_(R[16] + 72);  /* 0x8009EDBC */
    R[2] = lh_(R[2]);  /* 0x8009EDC4 */
    R[2] = R[2] >> 13;  /* 0x8009EDCC */
    R[2] = R[2] & 0x1;  /* 0x8009EDD0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009EDF0; } }  /* 0x8009EDD4 */
    R[5] = (uint32_t)(int16_t)lh_(R[2] + -29650);  /* 0x8009EDDC */
    { R[31] = 0x8009EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EDE0 jal */
L_8009EDE8:;
    { R[31] = 0x8009EDF0u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EDE8 jal */
L_8009EDF0:;
    R[31] = lw_(R[29] + 20);  /* 0x8009EDF0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EDF4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009EDF8 jr ra */
}

void g0_8009EDA0(void) {
    R[4] = R[16] + R[0];  /* 0x8009EDA0 */
    R[5] = R[2] + R[0];  /* 0x8009EDA4 */
    R[6] = R[0] + R[0];  /* 0x8009EDA8 */
    { R[31] = 0x8009EDB4u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009EDAC jal */
    { goto L_8009EDE8; }  /* 0x8009EDB4 j */
    R[2] = lw_(R[16] + 72);  /* 0x8009EDBC */
    R[2] = lh_(R[2]);  /* 0x8009EDC4 */
    R[2] = R[2] >> 13;  /* 0x8009EDCC */
    R[2] = R[2] & 0x1;  /* 0x8009EDD0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009EDF0; } }  /* 0x8009EDD4 */
    R[5] = (uint32_t)(int16_t)lh_(R[2] + -29650);  /* 0x8009EDDC */
    { R[31] = 0x8009EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EDE0 jal */
L_8009EDE8:;
    { R[31] = 0x8009EDF0u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EDE8 jal */
L_8009EDF0:;
    R[31] = lw_(R[29] + 20);  /* 0x8009EDF0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EDF4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009EDF8 jr ra */
}

void g0_8009EDB4(void) {
    { goto L_8009EDE8; }  /* 0x8009EDB4 j */
    R[2] = lw_(R[16] + 72);  /* 0x8009EDBC */
    R[2] = lh_(R[2]);  /* 0x8009EDC4 */
    R[2] = R[2] >> 13;  /* 0x8009EDCC */
    R[2] = R[2] & 0x1;  /* 0x8009EDD0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009EDF0; } }  /* 0x8009EDD4 */
    R[5] = (uint32_t)(int16_t)lh_(R[2] + -29650);  /* 0x8009EDDC */
    { R[31] = 0x8009EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EDE0 jal */
L_8009EDE8:;
    { R[31] = 0x8009EDF0u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EDE8 jal */
L_8009EDF0:;
    R[31] = lw_(R[29] + 20);  /* 0x8009EDF0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EDF4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009EDF8 jr ra */
}

void g0_8009EDE8(void) {
    { R[31] = 0x8009EDF0u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EDE8 jal */
    R[31] = lw_(R[29] + 20);  /* 0x8009EDF0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EDF4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009EDF8 jr ra */
}

void g0_8009EDF0(void) {
    R[31] = lw_(R[29] + 20);  /* 0x8009EDF0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EDF4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009EDF8 jr ra */
}

void g0_8009EE00(void) {
    R[29] = R[29] - 40;  /* 0x8009EE00 */
    sw_(R[29] + 24, R[16]);  /* 0x8009EE04 */
    R[16] = R[4] + R[0];  /* 0x8009EE08 */
    psx_next = 0x8009EE0Cu; return;  /* fallthrough */
}

void g0_8009EE0C(void) {
    sw_(R[29] + 32, R[31]);  /* 0x8009EE0C */
    sw_(R[29] + 28, R[17]);  /* 0x8009EE10 */
    R[2] = lw_(R[16] + 72);  /* 0x8009EE14 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x8009EE1C */
    R[2] = R[0] + 20;  /* 0x8009EE20 */
    { uint32_t _c = (R[3] != R[2]); R[17] = R[3] + R[0]; if (_c) { goto L_8009EE30; } }  /* 0x8009EE24 */
    sw_(R[16] + 124, R[0]);  /* 0x8009EE2C */
L_8009EE30:;
    R[2] = R[0] + 1;  /* 0x8009EE30 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[17] - 4; if (_c) { goto L_8009EE54; } }  /* 0x8009EE34 */
    { R[31] = 0x8009EE44u; psx_next = 0x8009BCE8u; return; }  /* 0x8009EE3C jal */
    R[4] = R[16] + R[0];  /* 0x8009EE44 */
    { R[31] = 0x8009EE50u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EE48 jal */
    R[2] = R[17] - 4;  /* 0x8009EE50 */
L_8009EE54:;
    R[2] = (R[2] < (uint32_t)12u);  /* 0x8009EE54 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[17] & 0x1; if (_c) { goto L_8009EE90; } }  /* 0x8009EE58 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009EE90; } }  /* 0x8009EE60 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 4);  /* 0x8009EE68 */
    R[2] = R[2] - 256;  /* 0x8009EE70 */
    R[2] = R[2] & 0x1FF;  /* 0x8009EE74 */
    sw_(R[29] + 16, R[2]);  /* 0x8009EE78 */
    R[5] = lw_(R[16] + 24);  /* 0x8009EE7C */
    R[6] = lw_(R[16] + 28);  /* 0x8009EE80 */
    R[7] = lw_(R[16] + 32);  /* 0x8009EE84 */
    { R[31] = 0x8009EE90u; R[4] = R[0] + 7; psx_next = 0x800A7290u; return; }  /* 0x8009EE88 jal */
L_8009EE90:;
    R[2] = lw_(R[16] + 72);  /* 0x8009EE90 */
    R[2] = lh_(R[2]);  /* 0x8009EE98 */
    R[2] = R[2] >> 13;  /* 0x8009EEA0 */
    R[2] = R[2] & 0x1;  /* 0x8009EEA4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009EEC4u; return; } }  /* 0x8009EEA8 b extern */
    R[4] = R[16] + R[0];  /* 0x8009EEB0 */
    { R[31] = 0x8009EEBCu; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EEB4 jal */
    { R[31] = 0x8009EEC4u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EEBC jal */
}

void g0_8009EE44(void) {
    R[4] = R[16] + R[0];  /* 0x8009EE44 */
    { R[31] = 0x8009EE50u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EE48 jal */
    R[2] = R[17] - 4;  /* 0x8009EE50 */
    R[2] = (R[2] < (uint32_t)12u);  /* 0x8009EE54 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[17] & 0x1; if (_c) { goto L_8009EE90; } }  /* 0x8009EE58 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009EE90; } }  /* 0x8009EE60 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 4);  /* 0x8009EE68 */
    R[2] = R[2] - 256;  /* 0x8009EE70 */
    R[2] = R[2] & 0x1FF;  /* 0x8009EE74 */
    sw_(R[29] + 16, R[2]);  /* 0x8009EE78 */
    R[5] = lw_(R[16] + 24);  /* 0x8009EE7C */
    R[6] = lw_(R[16] + 28);  /* 0x8009EE80 */
    R[7] = lw_(R[16] + 32);  /* 0x8009EE84 */
    { R[31] = 0x8009EE90u; R[4] = R[0] + 7; psx_next = 0x800A7290u; return; }  /* 0x8009EE88 jal */
L_8009EE90:;
    R[2] = lw_(R[16] + 72);  /* 0x8009EE90 */
    R[2] = lh_(R[2]);  /* 0x8009EE98 */
    R[2] = R[2] >> 13;  /* 0x8009EEA0 */
    R[2] = R[2] & 0x1;  /* 0x8009EEA4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009EEC4u; return; } }  /* 0x8009EEA8 b extern */
    R[4] = R[16] + R[0];  /* 0x8009EEB0 */
    { R[31] = 0x8009EEBCu; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EEB4 jal */
    { R[31] = 0x8009EEC4u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EEBC jal */
}

void g0_8009EE50(void) {
    R[2] = R[17] - 4;  /* 0x8009EE50 */
    R[2] = (R[2] < (uint32_t)12u);  /* 0x8009EE54 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[17] & 0x1; if (_c) { goto L_8009EE90; } }  /* 0x8009EE58 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009EE90; } }  /* 0x8009EE60 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 4);  /* 0x8009EE68 */
    R[2] = R[2] - 256;  /* 0x8009EE70 */
    R[2] = R[2] & 0x1FF;  /* 0x8009EE74 */
    sw_(R[29] + 16, R[2]);  /* 0x8009EE78 */
    R[5] = lw_(R[16] + 24);  /* 0x8009EE7C */
    R[6] = lw_(R[16] + 28);  /* 0x8009EE80 */
    R[7] = lw_(R[16] + 32);  /* 0x8009EE84 */
    { R[31] = 0x8009EE90u; R[4] = R[0] + 7; psx_next = 0x800A7290u; return; }  /* 0x8009EE88 jal */
L_8009EE90:;
    R[2] = lw_(R[16] + 72);  /* 0x8009EE90 */
    R[2] = lh_(R[2]);  /* 0x8009EE98 */
    R[2] = R[2] >> 13;  /* 0x8009EEA0 */
    R[2] = R[2] & 0x1;  /* 0x8009EEA4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009EEC4u; return; } }  /* 0x8009EEA8 b extern */
    R[4] = R[16] + R[0];  /* 0x8009EEB0 */
    { R[31] = 0x8009EEBCu; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EEB4 jal */
    { R[31] = 0x8009EEC4u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EEBC jal */
}

void g0_8009EE90(void) {
    R[2] = lw_(R[16] + 72);  /* 0x8009EE90 */
    R[2] = lh_(R[2]);  /* 0x8009EE98 */
    R[2] = R[2] >> 13;  /* 0x8009EEA0 */
    R[2] = R[2] & 0x1;  /* 0x8009EEA4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009EEC4u; return; } }  /* 0x8009EEA8 b extern */
    R[4] = R[16] + R[0];  /* 0x8009EEB0 */
    { R[31] = 0x8009EEBCu; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EEB4 jal */
    { R[31] = 0x8009EEC4u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EEBC jal */
}

void g0_8009EEBC(void) {
    { R[31] = 0x8009EEC4u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EEBC jal */
}

void g0_8009EEC0(void) {
    R[4] = R[16] + R[0];  /* 0x8009EEC0 */
    R[31] = lw_(R[29] + 32);  /* 0x8009EEC4 */
    R[17] = lw_(R[29] + 28);  /* 0x8009EEC8 */
    R[16] = lw_(R[29] + 24);  /* 0x8009EECC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009EED0 jr ra */
}

void g0_8009EEC4(void) {
    R[31] = lw_(R[29] + 32);  /* 0x8009EEC4 */
    R[17] = lw_(R[29] + 28);  /* 0x8009EEC8 */
    R[16] = lw_(R[29] + 24);  /* 0x8009EECC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009EED0 jr ra */
}

void g0_8009EED8(void) {
    R[29] = R[29] - 24;  /* 0x8009EED8 */
    sw_(R[29] + 16, R[16]);  /* 0x8009EEDC */
    R[16] = R[4] + R[0];  /* 0x8009EEE0 */
    R[3] = 0x8013u << 16;  /* 0x8009EEE4 */
    R[2] = R[0] + 4;  /* 0x8009EEE8 */
    sw_(R[29] + 20, R[31]);  /* 0x8009EEEC */
    sh_(R[3] + -29656, R[2]);  /* 0x8009EEF0 */
    R[2] = lw_(R[16] + 72);  /* 0x8009EEF4 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x8009EEFC */
    R[2] = ((int32_t)R[2] < 16);  /* 0x8009EF04 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009EF44; } }  /* 0x8009EF08 */
    R[2] = lh_(R[16] + 784);  /* 0x8009EF10 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009EF44; } }  /* 0x8009EF18 */
    R[2] = lh_(R[16] + 4);  /* 0x8009EF20 */
    { R[31] = 0x8009EF2Cu; sh_(R[16] + 6, R[2]); psx_next = 0x800A9EB4u; return; }  /* 0x8009EF24 jal */
    { R[31] = 0x8009EF34u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009EF2C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EF44; } }  /* 0x8009EF34 */
    { R[31] = 0x8009EF44u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EF3C jal */
L_8009EF44:;
    R[31] = lw_(R[29] + 20);  /* 0x8009EF44 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EF48 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009EF4C jr ra */
}

void g0_8009EF2C(void) {
    { R[31] = 0x8009EF34u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009EF2C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EF44; } }  /* 0x8009EF34 */
    { R[31] = 0x8009EF44u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EF3C jal */
L_8009EF44:;
    R[31] = lw_(R[29] + 20);  /* 0x8009EF44 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EF48 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009EF4C jr ra */
}

void g0_8009EF34(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EF44; } }  /* 0x8009EF34 */
    { R[31] = 0x8009EF44u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EF3C jal */
L_8009EF44:;
    R[31] = lw_(R[29] + 20);  /* 0x8009EF44 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EF48 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009EF4C jr ra */
}

void g0_8009EF44(void) {
    R[31] = lw_(R[29] + 20);  /* 0x8009EF44 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EF48 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009EF4C jr ra */
}

void g0_8009EF54(void) {
    R[29] = R[29] - 32;  /* 0x8009EF54 */
    sw_(R[29] + 16, R[16]);  /* 0x8009EF58 */
    R[16] = R[4] + R[0];  /* 0x8009EF5C */
    R[4] = 0x8013u << 16;  /* 0x8009EF60 */
    R[2] = R[0] + 3;  /* 0x8009EF64 */
    sw_(R[29] + 28, R[31]);  /* 0x8009EF68 */
    sw_(R[29] + 24, R[18]);  /* 0x8009EF6C */
    sw_(R[29] + 20, R[17]);  /* 0x8009EF70 */
    sh_(R[4] + -29656, R[2]);  /* 0x8009EF74 */
    R[2] = lw_(R[16] + 72);  /* 0x8009EF78 */
    R[18] = R[4] - 29656;  /* 0x8009EF7C */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x8009EF80 */
    R[2] = R[0] + 7;  /* 0x8009EF84 */
    { uint32_t _c = (R[3] != R[2]); R[17] = R[3] + R[0]; if (_c) { goto L_8009EFA8; } }  /* 0x8009EF88 */
    R[2] = 0x1u << 16;  /* 0x8009EF90 */
    R[3] = 0x8012u << 16;  /* 0x8009EF94 */
    R[3] = (uint32_t)(int16_t)lh_(R[3] + 30976);  /* 0x8009EF98 */
    R[2] = R[2] | 0x22E5;  /* 0x8009EF9C */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009EFA0 */
    sw_(R[16] + 140, R[2]);  /* 0x8009EFA4 */
L_8009EFA8:;
    R[4] = R[16] + R[0];  /* 0x8009EFA8 */
    { R[31] = 0x8009EFB4u; R[5] = R[17] + R[0]; psx_next = 0x8009EA38u; return; }  /* 0x8009EFAC jal */
    R[2] = R[0] + 10;  /* 0x8009EFB4 */
    { uint32_t _c = (R[17] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009EFFC; } }  /* 0x8009EFB8 */
    R[3] = lb_(R[18] + 30);  /* 0x8009EFC0 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EFFC; } }  /* 0x8009EFC8 */
    { R[31] = 0x8009EFD8u; R[5] = R[0] + 90; psx_next = 0x8009BC84u; return; }  /* 0x8009EFD0 jal */
    R[2] = lb_(R[16] + 781);  /* 0x8009EFD8 */
    R[2] = R[2] | 0x80;  /* 0x8009EFE0 */
    { R[31] = 0x8009EFECu; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009EFE4 jal */
    R[4] = R[16] + R[0];  /* 0x8009EFEC */
    { R[31] = 0x8009EFF8u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EFF0 jal */
    sb_(R[18] + 30, R[0]);  /* 0x8009EFF8 */
L_8009EFFC:;
    R[2] = lw_(R[16] + 72);  /* 0x8009EFFC */
    R[2] = lh_(R[2]);  /* 0x8009F004 */
    R[2] = R[2] >> 13;  /* 0x8009F00C */
    R[2] = R[2] & 0x1;  /* 0x8009F010 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F03C; } }  /* 0x8009F014 */
    { R[31] = 0x8009F024u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009F01C jal */
    { R[31] = 0x8009F02Cu; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009F024 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F03C; } }  /* 0x8009F02C */
    { R[31] = 0x8009F03Cu; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F034 jal */
L_8009F03C:;
    R[31] = lw_(R[29] + 28);  /* 0x8009F03C */
    R[18] = lw_(R[29] + 24);  /* 0x8009F040 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F044 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F048 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F04C jr ra */
}

void g0_8009EFB4(void) {
    R[2] = R[0] + 10;  /* 0x8009EFB4 */
    { uint32_t _c = (R[17] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009EFFC; } }  /* 0x8009EFB8 */
    R[3] = lb_(R[18] + 30);  /* 0x8009EFC0 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EFFC; } }  /* 0x8009EFC8 */
    { R[31] = 0x8009EFD8u; R[5] = R[0] + 90; psx_next = 0x8009BC84u; return; }  /* 0x8009EFD0 jal */
    R[2] = lb_(R[16] + 781);  /* 0x8009EFD8 */
    R[2] = R[2] | 0x80;  /* 0x8009EFE0 */
    { R[31] = 0x8009EFECu; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009EFE4 jal */
    R[4] = R[16] + R[0];  /* 0x8009EFEC */
    { R[31] = 0x8009EFF8u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EFF0 jal */
    sb_(R[18] + 30, R[0]);  /* 0x8009EFF8 */
L_8009EFFC:;
    R[2] = lw_(R[16] + 72);  /* 0x8009EFFC */
    R[2] = lh_(R[2]);  /* 0x8009F004 */
    R[2] = R[2] >> 13;  /* 0x8009F00C */
    R[2] = R[2] & 0x1;  /* 0x8009F010 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F03C; } }  /* 0x8009F014 */
    { R[31] = 0x8009F024u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009F01C jal */
    { R[31] = 0x8009F02Cu; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009F024 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F03C; } }  /* 0x8009F02C */
    { R[31] = 0x8009F03Cu; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F034 jal */
L_8009F03C:;
    R[31] = lw_(R[29] + 28);  /* 0x8009F03C */
    R[18] = lw_(R[29] + 24);  /* 0x8009F040 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F044 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F048 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F04C jr ra */
}

void g0_8009EFD8(void) {
    R[2] = lb_(R[16] + 781);  /* 0x8009EFD8 */
    R[2] = R[2] | 0x80;  /* 0x8009EFE0 */
    { R[31] = 0x8009EFECu; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009EFE4 jal */
    R[4] = R[16] + R[0];  /* 0x8009EFEC */
    { R[31] = 0x8009EFF8u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EFF0 jal */
    sb_(R[18] + 30, R[0]);  /* 0x8009EFF8 */
    R[2] = lw_(R[16] + 72);  /* 0x8009EFFC */
    R[2] = lh_(R[2]);  /* 0x8009F004 */
    R[2] = R[2] >> 13;  /* 0x8009F00C */
    R[2] = R[2] & 0x1;  /* 0x8009F010 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F03C; } }  /* 0x8009F014 */
    { R[31] = 0x8009F024u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009F01C jal */
    { R[31] = 0x8009F02Cu; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009F024 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F03C; } }  /* 0x8009F02C */
    { R[31] = 0x8009F03Cu; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F034 jal */
L_8009F03C:;
    R[31] = lw_(R[29] + 28);  /* 0x8009F03C */
    R[18] = lw_(R[29] + 24);  /* 0x8009F040 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F044 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F048 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F04C jr ra */
}

void g0_8009EFEC(void) {
    R[4] = R[16] + R[0];  /* 0x8009EFEC */
    { R[31] = 0x8009EFF8u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EFF0 jal */
    sb_(R[18] + 30, R[0]);  /* 0x8009EFF8 */
    R[2] = lw_(R[16] + 72);  /* 0x8009EFFC */
    R[2] = lh_(R[2]);  /* 0x8009F004 */
    R[2] = R[2] >> 13;  /* 0x8009F00C */
    R[2] = R[2] & 0x1;  /* 0x8009F010 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F03C; } }  /* 0x8009F014 */
    { R[31] = 0x8009F024u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009F01C jal */
    { R[31] = 0x8009F02Cu; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009F024 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F03C; } }  /* 0x8009F02C */
    { R[31] = 0x8009F03Cu; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F034 jal */
L_8009F03C:;
    R[31] = lw_(R[29] + 28);  /* 0x8009F03C */
    R[18] = lw_(R[29] + 24);  /* 0x8009F040 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F044 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F048 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F04C jr ra */
}

void g0_8009EFF8(void) {
    sb_(R[18] + 30, R[0]);  /* 0x8009EFF8 */
    R[2] = lw_(R[16] + 72);  /* 0x8009EFFC */
    R[2] = lh_(R[2]);  /* 0x8009F004 */
    R[2] = R[2] >> 13;  /* 0x8009F00C */
    R[2] = R[2] & 0x1;  /* 0x8009F010 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F03C; } }  /* 0x8009F014 */
    { R[31] = 0x8009F024u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009F01C jal */
    { R[31] = 0x8009F02Cu; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009F024 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F03C; } }  /* 0x8009F02C */
    { R[31] = 0x8009F03Cu; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F034 jal */
L_8009F03C:;
    R[31] = lw_(R[29] + 28);  /* 0x8009F03C */
    R[18] = lw_(R[29] + 24);  /* 0x8009F040 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F044 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F048 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F04C jr ra */
}

void g0_8009F024(void) {
    { R[31] = 0x8009F02Cu; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009F024 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F03C; } }  /* 0x8009F02C */
    { R[31] = 0x8009F03Cu; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F034 jal */
L_8009F03C:;
    R[31] = lw_(R[29] + 28);  /* 0x8009F03C */
    R[18] = lw_(R[29] + 24);  /* 0x8009F040 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F044 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F048 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F04C jr ra */
}

void g0_8009F02C(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F03C; } }  /* 0x8009F02C */
    { R[31] = 0x8009F03Cu; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F034 jal */
L_8009F03C:;
    R[31] = lw_(R[29] + 28);  /* 0x8009F03C */
    R[18] = lw_(R[29] + 24);  /* 0x8009F040 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F044 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F048 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F04C jr ra */
}

void g0_8009F03C(void) {
    R[31] = lw_(R[29] + 28);  /* 0x8009F03C */
    R[18] = lw_(R[29] + 24);  /* 0x8009F040 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F044 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F048 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F04C jr ra */
}

void g0_8009F054(void) {
    R[29] = R[29] - 32;  /* 0x8009F054 */
    sw_(R[29] + 16, R[16]);  /* 0x8009F058 */
    R[16] = R[4] + R[0];  /* 0x8009F05C */
    R[3] = 0x8013u << 16;  /* 0x8009F060 */
    R[2] = R[0] + 1;  /* 0x8009F064 */
    sw_(R[29] + 24, R[31]);  /* 0x8009F068 */
    sw_(R[29] + 20, R[17]);  /* 0x8009F06C */
    sh_(R[3] + -29656, R[2]);  /* 0x8009F070 */
    R[2] = lw_(R[16] + 72);  /* 0x8009F074 */
    R[5] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x8009F07C */
    { R[31] = 0x8009F088u; R[17] = R[3] - 29656; psx_next = 0x8009EA38u; return; }  /* 0x8009F080 jal */
    R[2] = lw_(R[16] + 72);  /* 0x8009F088 */
    R[2] = lh_(R[2]);  /* 0x8009F090 */
    R[2] = R[2] >> 13;  /* 0x8009F098 */
    R[2] = R[2] & 0x1;  /* 0x8009F09C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009F108; } }  /* 0x8009F0A0 */
    R[3] = lb_(R[17] + 30);  /* 0x8009F0A8 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F0E8; } }  /* 0x8009F0B0 */
    { R[31] = 0x8009F0C0u; R[5] = R[0] + 95; psx_next = 0x8009BC84u; return; }  /* 0x8009F0B8 jal */
    R[2] = lb_(R[16] + 781);  /* 0x8009F0C0 */
    R[2] = R[2] | 0x80;  /* 0x8009F0C8 */
    { R[31] = 0x8009F0D4u; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009F0CC jal */
    R[4] = R[16] + R[0];  /* 0x8009F0D4 */
    { R[31] = 0x8009F0E0u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009F0D8 jal */
    { sb_(R[17] + 30, R[0]); goto L_8009F108; }  /* 0x8009F0E0 j */
L_8009F0E8:;
    { R[31] = 0x8009F0F0u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009F0E8 jal */
    { R[31] = 0x8009F0F8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009F0F0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F108; } }  /* 0x8009F0F8 */
    { R[31] = 0x8009F108u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F100 jal */
L_8009F108:;
    R[31] = lw_(R[29] + 24);  /* 0x8009F108 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F10C */
    R[16] = lw_(R[29] + 16);  /* 0x8009F110 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F114 jr ra */
}

void g0_8009F088(void) {
    R[2] = lw_(R[16] + 72);  /* 0x8009F088 */
    R[2] = lh_(R[2]);  /* 0x8009F090 */
    R[2] = R[2] >> 13;  /* 0x8009F098 */
    R[2] = R[2] & 0x1;  /* 0x8009F09C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009F108; } }  /* 0x8009F0A0 */
    R[3] = lb_(R[17] + 30);  /* 0x8009F0A8 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F0E8; } }  /* 0x8009F0B0 */
    { R[31] = 0x8009F0C0u; R[5] = R[0] + 95; psx_next = 0x8009BC84u; return; }  /* 0x8009F0B8 jal */
    R[2] = lb_(R[16] + 781);  /* 0x8009F0C0 */
    R[2] = R[2] | 0x80;  /* 0x8009F0C8 */
    { R[31] = 0x8009F0D4u; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009F0CC jal */
    R[4] = R[16] + R[0];  /* 0x8009F0D4 */
    { R[31] = 0x8009F0E0u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009F0D8 jal */
    { sb_(R[17] + 30, R[0]); goto L_8009F108; }  /* 0x8009F0E0 j */
L_8009F0E8:;
    { R[31] = 0x8009F0F0u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009F0E8 jal */
    { R[31] = 0x8009F0F8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009F0F0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F108; } }  /* 0x8009F0F8 */
    { R[31] = 0x8009F108u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F100 jal */
L_8009F108:;
    R[31] = lw_(R[29] + 24);  /* 0x8009F108 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F10C */
    R[16] = lw_(R[29] + 16);  /* 0x8009F110 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F114 jr ra */
}

void g0_8009F0C0(void) {
    R[2] = lb_(R[16] + 781);  /* 0x8009F0C0 */
    R[2] = R[2] | 0x80;  /* 0x8009F0C8 */
    { R[31] = 0x8009F0D4u; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009F0CC jal */
    R[4] = R[16] + R[0];  /* 0x8009F0D4 */
    { R[31] = 0x8009F0E0u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009F0D8 jal */
    { sb_(R[17] + 30, R[0]); goto L_8009F108; }  /* 0x8009F0E0 j */
    { R[31] = 0x8009F0F0u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009F0E8 jal */
    { R[31] = 0x8009F0F8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009F0F0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F108; } }  /* 0x8009F0F8 */
    { R[31] = 0x8009F108u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F100 jal */
L_8009F108:;
    R[31] = lw_(R[29] + 24);  /* 0x8009F108 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F10C */
    R[16] = lw_(R[29] + 16);  /* 0x8009F110 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F114 jr ra */
}

void g0_8009F0D4(void) {
    R[4] = R[16] + R[0];  /* 0x8009F0D4 */
    { R[31] = 0x8009F0E0u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009F0D8 jal */
    { sb_(R[17] + 30, R[0]); goto L_8009F108; }  /* 0x8009F0E0 j */
    { R[31] = 0x8009F0F0u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009F0E8 jal */
    { R[31] = 0x8009F0F8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009F0F0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F108; } }  /* 0x8009F0F8 */
    { R[31] = 0x8009F108u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F100 jal */
L_8009F108:;
    R[31] = lw_(R[29] + 24);  /* 0x8009F108 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F10C */
    R[16] = lw_(R[29] + 16);  /* 0x8009F110 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F114 jr ra */
}

void g0_8009F0E0(void) {
    { sb_(R[17] + 30, R[0]); goto L_8009F108; }  /* 0x8009F0E0 j */
    { R[31] = 0x8009F0F0u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009F0E8 jal */
    { R[31] = 0x8009F0F8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009F0F0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F108; } }  /* 0x8009F0F8 */
    { R[31] = 0x8009F108u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F100 jal */
L_8009F108:;
    R[31] = lw_(R[29] + 24);  /* 0x8009F108 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F10C */
    R[16] = lw_(R[29] + 16);  /* 0x8009F110 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F114 jr ra */
}

void g0_8009F0F0(void) {
    { R[31] = 0x8009F0F8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009F0F0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F108; } }  /* 0x8009F0F8 */
    { R[31] = 0x8009F108u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F100 jal */
L_8009F108:;
    R[31] = lw_(R[29] + 24);  /* 0x8009F108 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F10C */
    R[16] = lw_(R[29] + 16);  /* 0x8009F110 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F114 jr ra */
}

void g0_8009F0F8(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F108; } }  /* 0x8009F0F8 */
    { R[31] = 0x8009F108u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F100 jal */
L_8009F108:;
    R[31] = lw_(R[29] + 24);  /* 0x8009F108 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F10C */
    R[16] = lw_(R[29] + 16);  /* 0x8009F110 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F114 jr ra */
}

void g0_8009F108(void) {
    R[31] = lw_(R[29] + 24);  /* 0x8009F108 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F10C */
    R[16] = lw_(R[29] + 16);  /* 0x8009F110 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F114 jr ra */
}

void g0_8009F11C(void) {
    R[29] = R[29] - 32;  /* 0x8009F11C */
    sw_(R[29] + 16, R[16]);  /* 0x8009F120 */
    R[16] = R[4] + R[0];  /* 0x8009F124 */
    R[3] = 0x8013u << 16;  /* 0x8009F128 */
    R[2] = R[0] + 2;  /* 0x8009F12C */
    sw_(R[29] + 24, R[31]);  /* 0x8009F130 */
    sw_(R[29] + 20, R[17]);  /* 0x8009F134 */
    sh_(R[3] + -29656, R[2]);  /* 0x8009F138 */
    R[2] = lw_(R[16] + 72);  /* 0x8009F13C */
    R[5] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x8009F144 */
    { R[31] = 0x8009F150u; R[17] = R[3] - 29656; psx_next = 0x8009EA38u; return; }  /* 0x8009F148 jal */
    R[2] = lw_(R[16] + 72);  /* 0x8009F150 */
    R[2] = lh_(R[2]);  /* 0x8009F158 */
    R[2] = R[2] >> 13;  /* 0x8009F160 */
    R[2] = R[2] & 0x1;  /* 0x8009F164 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009F1D0; } }  /* 0x8009F168 */
    R[3] = lb_(R[17] + 30);  /* 0x8009F170 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F1B0; } }  /* 0x8009F178 */
    { R[31] = 0x8009F188u; R[5] = R[0] + 92; psx_next = 0x8009BC84u; return; }  /* 0x8009F180 jal */
    R[2] = lb_(R[16] + 781);  /* 0x8009F188 */
    R[2] = R[2] | 0x80;  /* 0x8009F190 */
    { R[31] = 0x8009F19Cu; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009F194 jal */
    R[4] = R[16] + R[0];  /* 0x8009F19C */
    { R[31] = 0x8009F1A8u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009F1A0 jal */
    { sb_(R[17] + 30, R[0]); goto L_8009F1D0; }  /* 0x8009F1A8 j */
L_8009F1B0:;
    { R[31] = 0x8009F1B8u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009F1B0 jal */
    { R[31] = 0x8009F1C0u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009F1B8 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F1D0; } }  /* 0x8009F1C0 */
    { R[31] = 0x8009F1D0u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F1C8 jal */
L_8009F1D0:;
    R[31] = lw_(R[29] + 24);  /* 0x8009F1D0 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F1D4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F1D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F1DC jr ra */
}

void g0_8009F150(void) {
    R[2] = lw_(R[16] + 72);  /* 0x8009F150 */
    R[2] = lh_(R[2]);  /* 0x8009F158 */
    R[2] = R[2] >> 13;  /* 0x8009F160 */
    R[2] = R[2] & 0x1;  /* 0x8009F164 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009F1D0; } }  /* 0x8009F168 */
    R[3] = lb_(R[17] + 30);  /* 0x8009F170 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F1B0; } }  /* 0x8009F178 */
    { R[31] = 0x8009F188u; R[5] = R[0] + 92; psx_next = 0x8009BC84u; return; }  /* 0x8009F180 jal */
    R[2] = lb_(R[16] + 781);  /* 0x8009F188 */
    R[2] = R[2] | 0x80;  /* 0x8009F190 */
    { R[31] = 0x8009F19Cu; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009F194 jal */
    R[4] = R[16] + R[0];  /* 0x8009F19C */
    { R[31] = 0x8009F1A8u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009F1A0 jal */
    { sb_(R[17] + 30, R[0]); goto L_8009F1D0; }  /* 0x8009F1A8 j */
L_8009F1B0:;
    { R[31] = 0x8009F1B8u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009F1B0 jal */
    { R[31] = 0x8009F1C0u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009F1B8 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F1D0; } }  /* 0x8009F1C0 */
    { R[31] = 0x8009F1D0u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F1C8 jal */
L_8009F1D0:;
    R[31] = lw_(R[29] + 24);  /* 0x8009F1D0 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F1D4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F1D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F1DC jr ra */
}

void g0_8009F188(void) {
    R[2] = lb_(R[16] + 781);  /* 0x8009F188 */
    R[2] = R[2] | 0x80;  /* 0x8009F190 */
    { R[31] = 0x8009F19Cu; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009F194 jal */
    R[4] = R[16] + R[0];  /* 0x8009F19C */
    { R[31] = 0x8009F1A8u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009F1A0 jal */
    { sb_(R[17] + 30, R[0]); goto L_8009F1D0; }  /* 0x8009F1A8 j */
    { R[31] = 0x8009F1B8u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009F1B0 jal */
    { R[31] = 0x8009F1C0u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009F1B8 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F1D0; } }  /* 0x8009F1C0 */
    { R[31] = 0x8009F1D0u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F1C8 jal */
L_8009F1D0:;
    R[31] = lw_(R[29] + 24);  /* 0x8009F1D0 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F1D4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F1D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F1DC jr ra */
}

void g0_8009F19C(void) {
    R[4] = R[16] + R[0];  /* 0x8009F19C */
    { R[31] = 0x8009F1A8u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009F1A0 jal */
    { sb_(R[17] + 30, R[0]); goto L_8009F1D0; }  /* 0x8009F1A8 j */
    { R[31] = 0x8009F1B8u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009F1B0 jal */
    { R[31] = 0x8009F1C0u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009F1B8 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F1D0; } }  /* 0x8009F1C0 */
    { R[31] = 0x8009F1D0u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F1C8 jal */
L_8009F1D0:;
    R[31] = lw_(R[29] + 24);  /* 0x8009F1D0 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F1D4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F1D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F1DC jr ra */
}

void g0_8009F1A8(void) {
    { sb_(R[17] + 30, R[0]); goto L_8009F1D0; }  /* 0x8009F1A8 j */
    { R[31] = 0x8009F1B8u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009F1B0 jal */
    { R[31] = 0x8009F1C0u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009F1B8 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F1D0; } }  /* 0x8009F1C0 */
    { R[31] = 0x8009F1D0u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F1C8 jal */
L_8009F1D0:;
    R[31] = lw_(R[29] + 24);  /* 0x8009F1D0 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F1D4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F1D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F1DC jr ra */
}

void g0_8009F1B8(void) {
    { R[31] = 0x8009F1C0u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009F1B8 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F1D0; } }  /* 0x8009F1C0 */
    { R[31] = 0x8009F1D0u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F1C8 jal */
L_8009F1D0:;
    R[31] = lw_(R[29] + 24);  /* 0x8009F1D0 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F1D4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F1D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F1DC jr ra */
}

void g0_8009F1C0(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F1D0; } }  /* 0x8009F1C0 */
    { R[31] = 0x8009F1D0u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F1C8 jal */
L_8009F1D0:;
    R[31] = lw_(R[29] + 24);  /* 0x8009F1D0 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F1D4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F1D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F1DC jr ra */
}

void g0_8009F1D0(void) {
    R[31] = lw_(R[29] + 24);  /* 0x8009F1D0 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F1D4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F1D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F1DC jr ra */
}

void g0_8009F1E4(void) {
    R[29] = R[29] - 40;  /* 0x8009F1E4 */
    sw_(R[29] + 28, R[17]);  /* 0x8009F1E8 */
    R[17] = R[4] + R[0];  /* 0x8009F1EC */
    R[5] = R[0] + 37;  /* 0x8009F1F0 */
    sw_(R[29] + 32, R[31]);  /* 0x8009F1F4 */
    { R[31] = 0x8009F200u; sw_(R[29] + 24, R[16]); psx_next = 0x8009D4B0u; return; }  /* 0x8009F1F8 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F2C0; } }  /* 0x8009F200 */
    R[2] = lw_(R[17] + 72);  /* 0x8009F208 */
    R[16] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x8009F210 */
    R[2] = R[16] - 4;  /* 0x8009F218 */
    R[2] = (R[2] < (uint32_t)12u);  /* 0x8009F21C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[16] & 0x1; if (_c) { goto L_8009F258; } }  /* 0x8009F220 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 20; if (_c) { goto L_8009F25C; } }  /* 0x8009F228 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x8009F230 */
    R[2] = R[2] - 256;  /* 0x8009F238 */
    R[2] = R[2] & 0x1FF;  /* 0x8009F23C */
    sw_(R[29] + 16, R[2]);  /* 0x8009F240 */
    R[5] = lw_(R[17] + 24);  /* 0x8009F244 */
    R[6] = lw_(R[17] + 28);  /* 0x8009F248 */
    R[7] = lw_(R[17] + 32);  /* 0x8009F24C */
    { R[31] = 0x8009F258u; R[4] = R[0] + 7; psx_next = 0x800A7290u; return; }  /* 0x8009F250 jal */
L_8009F258:;
    R[2] = R[0] + 20;  /* 0x8009F258 */
L_8009F25C:;
    { uint32_t _c = (R[16] != R[2]); if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    sw_(R[17] + 124, R[0]);  /* 0x8009F264 */
L_8009F268:;
    R[2] = lw_(R[17] + 72);  /* 0x8009F268 */
    R[2] = lh_(R[2]);  /* 0x8009F270 */
    R[2] = R[2] >> 13;  /* 0x8009F278 */
    R[2] = R[2] & 0x1;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8012u << 16; if (_c) { goto L_8009F2C0; } }  /* 0x8009F280 */
    R[2] = lh_(R[2] + 31132);  /* 0x8009F288 */
    R[2] = R[2] & 0x1;  /* 0x8009F290 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009F2A4; } }  /* 0x8009F294 */
    { R[5] = R[0] + 5; goto L_8009F2B4; }  /* 0x8009F29C j */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 8; psx_next = 0x8009DCB0u; return; }  /* 0x8009F2A4 jal */
    R[4] = R[17] + R[0];  /* 0x8009F2AC */
    R[5] = R[2] + R[0];  /* 0x8009F2B0 */
L_8009F2B4:;
    R[6] = R[0] + R[0];  /* 0x8009F2B4 */
    { R[31] = 0x8009F2C0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009F2B8 jal */
L_8009F2C0:;
    R[31] = lw_(R[29] + 32);  /* 0x8009F2C0 */
    R[17] = lw_(R[29] + 28);  /* 0x8009F2C4 */
    R[16] = lw_(R[29] + 24);  /* 0x8009F2C8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009F2CC jr ra */
}

void g0_8009F200(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F2C0; } }  /* 0x8009F200 */
    R[2] = lw_(R[17] + 72);  /* 0x8009F208 */
    R[16] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x8009F210 */
    R[2] = R[16] - 4;  /* 0x8009F218 */
    R[2] = (R[2] < (uint32_t)12u);  /* 0x8009F21C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[16] & 0x1; if (_c) { goto L_8009F258; } }  /* 0x8009F220 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 20; if (_c) { goto L_8009F25C; } }  /* 0x8009F228 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 4);  /* 0x8009F230 */
    R[2] = R[2] - 256;  /* 0x8009F238 */
    R[2] = R[2] & 0x1FF;  /* 0x8009F23C */
    sw_(R[29] + 16, R[2]);  /* 0x8009F240 */
    R[5] = lw_(R[17] + 24);  /* 0x8009F244 */
    R[6] = lw_(R[17] + 28);  /* 0x8009F248 */
    R[7] = lw_(R[17] + 32);  /* 0x8009F24C */
    { R[31] = 0x8009F258u; R[4] = R[0] + 7; psx_next = 0x800A7290u; return; }  /* 0x8009F250 jal */
L_8009F258:;
    R[2] = R[0] + 20;  /* 0x8009F258 */
L_8009F25C:;
    { uint32_t _c = (R[16] != R[2]); if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    sw_(R[17] + 124, R[0]);  /* 0x8009F264 */
L_8009F268:;
    R[2] = lw_(R[17] + 72);  /* 0x8009F268 */
    R[2] = lh_(R[2]);  /* 0x8009F270 */
    R[2] = R[2] >> 13;  /* 0x8009F278 */
    R[2] = R[2] & 0x1;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8012u << 16; if (_c) { goto L_8009F2C0; } }  /* 0x8009F280 */
    R[2] = lh_(R[2] + 31132);  /* 0x8009F288 */
    R[2] = R[2] & 0x1;  /* 0x8009F290 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009F2A4; } }  /* 0x8009F294 */
    { R[5] = R[0] + 5; goto L_8009F2B4; }  /* 0x8009F29C j */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 8; psx_next = 0x8009DCB0u; return; }  /* 0x8009F2A4 jal */
    R[4] = R[17] + R[0];  /* 0x8009F2AC */
    R[5] = R[2] + R[0];  /* 0x8009F2B0 */
L_8009F2B4:;
    R[6] = R[0] + R[0];  /* 0x8009F2B4 */
    { R[31] = 0x8009F2C0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009F2B8 jal */
L_8009F2C0:;
    R[31] = lw_(R[29] + 32);  /* 0x8009F2C0 */
    R[17] = lw_(R[29] + 28);  /* 0x8009F2C4 */
    R[16] = lw_(R[29] + 24);  /* 0x8009F2C8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009F2CC jr ra */
}

void g0_8009F258(void) {
    R[2] = R[0] + 20;  /* 0x8009F258 */
    { uint32_t _c = (R[16] != R[2]); if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    sw_(R[17] + 124, R[0]);  /* 0x8009F264 */
L_8009F268:;
    R[2] = lw_(R[17] + 72);  /* 0x8009F268 */
    R[2] = lh_(R[2]);  /* 0x8009F270 */
    R[2] = R[2] >> 13;  /* 0x8009F278 */
    R[2] = R[2] & 0x1;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8012u << 16; if (_c) { goto L_8009F2C0; } }  /* 0x8009F280 */
    R[2] = lh_(R[2] + 31132);  /* 0x8009F288 */
    R[2] = R[2] & 0x1;  /* 0x8009F290 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009F2A4; } }  /* 0x8009F294 */
    { R[5] = R[0] + 5; goto L_8009F2B4; }  /* 0x8009F29C j */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 8; psx_next = 0x8009DCB0u; return; }  /* 0x8009F2A4 jal */
    R[4] = R[17] + R[0];  /* 0x8009F2AC */
    R[5] = R[2] + R[0];  /* 0x8009F2B0 */
L_8009F2B4:;
    R[6] = R[0] + R[0];  /* 0x8009F2B4 */
    { R[31] = 0x8009F2C0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009F2B8 jal */
L_8009F2C0:;
    R[31] = lw_(R[29] + 32);  /* 0x8009F2C0 */
    R[17] = lw_(R[29] + 28);  /* 0x8009F2C4 */
    R[16] = lw_(R[29] + 24);  /* 0x8009F2C8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009F2CC jr ra */
}

void g0_8009F2AC(void) {
    R[4] = R[17] + R[0];  /* 0x8009F2AC */
    R[5] = R[2] + R[0];  /* 0x8009F2B0 */
    R[6] = R[0] + R[0];  /* 0x8009F2B4 */
    { R[31] = 0x8009F2C0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009F2B8 jal */
    R[31] = lw_(R[29] + 32);  /* 0x8009F2C0 */
    R[17] = lw_(R[29] + 28);  /* 0x8009F2C4 */
    R[16] = lw_(R[29] + 24);  /* 0x8009F2C8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009F2CC jr ra */
}

void g0_8009F2C0(void) {
    R[31] = lw_(R[29] + 32);  /* 0x8009F2C0 */
    R[17] = lw_(R[29] + 28);  /* 0x8009F2C4 */
    R[16] = lw_(R[29] + 24);  /* 0x8009F2C8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009F2CC jr ra */
}

void g0_8009F2D4(void) {
    R[29] = R[29] - 24;  /* 0x8009F2D4 */
    sw_(R[29] + 16, R[16]);  /* 0x8009F2D8 */
    R[16] = R[4] + R[0];  /* 0x8009F2DC */
    sw_(R[29] + 20, R[31]);  /* 0x8009F2E0 */
    R[3] = lb_(R[16] + 784);  /* 0x8009F2E4 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F320; } }  /* 0x8009F2EC */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F30C; } }  /* 0x8009F2F4 */
    { R[31] = 0x8009F304u; psx_next = 0x8009DB64u; return; }  /* 0x8009F2FC jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F364; } }  /* 0x8009F304 */
L_8009F30C:;
    R[4] = R[16] + R[0];  /* 0x8009F30C */
    { R[31] = 0x8009F318u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F310 jal */
    { goto L_8009F364; }  /* 0x8009F318 j */
L_8009F320:;
    R[4] = R[16] + R[0];  /* 0x8009F320 */
    R[5] = R[0] - 1;  /* 0x8009F324 */
    R[6] = R[5] + R[0];  /* 0x8009F328 */
    { R[31] = 0x8009F334u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009F32C jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_8009F344; } }  /* 0x8009F334 */
    { sw_(R[16] + 124, R[0]); goto L_8009F364; }  /* 0x8009F33C j */
L_8009F344:;
    R[2] = lh_(R[2] + 29320);  /* 0x8009F344 */
    R[2] = R[2] << 16;  /* 0x8009F34C */
    R[3] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009F350 */
    R[2] = R[2] >> 31;  /* 0x8009F354 */
    R[3] = R[3] + R[2];  /* 0x8009F358 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009F35C */
    sw_(R[16] + 124, R[3]);  /* 0x8009F360 */
L_8009F364:;
    R[31] = lw_(R[29] + 20);  /* 0x8009F364 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F368 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F36C jr ra */
}

void g0_8009F304(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F364; } }  /* 0x8009F304 */
    R[4] = R[16] + R[0];  /* 0x8009F30C */
    { R[31] = 0x8009F318u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F310 jal */
    { goto L_8009F364; }  /* 0x8009F318 j */
    R[4] = R[16] + R[0];  /* 0x8009F320 */
    R[5] = R[0] - 1;  /* 0x8009F324 */
    R[6] = R[5] + R[0];  /* 0x8009F328 */
    { R[31] = 0x8009F334u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009F32C jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_8009F344; } }  /* 0x8009F334 */
    { sw_(R[16] + 124, R[0]); goto L_8009F364; }  /* 0x8009F33C j */
L_8009F344:;
    R[2] = lh_(R[2] + 29320);  /* 0x8009F344 */
    R[2] = R[2] << 16;  /* 0x8009F34C */
    R[3] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009F350 */
    R[2] = R[2] >> 31;  /* 0x8009F354 */
    R[3] = R[3] + R[2];  /* 0x8009F358 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009F35C */
    sw_(R[16] + 124, R[3]);  /* 0x8009F360 */
L_8009F364:;
    R[31] = lw_(R[29] + 20);  /* 0x8009F364 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F368 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F36C jr ra */
}

void g0_8009F318(void) {
    { goto L_8009F364; }  /* 0x8009F318 j */
    R[4] = R[16] + R[0];  /* 0x8009F320 */
    R[5] = R[0] - 1;  /* 0x8009F324 */
    R[6] = R[5] + R[0];  /* 0x8009F328 */
    { R[31] = 0x8009F334u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009F32C jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_8009F344; } }  /* 0x8009F334 */
    { sw_(R[16] + 124, R[0]); goto L_8009F364; }  /* 0x8009F33C j */
L_8009F344:;
    R[2] = lh_(R[2] + 29320);  /* 0x8009F344 */
    R[2] = R[2] << 16;  /* 0x8009F34C */
    R[3] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009F350 */
    R[2] = R[2] >> 31;  /* 0x8009F354 */
    R[3] = R[3] + R[2];  /* 0x8009F358 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009F35C */
    sw_(R[16] + 124, R[3]);  /* 0x8009F360 */
L_8009F364:;
    R[31] = lw_(R[29] + 20);  /* 0x8009F364 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F368 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F36C jr ra */
}

void g0_8009F334(void) {
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_8009F344; } }  /* 0x8009F334 */
    { sw_(R[16] + 124, R[0]); goto L_8009F364; }  /* 0x8009F33C j */
L_8009F344:;
    R[2] = lh_(R[2] + 29320);  /* 0x8009F344 */
    R[2] = R[2] << 16;  /* 0x8009F34C */
    R[3] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009F350 */
    R[2] = R[2] >> 31;  /* 0x8009F354 */
    R[3] = R[3] + R[2];  /* 0x8009F358 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009F35C */
    sw_(R[16] + 124, R[3]);  /* 0x8009F360 */
L_8009F364:;
    R[31] = lw_(R[29] + 20);  /* 0x8009F364 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F368 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F36C jr ra */
}

void g0_8009F374(void) {
    R[29] = R[29] - 24;  /* 0x8009F374 */
    sw_(R[29] + 16, R[16]);  /* 0x8009F378 */
    R[16] = R[4] + R[0];  /* 0x8009F37C */
    sw_(R[29] + 20, R[31]);  /* 0x8009F380 */
    R[2] = lw_(R[16] + 72);  /* 0x8009F384 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x8009F38C */
    R[2] = R[0] + 5;  /* 0x8009F390 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F394 */
    sw_(R[16] + 124, R[0]);  /* 0x8009F39C */
L_8009F3A0:;
    R[2] = lw_(R[16] + 72);  /* 0x8009F3A0 */
    R[2] = lh_(R[2]);  /* 0x8009F3A8 */
    R[2] = R[2] >> 13;  /* 0x8009F3B0 */
    R[2] = R[2] & 0x1;  /* 0x8009F3B4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F3F8; } }  /* 0x8009F3B8 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 56);  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F3E0; } }  /* 0x8009F3C8 */
    { R[31] = 0x8009F3D8u; R[5] = R[0] + 34; psx_next = 0x8009BC84u; return; }  /* 0x8009F3D0 jal */
    { goto L_8009F3F8; }  /* 0x8009F3D8 j */
L_8009F3E0:;
    R[2] = lh_(R[16] + 4);  /* 0x8009F3E0 */
    R[5] = R[0] + R[0];  /* 0x8009F3E4 */
    { R[31] = 0x8009F3F0u; sh_(R[16] + 6, R[2]); psx_next = 0x8009BC84u; return; }  /* 0x8009F3E8 jal */
    R[2] = R[0] + 30;  /* 0x8009F3F0 */
    sb_(R[16] + 797, R[2]);  /* 0x8009F3F4 */
L_8009F3F8:;
    R[31] = lw_(R[29] + 20);  /* 0x8009F3F8 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F3FC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F400 jr ra */
}

void g0_8009F3D8(void) {
    { goto L_8009F3F8; }  /* 0x8009F3D8 j */
    R[2] = lh_(R[16] + 4);  /* 0x8009F3E0 */
    R[5] = R[0] + R[0];  /* 0x8009F3E4 */
    { R[31] = 0x8009F3F0u; sh_(R[16] + 6, R[2]); psx_next = 0x8009BC84u; return; }  /* 0x8009F3E8 jal */
    R[2] = R[0] + 30;  /* 0x8009F3F0 */
    sb_(R[16] + 797, R[2]);  /* 0x8009F3F4 */
L_8009F3F8:;
    R[31] = lw_(R[29] + 20);  /* 0x8009F3F8 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F3FC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F400 jr ra */
}

void g0_8009F3F0(void) {
    R[2] = R[0] + 30;  /* 0x8009F3F0 */
    sb_(R[16] + 797, R[2]);  /* 0x8009F3F4 */
    R[31] = lw_(R[29] + 20);  /* 0x8009F3F8 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F3FC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F400 jr ra */
}

void g0_8009F408(void) {
    R[29] = R[29] - 24;  /* 0x8009F408 */
    sw_(R[29] + 16, R[16]);  /* 0x8009F40C */
    R[16] = R[4] + R[0];  /* 0x8009F410 */
    sw_(R[29] + 20, R[31]);  /* 0x8009F414 */
    R[2] = lw_(R[16] + 600);  /* 0x8009F418 */
    R[3] = lw_(R[16] + 72);  /* 0x8009F41C */
    R[2] = R[2] + 1;  /* 0x8009F420 */
    sw_(R[16] + 600, R[2]);  /* 0x8009F424 */
    R[3] = (uint32_t)(int16_t)lh_(R[3] + 4);  /* 0x8009F428 */
    R[2] = R[0] + 10;  /* 0x8009F42C */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F43C; } }  /* 0x8009F430 */
    sw_(R[16] + 124, R[0]);  /* 0x8009F438 */
L_8009F43C:;
    R[2] = lb_(R[16] + 784);  /* 0x8009F43C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F478; } }  /* 0x8009F444 */
    R[2] = 0x8012u << 16;  /* 0x8009F44C */
    R[2] = lh_(R[2] + 31132);  /* 0x8009F450 */
    R[2] = R[2] & 0x1;  /* 0x8009F458 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F488; } }  /* 0x8009F45C */
    R[2] = lw_(R[16] + 600);  /* 0x8009F464 */
    R[2] = ((int32_t)R[2] < 30);  /* 0x8009F46C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F488; } }  /* 0x8009F470 */
L_8009F478:;
    { R[31] = 0x8009F480u; R[5] = R[0] + 31; psx_next = 0x8009BC84u; return; }  /* 0x8009F478 jal */
    R[2] = R[0] + 384;  /* 0x8009F480 */
    sw_(R[16] + 124, R[2]);  /* 0x8009F484 */
L_8009F488:;
    R[31] = lw_(R[29] + 20);  /* 0x8009F488 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F48C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F490 jr ra */
}

void g0_8009F480(void) {
    R[2] = R[0] + 384;  /* 0x8009F480 */
    sw_(R[16] + 124, R[2]);  /* 0x8009F484 */
    R[31] = lw_(R[29] + 20);  /* 0x8009F488 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F48C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F490 jr ra */
}

void g0_8009F498(void) {
    R[29] = R[29] - 24;  /* 0x8009F498 */
    sw_(R[29] + 16, R[16]);  /* 0x8009F49C */
    R[16] = R[4] + R[0];  /* 0x8009F4A0 */
    sw_(R[29] + 20, R[31]);  /* 0x8009F4A4 */
    R[2] = lw_(R[16] + 600);  /* 0x8009F4A8 */
    R[3] = lw_(R[16] + 72);  /* 0x8009F4AC */
    R[2] = R[2] + 1;  /* 0x8009F4B0 */
    sw_(R[16] + 600, R[2]);  /* 0x8009F4B4 */
    R[3] = (uint32_t)(int16_t)lh_(R[3] + 4);  /* 0x8009F4B8 */
    R[2] = R[0] + 10;  /* 0x8009F4BC */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4CC; } }  /* 0x8009F4C0 */
    sw_(R[16] + 124, R[0]);  /* 0x8009F4C8 */
L_8009F4CC:;
    R[2] = lb_(R[16] + 784);  /* 0x8009F4CC */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F508; } }  /* 0x8009F4D4 */
    R[2] = 0x8012u << 16;  /* 0x8009F4DC */
    R[2] = lh_(R[2] + 31132);  /* 0x8009F4E0 */
    R[2] = R[2] & 0x1;  /* 0x8009F4E8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F518; } }  /* 0x8009F4EC */
    R[2] = lw_(R[16] + 600);  /* 0x8009F4F4 */
    R[2] = ((int32_t)R[2] < 30);  /* 0x8009F4FC */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F518; } }  /* 0x8009F500 */
L_8009F508:;
    { R[31] = 0x8009F510u; R[5] = R[0] + 31; psx_next = 0x8009BC84u; return; }  /* 0x8009F508 jal */
    R[2] = R[0] + 768;  /* 0x8009F510 */
    sw_(R[16] + 124, R[2]);  /* 0x8009F514 */
L_8009F518:;
    R[31] = lw_(R[29] + 20);  /* 0x8009F518 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F51C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F520 jr ra */
}

void g0_8009F510(void) {
    R[2] = R[0] + 768;  /* 0x8009F510 */
    sw_(R[16] + 124, R[2]);  /* 0x8009F514 */
    R[31] = lw_(R[29] + 20);  /* 0x8009F518 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F51C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F520 jr ra */
}

void g0_8009F528(void) {
    R[29] = R[29] - 32;  /* 0x8009F528 */
    sw_(R[29] + 20, R[17]);  /* 0x8009F52C */
    R[17] = R[4] + R[0];  /* 0x8009F530 */
    sw_(R[29] + 24, R[31]);  /* 0x8009F534 */
    { R[31] = 0x8009F540u; sw_(R[29] + 16, R[16]); psx_next = 0x8001D16Cu; return; }  /* 0x8009F538 jal */
    R[16] = 0x8012u << 16;  /* 0x8009F540 */
    R[16] = R[16] - 26864;  /* 0x8009F544 */
    { R[31] = 0x8009F550u; sh_(R[16] + 56, R[2]); psx_next = 0x8001D1B8u; return; }  /* 0x8009F548 jal */
    R[4] = R[17] + R[0];  /* 0x8009F550 */
    { R[31] = 0x8009F55Cu; sh_(R[16] + 58, R[2]); psx_next = 0x800A4B08u; return; }  /* 0x8009F554 jal */
    R[4] = lh_(R[16] + 56);  /* 0x8009F55C */
    R[3] = 0x8006u << 16;  /* 0x8009F560 */
    sh_(R[3] + 16082, R[4]);  /* 0x8009F564 */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 56);  /* 0x8009F568 */
    { uint32_t _c = (R[3] != R[0]); R[16] = R[2] + R[0]; if (_c) { psx_next = 0x8009F5ACu; return; } }  /* 0x8009F570 b extern */
    R[4] = R[17] + R[0];  /* 0x8009F578 */
    R[5] = 0x800Fu << 16;  /* 0x8009F57C */
    R[2] = lw_(R[5] + 25120);  /* 0x8009F580 */
    R[3] = 0x8013u << 16;  /* 0x8009F584 */
    sw_(R[3] + -29560, R[17]);  /* 0x8009F588 */
    R[2] = R[2] | 0x40;  /* 0x8009F58C */
    psx_next = 0x8009F590u; return;  /* fallthrough */
}

void g0_8009F540(void) {
    R[16] = 0x8012u << 16;  /* 0x8009F540 */
    R[16] = R[16] - 26864;  /* 0x8009F544 */
    { R[31] = 0x8009F550u; sh_(R[16] + 56, R[2]); psx_next = 0x8001D1B8u; return; }  /* 0x8009F548 jal */
    R[4] = R[17] + R[0];  /* 0x8009F550 */
    { R[31] = 0x8009F55Cu; sh_(R[16] + 58, R[2]); psx_next = 0x800A4B08u; return; }  /* 0x8009F554 jal */
    R[4] = lh_(R[16] + 56);  /* 0x8009F55C */
    R[3] = 0x8006u << 16;  /* 0x8009F560 */
    sh_(R[3] + 16082, R[4]);  /* 0x8009F564 */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 56);  /* 0x8009F568 */
    { uint32_t _c = (R[3] != R[0]); R[16] = R[2] + R[0]; if (_c) { psx_next = 0x8009F5ACu; return; } }  /* 0x8009F570 b extern */
    R[4] = R[17] + R[0];  /* 0x8009F578 */
    R[5] = 0x800Fu << 16;  /* 0x8009F57C */
    R[2] = lw_(R[5] + 25120);  /* 0x8009F580 */
    R[3] = 0x8013u << 16;  /* 0x8009F584 */
    sw_(R[3] + -29560, R[17]);  /* 0x8009F588 */
    R[2] = R[2] | 0x40;  /* 0x8009F58C */
    psx_next = 0x8009F590u; return;  /* fallthrough */
}

void g0_8009F550(void) {
    R[4] = R[17] + R[0];  /* 0x8009F550 */
    { R[31] = 0x8009F55Cu; sh_(R[16] + 58, R[2]); psx_next = 0x800A4B08u; return; }  /* 0x8009F554 jal */
    R[4] = lh_(R[16] + 56);  /* 0x8009F55C */
    R[3] = 0x8006u << 16;  /* 0x8009F560 */
    sh_(R[3] + 16082, R[4]);  /* 0x8009F564 */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 56);  /* 0x8009F568 */
    { uint32_t _c = (R[3] != R[0]); R[16] = R[2] + R[0]; if (_c) { psx_next = 0x8009F5ACu; return; } }  /* 0x8009F570 b extern */
    R[4] = R[17] + R[0];  /* 0x8009F578 */
    R[5] = 0x800Fu << 16;  /* 0x8009F57C */
    R[2] = lw_(R[5] + 25120);  /* 0x8009F580 */
    R[3] = 0x8013u << 16;  /* 0x8009F584 */
    sw_(R[3] + -29560, R[17]);  /* 0x8009F588 */
    R[2] = R[2] | 0x40;  /* 0x8009F58C */
    psx_next = 0x8009F590u; return;  /* fallthrough */
}

void g0_8009F55C(void) {
    R[4] = lh_(R[16] + 56);  /* 0x8009F55C */
    R[3] = 0x8006u << 16;  /* 0x8009F560 */
    sh_(R[3] + 16082, R[4]);  /* 0x8009F564 */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 56);  /* 0x8009F568 */
    { uint32_t _c = (R[3] != R[0]); R[16] = R[2] + R[0]; if (_c) { psx_next = 0x8009F5ACu; return; } }  /* 0x8009F570 b extern */
    R[4] = R[17] + R[0];  /* 0x8009F578 */
    R[5] = 0x800Fu << 16;  /* 0x8009F57C */
    R[2] = lw_(R[5] + 25120);  /* 0x8009F580 */
    R[3] = 0x8013u << 16;  /* 0x8009F584 */
    sw_(R[3] + -29560, R[17]);  /* 0x8009F588 */
    R[2] = R[2] | 0x40;  /* 0x8009F58C */
    psx_next = 0x8009F590u; return;  /* fallthrough */
}

void g0_8009F590(void) {
    { R[31] = 0x8009F598u; sw_(R[5] + 25120, R[2]); psx_next = 0x8008DD18u; return; }  /* 0x8009F590 jal */
    R[3] = 0xFBFFu << 16;  /* 0x8009F598 */
    R[2] = lw_(R[17] + 16);  /* 0x8009F59C */
    R[3] = R[3] | 0xFFFF;  /* 0x8009F5A0 */
    R[2] = R[2] & R[3];  /* 0x8009F5A4 */
    sw_(R[17] + 16, R[2]);  /* 0x8009F5A8 */
    R[2] = R[16] + R[0];  /* 0x8009F5AC */
    R[31] = lw_(R[29] + 24);  /* 0x8009F5B0 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F5B4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F5B8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F5BC jr ra */
}

void g0_8009F598(void) {
    R[3] = 0xFBFFu << 16;  /* 0x8009F598 */
    R[2] = lw_(R[17] + 16);  /* 0x8009F59C */
    R[3] = R[3] | 0xFFFF;  /* 0x8009F5A0 */
    R[2] = R[2] & R[3];  /* 0x8009F5A4 */
    sw_(R[17] + 16, R[2]);  /* 0x8009F5A8 */
    R[2] = R[16] + R[0];  /* 0x8009F5AC */
    R[31] = lw_(R[29] + 24);  /* 0x8009F5B0 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F5B4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F5B8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F5BC jr ra */
}

void g0_8009F5AC(void) {
    R[2] = R[16] + R[0];  /* 0x8009F5AC */
    R[31] = lw_(R[29] + 24);  /* 0x8009F5B0 */
    R[17] = lw_(R[29] + 20);  /* 0x8009F5B4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F5B8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F5BC jr ra */
}

void g0_8009F5C4(void) {
    R[29] = R[29] - 32;  /* 0x8009F5C4 */
    sw_(R[29] + 16, R[16]);  /* 0x8009F5C8 */
    R[16] = R[4] + R[0];  /* 0x8009F5CC */
    sw_(R[29] + 24, R[31]);  /* 0x8009F5D0 */
    { R[31] = 0x8009F5DCu; sw_(R[29] + 20, R[17]); psx_next = 0x8009F528u; return; }  /* 0x8009F5D4 jal */
    R[4] = R[16] + R[0];  /* 0x8009F5DC */
    R[5] = R[0] + 2;  /* 0x8009F5E0 */
    { R[31] = 0x8009F5ECu; R[17] = R[2] + R[0]; psx_next = 0x8009C12Cu; return; }  /* 0x8009F5E4 jal */
    R[3] = 0x8013u << 16;  /* 0x8009F5EC */
    R[2] = R[0] - 1;  /* 0x8009F5F0 */
    sh_(R[3] + -29476, R[2]);  /* 0x8009F5F4 */
    R[2] = 0x8013u << 16;  /* 0x8009F5F8 */
    sh_(R[2] + -29606, R[0]);  /* 0x8009F5FC */
    R[2] = R[0] + 9;  /* 0x8009F600 */
    { uint32_t _c = (R[17] == R[2]); R[2] = ((int32_t)R[17] < 10); if (_c) { goto L_8009F7BC; } }  /* 0x8009F604 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009F624; } }  /* 0x8009F60C */
    { uint32_t _c = (R[17] == R[2]); if (_c) { goto L_8009F734; } }  /* 0x8009F614 */
    { goto L_8009F630; }  /* 0x8009F61C j */
L_8009F624:;
    R[2] = R[0] + 10;  /* 0x8009F624 */
    { uint32_t _c = (R[17] == R[2]); if (_c) { goto L_8009F774; } }  /* 0x8009F628 */
L_8009F630:;
    { R[31] = 0x8009F638u; R[4] = R[0] + R[0]; psx_next = 0x800905D4u; return; }  /* 0x8009F630 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F638 */
    { R[31] = 0x8009F644u; R[4] = R[0] + 38; psx_next = 0x8002DAE8u; return; }  /* 0x8009F63C jal */
    R[4] = R[16] + R[0];  /* 0x8009F644 */
    { R[31] = 0x8009F650u; R[5] = R[0] + 24; psx_next = 0x8009BC84u; return; }  /* 0x8009F648 jal */
L_8009F650:;
    R[2] = 0x8011u << 16;  /* 0x8009F650 */
    R[4] = R[2] + 29992;  /* 0x8009F654 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 29992);  /* 0x8009F658 */
    R[2] = R[0] + 2;  /* 0x8009F65C */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F6F4; } }  /* 0x8009F660 */
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 226);  /* 0x8009F668 */
    R[5] = R[0] + 384;  /* 0x8009F66C */
    { uint32_t _c = (R[3] == R[5]); R[4] = R[0] + 128; if (_c) { goto L_8009F680; } }  /* 0x8009F670 */
    { uint32_t _c = (R[3] != R[4]); if (_c) { goto L_8009F6A4; } }  /* 0x8009F678 */
L_8009F680:;
    R[2] = lw_(R[16] + 220);  /* 0x8009F680 */
    R[3] = lw_(R[16] + 24);  /* 0x8009F684 */
    R[2] = lw_(R[2] + 24);  /* 0x8009F688 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009F690 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 256; if (_c) { goto L_8009F700; } }  /* 0x8009F694 */
    { sh_(R[16] + 6, R[0]); goto L_8009F704; }  /* 0x8009F69C j */
L_8009F6A4:;
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 256; if (_c) { goto L_8009F6B4; } }  /* 0x8009F6A4 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F6E0; } }  /* 0x8009F6AC */
L_8009F6B4:;
    R[2] = lw_(R[16] + 220);  /* 0x8009F6B4 */
    R[3] = lw_(R[16] + 32);  /* 0x8009F6B8 */
    R[2] = lw_(R[2] + 32);  /* 0x8009F6BC */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009F6C4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F6D8; } }  /* 0x8009F6C8 */
    { sh_(R[16] + 6, R[4]); goto L_8009F704; }  /* 0x8009F6D0 j */
L_8009F6D8:;
    { sh_(R[16] + 6, R[5]); goto L_8009F704; }  /* 0x8009F6D8 j */
L_8009F6E0:;
    R[4] = 0x8008u << 16;  /* 0x8009F6E0 */
    { R[31] = 0x8009F6ECu; R[4] = R[4] + 8660; psx_next = 0x8001BBF8u; return; }  /* 0x8009F6E4 jal */
    { goto L_8009F704; }  /* 0x8009F6EC j */
L_8009F6F4:;
    R[4] = lw_(R[16] + 220);  /* 0x8009F6F4 */
    { R[31] = 0x8009F700u; R[5] = R[16] + R[0]; psx_next = 0x8008DC60u; return; }  /* 0x8009F6F8 jal */
L_8009F700:;
    sh_(R[16] + 6, R[2]);  /* 0x8009F700 */
L_8009F704:;
    R[5] = lh_(R[16] + 6);  /* 0x8009F704 */
    R[4] = R[16] + R[0];  /* 0x8009F708 */
    R[5] = R[5] - 256;  /* 0x8009F70C */
    { R[31] = 0x8009F718u; R[5] = R[5] & 0x1FF; psx_next = 0x8008D114u; return; }  /* 0x8009F710 jal */
    R[2] = 0x8013u << 16;  /* 0x8009F718 */
    sw_(R[2] + -29556, R[0]);  /* 0x8009F71C */
    R[2] = lb_(R[16] + 781);  /* 0x8009F720 */
    R[2] = R[2] | 0x80;  /* 0x8009F728 */
    { sb_(R[16] + 781, R[2]); goto L_8009F7C8; }  /* 0x8009F72C j */
L_8009F734:;
    { R[31] = 0x8009F73Cu; R[4] = R[0] + 1; psx_next = 0x800905D4u; return; }  /* 0x8009F734 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F73C */
    { R[31] = 0x8009F748u; R[4] = R[0] + 39; psx_next = 0x8002DAE8u; return; }  /* 0x8009F740 jal */
    R[4] = R[16] + R[0];  /* 0x8009F748 */
    { R[31] = 0x8009F754u; R[5] = R[0] + 25; psx_next = 0x8009BC84u; return; }  /* 0x8009F74C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F754 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_bb(); goto L_8009F650; } }  /* 0x8009F75C */
    R[2] = 0x8012u << 16;  /* 0x8009F764 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F768 */
    { R[2] = R[0] | 0xE8B7; goto L_8009F7B0; }  /* 0x8009F76C j */
L_8009F774:;
    { R[31] = 0x8009F77Cu; R[4] = R[0] + 2; psx_next = 0x800905D4u; return; }  /* 0x8009F774 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F77C */
    { R[31] = 0x8009F788u; R[4] = R[0] + 40; psx_next = 0x8002DAE8u; return; }  /* 0x8009F780 jal */
    R[4] = R[16] + R[0];  /* 0x8009F788 */
    { R[31] = 0x8009F794u; R[5] = R[0] + 26; psx_next = 0x8009BC84u; return; }  /* 0x8009F78C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F794 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_bb(); goto L_8009F650; } }  /* 0x8009F79C */
    R[2] = 0x8012u << 16;  /* 0x8009F7A4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F7A8 */
    R[2] = R[0] + 29787;  /* 0x8009F7AC */
L_8009F7B0:;
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009F7B0 */
    { sw_(R[16] + 140, R[2]); psx_bb(); goto L_8009F650; }  /* 0x8009F7B4 j */
L_8009F7BC:;
    R[4] = R[16] + R[0];  /* 0x8009F7BC */
    { R[31] = 0x8009F7C8u; R[5] = R[0] + 29; psx_next = 0x8009BC84u; return; }  /* 0x8009F7C0 jal */
L_8009F7C8:;
    sb_(R[16] + 787, R[0]);  /* 0x8009F7C8 */
    R[31] = lw_(R[29] + 24);  /* 0x8009F7CC */
    R[17] = lw_(R[29] + 20);  /* 0x8009F7D0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F7D4 */
    R[2] = R[0] + 1;  /* 0x8009F7D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F7DC jr ra */
}

void g0_8009F5DC(void) {
    R[4] = R[16] + R[0];  /* 0x8009F5DC */
    R[5] = R[0] + 2;  /* 0x8009F5E0 */
    { R[31] = 0x8009F5ECu; R[17] = R[2] + R[0]; psx_next = 0x8009C12Cu; return; }  /* 0x8009F5E4 jal */
    R[3] = 0x8013u << 16;  /* 0x8009F5EC */
    R[2] = R[0] - 1;  /* 0x8009F5F0 */
    sh_(R[3] + -29476, R[2]);  /* 0x8009F5F4 */
    R[2] = 0x8013u << 16;  /* 0x8009F5F8 */
    sh_(R[2] + -29606, R[0]);  /* 0x8009F5FC */
    R[2] = R[0] + 9;  /* 0x8009F600 */
    { uint32_t _c = (R[17] == R[2]); R[2] = ((int32_t)R[17] < 10); if (_c) { goto L_8009F7BC; } }  /* 0x8009F604 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009F624; } }  /* 0x8009F60C */
    { uint32_t _c = (R[17] == R[2]); if (_c) { goto L_8009F734; } }  /* 0x8009F614 */
    { goto L_8009F630; }  /* 0x8009F61C j */
L_8009F624:;
    R[2] = R[0] + 10;  /* 0x8009F624 */
    { uint32_t _c = (R[17] == R[2]); if (_c) { goto L_8009F774; } }  /* 0x8009F628 */
L_8009F630:;
    { R[31] = 0x8009F638u; R[4] = R[0] + R[0]; psx_next = 0x800905D4u; return; }  /* 0x8009F630 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F638 */
    { R[31] = 0x8009F644u; R[4] = R[0] + 38; psx_next = 0x8002DAE8u; return; }  /* 0x8009F63C jal */
    R[4] = R[16] + R[0];  /* 0x8009F644 */
    { R[31] = 0x8009F650u; R[5] = R[0] + 24; psx_next = 0x8009BC84u; return; }  /* 0x8009F648 jal */
L_8009F650:;
    R[2] = 0x8011u << 16;  /* 0x8009F650 */
    R[4] = R[2] + 29992;  /* 0x8009F654 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 29992);  /* 0x8009F658 */
    R[2] = R[0] + 2;  /* 0x8009F65C */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F6F4; } }  /* 0x8009F660 */
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 226);  /* 0x8009F668 */
    R[5] = R[0] + 384;  /* 0x8009F66C */
    { uint32_t _c = (R[3] == R[5]); R[4] = R[0] + 128; if (_c) { goto L_8009F680; } }  /* 0x8009F670 */
    { uint32_t _c = (R[3] != R[4]); if (_c) { goto L_8009F6A4; } }  /* 0x8009F678 */
L_8009F680:;
    R[2] = lw_(R[16] + 220);  /* 0x8009F680 */
    R[3] = lw_(R[16] + 24);  /* 0x8009F684 */
    R[2] = lw_(R[2] + 24);  /* 0x8009F688 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009F690 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 256; if (_c) { goto L_8009F700; } }  /* 0x8009F694 */
    { sh_(R[16] + 6, R[0]); goto L_8009F704; }  /* 0x8009F69C j */
L_8009F6A4:;
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 256; if (_c) { goto L_8009F6B4; } }  /* 0x8009F6A4 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F6E0; } }  /* 0x8009F6AC */
L_8009F6B4:;
    R[2] = lw_(R[16] + 220);  /* 0x8009F6B4 */
    R[3] = lw_(R[16] + 32);  /* 0x8009F6B8 */
    R[2] = lw_(R[2] + 32);  /* 0x8009F6BC */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009F6C4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F6D8; } }  /* 0x8009F6C8 */
    { sh_(R[16] + 6, R[4]); goto L_8009F704; }  /* 0x8009F6D0 j */
L_8009F6D8:;
    { sh_(R[16] + 6, R[5]); goto L_8009F704; }  /* 0x8009F6D8 j */
L_8009F6E0:;
    R[4] = 0x8008u << 16;  /* 0x8009F6E0 */
    { R[31] = 0x8009F6ECu; R[4] = R[4] + 8660; psx_next = 0x8001BBF8u; return; }  /* 0x8009F6E4 jal */
    { goto L_8009F704; }  /* 0x8009F6EC j */
L_8009F6F4:;
    R[4] = lw_(R[16] + 220);  /* 0x8009F6F4 */
    { R[31] = 0x8009F700u; R[5] = R[16] + R[0]; psx_next = 0x8008DC60u; return; }  /* 0x8009F6F8 jal */
L_8009F700:;
    sh_(R[16] + 6, R[2]);  /* 0x8009F700 */
L_8009F704:;
    R[5] = lh_(R[16] + 6);  /* 0x8009F704 */
    R[4] = R[16] + R[0];  /* 0x8009F708 */
    R[5] = R[5] - 256;  /* 0x8009F70C */
    { R[31] = 0x8009F718u; R[5] = R[5] & 0x1FF; psx_next = 0x8008D114u; return; }  /* 0x8009F710 jal */
    R[2] = 0x8013u << 16;  /* 0x8009F718 */
    sw_(R[2] + -29556, R[0]);  /* 0x8009F71C */
    R[2] = lb_(R[16] + 781);  /* 0x8009F720 */
    R[2] = R[2] | 0x80;  /* 0x8009F728 */
    { sb_(R[16] + 781, R[2]); goto L_8009F7C8; }  /* 0x8009F72C j */
L_8009F734:;
    { R[31] = 0x8009F73Cu; R[4] = R[0] + 1; psx_next = 0x800905D4u; return; }  /* 0x8009F734 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F73C */
    { R[31] = 0x8009F748u; R[4] = R[0] + 39; psx_next = 0x8002DAE8u; return; }  /* 0x8009F740 jal */
    R[4] = R[16] + R[0];  /* 0x8009F748 */
    { R[31] = 0x8009F754u; R[5] = R[0] + 25; psx_next = 0x8009BC84u; return; }  /* 0x8009F74C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F754 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_bb(); goto L_8009F650; } }  /* 0x8009F75C */
    R[2] = 0x8012u << 16;  /* 0x8009F764 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F768 */
    { R[2] = R[0] | 0xE8B7; goto L_8009F7B0; }  /* 0x8009F76C j */
L_8009F774:;
    { R[31] = 0x8009F77Cu; R[4] = R[0] + 2; psx_next = 0x800905D4u; return; }  /* 0x8009F774 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F77C */
    { R[31] = 0x8009F788u; R[4] = R[0] + 40; psx_next = 0x8002DAE8u; return; }  /* 0x8009F780 jal */
    R[4] = R[16] + R[0];  /* 0x8009F788 */
    { R[31] = 0x8009F794u; R[5] = R[0] + 26; psx_next = 0x8009BC84u; return; }  /* 0x8009F78C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F794 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_bb(); goto L_8009F650; } }  /* 0x8009F79C */
    R[2] = 0x8012u << 16;  /* 0x8009F7A4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F7A8 */
    R[2] = R[0] + 29787;  /* 0x8009F7AC */
L_8009F7B0:;
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009F7B0 */
    { sw_(R[16] + 140, R[2]); psx_bb(); goto L_8009F650; }  /* 0x8009F7B4 j */
L_8009F7BC:;
    R[4] = R[16] + R[0];  /* 0x8009F7BC */
    { R[31] = 0x8009F7C8u; R[5] = R[0] + 29; psx_next = 0x8009BC84u; return; }  /* 0x8009F7C0 jal */
L_8009F7C8:;
    sb_(R[16] + 787, R[0]);  /* 0x8009F7C8 */
    R[31] = lw_(R[29] + 24);  /* 0x8009F7CC */
    R[17] = lw_(R[29] + 20);  /* 0x8009F7D0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F7D4 */
    R[2] = R[0] + 1;  /* 0x8009F7D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F7DC jr ra */
}

void g0_8009F5EC(void) {
    R[3] = 0x8013u << 16;  /* 0x8009F5EC */
    R[2] = R[0] - 1;  /* 0x8009F5F0 */
    sh_(R[3] + -29476, R[2]);  /* 0x8009F5F4 */
    R[2] = 0x8013u << 16;  /* 0x8009F5F8 */
    sh_(R[2] + -29606, R[0]);  /* 0x8009F5FC */
    R[2] = R[0] + 9;  /* 0x8009F600 */
    { uint32_t _c = (R[17] == R[2]); R[2] = ((int32_t)R[17] < 10); if (_c) { goto L_8009F7BC; } }  /* 0x8009F604 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009F624; } }  /* 0x8009F60C */
    { uint32_t _c = (R[17] == R[2]); if (_c) { goto L_8009F734; } }  /* 0x8009F614 */
    { goto L_8009F630; }  /* 0x8009F61C j */
L_8009F624:;
    R[2] = R[0] + 10;  /* 0x8009F624 */
    { uint32_t _c = (R[17] == R[2]); if (_c) { goto L_8009F774; } }  /* 0x8009F628 */
L_8009F630:;
    { R[31] = 0x8009F638u; R[4] = R[0] + R[0]; psx_next = 0x800905D4u; return; }  /* 0x8009F630 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F638 */
    { R[31] = 0x8009F644u; R[4] = R[0] + 38; psx_next = 0x8002DAE8u; return; }  /* 0x8009F63C jal */
    R[4] = R[16] + R[0];  /* 0x8009F644 */
    { R[31] = 0x8009F650u; R[5] = R[0] + 24; psx_next = 0x8009BC84u; return; }  /* 0x8009F648 jal */
L_8009F650:;
    R[2] = 0x8011u << 16;  /* 0x8009F650 */
    R[4] = R[2] + 29992;  /* 0x8009F654 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 29992);  /* 0x8009F658 */
    R[2] = R[0] + 2;  /* 0x8009F65C */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F6F4; } }  /* 0x8009F660 */
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 226);  /* 0x8009F668 */
    R[5] = R[0] + 384;  /* 0x8009F66C */
    { uint32_t _c = (R[3] == R[5]); R[4] = R[0] + 128; if (_c) { goto L_8009F680; } }  /* 0x8009F670 */
    { uint32_t _c = (R[3] != R[4]); if (_c) { goto L_8009F6A4; } }  /* 0x8009F678 */
L_8009F680:;
    R[2] = lw_(R[16] + 220);  /* 0x8009F680 */
    R[3] = lw_(R[16] + 24);  /* 0x8009F684 */
    R[2] = lw_(R[2] + 24);  /* 0x8009F688 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009F690 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 256; if (_c) { goto L_8009F700; } }  /* 0x8009F694 */
    { sh_(R[16] + 6, R[0]); goto L_8009F704; }  /* 0x8009F69C j */
L_8009F6A4:;
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 256; if (_c) { goto L_8009F6B4; } }  /* 0x8009F6A4 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F6E0; } }  /* 0x8009F6AC */
L_8009F6B4:;
    R[2] = lw_(R[16] + 220);  /* 0x8009F6B4 */
    R[3] = lw_(R[16] + 32);  /* 0x8009F6B8 */
    R[2] = lw_(R[2] + 32);  /* 0x8009F6BC */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009F6C4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F6D8; } }  /* 0x8009F6C8 */
    { sh_(R[16] + 6, R[4]); goto L_8009F704; }  /* 0x8009F6D0 j */
L_8009F6D8:;
    { sh_(R[16] + 6, R[5]); goto L_8009F704; }  /* 0x8009F6D8 j */
L_8009F6E0:;
    R[4] = 0x8008u << 16;  /* 0x8009F6E0 */
    { R[31] = 0x8009F6ECu; R[4] = R[4] + 8660; psx_next = 0x8001BBF8u; return; }  /* 0x8009F6E4 jal */
    { goto L_8009F704; }  /* 0x8009F6EC j */
L_8009F6F4:;
    R[4] = lw_(R[16] + 220);  /* 0x8009F6F4 */
    { R[31] = 0x8009F700u; R[5] = R[16] + R[0]; psx_next = 0x8008DC60u; return; }  /* 0x8009F6F8 jal */
L_8009F700:;
    sh_(R[16] + 6, R[2]);  /* 0x8009F700 */
L_8009F704:;
    R[5] = lh_(R[16] + 6);  /* 0x8009F704 */
    R[4] = R[16] + R[0];  /* 0x8009F708 */
    R[5] = R[5] - 256;  /* 0x8009F70C */
    { R[31] = 0x8009F718u; R[5] = R[5] & 0x1FF; psx_next = 0x8008D114u; return; }  /* 0x8009F710 jal */
    R[2] = 0x8013u << 16;  /* 0x8009F718 */
    sw_(R[2] + -29556, R[0]);  /* 0x8009F71C */
    R[2] = lb_(R[16] + 781);  /* 0x8009F720 */
    R[2] = R[2] | 0x80;  /* 0x8009F728 */
    { sb_(R[16] + 781, R[2]); goto L_8009F7C8; }  /* 0x8009F72C j */
L_8009F734:;
    { R[31] = 0x8009F73Cu; R[4] = R[0] + 1; psx_next = 0x800905D4u; return; }  /* 0x8009F734 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F73C */
    { R[31] = 0x8009F748u; R[4] = R[0] + 39; psx_next = 0x8002DAE8u; return; }  /* 0x8009F740 jal */
    R[4] = R[16] + R[0];  /* 0x8009F748 */
    { R[31] = 0x8009F754u; R[5] = R[0] + 25; psx_next = 0x8009BC84u; return; }  /* 0x8009F74C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F754 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_bb(); goto L_8009F650; } }  /* 0x8009F75C */
    R[2] = 0x8012u << 16;  /* 0x8009F764 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F768 */
    { R[2] = R[0] | 0xE8B7; goto L_8009F7B0; }  /* 0x8009F76C j */
L_8009F774:;
    { R[31] = 0x8009F77Cu; R[4] = R[0] + 2; psx_next = 0x800905D4u; return; }  /* 0x8009F774 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F77C */
    { R[31] = 0x8009F788u; R[4] = R[0] + 40; psx_next = 0x8002DAE8u; return; }  /* 0x8009F780 jal */
    R[4] = R[16] + R[0];  /* 0x8009F788 */
    { R[31] = 0x8009F794u; R[5] = R[0] + 26; psx_next = 0x8009BC84u; return; }  /* 0x8009F78C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F794 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_bb(); goto L_8009F650; } }  /* 0x8009F79C */
    R[2] = 0x8012u << 16;  /* 0x8009F7A4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F7A8 */
    R[2] = R[0] + 29787;  /* 0x8009F7AC */
L_8009F7B0:;
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009F7B0 */
    { sw_(R[16] + 140, R[2]); psx_bb(); goto L_8009F650; }  /* 0x8009F7B4 j */
L_8009F7BC:;
    R[4] = R[16] + R[0];  /* 0x8009F7BC */
    { R[31] = 0x8009F7C8u; R[5] = R[0] + 29; psx_next = 0x8009BC84u; return; }  /* 0x8009F7C0 jal */
L_8009F7C8:;
    sb_(R[16] + 787, R[0]);  /* 0x8009F7C8 */
    R[31] = lw_(R[29] + 24);  /* 0x8009F7CC */
    R[17] = lw_(R[29] + 20);  /* 0x8009F7D0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F7D4 */
    R[2] = R[0] + 1;  /* 0x8009F7D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F7DC jr ra */
}

void g0_8009F638(void) {
    R[5] = lh_(R[16] + 2);  /* 0x8009F638 */
    { R[31] = 0x8009F644u; R[4] = R[0] + 38; psx_next = 0x8002DAE8u; return; }  /* 0x8009F63C jal */
    R[4] = R[16] + R[0];  /* 0x8009F644 */
    { R[31] = 0x8009F650u; R[5] = R[0] + 24; psx_next = 0x8009BC84u; return; }  /* 0x8009F648 jal */
L_8009F650:;
    R[2] = 0x8011u << 16;  /* 0x8009F650 */
    R[4] = R[2] + 29992;  /* 0x8009F654 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 29992);  /* 0x8009F658 */
    R[2] = R[0] + 2;  /* 0x8009F65C */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F6F4; } }  /* 0x8009F660 */
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 226);  /* 0x8009F668 */
    R[5] = R[0] + 384;  /* 0x8009F66C */
    { uint32_t _c = (R[3] == R[5]); R[4] = R[0] + 128; if (_c) { goto L_8009F680; } }  /* 0x8009F670 */
    { uint32_t _c = (R[3] != R[4]); if (_c) { goto L_8009F6A4; } }  /* 0x8009F678 */
L_8009F680:;
    R[2] = lw_(R[16] + 220);  /* 0x8009F680 */
    R[3] = lw_(R[16] + 24);  /* 0x8009F684 */
    R[2] = lw_(R[2] + 24);  /* 0x8009F688 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009F690 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 256; if (_c) { goto L_8009F700; } }  /* 0x8009F694 */
    { sh_(R[16] + 6, R[0]); goto L_8009F704; }  /* 0x8009F69C j */
L_8009F6A4:;
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 256; if (_c) { goto L_8009F6B4; } }  /* 0x8009F6A4 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F6E0; } }  /* 0x8009F6AC */
L_8009F6B4:;
    R[2] = lw_(R[16] + 220);  /* 0x8009F6B4 */
    R[3] = lw_(R[16] + 32);  /* 0x8009F6B8 */
    R[2] = lw_(R[2] + 32);  /* 0x8009F6BC */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009F6C4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F6D8; } }  /* 0x8009F6C8 */
    { sh_(R[16] + 6, R[4]); goto L_8009F704; }  /* 0x8009F6D0 j */
L_8009F6D8:;
    { sh_(R[16] + 6, R[5]); goto L_8009F704; }  /* 0x8009F6D8 j */
L_8009F6E0:;
    R[4] = 0x8008u << 16;  /* 0x8009F6E0 */
    { R[31] = 0x8009F6ECu; R[4] = R[4] + 8660; psx_next = 0x8001BBF8u; return; }  /* 0x8009F6E4 jal */
    { goto L_8009F704; }  /* 0x8009F6EC j */
L_8009F6F4:;
    R[4] = lw_(R[16] + 220);  /* 0x8009F6F4 */
    { R[31] = 0x8009F700u; R[5] = R[16] + R[0]; psx_next = 0x8008DC60u; return; }  /* 0x8009F6F8 jal */
L_8009F700:;
    sh_(R[16] + 6, R[2]);  /* 0x8009F700 */
L_8009F704:;
    R[5] = lh_(R[16] + 6);  /* 0x8009F704 */
    R[4] = R[16] + R[0];  /* 0x8009F708 */
    R[5] = R[5] - 256;  /* 0x8009F70C */
    { R[31] = 0x8009F718u; R[5] = R[5] & 0x1FF; psx_next = 0x8008D114u; return; }  /* 0x8009F710 jal */
    R[2] = 0x8013u << 16;  /* 0x8009F718 */
    sw_(R[2] + -29556, R[0]);  /* 0x8009F71C */
    R[2] = lb_(R[16] + 781);  /* 0x8009F720 */
    R[2] = R[2] | 0x80;  /* 0x8009F728 */
    { sb_(R[16] + 781, R[2]); goto L_8009F7C8; }  /* 0x8009F72C j */
    { R[31] = 0x8009F73Cu; R[4] = R[0] + 1; psx_next = 0x800905D4u; return; }  /* 0x8009F734 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F73C */
    { R[31] = 0x8009F748u; R[4] = R[0] + 39; psx_next = 0x8002DAE8u; return; }  /* 0x8009F740 jal */
    R[4] = R[16] + R[0];  /* 0x8009F748 */
    { R[31] = 0x8009F754u; R[5] = R[0] + 25; psx_next = 0x8009BC84u; return; }  /* 0x8009F74C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F754 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_bb(); goto L_8009F650; } }  /* 0x8009F75C */
    R[2] = 0x8012u << 16;  /* 0x8009F764 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F768 */
    { R[2] = R[0] | 0xE8B7; goto L_8009F7B0; }  /* 0x8009F76C j */
    { R[31] = 0x8009F77Cu; R[4] = R[0] + 2; psx_next = 0x800905D4u; return; }  /* 0x8009F774 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F77C */
    { R[31] = 0x8009F788u; R[4] = R[0] + 40; psx_next = 0x8002DAE8u; return; }  /* 0x8009F780 jal */
    R[4] = R[16] + R[0];  /* 0x8009F788 */
    { R[31] = 0x8009F794u; R[5] = R[0] + 26; psx_next = 0x8009BC84u; return; }  /* 0x8009F78C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F794 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_bb(); goto L_8009F650; } }  /* 0x8009F79C */
    R[2] = 0x8012u << 16;  /* 0x8009F7A4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F7A8 */
    R[2] = R[0] + 29787;  /* 0x8009F7AC */
L_8009F7B0:;
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009F7B0 */
    { sw_(R[16] + 140, R[2]); psx_bb(); goto L_8009F650; }  /* 0x8009F7B4 j */
    R[4] = R[16] + R[0];  /* 0x8009F7BC */
    { R[31] = 0x8009F7C8u; R[5] = R[0] + 29; psx_next = 0x8009BC84u; return; }  /* 0x8009F7C0 jal */
L_8009F7C8:;
    sb_(R[16] + 787, R[0]);  /* 0x8009F7C8 */
    R[31] = lw_(R[29] + 24);  /* 0x8009F7CC */
    R[17] = lw_(R[29] + 20);  /* 0x8009F7D0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F7D4 */
    R[2] = R[0] + 1;  /* 0x8009F7D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F7DC jr ra */
}

void g0_8009F644(void) {
    R[4] = R[16] + R[0];  /* 0x8009F644 */
    { R[31] = 0x8009F650u; R[5] = R[0] + 24; psx_next = 0x8009BC84u; return; }  /* 0x8009F648 jal */
L_8009F650:;
    R[2] = 0x8011u << 16;  /* 0x8009F650 */
    R[4] = R[2] + 29992;  /* 0x8009F654 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 29992);  /* 0x8009F658 */
    R[2] = R[0] + 2;  /* 0x8009F65C */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F6F4; } }  /* 0x8009F660 */
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 226);  /* 0x8009F668 */
    R[5] = R[0] + 384;  /* 0x8009F66C */
    { uint32_t _c = (R[3] == R[5]); R[4] = R[0] + 128; if (_c) { goto L_8009F680; } }  /* 0x8009F670 */
    { uint32_t _c = (R[3] != R[4]); if (_c) { goto L_8009F6A4; } }  /* 0x8009F678 */
L_8009F680:;
    R[2] = lw_(R[16] + 220);  /* 0x8009F680 */
    R[3] = lw_(R[16] + 24);  /* 0x8009F684 */
    R[2] = lw_(R[2] + 24);  /* 0x8009F688 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009F690 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 256; if (_c) { goto L_8009F700; } }  /* 0x8009F694 */
    { sh_(R[16] + 6, R[0]); goto L_8009F704; }  /* 0x8009F69C j */
L_8009F6A4:;
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 256; if (_c) { goto L_8009F6B4; } }  /* 0x8009F6A4 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F6E0; } }  /* 0x8009F6AC */
L_8009F6B4:;
    R[2] = lw_(R[16] + 220);  /* 0x8009F6B4 */
    R[3] = lw_(R[16] + 32);  /* 0x8009F6B8 */
    R[2] = lw_(R[2] + 32);  /* 0x8009F6BC */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009F6C4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F6D8; } }  /* 0x8009F6C8 */
    { sh_(R[16] + 6, R[4]); goto L_8009F704; }  /* 0x8009F6D0 j */
L_8009F6D8:;
    { sh_(R[16] + 6, R[5]); goto L_8009F704; }  /* 0x8009F6D8 j */
L_8009F6E0:;
    R[4] = 0x8008u << 16;  /* 0x8009F6E0 */
    { R[31] = 0x8009F6ECu; R[4] = R[4] + 8660; psx_next = 0x8001BBF8u; return; }  /* 0x8009F6E4 jal */
    { goto L_8009F704; }  /* 0x8009F6EC j */
L_8009F6F4:;
    R[4] = lw_(R[16] + 220);  /* 0x8009F6F4 */
    { R[31] = 0x8009F700u; R[5] = R[16] + R[0]; psx_next = 0x8008DC60u; return; }  /* 0x8009F6F8 jal */
L_8009F700:;
    sh_(R[16] + 6, R[2]);  /* 0x8009F700 */
L_8009F704:;
    R[5] = lh_(R[16] + 6);  /* 0x8009F704 */
    R[4] = R[16] + R[0];  /* 0x8009F708 */
    R[5] = R[5] - 256;  /* 0x8009F70C */
    { R[31] = 0x8009F718u; R[5] = R[5] & 0x1FF; psx_next = 0x8008D114u; return; }  /* 0x8009F710 jal */
    R[2] = 0x8013u << 16;  /* 0x8009F718 */
    sw_(R[2] + -29556, R[0]);  /* 0x8009F71C */
    R[2] = lb_(R[16] + 781);  /* 0x8009F720 */
    R[2] = R[2] | 0x80;  /* 0x8009F728 */
    { sb_(R[16] + 781, R[2]); goto L_8009F7C8; }  /* 0x8009F72C j */
    { R[31] = 0x8009F73Cu; R[4] = R[0] + 1; psx_next = 0x800905D4u; return; }  /* 0x8009F734 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F73C */
    { R[31] = 0x8009F748u; R[4] = R[0] + 39; psx_next = 0x8002DAE8u; return; }  /* 0x8009F740 jal */
    R[4] = R[16] + R[0];  /* 0x8009F748 */
    { R[31] = 0x8009F754u; R[5] = R[0] + 25; psx_next = 0x8009BC84u; return; }  /* 0x8009F74C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F754 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_bb(); goto L_8009F650; } }  /* 0x8009F75C */
    R[2] = 0x8012u << 16;  /* 0x8009F764 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F768 */
    { R[2] = R[0] | 0xE8B7; goto L_8009F7B0; }  /* 0x8009F76C j */
    { R[31] = 0x8009F77Cu; R[4] = R[0] + 2; psx_next = 0x800905D4u; return; }  /* 0x8009F774 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F77C */
    { R[31] = 0x8009F788u; R[4] = R[0] + 40; psx_next = 0x8002DAE8u; return; }  /* 0x8009F780 jal */
    R[4] = R[16] + R[0];  /* 0x8009F788 */
    { R[31] = 0x8009F794u; R[5] = R[0] + 26; psx_next = 0x8009BC84u; return; }  /* 0x8009F78C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F794 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_bb(); goto L_8009F650; } }  /* 0x8009F79C */
    R[2] = 0x8012u << 16;  /* 0x8009F7A4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F7A8 */
    R[2] = R[0] + 29787;  /* 0x8009F7AC */
L_8009F7B0:;
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009F7B0 */
    { sw_(R[16] + 140, R[2]); psx_bb(); goto L_8009F650; }  /* 0x8009F7B4 j */
    R[4] = R[16] + R[0];  /* 0x8009F7BC */
    { R[31] = 0x8009F7C8u; R[5] = R[0] + 29; psx_next = 0x8009BC84u; return; }  /* 0x8009F7C0 jal */
L_8009F7C8:;
    sb_(R[16] + 787, R[0]);  /* 0x8009F7C8 */
    R[31] = lw_(R[29] + 24);  /* 0x8009F7CC */
    R[17] = lw_(R[29] + 20);  /* 0x8009F7D0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F7D4 */
    R[2] = R[0] + 1;  /* 0x8009F7D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F7DC jr ra */
}

void g0_8009F650(void) {
L_8009F650:;
    R[2] = 0x8011u << 16;  /* 0x8009F650 */
    R[4] = R[2] + 29992;  /* 0x8009F654 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 29992);  /* 0x8009F658 */
    R[2] = R[0] + 2;  /* 0x8009F65C */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F6F4; } }  /* 0x8009F660 */
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 226);  /* 0x8009F668 */
    R[5] = R[0] + 384;  /* 0x8009F66C */
    { uint32_t _c = (R[3] == R[5]); R[4] = R[0] + 128; if (_c) { goto L_8009F680; } }  /* 0x8009F670 */
    { uint32_t _c = (R[3] != R[4]); if (_c) { goto L_8009F6A4; } }  /* 0x8009F678 */
L_8009F680:;
    R[2] = lw_(R[16] + 220);  /* 0x8009F680 */
    R[3] = lw_(R[16] + 24);  /* 0x8009F684 */
    R[2] = lw_(R[2] + 24);  /* 0x8009F688 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009F690 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 256; if (_c) { goto L_8009F700; } }  /* 0x8009F694 */
    { sh_(R[16] + 6, R[0]); goto L_8009F704; }  /* 0x8009F69C j */
L_8009F6A4:;
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 256; if (_c) { goto L_8009F6B4; } }  /* 0x8009F6A4 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F6E0; } }  /* 0x8009F6AC */
L_8009F6B4:;
    R[2] = lw_(R[16] + 220);  /* 0x8009F6B4 */
    R[3] = lw_(R[16] + 32);  /* 0x8009F6B8 */
    R[2] = lw_(R[2] + 32);  /* 0x8009F6BC */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009F6C4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F6D8; } }  /* 0x8009F6C8 */
    { sh_(R[16] + 6, R[4]); goto L_8009F704; }  /* 0x8009F6D0 j */
L_8009F6D8:;
    { sh_(R[16] + 6, R[5]); goto L_8009F704; }  /* 0x8009F6D8 j */
L_8009F6E0:;
    R[4] = 0x8008u << 16;  /* 0x8009F6E0 */
    { R[31] = 0x8009F6ECu; R[4] = R[4] + 8660; psx_next = 0x8001BBF8u; return; }  /* 0x8009F6E4 jal */
    { goto L_8009F704; }  /* 0x8009F6EC j */
L_8009F6F4:;
    R[4] = lw_(R[16] + 220);  /* 0x8009F6F4 */
    { R[31] = 0x8009F700u; R[5] = R[16] + R[0]; psx_next = 0x8008DC60u; return; }  /* 0x8009F6F8 jal */
L_8009F700:;
    sh_(R[16] + 6, R[2]);  /* 0x8009F700 */
L_8009F704:;
    R[5] = lh_(R[16] + 6);  /* 0x8009F704 */
    R[4] = R[16] + R[0];  /* 0x8009F708 */
    R[5] = R[5] - 256;  /* 0x8009F70C */
    { R[31] = 0x8009F718u; R[5] = R[5] & 0x1FF; psx_next = 0x8008D114u; return; }  /* 0x8009F710 jal */
    R[2] = 0x8013u << 16;  /* 0x8009F718 */
    sw_(R[2] + -29556, R[0]);  /* 0x8009F71C */
    R[2] = lb_(R[16] + 781);  /* 0x8009F720 */
    R[2] = R[2] | 0x80;  /* 0x8009F728 */
    { sb_(R[16] + 781, R[2]); goto L_8009F7C8; }  /* 0x8009F72C j */
    { R[31] = 0x8009F73Cu; R[4] = R[0] + 1; psx_next = 0x800905D4u; return; }  /* 0x8009F734 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F73C */
    { R[31] = 0x8009F748u; R[4] = R[0] + 39; psx_next = 0x8002DAE8u; return; }  /* 0x8009F740 jal */
    R[4] = R[16] + R[0];  /* 0x8009F748 */
    { R[31] = 0x8009F754u; R[5] = R[0] + 25; psx_next = 0x8009BC84u; return; }  /* 0x8009F74C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F754 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_bb(); goto L_8009F650; } }  /* 0x8009F75C */
    R[2] = 0x8012u << 16;  /* 0x8009F764 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F768 */
    { R[2] = R[0] | 0xE8B7; goto L_8009F7B0; }  /* 0x8009F76C j */
    { R[31] = 0x8009F77Cu; R[4] = R[0] + 2; psx_next = 0x800905D4u; return; }  /* 0x8009F774 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F77C */
    { R[31] = 0x8009F788u; R[4] = R[0] + 40; psx_next = 0x8002DAE8u; return; }  /* 0x8009F780 jal */
    R[4] = R[16] + R[0];  /* 0x8009F788 */
    { R[31] = 0x8009F794u; R[5] = R[0] + 26; psx_next = 0x8009BC84u; return; }  /* 0x8009F78C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F794 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_bb(); goto L_8009F650; } }  /* 0x8009F79C */
    R[2] = 0x8012u << 16;  /* 0x8009F7A4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F7A8 */
    R[2] = R[0] + 29787;  /* 0x8009F7AC */
L_8009F7B0:;
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009F7B0 */
    { sw_(R[16] + 140, R[2]); psx_bb(); goto L_8009F650; }  /* 0x8009F7B4 j */
    R[4] = R[16] + R[0];  /* 0x8009F7BC */
    { R[31] = 0x8009F7C8u; R[5] = R[0] + 29; psx_next = 0x8009BC84u; return; }  /* 0x8009F7C0 jal */
L_8009F7C8:;
    sb_(R[16] + 787, R[0]);  /* 0x8009F7C8 */
    R[31] = lw_(R[29] + 24);  /* 0x8009F7CC */
    R[17] = lw_(R[29] + 20);  /* 0x8009F7D0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F7D4 */
    R[2] = R[0] + 1;  /* 0x8009F7D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F7DC jr ra */
}

void g0_8009F6EC(void) {
    { goto L_8009F704; }  /* 0x8009F6EC j */
    R[4] = lw_(R[16] + 220);  /* 0x8009F6F4 */
    { R[31] = 0x8009F700u; R[5] = R[16] + R[0]; psx_next = 0x8008DC60u; return; }  /* 0x8009F6F8 jal */
    sh_(R[16] + 6, R[2]);  /* 0x8009F700 */
L_8009F704:;
    R[5] = lh_(R[16] + 6);  /* 0x8009F704 */
    R[4] = R[16] + R[0];  /* 0x8009F708 */
    R[5] = R[5] - 256;  /* 0x8009F70C */
    { R[31] = 0x8009F718u; R[5] = R[5] & 0x1FF; psx_next = 0x8008D114u; return; }  /* 0x8009F710 jal */
    R[2] = 0x8013u << 16;  /* 0x8009F718 */
    sw_(R[2] + -29556, R[0]);  /* 0x8009F71C */
    R[2] = lb_(R[16] + 781);  /* 0x8009F720 */
    R[2] = R[2] | 0x80;  /* 0x8009F728 */
    { sb_(R[16] + 781, R[2]); goto L_8009F7C8; }  /* 0x8009F72C j */
    { R[31] = 0x8009F73Cu; R[4] = R[0] + 1; psx_next = 0x800905D4u; return; }  /* 0x8009F734 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F73C */
    { R[31] = 0x8009F748u; R[4] = R[0] + 39; psx_next = 0x8002DAE8u; return; }  /* 0x8009F740 jal */
    R[4] = R[16] + R[0];  /* 0x8009F748 */
    { R[31] = 0x8009F754u; R[5] = R[0] + 25; psx_next = 0x8009BC84u; return; }  /* 0x8009F74C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F754 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_next = 0x8009F650u; return; } }  /* 0x8009F75C b extern */
    R[2] = 0x8012u << 16;  /* 0x8009F764 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F768 */
    { R[2] = R[0] | 0xE8B7; goto L_8009F7B0; }  /* 0x8009F76C j */
    { R[31] = 0x8009F77Cu; R[4] = R[0] + 2; psx_next = 0x800905D4u; return; }  /* 0x8009F774 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F77C */
    { R[31] = 0x8009F788u; R[4] = R[0] + 40; psx_next = 0x8002DAE8u; return; }  /* 0x8009F780 jal */
    R[4] = R[16] + R[0];  /* 0x8009F788 */
    { R[31] = 0x8009F794u; R[5] = R[0] + 26; psx_next = 0x8009BC84u; return; }  /* 0x8009F78C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F794 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_next = 0x8009F650u; return; } }  /* 0x8009F79C b extern */
    R[2] = 0x8012u << 16;  /* 0x8009F7A4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F7A8 */
    R[2] = R[0] + 29787;  /* 0x8009F7AC */
L_8009F7B0:;
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009F7B0 */
    { sw_(R[16] + 140, R[2]); psx_next = 0x8009F650u; return; }  /* 0x8009F7B4 j extern */
    R[4] = R[16] + R[0];  /* 0x8009F7BC */
    { R[31] = 0x8009F7C8u; R[5] = R[0] + 29; psx_next = 0x8009BC84u; return; }  /* 0x8009F7C0 jal */
L_8009F7C8:;
    sb_(R[16] + 787, R[0]);  /* 0x8009F7C8 */
    R[31] = lw_(R[29] + 24);  /* 0x8009F7CC */
    R[17] = lw_(R[29] + 20);  /* 0x8009F7D0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F7D4 */
    R[2] = R[0] + 1;  /* 0x8009F7D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F7DC jr ra */
}

void g0_8009F700(void) {
    sh_(R[16] + 6, R[2]);  /* 0x8009F700 */
    R[5] = lh_(R[16] + 6);  /* 0x8009F704 */
    R[4] = R[16] + R[0];  /* 0x8009F708 */
    R[5] = R[5] - 256;  /* 0x8009F70C */
    { R[31] = 0x8009F718u; R[5] = R[5] & 0x1FF; psx_next = 0x8008D114u; return; }  /* 0x8009F710 jal */
    R[2] = 0x8013u << 16;  /* 0x8009F718 */
    sw_(R[2] + -29556, R[0]);  /* 0x8009F71C */
    R[2] = lb_(R[16] + 781);  /* 0x8009F720 */
    R[2] = R[2] | 0x80;  /* 0x8009F728 */
    { sb_(R[16] + 781, R[2]); goto L_8009F7C8; }  /* 0x8009F72C j */
    { R[31] = 0x8009F73Cu; R[4] = R[0] + 1; psx_next = 0x800905D4u; return; }  /* 0x8009F734 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F73C */
    { R[31] = 0x8009F748u; R[4] = R[0] + 39; psx_next = 0x8002DAE8u; return; }  /* 0x8009F740 jal */
    R[4] = R[16] + R[0];  /* 0x8009F748 */
    { R[31] = 0x8009F754u; R[5] = R[0] + 25; psx_next = 0x8009BC84u; return; }  /* 0x8009F74C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F754 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_next = 0x8009F650u; return; } }  /* 0x8009F75C b extern */
    R[2] = 0x8012u << 16;  /* 0x8009F764 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F768 */
    { R[2] = R[0] | 0xE8B7; goto L_8009F7B0; }  /* 0x8009F76C j */
    { R[31] = 0x8009F77Cu; R[4] = R[0] + 2; psx_next = 0x800905D4u; return; }  /* 0x8009F774 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F77C */
    { R[31] = 0x8009F788u; R[4] = R[0] + 40; psx_next = 0x8002DAE8u; return; }  /* 0x8009F780 jal */
    R[4] = R[16] + R[0];  /* 0x8009F788 */
    { R[31] = 0x8009F794u; R[5] = R[0] + 26; psx_next = 0x8009BC84u; return; }  /* 0x8009F78C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F794 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_next = 0x8009F650u; return; } }  /* 0x8009F79C b extern */
    R[2] = 0x8012u << 16;  /* 0x8009F7A4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F7A8 */
    R[2] = R[0] + 29787;  /* 0x8009F7AC */
L_8009F7B0:;
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009F7B0 */
    { sw_(R[16] + 140, R[2]); psx_next = 0x8009F650u; return; }  /* 0x8009F7B4 j extern */
    R[4] = R[16] + R[0];  /* 0x8009F7BC */
    { R[31] = 0x8009F7C8u; R[5] = R[0] + 29; psx_next = 0x8009BC84u; return; }  /* 0x8009F7C0 jal */
L_8009F7C8:;
    sb_(R[16] + 787, R[0]);  /* 0x8009F7C8 */
    R[31] = lw_(R[29] + 24);  /* 0x8009F7CC */
    R[17] = lw_(R[29] + 20);  /* 0x8009F7D0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F7D4 */
    R[2] = R[0] + 1;  /* 0x8009F7D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F7DC jr ra */
}

void g0_8009F718(void) {
    R[2] = 0x8013u << 16;  /* 0x8009F718 */
    sw_(R[2] + -29556, R[0]);  /* 0x8009F71C */
    R[2] = lb_(R[16] + 781);  /* 0x8009F720 */
    R[2] = R[2] | 0x80;  /* 0x8009F728 */
    { sb_(R[16] + 781, R[2]); goto L_8009F7C8; }  /* 0x8009F72C j */
    { R[31] = 0x8009F73Cu; R[4] = R[0] + 1; psx_next = 0x800905D4u; return; }  /* 0x8009F734 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F73C */
    { R[31] = 0x8009F748u; R[4] = R[0] + 39; psx_next = 0x8002DAE8u; return; }  /* 0x8009F740 jal */
    R[4] = R[16] + R[0];  /* 0x8009F748 */
    { R[31] = 0x8009F754u; R[5] = R[0] + 25; psx_next = 0x8009BC84u; return; }  /* 0x8009F74C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F754 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_next = 0x8009F650u; return; } }  /* 0x8009F75C b extern */
    R[2] = 0x8012u << 16;  /* 0x8009F764 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F768 */
    { R[2] = R[0] | 0xE8B7; goto L_8009F7B0; }  /* 0x8009F76C j */
    { R[31] = 0x8009F77Cu; R[4] = R[0] + 2; psx_next = 0x800905D4u; return; }  /* 0x8009F774 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F77C */
    { R[31] = 0x8009F788u; R[4] = R[0] + 40; psx_next = 0x8002DAE8u; return; }  /* 0x8009F780 jal */
    R[4] = R[16] + R[0];  /* 0x8009F788 */
    { R[31] = 0x8009F794u; R[5] = R[0] + 26; psx_next = 0x8009BC84u; return; }  /* 0x8009F78C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F794 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_next = 0x8009F650u; return; } }  /* 0x8009F79C b extern */
    R[2] = 0x8012u << 16;  /* 0x8009F7A4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F7A8 */
    R[2] = R[0] + 29787;  /* 0x8009F7AC */
L_8009F7B0:;
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009F7B0 */
    { sw_(R[16] + 140, R[2]); psx_next = 0x8009F650u; return; }  /* 0x8009F7B4 j extern */
    R[4] = R[16] + R[0];  /* 0x8009F7BC */
    { R[31] = 0x8009F7C8u; R[5] = R[0] + 29; psx_next = 0x8009BC84u; return; }  /* 0x8009F7C0 jal */
L_8009F7C8:;
    sb_(R[16] + 787, R[0]);  /* 0x8009F7C8 */
    R[31] = lw_(R[29] + 24);  /* 0x8009F7CC */
    R[17] = lw_(R[29] + 20);  /* 0x8009F7D0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F7D4 */
    R[2] = R[0] + 1;  /* 0x8009F7D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F7DC jr ra */
}

void g0_8009F73C(void) {
    R[5] = lh_(R[16] + 2);  /* 0x8009F73C */
    { R[31] = 0x8009F748u; R[4] = R[0] + 39; psx_next = 0x8002DAE8u; return; }  /* 0x8009F740 jal */
    R[4] = R[16] + R[0];  /* 0x8009F748 */
    { R[31] = 0x8009F754u; R[5] = R[0] + 25; psx_next = 0x8009BC84u; return; }  /* 0x8009F74C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F754 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_next = 0x8009F650u; return; } }  /* 0x8009F75C b extern */
    R[2] = 0x8012u << 16;  /* 0x8009F764 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F768 */
    { R[2] = R[0] | 0xE8B7; goto L_8009F7B0; }  /* 0x8009F76C j */
    { R[31] = 0x8009F77Cu; R[4] = R[0] + 2; psx_next = 0x800905D4u; return; }  /* 0x8009F774 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F77C */
    { R[31] = 0x8009F788u; R[4] = R[0] + 40; psx_next = 0x8002DAE8u; return; }  /* 0x8009F780 jal */
    R[4] = R[16] + R[0];  /* 0x8009F788 */
    { R[31] = 0x8009F794u; R[5] = R[0] + 26; psx_next = 0x8009BC84u; return; }  /* 0x8009F78C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F794 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_next = 0x8009F650u; return; } }  /* 0x8009F79C b extern */
    R[2] = 0x8012u << 16;  /* 0x8009F7A4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F7A8 */
    R[2] = R[0] + 29787;  /* 0x8009F7AC */
L_8009F7B0:;
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009F7B0 */
    { sw_(R[16] + 140, R[2]); psx_next = 0x8009F650u; return; }  /* 0x8009F7B4 j extern */
    R[4] = R[16] + R[0];  /* 0x8009F7BC */
    { R[31] = 0x8009F7C8u; R[5] = R[0] + 29; psx_next = 0x8009BC84u; return; }  /* 0x8009F7C0 jal */
    sb_(R[16] + 787, R[0]);  /* 0x8009F7C8 */
    R[31] = lw_(R[29] + 24);  /* 0x8009F7CC */
    R[17] = lw_(R[29] + 20);  /* 0x8009F7D0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F7D4 */
    R[2] = R[0] + 1;  /* 0x8009F7D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F7DC jr ra */
}

void g0_8009F748(void) {
    R[4] = R[16] + R[0];  /* 0x8009F748 */
    { R[31] = 0x8009F754u; R[5] = R[0] + 25; psx_next = 0x8009BC84u; return; }  /* 0x8009F74C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F754 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_next = 0x8009F650u; return; } }  /* 0x8009F75C b extern */
    R[2] = 0x8012u << 16;  /* 0x8009F764 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F768 */
    { R[2] = R[0] | 0xE8B7; goto L_8009F7B0; }  /* 0x8009F76C j */
    { R[31] = 0x8009F77Cu; R[4] = R[0] + 2; psx_next = 0x800905D4u; return; }  /* 0x8009F774 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F77C */
    { R[31] = 0x8009F788u; R[4] = R[0] + 40; psx_next = 0x8002DAE8u; return; }  /* 0x8009F780 jal */
    R[4] = R[16] + R[0];  /* 0x8009F788 */
    { R[31] = 0x8009F794u; R[5] = R[0] + 26; psx_next = 0x8009BC84u; return; }  /* 0x8009F78C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F794 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_next = 0x8009F650u; return; } }  /* 0x8009F79C b extern */
    R[2] = 0x8012u << 16;  /* 0x8009F7A4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F7A8 */
    R[2] = R[0] + 29787;  /* 0x8009F7AC */
L_8009F7B0:;
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009F7B0 */
    { sw_(R[16] + 140, R[2]); psx_next = 0x8009F650u; return; }  /* 0x8009F7B4 j extern */
    R[4] = R[16] + R[0];  /* 0x8009F7BC */
    { R[31] = 0x8009F7C8u; R[5] = R[0] + 29; psx_next = 0x8009BC84u; return; }  /* 0x8009F7C0 jal */
    sb_(R[16] + 787, R[0]);  /* 0x8009F7C8 */
    R[31] = lw_(R[29] + 24);  /* 0x8009F7CC */
    R[17] = lw_(R[29] + 20);  /* 0x8009F7D0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F7D4 */
    R[2] = R[0] + 1;  /* 0x8009F7D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F7DC jr ra */
}

void g0_8009F754(void) {
    R[2] = lb_(R[16] + 784);  /* 0x8009F754 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_next = 0x8009F650u; return; } }  /* 0x8009F75C b extern */
    R[2] = 0x8012u << 16;  /* 0x8009F764 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F768 */
    { R[2] = R[0] | 0xE8B7; goto L_8009F7B0; }  /* 0x8009F76C j */
    { R[31] = 0x8009F77Cu; R[4] = R[0] + 2; psx_next = 0x800905D4u; return; }  /* 0x8009F774 jal */
    R[5] = lh_(R[16] + 2);  /* 0x8009F77C */
    { R[31] = 0x8009F788u; R[4] = R[0] + 40; psx_next = 0x8002DAE8u; return; }  /* 0x8009F780 jal */
    R[4] = R[16] + R[0];  /* 0x8009F788 */
    { R[31] = 0x8009F794u; R[5] = R[0] + 26; psx_next = 0x8009BC84u; return; }  /* 0x8009F78C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F794 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_next = 0x8009F650u; return; } }  /* 0x8009F79C b extern */
    R[2] = 0x8012u << 16;  /* 0x8009F7A4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F7A8 */
    R[2] = R[0] + 29787;  /* 0x8009F7AC */
L_8009F7B0:;
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009F7B0 */
    { sw_(R[16] + 140, R[2]); psx_next = 0x8009F650u; return; }  /* 0x8009F7B4 j extern */
    R[4] = R[16] + R[0];  /* 0x8009F7BC */
    { R[31] = 0x8009F7C8u; R[5] = R[0] + 29; psx_next = 0x8009BC84u; return; }  /* 0x8009F7C0 jal */
    sb_(R[16] + 787, R[0]);  /* 0x8009F7C8 */
    R[31] = lw_(R[29] + 24);  /* 0x8009F7CC */
    R[17] = lw_(R[29] + 20);  /* 0x8009F7D0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F7D4 */
    R[2] = R[0] + 1;  /* 0x8009F7D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F7DC jr ra */
}

void g0_8009F77C(void) {
    R[5] = lh_(R[16] + 2);  /* 0x8009F77C */
    { R[31] = 0x8009F788u; R[4] = R[0] + 40; psx_next = 0x8002DAE8u; return; }  /* 0x8009F780 jal */
    R[4] = R[16] + R[0];  /* 0x8009F788 */
    { R[31] = 0x8009F794u; R[5] = R[0] + 26; psx_next = 0x8009BC84u; return; }  /* 0x8009F78C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F794 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_next = 0x8009F650u; return; } }  /* 0x8009F79C b extern */
    R[2] = 0x8012u << 16;  /* 0x8009F7A4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F7A8 */
    R[2] = R[0] + 29787;  /* 0x8009F7AC */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009F7B0 */
    { sw_(R[16] + 140, R[2]); psx_next = 0x8009F650u; return; }  /* 0x8009F7B4 j extern */
    R[4] = R[16] + R[0];  /* 0x8009F7BC */
    { R[31] = 0x8009F7C8u; R[5] = R[0] + 29; psx_next = 0x8009BC84u; return; }  /* 0x8009F7C0 jal */
    sb_(R[16] + 787, R[0]);  /* 0x8009F7C8 */
    R[31] = lw_(R[29] + 24);  /* 0x8009F7CC */
    R[17] = lw_(R[29] + 20);  /* 0x8009F7D0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F7D4 */
    R[2] = R[0] + 1;  /* 0x8009F7D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F7DC jr ra */
}

void g0_8009F788(void) {
    R[4] = R[16] + R[0];  /* 0x8009F788 */
    { R[31] = 0x8009F794u; R[5] = R[0] + 26; psx_next = 0x8009BC84u; return; }  /* 0x8009F78C jal */
    R[2] = lb_(R[16] + 784);  /* 0x8009F794 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_next = 0x8009F650u; return; } }  /* 0x8009F79C b extern */
    R[2] = 0x8012u << 16;  /* 0x8009F7A4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F7A8 */
    R[2] = R[0] + 29787;  /* 0x8009F7AC */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009F7B0 */
    { sw_(R[16] + 140, R[2]); psx_next = 0x8009F650u; return; }  /* 0x8009F7B4 j extern */
    R[4] = R[16] + R[0];  /* 0x8009F7BC */
    { R[31] = 0x8009F7C8u; R[5] = R[0] + 29; psx_next = 0x8009BC84u; return; }  /* 0x8009F7C0 jal */
    sb_(R[16] + 787, R[0]);  /* 0x8009F7C8 */
    R[31] = lw_(R[29] + 24);  /* 0x8009F7CC */
    R[17] = lw_(R[29] + 20);  /* 0x8009F7D0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F7D4 */
    R[2] = R[0] + 1;  /* 0x8009F7D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F7DC jr ra */
}

void g0_8009F794(void) {
    R[2] = lb_(R[16] + 784);  /* 0x8009F794 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[16] + 600, R[0]); if (_c) { psx_next = 0x8009F650u; return; } }  /* 0x8009F79C b extern */
    R[2] = 0x8012u << 16;  /* 0x8009F7A4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F7A8 */
    R[2] = R[0] + 29787;  /* 0x8009F7AC */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009F7B0 */
    { sw_(R[16] + 140, R[2]); psx_next = 0x8009F650u; return; }  /* 0x8009F7B4 j extern */
    R[4] = R[16] + R[0];  /* 0x8009F7BC */
    { R[31] = 0x8009F7C8u; R[5] = R[0] + 29; psx_next = 0x8009BC84u; return; }  /* 0x8009F7C0 jal */
    sb_(R[16] + 787, R[0]);  /* 0x8009F7C8 */
    R[31] = lw_(R[29] + 24);  /* 0x8009F7CC */
    R[17] = lw_(R[29] + 20);  /* 0x8009F7D0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F7D4 */
    R[2] = R[0] + 1;  /* 0x8009F7D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F7DC jr ra */
}

void g0_8009F7C8(void) {
    sb_(R[16] + 787, R[0]);  /* 0x8009F7C8 */
    R[31] = lw_(R[29] + 24);  /* 0x8009F7CC */
    R[17] = lw_(R[29] + 20);  /* 0x8009F7D0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F7D4 */
    R[2] = R[0] + 1;  /* 0x8009F7D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F7DC jr ra */
}

void g0_8009F7E4(void) {
    R[29] = R[29] - 24;  /* 0x8009F7E4 */
    sw_(R[29] + 16, R[16]);  /* 0x8009F7E8 */
    R[16] = R[4] + R[0];  /* 0x8009F7EC */
    R[5] = R[0] - 1;  /* 0x8009F7F0 */
    R[6] = R[5] + R[0];  /* 0x8009F7F4 */
    sw_(R[29] + 20, R[31]);  /* 0x8009F7F8 */
    { R[31] = 0x8009F804u; R[7] = R[0] + R[0]; psx_next = 0x8009D0B0u; return; }  /* 0x8009F7FC jal */
    R[2] = lw_(R[16] + 72);  /* 0x8009F804 */
    R[2] = lh_(R[2]);  /* 0x8009F80C */
    R[2] = R[2] >> 13;  /* 0x8009F814 */
    R[2] = R[2] & 0x1;  /* 0x8009F818 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F858; } }  /* 0x8009F81C */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 56);  /* 0x8009F824 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F844; } }  /* 0x8009F82C */
    { R[31] = 0x8009F83Cu; R[5] = R[0] + 34; psx_next = 0x8009BC84u; return; }  /* 0x8009F834 jal */
    { goto L_8009F86C; }  /* 0x8009F83C j */
L_8009F844:;
    { R[31] = 0x8009F84Cu; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F844 jal */
    R[2] = R[0] + 60;  /* 0x8009F84C */
    { sb_(R[16] + 797, R[2]); goto L_8009F86C; }  /* 0x8009F850 j */
L_8009F858:;
    R[2] = lh_(R[16] + 4);  /* 0x8009F858 */
    R[2] = R[2] + 8;  /* 0x8009F860 */
    R[2] = R[2] & 0x1FF;  /* 0x8009F864 */
    sh_(R[16] + 4, R[2]);  /* 0x8009F868 */
L_8009F86C:;
    R[31] = lw_(R[29] + 20);  /* 0x8009F86C */
    R[16] = lw_(R[29] + 16);  /* 0x8009F870 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F874 jr ra */
}

void g0_8009F804(void) {
    R[2] = lw_(R[16] + 72);  /* 0x8009F804 */
    R[2] = lh_(R[2]);  /* 0x8009F80C */
    R[2] = R[2] >> 13;  /* 0x8009F814 */
    R[2] = R[2] & 0x1;  /* 0x8009F818 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F858; } }  /* 0x8009F81C */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 56);  /* 0x8009F824 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F844; } }  /* 0x8009F82C */
    { R[31] = 0x8009F83Cu; R[5] = R[0] + 34; psx_next = 0x8009BC84u; return; }  /* 0x8009F834 jal */
    { goto L_8009F86C; }  /* 0x8009F83C j */
L_8009F844:;
    { R[31] = 0x8009F84Cu; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F844 jal */
    R[2] = R[0] + 60;  /* 0x8009F84C */
    { sb_(R[16] + 797, R[2]); goto L_8009F86C; }  /* 0x8009F850 j */
L_8009F858:;
    R[2] = lh_(R[16] + 4);  /* 0x8009F858 */
    R[2] = R[2] + 8;  /* 0x8009F860 */
    R[2] = R[2] & 0x1FF;  /* 0x8009F864 */
    sh_(R[16] + 4, R[2]);  /* 0x8009F868 */
L_8009F86C:;
    R[31] = lw_(R[29] + 20);  /* 0x8009F86C */
    R[16] = lw_(R[29] + 16);  /* 0x8009F870 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F874 jr ra */
}

void g0_8009F83C(void) {
    { goto L_8009F86C; }  /* 0x8009F83C j */
    { R[31] = 0x8009F84Cu; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F844 jal */
    R[2] = R[0] + 60;  /* 0x8009F84C */
    { sb_(R[16] + 797, R[2]); goto L_8009F86C; }  /* 0x8009F850 j */
    R[2] = lh_(R[16] + 4);  /* 0x8009F858 */
    R[2] = R[2] + 8;  /* 0x8009F860 */
    R[2] = R[2] & 0x1FF;  /* 0x8009F864 */
    sh_(R[16] + 4, R[2]);  /* 0x8009F868 */
L_8009F86C:;
    R[31] = lw_(R[29] + 20);  /* 0x8009F86C */
    R[16] = lw_(R[29] + 16);  /* 0x8009F870 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F874 jr ra */
}

void g0_8009F84C(void) {
    R[2] = R[0] + 60;  /* 0x8009F84C */
    { sb_(R[16] + 797, R[2]); goto L_8009F86C; }  /* 0x8009F850 j */
    R[2] = lh_(R[16] + 4);  /* 0x8009F858 */
    R[2] = R[2] + 8;  /* 0x8009F860 */
    R[2] = R[2] & 0x1FF;  /* 0x8009F864 */
    sh_(R[16] + 4, R[2]);  /* 0x8009F868 */
L_8009F86C:;
    R[31] = lw_(R[29] + 20);  /* 0x8009F86C */
    R[16] = lw_(R[29] + 16);  /* 0x8009F870 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F874 jr ra */
}

void g0_8009F87C(void) {
    R[29] = R[29] - 24;  /* 0x8009F87C */
    sw_(R[29] + 16, R[31]);  /* 0x8009F880 */
    R[2] = lw_(R[4] + 72);  /* 0x8009F884 */
    R[2] = lh_(R[2]);  /* 0x8009F88C */
    R[2] = R[2] >> 13;  /* 0x8009F894 */
    R[2] = R[2] & 0x1;  /* 0x8009F898 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F8AC; } }  /* 0x8009F89C */
    { R[31] = 0x8009F8ACu; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009F8A4 jal */
L_8009F8AC:;
    R[31] = lw_(R[29] + 16);  /* 0x8009F8AC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F8B4 jr ra */
}

void g0_8009F8AC(void) {
    R[31] = lw_(R[29] + 16);  /* 0x8009F8AC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F8B4 jr ra */
}

void g0_8009F8BC(void) {
    R[2] = 0x8006u << 16;  /* 0x8009F8BC */
    R[3] = 0x8006u << 16;  /* 0x8009F8C0 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F8C4 */
    R[3] = lh_(R[3] + 16114);  /* 0x8009F8C8 */
    psx_next = 0x8009F8CCu; return;  /* fallthrough */
}

void g0_8009F8CC(void) {
    R[29] = R[29] - 24;  /* 0x8009F8CC */
    sw_(R[29] + 16, R[16]);  /* 0x8009F8D0 */
    R[16] = R[4] + R[0];  /* 0x8009F8D4 */
    R[2] = R[2] & R[3];  /* 0x8009F8D8 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[29] + 20, R[31]); if (_c) { goto L_8009F8EC; } }  /* 0x8009F8DC */
    { R[2] = R[0] + R[0]; goto L_8009F930; }  /* 0x8009F8E4 j */
L_8009F8EC:;
    R[4] = R[16] + R[0];  /* 0x8009F8EC */
    R[2] = lh_(R[16] + 6);  /* 0x8009F8F0 */
    R[5] = R[0] + 14;  /* 0x8009F8F4 */
    R[2] = R[2] - 256;  /* 0x8009F8F8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009F8FC */
    sh_(R[16] + 4, R[2]);  /* 0x8009F900 */
    { R[31] = 0x8009F90Cu; sh_(R[16] + 6, R[2]); psx_next = 0x8009BC84u; return; }  /* 0x8009F904 jal */
    R[3] = 0x1u << 16;  /* 0x8009F90C */
    R[3] = R[3] | 0x22E5;  /* 0x8009F910 */
    R[2] = 0x8012u << 16;  /* 0x8009F914 */
    R[4] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F918 */
    R[2] = R[0] + 1;  /* 0x8009F91C */
    R[3] = (uint32_t)((int32_t)R[3] >> (R[4] & 31));  /* 0x8009F920 */
    sw_(R[16] + 140, R[3]);  /* 0x8009F924 */
    R[3] = 0x8013u << 16;  /* 0x8009F928 */
    sw_(R[3] + -29556, R[0]);  /* 0x8009F92C */
L_8009F930:;
    R[31] = lw_(R[29] + 20);  /* 0x8009F930 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F934 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F938 jr ra */
}

void g0_8009F90C(void) {
    R[3] = 0x1u << 16;  /* 0x8009F90C */
    R[3] = R[3] | 0x22E5;  /* 0x8009F910 */
    R[2] = 0x8012u << 16;  /* 0x8009F914 */
    R[4] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009F918 */
    R[2] = R[0] + 1;  /* 0x8009F91C */
    R[3] = (uint32_t)((int32_t)R[3] >> (R[4] & 31));  /* 0x8009F920 */
    sw_(R[16] + 140, R[3]);  /* 0x8009F924 */
    R[3] = 0x8013u << 16;  /* 0x8009F928 */
    sw_(R[3] + -29556, R[0]);  /* 0x8009F92C */
    R[31] = lw_(R[29] + 20);  /* 0x8009F930 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F934 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F938 jr ra */
}

void g0_8009F940(void) {
    R[29] = R[29] - 24;  /* 0x8009F940 */
    sw_(R[29] + 16, R[16]);  /* 0x8009F944 */
    sw_(R[29] + 20, R[31]);  /* 0x8009F948 */
    { R[31] = 0x8009F954u; R[16] = R[4] + R[0]; psx_next = 0x8009F8BCu; return; }  /* 0x8009F94C jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009F9A4u; return; } }  /* 0x8009F954 b extern */
    R[3] = lh_(R[2] + -6454);  /* 0x8009F95C */
    R[2] = R[3] & 0x4000;  /* 0x8009F964 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F97C; } }  /* 0x8009F968 */
    sh_(R[16] + 22, R[0]);  /* 0x8009F970 */
    { R[5] = R[0] + 127; psx_next = 0x8009F99Cu; return; }  /* 0x8009F974 j extern */
L_8009F97C:;
    R[2] = R[3] & 0x1000;  /* 0x8009F97C */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 126; if (_c) { psx_next = 0x8009F998u; return; } }  /* 0x8009F980 b extern */
    psx_next = 0x8009F988u; return;  /* fallthrough */
}

void g0_8009F954(void) {
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009F9A4u; return; } }  /* 0x8009F954 b extern */
    R[3] = lh_(R[2] + -6454);  /* 0x8009F95C */
    R[2] = R[3] & 0x4000;  /* 0x8009F964 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009F97C; } }  /* 0x8009F968 */
    sh_(R[16] + 22, R[0]);  /* 0x8009F970 */
    { R[5] = R[0] + 127; psx_next = 0x8009F99Cu; return; }  /* 0x8009F974 j extern */
L_8009F97C:;
    R[2] = R[3] & 0x1000;  /* 0x8009F97C */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 126; if (_c) { psx_next = 0x8009F998u; return; } }  /* 0x8009F980 b extern */
    psx_next = 0x8009F988u; return;  /* fallthrough */
}

void g0_8009F984(void) {
    R[5] = R[0] + 126;  /* 0x8009F984 */
    { R[31] = 0x8009F990u; R[5] = R[0] + 125; psx_next = 0x8009BC84u; return; }  /* 0x8009F988 jal */
    { sh_(R[16] + 22, R[0]); goto L_8009F9A4; }  /* 0x8009F990 j */
    R[4] = R[16] + R[0];  /* 0x8009F998 */
    { R[31] = 0x8009F9A4u; psx_next = 0x8009BC84u; return; }  /* 0x8009F99C jal */
L_8009F9A4:;
    R[31] = lw_(R[29] + 20);  /* 0x8009F9A4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F9A8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F9AC jr ra */
}

void g0_8009F988(void) {
    { R[31] = 0x8009F990u; R[5] = R[0] + 125; psx_next = 0x8009BC84u; return; }  /* 0x8009F988 jal */
    { sh_(R[16] + 22, R[0]); goto L_8009F9A4; }  /* 0x8009F990 j */
    R[4] = R[16] + R[0];  /* 0x8009F998 */
    { R[31] = 0x8009F9A4u; psx_next = 0x8009BC84u; return; }  /* 0x8009F99C jal */
L_8009F9A4:;
    R[31] = lw_(R[29] + 20);  /* 0x8009F9A4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F9A8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F9AC jr ra */
}

void g0_8009F990(void) {
    { sh_(R[16] + 22, R[0]); goto L_8009F9A4; }  /* 0x8009F990 j */
    R[4] = R[16] + R[0];  /* 0x8009F998 */
    { R[31] = 0x8009F9A4u; psx_next = 0x8009BC84u; return; }  /* 0x8009F99C jal */
L_8009F9A4:;
    R[31] = lw_(R[29] + 20);  /* 0x8009F9A4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F9A8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F9AC jr ra */
}

void g0_8009F998(void) {
    R[4] = R[16] + R[0];  /* 0x8009F998 */
    { R[31] = 0x8009F9A4u; psx_next = 0x8009BC84u; return; }  /* 0x8009F99C jal */
    R[31] = lw_(R[29] + 20);  /* 0x8009F9A4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F9A8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F9AC jr ra */
}

void g0_8009F99C(void) {
    { R[31] = 0x8009F9A4u; psx_next = 0x8009BC84u; return; }  /* 0x8009F99C jal */
    R[31] = lw_(R[29] + 20);  /* 0x8009F9A4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F9A8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F9AC jr ra */
}

void g0_8009F9A4(void) {
    R[31] = lw_(R[29] + 20);  /* 0x8009F9A4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F9A8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009F9AC jr ra */
}

void g0_8009F9B4(void) {
    R[29] = R[29] - 24;  /* 0x8009F9B4 */
    sw_(R[29] + 16, R[16]);  /* 0x8009F9B8 */
    sw_(R[29] + 20, R[31]);  /* 0x8009F9BC */
    { R[31] = 0x8009F9C8u; R[16] = R[4] + R[0]; psx_next = 0x8009F8BCu; return; }  /* 0x8009F9C0 jal */
    { uint32_t _c = (R[2] != R[0]); R[5] = 0x3u << 16; if (_c) { goto L_8009FA34; } }  /* 0x8009F9C8 */
    R[5] = R[5] | 0x6FFF;  /* 0x8009F9D0 */
    R[3] = 0x8013u << 16;  /* 0x8009F9D4 */
    R[2] = lw_(R[16] + 476);  /* 0x8009F9D8 */
    R[3] = lw_(R[3] + -29556);  /* 0x8009F9DC */
    R[4] = lw_(R[16] + 488);  /* 0x8009F9E0 */
    R[3] = lw_(R[3] + 20);  /* 0x8009F9E4 */
    R[2] = R[2] + R[4];  /* 0x8009F9E8 */
    R[2] = R[2] + R[3];  /* 0x8009F9EC */
    R[5] = ((int32_t)R[5] < (int32_t)R[2]);  /* 0x8009F9F0 */
    { uint32_t _c = (R[5] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009FA0C; } }  /* 0x8009F9F4 */
    { R[31] = 0x8009FA04u; R[5] = R[0] + 122; psx_next = 0x8009BC84u; return; }  /* 0x8009F9FC jal */
    { goto L_8009FA34; }  /* 0x8009FA04 j */
L_8009FA0C:;
    R[2] = lw_(R[16] + 72);  /* 0x8009FA0C */
    R[2] = lh_(R[2]);  /* 0x8009FA14 */
    R[2] = R[2] >> 13;  /* 0x8009FA1C */
    R[2] = R[2] & 0x1;  /* 0x8009FA20 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009FA34; } }  /* 0x8009FA24 */
    { R[31] = 0x8009FA34u; R[4] = R[16] + R[0]; psx_next = 0x8009F940u; return; }  /* 0x8009FA2C jal */
L_8009FA34:;
    R[31] = lw_(R[29] + 20);  /* 0x8009FA34 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FA38 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FA3C jr ra */
}

void g0_8009F9C8(void) {
    { uint32_t _c = (R[2] != R[0]); R[5] = 0x3u << 16; if (_c) { goto L_8009FA34; } }  /* 0x8009F9C8 */
    R[5] = R[5] | 0x6FFF;  /* 0x8009F9D0 */
    R[3] = 0x8013u << 16;  /* 0x8009F9D4 */
    R[2] = lw_(R[16] + 476);  /* 0x8009F9D8 */
    R[3] = lw_(R[3] + -29556);  /* 0x8009F9DC */
    R[4] = lw_(R[16] + 488);  /* 0x8009F9E0 */
    R[3] = lw_(R[3] + 20);  /* 0x8009F9E4 */
    R[2] = R[2] + R[4];  /* 0x8009F9E8 */
    R[2] = R[2] + R[3];  /* 0x8009F9EC */
    R[5] = ((int32_t)R[5] < (int32_t)R[2]);  /* 0x8009F9F0 */
    { uint32_t _c = (R[5] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009FA0C; } }  /* 0x8009F9F4 */
    { R[31] = 0x8009FA04u; R[5] = R[0] + 122; psx_next = 0x8009BC84u; return; }  /* 0x8009F9FC jal */
    { goto L_8009FA34; }  /* 0x8009FA04 j */
L_8009FA0C:;
    R[2] = lw_(R[16] + 72);  /* 0x8009FA0C */
    R[2] = lh_(R[2]);  /* 0x8009FA14 */
    R[2] = R[2] >> 13;  /* 0x8009FA1C */
    R[2] = R[2] & 0x1;  /* 0x8009FA20 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009FA34; } }  /* 0x8009FA24 */
    { R[31] = 0x8009FA34u; R[4] = R[16] + R[0]; psx_next = 0x8009F940u; return; }  /* 0x8009FA2C jal */
L_8009FA34:;
    R[31] = lw_(R[29] + 20);  /* 0x8009FA34 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FA38 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FA3C jr ra */
}

void g0_8009FA04(void) {
    { goto L_8009FA34; }  /* 0x8009FA04 j */
    R[2] = lw_(R[16] + 72);  /* 0x8009FA0C */
    R[2] = lh_(R[2]);  /* 0x8009FA14 */
    R[2] = R[2] >> 13;  /* 0x8009FA1C */
    R[2] = R[2] & 0x1;  /* 0x8009FA20 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009FA34; } }  /* 0x8009FA24 */
    { R[31] = 0x8009FA34u; R[4] = R[16] + R[0]; psx_next = 0x8009F940u; return; }  /* 0x8009FA2C jal */
L_8009FA34:;
    R[31] = lw_(R[29] + 20);  /* 0x8009FA34 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FA38 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FA3C jr ra */
}

void g0_8009FA34(void) {
    R[31] = lw_(R[29] + 20);  /* 0x8009FA34 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FA38 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FA3C jr ra */
}

void g0_8009FA44(void) {
    R[29] = R[29] - 24;  /* 0x8009FA44 */
    psx_next = 0x8009FA48u; return;  /* fallthrough */
}

void g0_8009FA48(void) {
    R[6] = R[4] + R[0];  /* 0x8009FA48 */
    R[5] = 0x1u << 16;  /* 0x8009FA4C */
    R[5] = R[5] | 0xDFFF;  /* 0x8009FA50 */
    R[2] = 0x8013u << 16;  /* 0x8009FA54 */
    sw_(R[29] + 16, R[16]);  /* 0x8009FA58 */
    R[16] = R[2] - 29656;  /* 0x8009FA5C */
    sw_(R[29] + 20, R[31]);  /* 0x8009FA60 */
    R[2] = lw_(R[16] + 100);  /* 0x8009FA64 */
    R[3] = 0x3u << 16;  /* 0x8009FA68 */
    R[4] = lw_(R[2] + 8);  /* 0x8009FA6C */
    R[2] = lw_(R[6] + 476);  /* 0x8009FA70 */
    R[3] = R[3] | 0xBFFE;  /* 0x8009FA74 */
    R[2] = R[2] + R[4];  /* 0x8009FA78 */
    R[2] = R[2] + R[5];  /* 0x8009FA7C */
    R[3] = (R[3] < R[2]);  /* 0x8009FA80 */
    { uint32_t _c = (R[3] == R[0]); R[4] = R[6] + R[0]; if (_c) { goto L_8009FA9C; } }  /* 0x8009FA84 */
    R[2] = lb_(R[6] + 784);  /* 0x8009FA8C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009FAAC; } }  /* 0x8009FA94 */
L_8009FA9C:;
    { R[31] = 0x8009FAA4u; R[5] = R[0] + 11; psx_next = 0x8009BC84u; return; }  /* 0x8009FA9C jal */
    { sw_(R[16] + 100, R[0]); goto L_8009FAD4; }  /* 0x8009FAA4 j */
L_8009FAAC:;
    R[2] = lw_(R[6] + 72);  /* 0x8009FAAC */
    R[2] = lh_(R[2]);  /* 0x8009FAB4 */
    R[2] = R[2] >> 13;  /* 0x8009FABC */
    R[2] = R[2] & 0x1;  /* 0x8009FAC0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009FAD4; } }  /* 0x8009FAC4 */
    { R[31] = 0x8009FAD4u; R[4] = R[6] + R[0]; psx_next = 0x8009F940u; return; }  /* 0x8009FACC jal */
L_8009FAD4:;
    R[31] = lw_(R[29] + 20);  /* 0x8009FAD4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FAD8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FADC jr ra */
}

void g0_8009FAA4(void) {
    { sw_(R[16] + 100, R[0]); goto L_8009FAD4; }  /* 0x8009FAA4 j */
    R[2] = lw_(R[6] + 72);  /* 0x8009FAAC */
    R[2] = lh_(R[2]);  /* 0x8009FAB4 */
    R[2] = R[2] >> 13;  /* 0x8009FABC */
    R[2] = R[2] & 0x1;  /* 0x8009FAC0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009FAD4; } }  /* 0x8009FAC4 */
    { R[31] = 0x8009FAD4u; R[4] = R[6] + R[0]; psx_next = 0x8009F940u; return; }  /* 0x8009FACC jal */
L_8009FAD4:;
    R[31] = lw_(R[29] + 20);  /* 0x8009FAD4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FAD8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FADC jr ra */
}

void g0_8009FAD4(void) {
    R[31] = lw_(R[29] + 20);  /* 0x8009FAD4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FAD8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FADC jr ra */
}

void g0_8009FAE4(void) {
    R[29] = R[29] - 24;  /* 0x8009FAE4 */
    sw_(R[29] + 16, R[16]);  /* 0x8009FAE8 */
    R[16] = R[4] + R[0];  /* 0x8009FAEC */
    sw_(R[29] + 20, R[31]);  /* 0x8009FAF0 */
    R[2] = lw_(R[16] + 72);  /* 0x8009FAF4 */
    R[2] = lh_(R[2]);  /* 0x8009FAFC */
    R[2] = R[2] >> 13;  /* 0x8009FB04 */
    R[2] = R[2] & 0x1;  /* 0x8009FB08 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009FBE0; } }  /* 0x8009FB0C */
    { R[31] = 0x8009FB1Cu; R[5] = R[0] + 126; psx_next = 0x8009BC84u; return; }  /* 0x8009FB14 jal */
    R[4] = 0x8013u << 16;  /* 0x8009FB1C */
    R[2] = lh_(R[16] + 4);  /* 0x8009FB20 */
    R[6] = lw_(R[16] + 28);  /* 0x8009FB24 */
    R[4] = R[4] - 29656;  /* 0x8009FB28 */
    sh_(R[16] + 6, R[2]);  /* 0x8009FB2C */
    R[2] = 0xFFFBu << 16;  /* 0x8009FB30 */
    R[6] = R[6] + R[2];  /* 0x8009FB34 */
    R[5] = lw_(R[4] + 100);  /* 0x8009FB38 */
    R[2] = lw_(R[4] + 108);  /* 0x8009FB3C */
    R[3] = lw_(R[5] + 8);  /* 0x8009FB40 */
    R[2] = R[0] - R[2];  /* 0x8009FB44 */
    R[3] = R[6] + R[3];  /* 0x8009FB48 */
    psx_div((int32_t)R[3], (int32_t)R[2]);  /* 0x8009FB4C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009FB5C; } }  /* 0x8009FB50 */
    psx_break(7168);  /* 0x8009FB58 */
L_8009FB5C:;
    R[1] = R[0] - 1;  /* 0x8009FB5C */
    { uint32_t _c = (R[2] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_8009FB74; } }  /* 0x8009FB60 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_8009FB74; } }  /* 0x8009FB68 */
    psx_break(6144);  /* 0x8009FB70 */
L_8009FB74:;
    R[3] = LO;  /* 0x8009FB74 */
    R[2] = lw_(R[4] + 104);  /* 0x8009FB78 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB80 */
    R[4] = lw_(R[4] + 112);  /* 0x8009FB84 */
    R[2] = lw_(R[16] + 28);  /* 0x8009FB88 */
    R[9] = LO;  /* 0x8009FB8C */
    R[6] = R[6] - R[2];  /* 0x8009FB90 */
    R[2] = lw_(R[16] + 200);  /* 0x8009FB94 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB98 */
    R[3] = lw_(R[5] + 4);  /* 0x8009FB9C */
    R[5] = lw_(R[5] + 12);  /* 0x8009FBA0 */
    R[4] = lw_(R[16] + 24);  /* 0x8009FBA4 */
    R[2] = R[2] + R[6];  /* 0x8009FBA8 */
    sw_(R[16] + 200, R[2]);  /* 0x8009FBAC */
    R[2] = lw_(R[16] + 196);  /* 0x8009FBB0 */
    R[3] = R[3] + R[9];  /* 0x8009FBB4 */
    R[3] = R[3] - R[4];  /* 0x8009FBB8 */
    R[2] = R[2] + R[3];  /* 0x8009FBBC */
    R[3] = lw_(R[16] + 32);  /* 0x8009FBC0 */
    sw_(R[16] + 196, R[2]);  /* 0x8009FBC4 */
    R[2] = lw_(R[16] + 204);  /* 0x8009FBC8 */
    R[7] = LO;  /* 0x8009FBCC */
    R[5] = R[5] + R[7];  /* 0x8009FBD0 */
    R[5] = R[5] - R[3];  /* 0x8009FBD4 */
    R[2] = R[2] + R[5];  /* 0x8009FBD8 */
    sw_(R[16] + 204, R[2]);  /* 0x8009FBDC */
L_8009FBE0:;
    R[31] = lw_(R[29] + 20);  /* 0x8009FBE0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FBE4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FBE8 jr ra */
}

void g0_8009FB1C(void) {
    R[4] = 0x8013u << 16;  /* 0x8009FB1C */
    R[2] = lh_(R[16] + 4);  /* 0x8009FB20 */
    R[6] = lw_(R[16] + 28);  /* 0x8009FB24 */
    R[4] = R[4] - 29656;  /* 0x8009FB28 */
    sh_(R[16] + 6, R[2]);  /* 0x8009FB2C */
    R[2] = 0xFFFBu << 16;  /* 0x8009FB30 */
    R[6] = R[6] + R[2];  /* 0x8009FB34 */
    R[5] = lw_(R[4] + 100);  /* 0x8009FB38 */
    R[2] = lw_(R[4] + 108);  /* 0x8009FB3C */
    R[3] = lw_(R[5] + 8);  /* 0x8009FB40 */
    R[2] = R[0] - R[2];  /* 0x8009FB44 */
    R[3] = R[6] + R[3];  /* 0x8009FB48 */
    psx_div((int32_t)R[3], (int32_t)R[2]);  /* 0x8009FB4C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009FB5C; } }  /* 0x8009FB50 */
    psx_break(7168);  /* 0x8009FB58 */
L_8009FB5C:;
    R[1] = R[0] - 1;  /* 0x8009FB5C */
    { uint32_t _c = (R[2] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_8009FB74; } }  /* 0x8009FB60 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_8009FB74; } }  /* 0x8009FB68 */
    psx_break(6144);  /* 0x8009FB70 */
L_8009FB74:;
    R[3] = LO;  /* 0x8009FB74 */
    R[2] = lw_(R[4] + 104);  /* 0x8009FB78 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB80 */
    R[4] = lw_(R[4] + 112);  /* 0x8009FB84 */
    R[2] = lw_(R[16] + 28);  /* 0x8009FB88 */
    R[9] = LO;  /* 0x8009FB8C */
    R[6] = R[6] - R[2];  /* 0x8009FB90 */
    R[2] = lw_(R[16] + 200);  /* 0x8009FB94 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB98 */
    R[3] = lw_(R[5] + 4);  /* 0x8009FB9C */
    R[5] = lw_(R[5] + 12);  /* 0x8009FBA0 */
    R[4] = lw_(R[16] + 24);  /* 0x8009FBA4 */
    R[2] = R[2] + R[6];  /* 0x8009FBA8 */
    sw_(R[16] + 200, R[2]);  /* 0x8009FBAC */
    R[2] = lw_(R[16] + 196);  /* 0x8009FBB0 */
    R[3] = R[3] + R[9];  /* 0x8009FBB4 */
    R[3] = R[3] - R[4];  /* 0x8009FBB8 */
    R[2] = R[2] + R[3];  /* 0x8009FBBC */
    R[3] = lw_(R[16] + 32);  /* 0x8009FBC0 */
    sw_(R[16] + 196, R[2]);  /* 0x8009FBC4 */
    R[2] = lw_(R[16] + 204);  /* 0x8009FBC8 */
    R[7] = LO;  /* 0x8009FBCC */
    R[5] = R[5] + R[7];  /* 0x8009FBD0 */
    R[5] = R[5] - R[3];  /* 0x8009FBD4 */
    R[2] = R[2] + R[5];  /* 0x8009FBD8 */
    sw_(R[16] + 204, R[2]);  /* 0x8009FBDC */
    R[31] = lw_(R[29] + 20);  /* 0x8009FBE0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FBE4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FBE8 jr ra */
}

void g0_8009FBF0(void) {
    R[29] = R[29] - 24;  /* 0x8009FBF0 */
    sw_(R[29] + 16, R[31]);  /* 0x8009FBF4 */
    R[2] = lw_(R[4] + 72);  /* 0x8009FBF8 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x8009FC00 */
    R[2] = R[0] + 12;  /* 0x8009FC04 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009FC14; } }  /* 0x8009FC08 */
    sw_(R[4] + 124, R[0]);  /* 0x8009FC10 */
L_8009FC14:;
    R[2] = lw_(R[4] + 72);  /* 0x8009FC14 */
    R[2] = lh_(R[2]);  /* 0x8009FC1C */
    R[2] = R[2] >> 13;  /* 0x8009FC24 */
    R[2] = R[2] & 0x1;  /* 0x8009FC28 */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x1u << 16; if (_c) { goto L_8009FC58; } }  /* 0x8009FC2C */
    R[2] = 0x8012u << 16;  /* 0x8009FC34 */
    R[3] = R[3] | 0x22E5;  /* 0x8009FC38 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009FC3C */
    R[5] = R[0] + 140;  /* 0x8009FC40 */
    R[3] = (uint32_t)((int32_t)R[3] >> (R[2] & 31));  /* 0x8009FC44 */
    R[2] = 0x8013u << 16;  /* 0x8009FC48 */
    sw_(R[4] + 140, R[3]);  /* 0x8009FC4C */
    { R[31] = 0x8009FC58u; sw_(R[2] + -29556, R[0]); psx_next = 0x8009BC84u; return; }  /* 0x8009FC50 jal */
L_8009FC58:;
    R[31] = lw_(R[29] + 16);  /* 0x8009FC58 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FC60 jr ra */
}

void g0_8009FC58(void) {
    R[31] = lw_(R[29] + 16);  /* 0x8009FC58 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FC60 jr ra */
}

void g0_8009FC68(void) {
    R[29] = R[29] - 24;  /* 0x8009FC68 */
    sw_(R[29] + 16, R[16]);  /* 0x8009FC6C */
    psx_next = 0x8009FC70u; return;  /* fallthrough */
}

void g0_8009FC70(void) {
    R[16] = R[4] + R[0];  /* 0x8009FC70 */
    sw_(R[29] + 20, R[31]);  /* 0x8009FC74 */
    R[2] = lb_(R[16] + 784);  /* 0x8009FC78 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009FC90; } }  /* 0x8009FC80 */
    { R[31] = 0x8009FC90u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009FC88 jal */
L_8009FC90:;
    R[2] = lw_(R[16] + 72);  /* 0x8009FC90 */
    R[2] = lh_(R[2]);  /* 0x8009FC98 */
    R[2] = R[2] >> 13;  /* 0x8009FCA0 */
    R[2] = R[2] & 0x1;  /* 0x8009FCA4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009FCB8; } }  /* 0x8009FCA8 */
    { R[31] = 0x8009FCB8u; R[5] = R[0] + 15; psx_next = 0x8009BC84u; return; }  /* 0x8009FCB0 jal */
L_8009FCB8:;
    R[31] = lw_(R[29] + 20);  /* 0x8009FCB8 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FCBC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FCC0 jr ra */
}

void g0_8009FC90(void) {
    R[2] = lw_(R[16] + 72);  /* 0x8009FC90 */
    R[2] = lh_(R[2]);  /* 0x8009FC98 */
    R[2] = R[2] >> 13;  /* 0x8009FCA0 */
    R[2] = R[2] & 0x1;  /* 0x8009FCA4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009FCB8; } }  /* 0x8009FCA8 */
    { R[31] = 0x8009FCB8u; R[5] = R[0] + 15; psx_next = 0x8009BC84u; return; }  /* 0x8009FCB0 jal */
L_8009FCB8:;
    R[31] = lw_(R[29] + 20);  /* 0x8009FCB8 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FCBC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FCC0 jr ra */
}

void g0_8009FCB8(void) {
    R[31] = lw_(R[29] + 20);  /* 0x8009FCB8 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FCBC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FCC0 jr ra */
}

void g0_8009FCC8(void) {
    R[29] = R[29] - 32;  /* 0x8009FCC8 */
    sw_(R[29] + 20, R[17]);  /* 0x8009FCCC */
    R[17] = R[4] + R[0];  /* 0x8009FCD0 */
    sw_(R[29] + 28, R[31]);  /* 0x8009FCD4 */
    sw_(R[29] + 24, R[18]);  /* 0x8009FCD8 */
    sw_(R[29] + 16, R[16]);  /* 0x8009FCDC */
    R[3] = lw_(R[17] + 72);  /* 0x8009FCE0 */
    R[16] = lw_(R[17] + 576);  /* 0x8009FCE4 */
    R[2] = lh_(R[3]);  /* 0x8009FCE8 */
    R[18] = (uint32_t)(int16_t)lh_(R[3] + 4);  /* 0x8009FCEC */
    R[2] = R[2] >> 13;  /* 0x8009FCF0 */
    R[2] = R[2] & 0x1;  /* 0x8009FCF4 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 115; if (_c) { goto L_8009FD24; } }  /* 0x8009FCF8 */
    R[2] = R[5] + R[0];  /* 0x8009FD00 */
    sh_(R[16] + 20, R[2]);  /* 0x8009FD04 */
    { R[31] = 0x8009FD10u; sb_(R[16] + 795, R[0]); psx_next = 0x8009BC84u; return; }  /* 0x8009FD08 jal */
    R[2] = lh_(R[16] + 4);  /* 0x8009FD10 */
    R[3] = lh_(R[17] + 4);  /* 0x8009FD14 */
    R[4] = 0x8013u << 16;  /* 0x8009FD18 */
    R[2] = R[2] - R[3];  /* 0x8009FD1C */
    sh_(R[4] + -29628, R[2]);  /* 0x8009FD20 */
L_8009FD24:;
    { uint32_t _c = ((int32_t)R[18] <= 0); R[4] = R[17] + R[0]; if (_c) { goto L_8009FD38; } }  /* 0x8009FD24 */
    R[5] = R[16] + R[0];  /* 0x8009FD2C */
    { R[31] = 0x8009FD38u; R[6] = R[0] + 1; psx_next = 0x8009BD74u; return; }  /* 0x8009FD30 jal */
L_8009FD38:;
    R[31] = lw_(R[29] + 28);  /* 0x8009FD38 */
    R[18] = lw_(R[29] + 24);  /* 0x8009FD3C */
    R[17] = lw_(R[29] + 20);  /* 0x8009FD40 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FD44 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009FD48 jr ra */
}

void g0_8009FD10(void) {
    R[2] = lh_(R[16] + 4);  /* 0x8009FD10 */
    R[3] = lh_(R[17] + 4);  /* 0x8009FD14 */
    R[4] = 0x8013u << 16;  /* 0x8009FD18 */
    R[2] = R[2] - R[3];  /* 0x8009FD1C */
    sh_(R[4] + -29628, R[2]);  /* 0x8009FD20 */
    { uint32_t _c = ((int32_t)R[18] <= 0); R[4] = R[17] + R[0]; if (_c) { goto L_8009FD38; } }  /* 0x8009FD24 */
    R[5] = R[16] + R[0];  /* 0x8009FD2C */
    { R[31] = 0x8009FD38u; R[6] = R[0] + 1; psx_next = 0x8009BD74u; return; }  /* 0x8009FD30 jal */
L_8009FD38:;
    R[31] = lw_(R[29] + 28);  /* 0x8009FD38 */
    R[18] = lw_(R[29] + 24);  /* 0x8009FD3C */
    R[17] = lw_(R[29] + 20);  /* 0x8009FD40 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FD44 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009FD48 jr ra */
}

void g0_8009FD38(void) {
    R[31] = lw_(R[29] + 28);  /* 0x8009FD38 */
    R[18] = lw_(R[29] + 24);  /* 0x8009FD3C */
    R[17] = lw_(R[29] + 20);  /* 0x8009FD40 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FD44 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009FD48 jr ra */
}

void g0_8009FD50(void) {
    R[29] = R[29] - 24;  /* 0x8009FD50 */
    sw_(R[29] + 16, R[16]);  /* 0x8009FD54 */
    R[16] = R[4] + R[0];  /* 0x8009FD58 */
    sw_(R[29] + 20, R[31]);  /* 0x8009FD5C */
    R[2] = lb_(R[16] + 496);  /* 0x8009FD60 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + R[0]; if (_c) { psx_next = 0x8009FD9Cu; return; } }  /* 0x8009FD68 b extern */
    R[6] = lw_(R[16] + 576);  /* 0x8009FD70 */
    R[5] = R[2] + R[0];  /* 0x8009FD74 */
    R[3] = R[16] + R[0];  /* 0x8009FD78 */
    R[2] = lw_(R[3] + 500);  /* 0x8009FD7C */
    psx_next = 0x8009FD80u; return;  /* fallthrough */
}

void g0_8009FD7C(void) {
    R[2] = lw_(R[3] + 500);  /* 0x8009FD7C */
    psx_next = 0x8009FD80u; return;  /* fallthrough */
}

void g0_8009FD80(void) {
    { uint32_t _c = (R[6] != R[2]); R[4] = R[4] + 1; if (_c) { goto L_8009FD94; } }  /* 0x8009FD84 */
    { R[2] = R[0] + R[0]; goto L_8009FDB8; }  /* 0x8009FD8C j */
L_8009FD94:;
    { uint32_t _c = (R[4] != R[5]); R[3] = R[3] + 4; if (_c) { psx_next = 0x8009FD7Cu; return; } }  /* 0x8009FD94 b extern */
    R[4] = R[16] + R[0];  /* 0x8009FD9C */
    { R[31] = 0x8009FDA8u; R[5] = R[0] + R[0]; psx_next = 0x8009C12Cu; return; }  /* 0x8009FDA0 jal */
    R[4] = R[16] + R[0];  /* 0x8009FDA8 */
    { R[31] = 0x8009FDB4u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009FDAC jal */
    R[2] = R[0] + 1;  /* 0x8009FDB4 */
L_8009FDB8:;
    R[31] = lw_(R[29] + 20);  /* 0x8009FDB8 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FDBC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FDC0 jr ra */
}

void g0_8009FD9C(void) {
    R[4] = R[16] + R[0];  /* 0x8009FD9C */
    { R[31] = 0x8009FDA8u; R[5] = R[0] + R[0]; psx_next = 0x8009C12Cu; return; }  /* 0x8009FDA0 jal */
    R[4] = R[16] + R[0];  /* 0x8009FDA8 */
    { R[31] = 0x8009FDB4u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009FDAC jal */
    R[2] = R[0] + 1;  /* 0x8009FDB4 */
    R[31] = lw_(R[29] + 20);  /* 0x8009FDB8 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FDBC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FDC0 jr ra */
}

void g0_8009FDA8(void) {
    R[4] = R[16] + R[0];  /* 0x8009FDA8 */
    { R[31] = 0x8009FDB4u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009FDAC jal */
    R[2] = R[0] + 1;  /* 0x8009FDB4 */
    R[31] = lw_(R[29] + 20);  /* 0x8009FDB8 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FDBC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FDC0 jr ra */
}

void g0_8009FDB4(void) {
    R[2] = R[0] + 1;  /* 0x8009FDB4 */
    R[31] = lw_(R[29] + 20);  /* 0x8009FDB8 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FDBC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FDC0 jr ra */
}

void g0_8009FDC8(void) {
    R[29] = R[29] - 24;  /* 0x8009FDC8 */
    sw_(R[29] + 16, R[16]);  /* 0x8009FDCC */
    sw_(R[29] + 20, R[31]);  /* 0x8009FDD0 */
    { R[31] = 0x8009FDDCu; R[16] = R[4] + R[0]; psx_next = 0x8009FD50u; return; }  /* 0x8009FDD4 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009FE0C; } }  /* 0x8009FDDC */
    R[2] = lw_(R[16] + 72);  /* 0x8009FDE4 */
    R[2] = lh_(R[2]);  /* 0x8009FDEC */
    R[2] = R[2] >> 13;  /* 0x8009FDF4 */
    R[2] = R[2] & 0x1;  /* 0x8009FDF8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009FE0C; } }  /* 0x8009FDFC */
    { R[31] = 0x8009FE0Cu; R[5] = R[0] + 114; psx_next = 0x8009BC84u; return; }  /* 0x8009FE04 jal */
L_8009FE0C:;
    R[31] = lw_(R[29] + 20);  /* 0x8009FE0C */
    R[16] = lw_(R[29] + 16);  /* 0x8009FE10 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FE14 jr ra */
}

void g0_8009FDDC(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009FE0C; } }  /* 0x8009FDDC */
    R[2] = lw_(R[16] + 72);  /* 0x8009FDE4 */
    R[2] = lh_(R[2]);  /* 0x8009FDEC */
    R[2] = R[2] >> 13;  /* 0x8009FDF4 */
    R[2] = R[2] & 0x1;  /* 0x8009FDF8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009FE0C; } }  /* 0x8009FDFC */
    { R[31] = 0x8009FE0Cu; R[5] = R[0] + 114; psx_next = 0x8009BC84u; return; }  /* 0x8009FE04 jal */
L_8009FE0C:;
    R[31] = lw_(R[29] + 20);  /* 0x8009FE0C */
    R[16] = lw_(R[29] + 16);  /* 0x8009FE10 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FE14 jr ra */
}

void g0_8009FE0C(void) {
    R[31] = lw_(R[29] + 20);  /* 0x8009FE0C */
    R[16] = lw_(R[29] + 16);  /* 0x8009FE10 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009FE14 jr ra */
}

void g0_8009FE1C(void) {
    R[29] = R[29] - 72;  /* 0x8009FE1C */
    sw_(R[29] + 56, R[18]);  /* 0x8009FE20 */
    R[18] = R[4] + R[0];  /* 0x8009FE24 */
    sw_(R[29] + 68, R[31]);  /* 0x8009FE28 */
    sw_(R[29] + 64, R[20]);  /* 0x8009FE2C */
    sw_(R[29] + 60, R[19]);  /* 0x8009FE30 */
    sw_(R[29] + 52, R[17]);  /* 0x8009FE34 */
    sw_(R[29] + 48, R[16]);  /* 0x8009FE38 */
    R[2] = lw_(R[18] + 72);  /* 0x8009FE3C */
    R[16] = lw_(R[18] + 576);  /* 0x8009FE40 */
    R[19] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x8009FE44 */
    R[2] = lh_(R[2]);  /* 0x8009FE48 */
    R[2] = R[2] >> 13;  /* 0x8009FE50 */
    R[2] = R[2] & 0x1;  /* 0x8009FE54 */
    { uint32_t _c = (R[2] == R[0]); R[20] = R[19] + R[0]; if (_c) { goto L_8009FE88; } }  /* 0x8009FE58 */
    R[5] = R[0] + 115;  /* 0x8009FE60 */
    R[2] = R[5] + R[0];  /* 0x8009FE64 */
    sh_(R[16] + 20, R[2]);  /* 0x8009FE68 */
    { R[31] = 0x8009FE74u; sb_(R[16] + 795, R[0]); psx_next = 0x8009BC84u; return; }  /* 0x8009FE6C jal */
    R[2] = lh_(R[16] + 4);  /* 0x8009FE74 */
    R[3] = lh_(R[18] + 4);  /* 0x8009FE78 */
    R[4] = 0x8013u << 16;  /* 0x8009FE7C */
    R[2] = R[2] - R[3];  /* 0x8009FE80 */
    sh_(R[4] + -29628, R[2]);  /* 0x8009FE84 */
L_8009FE88:;
    R[17] = R[19] - 6;  /* 0x8009FE88 */
    R[2] = (R[17] < (uint32_t)5u);  /* 0x8009FE8C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + 48; if (_c) { goto L_8009FED8; } }  /* 0x8009FE90 */
    { R[31] = 0x8009FEA0u; R[5] = R[29] + 16; psx_next = 0x80036EA8u; return; }  /* 0x8009FE98 jal */
    R[4] = R[29] + 16;  /* 0x8009FEA0 */
    R[5] = R[16] + 208;  /* 0x8009FEA4 */
    R[6] = R[5] + R[0];  /* 0x8009FEA8 */
    R[3] = R[17] << 1;  /* 0x8009FEAC */
    R[3] = R[3] + R[17];  /* 0x8009FEB0 */
    R[2] = R[3] << 4;  /* 0x8009FEB4 */
    R[2] = R[2] - R[3];  /* 0x8009FEB8 */
    sh_(R[16] + 208, R[2]);  /* 0x8009FEBC */
    sh_(R[16] + 212, R[0]);  /* 0x8009FEC0 */
    { R[31] = 0x8009FECCu; sh_(R[16] + 210, R[0]); psx_next = 0x80036688u; return; }  /* 0x8009FEC4 jal */
    R[2] = R[0] + 3;  /* 0x8009FECC */
    { sb_(R[16] + 795, R[2]); goto L_8009FF0C; }  /* 0x8009FED0 j */
L_8009FED8:;
    R[2] = R[0] + 12;  /* 0x8009FED8 */
    { uint32_t _c = (R[19] != R[2]); R[2] = ((int32_t)R[20] < 13); if (_c) { goto L_8009FEF8; } }  /* 0x8009FEDC */
    R[4] = R[18] + R[0];  /* 0x8009FEE4 */
    R[5] = R[16] + R[0];  /* 0x8009FEE8 */
    { R[31] = 0x8009FEF4u; R[6] = R[0] + R[0]; psx_next = 0x8009BD74u; return; }  /* 0x8009FEEC jal */
    R[2] = ((int32_t)R[20] < 13);  /* 0x8009FEF4 */
L_8009FEF8:;
    { uint32_t _c = (R[2] != R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_8009FF0C; } }  /* 0x8009FEF8 */
    R[5] = R[16] + R[0];  /* 0x8009FF00 */
    { R[31] = 0x8009FF0Cu; R[6] = R[0] + 1; psx_next = 0x8009BD74u; return; }  /* 0x8009FF04 jal */
L_8009FF0C:;
    R[31] = lw_(R[29] + 68);  /* 0x8009FF0C */
    R[20] = lw_(R[29] + 64);  /* 0x8009FF10 */
    R[19] = lw_(R[29] + 60);  /* 0x8009FF14 */
    R[18] = lw_(R[29] + 56);  /* 0x8009FF18 */
    R[17] = lw_(R[29] + 52);  /* 0x8009FF1C */
    R[16] = lw_(R[29] + 48);  /* 0x8009FF20 */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x8009FF24 jr ra */
}

void g0_8009FE74(void) {
    R[2] = lh_(R[16] + 4);  /* 0x8009FE74 */
    R[3] = lh_(R[18] + 4);  /* 0x8009FE78 */
    R[4] = 0x8013u << 16;  /* 0x8009FE7C */
    R[2] = R[2] - R[3];  /* 0x8009FE80 */
    sh_(R[4] + -29628, R[2]);  /* 0x8009FE84 */
    R[17] = R[19] - 6;  /* 0x8009FE88 */
    R[2] = (R[17] < (uint32_t)5u);  /* 0x8009FE8C */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + 48; if (_c) { goto L_8009FED8; } }  /* 0x8009FE90 */
    { R[31] = 0x8009FEA0u; R[5] = R[29] + 16; psx_next = 0x80036EA8u; return; }  /* 0x8009FE98 jal */
    R[4] = R[29] + 16;  /* 0x8009FEA0 */
    R[5] = R[16] + 208;  /* 0x8009FEA4 */
    R[6] = R[5] + R[0];  /* 0x8009FEA8 */
    R[3] = R[17] << 1;  /* 0x8009FEAC */
    R[3] = R[3] + R[17];  /* 0x8009FEB0 */
    R[2] = R[3] << 4;  /* 0x8009FEB4 */
    R[2] = R[2] - R[3];  /* 0x8009FEB8 */
    sh_(R[16] + 208, R[2]);  /* 0x8009FEBC */
    sh_(R[16] + 212, R[0]);  /* 0x8009FEC0 */
    { R[31] = 0x8009FECCu; sh_(R[16] + 210, R[0]); psx_next = 0x80036688u; return; }  /* 0x8009FEC4 jal */
    R[2] = R[0] + 3;  /* 0x8009FECC */
    { sb_(R[16] + 795, R[2]); goto L_8009FF0C; }  /* 0x8009FED0 j */
L_8009FED8:;
    R[2] = R[0] + 12;  /* 0x8009FED8 */
    { uint32_t _c = (R[19] != R[2]); R[2] = ((int32_t)R[20] < 13); if (_c) { goto L_8009FEF8; } }  /* 0x8009FEDC */
    R[4] = R[18] + R[0];  /* 0x8009FEE4 */
    R[5] = R[16] + R[0];  /* 0x8009FEE8 */
    { R[31] = 0x8009FEF4u; R[6] = R[0] + R[0]; psx_next = 0x8009BD74u; return; }  /* 0x8009FEEC jal */
    R[2] = ((int32_t)R[20] < 13);  /* 0x8009FEF4 */
L_8009FEF8:;
    { uint32_t _c = (R[2] != R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_8009FF0C; } }  /* 0x8009FEF8 */
    R[5] = R[16] + R[0];  /* 0x8009FF00 */
    { R[31] = 0x8009FF0Cu; R[6] = R[0] + 1; psx_next = 0x8009BD74u; return; }  /* 0x8009FF04 jal */
L_8009FF0C:;
    R[31] = lw_(R[29] + 68);  /* 0x8009FF0C */
    R[20] = lw_(R[29] + 64);  /* 0x8009FF10 */
    R[19] = lw_(R[29] + 60);  /* 0x8009FF14 */
    R[18] = lw_(R[29] + 56);  /* 0x8009FF18 */
    R[17] = lw_(R[29] + 52);  /* 0x8009FF1C */
    R[16] = lw_(R[29] + 48);  /* 0x8009FF20 */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x8009FF24 jr ra */
}

void g0_8009FEA0(void) {
    R[4] = R[29] + 16;  /* 0x8009FEA0 */
    R[5] = R[16] + 208;  /* 0x8009FEA4 */
    R[6] = R[5] + R[0];  /* 0x8009FEA8 */
    R[3] = R[17] << 1;  /* 0x8009FEAC */
    R[3] = R[3] + R[17];  /* 0x8009FEB0 */
    R[2] = R[3] << 4;  /* 0x8009FEB4 */
    R[2] = R[2] - R[3];  /* 0x8009FEB8 */
    sh_(R[16] + 208, R[2]);  /* 0x8009FEBC */
    sh_(R[16] + 212, R[0]);  /* 0x8009FEC0 */
    { R[31] = 0x8009FECCu; sh_(R[16] + 210, R[0]); psx_next = 0x80036688u; return; }  /* 0x8009FEC4 jal */
    R[2] = R[0] + 3;  /* 0x8009FECC */
    { sb_(R[16] + 795, R[2]); goto L_8009FF0C; }  /* 0x8009FED0 j */
    R[2] = R[0] + 12;  /* 0x8009FED8 */
    { uint32_t _c = (R[19] != R[2]); R[2] = ((int32_t)R[20] < 13); if (_c) { goto L_8009FEF8; } }  /* 0x8009FEDC */
    R[4] = R[18] + R[0];  /* 0x8009FEE4 */
    R[5] = R[16] + R[0];  /* 0x8009FEE8 */
    { R[31] = 0x8009FEF4u; R[6] = R[0] + R[0]; psx_next = 0x8009BD74u; return; }  /* 0x8009FEEC jal */
    R[2] = ((int32_t)R[20] < 13);  /* 0x8009FEF4 */
L_8009FEF8:;
    { uint32_t _c = (R[2] != R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_8009FF0C; } }  /* 0x8009FEF8 */
    R[5] = R[16] + R[0];  /* 0x8009FF00 */
    { R[31] = 0x8009FF0Cu; R[6] = R[0] + 1; psx_next = 0x8009BD74u; return; }  /* 0x8009FF04 jal */
L_8009FF0C:;
    R[31] = lw_(R[29] + 68);  /* 0x8009FF0C */
    R[20] = lw_(R[29] + 64);  /* 0x8009FF10 */
    R[19] = lw_(R[29] + 60);  /* 0x8009FF14 */
    R[18] = lw_(R[29] + 56);  /* 0x8009FF18 */
    R[17] = lw_(R[29] + 52);  /* 0x8009FF1C */
    R[16] = lw_(R[29] + 48);  /* 0x8009FF20 */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x8009FF24 jr ra */
}

void g0_8009FECC(void) {
    R[2] = R[0] + 3;  /* 0x8009FECC */
    { sb_(R[16] + 795, R[2]); goto L_8009FF0C; }  /* 0x8009FED0 j */
    R[2] = R[0] + 12;  /* 0x8009FED8 */
    { uint32_t _c = (R[19] != R[2]); R[2] = ((int32_t)R[20] < 13); if (_c) { goto L_8009FEF8; } }  /* 0x8009FEDC */
    R[4] = R[18] + R[0];  /* 0x8009FEE4 */
    R[5] = R[16] + R[0];  /* 0x8009FEE8 */
    { R[31] = 0x8009FEF4u; R[6] = R[0] + R[0]; psx_next = 0x8009BD74u; return; }  /* 0x8009FEEC jal */
    R[2] = ((int32_t)R[20] < 13);  /* 0x8009FEF4 */
L_8009FEF8:;
    { uint32_t _c = (R[2] != R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_8009FF0C; } }  /* 0x8009FEF8 */
    R[5] = R[16] + R[0];  /* 0x8009FF00 */
    { R[31] = 0x8009FF0Cu; R[6] = R[0] + 1; psx_next = 0x8009BD74u; return; }  /* 0x8009FF04 jal */
L_8009FF0C:;
    R[31] = lw_(R[29] + 68);  /* 0x8009FF0C */
    R[20] = lw_(R[29] + 64);  /* 0x8009FF10 */
    R[19] = lw_(R[29] + 60);  /* 0x8009FF14 */
    R[18] = lw_(R[29] + 56);  /* 0x8009FF18 */
    R[17] = lw_(R[29] + 52);  /* 0x8009FF1C */
    R[16] = lw_(R[29] + 48);  /* 0x8009FF20 */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x8009FF24 jr ra */
}

void g0_8009FEF4(void) {
    R[2] = ((int32_t)R[20] < 13);  /* 0x8009FEF4 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_8009FF0C; } }  /* 0x8009FEF8 */
    R[5] = R[16] + R[0];  /* 0x8009FF00 */
    { R[31] = 0x8009FF0Cu; R[6] = R[0] + 1; psx_next = 0x8009BD74u; return; }  /* 0x8009FF04 jal */
L_8009FF0C:;
    R[31] = lw_(R[29] + 68);  /* 0x8009FF0C */
    R[20] = lw_(R[29] + 64);  /* 0x8009FF10 */
    R[19] = lw_(R[29] + 60);  /* 0x8009FF14 */
    R[18] = lw_(R[29] + 56);  /* 0x8009FF18 */
    R[17] = lw_(R[29] + 52);  /* 0x8009FF1C */
    R[16] = lw_(R[29] + 48);  /* 0x8009FF20 */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x8009FF24 jr ra */
}

void g0_8009FF0C(void) {
    R[31] = lw_(R[29] + 68);  /* 0x8009FF0C */
    R[20] = lw_(R[29] + 64);  /* 0x8009FF10 */
    R[19] = lw_(R[29] + 60);  /* 0x8009FF14 */
    R[18] = lw_(R[29] + 56);  /* 0x8009FF18 */
    R[17] = lw_(R[29] + 52);  /* 0x8009FF1C */
    R[16] = lw_(R[29] + 48);  /* 0x8009FF20 */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x8009FF24 jr ra */
}

void g0_8009FF2C(void) {
    R[2] = 0x8006u << 16;  /* 0x8009FF2C */
    R[3] = 0x8006u << 16;  /* 0x8009FF30 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009FF34 */
    R[3] = lh_(R[3] + 16112);  /* 0x8009FF38 */
    R[2] = R[2] & R[3];  /* 0x8009FF40 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009FF54; } }  /* 0x8009FF44 */
    { R[2] = R[0] + R[0]; psx_next = R[31]; return; }  /* 0x8009FF4C jr ra */
L_8009FF54:;
    R[3] = R[0] + 4;  /* 0x8009FF54 */
    sb_(R[4] + 499, R[3]);  /* 0x8009FF58 */
    R[3] = 0x8013u << 16;  /* 0x8009FF5C */
    sh_(R[4] + 20, R[5]);  /* 0x8009FF60 */
    { sb_(R[3] + -29624, R[6]); psx_next = R[31]; return; }  /* 0x8009FF64 jr ra */
}

void g0_8009FF6C(void) {
    R[29] = R[29] - 64;  /* 0x8009FF6C */
    sw_(R[29] + 52, R[17]);  /* 0x8009FF70 */
    psx_next = 0x8009FF74u; return;  /* fallthrough */
}

void g0_8009FF74(void) {
    R[17] = R[4] + R[0];  /* 0x8009FF74 */
    sw_(R[29] + 56, R[31]);  /* 0x8009FF78 */
    sw_(R[29] + 48, R[16]);  /* 0x8009FF7C */
    R[2] = lb_(R[17] + 784);  /* 0x8009FF80 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] + 117; if (_c) { goto L_8009FFA0; } }  /* 0x8009FF88 */
    { R[31] = 0x8009FF98u; R[5] = R[0] + 118; psx_next = 0x8009BC84u; return; }  /* 0x8009FF90 jal */
    { goto L_800A0084; }  /* 0x8009FF98 j */
L_8009FFA0:;
    R[4] = R[17] + R[0];  /* 0x8009FFA0 */
    R[16] = lw_(R[17] + 576);  /* 0x8009FFA4 */
    R[6] = R[0] + R[0];  /* 0x8009FFA8 */
    { R[31] = 0x8009FFB4u; sb_(R[16] + 795, R[0]); psx_next = 0x8009D268u; return; }  /* 0x8009FFAC jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800A0084; } }  /* 0x8009FFB4 */
    R[5] = R[0] + 116;  /* 0x8009FFBC */
    R[6] = R[0] + 115;  /* 0x8009FFC0 */
    { R[31] = 0x8009FFCCu; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009FFC4 jal */
    R[4] = R[17] + R[0];  /* 0x8009FFCC */
    R[5] = R[0] + 120;  /* 0x8009FFD0 */
    { R[31] = 0x8009FFDCu; R[6] = R[2] + R[0]; psx_next = 0x8009FF2Cu; return; }  /* 0x8009FFD4 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800A0084; } }  /* 0x8009FFDC */
    R[2] = lh_(R[17] + 6);  /* 0x8009FFE4 */
    R[3] = 0x8013u << 16;  /* 0x8009FFE8 */
    sh_(R[16] + 6, R[2]);  /* 0x8009FFEC */
    R[2] = lh_(R[17] + 4);  /* 0x8009FFF0 */
    R[3] = lh_(R[3] + -29628);  /* 0x8009FFF4 */
    R[5] = R[0] + 115;  /* 0x8009FFF8 */
    R[2] = R[2] + R[3];  /* 0x8009FFFC */
    R[2] = R[2] & 0x1FF;  /* 0x800A0000 */
    { R[31] = 0x800A000Cu; sh_(R[16] + 4, R[2]); psx_next = 0x8009BC08u; return; }  /* 0x800A0004 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + 48; if (_c) { goto L_800A0054; } }  /* 0x800A000C */
    R[2] = lw_(R[17] + 72);  /* 0x800A0014 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x800A001C */
    R[2] = ((int32_t)R[3] < 15);  /* 0x800A0024 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] + 1; if (_c) { goto L_800A0038; } }  /* 0x800A0028 */
    R[2] = R[0] + 30;  /* 0x800A0030 */
    R[2] = R[2] - R[3];  /* 0x800A0034 */
L_800A0038:;
    R[3] = R[2] >> 31;  /* 0x800A0038 */
    R[2] = R[2] + R[3];  /* 0x800A003C */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x800A0040 */
    R[2] = R[2] << 12;  /* 0x800A0044 */
    R[2] = R[0] - R[2];  /* 0x800A0048 */
    { sw_(R[16] + 40, R[2]); goto L_800A0084; }  /* 0x800A004C j */
L_800A0054:;
    { R[31] = 0x800A005Cu; R[5] = R[29] + 16; psx_next = 0x80036EA8u; return; }  /* 0x800A0054 jal */
    R[4] = R[29] + 16;  /* 0x800A005C */
    R[5] = R[16] + 208;  /* 0x800A0060 */
    R[6] = R[5] + R[0];  /* 0x800A0064 */
    R[2] = R[0] + 113;  /* 0x800A0068 */
    sh_(R[16] + 208, R[2]);  /* 0x800A006C */
    sh_(R[16] + 212, R[0]);  /* 0x800A0070 */
    { R[31] = 0x800A007Cu; sh_(R[16] + 210, R[0]); psx_next = 0x80036688u; return; }  /* 0x800A0074 jal */
    R[2] = R[0] + 3;  /* 0x800A007C */
    sb_(R[16] + 795, R[2]);  /* 0x800A0080 */
L_800A0084:;
    R[31] = lw_(R[29] + 56);  /* 0x800A0084 */
    R[17] = lw_(R[29] + 52);  /* 0x800A0088 */
    R[16] = lw_(R[29] + 48);  /* 0x800A008C */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A0090 jr ra */
}

void g0_8009FF98(void) {
    { goto L_800A0084; }  /* 0x8009FF98 j */
    R[4] = R[17] + R[0];  /* 0x8009FFA0 */
    R[16] = lw_(R[17] + 576);  /* 0x8009FFA4 */
    R[6] = R[0] + R[0];  /* 0x8009FFA8 */
    { R[31] = 0x8009FFB4u; sb_(R[16] + 795, R[0]); psx_next = 0x8009D268u; return; }  /* 0x8009FFAC jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800A0084; } }  /* 0x8009FFB4 */
    R[5] = R[0] + 116;  /* 0x8009FFBC */
    R[6] = R[0] + 115;  /* 0x8009FFC0 */
    { R[31] = 0x8009FFCCu; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009FFC4 jal */
    R[4] = R[17] + R[0];  /* 0x8009FFCC */
    R[5] = R[0] + 120;  /* 0x8009FFD0 */
    { R[31] = 0x8009FFDCu; R[6] = R[2] + R[0]; psx_next = 0x8009FF2Cu; return; }  /* 0x8009FFD4 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800A0084; } }  /* 0x8009FFDC */
    R[2] = lh_(R[17] + 6);  /* 0x8009FFE4 */
    R[3] = 0x8013u << 16;  /* 0x8009FFE8 */
    sh_(R[16] + 6, R[2]);  /* 0x8009FFEC */
    R[2] = lh_(R[17] + 4);  /* 0x8009FFF0 */
    R[3] = lh_(R[3] + -29628);  /* 0x8009FFF4 */
    R[5] = R[0] + 115;  /* 0x8009FFF8 */
    R[2] = R[2] + R[3];  /* 0x8009FFFC */
    R[2] = R[2] & 0x1FF;  /* 0x800A0000 */
    { R[31] = 0x800A000Cu; sh_(R[16] + 4, R[2]); psx_next = 0x8009BC08u; return; }  /* 0x800A0004 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + 48; if (_c) { goto L_800A0054; } }  /* 0x800A000C */
    R[2] = lw_(R[17] + 72);  /* 0x800A0014 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x800A001C */
    R[2] = ((int32_t)R[3] < 15);  /* 0x800A0024 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] + 1; if (_c) { goto L_800A0038; } }  /* 0x800A0028 */
    R[2] = R[0] + 30;  /* 0x800A0030 */
    R[2] = R[2] - R[3];  /* 0x800A0034 */
L_800A0038:;
    R[3] = R[2] >> 31;  /* 0x800A0038 */
    R[2] = R[2] + R[3];  /* 0x800A003C */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x800A0040 */
    R[2] = R[2] << 12;  /* 0x800A0044 */
    R[2] = R[0] - R[2];  /* 0x800A0048 */
    { sw_(R[16] + 40, R[2]); goto L_800A0084; }  /* 0x800A004C j */
L_800A0054:;
    { R[31] = 0x800A005Cu; R[5] = R[29] + 16; psx_next = 0x80036EA8u; return; }  /* 0x800A0054 jal */
    R[4] = R[29] + 16;  /* 0x800A005C */
    R[5] = R[16] + 208;  /* 0x800A0060 */
    R[6] = R[5] + R[0];  /* 0x800A0064 */
    R[2] = R[0] + 113;  /* 0x800A0068 */
    sh_(R[16] + 208, R[2]);  /* 0x800A006C */
    sh_(R[16] + 212, R[0]);  /* 0x800A0070 */
    { R[31] = 0x800A007Cu; sh_(R[16] + 210, R[0]); psx_next = 0x80036688u; return; }  /* 0x800A0074 jal */
    R[2] = R[0] + 3;  /* 0x800A007C */
    sb_(R[16] + 795, R[2]);  /* 0x800A0080 */
L_800A0084:;
    R[31] = lw_(R[29] + 56);  /* 0x800A0084 */
    R[17] = lw_(R[29] + 52);  /* 0x800A0088 */
    R[16] = lw_(R[29] + 48);  /* 0x800A008C */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A0090 jr ra */
}

void g0_8009FFB4(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800A0084; } }  /* 0x8009FFB4 */
    R[5] = R[0] + 116;  /* 0x8009FFBC */
    R[6] = R[0] + 115;  /* 0x8009FFC0 */
    { R[31] = 0x8009FFCCu; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009FFC4 jal */
    R[4] = R[17] + R[0];  /* 0x8009FFCC */
    R[5] = R[0] + 120;  /* 0x8009FFD0 */
    { R[31] = 0x8009FFDCu; R[6] = R[2] + R[0]; psx_next = 0x8009FF2Cu; return; }  /* 0x8009FFD4 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800A0084; } }  /* 0x8009FFDC */
    R[2] = lh_(R[17] + 6);  /* 0x8009FFE4 */
    R[3] = 0x8013u << 16;  /* 0x8009FFE8 */
    sh_(R[16] + 6, R[2]);  /* 0x8009FFEC */
    R[2] = lh_(R[17] + 4);  /* 0x8009FFF0 */
    R[3] = lh_(R[3] + -29628);  /* 0x8009FFF4 */
    R[5] = R[0] + 115;  /* 0x8009FFF8 */
    R[2] = R[2] + R[3];  /* 0x8009FFFC */
    R[2] = R[2] & 0x1FF;  /* 0x800A0000 */
    { R[31] = 0x800A000Cu; sh_(R[16] + 4, R[2]); psx_next = 0x8009BC08u; return; }  /* 0x800A0004 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + 48; if (_c) { goto L_800A0054; } }  /* 0x800A000C */
    R[2] = lw_(R[17] + 72);  /* 0x800A0014 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x800A001C */
    R[2] = ((int32_t)R[3] < 15);  /* 0x800A0024 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] + 1; if (_c) { goto L_800A0038; } }  /* 0x800A0028 */
    R[2] = R[0] + 30;  /* 0x800A0030 */
    R[2] = R[2] - R[3];  /* 0x800A0034 */
L_800A0038:;
    R[3] = R[2] >> 31;  /* 0x800A0038 */
    R[2] = R[2] + R[3];  /* 0x800A003C */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x800A0040 */
    R[2] = R[2] << 12;  /* 0x800A0044 */
    R[2] = R[0] - R[2];  /* 0x800A0048 */
    { sw_(R[16] + 40, R[2]); goto L_800A0084; }  /* 0x800A004C j */
L_800A0054:;
    { R[31] = 0x800A005Cu; R[5] = R[29] + 16; psx_next = 0x80036EA8u; return; }  /* 0x800A0054 jal */
    R[4] = R[29] + 16;  /* 0x800A005C */
    R[5] = R[16] + 208;  /* 0x800A0060 */
    R[6] = R[5] + R[0];  /* 0x800A0064 */
    R[2] = R[0] + 113;  /* 0x800A0068 */
    sh_(R[16] + 208, R[2]);  /* 0x800A006C */
    sh_(R[16] + 212, R[0]);  /* 0x800A0070 */
    { R[31] = 0x800A007Cu; sh_(R[16] + 210, R[0]); psx_next = 0x80036688u; return; }  /* 0x800A0074 jal */
    R[2] = R[0] + 3;  /* 0x800A007C */
    sb_(R[16] + 795, R[2]);  /* 0x800A0080 */
L_800A0084:;
    R[31] = lw_(R[29] + 56);  /* 0x800A0084 */
    R[17] = lw_(R[29] + 52);  /* 0x800A0088 */
    R[16] = lw_(R[29] + 48);  /* 0x800A008C */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A0090 jr ra */
}

void g0_8009FFCC(void) {
    R[4] = R[17] + R[0];  /* 0x8009FFCC */
    R[5] = R[0] + 120;  /* 0x8009FFD0 */
    { R[31] = 0x8009FFDCu; R[6] = R[2] + R[0]; psx_next = 0x8009FF2Cu; return; }  /* 0x8009FFD4 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800A0084; } }  /* 0x8009FFDC */
    R[2] = lh_(R[17] + 6);  /* 0x8009FFE4 */
    R[3] = 0x8013u << 16;  /* 0x8009FFE8 */
    sh_(R[16] + 6, R[2]);  /* 0x8009FFEC */
    R[2] = lh_(R[17] + 4);  /* 0x8009FFF0 */
    R[3] = lh_(R[3] + -29628);  /* 0x8009FFF4 */
    R[5] = R[0] + 115;  /* 0x8009FFF8 */
    R[2] = R[2] + R[3];  /* 0x8009FFFC */
    R[2] = R[2] & 0x1FF;  /* 0x800A0000 */
    { R[31] = 0x800A000Cu; sh_(R[16] + 4, R[2]); psx_next = 0x8009BC08u; return; }  /* 0x800A0004 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + 48; if (_c) { goto L_800A0054; } }  /* 0x800A000C */
    R[2] = lw_(R[17] + 72);  /* 0x800A0014 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x800A001C */
    R[2] = ((int32_t)R[3] < 15);  /* 0x800A0024 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] + 1; if (_c) { goto L_800A0038; } }  /* 0x800A0028 */
    R[2] = R[0] + 30;  /* 0x800A0030 */
    R[2] = R[2] - R[3];  /* 0x800A0034 */
L_800A0038:;
    R[3] = R[2] >> 31;  /* 0x800A0038 */
    R[2] = R[2] + R[3];  /* 0x800A003C */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x800A0040 */
    R[2] = R[2] << 12;  /* 0x800A0044 */
    R[2] = R[0] - R[2];  /* 0x800A0048 */
    { sw_(R[16] + 40, R[2]); goto L_800A0084; }  /* 0x800A004C j */
L_800A0054:;
    { R[31] = 0x800A005Cu; R[5] = R[29] + 16; psx_next = 0x80036EA8u; return; }  /* 0x800A0054 jal */
    R[4] = R[29] + 16;  /* 0x800A005C */
    R[5] = R[16] + 208;  /* 0x800A0060 */
    R[6] = R[5] + R[0];  /* 0x800A0064 */
    R[2] = R[0] + 113;  /* 0x800A0068 */
    sh_(R[16] + 208, R[2]);  /* 0x800A006C */
    sh_(R[16] + 212, R[0]);  /* 0x800A0070 */
    { R[31] = 0x800A007Cu; sh_(R[16] + 210, R[0]); psx_next = 0x80036688u; return; }  /* 0x800A0074 jal */
    R[2] = R[0] + 3;  /* 0x800A007C */
    sb_(R[16] + 795, R[2]);  /* 0x800A0080 */
L_800A0084:;
    R[31] = lw_(R[29] + 56);  /* 0x800A0084 */
    R[17] = lw_(R[29] + 52);  /* 0x800A0088 */
    R[16] = lw_(R[29] + 48);  /* 0x800A008C */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A0090 jr ra */
}

void g0_8009FFDC(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800A0084; } }  /* 0x8009FFDC */
    R[2] = lh_(R[17] + 6);  /* 0x8009FFE4 */
    R[3] = 0x8013u << 16;  /* 0x8009FFE8 */
    sh_(R[16] + 6, R[2]);  /* 0x8009FFEC */
    R[2] = lh_(R[17] + 4);  /* 0x8009FFF0 */
    R[3] = lh_(R[3] + -29628);  /* 0x8009FFF4 */
    R[5] = R[0] + 115;  /* 0x8009FFF8 */
    R[2] = R[2] + R[3];  /* 0x8009FFFC */
    R[2] = R[2] & 0x1FF;  /* 0x800A0000 */
    { R[31] = 0x800A000Cu; sh_(R[16] + 4, R[2]); psx_next = 0x8009BC08u; return; }  /* 0x800A0004 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + 48; if (_c) { goto L_800A0054; } }  /* 0x800A000C */
    R[2] = lw_(R[17] + 72);  /* 0x800A0014 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x800A001C */
    R[2] = ((int32_t)R[3] < 15);  /* 0x800A0024 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] + 1; if (_c) { goto L_800A0038; } }  /* 0x800A0028 */
    R[2] = R[0] + 30;  /* 0x800A0030 */
    R[2] = R[2] - R[3];  /* 0x800A0034 */
L_800A0038:;
    R[3] = R[2] >> 31;  /* 0x800A0038 */
    R[2] = R[2] + R[3];  /* 0x800A003C */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x800A0040 */
    R[2] = R[2] << 12;  /* 0x800A0044 */
    R[2] = R[0] - R[2];  /* 0x800A0048 */
    { sw_(R[16] + 40, R[2]); goto L_800A0084; }  /* 0x800A004C j */
L_800A0054:;
    { R[31] = 0x800A005Cu; R[5] = R[29] + 16; psx_next = 0x80036EA8u; return; }  /* 0x800A0054 jal */
    R[4] = R[29] + 16;  /* 0x800A005C */
    R[5] = R[16] + 208;  /* 0x800A0060 */
    R[6] = R[5] + R[0];  /* 0x800A0064 */
    R[2] = R[0] + 113;  /* 0x800A0068 */
    sh_(R[16] + 208, R[2]);  /* 0x800A006C */
    sh_(R[16] + 212, R[0]);  /* 0x800A0070 */
    { R[31] = 0x800A007Cu; sh_(R[16] + 210, R[0]); psx_next = 0x80036688u; return; }  /* 0x800A0074 jal */
    R[2] = R[0] + 3;  /* 0x800A007C */
    sb_(R[16] + 795, R[2]);  /* 0x800A0080 */
L_800A0084:;
    R[31] = lw_(R[29] + 56);  /* 0x800A0084 */
    R[17] = lw_(R[29] + 52);  /* 0x800A0088 */
    R[16] = lw_(R[29] + 48);  /* 0x800A008C */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A0090 jr ra */
}

void g0_800A000C(void) {
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + 48; if (_c) { goto L_800A0054; } }  /* 0x800A000C */
    R[2] = lw_(R[17] + 72);  /* 0x800A0014 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x800A001C */
    R[2] = ((int32_t)R[3] < 15);  /* 0x800A0024 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] + 1; if (_c) { goto L_800A0038; } }  /* 0x800A0028 */
    R[2] = R[0] + 30;  /* 0x800A0030 */
    R[2] = R[2] - R[3];  /* 0x800A0034 */
L_800A0038:;
    R[3] = R[2] >> 31;  /* 0x800A0038 */
    R[2] = R[2] + R[3];  /* 0x800A003C */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x800A0040 */
    R[2] = R[2] << 12;  /* 0x800A0044 */
    R[2] = R[0] - R[2];  /* 0x800A0048 */
    { sw_(R[16] + 40, R[2]); goto L_800A0084; }  /* 0x800A004C j */
L_800A0054:;
    { R[31] = 0x800A005Cu; R[5] = R[29] + 16; psx_next = 0x80036EA8u; return; }  /* 0x800A0054 jal */
    R[4] = R[29] + 16;  /* 0x800A005C */
    R[5] = R[16] + 208;  /* 0x800A0060 */
    R[6] = R[5] + R[0];  /* 0x800A0064 */
    R[2] = R[0] + 113;  /* 0x800A0068 */
    sh_(R[16] + 208, R[2]);  /* 0x800A006C */
    sh_(R[16] + 212, R[0]);  /* 0x800A0070 */
    { R[31] = 0x800A007Cu; sh_(R[16] + 210, R[0]); psx_next = 0x80036688u; return; }  /* 0x800A0074 jal */
    R[2] = R[0] + 3;  /* 0x800A007C */
    sb_(R[16] + 795, R[2]);  /* 0x800A0080 */
L_800A0084:;
    R[31] = lw_(R[29] + 56);  /* 0x800A0084 */
    R[17] = lw_(R[29] + 52);  /* 0x800A0088 */
    R[16] = lw_(R[29] + 48);  /* 0x800A008C */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A0090 jr ra */
}

void g0_800A005C(void) {
    R[4] = R[29] + 16;  /* 0x800A005C */
    R[5] = R[16] + 208;  /* 0x800A0060 */
    R[6] = R[5] + R[0];  /* 0x800A0064 */
    R[2] = R[0] + 113;  /* 0x800A0068 */
    sh_(R[16] + 208, R[2]);  /* 0x800A006C */
    sh_(R[16] + 212, R[0]);  /* 0x800A0070 */
    { R[31] = 0x800A007Cu; sh_(R[16] + 210, R[0]); psx_next = 0x80036688u; return; }  /* 0x800A0074 jal */
    R[2] = R[0] + 3;  /* 0x800A007C */
    sb_(R[16] + 795, R[2]);  /* 0x800A0080 */
    R[31] = lw_(R[29] + 56);  /* 0x800A0084 */
    R[17] = lw_(R[29] + 52);  /* 0x800A0088 */
    R[16] = lw_(R[29] + 48);  /* 0x800A008C */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A0090 jr ra */
}

void g0_800A007C(void) {
    R[2] = R[0] + 3;  /* 0x800A007C */
    sb_(R[16] + 795, R[2]);  /* 0x800A0080 */
    R[31] = lw_(R[29] + 56);  /* 0x800A0084 */
    R[17] = lw_(R[29] + 52);  /* 0x800A0088 */
    R[16] = lw_(R[29] + 48);  /* 0x800A008C */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A0090 jr ra */
}

void g0_800A0098(void) {
    R[29] = R[29] - 24;  /* 0x800A0098 */
    sw_(R[29] + 16, R[16]);  /* 0x800A009C */
    sw_(R[29] + 20, R[31]);  /* 0x800A00A0 */
    { R[31] = 0x800A00ACu; R[16] = R[4] + R[0]; psx_next = 0x8009D8D0u; return; }  /* 0x800A00A4 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { psx_next = 0x800A01A0u; return; } }  /* 0x800A00AC b extern */
    R[5] = R[0] + 117;  /* 0x800A00B4 */
    { R[31] = 0x800A00C0u; R[6] = R[0] + 1; psx_next = 0x8009D268u; return; }  /* 0x800A00B8 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x800A01A0u; return; } }  /* 0x800A00C0 b extern */
    R[2] = lb_(R[16] + 784);  /* 0x800A00C8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_800A00F0; } }  /* 0x800A00D0 */
    R[5] = R[0] + 116;  /* 0x800A00D8 */
    R[6] = R[0] + 115;  /* 0x800A00DC */
    { R[31] = 0x800A00E8u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x800A00E0 jal */
    { psx_next = 0x800A0130u; return; }  /* 0x800A00E8 j extern */
L_800A00F0:;
    R[5] = R[0] - 1;  /* 0x800A00F0 */
    R[6] = R[5] + R[0];  /* 0x800A00F4 */
    { R[31] = 0x800A0100u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x800A00F8 jal */
    R[6] = R[2] + R[0];  /* 0x800A0100 */
    { uint32_t _c = (R[6] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_800A0114; } }  /* 0x800A0104 */
    { sw_(R[16] + 124, R[0]); psx_next = 0x800A0124u; return; }  /* 0x800A010C j extern */
L_800A0114:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x800A0114 */
    psx_next = 0x800A011Cu; return;  /* fallthrough */
}

void g0_800A00AC(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { psx_next = 0x800A01A0u; return; } }  /* 0x800A00AC b extern */
    R[5] = R[0] + 117;  /* 0x800A00B4 */
    { R[31] = 0x800A00C0u; R[6] = R[0] + 1; psx_next = 0x8009D268u; return; }  /* 0x800A00B8 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x800A01A0u; return; } }  /* 0x800A00C0 b extern */
    R[2] = lb_(R[16] + 784);  /* 0x800A00C8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_800A00F0; } }  /* 0x800A00D0 */
    R[5] = R[0] + 116;  /* 0x800A00D8 */
    R[6] = R[0] + 115;  /* 0x800A00DC */
    { R[31] = 0x800A00E8u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x800A00E0 jal */
    { psx_next = 0x800A0130u; return; }  /* 0x800A00E8 j extern */
L_800A00F0:;
    R[5] = R[0] - 1;  /* 0x800A00F0 */
    R[6] = R[5] + R[0];  /* 0x800A00F4 */
    { R[31] = 0x800A0100u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x800A00F8 jal */
    R[6] = R[2] + R[0];  /* 0x800A0100 */
    { uint32_t _c = (R[6] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_800A0114; } }  /* 0x800A0104 */
    { sw_(R[16] + 124, R[0]); psx_next = 0x800A0124u; return; }  /* 0x800A010C j extern */
L_800A0114:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x800A0114 */
    psx_next = 0x800A011Cu; return;  /* fallthrough */
}

void g0_800A00C0(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x800A01A0u; return; } }  /* 0x800A00C0 b extern */
    R[2] = lb_(R[16] + 784);  /* 0x800A00C8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_800A00F0; } }  /* 0x800A00D0 */
    R[5] = R[0] + 116;  /* 0x800A00D8 */
    R[6] = R[0] + 115;  /* 0x800A00DC */
    { R[31] = 0x800A00E8u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x800A00E0 jal */
    { psx_next = 0x800A0130u; return; }  /* 0x800A00E8 j extern */
L_800A00F0:;
    R[5] = R[0] - 1;  /* 0x800A00F0 */
    R[6] = R[5] + R[0];  /* 0x800A00F4 */
    { R[31] = 0x800A0100u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x800A00F8 jal */
    R[6] = R[2] + R[0];  /* 0x800A0100 */
    { uint32_t _c = (R[6] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_800A0114; } }  /* 0x800A0104 */
    { sw_(R[16] + 124, R[0]); psx_next = 0x800A0124u; return; }  /* 0x800A010C j extern */
L_800A0114:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x800A0114 */
    psx_next = 0x800A011Cu; return;  /* fallthrough */
}
