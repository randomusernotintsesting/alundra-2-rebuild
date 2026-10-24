#include "event00_decls.h"

void ev_8009EE70(void) {
    { R[4] = R[0] + 7502; goto L_8009EEA4; }  /* 0x8009EE70 j */
    { R[31] = 0x8009EE80u; psx_next = 0x8001D060u; return; }  /* 0x8009EE78 jal */
    R[3] = lw_(R[16] + 13488);  /* 0x8009EE80 */
    R[4] = R[0] + 7502;  /* 0x8009EE84 */
    R[2] = R[3] << 1;  /* 0x8009EE88 */
    R[2] = R[2] + R[3];  /* 0x8009EE8C */
    R[2] = R[2] << 2;  /* 0x8009EE90 */
    R[2] = R[2] + R[3];  /* 0x8009EE94 */
    R[2] = R[2] << 2;  /* 0x8009EE98 */
    R[2] = R[2] + R[17];  /* 0x8009EE9C */
    sh_(R[2] + 2, R[0]);  /* 0x8009EEA0 */
L_8009EEA4:;
    { R[31] = 0x8009EEACu; psx_next = 0x8002DB10u; return; }  /* 0x8009EEA4 jal */
    R[31] = lw_(R[29] + 24);  /* 0x8009EEAC */
    R[17] = lw_(R[29] + 20);  /* 0x8009EEB0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EEB4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009EEB8 jr ra */
}

void ev_8009EE80(void) {
    R[3] = lw_(R[16] + 13488);  /* 0x8009EE80 */
    R[4] = R[0] + 7502;  /* 0x8009EE84 */
    R[2] = R[3] << 1;  /* 0x8009EE88 */
    R[2] = R[2] + R[3];  /* 0x8009EE8C */
    R[2] = R[2] << 2;  /* 0x8009EE90 */
    R[2] = R[2] + R[3];  /* 0x8009EE94 */
    R[2] = R[2] << 2;  /* 0x8009EE98 */
    R[2] = R[2] + R[17];  /* 0x8009EE9C */
    sh_(R[2] + 2, R[0]);  /* 0x8009EEA0 */
    { R[31] = 0x8009EEACu; psx_next = 0x8002DB10u; return; }  /* 0x8009EEA4 jal */
    R[31] = lw_(R[29] + 24);  /* 0x8009EEAC */
    R[17] = lw_(R[29] + 20);  /* 0x8009EEB0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EEB4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009EEB8 jr ra */
}

void ev_8009EEAC(void) {
    R[31] = lw_(R[29] + 24);  /* 0x8009EEAC */
    R[17] = lw_(R[29] + 20);  /* 0x8009EEB0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EEB4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009EEB8 jr ra */
}

void ev_8009EEC0(void) {
    R[2] = 0x800Bu << 16;  /* 0x8009EEC0 */
    R[2] = lw_(R[2] + 13480);  /* 0x8009EEC4 */
    psx_next = 0x8009EEC8u; return;  /* fallthrough */
}

void ev_8009EEC8(void) {
    R[29] = R[29] - 32;  /* 0x8009EEC8 */
    sw_(R[29] + 24, R[31]);  /* 0x8009EECC */
    sw_(R[29] + 20, R[17]);  /* 0x8009EED0 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[29] + 16, R[16]); if (_c) { goto L_8009F014; } }  /* 0x8009EED4 */
    R[2] = 0x800Bu << 16;  /* 0x8009EEDC */
    R[2] = lw_(R[2] + 13652);  /* 0x8009EEE0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F018; } }  /* 0x8009EEE8 */
    R[2] = 0x8006u << 16;  /* 0x8009EEF0 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009EEF4 */
    R[2] = R[2] & 0x4000;  /* 0x8009EEFC */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009EF28; } }  /* 0x8009EF00 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009EF08 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009EF24; } }  /* 0x8009EF10 */
    { R[31] = 0x8009EF20u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009EF18 jal */
    R[2] = R[0] + 1;  /* 0x8009EF20 */
L_8009EF24:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009EF24 */
L_8009EF28:;
    R[2] = 0x8006u << 16;  /* 0x8009EF28 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009EF2C */
    R[2] = R[2] & 0x1000;  /* 0x8009EF34 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009EF5C; } }  /* 0x8009EF38 */
    R[3] = lw_(R[16] + 13488);  /* 0x8009EF40 */
    R[2] = R[0] + 1;  /* 0x8009EF44 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009EF58; } }  /* 0x8009EF48 */
    { R[31] = 0x8009EF58u; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009EF50 jal */
L_8009EF58:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009EF58 */
L_8009EF5C:;
    R[2] = 0x8006u << 16;  /* 0x8009EF5C */
    R[3] = lh_(R[2] + -6452);  /* 0x8009EF60 */
    R[2] = R[3] & 0xA0;  /* 0x8009EF68 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { goto L_8009EFB8; } }  /* 0x8009EF6C */
    { R[31] = 0x8009EF7Cu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009EF74 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009EF7C */
    R[2] = lw_(R[16] + 13488);  /* 0x8009EF80 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009EF98; } }  /* 0x8009EF88 */
    { R[31] = 0x8009EF98u; R[4] = R[0] + R[0]; psx_next = 0x8009BD74u; return; }  /* 0x8009EF90 jal */
L_8009EF98:;
    R[3] = lw_(R[16] + 13488);  /* 0x8009EF98 */
    R[2] = R[0] + 1;  /* 0x8009EF9C */
    { uint32_t _c = (R[3] != R[2]); R[3] = 0x800Fu << 16; if (_c) { goto L_8009EFF8; } }  /* 0x8009EFA0 */
    { R[31] = 0x8009EFB0u; R[4] = R[0] + R[0]; psx_next = 0x8009BD1Cu; return; }  /* 0x8009EFA8 jal */
    { R[3] = 0x800Fu << 16; goto L_8009EFF8; }  /* 0x8009EFB0 j */
L_8009EFB8:;
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x800Fu << 16; if (_c) { goto L_8009EFF8; } }  /* 0x8009EFB8 */
    { R[31] = 0x8009EFC8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009EFC0 jal */
    R[17] = R[0] + R[0];  /* 0x8009EFC8 */
    R[2] = 0x800Fu << 16;  /* 0x8009EFCC */
    R[16] = R[2] - 1904;  /* 0x8009EFD0 */
L_8009EFD4:;
    R[4] = lh_(R[16] + 2);  /* 0x8009EFD4 */
    { R[31] = 0x8009EFE0u; R[17] = R[17] + 1; psx_next = 0x8001D060u; return; }  /* 0x8009EFD8 jal */
    sh_(R[16] + 2, R[0]);  /* 0x8009EFE0 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009EFE4 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 52; if (_c) { psx_bb(); goto L_8009EFD4; } }  /* 0x8009EFE8 */
    { R[2] = R[0] - 1; psx_next = 0x8009F57Cu; return; }  /* 0x8009EFF0 j extern */
L_8009EFF8:;
    R[2] = lb_(R[3] + 27968);  /* 0x8009EFF8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F000 b extern */
    sw_(R[2] + 13060, R[0]);  /* 0x8009F008 */
    { sb_(R[3] + 27968, R[0]); psx_next = 0x8009F578u; return; }  /* 0x8009F00C j extern */
L_8009F014:;
    R[2] = 0x800Bu << 16;  /* 0x8009F014 */
L_8009F018:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F018 */
    R[2] = R[0] + 1;  /* 0x8009F01C */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F08C; } }  /* 0x8009F020 */
    R[2] = 0x800Bu << 16;  /* 0x8009F028 */
    R[2] = lw_(R[2] + 13656);  /* 0x8009F02C */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F08C; } }  /* 0x8009F034 */
    R[2] = 0x8006u << 16;  /* 0x8009F03C */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F040 */
    R[2] = R[3] & 0xA0;  /* 0x8009F048 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { goto L_8009F06C; } }  /* 0x8009F04C */
    { R[31] = 0x8009F05Cu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F054 jal */
    { R[31] = 0x8009F064u; R[4] = R[0] + R[0]; psx_next = 0x8009BD50u; return; }  /* 0x8009F05C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F064 j extern */
L_8009F06C:;
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F06C b extern */
    { R[31] = 0x8009F07Cu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F074 jal */
    { R[31] = 0x8009F084u; R[4] = R[0] + R[0]; psx_next = 0x8009BCA4u; return; }  /* 0x8009F07C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F084 j extern */
L_8009F08C:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F08C */
    R[2] = R[0] + 2;  /* 0x8009F090 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F094 */
    R[2] = 0x800Bu << 16;  /* 0x8009F09C */
    R[2] = lw_(R[2] + 13660);  /* 0x8009F0A0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F0A8 */
    R[2] = 0x8006u << 16;  /* 0x8009F0B0 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F0B4 */
    R[2] = R[3] & 0xA0;  /* 0x8009F0BC */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 2; if (_c) { goto L_8009F0D4; } }  /* 0x8009F0C0 */
    R[2] = R[3] & 0x40;  /* 0x8009F0C8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 3; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F0CC b extern */
L_8009F0D4:;
    { R[31] = 0x8009F0DCu; psx_next = 0x8002DB10u; return; }  /* 0x8009F0D4 jal */
    { R[31] = 0x8009F0E4u; R[4] = R[0] + 1; psx_next = 0x8009BD1Cu; return; }  /* 0x8009F0DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F0E4 j extern */
L_8009F0EC:;
    R[4] = lw_(R[2] + 13480);  /* 0x8009F0EC */
    R[2] = R[0] + 3;  /* 0x8009F0F0 */
    { uint32_t _c = (R[4] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F0F4 */
    R[2] = 0x800Bu << 16;  /* 0x8009F0FC */
    R[2] = lw_(R[2] + 13664);  /* 0x8009F100 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F108 */
    R[5] = 0x800Bu << 16;  /* 0x8009F110 */
    R[3] = lw_(R[5] + 13484);  /* 0x8009F114 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F2EC; } }  /* 0x8009F11C */
    R[2] = 0x800Fu << 16;  /* 0x8009F124 */
    R[2] = lb_(R[2] + 25764);  /* 0x8009F128 */
    { uint32_t _c = (R[2] != R[4]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F130 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F138 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F13C */
    R[2] = R[2] & 0x4000;  /* 0x8009F144 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F180; } }  /* 0x8009F148 */
    { R[31] = 0x8009F158u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F150 jal */
    R[4] = 0x800Bu << 16;  /* 0x8009F158 */
    R[3] = lw_(R[4] + 13488);  /* 0x8009F15C */
    R[2] = ((int32_t)R[3] < 8);  /* 0x8009F164 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_8009F178; } }  /* 0x8009F168 */
    { sw_(R[4] + 13488, R[2]); goto L_8009F17C; }  /* 0x8009F170 j */
L_8009F178:;
    sw_(R[4] + 13488, R[0]);  /* 0x8009F178 */
L_8009F17C:;
    R[2] = 0x8006u << 16;  /* 0x8009F17C */
L_8009F180:;
    R[2] = lh_(R[2] + -6450);  /* 0x8009F180 */
    R[2] = R[2] & 0x1000;  /* 0x8009F188 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F1BC; } }  /* 0x8009F18C */
    { R[31] = 0x8009F19Cu; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F194 jal */
    R[3] = 0x800Bu << 16;  /* 0x8009F19C */
    R[2] = lw_(R[3] + 13488);  /* 0x8009F1A0 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[2] - 1; if (_c) { goto L_8009F1B4; } }  /* 0x8009F1A8 */
    R[2] = R[0] + 8;  /* 0x8009F1B0 */
L_8009F1B4:;
    sw_(R[3] + 13488, R[2]);  /* 0x8009F1B4 */
    R[2] = 0x8006u << 16;  /* 0x8009F1B8 */
L_8009F1BC:;
    R[3] = R[2] - 6456;  /* 0x8009F1BC */
    R[2] = lh_(R[3] + 6);  /* 0x8009F1C0 */
    R[2] = R[2] & 0x2000;  /* 0x8009F1C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F214; } }  /* 0x8009F1CC */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F1D4 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F1DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F218; } }  /* 0x8009F1E0 */
    R[3] = lh_(R[3] + 2);  /* 0x8009F1E8 */
    R[2] = R[3] & 0x8;  /* 0x8009F1F0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F20C; } }  /* 0x8009F1F4 */
    R[2] = R[3] & 0x2;  /* 0x8009F1FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F20C; } }  /* 0x8009F200 */
    R[4] = R[0] + 100;  /* 0x8009F208 */
L_8009F20C:;
    { R[31] = 0x8009F214u; psx_next = 0x8009ECECu; return; }  /* 0x8009F20C jal */
L_8009F214:;
    R[2] = 0x8006u << 16;  /* 0x8009F214 */
L_8009F218:;
    R[3] = R[2] - 6456;  /* 0x8009F218 */
    R[2] = lh_(R[3] + 6);  /* 0x8009F21C */
    R[2] = R[2] & 0x8000;  /* 0x8009F224 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F270; } }  /* 0x8009F228 */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F230 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F238 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F274; } }  /* 0x8009F23C */
    R[3] = lh_(R[3] + 2);  /* 0x8009F244 */
    R[2] = R[3] & 0x8;  /* 0x8009F24C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F268; } }  /* 0x8009F250 */
    R[2] = R[3] & 0x2;  /* 0x8009F258 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    R[4] = R[0] + 100;  /* 0x8009F264 */
L_8009F268:;
    { R[31] = 0x8009F270u; psx_next = 0x8009EE0Cu; return; }  /* 0x8009F268 jal */
L_8009F270:;
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
L_8009F274:;
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
L_8009F2EC:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
L_8009F418:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009EF20(void) {
    R[2] = R[0] + 1;  /* 0x8009EF20 */
    sw_(R[16] + 13488, R[2]);  /* 0x8009EF24 */
    R[2] = 0x8006u << 16;  /* 0x8009EF28 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009EF2C */
    R[2] = R[2] & 0x1000;  /* 0x8009EF34 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009EF5C; } }  /* 0x8009EF38 */
    R[3] = lw_(R[16] + 13488);  /* 0x8009EF40 */
    R[2] = R[0] + 1;  /* 0x8009EF44 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009EF58; } }  /* 0x8009EF48 */
    { R[31] = 0x8009EF58u; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009EF50 jal */
L_8009EF58:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009EF58 */
L_8009EF5C:;
    R[2] = 0x8006u << 16;  /* 0x8009EF5C */
    R[3] = lh_(R[2] + -6452);  /* 0x8009EF60 */
    R[2] = R[3] & 0xA0;  /* 0x8009EF68 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { goto L_8009EFB8; } }  /* 0x8009EF6C */
    { R[31] = 0x8009EF7Cu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009EF74 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009EF7C */
    R[2] = lw_(R[16] + 13488);  /* 0x8009EF80 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009EF98; } }  /* 0x8009EF88 */
    { R[31] = 0x8009EF98u; R[4] = R[0] + R[0]; psx_next = 0x8009BD74u; return; }  /* 0x8009EF90 jal */
L_8009EF98:;
    R[3] = lw_(R[16] + 13488);  /* 0x8009EF98 */
    R[2] = R[0] + 1;  /* 0x8009EF9C */
    { uint32_t _c = (R[3] != R[2]); R[3] = 0x800Fu << 16; if (_c) { goto L_8009EFF8; } }  /* 0x8009EFA0 */
    { R[31] = 0x8009EFB0u; R[4] = R[0] + R[0]; psx_next = 0x8009BD1Cu; return; }  /* 0x8009EFA8 jal */
    { R[3] = 0x800Fu << 16; goto L_8009EFF8; }  /* 0x8009EFB0 j */
L_8009EFB8:;
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x800Fu << 16; if (_c) { goto L_8009EFF8; } }  /* 0x8009EFB8 */
    { R[31] = 0x8009EFC8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009EFC0 jal */
    R[17] = R[0] + R[0];  /* 0x8009EFC8 */
    R[2] = 0x800Fu << 16;  /* 0x8009EFCC */
    R[16] = R[2] - 1904;  /* 0x8009EFD0 */
L_8009EFD4:;
    R[4] = lh_(R[16] + 2);  /* 0x8009EFD4 */
    { R[31] = 0x8009EFE0u; R[17] = R[17] + 1; psx_next = 0x8001D060u; return; }  /* 0x8009EFD8 jal */
    sh_(R[16] + 2, R[0]);  /* 0x8009EFE0 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009EFE4 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 52; if (_c) { psx_bb(); goto L_8009EFD4; } }  /* 0x8009EFE8 */
    { R[2] = R[0] - 1; psx_next = 0x8009F57Cu; return; }  /* 0x8009EFF0 j extern */
L_8009EFF8:;
    R[2] = lb_(R[3] + 27968);  /* 0x8009EFF8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F000 b extern */
    sw_(R[2] + 13060, R[0]);  /* 0x8009F008 */
    { sb_(R[3] + 27968, R[0]); psx_next = 0x8009F578u; return; }  /* 0x8009F00C j extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F014 */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F018 */
    R[2] = R[0] + 1;  /* 0x8009F01C */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F08C; } }  /* 0x8009F020 */
    R[2] = 0x800Bu << 16;  /* 0x8009F028 */
    R[2] = lw_(R[2] + 13656);  /* 0x8009F02C */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F08C; } }  /* 0x8009F034 */
    R[2] = 0x8006u << 16;  /* 0x8009F03C */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F040 */
    R[2] = R[3] & 0xA0;  /* 0x8009F048 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { goto L_8009F06C; } }  /* 0x8009F04C */
    { R[31] = 0x8009F05Cu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F054 jal */
    { R[31] = 0x8009F064u; R[4] = R[0] + R[0]; psx_next = 0x8009BD50u; return; }  /* 0x8009F05C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F064 j extern */
L_8009F06C:;
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F06C b extern */
    { R[31] = 0x8009F07Cu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F074 jal */
    { R[31] = 0x8009F084u; R[4] = R[0] + R[0]; psx_next = 0x8009BCA4u; return; }  /* 0x8009F07C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F084 j extern */
L_8009F08C:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F08C */
    R[2] = R[0] + 2;  /* 0x8009F090 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F094 */
    R[2] = 0x800Bu << 16;  /* 0x8009F09C */
    R[2] = lw_(R[2] + 13660);  /* 0x8009F0A0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F0A8 */
    R[2] = 0x8006u << 16;  /* 0x8009F0B0 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F0B4 */
    R[2] = R[3] & 0xA0;  /* 0x8009F0BC */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 2; if (_c) { goto L_8009F0D4; } }  /* 0x8009F0C0 */
    R[2] = R[3] & 0x40;  /* 0x8009F0C8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 3; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F0CC b extern */
L_8009F0D4:;
    { R[31] = 0x8009F0DCu; psx_next = 0x8002DB10u; return; }  /* 0x8009F0D4 jal */
    { R[31] = 0x8009F0E4u; R[4] = R[0] + 1; psx_next = 0x8009BD1Cu; return; }  /* 0x8009F0DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F0E4 j extern */
L_8009F0EC:;
    R[4] = lw_(R[2] + 13480);  /* 0x8009F0EC */
    R[2] = R[0] + 3;  /* 0x8009F0F0 */
    { uint32_t _c = (R[4] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F0F4 */
    R[2] = 0x800Bu << 16;  /* 0x8009F0FC */
    R[2] = lw_(R[2] + 13664);  /* 0x8009F100 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F108 */
    R[5] = 0x800Bu << 16;  /* 0x8009F110 */
    R[3] = lw_(R[5] + 13484);  /* 0x8009F114 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F2EC; } }  /* 0x8009F11C */
    R[2] = 0x800Fu << 16;  /* 0x8009F124 */
    R[2] = lb_(R[2] + 25764);  /* 0x8009F128 */
    { uint32_t _c = (R[2] != R[4]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F130 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F138 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F13C */
    R[2] = R[2] & 0x4000;  /* 0x8009F144 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F180; } }  /* 0x8009F148 */
    { R[31] = 0x8009F158u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F150 jal */
    R[4] = 0x800Bu << 16;  /* 0x8009F158 */
    R[3] = lw_(R[4] + 13488);  /* 0x8009F15C */
    R[2] = ((int32_t)R[3] < 8);  /* 0x8009F164 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_8009F178; } }  /* 0x8009F168 */
    { sw_(R[4] + 13488, R[2]); goto L_8009F17C; }  /* 0x8009F170 j */
L_8009F178:;
    sw_(R[4] + 13488, R[0]);  /* 0x8009F178 */
L_8009F17C:;
    R[2] = 0x8006u << 16;  /* 0x8009F17C */
L_8009F180:;
    R[2] = lh_(R[2] + -6450);  /* 0x8009F180 */
    R[2] = R[2] & 0x1000;  /* 0x8009F188 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F1BC; } }  /* 0x8009F18C */
    { R[31] = 0x8009F19Cu; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F194 jal */
    R[3] = 0x800Bu << 16;  /* 0x8009F19C */
    R[2] = lw_(R[3] + 13488);  /* 0x8009F1A0 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[2] - 1; if (_c) { goto L_8009F1B4; } }  /* 0x8009F1A8 */
    R[2] = R[0] + 8;  /* 0x8009F1B0 */
L_8009F1B4:;
    sw_(R[3] + 13488, R[2]);  /* 0x8009F1B4 */
    R[2] = 0x8006u << 16;  /* 0x8009F1B8 */
L_8009F1BC:;
    R[3] = R[2] - 6456;  /* 0x8009F1BC */
    R[2] = lh_(R[3] + 6);  /* 0x8009F1C0 */
    R[2] = R[2] & 0x2000;  /* 0x8009F1C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F214; } }  /* 0x8009F1CC */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F1D4 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F1DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F218; } }  /* 0x8009F1E0 */
    R[3] = lh_(R[3] + 2);  /* 0x8009F1E8 */
    R[2] = R[3] & 0x8;  /* 0x8009F1F0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F20C; } }  /* 0x8009F1F4 */
    R[2] = R[3] & 0x2;  /* 0x8009F1FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F20C; } }  /* 0x8009F200 */
    R[4] = R[0] + 100;  /* 0x8009F208 */
L_8009F20C:;
    { R[31] = 0x8009F214u; psx_next = 0x8009ECECu; return; }  /* 0x8009F20C jal */
L_8009F214:;
    R[2] = 0x8006u << 16;  /* 0x8009F214 */
L_8009F218:;
    R[3] = R[2] - 6456;  /* 0x8009F218 */
    R[2] = lh_(R[3] + 6);  /* 0x8009F21C */
    R[2] = R[2] & 0x8000;  /* 0x8009F224 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F270; } }  /* 0x8009F228 */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F230 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F238 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F274; } }  /* 0x8009F23C */
    R[3] = lh_(R[3] + 2);  /* 0x8009F244 */
    R[2] = R[3] & 0x8;  /* 0x8009F24C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F268; } }  /* 0x8009F250 */
    R[2] = R[3] & 0x2;  /* 0x8009F258 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    R[4] = R[0] + 100;  /* 0x8009F264 */
L_8009F268:;
    { R[31] = 0x8009F270u; psx_next = 0x8009EE0Cu; return; }  /* 0x8009F268 jal */
L_8009F270:;
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
L_8009F274:;
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
L_8009F2EC:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
L_8009F418:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009EF58(void) {
    sw_(R[16] + 13488, R[0]);  /* 0x8009EF58 */
    R[2] = 0x8006u << 16;  /* 0x8009EF5C */
    R[3] = lh_(R[2] + -6452);  /* 0x8009EF60 */
    R[2] = R[3] & 0xA0;  /* 0x8009EF68 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { goto L_8009EFB8; } }  /* 0x8009EF6C */
    { R[31] = 0x8009EF7Cu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009EF74 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009EF7C */
    R[2] = lw_(R[16] + 13488);  /* 0x8009EF80 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009EF98; } }  /* 0x8009EF88 */
    { R[31] = 0x8009EF98u; R[4] = R[0] + R[0]; psx_next = 0x8009BD74u; return; }  /* 0x8009EF90 jal */
L_8009EF98:;
    R[3] = lw_(R[16] + 13488);  /* 0x8009EF98 */
    R[2] = R[0] + 1;  /* 0x8009EF9C */
    { uint32_t _c = (R[3] != R[2]); R[3] = 0x800Fu << 16; if (_c) { goto L_8009EFF8; } }  /* 0x8009EFA0 */
    { R[31] = 0x8009EFB0u; R[4] = R[0] + R[0]; psx_next = 0x8009BD1Cu; return; }  /* 0x8009EFA8 jal */
    { R[3] = 0x800Fu << 16; goto L_8009EFF8; }  /* 0x8009EFB0 j */
L_8009EFB8:;
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x800Fu << 16; if (_c) { goto L_8009EFF8; } }  /* 0x8009EFB8 */
    { R[31] = 0x8009EFC8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009EFC0 jal */
    R[17] = R[0] + R[0];  /* 0x8009EFC8 */
    R[2] = 0x800Fu << 16;  /* 0x8009EFCC */
    R[16] = R[2] - 1904;  /* 0x8009EFD0 */
L_8009EFD4:;
    R[4] = lh_(R[16] + 2);  /* 0x8009EFD4 */
    { R[31] = 0x8009EFE0u; R[17] = R[17] + 1; psx_next = 0x8001D060u; return; }  /* 0x8009EFD8 jal */
    sh_(R[16] + 2, R[0]);  /* 0x8009EFE0 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009EFE4 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 52; if (_c) { psx_bb(); goto L_8009EFD4; } }  /* 0x8009EFE8 */
    { R[2] = R[0] - 1; psx_next = 0x8009F57Cu; return; }  /* 0x8009EFF0 j extern */
L_8009EFF8:;
    R[2] = lb_(R[3] + 27968);  /* 0x8009EFF8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F000 b extern */
    sw_(R[2] + 13060, R[0]);  /* 0x8009F008 */
    { sb_(R[3] + 27968, R[0]); psx_next = 0x8009F578u; return; }  /* 0x8009F00C j extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F014 */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F018 */
    R[2] = R[0] + 1;  /* 0x8009F01C */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F08C; } }  /* 0x8009F020 */
    R[2] = 0x800Bu << 16;  /* 0x8009F028 */
    R[2] = lw_(R[2] + 13656);  /* 0x8009F02C */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F08C; } }  /* 0x8009F034 */
    R[2] = 0x8006u << 16;  /* 0x8009F03C */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F040 */
    R[2] = R[3] & 0xA0;  /* 0x8009F048 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { goto L_8009F06C; } }  /* 0x8009F04C */
    { R[31] = 0x8009F05Cu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F054 jal */
    { R[31] = 0x8009F064u; R[4] = R[0] + R[0]; psx_next = 0x8009BD50u; return; }  /* 0x8009F05C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F064 j extern */
L_8009F06C:;
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F06C b extern */
    { R[31] = 0x8009F07Cu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F074 jal */
    { R[31] = 0x8009F084u; R[4] = R[0] + R[0]; psx_next = 0x8009BCA4u; return; }  /* 0x8009F07C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F084 j extern */
L_8009F08C:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F08C */
    R[2] = R[0] + 2;  /* 0x8009F090 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F094 */
    R[2] = 0x800Bu << 16;  /* 0x8009F09C */
    R[2] = lw_(R[2] + 13660);  /* 0x8009F0A0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F0A8 */
    R[2] = 0x8006u << 16;  /* 0x8009F0B0 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F0B4 */
    R[2] = R[3] & 0xA0;  /* 0x8009F0BC */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 2; if (_c) { goto L_8009F0D4; } }  /* 0x8009F0C0 */
    R[2] = R[3] & 0x40;  /* 0x8009F0C8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 3; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F0CC b extern */
L_8009F0D4:;
    { R[31] = 0x8009F0DCu; psx_next = 0x8002DB10u; return; }  /* 0x8009F0D4 jal */
    { R[31] = 0x8009F0E4u; R[4] = R[0] + 1; psx_next = 0x8009BD1Cu; return; }  /* 0x8009F0DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F0E4 j extern */
L_8009F0EC:;
    R[4] = lw_(R[2] + 13480);  /* 0x8009F0EC */
    R[2] = R[0] + 3;  /* 0x8009F0F0 */
    { uint32_t _c = (R[4] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F0F4 */
    R[2] = 0x800Bu << 16;  /* 0x8009F0FC */
    R[2] = lw_(R[2] + 13664);  /* 0x8009F100 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F108 */
    R[5] = 0x800Bu << 16;  /* 0x8009F110 */
    R[3] = lw_(R[5] + 13484);  /* 0x8009F114 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F2EC; } }  /* 0x8009F11C */
    R[2] = 0x800Fu << 16;  /* 0x8009F124 */
    R[2] = lb_(R[2] + 25764);  /* 0x8009F128 */
    { uint32_t _c = (R[2] != R[4]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F130 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F138 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F13C */
    R[2] = R[2] & 0x4000;  /* 0x8009F144 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F180; } }  /* 0x8009F148 */
    { R[31] = 0x8009F158u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F150 jal */
    R[4] = 0x800Bu << 16;  /* 0x8009F158 */
    R[3] = lw_(R[4] + 13488);  /* 0x8009F15C */
    R[2] = ((int32_t)R[3] < 8);  /* 0x8009F164 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_8009F178; } }  /* 0x8009F168 */
    { sw_(R[4] + 13488, R[2]); goto L_8009F17C; }  /* 0x8009F170 j */
L_8009F178:;
    sw_(R[4] + 13488, R[0]);  /* 0x8009F178 */
L_8009F17C:;
    R[2] = 0x8006u << 16;  /* 0x8009F17C */
L_8009F180:;
    R[2] = lh_(R[2] + -6450);  /* 0x8009F180 */
    R[2] = R[2] & 0x1000;  /* 0x8009F188 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F1BC; } }  /* 0x8009F18C */
    { R[31] = 0x8009F19Cu; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F194 jal */
    R[3] = 0x800Bu << 16;  /* 0x8009F19C */
    R[2] = lw_(R[3] + 13488);  /* 0x8009F1A0 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[2] - 1; if (_c) { goto L_8009F1B4; } }  /* 0x8009F1A8 */
    R[2] = R[0] + 8;  /* 0x8009F1B0 */
L_8009F1B4:;
    sw_(R[3] + 13488, R[2]);  /* 0x8009F1B4 */
    R[2] = 0x8006u << 16;  /* 0x8009F1B8 */
L_8009F1BC:;
    R[3] = R[2] - 6456;  /* 0x8009F1BC */
    R[2] = lh_(R[3] + 6);  /* 0x8009F1C0 */
    R[2] = R[2] & 0x2000;  /* 0x8009F1C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F214; } }  /* 0x8009F1CC */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F1D4 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F1DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F218; } }  /* 0x8009F1E0 */
    R[3] = lh_(R[3] + 2);  /* 0x8009F1E8 */
    R[2] = R[3] & 0x8;  /* 0x8009F1F0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F20C; } }  /* 0x8009F1F4 */
    R[2] = R[3] & 0x2;  /* 0x8009F1FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F20C; } }  /* 0x8009F200 */
    R[4] = R[0] + 100;  /* 0x8009F208 */
L_8009F20C:;
    { R[31] = 0x8009F214u; psx_next = 0x8009ECECu; return; }  /* 0x8009F20C jal */
L_8009F214:;
    R[2] = 0x8006u << 16;  /* 0x8009F214 */
L_8009F218:;
    R[3] = R[2] - 6456;  /* 0x8009F218 */
    R[2] = lh_(R[3] + 6);  /* 0x8009F21C */
    R[2] = R[2] & 0x8000;  /* 0x8009F224 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F270; } }  /* 0x8009F228 */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F230 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F238 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F274; } }  /* 0x8009F23C */
    R[3] = lh_(R[3] + 2);  /* 0x8009F244 */
    R[2] = R[3] & 0x8;  /* 0x8009F24C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F268; } }  /* 0x8009F250 */
    R[2] = R[3] & 0x2;  /* 0x8009F258 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    R[4] = R[0] + 100;  /* 0x8009F264 */
L_8009F268:;
    { R[31] = 0x8009F270u; psx_next = 0x8009EE0Cu; return; }  /* 0x8009F268 jal */
L_8009F270:;
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
L_8009F274:;
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
L_8009F2EC:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
L_8009F418:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009EF7C(void) {
    R[16] = 0x800Bu << 16;  /* 0x8009EF7C */
    R[2] = lw_(R[16] + 13488);  /* 0x8009EF80 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009EF98; } }  /* 0x8009EF88 */
    { R[31] = 0x8009EF98u; R[4] = R[0] + R[0]; psx_next = 0x8009BD74u; return; }  /* 0x8009EF90 jal */
L_8009EF98:;
    R[3] = lw_(R[16] + 13488);  /* 0x8009EF98 */
    R[2] = R[0] + 1;  /* 0x8009EF9C */
    { uint32_t _c = (R[3] != R[2]); R[3] = 0x800Fu << 16; if (_c) { goto L_8009EFF8; } }  /* 0x8009EFA0 */
    { R[31] = 0x8009EFB0u; R[4] = R[0] + R[0]; psx_next = 0x8009BD1Cu; return; }  /* 0x8009EFA8 jal */
    { R[3] = 0x800Fu << 16; goto L_8009EFF8; }  /* 0x8009EFB0 j */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x800Fu << 16; if (_c) { goto L_8009EFF8; } }  /* 0x8009EFB8 */
    { R[31] = 0x8009EFC8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009EFC0 jal */
    R[17] = R[0] + R[0];  /* 0x8009EFC8 */
    R[2] = 0x800Fu << 16;  /* 0x8009EFCC */
    R[16] = R[2] - 1904;  /* 0x8009EFD0 */
L_8009EFD4:;
    R[4] = lh_(R[16] + 2);  /* 0x8009EFD4 */
    { R[31] = 0x8009EFE0u; R[17] = R[17] + 1; psx_next = 0x8001D060u; return; }  /* 0x8009EFD8 jal */
    sh_(R[16] + 2, R[0]);  /* 0x8009EFE0 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009EFE4 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 52; if (_c) { psx_bb(); goto L_8009EFD4; } }  /* 0x8009EFE8 */
    { R[2] = R[0] - 1; psx_next = 0x8009F57Cu; return; }  /* 0x8009EFF0 j extern */
L_8009EFF8:;
    R[2] = lb_(R[3] + 27968);  /* 0x8009EFF8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F000 b extern */
    sw_(R[2] + 13060, R[0]);  /* 0x8009F008 */
    { sb_(R[3] + 27968, R[0]); psx_next = 0x8009F578u; return; }  /* 0x8009F00C j extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F014 */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F018 */
    R[2] = R[0] + 1;  /* 0x8009F01C */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F08C; } }  /* 0x8009F020 */
    R[2] = 0x800Bu << 16;  /* 0x8009F028 */
    R[2] = lw_(R[2] + 13656);  /* 0x8009F02C */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F08C; } }  /* 0x8009F034 */
    R[2] = 0x8006u << 16;  /* 0x8009F03C */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F040 */
    R[2] = R[3] & 0xA0;  /* 0x8009F048 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { goto L_8009F06C; } }  /* 0x8009F04C */
    { R[31] = 0x8009F05Cu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F054 jal */
    { R[31] = 0x8009F064u; R[4] = R[0] + R[0]; psx_next = 0x8009BD50u; return; }  /* 0x8009F05C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F064 j extern */
L_8009F06C:;
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F06C b extern */
    { R[31] = 0x8009F07Cu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F074 jal */
    { R[31] = 0x8009F084u; R[4] = R[0] + R[0]; psx_next = 0x8009BCA4u; return; }  /* 0x8009F07C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F084 j extern */
L_8009F08C:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F08C */
    R[2] = R[0] + 2;  /* 0x8009F090 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F094 */
    R[2] = 0x800Bu << 16;  /* 0x8009F09C */
    R[2] = lw_(R[2] + 13660);  /* 0x8009F0A0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F0A8 */
    R[2] = 0x8006u << 16;  /* 0x8009F0B0 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F0B4 */
    R[2] = R[3] & 0xA0;  /* 0x8009F0BC */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 2; if (_c) { goto L_8009F0D4; } }  /* 0x8009F0C0 */
    R[2] = R[3] & 0x40;  /* 0x8009F0C8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 3; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F0CC b extern */
L_8009F0D4:;
    { R[31] = 0x8009F0DCu; psx_next = 0x8002DB10u; return; }  /* 0x8009F0D4 jal */
    { R[31] = 0x8009F0E4u; R[4] = R[0] + 1; psx_next = 0x8009BD1Cu; return; }  /* 0x8009F0DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F0E4 j extern */
L_8009F0EC:;
    R[4] = lw_(R[2] + 13480);  /* 0x8009F0EC */
    R[2] = R[0] + 3;  /* 0x8009F0F0 */
    { uint32_t _c = (R[4] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F0F4 */
    R[2] = 0x800Bu << 16;  /* 0x8009F0FC */
    R[2] = lw_(R[2] + 13664);  /* 0x8009F100 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F108 */
    R[5] = 0x800Bu << 16;  /* 0x8009F110 */
    R[3] = lw_(R[5] + 13484);  /* 0x8009F114 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F2EC; } }  /* 0x8009F11C */
    R[2] = 0x800Fu << 16;  /* 0x8009F124 */
    R[2] = lb_(R[2] + 25764);  /* 0x8009F128 */
    { uint32_t _c = (R[2] != R[4]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F130 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F138 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F13C */
    R[2] = R[2] & 0x4000;  /* 0x8009F144 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F180; } }  /* 0x8009F148 */
    { R[31] = 0x8009F158u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F150 jal */
    R[4] = 0x800Bu << 16;  /* 0x8009F158 */
    R[3] = lw_(R[4] + 13488);  /* 0x8009F15C */
    R[2] = ((int32_t)R[3] < 8);  /* 0x8009F164 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_8009F178; } }  /* 0x8009F168 */
    { sw_(R[4] + 13488, R[2]); goto L_8009F17C; }  /* 0x8009F170 j */
L_8009F178:;
    sw_(R[4] + 13488, R[0]);  /* 0x8009F178 */
L_8009F17C:;
    R[2] = 0x8006u << 16;  /* 0x8009F17C */
L_8009F180:;
    R[2] = lh_(R[2] + -6450);  /* 0x8009F180 */
    R[2] = R[2] & 0x1000;  /* 0x8009F188 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F1BC; } }  /* 0x8009F18C */
    { R[31] = 0x8009F19Cu; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F194 jal */
    R[3] = 0x800Bu << 16;  /* 0x8009F19C */
    R[2] = lw_(R[3] + 13488);  /* 0x8009F1A0 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[2] - 1; if (_c) { goto L_8009F1B4; } }  /* 0x8009F1A8 */
    R[2] = R[0] + 8;  /* 0x8009F1B0 */
L_8009F1B4:;
    sw_(R[3] + 13488, R[2]);  /* 0x8009F1B4 */
    R[2] = 0x8006u << 16;  /* 0x8009F1B8 */
L_8009F1BC:;
    R[3] = R[2] - 6456;  /* 0x8009F1BC */
    R[2] = lh_(R[3] + 6);  /* 0x8009F1C0 */
    R[2] = R[2] & 0x2000;  /* 0x8009F1C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F214; } }  /* 0x8009F1CC */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F1D4 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F1DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F218; } }  /* 0x8009F1E0 */
    R[3] = lh_(R[3] + 2);  /* 0x8009F1E8 */
    R[2] = R[3] & 0x8;  /* 0x8009F1F0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F20C; } }  /* 0x8009F1F4 */
    R[2] = R[3] & 0x2;  /* 0x8009F1FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F20C; } }  /* 0x8009F200 */
    R[4] = R[0] + 100;  /* 0x8009F208 */
L_8009F20C:;
    { R[31] = 0x8009F214u; psx_next = 0x8009ECECu; return; }  /* 0x8009F20C jal */
L_8009F214:;
    R[2] = 0x8006u << 16;  /* 0x8009F214 */
L_8009F218:;
    R[3] = R[2] - 6456;  /* 0x8009F218 */
    R[2] = lh_(R[3] + 6);  /* 0x8009F21C */
    R[2] = R[2] & 0x8000;  /* 0x8009F224 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F270; } }  /* 0x8009F228 */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F230 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F238 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F274; } }  /* 0x8009F23C */
    R[3] = lh_(R[3] + 2);  /* 0x8009F244 */
    R[2] = R[3] & 0x8;  /* 0x8009F24C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F268; } }  /* 0x8009F250 */
    R[2] = R[3] & 0x2;  /* 0x8009F258 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    R[4] = R[0] + 100;  /* 0x8009F264 */
L_8009F268:;
    { R[31] = 0x8009F270u; psx_next = 0x8009EE0Cu; return; }  /* 0x8009F268 jal */
L_8009F270:;
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
L_8009F274:;
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
L_8009F2EC:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
L_8009F418:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009EF98(void) {
    R[3] = lw_(R[16] + 13488);  /* 0x8009EF98 */
    R[2] = R[0] + 1;  /* 0x8009EF9C */
    { uint32_t _c = (R[3] != R[2]); R[3] = 0x800Fu << 16; if (_c) { goto L_8009EFF8; } }  /* 0x8009EFA0 */
    { R[31] = 0x8009EFB0u; R[4] = R[0] + R[0]; psx_next = 0x8009BD1Cu; return; }  /* 0x8009EFA8 jal */
    { R[3] = 0x800Fu << 16; goto L_8009EFF8; }  /* 0x8009EFB0 j */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x800Fu << 16; if (_c) { goto L_8009EFF8; } }  /* 0x8009EFB8 */
    { R[31] = 0x8009EFC8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009EFC0 jal */
    R[17] = R[0] + R[0];  /* 0x8009EFC8 */
    R[2] = 0x800Fu << 16;  /* 0x8009EFCC */
    R[16] = R[2] - 1904;  /* 0x8009EFD0 */
L_8009EFD4:;
    R[4] = lh_(R[16] + 2);  /* 0x8009EFD4 */
    { R[31] = 0x8009EFE0u; R[17] = R[17] + 1; psx_next = 0x8001D060u; return; }  /* 0x8009EFD8 jal */
    sh_(R[16] + 2, R[0]);  /* 0x8009EFE0 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009EFE4 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 52; if (_c) { psx_bb(); goto L_8009EFD4; } }  /* 0x8009EFE8 */
    { R[2] = R[0] - 1; psx_next = 0x8009F57Cu; return; }  /* 0x8009EFF0 j extern */
L_8009EFF8:;
    R[2] = lb_(R[3] + 27968);  /* 0x8009EFF8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F000 b extern */
    sw_(R[2] + 13060, R[0]);  /* 0x8009F008 */
    { sb_(R[3] + 27968, R[0]); psx_next = 0x8009F578u; return; }  /* 0x8009F00C j extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F014 */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F018 */
    R[2] = R[0] + 1;  /* 0x8009F01C */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F08C; } }  /* 0x8009F020 */
    R[2] = 0x800Bu << 16;  /* 0x8009F028 */
    R[2] = lw_(R[2] + 13656);  /* 0x8009F02C */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F08C; } }  /* 0x8009F034 */
    R[2] = 0x8006u << 16;  /* 0x8009F03C */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F040 */
    R[2] = R[3] & 0xA0;  /* 0x8009F048 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { goto L_8009F06C; } }  /* 0x8009F04C */
    { R[31] = 0x8009F05Cu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F054 jal */
    { R[31] = 0x8009F064u; R[4] = R[0] + R[0]; psx_next = 0x8009BD50u; return; }  /* 0x8009F05C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F064 j extern */
L_8009F06C:;
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F06C b extern */
    { R[31] = 0x8009F07Cu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F074 jal */
    { R[31] = 0x8009F084u; R[4] = R[0] + R[0]; psx_next = 0x8009BCA4u; return; }  /* 0x8009F07C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F084 j extern */
L_8009F08C:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F08C */
    R[2] = R[0] + 2;  /* 0x8009F090 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F094 */
    R[2] = 0x800Bu << 16;  /* 0x8009F09C */
    R[2] = lw_(R[2] + 13660);  /* 0x8009F0A0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F0A8 */
    R[2] = 0x8006u << 16;  /* 0x8009F0B0 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F0B4 */
    R[2] = R[3] & 0xA0;  /* 0x8009F0BC */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 2; if (_c) { goto L_8009F0D4; } }  /* 0x8009F0C0 */
    R[2] = R[3] & 0x40;  /* 0x8009F0C8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 3; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F0CC b extern */
L_8009F0D4:;
    { R[31] = 0x8009F0DCu; psx_next = 0x8002DB10u; return; }  /* 0x8009F0D4 jal */
    { R[31] = 0x8009F0E4u; R[4] = R[0] + 1; psx_next = 0x8009BD1Cu; return; }  /* 0x8009F0DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F0E4 j extern */
L_8009F0EC:;
    R[4] = lw_(R[2] + 13480);  /* 0x8009F0EC */
    R[2] = R[0] + 3;  /* 0x8009F0F0 */
    { uint32_t _c = (R[4] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F0F4 */
    R[2] = 0x800Bu << 16;  /* 0x8009F0FC */
    R[2] = lw_(R[2] + 13664);  /* 0x8009F100 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F108 */
    R[5] = 0x800Bu << 16;  /* 0x8009F110 */
    R[3] = lw_(R[5] + 13484);  /* 0x8009F114 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F2EC; } }  /* 0x8009F11C */
    R[2] = 0x800Fu << 16;  /* 0x8009F124 */
    R[2] = lb_(R[2] + 25764);  /* 0x8009F128 */
    { uint32_t _c = (R[2] != R[4]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F130 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F138 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F13C */
    R[2] = R[2] & 0x4000;  /* 0x8009F144 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F180; } }  /* 0x8009F148 */
    { R[31] = 0x8009F158u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F150 jal */
    R[4] = 0x800Bu << 16;  /* 0x8009F158 */
    R[3] = lw_(R[4] + 13488);  /* 0x8009F15C */
    R[2] = ((int32_t)R[3] < 8);  /* 0x8009F164 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_8009F178; } }  /* 0x8009F168 */
    { sw_(R[4] + 13488, R[2]); goto L_8009F17C; }  /* 0x8009F170 j */
L_8009F178:;
    sw_(R[4] + 13488, R[0]);  /* 0x8009F178 */
L_8009F17C:;
    R[2] = 0x8006u << 16;  /* 0x8009F17C */
L_8009F180:;
    R[2] = lh_(R[2] + -6450);  /* 0x8009F180 */
    R[2] = R[2] & 0x1000;  /* 0x8009F188 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F1BC; } }  /* 0x8009F18C */
    { R[31] = 0x8009F19Cu; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F194 jal */
    R[3] = 0x800Bu << 16;  /* 0x8009F19C */
    R[2] = lw_(R[3] + 13488);  /* 0x8009F1A0 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[2] - 1; if (_c) { goto L_8009F1B4; } }  /* 0x8009F1A8 */
    R[2] = R[0] + 8;  /* 0x8009F1B0 */
L_8009F1B4:;
    sw_(R[3] + 13488, R[2]);  /* 0x8009F1B4 */
    R[2] = 0x8006u << 16;  /* 0x8009F1B8 */
L_8009F1BC:;
    R[3] = R[2] - 6456;  /* 0x8009F1BC */
    R[2] = lh_(R[3] + 6);  /* 0x8009F1C0 */
    R[2] = R[2] & 0x2000;  /* 0x8009F1C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F214; } }  /* 0x8009F1CC */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F1D4 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F1DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F218; } }  /* 0x8009F1E0 */
    R[3] = lh_(R[3] + 2);  /* 0x8009F1E8 */
    R[2] = R[3] & 0x8;  /* 0x8009F1F0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F20C; } }  /* 0x8009F1F4 */
    R[2] = R[3] & 0x2;  /* 0x8009F1FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F20C; } }  /* 0x8009F200 */
    R[4] = R[0] + 100;  /* 0x8009F208 */
L_8009F20C:;
    { R[31] = 0x8009F214u; psx_next = 0x8009ECECu; return; }  /* 0x8009F20C jal */
L_8009F214:;
    R[2] = 0x8006u << 16;  /* 0x8009F214 */
L_8009F218:;
    R[3] = R[2] - 6456;  /* 0x8009F218 */
    R[2] = lh_(R[3] + 6);  /* 0x8009F21C */
    R[2] = R[2] & 0x8000;  /* 0x8009F224 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F270; } }  /* 0x8009F228 */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F230 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F238 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F274; } }  /* 0x8009F23C */
    R[3] = lh_(R[3] + 2);  /* 0x8009F244 */
    R[2] = R[3] & 0x8;  /* 0x8009F24C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F268; } }  /* 0x8009F250 */
    R[2] = R[3] & 0x2;  /* 0x8009F258 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    R[4] = R[0] + 100;  /* 0x8009F264 */
L_8009F268:;
    { R[31] = 0x8009F270u; psx_next = 0x8009EE0Cu; return; }  /* 0x8009F268 jal */
L_8009F270:;
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
L_8009F274:;
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
L_8009F2EC:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
L_8009F418:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009EFB0(void) {
    { R[3] = 0x800Fu << 16; goto L_8009EFF8; }  /* 0x8009EFB0 j */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x800Fu << 16; if (_c) { goto L_8009EFF8; } }  /* 0x8009EFB8 */
    { R[31] = 0x8009EFC8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009EFC0 jal */
    R[17] = R[0] + R[0];  /* 0x8009EFC8 */
    R[2] = 0x800Fu << 16;  /* 0x8009EFCC */
    R[16] = R[2] - 1904;  /* 0x8009EFD0 */
L_8009EFD4:;
    R[4] = lh_(R[16] + 2);  /* 0x8009EFD4 */
    { R[31] = 0x8009EFE0u; R[17] = R[17] + 1; psx_next = 0x8001D060u; return; }  /* 0x8009EFD8 jal */
    sh_(R[16] + 2, R[0]);  /* 0x8009EFE0 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009EFE4 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 52; if (_c) { psx_bb(); goto L_8009EFD4; } }  /* 0x8009EFE8 */
    { R[2] = R[0] - 1; psx_next = 0x8009F57Cu; return; }  /* 0x8009EFF0 j extern */
L_8009EFF8:;
    R[2] = lb_(R[3] + 27968);  /* 0x8009EFF8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F000 b extern */
    sw_(R[2] + 13060, R[0]);  /* 0x8009F008 */
    { sb_(R[3] + 27968, R[0]); psx_next = 0x8009F578u; return; }  /* 0x8009F00C j extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F014 */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F018 */
    R[2] = R[0] + 1;  /* 0x8009F01C */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F08C; } }  /* 0x8009F020 */
    R[2] = 0x800Bu << 16;  /* 0x8009F028 */
    R[2] = lw_(R[2] + 13656);  /* 0x8009F02C */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F08C; } }  /* 0x8009F034 */
    R[2] = 0x8006u << 16;  /* 0x8009F03C */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F040 */
    R[2] = R[3] & 0xA0;  /* 0x8009F048 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { goto L_8009F06C; } }  /* 0x8009F04C */
    { R[31] = 0x8009F05Cu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F054 jal */
    { R[31] = 0x8009F064u; R[4] = R[0] + R[0]; psx_next = 0x8009BD50u; return; }  /* 0x8009F05C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F064 j extern */
L_8009F06C:;
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F06C b extern */
    { R[31] = 0x8009F07Cu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F074 jal */
    { R[31] = 0x8009F084u; R[4] = R[0] + R[0]; psx_next = 0x8009BCA4u; return; }  /* 0x8009F07C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F084 j extern */
L_8009F08C:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F08C */
    R[2] = R[0] + 2;  /* 0x8009F090 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F094 */
    R[2] = 0x800Bu << 16;  /* 0x8009F09C */
    R[2] = lw_(R[2] + 13660);  /* 0x8009F0A0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F0A8 */
    R[2] = 0x8006u << 16;  /* 0x8009F0B0 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F0B4 */
    R[2] = R[3] & 0xA0;  /* 0x8009F0BC */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 2; if (_c) { goto L_8009F0D4; } }  /* 0x8009F0C0 */
    R[2] = R[3] & 0x40;  /* 0x8009F0C8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 3; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F0CC b extern */
L_8009F0D4:;
    { R[31] = 0x8009F0DCu; psx_next = 0x8002DB10u; return; }  /* 0x8009F0D4 jal */
    { R[31] = 0x8009F0E4u; R[4] = R[0] + 1; psx_next = 0x8009BD1Cu; return; }  /* 0x8009F0DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F0E4 j extern */
L_8009F0EC:;
    R[4] = lw_(R[2] + 13480);  /* 0x8009F0EC */
    R[2] = R[0] + 3;  /* 0x8009F0F0 */
    { uint32_t _c = (R[4] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F0F4 */
    R[2] = 0x800Bu << 16;  /* 0x8009F0FC */
    R[2] = lw_(R[2] + 13664);  /* 0x8009F100 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F108 */
    R[5] = 0x800Bu << 16;  /* 0x8009F110 */
    R[3] = lw_(R[5] + 13484);  /* 0x8009F114 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F2EC; } }  /* 0x8009F11C */
    R[2] = 0x800Fu << 16;  /* 0x8009F124 */
    R[2] = lb_(R[2] + 25764);  /* 0x8009F128 */
    { uint32_t _c = (R[2] != R[4]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F130 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F138 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F13C */
    R[2] = R[2] & 0x4000;  /* 0x8009F144 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F180; } }  /* 0x8009F148 */
    { R[31] = 0x8009F158u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F150 jal */
    R[4] = 0x800Bu << 16;  /* 0x8009F158 */
    R[3] = lw_(R[4] + 13488);  /* 0x8009F15C */
    R[2] = ((int32_t)R[3] < 8);  /* 0x8009F164 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_8009F178; } }  /* 0x8009F168 */
    { sw_(R[4] + 13488, R[2]); goto L_8009F17C; }  /* 0x8009F170 j */
L_8009F178:;
    sw_(R[4] + 13488, R[0]);  /* 0x8009F178 */
L_8009F17C:;
    R[2] = 0x8006u << 16;  /* 0x8009F17C */
L_8009F180:;
    R[2] = lh_(R[2] + -6450);  /* 0x8009F180 */
    R[2] = R[2] & 0x1000;  /* 0x8009F188 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F1BC; } }  /* 0x8009F18C */
    { R[31] = 0x8009F19Cu; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F194 jal */
    R[3] = 0x800Bu << 16;  /* 0x8009F19C */
    R[2] = lw_(R[3] + 13488);  /* 0x8009F1A0 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[2] - 1; if (_c) { goto L_8009F1B4; } }  /* 0x8009F1A8 */
    R[2] = R[0] + 8;  /* 0x8009F1B0 */
L_8009F1B4:;
    sw_(R[3] + 13488, R[2]);  /* 0x8009F1B4 */
    R[2] = 0x8006u << 16;  /* 0x8009F1B8 */
L_8009F1BC:;
    R[3] = R[2] - 6456;  /* 0x8009F1BC */
    R[2] = lh_(R[3] + 6);  /* 0x8009F1C0 */
    R[2] = R[2] & 0x2000;  /* 0x8009F1C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F214; } }  /* 0x8009F1CC */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F1D4 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F1DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F218; } }  /* 0x8009F1E0 */
    R[3] = lh_(R[3] + 2);  /* 0x8009F1E8 */
    R[2] = R[3] & 0x8;  /* 0x8009F1F0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F20C; } }  /* 0x8009F1F4 */
    R[2] = R[3] & 0x2;  /* 0x8009F1FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F20C; } }  /* 0x8009F200 */
    R[4] = R[0] + 100;  /* 0x8009F208 */
L_8009F20C:;
    { R[31] = 0x8009F214u; psx_next = 0x8009ECECu; return; }  /* 0x8009F20C jal */
L_8009F214:;
    R[2] = 0x8006u << 16;  /* 0x8009F214 */
L_8009F218:;
    R[3] = R[2] - 6456;  /* 0x8009F218 */
    R[2] = lh_(R[3] + 6);  /* 0x8009F21C */
    R[2] = R[2] & 0x8000;  /* 0x8009F224 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F270; } }  /* 0x8009F228 */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F230 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F238 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F274; } }  /* 0x8009F23C */
    R[3] = lh_(R[3] + 2);  /* 0x8009F244 */
    R[2] = R[3] & 0x8;  /* 0x8009F24C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F268; } }  /* 0x8009F250 */
    R[2] = R[3] & 0x2;  /* 0x8009F258 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    R[4] = R[0] + 100;  /* 0x8009F264 */
L_8009F268:;
    { R[31] = 0x8009F270u; psx_next = 0x8009EE0Cu; return; }  /* 0x8009F268 jal */
L_8009F270:;
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
L_8009F274:;
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
L_8009F2EC:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
L_8009F418:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009EFC8(void) {
    R[17] = R[0] + R[0];  /* 0x8009EFC8 */
    R[2] = 0x800Fu << 16;  /* 0x8009EFCC */
    R[16] = R[2] - 1904;  /* 0x8009EFD0 */
L_8009EFD4:;
    R[4] = lh_(R[16] + 2);  /* 0x8009EFD4 */
    { R[31] = 0x8009EFE0u; R[17] = R[17] + 1; psx_next = 0x8001D060u; return; }  /* 0x8009EFD8 jal */
    sh_(R[16] + 2, R[0]);  /* 0x8009EFE0 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009EFE4 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 52; if (_c) { psx_bb(); goto L_8009EFD4; } }  /* 0x8009EFE8 */
    { R[2] = R[0] - 1; psx_next = 0x8009F57Cu; return; }  /* 0x8009EFF0 j extern */
    R[2] = lb_(R[3] + 27968);  /* 0x8009EFF8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F000 b extern */
    sw_(R[2] + 13060, R[0]);  /* 0x8009F008 */
    { sb_(R[3] + 27968, R[0]); psx_next = 0x8009F578u; return; }  /* 0x8009F00C j extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F014 */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F018 */
    R[2] = R[0] + 1;  /* 0x8009F01C */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F08C; } }  /* 0x8009F020 */
    R[2] = 0x800Bu << 16;  /* 0x8009F028 */
    R[2] = lw_(R[2] + 13656);  /* 0x8009F02C */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F08C; } }  /* 0x8009F034 */
    R[2] = 0x8006u << 16;  /* 0x8009F03C */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F040 */
    R[2] = R[3] & 0xA0;  /* 0x8009F048 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { goto L_8009F06C; } }  /* 0x8009F04C */
    { R[31] = 0x8009F05Cu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F054 jal */
    { R[31] = 0x8009F064u; R[4] = R[0] + R[0]; psx_next = 0x8009BD50u; return; }  /* 0x8009F05C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F064 j extern */
L_8009F06C:;
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F06C b extern */
    { R[31] = 0x8009F07Cu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F074 jal */
    { R[31] = 0x8009F084u; R[4] = R[0] + R[0]; psx_next = 0x8009BCA4u; return; }  /* 0x8009F07C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F084 j extern */
L_8009F08C:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F08C */
    R[2] = R[0] + 2;  /* 0x8009F090 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F094 */
    R[2] = 0x800Bu << 16;  /* 0x8009F09C */
    R[2] = lw_(R[2] + 13660);  /* 0x8009F0A0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F0A8 */
    R[2] = 0x8006u << 16;  /* 0x8009F0B0 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F0B4 */
    R[2] = R[3] & 0xA0;  /* 0x8009F0BC */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 2; if (_c) { goto L_8009F0D4; } }  /* 0x8009F0C0 */
    R[2] = R[3] & 0x40;  /* 0x8009F0C8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 3; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F0CC b extern */
L_8009F0D4:;
    { R[31] = 0x8009F0DCu; psx_next = 0x8002DB10u; return; }  /* 0x8009F0D4 jal */
    { R[31] = 0x8009F0E4u; R[4] = R[0] + 1; psx_next = 0x8009BD1Cu; return; }  /* 0x8009F0DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F0E4 j extern */
L_8009F0EC:;
    R[4] = lw_(R[2] + 13480);  /* 0x8009F0EC */
    R[2] = R[0] + 3;  /* 0x8009F0F0 */
    { uint32_t _c = (R[4] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F0F4 */
    R[2] = 0x800Bu << 16;  /* 0x8009F0FC */
    R[2] = lw_(R[2] + 13664);  /* 0x8009F100 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F108 */
    R[5] = 0x800Bu << 16;  /* 0x8009F110 */
    R[3] = lw_(R[5] + 13484);  /* 0x8009F114 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F2EC; } }  /* 0x8009F11C */
    R[2] = 0x800Fu << 16;  /* 0x8009F124 */
    R[2] = lb_(R[2] + 25764);  /* 0x8009F128 */
    { uint32_t _c = (R[2] != R[4]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F130 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F138 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F13C */
    R[2] = R[2] & 0x4000;  /* 0x8009F144 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F180; } }  /* 0x8009F148 */
    { R[31] = 0x8009F158u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F150 jal */
    R[4] = 0x800Bu << 16;  /* 0x8009F158 */
    R[3] = lw_(R[4] + 13488);  /* 0x8009F15C */
    R[2] = ((int32_t)R[3] < 8);  /* 0x8009F164 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_8009F178; } }  /* 0x8009F168 */
    { sw_(R[4] + 13488, R[2]); goto L_8009F17C; }  /* 0x8009F170 j */
L_8009F178:;
    sw_(R[4] + 13488, R[0]);  /* 0x8009F178 */
L_8009F17C:;
    R[2] = 0x8006u << 16;  /* 0x8009F17C */
L_8009F180:;
    R[2] = lh_(R[2] + -6450);  /* 0x8009F180 */
    R[2] = R[2] & 0x1000;  /* 0x8009F188 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F1BC; } }  /* 0x8009F18C */
    { R[31] = 0x8009F19Cu; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F194 jal */
    R[3] = 0x800Bu << 16;  /* 0x8009F19C */
    R[2] = lw_(R[3] + 13488);  /* 0x8009F1A0 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[2] - 1; if (_c) { goto L_8009F1B4; } }  /* 0x8009F1A8 */
    R[2] = R[0] + 8;  /* 0x8009F1B0 */
L_8009F1B4:;
    sw_(R[3] + 13488, R[2]);  /* 0x8009F1B4 */
    R[2] = 0x8006u << 16;  /* 0x8009F1B8 */
L_8009F1BC:;
    R[3] = R[2] - 6456;  /* 0x8009F1BC */
    R[2] = lh_(R[3] + 6);  /* 0x8009F1C0 */
    R[2] = R[2] & 0x2000;  /* 0x8009F1C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F214; } }  /* 0x8009F1CC */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F1D4 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F1DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F218; } }  /* 0x8009F1E0 */
    R[3] = lh_(R[3] + 2);  /* 0x8009F1E8 */
    R[2] = R[3] & 0x8;  /* 0x8009F1F0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F20C; } }  /* 0x8009F1F4 */
    R[2] = R[3] & 0x2;  /* 0x8009F1FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F20C; } }  /* 0x8009F200 */
    R[4] = R[0] + 100;  /* 0x8009F208 */
L_8009F20C:;
    { R[31] = 0x8009F214u; psx_next = 0x8009ECECu; return; }  /* 0x8009F20C jal */
L_8009F214:;
    R[2] = 0x8006u << 16;  /* 0x8009F214 */
L_8009F218:;
    R[3] = R[2] - 6456;  /* 0x8009F218 */
    R[2] = lh_(R[3] + 6);  /* 0x8009F21C */
    R[2] = R[2] & 0x8000;  /* 0x8009F224 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F270; } }  /* 0x8009F228 */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F230 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F238 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F274; } }  /* 0x8009F23C */
    R[3] = lh_(R[3] + 2);  /* 0x8009F244 */
    R[2] = R[3] & 0x8;  /* 0x8009F24C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F268; } }  /* 0x8009F250 */
    R[2] = R[3] & 0x2;  /* 0x8009F258 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    R[4] = R[0] + 100;  /* 0x8009F264 */
L_8009F268:;
    { R[31] = 0x8009F270u; psx_next = 0x8009EE0Cu; return; }  /* 0x8009F268 jal */
L_8009F270:;
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
L_8009F274:;
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
L_8009F2EC:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
L_8009F418:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009EFD4(void) {
L_8009EFD4:;
    R[4] = lh_(R[16] + 2);  /* 0x8009EFD4 */
    { R[31] = 0x8009EFE0u; R[17] = R[17] + 1; psx_next = 0x8001D060u; return; }  /* 0x8009EFD8 jal */
    sh_(R[16] + 2, R[0]);  /* 0x8009EFE0 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009EFE4 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 52; if (_c) { psx_bb(); goto L_8009EFD4; } }  /* 0x8009EFE8 */
    { R[2] = R[0] - 1; psx_next = 0x8009F57Cu; return; }  /* 0x8009EFF0 j extern */
    R[2] = lb_(R[3] + 27968);  /* 0x8009EFF8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F000 b extern */
    sw_(R[2] + 13060, R[0]);  /* 0x8009F008 */
    { sb_(R[3] + 27968, R[0]); psx_next = 0x8009F578u; return; }  /* 0x8009F00C j extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F014 */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F018 */
    R[2] = R[0] + 1;  /* 0x8009F01C */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F08C; } }  /* 0x8009F020 */
    R[2] = 0x800Bu << 16;  /* 0x8009F028 */
    R[2] = lw_(R[2] + 13656);  /* 0x8009F02C */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F08C; } }  /* 0x8009F034 */
    R[2] = 0x8006u << 16;  /* 0x8009F03C */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F040 */
    R[2] = R[3] & 0xA0;  /* 0x8009F048 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { goto L_8009F06C; } }  /* 0x8009F04C */
    { R[31] = 0x8009F05Cu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F054 jal */
    { R[31] = 0x8009F064u; R[4] = R[0] + R[0]; psx_next = 0x8009BD50u; return; }  /* 0x8009F05C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F064 j extern */
L_8009F06C:;
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F06C b extern */
    { R[31] = 0x8009F07Cu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F074 jal */
    { R[31] = 0x8009F084u; R[4] = R[0] + R[0]; psx_next = 0x8009BCA4u; return; }  /* 0x8009F07C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F084 j extern */
L_8009F08C:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F08C */
    R[2] = R[0] + 2;  /* 0x8009F090 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F094 */
    R[2] = 0x800Bu << 16;  /* 0x8009F09C */
    R[2] = lw_(R[2] + 13660);  /* 0x8009F0A0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F0A8 */
    R[2] = 0x8006u << 16;  /* 0x8009F0B0 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F0B4 */
    R[2] = R[3] & 0xA0;  /* 0x8009F0BC */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 2; if (_c) { goto L_8009F0D4; } }  /* 0x8009F0C0 */
    R[2] = R[3] & 0x40;  /* 0x8009F0C8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 3; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F0CC b extern */
L_8009F0D4:;
    { R[31] = 0x8009F0DCu; psx_next = 0x8002DB10u; return; }  /* 0x8009F0D4 jal */
    { R[31] = 0x8009F0E4u; R[4] = R[0] + 1; psx_next = 0x8009BD1Cu; return; }  /* 0x8009F0DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F0E4 j extern */
L_8009F0EC:;
    R[4] = lw_(R[2] + 13480);  /* 0x8009F0EC */
    R[2] = R[0] + 3;  /* 0x8009F0F0 */
    { uint32_t _c = (R[4] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F0F4 */
    R[2] = 0x800Bu << 16;  /* 0x8009F0FC */
    R[2] = lw_(R[2] + 13664);  /* 0x8009F100 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F108 */
    R[5] = 0x800Bu << 16;  /* 0x8009F110 */
    R[3] = lw_(R[5] + 13484);  /* 0x8009F114 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F2EC; } }  /* 0x8009F11C */
    R[2] = 0x800Fu << 16;  /* 0x8009F124 */
    R[2] = lb_(R[2] + 25764);  /* 0x8009F128 */
    { uint32_t _c = (R[2] != R[4]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F130 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F138 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F13C */
    R[2] = R[2] & 0x4000;  /* 0x8009F144 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F180; } }  /* 0x8009F148 */
    { R[31] = 0x8009F158u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F150 jal */
    R[4] = 0x800Bu << 16;  /* 0x8009F158 */
    R[3] = lw_(R[4] + 13488);  /* 0x8009F15C */
    R[2] = ((int32_t)R[3] < 8);  /* 0x8009F164 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_8009F178; } }  /* 0x8009F168 */
    { sw_(R[4] + 13488, R[2]); goto L_8009F17C; }  /* 0x8009F170 j */
L_8009F178:;
    sw_(R[4] + 13488, R[0]);  /* 0x8009F178 */
L_8009F17C:;
    R[2] = 0x8006u << 16;  /* 0x8009F17C */
L_8009F180:;
    R[2] = lh_(R[2] + -6450);  /* 0x8009F180 */
    R[2] = R[2] & 0x1000;  /* 0x8009F188 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F1BC; } }  /* 0x8009F18C */
    { R[31] = 0x8009F19Cu; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F194 jal */
    R[3] = 0x800Bu << 16;  /* 0x8009F19C */
    R[2] = lw_(R[3] + 13488);  /* 0x8009F1A0 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[2] - 1; if (_c) { goto L_8009F1B4; } }  /* 0x8009F1A8 */
    R[2] = R[0] + 8;  /* 0x8009F1B0 */
L_8009F1B4:;
    sw_(R[3] + 13488, R[2]);  /* 0x8009F1B4 */
    R[2] = 0x8006u << 16;  /* 0x8009F1B8 */
L_8009F1BC:;
    R[3] = R[2] - 6456;  /* 0x8009F1BC */
    R[2] = lh_(R[3] + 6);  /* 0x8009F1C0 */
    R[2] = R[2] & 0x2000;  /* 0x8009F1C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F214; } }  /* 0x8009F1CC */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F1D4 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F1DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F218; } }  /* 0x8009F1E0 */
    R[3] = lh_(R[3] + 2);  /* 0x8009F1E8 */
    R[2] = R[3] & 0x8;  /* 0x8009F1F0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F20C; } }  /* 0x8009F1F4 */
    R[2] = R[3] & 0x2;  /* 0x8009F1FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F20C; } }  /* 0x8009F200 */
    R[4] = R[0] + 100;  /* 0x8009F208 */
L_8009F20C:;
    { R[31] = 0x8009F214u; psx_next = 0x8009ECECu; return; }  /* 0x8009F20C jal */
L_8009F214:;
    R[2] = 0x8006u << 16;  /* 0x8009F214 */
L_8009F218:;
    R[3] = R[2] - 6456;  /* 0x8009F218 */
    R[2] = lh_(R[3] + 6);  /* 0x8009F21C */
    R[2] = R[2] & 0x8000;  /* 0x8009F224 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F270; } }  /* 0x8009F228 */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F230 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F238 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F274; } }  /* 0x8009F23C */
    R[3] = lh_(R[3] + 2);  /* 0x8009F244 */
    R[2] = R[3] & 0x8;  /* 0x8009F24C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F268; } }  /* 0x8009F250 */
    R[2] = R[3] & 0x2;  /* 0x8009F258 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    R[4] = R[0] + 100;  /* 0x8009F264 */
L_8009F268:;
    { R[31] = 0x8009F270u; psx_next = 0x8009EE0Cu; return; }  /* 0x8009F268 jal */
L_8009F270:;
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
L_8009F274:;
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
L_8009F2EC:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
L_8009F418:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009EFE0(void) {
    sh_(R[16] + 2, R[0]);  /* 0x8009EFE0 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009EFE4 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 52; if (_c) { psx_next = 0x8009EFD4u; return; } }  /* 0x8009EFE8 b extern */
    { R[2] = R[0] - 1; psx_next = 0x8009F57Cu; return; }  /* 0x8009EFF0 j extern */
    R[2] = lb_(R[3] + 27968);  /* 0x8009EFF8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F000 b extern */
    sw_(R[2] + 13060, R[0]);  /* 0x8009F008 */
    { sb_(R[3] + 27968, R[0]); psx_next = 0x8009F578u; return; }  /* 0x8009F00C j extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F014 */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F018 */
    R[2] = R[0] + 1;  /* 0x8009F01C */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F08C; } }  /* 0x8009F020 */
    R[2] = 0x800Bu << 16;  /* 0x8009F028 */
    R[2] = lw_(R[2] + 13656);  /* 0x8009F02C */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F08C; } }  /* 0x8009F034 */
    R[2] = 0x8006u << 16;  /* 0x8009F03C */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F040 */
    R[2] = R[3] & 0xA0;  /* 0x8009F048 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { goto L_8009F06C; } }  /* 0x8009F04C */
    { R[31] = 0x8009F05Cu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F054 jal */
    { R[31] = 0x8009F064u; R[4] = R[0] + R[0]; psx_next = 0x8009BD50u; return; }  /* 0x8009F05C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F064 j extern */
L_8009F06C:;
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F06C b extern */
    { R[31] = 0x8009F07Cu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F074 jal */
    { R[31] = 0x8009F084u; R[4] = R[0] + R[0]; psx_next = 0x8009BCA4u; return; }  /* 0x8009F07C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F084 j extern */
L_8009F08C:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F08C */
    R[2] = R[0] + 2;  /* 0x8009F090 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F094 */
    R[2] = 0x800Bu << 16;  /* 0x8009F09C */
    R[2] = lw_(R[2] + 13660);  /* 0x8009F0A0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F0A8 */
    R[2] = 0x8006u << 16;  /* 0x8009F0B0 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F0B4 */
    R[2] = R[3] & 0xA0;  /* 0x8009F0BC */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 2; if (_c) { goto L_8009F0D4; } }  /* 0x8009F0C0 */
    R[2] = R[3] & 0x40;  /* 0x8009F0C8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 3; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F0CC b extern */
L_8009F0D4:;
    { R[31] = 0x8009F0DCu; psx_next = 0x8002DB10u; return; }  /* 0x8009F0D4 jal */
    { R[31] = 0x8009F0E4u; R[4] = R[0] + 1; psx_next = 0x8009BD1Cu; return; }  /* 0x8009F0DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F0E4 j extern */
L_8009F0EC:;
    R[4] = lw_(R[2] + 13480);  /* 0x8009F0EC */
    R[2] = R[0] + 3;  /* 0x8009F0F0 */
    { uint32_t _c = (R[4] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F0F4 */
    R[2] = 0x800Bu << 16;  /* 0x8009F0FC */
    R[2] = lw_(R[2] + 13664);  /* 0x8009F100 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F108 */
    R[5] = 0x800Bu << 16;  /* 0x8009F110 */
    R[3] = lw_(R[5] + 13484);  /* 0x8009F114 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F2EC; } }  /* 0x8009F11C */
    R[2] = 0x800Fu << 16;  /* 0x8009F124 */
    R[2] = lb_(R[2] + 25764);  /* 0x8009F128 */
    { uint32_t _c = (R[2] != R[4]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F130 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F138 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F13C */
    R[2] = R[2] & 0x4000;  /* 0x8009F144 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F180; } }  /* 0x8009F148 */
    { R[31] = 0x8009F158u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F150 jal */
    R[4] = 0x800Bu << 16;  /* 0x8009F158 */
    R[3] = lw_(R[4] + 13488);  /* 0x8009F15C */
    R[2] = ((int32_t)R[3] < 8);  /* 0x8009F164 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_8009F178; } }  /* 0x8009F168 */
    { sw_(R[4] + 13488, R[2]); goto L_8009F17C; }  /* 0x8009F170 j */
L_8009F178:;
    sw_(R[4] + 13488, R[0]);  /* 0x8009F178 */
L_8009F17C:;
    R[2] = 0x8006u << 16;  /* 0x8009F17C */
L_8009F180:;
    R[2] = lh_(R[2] + -6450);  /* 0x8009F180 */
    R[2] = R[2] & 0x1000;  /* 0x8009F188 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F1BC; } }  /* 0x8009F18C */
    { R[31] = 0x8009F19Cu; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F194 jal */
    R[3] = 0x800Bu << 16;  /* 0x8009F19C */
    R[2] = lw_(R[3] + 13488);  /* 0x8009F1A0 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[2] - 1; if (_c) { goto L_8009F1B4; } }  /* 0x8009F1A8 */
    R[2] = R[0] + 8;  /* 0x8009F1B0 */
L_8009F1B4:;
    sw_(R[3] + 13488, R[2]);  /* 0x8009F1B4 */
    R[2] = 0x8006u << 16;  /* 0x8009F1B8 */
L_8009F1BC:;
    R[3] = R[2] - 6456;  /* 0x8009F1BC */
    R[2] = lh_(R[3] + 6);  /* 0x8009F1C0 */
    R[2] = R[2] & 0x2000;  /* 0x8009F1C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F214; } }  /* 0x8009F1CC */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F1D4 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F1DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F218; } }  /* 0x8009F1E0 */
    R[3] = lh_(R[3] + 2);  /* 0x8009F1E8 */
    R[2] = R[3] & 0x8;  /* 0x8009F1F0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F20C; } }  /* 0x8009F1F4 */
    R[2] = R[3] & 0x2;  /* 0x8009F1FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F20C; } }  /* 0x8009F200 */
    R[4] = R[0] + 100;  /* 0x8009F208 */
L_8009F20C:;
    { R[31] = 0x8009F214u; psx_next = 0x8009ECECu; return; }  /* 0x8009F20C jal */
L_8009F214:;
    R[2] = 0x8006u << 16;  /* 0x8009F214 */
L_8009F218:;
    R[3] = R[2] - 6456;  /* 0x8009F218 */
    R[2] = lh_(R[3] + 6);  /* 0x8009F21C */
    R[2] = R[2] & 0x8000;  /* 0x8009F224 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F270; } }  /* 0x8009F228 */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F230 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F238 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F274; } }  /* 0x8009F23C */
    R[3] = lh_(R[3] + 2);  /* 0x8009F244 */
    R[2] = R[3] & 0x8;  /* 0x8009F24C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F268; } }  /* 0x8009F250 */
    R[2] = R[3] & 0x2;  /* 0x8009F258 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    R[4] = R[0] + 100;  /* 0x8009F264 */
L_8009F268:;
    { R[31] = 0x8009F270u; psx_next = 0x8009EE0Cu; return; }  /* 0x8009F268 jal */
L_8009F270:;
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
L_8009F274:;
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
L_8009F2EC:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
L_8009F418:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F05C(void) {
    { R[31] = 0x8009F064u; R[4] = R[0] + R[0]; psx_next = 0x8009BD50u; return; }  /* 0x8009F05C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F064 j extern */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F06C b extern */
    { R[31] = 0x8009F07Cu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F074 jal */
    { R[31] = 0x8009F084u; R[4] = R[0] + R[0]; psx_next = 0x8009BCA4u; return; }  /* 0x8009F07C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F084 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F08C */
    R[2] = R[0] + 2;  /* 0x8009F090 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F094 */
    R[2] = 0x800Bu << 16;  /* 0x8009F09C */
    R[2] = lw_(R[2] + 13660);  /* 0x8009F0A0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F0A8 */
    R[2] = 0x8006u << 16;  /* 0x8009F0B0 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F0B4 */
    R[2] = R[3] & 0xA0;  /* 0x8009F0BC */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 2; if (_c) { goto L_8009F0D4; } }  /* 0x8009F0C0 */
    R[2] = R[3] & 0x40;  /* 0x8009F0C8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 3; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F0CC b extern */
L_8009F0D4:;
    { R[31] = 0x8009F0DCu; psx_next = 0x8002DB10u; return; }  /* 0x8009F0D4 jal */
    { R[31] = 0x8009F0E4u; R[4] = R[0] + 1; psx_next = 0x8009BD1Cu; return; }  /* 0x8009F0DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F0E4 j extern */
L_8009F0EC:;
    R[4] = lw_(R[2] + 13480);  /* 0x8009F0EC */
    R[2] = R[0] + 3;  /* 0x8009F0F0 */
    { uint32_t _c = (R[4] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F0F4 */
    R[2] = 0x800Bu << 16;  /* 0x8009F0FC */
    R[2] = lw_(R[2] + 13664);  /* 0x8009F100 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F108 */
    R[5] = 0x800Bu << 16;  /* 0x8009F110 */
    R[3] = lw_(R[5] + 13484);  /* 0x8009F114 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F2EC; } }  /* 0x8009F11C */
    R[2] = 0x800Fu << 16;  /* 0x8009F124 */
    R[2] = lb_(R[2] + 25764);  /* 0x8009F128 */
    { uint32_t _c = (R[2] != R[4]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F130 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F138 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F13C */
    R[2] = R[2] & 0x4000;  /* 0x8009F144 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F180; } }  /* 0x8009F148 */
    { R[31] = 0x8009F158u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F150 jal */
    R[4] = 0x800Bu << 16;  /* 0x8009F158 */
    R[3] = lw_(R[4] + 13488);  /* 0x8009F15C */
    R[2] = ((int32_t)R[3] < 8);  /* 0x8009F164 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_8009F178; } }  /* 0x8009F168 */
    { sw_(R[4] + 13488, R[2]); goto L_8009F17C; }  /* 0x8009F170 j */
L_8009F178:;
    sw_(R[4] + 13488, R[0]);  /* 0x8009F178 */
L_8009F17C:;
    R[2] = 0x8006u << 16;  /* 0x8009F17C */
L_8009F180:;
    R[2] = lh_(R[2] + -6450);  /* 0x8009F180 */
    R[2] = R[2] & 0x1000;  /* 0x8009F188 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F1BC; } }  /* 0x8009F18C */
    { R[31] = 0x8009F19Cu; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F194 jal */
    R[3] = 0x800Bu << 16;  /* 0x8009F19C */
    R[2] = lw_(R[3] + 13488);  /* 0x8009F1A0 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[2] - 1; if (_c) { goto L_8009F1B4; } }  /* 0x8009F1A8 */
    R[2] = R[0] + 8;  /* 0x8009F1B0 */
L_8009F1B4:;
    sw_(R[3] + 13488, R[2]);  /* 0x8009F1B4 */
    R[2] = 0x8006u << 16;  /* 0x8009F1B8 */
L_8009F1BC:;
    R[3] = R[2] - 6456;  /* 0x8009F1BC */
    R[2] = lh_(R[3] + 6);  /* 0x8009F1C0 */
    R[2] = R[2] & 0x2000;  /* 0x8009F1C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F214; } }  /* 0x8009F1CC */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F1D4 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F1DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F218; } }  /* 0x8009F1E0 */
    R[3] = lh_(R[3] + 2);  /* 0x8009F1E8 */
    R[2] = R[3] & 0x8;  /* 0x8009F1F0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F20C; } }  /* 0x8009F1F4 */
    R[2] = R[3] & 0x2;  /* 0x8009F1FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F20C; } }  /* 0x8009F200 */
    R[4] = R[0] + 100;  /* 0x8009F208 */
L_8009F20C:;
    { R[31] = 0x8009F214u; psx_next = 0x8009ECECu; return; }  /* 0x8009F20C jal */
L_8009F214:;
    R[2] = 0x8006u << 16;  /* 0x8009F214 */
L_8009F218:;
    R[3] = R[2] - 6456;  /* 0x8009F218 */
    R[2] = lh_(R[3] + 6);  /* 0x8009F21C */
    R[2] = R[2] & 0x8000;  /* 0x8009F224 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F270; } }  /* 0x8009F228 */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F230 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F238 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F274; } }  /* 0x8009F23C */
    R[3] = lh_(R[3] + 2);  /* 0x8009F244 */
    R[2] = R[3] & 0x8;  /* 0x8009F24C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F268; } }  /* 0x8009F250 */
    R[2] = R[3] & 0x2;  /* 0x8009F258 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    R[4] = R[0] + 100;  /* 0x8009F264 */
L_8009F268:;
    { R[31] = 0x8009F270u; psx_next = 0x8009EE0Cu; return; }  /* 0x8009F268 jal */
L_8009F270:;
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
L_8009F274:;
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
L_8009F2EC:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
L_8009F418:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F064(void) {
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F064 j extern */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F06C b extern */
    { R[31] = 0x8009F07Cu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F074 jal */
    { R[31] = 0x8009F084u; R[4] = R[0] + R[0]; psx_next = 0x8009BCA4u; return; }  /* 0x8009F07C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F084 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F08C */
    R[2] = R[0] + 2;  /* 0x8009F090 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F094 */
    R[2] = 0x800Bu << 16;  /* 0x8009F09C */
    R[2] = lw_(R[2] + 13660);  /* 0x8009F0A0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F0A8 */
    R[2] = 0x8006u << 16;  /* 0x8009F0B0 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F0B4 */
    R[2] = R[3] & 0xA0;  /* 0x8009F0BC */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 2; if (_c) { goto L_8009F0D4; } }  /* 0x8009F0C0 */
    R[2] = R[3] & 0x40;  /* 0x8009F0C8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 3; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F0CC b extern */
L_8009F0D4:;
    { R[31] = 0x8009F0DCu; psx_next = 0x8002DB10u; return; }  /* 0x8009F0D4 jal */
    { R[31] = 0x8009F0E4u; R[4] = R[0] + 1; psx_next = 0x8009BD1Cu; return; }  /* 0x8009F0DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F0E4 j extern */
L_8009F0EC:;
    R[4] = lw_(R[2] + 13480);  /* 0x8009F0EC */
    R[2] = R[0] + 3;  /* 0x8009F0F0 */
    { uint32_t _c = (R[4] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F0F4 */
    R[2] = 0x800Bu << 16;  /* 0x8009F0FC */
    R[2] = lw_(R[2] + 13664);  /* 0x8009F100 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F108 */
    R[5] = 0x800Bu << 16;  /* 0x8009F110 */
    R[3] = lw_(R[5] + 13484);  /* 0x8009F114 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F2EC; } }  /* 0x8009F11C */
    R[2] = 0x800Fu << 16;  /* 0x8009F124 */
    R[2] = lb_(R[2] + 25764);  /* 0x8009F128 */
    { uint32_t _c = (R[2] != R[4]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F130 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F138 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F13C */
    R[2] = R[2] & 0x4000;  /* 0x8009F144 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F180; } }  /* 0x8009F148 */
    { R[31] = 0x8009F158u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F150 jal */
    R[4] = 0x800Bu << 16;  /* 0x8009F158 */
    R[3] = lw_(R[4] + 13488);  /* 0x8009F15C */
    R[2] = ((int32_t)R[3] < 8);  /* 0x8009F164 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_8009F178; } }  /* 0x8009F168 */
    { sw_(R[4] + 13488, R[2]); goto L_8009F17C; }  /* 0x8009F170 j */
L_8009F178:;
    sw_(R[4] + 13488, R[0]);  /* 0x8009F178 */
L_8009F17C:;
    R[2] = 0x8006u << 16;  /* 0x8009F17C */
L_8009F180:;
    R[2] = lh_(R[2] + -6450);  /* 0x8009F180 */
    R[2] = R[2] & 0x1000;  /* 0x8009F188 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F1BC; } }  /* 0x8009F18C */
    { R[31] = 0x8009F19Cu; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F194 jal */
    R[3] = 0x800Bu << 16;  /* 0x8009F19C */
    R[2] = lw_(R[3] + 13488);  /* 0x8009F1A0 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[2] - 1; if (_c) { goto L_8009F1B4; } }  /* 0x8009F1A8 */
    R[2] = R[0] + 8;  /* 0x8009F1B0 */
L_8009F1B4:;
    sw_(R[3] + 13488, R[2]);  /* 0x8009F1B4 */
    R[2] = 0x8006u << 16;  /* 0x8009F1B8 */
L_8009F1BC:;
    R[3] = R[2] - 6456;  /* 0x8009F1BC */
    R[2] = lh_(R[3] + 6);  /* 0x8009F1C0 */
    R[2] = R[2] & 0x2000;  /* 0x8009F1C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F214; } }  /* 0x8009F1CC */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F1D4 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F1DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F218; } }  /* 0x8009F1E0 */
    R[3] = lh_(R[3] + 2);  /* 0x8009F1E8 */
    R[2] = R[3] & 0x8;  /* 0x8009F1F0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F20C; } }  /* 0x8009F1F4 */
    R[2] = R[3] & 0x2;  /* 0x8009F1FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F20C; } }  /* 0x8009F200 */
    R[4] = R[0] + 100;  /* 0x8009F208 */
L_8009F20C:;
    { R[31] = 0x8009F214u; psx_next = 0x8009ECECu; return; }  /* 0x8009F20C jal */
L_8009F214:;
    R[2] = 0x8006u << 16;  /* 0x8009F214 */
L_8009F218:;
    R[3] = R[2] - 6456;  /* 0x8009F218 */
    R[2] = lh_(R[3] + 6);  /* 0x8009F21C */
    R[2] = R[2] & 0x8000;  /* 0x8009F224 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F270; } }  /* 0x8009F228 */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F230 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F238 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F274; } }  /* 0x8009F23C */
    R[3] = lh_(R[3] + 2);  /* 0x8009F244 */
    R[2] = R[3] & 0x8;  /* 0x8009F24C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F268; } }  /* 0x8009F250 */
    R[2] = R[3] & 0x2;  /* 0x8009F258 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    R[4] = R[0] + 100;  /* 0x8009F264 */
L_8009F268:;
    { R[31] = 0x8009F270u; psx_next = 0x8009EE0Cu; return; }  /* 0x8009F268 jal */
L_8009F270:;
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
L_8009F274:;
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
L_8009F2EC:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
L_8009F418:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F07C(void) {
    { R[31] = 0x8009F084u; R[4] = R[0] + R[0]; psx_next = 0x8009BCA4u; return; }  /* 0x8009F07C jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F084 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F08C */
    R[2] = R[0] + 2;  /* 0x8009F090 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F094 */
    R[2] = 0x800Bu << 16;  /* 0x8009F09C */
    R[2] = lw_(R[2] + 13660);  /* 0x8009F0A0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F0A8 */
    R[2] = 0x8006u << 16;  /* 0x8009F0B0 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F0B4 */
    R[2] = R[3] & 0xA0;  /* 0x8009F0BC */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 2; if (_c) { goto L_8009F0D4; } }  /* 0x8009F0C0 */
    R[2] = R[3] & 0x40;  /* 0x8009F0C8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 3; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F0CC b extern */
L_8009F0D4:;
    { R[31] = 0x8009F0DCu; psx_next = 0x8002DB10u; return; }  /* 0x8009F0D4 jal */
    { R[31] = 0x8009F0E4u; R[4] = R[0] + 1; psx_next = 0x8009BD1Cu; return; }  /* 0x8009F0DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F0E4 j extern */
L_8009F0EC:;
    R[4] = lw_(R[2] + 13480);  /* 0x8009F0EC */
    R[2] = R[0] + 3;  /* 0x8009F0F0 */
    { uint32_t _c = (R[4] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F0F4 */
    R[2] = 0x800Bu << 16;  /* 0x8009F0FC */
    R[2] = lw_(R[2] + 13664);  /* 0x8009F100 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F108 */
    R[5] = 0x800Bu << 16;  /* 0x8009F110 */
    R[3] = lw_(R[5] + 13484);  /* 0x8009F114 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F2EC; } }  /* 0x8009F11C */
    R[2] = 0x800Fu << 16;  /* 0x8009F124 */
    R[2] = lb_(R[2] + 25764);  /* 0x8009F128 */
    { uint32_t _c = (R[2] != R[4]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F130 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F138 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F13C */
    R[2] = R[2] & 0x4000;  /* 0x8009F144 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F180; } }  /* 0x8009F148 */
    { R[31] = 0x8009F158u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F150 jal */
    R[4] = 0x800Bu << 16;  /* 0x8009F158 */
    R[3] = lw_(R[4] + 13488);  /* 0x8009F15C */
    R[2] = ((int32_t)R[3] < 8);  /* 0x8009F164 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_8009F178; } }  /* 0x8009F168 */
    { sw_(R[4] + 13488, R[2]); goto L_8009F17C; }  /* 0x8009F170 j */
L_8009F178:;
    sw_(R[4] + 13488, R[0]);  /* 0x8009F178 */
L_8009F17C:;
    R[2] = 0x8006u << 16;  /* 0x8009F17C */
L_8009F180:;
    R[2] = lh_(R[2] + -6450);  /* 0x8009F180 */
    R[2] = R[2] & 0x1000;  /* 0x8009F188 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F1BC; } }  /* 0x8009F18C */
    { R[31] = 0x8009F19Cu; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F194 jal */
    R[3] = 0x800Bu << 16;  /* 0x8009F19C */
    R[2] = lw_(R[3] + 13488);  /* 0x8009F1A0 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[2] - 1; if (_c) { goto L_8009F1B4; } }  /* 0x8009F1A8 */
    R[2] = R[0] + 8;  /* 0x8009F1B0 */
L_8009F1B4:;
    sw_(R[3] + 13488, R[2]);  /* 0x8009F1B4 */
    R[2] = 0x8006u << 16;  /* 0x8009F1B8 */
L_8009F1BC:;
    R[3] = R[2] - 6456;  /* 0x8009F1BC */
    R[2] = lh_(R[3] + 6);  /* 0x8009F1C0 */
    R[2] = R[2] & 0x2000;  /* 0x8009F1C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F214; } }  /* 0x8009F1CC */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F1D4 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F1DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F218; } }  /* 0x8009F1E0 */
    R[3] = lh_(R[3] + 2);  /* 0x8009F1E8 */
    R[2] = R[3] & 0x8;  /* 0x8009F1F0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F20C; } }  /* 0x8009F1F4 */
    R[2] = R[3] & 0x2;  /* 0x8009F1FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F20C; } }  /* 0x8009F200 */
    R[4] = R[0] + 100;  /* 0x8009F208 */
L_8009F20C:;
    { R[31] = 0x8009F214u; psx_next = 0x8009ECECu; return; }  /* 0x8009F20C jal */
L_8009F214:;
    R[2] = 0x8006u << 16;  /* 0x8009F214 */
L_8009F218:;
    R[3] = R[2] - 6456;  /* 0x8009F218 */
    R[2] = lh_(R[3] + 6);  /* 0x8009F21C */
    R[2] = R[2] & 0x8000;  /* 0x8009F224 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F270; } }  /* 0x8009F228 */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F230 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F238 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F274; } }  /* 0x8009F23C */
    R[3] = lh_(R[3] + 2);  /* 0x8009F244 */
    R[2] = R[3] & 0x8;  /* 0x8009F24C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F268; } }  /* 0x8009F250 */
    R[2] = R[3] & 0x2;  /* 0x8009F258 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    R[4] = R[0] + 100;  /* 0x8009F264 */
L_8009F268:;
    { R[31] = 0x8009F270u; psx_next = 0x8009EE0Cu; return; }  /* 0x8009F268 jal */
L_8009F270:;
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
L_8009F274:;
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
L_8009F2EC:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
L_8009F418:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F084(void) {
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F084 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F08C */
    R[2] = R[0] + 2;  /* 0x8009F090 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F094 */
    R[2] = 0x800Bu << 16;  /* 0x8009F09C */
    R[2] = lw_(R[2] + 13660);  /* 0x8009F0A0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F0EC; } }  /* 0x8009F0A8 */
    R[2] = 0x8006u << 16;  /* 0x8009F0B0 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F0B4 */
    R[2] = R[3] & 0xA0;  /* 0x8009F0BC */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 2; if (_c) { goto L_8009F0D4; } }  /* 0x8009F0C0 */
    R[2] = R[3] & 0x40;  /* 0x8009F0C8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 3; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F0CC b extern */
L_8009F0D4:;
    { R[31] = 0x8009F0DCu; psx_next = 0x8002DB10u; return; }  /* 0x8009F0D4 jal */
    { R[31] = 0x8009F0E4u; R[4] = R[0] + 1; psx_next = 0x8009BD1Cu; return; }  /* 0x8009F0DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F0E4 j extern */
L_8009F0EC:;
    R[4] = lw_(R[2] + 13480);  /* 0x8009F0EC */
    R[2] = R[0] + 3;  /* 0x8009F0F0 */
    { uint32_t _c = (R[4] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F0F4 */
    R[2] = 0x800Bu << 16;  /* 0x8009F0FC */
    R[2] = lw_(R[2] + 13664);  /* 0x8009F100 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F108 */
    R[5] = 0x800Bu << 16;  /* 0x8009F110 */
    R[3] = lw_(R[5] + 13484);  /* 0x8009F114 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F2EC; } }  /* 0x8009F11C */
    R[2] = 0x800Fu << 16;  /* 0x8009F124 */
    R[2] = lb_(R[2] + 25764);  /* 0x8009F128 */
    { uint32_t _c = (R[2] != R[4]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F130 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F138 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F13C */
    R[2] = R[2] & 0x4000;  /* 0x8009F144 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F180; } }  /* 0x8009F148 */
    { R[31] = 0x8009F158u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F150 jal */
    R[4] = 0x800Bu << 16;  /* 0x8009F158 */
    R[3] = lw_(R[4] + 13488);  /* 0x8009F15C */
    R[2] = ((int32_t)R[3] < 8);  /* 0x8009F164 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_8009F178; } }  /* 0x8009F168 */
    { sw_(R[4] + 13488, R[2]); goto L_8009F17C; }  /* 0x8009F170 j */
L_8009F178:;
    sw_(R[4] + 13488, R[0]);  /* 0x8009F178 */
L_8009F17C:;
    R[2] = 0x8006u << 16;  /* 0x8009F17C */
L_8009F180:;
    R[2] = lh_(R[2] + -6450);  /* 0x8009F180 */
    R[2] = R[2] & 0x1000;  /* 0x8009F188 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F1BC; } }  /* 0x8009F18C */
    { R[31] = 0x8009F19Cu; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F194 jal */
    R[3] = 0x800Bu << 16;  /* 0x8009F19C */
    R[2] = lw_(R[3] + 13488);  /* 0x8009F1A0 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[2] - 1; if (_c) { goto L_8009F1B4; } }  /* 0x8009F1A8 */
    R[2] = R[0] + 8;  /* 0x8009F1B0 */
L_8009F1B4:;
    sw_(R[3] + 13488, R[2]);  /* 0x8009F1B4 */
    R[2] = 0x8006u << 16;  /* 0x8009F1B8 */
L_8009F1BC:;
    R[3] = R[2] - 6456;  /* 0x8009F1BC */
    R[2] = lh_(R[3] + 6);  /* 0x8009F1C0 */
    R[2] = R[2] & 0x2000;  /* 0x8009F1C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F214; } }  /* 0x8009F1CC */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F1D4 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F1DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F218; } }  /* 0x8009F1E0 */
    R[3] = lh_(R[3] + 2);  /* 0x8009F1E8 */
    R[2] = R[3] & 0x8;  /* 0x8009F1F0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F20C; } }  /* 0x8009F1F4 */
    R[2] = R[3] & 0x2;  /* 0x8009F1FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F20C; } }  /* 0x8009F200 */
    R[4] = R[0] + 100;  /* 0x8009F208 */
L_8009F20C:;
    { R[31] = 0x8009F214u; psx_next = 0x8009ECECu; return; }  /* 0x8009F20C jal */
L_8009F214:;
    R[2] = 0x8006u << 16;  /* 0x8009F214 */
L_8009F218:;
    R[3] = R[2] - 6456;  /* 0x8009F218 */
    R[2] = lh_(R[3] + 6);  /* 0x8009F21C */
    R[2] = R[2] & 0x8000;  /* 0x8009F224 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F270; } }  /* 0x8009F228 */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F230 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F238 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F274; } }  /* 0x8009F23C */
    R[3] = lh_(R[3] + 2);  /* 0x8009F244 */
    R[2] = R[3] & 0x8;  /* 0x8009F24C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F268; } }  /* 0x8009F250 */
    R[2] = R[3] & 0x2;  /* 0x8009F258 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    R[4] = R[0] + 100;  /* 0x8009F264 */
L_8009F268:;
    { R[31] = 0x8009F270u; psx_next = 0x8009EE0Cu; return; }  /* 0x8009F268 jal */
L_8009F270:;
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
L_8009F274:;
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
L_8009F2EC:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
L_8009F418:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F0DC(void) {
    { R[31] = 0x8009F0E4u; R[4] = R[0] + 1; psx_next = 0x8009BD1Cu; return; }  /* 0x8009F0DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F0E4 j extern */
    R[4] = lw_(R[2] + 13480);  /* 0x8009F0EC */
    R[2] = R[0] + 3;  /* 0x8009F0F0 */
    { uint32_t _c = (R[4] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F0F4 */
    R[2] = 0x800Bu << 16;  /* 0x8009F0FC */
    R[2] = lw_(R[2] + 13664);  /* 0x8009F100 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F108 */
    R[5] = 0x800Bu << 16;  /* 0x8009F110 */
    R[3] = lw_(R[5] + 13484);  /* 0x8009F114 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F2EC; } }  /* 0x8009F11C */
    R[2] = 0x800Fu << 16;  /* 0x8009F124 */
    R[2] = lb_(R[2] + 25764);  /* 0x8009F128 */
    { uint32_t _c = (R[2] != R[4]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F130 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F138 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F13C */
    R[2] = R[2] & 0x4000;  /* 0x8009F144 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F180; } }  /* 0x8009F148 */
    { R[31] = 0x8009F158u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F150 jal */
    R[4] = 0x800Bu << 16;  /* 0x8009F158 */
    R[3] = lw_(R[4] + 13488);  /* 0x8009F15C */
    R[2] = ((int32_t)R[3] < 8);  /* 0x8009F164 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_8009F178; } }  /* 0x8009F168 */
    { sw_(R[4] + 13488, R[2]); goto L_8009F17C; }  /* 0x8009F170 j */
L_8009F178:;
    sw_(R[4] + 13488, R[0]);  /* 0x8009F178 */
L_8009F17C:;
    R[2] = 0x8006u << 16;  /* 0x8009F17C */
L_8009F180:;
    R[2] = lh_(R[2] + -6450);  /* 0x8009F180 */
    R[2] = R[2] & 0x1000;  /* 0x8009F188 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F1BC; } }  /* 0x8009F18C */
    { R[31] = 0x8009F19Cu; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F194 jal */
    R[3] = 0x800Bu << 16;  /* 0x8009F19C */
    R[2] = lw_(R[3] + 13488);  /* 0x8009F1A0 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[2] - 1; if (_c) { goto L_8009F1B4; } }  /* 0x8009F1A8 */
    R[2] = R[0] + 8;  /* 0x8009F1B0 */
L_8009F1B4:;
    sw_(R[3] + 13488, R[2]);  /* 0x8009F1B4 */
    R[2] = 0x8006u << 16;  /* 0x8009F1B8 */
L_8009F1BC:;
    R[3] = R[2] - 6456;  /* 0x8009F1BC */
    R[2] = lh_(R[3] + 6);  /* 0x8009F1C0 */
    R[2] = R[2] & 0x2000;  /* 0x8009F1C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F214; } }  /* 0x8009F1CC */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F1D4 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F1DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F218; } }  /* 0x8009F1E0 */
    R[3] = lh_(R[3] + 2);  /* 0x8009F1E8 */
    R[2] = R[3] & 0x8;  /* 0x8009F1F0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F20C; } }  /* 0x8009F1F4 */
    R[2] = R[3] & 0x2;  /* 0x8009F1FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F20C; } }  /* 0x8009F200 */
    R[4] = R[0] + 100;  /* 0x8009F208 */
L_8009F20C:;
    { R[31] = 0x8009F214u; psx_next = 0x8009ECECu; return; }  /* 0x8009F20C jal */
L_8009F214:;
    R[2] = 0x8006u << 16;  /* 0x8009F214 */
L_8009F218:;
    R[3] = R[2] - 6456;  /* 0x8009F218 */
    R[2] = lh_(R[3] + 6);  /* 0x8009F21C */
    R[2] = R[2] & 0x8000;  /* 0x8009F224 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F270; } }  /* 0x8009F228 */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F230 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F238 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F274; } }  /* 0x8009F23C */
    R[3] = lh_(R[3] + 2);  /* 0x8009F244 */
    R[2] = R[3] & 0x8;  /* 0x8009F24C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F268; } }  /* 0x8009F250 */
    R[2] = R[3] & 0x2;  /* 0x8009F258 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    R[4] = R[0] + 100;  /* 0x8009F264 */
L_8009F268:;
    { R[31] = 0x8009F270u; psx_next = 0x8009EE0Cu; return; }  /* 0x8009F268 jal */
L_8009F270:;
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
L_8009F274:;
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
L_8009F2EC:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
L_8009F418:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F0E4(void) {
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F0E4 j extern */
    R[4] = lw_(R[2] + 13480);  /* 0x8009F0EC */
    R[2] = R[0] + 3;  /* 0x8009F0F0 */
    { uint32_t _c = (R[4] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F0F4 */
    R[2] = 0x800Bu << 16;  /* 0x8009F0FC */
    R[2] = lw_(R[2] + 13664);  /* 0x8009F100 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F418; } }  /* 0x8009F108 */
    R[5] = 0x800Bu << 16;  /* 0x8009F110 */
    R[3] = lw_(R[5] + 13484);  /* 0x8009F114 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F2EC; } }  /* 0x8009F11C */
    R[2] = 0x800Fu << 16;  /* 0x8009F124 */
    R[2] = lb_(R[2] + 25764);  /* 0x8009F128 */
    { uint32_t _c = (R[2] != R[4]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F130 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F138 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F13C */
    R[2] = R[2] & 0x4000;  /* 0x8009F144 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F180; } }  /* 0x8009F148 */
    { R[31] = 0x8009F158u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F150 jal */
    R[4] = 0x800Bu << 16;  /* 0x8009F158 */
    R[3] = lw_(R[4] + 13488);  /* 0x8009F15C */
    R[2] = ((int32_t)R[3] < 8);  /* 0x8009F164 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_8009F178; } }  /* 0x8009F168 */
    { sw_(R[4] + 13488, R[2]); goto L_8009F17C; }  /* 0x8009F170 j */
L_8009F178:;
    sw_(R[4] + 13488, R[0]);  /* 0x8009F178 */
L_8009F17C:;
    R[2] = 0x8006u << 16;  /* 0x8009F17C */
L_8009F180:;
    R[2] = lh_(R[2] + -6450);  /* 0x8009F180 */
    R[2] = R[2] & 0x1000;  /* 0x8009F188 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F1BC; } }  /* 0x8009F18C */
    { R[31] = 0x8009F19Cu; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F194 jal */
    R[3] = 0x800Bu << 16;  /* 0x8009F19C */
    R[2] = lw_(R[3] + 13488);  /* 0x8009F1A0 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[2] - 1; if (_c) { goto L_8009F1B4; } }  /* 0x8009F1A8 */
    R[2] = R[0] + 8;  /* 0x8009F1B0 */
L_8009F1B4:;
    sw_(R[3] + 13488, R[2]);  /* 0x8009F1B4 */
    R[2] = 0x8006u << 16;  /* 0x8009F1B8 */
L_8009F1BC:;
    R[3] = R[2] - 6456;  /* 0x8009F1BC */
    R[2] = lh_(R[3] + 6);  /* 0x8009F1C0 */
    R[2] = R[2] & 0x2000;  /* 0x8009F1C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F214; } }  /* 0x8009F1CC */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F1D4 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F1DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F218; } }  /* 0x8009F1E0 */
    R[3] = lh_(R[3] + 2);  /* 0x8009F1E8 */
    R[2] = R[3] & 0x8;  /* 0x8009F1F0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F20C; } }  /* 0x8009F1F4 */
    R[2] = R[3] & 0x2;  /* 0x8009F1FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F20C; } }  /* 0x8009F200 */
    R[4] = R[0] + 100;  /* 0x8009F208 */
L_8009F20C:;
    { R[31] = 0x8009F214u; psx_next = 0x8009ECECu; return; }  /* 0x8009F20C jal */
L_8009F214:;
    R[2] = 0x8006u << 16;  /* 0x8009F214 */
L_8009F218:;
    R[3] = R[2] - 6456;  /* 0x8009F218 */
    R[2] = lh_(R[3] + 6);  /* 0x8009F21C */
    R[2] = R[2] & 0x8000;  /* 0x8009F224 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F270; } }  /* 0x8009F228 */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F230 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F238 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F274; } }  /* 0x8009F23C */
    R[3] = lh_(R[3] + 2);  /* 0x8009F244 */
    R[2] = R[3] & 0x8;  /* 0x8009F24C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F268; } }  /* 0x8009F250 */
    R[2] = R[3] & 0x2;  /* 0x8009F258 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    R[4] = R[0] + 100;  /* 0x8009F264 */
L_8009F268:;
    { R[31] = 0x8009F270u; psx_next = 0x8009EE0Cu; return; }  /* 0x8009F268 jal */
L_8009F270:;
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
L_8009F274:;
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
L_8009F2EC:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
L_8009F418:;
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F158(void) {
    R[4] = 0x800Bu << 16;  /* 0x8009F158 */
    R[3] = lw_(R[4] + 13488);  /* 0x8009F15C */
    R[2] = ((int32_t)R[3] < 8);  /* 0x8009F164 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_8009F178; } }  /* 0x8009F168 */
    { sw_(R[4] + 13488, R[2]); goto L_8009F17C; }  /* 0x8009F170 j */
L_8009F178:;
    sw_(R[4] + 13488, R[0]);  /* 0x8009F178 */
L_8009F17C:;
    R[2] = 0x8006u << 16;  /* 0x8009F17C */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F180 */
    R[2] = R[2] & 0x1000;  /* 0x8009F188 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F1BC; } }  /* 0x8009F18C */
    { R[31] = 0x8009F19Cu; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F194 jal */
    R[3] = 0x800Bu << 16;  /* 0x8009F19C */
    R[2] = lw_(R[3] + 13488);  /* 0x8009F1A0 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[2] - 1; if (_c) { goto L_8009F1B4; } }  /* 0x8009F1A8 */
    R[2] = R[0] + 8;  /* 0x8009F1B0 */
L_8009F1B4:;
    sw_(R[3] + 13488, R[2]);  /* 0x8009F1B4 */
    R[2] = 0x8006u << 16;  /* 0x8009F1B8 */
L_8009F1BC:;
    R[3] = R[2] - 6456;  /* 0x8009F1BC */
    R[2] = lh_(R[3] + 6);  /* 0x8009F1C0 */
    R[2] = R[2] & 0x2000;  /* 0x8009F1C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F214; } }  /* 0x8009F1CC */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F1D4 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F1DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F218; } }  /* 0x8009F1E0 */
    R[3] = lh_(R[3] + 2);  /* 0x8009F1E8 */
    R[2] = R[3] & 0x8;  /* 0x8009F1F0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F20C; } }  /* 0x8009F1F4 */
    R[2] = R[3] & 0x2;  /* 0x8009F1FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F20C; } }  /* 0x8009F200 */
    R[4] = R[0] + 100;  /* 0x8009F208 */
L_8009F20C:;
    { R[31] = 0x8009F214u; psx_next = 0x8009ECECu; return; }  /* 0x8009F20C jal */
L_8009F214:;
    R[2] = 0x8006u << 16;  /* 0x8009F214 */
L_8009F218:;
    R[3] = R[2] - 6456;  /* 0x8009F218 */
    R[2] = lh_(R[3] + 6);  /* 0x8009F21C */
    R[2] = R[2] & 0x8000;  /* 0x8009F224 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F270; } }  /* 0x8009F228 */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F230 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F238 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F274; } }  /* 0x8009F23C */
    R[3] = lh_(R[3] + 2);  /* 0x8009F244 */
    R[2] = R[3] & 0x8;  /* 0x8009F24C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F268; } }  /* 0x8009F250 */
    R[2] = R[3] & 0x2;  /* 0x8009F258 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    R[4] = R[0] + 100;  /* 0x8009F264 */
L_8009F268:;
    { R[31] = 0x8009F270u; psx_next = 0x8009EE0Cu; return; }  /* 0x8009F268 jal */
L_8009F270:;
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
L_8009F274:;
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F19C(void) {
    R[3] = 0x800Bu << 16;  /* 0x8009F19C */
    R[2] = lw_(R[3] + 13488);  /* 0x8009F1A0 */
    { uint32_t _c = ((int32_t)R[2] > 0); R[2] = R[2] - 1; if (_c) { goto L_8009F1B4; } }  /* 0x8009F1A8 */
    R[2] = R[0] + 8;  /* 0x8009F1B0 */
L_8009F1B4:;
    sw_(R[3] + 13488, R[2]);  /* 0x8009F1B4 */
    R[2] = 0x8006u << 16;  /* 0x8009F1B8 */
    R[3] = R[2] - 6456;  /* 0x8009F1BC */
    R[2] = lh_(R[3] + 6);  /* 0x8009F1C0 */
    R[2] = R[2] & 0x2000;  /* 0x8009F1C8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F214; } }  /* 0x8009F1CC */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F1D4 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F1DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F218; } }  /* 0x8009F1E0 */
    R[3] = lh_(R[3] + 2);  /* 0x8009F1E8 */
    R[2] = R[3] & 0x8;  /* 0x8009F1F0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F20C; } }  /* 0x8009F1F4 */
    R[2] = R[3] & 0x2;  /* 0x8009F1FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F20C; } }  /* 0x8009F200 */
    R[4] = R[0] + 100;  /* 0x8009F208 */
L_8009F20C:;
    { R[31] = 0x8009F214u; psx_next = 0x8009ECECu; return; }  /* 0x8009F20C jal */
L_8009F214:;
    R[2] = 0x8006u << 16;  /* 0x8009F214 */
L_8009F218:;
    R[3] = R[2] - 6456;  /* 0x8009F218 */
    R[2] = lh_(R[3] + 6);  /* 0x8009F21C */
    R[2] = R[2] & 0x8000;  /* 0x8009F224 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F270; } }  /* 0x8009F228 */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F230 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F238 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F274; } }  /* 0x8009F23C */
    R[3] = lh_(R[3] + 2);  /* 0x8009F244 */
    R[2] = R[3] & 0x8;  /* 0x8009F24C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F268; } }  /* 0x8009F250 */
    R[2] = R[3] & 0x2;  /* 0x8009F258 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    R[4] = R[0] + 100;  /* 0x8009F264 */
L_8009F268:;
    { R[31] = 0x8009F270u; psx_next = 0x8009EE0Cu; return; }  /* 0x8009F268 jal */
L_8009F270:;
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
L_8009F274:;
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F214(void) {
    R[2] = 0x8006u << 16;  /* 0x8009F214 */
    R[3] = R[2] - 6456;  /* 0x8009F218 */
    R[2] = lh_(R[3] + 6);  /* 0x8009F21C */
    R[2] = R[2] & 0x8000;  /* 0x8009F224 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F270; } }  /* 0x8009F228 */
    R[2] = lw_(R[2] + 13488);  /* 0x8009F230 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x8009F238 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F274; } }  /* 0x8009F23C */
    R[3] = lh_(R[3] + 2);  /* 0x8009F244 */
    R[2] = R[3] & 0x8;  /* 0x8009F24C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 10; if (_c) { goto L_8009F268; } }  /* 0x8009F250 */
    R[2] = R[3] & 0x2;  /* 0x8009F258 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 1; if (_c) { goto L_8009F268; } }  /* 0x8009F25C */
    R[4] = R[0] + 100;  /* 0x8009F264 */
L_8009F268:;
    { R[31] = 0x8009F270u; psx_next = 0x8009EE0Cu; return; }  /* 0x8009F268 jal */
L_8009F270:;
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
L_8009F274:;
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F270(void) {
    R[2] = 0x8006u << 16;  /* 0x8009F270 */
    R[4] = lh_(R[2] + -6452);  /* 0x8009F274 */
    R[2] = R[4] & 0xA0;  /* 0x8009F27C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_8009F298; } }  /* 0x8009F280 */
    R[3] = lw_(R[2] + 13488);  /* 0x8009F288 */
    R[2] = R[0] + 8;  /* 0x8009F28C */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009F2A4; } }  /* 0x8009F290 */
L_8009F298:;
    R[2] = R[4] & 0x800;  /* 0x8009F298 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F2B8; } }  /* 0x8009F29C */
L_8009F2A4:;
    { R[31] = 0x8009F2ACu; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F2A4 jal */
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
L_8009F2B8:;
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F2AC(void) {
    { R[31] = 0x8009F2B4u; psx_next = 0x8009BDB4u; return; }  /* 0x8009F2AC jal */
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F2B4(void) {
    R[2] = 0x8006u << 16;  /* 0x8009F2B4 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F2B8 */
    R[2] = R[2] & 0x40;  /* 0x8009F2C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009F2DC; } }  /* 0x8009F2C4 */
    { R[31] = 0x8009F2D4u; R[4] = R[0] + 2; psx_next = 0x8009BCA4u; return; }  /* 0x8009F2CC jal */
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
L_8009F2DC:;
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F2D4(void) {
    { R[31] = 0x8009F2DCu; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F2D4 jal */
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F2DC(void) {
    { R[31] = 0x8009F2E4u; psx_next = 0x800A101Cu; return; }  /* 0x8009F2DC jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F2E4(void) {
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F2E4 j extern */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009F3F0; } }  /* 0x8009F2EC */
    R[2] = 0x8006u << 16;  /* 0x8009F2F4 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F2F8 */
    R[2] = R[2] & 0x8000;  /* 0x8009F300 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F328; } }  /* 0x8009F304 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F30C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009F324; } }  /* 0x8009F314 */
    { R[31] = 0x8009F324u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F31C jal */
L_8009F324:;
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
L_8009F328:;
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
L_8009F3F0:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F324(void) {
    sw_(R[16] + 13488, R[0]);  /* 0x8009F324 */
    R[2] = 0x8006u << 16;  /* 0x8009F328 */
    R[2] = lh_(R[2] + -6450);  /* 0x8009F32C */
    R[2] = R[2] & 0x2000;  /* 0x8009F334 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F360; } }  /* 0x8009F338 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F340 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F35C; } }  /* 0x8009F348 */
    { R[31] = 0x8009F358u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F350 jal */
    R[2] = R[0] + 1;  /* 0x8009F358 */
L_8009F35C:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
L_8009F360:;
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F358(void) {
    R[2] = R[0] + 1;  /* 0x8009F358 */
    sw_(R[16] + 13488, R[2]);  /* 0x8009F35C */
    R[2] = 0x8006u << 16;  /* 0x8009F360 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F364 */
    R[2] = R[3] & 0xA0;  /* 0x8009F36C */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F3C0; } }  /* 0x8009F370 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F378 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F3A0; } }  /* 0x8009F380 */
    { R[31] = 0x8009F390u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F388 jal */
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
L_8009F3A0:;
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
L_8009F3C0:;
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F390(void) {
    { R[31] = 0x8009F398u; R[4] = R[0] + R[0]; psx_next = 0x8009BE90u; return; }  /* 0x8009F390 jal */
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F398(void) {
    { R[2] = R[0] + R[0]; psx_next = 0x8009F57Cu; return; }  /* 0x8009F398 j extern */
    { R[31] = 0x8009F3A8u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3A0 jal */
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F3A8(void) {
    R[2] = 0x800Fu << 16;  /* 0x8009F3A8 */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3AC */
    R[2] = 0x800Bu << 16;  /* 0x8009F3B0 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3B4 */
    { sw_(R[16] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3B8 j extern */
    R[2] = R[3] & 0x40;  /* 0x8009F3C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3C4 b extern */
    { R[31] = 0x8009F3D4u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F3CC jal */
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F3D4(void) {
    R[2] = 0x800Bu << 16;  /* 0x8009F3D4 */
    sw_(R[2] + 13484, R[0]);  /* 0x8009F3D8 */
    R[2] = 0x800Fu << 16;  /* 0x8009F3DC */
    R[3] = lw_(R[2] + -732);  /* 0x8009F3E0 */
    R[2] = 0x800Bu << 16;  /* 0x8009F3E4 */
    { sw_(R[2] + 13488, R[3]); psx_next = 0x8009F578u; return; }  /* 0x8009F3E8 j extern */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F3F0 b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F3F8 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F3FC */
    R[2] = R[2] & 0xE0;  /* 0x8009F404 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F408 b extern */
    { sw_(R[5] + 13484, R[0]); psx_next = 0x8009F57Cu; return; }  /* 0x8009F410 j extern */
    R[3] = lw_(R[2] + 13480);  /* 0x8009F418 */
    R[2] = R[0] + 5;  /* 0x8009F41C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 6; if (_c) { goto L_8009F43C; } }  /* 0x8009F420 */
    R[2] = 0x800Bu << 16;  /* 0x8009F428 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F42C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 6; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F434 b extern */
L_8009F43C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 7; if (_c) { goto L_8009F458; } }  /* 0x8009F43C */
    R[2] = 0x800Bu << 16;  /* 0x8009F444 */
    R[2] = lw_(R[2] + 13668);  /* 0x8009F448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 7; if (_c) { psx_next = 0x8009F578u; return; } }  /* 0x8009F450 b extern */
L_8009F458:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F458 b extern */
    R[2] = 0x800Bu << 16;  /* 0x8009F460 */
    R[2] = lw_(R[2] + 13676);  /* 0x8009F464 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009F57Cu; return; } }  /* 0x8009F46C b extern */
    R[2] = 0x8006u << 16;  /* 0x8009F474 */
    R[2] = lw_(R[2] + 16068);  /* 0x8009F478 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009F4F4; } }  /* 0x8009F480 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F488 */
    R[2] = R[2] & 0x4000;  /* 0x8009F490 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F4BC; } }  /* 0x8009F494 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F49C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009F4B8; } }  /* 0x8009F4A4 */
    { R[31] = 0x8009F4B4u; R[4] = R[0] + 1; psx_next = 0x8002DB10u; return; }  /* 0x8009F4AC jal */
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
L_8009F4B8:;
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
L_8009F4BC:;
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
L_8009F4F4:;
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F4B4(void) {
    R[2] = R[0] + 1;  /* 0x8009F4B4 */
    sw_(R[16] + 13488, R[2]);  /* 0x8009F4B8 */
    R[2] = 0x8006u << 16;  /* 0x8009F4BC */
    R[2] = lh_(R[2] + -6452);  /* 0x8009F4C0 */
    R[2] = R[2] & 0x1000;  /* 0x8009F4C8 */
    { uint32_t _c = (R[2] == R[0]); R[16] = 0x800Bu << 16; if (_c) { goto L_8009F500; } }  /* 0x8009F4CC */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F4D4 */
    R[2] = R[0] + 1;  /* 0x8009F4D8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009F4EC; } }  /* 0x8009F4DC */
    { R[31] = 0x8009F4ECu; R[4] = R[2] + R[0]; psx_next = 0x8002DB10u; return; }  /* 0x8009F4E4 jal */
L_8009F4EC:;
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F4EC(void) {
    { sw_(R[16] + 13488, R[0]); goto L_8009F500; }  /* 0x8009F4EC j */
    R[3] = 0x800Bu << 16;  /* 0x8009F4F4 */
    R[2] = R[0] + 1;  /* 0x8009F4F8 */
    sw_(R[3] + 13488, R[2]);  /* 0x8009F4FC */
L_8009F500:;
    R[2] = 0x8006u << 16;  /* 0x8009F500 */
    R[3] = lh_(R[2] + -6452);  /* 0x8009F504 */
    R[2] = R[3] & 0xA0;  /* 0x8009F50C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x40; if (_c) { psx_next = 0x8009F560u; return; } }  /* 0x8009F510 b extern */
    { R[31] = 0x8009F520u; R[4] = R[0] + 2; psx_next = 0x8002DB10u; return; }  /* 0x8009F518 jal */
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F520(void) {
    R[16] = 0x800Bu << 16;  /* 0x8009F520 */
    R[2] = lw_(R[16] + 13488);  /* 0x8009F524 */
    psx_next = 0x8009F528u; return;  /* fallthrough */
}

void ev_8009F528(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009F548; } }  /* 0x8009F52C */
    { R[31] = 0x8009F53Cu; R[4] = R[0] + 1; psx_next = 0x8009BCA4u; return; }  /* 0x8009F534 jal */
    R[3] = 0x800Fu << 16;  /* 0x8009F53C */
    R[2] = R[0] + 1;  /* 0x8009F540 */
    sb_(R[3] + 27968, R[2]);  /* 0x8009F544 */
L_8009F548:;
    R[3] = lw_(R[16] + 13488);  /* 0x8009F548 */
    R[2] = R[0] + 1;  /* 0x8009F54C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009F57C; } }  /* 0x8009F550 */
    { R[2] = R[0] - 1; goto L_8009F57C; }  /* 0x8009F558 j */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009F57C; } }  /* 0x8009F560 */
    { R[31] = 0x8009F570u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F568 jal */
    { R[2] = R[0] - 1; goto L_8009F57C; }  /* 0x8009F570 j */
    R[2] = R[0] + R[0];  /* 0x8009F578 */
L_8009F57C:;
    R[31] = lw_(R[29] + 24);  /* 0x8009F57C */
    R[17] = lw_(R[29] + 20);  /* 0x8009F580 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F584 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F588 jr ra */
}

void ev_8009F53C(void) {
    R[3] = 0x800Fu << 16;  /* 0x8009F53C */
    R[2] = R[0] + 1;  /* 0x8009F540 */
    sb_(R[3] + 27968, R[2]);  /* 0x8009F544 */
    R[3] = lw_(R[16] + 13488);  /* 0x8009F548 */
    R[2] = R[0] + 1;  /* 0x8009F54C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009F57C; } }  /* 0x8009F550 */
    { R[2] = R[0] - 1; goto L_8009F57C; }  /* 0x8009F558 j */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009F57C; } }  /* 0x8009F560 */
    { R[31] = 0x8009F570u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F568 jal */
    { R[2] = R[0] - 1; goto L_8009F57C; }  /* 0x8009F570 j */
    R[2] = R[0] + R[0];  /* 0x8009F578 */
L_8009F57C:;
    R[31] = lw_(R[29] + 24);  /* 0x8009F57C */
    R[17] = lw_(R[29] + 20);  /* 0x8009F580 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F584 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F588 jr ra */
}

void ev_8009F560(void) {
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009F57C; } }  /* 0x8009F560 */
    { R[31] = 0x8009F570u; R[4] = R[0] + 3; psx_next = 0x8002DB10u; return; }  /* 0x8009F568 jal */
    { R[2] = R[0] - 1; goto L_8009F57C; }  /* 0x8009F570 j */
    R[2] = R[0] + R[0];  /* 0x8009F578 */
L_8009F57C:;
    R[31] = lw_(R[29] + 24);  /* 0x8009F57C */
    R[17] = lw_(R[29] + 20);  /* 0x8009F580 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F584 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F588 jr ra */
}

void ev_8009F570(void) {
    { R[2] = R[0] - 1; goto L_8009F57C; }  /* 0x8009F570 j */
    R[2] = R[0] + R[0];  /* 0x8009F578 */
L_8009F57C:;
    R[31] = lw_(R[29] + 24);  /* 0x8009F57C */
    R[17] = lw_(R[29] + 20);  /* 0x8009F580 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F584 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F588 jr ra */
}

void ev_8009F578(void) {
    R[2] = R[0] + R[0];  /* 0x8009F578 */
    R[31] = lw_(R[29] + 24);  /* 0x8009F57C */
    R[17] = lw_(R[29] + 20);  /* 0x8009F580 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F584 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F588 jr ra */
}

void ev_8009F57C(void) {
    R[31] = lw_(R[29] + 24);  /* 0x8009F57C */
    R[17] = lw_(R[29] + 20);  /* 0x8009F580 */
    R[16] = lw_(R[29] + 16);  /* 0x8009F584 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009F588 jr ra */
}

void ev_8009F590(void) {
    R[29] = R[29] - 40;  /* 0x8009F590 */
    sw_(R[29] + 28, R[17]);  /* 0x8009F594 */
    R[17] = R[0] + R[0];  /* 0x8009F598 */
    R[5] = 0x800Bu << 16;  /* 0x8009F59C */
    R[6] = R[17] + R[0];  /* 0x8009F5A0 */
    sw_(R[29] + 36, R[31]);  /* 0x8009F5A4 */
    sw_(R[29] + 32, R[18]);  /* 0x8009F5A8 */
    sw_(R[29] + 24, R[16]);  /* 0x8009F5AC */
    R[4] = R[0] + R[0];  /* 0x8009F5B0 */
    R[3] = R[6] + R[0];  /* 0x8009F5B4 */
    R[2] = lw_(R[5] + 14000);  /* 0x8009F5B8 */
    R[2] = R[2] + R[3];  /* 0x8009F5C0 */
    psx_next = 0x8009F5C4u; return;  /* fallthrough */
}

void ev_8009F5B0(void) {
    R[4] = R[0] + R[0];  /* 0x8009F5B0 */
    R[3] = R[6] + R[0];  /* 0x8009F5B4 */
    R[2] = lw_(R[5] + 14000);  /* 0x8009F5B8 */
    R[2] = R[2] + R[3];  /* 0x8009F5C0 */
    psx_next = 0x8009F5C4u; return;  /* fallthrough */
}

void ev_8009F5B8(void) {
    R[2] = lw_(R[5] + 14000);  /* 0x8009F5B8 */
    R[2] = R[2] + R[3];  /* 0x8009F5C0 */
    psx_next = 0x8009F5C4u; return;  /* fallthrough */
}

void ev_8009F5C4(void) {
    sb_(R[2] + 61, R[0]);  /* 0x8009F5C4 */
    R[2] = lw_(R[5] + 14000);  /* 0x8009F5C8 */
    R[2] = R[2] + R[3];  /* 0x8009F5D0 */
    sb_(R[2] + 62, R[0]);  /* 0x8009F5D4 */
    R[2] = lw_(R[5] + 14000);  /* 0x8009F5D8 */
    R[4] = R[4] + 1;  /* 0x8009F5DC */
    R[2] = R[2] + R[3];  /* 0x8009F5E0 */
    sb_(R[2] + 63, R[0]);  /* 0x8009F5E4 */
    R[2] = ((int32_t)R[4] < 3);  /* 0x8009F5E8 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 3; if (_c) { psx_next = 0x8009F5B8u; return; } }  /* 0x8009F5EC b extern */
    R[17] = R[17] + 1;  /* 0x8009F5F4 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F5F8 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[6] + 72; if (_c) { psx_next = 0x8009F5B0u; return; } }  /* 0x8009F5FC b extern */
    R[17] = R[0] + R[0];  /* 0x8009F604 */
    R[18] = 0x800Bu << 16;  /* 0x8009F608 */
    R[16] = R[17] + R[0];  /* 0x8009F60C */
L_8009F610:;
    R[4] = lw_(R[18] + 14000);  /* 0x8009F610 */
    { R[31] = 0x8009F61Cu; R[4] = R[4] + R[16]; psx_next = 0x8009F984u; return; }  /* 0x8009F614 jal */
    R[4] = lw_(R[18] + 14000);  /* 0x8009F61C */
    { R[31] = 0x8009F628u; R[4] = R[4] + R[16]; psx_next = 0x8009FA48u; return; }  /* 0x8009F620 jal */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F628 */
    R[2] = R[2] + R[16];  /* 0x8009F630 */
    sb_(R[2] + 71, R[0]);  /* 0x8009F634 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F638 */
    R[2] = R[2] + R[16];  /* 0x8009F640 */
    sb_(R[2] + 70, R[0]);  /* 0x8009F644 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F648 */
    R[2] = R[2] + R[16];  /* 0x8009F650 */
    sb_(R[2] + 58, R[0]);  /* 0x8009F654 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F658 */
    R[2] = R[2] + R[16];  /* 0x8009F660 */
    sb_(R[2] + 59, R[0]);  /* 0x8009F664 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F668 */
    R[17] = R[17] + 1;  /* 0x8009F66C */
    R[2] = R[2] + R[16];  /* 0x8009F670 */
    sb_(R[2] + 60, R[0]);  /* 0x8009F674 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F678 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 72; if (_c) { psx_bb(); goto L_8009F610; } }  /* 0x8009F67C */
    R[16] = 0x800Bu << 16;  /* 0x8009F684 */
    R[4] = lw_(R[16] + 14000);  /* 0x8009F688 */
    { R[31] = 0x8009F694u; R[5] = R[4] + 72; psx_next = 0x800A0224u; return; }  /* 0x8009F68C jal */
    R[5] = lw_(R[16] + 14000);  /* 0x8009F694 */
    R[4] = R[5] + 144;  /* 0x8009F69C */
    { R[31] = 0x8009F6A8u; R[5] = R[5] + 216; psx_next = 0x800A0224u; return; }  /* 0x8009F6A0 jal */
    R[5] = lw_(R[16] + 14000);  /* 0x8009F6A8 */
    R[4] = R[5] + 288;  /* 0x8009F6B0 */
    { R[31] = 0x8009F6BCu; R[5] = R[5] + 360; psx_next = 0x800A0224u; return; }  /* 0x8009F6B4 jal */
    R[5] = lw_(R[16] + 14000);  /* 0x8009F6BC */
    R[17] = R[0] + R[0];  /* 0x8009F6C0 */
    R[4] = R[5] + 432;  /* 0x8009F6C4 */
    { R[31] = 0x8009F6D0u; R[5] = R[5] + 504; psx_next = 0x800A0224u; return; }  /* 0x8009F6C8 jal */
    R[7] = R[0] + 1;  /* 0x8009F6D0 */
    R[3] = R[29] + 16;  /* 0x8009F6D4 */
    R[6] = R[7] + R[0];  /* 0x8009F6D8 */
    R[5] = R[17] + R[0];  /* 0x8009F6DC */
    R[4] = R[17] + R[0];  /* 0x8009F6E0 */
L_8009F6E4:;
    R[2] = lw_(R[16] + 14000);  /* 0x8009F6E4 */
    R[2] = R[2] + R[4];  /* 0x8009F6EC */
    R[2] = lb_(R[2] + 71);  /* 0x8009F6F0 */
    { uint32_t _c = (R[2] != R[7]); if (_c) { goto L_8009F708; } }  /* 0x8009F6F8 */
    { sb_(R[3], R[5]); goto L_8009F70C; }  /* 0x8009F700 j */
L_8009F708:;
    sb_(R[3], R[6]);  /* 0x8009F708 */
L_8009F70C:;
    R[3] = R[3] + 1;  /* 0x8009F70C */
    R[6] = R[6] + 2;  /* 0x8009F710 */
    R[5] = R[5] + 2;  /* 0x8009F714 */
    R[17] = R[17] + 1;  /* 0x8009F718 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F71C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[4] + 144; if (_c) { psx_bb(); goto L_8009F6E4; } }  /* 0x8009F720 */
    R[17] = R[0] + R[0];  /* 0x8009F728 */
    R[18] = 0x800Bu << 16;  /* 0x8009F72C */
    R[16] = R[29] + 16;  /* 0x8009F730 */
L_8009F734:;
    R[16] = R[16] + R[17];  /* 0x8009F734 */
    R[3] = lb_(R[16]);  /* 0x8009F738 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F73C */
    R[2] = R[3] << 3;  /* 0x8009F740 */
    R[2] = R[2] + R[3];  /* 0x8009F744 */
    R[2] = R[2] << 3;  /* 0x8009F748 */
    R[2] = R[5] + R[2];  /* 0x8009F74C */
    R[3] = lw_(R[2] + 48);  /* 0x8009F750 */
    sw_(R[2] + 4, R[3]);  /* 0x8009F758 */
    R[2] = lb_(R[16]);  /* 0x8009F75C */
    R[4] = R[2] << 3;  /* 0x8009F764 */
    R[4] = R[4] + R[2];  /* 0x8009F768 */
    R[4] = R[4] << 3;  /* 0x8009F76C */
    { R[31] = 0x8009F778u; R[4] = R[5] + R[4]; psx_next = 0x8009F984u; return; }  /* 0x8009F770 jal */
    R[2] = lb_(R[16]);  /* 0x8009F778 */
    R[4] = R[2] << 3;  /* 0x8009F780 */
    R[4] = R[4] + R[2];  /* 0x8009F784 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F788 */
    R[4] = R[4] << 3;  /* 0x8009F78C */
    { R[31] = 0x8009F798u; R[4] = R[2] + R[4]; psx_next = 0x8009FA48u; return; }  /* 0x8009F790 jal */
    R[3] = lb_(R[16]);  /* 0x8009F798 */
    R[17] = R[17] + 1;  /* 0x8009F79C */
    R[2] = R[3] << 3;  /* 0x8009F7A0 */
    R[2] = R[2] + R[3];  /* 0x8009F7A4 */
    R[3] = lw_(R[18] + 14000);  /* 0x8009F7A8 */
    R[2] = R[2] << 3;  /* 0x8009F7AC */
    R[3] = R[3] + R[2];  /* 0x8009F7B0 */
    R[2] = R[0] + 1;  /* 0x8009F7B4 */
    sb_(R[3] + 70, R[2]);  /* 0x8009F7B8 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F7BC */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[29] + 16; if (_c) { psx_bb(); goto L_8009F734; } }  /* 0x8009F7C0 */
    R[16] = 0x800Bu << 16;  /* 0x8009F7C8 */
    R[2] = lb_(R[29] + 16);  /* 0x8009F7CC */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F7D0 */
    R[4] = R[2] << 3;  /* 0x8009F7D4 */
    R[4] = R[4] + R[2];  /* 0x8009F7D8 */
    R[4] = R[4] << 3;  /* 0x8009F7DC */
    R[2] = lb_(R[29] + 17);  /* 0x8009F7E0 */
    R[4] = R[3] + R[4];  /* 0x8009F7E4 */
    R[5] = R[2] << 3;  /* 0x8009F7E8 */
    R[5] = R[5] + R[2];  /* 0x8009F7EC */
    R[5] = R[5] << 3;  /* 0x8009F7F0 */
    { R[31] = 0x8009F7FCu; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F7F4 jal */
    R[17] = R[0] + R[0];  /* 0x8009F7FC */
    R[2] = lb_(R[29] + 18);  /* 0x8009F800 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F804 */
    R[4] = R[2] << 3;  /* 0x8009F808 */
    R[4] = R[4] + R[2];  /* 0x8009F80C */
    R[4] = R[4] << 3;  /* 0x8009F810 */
    R[2] = lb_(R[29] + 19);  /* 0x8009F814 */
    R[4] = R[3] + R[4];  /* 0x8009F818 */
    R[5] = R[2] << 3;  /* 0x8009F81C */
    R[5] = R[5] + R[2];  /* 0x8009F820 */
    R[5] = R[5] << 3;  /* 0x8009F824 */
    { R[31] = 0x8009F830u; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F828 jal */
    R[4] = R[0] + 2;  /* 0x8009F830 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F834 */
L_8009F838:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F83C */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F850; } }  /* 0x8009F844 */
    sb_(R[29] + 16, R[17]);  /* 0x8009F84C */
L_8009F850:;
    R[17] = R[17] + 1;  /* 0x8009F850 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F854 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F838; } }  /* 0x8009F858 */
    R[17] = R[0] + 4;  /* 0x8009F860 */
    R[2] = 0x800Bu << 16;  /* 0x8009F864 */
    R[2] = lw_(R[2] + 14000);  /* 0x8009F868 */
    R[4] = R[0] + 2;  /* 0x8009F86C */
    R[3] = R[2] + 288;  /* 0x8009F870 */
L_8009F874:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F874 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F888; } }  /* 0x8009F87C */
    sb_(R[29] + 17, R[17]);  /* 0x8009F884 */
L_8009F888:;
    R[17] = R[17] + 1;  /* 0x8009F888 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F88C */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F874; } }  /* 0x8009F890 */
    R[17] = R[0] + R[0];  /* 0x8009F898 */
    R[18] = 0x800Bu << 16;  /* 0x8009F89C */
    R[16] = R[29] + 16;  /* 0x8009F8A0 */
    R[16] = R[16] + R[17];  /* 0x8009F8A4 */
    R[3] = lb_(R[16]);  /* 0x8009F8A8 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F8AC */
    R[2] = R[3] << 3;  /* 0x8009F8B0 */
    R[2] = R[2] + R[3];  /* 0x8009F8B4 */
    R[2] = R[2] << 3;  /* 0x8009F8B8 */
    psx_next = 0x8009F8BCu; return;  /* fallthrough */
}

void ev_8009F610(void) {
L_8009F610:;
    R[4] = lw_(R[18] + 14000);  /* 0x8009F610 */
    { R[31] = 0x8009F61Cu; R[4] = R[4] + R[16]; psx_next = 0x8009F984u; return; }  /* 0x8009F614 jal */
    R[4] = lw_(R[18] + 14000);  /* 0x8009F61C */
    { R[31] = 0x8009F628u; R[4] = R[4] + R[16]; psx_next = 0x8009FA48u; return; }  /* 0x8009F620 jal */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F628 */
    R[2] = R[2] + R[16];  /* 0x8009F630 */
    sb_(R[2] + 71, R[0]);  /* 0x8009F634 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F638 */
    R[2] = R[2] + R[16];  /* 0x8009F640 */
    sb_(R[2] + 70, R[0]);  /* 0x8009F644 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F648 */
    R[2] = R[2] + R[16];  /* 0x8009F650 */
    sb_(R[2] + 58, R[0]);  /* 0x8009F654 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F658 */
    R[2] = R[2] + R[16];  /* 0x8009F660 */
    sb_(R[2] + 59, R[0]);  /* 0x8009F664 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F668 */
    R[17] = R[17] + 1;  /* 0x8009F66C */
    R[2] = R[2] + R[16];  /* 0x8009F670 */
    sb_(R[2] + 60, R[0]);  /* 0x8009F674 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F678 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 72; if (_c) { psx_bb(); goto L_8009F610; } }  /* 0x8009F67C */
    R[16] = 0x800Bu << 16;  /* 0x8009F684 */
    R[4] = lw_(R[16] + 14000);  /* 0x8009F688 */
    { R[31] = 0x8009F694u; R[5] = R[4] + 72; psx_next = 0x800A0224u; return; }  /* 0x8009F68C jal */
    R[5] = lw_(R[16] + 14000);  /* 0x8009F694 */
    R[4] = R[5] + 144;  /* 0x8009F69C */
    { R[31] = 0x8009F6A8u; R[5] = R[5] + 216; psx_next = 0x800A0224u; return; }  /* 0x8009F6A0 jal */
    R[5] = lw_(R[16] + 14000);  /* 0x8009F6A8 */
    R[4] = R[5] + 288;  /* 0x8009F6B0 */
    { R[31] = 0x8009F6BCu; R[5] = R[5] + 360; psx_next = 0x800A0224u; return; }  /* 0x8009F6B4 jal */
    R[5] = lw_(R[16] + 14000);  /* 0x8009F6BC */
    R[17] = R[0] + R[0];  /* 0x8009F6C0 */
    R[4] = R[5] + 432;  /* 0x8009F6C4 */
    { R[31] = 0x8009F6D0u; R[5] = R[5] + 504; psx_next = 0x800A0224u; return; }  /* 0x8009F6C8 jal */
    R[7] = R[0] + 1;  /* 0x8009F6D0 */
    R[3] = R[29] + 16;  /* 0x8009F6D4 */
    R[6] = R[7] + R[0];  /* 0x8009F6D8 */
    R[5] = R[17] + R[0];  /* 0x8009F6DC */
    R[4] = R[17] + R[0];  /* 0x8009F6E0 */
L_8009F6E4:;
    R[2] = lw_(R[16] + 14000);  /* 0x8009F6E4 */
    R[2] = R[2] + R[4];  /* 0x8009F6EC */
    R[2] = lb_(R[2] + 71);  /* 0x8009F6F0 */
    { uint32_t _c = (R[2] != R[7]); if (_c) { goto L_8009F708; } }  /* 0x8009F6F8 */
    { sb_(R[3], R[5]); goto L_8009F70C; }  /* 0x8009F700 j */
L_8009F708:;
    sb_(R[3], R[6]);  /* 0x8009F708 */
L_8009F70C:;
    R[3] = R[3] + 1;  /* 0x8009F70C */
    R[6] = R[6] + 2;  /* 0x8009F710 */
    R[5] = R[5] + 2;  /* 0x8009F714 */
    R[17] = R[17] + 1;  /* 0x8009F718 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F71C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[4] + 144; if (_c) { psx_bb(); goto L_8009F6E4; } }  /* 0x8009F720 */
    R[17] = R[0] + R[0];  /* 0x8009F728 */
    R[18] = 0x800Bu << 16;  /* 0x8009F72C */
    R[16] = R[29] + 16;  /* 0x8009F730 */
L_8009F734:;
    R[16] = R[16] + R[17];  /* 0x8009F734 */
    R[3] = lb_(R[16]);  /* 0x8009F738 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F73C */
    R[2] = R[3] << 3;  /* 0x8009F740 */
    R[2] = R[2] + R[3];  /* 0x8009F744 */
    R[2] = R[2] << 3;  /* 0x8009F748 */
    R[2] = R[5] + R[2];  /* 0x8009F74C */
    R[3] = lw_(R[2] + 48);  /* 0x8009F750 */
    sw_(R[2] + 4, R[3]);  /* 0x8009F758 */
    R[2] = lb_(R[16]);  /* 0x8009F75C */
    R[4] = R[2] << 3;  /* 0x8009F764 */
    R[4] = R[4] + R[2];  /* 0x8009F768 */
    R[4] = R[4] << 3;  /* 0x8009F76C */
    { R[31] = 0x8009F778u; R[4] = R[5] + R[4]; psx_next = 0x8009F984u; return; }  /* 0x8009F770 jal */
    R[2] = lb_(R[16]);  /* 0x8009F778 */
    R[4] = R[2] << 3;  /* 0x8009F780 */
    R[4] = R[4] + R[2];  /* 0x8009F784 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F788 */
    R[4] = R[4] << 3;  /* 0x8009F78C */
    { R[31] = 0x8009F798u; R[4] = R[2] + R[4]; psx_next = 0x8009FA48u; return; }  /* 0x8009F790 jal */
    R[3] = lb_(R[16]);  /* 0x8009F798 */
    R[17] = R[17] + 1;  /* 0x8009F79C */
    R[2] = R[3] << 3;  /* 0x8009F7A0 */
    R[2] = R[2] + R[3];  /* 0x8009F7A4 */
    R[3] = lw_(R[18] + 14000);  /* 0x8009F7A8 */
    R[2] = R[2] << 3;  /* 0x8009F7AC */
    R[3] = R[3] + R[2];  /* 0x8009F7B0 */
    R[2] = R[0] + 1;  /* 0x8009F7B4 */
    sb_(R[3] + 70, R[2]);  /* 0x8009F7B8 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F7BC */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[29] + 16; if (_c) { psx_bb(); goto L_8009F734; } }  /* 0x8009F7C0 */
    R[16] = 0x800Bu << 16;  /* 0x8009F7C8 */
    R[2] = lb_(R[29] + 16);  /* 0x8009F7CC */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F7D0 */
    R[4] = R[2] << 3;  /* 0x8009F7D4 */
    R[4] = R[4] + R[2];  /* 0x8009F7D8 */
    R[4] = R[4] << 3;  /* 0x8009F7DC */
    R[2] = lb_(R[29] + 17);  /* 0x8009F7E0 */
    R[4] = R[3] + R[4];  /* 0x8009F7E4 */
    R[5] = R[2] << 3;  /* 0x8009F7E8 */
    R[5] = R[5] + R[2];  /* 0x8009F7EC */
    R[5] = R[5] << 3;  /* 0x8009F7F0 */
    { R[31] = 0x8009F7FCu; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F7F4 jal */
    R[17] = R[0] + R[0];  /* 0x8009F7FC */
    R[2] = lb_(R[29] + 18);  /* 0x8009F800 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F804 */
    R[4] = R[2] << 3;  /* 0x8009F808 */
    R[4] = R[4] + R[2];  /* 0x8009F80C */
    R[4] = R[4] << 3;  /* 0x8009F810 */
    R[2] = lb_(R[29] + 19);  /* 0x8009F814 */
    R[4] = R[3] + R[4];  /* 0x8009F818 */
    R[5] = R[2] << 3;  /* 0x8009F81C */
    R[5] = R[5] + R[2];  /* 0x8009F820 */
    R[5] = R[5] << 3;  /* 0x8009F824 */
    { R[31] = 0x8009F830u; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F828 jal */
    R[4] = R[0] + 2;  /* 0x8009F830 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F834 */
L_8009F838:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F83C */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F850; } }  /* 0x8009F844 */
    sb_(R[29] + 16, R[17]);  /* 0x8009F84C */
L_8009F850:;
    R[17] = R[17] + 1;  /* 0x8009F850 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F854 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F838; } }  /* 0x8009F858 */
    R[17] = R[0] + 4;  /* 0x8009F860 */
    R[2] = 0x800Bu << 16;  /* 0x8009F864 */
    R[2] = lw_(R[2] + 14000);  /* 0x8009F868 */
    R[4] = R[0] + 2;  /* 0x8009F86C */
    R[3] = R[2] + 288;  /* 0x8009F870 */
L_8009F874:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F874 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F888; } }  /* 0x8009F87C */
    sb_(R[29] + 17, R[17]);  /* 0x8009F884 */
L_8009F888:;
    R[17] = R[17] + 1;  /* 0x8009F888 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F88C */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F874; } }  /* 0x8009F890 */
    R[17] = R[0] + R[0];  /* 0x8009F898 */
    R[18] = 0x800Bu << 16;  /* 0x8009F89C */
    R[16] = R[29] + 16;  /* 0x8009F8A0 */
    R[16] = R[16] + R[17];  /* 0x8009F8A4 */
    R[3] = lb_(R[16]);  /* 0x8009F8A8 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F8AC */
    R[2] = R[3] << 3;  /* 0x8009F8B0 */
    R[2] = R[2] + R[3];  /* 0x8009F8B4 */
    R[2] = R[2] << 3;  /* 0x8009F8B8 */
    psx_next = 0x8009F8BCu; return;  /* fallthrough */
}

void ev_8009F61C(void) {
    R[4] = lw_(R[18] + 14000);  /* 0x8009F61C */
    { R[31] = 0x8009F628u; R[4] = R[4] + R[16]; psx_next = 0x8009FA48u; return; }  /* 0x8009F620 jal */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F628 */
    R[2] = R[2] + R[16];  /* 0x8009F630 */
    sb_(R[2] + 71, R[0]);  /* 0x8009F634 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F638 */
    R[2] = R[2] + R[16];  /* 0x8009F640 */
    sb_(R[2] + 70, R[0]);  /* 0x8009F644 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F648 */
    R[2] = R[2] + R[16];  /* 0x8009F650 */
    sb_(R[2] + 58, R[0]);  /* 0x8009F654 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F658 */
    R[2] = R[2] + R[16];  /* 0x8009F660 */
    sb_(R[2] + 59, R[0]);  /* 0x8009F664 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F668 */
    R[17] = R[17] + 1;  /* 0x8009F66C */
    R[2] = R[2] + R[16];  /* 0x8009F670 */
    sb_(R[2] + 60, R[0]);  /* 0x8009F674 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F678 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 72; if (_c) { psx_next = 0x8009F610u; return; } }  /* 0x8009F67C b extern */
    R[16] = 0x800Bu << 16;  /* 0x8009F684 */
    R[4] = lw_(R[16] + 14000);  /* 0x8009F688 */
    { R[31] = 0x8009F694u; R[5] = R[4] + 72; psx_next = 0x800A0224u; return; }  /* 0x8009F68C jal */
    R[5] = lw_(R[16] + 14000);  /* 0x8009F694 */
    R[4] = R[5] + 144;  /* 0x8009F69C */
    { R[31] = 0x8009F6A8u; R[5] = R[5] + 216; psx_next = 0x800A0224u; return; }  /* 0x8009F6A0 jal */
    R[5] = lw_(R[16] + 14000);  /* 0x8009F6A8 */
    R[4] = R[5] + 288;  /* 0x8009F6B0 */
    { R[31] = 0x8009F6BCu; R[5] = R[5] + 360; psx_next = 0x800A0224u; return; }  /* 0x8009F6B4 jal */
    R[5] = lw_(R[16] + 14000);  /* 0x8009F6BC */
    R[17] = R[0] + R[0];  /* 0x8009F6C0 */
    R[4] = R[5] + 432;  /* 0x8009F6C4 */
    { R[31] = 0x8009F6D0u; R[5] = R[5] + 504; psx_next = 0x800A0224u; return; }  /* 0x8009F6C8 jal */
    R[7] = R[0] + 1;  /* 0x8009F6D0 */
    R[3] = R[29] + 16;  /* 0x8009F6D4 */
    R[6] = R[7] + R[0];  /* 0x8009F6D8 */
    R[5] = R[17] + R[0];  /* 0x8009F6DC */
    R[4] = R[17] + R[0];  /* 0x8009F6E0 */
L_8009F6E4:;
    R[2] = lw_(R[16] + 14000);  /* 0x8009F6E4 */
    R[2] = R[2] + R[4];  /* 0x8009F6EC */
    R[2] = lb_(R[2] + 71);  /* 0x8009F6F0 */
    { uint32_t _c = (R[2] != R[7]); if (_c) { goto L_8009F708; } }  /* 0x8009F6F8 */
    { sb_(R[3], R[5]); goto L_8009F70C; }  /* 0x8009F700 j */
L_8009F708:;
    sb_(R[3], R[6]);  /* 0x8009F708 */
L_8009F70C:;
    R[3] = R[3] + 1;  /* 0x8009F70C */
    R[6] = R[6] + 2;  /* 0x8009F710 */
    R[5] = R[5] + 2;  /* 0x8009F714 */
    R[17] = R[17] + 1;  /* 0x8009F718 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F71C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[4] + 144; if (_c) { psx_bb(); goto L_8009F6E4; } }  /* 0x8009F720 */
    R[17] = R[0] + R[0];  /* 0x8009F728 */
    R[18] = 0x800Bu << 16;  /* 0x8009F72C */
    R[16] = R[29] + 16;  /* 0x8009F730 */
L_8009F734:;
    R[16] = R[16] + R[17];  /* 0x8009F734 */
    R[3] = lb_(R[16]);  /* 0x8009F738 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F73C */
    R[2] = R[3] << 3;  /* 0x8009F740 */
    R[2] = R[2] + R[3];  /* 0x8009F744 */
    R[2] = R[2] << 3;  /* 0x8009F748 */
    R[2] = R[5] + R[2];  /* 0x8009F74C */
    R[3] = lw_(R[2] + 48);  /* 0x8009F750 */
    sw_(R[2] + 4, R[3]);  /* 0x8009F758 */
    R[2] = lb_(R[16]);  /* 0x8009F75C */
    R[4] = R[2] << 3;  /* 0x8009F764 */
    R[4] = R[4] + R[2];  /* 0x8009F768 */
    R[4] = R[4] << 3;  /* 0x8009F76C */
    { R[31] = 0x8009F778u; R[4] = R[5] + R[4]; psx_next = 0x8009F984u; return; }  /* 0x8009F770 jal */
    R[2] = lb_(R[16]);  /* 0x8009F778 */
    R[4] = R[2] << 3;  /* 0x8009F780 */
    R[4] = R[4] + R[2];  /* 0x8009F784 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F788 */
    R[4] = R[4] << 3;  /* 0x8009F78C */
    { R[31] = 0x8009F798u; R[4] = R[2] + R[4]; psx_next = 0x8009FA48u; return; }  /* 0x8009F790 jal */
    R[3] = lb_(R[16]);  /* 0x8009F798 */
    R[17] = R[17] + 1;  /* 0x8009F79C */
    R[2] = R[3] << 3;  /* 0x8009F7A0 */
    R[2] = R[2] + R[3];  /* 0x8009F7A4 */
    R[3] = lw_(R[18] + 14000);  /* 0x8009F7A8 */
    R[2] = R[2] << 3;  /* 0x8009F7AC */
    R[3] = R[3] + R[2];  /* 0x8009F7B0 */
    R[2] = R[0] + 1;  /* 0x8009F7B4 */
    sb_(R[3] + 70, R[2]);  /* 0x8009F7B8 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F7BC */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[29] + 16; if (_c) { psx_bb(); goto L_8009F734; } }  /* 0x8009F7C0 */
    R[16] = 0x800Bu << 16;  /* 0x8009F7C8 */
    R[2] = lb_(R[29] + 16);  /* 0x8009F7CC */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F7D0 */
    R[4] = R[2] << 3;  /* 0x8009F7D4 */
    R[4] = R[4] + R[2];  /* 0x8009F7D8 */
    R[4] = R[4] << 3;  /* 0x8009F7DC */
    R[2] = lb_(R[29] + 17);  /* 0x8009F7E0 */
    R[4] = R[3] + R[4];  /* 0x8009F7E4 */
    R[5] = R[2] << 3;  /* 0x8009F7E8 */
    R[5] = R[5] + R[2];  /* 0x8009F7EC */
    R[5] = R[5] << 3;  /* 0x8009F7F0 */
    { R[31] = 0x8009F7FCu; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F7F4 jal */
    R[17] = R[0] + R[0];  /* 0x8009F7FC */
    R[2] = lb_(R[29] + 18);  /* 0x8009F800 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F804 */
    R[4] = R[2] << 3;  /* 0x8009F808 */
    R[4] = R[4] + R[2];  /* 0x8009F80C */
    R[4] = R[4] << 3;  /* 0x8009F810 */
    R[2] = lb_(R[29] + 19);  /* 0x8009F814 */
    R[4] = R[3] + R[4];  /* 0x8009F818 */
    R[5] = R[2] << 3;  /* 0x8009F81C */
    R[5] = R[5] + R[2];  /* 0x8009F820 */
    R[5] = R[5] << 3;  /* 0x8009F824 */
    { R[31] = 0x8009F830u; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F828 jal */
    R[4] = R[0] + 2;  /* 0x8009F830 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F834 */
L_8009F838:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F83C */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F850; } }  /* 0x8009F844 */
    sb_(R[29] + 16, R[17]);  /* 0x8009F84C */
L_8009F850:;
    R[17] = R[17] + 1;  /* 0x8009F850 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F854 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F838; } }  /* 0x8009F858 */
    R[17] = R[0] + 4;  /* 0x8009F860 */
    R[2] = 0x800Bu << 16;  /* 0x8009F864 */
    R[2] = lw_(R[2] + 14000);  /* 0x8009F868 */
    R[4] = R[0] + 2;  /* 0x8009F86C */
    R[3] = R[2] + 288;  /* 0x8009F870 */
L_8009F874:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F874 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F888; } }  /* 0x8009F87C */
    sb_(R[29] + 17, R[17]);  /* 0x8009F884 */
L_8009F888:;
    R[17] = R[17] + 1;  /* 0x8009F888 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F88C */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F874; } }  /* 0x8009F890 */
    R[17] = R[0] + R[0];  /* 0x8009F898 */
    R[18] = 0x800Bu << 16;  /* 0x8009F89C */
    R[16] = R[29] + 16;  /* 0x8009F8A0 */
    R[16] = R[16] + R[17];  /* 0x8009F8A4 */
    R[3] = lb_(R[16]);  /* 0x8009F8A8 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F8AC */
    R[2] = R[3] << 3;  /* 0x8009F8B0 */
    R[2] = R[2] + R[3];  /* 0x8009F8B4 */
    R[2] = R[2] << 3;  /* 0x8009F8B8 */
    psx_next = 0x8009F8BCu; return;  /* fallthrough */
}

void ev_8009F628(void) {
    R[2] = lw_(R[18] + 14000);  /* 0x8009F628 */
    R[2] = R[2] + R[16];  /* 0x8009F630 */
    sb_(R[2] + 71, R[0]);  /* 0x8009F634 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F638 */
    R[2] = R[2] + R[16];  /* 0x8009F640 */
    sb_(R[2] + 70, R[0]);  /* 0x8009F644 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F648 */
    R[2] = R[2] + R[16];  /* 0x8009F650 */
    sb_(R[2] + 58, R[0]);  /* 0x8009F654 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F658 */
    R[2] = R[2] + R[16];  /* 0x8009F660 */
    sb_(R[2] + 59, R[0]);  /* 0x8009F664 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F668 */
    R[17] = R[17] + 1;  /* 0x8009F66C */
    R[2] = R[2] + R[16];  /* 0x8009F670 */
    sb_(R[2] + 60, R[0]);  /* 0x8009F674 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F678 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 72; if (_c) { psx_next = 0x8009F610u; return; } }  /* 0x8009F67C b extern */
    R[16] = 0x800Bu << 16;  /* 0x8009F684 */
    R[4] = lw_(R[16] + 14000);  /* 0x8009F688 */
    { R[31] = 0x8009F694u; R[5] = R[4] + 72; psx_next = 0x800A0224u; return; }  /* 0x8009F68C jal */
    R[5] = lw_(R[16] + 14000);  /* 0x8009F694 */
    R[4] = R[5] + 144;  /* 0x8009F69C */
    { R[31] = 0x8009F6A8u; R[5] = R[5] + 216; psx_next = 0x800A0224u; return; }  /* 0x8009F6A0 jal */
    R[5] = lw_(R[16] + 14000);  /* 0x8009F6A8 */
    R[4] = R[5] + 288;  /* 0x8009F6B0 */
    { R[31] = 0x8009F6BCu; R[5] = R[5] + 360; psx_next = 0x800A0224u; return; }  /* 0x8009F6B4 jal */
    R[5] = lw_(R[16] + 14000);  /* 0x8009F6BC */
    R[17] = R[0] + R[0];  /* 0x8009F6C0 */
    R[4] = R[5] + 432;  /* 0x8009F6C4 */
    { R[31] = 0x8009F6D0u; R[5] = R[5] + 504; psx_next = 0x800A0224u; return; }  /* 0x8009F6C8 jal */
    R[7] = R[0] + 1;  /* 0x8009F6D0 */
    R[3] = R[29] + 16;  /* 0x8009F6D4 */
    R[6] = R[7] + R[0];  /* 0x8009F6D8 */
    R[5] = R[17] + R[0];  /* 0x8009F6DC */
    R[4] = R[17] + R[0];  /* 0x8009F6E0 */
L_8009F6E4:;
    R[2] = lw_(R[16] + 14000);  /* 0x8009F6E4 */
    R[2] = R[2] + R[4];  /* 0x8009F6EC */
    R[2] = lb_(R[2] + 71);  /* 0x8009F6F0 */
    { uint32_t _c = (R[2] != R[7]); if (_c) { goto L_8009F708; } }  /* 0x8009F6F8 */
    { sb_(R[3], R[5]); goto L_8009F70C; }  /* 0x8009F700 j */
L_8009F708:;
    sb_(R[3], R[6]);  /* 0x8009F708 */
L_8009F70C:;
    R[3] = R[3] + 1;  /* 0x8009F70C */
    R[6] = R[6] + 2;  /* 0x8009F710 */
    R[5] = R[5] + 2;  /* 0x8009F714 */
    R[17] = R[17] + 1;  /* 0x8009F718 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F71C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[4] + 144; if (_c) { psx_bb(); goto L_8009F6E4; } }  /* 0x8009F720 */
    R[17] = R[0] + R[0];  /* 0x8009F728 */
    R[18] = 0x800Bu << 16;  /* 0x8009F72C */
    R[16] = R[29] + 16;  /* 0x8009F730 */
L_8009F734:;
    R[16] = R[16] + R[17];  /* 0x8009F734 */
    R[3] = lb_(R[16]);  /* 0x8009F738 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F73C */
    R[2] = R[3] << 3;  /* 0x8009F740 */
    R[2] = R[2] + R[3];  /* 0x8009F744 */
    R[2] = R[2] << 3;  /* 0x8009F748 */
    R[2] = R[5] + R[2];  /* 0x8009F74C */
    R[3] = lw_(R[2] + 48);  /* 0x8009F750 */
    sw_(R[2] + 4, R[3]);  /* 0x8009F758 */
    R[2] = lb_(R[16]);  /* 0x8009F75C */
    R[4] = R[2] << 3;  /* 0x8009F764 */
    R[4] = R[4] + R[2];  /* 0x8009F768 */
    R[4] = R[4] << 3;  /* 0x8009F76C */
    { R[31] = 0x8009F778u; R[4] = R[5] + R[4]; psx_next = 0x8009F984u; return; }  /* 0x8009F770 jal */
    R[2] = lb_(R[16]);  /* 0x8009F778 */
    R[4] = R[2] << 3;  /* 0x8009F780 */
    R[4] = R[4] + R[2];  /* 0x8009F784 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F788 */
    R[4] = R[4] << 3;  /* 0x8009F78C */
    { R[31] = 0x8009F798u; R[4] = R[2] + R[4]; psx_next = 0x8009FA48u; return; }  /* 0x8009F790 jal */
    R[3] = lb_(R[16]);  /* 0x8009F798 */
    R[17] = R[17] + 1;  /* 0x8009F79C */
    R[2] = R[3] << 3;  /* 0x8009F7A0 */
    R[2] = R[2] + R[3];  /* 0x8009F7A4 */
    R[3] = lw_(R[18] + 14000);  /* 0x8009F7A8 */
    R[2] = R[2] << 3;  /* 0x8009F7AC */
    R[3] = R[3] + R[2];  /* 0x8009F7B0 */
    R[2] = R[0] + 1;  /* 0x8009F7B4 */
    sb_(R[3] + 70, R[2]);  /* 0x8009F7B8 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F7BC */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[29] + 16; if (_c) { psx_bb(); goto L_8009F734; } }  /* 0x8009F7C0 */
    R[16] = 0x800Bu << 16;  /* 0x8009F7C8 */
    R[2] = lb_(R[29] + 16);  /* 0x8009F7CC */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F7D0 */
    R[4] = R[2] << 3;  /* 0x8009F7D4 */
    R[4] = R[4] + R[2];  /* 0x8009F7D8 */
    R[4] = R[4] << 3;  /* 0x8009F7DC */
    R[2] = lb_(R[29] + 17);  /* 0x8009F7E0 */
    R[4] = R[3] + R[4];  /* 0x8009F7E4 */
    R[5] = R[2] << 3;  /* 0x8009F7E8 */
    R[5] = R[5] + R[2];  /* 0x8009F7EC */
    R[5] = R[5] << 3;  /* 0x8009F7F0 */
    { R[31] = 0x8009F7FCu; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F7F4 jal */
    R[17] = R[0] + R[0];  /* 0x8009F7FC */
    R[2] = lb_(R[29] + 18);  /* 0x8009F800 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F804 */
    R[4] = R[2] << 3;  /* 0x8009F808 */
    R[4] = R[4] + R[2];  /* 0x8009F80C */
    R[4] = R[4] << 3;  /* 0x8009F810 */
    R[2] = lb_(R[29] + 19);  /* 0x8009F814 */
    R[4] = R[3] + R[4];  /* 0x8009F818 */
    R[5] = R[2] << 3;  /* 0x8009F81C */
    R[5] = R[5] + R[2];  /* 0x8009F820 */
    R[5] = R[5] << 3;  /* 0x8009F824 */
    { R[31] = 0x8009F830u; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F828 jal */
    R[4] = R[0] + 2;  /* 0x8009F830 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F834 */
L_8009F838:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F83C */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F850; } }  /* 0x8009F844 */
    sb_(R[29] + 16, R[17]);  /* 0x8009F84C */
L_8009F850:;
    R[17] = R[17] + 1;  /* 0x8009F850 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F854 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F838; } }  /* 0x8009F858 */
    R[17] = R[0] + 4;  /* 0x8009F860 */
    R[2] = 0x800Bu << 16;  /* 0x8009F864 */
    R[2] = lw_(R[2] + 14000);  /* 0x8009F868 */
    R[4] = R[0] + 2;  /* 0x8009F86C */
    R[3] = R[2] + 288;  /* 0x8009F870 */
L_8009F874:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F874 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F888; } }  /* 0x8009F87C */
    sb_(R[29] + 17, R[17]);  /* 0x8009F884 */
L_8009F888:;
    R[17] = R[17] + 1;  /* 0x8009F888 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F88C */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F874; } }  /* 0x8009F890 */
    R[17] = R[0] + R[0];  /* 0x8009F898 */
    R[18] = 0x800Bu << 16;  /* 0x8009F89C */
    R[16] = R[29] + 16;  /* 0x8009F8A0 */
    R[16] = R[16] + R[17];  /* 0x8009F8A4 */
    R[3] = lb_(R[16]);  /* 0x8009F8A8 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F8AC */
    R[2] = R[3] << 3;  /* 0x8009F8B0 */
    R[2] = R[2] + R[3];  /* 0x8009F8B4 */
    R[2] = R[2] << 3;  /* 0x8009F8B8 */
    psx_next = 0x8009F8BCu; return;  /* fallthrough */
}

void ev_8009F694(void) {
    R[5] = lw_(R[16] + 14000);  /* 0x8009F694 */
    R[4] = R[5] + 144;  /* 0x8009F69C */
    { R[31] = 0x8009F6A8u; R[5] = R[5] + 216; psx_next = 0x800A0224u; return; }  /* 0x8009F6A0 jal */
    R[5] = lw_(R[16] + 14000);  /* 0x8009F6A8 */
    R[4] = R[5] + 288;  /* 0x8009F6B0 */
    { R[31] = 0x8009F6BCu; R[5] = R[5] + 360; psx_next = 0x800A0224u; return; }  /* 0x8009F6B4 jal */
    R[5] = lw_(R[16] + 14000);  /* 0x8009F6BC */
    R[17] = R[0] + R[0];  /* 0x8009F6C0 */
    R[4] = R[5] + 432;  /* 0x8009F6C4 */
    { R[31] = 0x8009F6D0u; R[5] = R[5] + 504; psx_next = 0x800A0224u; return; }  /* 0x8009F6C8 jal */
    R[7] = R[0] + 1;  /* 0x8009F6D0 */
    R[3] = R[29] + 16;  /* 0x8009F6D4 */
    R[6] = R[7] + R[0];  /* 0x8009F6D8 */
    R[5] = R[17] + R[0];  /* 0x8009F6DC */
    R[4] = R[17] + R[0];  /* 0x8009F6E0 */
L_8009F6E4:;
    R[2] = lw_(R[16] + 14000);  /* 0x8009F6E4 */
    R[2] = R[2] + R[4];  /* 0x8009F6EC */
    R[2] = lb_(R[2] + 71);  /* 0x8009F6F0 */
    { uint32_t _c = (R[2] != R[7]); if (_c) { goto L_8009F708; } }  /* 0x8009F6F8 */
    { sb_(R[3], R[5]); goto L_8009F70C; }  /* 0x8009F700 j */
L_8009F708:;
    sb_(R[3], R[6]);  /* 0x8009F708 */
L_8009F70C:;
    R[3] = R[3] + 1;  /* 0x8009F70C */
    R[6] = R[6] + 2;  /* 0x8009F710 */
    R[5] = R[5] + 2;  /* 0x8009F714 */
    R[17] = R[17] + 1;  /* 0x8009F718 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F71C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[4] + 144; if (_c) { psx_bb(); goto L_8009F6E4; } }  /* 0x8009F720 */
    R[17] = R[0] + R[0];  /* 0x8009F728 */
    R[18] = 0x800Bu << 16;  /* 0x8009F72C */
    R[16] = R[29] + 16;  /* 0x8009F730 */
L_8009F734:;
    R[16] = R[16] + R[17];  /* 0x8009F734 */
    R[3] = lb_(R[16]);  /* 0x8009F738 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F73C */
    R[2] = R[3] << 3;  /* 0x8009F740 */
    R[2] = R[2] + R[3];  /* 0x8009F744 */
    R[2] = R[2] << 3;  /* 0x8009F748 */
    R[2] = R[5] + R[2];  /* 0x8009F74C */
    R[3] = lw_(R[2] + 48);  /* 0x8009F750 */
    sw_(R[2] + 4, R[3]);  /* 0x8009F758 */
    R[2] = lb_(R[16]);  /* 0x8009F75C */
    R[4] = R[2] << 3;  /* 0x8009F764 */
    R[4] = R[4] + R[2];  /* 0x8009F768 */
    R[4] = R[4] << 3;  /* 0x8009F76C */
    { R[31] = 0x8009F778u; R[4] = R[5] + R[4]; psx_next = 0x8009F984u; return; }  /* 0x8009F770 jal */
    R[2] = lb_(R[16]);  /* 0x8009F778 */
    R[4] = R[2] << 3;  /* 0x8009F780 */
    R[4] = R[4] + R[2];  /* 0x8009F784 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F788 */
    R[4] = R[4] << 3;  /* 0x8009F78C */
    { R[31] = 0x8009F798u; R[4] = R[2] + R[4]; psx_next = 0x8009FA48u; return; }  /* 0x8009F790 jal */
    R[3] = lb_(R[16]);  /* 0x8009F798 */
    R[17] = R[17] + 1;  /* 0x8009F79C */
    R[2] = R[3] << 3;  /* 0x8009F7A0 */
    R[2] = R[2] + R[3];  /* 0x8009F7A4 */
    R[3] = lw_(R[18] + 14000);  /* 0x8009F7A8 */
    R[2] = R[2] << 3;  /* 0x8009F7AC */
    R[3] = R[3] + R[2];  /* 0x8009F7B0 */
    R[2] = R[0] + 1;  /* 0x8009F7B4 */
    sb_(R[3] + 70, R[2]);  /* 0x8009F7B8 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F7BC */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[29] + 16; if (_c) { psx_bb(); goto L_8009F734; } }  /* 0x8009F7C0 */
    R[16] = 0x800Bu << 16;  /* 0x8009F7C8 */
    R[2] = lb_(R[29] + 16);  /* 0x8009F7CC */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F7D0 */
    R[4] = R[2] << 3;  /* 0x8009F7D4 */
    R[4] = R[4] + R[2];  /* 0x8009F7D8 */
    R[4] = R[4] << 3;  /* 0x8009F7DC */
    R[2] = lb_(R[29] + 17);  /* 0x8009F7E0 */
    R[4] = R[3] + R[4];  /* 0x8009F7E4 */
    R[5] = R[2] << 3;  /* 0x8009F7E8 */
    R[5] = R[5] + R[2];  /* 0x8009F7EC */
    R[5] = R[5] << 3;  /* 0x8009F7F0 */
    { R[31] = 0x8009F7FCu; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F7F4 jal */
    R[17] = R[0] + R[0];  /* 0x8009F7FC */
    R[2] = lb_(R[29] + 18);  /* 0x8009F800 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F804 */
    R[4] = R[2] << 3;  /* 0x8009F808 */
    R[4] = R[4] + R[2];  /* 0x8009F80C */
    R[4] = R[4] << 3;  /* 0x8009F810 */
    R[2] = lb_(R[29] + 19);  /* 0x8009F814 */
    R[4] = R[3] + R[4];  /* 0x8009F818 */
    R[5] = R[2] << 3;  /* 0x8009F81C */
    R[5] = R[5] + R[2];  /* 0x8009F820 */
    R[5] = R[5] << 3;  /* 0x8009F824 */
    { R[31] = 0x8009F830u; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F828 jal */
    R[4] = R[0] + 2;  /* 0x8009F830 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F834 */
L_8009F838:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F83C */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F850; } }  /* 0x8009F844 */
    sb_(R[29] + 16, R[17]);  /* 0x8009F84C */
L_8009F850:;
    R[17] = R[17] + 1;  /* 0x8009F850 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F854 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F838; } }  /* 0x8009F858 */
    R[17] = R[0] + 4;  /* 0x8009F860 */
    R[2] = 0x800Bu << 16;  /* 0x8009F864 */
    R[2] = lw_(R[2] + 14000);  /* 0x8009F868 */
    R[4] = R[0] + 2;  /* 0x8009F86C */
    R[3] = R[2] + 288;  /* 0x8009F870 */
L_8009F874:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F874 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F888; } }  /* 0x8009F87C */
    sb_(R[29] + 17, R[17]);  /* 0x8009F884 */
L_8009F888:;
    R[17] = R[17] + 1;  /* 0x8009F888 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F88C */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F874; } }  /* 0x8009F890 */
    R[17] = R[0] + R[0];  /* 0x8009F898 */
    R[18] = 0x800Bu << 16;  /* 0x8009F89C */
    R[16] = R[29] + 16;  /* 0x8009F8A0 */
    R[16] = R[16] + R[17];  /* 0x8009F8A4 */
    R[3] = lb_(R[16]);  /* 0x8009F8A8 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F8AC */
    R[2] = R[3] << 3;  /* 0x8009F8B0 */
    R[2] = R[2] + R[3];  /* 0x8009F8B4 */
    R[2] = R[2] << 3;  /* 0x8009F8B8 */
    psx_next = 0x8009F8BCu; return;  /* fallthrough */
}

void ev_8009F6A8(void) {
    R[5] = lw_(R[16] + 14000);  /* 0x8009F6A8 */
    R[4] = R[5] + 288;  /* 0x8009F6B0 */
    { R[31] = 0x8009F6BCu; R[5] = R[5] + 360; psx_next = 0x800A0224u; return; }  /* 0x8009F6B4 jal */
    R[5] = lw_(R[16] + 14000);  /* 0x8009F6BC */
    R[17] = R[0] + R[0];  /* 0x8009F6C0 */
    R[4] = R[5] + 432;  /* 0x8009F6C4 */
    { R[31] = 0x8009F6D0u; R[5] = R[5] + 504; psx_next = 0x800A0224u; return; }  /* 0x8009F6C8 jal */
    R[7] = R[0] + 1;  /* 0x8009F6D0 */
    R[3] = R[29] + 16;  /* 0x8009F6D4 */
    R[6] = R[7] + R[0];  /* 0x8009F6D8 */
    R[5] = R[17] + R[0];  /* 0x8009F6DC */
    R[4] = R[17] + R[0];  /* 0x8009F6E0 */
L_8009F6E4:;
    R[2] = lw_(R[16] + 14000);  /* 0x8009F6E4 */
    R[2] = R[2] + R[4];  /* 0x8009F6EC */
    R[2] = lb_(R[2] + 71);  /* 0x8009F6F0 */
    { uint32_t _c = (R[2] != R[7]); if (_c) { goto L_8009F708; } }  /* 0x8009F6F8 */
    { sb_(R[3], R[5]); goto L_8009F70C; }  /* 0x8009F700 j */
L_8009F708:;
    sb_(R[3], R[6]);  /* 0x8009F708 */
L_8009F70C:;
    R[3] = R[3] + 1;  /* 0x8009F70C */
    R[6] = R[6] + 2;  /* 0x8009F710 */
    R[5] = R[5] + 2;  /* 0x8009F714 */
    R[17] = R[17] + 1;  /* 0x8009F718 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F71C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[4] + 144; if (_c) { psx_bb(); goto L_8009F6E4; } }  /* 0x8009F720 */
    R[17] = R[0] + R[0];  /* 0x8009F728 */
    R[18] = 0x800Bu << 16;  /* 0x8009F72C */
    R[16] = R[29] + 16;  /* 0x8009F730 */
L_8009F734:;
    R[16] = R[16] + R[17];  /* 0x8009F734 */
    R[3] = lb_(R[16]);  /* 0x8009F738 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F73C */
    R[2] = R[3] << 3;  /* 0x8009F740 */
    R[2] = R[2] + R[3];  /* 0x8009F744 */
    R[2] = R[2] << 3;  /* 0x8009F748 */
    R[2] = R[5] + R[2];  /* 0x8009F74C */
    R[3] = lw_(R[2] + 48);  /* 0x8009F750 */
    sw_(R[2] + 4, R[3]);  /* 0x8009F758 */
    R[2] = lb_(R[16]);  /* 0x8009F75C */
    R[4] = R[2] << 3;  /* 0x8009F764 */
    R[4] = R[4] + R[2];  /* 0x8009F768 */
    R[4] = R[4] << 3;  /* 0x8009F76C */
    { R[31] = 0x8009F778u; R[4] = R[5] + R[4]; psx_next = 0x8009F984u; return; }  /* 0x8009F770 jal */
    R[2] = lb_(R[16]);  /* 0x8009F778 */
    R[4] = R[2] << 3;  /* 0x8009F780 */
    R[4] = R[4] + R[2];  /* 0x8009F784 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F788 */
    R[4] = R[4] << 3;  /* 0x8009F78C */
    { R[31] = 0x8009F798u; R[4] = R[2] + R[4]; psx_next = 0x8009FA48u; return; }  /* 0x8009F790 jal */
    R[3] = lb_(R[16]);  /* 0x8009F798 */
    R[17] = R[17] + 1;  /* 0x8009F79C */
    R[2] = R[3] << 3;  /* 0x8009F7A0 */
    R[2] = R[2] + R[3];  /* 0x8009F7A4 */
    R[3] = lw_(R[18] + 14000);  /* 0x8009F7A8 */
    R[2] = R[2] << 3;  /* 0x8009F7AC */
    R[3] = R[3] + R[2];  /* 0x8009F7B0 */
    R[2] = R[0] + 1;  /* 0x8009F7B4 */
    sb_(R[3] + 70, R[2]);  /* 0x8009F7B8 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F7BC */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[29] + 16; if (_c) { psx_bb(); goto L_8009F734; } }  /* 0x8009F7C0 */
    R[16] = 0x800Bu << 16;  /* 0x8009F7C8 */
    R[2] = lb_(R[29] + 16);  /* 0x8009F7CC */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F7D0 */
    R[4] = R[2] << 3;  /* 0x8009F7D4 */
    R[4] = R[4] + R[2];  /* 0x8009F7D8 */
    R[4] = R[4] << 3;  /* 0x8009F7DC */
    R[2] = lb_(R[29] + 17);  /* 0x8009F7E0 */
    R[4] = R[3] + R[4];  /* 0x8009F7E4 */
    R[5] = R[2] << 3;  /* 0x8009F7E8 */
    R[5] = R[5] + R[2];  /* 0x8009F7EC */
    R[5] = R[5] << 3;  /* 0x8009F7F0 */
    { R[31] = 0x8009F7FCu; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F7F4 jal */
    R[17] = R[0] + R[0];  /* 0x8009F7FC */
    R[2] = lb_(R[29] + 18);  /* 0x8009F800 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F804 */
    R[4] = R[2] << 3;  /* 0x8009F808 */
    R[4] = R[4] + R[2];  /* 0x8009F80C */
    R[4] = R[4] << 3;  /* 0x8009F810 */
    R[2] = lb_(R[29] + 19);  /* 0x8009F814 */
    R[4] = R[3] + R[4];  /* 0x8009F818 */
    R[5] = R[2] << 3;  /* 0x8009F81C */
    R[5] = R[5] + R[2];  /* 0x8009F820 */
    R[5] = R[5] << 3;  /* 0x8009F824 */
    { R[31] = 0x8009F830u; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F828 jal */
    R[4] = R[0] + 2;  /* 0x8009F830 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F834 */
L_8009F838:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F83C */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F850; } }  /* 0x8009F844 */
    sb_(R[29] + 16, R[17]);  /* 0x8009F84C */
L_8009F850:;
    R[17] = R[17] + 1;  /* 0x8009F850 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F854 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F838; } }  /* 0x8009F858 */
    R[17] = R[0] + 4;  /* 0x8009F860 */
    R[2] = 0x800Bu << 16;  /* 0x8009F864 */
    R[2] = lw_(R[2] + 14000);  /* 0x8009F868 */
    R[4] = R[0] + 2;  /* 0x8009F86C */
    R[3] = R[2] + 288;  /* 0x8009F870 */
L_8009F874:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F874 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F888; } }  /* 0x8009F87C */
    sb_(R[29] + 17, R[17]);  /* 0x8009F884 */
L_8009F888:;
    R[17] = R[17] + 1;  /* 0x8009F888 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F88C */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F874; } }  /* 0x8009F890 */
    R[17] = R[0] + R[0];  /* 0x8009F898 */
    R[18] = 0x800Bu << 16;  /* 0x8009F89C */
    R[16] = R[29] + 16;  /* 0x8009F8A0 */
    R[16] = R[16] + R[17];  /* 0x8009F8A4 */
    R[3] = lb_(R[16]);  /* 0x8009F8A8 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F8AC */
    R[2] = R[3] << 3;  /* 0x8009F8B0 */
    R[2] = R[2] + R[3];  /* 0x8009F8B4 */
    R[2] = R[2] << 3;  /* 0x8009F8B8 */
    psx_next = 0x8009F8BCu; return;  /* fallthrough */
}

void ev_8009F6BC(void) {
    R[5] = lw_(R[16] + 14000);  /* 0x8009F6BC */
    R[17] = R[0] + R[0];  /* 0x8009F6C0 */
    R[4] = R[5] + 432;  /* 0x8009F6C4 */
    { R[31] = 0x8009F6D0u; R[5] = R[5] + 504; psx_next = 0x800A0224u; return; }  /* 0x8009F6C8 jal */
    R[7] = R[0] + 1;  /* 0x8009F6D0 */
    R[3] = R[29] + 16;  /* 0x8009F6D4 */
    R[6] = R[7] + R[0];  /* 0x8009F6D8 */
    R[5] = R[17] + R[0];  /* 0x8009F6DC */
    R[4] = R[17] + R[0];  /* 0x8009F6E0 */
L_8009F6E4:;
    R[2] = lw_(R[16] + 14000);  /* 0x8009F6E4 */
    R[2] = R[2] + R[4];  /* 0x8009F6EC */
    R[2] = lb_(R[2] + 71);  /* 0x8009F6F0 */
    { uint32_t _c = (R[2] != R[7]); if (_c) { goto L_8009F708; } }  /* 0x8009F6F8 */
    { sb_(R[3], R[5]); goto L_8009F70C; }  /* 0x8009F700 j */
L_8009F708:;
    sb_(R[3], R[6]);  /* 0x8009F708 */
L_8009F70C:;
    R[3] = R[3] + 1;  /* 0x8009F70C */
    R[6] = R[6] + 2;  /* 0x8009F710 */
    R[5] = R[5] + 2;  /* 0x8009F714 */
    R[17] = R[17] + 1;  /* 0x8009F718 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F71C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[4] + 144; if (_c) { psx_bb(); goto L_8009F6E4; } }  /* 0x8009F720 */
    R[17] = R[0] + R[0];  /* 0x8009F728 */
    R[18] = 0x800Bu << 16;  /* 0x8009F72C */
    R[16] = R[29] + 16;  /* 0x8009F730 */
L_8009F734:;
    R[16] = R[16] + R[17];  /* 0x8009F734 */
    R[3] = lb_(R[16]);  /* 0x8009F738 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F73C */
    R[2] = R[3] << 3;  /* 0x8009F740 */
    R[2] = R[2] + R[3];  /* 0x8009F744 */
    R[2] = R[2] << 3;  /* 0x8009F748 */
    R[2] = R[5] + R[2];  /* 0x8009F74C */
    R[3] = lw_(R[2] + 48);  /* 0x8009F750 */
    sw_(R[2] + 4, R[3]);  /* 0x8009F758 */
    R[2] = lb_(R[16]);  /* 0x8009F75C */
    R[4] = R[2] << 3;  /* 0x8009F764 */
    R[4] = R[4] + R[2];  /* 0x8009F768 */
    R[4] = R[4] << 3;  /* 0x8009F76C */
    { R[31] = 0x8009F778u; R[4] = R[5] + R[4]; psx_next = 0x8009F984u; return; }  /* 0x8009F770 jal */
    R[2] = lb_(R[16]);  /* 0x8009F778 */
    R[4] = R[2] << 3;  /* 0x8009F780 */
    R[4] = R[4] + R[2];  /* 0x8009F784 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F788 */
    R[4] = R[4] << 3;  /* 0x8009F78C */
    { R[31] = 0x8009F798u; R[4] = R[2] + R[4]; psx_next = 0x8009FA48u; return; }  /* 0x8009F790 jal */
    R[3] = lb_(R[16]);  /* 0x8009F798 */
    R[17] = R[17] + 1;  /* 0x8009F79C */
    R[2] = R[3] << 3;  /* 0x8009F7A0 */
    R[2] = R[2] + R[3];  /* 0x8009F7A4 */
    R[3] = lw_(R[18] + 14000);  /* 0x8009F7A8 */
    R[2] = R[2] << 3;  /* 0x8009F7AC */
    R[3] = R[3] + R[2];  /* 0x8009F7B0 */
    R[2] = R[0] + 1;  /* 0x8009F7B4 */
    sb_(R[3] + 70, R[2]);  /* 0x8009F7B8 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F7BC */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[29] + 16; if (_c) { psx_bb(); goto L_8009F734; } }  /* 0x8009F7C0 */
    R[16] = 0x800Bu << 16;  /* 0x8009F7C8 */
    R[2] = lb_(R[29] + 16);  /* 0x8009F7CC */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F7D0 */
    R[4] = R[2] << 3;  /* 0x8009F7D4 */
    R[4] = R[4] + R[2];  /* 0x8009F7D8 */
    R[4] = R[4] << 3;  /* 0x8009F7DC */
    R[2] = lb_(R[29] + 17);  /* 0x8009F7E0 */
    R[4] = R[3] + R[4];  /* 0x8009F7E4 */
    R[5] = R[2] << 3;  /* 0x8009F7E8 */
    R[5] = R[5] + R[2];  /* 0x8009F7EC */
    R[5] = R[5] << 3;  /* 0x8009F7F0 */
    { R[31] = 0x8009F7FCu; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F7F4 jal */
    R[17] = R[0] + R[0];  /* 0x8009F7FC */
    R[2] = lb_(R[29] + 18);  /* 0x8009F800 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F804 */
    R[4] = R[2] << 3;  /* 0x8009F808 */
    R[4] = R[4] + R[2];  /* 0x8009F80C */
    R[4] = R[4] << 3;  /* 0x8009F810 */
    R[2] = lb_(R[29] + 19);  /* 0x8009F814 */
    R[4] = R[3] + R[4];  /* 0x8009F818 */
    R[5] = R[2] << 3;  /* 0x8009F81C */
    R[5] = R[5] + R[2];  /* 0x8009F820 */
    R[5] = R[5] << 3;  /* 0x8009F824 */
    { R[31] = 0x8009F830u; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F828 jal */
    R[4] = R[0] + 2;  /* 0x8009F830 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F834 */
L_8009F838:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F83C */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F850; } }  /* 0x8009F844 */
    sb_(R[29] + 16, R[17]);  /* 0x8009F84C */
L_8009F850:;
    R[17] = R[17] + 1;  /* 0x8009F850 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F854 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F838; } }  /* 0x8009F858 */
    R[17] = R[0] + 4;  /* 0x8009F860 */
    R[2] = 0x800Bu << 16;  /* 0x8009F864 */
    R[2] = lw_(R[2] + 14000);  /* 0x8009F868 */
    R[4] = R[0] + 2;  /* 0x8009F86C */
    R[3] = R[2] + 288;  /* 0x8009F870 */
L_8009F874:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F874 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F888; } }  /* 0x8009F87C */
    sb_(R[29] + 17, R[17]);  /* 0x8009F884 */
L_8009F888:;
    R[17] = R[17] + 1;  /* 0x8009F888 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F88C */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F874; } }  /* 0x8009F890 */
    R[17] = R[0] + R[0];  /* 0x8009F898 */
    R[18] = 0x800Bu << 16;  /* 0x8009F89C */
    R[16] = R[29] + 16;  /* 0x8009F8A0 */
    R[16] = R[16] + R[17];  /* 0x8009F8A4 */
    R[3] = lb_(R[16]);  /* 0x8009F8A8 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F8AC */
    R[2] = R[3] << 3;  /* 0x8009F8B0 */
    R[2] = R[2] + R[3];  /* 0x8009F8B4 */
    R[2] = R[2] << 3;  /* 0x8009F8B8 */
    psx_next = 0x8009F8BCu; return;  /* fallthrough */
}

void ev_8009F6D0(void) {
    R[7] = R[0] + 1;  /* 0x8009F6D0 */
    R[3] = R[29] + 16;  /* 0x8009F6D4 */
    R[6] = R[7] + R[0];  /* 0x8009F6D8 */
    R[5] = R[17] + R[0];  /* 0x8009F6DC */
    R[4] = R[17] + R[0];  /* 0x8009F6E0 */
L_8009F6E4:;
    R[2] = lw_(R[16] + 14000);  /* 0x8009F6E4 */
    R[2] = R[2] + R[4];  /* 0x8009F6EC */
    R[2] = lb_(R[2] + 71);  /* 0x8009F6F0 */
    { uint32_t _c = (R[2] != R[7]); if (_c) { goto L_8009F708; } }  /* 0x8009F6F8 */
    { sb_(R[3], R[5]); goto L_8009F70C; }  /* 0x8009F700 j */
L_8009F708:;
    sb_(R[3], R[6]);  /* 0x8009F708 */
L_8009F70C:;
    R[3] = R[3] + 1;  /* 0x8009F70C */
    R[6] = R[6] + 2;  /* 0x8009F710 */
    R[5] = R[5] + 2;  /* 0x8009F714 */
    R[17] = R[17] + 1;  /* 0x8009F718 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F71C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[4] + 144; if (_c) { psx_bb(); goto L_8009F6E4; } }  /* 0x8009F720 */
    R[17] = R[0] + R[0];  /* 0x8009F728 */
    R[18] = 0x800Bu << 16;  /* 0x8009F72C */
    R[16] = R[29] + 16;  /* 0x8009F730 */
L_8009F734:;
    R[16] = R[16] + R[17];  /* 0x8009F734 */
    R[3] = lb_(R[16]);  /* 0x8009F738 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F73C */
    R[2] = R[3] << 3;  /* 0x8009F740 */
    R[2] = R[2] + R[3];  /* 0x8009F744 */
    R[2] = R[2] << 3;  /* 0x8009F748 */
    R[2] = R[5] + R[2];  /* 0x8009F74C */
    R[3] = lw_(R[2] + 48);  /* 0x8009F750 */
    sw_(R[2] + 4, R[3]);  /* 0x8009F758 */
    R[2] = lb_(R[16]);  /* 0x8009F75C */
    R[4] = R[2] << 3;  /* 0x8009F764 */
    R[4] = R[4] + R[2];  /* 0x8009F768 */
    R[4] = R[4] << 3;  /* 0x8009F76C */
    { R[31] = 0x8009F778u; R[4] = R[5] + R[4]; psx_next = 0x8009F984u; return; }  /* 0x8009F770 jal */
    R[2] = lb_(R[16]);  /* 0x8009F778 */
    R[4] = R[2] << 3;  /* 0x8009F780 */
    R[4] = R[4] + R[2];  /* 0x8009F784 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F788 */
    R[4] = R[4] << 3;  /* 0x8009F78C */
    { R[31] = 0x8009F798u; R[4] = R[2] + R[4]; psx_next = 0x8009FA48u; return; }  /* 0x8009F790 jal */
    R[3] = lb_(R[16]);  /* 0x8009F798 */
    R[17] = R[17] + 1;  /* 0x8009F79C */
    R[2] = R[3] << 3;  /* 0x8009F7A0 */
    R[2] = R[2] + R[3];  /* 0x8009F7A4 */
    R[3] = lw_(R[18] + 14000);  /* 0x8009F7A8 */
    R[2] = R[2] << 3;  /* 0x8009F7AC */
    R[3] = R[3] + R[2];  /* 0x8009F7B0 */
    R[2] = R[0] + 1;  /* 0x8009F7B4 */
    sb_(R[3] + 70, R[2]);  /* 0x8009F7B8 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F7BC */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[29] + 16; if (_c) { psx_bb(); goto L_8009F734; } }  /* 0x8009F7C0 */
    R[16] = 0x800Bu << 16;  /* 0x8009F7C8 */
    R[2] = lb_(R[29] + 16);  /* 0x8009F7CC */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F7D0 */
    R[4] = R[2] << 3;  /* 0x8009F7D4 */
    R[4] = R[4] + R[2];  /* 0x8009F7D8 */
    R[4] = R[4] << 3;  /* 0x8009F7DC */
    R[2] = lb_(R[29] + 17);  /* 0x8009F7E0 */
    R[4] = R[3] + R[4];  /* 0x8009F7E4 */
    R[5] = R[2] << 3;  /* 0x8009F7E8 */
    R[5] = R[5] + R[2];  /* 0x8009F7EC */
    R[5] = R[5] << 3;  /* 0x8009F7F0 */
    { R[31] = 0x8009F7FCu; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F7F4 jal */
    R[17] = R[0] + R[0];  /* 0x8009F7FC */
    R[2] = lb_(R[29] + 18);  /* 0x8009F800 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F804 */
    R[4] = R[2] << 3;  /* 0x8009F808 */
    R[4] = R[4] + R[2];  /* 0x8009F80C */
    R[4] = R[4] << 3;  /* 0x8009F810 */
    R[2] = lb_(R[29] + 19);  /* 0x8009F814 */
    R[4] = R[3] + R[4];  /* 0x8009F818 */
    R[5] = R[2] << 3;  /* 0x8009F81C */
    R[5] = R[5] + R[2];  /* 0x8009F820 */
    R[5] = R[5] << 3;  /* 0x8009F824 */
    { R[31] = 0x8009F830u; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F828 jal */
    R[4] = R[0] + 2;  /* 0x8009F830 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F834 */
L_8009F838:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F83C */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F850; } }  /* 0x8009F844 */
    sb_(R[29] + 16, R[17]);  /* 0x8009F84C */
L_8009F850:;
    R[17] = R[17] + 1;  /* 0x8009F850 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F854 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F838; } }  /* 0x8009F858 */
    R[17] = R[0] + 4;  /* 0x8009F860 */
    R[2] = 0x800Bu << 16;  /* 0x8009F864 */
    R[2] = lw_(R[2] + 14000);  /* 0x8009F868 */
    R[4] = R[0] + 2;  /* 0x8009F86C */
    R[3] = R[2] + 288;  /* 0x8009F870 */
L_8009F874:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F874 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F888; } }  /* 0x8009F87C */
    sb_(R[29] + 17, R[17]);  /* 0x8009F884 */
L_8009F888:;
    R[17] = R[17] + 1;  /* 0x8009F888 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F88C */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F874; } }  /* 0x8009F890 */
    R[17] = R[0] + R[0];  /* 0x8009F898 */
    R[18] = 0x800Bu << 16;  /* 0x8009F89C */
    R[16] = R[29] + 16;  /* 0x8009F8A0 */
    R[16] = R[16] + R[17];  /* 0x8009F8A4 */
    R[3] = lb_(R[16]);  /* 0x8009F8A8 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F8AC */
    R[2] = R[3] << 3;  /* 0x8009F8B0 */
    R[2] = R[2] + R[3];  /* 0x8009F8B4 */
    R[2] = R[2] << 3;  /* 0x8009F8B8 */
    psx_next = 0x8009F8BCu; return;  /* fallthrough */
}

void ev_8009F734(void) {
L_8009F734:;
    R[16] = R[16] + R[17];  /* 0x8009F734 */
    R[3] = lb_(R[16]);  /* 0x8009F738 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F73C */
    R[2] = R[3] << 3;  /* 0x8009F740 */
    R[2] = R[2] + R[3];  /* 0x8009F744 */
    R[2] = R[2] << 3;  /* 0x8009F748 */
    R[2] = R[5] + R[2];  /* 0x8009F74C */
    R[3] = lw_(R[2] + 48);  /* 0x8009F750 */
    sw_(R[2] + 4, R[3]);  /* 0x8009F758 */
    R[2] = lb_(R[16]);  /* 0x8009F75C */
    R[4] = R[2] << 3;  /* 0x8009F764 */
    R[4] = R[4] + R[2];  /* 0x8009F768 */
    R[4] = R[4] << 3;  /* 0x8009F76C */
    { R[31] = 0x8009F778u; R[4] = R[5] + R[4]; psx_next = 0x8009F984u; return; }  /* 0x8009F770 jal */
    R[2] = lb_(R[16]);  /* 0x8009F778 */
    R[4] = R[2] << 3;  /* 0x8009F780 */
    R[4] = R[4] + R[2];  /* 0x8009F784 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F788 */
    R[4] = R[4] << 3;  /* 0x8009F78C */
    { R[31] = 0x8009F798u; R[4] = R[2] + R[4]; psx_next = 0x8009FA48u; return; }  /* 0x8009F790 jal */
    R[3] = lb_(R[16]);  /* 0x8009F798 */
    R[17] = R[17] + 1;  /* 0x8009F79C */
    R[2] = R[3] << 3;  /* 0x8009F7A0 */
    R[2] = R[2] + R[3];  /* 0x8009F7A4 */
    R[3] = lw_(R[18] + 14000);  /* 0x8009F7A8 */
    R[2] = R[2] << 3;  /* 0x8009F7AC */
    R[3] = R[3] + R[2];  /* 0x8009F7B0 */
    R[2] = R[0] + 1;  /* 0x8009F7B4 */
    sb_(R[3] + 70, R[2]);  /* 0x8009F7B8 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F7BC */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[29] + 16; if (_c) { psx_bb(); goto L_8009F734; } }  /* 0x8009F7C0 */
    R[16] = 0x800Bu << 16;  /* 0x8009F7C8 */
    R[2] = lb_(R[29] + 16);  /* 0x8009F7CC */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F7D0 */
    R[4] = R[2] << 3;  /* 0x8009F7D4 */
    R[4] = R[4] + R[2];  /* 0x8009F7D8 */
    R[4] = R[4] << 3;  /* 0x8009F7DC */
    R[2] = lb_(R[29] + 17);  /* 0x8009F7E0 */
    R[4] = R[3] + R[4];  /* 0x8009F7E4 */
    R[5] = R[2] << 3;  /* 0x8009F7E8 */
    R[5] = R[5] + R[2];  /* 0x8009F7EC */
    R[5] = R[5] << 3;  /* 0x8009F7F0 */
    { R[31] = 0x8009F7FCu; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F7F4 jal */
    R[17] = R[0] + R[0];  /* 0x8009F7FC */
    R[2] = lb_(R[29] + 18);  /* 0x8009F800 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F804 */
    R[4] = R[2] << 3;  /* 0x8009F808 */
    R[4] = R[4] + R[2];  /* 0x8009F80C */
    R[4] = R[4] << 3;  /* 0x8009F810 */
    R[2] = lb_(R[29] + 19);  /* 0x8009F814 */
    R[4] = R[3] + R[4];  /* 0x8009F818 */
    R[5] = R[2] << 3;  /* 0x8009F81C */
    R[5] = R[5] + R[2];  /* 0x8009F820 */
    R[5] = R[5] << 3;  /* 0x8009F824 */
    { R[31] = 0x8009F830u; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F828 jal */
    R[4] = R[0] + 2;  /* 0x8009F830 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F834 */
L_8009F838:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F83C */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F850; } }  /* 0x8009F844 */
    sb_(R[29] + 16, R[17]);  /* 0x8009F84C */
L_8009F850:;
    R[17] = R[17] + 1;  /* 0x8009F850 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F854 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F838; } }  /* 0x8009F858 */
    R[17] = R[0] + 4;  /* 0x8009F860 */
    R[2] = 0x800Bu << 16;  /* 0x8009F864 */
    R[2] = lw_(R[2] + 14000);  /* 0x8009F868 */
    R[4] = R[0] + 2;  /* 0x8009F86C */
    R[3] = R[2] + 288;  /* 0x8009F870 */
L_8009F874:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F874 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F888; } }  /* 0x8009F87C */
    sb_(R[29] + 17, R[17]);  /* 0x8009F884 */
L_8009F888:;
    R[17] = R[17] + 1;  /* 0x8009F888 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F88C */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F874; } }  /* 0x8009F890 */
    R[17] = R[0] + R[0];  /* 0x8009F898 */
    R[18] = 0x800Bu << 16;  /* 0x8009F89C */
    R[16] = R[29] + 16;  /* 0x8009F8A0 */
    R[16] = R[16] + R[17];  /* 0x8009F8A4 */
    R[3] = lb_(R[16]);  /* 0x8009F8A8 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F8AC */
    R[2] = R[3] << 3;  /* 0x8009F8B0 */
    R[2] = R[2] + R[3];  /* 0x8009F8B4 */
    R[2] = R[2] << 3;  /* 0x8009F8B8 */
    psx_next = 0x8009F8BCu; return;  /* fallthrough */
}

void ev_8009F778(void) {
    R[2] = lb_(R[16]);  /* 0x8009F778 */
    R[4] = R[2] << 3;  /* 0x8009F780 */
    R[4] = R[4] + R[2];  /* 0x8009F784 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F788 */
    R[4] = R[4] << 3;  /* 0x8009F78C */
    { R[31] = 0x8009F798u; R[4] = R[2] + R[4]; psx_next = 0x8009FA48u; return; }  /* 0x8009F790 jal */
    R[3] = lb_(R[16]);  /* 0x8009F798 */
    R[17] = R[17] + 1;  /* 0x8009F79C */
    R[2] = R[3] << 3;  /* 0x8009F7A0 */
    R[2] = R[2] + R[3];  /* 0x8009F7A4 */
    R[3] = lw_(R[18] + 14000);  /* 0x8009F7A8 */
    R[2] = R[2] << 3;  /* 0x8009F7AC */
    R[3] = R[3] + R[2];  /* 0x8009F7B0 */
    R[2] = R[0] + 1;  /* 0x8009F7B4 */
    sb_(R[3] + 70, R[2]);  /* 0x8009F7B8 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F7BC */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[29] + 16; if (_c) { psx_next = 0x8009F734u; return; } }  /* 0x8009F7C0 b extern */
    R[16] = 0x800Bu << 16;  /* 0x8009F7C8 */
    R[2] = lb_(R[29] + 16);  /* 0x8009F7CC */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F7D0 */
    R[4] = R[2] << 3;  /* 0x8009F7D4 */
    R[4] = R[4] + R[2];  /* 0x8009F7D8 */
    R[4] = R[4] << 3;  /* 0x8009F7DC */
    R[2] = lb_(R[29] + 17);  /* 0x8009F7E0 */
    R[4] = R[3] + R[4];  /* 0x8009F7E4 */
    R[5] = R[2] << 3;  /* 0x8009F7E8 */
    R[5] = R[5] + R[2];  /* 0x8009F7EC */
    R[5] = R[5] << 3;  /* 0x8009F7F0 */
    { R[31] = 0x8009F7FCu; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F7F4 jal */
    R[17] = R[0] + R[0];  /* 0x8009F7FC */
    R[2] = lb_(R[29] + 18);  /* 0x8009F800 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F804 */
    R[4] = R[2] << 3;  /* 0x8009F808 */
    R[4] = R[4] + R[2];  /* 0x8009F80C */
    R[4] = R[4] << 3;  /* 0x8009F810 */
    R[2] = lb_(R[29] + 19);  /* 0x8009F814 */
    R[4] = R[3] + R[4];  /* 0x8009F818 */
    R[5] = R[2] << 3;  /* 0x8009F81C */
    R[5] = R[5] + R[2];  /* 0x8009F820 */
    R[5] = R[5] << 3;  /* 0x8009F824 */
    { R[31] = 0x8009F830u; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F828 jal */
    R[4] = R[0] + 2;  /* 0x8009F830 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F834 */
L_8009F838:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F83C */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F850; } }  /* 0x8009F844 */
    sb_(R[29] + 16, R[17]);  /* 0x8009F84C */
L_8009F850:;
    R[17] = R[17] + 1;  /* 0x8009F850 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F854 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F838; } }  /* 0x8009F858 */
    R[17] = R[0] + 4;  /* 0x8009F860 */
    R[2] = 0x800Bu << 16;  /* 0x8009F864 */
    R[2] = lw_(R[2] + 14000);  /* 0x8009F868 */
    R[4] = R[0] + 2;  /* 0x8009F86C */
    R[3] = R[2] + 288;  /* 0x8009F870 */
L_8009F874:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F874 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F888; } }  /* 0x8009F87C */
    sb_(R[29] + 17, R[17]);  /* 0x8009F884 */
L_8009F888:;
    R[17] = R[17] + 1;  /* 0x8009F888 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F88C */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F874; } }  /* 0x8009F890 */
    R[17] = R[0] + R[0];  /* 0x8009F898 */
    R[18] = 0x800Bu << 16;  /* 0x8009F89C */
    R[16] = R[29] + 16;  /* 0x8009F8A0 */
    R[16] = R[16] + R[17];  /* 0x8009F8A4 */
    R[3] = lb_(R[16]);  /* 0x8009F8A8 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F8AC */
    R[2] = R[3] << 3;  /* 0x8009F8B0 */
    R[2] = R[2] + R[3];  /* 0x8009F8B4 */
    R[2] = R[2] << 3;  /* 0x8009F8B8 */
    psx_next = 0x8009F8BCu; return;  /* fallthrough */
}

void ev_8009F798(void) {
    R[3] = lb_(R[16]);  /* 0x8009F798 */
    R[17] = R[17] + 1;  /* 0x8009F79C */
    R[2] = R[3] << 3;  /* 0x8009F7A0 */
    R[2] = R[2] + R[3];  /* 0x8009F7A4 */
    R[3] = lw_(R[18] + 14000);  /* 0x8009F7A8 */
    R[2] = R[2] << 3;  /* 0x8009F7AC */
    R[3] = R[3] + R[2];  /* 0x8009F7B0 */
    R[2] = R[0] + 1;  /* 0x8009F7B4 */
    sb_(R[3] + 70, R[2]);  /* 0x8009F7B8 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F7BC */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[29] + 16; if (_c) { psx_next = 0x8009F734u; return; } }  /* 0x8009F7C0 b extern */
    R[16] = 0x800Bu << 16;  /* 0x8009F7C8 */
    R[2] = lb_(R[29] + 16);  /* 0x8009F7CC */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F7D0 */
    R[4] = R[2] << 3;  /* 0x8009F7D4 */
    R[4] = R[4] + R[2];  /* 0x8009F7D8 */
    R[4] = R[4] << 3;  /* 0x8009F7DC */
    R[2] = lb_(R[29] + 17);  /* 0x8009F7E0 */
    R[4] = R[3] + R[4];  /* 0x8009F7E4 */
    R[5] = R[2] << 3;  /* 0x8009F7E8 */
    R[5] = R[5] + R[2];  /* 0x8009F7EC */
    R[5] = R[5] << 3;  /* 0x8009F7F0 */
    { R[31] = 0x8009F7FCu; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F7F4 jal */
    R[17] = R[0] + R[0];  /* 0x8009F7FC */
    R[2] = lb_(R[29] + 18);  /* 0x8009F800 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F804 */
    R[4] = R[2] << 3;  /* 0x8009F808 */
    R[4] = R[4] + R[2];  /* 0x8009F80C */
    R[4] = R[4] << 3;  /* 0x8009F810 */
    R[2] = lb_(R[29] + 19);  /* 0x8009F814 */
    R[4] = R[3] + R[4];  /* 0x8009F818 */
    R[5] = R[2] << 3;  /* 0x8009F81C */
    R[5] = R[5] + R[2];  /* 0x8009F820 */
    R[5] = R[5] << 3;  /* 0x8009F824 */
    { R[31] = 0x8009F830u; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F828 jal */
    R[4] = R[0] + 2;  /* 0x8009F830 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F834 */
L_8009F838:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F83C */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F850; } }  /* 0x8009F844 */
    sb_(R[29] + 16, R[17]);  /* 0x8009F84C */
L_8009F850:;
    R[17] = R[17] + 1;  /* 0x8009F850 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F854 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F838; } }  /* 0x8009F858 */
    R[17] = R[0] + 4;  /* 0x8009F860 */
    R[2] = 0x800Bu << 16;  /* 0x8009F864 */
    R[2] = lw_(R[2] + 14000);  /* 0x8009F868 */
    R[4] = R[0] + 2;  /* 0x8009F86C */
    R[3] = R[2] + 288;  /* 0x8009F870 */
L_8009F874:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F874 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F888; } }  /* 0x8009F87C */
    sb_(R[29] + 17, R[17]);  /* 0x8009F884 */
L_8009F888:;
    R[17] = R[17] + 1;  /* 0x8009F888 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F88C */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F874; } }  /* 0x8009F890 */
    R[17] = R[0] + R[0];  /* 0x8009F898 */
    R[18] = 0x800Bu << 16;  /* 0x8009F89C */
    R[16] = R[29] + 16;  /* 0x8009F8A0 */
    R[16] = R[16] + R[17];  /* 0x8009F8A4 */
    R[3] = lb_(R[16]);  /* 0x8009F8A8 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F8AC */
    R[2] = R[3] << 3;  /* 0x8009F8B0 */
    R[2] = R[2] + R[3];  /* 0x8009F8B4 */
    R[2] = R[2] << 3;  /* 0x8009F8B8 */
    psx_next = 0x8009F8BCu; return;  /* fallthrough */
}

void ev_8009F7FC(void) {
    R[17] = R[0] + R[0];  /* 0x8009F7FC */
    R[2] = lb_(R[29] + 18);  /* 0x8009F800 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F804 */
    R[4] = R[2] << 3;  /* 0x8009F808 */
    R[4] = R[4] + R[2];  /* 0x8009F80C */
    R[4] = R[4] << 3;  /* 0x8009F810 */
    R[2] = lb_(R[29] + 19);  /* 0x8009F814 */
    R[4] = R[3] + R[4];  /* 0x8009F818 */
    R[5] = R[2] << 3;  /* 0x8009F81C */
    R[5] = R[5] + R[2];  /* 0x8009F820 */
    R[5] = R[5] << 3;  /* 0x8009F824 */
    { R[31] = 0x8009F830u; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F828 jal */
    R[4] = R[0] + 2;  /* 0x8009F830 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F834 */
L_8009F838:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F83C */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F850; } }  /* 0x8009F844 */
    sb_(R[29] + 16, R[17]);  /* 0x8009F84C */
L_8009F850:;
    R[17] = R[17] + 1;  /* 0x8009F850 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F854 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F838; } }  /* 0x8009F858 */
    R[17] = R[0] + 4;  /* 0x8009F860 */
    R[2] = 0x800Bu << 16;  /* 0x8009F864 */
    R[2] = lw_(R[2] + 14000);  /* 0x8009F868 */
    R[4] = R[0] + 2;  /* 0x8009F86C */
    R[3] = R[2] + 288;  /* 0x8009F870 */
L_8009F874:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F874 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F888; } }  /* 0x8009F87C */
    sb_(R[29] + 17, R[17]);  /* 0x8009F884 */
L_8009F888:;
    R[17] = R[17] + 1;  /* 0x8009F888 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F88C */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F874; } }  /* 0x8009F890 */
    R[17] = R[0] + R[0];  /* 0x8009F898 */
    R[18] = 0x800Bu << 16;  /* 0x8009F89C */
    R[16] = R[29] + 16;  /* 0x8009F8A0 */
    R[16] = R[16] + R[17];  /* 0x8009F8A4 */
    R[3] = lb_(R[16]);  /* 0x8009F8A8 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F8AC */
    R[2] = R[3] << 3;  /* 0x8009F8B0 */
    R[2] = R[2] + R[3];  /* 0x8009F8B4 */
    R[2] = R[2] << 3;  /* 0x8009F8B8 */
    psx_next = 0x8009F8BCu; return;  /* fallthrough */
}

void ev_8009F800(void) {
    R[2] = lb_(R[29] + 18);  /* 0x8009F800 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F804 */
    R[4] = R[2] << 3;  /* 0x8009F808 */
    R[4] = R[4] + R[2];  /* 0x8009F80C */
    R[4] = R[4] << 3;  /* 0x8009F810 */
    R[2] = lb_(R[29] + 19);  /* 0x8009F814 */
    R[4] = R[3] + R[4];  /* 0x8009F818 */
    R[5] = R[2] << 3;  /* 0x8009F81C */
    R[5] = R[5] + R[2];  /* 0x8009F820 */
    R[5] = R[5] << 3;  /* 0x8009F824 */
    { R[31] = 0x8009F830u; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F828 jal */
    R[4] = R[0] + 2;  /* 0x8009F830 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F834 */
L_8009F838:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F83C */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F850; } }  /* 0x8009F844 */
    sb_(R[29] + 16, R[17]);  /* 0x8009F84C */
L_8009F850:;
    R[17] = R[17] + 1;  /* 0x8009F850 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F854 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F838; } }  /* 0x8009F858 */
    R[17] = R[0] + 4;  /* 0x8009F860 */
    R[2] = 0x800Bu << 16;  /* 0x8009F864 */
    R[2] = lw_(R[2] + 14000);  /* 0x8009F868 */
    R[4] = R[0] + 2;  /* 0x8009F86C */
    R[3] = R[2] + 288;  /* 0x8009F870 */
L_8009F874:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F874 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F888; } }  /* 0x8009F87C */
    sb_(R[29] + 17, R[17]);  /* 0x8009F884 */
L_8009F888:;
    R[17] = R[17] + 1;  /* 0x8009F888 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F88C */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F874; } }  /* 0x8009F890 */
    R[17] = R[0] + R[0];  /* 0x8009F898 */
    R[18] = 0x800Bu << 16;  /* 0x8009F89C */
    R[16] = R[29] + 16;  /* 0x8009F8A0 */
    R[16] = R[16] + R[17];  /* 0x8009F8A4 */
    R[3] = lb_(R[16]);  /* 0x8009F8A8 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F8AC */
    R[2] = R[3] << 3;  /* 0x8009F8B0 */
    R[2] = R[2] + R[3];  /* 0x8009F8B4 */
    R[2] = R[2] << 3;  /* 0x8009F8B8 */
    psx_next = 0x8009F8BCu; return;  /* fallthrough */
}

void ev_8009F830(void) {
    R[4] = R[0] + 2;  /* 0x8009F830 */
    R[3] = lw_(R[16] + 14000);  /* 0x8009F834 */
L_8009F838:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F83C */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F850; } }  /* 0x8009F844 */
    sb_(R[29] + 16, R[17]);  /* 0x8009F84C */
L_8009F850:;
    R[17] = R[17] + 1;  /* 0x8009F850 */
    R[2] = ((int32_t)R[17] < 4);  /* 0x8009F854 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F838; } }  /* 0x8009F858 */
    R[17] = R[0] + 4;  /* 0x8009F860 */
    R[2] = 0x800Bu << 16;  /* 0x8009F864 */
    R[2] = lw_(R[2] + 14000);  /* 0x8009F868 */
    R[4] = R[0] + 2;  /* 0x8009F86C */
    R[3] = R[2] + 288;  /* 0x8009F870 */
L_8009F874:;
    R[2] = lb_(R[3] + 71);  /* 0x8009F874 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8009F888; } }  /* 0x8009F87C */
    sb_(R[29] + 17, R[17]);  /* 0x8009F884 */
L_8009F888:;
    R[17] = R[17] + 1;  /* 0x8009F888 */
    R[2] = ((int32_t)R[17] < 8);  /* 0x8009F88C */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 72; if (_c) { psx_bb(); goto L_8009F874; } }  /* 0x8009F890 */
    R[17] = R[0] + R[0];  /* 0x8009F898 */
    R[18] = 0x800Bu << 16;  /* 0x8009F89C */
    R[16] = R[29] + 16;  /* 0x8009F8A0 */
    R[16] = R[16] + R[17];  /* 0x8009F8A4 */
    R[3] = lb_(R[16]);  /* 0x8009F8A8 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F8AC */
    R[2] = R[3] << 3;  /* 0x8009F8B0 */
    R[2] = R[2] + R[3];  /* 0x8009F8B4 */
    R[2] = R[2] << 3;  /* 0x8009F8B8 */
    psx_next = 0x8009F8BCu; return;  /* fallthrough */
}

void ev_8009F8A4(void) {
    R[16] = R[16] + R[17];  /* 0x8009F8A4 */
    R[3] = lb_(R[16]);  /* 0x8009F8A8 */
    R[5] = lw_(R[18] + 14000);  /* 0x8009F8AC */
    R[2] = R[3] << 3;  /* 0x8009F8B0 */
    R[2] = R[2] + R[3];  /* 0x8009F8B4 */
    R[2] = R[2] << 3;  /* 0x8009F8B8 */
    psx_next = 0x8009F8BCu; return;  /* fallthrough */
}

void ev_8009F8BC(void) {
    R[2] = R[5] + R[2];  /* 0x8009F8BC */
    R[3] = lw_(R[2] + 48);  /* 0x8009F8C0 */
    sw_(R[2] + 4, R[3]);  /* 0x8009F8C8 */
    R[2] = lb_(R[16]);  /* 0x8009F8CC */
    R[4] = R[2] << 3;  /* 0x8009F8D4 */
    R[4] = R[4] + R[2];  /* 0x8009F8D8 */
    R[4] = R[4] << 3;  /* 0x8009F8DC */
    { R[31] = 0x8009F8E8u; R[4] = R[5] + R[4]; psx_next = 0x8009F984u; return; }  /* 0x8009F8E0 jal */
    R[2] = lb_(R[16]);  /* 0x8009F8E8 */
    R[4] = R[2] << 3;  /* 0x8009F8F0 */
    R[4] = R[4] + R[2];  /* 0x8009F8F4 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F8F8 */
    R[4] = R[4] << 3;  /* 0x8009F8FC */
    { R[31] = 0x8009F908u; R[4] = R[2] + R[4]; psx_next = 0x8009FA48u; return; }  /* 0x8009F900 jal */
    R[3] = lb_(R[16]);  /* 0x8009F908 */
    R[17] = R[17] + 1;  /* 0x8009F90C */
    R[2] = R[3] << 3;  /* 0x8009F910 */
    R[2] = R[2] + R[3];  /* 0x8009F914 */
    R[3] = lw_(R[18] + 14000);  /* 0x8009F918 */
    R[2] = R[2] << 3;  /* 0x8009F91C */
    R[3] = R[3] + R[2];  /* 0x8009F920 */
    R[2] = R[0] + 2;  /* 0x8009F924 */
    sb_(R[3] + 70, R[2]);  /* 0x8009F928 */
    R[2] = ((int32_t)R[17] < 2);  /* 0x8009F92C */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[29] + 16; if (_c) { psx_next = 0x8009F8A4u; return; } }  /* 0x8009F930 b extern */
    R[3] = 0x800Bu << 16;  /* 0x8009F938 */
    R[2] = lb_(R[29] + 16);  /* 0x8009F93C */
    psx_next = 0x8009F940u; return;  /* fallthrough */
}

void ev_8009F8E8(void) {
    R[2] = lb_(R[16]);  /* 0x8009F8E8 */
    R[4] = R[2] << 3;  /* 0x8009F8F0 */
    R[4] = R[4] + R[2];  /* 0x8009F8F4 */
    R[2] = lw_(R[18] + 14000);  /* 0x8009F8F8 */
    R[4] = R[4] << 3;  /* 0x8009F8FC */
    { R[31] = 0x8009F908u; R[4] = R[2] + R[4]; psx_next = 0x8009FA48u; return; }  /* 0x8009F900 jal */
    R[3] = lb_(R[16]);  /* 0x8009F908 */
    R[17] = R[17] + 1;  /* 0x8009F90C */
    R[2] = R[3] << 3;  /* 0x8009F910 */
    R[2] = R[2] + R[3];  /* 0x8009F914 */
    R[3] = lw_(R[18] + 14000);  /* 0x8009F918 */
    R[2] = R[2] << 3;  /* 0x8009F91C */
    R[3] = R[3] + R[2];  /* 0x8009F920 */
    R[2] = R[0] + 2;  /* 0x8009F924 */
    sb_(R[3] + 70, R[2]);  /* 0x8009F928 */
    R[2] = ((int32_t)R[17] < 2);  /* 0x8009F92C */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[29] + 16; if (_c) { psx_next = 0x8009F8A4u; return; } }  /* 0x8009F930 b extern */
    R[3] = 0x800Bu << 16;  /* 0x8009F938 */
    R[2] = lb_(R[29] + 16);  /* 0x8009F93C */
    psx_next = 0x8009F940u; return;  /* fallthrough */
}

void ev_8009F908(void) {
    R[3] = lb_(R[16]);  /* 0x8009F908 */
    R[17] = R[17] + 1;  /* 0x8009F90C */
    R[2] = R[3] << 3;  /* 0x8009F910 */
    R[2] = R[2] + R[3];  /* 0x8009F914 */
    R[3] = lw_(R[18] + 14000);  /* 0x8009F918 */
    R[2] = R[2] << 3;  /* 0x8009F91C */
    R[3] = R[3] + R[2];  /* 0x8009F920 */
    R[2] = R[0] + 2;  /* 0x8009F924 */
    sb_(R[3] + 70, R[2]);  /* 0x8009F928 */
    R[2] = ((int32_t)R[17] < 2);  /* 0x8009F92C */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[29] + 16; if (_c) { psx_next = 0x8009F8A4u; return; } }  /* 0x8009F930 b extern */
    R[3] = 0x800Bu << 16;  /* 0x8009F938 */
    R[2] = lb_(R[29] + 16);  /* 0x8009F93C */
    psx_next = 0x8009F940u; return;  /* fallthrough */
}

void ev_8009F940(void) {
    R[3] = lw_(R[3] + 14000);  /* 0x8009F940 */
    R[4] = R[2] << 3;  /* 0x8009F944 */
    R[4] = R[4] + R[2];  /* 0x8009F948 */
    R[4] = R[4] << 3;  /* 0x8009F94C */
    R[2] = lb_(R[29] + 17);  /* 0x8009F950 */
    R[4] = R[3] + R[4];  /* 0x8009F954 */
    R[5] = R[2] << 3;  /* 0x8009F958 */
    R[5] = R[5] + R[2];  /* 0x8009F95C */
    R[5] = R[5] << 3;  /* 0x8009F960 */
    { R[31] = 0x8009F96Cu; R[5] = R[3] + R[5]; psx_next = 0x800A0224u; return; }  /* 0x8009F964 jal */
    R[31] = lw_(R[29] + 36);  /* 0x8009F96C */
    R[18] = lw_(R[29] + 32);  /* 0x8009F970 */
    R[17] = lw_(R[29] + 28);  /* 0x8009F974 */
    R[16] = lw_(R[29] + 24);  /* 0x8009F978 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009F97C jr ra */
}

void ev_8009F96C(void) {
    R[31] = lw_(R[29] + 36);  /* 0x8009F96C */
    R[18] = lw_(R[29] + 32);  /* 0x8009F970 */
    R[17] = lw_(R[29] + 28);  /* 0x8009F974 */
    R[16] = lw_(R[29] + 24);  /* 0x8009F978 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009F97C jr ra */
}

void ev_8009F984(void) {
    R[6] = lb_(R[4]);  /* 0x8009F984 */
    R[7] = lb_(R[4] + 4);  /* 0x8009F988 */
    R[5] = lb_(R[4] + 8);  /* 0x8009F98C */
    R[3] = R[6] & 0xFF;  /* 0x8009F990 */
    R[2] = (R[7] < R[3]);  /* 0x8009F994 */
    { uint32_t _c = (R[2] == R[0]); R[2] = (R[5] < R[3]); if (_c) { goto L_8009F9A8; } }  /* 0x8009F998 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[0] + R[0]; if (_c) { goto L_8009FA40; } }  /* 0x8009F9A0 */
L_8009F9A8:;
    R[3] = R[7] & 0xFF;  /* 0x8009F9A8 */
    R[2] = (R[6] < R[3]);  /* 0x8009F9AC */
    { uint32_t _c = (R[2] == R[0]); R[2] = (R[5] < R[3]); if (_c) { goto L_8009F9C0; } }  /* 0x8009F9B0 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[0] + 1; if (_c) { goto L_8009FA40; } }  /* 0x8009F9B8 */
L_8009F9C0:;
    R[3] = R[5] & 0xFF;  /* 0x8009F9C0 */
    R[2] = (R[6] < R[3]);  /* 0x8009F9C4 */
    { uint32_t _c = (R[2] == R[0]); R[2] = (R[7] < R[3]); if (_c) { goto L_8009F9D8; } }  /* 0x8009F9C8 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[0] + 2; if (_c) { goto L_8009FA40; } }  /* 0x8009F9D0 */
L_8009F9D8:;
    R[2] = R[6] & 0xFF;  /* 0x8009F9D8 */
    { uint32_t _c = (R[2] != R[7]); R[3] = R[5] & 0xFF; if (_c) { goto L_8009F9F4; } }  /* 0x8009F9DC */
    { uint32_t _c = (R[2] != R[5]); R[2] = (R[3] < R[6]); if (_c) { goto L_8009F9F8; } }  /* 0x8009F9E4 */
    { R[3] = R[0] + 3; goto L_8009FA40; }  /* 0x8009F9EC j */
L_8009F9F4:;
    R[2] = (R[3] < R[6]);  /* 0x8009F9F4 */
L_8009F9F8:;
    { uint32_t _c = (R[2] == R[0]); R[2] = (R[3] < R[7]); if (_c) { goto L_8009FA08; } }  /* 0x8009F9F8 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[0] + 1; if (_c) { goto L_8009FA40; } }  /* 0x8009FA00 */
L_8009FA08:;
    R[3] = R[7] & 0xFF;  /* 0x8009FA08 */
    R[2] = (R[3] < R[6]);  /* 0x8009FA0C */
    { uint32_t _c = (R[2] == R[0]); R[2] = (R[3] < R[5]); if (_c) { goto L_8009FA20; } }  /* 0x8009FA10 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[0] + R[0]; if (_c) { goto L_8009FA40; } }  /* 0x8009FA18 */
L_8009FA20:;
    R[6] = R[6] & 0xFF;  /* 0x8009FA20 */
    R[2] = (R[6] < R[7]);  /* 0x8009FA24 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[0] + 4; if (_c) { goto L_8009FA40; } }  /* 0x8009FA28 */
    R[2] = (R[6] < R[5]);  /* 0x8009FA30 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009FA40; } }  /* 0x8009FA34 */
    R[3] = R[0] + 2;  /* 0x8009FA3C */
L_8009FA40:;
    { sb_(R[4] + 57, R[3]); psx_next = R[31]; return; }  /* 0x8009FA40 jr ra */
}

void ev_8009FA48(void) {
    R[29] = R[29] - 40;  /* 0x8009FA48 */
    sw_(R[29] + 16, R[16]);  /* 0x8009FA4C */
    R[16] = R[4] + R[0];  /* 0x8009FA50 */
    sw_(R[29] + 36, R[31]);  /* 0x8009FA54 */
    sw_(R[29] + 32, R[20]);  /* 0x8009FA58 */
    sw_(R[29] + 28, R[19]);  /* 0x8009FA5C */
    sw_(R[29] + 24, R[18]);  /* 0x8009FA60 */
    { R[31] = 0x8009FA6Cu; sw_(R[29] + 20, R[17]); psx_next = 0x800A0260u; return; }  /* 0x8009FA64 jal */
    { R[31] = 0x8009FA74u; R[18] = R[2] + R[0]; psx_next = 0x800A0260u; return; }  /* 0x8009FA6C jal */
    R[20] = 0x8001u << 16;  /* 0x8009FA74 */
    R[20] = R[20] | 0x28;  /* 0x8009FA78 */
    R[17] = R[0] + 4096;  /* 0x8009FA7C */
    R[4] = R[17] - R[18];  /* 0x8009FA80 */
    { uint32_t _t = R[20]; R[31] = 0x8009FA8Cu; R[5] = R[2] + R[0]; psx_next = _t; return; }  /* 0x8009FA84 jalr */
    R[19] = 0x6666u << 16;  /* 0x8009FA8C */
    R[4] = lw_(R[16] + 16);  /* 0x8009FA90 */
    R[19] = R[19] | 0x6667;  /* 0x8009FA94 */
    R[4] = R[4] << 1;  /* 0x8009FA98 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FA9C */
    R[5] = R[18] + R[0];  /* 0x8009FAA0 */
    R[18] = R[2] + R[0];  /* 0x8009FAA4 */
    R[17] = R[17] - R[18];  /* 0x8009FAA8 */
    R[17] = R[17] - R[5];  /* 0x8009FAAC */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FAB0 */
    R[3] = HI;  /* 0x8009FAB4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FAB8 */
    { uint32_t _t = R[20]; R[31] = 0x8009FAC4u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FABC jalr */
    R[4] = lw_(R[16] + 16);  /* 0x8009FAC4 */
    R[4] = R[4] << 1;  /* 0x8009FACC */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FAD0 */
    R[3] = HI;  /* 0x8009FAD4 */
    R[6] = lw_(R[16] + 16);  /* 0x8009FAD8 */
    { int64_t _p = (int64_t)(int32_t)R[6] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FAE0 */
    R[5] = R[18] + R[0];  /* 0x8009FAE4 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FAE8 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FAEC */
    R[4] = R[3] - R[4];  /* 0x8009FAF0 */
    R[6] = (uint32_t)((int32_t)R[6] >> 31);  /* 0x8009FAF4 */
    R[7] = HI;  /* 0x8009FAF8 */
    R[3] = (uint32_t)((int32_t)R[7] >> 1);  /* 0x8009FAFC */
    R[3] = R[3] - R[6];  /* 0x8009FB00 */
    R[3] = R[3] + R[2];  /* 0x8009FB04 */
    { uint32_t _t = R[20]; R[31] = 0x8009FB10u; sw_(R[16] + 20, R[3]); psx_next = _t; return; }  /* 0x8009FB08 jalr */
    R[4] = lw_(R[16] + 16);  /* 0x8009FB10 */
    R[4] = R[4] << 1;  /* 0x8009FB18 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB1C */
    R[3] = HI;  /* 0x8009FB20 */
    R[6] = lw_(R[16] + 16);  /* 0x8009FB24 */
    { int64_t _p = (int64_t)(int32_t)R[6] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB2C */
    R[5] = R[17] + R[0];  /* 0x8009FB30 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB34 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FB38 */
    R[4] = R[3] - R[4];  /* 0x8009FB3C */
    R[6] = (uint32_t)((int32_t)R[6] >> 31);  /* 0x8009FB40 */
    R[7] = HI;  /* 0x8009FB44 */
    R[3] = (uint32_t)((int32_t)R[7] >> 1);  /* 0x8009FB48 */
    R[3] = R[3] - R[6];  /* 0x8009FB4C */
    R[3] = R[3] + R[2];  /* 0x8009FB50 */
    { uint32_t _t = R[20]; R[31] = 0x8009FB5Cu; sw_(R[16] + 24, R[3]); psx_next = _t; return; }  /* 0x8009FB54 jalr */
    R[4] = lw_(R[16] + 16);  /* 0x8009FB5C */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB64 */
    R[17] = 0x5555u << 16;  /* 0x8009FB68 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB6C */
    R[3] = HI;  /* 0x8009FB70 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FB74 */
    R[3] = R[3] - R[4];  /* 0x8009FB78 */
    R[3] = R[3] + R[2];  /* 0x8009FB7C */
    { R[31] = 0x8009FB88u; sw_(R[16] + 28, R[3]); psx_next = 0x800A0260u; return; }  /* 0x8009FB80 jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FB88 */
    R[17] = R[17] | 0x5556;  /* 0x8009FB8C */
    R[4] = R[4] << 1;  /* 0x8009FB90 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB94 */
    R[5] = R[2] + R[0];  /* 0x8009FB98 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB9C */
    R[3] = HI;  /* 0x8009FBA0 */
    { uint32_t _t = R[20]; R[31] = 0x8009FBACu; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBA4 jalr */
    { R[31] = 0x8009FBB4u; sw_(R[16] + 32, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBAC jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBB4 */
    R[4] = R[4] << 1;  /* 0x8009FBBC */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBC0 */
    R[5] = R[2] + R[0];  /* 0x8009FBC4 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBC8 */
    R[3] = HI;  /* 0x8009FBCC */
    { uint32_t _t = R[20]; R[31] = 0x8009FBD8u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBD0 jalr */
    { R[31] = 0x8009FBE0u; sw_(R[16] + 36, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBD8 jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBE0 */
    R[4] = R[4] << 1;  /* 0x8009FBE8 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBEC */
    R[5] = R[2] + R[0];  /* 0x8009FBF0 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBF4 */
    R[3] = HI;  /* 0x8009FBF8 */
    { uint32_t _t = R[20]; R[31] = 0x8009FC04u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBFC jalr */
    sw_(R[16] + 40, R[2]);  /* 0x8009FC04 */
    R[2] = lw_(R[16]);  /* 0x8009FC08 */
    R[3] = lw_(R[16] + 32);  /* 0x8009FC0C */
    R[4] = lw_(R[16] + 20);  /* 0x8009FC10 */
    R[2] = R[2] + R[3];  /* 0x8009FC14 */
    R[2] = R[2] + R[4];  /* 0x8009FC18 */
    sw_(R[16] + 44, R[2]);  /* 0x8009FC1C */
    R[2] = lw_(R[16] + 4);  /* 0x8009FC20 */
    R[3] = lw_(R[16] + 36);  /* 0x8009FC24 */
    R[4] = lw_(R[16] + 24);  /* 0x8009FC28 */
    R[2] = R[2] + R[3];  /* 0x8009FC2C */
    R[2] = R[2] + R[4];  /* 0x8009FC30 */
    sw_(R[16] + 48, R[2]);  /* 0x8009FC34 */
    R[2] = lw_(R[16] + 8);  /* 0x8009FC38 */
    R[3] = lw_(R[16] + 40);  /* 0x8009FC3C */
    R[4] = lw_(R[16] + 28);  /* 0x8009FC40 */
    R[2] = R[2] + R[3];  /* 0x8009FC44 */
    R[2] = R[2] + R[4];  /* 0x8009FC48 */
    sw_(R[16] + 52, R[2]);  /* 0x8009FC4C */
    R[31] = lw_(R[29] + 36);  /* 0x8009FC50 */
    R[20] = lw_(R[29] + 32);  /* 0x8009FC54 */
    R[19] = lw_(R[29] + 28);  /* 0x8009FC58 */
    R[18] = lw_(R[29] + 24);  /* 0x8009FC5C */
    R[17] = lw_(R[29] + 20);  /* 0x8009FC60 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FC64 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009FC68 jr ra */
}

void ev_8009FA6C(void) {
    { R[31] = 0x8009FA74u; R[18] = R[2] + R[0]; psx_next = 0x800A0260u; return; }  /* 0x8009FA6C jal */
    R[20] = 0x8001u << 16;  /* 0x8009FA74 */
    R[20] = R[20] | 0x28;  /* 0x8009FA78 */
    R[17] = R[0] + 4096;  /* 0x8009FA7C */
    R[4] = R[17] - R[18];  /* 0x8009FA80 */
    { uint32_t _t = R[20]; R[31] = 0x8009FA8Cu; R[5] = R[2] + R[0]; psx_next = _t; return; }  /* 0x8009FA84 jalr */
    R[19] = 0x6666u << 16;  /* 0x8009FA8C */
    R[4] = lw_(R[16] + 16);  /* 0x8009FA90 */
    R[19] = R[19] | 0x6667;  /* 0x8009FA94 */
    R[4] = R[4] << 1;  /* 0x8009FA98 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FA9C */
    R[5] = R[18] + R[0];  /* 0x8009FAA0 */
    R[18] = R[2] + R[0];  /* 0x8009FAA4 */
    R[17] = R[17] - R[18];  /* 0x8009FAA8 */
    R[17] = R[17] - R[5];  /* 0x8009FAAC */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FAB0 */
    R[3] = HI;  /* 0x8009FAB4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FAB8 */
    { uint32_t _t = R[20]; R[31] = 0x8009FAC4u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FABC jalr */
    R[4] = lw_(R[16] + 16);  /* 0x8009FAC4 */
    R[4] = R[4] << 1;  /* 0x8009FACC */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FAD0 */
    R[3] = HI;  /* 0x8009FAD4 */
    R[6] = lw_(R[16] + 16);  /* 0x8009FAD8 */
    { int64_t _p = (int64_t)(int32_t)R[6] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FAE0 */
    R[5] = R[18] + R[0];  /* 0x8009FAE4 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FAE8 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FAEC */
    R[4] = R[3] - R[4];  /* 0x8009FAF0 */
    R[6] = (uint32_t)((int32_t)R[6] >> 31);  /* 0x8009FAF4 */
    R[7] = HI;  /* 0x8009FAF8 */
    R[3] = (uint32_t)((int32_t)R[7] >> 1);  /* 0x8009FAFC */
    R[3] = R[3] - R[6];  /* 0x8009FB00 */
    R[3] = R[3] + R[2];  /* 0x8009FB04 */
    { uint32_t _t = R[20]; R[31] = 0x8009FB10u; sw_(R[16] + 20, R[3]); psx_next = _t; return; }  /* 0x8009FB08 jalr */
    R[4] = lw_(R[16] + 16);  /* 0x8009FB10 */
    R[4] = R[4] << 1;  /* 0x8009FB18 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB1C */
    R[3] = HI;  /* 0x8009FB20 */
    R[6] = lw_(R[16] + 16);  /* 0x8009FB24 */
    { int64_t _p = (int64_t)(int32_t)R[6] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB2C */
    R[5] = R[17] + R[0];  /* 0x8009FB30 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB34 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FB38 */
    R[4] = R[3] - R[4];  /* 0x8009FB3C */
    R[6] = (uint32_t)((int32_t)R[6] >> 31);  /* 0x8009FB40 */
    R[7] = HI;  /* 0x8009FB44 */
    R[3] = (uint32_t)((int32_t)R[7] >> 1);  /* 0x8009FB48 */
    R[3] = R[3] - R[6];  /* 0x8009FB4C */
    R[3] = R[3] + R[2];  /* 0x8009FB50 */
    { uint32_t _t = R[20]; R[31] = 0x8009FB5Cu; sw_(R[16] + 24, R[3]); psx_next = _t; return; }  /* 0x8009FB54 jalr */
    R[4] = lw_(R[16] + 16);  /* 0x8009FB5C */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB64 */
    R[17] = 0x5555u << 16;  /* 0x8009FB68 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB6C */
    R[3] = HI;  /* 0x8009FB70 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FB74 */
    R[3] = R[3] - R[4];  /* 0x8009FB78 */
    R[3] = R[3] + R[2];  /* 0x8009FB7C */
    { R[31] = 0x8009FB88u; sw_(R[16] + 28, R[3]); psx_next = 0x800A0260u; return; }  /* 0x8009FB80 jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FB88 */
    R[17] = R[17] | 0x5556;  /* 0x8009FB8C */
    R[4] = R[4] << 1;  /* 0x8009FB90 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB94 */
    R[5] = R[2] + R[0];  /* 0x8009FB98 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB9C */
    R[3] = HI;  /* 0x8009FBA0 */
    { uint32_t _t = R[20]; R[31] = 0x8009FBACu; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBA4 jalr */
    { R[31] = 0x8009FBB4u; sw_(R[16] + 32, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBAC jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBB4 */
    R[4] = R[4] << 1;  /* 0x8009FBBC */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBC0 */
    R[5] = R[2] + R[0];  /* 0x8009FBC4 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBC8 */
    R[3] = HI;  /* 0x8009FBCC */
    { uint32_t _t = R[20]; R[31] = 0x8009FBD8u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBD0 jalr */
    { R[31] = 0x8009FBE0u; sw_(R[16] + 36, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBD8 jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBE0 */
    R[4] = R[4] << 1;  /* 0x8009FBE8 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBEC */
    R[5] = R[2] + R[0];  /* 0x8009FBF0 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBF4 */
    R[3] = HI;  /* 0x8009FBF8 */
    { uint32_t _t = R[20]; R[31] = 0x8009FC04u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBFC jalr */
    sw_(R[16] + 40, R[2]);  /* 0x8009FC04 */
    R[2] = lw_(R[16]);  /* 0x8009FC08 */
    R[3] = lw_(R[16] + 32);  /* 0x8009FC0C */
    R[4] = lw_(R[16] + 20);  /* 0x8009FC10 */
    R[2] = R[2] + R[3];  /* 0x8009FC14 */
    R[2] = R[2] + R[4];  /* 0x8009FC18 */
    sw_(R[16] + 44, R[2]);  /* 0x8009FC1C */
    R[2] = lw_(R[16] + 4);  /* 0x8009FC20 */
    R[3] = lw_(R[16] + 36);  /* 0x8009FC24 */
    R[4] = lw_(R[16] + 24);  /* 0x8009FC28 */
    R[2] = R[2] + R[3];  /* 0x8009FC2C */
    R[2] = R[2] + R[4];  /* 0x8009FC30 */
    sw_(R[16] + 48, R[2]);  /* 0x8009FC34 */
    R[2] = lw_(R[16] + 8);  /* 0x8009FC38 */
    R[3] = lw_(R[16] + 40);  /* 0x8009FC3C */
    R[4] = lw_(R[16] + 28);  /* 0x8009FC40 */
    R[2] = R[2] + R[3];  /* 0x8009FC44 */
    R[2] = R[2] + R[4];  /* 0x8009FC48 */
    sw_(R[16] + 52, R[2]);  /* 0x8009FC4C */
    R[31] = lw_(R[29] + 36);  /* 0x8009FC50 */
    R[20] = lw_(R[29] + 32);  /* 0x8009FC54 */
    R[19] = lw_(R[29] + 28);  /* 0x8009FC58 */
    R[18] = lw_(R[29] + 24);  /* 0x8009FC5C */
    R[17] = lw_(R[29] + 20);  /* 0x8009FC60 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FC64 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009FC68 jr ra */
}

void ev_8009FA74(void) {
    R[20] = 0x8001u << 16;  /* 0x8009FA74 */
    R[20] = R[20] | 0x28;  /* 0x8009FA78 */
    R[17] = R[0] + 4096;  /* 0x8009FA7C */
    R[4] = R[17] - R[18];  /* 0x8009FA80 */
    { uint32_t _t = R[20]; R[31] = 0x8009FA8Cu; R[5] = R[2] + R[0]; psx_next = _t; return; }  /* 0x8009FA84 jalr */
    R[19] = 0x6666u << 16;  /* 0x8009FA8C */
    R[4] = lw_(R[16] + 16);  /* 0x8009FA90 */
    R[19] = R[19] | 0x6667;  /* 0x8009FA94 */
    R[4] = R[4] << 1;  /* 0x8009FA98 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FA9C */
    R[5] = R[18] + R[0];  /* 0x8009FAA0 */
    R[18] = R[2] + R[0];  /* 0x8009FAA4 */
    R[17] = R[17] - R[18];  /* 0x8009FAA8 */
    R[17] = R[17] - R[5];  /* 0x8009FAAC */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FAB0 */
    R[3] = HI;  /* 0x8009FAB4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FAB8 */
    { uint32_t _t = R[20]; R[31] = 0x8009FAC4u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FABC jalr */
    R[4] = lw_(R[16] + 16);  /* 0x8009FAC4 */
    R[4] = R[4] << 1;  /* 0x8009FACC */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FAD0 */
    R[3] = HI;  /* 0x8009FAD4 */
    R[6] = lw_(R[16] + 16);  /* 0x8009FAD8 */
    { int64_t _p = (int64_t)(int32_t)R[6] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FAE0 */
    R[5] = R[18] + R[0];  /* 0x8009FAE4 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FAE8 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FAEC */
    R[4] = R[3] - R[4];  /* 0x8009FAF0 */
    R[6] = (uint32_t)((int32_t)R[6] >> 31);  /* 0x8009FAF4 */
    R[7] = HI;  /* 0x8009FAF8 */
    R[3] = (uint32_t)((int32_t)R[7] >> 1);  /* 0x8009FAFC */
    R[3] = R[3] - R[6];  /* 0x8009FB00 */
    R[3] = R[3] + R[2];  /* 0x8009FB04 */
    { uint32_t _t = R[20]; R[31] = 0x8009FB10u; sw_(R[16] + 20, R[3]); psx_next = _t; return; }  /* 0x8009FB08 jalr */
    R[4] = lw_(R[16] + 16);  /* 0x8009FB10 */
    R[4] = R[4] << 1;  /* 0x8009FB18 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB1C */
    R[3] = HI;  /* 0x8009FB20 */
    R[6] = lw_(R[16] + 16);  /* 0x8009FB24 */
    { int64_t _p = (int64_t)(int32_t)R[6] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB2C */
    R[5] = R[17] + R[0];  /* 0x8009FB30 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB34 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FB38 */
    R[4] = R[3] - R[4];  /* 0x8009FB3C */
    R[6] = (uint32_t)((int32_t)R[6] >> 31);  /* 0x8009FB40 */
    R[7] = HI;  /* 0x8009FB44 */
    R[3] = (uint32_t)((int32_t)R[7] >> 1);  /* 0x8009FB48 */
    R[3] = R[3] - R[6];  /* 0x8009FB4C */
    R[3] = R[3] + R[2];  /* 0x8009FB50 */
    { uint32_t _t = R[20]; R[31] = 0x8009FB5Cu; sw_(R[16] + 24, R[3]); psx_next = _t; return; }  /* 0x8009FB54 jalr */
    R[4] = lw_(R[16] + 16);  /* 0x8009FB5C */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB64 */
    R[17] = 0x5555u << 16;  /* 0x8009FB68 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB6C */
    R[3] = HI;  /* 0x8009FB70 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FB74 */
    R[3] = R[3] - R[4];  /* 0x8009FB78 */
    R[3] = R[3] + R[2];  /* 0x8009FB7C */
    { R[31] = 0x8009FB88u; sw_(R[16] + 28, R[3]); psx_next = 0x800A0260u; return; }  /* 0x8009FB80 jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FB88 */
    R[17] = R[17] | 0x5556;  /* 0x8009FB8C */
    R[4] = R[4] << 1;  /* 0x8009FB90 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB94 */
    R[5] = R[2] + R[0];  /* 0x8009FB98 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB9C */
    R[3] = HI;  /* 0x8009FBA0 */
    { uint32_t _t = R[20]; R[31] = 0x8009FBACu; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBA4 jalr */
    { R[31] = 0x8009FBB4u; sw_(R[16] + 32, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBAC jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBB4 */
    R[4] = R[4] << 1;  /* 0x8009FBBC */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBC0 */
    R[5] = R[2] + R[0];  /* 0x8009FBC4 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBC8 */
    R[3] = HI;  /* 0x8009FBCC */
    { uint32_t _t = R[20]; R[31] = 0x8009FBD8u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBD0 jalr */
    { R[31] = 0x8009FBE0u; sw_(R[16] + 36, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBD8 jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBE0 */
    R[4] = R[4] << 1;  /* 0x8009FBE8 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBEC */
    R[5] = R[2] + R[0];  /* 0x8009FBF0 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBF4 */
    R[3] = HI;  /* 0x8009FBF8 */
    { uint32_t _t = R[20]; R[31] = 0x8009FC04u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBFC jalr */
    sw_(R[16] + 40, R[2]);  /* 0x8009FC04 */
    R[2] = lw_(R[16]);  /* 0x8009FC08 */
    R[3] = lw_(R[16] + 32);  /* 0x8009FC0C */
    R[4] = lw_(R[16] + 20);  /* 0x8009FC10 */
    R[2] = R[2] + R[3];  /* 0x8009FC14 */
    R[2] = R[2] + R[4];  /* 0x8009FC18 */
    sw_(R[16] + 44, R[2]);  /* 0x8009FC1C */
    R[2] = lw_(R[16] + 4);  /* 0x8009FC20 */
    R[3] = lw_(R[16] + 36);  /* 0x8009FC24 */
    R[4] = lw_(R[16] + 24);  /* 0x8009FC28 */
    R[2] = R[2] + R[3];  /* 0x8009FC2C */
    R[2] = R[2] + R[4];  /* 0x8009FC30 */
    sw_(R[16] + 48, R[2]);  /* 0x8009FC34 */
    R[2] = lw_(R[16] + 8);  /* 0x8009FC38 */
    R[3] = lw_(R[16] + 40);  /* 0x8009FC3C */
    R[4] = lw_(R[16] + 28);  /* 0x8009FC40 */
    R[2] = R[2] + R[3];  /* 0x8009FC44 */
    R[2] = R[2] + R[4];  /* 0x8009FC48 */
    sw_(R[16] + 52, R[2]);  /* 0x8009FC4C */
    R[31] = lw_(R[29] + 36);  /* 0x8009FC50 */
    R[20] = lw_(R[29] + 32);  /* 0x8009FC54 */
    R[19] = lw_(R[29] + 28);  /* 0x8009FC58 */
    R[18] = lw_(R[29] + 24);  /* 0x8009FC5C */
    R[17] = lw_(R[29] + 20);  /* 0x8009FC60 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FC64 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009FC68 jr ra */
}

void ev_8009FA8C(void) {
    R[19] = 0x6666u << 16;  /* 0x8009FA8C */
    R[4] = lw_(R[16] + 16);  /* 0x8009FA90 */
    R[19] = R[19] | 0x6667;  /* 0x8009FA94 */
    R[4] = R[4] << 1;  /* 0x8009FA98 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FA9C */
    R[5] = R[18] + R[0];  /* 0x8009FAA0 */
    R[18] = R[2] + R[0];  /* 0x8009FAA4 */
    R[17] = R[17] - R[18];  /* 0x8009FAA8 */
    R[17] = R[17] - R[5];  /* 0x8009FAAC */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FAB0 */
    R[3] = HI;  /* 0x8009FAB4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FAB8 */
    { uint32_t _t = R[20]; R[31] = 0x8009FAC4u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FABC jalr */
    R[4] = lw_(R[16] + 16);  /* 0x8009FAC4 */
    R[4] = R[4] << 1;  /* 0x8009FACC */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FAD0 */
    R[3] = HI;  /* 0x8009FAD4 */
    R[6] = lw_(R[16] + 16);  /* 0x8009FAD8 */
    { int64_t _p = (int64_t)(int32_t)R[6] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FAE0 */
    R[5] = R[18] + R[0];  /* 0x8009FAE4 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FAE8 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FAEC */
    R[4] = R[3] - R[4];  /* 0x8009FAF0 */
    R[6] = (uint32_t)((int32_t)R[6] >> 31);  /* 0x8009FAF4 */
    R[7] = HI;  /* 0x8009FAF8 */
    R[3] = (uint32_t)((int32_t)R[7] >> 1);  /* 0x8009FAFC */
    R[3] = R[3] - R[6];  /* 0x8009FB00 */
    R[3] = R[3] + R[2];  /* 0x8009FB04 */
    { uint32_t _t = R[20]; R[31] = 0x8009FB10u; sw_(R[16] + 20, R[3]); psx_next = _t; return; }  /* 0x8009FB08 jalr */
    R[4] = lw_(R[16] + 16);  /* 0x8009FB10 */
    R[4] = R[4] << 1;  /* 0x8009FB18 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB1C */
    R[3] = HI;  /* 0x8009FB20 */
    R[6] = lw_(R[16] + 16);  /* 0x8009FB24 */
    { int64_t _p = (int64_t)(int32_t)R[6] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB2C */
    R[5] = R[17] + R[0];  /* 0x8009FB30 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB34 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FB38 */
    R[4] = R[3] - R[4];  /* 0x8009FB3C */
    R[6] = (uint32_t)((int32_t)R[6] >> 31);  /* 0x8009FB40 */
    R[7] = HI;  /* 0x8009FB44 */
    R[3] = (uint32_t)((int32_t)R[7] >> 1);  /* 0x8009FB48 */
    R[3] = R[3] - R[6];  /* 0x8009FB4C */
    R[3] = R[3] + R[2];  /* 0x8009FB50 */
    { uint32_t _t = R[20]; R[31] = 0x8009FB5Cu; sw_(R[16] + 24, R[3]); psx_next = _t; return; }  /* 0x8009FB54 jalr */
    R[4] = lw_(R[16] + 16);  /* 0x8009FB5C */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB64 */
    R[17] = 0x5555u << 16;  /* 0x8009FB68 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB6C */
    R[3] = HI;  /* 0x8009FB70 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FB74 */
    R[3] = R[3] - R[4];  /* 0x8009FB78 */
    R[3] = R[3] + R[2];  /* 0x8009FB7C */
    { R[31] = 0x8009FB88u; sw_(R[16] + 28, R[3]); psx_next = 0x800A0260u; return; }  /* 0x8009FB80 jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FB88 */
    R[17] = R[17] | 0x5556;  /* 0x8009FB8C */
    R[4] = R[4] << 1;  /* 0x8009FB90 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB94 */
    R[5] = R[2] + R[0];  /* 0x8009FB98 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB9C */
    R[3] = HI;  /* 0x8009FBA0 */
    { uint32_t _t = R[20]; R[31] = 0x8009FBACu; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBA4 jalr */
    { R[31] = 0x8009FBB4u; sw_(R[16] + 32, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBAC jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBB4 */
    R[4] = R[4] << 1;  /* 0x8009FBBC */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBC0 */
    R[5] = R[2] + R[0];  /* 0x8009FBC4 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBC8 */
    R[3] = HI;  /* 0x8009FBCC */
    { uint32_t _t = R[20]; R[31] = 0x8009FBD8u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBD0 jalr */
    { R[31] = 0x8009FBE0u; sw_(R[16] + 36, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBD8 jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBE0 */
    R[4] = R[4] << 1;  /* 0x8009FBE8 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBEC */
    R[5] = R[2] + R[0];  /* 0x8009FBF0 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBF4 */
    R[3] = HI;  /* 0x8009FBF8 */
    { uint32_t _t = R[20]; R[31] = 0x8009FC04u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBFC jalr */
    sw_(R[16] + 40, R[2]);  /* 0x8009FC04 */
    R[2] = lw_(R[16]);  /* 0x8009FC08 */
    R[3] = lw_(R[16] + 32);  /* 0x8009FC0C */
    R[4] = lw_(R[16] + 20);  /* 0x8009FC10 */
    R[2] = R[2] + R[3];  /* 0x8009FC14 */
    R[2] = R[2] + R[4];  /* 0x8009FC18 */
    sw_(R[16] + 44, R[2]);  /* 0x8009FC1C */
    R[2] = lw_(R[16] + 4);  /* 0x8009FC20 */
    R[3] = lw_(R[16] + 36);  /* 0x8009FC24 */
    R[4] = lw_(R[16] + 24);  /* 0x8009FC28 */
    R[2] = R[2] + R[3];  /* 0x8009FC2C */
    R[2] = R[2] + R[4];  /* 0x8009FC30 */
    sw_(R[16] + 48, R[2]);  /* 0x8009FC34 */
    R[2] = lw_(R[16] + 8);  /* 0x8009FC38 */
    R[3] = lw_(R[16] + 40);  /* 0x8009FC3C */
    R[4] = lw_(R[16] + 28);  /* 0x8009FC40 */
    R[2] = R[2] + R[3];  /* 0x8009FC44 */
    R[2] = R[2] + R[4];  /* 0x8009FC48 */
    sw_(R[16] + 52, R[2]);  /* 0x8009FC4C */
    R[31] = lw_(R[29] + 36);  /* 0x8009FC50 */
    R[20] = lw_(R[29] + 32);  /* 0x8009FC54 */
    R[19] = lw_(R[29] + 28);  /* 0x8009FC58 */
    R[18] = lw_(R[29] + 24);  /* 0x8009FC5C */
    R[17] = lw_(R[29] + 20);  /* 0x8009FC60 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FC64 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009FC68 jr ra */
}

void ev_8009FAC4(void) {
    R[4] = lw_(R[16] + 16);  /* 0x8009FAC4 */
    R[4] = R[4] << 1;  /* 0x8009FACC */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FAD0 */
    R[3] = HI;  /* 0x8009FAD4 */
    R[6] = lw_(R[16] + 16);  /* 0x8009FAD8 */
    { int64_t _p = (int64_t)(int32_t)R[6] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FAE0 */
    R[5] = R[18] + R[0];  /* 0x8009FAE4 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FAE8 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FAEC */
    R[4] = R[3] - R[4];  /* 0x8009FAF0 */
    R[6] = (uint32_t)((int32_t)R[6] >> 31);  /* 0x8009FAF4 */
    R[7] = HI;  /* 0x8009FAF8 */
    R[3] = (uint32_t)((int32_t)R[7] >> 1);  /* 0x8009FAFC */
    R[3] = R[3] - R[6];  /* 0x8009FB00 */
    R[3] = R[3] + R[2];  /* 0x8009FB04 */
    { uint32_t _t = R[20]; R[31] = 0x8009FB10u; sw_(R[16] + 20, R[3]); psx_next = _t; return; }  /* 0x8009FB08 jalr */
    R[4] = lw_(R[16] + 16);  /* 0x8009FB10 */
    R[4] = R[4] << 1;  /* 0x8009FB18 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB1C */
    R[3] = HI;  /* 0x8009FB20 */
    R[6] = lw_(R[16] + 16);  /* 0x8009FB24 */
    { int64_t _p = (int64_t)(int32_t)R[6] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB2C */
    R[5] = R[17] + R[0];  /* 0x8009FB30 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB34 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FB38 */
    R[4] = R[3] - R[4];  /* 0x8009FB3C */
    R[6] = (uint32_t)((int32_t)R[6] >> 31);  /* 0x8009FB40 */
    R[7] = HI;  /* 0x8009FB44 */
    R[3] = (uint32_t)((int32_t)R[7] >> 1);  /* 0x8009FB48 */
    R[3] = R[3] - R[6];  /* 0x8009FB4C */
    R[3] = R[3] + R[2];  /* 0x8009FB50 */
    { uint32_t _t = R[20]; R[31] = 0x8009FB5Cu; sw_(R[16] + 24, R[3]); psx_next = _t; return; }  /* 0x8009FB54 jalr */
    R[4] = lw_(R[16] + 16);  /* 0x8009FB5C */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB64 */
    R[17] = 0x5555u << 16;  /* 0x8009FB68 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB6C */
    R[3] = HI;  /* 0x8009FB70 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FB74 */
    R[3] = R[3] - R[4];  /* 0x8009FB78 */
    R[3] = R[3] + R[2];  /* 0x8009FB7C */
    { R[31] = 0x8009FB88u; sw_(R[16] + 28, R[3]); psx_next = 0x800A0260u; return; }  /* 0x8009FB80 jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FB88 */
    R[17] = R[17] | 0x5556;  /* 0x8009FB8C */
    R[4] = R[4] << 1;  /* 0x8009FB90 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB94 */
    R[5] = R[2] + R[0];  /* 0x8009FB98 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB9C */
    R[3] = HI;  /* 0x8009FBA0 */
    { uint32_t _t = R[20]; R[31] = 0x8009FBACu; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBA4 jalr */
    { R[31] = 0x8009FBB4u; sw_(R[16] + 32, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBAC jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBB4 */
    R[4] = R[4] << 1;  /* 0x8009FBBC */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBC0 */
    R[5] = R[2] + R[0];  /* 0x8009FBC4 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBC8 */
    R[3] = HI;  /* 0x8009FBCC */
    { uint32_t _t = R[20]; R[31] = 0x8009FBD8u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBD0 jalr */
    { R[31] = 0x8009FBE0u; sw_(R[16] + 36, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBD8 jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBE0 */
    R[4] = R[4] << 1;  /* 0x8009FBE8 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBEC */
    R[5] = R[2] + R[0];  /* 0x8009FBF0 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBF4 */
    R[3] = HI;  /* 0x8009FBF8 */
    { uint32_t _t = R[20]; R[31] = 0x8009FC04u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBFC jalr */
    sw_(R[16] + 40, R[2]);  /* 0x8009FC04 */
    R[2] = lw_(R[16]);  /* 0x8009FC08 */
    R[3] = lw_(R[16] + 32);  /* 0x8009FC0C */
    R[4] = lw_(R[16] + 20);  /* 0x8009FC10 */
    R[2] = R[2] + R[3];  /* 0x8009FC14 */
    R[2] = R[2] + R[4];  /* 0x8009FC18 */
    sw_(R[16] + 44, R[2]);  /* 0x8009FC1C */
    R[2] = lw_(R[16] + 4);  /* 0x8009FC20 */
    R[3] = lw_(R[16] + 36);  /* 0x8009FC24 */
    R[4] = lw_(R[16] + 24);  /* 0x8009FC28 */
    R[2] = R[2] + R[3];  /* 0x8009FC2C */
    R[2] = R[2] + R[4];  /* 0x8009FC30 */
    sw_(R[16] + 48, R[2]);  /* 0x8009FC34 */
    R[2] = lw_(R[16] + 8);  /* 0x8009FC38 */
    R[3] = lw_(R[16] + 40);  /* 0x8009FC3C */
    R[4] = lw_(R[16] + 28);  /* 0x8009FC40 */
    R[2] = R[2] + R[3];  /* 0x8009FC44 */
    R[2] = R[2] + R[4];  /* 0x8009FC48 */
    sw_(R[16] + 52, R[2]);  /* 0x8009FC4C */
    R[31] = lw_(R[29] + 36);  /* 0x8009FC50 */
    R[20] = lw_(R[29] + 32);  /* 0x8009FC54 */
    R[19] = lw_(R[29] + 28);  /* 0x8009FC58 */
    R[18] = lw_(R[29] + 24);  /* 0x8009FC5C */
    R[17] = lw_(R[29] + 20);  /* 0x8009FC60 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FC64 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009FC68 jr ra */
}

void ev_8009FB10(void) {
    R[4] = lw_(R[16] + 16);  /* 0x8009FB10 */
    R[4] = R[4] << 1;  /* 0x8009FB18 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB1C */
    R[3] = HI;  /* 0x8009FB20 */
    R[6] = lw_(R[16] + 16);  /* 0x8009FB24 */
    { int64_t _p = (int64_t)(int32_t)R[6] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB2C */
    R[5] = R[17] + R[0];  /* 0x8009FB30 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB34 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FB38 */
    R[4] = R[3] - R[4];  /* 0x8009FB3C */
    R[6] = (uint32_t)((int32_t)R[6] >> 31);  /* 0x8009FB40 */
    R[7] = HI;  /* 0x8009FB44 */
    R[3] = (uint32_t)((int32_t)R[7] >> 1);  /* 0x8009FB48 */
    R[3] = R[3] - R[6];  /* 0x8009FB4C */
    R[3] = R[3] + R[2];  /* 0x8009FB50 */
    { uint32_t _t = R[20]; R[31] = 0x8009FB5Cu; sw_(R[16] + 24, R[3]); psx_next = _t; return; }  /* 0x8009FB54 jalr */
    R[4] = lw_(R[16] + 16);  /* 0x8009FB5C */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB64 */
    R[17] = 0x5555u << 16;  /* 0x8009FB68 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB6C */
    R[3] = HI;  /* 0x8009FB70 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FB74 */
    R[3] = R[3] - R[4];  /* 0x8009FB78 */
    R[3] = R[3] + R[2];  /* 0x8009FB7C */
    { R[31] = 0x8009FB88u; sw_(R[16] + 28, R[3]); psx_next = 0x800A0260u; return; }  /* 0x8009FB80 jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FB88 */
    R[17] = R[17] | 0x5556;  /* 0x8009FB8C */
    R[4] = R[4] << 1;  /* 0x8009FB90 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB94 */
    R[5] = R[2] + R[0];  /* 0x8009FB98 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB9C */
    R[3] = HI;  /* 0x8009FBA0 */
    { uint32_t _t = R[20]; R[31] = 0x8009FBACu; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBA4 jalr */
    { R[31] = 0x8009FBB4u; sw_(R[16] + 32, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBAC jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBB4 */
    R[4] = R[4] << 1;  /* 0x8009FBBC */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBC0 */
    R[5] = R[2] + R[0];  /* 0x8009FBC4 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBC8 */
    R[3] = HI;  /* 0x8009FBCC */
    { uint32_t _t = R[20]; R[31] = 0x8009FBD8u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBD0 jalr */
    { R[31] = 0x8009FBE0u; sw_(R[16] + 36, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBD8 jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBE0 */
    R[4] = R[4] << 1;  /* 0x8009FBE8 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBEC */
    R[5] = R[2] + R[0];  /* 0x8009FBF0 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBF4 */
    R[3] = HI;  /* 0x8009FBF8 */
    { uint32_t _t = R[20]; R[31] = 0x8009FC04u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBFC jalr */
    sw_(R[16] + 40, R[2]);  /* 0x8009FC04 */
    R[2] = lw_(R[16]);  /* 0x8009FC08 */
    R[3] = lw_(R[16] + 32);  /* 0x8009FC0C */
    R[4] = lw_(R[16] + 20);  /* 0x8009FC10 */
    R[2] = R[2] + R[3];  /* 0x8009FC14 */
    R[2] = R[2] + R[4];  /* 0x8009FC18 */
    sw_(R[16] + 44, R[2]);  /* 0x8009FC1C */
    R[2] = lw_(R[16] + 4);  /* 0x8009FC20 */
    R[3] = lw_(R[16] + 36);  /* 0x8009FC24 */
    R[4] = lw_(R[16] + 24);  /* 0x8009FC28 */
    R[2] = R[2] + R[3];  /* 0x8009FC2C */
    R[2] = R[2] + R[4];  /* 0x8009FC30 */
    sw_(R[16] + 48, R[2]);  /* 0x8009FC34 */
    R[2] = lw_(R[16] + 8);  /* 0x8009FC38 */
    R[3] = lw_(R[16] + 40);  /* 0x8009FC3C */
    R[4] = lw_(R[16] + 28);  /* 0x8009FC40 */
    R[2] = R[2] + R[3];  /* 0x8009FC44 */
    R[2] = R[2] + R[4];  /* 0x8009FC48 */
    sw_(R[16] + 52, R[2]);  /* 0x8009FC4C */
    R[31] = lw_(R[29] + 36);  /* 0x8009FC50 */
    R[20] = lw_(R[29] + 32);  /* 0x8009FC54 */
    R[19] = lw_(R[29] + 28);  /* 0x8009FC58 */
    R[18] = lw_(R[29] + 24);  /* 0x8009FC5C */
    R[17] = lw_(R[29] + 20);  /* 0x8009FC60 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FC64 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009FC68 jr ra */
}

void ev_8009FB5C(void) {
    R[4] = lw_(R[16] + 16);  /* 0x8009FB5C */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[19]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB64 */
    R[17] = 0x5555u << 16;  /* 0x8009FB68 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB6C */
    R[3] = HI;  /* 0x8009FB70 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009FB74 */
    R[3] = R[3] - R[4];  /* 0x8009FB78 */
    R[3] = R[3] + R[2];  /* 0x8009FB7C */
    { R[31] = 0x8009FB88u; sw_(R[16] + 28, R[3]); psx_next = 0x800A0260u; return; }  /* 0x8009FB80 jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FB88 */
    R[17] = R[17] | 0x5556;  /* 0x8009FB8C */
    R[4] = R[4] << 1;  /* 0x8009FB90 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB94 */
    R[5] = R[2] + R[0];  /* 0x8009FB98 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB9C */
    R[3] = HI;  /* 0x8009FBA0 */
    { uint32_t _t = R[20]; R[31] = 0x8009FBACu; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBA4 jalr */
    { R[31] = 0x8009FBB4u; sw_(R[16] + 32, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBAC jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBB4 */
    R[4] = R[4] << 1;  /* 0x8009FBBC */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBC0 */
    R[5] = R[2] + R[0];  /* 0x8009FBC4 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBC8 */
    R[3] = HI;  /* 0x8009FBCC */
    { uint32_t _t = R[20]; R[31] = 0x8009FBD8u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBD0 jalr */
    { R[31] = 0x8009FBE0u; sw_(R[16] + 36, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBD8 jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBE0 */
    R[4] = R[4] << 1;  /* 0x8009FBE8 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBEC */
    R[5] = R[2] + R[0];  /* 0x8009FBF0 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBF4 */
    R[3] = HI;  /* 0x8009FBF8 */
    { uint32_t _t = R[20]; R[31] = 0x8009FC04u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBFC jalr */
    sw_(R[16] + 40, R[2]);  /* 0x8009FC04 */
    R[2] = lw_(R[16]);  /* 0x8009FC08 */
    R[3] = lw_(R[16] + 32);  /* 0x8009FC0C */
    R[4] = lw_(R[16] + 20);  /* 0x8009FC10 */
    R[2] = R[2] + R[3];  /* 0x8009FC14 */
    R[2] = R[2] + R[4];  /* 0x8009FC18 */
    sw_(R[16] + 44, R[2]);  /* 0x8009FC1C */
    R[2] = lw_(R[16] + 4);  /* 0x8009FC20 */
    R[3] = lw_(R[16] + 36);  /* 0x8009FC24 */
    R[4] = lw_(R[16] + 24);  /* 0x8009FC28 */
    R[2] = R[2] + R[3];  /* 0x8009FC2C */
    R[2] = R[2] + R[4];  /* 0x8009FC30 */
    sw_(R[16] + 48, R[2]);  /* 0x8009FC34 */
    R[2] = lw_(R[16] + 8);  /* 0x8009FC38 */
    R[3] = lw_(R[16] + 40);  /* 0x8009FC3C */
    R[4] = lw_(R[16] + 28);  /* 0x8009FC40 */
    R[2] = R[2] + R[3];  /* 0x8009FC44 */
    R[2] = R[2] + R[4];  /* 0x8009FC48 */
    sw_(R[16] + 52, R[2]);  /* 0x8009FC4C */
    R[31] = lw_(R[29] + 36);  /* 0x8009FC50 */
    R[20] = lw_(R[29] + 32);  /* 0x8009FC54 */
    R[19] = lw_(R[29] + 28);  /* 0x8009FC58 */
    R[18] = lw_(R[29] + 24);  /* 0x8009FC5C */
    R[17] = lw_(R[29] + 20);  /* 0x8009FC60 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FC64 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009FC68 jr ra */
}

void ev_8009FB88(void) {
    R[4] = lw_(R[16] + 12);  /* 0x8009FB88 */
    R[17] = R[17] | 0x5556;  /* 0x8009FB8C */
    R[4] = R[4] << 1;  /* 0x8009FB90 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FB94 */
    R[5] = R[2] + R[0];  /* 0x8009FB98 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FB9C */
    R[3] = HI;  /* 0x8009FBA0 */
    { uint32_t _t = R[20]; R[31] = 0x8009FBACu; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBA4 jalr */
    { R[31] = 0x8009FBB4u; sw_(R[16] + 32, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBAC jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBB4 */
    R[4] = R[4] << 1;  /* 0x8009FBBC */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBC0 */
    R[5] = R[2] + R[0];  /* 0x8009FBC4 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBC8 */
    R[3] = HI;  /* 0x8009FBCC */
    { uint32_t _t = R[20]; R[31] = 0x8009FBD8u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBD0 jalr */
    { R[31] = 0x8009FBE0u; sw_(R[16] + 36, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBD8 jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBE0 */
    R[4] = R[4] << 1;  /* 0x8009FBE8 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBEC */
    R[5] = R[2] + R[0];  /* 0x8009FBF0 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBF4 */
    R[3] = HI;  /* 0x8009FBF8 */
    { uint32_t _t = R[20]; R[31] = 0x8009FC04u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBFC jalr */
    sw_(R[16] + 40, R[2]);  /* 0x8009FC04 */
    R[2] = lw_(R[16]);  /* 0x8009FC08 */
    R[3] = lw_(R[16] + 32);  /* 0x8009FC0C */
    R[4] = lw_(R[16] + 20);  /* 0x8009FC10 */
    R[2] = R[2] + R[3];  /* 0x8009FC14 */
    R[2] = R[2] + R[4];  /* 0x8009FC18 */
    sw_(R[16] + 44, R[2]);  /* 0x8009FC1C */
    R[2] = lw_(R[16] + 4);  /* 0x8009FC20 */
    R[3] = lw_(R[16] + 36);  /* 0x8009FC24 */
    R[4] = lw_(R[16] + 24);  /* 0x8009FC28 */
    R[2] = R[2] + R[3];  /* 0x8009FC2C */
    R[2] = R[2] + R[4];  /* 0x8009FC30 */
    sw_(R[16] + 48, R[2]);  /* 0x8009FC34 */
    R[2] = lw_(R[16] + 8);  /* 0x8009FC38 */
    R[3] = lw_(R[16] + 40);  /* 0x8009FC3C */
    R[4] = lw_(R[16] + 28);  /* 0x8009FC40 */
    R[2] = R[2] + R[3];  /* 0x8009FC44 */
    R[2] = R[2] + R[4];  /* 0x8009FC48 */
    sw_(R[16] + 52, R[2]);  /* 0x8009FC4C */
    R[31] = lw_(R[29] + 36);  /* 0x8009FC50 */
    R[20] = lw_(R[29] + 32);  /* 0x8009FC54 */
    R[19] = lw_(R[29] + 28);  /* 0x8009FC58 */
    R[18] = lw_(R[29] + 24);  /* 0x8009FC5C */
    R[17] = lw_(R[29] + 20);  /* 0x8009FC60 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FC64 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009FC68 jr ra */
}

void ev_8009FBAC(void) {
    { R[31] = 0x8009FBB4u; sw_(R[16] + 32, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBAC jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBB4 */
    R[4] = R[4] << 1;  /* 0x8009FBBC */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBC0 */
    R[5] = R[2] + R[0];  /* 0x8009FBC4 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBC8 */
    R[3] = HI;  /* 0x8009FBCC */
    { uint32_t _t = R[20]; R[31] = 0x8009FBD8u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBD0 jalr */
    { R[31] = 0x8009FBE0u; sw_(R[16] + 36, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBD8 jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBE0 */
    R[4] = R[4] << 1;  /* 0x8009FBE8 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBEC */
    R[5] = R[2] + R[0];  /* 0x8009FBF0 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBF4 */
    R[3] = HI;  /* 0x8009FBF8 */
    { uint32_t _t = R[20]; R[31] = 0x8009FC04u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBFC jalr */
    sw_(R[16] + 40, R[2]);  /* 0x8009FC04 */
    R[2] = lw_(R[16]);  /* 0x8009FC08 */
    R[3] = lw_(R[16] + 32);  /* 0x8009FC0C */
    R[4] = lw_(R[16] + 20);  /* 0x8009FC10 */
    R[2] = R[2] + R[3];  /* 0x8009FC14 */
    R[2] = R[2] + R[4];  /* 0x8009FC18 */
    sw_(R[16] + 44, R[2]);  /* 0x8009FC1C */
    R[2] = lw_(R[16] + 4);  /* 0x8009FC20 */
    R[3] = lw_(R[16] + 36);  /* 0x8009FC24 */
    R[4] = lw_(R[16] + 24);  /* 0x8009FC28 */
    R[2] = R[2] + R[3];  /* 0x8009FC2C */
    R[2] = R[2] + R[4];  /* 0x8009FC30 */
    sw_(R[16] + 48, R[2]);  /* 0x8009FC34 */
    R[2] = lw_(R[16] + 8);  /* 0x8009FC38 */
    R[3] = lw_(R[16] + 40);  /* 0x8009FC3C */
    R[4] = lw_(R[16] + 28);  /* 0x8009FC40 */
    R[2] = R[2] + R[3];  /* 0x8009FC44 */
    R[2] = R[2] + R[4];  /* 0x8009FC48 */
    sw_(R[16] + 52, R[2]);  /* 0x8009FC4C */
    R[31] = lw_(R[29] + 36);  /* 0x8009FC50 */
    R[20] = lw_(R[29] + 32);  /* 0x8009FC54 */
    R[19] = lw_(R[29] + 28);  /* 0x8009FC58 */
    R[18] = lw_(R[29] + 24);  /* 0x8009FC5C */
    R[17] = lw_(R[29] + 20);  /* 0x8009FC60 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FC64 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009FC68 jr ra */
}

void ev_8009FBB4(void) {
    R[4] = lw_(R[16] + 12);  /* 0x8009FBB4 */
    R[4] = R[4] << 1;  /* 0x8009FBBC */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBC0 */
    R[5] = R[2] + R[0];  /* 0x8009FBC4 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBC8 */
    R[3] = HI;  /* 0x8009FBCC */
    { uint32_t _t = R[20]; R[31] = 0x8009FBD8u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBD0 jalr */
    { R[31] = 0x8009FBE0u; sw_(R[16] + 36, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBD8 jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBE0 */
    R[4] = R[4] << 1;  /* 0x8009FBE8 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBEC */
    R[5] = R[2] + R[0];  /* 0x8009FBF0 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBF4 */
    R[3] = HI;  /* 0x8009FBF8 */
    { uint32_t _t = R[20]; R[31] = 0x8009FC04u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBFC jalr */
    sw_(R[16] + 40, R[2]);  /* 0x8009FC04 */
    R[2] = lw_(R[16]);  /* 0x8009FC08 */
    R[3] = lw_(R[16] + 32);  /* 0x8009FC0C */
    R[4] = lw_(R[16] + 20);  /* 0x8009FC10 */
    R[2] = R[2] + R[3];  /* 0x8009FC14 */
    R[2] = R[2] + R[4];  /* 0x8009FC18 */
    sw_(R[16] + 44, R[2]);  /* 0x8009FC1C */
    R[2] = lw_(R[16] + 4);  /* 0x8009FC20 */
    R[3] = lw_(R[16] + 36);  /* 0x8009FC24 */
    R[4] = lw_(R[16] + 24);  /* 0x8009FC28 */
    R[2] = R[2] + R[3];  /* 0x8009FC2C */
    R[2] = R[2] + R[4];  /* 0x8009FC30 */
    sw_(R[16] + 48, R[2]);  /* 0x8009FC34 */
    R[2] = lw_(R[16] + 8);  /* 0x8009FC38 */
    R[3] = lw_(R[16] + 40);  /* 0x8009FC3C */
    R[4] = lw_(R[16] + 28);  /* 0x8009FC40 */
    R[2] = R[2] + R[3];  /* 0x8009FC44 */
    R[2] = R[2] + R[4];  /* 0x8009FC48 */
    sw_(R[16] + 52, R[2]);  /* 0x8009FC4C */
    R[31] = lw_(R[29] + 36);  /* 0x8009FC50 */
    R[20] = lw_(R[29] + 32);  /* 0x8009FC54 */
    R[19] = lw_(R[29] + 28);  /* 0x8009FC58 */
    R[18] = lw_(R[29] + 24);  /* 0x8009FC5C */
    R[17] = lw_(R[29] + 20);  /* 0x8009FC60 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FC64 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009FC68 jr ra */
}

void ev_8009FBD8(void) {
    { R[31] = 0x8009FBE0u; sw_(R[16] + 36, R[2]); psx_next = 0x800A0260u; return; }  /* 0x8009FBD8 jal */
    R[4] = lw_(R[16] + 12);  /* 0x8009FBE0 */
    R[4] = R[4] << 1;  /* 0x8009FBE8 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBEC */
    R[5] = R[2] + R[0];  /* 0x8009FBF0 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBF4 */
    R[3] = HI;  /* 0x8009FBF8 */
    { uint32_t _t = R[20]; R[31] = 0x8009FC04u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBFC jalr */
    sw_(R[16] + 40, R[2]);  /* 0x8009FC04 */
    R[2] = lw_(R[16]);  /* 0x8009FC08 */
    R[3] = lw_(R[16] + 32);  /* 0x8009FC0C */
    R[4] = lw_(R[16] + 20);  /* 0x8009FC10 */
    R[2] = R[2] + R[3];  /* 0x8009FC14 */
    R[2] = R[2] + R[4];  /* 0x8009FC18 */
    sw_(R[16] + 44, R[2]);  /* 0x8009FC1C */
    R[2] = lw_(R[16] + 4);  /* 0x8009FC20 */
    R[3] = lw_(R[16] + 36);  /* 0x8009FC24 */
    R[4] = lw_(R[16] + 24);  /* 0x8009FC28 */
    R[2] = R[2] + R[3];  /* 0x8009FC2C */
    R[2] = R[2] + R[4];  /* 0x8009FC30 */
    sw_(R[16] + 48, R[2]);  /* 0x8009FC34 */
    R[2] = lw_(R[16] + 8);  /* 0x8009FC38 */
    R[3] = lw_(R[16] + 40);  /* 0x8009FC3C */
    R[4] = lw_(R[16] + 28);  /* 0x8009FC40 */
    R[2] = R[2] + R[3];  /* 0x8009FC44 */
    R[2] = R[2] + R[4];  /* 0x8009FC48 */
    sw_(R[16] + 52, R[2]);  /* 0x8009FC4C */
    R[31] = lw_(R[29] + 36);  /* 0x8009FC50 */
    R[20] = lw_(R[29] + 32);  /* 0x8009FC54 */
    R[19] = lw_(R[29] + 28);  /* 0x8009FC58 */
    R[18] = lw_(R[29] + 24);  /* 0x8009FC5C */
    R[17] = lw_(R[29] + 20);  /* 0x8009FC60 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FC64 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009FC68 jr ra */
}

void ev_8009FBE0(void) {
    R[4] = lw_(R[16] + 12);  /* 0x8009FBE0 */
    R[4] = R[4] << 1;  /* 0x8009FBE8 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[17]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009FBEC */
    R[5] = R[2] + R[0];  /* 0x8009FBF0 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x8009FBF4 */
    R[3] = HI;  /* 0x8009FBF8 */
    { uint32_t _t = R[20]; R[31] = 0x8009FC04u; R[4] = R[3] - R[4]; psx_next = _t; return; }  /* 0x8009FBFC jalr */
    sw_(R[16] + 40, R[2]);  /* 0x8009FC04 */
    R[2] = lw_(R[16]);  /* 0x8009FC08 */
    R[3] = lw_(R[16] + 32);  /* 0x8009FC0C */
    R[4] = lw_(R[16] + 20);  /* 0x8009FC10 */
    R[2] = R[2] + R[3];  /* 0x8009FC14 */
    R[2] = R[2] + R[4];  /* 0x8009FC18 */
    sw_(R[16] + 44, R[2]);  /* 0x8009FC1C */
    R[2] = lw_(R[16] + 4);  /* 0x8009FC20 */
    R[3] = lw_(R[16] + 36);  /* 0x8009FC24 */
    R[4] = lw_(R[16] + 24);  /* 0x8009FC28 */
    R[2] = R[2] + R[3];  /* 0x8009FC2C */
    R[2] = R[2] + R[4];  /* 0x8009FC30 */
    sw_(R[16] + 48, R[2]);  /* 0x8009FC34 */
    R[2] = lw_(R[16] + 8);  /* 0x8009FC38 */
    R[3] = lw_(R[16] + 40);  /* 0x8009FC3C */
    R[4] = lw_(R[16] + 28);  /* 0x8009FC40 */
    R[2] = R[2] + R[3];  /* 0x8009FC44 */
    R[2] = R[2] + R[4];  /* 0x8009FC48 */
    sw_(R[16] + 52, R[2]);  /* 0x8009FC4C */
    R[31] = lw_(R[29] + 36);  /* 0x8009FC50 */
    R[20] = lw_(R[29] + 32);  /* 0x8009FC54 */
    R[19] = lw_(R[29] + 28);  /* 0x8009FC58 */
    R[18] = lw_(R[29] + 24);  /* 0x8009FC5C */
    R[17] = lw_(R[29] + 20);  /* 0x8009FC60 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FC64 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009FC68 jr ra */
}

void ev_8009FC00(void) {
    R[4] = R[3] - R[4];  /* 0x8009FC00 */
    sw_(R[16] + 40, R[2]);  /* 0x8009FC04 */
    R[2] = lw_(R[16]);  /* 0x8009FC08 */
    R[3] = lw_(R[16] + 32);  /* 0x8009FC0C */
    R[4] = lw_(R[16] + 20);  /* 0x8009FC10 */
    R[2] = R[2] + R[3];  /* 0x8009FC14 */
    R[2] = R[2] + R[4];  /* 0x8009FC18 */
    sw_(R[16] + 44, R[2]);  /* 0x8009FC1C */
    R[2] = lw_(R[16] + 4);  /* 0x8009FC20 */
    R[3] = lw_(R[16] + 36);  /* 0x8009FC24 */
    R[4] = lw_(R[16] + 24);  /* 0x8009FC28 */
    R[2] = R[2] + R[3];  /* 0x8009FC2C */
    R[2] = R[2] + R[4];  /* 0x8009FC30 */
    sw_(R[16] + 48, R[2]);  /* 0x8009FC34 */
    R[2] = lw_(R[16] + 8);  /* 0x8009FC38 */
    R[3] = lw_(R[16] + 40);  /* 0x8009FC3C */
    R[4] = lw_(R[16] + 28);  /* 0x8009FC40 */
    R[2] = R[2] + R[3];  /* 0x8009FC44 */
    R[2] = R[2] + R[4];  /* 0x8009FC48 */
    sw_(R[16] + 52, R[2]);  /* 0x8009FC4C */
    R[31] = lw_(R[29] + 36);  /* 0x8009FC50 */
    R[20] = lw_(R[29] + 32);  /* 0x8009FC54 */
    R[19] = lw_(R[29] + 28);  /* 0x8009FC58 */
    R[18] = lw_(R[29] + 24);  /* 0x8009FC5C */
    R[17] = lw_(R[29] + 20);  /* 0x8009FC60 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FC64 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009FC68 jr ra */
}

void ev_8009FC04(void) {
    sw_(R[16] + 40, R[2]);  /* 0x8009FC04 */
    R[2] = lw_(R[16]);  /* 0x8009FC08 */
    R[3] = lw_(R[16] + 32);  /* 0x8009FC0C */
    R[4] = lw_(R[16] + 20);  /* 0x8009FC10 */
    R[2] = R[2] + R[3];  /* 0x8009FC14 */
    R[2] = R[2] + R[4];  /* 0x8009FC18 */
    sw_(R[16] + 44, R[2]);  /* 0x8009FC1C */
    R[2] = lw_(R[16] + 4);  /* 0x8009FC20 */
    R[3] = lw_(R[16] + 36);  /* 0x8009FC24 */
    R[4] = lw_(R[16] + 24);  /* 0x8009FC28 */
    R[2] = R[2] + R[3];  /* 0x8009FC2C */
    R[2] = R[2] + R[4];  /* 0x8009FC30 */
    sw_(R[16] + 48, R[2]);  /* 0x8009FC34 */
    R[2] = lw_(R[16] + 8);  /* 0x8009FC38 */
    R[3] = lw_(R[16] + 40);  /* 0x8009FC3C */
    R[4] = lw_(R[16] + 28);  /* 0x8009FC40 */
    R[2] = R[2] + R[3];  /* 0x8009FC44 */
    R[2] = R[2] + R[4];  /* 0x8009FC48 */
    sw_(R[16] + 52, R[2]);  /* 0x8009FC4C */
    R[31] = lw_(R[29] + 36);  /* 0x8009FC50 */
    R[20] = lw_(R[29] + 32);  /* 0x8009FC54 */
    R[19] = lw_(R[29] + 28);  /* 0x8009FC58 */
    R[18] = lw_(R[29] + 24);  /* 0x8009FC5C */
    R[17] = lw_(R[29] + 20);  /* 0x8009FC60 */
    R[16] = lw_(R[29] + 16);  /* 0x8009FC64 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009FC68 jr ra */
}

void ev_8009FC70(void) {
    R[2] = lb_(R[4] + 57);  /* 0x8009FC70 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[0] + R[0]; if (_c) { goto L_8009FCA4; } }  /* 0x8009FC78 */
    R[2] = lb_(R[5] + 57);  /* 0x8009FC80 */
    R[3] = R[2] ^ 0x1;  /* 0x8009FC88 */
    R[3] = (R[3] < (uint32_t)1u);  /* 0x8009FC8C */
    R[6] = R[3] + R[0];  /* 0x8009FC90 */
    R[3] = R[0] + 2;  /* 0x8009FC94 */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009FCA4; } }  /* 0x8009FC98 */
    R[6] = R[3] + R[0];  /* 0x8009FCA0 */
L_8009FCA4:;
    R[7] = lb_(R[4] + 57);  /* 0x8009FCA4 */
    R[2] = R[0] + 1;  /* 0x8009FCA8 */
    { uint32_t _c = (R[7] != R[2]); if (_c) { goto L_8009FCE4; } }  /* 0x8009FCAC */
    R[3] = lb_(R[5] + 57);  /* 0x8009FCB4 */
    { uint32_t _c = (R[3] != R[0]); if (_c) { goto L_8009FCC8; } }  /* 0x8009FCBC */
    R[6] = R[0] + 2;  /* 0x8009FCC4 */
L_8009FCC8:;
    { uint32_t _c = (R[3] != R[7]); R[2] = R[0] + 2; if (_c) { goto L_8009FCD4; } }  /* 0x8009FCC8 */
    R[6] = R[0] + R[0];  /* 0x8009FCD0 */
L_8009FCD4:;
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009FCE0; } }  /* 0x8009FCD4 */
    R[6] = R[0] + 1;  /* 0x8009FCDC */
L_8009FCE0:;
    R[7] = lb_(R[4] + 57);  /* 0x8009FCE0 */
L_8009FCE4:;
    R[2] = R[0] + 2;  /* 0x8009FCE4 */
    { uint32_t _c = (R[7] != R[2]); if (_c) { goto L_8009FD1C; } }  /* 0x8009FCE8 */
    R[3] = lb_(R[5] + 57);  /* 0x8009FCF0 */
    { uint32_t _c = (R[3] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009FD04; } }  /* 0x8009FCF8 */
    R[6] = R[0] + 1;  /* 0x8009FD00 */
L_8009FD04:;
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009FD10; } }  /* 0x8009FD04 */
    R[6] = R[0] + 2;  /* 0x8009FD0C */
L_8009FD10:;
    { uint32_t _c = (R[3] != R[7]); R[7] = R[6] & 0xFF; if (_c) { goto L_8009FD20; } }  /* 0x8009FD10 */
    R[6] = R[0] + R[0];  /* 0x8009FD18 */
L_8009FD1C:;
    R[7] = R[6] & 0xFF;  /* 0x8009FD1C */
L_8009FD20:;
    R[6] = R[0] + 1;  /* 0x8009FD20 */
    { uint32_t _c = (R[7] != R[6]); R[2] = R[0] + 2; if (_c) { psx_next = 0x8009FD50u; return; } }  /* 0x8009FD24 b extern */
    sb_(R[4] + 56, R[6]);  /* 0x8009FD2C */
    sb_(R[5] + 56, R[0]);  /* 0x8009FD30 */
    R[2] = lw_(R[4] + 44);  /* 0x8009FD34 */
    R[3] = lw_(R[4] + 52);  /* 0x8009FD38 */
    R[2] = R[2] + 8192;  /* 0x8009FD3C */
    R[3] = R[3] + 8192;  /* 0x8009FD40 */
    sw_(R[4] + 44, R[2]);  /* 0x8009FD44 */
    sw_(R[4] + 52, R[3]);  /* 0x8009FD48 */
    R[2] = R[0] + 2;  /* 0x8009FD4C */
    psx_next = 0x8009FD50u; return;  /* fallthrough */
}

void ev_8009FD50(void) {
    { uint32_t _c = (R[7] != R[2]); if (_c) { goto L_8009FD78; } }  /* 0x8009FD50 */
    sb_(R[4] + 56, R[0]);  /* 0x8009FD58 */
    R[2] = lw_(R[5] + 44);  /* 0x8009FD5C */
    R[3] = lw_(R[5] + 52);  /* 0x8009FD60 */
    sb_(R[5] + 56, R[6]);  /* 0x8009FD64 */
    R[2] = R[2] + 8192;  /* 0x8009FD68 */
    R[3] = R[3] + 8192;  /* 0x8009FD6C */
    sw_(R[5] + 44, R[2]);  /* 0x8009FD70 */
    sw_(R[5] + 52, R[3]);  /* 0x8009FD74 */
L_8009FD78:;
    { psx_next = R[31]; return; }  /* 0x8009FD78 jr ra */
}

void ev_8009FD80(void) {
    R[8] = R[4] + R[0];  /* 0x8009FD80 */
    R[10] = lb_(R[29] + 16);  /* 0x8009FD84 */
    R[2] = ((int32_t)R[6] < (int32_t)R[7]);  /* 0x8009FD88 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[7] + R[0]; if (_c) { goto L_8009FD98; } }  /* 0x8009FD8C */
    R[3] = R[6] + R[0];  /* 0x8009FD94 */
L_8009FD98:;
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[3] + R[0]; if (_c) { goto L_8009FDA4; } }  /* 0x8009FD98 */
    R[2] = R[3] + 4095;  /* 0x8009FDA0 */
L_8009FDA4:;
    R[4] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8009FDA4 */
    R[2] = ((int32_t)R[4] < 9);  /* 0x8009FDA8 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[0] + 3; if (_c) { goto L_8009FDC4; } }  /* 0x8009FDAC */
    R[2] = ((int32_t)R[4] < 6);  /* 0x8009FDB4 */
    { uint32_t _c = (R[2] != R[0]); R[9] = R[0] + 1; if (_c) { goto L_8009FDC4; } }  /* 0x8009FDB8 */
    R[9] = R[0] + 2;  /* 0x8009FDC0 */
L_8009FDC4:;
    R[2] = ((int32_t)R[6] < (int32_t)R[7]);  /* 0x8009FDC4 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[10] & 0xFF; if (_c) { goto L_8009FE0C; } }  /* 0x8009FDC8 */
    R[3] = lb_(R[8] + 70);  /* 0x8009FDD0 */
    R[2] = R[3] << 1;  /* 0x8009FDD8 */
    R[2] = R[2] + R[3];  /* 0x8009FDDC */
    R[2] = R[4] + R[2];  /* 0x8009FDE0 */
    R[2] = R[8] + R[2];  /* 0x8009FDE4 */
    sb_(R[2] + 61, R[0]);  /* 0x8009FDE8 */
    R[3] = lb_(R[8] + 70);  /* 0x8009FDEC */
    R[2] = R[3] << 1;  /* 0x8009FDF4 */
    R[2] = R[2] + R[3];  /* 0x8009FDF8 */
    R[4] = R[4] + R[2];  /* 0x8009FDFC */
    R[4] = R[5] + R[4];  /* 0x8009FE00 */
    { sb_(R[4] + 61, R[9]); goto L_8009FE44; }  /* 0x8009FE04 j */
L_8009FE0C:;
    R[3] = lb_(R[8] + 70);  /* 0x8009FE0C */
    R[2] = R[3] << 1;  /* 0x8009FE14 */
    R[2] = R[2] + R[3];  /* 0x8009FE18 */
    R[2] = R[4] + R[2];  /* 0x8009FE1C */
    R[2] = R[8] + R[2];  /* 0x8009FE20 */
    sb_(R[2] + 61, R[9]);  /* 0x8009FE24 */
    R[3] = lb_(R[8] + 70);  /* 0x8009FE28 */
    R[2] = R[3] << 1;  /* 0x8009FE30 */
    R[2] = R[2] + R[3];  /* 0x8009FE34 */
    R[4] = R[4] + R[2];  /* 0x8009FE38 */
    R[4] = R[5] + R[4];  /* 0x8009FE3C */
    sb_(R[4] + 61, R[0]);  /* 0x8009FE40 */
L_8009FE44:;
    R[3] = R[10] & 0xFF;  /* 0x8009FE44 */
    R[2] = R[0] + 2;  /* 0x8009FE48 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009FED0; } }  /* 0x8009FE4C */
    R[2] = lw_(R[8] + 48);  /* 0x8009FE54 */
    R[3] = lw_(R[5] + 48);  /* 0x8009FE58 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009FE60 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009FEA0; } }  /* 0x8009FE64 */
    R[3] = lb_(R[8] + 70);  /* 0x8009FE6C */
    R[2] = R[3] << 1;  /* 0x8009FE74 */
    R[2] = R[2] + R[3];  /* 0x8009FE78 */
    R[2] = R[2] + R[8];  /* 0x8009FE7C */
    sb_(R[2] + 63, R[0]);  /* 0x8009FE80 */
    R[3] = lb_(R[8] + 70);  /* 0x8009FE84 */
    R[2] = R[3] << 1;  /* 0x8009FE8C */
    R[2] = R[2] + R[3];  /* 0x8009FE90 */
    R[2] = R[2] + R[5];  /* 0x8009FE94 */
    { sb_(R[2] + 63, R[9]); goto L_8009FED0; }  /* 0x8009FE98 j */
L_8009FEA0:;
    R[3] = lb_(R[8] + 70);  /* 0x8009FEA0 */
    R[2] = R[3] << 1;  /* 0x8009FEA8 */
    R[2] = R[2] + R[3];  /* 0x8009FEAC */
    R[2] = R[2] + R[8];  /* 0x8009FEB0 */
    sb_(R[2] + 63, R[9]);  /* 0x8009FEB4 */
    R[3] = lb_(R[8] + 70);  /* 0x8009FEB8 */
    R[2] = R[3] << 1;  /* 0x8009FEC0 */
    R[2] = R[2] + R[3];  /* 0x8009FEC4 */
    R[2] = R[2] + R[5];  /* 0x8009FEC8 */
    sb_(R[2] + 63, R[0]);  /* 0x8009FECC */
L_8009FED0:;
    R[2] = lw_(R[5] + 48);  /* 0x8009FED0 */
    R[2] = ((int32_t)R[2] < (int32_t)R[6]);  /* 0x8009FED8 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[10] & 0xFF; if (_c) { goto L_8009FF20; } }  /* 0x8009FEDC */
    R[3] = lb_(R[8] + 70);  /* 0x8009FEE4 */
    R[2] = R[3] << 1;  /* 0x8009FEEC */
    R[2] = R[2] + R[3];  /* 0x8009FEF0 */
    R[2] = R[4] + R[2];  /* 0x8009FEF4 */
    R[2] = R[8] + R[2];  /* 0x8009FEF8 */
    sb_(R[2] + 61, R[0]);  /* 0x8009FEFC */
    R[3] = lb_(R[8] + 70);  /* 0x8009FF00 */
    R[2] = R[3] << 1;  /* 0x8009FF08 */
    R[2] = R[2] + R[3];  /* 0x8009FF0C */
    R[4] = R[4] + R[2];  /* 0x8009FF10 */
    R[4] = R[5] + R[4];  /* 0x8009FF14 */
    { sb_(R[4] + 61, R[9]); psx_next = 0x8009FF6Cu; return; }  /* 0x8009FF18 j extern */
L_8009FF20:;
    R[2] = lw_(R[8] + 48);  /* 0x8009FF20 */
    R[2] = ((int32_t)R[2] < (int32_t)R[7]);  /* 0x8009FF28 */
    psx_next = 0x8009FF2Cu; return;  /* fallthrough */
}

void ev_8009FF2C(void) {
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009FF6C; } }  /* 0x8009FF2C */
    R[3] = lb_(R[8] + 70);  /* 0x8009FF34 */
    R[2] = R[3] << 1;  /* 0x8009FF3C */
    R[2] = R[2] + R[3];  /* 0x8009FF40 */
    R[2] = R[4] + R[2];  /* 0x8009FF44 */
    R[2] = R[8] + R[2];  /* 0x8009FF48 */
    sb_(R[2] + 61, R[9]);  /* 0x8009FF4C */
    R[3] = lb_(R[8] + 70);  /* 0x8009FF50 */
    R[2] = R[3] << 1;  /* 0x8009FF58 */
    R[2] = R[2] + R[3];  /* 0x8009FF5C */
    R[4] = R[4] + R[2];  /* 0x8009FF60 */
    R[4] = R[5] + R[4];  /* 0x8009FF64 */
    sb_(R[4] + 61, R[0]);  /* 0x8009FF68 */
L_8009FF6C:;
    { R[2] = R[0] + R[0]; psx_next = R[31]; return; }  /* 0x8009FF6C jr ra */
}

void ev_8009FF6C(void) {
    { R[2] = R[0] + R[0]; psx_next = R[31]; return; }  /* 0x8009FF6C jr ra */
}

void ev_8009FF74(void) {
    R[29] = R[29] - 48;  /* 0x8009FF74 */
    sw_(R[29] + 32, R[18]);  /* 0x8009FF78 */
    R[18] = R[4] + R[0];  /* 0x8009FF7C */
    sw_(R[29] + 28, R[17]);  /* 0x8009FF80 */
    R[17] = R[5] + R[0];  /* 0x8009FF84 */
    sw_(R[29] + 40, R[31]);  /* 0x8009FF88 */
    sw_(R[29] + 36, R[19]);  /* 0x8009FF8C */
    { R[31] = 0x8009FF98u; sw_(R[29] + 24, R[16]); psx_next = 0x800A0260u; return; }  /* 0x8009FF90 jal */
    R[16] = 0x8001u << 16;  /* 0x8009FF98 */
    R[16] = R[16] | 0x28;  /* 0x8009FF9C */
    R[4] = lw_(R[18] + 44);  /* 0x8009FFA0 */
    { uint32_t _t = R[16]; R[31] = 0x8009FFACu; R[5] = R[2] + R[0]; psx_next = _t; return; }  /* 0x8009FFA4 jalr */
    { R[31] = 0x8009FFB4u; R[19] = R[2] + R[0]; psx_next = 0x800A0260u; return; }  /* 0x8009FFAC jal */
    R[4] = lw_(R[17] + 44);  /* 0x8009FFB4 */
    { uint32_t _t = R[16]; R[31] = 0x8009FFC0u; R[5] = R[2] + R[0]; psx_next = _t; return; }  /* 0x8009FFB8 jalr */
    R[4] = R[18] + R[0];  /* 0x8009FFC0 */
    R[5] = R[17] + R[0];  /* 0x8009FFC4 */
    R[6] = R[19] + R[0];  /* 0x8009FFC8 */
    R[8] = R[0] + 1;  /* 0x8009FFCC */
    R[3] = lb_(R[18] + 70);  /* 0x8009FFD0 */
    R[16] = R[2] + R[0];  /* 0x8009FFD4 */
    R[3] = R[18] + R[3];  /* 0x8009FFD8 */
    sb_(R[3] + 58, R[8]);  /* 0x8009FFDC */
    R[2] = lb_(R[17] + 70);  /* 0x8009FFE0 */
    R[7] = R[16] + R[0];  /* 0x8009FFE4 */
    R[2] = R[17] + R[2];  /* 0x8009FFE8 */
    sb_(R[2] + 58, R[8]);  /* 0x8009FFEC */
    { R[31] = 0x8009FFF8u; sw_(R[29] + 16, R[0]); psx_next = 0x8009FD80u; return; }  /* 0x8009FFF0 jal */
    R[2] = lw_(R[17] + 48);  /* 0x8009FFF8 */
    R[2] = R[2] - R[19];  /* 0x800A0000 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { goto L_800A006C; } }  /* 0x800A0004 */
    R[2] = lw_(R[18] + 48);  /* 0x800A000C */
    R[2] = R[2] - R[16];  /* 0x800A0014 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0018 */
    R[4] = R[18] + R[0];  /* 0x800A0020 */
    R[5] = R[17] + R[0];  /* 0x800A0024 */
    R[6] = R[19] + R[0];  /* 0x800A0028 */
    R[2] = lb_(R[18] + 70);  /* 0x800A002C */
    R[3] = R[0] + 2;  /* 0x800A0030 */
    R[2] = R[18] + R[2];  /* 0x800A0034 */
    sb_(R[2] + 58, R[3]);  /* 0x800A0038 */
    R[2] = lb_(R[17] + 70);  /* 0x800A003C */
    R[7] = R[16] + R[0];  /* 0x800A0040 */
    R[2] = R[17] + R[2];  /* 0x800A0044 */
    sb_(R[2] + 58, R[3]);  /* 0x800A0048 */
    R[2] = R[0] + 1;  /* 0x800A004C */
    { R[31] = 0x800A0058u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A0050 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A0058 */
    R[2] = R[2] - R[19];  /* 0x800A0060 */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[17] + 48, R[2]); if (_c) { goto L_800A0074; } }  /* 0x800A0064 */
L_800A006C:;
    { R[2] = R[0] + 1; goto L_800A0100; }  /* 0x800A006C j */
L_800A0074:;
    R[2] = lw_(R[18] + 48);  /* 0x800A0074 */
    R[2] = R[2] - R[16];  /* 0x800A007C */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0080 */
    R[4] = R[18] + R[0];  /* 0x800A0088 */
    R[5] = R[17] + R[0];  /* 0x800A008C */
    R[6] = R[19] + R[0];  /* 0x800A0090 */
    R[2] = lb_(R[18] + 70);  /* 0x800A0094 */
    R[3] = R[0] + 3;  /* 0x800A0098 */
    R[2] = R[18] + R[2];  /* 0x800A009C */
    sb_(R[2] + 58, R[3]);  /* 0x800A00A0 */
    R[2] = lb_(R[17] + 70);  /* 0x800A00A4 */
    R[7] = R[16] + R[0];  /* 0x800A00A8 */
    R[2] = R[17] + R[2];  /* 0x800A00AC */
    sb_(R[2] + 58, R[3]);  /* 0x800A00B0 */
    R[2] = R[0] + 2;  /* 0x800A00B4 */
    { R[31] = 0x800A00C0u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A00B8 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A00C0 */
    R[2] = R[2] - R[19];  /* 0x800A00C8 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { psx_bb(); goto L_800A006C; } }  /* 0x800A00CC */
    R[2] = lw_(R[18] + 48);  /* 0x800A00D4 */
    R[7] = R[2] - R[16];  /* 0x800A00DC */
    { uint32_t _c = ((int32_t)R[7] < 0); sw_(R[18] + 48, R[7]); if (_c) { goto L_800A00FC; } }  /* 0x800A00E0 */
    R[3] = lw_(R[17] + 48);  /* 0x800A00E8 */
    R[3] = ((int32_t)R[7] < (int32_t)R[3]);  /* 0x800A00F0 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_800A0100; } }  /* 0x800A00F4 */
L_800A00FC:;
    R[2] = R[0] + 2;  /* 0x800A00FC */
L_800A0100:;
    R[31] = lw_(R[29] + 40);  /* 0x800A0100 */
    R[19] = lw_(R[29] + 36);  /* 0x800A0104 */
    R[18] = lw_(R[29] + 32);  /* 0x800A0108 */
    R[17] = lw_(R[29] + 28);  /* 0x800A010C */
    R[16] = lw_(R[29] + 24);  /* 0x800A0110 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A0114 jr ra */
}

void ev_8009FF98(void) {
    R[16] = 0x8001u << 16;  /* 0x8009FF98 */
    R[16] = R[16] | 0x28;  /* 0x8009FF9C */
    R[4] = lw_(R[18] + 44);  /* 0x8009FFA0 */
    { uint32_t _t = R[16]; R[31] = 0x8009FFACu; R[5] = R[2] + R[0]; psx_next = _t; return; }  /* 0x8009FFA4 jalr */
    { R[31] = 0x8009FFB4u; R[19] = R[2] + R[0]; psx_next = 0x800A0260u; return; }  /* 0x8009FFAC jal */
    R[4] = lw_(R[17] + 44);  /* 0x8009FFB4 */
    { uint32_t _t = R[16]; R[31] = 0x8009FFC0u; R[5] = R[2] + R[0]; psx_next = _t; return; }  /* 0x8009FFB8 jalr */
    R[4] = R[18] + R[0];  /* 0x8009FFC0 */
    R[5] = R[17] + R[0];  /* 0x8009FFC4 */
    R[6] = R[19] + R[0];  /* 0x8009FFC8 */
    R[8] = R[0] + 1;  /* 0x8009FFCC */
    R[3] = lb_(R[18] + 70);  /* 0x8009FFD0 */
    R[16] = R[2] + R[0];  /* 0x8009FFD4 */
    R[3] = R[18] + R[3];  /* 0x8009FFD8 */
    sb_(R[3] + 58, R[8]);  /* 0x8009FFDC */
    R[2] = lb_(R[17] + 70);  /* 0x8009FFE0 */
    R[7] = R[16] + R[0];  /* 0x8009FFE4 */
    R[2] = R[17] + R[2];  /* 0x8009FFE8 */
    sb_(R[2] + 58, R[8]);  /* 0x8009FFEC */
    { R[31] = 0x8009FFF8u; sw_(R[29] + 16, R[0]); psx_next = 0x8009FD80u; return; }  /* 0x8009FFF0 jal */
    R[2] = lw_(R[17] + 48);  /* 0x8009FFF8 */
    R[2] = R[2] - R[19];  /* 0x800A0000 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { goto L_800A006C; } }  /* 0x800A0004 */
    R[2] = lw_(R[18] + 48);  /* 0x800A000C */
    R[2] = R[2] - R[16];  /* 0x800A0014 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0018 */
    R[4] = R[18] + R[0];  /* 0x800A0020 */
    R[5] = R[17] + R[0];  /* 0x800A0024 */
    R[6] = R[19] + R[0];  /* 0x800A0028 */
    R[2] = lb_(R[18] + 70);  /* 0x800A002C */
    R[3] = R[0] + 2;  /* 0x800A0030 */
    R[2] = R[18] + R[2];  /* 0x800A0034 */
    sb_(R[2] + 58, R[3]);  /* 0x800A0038 */
    R[2] = lb_(R[17] + 70);  /* 0x800A003C */
    R[7] = R[16] + R[0];  /* 0x800A0040 */
    R[2] = R[17] + R[2];  /* 0x800A0044 */
    sb_(R[2] + 58, R[3]);  /* 0x800A0048 */
    R[2] = R[0] + 1;  /* 0x800A004C */
    { R[31] = 0x800A0058u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A0050 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A0058 */
    R[2] = R[2] - R[19];  /* 0x800A0060 */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[17] + 48, R[2]); if (_c) { goto L_800A0074; } }  /* 0x800A0064 */
L_800A006C:;
    { R[2] = R[0] + 1; goto L_800A0100; }  /* 0x800A006C j */
L_800A0074:;
    R[2] = lw_(R[18] + 48);  /* 0x800A0074 */
    R[2] = R[2] - R[16];  /* 0x800A007C */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0080 */
    R[4] = R[18] + R[0];  /* 0x800A0088 */
    R[5] = R[17] + R[0];  /* 0x800A008C */
    R[6] = R[19] + R[0];  /* 0x800A0090 */
    R[2] = lb_(R[18] + 70);  /* 0x800A0094 */
    R[3] = R[0] + 3;  /* 0x800A0098 */
    R[2] = R[18] + R[2];  /* 0x800A009C */
    sb_(R[2] + 58, R[3]);  /* 0x800A00A0 */
    R[2] = lb_(R[17] + 70);  /* 0x800A00A4 */
    R[7] = R[16] + R[0];  /* 0x800A00A8 */
    R[2] = R[17] + R[2];  /* 0x800A00AC */
    sb_(R[2] + 58, R[3]);  /* 0x800A00B0 */
    R[2] = R[0] + 2;  /* 0x800A00B4 */
    { R[31] = 0x800A00C0u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A00B8 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A00C0 */
    R[2] = R[2] - R[19];  /* 0x800A00C8 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { psx_bb(); goto L_800A006C; } }  /* 0x800A00CC */
    R[2] = lw_(R[18] + 48);  /* 0x800A00D4 */
    R[7] = R[2] - R[16];  /* 0x800A00DC */
    { uint32_t _c = ((int32_t)R[7] < 0); sw_(R[18] + 48, R[7]); if (_c) { goto L_800A00FC; } }  /* 0x800A00E0 */
    R[3] = lw_(R[17] + 48);  /* 0x800A00E8 */
    R[3] = ((int32_t)R[7] < (int32_t)R[3]);  /* 0x800A00F0 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_800A0100; } }  /* 0x800A00F4 */
L_800A00FC:;
    R[2] = R[0] + 2;  /* 0x800A00FC */
L_800A0100:;
    R[31] = lw_(R[29] + 40);  /* 0x800A0100 */
    R[19] = lw_(R[29] + 36);  /* 0x800A0104 */
    R[18] = lw_(R[29] + 32);  /* 0x800A0108 */
    R[17] = lw_(R[29] + 28);  /* 0x800A010C */
    R[16] = lw_(R[29] + 24);  /* 0x800A0110 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A0114 jr ra */
}

void ev_8009FFAC(void) {
    { R[31] = 0x8009FFB4u; R[19] = R[2] + R[0]; psx_next = 0x800A0260u; return; }  /* 0x8009FFAC jal */
    R[4] = lw_(R[17] + 44);  /* 0x8009FFB4 */
    { uint32_t _t = R[16]; R[31] = 0x8009FFC0u; R[5] = R[2] + R[0]; psx_next = _t; return; }  /* 0x8009FFB8 jalr */
    R[4] = R[18] + R[0];  /* 0x8009FFC0 */
    R[5] = R[17] + R[0];  /* 0x8009FFC4 */
    R[6] = R[19] + R[0];  /* 0x8009FFC8 */
    R[8] = R[0] + 1;  /* 0x8009FFCC */
    R[3] = lb_(R[18] + 70);  /* 0x8009FFD0 */
    R[16] = R[2] + R[0];  /* 0x8009FFD4 */
    R[3] = R[18] + R[3];  /* 0x8009FFD8 */
    sb_(R[3] + 58, R[8]);  /* 0x8009FFDC */
    R[2] = lb_(R[17] + 70);  /* 0x8009FFE0 */
    R[7] = R[16] + R[0];  /* 0x8009FFE4 */
    R[2] = R[17] + R[2];  /* 0x8009FFE8 */
    sb_(R[2] + 58, R[8]);  /* 0x8009FFEC */
    { R[31] = 0x8009FFF8u; sw_(R[29] + 16, R[0]); psx_next = 0x8009FD80u; return; }  /* 0x8009FFF0 jal */
    R[2] = lw_(R[17] + 48);  /* 0x8009FFF8 */
    R[2] = R[2] - R[19];  /* 0x800A0000 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { goto L_800A006C; } }  /* 0x800A0004 */
    R[2] = lw_(R[18] + 48);  /* 0x800A000C */
    R[2] = R[2] - R[16];  /* 0x800A0014 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0018 */
    R[4] = R[18] + R[0];  /* 0x800A0020 */
    R[5] = R[17] + R[0];  /* 0x800A0024 */
    R[6] = R[19] + R[0];  /* 0x800A0028 */
    R[2] = lb_(R[18] + 70);  /* 0x800A002C */
    R[3] = R[0] + 2;  /* 0x800A0030 */
    R[2] = R[18] + R[2];  /* 0x800A0034 */
    sb_(R[2] + 58, R[3]);  /* 0x800A0038 */
    R[2] = lb_(R[17] + 70);  /* 0x800A003C */
    R[7] = R[16] + R[0];  /* 0x800A0040 */
    R[2] = R[17] + R[2];  /* 0x800A0044 */
    sb_(R[2] + 58, R[3]);  /* 0x800A0048 */
    R[2] = R[0] + 1;  /* 0x800A004C */
    { R[31] = 0x800A0058u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A0050 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A0058 */
    R[2] = R[2] - R[19];  /* 0x800A0060 */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[17] + 48, R[2]); if (_c) { goto L_800A0074; } }  /* 0x800A0064 */
L_800A006C:;
    { R[2] = R[0] + 1; goto L_800A0100; }  /* 0x800A006C j */
L_800A0074:;
    R[2] = lw_(R[18] + 48);  /* 0x800A0074 */
    R[2] = R[2] - R[16];  /* 0x800A007C */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0080 */
    R[4] = R[18] + R[0];  /* 0x800A0088 */
    R[5] = R[17] + R[0];  /* 0x800A008C */
    R[6] = R[19] + R[0];  /* 0x800A0090 */
    R[2] = lb_(R[18] + 70);  /* 0x800A0094 */
    R[3] = R[0] + 3;  /* 0x800A0098 */
    R[2] = R[18] + R[2];  /* 0x800A009C */
    sb_(R[2] + 58, R[3]);  /* 0x800A00A0 */
    R[2] = lb_(R[17] + 70);  /* 0x800A00A4 */
    R[7] = R[16] + R[0];  /* 0x800A00A8 */
    R[2] = R[17] + R[2];  /* 0x800A00AC */
    sb_(R[2] + 58, R[3]);  /* 0x800A00B0 */
    R[2] = R[0] + 2;  /* 0x800A00B4 */
    { R[31] = 0x800A00C0u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A00B8 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A00C0 */
    R[2] = R[2] - R[19];  /* 0x800A00C8 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { psx_bb(); goto L_800A006C; } }  /* 0x800A00CC */
    R[2] = lw_(R[18] + 48);  /* 0x800A00D4 */
    R[7] = R[2] - R[16];  /* 0x800A00DC */
    { uint32_t _c = ((int32_t)R[7] < 0); sw_(R[18] + 48, R[7]); if (_c) { goto L_800A00FC; } }  /* 0x800A00E0 */
    R[3] = lw_(R[17] + 48);  /* 0x800A00E8 */
    R[3] = ((int32_t)R[7] < (int32_t)R[3]);  /* 0x800A00F0 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_800A0100; } }  /* 0x800A00F4 */
L_800A00FC:;
    R[2] = R[0] + 2;  /* 0x800A00FC */
L_800A0100:;
    R[31] = lw_(R[29] + 40);  /* 0x800A0100 */
    R[19] = lw_(R[29] + 36);  /* 0x800A0104 */
    R[18] = lw_(R[29] + 32);  /* 0x800A0108 */
    R[17] = lw_(R[29] + 28);  /* 0x800A010C */
    R[16] = lw_(R[29] + 24);  /* 0x800A0110 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A0114 jr ra */
}

void ev_8009FFB4(void) {
    R[4] = lw_(R[17] + 44);  /* 0x8009FFB4 */
    { uint32_t _t = R[16]; R[31] = 0x8009FFC0u; R[5] = R[2] + R[0]; psx_next = _t; return; }  /* 0x8009FFB8 jalr */
    R[4] = R[18] + R[0];  /* 0x8009FFC0 */
    R[5] = R[17] + R[0];  /* 0x8009FFC4 */
    R[6] = R[19] + R[0];  /* 0x8009FFC8 */
    R[8] = R[0] + 1;  /* 0x8009FFCC */
    R[3] = lb_(R[18] + 70);  /* 0x8009FFD0 */
    R[16] = R[2] + R[0];  /* 0x8009FFD4 */
    R[3] = R[18] + R[3];  /* 0x8009FFD8 */
    sb_(R[3] + 58, R[8]);  /* 0x8009FFDC */
    R[2] = lb_(R[17] + 70);  /* 0x8009FFE0 */
    R[7] = R[16] + R[0];  /* 0x8009FFE4 */
    R[2] = R[17] + R[2];  /* 0x8009FFE8 */
    sb_(R[2] + 58, R[8]);  /* 0x8009FFEC */
    { R[31] = 0x8009FFF8u; sw_(R[29] + 16, R[0]); psx_next = 0x8009FD80u; return; }  /* 0x8009FFF0 jal */
    R[2] = lw_(R[17] + 48);  /* 0x8009FFF8 */
    R[2] = R[2] - R[19];  /* 0x800A0000 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { goto L_800A006C; } }  /* 0x800A0004 */
    R[2] = lw_(R[18] + 48);  /* 0x800A000C */
    R[2] = R[2] - R[16];  /* 0x800A0014 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0018 */
    R[4] = R[18] + R[0];  /* 0x800A0020 */
    R[5] = R[17] + R[0];  /* 0x800A0024 */
    R[6] = R[19] + R[0];  /* 0x800A0028 */
    R[2] = lb_(R[18] + 70);  /* 0x800A002C */
    R[3] = R[0] + 2;  /* 0x800A0030 */
    R[2] = R[18] + R[2];  /* 0x800A0034 */
    sb_(R[2] + 58, R[3]);  /* 0x800A0038 */
    R[2] = lb_(R[17] + 70);  /* 0x800A003C */
    R[7] = R[16] + R[0];  /* 0x800A0040 */
    R[2] = R[17] + R[2];  /* 0x800A0044 */
    sb_(R[2] + 58, R[3]);  /* 0x800A0048 */
    R[2] = R[0] + 1;  /* 0x800A004C */
    { R[31] = 0x800A0058u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A0050 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A0058 */
    R[2] = R[2] - R[19];  /* 0x800A0060 */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[17] + 48, R[2]); if (_c) { goto L_800A0074; } }  /* 0x800A0064 */
L_800A006C:;
    { R[2] = R[0] + 1; goto L_800A0100; }  /* 0x800A006C j */
L_800A0074:;
    R[2] = lw_(R[18] + 48);  /* 0x800A0074 */
    R[2] = R[2] - R[16];  /* 0x800A007C */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0080 */
    R[4] = R[18] + R[0];  /* 0x800A0088 */
    R[5] = R[17] + R[0];  /* 0x800A008C */
    R[6] = R[19] + R[0];  /* 0x800A0090 */
    R[2] = lb_(R[18] + 70);  /* 0x800A0094 */
    R[3] = R[0] + 3;  /* 0x800A0098 */
    R[2] = R[18] + R[2];  /* 0x800A009C */
    sb_(R[2] + 58, R[3]);  /* 0x800A00A0 */
    R[2] = lb_(R[17] + 70);  /* 0x800A00A4 */
    R[7] = R[16] + R[0];  /* 0x800A00A8 */
    R[2] = R[17] + R[2];  /* 0x800A00AC */
    sb_(R[2] + 58, R[3]);  /* 0x800A00B0 */
    R[2] = R[0] + 2;  /* 0x800A00B4 */
    { R[31] = 0x800A00C0u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A00B8 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A00C0 */
    R[2] = R[2] - R[19];  /* 0x800A00C8 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { psx_bb(); goto L_800A006C; } }  /* 0x800A00CC */
    R[2] = lw_(R[18] + 48);  /* 0x800A00D4 */
    R[7] = R[2] - R[16];  /* 0x800A00DC */
    { uint32_t _c = ((int32_t)R[7] < 0); sw_(R[18] + 48, R[7]); if (_c) { goto L_800A00FC; } }  /* 0x800A00E0 */
    R[3] = lw_(R[17] + 48);  /* 0x800A00E8 */
    R[3] = ((int32_t)R[7] < (int32_t)R[3]);  /* 0x800A00F0 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_800A0100; } }  /* 0x800A00F4 */
L_800A00FC:;
    R[2] = R[0] + 2;  /* 0x800A00FC */
L_800A0100:;
    R[31] = lw_(R[29] + 40);  /* 0x800A0100 */
    R[19] = lw_(R[29] + 36);  /* 0x800A0104 */
    R[18] = lw_(R[29] + 32);  /* 0x800A0108 */
    R[17] = lw_(R[29] + 28);  /* 0x800A010C */
    R[16] = lw_(R[29] + 24);  /* 0x800A0110 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A0114 jr ra */
}

void ev_8009FFC0(void) {
    R[4] = R[18] + R[0];  /* 0x8009FFC0 */
    R[5] = R[17] + R[0];  /* 0x8009FFC4 */
    R[6] = R[19] + R[0];  /* 0x8009FFC8 */
    R[8] = R[0] + 1;  /* 0x8009FFCC */
    R[3] = lb_(R[18] + 70);  /* 0x8009FFD0 */
    R[16] = R[2] + R[0];  /* 0x8009FFD4 */
    R[3] = R[18] + R[3];  /* 0x8009FFD8 */
    sb_(R[3] + 58, R[8]);  /* 0x8009FFDC */
    R[2] = lb_(R[17] + 70);  /* 0x8009FFE0 */
    R[7] = R[16] + R[0];  /* 0x8009FFE4 */
    R[2] = R[17] + R[2];  /* 0x8009FFE8 */
    sb_(R[2] + 58, R[8]);  /* 0x8009FFEC */
    { R[31] = 0x8009FFF8u; sw_(R[29] + 16, R[0]); psx_next = 0x8009FD80u; return; }  /* 0x8009FFF0 jal */
    R[2] = lw_(R[17] + 48);  /* 0x8009FFF8 */
    R[2] = R[2] - R[19];  /* 0x800A0000 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { goto L_800A006C; } }  /* 0x800A0004 */
    R[2] = lw_(R[18] + 48);  /* 0x800A000C */
    R[2] = R[2] - R[16];  /* 0x800A0014 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0018 */
    R[4] = R[18] + R[0];  /* 0x800A0020 */
    R[5] = R[17] + R[0];  /* 0x800A0024 */
    R[6] = R[19] + R[0];  /* 0x800A0028 */
    R[2] = lb_(R[18] + 70);  /* 0x800A002C */
    R[3] = R[0] + 2;  /* 0x800A0030 */
    R[2] = R[18] + R[2];  /* 0x800A0034 */
    sb_(R[2] + 58, R[3]);  /* 0x800A0038 */
    R[2] = lb_(R[17] + 70);  /* 0x800A003C */
    R[7] = R[16] + R[0];  /* 0x800A0040 */
    R[2] = R[17] + R[2];  /* 0x800A0044 */
    sb_(R[2] + 58, R[3]);  /* 0x800A0048 */
    R[2] = R[0] + 1;  /* 0x800A004C */
    { R[31] = 0x800A0058u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A0050 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A0058 */
    R[2] = R[2] - R[19];  /* 0x800A0060 */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[17] + 48, R[2]); if (_c) { goto L_800A0074; } }  /* 0x800A0064 */
L_800A006C:;
    { R[2] = R[0] + 1; goto L_800A0100; }  /* 0x800A006C j */
L_800A0074:;
    R[2] = lw_(R[18] + 48);  /* 0x800A0074 */
    R[2] = R[2] - R[16];  /* 0x800A007C */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0080 */
    R[4] = R[18] + R[0];  /* 0x800A0088 */
    R[5] = R[17] + R[0];  /* 0x800A008C */
    R[6] = R[19] + R[0];  /* 0x800A0090 */
    R[2] = lb_(R[18] + 70);  /* 0x800A0094 */
    R[3] = R[0] + 3;  /* 0x800A0098 */
    R[2] = R[18] + R[2];  /* 0x800A009C */
    sb_(R[2] + 58, R[3]);  /* 0x800A00A0 */
    R[2] = lb_(R[17] + 70);  /* 0x800A00A4 */
    R[7] = R[16] + R[0];  /* 0x800A00A8 */
    R[2] = R[17] + R[2];  /* 0x800A00AC */
    sb_(R[2] + 58, R[3]);  /* 0x800A00B0 */
    R[2] = R[0] + 2;  /* 0x800A00B4 */
    { R[31] = 0x800A00C0u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A00B8 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A00C0 */
    R[2] = R[2] - R[19];  /* 0x800A00C8 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { psx_bb(); goto L_800A006C; } }  /* 0x800A00CC */
    R[2] = lw_(R[18] + 48);  /* 0x800A00D4 */
    R[7] = R[2] - R[16];  /* 0x800A00DC */
    { uint32_t _c = ((int32_t)R[7] < 0); sw_(R[18] + 48, R[7]); if (_c) { goto L_800A00FC; } }  /* 0x800A00E0 */
    R[3] = lw_(R[17] + 48);  /* 0x800A00E8 */
    R[3] = ((int32_t)R[7] < (int32_t)R[3]);  /* 0x800A00F0 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_800A0100; } }  /* 0x800A00F4 */
L_800A00FC:;
    R[2] = R[0] + 2;  /* 0x800A00FC */
L_800A0100:;
    R[31] = lw_(R[29] + 40);  /* 0x800A0100 */
    R[19] = lw_(R[29] + 36);  /* 0x800A0104 */
    R[18] = lw_(R[29] + 32);  /* 0x800A0108 */
    R[17] = lw_(R[29] + 28);  /* 0x800A010C */
    R[16] = lw_(R[29] + 24);  /* 0x800A0110 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A0114 jr ra */
}

void ev_8009FFF8(void) {
    R[2] = lw_(R[17] + 48);  /* 0x8009FFF8 */
    R[2] = R[2] - R[19];  /* 0x800A0000 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { goto L_800A006C; } }  /* 0x800A0004 */
    R[2] = lw_(R[18] + 48);  /* 0x800A000C */
    R[2] = R[2] - R[16];  /* 0x800A0014 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0018 */
    R[4] = R[18] + R[0];  /* 0x800A0020 */
    R[5] = R[17] + R[0];  /* 0x800A0024 */
    R[6] = R[19] + R[0];  /* 0x800A0028 */
    R[2] = lb_(R[18] + 70);  /* 0x800A002C */
    R[3] = R[0] + 2;  /* 0x800A0030 */
    R[2] = R[18] + R[2];  /* 0x800A0034 */
    sb_(R[2] + 58, R[3]);  /* 0x800A0038 */
    R[2] = lb_(R[17] + 70);  /* 0x800A003C */
    R[7] = R[16] + R[0];  /* 0x800A0040 */
    R[2] = R[17] + R[2];  /* 0x800A0044 */
    sb_(R[2] + 58, R[3]);  /* 0x800A0048 */
    R[2] = R[0] + 1;  /* 0x800A004C */
    { R[31] = 0x800A0058u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A0050 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A0058 */
    R[2] = R[2] - R[19];  /* 0x800A0060 */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[17] + 48, R[2]); if (_c) { goto L_800A0074; } }  /* 0x800A0064 */
L_800A006C:;
    { R[2] = R[0] + 1; goto L_800A0100; }  /* 0x800A006C j */
L_800A0074:;
    R[2] = lw_(R[18] + 48);  /* 0x800A0074 */
    R[2] = R[2] - R[16];  /* 0x800A007C */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0080 */
    R[4] = R[18] + R[0];  /* 0x800A0088 */
    R[5] = R[17] + R[0];  /* 0x800A008C */
    R[6] = R[19] + R[0];  /* 0x800A0090 */
    R[2] = lb_(R[18] + 70);  /* 0x800A0094 */
    R[3] = R[0] + 3;  /* 0x800A0098 */
    R[2] = R[18] + R[2];  /* 0x800A009C */
    sb_(R[2] + 58, R[3]);  /* 0x800A00A0 */
    R[2] = lb_(R[17] + 70);  /* 0x800A00A4 */
    R[7] = R[16] + R[0];  /* 0x800A00A8 */
    R[2] = R[17] + R[2];  /* 0x800A00AC */
    sb_(R[2] + 58, R[3]);  /* 0x800A00B0 */
    R[2] = R[0] + 2;  /* 0x800A00B4 */
    { R[31] = 0x800A00C0u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A00B8 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A00C0 */
    R[2] = R[2] - R[19];  /* 0x800A00C8 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { psx_bb(); goto L_800A006C; } }  /* 0x800A00CC */
    R[2] = lw_(R[18] + 48);  /* 0x800A00D4 */
    R[7] = R[2] - R[16];  /* 0x800A00DC */
    { uint32_t _c = ((int32_t)R[7] < 0); sw_(R[18] + 48, R[7]); if (_c) { goto L_800A00FC; } }  /* 0x800A00E0 */
    R[3] = lw_(R[17] + 48);  /* 0x800A00E8 */
    R[3] = ((int32_t)R[7] < (int32_t)R[3]);  /* 0x800A00F0 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_800A0100; } }  /* 0x800A00F4 */
L_800A00FC:;
    R[2] = R[0] + 2;  /* 0x800A00FC */
L_800A0100:;
    R[31] = lw_(R[29] + 40);  /* 0x800A0100 */
    R[19] = lw_(R[29] + 36);  /* 0x800A0104 */
    R[18] = lw_(R[29] + 32);  /* 0x800A0108 */
    R[17] = lw_(R[29] + 28);  /* 0x800A010C */
    R[16] = lw_(R[29] + 24);  /* 0x800A0110 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A0114 jr ra */
}

void ev_800A0014(void) {
    R[2] = R[2] - R[16];  /* 0x800A0014 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0018 */
    R[4] = R[18] + R[0];  /* 0x800A0020 */
    R[5] = R[17] + R[0];  /* 0x800A0024 */
    R[6] = R[19] + R[0];  /* 0x800A0028 */
    R[2] = lb_(R[18] + 70);  /* 0x800A002C */
    R[3] = R[0] + 2;  /* 0x800A0030 */
    R[2] = R[18] + R[2];  /* 0x800A0034 */
    sb_(R[2] + 58, R[3]);  /* 0x800A0038 */
    R[2] = lb_(R[17] + 70);  /* 0x800A003C */
    R[7] = R[16] + R[0];  /* 0x800A0040 */
    R[2] = R[17] + R[2];  /* 0x800A0044 */
    sb_(R[2] + 58, R[3]);  /* 0x800A0048 */
    R[2] = R[0] + 1;  /* 0x800A004C */
    { R[31] = 0x800A0058u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A0050 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A0058 */
    R[2] = R[2] - R[19];  /* 0x800A0060 */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[17] + 48, R[2]); if (_c) { goto L_800A0074; } }  /* 0x800A0064 */
L_800A006C:;
    { R[2] = R[0] + 1; goto L_800A0100; }  /* 0x800A006C j */
L_800A0074:;
    R[2] = lw_(R[18] + 48);  /* 0x800A0074 */
    R[2] = R[2] - R[16];  /* 0x800A007C */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0080 */
    R[4] = R[18] + R[0];  /* 0x800A0088 */
    R[5] = R[17] + R[0];  /* 0x800A008C */
    R[6] = R[19] + R[0];  /* 0x800A0090 */
    R[2] = lb_(R[18] + 70);  /* 0x800A0094 */
    R[3] = R[0] + 3;  /* 0x800A0098 */
    R[2] = R[18] + R[2];  /* 0x800A009C */
    sb_(R[2] + 58, R[3]);  /* 0x800A00A0 */
    R[2] = lb_(R[17] + 70);  /* 0x800A00A4 */
    R[7] = R[16] + R[0];  /* 0x800A00A8 */
    R[2] = R[17] + R[2];  /* 0x800A00AC */
    sb_(R[2] + 58, R[3]);  /* 0x800A00B0 */
    R[2] = R[0] + 2;  /* 0x800A00B4 */
    { R[31] = 0x800A00C0u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A00B8 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A00C0 */
    R[2] = R[2] - R[19];  /* 0x800A00C8 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { psx_bb(); goto L_800A006C; } }  /* 0x800A00CC */
    R[2] = lw_(R[18] + 48);  /* 0x800A00D4 */
    R[7] = R[2] - R[16];  /* 0x800A00DC */
    { uint32_t _c = ((int32_t)R[7] < 0); sw_(R[18] + 48, R[7]); if (_c) { goto L_800A00FC; } }  /* 0x800A00E0 */
    R[3] = lw_(R[17] + 48);  /* 0x800A00E8 */
    R[3] = ((int32_t)R[7] < (int32_t)R[3]);  /* 0x800A00F0 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_800A0100; } }  /* 0x800A00F4 */
L_800A00FC:;
    R[2] = R[0] + 2;  /* 0x800A00FC */
L_800A0100:;
    R[31] = lw_(R[29] + 40);  /* 0x800A0100 */
    R[19] = lw_(R[29] + 36);  /* 0x800A0104 */
    R[18] = lw_(R[29] + 32);  /* 0x800A0108 */
    R[17] = lw_(R[29] + 28);  /* 0x800A010C */
    R[16] = lw_(R[29] + 24);  /* 0x800A0110 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A0114 jr ra */
}

void ev_800A0018(void) {
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0018 */
    R[4] = R[18] + R[0];  /* 0x800A0020 */
    R[5] = R[17] + R[0];  /* 0x800A0024 */
    R[6] = R[19] + R[0];  /* 0x800A0028 */
    R[2] = lb_(R[18] + 70);  /* 0x800A002C */
    R[3] = R[0] + 2;  /* 0x800A0030 */
    R[2] = R[18] + R[2];  /* 0x800A0034 */
    sb_(R[2] + 58, R[3]);  /* 0x800A0038 */
    R[2] = lb_(R[17] + 70);  /* 0x800A003C */
    R[7] = R[16] + R[0];  /* 0x800A0040 */
    R[2] = R[17] + R[2];  /* 0x800A0044 */
    sb_(R[2] + 58, R[3]);  /* 0x800A0048 */
    R[2] = R[0] + 1;  /* 0x800A004C */
    { R[31] = 0x800A0058u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A0050 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A0058 */
    R[2] = R[2] - R[19];  /* 0x800A0060 */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[17] + 48, R[2]); if (_c) { goto L_800A0074; } }  /* 0x800A0064 */
L_800A006C:;
    { R[2] = R[0] + 1; goto L_800A0100; }  /* 0x800A006C j */
L_800A0074:;
    R[2] = lw_(R[18] + 48);  /* 0x800A0074 */
    R[2] = R[2] - R[16];  /* 0x800A007C */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0080 */
    R[4] = R[18] + R[0];  /* 0x800A0088 */
    R[5] = R[17] + R[0];  /* 0x800A008C */
    R[6] = R[19] + R[0];  /* 0x800A0090 */
    R[2] = lb_(R[18] + 70);  /* 0x800A0094 */
    R[3] = R[0] + 3;  /* 0x800A0098 */
    R[2] = R[18] + R[2];  /* 0x800A009C */
    sb_(R[2] + 58, R[3]);  /* 0x800A00A0 */
    R[2] = lb_(R[17] + 70);  /* 0x800A00A4 */
    R[7] = R[16] + R[0];  /* 0x800A00A8 */
    R[2] = R[17] + R[2];  /* 0x800A00AC */
    sb_(R[2] + 58, R[3]);  /* 0x800A00B0 */
    R[2] = R[0] + 2;  /* 0x800A00B4 */
    { R[31] = 0x800A00C0u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A00B8 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A00C0 */
    R[2] = R[2] - R[19];  /* 0x800A00C8 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { psx_bb(); goto L_800A006C; } }  /* 0x800A00CC */
    R[2] = lw_(R[18] + 48);  /* 0x800A00D4 */
    R[7] = R[2] - R[16];  /* 0x800A00DC */
    { uint32_t _c = ((int32_t)R[7] < 0); sw_(R[18] + 48, R[7]); if (_c) { goto L_800A00FC; } }  /* 0x800A00E0 */
    R[3] = lw_(R[17] + 48);  /* 0x800A00E8 */
    R[3] = ((int32_t)R[7] < (int32_t)R[3]);  /* 0x800A00F0 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_800A0100; } }  /* 0x800A00F4 */
L_800A00FC:;
    R[2] = R[0] + 2;  /* 0x800A00FC */
L_800A0100:;
    R[31] = lw_(R[29] + 40);  /* 0x800A0100 */
    R[19] = lw_(R[29] + 36);  /* 0x800A0104 */
    R[18] = lw_(R[29] + 32);  /* 0x800A0108 */
    R[17] = lw_(R[29] + 28);  /* 0x800A010C */
    R[16] = lw_(R[29] + 24);  /* 0x800A0110 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A0114 jr ra */
}

void ev_800A0020(void) {
    R[4] = R[18] + R[0];  /* 0x800A0020 */
    R[5] = R[17] + R[0];  /* 0x800A0024 */
    R[6] = R[19] + R[0];  /* 0x800A0028 */
    R[2] = lb_(R[18] + 70);  /* 0x800A002C */
    R[3] = R[0] + 2;  /* 0x800A0030 */
    R[2] = R[18] + R[2];  /* 0x800A0034 */
    sb_(R[2] + 58, R[3]);  /* 0x800A0038 */
    R[2] = lb_(R[17] + 70);  /* 0x800A003C */
    R[7] = R[16] + R[0];  /* 0x800A0040 */
    R[2] = R[17] + R[2];  /* 0x800A0044 */
    sb_(R[2] + 58, R[3]);  /* 0x800A0048 */
    R[2] = R[0] + 1;  /* 0x800A004C */
    { R[31] = 0x800A0058u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A0050 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A0058 */
    R[2] = R[2] - R[19];  /* 0x800A0060 */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[17] + 48, R[2]); if (_c) { goto L_800A0074; } }  /* 0x800A0064 */
L_800A006C:;
    { R[2] = R[0] + 1; goto L_800A0100; }  /* 0x800A006C j */
L_800A0074:;
    R[2] = lw_(R[18] + 48);  /* 0x800A0074 */
    R[2] = R[2] - R[16];  /* 0x800A007C */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0080 */
    R[4] = R[18] + R[0];  /* 0x800A0088 */
    R[5] = R[17] + R[0];  /* 0x800A008C */
    R[6] = R[19] + R[0];  /* 0x800A0090 */
    R[2] = lb_(R[18] + 70);  /* 0x800A0094 */
    R[3] = R[0] + 3;  /* 0x800A0098 */
    R[2] = R[18] + R[2];  /* 0x800A009C */
    sb_(R[2] + 58, R[3]);  /* 0x800A00A0 */
    R[2] = lb_(R[17] + 70);  /* 0x800A00A4 */
    R[7] = R[16] + R[0];  /* 0x800A00A8 */
    R[2] = R[17] + R[2];  /* 0x800A00AC */
    sb_(R[2] + 58, R[3]);  /* 0x800A00B0 */
    R[2] = R[0] + 2;  /* 0x800A00B4 */
    { R[31] = 0x800A00C0u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A00B8 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A00C0 */
    R[2] = R[2] - R[19];  /* 0x800A00C8 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { psx_bb(); goto L_800A006C; } }  /* 0x800A00CC */
    R[2] = lw_(R[18] + 48);  /* 0x800A00D4 */
    R[7] = R[2] - R[16];  /* 0x800A00DC */
    { uint32_t _c = ((int32_t)R[7] < 0); sw_(R[18] + 48, R[7]); if (_c) { goto L_800A00FC; } }  /* 0x800A00E0 */
    R[3] = lw_(R[17] + 48);  /* 0x800A00E8 */
    R[3] = ((int32_t)R[7] < (int32_t)R[3]);  /* 0x800A00F0 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_800A0100; } }  /* 0x800A00F4 */
L_800A00FC:;
    R[2] = R[0] + 2;  /* 0x800A00FC */
L_800A0100:;
    R[31] = lw_(R[29] + 40);  /* 0x800A0100 */
    R[19] = lw_(R[29] + 36);  /* 0x800A0104 */
    R[18] = lw_(R[29] + 32);  /* 0x800A0108 */
    R[17] = lw_(R[29] + 28);  /* 0x800A010C */
    R[16] = lw_(R[29] + 24);  /* 0x800A0110 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A0114 jr ra */
}

void ev_800A0050(void) {
    { R[31] = 0x800A0058u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A0050 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A0058 */
    R[2] = R[2] - R[19];  /* 0x800A0060 */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[17] + 48, R[2]); if (_c) { goto L_800A0074; } }  /* 0x800A0064 */
L_800A006C:;
    { R[2] = R[0] + 1; goto L_800A0100; }  /* 0x800A006C j */
L_800A0074:;
    R[2] = lw_(R[18] + 48);  /* 0x800A0074 */
    R[2] = R[2] - R[16];  /* 0x800A007C */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0080 */
    R[4] = R[18] + R[0];  /* 0x800A0088 */
    R[5] = R[17] + R[0];  /* 0x800A008C */
    R[6] = R[19] + R[0];  /* 0x800A0090 */
    R[2] = lb_(R[18] + 70);  /* 0x800A0094 */
    R[3] = R[0] + 3;  /* 0x800A0098 */
    R[2] = R[18] + R[2];  /* 0x800A009C */
    sb_(R[2] + 58, R[3]);  /* 0x800A00A0 */
    R[2] = lb_(R[17] + 70);  /* 0x800A00A4 */
    R[7] = R[16] + R[0];  /* 0x800A00A8 */
    R[2] = R[17] + R[2];  /* 0x800A00AC */
    sb_(R[2] + 58, R[3]);  /* 0x800A00B0 */
    R[2] = R[0] + 2;  /* 0x800A00B4 */
    { R[31] = 0x800A00C0u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A00B8 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A00C0 */
    R[2] = R[2] - R[19];  /* 0x800A00C8 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { psx_bb(); goto L_800A006C; } }  /* 0x800A00CC */
    R[2] = lw_(R[18] + 48);  /* 0x800A00D4 */
    R[7] = R[2] - R[16];  /* 0x800A00DC */
    { uint32_t _c = ((int32_t)R[7] < 0); sw_(R[18] + 48, R[7]); if (_c) { goto L_800A00FC; } }  /* 0x800A00E0 */
    R[3] = lw_(R[17] + 48);  /* 0x800A00E8 */
    R[3] = ((int32_t)R[7] < (int32_t)R[3]);  /* 0x800A00F0 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_800A0100; } }  /* 0x800A00F4 */
L_800A00FC:;
    R[2] = R[0] + 2;  /* 0x800A00FC */
L_800A0100:;
    R[31] = lw_(R[29] + 40);  /* 0x800A0100 */
    R[19] = lw_(R[29] + 36);  /* 0x800A0104 */
    R[18] = lw_(R[29] + 32);  /* 0x800A0108 */
    R[17] = lw_(R[29] + 28);  /* 0x800A010C */
    R[16] = lw_(R[29] + 24);  /* 0x800A0110 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A0114 jr ra */
}

void ev_800A0058(void) {
    R[2] = lw_(R[17] + 48);  /* 0x800A0058 */
    R[2] = R[2] - R[19];  /* 0x800A0060 */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[17] + 48, R[2]); if (_c) { goto L_800A0074; } }  /* 0x800A0064 */
L_800A006C:;
    { R[2] = R[0] + 1; goto L_800A0100; }  /* 0x800A006C j */
L_800A0074:;
    R[2] = lw_(R[18] + 48);  /* 0x800A0074 */
    R[2] = R[2] - R[16];  /* 0x800A007C */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0080 */
    R[4] = R[18] + R[0];  /* 0x800A0088 */
    R[5] = R[17] + R[0];  /* 0x800A008C */
    R[6] = R[19] + R[0];  /* 0x800A0090 */
    R[2] = lb_(R[18] + 70);  /* 0x800A0094 */
    R[3] = R[0] + 3;  /* 0x800A0098 */
    R[2] = R[18] + R[2];  /* 0x800A009C */
    sb_(R[2] + 58, R[3]);  /* 0x800A00A0 */
    R[2] = lb_(R[17] + 70);  /* 0x800A00A4 */
    R[7] = R[16] + R[0];  /* 0x800A00A8 */
    R[2] = R[17] + R[2];  /* 0x800A00AC */
    sb_(R[2] + 58, R[3]);  /* 0x800A00B0 */
    R[2] = R[0] + 2;  /* 0x800A00B4 */
    { R[31] = 0x800A00C0u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A00B8 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A00C0 */
    R[2] = R[2] - R[19];  /* 0x800A00C8 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { psx_bb(); goto L_800A006C; } }  /* 0x800A00CC */
    R[2] = lw_(R[18] + 48);  /* 0x800A00D4 */
    R[7] = R[2] - R[16];  /* 0x800A00DC */
    { uint32_t _c = ((int32_t)R[7] < 0); sw_(R[18] + 48, R[7]); if (_c) { goto L_800A00FC; } }  /* 0x800A00E0 */
    R[3] = lw_(R[17] + 48);  /* 0x800A00E8 */
    R[3] = ((int32_t)R[7] < (int32_t)R[3]);  /* 0x800A00F0 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_800A0100; } }  /* 0x800A00F4 */
L_800A00FC:;
    R[2] = R[0] + 2;  /* 0x800A00FC */
L_800A0100:;
    R[31] = lw_(R[29] + 40);  /* 0x800A0100 */
    R[19] = lw_(R[29] + 36);  /* 0x800A0104 */
    R[18] = lw_(R[29] + 32);  /* 0x800A0108 */
    R[17] = lw_(R[29] + 28);  /* 0x800A010C */
    R[16] = lw_(R[29] + 24);  /* 0x800A0110 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A0114 jr ra */
}

void ev_800A006C(void) {
L_800A006C:;
    { R[2] = R[0] + 1; goto L_800A0100; }  /* 0x800A006C j */
    R[2] = lw_(R[18] + 48);  /* 0x800A0074 */
    R[2] = R[2] - R[16];  /* 0x800A007C */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[18] + 48, R[2]); if (_c) { goto L_800A00FC; } }  /* 0x800A0080 */
    R[4] = R[18] + R[0];  /* 0x800A0088 */
    R[5] = R[17] + R[0];  /* 0x800A008C */
    R[6] = R[19] + R[0];  /* 0x800A0090 */
    R[2] = lb_(R[18] + 70);  /* 0x800A0094 */
    R[3] = R[0] + 3;  /* 0x800A0098 */
    R[2] = R[18] + R[2];  /* 0x800A009C */
    sb_(R[2] + 58, R[3]);  /* 0x800A00A0 */
    R[2] = lb_(R[17] + 70);  /* 0x800A00A4 */
    R[7] = R[16] + R[0];  /* 0x800A00A8 */
    R[2] = R[17] + R[2];  /* 0x800A00AC */
    sb_(R[2] + 58, R[3]);  /* 0x800A00B0 */
    R[2] = R[0] + 2;  /* 0x800A00B4 */
    { R[31] = 0x800A00C0u; sw_(R[29] + 16, R[2]); psx_next = 0x8009FD80u; return; }  /* 0x800A00B8 jal */
    R[2] = lw_(R[17] + 48);  /* 0x800A00C0 */
    R[2] = R[2] - R[19];  /* 0x800A00C8 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { psx_bb(); goto L_800A006C; } }  /* 0x800A00CC */
    R[2] = lw_(R[18] + 48);  /* 0x800A00D4 */
    R[7] = R[2] - R[16];  /* 0x800A00DC */
    { uint32_t _c = ((int32_t)R[7] < 0); sw_(R[18] + 48, R[7]); if (_c) { goto L_800A00FC; } }  /* 0x800A00E0 */
    R[3] = lw_(R[17] + 48);  /* 0x800A00E8 */
    R[3] = ((int32_t)R[7] < (int32_t)R[3]);  /* 0x800A00F0 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_800A0100; } }  /* 0x800A00F4 */
L_800A00FC:;
    R[2] = R[0] + 2;  /* 0x800A00FC */
L_800A0100:;
    R[31] = lw_(R[29] + 40);  /* 0x800A0100 */
    R[19] = lw_(R[29] + 36);  /* 0x800A0104 */
    R[18] = lw_(R[29] + 32);  /* 0x800A0108 */
    R[17] = lw_(R[29] + 28);  /* 0x800A010C */
    R[16] = lw_(R[29] + 24);  /* 0x800A0110 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A0114 jr ra */
}

void ev_800A00C0(void) {
    R[2] = lw_(R[17] + 48);  /* 0x800A00C0 */
    R[2] = R[2] - R[19];  /* 0x800A00C8 */
    { uint32_t _c = ((int32_t)R[2] < 0); sw_(R[17] + 48, R[2]); if (_c) { psx_next = 0x800A006Cu; return; } }  /* 0x800A00CC b extern */
    R[2] = lw_(R[18] + 48);  /* 0x800A00D4 */
    R[7] = R[2] - R[16];  /* 0x800A00DC */
    { uint32_t _c = ((int32_t)R[7] < 0); sw_(R[18] + 48, R[7]); if (_c) { goto L_800A00FC; } }  /* 0x800A00E0 */
    R[3] = lw_(R[17] + 48);  /* 0x800A00E8 */
    R[3] = ((int32_t)R[7] < (int32_t)R[3]);  /* 0x800A00F0 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_800A0100; } }  /* 0x800A00F4 */
L_800A00FC:;
    R[2] = R[0] + 2;  /* 0x800A00FC */
L_800A0100:;
    R[31] = lw_(R[29] + 40);  /* 0x800A0100 */
    R[19] = lw_(R[29] + 36);  /* 0x800A0104 */
    R[18] = lw_(R[29] + 32);  /* 0x800A0108 */
    R[17] = lw_(R[29] + 28);  /* 0x800A010C */
    R[16] = lw_(R[29] + 24);  /* 0x800A0110 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A0114 jr ra */
}

void ev_800A011C(void) {
    R[29] = R[29] - 40;  /* 0x800A011C */
    sw_(R[29] + 24, R[18]);  /* 0x800A0120 */
    R[18] = R[4] + R[0];  /* 0x800A0124 */
    sw_(R[29] + 28, R[19]);  /* 0x800A0128 */
    R[19] = R[5] + R[0];  /* 0x800A012C */
    sw_(R[29] + 32, R[31]);  /* 0x800A0130 */
    sw_(R[29] + 20, R[17]);  /* 0x800A0134 */
    { R[31] = 0x800A0140u; sw_(R[29] + 16, R[16]); psx_next = 0x800A0260u; return; }  /* 0x800A0138 jal */
    R[17] = 0x8001u << 16;  /* 0x800A0140 */
    R[17] = R[17] | 0x28;  /* 0x800A0144 */
    R[4] = lw_(R[18] + 52);  /* 0x800A0148 */
    { uint32_t _t = R[17]; R[31] = 0x800A0154u; R[5] = R[2] + R[0]; psx_next = _t; return; }  /* 0x800A014C jalr */
    { R[31] = 0x800A015Cu; R[16] = R[2] + R[0]; psx_next = 0x800A0260u; return; }  /* 0x800A0154 jal */
    R[4] = lw_(R[19] + 52);  /* 0x800A015C */
    { uint32_t _t = R[17]; R[31] = 0x800A0168u; R[5] = R[2] + R[0]; psx_next = _t; return; }  /* 0x800A0160 jalr */
    R[16] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800A0168 */
    { uint32_t _c = (R[16] != R[0]); R[4] = R[19] + R[0]; if (_c) { goto L_800A01C0; } }  /* 0x800A016C */
    R[4] = R[18] + R[0];  /* 0x800A0174 */
    { R[31] = 0x800A0180u; R[5] = R[19] + R[0]; psx_next = 0x8009FF74u; return; }  /* 0x800A0178 jal */
    R[3] = R[2] + R[0];  /* 0x800A0180 */
    R[2] = R[0] + 1;  /* 0x800A0184 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_800A01A4; } }  /* 0x800A0188 */
    R[2] = lb_(R[18] + 71);  /* 0x800A0190 */
    R[2] = R[2] + 1;  /* 0x800A0198 */
    sb_(R[18] + 71, R[2]);  /* 0x800A019C */
    R[2] = R[0] + 2;  /* 0x800A01A0 */
L_800A01A4:;
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800A0204; } }  /* 0x800A01A4 */
    R[2] = lb_(R[19] + 71);  /* 0x800A01AC */
    R[2] = R[2] + 1;  /* 0x800A01B4 */
    { sb_(R[19] + 71, R[2]); goto L_800A0204; }  /* 0x800A01B8 j */
L_800A01C0:;
    { R[31] = 0x800A01C8u; R[5] = R[18] + R[0]; psx_next = 0x8009FF74u; return; }  /* 0x800A01C0 jal */
    R[3] = R[2] + R[0];  /* 0x800A01C8 */
    R[2] = R[0] + 1;  /* 0x800A01CC */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_800A01EC; } }  /* 0x800A01D0 */
    R[2] = lb_(R[19] + 71);  /* 0x800A01D8 */
    R[2] = R[2] + 1;  /* 0x800A01E0 */
    sb_(R[19] + 71, R[2]);  /* 0x800A01E4 */
    R[2] = R[0] + 2;  /* 0x800A01E8 */
L_800A01EC:;
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800A0204; } }  /* 0x800A01EC */
    R[2] = lb_(R[18] + 71);  /* 0x800A01F4 */
    R[2] = R[2] + 1;  /* 0x800A01FC */
    sb_(R[18] + 71, R[2]);  /* 0x800A0200 */
L_800A0204:;
    R[31] = lw_(R[29] + 32);  /* 0x800A0204 */
    R[19] = lw_(R[29] + 28);  /* 0x800A0208 */
    R[18] = lw_(R[29] + 24);  /* 0x800A020C */
    R[17] = lw_(R[29] + 20);  /* 0x800A0210 */
    R[16] = lw_(R[29] + 16);  /* 0x800A0214 */
    R[2] = R[0] + R[0];  /* 0x800A0218 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A021C jr ra */
}

void ev_800A0140(void) {
    R[17] = 0x8001u << 16;  /* 0x800A0140 */
    R[17] = R[17] | 0x28;  /* 0x800A0144 */
    R[4] = lw_(R[18] + 52);  /* 0x800A0148 */
    { uint32_t _t = R[17]; R[31] = 0x800A0154u; R[5] = R[2] + R[0]; psx_next = _t; return; }  /* 0x800A014C jalr */
    { R[31] = 0x800A015Cu; R[16] = R[2] + R[0]; psx_next = 0x800A0260u; return; }  /* 0x800A0154 jal */
    R[4] = lw_(R[19] + 52);  /* 0x800A015C */
    { uint32_t _t = R[17]; R[31] = 0x800A0168u; R[5] = R[2] + R[0]; psx_next = _t; return; }  /* 0x800A0160 jalr */
    R[16] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800A0168 */
    { uint32_t _c = (R[16] != R[0]); R[4] = R[19] + R[0]; if (_c) { goto L_800A01C0; } }  /* 0x800A016C */
    R[4] = R[18] + R[0];  /* 0x800A0174 */
    { R[31] = 0x800A0180u; R[5] = R[19] + R[0]; psx_next = 0x8009FF74u; return; }  /* 0x800A0178 jal */
    R[3] = R[2] + R[0];  /* 0x800A0180 */
    R[2] = R[0] + 1;  /* 0x800A0184 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_800A01A4; } }  /* 0x800A0188 */
    R[2] = lb_(R[18] + 71);  /* 0x800A0190 */
    R[2] = R[2] + 1;  /* 0x800A0198 */
    sb_(R[18] + 71, R[2]);  /* 0x800A019C */
    R[2] = R[0] + 2;  /* 0x800A01A0 */
L_800A01A4:;
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800A0204; } }  /* 0x800A01A4 */
    R[2] = lb_(R[19] + 71);  /* 0x800A01AC */
    R[2] = R[2] + 1;  /* 0x800A01B4 */
    { sb_(R[19] + 71, R[2]); goto L_800A0204; }  /* 0x800A01B8 j */
L_800A01C0:;
    { R[31] = 0x800A01C8u; R[5] = R[18] + R[0]; psx_next = 0x8009FF74u; return; }  /* 0x800A01C0 jal */
    R[3] = R[2] + R[0];  /* 0x800A01C8 */
    R[2] = R[0] + 1;  /* 0x800A01CC */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_800A01EC; } }  /* 0x800A01D0 */
    R[2] = lb_(R[19] + 71);  /* 0x800A01D8 */
    R[2] = R[2] + 1;  /* 0x800A01E0 */
    sb_(R[19] + 71, R[2]);  /* 0x800A01E4 */
    R[2] = R[0] + 2;  /* 0x800A01E8 */
L_800A01EC:;
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800A0204; } }  /* 0x800A01EC */
    R[2] = lb_(R[18] + 71);  /* 0x800A01F4 */
    R[2] = R[2] + 1;  /* 0x800A01FC */
    sb_(R[18] + 71, R[2]);  /* 0x800A0200 */
L_800A0204:;
    R[31] = lw_(R[29] + 32);  /* 0x800A0204 */
    R[19] = lw_(R[29] + 28);  /* 0x800A0208 */
    R[18] = lw_(R[29] + 24);  /* 0x800A020C */
    R[17] = lw_(R[29] + 20);  /* 0x800A0210 */
    R[16] = lw_(R[29] + 16);  /* 0x800A0214 */
    R[2] = R[0] + R[0];  /* 0x800A0218 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A021C jr ra */
}

void ev_800A0154(void) {
    { R[31] = 0x800A015Cu; R[16] = R[2] + R[0]; psx_next = 0x800A0260u; return; }  /* 0x800A0154 jal */
    R[4] = lw_(R[19] + 52);  /* 0x800A015C */
    { uint32_t _t = R[17]; R[31] = 0x800A0168u; R[5] = R[2] + R[0]; psx_next = _t; return; }  /* 0x800A0160 jalr */
    R[16] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800A0168 */
    { uint32_t _c = (R[16] != R[0]); R[4] = R[19] + R[0]; if (_c) { goto L_800A01C0; } }  /* 0x800A016C */
    R[4] = R[18] + R[0];  /* 0x800A0174 */
    { R[31] = 0x800A0180u; R[5] = R[19] + R[0]; psx_next = 0x8009FF74u; return; }  /* 0x800A0178 jal */
    R[3] = R[2] + R[0];  /* 0x800A0180 */
    R[2] = R[0] + 1;  /* 0x800A0184 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_800A01A4; } }  /* 0x800A0188 */
    R[2] = lb_(R[18] + 71);  /* 0x800A0190 */
    R[2] = R[2] + 1;  /* 0x800A0198 */
    sb_(R[18] + 71, R[2]);  /* 0x800A019C */
    R[2] = R[0] + 2;  /* 0x800A01A0 */
L_800A01A4:;
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800A0204; } }  /* 0x800A01A4 */
    R[2] = lb_(R[19] + 71);  /* 0x800A01AC */
    R[2] = R[2] + 1;  /* 0x800A01B4 */
    { sb_(R[19] + 71, R[2]); goto L_800A0204; }  /* 0x800A01B8 j */
L_800A01C0:;
    { R[31] = 0x800A01C8u; R[5] = R[18] + R[0]; psx_next = 0x8009FF74u; return; }  /* 0x800A01C0 jal */
    R[3] = R[2] + R[0];  /* 0x800A01C8 */
    R[2] = R[0] + 1;  /* 0x800A01CC */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_800A01EC; } }  /* 0x800A01D0 */
    R[2] = lb_(R[19] + 71);  /* 0x800A01D8 */
    R[2] = R[2] + 1;  /* 0x800A01E0 */
    sb_(R[19] + 71, R[2]);  /* 0x800A01E4 */
    R[2] = R[0] + 2;  /* 0x800A01E8 */
L_800A01EC:;
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800A0204; } }  /* 0x800A01EC */
    R[2] = lb_(R[18] + 71);  /* 0x800A01F4 */
    R[2] = R[2] + 1;  /* 0x800A01FC */
    sb_(R[18] + 71, R[2]);  /* 0x800A0200 */
L_800A0204:;
    R[31] = lw_(R[29] + 32);  /* 0x800A0204 */
    R[19] = lw_(R[29] + 28);  /* 0x800A0208 */
    R[18] = lw_(R[29] + 24);  /* 0x800A020C */
    R[17] = lw_(R[29] + 20);  /* 0x800A0210 */
    R[16] = lw_(R[29] + 16);  /* 0x800A0214 */
    R[2] = R[0] + R[0];  /* 0x800A0218 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A021C jr ra */
}

void ev_800A015C(void) {
    R[4] = lw_(R[19] + 52);  /* 0x800A015C */
    { uint32_t _t = R[17]; R[31] = 0x800A0168u; R[5] = R[2] + R[0]; psx_next = _t; return; }  /* 0x800A0160 jalr */
    R[16] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800A0168 */
    { uint32_t _c = (R[16] != R[0]); R[4] = R[19] + R[0]; if (_c) { goto L_800A01C0; } }  /* 0x800A016C */
    R[4] = R[18] + R[0];  /* 0x800A0174 */
    { R[31] = 0x800A0180u; R[5] = R[19] + R[0]; psx_next = 0x8009FF74u; return; }  /* 0x800A0178 jal */
    R[3] = R[2] + R[0];  /* 0x800A0180 */
    R[2] = R[0] + 1;  /* 0x800A0184 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_800A01A4; } }  /* 0x800A0188 */
    R[2] = lb_(R[18] + 71);  /* 0x800A0190 */
    R[2] = R[2] + 1;  /* 0x800A0198 */
    sb_(R[18] + 71, R[2]);  /* 0x800A019C */
    R[2] = R[0] + 2;  /* 0x800A01A0 */
L_800A01A4:;
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800A0204; } }  /* 0x800A01A4 */
    R[2] = lb_(R[19] + 71);  /* 0x800A01AC */
    R[2] = R[2] + 1;  /* 0x800A01B4 */
    { sb_(R[19] + 71, R[2]); goto L_800A0204; }  /* 0x800A01B8 j */
L_800A01C0:;
    { R[31] = 0x800A01C8u; R[5] = R[18] + R[0]; psx_next = 0x8009FF74u; return; }  /* 0x800A01C0 jal */
    R[3] = R[2] + R[0];  /* 0x800A01C8 */
    R[2] = R[0] + 1;  /* 0x800A01CC */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_800A01EC; } }  /* 0x800A01D0 */
    R[2] = lb_(R[19] + 71);  /* 0x800A01D8 */
    R[2] = R[2] + 1;  /* 0x800A01E0 */
    sb_(R[19] + 71, R[2]);  /* 0x800A01E4 */
    R[2] = R[0] + 2;  /* 0x800A01E8 */
L_800A01EC:;
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800A0204; } }  /* 0x800A01EC */
    R[2] = lb_(R[18] + 71);  /* 0x800A01F4 */
    R[2] = R[2] + 1;  /* 0x800A01FC */
    sb_(R[18] + 71, R[2]);  /* 0x800A0200 */
L_800A0204:;
    R[31] = lw_(R[29] + 32);  /* 0x800A0204 */
    R[19] = lw_(R[29] + 28);  /* 0x800A0208 */
    R[18] = lw_(R[29] + 24);  /* 0x800A020C */
    R[17] = lw_(R[29] + 20);  /* 0x800A0210 */
    R[16] = lw_(R[29] + 16);  /* 0x800A0214 */
    R[2] = R[0] + R[0];  /* 0x800A0218 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A021C jr ra */
}

void ev_800A0168(void) {
    R[16] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800A0168 */
    { uint32_t _c = (R[16] != R[0]); R[4] = R[19] + R[0]; if (_c) { goto L_800A01C0; } }  /* 0x800A016C */
    R[4] = R[18] + R[0];  /* 0x800A0174 */
    { R[31] = 0x800A0180u; R[5] = R[19] + R[0]; psx_next = 0x8009FF74u; return; }  /* 0x800A0178 jal */
    R[3] = R[2] + R[0];  /* 0x800A0180 */
    R[2] = R[0] + 1;  /* 0x800A0184 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_800A01A4; } }  /* 0x800A0188 */
    R[2] = lb_(R[18] + 71);  /* 0x800A0190 */
    R[2] = R[2] + 1;  /* 0x800A0198 */
    sb_(R[18] + 71, R[2]);  /* 0x800A019C */
    R[2] = R[0] + 2;  /* 0x800A01A0 */
L_800A01A4:;
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800A0204; } }  /* 0x800A01A4 */
    R[2] = lb_(R[19] + 71);  /* 0x800A01AC */
    R[2] = R[2] + 1;  /* 0x800A01B4 */
    { sb_(R[19] + 71, R[2]); goto L_800A0204; }  /* 0x800A01B8 j */
L_800A01C0:;
    { R[31] = 0x800A01C8u; R[5] = R[18] + R[0]; psx_next = 0x8009FF74u; return; }  /* 0x800A01C0 jal */
    R[3] = R[2] + R[0];  /* 0x800A01C8 */
    R[2] = R[0] + 1;  /* 0x800A01CC */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_800A01EC; } }  /* 0x800A01D0 */
    R[2] = lb_(R[19] + 71);  /* 0x800A01D8 */
    R[2] = R[2] + 1;  /* 0x800A01E0 */
    sb_(R[19] + 71, R[2]);  /* 0x800A01E4 */
    R[2] = R[0] + 2;  /* 0x800A01E8 */
L_800A01EC:;
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800A0204; } }  /* 0x800A01EC */
    R[2] = lb_(R[18] + 71);  /* 0x800A01F4 */
    R[2] = R[2] + 1;  /* 0x800A01FC */
    sb_(R[18] + 71, R[2]);  /* 0x800A0200 */
L_800A0204:;
    R[31] = lw_(R[29] + 32);  /* 0x800A0204 */
    R[19] = lw_(R[29] + 28);  /* 0x800A0208 */
    R[18] = lw_(R[29] + 24);  /* 0x800A020C */
    R[17] = lw_(R[29] + 20);  /* 0x800A0210 */
    R[16] = lw_(R[29] + 16);  /* 0x800A0214 */
    R[2] = R[0] + R[0];  /* 0x800A0218 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A021C jr ra */
}

void ev_800A0180(void) {
    R[3] = R[2] + R[0];  /* 0x800A0180 */
    R[2] = R[0] + 1;  /* 0x800A0184 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_800A01A4; } }  /* 0x800A0188 */
    R[2] = lb_(R[18] + 71);  /* 0x800A0190 */
    R[2] = R[2] + 1;  /* 0x800A0198 */
    sb_(R[18] + 71, R[2]);  /* 0x800A019C */
    R[2] = R[0] + 2;  /* 0x800A01A0 */
L_800A01A4:;
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800A0204; } }  /* 0x800A01A4 */
    R[2] = lb_(R[19] + 71);  /* 0x800A01AC */
    R[2] = R[2] + 1;  /* 0x800A01B4 */
    { sb_(R[19] + 71, R[2]); goto L_800A0204; }  /* 0x800A01B8 j */
    { R[31] = 0x800A01C8u; R[5] = R[18] + R[0]; psx_next = 0x8009FF74u; return; }  /* 0x800A01C0 jal */
    R[3] = R[2] + R[0];  /* 0x800A01C8 */
    R[2] = R[0] + 1;  /* 0x800A01CC */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_800A01EC; } }  /* 0x800A01D0 */
    R[2] = lb_(R[19] + 71);  /* 0x800A01D8 */
    R[2] = R[2] + 1;  /* 0x800A01E0 */
    sb_(R[19] + 71, R[2]);  /* 0x800A01E4 */
    R[2] = R[0] + 2;  /* 0x800A01E8 */
L_800A01EC:;
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800A0204; } }  /* 0x800A01EC */
    R[2] = lb_(R[18] + 71);  /* 0x800A01F4 */
    R[2] = R[2] + 1;  /* 0x800A01FC */
    sb_(R[18] + 71, R[2]);  /* 0x800A0200 */
L_800A0204:;
    R[31] = lw_(R[29] + 32);  /* 0x800A0204 */
    R[19] = lw_(R[29] + 28);  /* 0x800A0208 */
    R[18] = lw_(R[29] + 24);  /* 0x800A020C */
    R[17] = lw_(R[29] + 20);  /* 0x800A0210 */
    R[16] = lw_(R[29] + 16);  /* 0x800A0214 */
    R[2] = R[0] + R[0];  /* 0x800A0218 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A021C jr ra */
}

void ev_800A01C8(void) {
    R[3] = R[2] + R[0];  /* 0x800A01C8 */
    R[2] = R[0] + 1;  /* 0x800A01CC */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_800A01EC; } }  /* 0x800A01D0 */
    R[2] = lb_(R[19] + 71);  /* 0x800A01D8 */
    R[2] = R[2] + 1;  /* 0x800A01E0 */
    sb_(R[19] + 71, R[2]);  /* 0x800A01E4 */
    R[2] = R[0] + 2;  /* 0x800A01E8 */
L_800A01EC:;
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800A0204; } }  /* 0x800A01EC */
    R[2] = lb_(R[18] + 71);  /* 0x800A01F4 */
    R[2] = R[2] + 1;  /* 0x800A01FC */
    sb_(R[18] + 71, R[2]);  /* 0x800A0200 */
L_800A0204:;
    R[31] = lw_(R[29] + 32);  /* 0x800A0204 */
    R[19] = lw_(R[29] + 28);  /* 0x800A0208 */
    R[18] = lw_(R[29] + 24);  /* 0x800A020C */
    R[17] = lw_(R[29] + 20);  /* 0x800A0210 */
    R[16] = lw_(R[29] + 16);  /* 0x800A0214 */
    R[2] = R[0] + R[0];  /* 0x800A0218 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A021C jr ra */
}

void ev_800A0224(void) {
    R[29] = R[29] - 32;  /* 0x800A0224 */
    sw_(R[29] + 16, R[16]);  /* 0x800A0228 */
    R[16] = R[4] + R[0];  /* 0x800A022C */
    sw_(R[29] + 20, R[17]);  /* 0x800A0230 */
    sw_(R[29] + 24, R[31]);  /* 0x800A0234 */
    { R[31] = 0x800A0240u; R[17] = R[5] + R[0]; psx_next = 0x8009FC70u; return; }  /* 0x800A0238 jal */
    R[4] = R[16] + R[0];  /* 0x800A0240 */
    { R[31] = 0x800A024Cu; R[5] = R[17] + R[0]; psx_next = 0x800A011Cu; return; }  /* 0x800A0244 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800A024C */
    R[17] = lw_(R[29] + 20);  /* 0x800A0250 */
    R[16] = lw_(R[29] + 16);  /* 0x800A0254 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800A0258 jr ra */
}

void ev_800A0240(void) {
    R[4] = R[16] + R[0];  /* 0x800A0240 */
    { R[31] = 0x800A024Cu; R[5] = R[17] + R[0]; psx_next = 0x800A011Cu; return; }  /* 0x800A0244 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800A024C */
    R[17] = lw_(R[29] + 20);  /* 0x800A0250 */
    R[16] = lw_(R[29] + 16);  /* 0x800A0254 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800A0258 jr ra */
}

void ev_800A024C(void) {
    R[31] = lw_(R[29] + 24);  /* 0x800A024C */
    R[17] = lw_(R[29] + 20);  /* 0x800A0250 */
    R[16] = lw_(R[29] + 16);  /* 0x800A0254 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800A0258 jr ra */
}

void ev_800A0260(void) {
    R[29] = R[29] - 24;  /* 0x800A0260 */
    sw_(R[29] + 16, R[31]);  /* 0x800A0264 */
    { R[31] = 0x800A0270u; psx_next = 0x80030E88u; return; }  /* 0x800A0268 jal */
    R[3] = R[2] + R[0];  /* 0x800A0270 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_800A0284; } }  /* 0x800A0274 */
    R[2] = R[3] + 4095;  /* 0x800A027C */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800A0280 */
L_800A0284:;
    R[2] = R[2] << 12;  /* 0x800A0284 */
    R[31] = lw_(R[29] + 16);  /* 0x800A0288 */
    R[2] = R[3] - R[2];  /* 0x800A028C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A0290 jr ra */
}

void ev_800A0270(void) {
    R[3] = R[2] + R[0];  /* 0x800A0270 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_800A0284; } }  /* 0x800A0274 */
    R[2] = R[3] + 4095;  /* 0x800A027C */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800A0280 */
L_800A0284:;
    R[2] = R[2] << 12;  /* 0x800A0284 */
    R[31] = lw_(R[29] + 16);  /* 0x800A0288 */
    R[2] = R[3] - R[2];  /* 0x800A028C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A0290 jr ra */
}

void ev_800A0298(void) {
    R[29] = R[29] - 72;  /* 0x800A0298 */
    R[4] = R[0] + R[0];  /* 0x800A029C */
    sw_(R[29] + 40, R[18]);  /* 0x800A02A0 */
    R[18] = 0x800Bu << 16;  /* 0x800A02A4 */
    R[18] = R[18] + 10840;  /* 0x800A02A8 */
    R[5] = R[18] + R[0];  /* 0x800A02AC */
    sw_(R[29] + 36, R[17]);  /* 0x800A02B0 */
    R[17] = 0x800Bu << 16;  /* 0x800A02B4 */
    R[17] = R[17] + 9412;  /* 0x800A02B8 */
    R[6] = R[17] + R[0];  /* 0x800A02BC */
    R[7] = 0x800Fu << 16;  /* 0x800A02C0 */
    R[7] = R[7] + 27920;  /* 0x800A02C4 */
    sw_(R[29] + 68, R[31]);  /* 0x800A02C8 */
    sw_(R[29] + 64, R[30]);  /* 0x800A02CC */
    sw_(R[29] + 60, R[23]);  /* 0x800A02D0 */
    sw_(R[29] + 56, R[22]);  /* 0x800A02D4 */
    sw_(R[29] + 52, R[21]);  /* 0x800A02D8 */
    sw_(R[29] + 48, R[20]);  /* 0x800A02DC */
    sw_(R[29] + 44, R[19]);  /* 0x800A02E0 */
    sw_(R[29] + 32, R[16]);  /* 0x800A02E4 */
    { R[31] = 0x800A02F0u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A02E8 jal */
    R[4] = R[0] + 6;  /* 0x800A02F0 */
    R[5] = R[18] + R[0];  /* 0x800A02F4 */
    R[6] = R[17] + R[0];  /* 0x800A02F8 */
    R[16] = 0x800Fu << 16;  /* 0x800A02FC */
    R[16] = R[16] - 6208;  /* 0x800A0300 */
    R[7] = R[16] + R[0];  /* 0x800A0304 */
    { R[31] = 0x800A0310u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0308 jal */
    R[4] = R[0] + 1;  /* 0x800A0310 */
    R[5] = R[18] + R[0];  /* 0x800A0314 */
    R[6] = R[17] + R[0];  /* 0x800A0318 */
    R[7] = R[16] + 44;  /* 0x800A031C */
    { R[31] = 0x800A0328u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0320 jal */
    R[4] = R[0] + 16;  /* 0x800A0328 */
    R[5] = R[18] + R[0];  /* 0x800A032C */
    R[6] = R[17] + R[0];  /* 0x800A0330 */
    R[7] = R[16] + 88;  /* 0x800A0334 */
    { R[31] = 0x800A0340u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0338 jal */
    R[4] = R[0] + 9;  /* 0x800A0340 */
    R[5] = R[18] + R[0];  /* 0x800A0344 */
    R[6] = R[17] + R[0];  /* 0x800A0348 */
    R[7] = R[16] + 132;  /* 0x800A034C */
    { R[31] = 0x800A0358u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0350 jal */
    R[4] = R[0] + 10;  /* 0x800A0358 */
    R[5] = R[18] + R[0];  /* 0x800A035C */
    R[6] = R[17] + R[0];  /* 0x800A0360 */
    R[7] = R[16] + 176;  /* 0x800A0364 */
    { R[31] = 0x800A0370u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0368 jal */
    R[4] = R[0] + 8;  /* 0x800A0370 */
    R[5] = R[18] + R[0];  /* 0x800A0374 */
    R[6] = R[17] + R[0];  /* 0x800A0378 */
    R[7] = R[16] + 220;  /* 0x800A037C */
    R[2] = R[0] + 1;  /* 0x800A0380 */
    { R[31] = 0x800A038Cu; sw_(R[29] + 16, R[2]); psx_next = 0x8009A380u; return; }  /* 0x800A0384 jal */
    R[4] = R[0] + 2;  /* 0x800A038C */
    R[5] = R[18] + R[0];  /* 0x800A0390 */
    R[6] = R[17] + R[0];  /* 0x800A0394 */
    R[7] = R[16] + 264;  /* 0x800A0398 */
    { R[31] = 0x800A03A4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A039C jal */
    R[4] = R[0] + 17;  /* 0x800A03A4 */
    R[5] = R[18] + R[0];  /* 0x800A03A8 */
    R[6] = R[17] + R[0];  /* 0x800A03AC */
    R[7] = R[16] + 308;  /* 0x800A03B0 */
    { R[31] = 0x800A03BCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03B4 jal */
    R[4] = R[0] + 11;  /* 0x800A03BC */
    R[5] = R[18] + R[0];  /* 0x800A03C0 */
    R[6] = R[17] + R[0];  /* 0x800A03C4 */
    R[7] = R[16] + 352;  /* 0x800A03C8 */
    { R[31] = 0x800A03D4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03CC jal */
    R[4] = R[0] + 3;  /* 0x800A03D4 */
    R[5] = R[18] + R[0];  /* 0x800A03D8 */
    R[6] = R[17] + R[0];  /* 0x800A03DC */
    R[7] = R[16] + 396;  /* 0x800A03E0 */
    { R[31] = 0x800A03ECu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03E4 jal */
}

void ev_800A02F0(void) {
    R[4] = R[0] + 6;  /* 0x800A02F0 */
    R[5] = R[18] + R[0];  /* 0x800A02F4 */
    R[6] = R[17] + R[0];  /* 0x800A02F8 */
    R[16] = 0x800Fu << 16;  /* 0x800A02FC */
    R[16] = R[16] - 6208;  /* 0x800A0300 */
    R[7] = R[16] + R[0];  /* 0x800A0304 */
    { R[31] = 0x800A0310u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0308 jal */
    R[4] = R[0] + 1;  /* 0x800A0310 */
    R[5] = R[18] + R[0];  /* 0x800A0314 */
    R[6] = R[17] + R[0];  /* 0x800A0318 */
    R[7] = R[16] + 44;  /* 0x800A031C */
    { R[31] = 0x800A0328u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0320 jal */
    R[4] = R[0] + 16;  /* 0x800A0328 */
    R[5] = R[18] + R[0];  /* 0x800A032C */
    R[6] = R[17] + R[0];  /* 0x800A0330 */
    R[7] = R[16] + 88;  /* 0x800A0334 */
    { R[31] = 0x800A0340u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0338 jal */
    R[4] = R[0] + 9;  /* 0x800A0340 */
    R[5] = R[18] + R[0];  /* 0x800A0344 */
    R[6] = R[17] + R[0];  /* 0x800A0348 */
    R[7] = R[16] + 132;  /* 0x800A034C */
    { R[31] = 0x800A0358u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0350 jal */
    R[4] = R[0] + 10;  /* 0x800A0358 */
    R[5] = R[18] + R[0];  /* 0x800A035C */
    R[6] = R[17] + R[0];  /* 0x800A0360 */
    R[7] = R[16] + 176;  /* 0x800A0364 */
    { R[31] = 0x800A0370u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0368 jal */
    R[4] = R[0] + 8;  /* 0x800A0370 */
    R[5] = R[18] + R[0];  /* 0x800A0374 */
    R[6] = R[17] + R[0];  /* 0x800A0378 */
    R[7] = R[16] + 220;  /* 0x800A037C */
    R[2] = R[0] + 1;  /* 0x800A0380 */
    { R[31] = 0x800A038Cu; sw_(R[29] + 16, R[2]); psx_next = 0x8009A380u; return; }  /* 0x800A0384 jal */
    R[4] = R[0] + 2;  /* 0x800A038C */
    R[5] = R[18] + R[0];  /* 0x800A0390 */
    R[6] = R[17] + R[0];  /* 0x800A0394 */
    R[7] = R[16] + 264;  /* 0x800A0398 */
    { R[31] = 0x800A03A4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A039C jal */
    R[4] = R[0] + 17;  /* 0x800A03A4 */
    R[5] = R[18] + R[0];  /* 0x800A03A8 */
    R[6] = R[17] + R[0];  /* 0x800A03AC */
    R[7] = R[16] + 308;  /* 0x800A03B0 */
    { R[31] = 0x800A03BCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03B4 jal */
    R[4] = R[0] + 11;  /* 0x800A03BC */
    R[5] = R[18] + R[0];  /* 0x800A03C0 */
    R[6] = R[17] + R[0];  /* 0x800A03C4 */
    R[7] = R[16] + 352;  /* 0x800A03C8 */
    { R[31] = 0x800A03D4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03CC jal */
    R[4] = R[0] + 3;  /* 0x800A03D4 */
    R[5] = R[18] + R[0];  /* 0x800A03D8 */
    R[6] = R[17] + R[0];  /* 0x800A03DC */
    R[7] = R[16] + 396;  /* 0x800A03E0 */
    { R[31] = 0x800A03ECu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03E4 jal */
}

void ev_800A0310(void) {
    R[4] = R[0] + 1;  /* 0x800A0310 */
    R[5] = R[18] + R[0];  /* 0x800A0314 */
    R[6] = R[17] + R[0];  /* 0x800A0318 */
    R[7] = R[16] + 44;  /* 0x800A031C */
    { R[31] = 0x800A0328u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0320 jal */
    R[4] = R[0] + 16;  /* 0x800A0328 */
    R[5] = R[18] + R[0];  /* 0x800A032C */
    R[6] = R[17] + R[0];  /* 0x800A0330 */
    R[7] = R[16] + 88;  /* 0x800A0334 */
    { R[31] = 0x800A0340u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0338 jal */
    R[4] = R[0] + 9;  /* 0x800A0340 */
    R[5] = R[18] + R[0];  /* 0x800A0344 */
    R[6] = R[17] + R[0];  /* 0x800A0348 */
    R[7] = R[16] + 132;  /* 0x800A034C */
    { R[31] = 0x800A0358u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0350 jal */
    R[4] = R[0] + 10;  /* 0x800A0358 */
    R[5] = R[18] + R[0];  /* 0x800A035C */
    R[6] = R[17] + R[0];  /* 0x800A0360 */
    R[7] = R[16] + 176;  /* 0x800A0364 */
    { R[31] = 0x800A0370u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0368 jal */
    R[4] = R[0] + 8;  /* 0x800A0370 */
    R[5] = R[18] + R[0];  /* 0x800A0374 */
    R[6] = R[17] + R[0];  /* 0x800A0378 */
    R[7] = R[16] + 220;  /* 0x800A037C */
    R[2] = R[0] + 1;  /* 0x800A0380 */
    { R[31] = 0x800A038Cu; sw_(R[29] + 16, R[2]); psx_next = 0x8009A380u; return; }  /* 0x800A0384 jal */
    R[4] = R[0] + 2;  /* 0x800A038C */
    R[5] = R[18] + R[0];  /* 0x800A0390 */
    R[6] = R[17] + R[0];  /* 0x800A0394 */
    R[7] = R[16] + 264;  /* 0x800A0398 */
    { R[31] = 0x800A03A4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A039C jal */
    R[4] = R[0] + 17;  /* 0x800A03A4 */
    R[5] = R[18] + R[0];  /* 0x800A03A8 */
    R[6] = R[17] + R[0];  /* 0x800A03AC */
    R[7] = R[16] + 308;  /* 0x800A03B0 */
    { R[31] = 0x800A03BCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03B4 jal */
    R[4] = R[0] + 11;  /* 0x800A03BC */
    R[5] = R[18] + R[0];  /* 0x800A03C0 */
    R[6] = R[17] + R[0];  /* 0x800A03C4 */
    R[7] = R[16] + 352;  /* 0x800A03C8 */
    { R[31] = 0x800A03D4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03CC jal */
    R[4] = R[0] + 3;  /* 0x800A03D4 */
    R[5] = R[18] + R[0];  /* 0x800A03D8 */
    R[6] = R[17] + R[0];  /* 0x800A03DC */
    R[7] = R[16] + 396;  /* 0x800A03E0 */
    { R[31] = 0x800A03ECu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03E4 jal */
}

void ev_800A0328(void) {
    R[4] = R[0] + 16;  /* 0x800A0328 */
    R[5] = R[18] + R[0];  /* 0x800A032C */
    R[6] = R[17] + R[0];  /* 0x800A0330 */
    R[7] = R[16] + 88;  /* 0x800A0334 */
    { R[31] = 0x800A0340u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0338 jal */
    R[4] = R[0] + 9;  /* 0x800A0340 */
    R[5] = R[18] + R[0];  /* 0x800A0344 */
    R[6] = R[17] + R[0];  /* 0x800A0348 */
    R[7] = R[16] + 132;  /* 0x800A034C */
    { R[31] = 0x800A0358u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0350 jal */
    R[4] = R[0] + 10;  /* 0x800A0358 */
    R[5] = R[18] + R[0];  /* 0x800A035C */
    R[6] = R[17] + R[0];  /* 0x800A0360 */
    R[7] = R[16] + 176;  /* 0x800A0364 */
    { R[31] = 0x800A0370u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0368 jal */
    R[4] = R[0] + 8;  /* 0x800A0370 */
    R[5] = R[18] + R[0];  /* 0x800A0374 */
    R[6] = R[17] + R[0];  /* 0x800A0378 */
    R[7] = R[16] + 220;  /* 0x800A037C */
    R[2] = R[0] + 1;  /* 0x800A0380 */
    { R[31] = 0x800A038Cu; sw_(R[29] + 16, R[2]); psx_next = 0x8009A380u; return; }  /* 0x800A0384 jal */
    R[4] = R[0] + 2;  /* 0x800A038C */
    R[5] = R[18] + R[0];  /* 0x800A0390 */
    R[6] = R[17] + R[0];  /* 0x800A0394 */
    R[7] = R[16] + 264;  /* 0x800A0398 */
    { R[31] = 0x800A03A4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A039C jal */
    R[4] = R[0] + 17;  /* 0x800A03A4 */
    R[5] = R[18] + R[0];  /* 0x800A03A8 */
    R[6] = R[17] + R[0];  /* 0x800A03AC */
    R[7] = R[16] + 308;  /* 0x800A03B0 */
    { R[31] = 0x800A03BCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03B4 jal */
    R[4] = R[0] + 11;  /* 0x800A03BC */
    R[5] = R[18] + R[0];  /* 0x800A03C0 */
    R[6] = R[17] + R[0];  /* 0x800A03C4 */
    R[7] = R[16] + 352;  /* 0x800A03C8 */
    { R[31] = 0x800A03D4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03CC jal */
    R[4] = R[0] + 3;  /* 0x800A03D4 */
    R[5] = R[18] + R[0];  /* 0x800A03D8 */
    R[6] = R[17] + R[0];  /* 0x800A03DC */
    R[7] = R[16] + 396;  /* 0x800A03E0 */
    { R[31] = 0x800A03ECu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03E4 jal */
}

void ev_800A0340(void) {
    R[4] = R[0] + 9;  /* 0x800A0340 */
    R[5] = R[18] + R[0];  /* 0x800A0344 */
    R[6] = R[17] + R[0];  /* 0x800A0348 */
    R[7] = R[16] + 132;  /* 0x800A034C */
    { R[31] = 0x800A0358u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0350 jal */
    R[4] = R[0] + 10;  /* 0x800A0358 */
    R[5] = R[18] + R[0];  /* 0x800A035C */
    R[6] = R[17] + R[0];  /* 0x800A0360 */
    R[7] = R[16] + 176;  /* 0x800A0364 */
    { R[31] = 0x800A0370u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0368 jal */
    R[4] = R[0] + 8;  /* 0x800A0370 */
    R[5] = R[18] + R[0];  /* 0x800A0374 */
    R[6] = R[17] + R[0];  /* 0x800A0378 */
    R[7] = R[16] + 220;  /* 0x800A037C */
    R[2] = R[0] + 1;  /* 0x800A0380 */
    { R[31] = 0x800A038Cu; sw_(R[29] + 16, R[2]); psx_next = 0x8009A380u; return; }  /* 0x800A0384 jal */
    R[4] = R[0] + 2;  /* 0x800A038C */
    R[5] = R[18] + R[0];  /* 0x800A0390 */
    R[6] = R[17] + R[0];  /* 0x800A0394 */
    R[7] = R[16] + 264;  /* 0x800A0398 */
    { R[31] = 0x800A03A4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A039C jal */
    R[4] = R[0] + 17;  /* 0x800A03A4 */
    R[5] = R[18] + R[0];  /* 0x800A03A8 */
    R[6] = R[17] + R[0];  /* 0x800A03AC */
    R[7] = R[16] + 308;  /* 0x800A03B0 */
    { R[31] = 0x800A03BCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03B4 jal */
    R[4] = R[0] + 11;  /* 0x800A03BC */
    R[5] = R[18] + R[0];  /* 0x800A03C0 */
    R[6] = R[17] + R[0];  /* 0x800A03C4 */
    R[7] = R[16] + 352;  /* 0x800A03C8 */
    { R[31] = 0x800A03D4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03CC jal */
    R[4] = R[0] + 3;  /* 0x800A03D4 */
    R[5] = R[18] + R[0];  /* 0x800A03D8 */
    R[6] = R[17] + R[0];  /* 0x800A03DC */
    R[7] = R[16] + 396;  /* 0x800A03E0 */
    { R[31] = 0x800A03ECu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03E4 jal */
}

void ev_800A0358(void) {
    R[4] = R[0] + 10;  /* 0x800A0358 */
    R[5] = R[18] + R[0];  /* 0x800A035C */
    R[6] = R[17] + R[0];  /* 0x800A0360 */
    R[7] = R[16] + 176;  /* 0x800A0364 */
    { R[31] = 0x800A0370u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0368 jal */
    R[4] = R[0] + 8;  /* 0x800A0370 */
    R[5] = R[18] + R[0];  /* 0x800A0374 */
    R[6] = R[17] + R[0];  /* 0x800A0378 */
    R[7] = R[16] + 220;  /* 0x800A037C */
    R[2] = R[0] + 1;  /* 0x800A0380 */
    { R[31] = 0x800A038Cu; sw_(R[29] + 16, R[2]); psx_next = 0x8009A380u; return; }  /* 0x800A0384 jal */
    R[4] = R[0] + 2;  /* 0x800A038C */
    R[5] = R[18] + R[0];  /* 0x800A0390 */
    R[6] = R[17] + R[0];  /* 0x800A0394 */
    R[7] = R[16] + 264;  /* 0x800A0398 */
    { R[31] = 0x800A03A4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A039C jal */
    R[4] = R[0] + 17;  /* 0x800A03A4 */
    R[5] = R[18] + R[0];  /* 0x800A03A8 */
    R[6] = R[17] + R[0];  /* 0x800A03AC */
    R[7] = R[16] + 308;  /* 0x800A03B0 */
    { R[31] = 0x800A03BCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03B4 jal */
    R[4] = R[0] + 11;  /* 0x800A03BC */
    R[5] = R[18] + R[0];  /* 0x800A03C0 */
    R[6] = R[17] + R[0];  /* 0x800A03C4 */
    R[7] = R[16] + 352;  /* 0x800A03C8 */
    { R[31] = 0x800A03D4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03CC jal */
    R[4] = R[0] + 3;  /* 0x800A03D4 */
    R[5] = R[18] + R[0];  /* 0x800A03D8 */
    R[6] = R[17] + R[0];  /* 0x800A03DC */
    R[7] = R[16] + 396;  /* 0x800A03E0 */
    { R[31] = 0x800A03ECu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03E4 jal */
}

void ev_800A0370(void) {
    R[4] = R[0] + 8;  /* 0x800A0370 */
    R[5] = R[18] + R[0];  /* 0x800A0374 */
    R[6] = R[17] + R[0];  /* 0x800A0378 */
    R[7] = R[16] + 220;  /* 0x800A037C */
    R[2] = R[0] + 1;  /* 0x800A0380 */
    { R[31] = 0x800A038Cu; sw_(R[29] + 16, R[2]); psx_next = 0x8009A380u; return; }  /* 0x800A0384 jal */
    R[4] = R[0] + 2;  /* 0x800A038C */
    R[5] = R[18] + R[0];  /* 0x800A0390 */
    R[6] = R[17] + R[0];  /* 0x800A0394 */
    R[7] = R[16] + 264;  /* 0x800A0398 */
    { R[31] = 0x800A03A4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A039C jal */
    R[4] = R[0] + 17;  /* 0x800A03A4 */
    R[5] = R[18] + R[0];  /* 0x800A03A8 */
    R[6] = R[17] + R[0];  /* 0x800A03AC */
    R[7] = R[16] + 308;  /* 0x800A03B0 */
    { R[31] = 0x800A03BCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03B4 jal */
    R[4] = R[0] + 11;  /* 0x800A03BC */
    R[5] = R[18] + R[0];  /* 0x800A03C0 */
    R[6] = R[17] + R[0];  /* 0x800A03C4 */
    R[7] = R[16] + 352;  /* 0x800A03C8 */
    { R[31] = 0x800A03D4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03CC jal */
    R[4] = R[0] + 3;  /* 0x800A03D4 */
    R[5] = R[18] + R[0];  /* 0x800A03D8 */
    R[6] = R[17] + R[0];  /* 0x800A03DC */
    R[7] = R[16] + 396;  /* 0x800A03E0 */
    { R[31] = 0x800A03ECu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03E4 jal */
}

void ev_800A038C(void) {
    R[4] = R[0] + 2;  /* 0x800A038C */
    R[5] = R[18] + R[0];  /* 0x800A0390 */
    R[6] = R[17] + R[0];  /* 0x800A0394 */
    R[7] = R[16] + 264;  /* 0x800A0398 */
    { R[31] = 0x800A03A4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A039C jal */
    R[4] = R[0] + 17;  /* 0x800A03A4 */
    R[5] = R[18] + R[0];  /* 0x800A03A8 */
    R[6] = R[17] + R[0];  /* 0x800A03AC */
    R[7] = R[16] + 308;  /* 0x800A03B0 */
    { R[31] = 0x800A03BCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03B4 jal */
    R[4] = R[0] + 11;  /* 0x800A03BC */
    R[5] = R[18] + R[0];  /* 0x800A03C0 */
    R[6] = R[17] + R[0];  /* 0x800A03C4 */
    R[7] = R[16] + 352;  /* 0x800A03C8 */
    { R[31] = 0x800A03D4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03CC jal */
    R[4] = R[0] + 3;  /* 0x800A03D4 */
    R[5] = R[18] + R[0];  /* 0x800A03D8 */
    R[6] = R[17] + R[0];  /* 0x800A03DC */
    R[7] = R[16] + 396;  /* 0x800A03E0 */
    { R[31] = 0x800A03ECu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03E4 jal */
}

void ev_800A03A4(void) {
    R[4] = R[0] + 17;  /* 0x800A03A4 */
    R[5] = R[18] + R[0];  /* 0x800A03A8 */
    R[6] = R[17] + R[0];  /* 0x800A03AC */
    R[7] = R[16] + 308;  /* 0x800A03B0 */
    { R[31] = 0x800A03BCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03B4 jal */
    R[4] = R[0] + 11;  /* 0x800A03BC */
    R[5] = R[18] + R[0];  /* 0x800A03C0 */
    R[6] = R[17] + R[0];  /* 0x800A03C4 */
    R[7] = R[16] + 352;  /* 0x800A03C8 */
    { R[31] = 0x800A03D4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03CC jal */
    R[4] = R[0] + 3;  /* 0x800A03D4 */
    R[5] = R[18] + R[0];  /* 0x800A03D8 */
    R[6] = R[17] + R[0];  /* 0x800A03DC */
    R[7] = R[16] + 396;  /* 0x800A03E0 */
    { R[31] = 0x800A03ECu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03E4 jal */
}

void ev_800A03BC(void) {
    R[4] = R[0] + 11;  /* 0x800A03BC */
    R[5] = R[18] + R[0];  /* 0x800A03C0 */
    R[6] = R[17] + R[0];  /* 0x800A03C4 */
    R[7] = R[16] + 352;  /* 0x800A03C8 */
    { R[31] = 0x800A03D4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03CC jal */
    R[4] = R[0] + 3;  /* 0x800A03D4 */
    R[5] = R[18] + R[0];  /* 0x800A03D8 */
    R[6] = R[17] + R[0];  /* 0x800A03DC */
    R[7] = R[16] + 396;  /* 0x800A03E0 */
    { R[31] = 0x800A03ECu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03E4 jal */
}

void ev_800A03D4(void) {
    R[4] = R[0] + 3;  /* 0x800A03D4 */
    R[5] = R[18] + R[0];  /* 0x800A03D8 */
    R[6] = R[17] + R[0];  /* 0x800A03DC */
    R[7] = R[16] + 396;  /* 0x800A03E0 */
    { R[31] = 0x800A03ECu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03E4 jal */
}

void ev_800A03E8(void) {
    sw_(R[29] + 16, R[0]);  /* 0x800A03E8 */
    R[4] = R[0] + 18;  /* 0x800A03EC */
    R[5] = R[18] + R[0];  /* 0x800A03F0 */
    R[6] = R[17] + R[0];  /* 0x800A03F4 */
    R[7] = R[16] + 440;  /* 0x800A03F8 */
    { R[31] = 0x800A0404u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03FC jal */
    R[4] = R[0] + 12;  /* 0x800A0404 */
    R[5] = R[18] + R[0];  /* 0x800A0408 */
    R[6] = R[17] + R[0];  /* 0x800A040C */
    R[7] = R[16] + 484;  /* 0x800A0410 */
    { R[31] = 0x800A041Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0414 jal */
    R[4] = R[0] + 7;  /* 0x800A041C */
    R[5] = R[18] + R[0];  /* 0x800A0420 */
    R[6] = R[17] + R[0];  /* 0x800A0424 */
    R[7] = R[16] + 528;  /* 0x800A0428 */
    { R[31] = 0x800A0434u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A042C jal */
    R[4] = R[0] + 13;  /* 0x800A0434 */
    R[5] = R[18] + R[0];  /* 0x800A0438 */
    R[6] = R[17] + R[0];  /* 0x800A043C */
    R[7] = R[16] + 660;  /* 0x800A0440 */
    { R[31] = 0x800A044Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0444 jal */
    R[4] = R[0] + 111;  /* 0x800A044C */
    R[5] = R[18] + R[0];  /* 0x800A0450 */
    R[6] = R[17] + R[0];  /* 0x800A0454 */
    R[7] = R[16] + 572;  /* 0x800A0458 */
    { R[31] = 0x800A0464u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A045C jal */
    R[4] = R[0] + 112;  /* 0x800A0464 */
    R[5] = R[18] + R[0];  /* 0x800A0468 */
    R[6] = R[17] + R[0];  /* 0x800A046C */
    R[7] = R[16] + 616;  /* 0x800A0470 */
    { R[31] = 0x800A047Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0474 jal */
    R[4] = R[0] + 6;  /* 0x800A047C */
    R[5] = R[18] + R[0];  /* 0x800A0480 */
    R[6] = R[17] + R[0];  /* 0x800A0484 */
    R[7] = R[16] + 704;  /* 0x800A0488 */
    { R[31] = 0x800A0494u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A048C jal */
    R[4] = R[0] + 21;  /* 0x800A0494 */
    R[5] = R[18] + R[0];  /* 0x800A0498 */
    R[6] = R[17] + R[0];  /* 0x800A049C */
    R[7] = R[16] + 748;  /* 0x800A04A0 */
    { R[31] = 0x800A04ACu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04A4 jal */
    R[4] = R[0] + 5;  /* 0x800A04AC */
    R[5] = R[18] + R[0];  /* 0x800A04B0 */
    R[6] = R[17] + R[0];  /* 0x800A04B4 */
    R[7] = R[16] + 792;  /* 0x800A04B8 */
    { R[31] = 0x800A04C4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04BC jal */
    R[4] = R[0] + 14;  /* 0x800A04C4 */
    R[5] = R[18] + R[0];  /* 0x800A04C8 */
    R[6] = R[17] + R[0];  /* 0x800A04CC */
    R[7] = R[16] + 836;  /* 0x800A04D0 */
    { R[31] = 0x800A04DCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04D4 jal */
    R[4] = R[0] + 15;  /* 0x800A04DC */
    R[5] = R[18] + R[0];  /* 0x800A04E0 */
    R[6] = R[17] + R[0];  /* 0x800A04E4 */
    R[7] = R[16] + 880;  /* 0x800A04E8 */
    { R[31] = 0x800A04F4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04EC jal */
    R[4] = R[0] + 22;  /* 0x800A04F4 */
    R[5] = R[18] + R[0];  /* 0x800A04F8 */
    R[6] = R[17] + R[0];  /* 0x800A04FC */
    R[7] = R[16] + 924;  /* 0x800A0500 */
    { R[31] = 0x800A050Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0504 jal */
    R[4] = R[0] + 23;  /* 0x800A050C */
    R[5] = R[18] + R[0];  /* 0x800A0510 */
    R[6] = R[17] + R[0];  /* 0x800A0514 */
    R[7] = R[16] + 968;  /* 0x800A0518 */
    { R[31] = 0x800A0524u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A051C jal */
    R[4] = R[0] + 24;  /* 0x800A0524 */
    R[5] = R[18] + R[0];  /* 0x800A0528 */
    R[6] = R[17] + R[0];  /* 0x800A052C */
    R[7] = R[16] + 1012;  /* 0x800A0530 */
    psx_next = 0x800A0534u; return;  /* fallthrough */
}

void ev_800A03EC(void) {
    R[4] = R[0] + 18;  /* 0x800A03EC */
    R[5] = R[18] + R[0];  /* 0x800A03F0 */
    R[6] = R[17] + R[0];  /* 0x800A03F4 */
    R[7] = R[16] + 440;  /* 0x800A03F8 */
    { R[31] = 0x800A0404u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A03FC jal */
    R[4] = R[0] + 12;  /* 0x800A0404 */
    R[5] = R[18] + R[0];  /* 0x800A0408 */
    R[6] = R[17] + R[0];  /* 0x800A040C */
    R[7] = R[16] + 484;  /* 0x800A0410 */
    { R[31] = 0x800A041Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0414 jal */
    R[4] = R[0] + 7;  /* 0x800A041C */
    R[5] = R[18] + R[0];  /* 0x800A0420 */
    R[6] = R[17] + R[0];  /* 0x800A0424 */
    R[7] = R[16] + 528;  /* 0x800A0428 */
    { R[31] = 0x800A0434u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A042C jal */
    R[4] = R[0] + 13;  /* 0x800A0434 */
    R[5] = R[18] + R[0];  /* 0x800A0438 */
    R[6] = R[17] + R[0];  /* 0x800A043C */
    R[7] = R[16] + 660;  /* 0x800A0440 */
    { R[31] = 0x800A044Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0444 jal */
    R[4] = R[0] + 111;  /* 0x800A044C */
    R[5] = R[18] + R[0];  /* 0x800A0450 */
    R[6] = R[17] + R[0];  /* 0x800A0454 */
    R[7] = R[16] + 572;  /* 0x800A0458 */
    { R[31] = 0x800A0464u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A045C jal */
    R[4] = R[0] + 112;  /* 0x800A0464 */
    R[5] = R[18] + R[0];  /* 0x800A0468 */
    R[6] = R[17] + R[0];  /* 0x800A046C */
    R[7] = R[16] + 616;  /* 0x800A0470 */
    { R[31] = 0x800A047Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0474 jal */
    R[4] = R[0] + 6;  /* 0x800A047C */
    R[5] = R[18] + R[0];  /* 0x800A0480 */
    R[6] = R[17] + R[0];  /* 0x800A0484 */
    R[7] = R[16] + 704;  /* 0x800A0488 */
    { R[31] = 0x800A0494u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A048C jal */
    R[4] = R[0] + 21;  /* 0x800A0494 */
    R[5] = R[18] + R[0];  /* 0x800A0498 */
    R[6] = R[17] + R[0];  /* 0x800A049C */
    R[7] = R[16] + 748;  /* 0x800A04A0 */
    { R[31] = 0x800A04ACu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04A4 jal */
    R[4] = R[0] + 5;  /* 0x800A04AC */
    R[5] = R[18] + R[0];  /* 0x800A04B0 */
    R[6] = R[17] + R[0];  /* 0x800A04B4 */
    R[7] = R[16] + 792;  /* 0x800A04B8 */
    { R[31] = 0x800A04C4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04BC jal */
    R[4] = R[0] + 14;  /* 0x800A04C4 */
    R[5] = R[18] + R[0];  /* 0x800A04C8 */
    R[6] = R[17] + R[0];  /* 0x800A04CC */
    R[7] = R[16] + 836;  /* 0x800A04D0 */
    { R[31] = 0x800A04DCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04D4 jal */
    R[4] = R[0] + 15;  /* 0x800A04DC */
    R[5] = R[18] + R[0];  /* 0x800A04E0 */
    R[6] = R[17] + R[0];  /* 0x800A04E4 */
    R[7] = R[16] + 880;  /* 0x800A04E8 */
    { R[31] = 0x800A04F4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04EC jal */
    R[4] = R[0] + 22;  /* 0x800A04F4 */
    R[5] = R[18] + R[0];  /* 0x800A04F8 */
    R[6] = R[17] + R[0];  /* 0x800A04FC */
    R[7] = R[16] + 924;  /* 0x800A0500 */
    { R[31] = 0x800A050Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0504 jal */
    R[4] = R[0] + 23;  /* 0x800A050C */
    R[5] = R[18] + R[0];  /* 0x800A0510 */
    R[6] = R[17] + R[0];  /* 0x800A0514 */
    R[7] = R[16] + 968;  /* 0x800A0518 */
    { R[31] = 0x800A0524u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A051C jal */
    R[4] = R[0] + 24;  /* 0x800A0524 */
    R[5] = R[18] + R[0];  /* 0x800A0528 */
    R[6] = R[17] + R[0];  /* 0x800A052C */
    R[7] = R[16] + 1012;  /* 0x800A0530 */
    psx_next = 0x800A0534u; return;  /* fallthrough */
}

void ev_800A0400(void) {
    sw_(R[29] + 16, R[0]);  /* 0x800A0400 */
    R[4] = R[0] + 12;  /* 0x800A0404 */
    R[5] = R[18] + R[0];  /* 0x800A0408 */
    R[6] = R[17] + R[0];  /* 0x800A040C */
    R[7] = R[16] + 484;  /* 0x800A0410 */
    { R[31] = 0x800A041Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0414 jal */
    R[4] = R[0] + 7;  /* 0x800A041C */
    R[5] = R[18] + R[0];  /* 0x800A0420 */
    R[6] = R[17] + R[0];  /* 0x800A0424 */
    R[7] = R[16] + 528;  /* 0x800A0428 */
    { R[31] = 0x800A0434u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A042C jal */
    R[4] = R[0] + 13;  /* 0x800A0434 */
    R[5] = R[18] + R[0];  /* 0x800A0438 */
    R[6] = R[17] + R[0];  /* 0x800A043C */
    R[7] = R[16] + 660;  /* 0x800A0440 */
    { R[31] = 0x800A044Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0444 jal */
    R[4] = R[0] + 111;  /* 0x800A044C */
    R[5] = R[18] + R[0];  /* 0x800A0450 */
    R[6] = R[17] + R[0];  /* 0x800A0454 */
    R[7] = R[16] + 572;  /* 0x800A0458 */
    { R[31] = 0x800A0464u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A045C jal */
    R[4] = R[0] + 112;  /* 0x800A0464 */
    R[5] = R[18] + R[0];  /* 0x800A0468 */
    R[6] = R[17] + R[0];  /* 0x800A046C */
    R[7] = R[16] + 616;  /* 0x800A0470 */
    { R[31] = 0x800A047Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0474 jal */
    R[4] = R[0] + 6;  /* 0x800A047C */
    R[5] = R[18] + R[0];  /* 0x800A0480 */
    R[6] = R[17] + R[0];  /* 0x800A0484 */
    R[7] = R[16] + 704;  /* 0x800A0488 */
    { R[31] = 0x800A0494u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A048C jal */
    R[4] = R[0] + 21;  /* 0x800A0494 */
    R[5] = R[18] + R[0];  /* 0x800A0498 */
    R[6] = R[17] + R[0];  /* 0x800A049C */
    R[7] = R[16] + 748;  /* 0x800A04A0 */
    { R[31] = 0x800A04ACu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04A4 jal */
    R[4] = R[0] + 5;  /* 0x800A04AC */
    R[5] = R[18] + R[0];  /* 0x800A04B0 */
    R[6] = R[17] + R[0];  /* 0x800A04B4 */
    R[7] = R[16] + 792;  /* 0x800A04B8 */
    { R[31] = 0x800A04C4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04BC jal */
    R[4] = R[0] + 14;  /* 0x800A04C4 */
    R[5] = R[18] + R[0];  /* 0x800A04C8 */
    R[6] = R[17] + R[0];  /* 0x800A04CC */
    R[7] = R[16] + 836;  /* 0x800A04D0 */
    { R[31] = 0x800A04DCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04D4 jal */
    R[4] = R[0] + 15;  /* 0x800A04DC */
    R[5] = R[18] + R[0];  /* 0x800A04E0 */
    R[6] = R[17] + R[0];  /* 0x800A04E4 */
    R[7] = R[16] + 880;  /* 0x800A04E8 */
    { R[31] = 0x800A04F4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04EC jal */
    R[4] = R[0] + 22;  /* 0x800A04F4 */
    R[5] = R[18] + R[0];  /* 0x800A04F8 */
    R[6] = R[17] + R[0];  /* 0x800A04FC */
    R[7] = R[16] + 924;  /* 0x800A0500 */
    { R[31] = 0x800A050Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0504 jal */
    R[4] = R[0] + 23;  /* 0x800A050C */
    R[5] = R[18] + R[0];  /* 0x800A0510 */
    R[6] = R[17] + R[0];  /* 0x800A0514 */
    R[7] = R[16] + 968;  /* 0x800A0518 */
    { R[31] = 0x800A0524u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A051C jal */
    R[4] = R[0] + 24;  /* 0x800A0524 */
    R[5] = R[18] + R[0];  /* 0x800A0528 */
    R[6] = R[17] + R[0];  /* 0x800A052C */
    R[7] = R[16] + 1012;  /* 0x800A0530 */
    psx_next = 0x800A0534u; return;  /* fallthrough */
}

void ev_800A0404(void) {
    R[4] = R[0] + 12;  /* 0x800A0404 */
    R[5] = R[18] + R[0];  /* 0x800A0408 */
    R[6] = R[17] + R[0];  /* 0x800A040C */
    R[7] = R[16] + 484;  /* 0x800A0410 */
    { R[31] = 0x800A041Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0414 jal */
    R[4] = R[0] + 7;  /* 0x800A041C */
    R[5] = R[18] + R[0];  /* 0x800A0420 */
    R[6] = R[17] + R[0];  /* 0x800A0424 */
    R[7] = R[16] + 528;  /* 0x800A0428 */
    { R[31] = 0x800A0434u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A042C jal */
    R[4] = R[0] + 13;  /* 0x800A0434 */
    R[5] = R[18] + R[0];  /* 0x800A0438 */
    R[6] = R[17] + R[0];  /* 0x800A043C */
    R[7] = R[16] + 660;  /* 0x800A0440 */
    { R[31] = 0x800A044Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0444 jal */
    R[4] = R[0] + 111;  /* 0x800A044C */
    R[5] = R[18] + R[0];  /* 0x800A0450 */
    R[6] = R[17] + R[0];  /* 0x800A0454 */
    R[7] = R[16] + 572;  /* 0x800A0458 */
    { R[31] = 0x800A0464u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A045C jal */
    R[4] = R[0] + 112;  /* 0x800A0464 */
    R[5] = R[18] + R[0];  /* 0x800A0468 */
    R[6] = R[17] + R[0];  /* 0x800A046C */
    R[7] = R[16] + 616;  /* 0x800A0470 */
    { R[31] = 0x800A047Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0474 jal */
    R[4] = R[0] + 6;  /* 0x800A047C */
    R[5] = R[18] + R[0];  /* 0x800A0480 */
    R[6] = R[17] + R[0];  /* 0x800A0484 */
    R[7] = R[16] + 704;  /* 0x800A0488 */
    { R[31] = 0x800A0494u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A048C jal */
    R[4] = R[0] + 21;  /* 0x800A0494 */
    R[5] = R[18] + R[0];  /* 0x800A0498 */
    R[6] = R[17] + R[0];  /* 0x800A049C */
    R[7] = R[16] + 748;  /* 0x800A04A0 */
    { R[31] = 0x800A04ACu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04A4 jal */
    R[4] = R[0] + 5;  /* 0x800A04AC */
    R[5] = R[18] + R[0];  /* 0x800A04B0 */
    R[6] = R[17] + R[0];  /* 0x800A04B4 */
    R[7] = R[16] + 792;  /* 0x800A04B8 */
    { R[31] = 0x800A04C4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04BC jal */
    R[4] = R[0] + 14;  /* 0x800A04C4 */
    R[5] = R[18] + R[0];  /* 0x800A04C8 */
    R[6] = R[17] + R[0];  /* 0x800A04CC */
    R[7] = R[16] + 836;  /* 0x800A04D0 */
    { R[31] = 0x800A04DCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04D4 jal */
    R[4] = R[0] + 15;  /* 0x800A04DC */
    R[5] = R[18] + R[0];  /* 0x800A04E0 */
    R[6] = R[17] + R[0];  /* 0x800A04E4 */
    R[7] = R[16] + 880;  /* 0x800A04E8 */
    { R[31] = 0x800A04F4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04EC jal */
    R[4] = R[0] + 22;  /* 0x800A04F4 */
    R[5] = R[18] + R[0];  /* 0x800A04F8 */
    R[6] = R[17] + R[0];  /* 0x800A04FC */
    R[7] = R[16] + 924;  /* 0x800A0500 */
    { R[31] = 0x800A050Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0504 jal */
    R[4] = R[0] + 23;  /* 0x800A050C */
    R[5] = R[18] + R[0];  /* 0x800A0510 */
    R[6] = R[17] + R[0];  /* 0x800A0514 */
    R[7] = R[16] + 968;  /* 0x800A0518 */
    { R[31] = 0x800A0524u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A051C jal */
    R[4] = R[0] + 24;  /* 0x800A0524 */
    R[5] = R[18] + R[0];  /* 0x800A0528 */
    R[6] = R[17] + R[0];  /* 0x800A052C */
    R[7] = R[16] + 1012;  /* 0x800A0530 */
    psx_next = 0x800A0534u; return;  /* fallthrough */
}

void ev_800A041C(void) {
    R[4] = R[0] + 7;  /* 0x800A041C */
    R[5] = R[18] + R[0];  /* 0x800A0420 */
    R[6] = R[17] + R[0];  /* 0x800A0424 */
    R[7] = R[16] + 528;  /* 0x800A0428 */
    { R[31] = 0x800A0434u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A042C jal */
    R[4] = R[0] + 13;  /* 0x800A0434 */
    R[5] = R[18] + R[0];  /* 0x800A0438 */
    R[6] = R[17] + R[0];  /* 0x800A043C */
    R[7] = R[16] + 660;  /* 0x800A0440 */
    { R[31] = 0x800A044Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0444 jal */
    R[4] = R[0] + 111;  /* 0x800A044C */
    R[5] = R[18] + R[0];  /* 0x800A0450 */
    R[6] = R[17] + R[0];  /* 0x800A0454 */
    R[7] = R[16] + 572;  /* 0x800A0458 */
    { R[31] = 0x800A0464u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A045C jal */
    R[4] = R[0] + 112;  /* 0x800A0464 */
    R[5] = R[18] + R[0];  /* 0x800A0468 */
    R[6] = R[17] + R[0];  /* 0x800A046C */
    R[7] = R[16] + 616;  /* 0x800A0470 */
    { R[31] = 0x800A047Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0474 jal */
    R[4] = R[0] + 6;  /* 0x800A047C */
    R[5] = R[18] + R[0];  /* 0x800A0480 */
    R[6] = R[17] + R[0];  /* 0x800A0484 */
    R[7] = R[16] + 704;  /* 0x800A0488 */
    { R[31] = 0x800A0494u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A048C jal */
    R[4] = R[0] + 21;  /* 0x800A0494 */
    R[5] = R[18] + R[0];  /* 0x800A0498 */
    R[6] = R[17] + R[0];  /* 0x800A049C */
    R[7] = R[16] + 748;  /* 0x800A04A0 */
    { R[31] = 0x800A04ACu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04A4 jal */
    R[4] = R[0] + 5;  /* 0x800A04AC */
    R[5] = R[18] + R[0];  /* 0x800A04B0 */
    R[6] = R[17] + R[0];  /* 0x800A04B4 */
    R[7] = R[16] + 792;  /* 0x800A04B8 */
    { R[31] = 0x800A04C4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04BC jal */
    R[4] = R[0] + 14;  /* 0x800A04C4 */
    R[5] = R[18] + R[0];  /* 0x800A04C8 */
    R[6] = R[17] + R[0];  /* 0x800A04CC */
    R[7] = R[16] + 836;  /* 0x800A04D0 */
    { R[31] = 0x800A04DCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04D4 jal */
    R[4] = R[0] + 15;  /* 0x800A04DC */
    R[5] = R[18] + R[0];  /* 0x800A04E0 */
    R[6] = R[17] + R[0];  /* 0x800A04E4 */
    R[7] = R[16] + 880;  /* 0x800A04E8 */
    { R[31] = 0x800A04F4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04EC jal */
    R[4] = R[0] + 22;  /* 0x800A04F4 */
    R[5] = R[18] + R[0];  /* 0x800A04F8 */
    R[6] = R[17] + R[0];  /* 0x800A04FC */
    R[7] = R[16] + 924;  /* 0x800A0500 */
    { R[31] = 0x800A050Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0504 jal */
    R[4] = R[0] + 23;  /* 0x800A050C */
    R[5] = R[18] + R[0];  /* 0x800A0510 */
    R[6] = R[17] + R[0];  /* 0x800A0514 */
    R[7] = R[16] + 968;  /* 0x800A0518 */
    { R[31] = 0x800A0524u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A051C jal */
    R[4] = R[0] + 24;  /* 0x800A0524 */
    R[5] = R[18] + R[0];  /* 0x800A0528 */
    R[6] = R[17] + R[0];  /* 0x800A052C */
    R[7] = R[16] + 1012;  /* 0x800A0530 */
    psx_next = 0x800A0534u; return;  /* fallthrough */
}

void ev_800A0434(void) {
    R[4] = R[0] + 13;  /* 0x800A0434 */
    R[5] = R[18] + R[0];  /* 0x800A0438 */
    R[6] = R[17] + R[0];  /* 0x800A043C */
    R[7] = R[16] + 660;  /* 0x800A0440 */
    { R[31] = 0x800A044Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0444 jal */
    R[4] = R[0] + 111;  /* 0x800A044C */
    R[5] = R[18] + R[0];  /* 0x800A0450 */
    R[6] = R[17] + R[0];  /* 0x800A0454 */
    R[7] = R[16] + 572;  /* 0x800A0458 */
    { R[31] = 0x800A0464u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A045C jal */
    R[4] = R[0] + 112;  /* 0x800A0464 */
    R[5] = R[18] + R[0];  /* 0x800A0468 */
    R[6] = R[17] + R[0];  /* 0x800A046C */
    R[7] = R[16] + 616;  /* 0x800A0470 */
    { R[31] = 0x800A047Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0474 jal */
    R[4] = R[0] + 6;  /* 0x800A047C */
    R[5] = R[18] + R[0];  /* 0x800A0480 */
    R[6] = R[17] + R[0];  /* 0x800A0484 */
    R[7] = R[16] + 704;  /* 0x800A0488 */
    { R[31] = 0x800A0494u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A048C jal */
    R[4] = R[0] + 21;  /* 0x800A0494 */
    R[5] = R[18] + R[0];  /* 0x800A0498 */
    R[6] = R[17] + R[0];  /* 0x800A049C */
    R[7] = R[16] + 748;  /* 0x800A04A0 */
    { R[31] = 0x800A04ACu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04A4 jal */
    R[4] = R[0] + 5;  /* 0x800A04AC */
    R[5] = R[18] + R[0];  /* 0x800A04B0 */
    R[6] = R[17] + R[0];  /* 0x800A04B4 */
    R[7] = R[16] + 792;  /* 0x800A04B8 */
    { R[31] = 0x800A04C4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04BC jal */
    R[4] = R[0] + 14;  /* 0x800A04C4 */
    R[5] = R[18] + R[0];  /* 0x800A04C8 */
    R[6] = R[17] + R[0];  /* 0x800A04CC */
    R[7] = R[16] + 836;  /* 0x800A04D0 */
    { R[31] = 0x800A04DCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04D4 jal */
    R[4] = R[0] + 15;  /* 0x800A04DC */
    R[5] = R[18] + R[0];  /* 0x800A04E0 */
    R[6] = R[17] + R[0];  /* 0x800A04E4 */
    R[7] = R[16] + 880;  /* 0x800A04E8 */
    { R[31] = 0x800A04F4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04EC jal */
    R[4] = R[0] + 22;  /* 0x800A04F4 */
    R[5] = R[18] + R[0];  /* 0x800A04F8 */
    R[6] = R[17] + R[0];  /* 0x800A04FC */
    R[7] = R[16] + 924;  /* 0x800A0500 */
    { R[31] = 0x800A050Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0504 jal */
    R[4] = R[0] + 23;  /* 0x800A050C */
    R[5] = R[18] + R[0];  /* 0x800A0510 */
    R[6] = R[17] + R[0];  /* 0x800A0514 */
    R[7] = R[16] + 968;  /* 0x800A0518 */
    { R[31] = 0x800A0524u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A051C jal */
    R[4] = R[0] + 24;  /* 0x800A0524 */
    R[5] = R[18] + R[0];  /* 0x800A0528 */
    R[6] = R[17] + R[0];  /* 0x800A052C */
    R[7] = R[16] + 1012;  /* 0x800A0530 */
    psx_next = 0x800A0534u; return;  /* fallthrough */
}

void ev_800A044C(void) {
    R[4] = R[0] + 111;  /* 0x800A044C */
    R[5] = R[18] + R[0];  /* 0x800A0450 */
    R[6] = R[17] + R[0];  /* 0x800A0454 */
    R[7] = R[16] + 572;  /* 0x800A0458 */
    { R[31] = 0x800A0464u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A045C jal */
    R[4] = R[0] + 112;  /* 0x800A0464 */
    R[5] = R[18] + R[0];  /* 0x800A0468 */
    R[6] = R[17] + R[0];  /* 0x800A046C */
    R[7] = R[16] + 616;  /* 0x800A0470 */
    { R[31] = 0x800A047Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0474 jal */
    R[4] = R[0] + 6;  /* 0x800A047C */
    R[5] = R[18] + R[0];  /* 0x800A0480 */
    R[6] = R[17] + R[0];  /* 0x800A0484 */
    R[7] = R[16] + 704;  /* 0x800A0488 */
    { R[31] = 0x800A0494u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A048C jal */
    R[4] = R[0] + 21;  /* 0x800A0494 */
    R[5] = R[18] + R[0];  /* 0x800A0498 */
    R[6] = R[17] + R[0];  /* 0x800A049C */
    R[7] = R[16] + 748;  /* 0x800A04A0 */
    { R[31] = 0x800A04ACu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04A4 jal */
    R[4] = R[0] + 5;  /* 0x800A04AC */
    R[5] = R[18] + R[0];  /* 0x800A04B0 */
    R[6] = R[17] + R[0];  /* 0x800A04B4 */
    R[7] = R[16] + 792;  /* 0x800A04B8 */
    { R[31] = 0x800A04C4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04BC jal */
    R[4] = R[0] + 14;  /* 0x800A04C4 */
    R[5] = R[18] + R[0];  /* 0x800A04C8 */
    R[6] = R[17] + R[0];  /* 0x800A04CC */
    R[7] = R[16] + 836;  /* 0x800A04D0 */
    { R[31] = 0x800A04DCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04D4 jal */
    R[4] = R[0] + 15;  /* 0x800A04DC */
    R[5] = R[18] + R[0];  /* 0x800A04E0 */
    R[6] = R[17] + R[0];  /* 0x800A04E4 */
    R[7] = R[16] + 880;  /* 0x800A04E8 */
    { R[31] = 0x800A04F4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04EC jal */
    R[4] = R[0] + 22;  /* 0x800A04F4 */
    R[5] = R[18] + R[0];  /* 0x800A04F8 */
    R[6] = R[17] + R[0];  /* 0x800A04FC */
    R[7] = R[16] + 924;  /* 0x800A0500 */
    { R[31] = 0x800A050Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0504 jal */
    R[4] = R[0] + 23;  /* 0x800A050C */
    R[5] = R[18] + R[0];  /* 0x800A0510 */
    R[6] = R[17] + R[0];  /* 0x800A0514 */
    R[7] = R[16] + 968;  /* 0x800A0518 */
    { R[31] = 0x800A0524u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A051C jal */
    R[4] = R[0] + 24;  /* 0x800A0524 */
    R[5] = R[18] + R[0];  /* 0x800A0528 */
    R[6] = R[17] + R[0];  /* 0x800A052C */
    R[7] = R[16] + 1012;  /* 0x800A0530 */
    psx_next = 0x800A0534u; return;  /* fallthrough */
}

void ev_800A0464(void) {
    R[4] = R[0] + 112;  /* 0x800A0464 */
    R[5] = R[18] + R[0];  /* 0x800A0468 */
    R[6] = R[17] + R[0];  /* 0x800A046C */
    R[7] = R[16] + 616;  /* 0x800A0470 */
    { R[31] = 0x800A047Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0474 jal */
    R[4] = R[0] + 6;  /* 0x800A047C */
    R[5] = R[18] + R[0];  /* 0x800A0480 */
    R[6] = R[17] + R[0];  /* 0x800A0484 */
    R[7] = R[16] + 704;  /* 0x800A0488 */
    { R[31] = 0x800A0494u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A048C jal */
    R[4] = R[0] + 21;  /* 0x800A0494 */
    R[5] = R[18] + R[0];  /* 0x800A0498 */
    R[6] = R[17] + R[0];  /* 0x800A049C */
    R[7] = R[16] + 748;  /* 0x800A04A0 */
    { R[31] = 0x800A04ACu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04A4 jal */
    R[4] = R[0] + 5;  /* 0x800A04AC */
    R[5] = R[18] + R[0];  /* 0x800A04B0 */
    R[6] = R[17] + R[0];  /* 0x800A04B4 */
    R[7] = R[16] + 792;  /* 0x800A04B8 */
    { R[31] = 0x800A04C4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04BC jal */
    R[4] = R[0] + 14;  /* 0x800A04C4 */
    R[5] = R[18] + R[0];  /* 0x800A04C8 */
    R[6] = R[17] + R[0];  /* 0x800A04CC */
    R[7] = R[16] + 836;  /* 0x800A04D0 */
    { R[31] = 0x800A04DCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04D4 jal */
    R[4] = R[0] + 15;  /* 0x800A04DC */
    R[5] = R[18] + R[0];  /* 0x800A04E0 */
    R[6] = R[17] + R[0];  /* 0x800A04E4 */
    R[7] = R[16] + 880;  /* 0x800A04E8 */
    { R[31] = 0x800A04F4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04EC jal */
    R[4] = R[0] + 22;  /* 0x800A04F4 */
    R[5] = R[18] + R[0];  /* 0x800A04F8 */
    R[6] = R[17] + R[0];  /* 0x800A04FC */
    R[7] = R[16] + 924;  /* 0x800A0500 */
    { R[31] = 0x800A050Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0504 jal */
    R[4] = R[0] + 23;  /* 0x800A050C */
    R[5] = R[18] + R[0];  /* 0x800A0510 */
    R[6] = R[17] + R[0];  /* 0x800A0514 */
    R[7] = R[16] + 968;  /* 0x800A0518 */
    { R[31] = 0x800A0524u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A051C jal */
    R[4] = R[0] + 24;  /* 0x800A0524 */
    R[5] = R[18] + R[0];  /* 0x800A0528 */
    R[6] = R[17] + R[0];  /* 0x800A052C */
    R[7] = R[16] + 1012;  /* 0x800A0530 */
    psx_next = 0x800A0534u; return;  /* fallthrough */
}

void ev_800A047C(void) {
    R[4] = R[0] + 6;  /* 0x800A047C */
    R[5] = R[18] + R[0];  /* 0x800A0480 */
    R[6] = R[17] + R[0];  /* 0x800A0484 */
    R[7] = R[16] + 704;  /* 0x800A0488 */
    { R[31] = 0x800A0494u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A048C jal */
    R[4] = R[0] + 21;  /* 0x800A0494 */
    R[5] = R[18] + R[0];  /* 0x800A0498 */
    R[6] = R[17] + R[0];  /* 0x800A049C */
    R[7] = R[16] + 748;  /* 0x800A04A0 */
    { R[31] = 0x800A04ACu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04A4 jal */
    R[4] = R[0] + 5;  /* 0x800A04AC */
    R[5] = R[18] + R[0];  /* 0x800A04B0 */
    R[6] = R[17] + R[0];  /* 0x800A04B4 */
    R[7] = R[16] + 792;  /* 0x800A04B8 */
    { R[31] = 0x800A04C4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04BC jal */
    R[4] = R[0] + 14;  /* 0x800A04C4 */
    R[5] = R[18] + R[0];  /* 0x800A04C8 */
    R[6] = R[17] + R[0];  /* 0x800A04CC */
    R[7] = R[16] + 836;  /* 0x800A04D0 */
    { R[31] = 0x800A04DCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04D4 jal */
    R[4] = R[0] + 15;  /* 0x800A04DC */
    R[5] = R[18] + R[0];  /* 0x800A04E0 */
    R[6] = R[17] + R[0];  /* 0x800A04E4 */
    R[7] = R[16] + 880;  /* 0x800A04E8 */
    { R[31] = 0x800A04F4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04EC jal */
    R[4] = R[0] + 22;  /* 0x800A04F4 */
    R[5] = R[18] + R[0];  /* 0x800A04F8 */
    R[6] = R[17] + R[0];  /* 0x800A04FC */
    R[7] = R[16] + 924;  /* 0x800A0500 */
    { R[31] = 0x800A050Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0504 jal */
    R[4] = R[0] + 23;  /* 0x800A050C */
    R[5] = R[18] + R[0];  /* 0x800A0510 */
    R[6] = R[17] + R[0];  /* 0x800A0514 */
    R[7] = R[16] + 968;  /* 0x800A0518 */
    { R[31] = 0x800A0524u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A051C jal */
    R[4] = R[0] + 24;  /* 0x800A0524 */
    R[5] = R[18] + R[0];  /* 0x800A0528 */
    R[6] = R[17] + R[0];  /* 0x800A052C */
    R[7] = R[16] + 1012;  /* 0x800A0530 */
    psx_next = 0x800A0534u; return;  /* fallthrough */
}

void ev_800A0494(void) {
    R[4] = R[0] + 21;  /* 0x800A0494 */
    R[5] = R[18] + R[0];  /* 0x800A0498 */
    R[6] = R[17] + R[0];  /* 0x800A049C */
    R[7] = R[16] + 748;  /* 0x800A04A0 */
    { R[31] = 0x800A04ACu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04A4 jal */
    R[4] = R[0] + 5;  /* 0x800A04AC */
    R[5] = R[18] + R[0];  /* 0x800A04B0 */
    R[6] = R[17] + R[0];  /* 0x800A04B4 */
    R[7] = R[16] + 792;  /* 0x800A04B8 */
    { R[31] = 0x800A04C4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04BC jal */
    R[4] = R[0] + 14;  /* 0x800A04C4 */
    R[5] = R[18] + R[0];  /* 0x800A04C8 */
    R[6] = R[17] + R[0];  /* 0x800A04CC */
    R[7] = R[16] + 836;  /* 0x800A04D0 */
    { R[31] = 0x800A04DCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04D4 jal */
    R[4] = R[0] + 15;  /* 0x800A04DC */
    R[5] = R[18] + R[0];  /* 0x800A04E0 */
    R[6] = R[17] + R[0];  /* 0x800A04E4 */
    R[7] = R[16] + 880;  /* 0x800A04E8 */
    { R[31] = 0x800A04F4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04EC jal */
    R[4] = R[0] + 22;  /* 0x800A04F4 */
    R[5] = R[18] + R[0];  /* 0x800A04F8 */
    R[6] = R[17] + R[0];  /* 0x800A04FC */
    R[7] = R[16] + 924;  /* 0x800A0500 */
    { R[31] = 0x800A050Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0504 jal */
    R[4] = R[0] + 23;  /* 0x800A050C */
    R[5] = R[18] + R[0];  /* 0x800A0510 */
    R[6] = R[17] + R[0];  /* 0x800A0514 */
    R[7] = R[16] + 968;  /* 0x800A0518 */
    { R[31] = 0x800A0524u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A051C jal */
    R[4] = R[0] + 24;  /* 0x800A0524 */
    R[5] = R[18] + R[0];  /* 0x800A0528 */
    R[6] = R[17] + R[0];  /* 0x800A052C */
    R[7] = R[16] + 1012;  /* 0x800A0530 */
    psx_next = 0x800A0534u; return;  /* fallthrough */
}

void ev_800A04AC(void) {
    R[4] = R[0] + 5;  /* 0x800A04AC */
    R[5] = R[18] + R[0];  /* 0x800A04B0 */
    R[6] = R[17] + R[0];  /* 0x800A04B4 */
    R[7] = R[16] + 792;  /* 0x800A04B8 */
    { R[31] = 0x800A04C4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04BC jal */
    R[4] = R[0] + 14;  /* 0x800A04C4 */
    R[5] = R[18] + R[0];  /* 0x800A04C8 */
    R[6] = R[17] + R[0];  /* 0x800A04CC */
    R[7] = R[16] + 836;  /* 0x800A04D0 */
    { R[31] = 0x800A04DCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04D4 jal */
    R[4] = R[0] + 15;  /* 0x800A04DC */
    R[5] = R[18] + R[0];  /* 0x800A04E0 */
    R[6] = R[17] + R[0];  /* 0x800A04E4 */
    R[7] = R[16] + 880;  /* 0x800A04E8 */
    { R[31] = 0x800A04F4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04EC jal */
    R[4] = R[0] + 22;  /* 0x800A04F4 */
    R[5] = R[18] + R[0];  /* 0x800A04F8 */
    R[6] = R[17] + R[0];  /* 0x800A04FC */
    R[7] = R[16] + 924;  /* 0x800A0500 */
    { R[31] = 0x800A050Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0504 jal */
    R[4] = R[0] + 23;  /* 0x800A050C */
    R[5] = R[18] + R[0];  /* 0x800A0510 */
    R[6] = R[17] + R[0];  /* 0x800A0514 */
    R[7] = R[16] + 968;  /* 0x800A0518 */
    { R[31] = 0x800A0524u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A051C jal */
    R[4] = R[0] + 24;  /* 0x800A0524 */
    R[5] = R[18] + R[0];  /* 0x800A0528 */
    R[6] = R[17] + R[0];  /* 0x800A052C */
    R[7] = R[16] + 1012;  /* 0x800A0530 */
    psx_next = 0x800A0534u; return;  /* fallthrough */
}

void ev_800A04C4(void) {
    R[4] = R[0] + 14;  /* 0x800A04C4 */
    R[5] = R[18] + R[0];  /* 0x800A04C8 */
    R[6] = R[17] + R[0];  /* 0x800A04CC */
    R[7] = R[16] + 836;  /* 0x800A04D0 */
    { R[31] = 0x800A04DCu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04D4 jal */
    R[4] = R[0] + 15;  /* 0x800A04DC */
    R[5] = R[18] + R[0];  /* 0x800A04E0 */
    R[6] = R[17] + R[0];  /* 0x800A04E4 */
    R[7] = R[16] + 880;  /* 0x800A04E8 */
    { R[31] = 0x800A04F4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04EC jal */
    R[4] = R[0] + 22;  /* 0x800A04F4 */
    R[5] = R[18] + R[0];  /* 0x800A04F8 */
    R[6] = R[17] + R[0];  /* 0x800A04FC */
    R[7] = R[16] + 924;  /* 0x800A0500 */
    { R[31] = 0x800A050Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0504 jal */
    R[4] = R[0] + 23;  /* 0x800A050C */
    R[5] = R[18] + R[0];  /* 0x800A0510 */
    R[6] = R[17] + R[0];  /* 0x800A0514 */
    R[7] = R[16] + 968;  /* 0x800A0518 */
    { R[31] = 0x800A0524u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A051C jal */
    R[4] = R[0] + 24;  /* 0x800A0524 */
    R[5] = R[18] + R[0];  /* 0x800A0528 */
    R[6] = R[17] + R[0];  /* 0x800A052C */
    R[7] = R[16] + 1012;  /* 0x800A0530 */
    psx_next = 0x800A0534u; return;  /* fallthrough */
}

void ev_800A04DC(void) {
    R[4] = R[0] + 15;  /* 0x800A04DC */
    R[5] = R[18] + R[0];  /* 0x800A04E0 */
    R[6] = R[17] + R[0];  /* 0x800A04E4 */
    R[7] = R[16] + 880;  /* 0x800A04E8 */
    { R[31] = 0x800A04F4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A04EC jal */
    R[4] = R[0] + 22;  /* 0x800A04F4 */
    R[5] = R[18] + R[0];  /* 0x800A04F8 */
    R[6] = R[17] + R[0];  /* 0x800A04FC */
    R[7] = R[16] + 924;  /* 0x800A0500 */
    { R[31] = 0x800A050Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0504 jal */
    R[4] = R[0] + 23;  /* 0x800A050C */
    R[5] = R[18] + R[0];  /* 0x800A0510 */
    R[6] = R[17] + R[0];  /* 0x800A0514 */
    R[7] = R[16] + 968;  /* 0x800A0518 */
    { R[31] = 0x800A0524u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A051C jal */
    R[4] = R[0] + 24;  /* 0x800A0524 */
    R[5] = R[18] + R[0];  /* 0x800A0528 */
    R[6] = R[17] + R[0];  /* 0x800A052C */
    R[7] = R[16] + 1012;  /* 0x800A0530 */
    psx_next = 0x800A0534u; return;  /* fallthrough */
}

void ev_800A04F4(void) {
    R[4] = R[0] + 22;  /* 0x800A04F4 */
    R[5] = R[18] + R[0];  /* 0x800A04F8 */
    R[6] = R[17] + R[0];  /* 0x800A04FC */
    R[7] = R[16] + 924;  /* 0x800A0500 */
    { R[31] = 0x800A050Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0504 jal */
    R[4] = R[0] + 23;  /* 0x800A050C */
    R[5] = R[18] + R[0];  /* 0x800A0510 */
    R[6] = R[17] + R[0];  /* 0x800A0514 */
    R[7] = R[16] + 968;  /* 0x800A0518 */
    { R[31] = 0x800A0524u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A051C jal */
    R[4] = R[0] + 24;  /* 0x800A0524 */
    R[5] = R[18] + R[0];  /* 0x800A0528 */
    R[6] = R[17] + R[0];  /* 0x800A052C */
    R[7] = R[16] + 1012;  /* 0x800A0530 */
    psx_next = 0x800A0534u; return;  /* fallthrough */
}

void ev_800A050C(void) {
    R[4] = R[0] + 23;  /* 0x800A050C */
    R[5] = R[18] + R[0];  /* 0x800A0510 */
    R[6] = R[17] + R[0];  /* 0x800A0514 */
    R[7] = R[16] + 968;  /* 0x800A0518 */
    { R[31] = 0x800A0524u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A051C jal */
    R[4] = R[0] + 24;  /* 0x800A0524 */
    R[5] = R[18] + R[0];  /* 0x800A0528 */
    R[6] = R[17] + R[0];  /* 0x800A052C */
    R[7] = R[16] + 1012;  /* 0x800A0530 */
    psx_next = 0x800A0534u; return;  /* fallthrough */
}

void ev_800A0524(void) {
    R[4] = R[0] + 24;  /* 0x800A0524 */
    R[5] = R[18] + R[0];  /* 0x800A0528 */
    R[6] = R[17] + R[0];  /* 0x800A052C */
    R[7] = R[16] + 1012;  /* 0x800A0530 */
    psx_next = 0x800A0534u; return;  /* fallthrough */
}

void ev_800A0534(void) {
    { R[31] = 0x800A053Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0534 jal */
    R[19] = R[0] + R[0];  /* 0x800A053C */
    R[23] = 0x6666u << 16;  /* 0x800A0540 */
    R[23] = R[23] | 0x6667;  /* 0x800A0544 */
    R[30] = R[18] + R[0];  /* 0x800A0548 */
    R[9] = 0x800Fu << 16;  /* 0x800A054C */
    R[9] = R[9] + 28800;  /* 0x800A0550 */
    R[22] = R[9] - 88;  /* 0x800A0554 */
    R[18] = 0x800Fu << 16;  /* 0x800A0558 */
    R[18] = R[18] + 28800;  /* 0x800A055C */
    R[21] = R[19] + R[0];  /* 0x800A0560 */
    R[2] = 0x800Fu << 16;  /* 0x800A0564 */
    R[20] = R[2] - 1904;  /* 0x800A0568 */
L_800A056C:;
    R[4] = lh_(R[20] + 2);  /* 0x800A056C */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[23]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0574 */
    R[5] = R[30] + R[0];  /* 0x800A0578 */
    R[6] = 0x800Bu << 16;  /* 0x800A057C */
    R[6] = R[6] + 9412;  /* 0x800A0580 */
    R[7] = R[18] + R[0];  /* 0x800A0584 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0588 */
    R[2] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A058C */
    R[9] = HI;  /* 0x800A0590 */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0594 */
    R[16] = R[16] - R[2];  /* 0x800A0598 */
    R[2] = R[16] << 2;  /* 0x800A059C */
    R[2] = R[2] + R[16];  /* 0x800A05A0 */
    R[2] = R[2] << 1;  /* 0x800A05A4 */
    R[4] = R[4] - R[2];  /* 0x800A05A8 */
    { R[31] = 0x800A05B4u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A05AC jal */
    { int64_t _p = (int64_t)(int32_t)R[16] * (int32_t)R[23]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A05B4 */
    R[5] = R[30] + R[0];  /* 0x800A05B8 */
    R[6] = 0x800Bu << 16;  /* 0x800A05BC */
    R[6] = R[6] + 9412;  /* 0x800A05C0 */
    R[9] = 0x800Fu << 16;  /* 0x800A05C4 */
    R[9] = R[9] + 28800;  /* 0x800A05C8 */
    R[7] = R[9] - 44;  /* 0x800A05CC */
    R[7] = R[21] + R[7];  /* 0x800A05D0 */
    R[2] = (uint32_t)((int32_t)R[16] >> 31);  /* 0x800A05D4 */
    sw_(R[29] + 16, R[0]);  /* 0x800A05D8 */
    R[9] = HI;  /* 0x800A05DC */
    R[17] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A05E0 */
    R[17] = R[17] - R[2];  /* 0x800A05E4 */
    R[2] = R[17] << 2;  /* 0x800A05E8 */
    R[2] = R[2] + R[17];  /* 0x800A05EC */
    R[2] = R[2] << 1;  /* 0x800A05F0 */
    R[16] = R[16] - R[2];  /* 0x800A05F4 */
    { R[31] = 0x800A0600u; R[4] = R[16] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A05F8 jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[23]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0600 */
    R[18] = R[18] + 132;  /* 0x800A0604 */
    R[20] = R[20] + 52;  /* 0x800A0608 */
    R[19] = R[19] + 1;  /* 0x800A060C */
    R[21] = R[21] + 132;  /* 0x800A0610 */
    R[5] = R[30] + R[0];  /* 0x800A0614 */
    R[6] = 0x800Bu << 16;  /* 0x800A0618 */
    R[6] = R[6] + 9412;  /* 0x800A061C */
    R[7] = R[22] + R[0];  /* 0x800A0620 */
    R[22] = R[22] + 132;  /* 0x800A0624 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0628 */
    sw_(R[29] + 16, R[0]);  /* 0x800A062C */
    R[9] = HI;  /* 0x800A0630 */
    R[3] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0634 */
    R[3] = R[3] - R[2];  /* 0x800A0638 */
    R[2] = R[3] << 2;  /* 0x800A063C */
    R[2] = R[2] + R[3];  /* 0x800A0640 */
    R[2] = R[2] << 1;  /* 0x800A0644 */
    R[17] = R[17] - R[2];  /* 0x800A0648 */
    { R[31] = 0x800A0654u; R[4] = R[17] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A064C jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0654 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Fu << 16; if (_c) { psx_bb(); goto L_800A056C; } }  /* 0x800A0658 */
    R[19] = R[0] + R[0];  /* 0x800A0660 */
    R[23] = 0x800Bu << 16;  /* 0x800A0664 */
    R[23] = R[23] + 9412;  /* 0x800A0668 */
    R[20] = 0x6666u << 16;  /* 0x800A066C */
    R[20] = R[20] | 0x6667;  /* 0x800A0670 */
    R[2] = R[2] - 4136;  /* 0x800A0674 */
    R[22] = R[2] - 44;  /* 0x800A0678 */
    R[21] = R[2] + R[0];  /* 0x800A067C */
    R[18] = R[21] + 44;  /* 0x800A0680 */
    R[2] = 0x800Fu << 16;  /* 0x800A0684 */
    R[2] = R[2] - 1904;  /* 0x800A0688 */
    sw_(R[29] + 24, R[0]);  /* 0x800A068C */
    sw_(R[29] + 28, R[2]);  /* 0x800A0690 */
    R[9] = lw_(R[29] + 28);  /* 0x800A0694 */
    R[17] = lw_(R[9] + 8);  /* 0x800A069C */
    R[2] = ((int32_t)R[17] < 100);  /* 0x800A06A4 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[30] + R[0]; if (_c) { goto L_800A06D8; } }  /* 0x800A06A8 */
    R[4] = R[0] + 40;  /* 0x800A06B0 */
    R[6] = R[23] + R[0];  /* 0x800A06B4 */
    R[7] = R[21] + R[0];  /* 0x800A06B8 */
    { R[31] = 0x800A06C4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A06BC jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A06C4 */
    R[5] = R[30] + R[0];  /* 0x800A06C8 */
    R[6] = R[23] + R[0];  /* 0x800A06CC */
    { R[7] = R[18] + R[0]; psx_next = 0x800A0738u; return; }  /* 0x800A06D0 j extern */
L_800A06D8:;
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A06D8 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A06DC */
    R[9] = HI;  /* 0x800A06E0 */
    psx_next = 0x800A06E4u; return;  /* fallthrough */
}

void ev_800A053C(void) {
    R[19] = R[0] + R[0];  /* 0x800A053C */
    R[23] = 0x6666u << 16;  /* 0x800A0540 */
    R[23] = R[23] | 0x6667;  /* 0x800A0544 */
    R[30] = R[18] + R[0];  /* 0x800A0548 */
    R[9] = 0x800Fu << 16;  /* 0x800A054C */
    R[9] = R[9] + 28800;  /* 0x800A0550 */
    R[22] = R[9] - 88;  /* 0x800A0554 */
    R[18] = 0x800Fu << 16;  /* 0x800A0558 */
    R[18] = R[18] + 28800;  /* 0x800A055C */
    R[21] = R[19] + R[0];  /* 0x800A0560 */
    R[2] = 0x800Fu << 16;  /* 0x800A0564 */
    R[20] = R[2] - 1904;  /* 0x800A0568 */
L_800A056C:;
    R[4] = lh_(R[20] + 2);  /* 0x800A056C */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[23]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0574 */
    R[5] = R[30] + R[0];  /* 0x800A0578 */
    R[6] = 0x800Bu << 16;  /* 0x800A057C */
    R[6] = R[6] + 9412;  /* 0x800A0580 */
    R[7] = R[18] + R[0];  /* 0x800A0584 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0588 */
    R[2] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A058C */
    R[9] = HI;  /* 0x800A0590 */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0594 */
    R[16] = R[16] - R[2];  /* 0x800A0598 */
    R[2] = R[16] << 2;  /* 0x800A059C */
    R[2] = R[2] + R[16];  /* 0x800A05A0 */
    R[2] = R[2] << 1;  /* 0x800A05A4 */
    R[4] = R[4] - R[2];  /* 0x800A05A8 */
    { R[31] = 0x800A05B4u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A05AC jal */
    { int64_t _p = (int64_t)(int32_t)R[16] * (int32_t)R[23]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A05B4 */
    R[5] = R[30] + R[0];  /* 0x800A05B8 */
    R[6] = 0x800Bu << 16;  /* 0x800A05BC */
    R[6] = R[6] + 9412;  /* 0x800A05C0 */
    R[9] = 0x800Fu << 16;  /* 0x800A05C4 */
    R[9] = R[9] + 28800;  /* 0x800A05C8 */
    R[7] = R[9] - 44;  /* 0x800A05CC */
    R[7] = R[21] + R[7];  /* 0x800A05D0 */
    R[2] = (uint32_t)((int32_t)R[16] >> 31);  /* 0x800A05D4 */
    sw_(R[29] + 16, R[0]);  /* 0x800A05D8 */
    R[9] = HI;  /* 0x800A05DC */
    R[17] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A05E0 */
    R[17] = R[17] - R[2];  /* 0x800A05E4 */
    R[2] = R[17] << 2;  /* 0x800A05E8 */
    R[2] = R[2] + R[17];  /* 0x800A05EC */
    R[2] = R[2] << 1;  /* 0x800A05F0 */
    R[16] = R[16] - R[2];  /* 0x800A05F4 */
    { R[31] = 0x800A0600u; R[4] = R[16] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A05F8 jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[23]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0600 */
    R[18] = R[18] + 132;  /* 0x800A0604 */
    R[20] = R[20] + 52;  /* 0x800A0608 */
    R[19] = R[19] + 1;  /* 0x800A060C */
    R[21] = R[21] + 132;  /* 0x800A0610 */
    R[5] = R[30] + R[0];  /* 0x800A0614 */
    R[6] = 0x800Bu << 16;  /* 0x800A0618 */
    R[6] = R[6] + 9412;  /* 0x800A061C */
    R[7] = R[22] + R[0];  /* 0x800A0620 */
    R[22] = R[22] + 132;  /* 0x800A0624 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0628 */
    sw_(R[29] + 16, R[0]);  /* 0x800A062C */
    R[9] = HI;  /* 0x800A0630 */
    R[3] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0634 */
    R[3] = R[3] - R[2];  /* 0x800A0638 */
    R[2] = R[3] << 2;  /* 0x800A063C */
    R[2] = R[2] + R[3];  /* 0x800A0640 */
    R[2] = R[2] << 1;  /* 0x800A0644 */
    R[17] = R[17] - R[2];  /* 0x800A0648 */
    { R[31] = 0x800A0654u; R[4] = R[17] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A064C jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0654 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Fu << 16; if (_c) { psx_bb(); goto L_800A056C; } }  /* 0x800A0658 */
    R[19] = R[0] + R[0];  /* 0x800A0660 */
    R[23] = 0x800Bu << 16;  /* 0x800A0664 */
    R[23] = R[23] + 9412;  /* 0x800A0668 */
    R[20] = 0x6666u << 16;  /* 0x800A066C */
    R[20] = R[20] | 0x6667;  /* 0x800A0670 */
    R[2] = R[2] - 4136;  /* 0x800A0674 */
    R[22] = R[2] - 44;  /* 0x800A0678 */
    R[21] = R[2] + R[0];  /* 0x800A067C */
    R[18] = R[21] + 44;  /* 0x800A0680 */
    R[2] = 0x800Fu << 16;  /* 0x800A0684 */
    R[2] = R[2] - 1904;  /* 0x800A0688 */
    sw_(R[29] + 24, R[0]);  /* 0x800A068C */
    sw_(R[29] + 28, R[2]);  /* 0x800A0690 */
    R[9] = lw_(R[29] + 28);  /* 0x800A0694 */
    R[17] = lw_(R[9] + 8);  /* 0x800A069C */
    R[2] = ((int32_t)R[17] < 100);  /* 0x800A06A4 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[30] + R[0]; if (_c) { goto L_800A06D8; } }  /* 0x800A06A8 */
    R[4] = R[0] + 40;  /* 0x800A06B0 */
    R[6] = R[23] + R[0];  /* 0x800A06B4 */
    R[7] = R[21] + R[0];  /* 0x800A06B8 */
    { R[31] = 0x800A06C4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A06BC jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A06C4 */
    R[5] = R[30] + R[0];  /* 0x800A06C8 */
    R[6] = R[23] + R[0];  /* 0x800A06CC */
    { R[7] = R[18] + R[0]; psx_next = 0x800A0738u; return; }  /* 0x800A06D0 j extern */
L_800A06D8:;
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A06D8 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A06DC */
    R[9] = HI;  /* 0x800A06E0 */
    psx_next = 0x800A06E4u; return;  /* fallthrough */
}

void ev_800A056C(void) {
L_800A056C:;
    R[4] = lh_(R[20] + 2);  /* 0x800A056C */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[23]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0574 */
    R[5] = R[30] + R[0];  /* 0x800A0578 */
    R[6] = 0x800Bu << 16;  /* 0x800A057C */
    R[6] = R[6] + 9412;  /* 0x800A0580 */
    R[7] = R[18] + R[0];  /* 0x800A0584 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0588 */
    R[2] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A058C */
    R[9] = HI;  /* 0x800A0590 */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0594 */
    R[16] = R[16] - R[2];  /* 0x800A0598 */
    R[2] = R[16] << 2;  /* 0x800A059C */
    R[2] = R[2] + R[16];  /* 0x800A05A0 */
    R[2] = R[2] << 1;  /* 0x800A05A4 */
    R[4] = R[4] - R[2];  /* 0x800A05A8 */
    { R[31] = 0x800A05B4u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A05AC jal */
    { int64_t _p = (int64_t)(int32_t)R[16] * (int32_t)R[23]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A05B4 */
    R[5] = R[30] + R[0];  /* 0x800A05B8 */
    R[6] = 0x800Bu << 16;  /* 0x800A05BC */
    R[6] = R[6] + 9412;  /* 0x800A05C0 */
    R[9] = 0x800Fu << 16;  /* 0x800A05C4 */
    R[9] = R[9] + 28800;  /* 0x800A05C8 */
    R[7] = R[9] - 44;  /* 0x800A05CC */
    R[7] = R[21] + R[7];  /* 0x800A05D0 */
    R[2] = (uint32_t)((int32_t)R[16] >> 31);  /* 0x800A05D4 */
    sw_(R[29] + 16, R[0]);  /* 0x800A05D8 */
    R[9] = HI;  /* 0x800A05DC */
    R[17] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A05E0 */
    R[17] = R[17] - R[2];  /* 0x800A05E4 */
    R[2] = R[17] << 2;  /* 0x800A05E8 */
    R[2] = R[2] + R[17];  /* 0x800A05EC */
    R[2] = R[2] << 1;  /* 0x800A05F0 */
    R[16] = R[16] - R[2];  /* 0x800A05F4 */
    { R[31] = 0x800A0600u; R[4] = R[16] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A05F8 jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[23]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0600 */
    R[18] = R[18] + 132;  /* 0x800A0604 */
    R[20] = R[20] + 52;  /* 0x800A0608 */
    R[19] = R[19] + 1;  /* 0x800A060C */
    R[21] = R[21] + 132;  /* 0x800A0610 */
    R[5] = R[30] + R[0];  /* 0x800A0614 */
    R[6] = 0x800Bu << 16;  /* 0x800A0618 */
    R[6] = R[6] + 9412;  /* 0x800A061C */
    R[7] = R[22] + R[0];  /* 0x800A0620 */
    R[22] = R[22] + 132;  /* 0x800A0624 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0628 */
    sw_(R[29] + 16, R[0]);  /* 0x800A062C */
    R[9] = HI;  /* 0x800A0630 */
    R[3] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0634 */
    R[3] = R[3] - R[2];  /* 0x800A0638 */
    R[2] = R[3] << 2;  /* 0x800A063C */
    R[2] = R[2] + R[3];  /* 0x800A0640 */
    R[2] = R[2] << 1;  /* 0x800A0644 */
    R[17] = R[17] - R[2];  /* 0x800A0648 */
    { R[31] = 0x800A0654u; R[4] = R[17] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A064C jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0654 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Fu << 16; if (_c) { psx_bb(); goto L_800A056C; } }  /* 0x800A0658 */
    R[19] = R[0] + R[0];  /* 0x800A0660 */
    R[23] = 0x800Bu << 16;  /* 0x800A0664 */
    R[23] = R[23] + 9412;  /* 0x800A0668 */
    R[20] = 0x6666u << 16;  /* 0x800A066C */
    R[20] = R[20] | 0x6667;  /* 0x800A0670 */
    R[2] = R[2] - 4136;  /* 0x800A0674 */
    R[22] = R[2] - 44;  /* 0x800A0678 */
    R[21] = R[2] + R[0];  /* 0x800A067C */
    R[18] = R[21] + 44;  /* 0x800A0680 */
    R[2] = 0x800Fu << 16;  /* 0x800A0684 */
    R[2] = R[2] - 1904;  /* 0x800A0688 */
    sw_(R[29] + 24, R[0]);  /* 0x800A068C */
    sw_(R[29] + 28, R[2]);  /* 0x800A0690 */
    R[9] = lw_(R[29] + 28);  /* 0x800A0694 */
    R[17] = lw_(R[9] + 8);  /* 0x800A069C */
    R[2] = ((int32_t)R[17] < 100);  /* 0x800A06A4 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[30] + R[0]; if (_c) { goto L_800A06D8; } }  /* 0x800A06A8 */
    R[4] = R[0] + 40;  /* 0x800A06B0 */
    R[6] = R[23] + R[0];  /* 0x800A06B4 */
    R[7] = R[21] + R[0];  /* 0x800A06B8 */
    { R[31] = 0x800A06C4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A06BC jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A06C4 */
    R[5] = R[30] + R[0];  /* 0x800A06C8 */
    R[6] = R[23] + R[0];  /* 0x800A06CC */
    { R[7] = R[18] + R[0]; psx_next = 0x800A0738u; return; }  /* 0x800A06D0 j extern */
L_800A06D8:;
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A06D8 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A06DC */
    R[9] = HI;  /* 0x800A06E0 */
    psx_next = 0x800A06E4u; return;  /* fallthrough */
}

void ev_800A05B4(void) {
    { int64_t _p = (int64_t)(int32_t)R[16] * (int32_t)R[23]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A05B4 */
    R[5] = R[30] + R[0];  /* 0x800A05B8 */
    R[6] = 0x800Bu << 16;  /* 0x800A05BC */
    R[6] = R[6] + 9412;  /* 0x800A05C0 */
    R[9] = 0x800Fu << 16;  /* 0x800A05C4 */
    R[9] = R[9] + 28800;  /* 0x800A05C8 */
    R[7] = R[9] - 44;  /* 0x800A05CC */
    R[7] = R[21] + R[7];  /* 0x800A05D0 */
    R[2] = (uint32_t)((int32_t)R[16] >> 31);  /* 0x800A05D4 */
    sw_(R[29] + 16, R[0]);  /* 0x800A05D8 */
    R[9] = HI;  /* 0x800A05DC */
    R[17] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A05E0 */
    R[17] = R[17] - R[2];  /* 0x800A05E4 */
    R[2] = R[17] << 2;  /* 0x800A05E8 */
    R[2] = R[2] + R[17];  /* 0x800A05EC */
    R[2] = R[2] << 1;  /* 0x800A05F0 */
    R[16] = R[16] - R[2];  /* 0x800A05F4 */
    { R[31] = 0x800A0600u; R[4] = R[16] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A05F8 jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[23]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0600 */
    R[18] = R[18] + 132;  /* 0x800A0604 */
    R[20] = R[20] + 52;  /* 0x800A0608 */
    R[19] = R[19] + 1;  /* 0x800A060C */
    R[21] = R[21] + 132;  /* 0x800A0610 */
    R[5] = R[30] + R[0];  /* 0x800A0614 */
    R[6] = 0x800Bu << 16;  /* 0x800A0618 */
    R[6] = R[6] + 9412;  /* 0x800A061C */
    R[7] = R[22] + R[0];  /* 0x800A0620 */
    R[22] = R[22] + 132;  /* 0x800A0624 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0628 */
    sw_(R[29] + 16, R[0]);  /* 0x800A062C */
    R[9] = HI;  /* 0x800A0630 */
    R[3] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0634 */
    R[3] = R[3] - R[2];  /* 0x800A0638 */
    R[2] = R[3] << 2;  /* 0x800A063C */
    R[2] = R[2] + R[3];  /* 0x800A0640 */
    R[2] = R[2] << 1;  /* 0x800A0644 */
    R[17] = R[17] - R[2];  /* 0x800A0648 */
    { R[31] = 0x800A0654u; R[4] = R[17] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A064C jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0654 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Fu << 16; if (_c) { psx_next = 0x800A056Cu; return; } }  /* 0x800A0658 b extern */
    R[19] = R[0] + R[0];  /* 0x800A0660 */
    R[23] = 0x800Bu << 16;  /* 0x800A0664 */
    R[23] = R[23] + 9412;  /* 0x800A0668 */
    R[20] = 0x6666u << 16;  /* 0x800A066C */
    R[20] = R[20] | 0x6667;  /* 0x800A0670 */
    R[2] = R[2] - 4136;  /* 0x800A0674 */
    R[22] = R[2] - 44;  /* 0x800A0678 */
    R[21] = R[2] + R[0];  /* 0x800A067C */
    R[18] = R[21] + 44;  /* 0x800A0680 */
    R[2] = 0x800Fu << 16;  /* 0x800A0684 */
    R[2] = R[2] - 1904;  /* 0x800A0688 */
    sw_(R[29] + 24, R[0]);  /* 0x800A068C */
    sw_(R[29] + 28, R[2]);  /* 0x800A0690 */
    R[9] = lw_(R[29] + 28);  /* 0x800A0694 */
    R[17] = lw_(R[9] + 8);  /* 0x800A069C */
    R[2] = ((int32_t)R[17] < 100);  /* 0x800A06A4 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[30] + R[0]; if (_c) { goto L_800A06D8; } }  /* 0x800A06A8 */
    R[4] = R[0] + 40;  /* 0x800A06B0 */
    R[6] = R[23] + R[0];  /* 0x800A06B4 */
    R[7] = R[21] + R[0];  /* 0x800A06B8 */
    { R[31] = 0x800A06C4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A06BC jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A06C4 */
    R[5] = R[30] + R[0];  /* 0x800A06C8 */
    R[6] = R[23] + R[0];  /* 0x800A06CC */
    { R[7] = R[18] + R[0]; psx_next = 0x800A0738u; return; }  /* 0x800A06D0 j extern */
L_800A06D8:;
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A06D8 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A06DC */
    R[9] = HI;  /* 0x800A06E0 */
    psx_next = 0x800A06E4u; return;  /* fallthrough */
}

void ev_800A0600(void) {
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[23]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0600 */
    R[18] = R[18] + 132;  /* 0x800A0604 */
    R[20] = R[20] + 52;  /* 0x800A0608 */
    R[19] = R[19] + 1;  /* 0x800A060C */
    R[21] = R[21] + 132;  /* 0x800A0610 */
    R[5] = R[30] + R[0];  /* 0x800A0614 */
    R[6] = 0x800Bu << 16;  /* 0x800A0618 */
    R[6] = R[6] + 9412;  /* 0x800A061C */
    R[7] = R[22] + R[0];  /* 0x800A0620 */
    R[22] = R[22] + 132;  /* 0x800A0624 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0628 */
    sw_(R[29] + 16, R[0]);  /* 0x800A062C */
    R[9] = HI;  /* 0x800A0630 */
    R[3] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0634 */
    R[3] = R[3] - R[2];  /* 0x800A0638 */
    R[2] = R[3] << 2;  /* 0x800A063C */
    R[2] = R[2] + R[3];  /* 0x800A0640 */
    R[2] = R[2] << 1;  /* 0x800A0644 */
    R[17] = R[17] - R[2];  /* 0x800A0648 */
    { R[31] = 0x800A0654u; R[4] = R[17] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A064C jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0654 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Fu << 16; if (_c) { psx_next = 0x800A056Cu; return; } }  /* 0x800A0658 b extern */
    R[19] = R[0] + R[0];  /* 0x800A0660 */
    R[23] = 0x800Bu << 16;  /* 0x800A0664 */
    R[23] = R[23] + 9412;  /* 0x800A0668 */
    R[20] = 0x6666u << 16;  /* 0x800A066C */
    R[20] = R[20] | 0x6667;  /* 0x800A0670 */
    R[2] = R[2] - 4136;  /* 0x800A0674 */
    R[22] = R[2] - 44;  /* 0x800A0678 */
    R[21] = R[2] + R[0];  /* 0x800A067C */
    R[18] = R[21] + 44;  /* 0x800A0680 */
    R[2] = 0x800Fu << 16;  /* 0x800A0684 */
    R[2] = R[2] - 1904;  /* 0x800A0688 */
    sw_(R[29] + 24, R[0]);  /* 0x800A068C */
    sw_(R[29] + 28, R[2]);  /* 0x800A0690 */
    R[9] = lw_(R[29] + 28);  /* 0x800A0694 */
    R[17] = lw_(R[9] + 8);  /* 0x800A069C */
    R[2] = ((int32_t)R[17] < 100);  /* 0x800A06A4 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[30] + R[0]; if (_c) { goto L_800A06D8; } }  /* 0x800A06A8 */
    R[4] = R[0] + 40;  /* 0x800A06B0 */
    R[6] = R[23] + R[0];  /* 0x800A06B4 */
    R[7] = R[21] + R[0];  /* 0x800A06B8 */
    { R[31] = 0x800A06C4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A06BC jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A06C4 */
    R[5] = R[30] + R[0];  /* 0x800A06C8 */
    R[6] = R[23] + R[0];  /* 0x800A06CC */
    { R[7] = R[18] + R[0]; psx_next = 0x800A0738u; return; }  /* 0x800A06D0 j extern */
L_800A06D8:;
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A06D8 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A06DC */
    R[9] = HI;  /* 0x800A06E0 */
    psx_next = 0x800A06E4u; return;  /* fallthrough */
}

void ev_800A0654(void) {
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0654 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Fu << 16; if (_c) { psx_next = 0x800A056Cu; return; } }  /* 0x800A0658 b extern */
    R[19] = R[0] + R[0];  /* 0x800A0660 */
    R[23] = 0x800Bu << 16;  /* 0x800A0664 */
    R[23] = R[23] + 9412;  /* 0x800A0668 */
    R[20] = 0x6666u << 16;  /* 0x800A066C */
    R[20] = R[20] | 0x6667;  /* 0x800A0670 */
    R[2] = R[2] - 4136;  /* 0x800A0674 */
    R[22] = R[2] - 44;  /* 0x800A0678 */
    R[21] = R[2] + R[0];  /* 0x800A067C */
    R[18] = R[21] + 44;  /* 0x800A0680 */
    R[2] = 0x800Fu << 16;  /* 0x800A0684 */
    R[2] = R[2] - 1904;  /* 0x800A0688 */
    sw_(R[29] + 24, R[0]);  /* 0x800A068C */
    sw_(R[29] + 28, R[2]);  /* 0x800A0690 */
    R[9] = lw_(R[29] + 28);  /* 0x800A0694 */
    R[17] = lw_(R[9] + 8);  /* 0x800A069C */
    R[2] = ((int32_t)R[17] < 100);  /* 0x800A06A4 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[30] + R[0]; if (_c) { goto L_800A06D8; } }  /* 0x800A06A8 */
    R[4] = R[0] + 40;  /* 0x800A06B0 */
    R[6] = R[23] + R[0];  /* 0x800A06B4 */
    R[7] = R[21] + R[0];  /* 0x800A06B8 */
    { R[31] = 0x800A06C4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A06BC jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A06C4 */
    R[5] = R[30] + R[0];  /* 0x800A06C8 */
    R[6] = R[23] + R[0];  /* 0x800A06CC */
    { R[7] = R[18] + R[0]; psx_next = 0x800A0738u; return; }  /* 0x800A06D0 j extern */
L_800A06D8:;
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A06D8 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A06DC */
    R[9] = HI;  /* 0x800A06E0 */
    psx_next = 0x800A06E4u; return;  /* fallthrough */
}

void ev_800A0694(void) {
    R[9] = lw_(R[29] + 28);  /* 0x800A0694 */
    R[17] = lw_(R[9] + 8);  /* 0x800A069C */
    R[2] = ((int32_t)R[17] < 100);  /* 0x800A06A4 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[30] + R[0]; if (_c) { goto L_800A06D8; } }  /* 0x800A06A8 */
    R[4] = R[0] + 40;  /* 0x800A06B0 */
    R[6] = R[23] + R[0];  /* 0x800A06B4 */
    R[7] = R[21] + R[0];  /* 0x800A06B8 */
    { R[31] = 0x800A06C4u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A06BC jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A06C4 */
    R[5] = R[30] + R[0];  /* 0x800A06C8 */
    R[6] = R[23] + R[0];  /* 0x800A06CC */
    { R[7] = R[18] + R[0]; psx_next = 0x800A0738u; return; }  /* 0x800A06D0 j extern */
L_800A06D8:;
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A06D8 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A06DC */
    R[9] = HI;  /* 0x800A06E0 */
    psx_next = 0x800A06E4u; return;  /* fallthrough */
}

void ev_800A06C4(void) {
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A06C4 */
    R[5] = R[30] + R[0];  /* 0x800A06C8 */
    R[6] = R[23] + R[0];  /* 0x800A06CC */
    { R[7] = R[18] + R[0]; psx_next = 0x800A0738u; return; }  /* 0x800A06D0 j extern */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A06D8 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A06DC */
    R[9] = HI;  /* 0x800A06E0 */
    psx_next = 0x800A06E4u; return;  /* fallthrough */
}

void ev_800A06E4(void) {
    R[3] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A06E4 */
    R[17] = R[3] - R[2];  /* 0x800A06E8 */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A06EC */
    R[6] = R[23] + R[0];  /* 0x800A06F0 */
    R[7] = R[18] + R[0];  /* 0x800A06F4 */
    sw_(R[29] + 16, R[0]);  /* 0x800A06F8 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A06FC */
    R[9] = HI;  /* 0x800A0700 */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0704 */
    R[16] = R[16] - R[2];  /* 0x800A0708 */
    R[4] = R[16] << 2;  /* 0x800A070C */
    R[4] = R[4] + R[16];  /* 0x800A0710 */
    R[4] = R[4] << 1;  /* 0x800A0714 */
    R[4] = R[17] - R[4];  /* 0x800A0718 */
    { R[31] = 0x800A0724u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A071C jal */
    R[17] = R[16] + R[0];  /* 0x800A0724 */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0728 */
    R[5] = R[30] + R[0];  /* 0x800A072C */
    R[6] = R[23] + R[0];  /* 0x800A0730 */
    R[7] = R[21] + R[0];  /* 0x800A0734 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0738 */
    sw_(R[29] + 16, R[0]);  /* 0x800A073C */
    R[9] = HI;  /* 0x800A0740 */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0744 */
    R[16] = R[16] - R[2];  /* 0x800A0748 */
    R[4] = R[16] << 2;  /* 0x800A074C */
    R[4] = R[4] + R[16];  /* 0x800A0750 */
    R[4] = R[4] << 1;  /* 0x800A0754 */
    R[4] = R[17] - R[4];  /* 0x800A0758 */
    { R[31] = 0x800A0764u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A075C jal */
    R[17] = R[16] + R[0];  /* 0x800A0764 */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0768 */
    R[5] = R[30] + R[0];  /* 0x800A076C */
    R[6] = R[23] + R[0];  /* 0x800A0770 */
    R[7] = R[22] + R[0];  /* 0x800A0774 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0778 */
    sw_(R[29] + 16, R[0]);  /* 0x800A077C */
    R[9] = HI;  /* 0x800A0780 */
    R[3] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0784 */
    R[3] = R[3] - R[2];  /* 0x800A0788 */
    R[4] = R[3] << 2;  /* 0x800A078C */
    R[4] = R[4] + R[3];  /* 0x800A0790 */
    R[4] = R[4] << 1;  /* 0x800A0794 */
    R[4] = R[17] - R[4];  /* 0x800A0798 */
    { R[31] = 0x800A07A4u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A079C jal */
    R[4] = R[0] + 29;  /* 0x800A07A4 */
    R[9] = 0x800Bu << 16;  /* 0x800A07A8 */
    R[5] = R[9] + 10840;  /* 0x800A07AC */
    R[9] = 0x800Bu << 16;  /* 0x800A07B0 */
    R[6] = R[9] + 9412;  /* 0x800A07B4 */
    R[7] = 0x800Fu << 16;  /* 0x800A07B8 */
    R[9] = lw_(R[29] + 24);  /* 0x800A07BC */
    R[7] = R[7] - 4224;  /* 0x800A07C0 */
    sw_(R[29] + 16, R[0]);  /* 0x800A07C4 */
    { R[31] = 0x800A07D0u; R[7] = R[9] + R[7]; psx_next = 0x8009A380u; return; }  /* 0x800A07C8 jal */
    R[22] = R[22] + 176;  /* 0x800A07D0 */
    R[21] = R[21] + 176;  /* 0x800A07D4 */
    R[18] = R[18] + 176;  /* 0x800A07D8 */
    R[9] = lw_(R[29] + 24);  /* 0x800A07DC */
    R[19] = R[19] + 1;  /* 0x800A07E0 */
    R[9] = R[9] + 176;  /* 0x800A07E4 */
    sw_(R[29] + 24, R[9]);  /* 0x800A07E8 */
    R[9] = lw_(R[29] + 28);  /* 0x800A07EC */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A07F0 */
    R[9] = R[9] + 52;  /* 0x800A07F4 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[29] + 28, R[9]); if (_c) { psx_next = 0x800A0694u; return; } }  /* 0x800A07F8 b extern */
    R[19] = R[0] + R[0];  /* 0x800A0800 */
    R[2] = 0x800Bu << 16;  /* 0x800A0804 */
    R[22] = R[2] + 10840;  /* 0x800A0808 */
    R[2] = 0x800Bu << 16;  /* 0x800A080C */
    R[21] = R[2] + 9412;  /* 0x800A0810 */
    R[2] = 0x800Fu << 16;  /* 0x800A0814 */
    R[20] = R[2] - 4632;  /* 0x800A0818 */
    R[18] = R[19] + R[0];  /* 0x800A081C */
    R[2] = 0x800Fu << 16;  /* 0x800A0820 */
    R[17] = R[2] - 1904;  /* 0x800A0824 */
L_800A0828:;
    R[5] = R[22] + R[0];  /* 0x800A0828 */
    R[6] = R[21] + R[0];  /* 0x800A082C */
    R[7] = R[20] + R[0];  /* 0x800A0830 */
    R[20] = R[20] + 44;  /* 0x800A0834 */
    R[16] = lb_(R[17]);  /* 0x800A0838 */
    R[17] = R[17] + 52;  /* 0x800A083C */
    R[19] = R[19] + 1;  /* 0x800A0840 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0844 */
    { R[31] = 0x800A0850u; R[4] = R[16] + 41; psx_next = 0x8009A380u; return; }  /* 0x800A0848 jal */
    R[4] = R[16] + 91;  /* 0x800A0850 */
    R[5] = R[22] + R[0];  /* 0x800A0854 */
    R[6] = R[21] + R[0];  /* 0x800A0858 */
    R[7] = 0x800Fu << 16;  /* 0x800A085C */
    R[7] = R[7] - 1384;  /* 0x800A0860 */
    R[7] = R[18] + R[7];  /* 0x800A0864 */
    { R[31] = 0x800A0870u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0868 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0870 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 44; if (_c) { psx_bb(); goto L_800A0828; } }  /* 0x800A0874 */
    R[19] = R[0] + R[0];  /* 0x800A087C */
    R[2] = 0x800Fu << 16;  /* 0x800A0880 */
    R[18] = R[2] - 2296;  /* 0x800A0884 */
    R[2] = 0x800Fu << 16;  /* 0x800A0888 */
    R[17] = R[2] - 1904;  /* 0x800A088C */
L_800A0890:;
    R[16] = lb_(R[17] + 12);  /* 0x800A0890 */
    { R[31] = 0x800A089Cu; R[17] = R[17] + 52; psx_next = 0x80030E88u; return; }  /* 0x800A0894 jal */
    R[3] = 0x5555u << 16;  /* 0x800A089C */
    R[3] = R[3] | 0x5556;  /* 0x800A08A0 */
    R[5] = 0x800Bu << 16;  /* 0x800A08A4 */
    R[5] = R[5] + 10840;  /* 0x800A08A8 */
    R[6] = 0x800Bu << 16;  /* 0x800A08AC */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A08B0 */
    R[6] = R[6] + 9412;  /* 0x800A08B4 */
    R[7] = R[18] + R[0];  /* 0x800A08B8 */
    R[18] = R[18] + 44;  /* 0x800A08BC */
    R[19] = R[19] + 1;  /* 0x800A08C0 */
    R[3] = R[0] + 9;  /* 0x800A08C4 */
    R[4] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x800A08C8 */
    sw_(R[29] + 16, R[0]);  /* 0x800A08CC */
    R[3] = R[3] - R[16];  /* 0x800A08D0 */
    R[8] = R[3] << 1;  /* 0x800A08D4 */
    R[8] = R[8] + R[3];  /* 0x800A08D8 */
    R[9] = HI;  /* 0x800A08DC */
    R[4] = R[9] - R[4];  /* 0x800A08E0 */
    R[3] = R[4] << 1;  /* 0x800A08E4 */
    R[3] = R[3] + R[4];  /* 0x800A08E8 */
    R[2] = R[2] - R[3];  /* 0x800A08EC */
    R[16] = R[8] + R[2];  /* 0x800A08F0 */
    { R[31] = 0x800A08FCu; R[4] = R[16] + 61; psx_next = 0x8009A380u; return; }  /* 0x800A08F4 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A08FC */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Fu << 16; if (_c) { psx_bb(); goto L_800A0890; } }  /* 0x800A0900 */
    R[19] = R[0] + R[0];  /* 0x800A0908 */
    R[17] = R[2] - 720;  /* 0x800A090C */
    R[2] = 0x800Fu << 16;  /* 0x800A0910 */
    R[16] = R[2] - 1904;  /* 0x800A0914 */
    R[5] = 0x800Bu << 16;  /* 0x800A0918 */
L_800A091C:;
    R[5] = R[5] + 10840;  /* 0x800A091C */
    R[6] = 0x800Bu << 16;  /* 0x800A0920 */
    R[6] = R[6] + 9412;  /* 0x800A0924 */
    R[7] = R[17] + R[0];  /* 0x800A0928 */
    R[17] = R[17] + 44;  /* 0x800A092C */
    R[4] = lb_(R[16] + 13);  /* 0x800A0930 */
    R[16] = R[16] + 52;  /* 0x800A0934 */
    R[19] = R[19] + 1;  /* 0x800A0938 */
    sw_(R[29] + 16, R[0]);  /* 0x800A093C */
    { R[31] = 0x800A0948u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0940 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0948 */
    { uint32_t _c = (R[2] != R[0]); R[5] = 0x800Bu << 16; if (_c) { psx_bb(); goto L_800A091C; } }  /* 0x800A094C */
    R[19] = R[0] + R[0];  /* 0x800A0954 */
    R[2] = 0x800Fu << 16;  /* 0x800A0958 */
    R[17] = R[2] + 27976;  /* 0x800A095C */
    R[2] = 0x800Fu << 16;  /* 0x800A0960 */
    R[16] = R[2] - 1904;  /* 0x800A0964 */
L_800A0968:;
    R[5] = R[5] + 10840;  /* 0x800A0968 */
    R[6] = 0x800Bu << 16;  /* 0x800A096C */
    R[6] = R[6] + 9412;  /* 0x800A0970 */
    R[7] = R[17] + R[0];  /* 0x800A0974 */
    R[17] = R[17] + 44;  /* 0x800A0978 */
    R[4] = lb_(R[16] + 14);  /* 0x800A097C */
    R[16] = R[16] + 52;  /* 0x800A0980 */
    R[19] = R[19] + 1;  /* 0x800A0984 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0988 */
    { R[31] = 0x800A0994u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A098C jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0994 */
    { uint32_t _c = (R[2] != R[0]); R[5] = 0x800Bu << 16; if (_c) { psx_bb(); goto L_800A0968; } }  /* 0x800A0998 */
    R[19] = R[0] + R[0];  /* 0x800A09A0 */
    R[2] = 0x800Fu << 16;  /* 0x800A09A4 */
    R[17] = R[2] - 2816;  /* 0x800A09A8 */
    R[2] = 0x800Fu << 16;  /* 0x800A09AC */
    R[16] = R[2] - 1904;  /* 0x800A09B0 */
L_800A09B4:;
    R[5] = R[5] + 10840;  /* 0x800A09B4 */
    R[6] = 0x800Bu << 16;  /* 0x800A09B8 */
    R[6] = R[6] + 9412;  /* 0x800A09BC */
    R[7] = R[17] + R[0];  /* 0x800A09C0 */
    R[17] = R[17] + 44;  /* 0x800A09C4 */
    R[4] = lb_(R[16] + 16);  /* 0x800A09C8 */
    R[16] = R[16] + 52;  /* 0x800A09CC */
    R[19] = R[19] + 1;  /* 0x800A09D0 */
    sw_(R[29] + 16, R[0]);  /* 0x800A09D4 */
    { R[31] = 0x800A09E0u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A09D8 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A09E0 */
    { uint32_t _c = (R[2] != R[0]); R[5] = 0x800Bu << 16; if (_c) { psx_bb(); goto L_800A09B4; } }  /* 0x800A09E4 */
    R[19] = R[0] + R[0];  /* 0x800A09EC */
    R[2] = 0x800Fu << 16;  /* 0x800A09F0 */
    R[16] = R[2] + 312;  /* 0x800A09F4 */
    R[2] = 0x800Fu << 16;  /* 0x800A09F8 */
    R[18] = R[2] - 1904;  /* 0x800A09FC */
L_800A0A00:;
    R[17] = 0x800Bu << 16;  /* 0x800A0A00 */
    R[5] = R[17] + 10840;  /* 0x800A0A04 */
    R[20] = 0x800Bu << 16;  /* 0x800A0A08 */
    R[6] = R[20] + 9412;  /* 0x800A0A0C */
    R[7] = R[16] + R[0];  /* 0x800A0A10 */
    R[16] = R[16] + 44;  /* 0x800A0A14 */
    R[4] = lb_(R[18] + 15);  /* 0x800A0A18 */
    R[18] = R[18] + 52;  /* 0x800A0A1C */
    R[19] = R[19] + 1;  /* 0x800A0A20 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0A24 */
    { R[31] = 0x800A0A30u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0A28 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0A30 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 10840; if (_c) { psx_bb(); goto L_800A0A00; } }  /* 0x800A0A34 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0A3C */
    R[4] = R[0] + 117;  /* 0x800A0A40 */
    R[5] = R[17] + R[0];  /* 0x800A0A44 */
    R[16] = R[20] + 9412;  /* 0x800A0A48 */
    R[6] = R[16] + R[0];  /* 0x800A0A4C */
    R[7] = 0x800Fu << 16;  /* 0x800A0A50 */
    { R[31] = 0x800A0A5Cu; R[7] = R[7] + 25664; psx_next = 0x8009A380u; return; }  /* 0x800A0A54 jal */
    R[19] = R[0] + R[0];  /* 0x800A0A5C */
    R[18] = 0x6666u << 16;  /* 0x800A0A60 */
    R[18] = R[18] | 0x6667;  /* 0x800A0A64 */
    R[20] = R[17] + R[0];  /* 0x800A0A68 */
    R[21] = R[16] + R[0];  /* 0x800A0A6C */
    R[2] = 0x800Fu << 16;  /* 0x800A0A70 */
    R[22] = R[2] - 148;  /* 0x800A0A74 */
    R[2] = 0x8006u << 16;  /* 0x800A0A78 */
    R[4] = lw_(R[2] + 16068);  /* 0x800A0A7C */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0A84 */
    R[5] = R[20] + R[0];  /* 0x800A0A88 */
    R[6] = R[21] + R[0];  /* 0x800A0A8C */
    R[7] = R[22] + R[0];  /* 0x800A0A90 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0A94 */
    R[2] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A0A98 */
    R[9] = HI;  /* 0x800A0A9C */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0AA0 */
    R[16] = R[16] - R[2];  /* 0x800A0AA4 */
    R[2] = R[16] << 2;  /* 0x800A0AA8 */
    R[2] = R[2] + R[16];  /* 0x800A0AAC */
    R[2] = R[2] << 1;  /* 0x800A0AB0 */
    R[4] = R[4] - R[2];  /* 0x800A0AB4 */
    { R[31] = 0x800A0AC0u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0AB8 jal */
    { int64_t _p = (int64_t)(int32_t)R[16] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0AC0 */
    R[5] = R[20] + R[0];  /* 0x800A0AC4 */
    R[6] = R[21] + R[0];  /* 0x800A0AC8 */
    R[7] = R[22] - 44;  /* 0x800A0ACC */
    R[2] = (uint32_t)((int32_t)R[16] >> 31);  /* 0x800A0AD0 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0AD4 */
    R[9] = HI;  /* 0x800A0AD8 */
    R[17] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0ADC */
    R[17] = R[17] - R[2];  /* 0x800A0AE0 */
    R[2] = R[17] << 2;  /* 0x800A0AE4 */
    R[2] = R[2] + R[17];  /* 0x800A0AE8 */
    R[2] = R[2] << 1;  /* 0x800A0AEC */
    R[16] = R[16] - R[2];  /* 0x800A0AF0 */
    { R[31] = 0x800A0AFCu; R[4] = R[16] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0AF4 jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0AFC */
    R[5] = R[20] + R[0];  /* 0x800A0B00 */
    R[6] = R[21] + R[0];  /* 0x800A0B04 */
    R[7] = R[22] - 88;  /* 0x800A0B08 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0B0C */
    sw_(R[29] + 16, R[0]);  /* 0x800A0B10 */
    R[9] = HI;  /* 0x800A0B14 */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0B18 */
    R[16] = R[16] - R[2];  /* 0x800A0B1C */
    R[2] = R[16] << 2;  /* 0x800A0B20 */
    R[2] = R[2] + R[16];  /* 0x800A0B24 */
    R[2] = R[2] << 1;  /* 0x800A0B28 */
    R[17] = R[17] - R[2];  /* 0x800A0B2C */
    { R[31] = 0x800A0B38u; R[4] = R[17] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0B30 jal */
    { int64_t _p = (int64_t)(int32_t)R[16] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0B38 */
    R[5] = R[20] + R[0];  /* 0x800A0B3C */
    R[6] = R[21] + R[0];  /* 0x800A0B40 */
    R[7] = R[22] - 132;  /* 0x800A0B44 */
    R[2] = (uint32_t)((int32_t)R[16] >> 31);  /* 0x800A0B48 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0B4C */
    R[9] = HI;  /* 0x800A0B50 */
    R[17] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0B54 */
    R[17] = R[17] - R[2];  /* 0x800A0B58 */
    R[2] = R[17] << 2;  /* 0x800A0B5C */
    R[2] = R[2] + R[17];  /* 0x800A0B60 */
    R[2] = R[2] << 1;  /* 0x800A0B64 */
    R[16] = R[16] - R[2];  /* 0x800A0B68 */
    { R[31] = 0x800A0B74u; R[4] = R[16] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0B6C jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0B74 */
    R[5] = R[20] + R[0];  /* 0x800A0B78 */
    R[6] = R[21] + R[0];  /* 0x800A0B7C */
    R[7] = R[22] - 176;  /* 0x800A0B80 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0B84 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0B88 */
    R[9] = HI;  /* 0x800A0B8C */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0B90 */
    R[16] = R[16] - R[2];  /* 0x800A0B94 */
    R[2] = R[16] << 2;  /* 0x800A0B98 */
    R[2] = R[2] + R[16];  /* 0x800A0B9C */
    R[2] = R[2] << 1;  /* 0x800A0BA0 */
    R[17] = R[17] - R[2];  /* 0x800A0BA4 */
    { R[31] = 0x800A0BB0u; R[4] = R[17] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0BA8 jal */
}

void ev_800A0724(void) {
    R[17] = R[16] + R[0];  /* 0x800A0724 */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0728 */
    R[5] = R[30] + R[0];  /* 0x800A072C */
    R[6] = R[23] + R[0];  /* 0x800A0730 */
    R[7] = R[21] + R[0];  /* 0x800A0734 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0738 */
    sw_(R[29] + 16, R[0]);  /* 0x800A073C */
    R[9] = HI;  /* 0x800A0740 */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0744 */
    R[16] = R[16] - R[2];  /* 0x800A0748 */
    R[4] = R[16] << 2;  /* 0x800A074C */
    R[4] = R[4] + R[16];  /* 0x800A0750 */
    R[4] = R[4] << 1;  /* 0x800A0754 */
    R[4] = R[17] - R[4];  /* 0x800A0758 */
    { R[31] = 0x800A0764u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A075C jal */
    R[17] = R[16] + R[0];  /* 0x800A0764 */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0768 */
    R[5] = R[30] + R[0];  /* 0x800A076C */
    R[6] = R[23] + R[0];  /* 0x800A0770 */
    R[7] = R[22] + R[0];  /* 0x800A0774 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0778 */
    sw_(R[29] + 16, R[0]);  /* 0x800A077C */
    R[9] = HI;  /* 0x800A0780 */
    R[3] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0784 */
    R[3] = R[3] - R[2];  /* 0x800A0788 */
    R[4] = R[3] << 2;  /* 0x800A078C */
    R[4] = R[4] + R[3];  /* 0x800A0790 */
    R[4] = R[4] << 1;  /* 0x800A0794 */
    R[4] = R[17] - R[4];  /* 0x800A0798 */
    { R[31] = 0x800A07A4u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A079C jal */
    R[4] = R[0] + 29;  /* 0x800A07A4 */
    R[9] = 0x800Bu << 16;  /* 0x800A07A8 */
    R[5] = R[9] + 10840;  /* 0x800A07AC */
    R[9] = 0x800Bu << 16;  /* 0x800A07B0 */
    R[6] = R[9] + 9412;  /* 0x800A07B4 */
    R[7] = 0x800Fu << 16;  /* 0x800A07B8 */
    R[9] = lw_(R[29] + 24);  /* 0x800A07BC */
    R[7] = R[7] - 4224;  /* 0x800A07C0 */
    sw_(R[29] + 16, R[0]);  /* 0x800A07C4 */
    { R[31] = 0x800A07D0u; R[7] = R[9] + R[7]; psx_next = 0x8009A380u; return; }  /* 0x800A07C8 jal */
    R[22] = R[22] + 176;  /* 0x800A07D0 */
    R[21] = R[21] + 176;  /* 0x800A07D4 */
    R[18] = R[18] + 176;  /* 0x800A07D8 */
    R[9] = lw_(R[29] + 24);  /* 0x800A07DC */
    R[19] = R[19] + 1;  /* 0x800A07E0 */
    R[9] = R[9] + 176;  /* 0x800A07E4 */
    sw_(R[29] + 24, R[9]);  /* 0x800A07E8 */
    R[9] = lw_(R[29] + 28);  /* 0x800A07EC */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A07F0 */
    R[9] = R[9] + 52;  /* 0x800A07F4 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[29] + 28, R[9]); if (_c) { psx_next = 0x800A0694u; return; } }  /* 0x800A07F8 b extern */
    R[19] = R[0] + R[0];  /* 0x800A0800 */
    R[2] = 0x800Bu << 16;  /* 0x800A0804 */
    R[22] = R[2] + 10840;  /* 0x800A0808 */
    R[2] = 0x800Bu << 16;  /* 0x800A080C */
    R[21] = R[2] + 9412;  /* 0x800A0810 */
    R[2] = 0x800Fu << 16;  /* 0x800A0814 */
    R[20] = R[2] - 4632;  /* 0x800A0818 */
    R[18] = R[19] + R[0];  /* 0x800A081C */
    R[2] = 0x800Fu << 16;  /* 0x800A0820 */
    R[17] = R[2] - 1904;  /* 0x800A0824 */
L_800A0828:;
    R[5] = R[22] + R[0];  /* 0x800A0828 */
    R[6] = R[21] + R[0];  /* 0x800A082C */
    R[7] = R[20] + R[0];  /* 0x800A0830 */
    R[20] = R[20] + 44;  /* 0x800A0834 */
    R[16] = lb_(R[17]);  /* 0x800A0838 */
    R[17] = R[17] + 52;  /* 0x800A083C */
    R[19] = R[19] + 1;  /* 0x800A0840 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0844 */
    { R[31] = 0x800A0850u; R[4] = R[16] + 41; psx_next = 0x8009A380u; return; }  /* 0x800A0848 jal */
    R[4] = R[16] + 91;  /* 0x800A0850 */
    R[5] = R[22] + R[0];  /* 0x800A0854 */
    R[6] = R[21] + R[0];  /* 0x800A0858 */
    R[7] = 0x800Fu << 16;  /* 0x800A085C */
    R[7] = R[7] - 1384;  /* 0x800A0860 */
    R[7] = R[18] + R[7];  /* 0x800A0864 */
    { R[31] = 0x800A0870u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0868 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0870 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 44; if (_c) { psx_bb(); goto L_800A0828; } }  /* 0x800A0874 */
    R[19] = R[0] + R[0];  /* 0x800A087C */
    R[2] = 0x800Fu << 16;  /* 0x800A0880 */
    R[18] = R[2] - 2296;  /* 0x800A0884 */
    R[2] = 0x800Fu << 16;  /* 0x800A0888 */
    R[17] = R[2] - 1904;  /* 0x800A088C */
L_800A0890:;
    R[16] = lb_(R[17] + 12);  /* 0x800A0890 */
    { R[31] = 0x800A089Cu; R[17] = R[17] + 52; psx_next = 0x80030E88u; return; }  /* 0x800A0894 jal */
    R[3] = 0x5555u << 16;  /* 0x800A089C */
    R[3] = R[3] | 0x5556;  /* 0x800A08A0 */
    R[5] = 0x800Bu << 16;  /* 0x800A08A4 */
    R[5] = R[5] + 10840;  /* 0x800A08A8 */
    R[6] = 0x800Bu << 16;  /* 0x800A08AC */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A08B0 */
    R[6] = R[6] + 9412;  /* 0x800A08B4 */
    R[7] = R[18] + R[0];  /* 0x800A08B8 */
    R[18] = R[18] + 44;  /* 0x800A08BC */
    R[19] = R[19] + 1;  /* 0x800A08C0 */
    R[3] = R[0] + 9;  /* 0x800A08C4 */
    R[4] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x800A08C8 */
    sw_(R[29] + 16, R[0]);  /* 0x800A08CC */
    R[3] = R[3] - R[16];  /* 0x800A08D0 */
    R[8] = R[3] << 1;  /* 0x800A08D4 */
    R[8] = R[8] + R[3];  /* 0x800A08D8 */
    R[9] = HI;  /* 0x800A08DC */
    R[4] = R[9] - R[4];  /* 0x800A08E0 */
    R[3] = R[4] << 1;  /* 0x800A08E4 */
    R[3] = R[3] + R[4];  /* 0x800A08E8 */
    R[2] = R[2] - R[3];  /* 0x800A08EC */
    R[16] = R[8] + R[2];  /* 0x800A08F0 */
    { R[31] = 0x800A08FCu; R[4] = R[16] + 61; psx_next = 0x8009A380u; return; }  /* 0x800A08F4 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A08FC */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Fu << 16; if (_c) { psx_bb(); goto L_800A0890; } }  /* 0x800A0900 */
    R[19] = R[0] + R[0];  /* 0x800A0908 */
    R[17] = R[2] - 720;  /* 0x800A090C */
    R[2] = 0x800Fu << 16;  /* 0x800A0910 */
    R[16] = R[2] - 1904;  /* 0x800A0914 */
    R[5] = 0x800Bu << 16;  /* 0x800A0918 */
L_800A091C:;
    R[5] = R[5] + 10840;  /* 0x800A091C */
    R[6] = 0x800Bu << 16;  /* 0x800A0920 */
    R[6] = R[6] + 9412;  /* 0x800A0924 */
    R[7] = R[17] + R[0];  /* 0x800A0928 */
    R[17] = R[17] + 44;  /* 0x800A092C */
    R[4] = lb_(R[16] + 13);  /* 0x800A0930 */
    R[16] = R[16] + 52;  /* 0x800A0934 */
    R[19] = R[19] + 1;  /* 0x800A0938 */
    sw_(R[29] + 16, R[0]);  /* 0x800A093C */
    { R[31] = 0x800A0948u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0940 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0948 */
    { uint32_t _c = (R[2] != R[0]); R[5] = 0x800Bu << 16; if (_c) { psx_bb(); goto L_800A091C; } }  /* 0x800A094C */
    R[19] = R[0] + R[0];  /* 0x800A0954 */
    R[2] = 0x800Fu << 16;  /* 0x800A0958 */
    R[17] = R[2] + 27976;  /* 0x800A095C */
    R[2] = 0x800Fu << 16;  /* 0x800A0960 */
    R[16] = R[2] - 1904;  /* 0x800A0964 */
L_800A0968:;
    R[5] = R[5] + 10840;  /* 0x800A0968 */
    R[6] = 0x800Bu << 16;  /* 0x800A096C */
    R[6] = R[6] + 9412;  /* 0x800A0970 */
    R[7] = R[17] + R[0];  /* 0x800A0974 */
    R[17] = R[17] + 44;  /* 0x800A0978 */
    R[4] = lb_(R[16] + 14);  /* 0x800A097C */
    R[16] = R[16] + 52;  /* 0x800A0980 */
    R[19] = R[19] + 1;  /* 0x800A0984 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0988 */
    { R[31] = 0x800A0994u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A098C jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0994 */
    { uint32_t _c = (R[2] != R[0]); R[5] = 0x800Bu << 16; if (_c) { psx_bb(); goto L_800A0968; } }  /* 0x800A0998 */
    R[19] = R[0] + R[0];  /* 0x800A09A0 */
    R[2] = 0x800Fu << 16;  /* 0x800A09A4 */
    R[17] = R[2] - 2816;  /* 0x800A09A8 */
    R[2] = 0x800Fu << 16;  /* 0x800A09AC */
    R[16] = R[2] - 1904;  /* 0x800A09B0 */
L_800A09B4:;
    R[5] = R[5] + 10840;  /* 0x800A09B4 */
    R[6] = 0x800Bu << 16;  /* 0x800A09B8 */
    R[6] = R[6] + 9412;  /* 0x800A09BC */
    R[7] = R[17] + R[0];  /* 0x800A09C0 */
    R[17] = R[17] + 44;  /* 0x800A09C4 */
    R[4] = lb_(R[16] + 16);  /* 0x800A09C8 */
    R[16] = R[16] + 52;  /* 0x800A09CC */
    R[19] = R[19] + 1;  /* 0x800A09D0 */
    sw_(R[29] + 16, R[0]);  /* 0x800A09D4 */
    { R[31] = 0x800A09E0u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A09D8 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A09E0 */
    { uint32_t _c = (R[2] != R[0]); R[5] = 0x800Bu << 16; if (_c) { psx_bb(); goto L_800A09B4; } }  /* 0x800A09E4 */
    R[19] = R[0] + R[0];  /* 0x800A09EC */
    R[2] = 0x800Fu << 16;  /* 0x800A09F0 */
    R[16] = R[2] + 312;  /* 0x800A09F4 */
    R[2] = 0x800Fu << 16;  /* 0x800A09F8 */
    R[18] = R[2] - 1904;  /* 0x800A09FC */
L_800A0A00:;
    R[17] = 0x800Bu << 16;  /* 0x800A0A00 */
    R[5] = R[17] + 10840;  /* 0x800A0A04 */
    R[20] = 0x800Bu << 16;  /* 0x800A0A08 */
    R[6] = R[20] + 9412;  /* 0x800A0A0C */
    R[7] = R[16] + R[0];  /* 0x800A0A10 */
    R[16] = R[16] + 44;  /* 0x800A0A14 */
    R[4] = lb_(R[18] + 15);  /* 0x800A0A18 */
    R[18] = R[18] + 52;  /* 0x800A0A1C */
    R[19] = R[19] + 1;  /* 0x800A0A20 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0A24 */
    { R[31] = 0x800A0A30u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0A28 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0A30 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 10840; if (_c) { psx_bb(); goto L_800A0A00; } }  /* 0x800A0A34 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0A3C */
    R[4] = R[0] + 117;  /* 0x800A0A40 */
    R[5] = R[17] + R[0];  /* 0x800A0A44 */
    R[16] = R[20] + 9412;  /* 0x800A0A48 */
    R[6] = R[16] + R[0];  /* 0x800A0A4C */
    R[7] = 0x800Fu << 16;  /* 0x800A0A50 */
    { R[31] = 0x800A0A5Cu; R[7] = R[7] + 25664; psx_next = 0x8009A380u; return; }  /* 0x800A0A54 jal */
    R[19] = R[0] + R[0];  /* 0x800A0A5C */
    R[18] = 0x6666u << 16;  /* 0x800A0A60 */
    R[18] = R[18] | 0x6667;  /* 0x800A0A64 */
    R[20] = R[17] + R[0];  /* 0x800A0A68 */
    R[21] = R[16] + R[0];  /* 0x800A0A6C */
    R[2] = 0x800Fu << 16;  /* 0x800A0A70 */
    R[22] = R[2] - 148;  /* 0x800A0A74 */
    R[2] = 0x8006u << 16;  /* 0x800A0A78 */
    R[4] = lw_(R[2] + 16068);  /* 0x800A0A7C */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0A84 */
    R[5] = R[20] + R[0];  /* 0x800A0A88 */
    R[6] = R[21] + R[0];  /* 0x800A0A8C */
    R[7] = R[22] + R[0];  /* 0x800A0A90 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0A94 */
    R[2] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A0A98 */
    R[9] = HI;  /* 0x800A0A9C */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0AA0 */
    R[16] = R[16] - R[2];  /* 0x800A0AA4 */
    R[2] = R[16] << 2;  /* 0x800A0AA8 */
    R[2] = R[2] + R[16];  /* 0x800A0AAC */
    R[2] = R[2] << 1;  /* 0x800A0AB0 */
    R[4] = R[4] - R[2];  /* 0x800A0AB4 */
    { R[31] = 0x800A0AC0u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0AB8 jal */
    { int64_t _p = (int64_t)(int32_t)R[16] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0AC0 */
    R[5] = R[20] + R[0];  /* 0x800A0AC4 */
    R[6] = R[21] + R[0];  /* 0x800A0AC8 */
    R[7] = R[22] - 44;  /* 0x800A0ACC */
    R[2] = (uint32_t)((int32_t)R[16] >> 31);  /* 0x800A0AD0 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0AD4 */
    R[9] = HI;  /* 0x800A0AD8 */
    R[17] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0ADC */
    R[17] = R[17] - R[2];  /* 0x800A0AE0 */
    R[2] = R[17] << 2;  /* 0x800A0AE4 */
    R[2] = R[2] + R[17];  /* 0x800A0AE8 */
    R[2] = R[2] << 1;  /* 0x800A0AEC */
    R[16] = R[16] - R[2];  /* 0x800A0AF0 */
    { R[31] = 0x800A0AFCu; R[4] = R[16] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0AF4 jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0AFC */
    R[5] = R[20] + R[0];  /* 0x800A0B00 */
    R[6] = R[21] + R[0];  /* 0x800A0B04 */
    R[7] = R[22] - 88;  /* 0x800A0B08 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0B0C */
    sw_(R[29] + 16, R[0]);  /* 0x800A0B10 */
    R[9] = HI;  /* 0x800A0B14 */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0B18 */
    R[16] = R[16] - R[2];  /* 0x800A0B1C */
    R[2] = R[16] << 2;  /* 0x800A0B20 */
    R[2] = R[2] + R[16];  /* 0x800A0B24 */
    R[2] = R[2] << 1;  /* 0x800A0B28 */
    R[17] = R[17] - R[2];  /* 0x800A0B2C */
    { R[31] = 0x800A0B38u; R[4] = R[17] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0B30 jal */
    { int64_t _p = (int64_t)(int32_t)R[16] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0B38 */
    R[5] = R[20] + R[0];  /* 0x800A0B3C */
    R[6] = R[21] + R[0];  /* 0x800A0B40 */
    R[7] = R[22] - 132;  /* 0x800A0B44 */
    R[2] = (uint32_t)((int32_t)R[16] >> 31);  /* 0x800A0B48 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0B4C */
    R[9] = HI;  /* 0x800A0B50 */
    R[17] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0B54 */
    R[17] = R[17] - R[2];  /* 0x800A0B58 */
    R[2] = R[17] << 2;  /* 0x800A0B5C */
    R[2] = R[2] + R[17];  /* 0x800A0B60 */
    R[2] = R[2] << 1;  /* 0x800A0B64 */
    R[16] = R[16] - R[2];  /* 0x800A0B68 */
    { R[31] = 0x800A0B74u; R[4] = R[16] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0B6C jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0B74 */
    R[5] = R[20] + R[0];  /* 0x800A0B78 */
    R[6] = R[21] + R[0];  /* 0x800A0B7C */
    R[7] = R[22] - 176;  /* 0x800A0B80 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0B84 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0B88 */
    R[9] = HI;  /* 0x800A0B8C */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0B90 */
    R[16] = R[16] - R[2];  /* 0x800A0B94 */
    R[2] = R[16] << 2;  /* 0x800A0B98 */
    R[2] = R[2] + R[16];  /* 0x800A0B9C */
    R[2] = R[2] << 1;  /* 0x800A0BA0 */
    R[17] = R[17] - R[2];  /* 0x800A0BA4 */
    { R[31] = 0x800A0BB0u; R[4] = R[17] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0BA8 jal */
}

void ev_800A0738(void) {
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0738 */
    sw_(R[29] + 16, R[0]);  /* 0x800A073C */
    R[9] = HI;  /* 0x800A0740 */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0744 */
    R[16] = R[16] - R[2];  /* 0x800A0748 */
    R[4] = R[16] << 2;  /* 0x800A074C */
    R[4] = R[4] + R[16];  /* 0x800A0750 */
    R[4] = R[4] << 1;  /* 0x800A0754 */
    R[4] = R[17] - R[4];  /* 0x800A0758 */
    { R[31] = 0x800A0764u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A075C jal */
    R[17] = R[16] + R[0];  /* 0x800A0764 */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0768 */
    R[5] = R[30] + R[0];  /* 0x800A076C */
    R[6] = R[23] + R[0];  /* 0x800A0770 */
    R[7] = R[22] + R[0];  /* 0x800A0774 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0778 */
    sw_(R[29] + 16, R[0]);  /* 0x800A077C */
    R[9] = HI;  /* 0x800A0780 */
    R[3] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0784 */
    R[3] = R[3] - R[2];  /* 0x800A0788 */
    R[4] = R[3] << 2;  /* 0x800A078C */
    R[4] = R[4] + R[3];  /* 0x800A0790 */
    R[4] = R[4] << 1;  /* 0x800A0794 */
    R[4] = R[17] - R[4];  /* 0x800A0798 */
    { R[31] = 0x800A07A4u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A079C jal */
    R[4] = R[0] + 29;  /* 0x800A07A4 */
    R[9] = 0x800Bu << 16;  /* 0x800A07A8 */
    R[5] = R[9] + 10840;  /* 0x800A07AC */
    R[9] = 0x800Bu << 16;  /* 0x800A07B0 */
    R[6] = R[9] + 9412;  /* 0x800A07B4 */
    R[7] = 0x800Fu << 16;  /* 0x800A07B8 */
    R[9] = lw_(R[29] + 24);  /* 0x800A07BC */
    R[7] = R[7] - 4224;  /* 0x800A07C0 */
    sw_(R[29] + 16, R[0]);  /* 0x800A07C4 */
    { R[31] = 0x800A07D0u; R[7] = R[9] + R[7]; psx_next = 0x8009A380u; return; }  /* 0x800A07C8 jal */
    R[22] = R[22] + 176;  /* 0x800A07D0 */
    R[21] = R[21] + 176;  /* 0x800A07D4 */
    R[18] = R[18] + 176;  /* 0x800A07D8 */
    R[9] = lw_(R[29] + 24);  /* 0x800A07DC */
    R[19] = R[19] + 1;  /* 0x800A07E0 */
    R[9] = R[9] + 176;  /* 0x800A07E4 */
    sw_(R[29] + 24, R[9]);  /* 0x800A07E8 */
    R[9] = lw_(R[29] + 28);  /* 0x800A07EC */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A07F0 */
    R[9] = R[9] + 52;  /* 0x800A07F4 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[29] + 28, R[9]); if (_c) { psx_next = 0x800A0694u; return; } }  /* 0x800A07F8 b extern */
    R[19] = R[0] + R[0];  /* 0x800A0800 */
    R[2] = 0x800Bu << 16;  /* 0x800A0804 */
    R[22] = R[2] + 10840;  /* 0x800A0808 */
    R[2] = 0x800Bu << 16;  /* 0x800A080C */
    R[21] = R[2] + 9412;  /* 0x800A0810 */
    R[2] = 0x800Fu << 16;  /* 0x800A0814 */
    R[20] = R[2] - 4632;  /* 0x800A0818 */
    R[18] = R[19] + R[0];  /* 0x800A081C */
    R[2] = 0x800Fu << 16;  /* 0x800A0820 */
    R[17] = R[2] - 1904;  /* 0x800A0824 */
L_800A0828:;
    R[5] = R[22] + R[0];  /* 0x800A0828 */
    R[6] = R[21] + R[0];  /* 0x800A082C */
    R[7] = R[20] + R[0];  /* 0x800A0830 */
    R[20] = R[20] + 44;  /* 0x800A0834 */
    R[16] = lb_(R[17]);  /* 0x800A0838 */
    R[17] = R[17] + 52;  /* 0x800A083C */
    R[19] = R[19] + 1;  /* 0x800A0840 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0844 */
    { R[31] = 0x800A0850u; R[4] = R[16] + 41; psx_next = 0x8009A380u; return; }  /* 0x800A0848 jal */
    R[4] = R[16] + 91;  /* 0x800A0850 */
    R[5] = R[22] + R[0];  /* 0x800A0854 */
    R[6] = R[21] + R[0];  /* 0x800A0858 */
    R[7] = 0x800Fu << 16;  /* 0x800A085C */
    R[7] = R[7] - 1384;  /* 0x800A0860 */
    R[7] = R[18] + R[7];  /* 0x800A0864 */
    { R[31] = 0x800A0870u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0868 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0870 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 44; if (_c) { psx_bb(); goto L_800A0828; } }  /* 0x800A0874 */
    R[19] = R[0] + R[0];  /* 0x800A087C */
    R[2] = 0x800Fu << 16;  /* 0x800A0880 */
    R[18] = R[2] - 2296;  /* 0x800A0884 */
    R[2] = 0x800Fu << 16;  /* 0x800A0888 */
    R[17] = R[2] - 1904;  /* 0x800A088C */
L_800A0890:;
    R[16] = lb_(R[17] + 12);  /* 0x800A0890 */
    { R[31] = 0x800A089Cu; R[17] = R[17] + 52; psx_next = 0x80030E88u; return; }  /* 0x800A0894 jal */
    R[3] = 0x5555u << 16;  /* 0x800A089C */
    R[3] = R[3] | 0x5556;  /* 0x800A08A0 */
    R[5] = 0x800Bu << 16;  /* 0x800A08A4 */
    R[5] = R[5] + 10840;  /* 0x800A08A8 */
    R[6] = 0x800Bu << 16;  /* 0x800A08AC */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A08B0 */
    R[6] = R[6] + 9412;  /* 0x800A08B4 */
    R[7] = R[18] + R[0];  /* 0x800A08B8 */
    R[18] = R[18] + 44;  /* 0x800A08BC */
    R[19] = R[19] + 1;  /* 0x800A08C0 */
    R[3] = R[0] + 9;  /* 0x800A08C4 */
    R[4] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x800A08C8 */
    sw_(R[29] + 16, R[0]);  /* 0x800A08CC */
    R[3] = R[3] - R[16];  /* 0x800A08D0 */
    R[8] = R[3] << 1;  /* 0x800A08D4 */
    R[8] = R[8] + R[3];  /* 0x800A08D8 */
    R[9] = HI;  /* 0x800A08DC */
    R[4] = R[9] - R[4];  /* 0x800A08E0 */
    R[3] = R[4] << 1;  /* 0x800A08E4 */
    R[3] = R[3] + R[4];  /* 0x800A08E8 */
    R[2] = R[2] - R[3];  /* 0x800A08EC */
    R[16] = R[8] + R[2];  /* 0x800A08F0 */
    { R[31] = 0x800A08FCu; R[4] = R[16] + 61; psx_next = 0x8009A380u; return; }  /* 0x800A08F4 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A08FC */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Fu << 16; if (_c) { psx_bb(); goto L_800A0890; } }  /* 0x800A0900 */
    R[19] = R[0] + R[0];  /* 0x800A0908 */
    R[17] = R[2] - 720;  /* 0x800A090C */
    R[2] = 0x800Fu << 16;  /* 0x800A0910 */
    R[16] = R[2] - 1904;  /* 0x800A0914 */
    R[5] = 0x800Bu << 16;  /* 0x800A0918 */
L_800A091C:;
    R[5] = R[5] + 10840;  /* 0x800A091C */
    R[6] = 0x800Bu << 16;  /* 0x800A0920 */
    R[6] = R[6] + 9412;  /* 0x800A0924 */
    R[7] = R[17] + R[0];  /* 0x800A0928 */
    R[17] = R[17] + 44;  /* 0x800A092C */
    R[4] = lb_(R[16] + 13);  /* 0x800A0930 */
    R[16] = R[16] + 52;  /* 0x800A0934 */
    R[19] = R[19] + 1;  /* 0x800A0938 */
    sw_(R[29] + 16, R[0]);  /* 0x800A093C */
    { R[31] = 0x800A0948u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0940 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0948 */
    { uint32_t _c = (R[2] != R[0]); R[5] = 0x800Bu << 16; if (_c) { psx_bb(); goto L_800A091C; } }  /* 0x800A094C */
    R[19] = R[0] + R[0];  /* 0x800A0954 */
    R[2] = 0x800Fu << 16;  /* 0x800A0958 */
    R[17] = R[2] + 27976;  /* 0x800A095C */
    R[2] = 0x800Fu << 16;  /* 0x800A0960 */
    R[16] = R[2] - 1904;  /* 0x800A0964 */
L_800A0968:;
    R[5] = R[5] + 10840;  /* 0x800A0968 */
    R[6] = 0x800Bu << 16;  /* 0x800A096C */
    R[6] = R[6] + 9412;  /* 0x800A0970 */
    R[7] = R[17] + R[0];  /* 0x800A0974 */
    R[17] = R[17] + 44;  /* 0x800A0978 */
    R[4] = lb_(R[16] + 14);  /* 0x800A097C */
    R[16] = R[16] + 52;  /* 0x800A0980 */
    R[19] = R[19] + 1;  /* 0x800A0984 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0988 */
    { R[31] = 0x800A0994u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A098C jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0994 */
    { uint32_t _c = (R[2] != R[0]); R[5] = 0x800Bu << 16; if (_c) { psx_bb(); goto L_800A0968; } }  /* 0x800A0998 */
    R[19] = R[0] + R[0];  /* 0x800A09A0 */
    R[2] = 0x800Fu << 16;  /* 0x800A09A4 */
    R[17] = R[2] - 2816;  /* 0x800A09A8 */
    R[2] = 0x800Fu << 16;  /* 0x800A09AC */
    R[16] = R[2] - 1904;  /* 0x800A09B0 */
L_800A09B4:;
    R[5] = R[5] + 10840;  /* 0x800A09B4 */
    R[6] = 0x800Bu << 16;  /* 0x800A09B8 */
    R[6] = R[6] + 9412;  /* 0x800A09BC */
    R[7] = R[17] + R[0];  /* 0x800A09C0 */
    R[17] = R[17] + 44;  /* 0x800A09C4 */
    R[4] = lb_(R[16] + 16);  /* 0x800A09C8 */
    R[16] = R[16] + 52;  /* 0x800A09CC */
    R[19] = R[19] + 1;  /* 0x800A09D0 */
    sw_(R[29] + 16, R[0]);  /* 0x800A09D4 */
    { R[31] = 0x800A09E0u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A09D8 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A09E0 */
    { uint32_t _c = (R[2] != R[0]); R[5] = 0x800Bu << 16; if (_c) { psx_bb(); goto L_800A09B4; } }  /* 0x800A09E4 */
    R[19] = R[0] + R[0];  /* 0x800A09EC */
    R[2] = 0x800Fu << 16;  /* 0x800A09F0 */
    R[16] = R[2] + 312;  /* 0x800A09F4 */
    R[2] = 0x800Fu << 16;  /* 0x800A09F8 */
    R[18] = R[2] - 1904;  /* 0x800A09FC */
L_800A0A00:;
    R[17] = 0x800Bu << 16;  /* 0x800A0A00 */
    R[5] = R[17] + 10840;  /* 0x800A0A04 */
    R[20] = 0x800Bu << 16;  /* 0x800A0A08 */
    R[6] = R[20] + 9412;  /* 0x800A0A0C */
    R[7] = R[16] + R[0];  /* 0x800A0A10 */
    R[16] = R[16] + 44;  /* 0x800A0A14 */
    R[4] = lb_(R[18] + 15);  /* 0x800A0A18 */
    R[18] = R[18] + 52;  /* 0x800A0A1C */
    R[19] = R[19] + 1;  /* 0x800A0A20 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0A24 */
    { R[31] = 0x800A0A30u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0A28 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0A30 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 10840; if (_c) { psx_bb(); goto L_800A0A00; } }  /* 0x800A0A34 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0A3C */
    R[4] = R[0] + 117;  /* 0x800A0A40 */
    R[5] = R[17] + R[0];  /* 0x800A0A44 */
    R[16] = R[20] + 9412;  /* 0x800A0A48 */
    R[6] = R[16] + R[0];  /* 0x800A0A4C */
    R[7] = 0x800Fu << 16;  /* 0x800A0A50 */
    { R[31] = 0x800A0A5Cu; R[7] = R[7] + 25664; psx_next = 0x8009A380u; return; }  /* 0x800A0A54 jal */
    R[19] = R[0] + R[0];  /* 0x800A0A5C */
    R[18] = 0x6666u << 16;  /* 0x800A0A60 */
    R[18] = R[18] | 0x6667;  /* 0x800A0A64 */
    R[20] = R[17] + R[0];  /* 0x800A0A68 */
    R[21] = R[16] + R[0];  /* 0x800A0A6C */
    R[2] = 0x800Fu << 16;  /* 0x800A0A70 */
    R[22] = R[2] - 148;  /* 0x800A0A74 */
    R[2] = 0x8006u << 16;  /* 0x800A0A78 */
    R[4] = lw_(R[2] + 16068);  /* 0x800A0A7C */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0A84 */
    R[5] = R[20] + R[0];  /* 0x800A0A88 */
    R[6] = R[21] + R[0];  /* 0x800A0A8C */
    R[7] = R[22] + R[0];  /* 0x800A0A90 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0A94 */
    R[2] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A0A98 */
    R[9] = HI;  /* 0x800A0A9C */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0AA0 */
    R[16] = R[16] - R[2];  /* 0x800A0AA4 */
    R[2] = R[16] << 2;  /* 0x800A0AA8 */
    R[2] = R[2] + R[16];  /* 0x800A0AAC */
    R[2] = R[2] << 1;  /* 0x800A0AB0 */
    R[4] = R[4] - R[2];  /* 0x800A0AB4 */
    { R[31] = 0x800A0AC0u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0AB8 jal */
    { int64_t _p = (int64_t)(int32_t)R[16] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0AC0 */
    R[5] = R[20] + R[0];  /* 0x800A0AC4 */
    R[6] = R[21] + R[0];  /* 0x800A0AC8 */
    R[7] = R[22] - 44;  /* 0x800A0ACC */
    R[2] = (uint32_t)((int32_t)R[16] >> 31);  /* 0x800A0AD0 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0AD4 */
    R[9] = HI;  /* 0x800A0AD8 */
    R[17] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0ADC */
    R[17] = R[17] - R[2];  /* 0x800A0AE0 */
    R[2] = R[17] << 2;  /* 0x800A0AE4 */
    R[2] = R[2] + R[17];  /* 0x800A0AE8 */
    R[2] = R[2] << 1;  /* 0x800A0AEC */
    R[16] = R[16] - R[2];  /* 0x800A0AF0 */
    { R[31] = 0x800A0AFCu; R[4] = R[16] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0AF4 jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0AFC */
    R[5] = R[20] + R[0];  /* 0x800A0B00 */
    R[6] = R[21] + R[0];  /* 0x800A0B04 */
    R[7] = R[22] - 88;  /* 0x800A0B08 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0B0C */
    sw_(R[29] + 16, R[0]);  /* 0x800A0B10 */
    R[9] = HI;  /* 0x800A0B14 */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0B18 */
    R[16] = R[16] - R[2];  /* 0x800A0B1C */
    R[2] = R[16] << 2;  /* 0x800A0B20 */
    R[2] = R[2] + R[16];  /* 0x800A0B24 */
    R[2] = R[2] << 1;  /* 0x800A0B28 */
    R[17] = R[17] - R[2];  /* 0x800A0B2C */
    { R[31] = 0x800A0B38u; R[4] = R[17] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0B30 jal */
    { int64_t _p = (int64_t)(int32_t)R[16] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0B38 */
    R[5] = R[20] + R[0];  /* 0x800A0B3C */
    R[6] = R[21] + R[0];  /* 0x800A0B40 */
    R[7] = R[22] - 132;  /* 0x800A0B44 */
    R[2] = (uint32_t)((int32_t)R[16] >> 31);  /* 0x800A0B48 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0B4C */
    R[9] = HI;  /* 0x800A0B50 */
    R[17] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0B54 */
    R[17] = R[17] - R[2];  /* 0x800A0B58 */
    R[2] = R[17] << 2;  /* 0x800A0B5C */
    R[2] = R[2] + R[17];  /* 0x800A0B60 */
    R[2] = R[2] << 1;  /* 0x800A0B64 */
    R[16] = R[16] - R[2];  /* 0x800A0B68 */
    { R[31] = 0x800A0B74u; R[4] = R[16] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0B6C jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0B74 */
    R[5] = R[20] + R[0];  /* 0x800A0B78 */
    R[6] = R[21] + R[0];  /* 0x800A0B7C */
    R[7] = R[22] - 176;  /* 0x800A0B80 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0B84 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0B88 */
    R[9] = HI;  /* 0x800A0B8C */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0B90 */
    R[16] = R[16] - R[2];  /* 0x800A0B94 */
    R[2] = R[16] << 2;  /* 0x800A0B98 */
    R[2] = R[2] + R[16];  /* 0x800A0B9C */
    R[2] = R[2] << 1;  /* 0x800A0BA0 */
    R[17] = R[17] - R[2];  /* 0x800A0BA4 */
    { R[31] = 0x800A0BB0u; R[4] = R[17] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0BA8 jal */
}

void ev_800A0764(void) {
    R[17] = R[16] + R[0];  /* 0x800A0764 */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[20]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0768 */
    R[5] = R[30] + R[0];  /* 0x800A076C */
    R[6] = R[23] + R[0];  /* 0x800A0770 */
    R[7] = R[22] + R[0];  /* 0x800A0774 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0778 */
    sw_(R[29] + 16, R[0]);  /* 0x800A077C */
    R[9] = HI;  /* 0x800A0780 */
    R[3] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0784 */
    R[3] = R[3] - R[2];  /* 0x800A0788 */
    R[4] = R[3] << 2;  /* 0x800A078C */
    R[4] = R[4] + R[3];  /* 0x800A0790 */
    R[4] = R[4] << 1;  /* 0x800A0794 */
    R[4] = R[17] - R[4];  /* 0x800A0798 */
    { R[31] = 0x800A07A4u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A079C jal */
    R[4] = R[0] + 29;  /* 0x800A07A4 */
    R[9] = 0x800Bu << 16;  /* 0x800A07A8 */
    R[5] = R[9] + 10840;  /* 0x800A07AC */
    R[9] = 0x800Bu << 16;  /* 0x800A07B0 */
    R[6] = R[9] + 9412;  /* 0x800A07B4 */
    R[7] = 0x800Fu << 16;  /* 0x800A07B8 */
    R[9] = lw_(R[29] + 24);  /* 0x800A07BC */
    R[7] = R[7] - 4224;  /* 0x800A07C0 */
    sw_(R[29] + 16, R[0]);  /* 0x800A07C4 */
    { R[31] = 0x800A07D0u; R[7] = R[9] + R[7]; psx_next = 0x8009A380u; return; }  /* 0x800A07C8 jal */
    R[22] = R[22] + 176;  /* 0x800A07D0 */
    R[21] = R[21] + 176;  /* 0x800A07D4 */
    R[18] = R[18] + 176;  /* 0x800A07D8 */
    R[9] = lw_(R[29] + 24);  /* 0x800A07DC */
    R[19] = R[19] + 1;  /* 0x800A07E0 */
    R[9] = R[9] + 176;  /* 0x800A07E4 */
    sw_(R[29] + 24, R[9]);  /* 0x800A07E8 */
    R[9] = lw_(R[29] + 28);  /* 0x800A07EC */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A07F0 */
    R[9] = R[9] + 52;  /* 0x800A07F4 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[29] + 28, R[9]); if (_c) { psx_next = 0x800A0694u; return; } }  /* 0x800A07F8 b extern */
    R[19] = R[0] + R[0];  /* 0x800A0800 */
    R[2] = 0x800Bu << 16;  /* 0x800A0804 */
    R[22] = R[2] + 10840;  /* 0x800A0808 */
    R[2] = 0x800Bu << 16;  /* 0x800A080C */
    R[21] = R[2] + 9412;  /* 0x800A0810 */
    R[2] = 0x800Fu << 16;  /* 0x800A0814 */
    R[20] = R[2] - 4632;  /* 0x800A0818 */
    R[18] = R[19] + R[0];  /* 0x800A081C */
    R[2] = 0x800Fu << 16;  /* 0x800A0820 */
    R[17] = R[2] - 1904;  /* 0x800A0824 */
L_800A0828:;
    R[5] = R[22] + R[0];  /* 0x800A0828 */
    R[6] = R[21] + R[0];  /* 0x800A082C */
    R[7] = R[20] + R[0];  /* 0x800A0830 */
    R[20] = R[20] + 44;  /* 0x800A0834 */
    R[16] = lb_(R[17]);  /* 0x800A0838 */
    R[17] = R[17] + 52;  /* 0x800A083C */
    R[19] = R[19] + 1;  /* 0x800A0840 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0844 */
    { R[31] = 0x800A0850u; R[4] = R[16] + 41; psx_next = 0x8009A380u; return; }  /* 0x800A0848 jal */
    R[4] = R[16] + 91;  /* 0x800A0850 */
    R[5] = R[22] + R[0];  /* 0x800A0854 */
    R[6] = R[21] + R[0];  /* 0x800A0858 */
    R[7] = 0x800Fu << 16;  /* 0x800A085C */
    R[7] = R[7] - 1384;  /* 0x800A0860 */
    R[7] = R[18] + R[7];  /* 0x800A0864 */
    { R[31] = 0x800A0870u; sw_(R[29] + 16, R[0]); psx_next = 0x8009A380u; return; }  /* 0x800A0868 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0870 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[18] + 44; if (_c) { psx_bb(); goto L_800A0828; } }  /* 0x800A0874 */
    R[19] = R[0] + R[0];  /* 0x800A087C */
    R[2] = 0x800Fu << 16;  /* 0x800A0880 */
    R[18] = R[2] - 2296;  /* 0x800A0884 */
    R[2] = 0x800Fu << 16;  /* 0x800A0888 */
    R[17] = R[2] - 1904;  /* 0x800A088C */
L_800A0890:;
    R[16] = lb_(R[17] + 12);  /* 0x800A0890 */
    { R[31] = 0x800A089Cu; R[17] = R[17] + 52; psx_next = 0x80030E88u; return; }  /* 0x800A0894 jal */
    R[3] = 0x5555u << 16;  /* 0x800A089C */
    R[3] = R[3] | 0x5556;  /* 0x800A08A0 */
    R[5] = 0x800Bu << 16;  /* 0x800A08A4 */
    R[5] = R[5] + 10840;  /* 0x800A08A8 */
    R[6] = 0x800Bu << 16;  /* 0x800A08AC */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A08B0 */
    R[6] = R[6] + 9412;  /* 0x800A08B4 */
    R[7] = R[18] + R[0];  /* 0x800A08B8 */
    R[18] = R[18] + 44;  /* 0x800A08BC */
    R[19] = R[19] + 1;  /* 0x800A08C0 */
    R[3] = R[0] + 9;  /* 0x800A08C4 */
    R[4] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x800A08C8 */
    sw_(R[29] + 16, R[0]);  /* 0x800A08CC */
    R[3] = R[3] - R[16];  /* 0x800A08D0 */
    R[8] = R[3] << 1;  /* 0x800A08D4 */
    R[8] = R[8] + R[3];  /* 0x800A08D8 */
    R[9] = HI;  /* 0x800A08DC */
    R[4] = R[9] - R[4];  /* 0x800A08E0 */
    R[3] = R[4] << 1;  /* 0x800A08E4 */
    R[3] = R[3] + R[4];  /* 0x800A08E8 */
    R[2] = R[2] - R[3];  /* 0x800A08EC */
    R[16] = R[8] + R[2];  /* 0x800A08F0 */
    { R[31] = 0x800A08FCu; R[4] = R[16] + 61; psx_next = 0x8009A380u; return; }  /* 0x800A08F4 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A08FC */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x800Fu << 16; if (_c) { psx_bb(); goto L_800A0890; } }  /* 0x800A0900 */
    R[19] = R[0] + R[0];  /* 0x800A0908 */
    R[17] = R[2] - 720;  /* 0x800A090C */
    R[2] = 0x800Fu << 16;  /* 0x800A0910 */
    R[16] = R[2] - 1904;  /* 0x800A0914 */
    R[5] = 0x800Bu << 16;  /* 0x800A0918 */
L_800A091C:;
    R[5] = R[5] + 10840;  /* 0x800A091C */
    R[6] = 0x800Bu << 16;  /* 0x800A0920 */
    R[6] = R[6] + 9412;  /* 0x800A0924 */
    R[7] = R[17] + R[0];  /* 0x800A0928 */
    R[17] = R[17] + 44;  /* 0x800A092C */
    R[4] = lb_(R[16] + 13);  /* 0x800A0930 */
    R[16] = R[16] + 52;  /* 0x800A0934 */
    R[19] = R[19] + 1;  /* 0x800A0938 */
    sw_(R[29] + 16, R[0]);  /* 0x800A093C */
    { R[31] = 0x800A0948u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0940 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0948 */
    { uint32_t _c = (R[2] != R[0]); R[5] = 0x800Bu << 16; if (_c) { psx_bb(); goto L_800A091C; } }  /* 0x800A094C */
    R[19] = R[0] + R[0];  /* 0x800A0954 */
    R[2] = 0x800Fu << 16;  /* 0x800A0958 */
    R[17] = R[2] + 27976;  /* 0x800A095C */
    R[2] = 0x800Fu << 16;  /* 0x800A0960 */
    R[16] = R[2] - 1904;  /* 0x800A0964 */
L_800A0968:;
    R[5] = R[5] + 10840;  /* 0x800A0968 */
    R[6] = 0x800Bu << 16;  /* 0x800A096C */
    R[6] = R[6] + 9412;  /* 0x800A0970 */
    R[7] = R[17] + R[0];  /* 0x800A0974 */
    R[17] = R[17] + 44;  /* 0x800A0978 */
    R[4] = lb_(R[16] + 14);  /* 0x800A097C */
    R[16] = R[16] + 52;  /* 0x800A0980 */
    R[19] = R[19] + 1;  /* 0x800A0984 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0988 */
    { R[31] = 0x800A0994u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A098C jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0994 */
    { uint32_t _c = (R[2] != R[0]); R[5] = 0x800Bu << 16; if (_c) { psx_bb(); goto L_800A0968; } }  /* 0x800A0998 */
    R[19] = R[0] + R[0];  /* 0x800A09A0 */
    R[2] = 0x800Fu << 16;  /* 0x800A09A4 */
    R[17] = R[2] - 2816;  /* 0x800A09A8 */
    R[2] = 0x800Fu << 16;  /* 0x800A09AC */
    R[16] = R[2] - 1904;  /* 0x800A09B0 */
L_800A09B4:;
    R[5] = R[5] + 10840;  /* 0x800A09B4 */
    R[6] = 0x800Bu << 16;  /* 0x800A09B8 */
    R[6] = R[6] + 9412;  /* 0x800A09BC */
    R[7] = R[17] + R[0];  /* 0x800A09C0 */
    R[17] = R[17] + 44;  /* 0x800A09C4 */
    R[4] = lb_(R[16] + 16);  /* 0x800A09C8 */
    R[16] = R[16] + 52;  /* 0x800A09CC */
    R[19] = R[19] + 1;  /* 0x800A09D0 */
    sw_(R[29] + 16, R[0]);  /* 0x800A09D4 */
    { R[31] = 0x800A09E0u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A09D8 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A09E0 */
    { uint32_t _c = (R[2] != R[0]); R[5] = 0x800Bu << 16; if (_c) { psx_bb(); goto L_800A09B4; } }  /* 0x800A09E4 */
    R[19] = R[0] + R[0];  /* 0x800A09EC */
    R[2] = 0x800Fu << 16;  /* 0x800A09F0 */
    R[16] = R[2] + 312;  /* 0x800A09F4 */
    R[2] = 0x800Fu << 16;  /* 0x800A09F8 */
    R[18] = R[2] - 1904;  /* 0x800A09FC */
L_800A0A00:;
    R[17] = 0x800Bu << 16;  /* 0x800A0A00 */
    R[5] = R[17] + 10840;  /* 0x800A0A04 */
    R[20] = 0x800Bu << 16;  /* 0x800A0A08 */
    R[6] = R[20] + 9412;  /* 0x800A0A0C */
    R[7] = R[16] + R[0];  /* 0x800A0A10 */
    R[16] = R[16] + 44;  /* 0x800A0A14 */
    R[4] = lb_(R[18] + 15);  /* 0x800A0A18 */
    R[18] = R[18] + 52;  /* 0x800A0A1C */
    R[19] = R[19] + 1;  /* 0x800A0A20 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0A24 */
    { R[31] = 0x800A0A30u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0A28 jal */
    R[2] = ((int32_t)R[19] < 8);  /* 0x800A0A30 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 10840; if (_c) { psx_bb(); goto L_800A0A00; } }  /* 0x800A0A34 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0A3C */
    R[4] = R[0] + 117;  /* 0x800A0A40 */
    R[5] = R[17] + R[0];  /* 0x800A0A44 */
    R[16] = R[20] + 9412;  /* 0x800A0A48 */
    R[6] = R[16] + R[0];  /* 0x800A0A4C */
    R[7] = 0x800Fu << 16;  /* 0x800A0A50 */
    { R[31] = 0x800A0A5Cu; R[7] = R[7] + 25664; psx_next = 0x8009A380u; return; }  /* 0x800A0A54 jal */
    R[19] = R[0] + R[0];  /* 0x800A0A5C */
    R[18] = 0x6666u << 16;  /* 0x800A0A60 */
    R[18] = R[18] | 0x6667;  /* 0x800A0A64 */
    R[20] = R[17] + R[0];  /* 0x800A0A68 */
    R[21] = R[16] + R[0];  /* 0x800A0A6C */
    R[2] = 0x800Fu << 16;  /* 0x800A0A70 */
    R[22] = R[2] - 148;  /* 0x800A0A74 */
    R[2] = 0x8006u << 16;  /* 0x800A0A78 */
    R[4] = lw_(R[2] + 16068);  /* 0x800A0A7C */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0A84 */
    R[5] = R[20] + R[0];  /* 0x800A0A88 */
    R[6] = R[21] + R[0];  /* 0x800A0A8C */
    R[7] = R[22] + R[0];  /* 0x800A0A90 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0A94 */
    R[2] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A0A98 */
    R[9] = HI;  /* 0x800A0A9C */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0AA0 */
    R[16] = R[16] - R[2];  /* 0x800A0AA4 */
    R[2] = R[16] << 2;  /* 0x800A0AA8 */
    R[2] = R[2] + R[16];  /* 0x800A0AAC */
    R[2] = R[2] << 1;  /* 0x800A0AB0 */
    R[4] = R[4] - R[2];  /* 0x800A0AB4 */
    { R[31] = 0x800A0AC0u; R[4] = R[4] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0AB8 jal */
    { int64_t _p = (int64_t)(int32_t)R[16] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0AC0 */
    R[5] = R[20] + R[0];  /* 0x800A0AC4 */
    R[6] = R[21] + R[0];  /* 0x800A0AC8 */
    R[7] = R[22] - 44;  /* 0x800A0ACC */
    R[2] = (uint32_t)((int32_t)R[16] >> 31);  /* 0x800A0AD0 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0AD4 */
    R[9] = HI;  /* 0x800A0AD8 */
    R[17] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0ADC */
    R[17] = R[17] - R[2];  /* 0x800A0AE0 */
    R[2] = R[17] << 2;  /* 0x800A0AE4 */
    R[2] = R[2] + R[17];  /* 0x800A0AE8 */
    R[2] = R[2] << 1;  /* 0x800A0AEC */
    R[16] = R[16] - R[2];  /* 0x800A0AF0 */
    { R[31] = 0x800A0AFCu; R[4] = R[16] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0AF4 jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0AFC */
    R[5] = R[20] + R[0];  /* 0x800A0B00 */
    R[6] = R[21] + R[0];  /* 0x800A0B04 */
    R[7] = R[22] - 88;  /* 0x800A0B08 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0B0C */
    sw_(R[29] + 16, R[0]);  /* 0x800A0B10 */
    R[9] = HI;  /* 0x800A0B14 */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0B18 */
    R[16] = R[16] - R[2];  /* 0x800A0B1C */
    R[2] = R[16] << 2;  /* 0x800A0B20 */
    R[2] = R[2] + R[16];  /* 0x800A0B24 */
    R[2] = R[2] << 1;  /* 0x800A0B28 */
    R[17] = R[17] - R[2];  /* 0x800A0B2C */
    { R[31] = 0x800A0B38u; R[4] = R[17] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0B30 jal */
    { int64_t _p = (int64_t)(int32_t)R[16] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0B38 */
    R[5] = R[20] + R[0];  /* 0x800A0B3C */
    R[6] = R[21] + R[0];  /* 0x800A0B40 */
    R[7] = R[22] - 132;  /* 0x800A0B44 */
    R[2] = (uint32_t)((int32_t)R[16] >> 31);  /* 0x800A0B48 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0B4C */
    R[9] = HI;  /* 0x800A0B50 */
    R[17] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0B54 */
    R[17] = R[17] - R[2];  /* 0x800A0B58 */
    R[2] = R[17] << 2;  /* 0x800A0B5C */
    R[2] = R[2] + R[17];  /* 0x800A0B60 */
    R[2] = R[2] << 1;  /* 0x800A0B64 */
    R[16] = R[16] - R[2];  /* 0x800A0B68 */
    { R[31] = 0x800A0B74u; R[4] = R[16] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0B6C jal */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[18]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A0B74 */
    R[5] = R[20] + R[0];  /* 0x800A0B78 */
    R[6] = R[21] + R[0];  /* 0x800A0B7C */
    R[7] = R[22] - 176;  /* 0x800A0B80 */
    R[2] = (uint32_t)((int32_t)R[17] >> 31);  /* 0x800A0B84 */
    sw_(R[29] + 16, R[0]);  /* 0x800A0B88 */
    R[9] = HI;  /* 0x800A0B8C */
    R[16] = (uint32_t)((int32_t)R[9] >> 2);  /* 0x800A0B90 */
    R[16] = R[16] - R[2];  /* 0x800A0B94 */
    R[2] = R[16] << 2;  /* 0x800A0B98 */
    R[2] = R[2] + R[16];  /* 0x800A0B9C */
    R[2] = R[2] << 1;  /* 0x800A0BA0 */
    R[17] = R[17] - R[2];  /* 0x800A0BA4 */
    { R[31] = 0x800A0BB0u; R[4] = R[17] + 30; psx_next = 0x8009A380u; return; }  /* 0x800A0BA8 jal */
}
