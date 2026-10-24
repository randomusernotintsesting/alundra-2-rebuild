#include "scps_decls.h"

void f_8001AA7C(void) {
    { R[31] = 0x8001AA84u; psx_next = 0x8001A694u; return; }  /* 0x8001AA7C jal */
    R[2] = 0x8006u << 16;  /* 0x8001AA84 */
    sw_(R[2] + -12280, R[0]);  /* 0x8001AA88 */
    R[4] = 0x8006u << 16;  /* 0x8001AA8C */
    { R[31] = 0x8001AA98u; R[4] = R[4] - 12248; psx_next = 0x800324E8u; return; }  /* 0x8001AA90 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001AB0C; } }  /* 0x8001AA98 */
    { R[31] = 0x8001AAA8u; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x8001AAA0 jal */
    { R[31] = 0x8001AAB0u; R[4] = R[0] + 3; psx_next = 0x80032578u; return; }  /* 0x8001AAA8 jal */
    { R[31] = 0x8001AAB8u; psx_next = 0x8002B12Cu; return; }  /* 0x8001AAB0 jal */
    { R[31] = 0x8001AAC0u; psx_next = 0x8001BB60u; return; }  /* 0x8001AAB8 jal */
    { R[31] = 0x8001AAC8u; psx_next = 0x8001C030u; return; }  /* 0x8001AAC0 jal */
    R[4] = R[29] + 16;  /* 0x8001AAC8 */
    R[5] = R[0] + R[0];  /* 0x8001AACC */
    R[6] = R[5] + R[0];  /* 0x8001AAD0 */
    R[7] = R[5] + R[0];  /* 0x8001AAD4 */
    R[2] = R[0] + 320;  /* 0x8001AAD8 */
    sh_(R[29] + 20, R[2]);  /* 0x8001AADC */
    R[2] = R[0] + 512;  /* 0x8001AAE0 */
    sh_(R[29] + 16, R[0]);  /* 0x8001AAE4 */
    sh_(R[29] + 18, R[0]);  /* 0x8001AAE8 */
    { R[31] = 0x8001AAF4u; sh_(R[29] + 22, R[2]); psx_next = 0x80032B08u; return; }  /* 0x8001AAEC jal */
    { R[31] = 0x8001AAFCu; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x8001AAF4 jal */
    R[3] = 0x8006u << 16;  /* 0x8001AAFC */
    R[2] = R[0] + 180;  /* 0x8001AB00 */
    { sw_(R[3] + -12280, R[2]); goto L_8001AB68; }  /* 0x8001AB04 j */
L_8001AB0C:;
    { R[31] = 0x8001AB14u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB0C jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB14 */
    R[2] = lw_(R[2] + -6472);  /* 0x8001AB18 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001AB68; } }  /* 0x8001AB20 */
    { R[31] = 0x8001AB30u; psx_next = 0x8001A764u; return; }  /* 0x8001AB28 jal */
    { R[31] = 0x8001AB38u; psx_next = 0x8001CEC4u; return; }  /* 0x8001AB30 jal */
    R[2] = 0x8001u << 16;  /* 0x8001AB38 */
    R[4] = lw_(R[2] + 28884);  /* 0x8001AB3C */
    { R[31] = 0x8001AB48u; R[5] = R[0] + R[0]; psx_next = 0x80021034u; return; }  /* 0x8001AB40 jal */
    R[4] = R[0] + 270;  /* 0x8001AB48 */
    R[3] = 0x8006u << 16;  /* 0x8001AB4C */
    R[2] = R[0] + 1;  /* 0x8001AB50 */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB54 */
    R[3] = 0x8006u << 16;  /* 0x8001AB58 */
    R[2] = R[4] + R[0];  /* 0x8001AB5C */
    { R[31] = 0x8001AB68u; sw_(R[3] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB60 jal */
L_8001AB68:;
    { R[31] = 0x8001AB70u; R[4] = R[0] + R[0]; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB68 jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB70 */
    { R[31] = 0x8001AB7Cu; sw_(R[2] + -12120, R[0]); psx_next = 0x8001CEC4u; return; }  /* 0x8001AB74 jal */
    { R[31] = 0x8001AB84u; R[16] = 0x8006u << 16; psx_next = 0x8001A764u; return; }  /* 0x8001AB7C jal */
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_bb(); goto L_8001AB0C; } }  /* 0x8001ABA4 */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_bb(); goto L_8001AB68; } }  /* 0x8001ABE0 */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001AA84(void) {
    R[2] = 0x8006u << 16;  /* 0x8001AA84 */
    sw_(R[2] + -12280, R[0]);  /* 0x8001AA88 */
    R[4] = 0x8006u << 16;  /* 0x8001AA8C */
    { R[31] = 0x8001AA98u; R[4] = R[4] - 12248; psx_next = 0x800324E8u; return; }  /* 0x8001AA90 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001AB0C; } }  /* 0x8001AA98 */
    { R[31] = 0x8001AAA8u; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x8001AAA0 jal */
    { R[31] = 0x8001AAB0u; R[4] = R[0] + 3; psx_next = 0x80032578u; return; }  /* 0x8001AAA8 jal */
    { R[31] = 0x8001AAB8u; psx_next = 0x8002B12Cu; return; }  /* 0x8001AAB0 jal */
    { R[31] = 0x8001AAC0u; psx_next = 0x8001BB60u; return; }  /* 0x8001AAB8 jal */
    { R[31] = 0x8001AAC8u; psx_next = 0x8001C030u; return; }  /* 0x8001AAC0 jal */
    R[4] = R[29] + 16;  /* 0x8001AAC8 */
    R[5] = R[0] + R[0];  /* 0x8001AACC */
    R[6] = R[5] + R[0];  /* 0x8001AAD0 */
    R[7] = R[5] + R[0];  /* 0x8001AAD4 */
    R[2] = R[0] + 320;  /* 0x8001AAD8 */
    sh_(R[29] + 20, R[2]);  /* 0x8001AADC */
    R[2] = R[0] + 512;  /* 0x8001AAE0 */
    sh_(R[29] + 16, R[0]);  /* 0x8001AAE4 */
    sh_(R[29] + 18, R[0]);  /* 0x8001AAE8 */
    { R[31] = 0x8001AAF4u; sh_(R[29] + 22, R[2]); psx_next = 0x80032B08u; return; }  /* 0x8001AAEC jal */
    { R[31] = 0x8001AAFCu; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x8001AAF4 jal */
    R[3] = 0x8006u << 16;  /* 0x8001AAFC */
    R[2] = R[0] + 180;  /* 0x8001AB00 */
    { sw_(R[3] + -12280, R[2]); goto L_8001AB68; }  /* 0x8001AB04 j */
L_8001AB0C:;
    { R[31] = 0x8001AB14u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB0C jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB14 */
    R[2] = lw_(R[2] + -6472);  /* 0x8001AB18 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001AB68; } }  /* 0x8001AB20 */
    { R[31] = 0x8001AB30u; psx_next = 0x8001A764u; return; }  /* 0x8001AB28 jal */
    { R[31] = 0x8001AB38u; psx_next = 0x8001CEC4u; return; }  /* 0x8001AB30 jal */
    R[2] = 0x8001u << 16;  /* 0x8001AB38 */
    R[4] = lw_(R[2] + 28884);  /* 0x8001AB3C */
    { R[31] = 0x8001AB48u; R[5] = R[0] + R[0]; psx_next = 0x80021034u; return; }  /* 0x8001AB40 jal */
    R[4] = R[0] + 270;  /* 0x8001AB48 */
    R[3] = 0x8006u << 16;  /* 0x8001AB4C */
    R[2] = R[0] + 1;  /* 0x8001AB50 */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB54 */
    R[3] = 0x8006u << 16;  /* 0x8001AB58 */
    R[2] = R[4] + R[0];  /* 0x8001AB5C */
    { R[31] = 0x8001AB68u; sw_(R[3] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB60 jal */
L_8001AB68:;
    { R[31] = 0x8001AB70u; R[4] = R[0] + R[0]; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB68 jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB70 */
    { R[31] = 0x8001AB7Cu; sw_(R[2] + -12120, R[0]); psx_next = 0x8001CEC4u; return; }  /* 0x8001AB74 jal */
    { R[31] = 0x8001AB84u; R[16] = 0x8006u << 16; psx_next = 0x8001A764u; return; }  /* 0x8001AB7C jal */
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_bb(); goto L_8001AB0C; } }  /* 0x8001ABA4 */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_bb(); goto L_8001AB68; } }  /* 0x8001ABE0 */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001AA98(void) {
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001AB0C; } }  /* 0x8001AA98 */
    { R[31] = 0x8001AAA8u; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x8001AAA0 jal */
    { R[31] = 0x8001AAB0u; R[4] = R[0] + 3; psx_next = 0x80032578u; return; }  /* 0x8001AAA8 jal */
    { R[31] = 0x8001AAB8u; psx_next = 0x8002B12Cu; return; }  /* 0x8001AAB0 jal */
    { R[31] = 0x8001AAC0u; psx_next = 0x8001BB60u; return; }  /* 0x8001AAB8 jal */
    { R[31] = 0x8001AAC8u; psx_next = 0x8001C030u; return; }  /* 0x8001AAC0 jal */
    R[4] = R[29] + 16;  /* 0x8001AAC8 */
    R[5] = R[0] + R[0];  /* 0x8001AACC */
    R[6] = R[5] + R[0];  /* 0x8001AAD0 */
    R[7] = R[5] + R[0];  /* 0x8001AAD4 */
    R[2] = R[0] + 320;  /* 0x8001AAD8 */
    sh_(R[29] + 20, R[2]);  /* 0x8001AADC */
    R[2] = R[0] + 512;  /* 0x8001AAE0 */
    sh_(R[29] + 16, R[0]);  /* 0x8001AAE4 */
    sh_(R[29] + 18, R[0]);  /* 0x8001AAE8 */
    { R[31] = 0x8001AAF4u; sh_(R[29] + 22, R[2]); psx_next = 0x80032B08u; return; }  /* 0x8001AAEC jal */
    { R[31] = 0x8001AAFCu; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x8001AAF4 jal */
    R[3] = 0x8006u << 16;  /* 0x8001AAFC */
    R[2] = R[0] + 180;  /* 0x8001AB00 */
    { sw_(R[3] + -12280, R[2]); goto L_8001AB68; }  /* 0x8001AB04 j */
L_8001AB0C:;
    { R[31] = 0x8001AB14u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB0C jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB14 */
    R[2] = lw_(R[2] + -6472);  /* 0x8001AB18 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001AB68; } }  /* 0x8001AB20 */
    { R[31] = 0x8001AB30u; psx_next = 0x8001A764u; return; }  /* 0x8001AB28 jal */
    { R[31] = 0x8001AB38u; psx_next = 0x8001CEC4u; return; }  /* 0x8001AB30 jal */
    R[2] = 0x8001u << 16;  /* 0x8001AB38 */
    R[4] = lw_(R[2] + 28884);  /* 0x8001AB3C */
    { R[31] = 0x8001AB48u; R[5] = R[0] + R[0]; psx_next = 0x80021034u; return; }  /* 0x8001AB40 jal */
    R[4] = R[0] + 270;  /* 0x8001AB48 */
    R[3] = 0x8006u << 16;  /* 0x8001AB4C */
    R[2] = R[0] + 1;  /* 0x8001AB50 */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB54 */
    R[3] = 0x8006u << 16;  /* 0x8001AB58 */
    R[2] = R[4] + R[0];  /* 0x8001AB5C */
    { R[31] = 0x8001AB68u; sw_(R[3] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB60 jal */
L_8001AB68:;
    { R[31] = 0x8001AB70u; R[4] = R[0] + R[0]; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB68 jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB70 */
    { R[31] = 0x8001AB7Cu; sw_(R[2] + -12120, R[0]); psx_next = 0x8001CEC4u; return; }  /* 0x8001AB74 jal */
    { R[31] = 0x8001AB84u; R[16] = 0x8006u << 16; psx_next = 0x8001A764u; return; }  /* 0x8001AB7C jal */
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_bb(); goto L_8001AB0C; } }  /* 0x8001ABA4 */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_bb(); goto L_8001AB68; } }  /* 0x8001ABE0 */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001AAA8(void) {
    { R[31] = 0x8001AAB0u; R[4] = R[0] + 3; psx_next = 0x80032578u; return; }  /* 0x8001AAA8 jal */
    { R[31] = 0x8001AAB8u; psx_next = 0x8002B12Cu; return; }  /* 0x8001AAB0 jal */
    { R[31] = 0x8001AAC0u; psx_next = 0x8001BB60u; return; }  /* 0x8001AAB8 jal */
    { R[31] = 0x8001AAC8u; psx_next = 0x8001C030u; return; }  /* 0x8001AAC0 jal */
    R[4] = R[29] + 16;  /* 0x8001AAC8 */
    R[5] = R[0] + R[0];  /* 0x8001AACC */
    R[6] = R[5] + R[0];  /* 0x8001AAD0 */
    R[7] = R[5] + R[0];  /* 0x8001AAD4 */
    R[2] = R[0] + 320;  /* 0x8001AAD8 */
    sh_(R[29] + 20, R[2]);  /* 0x8001AADC */
    R[2] = R[0] + 512;  /* 0x8001AAE0 */
    sh_(R[29] + 16, R[0]);  /* 0x8001AAE4 */
    sh_(R[29] + 18, R[0]);  /* 0x8001AAE8 */
    { R[31] = 0x8001AAF4u; sh_(R[29] + 22, R[2]); psx_next = 0x80032B08u; return; }  /* 0x8001AAEC jal */
    { R[31] = 0x8001AAFCu; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x8001AAF4 jal */
    R[3] = 0x8006u << 16;  /* 0x8001AAFC */
    R[2] = R[0] + 180;  /* 0x8001AB00 */
    { sw_(R[3] + -12280, R[2]); goto L_8001AB68; }  /* 0x8001AB04 j */
L_8001AB0C:;
    { R[31] = 0x8001AB14u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB0C jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB14 */
    R[2] = lw_(R[2] + -6472);  /* 0x8001AB18 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001AB68; } }  /* 0x8001AB20 */
    { R[31] = 0x8001AB30u; psx_next = 0x8001A764u; return; }  /* 0x8001AB28 jal */
    { R[31] = 0x8001AB38u; psx_next = 0x8001CEC4u; return; }  /* 0x8001AB30 jal */
    R[2] = 0x8001u << 16;  /* 0x8001AB38 */
    R[4] = lw_(R[2] + 28884);  /* 0x8001AB3C */
    { R[31] = 0x8001AB48u; R[5] = R[0] + R[0]; psx_next = 0x80021034u; return; }  /* 0x8001AB40 jal */
    R[4] = R[0] + 270;  /* 0x8001AB48 */
    R[3] = 0x8006u << 16;  /* 0x8001AB4C */
    R[2] = R[0] + 1;  /* 0x8001AB50 */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB54 */
    R[3] = 0x8006u << 16;  /* 0x8001AB58 */
    R[2] = R[4] + R[0];  /* 0x8001AB5C */
    { R[31] = 0x8001AB68u; sw_(R[3] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB60 jal */
L_8001AB68:;
    { R[31] = 0x8001AB70u; R[4] = R[0] + R[0]; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB68 jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB70 */
    { R[31] = 0x8001AB7Cu; sw_(R[2] + -12120, R[0]); psx_next = 0x8001CEC4u; return; }  /* 0x8001AB74 jal */
    { R[31] = 0x8001AB84u; R[16] = 0x8006u << 16; psx_next = 0x8001A764u; return; }  /* 0x8001AB7C jal */
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_bb(); goto L_8001AB0C; } }  /* 0x8001ABA4 */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_bb(); goto L_8001AB68; } }  /* 0x8001ABE0 */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001AAB0(void) {
    { R[31] = 0x8001AAB8u; psx_next = 0x8002B12Cu; return; }  /* 0x8001AAB0 jal */
    { R[31] = 0x8001AAC0u; psx_next = 0x8001BB60u; return; }  /* 0x8001AAB8 jal */
    { R[31] = 0x8001AAC8u; psx_next = 0x8001C030u; return; }  /* 0x8001AAC0 jal */
    R[4] = R[29] + 16;  /* 0x8001AAC8 */
    R[5] = R[0] + R[0];  /* 0x8001AACC */
    R[6] = R[5] + R[0];  /* 0x8001AAD0 */
    R[7] = R[5] + R[0];  /* 0x8001AAD4 */
    R[2] = R[0] + 320;  /* 0x8001AAD8 */
    sh_(R[29] + 20, R[2]);  /* 0x8001AADC */
    R[2] = R[0] + 512;  /* 0x8001AAE0 */
    sh_(R[29] + 16, R[0]);  /* 0x8001AAE4 */
    sh_(R[29] + 18, R[0]);  /* 0x8001AAE8 */
    { R[31] = 0x8001AAF4u; sh_(R[29] + 22, R[2]); psx_next = 0x80032B08u; return; }  /* 0x8001AAEC jal */
    { R[31] = 0x8001AAFCu; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x8001AAF4 jal */
    R[3] = 0x8006u << 16;  /* 0x8001AAFC */
    R[2] = R[0] + 180;  /* 0x8001AB00 */
    { sw_(R[3] + -12280, R[2]); goto L_8001AB68; }  /* 0x8001AB04 j */
L_8001AB0C:;
    { R[31] = 0x8001AB14u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB0C jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB14 */
    R[2] = lw_(R[2] + -6472);  /* 0x8001AB18 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001AB68; } }  /* 0x8001AB20 */
    { R[31] = 0x8001AB30u; psx_next = 0x8001A764u; return; }  /* 0x8001AB28 jal */
    { R[31] = 0x8001AB38u; psx_next = 0x8001CEC4u; return; }  /* 0x8001AB30 jal */
    R[2] = 0x8001u << 16;  /* 0x8001AB38 */
    R[4] = lw_(R[2] + 28884);  /* 0x8001AB3C */
    { R[31] = 0x8001AB48u; R[5] = R[0] + R[0]; psx_next = 0x80021034u; return; }  /* 0x8001AB40 jal */
    R[4] = R[0] + 270;  /* 0x8001AB48 */
    R[3] = 0x8006u << 16;  /* 0x8001AB4C */
    R[2] = R[0] + 1;  /* 0x8001AB50 */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB54 */
    R[3] = 0x8006u << 16;  /* 0x8001AB58 */
    R[2] = R[4] + R[0];  /* 0x8001AB5C */
    { R[31] = 0x8001AB68u; sw_(R[3] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB60 jal */
L_8001AB68:;
    { R[31] = 0x8001AB70u; R[4] = R[0] + R[0]; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB68 jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB70 */
    { R[31] = 0x8001AB7Cu; sw_(R[2] + -12120, R[0]); psx_next = 0x8001CEC4u; return; }  /* 0x8001AB74 jal */
    { R[31] = 0x8001AB84u; R[16] = 0x8006u << 16; psx_next = 0x8001A764u; return; }  /* 0x8001AB7C jal */
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_bb(); goto L_8001AB0C; } }  /* 0x8001ABA4 */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_bb(); goto L_8001AB68; } }  /* 0x8001ABE0 */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001AAB8(void) {
    { R[31] = 0x8001AAC0u; psx_next = 0x8001BB60u; return; }  /* 0x8001AAB8 jal */
    { R[31] = 0x8001AAC8u; psx_next = 0x8001C030u; return; }  /* 0x8001AAC0 jal */
    R[4] = R[29] + 16;  /* 0x8001AAC8 */
    R[5] = R[0] + R[0];  /* 0x8001AACC */
    R[6] = R[5] + R[0];  /* 0x8001AAD0 */
    R[7] = R[5] + R[0];  /* 0x8001AAD4 */
    R[2] = R[0] + 320;  /* 0x8001AAD8 */
    sh_(R[29] + 20, R[2]);  /* 0x8001AADC */
    R[2] = R[0] + 512;  /* 0x8001AAE0 */
    sh_(R[29] + 16, R[0]);  /* 0x8001AAE4 */
    sh_(R[29] + 18, R[0]);  /* 0x8001AAE8 */
    { R[31] = 0x8001AAF4u; sh_(R[29] + 22, R[2]); psx_next = 0x80032B08u; return; }  /* 0x8001AAEC jal */
    { R[31] = 0x8001AAFCu; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x8001AAF4 jal */
    R[3] = 0x8006u << 16;  /* 0x8001AAFC */
    R[2] = R[0] + 180;  /* 0x8001AB00 */
    { sw_(R[3] + -12280, R[2]); goto L_8001AB68; }  /* 0x8001AB04 j */
L_8001AB0C:;
    { R[31] = 0x8001AB14u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB0C jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB14 */
    R[2] = lw_(R[2] + -6472);  /* 0x8001AB18 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001AB68; } }  /* 0x8001AB20 */
    { R[31] = 0x8001AB30u; psx_next = 0x8001A764u; return; }  /* 0x8001AB28 jal */
    { R[31] = 0x8001AB38u; psx_next = 0x8001CEC4u; return; }  /* 0x8001AB30 jal */
    R[2] = 0x8001u << 16;  /* 0x8001AB38 */
    R[4] = lw_(R[2] + 28884);  /* 0x8001AB3C */
    { R[31] = 0x8001AB48u; R[5] = R[0] + R[0]; psx_next = 0x80021034u; return; }  /* 0x8001AB40 jal */
    R[4] = R[0] + 270;  /* 0x8001AB48 */
    R[3] = 0x8006u << 16;  /* 0x8001AB4C */
    R[2] = R[0] + 1;  /* 0x8001AB50 */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB54 */
    R[3] = 0x8006u << 16;  /* 0x8001AB58 */
    R[2] = R[4] + R[0];  /* 0x8001AB5C */
    { R[31] = 0x8001AB68u; sw_(R[3] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB60 jal */
L_8001AB68:;
    { R[31] = 0x8001AB70u; R[4] = R[0] + R[0]; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB68 jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB70 */
    { R[31] = 0x8001AB7Cu; sw_(R[2] + -12120, R[0]); psx_next = 0x8001CEC4u; return; }  /* 0x8001AB74 jal */
    { R[31] = 0x8001AB84u; R[16] = 0x8006u << 16; psx_next = 0x8001A764u; return; }  /* 0x8001AB7C jal */
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_bb(); goto L_8001AB0C; } }  /* 0x8001ABA4 */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_bb(); goto L_8001AB68; } }  /* 0x8001ABE0 */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001AAC0(void) {
    { R[31] = 0x8001AAC8u; psx_next = 0x8001C030u; return; }  /* 0x8001AAC0 jal */
    R[4] = R[29] + 16;  /* 0x8001AAC8 */
    R[5] = R[0] + R[0];  /* 0x8001AACC */
    R[6] = R[5] + R[0];  /* 0x8001AAD0 */
    R[7] = R[5] + R[0];  /* 0x8001AAD4 */
    R[2] = R[0] + 320;  /* 0x8001AAD8 */
    sh_(R[29] + 20, R[2]);  /* 0x8001AADC */
    R[2] = R[0] + 512;  /* 0x8001AAE0 */
    sh_(R[29] + 16, R[0]);  /* 0x8001AAE4 */
    sh_(R[29] + 18, R[0]);  /* 0x8001AAE8 */
    { R[31] = 0x8001AAF4u; sh_(R[29] + 22, R[2]); psx_next = 0x80032B08u; return; }  /* 0x8001AAEC jal */
    { R[31] = 0x8001AAFCu; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x8001AAF4 jal */
    R[3] = 0x8006u << 16;  /* 0x8001AAFC */
    R[2] = R[0] + 180;  /* 0x8001AB00 */
    { sw_(R[3] + -12280, R[2]); goto L_8001AB68; }  /* 0x8001AB04 j */
L_8001AB0C:;
    { R[31] = 0x8001AB14u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB0C jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB14 */
    R[2] = lw_(R[2] + -6472);  /* 0x8001AB18 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001AB68; } }  /* 0x8001AB20 */
    { R[31] = 0x8001AB30u; psx_next = 0x8001A764u; return; }  /* 0x8001AB28 jal */
    { R[31] = 0x8001AB38u; psx_next = 0x8001CEC4u; return; }  /* 0x8001AB30 jal */
    R[2] = 0x8001u << 16;  /* 0x8001AB38 */
    R[4] = lw_(R[2] + 28884);  /* 0x8001AB3C */
    { R[31] = 0x8001AB48u; R[5] = R[0] + R[0]; psx_next = 0x80021034u; return; }  /* 0x8001AB40 jal */
    R[4] = R[0] + 270;  /* 0x8001AB48 */
    R[3] = 0x8006u << 16;  /* 0x8001AB4C */
    R[2] = R[0] + 1;  /* 0x8001AB50 */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB54 */
    R[3] = 0x8006u << 16;  /* 0x8001AB58 */
    R[2] = R[4] + R[0];  /* 0x8001AB5C */
    { R[31] = 0x8001AB68u; sw_(R[3] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB60 jal */
L_8001AB68:;
    { R[31] = 0x8001AB70u; R[4] = R[0] + R[0]; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB68 jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB70 */
    { R[31] = 0x8001AB7Cu; sw_(R[2] + -12120, R[0]); psx_next = 0x8001CEC4u; return; }  /* 0x8001AB74 jal */
    { R[31] = 0x8001AB84u; R[16] = 0x8006u << 16; psx_next = 0x8001A764u; return; }  /* 0x8001AB7C jal */
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_bb(); goto L_8001AB0C; } }  /* 0x8001ABA4 */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_bb(); goto L_8001AB68; } }  /* 0x8001ABE0 */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001AAC8(void) {
    R[4] = R[29] + 16;  /* 0x8001AAC8 */
    R[5] = R[0] + R[0];  /* 0x8001AACC */
    R[6] = R[5] + R[0];  /* 0x8001AAD0 */
    R[7] = R[5] + R[0];  /* 0x8001AAD4 */
    R[2] = R[0] + 320;  /* 0x8001AAD8 */
    sh_(R[29] + 20, R[2]);  /* 0x8001AADC */
    R[2] = R[0] + 512;  /* 0x8001AAE0 */
    sh_(R[29] + 16, R[0]);  /* 0x8001AAE4 */
    sh_(R[29] + 18, R[0]);  /* 0x8001AAE8 */
    { R[31] = 0x8001AAF4u; sh_(R[29] + 22, R[2]); psx_next = 0x80032B08u; return; }  /* 0x8001AAEC jal */
    { R[31] = 0x8001AAFCu; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x8001AAF4 jal */
    R[3] = 0x8006u << 16;  /* 0x8001AAFC */
    R[2] = R[0] + 180;  /* 0x8001AB00 */
    { sw_(R[3] + -12280, R[2]); goto L_8001AB68; }  /* 0x8001AB04 j */
L_8001AB0C:;
    { R[31] = 0x8001AB14u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB0C jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB14 */
    R[2] = lw_(R[2] + -6472);  /* 0x8001AB18 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001AB68; } }  /* 0x8001AB20 */
    { R[31] = 0x8001AB30u; psx_next = 0x8001A764u; return; }  /* 0x8001AB28 jal */
    { R[31] = 0x8001AB38u; psx_next = 0x8001CEC4u; return; }  /* 0x8001AB30 jal */
    R[2] = 0x8001u << 16;  /* 0x8001AB38 */
    R[4] = lw_(R[2] + 28884);  /* 0x8001AB3C */
    { R[31] = 0x8001AB48u; R[5] = R[0] + R[0]; psx_next = 0x80021034u; return; }  /* 0x8001AB40 jal */
    R[4] = R[0] + 270;  /* 0x8001AB48 */
    R[3] = 0x8006u << 16;  /* 0x8001AB4C */
    R[2] = R[0] + 1;  /* 0x8001AB50 */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB54 */
    R[3] = 0x8006u << 16;  /* 0x8001AB58 */
    R[2] = R[4] + R[0];  /* 0x8001AB5C */
    { R[31] = 0x8001AB68u; sw_(R[3] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB60 jal */
L_8001AB68:;
    { R[31] = 0x8001AB70u; R[4] = R[0] + R[0]; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB68 jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB70 */
    { R[31] = 0x8001AB7Cu; sw_(R[2] + -12120, R[0]); psx_next = 0x8001CEC4u; return; }  /* 0x8001AB74 jal */
    { R[31] = 0x8001AB84u; R[16] = 0x8006u << 16; psx_next = 0x8001A764u; return; }  /* 0x8001AB7C jal */
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_bb(); goto L_8001AB0C; } }  /* 0x8001ABA4 */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_bb(); goto L_8001AB68; } }  /* 0x8001ABE0 */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001AAF4(void) {
    { R[31] = 0x8001AAFCu; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x8001AAF4 jal */
    R[3] = 0x8006u << 16;  /* 0x8001AAFC */
    R[2] = R[0] + 180;  /* 0x8001AB00 */
    { sw_(R[3] + -12280, R[2]); goto L_8001AB68; }  /* 0x8001AB04 j */
L_8001AB0C:;
    { R[31] = 0x8001AB14u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB0C jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB14 */
    R[2] = lw_(R[2] + -6472);  /* 0x8001AB18 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001AB68; } }  /* 0x8001AB20 */
    { R[31] = 0x8001AB30u; psx_next = 0x8001A764u; return; }  /* 0x8001AB28 jal */
    { R[31] = 0x8001AB38u; psx_next = 0x8001CEC4u; return; }  /* 0x8001AB30 jal */
    R[2] = 0x8001u << 16;  /* 0x8001AB38 */
    R[4] = lw_(R[2] + 28884);  /* 0x8001AB3C */
    { R[31] = 0x8001AB48u; R[5] = R[0] + R[0]; psx_next = 0x80021034u; return; }  /* 0x8001AB40 jal */
    R[4] = R[0] + 270;  /* 0x8001AB48 */
    R[3] = 0x8006u << 16;  /* 0x8001AB4C */
    R[2] = R[0] + 1;  /* 0x8001AB50 */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB54 */
    R[3] = 0x8006u << 16;  /* 0x8001AB58 */
    R[2] = R[4] + R[0];  /* 0x8001AB5C */
    { R[31] = 0x8001AB68u; sw_(R[3] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB60 jal */
L_8001AB68:;
    { R[31] = 0x8001AB70u; R[4] = R[0] + R[0]; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB68 jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB70 */
    { R[31] = 0x8001AB7Cu; sw_(R[2] + -12120, R[0]); psx_next = 0x8001CEC4u; return; }  /* 0x8001AB74 jal */
    { R[31] = 0x8001AB84u; R[16] = 0x8006u << 16; psx_next = 0x8001A764u; return; }  /* 0x8001AB7C jal */
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_bb(); goto L_8001AB0C; } }  /* 0x8001ABA4 */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_bb(); goto L_8001AB68; } }  /* 0x8001ABE0 */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001AAFC(void) {
    R[3] = 0x8006u << 16;  /* 0x8001AAFC */
    R[2] = R[0] + 180;  /* 0x8001AB00 */
    { sw_(R[3] + -12280, R[2]); goto L_8001AB68; }  /* 0x8001AB04 j */
L_8001AB0C:;
    { R[31] = 0x8001AB14u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB0C jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB14 */
    R[2] = lw_(R[2] + -6472);  /* 0x8001AB18 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001AB68; } }  /* 0x8001AB20 */
    { R[31] = 0x8001AB30u; psx_next = 0x8001A764u; return; }  /* 0x8001AB28 jal */
    { R[31] = 0x8001AB38u; psx_next = 0x8001CEC4u; return; }  /* 0x8001AB30 jal */
    R[2] = 0x8001u << 16;  /* 0x8001AB38 */
    R[4] = lw_(R[2] + 28884);  /* 0x8001AB3C */
    { R[31] = 0x8001AB48u; R[5] = R[0] + R[0]; psx_next = 0x80021034u; return; }  /* 0x8001AB40 jal */
    R[4] = R[0] + 270;  /* 0x8001AB48 */
    R[3] = 0x8006u << 16;  /* 0x8001AB4C */
    R[2] = R[0] + 1;  /* 0x8001AB50 */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB54 */
    R[3] = 0x8006u << 16;  /* 0x8001AB58 */
    R[2] = R[4] + R[0];  /* 0x8001AB5C */
    { R[31] = 0x8001AB68u; sw_(R[3] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB60 jal */
L_8001AB68:;
    { R[31] = 0x8001AB70u; R[4] = R[0] + R[0]; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB68 jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB70 */
    { R[31] = 0x8001AB7Cu; sw_(R[2] + -12120, R[0]); psx_next = 0x8001CEC4u; return; }  /* 0x8001AB74 jal */
    { R[31] = 0x8001AB84u; R[16] = 0x8006u << 16; psx_next = 0x8001A764u; return; }  /* 0x8001AB7C jal */
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_bb(); goto L_8001AB0C; } }  /* 0x8001ABA4 */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_bb(); goto L_8001AB68; } }  /* 0x8001ABE0 */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001AB0C(void) {
L_8001AB0C:;
    { R[31] = 0x8001AB14u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB0C jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB14 */
    R[2] = lw_(R[2] + -6472);  /* 0x8001AB18 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001AB68; } }  /* 0x8001AB20 */
    { R[31] = 0x8001AB30u; psx_next = 0x8001A764u; return; }  /* 0x8001AB28 jal */
    { R[31] = 0x8001AB38u; psx_next = 0x8001CEC4u; return; }  /* 0x8001AB30 jal */
    R[2] = 0x8001u << 16;  /* 0x8001AB38 */
    R[4] = lw_(R[2] + 28884);  /* 0x8001AB3C */
    { R[31] = 0x8001AB48u; R[5] = R[0] + R[0]; psx_next = 0x80021034u; return; }  /* 0x8001AB40 jal */
    R[4] = R[0] + 270;  /* 0x8001AB48 */
    R[3] = 0x8006u << 16;  /* 0x8001AB4C */
    R[2] = R[0] + 1;  /* 0x8001AB50 */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB54 */
    R[3] = 0x8006u << 16;  /* 0x8001AB58 */
    R[2] = R[4] + R[0];  /* 0x8001AB5C */
    { R[31] = 0x8001AB68u; sw_(R[3] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB60 jal */
L_8001AB68:;
    { R[31] = 0x8001AB70u; R[4] = R[0] + R[0]; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB68 jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB70 */
    { R[31] = 0x8001AB7Cu; sw_(R[2] + -12120, R[0]); psx_next = 0x8001CEC4u; return; }  /* 0x8001AB74 jal */
    { R[31] = 0x8001AB84u; R[16] = 0x8006u << 16; psx_next = 0x8001A764u; return; }  /* 0x8001AB7C jal */
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_bb(); goto L_8001AB0C; } }  /* 0x8001ABA4 */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_bb(); goto L_8001AB68; } }  /* 0x8001ABE0 */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001AB14(void) {
    R[2] = 0x8006u << 16;  /* 0x8001AB14 */
    R[2] = lw_(R[2] + -6472);  /* 0x8001AB18 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001AB68; } }  /* 0x8001AB20 */
    { R[31] = 0x8001AB30u; psx_next = 0x8001A764u; return; }  /* 0x8001AB28 jal */
    { R[31] = 0x8001AB38u; psx_next = 0x8001CEC4u; return; }  /* 0x8001AB30 jal */
    R[2] = 0x8001u << 16;  /* 0x8001AB38 */
    R[4] = lw_(R[2] + 28884);  /* 0x8001AB3C */
    { R[31] = 0x8001AB48u; R[5] = R[0] + R[0]; psx_next = 0x80021034u; return; }  /* 0x8001AB40 jal */
    R[4] = R[0] + 270;  /* 0x8001AB48 */
    R[3] = 0x8006u << 16;  /* 0x8001AB4C */
    R[2] = R[0] + 1;  /* 0x8001AB50 */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB54 */
    R[3] = 0x8006u << 16;  /* 0x8001AB58 */
    R[2] = R[4] + R[0];  /* 0x8001AB5C */
    { R[31] = 0x8001AB68u; sw_(R[3] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB60 jal */
L_8001AB68:;
    { R[31] = 0x8001AB70u; R[4] = R[0] + R[0]; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB68 jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB70 */
    { R[31] = 0x8001AB7Cu; sw_(R[2] + -12120, R[0]); psx_next = 0x8001CEC4u; return; }  /* 0x8001AB74 jal */
    { R[31] = 0x8001AB84u; R[16] = 0x8006u << 16; psx_next = 0x8001A764u; return; }  /* 0x8001AB7C jal */
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_next = 0x8001AB0Cu; return; } }  /* 0x8001ABA4 b extern */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_bb(); goto L_8001AB68; } }  /* 0x8001ABE0 */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001AB30(void) {
    { R[31] = 0x8001AB38u; psx_next = 0x8001CEC4u; return; }  /* 0x8001AB30 jal */
    R[2] = 0x8001u << 16;  /* 0x8001AB38 */
    R[4] = lw_(R[2] + 28884);  /* 0x8001AB3C */
    { R[31] = 0x8001AB48u; R[5] = R[0] + R[0]; psx_next = 0x80021034u; return; }  /* 0x8001AB40 jal */
    R[4] = R[0] + 270;  /* 0x8001AB48 */
    R[3] = 0x8006u << 16;  /* 0x8001AB4C */
    R[2] = R[0] + 1;  /* 0x8001AB50 */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB54 */
    R[3] = 0x8006u << 16;  /* 0x8001AB58 */
    R[2] = R[4] + R[0];  /* 0x8001AB5C */
    { R[31] = 0x8001AB68u; sw_(R[3] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB60 jal */
L_8001AB68:;
    { R[31] = 0x8001AB70u; R[4] = R[0] + R[0]; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB68 jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB70 */
    { R[31] = 0x8001AB7Cu; sw_(R[2] + -12120, R[0]); psx_next = 0x8001CEC4u; return; }  /* 0x8001AB74 jal */
    { R[31] = 0x8001AB84u; R[16] = 0x8006u << 16; psx_next = 0x8001A764u; return; }  /* 0x8001AB7C jal */
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_next = 0x8001AB0Cu; return; } }  /* 0x8001ABA4 b extern */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_bb(); goto L_8001AB68; } }  /* 0x8001ABE0 */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001AB38(void) {
    R[2] = 0x8001u << 16;  /* 0x8001AB38 */
    R[4] = lw_(R[2] + 28884);  /* 0x8001AB3C */
    { R[31] = 0x8001AB48u; R[5] = R[0] + R[0]; psx_next = 0x80021034u; return; }  /* 0x8001AB40 jal */
    R[4] = R[0] + 270;  /* 0x8001AB48 */
    R[3] = 0x8006u << 16;  /* 0x8001AB4C */
    R[2] = R[0] + 1;  /* 0x8001AB50 */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB54 */
    R[3] = 0x8006u << 16;  /* 0x8001AB58 */
    R[2] = R[4] + R[0];  /* 0x8001AB5C */
    { R[31] = 0x8001AB68u; sw_(R[3] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB60 jal */
L_8001AB68:;
    { R[31] = 0x8001AB70u; R[4] = R[0] + R[0]; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB68 jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB70 */
    { R[31] = 0x8001AB7Cu; sw_(R[2] + -12120, R[0]); psx_next = 0x8001CEC4u; return; }  /* 0x8001AB74 jal */
    { R[31] = 0x8001AB84u; R[16] = 0x8006u << 16; psx_next = 0x8001A764u; return; }  /* 0x8001AB7C jal */
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_next = 0x8001AB0Cu; return; } }  /* 0x8001ABA4 b extern */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_bb(); goto L_8001AB68; } }  /* 0x8001ABE0 */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001AB48(void) {
    R[4] = R[0] + 270;  /* 0x8001AB48 */
    R[3] = 0x8006u << 16;  /* 0x8001AB4C */
    R[2] = R[0] + 1;  /* 0x8001AB50 */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB54 */
    R[3] = 0x8006u << 16;  /* 0x8001AB58 */
    R[2] = R[4] + R[0];  /* 0x8001AB5C */
    { R[31] = 0x8001AB68u; sw_(R[3] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB60 jal */
L_8001AB68:;
    { R[31] = 0x8001AB70u; R[4] = R[0] + R[0]; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB68 jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB70 */
    { R[31] = 0x8001AB7Cu; sw_(R[2] + -12120, R[0]); psx_next = 0x8001CEC4u; return; }  /* 0x8001AB74 jal */
    { R[31] = 0x8001AB84u; R[16] = 0x8006u << 16; psx_next = 0x8001A764u; return; }  /* 0x8001AB7C jal */
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_next = 0x8001AB0Cu; return; } }  /* 0x8001ABA4 b extern */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_bb(); goto L_8001AB68; } }  /* 0x8001ABE0 */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001AB68(void) {
L_8001AB68:;
    { R[31] = 0x8001AB70u; R[4] = R[0] + R[0]; psx_next = 0x8002A0DCu; return; }  /* 0x8001AB68 jal */
    R[2] = 0x8006u << 16;  /* 0x8001AB70 */
    { R[31] = 0x8001AB7Cu; sw_(R[2] + -12120, R[0]); psx_next = 0x8001CEC4u; return; }  /* 0x8001AB74 jal */
    { R[31] = 0x8001AB84u; R[16] = 0x8006u << 16; psx_next = 0x8001A764u; return; }  /* 0x8001AB7C jal */
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_next = 0x8001AB0Cu; return; } }  /* 0x8001ABA4 b extern */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_bb(); goto L_8001AB68; } }  /* 0x8001ABE0 */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001AB70(void) {
    R[2] = 0x8006u << 16;  /* 0x8001AB70 */
    { R[31] = 0x8001AB7Cu; sw_(R[2] + -12120, R[0]); psx_next = 0x8001CEC4u; return; }  /* 0x8001AB74 jal */
    { R[31] = 0x8001AB84u; R[16] = 0x8006u << 16; psx_next = 0x8001A764u; return; }  /* 0x8001AB7C jal */
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_next = 0x8001AB0Cu; return; } }  /* 0x8001ABA4 b extern */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_next = 0x8001AB68u; return; } }  /* 0x8001ABE0 b extern */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001AB7C(void) {
    { R[31] = 0x8001AB84u; R[16] = 0x8006u << 16; psx_next = 0x8001A764u; return; }  /* 0x8001AB7C jal */
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_next = 0x8001AB0Cu; return; } }  /* 0x8001ABA4 b extern */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_next = 0x8001AB68u; return; } }  /* 0x8001ABE0 b extern */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001AB84(void) {
    R[4] = R[0] + 1;  /* 0x8001AB84 */
    R[3] = 0x8006u << 16;  /* 0x8001AB88 */
    R[2] = R[0] + 2;  /* 0x8001AB8C */
    sw_(R[3] + -12200, R[2]);  /* 0x8001AB90 */
    R[2] = R[4] + R[0];  /* 0x8001AB94 */
    { R[31] = 0x8001ABA0u; sw_(R[16] + -12132, R[2]); psx_next = 0x8001A198u; return; }  /* 0x8001AB98 jal */
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_next = 0x8001AB0Cu; return; } }  /* 0x8001ABA4 b extern */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_next = 0x8001AB68u; return; } }  /* 0x8001ABE0 b extern */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001ABA0(void) {
    R[3] = R[0] - 1;  /* 0x8001ABA0 */
    { uint32_t _c = (R[2] == R[3]); if (_c) { psx_next = 0x8001AB0Cu; return; } }  /* 0x8001ABA4 b extern */
    { R[31] = 0x8001ABB4u; R[4] = R[0] + 1; psx_next = 0x8002A0DCu; return; }  /* 0x8001ABAC jal */
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_next = 0x8001AB68u; return; } }  /* 0x8001ABE0 b extern */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001ABB4(void) {
    R[17] = R[16] + R[0];  /* 0x8001ABB4 */
    R[16] = R[0] - 1;  /* 0x8001ABB8 */
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_next = 0x8001AB68u; return; } }  /* 0x8001ABE0 b extern */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001ABBC(void) {
L_8001ABBC:;
    { R[31] = 0x8001ABC4u; psx_next = 0x8001EE78u; return; }  /* 0x8001ABBC jal */
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_next = 0x8001AB68u; return; } }  /* 0x8001ABE0 b extern */
    { psx_bb(); goto L_8001ABBC; }  /* 0x8001ABE8 j */
}

void f_8001ABC4(void) {
    { R[31] = 0x8001ABCCu; psx_next = 0x80021C74u; return; }  /* 0x8001ABC4 jal */
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_next = 0x8001AB68u; return; } }  /* 0x8001ABE0 b extern */
    { psx_next = 0x8001ABBCu; return; }  /* 0x8001ABE8 j extern */
}

void f_8001ABCC(void) {
    { R[31] = 0x8001ABD4u; psx_next = 0x8001A764u; return; }  /* 0x8001ABCC jal */
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_next = 0x8001AB68u; return; } }  /* 0x8001ABE0 b extern */
    { psx_next = 0x8001ABBCu; return; }  /* 0x8001ABE8 j extern */
}

void f_8001ABD4(void) {
    R[4] = lw_(R[17] + -12132);  /* 0x8001ABD4 */
    { R[31] = 0x8001ABE0u; psx_next = 0x8001A198u; return; }  /* 0x8001ABD8 jal */
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_next = 0x8001AB68u; return; } }  /* 0x8001ABE0 b extern */
    { psx_next = 0x8001ABBCu; return; }  /* 0x8001ABE8 j extern */
}

void f_8001ABE0(void) {
    { uint32_t _c = (R[2] == R[16]); if (_c) { psx_next = 0x8001AB68u; return; } }  /* 0x8001ABE0 b extern */
    { psx_next = 0x8001ABBCu; return; }  /* 0x8001ABE8 j extern */
}

void f_8001ABF0(void) {
    R[3] = lb_(R[4]);  /* 0x8001ABF0 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[3] - 97; if (_c) { goto L_8001AC24; } }  /* 0x8001ABF8 */
L_8001AC00:;
    R[2] = (R[2] < (uint32_t)26u);  /* 0x8001AC00 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 224; if (_c) { goto L_8001AC10; } }  /* 0x8001AC04 */
    sb_(R[4], R[2]);  /* 0x8001AC0C */
L_8001AC10:;
    R[4] = R[4] + 1;  /* 0x8001AC10 */
    R[3] = lb_(R[4]);  /* 0x8001AC14 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[3] - 97; if (_c) { psx_bb(); goto L_8001AC00; } }  /* 0x8001AC1C */
L_8001AC24:;
    { psx_next = R[31]; return; }  /* 0x8001AC24 jr ra */
}

void f_8001AC2C(void) {
    R[29] = R[29] - 24;  /* 0x8001AC2C */
    sw_(R[29] + 16, R[16]);  /* 0x8001AC30 */
    R[16] = R[4] + R[0];  /* 0x8001AC34 */
    R[2] = 0x8001u << 16;  /* 0x8001AC38 */
    sw_(R[29] + 20, R[31]);  /* 0x8001AC3C */
    R[8] = R[2] + 28892;  /* 0x8001AC40 */
    R[3] = (uint32_t)(int8_t)lb_(R[8]);  /* 0x8001AC44 */
    R[6] = (uint32_t)(int8_t)lb_(R[8] + 1);  /* 0x8001AC48 */
    sb_(R[16], R[3]);  /* 0x8001AC4C */
    sb_(R[16] + 1, R[6]);  /* 0x8001AC50 */
    { R[31] = 0x8001AC5Cu; psx_next = 0x80030EC8u; return; }  /* 0x8001AC54 jal */
    R[4] = R[16] + R[0];  /* 0x8001AC5C */
    R[5] = 0x8001u << 16;  /* 0x8001AC60 */
    { R[31] = 0x8001AC6Cu; R[5] = R[5] + 28896; psx_next = 0x80030EC8u; return; }  /* 0x8001AC64 jal */
    { R[31] = 0x8001AC74u; R[4] = R[16] + R[0]; psx_next = 0x8001ABF0u; return; }  /* 0x8001AC6C jal */
    R[2] = R[16] + R[0];  /* 0x8001AC74 */
    R[31] = lw_(R[29] + 20);  /* 0x8001AC78 */
    R[16] = lw_(R[29] + 16);  /* 0x8001AC7C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001AC80 jr ra */
}

void f_8001AC5C(void) {
    R[4] = R[16] + R[0];  /* 0x8001AC5C */
    R[5] = 0x8001u << 16;  /* 0x8001AC60 */
    { R[31] = 0x8001AC6Cu; R[5] = R[5] + 28896; psx_next = 0x80030EC8u; return; }  /* 0x8001AC64 jal */
    { R[31] = 0x8001AC74u; R[4] = R[16] + R[0]; psx_next = 0x8001ABF0u; return; }  /* 0x8001AC6C jal */
    R[2] = R[16] + R[0];  /* 0x8001AC74 */
    R[31] = lw_(R[29] + 20);  /* 0x8001AC78 */
    R[16] = lw_(R[29] + 16);  /* 0x8001AC7C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001AC80 jr ra */
}

void f_8001AC6C(void) {
    { R[31] = 0x8001AC74u; R[4] = R[16] + R[0]; psx_next = 0x8001ABF0u; return; }  /* 0x8001AC6C jal */
    R[2] = R[16] + R[0];  /* 0x8001AC74 */
    R[31] = lw_(R[29] + 20);  /* 0x8001AC78 */
    R[16] = lw_(R[29] + 16);  /* 0x8001AC7C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001AC80 jr ra */
}

void f_8001AC74(void) {
    R[2] = R[16] + R[0];  /* 0x8001AC74 */
    R[31] = lw_(R[29] + 20);  /* 0x8001AC78 */
    R[16] = lw_(R[29] + 16);  /* 0x8001AC7C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001AC80 jr ra */
}

void f_8001AC88(void) {
    R[29] = R[29] - 168;  /* 0x8001AC88 */
    sw_(R[29] + 160, R[31]);  /* 0x8001AC8C */
    sw_(R[29] + 156, R[19]);  /* 0x8001AC90 */
    sw_(R[29] + 152, R[18]);  /* 0x8001AC94 */
    sw_(R[29] + 148, R[17]);  /* 0x8001AC98 */
    { R[31] = 0x8001ACA4u; sw_(R[29] + 144, R[16]); psx_next = 0x8003E218u; return; }  /* 0x8001AC9C jal */
    R[16] = R[0] + R[0];  /* 0x8001ACA4 */
    R[2] = 0x8006u << 16;  /* 0x8001ACA8 */
    R[2] = R[2] - 10048;  /* 0x8001ACAC */
    R[3] = R[0] + 16;  /* 0x8001ACB0 */
L_8001ACB4:;
    sb_(R[2], R[0]);  /* 0x8001ACB4 */
    R[16] = R[16] + 1;  /* 0x8001ACB8 */
    { uint32_t _c = (R[16] != R[3]); R[2] = R[2] + 1; if (_c) { psx_bb(); goto L_8001ACB4; } }  /* 0x8001ACBC */
    R[16] = R[0] + R[0];  /* 0x8001ACC4 */
    R[2] = 0x8006u << 16;  /* 0x8001ACC8 */
    R[2] = R[2] - 10024;  /* 0x8001ACCC */
    R[3] = R[0] + 204;  /* 0x8001ACD0 */
L_8001ACD4:;
    sb_(R[2], R[0]);  /* 0x8001ACD4 */
    R[16] = R[16] + 1;  /* 0x8001ACD8 */
    { uint32_t _c = (R[16] != R[3]); R[2] = R[2] + 1; if (_c) { psx_bb(); goto L_8001ACD4; } }  /* 0x8001ACDC */
    R[16] = R[0] + R[0];  /* 0x8001ACE4 */
    R[2] = 0x8006u << 16;  /* 0x8001ACE8 */
    R[19] = R[2] - 9816;  /* 0x8001ACEC */
    R[17] = R[16] + R[0];  /* 0x8001ACF0 */
    R[2] = 0x8005u << 16;  /* 0x8001ACF4 */
    R[18] = R[2] - 1416;  /* 0x8001ACF8 */
L_8001ACFC:;
    R[5] = lw_(R[18]);  /* 0x8001ACFC */
    { uint32_t _c = (R[5] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8001AD38; } }  /* 0x8001AD04 */
    { R[31] = 0x8001AD14u; R[4] = R[29] + 16; psx_next = 0x8001AC2Cu; return; }  /* 0x8001AD0C jal */
    R[4] = R[17] + R[19];  /* 0x8001AD14 */
L_8001AD18:;
    { R[31] = 0x8001AD20u; R[5] = R[29] + 16; psx_next = 0x80042228u; return; }  /* 0x8001AD18 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[19]; if (_c) { psx_bb(); goto L_8001AD18; } }  /* 0x8001AD20 */
    R[17] = R[17] + 24;  /* 0x8001AD28 */
    R[18] = R[18] + 4;  /* 0x8001AD2C */
    { R[16] = R[16] + 1; psx_bb(); goto L_8001ACFC; }  /* 0x8001AD30 j */
L_8001AD38:;
    R[31] = lw_(R[29] + 160);  /* 0x8001AD38 */
    R[19] = lw_(R[29] + 156);  /* 0x8001AD3C */
    R[18] = lw_(R[29] + 152);  /* 0x8001AD40 */
    R[17] = lw_(R[29] + 148);  /* 0x8001AD44 */
    sw_(R[2] + -9552, R[16]);  /* 0x8001AD48 */
    R[16] = lw_(R[29] + 144);  /* 0x8001AD4C */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001AD50 jr ra */
}

void f_8001ACA4(void) {
    R[16] = R[0] + R[0];  /* 0x8001ACA4 */
    R[2] = 0x8006u << 16;  /* 0x8001ACA8 */
    R[2] = R[2] - 10048;  /* 0x8001ACAC */
    R[3] = R[0] + 16;  /* 0x8001ACB0 */
L_8001ACB4:;
    sb_(R[2], R[0]);  /* 0x8001ACB4 */
    R[16] = R[16] + 1;  /* 0x8001ACB8 */
    { uint32_t _c = (R[16] != R[3]); R[2] = R[2] + 1; if (_c) { psx_bb(); goto L_8001ACB4; } }  /* 0x8001ACBC */
    R[16] = R[0] + R[0];  /* 0x8001ACC4 */
    R[2] = 0x8006u << 16;  /* 0x8001ACC8 */
    R[2] = R[2] - 10024;  /* 0x8001ACCC */
    R[3] = R[0] + 204;  /* 0x8001ACD0 */
L_8001ACD4:;
    sb_(R[2], R[0]);  /* 0x8001ACD4 */
    R[16] = R[16] + 1;  /* 0x8001ACD8 */
    { uint32_t _c = (R[16] != R[3]); R[2] = R[2] + 1; if (_c) { psx_bb(); goto L_8001ACD4; } }  /* 0x8001ACDC */
    R[16] = R[0] + R[0];  /* 0x8001ACE4 */
    R[2] = 0x8006u << 16;  /* 0x8001ACE8 */
    R[19] = R[2] - 9816;  /* 0x8001ACEC */
    R[17] = R[16] + R[0];  /* 0x8001ACF0 */
    R[2] = 0x8005u << 16;  /* 0x8001ACF4 */
    R[18] = R[2] - 1416;  /* 0x8001ACF8 */
L_8001ACFC:;
    R[5] = lw_(R[18]);  /* 0x8001ACFC */
    { uint32_t _c = (R[5] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8001AD38; } }  /* 0x8001AD04 */
    { R[31] = 0x8001AD14u; R[4] = R[29] + 16; psx_next = 0x8001AC2Cu; return; }  /* 0x8001AD0C jal */
    R[4] = R[17] + R[19];  /* 0x8001AD14 */
L_8001AD18:;
    { R[31] = 0x8001AD20u; R[5] = R[29] + 16; psx_next = 0x80042228u; return; }  /* 0x8001AD18 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[19]; if (_c) { psx_bb(); goto L_8001AD18; } }  /* 0x8001AD20 */
    R[17] = R[17] + 24;  /* 0x8001AD28 */
    R[18] = R[18] + 4;  /* 0x8001AD2C */
    { R[16] = R[16] + 1; psx_bb(); goto L_8001ACFC; }  /* 0x8001AD30 j */
L_8001AD38:;
    R[31] = lw_(R[29] + 160);  /* 0x8001AD38 */
    R[19] = lw_(R[29] + 156);  /* 0x8001AD3C */
    R[18] = lw_(R[29] + 152);  /* 0x8001AD40 */
    R[17] = lw_(R[29] + 148);  /* 0x8001AD44 */
    sw_(R[2] + -9552, R[16]);  /* 0x8001AD48 */
    R[16] = lw_(R[29] + 144);  /* 0x8001AD4C */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001AD50 jr ra */
}

void f_8001ACFC(void) {
L_8001ACFC:;
    R[5] = lw_(R[18]);  /* 0x8001ACFC */
    { uint32_t _c = (R[5] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8001AD38; } }  /* 0x8001AD04 */
    { R[31] = 0x8001AD14u; R[4] = R[29] + 16; psx_next = 0x8001AC2Cu; return; }  /* 0x8001AD0C jal */
    R[4] = R[17] + R[19];  /* 0x8001AD14 */
L_8001AD18:;
    { R[31] = 0x8001AD20u; R[5] = R[29] + 16; psx_next = 0x80042228u; return; }  /* 0x8001AD18 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[19]; if (_c) { psx_bb(); goto L_8001AD18; } }  /* 0x8001AD20 */
    R[17] = R[17] + 24;  /* 0x8001AD28 */
    R[18] = R[18] + 4;  /* 0x8001AD2C */
    { R[16] = R[16] + 1; psx_bb(); goto L_8001ACFC; }  /* 0x8001AD30 j */
L_8001AD38:;
    R[31] = lw_(R[29] + 160);  /* 0x8001AD38 */
    R[19] = lw_(R[29] + 156);  /* 0x8001AD3C */
    R[18] = lw_(R[29] + 152);  /* 0x8001AD40 */
    R[17] = lw_(R[29] + 148);  /* 0x8001AD44 */
    sw_(R[2] + -9552, R[16]);  /* 0x8001AD48 */
    R[16] = lw_(R[29] + 144);  /* 0x8001AD4C */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001AD50 jr ra */
}

void f_8001AD14(void) {
    R[4] = R[17] + R[19];  /* 0x8001AD14 */
L_8001AD18:;
    { R[31] = 0x8001AD20u; R[5] = R[29] + 16; psx_next = 0x80042228u; return; }  /* 0x8001AD18 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[19]; if (_c) { psx_bb(); goto L_8001AD18; } }  /* 0x8001AD20 */
    R[17] = R[17] + 24;  /* 0x8001AD28 */
    R[18] = R[18] + 4;  /* 0x8001AD2C */
    { R[16] = R[16] + 1; psx_next = 0x8001ACFCu; return; }  /* 0x8001AD30 j extern */
    R[31] = lw_(R[29] + 160);  /* 0x8001AD38 */
    R[19] = lw_(R[29] + 156);  /* 0x8001AD3C */
    R[18] = lw_(R[29] + 152);  /* 0x8001AD40 */
    R[17] = lw_(R[29] + 148);  /* 0x8001AD44 */
    sw_(R[2] + -9552, R[16]);  /* 0x8001AD48 */
    R[16] = lw_(R[29] + 144);  /* 0x8001AD4C */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001AD50 jr ra */
}

void f_8001AD18(void) {
L_8001AD18:;
    { R[31] = 0x8001AD20u; R[5] = R[29] + 16; psx_next = 0x80042228u; return; }  /* 0x8001AD18 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[19]; if (_c) { psx_bb(); goto L_8001AD18; } }  /* 0x8001AD20 */
    R[17] = R[17] + 24;  /* 0x8001AD28 */
    R[18] = R[18] + 4;  /* 0x8001AD2C */
    { R[16] = R[16] + 1; psx_next = 0x8001ACFCu; return; }  /* 0x8001AD30 j extern */
    R[31] = lw_(R[29] + 160);  /* 0x8001AD38 */
    R[19] = lw_(R[29] + 156);  /* 0x8001AD3C */
    R[18] = lw_(R[29] + 152);  /* 0x8001AD40 */
    R[17] = lw_(R[29] + 148);  /* 0x8001AD44 */
    sw_(R[2] + -9552, R[16]);  /* 0x8001AD48 */
    R[16] = lw_(R[29] + 144);  /* 0x8001AD4C */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001AD50 jr ra */
}

void f_8001AD20(void) {
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[19]; if (_c) { psx_next = 0x8001AD18u; return; } }  /* 0x8001AD20 b extern */
    R[17] = R[17] + 24;  /* 0x8001AD28 */
    R[18] = R[18] + 4;  /* 0x8001AD2C */
    { R[16] = R[16] + 1; psx_next = 0x8001ACFCu; return; }  /* 0x8001AD30 j extern */
    R[31] = lw_(R[29] + 160);  /* 0x8001AD38 */
    R[19] = lw_(R[29] + 156);  /* 0x8001AD3C */
    R[18] = lw_(R[29] + 152);  /* 0x8001AD40 */
    R[17] = lw_(R[29] + 148);  /* 0x8001AD44 */
    sw_(R[2] + -9552, R[16]);  /* 0x8001AD48 */
    R[16] = lw_(R[29] + 144);  /* 0x8001AD4C */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001AD50 jr ra */
}

void f_8001AD58(void) {
    { psx_next = R[31]; return; }  /* 0x8001AD58 jr ra */
}

void f_8001AD60(void) {
    { psx_next = R[31]; return; }  /* 0x8001AD60 jr ra */
}

void f_8001AD68(void) {
    R[29] = R[29] - 168;  /* 0x8001AD68 */
    sw_(R[29] + 152, R[18]);  /* 0x8001AD6C */
    R[18] = R[4] + R[0];  /* 0x8001AD70 */
    sw_(R[29] + 156, R[19]);  /* 0x8001AD74 */
    R[19] = R[5] + R[0];  /* 0x8001AD78 */
    R[2] = 0x8006u << 16;  /* 0x8001AD7C */
    sw_(R[29] + 148, R[17]);  /* 0x8001AD80 */
    R[17] = R[2] - 9816;  /* 0x8001AD84 */
    R[2] = 0x8005u << 16;  /* 0x8001AD88 */
    sw_(R[29] + 144, R[16]);  /* 0x8001AD8C */
    R[16] = R[2] - 1416;  /* 0x8001AD90 */
    sw_(R[29] + 160, R[31]);  /* 0x8001AD94 */
L_8001AD98:;
    R[5] = lw_(R[16]);  /* 0x8001AD98 */
    { uint32_t _c = (R[5] == R[0]); R[4] = R[29] + 16; if (_c) { goto L_8001ADF8; } }  /* 0x8001ADA0 */
    { R[31] = 0x8001ADB0u; R[4] = R[19] + R[0]; psx_next = 0x80030F78u; return; }  /* 0x8001ADA8 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8001ADEC; } }  /* 0x8001ADB0 */
    R[3] = lw_(R[17]);  /* 0x8001ADB8 */
    R[6] = lw_(R[17] + 4);  /* 0x8001ADBC */
    R[7] = lw_(R[17] + 8);  /* 0x8001ADC0 */
    R[8] = lw_(R[17] + 12);  /* 0x8001ADC4 */
    sw_(R[18], R[3]);  /* 0x8001ADC8 */
    sw_(R[18] + 4, R[6]);  /* 0x8001ADCC */
    sw_(R[18] + 8, R[7]);  /* 0x8001ADD0 */
    sw_(R[18] + 12, R[8]);  /* 0x8001ADD4 */
    R[3] = lw_(R[17] + 16);  /* 0x8001ADD8 */
    R[6] = lw_(R[17] + 20);  /* 0x8001ADDC */
    sw_(R[18] + 16, R[3]);  /* 0x8001ADE0 */
    { sw_(R[18] + 20, R[6]); goto L_8001AE14; }  /* 0x8001ADE4 j */
L_8001ADEC:;
    R[17] = R[17] + 24;  /* 0x8001ADEC */
    { R[16] = R[16] + 4; psx_bb(); goto L_8001AD98; }  /* 0x8001ADF0 j */
L_8001ADF8:;
    { R[31] = 0x8001AE00u; R[5] = R[19] + R[0]; psx_next = 0x8001AC2Cu; return; }  /* 0x8001ADF8 jal */
    R[4] = R[18] + R[0];  /* 0x8001AE00 */
L_8001AE04:;
    { R[31] = 0x8001AE0Cu; R[5] = R[29] + 16; psx_next = 0x80042228u; return; }  /* 0x8001AE04 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { psx_bb(); goto L_8001AE04; } }  /* 0x8001AE0C */
L_8001AE14:;
    R[2] = R[18] + R[0];  /* 0x8001AE14 */
    R[31] = lw_(R[29] + 160);  /* 0x8001AE18 */
    R[19] = lw_(R[29] + 156);  /* 0x8001AE1C */
    R[18] = lw_(R[29] + 152);  /* 0x8001AE20 */
    R[17] = lw_(R[29] + 148);  /* 0x8001AE24 */
    R[16] = lw_(R[29] + 144);  /* 0x8001AE28 */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001AE2C jr ra */
}

void f_8001AD98(void) {
L_8001AD98:;
    R[5] = lw_(R[16]);  /* 0x8001AD98 */
    { uint32_t _c = (R[5] == R[0]); R[4] = R[29] + 16; if (_c) { goto L_8001ADF8; } }  /* 0x8001ADA0 */
    { R[31] = 0x8001ADB0u; R[4] = R[19] + R[0]; psx_next = 0x80030F78u; return; }  /* 0x8001ADA8 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8001ADEC; } }  /* 0x8001ADB0 */
    R[3] = lw_(R[17]);  /* 0x8001ADB8 */
    R[6] = lw_(R[17] + 4);  /* 0x8001ADBC */
    R[7] = lw_(R[17] + 8);  /* 0x8001ADC0 */
    R[8] = lw_(R[17] + 12);  /* 0x8001ADC4 */
    sw_(R[18], R[3]);  /* 0x8001ADC8 */
    sw_(R[18] + 4, R[6]);  /* 0x8001ADCC */
    sw_(R[18] + 8, R[7]);  /* 0x8001ADD0 */
    sw_(R[18] + 12, R[8]);  /* 0x8001ADD4 */
    R[3] = lw_(R[17] + 16);  /* 0x8001ADD8 */
    R[6] = lw_(R[17] + 20);  /* 0x8001ADDC */
    sw_(R[18] + 16, R[3]);  /* 0x8001ADE0 */
    { sw_(R[18] + 20, R[6]); goto L_8001AE14; }  /* 0x8001ADE4 j */
L_8001ADEC:;
    R[17] = R[17] + 24;  /* 0x8001ADEC */
    { R[16] = R[16] + 4; psx_bb(); goto L_8001AD98; }  /* 0x8001ADF0 j */
L_8001ADF8:;
    { R[31] = 0x8001AE00u; R[5] = R[19] + R[0]; psx_next = 0x8001AC2Cu; return; }  /* 0x8001ADF8 jal */
    R[4] = R[18] + R[0];  /* 0x8001AE00 */
L_8001AE04:;
    { R[31] = 0x8001AE0Cu; R[5] = R[29] + 16; psx_next = 0x80042228u; return; }  /* 0x8001AE04 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { psx_bb(); goto L_8001AE04; } }  /* 0x8001AE0C */
L_8001AE14:;
    R[2] = R[18] + R[0];  /* 0x8001AE14 */
    R[31] = lw_(R[29] + 160);  /* 0x8001AE18 */
    R[19] = lw_(R[29] + 156);  /* 0x8001AE1C */
    R[18] = lw_(R[29] + 152);  /* 0x8001AE20 */
    R[17] = lw_(R[29] + 148);  /* 0x8001AE24 */
    R[16] = lw_(R[29] + 144);  /* 0x8001AE28 */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001AE2C jr ra */
}

void f_8001ADB0(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8001ADEC; } }  /* 0x8001ADB0 */
    R[3] = lw_(R[17]);  /* 0x8001ADB8 */
    R[6] = lw_(R[17] + 4);  /* 0x8001ADBC */
    R[7] = lw_(R[17] + 8);  /* 0x8001ADC0 */
    R[8] = lw_(R[17] + 12);  /* 0x8001ADC4 */
    sw_(R[18], R[3]);  /* 0x8001ADC8 */
    sw_(R[18] + 4, R[6]);  /* 0x8001ADCC */
    sw_(R[18] + 8, R[7]);  /* 0x8001ADD0 */
    sw_(R[18] + 12, R[8]);  /* 0x8001ADD4 */
    R[3] = lw_(R[17] + 16);  /* 0x8001ADD8 */
    R[6] = lw_(R[17] + 20);  /* 0x8001ADDC */
    sw_(R[18] + 16, R[3]);  /* 0x8001ADE0 */
    { sw_(R[18] + 20, R[6]); goto L_8001AE14; }  /* 0x8001ADE4 j */
L_8001ADEC:;
    R[17] = R[17] + 24;  /* 0x8001ADEC */
    { R[16] = R[16] + 4; psx_next = 0x8001AD98u; return; }  /* 0x8001ADF0 j extern */
    { R[31] = 0x8001AE00u; R[5] = R[19] + R[0]; psx_next = 0x8001AC2Cu; return; }  /* 0x8001ADF8 jal */
    R[4] = R[18] + R[0];  /* 0x8001AE00 */
L_8001AE04:;
    { R[31] = 0x8001AE0Cu; R[5] = R[29] + 16; psx_next = 0x80042228u; return; }  /* 0x8001AE04 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { psx_bb(); goto L_8001AE04; } }  /* 0x8001AE0C */
L_8001AE14:;
    R[2] = R[18] + R[0];  /* 0x8001AE14 */
    R[31] = lw_(R[29] + 160);  /* 0x8001AE18 */
    R[19] = lw_(R[29] + 156);  /* 0x8001AE1C */
    R[18] = lw_(R[29] + 152);  /* 0x8001AE20 */
    R[17] = lw_(R[29] + 148);  /* 0x8001AE24 */
    R[16] = lw_(R[29] + 144);  /* 0x8001AE28 */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001AE2C jr ra */
}

void f_8001AE00(void) {
    R[4] = R[18] + R[0];  /* 0x8001AE00 */
L_8001AE04:;
    { R[31] = 0x8001AE0Cu; R[5] = R[29] + 16; psx_next = 0x80042228u; return; }  /* 0x8001AE04 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { psx_bb(); goto L_8001AE04; } }  /* 0x8001AE0C */
    R[2] = R[18] + R[0];  /* 0x8001AE14 */
    R[31] = lw_(R[29] + 160);  /* 0x8001AE18 */
    R[19] = lw_(R[29] + 156);  /* 0x8001AE1C */
    R[18] = lw_(R[29] + 152);  /* 0x8001AE20 */
    R[17] = lw_(R[29] + 148);  /* 0x8001AE24 */
    R[16] = lw_(R[29] + 144);  /* 0x8001AE28 */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001AE2C jr ra */
}

void f_8001AE04(void) {
L_8001AE04:;
    { R[31] = 0x8001AE0Cu; R[5] = R[29] + 16; psx_next = 0x80042228u; return; }  /* 0x8001AE04 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { psx_bb(); goto L_8001AE04; } }  /* 0x8001AE0C */
    R[2] = R[18] + R[0];  /* 0x8001AE14 */
    R[31] = lw_(R[29] + 160);  /* 0x8001AE18 */
    R[19] = lw_(R[29] + 156);  /* 0x8001AE1C */
    R[18] = lw_(R[29] + 152);  /* 0x8001AE20 */
    R[17] = lw_(R[29] + 148);  /* 0x8001AE24 */
    R[16] = lw_(R[29] + 144);  /* 0x8001AE28 */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001AE2C jr ra */
}

void f_8001AE0C(void) {
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { psx_next = 0x8001AE04u; return; } }  /* 0x8001AE0C b extern */
    R[2] = R[18] + R[0];  /* 0x8001AE14 */
    R[31] = lw_(R[29] + 160);  /* 0x8001AE18 */
    R[19] = lw_(R[29] + 156);  /* 0x8001AE1C */
    R[18] = lw_(R[29] + 152);  /* 0x8001AE20 */
    R[17] = lw_(R[29] + 148);  /* 0x8001AE24 */
    R[16] = lw_(R[29] + 144);  /* 0x8001AE28 */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001AE2C jr ra */
}

void f_8001AE34(void) {
    R[29] = R[29] - 32;  /* 0x8001AE34 */
    sw_(R[29] + 24, R[18]);  /* 0x8001AE38 */
    R[18] = R[4] + R[0];  /* 0x8001AE3C */
    sw_(R[29] + 16, R[16]);  /* 0x8001AE40 */
    R[16] = R[0] + R[0];  /* 0x8001AE44 */
    R[2] = 0x8005u << 16;  /* 0x8001AE48 */
    sw_(R[29] + 20, R[17]);  /* 0x8001AE4C */
    R[17] = R[2] - 1416;  /* 0x8001AE50 */
    sw_(R[29] + 28, R[31]);  /* 0x8001AE54 */
L_8001AE58:;
    R[5] = lw_(R[17]);  /* 0x8001AE58 */
    { uint32_t _c = (R[5] == R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8001AEB0; } }  /* 0x8001AE60 */
    { R[31] = 0x8001AE70u; R[4] = R[18] + R[0]; psx_next = 0x80030F78u; return; }  /* 0x8001AE68 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8001AEA0; } }  /* 0x8001AE70 */
    { uint32_t _c = (R[16] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8001AEAC; } }  /* 0x8001AE78 */
    { uint32_t _c = (R[16] == R[2]); R[2] = R[0] + 3; if (_c) { goto L_8001AEAC; } }  /* 0x8001AE80 */
    { uint32_t _c = (R[16] == R[2]); R[2] = R[0] + 4; if (_c) { goto L_8001AEAC; } }  /* 0x8001AE88 */
    { uint32_t _c = (R[16] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_8001AEAC; } }  /* 0x8001AE90 */
    { goto L_8001AEB0; }  /* 0x8001AE98 j */
L_8001AEA0:;
    R[17] = R[17] + 4;  /* 0x8001AEA0 */
    { R[16] = R[16] + 1; psx_bb(); goto L_8001AE58; }  /* 0x8001AEA4 j */
L_8001AEAC:;
    R[2] = R[0] + R[0];  /* 0x8001AEAC */
L_8001AEB0:;
    R[31] = lw_(R[29] + 28);  /* 0x8001AEB0 */
    R[18] = lw_(R[29] + 24);  /* 0x8001AEB4 */
    R[17] = lw_(R[29] + 20);  /* 0x8001AEB8 */
    R[16] = lw_(R[29] + 16);  /* 0x8001AEBC */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8001AEC0 jr ra */
}

void f_8001AE58(void) {
L_8001AE58:;
    R[5] = lw_(R[17]);  /* 0x8001AE58 */
    { uint32_t _c = (R[5] == R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8001AEB0; } }  /* 0x8001AE60 */
    { R[31] = 0x8001AE70u; R[4] = R[18] + R[0]; psx_next = 0x80030F78u; return; }  /* 0x8001AE68 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8001AEA0; } }  /* 0x8001AE70 */
    { uint32_t _c = (R[16] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8001AEAC; } }  /* 0x8001AE78 */
    { uint32_t _c = (R[16] == R[2]); R[2] = R[0] + 3; if (_c) { goto L_8001AEAC; } }  /* 0x8001AE80 */
    { uint32_t _c = (R[16] == R[2]); R[2] = R[0] + 4; if (_c) { goto L_8001AEAC; } }  /* 0x8001AE88 */
    { uint32_t _c = (R[16] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_8001AEAC; } }  /* 0x8001AE90 */
    { goto L_8001AEB0; }  /* 0x8001AE98 j */
L_8001AEA0:;
    R[17] = R[17] + 4;  /* 0x8001AEA0 */
    { R[16] = R[16] + 1; psx_bb(); goto L_8001AE58; }  /* 0x8001AEA4 j */
L_8001AEAC:;
    R[2] = R[0] + R[0];  /* 0x8001AEAC */
L_8001AEB0:;
    R[31] = lw_(R[29] + 28);  /* 0x8001AEB0 */
    R[18] = lw_(R[29] + 24);  /* 0x8001AEB4 */
    R[17] = lw_(R[29] + 20);  /* 0x8001AEB8 */
    R[16] = lw_(R[29] + 16);  /* 0x8001AEBC */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8001AEC0 jr ra */
}

void f_8001AE70(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8001AEA0; } }  /* 0x8001AE70 */
    { uint32_t _c = (R[16] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8001AEAC; } }  /* 0x8001AE78 */
    { uint32_t _c = (R[16] == R[2]); R[2] = R[0] + 3; if (_c) { goto L_8001AEAC; } }  /* 0x8001AE80 */
    { uint32_t _c = (R[16] == R[2]); R[2] = R[0] + 4; if (_c) { goto L_8001AEAC; } }  /* 0x8001AE88 */
    { uint32_t _c = (R[16] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_8001AEAC; } }  /* 0x8001AE90 */
    { goto L_8001AEB0; }  /* 0x8001AE98 j */
L_8001AEA0:;
    R[17] = R[17] + 4;  /* 0x8001AEA0 */
    { R[16] = R[16] + 1; psx_next = 0x8001AE58u; return; }  /* 0x8001AEA4 j extern */
L_8001AEAC:;
    R[2] = R[0] + R[0];  /* 0x8001AEAC */
L_8001AEB0:;
    R[31] = lw_(R[29] + 28);  /* 0x8001AEB0 */
    R[18] = lw_(R[29] + 24);  /* 0x8001AEB4 */
    R[17] = lw_(R[29] + 20);  /* 0x8001AEB8 */
    R[16] = lw_(R[29] + 16);  /* 0x8001AEBC */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8001AEC0 jr ra */
}

void f_8001AEC8(void) {
    R[29] = R[29] - 40;  /* 0x8001AEC8 */
    R[4] = R[4] & 0xFF;  /* 0x8001AECC */
    R[2] = R[0] + 1;  /* 0x8001AED0 */
    sw_(R[29] + 32, R[31]);  /* 0x8001AED4 */
    sw_(R[29] + 28, R[19]);  /* 0x8001AED8 */
    sw_(R[29] + 24, R[18]);  /* 0x8001AEDC */
    sw_(R[29] + 20, R[17]);  /* 0x8001AEE0 */
    { uint32_t _c = (R[4] != R[2]); sw_(R[29] + 16, R[16]); if (_c) { goto L_8001B07C; } }  /* 0x8001AEE4 */
    R[2] = 0x8006u << 16;  /* 0x8001AEEC */
    R[17] = R[2] - 10048;  /* 0x8001AEF0 */
    R[16] = lw_(R[17] + 12);  /* 0x8001AEF4 */
    R[2] = lw_(R[17] + 8);  /* 0x8001AEF8 */
    { uint32_t _c = (R[2] == R[0]); R[18] = R[0] + R[0]; if (_c) { goto L_8001AFB8; } }  /* 0x8001AF00 */
    R[4] = 0x8006u << 16;  /* 0x8001AF08 */
    R[4] = R[4] - 12096;  /* 0x8001AF0C */
    { R[31] = 0x8001AF18u; R[5] = R[0] + 512; psx_next = 0x800419C8u; return; }  /* 0x8001AF10 jal */
    R[18] = R[2] + R[0];  /* 0x8001AF18 */
    R[3] = lw_(R[17] + 8);  /* 0x8001AF1C */
    R[2] = R[0] + 2048;  /* 0x8001AF20 */
    R[17] = R[2] - R[3];  /* 0x8001AF24 */
    R[2] = (R[17] < R[16]);  /* 0x8001AF28 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001AF3C; } }  /* 0x8001AF2C */
    { R[16] = R[16] - R[17]; goto L_8001AF44; }  /* 0x8001AF34 j */
L_8001AF3C:;
    R[17] = R[16] + R[0];  /* 0x8001AF3C */
    R[16] = R[0] + R[0];  /* 0x8001AF40 */
L_8001AF44:;
    { uint32_t _c = (R[16] != R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8001AF58; } }  /* 0x8001AF44 */
    { R[31] = 0x8001AF54u; psx_next = 0x80042C0Cu; return; }  /* 0x8001AF4C jal */
    R[2] = 0x8006u << 16;  /* 0x8001AF54 */
L_8001AF58:;
    R[2] = R[2] - 10048;  /* 0x8001AF58 */
    R[4] = lw_(R[2] + 8);  /* 0x8001AF5C */
    { uint32_t _c = (R[17] == R[0]); R[5] = R[0] + R[0]; if (_c) { goto L_8001AF94; } }  /* 0x8001AF60 */
    R[7] = R[2] + R[0];  /* 0x8001AF68 */
    R[2] = 0x8006u << 16;  /* 0x8001AF6C */
    R[6] = R[2] - 12096;  /* 0x8001AF70 */
L_8001AF74:;
    R[2] = R[4] + R[6];  /* 0x8001AF74 */
    R[4] = R[4] + 1;  /* 0x8001AF78 */
    R[3] = lw_(R[7] + 4);  /* 0x8001AF7C */
    R[2] = lb_(R[2]);  /* 0x8001AF80 */
    R[3] = R[3] + R[5];  /* 0x8001AF84 */
    R[5] = R[5] + 1;  /* 0x8001AF88 */
    { uint32_t _c = (R[5] != R[17]); sb_(R[3], R[2]); if (_c) { psx_bb(); goto L_8001AF74; } }  /* 0x8001AF8C */
L_8001AF94:;
    R[3] = 0x8006u << 16;  /* 0x8001AF94 */
    R[3] = R[3] - 10048;  /* 0x8001AF98 */
    R[2] = lw_(R[3] + 4);  /* 0x8001AF9C */
    R[2] = R[2] + R[17];  /* 0x8001AFA4 */
    sw_(R[3] + 4, R[2]);  /* 0x8001AFA8 */
    sw_(R[3] + 8, R[0]);  /* 0x8001AFAC */
    { R[3] = 0x8006u << 16; goto L_8001B054; }  /* 0x8001AFB0 j */
L_8001AFB8:;
    R[2] = (R[16] < (uint32_t)2048u);  /* 0x8001AFB8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[16] - 1; if (_c) { goto L_8001AFFC; } }  /* 0x8001AFBC */
    R[5] = R[0] + 512;  /* 0x8001AFC4 */
    R[4] = lw_(R[17] + 4);  /* 0x8001AFC8 */
    { R[31] = 0x8001AFD4u; R[16] = R[16] - 2048; psx_next = 0x800419C8u; return; }  /* 0x8001AFCC jal */
    R[3] = lw_(R[17] + 4);  /* 0x8001AFD4 */
    R[18] = R[2] + R[0];  /* 0x8001AFD8 */
    R[3] = R[3] + 2048;  /* 0x8001AFDC */
    sw_(R[17] + 4, R[3]);  /* 0x8001AFE0 */
    { uint32_t _c = (R[16] != R[0]); R[3] = 0x8006u << 16; if (_c) { goto L_8001B054; } }  /* 0x8001AFE4 */
    { R[31] = 0x8001AFF4u; psx_next = 0x80042C0Cu; return; }  /* 0x8001AFEC jal */
    { R[3] = 0x8006u << 16; goto L_8001B054; }  /* 0x8001AFF4 j */
L_8001AFFC:;
    R[2] = (R[2] < (uint32_t)2047u);  /* 0x8001AFFC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8001B050; } }  /* 0x8001B000 */
    R[19] = R[2] - 12096;  /* 0x8001B008 */
    R[4] = R[19] + R[0];  /* 0x8001B00C */
    { R[31] = 0x8001B018u; R[5] = R[0] + 512; psx_next = 0x800419C8u; return; }  /* 0x8001B010 jal */
    { R[31] = 0x8001B020u; R[18] = R[2] + R[0]; psx_next = 0x80042C0Cu; return; }  /* 0x8001B018 jal */
    { uint32_t _c = (R[16] == R[0]); R[5] = R[0] + R[0]; if (_c) { goto L_8001B04C; } }  /* 0x8001B020 */
    R[6] = R[17] + R[0];  /* 0x8001B028 */
    R[4] = R[19] + R[0];  /* 0x8001B02C */
L_8001B030:;
    R[3] = R[5] + R[4];  /* 0x8001B030 */
    R[2] = lw_(R[6] + 4);  /* 0x8001B034 */
    R[3] = lb_(R[3]);  /* 0x8001B038 */
    R[2] = R[2] + R[5];  /* 0x8001B03C */
    R[5] = R[5] + 1;  /* 0x8001B040 */
    { uint32_t _c = (R[5] != R[16]); sb_(R[2], R[3]); if (_c) { psx_bb(); goto L_8001B030; } }  /* 0x8001B044 */
L_8001B04C:;
    R[16] = R[0] + R[0];  /* 0x8001B04C */
L_8001B050:;
    R[3] = 0x8006u << 16;  /* 0x8001B050 */
L_8001B054:;
    R[2] = R[3] - 10048;  /* 0x8001B054 */
    sw_(R[2] + 12, R[16]);  /* 0x8001B058 */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8001B06C; } }  /* 0x8001B05C */
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_8001B07C; } }  /* 0x8001B064 */
L_8001B06C:;
    { uint32_t _c = (R[18] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8001B078; } }  /* 0x8001B06C */
    R[2] = R[0] + 2;  /* 0x8001B074 */
L_8001B078:;
    sh_(R[3] + -10048, R[2]);  /* 0x8001B078 */
L_8001B07C:;
    R[31] = lw_(R[29] + 32);  /* 0x8001B07C */
    R[19] = lw_(R[29] + 28);  /* 0x8001B080 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B084 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B088 */
    R[16] = lw_(R[29] + 16);  /* 0x8001B08C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B090 jr ra */
}

void f_8001AF18(void) {
    R[18] = R[2] + R[0];  /* 0x8001AF18 */
    R[3] = lw_(R[17] + 8);  /* 0x8001AF1C */
    R[2] = R[0] + 2048;  /* 0x8001AF20 */
    R[17] = R[2] - R[3];  /* 0x8001AF24 */
    R[2] = (R[17] < R[16]);  /* 0x8001AF28 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001AF3C; } }  /* 0x8001AF2C */
    { R[16] = R[16] - R[17]; goto L_8001AF44; }  /* 0x8001AF34 j */
L_8001AF3C:;
    R[17] = R[16] + R[0];  /* 0x8001AF3C */
    R[16] = R[0] + R[0];  /* 0x8001AF40 */
L_8001AF44:;
    { uint32_t _c = (R[16] != R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8001AF58; } }  /* 0x8001AF44 */
    { R[31] = 0x8001AF54u; psx_next = 0x80042C0Cu; return; }  /* 0x8001AF4C jal */
    R[2] = 0x8006u << 16;  /* 0x8001AF54 */
L_8001AF58:;
    R[2] = R[2] - 10048;  /* 0x8001AF58 */
    R[4] = lw_(R[2] + 8);  /* 0x8001AF5C */
    { uint32_t _c = (R[17] == R[0]); R[5] = R[0] + R[0]; if (_c) { goto L_8001AF94; } }  /* 0x8001AF60 */
    R[7] = R[2] + R[0];  /* 0x8001AF68 */
    R[2] = 0x8006u << 16;  /* 0x8001AF6C */
    R[6] = R[2] - 12096;  /* 0x8001AF70 */
L_8001AF74:;
    R[2] = R[4] + R[6];  /* 0x8001AF74 */
    R[4] = R[4] + 1;  /* 0x8001AF78 */
    R[3] = lw_(R[7] + 4);  /* 0x8001AF7C */
    R[2] = lb_(R[2]);  /* 0x8001AF80 */
    R[3] = R[3] + R[5];  /* 0x8001AF84 */
    R[5] = R[5] + 1;  /* 0x8001AF88 */
    { uint32_t _c = (R[5] != R[17]); sb_(R[3], R[2]); if (_c) { psx_bb(); goto L_8001AF74; } }  /* 0x8001AF8C */
L_8001AF94:;
    R[3] = 0x8006u << 16;  /* 0x8001AF94 */
    R[3] = R[3] - 10048;  /* 0x8001AF98 */
    R[2] = lw_(R[3] + 4);  /* 0x8001AF9C */
    R[2] = R[2] + R[17];  /* 0x8001AFA4 */
    sw_(R[3] + 4, R[2]);  /* 0x8001AFA8 */
    sw_(R[3] + 8, R[0]);  /* 0x8001AFAC */
    { R[3] = 0x8006u << 16; goto L_8001B054; }  /* 0x8001AFB0 j */
    R[2] = (R[16] < (uint32_t)2048u);  /* 0x8001AFB8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[16] - 1; if (_c) { goto L_8001AFFC; } }  /* 0x8001AFBC */
    R[5] = R[0] + 512;  /* 0x8001AFC4 */
    R[4] = lw_(R[17] + 4);  /* 0x8001AFC8 */
    { R[31] = 0x8001AFD4u; R[16] = R[16] - 2048; psx_next = 0x800419C8u; return; }  /* 0x8001AFCC jal */
    R[3] = lw_(R[17] + 4);  /* 0x8001AFD4 */
    R[18] = R[2] + R[0];  /* 0x8001AFD8 */
    R[3] = R[3] + 2048;  /* 0x8001AFDC */
    sw_(R[17] + 4, R[3]);  /* 0x8001AFE0 */
    { uint32_t _c = (R[16] != R[0]); R[3] = 0x8006u << 16; if (_c) { goto L_8001B054; } }  /* 0x8001AFE4 */
    { R[31] = 0x8001AFF4u; psx_next = 0x80042C0Cu; return; }  /* 0x8001AFEC jal */
    { R[3] = 0x8006u << 16; goto L_8001B054; }  /* 0x8001AFF4 j */
L_8001AFFC:;
    R[2] = (R[2] < (uint32_t)2047u);  /* 0x8001AFFC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8001B050; } }  /* 0x8001B000 */
    R[19] = R[2] - 12096;  /* 0x8001B008 */
    R[4] = R[19] + R[0];  /* 0x8001B00C */
    { R[31] = 0x8001B018u; R[5] = R[0] + 512; psx_next = 0x800419C8u; return; }  /* 0x8001B010 jal */
    { R[31] = 0x8001B020u; R[18] = R[2] + R[0]; psx_next = 0x80042C0Cu; return; }  /* 0x8001B018 jal */
    { uint32_t _c = (R[16] == R[0]); R[5] = R[0] + R[0]; if (_c) { goto L_8001B04C; } }  /* 0x8001B020 */
    R[6] = R[17] + R[0];  /* 0x8001B028 */
    R[4] = R[19] + R[0];  /* 0x8001B02C */
L_8001B030:;
    R[3] = R[5] + R[4];  /* 0x8001B030 */
    R[2] = lw_(R[6] + 4);  /* 0x8001B034 */
    R[3] = lb_(R[3]);  /* 0x8001B038 */
    R[2] = R[2] + R[5];  /* 0x8001B03C */
    R[5] = R[5] + 1;  /* 0x8001B040 */
    { uint32_t _c = (R[5] != R[16]); sb_(R[2], R[3]); if (_c) { psx_bb(); goto L_8001B030; } }  /* 0x8001B044 */
L_8001B04C:;
    R[16] = R[0] + R[0];  /* 0x8001B04C */
L_8001B050:;
    R[3] = 0x8006u << 16;  /* 0x8001B050 */
L_8001B054:;
    R[2] = R[3] - 10048;  /* 0x8001B054 */
    sw_(R[2] + 12, R[16]);  /* 0x8001B058 */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8001B06C; } }  /* 0x8001B05C */
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_8001B07C; } }  /* 0x8001B064 */
L_8001B06C:;
    { uint32_t _c = (R[18] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8001B078; } }  /* 0x8001B06C */
    R[2] = R[0] + 2;  /* 0x8001B074 */
L_8001B078:;
    sh_(R[3] + -10048, R[2]);  /* 0x8001B078 */
L_8001B07C:;
    R[31] = lw_(R[29] + 32);  /* 0x8001B07C */
    R[19] = lw_(R[29] + 28);  /* 0x8001B080 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B084 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B088 */
    R[16] = lw_(R[29] + 16);  /* 0x8001B08C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B090 jr ra */
}

void f_8001AF54(void) {
    R[2] = 0x8006u << 16;  /* 0x8001AF54 */
    R[2] = R[2] - 10048;  /* 0x8001AF58 */
    R[4] = lw_(R[2] + 8);  /* 0x8001AF5C */
    { uint32_t _c = (R[17] == R[0]); R[5] = R[0] + R[0]; if (_c) { goto L_8001AF94; } }  /* 0x8001AF60 */
    R[7] = R[2] + R[0];  /* 0x8001AF68 */
    R[2] = 0x8006u << 16;  /* 0x8001AF6C */
    R[6] = R[2] - 12096;  /* 0x8001AF70 */
L_8001AF74:;
    R[2] = R[4] + R[6];  /* 0x8001AF74 */
    R[4] = R[4] + 1;  /* 0x8001AF78 */
    R[3] = lw_(R[7] + 4);  /* 0x8001AF7C */
    R[2] = lb_(R[2]);  /* 0x8001AF80 */
    R[3] = R[3] + R[5];  /* 0x8001AF84 */
    R[5] = R[5] + 1;  /* 0x8001AF88 */
    { uint32_t _c = (R[5] != R[17]); sb_(R[3], R[2]); if (_c) { psx_bb(); goto L_8001AF74; } }  /* 0x8001AF8C */
L_8001AF94:;
    R[3] = 0x8006u << 16;  /* 0x8001AF94 */
    R[3] = R[3] - 10048;  /* 0x8001AF98 */
    R[2] = lw_(R[3] + 4);  /* 0x8001AF9C */
    R[2] = R[2] + R[17];  /* 0x8001AFA4 */
    sw_(R[3] + 4, R[2]);  /* 0x8001AFA8 */
    sw_(R[3] + 8, R[0]);  /* 0x8001AFAC */
    { R[3] = 0x8006u << 16; goto L_8001B054; }  /* 0x8001AFB0 j */
    R[2] = (R[16] < (uint32_t)2048u);  /* 0x8001AFB8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[16] - 1; if (_c) { goto L_8001AFFC; } }  /* 0x8001AFBC */
    R[5] = R[0] + 512;  /* 0x8001AFC4 */
    R[4] = lw_(R[17] + 4);  /* 0x8001AFC8 */
    { R[31] = 0x8001AFD4u; R[16] = R[16] - 2048; psx_next = 0x800419C8u; return; }  /* 0x8001AFCC jal */
    R[3] = lw_(R[17] + 4);  /* 0x8001AFD4 */
    R[18] = R[2] + R[0];  /* 0x8001AFD8 */
    R[3] = R[3] + 2048;  /* 0x8001AFDC */
    sw_(R[17] + 4, R[3]);  /* 0x8001AFE0 */
    { uint32_t _c = (R[16] != R[0]); R[3] = 0x8006u << 16; if (_c) { goto L_8001B054; } }  /* 0x8001AFE4 */
    { R[31] = 0x8001AFF4u; psx_next = 0x80042C0Cu; return; }  /* 0x8001AFEC jal */
    { R[3] = 0x8006u << 16; goto L_8001B054; }  /* 0x8001AFF4 j */
L_8001AFFC:;
    R[2] = (R[2] < (uint32_t)2047u);  /* 0x8001AFFC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8001B050; } }  /* 0x8001B000 */
    R[19] = R[2] - 12096;  /* 0x8001B008 */
    R[4] = R[19] + R[0];  /* 0x8001B00C */
    { R[31] = 0x8001B018u; R[5] = R[0] + 512; psx_next = 0x800419C8u; return; }  /* 0x8001B010 jal */
    { R[31] = 0x8001B020u; R[18] = R[2] + R[0]; psx_next = 0x80042C0Cu; return; }  /* 0x8001B018 jal */
    { uint32_t _c = (R[16] == R[0]); R[5] = R[0] + R[0]; if (_c) { goto L_8001B04C; } }  /* 0x8001B020 */
    R[6] = R[17] + R[0];  /* 0x8001B028 */
    R[4] = R[19] + R[0];  /* 0x8001B02C */
L_8001B030:;
    R[3] = R[5] + R[4];  /* 0x8001B030 */
    R[2] = lw_(R[6] + 4);  /* 0x8001B034 */
    R[3] = lb_(R[3]);  /* 0x8001B038 */
    R[2] = R[2] + R[5];  /* 0x8001B03C */
    R[5] = R[5] + 1;  /* 0x8001B040 */
    { uint32_t _c = (R[5] != R[16]); sb_(R[2], R[3]); if (_c) { psx_bb(); goto L_8001B030; } }  /* 0x8001B044 */
L_8001B04C:;
    R[16] = R[0] + R[0];  /* 0x8001B04C */
L_8001B050:;
    R[3] = 0x8006u << 16;  /* 0x8001B050 */
L_8001B054:;
    R[2] = R[3] - 10048;  /* 0x8001B054 */
    sw_(R[2] + 12, R[16]);  /* 0x8001B058 */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8001B06C; } }  /* 0x8001B05C */
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_8001B07C; } }  /* 0x8001B064 */
L_8001B06C:;
    { uint32_t _c = (R[18] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8001B078; } }  /* 0x8001B06C */
    R[2] = R[0] + 2;  /* 0x8001B074 */
L_8001B078:;
    sh_(R[3] + -10048, R[2]);  /* 0x8001B078 */
L_8001B07C:;
    R[31] = lw_(R[29] + 32);  /* 0x8001B07C */
    R[19] = lw_(R[29] + 28);  /* 0x8001B080 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B084 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B088 */
    R[16] = lw_(R[29] + 16);  /* 0x8001B08C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B090 jr ra */
}

void f_8001AFD4(void) {
    R[3] = lw_(R[17] + 4);  /* 0x8001AFD4 */
    R[18] = R[2] + R[0];  /* 0x8001AFD8 */
    R[3] = R[3] + 2048;  /* 0x8001AFDC */
    sw_(R[17] + 4, R[3]);  /* 0x8001AFE0 */
    { uint32_t _c = (R[16] != R[0]); R[3] = 0x8006u << 16; if (_c) { goto L_8001B054; } }  /* 0x8001AFE4 */
    { R[31] = 0x8001AFF4u; psx_next = 0x80042C0Cu; return; }  /* 0x8001AFEC jal */
    { R[3] = 0x8006u << 16; goto L_8001B054; }  /* 0x8001AFF4 j */
    R[2] = (R[2] < (uint32_t)2047u);  /* 0x8001AFFC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8001B050; } }  /* 0x8001B000 */
    R[19] = R[2] - 12096;  /* 0x8001B008 */
    R[4] = R[19] + R[0];  /* 0x8001B00C */
    { R[31] = 0x8001B018u; R[5] = R[0] + 512; psx_next = 0x800419C8u; return; }  /* 0x8001B010 jal */
    { R[31] = 0x8001B020u; R[18] = R[2] + R[0]; psx_next = 0x80042C0Cu; return; }  /* 0x8001B018 jal */
    { uint32_t _c = (R[16] == R[0]); R[5] = R[0] + R[0]; if (_c) { goto L_8001B04C; } }  /* 0x8001B020 */
    R[6] = R[17] + R[0];  /* 0x8001B028 */
    R[4] = R[19] + R[0];  /* 0x8001B02C */
L_8001B030:;
    R[3] = R[5] + R[4];  /* 0x8001B030 */
    R[2] = lw_(R[6] + 4);  /* 0x8001B034 */
    R[3] = lb_(R[3]);  /* 0x8001B038 */
    R[2] = R[2] + R[5];  /* 0x8001B03C */
    R[5] = R[5] + 1;  /* 0x8001B040 */
    { uint32_t _c = (R[5] != R[16]); sb_(R[2], R[3]); if (_c) { psx_bb(); goto L_8001B030; } }  /* 0x8001B044 */
L_8001B04C:;
    R[16] = R[0] + R[0];  /* 0x8001B04C */
L_8001B050:;
    R[3] = 0x8006u << 16;  /* 0x8001B050 */
L_8001B054:;
    R[2] = R[3] - 10048;  /* 0x8001B054 */
    sw_(R[2] + 12, R[16]);  /* 0x8001B058 */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8001B06C; } }  /* 0x8001B05C */
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_8001B07C; } }  /* 0x8001B064 */
L_8001B06C:;
    { uint32_t _c = (R[18] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8001B078; } }  /* 0x8001B06C */
    R[2] = R[0] + 2;  /* 0x8001B074 */
L_8001B078:;
    sh_(R[3] + -10048, R[2]);  /* 0x8001B078 */
L_8001B07C:;
    R[31] = lw_(R[29] + 32);  /* 0x8001B07C */
    R[19] = lw_(R[29] + 28);  /* 0x8001B080 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B084 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B088 */
    R[16] = lw_(R[29] + 16);  /* 0x8001B08C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B090 jr ra */
}

void f_8001AFF4(void) {
    { R[3] = 0x8006u << 16; goto L_8001B054; }  /* 0x8001AFF4 j */
    R[2] = (R[2] < (uint32_t)2047u);  /* 0x8001AFFC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8001B050; } }  /* 0x8001B000 */
    R[19] = R[2] - 12096;  /* 0x8001B008 */
    R[4] = R[19] + R[0];  /* 0x8001B00C */
    { R[31] = 0x8001B018u; R[5] = R[0] + 512; psx_next = 0x800419C8u; return; }  /* 0x8001B010 jal */
    { R[31] = 0x8001B020u; R[18] = R[2] + R[0]; psx_next = 0x80042C0Cu; return; }  /* 0x8001B018 jal */
    { uint32_t _c = (R[16] == R[0]); R[5] = R[0] + R[0]; if (_c) { goto L_8001B04C; } }  /* 0x8001B020 */
    R[6] = R[17] + R[0];  /* 0x8001B028 */
    R[4] = R[19] + R[0];  /* 0x8001B02C */
L_8001B030:;
    R[3] = R[5] + R[4];  /* 0x8001B030 */
    R[2] = lw_(R[6] + 4);  /* 0x8001B034 */
    R[3] = lb_(R[3]);  /* 0x8001B038 */
    R[2] = R[2] + R[5];  /* 0x8001B03C */
    R[5] = R[5] + 1;  /* 0x8001B040 */
    { uint32_t _c = (R[5] != R[16]); sb_(R[2], R[3]); if (_c) { psx_bb(); goto L_8001B030; } }  /* 0x8001B044 */
L_8001B04C:;
    R[16] = R[0] + R[0];  /* 0x8001B04C */
L_8001B050:;
    R[3] = 0x8006u << 16;  /* 0x8001B050 */
L_8001B054:;
    R[2] = R[3] - 10048;  /* 0x8001B054 */
    sw_(R[2] + 12, R[16]);  /* 0x8001B058 */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8001B06C; } }  /* 0x8001B05C */
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_8001B07C; } }  /* 0x8001B064 */
L_8001B06C:;
    { uint32_t _c = (R[18] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8001B078; } }  /* 0x8001B06C */
    R[2] = R[0] + 2;  /* 0x8001B074 */
L_8001B078:;
    sh_(R[3] + -10048, R[2]);  /* 0x8001B078 */
L_8001B07C:;
    R[31] = lw_(R[29] + 32);  /* 0x8001B07C */
    R[19] = lw_(R[29] + 28);  /* 0x8001B080 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B084 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B088 */
    R[16] = lw_(R[29] + 16);  /* 0x8001B08C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B090 jr ra */
}

void f_8001B018(void) {
    { R[31] = 0x8001B020u; R[18] = R[2] + R[0]; psx_next = 0x80042C0Cu; return; }  /* 0x8001B018 jal */
    { uint32_t _c = (R[16] == R[0]); R[5] = R[0] + R[0]; if (_c) { goto L_8001B04C; } }  /* 0x8001B020 */
    R[6] = R[17] + R[0];  /* 0x8001B028 */
    R[4] = R[19] + R[0];  /* 0x8001B02C */
L_8001B030:;
    R[3] = R[5] + R[4];  /* 0x8001B030 */
    R[2] = lw_(R[6] + 4);  /* 0x8001B034 */
    R[3] = lb_(R[3]);  /* 0x8001B038 */
    R[2] = R[2] + R[5];  /* 0x8001B03C */
    R[5] = R[5] + 1;  /* 0x8001B040 */
    { uint32_t _c = (R[5] != R[16]); sb_(R[2], R[3]); if (_c) { psx_bb(); goto L_8001B030; } }  /* 0x8001B044 */
L_8001B04C:;
    R[16] = R[0] + R[0];  /* 0x8001B04C */
    R[3] = 0x8006u << 16;  /* 0x8001B050 */
    R[2] = R[3] - 10048;  /* 0x8001B054 */
    sw_(R[2] + 12, R[16]);  /* 0x8001B058 */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8001B06C; } }  /* 0x8001B05C */
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_8001B07C; } }  /* 0x8001B064 */
L_8001B06C:;
    { uint32_t _c = (R[18] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8001B078; } }  /* 0x8001B06C */
    R[2] = R[0] + 2;  /* 0x8001B074 */
L_8001B078:;
    sh_(R[3] + -10048, R[2]);  /* 0x8001B078 */
L_8001B07C:;
    R[31] = lw_(R[29] + 32);  /* 0x8001B07C */
    R[19] = lw_(R[29] + 28);  /* 0x8001B080 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B084 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B088 */
    R[16] = lw_(R[29] + 16);  /* 0x8001B08C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B090 jr ra */
}

void f_8001B020(void) {
    { uint32_t _c = (R[16] == R[0]); R[5] = R[0] + R[0]; if (_c) { goto L_8001B04C; } }  /* 0x8001B020 */
    R[6] = R[17] + R[0];  /* 0x8001B028 */
    R[4] = R[19] + R[0];  /* 0x8001B02C */
L_8001B030:;
    R[3] = R[5] + R[4];  /* 0x8001B030 */
    R[2] = lw_(R[6] + 4);  /* 0x8001B034 */
    R[3] = lb_(R[3]);  /* 0x8001B038 */
    R[2] = R[2] + R[5];  /* 0x8001B03C */
    R[5] = R[5] + 1;  /* 0x8001B040 */
    { uint32_t _c = (R[5] != R[16]); sb_(R[2], R[3]); if (_c) { psx_bb(); goto L_8001B030; } }  /* 0x8001B044 */
L_8001B04C:;
    R[16] = R[0] + R[0];  /* 0x8001B04C */
    R[3] = 0x8006u << 16;  /* 0x8001B050 */
    R[2] = R[3] - 10048;  /* 0x8001B054 */
    sw_(R[2] + 12, R[16]);  /* 0x8001B058 */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8001B06C; } }  /* 0x8001B05C */
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_8001B07C; } }  /* 0x8001B064 */
L_8001B06C:;
    { uint32_t _c = (R[18] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8001B078; } }  /* 0x8001B06C */
    R[2] = R[0] + 2;  /* 0x8001B074 */
L_8001B078:;
    sh_(R[3] + -10048, R[2]);  /* 0x8001B078 */
L_8001B07C:;
    R[31] = lw_(R[29] + 32);  /* 0x8001B07C */
    R[19] = lw_(R[29] + 28);  /* 0x8001B080 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B084 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B088 */
    R[16] = lw_(R[29] + 16);  /* 0x8001B08C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B090 jr ra */
}

void f_8001B098(void) {
    R[29] = R[29] - 24;  /* 0x8001B098 */
    R[4] = R[4] & 0xFF;  /* 0x8001B09C */
    R[2] = R[0] + 2;  /* 0x8001B0A0 */
    { uint32_t _c = (R[4] != R[2]); sw_(R[29] + 16, R[31]); if (_c) { goto L_8001B0BC; } }  /* 0x8001B0A4 */
    R[4] = 0x8002u << 16;  /* 0x8001B0AC */
    R[4] = R[4] - 20792;  /* 0x8001B0B0 */
    { R[31] = 0x8001B0BCu; R[5] = R[0] - 1; psx_next = 0x80042B88u; return; }  /* 0x8001B0B4 jal */
L_8001B0BC:;
    R[31] = lw_(R[29] + 16);  /* 0x8001B0BC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001B0C4 jr ra */
}

void f_8001B0BC(void) {
    R[31] = lw_(R[29] + 16);  /* 0x8001B0BC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001B0C4 jr ra */
}

void f_8001B0CC(void) {
    R[29] = R[29] - 96;  /* 0x8001B0CC */
    sw_(R[29] + 88, R[30]);  /* 0x8001B0D0 */
    R[30] = lw_(R[29] + 112);  /* 0x8001B0D4 */
    sw_(R[29] + 80, R[22]);  /* 0x8001B0D8 */
    R[22] = R[4] + R[0];  /* 0x8001B0DC */
    sw_(R[29] + 84, R[23]);  /* 0x8001B0E0 */
    R[23] = R[5] + R[0];  /* 0x8001B0E4 */
    sw_(R[29] + 76, R[21]);  /* 0x8001B0E8 */
    R[21] = R[6] + R[0];  /* 0x8001B0EC */
    sw_(R[29] + 64, R[18]);  /* 0x8001B0F0 */
    R[18] = R[7] + R[0];  /* 0x8001B0F4 */
    sw_(R[29] + 92, R[31]);  /* 0x8001B0F8 */
    sw_(R[29] + 72, R[20]);  /* 0x8001B0FC */
    sw_(R[29] + 68, R[19]);  /* 0x8001B100 */
    sw_(R[29] + 60, R[17]);  /* 0x8001B104 */
    { R[31] = 0x8001B110u; sw_(R[29] + 56, R[16]); psx_next = 0x8002FAA4u; return; }  /* 0x8001B108 jal */
    R[4] = R[29] + 24;  /* 0x8001B110 */
L_8001B114:;
    { R[31] = 0x8001B11Cu; R[5] = R[22] + R[0]; psx_next = 0x8001AD68u; return; }  /* 0x8001B114 jal */
    R[19] = R[0] - 1;  /* 0x8001B11C */
    { uint32_t _c = (R[18] != R[19]); R[17] = R[2] + R[0]; if (_c) { goto L_8001B12C; } }  /* 0x8001B120 */
    R[18] = lw_(R[17] + 4);  /* 0x8001B128 */
L_8001B12C:;
    R[4] = R[17] + R[0];  /* 0x8001B12C */
    R[20] = R[18] + R[0];  /* 0x8001B130 */
    { R[31] = 0x8001B13Cu; R[16] = R[21] >> 11; psx_next = 0x80041B2Cu; return; }  /* 0x8001B134 jal */
    R[4] = R[2] + R[16];  /* 0x8001B13C */
    { R[31] = 0x8001B148u; R[5] = R[17] + R[0]; psx_next = 0x80041A28u; return; }  /* 0x8001B140 jal */
    R[4] = R[0] + 160;  /* 0x8001B148 */
    R[5] = R[17] + R[0];  /* 0x8001B14C */
    R[6] = R[0] + 6;  /* 0x8001B150 */
    R[2] = 0x8006u << 16;  /* 0x8001B154 */
    sh_(R[2] + -10048, R[0]);  /* 0x8001B158 */
    R[2] = R[2] - 10048;  /* 0x8001B15C */
    R[3] = R[21] & 0x7FF;  /* 0x8001B160 */
    R[7] = 0x8002u << 16;  /* 0x8001B164 */
    R[7] = R[7] - 20328;  /* 0x8001B168 */
    sw_(R[2] + 4, R[23]);  /* 0x8001B16C */
    sw_(R[2] + 8, R[3]);  /* 0x8001B170 */
    sw_(R[2] + 12, R[20]);  /* 0x8001B174 */
    { R[31] = 0x8001B180u; sw_(R[29] + 16, R[19]); psx_next = 0x8003E6CCu; return; }  /* 0x8001B178 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B234; } }  /* 0x8001B180 */
    { R[31] = 0x8001B190u; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B188 jal */
    R[16] = R[0] + 5;  /* 0x8001B190 */
L_8001B194:;
    { R[31] = 0x8001B19Cu; psx_next = 0x8003EDE0u; return; }  /* 0x8001B194 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B19C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B1C0; } }  /* 0x8001B1A0 */
    { R[31] = 0x8001B1B0u; R[5] = R[29] + 48; psx_next = 0x8003EA70u; return; }  /* 0x8001B1A8 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B234; } }  /* 0x8001B1B0 */
    { psx_bb(); goto L_8001B194; }  /* 0x8001B1B8 j */
L_8001B1C0:;
    R[2] = R[0] + 1;  /* 0x8001B1C0 */
    { uint32_t _c = (R[30] != R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8001B1D4; } }  /* 0x8001B1C4 */
    { R[2] = R[0] + R[0]; goto L_8001B258; }  /* 0x8001B1CC j */
L_8001B1D4:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1D4 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B214; } }  /* 0x8001B1DC */
    R[4] = R[0] + 2;  /* 0x8001B1E4 */
L_8001B1E8:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1E8 */
    R[2] = R[2] << 16;  /* 0x8001B1F0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B1F4 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B230; } }  /* 0x8001B1F8 */
    R[2] = lh_(R[3] + -10048);  /* 0x8001B200 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B1E8; } }  /* 0x8001B208 */
    R[4] = R[0] + 9;  /* 0x8001B210 */
L_8001B214:;
    R[5] = R[0] + R[0];  /* 0x8001B214 */
    { R[31] = 0x8001B220u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B218 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B214; } }  /* 0x8001B220 */
    { R[2] = R[20] + R[0]; goto L_8001B258; }  /* 0x8001B228 j */
L_8001B230:;
    R[4] = R[0] + 9;  /* 0x8001B230 */
L_8001B234:;
    R[5] = R[0] + R[0];  /* 0x8001B234 */
    { R[31] = 0x8001B240u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B238 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B234; } }  /* 0x8001B240 */
    { R[31] = 0x8001B250u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B248 jal */
    { R[4] = R[29] + 24; psx_bb(); goto L_8001B114; }  /* 0x8001B250 j */
L_8001B258:;
    R[31] = lw_(R[29] + 92);  /* 0x8001B258 */
    R[30] = lw_(R[29] + 88);  /* 0x8001B25C */
    R[23] = lw_(R[29] + 84);  /* 0x8001B260 */
    R[22] = lw_(R[29] + 80);  /* 0x8001B264 */
    R[21] = lw_(R[29] + 76);  /* 0x8001B268 */
    R[20] = lw_(R[29] + 72);  /* 0x8001B26C */
    R[19] = lw_(R[29] + 68);  /* 0x8001B270 */
    R[18] = lw_(R[29] + 64);  /* 0x8001B274 */
    R[17] = lw_(R[29] + 60);  /* 0x8001B278 */
    R[16] = lw_(R[29] + 56);  /* 0x8001B27C */
    { R[29] = R[29] + 96; psx_next = R[31]; return; }  /* 0x8001B280 jr ra */
}

void f_8001B110(void) {
    R[4] = R[29] + 24;  /* 0x8001B110 */
L_8001B114:;
    { R[31] = 0x8001B11Cu; R[5] = R[22] + R[0]; psx_next = 0x8001AD68u; return; }  /* 0x8001B114 jal */
    R[19] = R[0] - 1;  /* 0x8001B11C */
    { uint32_t _c = (R[18] != R[19]); R[17] = R[2] + R[0]; if (_c) { goto L_8001B12C; } }  /* 0x8001B120 */
    R[18] = lw_(R[17] + 4);  /* 0x8001B128 */
L_8001B12C:;
    R[4] = R[17] + R[0];  /* 0x8001B12C */
    R[20] = R[18] + R[0];  /* 0x8001B130 */
    { R[31] = 0x8001B13Cu; R[16] = R[21] >> 11; psx_next = 0x80041B2Cu; return; }  /* 0x8001B134 jal */
    R[4] = R[2] + R[16];  /* 0x8001B13C */
    { R[31] = 0x8001B148u; R[5] = R[17] + R[0]; psx_next = 0x80041A28u; return; }  /* 0x8001B140 jal */
    R[4] = R[0] + 160;  /* 0x8001B148 */
    R[5] = R[17] + R[0];  /* 0x8001B14C */
    R[6] = R[0] + 6;  /* 0x8001B150 */
    R[2] = 0x8006u << 16;  /* 0x8001B154 */
    sh_(R[2] + -10048, R[0]);  /* 0x8001B158 */
    R[2] = R[2] - 10048;  /* 0x8001B15C */
    R[3] = R[21] & 0x7FF;  /* 0x8001B160 */
    R[7] = 0x8002u << 16;  /* 0x8001B164 */
    R[7] = R[7] - 20328;  /* 0x8001B168 */
    sw_(R[2] + 4, R[23]);  /* 0x8001B16C */
    sw_(R[2] + 8, R[3]);  /* 0x8001B170 */
    sw_(R[2] + 12, R[20]);  /* 0x8001B174 */
    { R[31] = 0x8001B180u; sw_(R[29] + 16, R[19]); psx_next = 0x8003E6CCu; return; }  /* 0x8001B178 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B234; } }  /* 0x8001B180 */
    { R[31] = 0x8001B190u; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B188 jal */
    R[16] = R[0] + 5;  /* 0x8001B190 */
L_8001B194:;
    { R[31] = 0x8001B19Cu; psx_next = 0x8003EDE0u; return; }  /* 0x8001B194 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B19C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B1C0; } }  /* 0x8001B1A0 */
    { R[31] = 0x8001B1B0u; R[5] = R[29] + 48; psx_next = 0x8003EA70u; return; }  /* 0x8001B1A8 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B234; } }  /* 0x8001B1B0 */
    { psx_bb(); goto L_8001B194; }  /* 0x8001B1B8 j */
L_8001B1C0:;
    R[2] = R[0] + 1;  /* 0x8001B1C0 */
    { uint32_t _c = (R[30] != R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8001B1D4; } }  /* 0x8001B1C4 */
    { R[2] = R[0] + R[0]; goto L_8001B258; }  /* 0x8001B1CC j */
L_8001B1D4:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1D4 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B214; } }  /* 0x8001B1DC */
    R[4] = R[0] + 2;  /* 0x8001B1E4 */
L_8001B1E8:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1E8 */
    R[2] = R[2] << 16;  /* 0x8001B1F0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B1F4 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B230; } }  /* 0x8001B1F8 */
    R[2] = lh_(R[3] + -10048);  /* 0x8001B200 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B1E8; } }  /* 0x8001B208 */
    R[4] = R[0] + 9;  /* 0x8001B210 */
L_8001B214:;
    R[5] = R[0] + R[0];  /* 0x8001B214 */
    { R[31] = 0x8001B220u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B218 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B214; } }  /* 0x8001B220 */
    { R[2] = R[20] + R[0]; goto L_8001B258; }  /* 0x8001B228 j */
L_8001B230:;
    R[4] = R[0] + 9;  /* 0x8001B230 */
L_8001B234:;
    R[5] = R[0] + R[0];  /* 0x8001B234 */
    { R[31] = 0x8001B240u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B238 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B234; } }  /* 0x8001B240 */
    { R[31] = 0x8001B250u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B248 jal */
    { R[4] = R[29] + 24; psx_bb(); goto L_8001B114; }  /* 0x8001B250 j */
L_8001B258:;
    R[31] = lw_(R[29] + 92);  /* 0x8001B258 */
    R[30] = lw_(R[29] + 88);  /* 0x8001B25C */
    R[23] = lw_(R[29] + 84);  /* 0x8001B260 */
    R[22] = lw_(R[29] + 80);  /* 0x8001B264 */
    R[21] = lw_(R[29] + 76);  /* 0x8001B268 */
    R[20] = lw_(R[29] + 72);  /* 0x8001B26C */
    R[19] = lw_(R[29] + 68);  /* 0x8001B270 */
    R[18] = lw_(R[29] + 64);  /* 0x8001B274 */
    R[17] = lw_(R[29] + 60);  /* 0x8001B278 */
    R[16] = lw_(R[29] + 56);  /* 0x8001B27C */
    { R[29] = R[29] + 96; psx_next = R[31]; return; }  /* 0x8001B280 jr ra */
}

void f_8001B114(void) {
L_8001B114:;
    { R[31] = 0x8001B11Cu; R[5] = R[22] + R[0]; psx_next = 0x8001AD68u; return; }  /* 0x8001B114 jal */
    R[19] = R[0] - 1;  /* 0x8001B11C */
    { uint32_t _c = (R[18] != R[19]); R[17] = R[2] + R[0]; if (_c) { goto L_8001B12C; } }  /* 0x8001B120 */
    R[18] = lw_(R[17] + 4);  /* 0x8001B128 */
L_8001B12C:;
    R[4] = R[17] + R[0];  /* 0x8001B12C */
    R[20] = R[18] + R[0];  /* 0x8001B130 */
    { R[31] = 0x8001B13Cu; R[16] = R[21] >> 11; psx_next = 0x80041B2Cu; return; }  /* 0x8001B134 jal */
    R[4] = R[2] + R[16];  /* 0x8001B13C */
    { R[31] = 0x8001B148u; R[5] = R[17] + R[0]; psx_next = 0x80041A28u; return; }  /* 0x8001B140 jal */
    R[4] = R[0] + 160;  /* 0x8001B148 */
    R[5] = R[17] + R[0];  /* 0x8001B14C */
    R[6] = R[0] + 6;  /* 0x8001B150 */
    R[2] = 0x8006u << 16;  /* 0x8001B154 */
    sh_(R[2] + -10048, R[0]);  /* 0x8001B158 */
    R[2] = R[2] - 10048;  /* 0x8001B15C */
    R[3] = R[21] & 0x7FF;  /* 0x8001B160 */
    R[7] = 0x8002u << 16;  /* 0x8001B164 */
    R[7] = R[7] - 20328;  /* 0x8001B168 */
    sw_(R[2] + 4, R[23]);  /* 0x8001B16C */
    sw_(R[2] + 8, R[3]);  /* 0x8001B170 */
    sw_(R[2] + 12, R[20]);  /* 0x8001B174 */
    { R[31] = 0x8001B180u; sw_(R[29] + 16, R[19]); psx_next = 0x8003E6CCu; return; }  /* 0x8001B178 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B234; } }  /* 0x8001B180 */
    { R[31] = 0x8001B190u; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B188 jal */
    R[16] = R[0] + 5;  /* 0x8001B190 */
L_8001B194:;
    { R[31] = 0x8001B19Cu; psx_next = 0x8003EDE0u; return; }  /* 0x8001B194 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B19C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B1C0; } }  /* 0x8001B1A0 */
    { R[31] = 0x8001B1B0u; R[5] = R[29] + 48; psx_next = 0x8003EA70u; return; }  /* 0x8001B1A8 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B234; } }  /* 0x8001B1B0 */
    { psx_bb(); goto L_8001B194; }  /* 0x8001B1B8 j */
L_8001B1C0:;
    R[2] = R[0] + 1;  /* 0x8001B1C0 */
    { uint32_t _c = (R[30] != R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8001B1D4; } }  /* 0x8001B1C4 */
    { R[2] = R[0] + R[0]; goto L_8001B258; }  /* 0x8001B1CC j */
L_8001B1D4:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1D4 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B214; } }  /* 0x8001B1DC */
    R[4] = R[0] + 2;  /* 0x8001B1E4 */
L_8001B1E8:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1E8 */
    R[2] = R[2] << 16;  /* 0x8001B1F0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B1F4 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B230; } }  /* 0x8001B1F8 */
    R[2] = lh_(R[3] + -10048);  /* 0x8001B200 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B1E8; } }  /* 0x8001B208 */
    R[4] = R[0] + 9;  /* 0x8001B210 */
L_8001B214:;
    R[5] = R[0] + R[0];  /* 0x8001B214 */
    { R[31] = 0x8001B220u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B218 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B214; } }  /* 0x8001B220 */
    { R[2] = R[20] + R[0]; goto L_8001B258; }  /* 0x8001B228 j */
L_8001B230:;
    R[4] = R[0] + 9;  /* 0x8001B230 */
L_8001B234:;
    R[5] = R[0] + R[0];  /* 0x8001B234 */
    { R[31] = 0x8001B240u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B238 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B234; } }  /* 0x8001B240 */
    { R[31] = 0x8001B250u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B248 jal */
    { R[4] = R[29] + 24; psx_bb(); goto L_8001B114; }  /* 0x8001B250 j */
L_8001B258:;
    R[31] = lw_(R[29] + 92);  /* 0x8001B258 */
    R[30] = lw_(R[29] + 88);  /* 0x8001B25C */
    R[23] = lw_(R[29] + 84);  /* 0x8001B260 */
    R[22] = lw_(R[29] + 80);  /* 0x8001B264 */
    R[21] = lw_(R[29] + 76);  /* 0x8001B268 */
    R[20] = lw_(R[29] + 72);  /* 0x8001B26C */
    R[19] = lw_(R[29] + 68);  /* 0x8001B270 */
    R[18] = lw_(R[29] + 64);  /* 0x8001B274 */
    R[17] = lw_(R[29] + 60);  /* 0x8001B278 */
    R[16] = lw_(R[29] + 56);  /* 0x8001B27C */
    { R[29] = R[29] + 96; psx_next = R[31]; return; }  /* 0x8001B280 jr ra */
}

void f_8001B11C(void) {
    R[19] = R[0] - 1;  /* 0x8001B11C */
    { uint32_t _c = (R[18] != R[19]); R[17] = R[2] + R[0]; if (_c) { goto L_8001B12C; } }  /* 0x8001B120 */
    R[18] = lw_(R[17] + 4);  /* 0x8001B128 */
L_8001B12C:;
    R[4] = R[17] + R[0];  /* 0x8001B12C */
    R[20] = R[18] + R[0];  /* 0x8001B130 */
    { R[31] = 0x8001B13Cu; R[16] = R[21] >> 11; psx_next = 0x80041B2Cu; return; }  /* 0x8001B134 jal */
    R[4] = R[2] + R[16];  /* 0x8001B13C */
    { R[31] = 0x8001B148u; R[5] = R[17] + R[0]; psx_next = 0x80041A28u; return; }  /* 0x8001B140 jal */
    R[4] = R[0] + 160;  /* 0x8001B148 */
    R[5] = R[17] + R[0];  /* 0x8001B14C */
    R[6] = R[0] + 6;  /* 0x8001B150 */
    R[2] = 0x8006u << 16;  /* 0x8001B154 */
    sh_(R[2] + -10048, R[0]);  /* 0x8001B158 */
    R[2] = R[2] - 10048;  /* 0x8001B15C */
    R[3] = R[21] & 0x7FF;  /* 0x8001B160 */
    R[7] = 0x8002u << 16;  /* 0x8001B164 */
    R[7] = R[7] - 20328;  /* 0x8001B168 */
    sw_(R[2] + 4, R[23]);  /* 0x8001B16C */
    sw_(R[2] + 8, R[3]);  /* 0x8001B170 */
    sw_(R[2] + 12, R[20]);  /* 0x8001B174 */
    { R[31] = 0x8001B180u; sw_(R[29] + 16, R[19]); psx_next = 0x8003E6CCu; return; }  /* 0x8001B178 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B234; } }  /* 0x8001B180 */
    { R[31] = 0x8001B190u; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B188 jal */
    R[16] = R[0] + 5;  /* 0x8001B190 */
L_8001B194:;
    { R[31] = 0x8001B19Cu; psx_next = 0x8003EDE0u; return; }  /* 0x8001B194 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B19C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B1C0; } }  /* 0x8001B1A0 */
    { R[31] = 0x8001B1B0u; R[5] = R[29] + 48; psx_next = 0x8003EA70u; return; }  /* 0x8001B1A8 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B234; } }  /* 0x8001B1B0 */
    { psx_bb(); goto L_8001B194; }  /* 0x8001B1B8 j */
L_8001B1C0:;
    R[2] = R[0] + 1;  /* 0x8001B1C0 */
    { uint32_t _c = (R[30] != R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8001B1D4; } }  /* 0x8001B1C4 */
    { R[2] = R[0] + R[0]; goto L_8001B258; }  /* 0x8001B1CC j */
L_8001B1D4:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1D4 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B214; } }  /* 0x8001B1DC */
    R[4] = R[0] + 2;  /* 0x8001B1E4 */
L_8001B1E8:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1E8 */
    R[2] = R[2] << 16;  /* 0x8001B1F0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B1F4 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B230; } }  /* 0x8001B1F8 */
    R[2] = lh_(R[3] + -10048);  /* 0x8001B200 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B1E8; } }  /* 0x8001B208 */
    R[4] = R[0] + 9;  /* 0x8001B210 */
L_8001B214:;
    R[5] = R[0] + R[0];  /* 0x8001B214 */
    { R[31] = 0x8001B220u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B218 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B214; } }  /* 0x8001B220 */
    { R[2] = R[20] + R[0]; goto L_8001B258; }  /* 0x8001B228 j */
L_8001B230:;
    R[4] = R[0] + 9;  /* 0x8001B230 */
L_8001B234:;
    R[5] = R[0] + R[0];  /* 0x8001B234 */
    { R[31] = 0x8001B240u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B238 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B234; } }  /* 0x8001B240 */
    { R[31] = 0x8001B250u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B248 jal */
    { R[4] = R[29] + 24; psx_next = 0x8001B114u; return; }  /* 0x8001B250 j extern */
L_8001B258:;
    R[31] = lw_(R[29] + 92);  /* 0x8001B258 */
    R[30] = lw_(R[29] + 88);  /* 0x8001B25C */
    R[23] = lw_(R[29] + 84);  /* 0x8001B260 */
    R[22] = lw_(R[29] + 80);  /* 0x8001B264 */
    R[21] = lw_(R[29] + 76);  /* 0x8001B268 */
    R[20] = lw_(R[29] + 72);  /* 0x8001B26C */
    R[19] = lw_(R[29] + 68);  /* 0x8001B270 */
    R[18] = lw_(R[29] + 64);  /* 0x8001B274 */
    R[17] = lw_(R[29] + 60);  /* 0x8001B278 */
    R[16] = lw_(R[29] + 56);  /* 0x8001B27C */
    { R[29] = R[29] + 96; psx_next = R[31]; return; }  /* 0x8001B280 jr ra */
}

void f_8001B13C(void) {
    R[4] = R[2] + R[16];  /* 0x8001B13C */
    { R[31] = 0x8001B148u; R[5] = R[17] + R[0]; psx_next = 0x80041A28u; return; }  /* 0x8001B140 jal */
    R[4] = R[0] + 160;  /* 0x8001B148 */
    R[5] = R[17] + R[0];  /* 0x8001B14C */
    R[6] = R[0] + 6;  /* 0x8001B150 */
    R[2] = 0x8006u << 16;  /* 0x8001B154 */
    sh_(R[2] + -10048, R[0]);  /* 0x8001B158 */
    R[2] = R[2] - 10048;  /* 0x8001B15C */
    R[3] = R[21] & 0x7FF;  /* 0x8001B160 */
    R[7] = 0x8002u << 16;  /* 0x8001B164 */
    R[7] = R[7] - 20328;  /* 0x8001B168 */
    sw_(R[2] + 4, R[23]);  /* 0x8001B16C */
    sw_(R[2] + 8, R[3]);  /* 0x8001B170 */
    sw_(R[2] + 12, R[20]);  /* 0x8001B174 */
    { R[31] = 0x8001B180u; sw_(R[29] + 16, R[19]); psx_next = 0x8003E6CCu; return; }  /* 0x8001B178 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B234; } }  /* 0x8001B180 */
    { R[31] = 0x8001B190u; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B188 jal */
    R[16] = R[0] + 5;  /* 0x8001B190 */
L_8001B194:;
    { R[31] = 0x8001B19Cu; psx_next = 0x8003EDE0u; return; }  /* 0x8001B194 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B19C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B1C0; } }  /* 0x8001B1A0 */
    { R[31] = 0x8001B1B0u; R[5] = R[29] + 48; psx_next = 0x8003EA70u; return; }  /* 0x8001B1A8 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B234; } }  /* 0x8001B1B0 */
    { psx_bb(); goto L_8001B194; }  /* 0x8001B1B8 j */
L_8001B1C0:;
    R[2] = R[0] + 1;  /* 0x8001B1C0 */
    { uint32_t _c = (R[30] != R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8001B1D4; } }  /* 0x8001B1C4 */
    { R[2] = R[0] + R[0]; goto L_8001B258; }  /* 0x8001B1CC j */
L_8001B1D4:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1D4 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B214; } }  /* 0x8001B1DC */
    R[4] = R[0] + 2;  /* 0x8001B1E4 */
L_8001B1E8:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1E8 */
    R[2] = R[2] << 16;  /* 0x8001B1F0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B1F4 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B230; } }  /* 0x8001B1F8 */
    R[2] = lh_(R[3] + -10048);  /* 0x8001B200 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B1E8; } }  /* 0x8001B208 */
    R[4] = R[0] + 9;  /* 0x8001B210 */
L_8001B214:;
    R[5] = R[0] + R[0];  /* 0x8001B214 */
    { R[31] = 0x8001B220u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B218 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B214; } }  /* 0x8001B220 */
    { R[2] = R[20] + R[0]; goto L_8001B258; }  /* 0x8001B228 j */
L_8001B230:;
    R[4] = R[0] + 9;  /* 0x8001B230 */
L_8001B234:;
    R[5] = R[0] + R[0];  /* 0x8001B234 */
    { R[31] = 0x8001B240u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B238 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B234; } }  /* 0x8001B240 */
    { R[31] = 0x8001B250u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B248 jal */
    { R[4] = R[29] + 24; psx_next = 0x8001B114u; return; }  /* 0x8001B250 j extern */
L_8001B258:;
    R[31] = lw_(R[29] + 92);  /* 0x8001B258 */
    R[30] = lw_(R[29] + 88);  /* 0x8001B25C */
    R[23] = lw_(R[29] + 84);  /* 0x8001B260 */
    R[22] = lw_(R[29] + 80);  /* 0x8001B264 */
    R[21] = lw_(R[29] + 76);  /* 0x8001B268 */
    R[20] = lw_(R[29] + 72);  /* 0x8001B26C */
    R[19] = lw_(R[29] + 68);  /* 0x8001B270 */
    R[18] = lw_(R[29] + 64);  /* 0x8001B274 */
    R[17] = lw_(R[29] + 60);  /* 0x8001B278 */
    R[16] = lw_(R[29] + 56);  /* 0x8001B27C */
    { R[29] = R[29] + 96; psx_next = R[31]; return; }  /* 0x8001B280 jr ra */
}

void f_8001B148(void) {
    R[4] = R[0] + 160;  /* 0x8001B148 */
    R[5] = R[17] + R[0];  /* 0x8001B14C */
    R[6] = R[0] + 6;  /* 0x8001B150 */
    R[2] = 0x8006u << 16;  /* 0x8001B154 */
    sh_(R[2] + -10048, R[0]);  /* 0x8001B158 */
    R[2] = R[2] - 10048;  /* 0x8001B15C */
    R[3] = R[21] & 0x7FF;  /* 0x8001B160 */
    R[7] = 0x8002u << 16;  /* 0x8001B164 */
    R[7] = R[7] - 20328;  /* 0x8001B168 */
    sw_(R[2] + 4, R[23]);  /* 0x8001B16C */
    sw_(R[2] + 8, R[3]);  /* 0x8001B170 */
    sw_(R[2] + 12, R[20]);  /* 0x8001B174 */
    { R[31] = 0x8001B180u; sw_(R[29] + 16, R[19]); psx_next = 0x8003E6CCu; return; }  /* 0x8001B178 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B234; } }  /* 0x8001B180 */
    { R[31] = 0x8001B190u; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B188 jal */
    R[16] = R[0] + 5;  /* 0x8001B190 */
L_8001B194:;
    { R[31] = 0x8001B19Cu; psx_next = 0x8003EDE0u; return; }  /* 0x8001B194 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B19C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B1C0; } }  /* 0x8001B1A0 */
    { R[31] = 0x8001B1B0u; R[5] = R[29] + 48; psx_next = 0x8003EA70u; return; }  /* 0x8001B1A8 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B234; } }  /* 0x8001B1B0 */
    { psx_bb(); goto L_8001B194; }  /* 0x8001B1B8 j */
L_8001B1C0:;
    R[2] = R[0] + 1;  /* 0x8001B1C0 */
    { uint32_t _c = (R[30] != R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8001B1D4; } }  /* 0x8001B1C4 */
    { R[2] = R[0] + R[0]; goto L_8001B258; }  /* 0x8001B1CC j */
L_8001B1D4:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1D4 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B214; } }  /* 0x8001B1DC */
    R[4] = R[0] + 2;  /* 0x8001B1E4 */
L_8001B1E8:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1E8 */
    R[2] = R[2] << 16;  /* 0x8001B1F0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B1F4 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B230; } }  /* 0x8001B1F8 */
    R[2] = lh_(R[3] + -10048);  /* 0x8001B200 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B1E8; } }  /* 0x8001B208 */
    R[4] = R[0] + 9;  /* 0x8001B210 */
L_8001B214:;
    R[5] = R[0] + R[0];  /* 0x8001B214 */
    { R[31] = 0x8001B220u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B218 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B214; } }  /* 0x8001B220 */
    { R[2] = R[20] + R[0]; goto L_8001B258; }  /* 0x8001B228 j */
L_8001B230:;
    R[4] = R[0] + 9;  /* 0x8001B230 */
L_8001B234:;
    R[5] = R[0] + R[0];  /* 0x8001B234 */
    { R[31] = 0x8001B240u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B238 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B234; } }  /* 0x8001B240 */
    { R[31] = 0x8001B250u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B248 jal */
    { R[4] = R[29] + 24; psx_next = 0x8001B114u; return; }  /* 0x8001B250 j extern */
L_8001B258:;
    R[31] = lw_(R[29] + 92);  /* 0x8001B258 */
    R[30] = lw_(R[29] + 88);  /* 0x8001B25C */
    R[23] = lw_(R[29] + 84);  /* 0x8001B260 */
    R[22] = lw_(R[29] + 80);  /* 0x8001B264 */
    R[21] = lw_(R[29] + 76);  /* 0x8001B268 */
    R[20] = lw_(R[29] + 72);  /* 0x8001B26C */
    R[19] = lw_(R[29] + 68);  /* 0x8001B270 */
    R[18] = lw_(R[29] + 64);  /* 0x8001B274 */
    R[17] = lw_(R[29] + 60);  /* 0x8001B278 */
    R[16] = lw_(R[29] + 56);  /* 0x8001B27C */
    { R[29] = R[29] + 96; psx_next = R[31]; return; }  /* 0x8001B280 jr ra */
}

void f_8001B180(void) {
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B234; } }  /* 0x8001B180 */
    { R[31] = 0x8001B190u; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B188 jal */
    R[16] = R[0] + 5;  /* 0x8001B190 */
L_8001B194:;
    { R[31] = 0x8001B19Cu; psx_next = 0x8003EDE0u; return; }  /* 0x8001B194 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B19C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B1C0; } }  /* 0x8001B1A0 */
    { R[31] = 0x8001B1B0u; R[5] = R[29] + 48; psx_next = 0x8003EA70u; return; }  /* 0x8001B1A8 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B234; } }  /* 0x8001B1B0 */
    { psx_bb(); goto L_8001B194; }  /* 0x8001B1B8 j */
L_8001B1C0:;
    R[2] = R[0] + 1;  /* 0x8001B1C0 */
    { uint32_t _c = (R[30] != R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8001B1D4; } }  /* 0x8001B1C4 */
    { R[2] = R[0] + R[0]; goto L_8001B258; }  /* 0x8001B1CC j */
L_8001B1D4:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1D4 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B214; } }  /* 0x8001B1DC */
    R[4] = R[0] + 2;  /* 0x8001B1E4 */
L_8001B1E8:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1E8 */
    R[2] = R[2] << 16;  /* 0x8001B1F0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B1F4 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B230; } }  /* 0x8001B1F8 */
    R[2] = lh_(R[3] + -10048);  /* 0x8001B200 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B1E8; } }  /* 0x8001B208 */
    R[4] = R[0] + 9;  /* 0x8001B210 */
L_8001B214:;
    R[5] = R[0] + R[0];  /* 0x8001B214 */
    { R[31] = 0x8001B220u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B218 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B214; } }  /* 0x8001B220 */
    { R[2] = R[20] + R[0]; goto L_8001B258; }  /* 0x8001B228 j */
L_8001B230:;
    R[4] = R[0] + 9;  /* 0x8001B230 */
L_8001B234:;
    R[5] = R[0] + R[0];  /* 0x8001B234 */
    { R[31] = 0x8001B240u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B238 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B234; } }  /* 0x8001B240 */
    { R[31] = 0x8001B250u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B248 jal */
    { R[4] = R[29] + 24; psx_next = 0x8001B114u; return; }  /* 0x8001B250 j extern */
L_8001B258:;
    R[31] = lw_(R[29] + 92);  /* 0x8001B258 */
    R[30] = lw_(R[29] + 88);  /* 0x8001B25C */
    R[23] = lw_(R[29] + 84);  /* 0x8001B260 */
    R[22] = lw_(R[29] + 80);  /* 0x8001B264 */
    R[21] = lw_(R[29] + 76);  /* 0x8001B268 */
    R[20] = lw_(R[29] + 72);  /* 0x8001B26C */
    R[19] = lw_(R[29] + 68);  /* 0x8001B270 */
    R[18] = lw_(R[29] + 64);  /* 0x8001B274 */
    R[17] = lw_(R[29] + 60);  /* 0x8001B278 */
    R[16] = lw_(R[29] + 56);  /* 0x8001B27C */
    { R[29] = R[29] + 96; psx_next = R[31]; return; }  /* 0x8001B280 jr ra */
}

void f_8001B190(void) {
    R[16] = R[0] + 5;  /* 0x8001B190 */
L_8001B194:;
    { R[31] = 0x8001B19Cu; psx_next = 0x8003EDE0u; return; }  /* 0x8001B194 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B19C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B1C0; } }  /* 0x8001B1A0 */
    { R[31] = 0x8001B1B0u; R[5] = R[29] + 48; psx_next = 0x8003EA70u; return; }  /* 0x8001B1A8 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B234; } }  /* 0x8001B1B0 */
    { psx_bb(); goto L_8001B194; }  /* 0x8001B1B8 j */
L_8001B1C0:;
    R[2] = R[0] + 1;  /* 0x8001B1C0 */
    { uint32_t _c = (R[30] != R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8001B1D4; } }  /* 0x8001B1C4 */
    { R[2] = R[0] + R[0]; goto L_8001B258; }  /* 0x8001B1CC j */
L_8001B1D4:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1D4 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B214; } }  /* 0x8001B1DC */
    R[4] = R[0] + 2;  /* 0x8001B1E4 */
L_8001B1E8:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1E8 */
    R[2] = R[2] << 16;  /* 0x8001B1F0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B1F4 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B230; } }  /* 0x8001B1F8 */
    R[2] = lh_(R[3] + -10048);  /* 0x8001B200 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B1E8; } }  /* 0x8001B208 */
    R[4] = R[0] + 9;  /* 0x8001B210 */
L_8001B214:;
    R[5] = R[0] + R[0];  /* 0x8001B214 */
    { R[31] = 0x8001B220u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B218 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B214; } }  /* 0x8001B220 */
    { R[2] = R[20] + R[0]; goto L_8001B258; }  /* 0x8001B228 j */
L_8001B230:;
    R[4] = R[0] + 9;  /* 0x8001B230 */
L_8001B234:;
    R[5] = R[0] + R[0];  /* 0x8001B234 */
    { R[31] = 0x8001B240u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B238 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B234; } }  /* 0x8001B240 */
    { R[31] = 0x8001B250u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B248 jal */
    { R[4] = R[29] + 24; psx_next = 0x8001B114u; return; }  /* 0x8001B250 j extern */
L_8001B258:;
    R[31] = lw_(R[29] + 92);  /* 0x8001B258 */
    R[30] = lw_(R[29] + 88);  /* 0x8001B25C */
    R[23] = lw_(R[29] + 84);  /* 0x8001B260 */
    R[22] = lw_(R[29] + 80);  /* 0x8001B264 */
    R[21] = lw_(R[29] + 76);  /* 0x8001B268 */
    R[20] = lw_(R[29] + 72);  /* 0x8001B26C */
    R[19] = lw_(R[29] + 68);  /* 0x8001B270 */
    R[18] = lw_(R[29] + 64);  /* 0x8001B274 */
    R[17] = lw_(R[29] + 60);  /* 0x8001B278 */
    R[16] = lw_(R[29] + 56);  /* 0x8001B27C */
    { R[29] = R[29] + 96; psx_next = R[31]; return; }  /* 0x8001B280 jr ra */
}

void f_8001B194(void) {
L_8001B194:;
    { R[31] = 0x8001B19Cu; psx_next = 0x8003EDE0u; return; }  /* 0x8001B194 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B19C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B1C0; } }  /* 0x8001B1A0 */
    { R[31] = 0x8001B1B0u; R[5] = R[29] + 48; psx_next = 0x8003EA70u; return; }  /* 0x8001B1A8 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B234; } }  /* 0x8001B1B0 */
    { psx_bb(); goto L_8001B194; }  /* 0x8001B1B8 j */
L_8001B1C0:;
    R[2] = R[0] + 1;  /* 0x8001B1C0 */
    { uint32_t _c = (R[30] != R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8001B1D4; } }  /* 0x8001B1C4 */
    { R[2] = R[0] + R[0]; goto L_8001B258; }  /* 0x8001B1CC j */
L_8001B1D4:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1D4 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B214; } }  /* 0x8001B1DC */
    R[4] = R[0] + 2;  /* 0x8001B1E4 */
L_8001B1E8:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1E8 */
    R[2] = R[2] << 16;  /* 0x8001B1F0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B1F4 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B230; } }  /* 0x8001B1F8 */
    R[2] = lh_(R[3] + -10048);  /* 0x8001B200 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B1E8; } }  /* 0x8001B208 */
    R[4] = R[0] + 9;  /* 0x8001B210 */
L_8001B214:;
    R[5] = R[0] + R[0];  /* 0x8001B214 */
    { R[31] = 0x8001B220u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B218 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B214; } }  /* 0x8001B220 */
    { R[2] = R[20] + R[0]; goto L_8001B258; }  /* 0x8001B228 j */
L_8001B230:;
    R[4] = R[0] + 9;  /* 0x8001B230 */
L_8001B234:;
    R[5] = R[0] + R[0];  /* 0x8001B234 */
    { R[31] = 0x8001B240u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B238 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B234; } }  /* 0x8001B240 */
    { R[31] = 0x8001B250u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B248 jal */
    { R[4] = R[29] + 24; psx_next = 0x8001B114u; return; }  /* 0x8001B250 j extern */
L_8001B258:;
    R[31] = lw_(R[29] + 92);  /* 0x8001B258 */
    R[30] = lw_(R[29] + 88);  /* 0x8001B25C */
    R[23] = lw_(R[29] + 84);  /* 0x8001B260 */
    R[22] = lw_(R[29] + 80);  /* 0x8001B264 */
    R[21] = lw_(R[29] + 76);  /* 0x8001B268 */
    R[20] = lw_(R[29] + 72);  /* 0x8001B26C */
    R[19] = lw_(R[29] + 68);  /* 0x8001B270 */
    R[18] = lw_(R[29] + 64);  /* 0x8001B274 */
    R[17] = lw_(R[29] + 60);  /* 0x8001B278 */
    R[16] = lw_(R[29] + 56);  /* 0x8001B27C */
    { R[29] = R[29] + 96; psx_next = R[31]; return; }  /* 0x8001B280 jr ra */
}

void f_8001B19C(void) {
    R[2] = R[2] & 0x20;  /* 0x8001B19C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B1C0; } }  /* 0x8001B1A0 */
    { R[31] = 0x8001B1B0u; R[5] = R[29] + 48; psx_next = 0x8003EA70u; return; }  /* 0x8001B1A8 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B234; } }  /* 0x8001B1B0 */
    { psx_next = 0x8001B194u; return; }  /* 0x8001B1B8 j extern */
L_8001B1C0:;
    R[2] = R[0] + 1;  /* 0x8001B1C0 */
    { uint32_t _c = (R[30] != R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8001B1D4; } }  /* 0x8001B1C4 */
    { R[2] = R[0] + R[0]; goto L_8001B258; }  /* 0x8001B1CC j */
L_8001B1D4:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1D4 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B214; } }  /* 0x8001B1DC */
    R[4] = R[0] + 2;  /* 0x8001B1E4 */
L_8001B1E8:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1E8 */
    R[2] = R[2] << 16;  /* 0x8001B1F0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B1F4 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B230; } }  /* 0x8001B1F8 */
    R[2] = lh_(R[3] + -10048);  /* 0x8001B200 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B1E8; } }  /* 0x8001B208 */
    R[4] = R[0] + 9;  /* 0x8001B210 */
L_8001B214:;
    R[5] = R[0] + R[0];  /* 0x8001B214 */
    { R[31] = 0x8001B220u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B218 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B214; } }  /* 0x8001B220 */
    { R[2] = R[20] + R[0]; goto L_8001B258; }  /* 0x8001B228 j */
L_8001B230:;
    R[4] = R[0] + 9;  /* 0x8001B230 */
L_8001B234:;
    R[5] = R[0] + R[0];  /* 0x8001B234 */
    { R[31] = 0x8001B240u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B238 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B234; } }  /* 0x8001B240 */
    { R[31] = 0x8001B250u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B248 jal */
    { R[4] = R[29] + 24; psx_next = 0x8001B114u; return; }  /* 0x8001B250 j extern */
L_8001B258:;
    R[31] = lw_(R[29] + 92);  /* 0x8001B258 */
    R[30] = lw_(R[29] + 88);  /* 0x8001B25C */
    R[23] = lw_(R[29] + 84);  /* 0x8001B260 */
    R[22] = lw_(R[29] + 80);  /* 0x8001B264 */
    R[21] = lw_(R[29] + 76);  /* 0x8001B268 */
    R[20] = lw_(R[29] + 72);  /* 0x8001B26C */
    R[19] = lw_(R[29] + 68);  /* 0x8001B270 */
    R[18] = lw_(R[29] + 64);  /* 0x8001B274 */
    R[17] = lw_(R[29] + 60);  /* 0x8001B278 */
    R[16] = lw_(R[29] + 56);  /* 0x8001B27C */
    { R[29] = R[29] + 96; psx_next = R[31]; return; }  /* 0x8001B280 jr ra */
}

void f_8001B1B0(void) {
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B234; } }  /* 0x8001B1B0 */
    { psx_next = 0x8001B194u; return; }  /* 0x8001B1B8 j extern */
    R[2] = R[0] + 1;  /* 0x8001B1C0 */
    { uint32_t _c = (R[30] != R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8001B1D4; } }  /* 0x8001B1C4 */
    { R[2] = R[0] + R[0]; goto L_8001B258; }  /* 0x8001B1CC j */
L_8001B1D4:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1D4 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B214; } }  /* 0x8001B1DC */
    R[4] = R[0] + 2;  /* 0x8001B1E4 */
L_8001B1E8:;
    R[2] = lh_(R[3] + -10048);  /* 0x8001B1E8 */
    R[2] = R[2] << 16;  /* 0x8001B1F0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B1F4 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B230; } }  /* 0x8001B1F8 */
    R[2] = lh_(R[3] + -10048);  /* 0x8001B200 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B1E8; } }  /* 0x8001B208 */
    R[4] = R[0] + 9;  /* 0x8001B210 */
L_8001B214:;
    R[5] = R[0] + R[0];  /* 0x8001B214 */
    { R[31] = 0x8001B220u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B218 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B214; } }  /* 0x8001B220 */
    { R[2] = R[20] + R[0]; goto L_8001B258; }  /* 0x8001B228 j */
L_8001B230:;
    R[4] = R[0] + 9;  /* 0x8001B230 */
L_8001B234:;
    R[5] = R[0] + R[0];  /* 0x8001B234 */
    { R[31] = 0x8001B240u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B238 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B234; } }  /* 0x8001B240 */
    { R[31] = 0x8001B250u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B248 jal */
    { R[4] = R[29] + 24; psx_next = 0x8001B114u; return; }  /* 0x8001B250 j extern */
L_8001B258:;
    R[31] = lw_(R[29] + 92);  /* 0x8001B258 */
    R[30] = lw_(R[29] + 88);  /* 0x8001B25C */
    R[23] = lw_(R[29] + 84);  /* 0x8001B260 */
    R[22] = lw_(R[29] + 80);  /* 0x8001B264 */
    R[21] = lw_(R[29] + 76);  /* 0x8001B268 */
    R[20] = lw_(R[29] + 72);  /* 0x8001B26C */
    R[19] = lw_(R[29] + 68);  /* 0x8001B270 */
    R[18] = lw_(R[29] + 64);  /* 0x8001B274 */
    R[17] = lw_(R[29] + 60);  /* 0x8001B278 */
    R[16] = lw_(R[29] + 56);  /* 0x8001B27C */
    { R[29] = R[29] + 96; psx_next = R[31]; return; }  /* 0x8001B280 jr ra */
}

void f_8001B214(void) {
L_8001B214:;
    R[5] = R[0] + R[0];  /* 0x8001B214 */
    { R[31] = 0x8001B220u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B218 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B214; } }  /* 0x8001B220 */
    { R[2] = R[20] + R[0]; goto L_8001B258; }  /* 0x8001B228 j */
    R[4] = R[0] + 9;  /* 0x8001B230 */
L_8001B234:;
    R[5] = R[0] + R[0];  /* 0x8001B234 */
    { R[31] = 0x8001B240u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B238 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B234; } }  /* 0x8001B240 */
    { R[31] = 0x8001B250u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B248 jal */
    { R[4] = R[29] + 24; psx_next = 0x8001B114u; return; }  /* 0x8001B250 j extern */
L_8001B258:;
    R[31] = lw_(R[29] + 92);  /* 0x8001B258 */
    R[30] = lw_(R[29] + 88);  /* 0x8001B25C */
    R[23] = lw_(R[29] + 84);  /* 0x8001B260 */
    R[22] = lw_(R[29] + 80);  /* 0x8001B264 */
    R[21] = lw_(R[29] + 76);  /* 0x8001B268 */
    R[20] = lw_(R[29] + 72);  /* 0x8001B26C */
    R[19] = lw_(R[29] + 68);  /* 0x8001B270 */
    R[18] = lw_(R[29] + 64);  /* 0x8001B274 */
    R[17] = lw_(R[29] + 60);  /* 0x8001B278 */
    R[16] = lw_(R[29] + 56);  /* 0x8001B27C */
    { R[29] = R[29] + 96; psx_next = R[31]; return; }  /* 0x8001B280 jr ra */
}

void f_8001B220(void) {
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_next = 0x8001B214u; return; } }  /* 0x8001B220 b extern */
    { R[2] = R[20] + R[0]; goto L_8001B258; }  /* 0x8001B228 j */
    R[4] = R[0] + 9;  /* 0x8001B230 */
L_8001B234:;
    R[5] = R[0] + R[0];  /* 0x8001B234 */
    { R[31] = 0x8001B240u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B238 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B234; } }  /* 0x8001B240 */
    { R[31] = 0x8001B250u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B248 jal */
    { R[4] = R[29] + 24; psx_next = 0x8001B114u; return; }  /* 0x8001B250 j extern */
L_8001B258:;
    R[31] = lw_(R[29] + 92);  /* 0x8001B258 */
    R[30] = lw_(R[29] + 88);  /* 0x8001B25C */
    R[23] = lw_(R[29] + 84);  /* 0x8001B260 */
    R[22] = lw_(R[29] + 80);  /* 0x8001B264 */
    R[21] = lw_(R[29] + 76);  /* 0x8001B268 */
    R[20] = lw_(R[29] + 72);  /* 0x8001B26C */
    R[19] = lw_(R[29] + 68);  /* 0x8001B270 */
    R[18] = lw_(R[29] + 64);  /* 0x8001B274 */
    R[17] = lw_(R[29] + 60);  /* 0x8001B278 */
    R[16] = lw_(R[29] + 56);  /* 0x8001B27C */
    { R[29] = R[29] + 96; psx_next = R[31]; return; }  /* 0x8001B280 jr ra */
}

void f_8001B234(void) {
L_8001B234:;
    R[5] = R[0] + R[0];  /* 0x8001B234 */
    { R[31] = 0x8001B240u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B238 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B234; } }  /* 0x8001B240 */
    { R[31] = 0x8001B250u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B248 jal */
    { R[4] = R[29] + 24; psx_next = 0x8001B114u; return; }  /* 0x8001B250 j extern */
    R[31] = lw_(R[29] + 92);  /* 0x8001B258 */
    R[30] = lw_(R[29] + 88);  /* 0x8001B25C */
    R[23] = lw_(R[29] + 84);  /* 0x8001B260 */
    R[22] = lw_(R[29] + 80);  /* 0x8001B264 */
    R[21] = lw_(R[29] + 76);  /* 0x8001B268 */
    R[20] = lw_(R[29] + 72);  /* 0x8001B26C */
    R[19] = lw_(R[29] + 68);  /* 0x8001B270 */
    R[18] = lw_(R[29] + 64);  /* 0x8001B274 */
    R[17] = lw_(R[29] + 60);  /* 0x8001B278 */
    R[16] = lw_(R[29] + 56);  /* 0x8001B27C */
    { R[29] = R[29] + 96; psx_next = R[31]; return; }  /* 0x8001B280 jr ra */
}

void f_8001B240(void) {
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_next = 0x8001B234u; return; } }  /* 0x8001B240 b extern */
    { R[31] = 0x8001B250u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B248 jal */
    { R[4] = R[29] + 24; psx_next = 0x8001B114u; return; }  /* 0x8001B250 j extern */
    R[31] = lw_(R[29] + 92);  /* 0x8001B258 */
    R[30] = lw_(R[29] + 88);  /* 0x8001B25C */
    R[23] = lw_(R[29] + 84);  /* 0x8001B260 */
    R[22] = lw_(R[29] + 80);  /* 0x8001B264 */
    R[21] = lw_(R[29] + 76);  /* 0x8001B268 */
    R[20] = lw_(R[29] + 72);  /* 0x8001B26C */
    R[19] = lw_(R[29] + 68);  /* 0x8001B270 */
    R[18] = lw_(R[29] + 64);  /* 0x8001B274 */
    R[17] = lw_(R[29] + 60);  /* 0x8001B278 */
    R[16] = lw_(R[29] + 56);  /* 0x8001B27C */
    { R[29] = R[29] + 96; psx_next = R[31]; return; }  /* 0x8001B280 jr ra */
}

void f_8001B250(void) {
    { R[4] = R[29] + 24; psx_next = 0x8001B114u; return; }  /* 0x8001B250 j extern */
    R[31] = lw_(R[29] + 92);  /* 0x8001B258 */
    R[30] = lw_(R[29] + 88);  /* 0x8001B25C */
    R[23] = lw_(R[29] + 84);  /* 0x8001B260 */
    R[22] = lw_(R[29] + 80);  /* 0x8001B264 */
    R[21] = lw_(R[29] + 76);  /* 0x8001B268 */
    R[20] = lw_(R[29] + 72);  /* 0x8001B26C */
    R[19] = lw_(R[29] + 68);  /* 0x8001B270 */
    R[18] = lw_(R[29] + 64);  /* 0x8001B274 */
    R[17] = lw_(R[29] + 60);  /* 0x8001B278 */
    R[16] = lw_(R[29] + 56);  /* 0x8001B27C */
    { R[29] = R[29] + 96; psx_next = R[31]; return; }  /* 0x8001B280 jr ra */
}

void f_8001B288(void) {
    { psx_next = R[31]; return; }  /* 0x8001B288 jr ra */
    { psx_next = R[31]; return; }  /* 0x8001B290 jr ra */
}

void f_8001B298(void) {
    R[29] = R[29] - 64;  /* 0x8001B298 */
    sw_(R[29] + 52, R[17]);  /* 0x8001B29C */
    R[17] = R[4] + R[0];  /* 0x8001B2A0 */
    sw_(R[29] + 48, R[16]);  /* 0x8001B2A4 */
    sw_(R[29] + 56, R[31]);  /* 0x8001B2A8 */
    { R[31] = 0x8001B2B4u; R[16] = R[5] + R[0]; psx_next = 0x8002FAA4u; return; }  /* 0x8001B2AC jal */
    R[4] = R[29] + 24;  /* 0x8001B2B4 */
    { R[31] = 0x8001B2C0u; R[5] = R[17] + R[0]; psx_next = 0x8001AD68u; return; }  /* 0x8001B2B8 jal */
    R[17] = R[2] + R[0];  /* 0x8001B2C0 */
    R[4] = R[17] + R[0];  /* 0x8001B2C4 */
    { R[31] = 0x8001B2D0u; R[16] = R[16] >> 11; psx_next = 0x80041B2Cu; return; }  /* 0x8001B2C8 jal */
    R[4] = R[2] + R[16];  /* 0x8001B2D0 */
    { R[31] = 0x8001B2DCu; R[5] = R[17] + R[0]; psx_next = 0x80041A28u; return; }  /* 0x8001B2D4 jal */
    R[2] = R[0] - 1;  /* 0x8001B2DC */
    R[4] = R[0] + 160;  /* 0x8001B2E0 */
    R[5] = R[17] + R[0];  /* 0x8001B2E4 */
    R[6] = R[0] + 21;  /* 0x8001B2E8 */
    R[7] = R[0] + R[0];  /* 0x8001B2EC */
    { R[31] = 0x8001B2F8u; sw_(R[29] + 16, R[2]); psx_next = 0x8003E6CCu; return; }  /* 0x8001B2F0 jal */
    R[31] = lw_(R[29] + 56);  /* 0x8001B2F8 */
    R[17] = lw_(R[29] + 52);  /* 0x8001B2FC */
    R[16] = lw_(R[29] + 48);  /* 0x8001B300 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8001B304 jr ra */
}

void f_8001B2B4(void) {
    R[4] = R[29] + 24;  /* 0x8001B2B4 */
    { R[31] = 0x8001B2C0u; R[5] = R[17] + R[0]; psx_next = 0x8001AD68u; return; }  /* 0x8001B2B8 jal */
    R[17] = R[2] + R[0];  /* 0x8001B2C0 */
    R[4] = R[17] + R[0];  /* 0x8001B2C4 */
    { R[31] = 0x8001B2D0u; R[16] = R[16] >> 11; psx_next = 0x80041B2Cu; return; }  /* 0x8001B2C8 jal */
    R[4] = R[2] + R[16];  /* 0x8001B2D0 */
    { R[31] = 0x8001B2DCu; R[5] = R[17] + R[0]; psx_next = 0x80041A28u; return; }  /* 0x8001B2D4 jal */
    R[2] = R[0] - 1;  /* 0x8001B2DC */
    R[4] = R[0] + 160;  /* 0x8001B2E0 */
    R[5] = R[17] + R[0];  /* 0x8001B2E4 */
    R[6] = R[0] + 21;  /* 0x8001B2E8 */
    R[7] = R[0] + R[0];  /* 0x8001B2EC */
    { R[31] = 0x8001B2F8u; sw_(R[29] + 16, R[2]); psx_next = 0x8003E6CCu; return; }  /* 0x8001B2F0 jal */
    R[31] = lw_(R[29] + 56);  /* 0x8001B2F8 */
    R[17] = lw_(R[29] + 52);  /* 0x8001B2FC */
    R[16] = lw_(R[29] + 48);  /* 0x8001B300 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8001B304 jr ra */
}

void f_8001B2C0(void) {
    R[17] = R[2] + R[0];  /* 0x8001B2C0 */
    R[4] = R[17] + R[0];  /* 0x8001B2C4 */
    { R[31] = 0x8001B2D0u; R[16] = R[16] >> 11; psx_next = 0x80041B2Cu; return; }  /* 0x8001B2C8 jal */
    R[4] = R[2] + R[16];  /* 0x8001B2D0 */
    { R[31] = 0x8001B2DCu; R[5] = R[17] + R[0]; psx_next = 0x80041A28u; return; }  /* 0x8001B2D4 jal */
    R[2] = R[0] - 1;  /* 0x8001B2DC */
    R[4] = R[0] + 160;  /* 0x8001B2E0 */
    R[5] = R[17] + R[0];  /* 0x8001B2E4 */
    R[6] = R[0] + 21;  /* 0x8001B2E8 */
    R[7] = R[0] + R[0];  /* 0x8001B2EC */
    { R[31] = 0x8001B2F8u; sw_(R[29] + 16, R[2]); psx_next = 0x8003E6CCu; return; }  /* 0x8001B2F0 jal */
    R[31] = lw_(R[29] + 56);  /* 0x8001B2F8 */
    R[17] = lw_(R[29] + 52);  /* 0x8001B2FC */
    R[16] = lw_(R[29] + 48);  /* 0x8001B300 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8001B304 jr ra */
}

void f_8001B2D0(void) {
    R[4] = R[2] + R[16];  /* 0x8001B2D0 */
    { R[31] = 0x8001B2DCu; R[5] = R[17] + R[0]; psx_next = 0x80041A28u; return; }  /* 0x8001B2D4 jal */
    R[2] = R[0] - 1;  /* 0x8001B2DC */
    R[4] = R[0] + 160;  /* 0x8001B2E0 */
    R[5] = R[17] + R[0];  /* 0x8001B2E4 */
    R[6] = R[0] + 21;  /* 0x8001B2E8 */
    R[7] = R[0] + R[0];  /* 0x8001B2EC */
    { R[31] = 0x8001B2F8u; sw_(R[29] + 16, R[2]); psx_next = 0x8003E6CCu; return; }  /* 0x8001B2F0 jal */
    R[31] = lw_(R[29] + 56);  /* 0x8001B2F8 */
    R[17] = lw_(R[29] + 52);  /* 0x8001B2FC */
    R[16] = lw_(R[29] + 48);  /* 0x8001B300 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8001B304 jr ra */
}

void f_8001B2DC(void) {
    R[2] = R[0] - 1;  /* 0x8001B2DC */
    R[4] = R[0] + 160;  /* 0x8001B2E0 */
    R[5] = R[17] + R[0];  /* 0x8001B2E4 */
    R[6] = R[0] + 21;  /* 0x8001B2E8 */
    R[7] = R[0] + R[0];  /* 0x8001B2EC */
    { R[31] = 0x8001B2F8u; sw_(R[29] + 16, R[2]); psx_next = 0x8003E6CCu; return; }  /* 0x8001B2F0 jal */
    R[31] = lw_(R[29] + 56);  /* 0x8001B2F8 */
    R[17] = lw_(R[29] + 52);  /* 0x8001B2FC */
    R[16] = lw_(R[29] + 48);  /* 0x8001B300 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8001B304 jr ra */
}

void f_8001B2F8(void) {
    R[31] = lw_(R[29] + 56);  /* 0x8001B2F8 */
    R[17] = lw_(R[29] + 52);  /* 0x8001B2FC */
    R[16] = lw_(R[29] + 48);  /* 0x8001B300 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8001B304 jr ra */
}

void f_8001B30C(void) {
    R[8] = R[4] + R[0];  /* 0x8001B30C */
    R[2] = 0x8006u << 16;  /* 0x8001B310 */
    R[7] = R[2] - 10024;  /* 0x8001B314 */
    R[3] = R[7] + 12;  /* 0x8001B318 */
    R[2] = lh_(R[7] + 2);  /* 0x8001B31C */
    R[4] = lh_(R[7] + 2);  /* 0x8001B320 */
    R[2] = R[2] << 16;  /* 0x8001B324 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8001B328 */
    { uint32_t _c = (R[4] != R[0]); R[3] = R[2] + R[3]; if (_c) { goto L_8001B338; } }  /* 0x8001B32C */
    sw_(R[7] + 8, R[5]);  /* 0x8001B334 */
L_8001B338:;
    R[2] = R[5] & 0x7FF;  /* 0x8001B338 */
    sh_(R[3], R[0]);  /* 0x8001B33C */
    sw_(R[3] + 4, R[8]);  /* 0x8001B340 */
    sw_(R[3] + 8, R[2]);  /* 0x8001B344 */
    sw_(R[3] + 12, R[6]);  /* 0x8001B348 */
    R[2] = lh_(R[7] + 2);  /* 0x8001B34C */
    R[2] = R[2] + 1;  /* 0x8001B354 */
    sh_(R[7] + 2, R[2]);  /* 0x8001B358 */
    { psx_next = R[31]; return; }  /* 0x8001B35C jr ra */
}

void f_8001B364(void) {
    R[29] = R[29] - 24;  /* 0x8001B364 */
    R[4] = ((int32_t)R[4] < 2049);  /* 0x8001B368 */
    { uint32_t _c = (R[4] == R[0]); sw_(R[29] + 16, R[31]); if (_c) { goto L_8001B3B0; } }  /* 0x8001B36C */
    R[2] = 0x8006u << 16;  /* 0x8001B374 */
    R[3] = lh_(R[2] + -10024);  /* 0x8001B378 */
    R[2] = R[2] - 10024;  /* 0x8001B37C */
    R[2] = lh_(R[2] + 2);  /* 0x8001B380 */
    R[3] = R[3] << 16;  /* 0x8001B384 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x8001B388 */
    R[3] = R[3] + 1;  /* 0x8001B38C */
    R[2] = R[2] << 16;  /* 0x8001B390 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B394 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8001B3B4; } }  /* 0x8001B398 */
    { R[31] = 0x8001B3A8u; psx_next = 0x80042C0Cu; return; }  /* 0x8001B3A0 jal */
    { R[2] = R[0] + 1; goto L_8001B3B4; }  /* 0x8001B3A8 j */
L_8001B3B0:;
    R[2] = R[0] + R[0];  /* 0x8001B3B0 */
L_8001B3B4:;
    R[31] = lw_(R[29] + 16);  /* 0x8001B3B4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001B3BC jr ra */
}

void f_8001B3A8(void) {
    { R[2] = R[0] + 1; goto L_8001B3B4; }  /* 0x8001B3A8 j */
    R[2] = R[0] + R[0];  /* 0x8001B3B0 */
L_8001B3B4:;
    R[31] = lw_(R[29] + 16);  /* 0x8001B3B4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001B3BC jr ra */
}

void f_8001B3C4(void) {
    R[29] = R[29] - 40;  /* 0x8001B3C4 */
    sw_(R[29] + 32, R[20]);  /* 0x8001B3C8 */
    R[20] = R[4] + R[0];  /* 0x8001B3CC */
    R[4] = R[0] + R[0];  /* 0x8001B3D0 */
    sw_(R[29] + 24, R[18]);  /* 0x8001B3D4 */
    R[18] = R[4] + R[0];  /* 0x8001B3D8 */
    sw_(R[29] + 36, R[31]);  /* 0x8001B3DC */
    sw_(R[29] + 28, R[19]);  /* 0x8001B3E0 */
    sw_(R[29] + 20, R[17]);  /* 0x8001B3E4 */
    sw_(R[29] + 16, R[16]);  /* 0x8001B3E8 */
    R[19] = R[0] + R[0];  /* 0x8001B3EC */
L_8001B3F0:;
    R[3] = 0x8006u << 16;  /* 0x8001B3F0 */
    R[2] = lh_(R[3] + -10024);  /* 0x8001B3F4 */
    R[3] = R[3] - 10024;  /* 0x8001B3F8 */
    R[3] = R[3] + 12;  /* 0x8001B3FC */
    R[2] = R[2] << 16;  /* 0x8001B400 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8001B404 */
    R[17] = R[2] + R[3];  /* 0x8001B408 */
    R[3] = R[20] & 0xFF;  /* 0x8001B40C */
    R[2] = R[0] + 1;  /* 0x8001B410 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8001B5EC; } }  /* 0x8001B414 */
    R[16] = lw_(R[17] + 12);  /* 0x8001B41C */
    R[2] = lw_(R[17] + 8);  /* 0x8001B420 */
    { uint32_t _c = (R[2] == R[0]); R[2] = (R[16] < (uint32_t)2048u); if (_c) { goto L_8001B4D0; } }  /* 0x8001B428 */
    { uint32_t _c = (R[4] != R[0]); if (_c) { goto L_8001B454; } }  /* 0x8001B430 */
    R[4] = 0x8006u << 16;  /* 0x8001B438 */
    R[4] = R[4] - 12096;  /* 0x8001B43C */
    { R[31] = 0x8001B448u; R[5] = R[0] + 512; psx_next = 0x800419C8u; return; }  /* 0x8001B440 jal */
    R[18] = R[2] + R[0];  /* 0x8001B448 */
    { R[31] = 0x8001B454u; R[4] = R[16] + R[0]; psx_next = 0x8001B364u; return; }  /* 0x8001B44C jal */
L_8001B454:;
    R[2] = lw_(R[17] + 8);  /* 0x8001B454 */
    R[3] = R[0] + 2048;  /* 0x8001B458 */
    R[6] = R[3] - R[2];  /* 0x8001B45C */
    R[2] = (R[16] < R[6]);  /* 0x8001B460 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8001B474; } }  /* 0x8001B464 */
    { R[16] = R[16] - R[6]; goto L_8001B480; }  /* 0x8001B46C j */
L_8001B474:;
    R[6] = R[16] + R[0];  /* 0x8001B474 */
    R[16] = R[0] + R[0];  /* 0x8001B478 */
    R[19] = R[0] + 1;  /* 0x8001B47C */
L_8001B480:;
    R[5] = lw_(R[17] + 8);  /* 0x8001B480 */
    { uint32_t _c = (R[6] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_8001B4B4; } }  /* 0x8001B484 */
    R[2] = 0x8006u << 16;  /* 0x8001B48C */
    R[7] = R[2] - 12096;  /* 0x8001B490 */
L_8001B494:;
    R[2] = R[5] + R[7];  /* 0x8001B494 */
    R[5] = R[5] + 1;  /* 0x8001B498 */
    R[3] = lw_(R[17] + 4);  /* 0x8001B49C */
    R[2] = lb_(R[2]);  /* 0x8001B4A0 */
    R[3] = R[3] + R[4];  /* 0x8001B4A4 */
    R[4] = R[4] + 1;  /* 0x8001B4A8 */
    { uint32_t _c = (R[4] != R[6]); sb_(R[3], R[2]); if (_c) { psx_bb(); goto L_8001B494; } }  /* 0x8001B4AC */
L_8001B4B4:;
    R[2] = lw_(R[17] + 4);  /* 0x8001B4B4 */
    R[2] = R[2] + R[6];  /* 0x8001B4BC */
    sw_(R[17] + 4, R[2]);  /* 0x8001B4C0 */
    sw_(R[17] + 8, R[0]);  /* 0x8001B4C4 */
    { goto L_8001B568; }  /* 0x8001B4C8 j */
L_8001B4D0:;
    { uint32_t _c = (R[2] != R[0]); R[2] = R[16] - 1; if (_c) { goto L_8001B508; } }  /* 0x8001B4D0 */
    R[4] = lw_(R[17] + 4);  /* 0x8001B4D8 */
    { R[31] = 0x8001B4E4u; R[5] = R[0] + 512; psx_next = 0x800419C8u; return; }  /* 0x8001B4DC jal */
    R[18] = R[2] + R[0];  /* 0x8001B4E4 */
    { R[31] = 0x8001B4F0u; R[4] = R[16] + R[0]; psx_next = 0x8001B364u; return; }  /* 0x8001B4E8 jal */
    R[2] = lw_(R[17] + 4);  /* 0x8001B4F0 */
    R[16] = R[16] - 2048;  /* 0x8001B4F4 */
    R[2] = R[2] + 2048;  /* 0x8001B4F8 */
    sw_(R[17] + 4, R[2]);  /* 0x8001B4FC */
    { goto L_8001B568; }  /* 0x8001B500 j */
L_8001B508:;
    R[2] = (R[2] < (uint32_t)2047u);  /* 0x8001B508 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001B568; } }  /* 0x8001B50C */
    { uint32_t _c = (R[4] != R[0]); R[4] = 0x8006u << 16; if (_c) { goto L_8001B534; } }  /* 0x8001B514 */
    R[4] = R[4] - 12096;  /* 0x8001B51C */
    { R[31] = 0x8001B528u; R[5] = R[0] + 512; psx_next = 0x800419C8u; return; }  /* 0x8001B520 jal */
    R[18] = R[2] + R[0];  /* 0x8001B528 */
    { R[31] = 0x8001B534u; R[4] = R[16] + R[0]; psx_next = 0x8001B364u; return; }  /* 0x8001B52C jal */
L_8001B534:;
    { uint32_t _c = (R[16] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_8001B560; } }  /* 0x8001B534 */
    R[2] = 0x8006u << 16;  /* 0x8001B53C */
    R[5] = R[2] - 12096;  /* 0x8001B540 */
L_8001B544:;
    R[3] = R[4] + R[5];  /* 0x8001B544 */
    R[2] = lw_(R[17] + 4);  /* 0x8001B548 */
    R[3] = lb_(R[3]);  /* 0x8001B54C */
    R[2] = R[2] + R[4];  /* 0x8001B550 */
    R[4] = R[4] + 1;  /* 0x8001B554 */
    { uint32_t _c = (R[4] != R[16]); sb_(R[2], R[3]); if (_c) { psx_bb(); goto L_8001B544; } }  /* 0x8001B558 */
L_8001B560:;
    R[16] = R[0] + R[0];  /* 0x8001B560 */
    R[19] = R[0] + 1;  /* 0x8001B564 */
L_8001B568:;
    sw_(R[17] + 12, R[16]);  /* 0x8001B568 */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8001B57C; } }  /* 0x8001B56C */
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_8001B5EC; } }  /* 0x8001B574 */
L_8001B57C:;
    { uint32_t _c = (R[18] != R[0]); R[6] = R[0] + 1; if (_c) { goto L_8001B5A4; } }  /* 0x8001B57C */
    R[3] = R[0] + 2;  /* 0x8001B584 */
    R[2] = 0x8006u << 16;  /* 0x8001B588 */
    R[2] = R[2] - 10024;  /* 0x8001B58C */
    sh_(R[17], R[3]);  /* 0x8001B590 */
    sh_(R[2] + 4, R[3]);  /* 0x8001B594 */
    sh_(R[2] + 2, R[0]);  /* 0x8001B598 */
    { goto L_8001B5EC; }  /* 0x8001B59C j */
L_8001B5A4:;
    R[4] = 0x8006u << 16;  /* 0x8001B5A4 */
    sh_(R[17], R[6]);  /* 0x8001B5A8 */
    R[2] = lh_(R[4] + -10024);  /* 0x8001B5AC */
    R[5] = R[4] - 10024;  /* 0x8001B5B0 */
    R[2] = R[2] + 1;  /* 0x8001B5B4 */
    sh_(R[4] + -10024, R[2]);  /* 0x8001B5B8 */
    R[3] = lh_(R[4] + -10024);  /* 0x8001B5BC */
    R[2] = lh_(R[5] + 2);  /* 0x8001B5C0 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8001B5E0; } }  /* 0x8001B5C8 */
    { uint32_t _c = (R[19] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8001B5EC; } }  /* 0x8001B5D0 */
    { R[19] = R[0] + R[0]; psx_bb(); goto L_8001B3F0; }  /* 0x8001B5D8 j */
L_8001B5E0:;
    sh_(R[5] + 4, R[6]);  /* 0x8001B5E0 */
    sh_(R[4] + -10024, R[0]);  /* 0x8001B5E4 */
    sh_(R[5] + 2, R[0]);  /* 0x8001B5E8 */
L_8001B5EC:;
    R[31] = lw_(R[29] + 36);  /* 0x8001B5EC */
    R[20] = lw_(R[29] + 32);  /* 0x8001B5F0 */
    R[19] = lw_(R[29] + 28);  /* 0x8001B5F4 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B5F8 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B5FC */
    R[16] = lw_(R[29] + 16);  /* 0x8001B600 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B604 jr ra */
}

void f_8001B3F0(void) {
L_8001B3F0:;
    R[3] = 0x8006u << 16;  /* 0x8001B3F0 */
    R[2] = lh_(R[3] + -10024);  /* 0x8001B3F4 */
    R[3] = R[3] - 10024;  /* 0x8001B3F8 */
    R[3] = R[3] + 12;  /* 0x8001B3FC */
    R[2] = R[2] << 16;  /* 0x8001B400 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8001B404 */
    R[17] = R[2] + R[3];  /* 0x8001B408 */
    R[3] = R[20] & 0xFF;  /* 0x8001B40C */
    R[2] = R[0] + 1;  /* 0x8001B410 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8001B5EC; } }  /* 0x8001B414 */
    R[16] = lw_(R[17] + 12);  /* 0x8001B41C */
    R[2] = lw_(R[17] + 8);  /* 0x8001B420 */
    { uint32_t _c = (R[2] == R[0]); R[2] = (R[16] < (uint32_t)2048u); if (_c) { goto L_8001B4D0; } }  /* 0x8001B428 */
    { uint32_t _c = (R[4] != R[0]); if (_c) { goto L_8001B454; } }  /* 0x8001B430 */
    R[4] = 0x8006u << 16;  /* 0x8001B438 */
    R[4] = R[4] - 12096;  /* 0x8001B43C */
    { R[31] = 0x8001B448u; R[5] = R[0] + 512; psx_next = 0x800419C8u; return; }  /* 0x8001B440 jal */
    R[18] = R[2] + R[0];  /* 0x8001B448 */
    { R[31] = 0x8001B454u; R[4] = R[16] + R[0]; psx_next = 0x8001B364u; return; }  /* 0x8001B44C jal */
L_8001B454:;
    R[2] = lw_(R[17] + 8);  /* 0x8001B454 */
    R[3] = R[0] + 2048;  /* 0x8001B458 */
    R[6] = R[3] - R[2];  /* 0x8001B45C */
    R[2] = (R[16] < R[6]);  /* 0x8001B460 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8001B474; } }  /* 0x8001B464 */
    { R[16] = R[16] - R[6]; goto L_8001B480; }  /* 0x8001B46C j */
L_8001B474:;
    R[6] = R[16] + R[0];  /* 0x8001B474 */
    R[16] = R[0] + R[0];  /* 0x8001B478 */
    R[19] = R[0] + 1;  /* 0x8001B47C */
L_8001B480:;
    R[5] = lw_(R[17] + 8);  /* 0x8001B480 */
    { uint32_t _c = (R[6] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_8001B4B4; } }  /* 0x8001B484 */
    R[2] = 0x8006u << 16;  /* 0x8001B48C */
    R[7] = R[2] - 12096;  /* 0x8001B490 */
L_8001B494:;
    R[2] = R[5] + R[7];  /* 0x8001B494 */
    R[5] = R[5] + 1;  /* 0x8001B498 */
    R[3] = lw_(R[17] + 4);  /* 0x8001B49C */
    R[2] = lb_(R[2]);  /* 0x8001B4A0 */
    R[3] = R[3] + R[4];  /* 0x8001B4A4 */
    R[4] = R[4] + 1;  /* 0x8001B4A8 */
    { uint32_t _c = (R[4] != R[6]); sb_(R[3], R[2]); if (_c) { psx_bb(); goto L_8001B494; } }  /* 0x8001B4AC */
L_8001B4B4:;
    R[2] = lw_(R[17] + 4);  /* 0x8001B4B4 */
    R[2] = R[2] + R[6];  /* 0x8001B4BC */
    sw_(R[17] + 4, R[2]);  /* 0x8001B4C0 */
    sw_(R[17] + 8, R[0]);  /* 0x8001B4C4 */
    { goto L_8001B568; }  /* 0x8001B4C8 j */
L_8001B4D0:;
    { uint32_t _c = (R[2] != R[0]); R[2] = R[16] - 1; if (_c) { goto L_8001B508; } }  /* 0x8001B4D0 */
    R[4] = lw_(R[17] + 4);  /* 0x8001B4D8 */
    { R[31] = 0x8001B4E4u; R[5] = R[0] + 512; psx_next = 0x800419C8u; return; }  /* 0x8001B4DC jal */
    R[18] = R[2] + R[0];  /* 0x8001B4E4 */
    { R[31] = 0x8001B4F0u; R[4] = R[16] + R[0]; psx_next = 0x8001B364u; return; }  /* 0x8001B4E8 jal */
    R[2] = lw_(R[17] + 4);  /* 0x8001B4F0 */
    R[16] = R[16] - 2048;  /* 0x8001B4F4 */
    R[2] = R[2] + 2048;  /* 0x8001B4F8 */
    sw_(R[17] + 4, R[2]);  /* 0x8001B4FC */
    { goto L_8001B568; }  /* 0x8001B500 j */
L_8001B508:;
    R[2] = (R[2] < (uint32_t)2047u);  /* 0x8001B508 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001B568; } }  /* 0x8001B50C */
    { uint32_t _c = (R[4] != R[0]); R[4] = 0x8006u << 16; if (_c) { goto L_8001B534; } }  /* 0x8001B514 */
    R[4] = R[4] - 12096;  /* 0x8001B51C */
    { R[31] = 0x8001B528u; R[5] = R[0] + 512; psx_next = 0x800419C8u; return; }  /* 0x8001B520 jal */
    R[18] = R[2] + R[0];  /* 0x8001B528 */
    { R[31] = 0x8001B534u; R[4] = R[16] + R[0]; psx_next = 0x8001B364u; return; }  /* 0x8001B52C jal */
L_8001B534:;
    { uint32_t _c = (R[16] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_8001B560; } }  /* 0x8001B534 */
    R[2] = 0x8006u << 16;  /* 0x8001B53C */
    R[5] = R[2] - 12096;  /* 0x8001B540 */
L_8001B544:;
    R[3] = R[4] + R[5];  /* 0x8001B544 */
    R[2] = lw_(R[17] + 4);  /* 0x8001B548 */
    R[3] = lb_(R[3]);  /* 0x8001B54C */
    R[2] = R[2] + R[4];  /* 0x8001B550 */
    R[4] = R[4] + 1;  /* 0x8001B554 */
    { uint32_t _c = (R[4] != R[16]); sb_(R[2], R[3]); if (_c) { psx_bb(); goto L_8001B544; } }  /* 0x8001B558 */
L_8001B560:;
    R[16] = R[0] + R[0];  /* 0x8001B560 */
    R[19] = R[0] + 1;  /* 0x8001B564 */
L_8001B568:;
    sw_(R[17] + 12, R[16]);  /* 0x8001B568 */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8001B57C; } }  /* 0x8001B56C */
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_8001B5EC; } }  /* 0x8001B574 */
L_8001B57C:;
    { uint32_t _c = (R[18] != R[0]); R[6] = R[0] + 1; if (_c) { goto L_8001B5A4; } }  /* 0x8001B57C */
    R[3] = R[0] + 2;  /* 0x8001B584 */
    R[2] = 0x8006u << 16;  /* 0x8001B588 */
    R[2] = R[2] - 10024;  /* 0x8001B58C */
    sh_(R[17], R[3]);  /* 0x8001B590 */
    sh_(R[2] + 4, R[3]);  /* 0x8001B594 */
    sh_(R[2] + 2, R[0]);  /* 0x8001B598 */
    { goto L_8001B5EC; }  /* 0x8001B59C j */
L_8001B5A4:;
    R[4] = 0x8006u << 16;  /* 0x8001B5A4 */
    sh_(R[17], R[6]);  /* 0x8001B5A8 */
    R[2] = lh_(R[4] + -10024);  /* 0x8001B5AC */
    R[5] = R[4] - 10024;  /* 0x8001B5B0 */
    R[2] = R[2] + 1;  /* 0x8001B5B4 */
    sh_(R[4] + -10024, R[2]);  /* 0x8001B5B8 */
    R[3] = lh_(R[4] + -10024);  /* 0x8001B5BC */
    R[2] = lh_(R[5] + 2);  /* 0x8001B5C0 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8001B5E0; } }  /* 0x8001B5C8 */
    { uint32_t _c = (R[19] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8001B5EC; } }  /* 0x8001B5D0 */
    { R[19] = R[0] + R[0]; psx_bb(); goto L_8001B3F0; }  /* 0x8001B5D8 j */
L_8001B5E0:;
    sh_(R[5] + 4, R[6]);  /* 0x8001B5E0 */
    sh_(R[4] + -10024, R[0]);  /* 0x8001B5E4 */
    sh_(R[5] + 2, R[0]);  /* 0x8001B5E8 */
L_8001B5EC:;
    R[31] = lw_(R[29] + 36);  /* 0x8001B5EC */
    R[20] = lw_(R[29] + 32);  /* 0x8001B5F0 */
    R[19] = lw_(R[29] + 28);  /* 0x8001B5F4 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B5F8 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B5FC */
    R[16] = lw_(R[29] + 16);  /* 0x8001B600 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B604 jr ra */
}

void f_8001B448(void) {
    R[18] = R[2] + R[0];  /* 0x8001B448 */
    { R[31] = 0x8001B454u; R[4] = R[16] + R[0]; psx_next = 0x8001B364u; return; }  /* 0x8001B44C jal */
    R[2] = lw_(R[17] + 8);  /* 0x8001B454 */
    R[3] = R[0] + 2048;  /* 0x8001B458 */
    R[6] = R[3] - R[2];  /* 0x8001B45C */
    R[2] = (R[16] < R[6]);  /* 0x8001B460 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8001B474; } }  /* 0x8001B464 */
    { R[16] = R[16] - R[6]; goto L_8001B480; }  /* 0x8001B46C j */
L_8001B474:;
    R[6] = R[16] + R[0];  /* 0x8001B474 */
    R[16] = R[0] + R[0];  /* 0x8001B478 */
    R[19] = R[0] + 1;  /* 0x8001B47C */
L_8001B480:;
    R[5] = lw_(R[17] + 8);  /* 0x8001B480 */
    { uint32_t _c = (R[6] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_8001B4B4; } }  /* 0x8001B484 */
    R[2] = 0x8006u << 16;  /* 0x8001B48C */
    R[7] = R[2] - 12096;  /* 0x8001B490 */
L_8001B494:;
    R[2] = R[5] + R[7];  /* 0x8001B494 */
    R[5] = R[5] + 1;  /* 0x8001B498 */
    R[3] = lw_(R[17] + 4);  /* 0x8001B49C */
    R[2] = lb_(R[2]);  /* 0x8001B4A0 */
    R[3] = R[3] + R[4];  /* 0x8001B4A4 */
    R[4] = R[4] + 1;  /* 0x8001B4A8 */
    { uint32_t _c = (R[4] != R[6]); sb_(R[3], R[2]); if (_c) { psx_bb(); goto L_8001B494; } }  /* 0x8001B4AC */
L_8001B4B4:;
    R[2] = lw_(R[17] + 4);  /* 0x8001B4B4 */
    R[2] = R[2] + R[6];  /* 0x8001B4BC */
    sw_(R[17] + 4, R[2]);  /* 0x8001B4C0 */
    sw_(R[17] + 8, R[0]);  /* 0x8001B4C4 */
    { goto L_8001B568; }  /* 0x8001B4C8 j */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[16] - 1; if (_c) { goto L_8001B508; } }  /* 0x8001B4D0 */
    R[4] = lw_(R[17] + 4);  /* 0x8001B4D8 */
    { R[31] = 0x8001B4E4u; R[5] = R[0] + 512; psx_next = 0x800419C8u; return; }  /* 0x8001B4DC jal */
    R[18] = R[2] + R[0];  /* 0x8001B4E4 */
    { R[31] = 0x8001B4F0u; R[4] = R[16] + R[0]; psx_next = 0x8001B364u; return; }  /* 0x8001B4E8 jal */
    R[2] = lw_(R[17] + 4);  /* 0x8001B4F0 */
    R[16] = R[16] - 2048;  /* 0x8001B4F4 */
    R[2] = R[2] + 2048;  /* 0x8001B4F8 */
    sw_(R[17] + 4, R[2]);  /* 0x8001B4FC */
    { goto L_8001B568; }  /* 0x8001B500 j */
L_8001B508:;
    R[2] = (R[2] < (uint32_t)2047u);  /* 0x8001B508 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001B568; } }  /* 0x8001B50C */
    { uint32_t _c = (R[4] != R[0]); R[4] = 0x8006u << 16; if (_c) { goto L_8001B534; } }  /* 0x8001B514 */
    R[4] = R[4] - 12096;  /* 0x8001B51C */
    { R[31] = 0x8001B528u; R[5] = R[0] + 512; psx_next = 0x800419C8u; return; }  /* 0x8001B520 jal */
    R[18] = R[2] + R[0];  /* 0x8001B528 */
    { R[31] = 0x8001B534u; R[4] = R[16] + R[0]; psx_next = 0x8001B364u; return; }  /* 0x8001B52C jal */
L_8001B534:;
    { uint32_t _c = (R[16] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_8001B560; } }  /* 0x8001B534 */
    R[2] = 0x8006u << 16;  /* 0x8001B53C */
    R[5] = R[2] - 12096;  /* 0x8001B540 */
L_8001B544:;
    R[3] = R[4] + R[5];  /* 0x8001B544 */
    R[2] = lw_(R[17] + 4);  /* 0x8001B548 */
    R[3] = lb_(R[3]);  /* 0x8001B54C */
    R[2] = R[2] + R[4];  /* 0x8001B550 */
    R[4] = R[4] + 1;  /* 0x8001B554 */
    { uint32_t _c = (R[4] != R[16]); sb_(R[2], R[3]); if (_c) { psx_bb(); goto L_8001B544; } }  /* 0x8001B558 */
L_8001B560:;
    R[16] = R[0] + R[0];  /* 0x8001B560 */
    R[19] = R[0] + 1;  /* 0x8001B564 */
L_8001B568:;
    sw_(R[17] + 12, R[16]);  /* 0x8001B568 */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8001B57C; } }  /* 0x8001B56C */
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_8001B5EC; } }  /* 0x8001B574 */
L_8001B57C:;
    { uint32_t _c = (R[18] != R[0]); R[6] = R[0] + 1; if (_c) { goto L_8001B5A4; } }  /* 0x8001B57C */
    R[3] = R[0] + 2;  /* 0x8001B584 */
    R[2] = 0x8006u << 16;  /* 0x8001B588 */
    R[2] = R[2] - 10024;  /* 0x8001B58C */
    sh_(R[17], R[3]);  /* 0x8001B590 */
    sh_(R[2] + 4, R[3]);  /* 0x8001B594 */
    sh_(R[2] + 2, R[0]);  /* 0x8001B598 */
    { goto L_8001B5EC; }  /* 0x8001B59C j */
L_8001B5A4:;
    R[4] = 0x8006u << 16;  /* 0x8001B5A4 */
    sh_(R[17], R[6]);  /* 0x8001B5A8 */
    R[2] = lh_(R[4] + -10024);  /* 0x8001B5AC */
    R[5] = R[4] - 10024;  /* 0x8001B5B0 */
    R[2] = R[2] + 1;  /* 0x8001B5B4 */
    sh_(R[4] + -10024, R[2]);  /* 0x8001B5B8 */
    R[3] = lh_(R[4] + -10024);  /* 0x8001B5BC */
    R[2] = lh_(R[5] + 2);  /* 0x8001B5C0 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8001B5E0; } }  /* 0x8001B5C8 */
    { uint32_t _c = (R[19] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8001B5EC; } }  /* 0x8001B5D0 */
    { R[19] = R[0] + R[0]; psx_next = 0x8001B3F0u; return; }  /* 0x8001B5D8 j extern */
L_8001B5E0:;
    sh_(R[5] + 4, R[6]);  /* 0x8001B5E0 */
    sh_(R[4] + -10024, R[0]);  /* 0x8001B5E4 */
    sh_(R[5] + 2, R[0]);  /* 0x8001B5E8 */
L_8001B5EC:;
    R[31] = lw_(R[29] + 36);  /* 0x8001B5EC */
    R[20] = lw_(R[29] + 32);  /* 0x8001B5F0 */
    R[19] = lw_(R[29] + 28);  /* 0x8001B5F4 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B5F8 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B5FC */
    R[16] = lw_(R[29] + 16);  /* 0x8001B600 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B604 jr ra */
}

void f_8001B454(void) {
    R[2] = lw_(R[17] + 8);  /* 0x8001B454 */
    R[3] = R[0] + 2048;  /* 0x8001B458 */
    R[6] = R[3] - R[2];  /* 0x8001B45C */
    R[2] = (R[16] < R[6]);  /* 0x8001B460 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8001B474; } }  /* 0x8001B464 */
    { R[16] = R[16] - R[6]; goto L_8001B480; }  /* 0x8001B46C j */
L_8001B474:;
    R[6] = R[16] + R[0];  /* 0x8001B474 */
    R[16] = R[0] + R[0];  /* 0x8001B478 */
    R[19] = R[0] + 1;  /* 0x8001B47C */
L_8001B480:;
    R[5] = lw_(R[17] + 8);  /* 0x8001B480 */
    { uint32_t _c = (R[6] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_8001B4B4; } }  /* 0x8001B484 */
    R[2] = 0x8006u << 16;  /* 0x8001B48C */
    R[7] = R[2] - 12096;  /* 0x8001B490 */
L_8001B494:;
    R[2] = R[5] + R[7];  /* 0x8001B494 */
    R[5] = R[5] + 1;  /* 0x8001B498 */
    R[3] = lw_(R[17] + 4);  /* 0x8001B49C */
    R[2] = lb_(R[2]);  /* 0x8001B4A0 */
    R[3] = R[3] + R[4];  /* 0x8001B4A4 */
    R[4] = R[4] + 1;  /* 0x8001B4A8 */
    { uint32_t _c = (R[4] != R[6]); sb_(R[3], R[2]); if (_c) { psx_bb(); goto L_8001B494; } }  /* 0x8001B4AC */
L_8001B4B4:;
    R[2] = lw_(R[17] + 4);  /* 0x8001B4B4 */
    R[2] = R[2] + R[6];  /* 0x8001B4BC */
    sw_(R[17] + 4, R[2]);  /* 0x8001B4C0 */
    sw_(R[17] + 8, R[0]);  /* 0x8001B4C4 */
    { goto L_8001B568; }  /* 0x8001B4C8 j */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[16] - 1; if (_c) { goto L_8001B508; } }  /* 0x8001B4D0 */
    R[4] = lw_(R[17] + 4);  /* 0x8001B4D8 */
    { R[31] = 0x8001B4E4u; R[5] = R[0] + 512; psx_next = 0x800419C8u; return; }  /* 0x8001B4DC jal */
    R[18] = R[2] + R[0];  /* 0x8001B4E4 */
    { R[31] = 0x8001B4F0u; R[4] = R[16] + R[0]; psx_next = 0x8001B364u; return; }  /* 0x8001B4E8 jal */
    R[2] = lw_(R[17] + 4);  /* 0x8001B4F0 */
    R[16] = R[16] - 2048;  /* 0x8001B4F4 */
    R[2] = R[2] + 2048;  /* 0x8001B4F8 */
    sw_(R[17] + 4, R[2]);  /* 0x8001B4FC */
    { goto L_8001B568; }  /* 0x8001B500 j */
L_8001B508:;
    R[2] = (R[2] < (uint32_t)2047u);  /* 0x8001B508 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001B568; } }  /* 0x8001B50C */
    { uint32_t _c = (R[4] != R[0]); R[4] = 0x8006u << 16; if (_c) { goto L_8001B534; } }  /* 0x8001B514 */
    R[4] = R[4] - 12096;  /* 0x8001B51C */
    { R[31] = 0x8001B528u; R[5] = R[0] + 512; psx_next = 0x800419C8u; return; }  /* 0x8001B520 jal */
    R[18] = R[2] + R[0];  /* 0x8001B528 */
    { R[31] = 0x8001B534u; R[4] = R[16] + R[0]; psx_next = 0x8001B364u; return; }  /* 0x8001B52C jal */
L_8001B534:;
    { uint32_t _c = (R[16] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_8001B560; } }  /* 0x8001B534 */
    R[2] = 0x8006u << 16;  /* 0x8001B53C */
    R[5] = R[2] - 12096;  /* 0x8001B540 */
L_8001B544:;
    R[3] = R[4] + R[5];  /* 0x8001B544 */
    R[2] = lw_(R[17] + 4);  /* 0x8001B548 */
    R[3] = lb_(R[3]);  /* 0x8001B54C */
    R[2] = R[2] + R[4];  /* 0x8001B550 */
    R[4] = R[4] + 1;  /* 0x8001B554 */
    { uint32_t _c = (R[4] != R[16]); sb_(R[2], R[3]); if (_c) { psx_bb(); goto L_8001B544; } }  /* 0x8001B558 */
L_8001B560:;
    R[16] = R[0] + R[0];  /* 0x8001B560 */
    R[19] = R[0] + 1;  /* 0x8001B564 */
L_8001B568:;
    sw_(R[17] + 12, R[16]);  /* 0x8001B568 */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8001B57C; } }  /* 0x8001B56C */
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_8001B5EC; } }  /* 0x8001B574 */
L_8001B57C:;
    { uint32_t _c = (R[18] != R[0]); R[6] = R[0] + 1; if (_c) { goto L_8001B5A4; } }  /* 0x8001B57C */
    R[3] = R[0] + 2;  /* 0x8001B584 */
    R[2] = 0x8006u << 16;  /* 0x8001B588 */
    R[2] = R[2] - 10024;  /* 0x8001B58C */
    sh_(R[17], R[3]);  /* 0x8001B590 */
    sh_(R[2] + 4, R[3]);  /* 0x8001B594 */
    sh_(R[2] + 2, R[0]);  /* 0x8001B598 */
    { goto L_8001B5EC; }  /* 0x8001B59C j */
L_8001B5A4:;
    R[4] = 0x8006u << 16;  /* 0x8001B5A4 */
    sh_(R[17], R[6]);  /* 0x8001B5A8 */
    R[2] = lh_(R[4] + -10024);  /* 0x8001B5AC */
    R[5] = R[4] - 10024;  /* 0x8001B5B0 */
    R[2] = R[2] + 1;  /* 0x8001B5B4 */
    sh_(R[4] + -10024, R[2]);  /* 0x8001B5B8 */
    R[3] = lh_(R[4] + -10024);  /* 0x8001B5BC */
    R[2] = lh_(R[5] + 2);  /* 0x8001B5C0 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8001B5E0; } }  /* 0x8001B5C8 */
    { uint32_t _c = (R[19] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8001B5EC; } }  /* 0x8001B5D0 */
    { R[19] = R[0] + R[0]; psx_next = 0x8001B3F0u; return; }  /* 0x8001B5D8 j extern */
L_8001B5E0:;
    sh_(R[5] + 4, R[6]);  /* 0x8001B5E0 */
    sh_(R[4] + -10024, R[0]);  /* 0x8001B5E4 */
    sh_(R[5] + 2, R[0]);  /* 0x8001B5E8 */
L_8001B5EC:;
    R[31] = lw_(R[29] + 36);  /* 0x8001B5EC */
    R[20] = lw_(R[29] + 32);  /* 0x8001B5F0 */
    R[19] = lw_(R[29] + 28);  /* 0x8001B5F4 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B5F8 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B5FC */
    R[16] = lw_(R[29] + 16);  /* 0x8001B600 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B604 jr ra */
}

void f_8001B4E4(void) {
    R[18] = R[2] + R[0];  /* 0x8001B4E4 */
    { R[31] = 0x8001B4F0u; R[4] = R[16] + R[0]; psx_next = 0x8001B364u; return; }  /* 0x8001B4E8 jal */
    R[2] = lw_(R[17] + 4);  /* 0x8001B4F0 */
    R[16] = R[16] - 2048;  /* 0x8001B4F4 */
    R[2] = R[2] + 2048;  /* 0x8001B4F8 */
    sw_(R[17] + 4, R[2]);  /* 0x8001B4FC */
    { goto L_8001B568; }  /* 0x8001B500 j */
    R[2] = (R[2] < (uint32_t)2047u);  /* 0x8001B508 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001B568; } }  /* 0x8001B50C */
    { uint32_t _c = (R[4] != R[0]); R[4] = 0x8006u << 16; if (_c) { goto L_8001B534; } }  /* 0x8001B514 */
    R[4] = R[4] - 12096;  /* 0x8001B51C */
    { R[31] = 0x8001B528u; R[5] = R[0] + 512; psx_next = 0x800419C8u; return; }  /* 0x8001B520 jal */
    R[18] = R[2] + R[0];  /* 0x8001B528 */
    { R[31] = 0x8001B534u; R[4] = R[16] + R[0]; psx_next = 0x8001B364u; return; }  /* 0x8001B52C jal */
L_8001B534:;
    { uint32_t _c = (R[16] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_8001B560; } }  /* 0x8001B534 */
    R[2] = 0x8006u << 16;  /* 0x8001B53C */
    R[5] = R[2] - 12096;  /* 0x8001B540 */
L_8001B544:;
    R[3] = R[4] + R[5];  /* 0x8001B544 */
    R[2] = lw_(R[17] + 4);  /* 0x8001B548 */
    R[3] = lb_(R[3]);  /* 0x8001B54C */
    R[2] = R[2] + R[4];  /* 0x8001B550 */
    R[4] = R[4] + 1;  /* 0x8001B554 */
    { uint32_t _c = (R[4] != R[16]); sb_(R[2], R[3]); if (_c) { psx_bb(); goto L_8001B544; } }  /* 0x8001B558 */
L_8001B560:;
    R[16] = R[0] + R[0];  /* 0x8001B560 */
    R[19] = R[0] + 1;  /* 0x8001B564 */
L_8001B568:;
    sw_(R[17] + 12, R[16]);  /* 0x8001B568 */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8001B57C; } }  /* 0x8001B56C */
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_8001B5EC; } }  /* 0x8001B574 */
L_8001B57C:;
    { uint32_t _c = (R[18] != R[0]); R[6] = R[0] + 1; if (_c) { goto L_8001B5A4; } }  /* 0x8001B57C */
    R[3] = R[0] + 2;  /* 0x8001B584 */
    R[2] = 0x8006u << 16;  /* 0x8001B588 */
    R[2] = R[2] - 10024;  /* 0x8001B58C */
    sh_(R[17], R[3]);  /* 0x8001B590 */
    sh_(R[2] + 4, R[3]);  /* 0x8001B594 */
    sh_(R[2] + 2, R[0]);  /* 0x8001B598 */
    { goto L_8001B5EC; }  /* 0x8001B59C j */
L_8001B5A4:;
    R[4] = 0x8006u << 16;  /* 0x8001B5A4 */
    sh_(R[17], R[6]);  /* 0x8001B5A8 */
    R[2] = lh_(R[4] + -10024);  /* 0x8001B5AC */
    R[5] = R[4] - 10024;  /* 0x8001B5B0 */
    R[2] = R[2] + 1;  /* 0x8001B5B4 */
    sh_(R[4] + -10024, R[2]);  /* 0x8001B5B8 */
    R[3] = lh_(R[4] + -10024);  /* 0x8001B5BC */
    R[2] = lh_(R[5] + 2);  /* 0x8001B5C0 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8001B5E0; } }  /* 0x8001B5C8 */
    { uint32_t _c = (R[19] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8001B5EC; } }  /* 0x8001B5D0 */
    { R[19] = R[0] + R[0]; psx_next = 0x8001B3F0u; return; }  /* 0x8001B5D8 j extern */
L_8001B5E0:;
    sh_(R[5] + 4, R[6]);  /* 0x8001B5E0 */
    sh_(R[4] + -10024, R[0]);  /* 0x8001B5E4 */
    sh_(R[5] + 2, R[0]);  /* 0x8001B5E8 */
L_8001B5EC:;
    R[31] = lw_(R[29] + 36);  /* 0x8001B5EC */
    R[20] = lw_(R[29] + 32);  /* 0x8001B5F0 */
    R[19] = lw_(R[29] + 28);  /* 0x8001B5F4 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B5F8 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B5FC */
    R[16] = lw_(R[29] + 16);  /* 0x8001B600 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B604 jr ra */
}

void f_8001B4F0(void) {
    R[2] = lw_(R[17] + 4);  /* 0x8001B4F0 */
    R[16] = R[16] - 2048;  /* 0x8001B4F4 */
    R[2] = R[2] + 2048;  /* 0x8001B4F8 */
    sw_(R[17] + 4, R[2]);  /* 0x8001B4FC */
    { goto L_8001B568; }  /* 0x8001B500 j */
    R[2] = (R[2] < (uint32_t)2047u);  /* 0x8001B508 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8001B568; } }  /* 0x8001B50C */
    { uint32_t _c = (R[4] != R[0]); R[4] = 0x8006u << 16; if (_c) { goto L_8001B534; } }  /* 0x8001B514 */
    R[4] = R[4] - 12096;  /* 0x8001B51C */
    { R[31] = 0x8001B528u; R[5] = R[0] + 512; psx_next = 0x800419C8u; return; }  /* 0x8001B520 jal */
    R[18] = R[2] + R[0];  /* 0x8001B528 */
    { R[31] = 0x8001B534u; R[4] = R[16] + R[0]; psx_next = 0x8001B364u; return; }  /* 0x8001B52C jal */
L_8001B534:;
    { uint32_t _c = (R[16] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_8001B560; } }  /* 0x8001B534 */
    R[2] = 0x8006u << 16;  /* 0x8001B53C */
    R[5] = R[2] - 12096;  /* 0x8001B540 */
L_8001B544:;
    R[3] = R[4] + R[5];  /* 0x8001B544 */
    R[2] = lw_(R[17] + 4);  /* 0x8001B548 */
    R[3] = lb_(R[3]);  /* 0x8001B54C */
    R[2] = R[2] + R[4];  /* 0x8001B550 */
    R[4] = R[4] + 1;  /* 0x8001B554 */
    { uint32_t _c = (R[4] != R[16]); sb_(R[2], R[3]); if (_c) { psx_bb(); goto L_8001B544; } }  /* 0x8001B558 */
L_8001B560:;
    R[16] = R[0] + R[0];  /* 0x8001B560 */
    R[19] = R[0] + 1;  /* 0x8001B564 */
L_8001B568:;
    sw_(R[17] + 12, R[16]);  /* 0x8001B568 */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8001B57C; } }  /* 0x8001B56C */
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_8001B5EC; } }  /* 0x8001B574 */
L_8001B57C:;
    { uint32_t _c = (R[18] != R[0]); R[6] = R[0] + 1; if (_c) { goto L_8001B5A4; } }  /* 0x8001B57C */
    R[3] = R[0] + 2;  /* 0x8001B584 */
    R[2] = 0x8006u << 16;  /* 0x8001B588 */
    R[2] = R[2] - 10024;  /* 0x8001B58C */
    sh_(R[17], R[3]);  /* 0x8001B590 */
    sh_(R[2] + 4, R[3]);  /* 0x8001B594 */
    sh_(R[2] + 2, R[0]);  /* 0x8001B598 */
    { goto L_8001B5EC; }  /* 0x8001B59C j */
L_8001B5A4:;
    R[4] = 0x8006u << 16;  /* 0x8001B5A4 */
    sh_(R[17], R[6]);  /* 0x8001B5A8 */
    R[2] = lh_(R[4] + -10024);  /* 0x8001B5AC */
    R[5] = R[4] - 10024;  /* 0x8001B5B0 */
    R[2] = R[2] + 1;  /* 0x8001B5B4 */
    sh_(R[4] + -10024, R[2]);  /* 0x8001B5B8 */
    R[3] = lh_(R[4] + -10024);  /* 0x8001B5BC */
    R[2] = lh_(R[5] + 2);  /* 0x8001B5C0 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8001B5E0; } }  /* 0x8001B5C8 */
    { uint32_t _c = (R[19] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8001B5EC; } }  /* 0x8001B5D0 */
    { R[19] = R[0] + R[0]; psx_next = 0x8001B3F0u; return; }  /* 0x8001B5D8 j extern */
L_8001B5E0:;
    sh_(R[5] + 4, R[6]);  /* 0x8001B5E0 */
    sh_(R[4] + -10024, R[0]);  /* 0x8001B5E4 */
    sh_(R[5] + 2, R[0]);  /* 0x8001B5E8 */
L_8001B5EC:;
    R[31] = lw_(R[29] + 36);  /* 0x8001B5EC */
    R[20] = lw_(R[29] + 32);  /* 0x8001B5F0 */
    R[19] = lw_(R[29] + 28);  /* 0x8001B5F4 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B5F8 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B5FC */
    R[16] = lw_(R[29] + 16);  /* 0x8001B600 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B604 jr ra */
}

void f_8001B528(void) {
    R[18] = R[2] + R[0];  /* 0x8001B528 */
    { R[31] = 0x8001B534u; R[4] = R[16] + R[0]; psx_next = 0x8001B364u; return; }  /* 0x8001B52C jal */
    { uint32_t _c = (R[16] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_8001B560; } }  /* 0x8001B534 */
    R[2] = 0x8006u << 16;  /* 0x8001B53C */
    R[5] = R[2] - 12096;  /* 0x8001B540 */
L_8001B544:;
    R[3] = R[4] + R[5];  /* 0x8001B544 */
    R[2] = lw_(R[17] + 4);  /* 0x8001B548 */
    R[3] = lb_(R[3]);  /* 0x8001B54C */
    R[2] = R[2] + R[4];  /* 0x8001B550 */
    R[4] = R[4] + 1;  /* 0x8001B554 */
    { uint32_t _c = (R[4] != R[16]); sb_(R[2], R[3]); if (_c) { psx_bb(); goto L_8001B544; } }  /* 0x8001B558 */
L_8001B560:;
    R[16] = R[0] + R[0];  /* 0x8001B560 */
    R[19] = R[0] + 1;  /* 0x8001B564 */
    sw_(R[17] + 12, R[16]);  /* 0x8001B568 */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8001B57C; } }  /* 0x8001B56C */
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_8001B5EC; } }  /* 0x8001B574 */
L_8001B57C:;
    { uint32_t _c = (R[18] != R[0]); R[6] = R[0] + 1; if (_c) { goto L_8001B5A4; } }  /* 0x8001B57C */
    R[3] = R[0] + 2;  /* 0x8001B584 */
    R[2] = 0x8006u << 16;  /* 0x8001B588 */
    R[2] = R[2] - 10024;  /* 0x8001B58C */
    sh_(R[17], R[3]);  /* 0x8001B590 */
    sh_(R[2] + 4, R[3]);  /* 0x8001B594 */
    sh_(R[2] + 2, R[0]);  /* 0x8001B598 */
    { goto L_8001B5EC; }  /* 0x8001B59C j */
L_8001B5A4:;
    R[4] = 0x8006u << 16;  /* 0x8001B5A4 */
    sh_(R[17], R[6]);  /* 0x8001B5A8 */
    R[2] = lh_(R[4] + -10024);  /* 0x8001B5AC */
    R[5] = R[4] - 10024;  /* 0x8001B5B0 */
    R[2] = R[2] + 1;  /* 0x8001B5B4 */
    sh_(R[4] + -10024, R[2]);  /* 0x8001B5B8 */
    R[3] = lh_(R[4] + -10024);  /* 0x8001B5BC */
    R[2] = lh_(R[5] + 2);  /* 0x8001B5C0 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8001B5E0; } }  /* 0x8001B5C8 */
    { uint32_t _c = (R[19] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8001B5EC; } }  /* 0x8001B5D0 */
    { R[19] = R[0] + R[0]; psx_next = 0x8001B3F0u; return; }  /* 0x8001B5D8 j extern */
L_8001B5E0:;
    sh_(R[5] + 4, R[6]);  /* 0x8001B5E0 */
    sh_(R[4] + -10024, R[0]);  /* 0x8001B5E4 */
    sh_(R[5] + 2, R[0]);  /* 0x8001B5E8 */
L_8001B5EC:;
    R[31] = lw_(R[29] + 36);  /* 0x8001B5EC */
    R[20] = lw_(R[29] + 32);  /* 0x8001B5F0 */
    R[19] = lw_(R[29] + 28);  /* 0x8001B5F4 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B5F8 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B5FC */
    R[16] = lw_(R[29] + 16);  /* 0x8001B600 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B604 jr ra */
}

void f_8001B534(void) {
    { uint32_t _c = (R[16] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_8001B560; } }  /* 0x8001B534 */
    R[2] = 0x8006u << 16;  /* 0x8001B53C */
    R[5] = R[2] - 12096;  /* 0x8001B540 */
L_8001B544:;
    R[3] = R[4] + R[5];  /* 0x8001B544 */
    R[2] = lw_(R[17] + 4);  /* 0x8001B548 */
    R[3] = lb_(R[3]);  /* 0x8001B54C */
    R[2] = R[2] + R[4];  /* 0x8001B550 */
    R[4] = R[4] + 1;  /* 0x8001B554 */
    { uint32_t _c = (R[4] != R[16]); sb_(R[2], R[3]); if (_c) { psx_bb(); goto L_8001B544; } }  /* 0x8001B558 */
L_8001B560:;
    R[16] = R[0] + R[0];  /* 0x8001B560 */
    R[19] = R[0] + 1;  /* 0x8001B564 */
    sw_(R[17] + 12, R[16]);  /* 0x8001B568 */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8001B57C; } }  /* 0x8001B56C */
    { uint32_t _c = (R[18] != R[0]); if (_c) { goto L_8001B5EC; } }  /* 0x8001B574 */
L_8001B57C:;
    { uint32_t _c = (R[18] != R[0]); R[6] = R[0] + 1; if (_c) { goto L_8001B5A4; } }  /* 0x8001B57C */
    R[3] = R[0] + 2;  /* 0x8001B584 */
    R[2] = 0x8006u << 16;  /* 0x8001B588 */
    R[2] = R[2] - 10024;  /* 0x8001B58C */
    sh_(R[17], R[3]);  /* 0x8001B590 */
    sh_(R[2] + 4, R[3]);  /* 0x8001B594 */
    sh_(R[2] + 2, R[0]);  /* 0x8001B598 */
    { goto L_8001B5EC; }  /* 0x8001B59C j */
L_8001B5A4:;
    R[4] = 0x8006u << 16;  /* 0x8001B5A4 */
    sh_(R[17], R[6]);  /* 0x8001B5A8 */
    R[2] = lh_(R[4] + -10024);  /* 0x8001B5AC */
    R[5] = R[4] - 10024;  /* 0x8001B5B0 */
    R[2] = R[2] + 1;  /* 0x8001B5B4 */
    sh_(R[4] + -10024, R[2]);  /* 0x8001B5B8 */
    R[3] = lh_(R[4] + -10024);  /* 0x8001B5BC */
    R[2] = lh_(R[5] + 2);  /* 0x8001B5C0 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8001B5E0; } }  /* 0x8001B5C8 */
    { uint32_t _c = (R[19] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8001B5EC; } }  /* 0x8001B5D0 */
    { R[19] = R[0] + R[0]; psx_next = 0x8001B3F0u; return; }  /* 0x8001B5D8 j extern */
L_8001B5E0:;
    sh_(R[5] + 4, R[6]);  /* 0x8001B5E0 */
    sh_(R[4] + -10024, R[0]);  /* 0x8001B5E4 */
    sh_(R[5] + 2, R[0]);  /* 0x8001B5E8 */
L_8001B5EC:;
    R[31] = lw_(R[29] + 36);  /* 0x8001B5EC */
    R[20] = lw_(R[29] + 32);  /* 0x8001B5F0 */
    R[19] = lw_(R[29] + 28);  /* 0x8001B5F4 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B5F8 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B5FC */
    R[16] = lw_(R[29] + 16);  /* 0x8001B600 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B604 jr ra */
}

void f_8001B60C(void) {
    R[29] = R[29] - 24;  /* 0x8001B60C */
    R[4] = R[4] & 0xFF;  /* 0x8001B610 */
    R[2] = R[0] + 2;  /* 0x8001B614 */
    { uint32_t _c = (R[4] != R[2]); sw_(R[29] + 16, R[31]); if (_c) { goto L_8001B630; } }  /* 0x8001B618 */
    R[4] = 0x8002u << 16;  /* 0x8001B620 */
    R[4] = R[4] - 19516;  /* 0x8001B624 */
    { R[31] = 0x8001B630u; R[5] = R[0] - 1; psx_next = 0x80042B88u; return; }  /* 0x8001B628 jal */
L_8001B630:;
    R[31] = lw_(R[29] + 16);  /* 0x8001B630 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001B638 jr ra */
}

void f_8001B630(void) {
    R[31] = lw_(R[29] + 16);  /* 0x8001B630 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001B638 jr ra */
}

void f_8001B640(void) {
    R[29] = R[29] - 296;  /* 0x8001B640 */
    sw_(R[29] + 284, R[21]);  /* 0x8001B644 */
    R[21] = R[4] + R[0];  /* 0x8001B648 */
    sw_(R[29] + 280, R[20]);  /* 0x8001B64C */
    R[20] = R[5] + R[0];  /* 0x8001B650 */
    sw_(R[29] + 288, R[31]);  /* 0x8001B654 */
    sw_(R[29] + 276, R[19]);  /* 0x8001B658 */
    sw_(R[29] + 272, R[18]);  /* 0x8001B65C */
    sw_(R[29] + 268, R[17]);  /* 0x8001B660 */
    { R[31] = 0x8001B66Cu; sw_(R[29] + 264, R[16]); psx_next = 0x8002FAA4u; return; }  /* 0x8001B664 jal */
    R[4] = R[29] + 48;  /* 0x8001B66C */
    R[5] = 0x8006u << 16;  /* 0x8001B670 */
    R[5] = R[5] - 10024;  /* 0x8001B674 */
L_8001B678:;
    { R[31] = 0x8001B680u; R[6] = R[0] + 204; psx_next = 0x80030E18u; return; }  /* 0x8001B678 jal */
    R[4] = R[29] + 24;  /* 0x8001B680 */
    { R[31] = 0x8001B68Cu; R[5] = R[21] + R[0]; psx_next = 0x8001AD68u; return; }  /* 0x8001B684 jal */
    R[19] = 0x8006u << 16;  /* 0x8001B68C */
    R[18] = R[19] - 10024;  /* 0x8001B690 */
    R[16] = lw_(R[18] + 8);  /* 0x8001B694 */
    { uint32_t _c = ((int32_t)R[16] >= 0); R[17] = R[2] + R[0]; if (_c) { goto L_8001B6A8; } }  /* 0x8001B69C */
    R[16] = R[16] + 2047;  /* 0x8001B6A4 */
L_8001B6A8:;
    R[4] = R[17] + R[0];  /* 0x8001B6A8 */
    { R[31] = 0x8001B6B4u; R[16] = (uint32_t)((int32_t)R[16] >> 11); psx_next = 0x80041B2Cu; return; }  /* 0x8001B6AC jal */
    R[4] = R[2] + R[16];  /* 0x8001B6B4 */
    { R[31] = 0x8001B6C0u; R[5] = R[17] + R[0]; psx_next = 0x80041A28u; return; }  /* 0x8001B6B8 jal */
    R[4] = R[0] + 160;  /* 0x8001B6C0 */
    R[5] = R[17] + R[0];  /* 0x8001B6C4 */
    R[6] = R[0] + 6;  /* 0x8001B6C8 */
    R[2] = R[0] - 1;  /* 0x8001B6CC */
    R[7] = 0x8002u << 16;  /* 0x8001B6D0 */
    R[7] = R[7] - 18932;  /* 0x8001B6D4 */
    sh_(R[18] + 6, R[20]);  /* 0x8001B6D8 */
    sh_(R[18] + 4, R[0]);  /* 0x8001B6DC */
    sh_(R[19] + -10024, R[0]);  /* 0x8001B6E0 */
    { R[31] = 0x8001B6ECu; sw_(R[29] + 16, R[2]); psx_next = 0x8003E6CCu; return; }  /* 0x8001B6E4 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B6EC */
    { R[31] = 0x8001B6FCu; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B6F4 jal */
    R[16] = R[0] + 5;  /* 0x8001B6FC */
L_8001B700:;
    { R[31] = 0x8001B708u; psx_next = 0x8003EDE0u; return; }  /* 0x8001B700 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B708 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B72C; } }  /* 0x8001B70C */
    { R[31] = 0x8001B71Cu; R[5] = R[29] + 256; psx_next = 0x8003EA70u; return; }  /* 0x8001B714 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B71C */
    { psx_bb(); goto L_8001B700; }  /* 0x8001B724 j */
L_8001B72C:;
    R[2] = R[20] - 1;  /* 0x8001B72C */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x8001B730 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8001B7D0; } }  /* 0x8001B734 */
    R[2] = 0x8006u << 16;  /* 0x8001B73C */
    R[3] = R[2] - 10024;  /* 0x8001B740 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B744 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B784; } }  /* 0x8001B74C */
    R[4] = R[0] + 2;  /* 0x8001B754 */
L_8001B758:;
    R[2] = lh_(R[3] + 4);  /* 0x8001B758 */
    R[2] = R[2] << 16;  /* 0x8001B760 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B764 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B7A0; } }  /* 0x8001B768 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B770 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B758; } }  /* 0x8001B778 */
    R[4] = R[0] + 9;  /* 0x8001B780 */
L_8001B784:;
    R[5] = R[0] + R[0];  /* 0x8001B784 */
    { R[31] = 0x8001B790u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B788 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B784; } }  /* 0x8001B790 */
    { R[2] = R[0] + R[0]; goto L_8001B7D0; }  /* 0x8001B798 j */
L_8001B7A0:;
    R[4] = R[0] + 9;  /* 0x8001B7A0 */
L_8001B7A4:;
    R[5] = R[0] + R[0];  /* 0x8001B7A4 */
    { R[31] = 0x8001B7B0u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B7A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B7A4; } }  /* 0x8001B7B0 */
    { R[31] = 0x8001B7C0u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B7B8 jal */
    R[4] = 0x8006u << 16;  /* 0x8001B7C0 */
    R[4] = R[4] - 10024;  /* 0x8001B7C4 */
    { R[5] = R[29] + 48; psx_bb(); goto L_8001B678; }  /* 0x8001B7C8 j */
L_8001B7D0:;
    R[31] = lw_(R[29] + 288);  /* 0x8001B7D0 */
    R[21] = lw_(R[29] + 284);  /* 0x8001B7D4 */
    R[20] = lw_(R[29] + 280);  /* 0x8001B7D8 */
    R[19] = lw_(R[29] + 276);  /* 0x8001B7DC */
    R[18] = lw_(R[29] + 272);  /* 0x8001B7E0 */
    R[17] = lw_(R[29] + 268);  /* 0x8001B7E4 */
    R[16] = lw_(R[29] + 264);  /* 0x8001B7E8 */
    { R[29] = R[29] + 296; psx_next = R[31]; return; }  /* 0x8001B7EC jr ra */
}

void f_8001B66C(void) {
    R[4] = R[29] + 48;  /* 0x8001B66C */
    R[5] = 0x8006u << 16;  /* 0x8001B670 */
    R[5] = R[5] - 10024;  /* 0x8001B674 */
L_8001B678:;
    { R[31] = 0x8001B680u; R[6] = R[0] + 204; psx_next = 0x80030E18u; return; }  /* 0x8001B678 jal */
    R[4] = R[29] + 24;  /* 0x8001B680 */
    { R[31] = 0x8001B68Cu; R[5] = R[21] + R[0]; psx_next = 0x8001AD68u; return; }  /* 0x8001B684 jal */
    R[19] = 0x8006u << 16;  /* 0x8001B68C */
    R[18] = R[19] - 10024;  /* 0x8001B690 */
    R[16] = lw_(R[18] + 8);  /* 0x8001B694 */
    { uint32_t _c = ((int32_t)R[16] >= 0); R[17] = R[2] + R[0]; if (_c) { goto L_8001B6A8; } }  /* 0x8001B69C */
    R[16] = R[16] + 2047;  /* 0x8001B6A4 */
L_8001B6A8:;
    R[4] = R[17] + R[0];  /* 0x8001B6A8 */
    { R[31] = 0x8001B6B4u; R[16] = (uint32_t)((int32_t)R[16] >> 11); psx_next = 0x80041B2Cu; return; }  /* 0x8001B6AC jal */
    R[4] = R[2] + R[16];  /* 0x8001B6B4 */
    { R[31] = 0x8001B6C0u; R[5] = R[17] + R[0]; psx_next = 0x80041A28u; return; }  /* 0x8001B6B8 jal */
    R[4] = R[0] + 160;  /* 0x8001B6C0 */
    R[5] = R[17] + R[0];  /* 0x8001B6C4 */
    R[6] = R[0] + 6;  /* 0x8001B6C8 */
    R[2] = R[0] - 1;  /* 0x8001B6CC */
    R[7] = 0x8002u << 16;  /* 0x8001B6D0 */
    R[7] = R[7] - 18932;  /* 0x8001B6D4 */
    sh_(R[18] + 6, R[20]);  /* 0x8001B6D8 */
    sh_(R[18] + 4, R[0]);  /* 0x8001B6DC */
    sh_(R[19] + -10024, R[0]);  /* 0x8001B6E0 */
    { R[31] = 0x8001B6ECu; sw_(R[29] + 16, R[2]); psx_next = 0x8003E6CCu; return; }  /* 0x8001B6E4 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B6EC */
    { R[31] = 0x8001B6FCu; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B6F4 jal */
    R[16] = R[0] + 5;  /* 0x8001B6FC */
L_8001B700:;
    { R[31] = 0x8001B708u; psx_next = 0x8003EDE0u; return; }  /* 0x8001B700 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B708 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B72C; } }  /* 0x8001B70C */
    { R[31] = 0x8001B71Cu; R[5] = R[29] + 256; psx_next = 0x8003EA70u; return; }  /* 0x8001B714 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B71C */
    { psx_bb(); goto L_8001B700; }  /* 0x8001B724 j */
L_8001B72C:;
    R[2] = R[20] - 1;  /* 0x8001B72C */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x8001B730 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8001B7D0; } }  /* 0x8001B734 */
    R[2] = 0x8006u << 16;  /* 0x8001B73C */
    R[3] = R[2] - 10024;  /* 0x8001B740 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B744 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B784; } }  /* 0x8001B74C */
    R[4] = R[0] + 2;  /* 0x8001B754 */
L_8001B758:;
    R[2] = lh_(R[3] + 4);  /* 0x8001B758 */
    R[2] = R[2] << 16;  /* 0x8001B760 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B764 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B7A0; } }  /* 0x8001B768 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B770 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B758; } }  /* 0x8001B778 */
    R[4] = R[0] + 9;  /* 0x8001B780 */
L_8001B784:;
    R[5] = R[0] + R[0];  /* 0x8001B784 */
    { R[31] = 0x8001B790u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B788 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B784; } }  /* 0x8001B790 */
    { R[2] = R[0] + R[0]; goto L_8001B7D0; }  /* 0x8001B798 j */
L_8001B7A0:;
    R[4] = R[0] + 9;  /* 0x8001B7A0 */
L_8001B7A4:;
    R[5] = R[0] + R[0];  /* 0x8001B7A4 */
    { R[31] = 0x8001B7B0u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B7A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B7A4; } }  /* 0x8001B7B0 */
    { R[31] = 0x8001B7C0u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B7B8 jal */
    R[4] = 0x8006u << 16;  /* 0x8001B7C0 */
    R[4] = R[4] - 10024;  /* 0x8001B7C4 */
    { R[5] = R[29] + 48; psx_bb(); goto L_8001B678; }  /* 0x8001B7C8 j */
L_8001B7D0:;
    R[31] = lw_(R[29] + 288);  /* 0x8001B7D0 */
    R[21] = lw_(R[29] + 284);  /* 0x8001B7D4 */
    R[20] = lw_(R[29] + 280);  /* 0x8001B7D8 */
    R[19] = lw_(R[29] + 276);  /* 0x8001B7DC */
    R[18] = lw_(R[29] + 272);  /* 0x8001B7E0 */
    R[17] = lw_(R[29] + 268);  /* 0x8001B7E4 */
    R[16] = lw_(R[29] + 264);  /* 0x8001B7E8 */
    { R[29] = R[29] + 296; psx_next = R[31]; return; }  /* 0x8001B7EC jr ra */
}

void f_8001B678(void) {
L_8001B678:;
    { R[31] = 0x8001B680u; R[6] = R[0] + 204; psx_next = 0x80030E18u; return; }  /* 0x8001B678 jal */
    R[4] = R[29] + 24;  /* 0x8001B680 */
    { R[31] = 0x8001B68Cu; R[5] = R[21] + R[0]; psx_next = 0x8001AD68u; return; }  /* 0x8001B684 jal */
    R[19] = 0x8006u << 16;  /* 0x8001B68C */
    R[18] = R[19] - 10024;  /* 0x8001B690 */
    R[16] = lw_(R[18] + 8);  /* 0x8001B694 */
    { uint32_t _c = ((int32_t)R[16] >= 0); R[17] = R[2] + R[0]; if (_c) { goto L_8001B6A8; } }  /* 0x8001B69C */
    R[16] = R[16] + 2047;  /* 0x8001B6A4 */
L_8001B6A8:;
    R[4] = R[17] + R[0];  /* 0x8001B6A8 */
    { R[31] = 0x8001B6B4u; R[16] = (uint32_t)((int32_t)R[16] >> 11); psx_next = 0x80041B2Cu; return; }  /* 0x8001B6AC jal */
    R[4] = R[2] + R[16];  /* 0x8001B6B4 */
    { R[31] = 0x8001B6C0u; R[5] = R[17] + R[0]; psx_next = 0x80041A28u; return; }  /* 0x8001B6B8 jal */
    R[4] = R[0] + 160;  /* 0x8001B6C0 */
    R[5] = R[17] + R[0];  /* 0x8001B6C4 */
    R[6] = R[0] + 6;  /* 0x8001B6C8 */
    R[2] = R[0] - 1;  /* 0x8001B6CC */
    R[7] = 0x8002u << 16;  /* 0x8001B6D0 */
    R[7] = R[7] - 18932;  /* 0x8001B6D4 */
    sh_(R[18] + 6, R[20]);  /* 0x8001B6D8 */
    sh_(R[18] + 4, R[0]);  /* 0x8001B6DC */
    sh_(R[19] + -10024, R[0]);  /* 0x8001B6E0 */
    { R[31] = 0x8001B6ECu; sw_(R[29] + 16, R[2]); psx_next = 0x8003E6CCu; return; }  /* 0x8001B6E4 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B6EC */
    { R[31] = 0x8001B6FCu; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B6F4 jal */
    R[16] = R[0] + 5;  /* 0x8001B6FC */
L_8001B700:;
    { R[31] = 0x8001B708u; psx_next = 0x8003EDE0u; return; }  /* 0x8001B700 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B708 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B72C; } }  /* 0x8001B70C */
    { R[31] = 0x8001B71Cu; R[5] = R[29] + 256; psx_next = 0x8003EA70u; return; }  /* 0x8001B714 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B71C */
    { psx_bb(); goto L_8001B700; }  /* 0x8001B724 j */
L_8001B72C:;
    R[2] = R[20] - 1;  /* 0x8001B72C */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x8001B730 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8001B7D0; } }  /* 0x8001B734 */
    R[2] = 0x8006u << 16;  /* 0x8001B73C */
    R[3] = R[2] - 10024;  /* 0x8001B740 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B744 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B784; } }  /* 0x8001B74C */
    R[4] = R[0] + 2;  /* 0x8001B754 */
L_8001B758:;
    R[2] = lh_(R[3] + 4);  /* 0x8001B758 */
    R[2] = R[2] << 16;  /* 0x8001B760 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B764 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B7A0; } }  /* 0x8001B768 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B770 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B758; } }  /* 0x8001B778 */
    R[4] = R[0] + 9;  /* 0x8001B780 */
L_8001B784:;
    R[5] = R[0] + R[0];  /* 0x8001B784 */
    { R[31] = 0x8001B790u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B788 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B784; } }  /* 0x8001B790 */
    { R[2] = R[0] + R[0]; goto L_8001B7D0; }  /* 0x8001B798 j */
L_8001B7A0:;
    R[4] = R[0] + 9;  /* 0x8001B7A0 */
L_8001B7A4:;
    R[5] = R[0] + R[0];  /* 0x8001B7A4 */
    { R[31] = 0x8001B7B0u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B7A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B7A4; } }  /* 0x8001B7B0 */
    { R[31] = 0x8001B7C0u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B7B8 jal */
    R[4] = 0x8006u << 16;  /* 0x8001B7C0 */
    R[4] = R[4] - 10024;  /* 0x8001B7C4 */
    { R[5] = R[29] + 48; psx_bb(); goto L_8001B678; }  /* 0x8001B7C8 j */
L_8001B7D0:;
    R[31] = lw_(R[29] + 288);  /* 0x8001B7D0 */
    R[21] = lw_(R[29] + 284);  /* 0x8001B7D4 */
    R[20] = lw_(R[29] + 280);  /* 0x8001B7D8 */
    R[19] = lw_(R[29] + 276);  /* 0x8001B7DC */
    R[18] = lw_(R[29] + 272);  /* 0x8001B7E0 */
    R[17] = lw_(R[29] + 268);  /* 0x8001B7E4 */
    R[16] = lw_(R[29] + 264);  /* 0x8001B7E8 */
    { R[29] = R[29] + 296; psx_next = R[31]; return; }  /* 0x8001B7EC jr ra */
}

void f_8001B680(void) {
    R[4] = R[29] + 24;  /* 0x8001B680 */
    { R[31] = 0x8001B68Cu; R[5] = R[21] + R[0]; psx_next = 0x8001AD68u; return; }  /* 0x8001B684 jal */
    R[19] = 0x8006u << 16;  /* 0x8001B68C */
    R[18] = R[19] - 10024;  /* 0x8001B690 */
    R[16] = lw_(R[18] + 8);  /* 0x8001B694 */
    { uint32_t _c = ((int32_t)R[16] >= 0); R[17] = R[2] + R[0]; if (_c) { goto L_8001B6A8; } }  /* 0x8001B69C */
    R[16] = R[16] + 2047;  /* 0x8001B6A4 */
L_8001B6A8:;
    R[4] = R[17] + R[0];  /* 0x8001B6A8 */
    { R[31] = 0x8001B6B4u; R[16] = (uint32_t)((int32_t)R[16] >> 11); psx_next = 0x80041B2Cu; return; }  /* 0x8001B6AC jal */
    R[4] = R[2] + R[16];  /* 0x8001B6B4 */
    { R[31] = 0x8001B6C0u; R[5] = R[17] + R[0]; psx_next = 0x80041A28u; return; }  /* 0x8001B6B8 jal */
    R[4] = R[0] + 160;  /* 0x8001B6C0 */
    R[5] = R[17] + R[0];  /* 0x8001B6C4 */
    R[6] = R[0] + 6;  /* 0x8001B6C8 */
    R[2] = R[0] - 1;  /* 0x8001B6CC */
    R[7] = 0x8002u << 16;  /* 0x8001B6D0 */
    R[7] = R[7] - 18932;  /* 0x8001B6D4 */
    sh_(R[18] + 6, R[20]);  /* 0x8001B6D8 */
    sh_(R[18] + 4, R[0]);  /* 0x8001B6DC */
    sh_(R[19] + -10024, R[0]);  /* 0x8001B6E0 */
    { R[31] = 0x8001B6ECu; sw_(R[29] + 16, R[2]); psx_next = 0x8003E6CCu; return; }  /* 0x8001B6E4 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B6EC */
    { R[31] = 0x8001B6FCu; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B6F4 jal */
    R[16] = R[0] + 5;  /* 0x8001B6FC */
L_8001B700:;
    { R[31] = 0x8001B708u; psx_next = 0x8003EDE0u; return; }  /* 0x8001B700 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B708 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B72C; } }  /* 0x8001B70C */
    { R[31] = 0x8001B71Cu; R[5] = R[29] + 256; psx_next = 0x8003EA70u; return; }  /* 0x8001B714 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B71C */
    { psx_bb(); goto L_8001B700; }  /* 0x8001B724 j */
L_8001B72C:;
    R[2] = R[20] - 1;  /* 0x8001B72C */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x8001B730 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8001B7D0; } }  /* 0x8001B734 */
    R[2] = 0x8006u << 16;  /* 0x8001B73C */
    R[3] = R[2] - 10024;  /* 0x8001B740 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B744 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B784; } }  /* 0x8001B74C */
    R[4] = R[0] + 2;  /* 0x8001B754 */
L_8001B758:;
    R[2] = lh_(R[3] + 4);  /* 0x8001B758 */
    R[2] = R[2] << 16;  /* 0x8001B760 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B764 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B7A0; } }  /* 0x8001B768 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B770 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B758; } }  /* 0x8001B778 */
    R[4] = R[0] + 9;  /* 0x8001B780 */
L_8001B784:;
    R[5] = R[0] + R[0];  /* 0x8001B784 */
    { R[31] = 0x8001B790u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B788 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B784; } }  /* 0x8001B790 */
    { R[2] = R[0] + R[0]; goto L_8001B7D0; }  /* 0x8001B798 j */
L_8001B7A0:;
    R[4] = R[0] + 9;  /* 0x8001B7A0 */
L_8001B7A4:;
    R[5] = R[0] + R[0];  /* 0x8001B7A4 */
    { R[31] = 0x8001B7B0u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B7A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B7A4; } }  /* 0x8001B7B0 */
    { R[31] = 0x8001B7C0u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B7B8 jal */
    R[4] = 0x8006u << 16;  /* 0x8001B7C0 */
    R[4] = R[4] - 10024;  /* 0x8001B7C4 */
    { R[5] = R[29] + 48; psx_next = 0x8001B678u; return; }  /* 0x8001B7C8 j extern */
L_8001B7D0:;
    R[31] = lw_(R[29] + 288);  /* 0x8001B7D0 */
    R[21] = lw_(R[29] + 284);  /* 0x8001B7D4 */
    R[20] = lw_(R[29] + 280);  /* 0x8001B7D8 */
    R[19] = lw_(R[29] + 276);  /* 0x8001B7DC */
    R[18] = lw_(R[29] + 272);  /* 0x8001B7E0 */
    R[17] = lw_(R[29] + 268);  /* 0x8001B7E4 */
    R[16] = lw_(R[29] + 264);  /* 0x8001B7E8 */
    { R[29] = R[29] + 296; psx_next = R[31]; return; }  /* 0x8001B7EC jr ra */
}

void f_8001B68C(void) {
    R[19] = 0x8006u << 16;  /* 0x8001B68C */
    R[18] = R[19] - 10024;  /* 0x8001B690 */
    R[16] = lw_(R[18] + 8);  /* 0x8001B694 */
    { uint32_t _c = ((int32_t)R[16] >= 0); R[17] = R[2] + R[0]; if (_c) { goto L_8001B6A8; } }  /* 0x8001B69C */
    R[16] = R[16] + 2047;  /* 0x8001B6A4 */
L_8001B6A8:;
    R[4] = R[17] + R[0];  /* 0x8001B6A8 */
    { R[31] = 0x8001B6B4u; R[16] = (uint32_t)((int32_t)R[16] >> 11); psx_next = 0x80041B2Cu; return; }  /* 0x8001B6AC jal */
    R[4] = R[2] + R[16];  /* 0x8001B6B4 */
    { R[31] = 0x8001B6C0u; R[5] = R[17] + R[0]; psx_next = 0x80041A28u; return; }  /* 0x8001B6B8 jal */
    R[4] = R[0] + 160;  /* 0x8001B6C0 */
    R[5] = R[17] + R[0];  /* 0x8001B6C4 */
    R[6] = R[0] + 6;  /* 0x8001B6C8 */
    R[2] = R[0] - 1;  /* 0x8001B6CC */
    R[7] = 0x8002u << 16;  /* 0x8001B6D0 */
    R[7] = R[7] - 18932;  /* 0x8001B6D4 */
    sh_(R[18] + 6, R[20]);  /* 0x8001B6D8 */
    sh_(R[18] + 4, R[0]);  /* 0x8001B6DC */
    sh_(R[19] + -10024, R[0]);  /* 0x8001B6E0 */
    { R[31] = 0x8001B6ECu; sw_(R[29] + 16, R[2]); psx_next = 0x8003E6CCu; return; }  /* 0x8001B6E4 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B6EC */
    { R[31] = 0x8001B6FCu; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B6F4 jal */
    R[16] = R[0] + 5;  /* 0x8001B6FC */
L_8001B700:;
    { R[31] = 0x8001B708u; psx_next = 0x8003EDE0u; return; }  /* 0x8001B700 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B708 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B72C; } }  /* 0x8001B70C */
    { R[31] = 0x8001B71Cu; R[5] = R[29] + 256; psx_next = 0x8003EA70u; return; }  /* 0x8001B714 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B71C */
    { psx_bb(); goto L_8001B700; }  /* 0x8001B724 j */
L_8001B72C:;
    R[2] = R[20] - 1;  /* 0x8001B72C */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x8001B730 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8001B7D0; } }  /* 0x8001B734 */
    R[2] = 0x8006u << 16;  /* 0x8001B73C */
    R[3] = R[2] - 10024;  /* 0x8001B740 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B744 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B784; } }  /* 0x8001B74C */
    R[4] = R[0] + 2;  /* 0x8001B754 */
L_8001B758:;
    R[2] = lh_(R[3] + 4);  /* 0x8001B758 */
    R[2] = R[2] << 16;  /* 0x8001B760 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B764 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B7A0; } }  /* 0x8001B768 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B770 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B758; } }  /* 0x8001B778 */
    R[4] = R[0] + 9;  /* 0x8001B780 */
L_8001B784:;
    R[5] = R[0] + R[0];  /* 0x8001B784 */
    { R[31] = 0x8001B790u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B788 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B784; } }  /* 0x8001B790 */
    { R[2] = R[0] + R[0]; goto L_8001B7D0; }  /* 0x8001B798 j */
L_8001B7A0:;
    R[4] = R[0] + 9;  /* 0x8001B7A0 */
L_8001B7A4:;
    R[5] = R[0] + R[0];  /* 0x8001B7A4 */
    { R[31] = 0x8001B7B0u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B7A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B7A4; } }  /* 0x8001B7B0 */
    { R[31] = 0x8001B7C0u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B7B8 jal */
    R[4] = 0x8006u << 16;  /* 0x8001B7C0 */
    R[4] = R[4] - 10024;  /* 0x8001B7C4 */
    { R[5] = R[29] + 48; psx_next = 0x8001B678u; return; }  /* 0x8001B7C8 j extern */
L_8001B7D0:;
    R[31] = lw_(R[29] + 288);  /* 0x8001B7D0 */
    R[21] = lw_(R[29] + 284);  /* 0x8001B7D4 */
    R[20] = lw_(R[29] + 280);  /* 0x8001B7D8 */
    R[19] = lw_(R[29] + 276);  /* 0x8001B7DC */
    R[18] = lw_(R[29] + 272);  /* 0x8001B7E0 */
    R[17] = lw_(R[29] + 268);  /* 0x8001B7E4 */
    R[16] = lw_(R[29] + 264);  /* 0x8001B7E8 */
    { R[29] = R[29] + 296; psx_next = R[31]; return; }  /* 0x8001B7EC jr ra */
}

void f_8001B6B4(void) {
    R[4] = R[2] + R[16];  /* 0x8001B6B4 */
    { R[31] = 0x8001B6C0u; R[5] = R[17] + R[0]; psx_next = 0x80041A28u; return; }  /* 0x8001B6B8 jal */
    R[4] = R[0] + 160;  /* 0x8001B6C0 */
    R[5] = R[17] + R[0];  /* 0x8001B6C4 */
    R[6] = R[0] + 6;  /* 0x8001B6C8 */
    R[2] = R[0] - 1;  /* 0x8001B6CC */
    R[7] = 0x8002u << 16;  /* 0x8001B6D0 */
    R[7] = R[7] - 18932;  /* 0x8001B6D4 */
    sh_(R[18] + 6, R[20]);  /* 0x8001B6D8 */
    sh_(R[18] + 4, R[0]);  /* 0x8001B6DC */
    sh_(R[19] + -10024, R[0]);  /* 0x8001B6E0 */
    { R[31] = 0x8001B6ECu; sw_(R[29] + 16, R[2]); psx_next = 0x8003E6CCu; return; }  /* 0x8001B6E4 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B6EC */
    { R[31] = 0x8001B6FCu; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B6F4 jal */
    R[16] = R[0] + 5;  /* 0x8001B6FC */
L_8001B700:;
    { R[31] = 0x8001B708u; psx_next = 0x8003EDE0u; return; }  /* 0x8001B700 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B708 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B72C; } }  /* 0x8001B70C */
    { R[31] = 0x8001B71Cu; R[5] = R[29] + 256; psx_next = 0x8003EA70u; return; }  /* 0x8001B714 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B71C */
    { psx_bb(); goto L_8001B700; }  /* 0x8001B724 j */
L_8001B72C:;
    R[2] = R[20] - 1;  /* 0x8001B72C */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x8001B730 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8001B7D0; } }  /* 0x8001B734 */
    R[2] = 0x8006u << 16;  /* 0x8001B73C */
    R[3] = R[2] - 10024;  /* 0x8001B740 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B744 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B784; } }  /* 0x8001B74C */
    R[4] = R[0] + 2;  /* 0x8001B754 */
L_8001B758:;
    R[2] = lh_(R[3] + 4);  /* 0x8001B758 */
    R[2] = R[2] << 16;  /* 0x8001B760 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B764 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B7A0; } }  /* 0x8001B768 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B770 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B758; } }  /* 0x8001B778 */
    R[4] = R[0] + 9;  /* 0x8001B780 */
L_8001B784:;
    R[5] = R[0] + R[0];  /* 0x8001B784 */
    { R[31] = 0x8001B790u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B788 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B784; } }  /* 0x8001B790 */
    { R[2] = R[0] + R[0]; goto L_8001B7D0; }  /* 0x8001B798 j */
L_8001B7A0:;
    R[4] = R[0] + 9;  /* 0x8001B7A0 */
L_8001B7A4:;
    R[5] = R[0] + R[0];  /* 0x8001B7A4 */
    { R[31] = 0x8001B7B0u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B7A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B7A4; } }  /* 0x8001B7B0 */
    { R[31] = 0x8001B7C0u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B7B8 jal */
    R[4] = 0x8006u << 16;  /* 0x8001B7C0 */
    R[4] = R[4] - 10024;  /* 0x8001B7C4 */
    { R[5] = R[29] + 48; psx_next = 0x8001B678u; return; }  /* 0x8001B7C8 j extern */
L_8001B7D0:;
    R[31] = lw_(R[29] + 288);  /* 0x8001B7D0 */
    R[21] = lw_(R[29] + 284);  /* 0x8001B7D4 */
    R[20] = lw_(R[29] + 280);  /* 0x8001B7D8 */
    R[19] = lw_(R[29] + 276);  /* 0x8001B7DC */
    R[18] = lw_(R[29] + 272);  /* 0x8001B7E0 */
    R[17] = lw_(R[29] + 268);  /* 0x8001B7E4 */
    R[16] = lw_(R[29] + 264);  /* 0x8001B7E8 */
    { R[29] = R[29] + 296; psx_next = R[31]; return; }  /* 0x8001B7EC jr ra */
}

void f_8001B6C0(void) {
    R[4] = R[0] + 160;  /* 0x8001B6C0 */
    R[5] = R[17] + R[0];  /* 0x8001B6C4 */
    R[6] = R[0] + 6;  /* 0x8001B6C8 */
    R[2] = R[0] - 1;  /* 0x8001B6CC */
    R[7] = 0x8002u << 16;  /* 0x8001B6D0 */
    R[7] = R[7] - 18932;  /* 0x8001B6D4 */
    sh_(R[18] + 6, R[20]);  /* 0x8001B6D8 */
    sh_(R[18] + 4, R[0]);  /* 0x8001B6DC */
    sh_(R[19] + -10024, R[0]);  /* 0x8001B6E0 */
    { R[31] = 0x8001B6ECu; sw_(R[29] + 16, R[2]); psx_next = 0x8003E6CCu; return; }  /* 0x8001B6E4 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B6EC */
    { R[31] = 0x8001B6FCu; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B6F4 jal */
    R[16] = R[0] + 5;  /* 0x8001B6FC */
L_8001B700:;
    { R[31] = 0x8001B708u; psx_next = 0x8003EDE0u; return; }  /* 0x8001B700 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B708 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B72C; } }  /* 0x8001B70C */
    { R[31] = 0x8001B71Cu; R[5] = R[29] + 256; psx_next = 0x8003EA70u; return; }  /* 0x8001B714 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B71C */
    { psx_bb(); goto L_8001B700; }  /* 0x8001B724 j */
L_8001B72C:;
    R[2] = R[20] - 1;  /* 0x8001B72C */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x8001B730 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8001B7D0; } }  /* 0x8001B734 */
    R[2] = 0x8006u << 16;  /* 0x8001B73C */
    R[3] = R[2] - 10024;  /* 0x8001B740 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B744 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B784; } }  /* 0x8001B74C */
    R[4] = R[0] + 2;  /* 0x8001B754 */
L_8001B758:;
    R[2] = lh_(R[3] + 4);  /* 0x8001B758 */
    R[2] = R[2] << 16;  /* 0x8001B760 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B764 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B7A0; } }  /* 0x8001B768 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B770 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B758; } }  /* 0x8001B778 */
    R[4] = R[0] + 9;  /* 0x8001B780 */
L_8001B784:;
    R[5] = R[0] + R[0];  /* 0x8001B784 */
    { R[31] = 0x8001B790u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B788 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B784; } }  /* 0x8001B790 */
    { R[2] = R[0] + R[0]; goto L_8001B7D0; }  /* 0x8001B798 j */
L_8001B7A0:;
    R[4] = R[0] + 9;  /* 0x8001B7A0 */
L_8001B7A4:;
    R[5] = R[0] + R[0];  /* 0x8001B7A4 */
    { R[31] = 0x8001B7B0u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B7A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B7A4; } }  /* 0x8001B7B0 */
    { R[31] = 0x8001B7C0u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B7B8 jal */
    R[4] = 0x8006u << 16;  /* 0x8001B7C0 */
    R[4] = R[4] - 10024;  /* 0x8001B7C4 */
    { R[5] = R[29] + 48; psx_next = 0x8001B678u; return; }  /* 0x8001B7C8 j extern */
L_8001B7D0:;
    R[31] = lw_(R[29] + 288);  /* 0x8001B7D0 */
    R[21] = lw_(R[29] + 284);  /* 0x8001B7D4 */
    R[20] = lw_(R[29] + 280);  /* 0x8001B7D8 */
    R[19] = lw_(R[29] + 276);  /* 0x8001B7DC */
    R[18] = lw_(R[29] + 272);  /* 0x8001B7E0 */
    R[17] = lw_(R[29] + 268);  /* 0x8001B7E4 */
    R[16] = lw_(R[29] + 264);  /* 0x8001B7E8 */
    { R[29] = R[29] + 296; psx_next = R[31]; return; }  /* 0x8001B7EC jr ra */
}

void f_8001B6EC(void) {
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B6EC */
    { R[31] = 0x8001B6FCu; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B6F4 jal */
    R[16] = R[0] + 5;  /* 0x8001B6FC */
L_8001B700:;
    { R[31] = 0x8001B708u; psx_next = 0x8003EDE0u; return; }  /* 0x8001B700 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B708 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B72C; } }  /* 0x8001B70C */
    { R[31] = 0x8001B71Cu; R[5] = R[29] + 256; psx_next = 0x8003EA70u; return; }  /* 0x8001B714 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B71C */
    { psx_bb(); goto L_8001B700; }  /* 0x8001B724 j */
L_8001B72C:;
    R[2] = R[20] - 1;  /* 0x8001B72C */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x8001B730 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8001B7D0; } }  /* 0x8001B734 */
    R[2] = 0x8006u << 16;  /* 0x8001B73C */
    R[3] = R[2] - 10024;  /* 0x8001B740 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B744 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B784; } }  /* 0x8001B74C */
    R[4] = R[0] + 2;  /* 0x8001B754 */
L_8001B758:;
    R[2] = lh_(R[3] + 4);  /* 0x8001B758 */
    R[2] = R[2] << 16;  /* 0x8001B760 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B764 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B7A0; } }  /* 0x8001B768 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B770 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B758; } }  /* 0x8001B778 */
    R[4] = R[0] + 9;  /* 0x8001B780 */
L_8001B784:;
    R[5] = R[0] + R[0];  /* 0x8001B784 */
    { R[31] = 0x8001B790u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B788 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B784; } }  /* 0x8001B790 */
    { R[2] = R[0] + R[0]; goto L_8001B7D0; }  /* 0x8001B798 j */
L_8001B7A0:;
    R[4] = R[0] + 9;  /* 0x8001B7A0 */
L_8001B7A4:;
    R[5] = R[0] + R[0];  /* 0x8001B7A4 */
    { R[31] = 0x8001B7B0u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B7A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B7A4; } }  /* 0x8001B7B0 */
    { R[31] = 0x8001B7C0u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B7B8 jal */
    R[4] = 0x8006u << 16;  /* 0x8001B7C0 */
    R[4] = R[4] - 10024;  /* 0x8001B7C4 */
    { R[5] = R[29] + 48; psx_next = 0x8001B678u; return; }  /* 0x8001B7C8 j extern */
L_8001B7D0:;
    R[31] = lw_(R[29] + 288);  /* 0x8001B7D0 */
    R[21] = lw_(R[29] + 284);  /* 0x8001B7D4 */
    R[20] = lw_(R[29] + 280);  /* 0x8001B7D8 */
    R[19] = lw_(R[29] + 276);  /* 0x8001B7DC */
    R[18] = lw_(R[29] + 272);  /* 0x8001B7E0 */
    R[17] = lw_(R[29] + 268);  /* 0x8001B7E4 */
    R[16] = lw_(R[29] + 264);  /* 0x8001B7E8 */
    { R[29] = R[29] + 296; psx_next = R[31]; return; }  /* 0x8001B7EC jr ra */
}

void f_8001B6FC(void) {
    R[16] = R[0] + 5;  /* 0x8001B6FC */
L_8001B700:;
    { R[31] = 0x8001B708u; psx_next = 0x8003EDE0u; return; }  /* 0x8001B700 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B708 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B72C; } }  /* 0x8001B70C */
    { R[31] = 0x8001B71Cu; R[5] = R[29] + 256; psx_next = 0x8003EA70u; return; }  /* 0x8001B714 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B71C */
    { psx_bb(); goto L_8001B700; }  /* 0x8001B724 j */
L_8001B72C:;
    R[2] = R[20] - 1;  /* 0x8001B72C */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x8001B730 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8001B7D0; } }  /* 0x8001B734 */
    R[2] = 0x8006u << 16;  /* 0x8001B73C */
    R[3] = R[2] - 10024;  /* 0x8001B740 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B744 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B784; } }  /* 0x8001B74C */
    R[4] = R[0] + 2;  /* 0x8001B754 */
L_8001B758:;
    R[2] = lh_(R[3] + 4);  /* 0x8001B758 */
    R[2] = R[2] << 16;  /* 0x8001B760 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B764 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B7A0; } }  /* 0x8001B768 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B770 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B758; } }  /* 0x8001B778 */
    R[4] = R[0] + 9;  /* 0x8001B780 */
L_8001B784:;
    R[5] = R[0] + R[0];  /* 0x8001B784 */
    { R[31] = 0x8001B790u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B788 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B784; } }  /* 0x8001B790 */
    { R[2] = R[0] + R[0]; goto L_8001B7D0; }  /* 0x8001B798 j */
L_8001B7A0:;
    R[4] = R[0] + 9;  /* 0x8001B7A0 */
L_8001B7A4:;
    R[5] = R[0] + R[0];  /* 0x8001B7A4 */
    { R[31] = 0x8001B7B0u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B7A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B7A4; } }  /* 0x8001B7B0 */
    { R[31] = 0x8001B7C0u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B7B8 jal */
    R[4] = 0x8006u << 16;  /* 0x8001B7C0 */
    R[4] = R[4] - 10024;  /* 0x8001B7C4 */
    { R[5] = R[29] + 48; psx_next = 0x8001B678u; return; }  /* 0x8001B7C8 j extern */
L_8001B7D0:;
    R[31] = lw_(R[29] + 288);  /* 0x8001B7D0 */
    R[21] = lw_(R[29] + 284);  /* 0x8001B7D4 */
    R[20] = lw_(R[29] + 280);  /* 0x8001B7D8 */
    R[19] = lw_(R[29] + 276);  /* 0x8001B7DC */
    R[18] = lw_(R[29] + 272);  /* 0x8001B7E0 */
    R[17] = lw_(R[29] + 268);  /* 0x8001B7E4 */
    R[16] = lw_(R[29] + 264);  /* 0x8001B7E8 */
    { R[29] = R[29] + 296; psx_next = R[31]; return; }  /* 0x8001B7EC jr ra */
}

void f_8001B700(void) {
L_8001B700:;
    { R[31] = 0x8001B708u; psx_next = 0x8003EDE0u; return; }  /* 0x8001B700 jal */
    R[2] = R[2] & 0x20;  /* 0x8001B708 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B72C; } }  /* 0x8001B70C */
    { R[31] = 0x8001B71Cu; R[5] = R[29] + 256; psx_next = 0x8003EA70u; return; }  /* 0x8001B714 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B71C */
    { psx_bb(); goto L_8001B700; }  /* 0x8001B724 j */
L_8001B72C:;
    R[2] = R[20] - 1;  /* 0x8001B72C */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x8001B730 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8001B7D0; } }  /* 0x8001B734 */
    R[2] = 0x8006u << 16;  /* 0x8001B73C */
    R[3] = R[2] - 10024;  /* 0x8001B740 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B744 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B784; } }  /* 0x8001B74C */
    R[4] = R[0] + 2;  /* 0x8001B754 */
L_8001B758:;
    R[2] = lh_(R[3] + 4);  /* 0x8001B758 */
    R[2] = R[2] << 16;  /* 0x8001B760 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B764 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B7A0; } }  /* 0x8001B768 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B770 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B758; } }  /* 0x8001B778 */
    R[4] = R[0] + 9;  /* 0x8001B780 */
L_8001B784:;
    R[5] = R[0] + R[0];  /* 0x8001B784 */
    { R[31] = 0x8001B790u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B788 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B784; } }  /* 0x8001B790 */
    { R[2] = R[0] + R[0]; goto L_8001B7D0; }  /* 0x8001B798 j */
L_8001B7A0:;
    R[4] = R[0] + 9;  /* 0x8001B7A0 */
L_8001B7A4:;
    R[5] = R[0] + R[0];  /* 0x8001B7A4 */
    { R[31] = 0x8001B7B0u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B7A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B7A4; } }  /* 0x8001B7B0 */
    { R[31] = 0x8001B7C0u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B7B8 jal */
    R[4] = 0x8006u << 16;  /* 0x8001B7C0 */
    R[4] = R[4] - 10024;  /* 0x8001B7C4 */
    { R[5] = R[29] + 48; psx_next = 0x8001B678u; return; }  /* 0x8001B7C8 j extern */
L_8001B7D0:;
    R[31] = lw_(R[29] + 288);  /* 0x8001B7D0 */
    R[21] = lw_(R[29] + 284);  /* 0x8001B7D4 */
    R[20] = lw_(R[29] + 280);  /* 0x8001B7D8 */
    R[19] = lw_(R[29] + 276);  /* 0x8001B7DC */
    R[18] = lw_(R[29] + 272);  /* 0x8001B7E0 */
    R[17] = lw_(R[29] + 268);  /* 0x8001B7E4 */
    R[16] = lw_(R[29] + 264);  /* 0x8001B7E8 */
    { R[29] = R[29] + 296; psx_next = R[31]; return; }  /* 0x8001B7EC jr ra */
}

void f_8001B708(void) {
    R[2] = R[2] & 0x20;  /* 0x8001B708 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] - 1; if (_c) { goto L_8001B72C; } }  /* 0x8001B70C */
    { R[31] = 0x8001B71Cu; R[5] = R[29] + 256; psx_next = 0x8003EA70u; return; }  /* 0x8001B714 jal */
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B71C */
    { psx_next = 0x8001B700u; return; }  /* 0x8001B724 j extern */
L_8001B72C:;
    R[2] = R[20] - 1;  /* 0x8001B72C */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x8001B730 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8001B7D0; } }  /* 0x8001B734 */
    R[2] = 0x8006u << 16;  /* 0x8001B73C */
    R[3] = R[2] - 10024;  /* 0x8001B740 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B744 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B784; } }  /* 0x8001B74C */
    R[4] = R[0] + 2;  /* 0x8001B754 */
L_8001B758:;
    R[2] = lh_(R[3] + 4);  /* 0x8001B758 */
    R[2] = R[2] << 16;  /* 0x8001B760 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B764 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B7A0; } }  /* 0x8001B768 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B770 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B758; } }  /* 0x8001B778 */
    R[4] = R[0] + 9;  /* 0x8001B780 */
L_8001B784:;
    R[5] = R[0] + R[0];  /* 0x8001B784 */
    { R[31] = 0x8001B790u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B788 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B784; } }  /* 0x8001B790 */
    { R[2] = R[0] + R[0]; goto L_8001B7D0; }  /* 0x8001B798 j */
L_8001B7A0:;
    R[4] = R[0] + 9;  /* 0x8001B7A0 */
L_8001B7A4:;
    R[5] = R[0] + R[0];  /* 0x8001B7A4 */
    { R[31] = 0x8001B7B0u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B7A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B7A4; } }  /* 0x8001B7B0 */
    { R[31] = 0x8001B7C0u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B7B8 jal */
    R[4] = 0x8006u << 16;  /* 0x8001B7C0 */
    R[4] = R[4] - 10024;  /* 0x8001B7C4 */
    { R[5] = R[29] + 48; psx_next = 0x8001B678u; return; }  /* 0x8001B7C8 j extern */
L_8001B7D0:;
    R[31] = lw_(R[29] + 288);  /* 0x8001B7D0 */
    R[21] = lw_(R[29] + 284);  /* 0x8001B7D4 */
    R[20] = lw_(R[29] + 280);  /* 0x8001B7D8 */
    R[19] = lw_(R[29] + 276);  /* 0x8001B7DC */
    R[18] = lw_(R[29] + 272);  /* 0x8001B7E0 */
    R[17] = lw_(R[29] + 268);  /* 0x8001B7E4 */
    R[16] = lw_(R[29] + 264);  /* 0x8001B7E8 */
    { R[29] = R[29] + 296; psx_next = R[31]; return; }  /* 0x8001B7EC jr ra */
}

void f_8001B71C(void) {
    { uint32_t _c = (R[2] == R[16]); R[4] = R[0] + 9; if (_c) { goto L_8001B7A4; } }  /* 0x8001B71C */
    { psx_next = 0x8001B700u; return; }  /* 0x8001B724 j extern */
    R[2] = R[20] - 1;  /* 0x8001B72C */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x8001B730 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8001B7D0; } }  /* 0x8001B734 */
    R[2] = 0x8006u << 16;  /* 0x8001B73C */
    R[3] = R[2] - 10024;  /* 0x8001B740 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B744 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 9; if (_c) { goto L_8001B784; } }  /* 0x8001B74C */
    R[4] = R[0] + 2;  /* 0x8001B754 */
L_8001B758:;
    R[2] = lh_(R[3] + 4);  /* 0x8001B758 */
    R[2] = R[2] << 16;  /* 0x8001B760 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8001B764 */
    { uint32_t _c = (R[2] == R[4]); if (_c) { goto L_8001B7A0; } }  /* 0x8001B768 */
    R[2] = lh_(R[3] + 4);  /* 0x8001B770 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_bb(); goto L_8001B758; } }  /* 0x8001B778 */
    R[4] = R[0] + 9;  /* 0x8001B780 */
L_8001B784:;
    R[5] = R[0] + R[0];  /* 0x8001B784 */
    { R[31] = 0x8001B790u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B788 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B784; } }  /* 0x8001B790 */
    { R[2] = R[0] + R[0]; goto L_8001B7D0; }  /* 0x8001B798 j */
L_8001B7A0:;
    R[4] = R[0] + 9;  /* 0x8001B7A0 */
L_8001B7A4:;
    R[5] = R[0] + R[0];  /* 0x8001B7A4 */
    { R[31] = 0x8001B7B0u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B7A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B7A4; } }  /* 0x8001B7B0 */
    { R[31] = 0x8001B7C0u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B7B8 jal */
    R[4] = 0x8006u << 16;  /* 0x8001B7C0 */
    R[4] = R[4] - 10024;  /* 0x8001B7C4 */
    { R[5] = R[29] + 48; psx_next = 0x8001B678u; return; }  /* 0x8001B7C8 j extern */
L_8001B7D0:;
    R[31] = lw_(R[29] + 288);  /* 0x8001B7D0 */
    R[21] = lw_(R[29] + 284);  /* 0x8001B7D4 */
    R[20] = lw_(R[29] + 280);  /* 0x8001B7D8 */
    R[19] = lw_(R[29] + 276);  /* 0x8001B7DC */
    R[18] = lw_(R[29] + 272);  /* 0x8001B7E0 */
    R[17] = lw_(R[29] + 268);  /* 0x8001B7E4 */
    R[16] = lw_(R[29] + 264);  /* 0x8001B7E8 */
    { R[29] = R[29] + 296; psx_next = R[31]; return; }  /* 0x8001B7EC jr ra */
}

void f_8001B784(void) {
L_8001B784:;
    R[5] = R[0] + R[0];  /* 0x8001B784 */
    { R[31] = 0x8001B790u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B788 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B784; } }  /* 0x8001B790 */
    { R[2] = R[0] + R[0]; goto L_8001B7D0; }  /* 0x8001B798 j */
    R[4] = R[0] + 9;  /* 0x8001B7A0 */
L_8001B7A4:;
    R[5] = R[0] + R[0];  /* 0x8001B7A4 */
    { R[31] = 0x8001B7B0u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B7A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B7A4; } }  /* 0x8001B7B0 */
    { R[31] = 0x8001B7C0u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B7B8 jal */
    R[4] = 0x8006u << 16;  /* 0x8001B7C0 */
    R[4] = R[4] - 10024;  /* 0x8001B7C4 */
    { R[5] = R[29] + 48; psx_next = 0x8001B678u; return; }  /* 0x8001B7C8 j extern */
L_8001B7D0:;
    R[31] = lw_(R[29] + 288);  /* 0x8001B7D0 */
    R[21] = lw_(R[29] + 284);  /* 0x8001B7D4 */
    R[20] = lw_(R[29] + 280);  /* 0x8001B7D8 */
    R[19] = lw_(R[29] + 276);  /* 0x8001B7DC */
    R[18] = lw_(R[29] + 272);  /* 0x8001B7E0 */
    R[17] = lw_(R[29] + 268);  /* 0x8001B7E4 */
    R[16] = lw_(R[29] + 264);  /* 0x8001B7E8 */
    { R[29] = R[29] + 296; psx_next = R[31]; return; }  /* 0x8001B7EC jr ra */
}

void f_8001B790(void) {
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_next = 0x8001B784u; return; } }  /* 0x8001B790 b extern */
    { R[2] = R[0] + R[0]; goto L_8001B7D0; }  /* 0x8001B798 j */
    R[4] = R[0] + 9;  /* 0x8001B7A0 */
L_8001B7A4:;
    R[5] = R[0] + R[0];  /* 0x8001B7A4 */
    { R[31] = 0x8001B7B0u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B7A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B7A4; } }  /* 0x8001B7B0 */
    { R[31] = 0x8001B7C0u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B7B8 jal */
    R[4] = 0x8006u << 16;  /* 0x8001B7C0 */
    R[4] = R[4] - 10024;  /* 0x8001B7C4 */
    { R[5] = R[29] + 48; psx_next = 0x8001B678u; return; }  /* 0x8001B7C8 j extern */
L_8001B7D0:;
    R[31] = lw_(R[29] + 288);  /* 0x8001B7D0 */
    R[21] = lw_(R[29] + 284);  /* 0x8001B7D4 */
    R[20] = lw_(R[29] + 280);  /* 0x8001B7D8 */
    R[19] = lw_(R[29] + 276);  /* 0x8001B7DC */
    R[18] = lw_(R[29] + 272);  /* 0x8001B7E0 */
    R[17] = lw_(R[29] + 268);  /* 0x8001B7E4 */
    R[16] = lw_(R[29] + 264);  /* 0x8001B7E8 */
    { R[29] = R[29] + 296; psx_next = R[31]; return; }  /* 0x8001B7EC jr ra */
}

void f_8001B7A4(void) {
L_8001B7A4:;
    R[5] = R[0] + R[0];  /* 0x8001B7A4 */
    { R[31] = 0x8001B7B0u; R[6] = R[5] + R[0]; psx_next = 0x80041CA8u; return; }  /* 0x8001B7A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_bb(); goto L_8001B7A4; } }  /* 0x8001B7B0 */
    { R[31] = 0x8001B7C0u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B7B8 jal */
    R[4] = 0x8006u << 16;  /* 0x8001B7C0 */
    R[4] = R[4] - 10024;  /* 0x8001B7C4 */
    { R[5] = R[29] + 48; psx_next = 0x8001B678u; return; }  /* 0x8001B7C8 j extern */
    R[31] = lw_(R[29] + 288);  /* 0x8001B7D0 */
    R[21] = lw_(R[29] + 284);  /* 0x8001B7D4 */
    R[20] = lw_(R[29] + 280);  /* 0x8001B7D8 */
    R[19] = lw_(R[29] + 276);  /* 0x8001B7DC */
    R[18] = lw_(R[29] + 272);  /* 0x8001B7E0 */
    R[17] = lw_(R[29] + 268);  /* 0x8001B7E4 */
    R[16] = lw_(R[29] + 264);  /* 0x8001B7E8 */
    { R[29] = R[29] + 296; psx_next = R[31]; return; }  /* 0x8001B7EC jr ra */
}

void f_8001B7B0(void) {
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 9; if (_c) { psx_next = 0x8001B7A4u; return; } }  /* 0x8001B7B0 b extern */
    { R[31] = 0x8001B7C0u; R[4] = R[0] + 120; psx_next = 0x80037D98u; return; }  /* 0x8001B7B8 jal */
    R[4] = 0x8006u << 16;  /* 0x8001B7C0 */
    R[4] = R[4] - 10024;  /* 0x8001B7C4 */
    { R[5] = R[29] + 48; psx_next = 0x8001B678u; return; }  /* 0x8001B7C8 j extern */
    R[31] = lw_(R[29] + 288);  /* 0x8001B7D0 */
    R[21] = lw_(R[29] + 284);  /* 0x8001B7D4 */
    R[20] = lw_(R[29] + 280);  /* 0x8001B7D8 */
    R[19] = lw_(R[29] + 276);  /* 0x8001B7DC */
    R[18] = lw_(R[29] + 272);  /* 0x8001B7E0 */
    R[17] = lw_(R[29] + 268);  /* 0x8001B7E4 */
    R[16] = lw_(R[29] + 264);  /* 0x8001B7E8 */
    { R[29] = R[29] + 296; psx_next = R[31]; return; }  /* 0x8001B7EC jr ra */
}

void f_8001B7C0(void) {
    R[4] = 0x8006u << 16;  /* 0x8001B7C0 */
    R[4] = R[4] - 10024;  /* 0x8001B7C4 */
    { R[5] = R[29] + 48; psx_next = 0x8001B678u; return; }  /* 0x8001B7C8 j extern */
    R[31] = lw_(R[29] + 288);  /* 0x8001B7D0 */
    R[21] = lw_(R[29] + 284);  /* 0x8001B7D4 */
    R[20] = lw_(R[29] + 280);  /* 0x8001B7D8 */
    R[19] = lw_(R[29] + 276);  /* 0x8001B7DC */
    R[18] = lw_(R[29] + 272);  /* 0x8001B7E0 */
    R[17] = lw_(R[29] + 268);  /* 0x8001B7E4 */
    R[16] = lw_(R[29] + 264);  /* 0x8001B7E8 */
    { R[29] = R[29] + 296; psx_next = R[31]; return; }  /* 0x8001B7EC jr ra */
}

void f_8001B7F4(void) {
    R[29] = R[29] - 24;  /* 0x8001B7F4 */
    sw_(R[29] + 16, R[31]);  /* 0x8001B7F8 */
    { R[31] = 0x8001B804u; psx_next = 0x8003E218u; return; }  /* 0x8001B7FC jal */
    { R[31] = 0x8001B80Cu; psx_next = 0x80039D8Cu; return; }  /* 0x8001B804 jal */
    R[31] = lw_(R[29] + 16);  /* 0x8001B80C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001B814 jr ra */
}

void f_8001B804(void) {
    { R[31] = 0x8001B80Cu; psx_next = 0x80039D8Cu; return; }  /* 0x8001B804 jal */
    R[31] = lw_(R[29] + 16);  /* 0x8001B80C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001B814 jr ra */
}

void f_8001B80C(void) {
    R[31] = lw_(R[29] + 16);  /* 0x8001B80C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001B814 jr ra */
}

void f_8001B81C(void) {
    psx_break(1024);  /* 0x8001B81C */
    { psx_next = R[31]; return; }  /* 0x8001B820 jr ra */
}

void f_8001B828(void) {
    R[29] = R[29] - 40;  /* 0x8001B828 */
    sw_(R[29] + 28, R[19]);  /* 0x8001B82C */
    R[19] = R[4] + R[0];  /* 0x8001B830 */
    sw_(R[29] + 24, R[18]);  /* 0x8001B834 */
    R[18] = 0x8001u << 16;  /* 0x8001B838 */
    sw_(R[29] + 20, R[17]);  /* 0x8001B83C */
    R[17] = R[0] - 1;  /* 0x8001B840 */
    sw_(R[29] + 32, R[31]);  /* 0x8001B844 */
    sw_(R[29] + 16, R[16]);  /* 0x8001B848 */
L_8001B84C:;
    R[4] = R[18] + 28900;  /* 0x8001B84C */
    R[5] = R[0] + 1;  /* 0x8001B850 */
    { R[31] = 0x8001B85Cu; R[6] = R[0] + R[0]; psx_next = 0x80039B88u; return; }  /* 0x8001B854 jal */
    R[4] = R[0] + R[0];  /* 0x8001B85C */
    { R[31] = 0x8001B868u; R[16] = R[2] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B860 jal */
    { uint32_t _c = (R[16] == R[17]); if (_c) { psx_bb(); goto L_8001B84C; } }  /* 0x8001B868 */
    { R[31] = 0x8001B878u; R[4] = R[19] + R[0]; psx_next = 0x80031038u; return; }  /* 0x8001B870 jal */
    R[4] = R[16] + R[0];  /* 0x8001B878 */
    R[5] = R[19] + R[0];  /* 0x8001B87C */
    { R[31] = 0x8001B888u; R[6] = R[2] + R[0]; psx_next = 0x80039E70u; return; }  /* 0x8001B880 jal */
    { R[31] = 0x8001B890u; R[4] = R[16] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001B888 jal */
    R[31] = lw_(R[29] + 32);  /* 0x8001B890 */
    R[19] = lw_(R[29] + 28);  /* 0x8001B894 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B898 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B89C */
    R[16] = lw_(R[29] + 16);  /* 0x8001B8A0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B8A4 jr ra */
}

void f_8001B84C(void) {
L_8001B84C:;
    R[4] = R[18] + 28900;  /* 0x8001B84C */
    R[5] = R[0] + 1;  /* 0x8001B850 */
    { R[31] = 0x8001B85Cu; R[6] = R[0] + R[0]; psx_next = 0x80039B88u; return; }  /* 0x8001B854 jal */
    R[4] = R[0] + R[0];  /* 0x8001B85C */
    { R[31] = 0x8001B868u; R[16] = R[2] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B860 jal */
    { uint32_t _c = (R[16] == R[17]); if (_c) { psx_bb(); goto L_8001B84C; } }  /* 0x8001B868 */
    { R[31] = 0x8001B878u; R[4] = R[19] + R[0]; psx_next = 0x80031038u; return; }  /* 0x8001B870 jal */
    R[4] = R[16] + R[0];  /* 0x8001B878 */
    R[5] = R[19] + R[0];  /* 0x8001B87C */
    { R[31] = 0x8001B888u; R[6] = R[2] + R[0]; psx_next = 0x80039E70u; return; }  /* 0x8001B880 jal */
    { R[31] = 0x8001B890u; R[4] = R[16] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001B888 jal */
    R[31] = lw_(R[29] + 32);  /* 0x8001B890 */
    R[19] = lw_(R[29] + 28);  /* 0x8001B894 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B898 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B89C */
    R[16] = lw_(R[29] + 16);  /* 0x8001B8A0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B8A4 jr ra */
}

void f_8001B85C(void) {
    R[4] = R[0] + R[0];  /* 0x8001B85C */
    { R[31] = 0x8001B868u; R[16] = R[2] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B860 jal */
    { uint32_t _c = (R[16] == R[17]); if (_c) { psx_next = 0x8001B84Cu; return; } }  /* 0x8001B868 b extern */
    { R[31] = 0x8001B878u; R[4] = R[19] + R[0]; psx_next = 0x80031038u; return; }  /* 0x8001B870 jal */
    R[4] = R[16] + R[0];  /* 0x8001B878 */
    R[5] = R[19] + R[0];  /* 0x8001B87C */
    { R[31] = 0x8001B888u; R[6] = R[2] + R[0]; psx_next = 0x80039E70u; return; }  /* 0x8001B880 jal */
    { R[31] = 0x8001B890u; R[4] = R[16] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001B888 jal */
    R[31] = lw_(R[29] + 32);  /* 0x8001B890 */
    R[19] = lw_(R[29] + 28);  /* 0x8001B894 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B898 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B89C */
    R[16] = lw_(R[29] + 16);  /* 0x8001B8A0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B8A4 jr ra */
}

void f_8001B868(void) {
    { uint32_t _c = (R[16] == R[17]); if (_c) { psx_next = 0x8001B84Cu; return; } }  /* 0x8001B868 b extern */
    { R[31] = 0x8001B878u; R[4] = R[19] + R[0]; psx_next = 0x80031038u; return; }  /* 0x8001B870 jal */
    R[4] = R[16] + R[0];  /* 0x8001B878 */
    R[5] = R[19] + R[0];  /* 0x8001B87C */
    { R[31] = 0x8001B888u; R[6] = R[2] + R[0]; psx_next = 0x80039E70u; return; }  /* 0x8001B880 jal */
    { R[31] = 0x8001B890u; R[4] = R[16] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001B888 jal */
    R[31] = lw_(R[29] + 32);  /* 0x8001B890 */
    R[19] = lw_(R[29] + 28);  /* 0x8001B894 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B898 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B89C */
    R[16] = lw_(R[29] + 16);  /* 0x8001B8A0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B8A4 jr ra */
}

void f_8001B878(void) {
    R[4] = R[16] + R[0];  /* 0x8001B878 */
    R[5] = R[19] + R[0];  /* 0x8001B87C */
    { R[31] = 0x8001B888u; R[6] = R[2] + R[0]; psx_next = 0x80039E70u; return; }  /* 0x8001B880 jal */
    { R[31] = 0x8001B890u; R[4] = R[16] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001B888 jal */
    R[31] = lw_(R[29] + 32);  /* 0x8001B890 */
    R[19] = lw_(R[29] + 28);  /* 0x8001B894 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B898 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B89C */
    R[16] = lw_(R[29] + 16);  /* 0x8001B8A0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B8A4 jr ra */
}

void f_8001B888(void) {
    { R[31] = 0x8001B890u; R[4] = R[16] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001B888 jal */
    R[31] = lw_(R[29] + 32);  /* 0x8001B890 */
    R[19] = lw_(R[29] + 28);  /* 0x8001B894 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B898 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B89C */
    R[16] = lw_(R[29] + 16);  /* 0x8001B8A0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B8A4 jr ra */
}

void f_8001B890(void) {
    R[31] = lw_(R[29] + 32);  /* 0x8001B890 */
    R[19] = lw_(R[29] + 28);  /* 0x8001B894 */
    R[18] = lw_(R[29] + 24);  /* 0x8001B898 */
    R[17] = lw_(R[29] + 20);  /* 0x8001B89C */
    R[16] = lw_(R[29] + 16);  /* 0x8001B8A0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8001B8A4 jr ra */
}

void f_8001B8AC(void) {
    R[29] = R[29] - 176;  /* 0x8001B8AC */
    sw_(R[29] + 168, R[22]);  /* 0x8001B8B0 */
    R[22] = R[4] + R[0];  /* 0x8001B8B4 */
    sw_(R[29] + 156, R[19]);  /* 0x8001B8B8 */
    R[19] = R[5] + R[0];  /* 0x8001B8BC */
    sw_(R[29] + 160, R[20]);  /* 0x8001B8C0 */
    R[20] = R[6] + R[0];  /* 0x8001B8C4 */
    sw_(R[29] + 148, R[17]);  /* 0x8001B8C8 */
    R[17] = R[7] + R[0];  /* 0x8001B8CC */
    R[2] = 0x8006u << 16;  /* 0x8001B8D0 */
    R[5] = R[0] + R[0];  /* 0x8001B8D4 */
    sw_(R[29] + 172, R[31]);  /* 0x8001B8D8 */
    sw_(R[29] + 164, R[21]);  /* 0x8001B8DC */
    sw_(R[29] + 152, R[18]);  /* 0x8001B8E0 */
    sw_(R[29] + 144, R[16]);  /* 0x8001B8E4 */
    sh_(R[2] + -10048, R[0]);  /* 0x8001B8E8 */
    { R[31] = 0x8001B8F4u; R[6] = R[5] + R[0]; psx_next = 0x80039B88u; return; }  /* 0x8001B8EC jal */
    R[4] = R[0] + R[0];  /* 0x8001B8F4 */
    { R[31] = 0x8001B900u; R[18] = R[2] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B8F8 jal */
    R[16] = R[0] - 1;  /* 0x8001B900 */
    { uint32_t _c = (R[18] != R[16]); R[5] = R[0] + R[0]; if (_c) { goto L_8001B930; } }  /* 0x8001B904 */
    R[4] = R[29] + 16;  /* 0x8001B90C */
    R[5] = 0x8001u << 16;  /* 0x8001B910 */
    R[5] = R[5] + 28904;  /* 0x8001B914 */
    { R[31] = 0x8001B920u; R[6] = R[22] + R[0]; psx_next = 0x80031BF8u; return; }  /* 0x8001B918 jal */
    { R[31] = 0x8001B928u; R[4] = R[29] + 16; psx_next = 0x8001B828u; return; }  /* 0x8001B920 jal */
    { R[31] = 0x8001B930u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8001B928 jal */
L_8001B930:;
    R[4] = R[18] + R[0];  /* 0x8001B930 */
    { R[31] = 0x8001B93Cu; R[6] = R[0] + 2; psx_next = 0x80039BB8u; return; }  /* 0x8001B934 jal */
    R[3] = R[2] - R[20];  /* 0x8001B93C */
    R[2] = (R[3] < R[17]);  /* 0x8001B940 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8001B954; } }  /* 0x8001B944 */
    { uint32_t _c = (R[17] != R[16]); R[4] = R[18] + R[0]; if (_c) { goto L_8001B95C; } }  /* 0x8001B94C */
L_8001B954:;
    R[17] = R[3] + R[0];  /* 0x8001B954 */
    R[4] = R[18] + R[0];  /* 0x8001B958 */
L_8001B95C:;
    R[5] = R[20] + R[0];  /* 0x8001B95C */
    { R[31] = 0x8001B968u; R[6] = R[0] + R[0]; psx_next = 0x80039BB8u; return; }  /* 0x8001B960 jal */
    R[20] = R[17] + R[0];  /* 0x8001B968 */
    { uint32_t _c = (R[20] == R[0]); R[21] = R[0] | 0xFFFE; if (_c) { goto L_8001B9A8; } }  /* 0x8001B96C */
L_8001B974:;
    R[2] = (R[21] < R[17]);  /* 0x8001B974 */
    { uint32_t _c = (R[2] == R[0]); R[16] = R[0] | 0xFFFE; if (_c) { goto L_8001B988; } }  /* 0x8001B978 */
    { R[17] = R[17] - R[16]; goto L_8001B990; }  /* 0x8001B980 j */
L_8001B988:;
    R[16] = R[17] + R[0];  /* 0x8001B988 */
    R[17] = R[0] + R[0];  /* 0x8001B98C */
L_8001B990:;
    R[4] = R[18] + R[0];  /* 0x8001B990 */
    R[5] = R[19] + R[0];  /* 0x8001B994 */
    { R[31] = 0x8001B9A0u; R[6] = R[16] + R[0]; psx_next = 0x80039D98u; return; }  /* 0x8001B998 jal */
    { uint32_t _c = (R[17] != R[0]); R[19] = R[19] + R[16]; if (_c) { psx_bb(); goto L_8001B974; } }  /* 0x8001B9A0 */
L_8001B9A8:;
    R[4] = 0x8001u << 16;  /* 0x8001B9A8 */
    R[4] = R[4] + 28924;  /* 0x8001B9AC */
    R[5] = R[22] + R[0];  /* 0x8001B9B0 */
    { R[31] = 0x8001B9BCu; R[6] = R[20] + R[0]; psx_next = 0x80031258u; return; }  /* 0x8001B9B4 jal */
    { R[31] = 0x8001B9C4u; R[4] = R[18] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001B9BC jal */
    R[3] = 0x8006u << 16;  /* 0x8001B9C4 */
    R[2] = R[0] + 1;  /* 0x8001B9C8 */
    sh_(R[3] + -10048, R[2]);  /* 0x8001B9CC */
    R[2] = R[20] + R[0];  /* 0x8001B9D0 */
    R[31] = lw_(R[29] + 172);  /* 0x8001B9D4 */
    R[22] = lw_(R[29] + 168);  /* 0x8001B9D8 */
    R[21] = lw_(R[29] + 164);  /* 0x8001B9DC */
    R[20] = lw_(R[29] + 160);  /* 0x8001B9E0 */
    R[19] = lw_(R[29] + 156);  /* 0x8001B9E4 */
    R[18] = lw_(R[29] + 152);  /* 0x8001B9E8 */
    R[17] = lw_(R[29] + 148);  /* 0x8001B9EC */
    R[16] = lw_(R[29] + 144);  /* 0x8001B9F0 */
    { R[29] = R[29] + 176; psx_next = R[31]; return; }  /* 0x8001B9F4 jr ra */
}

void f_8001B8F4(void) {
    R[4] = R[0] + R[0];  /* 0x8001B8F4 */
    { R[31] = 0x8001B900u; R[18] = R[2] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8001B8F8 jal */
    R[16] = R[0] - 1;  /* 0x8001B900 */
    { uint32_t _c = (R[18] != R[16]); R[5] = R[0] + R[0]; if (_c) { goto L_8001B930; } }  /* 0x8001B904 */
    R[4] = R[29] + 16;  /* 0x8001B90C */
    R[5] = 0x8001u << 16;  /* 0x8001B910 */
    R[5] = R[5] + 28904;  /* 0x8001B914 */
    { R[31] = 0x8001B920u; R[6] = R[22] + R[0]; psx_next = 0x80031BF8u; return; }  /* 0x8001B918 jal */
    { R[31] = 0x8001B928u; R[4] = R[29] + 16; psx_next = 0x8001B828u; return; }  /* 0x8001B920 jal */
    { R[31] = 0x8001B930u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8001B928 jal */
L_8001B930:;
    R[4] = R[18] + R[0];  /* 0x8001B930 */
    { R[31] = 0x8001B93Cu; R[6] = R[0] + 2; psx_next = 0x80039BB8u; return; }  /* 0x8001B934 jal */
    R[3] = R[2] - R[20];  /* 0x8001B93C */
    R[2] = (R[3] < R[17]);  /* 0x8001B940 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8001B954; } }  /* 0x8001B944 */
    { uint32_t _c = (R[17] != R[16]); R[4] = R[18] + R[0]; if (_c) { goto L_8001B95C; } }  /* 0x8001B94C */
L_8001B954:;
    R[17] = R[3] + R[0];  /* 0x8001B954 */
    R[4] = R[18] + R[0];  /* 0x8001B958 */
L_8001B95C:;
    R[5] = R[20] + R[0];  /* 0x8001B95C */
    { R[31] = 0x8001B968u; R[6] = R[0] + R[0]; psx_next = 0x80039BB8u; return; }  /* 0x8001B960 jal */
    R[20] = R[17] + R[0];  /* 0x8001B968 */
    { uint32_t _c = (R[20] == R[0]); R[21] = R[0] | 0xFFFE; if (_c) { goto L_8001B9A8; } }  /* 0x8001B96C */
L_8001B974:;
    R[2] = (R[21] < R[17]);  /* 0x8001B974 */
    { uint32_t _c = (R[2] == R[0]); R[16] = R[0] | 0xFFFE; if (_c) { goto L_8001B988; } }  /* 0x8001B978 */
    { R[17] = R[17] - R[16]; goto L_8001B990; }  /* 0x8001B980 j */
L_8001B988:;
    R[16] = R[17] + R[0];  /* 0x8001B988 */
    R[17] = R[0] + R[0];  /* 0x8001B98C */
L_8001B990:;
    R[4] = R[18] + R[0];  /* 0x8001B990 */
    R[5] = R[19] + R[0];  /* 0x8001B994 */
    { R[31] = 0x8001B9A0u; R[6] = R[16] + R[0]; psx_next = 0x80039D98u; return; }  /* 0x8001B998 jal */
    { uint32_t _c = (R[17] != R[0]); R[19] = R[19] + R[16]; if (_c) { psx_bb(); goto L_8001B974; } }  /* 0x8001B9A0 */
L_8001B9A8:;
    R[4] = 0x8001u << 16;  /* 0x8001B9A8 */
    R[4] = R[4] + 28924;  /* 0x8001B9AC */
    R[5] = R[22] + R[0];  /* 0x8001B9B0 */
    { R[31] = 0x8001B9BCu; R[6] = R[20] + R[0]; psx_next = 0x80031258u; return; }  /* 0x8001B9B4 jal */
    { R[31] = 0x8001B9C4u; R[4] = R[18] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001B9BC jal */
    R[3] = 0x8006u << 16;  /* 0x8001B9C4 */
    R[2] = R[0] + 1;  /* 0x8001B9C8 */
    sh_(R[3] + -10048, R[2]);  /* 0x8001B9CC */
    R[2] = R[20] + R[0];  /* 0x8001B9D0 */
    R[31] = lw_(R[29] + 172);  /* 0x8001B9D4 */
    R[22] = lw_(R[29] + 168);  /* 0x8001B9D8 */
    R[21] = lw_(R[29] + 164);  /* 0x8001B9DC */
    R[20] = lw_(R[29] + 160);  /* 0x8001B9E0 */
    R[19] = lw_(R[29] + 156);  /* 0x8001B9E4 */
    R[18] = lw_(R[29] + 152);  /* 0x8001B9E8 */
    R[17] = lw_(R[29] + 148);  /* 0x8001B9EC */
    R[16] = lw_(R[29] + 144);  /* 0x8001B9F0 */
    { R[29] = R[29] + 176; psx_next = R[31]; return; }  /* 0x8001B9F4 jr ra */
}

void f_8001B900(void) {
    R[16] = R[0] - 1;  /* 0x8001B900 */
    { uint32_t _c = (R[18] != R[16]); R[5] = R[0] + R[0]; if (_c) { goto L_8001B930; } }  /* 0x8001B904 */
    R[4] = R[29] + 16;  /* 0x8001B90C */
    R[5] = 0x8001u << 16;  /* 0x8001B910 */
    R[5] = R[5] + 28904;  /* 0x8001B914 */
    { R[31] = 0x8001B920u; R[6] = R[22] + R[0]; psx_next = 0x80031BF8u; return; }  /* 0x8001B918 jal */
    { R[31] = 0x8001B928u; R[4] = R[29] + 16; psx_next = 0x8001B828u; return; }  /* 0x8001B920 jal */
    { R[31] = 0x8001B930u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8001B928 jal */
L_8001B930:;
    R[4] = R[18] + R[0];  /* 0x8001B930 */
    { R[31] = 0x8001B93Cu; R[6] = R[0] + 2; psx_next = 0x80039BB8u; return; }  /* 0x8001B934 jal */
    R[3] = R[2] - R[20];  /* 0x8001B93C */
    R[2] = (R[3] < R[17]);  /* 0x8001B940 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8001B954; } }  /* 0x8001B944 */
    { uint32_t _c = (R[17] != R[16]); R[4] = R[18] + R[0]; if (_c) { goto L_8001B95C; } }  /* 0x8001B94C */
L_8001B954:;
    R[17] = R[3] + R[0];  /* 0x8001B954 */
    R[4] = R[18] + R[0];  /* 0x8001B958 */
L_8001B95C:;
    R[5] = R[20] + R[0];  /* 0x8001B95C */
    { R[31] = 0x8001B968u; R[6] = R[0] + R[0]; psx_next = 0x80039BB8u; return; }  /* 0x8001B960 jal */
    R[20] = R[17] + R[0];  /* 0x8001B968 */
    { uint32_t _c = (R[20] == R[0]); R[21] = R[0] | 0xFFFE; if (_c) { goto L_8001B9A8; } }  /* 0x8001B96C */
L_8001B974:;
    R[2] = (R[21] < R[17]);  /* 0x8001B974 */
    { uint32_t _c = (R[2] == R[0]); R[16] = R[0] | 0xFFFE; if (_c) { goto L_8001B988; } }  /* 0x8001B978 */
    { R[17] = R[17] - R[16]; goto L_8001B990; }  /* 0x8001B980 j */
L_8001B988:;
    R[16] = R[17] + R[0];  /* 0x8001B988 */
    R[17] = R[0] + R[0];  /* 0x8001B98C */
L_8001B990:;
    R[4] = R[18] + R[0];  /* 0x8001B990 */
    R[5] = R[19] + R[0];  /* 0x8001B994 */
    { R[31] = 0x8001B9A0u; R[6] = R[16] + R[0]; psx_next = 0x80039D98u; return; }  /* 0x8001B998 jal */
    { uint32_t _c = (R[17] != R[0]); R[19] = R[19] + R[16]; if (_c) { psx_bb(); goto L_8001B974; } }  /* 0x8001B9A0 */
L_8001B9A8:;
    R[4] = 0x8001u << 16;  /* 0x8001B9A8 */
    R[4] = R[4] + 28924;  /* 0x8001B9AC */
    R[5] = R[22] + R[0];  /* 0x8001B9B0 */
    { R[31] = 0x8001B9BCu; R[6] = R[20] + R[0]; psx_next = 0x80031258u; return; }  /* 0x8001B9B4 jal */
    { R[31] = 0x8001B9C4u; R[4] = R[18] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001B9BC jal */
    R[3] = 0x8006u << 16;  /* 0x8001B9C4 */
    R[2] = R[0] + 1;  /* 0x8001B9C8 */
    sh_(R[3] + -10048, R[2]);  /* 0x8001B9CC */
    R[2] = R[20] + R[0];  /* 0x8001B9D0 */
    R[31] = lw_(R[29] + 172);  /* 0x8001B9D4 */
    R[22] = lw_(R[29] + 168);  /* 0x8001B9D8 */
    R[21] = lw_(R[29] + 164);  /* 0x8001B9DC */
    R[20] = lw_(R[29] + 160);  /* 0x8001B9E0 */
    R[19] = lw_(R[29] + 156);  /* 0x8001B9E4 */
    R[18] = lw_(R[29] + 152);  /* 0x8001B9E8 */
    R[17] = lw_(R[29] + 148);  /* 0x8001B9EC */
    R[16] = lw_(R[29] + 144);  /* 0x8001B9F0 */
    { R[29] = R[29] + 176; psx_next = R[31]; return; }  /* 0x8001B9F4 jr ra */
}

void f_8001B920(void) {
    { R[31] = 0x8001B928u; R[4] = R[29] + 16; psx_next = 0x8001B828u; return; }  /* 0x8001B920 jal */
    { R[31] = 0x8001B930u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8001B928 jal */
    R[4] = R[18] + R[0];  /* 0x8001B930 */
    { R[31] = 0x8001B93Cu; R[6] = R[0] + 2; psx_next = 0x80039BB8u; return; }  /* 0x8001B934 jal */
    R[3] = R[2] - R[20];  /* 0x8001B93C */
    R[2] = (R[3] < R[17]);  /* 0x8001B940 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8001B954; } }  /* 0x8001B944 */
    { uint32_t _c = (R[17] != R[16]); R[4] = R[18] + R[0]; if (_c) { goto L_8001B95C; } }  /* 0x8001B94C */
L_8001B954:;
    R[17] = R[3] + R[0];  /* 0x8001B954 */
    R[4] = R[18] + R[0];  /* 0x8001B958 */
L_8001B95C:;
    R[5] = R[20] + R[0];  /* 0x8001B95C */
    { R[31] = 0x8001B968u; R[6] = R[0] + R[0]; psx_next = 0x80039BB8u; return; }  /* 0x8001B960 jal */
    R[20] = R[17] + R[0];  /* 0x8001B968 */
    { uint32_t _c = (R[20] == R[0]); R[21] = R[0] | 0xFFFE; if (_c) { goto L_8001B9A8; } }  /* 0x8001B96C */
L_8001B974:;
    R[2] = (R[21] < R[17]);  /* 0x8001B974 */
    { uint32_t _c = (R[2] == R[0]); R[16] = R[0] | 0xFFFE; if (_c) { goto L_8001B988; } }  /* 0x8001B978 */
    { R[17] = R[17] - R[16]; goto L_8001B990; }  /* 0x8001B980 j */
L_8001B988:;
    R[16] = R[17] + R[0];  /* 0x8001B988 */
    R[17] = R[0] + R[0];  /* 0x8001B98C */
L_8001B990:;
    R[4] = R[18] + R[0];  /* 0x8001B990 */
    R[5] = R[19] + R[0];  /* 0x8001B994 */
    { R[31] = 0x8001B9A0u; R[6] = R[16] + R[0]; psx_next = 0x80039D98u; return; }  /* 0x8001B998 jal */
    { uint32_t _c = (R[17] != R[0]); R[19] = R[19] + R[16]; if (_c) { psx_bb(); goto L_8001B974; } }  /* 0x8001B9A0 */
L_8001B9A8:;
    R[4] = 0x8001u << 16;  /* 0x8001B9A8 */
    R[4] = R[4] + 28924;  /* 0x8001B9AC */
    R[5] = R[22] + R[0];  /* 0x8001B9B0 */
    { R[31] = 0x8001B9BCu; R[6] = R[20] + R[0]; psx_next = 0x80031258u; return; }  /* 0x8001B9B4 jal */
    { R[31] = 0x8001B9C4u; R[4] = R[18] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001B9BC jal */
    R[3] = 0x8006u << 16;  /* 0x8001B9C4 */
    R[2] = R[0] + 1;  /* 0x8001B9C8 */
    sh_(R[3] + -10048, R[2]);  /* 0x8001B9CC */
    R[2] = R[20] + R[0];  /* 0x8001B9D0 */
    R[31] = lw_(R[29] + 172);  /* 0x8001B9D4 */
    R[22] = lw_(R[29] + 168);  /* 0x8001B9D8 */
    R[21] = lw_(R[29] + 164);  /* 0x8001B9DC */
    R[20] = lw_(R[29] + 160);  /* 0x8001B9E0 */
    R[19] = lw_(R[29] + 156);  /* 0x8001B9E4 */
    R[18] = lw_(R[29] + 152);  /* 0x8001B9E8 */
    R[17] = lw_(R[29] + 148);  /* 0x8001B9EC */
    R[16] = lw_(R[29] + 144);  /* 0x8001B9F0 */
    { R[29] = R[29] + 176; psx_next = R[31]; return; }  /* 0x8001B9F4 jr ra */
}

void f_8001B928(void) {
    { R[31] = 0x8001B930u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8001B928 jal */
    R[4] = R[18] + R[0];  /* 0x8001B930 */
    { R[31] = 0x8001B93Cu; R[6] = R[0] + 2; psx_next = 0x80039BB8u; return; }  /* 0x8001B934 jal */
    R[3] = R[2] - R[20];  /* 0x8001B93C */
    R[2] = (R[3] < R[17]);  /* 0x8001B940 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8001B954; } }  /* 0x8001B944 */
    { uint32_t _c = (R[17] != R[16]); R[4] = R[18] + R[0]; if (_c) { goto L_8001B95C; } }  /* 0x8001B94C */
L_8001B954:;
    R[17] = R[3] + R[0];  /* 0x8001B954 */
    R[4] = R[18] + R[0];  /* 0x8001B958 */
L_8001B95C:;
    R[5] = R[20] + R[0];  /* 0x8001B95C */
    { R[31] = 0x8001B968u; R[6] = R[0] + R[0]; psx_next = 0x80039BB8u; return; }  /* 0x8001B960 jal */
    R[20] = R[17] + R[0];  /* 0x8001B968 */
    { uint32_t _c = (R[20] == R[0]); R[21] = R[0] | 0xFFFE; if (_c) { goto L_8001B9A8; } }  /* 0x8001B96C */
L_8001B974:;
    R[2] = (R[21] < R[17]);  /* 0x8001B974 */
    { uint32_t _c = (R[2] == R[0]); R[16] = R[0] | 0xFFFE; if (_c) { goto L_8001B988; } }  /* 0x8001B978 */
    { R[17] = R[17] - R[16]; goto L_8001B990; }  /* 0x8001B980 j */
L_8001B988:;
    R[16] = R[17] + R[0];  /* 0x8001B988 */
    R[17] = R[0] + R[0];  /* 0x8001B98C */
L_8001B990:;
    R[4] = R[18] + R[0];  /* 0x8001B990 */
    R[5] = R[19] + R[0];  /* 0x8001B994 */
    { R[31] = 0x8001B9A0u; R[6] = R[16] + R[0]; psx_next = 0x80039D98u; return; }  /* 0x8001B998 jal */
    { uint32_t _c = (R[17] != R[0]); R[19] = R[19] + R[16]; if (_c) { psx_bb(); goto L_8001B974; } }  /* 0x8001B9A0 */
L_8001B9A8:;
    R[4] = 0x8001u << 16;  /* 0x8001B9A8 */
    R[4] = R[4] + 28924;  /* 0x8001B9AC */
    R[5] = R[22] + R[0];  /* 0x8001B9B0 */
    { R[31] = 0x8001B9BCu; R[6] = R[20] + R[0]; psx_next = 0x80031258u; return; }  /* 0x8001B9B4 jal */
    { R[31] = 0x8001B9C4u; R[4] = R[18] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001B9BC jal */
    R[3] = 0x8006u << 16;  /* 0x8001B9C4 */
    R[2] = R[0] + 1;  /* 0x8001B9C8 */
    sh_(R[3] + -10048, R[2]);  /* 0x8001B9CC */
    R[2] = R[20] + R[0];  /* 0x8001B9D0 */
    R[31] = lw_(R[29] + 172);  /* 0x8001B9D4 */
    R[22] = lw_(R[29] + 168);  /* 0x8001B9D8 */
    R[21] = lw_(R[29] + 164);  /* 0x8001B9DC */
    R[20] = lw_(R[29] + 160);  /* 0x8001B9E0 */
    R[19] = lw_(R[29] + 156);  /* 0x8001B9E4 */
    R[18] = lw_(R[29] + 152);  /* 0x8001B9E8 */
    R[17] = lw_(R[29] + 148);  /* 0x8001B9EC */
    R[16] = lw_(R[29] + 144);  /* 0x8001B9F0 */
    { R[29] = R[29] + 176; psx_next = R[31]; return; }  /* 0x8001B9F4 jr ra */
}

void f_8001B930(void) {
    R[4] = R[18] + R[0];  /* 0x8001B930 */
    { R[31] = 0x8001B93Cu; R[6] = R[0] + 2; psx_next = 0x80039BB8u; return; }  /* 0x8001B934 jal */
    R[3] = R[2] - R[20];  /* 0x8001B93C */
    R[2] = (R[3] < R[17]);  /* 0x8001B940 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8001B954; } }  /* 0x8001B944 */
    { uint32_t _c = (R[17] != R[16]); R[4] = R[18] + R[0]; if (_c) { goto L_8001B95C; } }  /* 0x8001B94C */
L_8001B954:;
    R[17] = R[3] + R[0];  /* 0x8001B954 */
    R[4] = R[18] + R[0];  /* 0x8001B958 */
L_8001B95C:;
    R[5] = R[20] + R[0];  /* 0x8001B95C */
    { R[31] = 0x8001B968u; R[6] = R[0] + R[0]; psx_next = 0x80039BB8u; return; }  /* 0x8001B960 jal */
    R[20] = R[17] + R[0];  /* 0x8001B968 */
    { uint32_t _c = (R[20] == R[0]); R[21] = R[0] | 0xFFFE; if (_c) { goto L_8001B9A8; } }  /* 0x8001B96C */
L_8001B974:;
    R[2] = (R[21] < R[17]);  /* 0x8001B974 */
    { uint32_t _c = (R[2] == R[0]); R[16] = R[0] | 0xFFFE; if (_c) { goto L_8001B988; } }  /* 0x8001B978 */
    { R[17] = R[17] - R[16]; goto L_8001B990; }  /* 0x8001B980 j */
L_8001B988:;
    R[16] = R[17] + R[0];  /* 0x8001B988 */
    R[17] = R[0] + R[0];  /* 0x8001B98C */
L_8001B990:;
    R[4] = R[18] + R[0];  /* 0x8001B990 */
    R[5] = R[19] + R[0];  /* 0x8001B994 */
    { R[31] = 0x8001B9A0u; R[6] = R[16] + R[0]; psx_next = 0x80039D98u; return; }  /* 0x8001B998 jal */
    { uint32_t _c = (R[17] != R[0]); R[19] = R[19] + R[16]; if (_c) { psx_bb(); goto L_8001B974; } }  /* 0x8001B9A0 */
L_8001B9A8:;
    R[4] = 0x8001u << 16;  /* 0x8001B9A8 */
    R[4] = R[4] + 28924;  /* 0x8001B9AC */
    R[5] = R[22] + R[0];  /* 0x8001B9B0 */
    { R[31] = 0x8001B9BCu; R[6] = R[20] + R[0]; psx_next = 0x80031258u; return; }  /* 0x8001B9B4 jal */
    { R[31] = 0x8001B9C4u; R[4] = R[18] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001B9BC jal */
    R[3] = 0x8006u << 16;  /* 0x8001B9C4 */
    R[2] = R[0] + 1;  /* 0x8001B9C8 */
    sh_(R[3] + -10048, R[2]);  /* 0x8001B9CC */
    R[2] = R[20] + R[0];  /* 0x8001B9D0 */
    R[31] = lw_(R[29] + 172);  /* 0x8001B9D4 */
    R[22] = lw_(R[29] + 168);  /* 0x8001B9D8 */
    R[21] = lw_(R[29] + 164);  /* 0x8001B9DC */
    R[20] = lw_(R[29] + 160);  /* 0x8001B9E0 */
    R[19] = lw_(R[29] + 156);  /* 0x8001B9E4 */
    R[18] = lw_(R[29] + 152);  /* 0x8001B9E8 */
    R[17] = lw_(R[29] + 148);  /* 0x8001B9EC */
    R[16] = lw_(R[29] + 144);  /* 0x8001B9F0 */
    { R[29] = R[29] + 176; psx_next = R[31]; return; }  /* 0x8001B9F4 jr ra */
}

void f_8001B93C(void) {
    R[3] = R[2] - R[20];  /* 0x8001B93C */
    R[2] = (R[3] < R[17]);  /* 0x8001B940 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8001B954; } }  /* 0x8001B944 */
    { uint32_t _c = (R[17] != R[16]); R[4] = R[18] + R[0]; if (_c) { goto L_8001B95C; } }  /* 0x8001B94C */
L_8001B954:;
    R[17] = R[3] + R[0];  /* 0x8001B954 */
    R[4] = R[18] + R[0];  /* 0x8001B958 */
L_8001B95C:;
    R[5] = R[20] + R[0];  /* 0x8001B95C */
    { R[31] = 0x8001B968u; R[6] = R[0] + R[0]; psx_next = 0x80039BB8u; return; }  /* 0x8001B960 jal */
    R[20] = R[17] + R[0];  /* 0x8001B968 */
    { uint32_t _c = (R[20] == R[0]); R[21] = R[0] | 0xFFFE; if (_c) { goto L_8001B9A8; } }  /* 0x8001B96C */
L_8001B974:;
    R[2] = (R[21] < R[17]);  /* 0x8001B974 */
    { uint32_t _c = (R[2] == R[0]); R[16] = R[0] | 0xFFFE; if (_c) { goto L_8001B988; } }  /* 0x8001B978 */
    { R[17] = R[17] - R[16]; goto L_8001B990; }  /* 0x8001B980 j */
L_8001B988:;
    R[16] = R[17] + R[0];  /* 0x8001B988 */
    R[17] = R[0] + R[0];  /* 0x8001B98C */
L_8001B990:;
    R[4] = R[18] + R[0];  /* 0x8001B990 */
    R[5] = R[19] + R[0];  /* 0x8001B994 */
    { R[31] = 0x8001B9A0u; R[6] = R[16] + R[0]; psx_next = 0x80039D98u; return; }  /* 0x8001B998 jal */
    { uint32_t _c = (R[17] != R[0]); R[19] = R[19] + R[16]; if (_c) { psx_bb(); goto L_8001B974; } }  /* 0x8001B9A0 */
L_8001B9A8:;
    R[4] = 0x8001u << 16;  /* 0x8001B9A8 */
    R[4] = R[4] + 28924;  /* 0x8001B9AC */
    R[5] = R[22] + R[0];  /* 0x8001B9B0 */
    { R[31] = 0x8001B9BCu; R[6] = R[20] + R[0]; psx_next = 0x80031258u; return; }  /* 0x8001B9B4 jal */
    { R[31] = 0x8001B9C4u; R[4] = R[18] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001B9BC jal */
    R[3] = 0x8006u << 16;  /* 0x8001B9C4 */
    R[2] = R[0] + 1;  /* 0x8001B9C8 */
    sh_(R[3] + -10048, R[2]);  /* 0x8001B9CC */
    R[2] = R[20] + R[0];  /* 0x8001B9D0 */
    R[31] = lw_(R[29] + 172);  /* 0x8001B9D4 */
    R[22] = lw_(R[29] + 168);  /* 0x8001B9D8 */
    R[21] = lw_(R[29] + 164);  /* 0x8001B9DC */
    R[20] = lw_(R[29] + 160);  /* 0x8001B9E0 */
    R[19] = lw_(R[29] + 156);  /* 0x8001B9E4 */
    R[18] = lw_(R[29] + 152);  /* 0x8001B9E8 */
    R[17] = lw_(R[29] + 148);  /* 0x8001B9EC */
    R[16] = lw_(R[29] + 144);  /* 0x8001B9F0 */
    { R[29] = R[29] + 176; psx_next = R[31]; return; }  /* 0x8001B9F4 jr ra */
}

void f_8001B968(void) {
    R[20] = R[17] + R[0];  /* 0x8001B968 */
    { uint32_t _c = (R[20] == R[0]); R[21] = R[0] | 0xFFFE; if (_c) { goto L_8001B9A8; } }  /* 0x8001B96C */
L_8001B974:;
    R[2] = (R[21] < R[17]);  /* 0x8001B974 */
    { uint32_t _c = (R[2] == R[0]); R[16] = R[0] | 0xFFFE; if (_c) { goto L_8001B988; } }  /* 0x8001B978 */
    { R[17] = R[17] - R[16]; goto L_8001B990; }  /* 0x8001B980 j */
L_8001B988:;
    R[16] = R[17] + R[0];  /* 0x8001B988 */
    R[17] = R[0] + R[0];  /* 0x8001B98C */
L_8001B990:;
    R[4] = R[18] + R[0];  /* 0x8001B990 */
    R[5] = R[19] + R[0];  /* 0x8001B994 */
    { R[31] = 0x8001B9A0u; R[6] = R[16] + R[0]; psx_next = 0x80039D98u; return; }  /* 0x8001B998 jal */
    { uint32_t _c = (R[17] != R[0]); R[19] = R[19] + R[16]; if (_c) { psx_bb(); goto L_8001B974; } }  /* 0x8001B9A0 */
L_8001B9A8:;
    R[4] = 0x8001u << 16;  /* 0x8001B9A8 */
    R[4] = R[4] + 28924;  /* 0x8001B9AC */
    R[5] = R[22] + R[0];  /* 0x8001B9B0 */
    { R[31] = 0x8001B9BCu; R[6] = R[20] + R[0]; psx_next = 0x80031258u; return; }  /* 0x8001B9B4 jal */
    { R[31] = 0x8001B9C4u; R[4] = R[18] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001B9BC jal */
    R[3] = 0x8006u << 16;  /* 0x8001B9C4 */
    R[2] = R[0] + 1;  /* 0x8001B9C8 */
    sh_(R[3] + -10048, R[2]);  /* 0x8001B9CC */
    R[2] = R[20] + R[0];  /* 0x8001B9D0 */
    R[31] = lw_(R[29] + 172);  /* 0x8001B9D4 */
    R[22] = lw_(R[29] + 168);  /* 0x8001B9D8 */
    R[21] = lw_(R[29] + 164);  /* 0x8001B9DC */
    R[20] = lw_(R[29] + 160);  /* 0x8001B9E0 */
    R[19] = lw_(R[29] + 156);  /* 0x8001B9E4 */
    R[18] = lw_(R[29] + 152);  /* 0x8001B9E8 */
    R[17] = lw_(R[29] + 148);  /* 0x8001B9EC */
    R[16] = lw_(R[29] + 144);  /* 0x8001B9F0 */
    { R[29] = R[29] + 176; psx_next = R[31]; return; }  /* 0x8001B9F4 jr ra */
}

void f_8001B974(void) {
L_8001B974:;
    R[2] = (R[21] < R[17]);  /* 0x8001B974 */
    { uint32_t _c = (R[2] == R[0]); R[16] = R[0] | 0xFFFE; if (_c) { goto L_8001B988; } }  /* 0x8001B978 */
    { R[17] = R[17] - R[16]; goto L_8001B990; }  /* 0x8001B980 j */
L_8001B988:;
    R[16] = R[17] + R[0];  /* 0x8001B988 */
    R[17] = R[0] + R[0];  /* 0x8001B98C */
L_8001B990:;
    R[4] = R[18] + R[0];  /* 0x8001B990 */
    R[5] = R[19] + R[0];  /* 0x8001B994 */
    { R[31] = 0x8001B9A0u; R[6] = R[16] + R[0]; psx_next = 0x80039D98u; return; }  /* 0x8001B998 jal */
    { uint32_t _c = (R[17] != R[0]); R[19] = R[19] + R[16]; if (_c) { psx_bb(); goto L_8001B974; } }  /* 0x8001B9A0 */
    R[4] = 0x8001u << 16;  /* 0x8001B9A8 */
    R[4] = R[4] + 28924;  /* 0x8001B9AC */
    R[5] = R[22] + R[0];  /* 0x8001B9B0 */
    { R[31] = 0x8001B9BCu; R[6] = R[20] + R[0]; psx_next = 0x80031258u; return; }  /* 0x8001B9B4 jal */
    { R[31] = 0x8001B9C4u; R[4] = R[18] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001B9BC jal */
    R[3] = 0x8006u << 16;  /* 0x8001B9C4 */
    R[2] = R[0] + 1;  /* 0x8001B9C8 */
    sh_(R[3] + -10048, R[2]);  /* 0x8001B9CC */
    R[2] = R[20] + R[0];  /* 0x8001B9D0 */
    R[31] = lw_(R[29] + 172);  /* 0x8001B9D4 */
    R[22] = lw_(R[29] + 168);  /* 0x8001B9D8 */
    R[21] = lw_(R[29] + 164);  /* 0x8001B9DC */
    R[20] = lw_(R[29] + 160);  /* 0x8001B9E0 */
    R[19] = lw_(R[29] + 156);  /* 0x8001B9E4 */
    R[18] = lw_(R[29] + 152);  /* 0x8001B9E8 */
    R[17] = lw_(R[29] + 148);  /* 0x8001B9EC */
    R[16] = lw_(R[29] + 144);  /* 0x8001B9F0 */
    { R[29] = R[29] + 176; psx_next = R[31]; return; }  /* 0x8001B9F4 jr ra */
}

void f_8001B9A0(void) {
    { uint32_t _c = (R[17] != R[0]); R[19] = R[19] + R[16]; if (_c) { psx_next = 0x8001B974u; return; } }  /* 0x8001B9A0 b extern */
    R[4] = 0x8001u << 16;  /* 0x8001B9A8 */
    R[4] = R[4] + 28924;  /* 0x8001B9AC */
    R[5] = R[22] + R[0];  /* 0x8001B9B0 */
    { R[31] = 0x8001B9BCu; R[6] = R[20] + R[0]; psx_next = 0x80031258u; return; }  /* 0x8001B9B4 jal */
    { R[31] = 0x8001B9C4u; R[4] = R[18] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001B9BC jal */
    R[3] = 0x8006u << 16;  /* 0x8001B9C4 */
    R[2] = R[0] + 1;  /* 0x8001B9C8 */
    sh_(R[3] + -10048, R[2]);  /* 0x8001B9CC */
    R[2] = R[20] + R[0];  /* 0x8001B9D0 */
    R[31] = lw_(R[29] + 172);  /* 0x8001B9D4 */
    R[22] = lw_(R[29] + 168);  /* 0x8001B9D8 */
    R[21] = lw_(R[29] + 164);  /* 0x8001B9DC */
    R[20] = lw_(R[29] + 160);  /* 0x8001B9E0 */
    R[19] = lw_(R[29] + 156);  /* 0x8001B9E4 */
    R[18] = lw_(R[29] + 152);  /* 0x8001B9E8 */
    R[17] = lw_(R[29] + 148);  /* 0x8001B9EC */
    R[16] = lw_(R[29] + 144);  /* 0x8001B9F0 */
    { R[29] = R[29] + 176; psx_next = R[31]; return; }  /* 0x8001B9F4 jr ra */
}

void f_8001B9BC(void) {
    { R[31] = 0x8001B9C4u; R[4] = R[18] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001B9BC jal */
    R[3] = 0x8006u << 16;  /* 0x8001B9C4 */
    R[2] = R[0] + 1;  /* 0x8001B9C8 */
    sh_(R[3] + -10048, R[2]);  /* 0x8001B9CC */
    R[2] = R[20] + R[0];  /* 0x8001B9D0 */
    R[31] = lw_(R[29] + 172);  /* 0x8001B9D4 */
    R[22] = lw_(R[29] + 168);  /* 0x8001B9D8 */
    R[21] = lw_(R[29] + 164);  /* 0x8001B9DC */
    R[20] = lw_(R[29] + 160);  /* 0x8001B9E0 */
    R[19] = lw_(R[29] + 156);  /* 0x8001B9E4 */
    R[18] = lw_(R[29] + 152);  /* 0x8001B9E8 */
    R[17] = lw_(R[29] + 148);  /* 0x8001B9EC */
    R[16] = lw_(R[29] + 144);  /* 0x8001B9F0 */
    { R[29] = R[29] + 176; psx_next = R[31]; return; }  /* 0x8001B9F4 jr ra */
}

void f_8001B9C4(void) {
    R[3] = 0x8006u << 16;  /* 0x8001B9C4 */
    R[2] = R[0] + 1;  /* 0x8001B9C8 */
    sh_(R[3] + -10048, R[2]);  /* 0x8001B9CC */
    R[2] = R[20] + R[0];  /* 0x8001B9D0 */
    R[31] = lw_(R[29] + 172);  /* 0x8001B9D4 */
    R[22] = lw_(R[29] + 168);  /* 0x8001B9D8 */
    R[21] = lw_(R[29] + 164);  /* 0x8001B9DC */
    R[20] = lw_(R[29] + 160);  /* 0x8001B9E0 */
    R[19] = lw_(R[29] + 156);  /* 0x8001B9E4 */
    R[18] = lw_(R[29] + 152);  /* 0x8001B9E8 */
    R[17] = lw_(R[29] + 148);  /* 0x8001B9EC */
    R[16] = lw_(R[29] + 144);  /* 0x8001B9F0 */
    { R[29] = R[29] + 176; psx_next = R[31]; return; }  /* 0x8001B9F4 jr ra */
}

void f_8001B9FC(void) {
    R[29] = R[29] - 168;  /* 0x8001B9FC */
    sw_(R[29] + 148, R[17]);  /* 0x8001BA00 */
    R[17] = R[4] + R[0];  /* 0x8001BA04 */
    sw_(R[29] + 152, R[18]);  /* 0x8001BA08 */
    R[18] = R[5] + R[0];  /* 0x8001BA0C */
    sw_(R[29] + 156, R[19]);  /* 0x8001BA10 */
    R[19] = R[6] + R[0];  /* 0x8001BA14 */
    R[5] = R[0] + R[0];  /* 0x8001BA18 */
    sw_(R[29] + 160, R[31]);  /* 0x8001BA1C */
    { R[31] = 0x8001BA28u; sw_(R[29] + 144, R[16]); psx_next = 0x80039BDCu; return; }  /* 0x8001BA20 jal */
    R[16] = R[2] + R[0];  /* 0x8001BA28 */
    R[2] = R[0] - 1;  /* 0x8001BA2C */
    { uint32_t _c = (R[16] != R[2]); R[5] = 0x8001u << 16; if (_c) { goto L_8001BA58; } }  /* 0x8001BA30 */
    R[4] = R[29] + 16;  /* 0x8001BA38 */
    R[5] = R[5] + 28904;  /* 0x8001BA3C */
    { R[31] = 0x8001BA48u; R[6] = R[17] + R[0]; psx_next = 0x80031BF8u; return; }  /* 0x8001BA40 jal */
    { R[31] = 0x8001BA50u; R[4] = R[29] + 16; psx_next = 0x8001B828u; return; }  /* 0x8001BA48 jal */
    { R[31] = 0x8001BA58u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8001BA50 jal */
L_8001BA58:;
    R[4] = 0x8001u << 16;  /* 0x8001BA58 */
    R[4] = R[4] + 28940;  /* 0x8001BA5C */
    { R[31] = 0x8001BA68u; R[5] = R[17] + R[0]; psx_next = 0x80031258u; return; }  /* 0x8001BA60 jal */
    R[4] = R[16] + R[0];  /* 0x8001BA68 */
    R[5] = R[18] + R[0];  /* 0x8001BA6C */
    { R[31] = 0x8001BA78u; R[6] = R[19] + R[0]; psx_next = 0x80039E70u; return; }  /* 0x8001BA70 jal */
    { R[31] = 0x8001BA80u; R[4] = R[16] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001BA78 jal */
    R[31] = lw_(R[29] + 160);  /* 0x8001BA80 */
    R[19] = lw_(R[29] + 156);  /* 0x8001BA84 */
    R[18] = lw_(R[29] + 152);  /* 0x8001BA88 */
    R[17] = lw_(R[29] + 148);  /* 0x8001BA8C */
    R[16] = lw_(R[29] + 144);  /* 0x8001BA90 */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001BA94 jr ra */
}

void f_8001BA28(void) {
    R[16] = R[2] + R[0];  /* 0x8001BA28 */
    R[2] = R[0] - 1;  /* 0x8001BA2C */
    { uint32_t _c = (R[16] != R[2]); R[5] = 0x8001u << 16; if (_c) { goto L_8001BA58; } }  /* 0x8001BA30 */
    R[4] = R[29] + 16;  /* 0x8001BA38 */
    R[5] = R[5] + 28904;  /* 0x8001BA3C */
    { R[31] = 0x8001BA48u; R[6] = R[17] + R[0]; psx_next = 0x80031BF8u; return; }  /* 0x8001BA40 jal */
    { R[31] = 0x8001BA50u; R[4] = R[29] + 16; psx_next = 0x8001B828u; return; }  /* 0x8001BA48 jal */
    { R[31] = 0x8001BA58u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8001BA50 jal */
L_8001BA58:;
    R[4] = 0x8001u << 16;  /* 0x8001BA58 */
    R[4] = R[4] + 28940;  /* 0x8001BA5C */
    { R[31] = 0x8001BA68u; R[5] = R[17] + R[0]; psx_next = 0x80031258u; return; }  /* 0x8001BA60 jal */
    R[4] = R[16] + R[0];  /* 0x8001BA68 */
    R[5] = R[18] + R[0];  /* 0x8001BA6C */
    { R[31] = 0x8001BA78u; R[6] = R[19] + R[0]; psx_next = 0x80039E70u; return; }  /* 0x8001BA70 jal */
    { R[31] = 0x8001BA80u; R[4] = R[16] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001BA78 jal */
    R[31] = lw_(R[29] + 160);  /* 0x8001BA80 */
    R[19] = lw_(R[29] + 156);  /* 0x8001BA84 */
    R[18] = lw_(R[29] + 152);  /* 0x8001BA88 */
    R[17] = lw_(R[29] + 148);  /* 0x8001BA8C */
    R[16] = lw_(R[29] + 144);  /* 0x8001BA90 */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001BA94 jr ra */
}

void f_8001BA48(void) {
    { R[31] = 0x8001BA50u; R[4] = R[29] + 16; psx_next = 0x8001B828u; return; }  /* 0x8001BA48 jal */
    { R[31] = 0x8001BA58u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8001BA50 jal */
    R[4] = 0x8001u << 16;  /* 0x8001BA58 */
    R[4] = R[4] + 28940;  /* 0x8001BA5C */
    { R[31] = 0x8001BA68u; R[5] = R[17] + R[0]; psx_next = 0x80031258u; return; }  /* 0x8001BA60 jal */
    R[4] = R[16] + R[0];  /* 0x8001BA68 */
    R[5] = R[18] + R[0];  /* 0x8001BA6C */
    { R[31] = 0x8001BA78u; R[6] = R[19] + R[0]; psx_next = 0x80039E70u; return; }  /* 0x8001BA70 jal */
    { R[31] = 0x8001BA80u; R[4] = R[16] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001BA78 jal */
    R[31] = lw_(R[29] + 160);  /* 0x8001BA80 */
    R[19] = lw_(R[29] + 156);  /* 0x8001BA84 */
    R[18] = lw_(R[29] + 152);  /* 0x8001BA88 */
    R[17] = lw_(R[29] + 148);  /* 0x8001BA8C */
    R[16] = lw_(R[29] + 144);  /* 0x8001BA90 */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001BA94 jr ra */
}

void f_8001BA50(void) {
    { R[31] = 0x8001BA58u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8001BA50 jal */
    R[4] = 0x8001u << 16;  /* 0x8001BA58 */
    R[4] = R[4] + 28940;  /* 0x8001BA5C */
    { R[31] = 0x8001BA68u; R[5] = R[17] + R[0]; psx_next = 0x80031258u; return; }  /* 0x8001BA60 jal */
    R[4] = R[16] + R[0];  /* 0x8001BA68 */
    R[5] = R[18] + R[0];  /* 0x8001BA6C */
    { R[31] = 0x8001BA78u; R[6] = R[19] + R[0]; psx_next = 0x80039E70u; return; }  /* 0x8001BA70 jal */
    { R[31] = 0x8001BA80u; R[4] = R[16] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001BA78 jal */
    R[31] = lw_(R[29] + 160);  /* 0x8001BA80 */
    R[19] = lw_(R[29] + 156);  /* 0x8001BA84 */
    R[18] = lw_(R[29] + 152);  /* 0x8001BA88 */
    R[17] = lw_(R[29] + 148);  /* 0x8001BA8C */
    R[16] = lw_(R[29] + 144);  /* 0x8001BA90 */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001BA94 jr ra */
}

void f_8001BA58(void) {
    R[4] = 0x8001u << 16;  /* 0x8001BA58 */
    R[4] = R[4] + 28940;  /* 0x8001BA5C */
    { R[31] = 0x8001BA68u; R[5] = R[17] + R[0]; psx_next = 0x80031258u; return; }  /* 0x8001BA60 jal */
    R[4] = R[16] + R[0];  /* 0x8001BA68 */
    R[5] = R[18] + R[0];  /* 0x8001BA6C */
    { R[31] = 0x8001BA78u; R[6] = R[19] + R[0]; psx_next = 0x80039E70u; return; }  /* 0x8001BA70 jal */
    { R[31] = 0x8001BA80u; R[4] = R[16] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001BA78 jal */
    R[31] = lw_(R[29] + 160);  /* 0x8001BA80 */
    R[19] = lw_(R[29] + 156);  /* 0x8001BA84 */
    R[18] = lw_(R[29] + 152);  /* 0x8001BA88 */
    R[17] = lw_(R[29] + 148);  /* 0x8001BA8C */
    R[16] = lw_(R[29] + 144);  /* 0x8001BA90 */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001BA94 jr ra */
}

void f_8001BA68(void) {
    R[4] = R[16] + R[0];  /* 0x8001BA68 */
    R[5] = R[18] + R[0];  /* 0x8001BA6C */
    { R[31] = 0x8001BA78u; R[6] = R[19] + R[0]; psx_next = 0x80039E70u; return; }  /* 0x8001BA70 jal */
    { R[31] = 0x8001BA80u; R[4] = R[16] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001BA78 jal */
    R[31] = lw_(R[29] + 160);  /* 0x8001BA80 */
    R[19] = lw_(R[29] + 156);  /* 0x8001BA84 */
    R[18] = lw_(R[29] + 152);  /* 0x8001BA88 */
    R[17] = lw_(R[29] + 148);  /* 0x8001BA8C */
    R[16] = lw_(R[29] + 144);  /* 0x8001BA90 */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001BA94 jr ra */
}

void f_8001BA78(void) {
    { R[31] = 0x8001BA80u; R[4] = R[16] + R[0]; psx_next = 0x80039BA8u; return; }  /* 0x8001BA78 jal */
    R[31] = lw_(R[29] + 160);  /* 0x8001BA80 */
    R[19] = lw_(R[29] + 156);  /* 0x8001BA84 */
    R[18] = lw_(R[29] + 152);  /* 0x8001BA88 */
    R[17] = lw_(R[29] + 148);  /* 0x8001BA8C */
    R[16] = lw_(R[29] + 144);  /* 0x8001BA90 */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001BA94 jr ra */
}

void f_8001BA80(void) {
    R[31] = lw_(R[29] + 160);  /* 0x8001BA80 */
    R[19] = lw_(R[29] + 156);  /* 0x8001BA84 */
    R[18] = lw_(R[29] + 152);  /* 0x8001BA88 */
    R[17] = lw_(R[29] + 148);  /* 0x8001BA8C */
    R[16] = lw_(R[29] + 144);  /* 0x8001BA90 */
    { R[29] = R[29] + 168; psx_next = R[31]; return; }  /* 0x8001BA94 jr ra */
}

void f_8001BA9C(void) {
    { R[2] = R[0] + R[0]; psx_next = R[31]; return; }  /* 0x8001BA9C jr ra */
}

void f_8001BAA4(void) {
    R[29] = R[29] - 24;  /* 0x8001BAA4 */
    R[3] = 0x8006u << 16;  /* 0x8001BAA8 */
    R[2] = 0x0u << 16;  /* 0x8001BAAC */
    R[2] = R[2] + 1;  /* 0x8001BAB0 */
    sw_(R[29] + 16, R[31]);  /* 0x8001BAB4 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[3] + -6472, R[2]); if (_c) { goto L_8001BAE8; } }  /* 0x8001BAB8 */
    { R[31] = 0x8001BAC8u; psx_next = 0x8004E8E0u; return; }  /* 0x8001BAC0 jal */
    { R[31] = 0x8001BAD0u; R[4] = R[0] + R[0]; psx_next = 0x8004E8F0u; return; }  /* 0x8001BAC8 jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8001BAE0; } }  /* 0x8001BAD0 */
    { R[31] = 0x8001BAE0u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8001BAD8 jal */
L_8001BAE0:;
    { R[31] = 0x8001BAE8u; R[4] = R[0] + 3; psx_next = 0x80037D98u; return; }  /* 0x8001BAE0 jal */
L_8001BAE8:;
    R[31] = lw_(R[29] + 16);  /* 0x8001BAE8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001BAF0 jr ra */
}

void f_8001BAC8(void) {
    { R[31] = 0x8001BAD0u; R[4] = R[0] + R[0]; psx_next = 0x8004E8F0u; return; }  /* 0x8001BAC8 jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8001BAE0; } }  /* 0x8001BAD0 */
    { R[31] = 0x8001BAE0u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8001BAD8 jal */
L_8001BAE0:;
    { R[31] = 0x8001BAE8u; R[4] = R[0] + 3; psx_next = 0x80037D98u; return; }  /* 0x8001BAE0 jal */
    R[31] = lw_(R[29] + 16);  /* 0x8001BAE8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001BAF0 jr ra */
}

void f_8001BAD0(void) {
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8001BAE0; } }  /* 0x8001BAD0 */
    { R[31] = 0x8001BAE0u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8001BAD8 jal */
L_8001BAE0:;
    { R[31] = 0x8001BAE8u; R[4] = R[0] + 3; psx_next = 0x80037D98u; return; }  /* 0x8001BAE0 jal */
    R[31] = lw_(R[29] + 16);  /* 0x8001BAE8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001BAF0 jr ra */
}

void f_8001BAE0(void) {
    { R[31] = 0x8001BAE8u; R[4] = R[0] + 3; psx_next = 0x80037D98u; return; }  /* 0x8001BAE0 jal */
    R[31] = lw_(R[29] + 16);  /* 0x8001BAE8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001BAF0 jr ra */
}

void f_8001BAE8(void) {
    R[31] = lw_(R[29] + 16);  /* 0x8001BAE8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001BAF0 jr ra */
}

void f_8001BAF8(void) {
    R[29] = R[29] - 24;  /* 0x8001BAF8 */
    R[2] = 0x8006u << 16;  /* 0x8001BAFC */
    R[3] = 0x0u << 16;  /* 0x8001BB00 */
    R[3] = R[3] + 1;  /* 0x8001BB04 */
    R[4] = 0x8006u << 16;  /* 0x8001BB08 */
    sw_(R[2] + -6472, R[3]);  /* 0x8001BB0C */
    R[2] = R[0] - 1;  /* 0x8001BB10 */
    sw_(R[29] + 16, R[31]);  /* 0x8001BB14 */
    { uint32_t _c = (R[3] == R[0]); sw_(R[4] + -10032, R[2]); if (_c) { goto L_8001BB30; } }  /* 0x8001BB18 */
    { R[31] = 0x8001BB28u; psx_next = 0x8001AC88u; return; }  /* 0x8001BB20 jal */
    { R[2] = 0x8006u << 16; goto L_8001BB3C; }  /* 0x8001BB28 j */
L_8001BB30:;
    { R[31] = 0x8001BB38u; psx_next = 0x8001B7F4u; return; }  /* 0x8001BB30 jal */
    R[2] = 0x8006u << 16;  /* 0x8001BB38 */
L_8001BB3C:;
    R[3] = R[0] + 1;  /* 0x8001BB3C */
    sh_(R[2] + -10048, R[3]);  /* 0x8001BB40 */
    R[2] = 0x8006u << 16;  /* 0x8001BB44 */
    R[2] = R[2] - 10024;  /* 0x8001BB48 */
    sh_(R[2] + 4, R[3]);  /* 0x8001BB4C */
    R[31] = lw_(R[29] + 16);  /* 0x8001BB50 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001BB58 jr ra */
}

void f_8001BB28(void) {
    { R[2] = 0x8006u << 16; goto L_8001BB3C; }  /* 0x8001BB28 j */
    { R[31] = 0x8001BB38u; psx_next = 0x8001B7F4u; return; }  /* 0x8001BB30 jal */
    R[2] = 0x8006u << 16;  /* 0x8001BB38 */
L_8001BB3C:;
    R[3] = R[0] + 1;  /* 0x8001BB3C */
    sh_(R[2] + -10048, R[3]);  /* 0x8001BB40 */
    R[2] = 0x8006u << 16;  /* 0x8001BB44 */
    R[2] = R[2] - 10024;  /* 0x8001BB48 */
    sh_(R[2] + 4, R[3]);  /* 0x8001BB4C */
    R[31] = lw_(R[29] + 16);  /* 0x8001BB50 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001BB58 jr ra */
}

void f_8001BB38(void) {
    R[2] = 0x8006u << 16;  /* 0x8001BB38 */
    R[3] = R[0] + 1;  /* 0x8001BB3C */
    sh_(R[2] + -10048, R[3]);  /* 0x8001BB40 */
    R[2] = 0x8006u << 16;  /* 0x8001BB44 */
    R[2] = R[2] - 10024;  /* 0x8001BB48 */
    sh_(R[2] + 4, R[3]);  /* 0x8001BB4C */
    R[31] = lw_(R[29] + 16);  /* 0x8001BB50 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8001BB58 jr ra */
}
