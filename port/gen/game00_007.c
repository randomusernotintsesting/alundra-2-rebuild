#include "game00_decls.h"

void g0_8008C0B4(void) {
    R[31] = lw_(R[29] + 32);  /* 0x8008C0B4 */
    R[19] = lw_(R[29] + 28);  /* 0x8008C0B8 */
    R[18] = lw_(R[29] + 24);  /* 0x8008C0BC */
    R[17] = lw_(R[29] + 20);  /* 0x8008C0C0 */
    R[16] = lw_(R[29] + 16);  /* 0x8008C0C4 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8008C0C8 jr ra */
}

void g0_8008C0D0(void) {
    R[29] = R[29] - 40;  /* 0x8008C0D0 */
    sw_(R[29] + 28, R[19]);  /* 0x8008C0D4 */
    R[19] = 0x1F80u << 16;  /* 0x8008C0D8 */
    R[12] = R[19] + R[0];  /* 0x8008C0DC */
    R[12] = R[12] | 0x14;  /* 0x8008C0E0 */
    sw_(R[29] + 20, R[17]);  /* 0x8008C0E4 */
    R[17] = R[0] + R[0];  /* 0x8008C0E8 */
    sw_(R[29] + 24, R[18]);  /* 0x8008C0EC */
    R[18] = R[17] + R[0];  /* 0x8008C0F0 */
    R[2] = 0x8012u << 16;  /* 0x8008C0F4 */
    R[4] = R[2] - 26864;  /* 0x8008C0F8 */
    R[5] = R[4] + 212;  /* 0x8008C0FC */
    R[7] = R[19] + R[0];  /* 0x8008C100 */
    psx_next = 0x8008C104u; return;  /* fallthrough */
}

void g0_8008C104(void) {
    R[7] = R[7] | 0x14;  /* 0x8008C104 */
    sw_(R[29] + 32, R[31]);  /* 0x8008C108 */
    sw_(R[29] + 16, R[16]);  /* 0x8008C10C */
    R[2] = (uint32_t)(int16_t)lh_(R[4]);  /* 0x8008C110 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 5; if (_c) { psx_next = 0x8008C27Cu; return; } }  /* 0x8008C118 b extern */
    R[3] = lb_(R[5] + 579);  /* 0x8008C120 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { psx_next = 0x8008C27Cu; return; } }  /* 0x8008C128 b extern */
    R[2] = (uint32_t)(int8_t)lb_(R[5] + 287);  /* 0x8008C130 */
    { uint32_t _c = ((int32_t)R[2] < 0); if (_c) { goto L_8008C150; } }  /* 0x8008C138 */
    sw_(R[7], R[4]);  /* 0x8008C140 */
    R[7] = R[7] + 4;  /* 0x8008C144 */
    { R[17] = R[17] + 1; goto L_8008C15C; }  /* 0x8008C148 j */
L_8008C150:;
    sb_(R[5] + 284, R[0]);  /* 0x8008C150 */
    sb_(R[5] + 286, R[0]);  /* 0x8008C154 */
    sb_(R[5] + 285, R[0]);  /* 0x8008C158 */
L_8008C15C:;
    R[3] = lb_(R[5] + 583);  /* 0x8008C15C */
    R[2] = R[0] + 2;  /* 0x8008C160 */
    sb_(R[5] + 571, R[0]);  /* 0x8008C164 */
    sb_(R[5] + 573, R[0]);  /* 0x8008C168 */
    { uint32_t _c = (R[3] == R[2]); sw_(R[5] + -44, R[0]); if (_c) { goto L_8008C1D8; } }  /* 0x8008C16C */
    R[2] = ((int32_t)R[3] < 3);  /* 0x8008C174 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C190; } }  /* 0x8008C178 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8008C1A4; } }  /* 0x8008C180 */
    { sh_(R[5] + -4, R[0]); psx_next = 0x8008C274u; return; }  /* 0x8008C188 j extern */
L_8008C190:;
    R[2] = ((int32_t)R[3] < 5);  /* 0x8008C190 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008C270u; return; } }  /* 0x8008C194 b extern */
    { R[18] = R[18] + 1; psx_next = 0x8008C280u; return; }  /* 0x8008C19C j extern */
L_8008C1A4:;
    R[2] = lw_(R[5] + 140);  /* 0x8008C1A4 */
    R[6] = lw_(R[2] + 24);  /* 0x8008C1AC */
    R[2] = lh_(R[6] + 24);  /* 0x8008C1B4 */
    sh_(R[5] + -4, R[2]);  /* 0x8008C1BC */
    R[2] = lh_(R[6] + 28);  /* 0x8008C1C0 */
    sh_(R[5], R[2]);  /* 0x8008C1C8 */
    R[2] = lh_(R[6] + 26);  /* 0x8008C1CC */
    { sh_(R[5] + -2, R[2]); psx_next = 0x8008C27Cu; return; }  /* 0x8008C1D0 j extern */
L_8008C1D8:;
    R[6] = lw_(R[5] + 140);  /* 0x8008C1D8 */
    R[2] = lw_(R[6] + 20);  /* 0x8008C1E0 */
    R[3] = 0x10u << 16;  /* 0x8008C1E4 */
    R[2] = R[2] & R[3];  /* 0x8008C1E8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008C208; } }  /* 0x8008C1EC */
    sb_(R[5] + 583, R[0]);  /* 0x8008C1F4 */
    sh_(R[5] + -4, R[0]);  /* 0x8008C1F8 */
    sh_(R[5], R[0]);  /* 0x8008C1FC */
    { sh_(R[5] + -2, R[0]); psx_next = 0x8008C27Cu; return; }  /* 0x8008C200 j extern */
L_8008C208:;
    R[6] = lw_(R[6] + 24);  /* 0x8008C208 */
    R[2] = lh_(R[6] + 24);  /* 0x8008C210 */
    R[2] = R[2] << 16;  /* 0x8008C218 */
    R[3] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008C21C */
    R[2] = R[2] >> 31;  /* 0x8008C220 */
    R[3] = R[3] + R[2];  /* 0x8008C224 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8008C228 */
    sh_(R[5] + -4, R[3]);  /* 0x8008C22C */
    R[2] = lh_(R[6] + 28);  /* 0x8008C230 */
    R[2] = R[2] << 16;  /* 0x8008C238 */
    R[3] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008C23C */
    R[2] = R[2] >> 31;  /* 0x8008C240 */
    R[3] = R[3] + R[2];  /* 0x8008C244 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8008C248 */
    sh_(R[5], R[3]);  /* 0x8008C24C */
    R[2] = (uint32_t)(int16_t)lh_(R[6] + 26);  /* 0x8008C250 */
    R[2] = R[2] + 4096;  /* 0x8008C258 */
    psx_next = 0x8008C25Cu; return;  /* fallthrough */
}

void g0_8008C110(void) {
    R[2] = (uint32_t)(int16_t)lh_(R[4]);  /* 0x8008C110 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 5; if (_c) { psx_next = 0x8008C27Cu; return; } }  /* 0x8008C118 b extern */
    R[3] = lb_(R[5] + 579);  /* 0x8008C120 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { psx_next = 0x8008C27Cu; return; } }  /* 0x8008C128 b extern */
    R[2] = (uint32_t)(int8_t)lb_(R[5] + 287);  /* 0x8008C130 */
    { uint32_t _c = ((int32_t)R[2] < 0); if (_c) { goto L_8008C150; } }  /* 0x8008C138 */
    sw_(R[7], R[4]);  /* 0x8008C140 */
    R[7] = R[7] + 4;  /* 0x8008C144 */
    { R[17] = R[17] + 1; goto L_8008C15C; }  /* 0x8008C148 j */
L_8008C150:;
    sb_(R[5] + 284, R[0]);  /* 0x8008C150 */
    sb_(R[5] + 286, R[0]);  /* 0x8008C154 */
    sb_(R[5] + 285, R[0]);  /* 0x8008C158 */
L_8008C15C:;
    R[3] = lb_(R[5] + 583);  /* 0x8008C15C */
    R[2] = R[0] + 2;  /* 0x8008C160 */
    sb_(R[5] + 571, R[0]);  /* 0x8008C164 */
    sb_(R[5] + 573, R[0]);  /* 0x8008C168 */
    { uint32_t _c = (R[3] == R[2]); sw_(R[5] + -44, R[0]); if (_c) { goto L_8008C1D8; } }  /* 0x8008C16C */
    R[2] = ((int32_t)R[3] < 3);  /* 0x8008C174 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C190; } }  /* 0x8008C178 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8008C1A4; } }  /* 0x8008C180 */
    { sh_(R[5] + -4, R[0]); psx_next = 0x8008C274u; return; }  /* 0x8008C188 j extern */
L_8008C190:;
    R[2] = ((int32_t)R[3] < 5);  /* 0x8008C190 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008C270u; return; } }  /* 0x8008C194 b extern */
    { R[18] = R[18] + 1; psx_next = 0x8008C280u; return; }  /* 0x8008C19C j extern */
L_8008C1A4:;
    R[2] = lw_(R[5] + 140);  /* 0x8008C1A4 */
    R[6] = lw_(R[2] + 24);  /* 0x8008C1AC */
    R[2] = lh_(R[6] + 24);  /* 0x8008C1B4 */
    sh_(R[5] + -4, R[2]);  /* 0x8008C1BC */
    R[2] = lh_(R[6] + 28);  /* 0x8008C1C0 */
    sh_(R[5], R[2]);  /* 0x8008C1C8 */
    R[2] = lh_(R[6] + 26);  /* 0x8008C1CC */
    { sh_(R[5] + -2, R[2]); psx_next = 0x8008C27Cu; return; }  /* 0x8008C1D0 j extern */
L_8008C1D8:;
    R[6] = lw_(R[5] + 140);  /* 0x8008C1D8 */
    R[2] = lw_(R[6] + 20);  /* 0x8008C1E0 */
    R[3] = 0x10u << 16;  /* 0x8008C1E4 */
    R[2] = R[2] & R[3];  /* 0x8008C1E8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008C208; } }  /* 0x8008C1EC */
    sb_(R[5] + 583, R[0]);  /* 0x8008C1F4 */
    sh_(R[5] + -4, R[0]);  /* 0x8008C1F8 */
    sh_(R[5], R[0]);  /* 0x8008C1FC */
    { sh_(R[5] + -2, R[0]); psx_next = 0x8008C27Cu; return; }  /* 0x8008C200 j extern */
L_8008C208:;
    R[6] = lw_(R[6] + 24);  /* 0x8008C208 */
    R[2] = lh_(R[6] + 24);  /* 0x8008C210 */
    R[2] = R[2] << 16;  /* 0x8008C218 */
    R[3] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008C21C */
    R[2] = R[2] >> 31;  /* 0x8008C220 */
    R[3] = R[3] + R[2];  /* 0x8008C224 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8008C228 */
    sh_(R[5] + -4, R[3]);  /* 0x8008C22C */
    R[2] = lh_(R[6] + 28);  /* 0x8008C230 */
    R[2] = R[2] << 16;  /* 0x8008C238 */
    R[3] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008C23C */
    R[2] = R[2] >> 31;  /* 0x8008C240 */
    R[3] = R[3] + R[2];  /* 0x8008C244 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8008C248 */
    sh_(R[5], R[3]);  /* 0x8008C24C */
    R[2] = (uint32_t)(int16_t)lh_(R[6] + 26);  /* 0x8008C250 */
    R[2] = R[2] + 4096;  /* 0x8008C258 */
    psx_next = 0x8008C25Cu; return;  /* fallthrough */
}

void g0_8008C25C(void) {
    R[3] = R[2] >> 31;  /* 0x8008C25C */
    R[2] = R[2] + R[3];  /* 0x8008C260 */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x8008C264 */
    { sh_(R[5] + -2, R[2]); goto L_8008C27C; }  /* 0x8008C268 j */
    sh_(R[5] + -4, R[0]);  /* 0x8008C270 */
    sh_(R[5] + -2, R[0]);  /* 0x8008C274 */
    sh_(R[5], R[0]);  /* 0x8008C278 */
L_8008C27C:;
    R[18] = R[18] + 1;  /* 0x8008C27C */
    R[5] = R[5] + 804;  /* 0x8008C280 */
    R[2] = R[0] + 60;  /* 0x8008C284 */
    { uint32_t _c = (R[18] != R[2]); R[4] = R[4] + 804; if (_c) { psx_next = 0x8008C110u; return; } }  /* 0x8008C288 b extern */
    { uint32_t _c = ((int32_t)R[17] <= 0); sw_(R[19] + 16, R[17]); if (_c) { goto L_8008C308; } }  /* 0x8008C290 */
    R[11] = R[17] - 1;  /* 0x8008C298 */
    { uint32_t _c = (R[11] == R[0]); R[10] = R[0] + R[0]; if (_c) { goto L_8008C308; } }  /* 0x8008C29C */
    R[9] = R[12] + R[0];  /* 0x8008C2A4 */
L_8008C2A8:;
    R[2] = lw_(R[9]);  /* 0x8008C2A8 */
    R[6] = R[10] + 1;  /* 0x8008C2AC */
    R[8] = lw_(R[2] + 28);  /* 0x8008C2B0 */
    { uint32_t _c = (R[6] == R[17]); R[2] = R[6] << 2; if (_c) { goto L_8008C2FC; } }  /* 0x8008C2B4 */
    R[7] = R[9] + R[0];  /* 0x8008C2BC */
    R[4] = R[2] + R[12];  /* 0x8008C2C0 */
L_8008C2C4:;
    R[5] = lw_(R[4]);  /* 0x8008C2C4 */
    R[3] = lw_(R[5] + 28);  /* 0x8008C2CC */
    R[2] = ((int32_t)R[8] < (int32_t)R[3]);  /* 0x8008C2D4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008C2F0; } }  /* 0x8008C2D8 */
    R[2] = lw_(R[7]);  /* 0x8008C2E0 */
    R[8] = R[3] + R[0];  /* 0x8008C2E4 */
    sw_(R[4], R[2]);  /* 0x8008C2E8 */
    sw_(R[7], R[5]);  /* 0x8008C2EC */
L_8008C2F0:;
    R[6] = R[6] + 1;  /* 0x8008C2F0 */
    { uint32_t _c = (R[6] != R[17]); R[4] = R[4] + 4; if (_c) { psx_bb(); goto L_8008C2C4; } }  /* 0x8008C2F4 */
L_8008C2FC:;
    R[10] = R[10] + 1;  /* 0x8008C2FC */
    { uint32_t _c = (R[10] != R[11]); R[9] = R[9] + 4; if (_c) { psx_bb(); goto L_8008C2A8; } }  /* 0x8008C300 */
L_8008C308:;
    { uint32_t _c = (R[17] == R[0]); R[18] = R[0] + R[0]; if (_c) { psx_next = 0x8008C340u; return; } }  /* 0x8008C308 b extern */
    R[16] = R[12] + R[0];  /* 0x8008C310 */
    R[4] = lw_(R[16]);  /* 0x8008C314 */
    R[2] = lb_(R[4] + 783);  /* 0x8008C31C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C334u; return; } }  /* 0x8008C324 b extern */
    psx_next = 0x8008C32Cu; return;  /* fallthrough */
}

void g0_8008C270(void) {
    sh_(R[5] + -4, R[0]);  /* 0x8008C270 */
    sh_(R[5] + -2, R[0]);  /* 0x8008C274 */
    sh_(R[5], R[0]);  /* 0x8008C278 */
    R[18] = R[18] + 1;  /* 0x8008C27C */
    R[5] = R[5] + 804;  /* 0x8008C280 */
    R[2] = R[0] + 60;  /* 0x8008C284 */
    { uint32_t _c = (R[18] != R[2]); R[4] = R[4] + 804; if (_c) { psx_next = 0x8008C110u; return; } }  /* 0x8008C288 b extern */
    { uint32_t _c = ((int32_t)R[17] <= 0); sw_(R[19] + 16, R[17]); if (_c) { goto L_8008C308; } }  /* 0x8008C290 */
    R[11] = R[17] - 1;  /* 0x8008C298 */
    { uint32_t _c = (R[11] == R[0]); R[10] = R[0] + R[0]; if (_c) { goto L_8008C308; } }  /* 0x8008C29C */
    R[9] = R[12] + R[0];  /* 0x8008C2A4 */
L_8008C2A8:;
    R[2] = lw_(R[9]);  /* 0x8008C2A8 */
    R[6] = R[10] + 1;  /* 0x8008C2AC */
    R[8] = lw_(R[2] + 28);  /* 0x8008C2B0 */
    { uint32_t _c = (R[6] == R[17]); R[2] = R[6] << 2; if (_c) { goto L_8008C2FC; } }  /* 0x8008C2B4 */
    R[7] = R[9] + R[0];  /* 0x8008C2BC */
    R[4] = R[2] + R[12];  /* 0x8008C2C0 */
L_8008C2C4:;
    R[5] = lw_(R[4]);  /* 0x8008C2C4 */
    R[3] = lw_(R[5] + 28);  /* 0x8008C2CC */
    R[2] = ((int32_t)R[8] < (int32_t)R[3]);  /* 0x8008C2D4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008C2F0; } }  /* 0x8008C2D8 */
    R[2] = lw_(R[7]);  /* 0x8008C2E0 */
    R[8] = R[3] + R[0];  /* 0x8008C2E4 */
    sw_(R[4], R[2]);  /* 0x8008C2E8 */
    sw_(R[7], R[5]);  /* 0x8008C2EC */
L_8008C2F0:;
    R[6] = R[6] + 1;  /* 0x8008C2F0 */
    { uint32_t _c = (R[6] != R[17]); R[4] = R[4] + 4; if (_c) { psx_bb(); goto L_8008C2C4; } }  /* 0x8008C2F4 */
L_8008C2FC:;
    R[10] = R[10] + 1;  /* 0x8008C2FC */
    { uint32_t _c = (R[10] != R[11]); R[9] = R[9] + 4; if (_c) { psx_bb(); goto L_8008C2A8; } }  /* 0x8008C300 */
L_8008C308:;
    { uint32_t _c = (R[17] == R[0]); R[18] = R[0] + R[0]; if (_c) { psx_next = 0x8008C340u; return; } }  /* 0x8008C308 b extern */
    R[16] = R[12] + R[0];  /* 0x8008C310 */
    R[4] = lw_(R[16]);  /* 0x8008C314 */
    R[2] = lb_(R[4] + 783);  /* 0x8008C31C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C334u; return; } }  /* 0x8008C324 b extern */
    psx_next = 0x8008C32Cu; return;  /* fallthrough */
}

void g0_8008C274(void) {
    sh_(R[5] + -2, R[0]);  /* 0x8008C274 */
    sh_(R[5], R[0]);  /* 0x8008C278 */
    R[18] = R[18] + 1;  /* 0x8008C27C */
    R[5] = R[5] + 804;  /* 0x8008C280 */
    R[2] = R[0] + 60;  /* 0x8008C284 */
    { uint32_t _c = (R[18] != R[2]); R[4] = R[4] + 804; if (_c) { psx_next = 0x8008C110u; return; } }  /* 0x8008C288 b extern */
    { uint32_t _c = ((int32_t)R[17] <= 0); sw_(R[19] + 16, R[17]); if (_c) { goto L_8008C308; } }  /* 0x8008C290 */
    R[11] = R[17] - 1;  /* 0x8008C298 */
    { uint32_t _c = (R[11] == R[0]); R[10] = R[0] + R[0]; if (_c) { goto L_8008C308; } }  /* 0x8008C29C */
    R[9] = R[12] + R[0];  /* 0x8008C2A4 */
L_8008C2A8:;
    R[2] = lw_(R[9]);  /* 0x8008C2A8 */
    R[6] = R[10] + 1;  /* 0x8008C2AC */
    R[8] = lw_(R[2] + 28);  /* 0x8008C2B0 */
    { uint32_t _c = (R[6] == R[17]); R[2] = R[6] << 2; if (_c) { goto L_8008C2FC; } }  /* 0x8008C2B4 */
    R[7] = R[9] + R[0];  /* 0x8008C2BC */
    R[4] = R[2] + R[12];  /* 0x8008C2C0 */
L_8008C2C4:;
    R[5] = lw_(R[4]);  /* 0x8008C2C4 */
    R[3] = lw_(R[5] + 28);  /* 0x8008C2CC */
    R[2] = ((int32_t)R[8] < (int32_t)R[3]);  /* 0x8008C2D4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008C2F0; } }  /* 0x8008C2D8 */
    R[2] = lw_(R[7]);  /* 0x8008C2E0 */
    R[8] = R[3] + R[0];  /* 0x8008C2E4 */
    sw_(R[4], R[2]);  /* 0x8008C2E8 */
    sw_(R[7], R[5]);  /* 0x8008C2EC */
L_8008C2F0:;
    R[6] = R[6] + 1;  /* 0x8008C2F0 */
    { uint32_t _c = (R[6] != R[17]); R[4] = R[4] + 4; if (_c) { psx_bb(); goto L_8008C2C4; } }  /* 0x8008C2F4 */
L_8008C2FC:;
    R[10] = R[10] + 1;  /* 0x8008C2FC */
    { uint32_t _c = (R[10] != R[11]); R[9] = R[9] + 4; if (_c) { psx_bb(); goto L_8008C2A8; } }  /* 0x8008C300 */
L_8008C308:;
    { uint32_t _c = (R[17] == R[0]); R[18] = R[0] + R[0]; if (_c) { psx_next = 0x8008C340u; return; } }  /* 0x8008C308 b extern */
    R[16] = R[12] + R[0];  /* 0x8008C310 */
    R[4] = lw_(R[16]);  /* 0x8008C314 */
    R[2] = lb_(R[4] + 783);  /* 0x8008C31C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C334u; return; } }  /* 0x8008C324 b extern */
    psx_next = 0x8008C32Cu; return;  /* fallthrough */
}

void g0_8008C27C(void) {
    R[18] = R[18] + 1;  /* 0x8008C27C */
    R[5] = R[5] + 804;  /* 0x8008C280 */
    R[2] = R[0] + 60;  /* 0x8008C284 */
    { uint32_t _c = (R[18] != R[2]); R[4] = R[4] + 804; if (_c) { psx_next = 0x8008C110u; return; } }  /* 0x8008C288 b extern */
    { uint32_t _c = ((int32_t)R[17] <= 0); sw_(R[19] + 16, R[17]); if (_c) { goto L_8008C308; } }  /* 0x8008C290 */
    R[11] = R[17] - 1;  /* 0x8008C298 */
    { uint32_t _c = (R[11] == R[0]); R[10] = R[0] + R[0]; if (_c) { goto L_8008C308; } }  /* 0x8008C29C */
    R[9] = R[12] + R[0];  /* 0x8008C2A4 */
L_8008C2A8:;
    R[2] = lw_(R[9]);  /* 0x8008C2A8 */
    R[6] = R[10] + 1;  /* 0x8008C2AC */
    R[8] = lw_(R[2] + 28);  /* 0x8008C2B0 */
    { uint32_t _c = (R[6] == R[17]); R[2] = R[6] << 2; if (_c) { goto L_8008C2FC; } }  /* 0x8008C2B4 */
    R[7] = R[9] + R[0];  /* 0x8008C2BC */
    R[4] = R[2] + R[12];  /* 0x8008C2C0 */
L_8008C2C4:;
    R[5] = lw_(R[4]);  /* 0x8008C2C4 */
    R[3] = lw_(R[5] + 28);  /* 0x8008C2CC */
    R[2] = ((int32_t)R[8] < (int32_t)R[3]);  /* 0x8008C2D4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008C2F0; } }  /* 0x8008C2D8 */
    R[2] = lw_(R[7]);  /* 0x8008C2E0 */
    R[8] = R[3] + R[0];  /* 0x8008C2E4 */
    sw_(R[4], R[2]);  /* 0x8008C2E8 */
    sw_(R[7], R[5]);  /* 0x8008C2EC */
L_8008C2F0:;
    R[6] = R[6] + 1;  /* 0x8008C2F0 */
    { uint32_t _c = (R[6] != R[17]); R[4] = R[4] + 4; if (_c) { psx_bb(); goto L_8008C2C4; } }  /* 0x8008C2F4 */
L_8008C2FC:;
    R[10] = R[10] + 1;  /* 0x8008C2FC */
    { uint32_t _c = (R[10] != R[11]); R[9] = R[9] + 4; if (_c) { psx_bb(); goto L_8008C2A8; } }  /* 0x8008C300 */
L_8008C308:;
    { uint32_t _c = (R[17] == R[0]); R[18] = R[0] + R[0]; if (_c) { psx_next = 0x8008C340u; return; } }  /* 0x8008C308 b extern */
    R[16] = R[12] + R[0];  /* 0x8008C310 */
    R[4] = lw_(R[16]);  /* 0x8008C314 */
    R[2] = lb_(R[4] + 783);  /* 0x8008C31C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C334u; return; } }  /* 0x8008C324 b extern */
    psx_next = 0x8008C32Cu; return;  /* fallthrough */
}

void g0_8008C280(void) {
    R[5] = R[5] + 804;  /* 0x8008C280 */
    R[2] = R[0] + 60;  /* 0x8008C284 */
    { uint32_t _c = (R[18] != R[2]); R[4] = R[4] + 804; if (_c) { psx_next = 0x8008C110u; return; } }  /* 0x8008C288 b extern */
    { uint32_t _c = ((int32_t)R[17] <= 0); sw_(R[19] + 16, R[17]); if (_c) { goto L_8008C308; } }  /* 0x8008C290 */
    R[11] = R[17] - 1;  /* 0x8008C298 */
    { uint32_t _c = (R[11] == R[0]); R[10] = R[0] + R[0]; if (_c) { goto L_8008C308; } }  /* 0x8008C29C */
    R[9] = R[12] + R[0];  /* 0x8008C2A4 */
L_8008C2A8:;
    R[2] = lw_(R[9]);  /* 0x8008C2A8 */
    R[6] = R[10] + 1;  /* 0x8008C2AC */
    R[8] = lw_(R[2] + 28);  /* 0x8008C2B0 */
    { uint32_t _c = (R[6] == R[17]); R[2] = R[6] << 2; if (_c) { goto L_8008C2FC; } }  /* 0x8008C2B4 */
    R[7] = R[9] + R[0];  /* 0x8008C2BC */
    R[4] = R[2] + R[12];  /* 0x8008C2C0 */
L_8008C2C4:;
    R[5] = lw_(R[4]);  /* 0x8008C2C4 */
    R[3] = lw_(R[5] + 28);  /* 0x8008C2CC */
    R[2] = ((int32_t)R[8] < (int32_t)R[3]);  /* 0x8008C2D4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008C2F0; } }  /* 0x8008C2D8 */
    R[2] = lw_(R[7]);  /* 0x8008C2E0 */
    R[8] = R[3] + R[0];  /* 0x8008C2E4 */
    sw_(R[4], R[2]);  /* 0x8008C2E8 */
    sw_(R[7], R[5]);  /* 0x8008C2EC */
L_8008C2F0:;
    R[6] = R[6] + 1;  /* 0x8008C2F0 */
    { uint32_t _c = (R[6] != R[17]); R[4] = R[4] + 4; if (_c) { psx_bb(); goto L_8008C2C4; } }  /* 0x8008C2F4 */
L_8008C2FC:;
    R[10] = R[10] + 1;  /* 0x8008C2FC */
    { uint32_t _c = (R[10] != R[11]); R[9] = R[9] + 4; if (_c) { psx_bb(); goto L_8008C2A8; } }  /* 0x8008C300 */
L_8008C308:;
    { uint32_t _c = (R[17] == R[0]); R[18] = R[0] + R[0]; if (_c) { psx_next = 0x8008C340u; return; } }  /* 0x8008C308 b extern */
    R[16] = R[12] + R[0];  /* 0x8008C310 */
    R[4] = lw_(R[16]);  /* 0x8008C314 */
    R[2] = lb_(R[4] + 783);  /* 0x8008C31C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C334u; return; } }  /* 0x8008C324 b extern */
    psx_next = 0x8008C32Cu; return;  /* fallthrough */
}

void g0_8008C314(void) {
    R[4] = lw_(R[16]);  /* 0x8008C314 */
    R[2] = lb_(R[4] + 783);  /* 0x8008C31C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C334u; return; } }  /* 0x8008C324 b extern */
    psx_next = 0x8008C32Cu; return;  /* fallthrough */
}

void g0_8008C328(void) {
    { R[31] = 0x8008C334u; R[5] = R[19] + R[0]; psx_next = 0x8008BDE0u; return; }  /* 0x8008C32C jal */
    R[18] = R[18] + 1;  /* 0x8008C334 */
    { uint32_t _c = (R[18] != R[17]); R[16] = R[16] + 4; if (_c) { psx_next = 0x8008C314u; return; } }  /* 0x8008C338 b extern */
    R[31] = lw_(R[29] + 32);  /* 0x8008C340 */
    R[19] = lw_(R[29] + 28);  /* 0x8008C344 */
    R[18] = lw_(R[29] + 24);  /* 0x8008C348 */
    R[17] = lw_(R[29] + 20);  /* 0x8008C34C */
    R[16] = lw_(R[29] + 16);  /* 0x8008C350 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8008C354 jr ra */
}

void g0_8008C32C(void) {
    { R[31] = 0x8008C334u; R[5] = R[19] + R[0]; psx_next = 0x8008BDE0u; return; }  /* 0x8008C32C jal */
    R[18] = R[18] + 1;  /* 0x8008C334 */
    { uint32_t _c = (R[18] != R[17]); R[16] = R[16] + 4; if (_c) { psx_next = 0x8008C314u; return; } }  /* 0x8008C338 b extern */
    R[31] = lw_(R[29] + 32);  /* 0x8008C340 */
    R[19] = lw_(R[29] + 28);  /* 0x8008C344 */
    R[18] = lw_(R[29] + 24);  /* 0x8008C348 */
    R[17] = lw_(R[29] + 20);  /* 0x8008C34C */
    R[16] = lw_(R[29] + 16);  /* 0x8008C350 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8008C354 jr ra */
}

void g0_8008C334(void) {
    R[18] = R[18] + 1;  /* 0x8008C334 */
    { uint32_t _c = (R[18] != R[17]); R[16] = R[16] + 4; if (_c) { psx_next = 0x8008C314u; return; } }  /* 0x8008C338 b extern */
    R[31] = lw_(R[29] + 32);  /* 0x8008C340 */
    R[19] = lw_(R[29] + 28);  /* 0x8008C344 */
    R[18] = lw_(R[29] + 24);  /* 0x8008C348 */
    R[17] = lw_(R[29] + 20);  /* 0x8008C34C */
    R[16] = lw_(R[29] + 16);  /* 0x8008C350 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8008C354 jr ra */
}

void g0_8008C340(void) {
    R[31] = lw_(R[29] + 32);  /* 0x8008C340 */
    R[19] = lw_(R[29] + 28);  /* 0x8008C344 */
    R[18] = lw_(R[29] + 24);  /* 0x8008C348 */
    R[17] = lw_(R[29] + 20);  /* 0x8008C34C */
    R[16] = lw_(R[29] + 16);  /* 0x8008C350 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8008C354 jr ra */
}

void g0_8008C35C(void) {
    R[29] = R[29] - 32;  /* 0x8008C35C */
    sw_(R[29] + 20, R[17]);  /* 0x8008C360 */
    R[17] = R[4] + R[0];  /* 0x8008C364 */
    sw_(R[29] + 24, R[31]);  /* 0x8008C368 */
    sw_(R[29] + 16, R[16]);  /* 0x8008C36C */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 10);  /* 0x8008C370 */
    R[2] = R[3] - 1;  /* 0x8008C378 */
    R[2] = (R[2] < (uint32_t)99u);  /* 0x8008C37C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 443; if (_c) { goto L_8008C398; } }  /* 0x8008C380 */
    { R[31] = 0x8008C390u; psx_next = 0x800E6830u; return; }  /* 0x8008C388 jal */
    { psx_next = 0x8008C554u; return; }  /* 0x8008C390 j extern */
L_8008C398:;
    { uint32_t _c = (R[3] == R[2]); R[16] = R[0] + R[0]; if (_c) { psx_next = 0x8008C534u; return; } }  /* 0x8008C398 b extern */
    R[2] = ((int32_t)R[3] < 444);  /* 0x8008C3A0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 427); if (_c) { goto L_8008C448; } }  /* 0x8008C3A4 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 423); if (_c) { goto L_8008C408; } }  /* 0x8008C3AC */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 406); if (_c) { psx_next = 0x8008C50Cu; return; } }  /* 0x8008C3B4 b extern */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 401); if (_c) { goto L_8008C3DC; } }  /* 0x8008C3BC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008C50Cu; return; } }  /* 0x8008C3C4 b extern */
    { uint32_t _c = (R[3] == R[0]); if (_c) { psx_next = 0x8008C504u; return; } }  /* 0x8008C3CC b extern */
    { psx_next = 0x8008C540u; return; }  /* 0x8008C3D4 j extern */
L_8008C3DC:;
    R[2] = R[0] + 408;  /* 0x8008C3DC */
    { uint32_t _c = (R[3] == R[2]); R[2] = ((int32_t)R[3] < (int32_t)R[2]); if (_c) { psx_next = 0x8008C514u; return; } }  /* 0x8008C3E0 b extern */
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[3] < 422); if (_c) { psx_next = 0x8008C540u; return; } }  /* 0x8008C3E8 b extern */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 418); if (_c) { psx_next = 0x8008C540u; return; } }  /* 0x8008C3F0 b extern */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C540u; return; } }  /* 0x8008C3F8 b extern */
    { R[16] = R[0] + 42; psx_next = 0x8008C540u; return; }  /* 0x8008C400 j extern */
L_8008C408:;
    R[2] = ((int32_t)R[3] < 440);  /* 0x8008C408 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 438); if (_c) { goto L_8008C434; } }  /* 0x8008C40C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 431; if (_c) { psx_next = 0x8008C514u; return; } }  /* 0x8008C414 b extern */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 436; if (_c) { psx_next = 0x8008C51Cu; return; } }  /* 0x8008C41C b extern */
    { uint32_t _c = (R[3] == R[2]); if (_c) { psx_next = 0x8008C50Cu; return; } }  /* 0x8008C424 b extern */
    { psx_next = 0x8008C540u; return; }  /* 0x8008C42C j extern */
L_8008C434:;
    R[2] = ((int32_t)R[3] < 442);  /* 0x8008C434 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[0] + 42; if (_c) { psx_next = 0x8008C540u; return; } }  /* 0x8008C438 b extern */
    { R[16] = R[0] + 43; psx_next = 0x8008C520u; return; }  /* 0x8008C440 j extern */
L_8008C448:;
    R[2] = ((int32_t)R[3] < 459);  /* 0x8008C448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 455); if (_c) { psx_next = 0x8008C498u; return; } }  /* 0x8008C44C b extern */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 447); if (_c) { psx_next = 0x8008C50Cu; return; } }  /* 0x8008C454 b extern */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 445); if (_c) { goto L_8008C474; } }  /* 0x8008C45C */
    { uint32_t _c = (R[2] == R[0]); R[16] = R[0] + 42; if (_c) { psx_next = 0x8008C53Cu; return; } }  /* 0x8008C464 b extern */
    { psx_next = 0x8008C540u; return; }  /* 0x8008C46C j extern */
L_8008C474:;
    R[2] = ((int32_t)R[3] < 450);  /* 0x8008C474 */
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[3] < 452); if (_c) { psx_next = 0x8008C540u; return; } }  /* 0x8008C478 b extern */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 453; if (_c) { psx_next = 0x8008C50Cu; return; } }  /* 0x8008C480 b extern */
    { uint32_t _c = (R[3] == R[2]); if (_c) { psx_next = 0x8008C514u; return; } }  /* 0x8008C488 b extern */
    { psx_next = 0x8008C540u; return; }  /* 0x8008C490 j extern */
}

void g0_8008C390(void) {
    { psx_next = 0x8008C554u; return; }  /* 0x8008C390 j extern */
    { uint32_t _c = (R[3] == R[2]); R[16] = R[0] + R[0]; if (_c) { psx_next = 0x8008C534u; return; } }  /* 0x8008C398 b extern */
    R[2] = ((int32_t)R[3] < 444);  /* 0x8008C3A0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 427); if (_c) { goto L_8008C448; } }  /* 0x8008C3A4 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 423); if (_c) { goto L_8008C408; } }  /* 0x8008C3AC */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 406); if (_c) { psx_next = 0x8008C50Cu; return; } }  /* 0x8008C3B4 b extern */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 401); if (_c) { goto L_8008C3DC; } }  /* 0x8008C3BC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008C50Cu; return; } }  /* 0x8008C3C4 b extern */
    { uint32_t _c = (R[3] == R[0]); if (_c) { psx_next = 0x8008C504u; return; } }  /* 0x8008C3CC b extern */
    { psx_next = 0x8008C540u; return; }  /* 0x8008C3D4 j extern */
L_8008C3DC:;
    R[2] = R[0] + 408;  /* 0x8008C3DC */
    { uint32_t _c = (R[3] == R[2]); R[2] = ((int32_t)R[3] < (int32_t)R[2]); if (_c) { psx_next = 0x8008C514u; return; } }  /* 0x8008C3E0 b extern */
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[3] < 422); if (_c) { psx_next = 0x8008C540u; return; } }  /* 0x8008C3E8 b extern */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 418); if (_c) { psx_next = 0x8008C540u; return; } }  /* 0x8008C3F0 b extern */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C540u; return; } }  /* 0x8008C3F8 b extern */
    { R[16] = R[0] + 42; psx_next = 0x8008C540u; return; }  /* 0x8008C400 j extern */
L_8008C408:;
    R[2] = ((int32_t)R[3] < 440);  /* 0x8008C408 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 438); if (_c) { goto L_8008C434; } }  /* 0x8008C40C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 431; if (_c) { psx_next = 0x8008C514u; return; } }  /* 0x8008C414 b extern */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 436; if (_c) { psx_next = 0x8008C51Cu; return; } }  /* 0x8008C41C b extern */
    { uint32_t _c = (R[3] == R[2]); if (_c) { psx_next = 0x8008C50Cu; return; } }  /* 0x8008C424 b extern */
    { psx_next = 0x8008C540u; return; }  /* 0x8008C42C j extern */
L_8008C434:;
    R[2] = ((int32_t)R[3] < 442);  /* 0x8008C434 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[0] + 42; if (_c) { psx_next = 0x8008C540u; return; } }  /* 0x8008C438 b extern */
    { R[16] = R[0] + 43; psx_next = 0x8008C520u; return; }  /* 0x8008C440 j extern */
L_8008C448:;
    R[2] = ((int32_t)R[3] < 459);  /* 0x8008C448 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 455); if (_c) { psx_next = 0x8008C498u; return; } }  /* 0x8008C44C b extern */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 447); if (_c) { psx_next = 0x8008C50Cu; return; } }  /* 0x8008C454 b extern */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 445); if (_c) { goto L_8008C474; } }  /* 0x8008C45C */
    { uint32_t _c = (R[2] == R[0]); R[16] = R[0] + 42; if (_c) { psx_next = 0x8008C53Cu; return; } }  /* 0x8008C464 b extern */
    { psx_next = 0x8008C540u; return; }  /* 0x8008C46C j extern */
L_8008C474:;
    R[2] = ((int32_t)R[3] < 450);  /* 0x8008C474 */
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[3] < 452); if (_c) { psx_next = 0x8008C540u; return; } }  /* 0x8008C478 b extern */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 453; if (_c) { psx_next = 0x8008C50Cu; return; } }  /* 0x8008C480 b extern */
    { uint32_t _c = (R[3] == R[2]); if (_c) { psx_next = 0x8008C514u; return; } }  /* 0x8008C488 b extern */
    { psx_next = 0x8008C540u; return; }  /* 0x8008C490 j extern */
}

void g0_8008C498(void) {
    R[2] = ((int32_t)R[3] < 474);  /* 0x8008C498 */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < 472); if (_c) { goto L_8008C4CC; } }  /* 0x8008C49C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 461; if (_c) { goto L_8008C50C; } }  /* 0x8008C4A4 */
    { uint32_t _c = (R[3] == R[2]); R[2] = ((int32_t)R[3] < (int32_t)R[2]); if (_c) { goto L_8008C50C; } }  /* 0x8008C4AC */
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[3] < 470); if (_c) { goto L_8008C540; } }  /* 0x8008C4B4 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008C540; } }  /* 0x8008C4BC */
    { R[16] = R[0] + 43; goto L_8008C540; }  /* 0x8008C4C4 j */
L_8008C4CC:;
    R[2] = R[0] + 479;  /* 0x8008C4CC */
    { uint32_t _c = (R[3] == R[2]); R[2] = ((int32_t)R[3] < 480); if (_c) { goto L_8008C50C; } }  /* 0x8008C4D0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 477; if (_c) { goto L_8008C4F0; } }  /* 0x8008C4D8 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8008C50C; } }  /* 0x8008C4E0 */
    { goto L_8008C540; }  /* 0x8008C4E8 j */
L_8008C4F0:;
    R[2] = R[0] + 494;  /* 0x8008C4F0 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8008C50C; } }  /* 0x8008C4F4 */
    { goto L_8008C540; }  /* 0x8008C4FC j */
    { R[16] = R[0] + 16; goto L_8008C540; }  /* 0x8008C504 j */
L_8008C50C:;
    { R[16] = R[0] + 42; goto L_8008C540; }  /* 0x8008C50C j */
    { R[16] = R[0] + 43; goto L_8008C540; }  /* 0x8008C514 j */
    R[16] = R[0] + 43;  /* 0x8008C51C */
    R[5] = lh_(R[17] + 2);  /* 0x8008C520 */
    { R[31] = 0x8008C52Cu; R[4] = R[0] + 2422; psx_next = 0x8002DAE8u; return; }  /* 0x8008C524 jal */
    { goto L_8008C540; }  /* 0x8008C52C j */
    { R[16] = R[0] + 2432; goto L_8008C540; }  /* 0x8008C534 j */
    R[16] = R[0] + 2461;  /* 0x8008C53C */
L_8008C540:;
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8008C554; } }  /* 0x8008C540 */
    R[5] = lh_(R[17] + 2);  /* 0x8008C548 */
    { R[31] = 0x8008C554u; R[4] = R[16] + R[0]; psx_next = 0x8002DAE8u; return; }  /* 0x8008C54C jal */
L_8008C554:;
    R[31] = lw_(R[29] + 24);  /* 0x8008C554 */
    R[17] = lw_(R[29] + 20);  /* 0x8008C558 */
    R[16] = lw_(R[29] + 16);  /* 0x8008C55C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008C560 jr ra */
}

void g0_8008C504(void) {
    { R[16] = R[0] + 16; goto L_8008C540; }  /* 0x8008C504 j */
    { R[16] = R[0] + 42; goto L_8008C540; }  /* 0x8008C50C j */
    { R[16] = R[0] + 43; goto L_8008C540; }  /* 0x8008C514 j */
    R[16] = R[0] + 43;  /* 0x8008C51C */
    R[5] = lh_(R[17] + 2);  /* 0x8008C520 */
    { R[31] = 0x8008C52Cu; R[4] = R[0] + 2422; psx_next = 0x8002DAE8u; return; }  /* 0x8008C524 jal */
    { goto L_8008C540; }  /* 0x8008C52C j */
    { R[16] = R[0] + 2432; goto L_8008C540; }  /* 0x8008C534 j */
    R[16] = R[0] + 2461;  /* 0x8008C53C */
L_8008C540:;
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8008C554; } }  /* 0x8008C540 */
    R[5] = lh_(R[17] + 2);  /* 0x8008C548 */
    { R[31] = 0x8008C554u; R[4] = R[16] + R[0]; psx_next = 0x8002DAE8u; return; }  /* 0x8008C54C jal */
L_8008C554:;
    R[31] = lw_(R[29] + 24);  /* 0x8008C554 */
    R[17] = lw_(R[29] + 20);  /* 0x8008C558 */
    R[16] = lw_(R[29] + 16);  /* 0x8008C55C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008C560 jr ra */
}

void g0_8008C50C(void) {
    { R[16] = R[0] + 42; goto L_8008C540; }  /* 0x8008C50C j */
    { R[16] = R[0] + 43; goto L_8008C540; }  /* 0x8008C514 j */
    R[16] = R[0] + 43;  /* 0x8008C51C */
    R[5] = lh_(R[17] + 2);  /* 0x8008C520 */
    { R[31] = 0x8008C52Cu; R[4] = R[0] + 2422; psx_next = 0x8002DAE8u; return; }  /* 0x8008C524 jal */
    { goto L_8008C540; }  /* 0x8008C52C j */
    { R[16] = R[0] + 2432; goto L_8008C540; }  /* 0x8008C534 j */
    R[16] = R[0] + 2461;  /* 0x8008C53C */
L_8008C540:;
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8008C554; } }  /* 0x8008C540 */
    R[5] = lh_(R[17] + 2);  /* 0x8008C548 */
    { R[31] = 0x8008C554u; R[4] = R[16] + R[0]; psx_next = 0x8002DAE8u; return; }  /* 0x8008C54C jal */
L_8008C554:;
    R[31] = lw_(R[29] + 24);  /* 0x8008C554 */
    R[17] = lw_(R[29] + 20);  /* 0x8008C558 */
    R[16] = lw_(R[29] + 16);  /* 0x8008C55C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008C560 jr ra */
}

void g0_8008C514(void) {
    { R[16] = R[0] + 43; goto L_8008C540; }  /* 0x8008C514 j */
    R[16] = R[0] + 43;  /* 0x8008C51C */
    R[5] = lh_(R[17] + 2);  /* 0x8008C520 */
    { R[31] = 0x8008C52Cu; R[4] = R[0] + 2422; psx_next = 0x8002DAE8u; return; }  /* 0x8008C524 jal */
    { goto L_8008C540; }  /* 0x8008C52C j */
    { R[16] = R[0] + 2432; goto L_8008C540; }  /* 0x8008C534 j */
    R[16] = R[0] + 2461;  /* 0x8008C53C */
L_8008C540:;
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8008C554; } }  /* 0x8008C540 */
    R[5] = lh_(R[17] + 2);  /* 0x8008C548 */
    { R[31] = 0x8008C554u; R[4] = R[16] + R[0]; psx_next = 0x8002DAE8u; return; }  /* 0x8008C54C jal */
L_8008C554:;
    R[31] = lw_(R[29] + 24);  /* 0x8008C554 */
    R[17] = lw_(R[29] + 20);  /* 0x8008C558 */
    R[16] = lw_(R[29] + 16);  /* 0x8008C55C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008C560 jr ra */
}

void g0_8008C51C(void) {
    R[16] = R[0] + 43;  /* 0x8008C51C */
    R[5] = lh_(R[17] + 2);  /* 0x8008C520 */
    { R[31] = 0x8008C52Cu; R[4] = R[0] + 2422; psx_next = 0x8002DAE8u; return; }  /* 0x8008C524 jal */
    { goto L_8008C540; }  /* 0x8008C52C j */
    { R[16] = R[0] + 2432; goto L_8008C540; }  /* 0x8008C534 j */
    R[16] = R[0] + 2461;  /* 0x8008C53C */
L_8008C540:;
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8008C554; } }  /* 0x8008C540 */
    R[5] = lh_(R[17] + 2);  /* 0x8008C548 */
    { R[31] = 0x8008C554u; R[4] = R[16] + R[0]; psx_next = 0x8002DAE8u; return; }  /* 0x8008C54C jal */
L_8008C554:;
    R[31] = lw_(R[29] + 24);  /* 0x8008C554 */
    R[17] = lw_(R[29] + 20);  /* 0x8008C558 */
    R[16] = lw_(R[29] + 16);  /* 0x8008C55C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008C560 jr ra */
}

void g0_8008C520(void) {
    R[5] = lh_(R[17] + 2);  /* 0x8008C520 */
    { R[31] = 0x8008C52Cu; R[4] = R[0] + 2422; psx_next = 0x8002DAE8u; return; }  /* 0x8008C524 jal */
    { goto L_8008C540; }  /* 0x8008C52C j */
    { R[16] = R[0] + 2432; goto L_8008C540; }  /* 0x8008C534 j */
    R[16] = R[0] + 2461;  /* 0x8008C53C */
L_8008C540:;
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8008C554; } }  /* 0x8008C540 */
    R[5] = lh_(R[17] + 2);  /* 0x8008C548 */
    { R[31] = 0x8008C554u; R[4] = R[16] + R[0]; psx_next = 0x8002DAE8u; return; }  /* 0x8008C54C jal */
L_8008C554:;
    R[31] = lw_(R[29] + 24);  /* 0x8008C554 */
    R[17] = lw_(R[29] + 20);  /* 0x8008C558 */
    R[16] = lw_(R[29] + 16);  /* 0x8008C55C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008C560 jr ra */
}

void g0_8008C52C(void) {
    { goto L_8008C540; }  /* 0x8008C52C j */
    { R[16] = R[0] + 2432; goto L_8008C540; }  /* 0x8008C534 j */
    R[16] = R[0] + 2461;  /* 0x8008C53C */
L_8008C540:;
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8008C554; } }  /* 0x8008C540 */
    R[5] = lh_(R[17] + 2);  /* 0x8008C548 */
    { R[31] = 0x8008C554u; R[4] = R[16] + R[0]; psx_next = 0x8002DAE8u; return; }  /* 0x8008C54C jal */
L_8008C554:;
    R[31] = lw_(R[29] + 24);  /* 0x8008C554 */
    R[17] = lw_(R[29] + 20);  /* 0x8008C558 */
    R[16] = lw_(R[29] + 16);  /* 0x8008C55C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008C560 jr ra */
}

void g0_8008C534(void) {
    { R[16] = R[0] + 2432; goto L_8008C540; }  /* 0x8008C534 j */
    R[16] = R[0] + 2461;  /* 0x8008C53C */
L_8008C540:;
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8008C554; } }  /* 0x8008C540 */
    R[5] = lh_(R[17] + 2);  /* 0x8008C548 */
    { R[31] = 0x8008C554u; R[4] = R[16] + R[0]; psx_next = 0x8002DAE8u; return; }  /* 0x8008C54C jal */
L_8008C554:;
    R[31] = lw_(R[29] + 24);  /* 0x8008C554 */
    R[17] = lw_(R[29] + 20);  /* 0x8008C558 */
    R[16] = lw_(R[29] + 16);  /* 0x8008C55C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008C560 jr ra */
}

void g0_8008C53C(void) {
    R[16] = R[0] + 2461;  /* 0x8008C53C */
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8008C554; } }  /* 0x8008C540 */
    R[5] = lh_(R[17] + 2);  /* 0x8008C548 */
    { R[31] = 0x8008C554u; R[4] = R[16] + R[0]; psx_next = 0x8002DAE8u; return; }  /* 0x8008C54C jal */
L_8008C554:;
    R[31] = lw_(R[29] + 24);  /* 0x8008C554 */
    R[17] = lw_(R[29] + 20);  /* 0x8008C558 */
    R[16] = lw_(R[29] + 16);  /* 0x8008C55C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008C560 jr ra */
}

void g0_8008C540(void) {
    { uint32_t _c = (R[16] == R[0]); if (_c) { goto L_8008C554; } }  /* 0x8008C540 */
    R[5] = lh_(R[17] + 2);  /* 0x8008C548 */
    { R[31] = 0x8008C554u; R[4] = R[16] + R[0]; psx_next = 0x8002DAE8u; return; }  /* 0x8008C54C jal */
L_8008C554:;
    R[31] = lw_(R[29] + 24);  /* 0x8008C554 */
    R[17] = lw_(R[29] + 20);  /* 0x8008C558 */
    R[16] = lw_(R[29] + 16);  /* 0x8008C55C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008C560 jr ra */
}

void g0_8008C554(void) {
    R[31] = lw_(R[29] + 24);  /* 0x8008C554 */
    R[17] = lw_(R[29] + 20);  /* 0x8008C558 */
    R[16] = lw_(R[29] + 16);  /* 0x8008C55C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008C560 jr ra */
}

void g0_8008C568(void) {
    R[29] = R[29] - 64;  /* 0x8008C568 */
    sw_(R[29] + 44, R[21]);  /* 0x8008C56C */
    R[21] = 0x1F80u << 16;  /* 0x8008C570 */
    sw_(R[29] + 56, R[30]);  /* 0x8008C574 */
    R[30] = R[21] + R[0];  /* 0x8008C578 */
    R[30] = R[30] | 0x14;  /* 0x8008C57C */
    R[4] = R[0] + R[0];  /* 0x8008C580 */
    sw_(R[29] + 32, R[18]);  /* 0x8008C584 */
    R[18] = R[4] + R[0];  /* 0x8008C588 */
    sw_(R[29] + 28, R[17]);  /* 0x8008C58C */
    R[17] = R[4] + R[0];  /* 0x8008C590 */
    R[2] = 0x8012u << 16;  /* 0x8008C594 */
    sw_(R[29] + 24, R[16]);  /* 0x8008C598 */
    R[16] = R[2] - 26864;  /* 0x8008C59C */
    R[5] = R[0] + 60;  /* 0x8008C5A0 */
    R[3] = R[21] + R[0];  /* 0x8008C5A4 */
    R[3] = R[3] | 0x14;  /* 0x8008C5A8 */
    sw_(R[29] + 60, R[31]);  /* 0x8008C5AC */
    sw_(R[29] + 52, R[23]);  /* 0x8008C5B0 */
    sw_(R[29] + 48, R[22]);  /* 0x8008C5B4 */
    sw_(R[29] + 40, R[20]);  /* 0x8008C5B8 */
    sw_(R[29] + 36, R[19]);  /* 0x8008C5BC */
L_8008C5C0:;
    R[2] = (uint32_t)(int16_t)lh_(R[16]);  /* 0x8008C5C0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008C5F4; } }  /* 0x8008C5C8 */
    R[2] = (uint32_t)(int8_t)lb_(R[16] + 499);  /* 0x8008C5D0 */
    { uint32_t _c = ((int32_t)R[2] < 0); if (_c) { goto L_8008C5F0; } }  /* 0x8008C5D8 */
    sw_(R[3], R[16]);  /* 0x8008C5E0 */
    R[3] = R[3] + 4;  /* 0x8008C5E4 */
    { R[18] = R[18] + 1; goto L_8008C5F4; }  /* 0x8008C5E8 j */
L_8008C5F0:;
    R[4] = R[16] + R[0];  /* 0x8008C5F0 */
L_8008C5F4:;
    R[17] = R[17] + 1;  /* 0x8008C5F4 */
    { uint32_t _c = (R[17] != R[5]); R[16] = R[16] + 804; if (_c) { psx_bb(); goto L_8008C5C0; } }  /* 0x8008C5F8 */
    psx_next = 0x8008C600u; return;  /* fallthrough */
}

void g0_8008C600(void) {
    R[2] = 0x8012u << 16;  /* 0x8008C600 */
    R[16] = R[2] - 26864;  /* 0x8008C604 */
    R[2] = 0x8012u << 16;  /* 0x8008C608 */
    R[2] = R[2] + 30872;  /* 0x8008C60C */
    sw_(R[21] + 16, R[18]);  /* 0x8008C610 */
    R[19] = lw_(R[2] + 92);  /* 0x8008C614 */
    R[23] = lw_(R[2] + 96);  /* 0x8008C618 */
    { uint32_t _c = (R[4] == R[0]); if (_c) { goto L_8008C62C; } }  /* 0x8008C61C */
    { R[31] = 0x8008C62Cu; R[5] = R[21] + R[0]; psx_next = 0x8008CBDCu; return; }  /* 0x8008C624 jal */
L_8008C62C:;
    { uint32_t _c = (R[18] == R[0]); R[17] = R[0] + R[0]; if (_c) { psx_next = 0x8008C9B8u; return; } }  /* 0x8008C62C b extern */
    R[20] = R[16] + R[0];  /* 0x8008C634 */
    R[2] = 0x8013u << 16;  /* 0x8008C638 */
    R[22] = R[2] - 29656;  /* 0x8008C63C */
    R[2] = R[17] << 2;  /* 0x8008C640 */
    R[2] = R[2] + R[30];  /* 0x8008C644 */
    R[16] = lw_(R[2]);  /* 0x8008C648 */
    R[5] = R[21] + R[0];  /* 0x8008C64C */
    { R[31] = 0x8008C658u; R[4] = R[16] + R[0]; psx_next = 0x8008C9E8u; return; }  /* 0x8008C650 jal */
    R[4] = R[16] + R[0];  /* 0x8008C658 */
    { R[31] = 0x8008C664u; R[5] = R[21] + R[0]; psx_next = 0x8008CBDCu; return; }  /* 0x8008C65C jal */
    R[5] = lb_(R[16] + 784);  /* 0x8008C664 */
    R[2] = lb_(R[16] + 497);  /* 0x8008C668 */
    R[6] = lw_(R[16] + 352);  /* 0x8008C66C */
    { uint32_t _c = (R[2] == R[0]); sb_(R[16] + 784, R[0]); if (_c) { goto L_8008C680; } }  /* 0x8008C670 */
    R[2] = R[0] + 2;  /* 0x8008C678 */
    sb_(R[16] + 784, R[2]);  /* 0x8008C67C */
L_8008C680:;
    { uint32_t _c = (R[16] != R[20]); if (_c) { goto L_8008C6A0; } }  /* 0x8008C680 */
    R[2] = lw_(R[22] + 100);  /* 0x8008C688 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008C6A0; } }  /* 0x8008C690 */
    { sw_(R[16] + 140, R[0]); psx_next = 0x8008C81Cu; return; }  /* 0x8008C698 j extern */
L_8008C6A0:;
    R[2] = lw_(R[16] + 352);  /* 0x8008C6A0 */
    R[2] = lb_(R[2] + 3);  /* 0x8008C6A8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008C6CC; } }  /* 0x8008C6B0 */
    R[2] = lb_(R[16] + 784);  /* 0x8008C6B8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C6CC; } }  /* 0x8008C6C0 */
    sb_(R[16] + 784, R[2]);  /* 0x8008C6C8 */
L_8008C6CC:;
    R[2] = lb_(R[16] + 357);  /* 0x8008C6CC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C70C; } }  /* 0x8008C6D4 */
    R[2] = lb_(R[16] + 385);  /* 0x8008C6DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C70C; } }  /* 0x8008C6E4 */
    R[2] = lb_(R[16] + 413);  /* 0x8008C6EC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C70C; } }  /* 0x8008C6F4 */
    R[2] = lb_(R[16] + 441);  /* 0x8008C6FC */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C714; } }  /* 0x8008C704 */
L_8008C70C:;
    sb_(R[16] + 784, R[2]);  /* 0x8008C70C */
    R[5] = R[0] + 1;  /* 0x8008C710 */
L_8008C714:;
    R[2] = lb_(R[16] + 358);  /* 0x8008C714 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C754; } }  /* 0x8008C71C */
    R[2] = lb_(R[16] + 386);  /* 0x8008C724 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C754; } }  /* 0x8008C72C */
    R[2] = lb_(R[16] + 414);  /* 0x8008C734 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C754; } }  /* 0x8008C73C */
    R[2] = lb_(R[16] + 442);  /* 0x8008C744 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C75C; } }  /* 0x8008C74C */
L_8008C754:;
    sb_(R[16] + 784, R[2]);  /* 0x8008C754 */
    R[5] = R[0] + 1;  /* 0x8008C758 */
L_8008C75C:;
    R[3] = lb_(R[16] + 789);  /* 0x8008C75C */
    R[4] = lw_(R[16] + 140);  /* 0x8008C760 */
    R[2] = R[3] & 0x1;  /* 0x8008C764 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C768 b extern */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C770 b extern */
    R[3] = lb_(R[16] + 791);  /* 0x8008C778 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C780 b extern */
    { uint32_t _c = (R[16] != R[20]); R[2] = R[0] + 1; if (_c) { goto L_8008C7A0; } }  /* 0x8008C788 */
    R[3] = (uint32_t)(int16_t)lh_(R[22] + 50);  /* 0x8008C790 */
    { uint32_t _c = (R[3] == R[2]); R[2] = 0x8012u << 16; if (_c) { psx_next = 0x8008C820u; return; } }  /* 0x8008C798 b extern */
L_8008C7A0:;
    R[2] = lb_(R[16] + 784);  /* 0x8008C7A0 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008C7C4; } }  /* 0x8008C7A8 */
    R[2] = lw_(R[16] + 16);  /* 0x8008C7B0 */
    R[2] = R[2] & 0x10;  /* 0x8008C7B8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C7D8u; return; } }  /* 0x8008C7BC b extern */
L_8008C7C4:;
    R[2] = lw_(R[16] + 16);  /* 0x8008C7C4 */
    R[2] = R[2] & 0x10;  /* 0x8008C7CC */
    psx_next = 0x8008C7D0u; return;  /* fallthrough */
}

void g0_8008C62C(void) {
    { uint32_t _c = (R[18] == R[0]); R[17] = R[0] + R[0]; if (_c) { psx_next = 0x8008C9B8u; return; } }  /* 0x8008C62C b extern */
    R[20] = R[16] + R[0];  /* 0x8008C634 */
    R[2] = 0x8013u << 16;  /* 0x8008C638 */
    R[22] = R[2] - 29656;  /* 0x8008C63C */
    R[2] = R[17] << 2;  /* 0x8008C640 */
    R[2] = R[2] + R[30];  /* 0x8008C644 */
    R[16] = lw_(R[2]);  /* 0x8008C648 */
    R[5] = R[21] + R[0];  /* 0x8008C64C */
    { R[31] = 0x8008C658u; R[4] = R[16] + R[0]; psx_next = 0x8008C9E8u; return; }  /* 0x8008C650 jal */
    R[4] = R[16] + R[0];  /* 0x8008C658 */
    { R[31] = 0x8008C664u; R[5] = R[21] + R[0]; psx_next = 0x8008CBDCu; return; }  /* 0x8008C65C jal */
    R[5] = lb_(R[16] + 784);  /* 0x8008C664 */
    R[2] = lb_(R[16] + 497);  /* 0x8008C668 */
    R[6] = lw_(R[16] + 352);  /* 0x8008C66C */
    { uint32_t _c = (R[2] == R[0]); sb_(R[16] + 784, R[0]); if (_c) { goto L_8008C680; } }  /* 0x8008C670 */
    R[2] = R[0] + 2;  /* 0x8008C678 */
    sb_(R[16] + 784, R[2]);  /* 0x8008C67C */
L_8008C680:;
    { uint32_t _c = (R[16] != R[20]); if (_c) { goto L_8008C6A0; } }  /* 0x8008C680 */
    R[2] = lw_(R[22] + 100);  /* 0x8008C688 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008C6A0; } }  /* 0x8008C690 */
    { sw_(R[16] + 140, R[0]); psx_next = 0x8008C81Cu; return; }  /* 0x8008C698 j extern */
L_8008C6A0:;
    R[2] = lw_(R[16] + 352);  /* 0x8008C6A0 */
    R[2] = lb_(R[2] + 3);  /* 0x8008C6A8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008C6CC; } }  /* 0x8008C6B0 */
    R[2] = lb_(R[16] + 784);  /* 0x8008C6B8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C6CC; } }  /* 0x8008C6C0 */
    sb_(R[16] + 784, R[2]);  /* 0x8008C6C8 */
L_8008C6CC:;
    R[2] = lb_(R[16] + 357);  /* 0x8008C6CC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C70C; } }  /* 0x8008C6D4 */
    R[2] = lb_(R[16] + 385);  /* 0x8008C6DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C70C; } }  /* 0x8008C6E4 */
    R[2] = lb_(R[16] + 413);  /* 0x8008C6EC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C70C; } }  /* 0x8008C6F4 */
    R[2] = lb_(R[16] + 441);  /* 0x8008C6FC */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C714; } }  /* 0x8008C704 */
L_8008C70C:;
    sb_(R[16] + 784, R[2]);  /* 0x8008C70C */
    R[5] = R[0] + 1;  /* 0x8008C710 */
L_8008C714:;
    R[2] = lb_(R[16] + 358);  /* 0x8008C714 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C754; } }  /* 0x8008C71C */
    R[2] = lb_(R[16] + 386);  /* 0x8008C724 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C754; } }  /* 0x8008C72C */
    R[2] = lb_(R[16] + 414);  /* 0x8008C734 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C754; } }  /* 0x8008C73C */
    R[2] = lb_(R[16] + 442);  /* 0x8008C744 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C75C; } }  /* 0x8008C74C */
L_8008C754:;
    sb_(R[16] + 784, R[2]);  /* 0x8008C754 */
    R[5] = R[0] + 1;  /* 0x8008C758 */
L_8008C75C:;
    R[3] = lb_(R[16] + 789);  /* 0x8008C75C */
    R[4] = lw_(R[16] + 140);  /* 0x8008C760 */
    R[2] = R[3] & 0x1;  /* 0x8008C764 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C768 b extern */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C770 b extern */
    R[3] = lb_(R[16] + 791);  /* 0x8008C778 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C780 b extern */
    { uint32_t _c = (R[16] != R[20]); R[2] = R[0] + 1; if (_c) { goto L_8008C7A0; } }  /* 0x8008C788 */
    R[3] = (uint32_t)(int16_t)lh_(R[22] + 50);  /* 0x8008C790 */
    { uint32_t _c = (R[3] == R[2]); R[2] = 0x8012u << 16; if (_c) { psx_next = 0x8008C820u; return; } }  /* 0x8008C798 b extern */
L_8008C7A0:;
    R[2] = lb_(R[16] + 784);  /* 0x8008C7A0 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008C7C4; } }  /* 0x8008C7A8 */
    R[2] = lw_(R[16] + 16);  /* 0x8008C7B0 */
    R[2] = R[2] & 0x10;  /* 0x8008C7B8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C7D8u; return; } }  /* 0x8008C7BC b extern */
L_8008C7C4:;
    R[2] = lw_(R[16] + 16);  /* 0x8008C7C4 */
    R[2] = R[2] & 0x10;  /* 0x8008C7CC */
    psx_next = 0x8008C7D0u; return;  /* fallthrough */
}

void g0_8008C644(void) {
    R[2] = R[2] + R[30];  /* 0x8008C644 */
    R[16] = lw_(R[2]);  /* 0x8008C648 */
    R[5] = R[21] + R[0];  /* 0x8008C64C */
    { R[31] = 0x8008C658u; R[4] = R[16] + R[0]; psx_next = 0x8008C9E8u; return; }  /* 0x8008C650 jal */
    R[4] = R[16] + R[0];  /* 0x8008C658 */
    { R[31] = 0x8008C664u; R[5] = R[21] + R[0]; psx_next = 0x8008CBDCu; return; }  /* 0x8008C65C jal */
    R[5] = lb_(R[16] + 784);  /* 0x8008C664 */
    R[2] = lb_(R[16] + 497);  /* 0x8008C668 */
    R[6] = lw_(R[16] + 352);  /* 0x8008C66C */
    { uint32_t _c = (R[2] == R[0]); sb_(R[16] + 784, R[0]); if (_c) { goto L_8008C680; } }  /* 0x8008C670 */
    R[2] = R[0] + 2;  /* 0x8008C678 */
    sb_(R[16] + 784, R[2]);  /* 0x8008C67C */
L_8008C680:;
    { uint32_t _c = (R[16] != R[20]); if (_c) { goto L_8008C6A0; } }  /* 0x8008C680 */
    R[2] = lw_(R[22] + 100);  /* 0x8008C688 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008C6A0; } }  /* 0x8008C690 */
    { sw_(R[16] + 140, R[0]); psx_next = 0x8008C81Cu; return; }  /* 0x8008C698 j extern */
L_8008C6A0:;
    R[2] = lw_(R[16] + 352);  /* 0x8008C6A0 */
    R[2] = lb_(R[2] + 3);  /* 0x8008C6A8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008C6CC; } }  /* 0x8008C6B0 */
    R[2] = lb_(R[16] + 784);  /* 0x8008C6B8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C6CC; } }  /* 0x8008C6C0 */
    sb_(R[16] + 784, R[2]);  /* 0x8008C6C8 */
L_8008C6CC:;
    R[2] = lb_(R[16] + 357);  /* 0x8008C6CC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C70C; } }  /* 0x8008C6D4 */
    R[2] = lb_(R[16] + 385);  /* 0x8008C6DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C70C; } }  /* 0x8008C6E4 */
    R[2] = lb_(R[16] + 413);  /* 0x8008C6EC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C70C; } }  /* 0x8008C6F4 */
    R[2] = lb_(R[16] + 441);  /* 0x8008C6FC */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C714; } }  /* 0x8008C704 */
L_8008C70C:;
    sb_(R[16] + 784, R[2]);  /* 0x8008C70C */
    R[5] = R[0] + 1;  /* 0x8008C710 */
L_8008C714:;
    R[2] = lb_(R[16] + 358);  /* 0x8008C714 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C754; } }  /* 0x8008C71C */
    R[2] = lb_(R[16] + 386);  /* 0x8008C724 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C754; } }  /* 0x8008C72C */
    R[2] = lb_(R[16] + 414);  /* 0x8008C734 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C754; } }  /* 0x8008C73C */
    R[2] = lb_(R[16] + 442);  /* 0x8008C744 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C75C; } }  /* 0x8008C74C */
L_8008C754:;
    sb_(R[16] + 784, R[2]);  /* 0x8008C754 */
    R[5] = R[0] + 1;  /* 0x8008C758 */
L_8008C75C:;
    R[3] = lb_(R[16] + 789);  /* 0x8008C75C */
    R[4] = lw_(R[16] + 140);  /* 0x8008C760 */
    R[2] = R[3] & 0x1;  /* 0x8008C764 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C768 b extern */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C770 b extern */
    R[3] = lb_(R[16] + 791);  /* 0x8008C778 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C780 b extern */
    { uint32_t _c = (R[16] != R[20]); R[2] = R[0] + 1; if (_c) { goto L_8008C7A0; } }  /* 0x8008C788 */
    R[3] = (uint32_t)(int16_t)lh_(R[22] + 50);  /* 0x8008C790 */
    { uint32_t _c = (R[3] == R[2]); R[2] = 0x8012u << 16; if (_c) { psx_next = 0x8008C820u; return; } }  /* 0x8008C798 b extern */
L_8008C7A0:;
    R[2] = lb_(R[16] + 784);  /* 0x8008C7A0 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008C7C4; } }  /* 0x8008C7A8 */
    R[2] = lw_(R[16] + 16);  /* 0x8008C7B0 */
    R[2] = R[2] & 0x10;  /* 0x8008C7B8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C7D8u; return; } }  /* 0x8008C7BC b extern */
L_8008C7C4:;
    R[2] = lw_(R[16] + 16);  /* 0x8008C7C4 */
    R[2] = R[2] & 0x10;  /* 0x8008C7CC */
    psx_next = 0x8008C7D0u; return;  /* fallthrough */
}

void g0_8008C658(void) {
    R[4] = R[16] + R[0];  /* 0x8008C658 */
    { R[31] = 0x8008C664u; R[5] = R[21] + R[0]; psx_next = 0x8008CBDCu; return; }  /* 0x8008C65C jal */
    R[5] = lb_(R[16] + 784);  /* 0x8008C664 */
    R[2] = lb_(R[16] + 497);  /* 0x8008C668 */
    R[6] = lw_(R[16] + 352);  /* 0x8008C66C */
    { uint32_t _c = (R[2] == R[0]); sb_(R[16] + 784, R[0]); if (_c) { goto L_8008C680; } }  /* 0x8008C670 */
    R[2] = R[0] + 2;  /* 0x8008C678 */
    sb_(R[16] + 784, R[2]);  /* 0x8008C67C */
L_8008C680:;
    { uint32_t _c = (R[16] != R[20]); if (_c) { goto L_8008C6A0; } }  /* 0x8008C680 */
    R[2] = lw_(R[22] + 100);  /* 0x8008C688 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008C6A0; } }  /* 0x8008C690 */
    { sw_(R[16] + 140, R[0]); psx_next = 0x8008C81Cu; return; }  /* 0x8008C698 j extern */
L_8008C6A0:;
    R[2] = lw_(R[16] + 352);  /* 0x8008C6A0 */
    R[2] = lb_(R[2] + 3);  /* 0x8008C6A8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008C6CC; } }  /* 0x8008C6B0 */
    R[2] = lb_(R[16] + 784);  /* 0x8008C6B8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C6CC; } }  /* 0x8008C6C0 */
    sb_(R[16] + 784, R[2]);  /* 0x8008C6C8 */
L_8008C6CC:;
    R[2] = lb_(R[16] + 357);  /* 0x8008C6CC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C70C; } }  /* 0x8008C6D4 */
    R[2] = lb_(R[16] + 385);  /* 0x8008C6DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C70C; } }  /* 0x8008C6E4 */
    R[2] = lb_(R[16] + 413);  /* 0x8008C6EC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C70C; } }  /* 0x8008C6F4 */
    R[2] = lb_(R[16] + 441);  /* 0x8008C6FC */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C714; } }  /* 0x8008C704 */
L_8008C70C:;
    sb_(R[16] + 784, R[2]);  /* 0x8008C70C */
    R[5] = R[0] + 1;  /* 0x8008C710 */
L_8008C714:;
    R[2] = lb_(R[16] + 358);  /* 0x8008C714 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C754; } }  /* 0x8008C71C */
    R[2] = lb_(R[16] + 386);  /* 0x8008C724 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C754; } }  /* 0x8008C72C */
    R[2] = lb_(R[16] + 414);  /* 0x8008C734 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C754; } }  /* 0x8008C73C */
    R[2] = lb_(R[16] + 442);  /* 0x8008C744 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C75C; } }  /* 0x8008C74C */
L_8008C754:;
    sb_(R[16] + 784, R[2]);  /* 0x8008C754 */
    R[5] = R[0] + 1;  /* 0x8008C758 */
L_8008C75C:;
    R[3] = lb_(R[16] + 789);  /* 0x8008C75C */
    R[4] = lw_(R[16] + 140);  /* 0x8008C760 */
    R[2] = R[3] & 0x1;  /* 0x8008C764 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C768 b extern */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C770 b extern */
    R[3] = lb_(R[16] + 791);  /* 0x8008C778 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C780 b extern */
    { uint32_t _c = (R[16] != R[20]); R[2] = R[0] + 1; if (_c) { goto L_8008C7A0; } }  /* 0x8008C788 */
    R[3] = (uint32_t)(int16_t)lh_(R[22] + 50);  /* 0x8008C790 */
    { uint32_t _c = (R[3] == R[2]); R[2] = 0x8012u << 16; if (_c) { psx_next = 0x8008C820u; return; } }  /* 0x8008C798 b extern */
L_8008C7A0:;
    R[2] = lb_(R[16] + 784);  /* 0x8008C7A0 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008C7C4; } }  /* 0x8008C7A8 */
    R[2] = lw_(R[16] + 16);  /* 0x8008C7B0 */
    R[2] = R[2] & 0x10;  /* 0x8008C7B8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C7D8u; return; } }  /* 0x8008C7BC b extern */
L_8008C7C4:;
    R[2] = lw_(R[16] + 16);  /* 0x8008C7C4 */
    R[2] = R[2] & 0x10;  /* 0x8008C7CC */
    psx_next = 0x8008C7D0u; return;  /* fallthrough */
}

void g0_8008C664(void) {
    R[5] = lb_(R[16] + 784);  /* 0x8008C664 */
    R[2] = lb_(R[16] + 497);  /* 0x8008C668 */
    R[6] = lw_(R[16] + 352);  /* 0x8008C66C */
    { uint32_t _c = (R[2] == R[0]); sb_(R[16] + 784, R[0]); if (_c) { goto L_8008C680; } }  /* 0x8008C670 */
    R[2] = R[0] + 2;  /* 0x8008C678 */
    sb_(R[16] + 784, R[2]);  /* 0x8008C67C */
L_8008C680:;
    { uint32_t _c = (R[16] != R[20]); if (_c) { goto L_8008C6A0; } }  /* 0x8008C680 */
    R[2] = lw_(R[22] + 100);  /* 0x8008C688 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008C6A0; } }  /* 0x8008C690 */
    { sw_(R[16] + 140, R[0]); psx_next = 0x8008C81Cu; return; }  /* 0x8008C698 j extern */
L_8008C6A0:;
    R[2] = lw_(R[16] + 352);  /* 0x8008C6A0 */
    R[2] = lb_(R[2] + 3);  /* 0x8008C6A8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008C6CC; } }  /* 0x8008C6B0 */
    R[2] = lb_(R[16] + 784);  /* 0x8008C6B8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C6CC; } }  /* 0x8008C6C0 */
    sb_(R[16] + 784, R[2]);  /* 0x8008C6C8 */
L_8008C6CC:;
    R[2] = lb_(R[16] + 357);  /* 0x8008C6CC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C70C; } }  /* 0x8008C6D4 */
    R[2] = lb_(R[16] + 385);  /* 0x8008C6DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C70C; } }  /* 0x8008C6E4 */
    R[2] = lb_(R[16] + 413);  /* 0x8008C6EC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C70C; } }  /* 0x8008C6F4 */
    R[2] = lb_(R[16] + 441);  /* 0x8008C6FC */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C714; } }  /* 0x8008C704 */
L_8008C70C:;
    sb_(R[16] + 784, R[2]);  /* 0x8008C70C */
    R[5] = R[0] + 1;  /* 0x8008C710 */
L_8008C714:;
    R[2] = lb_(R[16] + 358);  /* 0x8008C714 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C754; } }  /* 0x8008C71C */
    R[2] = lb_(R[16] + 386);  /* 0x8008C724 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C754; } }  /* 0x8008C72C */
    R[2] = lb_(R[16] + 414);  /* 0x8008C734 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C754; } }  /* 0x8008C73C */
    R[2] = lb_(R[16] + 442);  /* 0x8008C744 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008C75C; } }  /* 0x8008C74C */
L_8008C754:;
    sb_(R[16] + 784, R[2]);  /* 0x8008C754 */
    R[5] = R[0] + 1;  /* 0x8008C758 */
L_8008C75C:;
    R[3] = lb_(R[16] + 789);  /* 0x8008C75C */
    R[4] = lw_(R[16] + 140);  /* 0x8008C760 */
    R[2] = R[3] & 0x1;  /* 0x8008C764 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C768 b extern */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C770 b extern */
    R[3] = lb_(R[16] + 791);  /* 0x8008C778 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C780 b extern */
    { uint32_t _c = (R[16] != R[20]); R[2] = R[0] + 1; if (_c) { goto L_8008C7A0; } }  /* 0x8008C788 */
    R[3] = (uint32_t)(int16_t)lh_(R[22] + 50);  /* 0x8008C790 */
    { uint32_t _c = (R[3] == R[2]); R[2] = 0x8012u << 16; if (_c) { psx_next = 0x8008C820u; return; } }  /* 0x8008C798 b extern */
L_8008C7A0:;
    R[2] = lb_(R[16] + 784);  /* 0x8008C7A0 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008C7C4; } }  /* 0x8008C7A8 */
    R[2] = lw_(R[16] + 16);  /* 0x8008C7B0 */
    R[2] = R[2] & 0x10;  /* 0x8008C7B8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C7D8u; return; } }  /* 0x8008C7BC b extern */
L_8008C7C4:;
    R[2] = lw_(R[16] + 16);  /* 0x8008C7C4 */
    R[2] = R[2] & 0x10;  /* 0x8008C7CC */
    psx_next = 0x8008C7D0u; return;  /* fallthrough */
}

void g0_8008C7D0(void) {
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_8008C818; } }  /* 0x8008C7D0 */
    { uint32_t _c = ((int32_t)R[4] <= 0); if (_c) { goto L_8008C7F4; } }  /* 0x8008C7D8 */
    R[4] = R[4] - R[19];  /* 0x8008C7E0 */
    { uint32_t _c = ((int32_t)R[4] >= 0); if (_c) { goto L_8008C818; } }  /* 0x8008C7E4 */
    { R[4] = R[0] + R[0]; goto L_8008C818; }  /* 0x8008C7EC j */
L_8008C7F4:;
    R[2] = lb_(R[16] + 784);  /* 0x8008C7F4 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[0] - R[23]; if (_c) { goto L_8008C818; } }  /* 0x8008C7FC */
    R[4] = R[4] - R[19];  /* 0x8008C804 */
    R[2] = ((int32_t)R[3] < (int32_t)R[4]);  /* 0x8008C808 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008C818; } }  /* 0x8008C80C */
    R[4] = R[3] + R[0];  /* 0x8008C814 */
L_8008C818:;
    sw_(R[16] + 140, R[4]);  /* 0x8008C818 */
    R[2] = 0x8012u << 16;  /* 0x8008C81C */
    R[2] = lh_(R[2] + 31132);  /* 0x8008C820 */
    R[2] = R[2] & 0x1;  /* 0x8008C828 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x10u << 16; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C82C b extern */
    R[4] = lw_(R[16] + 16);  /* 0x8008C834 */
    R[2] = R[4] & R[2];  /* 0x8008C83C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C840 b extern */
    R[3] = lb_(R[16] + 789);  /* 0x8008C848 */
    R[2] = R[3] & 0x1;  /* 0x8008C850 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C854 b extern */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C85C b extern */
    R[3] = lb_(R[16] + 791);  /* 0x8008C864 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 10; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C86C b extern */
    R[3] = lb_(R[16] + 799);  /* 0x8008C874 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C87C b extern */
    { uint32_t _c = (R[5] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C884 b extern */
    R[2] = lb_(R[16] + 784);  /* 0x8008C88C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C894 b extern */
    R[2] = lw_(R[16] + 140);  /* 0x8008C89C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[4] & 0x10; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8A4 b extern */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8AC b extern */
    R[2] = lw_(R[6] + 24);  /* 0x8008C8B4 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 26);  /* 0x8008C8BC */
    R[2] = ((int32_t)R[2] < 712);  /* 0x8008C8C4 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8C8 b extern */
    { uint32_t _c = (R[16] != R[20]); if (_c) { goto L_8008C8FC; } }  /* 0x8008C8D0 */
    { R[31] = 0x8008C8E0u; R[4] = R[16] + R[0]; psx_next = 0x80091F88u; return; }  /* 0x8008C8D8 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8E0 b extern */
    R[4] = R[16] + R[0];  /* 0x8008C8E8 */
    { R[31] = 0x8008C8F4u; R[5] = R[0] + 2048; psx_next = 0x8008933Cu; return; }  /* 0x8008C8EC jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8F4 b extern */
L_8008C8FC:;
    R[2] = lw_(R[16] + 16);  /* 0x8008C8FC */
    R[3] = 0x1000u << 16;  /* 0x8008C900 */
    R[2] = R[2] & R[3];  /* 0x8008C904 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008C958u; return; } }  /* 0x8008C908 b extern */
    R[2] = lw_(R[16] + 484);  /* 0x8008C910 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008C924; } }  /* 0x8008C918 */
    R[2] = R[2] + 4095;  /* 0x8008C920 */
L_8008C924:;
    R[3] = lw_(R[16] + 492);  /* 0x8008C924 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008C928 */
    psx_next = 0x8008C92Cu; return;  /* fallthrough */
}

void g0_8008C7D8(void) {
    { uint32_t _c = ((int32_t)R[4] <= 0); if (_c) { goto L_8008C7F4; } }  /* 0x8008C7D8 */
    R[4] = R[4] - R[19];  /* 0x8008C7E0 */
    { uint32_t _c = ((int32_t)R[4] >= 0); if (_c) { goto L_8008C818; } }  /* 0x8008C7E4 */
    { R[4] = R[0] + R[0]; goto L_8008C818; }  /* 0x8008C7EC j */
L_8008C7F4:;
    R[2] = lb_(R[16] + 784);  /* 0x8008C7F4 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[0] - R[23]; if (_c) { goto L_8008C818; } }  /* 0x8008C7FC */
    R[4] = R[4] - R[19];  /* 0x8008C804 */
    R[2] = ((int32_t)R[3] < (int32_t)R[4]);  /* 0x8008C808 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008C818; } }  /* 0x8008C80C */
    R[4] = R[3] + R[0];  /* 0x8008C814 */
L_8008C818:;
    sw_(R[16] + 140, R[4]);  /* 0x8008C818 */
    R[2] = 0x8012u << 16;  /* 0x8008C81C */
    R[2] = lh_(R[2] + 31132);  /* 0x8008C820 */
    R[2] = R[2] & 0x1;  /* 0x8008C828 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x10u << 16; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C82C b extern */
    R[4] = lw_(R[16] + 16);  /* 0x8008C834 */
    R[2] = R[4] & R[2];  /* 0x8008C83C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C840 b extern */
    R[3] = lb_(R[16] + 789);  /* 0x8008C848 */
    R[2] = R[3] & 0x1;  /* 0x8008C850 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C854 b extern */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C85C b extern */
    R[3] = lb_(R[16] + 791);  /* 0x8008C864 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 10; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C86C b extern */
    R[3] = lb_(R[16] + 799);  /* 0x8008C874 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C87C b extern */
    { uint32_t _c = (R[5] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C884 b extern */
    R[2] = lb_(R[16] + 784);  /* 0x8008C88C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C894 b extern */
    R[2] = lw_(R[16] + 140);  /* 0x8008C89C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[4] & 0x10; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8A4 b extern */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8AC b extern */
    R[2] = lw_(R[6] + 24);  /* 0x8008C8B4 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 26);  /* 0x8008C8BC */
    R[2] = ((int32_t)R[2] < 712);  /* 0x8008C8C4 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8C8 b extern */
    { uint32_t _c = (R[16] != R[20]); if (_c) { goto L_8008C8FC; } }  /* 0x8008C8D0 */
    { R[31] = 0x8008C8E0u; R[4] = R[16] + R[0]; psx_next = 0x80091F88u; return; }  /* 0x8008C8D8 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8E0 b extern */
    R[4] = R[16] + R[0];  /* 0x8008C8E8 */
    { R[31] = 0x8008C8F4u; R[5] = R[0] + 2048; psx_next = 0x8008933Cu; return; }  /* 0x8008C8EC jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8F4 b extern */
L_8008C8FC:;
    R[2] = lw_(R[16] + 16);  /* 0x8008C8FC */
    R[3] = 0x1000u << 16;  /* 0x8008C900 */
    R[2] = R[2] & R[3];  /* 0x8008C904 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008C958u; return; } }  /* 0x8008C908 b extern */
    R[2] = lw_(R[16] + 484);  /* 0x8008C910 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008C924; } }  /* 0x8008C918 */
    R[2] = R[2] + 4095;  /* 0x8008C920 */
L_8008C924:;
    R[3] = lw_(R[16] + 492);  /* 0x8008C924 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008C928 */
    psx_next = 0x8008C92Cu; return;  /* fallthrough */
}

void g0_8008C81C(void) {
    R[2] = 0x8012u << 16;  /* 0x8008C81C */
    R[2] = lh_(R[2] + 31132);  /* 0x8008C820 */
    R[2] = R[2] & 0x1;  /* 0x8008C828 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x10u << 16; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C82C b extern */
    R[4] = lw_(R[16] + 16);  /* 0x8008C834 */
    R[2] = R[4] & R[2];  /* 0x8008C83C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C840 b extern */
    R[3] = lb_(R[16] + 789);  /* 0x8008C848 */
    R[2] = R[3] & 0x1;  /* 0x8008C850 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C854 b extern */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C85C b extern */
    R[3] = lb_(R[16] + 791);  /* 0x8008C864 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 10; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C86C b extern */
    R[3] = lb_(R[16] + 799);  /* 0x8008C874 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C87C b extern */
    { uint32_t _c = (R[5] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C884 b extern */
    R[2] = lb_(R[16] + 784);  /* 0x8008C88C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C894 b extern */
    R[2] = lw_(R[16] + 140);  /* 0x8008C89C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[4] & 0x10; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8A4 b extern */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8AC b extern */
    R[2] = lw_(R[6] + 24);  /* 0x8008C8B4 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 26);  /* 0x8008C8BC */
    R[2] = ((int32_t)R[2] < 712);  /* 0x8008C8C4 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8C8 b extern */
    { uint32_t _c = (R[16] != R[20]); if (_c) { goto L_8008C8FC; } }  /* 0x8008C8D0 */
    { R[31] = 0x8008C8E0u; R[4] = R[16] + R[0]; psx_next = 0x80091F88u; return; }  /* 0x8008C8D8 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8E0 b extern */
    R[4] = R[16] + R[0];  /* 0x8008C8E8 */
    { R[31] = 0x8008C8F4u; R[5] = R[0] + 2048; psx_next = 0x8008933Cu; return; }  /* 0x8008C8EC jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8F4 b extern */
L_8008C8FC:;
    R[2] = lw_(R[16] + 16);  /* 0x8008C8FC */
    R[3] = 0x1000u << 16;  /* 0x8008C900 */
    R[2] = R[2] & R[3];  /* 0x8008C904 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008C958u; return; } }  /* 0x8008C908 b extern */
    R[2] = lw_(R[16] + 484);  /* 0x8008C910 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008C924; } }  /* 0x8008C918 */
    R[2] = R[2] + 4095;  /* 0x8008C920 */
L_8008C924:;
    R[3] = lw_(R[16] + 492);  /* 0x8008C924 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008C928 */
    psx_next = 0x8008C92Cu; return;  /* fallthrough */
}

void g0_8008C820(void) {
    R[2] = lh_(R[2] + 31132);  /* 0x8008C820 */
    R[2] = R[2] & 0x1;  /* 0x8008C828 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x10u << 16; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C82C b extern */
    R[4] = lw_(R[16] + 16);  /* 0x8008C834 */
    R[2] = R[4] & R[2];  /* 0x8008C83C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C840 b extern */
    R[3] = lb_(R[16] + 789);  /* 0x8008C848 */
    R[2] = R[3] & 0x1;  /* 0x8008C850 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C854 b extern */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C85C b extern */
    R[3] = lb_(R[16] + 791);  /* 0x8008C864 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 10; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C86C b extern */
    R[3] = lb_(R[16] + 799);  /* 0x8008C874 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C87C b extern */
    { uint32_t _c = (R[5] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C884 b extern */
    R[2] = lb_(R[16] + 784);  /* 0x8008C88C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C894 b extern */
    R[2] = lw_(R[16] + 140);  /* 0x8008C89C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[4] & 0x10; if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8A4 b extern */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8AC b extern */
    R[2] = lw_(R[6] + 24);  /* 0x8008C8B4 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 26);  /* 0x8008C8BC */
    R[2] = ((int32_t)R[2] < 712);  /* 0x8008C8C4 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8C8 b extern */
    { uint32_t _c = (R[16] != R[20]); if (_c) { goto L_8008C8FC; } }  /* 0x8008C8D0 */
    { R[31] = 0x8008C8E0u; R[4] = R[16] + R[0]; psx_next = 0x80091F88u; return; }  /* 0x8008C8D8 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8E0 b extern */
    R[4] = R[16] + R[0];  /* 0x8008C8E8 */
    { R[31] = 0x8008C8F4u; R[5] = R[0] + 2048; psx_next = 0x8008933Cu; return; }  /* 0x8008C8EC jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8F4 b extern */
L_8008C8FC:;
    R[2] = lw_(R[16] + 16);  /* 0x8008C8FC */
    R[3] = 0x1000u << 16;  /* 0x8008C900 */
    R[2] = R[2] & R[3];  /* 0x8008C904 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008C958u; return; } }  /* 0x8008C908 b extern */
    R[2] = lw_(R[16] + 484);  /* 0x8008C910 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008C924; } }  /* 0x8008C918 */
    R[2] = R[2] + 4095;  /* 0x8008C920 */
L_8008C924:;
    R[3] = lw_(R[16] + 492);  /* 0x8008C924 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008C928 */
    psx_next = 0x8008C92Cu; return;  /* fallthrough */
}

void g0_8008C8E0(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8E0 b extern */
    R[4] = R[16] + R[0];  /* 0x8008C8E8 */
    { R[31] = 0x8008C8F4u; R[5] = R[0] + 2048; psx_next = 0x8008933Cu; return; }  /* 0x8008C8EC jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8F4 b extern */
    R[2] = lw_(R[16] + 16);  /* 0x8008C8FC */
    R[3] = 0x1000u << 16;  /* 0x8008C900 */
    R[2] = R[2] & R[3];  /* 0x8008C904 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008C958u; return; } }  /* 0x8008C908 b extern */
    R[2] = lw_(R[16] + 484);  /* 0x8008C910 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008C924; } }  /* 0x8008C918 */
    R[2] = R[2] + 4095;  /* 0x8008C920 */
L_8008C924:;
    R[3] = lw_(R[16] + 492);  /* 0x8008C924 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008C928 */
    psx_next = 0x8008C92Cu; return;  /* fallthrough */
}

void g0_8008C8F4(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008C9ACu; return; } }  /* 0x8008C8F4 b extern */
    R[2] = lw_(R[16] + 16);  /* 0x8008C8FC */
    R[3] = 0x1000u << 16;  /* 0x8008C900 */
    R[2] = R[2] & R[3];  /* 0x8008C904 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008C958u; return; } }  /* 0x8008C908 b extern */
    R[2] = lw_(R[16] + 484);  /* 0x8008C910 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008C924; } }  /* 0x8008C918 */
    R[2] = R[2] + 4095;  /* 0x8008C920 */
L_8008C924:;
    R[3] = lw_(R[16] + 492);  /* 0x8008C924 */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008C928 */
    psx_next = 0x8008C92Cu; return;  /* fallthrough */
}

void g0_8008C92C(void) {
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[2] << 16; if (_c) { goto L_8008C938; } }  /* 0x8008C92C */
    R[3] = R[3] + 4095;  /* 0x8008C934 */
L_8008C938:;
    R[2] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008C938 */
    R[2] = R[4] | R[2];  /* 0x8008C93C */
    sw_(R[29] + 16, R[2]);  /* 0x8008C940 */
    R[5] = lw_(R[16] + 24);  /* 0x8008C944 */
    R[6] = lw_(R[16] + 28);  /* 0x8008C948 */
    R[7] = lw_(R[16] + 32);  /* 0x8008C94C */
    { R[4] = R[0] + 32; psx_next = 0x8008C99Cu; return; }  /* 0x8008C950 j extern */
    R[2] = lw_(R[16] + 484);  /* 0x8008C958 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { psx_next = 0x8008C96Cu; return; } }  /* 0x8008C960 b extern */
    psx_next = 0x8008C968u; return;  /* fallthrough */
}

void g0_8008C958(void) {
    R[2] = lw_(R[16] + 484);  /* 0x8008C958 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { psx_next = 0x8008C96Cu; return; } }  /* 0x8008C960 b extern */
    psx_next = 0x8008C968u; return;  /* fallthrough */
}

void g0_8008C964(void) {
    R[2] = R[2] + 4095;  /* 0x8008C968 */
    R[3] = lw_(R[16] + 492);  /* 0x8008C96C */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008C970 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[2] << 16; if (_c) { goto L_8008C980; } }  /* 0x8008C974 */
    R[3] = R[3] + 4095;  /* 0x8008C97C */
L_8008C980:;
    R[2] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008C980 */
    R[2] = R[4] | R[2];  /* 0x8008C984 */
    sw_(R[29] + 16, R[2]);  /* 0x8008C988 */
    R[5] = lw_(R[16] + 24);  /* 0x8008C98C */
    R[6] = lw_(R[16] + 28);  /* 0x8008C990 */
    R[7] = lw_(R[16] + 32);  /* 0x8008C994 */
    R[4] = R[0] + 2;  /* 0x8008C998 */
    { R[31] = 0x8008C9A4u; psx_next = 0x800A7290u; return; }  /* 0x8008C99C jal */
    { R[31] = 0x8008C9ACu; R[4] = R[16] + R[0]; psx_next = 0x8008C35Cu; return; }  /* 0x8008C9A4 jal */
    R[17] = R[17] + 1;  /* 0x8008C9AC */
    { uint32_t _c = (R[17] != R[18]); R[2] = R[17] << 2; if (_c) { psx_next = 0x8008C644u; return; } }  /* 0x8008C9B0 b extern */
    R[31] = lw_(R[29] + 60);  /* 0x8008C9B8 */
    R[30] = lw_(R[29] + 56);  /* 0x8008C9BC */
    R[23] = lw_(R[29] + 52);  /* 0x8008C9C0 */
    R[22] = lw_(R[29] + 48);  /* 0x8008C9C4 */
    R[21] = lw_(R[29] + 44);  /* 0x8008C9C8 */
    R[20] = lw_(R[29] + 40);  /* 0x8008C9CC */
    R[19] = lw_(R[29] + 36);  /* 0x8008C9D0 */
    R[18] = lw_(R[29] + 32);  /* 0x8008C9D4 */
    R[17] = lw_(R[29] + 28);  /* 0x8008C9D8 */
    R[16] = lw_(R[29] + 24);  /* 0x8008C9DC */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008C9E0 jr ra */
}

void g0_8008C968(void) {
    R[2] = R[2] + 4095;  /* 0x8008C968 */
    R[3] = lw_(R[16] + 492);  /* 0x8008C96C */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008C970 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[2] << 16; if (_c) { goto L_8008C980; } }  /* 0x8008C974 */
    R[3] = R[3] + 4095;  /* 0x8008C97C */
L_8008C980:;
    R[2] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008C980 */
    R[2] = R[4] | R[2];  /* 0x8008C984 */
    sw_(R[29] + 16, R[2]);  /* 0x8008C988 */
    R[5] = lw_(R[16] + 24);  /* 0x8008C98C */
    R[6] = lw_(R[16] + 28);  /* 0x8008C990 */
    R[7] = lw_(R[16] + 32);  /* 0x8008C994 */
    R[4] = R[0] + 2;  /* 0x8008C998 */
    { R[31] = 0x8008C9A4u; psx_next = 0x800A7290u; return; }  /* 0x8008C99C jal */
    { R[31] = 0x8008C9ACu; R[4] = R[16] + R[0]; psx_next = 0x8008C35Cu; return; }  /* 0x8008C9A4 jal */
    R[17] = R[17] + 1;  /* 0x8008C9AC */
    { uint32_t _c = (R[17] != R[18]); R[2] = R[17] << 2; if (_c) { psx_next = 0x8008C644u; return; } }  /* 0x8008C9B0 b extern */
    R[31] = lw_(R[29] + 60);  /* 0x8008C9B8 */
    R[30] = lw_(R[29] + 56);  /* 0x8008C9BC */
    R[23] = lw_(R[29] + 52);  /* 0x8008C9C0 */
    R[22] = lw_(R[29] + 48);  /* 0x8008C9C4 */
    R[21] = lw_(R[29] + 44);  /* 0x8008C9C8 */
    R[20] = lw_(R[29] + 40);  /* 0x8008C9CC */
    R[19] = lw_(R[29] + 36);  /* 0x8008C9D0 */
    R[18] = lw_(R[29] + 32);  /* 0x8008C9D4 */
    R[17] = lw_(R[29] + 28);  /* 0x8008C9D8 */
    R[16] = lw_(R[29] + 24);  /* 0x8008C9DC */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008C9E0 jr ra */
}

void g0_8008C96C(void) {
    R[3] = lw_(R[16] + 492);  /* 0x8008C96C */
    R[2] = (uint32_t)((int32_t)R[2] >> 12);  /* 0x8008C970 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[4] = R[2] << 16; if (_c) { goto L_8008C980; } }  /* 0x8008C974 */
    R[3] = R[3] + 4095;  /* 0x8008C97C */
L_8008C980:;
    R[2] = (uint32_t)((int32_t)R[3] >> 12);  /* 0x8008C980 */
    R[2] = R[4] | R[2];  /* 0x8008C984 */
    sw_(R[29] + 16, R[2]);  /* 0x8008C988 */
    R[5] = lw_(R[16] + 24);  /* 0x8008C98C */
    R[6] = lw_(R[16] + 28);  /* 0x8008C990 */
    R[7] = lw_(R[16] + 32);  /* 0x8008C994 */
    R[4] = R[0] + 2;  /* 0x8008C998 */
    { R[31] = 0x8008C9A4u; psx_next = 0x800A7290u; return; }  /* 0x8008C99C jal */
    { R[31] = 0x8008C9ACu; R[4] = R[16] + R[0]; psx_next = 0x8008C35Cu; return; }  /* 0x8008C9A4 jal */
    R[17] = R[17] + 1;  /* 0x8008C9AC */
    { uint32_t _c = (R[17] != R[18]); R[2] = R[17] << 2; if (_c) { psx_next = 0x8008C644u; return; } }  /* 0x8008C9B0 b extern */
    R[31] = lw_(R[29] + 60);  /* 0x8008C9B8 */
    R[30] = lw_(R[29] + 56);  /* 0x8008C9BC */
    R[23] = lw_(R[29] + 52);  /* 0x8008C9C0 */
    R[22] = lw_(R[29] + 48);  /* 0x8008C9C4 */
    R[21] = lw_(R[29] + 44);  /* 0x8008C9C8 */
    R[20] = lw_(R[29] + 40);  /* 0x8008C9CC */
    R[19] = lw_(R[29] + 36);  /* 0x8008C9D0 */
    R[18] = lw_(R[29] + 32);  /* 0x8008C9D4 */
    R[17] = lw_(R[29] + 28);  /* 0x8008C9D8 */
    R[16] = lw_(R[29] + 24);  /* 0x8008C9DC */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008C9E0 jr ra */
}

void g0_8008C99C(void) {
    { R[31] = 0x8008C9A4u; psx_next = 0x800A7290u; return; }  /* 0x8008C99C jal */
    { R[31] = 0x8008C9ACu; R[4] = R[16] + R[0]; psx_next = 0x8008C35Cu; return; }  /* 0x8008C9A4 jal */
    R[17] = R[17] + 1;  /* 0x8008C9AC */
    { uint32_t _c = (R[17] != R[18]); R[2] = R[17] << 2; if (_c) { psx_next = 0x8008C644u; return; } }  /* 0x8008C9B0 b extern */
    R[31] = lw_(R[29] + 60);  /* 0x8008C9B8 */
    R[30] = lw_(R[29] + 56);  /* 0x8008C9BC */
    R[23] = lw_(R[29] + 52);  /* 0x8008C9C0 */
    R[22] = lw_(R[29] + 48);  /* 0x8008C9C4 */
    R[21] = lw_(R[29] + 44);  /* 0x8008C9C8 */
    R[20] = lw_(R[29] + 40);  /* 0x8008C9CC */
    R[19] = lw_(R[29] + 36);  /* 0x8008C9D0 */
    R[18] = lw_(R[29] + 32);  /* 0x8008C9D4 */
    R[17] = lw_(R[29] + 28);  /* 0x8008C9D8 */
    R[16] = lw_(R[29] + 24);  /* 0x8008C9DC */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008C9E0 jr ra */
}

void g0_8008C9A4(void) {
    { R[31] = 0x8008C9ACu; R[4] = R[16] + R[0]; psx_next = 0x8008C35Cu; return; }  /* 0x8008C9A4 jal */
    R[17] = R[17] + 1;  /* 0x8008C9AC */
    { uint32_t _c = (R[17] != R[18]); R[2] = R[17] << 2; if (_c) { psx_next = 0x8008C644u; return; } }  /* 0x8008C9B0 b extern */
    R[31] = lw_(R[29] + 60);  /* 0x8008C9B8 */
    R[30] = lw_(R[29] + 56);  /* 0x8008C9BC */
    R[23] = lw_(R[29] + 52);  /* 0x8008C9C0 */
    R[22] = lw_(R[29] + 48);  /* 0x8008C9C4 */
    R[21] = lw_(R[29] + 44);  /* 0x8008C9C8 */
    R[20] = lw_(R[29] + 40);  /* 0x8008C9CC */
    R[19] = lw_(R[29] + 36);  /* 0x8008C9D0 */
    R[18] = lw_(R[29] + 32);  /* 0x8008C9D4 */
    R[17] = lw_(R[29] + 28);  /* 0x8008C9D8 */
    R[16] = lw_(R[29] + 24);  /* 0x8008C9DC */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008C9E0 jr ra */
}

void g0_8008C9AC(void) {
    R[17] = R[17] + 1;  /* 0x8008C9AC */
    { uint32_t _c = (R[17] != R[18]); R[2] = R[17] << 2; if (_c) { psx_next = 0x8008C644u; return; } }  /* 0x8008C9B0 b extern */
    R[31] = lw_(R[29] + 60);  /* 0x8008C9B8 */
    R[30] = lw_(R[29] + 56);  /* 0x8008C9BC */
    R[23] = lw_(R[29] + 52);  /* 0x8008C9C0 */
    R[22] = lw_(R[29] + 48);  /* 0x8008C9C4 */
    R[21] = lw_(R[29] + 44);  /* 0x8008C9C8 */
    R[20] = lw_(R[29] + 40);  /* 0x8008C9CC */
    R[19] = lw_(R[29] + 36);  /* 0x8008C9D0 */
    R[18] = lw_(R[29] + 32);  /* 0x8008C9D4 */
    R[17] = lw_(R[29] + 28);  /* 0x8008C9D8 */
    R[16] = lw_(R[29] + 24);  /* 0x8008C9DC */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008C9E0 jr ra */
}

void g0_8008C9B8(void) {
    R[31] = lw_(R[29] + 60);  /* 0x8008C9B8 */
    R[30] = lw_(R[29] + 56);  /* 0x8008C9BC */
    R[23] = lw_(R[29] + 52);  /* 0x8008C9C0 */
    R[22] = lw_(R[29] + 48);  /* 0x8008C9C4 */
    R[21] = lw_(R[29] + 44);  /* 0x8008C9C8 */
    R[20] = lw_(R[29] + 40);  /* 0x8008C9CC */
    R[19] = lw_(R[29] + 36);  /* 0x8008C9D0 */
    R[18] = lw_(R[29] + 32);  /* 0x8008C9D4 */
    R[17] = lw_(R[29] + 28);  /* 0x8008C9D8 */
    R[16] = lw_(R[29] + 24);  /* 0x8008C9DC */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8008C9E0 jr ra */
}

void g0_8008C9E4(void) {
    R[29] = R[29] + 64;  /* 0x8008C9E4 */
    psx_next = 0x8008C9E8u; return;  /* fallthrough */
}

void g0_8008C9E8(void) {
    R[29] = R[29] - 8;  /* 0x8008C9E8 */
    R[7] = R[4] + R[0];  /* 0x8008C9EC */
    sw_(R[29] + 4, R[17]);  /* 0x8008C9F0 */
    sw_(R[29], R[16]);  /* 0x8008C9F4 */
    R[2] = lb_(R[7] + 790);  /* 0x8008C9F8 */
    { uint32_t _c = (R[2] != R[0]); sb_(R[7] + 496, R[0]); if (_c) { goto L_8008CBCC; } }  /* 0x8008CA00 */
    R[2] = lw_(R[7] + 16);  /* 0x8008CA08 */
    R[2] = R[2] & 0x1;  /* 0x8008CA10 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[5] + 20; if (_c) { goto L_8008CBCC; } }  /* 0x8008CA14 */
    R[9] = R[0] + R[0];  /* 0x8008CA1C */
    R[2] = 0x1u << 16;  /* 0x8008CA20 */
    R[3] = lw_(R[7] + 484);  /* 0x8008CA24 */
    R[4] = lw_(R[7] + 492);  /* 0x8008CA28 */
    R[5] = lw_(R[5] + 16);  /* 0x8008CA2C */
    R[25] = lw_(R[7] + 472);  /* 0x8008CA30 */
    R[24] = lw_(R[7] + 476);  /* 0x8008CA34 */
    R[15] = lw_(R[7] + 480);  /* 0x8008CA38 */
    R[14] = lw_(R[7] + 488);  /* 0x8008CA3C */
    R[10] = (uint32_t)(int16_t)lh_(R[7] + 12);  /* 0x8008CA40 */
    R[17] = R[3] + R[2];  /* 0x8008CA44 */
    { uint32_t _c = (R[5] == R[0]); R[16] = R[4] + R[2]; if (_c) { goto L_8008CBCC; } }  /* 0x8008CA48 */
    R[12] = 0x8000u << 16;  /* 0x8008CA50 */
    R[2] = 0x800Fu << 16;  /* 0x8008CA54 */
    R[2] = R[2] - 22908;  /* 0x8008CA58 */
    R[3] = R[10] << 2;  /* 0x8008CA5C */
    R[13] = R[3] + R[2];  /* 0x8008CA60 */
    R[11] = 0x1u << 16;  /* 0x8008CA64 */
    R[8] = R[6] + R[0];  /* 0x8008CA68 */
L_8008CA6C:;
    R[6] = lw_(R[8]);  /* 0x8008CA6C */
    { uint32_t _c = (R[7] == R[6]); if (_c) { goto L_8008CBC0; } }  /* 0x8008CA74 */
    R[2] = lb_(R[6] + 790);  /* 0x8008CA7C */
    R[3] = lw_(R[6] + 16);  /* 0x8008CA80 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8008CAE8; } }  /* 0x8008CA84 */
    R[2] = R[3] & 0x1;  /* 0x8008CA8C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8008CAE8; } }  /* 0x8008CA90 */
    R[2] = lw_(R[7] + 16);  /* 0x8008CA98 */
    R[2] = R[2] & R[12];  /* 0x8008CAA0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CAC0; } }  /* 0x8008CAA4 */
    R[2] = (uint32_t)(int16_t)lh_(R[6] + 12);  /* 0x8008CAAC */
    R[2] = R[2] ^ 0xE;  /* 0x8008CAB4 */
    { R[2] = (R[2] < (uint32_t)1u); goto L_8008CAE8; }  /* 0x8008CAB8 j */
L_8008CAC0:;
    R[2] = R[3] & R[12];  /* 0x8008CAC0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[10] ^ 0xE; if (_c) { goto L_8008CAD4; } }  /* 0x8008CAC4 */
    { R[2] = (R[2] < (uint32_t)1u); goto L_8008CAE8; }  /* 0x8008CACC j */
L_8008CAD4:;
    R[2] = R[0] + 1;  /* 0x8008CAD4 */
    R[3] = (uint32_t)(int16_t)lh_(R[6] + 12);  /* 0x8008CAD8 */
    R[4] = lw_(R[13]);  /* 0x8008CADC */
    R[2] = R[2] << (R[3] & 31);  /* 0x8008CAE0 */
    R[2] = R[4] & R[2];  /* 0x8008CAE4 */
L_8008CAE8:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CBC0; } }  /* 0x8008CAE8 */
    R[2] = lw_(R[6] + 472);  /* 0x8008CAF0 */
    R[3] = R[25] - R[2];  /* 0x8008CAF8 */
    { uint32_t _c = ((int32_t)R[3] < 0); if (_c) { goto L_8008CB18; } }  /* 0x8008CAFC */
    R[2] = lw_(R[6] + 484);  /* 0x8008CB04 */
    R[2] = R[2] + R[11];  /* 0x8008CB0C */
    { R[2] = ((int32_t)R[3] < (int32_t)R[2]); goto L_8008CB20; }  /* 0x8008CB10 j */
L_8008CB18:;
    R[2] = R[0] - R[3];  /* 0x8008CB18 */
    R[2] = ((int32_t)R[2] < (int32_t)R[17]);  /* 0x8008CB1C */
L_8008CB20:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CBC0; } }  /* 0x8008CB20 */
    R[2] = lw_(R[6] + 480);  /* 0x8008CB28 */
    R[3] = R[15] - R[2];  /* 0x8008CB30 */
    { uint32_t _c = ((int32_t)R[3] < 0); if (_c) { goto L_8008CB50; } }  /* 0x8008CB34 */
    R[2] = lw_(R[6] + 492);  /* 0x8008CB3C */
    R[2] = R[2] + R[11];  /* 0x8008CB44 */
    { R[2] = ((int32_t)R[3] < (int32_t)R[2]); goto L_8008CB58; }  /* 0x8008CB48 j */
L_8008CB50:;
    R[2] = R[0] - R[3];  /* 0x8008CB50 */
    R[2] = ((int32_t)R[2] < (int32_t)R[16]);  /* 0x8008CB54 */
L_8008CB58:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CBC0; } }  /* 0x8008CB58 */
    R[2] = lw_(R[6] + 476);  /* 0x8008CB60 */
    R[3] = R[24] - R[2];  /* 0x8008CB68 */
    { uint32_t _c = ((int32_t)R[3] < 0); if (_c) { goto L_8008CB80; } }  /* 0x8008CB6C */
    R[2] = lw_(R[6] + 488);  /* 0x8008CB74 */
    { R[2] = ((int32_t)R[3] < (int32_t)R[2]); goto L_8008CB88; }  /* 0x8008CB78 j */
L_8008CB80:;
    R[2] = R[0] - R[3];  /* 0x8008CB80 */
    R[2] = ((int32_t)R[2] < (int32_t)R[14]);  /* 0x8008CB84 */
L_8008CB88:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CBC0; } }  /* 0x8008CB88 */
    R[2] = lb_(R[7] + 496);  /* 0x8008CB90 */
    R[3] = R[2] + 1;  /* 0x8008CB98 */
    R[2] = R[2] & 0xFF;  /* 0x8008CB9C */
    R[2] = R[2] << 2;  /* 0x8008CBA0 */
    R[2] = R[7] + R[2];  /* 0x8008CBA4 */
    sb_(R[7] + 496, R[3]);  /* 0x8008CBA8 */
    sw_(R[2] + 500, R[6]);  /* 0x8008CBAC */
    R[3] = lb_(R[7] + 496);  /* 0x8008CBB0 */
    R[2] = R[0] + 6;  /* 0x8008CBB4 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8008CBCC; } }  /* 0x8008CBB8 */
L_8008CBC0:;
    R[9] = R[9] + 1;  /* 0x8008CBC0 */
    { uint32_t _c = (R[9] != R[5]); R[8] = R[8] + 4; if (_c) { psx_bb(); goto L_8008CA6C; } }  /* 0x8008CBC4 */
L_8008CBCC:;
    R[17] = lw_(R[29] + 4);  /* 0x8008CBCC */
    R[16] = lw_(R[29]);  /* 0x8008CBD0 */
    { R[29] = R[29] + 8; psx_next = R[31]; return; }  /* 0x8008CBD4 jr ra */
}

void g0_8008CBDC(void) {
    R[29] = R[29] - 16;  /* 0x8008CBDC */
    R[7] = R[4] + R[0];  /* 0x8008CBE0 */
    sw_(R[29] + 8, R[18]);  /* 0x8008CBE4 */
    sw_(R[29] + 4, R[17]);  /* 0x8008CBE8 */
    sw_(R[29], R[16]);  /* 0x8008CBEC */
    R[2] = lb_(R[7] + 790);  /* 0x8008CBF0 */
    sb_(R[7] + 497, R[0]);  /* 0x8008CBF4 */
    sw_(R[7] + 524, R[0]);  /* 0x8008CBF8 */
    { uint32_t _c = (R[2] != R[0]); sb_(R[7] + 498, R[0]); if (_c) { psx_next = 0x8008CE80u; return; } }  /* 0x8008CBFC b extern */
    R[2] = lw_(R[7] + 16);  /* 0x8008CC04 */
    R[2] = R[2] & 0x1;  /* 0x8008CC0C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[5] + 20; if (_c) { psx_next = 0x8008CE80u; return; } }  /* 0x8008CC10 b extern */
    R[2] = R[0] + 14;  /* 0x8008CC18 */
    R[5] = lw_(R[5] + 16);  /* 0x8008CC1C */
    R[18] = lw_(R[7] + 472);  /* 0x8008CC20 */
    R[17] = lw_(R[7] + 480);  /* 0x8008CC24 */
    R[13] = lw_(R[7] + 484);  /* 0x8008CC28 */
    R[9] = (uint32_t)(int16_t)lh_(R[7] + 12);  /* 0x8008CC2C */
    R[12] = lw_(R[7] + 492);  /* 0x8008CC30 */
    { uint32_t _c = (R[9] == R[2]); R[14] = 0x800u << 16; if (_c) { psx_next = 0x8008CE80u; return; } }  /* 0x8008CC34 b extern */
    { uint32_t _c = (R[5] == R[0]); R[11] = R[0] + R[0]; if (_c) { psx_next = 0x8008CE80u; return; } }  /* 0x8008CC3C b extern */
    R[25] = 0x8000u << 16;  /* 0x8008CC44 */
    R[2] = 0x800Fu << 16;  /* 0x8008CC48 */
    R[2] = R[2] - 22908;  /* 0x8008CC4C */
    R[3] = R[9] << 2;  /* 0x8008CC50 */
    R[16] = R[3] + R[2];  /* 0x8008CC54 */
    R[24] = R[0] + 5;  /* 0x8008CC58 */
    R[15] = R[0] + 6;  /* 0x8008CC5C */
    R[10] = R[4] + R[0];  /* 0x8008CC60 */
    R[6] = lw_(R[10]);  /* 0x8008CC64 */
    { uint32_t _c = (R[7] == R[6]); if (_c) { psx_next = 0x8008CE74u; return; } }  /* 0x8008CC6C b extern */
    R[2] = lb_(R[6] + 790);  /* 0x8008CC74 */
    R[3] = lw_(R[6] + 16);  /* 0x8008CC78 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8008CCE0u; return; } }  /* 0x8008CC7C b extern */
    R[2] = R[3] & 0x1;  /* 0x8008CC84 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8008CCE0u; return; } }  /* 0x8008CC88 b extern */
    R[2] = lw_(R[7] + 16);  /* 0x8008CC90 */
    R[2] = R[2] & R[25];  /* 0x8008CC98 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CCB8; } }  /* 0x8008CC9C */
    R[2] = (uint32_t)(int16_t)lh_(R[6] + 12);  /* 0x8008CCA4 */
    R[2] = R[2] ^ 0xE;  /* 0x8008CCAC */
    { R[2] = (R[2] < (uint32_t)1u); psx_next = 0x8008CCE0u; return; }  /* 0x8008CCB0 j extern */
L_8008CCB8:;
    R[2] = R[3] & R[25];  /* 0x8008CCB8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] ^ 0xE; if (_c) { psx_next = 0x8008CCCCu; return; } }  /* 0x8008CCBC b extern */
    { R[2] = (R[2] < (uint32_t)1u); psx_next = 0x8008CCE0u; return; }  /* 0x8008CCC4 j extern */
}

void g0_8008CC64(void) {
    R[6] = lw_(R[10]);  /* 0x8008CC64 */
    { uint32_t _c = (R[7] == R[6]); if (_c) { psx_next = 0x8008CE74u; return; } }  /* 0x8008CC6C b extern */
    R[2] = lb_(R[6] + 790);  /* 0x8008CC74 */
    R[3] = lw_(R[6] + 16);  /* 0x8008CC78 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8008CCE0u; return; } }  /* 0x8008CC7C b extern */
    R[2] = R[3] & 0x1;  /* 0x8008CC84 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8008CCE0u; return; } }  /* 0x8008CC88 b extern */
    R[2] = lw_(R[7] + 16);  /* 0x8008CC90 */
    R[2] = R[2] & R[25];  /* 0x8008CC98 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CCB8; } }  /* 0x8008CC9C */
    R[2] = (uint32_t)(int16_t)lh_(R[6] + 12);  /* 0x8008CCA4 */
    R[2] = R[2] ^ 0xE;  /* 0x8008CCAC */
    { R[2] = (R[2] < (uint32_t)1u); psx_next = 0x8008CCE0u; return; }  /* 0x8008CCB0 j extern */
L_8008CCB8:;
    R[2] = R[3] & R[25];  /* 0x8008CCB8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[9] ^ 0xE; if (_c) { psx_next = 0x8008CCCCu; return; } }  /* 0x8008CCBC b extern */
    { R[2] = (R[2] < (uint32_t)1u); psx_next = 0x8008CCE0u; return; }  /* 0x8008CCC4 j extern */
}

void g0_8008CCCC(void) {
    R[2] = R[0] + 1;  /* 0x8008CCCC */
    R[3] = (uint32_t)(int16_t)lh_(R[6] + 12);  /* 0x8008CCD0 */
    R[4] = lw_(R[16]);  /* 0x8008CCD4 */
    R[2] = R[2] << (R[3] & 31);  /* 0x8008CCD8 */
    R[2] = R[4] & R[2];  /* 0x8008CCDC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CE74; } }  /* 0x8008CCE0 */
    R[2] = lw_(R[6] + 472);  /* 0x8008CCE8 */
    R[3] = R[18] - R[2];  /* 0x8008CCF0 */
    { uint32_t _c = ((int32_t)R[3] < 0); if (_c) { goto L_8008CD08; } }  /* 0x8008CCF4 */
    R[2] = lw_(R[6] + 484);  /* 0x8008CCFC */
    { R[2] = ((int32_t)R[3] < (int32_t)R[2]); goto L_8008CD10; }  /* 0x8008CD00 j */
L_8008CD08:;
    R[2] = R[0] - R[3];  /* 0x8008CD08 */
    R[2] = ((int32_t)R[2] < (int32_t)R[13]);  /* 0x8008CD0C */
L_8008CD10:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CE74; } }  /* 0x8008CD10 */
    R[2] = lw_(R[6] + 480);  /* 0x8008CD18 */
    R[3] = R[17] - R[2];  /* 0x8008CD20 */
    { uint32_t _c = ((int32_t)R[3] < 0); if (_c) { goto L_8008CD38; } }  /* 0x8008CD24 */
    R[2] = lw_(R[6] + 492);  /* 0x8008CD2C */
    { R[2] = ((int32_t)R[3] < (int32_t)R[2]); goto L_8008CD40; }  /* 0x8008CD30 j */
L_8008CD38:;
    R[2] = R[0] - R[3];  /* 0x8008CD38 */
    R[2] = ((int32_t)R[2] < (int32_t)R[12]);  /* 0x8008CD3C */
L_8008CD40:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CE74; } }  /* 0x8008CD40 */
    R[3] = lw_(R[6] + 476);  /* 0x8008CD48 */
    R[2] = lw_(R[7] + 476);  /* 0x8008CD4C */
    { uint32_t _c = (R[9] == R[24]); R[4] = R[3] - R[2]; if (_c) { goto L_8008CD90; } }  /* 0x8008CD50 */
    R[2] = lw_(R[7] + 488);  /* 0x8008CD58 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8008CD90; } }  /* 0x8008CD60 */
    R[2] = lb_(R[7] + 498);  /* 0x8008CD68 */
    R[3] = R[2] & 0xFF;  /* 0x8008CD70 */
    { uint32_t _c = (R[3] == R[15]); R[2] = R[2] + 1; if (_c) { goto L_8008CD90; } }  /* 0x8008CD74 */
    sb_(R[7] + 498, R[2]);  /* 0x8008CD7C */
    R[2] = R[3] << 2;  /* 0x8008CD80 */
    R[2] = R[7] + R[2];  /* 0x8008CD84 */
    { sw_(R[2] + 552, R[6]); goto L_8008CE74; }  /* 0x8008CD88 j */
L_8008CD90:;
    R[8] = lw_(R[6] + 488);  /* 0x8008CD90 */
    R[4] = R[0] - R[4];  /* 0x8008CD94 */
    R[2] = ((int32_t)R[4] < (int32_t)R[8]);  /* 0x8008CD98 */
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[14]); if (_c) { goto L_8008CE14; } }  /* 0x8008CD9C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CE14; } }  /* 0x8008CDA4 */
    R[2] = lw_(R[6] + 16);  /* 0x8008CDAC */
    R[2] = R[2] & 0x400;  /* 0x8008CDB4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CE14; } }  /* 0x8008CDB8 */
    R[2] = lw_(R[6] + 484);  /* 0x8008CDC0 */
    R[2] = R[2] << 1;  /* 0x8008CDC8 */
    R[2] = ((int32_t)R[13] < (int32_t)R[2]);  /* 0x8008CDCC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CE14; } }  /* 0x8008CDD0 */
    R[2] = lw_(R[6] + 492);  /* 0x8008CDD8 */
    R[2] = R[2] << 1;  /* 0x8008CDE0 */
    R[2] = ((int32_t)R[12] < (int32_t)R[2]);  /* 0x8008CDE4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CE14; } }  /* 0x8008CDE8 */
    R[2] = lw_(R[7] + 352);  /* 0x8008CDF0 */
    R[3] = lw_(R[6] + 476);  /* 0x8008CDF4 */
    R[2] = lw_(R[2] + 12);  /* 0x8008CDF8 */
    R[3] = R[3] + R[8];  /* 0x8008CDFC */
    R[3] = ((int32_t)R[3] < (int32_t)R[2]);  /* 0x8008CE00 */
    { uint32_t _c = (R[3] != R[0]); if (_c) { goto L_8008CE14; } }  /* 0x8008CE04 */
    sw_(R[7] + 524, R[6]);  /* 0x8008CE0C */
    R[14] = R[4] + R[0];  /* 0x8008CE10 */
L_8008CE14:;
    { uint32_t _c = (R[9] != R[24]); if (_c) { goto L_8008CE40; } }  /* 0x8008CE14 */
    R[2] = lw_(R[6] + 488);  /* 0x8008CE1C */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[3] = R[4] + R[0]; if (_c) { goto L_8008CE2C; } }  /* 0x8008CE20 */
    R[3] = R[0] - R[3];  /* 0x8008CE28 */
L_8008CE2C:;
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8008CE2C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CE50; } }  /* 0x8008CE30 */
    { R[11] = R[11] + 1; goto L_8008CE78; }  /* 0x8008CE38 j */
L_8008CE40:;
    R[2] = lw_(R[6] + 488);  /* 0x8008CE40 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8008CE74; } }  /* 0x8008CE48 */
L_8008CE50:;
    R[2] = lb_(R[7] + 497);  /* 0x8008CE50 */
    R[3] = R[2] & 0xFF;  /* 0x8008CE58 */
    { uint32_t _c = (R[3] == R[15]); R[2] = R[2] + 1; if (_c) { goto L_8008CE74; } }  /* 0x8008CE5C */
    sb_(R[7] + 497, R[2]);  /* 0x8008CE64 */
    R[2] = R[3] << 2;  /* 0x8008CE68 */
    R[2] = R[7] + R[2];  /* 0x8008CE6C */
    sw_(R[2] + 528, R[6]);  /* 0x8008CE70 */
L_8008CE74:;
    R[11] = R[11] + 1;  /* 0x8008CE74 */
L_8008CE78:;
    { uint32_t _c = (R[11] != R[5]); R[10] = R[10] + 4; if (_c) { psx_next = 0x8008CC64u; return; } }  /* 0x8008CE78 b extern */
    R[18] = lw_(R[29] + 8);  /* 0x8008CE80 */
    R[17] = lw_(R[29] + 4);  /* 0x8008CE84 */
    R[16] = lw_(R[29]);  /* 0x8008CE88 */
    { R[29] = R[29] + 16; psx_next = R[31]; return; }  /* 0x8008CE8C jr ra */
}

void g0_8008CCE0(void) {
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CE74; } }  /* 0x8008CCE0 */
    R[2] = lw_(R[6] + 472);  /* 0x8008CCE8 */
    R[3] = R[18] - R[2];  /* 0x8008CCF0 */
    { uint32_t _c = ((int32_t)R[3] < 0); if (_c) { goto L_8008CD08; } }  /* 0x8008CCF4 */
    R[2] = lw_(R[6] + 484);  /* 0x8008CCFC */
    { R[2] = ((int32_t)R[3] < (int32_t)R[2]); goto L_8008CD10; }  /* 0x8008CD00 j */
L_8008CD08:;
    R[2] = R[0] - R[3];  /* 0x8008CD08 */
    R[2] = ((int32_t)R[2] < (int32_t)R[13]);  /* 0x8008CD0C */
L_8008CD10:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CE74; } }  /* 0x8008CD10 */
    R[2] = lw_(R[6] + 480);  /* 0x8008CD18 */
    R[3] = R[17] - R[2];  /* 0x8008CD20 */
    { uint32_t _c = ((int32_t)R[3] < 0); if (_c) { goto L_8008CD38; } }  /* 0x8008CD24 */
    R[2] = lw_(R[6] + 492);  /* 0x8008CD2C */
    { R[2] = ((int32_t)R[3] < (int32_t)R[2]); goto L_8008CD40; }  /* 0x8008CD30 j */
L_8008CD38:;
    R[2] = R[0] - R[3];  /* 0x8008CD38 */
    R[2] = ((int32_t)R[2] < (int32_t)R[12]);  /* 0x8008CD3C */
L_8008CD40:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CE74; } }  /* 0x8008CD40 */
    R[3] = lw_(R[6] + 476);  /* 0x8008CD48 */
    R[2] = lw_(R[7] + 476);  /* 0x8008CD4C */
    { uint32_t _c = (R[9] == R[24]); R[4] = R[3] - R[2]; if (_c) { goto L_8008CD90; } }  /* 0x8008CD50 */
    R[2] = lw_(R[7] + 488);  /* 0x8008CD58 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8008CD90; } }  /* 0x8008CD60 */
    R[2] = lb_(R[7] + 498);  /* 0x8008CD68 */
    R[3] = R[2] & 0xFF;  /* 0x8008CD70 */
    { uint32_t _c = (R[3] == R[15]); R[2] = R[2] + 1; if (_c) { goto L_8008CD90; } }  /* 0x8008CD74 */
    sb_(R[7] + 498, R[2]);  /* 0x8008CD7C */
    R[2] = R[3] << 2;  /* 0x8008CD80 */
    R[2] = R[7] + R[2];  /* 0x8008CD84 */
    { sw_(R[2] + 552, R[6]); goto L_8008CE74; }  /* 0x8008CD88 j */
L_8008CD90:;
    R[8] = lw_(R[6] + 488);  /* 0x8008CD90 */
    R[4] = R[0] - R[4];  /* 0x8008CD94 */
    R[2] = ((int32_t)R[4] < (int32_t)R[8]);  /* 0x8008CD98 */
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[14]); if (_c) { goto L_8008CE14; } }  /* 0x8008CD9C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CE14; } }  /* 0x8008CDA4 */
    R[2] = lw_(R[6] + 16);  /* 0x8008CDAC */
    R[2] = R[2] & 0x400;  /* 0x8008CDB4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CE14; } }  /* 0x8008CDB8 */
    R[2] = lw_(R[6] + 484);  /* 0x8008CDC0 */
    R[2] = R[2] << 1;  /* 0x8008CDC8 */
    R[2] = ((int32_t)R[13] < (int32_t)R[2]);  /* 0x8008CDCC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CE14; } }  /* 0x8008CDD0 */
    R[2] = lw_(R[6] + 492);  /* 0x8008CDD8 */
    R[2] = R[2] << 1;  /* 0x8008CDE0 */
    R[2] = ((int32_t)R[12] < (int32_t)R[2]);  /* 0x8008CDE4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CE14; } }  /* 0x8008CDE8 */
    R[2] = lw_(R[7] + 352);  /* 0x8008CDF0 */
    R[3] = lw_(R[6] + 476);  /* 0x8008CDF4 */
    R[2] = lw_(R[2] + 12);  /* 0x8008CDF8 */
    R[3] = R[3] + R[8];  /* 0x8008CDFC */
    R[3] = ((int32_t)R[3] < (int32_t)R[2]);  /* 0x8008CE00 */
    { uint32_t _c = (R[3] != R[0]); if (_c) { goto L_8008CE14; } }  /* 0x8008CE04 */
    sw_(R[7] + 524, R[6]);  /* 0x8008CE0C */
    R[14] = R[4] + R[0];  /* 0x8008CE10 */
L_8008CE14:;
    { uint32_t _c = (R[9] != R[24]); if (_c) { goto L_8008CE40; } }  /* 0x8008CE14 */
    R[2] = lw_(R[6] + 488);  /* 0x8008CE1C */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[3] = R[4] + R[0]; if (_c) { goto L_8008CE2C; } }  /* 0x8008CE20 */
    R[3] = R[0] - R[3];  /* 0x8008CE28 */
L_8008CE2C:;
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8008CE2C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008CE50; } }  /* 0x8008CE30 */
    { R[11] = R[11] + 1; goto L_8008CE78; }  /* 0x8008CE38 j */
L_8008CE40:;
    R[2] = lw_(R[6] + 488);  /* 0x8008CE40 */
    { uint32_t _c = (R[2] != R[4]); if (_c) { goto L_8008CE74; } }  /* 0x8008CE48 */
L_8008CE50:;
    R[2] = lb_(R[7] + 497);  /* 0x8008CE50 */
    R[3] = R[2] & 0xFF;  /* 0x8008CE58 */
    { uint32_t _c = (R[3] == R[15]); R[2] = R[2] + 1; if (_c) { goto L_8008CE74; } }  /* 0x8008CE5C */
    sb_(R[7] + 497, R[2]);  /* 0x8008CE64 */
    R[2] = R[3] << 2;  /* 0x8008CE68 */
    R[2] = R[7] + R[2];  /* 0x8008CE6C */
    sw_(R[2] + 528, R[6]);  /* 0x8008CE70 */
L_8008CE74:;
    R[11] = R[11] + 1;  /* 0x8008CE74 */
L_8008CE78:;
    { uint32_t _c = (R[11] != R[5]); R[10] = R[10] + 4; if (_c) { psx_next = 0x8008CC64u; return; } }  /* 0x8008CE78 b extern */
    R[18] = lw_(R[29] + 8);  /* 0x8008CE80 */
    R[17] = lw_(R[29] + 4);  /* 0x8008CE84 */
    R[16] = lw_(R[29]);  /* 0x8008CE88 */
    { R[29] = R[29] + 16; psx_next = R[31]; return; }  /* 0x8008CE8C jr ra */
}

void g0_8008CE74(void) {
    R[11] = R[11] + 1;  /* 0x8008CE74 */
    { uint32_t _c = (R[11] != R[5]); R[10] = R[10] + 4; if (_c) { psx_next = 0x8008CC64u; return; } }  /* 0x8008CE78 b extern */
    R[18] = lw_(R[29] + 8);  /* 0x8008CE80 */
    R[17] = lw_(R[29] + 4);  /* 0x8008CE84 */
    R[16] = lw_(R[29]);  /* 0x8008CE88 */
    { R[29] = R[29] + 16; psx_next = R[31]; return; }  /* 0x8008CE8C jr ra */
}

void g0_8008CE80(void) {
    R[18] = lw_(R[29] + 8);  /* 0x8008CE80 */
    R[17] = lw_(R[29] + 4);  /* 0x8008CE84 */
    R[16] = lw_(R[29]);  /* 0x8008CE88 */
    { R[29] = R[29] + 16; psx_next = R[31]; return; }  /* 0x8008CE8C jr ra */
}

void g0_8008CE94(void) {
    R[7] = R[4] + R[0];  /* 0x8008CE94 */
    R[2] = lw_(R[7] + 236);  /* 0x8008CE98 */
    { uint32_t _c = (R[2] != R[0]); R[8] = R[0] + R[0]; if (_c) { goto L_8008CEBC; } }  /* 0x8008CEA0 */
    R[2] = lw_(R[7] + 352);  /* 0x8008CEA8 */
    R[2] = lw_(R[2] + 12);  /* 0x8008CEB0 */
    { psx_next = R[31]; return; }  /* 0x8008CEB4 jr ra */
L_8008CEBC:;
    R[5] = R[8] + R[0];  /* 0x8008CEBC */
    R[9] = R[0] + 4;  /* 0x8008CEC0 */
    R[4] = R[7] + R[0];  /* 0x8008CEC4 */
    R[6] = R[0] + 240;  /* 0x8008CEC8 */
L_8008CECC:;
    R[3] = lw_(R[7] + 236);  /* 0x8008CECC */
    R[2] = R[7] + R[6];  /* 0x8008CED0 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8008CEE0; } }  /* 0x8008CED4 */
    R[8] = R[5] + R[0];  /* 0x8008CEDC */
L_8008CEE0:;
    R[10] = lw_(R[4] + 240);  /* 0x8008CEE0 */
    R[11] = lw_(R[4] + 244);  /* 0x8008CEE4 */
    R[12] = lw_(R[4] + 248);  /* 0x8008CEE8 */
    R[13] = lw_(R[4] + 252);  /* 0x8008CEEC */
    sw_(R[4] + 356, R[10]);  /* 0x8008CEF0 */
    sw_(R[4] + 360, R[11]);  /* 0x8008CEF4 */
    sw_(R[4] + 364, R[12]);  /* 0x8008CEF8 */
    sw_(R[4] + 368, R[13]);  /* 0x8008CEFC */
    R[10] = lw_(R[4] + 256);  /* 0x8008CF00 */
    R[11] = lw_(R[4] + 260);  /* 0x8008CF04 */
    R[12] = lw_(R[4] + 264);  /* 0x8008CF08 */
    sw_(R[4] + 372, R[10]);  /* 0x8008CF0C */
    sw_(R[4] + 376, R[11]);  /* 0x8008CF10 */
    sw_(R[4] + 380, R[12]);  /* 0x8008CF14 */
    R[4] = R[4] + 28;  /* 0x8008CF18 */
    R[5] = R[5] + 1;  /* 0x8008CF1C */
    { uint32_t _c = (R[5] != R[9]); R[6] = R[6] + 28; if (_c) { psx_bb(); goto L_8008CECC; } }  /* 0x8008CF20 */
    R[3] = R[8] << 3;  /* 0x8008CF28 */
    R[3] = R[3] - R[8];  /* 0x8008CF2C */
    R[3] = R[3] << 2;  /* 0x8008CF30 */
    R[3] = R[3] + 356;  /* 0x8008CF34 */
    R[2] = lw_(R[7] + 376);  /* 0x8008CF38 */
    R[4] = lw_(R[7] + 404);  /* 0x8008CF3C */
    R[5] = lw_(R[7] + 460);  /* 0x8008CF40 */
    R[2] = R[2] & R[4];  /* 0x8008CF44 */
    R[4] = lw_(R[7] + 432);  /* 0x8008CF48 */
    R[3] = R[7] + R[3];  /* 0x8008CF4C */
    sw_(R[7] + 352, R[3]);  /* 0x8008CF50 */
    R[2] = R[2] & R[4];  /* 0x8008CF54 */
    R[2] = R[2] & R[5];  /* 0x8008CF58 */
    sw_(R[7] + 468, R[2]);  /* 0x8008CF5C */
    R[2] = lw_(R[3] + 12);  /* 0x8008CF60 */
    { psx_next = R[31]; return; }  /* 0x8008CF64 jr ra */
}

void g0_8008CF6C(void) {
    R[29] = R[29] - 48;  /* 0x8008CF6C */
    sw_(R[29] + 36, R[19]);  /* 0x8008CF70 */
    R[19] = R[4] + R[0];  /* 0x8008CF74 */
    sw_(R[29] + 40, R[31]);  /* 0x8008CF78 */
    sw_(R[29] + 32, R[18]);  /* 0x8008CF7C */
    sw_(R[29] + 28, R[17]);  /* 0x8008CF80 */
    sw_(R[29] + 24, R[16]);  /* 0x8008CF84 */
    R[18] = lw_(R[19] + 472);  /* 0x8008CF88 */
    R[16] = lw_(R[19] + 476);  /* 0x8008CF8C */
    R[17] = lw_(R[19] + 480);  /* 0x8008CF90 */
    R[2] = lw_(R[19] + 492);  /* 0x8008CF94 */
    sw_(R[19] + 352, R[0]);  /* 0x8008CF98 */
    sw_(R[29] + 16, R[19]);  /* 0x8008CF9C */
    R[18] = R[18] + R[5];  /* 0x8008CFA0 */
    R[4] = R[18] + R[0];  /* 0x8008CFA4 */
    R[16] = R[16] + R[6];  /* 0x8008CFA8 */
    R[5] = R[16] + R[0];  /* 0x8008CFAC */
    R[17] = R[17] + R[7];  /* 0x8008CFB0 */
    R[6] = R[17] + R[2];  /* 0x8008CFB4 */
    { R[31] = 0x8008CFC0u; R[7] = R[19] + 356; psx_next = 0x80092A7Cu; return; }  /* 0x8008CFB8 jal */
    R[5] = R[16] + R[0];  /* 0x8008CFC0 */
    R[4] = lw_(R[19] + 484);  /* 0x8008CFC4 */
    R[6] = lw_(R[19] + 492);  /* 0x8008CFC8 */
    R[7] = R[19] + 384;  /* 0x8008CFCC */
    sw_(R[29] + 16, R[19]);  /* 0x8008CFD0 */
    R[4] = R[18] + R[4];  /* 0x8008CFD4 */
    { R[31] = 0x8008CFE0u; R[6] = R[17] + R[6]; psx_next = 0x80092A7Cu; return; }  /* 0x8008CFD8 jal */
    R[4] = R[18] + R[0];  /* 0x8008CFE0 */
    R[5] = R[16] + R[0];  /* 0x8008CFE4 */
    R[6] = R[17] + R[0];  /* 0x8008CFE8 */
    R[7] = R[19] + 412;  /* 0x8008CFEC */
    { R[31] = 0x8008CFF8u; sw_(R[29] + 16, R[19]); psx_next = 0x80092A7Cu; return; }  /* 0x8008CFF0 jal */
    R[5] = R[16] + R[0];  /* 0x8008CFF8 */
    R[6] = R[17] + R[0];  /* 0x8008CFFC */
    R[4] = lw_(R[19] + 484);  /* 0x8008D000 */
    R[7] = R[19] + 440;  /* 0x8008D004 */
    sw_(R[29] + 16, R[19]);  /* 0x8008D008 */
    { R[31] = 0x8008D014u; R[4] = R[18] + R[4]; psx_next = 0x80092A7Cu; return; }  /* 0x8008D00C jal */
    R[9] = R[0] + R[0];  /* 0x8008D014 */
    R[7] = R[9] + R[0];  /* 0x8008D018 */
    R[6] = R[9] + R[0];  /* 0x8008D01C */
    R[5] = R[9] + R[0];  /* 0x8008D020 */
    R[2] = 0x800Fu << 16;  /* 0x8008D024 */
    R[11] = R[2] - 22460;  /* 0x8008D028 */
    R[10] = R[0] + 4;  /* 0x8008D02C */
    R[8] = R[0] + 356;  /* 0x8008D030 */
L_8008D034:;
    R[4] = R[19] + R[8];  /* 0x8008D034 */
    R[2] = lb_(R[4] + 1);  /* 0x8008D038 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D09C; } }  /* 0x8008D040 */
    { uint32_t _c = (R[9] != R[0]); if (_c) { goto L_8008D060; } }  /* 0x8008D048 */
    R[6] = lw_(R[4] + 12);  /* 0x8008D050 */
    R[7] = R[5] + R[0];  /* 0x8008D054 */
    { R[9] = R[0] + 1; goto L_8008D0A0; }  /* 0x8008D058 j */
L_8008D060:;
    R[3] = lw_(R[4] + 12);  /* 0x8008D060 */
    { uint32_t _c = (R[6] != R[3]); R[2] = ((int32_t)R[6] < (int32_t)R[3]); if (_c) { goto L_8008D088; } }  /* 0x8008D068 */
    R[2] = lb_(R[4] + 3);  /* 0x8008D070 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D0A0; } }  /* 0x8008D078 */
    { R[7] = R[5] + R[0]; goto L_8008D0A0; }  /* 0x8008D080 j */
L_8008D088:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D0A0; } }  /* 0x8008D088 */
    R[6] = R[3] + R[0];  /* 0x8008D090 */
    { R[7] = R[5] + R[0]; goto L_8008D0A0; }  /* 0x8008D094 j */
L_8008D09C:;
    sw_(R[4] + 24, R[11]);  /* 0x8008D09C */
L_8008D0A0:;
    R[5] = R[5] + 1;  /* 0x8008D0A0 */
    { uint32_t _c = (R[5] != R[10]); R[8] = R[8] + 28; if (_c) { psx_bb(); goto L_8008D034; } }  /* 0x8008D0A4 */
    { uint32_t _c = (R[9] != R[0]); R[3] = R[7] << 3; if (_c) { goto L_8008D0C0; } }  /* 0x8008D0AC */
    R[2] = 0x800Fu << 16;  /* 0x8008D0B4 */
    R[2] = R[2] - 22460;  /* 0x8008D0B8 */
    sw_(R[19] + 380, R[2]);  /* 0x8008D0BC */
L_8008D0C0:;
    R[3] = R[3] - R[7];  /* 0x8008D0C0 */
    R[3] = R[3] << 2;  /* 0x8008D0C4 */
    R[3] = R[3] + 356;  /* 0x8008D0C8 */
    R[2] = lw_(R[19] + 376);  /* 0x8008D0CC */
    R[4] = lw_(R[19] + 404);  /* 0x8008D0D0 */
    R[5] = lw_(R[19] + 460);  /* 0x8008D0D4 */
    R[2] = R[2] & R[4];  /* 0x8008D0D8 */
    R[4] = lw_(R[19] + 432);  /* 0x8008D0DC */
    R[3] = R[19] + R[3];  /* 0x8008D0E0 */
    sw_(R[19] + 352, R[3]);  /* 0x8008D0E4 */
    R[2] = R[2] & R[4];  /* 0x8008D0E8 */
    R[2] = R[2] & R[5];  /* 0x8008D0EC */
    sw_(R[19] + 468, R[2]);  /* 0x8008D0F0 */
    R[2] = lw_(R[3] + 12);  /* 0x8008D0F4 */
    R[31] = lw_(R[29] + 40);  /* 0x8008D0F8 */
    R[19] = lw_(R[29] + 36);  /* 0x8008D0FC */
    R[18] = lw_(R[29] + 32);  /* 0x8008D100 */
    R[17] = lw_(R[29] + 28);  /* 0x8008D104 */
    R[16] = lw_(R[29] + 24);  /* 0x8008D108 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8008D10C jr ra */
}

void g0_8008CFC0(void) {
    R[5] = R[16] + R[0];  /* 0x8008CFC0 */
    R[4] = lw_(R[19] + 484);  /* 0x8008CFC4 */
    R[6] = lw_(R[19] + 492);  /* 0x8008CFC8 */
    R[7] = R[19] + 384;  /* 0x8008CFCC */
    sw_(R[29] + 16, R[19]);  /* 0x8008CFD0 */
    R[4] = R[18] + R[4];  /* 0x8008CFD4 */
    { R[31] = 0x8008CFE0u; R[6] = R[17] + R[6]; psx_next = 0x80092A7Cu; return; }  /* 0x8008CFD8 jal */
    R[4] = R[18] + R[0];  /* 0x8008CFE0 */
    R[5] = R[16] + R[0];  /* 0x8008CFE4 */
    R[6] = R[17] + R[0];  /* 0x8008CFE8 */
    R[7] = R[19] + 412;  /* 0x8008CFEC */
    { R[31] = 0x8008CFF8u; sw_(R[29] + 16, R[19]); psx_next = 0x80092A7Cu; return; }  /* 0x8008CFF0 jal */
    R[5] = R[16] + R[0];  /* 0x8008CFF8 */
    R[6] = R[17] + R[0];  /* 0x8008CFFC */
    R[4] = lw_(R[19] + 484);  /* 0x8008D000 */
    R[7] = R[19] + 440;  /* 0x8008D004 */
    sw_(R[29] + 16, R[19]);  /* 0x8008D008 */
    { R[31] = 0x8008D014u; R[4] = R[18] + R[4]; psx_next = 0x80092A7Cu; return; }  /* 0x8008D00C jal */
    R[9] = R[0] + R[0];  /* 0x8008D014 */
    R[7] = R[9] + R[0];  /* 0x8008D018 */
    R[6] = R[9] + R[0];  /* 0x8008D01C */
    R[5] = R[9] + R[0];  /* 0x8008D020 */
    R[2] = 0x800Fu << 16;  /* 0x8008D024 */
    R[11] = R[2] - 22460;  /* 0x8008D028 */
    R[10] = R[0] + 4;  /* 0x8008D02C */
    R[8] = R[0] + 356;  /* 0x8008D030 */
L_8008D034:;
    R[4] = R[19] + R[8];  /* 0x8008D034 */
    R[2] = lb_(R[4] + 1);  /* 0x8008D038 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D09C; } }  /* 0x8008D040 */
    { uint32_t _c = (R[9] != R[0]); if (_c) { goto L_8008D060; } }  /* 0x8008D048 */
    R[6] = lw_(R[4] + 12);  /* 0x8008D050 */
    R[7] = R[5] + R[0];  /* 0x8008D054 */
    { R[9] = R[0] + 1; goto L_8008D0A0; }  /* 0x8008D058 j */
L_8008D060:;
    R[3] = lw_(R[4] + 12);  /* 0x8008D060 */
    { uint32_t _c = (R[6] != R[3]); R[2] = ((int32_t)R[6] < (int32_t)R[3]); if (_c) { goto L_8008D088; } }  /* 0x8008D068 */
    R[2] = lb_(R[4] + 3);  /* 0x8008D070 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D0A0; } }  /* 0x8008D078 */
    { R[7] = R[5] + R[0]; goto L_8008D0A0; }  /* 0x8008D080 j */
L_8008D088:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D0A0; } }  /* 0x8008D088 */
    R[6] = R[3] + R[0];  /* 0x8008D090 */
    { R[7] = R[5] + R[0]; goto L_8008D0A0; }  /* 0x8008D094 j */
L_8008D09C:;
    sw_(R[4] + 24, R[11]);  /* 0x8008D09C */
L_8008D0A0:;
    R[5] = R[5] + 1;  /* 0x8008D0A0 */
    { uint32_t _c = (R[5] != R[10]); R[8] = R[8] + 28; if (_c) { psx_bb(); goto L_8008D034; } }  /* 0x8008D0A4 */
    { uint32_t _c = (R[9] != R[0]); R[3] = R[7] << 3; if (_c) { goto L_8008D0C0; } }  /* 0x8008D0AC */
    R[2] = 0x800Fu << 16;  /* 0x8008D0B4 */
    R[2] = R[2] - 22460;  /* 0x8008D0B8 */
    sw_(R[19] + 380, R[2]);  /* 0x8008D0BC */
L_8008D0C0:;
    R[3] = R[3] - R[7];  /* 0x8008D0C0 */
    R[3] = R[3] << 2;  /* 0x8008D0C4 */
    R[3] = R[3] + 356;  /* 0x8008D0C8 */
    R[2] = lw_(R[19] + 376);  /* 0x8008D0CC */
    R[4] = lw_(R[19] + 404);  /* 0x8008D0D0 */
    R[5] = lw_(R[19] + 460);  /* 0x8008D0D4 */
    R[2] = R[2] & R[4];  /* 0x8008D0D8 */
    R[4] = lw_(R[19] + 432);  /* 0x8008D0DC */
    R[3] = R[19] + R[3];  /* 0x8008D0E0 */
    sw_(R[19] + 352, R[3]);  /* 0x8008D0E4 */
    R[2] = R[2] & R[4];  /* 0x8008D0E8 */
    R[2] = R[2] & R[5];  /* 0x8008D0EC */
    sw_(R[19] + 468, R[2]);  /* 0x8008D0F0 */
    R[2] = lw_(R[3] + 12);  /* 0x8008D0F4 */
    R[31] = lw_(R[29] + 40);  /* 0x8008D0F8 */
    R[19] = lw_(R[29] + 36);  /* 0x8008D0FC */
    R[18] = lw_(R[29] + 32);  /* 0x8008D100 */
    R[17] = lw_(R[29] + 28);  /* 0x8008D104 */
    R[16] = lw_(R[29] + 24);  /* 0x8008D108 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8008D10C jr ra */
}

void g0_8008CFE0(void) {
    R[4] = R[18] + R[0];  /* 0x8008CFE0 */
    R[5] = R[16] + R[0];  /* 0x8008CFE4 */
    R[6] = R[17] + R[0];  /* 0x8008CFE8 */
    R[7] = R[19] + 412;  /* 0x8008CFEC */
    { R[31] = 0x8008CFF8u; sw_(R[29] + 16, R[19]); psx_next = 0x80092A7Cu; return; }  /* 0x8008CFF0 jal */
    R[5] = R[16] + R[0];  /* 0x8008CFF8 */
    R[6] = R[17] + R[0];  /* 0x8008CFFC */
    R[4] = lw_(R[19] + 484);  /* 0x8008D000 */
    R[7] = R[19] + 440;  /* 0x8008D004 */
    sw_(R[29] + 16, R[19]);  /* 0x8008D008 */
    { R[31] = 0x8008D014u; R[4] = R[18] + R[4]; psx_next = 0x80092A7Cu; return; }  /* 0x8008D00C jal */
    R[9] = R[0] + R[0];  /* 0x8008D014 */
    R[7] = R[9] + R[0];  /* 0x8008D018 */
    R[6] = R[9] + R[0];  /* 0x8008D01C */
    R[5] = R[9] + R[0];  /* 0x8008D020 */
    R[2] = 0x800Fu << 16;  /* 0x8008D024 */
    R[11] = R[2] - 22460;  /* 0x8008D028 */
    R[10] = R[0] + 4;  /* 0x8008D02C */
    R[8] = R[0] + 356;  /* 0x8008D030 */
L_8008D034:;
    R[4] = R[19] + R[8];  /* 0x8008D034 */
    R[2] = lb_(R[4] + 1);  /* 0x8008D038 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D09C; } }  /* 0x8008D040 */
    { uint32_t _c = (R[9] != R[0]); if (_c) { goto L_8008D060; } }  /* 0x8008D048 */
    R[6] = lw_(R[4] + 12);  /* 0x8008D050 */
    R[7] = R[5] + R[0];  /* 0x8008D054 */
    { R[9] = R[0] + 1; goto L_8008D0A0; }  /* 0x8008D058 j */
L_8008D060:;
    R[3] = lw_(R[4] + 12);  /* 0x8008D060 */
    { uint32_t _c = (R[6] != R[3]); R[2] = ((int32_t)R[6] < (int32_t)R[3]); if (_c) { goto L_8008D088; } }  /* 0x8008D068 */
    R[2] = lb_(R[4] + 3);  /* 0x8008D070 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D0A0; } }  /* 0x8008D078 */
    { R[7] = R[5] + R[0]; goto L_8008D0A0; }  /* 0x8008D080 j */
L_8008D088:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D0A0; } }  /* 0x8008D088 */
    R[6] = R[3] + R[0];  /* 0x8008D090 */
    { R[7] = R[5] + R[0]; goto L_8008D0A0; }  /* 0x8008D094 j */
L_8008D09C:;
    sw_(R[4] + 24, R[11]);  /* 0x8008D09C */
L_8008D0A0:;
    R[5] = R[5] + 1;  /* 0x8008D0A0 */
    { uint32_t _c = (R[5] != R[10]); R[8] = R[8] + 28; if (_c) { psx_bb(); goto L_8008D034; } }  /* 0x8008D0A4 */
    { uint32_t _c = (R[9] != R[0]); R[3] = R[7] << 3; if (_c) { goto L_8008D0C0; } }  /* 0x8008D0AC */
    R[2] = 0x800Fu << 16;  /* 0x8008D0B4 */
    R[2] = R[2] - 22460;  /* 0x8008D0B8 */
    sw_(R[19] + 380, R[2]);  /* 0x8008D0BC */
L_8008D0C0:;
    R[3] = R[3] - R[7];  /* 0x8008D0C0 */
    R[3] = R[3] << 2;  /* 0x8008D0C4 */
    R[3] = R[3] + 356;  /* 0x8008D0C8 */
    R[2] = lw_(R[19] + 376);  /* 0x8008D0CC */
    R[4] = lw_(R[19] + 404);  /* 0x8008D0D0 */
    R[5] = lw_(R[19] + 460);  /* 0x8008D0D4 */
    R[2] = R[2] & R[4];  /* 0x8008D0D8 */
    R[4] = lw_(R[19] + 432);  /* 0x8008D0DC */
    R[3] = R[19] + R[3];  /* 0x8008D0E0 */
    sw_(R[19] + 352, R[3]);  /* 0x8008D0E4 */
    R[2] = R[2] & R[4];  /* 0x8008D0E8 */
    R[2] = R[2] & R[5];  /* 0x8008D0EC */
    sw_(R[19] + 468, R[2]);  /* 0x8008D0F0 */
    R[2] = lw_(R[3] + 12);  /* 0x8008D0F4 */
    R[31] = lw_(R[29] + 40);  /* 0x8008D0F8 */
    R[19] = lw_(R[29] + 36);  /* 0x8008D0FC */
    R[18] = lw_(R[29] + 32);  /* 0x8008D100 */
    R[17] = lw_(R[29] + 28);  /* 0x8008D104 */
    R[16] = lw_(R[29] + 24);  /* 0x8008D108 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8008D10C jr ra */
}

void g0_8008CFF8(void) {
    R[5] = R[16] + R[0];  /* 0x8008CFF8 */
    R[6] = R[17] + R[0];  /* 0x8008CFFC */
    R[4] = lw_(R[19] + 484);  /* 0x8008D000 */
    R[7] = R[19] + 440;  /* 0x8008D004 */
    sw_(R[29] + 16, R[19]);  /* 0x8008D008 */
    { R[31] = 0x8008D014u; R[4] = R[18] + R[4]; psx_next = 0x80092A7Cu; return; }  /* 0x8008D00C jal */
    R[9] = R[0] + R[0];  /* 0x8008D014 */
    R[7] = R[9] + R[0];  /* 0x8008D018 */
    R[6] = R[9] + R[0];  /* 0x8008D01C */
    R[5] = R[9] + R[0];  /* 0x8008D020 */
    R[2] = 0x800Fu << 16;  /* 0x8008D024 */
    R[11] = R[2] - 22460;  /* 0x8008D028 */
    R[10] = R[0] + 4;  /* 0x8008D02C */
    R[8] = R[0] + 356;  /* 0x8008D030 */
L_8008D034:;
    R[4] = R[19] + R[8];  /* 0x8008D034 */
    R[2] = lb_(R[4] + 1);  /* 0x8008D038 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D09C; } }  /* 0x8008D040 */
    { uint32_t _c = (R[9] != R[0]); if (_c) { goto L_8008D060; } }  /* 0x8008D048 */
    R[6] = lw_(R[4] + 12);  /* 0x8008D050 */
    R[7] = R[5] + R[0];  /* 0x8008D054 */
    { R[9] = R[0] + 1; goto L_8008D0A0; }  /* 0x8008D058 j */
L_8008D060:;
    R[3] = lw_(R[4] + 12);  /* 0x8008D060 */
    { uint32_t _c = (R[6] != R[3]); R[2] = ((int32_t)R[6] < (int32_t)R[3]); if (_c) { goto L_8008D088; } }  /* 0x8008D068 */
    R[2] = lb_(R[4] + 3);  /* 0x8008D070 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D0A0; } }  /* 0x8008D078 */
    { R[7] = R[5] + R[0]; goto L_8008D0A0; }  /* 0x8008D080 j */
L_8008D088:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D0A0; } }  /* 0x8008D088 */
    R[6] = R[3] + R[0];  /* 0x8008D090 */
    { R[7] = R[5] + R[0]; goto L_8008D0A0; }  /* 0x8008D094 j */
L_8008D09C:;
    sw_(R[4] + 24, R[11]);  /* 0x8008D09C */
L_8008D0A0:;
    R[5] = R[5] + 1;  /* 0x8008D0A0 */
    { uint32_t _c = (R[5] != R[10]); R[8] = R[8] + 28; if (_c) { psx_bb(); goto L_8008D034; } }  /* 0x8008D0A4 */
    { uint32_t _c = (R[9] != R[0]); R[3] = R[7] << 3; if (_c) { goto L_8008D0C0; } }  /* 0x8008D0AC */
    R[2] = 0x800Fu << 16;  /* 0x8008D0B4 */
    R[2] = R[2] - 22460;  /* 0x8008D0B8 */
    sw_(R[19] + 380, R[2]);  /* 0x8008D0BC */
L_8008D0C0:;
    R[3] = R[3] - R[7];  /* 0x8008D0C0 */
    R[3] = R[3] << 2;  /* 0x8008D0C4 */
    R[3] = R[3] + 356;  /* 0x8008D0C8 */
    R[2] = lw_(R[19] + 376);  /* 0x8008D0CC */
    R[4] = lw_(R[19] + 404);  /* 0x8008D0D0 */
    R[5] = lw_(R[19] + 460);  /* 0x8008D0D4 */
    R[2] = R[2] & R[4];  /* 0x8008D0D8 */
    R[4] = lw_(R[19] + 432);  /* 0x8008D0DC */
    R[3] = R[19] + R[3];  /* 0x8008D0E0 */
    sw_(R[19] + 352, R[3]);  /* 0x8008D0E4 */
    R[2] = R[2] & R[4];  /* 0x8008D0E8 */
    R[2] = R[2] & R[5];  /* 0x8008D0EC */
    sw_(R[19] + 468, R[2]);  /* 0x8008D0F0 */
    R[2] = lw_(R[3] + 12);  /* 0x8008D0F4 */
    R[31] = lw_(R[29] + 40);  /* 0x8008D0F8 */
    R[19] = lw_(R[29] + 36);  /* 0x8008D0FC */
    R[18] = lw_(R[29] + 32);  /* 0x8008D100 */
    R[17] = lw_(R[29] + 28);  /* 0x8008D104 */
    R[16] = lw_(R[29] + 24);  /* 0x8008D108 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8008D10C jr ra */
}

void g0_8008D014(void) {
    R[9] = R[0] + R[0];  /* 0x8008D014 */
    R[7] = R[9] + R[0];  /* 0x8008D018 */
    R[6] = R[9] + R[0];  /* 0x8008D01C */
    R[5] = R[9] + R[0];  /* 0x8008D020 */
    R[2] = 0x800Fu << 16;  /* 0x8008D024 */
    R[11] = R[2] - 22460;  /* 0x8008D028 */
    R[10] = R[0] + 4;  /* 0x8008D02C */
    R[8] = R[0] + 356;  /* 0x8008D030 */
L_8008D034:;
    R[4] = R[19] + R[8];  /* 0x8008D034 */
    R[2] = lb_(R[4] + 1);  /* 0x8008D038 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D09C; } }  /* 0x8008D040 */
    { uint32_t _c = (R[9] != R[0]); if (_c) { goto L_8008D060; } }  /* 0x8008D048 */
    R[6] = lw_(R[4] + 12);  /* 0x8008D050 */
    R[7] = R[5] + R[0];  /* 0x8008D054 */
    { R[9] = R[0] + 1; goto L_8008D0A0; }  /* 0x8008D058 j */
L_8008D060:;
    R[3] = lw_(R[4] + 12);  /* 0x8008D060 */
    { uint32_t _c = (R[6] != R[3]); R[2] = ((int32_t)R[6] < (int32_t)R[3]); if (_c) { goto L_8008D088; } }  /* 0x8008D068 */
    R[2] = lb_(R[4] + 3);  /* 0x8008D070 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D0A0; } }  /* 0x8008D078 */
    { R[7] = R[5] + R[0]; goto L_8008D0A0; }  /* 0x8008D080 j */
L_8008D088:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D0A0; } }  /* 0x8008D088 */
    R[6] = R[3] + R[0];  /* 0x8008D090 */
    { R[7] = R[5] + R[0]; goto L_8008D0A0; }  /* 0x8008D094 j */
L_8008D09C:;
    sw_(R[4] + 24, R[11]);  /* 0x8008D09C */
L_8008D0A0:;
    R[5] = R[5] + 1;  /* 0x8008D0A0 */
    { uint32_t _c = (R[5] != R[10]); R[8] = R[8] + 28; if (_c) { psx_bb(); goto L_8008D034; } }  /* 0x8008D0A4 */
    { uint32_t _c = (R[9] != R[0]); R[3] = R[7] << 3; if (_c) { goto L_8008D0C0; } }  /* 0x8008D0AC */
    R[2] = 0x800Fu << 16;  /* 0x8008D0B4 */
    R[2] = R[2] - 22460;  /* 0x8008D0B8 */
    sw_(R[19] + 380, R[2]);  /* 0x8008D0BC */
L_8008D0C0:;
    R[3] = R[3] - R[7];  /* 0x8008D0C0 */
    R[3] = R[3] << 2;  /* 0x8008D0C4 */
    R[3] = R[3] + 356;  /* 0x8008D0C8 */
    R[2] = lw_(R[19] + 376);  /* 0x8008D0CC */
    R[4] = lw_(R[19] + 404);  /* 0x8008D0D0 */
    R[5] = lw_(R[19] + 460);  /* 0x8008D0D4 */
    R[2] = R[2] & R[4];  /* 0x8008D0D8 */
    R[4] = lw_(R[19] + 432);  /* 0x8008D0DC */
    R[3] = R[19] + R[3];  /* 0x8008D0E0 */
    sw_(R[19] + 352, R[3]);  /* 0x8008D0E4 */
    R[2] = R[2] & R[4];  /* 0x8008D0E8 */
    R[2] = R[2] & R[5];  /* 0x8008D0EC */
    sw_(R[19] + 468, R[2]);  /* 0x8008D0F0 */
    R[2] = lw_(R[3] + 12);  /* 0x8008D0F4 */
    R[31] = lw_(R[29] + 40);  /* 0x8008D0F8 */
    R[19] = lw_(R[29] + 36);  /* 0x8008D0FC */
    R[18] = lw_(R[29] + 32);  /* 0x8008D100 */
    R[17] = lw_(R[29] + 28);  /* 0x8008D104 */
    R[16] = lw_(R[29] + 24);  /* 0x8008D108 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8008D10C jr ra */
}

void g0_8008D114(void) {
    sh_(R[4] + 4, R[5]);  /* 0x8008D114 */
    R[5] = R[5] << 16;  /* 0x8008D118 */
    R[5] = (uint32_t)((int32_t)R[5] >> 16);  /* 0x8008D11C */
    R[5] = R[5] + 128;  /* 0x8008D120 */
    R[5] = R[5] & 0x1FF;  /* 0x8008D124 */
    R[5] = R[5] << 3;  /* 0x8008D128 */
    R[5] = R[0] - R[5];  /* 0x8008D12C */
    { sh_(R[4] + 50, R[5]); psx_next = R[31]; return; }  /* 0x8008D130 jr ra */
}

void g0_8008D138(void) {
    R[29] = R[29] - 40;  /* 0x8008D138 */
    sw_(R[29] + 28, R[19]);  /* 0x8008D13C */
    R[19] = R[4] + R[0];  /* 0x8008D140 */
    sw_(R[29] + 36, R[31]);  /* 0x8008D144 */
    sw_(R[29] + 32, R[20]);  /* 0x8008D148 */
    sw_(R[29] + 24, R[18]);  /* 0x8008D14C */
    sw_(R[29] + 20, R[17]);  /* 0x8008D150 */
    sw_(R[29] + 16, R[16]);  /* 0x8008D154 */
    R[17] = lw_(R[19] + 16);  /* 0x8008D158 */
    { uint32_t _c = (R[17] == R[0]); R[16] = R[0] + R[0]; if (_c) { goto L_8008D284; } }  /* 0x8008D160 */
    R[2] = 0x800Fu << 16;  /* 0x8008D168 */
    R[20] = R[2] - 22848;  /* 0x8008D16C */
    R[18] = 0x1u << 16;  /* 0x8008D170 */
    R[2] = R[16] << 2;  /* 0x8008D174 */
L_8008D178:;
    R[2] = R[19] + R[2];  /* 0x8008D178 */
    R[4] = lw_(R[2] + 20);  /* 0x8008D17C */
    R[2] = lb_(R[4] + 782);  /* 0x8008D184 */
    R[2] = R[2] << 1;  /* 0x8008D18C */
    R[2] = R[2] + R[20];  /* 0x8008D190 */
    R[5] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x8008D194 */
    R[7] = lh_(R[2]);  /* 0x8008D198 */
    { uint32_t _c = ((int32_t)R[5] >= 0); if (_c) { goto L_8008D1D0; } }  /* 0x8008D19C */
    R[7] = lh_(R[4] + 664);  /* 0x8008D1A4 */
    R[2] = lh_(R[4] + 8);  /* 0x8008D1A8 */
    R[3] = lw_(R[4] + 16);  /* 0x8008D1AC */
    R[2] = R[2] + R[7];  /* 0x8008D1B0 */
    R[2] = R[2] & 0x1FF;  /* 0x8008D1B4 */
    R[3] = R[3] & R[18];  /* 0x8008D1B8 */
    sh_(R[4] + 8, R[2]);  /* 0x8008D1BC */
    { uint32_t _c = (R[3] != R[0]); sh_(R[4] + 6, R[2]); if (_c) { goto L_8008D278; } }  /* 0x8008D1C0 */
    { goto L_8008D258; }  /* 0x8008D1C8 j */
L_8008D1D0:;
    { uint32_t _c = (R[5] == R[0]); if (_c) { goto L_8008D26C; } }  /* 0x8008D1D0 */
    R[8] = lh_(R[4] + 6);  /* 0x8008D1D8 */
    R[6] = lh_(R[4] + 8);  /* 0x8008D1DC */
    R[2] = R[8] - R[6];  /* 0x8008D1E4 */
    R[3] = R[2] & 0x1FF;  /* 0x8008D1E8 */
    R[2] = ((int32_t)R[3] < 256);  /* 0x8008D1EC */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < (int32_t)R[5]); if (_c) { goto L_8008D208; } }  /* 0x8008D1F0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[6] + R[7]; if (_c) { goto L_8008D21C; } }  /* 0x8008D1F8 */
    { R[2] = R[2] & 0x1FF; goto L_8008D228; }  /* 0x8008D200 j */
L_8008D208:;
    R[2] = R[0] + 512;  /* 0x8008D208 */
    R[2] = R[2] - R[5];  /* 0x8008D20C */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8008D210 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[6] - R[7]; if (_c) { goto L_8008D224; } }  /* 0x8008D214 */
L_8008D21C:;
    { sh_(R[4] + 8, R[8]); goto L_8008D22C; }  /* 0x8008D21C j */
L_8008D224:;
    R[2] = R[2] & 0x1FF;  /* 0x8008D224 */
L_8008D228:;
    sh_(R[4] + 8, R[2]);  /* 0x8008D228 */
L_8008D22C:;
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 8);  /* 0x8008D22C */
    R[2] = R[8] << 16;  /* 0x8008D230 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008D234 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8008D244; } }  /* 0x8008D238 */
    sb_(R[4] + 782, R[0]);  /* 0x8008D240 */
L_8008D244:;
    R[2] = lw_(R[4] + 16);  /* 0x8008D244 */
    R[2] = R[2] & R[18];  /* 0x8008D24C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008D278; } }  /* 0x8008D250 */
L_8008D258:;
    R[5] = (uint32_t)(int16_t)lh_(R[4] + 8);  /* 0x8008D258 */
    { R[31] = 0x8008D264u; R[16] = R[16] + 1; psx_next = 0x8008D114u; return; }  /* 0x8008D25C jal */
    { goto L_8008D27C; }  /* 0x8008D264 j */
L_8008D26C:;
    R[2] = lh_(R[4] + 6);  /* 0x8008D26C */
    sh_(R[4] + 8, R[2]);  /* 0x8008D274 */
L_8008D278:;
    R[16] = R[16] + 1;  /* 0x8008D278 */
L_8008D27C:;
    { uint32_t _c = (R[16] != R[17]); R[2] = R[16] << 2; if (_c) { psx_bb(); goto L_8008D178; } }  /* 0x8008D27C */
L_8008D284:;
    R[31] = lw_(R[29] + 36);  /* 0x8008D284 */
    R[20] = lw_(R[29] + 32);  /* 0x8008D288 */
    R[19] = lw_(R[29] + 28);  /* 0x8008D28C */
    R[18] = lw_(R[29] + 24);  /* 0x8008D290 */
    R[17] = lw_(R[29] + 20);  /* 0x8008D294 */
    R[16] = lw_(R[29] + 16);  /* 0x8008D298 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8008D29C jr ra */
}

void g0_8008D178(void) {
L_8008D178:;
    R[2] = R[19] + R[2];  /* 0x8008D178 */
    R[4] = lw_(R[2] + 20);  /* 0x8008D17C */
    R[2] = lb_(R[4] + 782);  /* 0x8008D184 */
    R[2] = R[2] << 1;  /* 0x8008D18C */
    R[2] = R[2] + R[20];  /* 0x8008D190 */
    R[5] = (uint32_t)(int16_t)lh_(R[2]);  /* 0x8008D194 */
    R[7] = lh_(R[2]);  /* 0x8008D198 */
    { uint32_t _c = ((int32_t)R[5] >= 0); if (_c) { goto L_8008D1D0; } }  /* 0x8008D19C */
    R[7] = lh_(R[4] + 664);  /* 0x8008D1A4 */
    R[2] = lh_(R[4] + 8);  /* 0x8008D1A8 */
    R[3] = lw_(R[4] + 16);  /* 0x8008D1AC */
    R[2] = R[2] + R[7];  /* 0x8008D1B0 */
    R[2] = R[2] & 0x1FF;  /* 0x8008D1B4 */
    R[3] = R[3] & R[18];  /* 0x8008D1B8 */
    sh_(R[4] + 8, R[2]);  /* 0x8008D1BC */
    { uint32_t _c = (R[3] != R[0]); sh_(R[4] + 6, R[2]); if (_c) { goto L_8008D278; } }  /* 0x8008D1C0 */
    { goto L_8008D258; }  /* 0x8008D1C8 j */
L_8008D1D0:;
    { uint32_t _c = (R[5] == R[0]); if (_c) { goto L_8008D26C; } }  /* 0x8008D1D0 */
    R[8] = lh_(R[4] + 6);  /* 0x8008D1D8 */
    R[6] = lh_(R[4] + 8);  /* 0x8008D1DC */
    R[2] = R[8] - R[6];  /* 0x8008D1E4 */
    R[3] = R[2] & 0x1FF;  /* 0x8008D1E8 */
    R[2] = ((int32_t)R[3] < 256);  /* 0x8008D1EC */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[3] < (int32_t)R[5]); if (_c) { goto L_8008D208; } }  /* 0x8008D1F0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[6] + R[7]; if (_c) { goto L_8008D21C; } }  /* 0x8008D1F8 */
    { R[2] = R[2] & 0x1FF; goto L_8008D228; }  /* 0x8008D200 j */
L_8008D208:;
    R[2] = R[0] + 512;  /* 0x8008D208 */
    R[2] = R[2] - R[5];  /* 0x8008D20C */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8008D210 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[6] - R[7]; if (_c) { goto L_8008D224; } }  /* 0x8008D214 */
L_8008D21C:;
    { sh_(R[4] + 8, R[8]); goto L_8008D22C; }  /* 0x8008D21C j */
L_8008D224:;
    R[2] = R[2] & 0x1FF;  /* 0x8008D224 */
L_8008D228:;
    sh_(R[4] + 8, R[2]);  /* 0x8008D228 */
L_8008D22C:;
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 8);  /* 0x8008D22C */
    R[2] = R[8] << 16;  /* 0x8008D230 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8008D234 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8008D244; } }  /* 0x8008D238 */
    sb_(R[4] + 782, R[0]);  /* 0x8008D240 */
L_8008D244:;
    R[2] = lw_(R[4] + 16);  /* 0x8008D244 */
    R[2] = R[2] & R[18];  /* 0x8008D24C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008D278; } }  /* 0x8008D250 */
L_8008D258:;
    R[5] = (uint32_t)(int16_t)lh_(R[4] + 8);  /* 0x8008D258 */
    { R[31] = 0x8008D264u; R[16] = R[16] + 1; psx_next = 0x8008D114u; return; }  /* 0x8008D25C jal */
    { goto L_8008D27C; }  /* 0x8008D264 j */
L_8008D26C:;
    R[2] = lh_(R[4] + 6);  /* 0x8008D26C */
    sh_(R[4] + 8, R[2]);  /* 0x8008D274 */
L_8008D278:;
    R[16] = R[16] + 1;  /* 0x8008D278 */
L_8008D27C:;
    { uint32_t _c = (R[16] != R[17]); R[2] = R[16] << 2; if (_c) { psx_bb(); goto L_8008D178; } }  /* 0x8008D27C */
    R[31] = lw_(R[29] + 36);  /* 0x8008D284 */
    R[20] = lw_(R[29] + 32);  /* 0x8008D288 */
    R[19] = lw_(R[29] + 28);  /* 0x8008D28C */
    R[18] = lw_(R[29] + 24);  /* 0x8008D290 */
    R[17] = lw_(R[29] + 20);  /* 0x8008D294 */
    R[16] = lw_(R[29] + 16);  /* 0x8008D298 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8008D29C jr ra */
}

void g0_8008D264(void) {
    { goto L_8008D27C; }  /* 0x8008D264 j */
    R[2] = lh_(R[4] + 6);  /* 0x8008D26C */
    sh_(R[4] + 8, R[2]);  /* 0x8008D274 */
    R[16] = R[16] + 1;  /* 0x8008D278 */
L_8008D27C:;
    { uint32_t _c = (R[16] != R[17]); R[2] = R[16] << 2; if (_c) { psx_next = 0x8008D178u; return; } }  /* 0x8008D27C b extern */
    R[31] = lw_(R[29] + 36);  /* 0x8008D284 */
    R[20] = lw_(R[29] + 32);  /* 0x8008D288 */
    R[19] = lw_(R[29] + 28);  /* 0x8008D28C */
    R[18] = lw_(R[29] + 24);  /* 0x8008D290 */
    R[17] = lw_(R[29] + 20);  /* 0x8008D294 */
    R[16] = lw_(R[29] + 16);  /* 0x8008D298 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8008D29C jr ra */
}

void g0_8008D2A4(void) {
#ifdef A2_NATIVE_ACTOR_SNAPSHOT
    /* actor snapshot 8008D2A4 */
    if (a2_native_actor_snapshot_enabled) {
        a2_native_actor_snapshot_entity_update(R[4]);
    }
#endif
    R[29] = R[29] - 32;  /* 0x8008D2A4 */
    sw_(R[29] + 24, R[18]);  /* 0x8008D2A8 */
    R[18] = R[4] + R[0];  /* 0x8008D2AC */
    sw_(R[29] + 28, R[31]);  /* 0x8008D2B0 */
    sw_(R[29] + 20, R[17]);  /* 0x8008D2B4 */
    { R[31] = 0x8008D2C0u; sw_(R[29] + 16, R[16]); psx_next = 0x800A0BF8u; return; }  /* 0x8008D2B8 jal */
    R[5] = lw_(R[18] + 68);  /* 0x8008D2C0 */
    R[16] = R[0] + R[0];  /* 0x8008D2C4 */
    { uint32_t _c = (R[5] == R[0]); sh_(R[18] + 76, R[0]); if (_c) { goto L_8008D3DC; } }  /* 0x8008D2C8 */
    R[4] = (uint32_t)(int16_t)lh_(R[18] + 20);  /* 0x8008D2D0 */
    { R[31] = 0x8008D2DCu; psx_next = 0x80025C00u; return; }  /* 0x8008D2D4 jal */
    R[6] = (uint32_t)(int16_t)lh_(R[18] + 22);  /* 0x8008D2DC */
    R[5] = (uint32_t)(int16_t)lh_(R[18] + 20);  /* 0x8008D2E0 */
    R[7] = R[2] + R[0];  /* 0x8008D2E4 */
    { uint32_t _c = (R[6] == R[5]); sh_(R[18] + 88, R[7]); if (_c) { goto L_8008D32C; } }  /* 0x8008D2E8 */
    R[7] = R[7] & 0x8000;  /* 0x8008D2F0 */
    R[4] = lw_(R[18] + 72);  /* 0x8008D2F4 */
    R[6] = lw_(R[18] + 68);  /* 0x8008D2F8 */
    { R[31] = 0x8008D304u; R[16] = R[0] + 1; psx_next = 0x80025A68u; return; }  /* 0x8008D2FC jal */
    R[4] = lw_(R[18] + 72);  /* 0x8008D304 */
    { R[31] = 0x8008D310u; R[5] = R[18] + 76; psx_next = 0x80025DF4u; return; }  /* 0x8008D308 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[18] + 216);  /* 0x8008D310 */
    R[3] = lh_(R[18] + 216);  /* 0x8008D314 */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[2] = R[3] - 1; if (_c) { goto L_8008D324; } }  /* 0x8008D318 */
    sh_(R[18] + 216, R[2]);  /* 0x8008D320 */
L_8008D324:;
    { sb_(R[18] + 800, R[0]); goto L_8008D3DC; }  /* 0x8008D324 j */
L_8008D32C:;
    R[2] = 0x8012u << 16;  /* 0x8008D32C */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 24008);  /* 0x8008D330 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] - 1; if (_c) { goto L_8008D3DC; } }  /* 0x8008D338 */
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 216);  /* 0x8008D340 */
    R[2] = lh_(R[18] + 216);  /* 0x8008D344 */
    { uint32_t _c = (R[3] == R[5]); if (_c) { goto L_8008D3DC; } }  /* 0x8008D348 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[2] + R[5]; if (_c) { goto L_8008D360; } }  /* 0x8008D350 */
    { sh_(R[18] + 216, R[2]); goto L_8008D3DC; }  /* 0x8008D358 j */
L_8008D360:;
    R[2] = lb_(R[18] + 800);  /* 0x8008D360 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D3C0; } }  /* 0x8008D368 */
    R[4] = lw_(R[18] + 72);  /* 0x8008D370 */
    R[17] = (uint32_t)(int16_t)lh_(R[4] + 4);  /* 0x8008D378 */
    R[17] = R[17] - 1;  /* 0x8008D380 */
    { uint32_t _c = (R[17] == R[5]); R[5] = R[6] + R[0]; if (_c) { goto L_8008D3D0; } }  /* 0x8008D384 */
    R[6] = lw_(R[18] + 68);  /* 0x8008D38C */
    R[7] = R[7] & 0x8000;  /* 0x8008D390 */
    { R[31] = 0x8008D39Cu; R[16] = R[0] + R[0]; psx_next = 0x80025A68u; return; }  /* 0x8008D394 jal */
    { uint32_t _c = (R[17] == R[0]); if (_c) { goto L_8008D3CC; } }  /* 0x8008D39C */
L_8008D3A4:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3A4 */
    { R[31] = 0x8008D3B0u; R[16] = R[16] + 1; psx_next = 0x80025EFCu; return; }  /* 0x8008D3A8 jal */
    { uint32_t _c = (R[16] == R[17]); if (_c) { goto L_8008D3CC; } }  /* 0x8008D3B0 */
    { psx_bb(); goto L_8008D3A4; }  /* 0x8008D3B8 j */
L_8008D3C0:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3C0 */
    { R[31] = 0x8008D3CCu; psx_next = 0x80025EFCu; return; }  /* 0x8008D3C4 jal */
L_8008D3CC:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3CC */
L_8008D3D0:;
    R[5] = R[18] + 76;  /* 0x8008D3D0 */
    { R[31] = 0x8008D3DCu; R[16] = R[0] + 1; psx_next = 0x80025DF4u; return; }  /* 0x8008D3D4 jal */
L_8008D3DC:;
    R[4] = (uint32_t)(int16_t)lh_(R[18] + 76);  /* 0x8008D3DC */
    { uint32_t _c = (R[4] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3E4 b extern */
    { uint32_t _c = (R[16] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3EC b extern */
    { uint32_t _c = ((int32_t)R[4] < 0); if (_c) { psx_next = 0x8008D410u; return; } }  /* 0x8008D3F4 b extern */
    psx_next = 0x8008D3FCu; return;  /* fallthrough */
}

void g0_8008D2C0(void) {
    R[5] = lw_(R[18] + 68);  /* 0x8008D2C0 */
    R[16] = R[0] + R[0];  /* 0x8008D2C4 */
    { uint32_t _c = (R[5] == R[0]); sh_(R[18] + 76, R[0]); if (_c) { goto L_8008D3DC; } }  /* 0x8008D2C8 */
    R[4] = (uint32_t)(int16_t)lh_(R[18] + 20);  /* 0x8008D2D0 */
    { R[31] = 0x8008D2DCu; psx_next = 0x80025C00u; return; }  /* 0x8008D2D4 jal */
    R[6] = (uint32_t)(int16_t)lh_(R[18] + 22);  /* 0x8008D2DC */
    R[5] = (uint32_t)(int16_t)lh_(R[18] + 20);  /* 0x8008D2E0 */
    R[7] = R[2] + R[0];  /* 0x8008D2E4 */
    { uint32_t _c = (R[6] == R[5]); sh_(R[18] + 88, R[7]); if (_c) { goto L_8008D32C; } }  /* 0x8008D2E8 */
    R[7] = R[7] & 0x8000;  /* 0x8008D2F0 */
    R[4] = lw_(R[18] + 72);  /* 0x8008D2F4 */
    R[6] = lw_(R[18] + 68);  /* 0x8008D2F8 */
    { R[31] = 0x8008D304u; R[16] = R[0] + 1; psx_next = 0x80025A68u; return; }  /* 0x8008D2FC jal */
    R[4] = lw_(R[18] + 72);  /* 0x8008D304 */
    { R[31] = 0x8008D310u; R[5] = R[18] + 76; psx_next = 0x80025DF4u; return; }  /* 0x8008D308 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[18] + 216);  /* 0x8008D310 */
    R[3] = lh_(R[18] + 216);  /* 0x8008D314 */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[2] = R[3] - 1; if (_c) { goto L_8008D324; } }  /* 0x8008D318 */
    sh_(R[18] + 216, R[2]);  /* 0x8008D320 */
L_8008D324:;
    { sb_(R[18] + 800, R[0]); goto L_8008D3DC; }  /* 0x8008D324 j */
L_8008D32C:;
    R[2] = 0x8012u << 16;  /* 0x8008D32C */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 24008);  /* 0x8008D330 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] - 1; if (_c) { goto L_8008D3DC; } }  /* 0x8008D338 */
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 216);  /* 0x8008D340 */
    R[2] = lh_(R[18] + 216);  /* 0x8008D344 */
    { uint32_t _c = (R[3] == R[5]); if (_c) { goto L_8008D3DC; } }  /* 0x8008D348 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[2] + R[5]; if (_c) { goto L_8008D360; } }  /* 0x8008D350 */
    { sh_(R[18] + 216, R[2]); goto L_8008D3DC; }  /* 0x8008D358 j */
L_8008D360:;
    R[2] = lb_(R[18] + 800);  /* 0x8008D360 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D3C0; } }  /* 0x8008D368 */
    R[4] = lw_(R[18] + 72);  /* 0x8008D370 */
    R[17] = (uint32_t)(int16_t)lh_(R[4] + 4);  /* 0x8008D378 */
    R[17] = R[17] - 1;  /* 0x8008D380 */
    { uint32_t _c = (R[17] == R[5]); R[5] = R[6] + R[0]; if (_c) { goto L_8008D3D0; } }  /* 0x8008D384 */
    R[6] = lw_(R[18] + 68);  /* 0x8008D38C */
    R[7] = R[7] & 0x8000;  /* 0x8008D390 */
    { R[31] = 0x8008D39Cu; R[16] = R[0] + R[0]; psx_next = 0x80025A68u; return; }  /* 0x8008D394 jal */
    { uint32_t _c = (R[17] == R[0]); if (_c) { goto L_8008D3CC; } }  /* 0x8008D39C */
L_8008D3A4:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3A4 */
    { R[31] = 0x8008D3B0u; R[16] = R[16] + 1; psx_next = 0x80025EFCu; return; }  /* 0x8008D3A8 jal */
    { uint32_t _c = (R[16] == R[17]); if (_c) { goto L_8008D3CC; } }  /* 0x8008D3B0 */
    { psx_bb(); goto L_8008D3A4; }  /* 0x8008D3B8 j */
L_8008D3C0:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3C0 */
    { R[31] = 0x8008D3CCu; psx_next = 0x80025EFCu; return; }  /* 0x8008D3C4 jal */
L_8008D3CC:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3CC */
L_8008D3D0:;
    R[5] = R[18] + 76;  /* 0x8008D3D0 */
    { R[31] = 0x8008D3DCu; R[16] = R[0] + 1; psx_next = 0x80025DF4u; return; }  /* 0x8008D3D4 jal */
L_8008D3DC:;
    R[4] = (uint32_t)(int16_t)lh_(R[18] + 76);  /* 0x8008D3DC */
    { uint32_t _c = (R[4] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3E4 b extern */
    { uint32_t _c = (R[16] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3EC b extern */
    { uint32_t _c = ((int32_t)R[4] < 0); if (_c) { psx_next = 0x8008D410u; return; } }  /* 0x8008D3F4 b extern */
    psx_next = 0x8008D3FCu; return;  /* fallthrough */
}

void g0_8008D2DC(void) {
    R[6] = (uint32_t)(int16_t)lh_(R[18] + 22);  /* 0x8008D2DC */
    R[5] = (uint32_t)(int16_t)lh_(R[18] + 20);  /* 0x8008D2E0 */
    R[7] = R[2] + R[0];  /* 0x8008D2E4 */
    { uint32_t _c = (R[6] == R[5]); sh_(R[18] + 88, R[7]); if (_c) { goto L_8008D32C; } }  /* 0x8008D2E8 */
    R[7] = R[7] & 0x8000;  /* 0x8008D2F0 */
    R[4] = lw_(R[18] + 72);  /* 0x8008D2F4 */
    R[6] = lw_(R[18] + 68);  /* 0x8008D2F8 */
    { R[31] = 0x8008D304u; R[16] = R[0] + 1; psx_next = 0x80025A68u; return; }  /* 0x8008D2FC jal */
    R[4] = lw_(R[18] + 72);  /* 0x8008D304 */
    { R[31] = 0x8008D310u; R[5] = R[18] + 76; psx_next = 0x80025DF4u; return; }  /* 0x8008D308 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[18] + 216);  /* 0x8008D310 */
    R[3] = lh_(R[18] + 216);  /* 0x8008D314 */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[2] = R[3] - 1; if (_c) { goto L_8008D324; } }  /* 0x8008D318 */
    sh_(R[18] + 216, R[2]);  /* 0x8008D320 */
L_8008D324:;
    { sb_(R[18] + 800, R[0]); goto L_8008D3DC; }  /* 0x8008D324 j */
L_8008D32C:;
    R[2] = 0x8012u << 16;  /* 0x8008D32C */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 24008);  /* 0x8008D330 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] - 1; if (_c) { goto L_8008D3DC; } }  /* 0x8008D338 */
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 216);  /* 0x8008D340 */
    R[2] = lh_(R[18] + 216);  /* 0x8008D344 */
    { uint32_t _c = (R[3] == R[5]); if (_c) { goto L_8008D3DC; } }  /* 0x8008D348 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[2] + R[5]; if (_c) { goto L_8008D360; } }  /* 0x8008D350 */
    { sh_(R[18] + 216, R[2]); goto L_8008D3DC; }  /* 0x8008D358 j */
L_8008D360:;
    R[2] = lb_(R[18] + 800);  /* 0x8008D360 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D3C0; } }  /* 0x8008D368 */
    R[4] = lw_(R[18] + 72);  /* 0x8008D370 */
    R[17] = (uint32_t)(int16_t)lh_(R[4] + 4);  /* 0x8008D378 */
    R[17] = R[17] - 1;  /* 0x8008D380 */
    { uint32_t _c = (R[17] == R[5]); R[5] = R[6] + R[0]; if (_c) { goto L_8008D3D0; } }  /* 0x8008D384 */
    R[6] = lw_(R[18] + 68);  /* 0x8008D38C */
    R[7] = R[7] & 0x8000;  /* 0x8008D390 */
    { R[31] = 0x8008D39Cu; R[16] = R[0] + R[0]; psx_next = 0x80025A68u; return; }  /* 0x8008D394 jal */
    { uint32_t _c = (R[17] == R[0]); if (_c) { goto L_8008D3CC; } }  /* 0x8008D39C */
L_8008D3A4:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3A4 */
    { R[31] = 0x8008D3B0u; R[16] = R[16] + 1; psx_next = 0x80025EFCu; return; }  /* 0x8008D3A8 jal */
    { uint32_t _c = (R[16] == R[17]); if (_c) { goto L_8008D3CC; } }  /* 0x8008D3B0 */
    { psx_bb(); goto L_8008D3A4; }  /* 0x8008D3B8 j */
L_8008D3C0:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3C0 */
    { R[31] = 0x8008D3CCu; psx_next = 0x80025EFCu; return; }  /* 0x8008D3C4 jal */
L_8008D3CC:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3CC */
L_8008D3D0:;
    R[5] = R[18] + 76;  /* 0x8008D3D0 */
    { R[31] = 0x8008D3DCu; R[16] = R[0] + 1; psx_next = 0x80025DF4u; return; }  /* 0x8008D3D4 jal */
L_8008D3DC:;
    R[4] = (uint32_t)(int16_t)lh_(R[18] + 76);  /* 0x8008D3DC */
    { uint32_t _c = (R[4] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3E4 b extern */
    { uint32_t _c = (R[16] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3EC b extern */
    { uint32_t _c = ((int32_t)R[4] < 0); if (_c) { psx_next = 0x8008D410u; return; } }  /* 0x8008D3F4 b extern */
    psx_next = 0x8008D3FCu; return;  /* fallthrough */
}

void g0_8008D304(void) {
    R[4] = lw_(R[18] + 72);  /* 0x8008D304 */
    { R[31] = 0x8008D310u; R[5] = R[18] + 76; psx_next = 0x80025DF4u; return; }  /* 0x8008D308 jal */
    R[2] = (uint32_t)(int16_t)lh_(R[18] + 216);  /* 0x8008D310 */
    R[3] = lh_(R[18] + 216);  /* 0x8008D314 */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[2] = R[3] - 1; if (_c) { goto L_8008D324; } }  /* 0x8008D318 */
    sh_(R[18] + 216, R[2]);  /* 0x8008D320 */
L_8008D324:;
    { sb_(R[18] + 800, R[0]); goto L_8008D3DC; }  /* 0x8008D324 j */
    R[2] = 0x8012u << 16;  /* 0x8008D32C */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 24008);  /* 0x8008D330 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] - 1; if (_c) { goto L_8008D3DC; } }  /* 0x8008D338 */
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 216);  /* 0x8008D340 */
    R[2] = lh_(R[18] + 216);  /* 0x8008D344 */
    { uint32_t _c = (R[3] == R[5]); if (_c) { goto L_8008D3DC; } }  /* 0x8008D348 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[2] + R[5]; if (_c) { goto L_8008D360; } }  /* 0x8008D350 */
    { sh_(R[18] + 216, R[2]); goto L_8008D3DC; }  /* 0x8008D358 j */
L_8008D360:;
    R[2] = lb_(R[18] + 800);  /* 0x8008D360 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D3C0; } }  /* 0x8008D368 */
    R[4] = lw_(R[18] + 72);  /* 0x8008D370 */
    R[17] = (uint32_t)(int16_t)lh_(R[4] + 4);  /* 0x8008D378 */
    R[17] = R[17] - 1;  /* 0x8008D380 */
    { uint32_t _c = (R[17] == R[5]); R[5] = R[6] + R[0]; if (_c) { goto L_8008D3D0; } }  /* 0x8008D384 */
    R[6] = lw_(R[18] + 68);  /* 0x8008D38C */
    R[7] = R[7] & 0x8000;  /* 0x8008D390 */
    { R[31] = 0x8008D39Cu; R[16] = R[0] + R[0]; psx_next = 0x80025A68u; return; }  /* 0x8008D394 jal */
    { uint32_t _c = (R[17] == R[0]); if (_c) { goto L_8008D3CC; } }  /* 0x8008D39C */
L_8008D3A4:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3A4 */
    { R[31] = 0x8008D3B0u; R[16] = R[16] + 1; psx_next = 0x80025EFCu; return; }  /* 0x8008D3A8 jal */
    { uint32_t _c = (R[16] == R[17]); if (_c) { goto L_8008D3CC; } }  /* 0x8008D3B0 */
    { psx_bb(); goto L_8008D3A4; }  /* 0x8008D3B8 j */
L_8008D3C0:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3C0 */
    { R[31] = 0x8008D3CCu; psx_next = 0x80025EFCu; return; }  /* 0x8008D3C4 jal */
L_8008D3CC:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3CC */
L_8008D3D0:;
    R[5] = R[18] + 76;  /* 0x8008D3D0 */
    { R[31] = 0x8008D3DCu; R[16] = R[0] + 1; psx_next = 0x80025DF4u; return; }  /* 0x8008D3D4 jal */
L_8008D3DC:;
    R[4] = (uint32_t)(int16_t)lh_(R[18] + 76);  /* 0x8008D3DC */
    { uint32_t _c = (R[4] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3E4 b extern */
    { uint32_t _c = (R[16] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3EC b extern */
    { uint32_t _c = ((int32_t)R[4] < 0); if (_c) { psx_next = 0x8008D410u; return; } }  /* 0x8008D3F4 b extern */
    psx_next = 0x8008D3FCu; return;  /* fallthrough */
}

void g0_8008D310(void) {
    R[2] = (uint32_t)(int16_t)lh_(R[18] + 216);  /* 0x8008D310 */
    R[3] = lh_(R[18] + 216);  /* 0x8008D314 */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[2] = R[3] - 1; if (_c) { goto L_8008D324; } }  /* 0x8008D318 */
    sh_(R[18] + 216, R[2]);  /* 0x8008D320 */
L_8008D324:;
    { sb_(R[18] + 800, R[0]); goto L_8008D3DC; }  /* 0x8008D324 j */
    R[2] = 0x8012u << 16;  /* 0x8008D32C */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 24008);  /* 0x8008D330 */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] - 1; if (_c) { goto L_8008D3DC; } }  /* 0x8008D338 */
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 216);  /* 0x8008D340 */
    R[2] = lh_(R[18] + 216);  /* 0x8008D344 */
    { uint32_t _c = (R[3] == R[5]); if (_c) { goto L_8008D3DC; } }  /* 0x8008D348 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[2] + R[5]; if (_c) { goto L_8008D360; } }  /* 0x8008D350 */
    { sh_(R[18] + 216, R[2]); goto L_8008D3DC; }  /* 0x8008D358 j */
L_8008D360:;
    R[2] = lb_(R[18] + 800);  /* 0x8008D360 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D3C0; } }  /* 0x8008D368 */
    R[4] = lw_(R[18] + 72);  /* 0x8008D370 */
    R[17] = (uint32_t)(int16_t)lh_(R[4] + 4);  /* 0x8008D378 */
    R[17] = R[17] - 1;  /* 0x8008D380 */
    { uint32_t _c = (R[17] == R[5]); R[5] = R[6] + R[0]; if (_c) { goto L_8008D3D0; } }  /* 0x8008D384 */
    R[6] = lw_(R[18] + 68);  /* 0x8008D38C */
    R[7] = R[7] & 0x8000;  /* 0x8008D390 */
    { R[31] = 0x8008D39Cu; R[16] = R[0] + R[0]; psx_next = 0x80025A68u; return; }  /* 0x8008D394 jal */
    { uint32_t _c = (R[17] == R[0]); if (_c) { goto L_8008D3CC; } }  /* 0x8008D39C */
L_8008D3A4:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3A4 */
    { R[31] = 0x8008D3B0u; R[16] = R[16] + 1; psx_next = 0x80025EFCu; return; }  /* 0x8008D3A8 jal */
    { uint32_t _c = (R[16] == R[17]); if (_c) { goto L_8008D3CC; } }  /* 0x8008D3B0 */
    { psx_bb(); goto L_8008D3A4; }  /* 0x8008D3B8 j */
L_8008D3C0:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3C0 */
    { R[31] = 0x8008D3CCu; psx_next = 0x80025EFCu; return; }  /* 0x8008D3C4 jal */
L_8008D3CC:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3CC */
L_8008D3D0:;
    R[5] = R[18] + 76;  /* 0x8008D3D0 */
    { R[31] = 0x8008D3DCu; R[16] = R[0] + 1; psx_next = 0x80025DF4u; return; }  /* 0x8008D3D4 jal */
L_8008D3DC:;
    R[4] = (uint32_t)(int16_t)lh_(R[18] + 76);  /* 0x8008D3DC */
    { uint32_t _c = (R[4] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3E4 b extern */
    { uint32_t _c = (R[16] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3EC b extern */
    { uint32_t _c = ((int32_t)R[4] < 0); if (_c) { psx_next = 0x8008D410u; return; } }  /* 0x8008D3F4 b extern */
    psx_next = 0x8008D3FCu; return;  /* fallthrough */
}

void g0_8008D39C(void) {
    { uint32_t _c = (R[17] == R[0]); if (_c) { goto L_8008D3CC; } }  /* 0x8008D39C */
L_8008D3A4:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3A4 */
    { R[31] = 0x8008D3B0u; R[16] = R[16] + 1; psx_next = 0x80025EFCu; return; }  /* 0x8008D3A8 jal */
    { uint32_t _c = (R[16] == R[17]); if (_c) { goto L_8008D3CC; } }  /* 0x8008D3B0 */
    { psx_bb(); goto L_8008D3A4; }  /* 0x8008D3B8 j */
    R[4] = lw_(R[18] + 72);  /* 0x8008D3C0 */
    { R[31] = 0x8008D3CCu; psx_next = 0x80025EFCu; return; }  /* 0x8008D3C4 jal */
L_8008D3CC:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3CC */
    R[5] = R[18] + 76;  /* 0x8008D3D0 */
    { R[31] = 0x8008D3DCu; R[16] = R[0] + 1; psx_next = 0x80025DF4u; return; }  /* 0x8008D3D4 jal */
    R[4] = (uint32_t)(int16_t)lh_(R[18] + 76);  /* 0x8008D3DC */
    { uint32_t _c = (R[4] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3E4 b extern */
    { uint32_t _c = (R[16] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3EC b extern */
    { uint32_t _c = ((int32_t)R[4] < 0); if (_c) { psx_next = 0x8008D410u; return; } }  /* 0x8008D3F4 b extern */
    psx_next = 0x8008D3FCu; return;  /* fallthrough */
}

void g0_8008D3A4(void) {
L_8008D3A4:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3A4 */
    { R[31] = 0x8008D3B0u; R[16] = R[16] + 1; psx_next = 0x80025EFCu; return; }  /* 0x8008D3A8 jal */
    { uint32_t _c = (R[16] == R[17]); if (_c) { goto L_8008D3CC; } }  /* 0x8008D3B0 */
    { psx_bb(); goto L_8008D3A4; }  /* 0x8008D3B8 j */
    R[4] = lw_(R[18] + 72);  /* 0x8008D3C0 */
    { R[31] = 0x8008D3CCu; psx_next = 0x80025EFCu; return; }  /* 0x8008D3C4 jal */
L_8008D3CC:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3CC */
    R[5] = R[18] + 76;  /* 0x8008D3D0 */
    { R[31] = 0x8008D3DCu; R[16] = R[0] + 1; psx_next = 0x80025DF4u; return; }  /* 0x8008D3D4 jal */
    R[4] = (uint32_t)(int16_t)lh_(R[18] + 76);  /* 0x8008D3DC */
    { uint32_t _c = (R[4] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3E4 b extern */
    { uint32_t _c = (R[16] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3EC b extern */
    { uint32_t _c = ((int32_t)R[4] < 0); if (_c) { psx_next = 0x8008D410u; return; } }  /* 0x8008D3F4 b extern */
    psx_next = 0x8008D3FCu; return;  /* fallthrough */
}

void g0_8008D3B0(void) {
    { uint32_t _c = (R[16] == R[17]); if (_c) { goto L_8008D3CC; } }  /* 0x8008D3B0 */
    { psx_next = 0x8008D3A4u; return; }  /* 0x8008D3B8 j extern */
    R[4] = lw_(R[18] + 72);  /* 0x8008D3C0 */
    { R[31] = 0x8008D3CCu; psx_next = 0x80025EFCu; return; }  /* 0x8008D3C4 jal */
L_8008D3CC:;
    R[4] = lw_(R[18] + 72);  /* 0x8008D3CC */
    R[5] = R[18] + 76;  /* 0x8008D3D0 */
    { R[31] = 0x8008D3DCu; R[16] = R[0] + 1; psx_next = 0x80025DF4u; return; }  /* 0x8008D3D4 jal */
    R[4] = (uint32_t)(int16_t)lh_(R[18] + 76);  /* 0x8008D3DC */
    { uint32_t _c = (R[4] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3E4 b extern */
    { uint32_t _c = (R[16] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3EC b extern */
    { uint32_t _c = ((int32_t)R[4] < 0); if (_c) { psx_next = 0x8008D410u; return; } }  /* 0x8008D3F4 b extern */
    psx_next = 0x8008D3FCu; return;  /* fallthrough */
}

void g0_8008D3CC(void) {
    R[4] = lw_(R[18] + 72);  /* 0x8008D3CC */
    R[5] = R[18] + 76;  /* 0x8008D3D0 */
    { R[31] = 0x8008D3DCu; R[16] = R[0] + 1; psx_next = 0x80025DF4u; return; }  /* 0x8008D3D4 jal */
    R[4] = (uint32_t)(int16_t)lh_(R[18] + 76);  /* 0x8008D3DC */
    { uint32_t _c = (R[4] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3E4 b extern */
    { uint32_t _c = (R[16] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3EC b extern */
    { uint32_t _c = ((int32_t)R[4] < 0); if (_c) { psx_next = 0x8008D410u; return; } }  /* 0x8008D3F4 b extern */
    psx_next = 0x8008D3FCu; return;  /* fallthrough */
}

void g0_8008D3DC(void) {
    R[4] = (uint32_t)(int16_t)lh_(R[18] + 76);  /* 0x8008D3DC */
    { uint32_t _c = (R[4] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3E4 b extern */
    { uint32_t _c = (R[16] == R[0]); if (_c) { psx_next = 0x8008D41Cu; return; } }  /* 0x8008D3EC b extern */
    { uint32_t _c = ((int32_t)R[4] < 0); if (_c) { psx_next = 0x8008D410u; return; } }  /* 0x8008D3F4 b extern */
    psx_next = 0x8008D3FCu; return;  /* fallthrough */
}

void g0_8008D3FC(void) {
    R[5] = lh_(R[18] + 2);  /* 0x8008D3FC */
    { R[31] = 0x8008D408u; psx_next = 0x8002DAE8u; return; }  /* 0x8008D400 jal */
    { goto L_8008D41C; }  /* 0x8008D408 j */
    R[5] = lh_(R[18] + 2);  /* 0x8008D410 */
    { R[31] = 0x8008D41Cu; R[4] = R[0] - R[4]; psx_next = 0x8002CF6Cu; return; }  /* 0x8008D414 jal */
L_8008D41C:;
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 22);  /* 0x8008D41C */
    R[2] = R[0] - 1;  /* 0x8008D420 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8008D438; } }  /* 0x8008D424 */
    R[2] = lh_(R[18] + 20);  /* 0x8008D42C */
    sh_(R[18] + 22, R[2]);  /* 0x8008D434 */
L_8008D438:;
    R[31] = lw_(R[29] + 28);  /* 0x8008D438 */
    R[18] = lw_(R[29] + 24);  /* 0x8008D43C */
    R[17] = lw_(R[29] + 20);  /* 0x8008D440 */
    R[16] = lw_(R[29] + 16);  /* 0x8008D444 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008D448 jr ra */
}

void g0_8008D408(void) {
    { goto L_8008D41C; }  /* 0x8008D408 j */
    R[5] = lh_(R[18] + 2);  /* 0x8008D410 */
    { R[31] = 0x8008D41Cu; R[4] = R[0] - R[4]; psx_next = 0x8002CF6Cu; return; }  /* 0x8008D414 jal */
L_8008D41C:;
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 22);  /* 0x8008D41C */
    R[2] = R[0] - 1;  /* 0x8008D420 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8008D438; } }  /* 0x8008D424 */
    R[2] = lh_(R[18] + 20);  /* 0x8008D42C */
    sh_(R[18] + 22, R[2]);  /* 0x8008D434 */
L_8008D438:;
    R[31] = lw_(R[29] + 28);  /* 0x8008D438 */
    R[18] = lw_(R[29] + 24);  /* 0x8008D43C */
    R[17] = lw_(R[29] + 20);  /* 0x8008D440 */
    R[16] = lw_(R[29] + 16);  /* 0x8008D444 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008D448 jr ra */
}

void g0_8008D410(void) {
    R[5] = lh_(R[18] + 2);  /* 0x8008D410 */
    { R[31] = 0x8008D41Cu; R[4] = R[0] - R[4]; psx_next = 0x8002CF6Cu; return; }  /* 0x8008D414 jal */
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 22);  /* 0x8008D41C */
    R[2] = R[0] - 1;  /* 0x8008D420 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8008D438; } }  /* 0x8008D424 */
    R[2] = lh_(R[18] + 20);  /* 0x8008D42C */
    sh_(R[18] + 22, R[2]);  /* 0x8008D434 */
L_8008D438:;
    R[31] = lw_(R[29] + 28);  /* 0x8008D438 */
    R[18] = lw_(R[29] + 24);  /* 0x8008D43C */
    R[17] = lw_(R[29] + 20);  /* 0x8008D440 */
    R[16] = lw_(R[29] + 16);  /* 0x8008D444 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008D448 jr ra */
}

void g0_8008D41C(void) {
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 22);  /* 0x8008D41C */
    R[2] = R[0] - 1;  /* 0x8008D420 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8008D438; } }  /* 0x8008D424 */
    R[2] = lh_(R[18] + 20);  /* 0x8008D42C */
    sh_(R[18] + 22, R[2]);  /* 0x8008D434 */
L_8008D438:;
    R[31] = lw_(R[29] + 28);  /* 0x8008D438 */
    R[18] = lw_(R[29] + 24);  /* 0x8008D43C */
    R[17] = lw_(R[29] + 20);  /* 0x8008D440 */
    R[16] = lw_(R[29] + 16);  /* 0x8008D444 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008D448 jr ra */
}

void g0_8008D450(void) {
    R[29] = R[29] - 32;  /* 0x8008D450 */
    sw_(R[29] + 28, R[31]);  /* 0x8008D454 */
    sw_(R[29] + 24, R[18]);  /* 0x8008D458 */
    sw_(R[29] + 20, R[17]);  /* 0x8008D45C */
    sw_(R[29] + 16, R[16]);  /* 0x8008D460 */
    R[18] = lw_(R[4] + 16);  /* 0x8008D464 */
    { uint32_t _c = (R[18] == R[0]); R[17] = R[0] + R[0]; if (_c) { goto L_8008D490; } }  /* 0x8008D46C */
    R[16] = R[4] + R[0];  /* 0x8008D474 */
L_8008D478:;
    R[4] = lw_(R[16] + 20);  /* 0x8008D478 */
    R[16] = R[16] + 4;  /* 0x8008D47C */
    { R[31] = 0x8008D488u; R[17] = R[17] + 1; psx_next = 0x8008D2A4u; return; }  /* 0x8008D480 jal */
    { uint32_t _c = (R[17] != R[18]); if (_c) { psx_bb(); goto L_8008D478; } }  /* 0x8008D488 */
L_8008D490:;
    R[31] = lw_(R[29] + 28);  /* 0x8008D490 */
    R[18] = lw_(R[29] + 24);  /* 0x8008D494 */
    R[17] = lw_(R[29] + 20);  /* 0x8008D498 */
    R[16] = lw_(R[29] + 16);  /* 0x8008D49C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008D4A0 jr ra */
}

void g0_8008D478(void) {
L_8008D478:;
    R[4] = lw_(R[16] + 20);  /* 0x8008D478 */
    R[16] = R[16] + 4;  /* 0x8008D47C */
    { R[31] = 0x8008D488u; R[17] = R[17] + 1; psx_next = 0x8008D2A4u; return; }  /* 0x8008D480 jal */
    { uint32_t _c = (R[17] != R[18]); if (_c) { psx_bb(); goto L_8008D478; } }  /* 0x8008D488 */
    R[31] = lw_(R[29] + 28);  /* 0x8008D490 */
    R[18] = lw_(R[29] + 24);  /* 0x8008D494 */
    R[17] = lw_(R[29] + 20);  /* 0x8008D498 */
    R[16] = lw_(R[29] + 16);  /* 0x8008D49C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008D4A0 jr ra */
}

void g0_8008D488(void) {
    { uint32_t _c = (R[17] != R[18]); if (_c) { psx_next = 0x8008D478u; return; } }  /* 0x8008D488 b extern */
    R[31] = lw_(R[29] + 28);  /* 0x8008D490 */
    R[18] = lw_(R[29] + 24);  /* 0x8008D494 */
    R[17] = lw_(R[29] + 20);  /* 0x8008D498 */
    R[16] = lw_(R[29] + 16);  /* 0x8008D49C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008D4A0 jr ra */
}

void g0_8008D4A8(void) {
    R[4] = 0x8012u << 16;  /* 0x8008D4A8 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 24008);  /* 0x8008D4AC */
    R[3] = lh_(R[4] + 24008);  /* 0x8008D4B0 */
    psx_next = 0x8008D4B4u; return;  /* fallthrough */
}

void g0_8008D4B4(void) {
    R[29] = R[29] - 24;  /* 0x8008D4B4 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[29] + 16, R[31]); if (_c) { goto L_8008D4C8; } }  /* 0x8008D4B8 */
    { R[2] = R[3] - 1; goto L_8008D4D0; }  /* 0x8008D4C0 j */
L_8008D4C8:;
    R[2] = 0x8012u << 16;  /* 0x8008D4C8 */
    R[2] = lh_(R[2] + 21376);  /* 0x8008D4CC */
L_8008D4D0:;
    sh_(R[4] + 24008, R[2]);  /* 0x8008D4D4 */
    R[7] = R[0] + R[0];  /* 0x8008D4D8 */
    R[2] = 0x8012u << 16;  /* 0x8008D4DC */
    R[6] = R[2] - 26864;  /* 0x8008D4E0 */
    R[9] = R[6] + R[0];  /* 0x8008D4E4 */
    R[2] = 0x8013u << 16;  /* 0x8008D4E8 */
    R[8] = R[2] - 23304;  /* 0x8008D4EC */
    R[5] = R[6] + 352;  /* 0x8008D4F0 */
L_8008D4F4:;
    R[2] = (uint32_t)(int16_t)lh_(R[6]);  /* 0x8008D4F4 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 5; if (_c) { goto L_8008D634; } }  /* 0x8008D4FC */
    R[3] = lb_(R[5] + 439);  /* 0x8008D504 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] - 1; if (_c) { goto L_8008D530; } }  /* 0x8008D50C */
    sw_(R[5] + -148, R[0]);  /* 0x8008D514 */
    sw_(R[5] + -152, R[0]);  /* 0x8008D518 */
    sw_(R[5] + -156, R[0]);  /* 0x8008D51C */
    sw_(R[5] + -188, R[0]);  /* 0x8008D520 */
    sw_(R[5] + -192, R[0]);  /* 0x8008D524 */
    sw_(R[5] + -196, R[0]);  /* 0x8008D528 */
    sw_(R[5] + -228, R[2]);  /* 0x8008D52C */
L_8008D530:;
    R[2] = lb_(R[5] + 437);  /* 0x8008D530 */
    sh_(R[5] + -134, R[0]);  /* 0x8008D534 */
    sw_(R[5] + -132, R[0]);  /* 0x8008D538 */
    R[2] = R[2] & 0xB;  /* 0x8008D53C */
    { uint32_t _c = (R[2] != R[0]); sh_(R[5] + -128, R[0]); if (_c) { goto L_8008D5B0; } }  /* 0x8008D540 */
    R[3] = lb_(R[5] + 445);  /* 0x8008D548 */
    R[2] = R[0] | 0xFFFF;  /* 0x8008D54C */
    sh_(R[5] + 424, R[2]);  /* 0x8008D550 */
    sh_(R[5] + 426, R[0]);  /* 0x8008D554 */
    { uint32_t _c = (R[3] == R[0]); sb_(R[5] + 443, R[0]); if (_c) { goto L_8008D56C; } }  /* 0x8008D558 */
    R[2] = R[3] - 1;  /* 0x8008D560 */
    { sb_(R[5] + 445, R[2]); goto L_8008D570; }  /* 0x8008D564 j */
L_8008D56C:;
    sb_(R[5] + 446, R[0]);  /* 0x8008D56C */
L_8008D570:;
    R[3] = lb_(R[5] + 447);  /* 0x8008D570 */
    sw_(R[5] + -308, R[0]);  /* 0x8008D574 */
    sw_(R[5] + -312, R[0]);  /* 0x8008D578 */
    R[2] = (R[3] < (uint32_t)10u);  /* 0x8008D57C */
    { uint32_t _c = (R[2] == R[0]); sw_(R[5] + -316, R[0]); if (_c) { goto L_8008D590; } }  /* 0x8008D580 */
    R[2] = R[3] + 1;  /* 0x8008D588 */
    sb_(R[5] + 447, R[2]);  /* 0x8008D58C */
L_8008D590:;
    R[2] = (uint32_t)(int16_t)lh_(R[5] + -136);  /* 0x8008D590 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008D5B0; } }  /* 0x8008D598 */
    R[2] = lh_(R[5] + -126);  /* 0x8008D5A0 */
    R[2] = R[2] + 1;  /* 0x8008D5A8 */
    sh_(R[5] + -126, R[2]);  /* 0x8008D5AC */
L_8008D5B0:;
    R[2] = lw_(R[5] + -336);  /* 0x8008D5B0 */
    R[3] = R[0] | 0x8000;  /* 0x8008D5B4 */
    R[2] = R[2] & 0xC000;  /* 0x8008D5B8 */
    { uint32_t _c = (R[2] != R[3]); R[4] = R[6] - R[9]; if (_c) { goto L_8008D610; } }  /* 0x8008D5BC */
    R[2] = R[4] << 2;  /* 0x8008D5C4 */
    R[2] = R[2] + R[4];  /* 0x8008D5C8 */
    R[2] = R[2] << 4;  /* 0x8008D5CC */
    R[2] = R[2] - R[4];  /* 0x8008D5D0 */
    R[3] = R[2] << 5;  /* 0x8008D5D4 */
    R[2] = R[2] + R[3];  /* 0x8008D5D8 */
    R[2] = R[2] << 3;  /* 0x8008D5DC */
    R[2] = R[2] + R[4];  /* 0x8008D5E0 */
    R[3] = R[2] << 11;  /* 0x8008D5E4 */
    R[2] = R[2] + R[3];  /* 0x8008D5E8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 2);  /* 0x8008D5EC */
    R[3] = R[2] << 3;  /* 0x8008D5F0 */
    R[3] = R[3] + R[2];  /* 0x8008D5F4 */
    R[3] = R[3] << 3;  /* 0x8008D5F8 */
    R[3] = R[3] + R[8];  /* 0x8008D5FC */
    R[2] = lh_(R[3]);  /* 0x8008D600 */
    R[2] = R[2] & 0x7FFF;  /* 0x8008D608 */
    sh_(R[3], R[2]);  /* 0x8008D60C */
L_8008D610:;
    R[2] = lw_(R[5]);  /* 0x8008D610 */
    { uint32_t _c = (R[2] != R[0]); R[7] = R[7] + 1; if (_c) { goto L_8008D638; } }  /* 0x8008D618 */
    R[4] = 0x8008u << 16;  /* 0x8008D620 */
    { R[31] = 0x8008D62Cu; R[4] = R[4] + 5356; psx_next = 0x8001BBF8u; return; }  /* 0x8008D624 jal */
    { R[31] = 0x8008D634u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8008D62C jal */
L_8008D634:;
    R[7] = R[7] + 1;  /* 0x8008D634 */
L_8008D638:;
    R[5] = R[5] + 804;  /* 0x8008D638 */
    R[2] = R[0] + 60;  /* 0x8008D63C */
    { uint32_t _c = (R[7] != R[2]); R[6] = R[6] + 804; if (_c) { psx_bb(); goto L_8008D4F4; } }  /* 0x8008D640 */
    { R[31] = 0x8008D650u; psx_next = 0x8008C568u; return; }  /* 0x8008D648 jal */
    R[31] = lw_(R[29] + 16);  /* 0x8008D650 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8008D658 jr ra */
}

void g0_8008D4F4(void) {
L_8008D4F4:;
    R[2] = (uint32_t)(int16_t)lh_(R[6]);  /* 0x8008D4F4 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 5; if (_c) { goto L_8008D634; } }  /* 0x8008D4FC */
    R[3] = lb_(R[5] + 439);  /* 0x8008D504 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] - 1; if (_c) { goto L_8008D530; } }  /* 0x8008D50C */
    sw_(R[5] + -148, R[0]);  /* 0x8008D514 */
    sw_(R[5] + -152, R[0]);  /* 0x8008D518 */
    sw_(R[5] + -156, R[0]);  /* 0x8008D51C */
    sw_(R[5] + -188, R[0]);  /* 0x8008D520 */
    sw_(R[5] + -192, R[0]);  /* 0x8008D524 */
    sw_(R[5] + -196, R[0]);  /* 0x8008D528 */
    sw_(R[5] + -228, R[2]);  /* 0x8008D52C */
L_8008D530:;
    R[2] = lb_(R[5] + 437);  /* 0x8008D530 */
    sh_(R[5] + -134, R[0]);  /* 0x8008D534 */
    sw_(R[5] + -132, R[0]);  /* 0x8008D538 */
    R[2] = R[2] & 0xB;  /* 0x8008D53C */
    { uint32_t _c = (R[2] != R[0]); sh_(R[5] + -128, R[0]); if (_c) { goto L_8008D5B0; } }  /* 0x8008D540 */
    R[3] = lb_(R[5] + 445);  /* 0x8008D548 */
    R[2] = R[0] | 0xFFFF;  /* 0x8008D54C */
    sh_(R[5] + 424, R[2]);  /* 0x8008D550 */
    sh_(R[5] + 426, R[0]);  /* 0x8008D554 */
    { uint32_t _c = (R[3] == R[0]); sb_(R[5] + 443, R[0]); if (_c) { goto L_8008D56C; } }  /* 0x8008D558 */
    R[2] = R[3] - 1;  /* 0x8008D560 */
    { sb_(R[5] + 445, R[2]); goto L_8008D570; }  /* 0x8008D564 j */
L_8008D56C:;
    sb_(R[5] + 446, R[0]);  /* 0x8008D56C */
L_8008D570:;
    R[3] = lb_(R[5] + 447);  /* 0x8008D570 */
    sw_(R[5] + -308, R[0]);  /* 0x8008D574 */
    sw_(R[5] + -312, R[0]);  /* 0x8008D578 */
    R[2] = (R[3] < (uint32_t)10u);  /* 0x8008D57C */
    { uint32_t _c = (R[2] == R[0]); sw_(R[5] + -316, R[0]); if (_c) { goto L_8008D590; } }  /* 0x8008D580 */
    R[2] = R[3] + 1;  /* 0x8008D588 */
    sb_(R[5] + 447, R[2]);  /* 0x8008D58C */
L_8008D590:;
    R[2] = (uint32_t)(int16_t)lh_(R[5] + -136);  /* 0x8008D590 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008D5B0; } }  /* 0x8008D598 */
    R[2] = lh_(R[5] + -126);  /* 0x8008D5A0 */
    R[2] = R[2] + 1;  /* 0x8008D5A8 */
    sh_(R[5] + -126, R[2]);  /* 0x8008D5AC */
L_8008D5B0:;
    R[2] = lw_(R[5] + -336);  /* 0x8008D5B0 */
    R[3] = R[0] | 0x8000;  /* 0x8008D5B4 */
    R[2] = R[2] & 0xC000;  /* 0x8008D5B8 */
    { uint32_t _c = (R[2] != R[3]); R[4] = R[6] - R[9]; if (_c) { goto L_8008D610; } }  /* 0x8008D5BC */
    R[2] = R[4] << 2;  /* 0x8008D5C4 */
    R[2] = R[2] + R[4];  /* 0x8008D5C8 */
    R[2] = R[2] << 4;  /* 0x8008D5CC */
    R[2] = R[2] - R[4];  /* 0x8008D5D0 */
    R[3] = R[2] << 5;  /* 0x8008D5D4 */
    R[2] = R[2] + R[3];  /* 0x8008D5D8 */
    R[2] = R[2] << 3;  /* 0x8008D5DC */
    R[2] = R[2] + R[4];  /* 0x8008D5E0 */
    R[3] = R[2] << 11;  /* 0x8008D5E4 */
    R[2] = R[2] + R[3];  /* 0x8008D5E8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 2);  /* 0x8008D5EC */
    R[3] = R[2] << 3;  /* 0x8008D5F0 */
    R[3] = R[3] + R[2];  /* 0x8008D5F4 */
    R[3] = R[3] << 3;  /* 0x8008D5F8 */
    R[3] = R[3] + R[8];  /* 0x8008D5FC */
    R[2] = lh_(R[3]);  /* 0x8008D600 */
    R[2] = R[2] & 0x7FFF;  /* 0x8008D608 */
    sh_(R[3], R[2]);  /* 0x8008D60C */
L_8008D610:;
    R[2] = lw_(R[5]);  /* 0x8008D610 */
    { uint32_t _c = (R[2] != R[0]); R[7] = R[7] + 1; if (_c) { goto L_8008D638; } }  /* 0x8008D618 */
    R[4] = 0x8008u << 16;  /* 0x8008D620 */
    { R[31] = 0x8008D62Cu; R[4] = R[4] + 5356; psx_next = 0x8001BBF8u; return; }  /* 0x8008D624 jal */
    { R[31] = 0x8008D634u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8008D62C jal */
L_8008D634:;
    R[7] = R[7] + 1;  /* 0x8008D634 */
L_8008D638:;
    R[5] = R[5] + 804;  /* 0x8008D638 */
    R[2] = R[0] + 60;  /* 0x8008D63C */
    { uint32_t _c = (R[7] != R[2]); R[6] = R[6] + 804; if (_c) { psx_bb(); goto L_8008D4F4; } }  /* 0x8008D640 */
    { R[31] = 0x8008D650u; psx_next = 0x8008C568u; return; }  /* 0x8008D648 jal */
    R[31] = lw_(R[29] + 16);  /* 0x8008D650 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8008D658 jr ra */
}

void g0_8008D62C(void) {
    { R[31] = 0x8008D634u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8008D62C jal */
    R[7] = R[7] + 1;  /* 0x8008D634 */
    R[5] = R[5] + 804;  /* 0x8008D638 */
    R[2] = R[0] + 60;  /* 0x8008D63C */
    { uint32_t _c = (R[7] != R[2]); R[6] = R[6] + 804; if (_c) { psx_next = 0x8008D4F4u; return; } }  /* 0x8008D640 b extern */
    { R[31] = 0x8008D650u; psx_next = 0x8008C568u; return; }  /* 0x8008D648 jal */
    R[31] = lw_(R[29] + 16);  /* 0x8008D650 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8008D658 jr ra */
}

void g0_8008D634(void) {
    R[7] = R[7] + 1;  /* 0x8008D634 */
    R[5] = R[5] + 804;  /* 0x8008D638 */
    R[2] = R[0] + 60;  /* 0x8008D63C */
    { uint32_t _c = (R[7] != R[2]); R[6] = R[6] + 804; if (_c) { psx_next = 0x8008D4F4u; return; } }  /* 0x8008D640 b extern */
    { R[31] = 0x8008D650u; psx_next = 0x8008C568u; return; }  /* 0x8008D648 jal */
    R[31] = lw_(R[29] + 16);  /* 0x8008D650 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8008D658 jr ra */
}

void g0_8008D650(void) {
    R[31] = lw_(R[29] + 16);  /* 0x8008D650 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8008D658 jr ra */
}

void g0_8008D660(void) {
    R[29] = R[29] - 24;  /* 0x8008D660 */
    sw_(R[29] + 16, R[16]);  /* 0x8008D664 */
    R[16] = R[4] + R[0];  /* 0x8008D668 */
    R[4] = R[5] + R[0];  /* 0x8008D66C */
    sw_(R[29] + 20, R[31]);  /* 0x8008D670 */
    R[2] = lh_(R[16] + 6);  /* 0x8008D674 */
    R[3] = lh_(R[16] + 20);  /* 0x8008D678 */
    R[5] = lw_(R[16] + 672);  /* 0x8008D67C */
    R[6] = lh_(R[16] + 632);  /* 0x8008D680 */
    R[7] = lw_(R[16] + 676);  /* 0x8008D684 */
    sh_(R[16] + 632, R[0]);  /* 0x8008D688 */
    sh_(R[16] + 628, R[4]);  /* 0x8008D68C */
    sh_(R[16] + 616, R[2]);  /* 0x8008D690 */
    R[2] = R[16] + R[4];  /* 0x8008D694 */
    sh_(R[16] + 618, R[3]);  /* 0x8008D698 */
    sw_(R[16] + 624, R[5]);  /* 0x8008D69C */
    sh_(R[16] + 620, R[6]);  /* 0x8008D6A0 */
    sw_(R[16] + 680, R[7]);  /* 0x8008D6A4 */
    R[5] = lb_(R[2] + 684);  /* 0x8008D6A8 */
    { R[31] = 0x8008D6B4u; sh_(R[16] + 630, R[5]); psx_next = 0x8009334Cu; return; }  /* 0x8008D6AC jal */
    sw_(R[16] + 676, R[2]);  /* 0x8008D6B4 */
    R[31] = lw_(R[29] + 20);  /* 0x8008D6B8 */
    R[16] = lw_(R[29] + 16);  /* 0x8008D6BC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8008D6C0 jr ra */
}

void g0_8008D6B4(void) {
    sw_(R[16] + 676, R[2]);  /* 0x8008D6B4 */
    R[31] = lw_(R[29] + 20);  /* 0x8008D6B8 */
    R[16] = lw_(R[29] + 16);  /* 0x8008D6BC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8008D6C0 jr ra */
}

void g0_8008D6C8(void) {
    R[2] = lh_(R[4] + 620);  /* 0x8008D6C8 */
    R[3] = lb_(R[4] + 684);  /* 0x8008D6CC */
    R[5] = lw_(R[4] + 680);  /* 0x8008D6D0 */
    R[6] = lw_(R[4] + 624);  /* 0x8008D6D4 */
    sh_(R[4] + 628, R[0]);  /* 0x8008D6D8 */
    sh_(R[4] + 632, R[2]);  /* 0x8008D6DC */
    sh_(R[4] + 630, R[3]);  /* 0x8008D6E0 */
    sw_(R[4] + 676, R[5]);  /* 0x8008D6E4 */
    { sw_(R[4] + 672, R[6]); psx_next = R[31]; return; }  /* 0x8008D6E8 jr ra */
}

void g0_8008D6F0(void) {
    R[29] = R[29] - 40;  /* 0x8008D6F0 */
    sw_(R[29] + 28, R[19]);  /* 0x8008D6F4 */
    R[19] = R[0] + R[0];  /* 0x8008D6F8 */
    R[2] = 0x8012u << 16;  /* 0x8008D6FC */
    sw_(R[29] + 20, R[17]);  /* 0x8008D700 */
    R[17] = R[2] - 26864;  /* 0x8008D704 */
    R[2] = 0x8008u << 16;  /* 0x8008D708 */
    sw_(R[29] + 32, R[20]);  /* 0x8008D70C */
    R[20] = R[2] + 5368;  /* 0x8008D710 */
    sw_(R[29] + 24, R[18]);  /* 0x8008D714 */
    R[18] = R[0] + 3;  /* 0x8008D718 */
    sw_(R[29] + 16, R[16]);  /* 0x8008D71C */
    R[16] = R[17] + 794;  /* 0x8008D720 */
    sw_(R[29] + 36, R[31]);  /* 0x8008D724 */
    R[2] = lb_(R[16] + -5);  /* 0x8008D728 */
    R[2] = R[2] & 0xB;  /* 0x8008D730 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008D948u; return; } }  /* 0x8008D734 b extern */
    R[3] = lb_(R[16] + -3);  /* 0x8008D73C */
    R[2] = (R[3] < (uint32_t)6u);  /* 0x8008D744 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] << 2; if (_c) { goto L_8008D87C; } }  /* 0x8008D748 */
    R[2] = R[2] + R[20];  /* 0x8008D750 */
    R[2] = lw_(R[2]);  /* 0x8008D754 */
    { uint32_t _t = R[2]; psx_next = _t; return; }  /* 0x8008D75C jr indirect */
    R[5] = lb_(R[16] + -3);  /* 0x8008D764 */
    { R[31] = 0x8008D770u; R[4] = R[17] + R[0]; psx_next = 0x80088F6Cu; return; }  /* 0x8008D768 jal */
    R[2] = lb_(R[16] + -110);  /* 0x8008D770 */
    R[4] = R[0] + R[0];  /* 0x8008D774 */
    sb_(R[16] + -3, R[0]);  /* 0x8008D778 */
    sh_(R[16] + -166, R[0]);  /* 0x8008D77C */
    R[5] = R[2] + R[0];  /* 0x8008D780 */
    { R[31] = 0x8008D78Cu; sh_(R[16] + -164, R[2]); psx_next = 0x8009334Cu; return; }  /* 0x8008D784 jal */
    R[4] = R[17] + R[0];  /* 0x8008D78C */
    { R[31] = 0x8008D798u; sw_(R[16] + -118, R[2]); psx_next = 0x8008D2A4u; return; }  /* 0x8008D790 jal */
    { goto L_8008D87C; }  /* 0x8008D798 j */
    R[2] = lb_(R[16] + -7);  /* 0x8008D7A0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D7D0; } }  /* 0x8008D7A8 */
    R[2] = lb_(R[16] + -105);  /* 0x8008D7B0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008D7C8; } }  /* 0x8008D7B8 */
    { sb_(R[16] + -3, R[2]); goto L_8008D87C; }  /* 0x8008D7C0 j */
L_8008D7C8:;
    { sb_(R[16] + -7, R[0]); goto L_8008D87C; }  /* 0x8008D7C8 j */
L_8008D7D0:;
    R[2] = lb_(R[16] + -4);  /* 0x8008D7D0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D808; } }  /* 0x8008D7D8 */
    { uint32_t _c = (R[2] == R[18]); if (_c) { goto L_8008D858; } }  /* 0x8008D7E0 */
    R[2] = lb_(R[16] + -104);  /* 0x8008D7E8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8008D800; } }  /* 0x8008D7F0 */
    { sb_(R[16] + -3, R[2]); goto L_8008D87C; }  /* 0x8008D7F8 j */
L_8008D800:;
    { sb_(R[16] + -4, R[0]); goto L_8008D87C; }  /* 0x8008D800 j */
L_8008D808:;
    R[2] = lb_(R[16] + -1);  /* 0x8008D808 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D87C; } }  /* 0x8008D810 */
    R[2] = lb_(R[16] + -103);  /* 0x8008D818 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008D834; } }  /* 0x8008D820 */
    sb_(R[16] + -3, R[18]);  /* 0x8008D828 */
    { sb_(R[16] + -1, R[2]); goto L_8008D87C; }  /* 0x8008D82C j */
L_8008D834:;
    { sb_(R[16] + -1, R[0]); goto L_8008D87C; }  /* 0x8008D834 j */
    R[2] = lb_(R[16] + -7);  /* 0x8008D83C */
    { goto L_8008D86C; }  /* 0x8008D840 j */
    R[2] = lb_(R[16] + -4);  /* 0x8008D848 */
    { uint32_t _c = (R[2] != R[18]); if (_c) { goto L_8008D87C; } }  /* 0x8008D850 */
L_8008D858:;
    { R[31] = 0x8008D860u; R[4] = R[17] + R[0]; psx_next = 0x80088410u; return; }  /* 0x8008D858 jal */
    { goto L_8008D87C; }  /* 0x8008D860 j */
    R[2] = lb_(R[16] + -1);  /* 0x8008D868 */
L_8008D86C:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008D87C; } }  /* 0x8008D870 */
    sb_(R[16] + -3, R[0]);  /* 0x8008D878 */
L_8008D87C:;
    R[3] = (uint32_t)(int16_t)lh_(R[16] + -166);  /* 0x8008D87C */
    R[2] = R[0] + 1;  /* 0x8008D880 */
    { uint32_t _c = (R[3] == R[2]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_8008D924; } }  /* 0x8008D884 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8A4; } }  /* 0x8008D88C */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_8008D8B4; } }  /* 0x8008D894 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D89C j extern */
L_8008D8A4:;
    { uint32_t _c = (R[3] == R[18]); if (_c) { goto L_8008D930; } }  /* 0x8008D8A4 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8AC j extern */
L_8008D8B4:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D8B4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8EC; } }  /* 0x8008D8BC */
    R[2] = lb_(R[16] + -109);  /* 0x8008D8C4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D8E4; } }  /* 0x8008D8CC */
    { R[31] = 0x8008D8DCu; R[5] = R[0] + 1; psx_next = 0x8008D660u; return; }  /* 0x8008D8D4 jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8DC j extern */
L_8008D8E4:;
    { sb_(R[16] + -6, R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D8E4 j extern */
L_8008D8EC:;
    R[2] = lb_(R[16]);  /* 0x8008D8EC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008D948u; return; } }  /* 0x8008D8F4 b extern */
    R[2] = lb_(R[16] + -107);  /* 0x8008D8FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D91C; } }  /* 0x8008D904 */
    { R[31] = 0x8008D914u; R[5] = R[0] + 3; psx_next = 0x8008D660u; return; }  /* 0x8008D90C jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D914 j extern */
L_8008D91C:;
    { sb_(R[16], R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D91C j extern */
L_8008D924:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D924 */
    { goto L_8008D934; }  /* 0x8008D928 j */
L_8008D930:;
    R[2] = lb_(R[16]);  /* 0x8008D930 */
L_8008D934:;
    psx_next = 0x8008D938u; return;  /* fallthrough */
}

void g0_8008D728(void) {
    R[2] = lb_(R[16] + -5);  /* 0x8008D728 */
    R[2] = R[2] & 0xB;  /* 0x8008D730 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8008D948u; return; } }  /* 0x8008D734 b extern */
    R[3] = lb_(R[16] + -3);  /* 0x8008D73C */
    R[2] = (R[3] < (uint32_t)6u);  /* 0x8008D744 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] << 2; if (_c) { goto L_8008D87C; } }  /* 0x8008D748 */
    R[2] = R[2] + R[20];  /* 0x8008D750 */
    R[2] = lw_(R[2]);  /* 0x8008D754 */
    { uint32_t _t = R[2]; psx_next = _t; return; }  /* 0x8008D75C jr indirect */
    R[5] = lb_(R[16] + -3);  /* 0x8008D764 */
    { R[31] = 0x8008D770u; R[4] = R[17] + R[0]; psx_next = 0x80088F6Cu; return; }  /* 0x8008D768 jal */
    R[2] = lb_(R[16] + -110);  /* 0x8008D770 */
    R[4] = R[0] + R[0];  /* 0x8008D774 */
    sb_(R[16] + -3, R[0]);  /* 0x8008D778 */
    sh_(R[16] + -166, R[0]);  /* 0x8008D77C */
    R[5] = R[2] + R[0];  /* 0x8008D780 */
    { R[31] = 0x8008D78Cu; sh_(R[16] + -164, R[2]); psx_next = 0x8009334Cu; return; }  /* 0x8008D784 jal */
    R[4] = R[17] + R[0];  /* 0x8008D78C */
    { R[31] = 0x8008D798u; sw_(R[16] + -118, R[2]); psx_next = 0x8008D2A4u; return; }  /* 0x8008D790 jal */
    { goto L_8008D87C; }  /* 0x8008D798 j */
    R[2] = lb_(R[16] + -7);  /* 0x8008D7A0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D7D0; } }  /* 0x8008D7A8 */
    R[2] = lb_(R[16] + -105);  /* 0x8008D7B0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008D7C8; } }  /* 0x8008D7B8 */
    { sb_(R[16] + -3, R[2]); goto L_8008D87C; }  /* 0x8008D7C0 j */
L_8008D7C8:;
    { sb_(R[16] + -7, R[0]); goto L_8008D87C; }  /* 0x8008D7C8 j */
L_8008D7D0:;
    R[2] = lb_(R[16] + -4);  /* 0x8008D7D0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D808; } }  /* 0x8008D7D8 */
    { uint32_t _c = (R[2] == R[18]); if (_c) { goto L_8008D858; } }  /* 0x8008D7E0 */
    R[2] = lb_(R[16] + -104);  /* 0x8008D7E8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8008D800; } }  /* 0x8008D7F0 */
    { sb_(R[16] + -3, R[2]); goto L_8008D87C; }  /* 0x8008D7F8 j */
L_8008D800:;
    { sb_(R[16] + -4, R[0]); goto L_8008D87C; }  /* 0x8008D800 j */
L_8008D808:;
    R[2] = lb_(R[16] + -1);  /* 0x8008D808 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D87C; } }  /* 0x8008D810 */
    R[2] = lb_(R[16] + -103);  /* 0x8008D818 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008D834; } }  /* 0x8008D820 */
    sb_(R[16] + -3, R[18]);  /* 0x8008D828 */
    { sb_(R[16] + -1, R[2]); goto L_8008D87C; }  /* 0x8008D82C j */
L_8008D834:;
    { sb_(R[16] + -1, R[0]); goto L_8008D87C; }  /* 0x8008D834 j */
    R[2] = lb_(R[16] + -7);  /* 0x8008D83C */
    { goto L_8008D86C; }  /* 0x8008D840 j */
    R[2] = lb_(R[16] + -4);  /* 0x8008D848 */
    { uint32_t _c = (R[2] != R[18]); if (_c) { goto L_8008D87C; } }  /* 0x8008D850 */
L_8008D858:;
    { R[31] = 0x8008D860u; R[4] = R[17] + R[0]; psx_next = 0x80088410u; return; }  /* 0x8008D858 jal */
    { goto L_8008D87C; }  /* 0x8008D860 j */
    R[2] = lb_(R[16] + -1);  /* 0x8008D868 */
L_8008D86C:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008D87C; } }  /* 0x8008D870 */
    sb_(R[16] + -3, R[0]);  /* 0x8008D878 */
L_8008D87C:;
    R[3] = (uint32_t)(int16_t)lh_(R[16] + -166);  /* 0x8008D87C */
    R[2] = R[0] + 1;  /* 0x8008D880 */
    { uint32_t _c = (R[3] == R[2]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_8008D924; } }  /* 0x8008D884 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8A4; } }  /* 0x8008D88C */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_8008D8B4; } }  /* 0x8008D894 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D89C j extern */
L_8008D8A4:;
    { uint32_t _c = (R[3] == R[18]); if (_c) { goto L_8008D930; } }  /* 0x8008D8A4 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8AC j extern */
L_8008D8B4:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D8B4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8EC; } }  /* 0x8008D8BC */
    R[2] = lb_(R[16] + -109);  /* 0x8008D8C4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D8E4; } }  /* 0x8008D8CC */
    { R[31] = 0x8008D8DCu; R[5] = R[0] + 1; psx_next = 0x8008D660u; return; }  /* 0x8008D8D4 jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8DC j extern */
L_8008D8E4:;
    { sb_(R[16] + -6, R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D8E4 j extern */
L_8008D8EC:;
    R[2] = lb_(R[16]);  /* 0x8008D8EC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008D948u; return; } }  /* 0x8008D8F4 b extern */
    R[2] = lb_(R[16] + -107);  /* 0x8008D8FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D91C; } }  /* 0x8008D904 */
    { R[31] = 0x8008D914u; R[5] = R[0] + 3; psx_next = 0x8008D660u; return; }  /* 0x8008D90C jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D914 j extern */
L_8008D91C:;
    { sb_(R[16], R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D91C j extern */
L_8008D924:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D924 */
    { goto L_8008D934; }  /* 0x8008D928 j */
L_8008D930:;
    R[2] = lb_(R[16]);  /* 0x8008D930 */
L_8008D934:;
    psx_next = 0x8008D938u; return;  /* fallthrough */
}

void g0_8008D764(void) {
    R[5] = lb_(R[16] + -3);  /* 0x8008D764 */
    { R[31] = 0x8008D770u; R[4] = R[17] + R[0]; psx_next = 0x80088F6Cu; return; }  /* 0x8008D768 jal */
    R[2] = lb_(R[16] + -110);  /* 0x8008D770 */
    R[4] = R[0] + R[0];  /* 0x8008D774 */
    sb_(R[16] + -3, R[0]);  /* 0x8008D778 */
    sh_(R[16] + -166, R[0]);  /* 0x8008D77C */
    R[5] = R[2] + R[0];  /* 0x8008D780 */
    { R[31] = 0x8008D78Cu; sh_(R[16] + -164, R[2]); psx_next = 0x8009334Cu; return; }  /* 0x8008D784 jal */
    R[4] = R[17] + R[0];  /* 0x8008D78C */
    { R[31] = 0x8008D798u; sw_(R[16] + -118, R[2]); psx_next = 0x8008D2A4u; return; }  /* 0x8008D790 jal */
    { goto L_8008D87C; }  /* 0x8008D798 j */
    R[2] = lb_(R[16] + -7);  /* 0x8008D7A0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D7D0; } }  /* 0x8008D7A8 */
    R[2] = lb_(R[16] + -105);  /* 0x8008D7B0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008D7C8; } }  /* 0x8008D7B8 */
    { sb_(R[16] + -3, R[2]); goto L_8008D87C; }  /* 0x8008D7C0 j */
L_8008D7C8:;
    { sb_(R[16] + -7, R[0]); goto L_8008D87C; }  /* 0x8008D7C8 j */
L_8008D7D0:;
    R[2] = lb_(R[16] + -4);  /* 0x8008D7D0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D808; } }  /* 0x8008D7D8 */
    { uint32_t _c = (R[2] == R[18]); if (_c) { goto L_8008D858; } }  /* 0x8008D7E0 */
    R[2] = lb_(R[16] + -104);  /* 0x8008D7E8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8008D800; } }  /* 0x8008D7F0 */
    { sb_(R[16] + -3, R[2]); goto L_8008D87C; }  /* 0x8008D7F8 j */
L_8008D800:;
    { sb_(R[16] + -4, R[0]); goto L_8008D87C; }  /* 0x8008D800 j */
L_8008D808:;
    R[2] = lb_(R[16] + -1);  /* 0x8008D808 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D87C; } }  /* 0x8008D810 */
    R[2] = lb_(R[16] + -103);  /* 0x8008D818 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008D834; } }  /* 0x8008D820 */
    sb_(R[16] + -3, R[18]);  /* 0x8008D828 */
    { sb_(R[16] + -1, R[2]); goto L_8008D87C; }  /* 0x8008D82C j */
L_8008D834:;
    { sb_(R[16] + -1, R[0]); goto L_8008D87C; }  /* 0x8008D834 j */
    R[2] = lb_(R[16] + -7);  /* 0x8008D83C */
    { goto L_8008D86C; }  /* 0x8008D840 j */
    R[2] = lb_(R[16] + -4);  /* 0x8008D848 */
    { uint32_t _c = (R[2] != R[18]); if (_c) { goto L_8008D87C; } }  /* 0x8008D850 */
L_8008D858:;
    { R[31] = 0x8008D860u; R[4] = R[17] + R[0]; psx_next = 0x80088410u; return; }  /* 0x8008D858 jal */
    { goto L_8008D87C; }  /* 0x8008D860 j */
    R[2] = lb_(R[16] + -1);  /* 0x8008D868 */
L_8008D86C:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008D87C; } }  /* 0x8008D870 */
    sb_(R[16] + -3, R[0]);  /* 0x8008D878 */
L_8008D87C:;
    R[3] = (uint32_t)(int16_t)lh_(R[16] + -166);  /* 0x8008D87C */
    R[2] = R[0] + 1;  /* 0x8008D880 */
    { uint32_t _c = (R[3] == R[2]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_8008D924; } }  /* 0x8008D884 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8A4; } }  /* 0x8008D88C */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_8008D8B4; } }  /* 0x8008D894 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D89C j extern */
L_8008D8A4:;
    { uint32_t _c = (R[3] == R[18]); if (_c) { goto L_8008D930; } }  /* 0x8008D8A4 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8AC j extern */
L_8008D8B4:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D8B4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8EC; } }  /* 0x8008D8BC */
    R[2] = lb_(R[16] + -109);  /* 0x8008D8C4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D8E4; } }  /* 0x8008D8CC */
    { R[31] = 0x8008D8DCu; R[5] = R[0] + 1; psx_next = 0x8008D660u; return; }  /* 0x8008D8D4 jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8DC j extern */
L_8008D8E4:;
    { sb_(R[16] + -6, R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D8E4 j extern */
L_8008D8EC:;
    R[2] = lb_(R[16]);  /* 0x8008D8EC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008D948u; return; } }  /* 0x8008D8F4 b extern */
    R[2] = lb_(R[16] + -107);  /* 0x8008D8FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D91C; } }  /* 0x8008D904 */
    { R[31] = 0x8008D914u; R[5] = R[0] + 3; psx_next = 0x8008D660u; return; }  /* 0x8008D90C jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D914 j extern */
L_8008D91C:;
    { sb_(R[16], R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D91C j extern */
L_8008D924:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D924 */
    { goto L_8008D934; }  /* 0x8008D928 j */
L_8008D930:;
    R[2] = lb_(R[16]);  /* 0x8008D930 */
L_8008D934:;
    psx_next = 0x8008D938u; return;  /* fallthrough */
}

void g0_8008D770(void) {
    R[2] = lb_(R[16] + -110);  /* 0x8008D770 */
    R[4] = R[0] + R[0];  /* 0x8008D774 */
    sb_(R[16] + -3, R[0]);  /* 0x8008D778 */
    sh_(R[16] + -166, R[0]);  /* 0x8008D77C */
    R[5] = R[2] + R[0];  /* 0x8008D780 */
    { R[31] = 0x8008D78Cu; sh_(R[16] + -164, R[2]); psx_next = 0x8009334Cu; return; }  /* 0x8008D784 jal */
    R[4] = R[17] + R[0];  /* 0x8008D78C */
    { R[31] = 0x8008D798u; sw_(R[16] + -118, R[2]); psx_next = 0x8008D2A4u; return; }  /* 0x8008D790 jal */
    { goto L_8008D87C; }  /* 0x8008D798 j */
    R[2] = lb_(R[16] + -7);  /* 0x8008D7A0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D7D0; } }  /* 0x8008D7A8 */
    R[2] = lb_(R[16] + -105);  /* 0x8008D7B0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008D7C8; } }  /* 0x8008D7B8 */
    { sb_(R[16] + -3, R[2]); goto L_8008D87C; }  /* 0x8008D7C0 j */
L_8008D7C8:;
    { sb_(R[16] + -7, R[0]); goto L_8008D87C; }  /* 0x8008D7C8 j */
L_8008D7D0:;
    R[2] = lb_(R[16] + -4);  /* 0x8008D7D0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D808; } }  /* 0x8008D7D8 */
    { uint32_t _c = (R[2] == R[18]); if (_c) { goto L_8008D858; } }  /* 0x8008D7E0 */
    R[2] = lb_(R[16] + -104);  /* 0x8008D7E8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8008D800; } }  /* 0x8008D7F0 */
    { sb_(R[16] + -3, R[2]); goto L_8008D87C; }  /* 0x8008D7F8 j */
L_8008D800:;
    { sb_(R[16] + -4, R[0]); goto L_8008D87C; }  /* 0x8008D800 j */
L_8008D808:;
    R[2] = lb_(R[16] + -1);  /* 0x8008D808 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D87C; } }  /* 0x8008D810 */
    R[2] = lb_(R[16] + -103);  /* 0x8008D818 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008D834; } }  /* 0x8008D820 */
    sb_(R[16] + -3, R[18]);  /* 0x8008D828 */
    { sb_(R[16] + -1, R[2]); goto L_8008D87C; }  /* 0x8008D82C j */
L_8008D834:;
    { sb_(R[16] + -1, R[0]); goto L_8008D87C; }  /* 0x8008D834 j */
    R[2] = lb_(R[16] + -7);  /* 0x8008D83C */
    { goto L_8008D86C; }  /* 0x8008D840 j */
    R[2] = lb_(R[16] + -4);  /* 0x8008D848 */
    { uint32_t _c = (R[2] != R[18]); if (_c) { goto L_8008D87C; } }  /* 0x8008D850 */
L_8008D858:;
    { R[31] = 0x8008D860u; R[4] = R[17] + R[0]; psx_next = 0x80088410u; return; }  /* 0x8008D858 jal */
    { goto L_8008D87C; }  /* 0x8008D860 j */
    R[2] = lb_(R[16] + -1);  /* 0x8008D868 */
L_8008D86C:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008D87C; } }  /* 0x8008D870 */
    sb_(R[16] + -3, R[0]);  /* 0x8008D878 */
L_8008D87C:;
    R[3] = (uint32_t)(int16_t)lh_(R[16] + -166);  /* 0x8008D87C */
    R[2] = R[0] + 1;  /* 0x8008D880 */
    { uint32_t _c = (R[3] == R[2]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_8008D924; } }  /* 0x8008D884 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8A4; } }  /* 0x8008D88C */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_8008D8B4; } }  /* 0x8008D894 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D89C j extern */
L_8008D8A4:;
    { uint32_t _c = (R[3] == R[18]); if (_c) { goto L_8008D930; } }  /* 0x8008D8A4 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8AC j extern */
L_8008D8B4:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D8B4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8EC; } }  /* 0x8008D8BC */
    R[2] = lb_(R[16] + -109);  /* 0x8008D8C4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D8E4; } }  /* 0x8008D8CC */
    { R[31] = 0x8008D8DCu; R[5] = R[0] + 1; psx_next = 0x8008D660u; return; }  /* 0x8008D8D4 jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8DC j extern */
L_8008D8E4:;
    { sb_(R[16] + -6, R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D8E4 j extern */
L_8008D8EC:;
    R[2] = lb_(R[16]);  /* 0x8008D8EC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008D948u; return; } }  /* 0x8008D8F4 b extern */
    R[2] = lb_(R[16] + -107);  /* 0x8008D8FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D91C; } }  /* 0x8008D904 */
    { R[31] = 0x8008D914u; R[5] = R[0] + 3; psx_next = 0x8008D660u; return; }  /* 0x8008D90C jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D914 j extern */
L_8008D91C:;
    { sb_(R[16], R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D91C j extern */
L_8008D924:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D924 */
    { goto L_8008D934; }  /* 0x8008D928 j */
L_8008D930:;
    R[2] = lb_(R[16]);  /* 0x8008D930 */
L_8008D934:;
    psx_next = 0x8008D938u; return;  /* fallthrough */
}

void g0_8008D78C(void) {
    R[4] = R[17] + R[0];  /* 0x8008D78C */
    { R[31] = 0x8008D798u; sw_(R[16] + -118, R[2]); psx_next = 0x8008D2A4u; return; }  /* 0x8008D790 jal */
    { goto L_8008D87C; }  /* 0x8008D798 j */
    R[2] = lb_(R[16] + -7);  /* 0x8008D7A0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D7D0; } }  /* 0x8008D7A8 */
    R[2] = lb_(R[16] + -105);  /* 0x8008D7B0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008D7C8; } }  /* 0x8008D7B8 */
    { sb_(R[16] + -3, R[2]); goto L_8008D87C; }  /* 0x8008D7C0 j */
L_8008D7C8:;
    { sb_(R[16] + -7, R[0]); goto L_8008D87C; }  /* 0x8008D7C8 j */
L_8008D7D0:;
    R[2] = lb_(R[16] + -4);  /* 0x8008D7D0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D808; } }  /* 0x8008D7D8 */
    { uint32_t _c = (R[2] == R[18]); if (_c) { goto L_8008D858; } }  /* 0x8008D7E0 */
    R[2] = lb_(R[16] + -104);  /* 0x8008D7E8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8008D800; } }  /* 0x8008D7F0 */
    { sb_(R[16] + -3, R[2]); goto L_8008D87C; }  /* 0x8008D7F8 j */
L_8008D800:;
    { sb_(R[16] + -4, R[0]); goto L_8008D87C; }  /* 0x8008D800 j */
L_8008D808:;
    R[2] = lb_(R[16] + -1);  /* 0x8008D808 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D87C; } }  /* 0x8008D810 */
    R[2] = lb_(R[16] + -103);  /* 0x8008D818 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008D834; } }  /* 0x8008D820 */
    sb_(R[16] + -3, R[18]);  /* 0x8008D828 */
    { sb_(R[16] + -1, R[2]); goto L_8008D87C; }  /* 0x8008D82C j */
L_8008D834:;
    { sb_(R[16] + -1, R[0]); goto L_8008D87C; }  /* 0x8008D834 j */
    R[2] = lb_(R[16] + -7);  /* 0x8008D83C */
    { goto L_8008D86C; }  /* 0x8008D840 j */
    R[2] = lb_(R[16] + -4);  /* 0x8008D848 */
    { uint32_t _c = (R[2] != R[18]); if (_c) { goto L_8008D87C; } }  /* 0x8008D850 */
L_8008D858:;
    { R[31] = 0x8008D860u; R[4] = R[17] + R[0]; psx_next = 0x80088410u; return; }  /* 0x8008D858 jal */
    { goto L_8008D87C; }  /* 0x8008D860 j */
    R[2] = lb_(R[16] + -1);  /* 0x8008D868 */
L_8008D86C:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008D87C; } }  /* 0x8008D870 */
    sb_(R[16] + -3, R[0]);  /* 0x8008D878 */
L_8008D87C:;
    R[3] = (uint32_t)(int16_t)lh_(R[16] + -166);  /* 0x8008D87C */
    R[2] = R[0] + 1;  /* 0x8008D880 */
    { uint32_t _c = (R[3] == R[2]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_8008D924; } }  /* 0x8008D884 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8A4; } }  /* 0x8008D88C */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_8008D8B4; } }  /* 0x8008D894 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D89C j extern */
L_8008D8A4:;
    { uint32_t _c = (R[3] == R[18]); if (_c) { goto L_8008D930; } }  /* 0x8008D8A4 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8AC j extern */
L_8008D8B4:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D8B4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8EC; } }  /* 0x8008D8BC */
    R[2] = lb_(R[16] + -109);  /* 0x8008D8C4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D8E4; } }  /* 0x8008D8CC */
    { R[31] = 0x8008D8DCu; R[5] = R[0] + 1; psx_next = 0x8008D660u; return; }  /* 0x8008D8D4 jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8DC j extern */
L_8008D8E4:;
    { sb_(R[16] + -6, R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D8E4 j extern */
L_8008D8EC:;
    R[2] = lb_(R[16]);  /* 0x8008D8EC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008D948u; return; } }  /* 0x8008D8F4 b extern */
    R[2] = lb_(R[16] + -107);  /* 0x8008D8FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D91C; } }  /* 0x8008D904 */
    { R[31] = 0x8008D914u; R[5] = R[0] + 3; psx_next = 0x8008D660u; return; }  /* 0x8008D90C jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D914 j extern */
L_8008D91C:;
    { sb_(R[16], R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D91C j extern */
L_8008D924:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D924 */
    { goto L_8008D934; }  /* 0x8008D928 j */
L_8008D930:;
    R[2] = lb_(R[16]);  /* 0x8008D930 */
L_8008D934:;
    psx_next = 0x8008D938u; return;  /* fallthrough */
}

void g0_8008D798(void) {
    { goto L_8008D87C; }  /* 0x8008D798 j */
    R[2] = lb_(R[16] + -7);  /* 0x8008D7A0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D7D0; } }  /* 0x8008D7A8 */
    R[2] = lb_(R[16] + -105);  /* 0x8008D7B0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008D7C8; } }  /* 0x8008D7B8 */
    { sb_(R[16] + -3, R[2]); goto L_8008D87C; }  /* 0x8008D7C0 j */
L_8008D7C8:;
    { sb_(R[16] + -7, R[0]); goto L_8008D87C; }  /* 0x8008D7C8 j */
L_8008D7D0:;
    R[2] = lb_(R[16] + -4);  /* 0x8008D7D0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D808; } }  /* 0x8008D7D8 */
    { uint32_t _c = (R[2] == R[18]); if (_c) { goto L_8008D858; } }  /* 0x8008D7E0 */
    R[2] = lb_(R[16] + -104);  /* 0x8008D7E8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8008D800; } }  /* 0x8008D7F0 */
    { sb_(R[16] + -3, R[2]); goto L_8008D87C; }  /* 0x8008D7F8 j */
L_8008D800:;
    { sb_(R[16] + -4, R[0]); goto L_8008D87C; }  /* 0x8008D800 j */
L_8008D808:;
    R[2] = lb_(R[16] + -1);  /* 0x8008D808 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D87C; } }  /* 0x8008D810 */
    R[2] = lb_(R[16] + -103);  /* 0x8008D818 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008D834; } }  /* 0x8008D820 */
    sb_(R[16] + -3, R[18]);  /* 0x8008D828 */
    { sb_(R[16] + -1, R[2]); goto L_8008D87C; }  /* 0x8008D82C j */
L_8008D834:;
    { sb_(R[16] + -1, R[0]); goto L_8008D87C; }  /* 0x8008D834 j */
    R[2] = lb_(R[16] + -7);  /* 0x8008D83C */
    { goto L_8008D86C; }  /* 0x8008D840 j */
    R[2] = lb_(R[16] + -4);  /* 0x8008D848 */
    { uint32_t _c = (R[2] != R[18]); if (_c) { goto L_8008D87C; } }  /* 0x8008D850 */
L_8008D858:;
    { R[31] = 0x8008D860u; R[4] = R[17] + R[0]; psx_next = 0x80088410u; return; }  /* 0x8008D858 jal */
    { goto L_8008D87C; }  /* 0x8008D860 j */
    R[2] = lb_(R[16] + -1);  /* 0x8008D868 */
L_8008D86C:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008D87C; } }  /* 0x8008D870 */
    sb_(R[16] + -3, R[0]);  /* 0x8008D878 */
L_8008D87C:;
    R[3] = (uint32_t)(int16_t)lh_(R[16] + -166);  /* 0x8008D87C */
    R[2] = R[0] + 1;  /* 0x8008D880 */
    { uint32_t _c = (R[3] == R[2]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_8008D924; } }  /* 0x8008D884 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8A4; } }  /* 0x8008D88C */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_8008D8B4; } }  /* 0x8008D894 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D89C j extern */
L_8008D8A4:;
    { uint32_t _c = (R[3] == R[18]); if (_c) { goto L_8008D930; } }  /* 0x8008D8A4 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8AC j extern */
L_8008D8B4:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D8B4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8EC; } }  /* 0x8008D8BC */
    R[2] = lb_(R[16] + -109);  /* 0x8008D8C4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D8E4; } }  /* 0x8008D8CC */
    { R[31] = 0x8008D8DCu; R[5] = R[0] + 1; psx_next = 0x8008D660u; return; }  /* 0x8008D8D4 jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8DC j extern */
L_8008D8E4:;
    { sb_(R[16] + -6, R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D8E4 j extern */
L_8008D8EC:;
    R[2] = lb_(R[16]);  /* 0x8008D8EC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008D948u; return; } }  /* 0x8008D8F4 b extern */
    R[2] = lb_(R[16] + -107);  /* 0x8008D8FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D91C; } }  /* 0x8008D904 */
    { R[31] = 0x8008D914u; R[5] = R[0] + 3; psx_next = 0x8008D660u; return; }  /* 0x8008D90C jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D914 j extern */
L_8008D91C:;
    { sb_(R[16], R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D91C j extern */
L_8008D924:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D924 */
    { goto L_8008D934; }  /* 0x8008D928 j */
L_8008D930:;
    R[2] = lb_(R[16]);  /* 0x8008D930 */
L_8008D934:;
    psx_next = 0x8008D938u; return;  /* fallthrough */
}

void g0_8008D7A0(void) {
    R[2] = lb_(R[16] + -7);  /* 0x8008D7A0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D7D0; } }  /* 0x8008D7A8 */
    R[2] = lb_(R[16] + -105);  /* 0x8008D7B0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008D7C8; } }  /* 0x8008D7B8 */
    { sb_(R[16] + -3, R[2]); goto L_8008D87C; }  /* 0x8008D7C0 j */
L_8008D7C8:;
    { sb_(R[16] + -7, R[0]); goto L_8008D87C; }  /* 0x8008D7C8 j */
L_8008D7D0:;
    R[2] = lb_(R[16] + -4);  /* 0x8008D7D0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D808; } }  /* 0x8008D7D8 */
    { uint32_t _c = (R[2] == R[18]); if (_c) { goto L_8008D858; } }  /* 0x8008D7E0 */
    R[2] = lb_(R[16] + -104);  /* 0x8008D7E8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8008D800; } }  /* 0x8008D7F0 */
    { sb_(R[16] + -3, R[2]); goto L_8008D87C; }  /* 0x8008D7F8 j */
L_8008D800:;
    { sb_(R[16] + -4, R[0]); goto L_8008D87C; }  /* 0x8008D800 j */
L_8008D808:;
    R[2] = lb_(R[16] + -1);  /* 0x8008D808 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D87C; } }  /* 0x8008D810 */
    R[2] = lb_(R[16] + -103);  /* 0x8008D818 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8008D834; } }  /* 0x8008D820 */
    sb_(R[16] + -3, R[18]);  /* 0x8008D828 */
    { sb_(R[16] + -1, R[2]); goto L_8008D87C; }  /* 0x8008D82C j */
L_8008D834:;
    { sb_(R[16] + -1, R[0]); goto L_8008D87C; }  /* 0x8008D834 j */
    R[2] = lb_(R[16] + -7);  /* 0x8008D83C */
    { goto L_8008D86C; }  /* 0x8008D840 j */
    R[2] = lb_(R[16] + -4);  /* 0x8008D848 */
    { uint32_t _c = (R[2] != R[18]); if (_c) { goto L_8008D87C; } }  /* 0x8008D850 */
L_8008D858:;
    { R[31] = 0x8008D860u; R[4] = R[17] + R[0]; psx_next = 0x80088410u; return; }  /* 0x8008D858 jal */
    { goto L_8008D87C; }  /* 0x8008D860 j */
    R[2] = lb_(R[16] + -1);  /* 0x8008D868 */
L_8008D86C:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008D87C; } }  /* 0x8008D870 */
    sb_(R[16] + -3, R[0]);  /* 0x8008D878 */
L_8008D87C:;
    R[3] = (uint32_t)(int16_t)lh_(R[16] + -166);  /* 0x8008D87C */
    R[2] = R[0] + 1;  /* 0x8008D880 */
    { uint32_t _c = (R[3] == R[2]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_8008D924; } }  /* 0x8008D884 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8A4; } }  /* 0x8008D88C */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_8008D8B4; } }  /* 0x8008D894 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D89C j extern */
L_8008D8A4:;
    { uint32_t _c = (R[3] == R[18]); if (_c) { goto L_8008D930; } }  /* 0x8008D8A4 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8AC j extern */
L_8008D8B4:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D8B4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8EC; } }  /* 0x8008D8BC */
    R[2] = lb_(R[16] + -109);  /* 0x8008D8C4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D8E4; } }  /* 0x8008D8CC */
    { R[31] = 0x8008D8DCu; R[5] = R[0] + 1; psx_next = 0x8008D660u; return; }  /* 0x8008D8D4 jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8DC j extern */
L_8008D8E4:;
    { sb_(R[16] + -6, R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D8E4 j extern */
L_8008D8EC:;
    R[2] = lb_(R[16]);  /* 0x8008D8EC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008D948u; return; } }  /* 0x8008D8F4 b extern */
    R[2] = lb_(R[16] + -107);  /* 0x8008D8FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D91C; } }  /* 0x8008D904 */
    { R[31] = 0x8008D914u; R[5] = R[0] + 3; psx_next = 0x8008D660u; return; }  /* 0x8008D90C jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D914 j extern */
L_8008D91C:;
    { sb_(R[16], R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D91C j extern */
L_8008D924:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D924 */
    { goto L_8008D934; }  /* 0x8008D928 j */
L_8008D930:;
    R[2] = lb_(R[16]);  /* 0x8008D930 */
L_8008D934:;
    psx_next = 0x8008D938u; return;  /* fallthrough */
}

void g0_8008D83C(void) {
    R[2] = lb_(R[16] + -7);  /* 0x8008D83C */
    { goto L_8008D86C; }  /* 0x8008D840 j */
    R[2] = lb_(R[16] + -4);  /* 0x8008D848 */
    { uint32_t _c = (R[2] != R[18]); if (_c) { goto L_8008D87C; } }  /* 0x8008D850 */
    { R[31] = 0x8008D860u; R[4] = R[17] + R[0]; psx_next = 0x80088410u; return; }  /* 0x8008D858 jal */
    { goto L_8008D87C; }  /* 0x8008D860 j */
    R[2] = lb_(R[16] + -1);  /* 0x8008D868 */
L_8008D86C:;
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008D87C; } }  /* 0x8008D870 */
    sb_(R[16] + -3, R[0]);  /* 0x8008D878 */
L_8008D87C:;
    R[3] = (uint32_t)(int16_t)lh_(R[16] + -166);  /* 0x8008D87C */
    R[2] = R[0] + 1;  /* 0x8008D880 */
    { uint32_t _c = (R[3] == R[2]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_8008D924; } }  /* 0x8008D884 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8A4; } }  /* 0x8008D88C */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_8008D8B4; } }  /* 0x8008D894 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D89C j extern */
L_8008D8A4:;
    { uint32_t _c = (R[3] == R[18]); if (_c) { goto L_8008D930; } }  /* 0x8008D8A4 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8AC j extern */
L_8008D8B4:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D8B4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8EC; } }  /* 0x8008D8BC */
    R[2] = lb_(R[16] + -109);  /* 0x8008D8C4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D8E4; } }  /* 0x8008D8CC */
    { R[31] = 0x8008D8DCu; R[5] = R[0] + 1; psx_next = 0x8008D660u; return; }  /* 0x8008D8D4 jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8DC j extern */
L_8008D8E4:;
    { sb_(R[16] + -6, R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D8E4 j extern */
L_8008D8EC:;
    R[2] = lb_(R[16]);  /* 0x8008D8EC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008D948u; return; } }  /* 0x8008D8F4 b extern */
    R[2] = lb_(R[16] + -107);  /* 0x8008D8FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D91C; } }  /* 0x8008D904 */
    { R[31] = 0x8008D914u; R[5] = R[0] + 3; psx_next = 0x8008D660u; return; }  /* 0x8008D90C jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D914 j extern */
L_8008D91C:;
    { sb_(R[16], R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D91C j extern */
L_8008D924:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D924 */
    { goto L_8008D934; }  /* 0x8008D928 j */
L_8008D930:;
    R[2] = lb_(R[16]);  /* 0x8008D930 */
L_8008D934:;
    psx_next = 0x8008D938u; return;  /* fallthrough */
}

void g0_8008D848(void) {
    R[2] = lb_(R[16] + -4);  /* 0x8008D848 */
    { uint32_t _c = (R[2] != R[18]); if (_c) { goto L_8008D87C; } }  /* 0x8008D850 */
    { R[31] = 0x8008D860u; R[4] = R[17] + R[0]; psx_next = 0x80088410u; return; }  /* 0x8008D858 jal */
    { goto L_8008D87C; }  /* 0x8008D860 j */
    R[2] = lb_(R[16] + -1);  /* 0x8008D868 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008D87C; } }  /* 0x8008D870 */
    sb_(R[16] + -3, R[0]);  /* 0x8008D878 */
L_8008D87C:;
    R[3] = (uint32_t)(int16_t)lh_(R[16] + -166);  /* 0x8008D87C */
    R[2] = R[0] + 1;  /* 0x8008D880 */
    { uint32_t _c = (R[3] == R[2]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_8008D924; } }  /* 0x8008D884 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8A4; } }  /* 0x8008D88C */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_8008D8B4; } }  /* 0x8008D894 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D89C j extern */
L_8008D8A4:;
    { uint32_t _c = (R[3] == R[18]); if (_c) { goto L_8008D930; } }  /* 0x8008D8A4 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8AC j extern */
L_8008D8B4:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D8B4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8EC; } }  /* 0x8008D8BC */
    R[2] = lb_(R[16] + -109);  /* 0x8008D8C4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D8E4; } }  /* 0x8008D8CC */
    { R[31] = 0x8008D8DCu; R[5] = R[0] + 1; psx_next = 0x8008D660u; return; }  /* 0x8008D8D4 jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8DC j extern */
L_8008D8E4:;
    { sb_(R[16] + -6, R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D8E4 j extern */
L_8008D8EC:;
    R[2] = lb_(R[16]);  /* 0x8008D8EC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008D948u; return; } }  /* 0x8008D8F4 b extern */
    R[2] = lb_(R[16] + -107);  /* 0x8008D8FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D91C; } }  /* 0x8008D904 */
    { R[31] = 0x8008D914u; R[5] = R[0] + 3; psx_next = 0x8008D660u; return; }  /* 0x8008D90C jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D914 j extern */
L_8008D91C:;
    { sb_(R[16], R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D91C j extern */
L_8008D924:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D924 */
    { goto L_8008D934; }  /* 0x8008D928 j */
L_8008D930:;
    R[2] = lb_(R[16]);  /* 0x8008D930 */
L_8008D934:;
    psx_next = 0x8008D938u; return;  /* fallthrough */
}

void g0_8008D860(void) {
    { goto L_8008D87C; }  /* 0x8008D860 j */
    R[2] = lb_(R[16] + -1);  /* 0x8008D868 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008D87C; } }  /* 0x8008D870 */
    sb_(R[16] + -3, R[0]);  /* 0x8008D878 */
L_8008D87C:;
    R[3] = (uint32_t)(int16_t)lh_(R[16] + -166);  /* 0x8008D87C */
    R[2] = R[0] + 1;  /* 0x8008D880 */
    { uint32_t _c = (R[3] == R[2]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_8008D924; } }  /* 0x8008D884 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8A4; } }  /* 0x8008D88C */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_8008D8B4; } }  /* 0x8008D894 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D89C j extern */
L_8008D8A4:;
    { uint32_t _c = (R[3] == R[18]); if (_c) { goto L_8008D930; } }  /* 0x8008D8A4 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8AC j extern */
L_8008D8B4:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D8B4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8EC; } }  /* 0x8008D8BC */
    R[2] = lb_(R[16] + -109);  /* 0x8008D8C4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D8E4; } }  /* 0x8008D8CC */
    { R[31] = 0x8008D8DCu; R[5] = R[0] + 1; psx_next = 0x8008D660u; return; }  /* 0x8008D8D4 jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8DC j extern */
L_8008D8E4:;
    { sb_(R[16] + -6, R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D8E4 j extern */
L_8008D8EC:;
    R[2] = lb_(R[16]);  /* 0x8008D8EC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008D948u; return; } }  /* 0x8008D8F4 b extern */
    R[2] = lb_(R[16] + -107);  /* 0x8008D8FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D91C; } }  /* 0x8008D904 */
    { R[31] = 0x8008D914u; R[5] = R[0] + 3; psx_next = 0x8008D660u; return; }  /* 0x8008D90C jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D914 j extern */
L_8008D91C:;
    { sb_(R[16], R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D91C j extern */
L_8008D924:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D924 */
    { goto L_8008D934; }  /* 0x8008D928 j */
L_8008D930:;
    R[2] = lb_(R[16]);  /* 0x8008D930 */
L_8008D934:;
    psx_next = 0x8008D938u; return;  /* fallthrough */
}

void g0_8008D868(void) {
    R[2] = lb_(R[16] + -1);  /* 0x8008D868 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008D87C; } }  /* 0x8008D870 */
    sb_(R[16] + -3, R[0]);  /* 0x8008D878 */
L_8008D87C:;
    R[3] = (uint32_t)(int16_t)lh_(R[16] + -166);  /* 0x8008D87C */
    R[2] = R[0] + 1;  /* 0x8008D880 */
    { uint32_t _c = (R[3] == R[2]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_8008D924; } }  /* 0x8008D884 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8A4; } }  /* 0x8008D88C */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_8008D8B4; } }  /* 0x8008D894 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D89C j extern */
L_8008D8A4:;
    { uint32_t _c = (R[3] == R[18]); if (_c) { goto L_8008D930; } }  /* 0x8008D8A4 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8AC j extern */
L_8008D8B4:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D8B4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8EC; } }  /* 0x8008D8BC */
    R[2] = lb_(R[16] + -109);  /* 0x8008D8C4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D8E4; } }  /* 0x8008D8CC */
    { R[31] = 0x8008D8DCu; R[5] = R[0] + 1; psx_next = 0x8008D660u; return; }  /* 0x8008D8D4 jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8DC j extern */
L_8008D8E4:;
    { sb_(R[16] + -6, R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D8E4 j extern */
L_8008D8EC:;
    R[2] = lb_(R[16]);  /* 0x8008D8EC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008D948u; return; } }  /* 0x8008D8F4 b extern */
    R[2] = lb_(R[16] + -107);  /* 0x8008D8FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D91C; } }  /* 0x8008D904 */
    { R[31] = 0x8008D914u; R[5] = R[0] + 3; psx_next = 0x8008D660u; return; }  /* 0x8008D90C jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D914 j extern */
L_8008D91C:;
    { sb_(R[16], R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D91C j extern */
L_8008D924:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D924 */
    { goto L_8008D934; }  /* 0x8008D928 j */
L_8008D930:;
    R[2] = lb_(R[16]);  /* 0x8008D930 */
L_8008D934:;
    psx_next = 0x8008D938u; return;  /* fallthrough */
}

void g0_8008D87C(void) {
    R[3] = (uint32_t)(int16_t)lh_(R[16] + -166);  /* 0x8008D87C */
    R[2] = R[0] + 1;  /* 0x8008D880 */
    { uint32_t _c = (R[3] == R[2]); R[2] = ((int32_t)R[3] < 2); if (_c) { goto L_8008D924; } }  /* 0x8008D884 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8A4; } }  /* 0x8008D88C */
    { uint32_t _c = (R[3] == R[0]); if (_c) { goto L_8008D8B4; } }  /* 0x8008D894 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D89C j extern */
L_8008D8A4:;
    { uint32_t _c = (R[3] == R[18]); if (_c) { goto L_8008D930; } }  /* 0x8008D8A4 */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8AC j extern */
L_8008D8B4:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D8B4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008D8EC; } }  /* 0x8008D8BC */
    R[2] = lb_(R[16] + -109);  /* 0x8008D8C4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D8E4; } }  /* 0x8008D8CC */
    { R[31] = 0x8008D8DCu; R[5] = R[0] + 1; psx_next = 0x8008D660u; return; }  /* 0x8008D8D4 jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8DC j extern */
L_8008D8E4:;
    { sb_(R[16] + -6, R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D8E4 j extern */
L_8008D8EC:;
    R[2] = lb_(R[16]);  /* 0x8008D8EC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008D948u; return; } }  /* 0x8008D8F4 b extern */
    R[2] = lb_(R[16] + -107);  /* 0x8008D8FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D91C; } }  /* 0x8008D904 */
    { R[31] = 0x8008D914u; R[5] = R[0] + 3; psx_next = 0x8008D660u; return; }  /* 0x8008D90C jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D914 j extern */
L_8008D91C:;
    { sb_(R[16], R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D91C j extern */
L_8008D924:;
    R[2] = lb_(R[16] + -6);  /* 0x8008D924 */
    { goto L_8008D934; }  /* 0x8008D928 j */
L_8008D930:;
    R[2] = lb_(R[16]);  /* 0x8008D930 */
L_8008D934:;
    psx_next = 0x8008D938u; return;  /* fallthrough */
}

void g0_8008D8DC(void) {
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D8DC j extern */
    { sb_(R[16] + -6, R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D8E4 j extern */
    R[2] = lb_(R[16]);  /* 0x8008D8EC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008D948u; return; } }  /* 0x8008D8F4 b extern */
    R[2] = lb_(R[16] + -107);  /* 0x8008D8FC */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8008D91C; } }  /* 0x8008D904 */
    { R[31] = 0x8008D914u; R[5] = R[0] + 3; psx_next = 0x8008D660u; return; }  /* 0x8008D90C jal */
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D914 j extern */
L_8008D91C:;
    { sb_(R[16], R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D91C j extern */
    R[2] = lb_(R[16] + -6);  /* 0x8008D924 */
    { goto L_8008D934; }  /* 0x8008D928 j */
    R[2] = lb_(R[16]);  /* 0x8008D930 */
L_8008D934:;
    psx_next = 0x8008D938u; return;  /* fallthrough */
}

void g0_8008D914(void) {
    { R[19] = R[19] + 1; psx_next = 0x8008D94Cu; return; }  /* 0x8008D914 j extern */
    { sb_(R[16], R[0]); psx_next = 0x8008D948u; return; }  /* 0x8008D91C j extern */
    R[2] = lb_(R[16] + -6);  /* 0x8008D924 */
    { goto L_8008D934; }  /* 0x8008D928 j */
    R[2] = lb_(R[16]);  /* 0x8008D930 */
L_8008D934:;
    psx_next = 0x8008D938u; return;  /* fallthrough */
}

void g0_8008D938(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008D948; } }  /* 0x8008D938 */
    { R[31] = 0x8008D948u; R[4] = R[17] + R[0]; psx_next = 0x8008D6C8u; return; }  /* 0x8008D940 jal */
L_8008D948:;
    R[19] = R[19] + 1;  /* 0x8008D948 */
    R[16] = R[16] + 804;  /* 0x8008D94C */
    R[2] = R[0] + 60;  /* 0x8008D950 */
    { uint32_t _c = (R[19] != R[2]); R[17] = R[17] + 804; if (_c) { psx_next = 0x8008D728u; return; } }  /* 0x8008D954 b extern */
    R[31] = lw_(R[29] + 36);  /* 0x8008D95C */
    R[20] = lw_(R[29] + 32);  /* 0x8008D960 */
    R[19] = lw_(R[29] + 28);  /* 0x8008D964 */
    R[18] = lw_(R[29] + 24);  /* 0x8008D968 */
    R[17] = lw_(R[29] + 20);  /* 0x8008D96C */
    R[16] = lw_(R[29] + 16);  /* 0x8008D970 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8008D974 jr ra */
}

void g0_8008D948(void) {
    R[19] = R[19] + 1;  /* 0x8008D948 */
    R[16] = R[16] + 804;  /* 0x8008D94C */
    R[2] = R[0] + 60;  /* 0x8008D950 */
    { uint32_t _c = (R[19] != R[2]); R[17] = R[17] + 804; if (_c) { psx_next = 0x8008D728u; return; } }  /* 0x8008D954 b extern */
    R[31] = lw_(R[29] + 36);  /* 0x8008D95C */
    R[20] = lw_(R[29] + 32);  /* 0x8008D960 */
    R[19] = lw_(R[29] + 28);  /* 0x8008D964 */
    R[18] = lw_(R[29] + 24);  /* 0x8008D968 */
    R[17] = lw_(R[29] + 20);  /* 0x8008D96C */
    R[16] = lw_(R[29] + 16);  /* 0x8008D970 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8008D974 jr ra */
}

void g0_8008D94C(void) {
    R[16] = R[16] + 804;  /* 0x8008D94C */
    R[2] = R[0] + 60;  /* 0x8008D950 */
    { uint32_t _c = (R[19] != R[2]); R[17] = R[17] + 804; if (_c) { psx_next = 0x8008D728u; return; } }  /* 0x8008D954 b extern */
    R[31] = lw_(R[29] + 36);  /* 0x8008D95C */
    R[20] = lw_(R[29] + 32);  /* 0x8008D960 */
    R[19] = lw_(R[29] + 28);  /* 0x8008D964 */
    R[18] = lw_(R[29] + 24);  /* 0x8008D968 */
    R[17] = lw_(R[29] + 20);  /* 0x8008D96C */
    R[16] = lw_(R[29] + 16);  /* 0x8008D970 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8008D974 jr ra */
}

void g0_8008D97C(void) {
    R[29] = R[29] - 32;  /* 0x8008D97C */
    R[4] = R[0] + 1;  /* 0x8008D980 */
    sw_(R[29] + 28, R[31]);  /* 0x8008D984 */
    sw_(R[29] + 24, R[18]);  /* 0x8008D988 */
    sw_(R[29] + 20, R[17]);  /* 0x8008D98C */
    { R[31] = 0x8008D998u; sw_(R[29] + 16, R[16]); psx_next = 0x80037D98u; return; }  /* 0x8008D990 jal */
    R[3] = 0x800Fu << 16;  /* 0x8008D998 */
    R[3] = lw_(R[3] + 25120);  /* 0x8008D99C */
    R[18] = R[2] + R[0];  /* 0x8008D9A0 */
    R[2] = R[3] & 0x44;  /* 0x8008D9A4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x8; if (_c) { goto L_8008D9D8; } }  /* 0x8008D9A8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008D9D8; } }  /* 0x8008D9B0 */
    { R[31] = 0x8008D9C0u; R[16] = 0x8012u << 16; psx_next = 0x800A2760u; return; }  /* 0x8008D9B8 jal */
    { R[31] = 0x8008D9C8u; R[16] = R[16] - 26864; psx_next = 0x800A14A8u; return; }  /* 0x8008D9C0 jal */
    { R[31] = 0x8008D9D0u; R[4] = R[16] + R[0]; psx_next = 0x8009C658u; return; }  /* 0x8008D9C8 jal */
    { R[31] = 0x8008D9D8u; R[4] = R[16] + R[0]; psx_next = 0x80092014u; return; }  /* 0x8008D9D0 jal */
L_8008D9D8:;
    { R[31] = 0x8008D9E0u; R[16] = 0x1F80u << 16; psx_next = 0x80088760u; return; }  /* 0x8008D9D8 jal */
    { R[31] = 0x8008D9E8u; psx_next = 0x8008D6F0u; return; }  /* 0x8008D9E0 jal */
    R[8] = R[0] + R[0];  /* 0x8008D9E8 */
    R[7] = R[8] + R[0];  /* 0x8008D9EC */
    R[2] = 0x8012u << 16;  /* 0x8008D9F0 */
    R[5] = R[2] - 26864;  /* 0x8008D9F4 */
    R[10] = R[0] + 5;  /* 0x8008D9F8 */
    psx_next = 0x8008D9FCu; return;  /* fallthrough */
}

void g0_8008D998(void) {
    R[3] = 0x800Fu << 16;  /* 0x8008D998 */
    R[3] = lw_(R[3] + 25120);  /* 0x8008D99C */
    R[18] = R[2] + R[0];  /* 0x8008D9A0 */
    R[2] = R[3] & 0x44;  /* 0x8008D9A4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x8; if (_c) { goto L_8008D9D8; } }  /* 0x8008D9A8 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008D9D8; } }  /* 0x8008D9B0 */
    { R[31] = 0x8008D9C0u; R[16] = 0x8012u << 16; psx_next = 0x800A2760u; return; }  /* 0x8008D9B8 jal */
    { R[31] = 0x8008D9C8u; R[16] = R[16] - 26864; psx_next = 0x800A14A8u; return; }  /* 0x8008D9C0 jal */
    { R[31] = 0x8008D9D0u; R[4] = R[16] + R[0]; psx_next = 0x8009C658u; return; }  /* 0x8008D9C8 jal */
    { R[31] = 0x8008D9D8u; R[4] = R[16] + R[0]; psx_next = 0x80092014u; return; }  /* 0x8008D9D0 jal */
L_8008D9D8:;
    { R[31] = 0x8008D9E0u; R[16] = 0x1F80u << 16; psx_next = 0x80088760u; return; }  /* 0x8008D9D8 jal */
    { R[31] = 0x8008D9E8u; psx_next = 0x8008D6F0u; return; }  /* 0x8008D9E0 jal */
    R[8] = R[0] + R[0];  /* 0x8008D9E8 */
    R[7] = R[8] + R[0];  /* 0x8008D9EC */
    R[2] = 0x8012u << 16;  /* 0x8008D9F0 */
    R[5] = R[2] - 26864;  /* 0x8008D9F4 */
    R[10] = R[0] + 5;  /* 0x8008D9F8 */
    psx_next = 0x8008D9FCu; return;  /* fallthrough */
}

void g0_8008D9C0(void) {
    { R[31] = 0x8008D9C8u; R[16] = R[16] - 26864; psx_next = 0x800A14A8u; return; }  /* 0x8008D9C0 jal */
    { R[31] = 0x8008D9D0u; R[4] = R[16] + R[0]; psx_next = 0x8009C658u; return; }  /* 0x8008D9C8 jal */
    { R[31] = 0x8008D9D8u; R[4] = R[16] + R[0]; psx_next = 0x80092014u; return; }  /* 0x8008D9D0 jal */
    { R[31] = 0x8008D9E0u; R[16] = 0x1F80u << 16; psx_next = 0x80088760u; return; }  /* 0x8008D9D8 jal */
    { R[31] = 0x8008D9E8u; psx_next = 0x8008D6F0u; return; }  /* 0x8008D9E0 jal */
    R[8] = R[0] + R[0];  /* 0x8008D9E8 */
    R[7] = R[8] + R[0];  /* 0x8008D9EC */
    R[2] = 0x8012u << 16;  /* 0x8008D9F0 */
    R[5] = R[2] - 26864;  /* 0x8008D9F4 */
    R[10] = R[0] + 5;  /* 0x8008D9F8 */
    psx_next = 0x8008D9FCu; return;  /* fallthrough */
}

void g0_8008D9C8(void) {
    { R[31] = 0x8008D9D0u; R[4] = R[16] + R[0]; psx_next = 0x8009C658u; return; }  /* 0x8008D9C8 jal */
    { R[31] = 0x8008D9D8u; R[4] = R[16] + R[0]; psx_next = 0x80092014u; return; }  /* 0x8008D9D0 jal */
    { R[31] = 0x8008D9E0u; R[16] = 0x1F80u << 16; psx_next = 0x80088760u; return; }  /* 0x8008D9D8 jal */
    { R[31] = 0x8008D9E8u; psx_next = 0x8008D6F0u; return; }  /* 0x8008D9E0 jal */
    R[8] = R[0] + R[0];  /* 0x8008D9E8 */
    R[7] = R[8] + R[0];  /* 0x8008D9EC */
    R[2] = 0x8012u << 16;  /* 0x8008D9F0 */
    R[5] = R[2] - 26864;  /* 0x8008D9F4 */
    R[10] = R[0] + 5;  /* 0x8008D9F8 */
    psx_next = 0x8008D9FCu; return;  /* fallthrough */
}

void g0_8008D9D0(void) {
    { R[31] = 0x8008D9D8u; R[4] = R[16] + R[0]; psx_next = 0x80092014u; return; }  /* 0x8008D9D0 jal */
    { R[31] = 0x8008D9E0u; R[16] = 0x1F80u << 16; psx_next = 0x80088760u; return; }  /* 0x8008D9D8 jal */
    { R[31] = 0x8008D9E8u; psx_next = 0x8008D6F0u; return; }  /* 0x8008D9E0 jal */
    R[8] = R[0] + R[0];  /* 0x8008D9E8 */
    R[7] = R[8] + R[0];  /* 0x8008D9EC */
    R[2] = 0x8012u << 16;  /* 0x8008D9F0 */
    R[5] = R[2] - 26864;  /* 0x8008D9F4 */
    R[10] = R[0] + 5;  /* 0x8008D9F8 */
    psx_next = 0x8008D9FCu; return;  /* fallthrough */
}

void g0_8008D9D8(void) {
    { R[31] = 0x8008D9E0u; R[16] = 0x1F80u << 16; psx_next = 0x80088760u; return; }  /* 0x8008D9D8 jal */
    { R[31] = 0x8008D9E8u; psx_next = 0x8008D6F0u; return; }  /* 0x8008D9E0 jal */
    R[8] = R[0] + R[0];  /* 0x8008D9E8 */
    R[7] = R[8] + R[0];  /* 0x8008D9EC */
    R[2] = 0x8012u << 16;  /* 0x8008D9F0 */
    R[5] = R[2] - 26864;  /* 0x8008D9F4 */
    R[10] = R[0] + 5;  /* 0x8008D9F8 */
    psx_next = 0x8008D9FCu; return;  /* fallthrough */
}

void g0_8008D9E0(void) {
    { R[31] = 0x8008D9E8u; psx_next = 0x8008D6F0u; return; }  /* 0x8008D9E0 jal */
    R[8] = R[0] + R[0];  /* 0x8008D9E8 */
    R[7] = R[8] + R[0];  /* 0x8008D9EC */
    R[2] = 0x8012u << 16;  /* 0x8008D9F0 */
    R[5] = R[2] - 26864;  /* 0x8008D9F4 */
    R[10] = R[0] + 5;  /* 0x8008D9F8 */
    psx_next = 0x8008D9FCu; return;  /* fallthrough */
}

void g0_8008D9E8(void) {
    R[8] = R[0] + R[0];  /* 0x8008D9E8 */
    R[7] = R[8] + R[0];  /* 0x8008D9EC */
    R[2] = 0x8012u << 16;  /* 0x8008D9F0 */
    R[5] = R[2] - 26864;  /* 0x8008D9F4 */
    R[10] = R[0] + 5;  /* 0x8008D9F8 */
    psx_next = 0x8008D9FCu; return;  /* fallthrough */
}

void g0_8008D9FC(void) {
    R[9] = R[0] + 60;  /* 0x8008D9FC */
    R[4] = R[5] + 791;  /* 0x8008DA00 */
    R[6] = R[16] + R[0];  /* 0x8008DA04 */
L_8008DA08:;
    R[2] = (uint32_t)(int16_t)lh_(R[5]);  /* 0x8008DA08 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008DA50; } }  /* 0x8008DA10 */
    R[3] = lb_(R[4] + -2);  /* 0x8008DA18 */
    R[2] = R[3] & 0x1;  /* 0x8008DA20 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { goto L_8008DA50; } }  /* 0x8008DA24 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8008DA50; } }  /* 0x8008DA2C */
    R[2] = lb_(R[4]);  /* 0x8008DA34 */
    { uint32_t _c = (R[2] == R[10]); if (_c) { goto L_8008DA50; } }  /* 0x8008DA3C */
    sw_(R[6] + 20, R[5]);  /* 0x8008DA44 */
    R[6] = R[6] + 4;  /* 0x8008DA48 */
    R[8] = R[8] + 1;  /* 0x8008DA4C */
L_8008DA50:;
    R[7] = R[7] + 1;  /* 0x8008DA50 */
    R[4] = R[4] + 804;  /* 0x8008DA54 */
    { uint32_t _c = (R[7] != R[9]); R[5] = R[5] + 804; if (_c) { psx_bb(); goto L_8008DA08; } }  /* 0x8008DA58 */
    R[4] = R[16] + R[0];  /* 0x8008DA60 */
    R[5] = R[0] + R[0];  /* 0x8008DA64 */
    { R[31] = 0x8008DA70u; sw_(R[16] + 16, R[8]); psx_next = 0x8008918Cu; return; }  /* 0x8008DA68 jal */
    { R[31] = 0x8008DA78u; R[4] = R[16] + R[0]; psx_next = 0x8009AD54u; return; }  /* 0x8008DA70 jal */
    R[4] = R[16] + R[0];  /* 0x8008DA78 */
    { R[31] = 0x8008DA84u; R[5] = R[0] + 1; psx_next = 0x8008918Cu; return; }  /* 0x8008DA7C jal */
    R[2] = 0x8013u << 16;  /* 0x8008DA84 */
    R[17] = R[2] - 29656;  /* 0x8008DA88 */
    R[4] = lw_(R[17] + 96);  /* 0x8008DA8C */
    { uint32_t _c = (R[4] == R[0]); if (_c) { goto L_8008DAA8; } }  /* 0x8008DA94 */
    { R[31] = 0x8008DAA4u; psx_next = 0x8008DDD0u; return; }  /* 0x8008DA9C jal */
    sw_(R[17] + 96, R[0]);  /* 0x8008DAA4 */
L_8008DAA8:;
    { R[31] = 0x8008DAB0u; R[4] = R[16] + R[0]; psx_next = 0x8008D450u; return; }  /* 0x8008DAA8 jal */
}

void g0_8008DA70(void) {
    { R[31] = 0x8008DA78u; R[4] = R[16] + R[0]; psx_next = 0x8009AD54u; return; }  /* 0x8008DA70 jal */
    R[4] = R[16] + R[0];  /* 0x8008DA78 */
    { R[31] = 0x8008DA84u; R[5] = R[0] + 1; psx_next = 0x8008918Cu; return; }  /* 0x8008DA7C jal */
    R[2] = 0x8013u << 16;  /* 0x8008DA84 */
    R[17] = R[2] - 29656;  /* 0x8008DA88 */
    R[4] = lw_(R[17] + 96);  /* 0x8008DA8C */
    { uint32_t _c = (R[4] == R[0]); if (_c) { goto L_8008DAA8; } }  /* 0x8008DA94 */
    { R[31] = 0x8008DAA4u; psx_next = 0x8008DDD0u; return; }  /* 0x8008DA9C jal */
    sw_(R[17] + 96, R[0]);  /* 0x8008DAA4 */
L_8008DAA8:;
    { R[31] = 0x8008DAB0u; R[4] = R[16] + R[0]; psx_next = 0x8008D450u; return; }  /* 0x8008DAA8 jal */
}

void g0_8008DA78(void) {
    R[4] = R[16] + R[0];  /* 0x8008DA78 */
    { R[31] = 0x8008DA84u; R[5] = R[0] + 1; psx_next = 0x8008918Cu; return; }  /* 0x8008DA7C jal */
    R[2] = 0x8013u << 16;  /* 0x8008DA84 */
    R[17] = R[2] - 29656;  /* 0x8008DA88 */
    R[4] = lw_(R[17] + 96);  /* 0x8008DA8C */
    { uint32_t _c = (R[4] == R[0]); if (_c) { goto L_8008DAA8; } }  /* 0x8008DA94 */
    { R[31] = 0x8008DAA4u; psx_next = 0x8008DDD0u; return; }  /* 0x8008DA9C jal */
    sw_(R[17] + 96, R[0]);  /* 0x8008DAA4 */
L_8008DAA8:;
    { R[31] = 0x8008DAB0u; R[4] = R[16] + R[0]; psx_next = 0x8008D450u; return; }  /* 0x8008DAA8 jal */
}

void g0_8008DA84(void) {
    R[2] = 0x8013u << 16;  /* 0x8008DA84 */
    R[17] = R[2] - 29656;  /* 0x8008DA88 */
    R[4] = lw_(R[17] + 96);  /* 0x8008DA8C */
    { uint32_t _c = (R[4] == R[0]); if (_c) { goto L_8008DAA8; } }  /* 0x8008DA94 */
    { R[31] = 0x8008DAA4u; psx_next = 0x8008DDD0u; return; }  /* 0x8008DA9C jal */
    sw_(R[17] + 96, R[0]);  /* 0x8008DAA4 */
L_8008DAA8:;
    { R[31] = 0x8008DAB0u; R[4] = R[16] + R[0]; psx_next = 0x8008D450u; return; }  /* 0x8008DAA8 jal */
}

void g0_8008DAA4(void) {
    sw_(R[17] + 96, R[0]);  /* 0x8008DAA4 */
    { R[31] = 0x8008DAB0u; R[4] = R[16] + R[0]; psx_next = 0x8008D450u; return; }  /* 0x8008DAA8 jal */
}

void g0_8008DAAC(void) {
    R[4] = R[16] + R[0];  /* 0x8008DAAC */
    { R[31] = 0x8008DAB8u; R[4] = R[16] + R[0]; psx_next = 0x8008D138u; return; }  /* 0x8008DAB0 jal */
    { R[31] = 0x8008DAC0u; R[4] = R[16] + R[0]; psx_next = 0x8008994Cu; return; }  /* 0x8008DAB8 jal */
    { R[31] = 0x8008DAC8u; R[4] = R[16] + R[0]; psx_next = 0x800AD2A8u; return; }  /* 0x8008DAC0 jal */
    { R[31] = 0x8008DAD0u; psx_next = 0x8008C0D0u; return; }  /* 0x8008DAC8 jal */
    { R[31] = 0x8008DAD8u; R[4] = R[0] + 1; psx_next = 0x80037D98u; return; }  /* 0x8008DAD0 jal */
    R[2] = R[2] - R[18];  /* 0x8008DAD8 */
    R[31] = lw_(R[29] + 28);  /* 0x8008DADC */
    R[18] = lw_(R[29] + 24);  /* 0x8008DAE0 */
    R[17] = lw_(R[29] + 20);  /* 0x8008DAE4 */
    R[16] = lw_(R[29] + 16);  /* 0x8008DAE8 */
    R[3] = 0x800Fu << 16;  /* 0x8008DAEC */
    sw_(R[3] + 25144, R[2]);  /* 0x8008DAF0 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008DAF4 jr ra */
}

void g0_8008DAB0(void) {
    { R[31] = 0x8008DAB8u; R[4] = R[16] + R[0]; psx_next = 0x8008D138u; return; }  /* 0x8008DAB0 jal */
    { R[31] = 0x8008DAC0u; R[4] = R[16] + R[0]; psx_next = 0x8008994Cu; return; }  /* 0x8008DAB8 jal */
    { R[31] = 0x8008DAC8u; R[4] = R[16] + R[0]; psx_next = 0x800AD2A8u; return; }  /* 0x8008DAC0 jal */
    { R[31] = 0x8008DAD0u; psx_next = 0x8008C0D0u; return; }  /* 0x8008DAC8 jal */
    { R[31] = 0x8008DAD8u; R[4] = R[0] + 1; psx_next = 0x80037D98u; return; }  /* 0x8008DAD0 jal */
    R[2] = R[2] - R[18];  /* 0x8008DAD8 */
    R[31] = lw_(R[29] + 28);  /* 0x8008DADC */
    R[18] = lw_(R[29] + 24);  /* 0x8008DAE0 */
    R[17] = lw_(R[29] + 20);  /* 0x8008DAE4 */
    R[16] = lw_(R[29] + 16);  /* 0x8008DAE8 */
    R[3] = 0x800Fu << 16;  /* 0x8008DAEC */
    sw_(R[3] + 25144, R[2]);  /* 0x8008DAF0 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008DAF4 jr ra */
}

void g0_8008DAB8(void) {
    { R[31] = 0x8008DAC0u; R[4] = R[16] + R[0]; psx_next = 0x8008994Cu; return; }  /* 0x8008DAB8 jal */
    { R[31] = 0x8008DAC8u; R[4] = R[16] + R[0]; psx_next = 0x800AD2A8u; return; }  /* 0x8008DAC0 jal */
    { R[31] = 0x8008DAD0u; psx_next = 0x8008C0D0u; return; }  /* 0x8008DAC8 jal */
    { R[31] = 0x8008DAD8u; R[4] = R[0] + 1; psx_next = 0x80037D98u; return; }  /* 0x8008DAD0 jal */
    R[2] = R[2] - R[18];  /* 0x8008DAD8 */
    R[31] = lw_(R[29] + 28);  /* 0x8008DADC */
    R[18] = lw_(R[29] + 24);  /* 0x8008DAE0 */
    R[17] = lw_(R[29] + 20);  /* 0x8008DAE4 */
    R[16] = lw_(R[29] + 16);  /* 0x8008DAE8 */
    R[3] = 0x800Fu << 16;  /* 0x8008DAEC */
    sw_(R[3] + 25144, R[2]);  /* 0x8008DAF0 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008DAF4 jr ra */
}

void g0_8008DAC0(void) {
    { R[31] = 0x8008DAC8u; R[4] = R[16] + R[0]; psx_next = 0x800AD2A8u; return; }  /* 0x8008DAC0 jal */
    { R[31] = 0x8008DAD0u; psx_next = 0x8008C0D0u; return; }  /* 0x8008DAC8 jal */
    { R[31] = 0x8008DAD8u; R[4] = R[0] + 1; psx_next = 0x80037D98u; return; }  /* 0x8008DAD0 jal */
    R[2] = R[2] - R[18];  /* 0x8008DAD8 */
    R[31] = lw_(R[29] + 28);  /* 0x8008DADC */
    R[18] = lw_(R[29] + 24);  /* 0x8008DAE0 */
    R[17] = lw_(R[29] + 20);  /* 0x8008DAE4 */
    R[16] = lw_(R[29] + 16);  /* 0x8008DAE8 */
    R[3] = 0x800Fu << 16;  /* 0x8008DAEC */
    sw_(R[3] + 25144, R[2]);  /* 0x8008DAF0 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008DAF4 jr ra */
}

void g0_8008DAC8(void) {
    { R[31] = 0x8008DAD0u; psx_next = 0x8008C0D0u; return; }  /* 0x8008DAC8 jal */
    { R[31] = 0x8008DAD8u; R[4] = R[0] + 1; psx_next = 0x80037D98u; return; }  /* 0x8008DAD0 jal */
    R[2] = R[2] - R[18];  /* 0x8008DAD8 */
    R[31] = lw_(R[29] + 28);  /* 0x8008DADC */
    R[18] = lw_(R[29] + 24);  /* 0x8008DAE0 */
    R[17] = lw_(R[29] + 20);  /* 0x8008DAE4 */
    R[16] = lw_(R[29] + 16);  /* 0x8008DAE8 */
    R[3] = 0x800Fu << 16;  /* 0x8008DAEC */
    sw_(R[3] + 25144, R[2]);  /* 0x8008DAF0 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008DAF4 jr ra */
}

void g0_8008DAD0(void) {
    { R[31] = 0x8008DAD8u; R[4] = R[0] + 1; psx_next = 0x80037D98u; return; }  /* 0x8008DAD0 jal */
    R[2] = R[2] - R[18];  /* 0x8008DAD8 */
    R[31] = lw_(R[29] + 28);  /* 0x8008DADC */
    R[18] = lw_(R[29] + 24);  /* 0x8008DAE0 */
    R[17] = lw_(R[29] + 20);  /* 0x8008DAE4 */
    R[16] = lw_(R[29] + 16);  /* 0x8008DAE8 */
    R[3] = 0x800Fu << 16;  /* 0x8008DAEC */
    sw_(R[3] + 25144, R[2]);  /* 0x8008DAF0 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008DAF4 jr ra */
}

void g0_8008DAD8(void) {
    R[2] = R[2] - R[18];  /* 0x8008DAD8 */
    R[31] = lw_(R[29] + 28);  /* 0x8008DADC */
    R[18] = lw_(R[29] + 24);  /* 0x8008DAE0 */
    R[17] = lw_(R[29] + 20);  /* 0x8008DAE4 */
    R[16] = lw_(R[29] + 16);  /* 0x8008DAE8 */
    R[3] = 0x800Fu << 16;  /* 0x8008DAEC */
    sw_(R[3] + 25144, R[2]);  /* 0x8008DAF0 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8008DAF4 jr ra */
}

void g0_8008DAFC(void) {
    R[3] = lw_(R[4] + 472);  /* 0x8008DAFC */
    R[2] = lw_(R[5] + 472);  /* 0x8008DB00 */
    R[6] = R[3] - R[2];  /* 0x8008DB08 */
    { uint32_t _c = ((int32_t)R[6] < 0); R[2] = R[0] - R[6]; if (_c) { psx_next = 0x8008DB48u; return; } }  /* 0x8008DB0C b extern */
    R[2] = lw_(R[5] + 484);  /* 0x8008DB14 */
    R[2] = ((int32_t)R[6] < (int32_t)R[2]);  /* 0x8008DB1C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008DB54u; return; } }  /* 0x8008DB20 b extern */
    R[3] = lw_(R[4] + 32);  /* 0x8008DB28 */
    R[4] = lw_(R[5] + 32);  /* 0x8008DB2C */
    R[3] = ((int32_t)R[3] < (int32_t)R[4]);  /* 0x8008DB34 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 384; if (_c) { psx_next = 0x8008DBA0u; return; } }  /* 0x8008DB38 b extern */
    { R[2] = R[0] + 128; psx_next = R[31]; return; }  /* 0x8008DB40 jr ra */
}

void g0_8008DB20(void) {
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008DB54u; return; } }  /* 0x8008DB20 b extern */
    R[3] = lw_(R[4] + 32);  /* 0x8008DB28 */
    R[4] = lw_(R[5] + 32);  /* 0x8008DB2C */
    R[3] = ((int32_t)R[3] < (int32_t)R[4]);  /* 0x8008DB34 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 384; if (_c) { psx_next = 0x8008DBA0u; return; } }  /* 0x8008DB38 b extern */
    { R[2] = R[0] + 128; psx_next = R[31]; return; }  /* 0x8008DB40 jr ra */
}

void g0_8008DB48(void) {
    R[3] = lw_(R[4] + 484);  /* 0x8008DB48 */
    { R[2] = ((int32_t)R[2] < (int32_t)R[3]); psx_next = 0x8008DB20u; return; }  /* 0x8008DB4C j extern */
    R[2] = lw_(R[4] + 480);  /* 0x8008DB54 */
    R[3] = lw_(R[5] + 480);  /* 0x8008DB58 */
    R[2] = R[2] - R[3];  /* 0x8008DB60 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008DB88; } }  /* 0x8008DB64 */
    R[2] = lw_(R[4] + 24);  /* 0x8008DB6C */
    R[3] = lw_(R[5] + 24);  /* 0x8008DB70 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8008DB78 */
    R[2] = R[2] ^ 0x1;  /* 0x8008DB7C */
    { R[2] = R[2] << 8; psx_next = R[31]; return; }  /* 0x8008DB80 jr ra */
L_8008DB88:;
    R[2] = lw_(R[4] + 24);  /* 0x8008DB88 */
    R[3] = lw_(R[5] + 24);  /* 0x8008DB8C */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8008DB94 */
    R[2] = R[2] ^ 0x1;  /* 0x8008DB98 */
    R[2] = R[2] << 8;  /* 0x8008DB9C */
    { psx_next = R[31]; return; }  /* 0x8008DBA0 jr ra */
}

void g0_8008DB54(void) {
    R[2] = lw_(R[4] + 480);  /* 0x8008DB54 */
    R[3] = lw_(R[5] + 480);  /* 0x8008DB58 */
    R[2] = R[2] - R[3];  /* 0x8008DB60 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8008DB88; } }  /* 0x8008DB64 */
    R[2] = lw_(R[4] + 24);  /* 0x8008DB6C */
    R[3] = lw_(R[5] + 24);  /* 0x8008DB70 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8008DB78 */
    R[2] = R[2] ^ 0x1;  /* 0x8008DB7C */
    { R[2] = R[2] << 8; psx_next = R[31]; return; }  /* 0x8008DB80 jr ra */
L_8008DB88:;
    R[2] = lw_(R[4] + 24);  /* 0x8008DB88 */
    R[3] = lw_(R[5] + 24);  /* 0x8008DB8C */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8008DB94 */
    R[2] = R[2] ^ 0x1;  /* 0x8008DB98 */
    R[2] = R[2] << 8;  /* 0x8008DB9C */
    { psx_next = R[31]; return; }  /* 0x8008DBA0 jr ra */
}

void g0_8008DBA0(void) {
    { psx_next = R[31]; return; }  /* 0x8008DBA0 jr ra */
}

void g0_8008DBA8(void) {
    R[3] = lw_(R[4] + 472);  /* 0x8008DBA8 */
    R[2] = lw_(R[5] + 472);  /* 0x8008DBAC */
    R[6] = R[3] - R[2];  /* 0x8008DBB4 */
    { uint32_t _c = ((int32_t)R[6] < 0); R[2] = R[0] - R[6]; if (_c) { psx_next = 0x8008DBF4u; return; } }  /* 0x8008DBB8 b extern */
    R[2] = lw_(R[5] + 484);  /* 0x8008DBC0 */
    R[2] = ((int32_t)R[6] < (int32_t)R[2]);  /* 0x8008DBC8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008DC00u; return; } }  /* 0x8008DBCC b extern */
    R[3] = lw_(R[4] + 32);  /* 0x8008DBD4 */
    R[4] = lw_(R[5] + 32);  /* 0x8008DBD8 */
    R[3] = ((int32_t)R[3] < (int32_t)R[4]);  /* 0x8008DBE0 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 384; if (_c) { psx_next = 0x8008DC58u; return; } }  /* 0x8008DBE4 b extern */
    psx_next = 0x8008DBECu; return;  /* fallthrough */
}

void g0_8008DBCC(void) {
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008DC00u; return; } }  /* 0x8008DBCC b extern */
    R[3] = lw_(R[4] + 32);  /* 0x8008DBD4 */
    R[4] = lw_(R[5] + 32);  /* 0x8008DBD8 */
    R[3] = ((int32_t)R[3] < (int32_t)R[4]);  /* 0x8008DBE0 */
    { uint32_t _c = (R[3] == R[0]); R[2] = R[0] + 384; if (_c) { psx_next = 0x8008DC58u; return; } }  /* 0x8008DBE4 b extern */
    psx_next = 0x8008DBECu; return;  /* fallthrough */
}

void g0_8008DBEC(void) {
    { R[2] = R[0] + 128; psx_next = R[31]; return; }  /* 0x8008DBEC jr ra */
    R[3] = lw_(R[4] + 484);  /* 0x8008DBF4 */
    { R[2] = ((int32_t)R[2] < (int32_t)R[3]); psx_next = 0x8008DBCCu; return; }  /* 0x8008DBF8 j extern */
    R[3] = lw_(R[4] + 480);  /* 0x8008DC00 */
    R[2] = lw_(R[5] + 480);  /* 0x8008DC04 */
    R[6] = R[3] - R[2];  /* 0x8008DC0C */
    { uint32_t _c = ((int32_t)R[6] < 0); R[2] = R[0] - R[6]; if (_c) { goto L_8008DC48; } }  /* 0x8008DC10 */
    R[2] = lw_(R[5] + 492);  /* 0x8008DC18 */
    R[2] = ((int32_t)R[6] < (int32_t)R[2]);  /* 0x8008DC20 */
L_8008DC24:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008DC54; } }  /* 0x8008DC24 */
    R[2] = lw_(R[4] + 24);  /* 0x8008DC2C */
    R[3] = lw_(R[5] + 24);  /* 0x8008DC30 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8008DC38 */
    R[2] = R[2] ^ 0x1;  /* 0x8008DC3C */
    { R[2] = R[2] << 8; psx_next = R[31]; return; }  /* 0x8008DC40 jr ra */
L_8008DC48:;
    R[3] = lw_(R[4] + 492);  /* 0x8008DC48 */
    { R[2] = ((int32_t)R[2] < (int32_t)R[3]); psx_bb(); goto L_8008DC24; }  /* 0x8008DC4C j */
L_8008DC54:;
    R[2] = R[0] - 1;  /* 0x8008DC54 */
    { psx_next = R[31]; return; }  /* 0x8008DC58 jr ra */
}

void g0_8008DBF4(void) {
    R[3] = lw_(R[4] + 484);  /* 0x8008DBF4 */
    { R[2] = ((int32_t)R[2] < (int32_t)R[3]); psx_next = 0x8008DBCCu; return; }  /* 0x8008DBF8 j extern */
    R[3] = lw_(R[4] + 480);  /* 0x8008DC00 */
    R[2] = lw_(R[5] + 480);  /* 0x8008DC04 */
    R[6] = R[3] - R[2];  /* 0x8008DC0C */
    { uint32_t _c = ((int32_t)R[6] < 0); R[2] = R[0] - R[6]; if (_c) { goto L_8008DC48; } }  /* 0x8008DC10 */
    R[2] = lw_(R[5] + 492);  /* 0x8008DC18 */
    R[2] = ((int32_t)R[6] < (int32_t)R[2]);  /* 0x8008DC20 */
L_8008DC24:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008DC54; } }  /* 0x8008DC24 */
    R[2] = lw_(R[4] + 24);  /* 0x8008DC2C */
    R[3] = lw_(R[5] + 24);  /* 0x8008DC30 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8008DC38 */
    R[2] = R[2] ^ 0x1;  /* 0x8008DC3C */
    { R[2] = R[2] << 8; psx_next = R[31]; return; }  /* 0x8008DC40 jr ra */
L_8008DC48:;
    R[3] = lw_(R[4] + 492);  /* 0x8008DC48 */
    { R[2] = ((int32_t)R[2] < (int32_t)R[3]); psx_bb(); goto L_8008DC24; }  /* 0x8008DC4C j */
L_8008DC54:;
    R[2] = R[0] - 1;  /* 0x8008DC54 */
    { psx_next = R[31]; return; }  /* 0x8008DC58 jr ra */
}

void g0_8008DC00(void) {
    R[3] = lw_(R[4] + 480);  /* 0x8008DC00 */
    R[2] = lw_(R[5] + 480);  /* 0x8008DC04 */
    R[6] = R[3] - R[2];  /* 0x8008DC0C */
    { uint32_t _c = ((int32_t)R[6] < 0); R[2] = R[0] - R[6]; if (_c) { goto L_8008DC48; } }  /* 0x8008DC10 */
    R[2] = lw_(R[5] + 492);  /* 0x8008DC18 */
    R[2] = ((int32_t)R[6] < (int32_t)R[2]);  /* 0x8008DC20 */
L_8008DC24:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008DC54; } }  /* 0x8008DC24 */
    R[2] = lw_(R[4] + 24);  /* 0x8008DC2C */
    R[3] = lw_(R[5] + 24);  /* 0x8008DC30 */
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8008DC38 */
    R[2] = R[2] ^ 0x1;  /* 0x8008DC3C */
    { R[2] = R[2] << 8; psx_next = R[31]; return; }  /* 0x8008DC40 jr ra */
L_8008DC48:;
    R[3] = lw_(R[4] + 492);  /* 0x8008DC48 */
    { R[2] = ((int32_t)R[2] < (int32_t)R[3]); psx_bb(); goto L_8008DC24; }  /* 0x8008DC4C j */
L_8008DC54:;
    R[2] = R[0] - 1;  /* 0x8008DC54 */
    { psx_next = R[31]; return; }  /* 0x8008DC58 jr ra */
}

void g0_8008DC58(void) {
    { psx_next = R[31]; return; }  /* 0x8008DC58 jr ra */
}

void g0_8008DC60(void) {
    R[29] = R[29] - 24;  /* 0x8008DC60 */
    R[6] = R[5] + R[0];  /* 0x8008DC64 */
    sw_(R[29] + 16, R[31]);  /* 0x8008DC68 */
    R[3] = lw_(R[6] + 24);  /* 0x8008DC6C */
    R[2] = lw_(R[4] + 24);  /* 0x8008DC70 */
    R[5] = R[3] - R[2];  /* 0x8008DC78 */
    { uint32_t _c = ((int32_t)R[5] >= 0); if (_c) { goto L_8008DC88; } }  /* 0x8008DC7C */
    R[5] = R[5] + 4095;  /* 0x8008DC84 */
L_8008DC88:;
    R[3] = lw_(R[6] + 32);  /* 0x8008DC88 */
    R[2] = lw_(R[4] + 32);  /* 0x8008DC8C */
    R[3] = R[3] - R[2];  /* 0x8008DC94 */
    psx_next = 0x8008DC98u; return;  /* fallthrough */
}

void g0_8008DC98(void) {
    { uint32_t _c = ((int32_t)R[3] >= 0); R[5] = (uint32_t)((int32_t)R[5] >> 12); if (_c) { goto L_8008DCA4; } }  /* 0x8008DC98 */
    R[3] = R[3] + 4095;  /* 0x8008DCA0 */
L_8008DCA4:;
    { uint32_t _c = (R[5] != R[0]); R[4] = (uint32_t)((int32_t)R[3] >> 12); if (_c) { goto L_8008DCB4; } }  /* 0x8008DCA4 */
    { uint32_t _c = (R[4] == R[0]); R[2] = R[0] + 384; if (_c) { goto L_8008DCD0; } }  /* 0x8008DCAC */
L_8008DCB4:;
    { R[31] = 0x8008DCBCu; psx_next = 0x80037B38u; return; }  /* 0x8008DCB4 jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = R[2] + R[0]; if (_c) { goto L_8008DCC8; } }  /* 0x8008DCBC */
    R[3] = R[2] + 7;  /* 0x8008DCC4 */
L_8008DCC8:;
    R[2] = (uint32_t)((int32_t)R[3] >> 3);  /* 0x8008DCC8 */
    R[2] = R[2] & 0x1FF;  /* 0x8008DCCC */
L_8008DCD0:;
    R[31] = lw_(R[29] + 16);  /* 0x8008DCD0 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8008DCD8 jr ra */
}

void g0_8008DCBC(void) {
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = R[2] + R[0]; if (_c) { goto L_8008DCC8; } }  /* 0x8008DCBC */
    R[3] = R[2] + 7;  /* 0x8008DCC4 */
L_8008DCC8:;
    R[2] = (uint32_t)((int32_t)R[3] >> 3);  /* 0x8008DCC8 */
    R[2] = R[2] & 0x1FF;  /* 0x8008DCCC */
    R[31] = lw_(R[29] + 16);  /* 0x8008DCD0 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8008DCD8 jr ra */
}

void g0_8008DCE0(void) {
    R[29] = R[29] - 24;  /* 0x8008DCE0 */
    sw_(R[29] + 16, R[31]);  /* 0x8008DCE4 */
    R[6] = R[6] - R[4];  /* 0x8008DCE8 */
    R[4] = R[7] - R[5];  /* 0x8008DCEC */
    { R[31] = 0x8008DCF8u; R[5] = R[6] + R[0]; psx_next = 0x80037B38u; return; }  /* 0x8008DCF0 jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = R[2] + R[0]; if (_c) { goto L_8008DD04; } }  /* 0x8008DCF8 */
    R[3] = R[2] + 7;  /* 0x8008DD00 */
L_8008DD04:;
    R[2] = (uint32_t)((int32_t)R[3] >> 3);  /* 0x8008DD04 */
    R[31] = lw_(R[29] + 16);  /* 0x8008DD08 */
    R[2] = R[2] & 0x1FF;  /* 0x8008DD0C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8008DD10 jr ra */
}

void g0_8008DCF8(void) {
    { uint32_t _c = ((int32_t)R[2] >= 0); R[3] = R[2] + R[0]; if (_c) { goto L_8008DD04; } }  /* 0x8008DCF8 */
    R[3] = R[2] + 7;  /* 0x8008DD00 */
L_8008DD04:;
    R[2] = (uint32_t)((int32_t)R[3] >> 3);  /* 0x8008DD04 */
    R[31] = lw_(R[29] + 16);  /* 0x8008DD08 */
    R[2] = R[2] & 0x1FF;  /* 0x8008DD0C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8008DD10 jr ra */
}

void g0_8008DD18(void) {
    R[7] = R[4] + R[0];  /* 0x8008DD18 */
    R[5] = R[0] + R[0];  /* 0x8008DD1C */
    R[6] = R[0] + 60;  /* 0x8008DD20 */
    R[4] = 0x800Fu << 16;  /* 0x8008DD24 */
    R[3] = 0x8012u << 16;  /* 0x8008DD28 */
    R[2] = lw_(R[4] + 25120);  /* 0x8008DD2C */
    R[3] = R[3] - 26864;  /* 0x8008DD30 */
    R[2] = R[2] | 0x20;  /* 0x8008DD34 */
    sw_(R[4] + 25120, R[2]);  /* 0x8008DD38 */
    { uint32_t _c = (R[7] == R[3]); if (_c) { psx_next = 0x8008DD64u; return; } }  /* 0x8008DD3C b extern */
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x8008DD44 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008DD64u; return; } }  /* 0x8008DD4C b extern */
    R[2] = lb_(R[3] + 789);  /* 0x8008DD54 */
    R[2] = R[2] | 0x8;  /* 0x8008DD5C */
    sb_(R[3] + 789, R[2]);  /* 0x8008DD60 */
    psx_next = 0x8008DD64u; return;  /* fallthrough */
}

void g0_8008DD3C(void) {
    { uint32_t _c = (R[7] == R[3]); if (_c) { psx_next = 0x8008DD64u; return; } }  /* 0x8008DD3C b extern */
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x8008DD44 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8008DD64u; return; } }  /* 0x8008DD4C b extern */
    R[2] = lb_(R[3] + 789);  /* 0x8008DD54 */
    R[2] = R[2] | 0x8;  /* 0x8008DD5C */
    sb_(R[3] + 789, R[2]);  /* 0x8008DD60 */
    psx_next = 0x8008DD64u; return;  /* fallthrough */
}

void g0_8008DD64(void) {
    R[5] = R[5] + 1;  /* 0x8008DD64 */
    { uint32_t _c = (R[5] != R[6]); R[3] = R[3] + 804; if (_c) { psx_next = 0x8008DD3Cu; return; } }  /* 0x8008DD68 b extern */
    { psx_next = R[31]; return; }  /* 0x8008DD70 jr ra */
    R[6] = R[0] + R[0];  /* 0x8008DD78 */
    R[7] = R[0] + 60;  /* 0x8008DD7C */
    R[2] = 0x8012u << 16;  /* 0x8008DD80 */
    R[5] = R[2] - 26864;  /* 0x8008DD84 */
    R[4] = 0x800Fu << 16;  /* 0x8008DD88 */
    R[2] = lw_(R[4] + 25120);  /* 0x8008DD8C */
    R[3] = R[0] - 33;  /* 0x8008DD90 */
    R[2] = R[2] & R[3];  /* 0x8008DD94 */
    sw_(R[4] + 25120, R[2]);  /* 0x8008DD98 */
L_8008DD9C:;
    R[2] = (uint32_t)(int16_t)lh_(R[5]);  /* 0x8008DD9C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008DDBC; } }  /* 0x8008DDA4 */
    R[2] = lb_(R[5] + 789);  /* 0x8008DDAC */
    R[2] = R[2] & 0xF7;  /* 0x8008DDB4 */
    sb_(R[5] + 789, R[2]);  /* 0x8008DDB8 */
L_8008DDBC:;
    R[6] = R[6] + 1;  /* 0x8008DDBC */
    { uint32_t _c = (R[6] != R[7]); R[5] = R[5] + 804; if (_c) { psx_bb(); goto L_8008DD9C; } }  /* 0x8008DDC0 */
    { psx_next = R[31]; return; }  /* 0x8008DDC8 jr ra */
}

void g0_8008DDD0(void) {
    R[7] = R[4] + R[0];  /* 0x8008DDD0 */
    R[5] = R[0] + R[0];  /* 0x8008DDD4 */
    R[6] = R[0] + 60;  /* 0x8008DDD8 */
    R[4] = 0x800Fu << 16;  /* 0x8008DDDC */
    R[3] = 0x8012u << 16;  /* 0x8008DDE0 */
    R[2] = lw_(R[4] + 25120);  /* 0x8008DDE4 */
    R[3] = R[3] - 26864;  /* 0x8008DDE8 */
    R[2] = R[2] | 0x20;  /* 0x8008DDEC */
    sw_(R[4] + 25120, R[2]);  /* 0x8008DDF0 */
L_8008DDF4:;
    { uint32_t _c = (R[7] == R[3]); if (_c) { goto L_8008DE1C; } }  /* 0x8008DDF4 */
    R[2] = (uint32_t)(int16_t)lh_(R[3]);  /* 0x8008DDFC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008DE1C; } }  /* 0x8008DE04 */
    R[2] = lb_(R[3] + 789);  /* 0x8008DE0C */
    R[2] = R[2] | 0x1;  /* 0x8008DE14 */
    sb_(R[3] + 789, R[2]);  /* 0x8008DE18 */
L_8008DE1C:;
    R[5] = R[5] + 1;  /* 0x8008DE1C */
    { uint32_t _c = (R[5] != R[6]); R[3] = R[3] + 804; if (_c) { psx_bb(); goto L_8008DDF4; } }  /* 0x8008DE20 */
    { psx_next = R[31]; return; }  /* 0x8008DE28 jr ra */
}

void g0_8008DE30(void) {
    R[6] = R[0] + R[0];  /* 0x8008DE30 */
    R[7] = R[0] + 60;  /* 0x8008DE34 */
    R[2] = 0x8012u << 16;  /* 0x8008DE38 */
    R[5] = R[2] - 26864;  /* 0x8008DE3C */
    R[4] = 0x800Fu << 16;  /* 0x8008DE40 */
    R[2] = lw_(R[4] + 25120);  /* 0x8008DE44 */
    R[3] = R[0] - 33;  /* 0x8008DE48 */
    R[2] = R[2] & R[3];  /* 0x8008DE4C */
    sw_(R[4] + 25120, R[2]);  /* 0x8008DE50 */
L_8008DE54:;
    R[2] = (uint32_t)(int16_t)lh_(R[5]);  /* 0x8008DE54 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8008DE74; } }  /* 0x8008DE5C */
    R[2] = lb_(R[5] + 789);  /* 0x8008DE64 */
    R[2] = R[2] & 0xFE;  /* 0x8008DE6C */
    sb_(R[5] + 789, R[2]);  /* 0x8008DE70 */
L_8008DE74:;
    R[6] = R[6] + 1;  /* 0x8008DE74 */
    { uint32_t _c = (R[6] != R[7]); R[5] = R[5] + 804; if (_c) { psx_bb(); goto L_8008DE54; } }  /* 0x8008DE78 */
    { psx_next = R[31]; return; }  /* 0x8008DE80 jr ra */
}
