#include "game00_decls.h"

void g0_800A6ADC(void) {
    { uint32_t _c = (R[2] == R[0]); R[7] = 0x800Fu << 16; if (_c) { goto L_800A6AFC; } }  /* 0x800A6ADC */
    R[5] = R[17] + R[0];  /* 0x800A6AE4 */
    R[6] = R[2] + R[0];  /* 0x800A6AE8 */
    R[4] = lw_(R[16] + 12);  /* 0x800A6AEC */
    R[7] = R[7] - 14024;  /* 0x800A6AF0 */
    { R[31] = 0x800A6AFCu; sw_(R[29] + 16, R[16]); psx_next = 0x800A5A6Cu; return; }  /* 0x800A6AF4 jal */
L_800A6AFC:;
    R[31] = lw_(R[29] + 32);  /* 0x800A6AFC */
    R[17] = lw_(R[29] + 28);  /* 0x800A6B00 */
    R[16] = lw_(R[29] + 24);  /* 0x800A6B04 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A6B08 jr ra */
}

void g0_800A6AFC(void) {
    R[31] = lw_(R[29] + 32);  /* 0x800A6AFC */
    R[17] = lw_(R[29] + 28);  /* 0x800A6B00 */
    R[16] = lw_(R[29] + 24);  /* 0x800A6B04 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A6B08 jr ra */
}

void g0_800A6B10(void) {
    R[29] = R[29] - 56;  /* 0x800A6B10 */
    sw_(R[29] + 48, R[22]);  /* 0x800A6B14 */
    R[22] = R[4] + R[0];  /* 0x800A6B18 */
    sw_(R[29] + 40, R[20]);  /* 0x800A6B1C */
    R[20] = R[5] + R[0];  /* 0x800A6B20 */
    R[2] = 0x8013u << 16;  /* 0x800A6B24 */
    sw_(R[29] + 28, R[17]);  /* 0x800A6B28 */
    R[17] = R[2] - 28480;  /* 0x800A6B2C */
    sw_(R[29] + 52, R[31]);  /* 0x800A6B30 */
    sw_(R[29] + 44, R[21]);  /* 0x800A6B34 */
    sw_(R[29] + 36, R[19]);  /* 0x800A6B38 */
    sw_(R[29] + 32, R[18]);  /* 0x800A6B3C */
    sw_(R[29] + 24, R[16]);  /* 0x800A6B40 */
    R[21] = lw_(R[20] + 12);  /* 0x800A6B44 */
    { R[31] = 0x800A6B50u; R[4] = R[0] + 320; psx_next = 0x800908F4u; return; }  /* 0x800A6B48 jal */
    R[18] = R[2] + R[0];  /* 0x800A6B50 */
    R[19] = R[0] + R[0];  /* 0x800A6B54 */
L_800A6B58:;
    { R[31] = 0x800A6B60u; R[4] = R[17] + R[0]; psx_next = 0x800A592Cu; return; }  /* 0x800A6B58 jal */
    R[17] = R[2] + R[0];  /* 0x800A6B60 */
    { uint32_t _c = (R[17] == R[0]); R[4] = R[21] + R[0]; if (_c) { goto L_800A6BE8; } }  /* 0x800A6B64 */
    R[7] = 0x800Fu << 16;  /* 0x800A6B6C */
    R[5] = R[22] + R[0];  /* 0x800A6B70 */
    R[6] = R[17] + R[0];  /* 0x800A6B74 */
    R[7] = R[7] - 14000;  /* 0x800A6B78 */
    { R[31] = 0x800A6B84u; sw_(R[29] + 16, R[20]); psx_next = 0x800A5A6Cu; return; }  /* 0x800A6B7C jal */
    { R[31] = 0x800A6B8Cu; R[4] = R[0] + 8; psx_next = 0x800908F4u; return; }  /* 0x800A6B84 jal */
    R[4] = R[18] + R[0];  /* 0x800A6B8C */
    { R[31] = 0x800A6B98u; R[16] = R[2] + 8; psx_next = 0x80035B18u; return; }  /* 0x800A6B90 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6B98 */
    R[4] = R[0] + 4;  /* 0x800A6B9C */
    R[8] = LO;  /* 0x800A6BA0 */
    { R[31] = 0x800A6BACu; sw_(R[17] + 32, R[8]); psx_next = 0x800908F4u; return; }  /* 0x800A6BA4 jal */
    R[4] = R[18] + R[0];  /* 0x800A6BAC */
    R[2] = R[2] << 12;  /* 0x800A6BB0 */
    R[3] = R[0] | 0xC1EE;  /* 0x800A6BB4 */
    R[2] = R[2] + R[3];  /* 0x800A6BB8 */
    R[2] = R[0] - R[2];  /* 0x800A6BBC */
    { R[31] = 0x800A6BC8u; sw_(R[17] + 36, R[2]); psx_next = 0x80035A48u; return; }  /* 0x800A6BC0 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6BC8 */
    R[19] = R[19] + 1;  /* 0x800A6BCC */
    R[2] = R[18] + 682;  /* 0x800A6BD0 */
    R[18] = R[2] & 0xFFF;  /* 0x800A6BD4 */
    R[2] = R[0] + 6;  /* 0x800A6BD8 */
    R[8] = LO;  /* 0x800A6BDC */
    { uint32_t _c = (R[19] != R[2]); sw_(R[17] + 40, R[8]); if (_c) { psx_bb(); goto L_800A6B58; } }  /* 0x800A6BE0 */
L_800A6BE8:;
    R[31] = lw_(R[29] + 52);  /* 0x800A6BE8 */
    R[22] = lw_(R[29] + 48);  /* 0x800A6BEC */
    R[21] = lw_(R[29] + 44);  /* 0x800A6BF0 */
    R[20] = lw_(R[29] + 40);  /* 0x800A6BF4 */
    R[19] = lw_(R[29] + 36);  /* 0x800A6BF8 */
    R[18] = lw_(R[29] + 32);  /* 0x800A6BFC */
    R[17] = lw_(R[29] + 28);  /* 0x800A6C00 */
    R[16] = lw_(R[29] + 24);  /* 0x800A6C04 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800A6C08 jr ra */
}

void g0_800A6B50(void) {
    R[18] = R[2] + R[0];  /* 0x800A6B50 */
    R[19] = R[0] + R[0];  /* 0x800A6B54 */
L_800A6B58:;
    { R[31] = 0x800A6B60u; R[4] = R[17] + R[0]; psx_next = 0x800A592Cu; return; }  /* 0x800A6B58 jal */
    R[17] = R[2] + R[0];  /* 0x800A6B60 */
    { uint32_t _c = (R[17] == R[0]); R[4] = R[21] + R[0]; if (_c) { goto L_800A6BE8; } }  /* 0x800A6B64 */
    R[7] = 0x800Fu << 16;  /* 0x800A6B6C */
    R[5] = R[22] + R[0];  /* 0x800A6B70 */
    R[6] = R[17] + R[0];  /* 0x800A6B74 */
    R[7] = R[7] - 14000;  /* 0x800A6B78 */
    { R[31] = 0x800A6B84u; sw_(R[29] + 16, R[20]); psx_next = 0x800A5A6Cu; return; }  /* 0x800A6B7C jal */
    { R[31] = 0x800A6B8Cu; R[4] = R[0] + 8; psx_next = 0x800908F4u; return; }  /* 0x800A6B84 jal */
    R[4] = R[18] + R[0];  /* 0x800A6B8C */
    { R[31] = 0x800A6B98u; R[16] = R[2] + 8; psx_next = 0x80035B18u; return; }  /* 0x800A6B90 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6B98 */
    R[4] = R[0] + 4;  /* 0x800A6B9C */
    R[8] = LO;  /* 0x800A6BA0 */
    { R[31] = 0x800A6BACu; sw_(R[17] + 32, R[8]); psx_next = 0x800908F4u; return; }  /* 0x800A6BA4 jal */
    R[4] = R[18] + R[0];  /* 0x800A6BAC */
    R[2] = R[2] << 12;  /* 0x800A6BB0 */
    R[3] = R[0] | 0xC1EE;  /* 0x800A6BB4 */
    R[2] = R[2] + R[3];  /* 0x800A6BB8 */
    R[2] = R[0] - R[2];  /* 0x800A6BBC */
    { R[31] = 0x800A6BC8u; sw_(R[17] + 36, R[2]); psx_next = 0x80035A48u; return; }  /* 0x800A6BC0 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6BC8 */
    R[19] = R[19] + 1;  /* 0x800A6BCC */
    R[2] = R[18] + 682;  /* 0x800A6BD0 */
    R[18] = R[2] & 0xFFF;  /* 0x800A6BD4 */
    R[2] = R[0] + 6;  /* 0x800A6BD8 */
    R[8] = LO;  /* 0x800A6BDC */
    { uint32_t _c = (R[19] != R[2]); sw_(R[17] + 40, R[8]); if (_c) { psx_bb(); goto L_800A6B58; } }  /* 0x800A6BE0 */
L_800A6BE8:;
    R[31] = lw_(R[29] + 52);  /* 0x800A6BE8 */
    R[22] = lw_(R[29] + 48);  /* 0x800A6BEC */
    R[21] = lw_(R[29] + 44);  /* 0x800A6BF0 */
    R[20] = lw_(R[29] + 40);  /* 0x800A6BF4 */
    R[19] = lw_(R[29] + 36);  /* 0x800A6BF8 */
    R[18] = lw_(R[29] + 32);  /* 0x800A6BFC */
    R[17] = lw_(R[29] + 28);  /* 0x800A6C00 */
    R[16] = lw_(R[29] + 24);  /* 0x800A6C04 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800A6C08 jr ra */
}

void g0_800A6B58(void) {
L_800A6B58:;
    { R[31] = 0x800A6B60u; R[4] = R[17] + R[0]; psx_next = 0x800A592Cu; return; }  /* 0x800A6B58 jal */
    R[17] = R[2] + R[0];  /* 0x800A6B60 */
    { uint32_t _c = (R[17] == R[0]); R[4] = R[21] + R[0]; if (_c) { goto L_800A6BE8; } }  /* 0x800A6B64 */
    R[7] = 0x800Fu << 16;  /* 0x800A6B6C */
    R[5] = R[22] + R[0];  /* 0x800A6B70 */
    R[6] = R[17] + R[0];  /* 0x800A6B74 */
    R[7] = R[7] - 14000;  /* 0x800A6B78 */
    { R[31] = 0x800A6B84u; sw_(R[29] + 16, R[20]); psx_next = 0x800A5A6Cu; return; }  /* 0x800A6B7C jal */
    { R[31] = 0x800A6B8Cu; R[4] = R[0] + 8; psx_next = 0x800908F4u; return; }  /* 0x800A6B84 jal */
    R[4] = R[18] + R[0];  /* 0x800A6B8C */
    { R[31] = 0x800A6B98u; R[16] = R[2] + 8; psx_next = 0x80035B18u; return; }  /* 0x800A6B90 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6B98 */
    R[4] = R[0] + 4;  /* 0x800A6B9C */
    R[8] = LO;  /* 0x800A6BA0 */
    { R[31] = 0x800A6BACu; sw_(R[17] + 32, R[8]); psx_next = 0x800908F4u; return; }  /* 0x800A6BA4 jal */
    R[4] = R[18] + R[0];  /* 0x800A6BAC */
    R[2] = R[2] << 12;  /* 0x800A6BB0 */
    R[3] = R[0] | 0xC1EE;  /* 0x800A6BB4 */
    R[2] = R[2] + R[3];  /* 0x800A6BB8 */
    R[2] = R[0] - R[2];  /* 0x800A6BBC */
    { R[31] = 0x800A6BC8u; sw_(R[17] + 36, R[2]); psx_next = 0x80035A48u; return; }  /* 0x800A6BC0 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6BC8 */
    R[19] = R[19] + 1;  /* 0x800A6BCC */
    R[2] = R[18] + 682;  /* 0x800A6BD0 */
    R[18] = R[2] & 0xFFF;  /* 0x800A6BD4 */
    R[2] = R[0] + 6;  /* 0x800A6BD8 */
    R[8] = LO;  /* 0x800A6BDC */
    { uint32_t _c = (R[19] != R[2]); sw_(R[17] + 40, R[8]); if (_c) { psx_bb(); goto L_800A6B58; } }  /* 0x800A6BE0 */
L_800A6BE8:;
    R[31] = lw_(R[29] + 52);  /* 0x800A6BE8 */
    R[22] = lw_(R[29] + 48);  /* 0x800A6BEC */
    R[21] = lw_(R[29] + 44);  /* 0x800A6BF0 */
    R[20] = lw_(R[29] + 40);  /* 0x800A6BF4 */
    R[19] = lw_(R[29] + 36);  /* 0x800A6BF8 */
    R[18] = lw_(R[29] + 32);  /* 0x800A6BFC */
    R[17] = lw_(R[29] + 28);  /* 0x800A6C00 */
    R[16] = lw_(R[29] + 24);  /* 0x800A6C04 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800A6C08 jr ra */
}

void g0_800A6B60(void) {
    R[17] = R[2] + R[0];  /* 0x800A6B60 */
    { uint32_t _c = (R[17] == R[0]); R[4] = R[21] + R[0]; if (_c) { goto L_800A6BE8; } }  /* 0x800A6B64 */
    R[7] = 0x800Fu << 16;  /* 0x800A6B6C */
    R[5] = R[22] + R[0];  /* 0x800A6B70 */
    R[6] = R[17] + R[0];  /* 0x800A6B74 */
    R[7] = R[7] - 14000;  /* 0x800A6B78 */
    { R[31] = 0x800A6B84u; sw_(R[29] + 16, R[20]); psx_next = 0x800A5A6Cu; return; }  /* 0x800A6B7C jal */
    { R[31] = 0x800A6B8Cu; R[4] = R[0] + 8; psx_next = 0x800908F4u; return; }  /* 0x800A6B84 jal */
    R[4] = R[18] + R[0];  /* 0x800A6B8C */
    { R[31] = 0x800A6B98u; R[16] = R[2] + 8; psx_next = 0x80035B18u; return; }  /* 0x800A6B90 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6B98 */
    R[4] = R[0] + 4;  /* 0x800A6B9C */
    R[8] = LO;  /* 0x800A6BA0 */
    { R[31] = 0x800A6BACu; sw_(R[17] + 32, R[8]); psx_next = 0x800908F4u; return; }  /* 0x800A6BA4 jal */
    R[4] = R[18] + R[0];  /* 0x800A6BAC */
    R[2] = R[2] << 12;  /* 0x800A6BB0 */
    R[3] = R[0] | 0xC1EE;  /* 0x800A6BB4 */
    R[2] = R[2] + R[3];  /* 0x800A6BB8 */
    R[2] = R[0] - R[2];  /* 0x800A6BBC */
    { R[31] = 0x800A6BC8u; sw_(R[17] + 36, R[2]); psx_next = 0x80035A48u; return; }  /* 0x800A6BC0 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6BC8 */
    R[19] = R[19] + 1;  /* 0x800A6BCC */
    R[2] = R[18] + 682;  /* 0x800A6BD0 */
    R[18] = R[2] & 0xFFF;  /* 0x800A6BD4 */
    R[2] = R[0] + 6;  /* 0x800A6BD8 */
    R[8] = LO;  /* 0x800A6BDC */
    { uint32_t _c = (R[19] != R[2]); sw_(R[17] + 40, R[8]); if (_c) { psx_next = 0x800A6B58u; return; } }  /* 0x800A6BE0 b extern */
L_800A6BE8:;
    R[31] = lw_(R[29] + 52);  /* 0x800A6BE8 */
    R[22] = lw_(R[29] + 48);  /* 0x800A6BEC */
    R[21] = lw_(R[29] + 44);  /* 0x800A6BF0 */
    R[20] = lw_(R[29] + 40);  /* 0x800A6BF4 */
    R[19] = lw_(R[29] + 36);  /* 0x800A6BF8 */
    R[18] = lw_(R[29] + 32);  /* 0x800A6BFC */
    R[17] = lw_(R[29] + 28);  /* 0x800A6C00 */
    R[16] = lw_(R[29] + 24);  /* 0x800A6C04 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800A6C08 jr ra */
}

void g0_800A6B84(void) {
    { R[31] = 0x800A6B8Cu; R[4] = R[0] + 8; psx_next = 0x800908F4u; return; }  /* 0x800A6B84 jal */
    R[4] = R[18] + R[0];  /* 0x800A6B8C */
    { R[31] = 0x800A6B98u; R[16] = R[2] + 8; psx_next = 0x80035B18u; return; }  /* 0x800A6B90 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6B98 */
    R[4] = R[0] + 4;  /* 0x800A6B9C */
    R[8] = LO;  /* 0x800A6BA0 */
    { R[31] = 0x800A6BACu; sw_(R[17] + 32, R[8]); psx_next = 0x800908F4u; return; }  /* 0x800A6BA4 jal */
    R[4] = R[18] + R[0];  /* 0x800A6BAC */
    R[2] = R[2] << 12;  /* 0x800A6BB0 */
    R[3] = R[0] | 0xC1EE;  /* 0x800A6BB4 */
    R[2] = R[2] + R[3];  /* 0x800A6BB8 */
    R[2] = R[0] - R[2];  /* 0x800A6BBC */
    { R[31] = 0x800A6BC8u; sw_(R[17] + 36, R[2]); psx_next = 0x80035A48u; return; }  /* 0x800A6BC0 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6BC8 */
    R[19] = R[19] + 1;  /* 0x800A6BCC */
    R[2] = R[18] + 682;  /* 0x800A6BD0 */
    R[18] = R[2] & 0xFFF;  /* 0x800A6BD4 */
    R[2] = R[0] + 6;  /* 0x800A6BD8 */
    R[8] = LO;  /* 0x800A6BDC */
    { uint32_t _c = (R[19] != R[2]); sw_(R[17] + 40, R[8]); if (_c) { psx_next = 0x800A6B58u; return; } }  /* 0x800A6BE0 b extern */
    R[31] = lw_(R[29] + 52);  /* 0x800A6BE8 */
    R[22] = lw_(R[29] + 48);  /* 0x800A6BEC */
    R[21] = lw_(R[29] + 44);  /* 0x800A6BF0 */
    R[20] = lw_(R[29] + 40);  /* 0x800A6BF4 */
    R[19] = lw_(R[29] + 36);  /* 0x800A6BF8 */
    R[18] = lw_(R[29] + 32);  /* 0x800A6BFC */
    R[17] = lw_(R[29] + 28);  /* 0x800A6C00 */
    R[16] = lw_(R[29] + 24);  /* 0x800A6C04 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800A6C08 jr ra */
}

void g0_800A6B8C(void) {
    R[4] = R[18] + R[0];  /* 0x800A6B8C */
    { R[31] = 0x800A6B98u; R[16] = R[2] + 8; psx_next = 0x80035B18u; return; }  /* 0x800A6B90 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6B98 */
    R[4] = R[0] + 4;  /* 0x800A6B9C */
    R[8] = LO;  /* 0x800A6BA0 */
    { R[31] = 0x800A6BACu; sw_(R[17] + 32, R[8]); psx_next = 0x800908F4u; return; }  /* 0x800A6BA4 jal */
    R[4] = R[18] + R[0];  /* 0x800A6BAC */
    R[2] = R[2] << 12;  /* 0x800A6BB0 */
    R[3] = R[0] | 0xC1EE;  /* 0x800A6BB4 */
    R[2] = R[2] + R[3];  /* 0x800A6BB8 */
    R[2] = R[0] - R[2];  /* 0x800A6BBC */
    { R[31] = 0x800A6BC8u; sw_(R[17] + 36, R[2]); psx_next = 0x80035A48u; return; }  /* 0x800A6BC0 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6BC8 */
    R[19] = R[19] + 1;  /* 0x800A6BCC */
    R[2] = R[18] + 682;  /* 0x800A6BD0 */
    R[18] = R[2] & 0xFFF;  /* 0x800A6BD4 */
    R[2] = R[0] + 6;  /* 0x800A6BD8 */
    R[8] = LO;  /* 0x800A6BDC */
    { uint32_t _c = (R[19] != R[2]); sw_(R[17] + 40, R[8]); if (_c) { psx_next = 0x800A6B58u; return; } }  /* 0x800A6BE0 b extern */
    R[31] = lw_(R[29] + 52);  /* 0x800A6BE8 */
    R[22] = lw_(R[29] + 48);  /* 0x800A6BEC */
    R[21] = lw_(R[29] + 44);  /* 0x800A6BF0 */
    R[20] = lw_(R[29] + 40);  /* 0x800A6BF4 */
    R[19] = lw_(R[29] + 36);  /* 0x800A6BF8 */
    R[18] = lw_(R[29] + 32);  /* 0x800A6BFC */
    R[17] = lw_(R[29] + 28);  /* 0x800A6C00 */
    R[16] = lw_(R[29] + 24);  /* 0x800A6C04 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800A6C08 jr ra */
}

void g0_800A6B98(void) {
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6B98 */
    R[4] = R[0] + 4;  /* 0x800A6B9C */
    R[8] = LO;  /* 0x800A6BA0 */
    { R[31] = 0x800A6BACu; sw_(R[17] + 32, R[8]); psx_next = 0x800908F4u; return; }  /* 0x800A6BA4 jal */
    R[4] = R[18] + R[0];  /* 0x800A6BAC */
    R[2] = R[2] << 12;  /* 0x800A6BB0 */
    R[3] = R[0] | 0xC1EE;  /* 0x800A6BB4 */
    R[2] = R[2] + R[3];  /* 0x800A6BB8 */
    R[2] = R[0] - R[2];  /* 0x800A6BBC */
    { R[31] = 0x800A6BC8u; sw_(R[17] + 36, R[2]); psx_next = 0x80035A48u; return; }  /* 0x800A6BC0 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6BC8 */
    R[19] = R[19] + 1;  /* 0x800A6BCC */
    R[2] = R[18] + 682;  /* 0x800A6BD0 */
    R[18] = R[2] & 0xFFF;  /* 0x800A6BD4 */
    R[2] = R[0] + 6;  /* 0x800A6BD8 */
    R[8] = LO;  /* 0x800A6BDC */
    { uint32_t _c = (R[19] != R[2]); sw_(R[17] + 40, R[8]); if (_c) { psx_next = 0x800A6B58u; return; } }  /* 0x800A6BE0 b extern */
    R[31] = lw_(R[29] + 52);  /* 0x800A6BE8 */
    R[22] = lw_(R[29] + 48);  /* 0x800A6BEC */
    R[21] = lw_(R[29] + 44);  /* 0x800A6BF0 */
    R[20] = lw_(R[29] + 40);  /* 0x800A6BF4 */
    R[19] = lw_(R[29] + 36);  /* 0x800A6BF8 */
    R[18] = lw_(R[29] + 32);  /* 0x800A6BFC */
    R[17] = lw_(R[29] + 28);  /* 0x800A6C00 */
    R[16] = lw_(R[29] + 24);  /* 0x800A6C04 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800A6C08 jr ra */
}

void g0_800A6BAC(void) {
    R[4] = R[18] + R[0];  /* 0x800A6BAC */
    R[2] = R[2] << 12;  /* 0x800A6BB0 */
    R[3] = R[0] | 0xC1EE;  /* 0x800A6BB4 */
    R[2] = R[2] + R[3];  /* 0x800A6BB8 */
    R[2] = R[0] - R[2];  /* 0x800A6BBC */
    { R[31] = 0x800A6BC8u; sw_(R[17] + 36, R[2]); psx_next = 0x80035A48u; return; }  /* 0x800A6BC0 jal */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6BC8 */
    R[19] = R[19] + 1;  /* 0x800A6BCC */
    R[2] = R[18] + 682;  /* 0x800A6BD0 */
    R[18] = R[2] & 0xFFF;  /* 0x800A6BD4 */
    R[2] = R[0] + 6;  /* 0x800A6BD8 */
    R[8] = LO;  /* 0x800A6BDC */
    { uint32_t _c = (R[19] != R[2]); sw_(R[17] + 40, R[8]); if (_c) { psx_next = 0x800A6B58u; return; } }  /* 0x800A6BE0 b extern */
    R[31] = lw_(R[29] + 52);  /* 0x800A6BE8 */
    R[22] = lw_(R[29] + 48);  /* 0x800A6BEC */
    R[21] = lw_(R[29] + 44);  /* 0x800A6BF0 */
    R[20] = lw_(R[29] + 40);  /* 0x800A6BF4 */
    R[19] = lw_(R[29] + 36);  /* 0x800A6BF8 */
    R[18] = lw_(R[29] + 32);  /* 0x800A6BFC */
    R[17] = lw_(R[29] + 28);  /* 0x800A6C00 */
    R[16] = lw_(R[29] + 24);  /* 0x800A6C04 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800A6C08 jr ra */
}

void g0_800A6BC8(void) {
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[16]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6BC8 */
    R[19] = R[19] + 1;  /* 0x800A6BCC */
    R[2] = R[18] + 682;  /* 0x800A6BD0 */
    R[18] = R[2] & 0xFFF;  /* 0x800A6BD4 */
    R[2] = R[0] + 6;  /* 0x800A6BD8 */
    R[8] = LO;  /* 0x800A6BDC */
    { uint32_t _c = (R[19] != R[2]); sw_(R[17] + 40, R[8]); if (_c) { psx_next = 0x800A6B58u; return; } }  /* 0x800A6BE0 b extern */
    R[31] = lw_(R[29] + 52);  /* 0x800A6BE8 */
    R[22] = lw_(R[29] + 48);  /* 0x800A6BEC */
    R[21] = lw_(R[29] + 44);  /* 0x800A6BF0 */
    R[20] = lw_(R[29] + 40);  /* 0x800A6BF4 */
    R[19] = lw_(R[29] + 36);  /* 0x800A6BF8 */
    R[18] = lw_(R[29] + 32);  /* 0x800A6BFC */
    R[17] = lw_(R[29] + 28);  /* 0x800A6C00 */
    R[16] = lw_(R[29] + 24);  /* 0x800A6C04 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800A6C08 jr ra */
}

void g0_800A6C10(void) {
    R[29] = R[29] - 32;  /* 0x800A6C10 */
    sw_(R[29] + 20, R[17]);  /* 0x800A6C14 */
    R[17] = R[4] + R[0];  /* 0x800A6C18 */
    sw_(R[29] + 24, R[18]);  /* 0x800A6C1C */
    R[18] = R[5] + R[0];  /* 0x800A6C20 */
    R[4] = 0x8013u << 16;  /* 0x800A6C24 */
    R[4] = R[4] - 28480;  /* 0x800A6C28 */
    sw_(R[29] + 28, R[31]);  /* 0x800A6C2C */
    { R[31] = 0x800A6C38u; sw_(R[29] + 16, R[16]); psx_next = 0x800A592Cu; return; }  /* 0x800A6C30 jal */
    R[16] = R[2] + R[0];  /* 0x800A6C38 */
    { uint32_t _c = (R[16] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800A6C78; } }  /* 0x800A6C3C */
    R[6] = 0x800Fu << 16;  /* 0x800A6C44 */
    R[5] = R[16] + R[0];  /* 0x800A6C48 */
    R[6] = R[6] - 13976;  /* 0x800A6C4C */
    { R[31] = 0x800A6C58u; R[7] = R[18] + R[0]; psx_next = 0x800A5964u; return; }  /* 0x800A6C50 jal */
    R[4] = R[0] + 2;  /* 0x800A6C58 */
    { R[31] = 0x800A6C64u; sw_(R[16] + 32, R[0]); psx_next = 0x800908F4u; return; }  /* 0x800A6C5C jal */
    R[2] = R[2] << 12;  /* 0x800A6C64 */
    R[2] = R[2] + 8192;  /* 0x800A6C68 */
    R[2] = R[0] - R[2];  /* 0x800A6C6C */
    sw_(R[16] + 36, R[2]);  /* 0x800A6C70 */
    sw_(R[16] + 40, R[0]);  /* 0x800A6C74 */
L_800A6C78:;
    R[31] = lw_(R[29] + 28);  /* 0x800A6C78 */
    R[18] = lw_(R[29] + 24);  /* 0x800A6C7C */
    R[17] = lw_(R[29] + 20);  /* 0x800A6C80 */
    R[16] = lw_(R[29] + 16);  /* 0x800A6C84 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800A6C88 jr ra */
}

void g0_800A6C38(void) {
    R[16] = R[2] + R[0];  /* 0x800A6C38 */
    { uint32_t _c = (R[16] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_800A6C78; } }  /* 0x800A6C3C */
    R[6] = 0x800Fu << 16;  /* 0x800A6C44 */
    R[5] = R[16] + R[0];  /* 0x800A6C48 */
    R[6] = R[6] - 13976;  /* 0x800A6C4C */
    { R[31] = 0x800A6C58u; R[7] = R[18] + R[0]; psx_next = 0x800A5964u; return; }  /* 0x800A6C50 jal */
    R[4] = R[0] + 2;  /* 0x800A6C58 */
    { R[31] = 0x800A6C64u; sw_(R[16] + 32, R[0]); psx_next = 0x800908F4u; return; }  /* 0x800A6C5C jal */
    R[2] = R[2] << 12;  /* 0x800A6C64 */
    R[2] = R[2] + 8192;  /* 0x800A6C68 */
    R[2] = R[0] - R[2];  /* 0x800A6C6C */
    sw_(R[16] + 36, R[2]);  /* 0x800A6C70 */
    sw_(R[16] + 40, R[0]);  /* 0x800A6C74 */
L_800A6C78:;
    R[31] = lw_(R[29] + 28);  /* 0x800A6C78 */
    R[18] = lw_(R[29] + 24);  /* 0x800A6C7C */
    R[17] = lw_(R[29] + 20);  /* 0x800A6C80 */
    R[16] = lw_(R[29] + 16);  /* 0x800A6C84 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800A6C88 jr ra */
}

void g0_800A6C58(void) {
    R[4] = R[0] + 2;  /* 0x800A6C58 */
    { R[31] = 0x800A6C64u; sw_(R[16] + 32, R[0]); psx_next = 0x800908F4u; return; }  /* 0x800A6C5C jal */
    R[2] = R[2] << 12;  /* 0x800A6C64 */
    R[2] = R[2] + 8192;  /* 0x800A6C68 */
    R[2] = R[0] - R[2];  /* 0x800A6C6C */
    sw_(R[16] + 36, R[2]);  /* 0x800A6C70 */
    sw_(R[16] + 40, R[0]);  /* 0x800A6C74 */
    R[31] = lw_(R[29] + 28);  /* 0x800A6C78 */
    R[18] = lw_(R[29] + 24);  /* 0x800A6C7C */
    R[17] = lw_(R[29] + 20);  /* 0x800A6C80 */
    R[16] = lw_(R[29] + 16);  /* 0x800A6C84 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800A6C88 jr ra */
}

void g0_800A6C64(void) {
    R[2] = R[2] << 12;  /* 0x800A6C64 */
    R[2] = R[2] + 8192;  /* 0x800A6C68 */
    R[2] = R[0] - R[2];  /* 0x800A6C6C */
    sw_(R[16] + 36, R[2]);  /* 0x800A6C70 */
    sw_(R[16] + 40, R[0]);  /* 0x800A6C74 */
    R[31] = lw_(R[29] + 28);  /* 0x800A6C78 */
    R[18] = lw_(R[29] + 24);  /* 0x800A6C7C */
    R[17] = lw_(R[29] + 20);  /* 0x800A6C80 */
    R[16] = lw_(R[29] + 16);  /* 0x800A6C84 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800A6C88 jr ra */
}

void g0_800A6C90(void) {
    R[29] = R[29] - 40;  /* 0x800A6C90 */
    sw_(R[29] + 28, R[17]);  /* 0x800A6C94 */
    R[17] = R[4] + R[0];  /* 0x800A6C98 */
    sw_(R[29] + 24, R[16]);  /* 0x800A6C9C */
    R[16] = R[5] + R[0];  /* 0x800A6CA0 */
    R[4] = 0x8013u << 16;  /* 0x800A6CA4 */
    sw_(R[29] + 32, R[31]);  /* 0x800A6CA8 */
    { R[31] = 0x800A6CB4u; R[4] = R[4] - 28480; psx_next = 0x800A592Cu; return; }  /* 0x800A6CAC jal */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[17] + R[0]; if (_c) { goto L_800A6CD4; } }  /* 0x800A6CB4 */
    R[7] = 0x800Fu << 16;  /* 0x800A6CBC */
    R[6] = R[2] + R[0];  /* 0x800A6CC0 */
    sw_(R[29] + 16, R[16]);  /* 0x800A6CC4 */
    R[4] = lw_(R[16] + 12);  /* 0x800A6CC8 */
    { R[31] = 0x800A6CD4u; R[7] = R[7] - 13952; psx_next = 0x800A5A6Cu; return; }  /* 0x800A6CCC jal */
L_800A6CD4:;
    R[31] = lw_(R[29] + 32);  /* 0x800A6CD4 */
    R[17] = lw_(R[29] + 28);  /* 0x800A6CD8 */
    R[16] = lw_(R[29] + 24);  /* 0x800A6CDC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A6CE0 jr ra */
}

void g0_800A6CB4(void) {
    { uint32_t _c = (R[2] == R[0]); R[5] = R[17] + R[0]; if (_c) { goto L_800A6CD4; } }  /* 0x800A6CB4 */
    R[7] = 0x800Fu << 16;  /* 0x800A6CBC */
    R[6] = R[2] + R[0];  /* 0x800A6CC0 */
    sw_(R[29] + 16, R[16]);  /* 0x800A6CC4 */
    R[4] = lw_(R[16] + 12);  /* 0x800A6CC8 */
    { R[31] = 0x800A6CD4u; R[7] = R[7] - 13952; psx_next = 0x800A5A6Cu; return; }  /* 0x800A6CCC jal */
L_800A6CD4:;
    R[31] = lw_(R[29] + 32);  /* 0x800A6CD4 */
    R[17] = lw_(R[29] + 28);  /* 0x800A6CD8 */
    R[16] = lw_(R[29] + 24);  /* 0x800A6CDC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A6CE0 jr ra */
}

void g0_800A6CD4(void) {
    R[31] = lw_(R[29] + 32);  /* 0x800A6CD4 */
    R[17] = lw_(R[29] + 28);  /* 0x800A6CD8 */
    R[16] = lw_(R[29] + 24);  /* 0x800A6CDC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A6CE0 jr ra */
}

void g0_800A6CE8(void) {
    R[29] = R[29] - 32;  /* 0x800A6CE8 */
    sw_(R[29] + 16, R[16]);  /* 0x800A6CEC */
    R[16] = R[4] + R[0];  /* 0x800A6CF0 */
    sw_(R[29] + 20, R[17]);  /* 0x800A6CF4 */
    R[17] = R[5] + R[0];  /* 0x800A6CF8 */
    R[4] = 0x8014u << 16;  /* 0x800A6CFC */
    sw_(R[29] + 24, R[31]);  /* 0x800A6D00 */
    { R[31] = 0x800A6D0Cu; R[4] = R[4] + 15160; psx_next = 0x800A592Cu; return; }  /* 0x800A6D04 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_800A6D28; } }  /* 0x800A6D0C */
    R[6] = 0x800Fu << 16;  /* 0x800A6D14 */
    R[5] = R[2] + R[0];  /* 0x800A6D18 */
    R[6] = R[6] - 13928;  /* 0x800A6D1C */
    { R[31] = 0x800A6D28u; R[7] = R[17] + R[0]; psx_next = 0x800A5964u; return; }  /* 0x800A6D20 jal */
L_800A6D28:;
    R[31] = lw_(R[29] + 24);  /* 0x800A6D28 */
    R[17] = lw_(R[29] + 20);  /* 0x800A6D2C */
    R[16] = lw_(R[29] + 16);  /* 0x800A6D30 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800A6D34 jr ra */
}

void g0_800A6D0C(void) {
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_800A6D28; } }  /* 0x800A6D0C */
    R[6] = 0x800Fu << 16;  /* 0x800A6D14 */
    R[5] = R[2] + R[0];  /* 0x800A6D18 */
    R[6] = R[6] - 13928;  /* 0x800A6D1C */
    { R[31] = 0x800A6D28u; R[7] = R[17] + R[0]; psx_next = 0x800A5964u; return; }  /* 0x800A6D20 jal */
L_800A6D28:;
    R[31] = lw_(R[29] + 24);  /* 0x800A6D28 */
    R[17] = lw_(R[29] + 20);  /* 0x800A6D2C */
    R[16] = lw_(R[29] + 16);  /* 0x800A6D30 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800A6D34 jr ra */
}

void g0_800A6D28(void) {
    R[31] = lw_(R[29] + 24);  /* 0x800A6D28 */
    R[17] = lw_(R[29] + 20);  /* 0x800A6D2C */
    R[16] = lw_(R[29] + 16);  /* 0x800A6D30 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800A6D34 jr ra */
}

void g0_800A6D3C(void) {
    R[29] = R[29] - 48;  /* 0x800A6D3C */
    sw_(R[29] + 36, R[21]);  /* 0x800A6D40 */
    R[21] = R[4] + R[0];  /* 0x800A6D44 */
    sw_(R[29] + 24, R[18]);  /* 0x800A6D48 */
    R[18] = R[5] + R[0];  /* 0x800A6D4C */
    R[2] = 0x8013u << 16;  /* 0x800A6D50 */
    sw_(R[29] + 16, R[16]);  /* 0x800A6D54 */
    R[16] = R[2] - 28480;  /* 0x800A6D58 */
    sw_(R[29] + 28, R[19]);  /* 0x800A6D5C */
    sw_(R[29] + 40, R[31]);  /* 0x800A6D60 */
    sw_(R[29] + 32, R[20]);  /* 0x800A6D64 */
    sw_(R[29] + 20, R[17]);  /* 0x800A6D68 */
    R[3] = lw_(R[18] + 12);  /* 0x800A6D6C */
    R[2] = R[0] + 3;  /* 0x800A6D70 */
    { uint32_t _c = (R[3] != R[2]); R[19] = R[0] + 1; if (_c) { goto L_800A6D80; } }  /* 0x800A6D74 */
    R[19] = R[0] + 2;  /* 0x800A6D7C */
L_800A6D80:;
    { uint32_t _c = (R[19] == R[0]); R[17] = R[0] + R[0]; if (_c) { goto L_800A6E20; } }  /* 0x800A6D80 */
    R[20] = 0xFFFCu << 16;  /* 0x800A6D88 */
L_800A6D8C:;
    { R[31] = 0x800A6D94u; R[4] = R[16] + R[0]; psx_next = 0x800A592Cu; return; }  /* 0x800A6D8C jal */
    R[16] = R[2] + R[0];  /* 0x800A6D94 */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_800A6E20; } }  /* 0x800A6D98 */
    { R[31] = 0x800A6DA8u; R[4] = R[0] + 16; psx_next = 0x800908F4u; return; }  /* 0x800A6DA0 jal */
    R[4] = R[0] + 16;  /* 0x800A6DA8 */
    R[2] = R[2] << 15;  /* 0x800A6DAC */
    R[3] = lw_(R[18]);  /* 0x800A6DB0 */
    R[2] = R[2] + R[20];  /* 0x800A6DB4 */
    R[3] = R[3] + R[2];  /* 0x800A6DB8 */
    { R[31] = 0x800A6DC4u; sw_(R[18], R[3]); psx_next = 0x800908F4u; return; }  /* 0x800A6DBC jal */
    R[4] = R[21] + R[0];  /* 0x800A6DC4 */
    R[2] = R[2] << 15;  /* 0x800A6DC8 */
    R[2] = R[2] + R[20];  /* 0x800A6DCC */
    R[6] = 0x800Fu << 16;  /* 0x800A6DD0 */
    R[5] = R[16] + R[0];  /* 0x800A6DD4 */
    R[6] = R[6] - 13904;  /* 0x800A6DD8 */
    R[3] = lw_(R[18] + 8);  /* 0x800A6DDC */
    R[7] = R[18] + R[0];  /* 0x800A6DE0 */
    R[3] = R[3] + R[2];  /* 0x800A6DE4 */
    { R[31] = 0x800A6DF0u; sw_(R[18] + 8, R[3]); psx_next = 0x800A5964u; return; }  /* 0x800A6DE8 jal */
    R[3] = lw_(R[18] + 12);  /* 0x800A6DF0 */
    R[2] = R[0] + 2;  /* 0x800A6DF4 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_800A6E08; } }  /* 0x800A6DF8 */
    { uint32_t _c = (R[17] != R[2]); if (_c) { goto L_800A6E14; } }  /* 0x800A6E00 */
L_800A6E08:;
    R[2] = 0x2E62u << 16;  /* 0x800A6E08 */
    R[2] = R[2] | 0x8010;  /* 0x800A6E0C */
    sw_(R[16] + 44, R[2]);  /* 0x800A6E10 */
L_800A6E14:;
    R[17] = R[17] + 1;  /* 0x800A6E14 */
    { uint32_t _c = (R[17] != R[19]); if (_c) { psx_bb(); goto L_800A6D8C; } }  /* 0x800A6E18 */
L_800A6E20:;
    R[31] = lw_(R[29] + 40);  /* 0x800A6E20 */
    R[21] = lw_(R[29] + 36);  /* 0x800A6E24 */
    R[20] = lw_(R[29] + 32);  /* 0x800A6E28 */
    R[19] = lw_(R[29] + 28);  /* 0x800A6E2C */
    R[18] = lw_(R[29] + 24);  /* 0x800A6E30 */
    R[17] = lw_(R[29] + 20);  /* 0x800A6E34 */
    R[16] = lw_(R[29] + 16);  /* 0x800A6E38 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A6E3C jr ra */
}

void g0_800A6D8C(void) {
L_800A6D8C:;
    { R[31] = 0x800A6D94u; R[4] = R[16] + R[0]; psx_next = 0x800A592Cu; return; }  /* 0x800A6D8C jal */
    R[16] = R[2] + R[0];  /* 0x800A6D94 */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_800A6E20; } }  /* 0x800A6D98 */
    { R[31] = 0x800A6DA8u; R[4] = R[0] + 16; psx_next = 0x800908F4u; return; }  /* 0x800A6DA0 jal */
    R[4] = R[0] + 16;  /* 0x800A6DA8 */
    R[2] = R[2] << 15;  /* 0x800A6DAC */
    R[3] = lw_(R[18]);  /* 0x800A6DB0 */
    R[2] = R[2] + R[20];  /* 0x800A6DB4 */
    R[3] = R[3] + R[2];  /* 0x800A6DB8 */
    { R[31] = 0x800A6DC4u; sw_(R[18], R[3]); psx_next = 0x800908F4u; return; }  /* 0x800A6DBC jal */
    R[4] = R[21] + R[0];  /* 0x800A6DC4 */
    R[2] = R[2] << 15;  /* 0x800A6DC8 */
    R[2] = R[2] + R[20];  /* 0x800A6DCC */
    R[6] = 0x800Fu << 16;  /* 0x800A6DD0 */
    R[5] = R[16] + R[0];  /* 0x800A6DD4 */
    R[6] = R[6] - 13904;  /* 0x800A6DD8 */
    R[3] = lw_(R[18] + 8);  /* 0x800A6DDC */
    R[7] = R[18] + R[0];  /* 0x800A6DE0 */
    R[3] = R[3] + R[2];  /* 0x800A6DE4 */
    { R[31] = 0x800A6DF0u; sw_(R[18] + 8, R[3]); psx_next = 0x800A5964u; return; }  /* 0x800A6DE8 jal */
    R[3] = lw_(R[18] + 12);  /* 0x800A6DF0 */
    R[2] = R[0] + 2;  /* 0x800A6DF4 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_800A6E08; } }  /* 0x800A6DF8 */
    { uint32_t _c = (R[17] != R[2]); if (_c) { goto L_800A6E14; } }  /* 0x800A6E00 */
L_800A6E08:;
    R[2] = 0x2E62u << 16;  /* 0x800A6E08 */
    R[2] = R[2] | 0x8010;  /* 0x800A6E0C */
    sw_(R[16] + 44, R[2]);  /* 0x800A6E10 */
L_800A6E14:;
    R[17] = R[17] + 1;  /* 0x800A6E14 */
    { uint32_t _c = (R[17] != R[19]); if (_c) { psx_bb(); goto L_800A6D8C; } }  /* 0x800A6E18 */
L_800A6E20:;
    R[31] = lw_(R[29] + 40);  /* 0x800A6E20 */
    R[21] = lw_(R[29] + 36);  /* 0x800A6E24 */
    R[20] = lw_(R[29] + 32);  /* 0x800A6E28 */
    R[19] = lw_(R[29] + 28);  /* 0x800A6E2C */
    R[18] = lw_(R[29] + 24);  /* 0x800A6E30 */
    R[17] = lw_(R[29] + 20);  /* 0x800A6E34 */
    R[16] = lw_(R[29] + 16);  /* 0x800A6E38 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A6E3C jr ra */
}

void g0_800A6D94(void) {
    R[16] = R[2] + R[0];  /* 0x800A6D94 */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_800A6E20; } }  /* 0x800A6D98 */
    { R[31] = 0x800A6DA8u; R[4] = R[0] + 16; psx_next = 0x800908F4u; return; }  /* 0x800A6DA0 jal */
    R[4] = R[0] + 16;  /* 0x800A6DA8 */
    R[2] = R[2] << 15;  /* 0x800A6DAC */
    R[3] = lw_(R[18]);  /* 0x800A6DB0 */
    R[2] = R[2] + R[20];  /* 0x800A6DB4 */
    R[3] = R[3] + R[2];  /* 0x800A6DB8 */
    { R[31] = 0x800A6DC4u; sw_(R[18], R[3]); psx_next = 0x800908F4u; return; }  /* 0x800A6DBC jal */
    R[4] = R[21] + R[0];  /* 0x800A6DC4 */
    R[2] = R[2] << 15;  /* 0x800A6DC8 */
    R[2] = R[2] + R[20];  /* 0x800A6DCC */
    R[6] = 0x800Fu << 16;  /* 0x800A6DD0 */
    R[5] = R[16] + R[0];  /* 0x800A6DD4 */
    R[6] = R[6] - 13904;  /* 0x800A6DD8 */
    R[3] = lw_(R[18] + 8);  /* 0x800A6DDC */
    R[7] = R[18] + R[0];  /* 0x800A6DE0 */
    R[3] = R[3] + R[2];  /* 0x800A6DE4 */
    { R[31] = 0x800A6DF0u; sw_(R[18] + 8, R[3]); psx_next = 0x800A5964u; return; }  /* 0x800A6DE8 jal */
    R[3] = lw_(R[18] + 12);  /* 0x800A6DF0 */
    R[2] = R[0] + 2;  /* 0x800A6DF4 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_800A6E08; } }  /* 0x800A6DF8 */
    { uint32_t _c = (R[17] != R[2]); if (_c) { goto L_800A6E14; } }  /* 0x800A6E00 */
L_800A6E08:;
    R[2] = 0x2E62u << 16;  /* 0x800A6E08 */
    R[2] = R[2] | 0x8010;  /* 0x800A6E0C */
    sw_(R[16] + 44, R[2]);  /* 0x800A6E10 */
L_800A6E14:;
    R[17] = R[17] + 1;  /* 0x800A6E14 */
    { uint32_t _c = (R[17] != R[19]); if (_c) { psx_next = 0x800A6D8Cu; return; } }  /* 0x800A6E18 b extern */
L_800A6E20:;
    R[31] = lw_(R[29] + 40);  /* 0x800A6E20 */
    R[21] = lw_(R[29] + 36);  /* 0x800A6E24 */
    R[20] = lw_(R[29] + 32);  /* 0x800A6E28 */
    R[19] = lw_(R[29] + 28);  /* 0x800A6E2C */
    R[18] = lw_(R[29] + 24);  /* 0x800A6E30 */
    R[17] = lw_(R[29] + 20);  /* 0x800A6E34 */
    R[16] = lw_(R[29] + 16);  /* 0x800A6E38 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A6E3C jr ra */
}

void g0_800A6DA8(void) {
    R[4] = R[0] + 16;  /* 0x800A6DA8 */
    R[2] = R[2] << 15;  /* 0x800A6DAC */
    R[3] = lw_(R[18]);  /* 0x800A6DB0 */
    R[2] = R[2] + R[20];  /* 0x800A6DB4 */
    R[3] = R[3] + R[2];  /* 0x800A6DB8 */
    { R[31] = 0x800A6DC4u; sw_(R[18], R[3]); psx_next = 0x800908F4u; return; }  /* 0x800A6DBC jal */
    R[4] = R[21] + R[0];  /* 0x800A6DC4 */
    R[2] = R[2] << 15;  /* 0x800A6DC8 */
    R[2] = R[2] + R[20];  /* 0x800A6DCC */
    R[6] = 0x800Fu << 16;  /* 0x800A6DD0 */
    R[5] = R[16] + R[0];  /* 0x800A6DD4 */
    R[6] = R[6] - 13904;  /* 0x800A6DD8 */
    R[3] = lw_(R[18] + 8);  /* 0x800A6DDC */
    R[7] = R[18] + R[0];  /* 0x800A6DE0 */
    R[3] = R[3] + R[2];  /* 0x800A6DE4 */
    { R[31] = 0x800A6DF0u; sw_(R[18] + 8, R[3]); psx_next = 0x800A5964u; return; }  /* 0x800A6DE8 jal */
    R[3] = lw_(R[18] + 12);  /* 0x800A6DF0 */
    R[2] = R[0] + 2;  /* 0x800A6DF4 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_800A6E08; } }  /* 0x800A6DF8 */
    { uint32_t _c = (R[17] != R[2]); if (_c) { goto L_800A6E14; } }  /* 0x800A6E00 */
L_800A6E08:;
    R[2] = 0x2E62u << 16;  /* 0x800A6E08 */
    R[2] = R[2] | 0x8010;  /* 0x800A6E0C */
    sw_(R[16] + 44, R[2]);  /* 0x800A6E10 */
L_800A6E14:;
    R[17] = R[17] + 1;  /* 0x800A6E14 */
    { uint32_t _c = (R[17] != R[19]); if (_c) { psx_next = 0x800A6D8Cu; return; } }  /* 0x800A6E18 b extern */
    R[31] = lw_(R[29] + 40);  /* 0x800A6E20 */
    R[21] = lw_(R[29] + 36);  /* 0x800A6E24 */
    R[20] = lw_(R[29] + 32);  /* 0x800A6E28 */
    R[19] = lw_(R[29] + 28);  /* 0x800A6E2C */
    R[18] = lw_(R[29] + 24);  /* 0x800A6E30 */
    R[17] = lw_(R[29] + 20);  /* 0x800A6E34 */
    R[16] = lw_(R[29] + 16);  /* 0x800A6E38 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A6E3C jr ra */
}

void g0_800A6DC4(void) {
    R[4] = R[21] + R[0];  /* 0x800A6DC4 */
    R[2] = R[2] << 15;  /* 0x800A6DC8 */
    R[2] = R[2] + R[20];  /* 0x800A6DCC */
    R[6] = 0x800Fu << 16;  /* 0x800A6DD0 */
    R[5] = R[16] + R[0];  /* 0x800A6DD4 */
    R[6] = R[6] - 13904;  /* 0x800A6DD8 */
    R[3] = lw_(R[18] + 8);  /* 0x800A6DDC */
    R[7] = R[18] + R[0];  /* 0x800A6DE0 */
    R[3] = R[3] + R[2];  /* 0x800A6DE4 */
    { R[31] = 0x800A6DF0u; sw_(R[18] + 8, R[3]); psx_next = 0x800A5964u; return; }  /* 0x800A6DE8 jal */
    R[3] = lw_(R[18] + 12);  /* 0x800A6DF0 */
    R[2] = R[0] + 2;  /* 0x800A6DF4 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_800A6E08; } }  /* 0x800A6DF8 */
    { uint32_t _c = (R[17] != R[2]); if (_c) { goto L_800A6E14; } }  /* 0x800A6E00 */
L_800A6E08:;
    R[2] = 0x2E62u << 16;  /* 0x800A6E08 */
    R[2] = R[2] | 0x8010;  /* 0x800A6E0C */
    sw_(R[16] + 44, R[2]);  /* 0x800A6E10 */
L_800A6E14:;
    R[17] = R[17] + 1;  /* 0x800A6E14 */
    { uint32_t _c = (R[17] != R[19]); if (_c) { psx_next = 0x800A6D8Cu; return; } }  /* 0x800A6E18 b extern */
    R[31] = lw_(R[29] + 40);  /* 0x800A6E20 */
    R[21] = lw_(R[29] + 36);  /* 0x800A6E24 */
    R[20] = lw_(R[29] + 32);  /* 0x800A6E28 */
    R[19] = lw_(R[29] + 28);  /* 0x800A6E2C */
    R[18] = lw_(R[29] + 24);  /* 0x800A6E30 */
    R[17] = lw_(R[29] + 20);  /* 0x800A6E34 */
    R[16] = lw_(R[29] + 16);  /* 0x800A6E38 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A6E3C jr ra */
}

void g0_800A6DF0(void) {
    R[3] = lw_(R[18] + 12);  /* 0x800A6DF0 */
    R[2] = R[0] + 2;  /* 0x800A6DF4 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_800A6E08; } }  /* 0x800A6DF8 */
    { uint32_t _c = (R[17] != R[2]); if (_c) { goto L_800A6E14; } }  /* 0x800A6E00 */
L_800A6E08:;
    R[2] = 0x2E62u << 16;  /* 0x800A6E08 */
    R[2] = R[2] | 0x8010;  /* 0x800A6E0C */
    sw_(R[16] + 44, R[2]);  /* 0x800A6E10 */
L_800A6E14:;
    R[17] = R[17] + 1;  /* 0x800A6E14 */
    { uint32_t _c = (R[17] != R[19]); if (_c) { psx_next = 0x800A6D8Cu; return; } }  /* 0x800A6E18 b extern */
    R[31] = lw_(R[29] + 40);  /* 0x800A6E20 */
    R[21] = lw_(R[29] + 36);  /* 0x800A6E24 */
    R[20] = lw_(R[29] + 32);  /* 0x800A6E28 */
    R[19] = lw_(R[29] + 28);  /* 0x800A6E2C */
    R[18] = lw_(R[29] + 24);  /* 0x800A6E30 */
    R[17] = lw_(R[29] + 20);  /* 0x800A6E34 */
    R[16] = lw_(R[29] + 16);  /* 0x800A6E38 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800A6E3C jr ra */
}

void g0_800A6E44(void) {
    R[29] = R[29] - 56;  /* 0x800A6E44 */
    sw_(R[29] + 32, R[20]);  /* 0x800A6E48 */
    R[20] = R[5] + R[0];  /* 0x800A6E4C */
    sw_(R[29] + 52, R[31]);  /* 0x800A6E50 */
    sw_(R[29] + 48, R[30]);  /* 0x800A6E54 */
    sw_(R[29] + 44, R[23]);  /* 0x800A6E58 */
    sw_(R[29] + 40, R[22]);  /* 0x800A6E5C */
    sw_(R[29] + 36, R[21]);  /* 0x800A6E60 */
    sw_(R[29] + 28, R[19]);  /* 0x800A6E64 */
    sw_(R[29] + 24, R[18]);  /* 0x800A6E68 */
    sw_(R[29] + 20, R[17]);  /* 0x800A6E6C */
    sw_(R[29] + 16, R[16]);  /* 0x800A6E70 */
    sw_(R[29] + 56, R[4]);  /* 0x800A6E74 */
    R[5] = lw_(R[20] + 12);  /* 0x800A6E78 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[3] = R[5] + R[0]; if (_c) { goto L_800A6E90; } }  /* 0x800A6E80 */
    R[2] = R[0] | 0xFFFF;  /* 0x800A6E88 */
    R[3] = R[5] + R[2];  /* 0x800A6E8C */
L_800A6E90:;
    R[2] = 0x8013u << 16;  /* 0x800A6E90 */
    R[16] = R[2] - 28480;  /* 0x800A6E94 */
    R[4] = R[0] + 40;  /* 0x800A6E98 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A6E9C */
    R[2] = R[3] << 1;  /* 0x800A6EA0 */
    R[2] = R[2] + R[3];  /* 0x800A6EA4 */
    R[22] = R[2] << 9;  /* 0x800A6EA8 */
    R[3] = R[5] & 0xFFFF;  /* 0x800A6EAC */
    R[2] = R[3] << 1;  /* 0x800A6EB0 */
    R[2] = R[2] + R[3];  /* 0x800A6EB4 */
    { R[31] = 0x800A6EC0u; R[21] = R[2] << 9; psx_next = 0x800908F4u; return; }  /* 0x800A6EB8 jal */
    R[19] = R[2] + R[0];  /* 0x800A6EC0 */
    R[18] = R[0] + R[0];  /* 0x800A6EC4 */
    R[2] = 0x8008u << 16;  /* 0x800A6EC8 */
    R[30] = R[2] + 5492;  /* 0x800A6ECC */
    R[2] = 0x8008u << 16;  /* 0x800A6ED0 */
    R[23] = R[2] + 6516;  /* 0x800A6ED4 */
L_800A6ED8:;
    { R[31] = 0x800A6EE0u; R[4] = R[16] + R[0]; psx_next = 0x800A592Cu; return; }  /* 0x800A6ED8 jal */
    R[16] = R[2] + R[0];  /* 0x800A6EE0 */
    { uint32_t _c = (R[16] == R[0]); R[6] = 0x800Fu << 16; if (_c) { goto L_800A6FC4; } }  /* 0x800A6EE4 */
    R[5] = R[16] + R[0];  /* 0x800A6EEC */
    R[6] = R[6] - 13880;  /* 0x800A6EF0 */
    R[4] = lw_(R[29] + 56);  /* 0x800A6EF4 */
    { R[31] = 0x800A6F00u; R[7] = R[20] + R[0]; psx_next = 0x800A5964u; return; }  /* 0x800A6EF8 jal */
    R[4] = R[19] << 1;  /* 0x800A6F00 */
    R[2] = R[4] + R[30];  /* 0x800A6F04 */
    R[5] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800A6F08 */
    { int64_t _p = (int64_t)(int32_t)R[5] * (int32_t)R[22]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6F10 */
    R[3] = LO;  /* 0x800A6F14 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[4] + R[23]; if (_c) { goto L_800A6F24; } }  /* 0x800A6F18 */
    R[3] = R[3] + 255;  /* 0x800A6F20 */
L_800A6F24:;
    R[17] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800A6F24 */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6F2C */
    R[2] = lw_(R[16] + 8);  /* 0x800A6F30 */
    R[3] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800A6F34 */
    R[2] = R[2] + R[3];  /* 0x800A6F38 */
    R[4] = LO;  /* 0x800A6F3C */
    { uint32_t _c = ((int32_t)R[4] >= 0); sw_(R[16] + 8, R[2]); if (_c) { goto L_800A6F4C; } }  /* 0x800A6F40 */
    R[4] = R[4] + 255;  /* 0x800A6F48 */
L_800A6F4C:;
    R[2] = lw_(R[16] + 16);  /* 0x800A6F4C */
    R[3] = (uint32_t)((int32_t)R[4] >> 8);  /* 0x800A6F50 */
    R[2] = R[2] + R[3];  /* 0x800A6F54 */
    { uint32_t _c = ((int32_t)R[5] >= 0); sw_(R[16] + 16, R[2]); if (_c) { goto L_800A6F64; } }  /* 0x800A6F58 */
    R[5] = R[5] + 15;  /* 0x800A6F60 */
L_800A6F64:;
    R[4] = R[0] + 4;  /* 0x800A6F64 */
    R[2] = (uint32_t)((int32_t)R[5] >> (R[4] & 31));  /* 0x800A6F68 */
    R[2] = R[2] << 12;  /* 0x800A6F6C */
    { R[31] = 0x800A6F78u; sw_(R[16] + 32, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800A6F70 jal */
    R[3] = R[17] + R[0];  /* 0x800A6F78 */
    R[2] = R[2] << 12;  /* 0x800A6F7C */
    R[2] = R[2] + 12288;  /* 0x800A6F80 */
    R[2] = R[0] - R[2];  /* 0x800A6F84 */
    { uint32_t _c = ((int32_t)R[3] >= 0); sw_(R[16] + 36, R[2]); if (_c) { goto L_800A6F94; } }  /* 0x800A6F88 */
    R[3] = R[3] + 15;  /* 0x800A6F90 */
L_800A6F94:;
    R[2] = (uint32_t)((int32_t)R[3] >> 4);  /* 0x800A6F94 */
    R[2] = R[2] << 12;  /* 0x800A6F98 */
    sw_(R[16] + 40, R[2]);  /* 0x800A6F9C */
    { R[31] = 0x800A6FA8u; R[4] = R[0] + 32; psx_next = 0x800908F4u; return; }  /* 0x800A6FA0 jal */
    R[2] = R[2] + R[19];  /* 0x800A6FA8 */
    R[2] = R[2] + 85;  /* 0x800A6FAC */
    R[19] = R[2] & 0x1FF;  /* 0x800A6FB0 */
    R[18] = R[18] + 1;  /* 0x800A6FB4 */
    R[2] = R[0] + 6;  /* 0x800A6FB8 */
    { uint32_t _c = (R[18] != R[2]); if (_c) { psx_bb(); goto L_800A6ED8; } }  /* 0x800A6FBC */
L_800A6FC4:;
    R[31] = lw_(R[29] + 52);  /* 0x800A6FC4 */
    R[30] = lw_(R[29] + 48);  /* 0x800A6FC8 */
    R[23] = lw_(R[29] + 44);  /* 0x800A6FCC */
    R[22] = lw_(R[29] + 40);  /* 0x800A6FD0 */
    R[21] = lw_(R[29] + 36);  /* 0x800A6FD4 */
    R[20] = lw_(R[29] + 32);  /* 0x800A6FD8 */
    R[19] = lw_(R[29] + 28);  /* 0x800A6FDC */
    R[18] = lw_(R[29] + 24);  /* 0x800A6FE0 */
    R[17] = lw_(R[29] + 20);  /* 0x800A6FE4 */
    R[16] = lw_(R[29] + 16);  /* 0x800A6FE8 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800A6FEC jr ra */
}

void g0_800A6EC0(void) {
    R[19] = R[2] + R[0];  /* 0x800A6EC0 */
    R[18] = R[0] + R[0];  /* 0x800A6EC4 */
    R[2] = 0x8008u << 16;  /* 0x800A6EC8 */
    R[30] = R[2] + 5492;  /* 0x800A6ECC */
    R[2] = 0x8008u << 16;  /* 0x800A6ED0 */
    R[23] = R[2] + 6516;  /* 0x800A6ED4 */
L_800A6ED8:;
    { R[31] = 0x800A6EE0u; R[4] = R[16] + R[0]; psx_next = 0x800A592Cu; return; }  /* 0x800A6ED8 jal */
    R[16] = R[2] + R[0];  /* 0x800A6EE0 */
    { uint32_t _c = (R[16] == R[0]); R[6] = 0x800Fu << 16; if (_c) { goto L_800A6FC4; } }  /* 0x800A6EE4 */
    R[5] = R[16] + R[0];  /* 0x800A6EEC */
    R[6] = R[6] - 13880;  /* 0x800A6EF0 */
    R[4] = lw_(R[29] + 56);  /* 0x800A6EF4 */
    { R[31] = 0x800A6F00u; R[7] = R[20] + R[0]; psx_next = 0x800A5964u; return; }  /* 0x800A6EF8 jal */
    R[4] = R[19] << 1;  /* 0x800A6F00 */
    R[2] = R[4] + R[30];  /* 0x800A6F04 */
    R[5] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800A6F08 */
    { int64_t _p = (int64_t)(int32_t)R[5] * (int32_t)R[22]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6F10 */
    R[3] = LO;  /* 0x800A6F14 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[4] + R[23]; if (_c) { goto L_800A6F24; } }  /* 0x800A6F18 */
    R[3] = R[3] + 255;  /* 0x800A6F20 */
L_800A6F24:;
    R[17] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800A6F24 */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6F2C */
    R[2] = lw_(R[16] + 8);  /* 0x800A6F30 */
    R[3] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800A6F34 */
    R[2] = R[2] + R[3];  /* 0x800A6F38 */
    R[4] = LO;  /* 0x800A6F3C */
    { uint32_t _c = ((int32_t)R[4] >= 0); sw_(R[16] + 8, R[2]); if (_c) { goto L_800A6F4C; } }  /* 0x800A6F40 */
    R[4] = R[4] + 255;  /* 0x800A6F48 */
L_800A6F4C:;
    R[2] = lw_(R[16] + 16);  /* 0x800A6F4C */
    R[3] = (uint32_t)((int32_t)R[4] >> 8);  /* 0x800A6F50 */
    R[2] = R[2] + R[3];  /* 0x800A6F54 */
    { uint32_t _c = ((int32_t)R[5] >= 0); sw_(R[16] + 16, R[2]); if (_c) { goto L_800A6F64; } }  /* 0x800A6F58 */
    R[5] = R[5] + 15;  /* 0x800A6F60 */
L_800A6F64:;
    R[4] = R[0] + 4;  /* 0x800A6F64 */
    R[2] = (uint32_t)((int32_t)R[5] >> (R[4] & 31));  /* 0x800A6F68 */
    R[2] = R[2] << 12;  /* 0x800A6F6C */
    { R[31] = 0x800A6F78u; sw_(R[16] + 32, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800A6F70 jal */
    R[3] = R[17] + R[0];  /* 0x800A6F78 */
    R[2] = R[2] << 12;  /* 0x800A6F7C */
    R[2] = R[2] + 12288;  /* 0x800A6F80 */
    R[2] = R[0] - R[2];  /* 0x800A6F84 */
    { uint32_t _c = ((int32_t)R[3] >= 0); sw_(R[16] + 36, R[2]); if (_c) { goto L_800A6F94; } }  /* 0x800A6F88 */
    R[3] = R[3] + 15;  /* 0x800A6F90 */
L_800A6F94:;
    R[2] = (uint32_t)((int32_t)R[3] >> 4);  /* 0x800A6F94 */
    R[2] = R[2] << 12;  /* 0x800A6F98 */
    sw_(R[16] + 40, R[2]);  /* 0x800A6F9C */
    { R[31] = 0x800A6FA8u; R[4] = R[0] + 32; psx_next = 0x800908F4u; return; }  /* 0x800A6FA0 jal */
    R[2] = R[2] + R[19];  /* 0x800A6FA8 */
    R[2] = R[2] + 85;  /* 0x800A6FAC */
    R[19] = R[2] & 0x1FF;  /* 0x800A6FB0 */
    R[18] = R[18] + 1;  /* 0x800A6FB4 */
    R[2] = R[0] + 6;  /* 0x800A6FB8 */
    { uint32_t _c = (R[18] != R[2]); if (_c) { psx_bb(); goto L_800A6ED8; } }  /* 0x800A6FBC */
L_800A6FC4:;
    R[31] = lw_(R[29] + 52);  /* 0x800A6FC4 */
    R[30] = lw_(R[29] + 48);  /* 0x800A6FC8 */
    R[23] = lw_(R[29] + 44);  /* 0x800A6FCC */
    R[22] = lw_(R[29] + 40);  /* 0x800A6FD0 */
    R[21] = lw_(R[29] + 36);  /* 0x800A6FD4 */
    R[20] = lw_(R[29] + 32);  /* 0x800A6FD8 */
    R[19] = lw_(R[29] + 28);  /* 0x800A6FDC */
    R[18] = lw_(R[29] + 24);  /* 0x800A6FE0 */
    R[17] = lw_(R[29] + 20);  /* 0x800A6FE4 */
    R[16] = lw_(R[29] + 16);  /* 0x800A6FE8 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800A6FEC jr ra */
}

void g0_800A6ED8(void) {
L_800A6ED8:;
    { R[31] = 0x800A6EE0u; R[4] = R[16] + R[0]; psx_next = 0x800A592Cu; return; }  /* 0x800A6ED8 jal */
    R[16] = R[2] + R[0];  /* 0x800A6EE0 */
    { uint32_t _c = (R[16] == R[0]); R[6] = 0x800Fu << 16; if (_c) { goto L_800A6FC4; } }  /* 0x800A6EE4 */
    R[5] = R[16] + R[0];  /* 0x800A6EEC */
    R[6] = R[6] - 13880;  /* 0x800A6EF0 */
    R[4] = lw_(R[29] + 56);  /* 0x800A6EF4 */
    { R[31] = 0x800A6F00u; R[7] = R[20] + R[0]; psx_next = 0x800A5964u; return; }  /* 0x800A6EF8 jal */
    R[4] = R[19] << 1;  /* 0x800A6F00 */
    R[2] = R[4] + R[30];  /* 0x800A6F04 */
    R[5] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800A6F08 */
    { int64_t _p = (int64_t)(int32_t)R[5] * (int32_t)R[22]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6F10 */
    R[3] = LO;  /* 0x800A6F14 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[4] + R[23]; if (_c) { goto L_800A6F24; } }  /* 0x800A6F18 */
    R[3] = R[3] + 255;  /* 0x800A6F20 */
L_800A6F24:;
    R[17] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800A6F24 */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6F2C */
    R[2] = lw_(R[16] + 8);  /* 0x800A6F30 */
    R[3] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800A6F34 */
    R[2] = R[2] + R[3];  /* 0x800A6F38 */
    R[4] = LO;  /* 0x800A6F3C */
    { uint32_t _c = ((int32_t)R[4] >= 0); sw_(R[16] + 8, R[2]); if (_c) { goto L_800A6F4C; } }  /* 0x800A6F40 */
    R[4] = R[4] + 255;  /* 0x800A6F48 */
L_800A6F4C:;
    R[2] = lw_(R[16] + 16);  /* 0x800A6F4C */
    R[3] = (uint32_t)((int32_t)R[4] >> 8);  /* 0x800A6F50 */
    R[2] = R[2] + R[3];  /* 0x800A6F54 */
    { uint32_t _c = ((int32_t)R[5] >= 0); sw_(R[16] + 16, R[2]); if (_c) { goto L_800A6F64; } }  /* 0x800A6F58 */
    R[5] = R[5] + 15;  /* 0x800A6F60 */
L_800A6F64:;
    R[4] = R[0] + 4;  /* 0x800A6F64 */
    R[2] = (uint32_t)((int32_t)R[5] >> (R[4] & 31));  /* 0x800A6F68 */
    R[2] = R[2] << 12;  /* 0x800A6F6C */
    { R[31] = 0x800A6F78u; sw_(R[16] + 32, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800A6F70 jal */
    R[3] = R[17] + R[0];  /* 0x800A6F78 */
    R[2] = R[2] << 12;  /* 0x800A6F7C */
    R[2] = R[2] + 12288;  /* 0x800A6F80 */
    R[2] = R[0] - R[2];  /* 0x800A6F84 */
    { uint32_t _c = ((int32_t)R[3] >= 0); sw_(R[16] + 36, R[2]); if (_c) { goto L_800A6F94; } }  /* 0x800A6F88 */
    R[3] = R[3] + 15;  /* 0x800A6F90 */
L_800A6F94:;
    R[2] = (uint32_t)((int32_t)R[3] >> 4);  /* 0x800A6F94 */
    R[2] = R[2] << 12;  /* 0x800A6F98 */
    sw_(R[16] + 40, R[2]);  /* 0x800A6F9C */
    { R[31] = 0x800A6FA8u; R[4] = R[0] + 32; psx_next = 0x800908F4u; return; }  /* 0x800A6FA0 jal */
    R[2] = R[2] + R[19];  /* 0x800A6FA8 */
    R[2] = R[2] + 85;  /* 0x800A6FAC */
    R[19] = R[2] & 0x1FF;  /* 0x800A6FB0 */
    R[18] = R[18] + 1;  /* 0x800A6FB4 */
    R[2] = R[0] + 6;  /* 0x800A6FB8 */
    { uint32_t _c = (R[18] != R[2]); if (_c) { psx_bb(); goto L_800A6ED8; } }  /* 0x800A6FBC */
L_800A6FC4:;
    R[31] = lw_(R[29] + 52);  /* 0x800A6FC4 */
    R[30] = lw_(R[29] + 48);  /* 0x800A6FC8 */
    R[23] = lw_(R[29] + 44);  /* 0x800A6FCC */
    R[22] = lw_(R[29] + 40);  /* 0x800A6FD0 */
    R[21] = lw_(R[29] + 36);  /* 0x800A6FD4 */
    R[20] = lw_(R[29] + 32);  /* 0x800A6FD8 */
    R[19] = lw_(R[29] + 28);  /* 0x800A6FDC */
    R[18] = lw_(R[29] + 24);  /* 0x800A6FE0 */
    R[17] = lw_(R[29] + 20);  /* 0x800A6FE4 */
    R[16] = lw_(R[29] + 16);  /* 0x800A6FE8 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800A6FEC jr ra */
}

void g0_800A6EE0(void) {
    R[16] = R[2] + R[0];  /* 0x800A6EE0 */
    { uint32_t _c = (R[16] == R[0]); R[6] = 0x800Fu << 16; if (_c) { goto L_800A6FC4; } }  /* 0x800A6EE4 */
    R[5] = R[16] + R[0];  /* 0x800A6EEC */
    R[6] = R[6] - 13880;  /* 0x800A6EF0 */
    R[4] = lw_(R[29] + 56);  /* 0x800A6EF4 */
    { R[31] = 0x800A6F00u; R[7] = R[20] + R[0]; psx_next = 0x800A5964u; return; }  /* 0x800A6EF8 jal */
    R[4] = R[19] << 1;  /* 0x800A6F00 */
    R[2] = R[4] + R[30];  /* 0x800A6F04 */
    R[5] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800A6F08 */
    { int64_t _p = (int64_t)(int32_t)R[5] * (int32_t)R[22]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6F10 */
    R[3] = LO;  /* 0x800A6F14 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[4] + R[23]; if (_c) { goto L_800A6F24; } }  /* 0x800A6F18 */
    R[3] = R[3] + 255;  /* 0x800A6F20 */
L_800A6F24:;
    R[17] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800A6F24 */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6F2C */
    R[2] = lw_(R[16] + 8);  /* 0x800A6F30 */
    R[3] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800A6F34 */
    R[2] = R[2] + R[3];  /* 0x800A6F38 */
    R[4] = LO;  /* 0x800A6F3C */
    { uint32_t _c = ((int32_t)R[4] >= 0); sw_(R[16] + 8, R[2]); if (_c) { goto L_800A6F4C; } }  /* 0x800A6F40 */
    R[4] = R[4] + 255;  /* 0x800A6F48 */
L_800A6F4C:;
    R[2] = lw_(R[16] + 16);  /* 0x800A6F4C */
    R[3] = (uint32_t)((int32_t)R[4] >> 8);  /* 0x800A6F50 */
    R[2] = R[2] + R[3];  /* 0x800A6F54 */
    { uint32_t _c = ((int32_t)R[5] >= 0); sw_(R[16] + 16, R[2]); if (_c) { goto L_800A6F64; } }  /* 0x800A6F58 */
    R[5] = R[5] + 15;  /* 0x800A6F60 */
L_800A6F64:;
    R[4] = R[0] + 4;  /* 0x800A6F64 */
    R[2] = (uint32_t)((int32_t)R[5] >> (R[4] & 31));  /* 0x800A6F68 */
    R[2] = R[2] << 12;  /* 0x800A6F6C */
    { R[31] = 0x800A6F78u; sw_(R[16] + 32, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800A6F70 jal */
    R[3] = R[17] + R[0];  /* 0x800A6F78 */
    R[2] = R[2] << 12;  /* 0x800A6F7C */
    R[2] = R[2] + 12288;  /* 0x800A6F80 */
    R[2] = R[0] - R[2];  /* 0x800A6F84 */
    { uint32_t _c = ((int32_t)R[3] >= 0); sw_(R[16] + 36, R[2]); if (_c) { goto L_800A6F94; } }  /* 0x800A6F88 */
    R[3] = R[3] + 15;  /* 0x800A6F90 */
L_800A6F94:;
    R[2] = (uint32_t)((int32_t)R[3] >> 4);  /* 0x800A6F94 */
    R[2] = R[2] << 12;  /* 0x800A6F98 */
    sw_(R[16] + 40, R[2]);  /* 0x800A6F9C */
    { R[31] = 0x800A6FA8u; R[4] = R[0] + 32; psx_next = 0x800908F4u; return; }  /* 0x800A6FA0 jal */
    R[2] = R[2] + R[19];  /* 0x800A6FA8 */
    R[2] = R[2] + 85;  /* 0x800A6FAC */
    R[19] = R[2] & 0x1FF;  /* 0x800A6FB0 */
    R[18] = R[18] + 1;  /* 0x800A6FB4 */
    R[2] = R[0] + 6;  /* 0x800A6FB8 */
    { uint32_t _c = (R[18] != R[2]); if (_c) { psx_next = 0x800A6ED8u; return; } }  /* 0x800A6FBC b extern */
L_800A6FC4:;
    R[31] = lw_(R[29] + 52);  /* 0x800A6FC4 */
    R[30] = lw_(R[29] + 48);  /* 0x800A6FC8 */
    R[23] = lw_(R[29] + 44);  /* 0x800A6FCC */
    R[22] = lw_(R[29] + 40);  /* 0x800A6FD0 */
    R[21] = lw_(R[29] + 36);  /* 0x800A6FD4 */
    R[20] = lw_(R[29] + 32);  /* 0x800A6FD8 */
    R[19] = lw_(R[29] + 28);  /* 0x800A6FDC */
    R[18] = lw_(R[29] + 24);  /* 0x800A6FE0 */
    R[17] = lw_(R[29] + 20);  /* 0x800A6FE4 */
    R[16] = lw_(R[29] + 16);  /* 0x800A6FE8 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800A6FEC jr ra */
}

void g0_800A6F00(void) {
    R[4] = R[19] << 1;  /* 0x800A6F00 */
    R[2] = R[4] + R[30];  /* 0x800A6F04 */
    R[5] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800A6F08 */
    { int64_t _p = (int64_t)(int32_t)R[5] * (int32_t)R[22]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6F10 */
    R[3] = LO;  /* 0x800A6F14 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[4] + R[23]; if (_c) { goto L_800A6F24; } }  /* 0x800A6F18 */
    R[3] = R[3] + 255;  /* 0x800A6F20 */
L_800A6F24:;
    R[17] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800A6F24 */
    { int64_t _p = (int64_t)(int32_t)R[17] * (int32_t)R[21]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A6F2C */
    R[2] = lw_(R[16] + 8);  /* 0x800A6F30 */
    R[3] = (uint32_t)((int32_t)R[3] >> 8);  /* 0x800A6F34 */
    R[2] = R[2] + R[3];  /* 0x800A6F38 */
    R[4] = LO;  /* 0x800A6F3C */
    { uint32_t _c = ((int32_t)R[4] >= 0); sw_(R[16] + 8, R[2]); if (_c) { goto L_800A6F4C; } }  /* 0x800A6F40 */
    R[4] = R[4] + 255;  /* 0x800A6F48 */
L_800A6F4C:;
    R[2] = lw_(R[16] + 16);  /* 0x800A6F4C */
    R[3] = (uint32_t)((int32_t)R[4] >> 8);  /* 0x800A6F50 */
    R[2] = R[2] + R[3];  /* 0x800A6F54 */
    { uint32_t _c = ((int32_t)R[5] >= 0); sw_(R[16] + 16, R[2]); if (_c) { goto L_800A6F64; } }  /* 0x800A6F58 */
    R[5] = R[5] + 15;  /* 0x800A6F60 */
L_800A6F64:;
    R[4] = R[0] + 4;  /* 0x800A6F64 */
    R[2] = (uint32_t)((int32_t)R[5] >> (R[4] & 31));  /* 0x800A6F68 */
    R[2] = R[2] << 12;  /* 0x800A6F6C */
    { R[31] = 0x800A6F78u; sw_(R[16] + 32, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800A6F70 jal */
    R[3] = R[17] + R[0];  /* 0x800A6F78 */
    R[2] = R[2] << 12;  /* 0x800A6F7C */
    R[2] = R[2] + 12288;  /* 0x800A6F80 */
    R[2] = R[0] - R[2];  /* 0x800A6F84 */
    { uint32_t _c = ((int32_t)R[3] >= 0); sw_(R[16] + 36, R[2]); if (_c) { goto L_800A6F94; } }  /* 0x800A6F88 */
    R[3] = R[3] + 15;  /* 0x800A6F90 */
L_800A6F94:;
    R[2] = (uint32_t)((int32_t)R[3] >> 4);  /* 0x800A6F94 */
    R[2] = R[2] << 12;  /* 0x800A6F98 */
    sw_(R[16] + 40, R[2]);  /* 0x800A6F9C */
    { R[31] = 0x800A6FA8u; R[4] = R[0] + 32; psx_next = 0x800908F4u; return; }  /* 0x800A6FA0 jal */
    R[2] = R[2] + R[19];  /* 0x800A6FA8 */
    R[2] = R[2] + 85;  /* 0x800A6FAC */
    R[19] = R[2] & 0x1FF;  /* 0x800A6FB0 */
    R[18] = R[18] + 1;  /* 0x800A6FB4 */
    R[2] = R[0] + 6;  /* 0x800A6FB8 */
    { uint32_t _c = (R[18] != R[2]); if (_c) { psx_next = 0x800A6ED8u; return; } }  /* 0x800A6FBC b extern */
    R[31] = lw_(R[29] + 52);  /* 0x800A6FC4 */
    R[30] = lw_(R[29] + 48);  /* 0x800A6FC8 */
    R[23] = lw_(R[29] + 44);  /* 0x800A6FCC */
    R[22] = lw_(R[29] + 40);  /* 0x800A6FD0 */
    R[21] = lw_(R[29] + 36);  /* 0x800A6FD4 */
    R[20] = lw_(R[29] + 32);  /* 0x800A6FD8 */
    R[19] = lw_(R[29] + 28);  /* 0x800A6FDC */
    R[18] = lw_(R[29] + 24);  /* 0x800A6FE0 */
    R[17] = lw_(R[29] + 20);  /* 0x800A6FE4 */
    R[16] = lw_(R[29] + 16);  /* 0x800A6FE8 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800A6FEC jr ra */
}

void g0_800A6F78(void) {
    R[3] = R[17] + R[0];  /* 0x800A6F78 */
    R[2] = R[2] << 12;  /* 0x800A6F7C */
    R[2] = R[2] + 12288;  /* 0x800A6F80 */
    R[2] = R[0] - R[2];  /* 0x800A6F84 */
    { uint32_t _c = ((int32_t)R[3] >= 0); sw_(R[16] + 36, R[2]); if (_c) { goto L_800A6F94; } }  /* 0x800A6F88 */
    R[3] = R[3] + 15;  /* 0x800A6F90 */
L_800A6F94:;
    R[2] = (uint32_t)((int32_t)R[3] >> 4);  /* 0x800A6F94 */
    R[2] = R[2] << 12;  /* 0x800A6F98 */
    sw_(R[16] + 40, R[2]);  /* 0x800A6F9C */
    { R[31] = 0x800A6FA8u; R[4] = R[0] + 32; psx_next = 0x800908F4u; return; }  /* 0x800A6FA0 jal */
    R[2] = R[2] + R[19];  /* 0x800A6FA8 */
    R[2] = R[2] + 85;  /* 0x800A6FAC */
    R[19] = R[2] & 0x1FF;  /* 0x800A6FB0 */
    R[18] = R[18] + 1;  /* 0x800A6FB4 */
    R[2] = R[0] + 6;  /* 0x800A6FB8 */
    { uint32_t _c = (R[18] != R[2]); if (_c) { psx_next = 0x800A6ED8u; return; } }  /* 0x800A6FBC b extern */
    R[31] = lw_(R[29] + 52);  /* 0x800A6FC4 */
    R[30] = lw_(R[29] + 48);  /* 0x800A6FC8 */
    R[23] = lw_(R[29] + 44);  /* 0x800A6FCC */
    R[22] = lw_(R[29] + 40);  /* 0x800A6FD0 */
    R[21] = lw_(R[29] + 36);  /* 0x800A6FD4 */
    R[20] = lw_(R[29] + 32);  /* 0x800A6FD8 */
    R[19] = lw_(R[29] + 28);  /* 0x800A6FDC */
    R[18] = lw_(R[29] + 24);  /* 0x800A6FE0 */
    R[17] = lw_(R[29] + 20);  /* 0x800A6FE4 */
    R[16] = lw_(R[29] + 16);  /* 0x800A6FE8 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800A6FEC jr ra */
}

void g0_800A6FA8(void) {
    R[2] = R[2] + R[19];  /* 0x800A6FA8 */
    R[2] = R[2] + 85;  /* 0x800A6FAC */
    R[19] = R[2] & 0x1FF;  /* 0x800A6FB0 */
    R[18] = R[18] + 1;  /* 0x800A6FB4 */
    R[2] = R[0] + 6;  /* 0x800A6FB8 */
    { uint32_t _c = (R[18] != R[2]); if (_c) { psx_next = 0x800A6ED8u; return; } }  /* 0x800A6FBC b extern */
    R[31] = lw_(R[29] + 52);  /* 0x800A6FC4 */
    R[30] = lw_(R[29] + 48);  /* 0x800A6FC8 */
    R[23] = lw_(R[29] + 44);  /* 0x800A6FCC */
    R[22] = lw_(R[29] + 40);  /* 0x800A6FD0 */
    R[21] = lw_(R[29] + 36);  /* 0x800A6FD4 */
    R[20] = lw_(R[29] + 32);  /* 0x800A6FD8 */
    R[19] = lw_(R[29] + 28);  /* 0x800A6FDC */
    R[18] = lw_(R[29] + 24);  /* 0x800A6FE0 */
    R[17] = lw_(R[29] + 20);  /* 0x800A6FE4 */
    R[16] = lw_(R[29] + 16);  /* 0x800A6FE8 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800A6FEC jr ra */
}

void g0_800A6FF4(void) {
    R[29] = R[29] - 40;  /* 0x800A6FF4 */
    sw_(R[29] + 32, R[20]);  /* 0x800A6FF8 */
    R[20] = R[4] + R[0];  /* 0x800A6FFC */
    sw_(R[29] + 24, R[18]);  /* 0x800A7000 */
    R[18] = R[5] + R[0];  /* 0x800A7004 */
    R[4] = 0x8013u << 16;  /* 0x800A7008 */
    R[4] = R[4] - 28480;  /* 0x800A700C */
    sw_(R[29] + 36, R[31]);  /* 0x800A7010 */
    sw_(R[29] + 28, R[19]);  /* 0x800A7014 */
    sw_(R[29] + 20, R[17]);  /* 0x800A7018 */
    { R[31] = 0x800A7024u; sw_(R[29] + 16, R[16]); psx_next = 0x800A592Cu; return; }  /* 0x800A701C jal */
    R[17] = R[2] + R[0];  /* 0x800A7024 */
    { uint32_t _c = (R[17] == R[0]); R[4] = R[0] + 16; if (_c) { goto L_800A7188; } }  /* 0x800A7028 */
    R[19] = lw_(R[18] + 12);  /* 0x800A7030 */
    R[2] = (uint32_t)(int16_t)lh_(R[19] + 4);  /* 0x800A7038 */
    R[2] = R[2] - 32;  /* 0x800A7040 */
    { R[31] = 0x800A704Cu; R[16] = R[2] & 0x1FF; psx_next = 0x800908F4u; return; }  /* 0x800A7044 jal */
    R[2] = R[2] << 2;  /* 0x800A704C */
    R[2] = R[16] + R[2];  /* 0x800A7050 */
    R[16] = R[2] & 0x1FF;  /* 0x800A7054 */
    { R[31] = 0x800A7060u; R[4] = R[0] + 40; psx_next = 0x800908F4u; return; }  /* 0x800A7058 jal */
    R[3] = R[2] << 1;  /* 0x800A7060 */
    R[3] = R[3] + R[2];  /* 0x800A7064 */
    R[3] = R[3] + 150;  /* 0x800A7068 */
    R[2] = 0x8008u << 16;  /* 0x800A706C */
    R[2] = R[2] + 5492;  /* 0x800A7070 */
    R[4] = R[16] << 1;  /* 0x800A7074 */
    R[2] = R[4] + R[2];  /* 0x800A7078 */
    R[2] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800A707C */
    R[3] = R[3] << 4;  /* 0x800A7080 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A7084 */
    R[2] = 0x8008u << 16;  /* 0x800A7088 */
    R[2] = R[2] + 6516;  /* 0x800A708C */
    R[4] = R[4] + R[2];  /* 0x800A7090 */
    R[5] = LO;  /* 0x800A7094 */
    R[2] = (uint32_t)(int16_t)lh_(R[4]);  /* 0x800A7098 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A70A0 */
    R[4] = R[0] + 16;  /* 0x800A70A4 */
    R[2] = lw_(R[18]);  /* 0x800A70A8 */
    R[3] = lw_(R[18] + 8);  /* 0x800A70AC */
    R[2] = R[2] + R[5];  /* 0x800A70B0 */
    sw_(R[18], R[2]);  /* 0x800A70B4 */
    R[9] = LO;  /* 0x800A70B8 */
    R[3] = R[3] + R[9];  /* 0x800A70BC */
    { R[31] = 0x800A70C8u; sw_(R[18] + 8, R[3]); psx_next = 0x800908F4u; return; }  /* 0x800A70C0 jal */
    R[4] = R[20] + R[0];  /* 0x800A70C8 */
    R[2] = R[2] << 14;  /* 0x800A70CC */
    R[5] = 0xFFFEu << 16;  /* 0x800A70D0 */
    R[2] = R[2] + R[5];  /* 0x800A70D4 */
    R[6] = 0x800Fu << 16;  /* 0x800A70D8 */
    R[5] = R[17] + R[0];  /* 0x800A70DC */
    R[6] = R[6] - 13856;  /* 0x800A70E0 */
    R[3] = lw_(R[18] + 4);  /* 0x800A70E4 */
    R[7] = R[18] + R[0];  /* 0x800A70E8 */
    R[3] = R[3] + R[2];  /* 0x800A70EC */
    { R[31] = 0x800A70F8u; sw_(R[18] + 4, R[3]); psx_next = 0x800A5964u; return; }  /* 0x800A70F0 jal */
    { R[31] = 0x800A7100u; R[4] = R[0] + 10; psx_next = 0x800908F4u; return; }  /* 0x800A70F8 jal */
    R[6] = 0xFFFDu << 16;  /* 0x800A7100 */
    R[6] = R[6] | 0x8000;  /* 0x800A7104 */
    R[2] = R[2] << 15;  /* 0x800A7108 */
    R[2] = R[2] + R[6];  /* 0x800A710C */
    R[5] = lw_(R[19] + 24);  /* 0x800A7110 */
    R[4] = lw_(R[17] + 8);  /* 0x800A7114 */
    R[3] = lw_(R[19] + 488);  /* 0x800A7118 */
    R[5] = R[5] - R[4];  /* 0x800A711C */
    R[4] = R[3] >> 31;  /* 0x800A7120 */
    R[3] = R[3] + R[4];  /* 0x800A7124 */
    R[4] = lw_(R[19] + 28);  /* 0x800A7128 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x800A712C */
    R[4] = R[4] + R[3];  /* 0x800A7130 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[4] = R[4] - R[2]; if (_c) { goto L_800A7140; } }  /* 0x800A7134 */
    R[5] = R[5] + 7;  /* 0x800A713C */
L_800A7140:;
    R[2] = lw_(R[17] + 12);  /* 0x800A7140 */
    R[3] = (uint32_t)((int32_t)R[5] >> 3);  /* 0x800A7144 */
    R[2] = R[4] + R[2];  /* 0x800A7148 */
    R[2] = R[0] - R[2];  /* 0x800A714C */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[17] + 32, R[3]); if (_c) { goto L_800A715C; } }  /* 0x800A7150 */
    R[2] = R[2] + 7;  /* 0x800A7158 */
L_800A715C:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A715C */
    sw_(R[17] + 36, R[2]);  /* 0x800A7160 */
    R[3] = lw_(R[19] + 32);  /* 0x800A7164 */
    R[2] = lw_(R[17] + 16);  /* 0x800A7168 */
    R[2] = R[3] - R[2];  /* 0x800A7170 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800A7180; } }  /* 0x800A7174 */
    R[2] = R[2] + 7;  /* 0x800A717C */
L_800A7180:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7180 */
    sw_(R[17] + 40, R[2]);  /* 0x800A7184 */
L_800A7188:;
    R[31] = lw_(R[29] + 36);  /* 0x800A7188 */
    R[20] = lw_(R[29] + 32);  /* 0x800A718C */
    R[19] = lw_(R[29] + 28);  /* 0x800A7190 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7194 */
    R[17] = lw_(R[29] + 20);  /* 0x800A7198 */
    R[16] = lw_(R[29] + 16);  /* 0x800A719C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A71A0 jr ra */
}

void g0_800A7024(void) {
    R[17] = R[2] + R[0];  /* 0x800A7024 */
    { uint32_t _c = (R[17] == R[0]); R[4] = R[0] + 16; if (_c) { goto L_800A7188; } }  /* 0x800A7028 */
    R[19] = lw_(R[18] + 12);  /* 0x800A7030 */
    R[2] = (uint32_t)(int16_t)lh_(R[19] + 4);  /* 0x800A7038 */
    R[2] = R[2] - 32;  /* 0x800A7040 */
    { R[31] = 0x800A704Cu; R[16] = R[2] & 0x1FF; psx_next = 0x800908F4u; return; }  /* 0x800A7044 jal */
    R[2] = R[2] << 2;  /* 0x800A704C */
    R[2] = R[16] + R[2];  /* 0x800A7050 */
    R[16] = R[2] & 0x1FF;  /* 0x800A7054 */
    { R[31] = 0x800A7060u; R[4] = R[0] + 40; psx_next = 0x800908F4u; return; }  /* 0x800A7058 jal */
    R[3] = R[2] << 1;  /* 0x800A7060 */
    R[3] = R[3] + R[2];  /* 0x800A7064 */
    R[3] = R[3] + 150;  /* 0x800A7068 */
    R[2] = 0x8008u << 16;  /* 0x800A706C */
    R[2] = R[2] + 5492;  /* 0x800A7070 */
    R[4] = R[16] << 1;  /* 0x800A7074 */
    R[2] = R[4] + R[2];  /* 0x800A7078 */
    R[2] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800A707C */
    R[3] = R[3] << 4;  /* 0x800A7080 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A7084 */
    R[2] = 0x8008u << 16;  /* 0x800A7088 */
    R[2] = R[2] + 6516;  /* 0x800A708C */
    R[4] = R[4] + R[2];  /* 0x800A7090 */
    R[5] = LO;  /* 0x800A7094 */
    R[2] = (uint32_t)(int16_t)lh_(R[4]);  /* 0x800A7098 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A70A0 */
    R[4] = R[0] + 16;  /* 0x800A70A4 */
    R[2] = lw_(R[18]);  /* 0x800A70A8 */
    R[3] = lw_(R[18] + 8);  /* 0x800A70AC */
    R[2] = R[2] + R[5];  /* 0x800A70B0 */
    sw_(R[18], R[2]);  /* 0x800A70B4 */
    R[9] = LO;  /* 0x800A70B8 */
    R[3] = R[3] + R[9];  /* 0x800A70BC */
    { R[31] = 0x800A70C8u; sw_(R[18] + 8, R[3]); psx_next = 0x800908F4u; return; }  /* 0x800A70C0 jal */
    R[4] = R[20] + R[0];  /* 0x800A70C8 */
    R[2] = R[2] << 14;  /* 0x800A70CC */
    R[5] = 0xFFFEu << 16;  /* 0x800A70D0 */
    R[2] = R[2] + R[5];  /* 0x800A70D4 */
    R[6] = 0x800Fu << 16;  /* 0x800A70D8 */
    R[5] = R[17] + R[0];  /* 0x800A70DC */
    R[6] = R[6] - 13856;  /* 0x800A70E0 */
    R[3] = lw_(R[18] + 4);  /* 0x800A70E4 */
    R[7] = R[18] + R[0];  /* 0x800A70E8 */
    R[3] = R[3] + R[2];  /* 0x800A70EC */
    { R[31] = 0x800A70F8u; sw_(R[18] + 4, R[3]); psx_next = 0x800A5964u; return; }  /* 0x800A70F0 jal */
    { R[31] = 0x800A7100u; R[4] = R[0] + 10; psx_next = 0x800908F4u; return; }  /* 0x800A70F8 jal */
    R[6] = 0xFFFDu << 16;  /* 0x800A7100 */
    R[6] = R[6] | 0x8000;  /* 0x800A7104 */
    R[2] = R[2] << 15;  /* 0x800A7108 */
    R[2] = R[2] + R[6];  /* 0x800A710C */
    R[5] = lw_(R[19] + 24);  /* 0x800A7110 */
    R[4] = lw_(R[17] + 8);  /* 0x800A7114 */
    R[3] = lw_(R[19] + 488);  /* 0x800A7118 */
    R[5] = R[5] - R[4];  /* 0x800A711C */
    R[4] = R[3] >> 31;  /* 0x800A7120 */
    R[3] = R[3] + R[4];  /* 0x800A7124 */
    R[4] = lw_(R[19] + 28);  /* 0x800A7128 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x800A712C */
    R[4] = R[4] + R[3];  /* 0x800A7130 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[4] = R[4] - R[2]; if (_c) { goto L_800A7140; } }  /* 0x800A7134 */
    R[5] = R[5] + 7;  /* 0x800A713C */
L_800A7140:;
    R[2] = lw_(R[17] + 12);  /* 0x800A7140 */
    R[3] = (uint32_t)((int32_t)R[5] >> 3);  /* 0x800A7144 */
    R[2] = R[4] + R[2];  /* 0x800A7148 */
    R[2] = R[0] - R[2];  /* 0x800A714C */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[17] + 32, R[3]); if (_c) { goto L_800A715C; } }  /* 0x800A7150 */
    R[2] = R[2] + 7;  /* 0x800A7158 */
L_800A715C:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A715C */
    sw_(R[17] + 36, R[2]);  /* 0x800A7160 */
    R[3] = lw_(R[19] + 32);  /* 0x800A7164 */
    R[2] = lw_(R[17] + 16);  /* 0x800A7168 */
    R[2] = R[3] - R[2];  /* 0x800A7170 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800A7180; } }  /* 0x800A7174 */
    R[2] = R[2] + 7;  /* 0x800A717C */
L_800A7180:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7180 */
    sw_(R[17] + 40, R[2]);  /* 0x800A7184 */
L_800A7188:;
    R[31] = lw_(R[29] + 36);  /* 0x800A7188 */
    R[20] = lw_(R[29] + 32);  /* 0x800A718C */
    R[19] = lw_(R[29] + 28);  /* 0x800A7190 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7194 */
    R[17] = lw_(R[29] + 20);  /* 0x800A7198 */
    R[16] = lw_(R[29] + 16);  /* 0x800A719C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A71A0 jr ra */
}

void g0_800A704C(void) {
    R[2] = R[2] << 2;  /* 0x800A704C */
    R[2] = R[16] + R[2];  /* 0x800A7050 */
    R[16] = R[2] & 0x1FF;  /* 0x800A7054 */
    { R[31] = 0x800A7060u; R[4] = R[0] + 40; psx_next = 0x800908F4u; return; }  /* 0x800A7058 jal */
    R[3] = R[2] << 1;  /* 0x800A7060 */
    R[3] = R[3] + R[2];  /* 0x800A7064 */
    R[3] = R[3] + 150;  /* 0x800A7068 */
    R[2] = 0x8008u << 16;  /* 0x800A706C */
    R[2] = R[2] + 5492;  /* 0x800A7070 */
    R[4] = R[16] << 1;  /* 0x800A7074 */
    R[2] = R[4] + R[2];  /* 0x800A7078 */
    R[2] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800A707C */
    R[3] = R[3] << 4;  /* 0x800A7080 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A7084 */
    R[2] = 0x8008u << 16;  /* 0x800A7088 */
    R[2] = R[2] + 6516;  /* 0x800A708C */
    R[4] = R[4] + R[2];  /* 0x800A7090 */
    R[5] = LO;  /* 0x800A7094 */
    R[2] = (uint32_t)(int16_t)lh_(R[4]);  /* 0x800A7098 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A70A0 */
    R[4] = R[0] + 16;  /* 0x800A70A4 */
    R[2] = lw_(R[18]);  /* 0x800A70A8 */
    R[3] = lw_(R[18] + 8);  /* 0x800A70AC */
    R[2] = R[2] + R[5];  /* 0x800A70B0 */
    sw_(R[18], R[2]);  /* 0x800A70B4 */
    R[9] = LO;  /* 0x800A70B8 */
    R[3] = R[3] + R[9];  /* 0x800A70BC */
    { R[31] = 0x800A70C8u; sw_(R[18] + 8, R[3]); psx_next = 0x800908F4u; return; }  /* 0x800A70C0 jal */
    R[4] = R[20] + R[0];  /* 0x800A70C8 */
    R[2] = R[2] << 14;  /* 0x800A70CC */
    R[5] = 0xFFFEu << 16;  /* 0x800A70D0 */
    R[2] = R[2] + R[5];  /* 0x800A70D4 */
    R[6] = 0x800Fu << 16;  /* 0x800A70D8 */
    R[5] = R[17] + R[0];  /* 0x800A70DC */
    R[6] = R[6] - 13856;  /* 0x800A70E0 */
    R[3] = lw_(R[18] + 4);  /* 0x800A70E4 */
    R[7] = R[18] + R[0];  /* 0x800A70E8 */
    R[3] = R[3] + R[2];  /* 0x800A70EC */
    { R[31] = 0x800A70F8u; sw_(R[18] + 4, R[3]); psx_next = 0x800A5964u; return; }  /* 0x800A70F0 jal */
    { R[31] = 0x800A7100u; R[4] = R[0] + 10; psx_next = 0x800908F4u; return; }  /* 0x800A70F8 jal */
    R[6] = 0xFFFDu << 16;  /* 0x800A7100 */
    R[6] = R[6] | 0x8000;  /* 0x800A7104 */
    R[2] = R[2] << 15;  /* 0x800A7108 */
    R[2] = R[2] + R[6];  /* 0x800A710C */
    R[5] = lw_(R[19] + 24);  /* 0x800A7110 */
    R[4] = lw_(R[17] + 8);  /* 0x800A7114 */
    R[3] = lw_(R[19] + 488);  /* 0x800A7118 */
    R[5] = R[5] - R[4];  /* 0x800A711C */
    R[4] = R[3] >> 31;  /* 0x800A7120 */
    R[3] = R[3] + R[4];  /* 0x800A7124 */
    R[4] = lw_(R[19] + 28);  /* 0x800A7128 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x800A712C */
    R[4] = R[4] + R[3];  /* 0x800A7130 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[4] = R[4] - R[2]; if (_c) { goto L_800A7140; } }  /* 0x800A7134 */
    R[5] = R[5] + 7;  /* 0x800A713C */
L_800A7140:;
    R[2] = lw_(R[17] + 12);  /* 0x800A7140 */
    R[3] = (uint32_t)((int32_t)R[5] >> 3);  /* 0x800A7144 */
    R[2] = R[4] + R[2];  /* 0x800A7148 */
    R[2] = R[0] - R[2];  /* 0x800A714C */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[17] + 32, R[3]); if (_c) { goto L_800A715C; } }  /* 0x800A7150 */
    R[2] = R[2] + 7;  /* 0x800A7158 */
L_800A715C:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A715C */
    sw_(R[17] + 36, R[2]);  /* 0x800A7160 */
    R[3] = lw_(R[19] + 32);  /* 0x800A7164 */
    R[2] = lw_(R[17] + 16);  /* 0x800A7168 */
    R[2] = R[3] - R[2];  /* 0x800A7170 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800A7180; } }  /* 0x800A7174 */
    R[2] = R[2] + 7;  /* 0x800A717C */
L_800A7180:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7180 */
    sw_(R[17] + 40, R[2]);  /* 0x800A7184 */
    R[31] = lw_(R[29] + 36);  /* 0x800A7188 */
    R[20] = lw_(R[29] + 32);  /* 0x800A718C */
    R[19] = lw_(R[29] + 28);  /* 0x800A7190 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7194 */
    R[17] = lw_(R[29] + 20);  /* 0x800A7198 */
    R[16] = lw_(R[29] + 16);  /* 0x800A719C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A71A0 jr ra */
}

void g0_800A7060(void) {
    R[3] = R[2] << 1;  /* 0x800A7060 */
    R[3] = R[3] + R[2];  /* 0x800A7064 */
    R[3] = R[3] + 150;  /* 0x800A7068 */
    R[2] = 0x8008u << 16;  /* 0x800A706C */
    R[2] = R[2] + 5492;  /* 0x800A7070 */
    R[4] = R[16] << 1;  /* 0x800A7074 */
    R[2] = R[4] + R[2];  /* 0x800A7078 */
    R[2] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800A707C */
    R[3] = R[3] << 4;  /* 0x800A7080 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A7084 */
    R[2] = 0x8008u << 16;  /* 0x800A7088 */
    R[2] = R[2] + 6516;  /* 0x800A708C */
    R[4] = R[4] + R[2];  /* 0x800A7090 */
    R[5] = LO;  /* 0x800A7094 */
    R[2] = (uint32_t)(int16_t)lh_(R[4]);  /* 0x800A7098 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A70A0 */
    R[4] = R[0] + 16;  /* 0x800A70A4 */
    R[2] = lw_(R[18]);  /* 0x800A70A8 */
    R[3] = lw_(R[18] + 8);  /* 0x800A70AC */
    R[2] = R[2] + R[5];  /* 0x800A70B0 */
    sw_(R[18], R[2]);  /* 0x800A70B4 */
    R[9] = LO;  /* 0x800A70B8 */
    R[3] = R[3] + R[9];  /* 0x800A70BC */
    { R[31] = 0x800A70C8u; sw_(R[18] + 8, R[3]); psx_next = 0x800908F4u; return; }  /* 0x800A70C0 jal */
    R[4] = R[20] + R[0];  /* 0x800A70C8 */
    R[2] = R[2] << 14;  /* 0x800A70CC */
    R[5] = 0xFFFEu << 16;  /* 0x800A70D0 */
    R[2] = R[2] + R[5];  /* 0x800A70D4 */
    R[6] = 0x800Fu << 16;  /* 0x800A70D8 */
    R[5] = R[17] + R[0];  /* 0x800A70DC */
    R[6] = R[6] - 13856;  /* 0x800A70E0 */
    R[3] = lw_(R[18] + 4);  /* 0x800A70E4 */
    R[7] = R[18] + R[0];  /* 0x800A70E8 */
    R[3] = R[3] + R[2];  /* 0x800A70EC */
    { R[31] = 0x800A70F8u; sw_(R[18] + 4, R[3]); psx_next = 0x800A5964u; return; }  /* 0x800A70F0 jal */
    { R[31] = 0x800A7100u; R[4] = R[0] + 10; psx_next = 0x800908F4u; return; }  /* 0x800A70F8 jal */
    R[6] = 0xFFFDu << 16;  /* 0x800A7100 */
    R[6] = R[6] | 0x8000;  /* 0x800A7104 */
    R[2] = R[2] << 15;  /* 0x800A7108 */
    R[2] = R[2] + R[6];  /* 0x800A710C */
    R[5] = lw_(R[19] + 24);  /* 0x800A7110 */
    R[4] = lw_(R[17] + 8);  /* 0x800A7114 */
    R[3] = lw_(R[19] + 488);  /* 0x800A7118 */
    R[5] = R[5] - R[4];  /* 0x800A711C */
    R[4] = R[3] >> 31;  /* 0x800A7120 */
    R[3] = R[3] + R[4];  /* 0x800A7124 */
    R[4] = lw_(R[19] + 28);  /* 0x800A7128 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x800A712C */
    R[4] = R[4] + R[3];  /* 0x800A7130 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[4] = R[4] - R[2]; if (_c) { goto L_800A7140; } }  /* 0x800A7134 */
    R[5] = R[5] + 7;  /* 0x800A713C */
L_800A7140:;
    R[2] = lw_(R[17] + 12);  /* 0x800A7140 */
    R[3] = (uint32_t)((int32_t)R[5] >> 3);  /* 0x800A7144 */
    R[2] = R[4] + R[2];  /* 0x800A7148 */
    R[2] = R[0] - R[2];  /* 0x800A714C */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[17] + 32, R[3]); if (_c) { goto L_800A715C; } }  /* 0x800A7150 */
    R[2] = R[2] + 7;  /* 0x800A7158 */
L_800A715C:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A715C */
    sw_(R[17] + 36, R[2]);  /* 0x800A7160 */
    R[3] = lw_(R[19] + 32);  /* 0x800A7164 */
    R[2] = lw_(R[17] + 16);  /* 0x800A7168 */
    R[2] = R[3] - R[2];  /* 0x800A7170 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800A7180; } }  /* 0x800A7174 */
    R[2] = R[2] + 7;  /* 0x800A717C */
L_800A7180:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7180 */
    sw_(R[17] + 40, R[2]);  /* 0x800A7184 */
    R[31] = lw_(R[29] + 36);  /* 0x800A7188 */
    R[20] = lw_(R[29] + 32);  /* 0x800A718C */
    R[19] = lw_(R[29] + 28);  /* 0x800A7190 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7194 */
    R[17] = lw_(R[29] + 20);  /* 0x800A7198 */
    R[16] = lw_(R[29] + 16);  /* 0x800A719C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A71A0 jr ra */
}

void g0_800A70C8(void) {
    R[4] = R[20] + R[0];  /* 0x800A70C8 */
    R[2] = R[2] << 14;  /* 0x800A70CC */
    R[5] = 0xFFFEu << 16;  /* 0x800A70D0 */
    R[2] = R[2] + R[5];  /* 0x800A70D4 */
    R[6] = 0x800Fu << 16;  /* 0x800A70D8 */
    R[5] = R[17] + R[0];  /* 0x800A70DC */
    R[6] = R[6] - 13856;  /* 0x800A70E0 */
    R[3] = lw_(R[18] + 4);  /* 0x800A70E4 */
    R[7] = R[18] + R[0];  /* 0x800A70E8 */
    R[3] = R[3] + R[2];  /* 0x800A70EC */
    { R[31] = 0x800A70F8u; sw_(R[18] + 4, R[3]); psx_next = 0x800A5964u; return; }  /* 0x800A70F0 jal */
    { R[31] = 0x800A7100u; R[4] = R[0] + 10; psx_next = 0x800908F4u; return; }  /* 0x800A70F8 jal */
    R[6] = 0xFFFDu << 16;  /* 0x800A7100 */
    R[6] = R[6] | 0x8000;  /* 0x800A7104 */
    R[2] = R[2] << 15;  /* 0x800A7108 */
    R[2] = R[2] + R[6];  /* 0x800A710C */
    R[5] = lw_(R[19] + 24);  /* 0x800A7110 */
    R[4] = lw_(R[17] + 8);  /* 0x800A7114 */
    R[3] = lw_(R[19] + 488);  /* 0x800A7118 */
    R[5] = R[5] - R[4];  /* 0x800A711C */
    R[4] = R[3] >> 31;  /* 0x800A7120 */
    R[3] = R[3] + R[4];  /* 0x800A7124 */
    R[4] = lw_(R[19] + 28);  /* 0x800A7128 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x800A712C */
    R[4] = R[4] + R[3];  /* 0x800A7130 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[4] = R[4] - R[2]; if (_c) { goto L_800A7140; } }  /* 0x800A7134 */
    R[5] = R[5] + 7;  /* 0x800A713C */
L_800A7140:;
    R[2] = lw_(R[17] + 12);  /* 0x800A7140 */
    R[3] = (uint32_t)((int32_t)R[5] >> 3);  /* 0x800A7144 */
    R[2] = R[4] + R[2];  /* 0x800A7148 */
    R[2] = R[0] - R[2];  /* 0x800A714C */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[17] + 32, R[3]); if (_c) { goto L_800A715C; } }  /* 0x800A7150 */
    R[2] = R[2] + 7;  /* 0x800A7158 */
L_800A715C:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A715C */
    sw_(R[17] + 36, R[2]);  /* 0x800A7160 */
    R[3] = lw_(R[19] + 32);  /* 0x800A7164 */
    R[2] = lw_(R[17] + 16);  /* 0x800A7168 */
    R[2] = R[3] - R[2];  /* 0x800A7170 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800A7180; } }  /* 0x800A7174 */
    R[2] = R[2] + 7;  /* 0x800A717C */
L_800A7180:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7180 */
    sw_(R[17] + 40, R[2]);  /* 0x800A7184 */
    R[31] = lw_(R[29] + 36);  /* 0x800A7188 */
    R[20] = lw_(R[29] + 32);  /* 0x800A718C */
    R[19] = lw_(R[29] + 28);  /* 0x800A7190 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7194 */
    R[17] = lw_(R[29] + 20);  /* 0x800A7198 */
    R[16] = lw_(R[29] + 16);  /* 0x800A719C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A71A0 jr ra */
}

void g0_800A70F8(void) {
    { R[31] = 0x800A7100u; R[4] = R[0] + 10; psx_next = 0x800908F4u; return; }  /* 0x800A70F8 jal */
    R[6] = 0xFFFDu << 16;  /* 0x800A7100 */
    R[6] = R[6] | 0x8000;  /* 0x800A7104 */
    R[2] = R[2] << 15;  /* 0x800A7108 */
    R[2] = R[2] + R[6];  /* 0x800A710C */
    R[5] = lw_(R[19] + 24);  /* 0x800A7110 */
    R[4] = lw_(R[17] + 8);  /* 0x800A7114 */
    R[3] = lw_(R[19] + 488);  /* 0x800A7118 */
    R[5] = R[5] - R[4];  /* 0x800A711C */
    R[4] = R[3] >> 31;  /* 0x800A7120 */
    R[3] = R[3] + R[4];  /* 0x800A7124 */
    R[4] = lw_(R[19] + 28);  /* 0x800A7128 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x800A712C */
    R[4] = R[4] + R[3];  /* 0x800A7130 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[4] = R[4] - R[2]; if (_c) { goto L_800A7140; } }  /* 0x800A7134 */
    R[5] = R[5] + 7;  /* 0x800A713C */
L_800A7140:;
    R[2] = lw_(R[17] + 12);  /* 0x800A7140 */
    R[3] = (uint32_t)((int32_t)R[5] >> 3);  /* 0x800A7144 */
    R[2] = R[4] + R[2];  /* 0x800A7148 */
    R[2] = R[0] - R[2];  /* 0x800A714C */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[17] + 32, R[3]); if (_c) { goto L_800A715C; } }  /* 0x800A7150 */
    R[2] = R[2] + 7;  /* 0x800A7158 */
L_800A715C:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A715C */
    sw_(R[17] + 36, R[2]);  /* 0x800A7160 */
    R[3] = lw_(R[19] + 32);  /* 0x800A7164 */
    R[2] = lw_(R[17] + 16);  /* 0x800A7168 */
    R[2] = R[3] - R[2];  /* 0x800A7170 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800A7180; } }  /* 0x800A7174 */
    R[2] = R[2] + 7;  /* 0x800A717C */
L_800A7180:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7180 */
    sw_(R[17] + 40, R[2]);  /* 0x800A7184 */
    R[31] = lw_(R[29] + 36);  /* 0x800A7188 */
    R[20] = lw_(R[29] + 32);  /* 0x800A718C */
    R[19] = lw_(R[29] + 28);  /* 0x800A7190 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7194 */
    R[17] = lw_(R[29] + 20);  /* 0x800A7198 */
    R[16] = lw_(R[29] + 16);  /* 0x800A719C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A71A0 jr ra */
}

void g0_800A7100(void) {
    R[6] = 0xFFFDu << 16;  /* 0x800A7100 */
    R[6] = R[6] | 0x8000;  /* 0x800A7104 */
    R[2] = R[2] << 15;  /* 0x800A7108 */
    R[2] = R[2] + R[6];  /* 0x800A710C */
    R[5] = lw_(R[19] + 24);  /* 0x800A7110 */
    R[4] = lw_(R[17] + 8);  /* 0x800A7114 */
    R[3] = lw_(R[19] + 488);  /* 0x800A7118 */
    R[5] = R[5] - R[4];  /* 0x800A711C */
    R[4] = R[3] >> 31;  /* 0x800A7120 */
    R[3] = R[3] + R[4];  /* 0x800A7124 */
    R[4] = lw_(R[19] + 28);  /* 0x800A7128 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x800A712C */
    R[4] = R[4] + R[3];  /* 0x800A7130 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[4] = R[4] - R[2]; if (_c) { goto L_800A7140; } }  /* 0x800A7134 */
    R[5] = R[5] + 7;  /* 0x800A713C */
L_800A7140:;
    R[2] = lw_(R[17] + 12);  /* 0x800A7140 */
    R[3] = (uint32_t)((int32_t)R[5] >> 3);  /* 0x800A7144 */
    R[2] = R[4] + R[2];  /* 0x800A7148 */
    R[2] = R[0] - R[2];  /* 0x800A714C */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[17] + 32, R[3]); if (_c) { goto L_800A715C; } }  /* 0x800A7150 */
    R[2] = R[2] + 7;  /* 0x800A7158 */
L_800A715C:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A715C */
    sw_(R[17] + 36, R[2]);  /* 0x800A7160 */
    R[3] = lw_(R[19] + 32);  /* 0x800A7164 */
    R[2] = lw_(R[17] + 16);  /* 0x800A7168 */
    R[2] = R[3] - R[2];  /* 0x800A7170 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800A7180; } }  /* 0x800A7174 */
    R[2] = R[2] + 7;  /* 0x800A717C */
L_800A7180:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7180 */
    sw_(R[17] + 40, R[2]);  /* 0x800A7184 */
    R[31] = lw_(R[29] + 36);  /* 0x800A7188 */
    R[20] = lw_(R[29] + 32);  /* 0x800A718C */
    R[19] = lw_(R[29] + 28);  /* 0x800A7190 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7194 */
    R[17] = lw_(R[29] + 20);  /* 0x800A7198 */
    R[16] = lw_(R[29] + 16);  /* 0x800A719C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A71A0 jr ra */
}

void g0_800A71A8(void) {
    R[29] = R[29] - 40;  /* 0x800A71A8 */
    sw_(R[29] + 28, R[19]);  /* 0x800A71AC */
    R[19] = R[4] + R[0];  /* 0x800A71B0 */
    sw_(R[29] + 24, R[18]);  /* 0x800A71B4 */
    R[18] = R[5] + R[0];  /* 0x800A71B8 */
    R[4] = 0x8013u << 16;  /* 0x800A71BC */
    R[4] = R[4] - 28480;  /* 0x800A71C0 */
    sw_(R[29] + 32, R[31]);  /* 0x800A71C4 */
    sw_(R[29] + 20, R[17]);  /* 0x800A71C8 */
    { R[31] = 0x800A71D4u; sw_(R[29] + 16, R[16]); psx_next = 0x800A592Cu; return; }  /* 0x800A71CC jal */
    R[17] = R[2] + R[0];  /* 0x800A71D4 */
    { uint32_t _c = (R[17] == R[0]); if (_c) { goto L_800A7274; } }  /* 0x800A71D8 */
    { R[31] = 0x800A71E8u; R[4] = R[0] + 32; psx_next = 0x800908F4u; return; }  /* 0x800A71E0 jal */
    R[4] = R[0] + 5;  /* 0x800A71E8 */
    R[16] = R[2] << 4;  /* 0x800A71EC */
    { R[31] = 0x800A71F8u; R[16] = R[16] & 0x1FF; psx_next = 0x800908F4u; return; }  /* 0x800A71F0 jal */
    R[2] = R[2] << 6;  /* 0x800A71F8 */
    R[3] = 0x8008u << 16;  /* 0x800A71FC */
    R[3] = R[3] + 5492;  /* 0x800A7200 */
    R[16] = R[16] << 1;  /* 0x800A7204 */
    R[3] = R[16] + R[3];  /* 0x800A7208 */
    R[3] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800A720C */
    R[2] = R[2] + 224;  /* 0x800A7210 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A7214 */
    R[3] = 0x8008u << 16;  /* 0x800A7218 */
    R[3] = R[3] + 6516;  /* 0x800A721C */
    R[16] = R[16] + R[3];  /* 0x800A7220 */
    R[5] = LO;  /* 0x800A7224 */
    R[3] = (uint32_t)(int16_t)lh_(R[16]);  /* 0x800A7228 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A7230 */
    R[4] = R[19] + R[0];  /* 0x800A7234 */
    R[6] = 0x800Fu << 16;  /* 0x800A7238 */
    R[6] = R[6] - 13832;  /* 0x800A723C */
    R[7] = R[18] + R[0];  /* 0x800A7240 */
    R[2] = lw_(R[18]);  /* 0x800A7244 */
    R[3] = lw_(R[18] + 8);  /* 0x800A7248 */
    R[2] = R[2] + R[5];  /* 0x800A724C */
    R[5] = R[17] + R[0];  /* 0x800A7250 */
    sw_(R[18], R[2]);  /* 0x800A7254 */
    R[9] = LO;  /* 0x800A7258 */
    R[3] = R[3] + R[9];  /* 0x800A725C */
    { R[31] = 0x800A7268u; sw_(R[18] + 8, R[3]); psx_next = 0x800A5964u; return; }  /* 0x800A7260 jal */
    R[2] = 0xFFFEu << 16;  /* 0x800A7268 */
    R[2] = R[2] | 0x7000;  /* 0x800A726C */
    sw_(R[17] + 36, R[2]);  /* 0x800A7270 */
L_800A7274:;
    R[31] = lw_(R[29] + 32);  /* 0x800A7274 */
    R[19] = lw_(R[29] + 28);  /* 0x800A7278 */
    R[18] = lw_(R[29] + 24);  /* 0x800A727C */
    R[17] = lw_(R[29] + 20);  /* 0x800A7280 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7284 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7288 jr ra */
}

void g0_800A71D4(void) {
    R[17] = R[2] + R[0];  /* 0x800A71D4 */
    { uint32_t _c = (R[17] == R[0]); if (_c) { goto L_800A7274; } }  /* 0x800A71D8 */
    { R[31] = 0x800A71E8u; R[4] = R[0] + 32; psx_next = 0x800908F4u; return; }  /* 0x800A71E0 jal */
    R[4] = R[0] + 5;  /* 0x800A71E8 */
    R[16] = R[2] << 4;  /* 0x800A71EC */
    { R[31] = 0x800A71F8u; R[16] = R[16] & 0x1FF; psx_next = 0x800908F4u; return; }  /* 0x800A71F0 jal */
    R[2] = R[2] << 6;  /* 0x800A71F8 */
    R[3] = 0x8008u << 16;  /* 0x800A71FC */
    R[3] = R[3] + 5492;  /* 0x800A7200 */
    R[16] = R[16] << 1;  /* 0x800A7204 */
    R[3] = R[16] + R[3];  /* 0x800A7208 */
    R[3] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800A720C */
    R[2] = R[2] + 224;  /* 0x800A7210 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A7214 */
    R[3] = 0x8008u << 16;  /* 0x800A7218 */
    R[3] = R[3] + 6516;  /* 0x800A721C */
    R[16] = R[16] + R[3];  /* 0x800A7220 */
    R[5] = LO;  /* 0x800A7224 */
    R[3] = (uint32_t)(int16_t)lh_(R[16]);  /* 0x800A7228 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A7230 */
    R[4] = R[19] + R[0];  /* 0x800A7234 */
    R[6] = 0x800Fu << 16;  /* 0x800A7238 */
    R[6] = R[6] - 13832;  /* 0x800A723C */
    R[7] = R[18] + R[0];  /* 0x800A7240 */
    R[2] = lw_(R[18]);  /* 0x800A7244 */
    R[3] = lw_(R[18] + 8);  /* 0x800A7248 */
    R[2] = R[2] + R[5];  /* 0x800A724C */
    R[5] = R[17] + R[0];  /* 0x800A7250 */
    sw_(R[18], R[2]);  /* 0x800A7254 */
    R[9] = LO;  /* 0x800A7258 */
    R[3] = R[3] + R[9];  /* 0x800A725C */
    { R[31] = 0x800A7268u; sw_(R[18] + 8, R[3]); psx_next = 0x800A5964u; return; }  /* 0x800A7260 jal */
    R[2] = 0xFFFEu << 16;  /* 0x800A7268 */
    R[2] = R[2] | 0x7000;  /* 0x800A726C */
    sw_(R[17] + 36, R[2]);  /* 0x800A7270 */
L_800A7274:;
    R[31] = lw_(R[29] + 32);  /* 0x800A7274 */
    R[19] = lw_(R[29] + 28);  /* 0x800A7278 */
    R[18] = lw_(R[29] + 24);  /* 0x800A727C */
    R[17] = lw_(R[29] + 20);  /* 0x800A7280 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7284 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7288 jr ra */
}

void g0_800A71E8(void) {
    R[4] = R[0] + 5;  /* 0x800A71E8 */
    R[16] = R[2] << 4;  /* 0x800A71EC */
    { R[31] = 0x800A71F8u; R[16] = R[16] & 0x1FF; psx_next = 0x800908F4u; return; }  /* 0x800A71F0 jal */
    R[2] = R[2] << 6;  /* 0x800A71F8 */
    R[3] = 0x8008u << 16;  /* 0x800A71FC */
    R[3] = R[3] + 5492;  /* 0x800A7200 */
    R[16] = R[16] << 1;  /* 0x800A7204 */
    R[3] = R[16] + R[3];  /* 0x800A7208 */
    R[3] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800A720C */
    R[2] = R[2] + 224;  /* 0x800A7210 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A7214 */
    R[3] = 0x8008u << 16;  /* 0x800A7218 */
    R[3] = R[3] + 6516;  /* 0x800A721C */
    R[16] = R[16] + R[3];  /* 0x800A7220 */
    R[5] = LO;  /* 0x800A7224 */
    R[3] = (uint32_t)(int16_t)lh_(R[16]);  /* 0x800A7228 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A7230 */
    R[4] = R[19] + R[0];  /* 0x800A7234 */
    R[6] = 0x800Fu << 16;  /* 0x800A7238 */
    R[6] = R[6] - 13832;  /* 0x800A723C */
    R[7] = R[18] + R[0];  /* 0x800A7240 */
    R[2] = lw_(R[18]);  /* 0x800A7244 */
    R[3] = lw_(R[18] + 8);  /* 0x800A7248 */
    R[2] = R[2] + R[5];  /* 0x800A724C */
    R[5] = R[17] + R[0];  /* 0x800A7250 */
    sw_(R[18], R[2]);  /* 0x800A7254 */
    R[9] = LO;  /* 0x800A7258 */
    R[3] = R[3] + R[9];  /* 0x800A725C */
    { R[31] = 0x800A7268u; sw_(R[18] + 8, R[3]); psx_next = 0x800A5964u; return; }  /* 0x800A7260 jal */
    R[2] = 0xFFFEu << 16;  /* 0x800A7268 */
    R[2] = R[2] | 0x7000;  /* 0x800A726C */
    sw_(R[17] + 36, R[2]);  /* 0x800A7270 */
    R[31] = lw_(R[29] + 32);  /* 0x800A7274 */
    R[19] = lw_(R[29] + 28);  /* 0x800A7278 */
    R[18] = lw_(R[29] + 24);  /* 0x800A727C */
    R[17] = lw_(R[29] + 20);  /* 0x800A7280 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7284 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7288 jr ra */
}

void g0_800A71F8(void) {
    R[2] = R[2] << 6;  /* 0x800A71F8 */
    R[3] = 0x8008u << 16;  /* 0x800A71FC */
    R[3] = R[3] + 5492;  /* 0x800A7200 */
    R[16] = R[16] << 1;  /* 0x800A7204 */
    R[3] = R[16] + R[3];  /* 0x800A7208 */
    R[3] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x800A720C */
    R[2] = R[2] + 224;  /* 0x800A7210 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A7214 */
    R[3] = 0x8008u << 16;  /* 0x800A7218 */
    R[3] = R[3] + 6516;  /* 0x800A721C */
    R[16] = R[16] + R[3];  /* 0x800A7220 */
    R[5] = LO;  /* 0x800A7224 */
    R[3] = (uint32_t)(int16_t)lh_(R[16]);  /* 0x800A7228 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A7230 */
    R[4] = R[19] + R[0];  /* 0x800A7234 */
    R[6] = 0x800Fu << 16;  /* 0x800A7238 */
    R[6] = R[6] - 13832;  /* 0x800A723C */
    R[7] = R[18] + R[0];  /* 0x800A7240 */
    R[2] = lw_(R[18]);  /* 0x800A7244 */
    R[3] = lw_(R[18] + 8);  /* 0x800A7248 */
    R[2] = R[2] + R[5];  /* 0x800A724C */
    R[5] = R[17] + R[0];  /* 0x800A7250 */
    sw_(R[18], R[2]);  /* 0x800A7254 */
    R[9] = LO;  /* 0x800A7258 */
    R[3] = R[3] + R[9];  /* 0x800A725C */
    { R[31] = 0x800A7268u; sw_(R[18] + 8, R[3]); psx_next = 0x800A5964u; return; }  /* 0x800A7260 jal */
    R[2] = 0xFFFEu << 16;  /* 0x800A7268 */
    R[2] = R[2] | 0x7000;  /* 0x800A726C */
    sw_(R[17] + 36, R[2]);  /* 0x800A7270 */
    R[31] = lw_(R[29] + 32);  /* 0x800A7274 */
    R[19] = lw_(R[29] + 28);  /* 0x800A7278 */
    R[18] = lw_(R[29] + 24);  /* 0x800A727C */
    R[17] = lw_(R[29] + 20);  /* 0x800A7280 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7284 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7288 jr ra */
}

void g0_800A7268(void) {
    R[2] = 0xFFFEu << 16;  /* 0x800A7268 */
    R[2] = R[2] | 0x7000;  /* 0x800A726C */
    sw_(R[17] + 36, R[2]);  /* 0x800A7270 */
    R[31] = lw_(R[29] + 32);  /* 0x800A7274 */
    R[19] = lw_(R[29] + 28);  /* 0x800A7278 */
    R[18] = lw_(R[29] + 24);  /* 0x800A727C */
    R[17] = lw_(R[29] + 20);  /* 0x800A7280 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7284 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7288 jr ra */
}

void g0_800A7290(void) {
    R[29] = R[29] - 40;  /* 0x800A7290 */
    R[2] = lw_(R[29] + 56);  /* 0x800A7294 */
    sw_(R[29] + 32, R[31]);  /* 0x800A7298 */
    sw_(R[29] + 16, R[5]);  /* 0x800A729C */
    sw_(R[29] + 20, R[6]);  /* 0x800A72A0 */
    sw_(R[29] + 24, R[7]);  /* 0x800A72A4 */
    sw_(R[29] + 28, R[2]);  /* 0x800A72A8 */
    R[2] = ((int32_t)R[4] < 100);  /* 0x800A72AC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Fu << 16; if (_c) { goto L_800A72C4; } }  /* 0x800A72B0 */
    R[2] = R[2] - 13808;  /* 0x800A72B8 */
    { R[3] = R[4] << 2; goto L_800A72D4; }  /* 0x800A72BC j */
L_800A72C4:;
    R[2] = 0x800Fu << 16;  /* 0x800A72C4 */
    R[2] = R[2] + 2172;  /* 0x800A72C8 */
    R[3] = R[4] - 100;  /* 0x800A72CC */
    R[3] = R[3] << 2;  /* 0x800A72D0 */
L_800A72D4:;
    R[3] = R[3] + R[2];  /* 0x800A72D4 */
    R[2] = lw_(R[3]);  /* 0x800A72D8 */
    { uint32_t _t = R[2]; R[31] = 0x800A72E8u; R[5] = R[29] + 16; psx_next = _t; return; }  /* 0x800A72E0 jalr */
    R[31] = lw_(R[29] + 32);  /* 0x800A72E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A72F0 jr ra */
}

void g0_800A72E8(void) {
    R[31] = lw_(R[29] + 32);  /* 0x800A72E8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A72F0 jr ra */
}

void g0_800A72F8(void) {
    R[7] = R[4] + R[0];  /* 0x800A72F8 */
    R[3] = lw_(R[7] + 44);  /* 0x800A72FC */
    R[2] = 0x200u << 16;  /* 0x800A7300 */
    R[6] = R[3] & 0xFF;  /* 0x800A7304 */
    R[6] = R[6] + R[5];  /* 0x800A7308 */
    { uint32_t _c = ((int32_t)R[6] >= 0); R[8] = R[3] & R[2]; if (_c) { goto L_800A731C; } }  /* 0x800A730C */
    { R[6] = R[0] + R[0]; goto L_800A732C; }  /* 0x800A7314 j */
L_800A731C:;
    R[2] = ((int32_t)R[6] < 256);  /* 0x800A731C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800A732C; } }  /* 0x800A7320 */
    R[6] = R[0] + 255;  /* 0x800A7328 */
L_800A732C:;
    R[3] = lb_(R[7] + 45);  /* 0x800A732C */
    R[3] = R[3] + R[5];  /* 0x800A7334 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = ((int32_t)R[3] < 256); if (_c) { goto L_800A7348; } }  /* 0x800A7338 */
    { R[3] = R[0] + R[0]; goto L_800A7354; }  /* 0x800A7340 j */
L_800A7348:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800A7354; } }  /* 0x800A7348 */
    R[3] = R[0] + 255;  /* 0x800A7350 */
L_800A7354:;
    R[4] = lb_(R[7] + 46);  /* 0x800A7354 */
    R[4] = R[4] + R[5];  /* 0x800A735C */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[2] = ((int32_t)R[4] < 256); if (_c) { goto L_800A7370; } }  /* 0x800A7360 */
    { R[4] = R[0] + R[0]; goto L_800A737C; }  /* 0x800A7368 j */
L_800A7370:;
    { uint32_t _c = (R[2] != R[0]); R[2] = R[4] << 16; if (_c) { goto L_800A7380; } }  /* 0x800A7370 */
    R[4] = R[0] + 255;  /* 0x800A7378 */
L_800A737C:;
    R[2] = R[4] << 16;  /* 0x800A737C */
L_800A7380:;
    R[3] = R[3] << 8;  /* 0x800A7380 */
    R[4] = 0x2C00u << 16;  /* 0x800A7384 */
    R[3] = R[3] | R[4];  /* 0x800A7388 */
    R[2] = R[2] | R[3];  /* 0x800A738C */
    R[2] = R[2] | R[6];  /* 0x800A7390 */
    R[2] = R[2] | R[8];  /* 0x800A7394 */
    { sw_(R[7] + 44, R[2]); psx_next = R[31]; return; }  /* 0x800A7398 jr ra */
}

void g0_800A73A0(void) {
    R[29] = R[29] - 24;  /* 0x800A73A0 */
    sw_(R[29] + 16, R[16]);  /* 0x800A73A4 */
    R[16] = R[4] + R[0];  /* 0x800A73A8 */
    sw_(R[29] + 20, R[31]);  /* 0x800A73AC */
    { R[31] = 0x800A73B8u; R[5] = R[0] + 10; psx_next = 0x800A72F8u; return; }  /* 0x800A73B0 jal */
    R[2] = lb_(R[16] + 52);  /* 0x800A73B8 */
    R[3] = lb_(R[16] + 53);  /* 0x800A73BC */
    R[2] = R[2] + 10;  /* 0x800A73C0 */
    R[3] = R[3] + 10;  /* 0x800A73C4 */
    sb_(R[16] + 52, R[2]);  /* 0x800A73C8 */
    sb_(R[16] + 53, R[3]);  /* 0x800A73CC */
    R[31] = lw_(R[29] + 20);  /* 0x800A73D0 */
    R[16] = lw_(R[29] + 16);  /* 0x800A73D4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A73D8 jr ra */
}

void g0_800A73B8(void) {
    R[2] = lb_(R[16] + 52);  /* 0x800A73B8 */
    R[3] = lb_(R[16] + 53);  /* 0x800A73BC */
    R[2] = R[2] + 10;  /* 0x800A73C0 */
    R[3] = R[3] + 10;  /* 0x800A73C4 */
    sb_(R[16] + 52, R[2]);  /* 0x800A73C8 */
    sb_(R[16] + 53, R[3]);  /* 0x800A73CC */
    R[31] = lw_(R[29] + 20);  /* 0x800A73D0 */
    R[16] = lw_(R[29] + 16);  /* 0x800A73D4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A73D8 jr ra */
}

void g0_800A73E0(void) {
    R[29] = R[29] - 24;  /* 0x800A73E0 */
    sw_(R[29] + 16, R[16]);  /* 0x800A73E4 */
    R[16] = R[4] + R[0];  /* 0x800A73E8 */
    R[2] = 0x6666u << 16;  /* 0x800A73EC */
    sw_(R[29] + 20, R[31]);  /* 0x800A73F0 */
    R[3] = lw_(R[16] + 32);  /* 0x800A73F4 */
    R[2] = R[2] | 0x6667;  /* 0x800A73F8 */
    R[3] = R[3] << 3;  /* 0x800A73FC */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A7400 */
    R[5] = lw_(R[16] + 40);  /* 0x800A7404 */
    R[8] = HI;  /* 0x800A7408 */
    R[5] = R[5] << 3;  /* 0x800A740C */
    { int64_t _p = (int64_t)(int32_t)R[5] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A7414 */
    R[4] = R[0] + 8;  /* 0x800A7418 */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x800A741C */
    R[2] = (uint32_t)((int32_t)R[8] >> 2);  /* 0x800A7420 */
    R[2] = R[2] - R[3];  /* 0x800A7424 */
    R[5] = (uint32_t)((int32_t)R[5] >> 31);  /* 0x800A7428 */
    sw_(R[16] + 32, R[2]);  /* 0x800A742C */
    R[6] = HI;  /* 0x800A7430 */
    R[2] = (uint32_t)((int32_t)R[6] >> 2);  /* 0x800A7434 */
    R[2] = R[2] - R[5];  /* 0x800A7438 */
    { R[31] = 0x800A7444u; sw_(R[16] + 40, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800A743C jal */
    R[4] = R[16] + R[0];  /* 0x800A7444 */
    R[2] = R[2] + 4;  /* 0x800A7448 */
    { R[31] = 0x800A7454u; R[5] = R[0] - R[2]; psx_next = 0x800A72F8u; return; }  /* 0x800A744C jal */
    R[31] = lw_(R[29] + 20);  /* 0x800A7454 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7458 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A745C jr ra */
    { psx_next = R[31]; return; }  /* 0x800A7464 jr ra */
}

void g0_800A7444(void) {
    R[4] = R[16] + R[0];  /* 0x800A7444 */
    R[2] = R[2] + 4;  /* 0x800A7448 */
    { R[31] = 0x800A7454u; R[5] = R[0] - R[2]; psx_next = 0x800A72F8u; return; }  /* 0x800A744C jal */
    R[31] = lw_(R[29] + 20);  /* 0x800A7454 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7458 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A745C jr ra */
    { psx_next = R[31]; return; }  /* 0x800A7464 jr ra */
}

void g0_800A7454(void) {
    R[31] = lw_(R[29] + 20);  /* 0x800A7454 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7458 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A745C jr ra */
    { psx_next = R[31]; return; }  /* 0x800A7464 jr ra */
}

void g0_800A7464(void) {
    { psx_next = R[31]; return; }  /* 0x800A7464 jr ra */
}

void g0_800A746C(void) {
    R[29] = R[29] - 24;  /* 0x800A746C */
    sw_(R[29] + 16, R[16]);  /* 0x800A7470 */
    R[16] = R[4] + R[0];  /* 0x800A7474 */
    sw_(R[29] + 20, R[31]);  /* 0x800A7478 */
    R[3] = lw_(R[16] + 32);  /* 0x800A747C */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[3] + R[0]; if (_c) { goto L_800A7490; } }  /* 0x800A7484 */
    R[2] = R[3] + 7;  /* 0x800A748C */
L_800A7490:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7490 */
    R[4] = lw_(R[16] + 40);  /* 0x800A7494 */
    R[2] = R[3] - R[2];  /* 0x800A7498 */
    sw_(R[16] + 32, R[2]);  /* 0x800A749C */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[2] = R[4] + R[0]; if (_c) { goto L_800A74AC; } }  /* 0x800A74A0 */
    R[2] = R[4] + 7;  /* 0x800A74A8 */
L_800A74AC:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A74AC */
    R[2] = R[4] - R[2];  /* 0x800A74B0 */
    sw_(R[16] + 40, R[2]);  /* 0x800A74B4 */
    R[2] = 0x8012u << 16;  /* 0x800A74B8 */
    R[5] = lw_(R[2] + 30964);  /* 0x800A74BC */
    R[4] = lw_(R[16] + 36);  /* 0x800A74C0 */
    R[2] = R[5] >> 31;  /* 0x800A74C4 */
    R[5] = R[5] + R[2];  /* 0x800A74C8 */
    R[4] = R[0] - R[4];  /* 0x800A74CC */
    { R[31] = 0x800A74D8u; R[5] = (uint32_t)((int32_t)R[5] >> 1); psx_next = 0x800A5B9Cu; return; }  /* 0x800A74D0 jal */
    R[2] = R[0] - R[2];  /* 0x800A74D8 */
    sw_(R[16] + 36, R[2]);  /* 0x800A74DC */
    R[31] = lw_(R[29] + 20);  /* 0x800A74E0 */
    R[16] = lw_(R[29] + 16);  /* 0x800A74E4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A74E8 jr ra */
    R[3] = lw_(R[4] + 32);  /* 0x800A74F0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[3] + R[0]; if (_c) { goto L_800A7504; } }  /* 0x800A74F8 */
    R[2] = R[3] + 7;  /* 0x800A7500 */
L_800A7504:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7504 */
    R[5] = lw_(R[4] + 40);  /* 0x800A7508 */
    R[2] = R[3] - R[2];  /* 0x800A750C */
    sw_(R[4] + 32, R[2]);  /* 0x800A7510 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[2] = R[5] + R[0]; if (_c) { goto L_800A7520; } }  /* 0x800A7514 */
    R[2] = R[5] + 7;  /* 0x800A751C */
L_800A7520:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7520 */
    R[3] = lb_(R[4] + 49);  /* 0x800A7524 */
    R[2] = R[5] - R[2];  /* 0x800A7528 */
    sw_(R[4] + 40, R[2]);  /* 0x800A752C */
    R[3] = R[3] + 8;  /* 0x800A7530 */
    { sb_(R[4] + 49, R[3]); psx_next = R[31]; return; }  /* 0x800A7534 jr ra */
    R[2] = lw_(R[4] + 60);  /* 0x800A753C */
    R[3] = lb_(R[2] + 21);  /* 0x800A7544 */
    R[2] = lb_(R[4] + 3);  /* 0x800A7548 */
    R[5] = R[3] - R[2];  /* 0x800A7550 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[2] = R[5] + R[0]; if (_c) { goto L_800A7560; } }  /* 0x800A7554 */
    R[2] = R[5] + 3;  /* 0x800A755C */
L_800A7560:;
    R[7] = (uint32_t)((int32_t)R[2] >> 2);  /* 0x800A7560 */
    R[6] = R[7] << 2;  /* 0x800A7564 */
    R[2] = R[5] - R[6];  /* 0x800A7568 */
    R[3] = R[2] << 3;  /* 0x800A756C */
    R[3] = R[3] - R[2];  /* 0x800A7570 */
    R[2] = lb_(R[4] + 68);  /* 0x800A7574 */
    R[3] = R[3] << 3;  /* 0x800A7578 */
    R[2] = R[2] + R[3];  /* 0x800A757C */
    sb_(R[4] + 48, R[2]);  /* 0x800A7580 */
    R[2] = R[6] + R[7];  /* 0x800A7584 */
    R[3] = lb_(R[4] + 69);  /* 0x800A7588 */
    R[2] = R[2] << 3;  /* 0x800A758C */
    R[3] = R[3] + R[2];  /* 0x800A7590 */
    { sb_(R[4] + 49, R[3]); psx_next = R[31]; return; }  /* 0x800A7594 jr ra */
}

void g0_800A74D8(void) {
    R[2] = R[0] - R[2];  /* 0x800A74D8 */
    sw_(R[16] + 36, R[2]);  /* 0x800A74DC */
    R[31] = lw_(R[29] + 20);  /* 0x800A74E0 */
    R[16] = lw_(R[29] + 16);  /* 0x800A74E4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A74E8 jr ra */
    R[3] = lw_(R[4] + 32);  /* 0x800A74F0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[3] + R[0]; if (_c) { goto L_800A7504; } }  /* 0x800A74F8 */
    R[2] = R[3] + 7;  /* 0x800A7500 */
L_800A7504:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7504 */
    R[5] = lw_(R[4] + 40);  /* 0x800A7508 */
    R[2] = R[3] - R[2];  /* 0x800A750C */
    sw_(R[4] + 32, R[2]);  /* 0x800A7510 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[2] = R[5] + R[0]; if (_c) { goto L_800A7520; } }  /* 0x800A7514 */
    R[2] = R[5] + 7;  /* 0x800A751C */
L_800A7520:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7520 */
    R[3] = lb_(R[4] + 49);  /* 0x800A7524 */
    R[2] = R[5] - R[2];  /* 0x800A7528 */
    sw_(R[4] + 40, R[2]);  /* 0x800A752C */
    R[3] = R[3] + 8;  /* 0x800A7530 */
    { sb_(R[4] + 49, R[3]); psx_next = R[31]; return; }  /* 0x800A7534 jr ra */
    R[2] = lw_(R[4] + 60);  /* 0x800A753C */
    R[3] = lb_(R[2] + 21);  /* 0x800A7544 */
    R[2] = lb_(R[4] + 3);  /* 0x800A7548 */
    R[5] = R[3] - R[2];  /* 0x800A7550 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[2] = R[5] + R[0]; if (_c) { goto L_800A7560; } }  /* 0x800A7554 */
    R[2] = R[5] + 3;  /* 0x800A755C */
L_800A7560:;
    R[7] = (uint32_t)((int32_t)R[2] >> 2);  /* 0x800A7560 */
    R[6] = R[7] << 2;  /* 0x800A7564 */
    R[2] = R[5] - R[6];  /* 0x800A7568 */
    R[3] = R[2] << 3;  /* 0x800A756C */
    R[3] = R[3] - R[2];  /* 0x800A7570 */
    R[2] = lb_(R[4] + 68);  /* 0x800A7574 */
    R[3] = R[3] << 3;  /* 0x800A7578 */
    R[2] = R[2] + R[3];  /* 0x800A757C */
    sb_(R[4] + 48, R[2]);  /* 0x800A7580 */
    R[2] = R[6] + R[7];  /* 0x800A7584 */
    R[3] = lb_(R[4] + 69);  /* 0x800A7588 */
    R[2] = R[2] << 3;  /* 0x800A758C */
    R[3] = R[3] + R[2];  /* 0x800A7590 */
    { sb_(R[4] + 49, R[3]); psx_next = R[31]; return; }  /* 0x800A7594 jr ra */
}

void g0_800A74F0(void) {
    R[3] = lw_(R[4] + 32);  /* 0x800A74F0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[3] + R[0]; if (_c) { goto L_800A7504; } }  /* 0x800A74F8 */
    R[2] = R[3] + 7;  /* 0x800A7500 */
L_800A7504:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7504 */
    R[5] = lw_(R[4] + 40);  /* 0x800A7508 */
    R[2] = R[3] - R[2];  /* 0x800A750C */
    sw_(R[4] + 32, R[2]);  /* 0x800A7510 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[2] = R[5] + R[0]; if (_c) { goto L_800A7520; } }  /* 0x800A7514 */
    R[2] = R[5] + 7;  /* 0x800A751C */
L_800A7520:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7520 */
    R[3] = lb_(R[4] + 49);  /* 0x800A7524 */
    R[2] = R[5] - R[2];  /* 0x800A7528 */
    sw_(R[4] + 40, R[2]);  /* 0x800A752C */
    R[3] = R[3] + 8;  /* 0x800A7530 */
    { sb_(R[4] + 49, R[3]); psx_next = R[31]; return; }  /* 0x800A7534 jr ra */
    R[2] = lw_(R[4] + 60);  /* 0x800A753C */
    R[3] = lb_(R[2] + 21);  /* 0x800A7544 */
    R[2] = lb_(R[4] + 3);  /* 0x800A7548 */
    R[5] = R[3] - R[2];  /* 0x800A7550 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[2] = R[5] + R[0]; if (_c) { goto L_800A7560; } }  /* 0x800A7554 */
    R[2] = R[5] + 3;  /* 0x800A755C */
L_800A7560:;
    R[7] = (uint32_t)((int32_t)R[2] >> 2);  /* 0x800A7560 */
    R[6] = R[7] << 2;  /* 0x800A7564 */
    R[2] = R[5] - R[6];  /* 0x800A7568 */
    R[3] = R[2] << 3;  /* 0x800A756C */
    R[3] = R[3] - R[2];  /* 0x800A7570 */
    R[2] = lb_(R[4] + 68);  /* 0x800A7574 */
    R[3] = R[3] << 3;  /* 0x800A7578 */
    R[2] = R[2] + R[3];  /* 0x800A757C */
    sb_(R[4] + 48, R[2]);  /* 0x800A7580 */
    R[2] = R[6] + R[7];  /* 0x800A7584 */
    R[3] = lb_(R[4] + 69);  /* 0x800A7588 */
    R[2] = R[2] << 3;  /* 0x800A758C */
    R[3] = R[3] + R[2];  /* 0x800A7590 */
    { sb_(R[4] + 49, R[3]); psx_next = R[31]; return; }  /* 0x800A7594 jr ra */
}

void g0_800A753C(void) {
    R[2] = lw_(R[4] + 60);  /* 0x800A753C */
    R[3] = lb_(R[2] + 21);  /* 0x800A7544 */
    R[2] = lb_(R[4] + 3);  /* 0x800A7548 */
    R[5] = R[3] - R[2];  /* 0x800A7550 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[2] = R[5] + R[0]; if (_c) { goto L_800A7560; } }  /* 0x800A7554 */
    R[2] = R[5] + 3;  /* 0x800A755C */
L_800A7560:;
    R[7] = (uint32_t)((int32_t)R[2] >> 2);  /* 0x800A7560 */
    R[6] = R[7] << 2;  /* 0x800A7564 */
    R[2] = R[5] - R[6];  /* 0x800A7568 */
    R[3] = R[2] << 3;  /* 0x800A756C */
    R[3] = R[3] - R[2];  /* 0x800A7570 */
    R[2] = lb_(R[4] + 68);  /* 0x800A7574 */
    R[3] = R[3] << 3;  /* 0x800A7578 */
    R[2] = R[2] + R[3];  /* 0x800A757C */
    sb_(R[4] + 48, R[2]);  /* 0x800A7580 */
    R[2] = R[6] + R[7];  /* 0x800A7584 */
    R[3] = lb_(R[4] + 69);  /* 0x800A7588 */
    R[2] = R[2] << 3;  /* 0x800A758C */
    R[3] = R[3] + R[2];  /* 0x800A7590 */
    { sb_(R[4] + 49, R[3]); psx_next = R[31]; return; }  /* 0x800A7594 jr ra */
}

void g0_800A759C(void) {
    R[29] = R[29] - 24;  /* 0x800A759C */
    sw_(R[29] + 16, R[16]);  /* 0x800A75A0 */
    R[16] = R[4] + R[0];  /* 0x800A75A4 */
    R[4] = 0x6666u << 16;  /* 0x800A75A8 */
    sw_(R[29] + 20, R[31]);  /* 0x800A75AC */
    R[2] = lw_(R[16] + 32);  /* 0x800A75B0 */
    R[4] = R[4] | 0x6667;  /* 0x800A75B4 */
    R[3] = R[2] << 3;  /* 0x800A75B8 */
    R[3] = R[3] + R[2];  /* 0x800A75BC */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A75C0 */
    R[2] = lw_(R[16] + 40);  /* 0x800A75C4 */
    R[8] = HI;  /* 0x800A75C8 */
    R[5] = R[2] << 3;  /* 0x800A75CC */
    R[5] = R[5] + R[2];  /* 0x800A75D0 */
    { int64_t _p = (int64_t)(int32_t)R[5] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A75D4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x800A75D8 */
    R[4] = R[0] + 8;  /* 0x800A75DC */
    R[2] = (uint32_t)((int32_t)R[8] >> 2);  /* 0x800A75E0 */
    R[2] = R[2] - R[3];  /* 0x800A75E4 */
    R[5] = (uint32_t)((int32_t)R[5] >> 31);  /* 0x800A75E8 */
    sw_(R[16] + 32, R[2]);  /* 0x800A75EC */
    R[6] = HI;  /* 0x800A75F0 */
    R[2] = (uint32_t)((int32_t)R[6] >> 2);  /* 0x800A75F4 */
    R[2] = R[2] - R[5];  /* 0x800A75F8 */
    { R[31] = 0x800A7604u; sw_(R[16] + 40, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800A75FC jal */
    R[4] = R[16] + R[0];  /* 0x800A7604 */
    R[2] = R[2] + 4;  /* 0x800A7608 */
    { R[31] = 0x800A7614u; R[5] = R[0] - R[2]; psx_next = 0x800A72F8u; return; }  /* 0x800A760C jal */
    R[31] = lw_(R[29] + 20);  /* 0x800A7614 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7618 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A761C jr ra */
}

void g0_800A7604(void) {
    R[4] = R[16] + R[0];  /* 0x800A7604 */
    R[2] = R[2] + 4;  /* 0x800A7608 */
    { R[31] = 0x800A7614u; R[5] = R[0] - R[2]; psx_next = 0x800A72F8u; return; }  /* 0x800A760C jal */
    R[31] = lw_(R[29] + 20);  /* 0x800A7614 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7618 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A761C jr ra */
}

void g0_800A7614(void) {
    R[31] = lw_(R[29] + 20);  /* 0x800A7614 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7618 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A761C jr ra */
}

void g0_800A7624(void) {
    R[29] = R[29] - 24;  /* 0x800A7624 */
    R[5] = R[0] - 8;  /* 0x800A7628 */
    sw_(R[29] + 16, R[31]);  /* 0x800A762C */
    R[2] = lb_(R[4] + 52);  /* 0x800A7630 */
    R[3] = lb_(R[4] + 53);  /* 0x800A7634 */
    R[2] = R[2] - 1;  /* 0x800A7638 */
    R[3] = R[3] - 1;  /* 0x800A763C */
    sb_(R[4] + 52, R[2]);  /* 0x800A7640 */
    { R[31] = 0x800A764Cu; sb_(R[4] + 53, R[3]); psx_next = 0x800A72F8u; return; }  /* 0x800A7644 jal */
    R[31] = lw_(R[29] + 16);  /* 0x800A764C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A7654 jr ra */
    { psx_next = R[31]; return; }  /* 0x800A765C jr ra */
}

void g0_800A764C(void) {
    R[31] = lw_(R[29] + 16);  /* 0x800A764C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A7654 jr ra */
    { psx_next = R[31]; return; }  /* 0x800A765C jr ra */
}

void g0_800A765C(void) {
    { psx_next = R[31]; return; }  /* 0x800A765C jr ra */
}

void g0_800A7664(void) {
    R[29] = R[29] - 24;  /* 0x800A7664 */
    sw_(R[29] + 16, R[16]);  /* 0x800A7668 */
    R[16] = R[4] + R[0];  /* 0x800A766C */
    sw_(R[29] + 20, R[31]);  /* 0x800A7670 */
    { R[31] = 0x800A767Cu; R[5] = R[0] - 10; psx_next = 0x800A72F8u; return; }  /* 0x800A7674 jal */
    R[2] = lb_(R[16] + 52);  /* 0x800A767C */
    R[3] = lb_(R[16] + 53);  /* 0x800A7680 */
    R[2] = R[2] - 2;  /* 0x800A7684 */
    R[3] = R[3] - 2;  /* 0x800A7688 */
    sb_(R[16] + 52, R[2]);  /* 0x800A768C */
    sb_(R[16] + 53, R[3]);  /* 0x800A7690 */
    R[31] = lw_(R[29] + 20);  /* 0x800A7694 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7698 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A769C jr ra */
}

void g0_800A767C(void) {
    R[2] = lb_(R[16] + 52);  /* 0x800A767C */
    R[3] = lb_(R[16] + 53);  /* 0x800A7680 */
    R[2] = R[2] - 2;  /* 0x800A7684 */
    R[3] = R[3] - 2;  /* 0x800A7688 */
    sb_(R[16] + 52, R[2]);  /* 0x800A768C */
    sb_(R[16] + 53, R[3]);  /* 0x800A7690 */
    R[31] = lw_(R[29] + 20);  /* 0x800A7694 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7698 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A769C jr ra */
}

void g0_800A76A4(void) {
    R[29] = R[29] - 24;  /* 0x800A76A4 */
    sw_(R[29] + 16, R[16]);  /* 0x800A76A8 */
    R[16] = R[4] + R[0];  /* 0x800A76AC */
    sw_(R[29] + 20, R[31]);  /* 0x800A76B0 */
    R[3] = lb_(R[16] + 3);  /* 0x800A76B4 */
    R[2] = R[0] + 4;  /* 0x800A76B8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800A76DC; } }  /* 0x800A76BC */
    { R[31] = 0x800A76CCu; R[4] = R[0] + 8; psx_next = 0x800908F4u; return; }  /* 0x800A76C4 jal */
    R[2] = R[2] << 8;  /* 0x800A76CC */
    R[2] = R[2] + 8192;  /* 0x800A76D0 */
    R[2] = R[0] - R[2];  /* 0x800A76D4 */
    sw_(R[16] + 36, R[2]);  /* 0x800A76D8 */
L_800A76DC:;
    R[31] = lw_(R[29] + 20);  /* 0x800A76DC */
    R[16] = lw_(R[29] + 16);  /* 0x800A76E0 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A76E4 jr ra */
    { psx_next = R[31]; return; }  /* 0x800A76EC jr ra */
}

void g0_800A76CC(void) {
    R[2] = R[2] << 8;  /* 0x800A76CC */
    R[2] = R[2] + 8192;  /* 0x800A76D0 */
    R[2] = R[0] - R[2];  /* 0x800A76D4 */
    sw_(R[16] + 36, R[2]);  /* 0x800A76D8 */
    R[31] = lw_(R[29] + 20);  /* 0x800A76DC */
    R[16] = lw_(R[29] + 16);  /* 0x800A76E0 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A76E4 jr ra */
    { psx_next = R[31]; return; }  /* 0x800A76EC jr ra */
}

void g0_800A76EC(void) {
    { psx_next = R[31]; return; }  /* 0x800A76EC jr ra */
}

void g0_800A76F4(void) {
    R[29] = R[29] - 24;  /* 0x800A76F4 */
    sw_(R[29] + 16, R[31]);  /* 0x800A76F8 */
    { R[31] = 0x800A7704u; R[5] = R[0] - 32; psx_next = 0x800A72F8u; return; }  /* 0x800A76FC jal */
    R[31] = lw_(R[29] + 16);  /* 0x800A7704 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A770C jr ra */
}

void g0_800A7704(void) {
    R[31] = lw_(R[29] + 16);  /* 0x800A7704 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A770C jr ra */
}

void g0_800A7714(void) {
    R[29] = R[29] - 24;  /* 0x800A7714 */
    sw_(R[29] + 16, R[16]);  /* 0x800A7718 */
    R[16] = R[4] + R[0];  /* 0x800A771C */
    sw_(R[29] + 20, R[31]);  /* 0x800A7720 */
    R[3] = lw_(R[16] + 32);  /* 0x800A7724 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[3] + R[0]; if (_c) { goto L_800A7738; } }  /* 0x800A772C */
    R[2] = R[3] + 7;  /* 0x800A7734 */
L_800A7738:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7738 */
    R[4] = lw_(R[16] + 40);  /* 0x800A773C */
    R[2] = R[3] - R[2];  /* 0x800A7740 */
    sw_(R[16] + 32, R[2]);  /* 0x800A7744 */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[2] = R[4] + R[0]; if (_c) { goto L_800A7754; } }  /* 0x800A7748 */
    R[2] = R[4] + 7;  /* 0x800A7750 */
L_800A7754:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7754 */
    R[2] = R[4] - R[2];  /* 0x800A7758 */
    sw_(R[16] + 40, R[2]);  /* 0x800A775C */
    R[2] = 0x8012u << 16;  /* 0x800A7760 */
    R[5] = lw_(R[2] + 30964);  /* 0x800A7764 */
    R[4] = lw_(R[16] + 36);  /* 0x800A7768 */
    R[2] = R[5] >> 31;  /* 0x800A776C */
    R[5] = R[5] + R[2];  /* 0x800A7770 */
    R[4] = R[0] - R[4];  /* 0x800A7774 */
    { R[31] = 0x800A7780u; R[5] = (uint32_t)((int32_t)R[5] >> 1); psx_next = 0x800A5B9Cu; return; }  /* 0x800A7778 jal */
    R[2] = R[0] - R[2];  /* 0x800A7780 */
    sw_(R[16] + 36, R[2]);  /* 0x800A7784 */
    R[2] = lb_(R[16] + 52);  /* 0x800A7788 */
    R[3] = lb_(R[16] + 53);  /* 0x800A778C */
    R[2] = R[2] + 1;  /* 0x800A7790 */
    R[3] = R[3] + 1;  /* 0x800A7794 */
    sb_(R[16] + 52, R[2]);  /* 0x800A7798 */
    sb_(R[16] + 53, R[3]);  /* 0x800A779C */
    R[31] = lw_(R[29] + 20);  /* 0x800A77A0 */
    R[16] = lw_(R[29] + 16);  /* 0x800A77A4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A77A8 jr ra */
}

void g0_800A7780(void) {
    R[2] = R[0] - R[2];  /* 0x800A7780 */
    sw_(R[16] + 36, R[2]);  /* 0x800A7784 */
    R[2] = lb_(R[16] + 52);  /* 0x800A7788 */
    R[3] = lb_(R[16] + 53);  /* 0x800A778C */
    R[2] = R[2] + 1;  /* 0x800A7790 */
    R[3] = R[3] + 1;  /* 0x800A7794 */
    sb_(R[16] + 52, R[2]);  /* 0x800A7798 */
    sb_(R[16] + 53, R[3]);  /* 0x800A779C */
    R[31] = lw_(R[29] + 20);  /* 0x800A77A0 */
    R[16] = lw_(R[29] + 16);  /* 0x800A77A4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A77A8 jr ra */
}

void g0_800A77B0(void) {
    R[29] = R[29] - 24;  /* 0x800A77B0 */
    sw_(R[29] + 16, R[31]);  /* 0x800A77B4 */
    { R[31] = 0x800A77C0u; R[5] = R[0] - 8; psx_next = 0x800A72F8u; return; }  /* 0x800A77B8 jal */
    R[31] = lw_(R[29] + 16);  /* 0x800A77C0 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A77C8 jr ra */
    { psx_next = R[31]; return; }  /* 0x800A77D0 jr ra */
    R[3] = lw_(R[4] + 32);  /* 0x800A77D8 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[3] + R[0]; if (_c) { goto L_800A77EC; } }  /* 0x800A77E0 */
    R[2] = R[3] + 7;  /* 0x800A77E8 */
L_800A77EC:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A77EC */
    R[5] = lw_(R[4] + 40);  /* 0x800A77F0 */
    R[2] = R[3] - R[2];  /* 0x800A77F4 */
    sw_(R[4] + 32, R[2]);  /* 0x800A77F8 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[2] = R[5] + R[0]; if (_c) { goto L_800A7808; } }  /* 0x800A77FC */
    R[2] = R[5] + 7;  /* 0x800A7804 */
L_800A7808:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7808 */
    R[2] = R[5] - R[2];  /* 0x800A780C */
    { sw_(R[4] + 40, R[2]); psx_next = R[31]; return; }  /* 0x800A7810 jr ra */
    R[3] = lb_(R[4] + 52);  /* 0x800A7818 */
    { uint32_t _c = (R[3] == R[0]); R[3] = R[3] - 4; if (_c) { goto L_800A7838; } }  /* 0x800A7820 */
    R[2] = lb_(R[4] + 53);  /* 0x800A7828 */
    sb_(R[4] + 52, R[3]);  /* 0x800A782C */
    R[2] = R[2] - 4;  /* 0x800A7830 */
    sb_(R[4] + 53, R[2]);  /* 0x800A7834 */
L_800A7838:;
    { psx_next = R[31]; return; }  /* 0x800A7838 jr ra */
    R[3] = lb_(R[4] + 52);  /* 0x800A7840 */
    { uint32_t _c = (R[3] == R[0]); R[3] = R[3] - 2; if (_c) { goto L_800A7860; } }  /* 0x800A7848 */
    R[2] = lb_(R[4] + 53);  /* 0x800A7850 */
    sb_(R[4] + 52, R[3]);  /* 0x800A7854 */
    R[2] = R[2] - 2;  /* 0x800A7858 */
    sb_(R[4] + 53, R[2]);  /* 0x800A785C */
L_800A7860:;
    { psx_next = R[31]; return; }  /* 0x800A7860 jr ra */
    { psx_next = R[31]; return; }  /* 0x800A7868 jr ra */
}

void g0_800A77C0(void) {
    R[31] = lw_(R[29] + 16);  /* 0x800A77C0 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A77C8 jr ra */
    { psx_next = R[31]; return; }  /* 0x800A77D0 jr ra */
    R[3] = lw_(R[4] + 32);  /* 0x800A77D8 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[3] + R[0]; if (_c) { goto L_800A77EC; } }  /* 0x800A77E0 */
    R[2] = R[3] + 7;  /* 0x800A77E8 */
L_800A77EC:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A77EC */
    R[5] = lw_(R[4] + 40);  /* 0x800A77F0 */
    R[2] = R[3] - R[2];  /* 0x800A77F4 */
    sw_(R[4] + 32, R[2]);  /* 0x800A77F8 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[2] = R[5] + R[0]; if (_c) { goto L_800A7808; } }  /* 0x800A77FC */
    R[2] = R[5] + 7;  /* 0x800A7804 */
L_800A7808:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7808 */
    R[2] = R[5] - R[2];  /* 0x800A780C */
    { sw_(R[4] + 40, R[2]); psx_next = R[31]; return; }  /* 0x800A7810 jr ra */
    R[3] = lb_(R[4] + 52);  /* 0x800A7818 */
    { uint32_t _c = (R[3] == R[0]); R[3] = R[3] - 4; if (_c) { goto L_800A7838; } }  /* 0x800A7820 */
    R[2] = lb_(R[4] + 53);  /* 0x800A7828 */
    sb_(R[4] + 52, R[3]);  /* 0x800A782C */
    R[2] = R[2] - 4;  /* 0x800A7830 */
    sb_(R[4] + 53, R[2]);  /* 0x800A7834 */
L_800A7838:;
    { psx_next = R[31]; return; }  /* 0x800A7838 jr ra */
    R[3] = lb_(R[4] + 52);  /* 0x800A7840 */
    { uint32_t _c = (R[3] == R[0]); R[3] = R[3] - 2; if (_c) { goto L_800A7860; } }  /* 0x800A7848 */
    R[2] = lb_(R[4] + 53);  /* 0x800A7850 */
    sb_(R[4] + 52, R[3]);  /* 0x800A7854 */
    R[2] = R[2] - 2;  /* 0x800A7858 */
    sb_(R[4] + 53, R[2]);  /* 0x800A785C */
L_800A7860:;
    { psx_next = R[31]; return; }  /* 0x800A7860 jr ra */
    { psx_next = R[31]; return; }  /* 0x800A7868 jr ra */
}

void g0_800A77D0(void) {
    { psx_next = R[31]; return; }  /* 0x800A77D0 jr ra */
    R[3] = lw_(R[4] + 32);  /* 0x800A77D8 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[3] + R[0]; if (_c) { goto L_800A77EC; } }  /* 0x800A77E0 */
    R[2] = R[3] + 7;  /* 0x800A77E8 */
L_800A77EC:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A77EC */
    R[5] = lw_(R[4] + 40);  /* 0x800A77F0 */
    R[2] = R[3] - R[2];  /* 0x800A77F4 */
    sw_(R[4] + 32, R[2]);  /* 0x800A77F8 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[2] = R[5] + R[0]; if (_c) { goto L_800A7808; } }  /* 0x800A77FC */
    R[2] = R[5] + 7;  /* 0x800A7804 */
L_800A7808:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7808 */
    R[2] = R[5] - R[2];  /* 0x800A780C */
    { sw_(R[4] + 40, R[2]); psx_next = R[31]; return; }  /* 0x800A7810 jr ra */
    R[3] = lb_(R[4] + 52);  /* 0x800A7818 */
    { uint32_t _c = (R[3] == R[0]); R[3] = R[3] - 4; if (_c) { goto L_800A7838; } }  /* 0x800A7820 */
    R[2] = lb_(R[4] + 53);  /* 0x800A7828 */
    sb_(R[4] + 52, R[3]);  /* 0x800A782C */
    R[2] = R[2] - 4;  /* 0x800A7830 */
    sb_(R[4] + 53, R[2]);  /* 0x800A7834 */
L_800A7838:;
    { psx_next = R[31]; return; }  /* 0x800A7838 jr ra */
    R[3] = lb_(R[4] + 52);  /* 0x800A7840 */
    { uint32_t _c = (R[3] == R[0]); R[3] = R[3] - 2; if (_c) { goto L_800A7860; } }  /* 0x800A7848 */
    R[2] = lb_(R[4] + 53);  /* 0x800A7850 */
    sb_(R[4] + 52, R[3]);  /* 0x800A7854 */
    R[2] = R[2] - 2;  /* 0x800A7858 */
    sb_(R[4] + 53, R[2]);  /* 0x800A785C */
L_800A7860:;
    { psx_next = R[31]; return; }  /* 0x800A7860 jr ra */
    { psx_next = R[31]; return; }  /* 0x800A7868 jr ra */
}

void g0_800A77D8(void) {
    R[3] = lw_(R[4] + 32);  /* 0x800A77D8 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[3] + R[0]; if (_c) { goto L_800A77EC; } }  /* 0x800A77E0 */
    R[2] = R[3] + 7;  /* 0x800A77E8 */
L_800A77EC:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A77EC */
    R[5] = lw_(R[4] + 40);  /* 0x800A77F0 */
    R[2] = R[3] - R[2];  /* 0x800A77F4 */
    sw_(R[4] + 32, R[2]);  /* 0x800A77F8 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[2] = R[5] + R[0]; if (_c) { goto L_800A7808; } }  /* 0x800A77FC */
    R[2] = R[5] + 7;  /* 0x800A7804 */
L_800A7808:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A7808 */
    R[2] = R[5] - R[2];  /* 0x800A780C */
    { sw_(R[4] + 40, R[2]); psx_next = R[31]; return; }  /* 0x800A7810 jr ra */
    R[3] = lb_(R[4] + 52);  /* 0x800A7818 */
    { uint32_t _c = (R[3] == R[0]); R[3] = R[3] - 4; if (_c) { goto L_800A7838; } }  /* 0x800A7820 */
    R[2] = lb_(R[4] + 53);  /* 0x800A7828 */
    sb_(R[4] + 52, R[3]);  /* 0x800A782C */
    R[2] = R[2] - 4;  /* 0x800A7830 */
    sb_(R[4] + 53, R[2]);  /* 0x800A7834 */
L_800A7838:;
    { psx_next = R[31]; return; }  /* 0x800A7838 jr ra */
    R[3] = lb_(R[4] + 52);  /* 0x800A7840 */
    { uint32_t _c = (R[3] == R[0]); R[3] = R[3] - 2; if (_c) { goto L_800A7860; } }  /* 0x800A7848 */
    R[2] = lb_(R[4] + 53);  /* 0x800A7850 */
    sb_(R[4] + 52, R[3]);  /* 0x800A7854 */
    R[2] = R[2] - 2;  /* 0x800A7858 */
    sb_(R[4] + 53, R[2]);  /* 0x800A785C */
L_800A7860:;
    { psx_next = R[31]; return; }  /* 0x800A7860 jr ra */
    { psx_next = R[31]; return; }  /* 0x800A7868 jr ra */
}

void g0_800A7818(void) {
    R[3] = lb_(R[4] + 52);  /* 0x800A7818 */
    { uint32_t _c = (R[3] == R[0]); R[3] = R[3] - 4; if (_c) { goto L_800A7838; } }  /* 0x800A7820 */
    R[2] = lb_(R[4] + 53);  /* 0x800A7828 */
    sb_(R[4] + 52, R[3]);  /* 0x800A782C */
    R[2] = R[2] - 4;  /* 0x800A7830 */
    sb_(R[4] + 53, R[2]);  /* 0x800A7834 */
L_800A7838:;
    { psx_next = R[31]; return; }  /* 0x800A7838 jr ra */
    R[3] = lb_(R[4] + 52);  /* 0x800A7840 */
    { uint32_t _c = (R[3] == R[0]); R[3] = R[3] - 2; if (_c) { goto L_800A7860; } }  /* 0x800A7848 */
    R[2] = lb_(R[4] + 53);  /* 0x800A7850 */
    sb_(R[4] + 52, R[3]);  /* 0x800A7854 */
    R[2] = R[2] - 2;  /* 0x800A7858 */
    sb_(R[4] + 53, R[2]);  /* 0x800A785C */
L_800A7860:;
    { psx_next = R[31]; return; }  /* 0x800A7860 jr ra */
    { psx_next = R[31]; return; }  /* 0x800A7868 jr ra */
}

void g0_800A7840(void) {
    R[3] = lb_(R[4] + 52);  /* 0x800A7840 */
    { uint32_t _c = (R[3] == R[0]); R[3] = R[3] - 2; if (_c) { goto L_800A7860; } }  /* 0x800A7848 */
    R[2] = lb_(R[4] + 53);  /* 0x800A7850 */
    sb_(R[4] + 52, R[3]);  /* 0x800A7854 */
    R[2] = R[2] - 2;  /* 0x800A7858 */
    sb_(R[4] + 53, R[2]);  /* 0x800A785C */
L_800A7860:;
    { psx_next = R[31]; return; }  /* 0x800A7860 jr ra */
    { psx_next = R[31]; return; }  /* 0x800A7868 jr ra */
}

void g0_800A7868(void) {
    { psx_next = R[31]; return; }  /* 0x800A7868 jr ra */
}

void g0_800A7870(void) {
    R[7] = R[4] + R[0];  /* 0x800A7870 */
    R[9] = R[5] + R[0];  /* 0x800A7874 */
    { uint32_t _c = (R[9] == R[0]); R[8] = R[0] + R[0]; if (_c) { psx_next = 0x800A7A3Cu; return; } }  /* 0x800A7878 b extern */
    R[6] = R[4] + 2;  /* 0x800A7880 */
    R[2] = lb_(R[6]);  /* 0x800A7884 */
    R[2] = R[2] & 0x1;  /* 0x800A788C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x800A7A2Cu; return; } }  /* 0x800A7890 b extern */
    R[2] = lb_(R[6] + 1);  /* 0x800A7898 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[2] - 1; if (_c) { psx_next = 0x800A7A24u; return; } }  /* 0x800A78A0 b extern */
    sb_(R[6] + 1, R[2]);  /* 0x800A78A8 */
    R[2] = R[2] & 0xFF;  /* 0x800A78AC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x800A7A24u; return; } }  /* 0x800A78B0 b extern */
    psx_next = 0x800A78B8u; return;  /* fallthrough */
}

void g0_800A7884(void) {
    R[2] = lb_(R[6]);  /* 0x800A7884 */
    R[2] = R[2] & 0x1;  /* 0x800A788C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x800A7A2Cu; return; } }  /* 0x800A7890 b extern */
    R[2] = lb_(R[6] + 1);  /* 0x800A7898 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[2] - 1; if (_c) { psx_next = 0x800A7A24u; return; } }  /* 0x800A78A0 b extern */
    sb_(R[6] + 1, R[2]);  /* 0x800A78A8 */
    R[2] = R[2] & 0xFF;  /* 0x800A78AC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x800A7A24u; return; } }  /* 0x800A78B0 b extern */
    psx_next = 0x800A78B8u; return;  /* fallthrough */
}

void g0_800A78B8(void) {
    R[2] = lb_(R[6]);  /* 0x800A78B8 */
    R[2] = R[2] & 0x80;  /* 0x800A78C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800A79F0; } }  /* 0x800A78C4 */
    R[2] = lb_(R[6] + 56);  /* 0x800A78CC */
    R[2] = R[2] - 1;  /* 0x800A78D4 */
    sb_(R[6] + 56, R[2]);  /* 0x800A78D8 */
    R[2] = R[2] & 0xFF;  /* 0x800A78DC */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800A79F0; } }  /* 0x800A78E0 */
    R[2] = lw_(R[6] + 58);  /* 0x800A78E8 */
    R[3] = lb_(R[6] + 57);  /* 0x800A78EC */
    R[2] = lb_(R[2] + 20);  /* 0x800A78F0 */
    R[3] = R[3] - 1;  /* 0x800A78F4 */
    sb_(R[6] + 57, R[3]);  /* 0x800A78F8 */
    R[3] = R[3] & 0xFF;  /* 0x800A78FC */
    { uint32_t _c = (R[3] != R[0]); sb_(R[6] + 56, R[2]); if (_c) { goto L_800A797C; } }  /* 0x800A7900 */
    R[3] = lb_(R[6]);  /* 0x800A7908 */
    R[2] = R[3] & 0x40;  /* 0x800A7910 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x7F; if (_c) { goto L_800A7974; } }  /* 0x800A7914 */
    R[2] = lh_(R[7]);  /* 0x800A791C */
    R[2] = R[2] & 0x20;  /* 0x800A7924 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800A7950; } }  /* 0x800A7928 */
    R[3] = lw_(R[6] + 58);  /* 0x800A7930 */
    R[4] = lb_(R[6] + 67);  /* 0x800A7934 */
    R[2] = lb_(R[6] + 66);  /* 0x800A7938 */
    R[3] = lb_(R[3] + 14);  /* 0x800A793C */
    sb_(R[6] + 47, R[4]);  /* 0x800A7940 */
    R[2] = R[2] + R[3];  /* 0x800A7944 */
    { sb_(R[6] + 46, R[2]); goto L_800A7960; }  /* 0x800A7948 j */
L_800A7950:;
    R[2] = lb_(R[6] + 66);  /* 0x800A7950 */
    R[3] = lb_(R[6] + 67);  /* 0x800A7954 */
    sb_(R[6] + 46, R[2]);  /* 0x800A7958 */
    sb_(R[6] + 47, R[3]);  /* 0x800A795C */
L_800A7960:;
    R[2] = lw_(R[6] + 58);  /* 0x800A7960 */
    R[2] = lb_(R[2] + 21);  /* 0x800A7968 */
    { sb_(R[6] + 57, R[2]); goto L_800A79F0; }  /* 0x800A796C j */
L_800A7974:;
    { sb_(R[6], R[2]); goto L_800A79F0; }  /* 0x800A7974 j */
L_800A797C:;
    R[5] = lw_(R[6] + 58);  /* 0x800A797C */
    R[2] = lb_(R[5] + 14);  /* 0x800A7984 */
    R[3] = lb_(R[6] + 46);  /* 0x800A7988 */
    R[2] = R[2] + 1;  /* 0x800A798C */
    R[3] = R[3] + R[2];  /* 0x800A7990 */
    R[2] = (uint32_t)(int16_t)lh_(R[6] + 68);  /* 0x800A7994 */
    R[4] = R[3] + R[0];  /* 0x800A7998 */
    R[3] = ((int32_t)R[3] < (int32_t)R[2]);  /* 0x800A799C */
    { uint32_t _c = (R[3] != R[0]); if (_c) { goto L_800A79C0; } }  /* 0x800A79A0 */
    R[4] = lb_(R[6] + 66);  /* 0x800A79A8 */
    R[2] = lb_(R[6] + 47);  /* 0x800A79AC */
    R[3] = lb_(R[5] + 15);  /* 0x800A79B0 */
    R[2] = R[2] + 1;  /* 0x800A79B4 */
    R[3] = R[3] + R[2];  /* 0x800A79B8 */
    sb_(R[6] + 47, R[3]);  /* 0x800A79BC */
L_800A79C0:;
    sb_(R[6] + 46, R[4]);  /* 0x800A79C0 */
    R[2] = lh_(R[7]);  /* 0x800A79C4 */
    R[2] = R[2] & 0x20;  /* 0x800A79CC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[4] & 0xFF; if (_c) { goto L_800A79F0; } }  /* 0x800A79D0 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800A79F0; } }  /* 0x800A79D8 */
    R[2] = lb_(R[6] + 68);  /* 0x800A79E0 */
    R[2] = R[2] - 1;  /* 0x800A79E8 */
    sb_(R[6] + 46, R[2]);  /* 0x800A79EC */
L_800A79F0:;
    R[2] = lw_(R[6] + 6);  /* 0x800A79F0 */
    R[3] = lw_(R[6] + 30);  /* 0x800A79F4 */
    R[4] = lw_(R[6] + 34);  /* 0x800A79F8 */
    R[5] = lw_(R[6] + 38);  /* 0x800A79FC */
    R[2] = R[2] + R[3];  /* 0x800A7A00 */
    sw_(R[6] + 6, R[2]);  /* 0x800A7A04 */
    R[2] = lw_(R[6] + 10);  /* 0x800A7A08 */
    R[3] = lw_(R[6] + 14);  /* 0x800A7A0C */
    R[2] = R[2] + R[4];  /* 0x800A7A10 */
    R[3] = R[3] + R[5];  /* 0x800A7A14 */
    sw_(R[6] + 10, R[2]);  /* 0x800A7A18 */
    { sw_(R[6] + 14, R[3]); goto L_800A7A2C; }  /* 0x800A7A1C j */
    sh_(R[7], R[0]);  /* 0x800A7A24 */
    sb_(R[6], R[0]);  /* 0x800A7A28 */
L_800A7A2C:;
    R[8] = R[8] + 1;  /* 0x800A7A2C */
    R[6] = R[6] + 72;  /* 0x800A7A30 */
    { uint32_t _c = (R[8] != R[9]); R[7] = R[7] + 72; if (_c) { psx_next = 0x800A7884u; return; } }  /* 0x800A7A34 b extern */
    { psx_next = R[31]; return; }  /* 0x800A7A3C jr ra */
}

void g0_800A7A24(void) {
    sh_(R[7], R[0]);  /* 0x800A7A24 */
    sb_(R[6], R[0]);  /* 0x800A7A28 */
    R[8] = R[8] + 1;  /* 0x800A7A2C */
    R[6] = R[6] + 72;  /* 0x800A7A30 */
    { uint32_t _c = (R[8] != R[9]); R[7] = R[7] + 72; if (_c) { psx_next = 0x800A7884u; return; } }  /* 0x800A7A34 b extern */
    { psx_next = R[31]; return; }  /* 0x800A7A3C jr ra */
}

void g0_800A7A2C(void) {
    R[8] = R[8] + 1;  /* 0x800A7A2C */
    R[6] = R[6] + 72;  /* 0x800A7A30 */
    { uint32_t _c = (R[8] != R[9]); R[7] = R[7] + 72; if (_c) { psx_next = 0x800A7884u; return; } }  /* 0x800A7A34 b extern */
    { psx_next = R[31]; return; }  /* 0x800A7A3C jr ra */
}

void g0_800A7A3C(void) {
    { psx_next = R[31]; return; }  /* 0x800A7A3C jr ra */
}

void g0_800A7A44(void) {
    R[29] = R[29] - 40;  /* 0x800A7A44 */
    sw_(R[29] + 24, R[18]);  /* 0x800A7A48 */
    R[18] = R[0] + R[0];  /* 0x800A7A4C */
    R[2] = 0x8014u << 16;  /* 0x800A7A50 */
    sw_(R[29] + 20, R[17]);  /* 0x800A7A54 */
    R[17] = R[2] + 15160;  /* 0x800A7A58 */
    R[2] = 0x800Fu << 16;  /* 0x800A7A5C */
    sw_(R[29] + 32, R[20]);  /* 0x800A7A60 */
    R[20] = R[2] - 13660;  /* 0x800A7A64 */
    sw_(R[29] + 28, R[19]);  /* 0x800A7A68 */
    R[19] = R[0] + 64;  /* 0x800A7A6C */
    sw_(R[29] + 16, R[16]);  /* 0x800A7A70 */
    R[16] = R[17] + 56;  /* 0x800A7A74 */
    sw_(R[29] + 36, R[31]);  /* 0x800A7A78 */
L_800A7A7C:;
    R[2] = lb_(R[16] + -54);  /* 0x800A7A7C */
    R[2] = R[2] & 0x1;  /* 0x800A7A84 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800A7AB8; } }  /* 0x800A7A88 */
    R[2] = (uint32_t)(int16_t)lh_(R[16]);  /* 0x800A7A90 */
    R[2] = R[2] << 2;  /* 0x800A7A98 */
    R[2] = R[2] + R[20];  /* 0x800A7A9C */
    R[2] = lw_(R[2]);  /* 0x800A7AA0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800A7AB8; } }  /* 0x800A7AA8 */
    { uint32_t _t = R[2]; R[31] = 0x800A7AB8u; R[4] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800A7AB0 jalr */
L_800A7AB8:;
    R[18] = R[18] + 1;  /* 0x800A7AB8 */
    R[16] = R[16] + 72;  /* 0x800A7ABC */
    { uint32_t _c = (R[18] != R[19]); R[17] = R[17] + 72; if (_c) { psx_bb(); goto L_800A7A7C; } }  /* 0x800A7AC0 */
    R[31] = lw_(R[29] + 36);  /* 0x800A7AC8 */
    R[20] = lw_(R[29] + 32);  /* 0x800A7ACC */
    R[19] = lw_(R[29] + 28);  /* 0x800A7AD0 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7AD4 */
    R[17] = lw_(R[29] + 20);  /* 0x800A7AD8 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7ADC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7AE0 jr ra */
}

void g0_800A7A7C(void) {
L_800A7A7C:;
    R[2] = lb_(R[16] + -54);  /* 0x800A7A7C */
    R[2] = R[2] & 0x1;  /* 0x800A7A84 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800A7AB8; } }  /* 0x800A7A88 */
    R[2] = (uint32_t)(int16_t)lh_(R[16]);  /* 0x800A7A90 */
    R[2] = R[2] << 2;  /* 0x800A7A98 */
    R[2] = R[2] + R[20];  /* 0x800A7A9C */
    R[2] = lw_(R[2]);  /* 0x800A7AA0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800A7AB8; } }  /* 0x800A7AA8 */
    { uint32_t _t = R[2]; R[31] = 0x800A7AB8u; R[4] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800A7AB0 jalr */
L_800A7AB8:;
    R[18] = R[18] + 1;  /* 0x800A7AB8 */
    R[16] = R[16] + 72;  /* 0x800A7ABC */
    { uint32_t _c = (R[18] != R[19]); R[17] = R[17] + 72; if (_c) { psx_bb(); goto L_800A7A7C; } }  /* 0x800A7AC0 */
    R[31] = lw_(R[29] + 36);  /* 0x800A7AC8 */
    R[20] = lw_(R[29] + 32);  /* 0x800A7ACC */
    R[19] = lw_(R[29] + 28);  /* 0x800A7AD0 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7AD4 */
    R[17] = lw_(R[29] + 20);  /* 0x800A7AD8 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7ADC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7AE0 jr ra */
}

void g0_800A7AB8(void) {
    R[18] = R[18] + 1;  /* 0x800A7AB8 */
    R[16] = R[16] + 72;  /* 0x800A7ABC */
    { uint32_t _c = (R[18] != R[19]); R[17] = R[17] + 72; if (_c) { psx_next = 0x800A7A7Cu; return; } }  /* 0x800A7AC0 b extern */
    R[31] = lw_(R[29] + 36);  /* 0x800A7AC8 */
    R[20] = lw_(R[29] + 32);  /* 0x800A7ACC */
    R[19] = lw_(R[29] + 28);  /* 0x800A7AD0 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7AD4 */
    R[17] = lw_(R[29] + 20);  /* 0x800A7AD8 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7ADC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7AE0 jr ra */
}

void g0_800A7AE8(void) {
    R[2] = 0x8013u << 16;  /* 0x800A7AE8 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + -29604);  /* 0x800A7AEC */
    psx_next = 0x800A7AF0u; return;  /* fallthrough */
}

void g0_800A7AF0(void) {
    R[29] = R[29] - 40;  /* 0x800A7AF0 */
    sw_(R[29] + 36, R[31]);  /* 0x800A7AF4 */
    sw_(R[29] + 32, R[20]);  /* 0x800A7AF8 */
    sw_(R[29] + 28, R[19]);  /* 0x800A7AFC */
    sw_(R[29] + 24, R[18]);  /* 0x800A7B00 */
    sw_(R[29] + 20, R[17]);  /* 0x800A7B04 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[29] + 16, R[16]); if (_c) { goto L_800A7B20; } }  /* 0x800A7B08 */
    R[4] = 0x8014u << 16;  /* 0x800A7B10 */
    R[4] = R[4] + 15160;  /* 0x800A7B14 */
    { R[31] = 0x800A7B20u; R[5] = R[0] + 64; psx_next = 0x800A7870u; return; }  /* 0x800A7B18 jal */
L_800A7B20:;
    R[2] = 0x800Fu << 16;  /* 0x800A7B20 */
    R[2] = lw_(R[2] + 25120);  /* 0x800A7B24 */
    R[2] = R[2] & 0x8;  /* 0x800A7B2C */
    { uint32_t _c = (R[2] != R[0]); R[19] = R[0] + R[0]; if (_c) { goto L_800A7CB0; } }  /* 0x800A7B30 */
    R[2] = 0x8013u << 16;  /* 0x800A7B38 */
    R[17] = R[2] - 28480;  /* 0x800A7B3C */
    R[2] = 0x800Fu << 16;  /* 0x800A7B40 */
    R[20] = R[2] - 13660;  /* 0x800A7B44 */
    R[2] = 0x800Fu << 16;  /* 0x800A7B48 */
    R[18] = R[2] + 2304;  /* 0x800A7B4C */
    R[16] = R[17] + 56;  /* 0x800A7B50 */
L_800A7B54:;
    R[2] = lb_(R[16] + -54);  /* 0x800A7B54 */
    R[2] = R[2] & 0x1;  /* 0x800A7B5C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800A7BA8; } }  /* 0x800A7B60 */
    R[3] = (uint32_t)(int16_t)lh_(R[16]);  /* 0x800A7B68 */
    R[2] = ((int32_t)R[3] < 100);  /* 0x800A7B70 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] << 2; if (_c) { goto L_800A7B84; } }  /* 0x800A7B74 */
    { R[2] = R[2] + R[20]; goto L_800A7B90; }  /* 0x800A7B7C j */
L_800A7B84:;
    R[2] = R[3] - 100;  /* 0x800A7B84 */
    R[2] = R[2] << 2;  /* 0x800A7B88 */
    R[2] = R[2] + R[18];  /* 0x800A7B8C */
L_800A7B90:;
    R[2] = lw_(R[2]);  /* 0x800A7B90 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800A7BA8; } }  /* 0x800A7B98 */
    { uint32_t _t = R[2]; R[31] = 0x800A7BA8u; R[4] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800A7BA0 jalr */
L_800A7BA8:;
    R[19] = R[19] + 1;  /* 0x800A7BA8 */
    R[16] = R[16] + 72;  /* 0x800A7BAC */
    R[2] = R[0] + 64;  /* 0x800A7BB0 */
    { uint32_t _c = (R[19] != R[2]); R[17] = R[17] + 72; if (_c) { psx_bb(); goto L_800A7B54; } }  /* 0x800A7BB4 */
    R[2] = 0x800Fu << 16;  /* 0x800A7BBC */
    R[2] = lw_(R[2] + 25168);  /* 0x800A7BC0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_800A7CB0; } }  /* 0x800A7BC8 */
    R[4] = R[4] - 28480;  /* 0x800A7BD0 */
    { R[31] = 0x800A7BDCu; R[5] = R[0] + 64; psx_next = 0x800A7870u; return; }  /* 0x800A7BD4 jal */
    R[19] = R[0] + R[0];  /* 0x800A7BDC */
    R[2] = 0x8012u << 16;  /* 0x800A7BE0 */
    R[18] = R[2] - 26864;  /* 0x800A7BE4 */
    R[17] = R[18] + 791;  /* 0x800A7BE8 */
    R[2] = 0x8013u << 16;  /* 0x800A7BEC */
    R[16] = R[2] - 23304;  /* 0x800A7BF0 */
L_800A7BF4:;
    R[2] = (uint32_t)(int16_t)lh_(R[18]);  /* 0x800A7BF4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800A7C4C; } }  /* 0x800A7BFC */
    R[3] = lb_(R[17] + -2);  /* 0x800A7C04 */
    R[2] = R[3] & 0x1;  /* 0x800A7C0C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { goto L_800A7C4C; } }  /* 0x800A7C10 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800A7C4C; } }  /* 0x800A7C18 */
    R[3] = lb_(R[17]);  /* 0x800A7C20 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_800A7C4C; } }  /* 0x800A7C28 */
    R[2] = lb_(R[16] + 2);  /* 0x800A7C30 */
    R[2] = R[2] & 0x1;  /* 0x800A7C38 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_800A7C4C; } }  /* 0x800A7C3C */
    { R[31] = 0x800A7C4Cu; R[5] = R[0] + 1; psx_next = 0x800A7870u; return; }  /* 0x800A7C44 jal */
L_800A7C4C:;
    R[16] = R[16] + 72;  /* 0x800A7C4C */
    R[19] = R[19] + 1;  /* 0x800A7C50 */
    R[17] = R[17] + 804;  /* 0x800A7C54 */
    R[2] = R[0] + 60;  /* 0x800A7C58 */
    { uint32_t _c = (R[19] != R[2]); R[18] = R[18] + 804; if (_c) { psx_bb(); goto L_800A7BF4; } }  /* 0x800A7C5C */
    R[2] = 0x8012u << 16;  /* 0x800A7C64 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + -26864);  /* 0x800A7C68 */
    { uint32_t _c = (R[3] == R[0]); R[4] = R[2] - 26864; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C70 */
    R[3] = lb_(R[4] + 789);  /* 0x800A7C78 */
    R[2] = R[3] & 0x1;  /* 0x800A7C80 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C84 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C8C */
    R[3] = lb_(R[4] + 791);  /* 0x800A7C94 */
    { uint32_t _c = (R[3] == R[2]); R[4] = 0x8014u << 16; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C9C */
    R[4] = R[4] + 15160;  /* 0x800A7CA4 */
    { R[31] = 0x800A7CB0u; R[5] = R[0] + 64; psx_next = 0x800A7870u; return; }  /* 0x800A7CA8 jal */
L_800A7CB0:;
    R[31] = lw_(R[29] + 36);  /* 0x800A7CB0 */
    R[20] = lw_(R[29] + 32);  /* 0x800A7CB4 */
    R[19] = lw_(R[29] + 28);  /* 0x800A7CB8 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7CBC */
    R[17] = lw_(R[29] + 20);  /* 0x800A7CC0 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7CC4 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7CC8 jr ra */
}

void g0_800A7B20(void) {
    R[2] = 0x800Fu << 16;  /* 0x800A7B20 */
    R[2] = lw_(R[2] + 25120);  /* 0x800A7B24 */
    R[2] = R[2] & 0x8;  /* 0x800A7B2C */
    { uint32_t _c = (R[2] != R[0]); R[19] = R[0] + R[0]; if (_c) { goto L_800A7CB0; } }  /* 0x800A7B30 */
    R[2] = 0x8013u << 16;  /* 0x800A7B38 */
    R[17] = R[2] - 28480;  /* 0x800A7B3C */
    R[2] = 0x800Fu << 16;  /* 0x800A7B40 */
    R[20] = R[2] - 13660;  /* 0x800A7B44 */
    R[2] = 0x800Fu << 16;  /* 0x800A7B48 */
    R[18] = R[2] + 2304;  /* 0x800A7B4C */
    R[16] = R[17] + 56;  /* 0x800A7B50 */
L_800A7B54:;
    R[2] = lb_(R[16] + -54);  /* 0x800A7B54 */
    R[2] = R[2] & 0x1;  /* 0x800A7B5C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800A7BA8; } }  /* 0x800A7B60 */
    R[3] = (uint32_t)(int16_t)lh_(R[16]);  /* 0x800A7B68 */
    R[2] = ((int32_t)R[3] < 100);  /* 0x800A7B70 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] << 2; if (_c) { goto L_800A7B84; } }  /* 0x800A7B74 */
    { R[2] = R[2] + R[20]; goto L_800A7B90; }  /* 0x800A7B7C j */
L_800A7B84:;
    R[2] = R[3] - 100;  /* 0x800A7B84 */
    R[2] = R[2] << 2;  /* 0x800A7B88 */
    R[2] = R[2] + R[18];  /* 0x800A7B8C */
L_800A7B90:;
    R[2] = lw_(R[2]);  /* 0x800A7B90 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800A7BA8; } }  /* 0x800A7B98 */
    { uint32_t _t = R[2]; R[31] = 0x800A7BA8u; R[4] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800A7BA0 jalr */
L_800A7BA8:;
    R[19] = R[19] + 1;  /* 0x800A7BA8 */
    R[16] = R[16] + 72;  /* 0x800A7BAC */
    R[2] = R[0] + 64;  /* 0x800A7BB0 */
    { uint32_t _c = (R[19] != R[2]); R[17] = R[17] + 72; if (_c) { psx_bb(); goto L_800A7B54; } }  /* 0x800A7BB4 */
    R[2] = 0x800Fu << 16;  /* 0x800A7BBC */
    R[2] = lw_(R[2] + 25168);  /* 0x800A7BC0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_800A7CB0; } }  /* 0x800A7BC8 */
    R[4] = R[4] - 28480;  /* 0x800A7BD0 */
    { R[31] = 0x800A7BDCu; R[5] = R[0] + 64; psx_next = 0x800A7870u; return; }  /* 0x800A7BD4 jal */
    R[19] = R[0] + R[0];  /* 0x800A7BDC */
    R[2] = 0x8012u << 16;  /* 0x800A7BE0 */
    R[18] = R[2] - 26864;  /* 0x800A7BE4 */
    R[17] = R[18] + 791;  /* 0x800A7BE8 */
    R[2] = 0x8013u << 16;  /* 0x800A7BEC */
    R[16] = R[2] - 23304;  /* 0x800A7BF0 */
L_800A7BF4:;
    R[2] = (uint32_t)(int16_t)lh_(R[18]);  /* 0x800A7BF4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800A7C4C; } }  /* 0x800A7BFC */
    R[3] = lb_(R[17] + -2);  /* 0x800A7C04 */
    R[2] = R[3] & 0x1;  /* 0x800A7C0C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { goto L_800A7C4C; } }  /* 0x800A7C10 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800A7C4C; } }  /* 0x800A7C18 */
    R[3] = lb_(R[17]);  /* 0x800A7C20 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_800A7C4C; } }  /* 0x800A7C28 */
    R[2] = lb_(R[16] + 2);  /* 0x800A7C30 */
    R[2] = R[2] & 0x1;  /* 0x800A7C38 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_800A7C4C; } }  /* 0x800A7C3C */
    { R[31] = 0x800A7C4Cu; R[5] = R[0] + 1; psx_next = 0x800A7870u; return; }  /* 0x800A7C44 jal */
L_800A7C4C:;
    R[16] = R[16] + 72;  /* 0x800A7C4C */
    R[19] = R[19] + 1;  /* 0x800A7C50 */
    R[17] = R[17] + 804;  /* 0x800A7C54 */
    R[2] = R[0] + 60;  /* 0x800A7C58 */
    { uint32_t _c = (R[19] != R[2]); R[18] = R[18] + 804; if (_c) { psx_bb(); goto L_800A7BF4; } }  /* 0x800A7C5C */
    R[2] = 0x8012u << 16;  /* 0x800A7C64 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + -26864);  /* 0x800A7C68 */
    { uint32_t _c = (R[3] == R[0]); R[4] = R[2] - 26864; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C70 */
    R[3] = lb_(R[4] + 789);  /* 0x800A7C78 */
    R[2] = R[3] & 0x1;  /* 0x800A7C80 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C84 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C8C */
    R[3] = lb_(R[4] + 791);  /* 0x800A7C94 */
    { uint32_t _c = (R[3] == R[2]); R[4] = 0x8014u << 16; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C9C */
    R[4] = R[4] + 15160;  /* 0x800A7CA4 */
    { R[31] = 0x800A7CB0u; R[5] = R[0] + 64; psx_next = 0x800A7870u; return; }  /* 0x800A7CA8 jal */
L_800A7CB0:;
    R[31] = lw_(R[29] + 36);  /* 0x800A7CB0 */
    R[20] = lw_(R[29] + 32);  /* 0x800A7CB4 */
    R[19] = lw_(R[29] + 28);  /* 0x800A7CB8 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7CBC */
    R[17] = lw_(R[29] + 20);  /* 0x800A7CC0 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7CC4 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7CC8 jr ra */
}

void g0_800A7B54(void) {
L_800A7B54:;
    R[2] = lb_(R[16] + -54);  /* 0x800A7B54 */
    R[2] = R[2] & 0x1;  /* 0x800A7B5C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800A7BA8; } }  /* 0x800A7B60 */
    R[3] = (uint32_t)(int16_t)lh_(R[16]);  /* 0x800A7B68 */
    R[2] = ((int32_t)R[3] < 100);  /* 0x800A7B70 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] << 2; if (_c) { goto L_800A7B84; } }  /* 0x800A7B74 */
    { R[2] = R[2] + R[20]; goto L_800A7B90; }  /* 0x800A7B7C j */
L_800A7B84:;
    R[2] = R[3] - 100;  /* 0x800A7B84 */
    R[2] = R[2] << 2;  /* 0x800A7B88 */
    R[2] = R[2] + R[18];  /* 0x800A7B8C */
L_800A7B90:;
    R[2] = lw_(R[2]);  /* 0x800A7B90 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800A7BA8; } }  /* 0x800A7B98 */
    { uint32_t _t = R[2]; R[31] = 0x800A7BA8u; R[4] = R[17] + R[0]; psx_next = _t; return; }  /* 0x800A7BA0 jalr */
L_800A7BA8:;
    R[19] = R[19] + 1;  /* 0x800A7BA8 */
    R[16] = R[16] + 72;  /* 0x800A7BAC */
    R[2] = R[0] + 64;  /* 0x800A7BB0 */
    { uint32_t _c = (R[19] != R[2]); R[17] = R[17] + 72; if (_c) { psx_bb(); goto L_800A7B54; } }  /* 0x800A7BB4 */
    R[2] = 0x800Fu << 16;  /* 0x800A7BBC */
    R[2] = lw_(R[2] + 25168);  /* 0x800A7BC0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_800A7CB0; } }  /* 0x800A7BC8 */
    R[4] = R[4] - 28480;  /* 0x800A7BD0 */
    { R[31] = 0x800A7BDCu; R[5] = R[0] + 64; psx_next = 0x800A7870u; return; }  /* 0x800A7BD4 jal */
    R[19] = R[0] + R[0];  /* 0x800A7BDC */
    R[2] = 0x8012u << 16;  /* 0x800A7BE0 */
    R[18] = R[2] - 26864;  /* 0x800A7BE4 */
    R[17] = R[18] + 791;  /* 0x800A7BE8 */
    R[2] = 0x8013u << 16;  /* 0x800A7BEC */
    R[16] = R[2] - 23304;  /* 0x800A7BF0 */
L_800A7BF4:;
    R[2] = (uint32_t)(int16_t)lh_(R[18]);  /* 0x800A7BF4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800A7C4C; } }  /* 0x800A7BFC */
    R[3] = lb_(R[17] + -2);  /* 0x800A7C04 */
    R[2] = R[3] & 0x1;  /* 0x800A7C0C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { goto L_800A7C4C; } }  /* 0x800A7C10 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800A7C4C; } }  /* 0x800A7C18 */
    R[3] = lb_(R[17]);  /* 0x800A7C20 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_800A7C4C; } }  /* 0x800A7C28 */
    R[2] = lb_(R[16] + 2);  /* 0x800A7C30 */
    R[2] = R[2] & 0x1;  /* 0x800A7C38 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_800A7C4C; } }  /* 0x800A7C3C */
    { R[31] = 0x800A7C4Cu; R[5] = R[0] + 1; psx_next = 0x800A7870u; return; }  /* 0x800A7C44 jal */
L_800A7C4C:;
    R[16] = R[16] + 72;  /* 0x800A7C4C */
    R[19] = R[19] + 1;  /* 0x800A7C50 */
    R[17] = R[17] + 804;  /* 0x800A7C54 */
    R[2] = R[0] + 60;  /* 0x800A7C58 */
    { uint32_t _c = (R[19] != R[2]); R[18] = R[18] + 804; if (_c) { psx_bb(); goto L_800A7BF4; } }  /* 0x800A7C5C */
    R[2] = 0x8012u << 16;  /* 0x800A7C64 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + -26864);  /* 0x800A7C68 */
    { uint32_t _c = (R[3] == R[0]); R[4] = R[2] - 26864; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C70 */
    R[3] = lb_(R[4] + 789);  /* 0x800A7C78 */
    R[2] = R[3] & 0x1;  /* 0x800A7C80 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C84 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C8C */
    R[3] = lb_(R[4] + 791);  /* 0x800A7C94 */
    { uint32_t _c = (R[3] == R[2]); R[4] = 0x8014u << 16; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C9C */
    R[4] = R[4] + 15160;  /* 0x800A7CA4 */
    { R[31] = 0x800A7CB0u; R[5] = R[0] + 64; psx_next = 0x800A7870u; return; }  /* 0x800A7CA8 jal */
L_800A7CB0:;
    R[31] = lw_(R[29] + 36);  /* 0x800A7CB0 */
    R[20] = lw_(R[29] + 32);  /* 0x800A7CB4 */
    R[19] = lw_(R[29] + 28);  /* 0x800A7CB8 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7CBC */
    R[17] = lw_(R[29] + 20);  /* 0x800A7CC0 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7CC4 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7CC8 jr ra */
}

void g0_800A7BA8(void) {
    R[19] = R[19] + 1;  /* 0x800A7BA8 */
    R[16] = R[16] + 72;  /* 0x800A7BAC */
    R[2] = R[0] + 64;  /* 0x800A7BB0 */
    { uint32_t _c = (R[19] != R[2]); R[17] = R[17] + 72; if (_c) { psx_next = 0x800A7B54u; return; } }  /* 0x800A7BB4 b extern */
    R[2] = 0x800Fu << 16;  /* 0x800A7BBC */
    R[2] = lw_(R[2] + 25168);  /* 0x800A7BC0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_800A7CB0; } }  /* 0x800A7BC8 */
    R[4] = R[4] - 28480;  /* 0x800A7BD0 */
    { R[31] = 0x800A7BDCu; R[5] = R[0] + 64; psx_next = 0x800A7870u; return; }  /* 0x800A7BD4 jal */
    R[19] = R[0] + R[0];  /* 0x800A7BDC */
    R[2] = 0x8012u << 16;  /* 0x800A7BE0 */
    R[18] = R[2] - 26864;  /* 0x800A7BE4 */
    R[17] = R[18] + 791;  /* 0x800A7BE8 */
    R[2] = 0x8013u << 16;  /* 0x800A7BEC */
    R[16] = R[2] - 23304;  /* 0x800A7BF0 */
L_800A7BF4:;
    R[2] = (uint32_t)(int16_t)lh_(R[18]);  /* 0x800A7BF4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800A7C4C; } }  /* 0x800A7BFC */
    R[3] = lb_(R[17] + -2);  /* 0x800A7C04 */
    R[2] = R[3] & 0x1;  /* 0x800A7C0C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { goto L_800A7C4C; } }  /* 0x800A7C10 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800A7C4C; } }  /* 0x800A7C18 */
    R[3] = lb_(R[17]);  /* 0x800A7C20 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_800A7C4C; } }  /* 0x800A7C28 */
    R[2] = lb_(R[16] + 2);  /* 0x800A7C30 */
    R[2] = R[2] & 0x1;  /* 0x800A7C38 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_800A7C4C; } }  /* 0x800A7C3C */
    { R[31] = 0x800A7C4Cu; R[5] = R[0] + 1; psx_next = 0x800A7870u; return; }  /* 0x800A7C44 jal */
L_800A7C4C:;
    R[16] = R[16] + 72;  /* 0x800A7C4C */
    R[19] = R[19] + 1;  /* 0x800A7C50 */
    R[17] = R[17] + 804;  /* 0x800A7C54 */
    R[2] = R[0] + 60;  /* 0x800A7C58 */
    { uint32_t _c = (R[19] != R[2]); R[18] = R[18] + 804; if (_c) { psx_bb(); goto L_800A7BF4; } }  /* 0x800A7C5C */
    R[2] = 0x8012u << 16;  /* 0x800A7C64 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + -26864);  /* 0x800A7C68 */
    { uint32_t _c = (R[3] == R[0]); R[4] = R[2] - 26864; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C70 */
    R[3] = lb_(R[4] + 789);  /* 0x800A7C78 */
    R[2] = R[3] & 0x1;  /* 0x800A7C80 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C84 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C8C */
    R[3] = lb_(R[4] + 791);  /* 0x800A7C94 */
    { uint32_t _c = (R[3] == R[2]); R[4] = 0x8014u << 16; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C9C */
    R[4] = R[4] + 15160;  /* 0x800A7CA4 */
    { R[31] = 0x800A7CB0u; R[5] = R[0] + 64; psx_next = 0x800A7870u; return; }  /* 0x800A7CA8 jal */
L_800A7CB0:;
    R[31] = lw_(R[29] + 36);  /* 0x800A7CB0 */
    R[20] = lw_(R[29] + 32);  /* 0x800A7CB4 */
    R[19] = lw_(R[29] + 28);  /* 0x800A7CB8 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7CBC */
    R[17] = lw_(R[29] + 20);  /* 0x800A7CC0 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7CC4 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7CC8 jr ra */
}

void g0_800A7BDC(void) {
    R[19] = R[0] + R[0];  /* 0x800A7BDC */
    R[2] = 0x8012u << 16;  /* 0x800A7BE0 */
    R[18] = R[2] - 26864;  /* 0x800A7BE4 */
    R[17] = R[18] + 791;  /* 0x800A7BE8 */
    R[2] = 0x8013u << 16;  /* 0x800A7BEC */
    R[16] = R[2] - 23304;  /* 0x800A7BF0 */
L_800A7BF4:;
    R[2] = (uint32_t)(int16_t)lh_(R[18]);  /* 0x800A7BF4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800A7C4C; } }  /* 0x800A7BFC */
    R[3] = lb_(R[17] + -2);  /* 0x800A7C04 */
    R[2] = R[3] & 0x1;  /* 0x800A7C0C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { goto L_800A7C4C; } }  /* 0x800A7C10 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800A7C4C; } }  /* 0x800A7C18 */
    R[3] = lb_(R[17]);  /* 0x800A7C20 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_800A7C4C; } }  /* 0x800A7C28 */
    R[2] = lb_(R[16] + 2);  /* 0x800A7C30 */
    R[2] = R[2] & 0x1;  /* 0x800A7C38 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_800A7C4C; } }  /* 0x800A7C3C */
    { R[31] = 0x800A7C4Cu; R[5] = R[0] + 1; psx_next = 0x800A7870u; return; }  /* 0x800A7C44 jal */
L_800A7C4C:;
    R[16] = R[16] + 72;  /* 0x800A7C4C */
    R[19] = R[19] + 1;  /* 0x800A7C50 */
    R[17] = R[17] + 804;  /* 0x800A7C54 */
    R[2] = R[0] + 60;  /* 0x800A7C58 */
    { uint32_t _c = (R[19] != R[2]); R[18] = R[18] + 804; if (_c) { psx_bb(); goto L_800A7BF4; } }  /* 0x800A7C5C */
    R[2] = 0x8012u << 16;  /* 0x800A7C64 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + -26864);  /* 0x800A7C68 */
    { uint32_t _c = (R[3] == R[0]); R[4] = R[2] - 26864; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C70 */
    R[3] = lb_(R[4] + 789);  /* 0x800A7C78 */
    R[2] = R[3] & 0x1;  /* 0x800A7C80 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C84 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C8C */
    R[3] = lb_(R[4] + 791);  /* 0x800A7C94 */
    { uint32_t _c = (R[3] == R[2]); R[4] = 0x8014u << 16; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C9C */
    R[4] = R[4] + 15160;  /* 0x800A7CA4 */
    { R[31] = 0x800A7CB0u; R[5] = R[0] + 64; psx_next = 0x800A7870u; return; }  /* 0x800A7CA8 jal */
L_800A7CB0:;
    R[31] = lw_(R[29] + 36);  /* 0x800A7CB0 */
    R[20] = lw_(R[29] + 32);  /* 0x800A7CB4 */
    R[19] = lw_(R[29] + 28);  /* 0x800A7CB8 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7CBC */
    R[17] = lw_(R[29] + 20);  /* 0x800A7CC0 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7CC4 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7CC8 jr ra */
}

void g0_800A7BF4(void) {
L_800A7BF4:;
    R[2] = (uint32_t)(int16_t)lh_(R[18]);  /* 0x800A7BF4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800A7C4C; } }  /* 0x800A7BFC */
    R[3] = lb_(R[17] + -2);  /* 0x800A7C04 */
    R[2] = R[3] & 0x1;  /* 0x800A7C0C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { goto L_800A7C4C; } }  /* 0x800A7C10 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800A7C4C; } }  /* 0x800A7C18 */
    R[3] = lb_(R[17]);  /* 0x800A7C20 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_800A7C4C; } }  /* 0x800A7C28 */
    R[2] = lb_(R[16] + 2);  /* 0x800A7C30 */
    R[2] = R[2] & 0x1;  /* 0x800A7C38 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_800A7C4C; } }  /* 0x800A7C3C */
    { R[31] = 0x800A7C4Cu; R[5] = R[0] + 1; psx_next = 0x800A7870u; return; }  /* 0x800A7C44 jal */
L_800A7C4C:;
    R[16] = R[16] + 72;  /* 0x800A7C4C */
    R[19] = R[19] + 1;  /* 0x800A7C50 */
    R[17] = R[17] + 804;  /* 0x800A7C54 */
    R[2] = R[0] + 60;  /* 0x800A7C58 */
    { uint32_t _c = (R[19] != R[2]); R[18] = R[18] + 804; if (_c) { psx_bb(); goto L_800A7BF4; } }  /* 0x800A7C5C */
    R[2] = 0x8012u << 16;  /* 0x800A7C64 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + -26864);  /* 0x800A7C68 */
    { uint32_t _c = (R[3] == R[0]); R[4] = R[2] - 26864; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C70 */
    R[3] = lb_(R[4] + 789);  /* 0x800A7C78 */
    R[2] = R[3] & 0x1;  /* 0x800A7C80 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C84 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C8C */
    R[3] = lb_(R[4] + 791);  /* 0x800A7C94 */
    { uint32_t _c = (R[3] == R[2]); R[4] = 0x8014u << 16; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C9C */
    R[4] = R[4] + 15160;  /* 0x800A7CA4 */
    { R[31] = 0x800A7CB0u; R[5] = R[0] + 64; psx_next = 0x800A7870u; return; }  /* 0x800A7CA8 jal */
L_800A7CB0:;
    R[31] = lw_(R[29] + 36);  /* 0x800A7CB0 */
    R[20] = lw_(R[29] + 32);  /* 0x800A7CB4 */
    R[19] = lw_(R[29] + 28);  /* 0x800A7CB8 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7CBC */
    R[17] = lw_(R[29] + 20);  /* 0x800A7CC0 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7CC4 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7CC8 jr ra */
}

void g0_800A7C4C(void) {
    R[16] = R[16] + 72;  /* 0x800A7C4C */
    R[19] = R[19] + 1;  /* 0x800A7C50 */
    R[17] = R[17] + 804;  /* 0x800A7C54 */
    R[2] = R[0] + 60;  /* 0x800A7C58 */
    { uint32_t _c = (R[19] != R[2]); R[18] = R[18] + 804; if (_c) { psx_next = 0x800A7BF4u; return; } }  /* 0x800A7C5C b extern */
    R[2] = 0x8012u << 16;  /* 0x800A7C64 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + -26864);  /* 0x800A7C68 */
    { uint32_t _c = (R[3] == R[0]); R[4] = R[2] - 26864; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C70 */
    R[3] = lb_(R[4] + 789);  /* 0x800A7C78 */
    R[2] = R[3] & 0x1;  /* 0x800A7C80 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C84 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C8C */
    R[3] = lb_(R[4] + 791);  /* 0x800A7C94 */
    { uint32_t _c = (R[3] == R[2]); R[4] = 0x8014u << 16; if (_c) { goto L_800A7CB0; } }  /* 0x800A7C9C */
    R[4] = R[4] + 15160;  /* 0x800A7CA4 */
    { R[31] = 0x800A7CB0u; R[5] = R[0] + 64; psx_next = 0x800A7870u; return; }  /* 0x800A7CA8 jal */
L_800A7CB0:;
    R[31] = lw_(R[29] + 36);  /* 0x800A7CB0 */
    R[20] = lw_(R[29] + 32);  /* 0x800A7CB4 */
    R[19] = lw_(R[29] + 28);  /* 0x800A7CB8 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7CBC */
    R[17] = lw_(R[29] + 20);  /* 0x800A7CC0 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7CC4 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7CC8 jr ra */
}

void g0_800A7CB0(void) {
    R[31] = lw_(R[29] + 36);  /* 0x800A7CB0 */
    R[20] = lw_(R[29] + 32);  /* 0x800A7CB4 */
    R[19] = lw_(R[29] + 28);  /* 0x800A7CB8 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7CBC */
    R[17] = lw_(R[29] + 20);  /* 0x800A7CC0 */
    R[16] = lw_(R[29] + 16);  /* 0x800A7CC4 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7CC8 jr ra */
}

void g0_800A7CD0(void) {
    R[29] = R[29] - 40;  /* 0x800A7CD0 */
    R[3] = 0x8013u << 16;  /* 0x800A7CD4 */
    R[2] = R[0] + 6;  /* 0x800A7CD8 */
    R[4] = R[3] - 23368;  /* 0x800A7CDC */
    sw_(R[3] + -23368, R[2]);  /* 0x800A7CE0 */
    R[2] = 0x8013u << 16;  /* 0x800A7CE4 */
    R[2] = R[2] - 23800;  /* 0x800A7CE8 */
    sw_(R[29] + 36, R[31]);  /* 0x800A7CEC */
    sw_(R[29] + 32, R[20]);  /* 0x800A7CF0 */
    sw_(R[29] + 28, R[19]);  /* 0x800A7CF4 */
    sw_(R[29] + 24, R[18]);  /* 0x800A7CF8 */
    sw_(R[29] + 20, R[17]);  /* 0x800A7CFC */
    sw_(R[29] + 16, R[16]);  /* 0x800A7D00 */
    sw_(R[4] + 4, R[2]);  /* 0x800A7D04 */
    R[2] = R[0] + 60;  /* 0x800A7D08 */
    sw_(R[4] + 8, R[2]);  /* 0x800A7D0C */
    R[2] = 0x8013u << 16;  /* 0x800A7D10 */
    R[2] = R[2] - 23304;  /* 0x800A7D14 */
    R[5] = R[0] + 64;  /* 0x800A7D18 */
    sw_(R[4] + 12, R[2]);  /* 0x800A7D1C */
    R[2] = 0x8013u << 16;  /* 0x800A7D20 */
    R[3] = 0x8013u << 16;  /* 0x800A7D24 */
    sw_(R[4] + 16, R[5]);  /* 0x800A7D28 */
    R[3] = (uint32_t)(int16_t)lh_(R[3] + -29604);  /* 0x800A7D2C */
    R[2] = R[2] - 28480;  /* 0x800A7D30 */
    { uint32_t _c = (R[3] != R[0]); sw_(R[4] + 20, R[2]); if (_c) { goto L_800A7D54; } }  /* 0x800A7D34 */
    R[2] = 0x8014u << 16;  /* 0x800A7D3C */
    R[2] = R[2] + 15160;  /* 0x800A7D40 */
    sw_(R[4] + 24, R[5]);  /* 0x800A7D44 */
    sw_(R[4] + 28, R[2]);  /* 0x800A7D48 */
    { sw_(R[4] + 32, R[0]); goto L_800A7D58; }  /* 0x800A7D4C j */
L_800A7D54:;
    sw_(R[4] + 24, R[0]);  /* 0x800A7D54 */
L_800A7D58:;
    R[2] = 0x800Fu << 16;  /* 0x800A7D58 */
    R[2] = lb_(R[2] + 25118);  /* 0x800A7D5C */
    R[2] = R[2] & 0x2;  /* 0x800A7D64 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A7D74; } }  /* 0x800A7D68 */
    sw_(R[2] + -23368, R[0]);  /* 0x800A7D70 */
L_800A7D74:;
    R[16] = 0x8011u << 16;  /* 0x800A7D74 */
    R[19] = R[16] + 30268;  /* 0x800A7D78 */
    R[4] = R[19] + R[0];  /* 0x800A7D7C */
    R[5] = R[0] + R[0];  /* 0x800A7D80 */
    R[20] = 0x8013u << 16;  /* 0x800A7D84 */
    R[18] = R[20] - 23368;  /* 0x800A7D88 */
    { R[31] = 0x800A7D94u; sw_(R[19] + 20, R[18]); psx_next = 0x80025408u; return; }  /* 0x800A7D8C jal */
    R[2] = 0x8013u << 16;  /* 0x800A7D94 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + -29604);  /* 0x800A7D98 */
    { uint32_t _c = (R[2] == R[0]); sh_(R[16] + 30268, R[0]); if (_c) { goto L_800A7DEC; } }  /* 0x800A7DA0 */
    R[17] = 0x8011u << 16;  /* 0x800A7DA8 */
    R[16] = R[17] + 30440;  /* 0x800A7DAC */
    R[4] = R[16] + R[0];  /* 0x800A7DB0 */
    R[5] = R[0] + R[0];  /* 0x800A7DB4 */
    R[2] = R[0] + 64;  /* 0x800A7DB8 */
    sw_(R[20] + -23368, R[2]);  /* 0x800A7DBC */
    R[2] = 0x8014u << 16;  /* 0x800A7DC0 */
    R[3] = lw_(R[19] + 4);  /* 0x800A7DC4 */
    R[2] = R[2] + 15160;  /* 0x800A7DC8 */
    sw_(R[18] + 4, R[2]);  /* 0x800A7DCC */
    sw_(R[18] + 8, R[0]);  /* 0x800A7DD0 */
    sw_(R[16] + 20, R[18]);  /* 0x800A7DD4 */
    { R[31] = 0x800A7DE0u; sw_(R[16] + 4, R[3]); psx_next = 0x80025408u; return; }  /* 0x800A7DD8 jal */
    R[2] = lw_(R[16] + 4);  /* 0x800A7DE0 */
    sh_(R[17] + 30440, R[0]);  /* 0x800A7DE4 */
    sw_(R[19] + 4, R[2]);  /* 0x800A7DE8 */
L_800A7DEC:;
    R[31] = lw_(R[29] + 36);  /* 0x800A7DEC */
    R[20] = lw_(R[29] + 32);  /* 0x800A7DF0 */
    R[19] = lw_(R[29] + 28);  /* 0x800A7DF4 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7DF8 */
    R[17] = lw_(R[29] + 20);  /* 0x800A7DFC */
    R[16] = lw_(R[29] + 16);  /* 0x800A7E00 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7E04 jr ra */
}

void g0_800A7D94(void) {
    R[2] = 0x8013u << 16;  /* 0x800A7D94 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + -29604);  /* 0x800A7D98 */
    { uint32_t _c = (R[2] == R[0]); sh_(R[16] + 30268, R[0]); if (_c) { goto L_800A7DEC; } }  /* 0x800A7DA0 */
    R[17] = 0x8011u << 16;  /* 0x800A7DA8 */
    R[16] = R[17] + 30440;  /* 0x800A7DAC */
    R[4] = R[16] + R[0];  /* 0x800A7DB0 */
    R[5] = R[0] + R[0];  /* 0x800A7DB4 */
    R[2] = R[0] + 64;  /* 0x800A7DB8 */
    sw_(R[20] + -23368, R[2]);  /* 0x800A7DBC */
    R[2] = 0x8014u << 16;  /* 0x800A7DC0 */
    R[3] = lw_(R[19] + 4);  /* 0x800A7DC4 */
    R[2] = R[2] + 15160;  /* 0x800A7DC8 */
    sw_(R[18] + 4, R[2]);  /* 0x800A7DCC */
    sw_(R[18] + 8, R[0]);  /* 0x800A7DD0 */
    sw_(R[16] + 20, R[18]);  /* 0x800A7DD4 */
    { R[31] = 0x800A7DE0u; sw_(R[16] + 4, R[3]); psx_next = 0x80025408u; return; }  /* 0x800A7DD8 jal */
    R[2] = lw_(R[16] + 4);  /* 0x800A7DE0 */
    sh_(R[17] + 30440, R[0]);  /* 0x800A7DE4 */
    sw_(R[19] + 4, R[2]);  /* 0x800A7DE8 */
L_800A7DEC:;
    R[31] = lw_(R[29] + 36);  /* 0x800A7DEC */
    R[20] = lw_(R[29] + 32);  /* 0x800A7DF0 */
    R[19] = lw_(R[29] + 28);  /* 0x800A7DF4 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7DF8 */
    R[17] = lw_(R[29] + 20);  /* 0x800A7DFC */
    R[16] = lw_(R[29] + 16);  /* 0x800A7E00 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7E04 jr ra */
}

void g0_800A7DE0(void) {
    R[2] = lw_(R[16] + 4);  /* 0x800A7DE0 */
    sh_(R[17] + 30440, R[0]);  /* 0x800A7DE4 */
    sw_(R[19] + 4, R[2]);  /* 0x800A7DE8 */
    R[31] = lw_(R[29] + 36);  /* 0x800A7DEC */
    R[20] = lw_(R[29] + 32);  /* 0x800A7DF0 */
    R[19] = lw_(R[29] + 28);  /* 0x800A7DF4 */
    R[18] = lw_(R[29] + 24);  /* 0x800A7DF8 */
    R[17] = lw_(R[29] + 20);  /* 0x800A7DFC */
    R[16] = lw_(R[29] + 16);  /* 0x800A7E00 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A7E04 jr ra */
}

void g0_800A7E0C(void) {
    R[29] = R[29] - 24;  /* 0x800A7E0C */
    sw_(R[29] + 16, R[31]);  /* 0x800A7E10 */
    { R[31] = 0x800A7E1Cu; psx_next = 0x8001D050u; return; }  /* 0x800A7E14 jal */
    R[3] = 0x8013u << 16;  /* 0x800A7E1C */
    { R[31] = 0x800A7E28u; sw_(R[3] + -18708, R[2]); psx_next = 0x8001D1B8u; return; }  /* 0x800A7E20 jal */
    R[3] = 0x8013u << 16;  /* 0x800A7E28 */
    R[2] = R[2] << 16;  /* 0x800A7E2C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A7E30 */
    { R[31] = 0x800A7E3Cu; sw_(R[3] + -18716, R[2]); psx_next = 0x8001D16Cu; return; }  /* 0x800A7E34 jal */
    R[3] = 0x8013u << 16;  /* 0x800A7E3C */
    R[2] = R[2] << 16;  /* 0x800A7E40 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A7E44 */
    { R[31] = 0x800A7E50u; sw_(R[3] + -18636, R[2]); psx_next = 0x8001D2A4u; return; }  /* 0x800A7E48 jal */
    R[3] = 0x8013u << 16;  /* 0x800A7E50 */
    R[2] = R[2] << 16;  /* 0x800A7E54 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A7E58 */
    { R[31] = 0x800A7E64u; sw_(R[3] + -18724, R[2]); psx_next = 0x8001D258u; return; }  /* 0x800A7E5C jal */
    R[3] = 0x8013u << 16;  /* 0x800A7E64 */
    R[2] = R[2] << 16;  /* 0x800A7E68 */
    R[31] = lw_(R[29] + 16);  /* 0x800A7E6C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A7E70 */
    sw_(R[3] + -18640, R[2]);  /* 0x800A7E74 */
    R[2] = 0x8013u << 16;  /* 0x800A7E78 */
    sw_(R[2] + -18632, R[0]);  /* 0x800A7E7C */
    R[2] = 0x8013u << 16;  /* 0x800A7E80 */
    sw_(R[2] + -18704, R[0]);  /* 0x800A7E84 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A7E88 jr ra */
}

void g0_800A7E1C(void) {
    R[3] = 0x8013u << 16;  /* 0x800A7E1C */
    { R[31] = 0x800A7E28u; sw_(R[3] + -18708, R[2]); psx_next = 0x8001D1B8u; return; }  /* 0x800A7E20 jal */
    R[3] = 0x8013u << 16;  /* 0x800A7E28 */
    R[2] = R[2] << 16;  /* 0x800A7E2C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A7E30 */
    { R[31] = 0x800A7E3Cu; sw_(R[3] + -18716, R[2]); psx_next = 0x8001D16Cu; return; }  /* 0x800A7E34 jal */
    R[3] = 0x8013u << 16;  /* 0x800A7E3C */
    R[2] = R[2] << 16;  /* 0x800A7E40 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A7E44 */
    { R[31] = 0x800A7E50u; sw_(R[3] + -18636, R[2]); psx_next = 0x8001D2A4u; return; }  /* 0x800A7E48 jal */
    R[3] = 0x8013u << 16;  /* 0x800A7E50 */
    R[2] = R[2] << 16;  /* 0x800A7E54 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A7E58 */
    { R[31] = 0x800A7E64u; sw_(R[3] + -18724, R[2]); psx_next = 0x8001D258u; return; }  /* 0x800A7E5C jal */
    R[3] = 0x8013u << 16;  /* 0x800A7E64 */
    R[2] = R[2] << 16;  /* 0x800A7E68 */
    R[31] = lw_(R[29] + 16);  /* 0x800A7E6C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A7E70 */
    sw_(R[3] + -18640, R[2]);  /* 0x800A7E74 */
    R[2] = 0x8013u << 16;  /* 0x800A7E78 */
    sw_(R[2] + -18632, R[0]);  /* 0x800A7E7C */
    R[2] = 0x8013u << 16;  /* 0x800A7E80 */
    sw_(R[2] + -18704, R[0]);  /* 0x800A7E84 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A7E88 jr ra */
}

void g0_800A7E28(void) {
    R[3] = 0x8013u << 16;  /* 0x800A7E28 */
    R[2] = R[2] << 16;  /* 0x800A7E2C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A7E30 */
    { R[31] = 0x800A7E3Cu; sw_(R[3] + -18716, R[2]); psx_next = 0x8001D16Cu; return; }  /* 0x800A7E34 jal */
    R[3] = 0x8013u << 16;  /* 0x800A7E3C */
    R[2] = R[2] << 16;  /* 0x800A7E40 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A7E44 */
    { R[31] = 0x800A7E50u; sw_(R[3] + -18636, R[2]); psx_next = 0x8001D2A4u; return; }  /* 0x800A7E48 jal */
    R[3] = 0x8013u << 16;  /* 0x800A7E50 */
    R[2] = R[2] << 16;  /* 0x800A7E54 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A7E58 */
    { R[31] = 0x800A7E64u; sw_(R[3] + -18724, R[2]); psx_next = 0x8001D258u; return; }  /* 0x800A7E5C jal */
    R[3] = 0x8013u << 16;  /* 0x800A7E64 */
    R[2] = R[2] << 16;  /* 0x800A7E68 */
    R[31] = lw_(R[29] + 16);  /* 0x800A7E6C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A7E70 */
    sw_(R[3] + -18640, R[2]);  /* 0x800A7E74 */
    R[2] = 0x8013u << 16;  /* 0x800A7E78 */
    sw_(R[2] + -18632, R[0]);  /* 0x800A7E7C */
    R[2] = 0x8013u << 16;  /* 0x800A7E80 */
    sw_(R[2] + -18704, R[0]);  /* 0x800A7E84 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A7E88 jr ra */
}

void g0_800A7E3C(void) {
    R[3] = 0x8013u << 16;  /* 0x800A7E3C */
    R[2] = R[2] << 16;  /* 0x800A7E40 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A7E44 */
    { R[31] = 0x800A7E50u; sw_(R[3] + -18636, R[2]); psx_next = 0x8001D2A4u; return; }  /* 0x800A7E48 jal */
    R[3] = 0x8013u << 16;  /* 0x800A7E50 */
    R[2] = R[2] << 16;  /* 0x800A7E54 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A7E58 */
    { R[31] = 0x800A7E64u; sw_(R[3] + -18724, R[2]); psx_next = 0x8001D258u; return; }  /* 0x800A7E5C jal */
    R[3] = 0x8013u << 16;  /* 0x800A7E64 */
    R[2] = R[2] << 16;  /* 0x800A7E68 */
    R[31] = lw_(R[29] + 16);  /* 0x800A7E6C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A7E70 */
    sw_(R[3] + -18640, R[2]);  /* 0x800A7E74 */
    R[2] = 0x8013u << 16;  /* 0x800A7E78 */
    sw_(R[2] + -18632, R[0]);  /* 0x800A7E7C */
    R[2] = 0x8013u << 16;  /* 0x800A7E80 */
    sw_(R[2] + -18704, R[0]);  /* 0x800A7E84 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A7E88 jr ra */
}

void g0_800A7E50(void) {
    R[3] = 0x8013u << 16;  /* 0x800A7E50 */
    R[2] = R[2] << 16;  /* 0x800A7E54 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A7E58 */
    { R[31] = 0x800A7E64u; sw_(R[3] + -18724, R[2]); psx_next = 0x8001D258u; return; }  /* 0x800A7E5C jal */
    R[3] = 0x8013u << 16;  /* 0x800A7E64 */
    R[2] = R[2] << 16;  /* 0x800A7E68 */
    R[31] = lw_(R[29] + 16);  /* 0x800A7E6C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A7E70 */
    sw_(R[3] + -18640, R[2]);  /* 0x800A7E74 */
    R[2] = 0x8013u << 16;  /* 0x800A7E78 */
    sw_(R[2] + -18632, R[0]);  /* 0x800A7E7C */
    R[2] = 0x8013u << 16;  /* 0x800A7E80 */
    sw_(R[2] + -18704, R[0]);  /* 0x800A7E84 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A7E88 jr ra */
}

void g0_800A7E64(void) {
    R[3] = 0x8013u << 16;  /* 0x800A7E64 */
    R[2] = R[2] << 16;  /* 0x800A7E68 */
    R[31] = lw_(R[29] + 16);  /* 0x800A7E6C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A7E70 */
    sw_(R[3] + -18640, R[2]);  /* 0x800A7E74 */
    R[2] = 0x8013u << 16;  /* 0x800A7E78 */
    sw_(R[2] + -18632, R[0]);  /* 0x800A7E7C */
    R[2] = 0x8013u << 16;  /* 0x800A7E80 */
    sw_(R[2] + -18704, R[0]);  /* 0x800A7E84 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A7E88 jr ra */
}

void g0_800A7E90(void) {
    R[29] = R[29] - 64;  /* 0x800A7E90 */
    sw_(R[29] + 60, R[31]);  /* 0x800A7E94 */
    sw_(R[29] + 56, R[30]);  /* 0x800A7E98 */
    sw_(R[29] + 52, R[23]);  /* 0x800A7E9C */
    sw_(R[29] + 48, R[22]);  /* 0x800A7EA0 */
    sw_(R[29] + 44, R[21]);  /* 0x800A7EA4 */
    sw_(R[29] + 40, R[20]);  /* 0x800A7EA8 */
    sw_(R[29] + 36, R[19]);  /* 0x800A7EAC */
    sw_(R[29] + 32, R[18]);  /* 0x800A7EB0 */
    sw_(R[29] + 28, R[17]);  /* 0x800A7EB4 */
    sw_(R[29] + 24, R[16]);  /* 0x800A7EB8 */
    sw_(R[29] + 68, R[5]);  /* 0x800A7EBC */
    { uint32_t _c = (R[6] == R[0]); sh_(R[29] + 16, R[7]); if (_c) { goto L_800A7ED0; } }  /* 0x800A7EC0 */
    { R[2] = R[4] + R[0]; goto L_800A82BC; }  /* 0x800A7EC8 j */
L_800A7ED0:;
    R[6] = R[7] + 272;  /* 0x800A7ED0 */
    R[2] = R[0] + 12;  /* 0x800A7ED4 */
    sb_(R[4] + 3, R[2]);  /* 0x800A7ED8 */
    R[2] = R[0] + 60;  /* 0x800A7EDC */
    sb_(R[4] + 7, R[2]);  /* 0x800A7EE0 */
    R[2] = 0x8005u << 16;  /* 0x800A7EE4 */
    R[2] = lh_(R[2] + -868);  /* 0x800A7EE8 */
    R[3] = 0x8011u << 16;  /* 0x800A7EEC */
    sh_(R[4] + 14, R[2]);  /* 0x800A7EF0 */
    R[2] = R[3] + 29992;  /* 0x800A7EF4 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 2);  /* 0x800A7EF8 */
    { uint32_t _c = (R[2] != R[0]); R[30] = R[4] + R[0]; if (_c) { goto L_800A7F30; } }  /* 0x800A7F00 */
    R[2] = 0x800Fu << 16;  /* 0x800A7F08 */
    R[2] = lw_(R[2] + 25120);  /* 0x800A7F0C */
    R[2] = R[2] & 0x10;  /* 0x800A7F14 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 52; if (_c) { goto L_800A7F34; } }  /* 0x800A7F18 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 29992);  /* 0x800A7F20 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 211; if (_c) { goto L_800A7F74; } }  /* 0x800A7F28 */
L_800A7F30:;
    R[2] = R[0] + 52;  /* 0x800A7F30 */
L_800A7F34:;
    R[3] = R[0] + 49;  /* 0x800A7F34 */
    sb_(R[30] + 4, R[2]);  /* 0x800A7F38 */
    sb_(R[30] + 6, R[2]);  /* 0x800A7F3C */
    sb_(R[30] + 16, R[2]);  /* 0x800A7F40 */
    sb_(R[30] + 18, R[2]);  /* 0x800A7F44 */
    R[2] = R[0] + 18;  /* 0x800A7F48 */
    sb_(R[30] + 28, R[2]);  /* 0x800A7F4C */
    sb_(R[30] + 29, R[2]);  /* 0x800A7F50 */
    sb_(R[30] + 30, R[2]);  /* 0x800A7F54 */
    R[2] = R[0] + 5;  /* 0x800A7F58 */
    sb_(R[30] + 5, R[3]);  /* 0x800A7F5C */
    sb_(R[30] + 17, R[3]);  /* 0x800A7F60 */
    sb_(R[30] + 40, R[2]);  /* 0x800A7F64 */
    sb_(R[30] + 41, R[2]);  /* 0x800A7F68 */
    { sb_(R[30] + 42, R[2]); goto L_800A7FB0; }  /* 0x800A7F6C j */
L_800A7F74:;
    R[3] = R[0] + 196;  /* 0x800A7F74 */
    sb_(R[4] + 4, R[2]);  /* 0x800A7F78 */
    sb_(R[4] + 6, R[2]);  /* 0x800A7F7C */
    sb_(R[4] + 16, R[2]);  /* 0x800A7F80 */
    sb_(R[4] + 18, R[2]);  /* 0x800A7F84 */
    R[2] = R[0] + 75;  /* 0x800A7F88 */
    sb_(R[4] + 28, R[2]);  /* 0x800A7F8C */
    sb_(R[4] + 29, R[2]);  /* 0x800A7F90 */
    sb_(R[4] + 30, R[2]);  /* 0x800A7F94 */
    R[2] = R[0] + 21;  /* 0x800A7F98 */
    sb_(R[4] + 5, R[3]);  /* 0x800A7F9C */
    sb_(R[4] + 17, R[3]);  /* 0x800A7FA0 */
    sb_(R[4] + 40, R[2]);  /* 0x800A7FA4 */
    sb_(R[4] + 41, R[2]);  /* 0x800A7FA8 */
    sb_(R[4] + 42, R[2]);  /* 0x800A7FAC */
L_800A7FB0:;
    R[5] = R[30] + R[0];  /* 0x800A7FB0 */
    R[2] = R[0] + 25;  /* 0x800A7FB4 */
    R[8] = R[0] + 182;  /* 0x800A7FB8 */
    R[4] = lw_(R[29] + 68);  /* 0x800A7FBC */
    R[3] = R[6] + 24;  /* 0x800A7FC0 */
    sh_(R[30] + 10, R[8]);  /* 0x800A7FC4 */
    sh_(R[30] + 22, R[8]);  /* 0x800A7FC8 */
    R[8] = R[0] + 182;  /* 0x800A7FCC */
    sh_(R[30] + 26, R[2]);  /* 0x800A7FD0 */
    R[2] = R[8] + 24;  /* 0x800A7FD4 */
    sh_(R[30] + 8, R[6]);  /* 0x800A7FD8 */
    sh_(R[30] + 32, R[6]);  /* 0x800A7FDC */
    R[6] = R[0] + 96;  /* 0x800A7FE0 */
    sh_(R[30] + 34, R[2]);  /* 0x800A7FE4 */
    sh_(R[30] + 46, R[2]);  /* 0x800A7FE8 */
    R[2] = R[0] + 160;  /* 0x800A7FEC */
    sh_(R[30] + 20, R[3]);  /* 0x800A7FF0 */
    sh_(R[30] + 44, R[3]);  /* 0x800A7FF4 */
    R[3] = R[0] + 120;  /* 0x800A7FF8 */
    sb_(R[30] + 13, R[2]);  /* 0x800A7FFC */
    sb_(R[30] + 25, R[2]);  /* 0x800A8000 */
    R[2] = R[0] + 184;  /* 0x800A8004 */
    sb_(R[30] + 12, R[6]);  /* 0x800A8008 */
    sb_(R[30] + 24, R[3]);  /* 0x800A800C */
    sb_(R[30] + 36, R[6]);  /* 0x800A8010 */
    sb_(R[30] + 37, R[2]);  /* 0x800A8014 */
    sb_(R[30] + 48, R[3]);  /* 0x800A8018 */
    { R[31] = 0x800A8024u; sb_(R[30] + 49, R[2]); psx_next = 0x800356E8u; return; }  /* 0x800A801C jal */
    R[30] = R[30] + 52;  /* 0x800A8024 */
    R[2] = R[0] + 12;  /* 0x800A8028 */
    sb_(R[30] + 3, R[2]);  /* 0x800A802C */
    R[2] = R[0] + 60;  /* 0x800A8030 */
    sb_(R[30] + 7, R[2]);  /* 0x800A8034 */
    R[2] = 0x8013u << 16;  /* 0x800A8038 */
    R[8] = lh_(R[29] + 16);  /* 0x800A803C */
    R[2] = lh_(R[2] + -29480);  /* 0x800A8040 */
    R[2] = R[2] - 2;  /* 0x800A8048 */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x800A804C */
    { uint32_t _c = (R[2] == R[0]); R[6] = R[8] + 242; if (_c) { goto L_800A8088; } }  /* 0x800A8050 */
    R[2] = R[0] + 52;  /* 0x800A8058 */
    R[3] = R[0] + 49;  /* 0x800A805C */
    sb_(R[30] + 4, R[2]);  /* 0x800A8060 */
    sb_(R[30] + 6, R[2]);  /* 0x800A8064 */
    sb_(R[30] + 16, R[2]);  /* 0x800A8068 */
    sb_(R[30] + 18, R[2]);  /* 0x800A806C */
    R[2] = R[0] + 18;  /* 0x800A8070 */
    sb_(R[30] + 28, R[2]);  /* 0x800A8074 */
    sb_(R[30] + 29, R[2]);  /* 0x800A8078 */
    sb_(R[30] + 30, R[2]);  /* 0x800A807C */
    { R[2] = R[0] + 5; goto L_800A80B4; }  /* 0x800A8080 j */
L_800A8088:;
    R[2] = R[0] + 211;  /* 0x800A8088 */
    R[3] = R[0] + 196;  /* 0x800A808C */
    sb_(R[30] + 4, R[2]);  /* 0x800A8090 */
    sb_(R[30] + 6, R[2]);  /* 0x800A8094 */
    sb_(R[30] + 16, R[2]);  /* 0x800A8098 */
    sb_(R[30] + 18, R[2]);  /* 0x800A809C */
    R[2] = R[0] + 75;  /* 0x800A80A0 */
    sb_(R[30] + 28, R[2]);  /* 0x800A80A4 */
    sb_(R[30] + 29, R[2]);  /* 0x800A80A8 */
    sb_(R[30] + 30, R[2]);  /* 0x800A80AC */
    R[2] = R[0] + 21;  /* 0x800A80B0 */
L_800A80B4:;
    sb_(R[30] + 5, R[3]);  /* 0x800A80B4 */
    sb_(R[30] + 17, R[3]);  /* 0x800A80B8 */
    sb_(R[30] + 40, R[2]);  /* 0x800A80BC */
    sb_(R[30] + 41, R[2]);  /* 0x800A80C0 */
    sb_(R[30] + 42, R[2]);  /* 0x800A80C4 */
    R[2] = 0x8005u << 16;  /* 0x800A80C8 */
    R[4] = lh_(R[2] + -868);  /* 0x800A80CC */
    R[2] = R[0] + 25;  /* 0x800A80D0 */
    R[8] = R[0] + 182;  /* 0x800A80D4 */
    R[3] = R[6] + 24;  /* 0x800A80D8 */
    sh_(R[30] + 10, R[8]);  /* 0x800A80DC */
    sh_(R[30] + 22, R[8]);  /* 0x800A80E0 */
    R[8] = R[0] + 182;  /* 0x800A80E4 */
    sh_(R[30] + 26, R[2]);  /* 0x800A80E8 */
    R[2] = R[8] + 24;  /* 0x800A80EC */
    sh_(R[30] + 34, R[2]);  /* 0x800A80F0 */
    sh_(R[30] + 46, R[2]);  /* 0x800A80F4 */
    R[2] = 0x8006u << 16;  /* 0x800A80F8 */
    sh_(R[30] + 8, R[6]);  /* 0x800A80FC */
    sh_(R[30] + 20, R[3]);  /* 0x800A8100 */
    sh_(R[30] + 32, R[6]);  /* 0x800A8104 */
    sh_(R[30] + 44, R[3]);  /* 0x800A8108 */
    sh_(R[30] + 14, R[4]);  /* 0x800A810C */
    R[2] = lh_(R[2] + 16104);  /* 0x800A8110 */
    R[2] = R[2] & 0x1;  /* 0x800A8118 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 96; if (_c) { goto L_800A8130; } }  /* 0x800A811C */
    R[2] = R[0] + 136;  /* 0x800A8124 */
    { R[3] = R[0] + 120; goto L_800A813C; }  /* 0x800A8128 j */
L_800A8130:;
    R[4] = R[0] + 120;  /* 0x800A8130 */
    R[2] = R[0] + 136;  /* 0x800A8134 */
    R[3] = R[0] + 144;  /* 0x800A8138 */
L_800A813C:;
    sb_(R[30] + 13, R[2]);  /* 0x800A813C */
    sb_(R[30] + 25, R[2]);  /* 0x800A8140 */
    R[2] = R[0] + 160;  /* 0x800A8144 */
    sb_(R[30] + 12, R[4]);  /* 0x800A8148 */
    sb_(R[30] + 24, R[3]);  /* 0x800A814C */
    sb_(R[30] + 36, R[4]);  /* 0x800A8150 */
    sb_(R[30] + 37, R[2]);  /* 0x800A8154 */
    sb_(R[30] + 48, R[3]);  /* 0x800A8158 */
    sb_(R[30] + 49, R[2]);  /* 0x800A815C */
    R[4] = lw_(R[29] + 68);  /* 0x800A8160 */
    { R[31] = 0x800A816Cu; R[5] = R[30] + R[0]; psx_next = 0x800356E8u; return; }  /* 0x800A8164 jal */
    R[30] = R[30] + 52;  /* 0x800A816C */
    R[5] = R[30] + R[0];  /* 0x800A8170 */
    R[4] = lw_(R[29] + 68);  /* 0x800A8174 */
    R[8] = R[0] + 9;  /* 0x800A8178 */
    sb_(R[30] + 3, R[8]);  /* 0x800A817C */
    R[8] = R[0] + 46;  /* 0x800A8180 */
    R[16] = R[0] + 128;  /* 0x800A8184 */
    R[20] = 0x8005u << 16;  /* 0x800A8188 */
    R[20] = R[20] - 888;  /* 0x800A818C */
    R[23] = R[0] + 25;  /* 0x800A8190 */
    R[22] = R[0] + 120;  /* 0x800A8194 */
    sb_(R[30] + 7, R[8]);  /* 0x800A8198 */
    sb_(R[30] + 4, R[16]);  /* 0x800A819C */
    sb_(R[30] + 5, R[16]);  /* 0x800A81A0 */
    sb_(R[30] + 6, R[16]);  /* 0x800A81A4 */
    R[6] = lh_(R[20] + 18);  /* 0x800A81A8 */
    R[18] = R[0] + 160;  /* 0x800A81AC */
    sh_(R[30] + 22, R[23]);  /* 0x800A81B0 */
    R[8] = lh_(R[29] + 16);  /* 0x800A81B4 */
    R[19] = R[0] + 144;  /* 0x800A81B8 */
    R[2] = R[8] + 272;  /* 0x800A81BC */
    R[8] = R[0] + 182;  /* 0x800A81C0 */
    sh_(R[30] + 8, R[2]);  /* 0x800A81C4 */
    sh_(R[30] + 10, R[8]);  /* 0x800A81C8 */
    R[8] = lh_(R[29] + 16);  /* 0x800A81CC */
    R[17] = R[0] + 184;  /* 0x800A81D0 */
    sh_(R[30] + 24, R[2]);  /* 0x800A81D4 */
    sb_(R[30] + 12, R[22]);  /* 0x800A81D8 */
    sb_(R[30] + 13, R[18]);  /* 0x800A81DC */
    sb_(R[30] + 20, R[19]);  /* 0x800A81E0 */
    sb_(R[30] + 21, R[18]);  /* 0x800A81E4 */
    sb_(R[30] + 28, R[22]);  /* 0x800A81E8 */
    sb_(R[30] + 29, R[17]);  /* 0x800A81EC */
    sb_(R[30] + 36, R[19]);  /* 0x800A81F0 */
    sb_(R[30] + 37, R[17]);  /* 0x800A81F4 */
    sh_(R[30] + 14, R[6]);  /* 0x800A81F8 */
    R[3] = R[8] + 296;  /* 0x800A81FC */
    R[8] = R[0] + 182;  /* 0x800A8200 */
    sh_(R[30] + 18, R[8]);  /* 0x800A8204 */
    R[8] = R[0] + 182;  /* 0x800A8208 */
    R[21] = R[8] + 24;  /* 0x800A820C */
    sh_(R[30] + 16, R[3]);  /* 0x800A8210 */
    sh_(R[30] + 26, R[21]);  /* 0x800A8214 */
    sh_(R[30] + 32, R[3]);  /* 0x800A8218 */
    { R[31] = 0x800A8224u; sh_(R[30] + 34, R[21]); psx_next = 0x800356E8u; return; }  /* 0x800A821C jal */
    R[5] = R[30] + 40;  /* 0x800A8224 */
    R[4] = lw_(R[29] + 68);  /* 0x800A8228 */
    R[8] = R[0] + 9;  /* 0x800A822C */
    sb_(R[5] + 3, R[8]);  /* 0x800A8230 */
    R[8] = R[0] + 46;  /* 0x800A8234 */
    sb_(R[5] + 7, R[8]);  /* 0x800A8238 */
    sb_(R[5] + 4, R[16]);  /* 0x800A823C */
    sb_(R[5] + 5, R[16]);  /* 0x800A8240 */
    sb_(R[5] + 6, R[16]);  /* 0x800A8244 */
    R[6] = lh_(R[20] + 18);  /* 0x800A8248 */
    sh_(R[5] + 22, R[23]);  /* 0x800A824C */
    R[8] = lh_(R[29] + 16);  /* 0x800A8250 */
    R[3] = R[8] + 242;  /* 0x800A8258 */
    R[8] = R[0] + 182;  /* 0x800A825C */
    sh_(R[5] + 8, R[3]);  /* 0x800A8260 */
    sh_(R[5] + 10, R[8]);  /* 0x800A8264 */
    R[8] = lh_(R[29] + 16);  /* 0x800A8268 */
    R[2] = R[8] + 266;  /* 0x800A8270 */
    R[8] = R[0] + 182;  /* 0x800A8274 */
    sh_(R[5] + 16, R[2]);  /* 0x800A8278 */
    sh_(R[5] + 18, R[8]);  /* 0x800A827C */
    sh_(R[5] + 24, R[3]);  /* 0x800A8280 */
    sh_(R[5] + 26, R[21]);  /* 0x800A8284 */
    sh_(R[5] + 32, R[2]);  /* 0x800A8288 */
    sh_(R[5] + 34, R[21]);  /* 0x800A828C */
    sb_(R[5] + 12, R[22]);  /* 0x800A8290 */
    sb_(R[5] + 13, R[18]);  /* 0x800A8294 */
    sb_(R[5] + 20, R[19]);  /* 0x800A8298 */
    sb_(R[5] + 21, R[18]);  /* 0x800A829C */
    sb_(R[5] + 28, R[22]);  /* 0x800A82A0 */
    sb_(R[5] + 29, R[17]);  /* 0x800A82A4 */
    sb_(R[5] + 36, R[19]);  /* 0x800A82A8 */
    sb_(R[5] + 37, R[17]);  /* 0x800A82AC */
    { R[31] = 0x800A82B8u; sh_(R[5] + 14, R[6]); psx_next = 0x800356E8u; return; }  /* 0x800A82B0 jal */
    R[2] = R[30] + 80;  /* 0x800A82B8 */
L_800A82BC:;
    R[31] = lw_(R[29] + 60);  /* 0x800A82BC */
    R[30] = lw_(R[29] + 56);  /* 0x800A82C0 */
    R[23] = lw_(R[29] + 52);  /* 0x800A82C4 */
    R[22] = lw_(R[29] + 48);  /* 0x800A82C8 */
    R[21] = lw_(R[29] + 44);  /* 0x800A82CC */
    R[20] = lw_(R[29] + 40);  /* 0x800A82D0 */
    R[19] = lw_(R[29] + 36);  /* 0x800A82D4 */
    R[18] = lw_(R[29] + 32);  /* 0x800A82D8 */
    R[17] = lw_(R[29] + 28);  /* 0x800A82DC */
    R[16] = lw_(R[29] + 24);  /* 0x800A82E0 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A82E4 jr ra */
}

void g0_800A8024(void) {
    R[30] = R[30] + 52;  /* 0x800A8024 */
    R[2] = R[0] + 12;  /* 0x800A8028 */
    sb_(R[30] + 3, R[2]);  /* 0x800A802C */
    R[2] = R[0] + 60;  /* 0x800A8030 */
    sb_(R[30] + 7, R[2]);  /* 0x800A8034 */
    R[2] = 0x8013u << 16;  /* 0x800A8038 */
    R[8] = lh_(R[29] + 16);  /* 0x800A803C */
    R[2] = lh_(R[2] + -29480);  /* 0x800A8040 */
    R[2] = R[2] - 2;  /* 0x800A8048 */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x800A804C */
    { uint32_t _c = (R[2] == R[0]); R[6] = R[8] + 242; if (_c) { goto L_800A8088; } }  /* 0x800A8050 */
    R[2] = R[0] + 52;  /* 0x800A8058 */
    R[3] = R[0] + 49;  /* 0x800A805C */
    sb_(R[30] + 4, R[2]);  /* 0x800A8060 */
    sb_(R[30] + 6, R[2]);  /* 0x800A8064 */
    sb_(R[30] + 16, R[2]);  /* 0x800A8068 */
    sb_(R[30] + 18, R[2]);  /* 0x800A806C */
    R[2] = R[0] + 18;  /* 0x800A8070 */
    sb_(R[30] + 28, R[2]);  /* 0x800A8074 */
    sb_(R[30] + 29, R[2]);  /* 0x800A8078 */
    sb_(R[30] + 30, R[2]);  /* 0x800A807C */
    { R[2] = R[0] + 5; goto L_800A80B4; }  /* 0x800A8080 j */
L_800A8088:;
    R[2] = R[0] + 211;  /* 0x800A8088 */
    R[3] = R[0] + 196;  /* 0x800A808C */
    sb_(R[30] + 4, R[2]);  /* 0x800A8090 */
    sb_(R[30] + 6, R[2]);  /* 0x800A8094 */
    sb_(R[30] + 16, R[2]);  /* 0x800A8098 */
    sb_(R[30] + 18, R[2]);  /* 0x800A809C */
    R[2] = R[0] + 75;  /* 0x800A80A0 */
    sb_(R[30] + 28, R[2]);  /* 0x800A80A4 */
    sb_(R[30] + 29, R[2]);  /* 0x800A80A8 */
    sb_(R[30] + 30, R[2]);  /* 0x800A80AC */
    R[2] = R[0] + 21;  /* 0x800A80B0 */
L_800A80B4:;
    sb_(R[30] + 5, R[3]);  /* 0x800A80B4 */
    sb_(R[30] + 17, R[3]);  /* 0x800A80B8 */
    sb_(R[30] + 40, R[2]);  /* 0x800A80BC */
    sb_(R[30] + 41, R[2]);  /* 0x800A80C0 */
    sb_(R[30] + 42, R[2]);  /* 0x800A80C4 */
    R[2] = 0x8005u << 16;  /* 0x800A80C8 */
    R[4] = lh_(R[2] + -868);  /* 0x800A80CC */
    R[2] = R[0] + 25;  /* 0x800A80D0 */
    R[8] = R[0] + 182;  /* 0x800A80D4 */
    R[3] = R[6] + 24;  /* 0x800A80D8 */
    sh_(R[30] + 10, R[8]);  /* 0x800A80DC */
    sh_(R[30] + 22, R[8]);  /* 0x800A80E0 */
    R[8] = R[0] + 182;  /* 0x800A80E4 */
    sh_(R[30] + 26, R[2]);  /* 0x800A80E8 */
    R[2] = R[8] + 24;  /* 0x800A80EC */
    sh_(R[30] + 34, R[2]);  /* 0x800A80F0 */
    sh_(R[30] + 46, R[2]);  /* 0x800A80F4 */
    R[2] = 0x8006u << 16;  /* 0x800A80F8 */
    sh_(R[30] + 8, R[6]);  /* 0x800A80FC */
    sh_(R[30] + 20, R[3]);  /* 0x800A8100 */
    sh_(R[30] + 32, R[6]);  /* 0x800A8104 */
    sh_(R[30] + 44, R[3]);  /* 0x800A8108 */
    sh_(R[30] + 14, R[4]);  /* 0x800A810C */
    R[2] = lh_(R[2] + 16104);  /* 0x800A8110 */
    R[2] = R[2] & 0x1;  /* 0x800A8118 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 96; if (_c) { goto L_800A8130; } }  /* 0x800A811C */
    R[2] = R[0] + 136;  /* 0x800A8124 */
    { R[3] = R[0] + 120; goto L_800A813C; }  /* 0x800A8128 j */
L_800A8130:;
    R[4] = R[0] + 120;  /* 0x800A8130 */
    R[2] = R[0] + 136;  /* 0x800A8134 */
    R[3] = R[0] + 144;  /* 0x800A8138 */
L_800A813C:;
    sb_(R[30] + 13, R[2]);  /* 0x800A813C */
    sb_(R[30] + 25, R[2]);  /* 0x800A8140 */
    R[2] = R[0] + 160;  /* 0x800A8144 */
    sb_(R[30] + 12, R[4]);  /* 0x800A8148 */
    sb_(R[30] + 24, R[3]);  /* 0x800A814C */
    sb_(R[30] + 36, R[4]);  /* 0x800A8150 */
    sb_(R[30] + 37, R[2]);  /* 0x800A8154 */
    sb_(R[30] + 48, R[3]);  /* 0x800A8158 */
    sb_(R[30] + 49, R[2]);  /* 0x800A815C */
    R[4] = lw_(R[29] + 68);  /* 0x800A8160 */
    { R[31] = 0x800A816Cu; R[5] = R[30] + R[0]; psx_next = 0x800356E8u; return; }  /* 0x800A8164 jal */
    R[30] = R[30] + 52;  /* 0x800A816C */
    R[5] = R[30] + R[0];  /* 0x800A8170 */
    R[4] = lw_(R[29] + 68);  /* 0x800A8174 */
    R[8] = R[0] + 9;  /* 0x800A8178 */
    sb_(R[30] + 3, R[8]);  /* 0x800A817C */
    R[8] = R[0] + 46;  /* 0x800A8180 */
    R[16] = R[0] + 128;  /* 0x800A8184 */
    R[20] = 0x8005u << 16;  /* 0x800A8188 */
    R[20] = R[20] - 888;  /* 0x800A818C */
    R[23] = R[0] + 25;  /* 0x800A8190 */
    R[22] = R[0] + 120;  /* 0x800A8194 */
    sb_(R[30] + 7, R[8]);  /* 0x800A8198 */
    sb_(R[30] + 4, R[16]);  /* 0x800A819C */
    sb_(R[30] + 5, R[16]);  /* 0x800A81A0 */
    sb_(R[30] + 6, R[16]);  /* 0x800A81A4 */
    R[6] = lh_(R[20] + 18);  /* 0x800A81A8 */
    R[18] = R[0] + 160;  /* 0x800A81AC */
    sh_(R[30] + 22, R[23]);  /* 0x800A81B0 */
    R[8] = lh_(R[29] + 16);  /* 0x800A81B4 */
    R[19] = R[0] + 144;  /* 0x800A81B8 */
    R[2] = R[8] + 272;  /* 0x800A81BC */
    R[8] = R[0] + 182;  /* 0x800A81C0 */
    sh_(R[30] + 8, R[2]);  /* 0x800A81C4 */
    sh_(R[30] + 10, R[8]);  /* 0x800A81C8 */
    R[8] = lh_(R[29] + 16);  /* 0x800A81CC */
    R[17] = R[0] + 184;  /* 0x800A81D0 */
    sh_(R[30] + 24, R[2]);  /* 0x800A81D4 */
    sb_(R[30] + 12, R[22]);  /* 0x800A81D8 */
    sb_(R[30] + 13, R[18]);  /* 0x800A81DC */
    sb_(R[30] + 20, R[19]);  /* 0x800A81E0 */
    sb_(R[30] + 21, R[18]);  /* 0x800A81E4 */
    sb_(R[30] + 28, R[22]);  /* 0x800A81E8 */
    sb_(R[30] + 29, R[17]);  /* 0x800A81EC */
    sb_(R[30] + 36, R[19]);  /* 0x800A81F0 */
    sb_(R[30] + 37, R[17]);  /* 0x800A81F4 */
    sh_(R[30] + 14, R[6]);  /* 0x800A81F8 */
    R[3] = R[8] + 296;  /* 0x800A81FC */
    R[8] = R[0] + 182;  /* 0x800A8200 */
    sh_(R[30] + 18, R[8]);  /* 0x800A8204 */
    R[8] = R[0] + 182;  /* 0x800A8208 */
    R[21] = R[8] + 24;  /* 0x800A820C */
    sh_(R[30] + 16, R[3]);  /* 0x800A8210 */
    sh_(R[30] + 26, R[21]);  /* 0x800A8214 */
    sh_(R[30] + 32, R[3]);  /* 0x800A8218 */
    { R[31] = 0x800A8224u; sh_(R[30] + 34, R[21]); psx_next = 0x800356E8u; return; }  /* 0x800A821C jal */
    R[5] = R[30] + 40;  /* 0x800A8224 */
    R[4] = lw_(R[29] + 68);  /* 0x800A8228 */
    R[8] = R[0] + 9;  /* 0x800A822C */
    sb_(R[5] + 3, R[8]);  /* 0x800A8230 */
    R[8] = R[0] + 46;  /* 0x800A8234 */
    sb_(R[5] + 7, R[8]);  /* 0x800A8238 */
    sb_(R[5] + 4, R[16]);  /* 0x800A823C */
    sb_(R[5] + 5, R[16]);  /* 0x800A8240 */
    sb_(R[5] + 6, R[16]);  /* 0x800A8244 */
    R[6] = lh_(R[20] + 18);  /* 0x800A8248 */
    sh_(R[5] + 22, R[23]);  /* 0x800A824C */
    R[8] = lh_(R[29] + 16);  /* 0x800A8250 */
    R[3] = R[8] + 242;  /* 0x800A8258 */
    R[8] = R[0] + 182;  /* 0x800A825C */
    sh_(R[5] + 8, R[3]);  /* 0x800A8260 */
    sh_(R[5] + 10, R[8]);  /* 0x800A8264 */
    R[8] = lh_(R[29] + 16);  /* 0x800A8268 */
    R[2] = R[8] + 266;  /* 0x800A8270 */
    R[8] = R[0] + 182;  /* 0x800A8274 */
    sh_(R[5] + 16, R[2]);  /* 0x800A8278 */
    sh_(R[5] + 18, R[8]);  /* 0x800A827C */
    sh_(R[5] + 24, R[3]);  /* 0x800A8280 */
    sh_(R[5] + 26, R[21]);  /* 0x800A8284 */
    sh_(R[5] + 32, R[2]);  /* 0x800A8288 */
    sh_(R[5] + 34, R[21]);  /* 0x800A828C */
    sb_(R[5] + 12, R[22]);  /* 0x800A8290 */
    sb_(R[5] + 13, R[18]);  /* 0x800A8294 */
    sb_(R[5] + 20, R[19]);  /* 0x800A8298 */
    sb_(R[5] + 21, R[18]);  /* 0x800A829C */
    sb_(R[5] + 28, R[22]);  /* 0x800A82A0 */
    sb_(R[5] + 29, R[17]);  /* 0x800A82A4 */
    sb_(R[5] + 36, R[19]);  /* 0x800A82A8 */
    sb_(R[5] + 37, R[17]);  /* 0x800A82AC */
    { R[31] = 0x800A82B8u; sh_(R[5] + 14, R[6]); psx_next = 0x800356E8u; return; }  /* 0x800A82B0 jal */
    R[2] = R[30] + 80;  /* 0x800A82B8 */
    R[31] = lw_(R[29] + 60);  /* 0x800A82BC */
    R[30] = lw_(R[29] + 56);  /* 0x800A82C0 */
    R[23] = lw_(R[29] + 52);  /* 0x800A82C4 */
    R[22] = lw_(R[29] + 48);  /* 0x800A82C8 */
    R[21] = lw_(R[29] + 44);  /* 0x800A82CC */
    R[20] = lw_(R[29] + 40);  /* 0x800A82D0 */
    R[19] = lw_(R[29] + 36);  /* 0x800A82D4 */
    R[18] = lw_(R[29] + 32);  /* 0x800A82D8 */
    R[17] = lw_(R[29] + 28);  /* 0x800A82DC */
    R[16] = lw_(R[29] + 24);  /* 0x800A82E0 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A82E4 jr ra */
}

void g0_800A816C(void) {
    R[30] = R[30] + 52;  /* 0x800A816C */
    R[5] = R[30] + R[0];  /* 0x800A8170 */
    R[4] = lw_(R[29] + 68);  /* 0x800A8174 */
    R[8] = R[0] + 9;  /* 0x800A8178 */
    sb_(R[30] + 3, R[8]);  /* 0x800A817C */
    R[8] = R[0] + 46;  /* 0x800A8180 */
    R[16] = R[0] + 128;  /* 0x800A8184 */
    R[20] = 0x8005u << 16;  /* 0x800A8188 */
    R[20] = R[20] - 888;  /* 0x800A818C */
    R[23] = R[0] + 25;  /* 0x800A8190 */
    R[22] = R[0] + 120;  /* 0x800A8194 */
    sb_(R[30] + 7, R[8]);  /* 0x800A8198 */
    sb_(R[30] + 4, R[16]);  /* 0x800A819C */
    sb_(R[30] + 5, R[16]);  /* 0x800A81A0 */
    sb_(R[30] + 6, R[16]);  /* 0x800A81A4 */
    R[6] = lh_(R[20] + 18);  /* 0x800A81A8 */
    R[18] = R[0] + 160;  /* 0x800A81AC */
    sh_(R[30] + 22, R[23]);  /* 0x800A81B0 */
    R[8] = lh_(R[29] + 16);  /* 0x800A81B4 */
    R[19] = R[0] + 144;  /* 0x800A81B8 */
    R[2] = R[8] + 272;  /* 0x800A81BC */
    R[8] = R[0] + 182;  /* 0x800A81C0 */
    sh_(R[30] + 8, R[2]);  /* 0x800A81C4 */
    sh_(R[30] + 10, R[8]);  /* 0x800A81C8 */
    R[8] = lh_(R[29] + 16);  /* 0x800A81CC */
    R[17] = R[0] + 184;  /* 0x800A81D0 */
    sh_(R[30] + 24, R[2]);  /* 0x800A81D4 */
    sb_(R[30] + 12, R[22]);  /* 0x800A81D8 */
    sb_(R[30] + 13, R[18]);  /* 0x800A81DC */
    sb_(R[30] + 20, R[19]);  /* 0x800A81E0 */
    sb_(R[30] + 21, R[18]);  /* 0x800A81E4 */
    sb_(R[30] + 28, R[22]);  /* 0x800A81E8 */
    sb_(R[30] + 29, R[17]);  /* 0x800A81EC */
    sb_(R[30] + 36, R[19]);  /* 0x800A81F0 */
    sb_(R[30] + 37, R[17]);  /* 0x800A81F4 */
    sh_(R[30] + 14, R[6]);  /* 0x800A81F8 */
    R[3] = R[8] + 296;  /* 0x800A81FC */
    R[8] = R[0] + 182;  /* 0x800A8200 */
    sh_(R[30] + 18, R[8]);  /* 0x800A8204 */
    R[8] = R[0] + 182;  /* 0x800A8208 */
    R[21] = R[8] + 24;  /* 0x800A820C */
    sh_(R[30] + 16, R[3]);  /* 0x800A8210 */
    sh_(R[30] + 26, R[21]);  /* 0x800A8214 */
    sh_(R[30] + 32, R[3]);  /* 0x800A8218 */
    { R[31] = 0x800A8224u; sh_(R[30] + 34, R[21]); psx_next = 0x800356E8u; return; }  /* 0x800A821C jal */
    R[5] = R[30] + 40;  /* 0x800A8224 */
    R[4] = lw_(R[29] + 68);  /* 0x800A8228 */
    R[8] = R[0] + 9;  /* 0x800A822C */
    sb_(R[5] + 3, R[8]);  /* 0x800A8230 */
    R[8] = R[0] + 46;  /* 0x800A8234 */
    sb_(R[5] + 7, R[8]);  /* 0x800A8238 */
    sb_(R[5] + 4, R[16]);  /* 0x800A823C */
    sb_(R[5] + 5, R[16]);  /* 0x800A8240 */
    sb_(R[5] + 6, R[16]);  /* 0x800A8244 */
    R[6] = lh_(R[20] + 18);  /* 0x800A8248 */
    sh_(R[5] + 22, R[23]);  /* 0x800A824C */
    R[8] = lh_(R[29] + 16);  /* 0x800A8250 */
    R[3] = R[8] + 242;  /* 0x800A8258 */
    R[8] = R[0] + 182;  /* 0x800A825C */
    sh_(R[5] + 8, R[3]);  /* 0x800A8260 */
    sh_(R[5] + 10, R[8]);  /* 0x800A8264 */
    R[8] = lh_(R[29] + 16);  /* 0x800A8268 */
    R[2] = R[8] + 266;  /* 0x800A8270 */
    R[8] = R[0] + 182;  /* 0x800A8274 */
    sh_(R[5] + 16, R[2]);  /* 0x800A8278 */
    sh_(R[5] + 18, R[8]);  /* 0x800A827C */
    sh_(R[5] + 24, R[3]);  /* 0x800A8280 */
    sh_(R[5] + 26, R[21]);  /* 0x800A8284 */
    sh_(R[5] + 32, R[2]);  /* 0x800A8288 */
    sh_(R[5] + 34, R[21]);  /* 0x800A828C */
    sb_(R[5] + 12, R[22]);  /* 0x800A8290 */
    sb_(R[5] + 13, R[18]);  /* 0x800A8294 */
    sb_(R[5] + 20, R[19]);  /* 0x800A8298 */
    sb_(R[5] + 21, R[18]);  /* 0x800A829C */
    sb_(R[5] + 28, R[22]);  /* 0x800A82A0 */
    sb_(R[5] + 29, R[17]);  /* 0x800A82A4 */
    sb_(R[5] + 36, R[19]);  /* 0x800A82A8 */
    sb_(R[5] + 37, R[17]);  /* 0x800A82AC */
    { R[31] = 0x800A82B8u; sh_(R[5] + 14, R[6]); psx_next = 0x800356E8u; return; }  /* 0x800A82B0 jal */
    R[2] = R[30] + 80;  /* 0x800A82B8 */
    R[31] = lw_(R[29] + 60);  /* 0x800A82BC */
    R[30] = lw_(R[29] + 56);  /* 0x800A82C0 */
    R[23] = lw_(R[29] + 52);  /* 0x800A82C4 */
    R[22] = lw_(R[29] + 48);  /* 0x800A82C8 */
    R[21] = lw_(R[29] + 44);  /* 0x800A82CC */
    R[20] = lw_(R[29] + 40);  /* 0x800A82D0 */
    R[19] = lw_(R[29] + 36);  /* 0x800A82D4 */
    R[18] = lw_(R[29] + 32);  /* 0x800A82D8 */
    R[17] = lw_(R[29] + 28);  /* 0x800A82DC */
    R[16] = lw_(R[29] + 24);  /* 0x800A82E0 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A82E4 jr ra */
}

void g0_800A8224(void) {
    R[5] = R[30] + 40;  /* 0x800A8224 */
    R[4] = lw_(R[29] + 68);  /* 0x800A8228 */
    R[8] = R[0] + 9;  /* 0x800A822C */
    sb_(R[5] + 3, R[8]);  /* 0x800A8230 */
    R[8] = R[0] + 46;  /* 0x800A8234 */
    sb_(R[5] + 7, R[8]);  /* 0x800A8238 */
    sb_(R[5] + 4, R[16]);  /* 0x800A823C */
    sb_(R[5] + 5, R[16]);  /* 0x800A8240 */
    sb_(R[5] + 6, R[16]);  /* 0x800A8244 */
    R[6] = lh_(R[20] + 18);  /* 0x800A8248 */
    sh_(R[5] + 22, R[23]);  /* 0x800A824C */
    R[8] = lh_(R[29] + 16);  /* 0x800A8250 */
    R[3] = R[8] + 242;  /* 0x800A8258 */
    R[8] = R[0] + 182;  /* 0x800A825C */
    sh_(R[5] + 8, R[3]);  /* 0x800A8260 */
    sh_(R[5] + 10, R[8]);  /* 0x800A8264 */
    R[8] = lh_(R[29] + 16);  /* 0x800A8268 */
    R[2] = R[8] + 266;  /* 0x800A8270 */
    R[8] = R[0] + 182;  /* 0x800A8274 */
    sh_(R[5] + 16, R[2]);  /* 0x800A8278 */
    sh_(R[5] + 18, R[8]);  /* 0x800A827C */
    sh_(R[5] + 24, R[3]);  /* 0x800A8280 */
    sh_(R[5] + 26, R[21]);  /* 0x800A8284 */
    sh_(R[5] + 32, R[2]);  /* 0x800A8288 */
    sh_(R[5] + 34, R[21]);  /* 0x800A828C */
    sb_(R[5] + 12, R[22]);  /* 0x800A8290 */
    sb_(R[5] + 13, R[18]);  /* 0x800A8294 */
    sb_(R[5] + 20, R[19]);  /* 0x800A8298 */
    sb_(R[5] + 21, R[18]);  /* 0x800A829C */
    sb_(R[5] + 28, R[22]);  /* 0x800A82A0 */
    sb_(R[5] + 29, R[17]);  /* 0x800A82A4 */
    sb_(R[5] + 36, R[19]);  /* 0x800A82A8 */
    sb_(R[5] + 37, R[17]);  /* 0x800A82AC */
    { R[31] = 0x800A82B8u; sh_(R[5] + 14, R[6]); psx_next = 0x800356E8u; return; }  /* 0x800A82B0 jal */
    R[2] = R[30] + 80;  /* 0x800A82B8 */
    R[31] = lw_(R[29] + 60);  /* 0x800A82BC */
    R[30] = lw_(R[29] + 56);  /* 0x800A82C0 */
    R[23] = lw_(R[29] + 52);  /* 0x800A82C4 */
    R[22] = lw_(R[29] + 48);  /* 0x800A82C8 */
    R[21] = lw_(R[29] + 44);  /* 0x800A82CC */
    R[20] = lw_(R[29] + 40);  /* 0x800A82D0 */
    R[19] = lw_(R[29] + 36);  /* 0x800A82D4 */
    R[18] = lw_(R[29] + 32);  /* 0x800A82D8 */
    R[17] = lw_(R[29] + 28);  /* 0x800A82DC */
    R[16] = lw_(R[29] + 24);  /* 0x800A82E0 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A82E4 jr ra */
}

void g0_800A82B8(void) {
    R[2] = R[30] + 80;  /* 0x800A82B8 */
    R[31] = lw_(R[29] + 60);  /* 0x800A82BC */
    R[30] = lw_(R[29] + 56);  /* 0x800A82C0 */
    R[23] = lw_(R[29] + 52);  /* 0x800A82C4 */
    R[22] = lw_(R[29] + 48);  /* 0x800A82C8 */
    R[21] = lw_(R[29] + 44);  /* 0x800A82CC */
    R[20] = lw_(R[29] + 40);  /* 0x800A82D0 */
    R[19] = lw_(R[29] + 36);  /* 0x800A82D4 */
    R[18] = lw_(R[29] + 32);  /* 0x800A82D8 */
    R[17] = lw_(R[29] + 28);  /* 0x800A82DC */
    R[16] = lw_(R[29] + 24);  /* 0x800A82E0 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A82E4 jr ra */
}

void g0_800A82EC(void) {
    R[29] = R[29] - 24;  /* 0x800A82EC */
    R[8] = R[4] + R[0];  /* 0x800A82F0 */
    R[2] = lw_(R[29] + 40);  /* 0x800A82F4 */
    R[10] = lw_(R[29] + 44);  /* 0x800A82F8 */
    R[3] = lw_(R[29] + 48);  /* 0x800A82FC */
    R[11] = lw_(R[29] + 52);  /* 0x800A8300 */
    R[12] = R[5] + R[0];  /* 0x800A8304 */
    sw_(R[29] + 20, R[31]);  /* 0x800A8308 */
    sw_(R[29] + 16, R[16]);  /* 0x800A830C */
    { uint32_t _c = (R[6] == R[0]); R[9] = R[2] + R[0]; if (_c) { goto L_800A8320; } }  /* 0x800A8310 */
    R[2] = R[2] << 16;  /* 0x800A8318 */
    R[9] = R[2] >> 15;  /* 0x800A831C */
L_800A8320:;
    R[2] = 0x8006u << 16;  /* 0x800A8320 */
    R[2] = R[2] + 15308;  /* 0x800A8324 */
    R[2] = R[10] + R[2];  /* 0x800A8328 */
    R[5] = (uint32_t)(int8_t)lb_(R[2] + 88);  /* 0x800A832C */
    R[4] = R[0] - 1;  /* 0x800A8330 */
    { uint32_t _c = (R[5] != R[4]); R[2] = R[0] + 9; if (_c) { goto L_800A8344; } }  /* 0x800A8334 */
    { uint32_t _c = (R[11] == R[0]); if (_c) { goto L_800A85C0; } }  /* 0x800A833C */
L_800A8344:;
    sb_(R[8] + 3, R[2]);  /* 0x800A8344 */
    R[2] = R[0] + 44;  /* 0x800A8348 */
    R[16] = R[8] + R[0];  /* 0x800A834C */
    sb_(R[8] + 7, R[2]);  /* 0x800A8350 */
    sb_(R[8] + 4, R[3]);  /* 0x800A8354 */
    sb_(R[8] + 5, R[3]);  /* 0x800A8358 */
    { uint32_t _c = (R[5] != R[4]); sb_(R[8] + 6, R[3]); if (_c) { goto L_800A83D8; } }  /* 0x800A835C */
    R[2] = 0x8005u << 16;  /* 0x800A8364 */
    R[5] = lh_(R[2] + -870);  /* 0x800A8368 */
    R[2] = R[0] + 25;  /* 0x800A836C */
    R[4] = R[7] + 12;  /* 0x800A8370 */
    sh_(R[8] + 22, R[2]);  /* 0x800A8374 */
    R[2] = R[9] + 12;  /* 0x800A8378 */
    R[3] = R[7] + 20;  /* 0x800A837C */
    sh_(R[8] + 10, R[2]);  /* 0x800A8380 */
    sh_(R[8] + 18, R[2]);  /* 0x800A8384 */
    R[2] = R[9] + 20;  /* 0x800A8388 */
    sh_(R[8] + 26, R[2]);  /* 0x800A838C */
    sh_(R[8] + 34, R[2]);  /* 0x800A8390 */
    R[2] = R[0] + 232;  /* 0x800A8394 */
    sh_(R[8] + 16, R[3]);  /* 0x800A8398 */
    sh_(R[8] + 32, R[3]);  /* 0x800A839C */
    R[3] = R[0] + 8;  /* 0x800A83A0 */
    sb_(R[8] + 13, R[2]);  /* 0x800A83A4 */
    sb_(R[8] + 21, R[2]);  /* 0x800A83A8 */
    R[2] = R[0] + 240;  /* 0x800A83AC */
    sh_(R[8] + 8, R[4]);  /* 0x800A83B0 */
    sh_(R[8] + 24, R[4]);  /* 0x800A83B4 */
    sb_(R[8] + 12, R[0]);  /* 0x800A83B8 */
    sb_(R[8] + 20, R[3]);  /* 0x800A83BC */
    sb_(R[8] + 28, R[0]);  /* 0x800A83C0 */
    sb_(R[8] + 29, R[2]);  /* 0x800A83C4 */
    sb_(R[8] + 36, R[3]);  /* 0x800A83C8 */
    sb_(R[8] + 37, R[2]);  /* 0x800A83CC */
    { sh_(R[8] + 14, R[5]); goto L_800A85B0; }  /* 0x800A83D0 j */
L_800A83D8:;
    { uint32_t _c = (R[6] != R[0]); if (_c) { goto L_800A84C4; } }  /* 0x800A83D8 */
    { uint32_t _c = ((int32_t)R[10] >= 0); R[2] = R[10] + R[0]; if (_c) { goto L_800A83EC; } }  /* 0x800A83E0 */
    R[2] = R[10] + 15;  /* 0x800A83E8 */
L_800A83EC:;
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800A83EC */
    R[3] = R[2] + 501;  /* 0x800A83F0 */
    R[3] = R[3] << 6;  /* 0x800A83F4 */
    R[2] = R[2] << 4;  /* 0x800A83F8 */
    R[2] = R[10] - R[2];  /* 0x800A83FC */
    R[2] = R[2] << 4;  /* 0x800A8400 */
    R[2] = R[2] + 768;  /* 0x800A8404 */
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800A8408 */
    R[2] = R[2] & 0x3F;  /* 0x800A840C */
    R[3] = R[3] | R[2];  /* 0x800A8410 */
    R[2] = R[0] + 27;  /* 0x800A8414 */
    sh_(R[8] + 14, R[3]);  /* 0x800A8418 */
    { uint32_t _c = (R[11] == R[0]); sh_(R[8] + 22, R[2]); if (_c) { goto L_800A8444; } }  /* 0x800A841C */
    R[3] = R[7] + 32;  /* 0x800A8424 */
    R[2] = R[9] + 32;  /* 0x800A8428 */
    sh_(R[8] + 8, R[7]);  /* 0x800A842C */
    sh_(R[8] + 10, R[9]);  /* 0x800A8430 */
    sh_(R[8] + 16, R[3]);  /* 0x800A8434 */
    sh_(R[8] + 18, R[9]);  /* 0x800A8438 */
    { sh_(R[8] + 24, R[7]); goto L_800A8468; }  /* 0x800A843C j */
L_800A8444:;
    R[4] = R[7] + 4;  /* 0x800A8444 */
    R[2] = R[9] + 4;  /* 0x800A8448 */
    R[3] = R[7] + 28;  /* 0x800A844C */
    sh_(R[8] + 10, R[2]);  /* 0x800A8450 */
    sh_(R[8] + 18, R[2]);  /* 0x800A8454 */
    R[2] = R[9] + 28;  /* 0x800A8458 */
    sh_(R[8] + 8, R[4]);  /* 0x800A845C */
    sh_(R[8] + 16, R[3]);  /* 0x800A8460 */
    sh_(R[8] + 24, R[4]);  /* 0x800A8464 */
L_800A8468:;
    sh_(R[8] + 26, R[2]);  /* 0x800A8468 */
    sh_(R[8] + 32, R[3]);  /* 0x800A846C */
    sh_(R[8] + 34, R[2]);  /* 0x800A8470 */
    { uint32_t _c = ((int32_t)R[10] >= 0); R[3] = R[10] + R[0]; if (_c) { goto L_800A8480; } }  /* 0x800A8474 */
    R[3] = R[10] + 7;  /* 0x800A847C */
L_800A8480:;
    R[3] = (uint32_t)((int32_t)R[3] >> 3);  /* 0x800A8480 */
    R[2] = R[3] << 3;  /* 0x800A8484 */
    R[2] = R[10] - R[2];  /* 0x800A8488 */
    R[2] = R[2] << 5;  /* 0x800A848C */
    R[3] = R[3] << 5;  /* 0x800A8490 */
    R[4] = R[3] - 128;  /* 0x800A8494 */
    R[5] = R[2] + 31;  /* 0x800A8498 */
    R[3] = R[3] - 97;  /* 0x800A849C */
    sb_(R[16] + 12, R[2]);  /* 0x800A84A0 */
    sb_(R[16] + 13, R[4]);  /* 0x800A84A4 */
    sb_(R[16] + 20, R[5]);  /* 0x800A84A8 */
    sb_(R[16] + 21, R[4]);  /* 0x800A84AC */
    sb_(R[16] + 28, R[2]);  /* 0x800A84B0 */
    sb_(R[16] + 29, R[3]);  /* 0x800A84B4 */
    sb_(R[16] + 36, R[5]);  /* 0x800A84B8 */
    { sb_(R[16] + 37, R[3]); goto L_800A85B0; }  /* 0x800A84BC j */
L_800A84C4:;
    { uint32_t _c = ((int32_t)R[5] >= 0); R[2] = R[5] + R[0]; if (_c) { goto L_800A84D0; } }  /* 0x800A84C4 */
    R[2] = R[5] + 15;  /* 0x800A84CC */
L_800A84D0:;
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800A84D0 */
    R[3] = R[2] + 480;  /* 0x800A84D4 */
    R[3] = R[3] << 6;  /* 0x800A84D8 */
    R[2] = R[2] << 4;  /* 0x800A84DC */
    R[2] = R[5] - R[2];  /* 0x800A84E0 */
    R[2] = R[2] << 4;  /* 0x800A84E4 */
    R[2] = R[2] + 768;  /* 0x800A84E8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800A84EC */
    R[2] = R[2] & 0x3F;  /* 0x800A84F0 */
    R[3] = R[3] | R[2];  /* 0x800A84F4 */
    sh_(R[8] + 14, R[3]);  /* 0x800A84F8 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[2] = R[5] + R[0]; if (_c) { goto L_800A8508; } }  /* 0x800A84FC */
    R[2] = R[5] + 63;  /* 0x800A8504 */
L_800A8508:;
    R[6] = R[5] + R[0];  /* 0x800A8508 */
    R[2] = (uint32_t)((int32_t)R[2] >> 6);  /* 0x800A850C */
    R[10] = R[2] << 6;  /* 0x800A8510 */
    R[2] = R[10] + 576;  /* 0x800A8514 */
    R[2] = R[2] & 0x3FF;  /* 0x800A8518 */
    R[2] = (uint32_t)((int32_t)R[2] >> 6);  /* 0x800A851C */
    R[2] = R[2] | 0x10;  /* 0x800A8520 */
    R[4] = R[7] + 4;  /* 0x800A8524 */
    sh_(R[8] + 22, R[2]);  /* 0x800A8528 */
    R[2] = R[9] + 8;  /* 0x800A852C */
    R[3] = R[7] + 28;  /* 0x800A8530 */
    sh_(R[8] + 10, R[2]);  /* 0x800A8534 */
    sh_(R[8] + 18, R[2]);  /* 0x800A8538 */
    R[2] = R[9] + 56;  /* 0x800A853C */
    sh_(R[8] + 8, R[4]);  /* 0x800A8540 */
    sh_(R[8] + 16, R[3]);  /* 0x800A8544 */
    sh_(R[8] + 24, R[4]);  /* 0x800A8548 */
    sh_(R[8] + 26, R[2]);  /* 0x800A854C */
    sh_(R[8] + 32, R[3]);  /* 0x800A8550 */
    { uint32_t _c = ((int32_t)R[5] >= 0); sh_(R[8] + 34, R[2]); if (_c) { goto L_800A8560; } }  /* 0x800A8554 */
    R[6] = R[5] + 7;  /* 0x800A855C */
L_800A8560:;
    R[2] = (uint32_t)((int32_t)R[6] >> 3);  /* 0x800A8560 */
    R[2] = R[2] << 3;  /* 0x800A8564 */
    R[2] = R[5] - R[2];  /* 0x800A8568 */
    R[4] = R[2] << 5;  /* 0x800A856C */
    sb_(R[8] + 12, R[4]);  /* 0x800A8570 */
    R[3] = R[5] - R[10];  /* 0x800A8574 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[3] + R[0]; if (_c) { goto L_800A8584; } }  /* 0x800A8578 */
    R[2] = R[3] + 7;  /* 0x800A8580 */
L_800A8584:;
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800A8584 */
    R[2] = R[2] << 5;  /* 0x800A8588 */
    R[5] = R[4] + 31;  /* 0x800A858C */
    sb_(R[8] + 13, R[2]);  /* 0x800A8590 */
    sb_(R[8] + 20, R[5]);  /* 0x800A8594 */
    sb_(R[8] + 21, R[2]);  /* 0x800A8598 */
    sb_(R[8] + 28, R[4]);  /* 0x800A859C */
    R[2] = R[2] + 31;  /* 0x800A85A0 */
    sb_(R[8] + 29, R[2]);  /* 0x800A85A4 */
    sb_(R[8] + 36, R[5]);  /* 0x800A85A8 */
    sb_(R[8] + 37, R[2]);  /* 0x800A85AC */
L_800A85B0:;
    R[4] = R[12] + R[0];  /* 0x800A85B0 */
    { R[31] = 0x800A85BCu; R[5] = R[16] + R[0]; psx_next = 0x800356E8u; return; }  /* 0x800A85B4 jal */
    R[8] = R[16] + 40;  /* 0x800A85BC */
L_800A85C0:;
    R[31] = lw_(R[29] + 20);  /* 0x800A85C0 */
    R[16] = lw_(R[29] + 16);  /* 0x800A85C4 */
    R[2] = R[8] + R[0];  /* 0x800A85C8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A85CC jr ra */
}

void g0_800A85BC(void) {
    R[8] = R[16] + 40;  /* 0x800A85BC */
    R[31] = lw_(R[29] + 20);  /* 0x800A85C0 */
    R[16] = lw_(R[29] + 16);  /* 0x800A85C4 */
    R[2] = R[8] + R[0];  /* 0x800A85C8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A85CC jr ra */
}

void g0_800A85D4(void) {
    R[29] = R[29] - 40;  /* 0x800A85D4 */
    sw_(R[29] + 16, R[16]);  /* 0x800A85D8 */
    R[16] = R[4] + R[0];  /* 0x800A85DC */
    sw_(R[29] + 28, R[19]);  /* 0x800A85E0 */
    R[19] = R[5] + R[0];  /* 0x800A85E4 */
    R[4] = R[19] + R[0];  /* 0x800A85E8 */
    R[8] = lw_(R[29] + 56);  /* 0x800A85EC */
    R[2] = R[0] + 4;  /* 0x800A85F0 */
    sw_(R[29] + 32, R[31]);  /* 0x800A85F4 */
    sw_(R[29] + 24, R[18]);  /* 0x800A85F8 */
    sw_(R[29] + 20, R[17]);  /* 0x800A85FC */
    sb_(R[16] + 3, R[2]);  /* 0x800A8600 */
    R[2] = R[0] + 100;  /* 0x800A8604 */
    sb_(R[16] + 7, R[2]);  /* 0x800A8608 */
    R[3] = R[2] + R[0];  /* 0x800A860C */
    R[2] = R[0] + 128;  /* 0x800A8610 */
    R[3] = R[3] | 0x2;  /* 0x800A8614 */
    sb_(R[16] + 4, R[2]);  /* 0x800A8618 */
    sb_(R[16] + 5, R[2]);  /* 0x800A861C */
    sb_(R[16] + 6, R[2]);  /* 0x800A8620 */
    R[2] = 0x8005u << 16;  /* 0x800A8624 */
    R[5] = R[16] + R[0];  /* 0x800A8628 */
    R[18] = 0x8013u << 16;  /* 0x800A862C */
    sb_(R[16] + 7, R[3]);  /* 0x800A8630 */
    R[6] = lh_(R[2] + -870);  /* 0x800A8634 */
    R[3] = lw_(R[18] + -18712);  /* 0x800A8638 */
    R[2] = R[0] + 200;  /* 0x800A863C */
    sb_(R[16] + 13, R[2]);  /* 0x800A8640 */
    R[2] = R[0] + 32;  /* 0x800A8644 */
    sh_(R[16] + 8, R[7]);  /* 0x800A8648 */
    sh_(R[16] + 16, R[2]);  /* 0x800A864C */
    sh_(R[16] + 18, R[2]);  /* 0x800A8650 */
    R[3] = R[3] << 5;  /* 0x800A8654 */
    sh_(R[16] + 10, R[8]);  /* 0x800A8658 */
    sh_(R[16] + 14, R[6]);  /* 0x800A865C */
    { R[31] = 0x800A8668u; sb_(R[16] + 12, R[3]); psx_next = 0x800356E8u; return; }  /* 0x800A8660 jal */
    R[17] = R[16] + 20;  /* 0x800A8668 */
    R[4] = R[17] + R[0];  /* 0x800A866C */
    R[5] = R[0] + 1;  /* 0x800A8670 */
    R[6] = R[5] + R[0];  /* 0x800A8674 */
    { R[31] = 0x800A8680u; R[7] = R[0] + 57; psx_next = 0x80035878u; return; }  /* 0x800A8678 jal */
    R[4] = R[19] + R[0];  /* 0x800A8680 */
    { R[31] = 0x800A868Cu; R[5] = R[17] + R[0]; psx_next = 0x800356E8u; return; }  /* 0x800A8684 jal */
    R[2] = lw_(R[18] + -18712);  /* 0x800A868C */
    R[31] = lw_(R[29] + 32);  /* 0x800A8690 */
    R[19] = lw_(R[29] + 28);  /* 0x800A8694 */
    R[17] = lw_(R[29] + 20);  /* 0x800A8698 */
    R[2] = R[2] + 1;  /* 0x800A869C */
    R[2] = R[2] & 0x3;  /* 0x800A86A0 */
    sw_(R[18] + -18712, R[2]);  /* 0x800A86A4 */
    R[2] = R[16] + 28;  /* 0x800A86A8 */
    R[18] = lw_(R[29] + 24);  /* 0x800A86AC */
    R[16] = lw_(R[29] + 16);  /* 0x800A86B0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A86B4 jr ra */
}

void g0_800A8668(void) {
    R[17] = R[16] + 20;  /* 0x800A8668 */
    R[4] = R[17] + R[0];  /* 0x800A866C */
    R[5] = R[0] + 1;  /* 0x800A8670 */
    R[6] = R[5] + R[0];  /* 0x800A8674 */
    { R[31] = 0x800A8680u; R[7] = R[0] + 57; psx_next = 0x80035878u; return; }  /* 0x800A8678 jal */
    R[4] = R[19] + R[0];  /* 0x800A8680 */
    { R[31] = 0x800A868Cu; R[5] = R[17] + R[0]; psx_next = 0x800356E8u; return; }  /* 0x800A8684 jal */
    R[2] = lw_(R[18] + -18712);  /* 0x800A868C */
    R[31] = lw_(R[29] + 32);  /* 0x800A8690 */
    R[19] = lw_(R[29] + 28);  /* 0x800A8694 */
    R[17] = lw_(R[29] + 20);  /* 0x800A8698 */
    R[2] = R[2] + 1;  /* 0x800A869C */
    R[2] = R[2] & 0x3;  /* 0x800A86A0 */
    sw_(R[18] + -18712, R[2]);  /* 0x800A86A4 */
    R[2] = R[16] + 28;  /* 0x800A86A8 */
    R[18] = lw_(R[29] + 24);  /* 0x800A86AC */
    R[16] = lw_(R[29] + 16);  /* 0x800A86B0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A86B4 jr ra */
}

void g0_800A8680(void) {
    R[4] = R[19] + R[0];  /* 0x800A8680 */
    { R[31] = 0x800A868Cu; R[5] = R[17] + R[0]; psx_next = 0x800356E8u; return; }  /* 0x800A8684 jal */
    R[2] = lw_(R[18] + -18712);  /* 0x800A868C */
    R[31] = lw_(R[29] + 32);  /* 0x800A8690 */
    R[19] = lw_(R[29] + 28);  /* 0x800A8694 */
    R[17] = lw_(R[29] + 20);  /* 0x800A8698 */
    R[2] = R[2] + 1;  /* 0x800A869C */
    R[2] = R[2] & 0x3;  /* 0x800A86A0 */
    sw_(R[18] + -18712, R[2]);  /* 0x800A86A4 */
    R[2] = R[16] + 28;  /* 0x800A86A8 */
    R[18] = lw_(R[29] + 24);  /* 0x800A86AC */
    R[16] = lw_(R[29] + 16);  /* 0x800A86B0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A86B4 jr ra */
}

void g0_800A868C(void) {
    R[2] = lw_(R[18] + -18712);  /* 0x800A868C */
    R[31] = lw_(R[29] + 32);  /* 0x800A8690 */
    R[19] = lw_(R[29] + 28);  /* 0x800A8694 */
    R[17] = lw_(R[29] + 20);  /* 0x800A8698 */
    R[2] = R[2] + 1;  /* 0x800A869C */
    R[2] = R[2] & 0x3;  /* 0x800A86A0 */
    sw_(R[18] + -18712, R[2]);  /* 0x800A86A4 */
    R[2] = R[16] + 28;  /* 0x800A86A8 */
    R[18] = lw_(R[29] + 24);  /* 0x800A86AC */
    R[16] = lw_(R[29] + 16);  /* 0x800A86B0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A86B4 jr ra */
}

void g0_800A86BC(void) {
#ifdef A2_HUD_PRESENT
    a2_hud_present_group(R[4],320);
#endif
    R[29] = R[29] - 56;  /* 0x800A86BC */
    sw_(R[29] + 16, R[16]);  /* 0x800A86C0 */
    R[16] = R[4] + R[0];  /* 0x800A86C4 */
    sw_(R[29] + 44, R[23]);  /* 0x800A86C8 */
    R[23] = R[5] + R[0];  /* 0x800A86CC */
    sw_(R[29] + 40, R[22]);  /* 0x800A86D0 */
    R[22] = R[6] + R[0];  /* 0x800A86D4 */
    sw_(R[29] + 32, R[20]);  /* 0x800A86D8 */
    R[20] = R[7] + R[0];  /* 0x800A86DC */
    sw_(R[29] + 36, R[21]);  /* 0x800A86E0 */
    R[21] = R[16] + R[0];  /* 0x800A86E4 */
    sw_(R[29] + 20, R[17]);  /* 0x800A86E8 */
    R[17] = R[0] + 12;  /* 0x800A86EC */
    sw_(R[29] + 48, R[31]);  /* 0x800A86F0 */
    sw_(R[29] + 28, R[19]);  /* 0x800A86F4 */
    { uint32_t _c = (R[22] == R[0]); sw_(R[29] + 24, R[18]); if (_c) { goto L_800A8704; } }  /* 0x800A86F8 */
    R[17] = R[0] + 24;  /* 0x800A8700 */
L_800A8704:;
    { R[31] = 0x800A870Cu; R[18] = R[0] + 32305; psx_next = 0x80023DC4u; return; }  /* 0x800A8704 jal */
    R[3] = R[2] + R[0];  /* 0x800A870C */
    R[2] = R[0] + 23;  /* 0x800A8710 */
    { uint32_t _c = (R[3] != R[2]); R[19] = R[20] + 272; if (_c) { goto L_800A8720; } }  /* 0x800A8714 */
    R[18] = R[0] + 32313;  /* 0x800A871C */
L_800A8720:;
    R[2] = R[0] + 25;  /* 0x800A8720 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 24; if (_c) { goto L_800A8730; } }  /* 0x800A8724 */
    R[18] = R[0] + 32314;  /* 0x800A872C */
L_800A8730:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 26; if (_c) { goto L_800A873C; } }  /* 0x800A8730 */
    R[18] = R[0] + 32315;  /* 0x800A8738 */
L_800A873C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 9; if (_c) { goto L_800A8748; } }  /* 0x800A873C */
    R[18] = R[0] + 32316;  /* 0x800A8744 */
L_800A8748:;
    sb_(R[16] + 3, R[2]);  /* 0x800A8748 */
    R[2] = R[0] + 44;  /* 0x800A874C */
    sb_(R[16] + 7, R[2]);  /* 0x800A8750 */
    R[2] = R[0] + 128;  /* 0x800A8754 */
    sb_(R[16] + 4, R[2]);  /* 0x800A8758 */
    sb_(R[16] + 5, R[2]);  /* 0x800A875C */
    sb_(R[16] + 6, R[2]);  /* 0x800A8760 */
    R[2] = lb_(R[16] + 7);  /* 0x800A8764 */
    R[3] = R[0] + 59;  /* 0x800A8768 */
    sh_(R[16] + 14, R[18]);  /* 0x800A876C */
    sh_(R[16] + 22, R[3]);  /* 0x800A8770 */
    R[2] = R[2] | 0x2;  /* 0x800A8774 */
    { uint32_t _c = (R[22] != R[0]); sb_(R[16] + 7, R[2]); if (_c) { goto L_800A87B4; } }  /* 0x800A8778 */
    R[3] = R[20] + 304;  /* 0x800A8780 */
    R[2] = R[17] + 32;  /* 0x800A8784 */
    R[4] = R[0] + 56;  /* 0x800A8788 */
    sh_(R[16] + 26, R[2]);  /* 0x800A878C */
    sh_(R[16] + 34, R[2]);  /* 0x800A8790 */
    R[2] = R[0] + 72;  /* 0x800A8794 */
    sh_(R[16] + 16, R[3]);  /* 0x800A8798 */
    sh_(R[16] + 32, R[3]);  /* 0x800A879C */
    R[3] = R[0] + 88;  /* 0x800A87A0 */
    sb_(R[16] + 13, R[2]);  /* 0x800A87A4 */
    sb_(R[16] + 21, R[2]);  /* 0x800A87A8 */
    { R[2] = R[0] + 104; goto L_800A87E4; }  /* 0x800A87AC j */
L_800A87B4:;
    R[3] = R[20] + 304;  /* 0x800A87B4 */
    R[2] = R[17] + 64;  /* 0x800A87B8 */
    R[4] = R[0] + 56;  /* 0x800A87BC */
    sh_(R[16] + 26, R[2]);  /* 0x800A87C0 */
    sh_(R[16] + 34, R[2]);  /* 0x800A87C4 */
    R[2] = R[0] + 72;  /* 0x800A87C8 */
    sh_(R[16] + 16, R[3]);  /* 0x800A87CC */
    sh_(R[16] + 32, R[3]);  /* 0x800A87D0 */
    R[3] = R[0] + 88;  /* 0x800A87D4 */
    sb_(R[16] + 13, R[2]);  /* 0x800A87D8 */
    sb_(R[16] + 21, R[2]);  /* 0x800A87DC */
    R[2] = R[0] + 103;  /* 0x800A87E0 */
L_800A87E4:;
    sh_(R[16] + 8, R[19]);  /* 0x800A87E4 */
    sh_(R[16] + 10, R[17]);  /* 0x800A87E8 */
    sh_(R[16] + 18, R[17]);  /* 0x800A87EC */
    sh_(R[16] + 24, R[19]);  /* 0x800A87F0 */
    sb_(R[16] + 12, R[4]);  /* 0x800A87F4 */
    sb_(R[16] + 20, R[3]);  /* 0x800A87F8 */
    sb_(R[16] + 28, R[4]);  /* 0x800A87FC */
    sb_(R[16] + 29, R[2]);  /* 0x800A8800 */
    sb_(R[16] + 36, R[3]);  /* 0x800A8804 */
    sb_(R[16] + 37, R[2]);  /* 0x800A8808 */
    R[4] = 0xFFu << 16;  /* 0x800A880C */
    R[4] = R[4] | 0xFFFF;  /* 0x800A8810 */
    R[5] = 0xFF00u << 16;  /* 0x800A8814 */
    R[3] = lw_(R[21]);  /* 0x800A8818 */
    R[2] = lw_(R[23]);  /* 0x800A881C */
    R[3] = R[3] & R[5];  /* 0x800A8820 */
    R[2] = R[2] & R[4];  /* 0x800A8824 */
    R[3] = R[3] | R[2];  /* 0x800A8828 */
    R[2] = R[21] + 80;  /* 0x800A882C */
    sw_(R[21], R[3]);  /* 0x800A8830 */
    R[3] = lw_(R[23]);  /* 0x800A8834 */
    R[4] = R[21] & R[4];  /* 0x800A8838 */
    R[3] = R[3] & R[5];  /* 0x800A883C */
    R[3] = R[3] | R[4];  /* 0x800A8840 */
    sw_(R[23], R[3]);  /* 0x800A8844 */
    R[31] = lw_(R[29] + 48);  /* 0x800A8848 */
    R[23] = lw_(R[29] + 44);  /* 0x800A884C */
    R[22] = lw_(R[29] + 40);  /* 0x800A8850 */
    R[21] = lw_(R[29] + 36);  /* 0x800A8854 */
    R[20] = lw_(R[29] + 32);  /* 0x800A8858 */
    R[19] = lw_(R[29] + 28);  /* 0x800A885C */
    R[18] = lw_(R[29] + 24);  /* 0x800A8860 */
    R[17] = lw_(R[29] + 20);  /* 0x800A8864 */
    R[16] = lw_(R[29] + 16);  /* 0x800A8868 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800A886C jr ra */
}

void g0_800A870C(void) {
    R[3] = R[2] + R[0];  /* 0x800A870C */
    R[2] = R[0] + 23;  /* 0x800A8710 */
    { uint32_t _c = (R[3] != R[2]); R[19] = R[20] + 272; if (_c) { goto L_800A8720; } }  /* 0x800A8714 */
    R[18] = R[0] + 32313;  /* 0x800A871C */
L_800A8720:;
    R[2] = R[0] + 25;  /* 0x800A8720 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 24; if (_c) { goto L_800A8730; } }  /* 0x800A8724 */
    R[18] = R[0] + 32314;  /* 0x800A872C */
L_800A8730:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 26; if (_c) { goto L_800A873C; } }  /* 0x800A8730 */
    R[18] = R[0] + 32315;  /* 0x800A8738 */
L_800A873C:;
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 9; if (_c) { goto L_800A8748; } }  /* 0x800A873C */
    R[18] = R[0] + 32316;  /* 0x800A8744 */
L_800A8748:;
    sb_(R[16] + 3, R[2]);  /* 0x800A8748 */
    R[2] = R[0] + 44;  /* 0x800A874C */
    sb_(R[16] + 7, R[2]);  /* 0x800A8750 */
    R[2] = R[0] + 128;  /* 0x800A8754 */
    sb_(R[16] + 4, R[2]);  /* 0x800A8758 */
    sb_(R[16] + 5, R[2]);  /* 0x800A875C */
    sb_(R[16] + 6, R[2]);  /* 0x800A8760 */
    R[2] = lb_(R[16] + 7);  /* 0x800A8764 */
    R[3] = R[0] + 59;  /* 0x800A8768 */
    sh_(R[16] + 14, R[18]);  /* 0x800A876C */
    sh_(R[16] + 22, R[3]);  /* 0x800A8770 */
    R[2] = R[2] | 0x2;  /* 0x800A8774 */
    { uint32_t _c = (R[22] != R[0]); sb_(R[16] + 7, R[2]); if (_c) { goto L_800A87B4; } }  /* 0x800A8778 */
    R[3] = R[20] + 304;  /* 0x800A8780 */
    R[2] = R[17] + 32;  /* 0x800A8784 */
    R[4] = R[0] + 56;  /* 0x800A8788 */
    sh_(R[16] + 26, R[2]);  /* 0x800A878C */
    sh_(R[16] + 34, R[2]);  /* 0x800A8790 */
    R[2] = R[0] + 72;  /* 0x800A8794 */
    sh_(R[16] + 16, R[3]);  /* 0x800A8798 */
    sh_(R[16] + 32, R[3]);  /* 0x800A879C */
    R[3] = R[0] + 88;  /* 0x800A87A0 */
    sb_(R[16] + 13, R[2]);  /* 0x800A87A4 */
    sb_(R[16] + 21, R[2]);  /* 0x800A87A8 */
    { R[2] = R[0] + 104; goto L_800A87E4; }  /* 0x800A87AC j */
L_800A87B4:;
    R[3] = R[20] + 304;  /* 0x800A87B4 */
    R[2] = R[17] + 64;  /* 0x800A87B8 */
    R[4] = R[0] + 56;  /* 0x800A87BC */
    sh_(R[16] + 26, R[2]);  /* 0x800A87C0 */
    sh_(R[16] + 34, R[2]);  /* 0x800A87C4 */
    R[2] = R[0] + 72;  /* 0x800A87C8 */
    sh_(R[16] + 16, R[3]);  /* 0x800A87CC */
    sh_(R[16] + 32, R[3]);  /* 0x800A87D0 */
    R[3] = R[0] + 88;  /* 0x800A87D4 */
    sb_(R[16] + 13, R[2]);  /* 0x800A87D8 */
    sb_(R[16] + 21, R[2]);  /* 0x800A87DC */
    R[2] = R[0] + 103;  /* 0x800A87E0 */
L_800A87E4:;
    sh_(R[16] + 8, R[19]);  /* 0x800A87E4 */
    sh_(R[16] + 10, R[17]);  /* 0x800A87E8 */
    sh_(R[16] + 18, R[17]);  /* 0x800A87EC */
    sh_(R[16] + 24, R[19]);  /* 0x800A87F0 */
    sb_(R[16] + 12, R[4]);  /* 0x800A87F4 */
    sb_(R[16] + 20, R[3]);  /* 0x800A87F8 */
    sb_(R[16] + 28, R[4]);  /* 0x800A87FC */
    sb_(R[16] + 29, R[2]);  /* 0x800A8800 */
    sb_(R[16] + 36, R[3]);  /* 0x800A8804 */
    sb_(R[16] + 37, R[2]);  /* 0x800A8808 */
    R[4] = 0xFFu << 16;  /* 0x800A880C */
    R[4] = R[4] | 0xFFFF;  /* 0x800A8810 */
    R[5] = 0xFF00u << 16;  /* 0x800A8814 */
    R[3] = lw_(R[21]);  /* 0x800A8818 */
    R[2] = lw_(R[23]);  /* 0x800A881C */
    R[3] = R[3] & R[5];  /* 0x800A8820 */
    R[2] = R[2] & R[4];  /* 0x800A8824 */
    R[3] = R[3] | R[2];  /* 0x800A8828 */
    R[2] = R[21] + 80;  /* 0x800A882C */
    sw_(R[21], R[3]);  /* 0x800A8830 */
    R[3] = lw_(R[23]);  /* 0x800A8834 */
    R[4] = R[21] & R[4];  /* 0x800A8838 */
    R[3] = R[3] & R[5];  /* 0x800A883C */
    R[3] = R[3] | R[4];  /* 0x800A8840 */
    sw_(R[23], R[3]);  /* 0x800A8844 */
    R[31] = lw_(R[29] + 48);  /* 0x800A8848 */
    R[23] = lw_(R[29] + 44);  /* 0x800A884C */
    R[22] = lw_(R[29] + 40);  /* 0x800A8850 */
    R[21] = lw_(R[29] + 36);  /* 0x800A8854 */
    R[20] = lw_(R[29] + 32);  /* 0x800A8858 */
    R[19] = lw_(R[29] + 28);  /* 0x800A885C */
    R[18] = lw_(R[29] + 24);  /* 0x800A8860 */
    R[17] = lw_(R[29] + 20);  /* 0x800A8864 */
    R[16] = lw_(R[29] + 16);  /* 0x800A8868 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800A886C jr ra */
}

void g0_800A8874(void) {
    R[8] = R[4] + R[0];  /* 0x800A8874 */
    R[10] = R[5] + R[0];  /* 0x800A8878 */
    R[9] = R[8] + R[0];  /* 0x800A887C */
    R[3] = lw_(R[29] + 20);  /* 0x800A8880 */
    R[2] = lw_(R[29] + 16);  /* 0x800A8884 */
    R[5] = R[2] + R[7];  /* 0x800A888C */
    R[7] = lw_(R[29] + 24);  /* 0x800A8890 */
    { uint32_t _c = (R[6] == R[0]); R[4] = R[3] + R[0]; if (_c) { goto L_800A88A4; } }  /* 0x800A8894 */
    R[2] = R[3] << 16;  /* 0x800A889C */
    R[4] = R[2] >> 15;  /* 0x800A88A0 */
L_800A88A4:;
    R[2] = R[0] + 9;  /* 0x800A88A4 */
    sb_(R[8] + 3, R[2]);  /* 0x800A88A8 */
    R[2] = R[0] + 44;  /* 0x800A88AC */
    sb_(R[8] + 7, R[2]);  /* 0x800A88B0 */
    R[2] = R[0] + 128;  /* 0x800A88B4 */
    sb_(R[8] + 4, R[2]);  /* 0x800A88B8 */
    sb_(R[8] + 5, R[2]);  /* 0x800A88BC */
    sb_(R[8] + 6, R[2]);  /* 0x800A88C0 */
    R[2] = R[0] + 32311;  /* 0x800A88C4 */
    sh_(R[8] + 14, R[2]);  /* 0x800A88C8 */
    R[2] = R[0] + 27;  /* 0x800A88CC */
    { uint32_t _c = (R[6] != R[0]); sh_(R[8] + 22, R[2]); if (_c) { goto L_800A8928; } }  /* 0x800A88D0 */
    R[3] = R[5] + 6;  /* 0x800A88D8 */
    R[2] = R[4] + 8;  /* 0x800A88DC */
    sh_(R[8] + 26, R[2]);  /* 0x800A88E0 */
    sh_(R[8] + 34, R[2]);  /* 0x800A88E4 */
    R[2] = R[7] << 16;  /* 0x800A88E8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A88EC */
    R[2] = R[2] + 1;  /* 0x800A88F0 */
    sh_(R[8] + 16, R[3]);  /* 0x800A88F4 */
    sh_(R[8] + 32, R[3]);  /* 0x800A88F8 */
    R[3] = R[2] << 1;  /* 0x800A88FC */
    R[3] = R[3] + R[2];  /* 0x800A8900 */
    R[3] = R[3] << 1;  /* 0x800A8904 */
    R[2] = R[0] + 112;  /* 0x800A8908 */
    sh_(R[8] + 10, R[4]);  /* 0x800A890C */
    sh_(R[8] + 18, R[4]);  /* 0x800A8910 */
    R[4] = R[3] + 6;  /* 0x800A8914 */
    sb_(R[8] + 13, R[2]);  /* 0x800A8918 */
    sb_(R[8] + 21, R[2]);  /* 0x800A891C */
    { R[2] = R[0] + 120; goto L_800A8974; }  /* 0x800A8920 j */
L_800A8928:;
    R[3] = R[5] + 6;  /* 0x800A8928 */
    R[2] = R[4] + 16;  /* 0x800A892C */
    sh_(R[8] + 26, R[2]);  /* 0x800A8930 */
    sh_(R[8] + 34, R[2]);  /* 0x800A8934 */
    R[2] = R[7] << 16;  /* 0x800A8938 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A893C */
    R[2] = R[2] + 1;  /* 0x800A8940 */
    sh_(R[8] + 16, R[3]);  /* 0x800A8944 */
    sh_(R[8] + 32, R[3]);  /* 0x800A8948 */
    R[3] = R[2] << 1;  /* 0x800A894C */
    R[3] = R[3] + R[2];  /* 0x800A8950 */
    R[3] = R[3] << 1;  /* 0x800A8954 */
    R[2] = R[0] + 112;  /* 0x800A8958 */
    sh_(R[8] + 10, R[4]);  /* 0x800A895C */
    sh_(R[8] + 18, R[4]);  /* 0x800A8960 */
    R[4] = R[3] + 6;  /* 0x800A8964 */
    sb_(R[8] + 13, R[2]);  /* 0x800A8968 */
    sb_(R[8] + 21, R[2]);  /* 0x800A896C */
    R[2] = R[0] + 119;  /* 0x800A8970 */
L_800A8974:;
    sh_(R[8] + 8, R[5]);  /* 0x800A8974 */
    sh_(R[8] + 24, R[5]);  /* 0x800A8978 */
    sb_(R[8] + 12, R[3]);  /* 0x800A897C */
    sb_(R[8] + 20, R[4]);  /* 0x800A8980 */
    sb_(R[8] + 28, R[3]);  /* 0x800A8984 */
    sb_(R[8] + 29, R[2]);  /* 0x800A8988 */
    sb_(R[8] + 36, R[4]);  /* 0x800A898C */
    sb_(R[8] + 37, R[2]);  /* 0x800A8990 */
    R[4] = 0xFFu << 16;  /* 0x800A8994 */
    R[4] = R[4] | 0xFFFF;  /* 0x800A8998 */
    R[5] = 0xFF00u << 16;  /* 0x800A899C */
    R[3] = lw_(R[9]);  /* 0x800A89A0 */
    R[2] = lw_(R[10]);  /* 0x800A89A4 */
    R[3] = R[3] & R[5];  /* 0x800A89A8 */
    R[2] = R[2] & R[4];  /* 0x800A89AC */
    R[3] = R[3] | R[2];  /* 0x800A89B0 */
    sw_(R[9], R[3]);  /* 0x800A89B4 */
    R[2] = lw_(R[10]);  /* 0x800A89B8 */
    R[4] = R[9] & R[4];  /* 0x800A89BC */
    R[2] = R[2] & R[5];  /* 0x800A89C0 */
    R[2] = R[2] | R[4];  /* 0x800A89C4 */
    sw_(R[10], R[2]);  /* 0x800A89C8 */
    { R[2] = R[9] + 40; psx_next = R[31]; return; }  /* 0x800A89CC jr ra */
}

void g0_800A89D4(void) {
    R[29] = R[29] - 40;  /* 0x800A89D4 */
    R[2] = 0x8006u << 16;  /* 0x800A89D8 */
    R[2] = R[2] + 13192;  /* 0x800A89DC */
    sw_(R[29] + 32, R[31]);  /* 0x800A89E0 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 2842);  /* 0x800A89E4 */
    R[8] = R[2] + 2116;  /* 0x800A89E8 */
    R[3] = R[3] + R[8];  /* 0x800A89EC */
    R[3] = (uint32_t)(int8_t)lb_(R[3] + 88);  /* 0x800A89F0 */
    R[2] = R[0] - 1;  /* 0x800A89F4 */
    { uint32_t _c = (R[3] == R[2]); R[3] = R[3] + R[8]; if (_c) { goto L_800A8A34; } }  /* 0x800A89F8 */
    R[2] = lb_(R[3]);  /* 0x800A8A00 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 302; if (_c) { goto L_800A8A34; } }  /* 0x800A8A08 */
    sw_(R[29] + 16, R[2]);  /* 0x800A8A10 */
    R[2] = R[0] + 38;  /* 0x800A8A14 */
    R[7] = R[7] << 16;  /* 0x800A8A18 */
    sw_(R[29] + 20, R[2]);  /* 0x800A8A1C */
    R[2] = lb_(R[3]);  /* 0x800A8A20 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A8A24 */
    { R[31] = 0x800A8A30u; sw_(R[29] + 24, R[2]); psx_next = 0x800A8874u; return; }  /* 0x800A8A28 jal */
    R[4] = R[2] + R[0];  /* 0x800A8A30 */
L_800A8A34:;
    R[31] = lw_(R[29] + 32);  /* 0x800A8A34 */
    R[2] = R[4] + R[0];  /* 0x800A8A38 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A8A3C jr ra */
}

void g0_800A8A30(void) {
    R[4] = R[2] + R[0];  /* 0x800A8A30 */
    R[31] = lw_(R[29] + 32);  /* 0x800A8A34 */
    R[2] = R[4] + R[0];  /* 0x800A8A38 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A8A3C jr ra */
}

void g0_800A8A44(void) {
    R[29] = R[29] - 72;  /* 0x800A8A44 */
    sw_(R[29] + 48, R[20]);  /* 0x800A8A48 */
    R[20] = R[4] + R[0];  /* 0x800A8A4C */
    sw_(R[29] + 60, R[23]);  /* 0x800A8A50 */
    R[23] = R[5] + R[0];  /* 0x800A8A54 */
    sw_(R[29] + 64, R[30]);  /* 0x800A8A58 */
    R[30] = R[6] + R[0];  /* 0x800A8A5C */
    sw_(R[29] + 56, R[22]);  /* 0x800A8A60 */
    R[22] = R[7] + R[0];  /* 0x800A8A64 */
    sw_(R[29] + 68, R[31]);  /* 0x800A8A68 */
    sw_(R[29] + 52, R[21]);  /* 0x800A8A6C */
    sw_(R[29] + 44, R[19]);  /* 0x800A8A70 */
    sw_(R[29] + 40, R[18]);  /* 0x800A8A74 */
    sw_(R[29] + 36, R[17]);  /* 0x800A8A78 */
    { R[31] = 0x800A8A84u; sw_(R[29] + 32, R[16]); psx_next = 0x8001D050u; return; }  /* 0x800A8A7C jal */
    R[17] = R[2] + R[0];  /* 0x800A8A84 */
    R[3] = 0x6666u << 16;  /* 0x800A8A88 */
    R[5] = 0x8013u << 16;  /* 0x800A8A8C */
    R[4] = lw_(R[5] + -18708);  /* 0x800A8A90 */
    R[3] = R[3] | 0x6667;  /* 0x800A8A94 */
    R[2] = R[4] - R[17];  /* 0x800A8A98 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A8A9C */
    R[2] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x800A8AA0 */
    R[8] = HI;  /* 0x800A8AA4 */
    R[3] = (uint32_t)((int32_t)R[8] >> 3);  /* 0x800A8AA8 */
    R[3] = R[3] - R[2];  /* 0x800A8AAC */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800A8ABC; } }  /* 0x800A8AB0 */
    R[3] = R[0] - R[3];  /* 0x800A8AB8 */
L_800A8ABC:;
    { uint32_t _c = (R[3] != R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[17]); if (_c) { goto L_800A8AC8; } }  /* 0x800A8ABC */
    R[3] = R[0] + 5;  /* 0x800A8AC4 */
L_800A8AC8:;
    { uint32_t _c = (R[2] == R[0]); R[2] = R[4] + R[3]; if (_c) { goto L_800A8ADC; } }  /* 0x800A8AC8 */
    sw_(R[5] + -18708, R[2]);  /* 0x800A8AD0 */
    { R[2] = ((int32_t)R[17] < (int32_t)R[2]); goto L_800A8AF0; }  /* 0x800A8AD4 j */
L_800A8ADC:;
    R[2] = ((int32_t)R[17] < (int32_t)R[4]);  /* 0x800A8ADC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[4] - R[3]; if (_c) { goto L_800A8B1C; } }  /* 0x800A8AE0 */
    sw_(R[5] + -18708, R[2]);  /* 0x800A8AE8 */
    R[2] = ((int32_t)R[2] < (int32_t)R[17]);  /* 0x800A8AEC */
L_800A8AF0:;
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Fu << 16; if (_c) { goto L_800A8AFC; } }  /* 0x800A8AF0 */
    sw_(R[5] + -18708, R[17]);  /* 0x800A8AF8 */
L_800A8AFC:;
    R[2] = lw_(R[2] + 25520);  /* 0x800A8AFC */
    R[2] = R[2] & 0x1;  /* 0x800A8B04 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A8B20; } }  /* 0x800A8B08 */
    R[4] = R[0] + 75;  /* 0x800A8B10 */
    { R[31] = 0x800A8B1Cu; R[5] = R[0] + R[0]; psx_next = 0x8002DAE8u; return; }  /* 0x800A8B14 jal */
L_800A8B1C:;
    R[2] = 0x8013u << 16;  /* 0x800A8B1C */
L_800A8B20:;
    R[17] = lw_(R[2] + -18708);  /* 0x800A8B20 */
    R[18] = R[0] + 272;  /* 0x800A8B24 */
    R[16] = 0x1u << 16;  /* 0x800A8B28 */
    R[16] = R[16] | 0x86A0;  /* 0x800A8B2C */
    R[19] = R[0] + R[0];  /* 0x800A8B30 */
    R[21] = R[0] + 50;  /* 0x800A8B34 */
L_800A8B38:;
    psx_div((int32_t)R[17], (int32_t)R[16]);  /* 0x800A8B38 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800A8B48; } }  /* 0x800A8B3C */
    psx_break(7168);  /* 0x800A8B44 */
L_800A8B48:;
    R[1] = R[0] - 1;  /* 0x800A8B48 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800A8B60; } }  /* 0x800A8B4C */
    { uint32_t _c = (R[17] != R[1]); if (_c) { goto L_800A8B60; } }  /* 0x800A8B54 */
    psx_break(6144);  /* 0x800A8B5C */
L_800A8B60:;
    R[3] = LO;  /* 0x800A8B60 */
    R[17] = HI;  /* 0x800A8B64 */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_800A8B74; } }  /* 0x800A8B68 */
    R[19] = R[0] + 1;  /* 0x800A8B70 */
L_800A8B74:;
    { uint32_t _c = (R[19] != R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A8B8C; } }  /* 0x800A8B74 */
    R[2] = R[0] + 1;  /* 0x800A8B7C */
    { uint32_t _c = (R[16] != R[2]); R[2] = 0x6666u << 16; if (_c) { goto L_800A8BC4; } }  /* 0x800A8B80 */
    R[4] = R[20] + R[0];  /* 0x800A8B88 */
L_800A8B8C:;
    R[5] = R[23] + R[0];  /* 0x800A8B8C */
    R[2] = R[18] << 16;  /* 0x800A8B90 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8B94 */
    sw_(R[29] + 16, R[2]);  /* 0x800A8B98 */
    R[2] = R[3] << 16;  /* 0x800A8B9C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8BA0 */
    R[7] = R[22] << 16;  /* 0x800A8BA4 */
    R[6] = R[30] + R[0];  /* 0x800A8BA8 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A8BAC */
    sw_(R[29] + 20, R[21]);  /* 0x800A8BB0 */
    { R[31] = 0x800A8BBCu; sw_(R[29] + 24, R[2]); psx_next = 0x800A8874u; return; }  /* 0x800A8BB4 jal */
    R[20] = R[2] + R[0];  /* 0x800A8BBC */
    R[2] = 0x6666u << 16;  /* 0x800A8BC0 */
L_800A8BC4:;
    R[2] = R[2] | 0x6667;  /* 0x800A8BC4 */
    { int64_t _p = (int64_t)(int32_t)R[16] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A8BC8 */
    R[2] = (uint32_t)((int32_t)R[16] >> 31);  /* 0x800A8BCC */
    R[8] = HI;  /* 0x800A8BD0 */
    R[3] = (uint32_t)((int32_t)R[8] >> 2);  /* 0x800A8BD4 */
    R[16] = R[3] - R[2];  /* 0x800A8BD8 */
    { uint32_t _c = (R[16] != R[0]); R[18] = R[18] + 6; if (_c) { psx_bb(); goto L_800A8B38; } }  /* 0x800A8BDC */
    R[2] = R[20] + R[0];  /* 0x800A8BE4 */
    R[31] = lw_(R[29] + 68);  /* 0x800A8BE8 */
    R[30] = lw_(R[29] + 64);  /* 0x800A8BEC */
    R[23] = lw_(R[29] + 60);  /* 0x800A8BF0 */
    R[22] = lw_(R[29] + 56);  /* 0x800A8BF4 */
    R[21] = lw_(R[29] + 52);  /* 0x800A8BF8 */
    R[20] = lw_(R[29] + 48);  /* 0x800A8BFC */
    R[19] = lw_(R[29] + 44);  /* 0x800A8C00 */
    R[18] = lw_(R[29] + 40);  /* 0x800A8C04 */
    R[17] = lw_(R[29] + 36);  /* 0x800A8C08 */
    R[16] = lw_(R[29] + 32);  /* 0x800A8C0C */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x800A8C10 jr ra */
}

void g0_800A8A84(void) {
    R[17] = R[2] + R[0];  /* 0x800A8A84 */
    R[3] = 0x6666u << 16;  /* 0x800A8A88 */
    R[5] = 0x8013u << 16;  /* 0x800A8A8C */
    R[4] = lw_(R[5] + -18708);  /* 0x800A8A90 */
    R[3] = R[3] | 0x6667;  /* 0x800A8A94 */
    R[2] = R[4] - R[17];  /* 0x800A8A98 */
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A8A9C */
    R[2] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x800A8AA0 */
    R[8] = HI;  /* 0x800A8AA4 */
    R[3] = (uint32_t)((int32_t)R[8] >> 3);  /* 0x800A8AA8 */
    R[3] = R[3] - R[2];  /* 0x800A8AAC */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800A8ABC; } }  /* 0x800A8AB0 */
    R[3] = R[0] - R[3];  /* 0x800A8AB8 */
L_800A8ABC:;
    { uint32_t _c = (R[3] != R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[17]); if (_c) { goto L_800A8AC8; } }  /* 0x800A8ABC */
    R[3] = R[0] + 5;  /* 0x800A8AC4 */
L_800A8AC8:;
    { uint32_t _c = (R[2] == R[0]); R[2] = R[4] + R[3]; if (_c) { goto L_800A8ADC; } }  /* 0x800A8AC8 */
    sw_(R[5] + -18708, R[2]);  /* 0x800A8AD0 */
    { R[2] = ((int32_t)R[17] < (int32_t)R[2]); goto L_800A8AF0; }  /* 0x800A8AD4 j */
L_800A8ADC:;
    R[2] = ((int32_t)R[17] < (int32_t)R[4]);  /* 0x800A8ADC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[4] - R[3]; if (_c) { goto L_800A8B1C; } }  /* 0x800A8AE0 */
    sw_(R[5] + -18708, R[2]);  /* 0x800A8AE8 */
    R[2] = ((int32_t)R[2] < (int32_t)R[17]);  /* 0x800A8AEC */
L_800A8AF0:;
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Fu << 16; if (_c) { goto L_800A8AFC; } }  /* 0x800A8AF0 */
    sw_(R[5] + -18708, R[17]);  /* 0x800A8AF8 */
L_800A8AFC:;
    R[2] = lw_(R[2] + 25520);  /* 0x800A8AFC */
    R[2] = R[2] & 0x1;  /* 0x800A8B04 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A8B20; } }  /* 0x800A8B08 */
    R[4] = R[0] + 75;  /* 0x800A8B10 */
    { R[31] = 0x800A8B1Cu; R[5] = R[0] + R[0]; psx_next = 0x8002DAE8u; return; }  /* 0x800A8B14 jal */
L_800A8B1C:;
    R[2] = 0x8013u << 16;  /* 0x800A8B1C */
L_800A8B20:;
    R[17] = lw_(R[2] + -18708);  /* 0x800A8B20 */
    R[18] = R[0] + 272;  /* 0x800A8B24 */
    R[16] = 0x1u << 16;  /* 0x800A8B28 */
    R[16] = R[16] | 0x86A0;  /* 0x800A8B2C */
    R[19] = R[0] + R[0];  /* 0x800A8B30 */
    R[21] = R[0] + 50;  /* 0x800A8B34 */
L_800A8B38:;
    psx_div((int32_t)R[17], (int32_t)R[16]);  /* 0x800A8B38 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800A8B48; } }  /* 0x800A8B3C */
    psx_break(7168);  /* 0x800A8B44 */
L_800A8B48:;
    R[1] = R[0] - 1;  /* 0x800A8B48 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800A8B60; } }  /* 0x800A8B4C */
    { uint32_t _c = (R[17] != R[1]); if (_c) { goto L_800A8B60; } }  /* 0x800A8B54 */
    psx_break(6144);  /* 0x800A8B5C */
L_800A8B60:;
    R[3] = LO;  /* 0x800A8B60 */
    R[17] = HI;  /* 0x800A8B64 */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_800A8B74; } }  /* 0x800A8B68 */
    R[19] = R[0] + 1;  /* 0x800A8B70 */
L_800A8B74:;
    { uint32_t _c = (R[19] != R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A8B8C; } }  /* 0x800A8B74 */
    R[2] = R[0] + 1;  /* 0x800A8B7C */
    { uint32_t _c = (R[16] != R[2]); R[2] = 0x6666u << 16; if (_c) { goto L_800A8BC4; } }  /* 0x800A8B80 */
    R[4] = R[20] + R[0];  /* 0x800A8B88 */
L_800A8B8C:;
    R[5] = R[23] + R[0];  /* 0x800A8B8C */
    R[2] = R[18] << 16;  /* 0x800A8B90 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8B94 */
    sw_(R[29] + 16, R[2]);  /* 0x800A8B98 */
    R[2] = R[3] << 16;  /* 0x800A8B9C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8BA0 */
    R[7] = R[22] << 16;  /* 0x800A8BA4 */
    R[6] = R[30] + R[0];  /* 0x800A8BA8 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A8BAC */
    sw_(R[29] + 20, R[21]);  /* 0x800A8BB0 */
    { R[31] = 0x800A8BBCu; sw_(R[29] + 24, R[2]); psx_next = 0x800A8874u; return; }  /* 0x800A8BB4 jal */
    R[20] = R[2] + R[0];  /* 0x800A8BBC */
    R[2] = 0x6666u << 16;  /* 0x800A8BC0 */
L_800A8BC4:;
    R[2] = R[2] | 0x6667;  /* 0x800A8BC4 */
    { int64_t _p = (int64_t)(int32_t)R[16] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A8BC8 */
    R[2] = (uint32_t)((int32_t)R[16] >> 31);  /* 0x800A8BCC */
    R[8] = HI;  /* 0x800A8BD0 */
    R[3] = (uint32_t)((int32_t)R[8] >> 2);  /* 0x800A8BD4 */
    R[16] = R[3] - R[2];  /* 0x800A8BD8 */
    { uint32_t _c = (R[16] != R[0]); R[18] = R[18] + 6; if (_c) { psx_bb(); goto L_800A8B38; } }  /* 0x800A8BDC */
    R[2] = R[20] + R[0];  /* 0x800A8BE4 */
    R[31] = lw_(R[29] + 68);  /* 0x800A8BE8 */
    R[30] = lw_(R[29] + 64);  /* 0x800A8BEC */
    R[23] = lw_(R[29] + 60);  /* 0x800A8BF0 */
    R[22] = lw_(R[29] + 56);  /* 0x800A8BF4 */
    R[21] = lw_(R[29] + 52);  /* 0x800A8BF8 */
    R[20] = lw_(R[29] + 48);  /* 0x800A8BFC */
    R[19] = lw_(R[29] + 44);  /* 0x800A8C00 */
    R[18] = lw_(R[29] + 40);  /* 0x800A8C04 */
    R[17] = lw_(R[29] + 36);  /* 0x800A8C08 */
    R[16] = lw_(R[29] + 32);  /* 0x800A8C0C */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x800A8C10 jr ra */
}

void g0_800A8B1C(void) {
    R[2] = 0x8013u << 16;  /* 0x800A8B1C */
    R[17] = lw_(R[2] + -18708);  /* 0x800A8B20 */
    R[18] = R[0] + 272;  /* 0x800A8B24 */
    R[16] = 0x1u << 16;  /* 0x800A8B28 */
    R[16] = R[16] | 0x86A0;  /* 0x800A8B2C */
    R[19] = R[0] + R[0];  /* 0x800A8B30 */
    R[21] = R[0] + 50;  /* 0x800A8B34 */
L_800A8B38:;
    psx_div((int32_t)R[17], (int32_t)R[16]);  /* 0x800A8B38 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800A8B48; } }  /* 0x800A8B3C */
    psx_break(7168);  /* 0x800A8B44 */
L_800A8B48:;
    R[1] = R[0] - 1;  /* 0x800A8B48 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800A8B60; } }  /* 0x800A8B4C */
    { uint32_t _c = (R[17] != R[1]); if (_c) { goto L_800A8B60; } }  /* 0x800A8B54 */
    psx_break(6144);  /* 0x800A8B5C */
L_800A8B60:;
    R[3] = LO;  /* 0x800A8B60 */
    R[17] = HI;  /* 0x800A8B64 */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_800A8B74; } }  /* 0x800A8B68 */
    R[19] = R[0] + 1;  /* 0x800A8B70 */
L_800A8B74:;
    { uint32_t _c = (R[19] != R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A8B8C; } }  /* 0x800A8B74 */
    R[2] = R[0] + 1;  /* 0x800A8B7C */
    { uint32_t _c = (R[16] != R[2]); R[2] = 0x6666u << 16; if (_c) { goto L_800A8BC4; } }  /* 0x800A8B80 */
    R[4] = R[20] + R[0];  /* 0x800A8B88 */
L_800A8B8C:;
    R[5] = R[23] + R[0];  /* 0x800A8B8C */
    R[2] = R[18] << 16;  /* 0x800A8B90 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8B94 */
    sw_(R[29] + 16, R[2]);  /* 0x800A8B98 */
    R[2] = R[3] << 16;  /* 0x800A8B9C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8BA0 */
    R[7] = R[22] << 16;  /* 0x800A8BA4 */
    R[6] = R[30] + R[0];  /* 0x800A8BA8 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A8BAC */
    sw_(R[29] + 20, R[21]);  /* 0x800A8BB0 */
    { R[31] = 0x800A8BBCu; sw_(R[29] + 24, R[2]); psx_next = 0x800A8874u; return; }  /* 0x800A8BB4 jal */
    R[20] = R[2] + R[0];  /* 0x800A8BBC */
    R[2] = 0x6666u << 16;  /* 0x800A8BC0 */
L_800A8BC4:;
    R[2] = R[2] | 0x6667;  /* 0x800A8BC4 */
    { int64_t _p = (int64_t)(int32_t)R[16] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A8BC8 */
    R[2] = (uint32_t)((int32_t)R[16] >> 31);  /* 0x800A8BCC */
    R[8] = HI;  /* 0x800A8BD0 */
    R[3] = (uint32_t)((int32_t)R[8] >> 2);  /* 0x800A8BD4 */
    R[16] = R[3] - R[2];  /* 0x800A8BD8 */
    { uint32_t _c = (R[16] != R[0]); R[18] = R[18] + 6; if (_c) { psx_bb(); goto L_800A8B38; } }  /* 0x800A8BDC */
    R[2] = R[20] + R[0];  /* 0x800A8BE4 */
    R[31] = lw_(R[29] + 68);  /* 0x800A8BE8 */
    R[30] = lw_(R[29] + 64);  /* 0x800A8BEC */
    R[23] = lw_(R[29] + 60);  /* 0x800A8BF0 */
    R[22] = lw_(R[29] + 56);  /* 0x800A8BF4 */
    R[21] = lw_(R[29] + 52);  /* 0x800A8BF8 */
    R[20] = lw_(R[29] + 48);  /* 0x800A8BFC */
    R[19] = lw_(R[29] + 44);  /* 0x800A8C00 */
    R[18] = lw_(R[29] + 40);  /* 0x800A8C04 */
    R[17] = lw_(R[29] + 36);  /* 0x800A8C08 */
    R[16] = lw_(R[29] + 32);  /* 0x800A8C0C */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x800A8C10 jr ra */
}

void g0_800A8B38(void) {
L_800A8B38:;
    psx_div((int32_t)R[17], (int32_t)R[16]);  /* 0x800A8B38 */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_800A8B48; } }  /* 0x800A8B3C */
    psx_break(7168);  /* 0x800A8B44 */
L_800A8B48:;
    R[1] = R[0] - 1;  /* 0x800A8B48 */
    { uint32_t _c = (R[16] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800A8B60; } }  /* 0x800A8B4C */
    { uint32_t _c = (R[17] != R[1]); if (_c) { goto L_800A8B60; } }  /* 0x800A8B54 */
    psx_break(6144);  /* 0x800A8B5C */
L_800A8B60:;
    R[3] = LO;  /* 0x800A8B60 */
    R[17] = HI;  /* 0x800A8B64 */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_800A8B74; } }  /* 0x800A8B68 */
    R[19] = R[0] + 1;  /* 0x800A8B70 */
L_800A8B74:;
    { uint32_t _c = (R[19] != R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A8B8C; } }  /* 0x800A8B74 */
    R[2] = R[0] + 1;  /* 0x800A8B7C */
    { uint32_t _c = (R[16] != R[2]); R[2] = 0x6666u << 16; if (_c) { goto L_800A8BC4; } }  /* 0x800A8B80 */
    R[4] = R[20] + R[0];  /* 0x800A8B88 */
L_800A8B8C:;
    R[5] = R[23] + R[0];  /* 0x800A8B8C */
    R[2] = R[18] << 16;  /* 0x800A8B90 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8B94 */
    sw_(R[29] + 16, R[2]);  /* 0x800A8B98 */
    R[2] = R[3] << 16;  /* 0x800A8B9C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8BA0 */
    R[7] = R[22] << 16;  /* 0x800A8BA4 */
    R[6] = R[30] + R[0];  /* 0x800A8BA8 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A8BAC */
    sw_(R[29] + 20, R[21]);  /* 0x800A8BB0 */
    { R[31] = 0x800A8BBCu; sw_(R[29] + 24, R[2]); psx_next = 0x800A8874u; return; }  /* 0x800A8BB4 jal */
    R[20] = R[2] + R[0];  /* 0x800A8BBC */
    R[2] = 0x6666u << 16;  /* 0x800A8BC0 */
L_800A8BC4:;
    R[2] = R[2] | 0x6667;  /* 0x800A8BC4 */
    { int64_t _p = (int64_t)(int32_t)R[16] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A8BC8 */
    R[2] = (uint32_t)((int32_t)R[16] >> 31);  /* 0x800A8BCC */
    R[8] = HI;  /* 0x800A8BD0 */
    R[3] = (uint32_t)((int32_t)R[8] >> 2);  /* 0x800A8BD4 */
    R[16] = R[3] - R[2];  /* 0x800A8BD8 */
    { uint32_t _c = (R[16] != R[0]); R[18] = R[18] + 6; if (_c) { psx_bb(); goto L_800A8B38; } }  /* 0x800A8BDC */
    R[2] = R[20] + R[0];  /* 0x800A8BE4 */
    R[31] = lw_(R[29] + 68);  /* 0x800A8BE8 */
    R[30] = lw_(R[29] + 64);  /* 0x800A8BEC */
    R[23] = lw_(R[29] + 60);  /* 0x800A8BF0 */
    R[22] = lw_(R[29] + 56);  /* 0x800A8BF4 */
    R[21] = lw_(R[29] + 52);  /* 0x800A8BF8 */
    R[20] = lw_(R[29] + 48);  /* 0x800A8BFC */
    R[19] = lw_(R[29] + 44);  /* 0x800A8C00 */
    R[18] = lw_(R[29] + 40);  /* 0x800A8C04 */
    R[17] = lw_(R[29] + 36);  /* 0x800A8C08 */
    R[16] = lw_(R[29] + 32);  /* 0x800A8C0C */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x800A8C10 jr ra */
}

void g0_800A8BBC(void) {
    R[20] = R[2] + R[0];  /* 0x800A8BBC */
    R[2] = 0x6666u << 16;  /* 0x800A8BC0 */
    R[2] = R[2] | 0x6667;  /* 0x800A8BC4 */
    { int64_t _p = (int64_t)(int32_t)R[16] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A8BC8 */
    R[2] = (uint32_t)((int32_t)R[16] >> 31);  /* 0x800A8BCC */
    R[8] = HI;  /* 0x800A8BD0 */
    R[3] = (uint32_t)((int32_t)R[8] >> 2);  /* 0x800A8BD4 */
    R[16] = R[3] - R[2];  /* 0x800A8BD8 */
    { uint32_t _c = (R[16] != R[0]); R[18] = R[18] + 6; if (_c) { psx_next = 0x800A8B38u; return; } }  /* 0x800A8BDC b extern */
    R[2] = R[20] + R[0];  /* 0x800A8BE4 */
    R[31] = lw_(R[29] + 68);  /* 0x800A8BE8 */
    R[30] = lw_(R[29] + 64);  /* 0x800A8BEC */
    R[23] = lw_(R[29] + 60);  /* 0x800A8BF0 */
    R[22] = lw_(R[29] + 56);  /* 0x800A8BF4 */
    R[21] = lw_(R[29] + 52);  /* 0x800A8BF8 */
    R[20] = lw_(R[29] + 48);  /* 0x800A8BFC */
    R[19] = lw_(R[29] + 44);  /* 0x800A8C00 */
    R[18] = lw_(R[29] + 40);  /* 0x800A8C04 */
    R[17] = lw_(R[29] + 36);  /* 0x800A8C08 */
    R[16] = lw_(R[29] + 32);  /* 0x800A8C0C */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x800A8C10 jr ra */
}

void g0_800A8C18(void) {
    R[29] = R[29] - 40;  /* 0x800A8C18 */
    R[2] = R[0] + 293;  /* 0x800A8C1C */
    sw_(R[29] + 16, R[2]);  /* 0x800A8C20 */
    R[2] = 0x8006u << 16;  /* 0x800A8C24 */
    R[3] = lb_(R[2] + 15375);  /* 0x800A8C28 */
    R[2] = R[0] + 64;  /* 0x800A8C2C */
    R[7] = R[7] << 16;  /* 0x800A8C30 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A8C34 */
    sw_(R[29] + 32, R[31]);  /* 0x800A8C38 */
    sw_(R[29] + 20, R[2]);  /* 0x800A8C3C */
    { R[31] = 0x800A8C48u; sw_(R[29] + 24, R[3]); psx_next = 0x800A8874u; return; }  /* 0x800A8C40 jal */
    R[31] = lw_(R[29] + 32);  /* 0x800A8C48 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A8C50 jr ra */
}

void g0_800A8C28(void) {
    R[3] = lb_(R[2] + 15375);  /* 0x800A8C28 */
    R[2] = R[0] + 64;  /* 0x800A8C2C */
    R[7] = R[7] << 16;  /* 0x800A8C30 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A8C34 */
    sw_(R[29] + 32, R[31]);  /* 0x800A8C38 */
    sw_(R[29] + 20, R[2]);  /* 0x800A8C3C */
    { R[31] = 0x800A8C48u; sw_(R[29] + 24, R[3]); psx_next = 0x800A8874u; return; }  /* 0x800A8C40 jal */
    R[31] = lw_(R[29] + 32);  /* 0x800A8C48 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A8C50 jr ra */
}

void g0_800A8C48(void) {
    R[31] = lw_(R[29] + 32);  /* 0x800A8C48 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800A8C50 jr ra */
}

void g0_800A8C58(void) {
    R[29] = R[29] - 16;  /* 0x800A8C58 */
    sw_(R[29] + 4, R[17]);  /* 0x800A8C5C */
    R[17] = R[6] + R[0];  /* 0x800A8C60 */
    R[2] = lw_(R[29] + 32);  /* 0x800A8C64 */
    R[25] = lh_(R[29] + 36);  /* 0x800A8C68 */
    R[10] = R[4] + R[0];  /* 0x800A8C6C */
    sw_(R[29] + 8, R[18]);  /* 0x800A8C70 */
    sw_(R[29], R[16]);  /* 0x800A8C74 */
    { uint32_t _c = (R[17] == R[0]); R[9] = R[2] + R[0]; if (_c) { goto L_800A8C88; } }  /* 0x800A8C78 */
    R[2] = R[2] << 16;  /* 0x800A8C80 */
    R[9] = R[2] >> 15;  /* 0x800A8C84 */
L_800A8C88:;
    R[8] = R[0] + 100;  /* 0x800A8C88 */
    R[24] = R[0] + R[0];  /* 0x800A8C8C */
    R[11] = R[0] + 128;  /* 0x800A8C90 */
    R[15] = R[9] + 8;  /* 0x800A8C94 */
    R[13] = R[0] + 120;  /* 0x800A8C98 */
    R[14] = R[9] + 16;  /* 0x800A8C9C */
    R[16] = R[0] + 127;  /* 0x800A8CA0 */
    R[12] = 0xFFu << 16;  /* 0x800A8CA4 */
    R[12] = R[12] | 0xFFFF;  /* 0x800A8CA8 */
    R[6] = 0xFF00u << 16;  /* 0x800A8CAC */
    R[4] = R[4] + 37;  /* 0x800A8CB0 */
L_800A8CB4:;
    R[2] = R[25] << 16;  /* 0x800A8CB4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8CB8 */
    psx_div((int32_t)R[2], (int32_t)R[8]);  /* 0x800A8CBC */
    { uint32_t _c = (R[8] != R[0]); if (_c) { goto L_800A8CCC; } }  /* 0x800A8CC0 */
    psx_break(7168);  /* 0x800A8CC8 */
L_800A8CCC:;
    R[1] = R[0] - 1;  /* 0x800A8CCC */
    { uint32_t _c = (R[8] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800A8CE4; } }  /* 0x800A8CD0 */
    { uint32_t _c = (R[2] != R[1]); if (_c) { goto L_800A8CE4; } }  /* 0x800A8CD8 */
    psx_break(6144);  /* 0x800A8CE0 */
L_800A8CE4:;
    R[3] = LO;  /* 0x800A8CE4 */
    R[2] = HI;  /* 0x800A8CE8 */
    { uint32_t _c = (R[3] == R[0]); R[25] = R[2] + R[0]; if (_c) { goto L_800A8CF8; } }  /* 0x800A8CEC */
    R[24] = R[0] + 1;  /* 0x800A8CF4 */
L_800A8CF8:;
    { uint32_t _c = (R[24] != R[0]); R[2] = R[0] + 9; if (_c) { goto L_800A8D10; } }  /* 0x800A8CF8 */
    R[2] = R[0] + 1;  /* 0x800A8D00 */
    { uint32_t _c = (R[8] != R[2]); R[2] = 0x6666u << 16; if (_c) { goto L_800A8E18; } }  /* 0x800A8D04 */
    R[2] = R[0] + 9;  /* 0x800A8D0C */
L_800A8D10:;
    sb_(R[4] + -34, R[2]);  /* 0x800A8D10 */
    R[2] = R[0] + 44;  /* 0x800A8D14 */
    sb_(R[4] + -30, R[2]);  /* 0x800A8D18 */
    R[2] = R[0] + 32311;  /* 0x800A8D1C */
    sh_(R[4] + -23, R[2]);  /* 0x800A8D20 */
    R[2] = R[0] + 27;  /* 0x800A8D24 */
    sb_(R[4] + -33, R[11]);  /* 0x800A8D28 */
    sb_(R[4] + -32, R[11]);  /* 0x800A8D2C */
    sb_(R[4] + -31, R[11]);  /* 0x800A8D30 */
    { uint32_t _c = (R[17] != R[0]); sh_(R[4] + -15, R[2]); if (_c) { goto L_800A8D90; } }  /* 0x800A8D34 */
    R[2] = R[7] + 8;  /* 0x800A8D3C */
    sh_(R[4] + -21, R[2]);  /* 0x800A8D40 */
    sh_(R[4] + -5, R[2]);  /* 0x800A8D44 */
    R[2] = R[3] + 1;  /* 0x800A8D48 */
    R[2] = R[2] << 3;  /* 0x800A8D4C */
    R[3] = R[2] + 8;  /* 0x800A8D50 */
    sh_(R[4] + -29, R[7]);  /* 0x800A8D54 */
    sh_(R[4] + -27, R[9]);  /* 0x800A8D58 */
    sh_(R[4] + -19, R[9]);  /* 0x800A8D5C */
    sh_(R[4] + -13, R[7]);  /* 0x800A8D60 */
    sh_(R[4] + -11, R[15]);  /* 0x800A8D64 */
    sh_(R[4] + -3, R[15]);  /* 0x800A8D68 */
    sb_(R[4] + -25, R[2]);  /* 0x800A8D6C */
    sb_(R[4] + -24, R[13]);  /* 0x800A8D70 */
    sb_(R[4] + -17, R[3]);  /* 0x800A8D74 */
    sb_(R[4] + -16, R[13]);  /* 0x800A8D78 */
    sb_(R[4] + -9, R[2]);  /* 0x800A8D7C */
    sb_(R[4] + -8, R[11]);  /* 0x800A8D80 */
    sb_(R[4] + -1, R[3]);  /* 0x800A8D84 */
    { sb_(R[4], R[11]); goto L_800A8DE0; }  /* 0x800A8D88 j */
L_800A8D90:;
    R[2] = R[7] + 8;  /* 0x800A8D90 */
    sh_(R[4] + -21, R[2]);  /* 0x800A8D94 */
    sh_(R[4] + -5, R[2]);  /* 0x800A8D98 */
    R[2] = R[3] + 1;  /* 0x800A8D9C */
    R[2] = R[2] << 3;  /* 0x800A8DA0 */
    R[3] = R[2] + 8;  /* 0x800A8DA4 */
    sh_(R[4] + -29, R[7]);  /* 0x800A8DA8 */
    sh_(R[4] + -27, R[9]);  /* 0x800A8DAC */
    sh_(R[4] + -19, R[9]);  /* 0x800A8DB0 */
    sh_(R[4] + -13, R[7]);  /* 0x800A8DB4 */
    sh_(R[4] + -11, R[14]);  /* 0x800A8DB8 */
    sh_(R[4] + -3, R[14]);  /* 0x800A8DBC */
    sb_(R[4] + -25, R[2]);  /* 0x800A8DC0 */
    sb_(R[4] + -24, R[13]);  /* 0x800A8DC4 */
    sb_(R[4] + -17, R[3]);  /* 0x800A8DC8 */
    sb_(R[4] + -16, R[13]);  /* 0x800A8DCC */
    sb_(R[4] + -9, R[2]);  /* 0x800A8DD0 */
    sb_(R[4] + -8, R[16]);  /* 0x800A8DD4 */
    sb_(R[4] + -1, R[3]);  /* 0x800A8DD8 */
    sb_(R[4], R[16]);  /* 0x800A8DDC */
L_800A8DE0:;
    R[4] = R[4] + 40;  /* 0x800A8DE0 */
    R[3] = lw_(R[10]);  /* 0x800A8DE4 */
    R[2] = lw_(R[5]);  /* 0x800A8DE8 */
    R[3] = R[3] & R[6];  /* 0x800A8DEC */
    R[2] = R[2] & R[12];  /* 0x800A8DF0 */
    R[3] = R[3] | R[2];  /* 0x800A8DF4 */
    sw_(R[10], R[3]);  /* 0x800A8DF8 */
    R[3] = R[10] & R[12];  /* 0x800A8DFC */
    R[2] = lw_(R[5]);  /* 0x800A8E00 */
    R[10] = R[10] + 40;  /* 0x800A8E04 */
    R[2] = R[2] & R[6];  /* 0x800A8E08 */
    R[2] = R[2] | R[3];  /* 0x800A8E0C */
    sw_(R[5], R[2]);  /* 0x800A8E10 */
    R[2] = 0x6666u << 16;  /* 0x800A8E14 */
L_800A8E18:;
    R[2] = R[2] | 0x6667;  /* 0x800A8E18 */
    { int64_t _p = (int64_t)(int32_t)R[8] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A8E1C */
    R[2] = (uint32_t)((int32_t)R[8] >> 31);  /* 0x800A8E20 */
    R[18] = HI;  /* 0x800A8E24 */
    R[3] = (uint32_t)((int32_t)R[18] >> 2);  /* 0x800A8E28 */
    R[8] = R[3] - R[2];  /* 0x800A8E2C */
    { uint32_t _c = (R[8] != R[0]); R[7] = R[7] + 8; if (_c) { psx_bb(); goto L_800A8CB4; } }  /* 0x800A8E30 */
    R[18] = lw_(R[29] + 8);  /* 0x800A8E38 */
    R[17] = lw_(R[29] + 4);  /* 0x800A8E3C */
    R[16] = lw_(R[29]);  /* 0x800A8E40 */
    R[2] = R[10] + 40;  /* 0x800A8E44 */
    { R[29] = R[29] + 16; psx_next = R[31]; return; }  /* 0x800A8E48 jr ra */
}

void g0_800A8E50(void) {
#ifdef A2_HUD_PRESENT
    a2_hud_present_group(R[4],0);
#endif
    R[29] = R[29] - 64;  /* 0x800A8E50 */
    sw_(R[29] + 40, R[20]);  /* 0x800A8E54 */
    R[20] = R[4] + R[0];  /* 0x800A8E58 */
    sw_(R[29] + 52, R[23]);  /* 0x800A8E5C */
    R[23] = R[5] + R[0];  /* 0x800A8E60 */
    sw_(R[29] + 56, R[30]);  /* 0x800A8E64 */
    R[30] = R[6] + R[0];  /* 0x800A8E68 */
    sw_(R[29] + 24, R[16]);  /* 0x800A8E6C */
    R[16] = R[7] + R[0];  /* 0x800A8E70 */
    sw_(R[29] + 60, R[31]);  /* 0x800A8E74 */
    sw_(R[29] + 48, R[22]);  /* 0x800A8E78 */
    sw_(R[29] + 44, R[21]);  /* 0x800A8E7C */
    sw_(R[29] + 36, R[19]);  /* 0x800A8E80 */
    sw_(R[29] + 32, R[18]);  /* 0x800A8E84 */
    { R[31] = 0x800A8E90u; sw_(R[29] + 28, R[17]); psx_next = 0x8001D16Cu; return; }  /* 0x800A8E88 jal */
    R[3] = 0x8013u << 16;  /* 0x800A8E90 */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18636);  /* 0x800A8E94 */
    R[3] = R[2] + R[0];  /* 0x800A8E98 */
    R[2] = R[3] << 16;  /* 0x800A8E9C */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8EA0 */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A8EA4 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A8EC8; } }  /* 0x800A8EA8 */
    R[2] = R[9] + 10;  /* 0x800A8EB0 */
    R[9] = R[2] + R[0];  /* 0x800A8EB4 */
    R[2] = R[2] << 16;  /* 0x800A8EB8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8EBC */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A8EE4; }  /* 0x800A8EC0 j */
L_800A8EC8:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A8EC8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A8EF0; } }  /* 0x800A8ECC */
    R[9] = R[2] + R[0];  /* 0x800A8ED4 */
    R[2] = R[2] << 16;  /* 0x800A8ED8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8EDC */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A8EE0 */
L_800A8EE4:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A8EF4; } }  /* 0x800A8EE4 */
    R[9] = R[3] + R[0];  /* 0x800A8EEC */
L_800A8EF0:;
    R[4] = R[20] + R[0];  /* 0x800A8EF0 */
L_800A8EF4:;
    R[5] = R[23] + R[0];  /* 0x800A8EF4 */
    R[6] = R[30] + R[0];  /* 0x800A8EF8 */
    R[8] = R[16] + 24;  /* 0x800A8EFC */
    R[7] = R[8] << 16;  /* 0x800A8F00 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A8F04 */
    R[3] = 0x8013u << 16;  /* 0x800A8F08 */
    R[2] = R[9] << 16;  /* 0x800A8F0C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8F10 */
    sw_(R[3] + -18636, R[2]);  /* 0x800A8F14 */
    R[3] = R[0] + 17;  /* 0x800A8F18 */
    R[22] = R[8] + R[0];  /* 0x800A8F1C */
    sw_(R[29] + 16, R[3]);  /* 0x800A8F20 */
    { R[31] = 0x800A8F2Cu; sw_(R[29] + 20, R[2]); psx_next = 0x800A8C58u; return; }  /* 0x800A8F24 jal */
    R[20] = R[2] + R[0];  /* 0x800A8F2C */
    { R[31] = 0x800A8F38u; R[21] = R[0] + 26; psx_next = 0x8001D1B8u; return; }  /* 0x800A8F30 jal */
    R[3] = 0x8013u << 16;  /* 0x800A8F38 */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18716);  /* 0x800A8F3C */
    R[3] = R[2] + R[0];  /* 0x800A8F40 */
    R[2] = R[3] << 16;  /* 0x800A8F44 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8F48 */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A8F4C */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A8F70; } }  /* 0x800A8F50 */
    R[2] = R[9] + 10;  /* 0x800A8F58 */
    R[9] = R[2] + R[0];  /* 0x800A8F5C */
    R[2] = R[2] << 16;  /* 0x800A8F60 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8F64 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A8F8C; }  /* 0x800A8F68 j */
L_800A8F70:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A8F70 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A8F98; } }  /* 0x800A8F74 */
    R[9] = R[2] + R[0];  /* 0x800A8F7C */
    R[2] = R[2] << 16;  /* 0x800A8F80 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8F84 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A8F88 */
L_800A8F8C:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A8F9C; } }  /* 0x800A8F8C */
    R[9] = R[3] + R[0];  /* 0x800A8F94 */
L_800A8F98:;
    R[4] = R[20] + R[0];  /* 0x800A8F98 */
L_800A8F9C:;
    R[5] = R[23] + R[0];  /* 0x800A8F9C */
    R[6] = R[30] + R[0];  /* 0x800A8FA0 */
    R[7] = R[22] << 16;  /* 0x800A8FA4 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A8FA8 */
    R[16] = 0x8013u << 16;  /* 0x800A8FAC */
    R[3] = R[9] << 16;  /* 0x800A8FB0 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A8FB4 */
    R[2] = R[21] << 16;  /* 0x800A8FB8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8FBC */
    sw_(R[16] + -18716, R[3]);  /* 0x800A8FC0 */
    sw_(R[29] + 16, R[2]);  /* 0x800A8FC4 */
    { R[31] = 0x800A8FD0u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A8FC8 jal */
    R[6] = 0x8334u << 16;  /* 0x800A8FD0 */
    R[3] = 0x8013u << 16;  /* 0x800A8FD4 */
    R[3] = lw_(R[3] + -18636);  /* 0x800A8FD8 */
    R[6] = R[6] | 0x521;  /* 0x800A8FDC */
    R[4] = R[3] << 1;  /* 0x800A8FE0 */
    R[4] = R[4] + R[3];  /* 0x800A8FE4 */
    R[3] = R[4] << 4;  /* 0x800A8FE8 */
    R[4] = R[4] + R[3];  /* 0x800A8FEC */
    R[4] = R[4] << 1;  /* 0x800A8FF0 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A8FF4 */
    R[5] = lw_(R[16] + -18716);  /* 0x800A8FF8 */
    R[3] = R[5] << 1;  /* 0x800A9000 */
    R[3] = R[3] + R[5];  /* 0x800A9004 */
    R[5] = R[3] << 4;  /* 0x800A9008 */
    R[7] = HI;  /* 0x800A900C */
    R[3] = R[3] + R[5];  /* 0x800A9010 */
    R[3] = R[3] << 1;  /* 0x800A9014 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9018 */
    R[20] = R[2] + R[0];  /* 0x800A901C */
    R[2] = R[7] + R[4];  /* 0x800A9020 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9024 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A9028 */
    R[17] = R[2] - R[4];  /* 0x800A902C */
    R[8] = HI;  /* 0x800A9030 */
    R[2] = R[8] + R[3];  /* 0x800A9034 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9038 */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x800A903C */
    { R[31] = 0x800A9048u; R[18] = R[2] - R[3]; psx_next = 0x8001D1B8u; return; }  /* 0x800A9040 jal */
    R[4] = 0x6666u << 16;  /* 0x800A9048 */
    R[4] = R[4] | 0x6667;  /* 0x800A904C */
    R[2] = R[2] << 16;  /* 0x800A9050 */
    R[3] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9054 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9058 */
    R[19] = R[0] + 21;  /* 0x800A905C */
    R[2] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x800A9060 */
    R[3] = HI;  /* 0x800A9064 */
    R[16] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x800A9068 */
    { R[31] = 0x800A9074u; R[16] = R[16] - R[2]; psx_next = 0x8001D16Cu; return; }  /* 0x800A906C jal */
    R[2] = R[2] << 16;  /* 0x800A9074 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9078 */
    R[16] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800A907C */
    { uint32_t _c = (R[16] != R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_800A90F0; } }  /* 0x800A9080 */
    R[2] = lw_(R[4] + -18728);  /* 0x800A9088 */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800A90BC; } }  /* 0x800A9090 */
    R[2] = lw_(R[3] + -18720);  /* 0x800A9098 */
    R[2] = R[2] - 1;  /* 0x800A90A0 */
    sw_(R[3] + -18720, R[2]);  /* 0x800A90A4 */
    R[2] = ((int32_t)R[2] < -3);  /* 0x800A90A8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A90E4; } }  /* 0x800A90AC */
    { sw_(R[4] + -18728, R[0]); goto L_800A90E4; }  /* 0x800A90B4 j */
L_800A90BC:;
    R[2] = lw_(R[3] + -18720);  /* 0x800A90BC */
    R[2] = R[2] + 1;  /* 0x800A90C4 */
    sw_(R[3] + -18720, R[2]);  /* 0x800A90C8 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x800A90CC */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A90E4; } }  /* 0x800A90D0 */
    R[2] = R[0] + 1;  /* 0x800A90D8 */
    sw_(R[4] + -18728, R[2]);  /* 0x800A90DC */
    R[2] = 0x8013u << 16;  /* 0x800A90E0 */
L_800A90E4:;
    R[2] = lh_(R[2] + -18720);  /* 0x800A90E4 */
    R[19] = R[19] + R[2];  /* 0x800A90EC */
L_800A90F0:;
    { uint32_t _c = (R[17] == R[0]); R[5] = R[19] + R[0]; if (_c) { goto L_800A911C; } }  /* 0x800A90F0 */
    R[4] = R[0] + R[0];  /* 0x800A90F8 */
    R[2] = 0x8013u << 16;  /* 0x800A90FC */
    R[2] = R[2] - 18624;  /* 0x800A9100 */
    R[2] = R[2] + 204;  /* 0x800A9104 */
    R[3] = R[0] + 7006;  /* 0x800A9108 */
L_800A910C:;
    sh_(R[2], R[3]);  /* 0x800A910C */
    R[4] = R[4] + 1;  /* 0x800A9110 */
    { uint32_t _c = (R[4] != R[17]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A910C; } }  /* 0x800A9114 */
L_800A911C:;
    { uint32_t _c = (R[18] == R[17]); R[4] = R[17] + R[0]; if (_c) { goto L_800A9150; } }  /* 0x800A911C */
    R[3] = R[0] + 102;  /* 0x800A9124 */
    R[3] = R[3] - R[4];  /* 0x800A9128 */
    R[3] = R[3] << 1;  /* 0x800A912C */
    R[2] = 0x8013u << 16;  /* 0x800A9130 */
    R[2] = R[2] - 18624;  /* 0x800A9134 */
    { uint32_t _c = (R[4] == R[18]); R[2] = R[3] + R[2]; if (_c) { goto L_800A9150; } }  /* 0x800A9138 */
L_800A9140:;
    sh_(R[2], R[5]);  /* 0x800A9140 */
    R[4] = R[4] + 1;  /* 0x800A9144 */
    { uint32_t _c = (R[4] != R[18]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9140; } }  /* 0x800A9148 */
L_800A9150:;
    R[3] = R[0] + 102;  /* 0x800A9150 */
    { uint32_t _c = (R[18] == R[3]); R[4] = R[18] + R[0]; if (_c) { goto L_800A9188; } }  /* 0x800A9154 */
    R[3] = R[3] - R[4];  /* 0x800A915C */
    R[3] = R[3] << 1;  /* 0x800A9160 */
    R[2] = 0x8013u << 16;  /* 0x800A9164 */
    R[2] = R[2] - 18624;  /* 0x800A9168 */
    R[2] = R[3] + R[2];  /* 0x800A916C */
    R[5] = R[0] | 0x8421;  /* 0x800A9170 */
    R[3] = R[0] + 102;  /* 0x800A9174 */
L_800A9178:;
    sh_(R[2], R[5]);  /* 0x800A9178 */
    R[4] = R[4] + 1;  /* 0x800A917C */
    { uint32_t _c = (R[4] != R[3]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9178; } }  /* 0x800A9180 */
L_800A9188:;
    R[4] = 0x8013u << 16;  /* 0x800A9188 */
    R[3] = 0x8006u << 16;  /* 0x800A918C */
    R[2] = lw_(R[4] + -18632);  /* 0x800A9190 */
    R[3] = lb_(R[3] + 15333);  /* 0x800A9194 */
    R[2] = R[2] | 0x1;  /* 0x800A9198 */
    { uint32_t _c = (R[3] != R[0]); sw_(R[4] + -18632, R[2]); if (_c) { goto L_800A91AC; } }  /* 0x800A919C */
    { R[2] = R[20] + R[0]; goto L_800A9414; }  /* 0x800A91A4 j */
L_800A91AC:;
    { R[31] = 0x800A91B4u; psx_next = 0x8001D258u; return; }  /* 0x800A91AC jal */
    R[3] = 0x8013u << 16;  /* 0x800A91B4 */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18640);  /* 0x800A91B8 */
    R[3] = R[2] + R[0];  /* 0x800A91BC */
    R[2] = R[3] << 16;  /* 0x800A91C0 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A91C4 */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A91C8 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A91EC; } }  /* 0x800A91CC */
    R[2] = R[9] + 10;  /* 0x800A91D4 */
    R[9] = R[2] + R[0];  /* 0x800A91D8 */
    R[2] = R[2] << 16;  /* 0x800A91DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A91E0 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A9208; }  /* 0x800A91E4 j */
L_800A91EC:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A91EC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A9214; } }  /* 0x800A91F0 */
    R[9] = R[2] + R[0];  /* 0x800A91F8 */
    R[2] = R[2] << 16;  /* 0x800A91FC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9200 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A9204 */
L_800A9208:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A9218; } }  /* 0x800A9208 */
    R[9] = R[3] + R[0];  /* 0x800A9210 */
L_800A9214:;
    R[4] = R[20] + R[0];  /* 0x800A9214 */
L_800A9218:;
    R[5] = R[23] + R[0];  /* 0x800A9218 */
    R[6] = R[30] + R[0];  /* 0x800A921C */
    R[7] = R[22] << 16;  /* 0x800A9220 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A9224 */
    R[2] = 0x8013u << 16;  /* 0x800A9228 */
    R[3] = R[9] << 16;  /* 0x800A922C */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A9230 */
    R[16] = R[21] + 26;  /* 0x800A9234 */
    sw_(R[2] + -18640, R[3]);  /* 0x800A9238 */
    R[2] = R[16] << 16;  /* 0x800A923C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9240 */
    sw_(R[29] + 16, R[2]);  /* 0x800A9244 */
    { R[31] = 0x800A9250u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A9248 jal */
    R[20] = R[2] + R[0];  /* 0x800A9250 */
    { R[31] = 0x800A925Cu; R[21] = R[16] + 9; psx_next = 0x8001D2A4u; return; }  /* 0x800A9254 jal */
    R[3] = 0x8013u << 16;  /* 0x800A925C */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18724);  /* 0x800A9260 */
    R[3] = R[2] + R[0];  /* 0x800A9264 */
    R[2] = R[3] << 16;  /* 0x800A9268 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A926C */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A9270 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A9294; } }  /* 0x800A9274 */
    R[2] = R[9] + 10;  /* 0x800A927C */
    R[9] = R[2] + R[0];  /* 0x800A9280 */
    R[2] = R[2] << 16;  /* 0x800A9284 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9288 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A92B0; }  /* 0x800A928C j */
L_800A9294:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A9294 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A92BC; } }  /* 0x800A9298 */
    R[9] = R[2] + R[0];  /* 0x800A92A0 */
    R[2] = R[2] << 16;  /* 0x800A92A4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92A8 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A92AC */
L_800A92B0:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A92C0; } }  /* 0x800A92B0 */
    R[9] = R[3] + R[0];  /* 0x800A92B8 */
L_800A92BC:;
    R[4] = R[20] + R[0];  /* 0x800A92BC */
L_800A92C0:;
    R[5] = R[23] + R[0];  /* 0x800A92C0 */
    R[6] = R[30] + R[0];  /* 0x800A92C4 */
    R[7] = R[22] << 16;  /* 0x800A92C8 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A92CC */
    R[16] = 0x8013u << 16;  /* 0x800A92D0 */
    R[3] = R[9] << 16;  /* 0x800A92D4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A92D8 */
    R[2] = R[21] << 16;  /* 0x800A92DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92E0 */
    sw_(R[16] + -18724, R[3]);  /* 0x800A92E4 */
    sw_(R[29] + 16, R[2]);  /* 0x800A92E8 */
    { R[31] = 0x800A92F4u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A92EC jal */
    R[6] = 0x8334u << 16;  /* 0x800A92F4 */
    R[3] = 0x8013u << 16;  /* 0x800A92F8 */
    R[3] = lw_(R[3] + -18640);  /* 0x800A92FC */
    R[6] = R[6] | 0x521;  /* 0x800A9300 */
    R[4] = R[3] << 1;  /* 0x800A9304 */
    R[4] = R[4] + R[3];  /* 0x800A9308 */
    R[3] = R[4] << 4;  /* 0x800A930C */
    R[4] = R[4] + R[3];  /* 0x800A9310 */
    R[4] = R[4] << 1;  /* 0x800A9314 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9318 */
    R[5] = lw_(R[16] + -18724);  /* 0x800A931C */
    R[3] = R[5] << 1;  /* 0x800A9324 */
    R[3] = R[3] + R[5];  /* 0x800A9328 */
    R[5] = R[3] << 4;  /* 0x800A932C */
    R[7] = HI;  /* 0x800A9330 */
    R[3] = R[3] + R[5];  /* 0x800A9334 */
    R[3] = R[3] << 1;  /* 0x800A9338 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A933C */
    R[20] = R[2] + R[0];  /* 0x800A9340 */
    R[2] = R[7] + R[4];  /* 0x800A9344 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9348 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A934C */
    R[17] = R[2] - R[4];  /* 0x800A9350 */
    R[8] = HI;  /* 0x800A9354 */
    R[2] = R[8] + R[3];  /* 0x800A9358 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A935C */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x800A9360 */
    { uint32_t _c = (R[17] == R[0]); R[18] = R[2] - R[3]; if (_c) { goto L_800A9390; } }  /* 0x800A9364 */
    R[4] = R[0] + R[0];  /* 0x800A936C */
    R[2] = 0x8013u << 16;  /* 0x800A9370 */
    R[2] = R[2] - 18984;  /* 0x800A9374 */
    R[2] = R[2] + 204;  /* 0x800A9378 */
    R[3] = R[0] + 5797;  /* 0x800A937C */
L_800A9380:;
    sh_(R[2], R[3]);  /* 0x800A9380 */
    R[4] = R[4] + 1;  /* 0x800A9384 */
    { uint32_t _c = (R[4] != R[17]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9380; } }  /* 0x800A9388 */
L_800A9390:;
    { uint32_t _c = (R[18] == R[17]); R[4] = R[17] + R[0]; if (_c) { goto L_800A93C8; } }  /* 0x800A9390 */
    R[3] = R[0] + 102;  /* 0x800A9398 */
    R[3] = R[3] - R[4];  /* 0x800A939C */
    R[3] = R[3] << 1;  /* 0x800A93A0 */
    R[2] = 0x8013u << 16;  /* 0x800A93A4 */
    R[2] = R[2] - 18984;  /* 0x800A93A8 */
    { uint32_t _c = (R[4] == R[18]); R[2] = R[3] + R[2]; if (_c) { goto L_800A93C8; } }  /* 0x800A93AC */
    R[3] = R[0] + 24736;  /* 0x800A93B4 */
L_800A93B8:;
    sh_(R[2], R[3]);  /* 0x800A93B8 */
    R[4] = R[4] + 1;  /* 0x800A93BC */
    { uint32_t _c = (R[4] != R[18]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93B8; } }  /* 0x800A93C0 */
L_800A93C8:;
    R[3] = R[0] + 102;  /* 0x800A93C8 */
    { uint32_t _c = (R[18] == R[3]); R[4] = R[18] + R[0]; if (_c) { goto L_800A9400; } }  /* 0x800A93CC */
    R[3] = R[3] - R[4];  /* 0x800A93D4 */
    R[3] = R[3] << 1;  /* 0x800A93D8 */
    R[2] = 0x8013u << 16;  /* 0x800A93DC */
    R[2] = R[2] - 18984;  /* 0x800A93E0 */
    R[2] = R[3] + R[2];  /* 0x800A93E4 */
    R[5] = R[0] | 0x8421;  /* 0x800A93E8 */
    R[3] = R[0] + 102;  /* 0x800A93EC */
L_800A93F0:;
    sh_(R[2], R[5]);  /* 0x800A93F0 */
    R[4] = R[4] + 1;  /* 0x800A93F4 */
    { uint32_t _c = (R[4] != R[3]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93F0; } }  /* 0x800A93F8 */
L_800A9400:;
    R[4] = 0x8013u << 16;  /* 0x800A9400 */
    R[3] = lw_(R[4] + -18632);  /* 0x800A9404 */
    R[2] = R[20] + R[0];  /* 0x800A9408 */
    R[3] = R[3] | 0x2;  /* 0x800A940C */
    sw_(R[4] + -18632, R[3]);  /* 0x800A9410 */
L_800A9414:;
    R[31] = lw_(R[29] + 60);  /* 0x800A9414 */
    R[30] = lw_(R[29] + 56);  /* 0x800A9418 */
    R[23] = lw_(R[29] + 52);  /* 0x800A941C */
    R[22] = lw_(R[29] + 48);  /* 0x800A9420 */
    R[21] = lw_(R[29] + 44);  /* 0x800A9424 */
    R[20] = lw_(R[29] + 40);  /* 0x800A9428 */
    R[19] = lw_(R[29] + 36);  /* 0x800A942C */
    R[18] = lw_(R[29] + 32);  /* 0x800A9430 */
    R[17] = lw_(R[29] + 28);  /* 0x800A9434 */
    R[16] = lw_(R[29] + 24);  /* 0x800A9438 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A943C jr ra */
}

void g0_800A8E90(void) {
    R[3] = 0x8013u << 16;  /* 0x800A8E90 */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18636);  /* 0x800A8E94 */
    R[3] = R[2] + R[0];  /* 0x800A8E98 */
    R[2] = R[3] << 16;  /* 0x800A8E9C */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8EA0 */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A8EA4 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A8EC8; } }  /* 0x800A8EA8 */
    R[2] = R[9] + 10;  /* 0x800A8EB0 */
    R[9] = R[2] + R[0];  /* 0x800A8EB4 */
    R[2] = R[2] << 16;  /* 0x800A8EB8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8EBC */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A8EE4; }  /* 0x800A8EC0 j */
L_800A8EC8:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A8EC8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A8EF0; } }  /* 0x800A8ECC */
    R[9] = R[2] + R[0];  /* 0x800A8ED4 */
    R[2] = R[2] << 16;  /* 0x800A8ED8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8EDC */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A8EE0 */
L_800A8EE4:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A8EF4; } }  /* 0x800A8EE4 */
    R[9] = R[3] + R[0];  /* 0x800A8EEC */
L_800A8EF0:;
    R[4] = R[20] + R[0];  /* 0x800A8EF0 */
L_800A8EF4:;
    R[5] = R[23] + R[0];  /* 0x800A8EF4 */
    R[6] = R[30] + R[0];  /* 0x800A8EF8 */
    R[8] = R[16] + 24;  /* 0x800A8EFC */
    R[7] = R[8] << 16;  /* 0x800A8F00 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A8F04 */
    R[3] = 0x8013u << 16;  /* 0x800A8F08 */
    R[2] = R[9] << 16;  /* 0x800A8F0C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8F10 */
    sw_(R[3] + -18636, R[2]);  /* 0x800A8F14 */
    R[3] = R[0] + 17;  /* 0x800A8F18 */
    R[22] = R[8] + R[0];  /* 0x800A8F1C */
    sw_(R[29] + 16, R[3]);  /* 0x800A8F20 */
    { R[31] = 0x800A8F2Cu; sw_(R[29] + 20, R[2]); psx_next = 0x800A8C58u; return; }  /* 0x800A8F24 jal */
    R[20] = R[2] + R[0];  /* 0x800A8F2C */
    { R[31] = 0x800A8F38u; R[21] = R[0] + 26; psx_next = 0x8001D1B8u; return; }  /* 0x800A8F30 jal */
    R[3] = 0x8013u << 16;  /* 0x800A8F38 */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18716);  /* 0x800A8F3C */
    R[3] = R[2] + R[0];  /* 0x800A8F40 */
    R[2] = R[3] << 16;  /* 0x800A8F44 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8F48 */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A8F4C */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A8F70; } }  /* 0x800A8F50 */
    R[2] = R[9] + 10;  /* 0x800A8F58 */
    R[9] = R[2] + R[0];  /* 0x800A8F5C */
    R[2] = R[2] << 16;  /* 0x800A8F60 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8F64 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A8F8C; }  /* 0x800A8F68 j */
L_800A8F70:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A8F70 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A8F98; } }  /* 0x800A8F74 */
    R[9] = R[2] + R[0];  /* 0x800A8F7C */
    R[2] = R[2] << 16;  /* 0x800A8F80 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8F84 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A8F88 */
L_800A8F8C:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A8F9C; } }  /* 0x800A8F8C */
    R[9] = R[3] + R[0];  /* 0x800A8F94 */
L_800A8F98:;
    R[4] = R[20] + R[0];  /* 0x800A8F98 */
L_800A8F9C:;
    R[5] = R[23] + R[0];  /* 0x800A8F9C */
    R[6] = R[30] + R[0];  /* 0x800A8FA0 */
    R[7] = R[22] << 16;  /* 0x800A8FA4 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A8FA8 */
    R[16] = 0x8013u << 16;  /* 0x800A8FAC */
    R[3] = R[9] << 16;  /* 0x800A8FB0 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A8FB4 */
    R[2] = R[21] << 16;  /* 0x800A8FB8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8FBC */
    sw_(R[16] + -18716, R[3]);  /* 0x800A8FC0 */
    sw_(R[29] + 16, R[2]);  /* 0x800A8FC4 */
    { R[31] = 0x800A8FD0u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A8FC8 jal */
    R[6] = 0x8334u << 16;  /* 0x800A8FD0 */
    R[3] = 0x8013u << 16;  /* 0x800A8FD4 */
    R[3] = lw_(R[3] + -18636);  /* 0x800A8FD8 */
    R[6] = R[6] | 0x521;  /* 0x800A8FDC */
    R[4] = R[3] << 1;  /* 0x800A8FE0 */
    R[4] = R[4] + R[3];  /* 0x800A8FE4 */
    R[3] = R[4] << 4;  /* 0x800A8FE8 */
    R[4] = R[4] + R[3];  /* 0x800A8FEC */
    R[4] = R[4] << 1;  /* 0x800A8FF0 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A8FF4 */
    R[5] = lw_(R[16] + -18716);  /* 0x800A8FF8 */
    R[3] = R[5] << 1;  /* 0x800A9000 */
    R[3] = R[3] + R[5];  /* 0x800A9004 */
    R[5] = R[3] << 4;  /* 0x800A9008 */
    R[7] = HI;  /* 0x800A900C */
    R[3] = R[3] + R[5];  /* 0x800A9010 */
    R[3] = R[3] << 1;  /* 0x800A9014 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9018 */
    R[20] = R[2] + R[0];  /* 0x800A901C */
    R[2] = R[7] + R[4];  /* 0x800A9020 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9024 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A9028 */
    R[17] = R[2] - R[4];  /* 0x800A902C */
    R[8] = HI;  /* 0x800A9030 */
    R[2] = R[8] + R[3];  /* 0x800A9034 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9038 */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x800A903C */
    { R[31] = 0x800A9048u; R[18] = R[2] - R[3]; psx_next = 0x8001D1B8u; return; }  /* 0x800A9040 jal */
    R[4] = 0x6666u << 16;  /* 0x800A9048 */
    R[4] = R[4] | 0x6667;  /* 0x800A904C */
    R[2] = R[2] << 16;  /* 0x800A9050 */
    R[3] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9054 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9058 */
    R[19] = R[0] + 21;  /* 0x800A905C */
    R[2] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x800A9060 */
    R[3] = HI;  /* 0x800A9064 */
    R[16] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x800A9068 */
    { R[31] = 0x800A9074u; R[16] = R[16] - R[2]; psx_next = 0x8001D16Cu; return; }  /* 0x800A906C jal */
    R[2] = R[2] << 16;  /* 0x800A9074 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9078 */
    R[16] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800A907C */
    { uint32_t _c = (R[16] != R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_800A90F0; } }  /* 0x800A9080 */
    R[2] = lw_(R[4] + -18728);  /* 0x800A9088 */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800A90BC; } }  /* 0x800A9090 */
    R[2] = lw_(R[3] + -18720);  /* 0x800A9098 */
    R[2] = R[2] - 1;  /* 0x800A90A0 */
    sw_(R[3] + -18720, R[2]);  /* 0x800A90A4 */
    R[2] = ((int32_t)R[2] < -3);  /* 0x800A90A8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A90E4; } }  /* 0x800A90AC */
    { sw_(R[4] + -18728, R[0]); goto L_800A90E4; }  /* 0x800A90B4 j */
L_800A90BC:;
    R[2] = lw_(R[3] + -18720);  /* 0x800A90BC */
    R[2] = R[2] + 1;  /* 0x800A90C4 */
    sw_(R[3] + -18720, R[2]);  /* 0x800A90C8 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x800A90CC */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A90E4; } }  /* 0x800A90D0 */
    R[2] = R[0] + 1;  /* 0x800A90D8 */
    sw_(R[4] + -18728, R[2]);  /* 0x800A90DC */
    R[2] = 0x8013u << 16;  /* 0x800A90E0 */
L_800A90E4:;
    R[2] = lh_(R[2] + -18720);  /* 0x800A90E4 */
    R[19] = R[19] + R[2];  /* 0x800A90EC */
L_800A90F0:;
    { uint32_t _c = (R[17] == R[0]); R[5] = R[19] + R[0]; if (_c) { goto L_800A911C; } }  /* 0x800A90F0 */
    R[4] = R[0] + R[0];  /* 0x800A90F8 */
    R[2] = 0x8013u << 16;  /* 0x800A90FC */
    R[2] = R[2] - 18624;  /* 0x800A9100 */
    R[2] = R[2] + 204;  /* 0x800A9104 */
    R[3] = R[0] + 7006;  /* 0x800A9108 */
L_800A910C:;
    sh_(R[2], R[3]);  /* 0x800A910C */
    R[4] = R[4] + 1;  /* 0x800A9110 */
    { uint32_t _c = (R[4] != R[17]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A910C; } }  /* 0x800A9114 */
L_800A911C:;
    { uint32_t _c = (R[18] == R[17]); R[4] = R[17] + R[0]; if (_c) { goto L_800A9150; } }  /* 0x800A911C */
    R[3] = R[0] + 102;  /* 0x800A9124 */
    R[3] = R[3] - R[4];  /* 0x800A9128 */
    R[3] = R[3] << 1;  /* 0x800A912C */
    R[2] = 0x8013u << 16;  /* 0x800A9130 */
    R[2] = R[2] - 18624;  /* 0x800A9134 */
    { uint32_t _c = (R[4] == R[18]); R[2] = R[3] + R[2]; if (_c) { goto L_800A9150; } }  /* 0x800A9138 */
L_800A9140:;
    sh_(R[2], R[5]);  /* 0x800A9140 */
    R[4] = R[4] + 1;  /* 0x800A9144 */
    { uint32_t _c = (R[4] != R[18]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9140; } }  /* 0x800A9148 */
L_800A9150:;
    R[3] = R[0] + 102;  /* 0x800A9150 */
    { uint32_t _c = (R[18] == R[3]); R[4] = R[18] + R[0]; if (_c) { goto L_800A9188; } }  /* 0x800A9154 */
    R[3] = R[3] - R[4];  /* 0x800A915C */
    R[3] = R[3] << 1;  /* 0x800A9160 */
    R[2] = 0x8013u << 16;  /* 0x800A9164 */
    R[2] = R[2] - 18624;  /* 0x800A9168 */
    R[2] = R[3] + R[2];  /* 0x800A916C */
    R[5] = R[0] | 0x8421;  /* 0x800A9170 */
    R[3] = R[0] + 102;  /* 0x800A9174 */
L_800A9178:;
    sh_(R[2], R[5]);  /* 0x800A9178 */
    R[4] = R[4] + 1;  /* 0x800A917C */
    { uint32_t _c = (R[4] != R[3]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9178; } }  /* 0x800A9180 */
L_800A9188:;
    R[4] = 0x8013u << 16;  /* 0x800A9188 */
    R[3] = 0x8006u << 16;  /* 0x800A918C */
    R[2] = lw_(R[4] + -18632);  /* 0x800A9190 */
    R[3] = lb_(R[3] + 15333);  /* 0x800A9194 */
    R[2] = R[2] | 0x1;  /* 0x800A9198 */
    { uint32_t _c = (R[3] != R[0]); sw_(R[4] + -18632, R[2]); if (_c) { goto L_800A91AC; } }  /* 0x800A919C */
    { R[2] = R[20] + R[0]; goto L_800A9414; }  /* 0x800A91A4 j */
L_800A91AC:;
    { R[31] = 0x800A91B4u; psx_next = 0x8001D258u; return; }  /* 0x800A91AC jal */
    R[3] = 0x8013u << 16;  /* 0x800A91B4 */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18640);  /* 0x800A91B8 */
    R[3] = R[2] + R[0];  /* 0x800A91BC */
    R[2] = R[3] << 16;  /* 0x800A91C0 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A91C4 */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A91C8 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A91EC; } }  /* 0x800A91CC */
    R[2] = R[9] + 10;  /* 0x800A91D4 */
    R[9] = R[2] + R[0];  /* 0x800A91D8 */
    R[2] = R[2] << 16;  /* 0x800A91DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A91E0 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A9208; }  /* 0x800A91E4 j */
L_800A91EC:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A91EC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A9214; } }  /* 0x800A91F0 */
    R[9] = R[2] + R[0];  /* 0x800A91F8 */
    R[2] = R[2] << 16;  /* 0x800A91FC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9200 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A9204 */
L_800A9208:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A9218; } }  /* 0x800A9208 */
    R[9] = R[3] + R[0];  /* 0x800A9210 */
L_800A9214:;
    R[4] = R[20] + R[0];  /* 0x800A9214 */
L_800A9218:;
    R[5] = R[23] + R[0];  /* 0x800A9218 */
    R[6] = R[30] + R[0];  /* 0x800A921C */
    R[7] = R[22] << 16;  /* 0x800A9220 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A9224 */
    R[2] = 0x8013u << 16;  /* 0x800A9228 */
    R[3] = R[9] << 16;  /* 0x800A922C */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A9230 */
    R[16] = R[21] + 26;  /* 0x800A9234 */
    sw_(R[2] + -18640, R[3]);  /* 0x800A9238 */
    R[2] = R[16] << 16;  /* 0x800A923C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9240 */
    sw_(R[29] + 16, R[2]);  /* 0x800A9244 */
    { R[31] = 0x800A9250u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A9248 jal */
    R[20] = R[2] + R[0];  /* 0x800A9250 */
    { R[31] = 0x800A925Cu; R[21] = R[16] + 9; psx_next = 0x8001D2A4u; return; }  /* 0x800A9254 jal */
    R[3] = 0x8013u << 16;  /* 0x800A925C */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18724);  /* 0x800A9260 */
    R[3] = R[2] + R[0];  /* 0x800A9264 */
    R[2] = R[3] << 16;  /* 0x800A9268 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A926C */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A9270 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A9294; } }  /* 0x800A9274 */
    R[2] = R[9] + 10;  /* 0x800A927C */
    R[9] = R[2] + R[0];  /* 0x800A9280 */
    R[2] = R[2] << 16;  /* 0x800A9284 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9288 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A92B0; }  /* 0x800A928C j */
L_800A9294:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A9294 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A92BC; } }  /* 0x800A9298 */
    R[9] = R[2] + R[0];  /* 0x800A92A0 */
    R[2] = R[2] << 16;  /* 0x800A92A4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92A8 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A92AC */
L_800A92B0:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A92C0; } }  /* 0x800A92B0 */
    R[9] = R[3] + R[0];  /* 0x800A92B8 */
L_800A92BC:;
    R[4] = R[20] + R[0];  /* 0x800A92BC */
L_800A92C0:;
    R[5] = R[23] + R[0];  /* 0x800A92C0 */
    R[6] = R[30] + R[0];  /* 0x800A92C4 */
    R[7] = R[22] << 16;  /* 0x800A92C8 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A92CC */
    R[16] = 0x8013u << 16;  /* 0x800A92D0 */
    R[3] = R[9] << 16;  /* 0x800A92D4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A92D8 */
    R[2] = R[21] << 16;  /* 0x800A92DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92E0 */
    sw_(R[16] + -18724, R[3]);  /* 0x800A92E4 */
    sw_(R[29] + 16, R[2]);  /* 0x800A92E8 */
    { R[31] = 0x800A92F4u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A92EC jal */
    R[6] = 0x8334u << 16;  /* 0x800A92F4 */
    R[3] = 0x8013u << 16;  /* 0x800A92F8 */
    R[3] = lw_(R[3] + -18640);  /* 0x800A92FC */
    R[6] = R[6] | 0x521;  /* 0x800A9300 */
    R[4] = R[3] << 1;  /* 0x800A9304 */
    R[4] = R[4] + R[3];  /* 0x800A9308 */
    R[3] = R[4] << 4;  /* 0x800A930C */
    R[4] = R[4] + R[3];  /* 0x800A9310 */
    R[4] = R[4] << 1;  /* 0x800A9314 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9318 */
    R[5] = lw_(R[16] + -18724);  /* 0x800A931C */
    R[3] = R[5] << 1;  /* 0x800A9324 */
    R[3] = R[3] + R[5];  /* 0x800A9328 */
    R[5] = R[3] << 4;  /* 0x800A932C */
    R[7] = HI;  /* 0x800A9330 */
    R[3] = R[3] + R[5];  /* 0x800A9334 */
    R[3] = R[3] << 1;  /* 0x800A9338 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A933C */
    R[20] = R[2] + R[0];  /* 0x800A9340 */
    R[2] = R[7] + R[4];  /* 0x800A9344 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9348 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A934C */
    R[17] = R[2] - R[4];  /* 0x800A9350 */
    R[8] = HI;  /* 0x800A9354 */
    R[2] = R[8] + R[3];  /* 0x800A9358 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A935C */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x800A9360 */
    { uint32_t _c = (R[17] == R[0]); R[18] = R[2] - R[3]; if (_c) { goto L_800A9390; } }  /* 0x800A9364 */
    R[4] = R[0] + R[0];  /* 0x800A936C */
    R[2] = 0x8013u << 16;  /* 0x800A9370 */
    R[2] = R[2] - 18984;  /* 0x800A9374 */
    R[2] = R[2] + 204;  /* 0x800A9378 */
    R[3] = R[0] + 5797;  /* 0x800A937C */
L_800A9380:;
    sh_(R[2], R[3]);  /* 0x800A9380 */
    R[4] = R[4] + 1;  /* 0x800A9384 */
    { uint32_t _c = (R[4] != R[17]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9380; } }  /* 0x800A9388 */
L_800A9390:;
    { uint32_t _c = (R[18] == R[17]); R[4] = R[17] + R[0]; if (_c) { goto L_800A93C8; } }  /* 0x800A9390 */
    R[3] = R[0] + 102;  /* 0x800A9398 */
    R[3] = R[3] - R[4];  /* 0x800A939C */
    R[3] = R[3] << 1;  /* 0x800A93A0 */
    R[2] = 0x8013u << 16;  /* 0x800A93A4 */
    R[2] = R[2] - 18984;  /* 0x800A93A8 */
    { uint32_t _c = (R[4] == R[18]); R[2] = R[3] + R[2]; if (_c) { goto L_800A93C8; } }  /* 0x800A93AC */
    R[3] = R[0] + 24736;  /* 0x800A93B4 */
L_800A93B8:;
    sh_(R[2], R[3]);  /* 0x800A93B8 */
    R[4] = R[4] + 1;  /* 0x800A93BC */
    { uint32_t _c = (R[4] != R[18]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93B8; } }  /* 0x800A93C0 */
L_800A93C8:;
    R[3] = R[0] + 102;  /* 0x800A93C8 */
    { uint32_t _c = (R[18] == R[3]); R[4] = R[18] + R[0]; if (_c) { goto L_800A9400; } }  /* 0x800A93CC */
    R[3] = R[3] - R[4];  /* 0x800A93D4 */
    R[3] = R[3] << 1;  /* 0x800A93D8 */
    R[2] = 0x8013u << 16;  /* 0x800A93DC */
    R[2] = R[2] - 18984;  /* 0x800A93E0 */
    R[2] = R[3] + R[2];  /* 0x800A93E4 */
    R[5] = R[0] | 0x8421;  /* 0x800A93E8 */
    R[3] = R[0] + 102;  /* 0x800A93EC */
L_800A93F0:;
    sh_(R[2], R[5]);  /* 0x800A93F0 */
    R[4] = R[4] + 1;  /* 0x800A93F4 */
    { uint32_t _c = (R[4] != R[3]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93F0; } }  /* 0x800A93F8 */
L_800A9400:;
    R[4] = 0x8013u << 16;  /* 0x800A9400 */
    R[3] = lw_(R[4] + -18632);  /* 0x800A9404 */
    R[2] = R[20] + R[0];  /* 0x800A9408 */
    R[3] = R[3] | 0x2;  /* 0x800A940C */
    sw_(R[4] + -18632, R[3]);  /* 0x800A9410 */
L_800A9414:;
    R[31] = lw_(R[29] + 60);  /* 0x800A9414 */
    R[30] = lw_(R[29] + 56);  /* 0x800A9418 */
    R[23] = lw_(R[29] + 52);  /* 0x800A941C */
    R[22] = lw_(R[29] + 48);  /* 0x800A9420 */
    R[21] = lw_(R[29] + 44);  /* 0x800A9424 */
    R[20] = lw_(R[29] + 40);  /* 0x800A9428 */
    R[19] = lw_(R[29] + 36);  /* 0x800A942C */
    R[18] = lw_(R[29] + 32);  /* 0x800A9430 */
    R[17] = lw_(R[29] + 28);  /* 0x800A9434 */
    R[16] = lw_(R[29] + 24);  /* 0x800A9438 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A943C jr ra */
}

void g0_800A8F2C(void) {
    R[20] = R[2] + R[0];  /* 0x800A8F2C */
    { R[31] = 0x800A8F38u; R[21] = R[0] + 26; psx_next = 0x8001D1B8u; return; }  /* 0x800A8F30 jal */
    R[3] = 0x8013u << 16;  /* 0x800A8F38 */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18716);  /* 0x800A8F3C */
    R[3] = R[2] + R[0];  /* 0x800A8F40 */
    R[2] = R[3] << 16;  /* 0x800A8F44 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8F48 */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A8F4C */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A8F70; } }  /* 0x800A8F50 */
    R[2] = R[9] + 10;  /* 0x800A8F58 */
    R[9] = R[2] + R[0];  /* 0x800A8F5C */
    R[2] = R[2] << 16;  /* 0x800A8F60 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8F64 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A8F8C; }  /* 0x800A8F68 j */
L_800A8F70:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A8F70 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A8F98; } }  /* 0x800A8F74 */
    R[9] = R[2] + R[0];  /* 0x800A8F7C */
    R[2] = R[2] << 16;  /* 0x800A8F80 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8F84 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A8F88 */
L_800A8F8C:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A8F9C; } }  /* 0x800A8F8C */
    R[9] = R[3] + R[0];  /* 0x800A8F94 */
L_800A8F98:;
    R[4] = R[20] + R[0];  /* 0x800A8F98 */
L_800A8F9C:;
    R[5] = R[23] + R[0];  /* 0x800A8F9C */
    R[6] = R[30] + R[0];  /* 0x800A8FA0 */
    R[7] = R[22] << 16;  /* 0x800A8FA4 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A8FA8 */
    R[16] = 0x8013u << 16;  /* 0x800A8FAC */
    R[3] = R[9] << 16;  /* 0x800A8FB0 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A8FB4 */
    R[2] = R[21] << 16;  /* 0x800A8FB8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8FBC */
    sw_(R[16] + -18716, R[3]);  /* 0x800A8FC0 */
    sw_(R[29] + 16, R[2]);  /* 0x800A8FC4 */
    { R[31] = 0x800A8FD0u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A8FC8 jal */
    R[6] = 0x8334u << 16;  /* 0x800A8FD0 */
    R[3] = 0x8013u << 16;  /* 0x800A8FD4 */
    R[3] = lw_(R[3] + -18636);  /* 0x800A8FD8 */
    R[6] = R[6] | 0x521;  /* 0x800A8FDC */
    R[4] = R[3] << 1;  /* 0x800A8FE0 */
    R[4] = R[4] + R[3];  /* 0x800A8FE4 */
    R[3] = R[4] << 4;  /* 0x800A8FE8 */
    R[4] = R[4] + R[3];  /* 0x800A8FEC */
    R[4] = R[4] << 1;  /* 0x800A8FF0 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A8FF4 */
    R[5] = lw_(R[16] + -18716);  /* 0x800A8FF8 */
    R[3] = R[5] << 1;  /* 0x800A9000 */
    R[3] = R[3] + R[5];  /* 0x800A9004 */
    R[5] = R[3] << 4;  /* 0x800A9008 */
    R[7] = HI;  /* 0x800A900C */
    R[3] = R[3] + R[5];  /* 0x800A9010 */
    R[3] = R[3] << 1;  /* 0x800A9014 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9018 */
    R[20] = R[2] + R[0];  /* 0x800A901C */
    R[2] = R[7] + R[4];  /* 0x800A9020 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9024 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A9028 */
    R[17] = R[2] - R[4];  /* 0x800A902C */
    R[8] = HI;  /* 0x800A9030 */
    R[2] = R[8] + R[3];  /* 0x800A9034 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9038 */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x800A903C */
    { R[31] = 0x800A9048u; R[18] = R[2] - R[3]; psx_next = 0x8001D1B8u; return; }  /* 0x800A9040 jal */
    R[4] = 0x6666u << 16;  /* 0x800A9048 */
    R[4] = R[4] | 0x6667;  /* 0x800A904C */
    R[2] = R[2] << 16;  /* 0x800A9050 */
    R[3] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9054 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9058 */
    R[19] = R[0] + 21;  /* 0x800A905C */
    R[2] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x800A9060 */
    R[3] = HI;  /* 0x800A9064 */
    R[16] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x800A9068 */
    { R[31] = 0x800A9074u; R[16] = R[16] - R[2]; psx_next = 0x8001D16Cu; return; }  /* 0x800A906C jal */
    R[2] = R[2] << 16;  /* 0x800A9074 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9078 */
    R[16] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800A907C */
    { uint32_t _c = (R[16] != R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_800A90F0; } }  /* 0x800A9080 */
    R[2] = lw_(R[4] + -18728);  /* 0x800A9088 */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800A90BC; } }  /* 0x800A9090 */
    R[2] = lw_(R[3] + -18720);  /* 0x800A9098 */
    R[2] = R[2] - 1;  /* 0x800A90A0 */
    sw_(R[3] + -18720, R[2]);  /* 0x800A90A4 */
    R[2] = ((int32_t)R[2] < -3);  /* 0x800A90A8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A90E4; } }  /* 0x800A90AC */
    { sw_(R[4] + -18728, R[0]); goto L_800A90E4; }  /* 0x800A90B4 j */
L_800A90BC:;
    R[2] = lw_(R[3] + -18720);  /* 0x800A90BC */
    R[2] = R[2] + 1;  /* 0x800A90C4 */
    sw_(R[3] + -18720, R[2]);  /* 0x800A90C8 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x800A90CC */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A90E4; } }  /* 0x800A90D0 */
    R[2] = R[0] + 1;  /* 0x800A90D8 */
    sw_(R[4] + -18728, R[2]);  /* 0x800A90DC */
    R[2] = 0x8013u << 16;  /* 0x800A90E0 */
L_800A90E4:;
    R[2] = lh_(R[2] + -18720);  /* 0x800A90E4 */
    R[19] = R[19] + R[2];  /* 0x800A90EC */
L_800A90F0:;
    { uint32_t _c = (R[17] == R[0]); R[5] = R[19] + R[0]; if (_c) { goto L_800A911C; } }  /* 0x800A90F0 */
    R[4] = R[0] + R[0];  /* 0x800A90F8 */
    R[2] = 0x8013u << 16;  /* 0x800A90FC */
    R[2] = R[2] - 18624;  /* 0x800A9100 */
    R[2] = R[2] + 204;  /* 0x800A9104 */
    R[3] = R[0] + 7006;  /* 0x800A9108 */
L_800A910C:;
    sh_(R[2], R[3]);  /* 0x800A910C */
    R[4] = R[4] + 1;  /* 0x800A9110 */
    { uint32_t _c = (R[4] != R[17]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A910C; } }  /* 0x800A9114 */
L_800A911C:;
    { uint32_t _c = (R[18] == R[17]); R[4] = R[17] + R[0]; if (_c) { goto L_800A9150; } }  /* 0x800A911C */
    R[3] = R[0] + 102;  /* 0x800A9124 */
    R[3] = R[3] - R[4];  /* 0x800A9128 */
    R[3] = R[3] << 1;  /* 0x800A912C */
    R[2] = 0x8013u << 16;  /* 0x800A9130 */
    R[2] = R[2] - 18624;  /* 0x800A9134 */
    { uint32_t _c = (R[4] == R[18]); R[2] = R[3] + R[2]; if (_c) { goto L_800A9150; } }  /* 0x800A9138 */
L_800A9140:;
    sh_(R[2], R[5]);  /* 0x800A9140 */
    R[4] = R[4] + 1;  /* 0x800A9144 */
    { uint32_t _c = (R[4] != R[18]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9140; } }  /* 0x800A9148 */
L_800A9150:;
    R[3] = R[0] + 102;  /* 0x800A9150 */
    { uint32_t _c = (R[18] == R[3]); R[4] = R[18] + R[0]; if (_c) { goto L_800A9188; } }  /* 0x800A9154 */
    R[3] = R[3] - R[4];  /* 0x800A915C */
    R[3] = R[3] << 1;  /* 0x800A9160 */
    R[2] = 0x8013u << 16;  /* 0x800A9164 */
    R[2] = R[2] - 18624;  /* 0x800A9168 */
    R[2] = R[3] + R[2];  /* 0x800A916C */
    R[5] = R[0] | 0x8421;  /* 0x800A9170 */
    R[3] = R[0] + 102;  /* 0x800A9174 */
L_800A9178:;
    sh_(R[2], R[5]);  /* 0x800A9178 */
    R[4] = R[4] + 1;  /* 0x800A917C */
    { uint32_t _c = (R[4] != R[3]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9178; } }  /* 0x800A9180 */
L_800A9188:;
    R[4] = 0x8013u << 16;  /* 0x800A9188 */
    R[3] = 0x8006u << 16;  /* 0x800A918C */
    R[2] = lw_(R[4] + -18632);  /* 0x800A9190 */
    R[3] = lb_(R[3] + 15333);  /* 0x800A9194 */
    R[2] = R[2] | 0x1;  /* 0x800A9198 */
    { uint32_t _c = (R[3] != R[0]); sw_(R[4] + -18632, R[2]); if (_c) { goto L_800A91AC; } }  /* 0x800A919C */
    { R[2] = R[20] + R[0]; goto L_800A9414; }  /* 0x800A91A4 j */
L_800A91AC:;
    { R[31] = 0x800A91B4u; psx_next = 0x8001D258u; return; }  /* 0x800A91AC jal */
    R[3] = 0x8013u << 16;  /* 0x800A91B4 */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18640);  /* 0x800A91B8 */
    R[3] = R[2] + R[0];  /* 0x800A91BC */
    R[2] = R[3] << 16;  /* 0x800A91C0 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A91C4 */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A91C8 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A91EC; } }  /* 0x800A91CC */
    R[2] = R[9] + 10;  /* 0x800A91D4 */
    R[9] = R[2] + R[0];  /* 0x800A91D8 */
    R[2] = R[2] << 16;  /* 0x800A91DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A91E0 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A9208; }  /* 0x800A91E4 j */
L_800A91EC:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A91EC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A9214; } }  /* 0x800A91F0 */
    R[9] = R[2] + R[0];  /* 0x800A91F8 */
    R[2] = R[2] << 16;  /* 0x800A91FC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9200 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A9204 */
L_800A9208:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A9218; } }  /* 0x800A9208 */
    R[9] = R[3] + R[0];  /* 0x800A9210 */
L_800A9214:;
    R[4] = R[20] + R[0];  /* 0x800A9214 */
L_800A9218:;
    R[5] = R[23] + R[0];  /* 0x800A9218 */
    R[6] = R[30] + R[0];  /* 0x800A921C */
    R[7] = R[22] << 16;  /* 0x800A9220 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A9224 */
    R[2] = 0x8013u << 16;  /* 0x800A9228 */
    R[3] = R[9] << 16;  /* 0x800A922C */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A9230 */
    R[16] = R[21] + 26;  /* 0x800A9234 */
    sw_(R[2] + -18640, R[3]);  /* 0x800A9238 */
    R[2] = R[16] << 16;  /* 0x800A923C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9240 */
    sw_(R[29] + 16, R[2]);  /* 0x800A9244 */
    { R[31] = 0x800A9250u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A9248 jal */
    R[20] = R[2] + R[0];  /* 0x800A9250 */
    { R[31] = 0x800A925Cu; R[21] = R[16] + 9; psx_next = 0x8001D2A4u; return; }  /* 0x800A9254 jal */
    R[3] = 0x8013u << 16;  /* 0x800A925C */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18724);  /* 0x800A9260 */
    R[3] = R[2] + R[0];  /* 0x800A9264 */
    R[2] = R[3] << 16;  /* 0x800A9268 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A926C */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A9270 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A9294; } }  /* 0x800A9274 */
    R[2] = R[9] + 10;  /* 0x800A927C */
    R[9] = R[2] + R[0];  /* 0x800A9280 */
    R[2] = R[2] << 16;  /* 0x800A9284 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9288 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A92B0; }  /* 0x800A928C j */
L_800A9294:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A9294 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A92BC; } }  /* 0x800A9298 */
    R[9] = R[2] + R[0];  /* 0x800A92A0 */
    R[2] = R[2] << 16;  /* 0x800A92A4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92A8 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A92AC */
L_800A92B0:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A92C0; } }  /* 0x800A92B0 */
    R[9] = R[3] + R[0];  /* 0x800A92B8 */
L_800A92BC:;
    R[4] = R[20] + R[0];  /* 0x800A92BC */
L_800A92C0:;
    R[5] = R[23] + R[0];  /* 0x800A92C0 */
    R[6] = R[30] + R[0];  /* 0x800A92C4 */
    R[7] = R[22] << 16;  /* 0x800A92C8 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A92CC */
    R[16] = 0x8013u << 16;  /* 0x800A92D0 */
    R[3] = R[9] << 16;  /* 0x800A92D4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A92D8 */
    R[2] = R[21] << 16;  /* 0x800A92DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92E0 */
    sw_(R[16] + -18724, R[3]);  /* 0x800A92E4 */
    sw_(R[29] + 16, R[2]);  /* 0x800A92E8 */
    { R[31] = 0x800A92F4u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A92EC jal */
    R[6] = 0x8334u << 16;  /* 0x800A92F4 */
    R[3] = 0x8013u << 16;  /* 0x800A92F8 */
    R[3] = lw_(R[3] + -18640);  /* 0x800A92FC */
    R[6] = R[6] | 0x521;  /* 0x800A9300 */
    R[4] = R[3] << 1;  /* 0x800A9304 */
    R[4] = R[4] + R[3];  /* 0x800A9308 */
    R[3] = R[4] << 4;  /* 0x800A930C */
    R[4] = R[4] + R[3];  /* 0x800A9310 */
    R[4] = R[4] << 1;  /* 0x800A9314 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9318 */
    R[5] = lw_(R[16] + -18724);  /* 0x800A931C */
    R[3] = R[5] << 1;  /* 0x800A9324 */
    R[3] = R[3] + R[5];  /* 0x800A9328 */
    R[5] = R[3] << 4;  /* 0x800A932C */
    R[7] = HI;  /* 0x800A9330 */
    R[3] = R[3] + R[5];  /* 0x800A9334 */
    R[3] = R[3] << 1;  /* 0x800A9338 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A933C */
    R[20] = R[2] + R[0];  /* 0x800A9340 */
    R[2] = R[7] + R[4];  /* 0x800A9344 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9348 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A934C */
    R[17] = R[2] - R[4];  /* 0x800A9350 */
    R[8] = HI;  /* 0x800A9354 */
    R[2] = R[8] + R[3];  /* 0x800A9358 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A935C */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x800A9360 */
    { uint32_t _c = (R[17] == R[0]); R[18] = R[2] - R[3]; if (_c) { goto L_800A9390; } }  /* 0x800A9364 */
    R[4] = R[0] + R[0];  /* 0x800A936C */
    R[2] = 0x8013u << 16;  /* 0x800A9370 */
    R[2] = R[2] - 18984;  /* 0x800A9374 */
    R[2] = R[2] + 204;  /* 0x800A9378 */
    R[3] = R[0] + 5797;  /* 0x800A937C */
L_800A9380:;
    sh_(R[2], R[3]);  /* 0x800A9380 */
    R[4] = R[4] + 1;  /* 0x800A9384 */
    { uint32_t _c = (R[4] != R[17]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9380; } }  /* 0x800A9388 */
L_800A9390:;
    { uint32_t _c = (R[18] == R[17]); R[4] = R[17] + R[0]; if (_c) { goto L_800A93C8; } }  /* 0x800A9390 */
    R[3] = R[0] + 102;  /* 0x800A9398 */
    R[3] = R[3] - R[4];  /* 0x800A939C */
    R[3] = R[3] << 1;  /* 0x800A93A0 */
    R[2] = 0x8013u << 16;  /* 0x800A93A4 */
    R[2] = R[2] - 18984;  /* 0x800A93A8 */
    { uint32_t _c = (R[4] == R[18]); R[2] = R[3] + R[2]; if (_c) { goto L_800A93C8; } }  /* 0x800A93AC */
    R[3] = R[0] + 24736;  /* 0x800A93B4 */
L_800A93B8:;
    sh_(R[2], R[3]);  /* 0x800A93B8 */
    R[4] = R[4] + 1;  /* 0x800A93BC */
    { uint32_t _c = (R[4] != R[18]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93B8; } }  /* 0x800A93C0 */
L_800A93C8:;
    R[3] = R[0] + 102;  /* 0x800A93C8 */
    { uint32_t _c = (R[18] == R[3]); R[4] = R[18] + R[0]; if (_c) { goto L_800A9400; } }  /* 0x800A93CC */
    R[3] = R[3] - R[4];  /* 0x800A93D4 */
    R[3] = R[3] << 1;  /* 0x800A93D8 */
    R[2] = 0x8013u << 16;  /* 0x800A93DC */
    R[2] = R[2] - 18984;  /* 0x800A93E0 */
    R[2] = R[3] + R[2];  /* 0x800A93E4 */
    R[5] = R[0] | 0x8421;  /* 0x800A93E8 */
    R[3] = R[0] + 102;  /* 0x800A93EC */
L_800A93F0:;
    sh_(R[2], R[5]);  /* 0x800A93F0 */
    R[4] = R[4] + 1;  /* 0x800A93F4 */
    { uint32_t _c = (R[4] != R[3]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93F0; } }  /* 0x800A93F8 */
L_800A9400:;
    R[4] = 0x8013u << 16;  /* 0x800A9400 */
    R[3] = lw_(R[4] + -18632);  /* 0x800A9404 */
    R[2] = R[20] + R[0];  /* 0x800A9408 */
    R[3] = R[3] | 0x2;  /* 0x800A940C */
    sw_(R[4] + -18632, R[3]);  /* 0x800A9410 */
L_800A9414:;
    R[31] = lw_(R[29] + 60);  /* 0x800A9414 */
    R[30] = lw_(R[29] + 56);  /* 0x800A9418 */
    R[23] = lw_(R[29] + 52);  /* 0x800A941C */
    R[22] = lw_(R[29] + 48);  /* 0x800A9420 */
    R[21] = lw_(R[29] + 44);  /* 0x800A9424 */
    R[20] = lw_(R[29] + 40);  /* 0x800A9428 */
    R[19] = lw_(R[29] + 36);  /* 0x800A942C */
    R[18] = lw_(R[29] + 32);  /* 0x800A9430 */
    R[17] = lw_(R[29] + 28);  /* 0x800A9434 */
    R[16] = lw_(R[29] + 24);  /* 0x800A9438 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A943C jr ra */
}

void g0_800A8F38(void) {
    R[3] = 0x8013u << 16;  /* 0x800A8F38 */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18716);  /* 0x800A8F3C */
    R[3] = R[2] + R[0];  /* 0x800A8F40 */
    R[2] = R[3] << 16;  /* 0x800A8F44 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8F48 */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A8F4C */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A8F70; } }  /* 0x800A8F50 */
    R[2] = R[9] + 10;  /* 0x800A8F58 */
    R[9] = R[2] + R[0];  /* 0x800A8F5C */
    R[2] = R[2] << 16;  /* 0x800A8F60 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8F64 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A8F8C; }  /* 0x800A8F68 j */
L_800A8F70:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A8F70 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A8F98; } }  /* 0x800A8F74 */
    R[9] = R[2] + R[0];  /* 0x800A8F7C */
    R[2] = R[2] << 16;  /* 0x800A8F80 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8F84 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A8F88 */
L_800A8F8C:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A8F9C; } }  /* 0x800A8F8C */
    R[9] = R[3] + R[0];  /* 0x800A8F94 */
L_800A8F98:;
    R[4] = R[20] + R[0];  /* 0x800A8F98 */
L_800A8F9C:;
    R[5] = R[23] + R[0];  /* 0x800A8F9C */
    R[6] = R[30] + R[0];  /* 0x800A8FA0 */
    R[7] = R[22] << 16;  /* 0x800A8FA4 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A8FA8 */
    R[16] = 0x8013u << 16;  /* 0x800A8FAC */
    R[3] = R[9] << 16;  /* 0x800A8FB0 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A8FB4 */
    R[2] = R[21] << 16;  /* 0x800A8FB8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A8FBC */
    sw_(R[16] + -18716, R[3]);  /* 0x800A8FC0 */
    sw_(R[29] + 16, R[2]);  /* 0x800A8FC4 */
    { R[31] = 0x800A8FD0u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A8FC8 jal */
    R[6] = 0x8334u << 16;  /* 0x800A8FD0 */
    R[3] = 0x8013u << 16;  /* 0x800A8FD4 */
    R[3] = lw_(R[3] + -18636);  /* 0x800A8FD8 */
    R[6] = R[6] | 0x521;  /* 0x800A8FDC */
    R[4] = R[3] << 1;  /* 0x800A8FE0 */
    R[4] = R[4] + R[3];  /* 0x800A8FE4 */
    R[3] = R[4] << 4;  /* 0x800A8FE8 */
    R[4] = R[4] + R[3];  /* 0x800A8FEC */
    R[4] = R[4] << 1;  /* 0x800A8FF0 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A8FF4 */
    R[5] = lw_(R[16] + -18716);  /* 0x800A8FF8 */
    R[3] = R[5] << 1;  /* 0x800A9000 */
    R[3] = R[3] + R[5];  /* 0x800A9004 */
    R[5] = R[3] << 4;  /* 0x800A9008 */
    R[7] = HI;  /* 0x800A900C */
    R[3] = R[3] + R[5];  /* 0x800A9010 */
    R[3] = R[3] << 1;  /* 0x800A9014 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9018 */
    R[20] = R[2] + R[0];  /* 0x800A901C */
    R[2] = R[7] + R[4];  /* 0x800A9020 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9024 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A9028 */
    R[17] = R[2] - R[4];  /* 0x800A902C */
    R[8] = HI;  /* 0x800A9030 */
    R[2] = R[8] + R[3];  /* 0x800A9034 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9038 */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x800A903C */
    { R[31] = 0x800A9048u; R[18] = R[2] - R[3]; psx_next = 0x8001D1B8u; return; }  /* 0x800A9040 jal */
    R[4] = 0x6666u << 16;  /* 0x800A9048 */
    R[4] = R[4] | 0x6667;  /* 0x800A904C */
    R[2] = R[2] << 16;  /* 0x800A9050 */
    R[3] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9054 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9058 */
    R[19] = R[0] + 21;  /* 0x800A905C */
    R[2] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x800A9060 */
    R[3] = HI;  /* 0x800A9064 */
    R[16] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x800A9068 */
    { R[31] = 0x800A9074u; R[16] = R[16] - R[2]; psx_next = 0x8001D16Cu; return; }  /* 0x800A906C jal */
    R[2] = R[2] << 16;  /* 0x800A9074 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9078 */
    R[16] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800A907C */
    { uint32_t _c = (R[16] != R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_800A90F0; } }  /* 0x800A9080 */
    R[2] = lw_(R[4] + -18728);  /* 0x800A9088 */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800A90BC; } }  /* 0x800A9090 */
    R[2] = lw_(R[3] + -18720);  /* 0x800A9098 */
    R[2] = R[2] - 1;  /* 0x800A90A0 */
    sw_(R[3] + -18720, R[2]);  /* 0x800A90A4 */
    R[2] = ((int32_t)R[2] < -3);  /* 0x800A90A8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A90E4; } }  /* 0x800A90AC */
    { sw_(R[4] + -18728, R[0]); goto L_800A90E4; }  /* 0x800A90B4 j */
L_800A90BC:;
    R[2] = lw_(R[3] + -18720);  /* 0x800A90BC */
    R[2] = R[2] + 1;  /* 0x800A90C4 */
    sw_(R[3] + -18720, R[2]);  /* 0x800A90C8 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x800A90CC */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A90E4; } }  /* 0x800A90D0 */
    R[2] = R[0] + 1;  /* 0x800A90D8 */
    sw_(R[4] + -18728, R[2]);  /* 0x800A90DC */
    R[2] = 0x8013u << 16;  /* 0x800A90E0 */
L_800A90E4:;
    R[2] = lh_(R[2] + -18720);  /* 0x800A90E4 */
    R[19] = R[19] + R[2];  /* 0x800A90EC */
L_800A90F0:;
    { uint32_t _c = (R[17] == R[0]); R[5] = R[19] + R[0]; if (_c) { goto L_800A911C; } }  /* 0x800A90F0 */
    R[4] = R[0] + R[0];  /* 0x800A90F8 */
    R[2] = 0x8013u << 16;  /* 0x800A90FC */
    R[2] = R[2] - 18624;  /* 0x800A9100 */
    R[2] = R[2] + 204;  /* 0x800A9104 */
    R[3] = R[0] + 7006;  /* 0x800A9108 */
L_800A910C:;
    sh_(R[2], R[3]);  /* 0x800A910C */
    R[4] = R[4] + 1;  /* 0x800A9110 */
    { uint32_t _c = (R[4] != R[17]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A910C; } }  /* 0x800A9114 */
L_800A911C:;
    { uint32_t _c = (R[18] == R[17]); R[4] = R[17] + R[0]; if (_c) { goto L_800A9150; } }  /* 0x800A911C */
    R[3] = R[0] + 102;  /* 0x800A9124 */
    R[3] = R[3] - R[4];  /* 0x800A9128 */
    R[3] = R[3] << 1;  /* 0x800A912C */
    R[2] = 0x8013u << 16;  /* 0x800A9130 */
    R[2] = R[2] - 18624;  /* 0x800A9134 */
    { uint32_t _c = (R[4] == R[18]); R[2] = R[3] + R[2]; if (_c) { goto L_800A9150; } }  /* 0x800A9138 */
L_800A9140:;
    sh_(R[2], R[5]);  /* 0x800A9140 */
    R[4] = R[4] + 1;  /* 0x800A9144 */
    { uint32_t _c = (R[4] != R[18]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9140; } }  /* 0x800A9148 */
L_800A9150:;
    R[3] = R[0] + 102;  /* 0x800A9150 */
    { uint32_t _c = (R[18] == R[3]); R[4] = R[18] + R[0]; if (_c) { goto L_800A9188; } }  /* 0x800A9154 */
    R[3] = R[3] - R[4];  /* 0x800A915C */
    R[3] = R[3] << 1;  /* 0x800A9160 */
    R[2] = 0x8013u << 16;  /* 0x800A9164 */
    R[2] = R[2] - 18624;  /* 0x800A9168 */
    R[2] = R[3] + R[2];  /* 0x800A916C */
    R[5] = R[0] | 0x8421;  /* 0x800A9170 */
    R[3] = R[0] + 102;  /* 0x800A9174 */
L_800A9178:;
    sh_(R[2], R[5]);  /* 0x800A9178 */
    R[4] = R[4] + 1;  /* 0x800A917C */
    { uint32_t _c = (R[4] != R[3]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9178; } }  /* 0x800A9180 */
L_800A9188:;
    R[4] = 0x8013u << 16;  /* 0x800A9188 */
    R[3] = 0x8006u << 16;  /* 0x800A918C */
    R[2] = lw_(R[4] + -18632);  /* 0x800A9190 */
    R[3] = lb_(R[3] + 15333);  /* 0x800A9194 */
    R[2] = R[2] | 0x1;  /* 0x800A9198 */
    { uint32_t _c = (R[3] != R[0]); sw_(R[4] + -18632, R[2]); if (_c) { goto L_800A91AC; } }  /* 0x800A919C */
    { R[2] = R[20] + R[0]; goto L_800A9414; }  /* 0x800A91A4 j */
L_800A91AC:;
    { R[31] = 0x800A91B4u; psx_next = 0x8001D258u; return; }  /* 0x800A91AC jal */
    R[3] = 0x8013u << 16;  /* 0x800A91B4 */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18640);  /* 0x800A91B8 */
    R[3] = R[2] + R[0];  /* 0x800A91BC */
    R[2] = R[3] << 16;  /* 0x800A91C0 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A91C4 */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A91C8 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A91EC; } }  /* 0x800A91CC */
    R[2] = R[9] + 10;  /* 0x800A91D4 */
    R[9] = R[2] + R[0];  /* 0x800A91D8 */
    R[2] = R[2] << 16;  /* 0x800A91DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A91E0 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A9208; }  /* 0x800A91E4 j */
L_800A91EC:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A91EC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A9214; } }  /* 0x800A91F0 */
    R[9] = R[2] + R[0];  /* 0x800A91F8 */
    R[2] = R[2] << 16;  /* 0x800A91FC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9200 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A9204 */
L_800A9208:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A9218; } }  /* 0x800A9208 */
    R[9] = R[3] + R[0];  /* 0x800A9210 */
L_800A9214:;
    R[4] = R[20] + R[0];  /* 0x800A9214 */
L_800A9218:;
    R[5] = R[23] + R[0];  /* 0x800A9218 */
    R[6] = R[30] + R[0];  /* 0x800A921C */
    R[7] = R[22] << 16;  /* 0x800A9220 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A9224 */
    R[2] = 0x8013u << 16;  /* 0x800A9228 */
    R[3] = R[9] << 16;  /* 0x800A922C */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A9230 */
    R[16] = R[21] + 26;  /* 0x800A9234 */
    sw_(R[2] + -18640, R[3]);  /* 0x800A9238 */
    R[2] = R[16] << 16;  /* 0x800A923C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9240 */
    sw_(R[29] + 16, R[2]);  /* 0x800A9244 */
    { R[31] = 0x800A9250u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A9248 jal */
    R[20] = R[2] + R[0];  /* 0x800A9250 */
    { R[31] = 0x800A925Cu; R[21] = R[16] + 9; psx_next = 0x8001D2A4u; return; }  /* 0x800A9254 jal */
    R[3] = 0x8013u << 16;  /* 0x800A925C */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18724);  /* 0x800A9260 */
    R[3] = R[2] + R[0];  /* 0x800A9264 */
    R[2] = R[3] << 16;  /* 0x800A9268 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A926C */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A9270 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A9294; } }  /* 0x800A9274 */
    R[2] = R[9] + 10;  /* 0x800A927C */
    R[9] = R[2] + R[0];  /* 0x800A9280 */
    R[2] = R[2] << 16;  /* 0x800A9284 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9288 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A92B0; }  /* 0x800A928C j */
L_800A9294:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A9294 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A92BC; } }  /* 0x800A9298 */
    R[9] = R[2] + R[0];  /* 0x800A92A0 */
    R[2] = R[2] << 16;  /* 0x800A92A4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92A8 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A92AC */
L_800A92B0:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A92C0; } }  /* 0x800A92B0 */
    R[9] = R[3] + R[0];  /* 0x800A92B8 */
L_800A92BC:;
    R[4] = R[20] + R[0];  /* 0x800A92BC */
L_800A92C0:;
    R[5] = R[23] + R[0];  /* 0x800A92C0 */
    R[6] = R[30] + R[0];  /* 0x800A92C4 */
    R[7] = R[22] << 16;  /* 0x800A92C8 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A92CC */
    R[16] = 0x8013u << 16;  /* 0x800A92D0 */
    R[3] = R[9] << 16;  /* 0x800A92D4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A92D8 */
    R[2] = R[21] << 16;  /* 0x800A92DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92E0 */
    sw_(R[16] + -18724, R[3]);  /* 0x800A92E4 */
    sw_(R[29] + 16, R[2]);  /* 0x800A92E8 */
    { R[31] = 0x800A92F4u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A92EC jal */
    R[6] = 0x8334u << 16;  /* 0x800A92F4 */
    R[3] = 0x8013u << 16;  /* 0x800A92F8 */
    R[3] = lw_(R[3] + -18640);  /* 0x800A92FC */
    R[6] = R[6] | 0x521;  /* 0x800A9300 */
    R[4] = R[3] << 1;  /* 0x800A9304 */
    R[4] = R[4] + R[3];  /* 0x800A9308 */
    R[3] = R[4] << 4;  /* 0x800A930C */
    R[4] = R[4] + R[3];  /* 0x800A9310 */
    R[4] = R[4] << 1;  /* 0x800A9314 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9318 */
    R[5] = lw_(R[16] + -18724);  /* 0x800A931C */
    R[3] = R[5] << 1;  /* 0x800A9324 */
    R[3] = R[3] + R[5];  /* 0x800A9328 */
    R[5] = R[3] << 4;  /* 0x800A932C */
    R[7] = HI;  /* 0x800A9330 */
    R[3] = R[3] + R[5];  /* 0x800A9334 */
    R[3] = R[3] << 1;  /* 0x800A9338 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A933C */
    R[20] = R[2] + R[0];  /* 0x800A9340 */
    R[2] = R[7] + R[4];  /* 0x800A9344 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9348 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A934C */
    R[17] = R[2] - R[4];  /* 0x800A9350 */
    R[8] = HI;  /* 0x800A9354 */
    R[2] = R[8] + R[3];  /* 0x800A9358 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A935C */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x800A9360 */
    { uint32_t _c = (R[17] == R[0]); R[18] = R[2] - R[3]; if (_c) { goto L_800A9390; } }  /* 0x800A9364 */
    R[4] = R[0] + R[0];  /* 0x800A936C */
    R[2] = 0x8013u << 16;  /* 0x800A9370 */
    R[2] = R[2] - 18984;  /* 0x800A9374 */
    R[2] = R[2] + 204;  /* 0x800A9378 */
    R[3] = R[0] + 5797;  /* 0x800A937C */
L_800A9380:;
    sh_(R[2], R[3]);  /* 0x800A9380 */
    R[4] = R[4] + 1;  /* 0x800A9384 */
    { uint32_t _c = (R[4] != R[17]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9380; } }  /* 0x800A9388 */
L_800A9390:;
    { uint32_t _c = (R[18] == R[17]); R[4] = R[17] + R[0]; if (_c) { goto L_800A93C8; } }  /* 0x800A9390 */
    R[3] = R[0] + 102;  /* 0x800A9398 */
    R[3] = R[3] - R[4];  /* 0x800A939C */
    R[3] = R[3] << 1;  /* 0x800A93A0 */
    R[2] = 0x8013u << 16;  /* 0x800A93A4 */
    R[2] = R[2] - 18984;  /* 0x800A93A8 */
    { uint32_t _c = (R[4] == R[18]); R[2] = R[3] + R[2]; if (_c) { goto L_800A93C8; } }  /* 0x800A93AC */
    R[3] = R[0] + 24736;  /* 0x800A93B4 */
L_800A93B8:;
    sh_(R[2], R[3]);  /* 0x800A93B8 */
    R[4] = R[4] + 1;  /* 0x800A93BC */
    { uint32_t _c = (R[4] != R[18]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93B8; } }  /* 0x800A93C0 */
L_800A93C8:;
    R[3] = R[0] + 102;  /* 0x800A93C8 */
    { uint32_t _c = (R[18] == R[3]); R[4] = R[18] + R[0]; if (_c) { goto L_800A9400; } }  /* 0x800A93CC */
    R[3] = R[3] - R[4];  /* 0x800A93D4 */
    R[3] = R[3] << 1;  /* 0x800A93D8 */
    R[2] = 0x8013u << 16;  /* 0x800A93DC */
    R[2] = R[2] - 18984;  /* 0x800A93E0 */
    R[2] = R[3] + R[2];  /* 0x800A93E4 */
    R[5] = R[0] | 0x8421;  /* 0x800A93E8 */
    R[3] = R[0] + 102;  /* 0x800A93EC */
L_800A93F0:;
    sh_(R[2], R[5]);  /* 0x800A93F0 */
    R[4] = R[4] + 1;  /* 0x800A93F4 */
    { uint32_t _c = (R[4] != R[3]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93F0; } }  /* 0x800A93F8 */
L_800A9400:;
    R[4] = 0x8013u << 16;  /* 0x800A9400 */
    R[3] = lw_(R[4] + -18632);  /* 0x800A9404 */
    R[2] = R[20] + R[0];  /* 0x800A9408 */
    R[3] = R[3] | 0x2;  /* 0x800A940C */
    sw_(R[4] + -18632, R[3]);  /* 0x800A9410 */
L_800A9414:;
    R[31] = lw_(R[29] + 60);  /* 0x800A9414 */
    R[30] = lw_(R[29] + 56);  /* 0x800A9418 */
    R[23] = lw_(R[29] + 52);  /* 0x800A941C */
    R[22] = lw_(R[29] + 48);  /* 0x800A9420 */
    R[21] = lw_(R[29] + 44);  /* 0x800A9424 */
    R[20] = lw_(R[29] + 40);  /* 0x800A9428 */
    R[19] = lw_(R[29] + 36);  /* 0x800A942C */
    R[18] = lw_(R[29] + 32);  /* 0x800A9430 */
    R[17] = lw_(R[29] + 28);  /* 0x800A9434 */
    R[16] = lw_(R[29] + 24);  /* 0x800A9438 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A943C jr ra */
}

void g0_800A8FD0(void) {
    R[6] = 0x8334u << 16;  /* 0x800A8FD0 */
    R[3] = 0x8013u << 16;  /* 0x800A8FD4 */
    R[3] = lw_(R[3] + -18636);  /* 0x800A8FD8 */
    R[6] = R[6] | 0x521;  /* 0x800A8FDC */
    R[4] = R[3] << 1;  /* 0x800A8FE0 */
    R[4] = R[4] + R[3];  /* 0x800A8FE4 */
    R[3] = R[4] << 4;  /* 0x800A8FE8 */
    R[4] = R[4] + R[3];  /* 0x800A8FEC */
    R[4] = R[4] << 1;  /* 0x800A8FF0 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A8FF4 */
    R[5] = lw_(R[16] + -18716);  /* 0x800A8FF8 */
    R[3] = R[5] << 1;  /* 0x800A9000 */
    R[3] = R[3] + R[5];  /* 0x800A9004 */
    R[5] = R[3] << 4;  /* 0x800A9008 */
    R[7] = HI;  /* 0x800A900C */
    R[3] = R[3] + R[5];  /* 0x800A9010 */
    R[3] = R[3] << 1;  /* 0x800A9014 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9018 */
    R[20] = R[2] + R[0];  /* 0x800A901C */
    R[2] = R[7] + R[4];  /* 0x800A9020 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9024 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A9028 */
    R[17] = R[2] - R[4];  /* 0x800A902C */
    R[8] = HI;  /* 0x800A9030 */
    R[2] = R[8] + R[3];  /* 0x800A9034 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9038 */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x800A903C */
    { R[31] = 0x800A9048u; R[18] = R[2] - R[3]; psx_next = 0x8001D1B8u; return; }  /* 0x800A9040 jal */
    R[4] = 0x6666u << 16;  /* 0x800A9048 */
    R[4] = R[4] | 0x6667;  /* 0x800A904C */
    R[2] = R[2] << 16;  /* 0x800A9050 */
    R[3] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9054 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9058 */
    R[19] = R[0] + 21;  /* 0x800A905C */
    R[2] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x800A9060 */
    R[3] = HI;  /* 0x800A9064 */
    R[16] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x800A9068 */
    { R[31] = 0x800A9074u; R[16] = R[16] - R[2]; psx_next = 0x8001D16Cu; return; }  /* 0x800A906C jal */
    R[2] = R[2] << 16;  /* 0x800A9074 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9078 */
    R[16] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800A907C */
    { uint32_t _c = (R[16] != R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_800A90F0; } }  /* 0x800A9080 */
    R[2] = lw_(R[4] + -18728);  /* 0x800A9088 */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800A90BC; } }  /* 0x800A9090 */
    R[2] = lw_(R[3] + -18720);  /* 0x800A9098 */
    R[2] = R[2] - 1;  /* 0x800A90A0 */
    sw_(R[3] + -18720, R[2]);  /* 0x800A90A4 */
    R[2] = ((int32_t)R[2] < -3);  /* 0x800A90A8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A90E4; } }  /* 0x800A90AC */
    { sw_(R[4] + -18728, R[0]); goto L_800A90E4; }  /* 0x800A90B4 j */
L_800A90BC:;
    R[2] = lw_(R[3] + -18720);  /* 0x800A90BC */
    R[2] = R[2] + 1;  /* 0x800A90C4 */
    sw_(R[3] + -18720, R[2]);  /* 0x800A90C8 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x800A90CC */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A90E4; } }  /* 0x800A90D0 */
    R[2] = R[0] + 1;  /* 0x800A90D8 */
    sw_(R[4] + -18728, R[2]);  /* 0x800A90DC */
    R[2] = 0x8013u << 16;  /* 0x800A90E0 */
L_800A90E4:;
    R[2] = lh_(R[2] + -18720);  /* 0x800A90E4 */
    R[19] = R[19] + R[2];  /* 0x800A90EC */
L_800A90F0:;
    { uint32_t _c = (R[17] == R[0]); R[5] = R[19] + R[0]; if (_c) { goto L_800A911C; } }  /* 0x800A90F0 */
    R[4] = R[0] + R[0];  /* 0x800A90F8 */
    R[2] = 0x8013u << 16;  /* 0x800A90FC */
    R[2] = R[2] - 18624;  /* 0x800A9100 */
    R[2] = R[2] + 204;  /* 0x800A9104 */
    R[3] = R[0] + 7006;  /* 0x800A9108 */
L_800A910C:;
    sh_(R[2], R[3]);  /* 0x800A910C */
    R[4] = R[4] + 1;  /* 0x800A9110 */
    { uint32_t _c = (R[4] != R[17]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A910C; } }  /* 0x800A9114 */
L_800A911C:;
    { uint32_t _c = (R[18] == R[17]); R[4] = R[17] + R[0]; if (_c) { goto L_800A9150; } }  /* 0x800A911C */
    R[3] = R[0] + 102;  /* 0x800A9124 */
    R[3] = R[3] - R[4];  /* 0x800A9128 */
    R[3] = R[3] << 1;  /* 0x800A912C */
    R[2] = 0x8013u << 16;  /* 0x800A9130 */
    R[2] = R[2] - 18624;  /* 0x800A9134 */
    { uint32_t _c = (R[4] == R[18]); R[2] = R[3] + R[2]; if (_c) { goto L_800A9150; } }  /* 0x800A9138 */
L_800A9140:;
    sh_(R[2], R[5]);  /* 0x800A9140 */
    R[4] = R[4] + 1;  /* 0x800A9144 */
    { uint32_t _c = (R[4] != R[18]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9140; } }  /* 0x800A9148 */
L_800A9150:;
    R[3] = R[0] + 102;  /* 0x800A9150 */
    { uint32_t _c = (R[18] == R[3]); R[4] = R[18] + R[0]; if (_c) { goto L_800A9188; } }  /* 0x800A9154 */
    R[3] = R[3] - R[4];  /* 0x800A915C */
    R[3] = R[3] << 1;  /* 0x800A9160 */
    R[2] = 0x8013u << 16;  /* 0x800A9164 */
    R[2] = R[2] - 18624;  /* 0x800A9168 */
    R[2] = R[3] + R[2];  /* 0x800A916C */
    R[5] = R[0] | 0x8421;  /* 0x800A9170 */
    R[3] = R[0] + 102;  /* 0x800A9174 */
L_800A9178:;
    sh_(R[2], R[5]);  /* 0x800A9178 */
    R[4] = R[4] + 1;  /* 0x800A917C */
    { uint32_t _c = (R[4] != R[3]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9178; } }  /* 0x800A9180 */
L_800A9188:;
    R[4] = 0x8013u << 16;  /* 0x800A9188 */
    R[3] = 0x8006u << 16;  /* 0x800A918C */
    R[2] = lw_(R[4] + -18632);  /* 0x800A9190 */
    R[3] = lb_(R[3] + 15333);  /* 0x800A9194 */
    R[2] = R[2] | 0x1;  /* 0x800A9198 */
    { uint32_t _c = (R[3] != R[0]); sw_(R[4] + -18632, R[2]); if (_c) { goto L_800A91AC; } }  /* 0x800A919C */
    { R[2] = R[20] + R[0]; goto L_800A9414; }  /* 0x800A91A4 j */
L_800A91AC:;
    { R[31] = 0x800A91B4u; psx_next = 0x8001D258u; return; }  /* 0x800A91AC jal */
    R[3] = 0x8013u << 16;  /* 0x800A91B4 */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18640);  /* 0x800A91B8 */
    R[3] = R[2] + R[0];  /* 0x800A91BC */
    R[2] = R[3] << 16;  /* 0x800A91C0 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A91C4 */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A91C8 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A91EC; } }  /* 0x800A91CC */
    R[2] = R[9] + 10;  /* 0x800A91D4 */
    R[9] = R[2] + R[0];  /* 0x800A91D8 */
    R[2] = R[2] << 16;  /* 0x800A91DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A91E0 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A9208; }  /* 0x800A91E4 j */
L_800A91EC:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A91EC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A9214; } }  /* 0x800A91F0 */
    R[9] = R[2] + R[0];  /* 0x800A91F8 */
    R[2] = R[2] << 16;  /* 0x800A91FC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9200 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A9204 */
L_800A9208:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A9218; } }  /* 0x800A9208 */
    R[9] = R[3] + R[0];  /* 0x800A9210 */
L_800A9214:;
    R[4] = R[20] + R[0];  /* 0x800A9214 */
L_800A9218:;
    R[5] = R[23] + R[0];  /* 0x800A9218 */
    R[6] = R[30] + R[0];  /* 0x800A921C */
    R[7] = R[22] << 16;  /* 0x800A9220 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A9224 */
    R[2] = 0x8013u << 16;  /* 0x800A9228 */
    R[3] = R[9] << 16;  /* 0x800A922C */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A9230 */
    R[16] = R[21] + 26;  /* 0x800A9234 */
    sw_(R[2] + -18640, R[3]);  /* 0x800A9238 */
    R[2] = R[16] << 16;  /* 0x800A923C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9240 */
    sw_(R[29] + 16, R[2]);  /* 0x800A9244 */
    { R[31] = 0x800A9250u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A9248 jal */
    R[20] = R[2] + R[0];  /* 0x800A9250 */
    { R[31] = 0x800A925Cu; R[21] = R[16] + 9; psx_next = 0x8001D2A4u; return; }  /* 0x800A9254 jal */
    R[3] = 0x8013u << 16;  /* 0x800A925C */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18724);  /* 0x800A9260 */
    R[3] = R[2] + R[0];  /* 0x800A9264 */
    R[2] = R[3] << 16;  /* 0x800A9268 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A926C */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A9270 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A9294; } }  /* 0x800A9274 */
    R[2] = R[9] + 10;  /* 0x800A927C */
    R[9] = R[2] + R[0];  /* 0x800A9280 */
    R[2] = R[2] << 16;  /* 0x800A9284 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9288 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A92B0; }  /* 0x800A928C j */
L_800A9294:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A9294 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A92BC; } }  /* 0x800A9298 */
    R[9] = R[2] + R[0];  /* 0x800A92A0 */
    R[2] = R[2] << 16;  /* 0x800A92A4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92A8 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A92AC */
L_800A92B0:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A92C0; } }  /* 0x800A92B0 */
    R[9] = R[3] + R[0];  /* 0x800A92B8 */
L_800A92BC:;
    R[4] = R[20] + R[0];  /* 0x800A92BC */
L_800A92C0:;
    R[5] = R[23] + R[0];  /* 0x800A92C0 */
    R[6] = R[30] + R[0];  /* 0x800A92C4 */
    R[7] = R[22] << 16;  /* 0x800A92C8 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A92CC */
    R[16] = 0x8013u << 16;  /* 0x800A92D0 */
    R[3] = R[9] << 16;  /* 0x800A92D4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A92D8 */
    R[2] = R[21] << 16;  /* 0x800A92DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92E0 */
    sw_(R[16] + -18724, R[3]);  /* 0x800A92E4 */
    sw_(R[29] + 16, R[2]);  /* 0x800A92E8 */
    { R[31] = 0x800A92F4u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A92EC jal */
    R[6] = 0x8334u << 16;  /* 0x800A92F4 */
    R[3] = 0x8013u << 16;  /* 0x800A92F8 */
    R[3] = lw_(R[3] + -18640);  /* 0x800A92FC */
    R[6] = R[6] | 0x521;  /* 0x800A9300 */
    R[4] = R[3] << 1;  /* 0x800A9304 */
    R[4] = R[4] + R[3];  /* 0x800A9308 */
    R[3] = R[4] << 4;  /* 0x800A930C */
    R[4] = R[4] + R[3];  /* 0x800A9310 */
    R[4] = R[4] << 1;  /* 0x800A9314 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9318 */
    R[5] = lw_(R[16] + -18724);  /* 0x800A931C */
    R[3] = R[5] << 1;  /* 0x800A9324 */
    R[3] = R[3] + R[5];  /* 0x800A9328 */
    R[5] = R[3] << 4;  /* 0x800A932C */
    R[7] = HI;  /* 0x800A9330 */
    R[3] = R[3] + R[5];  /* 0x800A9334 */
    R[3] = R[3] << 1;  /* 0x800A9338 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A933C */
    R[20] = R[2] + R[0];  /* 0x800A9340 */
    R[2] = R[7] + R[4];  /* 0x800A9344 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9348 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A934C */
    R[17] = R[2] - R[4];  /* 0x800A9350 */
    R[8] = HI;  /* 0x800A9354 */
    R[2] = R[8] + R[3];  /* 0x800A9358 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A935C */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x800A9360 */
    { uint32_t _c = (R[17] == R[0]); R[18] = R[2] - R[3]; if (_c) { goto L_800A9390; } }  /* 0x800A9364 */
    R[4] = R[0] + R[0];  /* 0x800A936C */
    R[2] = 0x8013u << 16;  /* 0x800A9370 */
    R[2] = R[2] - 18984;  /* 0x800A9374 */
    R[2] = R[2] + 204;  /* 0x800A9378 */
    R[3] = R[0] + 5797;  /* 0x800A937C */
L_800A9380:;
    sh_(R[2], R[3]);  /* 0x800A9380 */
    R[4] = R[4] + 1;  /* 0x800A9384 */
    { uint32_t _c = (R[4] != R[17]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9380; } }  /* 0x800A9388 */
L_800A9390:;
    { uint32_t _c = (R[18] == R[17]); R[4] = R[17] + R[0]; if (_c) { goto L_800A93C8; } }  /* 0x800A9390 */
    R[3] = R[0] + 102;  /* 0x800A9398 */
    R[3] = R[3] - R[4];  /* 0x800A939C */
    R[3] = R[3] << 1;  /* 0x800A93A0 */
    R[2] = 0x8013u << 16;  /* 0x800A93A4 */
    R[2] = R[2] - 18984;  /* 0x800A93A8 */
    { uint32_t _c = (R[4] == R[18]); R[2] = R[3] + R[2]; if (_c) { goto L_800A93C8; } }  /* 0x800A93AC */
    R[3] = R[0] + 24736;  /* 0x800A93B4 */
L_800A93B8:;
    sh_(R[2], R[3]);  /* 0x800A93B8 */
    R[4] = R[4] + 1;  /* 0x800A93BC */
    { uint32_t _c = (R[4] != R[18]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93B8; } }  /* 0x800A93C0 */
L_800A93C8:;
    R[3] = R[0] + 102;  /* 0x800A93C8 */
    { uint32_t _c = (R[18] == R[3]); R[4] = R[18] + R[0]; if (_c) { goto L_800A9400; } }  /* 0x800A93CC */
    R[3] = R[3] - R[4];  /* 0x800A93D4 */
    R[3] = R[3] << 1;  /* 0x800A93D8 */
    R[2] = 0x8013u << 16;  /* 0x800A93DC */
    R[2] = R[2] - 18984;  /* 0x800A93E0 */
    R[2] = R[3] + R[2];  /* 0x800A93E4 */
    R[5] = R[0] | 0x8421;  /* 0x800A93E8 */
    R[3] = R[0] + 102;  /* 0x800A93EC */
L_800A93F0:;
    sh_(R[2], R[5]);  /* 0x800A93F0 */
    R[4] = R[4] + 1;  /* 0x800A93F4 */
    { uint32_t _c = (R[4] != R[3]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93F0; } }  /* 0x800A93F8 */
L_800A9400:;
    R[4] = 0x8013u << 16;  /* 0x800A9400 */
    R[3] = lw_(R[4] + -18632);  /* 0x800A9404 */
    R[2] = R[20] + R[0];  /* 0x800A9408 */
    R[3] = R[3] | 0x2;  /* 0x800A940C */
    sw_(R[4] + -18632, R[3]);  /* 0x800A9410 */
L_800A9414:;
    R[31] = lw_(R[29] + 60);  /* 0x800A9414 */
    R[30] = lw_(R[29] + 56);  /* 0x800A9418 */
    R[23] = lw_(R[29] + 52);  /* 0x800A941C */
    R[22] = lw_(R[29] + 48);  /* 0x800A9420 */
    R[21] = lw_(R[29] + 44);  /* 0x800A9424 */
    R[20] = lw_(R[29] + 40);  /* 0x800A9428 */
    R[19] = lw_(R[29] + 36);  /* 0x800A942C */
    R[18] = lw_(R[29] + 32);  /* 0x800A9430 */
    R[17] = lw_(R[29] + 28);  /* 0x800A9434 */
    R[16] = lw_(R[29] + 24);  /* 0x800A9438 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A943C jr ra */
}

void g0_800A9048(void) {
    R[4] = 0x6666u << 16;  /* 0x800A9048 */
    R[4] = R[4] | 0x6667;  /* 0x800A904C */
    R[2] = R[2] << 16;  /* 0x800A9050 */
    R[3] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9054 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9058 */
    R[19] = R[0] + 21;  /* 0x800A905C */
    R[2] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x800A9060 */
    R[3] = HI;  /* 0x800A9064 */
    R[16] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x800A9068 */
    { R[31] = 0x800A9074u; R[16] = R[16] - R[2]; psx_next = 0x8001D16Cu; return; }  /* 0x800A906C jal */
    R[2] = R[2] << 16;  /* 0x800A9074 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9078 */
    R[16] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800A907C */
    { uint32_t _c = (R[16] != R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_800A90F0; } }  /* 0x800A9080 */
    R[2] = lw_(R[4] + -18728);  /* 0x800A9088 */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800A90BC; } }  /* 0x800A9090 */
    R[2] = lw_(R[3] + -18720);  /* 0x800A9098 */
    R[2] = R[2] - 1;  /* 0x800A90A0 */
    sw_(R[3] + -18720, R[2]);  /* 0x800A90A4 */
    R[2] = ((int32_t)R[2] < -3);  /* 0x800A90A8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A90E4; } }  /* 0x800A90AC */
    { sw_(R[4] + -18728, R[0]); goto L_800A90E4; }  /* 0x800A90B4 j */
L_800A90BC:;
    R[2] = lw_(R[3] + -18720);  /* 0x800A90BC */
    R[2] = R[2] + 1;  /* 0x800A90C4 */
    sw_(R[3] + -18720, R[2]);  /* 0x800A90C8 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x800A90CC */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A90E4; } }  /* 0x800A90D0 */
    R[2] = R[0] + 1;  /* 0x800A90D8 */
    sw_(R[4] + -18728, R[2]);  /* 0x800A90DC */
    R[2] = 0x8013u << 16;  /* 0x800A90E0 */
L_800A90E4:;
    R[2] = lh_(R[2] + -18720);  /* 0x800A90E4 */
    R[19] = R[19] + R[2];  /* 0x800A90EC */
L_800A90F0:;
    { uint32_t _c = (R[17] == R[0]); R[5] = R[19] + R[0]; if (_c) { goto L_800A911C; } }  /* 0x800A90F0 */
    R[4] = R[0] + R[0];  /* 0x800A90F8 */
    R[2] = 0x8013u << 16;  /* 0x800A90FC */
    R[2] = R[2] - 18624;  /* 0x800A9100 */
    R[2] = R[2] + 204;  /* 0x800A9104 */
    R[3] = R[0] + 7006;  /* 0x800A9108 */
L_800A910C:;
    sh_(R[2], R[3]);  /* 0x800A910C */
    R[4] = R[4] + 1;  /* 0x800A9110 */
    { uint32_t _c = (R[4] != R[17]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A910C; } }  /* 0x800A9114 */
L_800A911C:;
    { uint32_t _c = (R[18] == R[17]); R[4] = R[17] + R[0]; if (_c) { goto L_800A9150; } }  /* 0x800A911C */
    R[3] = R[0] + 102;  /* 0x800A9124 */
    R[3] = R[3] - R[4];  /* 0x800A9128 */
    R[3] = R[3] << 1;  /* 0x800A912C */
    R[2] = 0x8013u << 16;  /* 0x800A9130 */
    R[2] = R[2] - 18624;  /* 0x800A9134 */
    { uint32_t _c = (R[4] == R[18]); R[2] = R[3] + R[2]; if (_c) { goto L_800A9150; } }  /* 0x800A9138 */
L_800A9140:;
    sh_(R[2], R[5]);  /* 0x800A9140 */
    R[4] = R[4] + 1;  /* 0x800A9144 */
    { uint32_t _c = (R[4] != R[18]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9140; } }  /* 0x800A9148 */
L_800A9150:;
    R[3] = R[0] + 102;  /* 0x800A9150 */
    { uint32_t _c = (R[18] == R[3]); R[4] = R[18] + R[0]; if (_c) { goto L_800A9188; } }  /* 0x800A9154 */
    R[3] = R[3] - R[4];  /* 0x800A915C */
    R[3] = R[3] << 1;  /* 0x800A9160 */
    R[2] = 0x8013u << 16;  /* 0x800A9164 */
    R[2] = R[2] - 18624;  /* 0x800A9168 */
    R[2] = R[3] + R[2];  /* 0x800A916C */
    R[5] = R[0] | 0x8421;  /* 0x800A9170 */
    R[3] = R[0] + 102;  /* 0x800A9174 */
L_800A9178:;
    sh_(R[2], R[5]);  /* 0x800A9178 */
    R[4] = R[4] + 1;  /* 0x800A917C */
    { uint32_t _c = (R[4] != R[3]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9178; } }  /* 0x800A9180 */
L_800A9188:;
    R[4] = 0x8013u << 16;  /* 0x800A9188 */
    R[3] = 0x8006u << 16;  /* 0x800A918C */
    R[2] = lw_(R[4] + -18632);  /* 0x800A9190 */
    R[3] = lb_(R[3] + 15333);  /* 0x800A9194 */
    R[2] = R[2] | 0x1;  /* 0x800A9198 */
    { uint32_t _c = (R[3] != R[0]); sw_(R[4] + -18632, R[2]); if (_c) { goto L_800A91AC; } }  /* 0x800A919C */
    { R[2] = R[20] + R[0]; goto L_800A9414; }  /* 0x800A91A4 j */
L_800A91AC:;
    { R[31] = 0x800A91B4u; psx_next = 0x8001D258u; return; }  /* 0x800A91AC jal */
    R[3] = 0x8013u << 16;  /* 0x800A91B4 */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18640);  /* 0x800A91B8 */
    R[3] = R[2] + R[0];  /* 0x800A91BC */
    R[2] = R[3] << 16;  /* 0x800A91C0 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A91C4 */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A91C8 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A91EC; } }  /* 0x800A91CC */
    R[2] = R[9] + 10;  /* 0x800A91D4 */
    R[9] = R[2] + R[0];  /* 0x800A91D8 */
    R[2] = R[2] << 16;  /* 0x800A91DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A91E0 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A9208; }  /* 0x800A91E4 j */
L_800A91EC:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A91EC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A9214; } }  /* 0x800A91F0 */
    R[9] = R[2] + R[0];  /* 0x800A91F8 */
    R[2] = R[2] << 16;  /* 0x800A91FC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9200 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A9204 */
L_800A9208:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A9218; } }  /* 0x800A9208 */
    R[9] = R[3] + R[0];  /* 0x800A9210 */
L_800A9214:;
    R[4] = R[20] + R[0];  /* 0x800A9214 */
L_800A9218:;
    R[5] = R[23] + R[0];  /* 0x800A9218 */
    R[6] = R[30] + R[0];  /* 0x800A921C */
    R[7] = R[22] << 16;  /* 0x800A9220 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A9224 */
    R[2] = 0x8013u << 16;  /* 0x800A9228 */
    R[3] = R[9] << 16;  /* 0x800A922C */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A9230 */
    R[16] = R[21] + 26;  /* 0x800A9234 */
    sw_(R[2] + -18640, R[3]);  /* 0x800A9238 */
    R[2] = R[16] << 16;  /* 0x800A923C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9240 */
    sw_(R[29] + 16, R[2]);  /* 0x800A9244 */
    { R[31] = 0x800A9250u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A9248 jal */
    R[20] = R[2] + R[0];  /* 0x800A9250 */
    { R[31] = 0x800A925Cu; R[21] = R[16] + 9; psx_next = 0x8001D2A4u; return; }  /* 0x800A9254 jal */
    R[3] = 0x8013u << 16;  /* 0x800A925C */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18724);  /* 0x800A9260 */
    R[3] = R[2] + R[0];  /* 0x800A9264 */
    R[2] = R[3] << 16;  /* 0x800A9268 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A926C */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A9270 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A9294; } }  /* 0x800A9274 */
    R[2] = R[9] + 10;  /* 0x800A927C */
    R[9] = R[2] + R[0];  /* 0x800A9280 */
    R[2] = R[2] << 16;  /* 0x800A9284 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9288 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A92B0; }  /* 0x800A928C j */
L_800A9294:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A9294 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A92BC; } }  /* 0x800A9298 */
    R[9] = R[2] + R[0];  /* 0x800A92A0 */
    R[2] = R[2] << 16;  /* 0x800A92A4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92A8 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A92AC */
L_800A92B0:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A92C0; } }  /* 0x800A92B0 */
    R[9] = R[3] + R[0];  /* 0x800A92B8 */
L_800A92BC:;
    R[4] = R[20] + R[0];  /* 0x800A92BC */
L_800A92C0:;
    R[5] = R[23] + R[0];  /* 0x800A92C0 */
    R[6] = R[30] + R[0];  /* 0x800A92C4 */
    R[7] = R[22] << 16;  /* 0x800A92C8 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A92CC */
    R[16] = 0x8013u << 16;  /* 0x800A92D0 */
    R[3] = R[9] << 16;  /* 0x800A92D4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A92D8 */
    R[2] = R[21] << 16;  /* 0x800A92DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92E0 */
    sw_(R[16] + -18724, R[3]);  /* 0x800A92E4 */
    sw_(R[29] + 16, R[2]);  /* 0x800A92E8 */
    { R[31] = 0x800A92F4u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A92EC jal */
    R[6] = 0x8334u << 16;  /* 0x800A92F4 */
    R[3] = 0x8013u << 16;  /* 0x800A92F8 */
    R[3] = lw_(R[3] + -18640);  /* 0x800A92FC */
    R[6] = R[6] | 0x521;  /* 0x800A9300 */
    R[4] = R[3] << 1;  /* 0x800A9304 */
    R[4] = R[4] + R[3];  /* 0x800A9308 */
    R[3] = R[4] << 4;  /* 0x800A930C */
    R[4] = R[4] + R[3];  /* 0x800A9310 */
    R[4] = R[4] << 1;  /* 0x800A9314 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9318 */
    R[5] = lw_(R[16] + -18724);  /* 0x800A931C */
    R[3] = R[5] << 1;  /* 0x800A9324 */
    R[3] = R[3] + R[5];  /* 0x800A9328 */
    R[5] = R[3] << 4;  /* 0x800A932C */
    R[7] = HI;  /* 0x800A9330 */
    R[3] = R[3] + R[5];  /* 0x800A9334 */
    R[3] = R[3] << 1;  /* 0x800A9338 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A933C */
    R[20] = R[2] + R[0];  /* 0x800A9340 */
    R[2] = R[7] + R[4];  /* 0x800A9344 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9348 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A934C */
    R[17] = R[2] - R[4];  /* 0x800A9350 */
    R[8] = HI;  /* 0x800A9354 */
    R[2] = R[8] + R[3];  /* 0x800A9358 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A935C */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x800A9360 */
    { uint32_t _c = (R[17] == R[0]); R[18] = R[2] - R[3]; if (_c) { goto L_800A9390; } }  /* 0x800A9364 */
    R[4] = R[0] + R[0];  /* 0x800A936C */
    R[2] = 0x8013u << 16;  /* 0x800A9370 */
    R[2] = R[2] - 18984;  /* 0x800A9374 */
    R[2] = R[2] + 204;  /* 0x800A9378 */
    R[3] = R[0] + 5797;  /* 0x800A937C */
L_800A9380:;
    sh_(R[2], R[3]);  /* 0x800A9380 */
    R[4] = R[4] + 1;  /* 0x800A9384 */
    { uint32_t _c = (R[4] != R[17]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9380; } }  /* 0x800A9388 */
L_800A9390:;
    { uint32_t _c = (R[18] == R[17]); R[4] = R[17] + R[0]; if (_c) { goto L_800A93C8; } }  /* 0x800A9390 */
    R[3] = R[0] + 102;  /* 0x800A9398 */
    R[3] = R[3] - R[4];  /* 0x800A939C */
    R[3] = R[3] << 1;  /* 0x800A93A0 */
    R[2] = 0x8013u << 16;  /* 0x800A93A4 */
    R[2] = R[2] - 18984;  /* 0x800A93A8 */
    { uint32_t _c = (R[4] == R[18]); R[2] = R[3] + R[2]; if (_c) { goto L_800A93C8; } }  /* 0x800A93AC */
    R[3] = R[0] + 24736;  /* 0x800A93B4 */
L_800A93B8:;
    sh_(R[2], R[3]);  /* 0x800A93B8 */
    R[4] = R[4] + 1;  /* 0x800A93BC */
    { uint32_t _c = (R[4] != R[18]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93B8; } }  /* 0x800A93C0 */
L_800A93C8:;
    R[3] = R[0] + 102;  /* 0x800A93C8 */
    { uint32_t _c = (R[18] == R[3]); R[4] = R[18] + R[0]; if (_c) { goto L_800A9400; } }  /* 0x800A93CC */
    R[3] = R[3] - R[4];  /* 0x800A93D4 */
    R[3] = R[3] << 1;  /* 0x800A93D8 */
    R[2] = 0x8013u << 16;  /* 0x800A93DC */
    R[2] = R[2] - 18984;  /* 0x800A93E0 */
    R[2] = R[3] + R[2];  /* 0x800A93E4 */
    R[5] = R[0] | 0x8421;  /* 0x800A93E8 */
    R[3] = R[0] + 102;  /* 0x800A93EC */
L_800A93F0:;
    sh_(R[2], R[5]);  /* 0x800A93F0 */
    R[4] = R[4] + 1;  /* 0x800A93F4 */
    { uint32_t _c = (R[4] != R[3]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93F0; } }  /* 0x800A93F8 */
L_800A9400:;
    R[4] = 0x8013u << 16;  /* 0x800A9400 */
    R[3] = lw_(R[4] + -18632);  /* 0x800A9404 */
    R[2] = R[20] + R[0];  /* 0x800A9408 */
    R[3] = R[3] | 0x2;  /* 0x800A940C */
    sw_(R[4] + -18632, R[3]);  /* 0x800A9410 */
L_800A9414:;
    R[31] = lw_(R[29] + 60);  /* 0x800A9414 */
    R[30] = lw_(R[29] + 56);  /* 0x800A9418 */
    R[23] = lw_(R[29] + 52);  /* 0x800A941C */
    R[22] = lw_(R[29] + 48);  /* 0x800A9420 */
    R[21] = lw_(R[29] + 44);  /* 0x800A9424 */
    R[20] = lw_(R[29] + 40);  /* 0x800A9428 */
    R[19] = lw_(R[29] + 36);  /* 0x800A942C */
    R[18] = lw_(R[29] + 32);  /* 0x800A9430 */
    R[17] = lw_(R[29] + 28);  /* 0x800A9434 */
    R[16] = lw_(R[29] + 24);  /* 0x800A9438 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A943C jr ra */
}

void g0_800A9074(void) {
    R[2] = R[2] << 16;  /* 0x800A9074 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9078 */
    R[16] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800A907C */
    { uint32_t _c = (R[16] != R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_800A90F0; } }  /* 0x800A9080 */
    R[2] = lw_(R[4] + -18728);  /* 0x800A9088 */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800A90BC; } }  /* 0x800A9090 */
    R[2] = lw_(R[3] + -18720);  /* 0x800A9098 */
    R[2] = R[2] - 1;  /* 0x800A90A0 */
    sw_(R[3] + -18720, R[2]);  /* 0x800A90A4 */
    R[2] = ((int32_t)R[2] < -3);  /* 0x800A90A8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A90E4; } }  /* 0x800A90AC */
    { sw_(R[4] + -18728, R[0]); goto L_800A90E4; }  /* 0x800A90B4 j */
L_800A90BC:;
    R[2] = lw_(R[3] + -18720);  /* 0x800A90BC */
    R[2] = R[2] + 1;  /* 0x800A90C4 */
    sw_(R[3] + -18720, R[2]);  /* 0x800A90C8 */
    R[2] = ((int32_t)R[2] < 8);  /* 0x800A90CC */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A90E4; } }  /* 0x800A90D0 */
    R[2] = R[0] + 1;  /* 0x800A90D8 */
    sw_(R[4] + -18728, R[2]);  /* 0x800A90DC */
    R[2] = 0x8013u << 16;  /* 0x800A90E0 */
L_800A90E4:;
    R[2] = lh_(R[2] + -18720);  /* 0x800A90E4 */
    R[19] = R[19] + R[2];  /* 0x800A90EC */
L_800A90F0:;
    { uint32_t _c = (R[17] == R[0]); R[5] = R[19] + R[0]; if (_c) { goto L_800A911C; } }  /* 0x800A90F0 */
    R[4] = R[0] + R[0];  /* 0x800A90F8 */
    R[2] = 0x8013u << 16;  /* 0x800A90FC */
    R[2] = R[2] - 18624;  /* 0x800A9100 */
    R[2] = R[2] + 204;  /* 0x800A9104 */
    R[3] = R[0] + 7006;  /* 0x800A9108 */
L_800A910C:;
    sh_(R[2], R[3]);  /* 0x800A910C */
    R[4] = R[4] + 1;  /* 0x800A9110 */
    { uint32_t _c = (R[4] != R[17]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A910C; } }  /* 0x800A9114 */
L_800A911C:;
    { uint32_t _c = (R[18] == R[17]); R[4] = R[17] + R[0]; if (_c) { goto L_800A9150; } }  /* 0x800A911C */
    R[3] = R[0] + 102;  /* 0x800A9124 */
    R[3] = R[3] - R[4];  /* 0x800A9128 */
    R[3] = R[3] << 1;  /* 0x800A912C */
    R[2] = 0x8013u << 16;  /* 0x800A9130 */
    R[2] = R[2] - 18624;  /* 0x800A9134 */
    { uint32_t _c = (R[4] == R[18]); R[2] = R[3] + R[2]; if (_c) { goto L_800A9150; } }  /* 0x800A9138 */
L_800A9140:;
    sh_(R[2], R[5]);  /* 0x800A9140 */
    R[4] = R[4] + 1;  /* 0x800A9144 */
    { uint32_t _c = (R[4] != R[18]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9140; } }  /* 0x800A9148 */
L_800A9150:;
    R[3] = R[0] + 102;  /* 0x800A9150 */
    { uint32_t _c = (R[18] == R[3]); R[4] = R[18] + R[0]; if (_c) { goto L_800A9188; } }  /* 0x800A9154 */
    R[3] = R[3] - R[4];  /* 0x800A915C */
    R[3] = R[3] << 1;  /* 0x800A9160 */
    R[2] = 0x8013u << 16;  /* 0x800A9164 */
    R[2] = R[2] - 18624;  /* 0x800A9168 */
    R[2] = R[3] + R[2];  /* 0x800A916C */
    R[5] = R[0] | 0x8421;  /* 0x800A9170 */
    R[3] = R[0] + 102;  /* 0x800A9174 */
L_800A9178:;
    sh_(R[2], R[5]);  /* 0x800A9178 */
    R[4] = R[4] + 1;  /* 0x800A917C */
    { uint32_t _c = (R[4] != R[3]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9178; } }  /* 0x800A9180 */
L_800A9188:;
    R[4] = 0x8013u << 16;  /* 0x800A9188 */
    R[3] = 0x8006u << 16;  /* 0x800A918C */
    R[2] = lw_(R[4] + -18632);  /* 0x800A9190 */
    R[3] = lb_(R[3] + 15333);  /* 0x800A9194 */
    R[2] = R[2] | 0x1;  /* 0x800A9198 */
    { uint32_t _c = (R[3] != R[0]); sw_(R[4] + -18632, R[2]); if (_c) { goto L_800A91AC; } }  /* 0x800A919C */
    { R[2] = R[20] + R[0]; goto L_800A9414; }  /* 0x800A91A4 j */
L_800A91AC:;
    { R[31] = 0x800A91B4u; psx_next = 0x8001D258u; return; }  /* 0x800A91AC jal */
    R[3] = 0x8013u << 16;  /* 0x800A91B4 */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18640);  /* 0x800A91B8 */
    R[3] = R[2] + R[0];  /* 0x800A91BC */
    R[2] = R[3] << 16;  /* 0x800A91C0 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A91C4 */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A91C8 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A91EC; } }  /* 0x800A91CC */
    R[2] = R[9] + 10;  /* 0x800A91D4 */
    R[9] = R[2] + R[0];  /* 0x800A91D8 */
    R[2] = R[2] << 16;  /* 0x800A91DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A91E0 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A9208; }  /* 0x800A91E4 j */
L_800A91EC:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A91EC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A9214; } }  /* 0x800A91F0 */
    R[9] = R[2] + R[0];  /* 0x800A91F8 */
    R[2] = R[2] << 16;  /* 0x800A91FC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9200 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A9204 */
L_800A9208:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A9218; } }  /* 0x800A9208 */
    R[9] = R[3] + R[0];  /* 0x800A9210 */
L_800A9214:;
    R[4] = R[20] + R[0];  /* 0x800A9214 */
L_800A9218:;
    R[5] = R[23] + R[0];  /* 0x800A9218 */
    R[6] = R[30] + R[0];  /* 0x800A921C */
    R[7] = R[22] << 16;  /* 0x800A9220 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A9224 */
    R[2] = 0x8013u << 16;  /* 0x800A9228 */
    R[3] = R[9] << 16;  /* 0x800A922C */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A9230 */
    R[16] = R[21] + 26;  /* 0x800A9234 */
    sw_(R[2] + -18640, R[3]);  /* 0x800A9238 */
    R[2] = R[16] << 16;  /* 0x800A923C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9240 */
    sw_(R[29] + 16, R[2]);  /* 0x800A9244 */
    { R[31] = 0x800A9250u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A9248 jal */
    R[20] = R[2] + R[0];  /* 0x800A9250 */
    { R[31] = 0x800A925Cu; R[21] = R[16] + 9; psx_next = 0x8001D2A4u; return; }  /* 0x800A9254 jal */
    R[3] = 0x8013u << 16;  /* 0x800A925C */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18724);  /* 0x800A9260 */
    R[3] = R[2] + R[0];  /* 0x800A9264 */
    R[2] = R[3] << 16;  /* 0x800A9268 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A926C */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A9270 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A9294; } }  /* 0x800A9274 */
    R[2] = R[9] + 10;  /* 0x800A927C */
    R[9] = R[2] + R[0];  /* 0x800A9280 */
    R[2] = R[2] << 16;  /* 0x800A9284 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9288 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A92B0; }  /* 0x800A928C j */
L_800A9294:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A9294 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A92BC; } }  /* 0x800A9298 */
    R[9] = R[2] + R[0];  /* 0x800A92A0 */
    R[2] = R[2] << 16;  /* 0x800A92A4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92A8 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A92AC */
L_800A92B0:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A92C0; } }  /* 0x800A92B0 */
    R[9] = R[3] + R[0];  /* 0x800A92B8 */
L_800A92BC:;
    R[4] = R[20] + R[0];  /* 0x800A92BC */
L_800A92C0:;
    R[5] = R[23] + R[0];  /* 0x800A92C0 */
    R[6] = R[30] + R[0];  /* 0x800A92C4 */
    R[7] = R[22] << 16;  /* 0x800A92C8 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A92CC */
    R[16] = 0x8013u << 16;  /* 0x800A92D0 */
    R[3] = R[9] << 16;  /* 0x800A92D4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A92D8 */
    R[2] = R[21] << 16;  /* 0x800A92DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92E0 */
    sw_(R[16] + -18724, R[3]);  /* 0x800A92E4 */
    sw_(R[29] + 16, R[2]);  /* 0x800A92E8 */
    { R[31] = 0x800A92F4u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A92EC jal */
    R[6] = 0x8334u << 16;  /* 0x800A92F4 */
    R[3] = 0x8013u << 16;  /* 0x800A92F8 */
    R[3] = lw_(R[3] + -18640);  /* 0x800A92FC */
    R[6] = R[6] | 0x521;  /* 0x800A9300 */
    R[4] = R[3] << 1;  /* 0x800A9304 */
    R[4] = R[4] + R[3];  /* 0x800A9308 */
    R[3] = R[4] << 4;  /* 0x800A930C */
    R[4] = R[4] + R[3];  /* 0x800A9310 */
    R[4] = R[4] << 1;  /* 0x800A9314 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9318 */
    R[5] = lw_(R[16] + -18724);  /* 0x800A931C */
    R[3] = R[5] << 1;  /* 0x800A9324 */
    R[3] = R[3] + R[5];  /* 0x800A9328 */
    R[5] = R[3] << 4;  /* 0x800A932C */
    R[7] = HI;  /* 0x800A9330 */
    R[3] = R[3] + R[5];  /* 0x800A9334 */
    R[3] = R[3] << 1;  /* 0x800A9338 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A933C */
    R[20] = R[2] + R[0];  /* 0x800A9340 */
    R[2] = R[7] + R[4];  /* 0x800A9344 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9348 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A934C */
    R[17] = R[2] - R[4];  /* 0x800A9350 */
    R[8] = HI;  /* 0x800A9354 */
    R[2] = R[8] + R[3];  /* 0x800A9358 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A935C */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x800A9360 */
    { uint32_t _c = (R[17] == R[0]); R[18] = R[2] - R[3]; if (_c) { goto L_800A9390; } }  /* 0x800A9364 */
    R[4] = R[0] + R[0];  /* 0x800A936C */
    R[2] = 0x8013u << 16;  /* 0x800A9370 */
    R[2] = R[2] - 18984;  /* 0x800A9374 */
    R[2] = R[2] + 204;  /* 0x800A9378 */
    R[3] = R[0] + 5797;  /* 0x800A937C */
L_800A9380:;
    sh_(R[2], R[3]);  /* 0x800A9380 */
    R[4] = R[4] + 1;  /* 0x800A9384 */
    { uint32_t _c = (R[4] != R[17]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9380; } }  /* 0x800A9388 */
L_800A9390:;
    { uint32_t _c = (R[18] == R[17]); R[4] = R[17] + R[0]; if (_c) { goto L_800A93C8; } }  /* 0x800A9390 */
    R[3] = R[0] + 102;  /* 0x800A9398 */
    R[3] = R[3] - R[4];  /* 0x800A939C */
    R[3] = R[3] << 1;  /* 0x800A93A0 */
    R[2] = 0x8013u << 16;  /* 0x800A93A4 */
    R[2] = R[2] - 18984;  /* 0x800A93A8 */
    { uint32_t _c = (R[4] == R[18]); R[2] = R[3] + R[2]; if (_c) { goto L_800A93C8; } }  /* 0x800A93AC */
    R[3] = R[0] + 24736;  /* 0x800A93B4 */
L_800A93B8:;
    sh_(R[2], R[3]);  /* 0x800A93B8 */
    R[4] = R[4] + 1;  /* 0x800A93BC */
    { uint32_t _c = (R[4] != R[18]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93B8; } }  /* 0x800A93C0 */
L_800A93C8:;
    R[3] = R[0] + 102;  /* 0x800A93C8 */
    { uint32_t _c = (R[18] == R[3]); R[4] = R[18] + R[0]; if (_c) { goto L_800A9400; } }  /* 0x800A93CC */
    R[3] = R[3] - R[4];  /* 0x800A93D4 */
    R[3] = R[3] << 1;  /* 0x800A93D8 */
    R[2] = 0x8013u << 16;  /* 0x800A93DC */
    R[2] = R[2] - 18984;  /* 0x800A93E0 */
    R[2] = R[3] + R[2];  /* 0x800A93E4 */
    R[5] = R[0] | 0x8421;  /* 0x800A93E8 */
    R[3] = R[0] + 102;  /* 0x800A93EC */
L_800A93F0:;
    sh_(R[2], R[5]);  /* 0x800A93F0 */
    R[4] = R[4] + 1;  /* 0x800A93F4 */
    { uint32_t _c = (R[4] != R[3]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93F0; } }  /* 0x800A93F8 */
L_800A9400:;
    R[4] = 0x8013u << 16;  /* 0x800A9400 */
    R[3] = lw_(R[4] + -18632);  /* 0x800A9404 */
    R[2] = R[20] + R[0];  /* 0x800A9408 */
    R[3] = R[3] | 0x2;  /* 0x800A940C */
    sw_(R[4] + -18632, R[3]);  /* 0x800A9410 */
L_800A9414:;
    R[31] = lw_(R[29] + 60);  /* 0x800A9414 */
    R[30] = lw_(R[29] + 56);  /* 0x800A9418 */
    R[23] = lw_(R[29] + 52);  /* 0x800A941C */
    R[22] = lw_(R[29] + 48);  /* 0x800A9420 */
    R[21] = lw_(R[29] + 44);  /* 0x800A9424 */
    R[20] = lw_(R[29] + 40);  /* 0x800A9428 */
    R[19] = lw_(R[29] + 36);  /* 0x800A942C */
    R[18] = lw_(R[29] + 32);  /* 0x800A9430 */
    R[17] = lw_(R[29] + 28);  /* 0x800A9434 */
    R[16] = lw_(R[29] + 24);  /* 0x800A9438 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A943C jr ra */
}

void g0_800A91B4(void) {
    R[3] = 0x8013u << 16;  /* 0x800A91B4 */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18640);  /* 0x800A91B8 */
    R[3] = R[2] + R[0];  /* 0x800A91BC */
    R[2] = R[3] << 16;  /* 0x800A91C0 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A91C4 */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A91C8 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A91EC; } }  /* 0x800A91CC */
    R[2] = R[9] + 10;  /* 0x800A91D4 */
    R[9] = R[2] + R[0];  /* 0x800A91D8 */
    R[2] = R[2] << 16;  /* 0x800A91DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A91E0 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A9208; }  /* 0x800A91E4 j */
L_800A91EC:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A91EC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A9214; } }  /* 0x800A91F0 */
    R[9] = R[2] + R[0];  /* 0x800A91F8 */
    R[2] = R[2] << 16;  /* 0x800A91FC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9200 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A9204 */
L_800A9208:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A9218; } }  /* 0x800A9208 */
    R[9] = R[3] + R[0];  /* 0x800A9210 */
L_800A9214:;
    R[4] = R[20] + R[0];  /* 0x800A9214 */
L_800A9218:;
    R[5] = R[23] + R[0];  /* 0x800A9218 */
    R[6] = R[30] + R[0];  /* 0x800A921C */
    R[7] = R[22] << 16;  /* 0x800A9220 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A9224 */
    R[2] = 0x8013u << 16;  /* 0x800A9228 */
    R[3] = R[9] << 16;  /* 0x800A922C */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A9230 */
    R[16] = R[21] + 26;  /* 0x800A9234 */
    sw_(R[2] + -18640, R[3]);  /* 0x800A9238 */
    R[2] = R[16] << 16;  /* 0x800A923C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9240 */
    sw_(R[29] + 16, R[2]);  /* 0x800A9244 */
    { R[31] = 0x800A9250u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A9248 jal */
    R[20] = R[2] + R[0];  /* 0x800A9250 */
    { R[31] = 0x800A925Cu; R[21] = R[16] + 9; psx_next = 0x8001D2A4u; return; }  /* 0x800A9254 jal */
    R[3] = 0x8013u << 16;  /* 0x800A925C */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18724);  /* 0x800A9260 */
    R[3] = R[2] + R[0];  /* 0x800A9264 */
    R[2] = R[3] << 16;  /* 0x800A9268 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A926C */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A9270 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A9294; } }  /* 0x800A9274 */
    R[2] = R[9] + 10;  /* 0x800A927C */
    R[9] = R[2] + R[0];  /* 0x800A9280 */
    R[2] = R[2] << 16;  /* 0x800A9284 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9288 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A92B0; }  /* 0x800A928C j */
L_800A9294:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A9294 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A92BC; } }  /* 0x800A9298 */
    R[9] = R[2] + R[0];  /* 0x800A92A0 */
    R[2] = R[2] << 16;  /* 0x800A92A4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92A8 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A92AC */
L_800A92B0:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A92C0; } }  /* 0x800A92B0 */
    R[9] = R[3] + R[0];  /* 0x800A92B8 */
L_800A92BC:;
    R[4] = R[20] + R[0];  /* 0x800A92BC */
L_800A92C0:;
    R[5] = R[23] + R[0];  /* 0x800A92C0 */
    R[6] = R[30] + R[0];  /* 0x800A92C4 */
    R[7] = R[22] << 16;  /* 0x800A92C8 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A92CC */
    R[16] = 0x8013u << 16;  /* 0x800A92D0 */
    R[3] = R[9] << 16;  /* 0x800A92D4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A92D8 */
    R[2] = R[21] << 16;  /* 0x800A92DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92E0 */
    sw_(R[16] + -18724, R[3]);  /* 0x800A92E4 */
    sw_(R[29] + 16, R[2]);  /* 0x800A92E8 */
    { R[31] = 0x800A92F4u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A92EC jal */
    R[6] = 0x8334u << 16;  /* 0x800A92F4 */
    R[3] = 0x8013u << 16;  /* 0x800A92F8 */
    R[3] = lw_(R[3] + -18640);  /* 0x800A92FC */
    R[6] = R[6] | 0x521;  /* 0x800A9300 */
    R[4] = R[3] << 1;  /* 0x800A9304 */
    R[4] = R[4] + R[3];  /* 0x800A9308 */
    R[3] = R[4] << 4;  /* 0x800A930C */
    R[4] = R[4] + R[3];  /* 0x800A9310 */
    R[4] = R[4] << 1;  /* 0x800A9314 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9318 */
    R[5] = lw_(R[16] + -18724);  /* 0x800A931C */
    R[3] = R[5] << 1;  /* 0x800A9324 */
    R[3] = R[3] + R[5];  /* 0x800A9328 */
    R[5] = R[3] << 4;  /* 0x800A932C */
    R[7] = HI;  /* 0x800A9330 */
    R[3] = R[3] + R[5];  /* 0x800A9334 */
    R[3] = R[3] << 1;  /* 0x800A9338 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A933C */
    R[20] = R[2] + R[0];  /* 0x800A9340 */
    R[2] = R[7] + R[4];  /* 0x800A9344 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9348 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A934C */
    R[17] = R[2] - R[4];  /* 0x800A9350 */
    R[8] = HI;  /* 0x800A9354 */
    R[2] = R[8] + R[3];  /* 0x800A9358 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A935C */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x800A9360 */
    { uint32_t _c = (R[17] == R[0]); R[18] = R[2] - R[3]; if (_c) { goto L_800A9390; } }  /* 0x800A9364 */
    R[4] = R[0] + R[0];  /* 0x800A936C */
    R[2] = 0x8013u << 16;  /* 0x800A9370 */
    R[2] = R[2] - 18984;  /* 0x800A9374 */
    R[2] = R[2] + 204;  /* 0x800A9378 */
    R[3] = R[0] + 5797;  /* 0x800A937C */
L_800A9380:;
    sh_(R[2], R[3]);  /* 0x800A9380 */
    R[4] = R[4] + 1;  /* 0x800A9384 */
    { uint32_t _c = (R[4] != R[17]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9380; } }  /* 0x800A9388 */
L_800A9390:;
    { uint32_t _c = (R[18] == R[17]); R[4] = R[17] + R[0]; if (_c) { goto L_800A93C8; } }  /* 0x800A9390 */
    R[3] = R[0] + 102;  /* 0x800A9398 */
    R[3] = R[3] - R[4];  /* 0x800A939C */
    R[3] = R[3] << 1;  /* 0x800A93A0 */
    R[2] = 0x8013u << 16;  /* 0x800A93A4 */
    R[2] = R[2] - 18984;  /* 0x800A93A8 */
    { uint32_t _c = (R[4] == R[18]); R[2] = R[3] + R[2]; if (_c) { goto L_800A93C8; } }  /* 0x800A93AC */
    R[3] = R[0] + 24736;  /* 0x800A93B4 */
L_800A93B8:;
    sh_(R[2], R[3]);  /* 0x800A93B8 */
    R[4] = R[4] + 1;  /* 0x800A93BC */
    { uint32_t _c = (R[4] != R[18]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93B8; } }  /* 0x800A93C0 */
L_800A93C8:;
    R[3] = R[0] + 102;  /* 0x800A93C8 */
    { uint32_t _c = (R[18] == R[3]); R[4] = R[18] + R[0]; if (_c) { goto L_800A9400; } }  /* 0x800A93CC */
    R[3] = R[3] - R[4];  /* 0x800A93D4 */
    R[3] = R[3] << 1;  /* 0x800A93D8 */
    R[2] = 0x8013u << 16;  /* 0x800A93DC */
    R[2] = R[2] - 18984;  /* 0x800A93E0 */
    R[2] = R[3] + R[2];  /* 0x800A93E4 */
    R[5] = R[0] | 0x8421;  /* 0x800A93E8 */
    R[3] = R[0] + 102;  /* 0x800A93EC */
L_800A93F0:;
    sh_(R[2], R[5]);  /* 0x800A93F0 */
    R[4] = R[4] + 1;  /* 0x800A93F4 */
    { uint32_t _c = (R[4] != R[3]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93F0; } }  /* 0x800A93F8 */
L_800A9400:;
    R[4] = 0x8013u << 16;  /* 0x800A9400 */
    R[3] = lw_(R[4] + -18632);  /* 0x800A9404 */
    R[2] = R[20] + R[0];  /* 0x800A9408 */
    R[3] = R[3] | 0x2;  /* 0x800A940C */
    sw_(R[4] + -18632, R[3]);  /* 0x800A9410 */
    R[31] = lw_(R[29] + 60);  /* 0x800A9414 */
    R[30] = lw_(R[29] + 56);  /* 0x800A9418 */
    R[23] = lw_(R[29] + 52);  /* 0x800A941C */
    R[22] = lw_(R[29] + 48);  /* 0x800A9420 */
    R[21] = lw_(R[29] + 44);  /* 0x800A9424 */
    R[20] = lw_(R[29] + 40);  /* 0x800A9428 */
    R[19] = lw_(R[29] + 36);  /* 0x800A942C */
    R[18] = lw_(R[29] + 32);  /* 0x800A9430 */
    R[17] = lw_(R[29] + 28);  /* 0x800A9434 */
    R[16] = lw_(R[29] + 24);  /* 0x800A9438 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A943C jr ra */
}

void g0_800A9250(void) {
    R[20] = R[2] + R[0];  /* 0x800A9250 */
    { R[31] = 0x800A925Cu; R[21] = R[16] + 9; psx_next = 0x8001D2A4u; return; }  /* 0x800A9254 jal */
    R[3] = 0x8013u << 16;  /* 0x800A925C */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18724);  /* 0x800A9260 */
    R[3] = R[2] + R[0];  /* 0x800A9264 */
    R[2] = R[3] << 16;  /* 0x800A9268 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A926C */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A9270 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A9294; } }  /* 0x800A9274 */
    R[2] = R[9] + 10;  /* 0x800A927C */
    R[9] = R[2] + R[0];  /* 0x800A9280 */
    R[2] = R[2] << 16;  /* 0x800A9284 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9288 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A92B0; }  /* 0x800A928C j */
L_800A9294:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A9294 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A92BC; } }  /* 0x800A9298 */
    R[9] = R[2] + R[0];  /* 0x800A92A0 */
    R[2] = R[2] << 16;  /* 0x800A92A4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92A8 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A92AC */
L_800A92B0:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A92C0; } }  /* 0x800A92B0 */
    R[9] = R[3] + R[0];  /* 0x800A92B8 */
L_800A92BC:;
    R[4] = R[20] + R[0];  /* 0x800A92BC */
L_800A92C0:;
    R[5] = R[23] + R[0];  /* 0x800A92C0 */
    R[6] = R[30] + R[0];  /* 0x800A92C4 */
    R[7] = R[22] << 16;  /* 0x800A92C8 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A92CC */
    R[16] = 0x8013u << 16;  /* 0x800A92D0 */
    R[3] = R[9] << 16;  /* 0x800A92D4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A92D8 */
    R[2] = R[21] << 16;  /* 0x800A92DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92E0 */
    sw_(R[16] + -18724, R[3]);  /* 0x800A92E4 */
    sw_(R[29] + 16, R[2]);  /* 0x800A92E8 */
    { R[31] = 0x800A92F4u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A92EC jal */
    R[6] = 0x8334u << 16;  /* 0x800A92F4 */
    R[3] = 0x8013u << 16;  /* 0x800A92F8 */
    R[3] = lw_(R[3] + -18640);  /* 0x800A92FC */
    R[6] = R[6] | 0x521;  /* 0x800A9300 */
    R[4] = R[3] << 1;  /* 0x800A9304 */
    R[4] = R[4] + R[3];  /* 0x800A9308 */
    R[3] = R[4] << 4;  /* 0x800A930C */
    R[4] = R[4] + R[3];  /* 0x800A9310 */
    R[4] = R[4] << 1;  /* 0x800A9314 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9318 */
    R[5] = lw_(R[16] + -18724);  /* 0x800A931C */
    R[3] = R[5] << 1;  /* 0x800A9324 */
    R[3] = R[3] + R[5];  /* 0x800A9328 */
    R[5] = R[3] << 4;  /* 0x800A932C */
    R[7] = HI;  /* 0x800A9330 */
    R[3] = R[3] + R[5];  /* 0x800A9334 */
    R[3] = R[3] << 1;  /* 0x800A9338 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A933C */
    R[20] = R[2] + R[0];  /* 0x800A9340 */
    R[2] = R[7] + R[4];  /* 0x800A9344 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9348 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A934C */
    R[17] = R[2] - R[4];  /* 0x800A9350 */
    R[8] = HI;  /* 0x800A9354 */
    R[2] = R[8] + R[3];  /* 0x800A9358 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A935C */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x800A9360 */
    { uint32_t _c = (R[17] == R[0]); R[18] = R[2] - R[3]; if (_c) { goto L_800A9390; } }  /* 0x800A9364 */
    R[4] = R[0] + R[0];  /* 0x800A936C */
    R[2] = 0x8013u << 16;  /* 0x800A9370 */
    R[2] = R[2] - 18984;  /* 0x800A9374 */
    R[2] = R[2] + 204;  /* 0x800A9378 */
    R[3] = R[0] + 5797;  /* 0x800A937C */
L_800A9380:;
    sh_(R[2], R[3]);  /* 0x800A9380 */
    R[4] = R[4] + 1;  /* 0x800A9384 */
    { uint32_t _c = (R[4] != R[17]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9380; } }  /* 0x800A9388 */
L_800A9390:;
    { uint32_t _c = (R[18] == R[17]); R[4] = R[17] + R[0]; if (_c) { goto L_800A93C8; } }  /* 0x800A9390 */
    R[3] = R[0] + 102;  /* 0x800A9398 */
    R[3] = R[3] - R[4];  /* 0x800A939C */
    R[3] = R[3] << 1;  /* 0x800A93A0 */
    R[2] = 0x8013u << 16;  /* 0x800A93A4 */
    R[2] = R[2] - 18984;  /* 0x800A93A8 */
    { uint32_t _c = (R[4] == R[18]); R[2] = R[3] + R[2]; if (_c) { goto L_800A93C8; } }  /* 0x800A93AC */
    R[3] = R[0] + 24736;  /* 0x800A93B4 */
L_800A93B8:;
    sh_(R[2], R[3]);  /* 0x800A93B8 */
    R[4] = R[4] + 1;  /* 0x800A93BC */
    { uint32_t _c = (R[4] != R[18]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93B8; } }  /* 0x800A93C0 */
L_800A93C8:;
    R[3] = R[0] + 102;  /* 0x800A93C8 */
    { uint32_t _c = (R[18] == R[3]); R[4] = R[18] + R[0]; if (_c) { goto L_800A9400; } }  /* 0x800A93CC */
    R[3] = R[3] - R[4];  /* 0x800A93D4 */
    R[3] = R[3] << 1;  /* 0x800A93D8 */
    R[2] = 0x8013u << 16;  /* 0x800A93DC */
    R[2] = R[2] - 18984;  /* 0x800A93E0 */
    R[2] = R[3] + R[2];  /* 0x800A93E4 */
    R[5] = R[0] | 0x8421;  /* 0x800A93E8 */
    R[3] = R[0] + 102;  /* 0x800A93EC */
L_800A93F0:;
    sh_(R[2], R[5]);  /* 0x800A93F0 */
    R[4] = R[4] + 1;  /* 0x800A93F4 */
    { uint32_t _c = (R[4] != R[3]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93F0; } }  /* 0x800A93F8 */
L_800A9400:;
    R[4] = 0x8013u << 16;  /* 0x800A9400 */
    R[3] = lw_(R[4] + -18632);  /* 0x800A9404 */
    R[2] = R[20] + R[0];  /* 0x800A9408 */
    R[3] = R[3] | 0x2;  /* 0x800A940C */
    sw_(R[4] + -18632, R[3]);  /* 0x800A9410 */
    R[31] = lw_(R[29] + 60);  /* 0x800A9414 */
    R[30] = lw_(R[29] + 56);  /* 0x800A9418 */
    R[23] = lw_(R[29] + 52);  /* 0x800A941C */
    R[22] = lw_(R[29] + 48);  /* 0x800A9420 */
    R[21] = lw_(R[29] + 44);  /* 0x800A9424 */
    R[20] = lw_(R[29] + 40);  /* 0x800A9428 */
    R[19] = lw_(R[29] + 36);  /* 0x800A942C */
    R[18] = lw_(R[29] + 32);  /* 0x800A9430 */
    R[17] = lw_(R[29] + 28);  /* 0x800A9434 */
    R[16] = lw_(R[29] + 24);  /* 0x800A9438 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A943C jr ra */
}

void g0_800A925C(void) {
    R[3] = 0x8013u << 16;  /* 0x800A925C */
    R[5] = (uint32_t)(int16_t)lh_(R[3] + -18724);  /* 0x800A9260 */
    R[3] = R[2] + R[0];  /* 0x800A9264 */
    R[2] = R[3] << 16;  /* 0x800A9268 */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A926C */
    R[2] = ((int32_t)R[5] < (int32_t)R[4]);  /* 0x800A9270 */
    { uint32_t _c = (R[2] == R[0]); R[9] = R[5] + R[0]; if (_c) { goto L_800A9294; } }  /* 0x800A9274 */
    R[2] = R[9] + 10;  /* 0x800A927C */
    R[9] = R[2] + R[0];  /* 0x800A9280 */
    R[2] = R[2] << 16;  /* 0x800A9284 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9288 */
    { R[2] = ((int32_t)R[4] < (int32_t)R[2]); goto L_800A92B0; }  /* 0x800A928C j */
L_800A9294:;
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x800A9294 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] - 10; if (_c) { goto L_800A92BC; } }  /* 0x800A9298 */
    R[9] = R[2] + R[0];  /* 0x800A92A0 */
    R[2] = R[2] << 16;  /* 0x800A92A4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92A8 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x800A92AC */
L_800A92B0:;
    { uint32_t _c = (R[2] == R[0]); R[4] = R[20] + R[0]; if (_c) { goto L_800A92C0; } }  /* 0x800A92B0 */
    R[9] = R[3] + R[0];  /* 0x800A92B8 */
L_800A92BC:;
    R[4] = R[20] + R[0];  /* 0x800A92BC */
L_800A92C0:;
    R[5] = R[23] + R[0];  /* 0x800A92C0 */
    R[6] = R[30] + R[0];  /* 0x800A92C4 */
    R[7] = R[22] << 16;  /* 0x800A92C8 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A92CC */
    R[16] = 0x8013u << 16;  /* 0x800A92D0 */
    R[3] = R[9] << 16;  /* 0x800A92D4 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800A92D8 */
    R[2] = R[21] << 16;  /* 0x800A92DC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A92E0 */
    sw_(R[16] + -18724, R[3]);  /* 0x800A92E4 */
    sw_(R[29] + 16, R[2]);  /* 0x800A92E8 */
    { R[31] = 0x800A92F4u; sw_(R[29] + 20, R[3]); psx_next = 0x800A8C58u; return; }  /* 0x800A92EC jal */
    R[6] = 0x8334u << 16;  /* 0x800A92F4 */
    R[3] = 0x8013u << 16;  /* 0x800A92F8 */
    R[3] = lw_(R[3] + -18640);  /* 0x800A92FC */
    R[6] = R[6] | 0x521;  /* 0x800A9300 */
    R[4] = R[3] << 1;  /* 0x800A9304 */
    R[4] = R[4] + R[3];  /* 0x800A9308 */
    R[3] = R[4] << 4;  /* 0x800A930C */
    R[4] = R[4] + R[3];  /* 0x800A9310 */
    R[4] = R[4] << 1;  /* 0x800A9314 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9318 */
    R[5] = lw_(R[16] + -18724);  /* 0x800A931C */
    R[3] = R[5] << 1;  /* 0x800A9324 */
    R[3] = R[3] + R[5];  /* 0x800A9328 */
    R[5] = R[3] << 4;  /* 0x800A932C */
    R[7] = HI;  /* 0x800A9330 */
    R[3] = R[3] + R[5];  /* 0x800A9334 */
    R[3] = R[3] << 1;  /* 0x800A9338 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A933C */
    R[20] = R[2] + R[0];  /* 0x800A9340 */
    R[2] = R[7] + R[4];  /* 0x800A9344 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9348 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A934C */
    R[17] = R[2] - R[4];  /* 0x800A9350 */
    R[8] = HI;  /* 0x800A9354 */
    R[2] = R[8] + R[3];  /* 0x800A9358 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A935C */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x800A9360 */
    { uint32_t _c = (R[17] == R[0]); R[18] = R[2] - R[3]; if (_c) { goto L_800A9390; } }  /* 0x800A9364 */
    R[4] = R[0] + R[0];  /* 0x800A936C */
    R[2] = 0x8013u << 16;  /* 0x800A9370 */
    R[2] = R[2] - 18984;  /* 0x800A9374 */
    R[2] = R[2] + 204;  /* 0x800A9378 */
    R[3] = R[0] + 5797;  /* 0x800A937C */
L_800A9380:;
    sh_(R[2], R[3]);  /* 0x800A9380 */
    R[4] = R[4] + 1;  /* 0x800A9384 */
    { uint32_t _c = (R[4] != R[17]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9380; } }  /* 0x800A9388 */
L_800A9390:;
    { uint32_t _c = (R[18] == R[17]); R[4] = R[17] + R[0]; if (_c) { goto L_800A93C8; } }  /* 0x800A9390 */
    R[3] = R[0] + 102;  /* 0x800A9398 */
    R[3] = R[3] - R[4];  /* 0x800A939C */
    R[3] = R[3] << 1;  /* 0x800A93A0 */
    R[2] = 0x8013u << 16;  /* 0x800A93A4 */
    R[2] = R[2] - 18984;  /* 0x800A93A8 */
    { uint32_t _c = (R[4] == R[18]); R[2] = R[3] + R[2]; if (_c) { goto L_800A93C8; } }  /* 0x800A93AC */
    R[3] = R[0] + 24736;  /* 0x800A93B4 */
L_800A93B8:;
    sh_(R[2], R[3]);  /* 0x800A93B8 */
    R[4] = R[4] + 1;  /* 0x800A93BC */
    { uint32_t _c = (R[4] != R[18]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93B8; } }  /* 0x800A93C0 */
L_800A93C8:;
    R[3] = R[0] + 102;  /* 0x800A93C8 */
    { uint32_t _c = (R[18] == R[3]); R[4] = R[18] + R[0]; if (_c) { goto L_800A9400; } }  /* 0x800A93CC */
    R[3] = R[3] - R[4];  /* 0x800A93D4 */
    R[3] = R[3] << 1;  /* 0x800A93D8 */
    R[2] = 0x8013u << 16;  /* 0x800A93DC */
    R[2] = R[2] - 18984;  /* 0x800A93E0 */
    R[2] = R[3] + R[2];  /* 0x800A93E4 */
    R[5] = R[0] | 0x8421;  /* 0x800A93E8 */
    R[3] = R[0] + 102;  /* 0x800A93EC */
L_800A93F0:;
    sh_(R[2], R[5]);  /* 0x800A93F0 */
    R[4] = R[4] + 1;  /* 0x800A93F4 */
    { uint32_t _c = (R[4] != R[3]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93F0; } }  /* 0x800A93F8 */
L_800A9400:;
    R[4] = 0x8013u << 16;  /* 0x800A9400 */
    R[3] = lw_(R[4] + -18632);  /* 0x800A9404 */
    R[2] = R[20] + R[0];  /* 0x800A9408 */
    R[3] = R[3] | 0x2;  /* 0x800A940C */
    sw_(R[4] + -18632, R[3]);  /* 0x800A9410 */
    R[31] = lw_(R[29] + 60);  /* 0x800A9414 */
    R[30] = lw_(R[29] + 56);  /* 0x800A9418 */
    R[23] = lw_(R[29] + 52);  /* 0x800A941C */
    R[22] = lw_(R[29] + 48);  /* 0x800A9420 */
    R[21] = lw_(R[29] + 44);  /* 0x800A9424 */
    R[20] = lw_(R[29] + 40);  /* 0x800A9428 */
    R[19] = lw_(R[29] + 36);  /* 0x800A942C */
    R[18] = lw_(R[29] + 32);  /* 0x800A9430 */
    R[17] = lw_(R[29] + 28);  /* 0x800A9434 */
    R[16] = lw_(R[29] + 24);  /* 0x800A9438 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A943C jr ra */
}

void g0_800A92F4(void) {
    R[6] = 0x8334u << 16;  /* 0x800A92F4 */
    R[3] = 0x8013u << 16;  /* 0x800A92F8 */
    R[3] = lw_(R[3] + -18640);  /* 0x800A92FC */
    R[6] = R[6] | 0x521;  /* 0x800A9300 */
    R[4] = R[3] << 1;  /* 0x800A9304 */
    R[4] = R[4] + R[3];  /* 0x800A9308 */
    R[3] = R[4] << 4;  /* 0x800A930C */
    R[4] = R[4] + R[3];  /* 0x800A9310 */
    R[4] = R[4] << 1;  /* 0x800A9314 */
    { int64_t _p = (int64_t)(int32_t)R[4] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9318 */
    R[5] = lw_(R[16] + -18724);  /* 0x800A931C */
    R[3] = R[5] << 1;  /* 0x800A9324 */
    R[3] = R[3] + R[5];  /* 0x800A9328 */
    R[5] = R[3] << 4;  /* 0x800A932C */
    R[7] = HI;  /* 0x800A9330 */
    R[3] = R[3] + R[5];  /* 0x800A9334 */
    R[3] = R[3] << 1;  /* 0x800A9338 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[6]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A933C */
    R[20] = R[2] + R[0];  /* 0x800A9340 */
    R[2] = R[7] + R[4];  /* 0x800A9344 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A9348 */
    R[4] = (uint32_t)((int32_t)R[4] >> 31);  /* 0x800A934C */
    R[17] = R[2] - R[4];  /* 0x800A9350 */
    R[8] = HI;  /* 0x800A9354 */
    R[2] = R[8] + R[3];  /* 0x800A9358 */
    R[2] = (uint32_t)((int32_t)R[2] >> 9);  /* 0x800A935C */
    R[3] = (uint32_t)((int32_t)R[3] >> 31);  /* 0x800A9360 */
    { uint32_t _c = (R[17] == R[0]); R[18] = R[2] - R[3]; if (_c) { goto L_800A9390; } }  /* 0x800A9364 */
    R[4] = R[0] + R[0];  /* 0x800A936C */
    R[2] = 0x8013u << 16;  /* 0x800A9370 */
    R[2] = R[2] - 18984;  /* 0x800A9374 */
    R[2] = R[2] + 204;  /* 0x800A9378 */
    R[3] = R[0] + 5797;  /* 0x800A937C */
L_800A9380:;
    sh_(R[2], R[3]);  /* 0x800A9380 */
    R[4] = R[4] + 1;  /* 0x800A9384 */
    { uint32_t _c = (R[4] != R[17]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A9380; } }  /* 0x800A9388 */
L_800A9390:;
    { uint32_t _c = (R[18] == R[17]); R[4] = R[17] + R[0]; if (_c) { goto L_800A93C8; } }  /* 0x800A9390 */
    R[3] = R[0] + 102;  /* 0x800A9398 */
    R[3] = R[3] - R[4];  /* 0x800A939C */
    R[3] = R[3] << 1;  /* 0x800A93A0 */
    R[2] = 0x8013u << 16;  /* 0x800A93A4 */
    R[2] = R[2] - 18984;  /* 0x800A93A8 */
    { uint32_t _c = (R[4] == R[18]); R[2] = R[3] + R[2]; if (_c) { goto L_800A93C8; } }  /* 0x800A93AC */
    R[3] = R[0] + 24736;  /* 0x800A93B4 */
L_800A93B8:;
    sh_(R[2], R[3]);  /* 0x800A93B8 */
    R[4] = R[4] + 1;  /* 0x800A93BC */
    { uint32_t _c = (R[4] != R[18]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93B8; } }  /* 0x800A93C0 */
L_800A93C8:;
    R[3] = R[0] + 102;  /* 0x800A93C8 */
    { uint32_t _c = (R[18] == R[3]); R[4] = R[18] + R[0]; if (_c) { goto L_800A9400; } }  /* 0x800A93CC */
    R[3] = R[3] - R[4];  /* 0x800A93D4 */
    R[3] = R[3] << 1;  /* 0x800A93D8 */
    R[2] = 0x8013u << 16;  /* 0x800A93DC */
    R[2] = R[2] - 18984;  /* 0x800A93E0 */
    R[2] = R[3] + R[2];  /* 0x800A93E4 */
    R[5] = R[0] | 0x8421;  /* 0x800A93E8 */
    R[3] = R[0] + 102;  /* 0x800A93EC */
L_800A93F0:;
    sh_(R[2], R[5]);  /* 0x800A93F0 */
    R[4] = R[4] + 1;  /* 0x800A93F4 */
    { uint32_t _c = (R[4] != R[3]); R[2] = R[2] - 2; if (_c) { psx_bb(); goto L_800A93F0; } }  /* 0x800A93F8 */
L_800A9400:;
    R[4] = 0x8013u << 16;  /* 0x800A9400 */
    R[3] = lw_(R[4] + -18632);  /* 0x800A9404 */
    R[2] = R[20] + R[0];  /* 0x800A9408 */
    R[3] = R[3] | 0x2;  /* 0x800A940C */
    sw_(R[4] + -18632, R[3]);  /* 0x800A9410 */
    R[31] = lw_(R[29] + 60);  /* 0x800A9414 */
    R[30] = lw_(R[29] + 56);  /* 0x800A9418 */
    R[23] = lw_(R[29] + 52);  /* 0x800A941C */
    R[22] = lw_(R[29] + 48);  /* 0x800A9420 */
    R[21] = lw_(R[29] + 44);  /* 0x800A9424 */
    R[20] = lw_(R[29] + 40);  /* 0x800A9428 */
    R[19] = lw_(R[29] + 36);  /* 0x800A942C */
    R[18] = lw_(R[29] + 32);  /* 0x800A9430 */
    R[17] = lw_(R[29] + 28);  /* 0x800A9434 */
    R[16] = lw_(R[29] + 24);  /* 0x800A9438 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A943C jr ra */
}

void g0_800A9444(void) {
    R[29] = R[29] - 24;  /* 0x800A9444 */
    sw_(R[29] + 20, R[31]);  /* 0x800A9448 */
    { R[31] = 0x800A9454u; sw_(R[29] + 16, R[16]); psx_next = 0x8001D1B8u; return; }  /* 0x800A944C jal */
    R[4] = 0x6666u << 16;  /* 0x800A9454 */
    R[4] = R[4] | 0x6667;  /* 0x800A9458 */
    R[2] = R[2] << 16;  /* 0x800A945C */
    R[3] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9460 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9464 */
    R[2] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x800A9468 */
    R[6] = HI;  /* 0x800A946C */
    R[16] = (uint32_t)((int32_t)R[6] >> 1);  /* 0x800A9470 */
    { R[31] = 0x800A947Cu; R[16] = R[16] - R[2]; psx_next = 0x8001D16Cu; return; }  /* 0x800A9474 jal */
    R[2] = R[2] << 16;  /* 0x800A947C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9480 */
    R[16] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800A9484 */
    { uint32_t _c = (R[16] != R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_800A9500; } }  /* 0x800A9488 */
    R[2] = lw_(R[4] + -18704);  /* 0x800A9490 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[2] - 1; if (_c) { goto L_800A94EC; } }  /* 0x800A9498 */
    R[2] = 0x8006u << 16;  /* 0x800A94A0 */
    R[3] = lw_(R[2] + -12128);  /* 0x800A94A4 */
    R[2] = R[0] + 60;  /* 0x800A94A8 */
    psx_div((int32_t)R[2], (int32_t)R[3]);  /* 0x800A94AC */
    { uint32_t _c = (R[3] != R[0]); if (_c) { goto L_800A94BC; } }  /* 0x800A94B0 */
    psx_break(7168);  /* 0x800A94B8 */
L_800A94BC:;
    R[1] = R[0] - 1;  /* 0x800A94BC */
    { uint32_t _c = (R[3] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800A94D4; } }  /* 0x800A94C0 */
    { uint32_t _c = (R[2] != R[1]); if (_c) { goto L_800A94D4; } }  /* 0x800A94C8 */
    psx_break(6144);  /* 0x800A94D0 */
L_800A94D4:;
    R[2] = LO;  /* 0x800A94D4 */
    sw_(R[4] + -18704, R[2]);  /* 0x800A94DC */
    R[2] = lw_(R[4] + -18704);  /* 0x800A94E0 */
    R[2] = R[2] - 1;  /* 0x800A94E8 */
L_800A94EC:;
    { uint32_t _c = (R[2] != R[0]); sw_(R[4] + -18704, R[2]); if (_c) { goto L_800A9500; } }  /* 0x800A94EC */
    R[4] = R[0] + 24;  /* 0x800A94F4 */
    { R[31] = 0x800A9500u; R[5] = R[0] + R[0]; psx_next = 0x8002DAE8u; return; }  /* 0x800A94F8 jal */
L_800A9500:;
    R[31] = lw_(R[29] + 20);  /* 0x800A9500 */
    R[16] = lw_(R[29] + 16);  /* 0x800A9504 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A9508 jr ra */
}

void g0_800A9454(void) {
    R[4] = 0x6666u << 16;  /* 0x800A9454 */
    R[4] = R[4] | 0x6667;  /* 0x800A9458 */
    R[2] = R[2] << 16;  /* 0x800A945C */
    R[3] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9460 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[4]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800A9464 */
    R[2] = (uint32_t)((int32_t)R[2] >> 31);  /* 0x800A9468 */
    R[6] = HI;  /* 0x800A946C */
    R[16] = (uint32_t)((int32_t)R[6] >> 1);  /* 0x800A9470 */
    { R[31] = 0x800A947Cu; R[16] = R[16] - R[2]; psx_next = 0x8001D16Cu; return; }  /* 0x800A9474 jal */
    R[2] = R[2] << 16;  /* 0x800A947C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9480 */
    R[16] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800A9484 */
    { uint32_t _c = (R[16] != R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_800A9500; } }  /* 0x800A9488 */
    R[2] = lw_(R[4] + -18704);  /* 0x800A9490 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[2] - 1; if (_c) { goto L_800A94EC; } }  /* 0x800A9498 */
    R[2] = 0x8006u << 16;  /* 0x800A94A0 */
    R[3] = lw_(R[2] + -12128);  /* 0x800A94A4 */
    R[2] = R[0] + 60;  /* 0x800A94A8 */
    psx_div((int32_t)R[2], (int32_t)R[3]);  /* 0x800A94AC */
    { uint32_t _c = (R[3] != R[0]); if (_c) { goto L_800A94BC; } }  /* 0x800A94B0 */
    psx_break(7168);  /* 0x800A94B8 */
L_800A94BC:;
    R[1] = R[0] - 1;  /* 0x800A94BC */
    { uint32_t _c = (R[3] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800A94D4; } }  /* 0x800A94C0 */
    { uint32_t _c = (R[2] != R[1]); if (_c) { goto L_800A94D4; } }  /* 0x800A94C8 */
    psx_break(6144);  /* 0x800A94D0 */
L_800A94D4:;
    R[2] = LO;  /* 0x800A94D4 */
    sw_(R[4] + -18704, R[2]);  /* 0x800A94DC */
    R[2] = lw_(R[4] + -18704);  /* 0x800A94E0 */
    R[2] = R[2] - 1;  /* 0x800A94E8 */
L_800A94EC:;
    { uint32_t _c = (R[2] != R[0]); sw_(R[4] + -18704, R[2]); if (_c) { goto L_800A9500; } }  /* 0x800A94EC */
    R[4] = R[0] + 24;  /* 0x800A94F4 */
    { R[31] = 0x800A9500u; R[5] = R[0] + R[0]; psx_next = 0x8002DAE8u; return; }  /* 0x800A94F8 jal */
L_800A9500:;
    R[31] = lw_(R[29] + 20);  /* 0x800A9500 */
    R[16] = lw_(R[29] + 16);  /* 0x800A9504 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A9508 jr ra */
}

void g0_800A947C(void) {
    R[2] = R[2] << 16;  /* 0x800A947C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9480 */
    R[16] = ((int32_t)R[16] < (int32_t)R[2]);  /* 0x800A9484 */
    { uint32_t _c = (R[16] != R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_800A9500; } }  /* 0x800A9488 */
    R[2] = lw_(R[4] + -18704);  /* 0x800A9490 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[2] - 1; if (_c) { goto L_800A94EC; } }  /* 0x800A9498 */
    R[2] = 0x8006u << 16;  /* 0x800A94A0 */
    R[3] = lw_(R[2] + -12128);  /* 0x800A94A4 */
    R[2] = R[0] + 60;  /* 0x800A94A8 */
    psx_div((int32_t)R[2], (int32_t)R[3]);  /* 0x800A94AC */
    { uint32_t _c = (R[3] != R[0]); if (_c) { goto L_800A94BC; } }  /* 0x800A94B0 */
    psx_break(7168);  /* 0x800A94B8 */
L_800A94BC:;
    R[1] = R[0] - 1;  /* 0x800A94BC */
    { uint32_t _c = (R[3] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800A94D4; } }  /* 0x800A94C0 */
    { uint32_t _c = (R[2] != R[1]); if (_c) { goto L_800A94D4; } }  /* 0x800A94C8 */
    psx_break(6144);  /* 0x800A94D0 */
L_800A94D4:;
    R[2] = LO;  /* 0x800A94D4 */
    sw_(R[4] + -18704, R[2]);  /* 0x800A94DC */
    R[2] = lw_(R[4] + -18704);  /* 0x800A94E0 */
    R[2] = R[2] - 1;  /* 0x800A94E8 */
L_800A94EC:;
    { uint32_t _c = (R[2] != R[0]); sw_(R[4] + -18704, R[2]); if (_c) { goto L_800A9500; } }  /* 0x800A94EC */
    R[4] = R[0] + 24;  /* 0x800A94F4 */
    { R[31] = 0x800A9500u; R[5] = R[0] + R[0]; psx_next = 0x8002DAE8u; return; }  /* 0x800A94F8 jal */
L_800A9500:;
    R[31] = lw_(R[29] + 20);  /* 0x800A9500 */
    R[16] = lw_(R[29] + 16);  /* 0x800A9504 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A9508 jr ra */
}

void g0_800A9500(void) {
    R[31] = lw_(R[29] + 20);  /* 0x800A9500 */
    R[16] = lw_(R[29] + 16);  /* 0x800A9504 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800A9508 jr ra */
}

void g0_800A9510(void) {
#ifdef A2_HUD_PRESENT
    a2_hud_present_begin(R[4],R[5],R[6],R[31]);
#endif
    R[2] = 0x800Fu << 16;  /* 0x800A9510 */
    R[2] = lb_(R[2] + 25118);  /* 0x800A9514 */
    psx_next = 0x800A9518u; return;  /* fallthrough */
}

void g0_800A9518(void) {
    R[29] = R[29] - 64;  /* 0x800A9518 */
    sw_(R[29] + 32, R[16]);  /* 0x800A951C */
    R[16] = R[4] + R[0];  /* 0x800A9520 */
    sw_(R[29] + 44, R[19]);  /* 0x800A9524 */
    R[19] = R[5] + R[0];  /* 0x800A9528 */
    sw_(R[29] + 48, R[20]);  /* 0x800A952C */
    R[20] = R[6] + R[0];  /* 0x800A9530 */
    sw_(R[29] + 56, R[31]);  /* 0x800A9534 */
    sw_(R[29] + 52, R[21]);  /* 0x800A9538 */
    sw_(R[29] + 40, R[18]);  /* 0x800A953C */
    R[2] = R[2] & 0x4;  /* 0x800A9540 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[29] + 36, R[17]); if (_c) { goto L_800A979C; } }  /* 0x800A9544 */
    { uint32_t _c = (R[20] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A9564; } }  /* 0x800A954C */
    R[3] = R[0] + 1;  /* 0x800A9554 */
    sw_(R[2] + -18652, R[3]);  /* 0x800A9558 */
    R[2] = 0x8013u << 16;  /* 0x800A955C */
    sw_(R[2] + -18648, R[0]);  /* 0x800A9560 */
L_800A9564:;
    R[2] = 0x8013u << 16;  /* 0x800A9564 */
    R[2] = lw_(R[2] + -18652);  /* 0x800A9568 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800A95A0; } }  /* 0x800A9570 */
    R[3] = 0x8013u << 16;  /* 0x800A9578 */
    R[2] = lw_(R[3] + -18648);  /* 0x800A957C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800A95AC; } }  /* 0x800A9584 */
    { R[31] = 0x800A9594u; psx_next = 0x8001D050u; return; }  /* 0x800A958C jal */
    R[3] = 0x8013u << 16;  /* 0x800A9594 */
    { sw_(R[3] + -18708, R[2]); goto L_800A979C; }  /* 0x800A9598 j */
L_800A95A0:;
    R[2] = lh_(R[2] + -18648);  /* 0x800A95A0 */
    { R[21] = R[0] - R[2]; goto L_800A95B8; }  /* 0x800A95A4 j */
L_800A95AC:;
    R[2] = lh_(R[3] + -18648);  /* 0x800A95AC */
    R[21] = R[2] - 64;  /* 0x800A95B4 */
L_800A95B8:;
    { R[31] = 0x800A95C0u; psx_next = 0x800A9444u; return; }  /* 0x800A95B8 jal */
    R[4] = R[16] + R[0];  /* 0x800A95C0 */
    R[5] = R[19] + R[0];  /* 0x800A95C4 */
    R[6] = R[20] + R[0];  /* 0x800A95C8 */
    R[2] = R[0] - R[21];  /* 0x800A95CC */
    R[2] = R[2] << 16;  /* 0x800A95D0 */
    R[18] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A95D4 */
    { R[31] = 0x800A95E0u; R[7] = R[18] + R[0]; psx_next = 0x800A8A44u; return; }  /* 0x800A95D8 jal */
    R[4] = R[2] + R[0];  /* 0x800A95E0 */
    R[5] = R[19] + R[0];  /* 0x800A95E4 */
    R[6] = R[20] + R[0];  /* 0x800A95E8 */
    { R[31] = 0x800A95F4u; R[7] = R[18] + R[0]; psx_next = 0x800A8C18u; return; }  /* 0x800A95EC jal */
    R[4] = R[2] + R[0];  /* 0x800A95F4 */
    R[5] = R[19] + R[0];  /* 0x800A95F8 */
    R[6] = R[20] + R[0];  /* 0x800A95FC */
    { R[31] = 0x800A9608u; R[7] = R[18] + R[0]; psx_next = 0x800A89D4u; return; }  /* 0x800A9600 jal */
    R[4] = R[2] + R[0];  /* 0x800A9608 */
    R[5] = R[19] + R[0];  /* 0x800A960C */
    R[6] = R[20] + R[0];  /* 0x800A9610 */
    R[2] = R[21] << 16;  /* 0x800A9614 */
    R[17] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800A9618 */
    { R[31] = 0x800A9624u; R[7] = R[17] + R[0]; psx_next = 0x800A8E50u; return; }  /* 0x800A961C jal */
    R[4] = R[2] + R[0];  /* 0x800A9624 */
    R[5] = R[19] + R[0];  /* 0x800A9628 */
    R[6] = R[20] + R[0];  /* 0x800A962C */
    { R[31] = 0x800A9638u; R[7] = R[18] + R[0]; psx_next = 0x800A86BCu; return; }  /* 0x800A9630 jal */
    R[4] = R[2] + R[0];  /* 0x800A9638 */
    R[5] = R[19] + R[0];  /* 0x800A963C */
    R[6] = R[20] + R[0];  /* 0x800A9640 */
    { R[31] = 0x800A964Cu; R[7] = R[18] + R[0]; psx_next = 0x800A7E90u; return; }  /* 0x800A9644 jal */
    { uint32_t _c = (R[20] != R[0]); R[16] = R[2] + R[0]; if (_c) { goto L_800A96CC; } }  /* 0x800A964C */
    R[2] = 0x8006u << 16;  /* 0x800A9654 */
    R[2] = lb_(R[2] + 15333);  /* 0x800A9658 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[17] + R[0]; if (_c) { goto L_800A968C; } }  /* 0x800A9660 */
    R[6] = R[0] + R[0];  /* 0x800A9668 */
    R[2] = 0x8013u << 16;  /* 0x800A966C */
    R[4] = lw_(R[2] + 9464);  /* 0x800A9670 */
    R[7] = R[6] + R[0];  /* 0x800A9674 */
    sw_(R[29] + 16, R[16]);  /* 0x800A9678 */
    sw_(R[29] + 20, R[19]);  /* 0x800A967C */
    { R[31] = 0x800A9688u; sw_(R[29] + 24, R[0]); psx_next = 0x80022A58u; return; }  /* 0x800A9680 jal */
    R[16] = R[2] + R[0];  /* 0x800A9688 */
L_800A968C:;
    R[5] = R[17] + R[0];  /* 0x800A968C */
    R[6] = R[0] + R[0];  /* 0x800A9690 */
    R[2] = 0x8013u << 16;  /* 0x800A9694 */
    R[4] = lw_(R[2] + 9468);  /* 0x800A9698 */
    R[7] = R[6] + R[0];  /* 0x800A969C */
    sw_(R[29] + 16, R[16]);  /* 0x800A96A0 */
    sw_(R[29] + 20, R[19]);  /* 0x800A96A4 */
    { R[31] = 0x800A96B0u; sw_(R[29] + 24, R[0]); psx_next = 0x80022A58u; return; }  /* 0x800A96A8 jal */
    R[5] = R[18] + R[0];  /* 0x800A96B0 */
    R[6] = R[0] + R[0];  /* 0x800A96B4 */
    R[3] = 0x8013u << 16;  /* 0x800A96B8 */
    R[4] = lw_(R[3] + 4336);  /* 0x800A96BC */
    R[7] = R[6] + R[0];  /* 0x800A96C0 */
    { sw_(R[29] + 16, R[2]); goto L_800A971C; }  /* 0x800A96C4 j */
L_800A96CC:;
    R[2] = 0x8006u << 16;  /* 0x800A96CC */
    R[2] = lb_(R[2] + 15333);  /* 0x800A96D0 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[17] + R[0]; if (_c) { goto L_800A9704; } }  /* 0x800A96D8 */
    R[6] = R[0] + R[0];  /* 0x800A96E0 */
    R[2] = 0x8013u << 16;  /* 0x800A96E4 */
    R[4] = lw_(R[2] + 4008);  /* 0x800A96E8 */
    R[7] = R[6] + R[0];  /* 0x800A96EC */
    sw_(R[29] + 16, R[16]);  /* 0x800A96F0 */
    sw_(R[29] + 20, R[19]);  /* 0x800A96F4 */
    { R[31] = 0x800A9700u; sw_(R[29] + 24, R[0]); psx_next = 0x80022A58u; return; }  /* 0x800A96F8 jal */
    R[16] = R[2] + R[0];  /* 0x800A9700 */
L_800A9704:;
    R[5] = R[17] + R[0];  /* 0x800A9704 */
    R[6] = R[0] + R[0];  /* 0x800A9708 */
    R[2] = 0x8013u << 16;  /* 0x800A970C */
    R[4] = lw_(R[2] + 4332);  /* 0x800A9710 */
    R[7] = R[6] + R[0];  /* 0x800A9714 */
    sw_(R[29] + 16, R[16]);  /* 0x800A9718 */
L_800A971C:;
    sw_(R[29] + 20, R[19]);  /* 0x800A971C */
    { R[31] = 0x800A9728u; sw_(R[29] + 24, R[0]); psx_next = 0x80022A58u; return; }  /* 0x800A9720 jal */
    R[16] = R[2] + R[0];  /* 0x800A9728 */
    R[2] = 0x8013u << 16;  /* 0x800A972C */
    R[2] = lw_(R[2] + -18628);  /* 0x800A9730 */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_800A9788; } }  /* 0x800A9738 */
    R[4] = R[16] + R[0];  /* 0x800A9740 */
    R[5] = R[19] + R[0];  /* 0x800A9744 */
    R[6] = R[20] + R[0];  /* 0x800A9748 */
    R[7] = R[0] + 270;  /* 0x800A974C */
    R[7] = R[7] - R[21];  /* 0x800A9750 */
    R[7] = R[7] << 16;  /* 0x800A9754 */
    R[7] = (uint32_t)((int32_t)R[7] >> 16);  /* 0x800A9758 */
    R[2] = R[0] + 10;  /* 0x800A975C */
    sw_(R[29] + 16, R[2]);  /* 0x800A9760 */
    R[2] = 0x8006u << 16;  /* 0x800A9764 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 16034);  /* 0x800A9768 */
    R[2] = R[0] + 128;  /* 0x800A976C */
    sw_(R[29] + 24, R[2]);  /* 0x800A9770 */
    sw_(R[29] + 28, R[0]);  /* 0x800A9774 */
    { R[31] = 0x800A9780u; sw_(R[29] + 20, R[3]); psx_next = 0x800A82ECu; return; }  /* 0x800A9778 jal */
    R[16] = R[2] + R[0];  /* 0x800A9780 */
    R[3] = 0x8013u << 16;  /* 0x800A9784 */
L_800A9788:;
    R[2] = lw_(R[3] + -18648);  /* 0x800A9788 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[2] - 8; if (_c) { goto L_800A979C; } }  /* 0x800A9790 */
    sw_(R[3] + -18648, R[2]);  /* 0x800A9798 */
L_800A979C:;
    R[2] = R[16] + R[0];  /* 0x800A979C */
    R[31] = lw_(R[29] + 56);  /* 0x800A97A0 */
    R[21] = lw_(R[29] + 52);  /* 0x800A97A4 */
    R[20] = lw_(R[29] + 48);  /* 0x800A97A8 */
    R[19] = lw_(R[29] + 44);  /* 0x800A97AC */
    R[18] = lw_(R[29] + 40);  /* 0x800A97B0 */
    R[17] = lw_(R[29] + 36);  /* 0x800A97B4 */
    R[16] = lw_(R[29] + 32);  /* 0x800A97B8 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x800A97BC jr ra */
}
