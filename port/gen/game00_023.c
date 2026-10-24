#include "game00_decls.h"

void g0_800AC304(void) {
    R[2] = lw_(R[16] + 84);  /* 0x800AC304 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800AC37C; } }  /* 0x800AC30C */
    { R[31] = 0x800AC31Cu; psx_next = 0x800AB6B4u; return; }  /* 0x800AC314 jal */
    { R[31] = 0x800AC324u; psx_next = 0x800AB204u; return; }  /* 0x800AC31C jal */
    { R[31] = 0x800AC32Cu; psx_next = 0x8009A880u; return; }  /* 0x800AC324 jal */
    { R[31] = 0x800AC334u; psx_next = 0x8009A9ECu; return; }  /* 0x800AC32C jal */
    R[2] = 0x8013u << 16;  /* 0x800AC334 */
    R[2] = lw_(R[2] + -31460);  /* 0x800AC338 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 498; if (_c) { goto L_800AC378; } }  /* 0x800AC340 */
    R[3] = lw_(R[17] + 30872);  /* 0x800AC348 */
    { uint32_t _c = (R[3] == R[2]); R[2] = 0x8013u << 16; if (_c) { goto L_800AC37C; } }  /* 0x800AC350 */
    { R[31] = 0x800AC360u; R[4] = R[0] + 422; psx_next = 0x80088DCCu; return; }  /* 0x800AC358 jal */
    R[3] = R[0] - 1;  /* 0x800AC360 */
    { uint32_t _c = (R[2] != R[3]); R[2] = 0x8013u << 16; if (_c) { goto L_800AC37C; } }  /* 0x800AC364 */
    R[4] = 0x8008u << 16;  /* 0x800AC36C */
    { R[31] = 0x800AC378u; R[4] = R[4] + 9388; psx_next = 0x8001BBF8u; return; }  /* 0x800AC370 jal */
L_800AC378:;
    R[2] = 0x8013u << 16;  /* 0x800AC378 */
L_800AC37C:;
    R[16] = (uint32_t)(int16_t)lh_(R[2] + 4296);  /* 0x800AC37C */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_800AC3B8; } }  /* 0x800AC384 */
    { R[31] = 0x800AC394u; R[4] = R[0] + 1; psx_next = 0x8001BCECu; return; }  /* 0x800AC38C jal */
    R[5] = R[16] + R[0];  /* 0x800AC394 */
    R[6] = R[5] + R[0];  /* 0x800AC398 */
    R[2] = 0x8001u << 16;  /* 0x800AC39C */
    R[4] = lw_(R[2] + 28888);  /* 0x800AC3A0 */
    R[7] = R[0] + 12288;  /* 0x800AC3A4 */
    { R[31] = 0x800AC3B0u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800AC3A8 jal */
    { R[31] = 0x800AC3B8u; R[4] = R[0] + R[0]; psx_next = 0x8001BCECu; return; }  /* 0x800AC3B0 jal */
L_800AC3B8:;
    { R[31] = 0x800AC3C0u; R[4] = R[0] + 567; psx_next = 0x8001D36Cu; return; }  /* 0x800AC3B8 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AC3D8; } }  /* 0x800AC3C0 */
    { R[31] = 0x800AC3D0u; R[4] = R[0] + 567; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3C8 jal */
    { goto L_800AC3E0; }  /* 0x800AC3D0 j */
L_800AC3D8:;
    { R[31] = 0x800AC3E0u; R[4] = R[0] + R[0]; psx_next = 0x8002C2C8u; return; }  /* 0x800AC3D8 jal */
L_800AC3E0:;
    { R[31] = 0x800AC3E8u; R[4] = R[0] + 599; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3E0 jal */
    R[4] = R[0] + R[0];  /* 0x800AC3E8 */
    R[2] = 0x8012u << 16;  /* 0x800AC3EC */
    R[3] = lw_(R[2] + 30872);  /* 0x800AC3F0 */
    R[2] = R[2] + 30872;  /* 0x800AC3F4 */
    sw_(R[2] + 4, R[3]);  /* 0x800AC3F8 */
    R[2] = 0x800Fu << 16;  /* 0x800AC3FC */
    { R[31] = 0x800AC408u; sw_(R[2] + 25200, R[3]); psx_next = 0x800E1A94u; return; }  /* 0x800AC400 jal */
    R[31] = lw_(R[29] + 200);  /* 0x800AC408 */
    R[23] = lw_(R[29] + 196);  /* 0x800AC40C */
    R[22] = lw_(R[29] + 192);  /* 0x800AC410 */
    R[21] = lw_(R[29] + 188);  /* 0x800AC414 */
    R[20] = lw_(R[29] + 184);  /* 0x800AC418 */
    R[19] = lw_(R[29] + 180);  /* 0x800AC41C */
    R[18] = lw_(R[29] + 176);  /* 0x800AC420 */
    R[17] = lw_(R[29] + 172);  /* 0x800AC424 */
    R[16] = lw_(R[29] + 168);  /* 0x800AC428 */
    { R[29] = R[29] + 208; psx_next = R[31]; return; }  /* 0x800AC42C jr ra */
}

void g0_800AC31C(void) {
    { R[31] = 0x800AC324u; psx_next = 0x800AB204u; return; }  /* 0x800AC31C jal */
    { R[31] = 0x800AC32Cu; psx_next = 0x8009A880u; return; }  /* 0x800AC324 jal */
    { R[31] = 0x800AC334u; psx_next = 0x8009A9ECu; return; }  /* 0x800AC32C jal */
    R[2] = 0x8013u << 16;  /* 0x800AC334 */
    R[2] = lw_(R[2] + -31460);  /* 0x800AC338 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 498; if (_c) { goto L_800AC378; } }  /* 0x800AC340 */
    R[3] = lw_(R[17] + 30872);  /* 0x800AC348 */
    { uint32_t _c = (R[3] == R[2]); R[2] = 0x8013u << 16; if (_c) { goto L_800AC37C; } }  /* 0x800AC350 */
    { R[31] = 0x800AC360u; R[4] = R[0] + 422; psx_next = 0x80088DCCu; return; }  /* 0x800AC358 jal */
    R[3] = R[0] - 1;  /* 0x800AC360 */
    { uint32_t _c = (R[2] != R[3]); R[2] = 0x8013u << 16; if (_c) { goto L_800AC37C; } }  /* 0x800AC364 */
    R[4] = 0x8008u << 16;  /* 0x800AC36C */
    { R[31] = 0x800AC378u; R[4] = R[4] + 9388; psx_next = 0x8001BBF8u; return; }  /* 0x800AC370 jal */
L_800AC378:;
    R[2] = 0x8013u << 16;  /* 0x800AC378 */
L_800AC37C:;
    R[16] = (uint32_t)(int16_t)lh_(R[2] + 4296);  /* 0x800AC37C */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_800AC3B8; } }  /* 0x800AC384 */
    { R[31] = 0x800AC394u; R[4] = R[0] + 1; psx_next = 0x8001BCECu; return; }  /* 0x800AC38C jal */
    R[5] = R[16] + R[0];  /* 0x800AC394 */
    R[6] = R[5] + R[0];  /* 0x800AC398 */
    R[2] = 0x8001u << 16;  /* 0x800AC39C */
    R[4] = lw_(R[2] + 28888);  /* 0x800AC3A0 */
    R[7] = R[0] + 12288;  /* 0x800AC3A4 */
    { R[31] = 0x800AC3B0u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800AC3A8 jal */
    { R[31] = 0x800AC3B8u; R[4] = R[0] + R[0]; psx_next = 0x8001BCECu; return; }  /* 0x800AC3B0 jal */
L_800AC3B8:;
    { R[31] = 0x800AC3C0u; R[4] = R[0] + 567; psx_next = 0x8001D36Cu; return; }  /* 0x800AC3B8 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AC3D8; } }  /* 0x800AC3C0 */
    { R[31] = 0x800AC3D0u; R[4] = R[0] + 567; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3C8 jal */
    { goto L_800AC3E0; }  /* 0x800AC3D0 j */
L_800AC3D8:;
    { R[31] = 0x800AC3E0u; R[4] = R[0] + R[0]; psx_next = 0x8002C2C8u; return; }  /* 0x800AC3D8 jal */
L_800AC3E0:;
    { R[31] = 0x800AC3E8u; R[4] = R[0] + 599; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3E0 jal */
    R[4] = R[0] + R[0];  /* 0x800AC3E8 */
    R[2] = 0x8012u << 16;  /* 0x800AC3EC */
    R[3] = lw_(R[2] + 30872);  /* 0x800AC3F0 */
    R[2] = R[2] + 30872;  /* 0x800AC3F4 */
    sw_(R[2] + 4, R[3]);  /* 0x800AC3F8 */
    R[2] = 0x800Fu << 16;  /* 0x800AC3FC */
    { R[31] = 0x800AC408u; sw_(R[2] + 25200, R[3]); psx_next = 0x800E1A94u; return; }  /* 0x800AC400 jal */
    R[31] = lw_(R[29] + 200);  /* 0x800AC408 */
    R[23] = lw_(R[29] + 196);  /* 0x800AC40C */
    R[22] = lw_(R[29] + 192);  /* 0x800AC410 */
    R[21] = lw_(R[29] + 188);  /* 0x800AC414 */
    R[20] = lw_(R[29] + 184);  /* 0x800AC418 */
    R[19] = lw_(R[29] + 180);  /* 0x800AC41C */
    R[18] = lw_(R[29] + 176);  /* 0x800AC420 */
    R[17] = lw_(R[29] + 172);  /* 0x800AC424 */
    R[16] = lw_(R[29] + 168);  /* 0x800AC428 */
    { R[29] = R[29] + 208; psx_next = R[31]; return; }  /* 0x800AC42C jr ra */
}

void g0_800AC324(void) {
    { R[31] = 0x800AC32Cu; psx_next = 0x8009A880u; return; }  /* 0x800AC324 jal */
    { R[31] = 0x800AC334u; psx_next = 0x8009A9ECu; return; }  /* 0x800AC32C jal */
    R[2] = 0x8013u << 16;  /* 0x800AC334 */
    R[2] = lw_(R[2] + -31460);  /* 0x800AC338 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 498; if (_c) { goto L_800AC378; } }  /* 0x800AC340 */
    R[3] = lw_(R[17] + 30872);  /* 0x800AC348 */
    { uint32_t _c = (R[3] == R[2]); R[2] = 0x8013u << 16; if (_c) { goto L_800AC37C; } }  /* 0x800AC350 */
    { R[31] = 0x800AC360u; R[4] = R[0] + 422; psx_next = 0x80088DCCu; return; }  /* 0x800AC358 jal */
    R[3] = R[0] - 1;  /* 0x800AC360 */
    { uint32_t _c = (R[2] != R[3]); R[2] = 0x8013u << 16; if (_c) { goto L_800AC37C; } }  /* 0x800AC364 */
    R[4] = 0x8008u << 16;  /* 0x800AC36C */
    { R[31] = 0x800AC378u; R[4] = R[4] + 9388; psx_next = 0x8001BBF8u; return; }  /* 0x800AC370 jal */
L_800AC378:;
    R[2] = 0x8013u << 16;  /* 0x800AC378 */
L_800AC37C:;
    R[16] = (uint32_t)(int16_t)lh_(R[2] + 4296);  /* 0x800AC37C */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_800AC3B8; } }  /* 0x800AC384 */
    { R[31] = 0x800AC394u; R[4] = R[0] + 1; psx_next = 0x8001BCECu; return; }  /* 0x800AC38C jal */
    R[5] = R[16] + R[0];  /* 0x800AC394 */
    R[6] = R[5] + R[0];  /* 0x800AC398 */
    R[2] = 0x8001u << 16;  /* 0x800AC39C */
    R[4] = lw_(R[2] + 28888);  /* 0x800AC3A0 */
    R[7] = R[0] + 12288;  /* 0x800AC3A4 */
    { R[31] = 0x800AC3B0u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800AC3A8 jal */
    { R[31] = 0x800AC3B8u; R[4] = R[0] + R[0]; psx_next = 0x8001BCECu; return; }  /* 0x800AC3B0 jal */
L_800AC3B8:;
    { R[31] = 0x800AC3C0u; R[4] = R[0] + 567; psx_next = 0x8001D36Cu; return; }  /* 0x800AC3B8 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AC3D8; } }  /* 0x800AC3C0 */
    { R[31] = 0x800AC3D0u; R[4] = R[0] + 567; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3C8 jal */
    { goto L_800AC3E0; }  /* 0x800AC3D0 j */
L_800AC3D8:;
    { R[31] = 0x800AC3E0u; R[4] = R[0] + R[0]; psx_next = 0x8002C2C8u; return; }  /* 0x800AC3D8 jal */
L_800AC3E0:;
    { R[31] = 0x800AC3E8u; R[4] = R[0] + 599; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3E0 jal */
    R[4] = R[0] + R[0];  /* 0x800AC3E8 */
    R[2] = 0x8012u << 16;  /* 0x800AC3EC */
    R[3] = lw_(R[2] + 30872);  /* 0x800AC3F0 */
    R[2] = R[2] + 30872;  /* 0x800AC3F4 */
    sw_(R[2] + 4, R[3]);  /* 0x800AC3F8 */
    R[2] = 0x800Fu << 16;  /* 0x800AC3FC */
    { R[31] = 0x800AC408u; sw_(R[2] + 25200, R[3]); psx_next = 0x800E1A94u; return; }  /* 0x800AC400 jal */
    R[31] = lw_(R[29] + 200);  /* 0x800AC408 */
    R[23] = lw_(R[29] + 196);  /* 0x800AC40C */
    R[22] = lw_(R[29] + 192);  /* 0x800AC410 */
    R[21] = lw_(R[29] + 188);  /* 0x800AC414 */
    R[20] = lw_(R[29] + 184);  /* 0x800AC418 */
    R[19] = lw_(R[29] + 180);  /* 0x800AC41C */
    R[18] = lw_(R[29] + 176);  /* 0x800AC420 */
    R[17] = lw_(R[29] + 172);  /* 0x800AC424 */
    R[16] = lw_(R[29] + 168);  /* 0x800AC428 */
    { R[29] = R[29] + 208; psx_next = R[31]; return; }  /* 0x800AC42C jr ra */
}

void g0_800AC32C(void) {
    { R[31] = 0x800AC334u; psx_next = 0x8009A9ECu; return; }  /* 0x800AC32C jal */
    R[2] = 0x8013u << 16;  /* 0x800AC334 */
    R[2] = lw_(R[2] + -31460);  /* 0x800AC338 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 498; if (_c) { goto L_800AC378; } }  /* 0x800AC340 */
    R[3] = lw_(R[17] + 30872);  /* 0x800AC348 */
    { uint32_t _c = (R[3] == R[2]); R[2] = 0x8013u << 16; if (_c) { goto L_800AC37C; } }  /* 0x800AC350 */
    { R[31] = 0x800AC360u; R[4] = R[0] + 422; psx_next = 0x80088DCCu; return; }  /* 0x800AC358 jal */
    R[3] = R[0] - 1;  /* 0x800AC360 */
    { uint32_t _c = (R[2] != R[3]); R[2] = 0x8013u << 16; if (_c) { goto L_800AC37C; } }  /* 0x800AC364 */
    R[4] = 0x8008u << 16;  /* 0x800AC36C */
    { R[31] = 0x800AC378u; R[4] = R[4] + 9388; psx_next = 0x8001BBF8u; return; }  /* 0x800AC370 jal */
L_800AC378:;
    R[2] = 0x8013u << 16;  /* 0x800AC378 */
L_800AC37C:;
    R[16] = (uint32_t)(int16_t)lh_(R[2] + 4296);  /* 0x800AC37C */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_800AC3B8; } }  /* 0x800AC384 */
    { R[31] = 0x800AC394u; R[4] = R[0] + 1; psx_next = 0x8001BCECu; return; }  /* 0x800AC38C jal */
    R[5] = R[16] + R[0];  /* 0x800AC394 */
    R[6] = R[5] + R[0];  /* 0x800AC398 */
    R[2] = 0x8001u << 16;  /* 0x800AC39C */
    R[4] = lw_(R[2] + 28888);  /* 0x800AC3A0 */
    R[7] = R[0] + 12288;  /* 0x800AC3A4 */
    { R[31] = 0x800AC3B0u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800AC3A8 jal */
    { R[31] = 0x800AC3B8u; R[4] = R[0] + R[0]; psx_next = 0x8001BCECu; return; }  /* 0x800AC3B0 jal */
L_800AC3B8:;
    { R[31] = 0x800AC3C0u; R[4] = R[0] + 567; psx_next = 0x8001D36Cu; return; }  /* 0x800AC3B8 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AC3D8; } }  /* 0x800AC3C0 */
    { R[31] = 0x800AC3D0u; R[4] = R[0] + 567; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3C8 jal */
    { goto L_800AC3E0; }  /* 0x800AC3D0 j */
L_800AC3D8:;
    { R[31] = 0x800AC3E0u; R[4] = R[0] + R[0]; psx_next = 0x8002C2C8u; return; }  /* 0x800AC3D8 jal */
L_800AC3E0:;
    { R[31] = 0x800AC3E8u; R[4] = R[0] + 599; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3E0 jal */
    R[4] = R[0] + R[0];  /* 0x800AC3E8 */
    R[2] = 0x8012u << 16;  /* 0x800AC3EC */
    R[3] = lw_(R[2] + 30872);  /* 0x800AC3F0 */
    R[2] = R[2] + 30872;  /* 0x800AC3F4 */
    sw_(R[2] + 4, R[3]);  /* 0x800AC3F8 */
    R[2] = 0x800Fu << 16;  /* 0x800AC3FC */
    { R[31] = 0x800AC408u; sw_(R[2] + 25200, R[3]); psx_next = 0x800E1A94u; return; }  /* 0x800AC400 jal */
    R[31] = lw_(R[29] + 200);  /* 0x800AC408 */
    R[23] = lw_(R[29] + 196);  /* 0x800AC40C */
    R[22] = lw_(R[29] + 192);  /* 0x800AC410 */
    R[21] = lw_(R[29] + 188);  /* 0x800AC414 */
    R[20] = lw_(R[29] + 184);  /* 0x800AC418 */
    R[19] = lw_(R[29] + 180);  /* 0x800AC41C */
    R[18] = lw_(R[29] + 176);  /* 0x800AC420 */
    R[17] = lw_(R[29] + 172);  /* 0x800AC424 */
    R[16] = lw_(R[29] + 168);  /* 0x800AC428 */
    { R[29] = R[29] + 208; psx_next = R[31]; return; }  /* 0x800AC42C jr ra */
}

void g0_800AC334(void) {
    R[2] = 0x8013u << 16;  /* 0x800AC334 */
    R[2] = lw_(R[2] + -31460);  /* 0x800AC338 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 498; if (_c) { goto L_800AC378; } }  /* 0x800AC340 */
    R[3] = lw_(R[17] + 30872);  /* 0x800AC348 */
    { uint32_t _c = (R[3] == R[2]); R[2] = 0x8013u << 16; if (_c) { goto L_800AC37C; } }  /* 0x800AC350 */
    { R[31] = 0x800AC360u; R[4] = R[0] + 422; psx_next = 0x80088DCCu; return; }  /* 0x800AC358 jal */
    R[3] = R[0] - 1;  /* 0x800AC360 */
    { uint32_t _c = (R[2] != R[3]); R[2] = 0x8013u << 16; if (_c) { goto L_800AC37C; } }  /* 0x800AC364 */
    R[4] = 0x8008u << 16;  /* 0x800AC36C */
    { R[31] = 0x800AC378u; R[4] = R[4] + 9388; psx_next = 0x8001BBF8u; return; }  /* 0x800AC370 jal */
L_800AC378:;
    R[2] = 0x8013u << 16;  /* 0x800AC378 */
L_800AC37C:;
    R[16] = (uint32_t)(int16_t)lh_(R[2] + 4296);  /* 0x800AC37C */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_800AC3B8; } }  /* 0x800AC384 */
    { R[31] = 0x800AC394u; R[4] = R[0] + 1; psx_next = 0x8001BCECu; return; }  /* 0x800AC38C jal */
    R[5] = R[16] + R[0];  /* 0x800AC394 */
    R[6] = R[5] + R[0];  /* 0x800AC398 */
    R[2] = 0x8001u << 16;  /* 0x800AC39C */
    R[4] = lw_(R[2] + 28888);  /* 0x800AC3A0 */
    R[7] = R[0] + 12288;  /* 0x800AC3A4 */
    { R[31] = 0x800AC3B0u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800AC3A8 jal */
    { R[31] = 0x800AC3B8u; R[4] = R[0] + R[0]; psx_next = 0x8001BCECu; return; }  /* 0x800AC3B0 jal */
L_800AC3B8:;
    { R[31] = 0x800AC3C0u; R[4] = R[0] + 567; psx_next = 0x8001D36Cu; return; }  /* 0x800AC3B8 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AC3D8; } }  /* 0x800AC3C0 */
    { R[31] = 0x800AC3D0u; R[4] = R[0] + 567; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3C8 jal */
    { goto L_800AC3E0; }  /* 0x800AC3D0 j */
L_800AC3D8:;
    { R[31] = 0x800AC3E0u; R[4] = R[0] + R[0]; psx_next = 0x8002C2C8u; return; }  /* 0x800AC3D8 jal */
L_800AC3E0:;
    { R[31] = 0x800AC3E8u; R[4] = R[0] + 599; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3E0 jal */
    R[4] = R[0] + R[0];  /* 0x800AC3E8 */
    R[2] = 0x8012u << 16;  /* 0x800AC3EC */
    R[3] = lw_(R[2] + 30872);  /* 0x800AC3F0 */
    R[2] = R[2] + 30872;  /* 0x800AC3F4 */
    sw_(R[2] + 4, R[3]);  /* 0x800AC3F8 */
    R[2] = 0x800Fu << 16;  /* 0x800AC3FC */
    { R[31] = 0x800AC408u; sw_(R[2] + 25200, R[3]); psx_next = 0x800E1A94u; return; }  /* 0x800AC400 jal */
    R[31] = lw_(R[29] + 200);  /* 0x800AC408 */
    R[23] = lw_(R[29] + 196);  /* 0x800AC40C */
    R[22] = lw_(R[29] + 192);  /* 0x800AC410 */
    R[21] = lw_(R[29] + 188);  /* 0x800AC414 */
    R[20] = lw_(R[29] + 184);  /* 0x800AC418 */
    R[19] = lw_(R[29] + 180);  /* 0x800AC41C */
    R[18] = lw_(R[29] + 176);  /* 0x800AC420 */
    R[17] = lw_(R[29] + 172);  /* 0x800AC424 */
    R[16] = lw_(R[29] + 168);  /* 0x800AC428 */
    { R[29] = R[29] + 208; psx_next = R[31]; return; }  /* 0x800AC42C jr ra */
}

void g0_800AC360(void) {
    R[3] = R[0] - 1;  /* 0x800AC360 */
    { uint32_t _c = (R[2] != R[3]); R[2] = 0x8013u << 16; if (_c) { goto L_800AC37C; } }  /* 0x800AC364 */
    R[4] = 0x8008u << 16;  /* 0x800AC36C */
    { R[31] = 0x800AC378u; R[4] = R[4] + 9388; psx_next = 0x8001BBF8u; return; }  /* 0x800AC370 jal */
    R[2] = 0x8013u << 16;  /* 0x800AC378 */
L_800AC37C:;
    R[16] = (uint32_t)(int16_t)lh_(R[2] + 4296);  /* 0x800AC37C */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_800AC3B8; } }  /* 0x800AC384 */
    { R[31] = 0x800AC394u; R[4] = R[0] + 1; psx_next = 0x8001BCECu; return; }  /* 0x800AC38C jal */
    R[5] = R[16] + R[0];  /* 0x800AC394 */
    R[6] = R[5] + R[0];  /* 0x800AC398 */
    R[2] = 0x8001u << 16;  /* 0x800AC39C */
    R[4] = lw_(R[2] + 28888);  /* 0x800AC3A0 */
    R[7] = R[0] + 12288;  /* 0x800AC3A4 */
    { R[31] = 0x800AC3B0u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800AC3A8 jal */
    { R[31] = 0x800AC3B8u; R[4] = R[0] + R[0]; psx_next = 0x8001BCECu; return; }  /* 0x800AC3B0 jal */
L_800AC3B8:;
    { R[31] = 0x800AC3C0u; R[4] = R[0] + 567; psx_next = 0x8001D36Cu; return; }  /* 0x800AC3B8 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AC3D8; } }  /* 0x800AC3C0 */
    { R[31] = 0x800AC3D0u; R[4] = R[0] + 567; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3C8 jal */
    { goto L_800AC3E0; }  /* 0x800AC3D0 j */
L_800AC3D8:;
    { R[31] = 0x800AC3E0u; R[4] = R[0] + R[0]; psx_next = 0x8002C2C8u; return; }  /* 0x800AC3D8 jal */
L_800AC3E0:;
    { R[31] = 0x800AC3E8u; R[4] = R[0] + 599; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3E0 jal */
    R[4] = R[0] + R[0];  /* 0x800AC3E8 */
    R[2] = 0x8012u << 16;  /* 0x800AC3EC */
    R[3] = lw_(R[2] + 30872);  /* 0x800AC3F0 */
    R[2] = R[2] + 30872;  /* 0x800AC3F4 */
    sw_(R[2] + 4, R[3]);  /* 0x800AC3F8 */
    R[2] = 0x800Fu << 16;  /* 0x800AC3FC */
    { R[31] = 0x800AC408u; sw_(R[2] + 25200, R[3]); psx_next = 0x800E1A94u; return; }  /* 0x800AC400 jal */
    R[31] = lw_(R[29] + 200);  /* 0x800AC408 */
    R[23] = lw_(R[29] + 196);  /* 0x800AC40C */
    R[22] = lw_(R[29] + 192);  /* 0x800AC410 */
    R[21] = lw_(R[29] + 188);  /* 0x800AC414 */
    R[20] = lw_(R[29] + 184);  /* 0x800AC418 */
    R[19] = lw_(R[29] + 180);  /* 0x800AC41C */
    R[18] = lw_(R[29] + 176);  /* 0x800AC420 */
    R[17] = lw_(R[29] + 172);  /* 0x800AC424 */
    R[16] = lw_(R[29] + 168);  /* 0x800AC428 */
    { R[29] = R[29] + 208; psx_next = R[31]; return; }  /* 0x800AC42C jr ra */
}

void g0_800AC378(void) {
    R[2] = 0x8013u << 16;  /* 0x800AC378 */
    R[16] = (uint32_t)(int16_t)lh_(R[2] + 4296);  /* 0x800AC37C */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_800AC3B8; } }  /* 0x800AC384 */
    { R[31] = 0x800AC394u; R[4] = R[0] + 1; psx_next = 0x8001BCECu; return; }  /* 0x800AC38C jal */
    R[5] = R[16] + R[0];  /* 0x800AC394 */
    R[6] = R[5] + R[0];  /* 0x800AC398 */
    R[2] = 0x8001u << 16;  /* 0x800AC39C */
    R[4] = lw_(R[2] + 28888);  /* 0x800AC3A0 */
    R[7] = R[0] + 12288;  /* 0x800AC3A4 */
    { R[31] = 0x800AC3B0u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800AC3A8 jal */
    { R[31] = 0x800AC3B8u; R[4] = R[0] + R[0]; psx_next = 0x8001BCECu; return; }  /* 0x800AC3B0 jal */
L_800AC3B8:;
    { R[31] = 0x800AC3C0u; R[4] = R[0] + 567; psx_next = 0x8001D36Cu; return; }  /* 0x800AC3B8 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AC3D8; } }  /* 0x800AC3C0 */
    { R[31] = 0x800AC3D0u; R[4] = R[0] + 567; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3C8 jal */
    { goto L_800AC3E0; }  /* 0x800AC3D0 j */
L_800AC3D8:;
    { R[31] = 0x800AC3E0u; R[4] = R[0] + R[0]; psx_next = 0x8002C2C8u; return; }  /* 0x800AC3D8 jal */
L_800AC3E0:;
    { R[31] = 0x800AC3E8u; R[4] = R[0] + 599; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3E0 jal */
    R[4] = R[0] + R[0];  /* 0x800AC3E8 */
    R[2] = 0x8012u << 16;  /* 0x800AC3EC */
    R[3] = lw_(R[2] + 30872);  /* 0x800AC3F0 */
    R[2] = R[2] + 30872;  /* 0x800AC3F4 */
    sw_(R[2] + 4, R[3]);  /* 0x800AC3F8 */
    R[2] = 0x800Fu << 16;  /* 0x800AC3FC */
    { R[31] = 0x800AC408u; sw_(R[2] + 25200, R[3]); psx_next = 0x800E1A94u; return; }  /* 0x800AC400 jal */
    R[31] = lw_(R[29] + 200);  /* 0x800AC408 */
    R[23] = lw_(R[29] + 196);  /* 0x800AC40C */
    R[22] = lw_(R[29] + 192);  /* 0x800AC410 */
    R[21] = lw_(R[29] + 188);  /* 0x800AC414 */
    R[20] = lw_(R[29] + 184);  /* 0x800AC418 */
    R[19] = lw_(R[29] + 180);  /* 0x800AC41C */
    R[18] = lw_(R[29] + 176);  /* 0x800AC420 */
    R[17] = lw_(R[29] + 172);  /* 0x800AC424 */
    R[16] = lw_(R[29] + 168);  /* 0x800AC428 */
    { R[29] = R[29] + 208; psx_next = R[31]; return; }  /* 0x800AC42C jr ra */
}

void g0_800AC394(void) {
    R[5] = R[16] + R[0];  /* 0x800AC394 */
    R[6] = R[5] + R[0];  /* 0x800AC398 */
    R[2] = 0x8001u << 16;  /* 0x800AC39C */
    R[4] = lw_(R[2] + 28888);  /* 0x800AC3A0 */
    R[7] = R[0] + 12288;  /* 0x800AC3A4 */
    { R[31] = 0x800AC3B0u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800AC3A8 jal */
    { R[31] = 0x800AC3B8u; R[4] = R[0] + R[0]; psx_next = 0x8001BCECu; return; }  /* 0x800AC3B0 jal */
    { R[31] = 0x800AC3C0u; R[4] = R[0] + 567; psx_next = 0x8001D36Cu; return; }  /* 0x800AC3B8 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AC3D8; } }  /* 0x800AC3C0 */
    { R[31] = 0x800AC3D0u; R[4] = R[0] + 567; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3C8 jal */
    { goto L_800AC3E0; }  /* 0x800AC3D0 j */
L_800AC3D8:;
    { R[31] = 0x800AC3E0u; R[4] = R[0] + R[0]; psx_next = 0x8002C2C8u; return; }  /* 0x800AC3D8 jal */
L_800AC3E0:;
    { R[31] = 0x800AC3E8u; R[4] = R[0] + 599; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3E0 jal */
    R[4] = R[0] + R[0];  /* 0x800AC3E8 */
    R[2] = 0x8012u << 16;  /* 0x800AC3EC */
    R[3] = lw_(R[2] + 30872);  /* 0x800AC3F0 */
    R[2] = R[2] + 30872;  /* 0x800AC3F4 */
    sw_(R[2] + 4, R[3]);  /* 0x800AC3F8 */
    R[2] = 0x800Fu << 16;  /* 0x800AC3FC */
    { R[31] = 0x800AC408u; sw_(R[2] + 25200, R[3]); psx_next = 0x800E1A94u; return; }  /* 0x800AC400 jal */
    R[31] = lw_(R[29] + 200);  /* 0x800AC408 */
    R[23] = lw_(R[29] + 196);  /* 0x800AC40C */
    R[22] = lw_(R[29] + 192);  /* 0x800AC410 */
    R[21] = lw_(R[29] + 188);  /* 0x800AC414 */
    R[20] = lw_(R[29] + 184);  /* 0x800AC418 */
    R[19] = lw_(R[29] + 180);  /* 0x800AC41C */
    R[18] = lw_(R[29] + 176);  /* 0x800AC420 */
    R[17] = lw_(R[29] + 172);  /* 0x800AC424 */
    R[16] = lw_(R[29] + 168);  /* 0x800AC428 */
    { R[29] = R[29] + 208; psx_next = R[31]; return; }  /* 0x800AC42C jr ra */
}

void g0_800AC3B0(void) {
    { R[31] = 0x800AC3B8u; R[4] = R[0] + R[0]; psx_next = 0x8001BCECu; return; }  /* 0x800AC3B0 jal */
    { R[31] = 0x800AC3C0u; R[4] = R[0] + 567; psx_next = 0x8001D36Cu; return; }  /* 0x800AC3B8 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AC3D8; } }  /* 0x800AC3C0 */
    { R[31] = 0x800AC3D0u; R[4] = R[0] + 567; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3C8 jal */
    { goto L_800AC3E0; }  /* 0x800AC3D0 j */
L_800AC3D8:;
    { R[31] = 0x800AC3E0u; R[4] = R[0] + R[0]; psx_next = 0x8002C2C8u; return; }  /* 0x800AC3D8 jal */
L_800AC3E0:;
    { R[31] = 0x800AC3E8u; R[4] = R[0] + 599; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3E0 jal */
    R[4] = R[0] + R[0];  /* 0x800AC3E8 */
    R[2] = 0x8012u << 16;  /* 0x800AC3EC */
    R[3] = lw_(R[2] + 30872);  /* 0x800AC3F0 */
    R[2] = R[2] + 30872;  /* 0x800AC3F4 */
    sw_(R[2] + 4, R[3]);  /* 0x800AC3F8 */
    R[2] = 0x800Fu << 16;  /* 0x800AC3FC */
    { R[31] = 0x800AC408u; sw_(R[2] + 25200, R[3]); psx_next = 0x800E1A94u; return; }  /* 0x800AC400 jal */
    R[31] = lw_(R[29] + 200);  /* 0x800AC408 */
    R[23] = lw_(R[29] + 196);  /* 0x800AC40C */
    R[22] = lw_(R[29] + 192);  /* 0x800AC410 */
    R[21] = lw_(R[29] + 188);  /* 0x800AC414 */
    R[20] = lw_(R[29] + 184);  /* 0x800AC418 */
    R[19] = lw_(R[29] + 180);  /* 0x800AC41C */
    R[18] = lw_(R[29] + 176);  /* 0x800AC420 */
    R[17] = lw_(R[29] + 172);  /* 0x800AC424 */
    R[16] = lw_(R[29] + 168);  /* 0x800AC428 */
    { R[29] = R[29] + 208; psx_next = R[31]; return; }  /* 0x800AC42C jr ra */
}

void g0_800AC3B8(void) {
    { R[31] = 0x800AC3C0u; R[4] = R[0] + 567; psx_next = 0x8001D36Cu; return; }  /* 0x800AC3B8 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AC3D8; } }  /* 0x800AC3C0 */
    { R[31] = 0x800AC3D0u; R[4] = R[0] + 567; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3C8 jal */
    { goto L_800AC3E0; }  /* 0x800AC3D0 j */
L_800AC3D8:;
    { R[31] = 0x800AC3E0u; R[4] = R[0] + R[0]; psx_next = 0x8002C2C8u; return; }  /* 0x800AC3D8 jal */
L_800AC3E0:;
    { R[31] = 0x800AC3E8u; R[4] = R[0] + 599; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3E0 jal */
    R[4] = R[0] + R[0];  /* 0x800AC3E8 */
    R[2] = 0x8012u << 16;  /* 0x800AC3EC */
    R[3] = lw_(R[2] + 30872);  /* 0x800AC3F0 */
    R[2] = R[2] + 30872;  /* 0x800AC3F4 */
    sw_(R[2] + 4, R[3]);  /* 0x800AC3F8 */
    R[2] = 0x800Fu << 16;  /* 0x800AC3FC */
    { R[31] = 0x800AC408u; sw_(R[2] + 25200, R[3]); psx_next = 0x800E1A94u; return; }  /* 0x800AC400 jal */
    R[31] = lw_(R[29] + 200);  /* 0x800AC408 */
    R[23] = lw_(R[29] + 196);  /* 0x800AC40C */
    R[22] = lw_(R[29] + 192);  /* 0x800AC410 */
    R[21] = lw_(R[29] + 188);  /* 0x800AC414 */
    R[20] = lw_(R[29] + 184);  /* 0x800AC418 */
    R[19] = lw_(R[29] + 180);  /* 0x800AC41C */
    R[18] = lw_(R[29] + 176);  /* 0x800AC420 */
    R[17] = lw_(R[29] + 172);  /* 0x800AC424 */
    R[16] = lw_(R[29] + 168);  /* 0x800AC428 */
    { R[29] = R[29] + 208; psx_next = R[31]; return; }  /* 0x800AC42C jr ra */
}

void g0_800AC3C0(void) {
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AC3D8; } }  /* 0x800AC3C0 */
    { R[31] = 0x800AC3D0u; R[4] = R[0] + 567; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3C8 jal */
    { goto L_800AC3E0; }  /* 0x800AC3D0 j */
L_800AC3D8:;
    { R[31] = 0x800AC3E0u; R[4] = R[0] + R[0]; psx_next = 0x8002C2C8u; return; }  /* 0x800AC3D8 jal */
L_800AC3E0:;
    { R[31] = 0x800AC3E8u; R[4] = R[0] + 599; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3E0 jal */
    R[4] = R[0] + R[0];  /* 0x800AC3E8 */
    R[2] = 0x8012u << 16;  /* 0x800AC3EC */
    R[3] = lw_(R[2] + 30872);  /* 0x800AC3F0 */
    R[2] = R[2] + 30872;  /* 0x800AC3F4 */
    sw_(R[2] + 4, R[3]);  /* 0x800AC3F8 */
    R[2] = 0x800Fu << 16;  /* 0x800AC3FC */
    { R[31] = 0x800AC408u; sw_(R[2] + 25200, R[3]); psx_next = 0x800E1A94u; return; }  /* 0x800AC400 jal */
    R[31] = lw_(R[29] + 200);  /* 0x800AC408 */
    R[23] = lw_(R[29] + 196);  /* 0x800AC40C */
    R[22] = lw_(R[29] + 192);  /* 0x800AC410 */
    R[21] = lw_(R[29] + 188);  /* 0x800AC414 */
    R[20] = lw_(R[29] + 184);  /* 0x800AC418 */
    R[19] = lw_(R[29] + 180);  /* 0x800AC41C */
    R[18] = lw_(R[29] + 176);  /* 0x800AC420 */
    R[17] = lw_(R[29] + 172);  /* 0x800AC424 */
    R[16] = lw_(R[29] + 168);  /* 0x800AC428 */
    { R[29] = R[29] + 208; psx_next = R[31]; return; }  /* 0x800AC42C jr ra */
}

void g0_800AC3D0(void) {
    { goto L_800AC3E0; }  /* 0x800AC3D0 j */
    { R[31] = 0x800AC3E0u; R[4] = R[0] + R[0]; psx_next = 0x8002C2C8u; return; }  /* 0x800AC3D8 jal */
L_800AC3E0:;
    { R[31] = 0x800AC3E8u; R[4] = R[0] + 599; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3E0 jal */
    R[4] = R[0] + R[0];  /* 0x800AC3E8 */
    R[2] = 0x8012u << 16;  /* 0x800AC3EC */
    R[3] = lw_(R[2] + 30872);  /* 0x800AC3F0 */
    R[2] = R[2] + 30872;  /* 0x800AC3F4 */
    sw_(R[2] + 4, R[3]);  /* 0x800AC3F8 */
    R[2] = 0x800Fu << 16;  /* 0x800AC3FC */
    { R[31] = 0x800AC408u; sw_(R[2] + 25200, R[3]); psx_next = 0x800E1A94u; return; }  /* 0x800AC400 jal */
    R[31] = lw_(R[29] + 200);  /* 0x800AC408 */
    R[23] = lw_(R[29] + 196);  /* 0x800AC40C */
    R[22] = lw_(R[29] + 192);  /* 0x800AC410 */
    R[21] = lw_(R[29] + 188);  /* 0x800AC414 */
    R[20] = lw_(R[29] + 184);  /* 0x800AC418 */
    R[19] = lw_(R[29] + 180);  /* 0x800AC41C */
    R[18] = lw_(R[29] + 176);  /* 0x800AC420 */
    R[17] = lw_(R[29] + 172);  /* 0x800AC424 */
    R[16] = lw_(R[29] + 168);  /* 0x800AC428 */
    { R[29] = R[29] + 208; psx_next = R[31]; return; }  /* 0x800AC42C jr ra */
}

void g0_800AC3E0(void) {
    { R[31] = 0x800AC3E8u; R[4] = R[0] + 599; psx_next = 0x8001D3E8u; return; }  /* 0x800AC3E0 jal */
    R[4] = R[0] + R[0];  /* 0x800AC3E8 */
    R[2] = 0x8012u << 16;  /* 0x800AC3EC */
    R[3] = lw_(R[2] + 30872);  /* 0x800AC3F0 */
    R[2] = R[2] + 30872;  /* 0x800AC3F4 */
    sw_(R[2] + 4, R[3]);  /* 0x800AC3F8 */
    R[2] = 0x800Fu << 16;  /* 0x800AC3FC */
    { R[31] = 0x800AC408u; sw_(R[2] + 25200, R[3]); psx_next = 0x800E1A94u; return; }  /* 0x800AC400 jal */
    R[31] = lw_(R[29] + 200);  /* 0x800AC408 */
    R[23] = lw_(R[29] + 196);  /* 0x800AC40C */
    R[22] = lw_(R[29] + 192);  /* 0x800AC410 */
    R[21] = lw_(R[29] + 188);  /* 0x800AC414 */
    R[20] = lw_(R[29] + 184);  /* 0x800AC418 */
    R[19] = lw_(R[29] + 180);  /* 0x800AC41C */
    R[18] = lw_(R[29] + 176);  /* 0x800AC420 */
    R[17] = lw_(R[29] + 172);  /* 0x800AC424 */
    R[16] = lw_(R[29] + 168);  /* 0x800AC428 */
    { R[29] = R[29] + 208; psx_next = R[31]; return; }  /* 0x800AC42C jr ra */
}

void g0_800AC3E8(void) {
    R[4] = R[0] + R[0];  /* 0x800AC3E8 */
    R[2] = 0x8012u << 16;  /* 0x800AC3EC */
    R[3] = lw_(R[2] + 30872);  /* 0x800AC3F0 */
    R[2] = R[2] + 30872;  /* 0x800AC3F4 */
    sw_(R[2] + 4, R[3]);  /* 0x800AC3F8 */
    R[2] = 0x800Fu << 16;  /* 0x800AC3FC */
    { R[31] = 0x800AC408u; sw_(R[2] + 25200, R[3]); psx_next = 0x800E1A94u; return; }  /* 0x800AC400 jal */
    R[31] = lw_(R[29] + 200);  /* 0x800AC408 */
    R[23] = lw_(R[29] + 196);  /* 0x800AC40C */
    R[22] = lw_(R[29] + 192);  /* 0x800AC410 */
    R[21] = lw_(R[29] + 188);  /* 0x800AC414 */
    R[20] = lw_(R[29] + 184);  /* 0x800AC418 */
    R[19] = lw_(R[29] + 180);  /* 0x800AC41C */
    R[18] = lw_(R[29] + 176);  /* 0x800AC420 */
    R[17] = lw_(R[29] + 172);  /* 0x800AC424 */
    R[16] = lw_(R[29] + 168);  /* 0x800AC428 */
    { R[29] = R[29] + 208; psx_next = R[31]; return; }  /* 0x800AC42C jr ra */
}

void g0_800AC408(void) {
    R[31] = lw_(R[29] + 200);  /* 0x800AC408 */
    R[23] = lw_(R[29] + 196);  /* 0x800AC40C */
    R[22] = lw_(R[29] + 192);  /* 0x800AC410 */
    R[21] = lw_(R[29] + 188);  /* 0x800AC414 */
    R[20] = lw_(R[29] + 184);  /* 0x800AC418 */
    R[19] = lw_(R[29] + 180);  /* 0x800AC41C */
    R[18] = lw_(R[29] + 176);  /* 0x800AC420 */
    R[17] = lw_(R[29] + 172);  /* 0x800AC424 */
    R[16] = lw_(R[29] + 168);  /* 0x800AC428 */
    { R[29] = R[29] + 208; psx_next = R[31]; return; }  /* 0x800AC42C jr ra */
}

void g0_800AC434(void) {
    R[29] = R[29] - 72;  /* 0x800AC434 */
    R[4] = 0x801Eu << 16;  /* 0x800AC438 */
    R[4] = R[4] | 0xC000;  /* 0x800AC43C */
    R[5] = R[0] + 29;  /* 0x800AC440 */
    R[6] = R[0] + 31;  /* 0x800AC444 */
    R[7] = 0x1u << 16;  /* 0x800AC448 */
    R[7] = R[7] | 0x1000;  /* 0x800AC44C */
    sw_(R[29] + 68, R[31]);  /* 0x800AC450 */
    sw_(R[29] + 64, R[22]);  /* 0x800AC454 */
    sw_(R[29] + 60, R[21]);  /* 0x800AC458 */
    sw_(R[29] + 56, R[20]);  /* 0x800AC45C */
    sw_(R[29] + 52, R[19]);  /* 0x800AC460 */
    sw_(R[29] + 48, R[18]);  /* 0x800AC464 */
    sw_(R[29] + 44, R[17]);  /* 0x800AC468 */
    sw_(R[29] + 40, R[16]);  /* 0x800AC46C */
    { R[31] = 0x800AC478u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800AC470 jal */
    R[4] = 0x801Eu << 16;  /* 0x800AC478 */
    R[4] = R[4] | 0xC000;  /* 0x800AC47C */
    R[20] = R[29] + 32;  /* 0x800AC480 */
    R[5] = R[20] + R[0];  /* 0x800AC484 */
    R[6] = R[29] + 24;  /* 0x800AC488 */
    R[19] = R[0] + 768;  /* 0x800AC48C */
    R[2] = R[0] + 504;  /* 0x800AC490 */
    R[17] = R[0] + 256;  /* 0x800AC494 */
    sh_(R[29] + 34, R[2]);  /* 0x800AC498 */
    R[2] = R[0] + 3;  /* 0x800AC49C */
    sh_(R[29] + 38, R[2]);  /* 0x800AC4A0 */
    R[2] = R[0] + 704;  /* 0x800AC4A4 */
    sh_(R[29] + 24, R[2]);  /* 0x800AC4A8 */
    R[2] = R[0] + 128;  /* 0x800AC4AC */
    sh_(R[29] + 32, R[19]);  /* 0x800AC4B0 */
    sh_(R[29] + 36, R[17]);  /* 0x800AC4B4 */
    sh_(R[29] + 26, R[17]);  /* 0x800AC4B8 */
    sh_(R[29] + 28, R[0]);  /* 0x800AC4BC */
    { R[31] = 0x800AC4C8u; sh_(R[29] + 30, R[2]); psx_next = 0x8001CA2Cu; return; }  /* 0x800AC4C0 jal */
    R[22] = 0x801Eu << 16;  /* 0x800AC4C8 */
    R[22] = R[22] | 0xC000;  /* 0x800AC4CC */
    R[5] = R[20] + R[0];  /* 0x800AC4D0 */
    R[6] = R[29] + 24;  /* 0x800AC4D4 */
    R[2] = R[0] + 960;  /* 0x800AC4D8 */
    sh_(R[29] + 32, R[2]);  /* 0x800AC4DC */
    R[2] = R[0] + 476;  /* 0x800AC4E0 */
    R[18] = R[0] + 64;  /* 0x800AC4E4 */
    sh_(R[29] + 34, R[2]);  /* 0x800AC4E8 */
    R[2] = R[0] + 4;  /* 0x800AC4EC */
    R[16] = 0x8006u << 16;  /* 0x800AC4F0 */
    R[16] = R[16] - 9544;  /* 0x800AC4F4 */
    sh_(R[29] + 36, R[18]);  /* 0x800AC4F8 */
    sh_(R[29] + 38, R[2]);  /* 0x800AC4FC */
    R[4] = lw_(R[16] + 120);  /* 0x800AC500 */
    R[3] = lw_(R[16] + 116);  /* 0x800AC504 */
    R[2] = R[0] + 640;  /* 0x800AC508 */
    sh_(R[29] + 24, R[2]);  /* 0x800AC50C */
    sh_(R[29] + 26, R[17]);  /* 0x800AC510 */
    sh_(R[29] + 28, R[18]);  /* 0x800AC514 */
    sh_(R[29] + 30, R[17]);  /* 0x800AC518 */
    R[4] = R[4] - R[3];  /* 0x800AC51C */
    { R[31] = 0x800AC528u; R[4] = R[4] + R[22]; psx_next = 0x8001CA2Cu; return; }  /* 0x800AC520 jal */
    R[5] = R[20] + R[0];  /* 0x800AC528 */
    R[6] = R[29] + 24;  /* 0x800AC52C */
    R[2] = R[0] + 509;  /* 0x800AC530 */
    R[21] = R[0] + 1;  /* 0x800AC534 */
    sh_(R[29] + 32, R[19]);  /* 0x800AC538 */
    sh_(R[29] + 34, R[2]);  /* 0x800AC53C */
    sh_(R[29] + 36, R[17]);  /* 0x800AC540 */
    sh_(R[29] + 38, R[21]);  /* 0x800AC544 */
    sh_(R[29] + 24, R[19]);  /* 0x800AC548 */
    sh_(R[29] + 26, R[17]);  /* 0x800AC54C */
    sh_(R[29] + 28, R[18]);  /* 0x800AC550 */
    R[4] = lw_(R[16] + 124);  /* 0x800AC554 */
    R[3] = lw_(R[16] + 116);  /* 0x800AC558 */
    R[2] = R[0] + 224;  /* 0x800AC55C */
    sh_(R[29] + 30, R[2]);  /* 0x800AC560 */
    R[4] = R[4] - R[3];  /* 0x800AC564 */
    { R[31] = 0x800AC570u; R[4] = R[4] + R[22]; psx_next = 0x8001CA2Cu; return; }  /* 0x800AC568 jal */
    { R[31] = 0x800AC578u; psx_next = 0x80023E98u; return; }  /* 0x800AC570 jal */
    R[4] = 0x801Eu << 16;  /* 0x800AC578 */
    R[4] = R[4] | 0xC000;  /* 0x800AC57C */
    R[5] = R[2] + 32;  /* 0x800AC580 */
    R[6] = R[5] + R[0];  /* 0x800AC584 */
    R[7] = 0x1u << 16;  /* 0x800AC588 */
    R[7] = R[7] | 0x1000;  /* 0x800AC58C */
    { R[31] = 0x800AC598u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800AC590 jal */
    R[4] = 0x801Eu << 16;  /* 0x800AC598 */
    R[4] = R[4] | 0xC000;  /* 0x800AC59C */
    R[5] = R[20] + R[0];  /* 0x800AC5A0 */
    R[6] = R[29] + 24;  /* 0x800AC5A4 */
    R[2] = R[0] + 500;  /* 0x800AC5A8 */
    sh_(R[29] + 34, R[2]);  /* 0x800AC5AC */
    R[2] = R[0] + 576;  /* 0x800AC5B0 */
    sh_(R[29] + 32, R[19]);  /* 0x800AC5B4 */
    sh_(R[29] + 36, R[17]);  /* 0x800AC5B8 */
    sh_(R[29] + 38, R[21]);  /* 0x800AC5BC */
    sh_(R[29] + 24, R[2]);  /* 0x800AC5C0 */
    sh_(R[29] + 26, R[17]);  /* 0x800AC5C4 */
    sh_(R[29] + 28, R[0]);  /* 0x800AC5C8 */
    { R[31] = 0x800AC5D4u; sh_(R[29] + 30, R[17]); psx_next = 0x8001CA2Cu; return; }  /* 0x800AC5CC jal */
    R[31] = lw_(R[29] + 68);  /* 0x800AC5D4 */
    R[22] = lw_(R[29] + 64);  /* 0x800AC5D8 */
    R[21] = lw_(R[29] + 60);  /* 0x800AC5DC */
    R[20] = lw_(R[29] + 56);  /* 0x800AC5E0 */
    R[19] = lw_(R[29] + 52);  /* 0x800AC5E4 */
    R[18] = lw_(R[29] + 48);  /* 0x800AC5E8 */
    R[17] = lw_(R[29] + 44);  /* 0x800AC5EC */
    R[16] = lw_(R[29] + 40);  /* 0x800AC5F0 */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x800AC5F4 jr ra */
}

void g0_800AC478(void) {
    R[4] = 0x801Eu << 16;  /* 0x800AC478 */
    R[4] = R[4] | 0xC000;  /* 0x800AC47C */
    R[20] = R[29] + 32;  /* 0x800AC480 */
    R[5] = R[20] + R[0];  /* 0x800AC484 */
    R[6] = R[29] + 24;  /* 0x800AC488 */
    R[19] = R[0] + 768;  /* 0x800AC48C */
    R[2] = R[0] + 504;  /* 0x800AC490 */
    R[17] = R[0] + 256;  /* 0x800AC494 */
    sh_(R[29] + 34, R[2]);  /* 0x800AC498 */
    R[2] = R[0] + 3;  /* 0x800AC49C */
    sh_(R[29] + 38, R[2]);  /* 0x800AC4A0 */
    R[2] = R[0] + 704;  /* 0x800AC4A4 */
    sh_(R[29] + 24, R[2]);  /* 0x800AC4A8 */
    R[2] = R[0] + 128;  /* 0x800AC4AC */
    sh_(R[29] + 32, R[19]);  /* 0x800AC4B0 */
    sh_(R[29] + 36, R[17]);  /* 0x800AC4B4 */
    sh_(R[29] + 26, R[17]);  /* 0x800AC4B8 */
    sh_(R[29] + 28, R[0]);  /* 0x800AC4BC */
    { R[31] = 0x800AC4C8u; sh_(R[29] + 30, R[2]); psx_next = 0x8001CA2Cu; return; }  /* 0x800AC4C0 jal */
    R[22] = 0x801Eu << 16;  /* 0x800AC4C8 */
    R[22] = R[22] | 0xC000;  /* 0x800AC4CC */
    R[5] = R[20] + R[0];  /* 0x800AC4D0 */
    R[6] = R[29] + 24;  /* 0x800AC4D4 */
    R[2] = R[0] + 960;  /* 0x800AC4D8 */
    sh_(R[29] + 32, R[2]);  /* 0x800AC4DC */
    R[2] = R[0] + 476;  /* 0x800AC4E0 */
    R[18] = R[0] + 64;  /* 0x800AC4E4 */
    sh_(R[29] + 34, R[2]);  /* 0x800AC4E8 */
    R[2] = R[0] + 4;  /* 0x800AC4EC */
    R[16] = 0x8006u << 16;  /* 0x800AC4F0 */
    R[16] = R[16] - 9544;  /* 0x800AC4F4 */
    sh_(R[29] + 36, R[18]);  /* 0x800AC4F8 */
    sh_(R[29] + 38, R[2]);  /* 0x800AC4FC */
    R[4] = lw_(R[16] + 120);  /* 0x800AC500 */
    R[3] = lw_(R[16] + 116);  /* 0x800AC504 */
    R[2] = R[0] + 640;  /* 0x800AC508 */
    sh_(R[29] + 24, R[2]);  /* 0x800AC50C */
    sh_(R[29] + 26, R[17]);  /* 0x800AC510 */
    sh_(R[29] + 28, R[18]);  /* 0x800AC514 */
    sh_(R[29] + 30, R[17]);  /* 0x800AC518 */
    R[4] = R[4] - R[3];  /* 0x800AC51C */
    { R[31] = 0x800AC528u; R[4] = R[4] + R[22]; psx_next = 0x8001CA2Cu; return; }  /* 0x800AC520 jal */
    R[5] = R[20] + R[0];  /* 0x800AC528 */
    R[6] = R[29] + 24;  /* 0x800AC52C */
    R[2] = R[0] + 509;  /* 0x800AC530 */
    R[21] = R[0] + 1;  /* 0x800AC534 */
    sh_(R[29] + 32, R[19]);  /* 0x800AC538 */
    sh_(R[29] + 34, R[2]);  /* 0x800AC53C */
    sh_(R[29] + 36, R[17]);  /* 0x800AC540 */
    sh_(R[29] + 38, R[21]);  /* 0x800AC544 */
    sh_(R[29] + 24, R[19]);  /* 0x800AC548 */
    sh_(R[29] + 26, R[17]);  /* 0x800AC54C */
    sh_(R[29] + 28, R[18]);  /* 0x800AC550 */
    R[4] = lw_(R[16] + 124);  /* 0x800AC554 */
    R[3] = lw_(R[16] + 116);  /* 0x800AC558 */
    R[2] = R[0] + 224;  /* 0x800AC55C */
    sh_(R[29] + 30, R[2]);  /* 0x800AC560 */
    R[4] = R[4] - R[3];  /* 0x800AC564 */
    { R[31] = 0x800AC570u; R[4] = R[4] + R[22]; psx_next = 0x8001CA2Cu; return; }  /* 0x800AC568 jal */
    { R[31] = 0x800AC578u; psx_next = 0x80023E98u; return; }  /* 0x800AC570 jal */
    R[4] = 0x801Eu << 16;  /* 0x800AC578 */
    R[4] = R[4] | 0xC000;  /* 0x800AC57C */
    R[5] = R[2] + 32;  /* 0x800AC580 */
    R[6] = R[5] + R[0];  /* 0x800AC584 */
    R[7] = 0x1u << 16;  /* 0x800AC588 */
    R[7] = R[7] | 0x1000;  /* 0x800AC58C */
    { R[31] = 0x800AC598u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800AC590 jal */
    R[4] = 0x801Eu << 16;  /* 0x800AC598 */
    R[4] = R[4] | 0xC000;  /* 0x800AC59C */
    R[5] = R[20] + R[0];  /* 0x800AC5A0 */
    R[6] = R[29] + 24;  /* 0x800AC5A4 */
    R[2] = R[0] + 500;  /* 0x800AC5A8 */
    sh_(R[29] + 34, R[2]);  /* 0x800AC5AC */
    R[2] = R[0] + 576;  /* 0x800AC5B0 */
    sh_(R[29] + 32, R[19]);  /* 0x800AC5B4 */
    sh_(R[29] + 36, R[17]);  /* 0x800AC5B8 */
    sh_(R[29] + 38, R[21]);  /* 0x800AC5BC */
    sh_(R[29] + 24, R[2]);  /* 0x800AC5C0 */
    sh_(R[29] + 26, R[17]);  /* 0x800AC5C4 */
    sh_(R[29] + 28, R[0]);  /* 0x800AC5C8 */
    { R[31] = 0x800AC5D4u; sh_(R[29] + 30, R[17]); psx_next = 0x8001CA2Cu; return; }  /* 0x800AC5CC jal */
    R[31] = lw_(R[29] + 68);  /* 0x800AC5D4 */
    R[22] = lw_(R[29] + 64);  /* 0x800AC5D8 */
    R[21] = lw_(R[29] + 60);  /* 0x800AC5DC */
    R[20] = lw_(R[29] + 56);  /* 0x800AC5E0 */
    R[19] = lw_(R[29] + 52);  /* 0x800AC5E4 */
    R[18] = lw_(R[29] + 48);  /* 0x800AC5E8 */
    R[17] = lw_(R[29] + 44);  /* 0x800AC5EC */
    R[16] = lw_(R[29] + 40);  /* 0x800AC5F0 */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x800AC5F4 jr ra */
}

void g0_800AC4C8(void) {
    R[22] = 0x801Eu << 16;  /* 0x800AC4C8 */
    R[22] = R[22] | 0xC000;  /* 0x800AC4CC */
    R[5] = R[20] + R[0];  /* 0x800AC4D0 */
    R[6] = R[29] + 24;  /* 0x800AC4D4 */
    R[2] = R[0] + 960;  /* 0x800AC4D8 */
    sh_(R[29] + 32, R[2]);  /* 0x800AC4DC */
    R[2] = R[0] + 476;  /* 0x800AC4E0 */
    R[18] = R[0] + 64;  /* 0x800AC4E4 */
    sh_(R[29] + 34, R[2]);  /* 0x800AC4E8 */
    R[2] = R[0] + 4;  /* 0x800AC4EC */
    R[16] = 0x8006u << 16;  /* 0x800AC4F0 */
    R[16] = R[16] - 9544;  /* 0x800AC4F4 */
    sh_(R[29] + 36, R[18]);  /* 0x800AC4F8 */
    sh_(R[29] + 38, R[2]);  /* 0x800AC4FC */
    R[4] = lw_(R[16] + 120);  /* 0x800AC500 */
    R[3] = lw_(R[16] + 116);  /* 0x800AC504 */
    R[2] = R[0] + 640;  /* 0x800AC508 */
    sh_(R[29] + 24, R[2]);  /* 0x800AC50C */
    sh_(R[29] + 26, R[17]);  /* 0x800AC510 */
    sh_(R[29] + 28, R[18]);  /* 0x800AC514 */
    sh_(R[29] + 30, R[17]);  /* 0x800AC518 */
    R[4] = R[4] - R[3];  /* 0x800AC51C */
    { R[31] = 0x800AC528u; R[4] = R[4] + R[22]; psx_next = 0x8001CA2Cu; return; }  /* 0x800AC520 jal */
    R[5] = R[20] + R[0];  /* 0x800AC528 */
    R[6] = R[29] + 24;  /* 0x800AC52C */
    R[2] = R[0] + 509;  /* 0x800AC530 */
    R[21] = R[0] + 1;  /* 0x800AC534 */
    sh_(R[29] + 32, R[19]);  /* 0x800AC538 */
    sh_(R[29] + 34, R[2]);  /* 0x800AC53C */
    sh_(R[29] + 36, R[17]);  /* 0x800AC540 */
    sh_(R[29] + 38, R[21]);  /* 0x800AC544 */
    sh_(R[29] + 24, R[19]);  /* 0x800AC548 */
    sh_(R[29] + 26, R[17]);  /* 0x800AC54C */
    sh_(R[29] + 28, R[18]);  /* 0x800AC550 */
    R[4] = lw_(R[16] + 124);  /* 0x800AC554 */
    R[3] = lw_(R[16] + 116);  /* 0x800AC558 */
    R[2] = R[0] + 224;  /* 0x800AC55C */
    sh_(R[29] + 30, R[2]);  /* 0x800AC560 */
    R[4] = R[4] - R[3];  /* 0x800AC564 */
    { R[31] = 0x800AC570u; R[4] = R[4] + R[22]; psx_next = 0x8001CA2Cu; return; }  /* 0x800AC568 jal */
    { R[31] = 0x800AC578u; psx_next = 0x80023E98u; return; }  /* 0x800AC570 jal */
    R[4] = 0x801Eu << 16;  /* 0x800AC578 */
    R[4] = R[4] | 0xC000;  /* 0x800AC57C */
    R[5] = R[2] + 32;  /* 0x800AC580 */
    R[6] = R[5] + R[0];  /* 0x800AC584 */
    R[7] = 0x1u << 16;  /* 0x800AC588 */
    R[7] = R[7] | 0x1000;  /* 0x800AC58C */
    { R[31] = 0x800AC598u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800AC590 jal */
    R[4] = 0x801Eu << 16;  /* 0x800AC598 */
    R[4] = R[4] | 0xC000;  /* 0x800AC59C */
    R[5] = R[20] + R[0];  /* 0x800AC5A0 */
    R[6] = R[29] + 24;  /* 0x800AC5A4 */
    R[2] = R[0] + 500;  /* 0x800AC5A8 */
    sh_(R[29] + 34, R[2]);  /* 0x800AC5AC */
    R[2] = R[0] + 576;  /* 0x800AC5B0 */
    sh_(R[29] + 32, R[19]);  /* 0x800AC5B4 */
    sh_(R[29] + 36, R[17]);  /* 0x800AC5B8 */
    sh_(R[29] + 38, R[21]);  /* 0x800AC5BC */
    sh_(R[29] + 24, R[2]);  /* 0x800AC5C0 */
    sh_(R[29] + 26, R[17]);  /* 0x800AC5C4 */
    sh_(R[29] + 28, R[0]);  /* 0x800AC5C8 */
    { R[31] = 0x800AC5D4u; sh_(R[29] + 30, R[17]); psx_next = 0x8001CA2Cu; return; }  /* 0x800AC5CC jal */
    R[31] = lw_(R[29] + 68);  /* 0x800AC5D4 */
    R[22] = lw_(R[29] + 64);  /* 0x800AC5D8 */
    R[21] = lw_(R[29] + 60);  /* 0x800AC5DC */
    R[20] = lw_(R[29] + 56);  /* 0x800AC5E0 */
    R[19] = lw_(R[29] + 52);  /* 0x800AC5E4 */
    R[18] = lw_(R[29] + 48);  /* 0x800AC5E8 */
    R[17] = lw_(R[29] + 44);  /* 0x800AC5EC */
    R[16] = lw_(R[29] + 40);  /* 0x800AC5F0 */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x800AC5F4 jr ra */
}

void g0_800AC528(void) {
    R[5] = R[20] + R[0];  /* 0x800AC528 */
    R[6] = R[29] + 24;  /* 0x800AC52C */
    R[2] = R[0] + 509;  /* 0x800AC530 */
    R[21] = R[0] + 1;  /* 0x800AC534 */
    sh_(R[29] + 32, R[19]);  /* 0x800AC538 */
    sh_(R[29] + 34, R[2]);  /* 0x800AC53C */
    sh_(R[29] + 36, R[17]);  /* 0x800AC540 */
    sh_(R[29] + 38, R[21]);  /* 0x800AC544 */
    sh_(R[29] + 24, R[19]);  /* 0x800AC548 */
    sh_(R[29] + 26, R[17]);  /* 0x800AC54C */
    sh_(R[29] + 28, R[18]);  /* 0x800AC550 */
    R[4] = lw_(R[16] + 124);  /* 0x800AC554 */
    R[3] = lw_(R[16] + 116);  /* 0x800AC558 */
    R[2] = R[0] + 224;  /* 0x800AC55C */
    sh_(R[29] + 30, R[2]);  /* 0x800AC560 */
    R[4] = R[4] - R[3];  /* 0x800AC564 */
    { R[31] = 0x800AC570u; R[4] = R[4] + R[22]; psx_next = 0x8001CA2Cu; return; }  /* 0x800AC568 jal */
    { R[31] = 0x800AC578u; psx_next = 0x80023E98u; return; }  /* 0x800AC570 jal */
    R[4] = 0x801Eu << 16;  /* 0x800AC578 */
    R[4] = R[4] | 0xC000;  /* 0x800AC57C */
    R[5] = R[2] + 32;  /* 0x800AC580 */
    R[6] = R[5] + R[0];  /* 0x800AC584 */
    R[7] = 0x1u << 16;  /* 0x800AC588 */
    R[7] = R[7] | 0x1000;  /* 0x800AC58C */
    { R[31] = 0x800AC598u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800AC590 jal */
    R[4] = 0x801Eu << 16;  /* 0x800AC598 */
    R[4] = R[4] | 0xC000;  /* 0x800AC59C */
    R[5] = R[20] + R[0];  /* 0x800AC5A0 */
    R[6] = R[29] + 24;  /* 0x800AC5A4 */
    R[2] = R[0] + 500;  /* 0x800AC5A8 */
    sh_(R[29] + 34, R[2]);  /* 0x800AC5AC */
    R[2] = R[0] + 576;  /* 0x800AC5B0 */
    sh_(R[29] + 32, R[19]);  /* 0x800AC5B4 */
    sh_(R[29] + 36, R[17]);  /* 0x800AC5B8 */
    sh_(R[29] + 38, R[21]);  /* 0x800AC5BC */
    sh_(R[29] + 24, R[2]);  /* 0x800AC5C0 */
    sh_(R[29] + 26, R[17]);  /* 0x800AC5C4 */
    sh_(R[29] + 28, R[0]);  /* 0x800AC5C8 */
    { R[31] = 0x800AC5D4u; sh_(R[29] + 30, R[17]); psx_next = 0x8001CA2Cu; return; }  /* 0x800AC5CC jal */
    R[31] = lw_(R[29] + 68);  /* 0x800AC5D4 */
    R[22] = lw_(R[29] + 64);  /* 0x800AC5D8 */
    R[21] = lw_(R[29] + 60);  /* 0x800AC5DC */
    R[20] = lw_(R[29] + 56);  /* 0x800AC5E0 */
    R[19] = lw_(R[29] + 52);  /* 0x800AC5E4 */
    R[18] = lw_(R[29] + 48);  /* 0x800AC5E8 */
    R[17] = lw_(R[29] + 44);  /* 0x800AC5EC */
    R[16] = lw_(R[29] + 40);  /* 0x800AC5F0 */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x800AC5F4 jr ra */
}

void g0_800AC570(void) {
    { R[31] = 0x800AC578u; psx_next = 0x80023E98u; return; }  /* 0x800AC570 jal */
    R[4] = 0x801Eu << 16;  /* 0x800AC578 */
    R[4] = R[4] | 0xC000;  /* 0x800AC57C */
    R[5] = R[2] + 32;  /* 0x800AC580 */
    R[6] = R[5] + R[0];  /* 0x800AC584 */
    R[7] = 0x1u << 16;  /* 0x800AC588 */
    R[7] = R[7] | 0x1000;  /* 0x800AC58C */
    { R[31] = 0x800AC598u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800AC590 jal */
    R[4] = 0x801Eu << 16;  /* 0x800AC598 */
    R[4] = R[4] | 0xC000;  /* 0x800AC59C */
    R[5] = R[20] + R[0];  /* 0x800AC5A0 */
    R[6] = R[29] + 24;  /* 0x800AC5A4 */
    R[2] = R[0] + 500;  /* 0x800AC5A8 */
    sh_(R[29] + 34, R[2]);  /* 0x800AC5AC */
    R[2] = R[0] + 576;  /* 0x800AC5B0 */
    sh_(R[29] + 32, R[19]);  /* 0x800AC5B4 */
    sh_(R[29] + 36, R[17]);  /* 0x800AC5B8 */
    sh_(R[29] + 38, R[21]);  /* 0x800AC5BC */
    sh_(R[29] + 24, R[2]);  /* 0x800AC5C0 */
    sh_(R[29] + 26, R[17]);  /* 0x800AC5C4 */
    sh_(R[29] + 28, R[0]);  /* 0x800AC5C8 */
    { R[31] = 0x800AC5D4u; sh_(R[29] + 30, R[17]); psx_next = 0x8001CA2Cu; return; }  /* 0x800AC5CC jal */
    R[31] = lw_(R[29] + 68);  /* 0x800AC5D4 */
    R[22] = lw_(R[29] + 64);  /* 0x800AC5D8 */
    R[21] = lw_(R[29] + 60);  /* 0x800AC5DC */
    R[20] = lw_(R[29] + 56);  /* 0x800AC5E0 */
    R[19] = lw_(R[29] + 52);  /* 0x800AC5E4 */
    R[18] = lw_(R[29] + 48);  /* 0x800AC5E8 */
    R[17] = lw_(R[29] + 44);  /* 0x800AC5EC */
    R[16] = lw_(R[29] + 40);  /* 0x800AC5F0 */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x800AC5F4 jr ra */
}

void g0_800AC578(void) {
    R[4] = 0x801Eu << 16;  /* 0x800AC578 */
    R[4] = R[4] | 0xC000;  /* 0x800AC57C */
    R[5] = R[2] + 32;  /* 0x800AC580 */
    R[6] = R[5] + R[0];  /* 0x800AC584 */
    R[7] = 0x1u << 16;  /* 0x800AC588 */
    R[7] = R[7] | 0x1000;  /* 0x800AC58C */
    { R[31] = 0x800AC598u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800AC590 jal */
    R[4] = 0x801Eu << 16;  /* 0x800AC598 */
    R[4] = R[4] | 0xC000;  /* 0x800AC59C */
    R[5] = R[20] + R[0];  /* 0x800AC5A0 */
    R[6] = R[29] + 24;  /* 0x800AC5A4 */
    R[2] = R[0] + 500;  /* 0x800AC5A8 */
    sh_(R[29] + 34, R[2]);  /* 0x800AC5AC */
    R[2] = R[0] + 576;  /* 0x800AC5B0 */
    sh_(R[29] + 32, R[19]);  /* 0x800AC5B4 */
    sh_(R[29] + 36, R[17]);  /* 0x800AC5B8 */
    sh_(R[29] + 38, R[21]);  /* 0x800AC5BC */
    sh_(R[29] + 24, R[2]);  /* 0x800AC5C0 */
    sh_(R[29] + 26, R[17]);  /* 0x800AC5C4 */
    sh_(R[29] + 28, R[0]);  /* 0x800AC5C8 */
    { R[31] = 0x800AC5D4u; sh_(R[29] + 30, R[17]); psx_next = 0x8001CA2Cu; return; }  /* 0x800AC5CC jal */
    R[31] = lw_(R[29] + 68);  /* 0x800AC5D4 */
    R[22] = lw_(R[29] + 64);  /* 0x800AC5D8 */
    R[21] = lw_(R[29] + 60);  /* 0x800AC5DC */
    R[20] = lw_(R[29] + 56);  /* 0x800AC5E0 */
    R[19] = lw_(R[29] + 52);  /* 0x800AC5E4 */
    R[18] = lw_(R[29] + 48);  /* 0x800AC5E8 */
    R[17] = lw_(R[29] + 44);  /* 0x800AC5EC */
    R[16] = lw_(R[29] + 40);  /* 0x800AC5F0 */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x800AC5F4 jr ra */
}

void g0_800AC598(void) {
    R[4] = 0x801Eu << 16;  /* 0x800AC598 */
    R[4] = R[4] | 0xC000;  /* 0x800AC59C */
    R[5] = R[20] + R[0];  /* 0x800AC5A0 */
    R[6] = R[29] + 24;  /* 0x800AC5A4 */
    R[2] = R[0] + 500;  /* 0x800AC5A8 */
    sh_(R[29] + 34, R[2]);  /* 0x800AC5AC */
    R[2] = R[0] + 576;  /* 0x800AC5B0 */
    sh_(R[29] + 32, R[19]);  /* 0x800AC5B4 */
    sh_(R[29] + 36, R[17]);  /* 0x800AC5B8 */
    sh_(R[29] + 38, R[21]);  /* 0x800AC5BC */
    sh_(R[29] + 24, R[2]);  /* 0x800AC5C0 */
    sh_(R[29] + 26, R[17]);  /* 0x800AC5C4 */
    sh_(R[29] + 28, R[0]);  /* 0x800AC5C8 */
    { R[31] = 0x800AC5D4u; sh_(R[29] + 30, R[17]); psx_next = 0x8001CA2Cu; return; }  /* 0x800AC5CC jal */
    R[31] = lw_(R[29] + 68);  /* 0x800AC5D4 */
    R[22] = lw_(R[29] + 64);  /* 0x800AC5D8 */
    R[21] = lw_(R[29] + 60);  /* 0x800AC5DC */
    R[20] = lw_(R[29] + 56);  /* 0x800AC5E0 */
    R[19] = lw_(R[29] + 52);  /* 0x800AC5E4 */
    R[18] = lw_(R[29] + 48);  /* 0x800AC5E8 */
    R[17] = lw_(R[29] + 44);  /* 0x800AC5EC */
    R[16] = lw_(R[29] + 40);  /* 0x800AC5F0 */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x800AC5F4 jr ra */
}

void g0_800AC5D4(void) {
    R[31] = lw_(R[29] + 68);  /* 0x800AC5D4 */
    R[22] = lw_(R[29] + 64);  /* 0x800AC5D8 */
    R[21] = lw_(R[29] + 60);  /* 0x800AC5DC */
    R[20] = lw_(R[29] + 56);  /* 0x800AC5E0 */
    R[19] = lw_(R[29] + 52);  /* 0x800AC5E4 */
    R[18] = lw_(R[29] + 48);  /* 0x800AC5E8 */
    R[17] = lw_(R[29] + 44);  /* 0x800AC5EC */
    R[16] = lw_(R[29] + 40);  /* 0x800AC5F0 */
    { R[29] = R[29] + 72; psx_next = R[31]; return; }  /* 0x800AC5F4 jr ra */
}

void g0_800AC5FC(void) {
    R[29] = R[29] - 40;  /* 0x800AC5FC */
    sw_(R[29] + 24, R[16]);  /* 0x800AC600 */
    R[16] = 0x8013u << 16;  /* 0x800AC604 */
    R[16] = R[16] + 4344;  /* 0x800AC608 */
    R[4] = R[16] + R[0];  /* 0x800AC60C */
    R[5] = R[0] + 14;  /* 0x800AC610 */
    R[6] = R[0] + 22;  /* 0x800AC614 */
    R[7] = R[0] + 5120;  /* 0x800AC618 */
    sw_(R[29] + 32, R[31]);  /* 0x800AC61C */
    sw_(R[29] + 28, R[17]);  /* 0x800AC620 */
    { R[31] = 0x800AC62Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800AC624 jal */
    R[4] = 0x8006u << 16;  /* 0x800AC62C */
    R[4] = R[4] - 9544;  /* 0x800AC630 */
    R[3] = 0x8012u << 16;  /* 0x800AC634 */
    R[3] = R[3] + 30872;  /* 0x800AC638 */
    R[9] = R[3] + 192;  /* 0x800AC63C */
    R[5] = lw_(R[4] + 56);  /* 0x800AC640 */
    R[2] = lw_(R[4] + 88);  /* 0x800AC644 */
    R[3] = 0x8013u << 16;  /* 0x800AC648 */
    R[2] = R[2] - R[5];  /* 0x800AC64C */
    R[8] = R[2] + R[16];  /* 0x800AC650 */
    R[2] = lw_(R[4] + 60);  /* 0x800AC654 */
    R[6] = R[8] + 48;  /* 0x800AC658 */
    R[2] = R[2] - R[5];  /* 0x800AC65C */
    R[2] = R[2] + R[16];  /* 0x800AC660 */
    sw_(R[3] + 4324, R[2]);  /* 0x800AC664 */
    R[2] = lw_(R[4] + 64);  /* 0x800AC668 */
    R[3] = 0x8013u << 16;  /* 0x800AC66C */
    R[2] = R[2] - R[5];  /* 0x800AC670 */
    R[2] = R[2] + R[16];  /* 0x800AC674 */
    sw_(R[3] + 4048, R[2]);  /* 0x800AC678 */
    R[2] = lw_(R[4] + 68);  /* 0x800AC67C */
    R[3] = 0x8013u << 16;  /* 0x800AC680 */
    R[2] = R[2] - R[5];  /* 0x800AC684 */
    R[2] = R[2] + R[16];  /* 0x800AC688 */
    sw_(R[3] + 9468, R[2]);  /* 0x800AC68C */
    R[2] = lw_(R[4] + 72);  /* 0x800AC690 */
    R[3] = 0x8013u << 16;  /* 0x800AC694 */
    R[2] = R[2] - R[5];  /* 0x800AC698 */
    R[2] = R[2] + R[16];  /* 0x800AC69C */
    sw_(R[3] + 9464, R[2]);  /* 0x800AC6A0 */
    R[2] = lw_(R[4] + 76);  /* 0x800AC6A4 */
    R[3] = 0x8013u << 16;  /* 0x800AC6A8 */
    R[2] = R[2] - R[5];  /* 0x800AC6AC */
    R[2] = R[2] + R[16];  /* 0x800AC6B0 */
    sw_(R[3] + 4336, R[2]);  /* 0x800AC6B4 */
    R[2] = lw_(R[4] + 80);  /* 0x800AC6B8 */
    R[3] = 0x8013u << 16;  /* 0x800AC6BC */
    R[2] = R[2] - R[5];  /* 0x800AC6C0 */
    R[2] = R[2] + R[16];  /* 0x800AC6C4 */
    sw_(R[3] + 4332, R[2]);  /* 0x800AC6C8 */
    R[2] = lw_(R[4] + 84);  /* 0x800AC6CC */
    R[3] = 0x8013u << 16;  /* 0x800AC6D0 */
    R[2] = R[2] - R[5];  /* 0x800AC6D4 */
    R[2] = R[2] + R[16];  /* 0x800AC6D8 */
    sw_(R[3] + 4008, R[2]);  /* 0x800AC6DC */
L_800AC6E0:;
    R[10] = lw_(R[8]);  /* 0x800AC6E0 */
    R[11] = lw_(R[8] + 4);  /* 0x800AC6E4 */
    R[12] = lw_(R[8] + 8);  /* 0x800AC6E8 */
    R[13] = lw_(R[8] + 12);  /* 0x800AC6EC */
    sw_(R[9], R[10]);  /* 0x800AC6F0 */
    sw_(R[9] + 4, R[11]);  /* 0x800AC6F4 */
    sw_(R[9] + 8, R[12]);  /* 0x800AC6F8 */
    sw_(R[9] + 12, R[13]);  /* 0x800AC6FC */
    R[8] = R[8] + 16;  /* 0x800AC700 */
    { uint32_t _c = (R[8] != R[6]); R[9] = R[9] + 16; if (_c) { psx_bb(); goto L_800AC6E0; } }  /* 0x800AC704 */
    R[5] = 0x8005u << 16;  /* 0x800AC70C */
    R[5] = R[5] - 908;  /* 0x800AC710 */
    R[6] = 0x8005u << 16;  /* 0x800AC714 */
    R[6] = R[6] - 888;  /* 0x800AC718 */
    R[2] = 0x8013u << 16;  /* 0x800AC71C */
    R[4] = lw_(R[2] + 4048);  /* 0x800AC720 */
    R[7] = R[0] + R[0];  /* 0x800AC724 */
    R[10] = lw_(R[8]);  /* 0x800AC728 */
    R[11] = lw_(R[8] + 4);  /* 0x800AC72C */
    R[12] = lw_(R[8] + 8);  /* 0x800AC730 */
    sw_(R[9], R[10]);  /* 0x800AC734 */
    sw_(R[9] + 4, R[11]);  /* 0x800AC738 */
    sw_(R[9] + 8, R[12]);  /* 0x800AC73C */
    { R[31] = 0x800AC748u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC740 jal */
    R[2] = 0x8006u << 16;  /* 0x800AC748 */
    R[2] = R[2] - 9544;  /* 0x800AC74C */
    R[3] = lw_(R[2] + 68);  /* 0x800AC750 */
    R[2] = lw_(R[2] + 64);  /* 0x800AC754 */
    R[3] = R[3] - R[2];  /* 0x800AC75C */
    R[3] = (R[3] < (uint32_t)769u);  /* 0x800AC760 */
    { uint32_t _c = (R[3] != R[0]); R[17] = 0x800Fu << 16; if (_c) { goto L_800AC780; } }  /* 0x800AC764 */
    R[4] = 0x8008u << 16;  /* 0x800AC76C */
    { R[31] = 0x800AC778u; R[4] = R[4] + 9404; psx_next = 0x8001BBF8u; return; }  /* 0x800AC770 jal */
    { R[31] = 0x800AC780u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x800AC778 jal */
L_800AC780:;
    R[17] = R[17] - 12848;  /* 0x800AC780 */
    R[5] = R[17] + R[0];  /* 0x800AC784 */
    R[16] = 0x800Fu << 16;  /* 0x800AC788 */
    R[16] = R[16] - 12844;  /* 0x800AC78C */
    R[6] = R[16] + R[0];  /* 0x800AC790 */
    R[2] = 0x8013u << 16;  /* 0x800AC794 */
    R[4] = lw_(R[2] + 9468);  /* 0x800AC798 */
    R[7] = R[0] + R[0];  /* 0x800AC79C */
    { R[31] = 0x800AC7A8u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7A0 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7A8 */
    R[6] = R[16] + R[0];  /* 0x800AC7AC */
    R[2] = 0x8013u << 16;  /* 0x800AC7B0 */
    R[4] = lw_(R[2] + 9464);  /* 0x800AC7B4 */
    R[7] = R[0] + R[0];  /* 0x800AC7B8 */
    { R[31] = 0x800AC7C4u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7BC jal */
    R[5] = R[17] + R[0];  /* 0x800AC7C4 */
    R[6] = R[16] + R[0];  /* 0x800AC7C8 */
    R[2] = 0x8013u << 16;  /* 0x800AC7CC */
    R[4] = lw_(R[2] + 4336);  /* 0x800AC7D0 */
    R[7] = R[0] + R[0];  /* 0x800AC7D4 */
    { R[31] = 0x800AC7E0u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7D8 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7E0 */
    R[6] = R[16] + R[0];  /* 0x800AC7E4 */
    R[2] = 0x8013u << 16;  /* 0x800AC7E8 */
    R[4] = lw_(R[2] + 4332);  /* 0x800AC7EC */
    R[7] = R[0] + R[0];  /* 0x800AC7F0 */
    { R[31] = 0x800AC7FCu; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7F4 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7FC */
    R[6] = R[16] + R[0];  /* 0x800AC800 */
    R[2] = 0x8013u << 16;  /* 0x800AC804 */
    R[4] = lw_(R[2] + 4008);  /* 0x800AC808 */
    R[7] = R[0] + R[0];  /* 0x800AC80C */
    { R[31] = 0x800AC818u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC810 jal */
    R[2] = 0x8006u << 16;  /* 0x800AC818 */
    R[2] = lw_(R[2] + -6472);  /* 0x800AC81C */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8008u << 16; if (_c) { goto L_800AC848; } }  /* 0x800AC824 */
    sw_(R[29] + 16, R[0]);  /* 0x800AC82C */
    R[4] = R[4] + 9204;  /* 0x800AC830 */
    R[5] = 0x8013u << 16;  /* 0x800AC834 */
    R[5] = R[5] - 16280;  /* 0x800AC838 */
    R[6] = R[0] + R[0];  /* 0x800AC83C */
    { R[31] = 0x800AC848u; R[7] = R[0] + 2048; psx_next = 0x8001BC34u; return; }  /* 0x800AC840 jal */
L_800AC848:;
    R[31] = lw_(R[29] + 32);  /* 0x800AC848 */
    R[17] = lw_(R[29] + 28);  /* 0x800AC84C */
    R[16] = lw_(R[29] + 24);  /* 0x800AC850 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AC854 jr ra */
}

void g0_800AC62C(void) {
    R[4] = 0x8006u << 16;  /* 0x800AC62C */
    R[4] = R[4] - 9544;  /* 0x800AC630 */
    R[3] = 0x8012u << 16;  /* 0x800AC634 */
    R[3] = R[3] + 30872;  /* 0x800AC638 */
    R[9] = R[3] + 192;  /* 0x800AC63C */
    R[5] = lw_(R[4] + 56);  /* 0x800AC640 */
    R[2] = lw_(R[4] + 88);  /* 0x800AC644 */
    R[3] = 0x8013u << 16;  /* 0x800AC648 */
    R[2] = R[2] - R[5];  /* 0x800AC64C */
    R[8] = R[2] + R[16];  /* 0x800AC650 */
    R[2] = lw_(R[4] + 60);  /* 0x800AC654 */
    R[6] = R[8] + 48;  /* 0x800AC658 */
    R[2] = R[2] - R[5];  /* 0x800AC65C */
    R[2] = R[2] + R[16];  /* 0x800AC660 */
    sw_(R[3] + 4324, R[2]);  /* 0x800AC664 */
    R[2] = lw_(R[4] + 64);  /* 0x800AC668 */
    R[3] = 0x8013u << 16;  /* 0x800AC66C */
    R[2] = R[2] - R[5];  /* 0x800AC670 */
    R[2] = R[2] + R[16];  /* 0x800AC674 */
    sw_(R[3] + 4048, R[2]);  /* 0x800AC678 */
    R[2] = lw_(R[4] + 68);  /* 0x800AC67C */
    R[3] = 0x8013u << 16;  /* 0x800AC680 */
    R[2] = R[2] - R[5];  /* 0x800AC684 */
    R[2] = R[2] + R[16];  /* 0x800AC688 */
    sw_(R[3] + 9468, R[2]);  /* 0x800AC68C */
    R[2] = lw_(R[4] + 72);  /* 0x800AC690 */
    R[3] = 0x8013u << 16;  /* 0x800AC694 */
    R[2] = R[2] - R[5];  /* 0x800AC698 */
    R[2] = R[2] + R[16];  /* 0x800AC69C */
    sw_(R[3] + 9464, R[2]);  /* 0x800AC6A0 */
    R[2] = lw_(R[4] + 76);  /* 0x800AC6A4 */
    R[3] = 0x8013u << 16;  /* 0x800AC6A8 */
    R[2] = R[2] - R[5];  /* 0x800AC6AC */
    R[2] = R[2] + R[16];  /* 0x800AC6B0 */
    sw_(R[3] + 4336, R[2]);  /* 0x800AC6B4 */
    R[2] = lw_(R[4] + 80);  /* 0x800AC6B8 */
    R[3] = 0x8013u << 16;  /* 0x800AC6BC */
    R[2] = R[2] - R[5];  /* 0x800AC6C0 */
    R[2] = R[2] + R[16];  /* 0x800AC6C4 */
    sw_(R[3] + 4332, R[2]);  /* 0x800AC6C8 */
    R[2] = lw_(R[4] + 84);  /* 0x800AC6CC */
    R[3] = 0x8013u << 16;  /* 0x800AC6D0 */
    R[2] = R[2] - R[5];  /* 0x800AC6D4 */
    R[2] = R[2] + R[16];  /* 0x800AC6D8 */
    sw_(R[3] + 4008, R[2]);  /* 0x800AC6DC */
L_800AC6E0:;
    R[10] = lw_(R[8]);  /* 0x800AC6E0 */
    R[11] = lw_(R[8] + 4);  /* 0x800AC6E4 */
    R[12] = lw_(R[8] + 8);  /* 0x800AC6E8 */
    R[13] = lw_(R[8] + 12);  /* 0x800AC6EC */
    sw_(R[9], R[10]);  /* 0x800AC6F0 */
    sw_(R[9] + 4, R[11]);  /* 0x800AC6F4 */
    sw_(R[9] + 8, R[12]);  /* 0x800AC6F8 */
    sw_(R[9] + 12, R[13]);  /* 0x800AC6FC */
    R[8] = R[8] + 16;  /* 0x800AC700 */
    { uint32_t _c = (R[8] != R[6]); R[9] = R[9] + 16; if (_c) { psx_bb(); goto L_800AC6E0; } }  /* 0x800AC704 */
    R[5] = 0x8005u << 16;  /* 0x800AC70C */
    R[5] = R[5] - 908;  /* 0x800AC710 */
    R[6] = 0x8005u << 16;  /* 0x800AC714 */
    R[6] = R[6] - 888;  /* 0x800AC718 */
    R[2] = 0x8013u << 16;  /* 0x800AC71C */
    R[4] = lw_(R[2] + 4048);  /* 0x800AC720 */
    R[7] = R[0] + R[0];  /* 0x800AC724 */
    R[10] = lw_(R[8]);  /* 0x800AC728 */
    R[11] = lw_(R[8] + 4);  /* 0x800AC72C */
    R[12] = lw_(R[8] + 8);  /* 0x800AC730 */
    sw_(R[9], R[10]);  /* 0x800AC734 */
    sw_(R[9] + 4, R[11]);  /* 0x800AC738 */
    sw_(R[9] + 8, R[12]);  /* 0x800AC73C */
    { R[31] = 0x800AC748u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC740 jal */
    R[2] = 0x8006u << 16;  /* 0x800AC748 */
    R[2] = R[2] - 9544;  /* 0x800AC74C */
    R[3] = lw_(R[2] + 68);  /* 0x800AC750 */
    R[2] = lw_(R[2] + 64);  /* 0x800AC754 */
    R[3] = R[3] - R[2];  /* 0x800AC75C */
    R[3] = (R[3] < (uint32_t)769u);  /* 0x800AC760 */
    { uint32_t _c = (R[3] != R[0]); R[17] = 0x800Fu << 16; if (_c) { goto L_800AC780; } }  /* 0x800AC764 */
    R[4] = 0x8008u << 16;  /* 0x800AC76C */
    { R[31] = 0x800AC778u; R[4] = R[4] + 9404; psx_next = 0x8001BBF8u; return; }  /* 0x800AC770 jal */
    { R[31] = 0x800AC780u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x800AC778 jal */
L_800AC780:;
    R[17] = R[17] - 12848;  /* 0x800AC780 */
    R[5] = R[17] + R[0];  /* 0x800AC784 */
    R[16] = 0x800Fu << 16;  /* 0x800AC788 */
    R[16] = R[16] - 12844;  /* 0x800AC78C */
    R[6] = R[16] + R[0];  /* 0x800AC790 */
    R[2] = 0x8013u << 16;  /* 0x800AC794 */
    R[4] = lw_(R[2] + 9468);  /* 0x800AC798 */
    R[7] = R[0] + R[0];  /* 0x800AC79C */
    { R[31] = 0x800AC7A8u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7A0 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7A8 */
    R[6] = R[16] + R[0];  /* 0x800AC7AC */
    R[2] = 0x8013u << 16;  /* 0x800AC7B0 */
    R[4] = lw_(R[2] + 9464);  /* 0x800AC7B4 */
    R[7] = R[0] + R[0];  /* 0x800AC7B8 */
    { R[31] = 0x800AC7C4u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7BC jal */
    R[5] = R[17] + R[0];  /* 0x800AC7C4 */
    R[6] = R[16] + R[0];  /* 0x800AC7C8 */
    R[2] = 0x8013u << 16;  /* 0x800AC7CC */
    R[4] = lw_(R[2] + 4336);  /* 0x800AC7D0 */
    R[7] = R[0] + R[0];  /* 0x800AC7D4 */
    { R[31] = 0x800AC7E0u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7D8 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7E0 */
    R[6] = R[16] + R[0];  /* 0x800AC7E4 */
    R[2] = 0x8013u << 16;  /* 0x800AC7E8 */
    R[4] = lw_(R[2] + 4332);  /* 0x800AC7EC */
    R[7] = R[0] + R[0];  /* 0x800AC7F0 */
    { R[31] = 0x800AC7FCu; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7F4 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7FC */
    R[6] = R[16] + R[0];  /* 0x800AC800 */
    R[2] = 0x8013u << 16;  /* 0x800AC804 */
    R[4] = lw_(R[2] + 4008);  /* 0x800AC808 */
    R[7] = R[0] + R[0];  /* 0x800AC80C */
    { R[31] = 0x800AC818u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC810 jal */
    R[2] = 0x8006u << 16;  /* 0x800AC818 */
    R[2] = lw_(R[2] + -6472);  /* 0x800AC81C */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8008u << 16; if (_c) { goto L_800AC848; } }  /* 0x800AC824 */
    sw_(R[29] + 16, R[0]);  /* 0x800AC82C */
    R[4] = R[4] + 9204;  /* 0x800AC830 */
    R[5] = 0x8013u << 16;  /* 0x800AC834 */
    R[5] = R[5] - 16280;  /* 0x800AC838 */
    R[6] = R[0] + R[0];  /* 0x800AC83C */
    { R[31] = 0x800AC848u; R[7] = R[0] + 2048; psx_next = 0x8001BC34u; return; }  /* 0x800AC840 jal */
L_800AC848:;
    R[31] = lw_(R[29] + 32);  /* 0x800AC848 */
    R[17] = lw_(R[29] + 28);  /* 0x800AC84C */
    R[16] = lw_(R[29] + 24);  /* 0x800AC850 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AC854 jr ra */
}

void g0_800AC748(void) {
    R[2] = 0x8006u << 16;  /* 0x800AC748 */
    R[2] = R[2] - 9544;  /* 0x800AC74C */
    R[3] = lw_(R[2] + 68);  /* 0x800AC750 */
    R[2] = lw_(R[2] + 64);  /* 0x800AC754 */
    R[3] = R[3] - R[2];  /* 0x800AC75C */
    R[3] = (R[3] < (uint32_t)769u);  /* 0x800AC760 */
    { uint32_t _c = (R[3] != R[0]); R[17] = 0x800Fu << 16; if (_c) { goto L_800AC780; } }  /* 0x800AC764 */
    R[4] = 0x8008u << 16;  /* 0x800AC76C */
    { R[31] = 0x800AC778u; R[4] = R[4] + 9404; psx_next = 0x8001BBF8u; return; }  /* 0x800AC770 jal */
    { R[31] = 0x800AC780u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x800AC778 jal */
L_800AC780:;
    R[17] = R[17] - 12848;  /* 0x800AC780 */
    R[5] = R[17] + R[0];  /* 0x800AC784 */
    R[16] = 0x800Fu << 16;  /* 0x800AC788 */
    R[16] = R[16] - 12844;  /* 0x800AC78C */
    R[6] = R[16] + R[0];  /* 0x800AC790 */
    R[2] = 0x8013u << 16;  /* 0x800AC794 */
    R[4] = lw_(R[2] + 9468);  /* 0x800AC798 */
    R[7] = R[0] + R[0];  /* 0x800AC79C */
    { R[31] = 0x800AC7A8u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7A0 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7A8 */
    R[6] = R[16] + R[0];  /* 0x800AC7AC */
    R[2] = 0x8013u << 16;  /* 0x800AC7B0 */
    R[4] = lw_(R[2] + 9464);  /* 0x800AC7B4 */
    R[7] = R[0] + R[0];  /* 0x800AC7B8 */
    { R[31] = 0x800AC7C4u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7BC jal */
    R[5] = R[17] + R[0];  /* 0x800AC7C4 */
    R[6] = R[16] + R[0];  /* 0x800AC7C8 */
    R[2] = 0x8013u << 16;  /* 0x800AC7CC */
    R[4] = lw_(R[2] + 4336);  /* 0x800AC7D0 */
    R[7] = R[0] + R[0];  /* 0x800AC7D4 */
    { R[31] = 0x800AC7E0u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7D8 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7E0 */
    R[6] = R[16] + R[0];  /* 0x800AC7E4 */
    R[2] = 0x8013u << 16;  /* 0x800AC7E8 */
    R[4] = lw_(R[2] + 4332);  /* 0x800AC7EC */
    R[7] = R[0] + R[0];  /* 0x800AC7F0 */
    { R[31] = 0x800AC7FCu; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7F4 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7FC */
    R[6] = R[16] + R[0];  /* 0x800AC800 */
    R[2] = 0x8013u << 16;  /* 0x800AC804 */
    R[4] = lw_(R[2] + 4008);  /* 0x800AC808 */
    R[7] = R[0] + R[0];  /* 0x800AC80C */
    { R[31] = 0x800AC818u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC810 jal */
    R[2] = 0x8006u << 16;  /* 0x800AC818 */
    R[2] = lw_(R[2] + -6472);  /* 0x800AC81C */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8008u << 16; if (_c) { goto L_800AC848; } }  /* 0x800AC824 */
    sw_(R[29] + 16, R[0]);  /* 0x800AC82C */
    R[4] = R[4] + 9204;  /* 0x800AC830 */
    R[5] = 0x8013u << 16;  /* 0x800AC834 */
    R[5] = R[5] - 16280;  /* 0x800AC838 */
    R[6] = R[0] + R[0];  /* 0x800AC83C */
    { R[31] = 0x800AC848u; R[7] = R[0] + 2048; psx_next = 0x8001BC34u; return; }  /* 0x800AC840 jal */
L_800AC848:;
    R[31] = lw_(R[29] + 32);  /* 0x800AC848 */
    R[17] = lw_(R[29] + 28);  /* 0x800AC84C */
    R[16] = lw_(R[29] + 24);  /* 0x800AC850 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AC854 jr ra */
}

void g0_800AC778(void) {
    { R[31] = 0x800AC780u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x800AC778 jal */
    R[17] = R[17] - 12848;  /* 0x800AC780 */
    R[5] = R[17] + R[0];  /* 0x800AC784 */
    R[16] = 0x800Fu << 16;  /* 0x800AC788 */
    R[16] = R[16] - 12844;  /* 0x800AC78C */
    R[6] = R[16] + R[0];  /* 0x800AC790 */
    R[2] = 0x8013u << 16;  /* 0x800AC794 */
    R[4] = lw_(R[2] + 9468);  /* 0x800AC798 */
    R[7] = R[0] + R[0];  /* 0x800AC79C */
    { R[31] = 0x800AC7A8u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7A0 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7A8 */
    R[6] = R[16] + R[0];  /* 0x800AC7AC */
    R[2] = 0x8013u << 16;  /* 0x800AC7B0 */
    R[4] = lw_(R[2] + 9464);  /* 0x800AC7B4 */
    R[7] = R[0] + R[0];  /* 0x800AC7B8 */
    { R[31] = 0x800AC7C4u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7BC jal */
    R[5] = R[17] + R[0];  /* 0x800AC7C4 */
    R[6] = R[16] + R[0];  /* 0x800AC7C8 */
    R[2] = 0x8013u << 16;  /* 0x800AC7CC */
    R[4] = lw_(R[2] + 4336);  /* 0x800AC7D0 */
    R[7] = R[0] + R[0];  /* 0x800AC7D4 */
    { R[31] = 0x800AC7E0u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7D8 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7E0 */
    R[6] = R[16] + R[0];  /* 0x800AC7E4 */
    R[2] = 0x8013u << 16;  /* 0x800AC7E8 */
    R[4] = lw_(R[2] + 4332);  /* 0x800AC7EC */
    R[7] = R[0] + R[0];  /* 0x800AC7F0 */
    { R[31] = 0x800AC7FCu; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7F4 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7FC */
    R[6] = R[16] + R[0];  /* 0x800AC800 */
    R[2] = 0x8013u << 16;  /* 0x800AC804 */
    R[4] = lw_(R[2] + 4008);  /* 0x800AC808 */
    R[7] = R[0] + R[0];  /* 0x800AC80C */
    { R[31] = 0x800AC818u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC810 jal */
    R[2] = 0x8006u << 16;  /* 0x800AC818 */
    R[2] = lw_(R[2] + -6472);  /* 0x800AC81C */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8008u << 16; if (_c) { goto L_800AC848; } }  /* 0x800AC824 */
    sw_(R[29] + 16, R[0]);  /* 0x800AC82C */
    R[4] = R[4] + 9204;  /* 0x800AC830 */
    R[5] = 0x8013u << 16;  /* 0x800AC834 */
    R[5] = R[5] - 16280;  /* 0x800AC838 */
    R[6] = R[0] + R[0];  /* 0x800AC83C */
    { R[31] = 0x800AC848u; R[7] = R[0] + 2048; psx_next = 0x8001BC34u; return; }  /* 0x800AC840 jal */
L_800AC848:;
    R[31] = lw_(R[29] + 32);  /* 0x800AC848 */
    R[17] = lw_(R[29] + 28);  /* 0x800AC84C */
    R[16] = lw_(R[29] + 24);  /* 0x800AC850 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AC854 jr ra */
}

void g0_800AC780(void) {
    R[17] = R[17] - 12848;  /* 0x800AC780 */
    R[5] = R[17] + R[0];  /* 0x800AC784 */
    R[16] = 0x800Fu << 16;  /* 0x800AC788 */
    R[16] = R[16] - 12844;  /* 0x800AC78C */
    R[6] = R[16] + R[0];  /* 0x800AC790 */
    R[2] = 0x8013u << 16;  /* 0x800AC794 */
    R[4] = lw_(R[2] + 9468);  /* 0x800AC798 */
    R[7] = R[0] + R[0];  /* 0x800AC79C */
    { R[31] = 0x800AC7A8u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7A0 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7A8 */
    R[6] = R[16] + R[0];  /* 0x800AC7AC */
    R[2] = 0x8013u << 16;  /* 0x800AC7B0 */
    R[4] = lw_(R[2] + 9464);  /* 0x800AC7B4 */
    R[7] = R[0] + R[0];  /* 0x800AC7B8 */
    { R[31] = 0x800AC7C4u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7BC jal */
    R[5] = R[17] + R[0];  /* 0x800AC7C4 */
    R[6] = R[16] + R[0];  /* 0x800AC7C8 */
    R[2] = 0x8013u << 16;  /* 0x800AC7CC */
    R[4] = lw_(R[2] + 4336);  /* 0x800AC7D0 */
    R[7] = R[0] + R[0];  /* 0x800AC7D4 */
    { R[31] = 0x800AC7E0u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7D8 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7E0 */
    R[6] = R[16] + R[0];  /* 0x800AC7E4 */
    R[2] = 0x8013u << 16;  /* 0x800AC7E8 */
    R[4] = lw_(R[2] + 4332);  /* 0x800AC7EC */
    R[7] = R[0] + R[0];  /* 0x800AC7F0 */
    { R[31] = 0x800AC7FCu; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7F4 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7FC */
    R[6] = R[16] + R[0];  /* 0x800AC800 */
    R[2] = 0x8013u << 16;  /* 0x800AC804 */
    R[4] = lw_(R[2] + 4008);  /* 0x800AC808 */
    R[7] = R[0] + R[0];  /* 0x800AC80C */
    { R[31] = 0x800AC818u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC810 jal */
    R[2] = 0x8006u << 16;  /* 0x800AC818 */
    R[2] = lw_(R[2] + -6472);  /* 0x800AC81C */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8008u << 16; if (_c) { goto L_800AC848; } }  /* 0x800AC824 */
    sw_(R[29] + 16, R[0]);  /* 0x800AC82C */
    R[4] = R[4] + 9204;  /* 0x800AC830 */
    R[5] = 0x8013u << 16;  /* 0x800AC834 */
    R[5] = R[5] - 16280;  /* 0x800AC838 */
    R[6] = R[0] + R[0];  /* 0x800AC83C */
    { R[31] = 0x800AC848u; R[7] = R[0] + 2048; psx_next = 0x8001BC34u; return; }  /* 0x800AC840 jal */
L_800AC848:;
    R[31] = lw_(R[29] + 32);  /* 0x800AC848 */
    R[17] = lw_(R[29] + 28);  /* 0x800AC84C */
    R[16] = lw_(R[29] + 24);  /* 0x800AC850 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AC854 jr ra */
}

void g0_800AC7A8(void) {
    R[5] = R[17] + R[0];  /* 0x800AC7A8 */
    R[6] = R[16] + R[0];  /* 0x800AC7AC */
    R[2] = 0x8013u << 16;  /* 0x800AC7B0 */
    R[4] = lw_(R[2] + 9464);  /* 0x800AC7B4 */
    R[7] = R[0] + R[0];  /* 0x800AC7B8 */
    { R[31] = 0x800AC7C4u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7BC jal */
    R[5] = R[17] + R[0];  /* 0x800AC7C4 */
    R[6] = R[16] + R[0];  /* 0x800AC7C8 */
    R[2] = 0x8013u << 16;  /* 0x800AC7CC */
    R[4] = lw_(R[2] + 4336);  /* 0x800AC7D0 */
    R[7] = R[0] + R[0];  /* 0x800AC7D4 */
    { R[31] = 0x800AC7E0u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7D8 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7E0 */
    R[6] = R[16] + R[0];  /* 0x800AC7E4 */
    R[2] = 0x8013u << 16;  /* 0x800AC7E8 */
    R[4] = lw_(R[2] + 4332);  /* 0x800AC7EC */
    R[7] = R[0] + R[0];  /* 0x800AC7F0 */
    { R[31] = 0x800AC7FCu; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7F4 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7FC */
    R[6] = R[16] + R[0];  /* 0x800AC800 */
    R[2] = 0x8013u << 16;  /* 0x800AC804 */
    R[4] = lw_(R[2] + 4008);  /* 0x800AC808 */
    R[7] = R[0] + R[0];  /* 0x800AC80C */
    { R[31] = 0x800AC818u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC810 jal */
    R[2] = 0x8006u << 16;  /* 0x800AC818 */
    R[2] = lw_(R[2] + -6472);  /* 0x800AC81C */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8008u << 16; if (_c) { goto L_800AC848; } }  /* 0x800AC824 */
    sw_(R[29] + 16, R[0]);  /* 0x800AC82C */
    R[4] = R[4] + 9204;  /* 0x800AC830 */
    R[5] = 0x8013u << 16;  /* 0x800AC834 */
    R[5] = R[5] - 16280;  /* 0x800AC838 */
    R[6] = R[0] + R[0];  /* 0x800AC83C */
    { R[31] = 0x800AC848u; R[7] = R[0] + 2048; psx_next = 0x8001BC34u; return; }  /* 0x800AC840 jal */
L_800AC848:;
    R[31] = lw_(R[29] + 32);  /* 0x800AC848 */
    R[17] = lw_(R[29] + 28);  /* 0x800AC84C */
    R[16] = lw_(R[29] + 24);  /* 0x800AC850 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AC854 jr ra */
}

void g0_800AC7C4(void) {
    R[5] = R[17] + R[0];  /* 0x800AC7C4 */
    R[6] = R[16] + R[0];  /* 0x800AC7C8 */
    R[2] = 0x8013u << 16;  /* 0x800AC7CC */
    R[4] = lw_(R[2] + 4336);  /* 0x800AC7D0 */
    R[7] = R[0] + R[0];  /* 0x800AC7D4 */
    { R[31] = 0x800AC7E0u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7D8 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7E0 */
    R[6] = R[16] + R[0];  /* 0x800AC7E4 */
    R[2] = 0x8013u << 16;  /* 0x800AC7E8 */
    R[4] = lw_(R[2] + 4332);  /* 0x800AC7EC */
    R[7] = R[0] + R[0];  /* 0x800AC7F0 */
    { R[31] = 0x800AC7FCu; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7F4 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7FC */
    R[6] = R[16] + R[0];  /* 0x800AC800 */
    R[2] = 0x8013u << 16;  /* 0x800AC804 */
    R[4] = lw_(R[2] + 4008);  /* 0x800AC808 */
    R[7] = R[0] + R[0];  /* 0x800AC80C */
    { R[31] = 0x800AC818u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC810 jal */
    R[2] = 0x8006u << 16;  /* 0x800AC818 */
    R[2] = lw_(R[2] + -6472);  /* 0x800AC81C */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8008u << 16; if (_c) { goto L_800AC848; } }  /* 0x800AC824 */
    sw_(R[29] + 16, R[0]);  /* 0x800AC82C */
    R[4] = R[4] + 9204;  /* 0x800AC830 */
    R[5] = 0x8013u << 16;  /* 0x800AC834 */
    R[5] = R[5] - 16280;  /* 0x800AC838 */
    R[6] = R[0] + R[0];  /* 0x800AC83C */
    { R[31] = 0x800AC848u; R[7] = R[0] + 2048; psx_next = 0x8001BC34u; return; }  /* 0x800AC840 jal */
L_800AC848:;
    R[31] = lw_(R[29] + 32);  /* 0x800AC848 */
    R[17] = lw_(R[29] + 28);  /* 0x800AC84C */
    R[16] = lw_(R[29] + 24);  /* 0x800AC850 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AC854 jr ra */
}

void g0_800AC7E0(void) {
    R[5] = R[17] + R[0];  /* 0x800AC7E0 */
    R[6] = R[16] + R[0];  /* 0x800AC7E4 */
    R[2] = 0x8013u << 16;  /* 0x800AC7E8 */
    R[4] = lw_(R[2] + 4332);  /* 0x800AC7EC */
    R[7] = R[0] + R[0];  /* 0x800AC7F0 */
    { R[31] = 0x800AC7FCu; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC7F4 jal */
    R[5] = R[17] + R[0];  /* 0x800AC7FC */
    R[6] = R[16] + R[0];  /* 0x800AC800 */
    R[2] = 0x8013u << 16;  /* 0x800AC804 */
    R[4] = lw_(R[2] + 4008);  /* 0x800AC808 */
    R[7] = R[0] + R[0];  /* 0x800AC80C */
    { R[31] = 0x800AC818u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC810 jal */
    R[2] = 0x8006u << 16;  /* 0x800AC818 */
    R[2] = lw_(R[2] + -6472);  /* 0x800AC81C */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8008u << 16; if (_c) { goto L_800AC848; } }  /* 0x800AC824 */
    sw_(R[29] + 16, R[0]);  /* 0x800AC82C */
    R[4] = R[4] + 9204;  /* 0x800AC830 */
    R[5] = 0x8013u << 16;  /* 0x800AC834 */
    R[5] = R[5] - 16280;  /* 0x800AC838 */
    R[6] = R[0] + R[0];  /* 0x800AC83C */
    { R[31] = 0x800AC848u; R[7] = R[0] + 2048; psx_next = 0x8001BC34u; return; }  /* 0x800AC840 jal */
L_800AC848:;
    R[31] = lw_(R[29] + 32);  /* 0x800AC848 */
    R[17] = lw_(R[29] + 28);  /* 0x800AC84C */
    R[16] = lw_(R[29] + 24);  /* 0x800AC850 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AC854 jr ra */
}

void g0_800AC7FC(void) {
    R[5] = R[17] + R[0];  /* 0x800AC7FC */
    R[6] = R[16] + R[0];  /* 0x800AC800 */
    R[2] = 0x8013u << 16;  /* 0x800AC804 */
    R[4] = lw_(R[2] + 4008);  /* 0x800AC808 */
    R[7] = R[0] + R[0];  /* 0x800AC80C */
    { R[31] = 0x800AC818u; sw_(R[29] + 16, R[0]); psx_next = 0x80022730u; return; }  /* 0x800AC810 jal */
    R[2] = 0x8006u << 16;  /* 0x800AC818 */
    R[2] = lw_(R[2] + -6472);  /* 0x800AC81C */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8008u << 16; if (_c) { goto L_800AC848; } }  /* 0x800AC824 */
    sw_(R[29] + 16, R[0]);  /* 0x800AC82C */
    R[4] = R[4] + 9204;  /* 0x800AC830 */
    R[5] = 0x8013u << 16;  /* 0x800AC834 */
    R[5] = R[5] - 16280;  /* 0x800AC838 */
    R[6] = R[0] + R[0];  /* 0x800AC83C */
    { R[31] = 0x800AC848u; R[7] = R[0] + 2048; psx_next = 0x8001BC34u; return; }  /* 0x800AC840 jal */
L_800AC848:;
    R[31] = lw_(R[29] + 32);  /* 0x800AC848 */
    R[17] = lw_(R[29] + 28);  /* 0x800AC84C */
    R[16] = lw_(R[29] + 24);  /* 0x800AC850 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AC854 jr ra */
}

void g0_800AC818(void) {
    R[2] = 0x8006u << 16;  /* 0x800AC818 */
    R[2] = lw_(R[2] + -6472);  /* 0x800AC81C */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8008u << 16; if (_c) { goto L_800AC848; } }  /* 0x800AC824 */
    sw_(R[29] + 16, R[0]);  /* 0x800AC82C */
    R[4] = R[4] + 9204;  /* 0x800AC830 */
    R[5] = 0x8013u << 16;  /* 0x800AC834 */
    R[5] = R[5] - 16280;  /* 0x800AC838 */
    R[6] = R[0] + R[0];  /* 0x800AC83C */
    { R[31] = 0x800AC848u; R[7] = R[0] + 2048; psx_next = 0x8001BC34u; return; }  /* 0x800AC840 jal */
L_800AC848:;
    R[31] = lw_(R[29] + 32);  /* 0x800AC848 */
    R[17] = lw_(R[29] + 28);  /* 0x800AC84C */
    R[16] = lw_(R[29] + 24);  /* 0x800AC850 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AC854 jr ra */
}

void g0_800AC848(void) {
    R[31] = lw_(R[29] + 32);  /* 0x800AC848 */
    R[17] = lw_(R[29] + 28);  /* 0x800AC84C */
    R[16] = lw_(R[29] + 24);  /* 0x800AC850 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AC854 jr ra */
}

void g0_800AC85C(void) {
    R[29] = R[29] - 48;  /* 0x800AC85C */
    sw_(R[29] + 32, R[16]);  /* 0x800AC860 */
    R[16] = R[4] + R[0];  /* 0x800AC864 */
    sw_(R[29] + 40, R[31]);  /* 0x800AC868 */
    sw_(R[29] + 36, R[17]);  /* 0x800AC86C */
    R[2] = lw_(R[16] + 712);  /* 0x800AC870 */
    { uint32_t _c = (R[2] == R[0]); R[17] = R[5] + R[0]; if (_c) { goto L_800AC88C; } }  /* 0x800AC878 */
    R[2] = 0x8011u << 16;  /* 0x800AC880 */
    { R[4] = R[2] + 30196; goto L_800AC890; }  /* 0x800AC884 j */
L_800AC88C:;
    R[4] = R[16] + 700;  /* 0x800AC88C */
L_800AC890:;
    R[2] = lw_(R[4]);  /* 0x800AC890 */
    R[3] = lw_(R[16] + 24);  /* 0x800AC894 */
    R[2] = R[2] - R[3];  /* 0x800AC89C */
    sw_(R[29] + 16, R[2]);  /* 0x800AC8A0 */
    R[2] = lw_(R[16] + 28);  /* 0x800AC8A4 */
    R[3] = lw_(R[4] + 4);  /* 0x800AC8A8 */
    R[2] = R[2] - R[3];  /* 0x800AC8B0 */
    sw_(R[29] + 20, R[2]);  /* 0x800AC8B4 */
    R[2] = lw_(R[4] + 8);  /* 0x800AC8B8 */
    R[4] = R[29] + 16;  /* 0x800AC8BC */
    R[3] = lw_(R[16] + 32);  /* 0x800AC8C0 */
    R[5] = R[4] + R[0];  /* 0x800AC8C4 */
    R[2] = R[2] - R[3];  /* 0x800AC8C8 */
    { R[31] = 0x800AC8D4u; sw_(R[29] + 24, R[2]); psx_next = 0x800270ACu; return; }  /* 0x800AC8CC jal */
    R[2] = lw_(R[29] + 16);  /* 0x800AC8D4 */
    R[2] = R[2] << 2;  /* 0x800AC8DC */
    sh_(R[16] + 740, R[2]);  /* 0x800AC8E0 */
    R[2] = lw_(R[29] + 20);  /* 0x800AC8E4 */
    R[2] = R[2] << 2;  /* 0x800AC8EC */
    sh_(R[16] + 742, R[2]);  /* 0x800AC8F0 */
    R[2] = lw_(R[29] + 24);  /* 0x800AC8F4 */
    R[2] = R[2] << 2;  /* 0x800AC8FC */
    sh_(R[16] + 744, R[2]);  /* 0x800AC900 */
    R[2] = lh_(R[17]);  /* 0x800AC904 */
    sh_(R[16] + 752, R[2]);  /* 0x800AC90C */
    R[2] = lh_(R[17] + 2);  /* 0x800AC910 */
    sh_(R[16] + 758, R[2]);  /* 0x800AC918 */
    R[2] = lh_(R[17] + 4);  /* 0x800AC91C */
    sh_(R[16] + 764, R[2]);  /* 0x800AC924 */
    R[31] = lw_(R[29] + 40);  /* 0x800AC928 */
    R[17] = lw_(R[29] + 36);  /* 0x800AC92C */
    R[16] = lw_(R[29] + 32);  /* 0x800AC930 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800AC934 jr ra */
}

void g0_800AC8D4(void) {
    R[2] = lw_(R[29] + 16);  /* 0x800AC8D4 */
    R[2] = R[2] << 2;  /* 0x800AC8DC */
    sh_(R[16] + 740, R[2]);  /* 0x800AC8E0 */
    R[2] = lw_(R[29] + 20);  /* 0x800AC8E4 */
    R[2] = R[2] << 2;  /* 0x800AC8EC */
    sh_(R[16] + 742, R[2]);  /* 0x800AC8F0 */
    R[2] = lw_(R[29] + 24);  /* 0x800AC8F4 */
    R[2] = R[2] << 2;  /* 0x800AC8FC */
    sh_(R[16] + 744, R[2]);  /* 0x800AC900 */
    R[2] = lh_(R[17]);  /* 0x800AC904 */
    sh_(R[16] + 752, R[2]);  /* 0x800AC90C */
    R[2] = lh_(R[17] + 2);  /* 0x800AC910 */
    sh_(R[16] + 758, R[2]);  /* 0x800AC918 */
    R[2] = lh_(R[17] + 4);  /* 0x800AC91C */
    sh_(R[16] + 764, R[2]);  /* 0x800AC924 */
    R[31] = lw_(R[29] + 40);  /* 0x800AC928 */
    R[17] = lw_(R[29] + 36);  /* 0x800AC92C */
    R[16] = lw_(R[29] + 32);  /* 0x800AC930 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800AC934 jr ra */
}

void g0_800AC93C(void) {
    R[2] = 0x8011u << 16;  /* 0x800AC93C */
    R[2] = R[2] + 30196;  /* 0x800AC940 */
    sh_(R[5] + 696, R[0]);  /* 0x800AC944 */
    sh_(R[5] + 694, R[4]);  /* 0x800AC948 */
    R[7] = lw_(R[6]);  /* 0x800AC94C */
    R[8] = lw_(R[6] + 4);  /* 0x800AC950 */
    R[9] = lw_(R[6] + 8);  /* 0x800AC954 */
    R[10] = lw_(R[6] + 12);  /* 0x800AC958 */
    sw_(R[5] + 700, R[7]);  /* 0x800AC95C */
    sw_(R[5] + 704, R[8]);  /* 0x800AC960 */
    sw_(R[5] + 708, R[9]);  /* 0x800AC964 */
    sw_(R[5] + 712, R[10]);  /* 0x800AC968 */
    { uint32_t _c = (R[6] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800AC97C; } }  /* 0x800AC96C */
    { sw_(R[5] + 712, R[2]); goto L_800AC980; }  /* 0x800AC974 j */
L_800AC97C:;
    sw_(R[5] + 712, R[0]);  /* 0x800AC97C */
L_800AC980:;
    R[2] = 0x8011u << 16;  /* 0x800AC980 */
    R[2] = lw_(R[2] + 30324);  /* 0x800AC984 */
    R[3] = R[5] + 716;  /* 0x800AC988 */
    R[4] = R[2] + 48;  /* 0x800AC98C */
L_800AC990:;
    R[7] = lw_(R[2]);  /* 0x800AC990 */
    R[8] = lw_(R[2] + 4);  /* 0x800AC994 */
    R[9] = lw_(R[2] + 8);  /* 0x800AC998 */
    R[10] = lw_(R[2] + 12);  /* 0x800AC99C */
    sw_(R[3], R[7]);  /* 0x800AC9A0 */
    sw_(R[3] + 4, R[8]);  /* 0x800AC9A4 */
    sw_(R[3] + 8, R[9]);  /* 0x800AC9A8 */
    sw_(R[3] + 12, R[10]);  /* 0x800AC9AC */
    R[2] = R[2] + 16;  /* 0x800AC9B0 */
    { uint32_t _c = (R[2] != R[4]); R[3] = R[3] + 16; if (_c) { psx_bb(); goto L_800AC990; } }  /* 0x800AC9B4 */
    R[7] = lw_(R[2]);  /* 0x800AC9BC */
    R[8] = lw_(R[2] + 4);  /* 0x800AC9C0 */
    R[9] = lw_(R[2] + 8);  /* 0x800AC9C4 */
    sw_(R[3], R[7]);  /* 0x800AC9C8 */
    sw_(R[3] + 4, R[8]);  /* 0x800AC9CC */
    sw_(R[3] + 8, R[9]);  /* 0x800AC9D0 */
    sh_(R[5] + 726, R[0]);  /* 0x800AC9D4 */
    sh_(R[5] + 724, R[0]);  /* 0x800AC9D8 */
    { sh_(R[5] + 722, R[0]); psx_next = R[31]; return; }  /* 0x800AC9DC jr ra */
}

void g0_800AC9E4(void) {
    R[29] = R[29] - 32;  /* 0x800AC9E4 */
    sw_(R[29] + 24, R[16]);  /* 0x800AC9E8 */
    R[16] = R[4] + R[0];  /* 0x800AC9EC */
    R[2] = R[0] + 16384;  /* 0x800AC9F0 */
    R[5] = R[29] + 16;  /* 0x800AC9F4 */
    sw_(R[29] + 28, R[31]);  /* 0x800AC9F8 */
    sh_(R[29] + 20, R[2]);  /* 0x800AC9FC */
    sh_(R[29] + 18, R[2]);  /* 0x800ACA00 */
    { R[31] = 0x800ACA0Cu; sh_(R[29] + 16, R[2]); psx_next = 0x800AC85Cu; return; }  /* 0x800ACA04 jal */
    R[2] = lh_(R[16] + 696);  /* 0x800ACA0C */
    R[3] = R[0] + 8;  /* 0x800ACA10 */
    R[2] = R[2] + 1;  /* 0x800ACA14 */
    sh_(R[16] + 696, R[2]);  /* 0x800ACA18 */
    R[2] = R[2] << 16;  /* 0x800ACA1C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800ACA20 */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_800ACA30; } }  /* 0x800ACA24 */
    sh_(R[16] + 694, R[0]);  /* 0x800ACA2C */
L_800ACA30:;
    R[31] = lw_(R[29] + 28);  /* 0x800ACA30 */
    R[16] = lw_(R[29] + 24);  /* 0x800ACA34 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACA38 jr ra */
}

void g0_800ACA0C(void) {
    R[2] = lh_(R[16] + 696);  /* 0x800ACA0C */
    R[3] = R[0] + 8;  /* 0x800ACA10 */
    R[2] = R[2] + 1;  /* 0x800ACA14 */
    sh_(R[16] + 696, R[2]);  /* 0x800ACA18 */
    R[2] = R[2] << 16;  /* 0x800ACA1C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800ACA20 */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_800ACA30; } }  /* 0x800ACA24 */
    sh_(R[16] + 694, R[0]);  /* 0x800ACA2C */
L_800ACA30:;
    R[31] = lw_(R[29] + 28);  /* 0x800ACA30 */
    R[16] = lw_(R[29] + 24);  /* 0x800ACA34 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACA38 jr ra */
}

void g0_800ACA40(void) {
    R[29] = R[29] - 32;  /* 0x800ACA40 */
    sw_(R[29] + 24, R[16]);  /* 0x800ACA44 */
    R[16] = R[4] + R[0];  /* 0x800ACA48 */
    sw_(R[29] + 28, R[31]);  /* 0x800ACA4C */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800ACA50 */
    R[5] = R[29] + 16;  /* 0x800ACA54 */
    sh_(R[16] + 720, R[0]);  /* 0x800ACA58 */
    sh_(R[16] + 718, R[0]);  /* 0x800ACA5C */
    sh_(R[16] + 716, R[0]);  /* 0x800ACA60 */
    R[2] = R[3] << 1;  /* 0x800ACA64 */
    R[2] = R[2] + R[3];  /* 0x800ACA68 */
    R[3] = R[2] << 4;  /* 0x800ACA6C */
    R[3] = R[3] - R[2];  /* 0x800ACA70 */
    R[3] = R[3] << 2;  /* 0x800ACA74 */
    R[2] = R[0] + 4096;  /* 0x800ACA78 */
    R[2] = R[2] - R[3];  /* 0x800ACA7C */
    sh_(R[29] + 20, R[2]);  /* 0x800ACA80 */
    sh_(R[29] + 18, R[2]);  /* 0x800ACA84 */
    { R[31] = 0x800ACA90u; sh_(R[29] + 16, R[2]); psx_next = 0x800AC85Cu; return; }  /* 0x800ACA88 jal */
    R[3] = R[0] + 25;  /* 0x800ACA90 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800ACA94 */
    R[4] = lh_(R[16] + 696);  /* 0x800ACA98 */
    { uint32_t _c = (R[2] == R[3]); R[2] = R[4] + 1; if (_c) { goto L_800ACAA8; } }  /* 0x800ACA9C */
    sh_(R[16] + 696, R[2]);  /* 0x800ACAA4 */
L_800ACAA8:;
    R[2] = R[0] | 0xFFFF;  /* 0x800ACAA8 */
    sh_(R[16] + 776, R[0]);  /* 0x800ACAAC */
    sh_(R[16] + 778, R[2]);  /* 0x800ACAB0 */
    R[31] = lw_(R[29] + 28);  /* 0x800ACAB4 */
    R[16] = lw_(R[29] + 24);  /* 0x800ACAB8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACABC jr ra */
}

void g0_800ACA90(void) {
    R[3] = R[0] + 25;  /* 0x800ACA90 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800ACA94 */
    R[4] = lh_(R[16] + 696);  /* 0x800ACA98 */
    { uint32_t _c = (R[2] == R[3]); R[2] = R[4] + 1; if (_c) { goto L_800ACAA8; } }  /* 0x800ACA9C */
    sh_(R[16] + 696, R[2]);  /* 0x800ACAA4 */
L_800ACAA8:;
    R[2] = R[0] | 0xFFFF;  /* 0x800ACAA8 */
    sh_(R[16] + 776, R[0]);  /* 0x800ACAAC */
    sh_(R[16] + 778, R[2]);  /* 0x800ACAB0 */
    R[31] = lw_(R[29] + 28);  /* 0x800ACAB4 */
    R[16] = lw_(R[29] + 24);  /* 0x800ACAB8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACABC jr ra */
}

void g0_800ACAC4(void) {
    R[29] = R[29] - 32;  /* 0x800ACAC4 */
    sw_(R[29] + 24, R[16]);  /* 0x800ACAC8 */
    R[16] = R[4] + R[0];  /* 0x800ACACC */
    sw_(R[29] + 28, R[31]);  /* 0x800ACAD0 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800ACAD4 */
    R[5] = R[29] + 16;  /* 0x800ACAD8 */
    R[3] = R[2] << 1;  /* 0x800ACADC */
    R[3] = R[3] + R[2];  /* 0x800ACAE0 */
    R[3] = R[3] << 5;  /* 0x800ACAE4 */
    sh_(R[29] + 20, R[3]);  /* 0x800ACAE8 */
    sh_(R[29] + 18, R[3]);  /* 0x800ACAEC */
    { R[31] = 0x800ACAF8u; sh_(R[29] + 16, R[3]); psx_next = 0x800AC85Cu; return; }  /* 0x800ACAF0 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800ACAF8 */
    R[3] = lh_(R[16] + 696);  /* 0x800ACAFC */
    R[2] = ((int32_t)R[2] < 26);  /* 0x800ACB00 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_800ACB14; } }  /* 0x800ACB04 */
    { sh_(R[16] + 696, R[2]); goto L_800ACB18; }  /* 0x800ACB0C j */
L_800ACB14:;
    sh_(R[16] + 694, R[0]);  /* 0x800ACB14 */
L_800ACB18:;
    R[31] = lw_(R[29] + 28);  /* 0x800ACB18 */
    R[16] = lw_(R[29] + 24);  /* 0x800ACB1C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACB20 jr ra */
}

void g0_800ACAF8(void) {
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800ACAF8 */
    R[3] = lh_(R[16] + 696);  /* 0x800ACAFC */
    R[2] = ((int32_t)R[2] < 26);  /* 0x800ACB00 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_800ACB14; } }  /* 0x800ACB04 */
    { sh_(R[16] + 696, R[2]); goto L_800ACB18; }  /* 0x800ACB0C j */
L_800ACB14:;
    sh_(R[16] + 694, R[0]);  /* 0x800ACB14 */
L_800ACB18:;
    R[31] = lw_(R[29] + 28);  /* 0x800ACB18 */
    R[16] = lw_(R[29] + 24);  /* 0x800ACB1C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACB20 jr ra */
}

void g0_800ACB28(void) {
    R[29] = R[29] - 32;  /* 0x800ACB28 */
    sw_(R[29] + 24, R[16]);  /* 0x800ACB2C */
    R[16] = R[4] + R[0];  /* 0x800ACB30 */
    R[2] = R[0] + 128;  /* 0x800ACB34 */
    sw_(R[29] + 28, R[31]);  /* 0x800ACB38 */
    sh_(R[16] + 722, R[2]);  /* 0x800ACB3C */
    sh_(R[16] + 724, R[2]);  /* 0x800ACB40 */
    sh_(R[16] + 726, R[2]);  /* 0x800ACB44 */
    R[2] = R[0] + 1024;  /* 0x800ACB48 */
    R[5] = R[29] + 16;  /* 0x800ACB4C */
    sh_(R[29] + 16, R[2]);  /* 0x800ACB50 */
    sh_(R[29] + 18, R[0]);  /* 0x800ACB54 */
    { R[31] = 0x800ACB60u; sh_(R[29] + 20, R[0]); psx_next = 0x800AC85Cu; return; }  /* 0x800ACB58 jal */
    R[2] = lh_(R[16] + 696);  /* 0x800ACB60 */
    R[2] = R[2] + 1;  /* 0x800ACB68 */
    sh_(R[16] + 696, R[2]);  /* 0x800ACB6C */
    R[31] = lw_(R[29] + 28);  /* 0x800ACB70 */
    R[16] = lw_(R[29] + 24);  /* 0x800ACB74 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACB78 jr ra */
}

void g0_800ACB60(void) {
    R[2] = lh_(R[16] + 696);  /* 0x800ACB60 */
    R[2] = R[2] + 1;  /* 0x800ACB68 */
    sh_(R[16] + 696, R[2]);  /* 0x800ACB6C */
    R[31] = lw_(R[29] + 28);  /* 0x800ACB70 */
    R[16] = lw_(R[29] + 24);  /* 0x800ACB74 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACB78 jr ra */
}

void g0_800ACB80(void) {
    R[29] = R[29] - 32;  /* 0x800ACB80 */
    sw_(R[29] + 24, R[16]);  /* 0x800ACB84 */
    R[16] = R[4] + R[0];  /* 0x800ACB88 */
    sw_(R[29] + 28, R[31]);  /* 0x800ACB8C */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800ACB90 */
    R[5] = R[29] + 16;  /* 0x800ACB94 */
    R[2] = R[2] << 10;  /* 0x800ACB98 */
    sh_(R[29] + 20, R[2]);  /* 0x800ACB9C */
    sh_(R[29] + 18, R[2]);  /* 0x800ACBA0 */
    { R[31] = 0x800ACBACu; sh_(R[29] + 16, R[2]); psx_next = 0x800AC85Cu; return; }  /* 0x800ACBA4 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800ACBAC */
    R[3] = lh_(R[16] + 696);  /* 0x800ACBB0 */
    R[2] = ((int32_t)R[2] < 4);  /* 0x800ACBB4 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_800ACBC4; } }  /* 0x800ACBB8 */
    sh_(R[16] + 696, R[2]);  /* 0x800ACBC0 */
L_800ACBC4:;
    R[31] = lw_(R[29] + 28);  /* 0x800ACBC4 */
    R[16] = lw_(R[29] + 24);  /* 0x800ACBC8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACBCC jr ra */
}

void g0_800ACBAC(void) {
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800ACBAC */
    R[3] = lh_(R[16] + 696);  /* 0x800ACBB0 */
    R[2] = ((int32_t)R[2] < 4);  /* 0x800ACBB4 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] + 1; if (_c) { goto L_800ACBC4; } }  /* 0x800ACBB8 */
    sh_(R[16] + 696, R[2]);  /* 0x800ACBC0 */
L_800ACBC4:;
    R[31] = lw_(R[29] + 28);  /* 0x800ACBC4 */
    R[16] = lw_(R[29] + 24);  /* 0x800ACBC8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACBCC jr ra */
}

void g0_800ACBD4(void) {
    R[29] = R[29] - 32;  /* 0x800ACBD4 */
    R[2] = R[0] + 128;  /* 0x800ACBD8 */
    sw_(R[29] + 24, R[31]);  /* 0x800ACBDC */
    sh_(R[4] + 722, R[2]);  /* 0x800ACBE0 */
    R[2] = lh_(R[4] + 696);  /* 0x800ACBE4 */
    R[3] = R[0] + 64;  /* 0x800ACBE8 */
    sh_(R[4] + 724, R[3]);  /* 0x800ACBEC */
    sh_(R[4] + 726, R[3]);  /* 0x800ACBF0 */
    R[2] = R[2] + 1;  /* 0x800ACBF4 */
    sh_(R[4] + 696, R[2]);  /* 0x800ACBF8 */
    R[2] = R[2] << 16;  /* 0x800ACBFC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800ACC00 */
    R[2] = ((int32_t)R[2] < 9);  /* 0x800ACC04 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800ACC14; } }  /* 0x800ACC08 */
    sh_(R[4] + 694, R[0]);  /* 0x800ACC10 */
L_800ACC14:;
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 696);  /* 0x800ACC14 */
    R[2] = R[2] << 11;  /* 0x800ACC1C */
    sh_(R[29] + 16, R[2]);  /* 0x800ACC20 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 696);  /* 0x800ACC24 */
    R[2] = R[2] << 6;  /* 0x800ACC2C */
    sh_(R[29] + 18, R[2]);  /* 0x800ACC30 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 696);  /* 0x800ACC34 */
    R[5] = R[29] + 16;  /* 0x800ACC38 */
    R[2] = R[2] << 6;  /* 0x800ACC3C */
    { R[31] = 0x800ACC48u; sh_(R[29] + 20, R[2]); psx_next = 0x800AC85Cu; return; }  /* 0x800ACC40 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800ACC48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACC50 jr ra */
}

void g0_800ACC48(void) {
    R[31] = lw_(R[29] + 24);  /* 0x800ACC48 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACC50 jr ra */
}

void g0_800ACC58(void) {
    R[29] = R[29] - 32;  /* 0x800ACC58 */
    R[2] = R[0] + 64;  /* 0x800ACC5C */
    sw_(R[29] + 24, R[31]);  /* 0x800ACC60 */
    sh_(R[4] + 722, R[2]);  /* 0x800ACC64 */
    sh_(R[4] + 724, R[2]);  /* 0x800ACC68 */
    R[2] = lh_(R[4] + 696);  /* 0x800ACC6C */
    R[3] = R[0] + 128;  /* 0x800ACC70 */
    sh_(R[4] + 726, R[3]);  /* 0x800ACC74 */
    R[2] = R[2] + 1;  /* 0x800ACC78 */
    sh_(R[4] + 696, R[2]);  /* 0x800ACC7C */
    R[2] = R[2] << 16;  /* 0x800ACC80 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800ACC84 */
    R[2] = ((int32_t)R[2] < 9);  /* 0x800ACC88 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800ACC98; } }  /* 0x800ACC8C */
    sh_(R[4] + 694, R[0]);  /* 0x800ACC94 */
L_800ACC98:;
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 696);  /* 0x800ACC98 */
    R[2] = R[2] << 6;  /* 0x800ACCA0 */
    sh_(R[29] + 16, R[2]);  /* 0x800ACCA4 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 696);  /* 0x800ACCA8 */
    R[2] = R[2] << 6;  /* 0x800ACCB0 */
    sh_(R[29] + 18, R[2]);  /* 0x800ACCB4 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 696);  /* 0x800ACCB8 */
    R[5] = R[29] + 16;  /* 0x800ACCBC */
    R[2] = R[2] << 11;  /* 0x800ACCC0 */
    { R[31] = 0x800ACCCCu; sh_(R[29] + 20, R[2]); psx_next = 0x800AC85Cu; return; }  /* 0x800ACCC4 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800ACCCC */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACCD4 jr ra */
}

void g0_800ACCCC(void) {
    R[31] = lw_(R[29] + 24);  /* 0x800ACCCC */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACCD4 jr ra */
}

void g0_800ACCDC(void) {
    R[29] = R[29] - 32;  /* 0x800ACCDC */
    R[2] = R[0] + 128;  /* 0x800ACCE0 */
    sw_(R[29] + 24, R[31]);  /* 0x800ACCE4 */
    sh_(R[4] + 722, R[2]);  /* 0x800ACCE8 */
    sh_(R[4] + 724, R[2]);  /* 0x800ACCEC */
    R[2] = lh_(R[4] + 696);  /* 0x800ACCF0 */
    R[3] = R[0] + 64;  /* 0x800ACCF4 */
    sh_(R[4] + 726, R[3]);  /* 0x800ACCF8 */
    R[2] = R[2] + 1;  /* 0x800ACCFC */
    sh_(R[4] + 696, R[2]);  /* 0x800ACD00 */
    R[2] = R[2] << 16;  /* 0x800ACD04 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800ACD08 */
    R[2] = ((int32_t)R[2] < 9);  /* 0x800ACD0C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800ACD1C; } }  /* 0x800ACD10 */
    sh_(R[4] + 694, R[0]);  /* 0x800ACD18 */
L_800ACD1C:;
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 696);  /* 0x800ACD1C */
    R[2] = R[2] << 11;  /* 0x800ACD24 */
    sh_(R[29] + 16, R[2]);  /* 0x800ACD28 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 696);  /* 0x800ACD2C */
    R[2] = R[2] << 11;  /* 0x800ACD34 */
    sh_(R[29] + 18, R[2]);  /* 0x800ACD38 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 696);  /* 0x800ACD3C */
    R[5] = R[29] + 16;  /* 0x800ACD40 */
    R[2] = R[2] << 6;  /* 0x800ACD44 */
    { R[31] = 0x800ACD50u; sh_(R[29] + 20, R[2]); psx_next = 0x800AC85Cu; return; }  /* 0x800ACD48 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800ACD50 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACD58 jr ra */
}

void g0_800ACD50(void) {
    R[31] = lw_(R[29] + 24);  /* 0x800ACD50 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACD58 jr ra */
}

void g0_800ACD60(void) {
    R[29] = R[29] - 32;  /* 0x800ACD60 */
    R[5] = R[4] + R[0];  /* 0x800ACD64 */
    R[2] = R[0] + 64;  /* 0x800ACD68 */
    sw_(R[29] + 24, R[31]);  /* 0x800ACD6C */
    R[3] = lh_(R[5] + 696);  /* 0x800ACD70 */
    R[4] = R[0] + 128;  /* 0x800ACD74 */
    sh_(R[5] + 722, R[2]);  /* 0x800ACD78 */
    sh_(R[5] + 724, R[4]);  /* 0x800ACD7C */
    sh_(R[5] + 726, R[2]);  /* 0x800ACD80 */
    R[3] = R[3] + 1;  /* 0x800ACD84 */
    sh_(R[5] + 696, R[3]);  /* 0x800ACD88 */
    R[3] = R[3] << 16;  /* 0x800ACD8C */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800ACD90 */
    R[3] = ((int32_t)R[3] < 9);  /* 0x800ACD94 */
    { uint32_t _c = (R[3] != R[0]); if (_c) { goto L_800ACDA4; } }  /* 0x800ACD98 */
    sh_(R[5] + 694, R[0]);  /* 0x800ACDA0 */
L_800ACDA4:;
    R[2] = (uint32_t)(int16_t)lh_(R[5] + 696);  /* 0x800ACDA4 */
    R[2] = R[2] << 6;  /* 0x800ACDAC */
    sh_(R[29] + 16, R[2]);  /* 0x800ACDB0 */
    R[2] = (uint32_t)(int16_t)lh_(R[5] + 696);  /* 0x800ACDB4 */
    R[4] = R[5] + R[0];  /* 0x800ACDB8 */
    R[2] = R[2] << 11;  /* 0x800ACDBC */
    sh_(R[29] + 18, R[2]);  /* 0x800ACDC0 */
    R[2] = (uint32_t)(int16_t)lh_(R[5] + 696);  /* 0x800ACDC4 */
    R[5] = R[29] + 16;  /* 0x800ACDC8 */
    R[2] = R[2] << 6;  /* 0x800ACDCC */
    { R[31] = 0x800ACDD8u; sh_(R[29] + 20, R[2]); psx_next = 0x800AC85Cu; return; }  /* 0x800ACDD0 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800ACDD8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACDE0 jr ra */
}

void g0_800ACDD8(void) {
    R[31] = lw_(R[29] + 24);  /* 0x800ACDD8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACDE0 jr ra */
}

void g0_800ACDE8(void) {
    R[29] = R[29] - 32;  /* 0x800ACDE8 */
    sw_(R[29] + 24, R[16]);  /* 0x800ACDEC */
    R[16] = R[4] + R[0];  /* 0x800ACDF0 */
    sw_(R[29] + 28, R[31]);  /* 0x800ACDF4 */
    R[3] = lh_(R[16] + 696);  /* 0x800ACDF8 */
    R[2] = R[0] + 64;  /* 0x800ACDFC */
    sh_(R[16] + 722, R[2]);  /* 0x800ACE00 */
    sh_(R[16] + 724, R[0]);  /* 0x800ACE04 */
    R[4] = R[3] & 0x1;  /* 0x800ACE08 */
    R[3] = R[3] & 0x2;  /* 0x800ACE0C */
    { uint32_t _c = (R[3] != R[0]); sh_(R[16] + 726, R[0]); if (_c) { goto L_800ACE28; } }  /* 0x800ACE10 */
    R[2] = R[4] << 11;  /* 0x800ACE18 */
    sh_(R[29] + 16, R[2]);  /* 0x800ACE1C */
    { R[2] = R[4] << 9; goto L_800ACE3C; }  /* 0x800ACE20 j */
L_800ACE28:;
    R[2] = R[0] + 4;  /* 0x800ACE28 */
    R[2] = R[2] - R[4];  /* 0x800ACE2C */
    R[3] = R[2] << 11;  /* 0x800ACE30 */
    R[2] = R[2] << 9;  /* 0x800ACE34 */
    sh_(R[29] + 16, R[3]);  /* 0x800ACE38 */
L_800ACE3C:;
    sh_(R[29] + 18, R[2]);  /* 0x800ACE3C */
    sh_(R[29] + 20, R[2]);  /* 0x800ACE40 */
    R[4] = R[16] + R[0];  /* 0x800ACE44 */
    { R[31] = 0x800ACE50u; R[5] = R[29] + 16; psx_next = 0x800AC85Cu; return; }  /* 0x800ACE48 jal */
    R[2] = lh_(R[16] + 696);  /* 0x800ACE50 */
    R[2] = R[2] + 1;  /* 0x800ACE58 */
    sh_(R[16] + 696, R[2]);  /* 0x800ACE5C */
    R[31] = lw_(R[29] + 28);  /* 0x800ACE60 */
    R[16] = lw_(R[29] + 24);  /* 0x800ACE64 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACE68 jr ra */
}

void g0_800ACE50(void) {
    R[2] = lh_(R[16] + 696);  /* 0x800ACE50 */
    R[2] = R[2] + 1;  /* 0x800ACE58 */
    sh_(R[16] + 696, R[2]);  /* 0x800ACE5C */
    R[31] = lw_(R[29] + 28);  /* 0x800ACE60 */
    R[16] = lw_(R[29] + 24);  /* 0x800ACE64 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACE68 jr ra */
}

void g0_800ACE70(void) {
    R[29] = R[29] - 32;  /* 0x800ACE70 */
    sw_(R[29] + 24, R[16]);  /* 0x800ACE74 */
    R[16] = R[4] + R[0];  /* 0x800ACE78 */
    sw_(R[29] + 28, R[31]);  /* 0x800ACE7C */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800ACE80 */
    R[2] = R[0] + 64;  /* 0x800ACE84 */
    sh_(R[16] + 722, R[2]);  /* 0x800ACE88 */
    sh_(R[16] + 724, R[2]);  /* 0x800ACE8C */
    R[2] = R[0] + 128;  /* 0x800ACE90 */
    sh_(R[16] + 726, R[2]);  /* 0x800ACE94 */
    R[2] = R[3] << 6;  /* 0x800ACE98 */
    R[2] = R[2] + R[3];  /* 0x800ACE9C */
    R[2] = R[2] << 2;  /* 0x800ACEA0 */
    R[2] = R[2] + 2048;  /* 0x800ACEA4 */
    sh_(R[29] + 16, R[2]);  /* 0x800ACEA8 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800ACEAC */
    R[2] = R[3] << 6;  /* 0x800ACEB4 */
    R[2] = R[2] + R[3];  /* 0x800ACEB8 */
    R[2] = R[2] << 2;  /* 0x800ACEBC */
    R[2] = R[2] + 2048;  /* 0x800ACEC0 */
    sh_(R[29] + 18, R[2]);  /* 0x800ACEC4 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800ACEC8 */
    R[5] = R[29] + 16;  /* 0x800ACECC */
    R[2] = R[2] << 9;  /* 0x800ACED0 */
    R[2] = R[2] + 16384;  /* 0x800ACED4 */
    { R[31] = 0x800ACEE0u; sh_(R[29] + 20, R[2]); psx_next = 0x800AC85Cu; return; }  /* 0x800ACED8 jal */
    R[2] = lh_(R[16] + 696);  /* 0x800ACEE0 */
    R[3] = R[0] + 30;  /* 0x800ACEE4 */
    R[2] = R[2] + 1;  /* 0x800ACEE8 */
    sh_(R[16] + 696, R[2]);  /* 0x800ACEEC */
    R[2] = R[2] << 16;  /* 0x800ACEF0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800ACEF4 */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_800ACF04; } }  /* 0x800ACEF8 */
    sh_(R[16] + 694, R[0]);  /* 0x800ACF00 */
L_800ACF04:;
    R[31] = lw_(R[29] + 28);  /* 0x800ACF04 */
    R[16] = lw_(R[29] + 24);  /* 0x800ACF08 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACF0C jr ra */
}

void g0_800ACEE0(void) {
    R[2] = lh_(R[16] + 696);  /* 0x800ACEE0 */
    R[3] = R[0] + 30;  /* 0x800ACEE4 */
    R[2] = R[2] + 1;  /* 0x800ACEE8 */
    sh_(R[16] + 696, R[2]);  /* 0x800ACEEC */
    R[2] = R[2] << 16;  /* 0x800ACEF0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800ACEF4 */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_800ACF04; } }  /* 0x800ACEF8 */
    sh_(R[16] + 694, R[0]);  /* 0x800ACF00 */
L_800ACF04:;
    R[31] = lw_(R[29] + 28);  /* 0x800ACF04 */
    R[16] = lw_(R[29] + 24);  /* 0x800ACF08 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACF0C jr ra */
}

void g0_800ACF14(void) {
    R[29] = R[29] - 32;  /* 0x800ACF14 */
    sw_(R[29] + 24, R[16]);  /* 0x800ACF18 */
    R[16] = R[4] + R[0];  /* 0x800ACF1C */
    R[2] = R[0] + 128;  /* 0x800ACF20 */
    sw_(R[29] + 28, R[31]);  /* 0x800ACF24 */
    sh_(R[16] + 722, R[2]);  /* 0x800ACF28 */
    sh_(R[16] + 724, R[2]);  /* 0x800ACF2C */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800ACF30 */
    R[3] = R[0] + 64;  /* 0x800ACF34 */
    sh_(R[16] + 726, R[3]);  /* 0x800ACF38 */
    R[2] = R[2] << 8;  /* 0x800ACF3C */
    R[2] = R[2] + 2048;  /* 0x800ACF40 */
    sh_(R[29] + 16, R[2]);  /* 0x800ACF44 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800ACF48 */
    R[2] = R[2] << 8;  /* 0x800ACF50 */
    R[2] = R[2] + 2048;  /* 0x800ACF54 */
    sh_(R[29] + 18, R[2]);  /* 0x800ACF58 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800ACF5C */
    R[5] = R[29] + 16;  /* 0x800ACF60 */
    R[2] = R[2] << 7;  /* 0x800ACF64 */
    R[2] = R[2] + 2048;  /* 0x800ACF68 */
    { R[31] = 0x800ACF74u; sh_(R[29] + 20, R[2]); psx_next = 0x800AC85Cu; return; }  /* 0x800ACF6C jal */
    R[2] = lh_(R[16] + 696);  /* 0x800ACF74 */
    R[3] = R[0] + 30;  /* 0x800ACF78 */
    R[2] = R[2] + 1;  /* 0x800ACF7C */
    sh_(R[16] + 696, R[2]);  /* 0x800ACF80 */
    R[2] = R[2] << 16;  /* 0x800ACF84 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800ACF88 */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_800ACF98; } }  /* 0x800ACF8C */
    sh_(R[16] + 694, R[0]);  /* 0x800ACF94 */
L_800ACF98:;
    R[31] = lw_(R[29] + 28);  /* 0x800ACF98 */
    R[16] = lw_(R[29] + 24);  /* 0x800ACF9C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACFA0 jr ra */
}

void g0_800ACF74(void) {
    R[2] = lh_(R[16] + 696);  /* 0x800ACF74 */
    R[3] = R[0] + 30;  /* 0x800ACF78 */
    R[2] = R[2] + 1;  /* 0x800ACF7C */
    sh_(R[16] + 696, R[2]);  /* 0x800ACF80 */
    R[2] = R[2] << 16;  /* 0x800ACF84 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800ACF88 */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_800ACF98; } }  /* 0x800ACF8C */
    sh_(R[16] + 694, R[0]);  /* 0x800ACF94 */
L_800ACF98:;
    R[31] = lw_(R[29] + 28);  /* 0x800ACF98 */
    R[16] = lw_(R[29] + 24);  /* 0x800ACF9C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACFA0 jr ra */
}

void g0_800ACFA8(void) {
    R[29] = R[29] - 32;  /* 0x800ACFA8 */
    sw_(R[29] + 24, R[16]);  /* 0x800ACFAC */
    R[16] = R[4] + R[0];  /* 0x800ACFB0 */
    R[2] = R[0] + 128;  /* 0x800ACFB4 */
    sw_(R[29] + 28, R[31]);  /* 0x800ACFB8 */
    sh_(R[16] + 722, R[2]);  /* 0x800ACFBC */
    sh_(R[16] + 724, R[2]);  /* 0x800ACFC0 */
    sh_(R[16] + 726, R[2]);  /* 0x800ACFC4 */
    R[2] = R[0] + 4096;  /* 0x800ACFC8 */
    R[5] = R[29] + 16;  /* 0x800ACFCC */
    sh_(R[29] + 16, R[0]);  /* 0x800ACFD0 */
    sh_(R[29] + 18, R[2]);  /* 0x800ACFD4 */
    { R[31] = 0x800ACFE0u; sh_(R[29] + 20, R[0]); psx_next = 0x800AC85Cu; return; }  /* 0x800ACFD8 jal */
    R[2] = lh_(R[16] + 696);  /* 0x800ACFE0 */
    R[2] = R[2] + 1;  /* 0x800ACFE8 */
    sh_(R[16] + 696, R[2]);  /* 0x800ACFEC */
    R[31] = lw_(R[29] + 28);  /* 0x800ACFF0 */
    R[16] = lw_(R[29] + 24);  /* 0x800ACFF4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACFF8 jr ra */
}

void g0_800ACFE0(void) {
    R[2] = lh_(R[16] + 696);  /* 0x800ACFE0 */
    R[2] = R[2] + 1;  /* 0x800ACFE8 */
    sh_(R[16] + 696, R[2]);  /* 0x800ACFEC */
    R[31] = lw_(R[29] + 28);  /* 0x800ACFF0 */
    R[16] = lw_(R[29] + 24);  /* 0x800ACFF4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800ACFF8 jr ra */
}

void g0_800AD000(void) {
    R[29] = R[29] - 32;  /* 0x800AD000 */
    sw_(R[29] + 24, R[16]);  /* 0x800AD004 */
    R[16] = R[4] + R[0];  /* 0x800AD008 */
    R[2] = R[0] + 4096;  /* 0x800AD00C */
    sw_(R[29] + 28, R[31]);  /* 0x800AD010 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800AD014 */
    R[5] = R[29] + 16;  /* 0x800AD018 */
    sh_(R[16] + 720, R[0]);  /* 0x800AD01C */
    sh_(R[16] + 718, R[0]);  /* 0x800AD020 */
    sh_(R[16] + 716, R[0]);  /* 0x800AD024 */
    R[3] = R[3] << 9;  /* 0x800AD028 */
    R[2] = R[2] - R[3];  /* 0x800AD02C */
    sh_(R[29] + 20, R[2]);  /* 0x800AD030 */
    sh_(R[29] + 18, R[2]);  /* 0x800AD034 */
    { R[31] = 0x800AD040u; sh_(R[29] + 16, R[2]); psx_next = 0x800AC85Cu; return; }  /* 0x800AD038 jal */
    R[3] = R[0] + 8;  /* 0x800AD040 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800AD044 */
    R[4] = lh_(R[16] + 696);  /* 0x800AD048 */
    { uint32_t _c = (R[2] == R[3]); R[2] = R[4] + 1; if (_c) { goto L_800AD058; } }  /* 0x800AD04C */
    sh_(R[16] + 696, R[2]);  /* 0x800AD054 */
L_800AD058:;
    R[2] = R[0] | 0xFFFF;  /* 0x800AD058 */
    sh_(R[16] + 776, R[0]);  /* 0x800AD05C */
    sh_(R[16] + 778, R[2]);  /* 0x800AD060 */
    R[31] = lw_(R[29] + 28);  /* 0x800AD064 */
    R[16] = lw_(R[29] + 24);  /* 0x800AD068 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800AD06C jr ra */
}

void g0_800AD040(void) {
    R[3] = R[0] + 8;  /* 0x800AD040 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800AD044 */
    R[4] = lh_(R[16] + 696);  /* 0x800AD048 */
    { uint32_t _c = (R[2] == R[3]); R[2] = R[4] + 1; if (_c) { goto L_800AD058; } }  /* 0x800AD04C */
    sh_(R[16] + 696, R[2]);  /* 0x800AD054 */
L_800AD058:;
    R[2] = R[0] | 0xFFFF;  /* 0x800AD058 */
    sh_(R[16] + 776, R[0]);  /* 0x800AD05C */
    sh_(R[16] + 778, R[2]);  /* 0x800AD060 */
    R[31] = lw_(R[29] + 28);  /* 0x800AD064 */
    R[16] = lw_(R[29] + 24);  /* 0x800AD068 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800AD06C jr ra */
}

void g0_800AD074(void) {
    R[29] = R[29] - 32;  /* 0x800AD074 */
    sw_(R[29] + 24, R[16]);  /* 0x800AD078 */
    R[16] = R[4] + R[0];  /* 0x800AD07C */
    R[2] = R[0] + 128;  /* 0x800AD080 */
    sw_(R[29] + 28, R[31]);  /* 0x800AD084 */
    sh_(R[16] + 722, R[2]);  /* 0x800AD088 */
    sh_(R[16] + 724, R[2]);  /* 0x800AD08C */
    sh_(R[16] + 726, R[2]);  /* 0x800AD090 */
    R[2] = R[0] + 1024;  /* 0x800AD094 */
    sh_(R[29] + 16, R[2]);  /* 0x800AD098 */
    sh_(R[29] + 18, R[2]);  /* 0x800AD09C */
    R[2] = R[0] + 16384;  /* 0x800AD0A0 */
    R[5] = R[29] + 16;  /* 0x800AD0A4 */
    { R[31] = 0x800AD0B0u; sh_(R[29] + 20, R[2]); psx_next = 0x800AC85Cu; return; }  /* 0x800AD0A8 jal */
    R[2] = lh_(R[16] + 696);  /* 0x800AD0B0 */
    R[2] = R[2] + 1;  /* 0x800AD0B8 */
    sh_(R[16] + 696, R[2]);  /* 0x800AD0BC */
    R[31] = lw_(R[29] + 28);  /* 0x800AD0C0 */
    R[16] = lw_(R[29] + 24);  /* 0x800AD0C4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800AD0C8 jr ra */
}

void g0_800AD0B0(void) {
    R[2] = lh_(R[16] + 696);  /* 0x800AD0B0 */
    R[2] = R[2] + 1;  /* 0x800AD0B8 */
    sh_(R[16] + 696, R[2]);  /* 0x800AD0BC */
    R[31] = lw_(R[29] + 28);  /* 0x800AD0C0 */
    R[16] = lw_(R[29] + 24);  /* 0x800AD0C4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800AD0C8 jr ra */
}

void g0_800AD0D0(void) {
    R[29] = R[29] - 32;  /* 0x800AD0D0 */
    sw_(R[29] + 24, R[16]);  /* 0x800AD0D4 */
    R[16] = R[4] + R[0];  /* 0x800AD0D8 */
    R[2] = R[0] + 192;  /* 0x800AD0DC */
    sw_(R[29] + 28, R[31]);  /* 0x800AD0E0 */
    sh_(R[16] + 722, R[2]);  /* 0x800AD0E4 */
    sh_(R[16] + 724, R[2]);  /* 0x800AD0E8 */
    R[2] = lh_(R[16] + 696);  /* 0x800AD0EC */
    R[3] = R[0] + 255;  /* 0x800AD0F0 */
    R[2] = R[2] & 0x1;  /* 0x800AD0F4 */
    { uint32_t _c = (R[2] != R[0]); sh_(R[16] + 726, R[3]); if (_c) { goto L_800AD114; } }  /* 0x800AD0F8 */
    R[2] = R[0] + 4096;  /* 0x800AD100 */
    sh_(R[29] + 16, R[2]);  /* 0x800AD104 */
    sh_(R[29] + 18, R[2]);  /* 0x800AD108 */
    { R[2] = R[0] + 16384; goto L_800AD124; }  /* 0x800AD10C j */
L_800AD114:;
    R[2] = R[0] + 512;  /* 0x800AD114 */
    sh_(R[29] + 16, R[2]);  /* 0x800AD118 */
    sh_(R[29] + 18, R[2]);  /* 0x800AD11C */
    R[2] = R[0] + 8192;  /* 0x800AD120 */
L_800AD124:;
    sh_(R[29] + 20, R[2]);  /* 0x800AD124 */
    R[4] = R[16] + R[0];  /* 0x800AD128 */
    { R[31] = 0x800AD134u; R[5] = R[29] + 16; psx_next = 0x800AC85Cu; return; }  /* 0x800AD12C jal */
    R[2] = lh_(R[16] + 696);  /* 0x800AD134 */
    R[2] = R[2] + 1;  /* 0x800AD13C */
    sh_(R[16] + 696, R[2]);  /* 0x800AD140 */
    R[31] = lw_(R[29] + 28);  /* 0x800AD144 */
    R[16] = lw_(R[29] + 24);  /* 0x800AD148 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800AD14C jr ra */
}

void g0_800AD134(void) {
    R[2] = lh_(R[16] + 696);  /* 0x800AD134 */
    R[2] = R[2] + 1;  /* 0x800AD13C */
    sh_(R[16] + 696, R[2]);  /* 0x800AD140 */
    R[31] = lw_(R[29] + 28);  /* 0x800AD144 */
    R[16] = lw_(R[29] + 24);  /* 0x800AD148 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800AD14C jr ra */
}

void g0_800AD154(void) {
    R[29] = R[29] - 32;  /* 0x800AD154 */
    sw_(R[29] + 24, R[16]);  /* 0x800AD158 */
    R[16] = R[4] + R[0];  /* 0x800AD15C */
    sw_(R[29] + 28, R[31]);  /* 0x800AD160 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800AD164 */
    R[5] = R[29] + 16;  /* 0x800AD168 */
    sh_(R[16] + 720, R[0]);  /* 0x800AD16C */
    sh_(R[16] + 718, R[0]);  /* 0x800AD170 */
    sh_(R[16] + 716, R[0]);  /* 0x800AD174 */
    R[2] = R[3] << 2;  /* 0x800AD178 */
    R[2] = R[2] + R[3];  /* 0x800AD17C */
    R[2] = R[2] << 3;  /* 0x800AD180 */
    R[2] = R[2] + R[3];  /* 0x800AD184 */
    R[2] = R[2] << 2;  /* 0x800AD188 */
    R[2] = R[2] - R[3];  /* 0x800AD18C */
    R[3] = R[0] + 4096;  /* 0x800AD190 */
    R[3] = R[3] - R[2];  /* 0x800AD194 */
    sh_(R[29] + 20, R[3]);  /* 0x800AD198 */
    sh_(R[29] + 18, R[3]);  /* 0x800AD19C */
    { R[31] = 0x800AD1A8u; sh_(R[29] + 16, R[3]); psx_next = 0x800AC85Cu; return; }  /* 0x800AD1A0 jal */
    R[3] = R[0] + 25;  /* 0x800AD1A8 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800AD1AC */
    R[4] = lh_(R[16] + 696);  /* 0x800AD1B0 */
    { uint32_t _c = (R[2] == R[3]); R[2] = R[4] + 1; if (_c) { goto L_800AD1C0; } }  /* 0x800AD1B4 */
    sh_(R[16] + 696, R[2]);  /* 0x800AD1BC */
L_800AD1C0:;
    R[31] = lw_(R[29] + 28);  /* 0x800AD1C0 */
    R[16] = lw_(R[29] + 24);  /* 0x800AD1C4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800AD1C8 jr ra */
}

void g0_800AD1A8(void) {
    R[3] = R[0] + 25;  /* 0x800AD1A8 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 696);  /* 0x800AD1AC */
    R[4] = lh_(R[16] + 696);  /* 0x800AD1B0 */
    { uint32_t _c = (R[2] == R[3]); R[2] = R[4] + 1; if (_c) { goto L_800AD1C0; } }  /* 0x800AD1B4 */
    sh_(R[16] + 696, R[2]);  /* 0x800AD1BC */
L_800AD1C0:;
    R[31] = lw_(R[29] + 28);  /* 0x800AD1C0 */
    R[16] = lw_(R[29] + 24);  /* 0x800AD1C4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800AD1C8 jr ra */
}

void g0_800AD1D0(void) {
    R[29] = R[29] - 32;  /* 0x800AD1D0 */
    R[5] = R[29] + 16;  /* 0x800AD1D4 */
    sw_(R[29] + 24, R[31]);  /* 0x800AD1D8 */
    sh_(R[4] + 720, R[0]);  /* 0x800AD1DC */
    sh_(R[4] + 718, R[0]);  /* 0x800AD1E0 */
    sh_(R[4] + 716, R[0]);  /* 0x800AD1E4 */
    sh_(R[29] + 20, R[0]);  /* 0x800AD1E8 */
    sh_(R[29] + 18, R[0]);  /* 0x800AD1EC */
    { R[31] = 0x800AD1F8u; sh_(R[29] + 16, R[0]); psx_next = 0x800AC85Cu; return; }  /* 0x800AD1F0 jal */
    R[31] = lw_(R[29] + 24);  /* 0x800AD1F8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800AD200 jr ra */
}

void g0_800AD1F8(void) {
    R[31] = lw_(R[29] + 24);  /* 0x800AD1F8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800AD200 jr ra */
}

void g0_800AD208(void) {
    R[29] = R[29] - 32;  /* 0x800AD208 */
    sw_(R[29] + 24, R[16]);  /* 0x800AD20C */
    R[16] = R[4] + R[0];  /* 0x800AD210 */
    R[2] = R[0] + 16384;  /* 0x800AD214 */
    R[5] = R[29] + 16;  /* 0x800AD218 */
    sw_(R[29] + 28, R[31]);  /* 0x800AD21C */
    sh_(R[29] + 20, R[2]);  /* 0x800AD220 */
    sh_(R[29] + 18, R[2]);  /* 0x800AD224 */
    { R[31] = 0x800AD230u; sh_(R[29] + 16, R[2]); psx_next = 0x800AC85Cu; return; }  /* 0x800AD228 jal */
    R[2] = lh_(R[16] + 696);  /* 0x800AD230 */
    R[3] = R[0] + 2;  /* 0x800AD234 */
    R[2] = R[2] + 1;  /* 0x800AD238 */
    sh_(R[16] + 696, R[2]);  /* 0x800AD23C */
    R[2] = R[2] << 16;  /* 0x800AD240 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800AD244 */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_800AD254; } }  /* 0x800AD248 */
    sh_(R[16] + 694, R[0]);  /* 0x800AD250 */
L_800AD254:;
    R[31] = lw_(R[29] + 28);  /* 0x800AD254 */
    R[16] = lw_(R[29] + 24);  /* 0x800AD258 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800AD25C jr ra */
}

void g0_800AD230(void) {
    R[2] = lh_(R[16] + 696);  /* 0x800AD230 */
    R[3] = R[0] + 2;  /* 0x800AD234 */
    R[2] = R[2] + 1;  /* 0x800AD238 */
    sh_(R[16] + 696, R[2]);  /* 0x800AD23C */
    R[2] = R[2] << 16;  /* 0x800AD240 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800AD244 */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_800AD254; } }  /* 0x800AD248 */
    sh_(R[16] + 694, R[0]);  /* 0x800AD250 */
L_800AD254:;
    R[31] = lw_(R[29] + 28);  /* 0x800AD254 */
    R[16] = lw_(R[29] + 24);  /* 0x800AD258 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800AD25C jr ra */
}

void g0_800AD264(void) {
    R[29] = R[29] - 24;  /* 0x800AD264 */
    sw_(R[29] + 16, R[31]);  /* 0x800AD268 */
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 694);  /* 0x800AD26C */
    { uint32_t _c = (R[3] == R[0]); R[2] = 0x800Fu << 16; if (_c) { goto L_800AD298; } }  /* 0x800AD274 */
    R[2] = R[2] - 12748;  /* 0x800AD27C */
    R[3] = R[3] << 2;  /* 0x800AD280 */
    R[3] = R[3] + R[2];  /* 0x800AD284 */
    R[2] = lw_(R[3]);  /* 0x800AD288 */
    { uint32_t _t = R[2]; R[31] = 0x800AD298u; psx_next = _t; return; }  /* 0x800AD290 jalr */
L_800AD298:;
    R[31] = lw_(R[29] + 16);  /* 0x800AD298 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800AD2A0 jr ra */
}

void g0_800AD298(void) {
    R[31] = lw_(R[29] + 16);  /* 0x800AD298 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800AD2A0 jr ra */
}

void g0_800AD2A8(void) {
    R[29] = R[29] - 32;  /* 0x800AD2A8 */
    sw_(R[29] + 28, R[31]);  /* 0x800AD2AC */
    sw_(R[29] + 24, R[18]);  /* 0x800AD2B0 */
    sw_(R[29] + 20, R[17]);  /* 0x800AD2B4 */
    sw_(R[29] + 16, R[16]);  /* 0x800AD2B8 */
    R[18] = lw_(R[4] + 16);  /* 0x800AD2BC */
    { uint32_t _c = (R[18] == R[0]); R[17] = R[0] + R[0]; if (_c) { goto L_800AD2E8; } }  /* 0x800AD2C4 */
    R[16] = R[4] + R[0];  /* 0x800AD2CC */
L_800AD2D0:;
    R[4] = lw_(R[16] + 20);  /* 0x800AD2D0 */
    R[16] = R[16] + 4;  /* 0x800AD2D4 */
    { R[31] = 0x800AD2E0u; R[17] = R[17] + 1; psx_next = 0x800AD264u; return; }  /* 0x800AD2D8 jal */
    { uint32_t _c = (R[17] != R[18]); if (_c) { psx_bb(); goto L_800AD2D0; } }  /* 0x800AD2E0 */
L_800AD2E8:;
    R[31] = lw_(R[29] + 28);  /* 0x800AD2E8 */
    R[18] = lw_(R[29] + 24);  /* 0x800AD2EC */
    R[17] = lw_(R[29] + 20);  /* 0x800AD2F0 */
    R[16] = lw_(R[29] + 16);  /* 0x800AD2F4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800AD2F8 jr ra */
}

void g0_800AD2D0(void) {
L_800AD2D0:;
    R[4] = lw_(R[16] + 20);  /* 0x800AD2D0 */
    R[16] = R[16] + 4;  /* 0x800AD2D4 */
    { R[31] = 0x800AD2E0u; R[17] = R[17] + 1; psx_next = 0x800AD264u; return; }  /* 0x800AD2D8 jal */
    { uint32_t _c = (R[17] != R[18]); if (_c) { psx_bb(); goto L_800AD2D0; } }  /* 0x800AD2E0 */
    R[31] = lw_(R[29] + 28);  /* 0x800AD2E8 */
    R[18] = lw_(R[29] + 24);  /* 0x800AD2EC */
    R[17] = lw_(R[29] + 20);  /* 0x800AD2F0 */
    R[16] = lw_(R[29] + 16);  /* 0x800AD2F4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800AD2F8 jr ra */
}

void g0_800AD2E0(void) {
    { uint32_t _c = (R[17] != R[18]); if (_c) { psx_next = 0x800AD2D0u; return; } }  /* 0x800AD2E0 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x800AD2E8 */
    R[18] = lw_(R[29] + 24);  /* 0x800AD2EC */
    R[17] = lw_(R[29] + 20);  /* 0x800AD2F0 */
    R[16] = lw_(R[29] + 16);  /* 0x800AD2F4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x800AD2F8 jr ra */
}

void g0_800AD300(void) {
    R[2] = 0x8013u << 16;  /* 0x800AD300 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 9472);  /* 0x800AD304 */
    psx_next = 0x800AD308u; return;  /* fallthrough */
}

void g0_800AD308(void) {
    R[29] = R[29] - 104;  /* 0x800AD308 */
    sw_(R[29] + 100, R[31]);  /* 0x800AD30C */
    sw_(R[29] + 96, R[30]);  /* 0x800AD310 */
    sw_(R[29] + 92, R[23]);  /* 0x800AD314 */
    sw_(R[29] + 88, R[22]);  /* 0x800AD318 */
    sw_(R[29] + 84, R[21]);  /* 0x800AD31C */
    sw_(R[29] + 80, R[20]);  /* 0x800AD320 */
    sw_(R[29] + 76, R[19]);  /* 0x800AD324 */
    sw_(R[29] + 72, R[18]);  /* 0x800AD328 */
    sw_(R[29] + 68, R[17]);  /* 0x800AD32C */
    { uint32_t _c = (R[2] == R[0]); sw_(R[29] + 64, R[16]); if (_c) { goto L_800ADB84; } }  /* 0x800AD330 */
    R[3] = 0x8006u << 16;  /* 0x800AD338 */
    R[3] = R[3] + 15308;  /* 0x800AD33C */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 726);  /* 0x800AD340 */
    R[2] = R[2] + R[3];  /* 0x800AD348 */
    R[3] = (uint32_t)(int8_t)lb_(R[2] + 88);  /* 0x800AD34C */
    R[2] = R[0] + 53;  /* 0x800AD350 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8011u << 16; if (_c) { goto L_800ADB84; } }  /* 0x800AD354 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 29992);  /* 0x800AD35C */
    R[2] = R[0] + 2;  /* 0x800AD360 */
    { uint32_t _c = (R[3] == R[2]); R[4] = 0x801Eu << 16; if (_c) { goto L_800ADB84; } }  /* 0x800AD364 */
    R[4] = R[4] | 0xC000;  /* 0x800AD36C */
    R[2] = 0x8011u << 16;  /* 0x800AD370 */
    R[3] = 0x8013u << 16;  /* 0x800AD374 */
    R[2] = lw_(R[2] + 29968);  /* 0x800AD378 */
    R[3] = lw_(R[3] + 4048);  /* 0x800AD37C */
    R[2] = R[2] + 96;  /* 0x800AD380 */
    sw_(R[29] + 48, R[2]);  /* 0x800AD384 */
    R[2] = R[3] & 0x3;  /* 0x800AD388 */
    { uint32_t _c = (R[2] == R[0]); R[21] = 0x1F80u << 16; if (_c) { goto L_800AD3EC; } }  /* 0x800AD38C */
    R[2] = R[3] + 768;  /* 0x800AD394 */
L_800AD398:;
    R[14] = lwl_(R[3] + 3, R[14]);  /* 0x800AD398 */
    R[14] = lwr_(R[3], R[14]);  /* 0x800AD39C */
    R[22] = lwl_(R[3] + 7, R[22]);  /* 0x800AD3A0 */
    R[22] = lwr_(R[3] + 4, R[22]);  /* 0x800AD3A4 */
    R[24] = lwl_(R[3] + 11, R[24]);  /* 0x800AD3A8 */
    R[24] = lwr_(R[3] + 8, R[24]);  /* 0x800AD3AC */
    R[25] = lwl_(R[3] + 15, R[25]);  /* 0x800AD3B0 */
    R[25] = lwr_(R[3] + 12, R[25]);  /* 0x800AD3B4 */
    swl_(R[4] + 3, R[14]);  /* 0x800AD3B8 */
    swr_(R[4], R[14]);  /* 0x800AD3BC */
    swl_(R[4] + 7, R[22]);  /* 0x800AD3C0 */
    swr_(R[4] + 4, R[22]);  /* 0x800AD3C4 */
    swl_(R[4] + 11, R[24]);  /* 0x800AD3C8 */
    swr_(R[4] + 8, R[24]);  /* 0x800AD3CC */
    swl_(R[4] + 15, R[25]);  /* 0x800AD3D0 */
    swr_(R[4] + 12, R[25]);  /* 0x800AD3D4 */
    R[3] = R[3] + 16;  /* 0x800AD3D8 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[4] + 16; if (_c) { psx_bb(); goto L_800AD398; } }  /* 0x800AD3DC */
    { R[3] = 0x801Eu << 16; goto L_800AD420; }  /* 0x800AD3E4 j */
L_800AD3EC:;
    R[2] = R[3] + 768;  /* 0x800AD3EC */
L_800AD3F0:;
    R[14] = lw_(R[3]);  /* 0x800AD3F0 */
    R[22] = lw_(R[3] + 4);  /* 0x800AD3F4 */
    R[24] = lw_(R[3] + 8);  /* 0x800AD3F8 */
    R[25] = lw_(R[3] + 12);  /* 0x800AD3FC */
    sw_(R[4], R[14]);  /* 0x800AD400 */
    sw_(R[4] + 4, R[22]);  /* 0x800AD404 */
    sw_(R[4] + 8, R[24]);  /* 0x800AD408 */
    sw_(R[4] + 12, R[25]);  /* 0x800AD40C */
    R[3] = R[3] + 16;  /* 0x800AD410 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[4] + 16; if (_c) { psx_bb(); goto L_800AD3F0; } }  /* 0x800AD414 */
    R[3] = 0x801Eu << 16;  /* 0x800AD41C */
L_800AD420:;
    R[3] = R[3] | 0xC000;  /* 0x800AD420 */
    R[20] = R[0] + R[0];  /* 0x800AD424 */
    R[4] = 0x8011u << 16;  /* 0x800AD428 */
    R[4] = R[4] + 29992;  /* 0x800AD42C */
    R[2] = lw_(R[3]);  /* 0x800AD430 */
    R[5] = lw_(R[4] + 204);  /* 0x800AD434 */
    R[16] = R[2] + R[3];  /* 0x800AD438 */
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 20);  /* 0x800AD43C */
    R[9] = lw_(R[16]);  /* 0x800AD440 */
    R[2] = R[3] << 1;  /* 0x800AD444 */
    R[2] = R[2] + R[3];  /* 0x800AD448 */
    R[2] = R[2] << 3;  /* 0x800AD44C */
    R[2] = R[2] + R[3];  /* 0x800AD450 */
    R[2] = R[2] << 5;  /* 0x800AD454 */
    R[30] = R[5] + R[2];  /* 0x800AD458 */
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 22);  /* 0x800AD45C */
    R[5] = lw_(R[4] + 208);  /* 0x800AD460 */
    R[2] = R[3] << 1;  /* 0x800AD464 */
    R[2] = R[2] + R[3];  /* 0x800AD468 */
    R[2] = R[2] << 3;  /* 0x800AD46C */
    R[2] = R[2] + R[3];  /* 0x800AD470 */
    R[2] = R[2] << 5;  /* 0x800AD474 */
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 24);  /* 0x800AD478 */
    R[5] = R[5] + R[2];  /* 0x800AD47C */
    sw_(R[29] + 52, R[5]);  /* 0x800AD480 */
    R[2] = R[3] << 1;  /* 0x800AD484 */
    R[2] = R[2] + R[3];  /* 0x800AD488 */
    R[2] = R[2] << 3;  /* 0x800AD48C */
    R[2] = R[2] + R[3];  /* 0x800AD490 */
    R[3] = lw_(R[4] + 212);  /* 0x800AD494 */
    R[2] = R[2] << 5;  /* 0x800AD498 */
    { uint32_t _c = (R[9] == R[0]); R[23] = R[3] + R[2]; if (_c) { goto L_800AD574; } }  /* 0x800AD49C */
    R[15] = R[0] - R[5];  /* 0x800AD4A4 */
    R[7] = R[16] + 42;  /* 0x800AD4A8 */
    R[17] = R[0] + 24;  /* 0x800AD4AC */
    R[13] = R[0] + 8;  /* 0x800AD4B0 */
    R[12] = R[0] + 12;  /* 0x800AD4B4 */
    R[11] = R[0] + 4;  /* 0x800AD4B8 */
    R[10] = R[21] + R[0];  /* 0x800AD4BC */
    R[8] = R[21] + R[0];  /* 0x800AD4C0 */
L_800AD4C4:;
    R[4] = R[21] + R[17];  /* 0x800AD4C4 */
    R[17] = R[17] + 36;  /* 0x800AD4C8 */
    R[6] = R[21] + R[13];  /* 0x800AD4CC */
    R[13] = R[13] + 12;  /* 0x800AD4D0 */
    R[3] = R[21] + R[12];  /* 0x800AD4D4 */
    R[2] = (uint32_t)(int16_t)lh_(R[7] + -26);  /* 0x800AD4D8 */
    R[12] = R[12] + 36;  /* 0x800AD4DC */
    sw_(R[8] + 4, R[15]);  /* 0x800AD4E0 */
    R[2] = R[2] << 12;  /* 0x800AD4E4 */
    R[2] = R[30] + R[2];  /* 0x800AD4E8 */
    sw_(R[8], R[2]);  /* 0x800AD4EC */
    R[2] = (uint32_t)(int16_t)lh_(R[7] + -24);  /* 0x800AD4F0 */
    R[5] = R[21] + R[11];  /* 0x800AD4F4 */
    R[2] = R[2] << 12;  /* 0x800AD4F8 */
    R[2] = R[23] - R[2];  /* 0x800AD4FC */
    sw_(R[8] + 8, R[2]);  /* 0x800AD500 */
    R[2] = (uint32_t)(int16_t)lh_(R[7] + -14);  /* 0x800AD504 */
    R[11] = R[11] + 12;  /* 0x800AD508 */
    sw_(R[3] + 4, R[15]);  /* 0x800AD50C */
    R[2] = R[2] << 12;  /* 0x800AD510 */
    R[2] = R[30] + R[2];  /* 0x800AD514 */
    sw_(R[3], R[2]);  /* 0x800AD518 */
    R[2] = (uint32_t)(int16_t)lh_(R[7] + -12);  /* 0x800AD51C */
    R[20] = R[20] + 3;  /* 0x800AD520 */
    R[2] = R[2] << 12;  /* 0x800AD524 */
    R[2] = R[23] - R[2];  /* 0x800AD528 */
    sw_(R[3] + 8, R[2]);  /* 0x800AD52C */
    R[2] = (uint32_t)(int16_t)lh_(R[7] + -2);  /* 0x800AD530 */
    R[9] = R[9] - 1;  /* 0x800AD534 */
    sw_(R[4] + 4, R[15]);  /* 0x800AD538 */
    R[2] = R[2] << 12;  /* 0x800AD53C */
    R[2] = R[30] + R[2];  /* 0x800AD540 */
    sw_(R[4], R[2]);  /* 0x800AD544 */
    R[2] = (uint32_t)(int16_t)lh_(R[7]);  /* 0x800AD548 */
    R[7] = R[7] + 44;  /* 0x800AD54C */
    R[2] = R[2] << 12;  /* 0x800AD550 */
    R[2] = R[23] - R[2];  /* 0x800AD554 */
    sw_(R[4] + 8, R[2]);  /* 0x800AD558 */
    sw_(R[10] + 408, R[8]);  /* 0x800AD55C */
    R[10] = R[10] + 12;  /* 0x800AD560 */
    R[8] = R[8] + 36;  /* 0x800AD564 */
    sw_(R[5] + 408, R[3]);  /* 0x800AD568 */
    { uint32_t _c = (R[9] != R[0]); sw_(R[6] + 408, R[4]); if (_c) { psx_bb(); goto L_800AD4C4; } }  /* 0x800AD56C */
L_800AD574:;
    R[9] = 0x5555u << 16;  /* 0x800AD574 */
    R[9] = R[9] | 0x5556;  /* 0x800AD578 */
    R[8] = R[20] << 1;  /* 0x800AD57C */
    R[8] = R[8] + R[20];  /* 0x800AD580 */
    R[8] = R[8] << 2;  /* 0x800AD584 */
    R[3] = 0x8011u << 16;  /* 0x800AD588 */
    R[3] = R[3] + 29992;  /* 0x800AD58C */
    R[5] = R[21] + R[8];  /* 0x800AD590 */
    R[4] = 0x8011u << 16;  /* 0x800AD594 */
    R[4] = R[4] + 30268;  /* 0x800AD598 */
    R[2] = lw_(R[3] + 140);  /* 0x800AD59C */
    R[6] = R[0] + R[0];  /* 0x800AD5A0 */
    sw_(R[5], R[2]);  /* 0x800AD5A4 */
    R[2] = lw_(R[3] + 144);  /* 0x800AD5A8 */
    R[7] = R[20] + 1;  /* 0x800AD5AC */
    R[2] = R[0] - R[2];  /* 0x800AD5B0 */
    sw_(R[5] + 4, R[2]);  /* 0x800AD5B4 */
    R[2] = lw_(R[3] + 148);  /* 0x800AD5B8 */
    R[3] = R[20] + 2;  /* 0x800AD5BC */
    sw_(R[5] + 8, R[2]);  /* 0x800AD5C0 */
    R[2] = R[7] << 1;  /* 0x800AD5C4 */
    R[2] = R[2] + R[7];  /* 0x800AD5C8 */
    R[2] = R[2] << 2;  /* 0x800AD5CC */
    R[2] = R[21] + R[2];  /* 0x800AD5D0 */
    sw_(R[2], R[0]);  /* 0x800AD5D4 */
    sw_(R[2] + 4, R[0]);  /* 0x800AD5D8 */
    sw_(R[2] + 8, R[0]);  /* 0x800AD5DC */
    R[2] = R[3] << 1;  /* 0x800AD5E0 */
    R[2] = R[2] + R[3];  /* 0x800AD5E4 */
    R[2] = R[2] << 2;  /* 0x800AD5E8 */
    R[2] = R[21] + R[2];  /* 0x800AD5EC */
    sw_(R[2], R[0]);  /* 0x800AD5F0 */
    sw_(R[2] + 4, R[0]);  /* 0x800AD5F4 */
    sw_(R[2] + 8, R[0]);  /* 0x800AD5F8 */
    R[2] = R[20] << 2;  /* 0x800AD5FC */
    R[2] = R[21] + R[2];  /* 0x800AD600 */
    R[7] = R[7] << 2;  /* 0x800AD604 */
    R[7] = R[21] + R[7];  /* 0x800AD608 */
    sw_(R[2] + 408, R[5]);  /* 0x800AD60C */
    R[2] = R[8] + 12;  /* 0x800AD610 */
    R[2] = R[21] + R[2];  /* 0x800AD614 */
    R[5] = R[20] + 3;  /* 0x800AD618 */
    { int64_t _p = (int64_t)(int32_t)R[5] * (int32_t)R[9]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800AD61C */
    R[3] = R[3] << 2;  /* 0x800AD620 */
    R[3] = R[21] + R[3];  /* 0x800AD624 */
    R[8] = R[8] + 24;  /* 0x800AD628 */
    R[8] = R[21] + R[8];  /* 0x800AD62C */
    sw_(R[7] + 408, R[2]);  /* 0x800AD630 */
    R[2] = R[21] + 408;  /* 0x800AD634 */
    sw_(R[3] + 408, R[8]);  /* 0x800AD638 */
    sw_(R[4] + 16, R[2]);  /* 0x800AD63C */
    R[2] = R[21] + 544;  /* 0x800AD640 */
    R[5] = (uint32_t)((int32_t)R[5] >> 31);  /* 0x800AD644 */
    sw_(R[4] + 20, R[2]);  /* 0x800AD648 */
    R[14] = HI;  /* 0x800AD64C */
    { R[31] = 0x800AD658u; R[5] = R[14] - R[5]; psx_next = 0x80025598u; return; }  /* 0x800AD650 jal */
    R[9] = lw_(R[16]);  /* 0x800AD658 */
    { uint32_t _c = (R[9] == R[0]); R[20] = R[0] + R[0]; if (_c) { goto L_800AD6CC; } }  /* 0x800AD660 */
    R[5] = R[16] + 42;  /* 0x800AD668 */
    R[8] = R[0] + 16;  /* 0x800AD66C */
    R[7] = R[0] + 8;  /* 0x800AD670 */
    R[6] = R[21] + R[0];  /* 0x800AD674 */
L_800AD678:;
    R[4] = R[21] + R[8];  /* 0x800AD678 */
    R[2] = lh_(R[6] + 544);  /* 0x800AD67C */
    R[8] = R[8] + 24;  /* 0x800AD680 */
    sh_(R[5] + -26, R[2]);  /* 0x800AD684 */
    R[2] = lh_(R[6] + 546);  /* 0x800AD688 */
    R[3] = R[21] + R[7];  /* 0x800AD68C */
    sh_(R[5] + -24, R[2]);  /* 0x800AD690 */
    R[2] = lh_(R[3] + 544);  /* 0x800AD694 */
    R[7] = R[7] + 24;  /* 0x800AD698 */
    sh_(R[5] + -14, R[2]);  /* 0x800AD69C */
    R[2] = lh_(R[3] + 546);  /* 0x800AD6A0 */
    R[20] = R[20] + 3;  /* 0x800AD6A4 */
    sh_(R[5] + -12, R[2]);  /* 0x800AD6A8 */
    R[2] = lh_(R[4] + 544);  /* 0x800AD6AC */
    R[9] = R[9] - 1;  /* 0x800AD6B0 */
    sh_(R[5] + -2, R[2]);  /* 0x800AD6B4 */
    R[2] = lh_(R[4] + 546);  /* 0x800AD6B8 */
    R[6] = R[6] + 24;  /* 0x800AD6BC */
    sh_(R[5], R[2]);  /* 0x800AD6C0 */
    { uint32_t _c = (R[9] != R[0]); R[5] = R[5] + 44; if (_c) { psx_bb(); goto L_800AD678; } }  /* 0x800AD6C4 */
L_800AD6CC:;
    R[2] = 0x1u << 16;  /* 0x800AD6CC */
    R[2] = R[2] | 0x8000;  /* 0x800AD6D0 */
    R[4] = 0x801Eu << 16;  /* 0x800AD6D4 */
    R[4] = R[4] | 0xC000;  /* 0x800AD6D8 */
    R[5] = R[0] + R[0];  /* 0x800AD6DC */
    R[16] = 0x800Fu << 16;  /* 0x800AD6E0 */
    R[16] = R[16] + 25528;  /* 0x800AD6E4 */
    R[16] = R[16] + R[2];  /* 0x800AD6E8 */
    R[6] = R[5] + R[0];  /* 0x800AD6EC */
    R[2] = lw_(R[16] + 20496);  /* 0x800AD6F0 */
    R[22] = lw_(R[29] + 48);  /* 0x800AD6F4 */
    R[7] = R[5] + R[0];  /* 0x800AD6F8 */
    sw_(R[29] + 24, R[0]);  /* 0x800AD6FC */
    sw_(R[29] + 20, R[22]);  /* 0x800AD700 */
    { R[31] = 0x800AD70Cu; sw_(R[29] + 16, R[2]); psx_next = 0x80022A58u; return; }  /* 0x800AD704 jal */
    R[3] = 0x8013u << 16;  /* 0x800AD70C */
    R[8] = R[3] - 29656;  /* 0x800AD710 */
    R[5] = lw_(R[8] + 36);  /* 0x800AD714 */
    R[17] = R[2] + R[0];  /* 0x800AD718 */
    { uint32_t _c = ((int32_t)R[5] >= 0); sw_(R[16] + 20496, R[17]); if (_c) { goto L_800AD728; } }  /* 0x800AD71C */
    R[5] = R[5] + 7;  /* 0x800AD724 */
L_800AD728:;
    R[6] = 0xFFu << 16;  /* 0x800AD728 */
    R[6] = R[6] | 0xFFFF;  /* 0x800AD72C */
    R[2] = R[20] << 3;  /* 0x800AD730 */
    R[2] = R[21] + R[2];  /* 0x800AD734 */
    R[11] = (uint32_t)(int16_t)lh_(R[2] + 544);  /* 0x800AD738 */
    R[12] = (uint32_t)(int16_t)lh_(R[2] + 546);  /* 0x800AD73C */
    R[2] = 0x8011u << 16;  /* 0x800AD740 */
    R[7] = lw_(R[2] + 29968);  /* 0x800AD744 */
    R[2] = R[0] + 9;  /* 0x800AD748 */
    sb_(R[17] + 3, R[2]);  /* 0x800AD74C */
    R[2] = R[0] + 46;  /* 0x800AD750 */
    sb_(R[17] + 7, R[2]);  /* 0x800AD754 */
    R[2] = R[0] + 128;  /* 0x800AD758 */
    R[4] = R[0] + 168;  /* 0x800AD75C */
    sb_(R[17] + 4, R[2]);  /* 0x800AD760 */
    sb_(R[17] + 5, R[2]);  /* 0x800AD764 */
    sb_(R[17] + 6, R[2]);  /* 0x800AD768 */
    R[2] = R[0] + 224;  /* 0x800AD76C */
    R[3] = R[0] + 183;  /* 0x800AD770 */
    sb_(R[17] + 13, R[2]);  /* 0x800AD774 */
    sb_(R[17] + 21, R[2]);  /* 0x800AD778 */
    R[2] = R[0] + 239;  /* 0x800AD77C */
    sb_(R[17] + 29, R[2]);  /* 0x800AD780 */
    sb_(R[17] + 37, R[2]);  /* 0x800AD784 */
    R[2] = (uint32_t)((int32_t)R[5] >> 3);  /* 0x800AD788 */
    sb_(R[17] + 12, R[4]);  /* 0x800AD78C */
    sb_(R[17] + 28, R[4]);  /* 0x800AD790 */
    R[4] = R[0] + 6;  /* 0x800AD794 */
    R[4] = R[4] - R[2];  /* 0x800AD798 */
    sb_(R[17] + 20, R[3]);  /* 0x800AD79C */
    sb_(R[17] + 36, R[3]);  /* 0x800AD7A0 */
    R[5] = R[11] - R[4];  /* 0x800AD7A4 */
    R[2] = R[12] - R[4];  /* 0x800AD7A8 */
    R[3] = R[4] + R[11];  /* 0x800AD7AC */
    sh_(R[17] + 10, R[2]);  /* 0x800AD7B0 */
    sh_(R[17] + 18, R[2]);  /* 0x800AD7B4 */
    R[2] = R[4] + R[12];  /* 0x800AD7B8 */
    sh_(R[17] + 26, R[2]);  /* 0x800AD7BC */
    sh_(R[17] + 34, R[2]);  /* 0x800AD7C0 */
    R[2] = 0x8005u << 16;  /* 0x800AD7C4 */
    sh_(R[17] + 8, R[5]);  /* 0x800AD7C8 */
    sh_(R[17] + 16, R[3]);  /* 0x800AD7CC */
    sh_(R[17] + 24, R[5]);  /* 0x800AD7D0 */
    sh_(R[17] + 32, R[3]);  /* 0x800AD7D4 */
    R[3] = lh_(R[2] + -860);  /* 0x800AD7D8 */
    R[2] = R[0] + 57;  /* 0x800AD7DC */
    R[5] = 0xFF00u << 16;  /* 0x800AD7E0 */
    R[24] = R[7] + 92;  /* 0x800AD7E4 */
    sh_(R[17] + 22, R[2]);  /* 0x800AD7E8 */
    sh_(R[17] + 14, R[3]);  /* 0x800AD7EC */
    R[3] = lw_(R[17]);  /* 0x800AD7F0 */
    R[2] = lw_(R[7] + 92);  /* 0x800AD7F4 */
    R[3] = R[3] & R[5];  /* 0x800AD7F8 */
    R[2] = R[2] & R[6];  /* 0x800AD7FC */
    R[3] = R[3] | R[2];  /* 0x800AD800 */
    sw_(R[17], R[3]);  /* 0x800AD804 */
    R[2] = lw_(R[7] + 92);  /* 0x800AD808 */
    R[6] = R[17] & R[6];  /* 0x800AD80C */
    sw_(R[29] + 48, R[24]);  /* 0x800AD810 */
    R[2] = R[2] & R[5];  /* 0x800AD814 */
    R[2] = R[2] | R[6];  /* 0x800AD818 */
    sw_(R[7] + 92, R[2]);  /* 0x800AD81C */
    R[2] = 0x8013u << 16;  /* 0x800AD820 */
    R[2] = lw_(R[2] + 4152);  /* 0x800AD824 */
    R[19] = lw_(R[2] + 536);  /* 0x800AD82C */
    R[17] = R[17] + 40;  /* 0x800AD830 */
    { uint32_t _c = (R[19] == R[0]); sh_(R[29] + 56, R[4]); if (_c) { goto L_800ADB6C; } }  /* 0x800AD834 */
    R[2] = (uint32_t)(int16_t)lh_(R[8] + 40);  /* 0x800AD83C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AD870; } }  /* 0x800AD844 */
    R[2] = lw_(R[8] + 36);  /* 0x800AD84C */
    R[2] = R[2] - 4;  /* 0x800AD854 */
    sw_(R[8] + 36, R[2]);  /* 0x800AD858 */
    R[2] = ((int32_t)R[2] < -31);  /* 0x800AD85C */
    { uint32_t _c = (R[2] == R[0]); R[20] = R[0] + R[0]; if (_c) { goto L_800AD894; } }  /* 0x800AD860 */
    { sh_(R[8] + 40, R[0]); goto L_800AD894; }  /* 0x800AD868 j */
L_800AD870:;
    R[2] = lw_(R[8] + 36);  /* 0x800AD870 */
    R[2] = R[2] + 4;  /* 0x800AD878 */
    sw_(R[8] + 36, R[2]);  /* 0x800AD87C */
    R[2] = ((int32_t)R[2] < 32);  /* 0x800AD880 */
    { uint32_t _c = (R[2] != R[0]); R[20] = R[0] + R[0]; if (_c) { goto L_800AD894; } }  /* 0x800AD884 */
    R[2] = R[0] + 1;  /* 0x800AD88C */
    sh_(R[8] + 40, R[2]);  /* 0x800AD890 */
L_800AD894:;
    R[18] = R[19] + 12;  /* 0x800AD894 */
    R[16] = R[21] + R[0];  /* 0x800AD898 */
L_800AD89C:;
    R[2] = lh_(R[19]);  /* 0x800AD89C */
    R[2] = R[2] & 0x8000;  /* 0x800AD8A4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[29] + 32; if (_c) { goto L_800AD934; } }  /* 0x800AD8A8 */
    R[5] = R[4] + R[0];  /* 0x800AD8B0 */
    R[2] = lw_(R[18] + -8);  /* 0x800AD8B4 */
    R[20] = R[20] + 1;  /* 0x800AD8B8 */
    R[2] = R[2] - R[30];  /* 0x800AD8BC */
    sw_(R[29] + 32, R[2]);  /* 0x800AD8C0 */
    R[2] = lw_(R[18]);  /* 0x800AD8C4 */
    R[19] = R[19] + 16;  /* 0x800AD8C8 */
    sw_(R[29] + 36, R[0]);  /* 0x800AD8CC */
    R[2] = R[2] - R[23];  /* 0x800AD8D0 */
    { R[31] = 0x800AD8DCu; sw_(R[29] + 40, R[2]); psx_next = 0x800270ACu; return; }  /* 0x800AD8D4 jal */
    R[25] = lw_(R[29] + 52);  /* 0x800AD8DC */
    R[3] = lw_(R[29] + 32);  /* 0x800AD8E0 */
    R[2] = R[0] - R[25];  /* 0x800AD8E4 */
    sw_(R[16] + 4, R[2]);  /* 0x800AD8E8 */
    R[2] = R[3] << 1;  /* 0x800AD8EC */
    R[2] = R[2] + R[3];  /* 0x800AD8F0 */
    R[2] = R[2] << 3;  /* 0x800AD8F4 */
    R[2] = R[2] + R[3];  /* 0x800AD8F8 */
    R[2] = R[2] << 2;  /* 0x800AD8FC */
    R[2] = R[2] + R[30];  /* 0x800AD900 */
    sw_(R[16], R[2]);  /* 0x800AD904 */
    R[3] = lw_(R[29] + 40);  /* 0x800AD908 */
    R[18] = R[18] + 16;  /* 0x800AD90C */
    R[2] = R[3] << 1;  /* 0x800AD910 */
    R[2] = R[2] + R[3];  /* 0x800AD914 */
    R[2] = R[2] << 3;  /* 0x800AD918 */
    R[2] = R[2] + R[3];  /* 0x800AD91C */
    R[2] = R[2] << 2;  /* 0x800AD920 */
    R[2] = R[2] + R[23];  /* 0x800AD924 */
    sw_(R[16] + 8, R[2]);  /* 0x800AD928 */
    { R[16] = R[16] + 12; psx_bb(); goto L_800AD89C; }  /* 0x800AD92C j */
L_800AD934:;
    { uint32_t _c = (R[20] == R[0]); R[2] = 0x5555u << 16; if (_c) { goto L_800ADB6C; } }  /* 0x800AD934 */
    R[2] = R[2] | 0x5556;  /* 0x800AD93C */
    R[5] = R[20] + 2;  /* 0x800AD940 */
    { int64_t _p = (int64_t)(int32_t)R[5] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800AD944 */
    R[4] = 0x8011u << 16;  /* 0x800AD948 */
    R[4] = R[4] + 30268;  /* 0x800AD94C */
    R[6] = R[0] + R[0];  /* 0x800AD950 */
    R[5] = (uint32_t)((int32_t)R[5] >> 31);  /* 0x800AD954 */
    R[14] = HI;  /* 0x800AD958 */
    { R[31] = 0x800AD964u; R[5] = R[14] - R[5]; psx_next = 0x80025598u; return; }  /* 0x800AD95C jal */
    R[2] = 0x8013u << 16;  /* 0x800AD964 */
    R[20] = R[2] - 29656;  /* 0x800AD968 */
    R[16] = R[0] + 168;  /* 0x800AD96C */
    R[15] = R[0] + 240;  /* 0x800AD970 */
    R[8] = R[0] + 255;  /* 0x800AD974 */
    R[2] = 0x8005u << 16;  /* 0x800AD978 */
    R[18] = R[2] - 888;  /* 0x800AD97C */
    R[6] = 0xFFu << 16;  /* 0x800AD980 */
    R[6] = R[6] | 0xFFFF;  /* 0x800AD984 */
    R[7] = 0xFF00u << 16;  /* 0x800AD988 */
    R[2] = 0x8013u << 16;  /* 0x800AD98C */
    R[2] = lw_(R[2] + 4152);  /* 0x800AD990 */
    R[5] = R[21] + R[0];  /* 0x800AD994 */
    R[19] = lw_(R[2] + 536);  /* 0x800AD998 */
    R[10] = R[17] + 22;  /* 0x800AD99C */
    R[13] = R[19] + 12;  /* 0x800AD9A0 */
L_800AD9A4:;
    R[2] = lh_(R[19]);  /* 0x800AD9A4 */
    R[2] = R[2] & 0x8000;  /* 0x800AD9AC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x1Fu << 16; if (_c) { goto L_800ADB6C; } }  /* 0x800AD9B0 */
    R[2] = R[2] | 0x3FFF;  /* 0x800AD9B8 */
    R[22] = 0x8011u << 16;  /* 0x800AD9BC */
    R[22] = R[22] + 29992;  /* 0x800AD9C0 */
    R[3] = lw_(R[13] + -4);  /* 0x800AD9C4 */
    R[4] = lw_(R[22] + 144);  /* 0x800AD9C8 */
    R[3] = R[0] - R[3];  /* 0x800AD9CC */
    R[3] = R[3] - R[4];  /* 0x800AD9D0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800AD9E0; } }  /* 0x800AD9D4 */
    R[3] = R[0] - R[3];  /* 0x800AD9DC */
L_800AD9E0:;
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x800AD9E0 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800ADB5C; } }  /* 0x800AD9E4 */
    R[2] = lw_(R[13] + -8);  /* 0x800AD9EC */
    R[2] = R[2] - R[30];  /* 0x800AD9F4 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[9] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_800ADA08; } }  /* 0x800AD9F8 */
    R[2] = R[2] + 4095;  /* 0x800ADA00 */
    R[9] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800ADA04 */
L_800ADA08:;
    { uint32_t _c = ((int32_t)R[9] >= 0); if (_c) { goto L_800ADA14; } }  /* 0x800ADA08 */
    R[9] = R[0] - R[9];  /* 0x800ADA10 */
L_800ADA14:;
    { int64_t _p = (int64_t)(int32_t)R[9] * (int32_t)R[9]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800ADA14 */
    R[2] = lw_(R[13]);  /* 0x800ADA18 */
    R[2] = R[2] - R[23];  /* 0x800ADA20 */
    R[9] = LO;  /* 0x800ADA24 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800ADA34; } }  /* 0x800ADA28 */
    R[2] = R[2] + 4095;  /* 0x800ADA30 */
L_800ADA34:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800ADA34 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800ADA44; } }  /* 0x800ADA38 */
    R[2] = R[0] - R[2];  /* 0x800ADA40 */
L_800ADA44:;
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800ADA44 */
    R[3] = 0x774Du << 16;  /* 0x800ADA48 */
    R[2] = LO;  /* 0x800ADA4C */
    R[3] = R[3] | 0xFD5B;  /* 0x800ADA50 */
    R[9] = R[9] + R[2];  /* 0x800ADA54 */
    { int64_t _p = (int64_t)(int32_t)R[9] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800ADA58 */
    R[4] = lw_(R[20] + 36);  /* 0x800ADA5C */
    R[2] = (uint32_t)((int32_t)R[9] >> 31);  /* 0x800ADA60 */
    R[3] = HI;  /* 0x800ADA64 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800ADA68 */
    R[3] = R[3] - R[2];  /* 0x800ADA6C */
    R[2] = R[0] + 64;  /* 0x800ADA70 */
    R[9] = R[2] - R[3];  /* 0x800ADA74 */
    R[9] = R[9] + R[4];  /* 0x800ADA78 */
    R[2] = ((int32_t)R[9] < 129);  /* 0x800ADA7C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800ADA8C; } }  /* 0x800ADA80 */
    R[9] = R[0] + 128;  /* 0x800ADA88 */
L_800ADA8C:;
    { uint32_t _c = ((int32_t)R[9] <= 0); R[2] = R[0] + 9; if (_c) { goto L_800ADB5C; } }  /* 0x800ADA8C */
    R[11] = (uint32_t)(int16_t)lh_(R[5] + 544);  /* 0x800ADA94 */
    R[12] = (uint32_t)(int16_t)lh_(R[5] + 546);  /* 0x800ADA98 */
    sb_(R[10] + -19, R[2]);  /* 0x800ADA9C */
    R[2] = R[0] + 46;  /* 0x800ADAA0 */
    R[14] = R[0] + 183;  /* 0x800ADAA4 */
    R[22] = R[14] + R[0];  /* 0x800ADAA8 */
    sb_(R[10] + -15, R[2]);  /* 0x800ADAAC */
    sb_(R[10] + -18, R[9]);  /* 0x800ADAB0 */
    sb_(R[10] + -17, R[9]);  /* 0x800ADAB4 */
    sb_(R[10] + -16, R[9]);  /* 0x800ADAB8 */
    sb_(R[10] + -10, R[16]);  /* 0x800ADABC */
    sb_(R[10] + -9, R[15]);  /* 0x800ADAC0 */
    sb_(R[10] + -2, R[14]);  /* 0x800ADAC4 */
    sb_(R[10] + -1, R[15]);  /* 0x800ADAC8 */
    sb_(R[10] + 6, R[16]);  /* 0x800ADACC */
    sb_(R[10] + 7, R[8]);  /* 0x800ADAD0 */
    sb_(R[10] + 14, R[22]);  /* 0x800ADAD4 */
    sb_(R[10] + 15, R[8]);  /* 0x800ADAD8 */
    R[24] = lh_(R[29] + 56);  /* 0x800ADADC */
    R[4] = R[11] - R[24];  /* 0x800ADAE4 */
    R[2] = R[12] - R[24];  /* 0x800ADAE8 */
    R[3] = R[24] + R[11];  /* 0x800ADAEC */
    sh_(R[10] + -12, R[2]);  /* 0x800ADAF0 */
    sh_(R[10] + -4, R[2]);  /* 0x800ADAF4 */
    R[2] = R[24] + R[12];  /* 0x800ADAF8 */
    sh_(R[10] + -14, R[4]);  /* 0x800ADAFC */
    sh_(R[10] + -6, R[3]);  /* 0x800ADB00 */
    sh_(R[10] + 2, R[4]);  /* 0x800ADB04 */
    sh_(R[10] + 4, R[2]);  /* 0x800ADB08 */
    sh_(R[10] + 10, R[3]);  /* 0x800ADB0C */
    sh_(R[10] + 12, R[2]);  /* 0x800ADB10 */
    R[3] = lh_(R[18] + 26);  /* 0x800ADB14 */
    R[2] = R[0] + 57;  /* 0x800ADB18 */
    sh_(R[10], R[2]);  /* 0x800ADB1C */
    sh_(R[10] + -8, R[3]);  /* 0x800ADB20 */
    R[10] = R[10] + 40;  /* 0x800ADB24 */
    R[25] = lw_(R[29] + 48);  /* 0x800ADB28 */
    R[3] = lw_(R[17]);  /* 0x800ADB2C */
    R[2] = lw_(R[25]);  /* 0x800ADB30 */
    R[3] = R[3] & R[7];  /* 0x800ADB34 */
    R[2] = R[2] & R[6];  /* 0x800ADB38 */
    R[3] = R[3] | R[2];  /* 0x800ADB3C */
    sw_(R[17], R[3]);  /* 0x800ADB40 */
    R[3] = R[17] & R[6];  /* 0x800ADB44 */
    R[2] = lw_(R[25]);  /* 0x800ADB48 */
    R[17] = R[17] + 40;  /* 0x800ADB4C */
    R[2] = R[2] & R[7];  /* 0x800ADB50 */
    R[2] = R[2] | R[3];  /* 0x800ADB54 */
    sw_(R[25], R[2]);  /* 0x800ADB58 */
L_800ADB5C:;
    R[13] = R[13] + 16;  /* 0x800ADB5C */
    R[19] = R[19] + 16;  /* 0x800ADB60 */
    { R[5] = R[5] + 8; psx_bb(); goto L_800AD9A4; }  /* 0x800ADB64 j */
L_800ADB6C:;
    R[3] = 0x1u << 16;  /* 0x800ADB6C */
    R[3] = R[3] | 0x8000;  /* 0x800ADB70 */
    R[2] = 0x800Fu << 16;  /* 0x800ADB74 */
    R[2] = R[2] + 25528;  /* 0x800ADB78 */
    R[2] = R[2] + R[3];  /* 0x800ADB7C */
    sw_(R[2] + 20496, R[17]);  /* 0x800ADB80 */
L_800ADB84:;
    R[31] = lw_(R[29] + 100);  /* 0x800ADB84 */
    R[30] = lw_(R[29] + 96);  /* 0x800ADB88 */
    R[23] = lw_(R[29] + 92);  /* 0x800ADB8C */
    R[22] = lw_(R[29] + 88);  /* 0x800ADB90 */
    R[21] = lw_(R[29] + 84);  /* 0x800ADB94 */
    R[20] = lw_(R[29] + 80);  /* 0x800ADB98 */
    R[19] = lw_(R[29] + 76);  /* 0x800ADB9C */
    R[18] = lw_(R[29] + 72);  /* 0x800ADBA0 */
    R[17] = lw_(R[29] + 68);  /* 0x800ADBA4 */
    R[16] = lw_(R[29] + 64);  /* 0x800ADBA8 */
    { R[29] = R[29] + 104; psx_next = R[31]; return; }  /* 0x800ADBAC jr ra */
}

void g0_800AD658(void) {
    R[9] = lw_(R[16]);  /* 0x800AD658 */
    { uint32_t _c = (R[9] == R[0]); R[20] = R[0] + R[0]; if (_c) { goto L_800AD6CC; } }  /* 0x800AD660 */
    R[5] = R[16] + 42;  /* 0x800AD668 */
    R[8] = R[0] + 16;  /* 0x800AD66C */
    R[7] = R[0] + 8;  /* 0x800AD670 */
    R[6] = R[21] + R[0];  /* 0x800AD674 */
L_800AD678:;
    R[4] = R[21] + R[8];  /* 0x800AD678 */
    R[2] = lh_(R[6] + 544);  /* 0x800AD67C */
    R[8] = R[8] + 24;  /* 0x800AD680 */
    sh_(R[5] + -26, R[2]);  /* 0x800AD684 */
    R[2] = lh_(R[6] + 546);  /* 0x800AD688 */
    R[3] = R[21] + R[7];  /* 0x800AD68C */
    sh_(R[5] + -24, R[2]);  /* 0x800AD690 */
    R[2] = lh_(R[3] + 544);  /* 0x800AD694 */
    R[7] = R[7] + 24;  /* 0x800AD698 */
    sh_(R[5] + -14, R[2]);  /* 0x800AD69C */
    R[2] = lh_(R[3] + 546);  /* 0x800AD6A0 */
    R[20] = R[20] + 3;  /* 0x800AD6A4 */
    sh_(R[5] + -12, R[2]);  /* 0x800AD6A8 */
    R[2] = lh_(R[4] + 544);  /* 0x800AD6AC */
    R[9] = R[9] - 1;  /* 0x800AD6B0 */
    sh_(R[5] + -2, R[2]);  /* 0x800AD6B4 */
    R[2] = lh_(R[4] + 546);  /* 0x800AD6B8 */
    R[6] = R[6] + 24;  /* 0x800AD6BC */
    sh_(R[5], R[2]);  /* 0x800AD6C0 */
    { uint32_t _c = (R[9] != R[0]); R[5] = R[5] + 44; if (_c) { psx_bb(); goto L_800AD678; } }  /* 0x800AD6C4 */
L_800AD6CC:;
    R[2] = 0x1u << 16;  /* 0x800AD6CC */
    R[2] = R[2] | 0x8000;  /* 0x800AD6D0 */
    R[4] = 0x801Eu << 16;  /* 0x800AD6D4 */
    R[4] = R[4] | 0xC000;  /* 0x800AD6D8 */
    R[5] = R[0] + R[0];  /* 0x800AD6DC */
    R[16] = 0x800Fu << 16;  /* 0x800AD6E0 */
    R[16] = R[16] + 25528;  /* 0x800AD6E4 */
    R[16] = R[16] + R[2];  /* 0x800AD6E8 */
    R[6] = R[5] + R[0];  /* 0x800AD6EC */
    R[2] = lw_(R[16] + 20496);  /* 0x800AD6F0 */
    R[22] = lw_(R[29] + 48);  /* 0x800AD6F4 */
    R[7] = R[5] + R[0];  /* 0x800AD6F8 */
    sw_(R[29] + 24, R[0]);  /* 0x800AD6FC */
    sw_(R[29] + 20, R[22]);  /* 0x800AD700 */
    { R[31] = 0x800AD70Cu; sw_(R[29] + 16, R[2]); psx_next = 0x80022A58u; return; }  /* 0x800AD704 jal */
    R[3] = 0x8013u << 16;  /* 0x800AD70C */
    R[8] = R[3] - 29656;  /* 0x800AD710 */
    R[5] = lw_(R[8] + 36);  /* 0x800AD714 */
    R[17] = R[2] + R[0];  /* 0x800AD718 */
    { uint32_t _c = ((int32_t)R[5] >= 0); sw_(R[16] + 20496, R[17]); if (_c) { goto L_800AD728; } }  /* 0x800AD71C */
    R[5] = R[5] + 7;  /* 0x800AD724 */
L_800AD728:;
    R[6] = 0xFFu << 16;  /* 0x800AD728 */
    R[6] = R[6] | 0xFFFF;  /* 0x800AD72C */
    R[2] = R[20] << 3;  /* 0x800AD730 */
    R[2] = R[21] + R[2];  /* 0x800AD734 */
    R[11] = (uint32_t)(int16_t)lh_(R[2] + 544);  /* 0x800AD738 */
    R[12] = (uint32_t)(int16_t)lh_(R[2] + 546);  /* 0x800AD73C */
    R[2] = 0x8011u << 16;  /* 0x800AD740 */
    R[7] = lw_(R[2] + 29968);  /* 0x800AD744 */
    R[2] = R[0] + 9;  /* 0x800AD748 */
    sb_(R[17] + 3, R[2]);  /* 0x800AD74C */
    R[2] = R[0] + 46;  /* 0x800AD750 */
    sb_(R[17] + 7, R[2]);  /* 0x800AD754 */
    R[2] = R[0] + 128;  /* 0x800AD758 */
    R[4] = R[0] + 168;  /* 0x800AD75C */
    sb_(R[17] + 4, R[2]);  /* 0x800AD760 */
    sb_(R[17] + 5, R[2]);  /* 0x800AD764 */
    sb_(R[17] + 6, R[2]);  /* 0x800AD768 */
    R[2] = R[0] + 224;  /* 0x800AD76C */
    R[3] = R[0] + 183;  /* 0x800AD770 */
    sb_(R[17] + 13, R[2]);  /* 0x800AD774 */
    sb_(R[17] + 21, R[2]);  /* 0x800AD778 */
    R[2] = R[0] + 239;  /* 0x800AD77C */
    sb_(R[17] + 29, R[2]);  /* 0x800AD780 */
    sb_(R[17] + 37, R[2]);  /* 0x800AD784 */
    R[2] = (uint32_t)((int32_t)R[5] >> 3);  /* 0x800AD788 */
    sb_(R[17] + 12, R[4]);  /* 0x800AD78C */
    sb_(R[17] + 28, R[4]);  /* 0x800AD790 */
    R[4] = R[0] + 6;  /* 0x800AD794 */
    R[4] = R[4] - R[2];  /* 0x800AD798 */
    sb_(R[17] + 20, R[3]);  /* 0x800AD79C */
    sb_(R[17] + 36, R[3]);  /* 0x800AD7A0 */
    R[5] = R[11] - R[4];  /* 0x800AD7A4 */
    R[2] = R[12] - R[4];  /* 0x800AD7A8 */
    R[3] = R[4] + R[11];  /* 0x800AD7AC */
    sh_(R[17] + 10, R[2]);  /* 0x800AD7B0 */
    sh_(R[17] + 18, R[2]);  /* 0x800AD7B4 */
    R[2] = R[4] + R[12];  /* 0x800AD7B8 */
    sh_(R[17] + 26, R[2]);  /* 0x800AD7BC */
    sh_(R[17] + 34, R[2]);  /* 0x800AD7C0 */
    R[2] = 0x8005u << 16;  /* 0x800AD7C4 */
    sh_(R[17] + 8, R[5]);  /* 0x800AD7C8 */
    sh_(R[17] + 16, R[3]);  /* 0x800AD7CC */
    sh_(R[17] + 24, R[5]);  /* 0x800AD7D0 */
    sh_(R[17] + 32, R[3]);  /* 0x800AD7D4 */
    R[3] = lh_(R[2] + -860);  /* 0x800AD7D8 */
    R[2] = R[0] + 57;  /* 0x800AD7DC */
    R[5] = 0xFF00u << 16;  /* 0x800AD7E0 */
    R[24] = R[7] + 92;  /* 0x800AD7E4 */
    sh_(R[17] + 22, R[2]);  /* 0x800AD7E8 */
    sh_(R[17] + 14, R[3]);  /* 0x800AD7EC */
    R[3] = lw_(R[17]);  /* 0x800AD7F0 */
    R[2] = lw_(R[7] + 92);  /* 0x800AD7F4 */
    R[3] = R[3] & R[5];  /* 0x800AD7F8 */
    R[2] = R[2] & R[6];  /* 0x800AD7FC */
    R[3] = R[3] | R[2];  /* 0x800AD800 */
    sw_(R[17], R[3]);  /* 0x800AD804 */
    R[2] = lw_(R[7] + 92);  /* 0x800AD808 */
    R[6] = R[17] & R[6];  /* 0x800AD80C */
    sw_(R[29] + 48, R[24]);  /* 0x800AD810 */
    R[2] = R[2] & R[5];  /* 0x800AD814 */
    R[2] = R[2] | R[6];  /* 0x800AD818 */
    sw_(R[7] + 92, R[2]);  /* 0x800AD81C */
    R[2] = 0x8013u << 16;  /* 0x800AD820 */
    R[2] = lw_(R[2] + 4152);  /* 0x800AD824 */
    R[19] = lw_(R[2] + 536);  /* 0x800AD82C */
    R[17] = R[17] + 40;  /* 0x800AD830 */
    { uint32_t _c = (R[19] == R[0]); sh_(R[29] + 56, R[4]); if (_c) { goto L_800ADB6C; } }  /* 0x800AD834 */
    R[2] = (uint32_t)(int16_t)lh_(R[8] + 40);  /* 0x800AD83C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AD870; } }  /* 0x800AD844 */
    R[2] = lw_(R[8] + 36);  /* 0x800AD84C */
    R[2] = R[2] - 4;  /* 0x800AD854 */
    sw_(R[8] + 36, R[2]);  /* 0x800AD858 */
    R[2] = ((int32_t)R[2] < -31);  /* 0x800AD85C */
    { uint32_t _c = (R[2] == R[0]); R[20] = R[0] + R[0]; if (_c) { goto L_800AD894; } }  /* 0x800AD860 */
    { sh_(R[8] + 40, R[0]); goto L_800AD894; }  /* 0x800AD868 j */
L_800AD870:;
    R[2] = lw_(R[8] + 36);  /* 0x800AD870 */
    R[2] = R[2] + 4;  /* 0x800AD878 */
    sw_(R[8] + 36, R[2]);  /* 0x800AD87C */
    R[2] = ((int32_t)R[2] < 32);  /* 0x800AD880 */
    { uint32_t _c = (R[2] != R[0]); R[20] = R[0] + R[0]; if (_c) { goto L_800AD894; } }  /* 0x800AD884 */
    R[2] = R[0] + 1;  /* 0x800AD88C */
    sh_(R[8] + 40, R[2]);  /* 0x800AD890 */
L_800AD894:;
    R[18] = R[19] + 12;  /* 0x800AD894 */
    R[16] = R[21] + R[0];  /* 0x800AD898 */
L_800AD89C:;
    R[2] = lh_(R[19]);  /* 0x800AD89C */
    R[2] = R[2] & 0x8000;  /* 0x800AD8A4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[29] + 32; if (_c) { goto L_800AD934; } }  /* 0x800AD8A8 */
    R[5] = R[4] + R[0];  /* 0x800AD8B0 */
    R[2] = lw_(R[18] + -8);  /* 0x800AD8B4 */
    R[20] = R[20] + 1;  /* 0x800AD8B8 */
    R[2] = R[2] - R[30];  /* 0x800AD8BC */
    sw_(R[29] + 32, R[2]);  /* 0x800AD8C0 */
    R[2] = lw_(R[18]);  /* 0x800AD8C4 */
    R[19] = R[19] + 16;  /* 0x800AD8C8 */
    sw_(R[29] + 36, R[0]);  /* 0x800AD8CC */
    R[2] = R[2] - R[23];  /* 0x800AD8D0 */
    { R[31] = 0x800AD8DCu; sw_(R[29] + 40, R[2]); psx_next = 0x800270ACu; return; }  /* 0x800AD8D4 jal */
    R[25] = lw_(R[29] + 52);  /* 0x800AD8DC */
    R[3] = lw_(R[29] + 32);  /* 0x800AD8E0 */
    R[2] = R[0] - R[25];  /* 0x800AD8E4 */
    sw_(R[16] + 4, R[2]);  /* 0x800AD8E8 */
    R[2] = R[3] << 1;  /* 0x800AD8EC */
    R[2] = R[2] + R[3];  /* 0x800AD8F0 */
    R[2] = R[2] << 3;  /* 0x800AD8F4 */
    R[2] = R[2] + R[3];  /* 0x800AD8F8 */
    R[2] = R[2] << 2;  /* 0x800AD8FC */
    R[2] = R[2] + R[30];  /* 0x800AD900 */
    sw_(R[16], R[2]);  /* 0x800AD904 */
    R[3] = lw_(R[29] + 40);  /* 0x800AD908 */
    R[18] = R[18] + 16;  /* 0x800AD90C */
    R[2] = R[3] << 1;  /* 0x800AD910 */
    R[2] = R[2] + R[3];  /* 0x800AD914 */
    R[2] = R[2] << 3;  /* 0x800AD918 */
    R[2] = R[2] + R[3];  /* 0x800AD91C */
    R[2] = R[2] << 2;  /* 0x800AD920 */
    R[2] = R[2] + R[23];  /* 0x800AD924 */
    sw_(R[16] + 8, R[2]);  /* 0x800AD928 */
    { R[16] = R[16] + 12; psx_bb(); goto L_800AD89C; }  /* 0x800AD92C j */
L_800AD934:;
    { uint32_t _c = (R[20] == R[0]); R[2] = 0x5555u << 16; if (_c) { goto L_800ADB6C; } }  /* 0x800AD934 */
    R[2] = R[2] | 0x5556;  /* 0x800AD93C */
    R[5] = R[20] + 2;  /* 0x800AD940 */
    { int64_t _p = (int64_t)(int32_t)R[5] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800AD944 */
    R[4] = 0x8011u << 16;  /* 0x800AD948 */
    R[4] = R[4] + 30268;  /* 0x800AD94C */
    R[6] = R[0] + R[0];  /* 0x800AD950 */
    R[5] = (uint32_t)((int32_t)R[5] >> 31);  /* 0x800AD954 */
    R[14] = HI;  /* 0x800AD958 */
    { R[31] = 0x800AD964u; R[5] = R[14] - R[5]; psx_next = 0x80025598u; return; }  /* 0x800AD95C jal */
    R[2] = 0x8013u << 16;  /* 0x800AD964 */
    R[20] = R[2] - 29656;  /* 0x800AD968 */
    R[16] = R[0] + 168;  /* 0x800AD96C */
    R[15] = R[0] + 240;  /* 0x800AD970 */
    R[8] = R[0] + 255;  /* 0x800AD974 */
    R[2] = 0x8005u << 16;  /* 0x800AD978 */
    R[18] = R[2] - 888;  /* 0x800AD97C */
    R[6] = 0xFFu << 16;  /* 0x800AD980 */
    R[6] = R[6] | 0xFFFF;  /* 0x800AD984 */
    R[7] = 0xFF00u << 16;  /* 0x800AD988 */
    R[2] = 0x8013u << 16;  /* 0x800AD98C */
    R[2] = lw_(R[2] + 4152);  /* 0x800AD990 */
    R[5] = R[21] + R[0];  /* 0x800AD994 */
    R[19] = lw_(R[2] + 536);  /* 0x800AD998 */
    R[10] = R[17] + 22;  /* 0x800AD99C */
    R[13] = R[19] + 12;  /* 0x800AD9A0 */
L_800AD9A4:;
    R[2] = lh_(R[19]);  /* 0x800AD9A4 */
    R[2] = R[2] & 0x8000;  /* 0x800AD9AC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x1Fu << 16; if (_c) { goto L_800ADB6C; } }  /* 0x800AD9B0 */
    R[2] = R[2] | 0x3FFF;  /* 0x800AD9B8 */
    R[22] = 0x8011u << 16;  /* 0x800AD9BC */
    R[22] = R[22] + 29992;  /* 0x800AD9C0 */
    R[3] = lw_(R[13] + -4);  /* 0x800AD9C4 */
    R[4] = lw_(R[22] + 144);  /* 0x800AD9C8 */
    R[3] = R[0] - R[3];  /* 0x800AD9CC */
    R[3] = R[3] - R[4];  /* 0x800AD9D0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800AD9E0; } }  /* 0x800AD9D4 */
    R[3] = R[0] - R[3];  /* 0x800AD9DC */
L_800AD9E0:;
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x800AD9E0 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800ADB5C; } }  /* 0x800AD9E4 */
    R[2] = lw_(R[13] + -8);  /* 0x800AD9EC */
    R[2] = R[2] - R[30];  /* 0x800AD9F4 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[9] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_800ADA08; } }  /* 0x800AD9F8 */
    R[2] = R[2] + 4095;  /* 0x800ADA00 */
    R[9] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800ADA04 */
L_800ADA08:;
    { uint32_t _c = ((int32_t)R[9] >= 0); if (_c) { goto L_800ADA14; } }  /* 0x800ADA08 */
    R[9] = R[0] - R[9];  /* 0x800ADA10 */
L_800ADA14:;
    { int64_t _p = (int64_t)(int32_t)R[9] * (int32_t)R[9]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800ADA14 */
    R[2] = lw_(R[13]);  /* 0x800ADA18 */
    R[2] = R[2] - R[23];  /* 0x800ADA20 */
    R[9] = LO;  /* 0x800ADA24 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800ADA34; } }  /* 0x800ADA28 */
    R[2] = R[2] + 4095;  /* 0x800ADA30 */
L_800ADA34:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800ADA34 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800ADA44; } }  /* 0x800ADA38 */
    R[2] = R[0] - R[2];  /* 0x800ADA40 */
L_800ADA44:;
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800ADA44 */
    R[3] = 0x774Du << 16;  /* 0x800ADA48 */
    R[2] = LO;  /* 0x800ADA4C */
    R[3] = R[3] | 0xFD5B;  /* 0x800ADA50 */
    R[9] = R[9] + R[2];  /* 0x800ADA54 */
    { int64_t _p = (int64_t)(int32_t)R[9] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800ADA58 */
    R[4] = lw_(R[20] + 36);  /* 0x800ADA5C */
    R[2] = (uint32_t)((int32_t)R[9] >> 31);  /* 0x800ADA60 */
    R[3] = HI;  /* 0x800ADA64 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800ADA68 */
    R[3] = R[3] - R[2];  /* 0x800ADA6C */
    R[2] = R[0] + 64;  /* 0x800ADA70 */
    R[9] = R[2] - R[3];  /* 0x800ADA74 */
    R[9] = R[9] + R[4];  /* 0x800ADA78 */
    R[2] = ((int32_t)R[9] < 129);  /* 0x800ADA7C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800ADA8C; } }  /* 0x800ADA80 */
    R[9] = R[0] + 128;  /* 0x800ADA88 */
L_800ADA8C:;
    { uint32_t _c = ((int32_t)R[9] <= 0); R[2] = R[0] + 9; if (_c) { goto L_800ADB5C; } }  /* 0x800ADA8C */
    R[11] = (uint32_t)(int16_t)lh_(R[5] + 544);  /* 0x800ADA94 */
    R[12] = (uint32_t)(int16_t)lh_(R[5] + 546);  /* 0x800ADA98 */
    sb_(R[10] + -19, R[2]);  /* 0x800ADA9C */
    R[2] = R[0] + 46;  /* 0x800ADAA0 */
    R[14] = R[0] + 183;  /* 0x800ADAA4 */
    R[22] = R[14] + R[0];  /* 0x800ADAA8 */
    sb_(R[10] + -15, R[2]);  /* 0x800ADAAC */
    sb_(R[10] + -18, R[9]);  /* 0x800ADAB0 */
    sb_(R[10] + -17, R[9]);  /* 0x800ADAB4 */
    sb_(R[10] + -16, R[9]);  /* 0x800ADAB8 */
    sb_(R[10] + -10, R[16]);  /* 0x800ADABC */
    sb_(R[10] + -9, R[15]);  /* 0x800ADAC0 */
    sb_(R[10] + -2, R[14]);  /* 0x800ADAC4 */
    sb_(R[10] + -1, R[15]);  /* 0x800ADAC8 */
    sb_(R[10] + 6, R[16]);  /* 0x800ADACC */
    sb_(R[10] + 7, R[8]);  /* 0x800ADAD0 */
    sb_(R[10] + 14, R[22]);  /* 0x800ADAD4 */
    sb_(R[10] + 15, R[8]);  /* 0x800ADAD8 */
    R[24] = lh_(R[29] + 56);  /* 0x800ADADC */
    R[4] = R[11] - R[24];  /* 0x800ADAE4 */
    R[2] = R[12] - R[24];  /* 0x800ADAE8 */
    R[3] = R[24] + R[11];  /* 0x800ADAEC */
    sh_(R[10] + -12, R[2]);  /* 0x800ADAF0 */
    sh_(R[10] + -4, R[2]);  /* 0x800ADAF4 */
    R[2] = R[24] + R[12];  /* 0x800ADAF8 */
    sh_(R[10] + -14, R[4]);  /* 0x800ADAFC */
    sh_(R[10] + -6, R[3]);  /* 0x800ADB00 */
    sh_(R[10] + 2, R[4]);  /* 0x800ADB04 */
    sh_(R[10] + 4, R[2]);  /* 0x800ADB08 */
    sh_(R[10] + 10, R[3]);  /* 0x800ADB0C */
    sh_(R[10] + 12, R[2]);  /* 0x800ADB10 */
    R[3] = lh_(R[18] + 26);  /* 0x800ADB14 */
    R[2] = R[0] + 57;  /* 0x800ADB18 */
    sh_(R[10], R[2]);  /* 0x800ADB1C */
    sh_(R[10] + -8, R[3]);  /* 0x800ADB20 */
    R[10] = R[10] + 40;  /* 0x800ADB24 */
    R[25] = lw_(R[29] + 48);  /* 0x800ADB28 */
    R[3] = lw_(R[17]);  /* 0x800ADB2C */
    R[2] = lw_(R[25]);  /* 0x800ADB30 */
    R[3] = R[3] & R[7];  /* 0x800ADB34 */
    R[2] = R[2] & R[6];  /* 0x800ADB38 */
    R[3] = R[3] | R[2];  /* 0x800ADB3C */
    sw_(R[17], R[3]);  /* 0x800ADB40 */
    R[3] = R[17] & R[6];  /* 0x800ADB44 */
    R[2] = lw_(R[25]);  /* 0x800ADB48 */
    R[17] = R[17] + 40;  /* 0x800ADB4C */
    R[2] = R[2] & R[7];  /* 0x800ADB50 */
    R[2] = R[2] | R[3];  /* 0x800ADB54 */
    sw_(R[25], R[2]);  /* 0x800ADB58 */
L_800ADB5C:;
    R[13] = R[13] + 16;  /* 0x800ADB5C */
    R[19] = R[19] + 16;  /* 0x800ADB60 */
    { R[5] = R[5] + 8; psx_bb(); goto L_800AD9A4; }  /* 0x800ADB64 j */
L_800ADB6C:;
    R[3] = 0x1u << 16;  /* 0x800ADB6C */
    R[3] = R[3] | 0x8000;  /* 0x800ADB70 */
    R[2] = 0x800Fu << 16;  /* 0x800ADB74 */
    R[2] = R[2] + 25528;  /* 0x800ADB78 */
    R[2] = R[2] + R[3];  /* 0x800ADB7C */
    sw_(R[2] + 20496, R[17]);  /* 0x800ADB80 */
    R[31] = lw_(R[29] + 100);  /* 0x800ADB84 */
    R[30] = lw_(R[29] + 96);  /* 0x800ADB88 */
    R[23] = lw_(R[29] + 92);  /* 0x800ADB8C */
    R[22] = lw_(R[29] + 88);  /* 0x800ADB90 */
    R[21] = lw_(R[29] + 84);  /* 0x800ADB94 */
    R[20] = lw_(R[29] + 80);  /* 0x800ADB98 */
    R[19] = lw_(R[29] + 76);  /* 0x800ADB9C */
    R[18] = lw_(R[29] + 72);  /* 0x800ADBA0 */
    R[17] = lw_(R[29] + 68);  /* 0x800ADBA4 */
    R[16] = lw_(R[29] + 64);  /* 0x800ADBA8 */
    { R[29] = R[29] + 104; psx_next = R[31]; return; }  /* 0x800ADBAC jr ra */
}

void g0_800AD70C(void) {
    R[3] = 0x8013u << 16;  /* 0x800AD70C */
    R[8] = R[3] - 29656;  /* 0x800AD710 */
    R[5] = lw_(R[8] + 36);  /* 0x800AD714 */
    R[17] = R[2] + R[0];  /* 0x800AD718 */
    { uint32_t _c = ((int32_t)R[5] >= 0); sw_(R[16] + 20496, R[17]); if (_c) { goto L_800AD728; } }  /* 0x800AD71C */
    R[5] = R[5] + 7;  /* 0x800AD724 */
L_800AD728:;
    R[6] = 0xFFu << 16;  /* 0x800AD728 */
    R[6] = R[6] | 0xFFFF;  /* 0x800AD72C */
    R[2] = R[20] << 3;  /* 0x800AD730 */
    R[2] = R[21] + R[2];  /* 0x800AD734 */
    R[11] = (uint32_t)(int16_t)lh_(R[2] + 544);  /* 0x800AD738 */
    R[12] = (uint32_t)(int16_t)lh_(R[2] + 546);  /* 0x800AD73C */
    R[2] = 0x8011u << 16;  /* 0x800AD740 */
    R[7] = lw_(R[2] + 29968);  /* 0x800AD744 */
    R[2] = R[0] + 9;  /* 0x800AD748 */
    sb_(R[17] + 3, R[2]);  /* 0x800AD74C */
    R[2] = R[0] + 46;  /* 0x800AD750 */
    sb_(R[17] + 7, R[2]);  /* 0x800AD754 */
    R[2] = R[0] + 128;  /* 0x800AD758 */
    R[4] = R[0] + 168;  /* 0x800AD75C */
    sb_(R[17] + 4, R[2]);  /* 0x800AD760 */
    sb_(R[17] + 5, R[2]);  /* 0x800AD764 */
    sb_(R[17] + 6, R[2]);  /* 0x800AD768 */
    R[2] = R[0] + 224;  /* 0x800AD76C */
    R[3] = R[0] + 183;  /* 0x800AD770 */
    sb_(R[17] + 13, R[2]);  /* 0x800AD774 */
    sb_(R[17] + 21, R[2]);  /* 0x800AD778 */
    R[2] = R[0] + 239;  /* 0x800AD77C */
    sb_(R[17] + 29, R[2]);  /* 0x800AD780 */
    sb_(R[17] + 37, R[2]);  /* 0x800AD784 */
    R[2] = (uint32_t)((int32_t)R[5] >> 3);  /* 0x800AD788 */
    sb_(R[17] + 12, R[4]);  /* 0x800AD78C */
    sb_(R[17] + 28, R[4]);  /* 0x800AD790 */
    R[4] = R[0] + 6;  /* 0x800AD794 */
    R[4] = R[4] - R[2];  /* 0x800AD798 */
    sb_(R[17] + 20, R[3]);  /* 0x800AD79C */
    sb_(R[17] + 36, R[3]);  /* 0x800AD7A0 */
    R[5] = R[11] - R[4];  /* 0x800AD7A4 */
    R[2] = R[12] - R[4];  /* 0x800AD7A8 */
    R[3] = R[4] + R[11];  /* 0x800AD7AC */
    sh_(R[17] + 10, R[2]);  /* 0x800AD7B0 */
    sh_(R[17] + 18, R[2]);  /* 0x800AD7B4 */
    R[2] = R[4] + R[12];  /* 0x800AD7B8 */
    sh_(R[17] + 26, R[2]);  /* 0x800AD7BC */
    sh_(R[17] + 34, R[2]);  /* 0x800AD7C0 */
    R[2] = 0x8005u << 16;  /* 0x800AD7C4 */
    sh_(R[17] + 8, R[5]);  /* 0x800AD7C8 */
    sh_(R[17] + 16, R[3]);  /* 0x800AD7CC */
    sh_(R[17] + 24, R[5]);  /* 0x800AD7D0 */
    sh_(R[17] + 32, R[3]);  /* 0x800AD7D4 */
    R[3] = lh_(R[2] + -860);  /* 0x800AD7D8 */
    R[2] = R[0] + 57;  /* 0x800AD7DC */
    R[5] = 0xFF00u << 16;  /* 0x800AD7E0 */
    R[24] = R[7] + 92;  /* 0x800AD7E4 */
    sh_(R[17] + 22, R[2]);  /* 0x800AD7E8 */
    sh_(R[17] + 14, R[3]);  /* 0x800AD7EC */
    R[3] = lw_(R[17]);  /* 0x800AD7F0 */
    R[2] = lw_(R[7] + 92);  /* 0x800AD7F4 */
    R[3] = R[3] & R[5];  /* 0x800AD7F8 */
    R[2] = R[2] & R[6];  /* 0x800AD7FC */
    R[3] = R[3] | R[2];  /* 0x800AD800 */
    sw_(R[17], R[3]);  /* 0x800AD804 */
    R[2] = lw_(R[7] + 92);  /* 0x800AD808 */
    R[6] = R[17] & R[6];  /* 0x800AD80C */
    sw_(R[29] + 48, R[24]);  /* 0x800AD810 */
    R[2] = R[2] & R[5];  /* 0x800AD814 */
    R[2] = R[2] | R[6];  /* 0x800AD818 */
    sw_(R[7] + 92, R[2]);  /* 0x800AD81C */
    R[2] = 0x8013u << 16;  /* 0x800AD820 */
    R[2] = lw_(R[2] + 4152);  /* 0x800AD824 */
    R[19] = lw_(R[2] + 536);  /* 0x800AD82C */
    R[17] = R[17] + 40;  /* 0x800AD830 */
    { uint32_t _c = (R[19] == R[0]); sh_(R[29] + 56, R[4]); if (_c) { goto L_800ADB6C; } }  /* 0x800AD834 */
    R[2] = (uint32_t)(int16_t)lh_(R[8] + 40);  /* 0x800AD83C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AD870; } }  /* 0x800AD844 */
    R[2] = lw_(R[8] + 36);  /* 0x800AD84C */
    R[2] = R[2] - 4;  /* 0x800AD854 */
    sw_(R[8] + 36, R[2]);  /* 0x800AD858 */
    R[2] = ((int32_t)R[2] < -31);  /* 0x800AD85C */
    { uint32_t _c = (R[2] == R[0]); R[20] = R[0] + R[0]; if (_c) { goto L_800AD894; } }  /* 0x800AD860 */
    { sh_(R[8] + 40, R[0]); goto L_800AD894; }  /* 0x800AD868 j */
L_800AD870:;
    R[2] = lw_(R[8] + 36);  /* 0x800AD870 */
    R[2] = R[2] + 4;  /* 0x800AD878 */
    sw_(R[8] + 36, R[2]);  /* 0x800AD87C */
    R[2] = ((int32_t)R[2] < 32);  /* 0x800AD880 */
    { uint32_t _c = (R[2] != R[0]); R[20] = R[0] + R[0]; if (_c) { goto L_800AD894; } }  /* 0x800AD884 */
    R[2] = R[0] + 1;  /* 0x800AD88C */
    sh_(R[8] + 40, R[2]);  /* 0x800AD890 */
L_800AD894:;
    R[18] = R[19] + 12;  /* 0x800AD894 */
    R[16] = R[21] + R[0];  /* 0x800AD898 */
L_800AD89C:;
    R[2] = lh_(R[19]);  /* 0x800AD89C */
    R[2] = R[2] & 0x8000;  /* 0x800AD8A4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[29] + 32; if (_c) { goto L_800AD934; } }  /* 0x800AD8A8 */
    R[5] = R[4] + R[0];  /* 0x800AD8B0 */
    R[2] = lw_(R[18] + -8);  /* 0x800AD8B4 */
    R[20] = R[20] + 1;  /* 0x800AD8B8 */
    R[2] = R[2] - R[30];  /* 0x800AD8BC */
    sw_(R[29] + 32, R[2]);  /* 0x800AD8C0 */
    R[2] = lw_(R[18]);  /* 0x800AD8C4 */
    R[19] = R[19] + 16;  /* 0x800AD8C8 */
    sw_(R[29] + 36, R[0]);  /* 0x800AD8CC */
    R[2] = R[2] - R[23];  /* 0x800AD8D0 */
    { R[31] = 0x800AD8DCu; sw_(R[29] + 40, R[2]); psx_next = 0x800270ACu; return; }  /* 0x800AD8D4 jal */
    R[25] = lw_(R[29] + 52);  /* 0x800AD8DC */
    R[3] = lw_(R[29] + 32);  /* 0x800AD8E0 */
    R[2] = R[0] - R[25];  /* 0x800AD8E4 */
    sw_(R[16] + 4, R[2]);  /* 0x800AD8E8 */
    R[2] = R[3] << 1;  /* 0x800AD8EC */
    R[2] = R[2] + R[3];  /* 0x800AD8F0 */
    R[2] = R[2] << 3;  /* 0x800AD8F4 */
    R[2] = R[2] + R[3];  /* 0x800AD8F8 */
    R[2] = R[2] << 2;  /* 0x800AD8FC */
    R[2] = R[2] + R[30];  /* 0x800AD900 */
    sw_(R[16], R[2]);  /* 0x800AD904 */
    R[3] = lw_(R[29] + 40);  /* 0x800AD908 */
    R[18] = R[18] + 16;  /* 0x800AD90C */
    R[2] = R[3] << 1;  /* 0x800AD910 */
    R[2] = R[2] + R[3];  /* 0x800AD914 */
    R[2] = R[2] << 3;  /* 0x800AD918 */
    R[2] = R[2] + R[3];  /* 0x800AD91C */
    R[2] = R[2] << 2;  /* 0x800AD920 */
    R[2] = R[2] + R[23];  /* 0x800AD924 */
    sw_(R[16] + 8, R[2]);  /* 0x800AD928 */
    { R[16] = R[16] + 12; psx_bb(); goto L_800AD89C; }  /* 0x800AD92C j */
L_800AD934:;
    { uint32_t _c = (R[20] == R[0]); R[2] = 0x5555u << 16; if (_c) { goto L_800ADB6C; } }  /* 0x800AD934 */
    R[2] = R[2] | 0x5556;  /* 0x800AD93C */
    R[5] = R[20] + 2;  /* 0x800AD940 */
    { int64_t _p = (int64_t)(int32_t)R[5] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800AD944 */
    R[4] = 0x8011u << 16;  /* 0x800AD948 */
    R[4] = R[4] + 30268;  /* 0x800AD94C */
    R[6] = R[0] + R[0];  /* 0x800AD950 */
    R[5] = (uint32_t)((int32_t)R[5] >> 31);  /* 0x800AD954 */
    R[14] = HI;  /* 0x800AD958 */
    { R[31] = 0x800AD964u; R[5] = R[14] - R[5]; psx_next = 0x80025598u; return; }  /* 0x800AD95C jal */
    R[2] = 0x8013u << 16;  /* 0x800AD964 */
    R[20] = R[2] - 29656;  /* 0x800AD968 */
    R[16] = R[0] + 168;  /* 0x800AD96C */
    R[15] = R[0] + 240;  /* 0x800AD970 */
    R[8] = R[0] + 255;  /* 0x800AD974 */
    R[2] = 0x8005u << 16;  /* 0x800AD978 */
    R[18] = R[2] - 888;  /* 0x800AD97C */
    R[6] = 0xFFu << 16;  /* 0x800AD980 */
    R[6] = R[6] | 0xFFFF;  /* 0x800AD984 */
    R[7] = 0xFF00u << 16;  /* 0x800AD988 */
    R[2] = 0x8013u << 16;  /* 0x800AD98C */
    R[2] = lw_(R[2] + 4152);  /* 0x800AD990 */
    R[5] = R[21] + R[0];  /* 0x800AD994 */
    R[19] = lw_(R[2] + 536);  /* 0x800AD998 */
    R[10] = R[17] + 22;  /* 0x800AD99C */
    R[13] = R[19] + 12;  /* 0x800AD9A0 */
L_800AD9A4:;
    R[2] = lh_(R[19]);  /* 0x800AD9A4 */
    R[2] = R[2] & 0x8000;  /* 0x800AD9AC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x1Fu << 16; if (_c) { goto L_800ADB6C; } }  /* 0x800AD9B0 */
    R[2] = R[2] | 0x3FFF;  /* 0x800AD9B8 */
    R[22] = 0x8011u << 16;  /* 0x800AD9BC */
    R[22] = R[22] + 29992;  /* 0x800AD9C0 */
    R[3] = lw_(R[13] + -4);  /* 0x800AD9C4 */
    R[4] = lw_(R[22] + 144);  /* 0x800AD9C8 */
    R[3] = R[0] - R[3];  /* 0x800AD9CC */
    R[3] = R[3] - R[4];  /* 0x800AD9D0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800AD9E0; } }  /* 0x800AD9D4 */
    R[3] = R[0] - R[3];  /* 0x800AD9DC */
L_800AD9E0:;
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x800AD9E0 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800ADB5C; } }  /* 0x800AD9E4 */
    R[2] = lw_(R[13] + -8);  /* 0x800AD9EC */
    R[2] = R[2] - R[30];  /* 0x800AD9F4 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[9] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_800ADA08; } }  /* 0x800AD9F8 */
    R[2] = R[2] + 4095;  /* 0x800ADA00 */
    R[9] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800ADA04 */
L_800ADA08:;
    { uint32_t _c = ((int32_t)R[9] >= 0); if (_c) { goto L_800ADA14; } }  /* 0x800ADA08 */
    R[9] = R[0] - R[9];  /* 0x800ADA10 */
L_800ADA14:;
    { int64_t _p = (int64_t)(int32_t)R[9] * (int32_t)R[9]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800ADA14 */
    R[2] = lw_(R[13]);  /* 0x800ADA18 */
    R[2] = R[2] - R[23];  /* 0x800ADA20 */
    R[9] = LO;  /* 0x800ADA24 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800ADA34; } }  /* 0x800ADA28 */
    R[2] = R[2] + 4095;  /* 0x800ADA30 */
L_800ADA34:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800ADA34 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800ADA44; } }  /* 0x800ADA38 */
    R[2] = R[0] - R[2];  /* 0x800ADA40 */
L_800ADA44:;
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800ADA44 */
    R[3] = 0x774Du << 16;  /* 0x800ADA48 */
    R[2] = LO;  /* 0x800ADA4C */
    R[3] = R[3] | 0xFD5B;  /* 0x800ADA50 */
    R[9] = R[9] + R[2];  /* 0x800ADA54 */
    { int64_t _p = (int64_t)(int32_t)R[9] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800ADA58 */
    R[4] = lw_(R[20] + 36);  /* 0x800ADA5C */
    R[2] = (uint32_t)((int32_t)R[9] >> 31);  /* 0x800ADA60 */
    R[3] = HI;  /* 0x800ADA64 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800ADA68 */
    R[3] = R[3] - R[2];  /* 0x800ADA6C */
    R[2] = R[0] + 64;  /* 0x800ADA70 */
    R[9] = R[2] - R[3];  /* 0x800ADA74 */
    R[9] = R[9] + R[4];  /* 0x800ADA78 */
    R[2] = ((int32_t)R[9] < 129);  /* 0x800ADA7C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800ADA8C; } }  /* 0x800ADA80 */
    R[9] = R[0] + 128;  /* 0x800ADA88 */
L_800ADA8C:;
    { uint32_t _c = ((int32_t)R[9] <= 0); R[2] = R[0] + 9; if (_c) { goto L_800ADB5C; } }  /* 0x800ADA8C */
    R[11] = (uint32_t)(int16_t)lh_(R[5] + 544);  /* 0x800ADA94 */
    R[12] = (uint32_t)(int16_t)lh_(R[5] + 546);  /* 0x800ADA98 */
    sb_(R[10] + -19, R[2]);  /* 0x800ADA9C */
    R[2] = R[0] + 46;  /* 0x800ADAA0 */
    R[14] = R[0] + 183;  /* 0x800ADAA4 */
    R[22] = R[14] + R[0];  /* 0x800ADAA8 */
    sb_(R[10] + -15, R[2]);  /* 0x800ADAAC */
    sb_(R[10] + -18, R[9]);  /* 0x800ADAB0 */
    sb_(R[10] + -17, R[9]);  /* 0x800ADAB4 */
    sb_(R[10] + -16, R[9]);  /* 0x800ADAB8 */
    sb_(R[10] + -10, R[16]);  /* 0x800ADABC */
    sb_(R[10] + -9, R[15]);  /* 0x800ADAC0 */
    sb_(R[10] + -2, R[14]);  /* 0x800ADAC4 */
    sb_(R[10] + -1, R[15]);  /* 0x800ADAC8 */
    sb_(R[10] + 6, R[16]);  /* 0x800ADACC */
    sb_(R[10] + 7, R[8]);  /* 0x800ADAD0 */
    sb_(R[10] + 14, R[22]);  /* 0x800ADAD4 */
    sb_(R[10] + 15, R[8]);  /* 0x800ADAD8 */
    R[24] = lh_(R[29] + 56);  /* 0x800ADADC */
    R[4] = R[11] - R[24];  /* 0x800ADAE4 */
    R[2] = R[12] - R[24];  /* 0x800ADAE8 */
    R[3] = R[24] + R[11];  /* 0x800ADAEC */
    sh_(R[10] + -12, R[2]);  /* 0x800ADAF0 */
    sh_(R[10] + -4, R[2]);  /* 0x800ADAF4 */
    R[2] = R[24] + R[12];  /* 0x800ADAF8 */
    sh_(R[10] + -14, R[4]);  /* 0x800ADAFC */
    sh_(R[10] + -6, R[3]);  /* 0x800ADB00 */
    sh_(R[10] + 2, R[4]);  /* 0x800ADB04 */
    sh_(R[10] + 4, R[2]);  /* 0x800ADB08 */
    sh_(R[10] + 10, R[3]);  /* 0x800ADB0C */
    sh_(R[10] + 12, R[2]);  /* 0x800ADB10 */
    R[3] = lh_(R[18] + 26);  /* 0x800ADB14 */
    R[2] = R[0] + 57;  /* 0x800ADB18 */
    sh_(R[10], R[2]);  /* 0x800ADB1C */
    sh_(R[10] + -8, R[3]);  /* 0x800ADB20 */
    R[10] = R[10] + 40;  /* 0x800ADB24 */
    R[25] = lw_(R[29] + 48);  /* 0x800ADB28 */
    R[3] = lw_(R[17]);  /* 0x800ADB2C */
    R[2] = lw_(R[25]);  /* 0x800ADB30 */
    R[3] = R[3] & R[7];  /* 0x800ADB34 */
    R[2] = R[2] & R[6];  /* 0x800ADB38 */
    R[3] = R[3] | R[2];  /* 0x800ADB3C */
    sw_(R[17], R[3]);  /* 0x800ADB40 */
    R[3] = R[17] & R[6];  /* 0x800ADB44 */
    R[2] = lw_(R[25]);  /* 0x800ADB48 */
    R[17] = R[17] + 40;  /* 0x800ADB4C */
    R[2] = R[2] & R[7];  /* 0x800ADB50 */
    R[2] = R[2] | R[3];  /* 0x800ADB54 */
    sw_(R[25], R[2]);  /* 0x800ADB58 */
L_800ADB5C:;
    R[13] = R[13] + 16;  /* 0x800ADB5C */
    R[19] = R[19] + 16;  /* 0x800ADB60 */
    { R[5] = R[5] + 8; psx_bb(); goto L_800AD9A4; }  /* 0x800ADB64 j */
L_800ADB6C:;
    R[3] = 0x1u << 16;  /* 0x800ADB6C */
    R[3] = R[3] | 0x8000;  /* 0x800ADB70 */
    R[2] = 0x800Fu << 16;  /* 0x800ADB74 */
    R[2] = R[2] + 25528;  /* 0x800ADB78 */
    R[2] = R[2] + R[3];  /* 0x800ADB7C */
    sw_(R[2] + 20496, R[17]);  /* 0x800ADB80 */
    R[31] = lw_(R[29] + 100);  /* 0x800ADB84 */
    R[30] = lw_(R[29] + 96);  /* 0x800ADB88 */
    R[23] = lw_(R[29] + 92);  /* 0x800ADB8C */
    R[22] = lw_(R[29] + 88);  /* 0x800ADB90 */
    R[21] = lw_(R[29] + 84);  /* 0x800ADB94 */
    R[20] = lw_(R[29] + 80);  /* 0x800ADB98 */
    R[19] = lw_(R[29] + 76);  /* 0x800ADB9C */
    R[18] = lw_(R[29] + 72);  /* 0x800ADBA0 */
    R[17] = lw_(R[29] + 68);  /* 0x800ADBA4 */
    R[16] = lw_(R[29] + 64);  /* 0x800ADBA8 */
    { R[29] = R[29] + 104; psx_next = R[31]; return; }  /* 0x800ADBAC jr ra */
}

void g0_800AD89C(void) {
L_800AD89C:;
    R[2] = lh_(R[19]);  /* 0x800AD89C */
    R[2] = R[2] & 0x8000;  /* 0x800AD8A4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[29] + 32; if (_c) { goto L_800AD934; } }  /* 0x800AD8A8 */
    R[5] = R[4] + R[0];  /* 0x800AD8B0 */
    R[2] = lw_(R[18] + -8);  /* 0x800AD8B4 */
    R[20] = R[20] + 1;  /* 0x800AD8B8 */
    R[2] = R[2] - R[30];  /* 0x800AD8BC */
    sw_(R[29] + 32, R[2]);  /* 0x800AD8C0 */
    R[2] = lw_(R[18]);  /* 0x800AD8C4 */
    R[19] = R[19] + 16;  /* 0x800AD8C8 */
    sw_(R[29] + 36, R[0]);  /* 0x800AD8CC */
    R[2] = R[2] - R[23];  /* 0x800AD8D0 */
    { R[31] = 0x800AD8DCu; sw_(R[29] + 40, R[2]); psx_next = 0x800270ACu; return; }  /* 0x800AD8D4 jal */
    R[25] = lw_(R[29] + 52);  /* 0x800AD8DC */
    R[3] = lw_(R[29] + 32);  /* 0x800AD8E0 */
    R[2] = R[0] - R[25];  /* 0x800AD8E4 */
    sw_(R[16] + 4, R[2]);  /* 0x800AD8E8 */
    R[2] = R[3] << 1;  /* 0x800AD8EC */
    R[2] = R[2] + R[3];  /* 0x800AD8F0 */
    R[2] = R[2] << 3;  /* 0x800AD8F4 */
    R[2] = R[2] + R[3];  /* 0x800AD8F8 */
    R[2] = R[2] << 2;  /* 0x800AD8FC */
    R[2] = R[2] + R[30];  /* 0x800AD900 */
    sw_(R[16], R[2]);  /* 0x800AD904 */
    R[3] = lw_(R[29] + 40);  /* 0x800AD908 */
    R[18] = R[18] + 16;  /* 0x800AD90C */
    R[2] = R[3] << 1;  /* 0x800AD910 */
    R[2] = R[2] + R[3];  /* 0x800AD914 */
    R[2] = R[2] << 3;  /* 0x800AD918 */
    R[2] = R[2] + R[3];  /* 0x800AD91C */
    R[2] = R[2] << 2;  /* 0x800AD920 */
    R[2] = R[2] + R[23];  /* 0x800AD924 */
    sw_(R[16] + 8, R[2]);  /* 0x800AD928 */
    { R[16] = R[16] + 12; psx_bb(); goto L_800AD89C; }  /* 0x800AD92C j */
L_800AD934:;
    { uint32_t _c = (R[20] == R[0]); R[2] = 0x5555u << 16; if (_c) { goto L_800ADB6C; } }  /* 0x800AD934 */
    R[2] = R[2] | 0x5556;  /* 0x800AD93C */
    R[5] = R[20] + 2;  /* 0x800AD940 */
    { int64_t _p = (int64_t)(int32_t)R[5] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800AD944 */
    R[4] = 0x8011u << 16;  /* 0x800AD948 */
    R[4] = R[4] + 30268;  /* 0x800AD94C */
    R[6] = R[0] + R[0];  /* 0x800AD950 */
    R[5] = (uint32_t)((int32_t)R[5] >> 31);  /* 0x800AD954 */
    R[14] = HI;  /* 0x800AD958 */
    { R[31] = 0x800AD964u; R[5] = R[14] - R[5]; psx_next = 0x80025598u; return; }  /* 0x800AD95C jal */
    R[2] = 0x8013u << 16;  /* 0x800AD964 */
    R[20] = R[2] - 29656;  /* 0x800AD968 */
    R[16] = R[0] + 168;  /* 0x800AD96C */
    R[15] = R[0] + 240;  /* 0x800AD970 */
    R[8] = R[0] + 255;  /* 0x800AD974 */
    R[2] = 0x8005u << 16;  /* 0x800AD978 */
    R[18] = R[2] - 888;  /* 0x800AD97C */
    R[6] = 0xFFu << 16;  /* 0x800AD980 */
    R[6] = R[6] | 0xFFFF;  /* 0x800AD984 */
    R[7] = 0xFF00u << 16;  /* 0x800AD988 */
    R[2] = 0x8013u << 16;  /* 0x800AD98C */
    R[2] = lw_(R[2] + 4152);  /* 0x800AD990 */
    R[5] = R[21] + R[0];  /* 0x800AD994 */
    R[19] = lw_(R[2] + 536);  /* 0x800AD998 */
    R[10] = R[17] + 22;  /* 0x800AD99C */
    R[13] = R[19] + 12;  /* 0x800AD9A0 */
L_800AD9A4:;
    R[2] = lh_(R[19]);  /* 0x800AD9A4 */
    R[2] = R[2] & 0x8000;  /* 0x800AD9AC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x1Fu << 16; if (_c) { goto L_800ADB6C; } }  /* 0x800AD9B0 */
    R[2] = R[2] | 0x3FFF;  /* 0x800AD9B8 */
    R[22] = 0x8011u << 16;  /* 0x800AD9BC */
    R[22] = R[22] + 29992;  /* 0x800AD9C0 */
    R[3] = lw_(R[13] + -4);  /* 0x800AD9C4 */
    R[4] = lw_(R[22] + 144);  /* 0x800AD9C8 */
    R[3] = R[0] - R[3];  /* 0x800AD9CC */
    R[3] = R[3] - R[4];  /* 0x800AD9D0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800AD9E0; } }  /* 0x800AD9D4 */
    R[3] = R[0] - R[3];  /* 0x800AD9DC */
L_800AD9E0:;
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x800AD9E0 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800ADB5C; } }  /* 0x800AD9E4 */
    R[2] = lw_(R[13] + -8);  /* 0x800AD9EC */
    R[2] = R[2] - R[30];  /* 0x800AD9F4 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[9] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_800ADA08; } }  /* 0x800AD9F8 */
    R[2] = R[2] + 4095;  /* 0x800ADA00 */
    R[9] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800ADA04 */
L_800ADA08:;
    { uint32_t _c = ((int32_t)R[9] >= 0); if (_c) { goto L_800ADA14; } }  /* 0x800ADA08 */
    R[9] = R[0] - R[9];  /* 0x800ADA10 */
L_800ADA14:;
    { int64_t _p = (int64_t)(int32_t)R[9] * (int32_t)R[9]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800ADA14 */
    R[2] = lw_(R[13]);  /* 0x800ADA18 */
    R[2] = R[2] - R[23];  /* 0x800ADA20 */
    R[9] = LO;  /* 0x800ADA24 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800ADA34; } }  /* 0x800ADA28 */
    R[2] = R[2] + 4095;  /* 0x800ADA30 */
L_800ADA34:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800ADA34 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800ADA44; } }  /* 0x800ADA38 */
    R[2] = R[0] - R[2];  /* 0x800ADA40 */
L_800ADA44:;
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800ADA44 */
    R[3] = 0x774Du << 16;  /* 0x800ADA48 */
    R[2] = LO;  /* 0x800ADA4C */
    R[3] = R[3] | 0xFD5B;  /* 0x800ADA50 */
    R[9] = R[9] + R[2];  /* 0x800ADA54 */
    { int64_t _p = (int64_t)(int32_t)R[9] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800ADA58 */
    R[4] = lw_(R[20] + 36);  /* 0x800ADA5C */
    R[2] = (uint32_t)((int32_t)R[9] >> 31);  /* 0x800ADA60 */
    R[3] = HI;  /* 0x800ADA64 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800ADA68 */
    R[3] = R[3] - R[2];  /* 0x800ADA6C */
    R[2] = R[0] + 64;  /* 0x800ADA70 */
    R[9] = R[2] - R[3];  /* 0x800ADA74 */
    R[9] = R[9] + R[4];  /* 0x800ADA78 */
    R[2] = ((int32_t)R[9] < 129);  /* 0x800ADA7C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800ADA8C; } }  /* 0x800ADA80 */
    R[9] = R[0] + 128;  /* 0x800ADA88 */
L_800ADA8C:;
    { uint32_t _c = ((int32_t)R[9] <= 0); R[2] = R[0] + 9; if (_c) { goto L_800ADB5C; } }  /* 0x800ADA8C */
    R[11] = (uint32_t)(int16_t)lh_(R[5] + 544);  /* 0x800ADA94 */
    R[12] = (uint32_t)(int16_t)lh_(R[5] + 546);  /* 0x800ADA98 */
    sb_(R[10] + -19, R[2]);  /* 0x800ADA9C */
    R[2] = R[0] + 46;  /* 0x800ADAA0 */
    R[14] = R[0] + 183;  /* 0x800ADAA4 */
    R[22] = R[14] + R[0];  /* 0x800ADAA8 */
    sb_(R[10] + -15, R[2]);  /* 0x800ADAAC */
    sb_(R[10] + -18, R[9]);  /* 0x800ADAB0 */
    sb_(R[10] + -17, R[9]);  /* 0x800ADAB4 */
    sb_(R[10] + -16, R[9]);  /* 0x800ADAB8 */
    sb_(R[10] + -10, R[16]);  /* 0x800ADABC */
    sb_(R[10] + -9, R[15]);  /* 0x800ADAC0 */
    sb_(R[10] + -2, R[14]);  /* 0x800ADAC4 */
    sb_(R[10] + -1, R[15]);  /* 0x800ADAC8 */
    sb_(R[10] + 6, R[16]);  /* 0x800ADACC */
    sb_(R[10] + 7, R[8]);  /* 0x800ADAD0 */
    sb_(R[10] + 14, R[22]);  /* 0x800ADAD4 */
    sb_(R[10] + 15, R[8]);  /* 0x800ADAD8 */
    R[24] = lh_(R[29] + 56);  /* 0x800ADADC */
    R[4] = R[11] - R[24];  /* 0x800ADAE4 */
    R[2] = R[12] - R[24];  /* 0x800ADAE8 */
    R[3] = R[24] + R[11];  /* 0x800ADAEC */
    sh_(R[10] + -12, R[2]);  /* 0x800ADAF0 */
    sh_(R[10] + -4, R[2]);  /* 0x800ADAF4 */
    R[2] = R[24] + R[12];  /* 0x800ADAF8 */
    sh_(R[10] + -14, R[4]);  /* 0x800ADAFC */
    sh_(R[10] + -6, R[3]);  /* 0x800ADB00 */
    sh_(R[10] + 2, R[4]);  /* 0x800ADB04 */
    sh_(R[10] + 4, R[2]);  /* 0x800ADB08 */
    sh_(R[10] + 10, R[3]);  /* 0x800ADB0C */
    sh_(R[10] + 12, R[2]);  /* 0x800ADB10 */
    R[3] = lh_(R[18] + 26);  /* 0x800ADB14 */
    R[2] = R[0] + 57;  /* 0x800ADB18 */
    sh_(R[10], R[2]);  /* 0x800ADB1C */
    sh_(R[10] + -8, R[3]);  /* 0x800ADB20 */
    R[10] = R[10] + 40;  /* 0x800ADB24 */
    R[25] = lw_(R[29] + 48);  /* 0x800ADB28 */
    R[3] = lw_(R[17]);  /* 0x800ADB2C */
    R[2] = lw_(R[25]);  /* 0x800ADB30 */
    R[3] = R[3] & R[7];  /* 0x800ADB34 */
    R[2] = R[2] & R[6];  /* 0x800ADB38 */
    R[3] = R[3] | R[2];  /* 0x800ADB3C */
    sw_(R[17], R[3]);  /* 0x800ADB40 */
    R[3] = R[17] & R[6];  /* 0x800ADB44 */
    R[2] = lw_(R[25]);  /* 0x800ADB48 */
    R[17] = R[17] + 40;  /* 0x800ADB4C */
    R[2] = R[2] & R[7];  /* 0x800ADB50 */
    R[2] = R[2] | R[3];  /* 0x800ADB54 */
    sw_(R[25], R[2]);  /* 0x800ADB58 */
L_800ADB5C:;
    R[13] = R[13] + 16;  /* 0x800ADB5C */
    R[19] = R[19] + 16;  /* 0x800ADB60 */
    { R[5] = R[5] + 8; psx_bb(); goto L_800AD9A4; }  /* 0x800ADB64 j */
L_800ADB6C:;
    R[3] = 0x1u << 16;  /* 0x800ADB6C */
    R[3] = R[3] | 0x8000;  /* 0x800ADB70 */
    R[2] = 0x800Fu << 16;  /* 0x800ADB74 */
    R[2] = R[2] + 25528;  /* 0x800ADB78 */
    R[2] = R[2] + R[3];  /* 0x800ADB7C */
    sw_(R[2] + 20496, R[17]);  /* 0x800ADB80 */
    R[31] = lw_(R[29] + 100);  /* 0x800ADB84 */
    R[30] = lw_(R[29] + 96);  /* 0x800ADB88 */
    R[23] = lw_(R[29] + 92);  /* 0x800ADB8C */
    R[22] = lw_(R[29] + 88);  /* 0x800ADB90 */
    R[21] = lw_(R[29] + 84);  /* 0x800ADB94 */
    R[20] = lw_(R[29] + 80);  /* 0x800ADB98 */
    R[19] = lw_(R[29] + 76);  /* 0x800ADB9C */
    R[18] = lw_(R[29] + 72);  /* 0x800ADBA0 */
    R[17] = lw_(R[29] + 68);  /* 0x800ADBA4 */
    R[16] = lw_(R[29] + 64);  /* 0x800ADBA8 */
    { R[29] = R[29] + 104; psx_next = R[31]; return; }  /* 0x800ADBAC jr ra */
}

void g0_800AD8DC(void) {
    R[25] = lw_(R[29] + 52);  /* 0x800AD8DC */
    R[3] = lw_(R[29] + 32);  /* 0x800AD8E0 */
    R[2] = R[0] - R[25];  /* 0x800AD8E4 */
    sw_(R[16] + 4, R[2]);  /* 0x800AD8E8 */
    R[2] = R[3] << 1;  /* 0x800AD8EC */
    R[2] = R[2] + R[3];  /* 0x800AD8F0 */
    R[2] = R[2] << 3;  /* 0x800AD8F4 */
    R[2] = R[2] + R[3];  /* 0x800AD8F8 */
    R[2] = R[2] << 2;  /* 0x800AD8FC */
    R[2] = R[2] + R[30];  /* 0x800AD900 */
    sw_(R[16], R[2]);  /* 0x800AD904 */
    R[3] = lw_(R[29] + 40);  /* 0x800AD908 */
    R[18] = R[18] + 16;  /* 0x800AD90C */
    R[2] = R[3] << 1;  /* 0x800AD910 */
    R[2] = R[2] + R[3];  /* 0x800AD914 */
    R[2] = R[2] << 3;  /* 0x800AD918 */
    R[2] = R[2] + R[3];  /* 0x800AD91C */
    R[2] = R[2] << 2;  /* 0x800AD920 */
    R[2] = R[2] + R[23];  /* 0x800AD924 */
    sw_(R[16] + 8, R[2]);  /* 0x800AD928 */
    { R[16] = R[16] + 12; psx_next = 0x800AD89Cu; return; }  /* 0x800AD92C j extern */
    { uint32_t _c = (R[20] == R[0]); R[2] = 0x5555u << 16; if (_c) { goto L_800ADB6C; } }  /* 0x800AD934 */
    R[2] = R[2] | 0x5556;  /* 0x800AD93C */
    R[5] = R[20] + 2;  /* 0x800AD940 */
    { int64_t _p = (int64_t)(int32_t)R[5] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800AD944 */
    R[4] = 0x8011u << 16;  /* 0x800AD948 */
    R[4] = R[4] + 30268;  /* 0x800AD94C */
    R[6] = R[0] + R[0];  /* 0x800AD950 */
    R[5] = (uint32_t)((int32_t)R[5] >> 31);  /* 0x800AD954 */
    R[14] = HI;  /* 0x800AD958 */
    { R[31] = 0x800AD964u; R[5] = R[14] - R[5]; psx_next = 0x80025598u; return; }  /* 0x800AD95C jal */
    R[2] = 0x8013u << 16;  /* 0x800AD964 */
    R[20] = R[2] - 29656;  /* 0x800AD968 */
    R[16] = R[0] + 168;  /* 0x800AD96C */
    R[15] = R[0] + 240;  /* 0x800AD970 */
    R[8] = R[0] + 255;  /* 0x800AD974 */
    R[2] = 0x8005u << 16;  /* 0x800AD978 */
    R[18] = R[2] - 888;  /* 0x800AD97C */
    R[6] = 0xFFu << 16;  /* 0x800AD980 */
    R[6] = R[6] | 0xFFFF;  /* 0x800AD984 */
    R[7] = 0xFF00u << 16;  /* 0x800AD988 */
    R[2] = 0x8013u << 16;  /* 0x800AD98C */
    R[2] = lw_(R[2] + 4152);  /* 0x800AD990 */
    R[5] = R[21] + R[0];  /* 0x800AD994 */
    R[19] = lw_(R[2] + 536);  /* 0x800AD998 */
    R[10] = R[17] + 22;  /* 0x800AD99C */
    R[13] = R[19] + 12;  /* 0x800AD9A0 */
L_800AD9A4:;
    R[2] = lh_(R[19]);  /* 0x800AD9A4 */
    R[2] = R[2] & 0x8000;  /* 0x800AD9AC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x1Fu << 16; if (_c) { goto L_800ADB6C; } }  /* 0x800AD9B0 */
    R[2] = R[2] | 0x3FFF;  /* 0x800AD9B8 */
    R[22] = 0x8011u << 16;  /* 0x800AD9BC */
    R[22] = R[22] + 29992;  /* 0x800AD9C0 */
    R[3] = lw_(R[13] + -4);  /* 0x800AD9C4 */
    R[4] = lw_(R[22] + 144);  /* 0x800AD9C8 */
    R[3] = R[0] - R[3];  /* 0x800AD9CC */
    R[3] = R[3] - R[4];  /* 0x800AD9D0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800AD9E0; } }  /* 0x800AD9D4 */
    R[3] = R[0] - R[3];  /* 0x800AD9DC */
L_800AD9E0:;
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x800AD9E0 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800ADB5C; } }  /* 0x800AD9E4 */
    R[2] = lw_(R[13] + -8);  /* 0x800AD9EC */
    R[2] = R[2] - R[30];  /* 0x800AD9F4 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[9] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_800ADA08; } }  /* 0x800AD9F8 */
    R[2] = R[2] + 4095;  /* 0x800ADA00 */
    R[9] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800ADA04 */
L_800ADA08:;
    { uint32_t _c = ((int32_t)R[9] >= 0); if (_c) { goto L_800ADA14; } }  /* 0x800ADA08 */
    R[9] = R[0] - R[9];  /* 0x800ADA10 */
L_800ADA14:;
    { int64_t _p = (int64_t)(int32_t)R[9] * (int32_t)R[9]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800ADA14 */
    R[2] = lw_(R[13]);  /* 0x800ADA18 */
    R[2] = R[2] - R[23];  /* 0x800ADA20 */
    R[9] = LO;  /* 0x800ADA24 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800ADA34; } }  /* 0x800ADA28 */
    R[2] = R[2] + 4095;  /* 0x800ADA30 */
L_800ADA34:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800ADA34 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800ADA44; } }  /* 0x800ADA38 */
    R[2] = R[0] - R[2];  /* 0x800ADA40 */
L_800ADA44:;
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800ADA44 */
    R[3] = 0x774Du << 16;  /* 0x800ADA48 */
    R[2] = LO;  /* 0x800ADA4C */
    R[3] = R[3] | 0xFD5B;  /* 0x800ADA50 */
    R[9] = R[9] + R[2];  /* 0x800ADA54 */
    { int64_t _p = (int64_t)(int32_t)R[9] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800ADA58 */
    R[4] = lw_(R[20] + 36);  /* 0x800ADA5C */
    R[2] = (uint32_t)((int32_t)R[9] >> 31);  /* 0x800ADA60 */
    R[3] = HI;  /* 0x800ADA64 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800ADA68 */
    R[3] = R[3] - R[2];  /* 0x800ADA6C */
    R[2] = R[0] + 64;  /* 0x800ADA70 */
    R[9] = R[2] - R[3];  /* 0x800ADA74 */
    R[9] = R[9] + R[4];  /* 0x800ADA78 */
    R[2] = ((int32_t)R[9] < 129);  /* 0x800ADA7C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800ADA8C; } }  /* 0x800ADA80 */
    R[9] = R[0] + 128;  /* 0x800ADA88 */
L_800ADA8C:;
    { uint32_t _c = ((int32_t)R[9] <= 0); R[2] = R[0] + 9; if (_c) { goto L_800ADB5C; } }  /* 0x800ADA8C */
    R[11] = (uint32_t)(int16_t)lh_(R[5] + 544);  /* 0x800ADA94 */
    R[12] = (uint32_t)(int16_t)lh_(R[5] + 546);  /* 0x800ADA98 */
    sb_(R[10] + -19, R[2]);  /* 0x800ADA9C */
    R[2] = R[0] + 46;  /* 0x800ADAA0 */
    R[14] = R[0] + 183;  /* 0x800ADAA4 */
    R[22] = R[14] + R[0];  /* 0x800ADAA8 */
    sb_(R[10] + -15, R[2]);  /* 0x800ADAAC */
    sb_(R[10] + -18, R[9]);  /* 0x800ADAB0 */
    sb_(R[10] + -17, R[9]);  /* 0x800ADAB4 */
    sb_(R[10] + -16, R[9]);  /* 0x800ADAB8 */
    sb_(R[10] + -10, R[16]);  /* 0x800ADABC */
    sb_(R[10] + -9, R[15]);  /* 0x800ADAC0 */
    sb_(R[10] + -2, R[14]);  /* 0x800ADAC4 */
    sb_(R[10] + -1, R[15]);  /* 0x800ADAC8 */
    sb_(R[10] + 6, R[16]);  /* 0x800ADACC */
    sb_(R[10] + 7, R[8]);  /* 0x800ADAD0 */
    sb_(R[10] + 14, R[22]);  /* 0x800ADAD4 */
    sb_(R[10] + 15, R[8]);  /* 0x800ADAD8 */
    R[24] = lh_(R[29] + 56);  /* 0x800ADADC */
    R[4] = R[11] - R[24];  /* 0x800ADAE4 */
    R[2] = R[12] - R[24];  /* 0x800ADAE8 */
    R[3] = R[24] + R[11];  /* 0x800ADAEC */
    sh_(R[10] + -12, R[2]);  /* 0x800ADAF0 */
    sh_(R[10] + -4, R[2]);  /* 0x800ADAF4 */
    R[2] = R[24] + R[12];  /* 0x800ADAF8 */
    sh_(R[10] + -14, R[4]);  /* 0x800ADAFC */
    sh_(R[10] + -6, R[3]);  /* 0x800ADB00 */
    sh_(R[10] + 2, R[4]);  /* 0x800ADB04 */
    sh_(R[10] + 4, R[2]);  /* 0x800ADB08 */
    sh_(R[10] + 10, R[3]);  /* 0x800ADB0C */
    sh_(R[10] + 12, R[2]);  /* 0x800ADB10 */
    R[3] = lh_(R[18] + 26);  /* 0x800ADB14 */
    R[2] = R[0] + 57;  /* 0x800ADB18 */
    sh_(R[10], R[2]);  /* 0x800ADB1C */
    sh_(R[10] + -8, R[3]);  /* 0x800ADB20 */
    R[10] = R[10] + 40;  /* 0x800ADB24 */
    R[25] = lw_(R[29] + 48);  /* 0x800ADB28 */
    R[3] = lw_(R[17]);  /* 0x800ADB2C */
    R[2] = lw_(R[25]);  /* 0x800ADB30 */
    R[3] = R[3] & R[7];  /* 0x800ADB34 */
    R[2] = R[2] & R[6];  /* 0x800ADB38 */
    R[3] = R[3] | R[2];  /* 0x800ADB3C */
    sw_(R[17], R[3]);  /* 0x800ADB40 */
    R[3] = R[17] & R[6];  /* 0x800ADB44 */
    R[2] = lw_(R[25]);  /* 0x800ADB48 */
    R[17] = R[17] + 40;  /* 0x800ADB4C */
    R[2] = R[2] & R[7];  /* 0x800ADB50 */
    R[2] = R[2] | R[3];  /* 0x800ADB54 */
    sw_(R[25], R[2]);  /* 0x800ADB58 */
L_800ADB5C:;
    R[13] = R[13] + 16;  /* 0x800ADB5C */
    R[19] = R[19] + 16;  /* 0x800ADB60 */
    { R[5] = R[5] + 8; psx_bb(); goto L_800AD9A4; }  /* 0x800ADB64 j */
L_800ADB6C:;
    R[3] = 0x1u << 16;  /* 0x800ADB6C */
    R[3] = R[3] | 0x8000;  /* 0x800ADB70 */
    R[2] = 0x800Fu << 16;  /* 0x800ADB74 */
    R[2] = R[2] + 25528;  /* 0x800ADB78 */
    R[2] = R[2] + R[3];  /* 0x800ADB7C */
    sw_(R[2] + 20496, R[17]);  /* 0x800ADB80 */
    R[31] = lw_(R[29] + 100);  /* 0x800ADB84 */
    R[30] = lw_(R[29] + 96);  /* 0x800ADB88 */
    R[23] = lw_(R[29] + 92);  /* 0x800ADB8C */
    R[22] = lw_(R[29] + 88);  /* 0x800ADB90 */
    R[21] = lw_(R[29] + 84);  /* 0x800ADB94 */
    R[20] = lw_(R[29] + 80);  /* 0x800ADB98 */
    R[19] = lw_(R[29] + 76);  /* 0x800ADB9C */
    R[18] = lw_(R[29] + 72);  /* 0x800ADBA0 */
    R[17] = lw_(R[29] + 68);  /* 0x800ADBA4 */
    R[16] = lw_(R[29] + 64);  /* 0x800ADBA8 */
    { R[29] = R[29] + 104; psx_next = R[31]; return; }  /* 0x800ADBAC jr ra */
}

void g0_800AD964(void) {
    R[2] = 0x8013u << 16;  /* 0x800AD964 */
    R[20] = R[2] - 29656;  /* 0x800AD968 */
    R[16] = R[0] + 168;  /* 0x800AD96C */
    R[15] = R[0] + 240;  /* 0x800AD970 */
    R[8] = R[0] + 255;  /* 0x800AD974 */
    R[2] = 0x8005u << 16;  /* 0x800AD978 */
    R[18] = R[2] - 888;  /* 0x800AD97C */
    R[6] = 0xFFu << 16;  /* 0x800AD980 */
    R[6] = R[6] | 0xFFFF;  /* 0x800AD984 */
    R[7] = 0xFF00u << 16;  /* 0x800AD988 */
    R[2] = 0x8013u << 16;  /* 0x800AD98C */
    R[2] = lw_(R[2] + 4152);  /* 0x800AD990 */
    R[5] = R[21] + R[0];  /* 0x800AD994 */
    R[19] = lw_(R[2] + 536);  /* 0x800AD998 */
    R[10] = R[17] + 22;  /* 0x800AD99C */
    R[13] = R[19] + 12;  /* 0x800AD9A0 */
L_800AD9A4:;
    R[2] = lh_(R[19]);  /* 0x800AD9A4 */
    R[2] = R[2] & 0x8000;  /* 0x800AD9AC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x1Fu << 16; if (_c) { goto L_800ADB6C; } }  /* 0x800AD9B0 */
    R[2] = R[2] | 0x3FFF;  /* 0x800AD9B8 */
    R[22] = 0x8011u << 16;  /* 0x800AD9BC */
    R[22] = R[22] + 29992;  /* 0x800AD9C0 */
    R[3] = lw_(R[13] + -4);  /* 0x800AD9C4 */
    R[4] = lw_(R[22] + 144);  /* 0x800AD9C8 */
    R[3] = R[0] - R[3];  /* 0x800AD9CC */
    R[3] = R[3] - R[4];  /* 0x800AD9D0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800AD9E0; } }  /* 0x800AD9D4 */
    R[3] = R[0] - R[3];  /* 0x800AD9DC */
L_800AD9E0:;
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x800AD9E0 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800ADB5C; } }  /* 0x800AD9E4 */
    R[2] = lw_(R[13] + -8);  /* 0x800AD9EC */
    R[2] = R[2] - R[30];  /* 0x800AD9F4 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[9] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_800ADA08; } }  /* 0x800AD9F8 */
    R[2] = R[2] + 4095;  /* 0x800ADA00 */
    R[9] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800ADA04 */
L_800ADA08:;
    { uint32_t _c = ((int32_t)R[9] >= 0); if (_c) { goto L_800ADA14; } }  /* 0x800ADA08 */
    R[9] = R[0] - R[9];  /* 0x800ADA10 */
L_800ADA14:;
    { int64_t _p = (int64_t)(int32_t)R[9] * (int32_t)R[9]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800ADA14 */
    R[2] = lw_(R[13]);  /* 0x800ADA18 */
    R[2] = R[2] - R[23];  /* 0x800ADA20 */
    R[9] = LO;  /* 0x800ADA24 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800ADA34; } }  /* 0x800ADA28 */
    R[2] = R[2] + 4095;  /* 0x800ADA30 */
L_800ADA34:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800ADA34 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800ADA44; } }  /* 0x800ADA38 */
    R[2] = R[0] - R[2];  /* 0x800ADA40 */
L_800ADA44:;
    { int64_t _p = (int64_t)(int32_t)R[2] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800ADA44 */
    R[3] = 0x774Du << 16;  /* 0x800ADA48 */
    R[2] = LO;  /* 0x800ADA4C */
    R[3] = R[3] | 0xFD5B;  /* 0x800ADA50 */
    R[9] = R[9] + R[2];  /* 0x800ADA54 */
    { int64_t _p = (int64_t)(int32_t)R[9] * (int32_t)R[3]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800ADA58 */
    R[4] = lw_(R[20] + 36);  /* 0x800ADA5C */
    R[2] = (uint32_t)((int32_t)R[9] >> 31);  /* 0x800ADA60 */
    R[3] = HI;  /* 0x800ADA64 */
    R[3] = (uint32_t)((int32_t)R[3] >> 16);  /* 0x800ADA68 */
    R[3] = R[3] - R[2];  /* 0x800ADA6C */
    R[2] = R[0] + 64;  /* 0x800ADA70 */
    R[9] = R[2] - R[3];  /* 0x800ADA74 */
    R[9] = R[9] + R[4];  /* 0x800ADA78 */
    R[2] = ((int32_t)R[9] < 129);  /* 0x800ADA7C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800ADA8C; } }  /* 0x800ADA80 */
    R[9] = R[0] + 128;  /* 0x800ADA88 */
L_800ADA8C:;
    { uint32_t _c = ((int32_t)R[9] <= 0); R[2] = R[0] + 9; if (_c) { goto L_800ADB5C; } }  /* 0x800ADA8C */
    R[11] = (uint32_t)(int16_t)lh_(R[5] + 544);  /* 0x800ADA94 */
    R[12] = (uint32_t)(int16_t)lh_(R[5] + 546);  /* 0x800ADA98 */
    sb_(R[10] + -19, R[2]);  /* 0x800ADA9C */
    R[2] = R[0] + 46;  /* 0x800ADAA0 */
    R[14] = R[0] + 183;  /* 0x800ADAA4 */
    R[22] = R[14] + R[0];  /* 0x800ADAA8 */
    sb_(R[10] + -15, R[2]);  /* 0x800ADAAC */
    sb_(R[10] + -18, R[9]);  /* 0x800ADAB0 */
    sb_(R[10] + -17, R[9]);  /* 0x800ADAB4 */
    sb_(R[10] + -16, R[9]);  /* 0x800ADAB8 */
    sb_(R[10] + -10, R[16]);  /* 0x800ADABC */
    sb_(R[10] + -9, R[15]);  /* 0x800ADAC0 */
    sb_(R[10] + -2, R[14]);  /* 0x800ADAC4 */
    sb_(R[10] + -1, R[15]);  /* 0x800ADAC8 */
    sb_(R[10] + 6, R[16]);  /* 0x800ADACC */
    sb_(R[10] + 7, R[8]);  /* 0x800ADAD0 */
    sb_(R[10] + 14, R[22]);  /* 0x800ADAD4 */
    sb_(R[10] + 15, R[8]);  /* 0x800ADAD8 */
    R[24] = lh_(R[29] + 56);  /* 0x800ADADC */
    R[4] = R[11] - R[24];  /* 0x800ADAE4 */
    R[2] = R[12] - R[24];  /* 0x800ADAE8 */
    R[3] = R[24] + R[11];  /* 0x800ADAEC */
    sh_(R[10] + -12, R[2]);  /* 0x800ADAF0 */
    sh_(R[10] + -4, R[2]);  /* 0x800ADAF4 */
    R[2] = R[24] + R[12];  /* 0x800ADAF8 */
    sh_(R[10] + -14, R[4]);  /* 0x800ADAFC */
    sh_(R[10] + -6, R[3]);  /* 0x800ADB00 */
    sh_(R[10] + 2, R[4]);  /* 0x800ADB04 */
    sh_(R[10] + 4, R[2]);  /* 0x800ADB08 */
    sh_(R[10] + 10, R[3]);  /* 0x800ADB0C */
    sh_(R[10] + 12, R[2]);  /* 0x800ADB10 */
    R[3] = lh_(R[18] + 26);  /* 0x800ADB14 */
    R[2] = R[0] + 57;  /* 0x800ADB18 */
    sh_(R[10], R[2]);  /* 0x800ADB1C */
    sh_(R[10] + -8, R[3]);  /* 0x800ADB20 */
    R[10] = R[10] + 40;  /* 0x800ADB24 */
    R[25] = lw_(R[29] + 48);  /* 0x800ADB28 */
    R[3] = lw_(R[17]);  /* 0x800ADB2C */
    R[2] = lw_(R[25]);  /* 0x800ADB30 */
    R[3] = R[3] & R[7];  /* 0x800ADB34 */
    R[2] = R[2] & R[6];  /* 0x800ADB38 */
    R[3] = R[3] | R[2];  /* 0x800ADB3C */
    sw_(R[17], R[3]);  /* 0x800ADB40 */
    R[3] = R[17] & R[6];  /* 0x800ADB44 */
    R[2] = lw_(R[25]);  /* 0x800ADB48 */
    R[17] = R[17] + 40;  /* 0x800ADB4C */
    R[2] = R[2] & R[7];  /* 0x800ADB50 */
    R[2] = R[2] | R[3];  /* 0x800ADB54 */
    sw_(R[25], R[2]);  /* 0x800ADB58 */
L_800ADB5C:;
    R[13] = R[13] + 16;  /* 0x800ADB5C */
    R[19] = R[19] + 16;  /* 0x800ADB60 */
    { R[5] = R[5] + 8; psx_bb(); goto L_800AD9A4; }  /* 0x800ADB64 j */
L_800ADB6C:;
    R[3] = 0x1u << 16;  /* 0x800ADB6C */
    R[3] = R[3] | 0x8000;  /* 0x800ADB70 */
    R[2] = 0x800Fu << 16;  /* 0x800ADB74 */
    R[2] = R[2] + 25528;  /* 0x800ADB78 */
    R[2] = R[2] + R[3];  /* 0x800ADB7C */
    sw_(R[2] + 20496, R[17]);  /* 0x800ADB80 */
    R[31] = lw_(R[29] + 100);  /* 0x800ADB84 */
    R[30] = lw_(R[29] + 96);  /* 0x800ADB88 */
    R[23] = lw_(R[29] + 92);  /* 0x800ADB8C */
    R[22] = lw_(R[29] + 88);  /* 0x800ADB90 */
    R[21] = lw_(R[29] + 84);  /* 0x800ADB94 */
    R[20] = lw_(R[29] + 80);  /* 0x800ADB98 */
    R[19] = lw_(R[29] + 76);  /* 0x800ADB9C */
    R[18] = lw_(R[29] + 72);  /* 0x800ADBA0 */
    R[17] = lw_(R[29] + 68);  /* 0x800ADBA4 */
    R[16] = lw_(R[29] + 64);  /* 0x800ADBA8 */
    { R[29] = R[29] + 104; psx_next = R[31]; return; }  /* 0x800ADBAC jr ra */
}

void g0_800ADBB4(void) {
    R[2] = 0x8013u << 16;  /* 0x800ADBB4 */
    R[2] = R[2] + 9480;  /* 0x800ADBB8 */
    R[3] = R[0] - 1;  /* 0x800ADBBC */
    sh_(R[2] + 3074, R[3]);  /* 0x800ADBC0 */
    sh_(R[2] + 3076, R[3]);  /* 0x800ADBC4 */
    { sw_(R[2] + 3080, R[0]); psx_next = R[31]; return; }  /* 0x800ADBC8 jr ra */
}

void g0_800ADBD0(void) {
    R[29] = R[29] - 304;  /* 0x800ADBD0 */
    R[8] = R[4] + R[0];  /* 0x800ADBD4 */
    R[2] = R[0] - 1;  /* 0x800ADBD8 */
    sw_(R[29] + 300, R[31]);  /* 0x800ADBDC */
    { uint32_t _c = (R[8] == R[2]); sw_(R[29] + 296, R[16]); if (_c) { goto L_800ADCB0; } }  /* 0x800ADBE0 */
    R[2] = ((int32_t)R[8] < 14);  /* 0x800ADBE8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_800ADC1C; } }  /* 0x800ADBEC */
    R[16] = R[29] + 40;  /* 0x800ADBF4 */
    R[4] = R[16] + R[0];  /* 0x800ADBF8 */
    R[5] = 0x8008u << 16;  /* 0x800ADBFC */
    R[5] = R[5] + 9432;  /* 0x800ADC00 */
    { R[31] = 0x800ADC0Cu; R[6] = R[8] + R[0]; psx_next = 0x80031BF8u; return; }  /* 0x800ADC04 jal */
    { R[31] = 0x800ADC14u; R[4] = R[16] + R[0]; psx_next = 0x8001BBF8u; return; }  /* 0x800ADC0C jal */
    { R[31] = 0x800ADC1Cu; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x800ADC14 jal */
L_800ADC1C:;
    R[16] = R[2] + 9480;  /* 0x800ADC1C */
    R[2] = R[0] + 768;  /* 0x800ADC20 */
    sh_(R[16] + 3074, R[8]);  /* 0x800ADC24 */
    sh_(R[16] + 3084, R[5]);  /* 0x800ADC28 */
    sh_(R[16] + 3086, R[6]);  /* 0x800ADC2C */
    sw_(R[16] + 3080, R[0]);  /* 0x800ADC30 */
    sh_(R[16] + 3078, R[7]);  /* 0x800ADC34 */
    sh_(R[29] + 24, R[2]);  /* 0x800ADC38 */
    R[2] = R[0] + 507;  /* 0x800ADC3C */
    sh_(R[29] + 26, R[2]);  /* 0x800ADC40 */
    R[2] = R[0] + 256;  /* 0x800ADC44 */
    sh_(R[29] + 28, R[2]);  /* 0x800ADC48 */
    R[2] = R[0] + 1;  /* 0x800ADC4C */
    sh_(R[29] + 30, R[2]);  /* 0x800ADC50 */
    R[2] = R[0] + 736;  /* 0x800ADC54 */
    sh_(R[29] + 32, R[2]);  /* 0x800ADC58 */
    R[2] = R[0] + 296;  /* 0x800ADC5C */
    sh_(R[29] + 34, R[2]);  /* 0x800ADC60 */
    R[2] = R[0] + 20;  /* 0x800ADC64 */
    sh_(R[29] + 36, R[2]);  /* 0x800ADC68 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 3076);  /* 0x800ADC6C */
    R[2] = R[0] + 48;  /* 0x800ADC70 */
    { uint32_t _c = (R[8] != R[3]); sh_(R[29] + 38, R[2]); if (_c) { goto L_800ADC84; } }  /* 0x800ADC74 */
    { uint32_t _c = (R[8] != R[0]); if (_c) { goto L_800ADCB0; } }  /* 0x800ADC7C */
L_800ADC84:;
    R[4] = R[16] + R[0];  /* 0x800ADC84 */
    R[5] = R[8] + R[0];  /* 0x800ADC88 */
    R[6] = R[5] + R[0];  /* 0x800ADC8C */
    R[7] = R[0] + 3072;  /* 0x800ADC90 */
    sh_(R[16] + 3076, R[5]);  /* 0x800ADC94 */
    { R[31] = 0x800ADCA0u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800ADC98 jal */
    R[4] = R[16] + R[0];  /* 0x800ADCA0 */
    R[5] = R[29] + 24;  /* 0x800ADCA4 */
    { R[31] = 0x800ADCB0u; R[6] = R[29] + 32; psx_next = 0x8001CA2Cu; return; }  /* 0x800ADCA8 jal */
L_800ADCB0:;
    R[31] = lw_(R[29] + 300);  /* 0x800ADCB0 */
    R[16] = lw_(R[29] + 296);  /* 0x800ADCB4 */
    { R[29] = R[29] + 304; psx_next = R[31]; return; }  /* 0x800ADCB8 jr ra */
}

void g0_800ADC0C(void) {
    { R[31] = 0x800ADC14u; R[4] = R[16] + R[0]; psx_next = 0x8001BBF8u; return; }  /* 0x800ADC0C jal */
    { R[31] = 0x800ADC1Cu; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x800ADC14 jal */
    R[16] = R[2] + 9480;  /* 0x800ADC1C */
    R[2] = R[0] + 768;  /* 0x800ADC20 */
    sh_(R[16] + 3074, R[8]);  /* 0x800ADC24 */
    sh_(R[16] + 3084, R[5]);  /* 0x800ADC28 */
    sh_(R[16] + 3086, R[6]);  /* 0x800ADC2C */
    sw_(R[16] + 3080, R[0]);  /* 0x800ADC30 */
    sh_(R[16] + 3078, R[7]);  /* 0x800ADC34 */
    sh_(R[29] + 24, R[2]);  /* 0x800ADC38 */
    R[2] = R[0] + 507;  /* 0x800ADC3C */
    sh_(R[29] + 26, R[2]);  /* 0x800ADC40 */
    R[2] = R[0] + 256;  /* 0x800ADC44 */
    sh_(R[29] + 28, R[2]);  /* 0x800ADC48 */
    R[2] = R[0] + 1;  /* 0x800ADC4C */
    sh_(R[29] + 30, R[2]);  /* 0x800ADC50 */
    R[2] = R[0] + 736;  /* 0x800ADC54 */
    sh_(R[29] + 32, R[2]);  /* 0x800ADC58 */
    R[2] = R[0] + 296;  /* 0x800ADC5C */
    sh_(R[29] + 34, R[2]);  /* 0x800ADC60 */
    R[2] = R[0] + 20;  /* 0x800ADC64 */
    sh_(R[29] + 36, R[2]);  /* 0x800ADC68 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 3076);  /* 0x800ADC6C */
    R[2] = R[0] + 48;  /* 0x800ADC70 */
    { uint32_t _c = (R[8] != R[3]); sh_(R[29] + 38, R[2]); if (_c) { goto L_800ADC84; } }  /* 0x800ADC74 */
    { uint32_t _c = (R[8] != R[0]); if (_c) { goto L_800ADCB0; } }  /* 0x800ADC7C */
L_800ADC84:;
    R[4] = R[16] + R[0];  /* 0x800ADC84 */
    R[5] = R[8] + R[0];  /* 0x800ADC88 */
    R[6] = R[5] + R[0];  /* 0x800ADC8C */
    R[7] = R[0] + 3072;  /* 0x800ADC90 */
    sh_(R[16] + 3076, R[5]);  /* 0x800ADC94 */
    { R[31] = 0x800ADCA0u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800ADC98 jal */
    R[4] = R[16] + R[0];  /* 0x800ADCA0 */
    R[5] = R[29] + 24;  /* 0x800ADCA4 */
    { R[31] = 0x800ADCB0u; R[6] = R[29] + 32; psx_next = 0x8001CA2Cu; return; }  /* 0x800ADCA8 jal */
L_800ADCB0:;
    R[31] = lw_(R[29] + 300);  /* 0x800ADCB0 */
    R[16] = lw_(R[29] + 296);  /* 0x800ADCB4 */
    { R[29] = R[29] + 304; psx_next = R[31]; return; }  /* 0x800ADCB8 jr ra */
}

void g0_800ADC14(void) {
    { R[31] = 0x800ADC1Cu; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x800ADC14 jal */
    R[16] = R[2] + 9480;  /* 0x800ADC1C */
    R[2] = R[0] + 768;  /* 0x800ADC20 */
    sh_(R[16] + 3074, R[8]);  /* 0x800ADC24 */
    sh_(R[16] + 3084, R[5]);  /* 0x800ADC28 */
    sh_(R[16] + 3086, R[6]);  /* 0x800ADC2C */
    sw_(R[16] + 3080, R[0]);  /* 0x800ADC30 */
    sh_(R[16] + 3078, R[7]);  /* 0x800ADC34 */
    sh_(R[29] + 24, R[2]);  /* 0x800ADC38 */
    R[2] = R[0] + 507;  /* 0x800ADC3C */
    sh_(R[29] + 26, R[2]);  /* 0x800ADC40 */
    R[2] = R[0] + 256;  /* 0x800ADC44 */
    sh_(R[29] + 28, R[2]);  /* 0x800ADC48 */
    R[2] = R[0] + 1;  /* 0x800ADC4C */
    sh_(R[29] + 30, R[2]);  /* 0x800ADC50 */
    R[2] = R[0] + 736;  /* 0x800ADC54 */
    sh_(R[29] + 32, R[2]);  /* 0x800ADC58 */
    R[2] = R[0] + 296;  /* 0x800ADC5C */
    sh_(R[29] + 34, R[2]);  /* 0x800ADC60 */
    R[2] = R[0] + 20;  /* 0x800ADC64 */
    sh_(R[29] + 36, R[2]);  /* 0x800ADC68 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 3076);  /* 0x800ADC6C */
    R[2] = R[0] + 48;  /* 0x800ADC70 */
    { uint32_t _c = (R[8] != R[3]); sh_(R[29] + 38, R[2]); if (_c) { goto L_800ADC84; } }  /* 0x800ADC74 */
    { uint32_t _c = (R[8] != R[0]); if (_c) { goto L_800ADCB0; } }  /* 0x800ADC7C */
L_800ADC84:;
    R[4] = R[16] + R[0];  /* 0x800ADC84 */
    R[5] = R[8] + R[0];  /* 0x800ADC88 */
    R[6] = R[5] + R[0];  /* 0x800ADC8C */
    R[7] = R[0] + 3072;  /* 0x800ADC90 */
    sh_(R[16] + 3076, R[5]);  /* 0x800ADC94 */
    { R[31] = 0x800ADCA0u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800ADC98 jal */
    R[4] = R[16] + R[0];  /* 0x800ADCA0 */
    R[5] = R[29] + 24;  /* 0x800ADCA4 */
    { R[31] = 0x800ADCB0u; R[6] = R[29] + 32; psx_next = 0x8001CA2Cu; return; }  /* 0x800ADCA8 jal */
L_800ADCB0:;
    R[31] = lw_(R[29] + 300);  /* 0x800ADCB0 */
    R[16] = lw_(R[29] + 296);  /* 0x800ADCB4 */
    { R[29] = R[29] + 304; psx_next = R[31]; return; }  /* 0x800ADCB8 jr ra */
}

void g0_800ADC1C(void) {
    R[16] = R[2] + 9480;  /* 0x800ADC1C */
    R[2] = R[0] + 768;  /* 0x800ADC20 */
    sh_(R[16] + 3074, R[8]);  /* 0x800ADC24 */
    sh_(R[16] + 3084, R[5]);  /* 0x800ADC28 */
    sh_(R[16] + 3086, R[6]);  /* 0x800ADC2C */
    sw_(R[16] + 3080, R[0]);  /* 0x800ADC30 */
    sh_(R[16] + 3078, R[7]);  /* 0x800ADC34 */
    sh_(R[29] + 24, R[2]);  /* 0x800ADC38 */
    R[2] = R[0] + 507;  /* 0x800ADC3C */
    sh_(R[29] + 26, R[2]);  /* 0x800ADC40 */
    R[2] = R[0] + 256;  /* 0x800ADC44 */
    sh_(R[29] + 28, R[2]);  /* 0x800ADC48 */
    R[2] = R[0] + 1;  /* 0x800ADC4C */
    sh_(R[29] + 30, R[2]);  /* 0x800ADC50 */
    R[2] = R[0] + 736;  /* 0x800ADC54 */
    sh_(R[29] + 32, R[2]);  /* 0x800ADC58 */
    R[2] = R[0] + 296;  /* 0x800ADC5C */
    sh_(R[29] + 34, R[2]);  /* 0x800ADC60 */
    R[2] = R[0] + 20;  /* 0x800ADC64 */
    sh_(R[29] + 36, R[2]);  /* 0x800ADC68 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 3076);  /* 0x800ADC6C */
    R[2] = R[0] + 48;  /* 0x800ADC70 */
    { uint32_t _c = (R[8] != R[3]); sh_(R[29] + 38, R[2]); if (_c) { goto L_800ADC84; } }  /* 0x800ADC74 */
    { uint32_t _c = (R[8] != R[0]); if (_c) { goto L_800ADCB0; } }  /* 0x800ADC7C */
L_800ADC84:;
    R[4] = R[16] + R[0];  /* 0x800ADC84 */
    R[5] = R[8] + R[0];  /* 0x800ADC88 */
    R[6] = R[5] + R[0];  /* 0x800ADC8C */
    R[7] = R[0] + 3072;  /* 0x800ADC90 */
    sh_(R[16] + 3076, R[5]);  /* 0x800ADC94 */
    { R[31] = 0x800ADCA0u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x800ADC98 jal */
    R[4] = R[16] + R[0];  /* 0x800ADCA0 */
    R[5] = R[29] + 24;  /* 0x800ADCA4 */
    { R[31] = 0x800ADCB0u; R[6] = R[29] + 32; psx_next = 0x8001CA2Cu; return; }  /* 0x800ADCA8 jal */
L_800ADCB0:;
    R[31] = lw_(R[29] + 300);  /* 0x800ADCB0 */
    R[16] = lw_(R[29] + 296);  /* 0x800ADCB4 */
    { R[29] = R[29] + 304; psx_next = R[31]; return; }  /* 0x800ADCB8 jr ra */
}

void g0_800ADCA0(void) {
    R[4] = R[16] + R[0];  /* 0x800ADCA0 */
    R[5] = R[29] + 24;  /* 0x800ADCA4 */
    { R[31] = 0x800ADCB0u; R[6] = R[29] + 32; psx_next = 0x8001CA2Cu; return; }  /* 0x800ADCA8 jal */
    R[31] = lw_(R[29] + 300);  /* 0x800ADCB0 */
    R[16] = lw_(R[29] + 296);  /* 0x800ADCB4 */
    { R[29] = R[29] + 304; psx_next = R[31]; return; }  /* 0x800ADCB8 jr ra */
}

void g0_800ADCB0(void) {
    R[31] = lw_(R[29] + 300);  /* 0x800ADCB0 */
    R[16] = lw_(R[29] + 296);  /* 0x800ADCB4 */
    { R[29] = R[29] + 304; psx_next = R[31]; return; }  /* 0x800ADCB8 jr ra */
}

void g0_800ADCC0(void) {
    R[29] = R[29] - 24;  /* 0x800ADCC0 */
    R[5] = R[5] << 16;  /* 0x800ADCC4 */
    R[6] = R[6] << 16;  /* 0x800ADCC8 */
    R[5] = (uint32_t)((int32_t)R[5] >> 16);  /* 0x800ADCCC */
    sw_(R[29] + 16, R[16]);  /* 0x800ADCD0 */
    R[16] = lw_(R[29] + 40);  /* 0x800ADCD4 */
    sw_(R[29] + 20, R[31]);  /* 0x800ADCD8 */
    { R[31] = 0x800ADCE4u; R[6] = (uint32_t)((int32_t)R[6] >> 16); psx_next = 0x800ADBD0u; return; }  /* 0x800ADCDC jal */
    R[31] = lw_(R[29] + 20);  /* 0x800ADCE4 */
    R[2] = 0x8013u << 16;  /* 0x800ADCE8 */
    sh_(R[2] + 12552, R[16]);  /* 0x800ADCEC */
    R[16] = lw_(R[29] + 16);  /* 0x800ADCF0 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800ADCF4 jr ra */
}

void g0_800ADCE4(void) {
    R[31] = lw_(R[29] + 20);  /* 0x800ADCE4 */
    R[2] = 0x8013u << 16;  /* 0x800ADCE8 */
    sh_(R[2] + 12552, R[16]);  /* 0x800ADCEC */
    R[16] = lw_(R[29] + 16);  /* 0x800ADCF0 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800ADCF4 jr ra */
}

void g0_800ADCFC(void) {
    R[3] = 0x8013u << 16;  /* 0x800ADCFC */
    R[2] = R[0] + 9;  /* 0x800ADD00 */
    { sw_(R[3] + 12560, R[2]); psx_next = R[31]; return; }  /* 0x800ADD04 jr ra */
}

void g0_800ADD0C(void) {
    R[29] = R[29] - 48;  /* 0x800ADD0C */
    sw_(R[29] + 36, R[21]);  /* 0x800ADD10 */
    R[2] = 0x8013u << 16;  /* 0x800ADD14 */
    R[6] = R[2] + 9480;  /* 0x800ADD18 */
    sw_(R[29] + 40, R[31]);  /* 0x800ADD1C */
    sw_(R[29] + 32, R[20]);  /* 0x800ADD20 */
    sw_(R[29] + 28, R[19]);  /* 0x800ADD24 */
    sw_(R[29] + 24, R[18]);  /* 0x800ADD28 */
    sw_(R[29] + 20, R[17]);  /* 0x800ADD2C */
    sw_(R[29] + 16, R[16]);  /* 0x800ADD30 */
    R[3] = (uint32_t)(int16_t)lh_(R[6] + 3074);  /* 0x800ADD34 */
    R[2] = R[0] - 1;  /* 0x800ADD38 */
    { uint32_t _c = (R[3] == R[2]); R[21] = R[5] + R[0]; if (_c) { goto L_800ADEC8; } }  /* 0x800ADD3C */
    R[2] = R[0] + 9;  /* 0x800ADD44 */
    sb_(R[4] + 3, R[2]);  /* 0x800ADD48 */
    R[2] = R[0] + 44;  /* 0x800ADD4C */
    sb_(R[4] + 7, R[2]);  /* 0x800ADD50 */
    R[3] = R[2] + R[0];  /* 0x800ADD54 */
    R[2] = R[0] + 128;  /* 0x800ADD58 */
    R[3] = R[3] | 0x2;  /* 0x800ADD5C */
    sb_(R[4] + 4, R[2]);  /* 0x800ADD60 */
    sb_(R[4] + 5, R[2]);  /* 0x800ADD64 */
    sb_(R[4] + 6, R[2]);  /* 0x800ADD68 */
    sb_(R[4] + 7, R[3]);  /* 0x800ADD6C */
    R[3] = lh_(R[6] + 3078);  /* 0x800ADD70 */
    R[2] = R[3] - 2;  /* 0x800ADD78 */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x800ADD7C */
    { uint32_t _c = (R[2] == R[0]); R[16] = R[4] + R[0]; if (_c) { goto L_800ADDF4; } }  /* 0x800ADD80 */
    R[4] = lw_(R[6] + 3080);  /* 0x800ADD88 */
    R[2] = R[0] + 8;  /* 0x800ADD8C */
    { uint32_t _c = (R[4] == R[2]); R[5] = R[2] - R[4]; if (_c) { goto L_800ADDF4; } }  /* 0x800ADD90 */
    { uint32_t _c = ((int32_t)R[5] >= 0); if (_c) { goto L_800ADDA4; } }  /* 0x800ADD98 */
    R[5] = R[0] - R[5];  /* 0x800ADDA0 */
L_800ADDA4:;
    R[2] = R[3] << 16;  /* 0x800ADDA4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800ADDA8 */
    R[3] = R[0] + 3;  /* 0x800ADDAC */
    { uint32_t _c = (R[2] != R[3]); R[19] = R[0] + 40; if (_c) { goto L_800ADDBC; } }  /* 0x800ADDB0 */
    R[5] = R[0] - R[5];  /* 0x800ADDB8 */
L_800ADDBC:;
    R[20] = R[0] + 48;  /* 0x800ADDBC */
    R[4] = R[4] + 1;  /* 0x800ADDC0 */
    R[2] = R[5] << 2;  /* 0x800ADDC4 */
    R[18] = lh_(R[6] + 3086);  /* 0x800ADDC8 */
    R[3] = lh_(R[6] + 3084);  /* 0x800ADDCC */
    R[2] = R[2] + R[5];  /* 0x800ADDD0 */
    R[17] = R[3] - R[2];  /* 0x800ADDD4 */
    R[2] = R[0] + 16;  /* 0x800ADDD8 */
    { uint32_t _c = (R[4] != R[2]); sw_(R[6] + 3080, R[4]); if (_c) { goto L_800ADE0C; } }  /* 0x800ADDDC */
    { R[31] = 0x800ADDECu; psx_next = 0x800ADBB4u; return; }  /* 0x800ADDE4 jal */
    { R[2] = 0x8013u << 16; goto L_800ADE10; }  /* 0x800ADDEC j */
L_800ADDF4:;
    R[19] = R[0] + 40;  /* 0x800ADDF4 */
    R[20] = R[0] + 48;  /* 0x800ADDF8 */
    R[2] = 0x8013u << 16;  /* 0x800ADDFC */
    R[2] = R[2] + 9480;  /* 0x800ADE00 */
    R[17] = lh_(R[2] + 3084);  /* 0x800ADE04 */
    R[18] = lh_(R[2] + 3086);  /* 0x800ADE08 */
L_800ADE0C:;
    R[2] = 0x8013u << 16;  /* 0x800ADE0C */
L_800ADE10:;
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 12558);  /* 0x800ADE10 */
    R[2] = R[0] + 1;  /* 0x800ADE14 */
    { uint32_t _c = (R[3] == R[2]); R[4] = R[0] + 64; if (_c) { goto L_800ADE50; } }  /* 0x800ADE18 */
    R[2] = R[0] + 40;  /* 0x800ADE20 */
    R[3] = R[0] + 104;  /* 0x800ADE24 */
    sb_(R[16] + 13, R[2]);  /* 0x800ADE28 */
    sb_(R[16] + 21, R[2]);  /* 0x800ADE2C */
    R[2] = R[0] + 88;  /* 0x800ADE30 */
    sb_(R[16] + 20, R[3]);  /* 0x800ADE34 */
    sb_(R[16] + 36, R[3]);  /* 0x800ADE38 */
    R[3] = R[17] + R[19];  /* 0x800ADE3C */
    sb_(R[16] + 29, R[2]);  /* 0x800ADE40 */
    sb_(R[16] + 37, R[2]);  /* 0x800ADE44 */
    { R[2] = R[18] + R[20]; goto L_800ADE80; }  /* 0x800ADE48 j */
L_800ADE50:;
    R[2] = R[0] + 40;  /* 0x800ADE50 */
    R[3] = R[0] + 104;  /* 0x800ADE54 */
    sb_(R[16] + 13, R[2]);  /* 0x800ADE58 */
    sb_(R[16] + 21, R[2]);  /* 0x800ADE5C */
    R[2] = R[0] + 87;  /* 0x800ADE60 */
    sb_(R[16] + 20, R[3]);  /* 0x800ADE64 */
    sb_(R[16] + 36, R[3]);  /* 0x800ADE68 */
    R[3] = R[17] + R[19];  /* 0x800ADE6C */
    sb_(R[16] + 29, R[2]);  /* 0x800ADE70 */
    sb_(R[16] + 37, R[2]);  /* 0x800ADE74 */
    R[2] = R[20] << 1;  /* 0x800ADE78 */
    R[2] = R[18] + R[2];  /* 0x800ADE7C */
L_800ADE80:;
    sb_(R[16] + 12, R[4]);  /* 0x800ADE80 */
    sb_(R[16] + 28, R[4]);  /* 0x800ADE84 */
    sh_(R[16] + 8, R[17]);  /* 0x800ADE88 */
    sh_(R[16] + 10, R[18]);  /* 0x800ADE8C */
    sh_(R[16] + 16, R[3]);  /* 0x800ADE90 */
    sh_(R[16] + 18, R[18]);  /* 0x800ADE94 */
    sh_(R[16] + 24, R[17]);  /* 0x800ADE98 */
    sh_(R[16] + 26, R[2]);  /* 0x800ADE9C */
    sh_(R[16] + 32, R[3]);  /* 0x800ADEA0 */
    sh_(R[16] + 34, R[2]);  /* 0x800ADEA4 */
    R[2] = R[0] + 155;  /* 0x800ADEA8 */
    sh_(R[16] + 22, R[2]);  /* 0x800ADEAC */
    R[2] = R[0] + 32496;  /* 0x800ADEB0 */
    R[4] = R[21] + R[0];  /* 0x800ADEB4 */
    R[5] = R[16] + R[0];  /* 0x800ADEB8 */
    { R[31] = 0x800ADEC4u; sh_(R[16] + 14, R[2]); psx_next = 0x800356E8u; return; }  /* 0x800ADEBC jal */
    R[4] = R[16] + 40;  /* 0x800ADEC4 */
L_800ADEC8:;
    R[31] = lw_(R[29] + 40);  /* 0x800ADEC8 */
    R[21] = lw_(R[29] + 36);  /* 0x800ADECC */
    R[20] = lw_(R[29] + 32);  /* 0x800ADED0 */
    R[19] = lw_(R[29] + 28);  /* 0x800ADED4 */
    R[18] = lw_(R[29] + 24);  /* 0x800ADED8 */
    R[17] = lw_(R[29] + 20);  /* 0x800ADEDC */
    R[16] = lw_(R[29] + 16);  /* 0x800ADEE0 */
    R[2] = R[4] + R[0];  /* 0x800ADEE4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800ADEE8 jr ra */
}

void g0_800ADDEC(void) {
    { R[2] = 0x8013u << 16; goto L_800ADE10; }  /* 0x800ADDEC j */
    R[19] = R[0] + 40;  /* 0x800ADDF4 */
    R[20] = R[0] + 48;  /* 0x800ADDF8 */
    R[2] = 0x8013u << 16;  /* 0x800ADDFC */
    R[2] = R[2] + 9480;  /* 0x800ADE00 */
    R[17] = lh_(R[2] + 3084);  /* 0x800ADE04 */
    R[18] = lh_(R[2] + 3086);  /* 0x800ADE08 */
    R[2] = 0x8013u << 16;  /* 0x800ADE0C */
L_800ADE10:;
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 12558);  /* 0x800ADE10 */
    R[2] = R[0] + 1;  /* 0x800ADE14 */
    { uint32_t _c = (R[3] == R[2]); R[4] = R[0] + 64; if (_c) { goto L_800ADE50; } }  /* 0x800ADE18 */
    R[2] = R[0] + 40;  /* 0x800ADE20 */
    R[3] = R[0] + 104;  /* 0x800ADE24 */
    sb_(R[16] + 13, R[2]);  /* 0x800ADE28 */
    sb_(R[16] + 21, R[2]);  /* 0x800ADE2C */
    R[2] = R[0] + 88;  /* 0x800ADE30 */
    sb_(R[16] + 20, R[3]);  /* 0x800ADE34 */
    sb_(R[16] + 36, R[3]);  /* 0x800ADE38 */
    R[3] = R[17] + R[19];  /* 0x800ADE3C */
    sb_(R[16] + 29, R[2]);  /* 0x800ADE40 */
    sb_(R[16] + 37, R[2]);  /* 0x800ADE44 */
    { R[2] = R[18] + R[20]; goto L_800ADE80; }  /* 0x800ADE48 j */
L_800ADE50:;
    R[2] = R[0] + 40;  /* 0x800ADE50 */
    R[3] = R[0] + 104;  /* 0x800ADE54 */
    sb_(R[16] + 13, R[2]);  /* 0x800ADE58 */
    sb_(R[16] + 21, R[2]);  /* 0x800ADE5C */
    R[2] = R[0] + 87;  /* 0x800ADE60 */
    sb_(R[16] + 20, R[3]);  /* 0x800ADE64 */
    sb_(R[16] + 36, R[3]);  /* 0x800ADE68 */
    R[3] = R[17] + R[19];  /* 0x800ADE6C */
    sb_(R[16] + 29, R[2]);  /* 0x800ADE70 */
    sb_(R[16] + 37, R[2]);  /* 0x800ADE74 */
    R[2] = R[20] << 1;  /* 0x800ADE78 */
    R[2] = R[18] + R[2];  /* 0x800ADE7C */
L_800ADE80:;
    sb_(R[16] + 12, R[4]);  /* 0x800ADE80 */
    sb_(R[16] + 28, R[4]);  /* 0x800ADE84 */
    sh_(R[16] + 8, R[17]);  /* 0x800ADE88 */
    sh_(R[16] + 10, R[18]);  /* 0x800ADE8C */
    sh_(R[16] + 16, R[3]);  /* 0x800ADE90 */
    sh_(R[16] + 18, R[18]);  /* 0x800ADE94 */
    sh_(R[16] + 24, R[17]);  /* 0x800ADE98 */
    sh_(R[16] + 26, R[2]);  /* 0x800ADE9C */
    sh_(R[16] + 32, R[3]);  /* 0x800ADEA0 */
    sh_(R[16] + 34, R[2]);  /* 0x800ADEA4 */
    R[2] = R[0] + 155;  /* 0x800ADEA8 */
    sh_(R[16] + 22, R[2]);  /* 0x800ADEAC */
    R[2] = R[0] + 32496;  /* 0x800ADEB0 */
    R[4] = R[21] + R[0];  /* 0x800ADEB4 */
    R[5] = R[16] + R[0];  /* 0x800ADEB8 */
    { R[31] = 0x800ADEC4u; sh_(R[16] + 14, R[2]); psx_next = 0x800356E8u; return; }  /* 0x800ADEBC jal */
    R[4] = R[16] + 40;  /* 0x800ADEC4 */
    R[31] = lw_(R[29] + 40);  /* 0x800ADEC8 */
    R[21] = lw_(R[29] + 36);  /* 0x800ADECC */
    R[20] = lw_(R[29] + 32);  /* 0x800ADED0 */
    R[19] = lw_(R[29] + 28);  /* 0x800ADED4 */
    R[18] = lw_(R[29] + 24);  /* 0x800ADED8 */
    R[17] = lw_(R[29] + 20);  /* 0x800ADEDC */
    R[16] = lw_(R[29] + 16);  /* 0x800ADEE0 */
    R[2] = R[4] + R[0];  /* 0x800ADEE4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800ADEE8 jr ra */
}

void g0_800ADEC4(void) {
    R[4] = R[16] + 40;  /* 0x800ADEC4 */
    R[31] = lw_(R[29] + 40);  /* 0x800ADEC8 */
    R[21] = lw_(R[29] + 36);  /* 0x800ADECC */
    R[20] = lw_(R[29] + 32);  /* 0x800ADED0 */
    R[19] = lw_(R[29] + 28);  /* 0x800ADED4 */
    R[18] = lw_(R[29] + 24);  /* 0x800ADED8 */
    R[17] = lw_(R[29] + 20);  /* 0x800ADEDC */
    R[16] = lw_(R[29] + 16);  /* 0x800ADEE0 */
    R[2] = R[4] + R[0];  /* 0x800ADEE4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800ADEE8 jr ra */
}

void g0_800ADEF0(void) {
    R[29] = R[29] - 40;  /* 0x800ADEF0 */
    sw_(R[29] + 28, R[19]);  /* 0x800ADEF4 */
    R[19] = R[4] + R[0];  /* 0x800ADEF8 */
    sw_(R[29] + 20, R[17]);  /* 0x800ADEFC */
    R[17] = R[5] + R[0];  /* 0x800ADF00 */
    sw_(R[29] + 24, R[18]);  /* 0x800ADF04 */
    R[18] = R[7] + R[0];  /* 0x800ADF08 */
    R[2] = R[0] + 1;  /* 0x800ADF0C */
    sw_(R[29] + 32, R[31]);  /* 0x800ADF10 */
    { uint32_t _c = (R[6] != R[2]); sw_(R[29] + 16, R[16]); if (_c) { goto L_800ADF8C; } }  /* 0x800ADF14 */
    R[2] = R[17] ^ 0x8;  /* 0x800ADF1C */
    R[2] = (R[2] < (uint32_t)1u);  /* 0x800ADF20 */
    R[16] = R[2] << 2;  /* 0x800ADF24 */
    R[2] = R[0] + 20;  /* 0x800ADF28 */
    { uint32_t _c = (R[17] != R[2]); R[2] = R[0] + 52; if (_c) { goto L_800ADF38; } }  /* 0x800ADF2C */
    R[16] = R[0] + 5;  /* 0x800ADF34 */
L_800ADF38:;
    { uint32_t _c = (R[17] != R[2]); R[2] = R[0] + 64; if (_c) { goto L_800ADF44; } }  /* 0x800ADF38 */
    R[16] = R[0] + 6;  /* 0x800ADF40 */
L_800ADF44:;
    { uint32_t _c = (R[17] != R[2]); R[2] = R[0] + 83; if (_c) { goto L_800ADF50; } }  /* 0x800ADF44 */
    R[16] = R[0] + 7;  /* 0x800ADF4C */
L_800ADF50:;
    { uint32_t _c = (R[17] != R[2]); R[2] = R[0] + 84; if (_c) { goto L_800ADF5C; } }  /* 0x800ADF50 */
    R[16] = R[0] + 8;  /* 0x800ADF58 */
L_800ADF5C:;
    { uint32_t _c = (R[17] != R[2]); R[2] = R[0] + 85; if (_c) { goto L_800ADF68; } }  /* 0x800ADF5C */
    R[16] = R[0] + 8;  /* 0x800ADF64 */
L_800ADF68:;
    { uint32_t _c = (R[17] != R[2]); R[2] = R[17] - 83; if (_c) { goto L_800ADFD0; } }  /* 0x800ADF68 */
    { R[16] = R[0] + 8; goto L_800ADFD0; }  /* 0x800ADF70 j */
L_800ADF78:;
    R[4] = 0x8008u << 16;  /* 0x800ADF78 */
    { R[31] = 0x800ADF84u; R[4] = R[4] + 9452; psx_next = 0x8001BBF8u; return; }  /* 0x800ADF7C jal */
    { R[2] = R[17] - 83; goto L_800ADFD0; }  /* 0x800ADF84 j */
L_800ADF8C:;
    R[16] = R[0] + 24;  /* 0x800ADF8C */
    R[2] = 0x8013u << 16;  /* 0x800ADF90 */
    R[3] = lw_(R[2] + 4144);  /* 0x800ADF94 */
    R[5] = R[0] + 255;  /* 0x800ADF98 */
    R[2] = lw_(R[3] + 16);  /* 0x800ADF9C */
    R[4] = R[0] + 32;  /* 0x800ADFA0 */
    R[3] = R[3] + R[2];  /* 0x800ADFA4 */
L_800ADFA8:;
    R[2] = lb_(R[3]);  /* 0x800ADFA8 */
    { uint32_t _c = (R[2] == R[5]); if (_c) { psx_bb(); goto L_800ADF78; } }  /* 0x800ADFB0 */
    { uint32_t _c = (R[2] == R[17]); R[2] = R[17] - 83; if (_c) { goto L_800ADFD0; } }  /* 0x800ADFB8 */
    R[16] = R[16] + 1;  /* 0x800ADFC0 */
    { uint32_t _c = (R[16] != R[4]); R[3] = R[3] + 1; if (_c) { psx_bb(); goto L_800ADFA8; } }  /* 0x800ADFC4 */
    R[2] = R[17] - 83;  /* 0x800ADFCC */
L_800ADFD0:;
    R[2] = (R[2] < (uint32_t)3u);  /* 0x800ADFD0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AE028; } }  /* 0x800ADFD4 */
    R[2] = R[16] - 83;  /* 0x800ADFDC */
    R[5] = R[2] + R[17];  /* 0x800ADFE0 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[2] = R[5] + R[0]; if (_c) { goto L_800ADFF0; } }  /* 0x800ADFE4 */
    R[2] = R[5] + 15;  /* 0x800ADFEC */
L_800ADFF0:;
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800ADFF0 */
    R[3] = R[2] + 501;  /* 0x800ADFF4 */
    R[3] = R[3] << 6;  /* 0x800ADFF8 */
    R[2] = R[2] << 4;  /* 0x800ADFFC */
    R[2] = R[5] - R[2];  /* 0x800AE000 */
    R[2] = R[2] << 4;  /* 0x800AE004 */
    R[2] = R[2] + 768;  /* 0x800AE008 */
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800AE00C */
    R[2] = R[2] & 0x3F;  /* 0x800AE010 */
    R[3] = R[3] | R[2];  /* 0x800AE014 */
    sh_(R[18] + 6, R[3]);  /* 0x800AE018 */
    R[2] = lw_(R[19] + 596);  /* 0x800AE01C */
    { R[16] = R[16] + R[2]; goto L_800AE060; }  /* 0x800AE020 j */
L_800AE028:;
    { uint32_t _c = ((int32_t)R[16] >= 0); R[2] = R[16] + R[0]; if (_c) { goto L_800AE034; } }  /* 0x800AE028 */
    R[2] = R[16] + 15;  /* 0x800AE030 */
L_800AE034:;
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800AE034 */
    R[3] = R[2] + 501;  /* 0x800AE038 */
    R[3] = R[3] << 6;  /* 0x800AE03C */
    R[2] = R[2] << 4;  /* 0x800AE040 */
    R[2] = R[16] - R[2];  /* 0x800AE044 */
    R[2] = R[2] << 4;  /* 0x800AE048 */
    R[2] = R[2] + 768;  /* 0x800AE04C */
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800AE050 */
    R[2] = R[2] & 0x3F;  /* 0x800AE054 */
    R[3] = R[3] | R[2];  /* 0x800AE058 */
    sh_(R[18] + 6, R[3]);  /* 0x800AE05C */
L_800AE060:;
    { uint32_t _c = ((int32_t)R[16] >= 0); R[2] = R[16] + R[0]; if (_c) { goto L_800AE06C; } }  /* 0x800AE060 */
    R[2] = R[16] + 7;  /* 0x800AE068 */
L_800AE06C:;
    R[3] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800AE06C */
    R[2] = R[3] << 3;  /* 0x800AE070 */
    R[2] = R[16] - R[2];  /* 0x800AE074 */
    R[2] = R[2] << 5;  /* 0x800AE078 */
    sb_(R[18] + 48, R[2]);  /* 0x800AE07C */
    R[2] = R[3] << 5;  /* 0x800AE080 */
    R[2] = R[2] - 128;  /* 0x800AE084 */
    sb_(R[18] + 49, R[2]);  /* 0x800AE088 */
    R[2] = R[0] + 31;  /* 0x800AE08C */
    sb_(R[18] + 50, R[2]);  /* 0x800AE090 */
    sb_(R[18] + 51, R[2]);  /* 0x800AE094 */
    R[31] = lw_(R[29] + 32);  /* 0x800AE098 */
    R[19] = lw_(R[29] + 28);  /* 0x800AE09C */
    R[18] = lw_(R[29] + 24);  /* 0x800AE0A0 */
    R[17] = lw_(R[29] + 20);  /* 0x800AE0A4 */
    R[16] = lw_(R[29] + 16);  /* 0x800AE0A8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AE0AC jr ra */
}

void g0_800ADF78(void) {
L_800ADF78:;
    R[4] = 0x8008u << 16;  /* 0x800ADF78 */
    { R[31] = 0x800ADF84u; R[4] = R[4] + 9452; psx_next = 0x8001BBF8u; return; }  /* 0x800ADF7C jal */
    { R[2] = R[17] - 83; goto L_800ADFD0; }  /* 0x800ADF84 j */
    R[16] = R[0] + 24;  /* 0x800ADF8C */
    R[2] = 0x8013u << 16;  /* 0x800ADF90 */
    R[3] = lw_(R[2] + 4144);  /* 0x800ADF94 */
    R[5] = R[0] + 255;  /* 0x800ADF98 */
    R[2] = lw_(R[3] + 16);  /* 0x800ADF9C */
    R[4] = R[0] + 32;  /* 0x800ADFA0 */
    R[3] = R[3] + R[2];  /* 0x800ADFA4 */
L_800ADFA8:;
    R[2] = lb_(R[3]);  /* 0x800ADFA8 */
    { uint32_t _c = (R[2] == R[5]); if (_c) { psx_bb(); goto L_800ADF78; } }  /* 0x800ADFB0 */
    { uint32_t _c = (R[2] == R[17]); R[2] = R[17] - 83; if (_c) { goto L_800ADFD0; } }  /* 0x800ADFB8 */
    R[16] = R[16] + 1;  /* 0x800ADFC0 */
    { uint32_t _c = (R[16] != R[4]); R[3] = R[3] + 1; if (_c) { psx_bb(); goto L_800ADFA8; } }  /* 0x800ADFC4 */
    R[2] = R[17] - 83;  /* 0x800ADFCC */
L_800ADFD0:;
    R[2] = (R[2] < (uint32_t)3u);  /* 0x800ADFD0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AE028; } }  /* 0x800ADFD4 */
    R[2] = R[16] - 83;  /* 0x800ADFDC */
    R[5] = R[2] + R[17];  /* 0x800ADFE0 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[2] = R[5] + R[0]; if (_c) { goto L_800ADFF0; } }  /* 0x800ADFE4 */
    R[2] = R[5] + 15;  /* 0x800ADFEC */
L_800ADFF0:;
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800ADFF0 */
    R[3] = R[2] + 501;  /* 0x800ADFF4 */
    R[3] = R[3] << 6;  /* 0x800ADFF8 */
    R[2] = R[2] << 4;  /* 0x800ADFFC */
    R[2] = R[5] - R[2];  /* 0x800AE000 */
    R[2] = R[2] << 4;  /* 0x800AE004 */
    R[2] = R[2] + 768;  /* 0x800AE008 */
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800AE00C */
    R[2] = R[2] & 0x3F;  /* 0x800AE010 */
    R[3] = R[3] | R[2];  /* 0x800AE014 */
    sh_(R[18] + 6, R[3]);  /* 0x800AE018 */
    R[2] = lw_(R[19] + 596);  /* 0x800AE01C */
    { R[16] = R[16] + R[2]; goto L_800AE060; }  /* 0x800AE020 j */
L_800AE028:;
    { uint32_t _c = ((int32_t)R[16] >= 0); R[2] = R[16] + R[0]; if (_c) { goto L_800AE034; } }  /* 0x800AE028 */
    R[2] = R[16] + 15;  /* 0x800AE030 */
L_800AE034:;
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800AE034 */
    R[3] = R[2] + 501;  /* 0x800AE038 */
    R[3] = R[3] << 6;  /* 0x800AE03C */
    R[2] = R[2] << 4;  /* 0x800AE040 */
    R[2] = R[16] - R[2];  /* 0x800AE044 */
    R[2] = R[2] << 4;  /* 0x800AE048 */
    R[2] = R[2] + 768;  /* 0x800AE04C */
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800AE050 */
    R[2] = R[2] & 0x3F;  /* 0x800AE054 */
    R[3] = R[3] | R[2];  /* 0x800AE058 */
    sh_(R[18] + 6, R[3]);  /* 0x800AE05C */
L_800AE060:;
    { uint32_t _c = ((int32_t)R[16] >= 0); R[2] = R[16] + R[0]; if (_c) { goto L_800AE06C; } }  /* 0x800AE060 */
    R[2] = R[16] + 7;  /* 0x800AE068 */
L_800AE06C:;
    R[3] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800AE06C */
    R[2] = R[3] << 3;  /* 0x800AE070 */
    R[2] = R[16] - R[2];  /* 0x800AE074 */
    R[2] = R[2] << 5;  /* 0x800AE078 */
    sb_(R[18] + 48, R[2]);  /* 0x800AE07C */
    R[2] = R[3] << 5;  /* 0x800AE080 */
    R[2] = R[2] - 128;  /* 0x800AE084 */
    sb_(R[18] + 49, R[2]);  /* 0x800AE088 */
    R[2] = R[0] + 31;  /* 0x800AE08C */
    sb_(R[18] + 50, R[2]);  /* 0x800AE090 */
    sb_(R[18] + 51, R[2]);  /* 0x800AE094 */
    R[31] = lw_(R[29] + 32);  /* 0x800AE098 */
    R[19] = lw_(R[29] + 28);  /* 0x800AE09C */
    R[18] = lw_(R[29] + 24);  /* 0x800AE0A0 */
    R[17] = lw_(R[29] + 20);  /* 0x800AE0A4 */
    R[16] = lw_(R[29] + 16);  /* 0x800AE0A8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AE0AC jr ra */
}

void g0_800ADF84(void) {
    { R[2] = R[17] - 83; goto L_800ADFD0; }  /* 0x800ADF84 j */
    R[16] = R[0] + 24;  /* 0x800ADF8C */
    R[2] = 0x8013u << 16;  /* 0x800ADF90 */
    R[3] = lw_(R[2] + 4144);  /* 0x800ADF94 */
    R[5] = R[0] + 255;  /* 0x800ADF98 */
    R[2] = lw_(R[3] + 16);  /* 0x800ADF9C */
    R[4] = R[0] + 32;  /* 0x800ADFA0 */
    R[3] = R[3] + R[2];  /* 0x800ADFA4 */
L_800ADFA8:;
    R[2] = lb_(R[3]);  /* 0x800ADFA8 */
    { uint32_t _c = (R[2] == R[5]); if (_c) { psx_next = 0x800ADF78u; return; } }  /* 0x800ADFB0 b extern */
    { uint32_t _c = (R[2] == R[17]); R[2] = R[17] - 83; if (_c) { goto L_800ADFD0; } }  /* 0x800ADFB8 */
    R[16] = R[16] + 1;  /* 0x800ADFC0 */
    { uint32_t _c = (R[16] != R[4]); R[3] = R[3] + 1; if (_c) { psx_bb(); goto L_800ADFA8; } }  /* 0x800ADFC4 */
    R[2] = R[17] - 83;  /* 0x800ADFCC */
L_800ADFD0:;
    R[2] = (R[2] < (uint32_t)3u);  /* 0x800ADFD0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AE028; } }  /* 0x800ADFD4 */
    R[2] = R[16] - 83;  /* 0x800ADFDC */
    R[5] = R[2] + R[17];  /* 0x800ADFE0 */
    { uint32_t _c = ((int32_t)R[5] >= 0); R[2] = R[5] + R[0]; if (_c) { goto L_800ADFF0; } }  /* 0x800ADFE4 */
    R[2] = R[5] + 15;  /* 0x800ADFEC */
L_800ADFF0:;
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800ADFF0 */
    R[3] = R[2] + 501;  /* 0x800ADFF4 */
    R[3] = R[3] << 6;  /* 0x800ADFF8 */
    R[2] = R[2] << 4;  /* 0x800ADFFC */
    R[2] = R[5] - R[2];  /* 0x800AE000 */
    R[2] = R[2] << 4;  /* 0x800AE004 */
    R[2] = R[2] + 768;  /* 0x800AE008 */
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800AE00C */
    R[2] = R[2] & 0x3F;  /* 0x800AE010 */
    R[3] = R[3] | R[2];  /* 0x800AE014 */
    sh_(R[18] + 6, R[3]);  /* 0x800AE018 */
    R[2] = lw_(R[19] + 596);  /* 0x800AE01C */
    { R[16] = R[16] + R[2]; goto L_800AE060; }  /* 0x800AE020 j */
L_800AE028:;
    { uint32_t _c = ((int32_t)R[16] >= 0); R[2] = R[16] + R[0]; if (_c) { goto L_800AE034; } }  /* 0x800AE028 */
    R[2] = R[16] + 15;  /* 0x800AE030 */
L_800AE034:;
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800AE034 */
    R[3] = R[2] + 501;  /* 0x800AE038 */
    R[3] = R[3] << 6;  /* 0x800AE03C */
    R[2] = R[2] << 4;  /* 0x800AE040 */
    R[2] = R[16] - R[2];  /* 0x800AE044 */
    R[2] = R[2] << 4;  /* 0x800AE048 */
    R[2] = R[2] + 768;  /* 0x800AE04C */
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800AE050 */
    R[2] = R[2] & 0x3F;  /* 0x800AE054 */
    R[3] = R[3] | R[2];  /* 0x800AE058 */
    sh_(R[18] + 6, R[3]);  /* 0x800AE05C */
L_800AE060:;
    { uint32_t _c = ((int32_t)R[16] >= 0); R[2] = R[16] + R[0]; if (_c) { goto L_800AE06C; } }  /* 0x800AE060 */
    R[2] = R[16] + 7;  /* 0x800AE068 */
L_800AE06C:;
    R[3] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x800AE06C */
    R[2] = R[3] << 3;  /* 0x800AE070 */
    R[2] = R[16] - R[2];  /* 0x800AE074 */
    R[2] = R[2] << 5;  /* 0x800AE078 */
    sb_(R[18] + 48, R[2]);  /* 0x800AE07C */
    R[2] = R[3] << 5;  /* 0x800AE080 */
    R[2] = R[2] - 128;  /* 0x800AE084 */
    sb_(R[18] + 49, R[2]);  /* 0x800AE088 */
    R[2] = R[0] + 31;  /* 0x800AE08C */
    sb_(R[18] + 50, R[2]);  /* 0x800AE090 */
    sb_(R[18] + 51, R[2]);  /* 0x800AE094 */
    R[31] = lw_(R[29] + 32);  /* 0x800AE098 */
    R[19] = lw_(R[29] + 28);  /* 0x800AE09C */
    R[18] = lw_(R[29] + 24);  /* 0x800AE0A0 */
    R[17] = lw_(R[29] + 20);  /* 0x800AE0A4 */
    R[16] = lw_(R[29] + 16);  /* 0x800AE0A8 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AE0AC jr ra */
}

void g0_800AE0B4(void) {
    R[29] = R[29] - 48;  /* 0x800AE0B4 */
    sw_(R[29] + 36, R[17]);  /* 0x800AE0B8 */
    R[17] = R[4] + R[0];  /* 0x800AE0BC */
    R[3] = 0x8012u << 16;  /* 0x800AE0C0 */
    R[3] = R[3] - 26864;  /* 0x800AE0C4 */
    R[3] = R[17] - R[3];  /* 0x800AE0C8 */
    R[2] = R[3] << 2;  /* 0x800AE0CC */
    R[2] = R[2] + R[3];  /* 0x800AE0D0 */
    R[2] = R[2] << 4;  /* 0x800AE0D4 */
    R[2] = R[2] - R[3];  /* 0x800AE0D8 */
    R[4] = R[2] << 5;  /* 0x800AE0DC */
    R[2] = R[2] + R[4];  /* 0x800AE0E0 */
    R[2] = R[2] << 3;  /* 0x800AE0E4 */
    R[2] = R[2] + R[3];  /* 0x800AE0E8 */
    R[3] = R[2] << 11;  /* 0x800AE0EC */
    R[2] = R[2] + R[3];  /* 0x800AE0F0 */
    R[2] = (uint32_t)((int32_t)R[2] >> 2);  /* 0x800AE0F4 */
    R[3] = R[2] << 3;  /* 0x800AE0F8 */
    R[3] = R[3] + R[2];  /* 0x800AE0FC */
    R[3] = R[3] << 3;  /* 0x800AE100 */
    R[2] = 0x8013u << 16;  /* 0x800AE104 */
    R[2] = R[2] - 23304;  /* 0x800AE108 */
    sw_(R[29] + 32, R[16]);  /* 0x800AE10C */
    R[16] = R[3] + R[2];  /* 0x800AE110 */
    sw_(R[29] + 40, R[31]);  /* 0x800AE114 */
    R[2] = lh_(R[16]);  /* 0x800AE118 */
    R[2] = R[2] | 0xC000;  /* 0x800AE120 */
    sh_(R[16], R[2]);  /* 0x800AE124 */
    R[2] = lw_(R[17] + 24);  /* 0x800AE128 */
    sw_(R[16] + 8, R[2]);  /* 0x800AE130 */
    R[2] = lw_(R[17] + 28);  /* 0x800AE134 */
    R[2] = R[0] - R[2];  /* 0x800AE13C */
    sw_(R[16] + 12, R[2]);  /* 0x800AE140 */
    R[2] = lw_(R[17] + 32);  /* 0x800AE144 */
    sw_(R[16] + 16, R[2]);  /* 0x800AE14C */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 12);  /* 0x800AE150 */
    R[2] = R[0] + 11;  /* 0x800AE154 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[17] + R[0]; if (_c) { goto L_800AE170; } }  /* 0x800AE158 */
    R[5] = lh_(R[17] + 14);  /* 0x800AE160 */
    R[6] = lw_(R[17] + 600);  /* 0x800AE164 */
    { R[31] = 0x800AE170u; R[7] = R[16] + R[0]; psx_next = 0x800ADEF0u; return; }  /* 0x800AE168 jal */
L_800AE170:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 694);  /* 0x800AE170 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AE258; } }  /* 0x800AE178 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 752);  /* 0x800AE180 */
    sw_(R[29] + 16, R[2]);  /* 0x800AE188 */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 758);  /* 0x800AE18C */
    sw_(R[29] + 20, R[3]);  /* 0x800AE194 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 764);  /* 0x800AE198 */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[29] + 24, R[4]); if (_c) { goto L_800AE1A8; } }  /* 0x800AE19C */
    R[2] = R[2] + 15;  /* 0x800AE1A4 */
L_800AE1A8:;
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800AE1A8 */
    R[2] = R[2] - 1;  /* 0x800AE1AC */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[5] = R[2] + R[0]; if (_c) { goto L_800AE1BC; } }  /* 0x800AE1B0 */
    R[5] = R[0] + R[0];  /* 0x800AE1B8 */
L_800AE1BC:;
    R[2] = R[3] + R[0];  /* 0x800AE1BC */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800AE1CC; } }  /* 0x800AE1C0 */
    R[2] = R[2] + 15;  /* 0x800AE1C8 */
L_800AE1CC:;
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800AE1CC */
    R[2] = R[2] - 1;  /* 0x800AE1D0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = R[2] + R[0]; if (_c) { goto L_800AE1E0; } }  /* 0x800AE1D4 */
    R[3] = R[0] + R[0];  /* 0x800AE1DC */
L_800AE1E0:;
    R[2] = R[4] + R[0];  /* 0x800AE1E0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800AE1F0; } }  /* 0x800AE1E4 */
    R[2] = R[2] + 15;  /* 0x800AE1EC */
L_800AE1F0:;
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800AE1F0 */
    R[2] = R[2] - 1;  /* 0x800AE1F4 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[4] = R[2] + R[0]; if (_c) { goto L_800AE204; } }  /* 0x800AE1F8 */
    R[4] = R[0] + R[0];  /* 0x800AE200 */
L_800AE204:;
    R[4] = R[4] << 16;  /* 0x800AE204 */
    R[2] = R[3] << 16;  /* 0x800AE208 */
    R[2] = (uint32_t)((int32_t)R[2] >> 8);  /* 0x800AE20C */
    R[3] = 0x2C00u << 16;  /* 0x800AE210 */
    R[2] = R[2] | R[3];  /* 0x800AE214 */
    R[4] = R[4] | R[2];  /* 0x800AE218 */
    R[2] = R[5] << 16;  /* 0x800AE21C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800AE220 */
    R[4] = R[4] | R[2];  /* 0x800AE224 */
    sw_(R[16] + 44, R[4]);  /* 0x800AE228 */
    R[2] = lh_(R[17] + 778);  /* 0x800AE22C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x200u << 16; if (_c) { goto L_800AE244; } }  /* 0x800AE234 */
    R[2] = R[4] | R[2];  /* 0x800AE23C */
    sw_(R[16] + 44, R[2]);  /* 0x800AE240 */
L_800AE244:;
    R[2] = lh_(R[16] + 4);  /* 0x800AE244 */
    R[2] = R[2] & 0xFF9F;  /* 0x800AE24C */
    R[2] = R[2] | 0x20;  /* 0x800AE250 */
    sh_(R[16] + 4, R[2]);  /* 0x800AE254 */
L_800AE258:;
    R[31] = lw_(R[29] + 40);  /* 0x800AE258 */
    R[17] = lw_(R[29] + 36);  /* 0x800AE25C */
    R[16] = lw_(R[29] + 32);  /* 0x800AE260 */
    R[2] = R[0] + R[0];  /* 0x800AE264 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800AE268 jr ra */
}

void g0_800AE170(void) {
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 694);  /* 0x800AE170 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AE258; } }  /* 0x800AE178 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 752);  /* 0x800AE180 */
    sw_(R[29] + 16, R[2]);  /* 0x800AE188 */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 758);  /* 0x800AE18C */
    sw_(R[29] + 20, R[3]);  /* 0x800AE194 */
    R[4] = (uint32_t)(int16_t)lh_(R[17] + 764);  /* 0x800AE198 */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[29] + 24, R[4]); if (_c) { goto L_800AE1A8; } }  /* 0x800AE19C */
    R[2] = R[2] + 15;  /* 0x800AE1A4 */
L_800AE1A8:;
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800AE1A8 */
    R[2] = R[2] - 1;  /* 0x800AE1AC */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[5] = R[2] + R[0]; if (_c) { goto L_800AE1BC; } }  /* 0x800AE1B0 */
    R[5] = R[0] + R[0];  /* 0x800AE1B8 */
L_800AE1BC:;
    R[2] = R[3] + R[0];  /* 0x800AE1BC */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800AE1CC; } }  /* 0x800AE1C0 */
    R[2] = R[2] + 15;  /* 0x800AE1C8 */
L_800AE1CC:;
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800AE1CC */
    R[2] = R[2] - 1;  /* 0x800AE1D0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = R[2] + R[0]; if (_c) { goto L_800AE1E0; } }  /* 0x800AE1D4 */
    R[3] = R[0] + R[0];  /* 0x800AE1DC */
L_800AE1E0:;
    R[2] = R[4] + R[0];  /* 0x800AE1E0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800AE1F0; } }  /* 0x800AE1E4 */
    R[2] = R[2] + 15;  /* 0x800AE1EC */
L_800AE1F0:;
    R[2] = (uint32_t)((int32_t)R[2] >> 4);  /* 0x800AE1F0 */
    R[2] = R[2] - 1;  /* 0x800AE1F4 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[4] = R[2] + R[0]; if (_c) { goto L_800AE204; } }  /* 0x800AE1F8 */
    R[4] = R[0] + R[0];  /* 0x800AE200 */
L_800AE204:;
    R[4] = R[4] << 16;  /* 0x800AE204 */
    R[2] = R[3] << 16;  /* 0x800AE208 */
    R[2] = (uint32_t)((int32_t)R[2] >> 8);  /* 0x800AE20C */
    R[3] = 0x2C00u << 16;  /* 0x800AE210 */
    R[2] = R[2] | R[3];  /* 0x800AE214 */
    R[4] = R[4] | R[2];  /* 0x800AE218 */
    R[2] = R[5] << 16;  /* 0x800AE21C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800AE220 */
    R[4] = R[4] | R[2];  /* 0x800AE224 */
    sw_(R[16] + 44, R[4]);  /* 0x800AE228 */
    R[2] = lh_(R[17] + 778);  /* 0x800AE22C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x200u << 16; if (_c) { goto L_800AE244; } }  /* 0x800AE234 */
    R[2] = R[4] | R[2];  /* 0x800AE23C */
    sw_(R[16] + 44, R[2]);  /* 0x800AE240 */
L_800AE244:;
    R[2] = lh_(R[16] + 4);  /* 0x800AE244 */
    R[2] = R[2] & 0xFF9F;  /* 0x800AE24C */
    R[2] = R[2] | 0x20;  /* 0x800AE250 */
    sh_(R[16] + 4, R[2]);  /* 0x800AE254 */
L_800AE258:;
    R[31] = lw_(R[29] + 40);  /* 0x800AE258 */
    R[17] = lw_(R[29] + 36);  /* 0x800AE25C */
    R[16] = lw_(R[29] + 32);  /* 0x800AE260 */
    R[2] = R[0] + R[0];  /* 0x800AE264 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800AE268 jr ra */
}

void g0_800AE270(void) {
    R[29] = R[29] - 40;  /* 0x800AE270 */
    sw_(R[29] + 24, R[16]);  /* 0x800AE274 */
    R[16] = R[0] + R[0];  /* 0x800AE278 */
    sw_(R[29] + 32, R[18]);  /* 0x800AE27C */
    R[18] = R[0] + 16;  /* 0x800AE280 */
    R[2] = 0x8013u << 16;  /* 0x800AE284 */
    sw_(R[29] + 28, R[17]);  /* 0x800AE288 */
    R[17] = R[2] + 13528;  /* 0x800AE28C */
    sw_(R[29] + 36, R[31]);  /* 0x800AE290 */
    sh_(R[29] + 20, R[0]);  /* 0x800AE294 */
    sh_(R[29] + 18, R[0]);  /* 0x800AE298 */
    sh_(R[29] + 16, R[0]);  /* 0x800AE29C */
L_800AE2A0:;
    R[2] = R[16] << 7;  /* 0x800AE2A0 */
    sh_(R[29] + 16, R[2]);  /* 0x800AE2A4 */
    R[4] = R[29] + 16;  /* 0x800AE2A8 */
    { R[31] = 0x800AE2B4u; R[5] = R[17] + R[0]; psx_next = 0x80036EA8u; return; }  /* 0x800AE2AC jal */
    R[16] = R[16] + 1;  /* 0x800AE2B4 */
    { uint32_t _c = (R[16] != R[18]); R[17] = R[17] + 20; if (_c) { psx_bb(); goto L_800AE2A0; } }  /* 0x800AE2B8 */
    R[31] = lw_(R[29] + 36);  /* 0x800AE2C0 */
    R[18] = lw_(R[29] + 32);  /* 0x800AE2C4 */
    R[17] = lw_(R[29] + 28);  /* 0x800AE2C8 */
    R[16] = lw_(R[29] + 24);  /* 0x800AE2CC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AE2D0 jr ra */
}

void g0_800AE2A0(void) {
L_800AE2A0:;
    R[2] = R[16] << 7;  /* 0x800AE2A0 */
    sh_(R[29] + 16, R[2]);  /* 0x800AE2A4 */
    R[4] = R[29] + 16;  /* 0x800AE2A8 */
    { R[31] = 0x800AE2B4u; R[5] = R[17] + R[0]; psx_next = 0x80036EA8u; return; }  /* 0x800AE2AC jal */
    R[16] = R[16] + 1;  /* 0x800AE2B4 */
    { uint32_t _c = (R[16] != R[18]); R[17] = R[17] + 20; if (_c) { psx_bb(); goto L_800AE2A0; } }  /* 0x800AE2B8 */
    R[31] = lw_(R[29] + 36);  /* 0x800AE2C0 */
    R[18] = lw_(R[29] + 32);  /* 0x800AE2C4 */
    R[17] = lw_(R[29] + 28);  /* 0x800AE2C8 */
    R[16] = lw_(R[29] + 24);  /* 0x800AE2CC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AE2D0 jr ra */
}

void g0_800AE2B4(void) {
    R[16] = R[16] + 1;  /* 0x800AE2B4 */
    { uint32_t _c = (R[16] != R[18]); R[17] = R[17] + 20; if (_c) { psx_next = 0x800AE2A0u; return; } }  /* 0x800AE2B8 b extern */
    R[31] = lw_(R[29] + 36);  /* 0x800AE2C0 */
    R[18] = lw_(R[29] + 32);  /* 0x800AE2C4 */
    R[17] = lw_(R[29] + 28);  /* 0x800AE2C8 */
    R[16] = lw_(R[29] + 24);  /* 0x800AE2CC */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AE2D0 jr ra */
}

void g0_800AE2D8(void) {
    R[29] = R[29] - 56;  /* 0x800AE2D8 */
    sw_(R[29] + 44, R[23]);  /* 0x800AE2DC */
    R[23] = R[4] + R[0];  /* 0x800AE2E0 */
    sw_(R[29] + 52, R[31]);  /* 0x800AE2E4 */
    sw_(R[29] + 48, R[30]);  /* 0x800AE2E8 */
    sw_(R[29] + 40, R[22]);  /* 0x800AE2EC */
    sw_(R[29] + 36, R[21]);  /* 0x800AE2F0 */
    sw_(R[29] + 32, R[20]);  /* 0x800AE2F4 */
    sw_(R[29] + 28, R[19]);  /* 0x800AE2F8 */
    sw_(R[29] + 24, R[18]);  /* 0x800AE2FC */
    sw_(R[29] + 20, R[17]);  /* 0x800AE300 */
    sw_(R[29] + 16, R[16]);  /* 0x800AE304 */
    R[21] = lb_(R[23] + 97);  /* 0x800AE308 */
    { uint32_t _c = (R[21] == R[0]); if (_c) { goto L_800AE464; } }  /* 0x800AE310 */
    { R[31] = 0x800AE320u; R[4] = R[0] + 511; psx_next = 0x800908F4u; return; }  /* 0x800AE318 jal */
    R[20] = R[2] + R[0];  /* 0x800AE320 */
    R[2] = 0x8013u << 16;  /* 0x800AE324 */
    R[17] = R[2] + 12568;  /* 0x800AE328 */
    R[19] = R[0] + R[0];  /* 0x800AE32C */
    R[2] = R[0] + 512;  /* 0x800AE330 */
    psx_div((int32_t)R[2], (int32_t)R[21]);  /* 0x800AE334 */
    { uint32_t _c = (R[21] != R[0]); if (_c) { goto L_800AE344; } }  /* 0x800AE338 */
    psx_break(7168);  /* 0x800AE340 */
L_800AE344:;
    R[1] = R[0] - 1;  /* 0x800AE344 */
    { uint32_t _c = (R[21] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800AE35C; } }  /* 0x800AE348 */
    { uint32_t _c = (R[2] != R[1]); if (_c) { goto L_800AE35C; } }  /* 0x800AE350 */
    psx_break(6144);  /* 0x800AE358 */
L_800AE35C:;
    R[30] = LO;  /* 0x800AE35C */
    { uint32_t _c = (R[21] == R[0]); R[18] = R[0] + R[0]; if (_c) { goto L_800AE460; } }  /* 0x800AE360 */
    R[22] = R[17] + 960;  /* 0x800AE368 */
    R[16] = R[17] + 16;  /* 0x800AE36C */
L_800AE370:;
    { uint32_t _c = (R[17] == R[22]); if (_c) { goto L_800AE460; } }  /* 0x800AE370 */
    R[2] = (uint32_t)(int16_t)lh_(R[17]);  /* 0x800AE378 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AE398; } }  /* 0x800AE380 */
    R[16] = R[16] + 20;  /* 0x800AE388 */
    R[17] = R[17] + 20;  /* 0x800AE38C */
    { R[19] = R[19] + 1; psx_bb(); goto L_800AE370; }  /* 0x800AE390 j */
L_800AE398:;
    { uint32_t _c = (R[17] == R[22]); if (_c) { goto L_800AE460; } }  /* 0x800AE398 */
    { uint32_t _c = (R[18] != R[0]); R[2] = 0x8008u << 16; if (_c) { goto L_800AE3AC; } }  /* 0x800AE3A0 */
    sb_(R[23] + 99, R[19]);  /* 0x800AE3A8 */
L_800AE3AC:;
    R[2] = R[2] + 6516;  /* 0x800AE3AC */
    R[3] = R[20] << 1;  /* 0x800AE3B0 */
    R[2] = R[3] + R[2];  /* 0x800AE3B4 */
    R[4] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800AE3B8 */
    R[2] = R[0] + 1;  /* 0x800AE3BC */
    { uint32_t _c = ((int32_t)R[4] >= 0); sh_(R[17], R[2]); if (_c) { goto L_800AE3CC; } }  /* 0x800AE3C0 */
    R[4] = R[4] + 31;  /* 0x800AE3C8 */
L_800AE3CC:;
    R[2] = 0x8008u << 16;  /* 0x800AE3CC */
    R[2] = R[2] + 5492;  /* 0x800AE3D0 */
    R[2] = R[3] + R[2];  /* 0x800AE3D4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800AE3D8 */
    R[2] = (uint32_t)((int32_t)R[4] >> 5);  /* 0x800AE3DC */
    { uint32_t _c = ((int32_t)R[3] >= 0); sh_(R[16] + -8, R[2]); if (_c) { goto L_800AE3EC; } }  /* 0x800AE3E0 */
    R[3] = R[3] + 31;  /* 0x800AE3E8 */
L_800AE3EC:;
    R[4] = R[0] + 8;  /* 0x800AE3EC */
    R[2] = (uint32_t)((int32_t)R[3] >> 5);  /* 0x800AE3F0 */
    { R[31] = 0x800AE3FCu; sh_(R[16] + -4, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800AE3F4 jal */
    R[4] = 0x1u << 16;  /* 0x800AE3FC */
    R[3] = 0x8012u << 16;  /* 0x800AE400 */
    R[3] = (uint32_t)(int16_t)lh_(R[3] + 30976);  /* 0x800AE404 */
    R[4] = R[4] | 0x22E5;  /* 0x800AE408 */
    R[3] = (uint32_t)((int32_t)R[4] >> (R[3] & 31));  /* 0x800AE40C */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800AE41C; } }  /* 0x800AE410 */
    R[3] = R[3] + 4095;  /* 0x800AE418 */
L_800AE41C:;
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x800AE41C */
    R[2] = R[2] + 10;  /* 0x800AE420 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800AE424 */
    R[3] = LO;  /* 0x800AE428 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[20] + R[30]; if (_c) { goto L_800AE438; } }  /* 0x800AE42C */
    R[3] = R[3] + 15;  /* 0x800AE434 */
L_800AE438:;
    R[20] = R[2] & 0x1FF;  /* 0x800AE438 */
    R[18] = R[18] + 1;  /* 0x800AE43C */
    R[2] = (uint32_t)((int32_t)R[3] >> 4);  /* 0x800AE440 */
    sh_(R[16] + -6, R[2]);  /* 0x800AE444 */
    R[2] = ((int32_t)R[18] < (int32_t)R[21]);  /* 0x800AE448 */
    sh_(R[16] + -10, R[0]);  /* 0x800AE44C */
    sh_(R[16] + -12, R[0]);  /* 0x800AE450 */
    sh_(R[16] + -14, R[0]);  /* 0x800AE454 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[16], R[23]); if (_c) { psx_bb(); goto L_800AE370; } }  /* 0x800AE458 */
L_800AE460:;
    sb_(R[23] + 98, R[18]);  /* 0x800AE460 */
L_800AE464:;
    R[31] = lw_(R[29] + 52);  /* 0x800AE464 */
    R[30] = lw_(R[29] + 48);  /* 0x800AE468 */
    R[23] = lw_(R[29] + 44);  /* 0x800AE46C */
    R[22] = lw_(R[29] + 40);  /* 0x800AE470 */
    R[21] = lw_(R[29] + 36);  /* 0x800AE474 */
    R[20] = lw_(R[29] + 32);  /* 0x800AE478 */
    R[19] = lw_(R[29] + 28);  /* 0x800AE47C */
    R[18] = lw_(R[29] + 24);  /* 0x800AE480 */
    R[17] = lw_(R[29] + 20);  /* 0x800AE484 */
    R[16] = lw_(R[29] + 16);  /* 0x800AE488 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800AE48C jr ra */
}

void g0_800AE320(void) {
    R[20] = R[2] + R[0];  /* 0x800AE320 */
    R[2] = 0x8013u << 16;  /* 0x800AE324 */
    R[17] = R[2] + 12568;  /* 0x800AE328 */
    R[19] = R[0] + R[0];  /* 0x800AE32C */
    R[2] = R[0] + 512;  /* 0x800AE330 */
    psx_div((int32_t)R[2], (int32_t)R[21]);  /* 0x800AE334 */
    { uint32_t _c = (R[21] != R[0]); if (_c) { goto L_800AE344; } }  /* 0x800AE338 */
    psx_break(7168);  /* 0x800AE340 */
L_800AE344:;
    R[1] = R[0] - 1;  /* 0x800AE344 */
    { uint32_t _c = (R[21] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800AE35C; } }  /* 0x800AE348 */
    { uint32_t _c = (R[2] != R[1]); if (_c) { goto L_800AE35C; } }  /* 0x800AE350 */
    psx_break(6144);  /* 0x800AE358 */
L_800AE35C:;
    R[30] = LO;  /* 0x800AE35C */
    { uint32_t _c = (R[21] == R[0]); R[18] = R[0] + R[0]; if (_c) { goto L_800AE460; } }  /* 0x800AE360 */
    R[22] = R[17] + 960;  /* 0x800AE368 */
    R[16] = R[17] + 16;  /* 0x800AE36C */
L_800AE370:;
    { uint32_t _c = (R[17] == R[22]); if (_c) { goto L_800AE460; } }  /* 0x800AE370 */
    R[2] = (uint32_t)(int16_t)lh_(R[17]);  /* 0x800AE378 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AE398; } }  /* 0x800AE380 */
    R[16] = R[16] + 20;  /* 0x800AE388 */
    R[17] = R[17] + 20;  /* 0x800AE38C */
    { R[19] = R[19] + 1; psx_bb(); goto L_800AE370; }  /* 0x800AE390 j */
L_800AE398:;
    { uint32_t _c = (R[17] == R[22]); if (_c) { goto L_800AE460; } }  /* 0x800AE398 */
    { uint32_t _c = (R[18] != R[0]); R[2] = 0x8008u << 16; if (_c) { goto L_800AE3AC; } }  /* 0x800AE3A0 */
    sb_(R[23] + 99, R[19]);  /* 0x800AE3A8 */
L_800AE3AC:;
    R[2] = R[2] + 6516;  /* 0x800AE3AC */
    R[3] = R[20] << 1;  /* 0x800AE3B0 */
    R[2] = R[3] + R[2];  /* 0x800AE3B4 */
    R[4] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800AE3B8 */
    R[2] = R[0] + 1;  /* 0x800AE3BC */
    { uint32_t _c = ((int32_t)R[4] >= 0); sh_(R[17], R[2]); if (_c) { goto L_800AE3CC; } }  /* 0x800AE3C0 */
    R[4] = R[4] + 31;  /* 0x800AE3C8 */
L_800AE3CC:;
    R[2] = 0x8008u << 16;  /* 0x800AE3CC */
    R[2] = R[2] + 5492;  /* 0x800AE3D0 */
    R[2] = R[3] + R[2];  /* 0x800AE3D4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800AE3D8 */
    R[2] = (uint32_t)((int32_t)R[4] >> 5);  /* 0x800AE3DC */
    { uint32_t _c = ((int32_t)R[3] >= 0); sh_(R[16] + -8, R[2]); if (_c) { goto L_800AE3EC; } }  /* 0x800AE3E0 */
    R[3] = R[3] + 31;  /* 0x800AE3E8 */
L_800AE3EC:;
    R[4] = R[0] + 8;  /* 0x800AE3EC */
    R[2] = (uint32_t)((int32_t)R[3] >> 5);  /* 0x800AE3F0 */
    { R[31] = 0x800AE3FCu; sh_(R[16] + -4, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800AE3F4 jal */
    R[4] = 0x1u << 16;  /* 0x800AE3FC */
    R[3] = 0x8012u << 16;  /* 0x800AE400 */
    R[3] = (uint32_t)(int16_t)lh_(R[3] + 30976);  /* 0x800AE404 */
    R[4] = R[4] | 0x22E5;  /* 0x800AE408 */
    R[3] = (uint32_t)((int32_t)R[4] >> (R[3] & 31));  /* 0x800AE40C */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800AE41C; } }  /* 0x800AE410 */
    R[3] = R[3] + 4095;  /* 0x800AE418 */
L_800AE41C:;
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x800AE41C */
    R[2] = R[2] + 10;  /* 0x800AE420 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800AE424 */
    R[3] = LO;  /* 0x800AE428 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[20] + R[30]; if (_c) { goto L_800AE438; } }  /* 0x800AE42C */
    R[3] = R[3] + 15;  /* 0x800AE434 */
L_800AE438:;
    R[20] = R[2] & 0x1FF;  /* 0x800AE438 */
    R[18] = R[18] + 1;  /* 0x800AE43C */
    R[2] = (uint32_t)((int32_t)R[3] >> 4);  /* 0x800AE440 */
    sh_(R[16] + -6, R[2]);  /* 0x800AE444 */
    R[2] = ((int32_t)R[18] < (int32_t)R[21]);  /* 0x800AE448 */
    sh_(R[16] + -10, R[0]);  /* 0x800AE44C */
    sh_(R[16] + -12, R[0]);  /* 0x800AE450 */
    sh_(R[16] + -14, R[0]);  /* 0x800AE454 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[16], R[23]); if (_c) { psx_bb(); goto L_800AE370; } }  /* 0x800AE458 */
L_800AE460:;
    sb_(R[23] + 98, R[18]);  /* 0x800AE460 */
    R[31] = lw_(R[29] + 52);  /* 0x800AE464 */
    R[30] = lw_(R[29] + 48);  /* 0x800AE468 */
    R[23] = lw_(R[29] + 44);  /* 0x800AE46C */
    R[22] = lw_(R[29] + 40);  /* 0x800AE470 */
    R[21] = lw_(R[29] + 36);  /* 0x800AE474 */
    R[20] = lw_(R[29] + 32);  /* 0x800AE478 */
    R[19] = lw_(R[29] + 28);  /* 0x800AE47C */
    R[18] = lw_(R[29] + 24);  /* 0x800AE480 */
    R[17] = lw_(R[29] + 20);  /* 0x800AE484 */
    R[16] = lw_(R[29] + 16);  /* 0x800AE488 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800AE48C jr ra */
}

void g0_800AE370(void) {
L_800AE370:;
    { uint32_t _c = (R[17] == R[22]); if (_c) { goto L_800AE460; } }  /* 0x800AE370 */
    R[2] = (uint32_t)(int16_t)lh_(R[17]);  /* 0x800AE378 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AE398; } }  /* 0x800AE380 */
    R[16] = R[16] + 20;  /* 0x800AE388 */
    R[17] = R[17] + 20;  /* 0x800AE38C */
    { R[19] = R[19] + 1; psx_bb(); goto L_800AE370; }  /* 0x800AE390 j */
L_800AE398:;
    { uint32_t _c = (R[17] == R[22]); if (_c) { goto L_800AE460; } }  /* 0x800AE398 */
    { uint32_t _c = (R[18] != R[0]); R[2] = 0x8008u << 16; if (_c) { goto L_800AE3AC; } }  /* 0x800AE3A0 */
    sb_(R[23] + 99, R[19]);  /* 0x800AE3A8 */
L_800AE3AC:;
    R[2] = R[2] + 6516;  /* 0x800AE3AC */
    R[3] = R[20] << 1;  /* 0x800AE3B0 */
    R[2] = R[3] + R[2];  /* 0x800AE3B4 */
    R[4] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800AE3B8 */
    R[2] = R[0] + 1;  /* 0x800AE3BC */
    { uint32_t _c = ((int32_t)R[4] >= 0); sh_(R[17], R[2]); if (_c) { goto L_800AE3CC; } }  /* 0x800AE3C0 */
    R[4] = R[4] + 31;  /* 0x800AE3C8 */
L_800AE3CC:;
    R[2] = 0x8008u << 16;  /* 0x800AE3CC */
    R[2] = R[2] + 5492;  /* 0x800AE3D0 */
    R[2] = R[3] + R[2];  /* 0x800AE3D4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x800AE3D8 */
    R[2] = (uint32_t)((int32_t)R[4] >> 5);  /* 0x800AE3DC */
    { uint32_t _c = ((int32_t)R[3] >= 0); sh_(R[16] + -8, R[2]); if (_c) { goto L_800AE3EC; } }  /* 0x800AE3E0 */
    R[3] = R[3] + 31;  /* 0x800AE3E8 */
L_800AE3EC:;
    R[4] = R[0] + 8;  /* 0x800AE3EC */
    R[2] = (uint32_t)((int32_t)R[3] >> 5);  /* 0x800AE3F0 */
    { R[31] = 0x800AE3FCu; sh_(R[16] + -4, R[2]); psx_next = 0x800908F4u; return; }  /* 0x800AE3F4 jal */
    R[4] = 0x1u << 16;  /* 0x800AE3FC */
    R[3] = 0x8012u << 16;  /* 0x800AE400 */
    R[3] = (uint32_t)(int16_t)lh_(R[3] + 30976);  /* 0x800AE404 */
    R[4] = R[4] | 0x22E5;  /* 0x800AE408 */
    R[3] = (uint32_t)((int32_t)R[4] >> (R[3] & 31));  /* 0x800AE40C */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800AE41C; } }  /* 0x800AE410 */
    R[3] = R[3] + 4095;  /* 0x800AE418 */
L_800AE41C:;
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x800AE41C */
    R[2] = R[2] + 10;  /* 0x800AE420 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800AE424 */
    R[3] = LO;  /* 0x800AE428 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[20] + R[30]; if (_c) { goto L_800AE438; } }  /* 0x800AE42C */
    R[3] = R[3] + 15;  /* 0x800AE434 */
L_800AE438:;
    R[20] = R[2] & 0x1FF;  /* 0x800AE438 */
    R[18] = R[18] + 1;  /* 0x800AE43C */
    R[2] = (uint32_t)((int32_t)R[3] >> 4);  /* 0x800AE440 */
    sh_(R[16] + -6, R[2]);  /* 0x800AE444 */
    R[2] = ((int32_t)R[18] < (int32_t)R[21]);  /* 0x800AE448 */
    sh_(R[16] + -10, R[0]);  /* 0x800AE44C */
    sh_(R[16] + -12, R[0]);  /* 0x800AE450 */
    sh_(R[16] + -14, R[0]);  /* 0x800AE454 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[16], R[23]); if (_c) { psx_bb(); goto L_800AE370; } }  /* 0x800AE458 */
L_800AE460:;
    sb_(R[23] + 98, R[18]);  /* 0x800AE460 */
    R[31] = lw_(R[29] + 52);  /* 0x800AE464 */
    R[30] = lw_(R[29] + 48);  /* 0x800AE468 */
    R[23] = lw_(R[29] + 44);  /* 0x800AE46C */
    R[22] = lw_(R[29] + 40);  /* 0x800AE470 */
    R[21] = lw_(R[29] + 36);  /* 0x800AE474 */
    R[20] = lw_(R[29] + 32);  /* 0x800AE478 */
    R[19] = lw_(R[29] + 28);  /* 0x800AE47C */
    R[18] = lw_(R[29] + 24);  /* 0x800AE480 */
    R[17] = lw_(R[29] + 20);  /* 0x800AE484 */
    R[16] = lw_(R[29] + 16);  /* 0x800AE488 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800AE48C jr ra */
}

void g0_800AE3FC(void) {
    R[4] = 0x1u << 16;  /* 0x800AE3FC */
    R[3] = 0x8012u << 16;  /* 0x800AE400 */
    R[3] = (uint32_t)(int16_t)lh_(R[3] + 30976);  /* 0x800AE404 */
    R[4] = R[4] | 0x22E5;  /* 0x800AE408 */
    R[3] = (uint32_t)((int32_t)R[4] >> (R[3] & 31));  /* 0x800AE40C */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800AE41C; } }  /* 0x800AE410 */
    R[3] = R[3] + 4095;  /* 0x800AE418 */
L_800AE41C:;
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x800AE41C */
    R[2] = R[2] + 10;  /* 0x800AE420 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x800AE424 */
    R[3] = LO;  /* 0x800AE428 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[20] + R[30]; if (_c) { goto L_800AE438; } }  /* 0x800AE42C */
    R[3] = R[3] + 15;  /* 0x800AE434 */
L_800AE438:;
    R[20] = R[2] & 0x1FF;  /* 0x800AE438 */
    R[18] = R[18] + 1;  /* 0x800AE43C */
    R[2] = (uint32_t)((int32_t)R[3] >> 4);  /* 0x800AE440 */
    sh_(R[16] + -6, R[2]);  /* 0x800AE444 */
    R[2] = ((int32_t)R[18] < (int32_t)R[21]);  /* 0x800AE448 */
    sh_(R[16] + -10, R[0]);  /* 0x800AE44C */
    sh_(R[16] + -12, R[0]);  /* 0x800AE450 */
    sh_(R[16] + -14, R[0]);  /* 0x800AE454 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[16], R[23]); if (_c) { psx_next = 0x800AE370u; return; } }  /* 0x800AE458 b extern */
    sb_(R[23] + 98, R[18]);  /* 0x800AE460 */
    R[31] = lw_(R[29] + 52);  /* 0x800AE464 */
    R[30] = lw_(R[29] + 48);  /* 0x800AE468 */
    R[23] = lw_(R[29] + 44);  /* 0x800AE46C */
    R[22] = lw_(R[29] + 40);  /* 0x800AE470 */
    R[21] = lw_(R[29] + 36);  /* 0x800AE474 */
    R[20] = lw_(R[29] + 32);  /* 0x800AE478 */
    R[19] = lw_(R[29] + 28);  /* 0x800AE47C */
    R[18] = lw_(R[29] + 24);  /* 0x800AE480 */
    R[17] = lw_(R[29] + 20);  /* 0x800AE484 */
    R[16] = lw_(R[29] + 16);  /* 0x800AE488 */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x800AE48C jr ra */
}

void g0_800AE494(void) {
    R[2] = 0x800Fu << 16;  /* 0x800AE494 */
    R[2] = lw_(R[2] + 25120);  /* 0x800AE498 */
    R[2] = R[2] & 0x87;  /* 0x800AE4A0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8012u << 16; if (_c) { goto L_800AE5DC; } }  /* 0x800AE4A4 */
    R[2] = R[2] + 30872;  /* 0x800AE4AC */
    R[3] = lw_(R[2] + 92);  /* 0x800AE4B0 */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_800AE4C4; } }  /* 0x800AE4B8 */
    R[3] = R[3] + 4095;  /* 0x800AE4C0 */
L_800AE4C4:;
    R[2] = lw_(R[2] + 96);  /* 0x800AE4C4 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[11] = (uint32_t)((int32_t)R[3] >> 12); if (_c) { goto L_800AE4D8; } }  /* 0x800AE4CC */
    R[2] = R[2] + 4095;  /* 0x800AE4D4 */
L_800AE4D8:;
    { uint32_t _c = (R[11] != R[0]); R[3] = (uint32_t)((int32_t)R[2] >> 12); if (_c) { goto L_800AE4E4; } }  /* 0x800AE4D8 */
    R[11] = R[0] + 1;  /* 0x800AE4E0 */
L_800AE4E4:;
    R[10] = R[0] + R[0];  /* 0x800AE4E4 */
    R[2] = 0x8013u << 16;  /* 0x800AE4E8 */
    R[9] = R[2] + 12568;  /* 0x800AE4EC */
    R[12] = R[0] - R[3];  /* 0x800AE4F0 */
    R[13] = R[0] - 1;  /* 0x800AE4F4 */
    R[8] = R[9] + 16;  /* 0x800AE4F8 */
L_800AE4FC:;
    R[2] = (uint32_t)(int16_t)lh_(R[9]);  /* 0x800AE4FC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AE5C8; } }  /* 0x800AE504 */
    R[2] = lh_(R[8] + -14);  /* 0x800AE50C */
    R[6] = (uint32_t)(int16_t)lh_(R[8] + -6);  /* 0x800AE510 */
    R[3] = lh_(R[8] + -8);  /* 0x800AE514 */
    R[5] = lh_(R[8] + -4);  /* 0x800AE518 */
    R[7] = R[6] + R[0];  /* 0x800AE51C */
    R[2] = R[2] + R[3];  /* 0x800AE520 */
    R[4] = R[7] + R[0];  /* 0x800AE524 */
    sh_(R[8] + -14, R[2]);  /* 0x800AE528 */
    R[2] = lh_(R[8] + -12);  /* 0x800AE52C */
    R[3] = lh_(R[8] + -10);  /* 0x800AE530 */
    R[2] = R[2] + R[4];  /* 0x800AE534 */
    R[3] = R[3] + R[5];  /* 0x800AE538 */
    sh_(R[8] + -12, R[2]);  /* 0x800AE53C */
    { uint32_t _c = ((int32_t)R[6] <= 0); sh_(R[8] + -10, R[3]); if (_c) { goto L_800AE564; } }  /* 0x800AE540 */
    R[2] = R[7] - R[11];  /* 0x800AE548 */
    R[7] = R[2] + R[0];  /* 0x800AE54C */
    R[2] = R[2] << 16;  /* 0x800AE550 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800AE584; } }  /* 0x800AE554 */
    { R[7] = R[0] + R[0]; goto L_800AE584; }  /* 0x800AE55C j */
L_800AE564:;
    R[2] = R[7] - R[11];  /* 0x800AE564 */
    R[7] = R[2] + R[0];  /* 0x800AE568 */
    R[2] = R[2] << 16;  /* 0x800AE56C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800AE570 */
    R[2] = ((int32_t)R[12] < (int32_t)R[2]);  /* 0x800AE574 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800AE584; } }  /* 0x800AE578 */
    R[7] = R[12] + R[0];  /* 0x800AE580 */
L_800AE584:;
    sh_(R[8] + -6, R[7]);  /* 0x800AE584 */
    R[2] = lh_(R[9]);  /* 0x800AE588 */
    R[2] = R[2] + 1;  /* 0x800AE590 */
    sh_(R[9], R[2]);  /* 0x800AE594 */
    R[2] = (uint32_t)(int16_t)lh_(R[8] + -12);  /* 0x800AE598 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800AE5C8; } }  /* 0x800AE5A0 */
    sh_(R[9], R[0]);  /* 0x800AE5A8 */
    R[3] = lw_(R[8]);  /* 0x800AE5AC */
    R[2] = (uint32_t)(int8_t)lb_(R[3] + 98);  /* 0x800AE5B4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AE5C8; } }  /* 0x800AE5BC */
    sb_(R[3] + 98, R[13]);  /* 0x800AE5C4 */
L_800AE5C8:;
    R[10] = R[10] + 1;  /* 0x800AE5C8 */
    R[8] = R[8] + 20;  /* 0x800AE5CC */
    R[2] = R[0] + 48;  /* 0x800AE5D0 */
    { uint32_t _c = (R[10] != R[2]); R[9] = R[9] + 20; if (_c) { psx_bb(); goto L_800AE4FC; } }  /* 0x800AE5D4 */
L_800AE5DC:;
    { psx_next = R[31]; return; }  /* 0x800AE5DC jr ra */
}

void g0_800AE5E4(void) {
    R[29] = R[29] - 24;  /* 0x800AE5E4 */
    sw_(R[29] + 16, R[31]);  /* 0x800AE5E8 */
    R[2] = (uint32_t)(int8_t)lb_(R[4] + 98);  /* 0x800AE5EC */
    R[2] = ((int32_t)R[6] < (int32_t)R[2]);  /* 0x800AE5F4 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[6] << 2; if (_c) { goto L_800AE6D8; } }  /* 0x800AE5F8 */
    R[2] = lb_(R[4] + 99);  /* 0x800AE600 */
    R[2] = R[2] + R[6];  /* 0x800AE608 */
    R[3] = R[2] << 2;  /* 0x800AE60C */
    R[3] = R[3] + R[2];  /* 0x800AE610 */
    R[3] = R[3] << 2;  /* 0x800AE614 */
    R[2] = 0x8013u << 16;  /* 0x800AE618 */
    R[2] = R[2] + 12568;  /* 0x800AE61C */
    R[4] = R[3] + R[2];  /* 0x800AE620 */
    R[2] = (uint32_t)(int16_t)lh_(R[4]);  /* 0x800AE624 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[6] << 2; if (_c) { goto L_800AE6D8; } }  /* 0x800AE62C */
    R[2] = R[2] + R[6];  /* 0x800AE634 */
    R[2] = R[2] << 4;  /* 0x800AE638 */
    R[5] = R[2] + R[5];  /* 0x800AE63C */
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 2);  /* 0x800AE640 */
    R[2] = lw_(R[5] + 8);  /* 0x800AE644 */
    R[2] = R[2] + R[3];  /* 0x800AE64C */
    sw_(R[5] + 8, R[2]);  /* 0x800AE650 */
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 4);  /* 0x800AE654 */
    R[2] = lw_(R[5] + 12);  /* 0x800AE658 */
    R[2] = R[2] - R[3];  /* 0x800AE660 */
    sw_(R[5] + 12, R[2]);  /* 0x800AE664 */
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 6);  /* 0x800AE668 */
    R[2] = lw_(R[5] + 16);  /* 0x800AE66C */
    R[2] = R[2] + R[3];  /* 0x800AE674 */
    sw_(R[5] + 16, R[2]);  /* 0x800AE678 */
    R[2] = lh_(R[4]);  /* 0x800AE67C */
    R[2] = R[2] << 16;  /* 0x800AE684 */
    R[3] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x800AE688 */
    R[2] = R[2] >> 31;  /* 0x800AE68C */
    R[3] = R[3] + R[2];  /* 0x800AE690 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x800AE694 */
    R[2] = ((int32_t)R[3] < 16);  /* 0x800AE698 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] << 2; if (_c) { goto L_800AE6AC; } }  /* 0x800AE69C */
    R[3] = R[0] + 15;  /* 0x800AE6A4 */
    R[2] = R[3] << 2;  /* 0x800AE6A8 */
L_800AE6AC:;
    R[2] = R[2] + R[3];  /* 0x800AE6AC */
    R[2] = R[2] << 2;  /* 0x800AE6B0 */
    R[4] = 0x8013u << 16;  /* 0x800AE6B4 */
    R[4] = R[4] + 13528;  /* 0x800AE6B8 */
    R[4] = R[2] + R[4];  /* 0x800AE6BC */
    R[1] = 0x8001u << 16;  /* 0x800AE6C0 */
    R[1] = R[1] | 0x88;  /* 0x800AE6C4 */
    { uint32_t _t = R[1]; R[31] = 0x800AE6D0u; R[5] = R[5] + 32; psx_next = _t; return; }  /* 0x800AE6C8 jalr */
    { goto L_800AE6EC; }  /* 0x800AE6D0 j */
L_800AE6D8:;
    R[2] = R[2] + R[6];  /* 0x800AE6D8 */
    R[2] = R[2] << 4;  /* 0x800AE6DC */
    R[2] = R[2] + R[5];  /* 0x800AE6E0 */
    R[3] = R[0] + 1;  /* 0x800AE6E4 */
    sh_(R[2], R[3]);  /* 0x800AE6E8 */
L_800AE6EC:;
    R[31] = lw_(R[29] + 16);  /* 0x800AE6EC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800AE6F4 jr ra */
}

void g0_800AE6D0(void) {
    { goto L_800AE6EC; }  /* 0x800AE6D0 j */
    R[2] = R[2] + R[6];  /* 0x800AE6D8 */
    R[2] = R[2] << 4;  /* 0x800AE6DC */
    R[2] = R[2] + R[5];  /* 0x800AE6E0 */
    R[3] = R[0] + 1;  /* 0x800AE6E4 */
    sh_(R[2], R[3]);  /* 0x800AE6E8 */
L_800AE6EC:;
    R[31] = lw_(R[29] + 16);  /* 0x800AE6EC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800AE6F4 jr ra */
}

void g0_800AE6FC(void) {
    R[29] = R[29] - 184;  /* 0x800AE6FC */
    sw_(R[29] + 156, R[19]);  /* 0x800AE700 */
    R[19] = R[4] + R[0];  /* 0x800AE704 */
    sw_(R[29] + 148, R[17]);  /* 0x800AE708 */
    R[17] = R[5] + R[0];  /* 0x800AE70C */
    sw_(R[29] + 160, R[20]);  /* 0x800AE710 */
    R[20] = R[7] + R[0];  /* 0x800AE714 */
    sw_(R[29] + 180, R[31]);  /* 0x800AE718 */
    sw_(R[29] + 176, R[30]);  /* 0x800AE71C */
    sw_(R[29] + 172, R[23]);  /* 0x800AE720 */
    sw_(R[29] + 168, R[22]);  /* 0x800AE724 */
    sw_(R[29] + 164, R[21]);  /* 0x800AE728 */
    sw_(R[29] + 152, R[18]);  /* 0x800AE72C */
    sw_(R[29] + 144, R[16]);  /* 0x800AE730 */
    R[4] = lw_(R[19] + 68);  /* 0x800AE734 */
    { R[31] = 0x800AE740u; R[5] = R[29] + 16; psx_next = 0x80025C14u; return; }  /* 0x800AE738 jal */
    R[2] = lh_(R[29] + 16);  /* 0x800AE740 */
    R[2] = R[2] >> 8;  /* 0x800AE748 */
    R[2] = R[2] & 0x7;  /* 0x800AE74C */
    sw_(R[29] + 136, R[2]);  /* 0x800AE750 */
    R[2] = lb_(R[19] + 786);  /* 0x800AE754 */
    R[2] = R[2] & 0x4;  /* 0x800AE75C */
    { uint32_t _c = (R[2] == R[0]); R[30] = R[0] + 8192; if (_c) { goto L_800AE76C; } }  /* 0x800AE760 */
    R[30] = R[0] + 10240;  /* 0x800AE768 */
L_800AE76C:;
    R[22] = lb_(R[19] + 97);  /* 0x800AE76C */
    { uint32_t _c = (R[22] == R[0]); R[16] = R[0] + R[0]; if (_c) { goto L_800AE8A4; } }  /* 0x800AE774 */
    R[2] = 0x8011u << 16;  /* 0x800AE77C */
    R[23] = R[2] + 29992;  /* 0x800AE780 */
    R[21] = R[29] + 112;  /* 0x800AE784 */
    R[18] = R[20] + R[0];  /* 0x800AE788 */
L_800AE78C:;
    R[2] = lw_(R[19] + 72);  /* 0x800AE78C */
    R[2] = lh_(R[2]);  /* 0x800AE794 */
    R[2] = R[2] & 0x8000;  /* 0x800AE79C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AE890; } }  /* 0x800AE7A0 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 18);  /* 0x800AE7A8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800AE890; } }  /* 0x800AE7B0 */
    { uint32_t _c = (R[16] != R[0]); R[6] = R[0] + R[0]; if (_c) { goto L_800AE7E8; } }  /* 0x800AE7B8 */
    R[9] = lw_(R[29] + 136);  /* 0x800AE7C0 */
    { uint32_t _c = (R[9] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_800AE7EC; } }  /* 0x800AE7C8 */
    R[3] = (uint32_t)(int16_t)lh_(R[19] + 226);  /* 0x800AE7D0 */
    R[2] = R[3] << 4;  /* 0x800AE7D8 */
    R[2] = R[2] + R[3];  /* 0x800AE7DC */
    { R[6] = R[2] << 3; goto L_800AE7EC; }  /* 0x800AE7E0 j */
L_800AE7E8:;
    R[4] = R[18] + R[0];  /* 0x800AE7E8 */
L_800AE7EC:;
    R[5] = R[17] + R[0];  /* 0x800AE7EC */
    { R[31] = 0x800AE7F8u; R[7] = 0x1F80u << 16; psx_next = 0x800277D4u; return; }  /* 0x800AE7F0 jal */
    { uint32_t _c = (R[16] != R[0]); R[3] = 0x4u << 16; if (_c) { goto L_800AE870; } }  /* 0x800AE7F8 */
    R[2] = lw_(R[19] + 16);  /* 0x800AE800 */
    R[2] = R[2] & R[3];  /* 0x800AE808 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[29] + 56; if (_c) { goto L_800AE870; } }  /* 0x800AE80C */
    R[2] = lw_(R[20] + 8);  /* 0x800AE814 */
    R[5] = R[29] + 72;  /* 0x800AE818 */
    R[2] = R[2] << 12;  /* 0x800AE81C */
    sw_(R[29] + 72, R[2]);  /* 0x800AE820 */
    R[2] = lw_(R[20] + 12);  /* 0x800AE824 */
    R[6] = R[29] + 88;  /* 0x800AE828 */
    R[2] = R[2] << 12;  /* 0x800AE82C */
    sw_(R[29] + 76, R[2]);  /* 0x800AE830 */
    R[8] = lw_(R[20] + 16);  /* 0x800AE834 */
    R[2] = lw_(R[23] + 204);  /* 0x800AE838 */
    R[7] = R[21] + R[0];  /* 0x800AE83C */
    sw_(R[29] + 56, R[2]);  /* 0x800AE840 */
    R[2] = lw_(R[23] + 208);  /* 0x800AE844 */
    R[3] = lw_(R[23] + 212);  /* 0x800AE848 */
    R[8] = R[8] << 12;  /* 0x800AE84C */
    sw_(R[29] + 80, R[8]);  /* 0x800AE850 */
    R[2] = R[0] - R[2];  /* 0x800AE854 */
    sw_(R[29] + 60, R[2]);  /* 0x800AE858 */
    { R[31] = 0x800AE864u; sw_(R[29] + 64, R[3]); psx_next = 0x800268E4u; return; }  /* 0x800AE85C jal */
    R[4] = R[21] + R[0];  /* 0x800AE864 */
    { R[31] = 0x800AE870u; R[5] = R[20] + 32; psx_next = 0x80036528u; return; }  /* 0x800AE868 jal */
L_800AE870:;
    sh_(R[18], R[30]);  /* 0x800AE870 */
    R[2] = (uint32_t)(int8_t)lb_(R[19] + 98);  /* 0x800AE874 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[19] + R[0]; if (_c) { goto L_800AE890; } }  /* 0x800AE87C */
    R[5] = R[20] + R[0];  /* 0x800AE884 */
    { R[31] = 0x800AE890u; R[6] = R[16] + R[0]; psx_next = 0x800AE5E4u; return; }  /* 0x800AE888 jal */
L_800AE890:;
    R[18] = R[18] + 80;  /* 0x800AE890 */
    R[16] = R[16] + 1;  /* 0x800AE894 */
    R[2] = ((int32_t)R[16] < (int32_t)R[22]);  /* 0x800AE898 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 20; if (_c) { psx_bb(); goto L_800AE78C; } }  /* 0x800AE89C */
L_800AE8A4:;
    R[2] = R[16] + R[0];  /* 0x800AE8A4 */
    R[31] = lw_(R[29] + 180);  /* 0x800AE8A8 */
    R[30] = lw_(R[29] + 176);  /* 0x800AE8AC */
    R[23] = lw_(R[29] + 172);  /* 0x800AE8B0 */
    R[22] = lw_(R[29] + 168);  /* 0x800AE8B4 */
    R[21] = lw_(R[29] + 164);  /* 0x800AE8B8 */
    R[20] = lw_(R[29] + 160);  /* 0x800AE8BC */
    R[19] = lw_(R[29] + 156);  /* 0x800AE8C0 */
    R[18] = lw_(R[29] + 152);  /* 0x800AE8C4 */
    R[17] = lw_(R[29] + 148);  /* 0x800AE8C8 */
    R[16] = lw_(R[29] + 144);  /* 0x800AE8CC */
    { R[29] = R[29] + 184; psx_next = R[31]; return; }  /* 0x800AE8D0 jr ra */
}

void g0_800AE740(void) {
    R[2] = lh_(R[29] + 16);  /* 0x800AE740 */
    R[2] = R[2] >> 8;  /* 0x800AE748 */
    R[2] = R[2] & 0x7;  /* 0x800AE74C */
    sw_(R[29] + 136, R[2]);  /* 0x800AE750 */
    R[2] = lb_(R[19] + 786);  /* 0x800AE754 */
    R[2] = R[2] & 0x4;  /* 0x800AE75C */
    { uint32_t _c = (R[2] == R[0]); R[30] = R[0] + 8192; if (_c) { goto L_800AE76C; } }  /* 0x800AE760 */
    R[30] = R[0] + 10240;  /* 0x800AE768 */
L_800AE76C:;
    R[22] = lb_(R[19] + 97);  /* 0x800AE76C */
    { uint32_t _c = (R[22] == R[0]); R[16] = R[0] + R[0]; if (_c) { goto L_800AE8A4; } }  /* 0x800AE774 */
    R[2] = 0x8011u << 16;  /* 0x800AE77C */
    R[23] = R[2] + 29992;  /* 0x800AE780 */
    R[21] = R[29] + 112;  /* 0x800AE784 */
    R[18] = R[20] + R[0];  /* 0x800AE788 */
L_800AE78C:;
    R[2] = lw_(R[19] + 72);  /* 0x800AE78C */
    R[2] = lh_(R[2]);  /* 0x800AE794 */
    R[2] = R[2] & 0x8000;  /* 0x800AE79C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AE890; } }  /* 0x800AE7A0 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 18);  /* 0x800AE7A8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800AE890; } }  /* 0x800AE7B0 */
    { uint32_t _c = (R[16] != R[0]); R[6] = R[0] + R[0]; if (_c) { goto L_800AE7E8; } }  /* 0x800AE7B8 */
    R[9] = lw_(R[29] + 136);  /* 0x800AE7C0 */
    { uint32_t _c = (R[9] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_800AE7EC; } }  /* 0x800AE7C8 */
    R[3] = (uint32_t)(int16_t)lh_(R[19] + 226);  /* 0x800AE7D0 */
    R[2] = R[3] << 4;  /* 0x800AE7D8 */
    R[2] = R[2] + R[3];  /* 0x800AE7DC */
    { R[6] = R[2] << 3; goto L_800AE7EC; }  /* 0x800AE7E0 j */
L_800AE7E8:;
    R[4] = R[18] + R[0];  /* 0x800AE7E8 */
L_800AE7EC:;
    R[5] = R[17] + R[0];  /* 0x800AE7EC */
    { R[31] = 0x800AE7F8u; R[7] = 0x1F80u << 16; psx_next = 0x800277D4u; return; }  /* 0x800AE7F0 jal */
    { uint32_t _c = (R[16] != R[0]); R[3] = 0x4u << 16; if (_c) { goto L_800AE870; } }  /* 0x800AE7F8 */
    R[2] = lw_(R[19] + 16);  /* 0x800AE800 */
    R[2] = R[2] & R[3];  /* 0x800AE808 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[29] + 56; if (_c) { goto L_800AE870; } }  /* 0x800AE80C */
    R[2] = lw_(R[20] + 8);  /* 0x800AE814 */
    R[5] = R[29] + 72;  /* 0x800AE818 */
    R[2] = R[2] << 12;  /* 0x800AE81C */
    sw_(R[29] + 72, R[2]);  /* 0x800AE820 */
    R[2] = lw_(R[20] + 12);  /* 0x800AE824 */
    R[6] = R[29] + 88;  /* 0x800AE828 */
    R[2] = R[2] << 12;  /* 0x800AE82C */
    sw_(R[29] + 76, R[2]);  /* 0x800AE830 */
    R[8] = lw_(R[20] + 16);  /* 0x800AE834 */
    R[2] = lw_(R[23] + 204);  /* 0x800AE838 */
    R[7] = R[21] + R[0];  /* 0x800AE83C */
    sw_(R[29] + 56, R[2]);  /* 0x800AE840 */
    R[2] = lw_(R[23] + 208);  /* 0x800AE844 */
    R[3] = lw_(R[23] + 212);  /* 0x800AE848 */
    R[8] = R[8] << 12;  /* 0x800AE84C */
    sw_(R[29] + 80, R[8]);  /* 0x800AE850 */
    R[2] = R[0] - R[2];  /* 0x800AE854 */
    sw_(R[29] + 60, R[2]);  /* 0x800AE858 */
    { R[31] = 0x800AE864u; sw_(R[29] + 64, R[3]); psx_next = 0x800268E4u; return; }  /* 0x800AE85C jal */
    R[4] = R[21] + R[0];  /* 0x800AE864 */
    { R[31] = 0x800AE870u; R[5] = R[20] + 32; psx_next = 0x80036528u; return; }  /* 0x800AE868 jal */
L_800AE870:;
    sh_(R[18], R[30]);  /* 0x800AE870 */
    R[2] = (uint32_t)(int8_t)lb_(R[19] + 98);  /* 0x800AE874 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[19] + R[0]; if (_c) { goto L_800AE890; } }  /* 0x800AE87C */
    R[5] = R[20] + R[0];  /* 0x800AE884 */
    { R[31] = 0x800AE890u; R[6] = R[16] + R[0]; psx_next = 0x800AE5E4u; return; }  /* 0x800AE888 jal */
L_800AE890:;
    R[18] = R[18] + 80;  /* 0x800AE890 */
    R[16] = R[16] + 1;  /* 0x800AE894 */
    R[2] = ((int32_t)R[16] < (int32_t)R[22]);  /* 0x800AE898 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 20; if (_c) { psx_bb(); goto L_800AE78C; } }  /* 0x800AE89C */
L_800AE8A4:;
    R[2] = R[16] + R[0];  /* 0x800AE8A4 */
    R[31] = lw_(R[29] + 180);  /* 0x800AE8A8 */
    R[30] = lw_(R[29] + 176);  /* 0x800AE8AC */
    R[23] = lw_(R[29] + 172);  /* 0x800AE8B0 */
    R[22] = lw_(R[29] + 168);  /* 0x800AE8B4 */
    R[21] = lw_(R[29] + 164);  /* 0x800AE8B8 */
    R[20] = lw_(R[29] + 160);  /* 0x800AE8BC */
    R[19] = lw_(R[29] + 156);  /* 0x800AE8C0 */
    R[18] = lw_(R[29] + 152);  /* 0x800AE8C4 */
    R[17] = lw_(R[29] + 148);  /* 0x800AE8C8 */
    R[16] = lw_(R[29] + 144);  /* 0x800AE8CC */
    { R[29] = R[29] + 184; psx_next = R[31]; return; }  /* 0x800AE8D0 jr ra */
}

void g0_800AE78C(void) {
L_800AE78C:;
    R[2] = lw_(R[19] + 72);  /* 0x800AE78C */
    R[2] = lh_(R[2]);  /* 0x800AE794 */
    R[2] = R[2] & 0x8000;  /* 0x800AE79C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AE890; } }  /* 0x800AE7A0 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 18);  /* 0x800AE7A8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_800AE890; } }  /* 0x800AE7B0 */
    { uint32_t _c = (R[16] != R[0]); R[6] = R[0] + R[0]; if (_c) { goto L_800AE7E8; } }  /* 0x800AE7B8 */
    R[9] = lw_(R[29] + 136);  /* 0x800AE7C0 */
    { uint32_t _c = (R[9] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_800AE7EC; } }  /* 0x800AE7C8 */
    R[3] = (uint32_t)(int16_t)lh_(R[19] + 226);  /* 0x800AE7D0 */
    R[2] = R[3] << 4;  /* 0x800AE7D8 */
    R[2] = R[2] + R[3];  /* 0x800AE7DC */
    { R[6] = R[2] << 3; goto L_800AE7EC; }  /* 0x800AE7E0 j */
L_800AE7E8:;
    R[4] = R[18] + R[0];  /* 0x800AE7E8 */
L_800AE7EC:;
    R[5] = R[17] + R[0];  /* 0x800AE7EC */
    { R[31] = 0x800AE7F8u; R[7] = 0x1F80u << 16; psx_next = 0x800277D4u; return; }  /* 0x800AE7F0 jal */
    { uint32_t _c = (R[16] != R[0]); R[3] = 0x4u << 16; if (_c) { goto L_800AE870; } }  /* 0x800AE7F8 */
    R[2] = lw_(R[19] + 16);  /* 0x800AE800 */
    R[2] = R[2] & R[3];  /* 0x800AE808 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[29] + 56; if (_c) { goto L_800AE870; } }  /* 0x800AE80C */
    R[2] = lw_(R[20] + 8);  /* 0x800AE814 */
    R[5] = R[29] + 72;  /* 0x800AE818 */
    R[2] = R[2] << 12;  /* 0x800AE81C */
    sw_(R[29] + 72, R[2]);  /* 0x800AE820 */
    R[2] = lw_(R[20] + 12);  /* 0x800AE824 */
    R[6] = R[29] + 88;  /* 0x800AE828 */
    R[2] = R[2] << 12;  /* 0x800AE82C */
    sw_(R[29] + 76, R[2]);  /* 0x800AE830 */
    R[8] = lw_(R[20] + 16);  /* 0x800AE834 */
    R[2] = lw_(R[23] + 204);  /* 0x800AE838 */
    R[7] = R[21] + R[0];  /* 0x800AE83C */
    sw_(R[29] + 56, R[2]);  /* 0x800AE840 */
    R[2] = lw_(R[23] + 208);  /* 0x800AE844 */
    R[3] = lw_(R[23] + 212);  /* 0x800AE848 */
    R[8] = R[8] << 12;  /* 0x800AE84C */
    sw_(R[29] + 80, R[8]);  /* 0x800AE850 */
    R[2] = R[0] - R[2];  /* 0x800AE854 */
    sw_(R[29] + 60, R[2]);  /* 0x800AE858 */
    { R[31] = 0x800AE864u; sw_(R[29] + 64, R[3]); psx_next = 0x800268E4u; return; }  /* 0x800AE85C jal */
    R[4] = R[21] + R[0];  /* 0x800AE864 */
    { R[31] = 0x800AE870u; R[5] = R[20] + 32; psx_next = 0x80036528u; return; }  /* 0x800AE868 jal */
L_800AE870:;
    sh_(R[18], R[30]);  /* 0x800AE870 */
    R[2] = (uint32_t)(int8_t)lb_(R[19] + 98);  /* 0x800AE874 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[19] + R[0]; if (_c) { goto L_800AE890; } }  /* 0x800AE87C */
    R[5] = R[20] + R[0];  /* 0x800AE884 */
    { R[31] = 0x800AE890u; R[6] = R[16] + R[0]; psx_next = 0x800AE5E4u; return; }  /* 0x800AE888 jal */
L_800AE890:;
    R[18] = R[18] + 80;  /* 0x800AE890 */
    R[16] = R[16] + 1;  /* 0x800AE894 */
    R[2] = ((int32_t)R[16] < (int32_t)R[22]);  /* 0x800AE898 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 20; if (_c) { psx_bb(); goto L_800AE78C; } }  /* 0x800AE89C */
    R[2] = R[16] + R[0];  /* 0x800AE8A4 */
    R[31] = lw_(R[29] + 180);  /* 0x800AE8A8 */
    R[30] = lw_(R[29] + 176);  /* 0x800AE8AC */
    R[23] = lw_(R[29] + 172);  /* 0x800AE8B0 */
    R[22] = lw_(R[29] + 168);  /* 0x800AE8B4 */
    R[21] = lw_(R[29] + 164);  /* 0x800AE8B8 */
    R[20] = lw_(R[29] + 160);  /* 0x800AE8BC */
    R[19] = lw_(R[29] + 156);  /* 0x800AE8C0 */
    R[18] = lw_(R[29] + 152);  /* 0x800AE8C4 */
    R[17] = lw_(R[29] + 148);  /* 0x800AE8C8 */
    R[16] = lw_(R[29] + 144);  /* 0x800AE8CC */
    { R[29] = R[29] + 184; psx_next = R[31]; return; }  /* 0x800AE8D0 jr ra */
}

void g0_800AE7F8(void) {
    { uint32_t _c = (R[16] != R[0]); R[3] = 0x4u << 16; if (_c) { goto L_800AE870; } }  /* 0x800AE7F8 */
    R[2] = lw_(R[19] + 16);  /* 0x800AE800 */
    R[2] = R[2] & R[3];  /* 0x800AE808 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[29] + 56; if (_c) { goto L_800AE870; } }  /* 0x800AE80C */
    R[2] = lw_(R[20] + 8);  /* 0x800AE814 */
    R[5] = R[29] + 72;  /* 0x800AE818 */
    R[2] = R[2] << 12;  /* 0x800AE81C */
    sw_(R[29] + 72, R[2]);  /* 0x800AE820 */
    R[2] = lw_(R[20] + 12);  /* 0x800AE824 */
    R[6] = R[29] + 88;  /* 0x800AE828 */
    R[2] = R[2] << 12;  /* 0x800AE82C */
    sw_(R[29] + 76, R[2]);  /* 0x800AE830 */
    R[8] = lw_(R[20] + 16);  /* 0x800AE834 */
    R[2] = lw_(R[23] + 204);  /* 0x800AE838 */
    R[7] = R[21] + R[0];  /* 0x800AE83C */
    sw_(R[29] + 56, R[2]);  /* 0x800AE840 */
    R[2] = lw_(R[23] + 208);  /* 0x800AE844 */
    R[3] = lw_(R[23] + 212);  /* 0x800AE848 */
    R[8] = R[8] << 12;  /* 0x800AE84C */
    sw_(R[29] + 80, R[8]);  /* 0x800AE850 */
    R[2] = R[0] - R[2];  /* 0x800AE854 */
    sw_(R[29] + 60, R[2]);  /* 0x800AE858 */
    { R[31] = 0x800AE864u; sw_(R[29] + 64, R[3]); psx_next = 0x800268E4u; return; }  /* 0x800AE85C jal */
    R[4] = R[21] + R[0];  /* 0x800AE864 */
    { R[31] = 0x800AE870u; R[5] = R[20] + 32; psx_next = 0x80036528u; return; }  /* 0x800AE868 jal */
L_800AE870:;
    sh_(R[18], R[30]);  /* 0x800AE870 */
    R[2] = (uint32_t)(int8_t)lb_(R[19] + 98);  /* 0x800AE874 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[19] + R[0]; if (_c) { goto L_800AE890; } }  /* 0x800AE87C */
    R[5] = R[20] + R[0];  /* 0x800AE884 */
    { R[31] = 0x800AE890u; R[6] = R[16] + R[0]; psx_next = 0x800AE5E4u; return; }  /* 0x800AE888 jal */
L_800AE890:;
    R[18] = R[18] + 80;  /* 0x800AE890 */
    R[16] = R[16] + 1;  /* 0x800AE894 */
    R[2] = ((int32_t)R[16] < (int32_t)R[22]);  /* 0x800AE898 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 20; if (_c) { psx_next = 0x800AE78Cu; return; } }  /* 0x800AE89C b extern */
    R[2] = R[16] + R[0];  /* 0x800AE8A4 */
    R[31] = lw_(R[29] + 180);  /* 0x800AE8A8 */
    R[30] = lw_(R[29] + 176);  /* 0x800AE8AC */
    R[23] = lw_(R[29] + 172);  /* 0x800AE8B0 */
    R[22] = lw_(R[29] + 168);  /* 0x800AE8B4 */
    R[21] = lw_(R[29] + 164);  /* 0x800AE8B8 */
    R[20] = lw_(R[29] + 160);  /* 0x800AE8BC */
    R[19] = lw_(R[29] + 156);  /* 0x800AE8C0 */
    R[18] = lw_(R[29] + 152);  /* 0x800AE8C4 */
    R[17] = lw_(R[29] + 148);  /* 0x800AE8C8 */
    R[16] = lw_(R[29] + 144);  /* 0x800AE8CC */
    { R[29] = R[29] + 184; psx_next = R[31]; return; }  /* 0x800AE8D0 jr ra */
}

void g0_800AE864(void) {
    R[4] = R[21] + R[0];  /* 0x800AE864 */
    { R[31] = 0x800AE870u; R[5] = R[20] + 32; psx_next = 0x80036528u; return; }  /* 0x800AE868 jal */
    sh_(R[18], R[30]);  /* 0x800AE870 */
    R[2] = (uint32_t)(int8_t)lb_(R[19] + 98);  /* 0x800AE874 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[19] + R[0]; if (_c) { goto L_800AE890; } }  /* 0x800AE87C */
    R[5] = R[20] + R[0];  /* 0x800AE884 */
    { R[31] = 0x800AE890u; R[6] = R[16] + R[0]; psx_next = 0x800AE5E4u; return; }  /* 0x800AE888 jal */
L_800AE890:;
    R[18] = R[18] + 80;  /* 0x800AE890 */
    R[16] = R[16] + 1;  /* 0x800AE894 */
    R[2] = ((int32_t)R[16] < (int32_t)R[22]);  /* 0x800AE898 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 20; if (_c) { psx_next = 0x800AE78Cu; return; } }  /* 0x800AE89C b extern */
    R[2] = R[16] + R[0];  /* 0x800AE8A4 */
    R[31] = lw_(R[29] + 180);  /* 0x800AE8A8 */
    R[30] = lw_(R[29] + 176);  /* 0x800AE8AC */
    R[23] = lw_(R[29] + 172);  /* 0x800AE8B0 */
    R[22] = lw_(R[29] + 168);  /* 0x800AE8B4 */
    R[21] = lw_(R[29] + 164);  /* 0x800AE8B8 */
    R[20] = lw_(R[29] + 160);  /* 0x800AE8BC */
    R[19] = lw_(R[29] + 156);  /* 0x800AE8C0 */
    R[18] = lw_(R[29] + 152);  /* 0x800AE8C4 */
    R[17] = lw_(R[29] + 148);  /* 0x800AE8C8 */
    R[16] = lw_(R[29] + 144);  /* 0x800AE8CC */
    { R[29] = R[29] + 184; psx_next = R[31]; return; }  /* 0x800AE8D0 jr ra */
}

void g0_800AE870(void) {
    sh_(R[18], R[30]);  /* 0x800AE870 */
    R[2] = (uint32_t)(int8_t)lb_(R[19] + 98);  /* 0x800AE874 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[19] + R[0]; if (_c) { goto L_800AE890; } }  /* 0x800AE87C */
    R[5] = R[20] + R[0];  /* 0x800AE884 */
    { R[31] = 0x800AE890u; R[6] = R[16] + R[0]; psx_next = 0x800AE5E4u; return; }  /* 0x800AE888 jal */
L_800AE890:;
    R[18] = R[18] + 80;  /* 0x800AE890 */
    R[16] = R[16] + 1;  /* 0x800AE894 */
    R[2] = ((int32_t)R[16] < (int32_t)R[22]);  /* 0x800AE898 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 20; if (_c) { psx_next = 0x800AE78Cu; return; } }  /* 0x800AE89C b extern */
    R[2] = R[16] + R[0];  /* 0x800AE8A4 */
    R[31] = lw_(R[29] + 180);  /* 0x800AE8A8 */
    R[30] = lw_(R[29] + 176);  /* 0x800AE8AC */
    R[23] = lw_(R[29] + 172);  /* 0x800AE8B0 */
    R[22] = lw_(R[29] + 168);  /* 0x800AE8B4 */
    R[21] = lw_(R[29] + 164);  /* 0x800AE8B8 */
    R[20] = lw_(R[29] + 160);  /* 0x800AE8BC */
    R[19] = lw_(R[29] + 156);  /* 0x800AE8C0 */
    R[18] = lw_(R[29] + 152);  /* 0x800AE8C4 */
    R[17] = lw_(R[29] + 148);  /* 0x800AE8C8 */
    R[16] = lw_(R[29] + 144);  /* 0x800AE8CC */
    { R[29] = R[29] + 184; psx_next = R[31]; return; }  /* 0x800AE8D0 jr ra */
}

void g0_800AE890(void) {
    R[18] = R[18] + 80;  /* 0x800AE890 */
    R[16] = R[16] + 1;  /* 0x800AE894 */
    R[2] = ((int32_t)R[16] < (int32_t)R[22]);  /* 0x800AE898 */
    { uint32_t _c = (R[2] != R[0]); R[17] = R[17] + 20; if (_c) { psx_next = 0x800AE78Cu; return; } }  /* 0x800AE89C b extern */
    R[2] = R[16] + R[0];  /* 0x800AE8A4 */
    R[31] = lw_(R[29] + 180);  /* 0x800AE8A8 */
    R[30] = lw_(R[29] + 176);  /* 0x800AE8AC */
    R[23] = lw_(R[29] + 172);  /* 0x800AE8B0 */
    R[22] = lw_(R[29] + 168);  /* 0x800AE8B4 */
    R[21] = lw_(R[29] + 164);  /* 0x800AE8B8 */
    R[20] = lw_(R[29] + 160);  /* 0x800AE8BC */
    R[19] = lw_(R[29] + 156);  /* 0x800AE8C0 */
    R[18] = lw_(R[29] + 152);  /* 0x800AE8C4 */
    R[17] = lw_(R[29] + 148);  /* 0x800AE8C8 */
    R[16] = lw_(R[29] + 144);  /* 0x800AE8CC */
    { R[29] = R[29] + 184; psx_next = R[31]; return; }  /* 0x800AE8D0 jr ra */
}

void g0_800AE8D8(void) {
    R[29] = R[29] - 24;  /* 0x800AE8D8 */
    R[5] = R[4] + R[0];  /* 0x800AE8DC */
    sw_(R[29] + 16, R[31]);  /* 0x800AE8E0 */
    R[3] = (uint32_t)(int16_t)lh_(R[5] + 4);  /* 0x800AE8E4 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 256; if (_c) { goto L_800AE8FC; } }  /* 0x800AE8EC */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800AE954; } }  /* 0x800AE8F4 */
L_800AE8FC:;
    R[2] = lw_(R[5] + 492);  /* 0x800AE8FC */
    R[4] = lw_(R[5] + 484);  /* 0x800AE900 */
    sw_(R[5] + 484, R[2]);  /* 0x800AE904 */
    R[3] = R[2] + R[0];  /* 0x800AE908 */
    R[2] = R[3] >> 31;  /* 0x800AE90C */
    R[3] = R[3] + R[2];  /* 0x800AE910 */
    R[2] = lw_(R[5] + 24);  /* 0x800AE914 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x800AE918 */
    sw_(R[5] + 492, R[4]);  /* 0x800AE91C */
    R[2] = R[2] - R[3];  /* 0x800AE920 */
    sw_(R[5] + 472, R[2]);  /* 0x800AE924 */
    R[2] = R[4] >> 31;  /* 0x800AE928 */
    R[4] = R[4] + R[2];  /* 0x800AE92C */
    R[2] = lw_(R[5] + 32);  /* 0x800AE930 */
    R[4] = (uint32_t)((int32_t)R[4] >> 1);  /* 0x800AE934 */
    R[2] = R[2] - R[4];  /* 0x800AE938 */
    R[4] = R[5] + R[0];  /* 0x800AE93C */
    sw_(R[5] + 480, R[2]);  /* 0x800AE940 */
    R[5] = R[0] + R[0];  /* 0x800AE944 */
    R[6] = R[5] + R[0];  /* 0x800AE948 */
    { R[31] = 0x800AE954u; R[7] = R[5] + R[0]; psx_next = 0x8008CF6Cu; return; }  /* 0x800AE94C jal */
L_800AE954:;
    R[31] = lw_(R[29] + 16);  /* 0x800AE954 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800AE95C jr ra */
}

void g0_800AE954(void) {
    R[31] = lw_(R[29] + 16);  /* 0x800AE954 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800AE95C jr ra */
}

void g0_800AE964(void) {
    R[29] = R[29] - 48;  /* 0x800AE964 */
    sw_(R[29] + 28, R[17]);  /* 0x800AE968 */
    R[17] = R[5] + R[0];  /* 0x800AE96C */
    R[2] = 0x800Fu << 16;  /* 0x800AE970 */
    R[2] = R[2] - 12516;  /* 0x800AE974 */
    R[4] = R[4] << 2;  /* 0x800AE978 */
    R[4] = R[4] + R[2];  /* 0x800AE97C */
    sw_(R[29] + 40, R[31]);  /* 0x800AE980 */
    sw_(R[29] + 36, R[19]);  /* 0x800AE984 */
    sw_(R[29] + 32, R[18]);  /* 0x800AE988 */
    sw_(R[29] + 24, R[16]);  /* 0x800AE98C */
    R[16] = lw_(R[4]);  /* 0x800AE990 */
    R[18] = R[6] + R[0];  /* 0x800AE994 */
    R[4] = lb_(R[16]);  /* 0x800AE998 */
    { uint32_t _c = (R[4] == R[0]); R[19] = R[7] + R[0]; if (_c) { goto L_800AE9E0; } }  /* 0x800AE9A0 */
    { R[31] = 0x800AE9B0u; psx_next = 0x800908F4u; return; }  /* 0x800AE9A8 jal */
    R[2] = R[2] + R[16];  /* 0x800AE9B0 */
    R[4] = lb_(R[2] + 1);  /* 0x800AE9B4 */
    { uint32_t _c = (R[4] == R[0]); R[5] = R[17] + R[0]; if (_c) { goto L_800AE9E0; } }  /* 0x800AE9BC */
    R[6] = R[18] + R[0];  /* 0x800AE9C4 */
    R[2] = lw_(R[29] + 64);  /* 0x800AE9C8 */
    R[7] = R[19] + R[0];  /* 0x800AE9CC */
    sw_(R[29] + 16, R[2]);  /* 0x800AE9D0 */
    R[2] = R[0] + 1;  /* 0x800AE9D4 */
    { R[31] = 0x800AE9E0u; sw_(R[29] + 20, R[2]); psx_next = 0x800B42B8u; return; }  /* 0x800AE9D8 jal */
L_800AE9E0:;
    R[31] = lw_(R[29] + 40);  /* 0x800AE9E0 */
    R[19] = lw_(R[29] + 36);  /* 0x800AE9E4 */
    R[18] = lw_(R[29] + 32);  /* 0x800AE9E8 */
    R[17] = lw_(R[29] + 28);  /* 0x800AE9EC */
    R[16] = lw_(R[29] + 24);  /* 0x800AE9F0 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800AE9F4 jr ra */
}

void g0_800AE9B0(void) {
    R[2] = R[2] + R[16];  /* 0x800AE9B0 */
    R[4] = lb_(R[2] + 1);  /* 0x800AE9B4 */
    { uint32_t _c = (R[4] == R[0]); R[5] = R[17] + R[0]; if (_c) { goto L_800AE9E0; } }  /* 0x800AE9BC */
    R[6] = R[18] + R[0];  /* 0x800AE9C4 */
    R[2] = lw_(R[29] + 64);  /* 0x800AE9C8 */
    R[7] = R[19] + R[0];  /* 0x800AE9CC */
    sw_(R[29] + 16, R[2]);  /* 0x800AE9D0 */
    R[2] = R[0] + 1;  /* 0x800AE9D4 */
    { R[31] = 0x800AE9E0u; sw_(R[29] + 20, R[2]); psx_next = 0x800B42B8u; return; }  /* 0x800AE9D8 jal */
L_800AE9E0:;
    R[31] = lw_(R[29] + 40);  /* 0x800AE9E0 */
    R[19] = lw_(R[29] + 36);  /* 0x800AE9E4 */
    R[18] = lw_(R[29] + 32);  /* 0x800AE9E8 */
    R[17] = lw_(R[29] + 28);  /* 0x800AE9EC */
    R[16] = lw_(R[29] + 24);  /* 0x800AE9F0 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800AE9F4 jr ra */
}

void g0_800AE9E0(void) {
    R[31] = lw_(R[29] + 40);  /* 0x800AE9E0 */
    R[19] = lw_(R[29] + 36);  /* 0x800AE9E4 */
    R[18] = lw_(R[29] + 32);  /* 0x800AE9E8 */
    R[17] = lw_(R[29] + 28);  /* 0x800AE9EC */
    R[16] = lw_(R[29] + 24);  /* 0x800AE9F0 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800AE9F4 jr ra */
}

void g0_800AE9FC(void) {
    R[29] = R[29] - 24;  /* 0x800AE9FC */
    sw_(R[29] + 16, R[31]);  /* 0x800AEA00 */
    R[2] = lw_(R[4] + 16);  /* 0x800AEA04 */
    R[3] = R[2] & 0xC000;  /* 0x800AEA0C */
    R[2] = R[0] + 16384;  /* 0x800AEA10 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_800AEA24; } }  /* 0x800AEA14 */
    R[2] = R[2] - 6404;  /* 0x800AEA1C */
    sw_(R[4] + 232, R[2]);  /* 0x800AEA20 */
L_800AEA24:;
    { uint32_t _c = (R[3] != R[0]); R[2] = 0x800Bu << 16; if (_c) { goto L_800AEA34; } }  /* 0x800AEA24 */
    R[2] = R[2] - 4668;  /* 0x800AEA2C */
    sw_(R[4] + 232, R[2]);  /* 0x800AEA30 */
L_800AEA34:;
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 10);  /* 0x800AEA34 */
    R[2] = R[0] + 1;  /* 0x800AEA38 */
    sb_(R[4] + 690, R[2]);  /* 0x800AEA3C */
    R[2] = R[0] + 416;  /* 0x800AEA40 */
    sb_(R[4] + 688, R[0]);  /* 0x800AEA44 */
    sb_(R[4] + 689, R[0]);  /* 0x800AEA48 */
    { uint32_t _c = (R[3] == R[2]); sb_(R[4] + 691, R[0]); if (_c) { goto L_800AEA78; } }  /* 0x800AEA4C */
    R[2] = R[0] + 413;  /* 0x800AEA54 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 454; if (_c) { goto L_800AEA78; } }  /* 0x800AEA58 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 219; if (_c) { goto L_800AEA78; } }  /* 0x800AEA60 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 462; if (_c) { goto L_800AEA78; } }  /* 0x800AEA68 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800AEA80; } }  /* 0x800AEA70 */
L_800AEA78:;
    { R[31] = 0x800AEA80u; psx_next = 0x800AE8D8u; return; }  /* 0x800AEA78 jal */
L_800AEA80:;
    R[31] = lw_(R[29] + 16);  /* 0x800AEA80 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800AEA88 jr ra */
}

void g0_800AEA80(void) {
    R[31] = lw_(R[29] + 16);  /* 0x800AEA80 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800AEA88 jr ra */
}

void g0_800AEA90(void) {
    R[29] = R[29] - 24;  /* 0x800AEA90 */
    sw_(R[29] + 16, R[16]);  /* 0x800AEA94 */
    R[16] = R[4] + R[0];  /* 0x800AEA98 */
    R[2] = (R[5] < (uint32_t)6u);  /* 0x800AEA9C */
    { uint32_t _c = (R[2] == R[0]); sw_(R[29] + 20, R[31]); if (_c) { goto L_800AEB14; } }  /* 0x800AEAA0 */
    R[2] = 0x8008u << 16;  /* 0x800AEAA8 */
    R[2] = R[2] + 9540;  /* 0x800AEAAC */
    R[3] = R[5] << 2;  /* 0x800AEAB0 */
    R[3] = R[3] + R[2];  /* 0x800AEAB4 */
    R[2] = lw_(R[3]);  /* 0x800AEAB8 */
    { uint32_t _t = R[2]; psx_next = _t; return; }  /* 0x800AEAC0 jr indirect */
    { R[31] = 0x800AEAD0u; R[4] = R[16] + R[0]; psx_next = 0x800AE9FCu; return; }  /* 0x800AEAC8 jal */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 10);  /* 0x800AEAD0 */
    R[2] = R[0] + 257;  /* 0x800AEAD4 */
    { uint32_t _c = (R[3] != R[2]); R[3] = 0x8011u << 16; if (_c) { goto L_800AEB14; } }  /* 0x800AEAD8 */
    R[2] = lh_(R[16] + 2);  /* 0x800AEAE0 */
    R[3] = R[3] + 30992;  /* 0x800AEAE4 */
    R[2] = R[2] << 7;  /* 0x800AEAE8 */
    R[2] = R[2] + R[3];  /* 0x800AEAEC */
    R[3] = lw_(R[16] + 92);  /* 0x800AEAF0 */
    R[4] = lw_(R[2] + 4);  /* 0x800AEAF4 */
    R[5] = lw_(R[3] + 4);  /* 0x800AEAF8 */
    { R[31] = 0x800AEB04u; R[6] = R[0] + 1; psx_next = 0x80024FDCu; return; }  /* 0x800AEAFC jal */
    { goto L_800AEB14; }  /* 0x800AEB04 j */
    { R[31] = 0x800AEB14u; R[4] = R[16] + R[0]; psx_next = 0x800B1570u; return; }  /* 0x800AEB0C jal */
L_800AEB14:;
    R[31] = lw_(R[29] + 20);  /* 0x800AEB14 */
    R[16] = lw_(R[29] + 16);  /* 0x800AEB18 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800AEB1C jr ra */
}

void g0_800AEAC8(void) {
    { R[31] = 0x800AEAD0u; R[4] = R[16] + R[0]; psx_next = 0x800AE9FCu; return; }  /* 0x800AEAC8 jal */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 10);  /* 0x800AEAD0 */
    R[2] = R[0] + 257;  /* 0x800AEAD4 */
    { uint32_t _c = (R[3] != R[2]); R[3] = 0x8011u << 16; if (_c) { goto L_800AEB14; } }  /* 0x800AEAD8 */
    R[2] = lh_(R[16] + 2);  /* 0x800AEAE0 */
    R[3] = R[3] + 30992;  /* 0x800AEAE4 */
    R[2] = R[2] << 7;  /* 0x800AEAE8 */
    R[2] = R[2] + R[3];  /* 0x800AEAEC */
    R[3] = lw_(R[16] + 92);  /* 0x800AEAF0 */
    R[4] = lw_(R[2] + 4);  /* 0x800AEAF4 */
    R[5] = lw_(R[3] + 4);  /* 0x800AEAF8 */
    { R[31] = 0x800AEB04u; R[6] = R[0] + 1; psx_next = 0x80024FDCu; return; }  /* 0x800AEAFC jal */
    { goto L_800AEB14; }  /* 0x800AEB04 j */
    { R[31] = 0x800AEB14u; R[4] = R[16] + R[0]; psx_next = 0x800B1570u; return; }  /* 0x800AEB0C jal */
L_800AEB14:;
    R[31] = lw_(R[29] + 20);  /* 0x800AEB14 */
    R[16] = lw_(R[29] + 16);  /* 0x800AEB18 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800AEB1C jr ra */
}

void g0_800AEAD0(void) {
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 10);  /* 0x800AEAD0 */
    R[2] = R[0] + 257;  /* 0x800AEAD4 */
    { uint32_t _c = (R[3] != R[2]); R[3] = 0x8011u << 16; if (_c) { goto L_800AEB14; } }  /* 0x800AEAD8 */
    R[2] = lh_(R[16] + 2);  /* 0x800AEAE0 */
    R[3] = R[3] + 30992;  /* 0x800AEAE4 */
    R[2] = R[2] << 7;  /* 0x800AEAE8 */
    R[2] = R[2] + R[3];  /* 0x800AEAEC */
    R[3] = lw_(R[16] + 92);  /* 0x800AEAF0 */
    R[4] = lw_(R[2] + 4);  /* 0x800AEAF4 */
    R[5] = lw_(R[3] + 4);  /* 0x800AEAF8 */
    { R[31] = 0x800AEB04u; R[6] = R[0] + 1; psx_next = 0x80024FDCu; return; }  /* 0x800AEAFC jal */
    { goto L_800AEB14; }  /* 0x800AEB04 j */
    { R[31] = 0x800AEB14u; R[4] = R[16] + R[0]; psx_next = 0x800B1570u; return; }  /* 0x800AEB0C jal */
L_800AEB14:;
    R[31] = lw_(R[29] + 20);  /* 0x800AEB14 */
    R[16] = lw_(R[29] + 16);  /* 0x800AEB18 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800AEB1C jr ra */
}

void g0_800AEB04(void) {
    { goto L_800AEB14; }  /* 0x800AEB04 j */
    { R[31] = 0x800AEB14u; R[4] = R[16] + R[0]; psx_next = 0x800B1570u; return; }  /* 0x800AEB0C jal */
L_800AEB14:;
    R[31] = lw_(R[29] + 20);  /* 0x800AEB14 */
    R[16] = lw_(R[29] + 16);  /* 0x800AEB18 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800AEB1C jr ra */
}

void g0_800AEB0C(void) {
    { R[31] = 0x800AEB14u; R[4] = R[16] + R[0]; psx_next = 0x800B1570u; return; }  /* 0x800AEB0C jal */
    R[31] = lw_(R[29] + 20);  /* 0x800AEB14 */
    R[16] = lw_(R[29] + 16);  /* 0x800AEB18 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800AEB1C jr ra */
}

void g0_800AEB14(void) {
    R[31] = lw_(R[29] + 20);  /* 0x800AEB14 */
    R[16] = lw_(R[29] + 16);  /* 0x800AEB18 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x800AEB1C jr ra */
}

void g0_800AEB24(void) {
    R[29] = R[29] - 128;  /* 0x800AEB24 */
    sw_(R[29] + 96, R[18]);  /* 0x800AEB28 */
    R[18] = R[4] + R[0];  /* 0x800AEB2C */
    sw_(R[29] + 104, R[20]);  /* 0x800AEB30 */
    sw_(R[29] + 108, R[21]);  /* 0x800AEB34 */
    R[21] = R[7] + R[0];  /* 0x800AEB38 */
    sw_(R[29] + 124, R[31]);  /* 0x800AEB3C */
    sw_(R[29] + 120, R[30]);  /* 0x800AEB40 */
    sw_(R[29] + 116, R[23]);  /* 0x800AEB44 */
    sw_(R[29] + 112, R[22]);  /* 0x800AEB48 */
    sw_(R[29] + 100, R[19]);  /* 0x800AEB4C */
    sw_(R[29] + 92, R[17]);  /* 0x800AEB50 */
    sw_(R[29] + 88, R[16]);  /* 0x800AEB54 */
    sw_(R[29] + 132, R[5]);  /* 0x800AEB58 */
    R[2] = lw_(R[21]);  /* 0x800AEB5C */
    R[19] = lw_(R[29] + 144);  /* 0x800AEB60 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[20] = R[6] + R[0]; if (_c) { goto L_800AEB70; } }  /* 0x800AEB64 */
    R[2] = R[2] + 4095;  /* 0x800AEB6C */
L_800AEB70:;
    R[3] = lw_(R[21] + 4);  /* 0x800AEB70 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800AEB74 */
    { uint32_t _c = ((int32_t)R[3] >= 0); sw_(R[29] + 72, R[2]); if (_c) { goto L_800AEB84; } }  /* 0x800AEB78 */
    R[3] = R[3] + 4095;  /* 0x800AEB80 */
L_800AEB84:;
    R[2] = lw_(R[21] + 8);  /* 0x800AEB84 */
    R[3] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x800AEB88 */
    { uint32_t _c = ((int32_t)R[2] >= 0); sw_(R[29] + 76, R[3]); if (_c) { goto L_800AEB98; } }  /* 0x800AEB8C */
    R[2] = R[2] + 4095;  /* 0x800AEB94 */
L_800AEB98:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800AEB98 */
    sw_(R[29] + 80, R[2]);  /* 0x800AEB9C */
    R[3] = lw_(R[18] + 16);  /* 0x800AEBA0 */
    R[2] = 0x4u << 16;  /* 0x800AEBA4 */
    R[30] = R[3] & R[2];  /* 0x800AEBA8 */
    R[3] = (uint32_t)(int8_t)lb_(R[18] + 98);  /* 0x800AEBAC */
    R[2] = R[0] - 1;  /* 0x800AEBB0 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_800AED94; } }  /* 0x800AEBB4 */
    R[2] = lb_(R[18] + 786);  /* 0x800AEBBC */
    R[2] = R[2] & 0x4;  /* 0x800AEBC4 */
    { uint32_t _c = (R[2] == R[0]); R[22] = R[0] + 8192; if (_c) { goto L_800AEBD4; } }  /* 0x800AEBC8 */
    R[22] = R[0] + 10240;  /* 0x800AEBD0 */
L_800AEBD4:;
    R[2] = lb_(R[18] + 97);  /* 0x800AEBD4 */
    { uint32_t _c = (R[2] == R[0]); R[17] = R[0] + R[0]; if (_c) { goto L_800AED94; } }  /* 0x800AEBDC */
    R[2] = 0x8011u << 16;  /* 0x800AEBE4 */
    R[23] = R[2] + 29992;  /* 0x800AEBE8 */
    R[16] = R[20] + R[0];  /* 0x800AEBEC */
L_800AEBF0:;
    R[8] = lw_(R[29] + 72);  /* 0x800AEBF0 */
    sw_(R[16] + 8, R[8]);  /* 0x800AEBF8 */
    R[9] = lw_(R[29] + 76);  /* 0x800AEBFC */
    sw_(R[16] + 12, R[9]);  /* 0x800AEC04 */
    R[10] = lw_(R[29] + 80);  /* 0x800AEC08 */
    sw_(R[16] + 16, R[10]);  /* 0x800AEC10 */
    R[2] = lw_(R[19]);  /* 0x800AEC14 */
    sw_(R[16] + 20, R[2]);  /* 0x800AEC1C */
    R[2] = lw_(R[19] + 4);  /* 0x800AEC20 */
    sw_(R[16] + 24, R[2]);  /* 0x800AEC28 */
    R[2] = lw_(R[19] + 8);  /* 0x800AEC2C */
    sw_(R[16] + 28, R[2]);  /* 0x800AEC34 */
    R[2] = lh_(R[19]);  /* 0x800AEC38 */
    sh_(R[16] + 52, R[2]);  /* 0x800AEC40 */
    R[2] = lh_(R[19] + 4);  /* 0x800AEC44 */
    R[2] = R[0] - R[2];  /* 0x800AEC4C */
    sh_(R[16] + 54, R[2]);  /* 0x800AEC50 */
    R[2] = lh_(R[19] + 8);  /* 0x800AEC54 */
    { uint32_t _c = (R[30] == R[0]); sh_(R[16] + 56, R[2]); if (_c) { goto L_800AED04; } }  /* 0x800AEC58 */
    { uint32_t _c = (R[17] != R[0]); if (_c) { goto L_800AED04; } }  /* 0x800AEC60 */
    R[2] = lw_(R[21]);  /* 0x800AEC68 */
    sw_(R[29] + 32, R[2]);  /* 0x800AEC70 */
    R[2] = lw_(R[21] + 4);  /* 0x800AEC74 */
    R[3] = lw_(R[18] + 588);  /* 0x800AEC78 */
    R[2] = R[2] + R[3];  /* 0x800AEC80 */
    sw_(R[29] + 36, R[2]);  /* 0x800AEC84 */
    R[2] = lw_(R[21] + 8);  /* 0x800AEC88 */
    sw_(R[29] + 40, R[2]);  /* 0x800AEC90 */
    R[2] = lw_(R[18] + 588);  /* 0x800AEC94 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800AECA8; } }  /* 0x800AEC9C */
    R[2] = R[2] + 4095;  /* 0x800AECA4 */
L_800AECA8:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800AECA8 */
    sw_(R[20] + 24, R[2]);  /* 0x800AECAC */
    R[2] = lw_(R[18] + 588);  /* 0x800AECB0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[4] = R[29] + 16; if (_c) { goto L_800AECC4; } }  /* 0x800AECB8 */
    R[2] = R[2] + 4095;  /* 0x800AECC0 */
L_800AECC4:;
    R[5] = R[29] + 32;  /* 0x800AECC4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800AECC8 */
    R[2] = R[0] - R[2];  /* 0x800AECCC */
    R[6] = R[29] + 48;  /* 0x800AECD0 */
    sh_(R[20] + 54, R[2]);  /* 0x800AECD4 */
    R[2] = lw_(R[23] + 204);  /* 0x800AECD8 */
    R[7] = R[20] + 32;  /* 0x800AECDC */
    sw_(R[29] + 16, R[2]);  /* 0x800AECE0 */
    R[2] = lw_(R[23] + 208);  /* 0x800AECE4 */
    R[3] = lw_(R[23] + 212);  /* 0x800AECE8 */
    R[2] = R[0] - R[2];  /* 0x800AECEC */
    sw_(R[29] + 20, R[2]);  /* 0x800AECF0 */
    { R[31] = 0x800AECFCu; sw_(R[29] + 24, R[3]); psx_next = 0x800268E4u; return; }  /* 0x800AECF4 jal */
    { sh_(R[16], R[22]); goto L_800AED64; }  /* 0x800AECFC j */
L_800AED04:;
    R[11] = lw_(R[29] + 132);  /* 0x800AED04 */
    R[12] = lwl_(R[11] + 3, R[12]);  /* 0x800AED0C */
    R[12] = lwr_(R[11], R[12]);  /* 0x800AED10 */
    R[8] = lwl_(R[11] + 7, R[8]);  /* 0x800AED14 */
    R[8] = lwr_(R[11] + 4, R[8]);  /* 0x800AED18 */
    R[9] = lwl_(R[11] + 11, R[9]);  /* 0x800AED1C */
    R[9] = lwr_(R[11] + 8, R[9]);  /* 0x800AED20 */
    R[10] = lwl_(R[11] + 15, R[10]);  /* 0x800AED24 */
    R[10] = lwr_(R[11] + 12, R[10]);  /* 0x800AED28 */
    swl_(R[16] + 35, R[12]);  /* 0x800AED2C */
    swr_(R[16] + 32, R[12]);  /* 0x800AED30 */
    swl_(R[16] + 39, R[8]);  /* 0x800AED34 */
    swr_(R[16] + 36, R[8]);  /* 0x800AED38 */
    swl_(R[16] + 43, R[9]);  /* 0x800AED3C */
    swr_(R[16] + 40, R[9]);  /* 0x800AED40 */
    swl_(R[16] + 47, R[10]);  /* 0x800AED44 */
    swr_(R[16] + 44, R[10]);  /* 0x800AED48 */
    R[12] = lwl_(R[11] + 19, R[12]);  /* 0x800AED4C */
    R[12] = lwr_(R[11] + 16, R[12]);  /* 0x800AED50 */
    swl_(R[16] + 51, R[12]);  /* 0x800AED58 */
    swr_(R[16] + 48, R[12]);  /* 0x800AED5C */
    sh_(R[16], R[22]);  /* 0x800AED60 */
L_800AED64:;
    R[2] = (uint32_t)(int8_t)lb_(R[18] + 98);  /* 0x800AED64 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_800AED80; } }  /* 0x800AED6C */
    R[5] = R[20] + R[0];  /* 0x800AED74 */
    { R[31] = 0x800AED80u; R[6] = R[17] + R[0]; psx_next = 0x800AE5E4u; return; }  /* 0x800AED78 jal */
L_800AED80:;
    R[2] = lb_(R[18] + 97);  /* 0x800AED80 */
    R[17] = R[17] + 1;  /* 0x800AED84 */
    { uint32_t _c = (R[17] != R[2]); R[16] = R[16] + 80; if (_c) { psx_bb(); goto L_800AEBF0; } }  /* 0x800AED88 */
    R[2] = lb_(R[18] + 97);  /* 0x800AED90 */
L_800AED94:;
    R[31] = lw_(R[29] + 124);  /* 0x800AED94 */
    R[30] = lw_(R[29] + 120);  /* 0x800AED98 */
    R[23] = lw_(R[29] + 116);  /* 0x800AED9C */
    R[22] = lw_(R[29] + 112);  /* 0x800AEDA0 */
    R[21] = lw_(R[29] + 108);  /* 0x800AEDA4 */
    R[20] = lw_(R[29] + 104);  /* 0x800AEDA8 */
    R[19] = lw_(R[29] + 100);  /* 0x800AEDAC */
    R[18] = lw_(R[29] + 96);  /* 0x800AEDB0 */
    R[17] = lw_(R[29] + 92);  /* 0x800AEDB4 */
    R[16] = lw_(R[29] + 88);  /* 0x800AEDB8 */
    { R[29] = R[29] + 128; psx_next = R[31]; return; }  /* 0x800AEDBC jr ra */
}

void g0_800AEBF0(void) {
L_800AEBF0:;
    R[8] = lw_(R[29] + 72);  /* 0x800AEBF0 */
    sw_(R[16] + 8, R[8]);  /* 0x800AEBF8 */
    R[9] = lw_(R[29] + 76);  /* 0x800AEBFC */
    sw_(R[16] + 12, R[9]);  /* 0x800AEC04 */
    R[10] = lw_(R[29] + 80);  /* 0x800AEC08 */
    sw_(R[16] + 16, R[10]);  /* 0x800AEC10 */
    R[2] = lw_(R[19]);  /* 0x800AEC14 */
    sw_(R[16] + 20, R[2]);  /* 0x800AEC1C */
    R[2] = lw_(R[19] + 4);  /* 0x800AEC20 */
    sw_(R[16] + 24, R[2]);  /* 0x800AEC28 */
    R[2] = lw_(R[19] + 8);  /* 0x800AEC2C */
    sw_(R[16] + 28, R[2]);  /* 0x800AEC34 */
    R[2] = lh_(R[19]);  /* 0x800AEC38 */
    sh_(R[16] + 52, R[2]);  /* 0x800AEC40 */
    R[2] = lh_(R[19] + 4);  /* 0x800AEC44 */
    R[2] = R[0] - R[2];  /* 0x800AEC4C */
    sh_(R[16] + 54, R[2]);  /* 0x800AEC50 */
    R[2] = lh_(R[19] + 8);  /* 0x800AEC54 */
    { uint32_t _c = (R[30] == R[0]); sh_(R[16] + 56, R[2]); if (_c) { goto L_800AED04; } }  /* 0x800AEC58 */
    { uint32_t _c = (R[17] != R[0]); if (_c) { goto L_800AED04; } }  /* 0x800AEC60 */
    R[2] = lw_(R[21]);  /* 0x800AEC68 */
    sw_(R[29] + 32, R[2]);  /* 0x800AEC70 */
    R[2] = lw_(R[21] + 4);  /* 0x800AEC74 */
    R[3] = lw_(R[18] + 588);  /* 0x800AEC78 */
    R[2] = R[2] + R[3];  /* 0x800AEC80 */
    sw_(R[29] + 36, R[2]);  /* 0x800AEC84 */
    R[2] = lw_(R[21] + 8);  /* 0x800AEC88 */
    sw_(R[29] + 40, R[2]);  /* 0x800AEC90 */
    R[2] = lw_(R[18] + 588);  /* 0x800AEC94 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800AECA8; } }  /* 0x800AEC9C */
    R[2] = R[2] + 4095;  /* 0x800AECA4 */
L_800AECA8:;
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800AECA8 */
    sw_(R[20] + 24, R[2]);  /* 0x800AECAC */
    R[2] = lw_(R[18] + 588);  /* 0x800AECB0 */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[4] = R[29] + 16; if (_c) { goto L_800AECC4; } }  /* 0x800AECB8 */
    R[2] = R[2] + 4095;  /* 0x800AECC0 */
L_800AECC4:;
    R[5] = R[29] + 32;  /* 0x800AECC4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x800AECC8 */
    R[2] = R[0] - R[2];  /* 0x800AECCC */
    R[6] = R[29] + 48;  /* 0x800AECD0 */
    sh_(R[20] + 54, R[2]);  /* 0x800AECD4 */
    R[2] = lw_(R[23] + 204);  /* 0x800AECD8 */
    R[7] = R[20] + 32;  /* 0x800AECDC */
    sw_(R[29] + 16, R[2]);  /* 0x800AECE0 */
    R[2] = lw_(R[23] + 208);  /* 0x800AECE4 */
    R[3] = lw_(R[23] + 212);  /* 0x800AECE8 */
    R[2] = R[0] - R[2];  /* 0x800AECEC */
    sw_(R[29] + 20, R[2]);  /* 0x800AECF0 */
    { R[31] = 0x800AECFCu; sw_(R[29] + 24, R[3]); psx_next = 0x800268E4u; return; }  /* 0x800AECF4 jal */
    { sh_(R[16], R[22]); goto L_800AED64; }  /* 0x800AECFC j */
L_800AED04:;
    R[11] = lw_(R[29] + 132);  /* 0x800AED04 */
    R[12] = lwl_(R[11] + 3, R[12]);  /* 0x800AED0C */
    R[12] = lwr_(R[11], R[12]);  /* 0x800AED10 */
    R[8] = lwl_(R[11] + 7, R[8]);  /* 0x800AED14 */
    R[8] = lwr_(R[11] + 4, R[8]);  /* 0x800AED18 */
    R[9] = lwl_(R[11] + 11, R[9]);  /* 0x800AED1C */
    R[9] = lwr_(R[11] + 8, R[9]);  /* 0x800AED20 */
    R[10] = lwl_(R[11] + 15, R[10]);  /* 0x800AED24 */
    R[10] = lwr_(R[11] + 12, R[10]);  /* 0x800AED28 */
    swl_(R[16] + 35, R[12]);  /* 0x800AED2C */
    swr_(R[16] + 32, R[12]);  /* 0x800AED30 */
    swl_(R[16] + 39, R[8]);  /* 0x800AED34 */
    swr_(R[16] + 36, R[8]);  /* 0x800AED38 */
    swl_(R[16] + 43, R[9]);  /* 0x800AED3C */
    swr_(R[16] + 40, R[9]);  /* 0x800AED40 */
    swl_(R[16] + 47, R[10]);  /* 0x800AED44 */
    swr_(R[16] + 44, R[10]);  /* 0x800AED48 */
    R[12] = lwl_(R[11] + 19, R[12]);  /* 0x800AED4C */
    R[12] = lwr_(R[11] + 16, R[12]);  /* 0x800AED50 */
    swl_(R[16] + 51, R[12]);  /* 0x800AED58 */
    swr_(R[16] + 48, R[12]);  /* 0x800AED5C */
    sh_(R[16], R[22]);  /* 0x800AED60 */
L_800AED64:;
    R[2] = (uint32_t)(int8_t)lb_(R[18] + 98);  /* 0x800AED64 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_800AED80; } }  /* 0x800AED6C */
    R[5] = R[20] + R[0];  /* 0x800AED74 */
    { R[31] = 0x800AED80u; R[6] = R[17] + R[0]; psx_next = 0x800AE5E4u; return; }  /* 0x800AED78 jal */
L_800AED80:;
    R[2] = lb_(R[18] + 97);  /* 0x800AED80 */
    R[17] = R[17] + 1;  /* 0x800AED84 */
    { uint32_t _c = (R[17] != R[2]); R[16] = R[16] + 80; if (_c) { psx_bb(); goto L_800AEBF0; } }  /* 0x800AED88 */
    R[2] = lb_(R[18] + 97);  /* 0x800AED90 */
    R[31] = lw_(R[29] + 124);  /* 0x800AED94 */
    R[30] = lw_(R[29] + 120);  /* 0x800AED98 */
    R[23] = lw_(R[29] + 116);  /* 0x800AED9C */
    R[22] = lw_(R[29] + 112);  /* 0x800AEDA0 */
    R[21] = lw_(R[29] + 108);  /* 0x800AEDA4 */
    R[20] = lw_(R[29] + 104);  /* 0x800AEDA8 */
    R[19] = lw_(R[29] + 100);  /* 0x800AEDAC */
    R[18] = lw_(R[29] + 96);  /* 0x800AEDB0 */
    R[17] = lw_(R[29] + 92);  /* 0x800AEDB4 */
    R[16] = lw_(R[29] + 88);  /* 0x800AEDB8 */
    { R[29] = R[29] + 128; psx_next = R[31]; return; }  /* 0x800AEDBC jr ra */
}

void g0_800AECFC(void) {
    { sh_(R[16], R[22]); goto L_800AED64; }  /* 0x800AECFC j */
    R[11] = lw_(R[29] + 132);  /* 0x800AED04 */
    R[12] = lwl_(R[11] + 3, R[12]);  /* 0x800AED0C */
    R[12] = lwr_(R[11], R[12]);  /* 0x800AED10 */
    R[8] = lwl_(R[11] + 7, R[8]);  /* 0x800AED14 */
    R[8] = lwr_(R[11] + 4, R[8]);  /* 0x800AED18 */
    R[9] = lwl_(R[11] + 11, R[9]);  /* 0x800AED1C */
    R[9] = lwr_(R[11] + 8, R[9]);  /* 0x800AED20 */
    R[10] = lwl_(R[11] + 15, R[10]);  /* 0x800AED24 */
    R[10] = lwr_(R[11] + 12, R[10]);  /* 0x800AED28 */
    swl_(R[16] + 35, R[12]);  /* 0x800AED2C */
    swr_(R[16] + 32, R[12]);  /* 0x800AED30 */
    swl_(R[16] + 39, R[8]);  /* 0x800AED34 */
    swr_(R[16] + 36, R[8]);  /* 0x800AED38 */
    swl_(R[16] + 43, R[9]);  /* 0x800AED3C */
    swr_(R[16] + 40, R[9]);  /* 0x800AED40 */
    swl_(R[16] + 47, R[10]);  /* 0x800AED44 */
    swr_(R[16] + 44, R[10]);  /* 0x800AED48 */
    R[12] = lwl_(R[11] + 19, R[12]);  /* 0x800AED4C */
    R[12] = lwr_(R[11] + 16, R[12]);  /* 0x800AED50 */
    swl_(R[16] + 51, R[12]);  /* 0x800AED58 */
    swr_(R[16] + 48, R[12]);  /* 0x800AED5C */
    sh_(R[16], R[22]);  /* 0x800AED60 */
L_800AED64:;
    R[2] = (uint32_t)(int8_t)lb_(R[18] + 98);  /* 0x800AED64 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_800AED80; } }  /* 0x800AED6C */
    R[5] = R[20] + R[0];  /* 0x800AED74 */
    { R[31] = 0x800AED80u; R[6] = R[17] + R[0]; psx_next = 0x800AE5E4u; return; }  /* 0x800AED78 jal */
L_800AED80:;
    R[2] = lb_(R[18] + 97);  /* 0x800AED80 */
    R[17] = R[17] + 1;  /* 0x800AED84 */
    { uint32_t _c = (R[17] != R[2]); R[16] = R[16] + 80; if (_c) { psx_next = 0x800AEBF0u; return; } }  /* 0x800AED88 b extern */
    R[2] = lb_(R[18] + 97);  /* 0x800AED90 */
    R[31] = lw_(R[29] + 124);  /* 0x800AED94 */
    R[30] = lw_(R[29] + 120);  /* 0x800AED98 */
    R[23] = lw_(R[29] + 116);  /* 0x800AED9C */
    R[22] = lw_(R[29] + 112);  /* 0x800AEDA0 */
    R[21] = lw_(R[29] + 108);  /* 0x800AEDA4 */
    R[20] = lw_(R[29] + 104);  /* 0x800AEDA8 */
    R[19] = lw_(R[29] + 100);  /* 0x800AEDAC */
    R[18] = lw_(R[29] + 96);  /* 0x800AEDB0 */
    R[17] = lw_(R[29] + 92);  /* 0x800AEDB4 */
    R[16] = lw_(R[29] + 88);  /* 0x800AEDB8 */
    { R[29] = R[29] + 128; psx_next = R[31]; return; }  /* 0x800AEDBC jr ra */
}

void g0_800AED80(void) {
    R[2] = lb_(R[18] + 97);  /* 0x800AED80 */
    R[17] = R[17] + 1;  /* 0x800AED84 */
    { uint32_t _c = (R[17] != R[2]); R[16] = R[16] + 80; if (_c) { psx_next = 0x800AEBF0u; return; } }  /* 0x800AED88 b extern */
    R[2] = lb_(R[18] + 97);  /* 0x800AED90 */
    R[31] = lw_(R[29] + 124);  /* 0x800AED94 */
    R[30] = lw_(R[29] + 120);  /* 0x800AED98 */
    R[23] = lw_(R[29] + 116);  /* 0x800AED9C */
    R[22] = lw_(R[29] + 112);  /* 0x800AEDA0 */
    R[21] = lw_(R[29] + 108);  /* 0x800AEDA4 */
    R[20] = lw_(R[29] + 104);  /* 0x800AEDA8 */
    R[19] = lw_(R[29] + 100);  /* 0x800AEDAC */
    R[18] = lw_(R[29] + 96);  /* 0x800AEDB0 */
    R[17] = lw_(R[29] + 92);  /* 0x800AEDB4 */
    R[16] = lw_(R[29] + 88);  /* 0x800AEDB8 */
    { R[29] = R[29] + 128; psx_next = R[31]; return; }  /* 0x800AEDBC jr ra */
}

void g0_800AEDC4(void) {
    R[29] = R[29] - 48;  /* 0x800AEDC4 */
    R[2] = R[29] + 24;  /* 0x800AEDC8 */
    sw_(R[29] + 40, R[31]);  /* 0x800AEDCC */
    sw_(R[29] + 24, R[0]);  /* 0x800AEDD0 */
    sw_(R[29] + 28, R[0]);  /* 0x800AEDD4 */
    sw_(R[29] + 32, R[0]);  /* 0x800AEDD8 */
    { R[31] = 0x800AEDE4u; sw_(R[29] + 16, R[2]); psx_next = 0x800AEB24u; return; }  /* 0x800AEDDC jal */
    R[31] = lw_(R[29] + 40);  /* 0x800AEDE4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800AEDEC jr ra */
}

void g0_800AEDE4(void) {
    R[31] = lw_(R[29] + 40);  /* 0x800AEDE4 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800AEDEC jr ra */
}

void g0_800AEDF4(void) {
    R[29] = R[29] - 48;  /* 0x800AEDF4 */
    sw_(R[29] + 40, R[31]);  /* 0x800AEDF8 */
    sw_(R[29] + 24, R[0]);  /* 0x800AEDFC */
    R[2] = lw_(R[4] + 488);  /* 0x800AEE00 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_800AEE14; } }  /* 0x800AEE08 */
    R[2] = R[2] + 8191;  /* 0x800AEE10 */
L_800AEE14:;
    R[2] = (uint32_t)((int32_t)R[2] >> 13);  /* 0x800AEE14 */
    R[2] = R[0] - R[2];  /* 0x800AEE18 */
    sw_(R[29] + 28, R[2]);  /* 0x800AEE1C */
    R[2] = R[29] + 24;  /* 0x800AEE20 */
    sw_(R[29] + 32, R[0]);  /* 0x800AEE24 */
    { R[31] = 0x800AEE30u; sw_(R[29] + 16, R[2]); psx_next = 0x800AEB24u; return; }  /* 0x800AEE28 jal */
    R[31] = lw_(R[29] + 40);  /* 0x800AEE30 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800AEE38 jr ra */
}

void g0_800AEE30(void) {
    R[31] = lw_(R[29] + 40);  /* 0x800AEE30 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x800AEE38 jr ra */
}

void g0_800AEE40(void) {
    R[29] = R[29] - 40;  /* 0x800AEE40 */
    sw_(R[29] + 16, R[16]);  /* 0x800AEE44 */
    R[16] = R[4] + R[0];  /* 0x800AEE48 */
    sw_(R[29] + 20, R[17]);  /* 0x800AEE4C */
    R[17] = R[5] + R[0];  /* 0x800AEE50 */
    R[2] = 0x8011u << 16;  /* 0x800AEE54 */
    R[2] = R[2] + 30992;  /* 0x800AEE58 */
    R[4] = R[0] + 1;  /* 0x800AEE5C */
    sw_(R[29] + 32, R[31]);  /* 0x800AEE60 */
    sw_(R[29] + 28, R[19]);  /* 0x800AEE64 */
    sw_(R[29] + 24, R[18]);  /* 0x800AEE68 */
    R[5] = lh_(R[16] + 2);  /* 0x800AEE6C */
    R[19] = lw_(R[16] + 92);  /* 0x800AEE70 */
    R[3] = R[5] << 7;  /* 0x800AEE74 */
    { uint32_t _c = (R[17] == R[4]); R[18] = R[3] + R[2]; if (_c) { goto L_800AEFD8; } }  /* 0x800AEE78 */
    R[2] = ((int32_t)R[17] < 2);  /* 0x800AEE80 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AEE9C; } }  /* 0x800AEE84 */
    { uint32_t _c = (R[17] == R[0]); if (_c) { goto L_800AEEC8; } }  /* 0x800AEE8C */
    { goto L_800AF00C; }  /* 0x800AEE94 j */
L_800AEE9C:;
    R[3] = R[0] + 2;  /* 0x800AEE9C */
    { uint32_t _c = (R[17] == R[3]); R[2] = R[0] + 5; if (_c) { goto L_800AF004; } }  /* 0x800AEEA0 */
    { uint32_t _c = (R[17] != R[2]); R[2] = 0x800Bu << 16; if (_c) { goto L_800AF00C; } }  /* 0x800AEEA8 */
    R[2] = R[2] - 6404;  /* 0x800AEEB0 */
    sw_(R[16] + 232, R[2]);  /* 0x800AEEB4 */
    sb_(R[16] + 688, R[3]);  /* 0x800AEEB8 */
    sb_(R[16] + 689, R[3]);  /* 0x800AEEBC */
    { sb_(R[16] + 690, R[4]); goto L_800AEFC0; }  /* 0x800AEEC0 j */
L_800AEEC8:;
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 20);  /* 0x800AEEC8 */
    { uint32_t _c = (R[2] == R[4]); R[2] = R[0] + 414; if (_c) { goto L_800AF00C; } }  /* 0x800AEED0 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 10);  /* 0x800AEED8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_800AEF4C; } }  /* 0x800AEEE0 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 56);  /* 0x800AEEE8 */
    R[2] = R[3] << 1;  /* 0x800AEEF0 */
    R[2] = R[2] + R[3];  /* 0x800AEEF4 */
    R[2] = R[2] << 3;  /* 0x800AEEF8 */
    R[2] = R[2] + R[3];  /* 0x800AEEFC */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 58);  /* 0x800AEF00 */
    R[2] = R[2] << 2;  /* 0x800AEF04 */
    psx_div((int32_t)R[2], (int32_t)R[3]);  /* 0x800AEF08 */
    { uint32_t _c = (R[3] != R[0]); if (_c) { goto L_800AEF18; } }  /* 0x800AEF0C */
    psx_break(7168);  /* 0x800AEF14 */
L_800AEF18:;
    R[1] = R[0] - 1;  /* 0x800AEF18 */
    { uint32_t _c = (R[3] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_800AEF30; } }  /* 0x800AEF1C */
    { uint32_t _c = (R[2] != R[1]); if (_c) { goto L_800AEF30; } }  /* 0x800AEF24 */
    psx_break(6144);  /* 0x800AEF2C */
L_800AEF30:;
    R[2] = LO;  /* 0x800AEF30 */
    R[2] = ((int32_t)R[2] < 30);  /* 0x800AEF38 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AEF4C; } }  /* 0x800AEF3C */
    { R[31] = 0x800AEF4Cu; R[4] = R[0] + R[0]; psx_next = 0x8001D3A8u; return; }  /* 0x800AEF44 jal */
L_800AEF4C:;
    R[2] = lw_(R[16] + 584);  /* 0x800AEF4C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AF00C; } }  /* 0x800AEF54 */
    R[2] = lw_(R[18] + 4);  /* 0x800AEF5C */
    R[2] = lh_(R[2]);  /* 0x800AEF64 */
    R[2] = R[2] >> 14;  /* 0x800AEF6C */
    R[2] = R[2] & 0x1;  /* 0x800AEF70 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AF00C; } }  /* 0x800AEF74 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 56);  /* 0x800AEF7C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 414; if (_c) { goto L_800AEFBC; } }  /* 0x800AEF84 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 10);  /* 0x800AEF8C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800AEFB8; } }  /* 0x800AEF94 */
    R[4] = R[0] + 2146;  /* 0x800AEF9C */
    R[5] = lh_(R[16] + 2);  /* 0x800AEFA0 */
    R[2] = R[0] + 1;  /* 0x800AEFA4 */
    { R[31] = 0x800AEFB0u; sh_(R[16] + 20, R[2]); psx_next = 0x8002DAE8u; return; }  /* 0x800AEFA8 jal */
    { sw_(R[16] + 584, R[0]); goto L_800AEFC0; }  /* 0x800AEFB0 j */
L_800AEFB8:;
    sb_(R[16] + 790, R[2]);  /* 0x800AEFB8 */
L_800AEFBC:;
    sw_(R[16] + 584, R[0]);  /* 0x800AEFBC */
L_800AEFC0:;
    R[4] = lw_(R[18] + 4);  /* 0x800AEFC0 */
    R[5] = lw_(R[19] + 4);  /* 0x800AEFC4 */
    { R[31] = 0x800AEFD0u; R[6] = R[0] + 1; psx_next = 0x80024FDCu; return; }  /* 0x800AEFC8 jal */
    { goto L_800AF00C; }  /* 0x800AEFD0 j */
L_800AEFD8:;
    { R[31] = 0x800AEFE0u; R[4] = R[0] + 2142; psx_next = 0x8002DAE8u; return; }  /* 0x800AEFD8 jal */
    R[4] = lw_(R[18] + 4);  /* 0x800AEFE0 */
    R[5] = lw_(R[19] + 8);  /* 0x800AEFE4 */
    { R[31] = 0x800AEFF0u; R[6] = R[0] + R[0]; psx_next = 0x80024FDCu; return; }  /* 0x800AEFE8 jal */
    R[4] = R[16] + R[0];  /* 0x800AEFF0 */
    { R[31] = 0x800AEFFCu; sw_(R[16] + 584, R[17]); psx_next = 0x800A4B08u; return; }  /* 0x800AEFF4 jal */
    { sb_(R[16] + 787, R[0]); goto L_800AF00C; }  /* 0x800AEFFC j */
L_800AF004:;
    { R[31] = 0x800AF00Cu; R[4] = R[16] + R[0]; psx_next = 0x800B1570u; return; }  /* 0x800AF004 jal */
L_800AF00C:;
    R[31] = lw_(R[29] + 32);  /* 0x800AF00C */
    R[19] = lw_(R[29] + 28);  /* 0x800AF010 */
    R[18] = lw_(R[29] + 24);  /* 0x800AF014 */
    R[17] = lw_(R[29] + 20);  /* 0x800AF018 */
    R[16] = lw_(R[29] + 16);  /* 0x800AF01C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AF020 jr ra */
}

void g0_800AEF4C(void) {
    R[2] = lw_(R[16] + 584);  /* 0x800AEF4C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AF00C; } }  /* 0x800AEF54 */
    R[2] = lw_(R[18] + 4);  /* 0x800AEF5C */
    R[2] = lh_(R[2]);  /* 0x800AEF64 */
    R[2] = R[2] >> 14;  /* 0x800AEF6C */
    R[2] = R[2] & 0x1;  /* 0x800AEF70 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_800AF00C; } }  /* 0x800AEF74 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 56);  /* 0x800AEF7C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 414; if (_c) { goto L_800AEFBC; } }  /* 0x800AEF84 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 10);  /* 0x800AEF8C */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 1; if (_c) { goto L_800AEFB8; } }  /* 0x800AEF94 */
    R[4] = R[0] + 2146;  /* 0x800AEF9C */
    R[5] = lh_(R[16] + 2);  /* 0x800AEFA0 */
    R[2] = R[0] + 1;  /* 0x800AEFA4 */
    { R[31] = 0x800AEFB0u; sh_(R[16] + 20, R[2]); psx_next = 0x8002DAE8u; return; }  /* 0x800AEFA8 jal */
    { sw_(R[16] + 584, R[0]); goto L_800AEFC0; }  /* 0x800AEFB0 j */
L_800AEFB8:;
    sb_(R[16] + 790, R[2]);  /* 0x800AEFB8 */
L_800AEFBC:;
    sw_(R[16] + 584, R[0]);  /* 0x800AEFBC */
L_800AEFC0:;
    R[4] = lw_(R[18] + 4);  /* 0x800AEFC0 */
    R[5] = lw_(R[19] + 4);  /* 0x800AEFC4 */
    { R[31] = 0x800AEFD0u; R[6] = R[0] + 1; psx_next = 0x80024FDCu; return; }  /* 0x800AEFC8 jal */
    { goto L_800AF00C; }  /* 0x800AEFD0 j */
    { R[31] = 0x800AEFE0u; R[4] = R[0] + 2142; psx_next = 0x8002DAE8u; return; }  /* 0x800AEFD8 jal */
    R[4] = lw_(R[18] + 4);  /* 0x800AEFE0 */
    R[5] = lw_(R[19] + 8);  /* 0x800AEFE4 */
    { R[31] = 0x800AEFF0u; R[6] = R[0] + R[0]; psx_next = 0x80024FDCu; return; }  /* 0x800AEFE8 jal */
    R[4] = R[16] + R[0];  /* 0x800AEFF0 */
    { R[31] = 0x800AEFFCu; sw_(R[16] + 584, R[17]); psx_next = 0x800A4B08u; return; }  /* 0x800AEFF4 jal */
    { sb_(R[16] + 787, R[0]); goto L_800AF00C; }  /* 0x800AEFFC j */
    { R[31] = 0x800AF00Cu; R[4] = R[16] + R[0]; psx_next = 0x800B1570u; return; }  /* 0x800AF004 jal */
L_800AF00C:;
    R[31] = lw_(R[29] + 32);  /* 0x800AF00C */
    R[19] = lw_(R[29] + 28);  /* 0x800AF010 */
    R[18] = lw_(R[29] + 24);  /* 0x800AF014 */
    R[17] = lw_(R[29] + 20);  /* 0x800AF018 */
    R[16] = lw_(R[29] + 16);  /* 0x800AF01C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AF020 jr ra */
}

void g0_800AEFB0(void) {
    { sw_(R[16] + 584, R[0]); goto L_800AEFC0; }  /* 0x800AEFB0 j */
    sb_(R[16] + 790, R[2]);  /* 0x800AEFB8 */
    sw_(R[16] + 584, R[0]);  /* 0x800AEFBC */
L_800AEFC0:;
    R[4] = lw_(R[18] + 4);  /* 0x800AEFC0 */
    R[5] = lw_(R[19] + 4);  /* 0x800AEFC4 */
    { R[31] = 0x800AEFD0u; R[6] = R[0] + 1; psx_next = 0x80024FDCu; return; }  /* 0x800AEFC8 jal */
    { goto L_800AF00C; }  /* 0x800AEFD0 j */
    { R[31] = 0x800AEFE0u; R[4] = R[0] + 2142; psx_next = 0x8002DAE8u; return; }  /* 0x800AEFD8 jal */
    R[4] = lw_(R[18] + 4);  /* 0x800AEFE0 */
    R[5] = lw_(R[19] + 8);  /* 0x800AEFE4 */
    { R[31] = 0x800AEFF0u; R[6] = R[0] + R[0]; psx_next = 0x80024FDCu; return; }  /* 0x800AEFE8 jal */
    R[4] = R[16] + R[0];  /* 0x800AEFF0 */
    { R[31] = 0x800AEFFCu; sw_(R[16] + 584, R[17]); psx_next = 0x800A4B08u; return; }  /* 0x800AEFF4 jal */
    { sb_(R[16] + 787, R[0]); goto L_800AF00C; }  /* 0x800AEFFC j */
    { R[31] = 0x800AF00Cu; R[4] = R[16] + R[0]; psx_next = 0x800B1570u; return; }  /* 0x800AF004 jal */
L_800AF00C:;
    R[31] = lw_(R[29] + 32);  /* 0x800AF00C */
    R[19] = lw_(R[29] + 28);  /* 0x800AF010 */
    R[18] = lw_(R[29] + 24);  /* 0x800AF014 */
    R[17] = lw_(R[29] + 20);  /* 0x800AF018 */
    R[16] = lw_(R[29] + 16);  /* 0x800AF01C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AF020 jr ra */
}

void g0_800AEFD0(void) {
    { goto L_800AF00C; }  /* 0x800AEFD0 j */
    { R[31] = 0x800AEFE0u; R[4] = R[0] + 2142; psx_next = 0x8002DAE8u; return; }  /* 0x800AEFD8 jal */
    R[4] = lw_(R[18] + 4);  /* 0x800AEFE0 */
    R[5] = lw_(R[19] + 8);  /* 0x800AEFE4 */
    { R[31] = 0x800AEFF0u; R[6] = R[0] + R[0]; psx_next = 0x80024FDCu; return; }  /* 0x800AEFE8 jal */
    R[4] = R[16] + R[0];  /* 0x800AEFF0 */
    { R[31] = 0x800AEFFCu; sw_(R[16] + 584, R[17]); psx_next = 0x800A4B08u; return; }  /* 0x800AEFF4 jal */
    { sb_(R[16] + 787, R[0]); goto L_800AF00C; }  /* 0x800AEFFC j */
    { R[31] = 0x800AF00Cu; R[4] = R[16] + R[0]; psx_next = 0x800B1570u; return; }  /* 0x800AF004 jal */
L_800AF00C:;
    R[31] = lw_(R[29] + 32);  /* 0x800AF00C */
    R[19] = lw_(R[29] + 28);  /* 0x800AF010 */
    R[18] = lw_(R[29] + 24);  /* 0x800AF014 */
    R[17] = lw_(R[29] + 20);  /* 0x800AF018 */
    R[16] = lw_(R[29] + 16);  /* 0x800AF01C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AF020 jr ra */
}

void g0_800AEFE0(void) {
    R[4] = lw_(R[18] + 4);  /* 0x800AEFE0 */
    R[5] = lw_(R[19] + 8);  /* 0x800AEFE4 */
    { R[31] = 0x800AEFF0u; R[6] = R[0] + R[0]; psx_next = 0x80024FDCu; return; }  /* 0x800AEFE8 jal */
    R[4] = R[16] + R[0];  /* 0x800AEFF0 */
    { R[31] = 0x800AEFFCu; sw_(R[16] + 584, R[17]); psx_next = 0x800A4B08u; return; }  /* 0x800AEFF4 jal */
    { sb_(R[16] + 787, R[0]); goto L_800AF00C; }  /* 0x800AEFFC j */
    { R[31] = 0x800AF00Cu; R[4] = R[16] + R[0]; psx_next = 0x800B1570u; return; }  /* 0x800AF004 jal */
L_800AF00C:;
    R[31] = lw_(R[29] + 32);  /* 0x800AF00C */
    R[19] = lw_(R[29] + 28);  /* 0x800AF010 */
    R[18] = lw_(R[29] + 24);  /* 0x800AF014 */
    R[17] = lw_(R[29] + 20);  /* 0x800AF018 */
    R[16] = lw_(R[29] + 16);  /* 0x800AF01C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AF020 jr ra */
}

void g0_800AEFF0(void) {
    R[4] = R[16] + R[0];  /* 0x800AEFF0 */
    { R[31] = 0x800AEFFCu; sw_(R[16] + 584, R[17]); psx_next = 0x800A4B08u; return; }  /* 0x800AEFF4 jal */
    { sb_(R[16] + 787, R[0]); goto L_800AF00C; }  /* 0x800AEFFC j */
    { R[31] = 0x800AF00Cu; R[4] = R[16] + R[0]; psx_next = 0x800B1570u; return; }  /* 0x800AF004 jal */
L_800AF00C:;
    R[31] = lw_(R[29] + 32);  /* 0x800AF00C */
    R[19] = lw_(R[29] + 28);  /* 0x800AF010 */
    R[18] = lw_(R[29] + 24);  /* 0x800AF014 */
    R[17] = lw_(R[29] + 20);  /* 0x800AF018 */
    R[16] = lw_(R[29] + 16);  /* 0x800AF01C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AF020 jr ra */
}

void g0_800AEFFC(void) {
    { sb_(R[16] + 787, R[0]); goto L_800AF00C; }  /* 0x800AEFFC j */
    { R[31] = 0x800AF00Cu; R[4] = R[16] + R[0]; psx_next = 0x800B1570u; return; }  /* 0x800AF004 jal */
L_800AF00C:;
    R[31] = lw_(R[29] + 32);  /* 0x800AF00C */
    R[19] = lw_(R[29] + 28);  /* 0x800AF010 */
    R[18] = lw_(R[29] + 24);  /* 0x800AF014 */
    R[17] = lw_(R[29] + 20);  /* 0x800AF018 */
    R[16] = lw_(R[29] + 16);  /* 0x800AF01C */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x800AF020 jr ra */
}
