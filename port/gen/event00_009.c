#include "event00_decls.h"

void ev_8008E6E0(void) {
    R[29] = R[29] - 24;  /* 0x8008E6E0 */
    R[6] = R[4] + R[0];  /* 0x8008E6E4 */
    sw_(R[29] + 16, R[31]);  /* 0x8008E6E8 */
    R[2] = lw_(R[6]);  /* 0x8008E6EC */
    R[2] = R[2] & 0x8000;  /* 0x8008E6F4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008E8B0; } }  /* 0x8008E6F8 */
    R[2] = lw_(R[6] + 32);  /* 0x8008E700 */
    R[4] = lw_(R[6] + 44);  /* 0x8008E704 */
    R[3] = lw_(R[6] + 36);  /* 0x8008E708 */
    R[5] = lw_(R[6] + 48);  /* 0x8008E70C */
    R[2] = R[2] + R[4];  /* 0x8008E710 */
    sw_(R[6] + 32, R[2]);  /* 0x8008E714 */
    R[2] = lw_(R[6] + 40);  /* 0x8008E718 */
    R[3] = R[3] + R[5];  /* 0x8008E71C */
    sw_(R[6] + 36, R[3]);  /* 0x8008E720 */
    R[3] = lw_(R[6] + 8);  /* 0x8008E724 */
    R[4] = lw_(R[6] + 52);  /* 0x8008E728 */
    R[3] = R[3] + 1;  /* 0x8008E72C */
    sw_(R[6] + 8, R[3]);  /* 0x8008E730 */
    R[3] = lw_(R[6] + 4);  /* 0x8008E734 */
    R[2] = R[2] + R[4];  /* 0x8008E738 */
    sw_(R[6] + 40, R[2]);  /* 0x8008E73C */
    R[2] = R[0] + 1;  /* 0x8008E740 */
    { uint32_t _c = (R[3] == R[2]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_8008E780; } }  /* 0x8008E744 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008E764; } }  /* 0x8008E74C */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_8008E778; } }  /* 0x8008E754 */
    { goto L_8008E8B0; }  /* 0x8008E75C j */
L_8008E764:;
    R[2] = R[0] + 2;  /* 0x8008E764 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8008E8A8; } }  /* 0x8008E768 */
    { goto L_8008E8B0; }  /* 0x8008E770 j */
L_8008E778:;
    { sw_(R[6], R[0]); goto L_8008E8B0; }  /* 0x8008E778 j */
L_8008E780:;
    R[8] = 0x800Cu << 16;  /* 0x8008E780 */
    R[2] = 0x800Bu << 16;  /* 0x8008E784 */
    R[7] = lw_(R[8] + -24632);  /* 0x8008E788 */
    R[2] = lw_(R[2] + 30896);  /* 0x8008E78C */
    R[2] = (R[7] < R[2]);  /* 0x8008E794 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 9; if (_c) { goto L_8008E870; } }  /* 0x8008E798 */
    sb_(R[7] + 3, R[2]);  /* 0x8008E7A0 */
    R[2] = R[0] + 44;  /* 0x8008E7A4 */
    sb_(R[7] + 7, R[2]);  /* 0x8008E7A8 */
    R[2] = R[0] + 255;  /* 0x8008E7AC */
    R[4] = R[0] + 172;  /* 0x8008E7B0 */
    R[3] = 0x800Bu << 16;  /* 0x8008E7B4 */
    sb_(R[7] + 12, R[0]);  /* 0x8008E7B8 */
    sb_(R[7] + 13, R[0]);  /* 0x8008E7BC */
    sb_(R[7] + 20, R[2]);  /* 0x8008E7C0 */
    sb_(R[7] + 21, R[0]);  /* 0x8008E7C4 */
    sb_(R[7] + 28, R[0]);  /* 0x8008E7C8 */
    sb_(R[7] + 29, R[4]);  /* 0x8008E7CC */
    sb_(R[7] + 36, R[2]);  /* 0x8008E7D0 */
    sb_(R[7] + 37, R[4]);  /* 0x8008E7D4 */
    R[2] = lb_(R[3] + -13188);  /* 0x8008E7D8 */
    sb_(R[7] + 4, R[2]);  /* 0x8008E7E0 */
    R[2] = lb_(R[3] + -13188);  /* 0x8008E7E4 */
    sh_(R[7] + 8, R[0]);  /* 0x8008E7E8 */
    sh_(R[7] + 10, R[0]);  /* 0x8008E7EC */
    sh_(R[7] + 18, R[0]);  /* 0x8008E7F0 */
    sh_(R[7] + 24, R[0]);  /* 0x8008E7F4 */
    sh_(R[7] + 26, R[4]);  /* 0x8008E7F8 */
    sh_(R[7] + 34, R[4]);  /* 0x8008E7FC */
    sb_(R[7] + 5, R[2]);  /* 0x8008E800 */
    R[3] = lb_(R[3] + -13188);  /* 0x8008E804 */
    R[2] = R[0] + 320;  /* 0x8008E808 */
    sh_(R[7] + 16, R[2]);  /* 0x8008E80C */
    sh_(R[7] + 32, R[2]);  /* 0x8008E810 */
    sb_(R[7] + 6, R[3]);  /* 0x8008E814 */
    R[2] = lh_(R[6] + 12);  /* 0x8008E818 */
    R[3] = lw_(R[7]);  /* 0x8008E81C */
    R[4] = 0xFFu << 16;  /* 0x8008E820 */
    sh_(R[7] + 22, R[2]);  /* 0x8008E824 */
    R[2] = lh_(R[6] + 14);  /* 0x8008E828 */
    R[4] = R[4] | 0xFFFF;  /* 0x8008E82C */
    sh_(R[7] + 14, R[2]);  /* 0x8008E830 */
    R[2] = 0x800Bu << 16;  /* 0x8008E834 */
    R[5] = lw_(R[2] + 30552);  /* 0x8008E838 */
    R[6] = 0xFF00u << 16;  /* 0x8008E83C */
    R[2] = lw_(R[5] + 4);  /* 0x8008E840 */
    R[3] = R[3] & R[6];  /* 0x8008E844 */
    R[2] = R[2] & R[4];  /* 0x8008E848 */
    R[3] = R[3] | R[2];  /* 0x8008E84C */
    R[4] = R[7] & R[4];  /* 0x8008E850 */
    sw_(R[7], R[3]);  /* 0x8008E854 */
    R[2] = lw_(R[5] + 4);  /* 0x8008E858 */
    R[7] = R[7] + 40;  /* 0x8008E85C */
    R[2] = R[2] & R[6];  /* 0x8008E860 */
    R[2] = R[2] | R[4];  /* 0x8008E864 */
    sw_(R[5] + 4, R[2]);  /* 0x8008E868 */
    sw_(R[8] + -24632, R[7]);  /* 0x8008E86C */
L_8008E870:;
    R[4] = 0x800Bu << 16;  /* 0x8008E870 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + -13188);  /* 0x8008E874 */
    R[3] = lh_(R[4] + -13188);  /* 0x8008E878 */
    R[2] = ((int32_t)R[2] < 128);  /* 0x8008E87C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 7; if (_c) { goto L_8008E8B0; } }  /* 0x8008E880 */
    sh_(R[4] + -13188, R[2]);  /* 0x8008E888 */
    R[2] = R[2] << 16;  /* 0x8008E88C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008E890 */
    R[2] = ((int32_t)R[2] < 128);  /* 0x8008E894 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 128; if (_c) { goto L_8008E8B0; } }  /* 0x8008E898 */
    { sh_(R[4] + -13188, R[2]); goto L_8008E8B0; }  /* 0x8008E8A0 j */
L_8008E8A8:;
    { R[31] = 0x8008E8B0u; R[4] = R[6] + R[0]; psx_next = 0x8008E8D0u; return; }  /* 0x8008E8A8 jal */
L_8008E8B0:;
    R[31] = lw_(R[29] + 16);  /* 0x8008E8B0 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8008E8B8 jr ra */
}

void ev_8008E8B0(void) {
    R[31] = lw_(R[29] + 16);  /* 0x8008E8B0 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8008E8B8 jr ra */
}

void ev_8008E8C0(void) {
    R[3] = 0x800Bu << 16;  /* 0x8008E8C0 */
    R[2] = R[0] + 96;  /* 0x8008E8C4 */
    { sh_(R[3] + 30176, R[2]); psx_next = R[31]; return; }  /* 0x8008E8C8 jr ra */
}

void ev_8008E8D0(void) {
    R[8] = R[4] + R[0];  /* 0x8008E8D0 */
    R[4] = 0xFu << 16;  /* 0x8008E8D4 */
    R[4] = R[4] | 0xF000;  /* 0x8008E8D8 */
    R[2] = R[0] + 12288;  /* 0x8008E8DC */
    R[3] = 0x800Du << 16;  /* 0x8008E8E0 */
    sw_(R[8] + 48, R[2]);  /* 0x8008E8E4 */
    R[2] = lw_(R[8] + 36);  /* 0x8008E8E8 */
    R[3] = lw_(R[3] + 20540);  /* 0x8008E8EC */
    R[2] = R[2] & R[4];  /* 0x8008E8F0 */
    R[3] = ((int32_t)R[3] < 488);  /* 0x8008E8F4 */
    { uint32_t _c = (R[3] != R[0]); sw_(R[8] + 36, R[2]); if (_c) { goto L_8008E924; } }  /* 0x8008E8F8 */
    R[3] = 0x800Bu << 16;  /* 0x8008E900 */
    R[2] = lh_(R[3] + 30176);  /* 0x8008E904 */
    R[2] = R[2] - 3;  /* 0x8008E90C */
    sh_(R[3] + 30176, R[2]);  /* 0x8008E910 */
    R[2] = R[2] << 16;  /* 0x8008E914 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[9] = 0x800Cu << 16; if (_c) { goto L_8008E928; } }  /* 0x8008E918 */
    sh_(R[3] + 30176, R[0]);  /* 0x8008E920 */
L_8008E924:;
    R[9] = 0x800Cu << 16;  /* 0x8008E924 */
L_8008E928:;
    R[2] = 0x800Bu << 16;  /* 0x8008E928 */
    R[7] = lw_(R[9] + -24632);  /* 0x8008E92C */
    R[2] = lw_(R[2] + 30896);  /* 0x8008E930 */
    R[2] = (R[7] < R[2]);  /* 0x8008E938 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 9; if (_c) { goto L_8008EA7C; } }  /* 0x8008E93C */
    sb_(R[7] + 3, R[2]);  /* 0x8008E944 */
    R[2] = R[0] + 44;  /* 0x8008E948 */
    sb_(R[7] + 7, R[2]);  /* 0x8008E94C */
    sh_(R[7] + 8, R[0]);  /* 0x8008E950 */
    R[2] = lw_(R[8] + 36);  /* 0x8008E954 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008E968; } }  /* 0x8008E95C */
    R[2] = R[2] + 4095;  /* 0x8008E964 */
L_8008E968:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008E968 */
    R[2] = R[2] - 256;  /* 0x8008E96C */
    R[3] = R[0] + 320;  /* 0x8008E970 */
    sh_(R[7] + 10, R[2]);  /* 0x8008E974 */
    sh_(R[7] + 16, R[3]);  /* 0x8008E978 */
    R[2] = lw_(R[8] + 36);  /* 0x8008E97C */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008E990; } }  /* 0x8008E984 */
    R[2] = R[2] + 4095;  /* 0x8008E98C */
L_8008E990:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008E990 */
    R[2] = R[2] - 256;  /* 0x8008E994 */
    sh_(R[7] + 18, R[2]);  /* 0x8008E998 */
    sh_(R[7] + 24, R[0]);  /* 0x8008E99C */
    R[2] = lw_(R[8] + 36);  /* 0x8008E9A0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008E9B4; } }  /* 0x8008E9A8 */
    R[2] = R[2] + 4095;  /* 0x8008E9B0 */
L_8008E9B4:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008E9B4 */
    sh_(R[7] + 26, R[2]);  /* 0x8008E9B8 */
    sh_(R[7] + 32, R[3]);  /* 0x8008E9BC */
    R[4] = lw_(R[8] + 36);  /* 0x8008E9C0 */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[2] = R[0] + 255; if (_c) { goto L_8008E9D4; } }  /* 0x8008E9C8 */
    R[4] = R[4] + 4095;  /* 0x8008E9D0 */
L_8008E9D4:;
    R[3] = 0x800Bu << 16;  /* 0x8008E9D4 */
    sb_(R[7] + 12, R[0]);  /* 0x8008E9D8 */
    sb_(R[7] + 13, R[0]);  /* 0x8008E9DC */
    sb_(R[7] + 20, R[2]);  /* 0x8008E9E0 */
    sb_(R[7] + 21, R[0]);  /* 0x8008E9E4 */
    sb_(R[7] + 28, R[0]);  /* 0x8008E9E8 */
    sb_(R[7] + 29, R[2]);  /* 0x8008E9EC */
    sb_(R[7] + 36, R[2]);  /* 0x8008E9F0 */
    sb_(R[7] + 37, R[2]);  /* 0x8008E9F4 */
    R[2] = lb_(R[3] + 30176);  /* 0x8008E9F8 */
    sb_(R[7] + 4, R[2]);  /* 0x8008EA00 */
    R[2] = lb_(R[3] + 30176);  /* 0x8008EA04 */
    R[5] = 0xFFu << 16;  /* 0x8008EA08 */
    sb_(R[7] + 5, R[2]);  /* 0x8008EA0C */
    R[3] = lb_(R[3] + 30176);  /* 0x8008EA10 */
    R[2] = (uint32_t)((int32_t)R[4] >> 12);  /* 0x8008EA14 */
    sh_(R[7] + 34, R[2]);  /* 0x8008EA18 */
    R[2] = 0x800Bu << 16;  /* 0x8008EA1C */
    sb_(R[7] + 6, R[3]);  /* 0x8008EA20 */
    R[2] = lh_(R[2] + -8582);  /* 0x8008EA24 */
    R[5] = R[5] | 0xFFFF;  /* 0x8008EA28 */
    sh_(R[7] + 22, R[2]);  /* 0x8008EA2C */
    R[2] = 0x800Bu << 16;  /* 0x8008EA30 */
    R[2] = lh_(R[2] + 30768);  /* 0x8008EA34 */
    R[6] = 0xFF00u << 16;  /* 0x8008EA38 */
    sh_(R[7] + 14, R[2]);  /* 0x8008EA3C */
    R[2] = 0x800Bu << 16;  /* 0x8008EA40 */
    R[4] = lw_(R[2] + 30552);  /* 0x8008EA44 */
    R[3] = lw_(R[7]);  /* 0x8008EA48 */
    R[2] = lw_(R[4] + 4);  /* 0x8008EA4C */
    R[3] = R[3] & R[6];  /* 0x8008EA50 */
    R[2] = R[2] & R[5];  /* 0x8008EA54 */
    R[3] = R[3] | R[2];  /* 0x8008EA58 */
    R[5] = R[7] & R[5];  /* 0x8008EA5C */
    sw_(R[7], R[3]);  /* 0x8008EA60 */
    R[2] = lw_(R[4] + 4);  /* 0x8008EA64 */
    R[7] = R[7] + 40;  /* 0x8008EA68 */
    sw_(R[9] + -24632, R[7]);  /* 0x8008EA6C */
    R[2] = R[2] & R[6];  /* 0x8008EA70 */
    R[2] = R[2] | R[5];  /* 0x8008EA74 */
    sw_(R[4] + 4, R[2]);  /* 0x8008EA78 */
L_8008EA7C:;
    R[9] = 0x800Cu << 16;  /* 0x8008EA7C */
    R[2] = 0x800Bu << 16;  /* 0x8008EA80 */
    R[7] = lw_(R[9] + -24632);  /* 0x8008EA84 */
    R[2] = lw_(R[2] + 30896);  /* 0x8008EA88 */
    R[2] = (R[7] < R[2]);  /* 0x8008EA90 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 9; if (_c) { psx_next = 0x8008EBD4u; return; } }  /* 0x8008EA94 b extern */
    sb_(R[7] + 3, R[2]);  /* 0x8008EA9C */
    R[2] = R[0] + 44;  /* 0x8008EAA0 */
    sb_(R[7] + 7, R[2]);  /* 0x8008EAA4 */
    sh_(R[7] + 8, R[0]);  /* 0x8008EAA8 */
    R[2] = lw_(R[8] + 36);  /* 0x8008EAAC */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008EAC0; } }  /* 0x8008EAB4 */
    R[2] = R[2] + 4095;  /* 0x8008EABC */
L_8008EAC0:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008EAC0 */
    R[3] = R[0] + 320;  /* 0x8008EAC4 */
    sh_(R[7] + 10, R[2]);  /* 0x8008EAC8 */
    sh_(R[7] + 16, R[3]);  /* 0x8008EACC */
    R[2] = lw_(R[8] + 36);  /* 0x8008EAD0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008EAE4; } }  /* 0x8008EAD8 */
    R[2] = R[2] + 4095;  /* 0x8008EAE0 */
L_8008EAE4:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008EAE4 */
    sh_(R[7] + 18, R[2]);  /* 0x8008EAE8 */
    sh_(R[7] + 24, R[0]);  /* 0x8008EAEC */
    R[2] = lw_(R[8] + 36);  /* 0x8008EAF0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008EB04; } }  /* 0x8008EAF8 */
    R[2] = R[2] + 4095;  /* 0x8008EB00 */
L_8008EB04:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008EB04 */
    R[2] = R[2] + 256;  /* 0x8008EB08 */
    sh_(R[7] + 26, R[2]);  /* 0x8008EB0C */
    sh_(R[7] + 32, R[3]);  /* 0x8008EB10 */
    R[4] = lw_(R[8] + 36);  /* 0x8008EB14 */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[2] = R[0] + 255; if (_c) { goto L_8008EB28; } }  /* 0x8008EB1C */
    R[4] = R[4] + 4095;  /* 0x8008EB24 */
L_8008EB28:;
    R[3] = 0x800Bu << 16;  /* 0x8008EB28 */
    sb_(R[7] + 12, R[0]);  /* 0x8008EB2C */
    sb_(R[7] + 13, R[0]);  /* 0x8008EB30 */
    sb_(R[7] + 20, R[2]);  /* 0x8008EB34 */
    sb_(R[7] + 21, R[0]);  /* 0x8008EB38 */
    sb_(R[7] + 28, R[0]);  /* 0x8008EB3C */
    sb_(R[7] + 29, R[2]);  /* 0x8008EB40 */
    sb_(R[7] + 36, R[2]);  /* 0x8008EB44 */
    psx_next = 0x8008EB48u; return;  /* fallthrough */
}

void ev_8008EB48(void) {
    sb_(R[7] + 37, R[2]);  /* 0x8008EB48 */
    R[2] = lb_(R[3] + 30176);  /* 0x8008EB4C */
    sb_(R[7] + 4, R[2]);  /* 0x8008EB54 */
    R[2] = lb_(R[3] + 30176);  /* 0x8008EB58 */
    R[5] = 0xFFu << 16;  /* 0x8008EB5C */
    sb_(R[7] + 5, R[2]);  /* 0x8008EB60 */
    R[2] = (uint32_t)((int32_t)R[4] >> 12);  /* 0x8008EB64 */
    R[3] = lb_(R[3] + 30176);  /* 0x8008EB68 */
    R[2] = R[2] + 256;  /* 0x8008EB6C */
    sh_(R[7] + 34, R[2]);  /* 0x8008EB70 */
    R[2] = 0x800Bu << 16;  /* 0x8008EB74 */
    sb_(R[7] + 6, R[3]);  /* 0x8008EB78 */
    R[2] = lh_(R[2] + -8582);  /* 0x8008EB7C */
    R[5] = R[5] | 0xFFFF;  /* 0x8008EB80 */
    sh_(R[7] + 22, R[2]);  /* 0x8008EB84 */
    R[2] = 0x800Bu << 16;  /* 0x8008EB88 */
    R[2] = lh_(R[2] + 30768);  /* 0x8008EB8C */
    R[6] = 0xFF00u << 16;  /* 0x8008EB90 */
    sh_(R[7] + 14, R[2]);  /* 0x8008EB94 */
    R[2] = 0x800Bu << 16;  /* 0x8008EB98 */
    R[4] = lw_(R[2] + 30552);  /* 0x8008EB9C */
    R[3] = lw_(R[7]);  /* 0x8008EBA0 */
    R[2] = lw_(R[4] + 4);  /* 0x8008EBA4 */
    R[3] = R[3] & R[6];  /* 0x8008EBA8 */
    R[2] = R[2] & R[5];  /* 0x8008EBAC */
    R[3] = R[3] | R[2];  /* 0x8008EBB0 */
    R[5] = R[7] & R[5];  /* 0x8008EBB4 */
    sw_(R[7], R[3]);  /* 0x8008EBB8 */
    R[2] = lw_(R[4] + 4);  /* 0x8008EBBC */
    R[7] = R[7] + 40;  /* 0x8008EBC0 */
    sw_(R[9] + -24632, R[7]);  /* 0x8008EBC4 */
    R[2] = R[2] & R[6];  /* 0x8008EBC8 */
    R[2] = R[2] | R[5];  /* 0x8008EBCC */
    sw_(R[4] + 4, R[2]);  /* 0x8008EBD0 */
    { psx_next = R[31]; return; }  /* 0x8008EBD4 jr ra */
}

void ev_8008EBD4(void) {
    { psx_next = R[31]; return; }  /* 0x8008EBD4 jr ra */
}

void ev_8008EBDC(void) {
    R[3] = R[0] + 127;  /* 0x8008EBDC */
    R[2] = 0x800Fu << 16;  /* 0x8008EBE0 */
    R[2] = R[2] - 15672;  /* 0x8008EBE4 */
    R[2] = R[2] + 9144;  /* 0x8008EBE8 */
L_8008EBEC:;
    sh_(R[2], R[0]);  /* 0x8008EBEC */
    R[3] = R[3] - 1;  /* 0x8008EBF0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[2] - 72; if (_c) { psx_bb(); goto L_8008EBEC; } }  /* 0x8008EBF4 */
    R[4] = R[0] - 1;  /* 0x8008EBFC */
    R[3] = R[0] + 3;  /* 0x8008EC00 */
    R[2] = 0x800Bu << 16;  /* 0x8008EC04 */
    R[2] = R[2] + 30184;  /* 0x8008EC08 */
    R[2] = R[2] + 48;  /* 0x8008EC0C */
L_8008EC10:;
    sw_(R[2], R[4]);  /* 0x8008EC10 */
    R[3] = R[3] - 1;  /* 0x8008EC14 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[2] - 16; if (_c) { psx_bb(); goto L_8008EC10; } }  /* 0x8008EC18 */
    { psx_next = R[31]; return; }  /* 0x8008EC20 jr ra */
}

void ev_8008EC28(void) {
    R[3] = R[0] + R[0];  /* 0x8008EC28 */
    R[6] = R[0] | 0xC000;  /* 0x8008EC2C */
    R[7] = 0x2E80u << 16;  /* 0x8008EC30 */
    R[7] = R[7] | 0x8080;  /* 0x8008EC34 */
    R[2] = 0x800Fu << 16;  /* 0x8008EC38 */
    R[5] = R[2] - 15672;  /* 0x8008EC3C */
L_8008EC40:;
    R[2] = lh_(R[5]);  /* 0x8008EC40 */
    R[2] = R[2] & 0x8000;  /* 0x8008EC48 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 1; if (_c) { goto L_8008ECC8; } }  /* 0x8008EC4C */
    sh_(R[5], R[6]);  /* 0x8008EC54 */
    R[2] = lb_(R[4]);  /* 0x8008EC58 */
    sb_(R[5] + 2, R[2]);  /* 0x8008EC60 */
    R[2] = lb_(R[4] + 1);  /* 0x8008EC64 */
    sb_(R[5] + 52, R[2]);  /* 0x8008EC6C */
    R[2] = lb_(R[4] + 2);  /* 0x8008EC70 */
    sb_(R[5] + 53, R[2]);  /* 0x8008EC78 */
    R[2] = lw_(R[4] + 4);  /* 0x8008EC7C */
    sw_(R[5] + 8, R[2]);  /* 0x8008EC84 */
    R[2] = lw_(R[4] + 8);  /* 0x8008EC88 */
    sw_(R[5] + 12, R[2]);  /* 0x8008EC90 */
    R[3] = lw_(R[4] + 12);  /* 0x8008EC94 */
    R[2] = R[5] + R[0];  /* 0x8008EC98 */
    sw_(R[2] + 20, R[0]);  /* 0x8008EC9C */
    sw_(R[2] + 24, R[0]);  /* 0x8008ECA0 */
    sw_(R[2] + 28, R[0]);  /* 0x8008ECA4 */
    sw_(R[2] + 32, R[0]);  /* 0x8008ECA8 */
    sw_(R[2] + 36, R[0]);  /* 0x8008ECAC */
    sw_(R[2] + 40, R[0]);  /* 0x8008ECB0 */
    sb_(R[2] + 3, R[0]);  /* 0x8008ECB4 */
    sh_(R[2] + 54, R[0]);  /* 0x8008ECB8 */
    sw_(R[2] + 44, R[7]);  /* 0x8008ECBC */
    { sw_(R[2] + 16, R[3]); psx_next = R[31]; return; }  /* 0x8008ECC0 jr ra */
L_8008ECC8:;
    R[2] = ((int32_t)R[3] < 128);  /* 0x8008ECC8 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[5] + 72; if (_c) { psx_bb(); goto L_8008EC40; } }  /* 0x8008ECCC */
    { R[2] = R[0] + R[0]; psx_next = R[31]; return; }  /* 0x8008ECD4 jr ra */
}

void ev_8008ECDC(void) {
    R[29] = R[29] - 32;  /* 0x8008ECDC */
    sw_(R[29] + 20, R[17]);  /* 0x8008ECE0 */
    R[17] = R[0] + R[0];  /* 0x8008ECE4 */
    R[2] = 0x8008u << 16;  /* 0x8008ECE8 */
    sw_(R[29] + 24, R[18]);  /* 0x8008ECEC */
    R[18] = R[2] + 5432;  /* 0x8008ECF0 */
    R[2] = 0x800Fu << 16;  /* 0x8008ECF4 */
    sw_(R[29] + 16, R[16]);  /* 0x8008ECF8 */
    R[16] = R[2] - 15672;  /* 0x8008ECFC */
    sw_(R[29] + 28, R[31]);  /* 0x8008ED00 */
L_8008ED04:;
    R[2] = lh_(R[16]);  /* 0x8008ED04 */
    R[2] = R[2] & 0x8000;  /* 0x8008ED0C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008EE28; } }  /* 0x8008ED10 */
    R[3] = lb_(R[16] + 2);  /* 0x8008ED18 */
    R[2] = (R[3] < (uint32_t)16u);  /* 0x8008ED20 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] << 2; if (_c) { goto L_8008EE28; } }  /* 0x8008ED24 */
    R[2] = R[2] + R[18];  /* 0x8008ED2C */
    R[2] = lw_(R[2]);  /* 0x8008ED30 */
    { uint32_t _t = R[2]; psx_next = _t; return; }  /* 0x8008ED38 jr indirect */
    { R[31] = 0x8008ED48u; R[4] = R[16] + R[0]; psx_next = 0x8008D3FCu; return; }  /* 0x8008ED40 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED48 j */
    { R[31] = 0x8008ED58u; R[4] = R[16] + R[0]; psx_next = 0x8008DD64u; return; }  /* 0x8008ED50 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED58 j */
    { R[31] = 0x8008ED68u; R[4] = R[16] + R[0]; psx_next = 0x8008DB48u; return; }  /* 0x8008ED60 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED68 j */
    { R[31] = 0x8008ED78u; R[4] = R[16] + R[0]; psx_next = 0x8008DBECu; return; }  /* 0x8008ED70 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED78 j */
    { R[31] = 0x8008ED88u; R[4] = R[16] + R[0]; psx_next = 0x8008DC98u; return; }  /* 0x8008ED80 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED88 j */
    { R[31] = 0x8008ED98u; R[4] = R[16] + R[0]; psx_next = 0x8008DE84u; return; }  /* 0x8008ED90 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED98 j */
    { R[31] = 0x8008EDA8u; R[4] = R[16] + R[0]; psx_next = 0x8008E018u; return; }  /* 0x8008EDA0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDA8 j */
    { R[31] = 0x8008EDB8u; R[4] = R[16] + R[0]; psx_next = 0x8008E0A8u; return; }  /* 0x8008EDB0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDB8 j */
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
L_8008EE28:;
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_bb(); goto L_8008ED04; } }  /* 0x8008EE34 */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008ED04(void) {
L_8008ED04:;
    R[2] = lh_(R[16]);  /* 0x8008ED04 */
    R[2] = R[2] & 0x8000;  /* 0x8008ED0C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008EE28; } }  /* 0x8008ED10 */
    R[3] = lb_(R[16] + 2);  /* 0x8008ED18 */
    R[2] = (R[3] < (uint32_t)16u);  /* 0x8008ED20 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] << 2; if (_c) { goto L_8008EE28; } }  /* 0x8008ED24 */
    R[2] = R[2] + R[18];  /* 0x8008ED2C */
    R[2] = lw_(R[2]);  /* 0x8008ED30 */
    { uint32_t _t = R[2]; psx_next = _t; return; }  /* 0x8008ED38 jr indirect */
    { R[31] = 0x8008ED48u; R[4] = R[16] + R[0]; psx_next = 0x8008D3FCu; return; }  /* 0x8008ED40 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED48 j */
    { R[31] = 0x8008ED58u; R[4] = R[16] + R[0]; psx_next = 0x8008DD64u; return; }  /* 0x8008ED50 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED58 j */
    { R[31] = 0x8008ED68u; R[4] = R[16] + R[0]; psx_next = 0x8008DB48u; return; }  /* 0x8008ED60 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED68 j */
    { R[31] = 0x8008ED78u; R[4] = R[16] + R[0]; psx_next = 0x8008DBECu; return; }  /* 0x8008ED70 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED78 j */
    { R[31] = 0x8008ED88u; R[4] = R[16] + R[0]; psx_next = 0x8008DC98u; return; }  /* 0x8008ED80 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED88 j */
    { R[31] = 0x8008ED98u; R[4] = R[16] + R[0]; psx_next = 0x8008DE84u; return; }  /* 0x8008ED90 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED98 j */
    { R[31] = 0x8008EDA8u; R[4] = R[16] + R[0]; psx_next = 0x8008E018u; return; }  /* 0x8008EDA0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDA8 j */
    { R[31] = 0x8008EDB8u; R[4] = R[16] + R[0]; psx_next = 0x8008E0A8u; return; }  /* 0x8008EDB0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDB8 j */
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
L_8008EE28:;
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_bb(); goto L_8008ED04; } }  /* 0x8008EE34 */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008ED40(void) {
    { R[31] = 0x8008ED48u; R[4] = R[16] + R[0]; psx_next = 0x8008D3FCu; return; }  /* 0x8008ED40 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED48 j */
    { R[31] = 0x8008ED58u; R[4] = R[16] + R[0]; psx_next = 0x8008DD64u; return; }  /* 0x8008ED50 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED58 j */
    { R[31] = 0x8008ED68u; R[4] = R[16] + R[0]; psx_next = 0x8008DB48u; return; }  /* 0x8008ED60 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED68 j */
    { R[31] = 0x8008ED78u; R[4] = R[16] + R[0]; psx_next = 0x8008DBECu; return; }  /* 0x8008ED70 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED78 j */
    { R[31] = 0x8008ED88u; R[4] = R[16] + R[0]; psx_next = 0x8008DC98u; return; }  /* 0x8008ED80 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED88 j */
    { R[31] = 0x8008ED98u; R[4] = R[16] + R[0]; psx_next = 0x8008DE84u; return; }  /* 0x8008ED90 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED98 j */
    { R[31] = 0x8008EDA8u; R[4] = R[16] + R[0]; psx_next = 0x8008E018u; return; }  /* 0x8008EDA0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDA8 j */
    { R[31] = 0x8008EDB8u; R[4] = R[16] + R[0]; psx_next = 0x8008E0A8u; return; }  /* 0x8008EDB0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDB8 j */
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008ED48(void) {
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED48 j */
    { R[31] = 0x8008ED58u; R[4] = R[16] + R[0]; psx_next = 0x8008DD64u; return; }  /* 0x8008ED50 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED58 j */
    { R[31] = 0x8008ED68u; R[4] = R[16] + R[0]; psx_next = 0x8008DB48u; return; }  /* 0x8008ED60 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED68 j */
    { R[31] = 0x8008ED78u; R[4] = R[16] + R[0]; psx_next = 0x8008DBECu; return; }  /* 0x8008ED70 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED78 j */
    { R[31] = 0x8008ED88u; R[4] = R[16] + R[0]; psx_next = 0x8008DC98u; return; }  /* 0x8008ED80 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED88 j */
    { R[31] = 0x8008ED98u; R[4] = R[16] + R[0]; psx_next = 0x8008DE84u; return; }  /* 0x8008ED90 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED98 j */
    { R[31] = 0x8008EDA8u; R[4] = R[16] + R[0]; psx_next = 0x8008E018u; return; }  /* 0x8008EDA0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDA8 j */
    { R[31] = 0x8008EDB8u; R[4] = R[16] + R[0]; psx_next = 0x8008E0A8u; return; }  /* 0x8008EDB0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDB8 j */
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008ED50(void) {
    { R[31] = 0x8008ED58u; R[4] = R[16] + R[0]; psx_next = 0x8008DD64u; return; }  /* 0x8008ED50 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED58 j */
    { R[31] = 0x8008ED68u; R[4] = R[16] + R[0]; psx_next = 0x8008DB48u; return; }  /* 0x8008ED60 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED68 j */
    { R[31] = 0x8008ED78u; R[4] = R[16] + R[0]; psx_next = 0x8008DBECu; return; }  /* 0x8008ED70 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED78 j */
    { R[31] = 0x8008ED88u; R[4] = R[16] + R[0]; psx_next = 0x8008DC98u; return; }  /* 0x8008ED80 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED88 j */
    { R[31] = 0x8008ED98u; R[4] = R[16] + R[0]; psx_next = 0x8008DE84u; return; }  /* 0x8008ED90 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED98 j */
    { R[31] = 0x8008EDA8u; R[4] = R[16] + R[0]; psx_next = 0x8008E018u; return; }  /* 0x8008EDA0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDA8 j */
    { R[31] = 0x8008EDB8u; R[4] = R[16] + R[0]; psx_next = 0x8008E0A8u; return; }  /* 0x8008EDB0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDB8 j */
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008ED58(void) {
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED58 j */
    { R[31] = 0x8008ED68u; R[4] = R[16] + R[0]; psx_next = 0x8008DB48u; return; }  /* 0x8008ED60 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED68 j */
    { R[31] = 0x8008ED78u; R[4] = R[16] + R[0]; psx_next = 0x8008DBECu; return; }  /* 0x8008ED70 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED78 j */
    { R[31] = 0x8008ED88u; R[4] = R[16] + R[0]; psx_next = 0x8008DC98u; return; }  /* 0x8008ED80 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED88 j */
    { R[31] = 0x8008ED98u; R[4] = R[16] + R[0]; psx_next = 0x8008DE84u; return; }  /* 0x8008ED90 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED98 j */
    { R[31] = 0x8008EDA8u; R[4] = R[16] + R[0]; psx_next = 0x8008E018u; return; }  /* 0x8008EDA0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDA8 j */
    { R[31] = 0x8008EDB8u; R[4] = R[16] + R[0]; psx_next = 0x8008E0A8u; return; }  /* 0x8008EDB0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDB8 j */
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008ED60(void) {
    { R[31] = 0x8008ED68u; R[4] = R[16] + R[0]; psx_next = 0x8008DB48u; return; }  /* 0x8008ED60 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED68 j */
    { R[31] = 0x8008ED78u; R[4] = R[16] + R[0]; psx_next = 0x8008DBECu; return; }  /* 0x8008ED70 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED78 j */
    { R[31] = 0x8008ED88u; R[4] = R[16] + R[0]; psx_next = 0x8008DC98u; return; }  /* 0x8008ED80 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED88 j */
    { R[31] = 0x8008ED98u; R[4] = R[16] + R[0]; psx_next = 0x8008DE84u; return; }  /* 0x8008ED90 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED98 j */
    { R[31] = 0x8008EDA8u; R[4] = R[16] + R[0]; psx_next = 0x8008E018u; return; }  /* 0x8008EDA0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDA8 j */
    { R[31] = 0x8008EDB8u; R[4] = R[16] + R[0]; psx_next = 0x8008E0A8u; return; }  /* 0x8008EDB0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDB8 j */
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008ED68(void) {
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED68 j */
    { R[31] = 0x8008ED78u; R[4] = R[16] + R[0]; psx_next = 0x8008DBECu; return; }  /* 0x8008ED70 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED78 j */
    { R[31] = 0x8008ED88u; R[4] = R[16] + R[0]; psx_next = 0x8008DC98u; return; }  /* 0x8008ED80 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED88 j */
    { R[31] = 0x8008ED98u; R[4] = R[16] + R[0]; psx_next = 0x8008DE84u; return; }  /* 0x8008ED90 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED98 j */
    { R[31] = 0x8008EDA8u; R[4] = R[16] + R[0]; psx_next = 0x8008E018u; return; }  /* 0x8008EDA0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDA8 j */
    { R[31] = 0x8008EDB8u; R[4] = R[16] + R[0]; psx_next = 0x8008E0A8u; return; }  /* 0x8008EDB0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDB8 j */
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008ED70(void) {
    { R[31] = 0x8008ED78u; R[4] = R[16] + R[0]; psx_next = 0x8008DBECu; return; }  /* 0x8008ED70 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED78 j */
    { R[31] = 0x8008ED88u; R[4] = R[16] + R[0]; psx_next = 0x8008DC98u; return; }  /* 0x8008ED80 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED88 j */
    { R[31] = 0x8008ED98u; R[4] = R[16] + R[0]; psx_next = 0x8008DE84u; return; }  /* 0x8008ED90 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED98 j */
    { R[31] = 0x8008EDA8u; R[4] = R[16] + R[0]; psx_next = 0x8008E018u; return; }  /* 0x8008EDA0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDA8 j */
    { R[31] = 0x8008EDB8u; R[4] = R[16] + R[0]; psx_next = 0x8008E0A8u; return; }  /* 0x8008EDB0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDB8 j */
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008ED78(void) {
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED78 j */
    { R[31] = 0x8008ED88u; R[4] = R[16] + R[0]; psx_next = 0x8008DC98u; return; }  /* 0x8008ED80 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED88 j */
    { R[31] = 0x8008ED98u; R[4] = R[16] + R[0]; psx_next = 0x8008DE84u; return; }  /* 0x8008ED90 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED98 j */
    { R[31] = 0x8008EDA8u; R[4] = R[16] + R[0]; psx_next = 0x8008E018u; return; }  /* 0x8008EDA0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDA8 j */
    { R[31] = 0x8008EDB8u; R[4] = R[16] + R[0]; psx_next = 0x8008E0A8u; return; }  /* 0x8008EDB0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDB8 j */
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008ED80(void) {
    { R[31] = 0x8008ED88u; R[4] = R[16] + R[0]; psx_next = 0x8008DC98u; return; }  /* 0x8008ED80 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED88 j */
    { R[31] = 0x8008ED98u; R[4] = R[16] + R[0]; psx_next = 0x8008DE84u; return; }  /* 0x8008ED90 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED98 j */
    { R[31] = 0x8008EDA8u; R[4] = R[16] + R[0]; psx_next = 0x8008E018u; return; }  /* 0x8008EDA0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDA8 j */
    { R[31] = 0x8008EDB8u; R[4] = R[16] + R[0]; psx_next = 0x8008E0A8u; return; }  /* 0x8008EDB0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDB8 j */
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008ED88(void) {
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED88 j */
    { R[31] = 0x8008ED98u; R[4] = R[16] + R[0]; psx_next = 0x8008DE84u; return; }  /* 0x8008ED90 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED98 j */
    { R[31] = 0x8008EDA8u; R[4] = R[16] + R[0]; psx_next = 0x8008E018u; return; }  /* 0x8008EDA0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDA8 j */
    { R[31] = 0x8008EDB8u; R[4] = R[16] + R[0]; psx_next = 0x8008E0A8u; return; }  /* 0x8008EDB0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDB8 j */
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008ED90(void) {
    { R[31] = 0x8008ED98u; R[4] = R[16] + R[0]; psx_next = 0x8008DE84u; return; }  /* 0x8008ED90 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED98 j */
    { R[31] = 0x8008EDA8u; R[4] = R[16] + R[0]; psx_next = 0x8008E018u; return; }  /* 0x8008EDA0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDA8 j */
    { R[31] = 0x8008EDB8u; R[4] = R[16] + R[0]; psx_next = 0x8008E0A8u; return; }  /* 0x8008EDB0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDB8 j */
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008ED98(void) {
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008ED98 j */
    { R[31] = 0x8008EDA8u; R[4] = R[16] + R[0]; psx_next = 0x8008E018u; return; }  /* 0x8008EDA0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDA8 j */
    { R[31] = 0x8008EDB8u; R[4] = R[16] + R[0]; psx_next = 0x8008E0A8u; return; }  /* 0x8008EDB0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDB8 j */
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EDA0(void) {
    { R[31] = 0x8008EDA8u; R[4] = R[16] + R[0]; psx_next = 0x8008E018u; return; }  /* 0x8008EDA0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDA8 j */
    { R[31] = 0x8008EDB8u; R[4] = R[16] + R[0]; psx_next = 0x8008E0A8u; return; }  /* 0x8008EDB0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDB8 j */
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EDA8(void) {
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDA8 j */
    { R[31] = 0x8008EDB8u; R[4] = R[16] + R[0]; psx_next = 0x8008E0A8u; return; }  /* 0x8008EDB0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDB8 j */
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EDB0(void) {
    { R[31] = 0x8008EDB8u; R[4] = R[16] + R[0]; psx_next = 0x8008E0A8u; return; }  /* 0x8008EDB0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDB8 j */
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EDB8(void) {
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDB8 j */
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EDC0(void) {
    { R[31] = 0x8008EDC8u; R[4] = R[16] + R[0]; psx_next = 0x8008E174u; return; }  /* 0x8008EDC0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EDC8(void) {
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDC8 j */
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EDD0(void) {
    { R[31] = 0x8008EDD8u; R[4] = R[16] + R[0]; psx_next = 0x8008E228u; return; }  /* 0x8008EDD0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EDD8(void) {
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDD8 j */
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EDE0(void) {
    { R[31] = 0x8008EDE8u; R[4] = R[16] + R[0]; psx_next = 0x8008E390u; return; }  /* 0x8008EDE0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EDE8(void) {
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDE8 j */
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EDF0(void) {
    { R[31] = 0x8008EDF8u; R[4] = R[16] + R[0]; psx_next = 0x8008E4C0u; return; }  /* 0x8008EDF0 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EDF8(void) {
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EDF8 j */
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EE00(void) {
    { R[31] = 0x8008EE08u; R[4] = R[16] + R[0]; psx_next = 0x8008DAACu; return; }  /* 0x8008EE00 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EE08(void) {
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE08 j */
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EE10(void) {
    { R[31] = 0x8008EE18u; R[4] = R[16] + R[0]; psx_next = 0x8008D938u; return; }  /* 0x8008EE10 jal */
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EE18(void) {
    { R[16] = R[16] + 72; goto L_8008EE2C; }  /* 0x8008EE18 j */
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
L_8008EE2C:;
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EE20(void) {
    { R[31] = 0x8008EE28u; R[4] = R[16] + R[0]; psx_next = 0x8008D9FCu; return; }  /* 0x8008EE20 jal */
    R[16] = R[16] + 72;  /* 0x8008EE28 */
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EE28(void) {
    R[16] = R[16] + 72;  /* 0x8008EE28 */
    R[17] = R[17] + 1;  /* 0x8008EE2C */
    R[2] = ((int32_t)R[17] < 128);  /* 0x8008EE30 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008ED04u; return; } }  /* 0x8008EE34 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008EE3C */
    R[18] = lw_(R[29] + 24);  /* 0x8008EE40 */
    R[17] = lw_(R[29] + 20);  /* 0x8008EE44 */
    R[16] = lw_(R[29] + 16);  /* 0x8008EE48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008EE4C jr ra */
}

void ev_8008EE54(void) {
    R[29] = R[29] - 40;  /* 0x8008EE54 */
    R[3] = R[5] - 10;  /* 0x8008EE58 */
    R[8] = lw_(R[29] + 56);  /* 0x8008EE5C */
    R[2] = (R[3] < (uint32_t)91u);  /* 0x8008EE60 */
    sw_(R[29] + 32, R[31]);  /* 0x8008EE64 */
    sw_(R[29] + 28, R[19]);  /* 0x8008EE68 */
    sw_(R[29] + 24, R[18]);  /* 0x8008EE6C */
    sw_(R[29] + 20, R[17]);  /* 0x8008EE70 */
    sw_(R[29] + 16, R[16]);  /* 0x8008EE74 */
    sw_(R[4] + 948, R[5]);  /* 0x8008EE78 */
    sw_(R[4] + 952, R[6]);  /* 0x8008EE7C */
    sw_(R[4] + 956, R[7]);  /* 0x8008EE80 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[4] + 960, R[8]); if (_c) { psx_next = 0x8008F130u; return; } }  /* 0x8008EE84 b extern */
    R[2] = 0x8008u << 16;  /* 0x8008EE8C */
    R[2] = R[2] + 5496;  /* 0x8008EE90 */
    R[3] = R[3] << 2;  /* 0x8008EE94 */
    R[3] = R[3] + R[2];  /* 0x8008EE98 */
    R[2] = lw_(R[3]);  /* 0x8008EE9C */
    { uint32_t _t = R[2]; psx_next = _t; return; }  /* 0x8008EEA4 jr indirect */
    { R[31] = 0x8008EEB4u; R[4] = R[4] + 1156; psx_next = 0x8008F280u; return; }  /* 0x8008EEAC jal */
    R[4] = R[0] + 22012;  /* 0x8008EEB4 */
    { R[31] = 0x8008EEC0u; R[17] = R[2] + R[0]; psx_next = 0x8008F198u; return; }  /* 0x8008EEB8 jal */
    R[16] = R[2] + R[0];  /* 0x8008EEC0 */
    R[4] = R[16] + R[0];  /* 0x8008EEC4 */
    R[5] = R[0] + R[0];  /* 0x8008EEC8 */
    R[6] = R[0] + 22012;  /* 0x8008EECC */
    { R[31] = 0x8008EED8u; sw_(R[17], R[16]); psx_next = 0x80030E58u; return; }  /* 0x8008EED0 jal */
    R[2] = R[0] + 11;  /* 0x8008EED8 */
    sw_(R[16] + 4, R[2]);  /* 0x8008EEDC */
    sw_(R[16], R[0]);  /* 0x8008EEE0 */
    { sw_(R[16] + 22008, R[0]); psx_next = 0x8008F130u; return; }  /* 0x8008EEE4 j extern */
    R[5] = R[0] + R[0];  /* 0x8008EEEC */
    R[6] = R[0] + 150;  /* 0x8008EEF0 */
    R[2] = 0x800Bu << 16;  /* 0x8008EEF4 */
    R[7] = R[2] + 19304;  /* 0x8008EEF8 */
    R[3] = R[7] + R[0];  /* 0x8008EEFC */
L_8008EF00:;
    { uint32_t _c = (R[5] == R[6]); if (_c) { psx_next = 0x8008F130u; return; } }  /* 0x8008EF00 b extern */
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x8008EF08 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[3] + 136; if (_c) { goto L_8008EF20; } }  /* 0x8008EF10 */
    { R[5] = R[5] + 2; psx_bb(); goto L_8008EF00; }  /* 0x8008EF18 j */
L_8008EF20:;
    R[2] = R[5] << 4;  /* 0x8008EF20 */
    R[2] = R[2] + R[5];  /* 0x8008EF24 */
    R[2] = R[2] << 2;  /* 0x8008EF28 */
    R[2] = R[2] + R[7];  /* 0x8008EF2C */
    R[3] = R[0] + 4;  /* 0x8008EF30 */
    sh_(R[2], R[3]);  /* 0x8008EF34 */
    sh_(R[2] + 2, R[0]);  /* 0x8008EF38 */
    { sw_(R[2] + 4, R[4]); psx_next = 0x8008F130u; return; }  /* 0x8008EF3C j extern */
    { sw_(R[4] + 960, R[0]); psx_next = 0x8008F130u; return; }  /* 0x8008EF44 j extern */
    R[2] = R[0] + 255;  /* 0x8008EF4C */
    psx_next = 0x8008EF50u; return;  /* fallthrough */
}

void ev_8008EEAC(void) {
    { R[31] = 0x8008EEB4u; R[4] = R[4] + 1156; psx_next = 0x8008F280u; return; }  /* 0x8008EEAC jal */
    R[4] = R[0] + 22012;  /* 0x8008EEB4 */
    { R[31] = 0x8008EEC0u; R[17] = R[2] + R[0]; psx_next = 0x8008F198u; return; }  /* 0x8008EEB8 jal */
    R[16] = R[2] + R[0];  /* 0x8008EEC0 */
    R[4] = R[16] + R[0];  /* 0x8008EEC4 */
    R[5] = R[0] + R[0];  /* 0x8008EEC8 */
    R[6] = R[0] + 22012;  /* 0x8008EECC */
    { R[31] = 0x8008EED8u; sw_(R[17], R[16]); psx_next = 0x80030E58u; return; }  /* 0x8008EED0 jal */
    R[2] = R[0] + 11;  /* 0x8008EED8 */
    sw_(R[16] + 4, R[2]);  /* 0x8008EEDC */
    sw_(R[16], R[0]);  /* 0x8008EEE0 */
    { sw_(R[16] + 22008, R[0]); psx_next = 0x8008F130u; return; }  /* 0x8008EEE4 j extern */
    R[5] = R[0] + R[0];  /* 0x8008EEEC */
    R[6] = R[0] + 150;  /* 0x8008EEF0 */
    R[2] = 0x800Bu << 16;  /* 0x8008EEF4 */
    R[7] = R[2] + 19304;  /* 0x8008EEF8 */
    R[3] = R[7] + R[0];  /* 0x8008EEFC */
L_8008EF00:;
    { uint32_t _c = (R[5] == R[6]); if (_c) { psx_next = 0x8008F130u; return; } }  /* 0x8008EF00 b extern */
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x8008EF08 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[3] + 136; if (_c) { goto L_8008EF20; } }  /* 0x8008EF10 */
    { R[5] = R[5] + 2; psx_bb(); goto L_8008EF00; }  /* 0x8008EF18 j */
L_8008EF20:;
    R[2] = R[5] << 4;  /* 0x8008EF20 */
    R[2] = R[2] + R[5];  /* 0x8008EF24 */
    R[2] = R[2] << 2;  /* 0x8008EF28 */
    R[2] = R[2] + R[7];  /* 0x8008EF2C */
    R[3] = R[0] + 4;  /* 0x8008EF30 */
    sh_(R[2], R[3]);  /* 0x8008EF34 */
    sh_(R[2] + 2, R[0]);  /* 0x8008EF38 */
    { sw_(R[2] + 4, R[4]); psx_next = 0x8008F130u; return; }  /* 0x8008EF3C j extern */
    { sw_(R[4] + 960, R[0]); psx_next = 0x8008F130u; return; }  /* 0x8008EF44 j extern */
    R[2] = R[0] + 255;  /* 0x8008EF4C */
    psx_next = 0x8008EF50u; return;  /* fallthrough */
}

void ev_8008EEB4(void) {
    R[4] = R[0] + 22012;  /* 0x8008EEB4 */
    { R[31] = 0x8008EEC0u; R[17] = R[2] + R[0]; psx_next = 0x8008F198u; return; }  /* 0x8008EEB8 jal */
    R[16] = R[2] + R[0];  /* 0x8008EEC0 */
    R[4] = R[16] + R[0];  /* 0x8008EEC4 */
    R[5] = R[0] + R[0];  /* 0x8008EEC8 */
    R[6] = R[0] + 22012;  /* 0x8008EECC */
    { R[31] = 0x8008EED8u; sw_(R[17], R[16]); psx_next = 0x80030E58u; return; }  /* 0x8008EED0 jal */
    R[2] = R[0] + 11;  /* 0x8008EED8 */
    sw_(R[16] + 4, R[2]);  /* 0x8008EEDC */
    sw_(R[16], R[0]);  /* 0x8008EEE0 */
    { sw_(R[16] + 22008, R[0]); psx_next = 0x8008F130u; return; }  /* 0x8008EEE4 j extern */
    R[5] = R[0] + R[0];  /* 0x8008EEEC */
    R[6] = R[0] + 150;  /* 0x8008EEF0 */
    R[2] = 0x800Bu << 16;  /* 0x8008EEF4 */
    R[7] = R[2] + 19304;  /* 0x8008EEF8 */
    R[3] = R[7] + R[0];  /* 0x8008EEFC */
L_8008EF00:;
    { uint32_t _c = (R[5] == R[6]); if (_c) { psx_next = 0x8008F130u; return; } }  /* 0x8008EF00 b extern */
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x8008EF08 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[3] + 136; if (_c) { goto L_8008EF20; } }  /* 0x8008EF10 */
    { R[5] = R[5] + 2; psx_bb(); goto L_8008EF00; }  /* 0x8008EF18 j */
L_8008EF20:;
    R[2] = R[5] << 4;  /* 0x8008EF20 */
    R[2] = R[2] + R[5];  /* 0x8008EF24 */
    R[2] = R[2] << 2;  /* 0x8008EF28 */
    R[2] = R[2] + R[7];  /* 0x8008EF2C */
    R[3] = R[0] + 4;  /* 0x8008EF30 */
    sh_(R[2], R[3]);  /* 0x8008EF34 */
    sh_(R[2] + 2, R[0]);  /* 0x8008EF38 */
    { sw_(R[2] + 4, R[4]); psx_next = 0x8008F130u; return; }  /* 0x8008EF3C j extern */
    { sw_(R[4] + 960, R[0]); psx_next = 0x8008F130u; return; }  /* 0x8008EF44 j extern */
    R[2] = R[0] + 255;  /* 0x8008EF4C */
    psx_next = 0x8008EF50u; return;  /* fallthrough */
}

void ev_8008EEC0(void) {
    R[16] = R[2] + R[0];  /* 0x8008EEC0 */
    R[4] = R[16] + R[0];  /* 0x8008EEC4 */
    R[5] = R[0] + R[0];  /* 0x8008EEC8 */
    R[6] = R[0] + 22012;  /* 0x8008EECC */
    { R[31] = 0x8008EED8u; sw_(R[17], R[16]); psx_next = 0x80030E58u; return; }  /* 0x8008EED0 jal */
    R[2] = R[0] + 11;  /* 0x8008EED8 */
    sw_(R[16] + 4, R[2]);  /* 0x8008EEDC */
    sw_(R[16], R[0]);  /* 0x8008EEE0 */
    { sw_(R[16] + 22008, R[0]); psx_next = 0x8008F130u; return; }  /* 0x8008EEE4 j extern */
    R[5] = R[0] + R[0];  /* 0x8008EEEC */
    R[6] = R[0] + 150;  /* 0x8008EEF0 */
    R[2] = 0x800Bu << 16;  /* 0x8008EEF4 */
    R[7] = R[2] + 19304;  /* 0x8008EEF8 */
    R[3] = R[7] + R[0];  /* 0x8008EEFC */
L_8008EF00:;
    { uint32_t _c = (R[5] == R[6]); if (_c) { psx_next = 0x8008F130u; return; } }  /* 0x8008EF00 b extern */
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x8008EF08 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[3] + 136; if (_c) { goto L_8008EF20; } }  /* 0x8008EF10 */
    { R[5] = R[5] + 2; psx_bb(); goto L_8008EF00; }  /* 0x8008EF18 j */
L_8008EF20:;
    R[2] = R[5] << 4;  /* 0x8008EF20 */
    R[2] = R[2] + R[5];  /* 0x8008EF24 */
    R[2] = R[2] << 2;  /* 0x8008EF28 */
    R[2] = R[2] + R[7];  /* 0x8008EF2C */
    R[3] = R[0] + 4;  /* 0x8008EF30 */
    sh_(R[2], R[3]);  /* 0x8008EF34 */
    sh_(R[2] + 2, R[0]);  /* 0x8008EF38 */
    { sw_(R[2] + 4, R[4]); psx_next = 0x8008F130u; return; }  /* 0x8008EF3C j extern */
    { sw_(R[4] + 960, R[0]); psx_next = 0x8008F130u; return; }  /* 0x8008EF44 j extern */
    R[2] = R[0] + 255;  /* 0x8008EF4C */
    psx_next = 0x8008EF50u; return;  /* fallthrough */
}

void ev_8008EED8(void) {
    R[2] = R[0] + 11;  /* 0x8008EED8 */
    sw_(R[16] + 4, R[2]);  /* 0x8008EEDC */
    sw_(R[16], R[0]);  /* 0x8008EEE0 */
    { sw_(R[16] + 22008, R[0]); psx_next = 0x8008F130u; return; }  /* 0x8008EEE4 j extern */
    R[5] = R[0] + R[0];  /* 0x8008EEEC */
    R[6] = R[0] + 150;  /* 0x8008EEF0 */
    R[2] = 0x800Bu << 16;  /* 0x8008EEF4 */
    R[7] = R[2] + 19304;  /* 0x8008EEF8 */
    R[3] = R[7] + R[0];  /* 0x8008EEFC */
L_8008EF00:;
    { uint32_t _c = (R[5] == R[6]); if (_c) { psx_next = 0x8008F130u; return; } }  /* 0x8008EF00 b extern */
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x8008EF08 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[3] + 136; if (_c) { goto L_8008EF20; } }  /* 0x8008EF10 */
    { R[5] = R[5] + 2; psx_bb(); goto L_8008EF00; }  /* 0x8008EF18 j */
L_8008EF20:;
    R[2] = R[5] << 4;  /* 0x8008EF20 */
    R[2] = R[2] + R[5];  /* 0x8008EF24 */
    R[2] = R[2] << 2;  /* 0x8008EF28 */
    R[2] = R[2] + R[7];  /* 0x8008EF2C */
    R[3] = R[0] + 4;  /* 0x8008EF30 */
    sh_(R[2], R[3]);  /* 0x8008EF34 */
    sh_(R[2] + 2, R[0]);  /* 0x8008EF38 */
    { sw_(R[2] + 4, R[4]); psx_next = 0x8008F130u; return; }  /* 0x8008EF3C j extern */
    { sw_(R[4] + 960, R[0]); psx_next = 0x8008F130u; return; }  /* 0x8008EF44 j extern */
    R[2] = R[0] + 255;  /* 0x8008EF4C */
    psx_next = 0x8008EF50u; return;  /* fallthrough */
}

void ev_8008EEEC(void) {
    R[5] = R[0] + R[0];  /* 0x8008EEEC */
    R[6] = R[0] + 150;  /* 0x8008EEF0 */
    R[2] = 0x800Bu << 16;  /* 0x8008EEF4 */
    R[7] = R[2] + 19304;  /* 0x8008EEF8 */
    R[3] = R[7] + R[0];  /* 0x8008EEFC */
L_8008EF00:;
    { uint32_t _c = (R[5] == R[6]); if (_c) { psx_next = 0x8008F130u; return; } }  /* 0x8008EF00 b extern */
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x8008EF08 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[3] + 136; if (_c) { goto L_8008EF20; } }  /* 0x8008EF10 */
    { R[5] = R[5] + 2; psx_bb(); goto L_8008EF00; }  /* 0x8008EF18 j */
L_8008EF20:;
    R[2] = R[5] << 4;  /* 0x8008EF20 */
    R[2] = R[2] + R[5];  /* 0x8008EF24 */
    R[2] = R[2] << 2;  /* 0x8008EF28 */
    R[2] = R[2] + R[7];  /* 0x8008EF2C */
    R[3] = R[0] + 4;  /* 0x8008EF30 */
    sh_(R[2], R[3]);  /* 0x8008EF34 */
    sh_(R[2] + 2, R[0]);  /* 0x8008EF38 */
    { sw_(R[2] + 4, R[4]); psx_next = 0x8008F130u; return; }  /* 0x8008EF3C j extern */
    { sw_(R[4] + 960, R[0]); psx_next = 0x8008F130u; return; }  /* 0x8008EF44 j extern */
    R[2] = R[0] + 255;  /* 0x8008EF4C */
    psx_next = 0x8008EF50u; return;  /* fallthrough */
}

void ev_8008EF44(void) {
    { sw_(R[4] + 960, R[0]); psx_next = 0x8008F130u; return; }  /* 0x8008EF44 j extern */
    R[2] = R[0] + 255;  /* 0x8008EF4C */
    psx_next = 0x8008EF50u; return;  /* fallthrough */
}

void ev_8008EF4C(void) {
    R[2] = R[0] + 255;  /* 0x8008EF4C */
    psx_next = 0x8008EF50u; return;  /* fallthrough */
}

void ev_8008EF50(void) {
    sw_(R[4] + 952, R[0]);  /* 0x8008EF50 */
    sw_(R[4] + 956, R[2]);  /* 0x8008EF54 */
    { sw_(R[4] + 960, R[2]); psx_next = 0x8008F130u; return; }  /* 0x8008EF58 j extern */
    { sw_(R[4] + 948, R[0]); psx_next = 0x8008F130u; return; }  /* 0x8008EF60 j extern */
    R[2] = R[6] << 16;  /* 0x8008EF68 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008EF6C */
    sw_(R[4] + 952, R[2]);  /* 0x8008EF70 */
    R[2] = R[7] << 16;  /* 0x8008EF74 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008EF78 */
    sw_(R[4] + 956, R[2]);  /* 0x8008EF7C */
    R[2] = R[8] << 16;  /* 0x8008EF80 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008EF84 */
    { sw_(R[4] + 960, R[2]); psx_next = 0x8008F130u; return; }  /* 0x8008EF88 j extern */
    R[17] = R[0] + R[0];  /* 0x8008EF90 */
    R[2] = 0x800Bu << 16;  /* 0x8008EF94 */
    R[5] = R[2] + 30184;  /* 0x8008EF98 */
    R[3] = R[0] - 1;  /* 0x8008EF9C */
    R[2] = R[17] << 16;  /* 0x8008EFA0 */
L_8008EFA4:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008EFA4 */
    R[2] = R[2] + R[5];  /* 0x8008EFA8 */
    R[2] = lw_(R[2]);  /* 0x8008EFAC */
    { uint32_t _c = (R[2] == R[3]); R[2] = R[17] + 1; if (_c) { goto L_8008EFD4; } }  /* 0x8008EFB4 */
    R[17] = R[2] + R[0];  /* 0x8008EFBC */
    R[2] = R[2] << 16;  /* 0x8008EFC0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008EFC4 */
    R[2] = ((int32_t)R[2] < 4);  /* 0x8008EFC8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[17] << 16; if (_c) { psx_bb(); goto L_8008EFA4; } }  /* 0x8008EFCC */
L_8008EFD4:;
    R[2] = R[17] << 16;  /* 0x8008EFD4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008EFD8 */
    R[3] = lw_(R[4] + 948);  /* 0x8008EFDC */
    R[2] = R[2] + R[5];  /* 0x8008EFE0 */
    sw_(R[2], R[3]);  /* 0x8008EFE4 */
    R[3] = lw_(R[4] + 952);  /* 0x8008EFE8 */
    sw_(R[2] + 4, R[3]);  /* 0x8008EFF0 */
    R[3] = lw_(R[4] + 956);  /* 0x8008EFF4 */
    sw_(R[2] + 8, R[3]);  /* 0x8008EFFC */
    R[3] = lw_(R[4] + 960);  /* 0x8008F000 */
    { sw_(R[2] + 12, R[3]); psx_next = 0x8008F130u; return; }  /* 0x8008F004 j extern */
    R[17] = R[0] + R[0];  /* 0x8008F00C */
    R[2] = 0x800Bu << 16;  /* 0x8008F010 */
    R[6] = R[2] + 30184;  /* 0x8008F014 */
    R[5] = R[0] + 12;  /* 0x8008F018 */
    R[4] = R[0] - 1;  /* 0x8008F01C */
    R[2] = R[17] << 16;  /* 0x8008F020 */
L_8008F024:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008F024 */
    R[3] = R[2] + R[6];  /* 0x8008F028 */
    R[2] = lw_(R[3]);  /* 0x8008F02C */
    { uint32_t _c = (R[2] != R[5]); R[2] = R[17] + 1; if (_c) { goto L_8008F04C; } }  /* 0x8008F034 */
    sw_(R[3], R[4]);  /* 0x8008F03C */
    sw_(R[3] + 4, R[0]);  /* 0x8008F040 */
    sw_(R[3] + 8, R[0]);  /* 0x8008F044 */
    sw_(R[3] + 12, R[0]);  /* 0x8008F048 */
L_8008F04C:;
    R[17] = R[2] + R[0];  /* 0x8008F04C */
    R[2] = R[2] << 16;  /* 0x8008F050 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008F054 */
    R[2] = ((int32_t)R[2] < 4);  /* 0x8008F058 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[17] << 16; if (_c) { psx_bb(); goto L_8008F024; } }  /* 0x8008F05C */
    { psx_next = 0x8008F130u; return; }  /* 0x8008F064 j extern */
    sh_(R[4] + 1240, R[0]);  /* 0x8008F06C */
    R[17] = R[0] + R[0];  /* 0x8008F070 */
    R[2] = 0x800Du << 16;  /* 0x8008F074 */
    R[19] = R[2] + 19496;  /* 0x8008F078 */
    R[2] = 0x800Eu << 16;  /* 0x8008F07C */
    psx_next = 0x8008F080u; return;  /* fallthrough */
}

void ev_8008EF60(void) {
    { sw_(R[4] + 948, R[0]); psx_next = 0x8008F130u; return; }  /* 0x8008EF60 j extern */
    R[2] = R[6] << 16;  /* 0x8008EF68 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008EF6C */
    sw_(R[4] + 952, R[2]);  /* 0x8008EF70 */
    R[2] = R[7] << 16;  /* 0x8008EF74 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008EF78 */
    sw_(R[4] + 956, R[2]);  /* 0x8008EF7C */
    R[2] = R[8] << 16;  /* 0x8008EF80 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008EF84 */
    { sw_(R[4] + 960, R[2]); psx_next = 0x8008F130u; return; }  /* 0x8008EF88 j extern */
    R[17] = R[0] + R[0];  /* 0x8008EF90 */
    R[2] = 0x800Bu << 16;  /* 0x8008EF94 */
    R[5] = R[2] + 30184;  /* 0x8008EF98 */
    R[3] = R[0] - 1;  /* 0x8008EF9C */
    R[2] = R[17] << 16;  /* 0x8008EFA0 */
L_8008EFA4:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008EFA4 */
    R[2] = R[2] + R[5];  /* 0x8008EFA8 */
    R[2] = lw_(R[2]);  /* 0x8008EFAC */
    { uint32_t _c = (R[2] == R[3]); R[2] = R[17] + 1; if (_c) { goto L_8008EFD4; } }  /* 0x8008EFB4 */
    R[17] = R[2] + R[0];  /* 0x8008EFBC */
    R[2] = R[2] << 16;  /* 0x8008EFC0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008EFC4 */
    R[2] = ((int32_t)R[2] < 4);  /* 0x8008EFC8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[17] << 16; if (_c) { psx_bb(); goto L_8008EFA4; } }  /* 0x8008EFCC */
L_8008EFD4:;
    R[2] = R[17] << 16;  /* 0x8008EFD4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008EFD8 */
    R[3] = lw_(R[4] + 948);  /* 0x8008EFDC */
    R[2] = R[2] + R[5];  /* 0x8008EFE0 */
    sw_(R[2], R[3]);  /* 0x8008EFE4 */
    R[3] = lw_(R[4] + 952);  /* 0x8008EFE8 */
    sw_(R[2] + 4, R[3]);  /* 0x8008EFF0 */
    R[3] = lw_(R[4] + 956);  /* 0x8008EFF4 */
    sw_(R[2] + 8, R[3]);  /* 0x8008EFFC */
    R[3] = lw_(R[4] + 960);  /* 0x8008F000 */
    { sw_(R[2] + 12, R[3]); psx_next = 0x8008F130u; return; }  /* 0x8008F004 j extern */
    R[17] = R[0] + R[0];  /* 0x8008F00C */
    R[2] = 0x800Bu << 16;  /* 0x8008F010 */
    R[6] = R[2] + 30184;  /* 0x8008F014 */
    R[5] = R[0] + 12;  /* 0x8008F018 */
    R[4] = R[0] - 1;  /* 0x8008F01C */
    R[2] = R[17] << 16;  /* 0x8008F020 */
L_8008F024:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008F024 */
    R[3] = R[2] + R[6];  /* 0x8008F028 */
    R[2] = lw_(R[3]);  /* 0x8008F02C */
    { uint32_t _c = (R[2] != R[5]); R[2] = R[17] + 1; if (_c) { goto L_8008F04C; } }  /* 0x8008F034 */
    sw_(R[3], R[4]);  /* 0x8008F03C */
    sw_(R[3] + 4, R[0]);  /* 0x8008F040 */
    sw_(R[3] + 8, R[0]);  /* 0x8008F044 */
    sw_(R[3] + 12, R[0]);  /* 0x8008F048 */
L_8008F04C:;
    R[17] = R[2] + R[0];  /* 0x8008F04C */
    R[2] = R[2] << 16;  /* 0x8008F050 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008F054 */
    R[2] = ((int32_t)R[2] < 4);  /* 0x8008F058 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[17] << 16; if (_c) { psx_bb(); goto L_8008F024; } }  /* 0x8008F05C */
    { psx_next = 0x8008F130u; return; }  /* 0x8008F064 j extern */
    sh_(R[4] + 1240, R[0]);  /* 0x8008F06C */
    R[17] = R[0] + R[0];  /* 0x8008F070 */
    R[2] = 0x800Du << 16;  /* 0x8008F074 */
    R[19] = R[2] + 19496;  /* 0x8008F078 */
    R[2] = 0x800Eu << 16;  /* 0x8008F07C */
    psx_next = 0x8008F080u; return;  /* fallthrough */
}

void ev_8008EF68(void) {
    R[2] = R[6] << 16;  /* 0x8008EF68 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008EF6C */
    sw_(R[4] + 952, R[2]);  /* 0x8008EF70 */
    R[2] = R[7] << 16;  /* 0x8008EF74 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008EF78 */
    sw_(R[4] + 956, R[2]);  /* 0x8008EF7C */
    R[2] = R[8] << 16;  /* 0x8008EF80 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008EF84 */
    { sw_(R[4] + 960, R[2]); psx_next = 0x8008F130u; return; }  /* 0x8008EF88 j extern */
    R[17] = R[0] + R[0];  /* 0x8008EF90 */
    R[2] = 0x800Bu << 16;  /* 0x8008EF94 */
    R[5] = R[2] + 30184;  /* 0x8008EF98 */
    R[3] = R[0] - 1;  /* 0x8008EF9C */
    R[2] = R[17] << 16;  /* 0x8008EFA0 */
L_8008EFA4:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008EFA4 */
    R[2] = R[2] + R[5];  /* 0x8008EFA8 */
    R[2] = lw_(R[2]);  /* 0x8008EFAC */
    { uint32_t _c = (R[2] == R[3]); R[2] = R[17] + 1; if (_c) { goto L_8008EFD4; } }  /* 0x8008EFB4 */
    R[17] = R[2] + R[0];  /* 0x8008EFBC */
    R[2] = R[2] << 16;  /* 0x8008EFC0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008EFC4 */
    R[2] = ((int32_t)R[2] < 4);  /* 0x8008EFC8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[17] << 16; if (_c) { psx_bb(); goto L_8008EFA4; } }  /* 0x8008EFCC */
L_8008EFD4:;
    R[2] = R[17] << 16;  /* 0x8008EFD4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008EFD8 */
    R[3] = lw_(R[4] + 948);  /* 0x8008EFDC */
    R[2] = R[2] + R[5];  /* 0x8008EFE0 */
    sw_(R[2], R[3]);  /* 0x8008EFE4 */
    R[3] = lw_(R[4] + 952);  /* 0x8008EFE8 */
    sw_(R[2] + 4, R[3]);  /* 0x8008EFF0 */
    R[3] = lw_(R[4] + 956);  /* 0x8008EFF4 */
    sw_(R[2] + 8, R[3]);  /* 0x8008EFFC */
    R[3] = lw_(R[4] + 960);  /* 0x8008F000 */
    { sw_(R[2] + 12, R[3]); psx_next = 0x8008F130u; return; }  /* 0x8008F004 j extern */
    R[17] = R[0] + R[0];  /* 0x8008F00C */
    R[2] = 0x800Bu << 16;  /* 0x8008F010 */
    R[6] = R[2] + 30184;  /* 0x8008F014 */
    R[5] = R[0] + 12;  /* 0x8008F018 */
    R[4] = R[0] - 1;  /* 0x8008F01C */
    R[2] = R[17] << 16;  /* 0x8008F020 */
L_8008F024:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008F024 */
    R[3] = R[2] + R[6];  /* 0x8008F028 */
    R[2] = lw_(R[3]);  /* 0x8008F02C */
    { uint32_t _c = (R[2] != R[5]); R[2] = R[17] + 1; if (_c) { goto L_8008F04C; } }  /* 0x8008F034 */
    sw_(R[3], R[4]);  /* 0x8008F03C */
    sw_(R[3] + 4, R[0]);  /* 0x8008F040 */
    sw_(R[3] + 8, R[0]);  /* 0x8008F044 */
    sw_(R[3] + 12, R[0]);  /* 0x8008F048 */
L_8008F04C:;
    R[17] = R[2] + R[0];  /* 0x8008F04C */
    R[2] = R[2] << 16;  /* 0x8008F050 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008F054 */
    R[2] = ((int32_t)R[2] < 4);  /* 0x8008F058 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[17] << 16; if (_c) { psx_bb(); goto L_8008F024; } }  /* 0x8008F05C */
    { psx_next = 0x8008F130u; return; }  /* 0x8008F064 j extern */
    sh_(R[4] + 1240, R[0]);  /* 0x8008F06C */
    R[17] = R[0] + R[0];  /* 0x8008F070 */
    R[2] = 0x800Du << 16;  /* 0x8008F074 */
    R[19] = R[2] + 19496;  /* 0x8008F078 */
    R[2] = 0x800Eu << 16;  /* 0x8008F07C */
    psx_next = 0x8008F080u; return;  /* fallthrough */
}

void ev_8008EF90(void) {
    R[17] = R[0] + R[0];  /* 0x8008EF90 */
    R[2] = 0x800Bu << 16;  /* 0x8008EF94 */
    R[5] = R[2] + 30184;  /* 0x8008EF98 */
    R[3] = R[0] - 1;  /* 0x8008EF9C */
    R[2] = R[17] << 16;  /* 0x8008EFA0 */
L_8008EFA4:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008EFA4 */
    R[2] = R[2] + R[5];  /* 0x8008EFA8 */
    R[2] = lw_(R[2]);  /* 0x8008EFAC */
    { uint32_t _c = (R[2] == R[3]); R[2] = R[17] + 1; if (_c) { goto L_8008EFD4; } }  /* 0x8008EFB4 */
    R[17] = R[2] + R[0];  /* 0x8008EFBC */
    R[2] = R[2] << 16;  /* 0x8008EFC0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008EFC4 */
    R[2] = ((int32_t)R[2] < 4);  /* 0x8008EFC8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[17] << 16; if (_c) { psx_bb(); goto L_8008EFA4; } }  /* 0x8008EFCC */
L_8008EFD4:;
    R[2] = R[17] << 16;  /* 0x8008EFD4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008EFD8 */
    R[3] = lw_(R[4] + 948);  /* 0x8008EFDC */
    R[2] = R[2] + R[5];  /* 0x8008EFE0 */
    sw_(R[2], R[3]);  /* 0x8008EFE4 */
    R[3] = lw_(R[4] + 952);  /* 0x8008EFE8 */
    sw_(R[2] + 4, R[3]);  /* 0x8008EFF0 */
    R[3] = lw_(R[4] + 956);  /* 0x8008EFF4 */
    sw_(R[2] + 8, R[3]);  /* 0x8008EFFC */
    R[3] = lw_(R[4] + 960);  /* 0x8008F000 */
    { sw_(R[2] + 12, R[3]); psx_next = 0x8008F130u; return; }  /* 0x8008F004 j extern */
    R[17] = R[0] + R[0];  /* 0x8008F00C */
    R[2] = 0x800Bu << 16;  /* 0x8008F010 */
    R[6] = R[2] + 30184;  /* 0x8008F014 */
    R[5] = R[0] + 12;  /* 0x8008F018 */
    R[4] = R[0] - 1;  /* 0x8008F01C */
    R[2] = R[17] << 16;  /* 0x8008F020 */
L_8008F024:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008F024 */
    R[3] = R[2] + R[6];  /* 0x8008F028 */
    R[2] = lw_(R[3]);  /* 0x8008F02C */
    { uint32_t _c = (R[2] != R[5]); R[2] = R[17] + 1; if (_c) { goto L_8008F04C; } }  /* 0x8008F034 */
    sw_(R[3], R[4]);  /* 0x8008F03C */
    sw_(R[3] + 4, R[0]);  /* 0x8008F040 */
    sw_(R[3] + 8, R[0]);  /* 0x8008F044 */
    sw_(R[3] + 12, R[0]);  /* 0x8008F048 */
L_8008F04C:;
    R[17] = R[2] + R[0];  /* 0x8008F04C */
    R[2] = R[2] << 16;  /* 0x8008F050 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008F054 */
    R[2] = ((int32_t)R[2] < 4);  /* 0x8008F058 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[17] << 16; if (_c) { psx_bb(); goto L_8008F024; } }  /* 0x8008F05C */
    { psx_next = 0x8008F130u; return; }  /* 0x8008F064 j extern */
    sh_(R[4] + 1240, R[0]);  /* 0x8008F06C */
    R[17] = R[0] + R[0];  /* 0x8008F070 */
    R[2] = 0x800Du << 16;  /* 0x8008F074 */
    R[19] = R[2] + 19496;  /* 0x8008F078 */
    R[2] = 0x800Eu << 16;  /* 0x8008F07C */
    psx_next = 0x8008F080u; return;  /* fallthrough */
}

void ev_8008F00C(void) {
    R[17] = R[0] + R[0];  /* 0x8008F00C */
    R[2] = 0x800Bu << 16;  /* 0x8008F010 */
    R[6] = R[2] + 30184;  /* 0x8008F014 */
    R[5] = R[0] + 12;  /* 0x8008F018 */
    R[4] = R[0] - 1;  /* 0x8008F01C */
    R[2] = R[17] << 16;  /* 0x8008F020 */
L_8008F024:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008F024 */
    R[3] = R[2] + R[6];  /* 0x8008F028 */
    R[2] = lw_(R[3]);  /* 0x8008F02C */
    { uint32_t _c = (R[2] != R[5]); R[2] = R[17] + 1; if (_c) { goto L_8008F04C; } }  /* 0x8008F034 */
    sw_(R[3], R[4]);  /* 0x8008F03C */
    sw_(R[3] + 4, R[0]);  /* 0x8008F040 */
    sw_(R[3] + 8, R[0]);  /* 0x8008F044 */
    sw_(R[3] + 12, R[0]);  /* 0x8008F048 */
L_8008F04C:;
    R[17] = R[2] + R[0];  /* 0x8008F04C */
    R[2] = R[2] << 16;  /* 0x8008F050 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008F054 */
    R[2] = ((int32_t)R[2] < 4);  /* 0x8008F058 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[17] << 16; if (_c) { psx_bb(); goto L_8008F024; } }  /* 0x8008F05C */
    { psx_next = 0x8008F130u; return; }  /* 0x8008F064 j extern */
    sh_(R[4] + 1240, R[0]);  /* 0x8008F06C */
    R[17] = R[0] + R[0];  /* 0x8008F070 */
    R[2] = 0x800Du << 16;  /* 0x8008F074 */
    R[19] = R[2] + 19496;  /* 0x8008F078 */
    R[2] = 0x800Eu << 16;  /* 0x8008F07C */
    psx_next = 0x8008F080u; return;  /* fallthrough */
}

void ev_8008F06C(void) {
    sh_(R[4] + 1240, R[0]);  /* 0x8008F06C */
    R[17] = R[0] + R[0];  /* 0x8008F070 */
    R[2] = 0x800Du << 16;  /* 0x8008F074 */
    R[19] = R[2] + 19496;  /* 0x8008F078 */
    R[2] = 0x800Eu << 16;  /* 0x8008F07C */
    psx_next = 0x8008F080u; return;  /* fallthrough */
}

void ev_8008F080(void) {
    R[18] = R[2] - 27632;  /* 0x8008F080 */
L_8008F084:;
    { R[31] = 0x8008F08Cu; R[16] = R[17] << 16; psx_next = 0x80030E88u; return; }  /* 0x8008F084 jal */
    R[3] = 0x2AAAu << 16;  /* 0x8008F08C */
    R[3] = R[3] | 0xAAAB;  /* 0x8008F090 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F094 */
    R[16] = (uint32_t)((int32_t)R[16] >> 15);  /* 0x8008F098 */
    R[5] = R[16] + R[19];  /* 0x8008F09C */
    R[4] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x8008F0A0 */
    R[9] = HI;  /* 0x8008F0A4 */
    R[4] = R[9] - R[4];  /* 0x8008F0A8 */
    R[3] = R[4] << 1;  /* 0x8008F0AC */
    R[3] = R[3] + R[4];  /* 0x8008F0B0 */
    R[3] = R[3] << 1;  /* 0x8008F0B4 */
    R[2] = R[2] - R[3];  /* 0x8008F0B8 */
    R[2] = R[2] + 6;  /* 0x8008F0BC */
    { R[31] = 0x8008F0C8u; sh_(R[5], R[2]); psx_next = 0x80030E88u; return; }  /* 0x8008F0C0 jal */
    R[3] = 0x6666u << 16;  /* 0x8008F0C8 */
    R[3] = R[3] | 0x6667;  /* 0x8008F0CC */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F0D0 */
    R[5] = R[17] + 1;  /* 0x8008F0D4 */
    R[17] = R[5] + R[0];  /* 0x8008F0D8 */
    R[16] = R[16] + R[18];  /* 0x8008F0DC */
    R[3] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x8008F0E0 */
    R[5] = R[5] << 16;  /* 0x8008F0E4 */
    R[5] = (uint32_t)((int32_t)R[5] >> 16);  /* 0x8008F0E8 */
    R[5] = ((int32_t)R[5] < 10);  /* 0x8008F0EC */
    R[9] = HI;  /* 0x8008F0F0 */
    R[4] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x8008F0F4 */
    R[4] = R[4] - R[3];  /* 0x8008F0F8 */
    R[3] = R[4] << 2;  /* 0x8008F0FC */
    R[3] = R[3] + R[4];  /* 0x8008F100 */
    R[3] = R[3] << 1;  /* 0x8008F104 */
    R[2] = R[2] - R[3];  /* 0x8008F108 */
    R[2] = R[2] - 5;  /* 0x8008F10C */
    R[3] = R[2] << 2;  /* 0x8008F110 */
    R[3] = R[3] + R[2];  /* 0x8008F114 */
    R[3] = R[3] << 1;  /* 0x8008F118 */
    { uint32_t _c = (R[5] != R[0]); sh_(R[16], R[3]); if (_c) { psx_bb(); goto L_8008F084; } }  /* 0x8008F11C */
    { goto L_8008F130; }  /* 0x8008F124 j */
    sh_(R[4] + 1240, R[0]);  /* 0x8008F12C */
L_8008F130:;
    R[31] = lw_(R[29] + 32);  /* 0x8008F130 */
    R[19] = lw_(R[29] + 28);  /* 0x8008F134 */
    R[18] = lw_(R[29] + 24);  /* 0x8008F138 */
    R[17] = lw_(R[29] + 20);  /* 0x8008F13C */
    R[16] = lw_(R[29] + 16);  /* 0x8008F140 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8008F144 jr ra */
}

void ev_8008F084(void) {
L_8008F084:;
    { R[31] = 0x8008F08Cu; R[16] = R[17] << 16; psx_next = 0x80030E88u; return; }  /* 0x8008F084 jal */
    R[3] = 0x2AAAu << 16;  /* 0x8008F08C */
    R[3] = R[3] | 0xAAAB;  /* 0x8008F090 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F094 */
    R[16] = (uint32_t)((int32_t)R[16] >> 15);  /* 0x8008F098 */
    R[5] = R[16] + R[19];  /* 0x8008F09C */
    R[4] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x8008F0A0 */
    R[9] = HI;  /* 0x8008F0A4 */
    R[4] = R[9] - R[4];  /* 0x8008F0A8 */
    R[3] = R[4] << 1;  /* 0x8008F0AC */
    R[3] = R[3] + R[4];  /* 0x8008F0B0 */
    R[3] = R[3] << 1;  /* 0x8008F0B4 */
    R[2] = R[2] - R[3];  /* 0x8008F0B8 */
    R[2] = R[2] + 6;  /* 0x8008F0BC */
    { R[31] = 0x8008F0C8u; sh_(R[5], R[2]); psx_next = 0x80030E88u; return; }  /* 0x8008F0C0 jal */
    R[3] = 0x6666u << 16;  /* 0x8008F0C8 */
    R[3] = R[3] | 0x6667;  /* 0x8008F0CC */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F0D0 */
    R[5] = R[17] + 1;  /* 0x8008F0D4 */
    R[17] = R[5] + R[0];  /* 0x8008F0D8 */
    R[16] = R[16] + R[18];  /* 0x8008F0DC */
    R[3] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x8008F0E0 */
    R[5] = R[5] << 16;  /* 0x8008F0E4 */
    R[5] = (uint32_t)((int32_t)R[5] >> 16);  /* 0x8008F0E8 */
    R[5] = ((int32_t)R[5] < 10);  /* 0x8008F0EC */
    R[9] = HI;  /* 0x8008F0F0 */
    R[4] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x8008F0F4 */
    R[4] = R[4] - R[3];  /* 0x8008F0F8 */
    R[3] = R[4] << 2;  /* 0x8008F0FC */
    R[3] = R[3] + R[4];  /* 0x8008F100 */
    R[3] = R[3] << 1;  /* 0x8008F104 */
    R[2] = R[2] - R[3];  /* 0x8008F108 */
    R[2] = R[2] - 5;  /* 0x8008F10C */
    R[3] = R[2] << 2;  /* 0x8008F110 */
    R[3] = R[3] + R[2];  /* 0x8008F114 */
    R[3] = R[3] << 1;  /* 0x8008F118 */
    { uint32_t _c = (R[5] != R[0]); sh_(R[16], R[3]); if (_c) { psx_bb(); goto L_8008F084; } }  /* 0x8008F11C */
    { goto L_8008F130; }  /* 0x8008F124 j */
    sh_(R[4] + 1240, R[0]);  /* 0x8008F12C */
L_8008F130:;
    R[31] = lw_(R[29] + 32);  /* 0x8008F130 */
    R[19] = lw_(R[29] + 28);  /* 0x8008F134 */
    R[18] = lw_(R[29] + 24);  /* 0x8008F138 */
    R[17] = lw_(R[29] + 20);  /* 0x8008F13C */
    R[16] = lw_(R[29] + 16);  /* 0x8008F140 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8008F144 jr ra */
}

void ev_8008F08C(void) {
    R[3] = 0x2AAAu << 16;  /* 0x8008F08C */
    R[3] = R[3] | 0xAAAB;  /* 0x8008F090 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F094 */
    R[16] = (uint32_t)((int32_t)R[16] >> 15);  /* 0x8008F098 */
    R[5] = R[16] + R[19];  /* 0x8008F09C */
    R[4] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x8008F0A0 */
    R[9] = HI;  /* 0x8008F0A4 */
    R[4] = R[9] - R[4];  /* 0x8008F0A8 */
    R[3] = R[4] << 1;  /* 0x8008F0AC */
    R[3] = R[3] + R[4];  /* 0x8008F0B0 */
    R[3] = R[3] << 1;  /* 0x8008F0B4 */
    R[2] = R[2] - R[3];  /* 0x8008F0B8 */
    R[2] = R[2] + 6;  /* 0x8008F0BC */
    { R[31] = 0x8008F0C8u; sh_(R[5], R[2]); psx_next = 0x80030E88u; return; }  /* 0x8008F0C0 jal */
    R[3] = 0x6666u << 16;  /* 0x8008F0C8 */
    R[3] = R[3] | 0x6667;  /* 0x8008F0CC */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F0D0 */
    R[5] = R[17] + 1;  /* 0x8008F0D4 */
    R[17] = R[5] + R[0];  /* 0x8008F0D8 */
    R[16] = R[16] + R[18];  /* 0x8008F0DC */
    R[3] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x8008F0E0 */
    R[5] = R[5] << 16;  /* 0x8008F0E4 */
    R[5] = (uint32_t)((int32_t)R[5] >> 16);  /* 0x8008F0E8 */
    R[5] = ((int32_t)R[5] < 10);  /* 0x8008F0EC */
    R[9] = HI;  /* 0x8008F0F0 */
    R[4] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x8008F0F4 */
    R[4] = R[4] - R[3];  /* 0x8008F0F8 */
    R[3] = R[4] << 2;  /* 0x8008F0FC */
    R[3] = R[3] + R[4];  /* 0x8008F100 */
    R[3] = R[3] << 1;  /* 0x8008F104 */
    R[2] = R[2] - R[3];  /* 0x8008F108 */
    R[2] = R[2] - 5;  /* 0x8008F10C */
    R[3] = R[2] << 2;  /* 0x8008F110 */
    R[3] = R[3] + R[2];  /* 0x8008F114 */
    R[3] = R[3] << 1;  /* 0x8008F118 */
    { uint32_t _c = (R[5] != R[0]); sh_(R[16], R[3]); if (_c) { psx_next = 0x8008F084u; return; } }  /* 0x8008F11C b extern */
    { goto L_8008F130; }  /* 0x8008F124 j */
    sh_(R[4] + 1240, R[0]);  /* 0x8008F12C */
L_8008F130:;
    R[31] = lw_(R[29] + 32);  /* 0x8008F130 */
    R[19] = lw_(R[29] + 28);  /* 0x8008F134 */
    R[18] = lw_(R[29] + 24);  /* 0x8008F138 */
    R[17] = lw_(R[29] + 20);  /* 0x8008F13C */
    R[16] = lw_(R[29] + 16);  /* 0x8008F140 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8008F144 jr ra */
}

void ev_8008F0C8(void) {
    R[3] = 0x6666u << 16;  /* 0x8008F0C8 */
    R[3] = R[3] | 0x6667;  /* 0x8008F0CC */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F0D0 */
    R[5] = R[17] + 1;  /* 0x8008F0D4 */
    R[17] = R[5] + R[0];  /* 0x8008F0D8 */
    R[16] = R[16] + R[18];  /* 0x8008F0DC */
    R[3] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x8008F0E0 */
    R[5] = R[5] << 16;  /* 0x8008F0E4 */
    R[5] = (uint32_t)((int32_t)R[5] >> 16);  /* 0x8008F0E8 */
    R[5] = ((int32_t)R[5] < 10);  /* 0x8008F0EC */
    R[9] = HI;  /* 0x8008F0F0 */
    R[4] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x8008F0F4 */
    R[4] = R[4] - R[3];  /* 0x8008F0F8 */
    R[3] = R[4] << 2;  /* 0x8008F0FC */
    R[3] = R[3] + R[4];  /* 0x8008F100 */
    R[3] = R[3] << 1;  /* 0x8008F104 */
    R[2] = R[2] - R[3];  /* 0x8008F108 */
    R[2] = R[2] - 5;  /* 0x8008F10C */
    R[3] = R[2] << 2;  /* 0x8008F110 */
    R[3] = R[3] + R[2];  /* 0x8008F114 */
    R[3] = R[3] << 1;  /* 0x8008F118 */
    { uint32_t _c = (R[5] != R[0]); sh_(R[16], R[3]); if (_c) { psx_next = 0x8008F084u; return; } }  /* 0x8008F11C b extern */
    { goto L_8008F130; }  /* 0x8008F124 j */
    sh_(R[4] + 1240, R[0]);  /* 0x8008F12C */
L_8008F130:;
    R[31] = lw_(R[29] + 32);  /* 0x8008F130 */
    R[19] = lw_(R[29] + 28);  /* 0x8008F134 */
    R[18] = lw_(R[29] + 24);  /* 0x8008F138 */
    R[17] = lw_(R[29] + 20);  /* 0x8008F13C */
    R[16] = lw_(R[29] + 16);  /* 0x8008F140 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8008F144 jr ra */
}

void ev_8008F12C(void) {
    sh_(R[4] + 1240, R[0]);  /* 0x8008F12C */
    R[31] = lw_(R[29] + 32);  /* 0x8008F130 */
    R[19] = lw_(R[29] + 28);  /* 0x8008F134 */
    R[18] = lw_(R[29] + 24);  /* 0x8008F138 */
    R[17] = lw_(R[29] + 20);  /* 0x8008F13C */
    R[16] = lw_(R[29] + 16);  /* 0x8008F140 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8008F144 jr ra */
}

void ev_8008F130(void) {
    R[31] = lw_(R[29] + 32);  /* 0x8008F130 */
    R[19] = lw_(R[29] + 28);  /* 0x8008F134 */
    R[18] = lw_(R[29] + 24);  /* 0x8008F138 */
    R[17] = lw_(R[29] + 20);  /* 0x8008F13C */
    R[16] = lw_(R[29] + 16);  /* 0x8008F140 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8008F144 jr ra */
}

void ev_8008F14C(void) {
    R[2] = R[0] + 18;  /* 0x8008F14C */
    sw_(R[4] + 948, R[2]);  /* 0x8008F150 */
    sh_(R[4] + 1240, R[0]);  /* 0x8008F154 */
    R[3] = lw_(R[29] + 16);  /* 0x8008F158 */
    R[4] = lw_(R[29] + 20);  /* 0x8008F15C */
    R[8] = lw_(R[29] + 24);  /* 0x8008F160 */
    R[9] = lw_(R[29] + 28);  /* 0x8008F164 */
    R[10] = lw_(R[29] + 32);  /* 0x8008F168 */
    R[2] = 0x800Fu << 16;  /* 0x8008F16C */
    sw_(R[2] + -16552, R[5]);  /* 0x8008F170 */
    R[2] = R[2] - 16552;  /* 0x8008F174 */
    sw_(R[2] + 4, R[6]);  /* 0x8008F178 */
    sw_(R[2] + 8, R[7]);  /* 0x8008F17C */
    sw_(R[2] + 12, R[3]);  /* 0x8008F180 */
    sw_(R[2] + 16, R[4]);  /* 0x8008F184 */
    sw_(R[2] + 20, R[8]);  /* 0x8008F188 */
    sw_(R[2] + 24, R[9]);  /* 0x8008F18C */
    { sw_(R[2] + 28, R[10]); psx_next = R[31]; return; }  /* 0x8008F190 jr ra */
}

void ev_8008F198(void) {
    R[29] = R[29] - 288;  /* 0x8008F198 */
    sw_(R[29] + 272, R[16]);  /* 0x8008F19C */
    R[16] = R[4] + R[0];  /* 0x8008F1A0 */
    R[5] = 0x800Bu << 16;  /* 0x8008F1A4 */
    R[4] = lw_(R[5] + 19288);  /* 0x8008F1A8 */
    R[3] = R[16] & 0x3;  /* 0x8008F1AC */
    sw_(R[29] + 280, R[31]);  /* 0x8008F1B0 */
    { uint32_t _c = (R[3] == R[0]); sw_(R[29] + 276, R[17]); if (_c) { psx_next = 0x8008F1C4u; return; } }  /* 0x8008F1B4 b extern */
    R[2] = R[16] + 4;  /* 0x8008F1BC */
    R[16] = R[2] - R[3];  /* 0x8008F1C0 */
    psx_next = 0x8008F1C4u; return;  /* fallthrough */
}

void ev_8008F1C4(void) {
    R[3] = R[4] + R[16];  /* 0x8008F1C4 */
    R[2] = 0x801Fu << 16;  /* 0x8008F1C8 */
    R[2] = R[2] | 0x8000;  /* 0x8008F1CC */
    R[2] = (R[2] < R[3]);  /* 0x8008F1D0 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[5] + 19288, R[3]); if (_c) { goto L_8008F240; } }  /* 0x8008F1D4 */
    R[17] = 0x8008u << 16;  /* 0x8008F1DC */
    R[4] = R[29] + 16;  /* 0x8008F1E0 */
L_8008F1E4:;
    R[5] = R[17] + 5860;  /* 0x8008F1E4 */
    { R[31] = 0x8008F1F0u; R[6] = R[16] + R[0]; psx_next = 0x80031BF8u; return; }  /* 0x8008F1E8 jal */
    R[4] = R[0] + 6;  /* 0x8008F1F0 */
    R[5] = R[0] + 12;  /* 0x8008F1F4 */
    { R[31] = 0x8008F200u; R[6] = R[29] + 16; psx_next = 0x8008BA94u; return; }  /* 0x8008F1F8 jal */
    { R[31] = 0x8008F208u; psx_next = 0x80084F20u; return; }  /* 0x8008F200 jal */
    { R[31] = 0x8008F210u; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x8008F208 jal */
    { R[31] = 0x8008F218u; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8008F210 jal */
    { R[31] = 0x8008F220u; psx_next = 0x8001BB80u; return; }  /* 0x8008F218 jal */
    { R[31] = 0x8008F228u; psx_next = 0x800935C8u; return; }  /* 0x8008F220 jal */
    { R[31] = 0x8008F230u; psx_next = 0x8001BFC8u; return; }  /* 0x8008F228 jal */
    { R[31] = 0x8008F238u; R[4] = R[0] + 1; psx_next = 0x8003285Cu; return; }  /* 0x8008F230 jal */
    { R[4] = R[29] + 16; psx_bb(); goto L_8008F1E4; }  /* 0x8008F238 j */
L_8008F240:;
    R[31] = lw_(R[29] + 280);  /* 0x8008F240 */
    R[17] = lw_(R[29] + 276);  /* 0x8008F244 */
    R[16] = lw_(R[29] + 272);  /* 0x8008F248 */
    R[2] = R[4] + R[0];  /* 0x8008F24C */
    { R[29] = R[29] + 288; psx_next = R[31]; return; }  /* 0x8008F250 jr ra */
}

void ev_8008F1E4(void) {
L_8008F1E4:;
    R[5] = R[17] + 5860;  /* 0x8008F1E4 */
    { R[31] = 0x8008F1F0u; R[6] = R[16] + R[0]; psx_next = 0x80031BF8u; return; }  /* 0x8008F1E8 jal */
    R[4] = R[0] + 6;  /* 0x8008F1F0 */
    R[5] = R[0] + 12;  /* 0x8008F1F4 */
    { R[31] = 0x8008F200u; R[6] = R[29] + 16; psx_next = 0x8008BA94u; return; }  /* 0x8008F1F8 jal */
    { R[31] = 0x8008F208u; psx_next = 0x80084F20u; return; }  /* 0x8008F200 jal */
    { R[31] = 0x8008F210u; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x8008F208 jal */
    { R[31] = 0x8008F218u; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8008F210 jal */
    { R[31] = 0x8008F220u; psx_next = 0x8001BB80u; return; }  /* 0x8008F218 jal */
    { R[31] = 0x8008F228u; psx_next = 0x800935C8u; return; }  /* 0x8008F220 jal */
    { R[31] = 0x8008F230u; psx_next = 0x8001BFC8u; return; }  /* 0x8008F228 jal */
    { R[31] = 0x8008F238u; R[4] = R[0] + 1; psx_next = 0x8003285Cu; return; }  /* 0x8008F230 jal */
    { R[4] = R[29] + 16; psx_bb(); goto L_8008F1E4; }  /* 0x8008F238 j */
    R[31] = lw_(R[29] + 280);  /* 0x8008F240 */
    R[17] = lw_(R[29] + 276);  /* 0x8008F244 */
    R[16] = lw_(R[29] + 272);  /* 0x8008F248 */
    R[2] = R[4] + R[0];  /* 0x8008F24C */
    { R[29] = R[29] + 288; psx_next = R[31]; return; }  /* 0x8008F250 jr ra */
}

void ev_8008F1F0(void) {
    R[4] = R[0] + 6;  /* 0x8008F1F0 */
    R[5] = R[0] + 12;  /* 0x8008F1F4 */
    { R[31] = 0x8008F200u; R[6] = R[29] + 16; psx_next = 0x8008BA94u; return; }  /* 0x8008F1F8 jal */
    { R[31] = 0x8008F208u; psx_next = 0x80084F20u; return; }  /* 0x8008F200 jal */
    { R[31] = 0x8008F210u; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x8008F208 jal */
    { R[31] = 0x8008F218u; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8008F210 jal */
    { R[31] = 0x8008F220u; psx_next = 0x8001BB80u; return; }  /* 0x8008F218 jal */
    { R[31] = 0x8008F228u; psx_next = 0x800935C8u; return; }  /* 0x8008F220 jal */
    { R[31] = 0x8008F230u; psx_next = 0x8001BFC8u; return; }  /* 0x8008F228 jal */
    { R[31] = 0x8008F238u; R[4] = R[0] + 1; psx_next = 0x8003285Cu; return; }  /* 0x8008F230 jal */
    { R[4] = R[29] + 16; psx_next = 0x8008F1E4u; return; }  /* 0x8008F238 j extern */
    R[31] = lw_(R[29] + 280);  /* 0x8008F240 */
    R[17] = lw_(R[29] + 276);  /* 0x8008F244 */
    R[16] = lw_(R[29] + 272);  /* 0x8008F248 */
    R[2] = R[4] + R[0];  /* 0x8008F24C */
    { R[29] = R[29] + 288; psx_next = R[31]; return; }  /* 0x8008F250 jr ra */
}

void ev_8008F200(void) {
    { R[31] = 0x8008F208u; psx_next = 0x80084F20u; return; }  /* 0x8008F200 jal */
    { R[31] = 0x8008F210u; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x8008F208 jal */
    { R[31] = 0x8008F218u; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8008F210 jal */
    { R[31] = 0x8008F220u; psx_next = 0x8001BB80u; return; }  /* 0x8008F218 jal */
    { R[31] = 0x8008F228u; psx_next = 0x800935C8u; return; }  /* 0x8008F220 jal */
    { R[31] = 0x8008F230u; psx_next = 0x8001BFC8u; return; }  /* 0x8008F228 jal */
    { R[31] = 0x8008F238u; R[4] = R[0] + 1; psx_next = 0x8003285Cu; return; }  /* 0x8008F230 jal */
    { R[4] = R[29] + 16; psx_next = 0x8008F1E4u; return; }  /* 0x8008F238 j extern */
    R[31] = lw_(R[29] + 280);  /* 0x8008F240 */
    R[17] = lw_(R[29] + 276);  /* 0x8008F244 */
    R[16] = lw_(R[29] + 272);  /* 0x8008F248 */
    R[2] = R[4] + R[0];  /* 0x8008F24C */
    { R[29] = R[29] + 288; psx_next = R[31]; return; }  /* 0x8008F250 jr ra */
}

void ev_8008F208(void) {
    { R[31] = 0x8008F210u; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x8008F208 jal */
    { R[31] = 0x8008F218u; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8008F210 jal */
    { R[31] = 0x8008F220u; psx_next = 0x8001BB80u; return; }  /* 0x8008F218 jal */
    { R[31] = 0x8008F228u; psx_next = 0x800935C8u; return; }  /* 0x8008F220 jal */
    { R[31] = 0x8008F230u; psx_next = 0x8001BFC8u; return; }  /* 0x8008F228 jal */
    { R[31] = 0x8008F238u; R[4] = R[0] + 1; psx_next = 0x8003285Cu; return; }  /* 0x8008F230 jal */
    { R[4] = R[29] + 16; psx_next = 0x8008F1E4u; return; }  /* 0x8008F238 j extern */
    R[31] = lw_(R[29] + 280);  /* 0x8008F240 */
    R[17] = lw_(R[29] + 276);  /* 0x8008F244 */
    R[16] = lw_(R[29] + 272);  /* 0x8008F248 */
    R[2] = R[4] + R[0];  /* 0x8008F24C */
    { R[29] = R[29] + 288; psx_next = R[31]; return; }  /* 0x8008F250 jr ra */
}

void ev_8008F210(void) {
    { R[31] = 0x8008F218u; R[4] = R[0] + R[0]; psx_next = 0x80037D98u; return; }  /* 0x8008F210 jal */
    { R[31] = 0x8008F220u; psx_next = 0x8001BB80u; return; }  /* 0x8008F218 jal */
    { R[31] = 0x8008F228u; psx_next = 0x800935C8u; return; }  /* 0x8008F220 jal */
    { R[31] = 0x8008F230u; psx_next = 0x8001BFC8u; return; }  /* 0x8008F228 jal */
    { R[31] = 0x8008F238u; R[4] = R[0] + 1; psx_next = 0x8003285Cu; return; }  /* 0x8008F230 jal */
    { R[4] = R[29] + 16; psx_next = 0x8008F1E4u; return; }  /* 0x8008F238 j extern */
    R[31] = lw_(R[29] + 280);  /* 0x8008F240 */
    R[17] = lw_(R[29] + 276);  /* 0x8008F244 */
    R[16] = lw_(R[29] + 272);  /* 0x8008F248 */
    R[2] = R[4] + R[0];  /* 0x8008F24C */
    { R[29] = R[29] + 288; psx_next = R[31]; return; }  /* 0x8008F250 jr ra */
}

void ev_8008F218(void) {
    { R[31] = 0x8008F220u; psx_next = 0x8001BB80u; return; }  /* 0x8008F218 jal */
    { R[31] = 0x8008F228u; psx_next = 0x800935C8u; return; }  /* 0x8008F220 jal */
    { R[31] = 0x8008F230u; psx_next = 0x8001BFC8u; return; }  /* 0x8008F228 jal */
    { R[31] = 0x8008F238u; R[4] = R[0] + 1; psx_next = 0x8003285Cu; return; }  /* 0x8008F230 jal */
    { R[4] = R[29] + 16; psx_next = 0x8008F1E4u; return; }  /* 0x8008F238 j extern */
    R[31] = lw_(R[29] + 280);  /* 0x8008F240 */
    R[17] = lw_(R[29] + 276);  /* 0x8008F244 */
    R[16] = lw_(R[29] + 272);  /* 0x8008F248 */
    R[2] = R[4] + R[0];  /* 0x8008F24C */
    { R[29] = R[29] + 288; psx_next = R[31]; return; }  /* 0x8008F250 jr ra */
}

void ev_8008F220(void) {
    { R[31] = 0x8008F228u; psx_next = 0x800935C8u; return; }  /* 0x8008F220 jal */
    { R[31] = 0x8008F230u; psx_next = 0x8001BFC8u; return; }  /* 0x8008F228 jal */
    { R[31] = 0x8008F238u; R[4] = R[0] + 1; psx_next = 0x8003285Cu; return; }  /* 0x8008F230 jal */
    { R[4] = R[29] + 16; psx_next = 0x8008F1E4u; return; }  /* 0x8008F238 j extern */
    R[31] = lw_(R[29] + 280);  /* 0x8008F240 */
    R[17] = lw_(R[29] + 276);  /* 0x8008F244 */
    R[16] = lw_(R[29] + 272);  /* 0x8008F248 */
    R[2] = R[4] + R[0];  /* 0x8008F24C */
    { R[29] = R[29] + 288; psx_next = R[31]; return; }  /* 0x8008F250 jr ra */
}

void ev_8008F228(void) {
    { R[31] = 0x8008F230u; psx_next = 0x8001BFC8u; return; }  /* 0x8008F228 jal */
    { R[31] = 0x8008F238u; R[4] = R[0] + 1; psx_next = 0x8003285Cu; return; }  /* 0x8008F230 jal */
    { R[4] = R[29] + 16; psx_next = 0x8008F1E4u; return; }  /* 0x8008F238 j extern */
    R[31] = lw_(R[29] + 280);  /* 0x8008F240 */
    R[17] = lw_(R[29] + 276);  /* 0x8008F244 */
    R[16] = lw_(R[29] + 272);  /* 0x8008F248 */
    R[2] = R[4] + R[0];  /* 0x8008F24C */
    { R[29] = R[29] + 288; psx_next = R[31]; return; }  /* 0x8008F250 jr ra */
}

void ev_8008F230(void) {
    { R[31] = 0x8008F238u; R[4] = R[0] + 1; psx_next = 0x8003285Cu; return; }  /* 0x8008F230 jal */
    { R[4] = R[29] + 16; psx_next = 0x8008F1E4u; return; }  /* 0x8008F238 j extern */
    R[31] = lw_(R[29] + 280);  /* 0x8008F240 */
    R[17] = lw_(R[29] + 276);  /* 0x8008F244 */
    R[16] = lw_(R[29] + 272);  /* 0x8008F248 */
    R[2] = R[4] + R[0];  /* 0x8008F24C */
    { R[29] = R[29] + 288; psx_next = R[31]; return; }  /* 0x8008F250 jr ra */
}

void ev_8008F238(void) {
    { R[4] = R[29] + 16; psx_next = 0x8008F1E4u; return; }  /* 0x8008F238 j extern */
    R[31] = lw_(R[29] + 280);  /* 0x8008F240 */
    R[17] = lw_(R[29] + 276);  /* 0x8008F244 */
    R[16] = lw_(R[29] + 272);  /* 0x8008F248 */
    R[2] = R[4] + R[0];  /* 0x8008F24C */
    { R[29] = R[29] + 288; psx_next = R[31]; return; }  /* 0x8008F250 jr ra */
}

void ev_8008F258(void) {
L_8008F258:;
    R[4] = lw_(R[4]);  /* 0x8008F258 */
    { uint32_t _c = (R[4] == R[0]); if (_c) { goto L_8008F278; } }  /* 0x8008F260 */
    R[2] = lw_(R[4] + 4);  /* 0x8008F268 */
    { uint32_t _c = (R[2] != R[5]); if (_c) { psx_bb(); goto L_8008F258; } }  /* 0x8008F270 */
L_8008F278:;
    { R[2] = R[4] + R[0]; psx_next = R[31]; return; }  /* 0x8008F278 jr ra */
}

void ev_8008F280(void) {
    R[2] = R[4] + R[0];  /* 0x8008F280 */
L_8008F284:;
    R[3] = lw_(R[2]);  /* 0x8008F284 */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_8008F29C; } }  /* 0x8008F28C */
    { R[2] = R[3] + R[0]; psx_bb(); goto L_8008F284; }  /* 0x8008F294 j */
L_8008F29C:;
    { psx_next = R[31]; return; }  /* 0x8008F29C jr ra */
}

void ev_8008F2A4(void) {
    R[29] = R[29] - 64;  /* 0x8008F2A4 */
    sw_(R[29] + 60, R[31]);  /* 0x8008F2A8 */
    sw_(R[29] + 56, R[30]);  /* 0x8008F2AC */
    sw_(R[29] + 52, R[23]);  /* 0x8008F2B0 */
    sw_(R[29] + 48, R[22]);  /* 0x8008F2B4 */
    sw_(R[29] + 44, R[21]);  /* 0x8008F2B8 */
    sw_(R[29] + 40, R[20]);  /* 0x8008F2BC */
    sw_(R[29] + 36, R[19]);  /* 0x8008F2C0 */
    sw_(R[29] + 32, R[18]);  /* 0x8008F2C4 */
    sw_(R[29] + 28, R[17]);  /* 0x8008F2C8 */
    { R[31] = 0x8008F2D4u; sw_(R[29] + 24, R[16]); psx_next = 0x80030E88u; return; }  /* 0x8008F2CC jal */
    { R[31] = 0x8008F2DCu; R[16] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2D4 jal */
    { R[31] = 0x8008F2E4u; sw_(R[29] + 16, R[2]); psx_next = 0x80030E88u; return; }  /* 0x8008F2DC jal */
    { R[31] = 0x8008F2ECu; sw_(R[29] + 20, R[2]); psx_next = 0x80030E88u; return; }  /* 0x8008F2E4 jal */
    { R[31] = 0x8008F2F4u; R[30] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2EC jal */
    { R[31] = 0x8008F2FCu; R[23] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2F4 jal */
    { R[31] = 0x8008F304u; R[22] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2FC jal */
    { R[31] = 0x8008F30Cu; R[21] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F304 jal */
    { R[31] = 0x8008F314u; R[20] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F30C jal */
    { R[31] = 0x8008F31Cu; R[19] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F314 jal */
    { R[31] = 0x8008F324u; R[18] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F31C jal */
    { R[31] = 0x8008F32Cu; R[17] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F324 jal */
    R[3] = lw_(R[29] + 16);  /* 0x8008F32C */
    R[16] = R[16] + R[3];  /* 0x8008F334 */
    R[3] = lw_(R[29] + 20);  /* 0x8008F338 */
    R[31] = lw_(R[29] + 60);  /* 0x8008F33C */
    R[16] = R[16] + R[3];  /* 0x8008F340 */
    R[16] = R[16] + R[30];  /* 0x8008F344 */
    R[16] = R[16] + R[23];  /* 0x8008F348 */
    R[16] = R[16] + R[22];  /* 0x8008F34C */
    R[16] = R[16] + R[21];  /* 0x8008F350 */
    R[16] = R[16] + R[20];  /* 0x8008F354 */
    R[16] = R[16] + R[19];  /* 0x8008F358 */
    R[16] = R[16] + R[18];  /* 0x8008F35C */
    R[16] = R[16] + R[17];  /* 0x8008F360 */
    R[16] = R[16] + R[2];  /* 0x8008F364 */
    R[2] = 0xFFFDu << 16;  /* 0x8008F368 */
    R[2] = R[16] + R[2];  /* 0x8008F36C */
    R[30] = lw_(R[29] + 56);  /* 0x8008F370 */
    R[23] = lw_(R[29] + 52);  /* 0x8008F374 */
    R[22] = lw_(R[29] + 48);  /* 0x8008F378 */
    R[21] = lw_(R[29] + 44);  /* 0x8008F37C */
    R[20] = lw_(R[29] + 40);  /* 0x8008F380 */
    R[19] = lw_(R[29] + 36);  /* 0x8008F384 */
    R[18] = lw_(R[29] + 32);  /* 0x8008F388 */
    R[17] = lw_(R[29] + 28);  /* 0x8008F38C */
    R[16] = lw_(R[29] + 24);  /* 0x8008F390 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008F394 jr ra */
}

void ev_8008F2D4(void) {
    { R[31] = 0x8008F2DCu; R[16] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2D4 jal */
    { R[31] = 0x8008F2E4u; sw_(R[29] + 16, R[2]); psx_next = 0x80030E88u; return; }  /* 0x8008F2DC jal */
    { R[31] = 0x8008F2ECu; sw_(R[29] + 20, R[2]); psx_next = 0x80030E88u; return; }  /* 0x8008F2E4 jal */
    { R[31] = 0x8008F2F4u; R[30] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2EC jal */
    { R[31] = 0x8008F2FCu; R[23] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2F4 jal */
    { R[31] = 0x8008F304u; R[22] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2FC jal */
    { R[31] = 0x8008F30Cu; R[21] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F304 jal */
    { R[31] = 0x8008F314u; R[20] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F30C jal */
    { R[31] = 0x8008F31Cu; R[19] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F314 jal */
    { R[31] = 0x8008F324u; R[18] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F31C jal */
    { R[31] = 0x8008F32Cu; R[17] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F324 jal */
    R[3] = lw_(R[29] + 16);  /* 0x8008F32C */
    R[16] = R[16] + R[3];  /* 0x8008F334 */
    R[3] = lw_(R[29] + 20);  /* 0x8008F338 */
    R[31] = lw_(R[29] + 60);  /* 0x8008F33C */
    R[16] = R[16] + R[3];  /* 0x8008F340 */
    R[16] = R[16] + R[30];  /* 0x8008F344 */
    R[16] = R[16] + R[23];  /* 0x8008F348 */
    R[16] = R[16] + R[22];  /* 0x8008F34C */
    R[16] = R[16] + R[21];  /* 0x8008F350 */
    R[16] = R[16] + R[20];  /* 0x8008F354 */
    R[16] = R[16] + R[19];  /* 0x8008F358 */
    R[16] = R[16] + R[18];  /* 0x8008F35C */
    R[16] = R[16] + R[17];  /* 0x8008F360 */
    R[16] = R[16] + R[2];  /* 0x8008F364 */
    R[2] = 0xFFFDu << 16;  /* 0x8008F368 */
    R[2] = R[16] + R[2];  /* 0x8008F36C */
    R[30] = lw_(R[29] + 56);  /* 0x8008F370 */
    R[23] = lw_(R[29] + 52);  /* 0x8008F374 */
    R[22] = lw_(R[29] + 48);  /* 0x8008F378 */
    R[21] = lw_(R[29] + 44);  /* 0x8008F37C */
    R[20] = lw_(R[29] + 40);  /* 0x8008F380 */
    R[19] = lw_(R[29] + 36);  /* 0x8008F384 */
    R[18] = lw_(R[29] + 32);  /* 0x8008F388 */
    R[17] = lw_(R[29] + 28);  /* 0x8008F38C */
    R[16] = lw_(R[29] + 24);  /* 0x8008F390 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008F394 jr ra */
}

void ev_8008F2DC(void) {
    { R[31] = 0x8008F2E4u; sw_(R[29] + 16, R[2]); psx_next = 0x80030E88u; return; }  /* 0x8008F2DC jal */
    { R[31] = 0x8008F2ECu; sw_(R[29] + 20, R[2]); psx_next = 0x80030E88u; return; }  /* 0x8008F2E4 jal */
    { R[31] = 0x8008F2F4u; R[30] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2EC jal */
    { R[31] = 0x8008F2FCu; R[23] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2F4 jal */
    { R[31] = 0x8008F304u; R[22] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2FC jal */
    { R[31] = 0x8008F30Cu; R[21] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F304 jal */
    { R[31] = 0x8008F314u; R[20] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F30C jal */
    { R[31] = 0x8008F31Cu; R[19] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F314 jal */
    { R[31] = 0x8008F324u; R[18] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F31C jal */
    { R[31] = 0x8008F32Cu; R[17] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F324 jal */
    R[3] = lw_(R[29] + 16);  /* 0x8008F32C */
    R[16] = R[16] + R[3];  /* 0x8008F334 */
    R[3] = lw_(R[29] + 20);  /* 0x8008F338 */
    R[31] = lw_(R[29] + 60);  /* 0x8008F33C */
    R[16] = R[16] + R[3];  /* 0x8008F340 */
    R[16] = R[16] + R[30];  /* 0x8008F344 */
    R[16] = R[16] + R[23];  /* 0x8008F348 */
    R[16] = R[16] + R[22];  /* 0x8008F34C */
    R[16] = R[16] + R[21];  /* 0x8008F350 */
    R[16] = R[16] + R[20];  /* 0x8008F354 */
    R[16] = R[16] + R[19];  /* 0x8008F358 */
    R[16] = R[16] + R[18];  /* 0x8008F35C */
    R[16] = R[16] + R[17];  /* 0x8008F360 */
    R[16] = R[16] + R[2];  /* 0x8008F364 */
    R[2] = 0xFFFDu << 16;  /* 0x8008F368 */
    R[2] = R[16] + R[2];  /* 0x8008F36C */
    R[30] = lw_(R[29] + 56);  /* 0x8008F370 */
    R[23] = lw_(R[29] + 52);  /* 0x8008F374 */
    R[22] = lw_(R[29] + 48);  /* 0x8008F378 */
    R[21] = lw_(R[29] + 44);  /* 0x8008F37C */
    R[20] = lw_(R[29] + 40);  /* 0x8008F380 */
    R[19] = lw_(R[29] + 36);  /* 0x8008F384 */
    R[18] = lw_(R[29] + 32);  /* 0x8008F388 */
    R[17] = lw_(R[29] + 28);  /* 0x8008F38C */
    R[16] = lw_(R[29] + 24);  /* 0x8008F390 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008F394 jr ra */
}

void ev_8008F2E4(void) {
    { R[31] = 0x8008F2ECu; sw_(R[29] + 20, R[2]); psx_next = 0x80030E88u; return; }  /* 0x8008F2E4 jal */
    { R[31] = 0x8008F2F4u; R[30] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2EC jal */
    { R[31] = 0x8008F2FCu; R[23] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2F4 jal */
    { R[31] = 0x8008F304u; R[22] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2FC jal */
    { R[31] = 0x8008F30Cu; R[21] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F304 jal */
    { R[31] = 0x8008F314u; R[20] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F30C jal */
    { R[31] = 0x8008F31Cu; R[19] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F314 jal */
    { R[31] = 0x8008F324u; R[18] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F31C jal */
    { R[31] = 0x8008F32Cu; R[17] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F324 jal */
    R[3] = lw_(R[29] + 16);  /* 0x8008F32C */
    R[16] = R[16] + R[3];  /* 0x8008F334 */
    R[3] = lw_(R[29] + 20);  /* 0x8008F338 */
    R[31] = lw_(R[29] + 60);  /* 0x8008F33C */
    R[16] = R[16] + R[3];  /* 0x8008F340 */
    R[16] = R[16] + R[30];  /* 0x8008F344 */
    R[16] = R[16] + R[23];  /* 0x8008F348 */
    R[16] = R[16] + R[22];  /* 0x8008F34C */
    R[16] = R[16] + R[21];  /* 0x8008F350 */
    R[16] = R[16] + R[20];  /* 0x8008F354 */
    R[16] = R[16] + R[19];  /* 0x8008F358 */
    R[16] = R[16] + R[18];  /* 0x8008F35C */
    R[16] = R[16] + R[17];  /* 0x8008F360 */
    R[16] = R[16] + R[2];  /* 0x8008F364 */
    R[2] = 0xFFFDu << 16;  /* 0x8008F368 */
    R[2] = R[16] + R[2];  /* 0x8008F36C */
    R[30] = lw_(R[29] + 56);  /* 0x8008F370 */
    R[23] = lw_(R[29] + 52);  /* 0x8008F374 */
    R[22] = lw_(R[29] + 48);  /* 0x8008F378 */
    R[21] = lw_(R[29] + 44);  /* 0x8008F37C */
    R[20] = lw_(R[29] + 40);  /* 0x8008F380 */
    R[19] = lw_(R[29] + 36);  /* 0x8008F384 */
    R[18] = lw_(R[29] + 32);  /* 0x8008F388 */
    R[17] = lw_(R[29] + 28);  /* 0x8008F38C */
    R[16] = lw_(R[29] + 24);  /* 0x8008F390 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008F394 jr ra */
}

void ev_8008F2EC(void) {
    { R[31] = 0x8008F2F4u; R[30] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2EC jal */
    { R[31] = 0x8008F2FCu; R[23] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2F4 jal */
    { R[31] = 0x8008F304u; R[22] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2FC jal */
    { R[31] = 0x8008F30Cu; R[21] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F304 jal */
    { R[31] = 0x8008F314u; R[20] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F30C jal */
    { R[31] = 0x8008F31Cu; R[19] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F314 jal */
    { R[31] = 0x8008F324u; R[18] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F31C jal */
    { R[31] = 0x8008F32Cu; R[17] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F324 jal */
    R[3] = lw_(R[29] + 16);  /* 0x8008F32C */
    R[16] = R[16] + R[3];  /* 0x8008F334 */
    R[3] = lw_(R[29] + 20);  /* 0x8008F338 */
    R[31] = lw_(R[29] + 60);  /* 0x8008F33C */
    R[16] = R[16] + R[3];  /* 0x8008F340 */
    R[16] = R[16] + R[30];  /* 0x8008F344 */
    R[16] = R[16] + R[23];  /* 0x8008F348 */
    R[16] = R[16] + R[22];  /* 0x8008F34C */
    R[16] = R[16] + R[21];  /* 0x8008F350 */
    R[16] = R[16] + R[20];  /* 0x8008F354 */
    R[16] = R[16] + R[19];  /* 0x8008F358 */
    R[16] = R[16] + R[18];  /* 0x8008F35C */
    R[16] = R[16] + R[17];  /* 0x8008F360 */
    R[16] = R[16] + R[2];  /* 0x8008F364 */
    R[2] = 0xFFFDu << 16;  /* 0x8008F368 */
    R[2] = R[16] + R[2];  /* 0x8008F36C */
    R[30] = lw_(R[29] + 56);  /* 0x8008F370 */
    R[23] = lw_(R[29] + 52);  /* 0x8008F374 */
    R[22] = lw_(R[29] + 48);  /* 0x8008F378 */
    R[21] = lw_(R[29] + 44);  /* 0x8008F37C */
    R[20] = lw_(R[29] + 40);  /* 0x8008F380 */
    R[19] = lw_(R[29] + 36);  /* 0x8008F384 */
    R[18] = lw_(R[29] + 32);  /* 0x8008F388 */
    R[17] = lw_(R[29] + 28);  /* 0x8008F38C */
    R[16] = lw_(R[29] + 24);  /* 0x8008F390 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008F394 jr ra */
}

void ev_8008F2F4(void) {
    { R[31] = 0x8008F2FCu; R[23] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2F4 jal */
    { R[31] = 0x8008F304u; R[22] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2FC jal */
    { R[31] = 0x8008F30Cu; R[21] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F304 jal */
    { R[31] = 0x8008F314u; R[20] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F30C jal */
    { R[31] = 0x8008F31Cu; R[19] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F314 jal */
    { R[31] = 0x8008F324u; R[18] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F31C jal */
    { R[31] = 0x8008F32Cu; R[17] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F324 jal */
    R[3] = lw_(R[29] + 16);  /* 0x8008F32C */
    R[16] = R[16] + R[3];  /* 0x8008F334 */
    R[3] = lw_(R[29] + 20);  /* 0x8008F338 */
    R[31] = lw_(R[29] + 60);  /* 0x8008F33C */
    R[16] = R[16] + R[3];  /* 0x8008F340 */
    R[16] = R[16] + R[30];  /* 0x8008F344 */
    R[16] = R[16] + R[23];  /* 0x8008F348 */
    R[16] = R[16] + R[22];  /* 0x8008F34C */
    R[16] = R[16] + R[21];  /* 0x8008F350 */
    R[16] = R[16] + R[20];  /* 0x8008F354 */
    R[16] = R[16] + R[19];  /* 0x8008F358 */
    R[16] = R[16] + R[18];  /* 0x8008F35C */
    R[16] = R[16] + R[17];  /* 0x8008F360 */
    R[16] = R[16] + R[2];  /* 0x8008F364 */
    R[2] = 0xFFFDu << 16;  /* 0x8008F368 */
    R[2] = R[16] + R[2];  /* 0x8008F36C */
    R[30] = lw_(R[29] + 56);  /* 0x8008F370 */
    R[23] = lw_(R[29] + 52);  /* 0x8008F374 */
    R[22] = lw_(R[29] + 48);  /* 0x8008F378 */
    R[21] = lw_(R[29] + 44);  /* 0x8008F37C */
    R[20] = lw_(R[29] + 40);  /* 0x8008F380 */
    R[19] = lw_(R[29] + 36);  /* 0x8008F384 */
    R[18] = lw_(R[29] + 32);  /* 0x8008F388 */
    R[17] = lw_(R[29] + 28);  /* 0x8008F38C */
    R[16] = lw_(R[29] + 24);  /* 0x8008F390 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008F394 jr ra */
}

void ev_8008F2FC(void) {
    { R[31] = 0x8008F304u; R[22] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F2FC jal */
    { R[31] = 0x8008F30Cu; R[21] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F304 jal */
    { R[31] = 0x8008F314u; R[20] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F30C jal */
    { R[31] = 0x8008F31Cu; R[19] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F314 jal */
    { R[31] = 0x8008F324u; R[18] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F31C jal */
    { R[31] = 0x8008F32Cu; R[17] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F324 jal */
    R[3] = lw_(R[29] + 16);  /* 0x8008F32C */
    R[16] = R[16] + R[3];  /* 0x8008F334 */
    R[3] = lw_(R[29] + 20);  /* 0x8008F338 */
    R[31] = lw_(R[29] + 60);  /* 0x8008F33C */
    R[16] = R[16] + R[3];  /* 0x8008F340 */
    R[16] = R[16] + R[30];  /* 0x8008F344 */
    R[16] = R[16] + R[23];  /* 0x8008F348 */
    R[16] = R[16] + R[22];  /* 0x8008F34C */
    R[16] = R[16] + R[21];  /* 0x8008F350 */
    R[16] = R[16] + R[20];  /* 0x8008F354 */
    R[16] = R[16] + R[19];  /* 0x8008F358 */
    R[16] = R[16] + R[18];  /* 0x8008F35C */
    R[16] = R[16] + R[17];  /* 0x8008F360 */
    R[16] = R[16] + R[2];  /* 0x8008F364 */
    R[2] = 0xFFFDu << 16;  /* 0x8008F368 */
    R[2] = R[16] + R[2];  /* 0x8008F36C */
    R[30] = lw_(R[29] + 56);  /* 0x8008F370 */
    R[23] = lw_(R[29] + 52);  /* 0x8008F374 */
    R[22] = lw_(R[29] + 48);  /* 0x8008F378 */
    R[21] = lw_(R[29] + 44);  /* 0x8008F37C */
    R[20] = lw_(R[29] + 40);  /* 0x8008F380 */
    R[19] = lw_(R[29] + 36);  /* 0x8008F384 */
    R[18] = lw_(R[29] + 32);  /* 0x8008F388 */
    R[17] = lw_(R[29] + 28);  /* 0x8008F38C */
    R[16] = lw_(R[29] + 24);  /* 0x8008F390 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008F394 jr ra */
}

void ev_8008F304(void) {
    { R[31] = 0x8008F30Cu; R[21] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F304 jal */
    { R[31] = 0x8008F314u; R[20] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F30C jal */
    { R[31] = 0x8008F31Cu; R[19] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F314 jal */
    { R[31] = 0x8008F324u; R[18] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F31C jal */
    { R[31] = 0x8008F32Cu; R[17] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F324 jal */
    R[3] = lw_(R[29] + 16);  /* 0x8008F32C */
    R[16] = R[16] + R[3];  /* 0x8008F334 */
    R[3] = lw_(R[29] + 20);  /* 0x8008F338 */
    R[31] = lw_(R[29] + 60);  /* 0x8008F33C */
    R[16] = R[16] + R[3];  /* 0x8008F340 */
    R[16] = R[16] + R[30];  /* 0x8008F344 */
    R[16] = R[16] + R[23];  /* 0x8008F348 */
    R[16] = R[16] + R[22];  /* 0x8008F34C */
    R[16] = R[16] + R[21];  /* 0x8008F350 */
    R[16] = R[16] + R[20];  /* 0x8008F354 */
    R[16] = R[16] + R[19];  /* 0x8008F358 */
    R[16] = R[16] + R[18];  /* 0x8008F35C */
    R[16] = R[16] + R[17];  /* 0x8008F360 */
    R[16] = R[16] + R[2];  /* 0x8008F364 */
    R[2] = 0xFFFDu << 16;  /* 0x8008F368 */
    R[2] = R[16] + R[2];  /* 0x8008F36C */
    R[30] = lw_(R[29] + 56);  /* 0x8008F370 */
    R[23] = lw_(R[29] + 52);  /* 0x8008F374 */
    R[22] = lw_(R[29] + 48);  /* 0x8008F378 */
    R[21] = lw_(R[29] + 44);  /* 0x8008F37C */
    R[20] = lw_(R[29] + 40);  /* 0x8008F380 */
    R[19] = lw_(R[29] + 36);  /* 0x8008F384 */
    R[18] = lw_(R[29] + 32);  /* 0x8008F388 */
    R[17] = lw_(R[29] + 28);  /* 0x8008F38C */
    R[16] = lw_(R[29] + 24);  /* 0x8008F390 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008F394 jr ra */
}

void ev_8008F30C(void) {
    { R[31] = 0x8008F314u; R[20] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F30C jal */
    { R[31] = 0x8008F31Cu; R[19] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F314 jal */
    { R[31] = 0x8008F324u; R[18] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F31C jal */
    { R[31] = 0x8008F32Cu; R[17] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F324 jal */
    R[3] = lw_(R[29] + 16);  /* 0x8008F32C */
    R[16] = R[16] + R[3];  /* 0x8008F334 */
    R[3] = lw_(R[29] + 20);  /* 0x8008F338 */
    R[31] = lw_(R[29] + 60);  /* 0x8008F33C */
    R[16] = R[16] + R[3];  /* 0x8008F340 */
    R[16] = R[16] + R[30];  /* 0x8008F344 */
    R[16] = R[16] + R[23];  /* 0x8008F348 */
    R[16] = R[16] + R[22];  /* 0x8008F34C */
    R[16] = R[16] + R[21];  /* 0x8008F350 */
    R[16] = R[16] + R[20];  /* 0x8008F354 */
    R[16] = R[16] + R[19];  /* 0x8008F358 */
    R[16] = R[16] + R[18];  /* 0x8008F35C */
    R[16] = R[16] + R[17];  /* 0x8008F360 */
    R[16] = R[16] + R[2];  /* 0x8008F364 */
    R[2] = 0xFFFDu << 16;  /* 0x8008F368 */
    R[2] = R[16] + R[2];  /* 0x8008F36C */
    R[30] = lw_(R[29] + 56);  /* 0x8008F370 */
    R[23] = lw_(R[29] + 52);  /* 0x8008F374 */
    R[22] = lw_(R[29] + 48);  /* 0x8008F378 */
    R[21] = lw_(R[29] + 44);  /* 0x8008F37C */
    R[20] = lw_(R[29] + 40);  /* 0x8008F380 */
    R[19] = lw_(R[29] + 36);  /* 0x8008F384 */
    R[18] = lw_(R[29] + 32);  /* 0x8008F388 */
    R[17] = lw_(R[29] + 28);  /* 0x8008F38C */
    R[16] = lw_(R[29] + 24);  /* 0x8008F390 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008F394 jr ra */
}

void ev_8008F314(void) {
    { R[31] = 0x8008F31Cu; R[19] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F314 jal */
    { R[31] = 0x8008F324u; R[18] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F31C jal */
    { R[31] = 0x8008F32Cu; R[17] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F324 jal */
    R[3] = lw_(R[29] + 16);  /* 0x8008F32C */
    R[16] = R[16] + R[3];  /* 0x8008F334 */
    R[3] = lw_(R[29] + 20);  /* 0x8008F338 */
    R[31] = lw_(R[29] + 60);  /* 0x8008F33C */
    R[16] = R[16] + R[3];  /* 0x8008F340 */
    R[16] = R[16] + R[30];  /* 0x8008F344 */
    R[16] = R[16] + R[23];  /* 0x8008F348 */
    R[16] = R[16] + R[22];  /* 0x8008F34C */
    R[16] = R[16] + R[21];  /* 0x8008F350 */
    R[16] = R[16] + R[20];  /* 0x8008F354 */
    R[16] = R[16] + R[19];  /* 0x8008F358 */
    R[16] = R[16] + R[18];  /* 0x8008F35C */
    R[16] = R[16] + R[17];  /* 0x8008F360 */
    R[16] = R[16] + R[2];  /* 0x8008F364 */
    R[2] = 0xFFFDu << 16;  /* 0x8008F368 */
    R[2] = R[16] + R[2];  /* 0x8008F36C */
    R[30] = lw_(R[29] + 56);  /* 0x8008F370 */
    R[23] = lw_(R[29] + 52);  /* 0x8008F374 */
    R[22] = lw_(R[29] + 48);  /* 0x8008F378 */
    R[21] = lw_(R[29] + 44);  /* 0x8008F37C */
    R[20] = lw_(R[29] + 40);  /* 0x8008F380 */
    R[19] = lw_(R[29] + 36);  /* 0x8008F384 */
    R[18] = lw_(R[29] + 32);  /* 0x8008F388 */
    R[17] = lw_(R[29] + 28);  /* 0x8008F38C */
    R[16] = lw_(R[29] + 24);  /* 0x8008F390 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008F394 jr ra */
}

void ev_8008F31C(void) {
    { R[31] = 0x8008F324u; R[18] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F31C jal */
    { R[31] = 0x8008F32Cu; R[17] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F324 jal */
    R[3] = lw_(R[29] + 16);  /* 0x8008F32C */
    R[16] = R[16] + R[3];  /* 0x8008F334 */
    R[3] = lw_(R[29] + 20);  /* 0x8008F338 */
    R[31] = lw_(R[29] + 60);  /* 0x8008F33C */
    R[16] = R[16] + R[3];  /* 0x8008F340 */
    R[16] = R[16] + R[30];  /* 0x8008F344 */
    R[16] = R[16] + R[23];  /* 0x8008F348 */
    R[16] = R[16] + R[22];  /* 0x8008F34C */
    R[16] = R[16] + R[21];  /* 0x8008F350 */
    R[16] = R[16] + R[20];  /* 0x8008F354 */
    R[16] = R[16] + R[19];  /* 0x8008F358 */
    R[16] = R[16] + R[18];  /* 0x8008F35C */
    R[16] = R[16] + R[17];  /* 0x8008F360 */
    R[16] = R[16] + R[2];  /* 0x8008F364 */
    R[2] = 0xFFFDu << 16;  /* 0x8008F368 */
    R[2] = R[16] + R[2];  /* 0x8008F36C */
    R[30] = lw_(R[29] + 56);  /* 0x8008F370 */
    R[23] = lw_(R[29] + 52);  /* 0x8008F374 */
    R[22] = lw_(R[29] + 48);  /* 0x8008F378 */
    R[21] = lw_(R[29] + 44);  /* 0x8008F37C */
    R[20] = lw_(R[29] + 40);  /* 0x8008F380 */
    R[19] = lw_(R[29] + 36);  /* 0x8008F384 */
    R[18] = lw_(R[29] + 32);  /* 0x8008F388 */
    R[17] = lw_(R[29] + 28);  /* 0x8008F38C */
    R[16] = lw_(R[29] + 24);  /* 0x8008F390 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008F394 jr ra */
}

void ev_8008F324(void) {
    { R[31] = 0x8008F32Cu; R[17] = R[2] + R[0]; psx_next = 0x80030E88u; return; }  /* 0x8008F324 jal */
    R[3] = lw_(R[29] + 16);  /* 0x8008F32C */
    R[16] = R[16] + R[3];  /* 0x8008F334 */
    R[3] = lw_(R[29] + 20);  /* 0x8008F338 */
    R[31] = lw_(R[29] + 60);  /* 0x8008F33C */
    R[16] = R[16] + R[3];  /* 0x8008F340 */
    R[16] = R[16] + R[30];  /* 0x8008F344 */
    R[16] = R[16] + R[23];  /* 0x8008F348 */
    R[16] = R[16] + R[22];  /* 0x8008F34C */
    R[16] = R[16] + R[21];  /* 0x8008F350 */
    R[16] = R[16] + R[20];  /* 0x8008F354 */
    R[16] = R[16] + R[19];  /* 0x8008F358 */
    R[16] = R[16] + R[18];  /* 0x8008F35C */
    R[16] = R[16] + R[17];  /* 0x8008F360 */
    R[16] = R[16] + R[2];  /* 0x8008F364 */
    R[2] = 0xFFFDu << 16;  /* 0x8008F368 */
    R[2] = R[16] + R[2];  /* 0x8008F36C */
    R[30] = lw_(R[29] + 56);  /* 0x8008F370 */
    R[23] = lw_(R[29] + 52);  /* 0x8008F374 */
    R[22] = lw_(R[29] + 48);  /* 0x8008F378 */
    R[21] = lw_(R[29] + 44);  /* 0x8008F37C */
    R[20] = lw_(R[29] + 40);  /* 0x8008F380 */
    R[19] = lw_(R[29] + 36);  /* 0x8008F384 */
    R[18] = lw_(R[29] + 32);  /* 0x8008F388 */
    R[17] = lw_(R[29] + 28);  /* 0x8008F38C */
    R[16] = lw_(R[29] + 24);  /* 0x8008F390 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008F394 jr ra */
}

void ev_8008F32C(void) {
    R[3] = lw_(R[29] + 16);  /* 0x8008F32C */
    R[16] = R[16] + R[3];  /* 0x8008F334 */
    R[3] = lw_(R[29] + 20);  /* 0x8008F338 */
    R[31] = lw_(R[29] + 60);  /* 0x8008F33C */
    R[16] = R[16] + R[3];  /* 0x8008F340 */
    R[16] = R[16] + R[30];  /* 0x8008F344 */
    R[16] = R[16] + R[23];  /* 0x8008F348 */
    R[16] = R[16] + R[22];  /* 0x8008F34C */
    R[16] = R[16] + R[21];  /* 0x8008F350 */
    R[16] = R[16] + R[20];  /* 0x8008F354 */
    R[16] = R[16] + R[19];  /* 0x8008F358 */
    R[16] = R[16] + R[18];  /* 0x8008F35C */
    R[16] = R[16] + R[17];  /* 0x8008F360 */
    R[16] = R[16] + R[2];  /* 0x8008F364 */
    R[2] = 0xFFFDu << 16;  /* 0x8008F368 */
    R[2] = R[16] + R[2];  /* 0x8008F36C */
    R[30] = lw_(R[29] + 56);  /* 0x8008F370 */
    R[23] = lw_(R[29] + 52);  /* 0x8008F374 */
    R[22] = lw_(R[29] + 48);  /* 0x8008F378 */
    R[21] = lw_(R[29] + 44);  /* 0x8008F37C */
    R[20] = lw_(R[29] + 40);  /* 0x8008F380 */
    R[19] = lw_(R[29] + 36);  /* 0x8008F384 */
    R[18] = lw_(R[29] + 32);  /* 0x8008F388 */
    R[17] = lw_(R[29] + 28);  /* 0x8008F38C */
    R[16] = lw_(R[29] + 24);  /* 0x8008F390 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008F394 jr ra */
}

void ev_8008F39C(void) {
    R[9] = 0x800Cu << 16;  /* 0x8008F39C */
    R[2] = 0x800Bu << 16;  /* 0x8008F3A0 */
    R[8] = lw_(R[9] + -24632);  /* 0x8008F3A4 */
    R[2] = lw_(R[2] + 30896);  /* 0x8008F3A8 */
    R[2] = (R[8] < R[2]);  /* 0x8008F3B0 */
    { uint32_t _c = (R[2] == R[0]); R[7] = R[6] + R[0]; if (_c) { goto L_8008F440; } }  /* 0x8008F3B4 */
    R[6] = 0xFFu << 16;  /* 0x8008F3BC */
    R[6] = R[6] | 0xFFFF;  /* 0x8008F3C0 */
    R[2] = R[0] + 1;  /* 0x8008F3C4 */
    R[3] = R[0] + 3;  /* 0x8008F3C8 */
    sb_(R[8] + 3, R[3]);  /* 0x8008F3CC */
    R[3] = R[0] + 98;  /* 0x8008F3D0 */
    sb_(R[8] + 7, R[3]);  /* 0x8008F3D4 */
    R[3] = R[0] + 320;  /* 0x8008F3D8 */
    sh_(R[8] + 12, R[3]);  /* 0x8008F3DC */
    R[3] = R[0] + 172;  /* 0x8008F3E0 */
    sh_(R[8] + 14, R[3]);  /* 0x8008F3E4 */
    R[3] = 0x800Bu << 16;  /* 0x8008F3E8 */
    sb_(R[8] + 4, R[4]);  /* 0x8008F3EC */
    sb_(R[8] + 5, R[5]);  /* 0x8008F3F0 */
    sb_(R[8] + 6, R[7]);  /* 0x8008F3F4 */
    R[5] = lw_(R[3] + 30552);  /* 0x8008F3F8 */
    R[4] = lw_(R[8]);  /* 0x8008F3FC */
    R[7] = 0xFF00u << 16;  /* 0x8008F400 */
    sh_(R[8] + 8, R[0]);  /* 0x8008F404 */
    sh_(R[8] + 10, R[0]);  /* 0x8008F408 */
    R[3] = lw_(R[5] + 36);  /* 0x8008F40C */
    R[4] = R[4] & R[7];  /* 0x8008F410 */
    R[3] = R[3] & R[6];  /* 0x8008F414 */
    R[4] = R[4] | R[3];  /* 0x8008F418 */
    R[6] = R[8] & R[6];  /* 0x8008F41C */
    sw_(R[8], R[4]);  /* 0x8008F420 */
    R[3] = lw_(R[5] + 36);  /* 0x8008F424 */
    R[8] = R[8] + 16;  /* 0x8008F428 */
    sw_(R[9] + -24632, R[8]);  /* 0x8008F42C */
    R[3] = R[3] & R[7];  /* 0x8008F430 */
    R[3] = R[3] | R[6];  /* 0x8008F434 */
    { sw_(R[5] + 36, R[3]); psx_next = R[31]; return; }  /* 0x8008F438 jr ra */
L_8008F440:;
    { R[2] = R[0] + R[0]; psx_next = R[31]; return; }  /* 0x8008F440 jr ra */
}

void ev_8008F448(void) {
    R[29] = R[29] - 32;  /* 0x8008F448 */
    sw_(R[29] + 24, R[18]);  /* 0x8008F44C */
    R[18] = 0x800Cu << 16;  /* 0x8008F450 */
    R[2] = 0x800Bu << 16;  /* 0x8008F454 */
    sw_(R[29] + 16, R[16]);  /* 0x8008F458 */
    R[16] = lw_(R[18] + -24632);  /* 0x8008F45C */
    R[2] = lw_(R[2] + 30896);  /* 0x8008F460 */
    sw_(R[29] + 20, R[17]);  /* 0x8008F464 */
    R[17] = R[5] + R[0];  /* 0x8008F468 */
    R[2] = (R[16] < R[2]);  /* 0x8008F46C */
    { uint32_t _c = (R[2] == R[0]); sw_(R[29] + 28, R[31]); if (_c) { goto L_8008F4E8; } }  /* 0x8008F470 */
    R[7] = R[4] & 0x3;  /* 0x8008F478 */
    R[4] = R[16] + R[0];  /* 0x8008F47C */
    R[5] = R[0] + 1;  /* 0x8008F480 */
    R[6] = R[5] + R[0];  /* 0x8008F484 */
    { R[31] = 0x8008F490u; R[7] = R[7] << 5; psx_next = 0x80035878u; return; }  /* 0x8008F488 jal */
    R[6] = 0xFFu << 16;  /* 0x8008F490 */
    R[6] = R[6] | 0xFFFF;  /* 0x8008F494 */
    R[2] = R[0] + 1;  /* 0x8008F498 */
    R[3] = 0x800Bu << 16;  /* 0x8008F49C */
    R[5] = R[17] << 2;  /* 0x8008F4A0 */
    R[7] = 0xFF00u << 16;  /* 0x8008F4A4 */
    R[3] = lw_(R[3] + 30552);  /* 0x8008F4A8 */
    R[4] = lw_(R[16]);  /* 0x8008F4AC */
    R[5] = R[5] + R[3];  /* 0x8008F4B0 */
    R[3] = lw_(R[5]);  /* 0x8008F4B4 */
    R[4] = R[4] & R[7];  /* 0x8008F4B8 */
    R[3] = R[3] & R[6];  /* 0x8008F4BC */
    R[4] = R[4] | R[3];  /* 0x8008F4C0 */
    R[6] = R[16] & R[6];  /* 0x8008F4C4 */
    sw_(R[16], R[4]);  /* 0x8008F4C8 */
    R[3] = lw_(R[5]);  /* 0x8008F4CC */
    R[16] = R[16] + 8;  /* 0x8008F4D0 */
    sw_(R[18] + -24632, R[16]);  /* 0x8008F4D4 */
    R[3] = R[3] & R[7];  /* 0x8008F4D8 */
    R[3] = R[3] | R[6];  /* 0x8008F4DC */
    { sw_(R[5], R[3]); goto L_8008F4EC; }  /* 0x8008F4E0 j */
L_8008F4E8:;
    R[2] = R[0] + R[0];  /* 0x8008F4E8 */
L_8008F4EC:;
    R[31] = lw_(R[29] + 28);  /* 0x8008F4EC */
    R[18] = lw_(R[29] + 24);  /* 0x8008F4F0 */
    R[17] = lw_(R[29] + 20);  /* 0x8008F4F4 */
    R[16] = lw_(R[29] + 16);  /* 0x8008F4F8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008F4FC jr ra */
}

void ev_8008F490(void) {
    R[6] = 0xFFu << 16;  /* 0x8008F490 */
    R[6] = R[6] | 0xFFFF;  /* 0x8008F494 */
    R[2] = R[0] + 1;  /* 0x8008F498 */
    R[3] = 0x800Bu << 16;  /* 0x8008F49C */
    R[5] = R[17] << 2;  /* 0x8008F4A0 */
    R[7] = 0xFF00u << 16;  /* 0x8008F4A4 */
    R[3] = lw_(R[3] + 30552);  /* 0x8008F4A8 */
    R[4] = lw_(R[16]);  /* 0x8008F4AC */
    R[5] = R[5] + R[3];  /* 0x8008F4B0 */
    R[3] = lw_(R[5]);  /* 0x8008F4B4 */
    R[4] = R[4] & R[7];  /* 0x8008F4B8 */
    R[3] = R[3] & R[6];  /* 0x8008F4BC */
    R[4] = R[4] | R[3];  /* 0x8008F4C0 */
    R[6] = R[16] & R[6];  /* 0x8008F4C4 */
    sw_(R[16], R[4]);  /* 0x8008F4C8 */
    R[3] = lw_(R[5]);  /* 0x8008F4CC */
    R[16] = R[16] + 8;  /* 0x8008F4D0 */
    sw_(R[18] + -24632, R[16]);  /* 0x8008F4D4 */
    R[3] = R[3] & R[7];  /* 0x8008F4D8 */
    R[3] = R[3] | R[6];  /* 0x8008F4DC */
    { sw_(R[5], R[3]); goto L_8008F4EC; }  /* 0x8008F4E0 j */
    R[2] = R[0] + R[0];  /* 0x8008F4E8 */
L_8008F4EC:;
    R[31] = lw_(R[29] + 28);  /* 0x8008F4EC */
    R[18] = lw_(R[29] + 24);  /* 0x8008F4F0 */
    R[17] = lw_(R[29] + 20);  /* 0x8008F4F4 */
    R[16] = lw_(R[29] + 16);  /* 0x8008F4F8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008F4FC jr ra */
}

void ev_8008F504(void) {
    R[29] = R[29] - 32;  /* 0x8008F504 */
    sw_(R[29] + 24, R[18]);  /* 0x8008F508 */
    R[18] = 0x800Cu << 16;  /* 0x8008F50C */
    R[2] = 0x800Bu << 16;  /* 0x8008F510 */
    sw_(R[29] + 16, R[16]);  /* 0x8008F514 */
    R[16] = lw_(R[18] + -24632);  /* 0x8008F518 */
    R[2] = lw_(R[2] + 30896);  /* 0x8008F51C */
    sw_(R[29] + 20, R[17]);  /* 0x8008F520 */
    R[17] = R[5] + R[0];  /* 0x8008F524 */
    R[2] = (R[16] < R[2]);  /* 0x8008F528 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[29] + 28, R[31]); if (_c) { goto L_8008F5B4; } }  /* 0x8008F52C */
    R[7] = R[4] & 0x3;  /* 0x8008F534 */
    R[4] = R[16] + R[0];  /* 0x8008F538 */
    R[5] = R[0] + 1;  /* 0x8008F53C */
    R[6] = R[5] + R[0];  /* 0x8008F540 */
    { R[31] = 0x8008F54Cu; R[7] = R[7] << 5; psx_next = 0x80035878u; return; }  /* 0x8008F544 jal */
    R[6] = 0xFFu << 16;  /* 0x8008F54C */
    R[6] = R[6] | 0xFFFF;  /* 0x8008F550 */
    R[2] = R[0] + 1;  /* 0x8008F554 */
    R[3] = 0x800Bu << 16;  /* 0x8008F558 */
    R[4] = 0x800Cu << 16;  /* 0x8008F55C */
    R[4] = R[4] - 24624;  /* 0x8008F560 */
    R[5] = lw_(R[3] + 30548);  /* 0x8008F564 */
    R[3] = R[17] << 2;  /* 0x8008F568 */
    R[7] = 0xFF00u << 16;  /* 0x8008F56C */
    R[5] = R[5] << 13;  /* 0x8008F570 */
    R[5] = R[5] + R[3];  /* 0x8008F574 */
    R[5] = R[5] + R[4];  /* 0x8008F578 */
    R[4] = lw_(R[16]);  /* 0x8008F57C */
    R[3] = lw_(R[5]);  /* 0x8008F580 */
    R[4] = R[4] & R[7];  /* 0x8008F584 */
    R[3] = R[3] & R[6];  /* 0x8008F588 */
    R[4] = R[4] | R[3];  /* 0x8008F58C */
    R[6] = R[16] & R[6];  /* 0x8008F590 */
    sw_(R[16], R[4]);  /* 0x8008F594 */
    R[3] = lw_(R[5]);  /* 0x8008F598 */
    R[16] = R[16] + 8;  /* 0x8008F59C */
    sw_(R[18] + -24632, R[16]);  /* 0x8008F5A0 */
    R[3] = R[3] & R[7];  /* 0x8008F5A4 */
    R[3] = R[3] | R[6];  /* 0x8008F5A8 */
    { sw_(R[5], R[3]); goto L_8008F5B8; }  /* 0x8008F5AC j */
L_8008F5B4:;
    R[2] = R[0] + R[0];  /* 0x8008F5B4 */
L_8008F5B8:;
    R[31] = lw_(R[29] + 28);  /* 0x8008F5B8 */
    R[18] = lw_(R[29] + 24);  /* 0x8008F5BC */
    R[17] = lw_(R[29] + 20);  /* 0x8008F5C0 */
    R[16] = lw_(R[29] + 16);  /* 0x8008F5C4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008F5C8 jr ra */
}

void ev_8008F54C(void) {
    R[6] = 0xFFu << 16;  /* 0x8008F54C */
    R[6] = R[6] | 0xFFFF;  /* 0x8008F550 */
    R[2] = R[0] + 1;  /* 0x8008F554 */
    R[3] = 0x800Bu << 16;  /* 0x8008F558 */
    R[4] = 0x800Cu << 16;  /* 0x8008F55C */
    R[4] = R[4] - 24624;  /* 0x8008F560 */
    R[5] = lw_(R[3] + 30548);  /* 0x8008F564 */
    R[3] = R[17] << 2;  /* 0x8008F568 */
    R[7] = 0xFF00u << 16;  /* 0x8008F56C */
    R[5] = R[5] << 13;  /* 0x8008F570 */
    R[5] = R[5] + R[3];  /* 0x8008F574 */
    R[5] = R[5] + R[4];  /* 0x8008F578 */
    R[4] = lw_(R[16]);  /* 0x8008F57C */
    R[3] = lw_(R[5]);  /* 0x8008F580 */
    R[4] = R[4] & R[7];  /* 0x8008F584 */
    R[3] = R[3] & R[6];  /* 0x8008F588 */
    R[4] = R[4] | R[3];  /* 0x8008F58C */
    R[6] = R[16] & R[6];  /* 0x8008F590 */
    sw_(R[16], R[4]);  /* 0x8008F594 */
    R[3] = lw_(R[5]);  /* 0x8008F598 */
    R[16] = R[16] + 8;  /* 0x8008F59C */
    sw_(R[18] + -24632, R[16]);  /* 0x8008F5A0 */
    R[3] = R[3] & R[7];  /* 0x8008F5A4 */
    R[3] = R[3] | R[6];  /* 0x8008F5A8 */
    { sw_(R[5], R[3]); goto L_8008F5B8; }  /* 0x8008F5AC j */
    R[2] = R[0] + R[0];  /* 0x8008F5B4 */
L_8008F5B8:;
    R[31] = lw_(R[29] + 28);  /* 0x8008F5B8 */
    R[18] = lw_(R[29] + 24);  /* 0x8008F5BC */
    R[17] = lw_(R[29] + 20);  /* 0x8008F5C0 */
    R[16] = lw_(R[29] + 16);  /* 0x8008F5C4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008F5C8 jr ra */
}

void ev_8008F5D0(void) {
    R[4] = R[0] + R[0];  /* 0x8008F5D0 */
    R[5] = R[0] + 150;  /* 0x8008F5D4 */
    R[2] = 0x800Bu << 16;  /* 0x8008F5D8 */
    R[3] = R[2] + 19304;  /* 0x8008F5DC */
L_8008F5E0:;
    { uint32_t _c = (R[4] == R[5]); R[2] = R[0] - 1; if (_c) { goto L_8008F608; } }  /* 0x8008F5E0 */
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x8008F5E8 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[3] + 136; if (_c) { goto L_8008F600; } }  /* 0x8008F5F0 */
    { R[4] = R[4] + 2; psx_bb(); goto L_8008F5E0; }  /* 0x8008F5F8 j */
L_8008F600:;
    { R[2] = R[4] + R[0]; psx_next = R[31]; return; }  /* 0x8008F600 jr ra */
L_8008F608:;
    { psx_next = R[31]; return; }  /* 0x8008F608 jr ra */
}

void ev_8008F610(void) {
    R[29] = R[29] - 104;  /* 0x8008F610 */
    R[3] = R[4] + R[0];  /* 0x8008F614 */
    sw_(R[29] + 80, R[16]);  /* 0x8008F618 */
    R[16] = R[5] + R[0];  /* 0x8008F61C */
    sw_(R[29] + 84, R[17]);  /* 0x8008F620 */
    R[17] = R[29] + 64;  /* 0x8008F624 */
    sw_(R[29] + 96, R[31]);  /* 0x8008F628 */
    sw_(R[29] + 92, R[19]);  /* 0x8008F62C */
    sw_(R[29] + 88, R[18]);  /* 0x8008F630 */
    R[2] = lw_(R[3]);  /* 0x8008F634 */
    R[4] = R[17] + R[0];  /* 0x8008F638 */
    sw_(R[29] + 64, R[2]);  /* 0x8008F63C */
    R[2] = lw_(R[3] + 4);  /* 0x8008F640 */
    R[18] = R[29] + 32;  /* 0x8008F644 */
    sw_(R[29] + 68, R[2]);  /* 0x8008F648 */
    R[2] = lw_(R[3] + 8);  /* 0x8008F64C */
    R[5] = R[18] + R[0];  /* 0x8008F650 */
    { R[31] = 0x8008F65Cu; sw_(R[29] + 72, R[2]); psx_next = 0x800270ACu; return; }  /* 0x8008F654 jal */
    R[4] = R[18] + R[0];  /* 0x8008F65C */
    R[19] = R[29] + 48;  /* 0x8008F660 */
    R[5] = R[19] + R[0];  /* 0x8008F664 */
    R[6] = R[17] + R[0];  /* 0x8008F668 */
    R[2] = R[0] + 4096;  /* 0x8008F66C */
    sw_(R[29] + 48, R[0]);  /* 0x8008F670 */
    sw_(R[29] + 52, R[0]);  /* 0x8008F674 */
    { R[31] = 0x8008F680u; sw_(R[29] + 56, R[2]); psx_next = 0x80036DACu; return; }  /* 0x8008F678 jal */
    R[4] = R[17] + R[0];  /* 0x8008F680 */
    { R[31] = 0x8008F68Cu; R[5] = R[29] + 16; psx_next = 0x800270ACu; return; }  /* 0x8008F684 jal */
    R[4] = R[29] + 16;  /* 0x8008F68C */
    R[5] = R[18] + R[0];  /* 0x8008F690 */
    { R[31] = 0x8008F69Cu; R[6] = R[17] + R[0]; psx_next = 0x80036DACu; return; }  /* 0x8008F694 jal */
    R[4] = R[17] + R[0];  /* 0x8008F69C */
    { R[31] = 0x8008F6A8u; R[5] = R[19] + R[0]; psx_next = 0x800270ACu; return; }  /* 0x8008F6A0 jal */
    R[2] = lh_(R[29] + 16);  /* 0x8008F6A8 */
    sh_(R[16], R[2]);  /* 0x8008F6B0 */
    R[2] = lh_(R[29] + 32);  /* 0x8008F6B4 */
    sh_(R[16] + 2, R[2]);  /* 0x8008F6BC */
    R[2] = lh_(R[29] + 48);  /* 0x8008F6C0 */
    sh_(R[16] + 4, R[2]);  /* 0x8008F6C8 */
    R[2] = lh_(R[29] + 20);  /* 0x8008F6CC */
    sh_(R[16] + 6, R[2]);  /* 0x8008F6D4 */
    R[2] = lh_(R[29] + 36);  /* 0x8008F6D8 */
    sh_(R[16] + 8, R[2]);  /* 0x8008F6E0 */
    R[2] = lh_(R[29] + 52);  /* 0x8008F6E4 */
    sh_(R[16] + 10, R[2]);  /* 0x8008F6EC */
    R[2] = lh_(R[29] + 24);  /* 0x8008F6F0 */
    sh_(R[16] + 12, R[2]);  /* 0x8008F6F8 */
    R[2] = lh_(R[29] + 40);  /* 0x8008F6FC */
    sh_(R[16] + 14, R[2]);  /* 0x8008F704 */
    R[2] = lh_(R[29] + 56);  /* 0x8008F708 */
    sh_(R[16] + 16, R[2]);  /* 0x8008F710 */
    R[31] = lw_(R[29] + 96);  /* 0x8008F714 */
    R[19] = lw_(R[29] + 92);  /* 0x8008F718 */
    R[18] = lw_(R[29] + 88);  /* 0x8008F71C */
    R[17] = lw_(R[29] + 84);  /* 0x8008F720 */
    R[16] = lw_(R[29] + 80);  /* 0x8008F724 */
    { R[29] = R[29] + 104; psx_next = R[31]; return; }  /* 0x8008F728 jr ra */
}

void ev_8008F65C(void) {
    R[4] = R[18] + R[0];  /* 0x8008F65C */
    R[19] = R[29] + 48;  /* 0x8008F660 */
    R[5] = R[19] + R[0];  /* 0x8008F664 */
    R[6] = R[17] + R[0];  /* 0x8008F668 */
    R[2] = R[0] + 4096;  /* 0x8008F66C */
    sw_(R[29] + 48, R[0]);  /* 0x8008F670 */
    sw_(R[29] + 52, R[0]);  /* 0x8008F674 */
    { R[31] = 0x8008F680u; sw_(R[29] + 56, R[2]); psx_next = 0x80036DACu; return; }  /* 0x8008F678 jal */
    R[4] = R[17] + R[0];  /* 0x8008F680 */
    { R[31] = 0x8008F68Cu; R[5] = R[29] + 16; psx_next = 0x800270ACu; return; }  /* 0x8008F684 jal */
    R[4] = R[29] + 16;  /* 0x8008F68C */
    R[5] = R[18] + R[0];  /* 0x8008F690 */
    { R[31] = 0x8008F69Cu; R[6] = R[17] + R[0]; psx_next = 0x80036DACu; return; }  /* 0x8008F694 jal */
    R[4] = R[17] + R[0];  /* 0x8008F69C */
    { R[31] = 0x8008F6A8u; R[5] = R[19] + R[0]; psx_next = 0x800270ACu; return; }  /* 0x8008F6A0 jal */
    R[2] = lh_(R[29] + 16);  /* 0x8008F6A8 */
    sh_(R[16], R[2]);  /* 0x8008F6B0 */
    R[2] = lh_(R[29] + 32);  /* 0x8008F6B4 */
    sh_(R[16] + 2, R[2]);  /* 0x8008F6BC */
    R[2] = lh_(R[29] + 48);  /* 0x8008F6C0 */
    sh_(R[16] + 4, R[2]);  /* 0x8008F6C8 */
    R[2] = lh_(R[29] + 20);  /* 0x8008F6CC */
    sh_(R[16] + 6, R[2]);  /* 0x8008F6D4 */
    R[2] = lh_(R[29] + 36);  /* 0x8008F6D8 */
    sh_(R[16] + 8, R[2]);  /* 0x8008F6E0 */
    R[2] = lh_(R[29] + 52);  /* 0x8008F6E4 */
    sh_(R[16] + 10, R[2]);  /* 0x8008F6EC */
    R[2] = lh_(R[29] + 24);  /* 0x8008F6F0 */
    sh_(R[16] + 12, R[2]);  /* 0x8008F6F8 */
    R[2] = lh_(R[29] + 40);  /* 0x8008F6FC */
    sh_(R[16] + 14, R[2]);  /* 0x8008F704 */
    R[2] = lh_(R[29] + 56);  /* 0x8008F708 */
    sh_(R[16] + 16, R[2]);  /* 0x8008F710 */
    R[31] = lw_(R[29] + 96);  /* 0x8008F714 */
    R[19] = lw_(R[29] + 92);  /* 0x8008F718 */
    R[18] = lw_(R[29] + 88);  /* 0x8008F71C */
    R[17] = lw_(R[29] + 84);  /* 0x8008F720 */
    R[16] = lw_(R[29] + 80);  /* 0x8008F724 */
    { R[29] = R[29] + 104; psx_next = R[31]; return; }  /* 0x8008F728 jr ra */
}

void ev_8008F680(void) {
    R[4] = R[17] + R[0];  /* 0x8008F680 */
    { R[31] = 0x8008F68Cu; R[5] = R[29] + 16; psx_next = 0x800270ACu; return; }  /* 0x8008F684 jal */
    R[4] = R[29] + 16;  /* 0x8008F68C */
    R[5] = R[18] + R[0];  /* 0x8008F690 */
    { R[31] = 0x8008F69Cu; R[6] = R[17] + R[0]; psx_next = 0x80036DACu; return; }  /* 0x8008F694 jal */
    R[4] = R[17] + R[0];  /* 0x8008F69C */
    { R[31] = 0x8008F6A8u; R[5] = R[19] + R[0]; psx_next = 0x800270ACu; return; }  /* 0x8008F6A0 jal */
    R[2] = lh_(R[29] + 16);  /* 0x8008F6A8 */
    sh_(R[16], R[2]);  /* 0x8008F6B0 */
    R[2] = lh_(R[29] + 32);  /* 0x8008F6B4 */
    sh_(R[16] + 2, R[2]);  /* 0x8008F6BC */
    R[2] = lh_(R[29] + 48);  /* 0x8008F6C0 */
    sh_(R[16] + 4, R[2]);  /* 0x8008F6C8 */
    R[2] = lh_(R[29] + 20);  /* 0x8008F6CC */
    sh_(R[16] + 6, R[2]);  /* 0x8008F6D4 */
    R[2] = lh_(R[29] + 36);  /* 0x8008F6D8 */
    sh_(R[16] + 8, R[2]);  /* 0x8008F6E0 */
    R[2] = lh_(R[29] + 52);  /* 0x8008F6E4 */
    sh_(R[16] + 10, R[2]);  /* 0x8008F6EC */
    R[2] = lh_(R[29] + 24);  /* 0x8008F6F0 */
    sh_(R[16] + 12, R[2]);  /* 0x8008F6F8 */
    R[2] = lh_(R[29] + 40);  /* 0x8008F6FC */
    sh_(R[16] + 14, R[2]);  /* 0x8008F704 */
    R[2] = lh_(R[29] + 56);  /* 0x8008F708 */
    sh_(R[16] + 16, R[2]);  /* 0x8008F710 */
    R[31] = lw_(R[29] + 96);  /* 0x8008F714 */
    R[19] = lw_(R[29] + 92);  /* 0x8008F718 */
    R[18] = lw_(R[29] + 88);  /* 0x8008F71C */
    R[17] = lw_(R[29] + 84);  /* 0x8008F720 */
    R[16] = lw_(R[29] + 80);  /* 0x8008F724 */
    { R[29] = R[29] + 104; psx_next = R[31]; return; }  /* 0x8008F728 jr ra */
}

void ev_8008F68C(void) {
    R[4] = R[29] + 16;  /* 0x8008F68C */
    R[5] = R[18] + R[0];  /* 0x8008F690 */
    { R[31] = 0x8008F69Cu; R[6] = R[17] + R[0]; psx_next = 0x80036DACu; return; }  /* 0x8008F694 jal */
    R[4] = R[17] + R[0];  /* 0x8008F69C */
    { R[31] = 0x8008F6A8u; R[5] = R[19] + R[0]; psx_next = 0x800270ACu; return; }  /* 0x8008F6A0 jal */
    R[2] = lh_(R[29] + 16);  /* 0x8008F6A8 */
    sh_(R[16], R[2]);  /* 0x8008F6B0 */
    R[2] = lh_(R[29] + 32);  /* 0x8008F6B4 */
    sh_(R[16] + 2, R[2]);  /* 0x8008F6BC */
    R[2] = lh_(R[29] + 48);  /* 0x8008F6C0 */
    sh_(R[16] + 4, R[2]);  /* 0x8008F6C8 */
    R[2] = lh_(R[29] + 20);  /* 0x8008F6CC */
    sh_(R[16] + 6, R[2]);  /* 0x8008F6D4 */
    R[2] = lh_(R[29] + 36);  /* 0x8008F6D8 */
    sh_(R[16] + 8, R[2]);  /* 0x8008F6E0 */
    R[2] = lh_(R[29] + 52);  /* 0x8008F6E4 */
    sh_(R[16] + 10, R[2]);  /* 0x8008F6EC */
    R[2] = lh_(R[29] + 24);  /* 0x8008F6F0 */
    sh_(R[16] + 12, R[2]);  /* 0x8008F6F8 */
    R[2] = lh_(R[29] + 40);  /* 0x8008F6FC */
    sh_(R[16] + 14, R[2]);  /* 0x8008F704 */
    R[2] = lh_(R[29] + 56);  /* 0x8008F708 */
    sh_(R[16] + 16, R[2]);  /* 0x8008F710 */
    R[31] = lw_(R[29] + 96);  /* 0x8008F714 */
    R[19] = lw_(R[29] + 92);  /* 0x8008F718 */
    R[18] = lw_(R[29] + 88);  /* 0x8008F71C */
    R[17] = lw_(R[29] + 84);  /* 0x8008F720 */
    R[16] = lw_(R[29] + 80);  /* 0x8008F724 */
    { R[29] = R[29] + 104; psx_next = R[31]; return; }  /* 0x8008F728 jr ra */
}

void ev_8008F69C(void) {
    R[4] = R[17] + R[0];  /* 0x8008F69C */
    { R[31] = 0x8008F6A8u; R[5] = R[19] + R[0]; psx_next = 0x800270ACu; return; }  /* 0x8008F6A0 jal */
    R[2] = lh_(R[29] + 16);  /* 0x8008F6A8 */
    sh_(R[16], R[2]);  /* 0x8008F6B0 */
    R[2] = lh_(R[29] + 32);  /* 0x8008F6B4 */
    sh_(R[16] + 2, R[2]);  /* 0x8008F6BC */
    R[2] = lh_(R[29] + 48);  /* 0x8008F6C0 */
    sh_(R[16] + 4, R[2]);  /* 0x8008F6C8 */
    R[2] = lh_(R[29] + 20);  /* 0x8008F6CC */
    sh_(R[16] + 6, R[2]);  /* 0x8008F6D4 */
    R[2] = lh_(R[29] + 36);  /* 0x8008F6D8 */
    sh_(R[16] + 8, R[2]);  /* 0x8008F6E0 */
    R[2] = lh_(R[29] + 52);  /* 0x8008F6E4 */
    sh_(R[16] + 10, R[2]);  /* 0x8008F6EC */
    R[2] = lh_(R[29] + 24);  /* 0x8008F6F0 */
    sh_(R[16] + 12, R[2]);  /* 0x8008F6F8 */
    R[2] = lh_(R[29] + 40);  /* 0x8008F6FC */
    sh_(R[16] + 14, R[2]);  /* 0x8008F704 */
    R[2] = lh_(R[29] + 56);  /* 0x8008F708 */
    sh_(R[16] + 16, R[2]);  /* 0x8008F710 */
    R[31] = lw_(R[29] + 96);  /* 0x8008F714 */
    R[19] = lw_(R[29] + 92);  /* 0x8008F718 */
    R[18] = lw_(R[29] + 88);  /* 0x8008F71C */
    R[17] = lw_(R[29] + 84);  /* 0x8008F720 */
    R[16] = lw_(R[29] + 80);  /* 0x8008F724 */
    { R[29] = R[29] + 104; psx_next = R[31]; return; }  /* 0x8008F728 jr ra */
}

void ev_8008F6A8(void) {
    R[2] = lh_(R[29] + 16);  /* 0x8008F6A8 */
    sh_(R[16], R[2]);  /* 0x8008F6B0 */
    R[2] = lh_(R[29] + 32);  /* 0x8008F6B4 */
    sh_(R[16] + 2, R[2]);  /* 0x8008F6BC */
    R[2] = lh_(R[29] + 48);  /* 0x8008F6C0 */
    sh_(R[16] + 4, R[2]);  /* 0x8008F6C8 */
    R[2] = lh_(R[29] + 20);  /* 0x8008F6CC */
    sh_(R[16] + 6, R[2]);  /* 0x8008F6D4 */
    R[2] = lh_(R[29] + 36);  /* 0x8008F6D8 */
    sh_(R[16] + 8, R[2]);  /* 0x8008F6E0 */
    R[2] = lh_(R[29] + 52);  /* 0x8008F6E4 */
    sh_(R[16] + 10, R[2]);  /* 0x8008F6EC */
    R[2] = lh_(R[29] + 24);  /* 0x8008F6F0 */
    sh_(R[16] + 12, R[2]);  /* 0x8008F6F8 */
    R[2] = lh_(R[29] + 40);  /* 0x8008F6FC */
    sh_(R[16] + 14, R[2]);  /* 0x8008F704 */
    R[2] = lh_(R[29] + 56);  /* 0x8008F708 */
    sh_(R[16] + 16, R[2]);  /* 0x8008F710 */
    R[31] = lw_(R[29] + 96);  /* 0x8008F714 */
    R[19] = lw_(R[29] + 92);  /* 0x8008F718 */
    R[18] = lw_(R[29] + 88);  /* 0x8008F71C */
    R[17] = lw_(R[29] + 84);  /* 0x8008F720 */
    R[16] = lw_(R[29] + 80);  /* 0x8008F724 */
    { R[29] = R[29] + 104; psx_next = R[31]; return; }  /* 0x8008F728 jr ra */
}

void ev_8008F730(void) {
    R[29] = R[29] - 64;  /* 0x8008F730 */
    sw_(R[29] + 48, R[16]);  /* 0x8008F734 */
    R[16] = R[6] + R[0];  /* 0x8008F738 */
    sw_(R[29] + 52, R[17]);  /* 0x8008F73C */
    R[17] = R[7] + R[0];  /* 0x8008F740 */
    R[5] = R[0] - R[5];  /* 0x8008F744 */
    R[5] = R[5] << 12;  /* 0x8008F748 */
    R[4] = R[4] << 12;  /* 0x8008F74C */
    sw_(R[29] + 20, R[4]);  /* 0x8008F750 */
    R[4] = R[29] + 16;  /* 0x8008F754 */
    sw_(R[29] + 16, R[5]);  /* 0x8008F758 */
    R[5] = R[29] + 32;  /* 0x8008F75C */
    sw_(R[29] + 56, R[31]);  /* 0x8008F760 */
    { R[31] = 0x8008F76Cu; sw_(R[29] + 24, R[0]); psx_next = 0x800270ACu; return; }  /* 0x8008F764 jal */
    R[2] = lw_(R[29] + 32);  /* 0x8008F76C */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F774 */
    R[2] = LO;  /* 0x8008F778 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008F788; } }  /* 0x8008F77C */
    R[2] = R[2] + 4095;  /* 0x8008F784 */
L_8008F788:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008F788 */
    sw_(R[17], R[2]);  /* 0x8008F78C */
    R[2] = lw_(R[29] + 36);  /* 0x8008F790 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F798 */
    R[2] = LO;  /* 0x8008F79C */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_8008F7B0; } }  /* 0x8008F7A0 */
    R[2] = R[2] + 4095;  /* 0x8008F7A8 */
    R[3] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008F7AC */
L_8008F7B0:;
    R[2] = lw_(R[29] + 80);  /* 0x8008F7B0 */
    sw_(R[2], R[3]);  /* 0x8008F7B8 */
    R[31] = lw_(R[29] + 56);  /* 0x8008F7BC */
    R[17] = lw_(R[29] + 52);  /* 0x8008F7C0 */
    R[16] = lw_(R[29] + 48);  /* 0x8008F7C4 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008F7C8 jr ra */
}

void ev_8008F76C(void) {
    R[2] = lw_(R[29] + 32);  /* 0x8008F76C */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F774 */
    R[2] = LO;  /* 0x8008F778 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008F788; } }  /* 0x8008F77C */
    R[2] = R[2] + 4095;  /* 0x8008F784 */
L_8008F788:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008F788 */
    sw_(R[17], R[2]);  /* 0x8008F78C */
    R[2] = lw_(R[29] + 36);  /* 0x8008F790 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F798 */
    R[2] = LO;  /* 0x8008F79C */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_8008F7B0; } }  /* 0x8008F7A0 */
    R[2] = R[2] + 4095;  /* 0x8008F7A8 */
    R[3] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008F7AC */
L_8008F7B0:;
    R[2] = lw_(R[29] + 80);  /* 0x8008F7B0 */
    sw_(R[2], R[3]);  /* 0x8008F7B8 */
    R[31] = lw_(R[29] + 56);  /* 0x8008F7BC */
    R[17] = lw_(R[29] + 52);  /* 0x8008F7C0 */
    R[16] = lw_(R[29] + 48);  /* 0x8008F7C4 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008F7C8 jr ra */
}

void ev_8008F7D0(void) {
    R[29] = R[29] - 56;  /* 0x8008F7D0 */
    sw_(R[29] + 40, R[22]);  /* 0x8008F7D4 */
    R[22] = lw_(R[29] + 72);  /* 0x8008F7D8 */
    sw_(R[29] + 36, R[21]);  /* 0x8008F7DC */
    R[21] = R[7] + R[0];  /* 0x8008F7E0 */
    sw_(R[29] + 24, R[18]);  /* 0x8008F7E4 */
    R[18] = R[0] + R[0];  /* 0x8008F7E8 */
    sw_(R[29] + 52, R[31]);  /* 0x8008F7EC */
    sw_(R[29] + 48, R[30]);  /* 0x8008F7F0 */
    sw_(R[29] + 44, R[23]);  /* 0x8008F7F4 */
    sw_(R[29] + 32, R[20]);  /* 0x8008F7F8 */
    sw_(R[29] + 28, R[19]);  /* 0x8008F7FC */
    sw_(R[29] + 20, R[17]);  /* 0x8008F800 */
    sw_(R[29] + 16, R[16]);  /* 0x8008F804 */
    { uint32_t _c = ((int32_t)R[22] <= 0); sw_(R[29] + 64, R[6]); if (_c) { psx_next = 0x8008FA04u; return; } }  /* 0x8008F808 b extern */
    R[30] = 0x800Cu << 16;  /* 0x8008F810 */
    R[20] = 0x800Eu << 16;  /* 0x8008F814 */
    R[23] = R[20] - 7120;  /* 0x8008F818 */
    R[19] = 0xFFu << 16;  /* 0x8008F81C */
    R[19] = R[19] | 0xFFFF;  /* 0x8008F820 */
    R[2] = 0x800Bu << 16;  /* 0x8008F824 */
    R[16] = lw_(R[30] + -24632);  /* 0x8008F828 */
    R[2] = lw_(R[2] + 30896);  /* 0x8008F82C */
    R[2] = (R[16] < R[2]);  /* 0x8008F834 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008F9F4u; return; } }  /* 0x8008F838 b extern */
    { R[31] = 0x8008F848u; R[4] = R[16] + R[0]; psx_next = 0x80035758u; return; }  /* 0x8008F840 jal */
    R[4] = R[16] + R[0];  /* 0x8008F848 */
    { R[31] = 0x8008F854u; R[5] = R[0] + 1; psx_next = 0x80035728u; return; }  /* 0x8008F84C jal */
    R[2] = R[0] + 4096;  /* 0x8008F854 */
    psx_div((int32_t)R[2], (int32_t)R[22]);  /* 0x8008F858 */
    R[2] = LO;  /* 0x8008F85C */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F868 */
    R[2] = lh_(R[20] + -7120);  /* 0x8008F86C */
    sh_(R[16] + 8, R[2]);  /* 0x8008F874 */
    R[2] = lh_(R[23] + 2);  /* 0x8008F878 */
    sh_(R[16] + 10, R[2]);  /* 0x8008F880 */
    R[17] = LO;  /* 0x8008F884 */
    { R[31] = 0x8008F890u; R[4] = R[17] & 0xFFF; psx_next = 0x80035B18u; return; }  /* 0x8008F888 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F890 */
    R[3] = LO;  /* 0x8008F894 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[17] - 1024; if (_c) { goto L_8008F8A4; } }  /* 0x8008F898 */
    R[3] = R[3] + 4095;  /* 0x8008F8A0 */
L_8008F8A4:;
    R[4] = R[4] & 0xFFF;  /* 0x8008F8A4 */
    R[2] = lh_(R[20] + -7120);  /* 0x8008F8A8 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008F8AC */
    R[2] = R[2] + R[3];  /* 0x8008F8B0 */
    { R[31] = 0x8008F8BCu; sh_(R[16] + 16, R[2]); psx_next = 0x80035B18u; return; }  /* 0x8008F8B4 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F8BC */
    R[3] = LO;  /* 0x8008F8C0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[17] + 256; if (_c) { goto L_8008F8D0; } }  /* 0x8008F8C4 */
    R[3] = R[3] + 4095;  /* 0x8008F8CC */
L_8008F8D0:;
    R[4] = R[4] & 0xFFF;  /* 0x8008F8D0 */
    R[2] = lh_(R[23] + 2);  /* 0x8008F8D4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008F8D8 */
    R[2] = R[2] + R[3];  /* 0x8008F8DC */
    { R[31] = 0x8008F8E8u; sh_(R[16] + 18, R[2]); psx_next = 0x80035B18u; return; }  /* 0x8008F8E0 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F8E8 */
    R[3] = LO;  /* 0x8008F8EC */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[17] - 768; if (_c) { goto L_8008F8FC; } }  /* 0x8008F8F0 */
    R[3] = R[3] + 4095;  /* 0x8008F8F8 */
L_8008F8FC:;
    R[4] = R[4] & 0xFFF;  /* 0x8008F8FC */
    R[2] = lh_(R[20] + -7120);  /* 0x8008F900 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008F904 */
    R[2] = R[2] + R[3];  /* 0x8008F908 */
    { R[31] = 0x8008F914u; sh_(R[16] + 24, R[2]); psx_next = 0x80035B18u; return; }  /* 0x8008F90C jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F914 */
    R[2] = LO;  /* 0x8008F918 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_8008F92C; } }  /* 0x8008F91C */
    R[2] = R[2] + 4095;  /* 0x8008F924 */
    R[3] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008F928 */
L_8008F92C:;
    R[2] = 0x800Bu << 16;  /* 0x8008F92C */
    R[5] = lh_(R[23] + 2);  /* 0x8008F930 */
    R[8] = lb_(R[29] + 76);  /* 0x8008F934 */
    R[5] = R[5] + R[3];  /* 0x8008F938 */
    sb_(R[16] + 4, R[8]);  /* 0x8008F93C */
    R[8] = lb_(R[29] + 88);  /* 0x8008F940 */
    R[3] = lw_(R[16]);  /* 0x8008F944 */
    sb_(R[16] + 12, R[8]);  /* 0x8008F948 */
    R[8] = lb_(R[29] + 100);  /* 0x8008F94C */
    psx_next = 0x8008F954u; return;  /* fallthrough */
}

void ev_8008F828(void) {
    R[16] = lw_(R[30] + -24632);  /* 0x8008F828 */
    R[2] = lw_(R[2] + 30896);  /* 0x8008F82C */
    R[2] = (R[16] < R[2]);  /* 0x8008F834 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008F9F4u; return; } }  /* 0x8008F838 b extern */
    { R[31] = 0x8008F848u; R[4] = R[16] + R[0]; psx_next = 0x80035758u; return; }  /* 0x8008F840 jal */
    R[4] = R[16] + R[0];  /* 0x8008F848 */
    { R[31] = 0x8008F854u; R[5] = R[0] + 1; psx_next = 0x80035728u; return; }  /* 0x8008F84C jal */
    R[2] = R[0] + 4096;  /* 0x8008F854 */
    psx_div((int32_t)R[2], (int32_t)R[22]);  /* 0x8008F858 */
    R[2] = LO;  /* 0x8008F85C */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F868 */
    R[2] = lh_(R[20] + -7120);  /* 0x8008F86C */
    sh_(R[16] + 8, R[2]);  /* 0x8008F874 */
    R[2] = lh_(R[23] + 2);  /* 0x8008F878 */
    sh_(R[16] + 10, R[2]);  /* 0x8008F880 */
    R[17] = LO;  /* 0x8008F884 */
    { R[31] = 0x8008F890u; R[4] = R[17] & 0xFFF; psx_next = 0x80035B18u; return; }  /* 0x8008F888 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F890 */
    R[3] = LO;  /* 0x8008F894 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[17] - 1024; if (_c) { goto L_8008F8A4; } }  /* 0x8008F898 */
    R[3] = R[3] + 4095;  /* 0x8008F8A0 */
L_8008F8A4:;
    R[4] = R[4] & 0xFFF;  /* 0x8008F8A4 */
    R[2] = lh_(R[20] + -7120);  /* 0x8008F8A8 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008F8AC */
    R[2] = R[2] + R[3];  /* 0x8008F8B0 */
    { R[31] = 0x8008F8BCu; sh_(R[16] + 16, R[2]); psx_next = 0x80035B18u; return; }  /* 0x8008F8B4 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F8BC */
    R[3] = LO;  /* 0x8008F8C0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[17] + 256; if (_c) { goto L_8008F8D0; } }  /* 0x8008F8C4 */
    R[3] = R[3] + 4095;  /* 0x8008F8CC */
L_8008F8D0:;
    R[4] = R[4] & 0xFFF;  /* 0x8008F8D0 */
    R[2] = lh_(R[23] + 2);  /* 0x8008F8D4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008F8D8 */
    R[2] = R[2] + R[3];  /* 0x8008F8DC */
    { R[31] = 0x8008F8E8u; sh_(R[16] + 18, R[2]); psx_next = 0x80035B18u; return; }  /* 0x8008F8E0 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F8E8 */
    R[3] = LO;  /* 0x8008F8EC */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[17] - 768; if (_c) { goto L_8008F8FC; } }  /* 0x8008F8F0 */
    R[3] = R[3] + 4095;  /* 0x8008F8F8 */
L_8008F8FC:;
    R[4] = R[4] & 0xFFF;  /* 0x8008F8FC */
    R[2] = lh_(R[20] + -7120);  /* 0x8008F900 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008F904 */
    R[2] = R[2] + R[3];  /* 0x8008F908 */
    { R[31] = 0x8008F914u; sh_(R[16] + 24, R[2]); psx_next = 0x80035B18u; return; }  /* 0x8008F90C jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F914 */
    R[2] = LO;  /* 0x8008F918 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_8008F92C; } }  /* 0x8008F91C */
    R[2] = R[2] + 4095;  /* 0x8008F924 */
    R[3] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008F928 */
L_8008F92C:;
    R[2] = 0x800Bu << 16;  /* 0x8008F92C */
    R[5] = lh_(R[23] + 2);  /* 0x8008F930 */
    R[8] = lb_(R[29] + 76);  /* 0x8008F934 */
    R[5] = R[5] + R[3];  /* 0x8008F938 */
    sb_(R[16] + 4, R[8]);  /* 0x8008F93C */
    R[8] = lb_(R[29] + 88);  /* 0x8008F940 */
    R[3] = lw_(R[16]);  /* 0x8008F944 */
    sb_(R[16] + 12, R[8]);  /* 0x8008F948 */
    R[8] = lb_(R[29] + 100);  /* 0x8008F94C */
    psx_next = 0x8008F954u; return;  /* fallthrough */
}

void ev_8008F848(void) {
    R[4] = R[16] + R[0];  /* 0x8008F848 */
    { R[31] = 0x8008F854u; R[5] = R[0] + 1; psx_next = 0x80035728u; return; }  /* 0x8008F84C jal */
    R[2] = R[0] + 4096;  /* 0x8008F854 */
    psx_div((int32_t)R[2], (int32_t)R[22]);  /* 0x8008F858 */
    R[2] = LO;  /* 0x8008F85C */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F868 */
    R[2] = lh_(R[20] + -7120);  /* 0x8008F86C */
    sh_(R[16] + 8, R[2]);  /* 0x8008F874 */
    R[2] = lh_(R[23] + 2);  /* 0x8008F878 */
    sh_(R[16] + 10, R[2]);  /* 0x8008F880 */
    R[17] = LO;  /* 0x8008F884 */
    { R[31] = 0x8008F890u; R[4] = R[17] & 0xFFF; psx_next = 0x80035B18u; return; }  /* 0x8008F888 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F890 */
    R[3] = LO;  /* 0x8008F894 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[17] - 1024; if (_c) { goto L_8008F8A4; } }  /* 0x8008F898 */
    R[3] = R[3] + 4095;  /* 0x8008F8A0 */
L_8008F8A4:;
    R[4] = R[4] & 0xFFF;  /* 0x8008F8A4 */
    R[2] = lh_(R[20] + -7120);  /* 0x8008F8A8 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008F8AC */
    R[2] = R[2] + R[3];  /* 0x8008F8B0 */
    { R[31] = 0x8008F8BCu; sh_(R[16] + 16, R[2]); psx_next = 0x80035B18u; return; }  /* 0x8008F8B4 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F8BC */
    R[3] = LO;  /* 0x8008F8C0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[17] + 256; if (_c) { goto L_8008F8D0; } }  /* 0x8008F8C4 */
    R[3] = R[3] + 4095;  /* 0x8008F8CC */
L_8008F8D0:;
    R[4] = R[4] & 0xFFF;  /* 0x8008F8D0 */
    R[2] = lh_(R[23] + 2);  /* 0x8008F8D4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008F8D8 */
    R[2] = R[2] + R[3];  /* 0x8008F8DC */
    { R[31] = 0x8008F8E8u; sh_(R[16] + 18, R[2]); psx_next = 0x80035B18u; return; }  /* 0x8008F8E0 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F8E8 */
    R[3] = LO;  /* 0x8008F8EC */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[17] - 768; if (_c) { goto L_8008F8FC; } }  /* 0x8008F8F0 */
    R[3] = R[3] + 4095;  /* 0x8008F8F8 */
L_8008F8FC:;
    R[4] = R[4] & 0xFFF;  /* 0x8008F8FC */
    R[2] = lh_(R[20] + -7120);  /* 0x8008F900 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008F904 */
    R[2] = R[2] + R[3];  /* 0x8008F908 */
    { R[31] = 0x8008F914u; sh_(R[16] + 24, R[2]); psx_next = 0x80035B18u; return; }  /* 0x8008F90C jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F914 */
    R[2] = LO;  /* 0x8008F918 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_8008F92C; } }  /* 0x8008F91C */
    R[2] = R[2] + 4095;  /* 0x8008F924 */
    R[3] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008F928 */
L_8008F92C:;
    R[2] = 0x800Bu << 16;  /* 0x8008F92C */
    R[5] = lh_(R[23] + 2);  /* 0x8008F930 */
    R[8] = lb_(R[29] + 76);  /* 0x8008F934 */
    R[5] = R[5] + R[3];  /* 0x8008F938 */
    sb_(R[16] + 4, R[8]);  /* 0x8008F93C */
    R[8] = lb_(R[29] + 88);  /* 0x8008F940 */
    R[3] = lw_(R[16]);  /* 0x8008F944 */
    sb_(R[16] + 12, R[8]);  /* 0x8008F948 */
    R[8] = lb_(R[29] + 100);  /* 0x8008F94C */
    psx_next = 0x8008F954u; return;  /* fallthrough */
}

void ev_8008F854(void) {
    R[2] = R[0] + 4096;  /* 0x8008F854 */
    psx_div((int32_t)R[2], (int32_t)R[22]);  /* 0x8008F858 */
    R[2] = LO;  /* 0x8008F85C */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F868 */
    R[2] = lh_(R[20] + -7120);  /* 0x8008F86C */
    sh_(R[16] + 8, R[2]);  /* 0x8008F874 */
    R[2] = lh_(R[23] + 2);  /* 0x8008F878 */
    sh_(R[16] + 10, R[2]);  /* 0x8008F880 */
    R[17] = LO;  /* 0x8008F884 */
    { R[31] = 0x8008F890u; R[4] = R[17] & 0xFFF; psx_next = 0x80035B18u; return; }  /* 0x8008F888 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F890 */
    R[3] = LO;  /* 0x8008F894 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[17] - 1024; if (_c) { goto L_8008F8A4; } }  /* 0x8008F898 */
    R[3] = R[3] + 4095;  /* 0x8008F8A0 */
L_8008F8A4:;
    R[4] = R[4] & 0xFFF;  /* 0x8008F8A4 */
    R[2] = lh_(R[20] + -7120);  /* 0x8008F8A8 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008F8AC */
    R[2] = R[2] + R[3];  /* 0x8008F8B0 */
    { R[31] = 0x8008F8BCu; sh_(R[16] + 16, R[2]); psx_next = 0x80035B18u; return; }  /* 0x8008F8B4 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F8BC */
    R[3] = LO;  /* 0x8008F8C0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[17] + 256; if (_c) { goto L_8008F8D0; } }  /* 0x8008F8C4 */
    R[3] = R[3] + 4095;  /* 0x8008F8CC */
L_8008F8D0:;
    R[4] = R[4] & 0xFFF;  /* 0x8008F8D0 */
    R[2] = lh_(R[23] + 2);  /* 0x8008F8D4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008F8D8 */
    R[2] = R[2] + R[3];  /* 0x8008F8DC */
    { R[31] = 0x8008F8E8u; sh_(R[16] + 18, R[2]); psx_next = 0x80035B18u; return; }  /* 0x8008F8E0 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F8E8 */
    R[3] = LO;  /* 0x8008F8EC */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[17] - 768; if (_c) { goto L_8008F8FC; } }  /* 0x8008F8F0 */
    R[3] = R[3] + 4095;  /* 0x8008F8F8 */
L_8008F8FC:;
    R[4] = R[4] & 0xFFF;  /* 0x8008F8FC */
    R[2] = lh_(R[20] + -7120);  /* 0x8008F900 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008F904 */
    R[2] = R[2] + R[3];  /* 0x8008F908 */
    { R[31] = 0x8008F914u; sh_(R[16] + 24, R[2]); psx_next = 0x80035B18u; return; }  /* 0x8008F90C jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F914 */
    R[2] = LO;  /* 0x8008F918 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_8008F92C; } }  /* 0x8008F91C */
    R[2] = R[2] + 4095;  /* 0x8008F924 */
    R[3] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008F928 */
L_8008F92C:;
    R[2] = 0x800Bu << 16;  /* 0x8008F92C */
    R[5] = lh_(R[23] + 2);  /* 0x8008F930 */
    R[8] = lb_(R[29] + 76);  /* 0x8008F934 */
    R[5] = R[5] + R[3];  /* 0x8008F938 */
    sb_(R[16] + 4, R[8]);  /* 0x8008F93C */
    R[8] = lb_(R[29] + 88);  /* 0x8008F940 */
    R[3] = lw_(R[16]);  /* 0x8008F944 */
    sb_(R[16] + 12, R[8]);  /* 0x8008F948 */
    R[8] = lb_(R[29] + 100);  /* 0x8008F94C */
    psx_next = 0x8008F954u; return;  /* fallthrough */
}

void ev_8008F890(void) {
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F890 */
    R[3] = LO;  /* 0x8008F894 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[17] - 1024; if (_c) { goto L_8008F8A4; } }  /* 0x8008F898 */
    R[3] = R[3] + 4095;  /* 0x8008F8A0 */
L_8008F8A4:;
    R[4] = R[4] & 0xFFF;  /* 0x8008F8A4 */
    R[2] = lh_(R[20] + -7120);  /* 0x8008F8A8 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008F8AC */
    R[2] = R[2] + R[3];  /* 0x8008F8B0 */
    { R[31] = 0x8008F8BCu; sh_(R[16] + 16, R[2]); psx_next = 0x80035B18u; return; }  /* 0x8008F8B4 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F8BC */
    R[3] = LO;  /* 0x8008F8C0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[17] + 256; if (_c) { goto L_8008F8D0; } }  /* 0x8008F8C4 */
    R[3] = R[3] + 4095;  /* 0x8008F8CC */
L_8008F8D0:;
    R[4] = R[4] & 0xFFF;  /* 0x8008F8D0 */
    R[2] = lh_(R[23] + 2);  /* 0x8008F8D4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008F8D8 */
    R[2] = R[2] + R[3];  /* 0x8008F8DC */
    { R[31] = 0x8008F8E8u; sh_(R[16] + 18, R[2]); psx_next = 0x80035B18u; return; }  /* 0x8008F8E0 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F8E8 */
    R[3] = LO;  /* 0x8008F8EC */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[17] - 768; if (_c) { goto L_8008F8FC; } }  /* 0x8008F8F0 */
    R[3] = R[3] + 4095;  /* 0x8008F8F8 */
L_8008F8FC:;
    R[4] = R[4] & 0xFFF;  /* 0x8008F8FC */
    R[2] = lh_(R[20] + -7120);  /* 0x8008F900 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008F904 */
    R[2] = R[2] + R[3];  /* 0x8008F908 */
    { R[31] = 0x8008F914u; sh_(R[16] + 24, R[2]); psx_next = 0x80035B18u; return; }  /* 0x8008F90C jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F914 */
    R[2] = LO;  /* 0x8008F918 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_8008F92C; } }  /* 0x8008F91C */
    R[2] = R[2] + 4095;  /* 0x8008F924 */
    R[3] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008F928 */
L_8008F92C:;
    R[2] = 0x800Bu << 16;  /* 0x8008F92C */
    R[5] = lh_(R[23] + 2);  /* 0x8008F930 */
    R[8] = lb_(R[29] + 76);  /* 0x8008F934 */
    R[5] = R[5] + R[3];  /* 0x8008F938 */
    sb_(R[16] + 4, R[8]);  /* 0x8008F93C */
    R[8] = lb_(R[29] + 88);  /* 0x8008F940 */
    R[3] = lw_(R[16]);  /* 0x8008F944 */
    sb_(R[16] + 12, R[8]);  /* 0x8008F948 */
    R[8] = lb_(R[29] + 100);  /* 0x8008F94C */
    psx_next = 0x8008F954u; return;  /* fallthrough */
}

void ev_8008F8BC(void) {
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F8BC */
    R[3] = LO;  /* 0x8008F8C0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[17] + 256; if (_c) { goto L_8008F8D0; } }  /* 0x8008F8C4 */
    R[3] = R[3] + 4095;  /* 0x8008F8CC */
L_8008F8D0:;
    R[4] = R[4] & 0xFFF;  /* 0x8008F8D0 */
    R[2] = lh_(R[23] + 2);  /* 0x8008F8D4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008F8D8 */
    R[2] = R[2] + R[3];  /* 0x8008F8DC */
    { R[31] = 0x8008F8E8u; sh_(R[16] + 18, R[2]); psx_next = 0x80035B18u; return; }  /* 0x8008F8E0 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F8E8 */
    R[3] = LO;  /* 0x8008F8EC */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[17] - 768; if (_c) { goto L_8008F8FC; } }  /* 0x8008F8F0 */
    R[3] = R[3] + 4095;  /* 0x8008F8F8 */
L_8008F8FC:;
    R[4] = R[4] & 0xFFF;  /* 0x8008F8FC */
    R[2] = lh_(R[20] + -7120);  /* 0x8008F900 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008F904 */
    R[2] = R[2] + R[3];  /* 0x8008F908 */
    { R[31] = 0x8008F914u; sh_(R[16] + 24, R[2]); psx_next = 0x80035B18u; return; }  /* 0x8008F90C jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F914 */
    R[2] = LO;  /* 0x8008F918 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_8008F92C; } }  /* 0x8008F91C */
    R[2] = R[2] + 4095;  /* 0x8008F924 */
    R[3] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008F928 */
L_8008F92C:;
    R[2] = 0x800Bu << 16;  /* 0x8008F92C */
    R[5] = lh_(R[23] + 2);  /* 0x8008F930 */
    R[8] = lb_(R[29] + 76);  /* 0x8008F934 */
    R[5] = R[5] + R[3];  /* 0x8008F938 */
    sb_(R[16] + 4, R[8]);  /* 0x8008F93C */
    R[8] = lb_(R[29] + 88);  /* 0x8008F940 */
    R[3] = lw_(R[16]);  /* 0x8008F944 */
    sb_(R[16] + 12, R[8]);  /* 0x8008F948 */
    R[8] = lb_(R[29] + 100);  /* 0x8008F94C */
    psx_next = 0x8008F954u; return;  /* fallthrough */
}

void ev_8008F8E8(void) {
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F8E8 */
    R[3] = LO;  /* 0x8008F8EC */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[17] - 768; if (_c) { goto L_8008F8FC; } }  /* 0x8008F8F0 */
    R[3] = R[3] + 4095;  /* 0x8008F8F8 */
L_8008F8FC:;
    R[4] = R[4] & 0xFFF;  /* 0x8008F8FC */
    R[2] = lh_(R[20] + -7120);  /* 0x8008F900 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008F904 */
    R[2] = R[2] + R[3];  /* 0x8008F908 */
    { R[31] = 0x8008F914u; sh_(R[16] + 24, R[2]); psx_next = 0x80035B18u; return; }  /* 0x8008F90C jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F914 */
    R[2] = LO;  /* 0x8008F918 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_8008F92C; } }  /* 0x8008F91C */
    R[2] = R[2] + 4095;  /* 0x8008F924 */
    R[3] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008F928 */
L_8008F92C:;
    R[2] = 0x800Bu << 16;  /* 0x8008F92C */
    R[5] = lh_(R[23] + 2);  /* 0x8008F930 */
    R[8] = lb_(R[29] + 76);  /* 0x8008F934 */
    R[5] = R[5] + R[3];  /* 0x8008F938 */
    sb_(R[16] + 4, R[8]);  /* 0x8008F93C */
    R[8] = lb_(R[29] + 88);  /* 0x8008F940 */
    R[3] = lw_(R[16]);  /* 0x8008F944 */
    sb_(R[16] + 12, R[8]);  /* 0x8008F948 */
    R[8] = lb_(R[29] + 100);  /* 0x8008F94C */
    psx_next = 0x8008F954u; return;  /* fallthrough */
}

void ev_8008F914(void) {
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008F914 */
    R[2] = LO;  /* 0x8008F918 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_8008F92C; } }  /* 0x8008F91C */
    R[2] = R[2] + 4095;  /* 0x8008F924 */
    R[3] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008F928 */
L_8008F92C:;
    R[2] = 0x800Bu << 16;  /* 0x8008F92C */
    R[5] = lh_(R[23] + 2);  /* 0x8008F930 */
    R[8] = lb_(R[29] + 76);  /* 0x8008F934 */
    R[5] = R[5] + R[3];  /* 0x8008F938 */
    sb_(R[16] + 4, R[8]);  /* 0x8008F93C */
    R[8] = lb_(R[29] + 88);  /* 0x8008F940 */
    R[3] = lw_(R[16]);  /* 0x8008F944 */
    sb_(R[16] + 12, R[8]);  /* 0x8008F948 */
    R[8] = lb_(R[29] + 100);  /* 0x8008F94C */
    psx_next = 0x8008F954u; return;  /* fallthrough */
}

void ev_8008F954(void) {
    sb_(R[16] + 20, R[8]);  /* 0x8008F954 */
    R[8] = lb_(R[29] + 80);  /* 0x8008F958 */
    sb_(R[16] + 5, R[8]);  /* 0x8008F960 */
    R[8] = lb_(R[29] + 92);  /* 0x8008F964 */
    sb_(R[16] + 13, R[8]);  /* 0x8008F96C */
    R[8] = lb_(R[29] + 104);  /* 0x8008F970 */
    sb_(R[16] + 21, R[8]);  /* 0x8008F978 */
    R[8] = lb_(R[29] + 84);  /* 0x8008F97C */
    sb_(R[16] + 6, R[8]);  /* 0x8008F984 */
    R[8] = lb_(R[29] + 96);  /* 0x8008F988 */
    sb_(R[16] + 14, R[8]);  /* 0x8008F990 */
    R[8] = lb_(R[29] + 108);  /* 0x8008F994 */
    sh_(R[16] + 26, R[5]);  /* 0x8008F998 */
    R[5] = 0xFF00u << 16;  /* 0x8008F99C */
    sb_(R[16] + 22, R[8]);  /* 0x8008F9A0 */
    R[4] = lw_(R[2] + 30548);  /* 0x8008F9A4 */
    R[8] = lw_(R[29] + 64);  /* 0x8008F9A8 */
    R[4] = R[4] << 13;  /* 0x8008F9AC */
    R[2] = R[8] << 2;  /* 0x8008F9B0 */
    R[4] = R[4] + R[2];  /* 0x8008F9B4 */
    R[8] = 0x800Cu << 16;  /* 0x8008F9B8 */
    R[8] = R[8] - 24624;  /* 0x8008F9BC */
    R[4] = R[4] + R[8];  /* 0x8008F9C0 */
    R[2] = lw_(R[4]);  /* 0x8008F9C4 */
    R[3] = R[3] & R[5];  /* 0x8008F9C8 */
    R[2] = R[2] & R[19];  /* 0x8008F9CC */
    R[3] = R[3] | R[2];  /* 0x8008F9D0 */
    sw_(R[16], R[3]);  /* 0x8008F9D4 */
    R[3] = R[16] & R[19];  /* 0x8008F9D8 */
    R[2] = lw_(R[4]);  /* 0x8008F9DC */
    R[16] = R[16] + 28;  /* 0x8008F9E0 */
    sw_(R[30] + -24632, R[16]);  /* 0x8008F9E4 */
    R[2] = R[2] & R[5];  /* 0x8008F9E8 */
    R[2] = R[2] | R[3];  /* 0x8008F9EC */
    sw_(R[4], R[2]);  /* 0x8008F9F0 */
    R[18] = R[18] + 1;  /* 0x8008F9F4 */
    R[2] = ((int32_t)R[18] < (int32_t)R[22]);  /* 0x8008F9F8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { psx_next = 0x8008F828u; return; } }  /* 0x8008F9FC b extern */
    R[31] = lw_(R[29] + 52);  /* 0x8008FA04 */
    R[30] = lw_(R[29] + 48);  /* 0x8008FA08 */
    R[23] = lw_(R[29] + 44);  /* 0x8008FA0C */
    R[22] = lw_(R[29] + 40);  /* 0x8008FA10 */
    R[21] = lw_(R[29] + 36);  /* 0x8008FA14 */
    R[20] = lw_(R[29] + 32);  /* 0x8008FA18 */
    R[19] = lw_(R[29] + 28);  /* 0x8008FA1C */
    R[18] = lw_(R[29] + 24);  /* 0x8008FA20 */
    R[17] = lw_(R[29] + 20);  /* 0x8008FA24 */
    R[16] = lw_(R[29] + 16);  /* 0x8008FA28 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x8008FA2C jr ra */
}

void ev_8008F9F4(void) {
    R[18] = R[18] + 1;  /* 0x8008F9F4 */
    R[2] = ((int32_t)R[18] < (int32_t)R[22]);  /* 0x8008F9F8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { psx_next = 0x8008F828u; return; } }  /* 0x8008F9FC b extern */
    R[31] = lw_(R[29] + 52);  /* 0x8008FA04 */
    R[30] = lw_(R[29] + 48);  /* 0x8008FA08 */
    R[23] = lw_(R[29] + 44);  /* 0x8008FA0C */
    R[22] = lw_(R[29] + 40);  /* 0x8008FA10 */
    R[21] = lw_(R[29] + 36);  /* 0x8008FA14 */
    R[20] = lw_(R[29] + 32);  /* 0x8008FA18 */
    R[19] = lw_(R[29] + 28);  /* 0x8008FA1C */
    R[18] = lw_(R[29] + 24);  /* 0x8008FA20 */
    R[17] = lw_(R[29] + 20);  /* 0x8008FA24 */
    R[16] = lw_(R[29] + 16);  /* 0x8008FA28 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x8008FA2C jr ra */
}

void ev_8008FA04(void) {
    R[31] = lw_(R[29] + 52);  /* 0x8008FA04 */
    R[30] = lw_(R[29] + 48);  /* 0x8008FA08 */
    R[23] = lw_(R[29] + 44);  /* 0x8008FA0C */
    R[22] = lw_(R[29] + 40);  /* 0x8008FA10 */
    R[21] = lw_(R[29] + 36);  /* 0x8008FA14 */
    R[20] = lw_(R[29] + 32);  /* 0x8008FA18 */
    R[19] = lw_(R[29] + 28);  /* 0x8008FA1C */
    R[18] = lw_(R[29] + 24);  /* 0x8008FA20 */
    R[17] = lw_(R[29] + 20);  /* 0x8008FA24 */
    R[16] = lw_(R[29] + 16);  /* 0x8008FA28 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x8008FA2C jr ra */
}

void ev_8008FA34(void) {
    R[29] = R[29] - 56;  /* 0x8008FA34 */
    sw_(R[29] + 36, R[21]);  /* 0x8008FA38 */
    R[21] = R[4] + R[0];  /* 0x8008FA3C */
    sw_(R[29] + 40, R[22]);  /* 0x8008FA40 */
    R[22] = R[5] + R[0];  /* 0x8008FA44 */
    sw_(R[29] + 32, R[20]);  /* 0x8008FA48 */
    R[20] = R[6] + R[0];  /* 0x8008FA4C */
    sw_(R[29] + 20, R[17]);  /* 0x8008FA50 */
    R[17] = R[0] + R[0];  /* 0x8008FA54 */
    sw_(R[29] + 48, R[30]);  /* 0x8008FA58 */
    R[30] = 0x800Cu << 16;  /* 0x8008FA5C */
    R[2] = 0x800Bu << 16;  /* 0x8008FA60 */
    sw_(R[29] + 44, R[23]);  /* 0x8008FA64 */
    R[23] = R[2] - 13168;  /* 0x8008FA68 */
    sw_(R[29] + 28, R[19]);  /* 0x8008FA6C */
    R[19] = 0xFFu << 16;  /* 0x8008FA70 */
    R[19] = R[19] | 0xFFFF;  /* 0x8008FA74 */
    sw_(R[29] + 24, R[18]);  /* 0x8008FA78 */
    R[18] = 0x800Bu << 16;  /* 0x8008FA7C */
    R[18] = R[18] - 13184;  /* 0x8008FA80 */
    sw_(R[29] + 52, R[31]);  /* 0x8008FA84 */
    sw_(R[29] + 16, R[16]);  /* 0x8008FA88 */
    sw_(R[29] + 68, R[7]);  /* 0x8008FA8C */
L_8008FA90:;
    R[2] = 0x800Bu << 16;  /* 0x8008FA90 */
    R[16] = lw_(R[30] + -24632);  /* 0x8008FA94 */
    R[2] = lw_(R[2] + 30896);  /* 0x8008FA98 */
    R[2] = (R[16] < R[2]);  /* 0x8008FAA0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008FC30; } }  /* 0x8008FAA4 */
    { R[31] = 0x8008FAB4u; R[4] = R[16] + R[0]; psx_next = 0x80035758u; return; }  /* 0x8008FAAC jal */
    R[4] = R[16] + R[0];  /* 0x8008FAB4 */
    { R[31] = 0x8008FAC0u; R[5] = R[0] + 1; psx_next = 0x80035728u; return; }  /* 0x8008FAB8 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[18]);  /* 0x8008FAC0 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FAC8 */
    R[2] = LO;  /* 0x8008FACC */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = R[17] << 1; if (_c) { goto L_8008FADC; } }  /* 0x8008FAD0 */
    R[2] = R[2] + 4095;  /* 0x8008FAD8 */
L_8008FADC:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008FADC */
    R[2] = R[2] + R[21];  /* 0x8008FAE0 */
    sh_(R[16] + 8, R[2]);  /* 0x8008FAE4 */
    R[2] = R[3] + R[23];  /* 0x8008FAE8 */
    R[2] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x8008FAEC */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FAF4 */
    R[2] = LO;  /* 0x8008FAF8 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008FB08; } }  /* 0x8008FAFC */
    R[2] = R[2] + 4095;  /* 0x8008FB04 */
L_8008FB08:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008FB08 */
    R[2] = R[2] + R[22];  /* 0x8008FB0C */
    sh_(R[16] + 10, R[2]);  /* 0x8008FB10 */
    R[2] = R[17] + 1;  /* 0x8008FB14 */
    R[2] = R[2] & 0x7;  /* 0x8008FB18 */
    R[3] = R[2] << 1;  /* 0x8008FB1C */
    R[8] = 0x800Bu << 16;  /* 0x8008FB20 */
    R[8] = R[8] - 13184;  /* 0x8008FB24 */
    R[2] = R[3] + R[8];  /* 0x8008FB28 */
    R[2] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x8008FB2C */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FB34 */
    R[2] = LO;  /* 0x8008FB38 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008FB48; } }  /* 0x8008FB3C */
    R[2] = R[2] + 4095;  /* 0x8008FB44 */
L_8008FB48:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008FB48 */
    R[2] = R[2] + R[21];  /* 0x8008FB4C */
    sh_(R[16] + 16, R[2]);  /* 0x8008FB50 */
    R[2] = R[3] + R[23];  /* 0x8008FB54 */
    R[2] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x8008FB58 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FB60 */
    R[2] = LO;  /* 0x8008FB64 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008FB74; } }  /* 0x8008FB68 */
    R[2] = R[2] + 4095;  /* 0x8008FB70 */
L_8008FB74:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008FB74 */
    R[2] = R[2] + R[22];  /* 0x8008FB78 */
    sh_(R[16] + 18, R[2]);  /* 0x8008FB7C */
    sh_(R[16] + 24, R[21]);  /* 0x8008FB80 */
    sh_(R[16] + 26, R[22]);  /* 0x8008FB84 */
    R[2] = 0x800Bu << 16;  /* 0x8008FB88 */
    R[8] = lb_(R[29] + 68);  /* 0x8008FB8C */
    R[5] = 0xFF00u << 16;  /* 0x8008FB90 */
    sb_(R[16] + 4, R[8]);  /* 0x8008FB94 */
    R[8] = lb_(R[29] + 80);  /* 0x8008FB98 */
    sb_(R[16] + 12, R[8]);  /* 0x8008FBA0 */
    R[8] = lb_(R[29] + 92);  /* 0x8008FBA4 */
    sb_(R[16] + 20, R[8]);  /* 0x8008FBAC */
    R[8] = lb_(R[29] + 72);  /* 0x8008FBB0 */
    sb_(R[16] + 5, R[8]);  /* 0x8008FBB8 */
    R[8] = lb_(R[29] + 84);  /* 0x8008FBBC */
    sb_(R[16] + 13, R[8]);  /* 0x8008FBC4 */
    R[8] = lb_(R[29] + 96);  /* 0x8008FBC8 */
    sb_(R[16] + 21, R[8]);  /* 0x8008FBD0 */
    R[8] = lb_(R[29] + 76);  /* 0x8008FBD4 */
    sb_(R[16] + 6, R[8]);  /* 0x8008FBDC */
    R[8] = lb_(R[29] + 88);  /* 0x8008FBE0 */
    sb_(R[16] + 14, R[8]);  /* 0x8008FBE8 */
    R[8] = lb_(R[29] + 100);  /* 0x8008FBEC */
    sb_(R[16] + 22, R[8]);  /* 0x8008FBF4 */
    R[4] = lw_(R[2] + 30552);  /* 0x8008FBF8 */
    R[3] = lw_(R[16]);  /* 0x8008FBFC */
    R[2] = lw_(R[4] + 36);  /* 0x8008FC00 */
    R[3] = R[3] & R[5];  /* 0x8008FC04 */
    R[2] = R[2] & R[19];  /* 0x8008FC08 */
    R[3] = R[3] | R[2];  /* 0x8008FC0C */
    sw_(R[16], R[3]);  /* 0x8008FC10 */
    R[3] = R[16] & R[19];  /* 0x8008FC14 */
    R[2] = lw_(R[4] + 36);  /* 0x8008FC18 */
    R[16] = R[16] + 28;  /* 0x8008FC1C */
    sw_(R[30] + -24632, R[16]);  /* 0x8008FC20 */
    R[2] = R[2] & R[5];  /* 0x8008FC24 */
    R[2] = R[2] | R[3];  /* 0x8008FC28 */
    sw_(R[4] + 36, R[2]);  /* 0x8008FC2C */
L_8008FC30:;
    R[17] = R[17] + 1;  /* 0x8008FC30 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8008FC34 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 2; if (_c) { psx_bb(); goto L_8008FA90; } }  /* 0x8008FC38 */
    R[31] = lw_(R[29] + 52);  /* 0x8008FC40 */
    R[30] = lw_(R[29] + 48);  /* 0x8008FC44 */
    R[23] = lw_(R[29] + 44);  /* 0x8008FC48 */
    R[22] = lw_(R[29] + 40);  /* 0x8008FC4C */
    R[21] = lw_(R[29] + 36);  /* 0x8008FC50 */
    psx_next = 0x8008FC54u; return;  /* fallthrough */
}

void ev_8008FA90(void) {
L_8008FA90:;
    R[2] = 0x800Bu << 16;  /* 0x8008FA90 */
    R[16] = lw_(R[30] + -24632);  /* 0x8008FA94 */
    R[2] = lw_(R[2] + 30896);  /* 0x8008FA98 */
    R[2] = (R[16] < R[2]);  /* 0x8008FAA0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008FC30; } }  /* 0x8008FAA4 */
    { R[31] = 0x8008FAB4u; R[4] = R[16] + R[0]; psx_next = 0x80035758u; return; }  /* 0x8008FAAC jal */
    R[4] = R[16] + R[0];  /* 0x8008FAB4 */
    { R[31] = 0x8008FAC0u; R[5] = R[0] + 1; psx_next = 0x80035728u; return; }  /* 0x8008FAB8 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[18]);  /* 0x8008FAC0 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FAC8 */
    R[2] = LO;  /* 0x8008FACC */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = R[17] << 1; if (_c) { goto L_8008FADC; } }  /* 0x8008FAD0 */
    R[2] = R[2] + 4095;  /* 0x8008FAD8 */
L_8008FADC:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008FADC */
    R[2] = R[2] + R[21];  /* 0x8008FAE0 */
    sh_(R[16] + 8, R[2]);  /* 0x8008FAE4 */
    R[2] = R[3] + R[23];  /* 0x8008FAE8 */
    R[2] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x8008FAEC */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FAF4 */
    R[2] = LO;  /* 0x8008FAF8 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008FB08; } }  /* 0x8008FAFC */
    R[2] = R[2] + 4095;  /* 0x8008FB04 */
L_8008FB08:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008FB08 */
    R[2] = R[2] + R[22];  /* 0x8008FB0C */
    sh_(R[16] + 10, R[2]);  /* 0x8008FB10 */
    R[2] = R[17] + 1;  /* 0x8008FB14 */
    R[2] = R[2] & 0x7;  /* 0x8008FB18 */
    R[3] = R[2] << 1;  /* 0x8008FB1C */
    R[8] = 0x800Bu << 16;  /* 0x8008FB20 */
    R[8] = R[8] - 13184;  /* 0x8008FB24 */
    R[2] = R[3] + R[8];  /* 0x8008FB28 */
    R[2] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x8008FB2C */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FB34 */
    R[2] = LO;  /* 0x8008FB38 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008FB48; } }  /* 0x8008FB3C */
    R[2] = R[2] + 4095;  /* 0x8008FB44 */
L_8008FB48:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008FB48 */
    R[2] = R[2] + R[21];  /* 0x8008FB4C */
    sh_(R[16] + 16, R[2]);  /* 0x8008FB50 */
    R[2] = R[3] + R[23];  /* 0x8008FB54 */
    R[2] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x8008FB58 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FB60 */
    R[2] = LO;  /* 0x8008FB64 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008FB74; } }  /* 0x8008FB68 */
    R[2] = R[2] + 4095;  /* 0x8008FB70 */
L_8008FB74:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008FB74 */
    R[2] = R[2] + R[22];  /* 0x8008FB78 */
    sh_(R[16] + 18, R[2]);  /* 0x8008FB7C */
    sh_(R[16] + 24, R[21]);  /* 0x8008FB80 */
    sh_(R[16] + 26, R[22]);  /* 0x8008FB84 */
    R[2] = 0x800Bu << 16;  /* 0x8008FB88 */
    R[8] = lb_(R[29] + 68);  /* 0x8008FB8C */
    R[5] = 0xFF00u << 16;  /* 0x8008FB90 */
    sb_(R[16] + 4, R[8]);  /* 0x8008FB94 */
    R[8] = lb_(R[29] + 80);  /* 0x8008FB98 */
    sb_(R[16] + 12, R[8]);  /* 0x8008FBA0 */
    R[8] = lb_(R[29] + 92);  /* 0x8008FBA4 */
    sb_(R[16] + 20, R[8]);  /* 0x8008FBAC */
    R[8] = lb_(R[29] + 72);  /* 0x8008FBB0 */
    sb_(R[16] + 5, R[8]);  /* 0x8008FBB8 */
    R[8] = lb_(R[29] + 84);  /* 0x8008FBBC */
    sb_(R[16] + 13, R[8]);  /* 0x8008FBC4 */
    R[8] = lb_(R[29] + 96);  /* 0x8008FBC8 */
    sb_(R[16] + 21, R[8]);  /* 0x8008FBD0 */
    R[8] = lb_(R[29] + 76);  /* 0x8008FBD4 */
    sb_(R[16] + 6, R[8]);  /* 0x8008FBDC */
    R[8] = lb_(R[29] + 88);  /* 0x8008FBE0 */
    sb_(R[16] + 14, R[8]);  /* 0x8008FBE8 */
    R[8] = lb_(R[29] + 100);  /* 0x8008FBEC */
    sb_(R[16] + 22, R[8]);  /* 0x8008FBF4 */
    R[4] = lw_(R[2] + 30552);  /* 0x8008FBF8 */
    R[3] = lw_(R[16]);  /* 0x8008FBFC */
    R[2] = lw_(R[4] + 36);  /* 0x8008FC00 */
    R[3] = R[3] & R[5];  /* 0x8008FC04 */
    R[2] = R[2] & R[19];  /* 0x8008FC08 */
    R[3] = R[3] | R[2];  /* 0x8008FC0C */
    sw_(R[16], R[3]);  /* 0x8008FC10 */
    R[3] = R[16] & R[19];  /* 0x8008FC14 */
    R[2] = lw_(R[4] + 36);  /* 0x8008FC18 */
    R[16] = R[16] + 28;  /* 0x8008FC1C */
    sw_(R[30] + -24632, R[16]);  /* 0x8008FC20 */
    R[2] = R[2] & R[5];  /* 0x8008FC24 */
    R[2] = R[2] | R[3];  /* 0x8008FC28 */
    sw_(R[4] + 36, R[2]);  /* 0x8008FC2C */
L_8008FC30:;
    R[17] = R[17] + 1;  /* 0x8008FC30 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8008FC34 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 2; if (_c) { psx_bb(); goto L_8008FA90; } }  /* 0x8008FC38 */
    R[31] = lw_(R[29] + 52);  /* 0x8008FC40 */
    R[30] = lw_(R[29] + 48);  /* 0x8008FC44 */
    R[23] = lw_(R[29] + 44);  /* 0x8008FC48 */
    R[22] = lw_(R[29] + 40);  /* 0x8008FC4C */
    R[21] = lw_(R[29] + 36);  /* 0x8008FC50 */
    psx_next = 0x8008FC54u; return;  /* fallthrough */
}

void ev_8008FAB4(void) {
    R[4] = R[16] + R[0];  /* 0x8008FAB4 */
    { R[31] = 0x8008FAC0u; R[5] = R[0] + 1; psx_next = 0x80035728u; return; }  /* 0x8008FAB8 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[18]);  /* 0x8008FAC0 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FAC8 */
    R[2] = LO;  /* 0x8008FACC */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = R[17] << 1; if (_c) { goto L_8008FADC; } }  /* 0x8008FAD0 */
    R[2] = R[2] + 4095;  /* 0x8008FAD8 */
L_8008FADC:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008FADC */
    R[2] = R[2] + R[21];  /* 0x8008FAE0 */
    sh_(R[16] + 8, R[2]);  /* 0x8008FAE4 */
    R[2] = R[3] + R[23];  /* 0x8008FAE8 */
    R[2] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x8008FAEC */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FAF4 */
    R[2] = LO;  /* 0x8008FAF8 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008FB08; } }  /* 0x8008FAFC */
    R[2] = R[2] + 4095;  /* 0x8008FB04 */
L_8008FB08:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008FB08 */
    R[2] = R[2] + R[22];  /* 0x8008FB0C */
    sh_(R[16] + 10, R[2]);  /* 0x8008FB10 */
    R[2] = R[17] + 1;  /* 0x8008FB14 */
    R[2] = R[2] & 0x7;  /* 0x8008FB18 */
    R[3] = R[2] << 1;  /* 0x8008FB1C */
    R[8] = 0x800Bu << 16;  /* 0x8008FB20 */
    R[8] = R[8] - 13184;  /* 0x8008FB24 */
    R[2] = R[3] + R[8];  /* 0x8008FB28 */
    R[2] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x8008FB2C */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FB34 */
    R[2] = LO;  /* 0x8008FB38 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008FB48; } }  /* 0x8008FB3C */
    R[2] = R[2] + 4095;  /* 0x8008FB44 */
L_8008FB48:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008FB48 */
    R[2] = R[2] + R[21];  /* 0x8008FB4C */
    sh_(R[16] + 16, R[2]);  /* 0x8008FB50 */
    R[2] = R[3] + R[23];  /* 0x8008FB54 */
    R[2] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x8008FB58 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FB60 */
    R[2] = LO;  /* 0x8008FB64 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008FB74; } }  /* 0x8008FB68 */
    R[2] = R[2] + 4095;  /* 0x8008FB70 */
L_8008FB74:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008FB74 */
    R[2] = R[2] + R[22];  /* 0x8008FB78 */
    sh_(R[16] + 18, R[2]);  /* 0x8008FB7C */
    sh_(R[16] + 24, R[21]);  /* 0x8008FB80 */
    sh_(R[16] + 26, R[22]);  /* 0x8008FB84 */
    R[2] = 0x800Bu << 16;  /* 0x8008FB88 */
    R[8] = lb_(R[29] + 68);  /* 0x8008FB8C */
    R[5] = 0xFF00u << 16;  /* 0x8008FB90 */
    sb_(R[16] + 4, R[8]);  /* 0x8008FB94 */
    R[8] = lb_(R[29] + 80);  /* 0x8008FB98 */
    sb_(R[16] + 12, R[8]);  /* 0x8008FBA0 */
    R[8] = lb_(R[29] + 92);  /* 0x8008FBA4 */
    sb_(R[16] + 20, R[8]);  /* 0x8008FBAC */
    R[8] = lb_(R[29] + 72);  /* 0x8008FBB0 */
    sb_(R[16] + 5, R[8]);  /* 0x8008FBB8 */
    R[8] = lb_(R[29] + 84);  /* 0x8008FBBC */
    sb_(R[16] + 13, R[8]);  /* 0x8008FBC4 */
    R[8] = lb_(R[29] + 96);  /* 0x8008FBC8 */
    sb_(R[16] + 21, R[8]);  /* 0x8008FBD0 */
    R[8] = lb_(R[29] + 76);  /* 0x8008FBD4 */
    sb_(R[16] + 6, R[8]);  /* 0x8008FBDC */
    R[8] = lb_(R[29] + 88);  /* 0x8008FBE0 */
    sb_(R[16] + 14, R[8]);  /* 0x8008FBE8 */
    R[8] = lb_(R[29] + 100);  /* 0x8008FBEC */
    sb_(R[16] + 22, R[8]);  /* 0x8008FBF4 */
    R[4] = lw_(R[2] + 30552);  /* 0x8008FBF8 */
    R[3] = lw_(R[16]);  /* 0x8008FBFC */
    R[2] = lw_(R[4] + 36);  /* 0x8008FC00 */
    R[3] = R[3] & R[5];  /* 0x8008FC04 */
    R[2] = R[2] & R[19];  /* 0x8008FC08 */
    R[3] = R[3] | R[2];  /* 0x8008FC0C */
    sw_(R[16], R[3]);  /* 0x8008FC10 */
    R[3] = R[16] & R[19];  /* 0x8008FC14 */
    R[2] = lw_(R[4] + 36);  /* 0x8008FC18 */
    R[16] = R[16] + 28;  /* 0x8008FC1C */
    sw_(R[30] + -24632, R[16]);  /* 0x8008FC20 */
    R[2] = R[2] & R[5];  /* 0x8008FC24 */
    R[2] = R[2] | R[3];  /* 0x8008FC28 */
    sw_(R[4] + 36, R[2]);  /* 0x8008FC2C */
    R[17] = R[17] + 1;  /* 0x8008FC30 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8008FC34 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 2; if (_c) { psx_next = 0x8008FA90u; return; } }  /* 0x8008FC38 b extern */
    R[31] = lw_(R[29] + 52);  /* 0x8008FC40 */
    R[30] = lw_(R[29] + 48);  /* 0x8008FC44 */
    R[23] = lw_(R[29] + 44);  /* 0x8008FC48 */
    R[22] = lw_(R[29] + 40);  /* 0x8008FC4C */
    R[21] = lw_(R[29] + 36);  /* 0x8008FC50 */
    psx_next = 0x8008FC54u; return;  /* fallthrough */
}

void ev_8008FAC0(void) {
    R[2] = (uint32_t)(int16_t)lh_(R[18]);  /* 0x8008FAC0 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FAC8 */
    R[2] = LO;  /* 0x8008FACC */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = R[17] << 1; if (_c) { goto L_8008FADC; } }  /* 0x8008FAD0 */
    R[2] = R[2] + 4095;  /* 0x8008FAD8 */
L_8008FADC:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008FADC */
    R[2] = R[2] + R[21];  /* 0x8008FAE0 */
    sh_(R[16] + 8, R[2]);  /* 0x8008FAE4 */
    R[2] = R[3] + R[23];  /* 0x8008FAE8 */
    R[2] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x8008FAEC */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FAF4 */
    R[2] = LO;  /* 0x8008FAF8 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008FB08; } }  /* 0x8008FAFC */
    R[2] = R[2] + 4095;  /* 0x8008FB04 */
L_8008FB08:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008FB08 */
    R[2] = R[2] + R[22];  /* 0x8008FB0C */
    sh_(R[16] + 10, R[2]);  /* 0x8008FB10 */
    R[2] = R[17] + 1;  /* 0x8008FB14 */
    R[2] = R[2] & 0x7;  /* 0x8008FB18 */
    R[3] = R[2] << 1;  /* 0x8008FB1C */
    R[8] = 0x800Bu << 16;  /* 0x8008FB20 */
    R[8] = R[8] - 13184;  /* 0x8008FB24 */
    R[2] = R[3] + R[8];  /* 0x8008FB28 */
    R[2] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x8008FB2C */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FB34 */
    R[2] = LO;  /* 0x8008FB38 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008FB48; } }  /* 0x8008FB3C */
    R[2] = R[2] + 4095;  /* 0x8008FB44 */
L_8008FB48:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008FB48 */
    R[2] = R[2] + R[21];  /* 0x8008FB4C */
    sh_(R[16] + 16, R[2]);  /* 0x8008FB50 */
    R[2] = R[3] + R[23];  /* 0x8008FB54 */
    R[2] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x8008FB58 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FB60 */
    R[2] = LO;  /* 0x8008FB64 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008FB74; } }  /* 0x8008FB68 */
    R[2] = R[2] + 4095;  /* 0x8008FB70 */
L_8008FB74:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008FB74 */
    R[2] = R[2] + R[22];  /* 0x8008FB78 */
    sh_(R[16] + 18, R[2]);  /* 0x8008FB7C */
    sh_(R[16] + 24, R[21]);  /* 0x8008FB80 */
    sh_(R[16] + 26, R[22]);  /* 0x8008FB84 */
    R[2] = 0x800Bu << 16;  /* 0x8008FB88 */
    R[8] = lb_(R[29] + 68);  /* 0x8008FB8C */
    R[5] = 0xFF00u << 16;  /* 0x8008FB90 */
    sb_(R[16] + 4, R[8]);  /* 0x8008FB94 */
    R[8] = lb_(R[29] + 80);  /* 0x8008FB98 */
    sb_(R[16] + 12, R[8]);  /* 0x8008FBA0 */
    R[8] = lb_(R[29] + 92);  /* 0x8008FBA4 */
    sb_(R[16] + 20, R[8]);  /* 0x8008FBAC */
    R[8] = lb_(R[29] + 72);  /* 0x8008FBB0 */
    sb_(R[16] + 5, R[8]);  /* 0x8008FBB8 */
    R[8] = lb_(R[29] + 84);  /* 0x8008FBBC */
    sb_(R[16] + 13, R[8]);  /* 0x8008FBC4 */
    R[8] = lb_(R[29] + 96);  /* 0x8008FBC8 */
    sb_(R[16] + 21, R[8]);  /* 0x8008FBD0 */
    R[8] = lb_(R[29] + 76);  /* 0x8008FBD4 */
    sb_(R[16] + 6, R[8]);  /* 0x8008FBDC */
    R[8] = lb_(R[29] + 88);  /* 0x8008FBE0 */
    sb_(R[16] + 14, R[8]);  /* 0x8008FBE8 */
    R[8] = lb_(R[29] + 100);  /* 0x8008FBEC */
    sb_(R[16] + 22, R[8]);  /* 0x8008FBF4 */
    R[4] = lw_(R[2] + 30552);  /* 0x8008FBF8 */
    R[3] = lw_(R[16]);  /* 0x8008FBFC */
    R[2] = lw_(R[4] + 36);  /* 0x8008FC00 */
    R[3] = R[3] & R[5];  /* 0x8008FC04 */
    R[2] = R[2] & R[19];  /* 0x8008FC08 */
    R[3] = R[3] | R[2];  /* 0x8008FC0C */
    sw_(R[16], R[3]);  /* 0x8008FC10 */
    R[3] = R[16] & R[19];  /* 0x8008FC14 */
    R[2] = lw_(R[4] + 36);  /* 0x8008FC18 */
    R[16] = R[16] + 28;  /* 0x8008FC1C */
    sw_(R[30] + -24632, R[16]);  /* 0x8008FC20 */
    R[2] = R[2] & R[5];  /* 0x8008FC24 */
    R[2] = R[2] | R[3];  /* 0x8008FC28 */
    sw_(R[4] + 36, R[2]);  /* 0x8008FC2C */
    R[17] = R[17] + 1;  /* 0x8008FC30 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8008FC34 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 2; if (_c) { psx_next = 0x8008FA90u; return; } }  /* 0x8008FC38 b extern */
    R[31] = lw_(R[29] + 52);  /* 0x8008FC40 */
    R[30] = lw_(R[29] + 48);  /* 0x8008FC44 */
    R[23] = lw_(R[29] + 44);  /* 0x8008FC48 */
    R[22] = lw_(R[29] + 40);  /* 0x8008FC4C */
    R[21] = lw_(R[29] + 36);  /* 0x8008FC50 */
    psx_next = 0x8008FC54u; return;  /* fallthrough */
}

void ev_8008FC54(void) {
    R[20] = lw_(R[29] + 32);  /* 0x8008FC54 */
    R[19] = lw_(R[29] + 28);  /* 0x8008FC58 */
    R[18] = lw_(R[29] + 24);  /* 0x8008FC5C */
    R[17] = lw_(R[29] + 20);  /* 0x8008FC60 */
    R[16] = lw_(R[29] + 16);  /* 0x8008FC64 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x8008FC68 jr ra */
}

void ev_8008FC70(void) {
    R[29] = R[29] - 56;  /* 0x8008FC70 */
    sw_(R[29] + 48, R[20]);  /* 0x8008FC74 */
    R[20] = R[4] + R[0];  /* 0x8008FC78 */
    sw_(R[29] + 40, R[18]);  /* 0x8008FC7C */
    R[18] = R[0] + R[0];  /* 0x8008FC80 */
    R[2] = 0x800Bu << 16;  /* 0x8008FC84 */
    sw_(R[29] + 44, R[19]);  /* 0x8008FC88 */
    R[19] = R[2] - 13128;  /* 0x8008FC8C */
    sw_(R[29] + 52, R[31]);  /* 0x8008FC90 */
    sw_(R[29] + 36, R[17]);  /* 0x8008FC94 */
    sw_(R[29] + 32, R[16]);  /* 0x8008FC98 */
    R[2] = R[0] + 4096;  /* 0x8008FC9C */
L_8008FCA0:;
    sw_(R[29] + 20, R[0]);  /* 0x8008FCA0 */
    sw_(R[29] + 24, R[0]);  /* 0x8008FCA4 */
    sw_(R[29] + 16, R[2]);  /* 0x8008FCA8 */
    R[4] = lw_(R[19]);  /* 0x8008FCAC */
    R[19] = R[19] + 4;  /* 0x8008FCB0 */
    R[3] = R[18] << 8;  /* 0x8008FCB4 */
    R[2] = (uint32_t)(int16_t)lh_(R[20] + 1708);  /* 0x8008FCB8 */
    R[18] = R[18] + 1;  /* 0x8008FCBC */
    R[16] = R[2] << 2;  /* 0x8008FCC0 */
    R[16] = R[16] + R[2];  /* 0x8008FCC4 */
    R[16] = R[16] << 1;  /* 0x8008FCC8 */
    { R[31] = 0x8008FCD4u; R[16] = R[16] + R[3]; psx_next = 0x80085FD0u; return; }  /* 0x8008FCCC jal */
    R[17] = R[2] + 20;  /* 0x8008FCD4 */
    R[1] = 0x8001u << 16;  /* 0x8008FCD8 */
    R[1] = R[1] | 0x8;  /* 0x8008FCDC */
    { uint32_t _t = R[1]; R[31] = 0x8008FCE8u; R[4] = R[17] + R[0]; psx_next = _t; return; }  /* 0x8008FCE0 jalr */
    R[4] = R[17] + R[0];  /* 0x8008FCE8 */
    R[5] = R[29] + 16;  /* 0x8008FCEC */
    { R[31] = 0x8008FCF8u; R[6] = R[16] + R[0]; psx_next = 0x80027BD4u; return; }  /* 0x8008FCF0 jal */
    R[2] = ((int32_t)R[18] < 7);  /* 0x8008FCF8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 4096; if (_c) { psx_bb(); goto L_8008FCA0; } }  /* 0x8008FCFC */
    R[2] = lh_(R[20] + 1708);  /* 0x8008FD04 */
    R[2] = R[2] + 1;  /* 0x8008FD0C */
    sh_(R[20] + 1708, R[2]);  /* 0x8008FD10 */
    R[31] = lw_(R[29] + 52);  /* 0x8008FD14 */
    R[20] = lw_(R[29] + 48);  /* 0x8008FD18 */
    R[19] = lw_(R[29] + 44);  /* 0x8008FD1C */
    R[18] = lw_(R[29] + 40);  /* 0x8008FD20 */
    R[17] = lw_(R[29] + 36);  /* 0x8008FD24 */
    R[16] = lw_(R[29] + 32);  /* 0x8008FD28 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x8008FD2C jr ra */
}

void ev_8008FCA0(void) {
L_8008FCA0:;
    sw_(R[29] + 20, R[0]);  /* 0x8008FCA0 */
    sw_(R[29] + 24, R[0]);  /* 0x8008FCA4 */
    sw_(R[29] + 16, R[2]);  /* 0x8008FCA8 */
    R[4] = lw_(R[19]);  /* 0x8008FCAC */
    R[19] = R[19] + 4;  /* 0x8008FCB0 */
    R[3] = R[18] << 8;  /* 0x8008FCB4 */
    R[2] = (uint32_t)(int16_t)lh_(R[20] + 1708);  /* 0x8008FCB8 */
    R[18] = R[18] + 1;  /* 0x8008FCBC */
    R[16] = R[2] << 2;  /* 0x8008FCC0 */
    R[16] = R[16] + R[2];  /* 0x8008FCC4 */
    R[16] = R[16] << 1;  /* 0x8008FCC8 */
    { R[31] = 0x8008FCD4u; R[16] = R[16] + R[3]; psx_next = 0x80085FD0u; return; }  /* 0x8008FCCC jal */
    R[17] = R[2] + 20;  /* 0x8008FCD4 */
    R[1] = 0x8001u << 16;  /* 0x8008FCD8 */
    R[1] = R[1] | 0x8;  /* 0x8008FCDC */
    { uint32_t _t = R[1]; R[31] = 0x8008FCE8u; R[4] = R[17] + R[0]; psx_next = _t; return; }  /* 0x8008FCE0 jalr */
    R[4] = R[17] + R[0];  /* 0x8008FCE8 */
    R[5] = R[29] + 16;  /* 0x8008FCEC */
    { R[31] = 0x8008FCF8u; R[6] = R[16] + R[0]; psx_next = 0x80027BD4u; return; }  /* 0x8008FCF0 jal */
    R[2] = ((int32_t)R[18] < 7);  /* 0x8008FCF8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 4096; if (_c) { psx_bb(); goto L_8008FCA0; } }  /* 0x8008FCFC */
    R[2] = lh_(R[20] + 1708);  /* 0x8008FD04 */
    R[2] = R[2] + 1;  /* 0x8008FD0C */
    sh_(R[20] + 1708, R[2]);  /* 0x8008FD10 */
    R[31] = lw_(R[29] + 52);  /* 0x8008FD14 */
    R[20] = lw_(R[29] + 48);  /* 0x8008FD18 */
    R[19] = lw_(R[29] + 44);  /* 0x8008FD1C */
    R[18] = lw_(R[29] + 40);  /* 0x8008FD20 */
    R[17] = lw_(R[29] + 36);  /* 0x8008FD24 */
    R[16] = lw_(R[29] + 32);  /* 0x8008FD28 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x8008FD2C jr ra */
}

void ev_8008FCD4(void) {
    R[17] = R[2] + 20;  /* 0x8008FCD4 */
    R[1] = 0x8001u << 16;  /* 0x8008FCD8 */
    R[1] = R[1] | 0x8;  /* 0x8008FCDC */
    { uint32_t _t = R[1]; R[31] = 0x8008FCE8u; R[4] = R[17] + R[0]; psx_next = _t; return; }  /* 0x8008FCE0 jalr */
    R[4] = R[17] + R[0];  /* 0x8008FCE8 */
    R[5] = R[29] + 16;  /* 0x8008FCEC */
    { R[31] = 0x8008FCF8u; R[6] = R[16] + R[0]; psx_next = 0x80027BD4u; return; }  /* 0x8008FCF0 jal */
    R[2] = ((int32_t)R[18] < 7);  /* 0x8008FCF8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 4096; if (_c) { psx_next = 0x8008FCA0u; return; } }  /* 0x8008FCFC b extern */
    R[2] = lh_(R[20] + 1708);  /* 0x8008FD04 */
    R[2] = R[2] + 1;  /* 0x8008FD0C */
    sh_(R[20] + 1708, R[2]);  /* 0x8008FD10 */
    R[31] = lw_(R[29] + 52);  /* 0x8008FD14 */
    R[20] = lw_(R[29] + 48);  /* 0x8008FD18 */
    R[19] = lw_(R[29] + 44);  /* 0x8008FD1C */
    R[18] = lw_(R[29] + 40);  /* 0x8008FD20 */
    R[17] = lw_(R[29] + 36);  /* 0x8008FD24 */
    R[16] = lw_(R[29] + 32);  /* 0x8008FD28 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x8008FD2C jr ra */
}

void ev_8008FCE8(void) {
    R[4] = R[17] + R[0];  /* 0x8008FCE8 */
    R[5] = R[29] + 16;  /* 0x8008FCEC */
    { R[31] = 0x8008FCF8u; R[6] = R[16] + R[0]; psx_next = 0x80027BD4u; return; }  /* 0x8008FCF0 jal */
    R[2] = ((int32_t)R[18] < 7);  /* 0x8008FCF8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 4096; if (_c) { psx_next = 0x8008FCA0u; return; } }  /* 0x8008FCFC b extern */
    R[2] = lh_(R[20] + 1708);  /* 0x8008FD04 */
    R[2] = R[2] + 1;  /* 0x8008FD0C */
    sh_(R[20] + 1708, R[2]);  /* 0x8008FD10 */
    R[31] = lw_(R[29] + 52);  /* 0x8008FD14 */
    R[20] = lw_(R[29] + 48);  /* 0x8008FD18 */
    R[19] = lw_(R[29] + 44);  /* 0x8008FD1C */
    R[18] = lw_(R[29] + 40);  /* 0x8008FD20 */
    R[17] = lw_(R[29] + 36);  /* 0x8008FD24 */
    R[16] = lw_(R[29] + 32);  /* 0x8008FD28 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x8008FD2C jr ra */
}

void ev_8008FCF8(void) {
    R[2] = ((int32_t)R[18] < 7);  /* 0x8008FCF8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 4096; if (_c) { psx_next = 0x8008FCA0u; return; } }  /* 0x8008FCFC b extern */
    R[2] = lh_(R[20] + 1708);  /* 0x8008FD04 */
    R[2] = R[2] + 1;  /* 0x8008FD0C */
    sh_(R[20] + 1708, R[2]);  /* 0x8008FD10 */
    R[31] = lw_(R[29] + 52);  /* 0x8008FD14 */
    R[20] = lw_(R[29] + 48);  /* 0x8008FD18 */
    R[19] = lw_(R[29] + 44);  /* 0x8008FD1C */
    R[18] = lw_(R[29] + 40);  /* 0x8008FD20 */
    R[17] = lw_(R[29] + 36);  /* 0x8008FD24 */
    R[16] = lw_(R[29] + 32);  /* 0x8008FD28 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x8008FD2C jr ra */
}

void ev_8008FD34(void) {
    R[29] = R[29] - 176;  /* 0x8008FD34 */
    sw_(R[29] + 164, R[21]);  /* 0x8008FD38 */
    R[21] = R[4] + R[0];  /* 0x8008FD3C */
    sw_(R[29] + 172, R[31]);  /* 0x8008FD40 */
    sw_(R[29] + 168, R[22]);  /* 0x8008FD44 */
    sw_(R[29] + 160, R[20]);  /* 0x8008FD48 */
    sw_(R[29] + 156, R[19]);  /* 0x8008FD4C */
    sw_(R[29] + 152, R[18]);  /* 0x8008FD50 */
    sw_(R[29] + 148, R[17]);  /* 0x8008FD54 */
    sw_(R[29] + 144, R[16]);  /* 0x8008FD58 */
    R[2] = lw_(R[21] + 1032);  /* 0x8008FD5C */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 2);  /* 0x8008FD64 */
    R[2] = R[2] << 12;  /* 0x8008FD6C */
    sw_(R[29] + 64, R[2]);  /* 0x8008FD70 */
    R[2] = lw_(R[21] + 1032);  /* 0x8008FD74 */
    R[8] = R[0] + 2;  /* 0x8008FD78 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x8008FD7C */
    R[7] = R[29] + 56;  /* 0x8008FD80 */
    R[2] = R[2] << 12;  /* 0x8008FD84 */
    sw_(R[29] + 68, R[2]);  /* 0x8008FD88 */
    R[2] = 0x800Du << 16;  /* 0x8008FD8C */
    R[2] = R[2] + 30448;  /* 0x8008FD90 */
    R[3] = lw_(R[21] + 1032);  /* 0x8008FD94 */
    R[4] = lw_(R[2] + 44);  /* 0x8008FD98 */
    R[5] = lw_(R[2] + 48);  /* 0x8008FD9C */
    R[2] = lw_(R[2] + 52);  /* 0x8008FDA0 */
    R[3] = (uint32_t)(int16_t)lh_(R[3] + 6);  /* 0x8008FDA4 */
    R[6] = R[29] + 88;  /* 0x8008FDA8 */
    sw_(R[29] + 76, R[4]);  /* 0x8008FDAC */
    sw_(R[29] + 80, R[5]);  /* 0x8008FDB0 */
    sw_(R[29] + 84, R[2]);  /* 0x8008FDB4 */
    R[3] = R[3] << 12;  /* 0x8008FDB8 */
    sw_(R[29] + 72, R[3]);  /* 0x8008FDBC */
L_8008FDC0:;
    sw_(R[7], R[6]);  /* 0x8008FDC0 */
    R[7] = R[7] - 4;  /* 0x8008FDC4 */
    R[8] = R[8] - 1;  /* 0x8008FDC8 */
    { uint32_t _c = ((int32_t)R[8] >= 0); R[6] = R[6] - 12; if (_c) { psx_bb(); goto L_8008FDC0; } }  /* 0x8008FDCC */
    R[4] = 0x800Du << 16;  /* 0x8008FDD4 */
    R[4] = R[4] + 30448;  /* 0x8008FDD8 */
    R[5] = R[0] + 1;  /* 0x8008FDDC */
    R[6] = R[0] + R[0];  /* 0x8008FDE0 */
    R[2] = R[29] + 48;  /* 0x8008FDE4 */
    sw_(R[4] + 16, R[2]);  /* 0x8008FDE8 */
    R[2] = R[29] + 120;  /* 0x8008FDEC */
    { R[31] = 0x8008FDF8u; sw_(R[4] + 20, R[2]); psx_next = 0x80025598u; return; }  /* 0x8008FDF0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[29] + 128);  /* 0x8008FDF8 */
    R[3] = (uint32_t)(int16_t)lh_(R[29] + 120);  /* 0x8008FDFC */
    R[2] = R[2] - R[3];  /* 0x8008FE04 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FE08 */
    R[2] = (uint32_t)(int16_t)lh_(R[29] + 130);  /* 0x8008FE0C */
    R[3] = (uint32_t)(int16_t)lh_(R[29] + 122);  /* 0x8008FE10 */
    R[4] = LO;  /* 0x8008FE14 */
    R[2] = R[2] - R[3];  /* 0x8008FE18 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FE20 */
    R[2] = R[0] | 0xC34F;  /* 0x8008FE24 */
    R[3] = LO;  /* 0x8008FE28 */
    R[19] = R[4] + R[3];  /* 0x8008FE2C */
    R[2] = ((int32_t)R[2] < (int32_t)R[19]);  /* 0x8008FE30 */
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[19] < 30000); if (_c) { psx_next = 0x80090030u; return; } }  /* 0x8008FE34 b extern */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[0] + 255; if (_c) { goto L_8008FE70; } }  /* 0x8008FE3C */
    R[4] = 0x68DBu << 16;  /* 0x8008FE44 */
    R[4] = R[4] | 0x8BAD;  /* 0x8008FE48 */
    R[2] = R[0] | 0xC350;  /* 0x8008FE4C */
    R[2] = R[2] - R[19];  /* 0x8008FE50 */
    R[3] = R[2] << 8;  /* 0x8008FE54 */
    R[3] = R[3] - R[2];  /* 0x8008FE58 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FE5C */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x8008FE60 */
    R[10] = HI;  /* 0x8008FE64 */
    R[2] = (uint32_t)((int32_t)R[10] >> 13);  /* 0x8008FE68 */
    R[18] = R[2] - R[3];  /* 0x8008FE6C */
L_8008FE70:;
    R[16] = R[0] + R[0];  /* 0x8008FE70 */
    R[20] = 0x6666u << 16;  /* 0x8008FE74 */
    R[20] = R[20] | 0x6667;  /* 0x8008FE78 */
    R[2] = 0x800Bu << 16;  /* 0x8008FE7C */
    R[22] = R[2] - 13152;  /* 0x8008FE80 */
    R[4] = R[29] + 104;  /* 0x8008FE84 */
    R[2] = (uint32_t)(int16_t)lh_(R[29] + 128);  /* 0x8008FE88 */
    R[6] = (uint32_t)(int16_t)lh_(R[29] + 120);  /* 0x8008FE8C */
    R[3] = (uint32_t)(int16_t)lh_(R[29] + 130);  /* 0x8008FE90 */
    R[7] = (uint32_t)(int16_t)lh_(R[29] + 122);  /* 0x8008FE94 */
    R[5] = R[4] + R[0];  /* 0x8008FE98 */
    sw_(R[29] + 112, R[0]);  /* 0x8008FE9C */
    R[2] = R[2] - R[6];  /* 0x8008FEA0 */
    R[3] = R[3] - R[7];  /* 0x8008FEA4 */
    sw_(R[29] + 104, R[2]);  /* 0x8008FEA8 */
    psx_next = 0x8008FEACu; return;  /* fallthrough */
}

void ev_8008FDF8(void) {
    R[2] = (uint32_t)(int16_t)lh_(R[29] + 128);  /* 0x8008FDF8 */
    R[3] = (uint32_t)(int16_t)lh_(R[29] + 120);  /* 0x8008FDFC */
    R[2] = R[2] - R[3];  /* 0x8008FE04 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FE08 */
    R[2] = (uint32_t)(int16_t)lh_(R[29] + 130);  /* 0x8008FE0C */
    R[3] = (uint32_t)(int16_t)lh_(R[29] + 122);  /* 0x8008FE10 */
    R[4] = LO;  /* 0x8008FE14 */
    R[2] = R[2] - R[3];  /* 0x8008FE18 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FE20 */
    R[2] = R[0] | 0xC34F;  /* 0x8008FE24 */
    R[3] = LO;  /* 0x8008FE28 */
    R[19] = R[4] + R[3];  /* 0x8008FE2C */
    R[2] = ((int32_t)R[2] < (int32_t)R[19]);  /* 0x8008FE30 */
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[19] < 30000); if (_c) { psx_next = 0x80090030u; return; } }  /* 0x8008FE34 b extern */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[0] + 255; if (_c) { goto L_8008FE70; } }  /* 0x8008FE3C */
    R[4] = 0x68DBu << 16;  /* 0x8008FE44 */
    R[4] = R[4] | 0x8BAD;  /* 0x8008FE48 */
    R[2] = R[0] | 0xC350;  /* 0x8008FE4C */
    R[2] = R[2] - R[19];  /* 0x8008FE50 */
    R[3] = R[2] << 8;  /* 0x8008FE54 */
    R[3] = R[3] - R[2];  /* 0x8008FE58 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FE5C */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x8008FE60 */
    R[10] = HI;  /* 0x8008FE64 */
    R[2] = (uint32_t)((int32_t)R[10] >> 13);  /* 0x8008FE68 */
    R[18] = R[2] - R[3];  /* 0x8008FE6C */
L_8008FE70:;
    R[16] = R[0] + R[0];  /* 0x8008FE70 */
    R[20] = 0x6666u << 16;  /* 0x8008FE74 */
    R[20] = R[20] | 0x6667;  /* 0x8008FE78 */
    R[2] = 0x800Bu << 16;  /* 0x8008FE7C */
    R[22] = R[2] - 13152;  /* 0x8008FE80 */
    R[4] = R[29] + 104;  /* 0x8008FE84 */
    R[2] = (uint32_t)(int16_t)lh_(R[29] + 128);  /* 0x8008FE88 */
    R[6] = (uint32_t)(int16_t)lh_(R[29] + 120);  /* 0x8008FE8C */
    R[3] = (uint32_t)(int16_t)lh_(R[29] + 130);  /* 0x8008FE90 */
    R[7] = (uint32_t)(int16_t)lh_(R[29] + 122);  /* 0x8008FE94 */
    R[5] = R[4] + R[0];  /* 0x8008FE98 */
    sw_(R[29] + 112, R[0]);  /* 0x8008FE9C */
    R[2] = R[2] - R[6];  /* 0x8008FEA0 */
    R[3] = R[3] - R[7];  /* 0x8008FEA4 */
    sw_(R[29] + 104, R[2]);  /* 0x8008FEA8 */
    psx_next = 0x8008FEACu; return;  /* fallthrough */
}

void ev_8008FE88(void) {
    R[2] = (uint32_t)(int16_t)lh_(R[29] + 128);  /* 0x8008FE88 */
    R[6] = (uint32_t)(int16_t)lh_(R[29] + 120);  /* 0x8008FE8C */
    R[3] = (uint32_t)(int16_t)lh_(R[29] + 130);  /* 0x8008FE90 */
    R[7] = (uint32_t)(int16_t)lh_(R[29] + 122);  /* 0x8008FE94 */
    R[5] = R[4] + R[0];  /* 0x8008FE98 */
    sw_(R[29] + 112, R[0]);  /* 0x8008FE9C */
    R[2] = R[2] - R[6];  /* 0x8008FEA0 */
    R[3] = R[3] - R[7];  /* 0x8008FEA4 */
    sw_(R[29] + 104, R[2]);  /* 0x8008FEA8 */
    psx_next = 0x8008FEACu; return;  /* fallthrough */
}

void ev_8008FEAC(void) {
    { R[31] = 0x8008FEB4u; sw_(R[29] + 108, R[3]); psx_next = 0x800270ACu; return; }  /* 0x8008FEAC jal */
    R[17] = R[16] + 1;  /* 0x8008FEB4 */
    R[2] = R[17] << 2;  /* 0x8008FEB8 */
    R[2] = R[2] + R[17];  /* 0x8008FEBC */
    R[3] = lw_(R[29] + 104);  /* 0x8008FEC0 */
    R[5] = R[2] << 2;  /* 0x8008FEC4 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[5]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FEC8 */
    R[6] = (uint32_t)(int16_t)lh_(R[29] + 120);  /* 0x8008FECC */
    R[4] = LO;  /* 0x8008FED0 */
    { uint32_t _c = ((int32_t)R[4] >= 0); if (_c) { goto L_8008FEE0; } }  /* 0x8008FED4 */
    R[4] = R[4] + 4095;  /* 0x8008FEDC */
L_8008FEE0:;
    R[2] = (uint32_t)(int16_t)lh_(R[29] + 128);  /* 0x8008FEE0 */
    R[2] = R[2] - R[6];  /* 0x8008FEE8 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FEEC */
    R[2] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x8008FEF0 */
    R[3] = HI;  /* 0x8008FEF4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 3);  /* 0x8008FEF8 */
    R[3] = R[3] - R[2];  /* 0x8008FEFC */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FF00 */
    R[3] = LO;  /* 0x8008FF04 */
    R[2] = lw_(R[29] + 108);  /* 0x8008FF08 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[5]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FF10 */
    R[2] = (uint32_t)((int32_t)R[4] >> 12);  /* 0x8008FF14 */
    R[2] = R[6] + R[2];  /* 0x8008FF18 */
    R[6] = (uint32_t)(int16_t)lh_(R[29] + 122);  /* 0x8008FF1C */
    R[5] = LO;  /* 0x8008FF20 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[4] = R[2] + R[3]; if (_c) { goto L_8008FF30; } }  /* 0x8008FF24 */
    R[5] = R[5] + 4095;  /* 0x8008FF2C */
L_8008FF30:;
    R[2] = (uint32_t)(int16_t)lh_(R[29] + 130);  /* 0x8008FF30 */
    R[2] = R[2] - R[6];  /* 0x8008FF38 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FF3C */
    R[2] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x8008FF40 */
    R[3] = HI;  /* 0x8008FF44 */
    R[3] = (uint32_t)((int32_t)R[3] >> 3);  /* 0x8008FF48 */
    R[3] = R[3] - R[2];  /* 0x8008FF4C */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FF50 */
    R[2] = 0x800Bu << 16;  /* 0x8008FF54 */
    R[2] = R[2] - 13136;  /* 0x8008FF58 */
    R[2] = R[16] + R[2];  /* 0x8008FF5C */
    R[8] = lb_(R[2]);  /* 0x8008FF60 */
    R[9] = lw_(R[21] + 564);  /* 0x8008FF64 */
    R[2] = R[8] << 1;  /* 0x8008FF68 */
    R[2] = R[9] + R[2];  /* 0x8008FF6C */
    R[3] = LO;  /* 0x8008FF70 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 32);  /* 0x8008FF74 */
    { int64_t _p = (int64_t)(int32_t)R[18] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FF7C */
    R[2] = (uint32_t)((int32_t)R[5] >> 12);  /* 0x8008FF80 */
    R[2] = R[6] + R[2];  /* 0x8008FF84 */
    R[7] = LO;  /* 0x8008FF88 */
    { uint32_t _c = ((int32_t)R[7] >= 0); R[5] = R[2] + R[3]; if (_c) { goto L_8008FF98; } }  /* 0x8008FF8C */
    R[7] = R[7] + 4095;  /* 0x8008FF94 */
L_8008FF98:;
    R[2] = R[8] + 3;  /* 0x8008FF98 */
    R[2] = R[2] << 1;  /* 0x8008FF9C */
    R[2] = R[9] + R[2];  /* 0x8008FFA0 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 32);  /* 0x8008FFA4 */
    { int64_t _p = (int64_t)(int32_t)R[18] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FFAC */
    R[6] = LO;  /* 0x8008FFB0 */
    { uint32_t _c = ((int32_t)R[6] >= 0); R[7] = (uint32_t)((int32_t)R[7] >> 12); if (_c) { goto L_8008FFC0; } }  /* 0x8008FFB4 */
    R[6] = R[6] + 4095;  /* 0x8008FFBC */
L_8008FFC0:;
    R[2] = R[8] + 6;  /* 0x8008FFC0 */
    R[2] = R[2] << 1;  /* 0x8008FFC4 */
    R[2] = R[9] + R[2];  /* 0x8008FFC8 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 32);  /* 0x8008FFCC */
    { int64_t _p = (int64_t)(int32_t)R[18] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FFD4 */
    R[8] = LO;  /* 0x8008FFD8 */
    { uint32_t _c = ((int32_t)R[8] >= 0); R[9] = (uint32_t)((int32_t)R[6] >> 12); if (_c) { goto L_8008FFE8; } }  /* 0x8008FFDC */
    R[8] = R[8] + 4095;  /* 0x8008FFE4 */
L_8008FFE8:;
    R[2] = R[16] << 1;  /* 0x8008FFE8 */
    R[2] = R[2] + R[22];  /* 0x8008FFEC */
    R[16] = R[17] + R[0];  /* 0x8008FFF0 */
    R[6] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x8008FFF4 */
    R[2] = (uint32_t)((int32_t)R[8] >> 12);  /* 0x8008FFF8 */
    sw_(R[29] + 16, R[9]);  /* 0x8008FFFC */
    sw_(R[29] + 20, R[2]);  /* 0x80090000 */
    sw_(R[29] + 24, R[7]);  /* 0x80090004 */
    sw_(R[29] + 28, R[9]);  /* 0x80090008 */
    sw_(R[29] + 32, R[2]);  /* 0x8009000C */
    sw_(R[29] + 36, R[7]);  /* 0x80090010 */
    sw_(R[29] + 40, R[9]);  /* 0x80090014 */
    { R[31] = 0x80090020u; sw_(R[29] + 44, R[2]); psx_next = 0x8008FA34u; return; }  /* 0x80090018 jal */
    R[2] = ((int32_t)R[16] < 5);  /* 0x80090020 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[29] + 104; if (_c) { psx_next = 0x8008FE88u; return; } }  /* 0x80090024 b extern */
    R[2] = ((int32_t)R[19] < 30000);  /* 0x8009002C */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x45E7u << 16; if (_c) { psx_next = 0x800900A0u; return; } }  /* 0x80090030 b extern */
    R[3] = R[3] | 0xB273;  /* 0x80090038 */
    R[2] = R[0] + 30000;  /* 0x8009003C */
    R[2] = R[2] - R[19];  /* 0x80090040 */
    R[2] = R[2] << 7;  /* 0x80090044 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x80090048 */
    R[2] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x8009004C */
    R[10] = HI;  /* 0x80090050 */
    R[3] = (uint32_t)((int32_t)R[10] >> 13);  /* 0x80090054 */
    R[5] = R[3] - R[2];  /* 0x80090058 */
    R[2] = ((int32_t)R[19] < 10000);  /* 0x8009005C */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x68DBu << 16; if (_c) { goto L_80090094; } }  /* 0x80090060 */
    R[4] = R[4] | 0x8BAD;  /* 0x80090068 */
    R[2] = R[0] + 10000;  /* 0x8009006C */
    R[2] = R[2] - R[19];  /* 0x80090070 */
    R[3] = R[2] << 7;  /* 0x80090074 */
    R[3] = R[3] - R[2];  /* 0x80090078 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009007C */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x80090080 */
    R[10] = HI;  /* 0x80090084 */
    R[2] = (uint32_t)((int32_t)R[10] >> 12);  /* 0x80090088 */
    R[2] = R[2] - R[3];  /* 0x8009008C */
    R[5] = R[5] + R[2];  /* 0x80090090 */
L_80090094:;
    R[4] = R[5] + R[0];  /* 0x80090094 */
    { R[31] = 0x800900A0u; R[6] = R[4] + R[0]; psx_next = 0x8008F39Cu; return; }  /* 0x80090098 jal */
}

void ev_8008FEB4(void) {
    R[17] = R[16] + 1;  /* 0x8008FEB4 */
    R[2] = R[17] << 2;  /* 0x8008FEB8 */
    R[2] = R[2] + R[17];  /* 0x8008FEBC */
    R[3] = lw_(R[29] + 104);  /* 0x8008FEC0 */
    R[5] = R[2] << 2;  /* 0x8008FEC4 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[5]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FEC8 */
    R[6] = (uint32_t)(int16_t)lh_(R[29] + 120);  /* 0x8008FECC */
    R[4] = LO;  /* 0x8008FED0 */
    { uint32_t _c = ((int32_t)R[4] >= 0); if (_c) { goto L_8008FEE0; } }  /* 0x8008FED4 */
    R[4] = R[4] + 4095;  /* 0x8008FEDC */
L_8008FEE0:;
    R[2] = (uint32_t)(int16_t)lh_(R[29] + 128);  /* 0x8008FEE0 */
    R[2] = R[2] - R[6];  /* 0x8008FEE8 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FEEC */
    R[2] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x8008FEF0 */
    R[3] = HI;  /* 0x8008FEF4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 3);  /* 0x8008FEF8 */
    R[3] = R[3] - R[2];  /* 0x8008FEFC */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FF00 */
    R[3] = LO;  /* 0x8008FF04 */
    R[2] = lw_(R[29] + 108);  /* 0x8008FF08 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[5]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FF10 */
    R[2] = (uint32_t)((int32_t)R[4] >> 12);  /* 0x8008FF14 */
    R[2] = R[6] + R[2];  /* 0x8008FF18 */
    R[6] = (uint32_t)(int16_t)lh_(R[29] + 122);  /* 0x8008FF1C */
    R[5] = LO;  /* 0x8008FF20 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[4] = R[2] + R[3]; if (_c) { goto L_8008FF30; } }  /* 0x8008FF24 */
    R[5] = R[5] + 4095;  /* 0x8008FF2C */
L_8008FF30:;
    R[2] = (uint32_t)(int16_t)lh_(R[29] + 130);  /* 0x8008FF30 */
    R[2] = R[2] - R[6];  /* 0x8008FF38 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FF3C */
    R[2] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x8008FF40 */
    R[3] = HI;  /* 0x8008FF44 */
    R[3] = (uint32_t)((int32_t)R[3] >> 3);  /* 0x8008FF48 */
    R[3] = R[3] - R[2];  /* 0x8008FF4C */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FF50 */
    R[2] = 0x800Bu << 16;  /* 0x8008FF54 */
    R[2] = R[2] - 13136;  /* 0x8008FF58 */
    R[2] = R[16] + R[2];  /* 0x8008FF5C */
    R[8] = lb_(R[2]);  /* 0x8008FF60 */
    R[9] = lw_(R[21] + 564);  /* 0x8008FF64 */
    R[2] = R[8] << 1;  /* 0x8008FF68 */
    R[2] = R[9] + R[2];  /* 0x8008FF6C */
    R[3] = LO;  /* 0x8008FF70 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 32);  /* 0x8008FF74 */
    { int64_t _p = (int64_t)(int32_t)R[18] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FF7C */
    R[2] = (uint32_t)((int32_t)R[5] >> 12);  /* 0x8008FF80 */
    R[2] = R[6] + R[2];  /* 0x8008FF84 */
    R[7] = LO;  /* 0x8008FF88 */
    { uint32_t _c = ((int32_t)R[7] >= 0); R[5] = R[2] + R[3]; if (_c) { goto L_8008FF98; } }  /* 0x8008FF8C */
    R[7] = R[7] + 4095;  /* 0x8008FF94 */
L_8008FF98:;
    R[2] = R[8] + 3;  /* 0x8008FF98 */
    R[2] = R[2] << 1;  /* 0x8008FF9C */
    R[2] = R[9] + R[2];  /* 0x8008FFA0 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 32);  /* 0x8008FFA4 */
    { int64_t _p = (int64_t)(int32_t)R[18] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FFAC */
    R[6] = LO;  /* 0x8008FFB0 */
    { uint32_t _c = ((int32_t)R[6] >= 0); R[7] = (uint32_t)((int32_t)R[7] >> 12); if (_c) { goto L_8008FFC0; } }  /* 0x8008FFB4 */
    R[6] = R[6] + 4095;  /* 0x8008FFBC */
L_8008FFC0:;
    R[2] = R[8] + 6;  /* 0x8008FFC0 */
    R[2] = R[2] << 1;  /* 0x8008FFC4 */
    R[2] = R[9] + R[2];  /* 0x8008FFC8 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 32);  /* 0x8008FFCC */
    { int64_t _p = (int64_t)(int32_t)R[18] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8008FFD4 */
    R[8] = LO;  /* 0x8008FFD8 */
    { uint32_t _c = ((int32_t)R[8] >= 0); R[9] = (uint32_t)((int32_t)R[6] >> 12); if (_c) { goto L_8008FFE8; } }  /* 0x8008FFDC */
    R[8] = R[8] + 4095;  /* 0x8008FFE4 */
L_8008FFE8:;
    R[2] = R[16] << 1;  /* 0x8008FFE8 */
    R[2] = R[2] + R[22];  /* 0x8008FFEC */
    R[16] = R[17] + R[0];  /* 0x8008FFF0 */
    R[6] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x8008FFF4 */
    R[2] = (uint32_t)((int32_t)R[8] >> 12);  /* 0x8008FFF8 */
    sw_(R[29] + 16, R[9]);  /* 0x8008FFFC */
    sw_(R[29] + 20, R[2]);  /* 0x80090000 */
    sw_(R[29] + 24, R[7]);  /* 0x80090004 */
    sw_(R[29] + 28, R[9]);  /* 0x80090008 */
    sw_(R[29] + 32, R[2]);  /* 0x8009000C */
    sw_(R[29] + 36, R[7]);  /* 0x80090010 */
    sw_(R[29] + 40, R[9]);  /* 0x80090014 */
    { R[31] = 0x80090020u; sw_(R[29] + 44, R[2]); psx_next = 0x8008FA34u; return; }  /* 0x80090018 jal */
    R[2] = ((int32_t)R[16] < 5);  /* 0x80090020 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[29] + 104; if (_c) { psx_next = 0x8008FE88u; return; } }  /* 0x80090024 b extern */
    R[2] = ((int32_t)R[19] < 30000);  /* 0x8009002C */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x45E7u << 16; if (_c) { psx_next = 0x800900A0u; return; } }  /* 0x80090030 b extern */
    R[3] = R[3] | 0xB273;  /* 0x80090038 */
    R[2] = R[0] + 30000;  /* 0x8009003C */
    R[2] = R[2] - R[19];  /* 0x80090040 */
    R[2] = R[2] << 7;  /* 0x80090044 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x80090048 */
    R[2] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x8009004C */
    R[10] = HI;  /* 0x80090050 */
    R[3] = (uint32_t)((int32_t)R[10] >> 13);  /* 0x80090054 */
    R[5] = R[3] - R[2];  /* 0x80090058 */
    R[2] = ((int32_t)R[19] < 10000);  /* 0x8009005C */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x68DBu << 16; if (_c) { goto L_80090094; } }  /* 0x80090060 */
    R[4] = R[4] | 0x8BAD;  /* 0x80090068 */
    R[2] = R[0] + 10000;  /* 0x8009006C */
    R[2] = R[2] - R[19];  /* 0x80090070 */
    R[3] = R[2] << 7;  /* 0x80090074 */
    R[3] = R[3] - R[2];  /* 0x80090078 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009007C */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x80090080 */
    R[10] = HI;  /* 0x80090084 */
    R[2] = (uint32_t)((int32_t)R[10] >> 12);  /* 0x80090088 */
    R[2] = R[2] - R[3];  /* 0x8009008C */
    R[5] = R[5] + R[2];  /* 0x80090090 */
L_80090094:;
    R[4] = R[5] + R[0];  /* 0x80090094 */
    { R[31] = 0x800900A0u; R[6] = R[4] + R[0]; psx_next = 0x8008F39Cu; return; }  /* 0x80090098 jal */
}

void ev_80090020(void) {
    R[2] = ((int32_t)R[16] < 5);  /* 0x80090020 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[29] + 104; if (_c) { psx_next = 0x8008FE88u; return; } }  /* 0x80090024 b extern */
    R[2] = ((int32_t)R[19] < 30000);  /* 0x8009002C */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x45E7u << 16; if (_c) { psx_next = 0x800900A0u; return; } }  /* 0x80090030 b extern */
    R[3] = R[3] | 0xB273;  /* 0x80090038 */
    R[2] = R[0] + 30000;  /* 0x8009003C */
    R[2] = R[2] - R[19];  /* 0x80090040 */
    R[2] = R[2] << 7;  /* 0x80090044 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x80090048 */
    R[2] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x8009004C */
    R[10] = HI;  /* 0x80090050 */
    R[3] = (uint32_t)((int32_t)R[10] >> 13);  /* 0x80090054 */
    R[5] = R[3] - R[2];  /* 0x80090058 */
    R[2] = ((int32_t)R[19] < 10000);  /* 0x8009005C */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x68DBu << 16; if (_c) { goto L_80090094; } }  /* 0x80090060 */
    R[4] = R[4] | 0x8BAD;  /* 0x80090068 */
    R[2] = R[0] + 10000;  /* 0x8009006C */
    R[2] = R[2] - R[19];  /* 0x80090070 */
    R[3] = R[2] << 7;  /* 0x80090074 */
    R[3] = R[3] - R[2];  /* 0x80090078 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009007C */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x80090080 */
    R[10] = HI;  /* 0x80090084 */
    R[2] = (uint32_t)((int32_t)R[10] >> 12);  /* 0x80090088 */
    R[2] = R[2] - R[3];  /* 0x8009008C */
    R[5] = R[5] + R[2];  /* 0x80090090 */
L_80090094:;
    R[4] = R[5] + R[0];  /* 0x80090094 */
    { R[31] = 0x800900A0u; R[6] = R[4] + R[0]; psx_next = 0x8008F39Cu; return; }  /* 0x80090098 jal */
}

void ev_80090030(void) {
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x45E7u << 16; if (_c) { psx_next = 0x800900A0u; return; } }  /* 0x80090030 b extern */
    R[3] = R[3] | 0xB273;  /* 0x80090038 */
    R[2] = R[0] + 30000;  /* 0x8009003C */
    R[2] = R[2] - R[19];  /* 0x80090040 */
    R[2] = R[2] << 7;  /* 0x80090044 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x80090048 */
    R[2] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x8009004C */
    R[10] = HI;  /* 0x80090050 */
    R[3] = (uint32_t)((int32_t)R[10] >> 13);  /* 0x80090054 */
    R[5] = R[3] - R[2];  /* 0x80090058 */
    R[2] = ((int32_t)R[19] < 10000);  /* 0x8009005C */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x68DBu << 16; if (_c) { goto L_80090094; } }  /* 0x80090060 */
    R[4] = R[4] | 0x8BAD;  /* 0x80090068 */
    R[2] = R[0] + 10000;  /* 0x8009006C */
    R[2] = R[2] - R[19];  /* 0x80090070 */
    R[3] = R[2] << 7;  /* 0x80090074 */
    R[3] = R[3] - R[2];  /* 0x80090078 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009007C */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x80090080 */
    R[10] = HI;  /* 0x80090084 */
    R[2] = (uint32_t)((int32_t)R[10] >> 12);  /* 0x80090088 */
    R[2] = R[2] - R[3];  /* 0x8009008C */
    R[5] = R[5] + R[2];  /* 0x80090090 */
L_80090094:;
    R[4] = R[5] + R[0];  /* 0x80090094 */
    { R[31] = 0x800900A0u; R[6] = R[4] + R[0]; psx_next = 0x8008F39Cu; return; }  /* 0x80090098 jal */
}

void ev_8009009C(void) {
    R[6] = R[4] + R[0];  /* 0x8009009C */
    R[4] = R[0] + 1;  /* 0x800900A0 */
    { R[31] = 0x800900ACu; R[5] = R[0] + 9; psx_next = 0x8008F448u; return; }  /* 0x800900A4 jal */
    R[31] = lw_(R[29] + 172);  /* 0x800900AC */
    R[22] = lw_(R[29] + 168);  /* 0x800900B0 */
    R[21] = lw_(R[29] + 164);  /* 0x800900B4 */
    R[20] = lw_(R[29] + 160);  /* 0x800900B8 */
    R[19] = lw_(R[29] + 156);  /* 0x800900BC */
    R[18] = lw_(R[29] + 152);  /* 0x800900C0 */
    R[17] = lw_(R[29] + 148);  /* 0x800900C4 */
    R[16] = lw_(R[29] + 144);  /* 0x800900C8 */
    { R[29] = R[29] + 176; psx_next = R[31]; return; }  /* 0x800900CC jr ra */
}

void ev_800900A0(void) {
    R[4] = R[0] + 1;  /* 0x800900A0 */
    { R[31] = 0x800900ACu; R[5] = R[0] + 9; psx_next = 0x8008F448u; return; }  /* 0x800900A4 jal */
    R[31] = lw_(R[29] + 172);  /* 0x800900AC */
    R[22] = lw_(R[29] + 168);  /* 0x800900B0 */
    R[21] = lw_(R[29] + 164);  /* 0x800900B4 */
    R[20] = lw_(R[29] + 160);  /* 0x800900B8 */
    R[19] = lw_(R[29] + 156);  /* 0x800900BC */
    R[18] = lw_(R[29] + 152);  /* 0x800900C0 */
    R[17] = lw_(R[29] + 148);  /* 0x800900C4 */
    R[16] = lw_(R[29] + 144);  /* 0x800900C8 */
    { R[29] = R[29] + 176; psx_next = R[31]; return; }  /* 0x800900CC jr ra */
}

void ev_800900AC(void) {
    R[31] = lw_(R[29] + 172);  /* 0x800900AC */
    R[22] = lw_(R[29] + 168);  /* 0x800900B0 */
    R[21] = lw_(R[29] + 164);  /* 0x800900B4 */
    R[20] = lw_(R[29] + 160);  /* 0x800900B8 */
    R[19] = lw_(R[29] + 156);  /* 0x800900BC */
    R[18] = lw_(R[29] + 152);  /* 0x800900C0 */
    R[17] = lw_(R[29] + 148);  /* 0x800900C4 */
    R[16] = lw_(R[29] + 144);  /* 0x800900C8 */
    { R[29] = R[29] + 176; psx_next = R[31]; return; }  /* 0x800900CC jr ra */
}

void ev_800900D4(void) {
    { psx_next = R[31]; return; }  /* 0x800900D4 jr ra */
}

void ev_800900DC(void) {
    { psx_next = R[31]; return; }  /* 0x800900DC jr ra */
}

void ev_800900E4(void) {
    R[8] = R[4] + R[0];  /* 0x800900E4 */
    R[10] = R[0] + R[0];  /* 0x800900E8 */
    R[4] = R[0] + 4;  /* 0x800900EC */
    R[2] = 0x800Bu << 16;  /* 0x800900F0 */
    R[3] = R[2] + 19304;  /* 0x800900F4 */
L_800900F8:;
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800900F8 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_80090118; } }  /* 0x80090100 */
    R[2] = lw_(R[3] + 4);  /* 0x80090108 */
    { uint32_t _c = (R[2] == R[8]); R[2] = R[0] + 150; if (_c) { goto L_8009012C; } }  /* 0x80090110 */
L_80090118:;
    R[10] = R[10] + 1;  /* 0x80090118 */
    R[2] = ((int32_t)R[10] < 150);  /* 0x8009011C */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 68; if (_c) { psx_bb(); goto L_800900F8; } }  /* 0x80090120 */
    R[2] = R[0] + 150;  /* 0x80090128 */
L_8009012C:;
    { uint32_t _c = (R[10] == R[2]); R[2] = R[10] << 4; if (_c) { psx_next = 0x80090418u; return; } }  /* 0x8009012C b extern */
    R[2] = R[2] + R[10];  /* 0x80090134 */
    R[2] = R[2] << 2;  /* 0x80090138 */
    R[3] = 0x800Bu << 16;  /* 0x8009013C */
    R[3] = R[3] + 19312;  /* 0x80090140 */
    R[4] = R[3] - 8;  /* 0x80090144 */
    R[13] = R[2] + R[4];  /* 0x80090148 */
    R[2] = R[2] + R[3];  /* 0x8009014C */
    R[4] = lw_(R[8] + 952);  /* 0x80090150 */
    R[3] = lw_(R[8] + 976);  /* 0x80090154 */
    R[9] = R[0] + R[0];  /* 0x80090158 */
    sw_(R[8] + 564, R[2]);  /* 0x8009015C */
    R[2] = lw_(R[8] + 956);  /* 0x80090160 */
    R[4] = R[4] << 2;  /* 0x80090164 */
    R[4] = R[3] + R[4];  /* 0x80090168 */
    R[2] = R[2] << 2;  /* 0x8009016C */
    R[3] = R[3] + R[2];  /* 0x80090170 */
    R[12] = lw_(R[3]);  /* 0x80090174 */
    R[11] = lw_(R[4]);  /* 0x80090178 */
    R[7] = R[12] + R[0];  /* 0x8009017C */
    R[6] = R[11] + R[0];  /* 0x80090180 */
    R[2] = (uint32_t)(int16_t)lh_(R[7] + 32);  /* 0x80090184 */
    R[3] = (uint32_t)(int16_t)lh_(R[6] + 32);  /* 0x80090188 */
    R[4] = (uint32_t)(int16_t)lh_(R[13] + 2);  /* 0x8009018C */
    R[2] = R[2] - R[3];  /* 0x80090190 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x80090194 */
    R[2] = LO;  /* 0x80090198 */
    R[4] = lw_(R[8] + 960);  /* 0x8009019C */
    psx_div((int32_t)R[2], (int32_t)R[4]);  /* 0x800901A4 */
    R[4] = LO;  /* 0x800901A8 */
    R[5] = R[9] << 1;  /* 0x800901AC */
    R[3] = lw_(R[8] + 564);  /* 0x800901B0 */
    R[2] = lh_(R[6] + 32);  /* 0x800901B4 */
    R[3] = R[3] + R[5];  /* 0x800901B8 */
    R[2] = R[2] + R[4];  /* 0x800901BC */
    sh_(R[3] + 32, R[2]);  /* 0x800901C0 */
    R[2] = (uint32_t)(int16_t)lh_(R[7] + 12);  /* 0x800901C4 */
    R[3] = (uint32_t)(int16_t)lh_(R[6] + 12);  /* 0x800901C8 */
    R[4] = (uint32_t)(int16_t)lh_(R[13] + 2);  /* 0x800901CC */
    R[2] = R[2] - R[3];  /* 0x800901D0 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800901D4 */
    psx_next = 0x800901D8u; return;  /* fallthrough */
}

void ev_80090184(void) {
    R[2] = (uint32_t)(int16_t)lh_(R[7] + 32);  /* 0x80090184 */
    R[3] = (uint32_t)(int16_t)lh_(R[6] + 32);  /* 0x80090188 */
    R[4] = (uint32_t)(int16_t)lh_(R[13] + 2);  /* 0x8009018C */
    R[2] = R[2] - R[3];  /* 0x80090190 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x80090194 */
    R[2] = LO;  /* 0x80090198 */
    R[4] = lw_(R[8] + 960);  /* 0x8009019C */
    psx_div((int32_t)R[2], (int32_t)R[4]);  /* 0x800901A4 */
    R[4] = LO;  /* 0x800901A8 */
    R[5] = R[9] << 1;  /* 0x800901AC */
    R[3] = lw_(R[8] + 564);  /* 0x800901B0 */
    R[2] = lh_(R[6] + 32);  /* 0x800901B4 */
    R[3] = R[3] + R[5];  /* 0x800901B8 */
    R[2] = R[2] + R[4];  /* 0x800901BC */
    sh_(R[3] + 32, R[2]);  /* 0x800901C0 */
    R[2] = (uint32_t)(int16_t)lh_(R[7] + 12);  /* 0x800901C4 */
    R[3] = (uint32_t)(int16_t)lh_(R[6] + 12);  /* 0x800901C8 */
    R[4] = (uint32_t)(int16_t)lh_(R[13] + 2);  /* 0x800901CC */
    R[2] = R[2] - R[3];  /* 0x800901D0 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800901D4 */
    psx_next = 0x800901D8u; return;  /* fallthrough */
}

void ev_800901D8(void) {
    R[2] = LO;  /* 0x800901D8 */
    R[4] = lw_(R[8] + 960);  /* 0x800901DC */
    psx_div((int32_t)R[2], (int32_t)R[4]);  /* 0x800901E4 */
    R[4] = LO;  /* 0x800901E8 */
    R[9] = R[9] + 1;  /* 0x800901EC */
    R[3] = lw_(R[8] + 564);  /* 0x800901F0 */
    R[7] = R[7] + 2;  /* 0x800901F4 */
    R[3] = R[3] + R[5];  /* 0x800901F8 */
    R[2] = lh_(R[6] + 12);  /* 0x800901FC */
    R[2] = R[2] + R[4];  /* 0x80090204 */
    sh_(R[3] + 12, R[2]);  /* 0x80090208 */
    R[2] = ((int32_t)R[9] < 10);  /* 0x8009020C */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[6] + 2; if (_c) { psx_next = 0x80090184u; return; } }  /* 0x80090210 b extern */
    R[3] = 0x800Bu << 16;  /* 0x80090218 */
    R[3] = R[3] + 19304;  /* 0x8009021C */
    R[2] = R[10] << 4;  /* 0x80090220 */
    R[2] = R[2] + R[10];  /* 0x80090224 */
    R[2] = R[2] << 2;  /* 0x80090228 */
    R[5] = R[2] + R[3];  /* 0x8009022C */
    R[2] = lh_(R[12] + 6);  /* 0x80090230 */
    R[3] = lh_(R[11] + 6);  /* 0x80090234 */
    R[4] = (uint32_t)(int16_t)lh_(R[5] + 2);  /* 0x80090238 */
    R[2] = R[2] - R[3];  /* 0x8009023C */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x80090240 */
    R[6] = LO;  /* 0x80090244 */
    R[2] = lw_(R[8] + 960);  /* 0x80090248 */
    psx_div((int32_t)R[6], (int32_t)R[2]);  /* 0x80090250 */
    R[2] = LO;  /* 0x80090254 */
    R[4] = lw_(R[8] + 564);  /* 0x80090258 */
    R[3] = R[3] + R[2];  /* 0x8009025C */
    sh_(R[4] + 6, R[3]);  /* 0x80090260 */
    R[2] = lh_(R[12] + 8);  /* 0x80090264 */
    R[3] = lh_(R[11] + 8);  /* 0x80090268 */
    R[4] = (uint32_t)(int16_t)lh_(R[5] + 2);  /* 0x8009026C */
    R[2] = R[2] - R[3];  /* 0x80090270 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x80090274 */
    R[6] = LO;  /* 0x80090278 */
    R[2] = lw_(R[8] + 960);  /* 0x8009027C */
    psx_div((int32_t)R[6], (int32_t)R[2]);  /* 0x80090284 */
    R[2] = LO;  /* 0x80090288 */
    R[4] = lw_(R[8] + 564);  /* 0x8009028C */
    R[3] = R[3] + R[2];  /* 0x80090290 */
    sh_(R[4] + 8, R[3]);  /* 0x80090294 */
    R[2] = lh_(R[12] + 10);  /* 0x80090298 */
    R[3] = lh_(R[11] + 10);  /* 0x8009029C */
    R[4] = (uint32_t)(int16_t)lh_(R[5] + 2);  /* 0x800902A0 */
    R[2] = R[2] - R[3];  /* 0x800902A4 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800902A8 */
    R[6] = LO;  /* 0x800902AC */
    R[2] = lw_(R[8] + 960);  /* 0x800902B0 */
    psx_div((int32_t)R[6], (int32_t)R[2]);  /* 0x800902B8 */
    R[2] = LO;  /* 0x800902BC */
    R[4] = lw_(R[8] + 564);  /* 0x800902C0 */
    R[3] = R[3] + R[2];  /* 0x800902C4 */
    sh_(R[4] + 10, R[3]);  /* 0x800902C8 */
    R[2] = lh_(R[12]);  /* 0x800902CC */
    R[3] = lh_(R[11]);  /* 0x800902D0 */
    R[4] = (uint32_t)(int16_t)lh_(R[5] + 2);  /* 0x800902D4 */
    R[2] = R[2] - R[3];  /* 0x800902D8 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800902DC */
    R[6] = LO;  /* 0x800902E0 */
    R[2] = lw_(R[8] + 960);  /* 0x800902E4 */
    psx_div((int32_t)R[6], (int32_t)R[2]);  /* 0x800902EC */
    R[2] = LO;  /* 0x800902F0 */
    R[4] = lw_(R[8] + 564);  /* 0x800902F4 */
    R[3] = R[3] + R[2];  /* 0x800902F8 */
    sh_(R[4], R[3]);  /* 0x800902FC */
    R[2] = lh_(R[12] + 2);  /* 0x80090300 */
    R[3] = lh_(R[11] + 2);  /* 0x80090304 */
    R[4] = (uint32_t)(int16_t)lh_(R[5] + 2);  /* 0x80090308 */
    R[2] = R[2] - R[3];  /* 0x8009030C */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x80090310 */
    R[6] = LO;  /* 0x80090314 */
    R[2] = lw_(R[8] + 960);  /* 0x80090318 */
    psx_div((int32_t)R[6], (int32_t)R[2]);  /* 0x80090320 */
    R[2] = LO;  /* 0x80090324 */
    R[4] = lw_(R[8] + 564);  /* 0x80090328 */
    R[3] = R[3] + R[2];  /* 0x8009032C */
    sh_(R[4] + 2, R[3]);  /* 0x80090330 */
    R[2] = lh_(R[12] + 4);  /* 0x80090334 */
    R[3] = lh_(R[11] + 4);  /* 0x80090338 */
    R[4] = (uint32_t)(int16_t)lh_(R[5] + 2);  /* 0x8009033C */
    R[2] = R[2] - R[3];  /* 0x80090340 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x80090344 */
    R[6] = LO;  /* 0x80090348 */
    R[2] = lw_(R[8] + 960);  /* 0x8009034C */
    psx_div((int32_t)R[6], (int32_t)R[2]);  /* 0x80090354 */
    R[2] = LO;  /* 0x80090358 */
    R[4] = lw_(R[8] + 564);  /* 0x8009035C */
    R[3] = R[3] + R[2];  /* 0x80090360 */
    sh_(R[4] + 4, R[3]);  /* 0x80090364 */
    R[2] = lw_(R[12] + 52);  /* 0x80090368 */
    R[3] = lw_(R[11] + 52);  /* 0x8009036C */
    R[4] = (uint32_t)(int16_t)lh_(R[5] + 2);  /* 0x80090370 */
    R[2] = R[2] - R[3];  /* 0x80090374 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x80090378 */
    R[6] = LO;  /* 0x8009037C */
    R[2] = lw_(R[8] + 960);  /* 0x80090380 */
    psx_div((int32_t)R[6], (int32_t)R[2]);  /* 0x80090388 */
    R[2] = LO;  /* 0x8009038C */
    R[4] = lw_(R[8] + 564);  /* 0x80090390 */
    R[3] = R[3] + R[2];  /* 0x80090394 */
    sw_(R[4] + 52, R[3]);  /* 0x80090398 */
    R[2] = lw_(R[12] + 56);  /* 0x8009039C */
    R[3] = lw_(R[11] + 56);  /* 0x800903A0 */
    R[4] = (uint32_t)(int16_t)lh_(R[5] + 2);  /* 0x800903A4 */
    R[2] = R[2] - R[3];  /* 0x800903A8 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800903AC */
    R[6] = LO;  /* 0x800903B0 */
    R[2] = lw_(R[8] + 960);  /* 0x800903B4 */
    psx_div((int32_t)R[6], (int32_t)R[2]);  /* 0x800903BC */
    R[2] = LO;  /* 0x800903C0 */
    R[4] = lw_(R[8] + 564);  /* 0x800903C4 */
    R[3] = R[3] + R[2];  /* 0x800903C8 */
    sw_(R[4] + 56, R[3]);  /* 0x800903CC */
    R[3] = (uint32_t)(int16_t)lh_(R[5] + 2);  /* 0x800903D0 */
    R[2] = lw_(R[8] + 960);  /* 0x800903D4 */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_80090408; } }  /* 0x800903DC */
    sh_(R[5], R[0]);  /* 0x800903E4 */
    R[2] = lw_(R[8] + 956);  /* 0x800903E8 */
    R[3] = lw_(R[8] + 976);  /* 0x800903EC */
    sw_(R[8] + 948, R[0]);  /* 0x800903F0 */
    R[2] = R[2] << 2;  /* 0x800903F4 */
    R[3] = R[3] + R[2];  /* 0x800903F8 */
    R[2] = lw_(R[3]);  /* 0x800903FC */
    sw_(R[8] + 564, R[2]);  /* 0x80090404 */
L_80090408:;
    R[2] = lh_(R[5] + 2);  /* 0x80090408 */
    R[2] = R[2] + 1;  /* 0x80090410 */
    sh_(R[5] + 2, R[2]);  /* 0x80090414 */
    { psx_next = R[31]; return; }  /* 0x80090418 jr ra */
}

void ev_80090418(void) {
    { psx_next = R[31]; return; }  /* 0x80090418 jr ra */
}

void ev_80090420(void) {
    R[29] = R[29] - 528;  /* 0x80090420 */
    R[2] = R[0] + 17;  /* 0x80090424 */
    sw_(R[29] + 528, R[4]);  /* 0x80090428 */
    R[4] = R[29] + 84;  /* 0x8009042C */
    R[3] = R[29] + 292;  /* 0x80090430 */
    sw_(R[29] + 524, R[31]);  /* 0x80090434 */
    sw_(R[29] + 520, R[30]);  /* 0x80090438 */
    sw_(R[29] + 516, R[23]);  /* 0x8009043C */
    sw_(R[29] + 512, R[22]);  /* 0x80090440 */
    sw_(R[29] + 508, R[21]);  /* 0x80090444 */
    sw_(R[29] + 504, R[20]);  /* 0x80090448 */
    sw_(R[29] + 500, R[19]);  /* 0x8009044C */
    sw_(R[29] + 496, R[18]);  /* 0x80090450 */
    sw_(R[29] + 492, R[17]);  /* 0x80090454 */
    sw_(R[29] + 488, R[16]);  /* 0x80090458 */
L_8009045C:;
    sw_(R[4], R[3]);  /* 0x8009045C */
    R[4] = R[4] - 4;  /* 0x80090460 */
    R[2] = R[2] - 1;  /* 0x80090464 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = R[3] - 12; if (_c) { psx_bb(); goto L_8009045C; } }  /* 0x80090468 */
    { R[31] = 0x80090478u; psx_next = 0x8008F5D0u; return; }  /* 0x80090470 jal */
    { uint32_t _c = ((int32_t)R[2] < 0); R[4] = 0x800Bu << 16; if (_c) { goto L_800904E4; } }  /* 0x80090478 */
    R[4] = R[4] + 19304;  /* 0x80090480 */
    R[3] = R[2] << 4;  /* 0x80090484 */
    R[7] = lw_(R[29] + 528);  /* 0x80090488 */
    R[3] = R[3] + R[2];  /* 0x8009048C */
    R[2] = lw_(R[7] + 1032);  /* 0x80090490 */
    R[3] = R[3] << 2;  /* 0x80090494 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 2);  /* 0x80090498 */
    R[3] = R[3] + R[4];  /* 0x8009049C */
    R[2] = R[2] << 12;  /* 0x800904A0 */
    sw_(R[3] + 8, R[2]);  /* 0x800904A4 */
    R[2] = lw_(R[7] + 1032);  /* 0x800904A8 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x800904B0 */
    R[2] = R[2] << 12;  /* 0x800904B8 */
    sw_(R[3] + 12, R[2]);  /* 0x800904BC */
    R[2] = lw_(R[7] + 1032);  /* 0x800904C0 */
    R[4] = (uint32_t)(int16_t)lh_(R[2] + 6);  /* 0x800904C8 */
    R[2] = R[0] + 6;  /* 0x800904CC */
    sh_(R[3], R[2]);  /* 0x800904D0 */
    sh_(R[3] + 2, R[0]);  /* 0x800904D4 */
    sw_(R[3] + 4, R[7]);  /* 0x800904D8 */
    R[4] = R[4] << 12;  /* 0x800904DC */
    sw_(R[3] + 16, R[4]);  /* 0x800904E0 */
L_800904E4:;
    R[22] = R[29] + 456;  /* 0x800904E4 */
    R[7] = R[29] + 88;  /* 0x800904E8 */
    sw_(R[29] + 480, R[7]);  /* 0x800904EC */
    R[23] = R[29] + 304;  /* 0x800904F0 */
    R[20] = 0x800Bu << 16;  /* 0x800904F4 */
    R[20] = R[20] + 19304;  /* 0x800904F8 */
    R[3] = (uint32_t)(int16_t)lh_(R[20]);  /* 0x800904FC */
    R[2] = R[0] + 6;  /* 0x80090500 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { psx_next = 0x80090704u; return; } }  /* 0x80090504 b extern */
    R[2] = lw_(R[20] + 4);  /* 0x8009050C */
    R[7] = lw_(R[29] + 528);  /* 0x80090510 */
    { uint32_t _c = (R[2] != R[7]); if (_c) { psx_next = 0x80090704u; return; } }  /* 0x80090518 b extern */
    R[18] = R[0] + R[0];  /* 0x80090520 */
    R[17] = R[20] + R[0];  /* 0x80090524 */
    R[16] = lw_(R[29] + 480);  /* 0x80090528 */
L_8009052C:;
    R[1] = 0x8001u << 16;  /* 0x8009052C */
    R[1] = R[1] | 0x8;  /* 0x80090530 */
    { uint32_t _t = R[1]; R[31] = 0x8009053Cu; R[4] = R[22] + R[0]; psx_next = _t; return; }  /* 0x80090534 jalr */
    R[4] = 0x800Du << 16;  /* 0x8009053C */
    R[4] = R[4] + 30472;  /* 0x80090540 */
    { R[31] = 0x8009054Cu; R[5] = R[22] + R[0]; psx_next = 0x80036528u; return; }  /* 0x80090544 jal */
    R[4] = R[22] + R[0];  /* 0x8009054C */
    R[5] = R[29] + 448;  /* 0x80090550 */
    R[6] = R[16] + R[0];  /* 0x80090554 */
    R[2] = R[0] + 200;  /* 0x80090558 */
    sh_(R[29] + 448, R[0]);  /* 0x8009055C */
    sh_(R[29] + 450, R[0]);  /* 0x80090560 */
    { R[31] = 0x8009056Cu; sh_(R[29] + 452, R[2]); psx_next = 0x80036638u; return; }  /* 0x80090564 jal */
    R[18] = R[18] + 1;  /* 0x8009056C */
    R[2] = lw_(R[16]);  /* 0x80090570 */
    R[3] = lw_(R[17] + 8);  /* 0x80090574 */
    R[2] = R[2] << 12;  /* 0x80090578 */
    R[2] = R[2] + R[3];  /* 0x8009057C */
    sw_(R[16], R[2]);  /* 0x80090580 */
    R[2] = lw_(R[16] + 4);  /* 0x80090584 */
    R[3] = lw_(R[17] + 12);  /* 0x80090588 */
    R[2] = R[2] << 12;  /* 0x8009058C */
    R[2] = R[2] + R[3];  /* 0x80090590 */
    sw_(R[16] + 4, R[2]);  /* 0x80090594 */
    R[2] = lw_(R[16] + 8);  /* 0x80090598 */
    R[3] = lw_(R[17] + 16);  /* 0x8009059C */
    R[2] = R[2] << 12;  /* 0x800905A0 */
    R[2] = R[2] + R[3];  /* 0x800905A4 */
    sw_(R[16] + 8, R[2]);  /* 0x800905A8 */
    R[2] = ((int32_t)R[18] < 16);  /* 0x800905AC */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 12; if (_c) { psx_bb(); goto L_8009052C; } }  /* 0x800905B0 */
    R[4] = 0x800Du << 16;  /* 0x800905B8 */
    R[4] = R[4] + 30448;  /* 0x800905BC */
    R[5] = R[0] + 6;  /* 0x800905C0 */
    R[6] = R[0] + R[0];  /* 0x800905C4 */
    R[18] = R[6] + R[0];  /* 0x800905C8 */
    R[17] = R[0] + 255;  /* 0x800905CC */
    R[21] = 0xFFu << 16;  /* 0x800905D0 */
    psx_next = 0x800905D4u; return;  /* fallthrough */
}

void ev_80090478(void) {
    { uint32_t _c = ((int32_t)R[2] < 0); R[4] = 0x800Bu << 16; if (_c) { goto L_800904E4; } }  /* 0x80090478 */
    R[4] = R[4] + 19304;  /* 0x80090480 */
    R[3] = R[2] << 4;  /* 0x80090484 */
    R[7] = lw_(R[29] + 528);  /* 0x80090488 */
    R[3] = R[3] + R[2];  /* 0x8009048C */
    R[2] = lw_(R[7] + 1032);  /* 0x80090490 */
    R[3] = R[3] << 2;  /* 0x80090494 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 2);  /* 0x80090498 */
    R[3] = R[3] + R[4];  /* 0x8009049C */
    R[2] = R[2] << 12;  /* 0x800904A0 */
    sw_(R[3] + 8, R[2]);  /* 0x800904A4 */
    R[2] = lw_(R[7] + 1032);  /* 0x800904A8 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x800904B0 */
    R[2] = R[2] << 12;  /* 0x800904B8 */
    sw_(R[3] + 12, R[2]);  /* 0x800904BC */
    R[2] = lw_(R[7] + 1032);  /* 0x800904C0 */
    R[4] = (uint32_t)(int16_t)lh_(R[2] + 6);  /* 0x800904C8 */
    R[2] = R[0] + 6;  /* 0x800904CC */
    sh_(R[3], R[2]);  /* 0x800904D0 */
    sh_(R[3] + 2, R[0]);  /* 0x800904D4 */
    sw_(R[3] + 4, R[7]);  /* 0x800904D8 */
    R[4] = R[4] << 12;  /* 0x800904DC */
    sw_(R[3] + 16, R[4]);  /* 0x800904E0 */
L_800904E4:;
    R[22] = R[29] + 456;  /* 0x800904E4 */
    R[7] = R[29] + 88;  /* 0x800904E8 */
    sw_(R[29] + 480, R[7]);  /* 0x800904EC */
    R[23] = R[29] + 304;  /* 0x800904F0 */
    R[20] = 0x800Bu << 16;  /* 0x800904F4 */
    R[20] = R[20] + 19304;  /* 0x800904F8 */
    R[3] = (uint32_t)(int16_t)lh_(R[20]);  /* 0x800904FC */
    R[2] = R[0] + 6;  /* 0x80090500 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { psx_next = 0x80090704u; return; } }  /* 0x80090504 b extern */
    R[2] = lw_(R[20] + 4);  /* 0x8009050C */
    R[7] = lw_(R[29] + 528);  /* 0x80090510 */
    { uint32_t _c = (R[2] != R[7]); if (_c) { psx_next = 0x80090704u; return; } }  /* 0x80090518 b extern */
    R[18] = R[0] + R[0];  /* 0x80090520 */
    R[17] = R[20] + R[0];  /* 0x80090524 */
    R[16] = lw_(R[29] + 480);  /* 0x80090528 */
L_8009052C:;
    R[1] = 0x8001u << 16;  /* 0x8009052C */
    R[1] = R[1] | 0x8;  /* 0x80090530 */
    { uint32_t _t = R[1]; R[31] = 0x8009053Cu; R[4] = R[22] + R[0]; psx_next = _t; return; }  /* 0x80090534 jalr */
    R[4] = 0x800Du << 16;  /* 0x8009053C */
    R[4] = R[4] + 30472;  /* 0x80090540 */
    { R[31] = 0x8009054Cu; R[5] = R[22] + R[0]; psx_next = 0x80036528u; return; }  /* 0x80090544 jal */
    R[4] = R[22] + R[0];  /* 0x8009054C */
    R[5] = R[29] + 448;  /* 0x80090550 */
    R[6] = R[16] + R[0];  /* 0x80090554 */
    R[2] = R[0] + 200;  /* 0x80090558 */
    sh_(R[29] + 448, R[0]);  /* 0x8009055C */
    sh_(R[29] + 450, R[0]);  /* 0x80090560 */
    { R[31] = 0x8009056Cu; sh_(R[29] + 452, R[2]); psx_next = 0x80036638u; return; }  /* 0x80090564 jal */
    R[18] = R[18] + 1;  /* 0x8009056C */
    R[2] = lw_(R[16]);  /* 0x80090570 */
    R[3] = lw_(R[17] + 8);  /* 0x80090574 */
    R[2] = R[2] << 12;  /* 0x80090578 */
    R[2] = R[2] + R[3];  /* 0x8009057C */
    sw_(R[16], R[2]);  /* 0x80090580 */
    R[2] = lw_(R[16] + 4);  /* 0x80090584 */
    R[3] = lw_(R[17] + 12);  /* 0x80090588 */
    R[2] = R[2] << 12;  /* 0x8009058C */
    R[2] = R[2] + R[3];  /* 0x80090590 */
    sw_(R[16] + 4, R[2]);  /* 0x80090594 */
    R[2] = lw_(R[16] + 8);  /* 0x80090598 */
    R[3] = lw_(R[17] + 16);  /* 0x8009059C */
    R[2] = R[2] << 12;  /* 0x800905A0 */
    R[2] = R[2] + R[3];  /* 0x800905A4 */
    sw_(R[16] + 8, R[2]);  /* 0x800905A8 */
    R[2] = ((int32_t)R[18] < 16);  /* 0x800905AC */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 12; if (_c) { psx_bb(); goto L_8009052C; } }  /* 0x800905B0 */
    R[4] = 0x800Du << 16;  /* 0x800905B8 */
    R[4] = R[4] + 30448;  /* 0x800905BC */
    R[5] = R[0] + 6;  /* 0x800905C0 */
    R[6] = R[0] + R[0];  /* 0x800905C4 */
    R[18] = R[6] + R[0];  /* 0x800905C8 */
    R[17] = R[0] + 255;  /* 0x800905CC */
    R[21] = 0xFFu << 16;  /* 0x800905D0 */
    psx_next = 0x800905D4u; return;  /* fallthrough */
}

void ev_800904FC(void) {
    R[3] = (uint32_t)(int16_t)lh_(R[20]);  /* 0x800904FC */
    R[2] = R[0] + 6;  /* 0x80090500 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { psx_next = 0x80090704u; return; } }  /* 0x80090504 b extern */
    R[2] = lw_(R[20] + 4);  /* 0x8009050C */
    R[7] = lw_(R[29] + 528);  /* 0x80090510 */
    { uint32_t _c = (R[2] != R[7]); if (_c) { psx_next = 0x80090704u; return; } }  /* 0x80090518 b extern */
    R[18] = R[0] + R[0];  /* 0x80090520 */
    R[17] = R[20] + R[0];  /* 0x80090524 */
    R[16] = lw_(R[29] + 480);  /* 0x80090528 */
L_8009052C:;
    R[1] = 0x8001u << 16;  /* 0x8009052C */
    R[1] = R[1] | 0x8;  /* 0x80090530 */
    { uint32_t _t = R[1]; R[31] = 0x8009053Cu; R[4] = R[22] + R[0]; psx_next = _t; return; }  /* 0x80090534 jalr */
    R[4] = 0x800Du << 16;  /* 0x8009053C */
    R[4] = R[4] + 30472;  /* 0x80090540 */
    { R[31] = 0x8009054Cu; R[5] = R[22] + R[0]; psx_next = 0x80036528u; return; }  /* 0x80090544 jal */
    R[4] = R[22] + R[0];  /* 0x8009054C */
    R[5] = R[29] + 448;  /* 0x80090550 */
    R[6] = R[16] + R[0];  /* 0x80090554 */
    R[2] = R[0] + 200;  /* 0x80090558 */
    sh_(R[29] + 448, R[0]);  /* 0x8009055C */
    sh_(R[29] + 450, R[0]);  /* 0x80090560 */
    { R[31] = 0x8009056Cu; sh_(R[29] + 452, R[2]); psx_next = 0x80036638u; return; }  /* 0x80090564 jal */
    R[18] = R[18] + 1;  /* 0x8009056C */
    R[2] = lw_(R[16]);  /* 0x80090570 */
    R[3] = lw_(R[17] + 8);  /* 0x80090574 */
    R[2] = R[2] << 12;  /* 0x80090578 */
    R[2] = R[2] + R[3];  /* 0x8009057C */
    sw_(R[16], R[2]);  /* 0x80090580 */
    R[2] = lw_(R[16] + 4);  /* 0x80090584 */
    R[3] = lw_(R[17] + 12);  /* 0x80090588 */
    R[2] = R[2] << 12;  /* 0x8009058C */
    R[2] = R[2] + R[3];  /* 0x80090590 */
    sw_(R[16] + 4, R[2]);  /* 0x80090594 */
    R[2] = lw_(R[16] + 8);  /* 0x80090598 */
    R[3] = lw_(R[17] + 16);  /* 0x8009059C */
    R[2] = R[2] << 12;  /* 0x800905A0 */
    R[2] = R[2] + R[3];  /* 0x800905A4 */
    sw_(R[16] + 8, R[2]);  /* 0x800905A8 */
    R[2] = ((int32_t)R[18] < 16);  /* 0x800905AC */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 12; if (_c) { psx_bb(); goto L_8009052C; } }  /* 0x800905B0 */
    R[4] = 0x800Du << 16;  /* 0x800905B8 */
    R[4] = R[4] + 30448;  /* 0x800905BC */
    R[5] = R[0] + 6;  /* 0x800905C0 */
    R[6] = R[0] + R[0];  /* 0x800905C4 */
    R[18] = R[6] + R[0];  /* 0x800905C8 */
    R[17] = R[0] + 255;  /* 0x800905CC */
    R[21] = 0xFFu << 16;  /* 0x800905D0 */
    psx_next = 0x800905D4u; return;  /* fallthrough */
}

void ev_8009052C(void) {
L_8009052C:;
    R[1] = 0x8001u << 16;  /* 0x8009052C */
    R[1] = R[1] | 0x8;  /* 0x80090530 */
    { uint32_t _t = R[1]; R[31] = 0x8009053Cu; R[4] = R[22] + R[0]; psx_next = _t; return; }  /* 0x80090534 jalr */
    R[4] = 0x800Du << 16;  /* 0x8009053C */
    R[4] = R[4] + 30472;  /* 0x80090540 */
    { R[31] = 0x8009054Cu; R[5] = R[22] + R[0]; psx_next = 0x80036528u; return; }  /* 0x80090544 jal */
    R[4] = R[22] + R[0];  /* 0x8009054C */
    R[5] = R[29] + 448;  /* 0x80090550 */
    R[6] = R[16] + R[0];  /* 0x80090554 */
    R[2] = R[0] + 200;  /* 0x80090558 */
    sh_(R[29] + 448, R[0]);  /* 0x8009055C */
    sh_(R[29] + 450, R[0]);  /* 0x80090560 */
    { R[31] = 0x8009056Cu; sh_(R[29] + 452, R[2]); psx_next = 0x80036638u; return; }  /* 0x80090564 jal */
    R[18] = R[18] + 1;  /* 0x8009056C */
    R[2] = lw_(R[16]);  /* 0x80090570 */
    R[3] = lw_(R[17] + 8);  /* 0x80090574 */
    R[2] = R[2] << 12;  /* 0x80090578 */
    R[2] = R[2] + R[3];  /* 0x8009057C */
    sw_(R[16], R[2]);  /* 0x80090580 */
    R[2] = lw_(R[16] + 4);  /* 0x80090584 */
    R[3] = lw_(R[17] + 12);  /* 0x80090588 */
    R[2] = R[2] << 12;  /* 0x8009058C */
    R[2] = R[2] + R[3];  /* 0x80090590 */
    sw_(R[16] + 4, R[2]);  /* 0x80090594 */
    R[2] = lw_(R[16] + 8);  /* 0x80090598 */
    R[3] = lw_(R[17] + 16);  /* 0x8009059C */
    R[2] = R[2] << 12;  /* 0x800905A0 */
    R[2] = R[2] + R[3];  /* 0x800905A4 */
    sw_(R[16] + 8, R[2]);  /* 0x800905A8 */
    R[2] = ((int32_t)R[18] < 16);  /* 0x800905AC */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 12; if (_c) { psx_bb(); goto L_8009052C; } }  /* 0x800905B0 */
    R[4] = 0x800Du << 16;  /* 0x800905B8 */
    R[4] = R[4] + 30448;  /* 0x800905BC */
    R[5] = R[0] + 6;  /* 0x800905C0 */
    R[6] = R[0] + R[0];  /* 0x800905C4 */
    R[18] = R[6] + R[0];  /* 0x800905C8 */
    R[17] = R[0] + 255;  /* 0x800905CC */
    R[21] = 0xFFu << 16;  /* 0x800905D0 */
    psx_next = 0x800905D4u; return;  /* fallthrough */
}

void ev_8009053C(void) {
    R[4] = 0x800Du << 16;  /* 0x8009053C */
    R[4] = R[4] + 30472;  /* 0x80090540 */
    { R[31] = 0x8009054Cu; R[5] = R[22] + R[0]; psx_next = 0x80036528u; return; }  /* 0x80090544 jal */
    R[4] = R[22] + R[0];  /* 0x8009054C */
    R[5] = R[29] + 448;  /* 0x80090550 */
    R[6] = R[16] + R[0];  /* 0x80090554 */
    R[2] = R[0] + 200;  /* 0x80090558 */
    sh_(R[29] + 448, R[0]);  /* 0x8009055C */
    sh_(R[29] + 450, R[0]);  /* 0x80090560 */
    { R[31] = 0x8009056Cu; sh_(R[29] + 452, R[2]); psx_next = 0x80036638u; return; }  /* 0x80090564 jal */
    R[18] = R[18] + 1;  /* 0x8009056C */
    R[2] = lw_(R[16]);  /* 0x80090570 */
    R[3] = lw_(R[17] + 8);  /* 0x80090574 */
    R[2] = R[2] << 12;  /* 0x80090578 */
    R[2] = R[2] + R[3];  /* 0x8009057C */
    sw_(R[16], R[2]);  /* 0x80090580 */
    R[2] = lw_(R[16] + 4);  /* 0x80090584 */
    R[3] = lw_(R[17] + 12);  /* 0x80090588 */
    R[2] = R[2] << 12;  /* 0x8009058C */
    R[2] = R[2] + R[3];  /* 0x80090590 */
    sw_(R[16] + 4, R[2]);  /* 0x80090594 */
    R[2] = lw_(R[16] + 8);  /* 0x80090598 */
    R[3] = lw_(R[17] + 16);  /* 0x8009059C */
    R[2] = R[2] << 12;  /* 0x800905A0 */
    R[2] = R[2] + R[3];  /* 0x800905A4 */
    sw_(R[16] + 8, R[2]);  /* 0x800905A8 */
    R[2] = ((int32_t)R[18] < 16);  /* 0x800905AC */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 12; if (_c) { psx_next = 0x8009052Cu; return; } }  /* 0x800905B0 b extern */
    R[4] = 0x800Du << 16;  /* 0x800905B8 */
    R[4] = R[4] + 30448;  /* 0x800905BC */
    R[5] = R[0] + 6;  /* 0x800905C0 */
    R[6] = R[0] + R[0];  /* 0x800905C4 */
    R[18] = R[6] + R[0];  /* 0x800905C8 */
    R[17] = R[0] + 255;  /* 0x800905CC */
    R[21] = 0xFFu << 16;  /* 0x800905D0 */
    psx_next = 0x800905D4u; return;  /* fallthrough */
}

void ev_8009054C(void) {
    R[4] = R[22] + R[0];  /* 0x8009054C */
    R[5] = R[29] + 448;  /* 0x80090550 */
    R[6] = R[16] + R[0];  /* 0x80090554 */
    R[2] = R[0] + 200;  /* 0x80090558 */
    sh_(R[29] + 448, R[0]);  /* 0x8009055C */
    sh_(R[29] + 450, R[0]);  /* 0x80090560 */
    { R[31] = 0x8009056Cu; sh_(R[29] + 452, R[2]); psx_next = 0x80036638u; return; }  /* 0x80090564 jal */
    R[18] = R[18] + 1;  /* 0x8009056C */
    R[2] = lw_(R[16]);  /* 0x80090570 */
    R[3] = lw_(R[17] + 8);  /* 0x80090574 */
    R[2] = R[2] << 12;  /* 0x80090578 */
    R[2] = R[2] + R[3];  /* 0x8009057C */
    sw_(R[16], R[2]);  /* 0x80090580 */
    R[2] = lw_(R[16] + 4);  /* 0x80090584 */
    R[3] = lw_(R[17] + 12);  /* 0x80090588 */
    R[2] = R[2] << 12;  /* 0x8009058C */
    R[2] = R[2] + R[3];  /* 0x80090590 */
    sw_(R[16] + 4, R[2]);  /* 0x80090594 */
    R[2] = lw_(R[16] + 8);  /* 0x80090598 */
    R[3] = lw_(R[17] + 16);  /* 0x8009059C */
    R[2] = R[2] << 12;  /* 0x800905A0 */
    R[2] = R[2] + R[3];  /* 0x800905A4 */
    sw_(R[16] + 8, R[2]);  /* 0x800905A8 */
    R[2] = ((int32_t)R[18] < 16);  /* 0x800905AC */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 12; if (_c) { psx_next = 0x8009052Cu; return; } }  /* 0x800905B0 b extern */
    R[4] = 0x800Du << 16;  /* 0x800905B8 */
    R[4] = R[4] + 30448;  /* 0x800905BC */
    R[5] = R[0] + 6;  /* 0x800905C0 */
    R[6] = R[0] + R[0];  /* 0x800905C4 */
    R[18] = R[6] + R[0];  /* 0x800905C8 */
    R[17] = R[0] + 255;  /* 0x800905CC */
    R[21] = 0xFFu << 16;  /* 0x800905D0 */
    psx_next = 0x800905D4u; return;  /* fallthrough */
}

void ev_8009056C(void) {
    R[18] = R[18] + 1;  /* 0x8009056C */
    R[2] = lw_(R[16]);  /* 0x80090570 */
    R[3] = lw_(R[17] + 8);  /* 0x80090574 */
    R[2] = R[2] << 12;  /* 0x80090578 */
    R[2] = R[2] + R[3];  /* 0x8009057C */
    sw_(R[16], R[2]);  /* 0x80090580 */
    R[2] = lw_(R[16] + 4);  /* 0x80090584 */
    R[3] = lw_(R[17] + 12);  /* 0x80090588 */
    R[2] = R[2] << 12;  /* 0x8009058C */
    R[2] = R[2] + R[3];  /* 0x80090590 */
    sw_(R[16] + 4, R[2]);  /* 0x80090594 */
    R[2] = lw_(R[16] + 8);  /* 0x80090598 */
    R[3] = lw_(R[17] + 16);  /* 0x8009059C */
    R[2] = R[2] << 12;  /* 0x800905A0 */
    R[2] = R[2] + R[3];  /* 0x800905A4 */
    sw_(R[16] + 8, R[2]);  /* 0x800905A8 */
    R[2] = ((int32_t)R[18] < 16);  /* 0x800905AC */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 12; if (_c) { psx_next = 0x8009052Cu; return; } }  /* 0x800905B0 b extern */
    R[4] = 0x800Du << 16;  /* 0x800905B8 */
    R[4] = R[4] + 30448;  /* 0x800905BC */
    R[5] = R[0] + 6;  /* 0x800905C0 */
    R[6] = R[0] + R[0];  /* 0x800905C4 */
    R[18] = R[6] + R[0];  /* 0x800905C8 */
    R[17] = R[0] + 255;  /* 0x800905CC */
    R[21] = 0xFFu << 16;  /* 0x800905D0 */
    psx_next = 0x800905D4u; return;  /* fallthrough */
}

void ev_800905D4(void) {
    R[21] = R[21] | 0xFFFF;  /* 0x800905D4 */
    R[2] = lw_(R[20] + 8);  /* 0x800905D8 */
    R[30] = 0xFF00u << 16;  /* 0x800905DC */
    sw_(R[29] + 280, R[2]);  /* 0x800905E0 */
    R[2] = lw_(R[20] + 12);  /* 0x800905E4 */
    R[19] = R[23] + R[0];  /* 0x800905E8 */
    sw_(R[29] + 284, R[2]);  /* 0x800905EC */
    R[3] = lw_(R[20] + 16);  /* 0x800905F0 */
    R[2] = R[29] + 16;  /* 0x800905F4 */
    sw_(R[4] + 16, R[2]);  /* 0x800905F8 */
    sw_(R[4] + 20, R[23]);  /* 0x800905FC */
    { R[31] = 0x80090608u; sw_(R[29] + 288, R[3]); psx_next = 0x80025598u; return; }  /* 0x80090600 jal */
L_80090608:;
    R[7] = 0x800Cu << 16;  /* 0x80090608 */
    R[2] = 0x800Bu << 16;  /* 0x8009060C */
    R[16] = lw_(R[7] + -24632);  /* 0x80090610 */
    R[2] = lw_(R[2] + 30896);  /* 0x80090614 */
    R[2] = (R[16] < R[2]);  /* 0x8009061C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800906F4; } }  /* 0x80090620 */
    { R[31] = 0x80090630u; R[4] = R[16] + R[0]; psx_next = 0x80035758u; return; }  /* 0x80090628 jal */
    R[4] = R[16] + R[0];  /* 0x80090630 */
    { R[31] = 0x8009063Cu; R[5] = R[0] + 1; psx_next = 0x80035728u; return; }  /* 0x80090634 jal */
    R[2] = lh_(R[29] + 432);  /* 0x8009063C */
    sh_(R[16] + 8, R[2]);  /* 0x80090644 */
    R[2] = lh_(R[29] + 434);  /* 0x80090648 */
    sh_(R[16] + 10, R[2]);  /* 0x80090650 */
    R[2] = lh_(R[19]);  /* 0x80090654 */
    sh_(R[16] + 16, R[2]);  /* 0x8009065C */
    R[2] = lh_(R[19] + 2);  /* 0x80090660 */
    sh_(R[16] + 18, R[2]);  /* 0x80090668 */
    R[2] = R[18] + 1;  /* 0x8009066C */
    R[2] = R[2] & 0xF;  /* 0x80090670 */
    R[2] = R[2] << 3;  /* 0x80090674 */
    R[2] = R[23] + R[2];  /* 0x80090678 */
    R[3] = lh_(R[2]);  /* 0x8009067C */
    sh_(R[16] + 24, R[3]);  /* 0x80090684 */
    R[2] = lh_(R[2] + 2);  /* 0x80090688 */
    R[7] = 0x800Cu << 16;  /* 0x8009068C */
    sb_(R[16] + 4, R[17]);  /* 0x80090690 */
    sb_(R[16] + 5, R[17]);  /* 0x80090694 */
    sb_(R[16] + 6, R[17]);  /* 0x80090698 */
    sb_(R[16] + 12, R[17]);  /* 0x8009069C */
    sb_(R[16] + 13, R[17]);  /* 0x800906A0 */
    sb_(R[16] + 14, R[17]);  /* 0x800906A4 */
    sb_(R[16] + 20, R[17]);  /* 0x800906A8 */
    sb_(R[16] + 21, R[17]);  /* 0x800906AC */
    sb_(R[16] + 22, R[17]);  /* 0x800906B0 */
    sh_(R[16] + 26, R[2]);  /* 0x800906B4 */
    R[2] = 0x800Bu << 16;  /* 0x800906B8 */
    R[4] = lw_(R[2] + 30552);  /* 0x800906BC */
    R[2] = lw_(R[16]);  /* 0x800906C0 */
    R[3] = lw_(R[4] + 36);  /* 0x800906C4 */
    R[2] = R[2] & R[30];  /* 0x800906C8 */
    R[3] = R[3] & R[21];  /* 0x800906CC */
    R[2] = R[2] | R[3];  /* 0x800906D0 */
    R[3] = R[16] & R[21];  /* 0x800906D4 */
    sw_(R[16], R[2]);  /* 0x800906D8 */
    R[2] = lw_(R[4] + 36);  /* 0x800906DC */
    R[16] = R[16] + 28;  /* 0x800906E0 */
    sw_(R[7] + -24632, R[16]);  /* 0x800906E4 */
    R[2] = R[2] & R[30];  /* 0x800906E8 */
    R[2] = R[2] | R[3];  /* 0x800906EC */
    sw_(R[4] + 36, R[2]);  /* 0x800906F0 */
L_800906F4:;
    R[18] = R[18] + 1;  /* 0x800906F4 */
    R[2] = ((int32_t)R[18] < 16);  /* 0x800906F8 */
    { uint32_t _c = (R[2] != R[0]); R[19] = R[19] + 8; if (_c) { psx_bb(); goto L_80090608; } }  /* 0x800906FC */
    R[20] = R[20] + 68;  /* 0x80090704 */
    R[7] = 0x800Bu << 16;  /* 0x80090708 */
    R[7] = R[7] + 19304;  /* 0x8009070C */
    R[2] = R[7] + 10200;  /* 0x80090710 */
    R[2] = ((int32_t)R[20] < (int32_t)R[2]);  /* 0x80090714 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x800904FCu; return; } }  /* 0x80090718 b extern */
    R[31] = lw_(R[29] + 524);  /* 0x80090720 */
    R[30] = lw_(R[29] + 520);  /* 0x80090724 */
    R[23] = lw_(R[29] + 516);  /* 0x80090728 */
    R[22] = lw_(R[29] + 512);  /* 0x8009072C */
    R[21] = lw_(R[29] + 508);  /* 0x80090730 */
    R[20] = lw_(R[29] + 504);  /* 0x80090734 */
    R[19] = lw_(R[29] + 500);  /* 0x80090738 */
    R[18] = lw_(R[29] + 496);  /* 0x8009073C */
    R[17] = lw_(R[29] + 492);  /* 0x80090740 */
    R[16] = lw_(R[29] + 488);  /* 0x80090744 */
    { R[29] = R[29] + 528; psx_next = R[31]; return; }  /* 0x80090748 jr ra */
}

void ev_80090608(void) {
L_80090608:;
    R[7] = 0x800Cu << 16;  /* 0x80090608 */
    R[2] = 0x800Bu << 16;  /* 0x8009060C */
    R[16] = lw_(R[7] + -24632);  /* 0x80090610 */
    R[2] = lw_(R[2] + 30896);  /* 0x80090614 */
    R[2] = (R[16] < R[2]);  /* 0x8009061C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800906F4; } }  /* 0x80090620 */
    { R[31] = 0x80090630u; R[4] = R[16] + R[0]; psx_next = 0x80035758u; return; }  /* 0x80090628 jal */
    R[4] = R[16] + R[0];  /* 0x80090630 */
    { R[31] = 0x8009063Cu; R[5] = R[0] + 1; psx_next = 0x80035728u; return; }  /* 0x80090634 jal */
    R[2] = lh_(R[29] + 432);  /* 0x8009063C */
    sh_(R[16] + 8, R[2]);  /* 0x80090644 */
    R[2] = lh_(R[29] + 434);  /* 0x80090648 */
    sh_(R[16] + 10, R[2]);  /* 0x80090650 */
    R[2] = lh_(R[19]);  /* 0x80090654 */
    sh_(R[16] + 16, R[2]);  /* 0x8009065C */
    R[2] = lh_(R[19] + 2);  /* 0x80090660 */
    sh_(R[16] + 18, R[2]);  /* 0x80090668 */
    R[2] = R[18] + 1;  /* 0x8009066C */
    R[2] = R[2] & 0xF;  /* 0x80090670 */
    R[2] = R[2] << 3;  /* 0x80090674 */
    R[2] = R[23] + R[2];  /* 0x80090678 */
    R[3] = lh_(R[2]);  /* 0x8009067C */
    sh_(R[16] + 24, R[3]);  /* 0x80090684 */
    R[2] = lh_(R[2] + 2);  /* 0x80090688 */
    R[7] = 0x800Cu << 16;  /* 0x8009068C */
    sb_(R[16] + 4, R[17]);  /* 0x80090690 */
    sb_(R[16] + 5, R[17]);  /* 0x80090694 */
    sb_(R[16] + 6, R[17]);  /* 0x80090698 */
    sb_(R[16] + 12, R[17]);  /* 0x8009069C */
    sb_(R[16] + 13, R[17]);  /* 0x800906A0 */
    sb_(R[16] + 14, R[17]);  /* 0x800906A4 */
    sb_(R[16] + 20, R[17]);  /* 0x800906A8 */
    sb_(R[16] + 21, R[17]);  /* 0x800906AC */
    sb_(R[16] + 22, R[17]);  /* 0x800906B0 */
    sh_(R[16] + 26, R[2]);  /* 0x800906B4 */
    R[2] = 0x800Bu << 16;  /* 0x800906B8 */
    R[4] = lw_(R[2] + 30552);  /* 0x800906BC */
    R[2] = lw_(R[16]);  /* 0x800906C0 */
    R[3] = lw_(R[4] + 36);  /* 0x800906C4 */
    R[2] = R[2] & R[30];  /* 0x800906C8 */
    R[3] = R[3] & R[21];  /* 0x800906CC */
    R[2] = R[2] | R[3];  /* 0x800906D0 */
    R[3] = R[16] & R[21];  /* 0x800906D4 */
    sw_(R[16], R[2]);  /* 0x800906D8 */
    R[2] = lw_(R[4] + 36);  /* 0x800906DC */
    R[16] = R[16] + 28;  /* 0x800906E0 */
    sw_(R[7] + -24632, R[16]);  /* 0x800906E4 */
    R[2] = R[2] & R[30];  /* 0x800906E8 */
    R[2] = R[2] | R[3];  /* 0x800906EC */
    sw_(R[4] + 36, R[2]);  /* 0x800906F0 */
L_800906F4:;
    R[18] = R[18] + 1;  /* 0x800906F4 */
    R[2] = ((int32_t)R[18] < 16);  /* 0x800906F8 */
    { uint32_t _c = (R[2] != R[0]); R[19] = R[19] + 8; if (_c) { psx_bb(); goto L_80090608; } }  /* 0x800906FC */
    R[20] = R[20] + 68;  /* 0x80090704 */
    R[7] = 0x800Bu << 16;  /* 0x80090708 */
    R[7] = R[7] + 19304;  /* 0x8009070C */
    R[2] = R[7] + 10200;  /* 0x80090710 */
    R[2] = ((int32_t)R[20] < (int32_t)R[2]);  /* 0x80090714 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x800904FCu; return; } }  /* 0x80090718 b extern */
    R[31] = lw_(R[29] + 524);  /* 0x80090720 */
    R[30] = lw_(R[29] + 520);  /* 0x80090724 */
    R[23] = lw_(R[29] + 516);  /* 0x80090728 */
    R[22] = lw_(R[29] + 512);  /* 0x8009072C */
    R[21] = lw_(R[29] + 508);  /* 0x80090730 */
    R[20] = lw_(R[29] + 504);  /* 0x80090734 */
    R[19] = lw_(R[29] + 500);  /* 0x80090738 */
    R[18] = lw_(R[29] + 496);  /* 0x8009073C */
    R[17] = lw_(R[29] + 492);  /* 0x80090740 */
    R[16] = lw_(R[29] + 488);  /* 0x80090744 */
    { R[29] = R[29] + 528; psx_next = R[31]; return; }  /* 0x80090748 jr ra */
}

void ev_80090630(void) {
    R[4] = R[16] + R[0];  /* 0x80090630 */
    { R[31] = 0x8009063Cu; R[5] = R[0] + 1; psx_next = 0x80035728u; return; }  /* 0x80090634 jal */
    R[2] = lh_(R[29] + 432);  /* 0x8009063C */
    sh_(R[16] + 8, R[2]);  /* 0x80090644 */
    R[2] = lh_(R[29] + 434);  /* 0x80090648 */
    sh_(R[16] + 10, R[2]);  /* 0x80090650 */
    R[2] = lh_(R[19]);  /* 0x80090654 */
    sh_(R[16] + 16, R[2]);  /* 0x8009065C */
    R[2] = lh_(R[19] + 2);  /* 0x80090660 */
    sh_(R[16] + 18, R[2]);  /* 0x80090668 */
    R[2] = R[18] + 1;  /* 0x8009066C */
    R[2] = R[2] & 0xF;  /* 0x80090670 */
    R[2] = R[2] << 3;  /* 0x80090674 */
    R[2] = R[23] + R[2];  /* 0x80090678 */
    R[3] = lh_(R[2]);  /* 0x8009067C */
    sh_(R[16] + 24, R[3]);  /* 0x80090684 */
    R[2] = lh_(R[2] + 2);  /* 0x80090688 */
    R[7] = 0x800Cu << 16;  /* 0x8009068C */
    sb_(R[16] + 4, R[17]);  /* 0x80090690 */
    sb_(R[16] + 5, R[17]);  /* 0x80090694 */
    sb_(R[16] + 6, R[17]);  /* 0x80090698 */
    sb_(R[16] + 12, R[17]);  /* 0x8009069C */
    sb_(R[16] + 13, R[17]);  /* 0x800906A0 */
    sb_(R[16] + 14, R[17]);  /* 0x800906A4 */
    sb_(R[16] + 20, R[17]);  /* 0x800906A8 */
    sb_(R[16] + 21, R[17]);  /* 0x800906AC */
    sb_(R[16] + 22, R[17]);  /* 0x800906B0 */
    sh_(R[16] + 26, R[2]);  /* 0x800906B4 */
    R[2] = 0x800Bu << 16;  /* 0x800906B8 */
    R[4] = lw_(R[2] + 30552);  /* 0x800906BC */
    R[2] = lw_(R[16]);  /* 0x800906C0 */
    R[3] = lw_(R[4] + 36);  /* 0x800906C4 */
    R[2] = R[2] & R[30];  /* 0x800906C8 */
    R[3] = R[3] & R[21];  /* 0x800906CC */
    R[2] = R[2] | R[3];  /* 0x800906D0 */
    R[3] = R[16] & R[21];  /* 0x800906D4 */
    sw_(R[16], R[2]);  /* 0x800906D8 */
    R[2] = lw_(R[4] + 36);  /* 0x800906DC */
    R[16] = R[16] + 28;  /* 0x800906E0 */
    sw_(R[7] + -24632, R[16]);  /* 0x800906E4 */
    R[2] = R[2] & R[30];  /* 0x800906E8 */
    R[2] = R[2] | R[3];  /* 0x800906EC */
    sw_(R[4] + 36, R[2]);  /* 0x800906F0 */
    R[18] = R[18] + 1;  /* 0x800906F4 */
    R[2] = ((int32_t)R[18] < 16);  /* 0x800906F8 */
    { uint32_t _c = (R[2] != R[0]); R[19] = R[19] + 8; if (_c) { psx_next = 0x80090608u; return; } }  /* 0x800906FC b extern */
    R[20] = R[20] + 68;  /* 0x80090704 */
    R[7] = 0x800Bu << 16;  /* 0x80090708 */
    R[7] = R[7] + 19304;  /* 0x8009070C */
    R[2] = R[7] + 10200;  /* 0x80090710 */
    R[2] = ((int32_t)R[20] < (int32_t)R[2]);  /* 0x80090714 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x800904FCu; return; } }  /* 0x80090718 b extern */
    R[31] = lw_(R[29] + 524);  /* 0x80090720 */
    R[30] = lw_(R[29] + 520);  /* 0x80090724 */
    R[23] = lw_(R[29] + 516);  /* 0x80090728 */
    R[22] = lw_(R[29] + 512);  /* 0x8009072C */
    R[21] = lw_(R[29] + 508);  /* 0x80090730 */
    R[20] = lw_(R[29] + 504);  /* 0x80090734 */
    R[19] = lw_(R[29] + 500);  /* 0x80090738 */
    R[18] = lw_(R[29] + 496);  /* 0x8009073C */
    R[17] = lw_(R[29] + 492);  /* 0x80090740 */
    R[16] = lw_(R[29] + 488);  /* 0x80090744 */
    { R[29] = R[29] + 528; psx_next = R[31]; return; }  /* 0x80090748 jr ra */
}

void ev_8009063C(void) {
    R[2] = lh_(R[29] + 432);  /* 0x8009063C */
    sh_(R[16] + 8, R[2]);  /* 0x80090644 */
    R[2] = lh_(R[29] + 434);  /* 0x80090648 */
    sh_(R[16] + 10, R[2]);  /* 0x80090650 */
    R[2] = lh_(R[19]);  /* 0x80090654 */
    sh_(R[16] + 16, R[2]);  /* 0x8009065C */
    R[2] = lh_(R[19] + 2);  /* 0x80090660 */
    sh_(R[16] + 18, R[2]);  /* 0x80090668 */
    R[2] = R[18] + 1;  /* 0x8009066C */
    R[2] = R[2] & 0xF;  /* 0x80090670 */
    R[2] = R[2] << 3;  /* 0x80090674 */
    R[2] = R[23] + R[2];  /* 0x80090678 */
    R[3] = lh_(R[2]);  /* 0x8009067C */
    sh_(R[16] + 24, R[3]);  /* 0x80090684 */
    R[2] = lh_(R[2] + 2);  /* 0x80090688 */
    R[7] = 0x800Cu << 16;  /* 0x8009068C */
    sb_(R[16] + 4, R[17]);  /* 0x80090690 */
    sb_(R[16] + 5, R[17]);  /* 0x80090694 */
    sb_(R[16] + 6, R[17]);  /* 0x80090698 */
    sb_(R[16] + 12, R[17]);  /* 0x8009069C */
    sb_(R[16] + 13, R[17]);  /* 0x800906A0 */
    sb_(R[16] + 14, R[17]);  /* 0x800906A4 */
    sb_(R[16] + 20, R[17]);  /* 0x800906A8 */
    sb_(R[16] + 21, R[17]);  /* 0x800906AC */
    sb_(R[16] + 22, R[17]);  /* 0x800906B0 */
    sh_(R[16] + 26, R[2]);  /* 0x800906B4 */
    R[2] = 0x800Bu << 16;  /* 0x800906B8 */
    R[4] = lw_(R[2] + 30552);  /* 0x800906BC */
    R[2] = lw_(R[16]);  /* 0x800906C0 */
    R[3] = lw_(R[4] + 36);  /* 0x800906C4 */
    R[2] = R[2] & R[30];  /* 0x800906C8 */
    R[3] = R[3] & R[21];  /* 0x800906CC */
    R[2] = R[2] | R[3];  /* 0x800906D0 */
    R[3] = R[16] & R[21];  /* 0x800906D4 */
    sw_(R[16], R[2]);  /* 0x800906D8 */
    R[2] = lw_(R[4] + 36);  /* 0x800906DC */
    R[16] = R[16] + 28;  /* 0x800906E0 */
    sw_(R[7] + -24632, R[16]);  /* 0x800906E4 */
    R[2] = R[2] & R[30];  /* 0x800906E8 */
    R[2] = R[2] | R[3];  /* 0x800906EC */
    sw_(R[4] + 36, R[2]);  /* 0x800906F0 */
    R[18] = R[18] + 1;  /* 0x800906F4 */
    R[2] = ((int32_t)R[18] < 16);  /* 0x800906F8 */
    { uint32_t _c = (R[2] != R[0]); R[19] = R[19] + 8; if (_c) { psx_next = 0x80090608u; return; } }  /* 0x800906FC b extern */
    R[20] = R[20] + 68;  /* 0x80090704 */
    R[7] = 0x800Bu << 16;  /* 0x80090708 */
    R[7] = R[7] + 19304;  /* 0x8009070C */
    R[2] = R[7] + 10200;  /* 0x80090710 */
    R[2] = ((int32_t)R[20] < (int32_t)R[2]);  /* 0x80090714 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x800904FCu; return; } }  /* 0x80090718 b extern */
    R[31] = lw_(R[29] + 524);  /* 0x80090720 */
    R[30] = lw_(R[29] + 520);  /* 0x80090724 */
    R[23] = lw_(R[29] + 516);  /* 0x80090728 */
    R[22] = lw_(R[29] + 512);  /* 0x8009072C */
    R[21] = lw_(R[29] + 508);  /* 0x80090730 */
    R[20] = lw_(R[29] + 504);  /* 0x80090734 */
    R[19] = lw_(R[29] + 500);  /* 0x80090738 */
    R[18] = lw_(R[29] + 496);  /* 0x8009073C */
    R[17] = lw_(R[29] + 492);  /* 0x80090740 */
    R[16] = lw_(R[29] + 488);  /* 0x80090744 */
    { R[29] = R[29] + 528; psx_next = R[31]; return; }  /* 0x80090748 jr ra */
}
