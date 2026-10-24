#include "game00_decls.h"

void g0_8009DB20(void) {
    R[4] = R[0] + 29;  /* 0x8009DB20 */
    R[5] = lw_(R[17] + 24);  /* 0x8009DB24 */
    R[7] = lw_(R[17] + 32);  /* 0x8009DB28 */
    R[6] = lw_(R[17] + 488);  /* 0x8009DB2C */
    R[2] = R[0] + 1;  /* 0x8009DB30 */
    sw_(R[29] + 16, R[2]);  /* 0x8009DB34 */
    R[2] = R[6] >> 31;  /* 0x8009DB38 */
    R[6] = R[6] + R[2];  /* 0x8009DB3C */
    R[2] = lw_(R[17] + 28);  /* 0x8009DB40 */
    R[6] = (uint32_t)((int32_t)R[6] >> 1);  /* 0x8009DB44 */
    { R[31] = 0x8009DB50u; R[6] = R[2] + R[6]; psx_next = 0x800A7290u; return; }  /* 0x8009DB48 jal */
    R[31] = lw_(R[29] + 32);  /* 0x8009DB50 */
    R[17] = lw_(R[29] + 28);  /* 0x8009DB54 */
    R[16] = lw_(R[29] + 24);  /* 0x8009DB58 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009DB5C jr ra */
}

void g0_8009DB50(void) {
    R[31] = lw_(R[29] + 32);  /* 0x8009DB50 */
    R[17] = lw_(R[29] + 28);  /* 0x8009DB54 */
    R[16] = lw_(R[29] + 24);  /* 0x8009DB58 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009DB5C jr ra */
}

void g0_8009DB64(void) {
    R[2] = 0x800Fu << 16;  /* 0x8009DB64 */
    R[2] = lw_(R[2] + 25120);  /* 0x8009DB68 */
    psx_next = 0x8009DB6Cu; return;  /* fallthrough */
}

void g0_8009DB6C(void) {
    R[29] = R[29] - 24;  /* 0x8009DB6C */
    sw_(R[29] + 16, R[16]);  /* 0x8009DB70 */
    R[16] = R[4] + R[0];  /* 0x8009DB74 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[29] + 20, R[31]); if (_c) { goto L_8009DC30; } }  /* 0x8009DB78 */
    R[2] = 0x8012u << 16;  /* 0x8009DB80 */
    R[2] = lh_(R[2] + 31132);  /* 0x8009DB84 */
    R[2] = R[2] & 0x1;  /* 0x8009DB8C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009DBF4; } }  /* 0x8009DB90 */
    R[2] = lh_(R[2] + 16104);  /* 0x8009DB98 */
    R[2] = R[2] & 0x1;  /* 0x8009DBA0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009DBF4; } }  /* 0x8009DBA4 */
    { goto L_8009DC34; }  /* 0x8009DBAC j */
L_8009DBB4:;
    R[4] = R[16] + R[0];  /* 0x8009DBB4 */
    { R[31] = 0x8009DBC0u; R[5] = R[0] + 27; psx_next = 0x8009BC84u; return; }  /* 0x8009DBB8 jal */
    R[4] = 0x8012u << 16;  /* 0x8009DBC0 */
    R[4] = R[4] - 26864;  /* 0x8009DBC4 */
    R[5] = R[0] + 2;  /* 0x8009DBC8 */
    R[2] = 0x8012u << 16;  /* 0x8009DBCC */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009DBD0 */
    R[2] = R[0] | 0xC1EE;  /* 0x8009DBD4 */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009DBD8 */
    { R[31] = 0x8009DBE4u; sw_(R[16] + 140, R[2]); psx_next = 0x8009C12Cu; return; }  /* 0x8009DBDC jal */
    R[2] = R[0] + 1;  /* 0x8009DBE4 */
    R[3] = 0x8013u << 16;  /* 0x8009DBE8 */
    { sw_(R[3] + -29556, R[0]); goto L_8009DC34; }  /* 0x8009DBEC j */
L_8009DBF4:;
    R[2] = lb_(R[16] + 497);  /* 0x8009DBF4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_8009DC30; } }  /* 0x8009DBFC */
    R[6] = R[0] + 2;  /* 0x8009DC04 */
    R[5] = R[2] + R[0];  /* 0x8009DC08 */
    R[3] = R[16] + R[0];  /* 0x8009DC0C */
L_8009DC10:;
    R[2] = lw_(R[3] + 528);  /* 0x8009DC10 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 12);  /* 0x8009DC18 */
    { uint32_t _c = (R[2] == R[6]); R[4] = R[4] + 1; if (_c) { psx_bb(); goto L_8009DBB4; } }  /* 0x8009DC20 */
    { uint32_t _c = (R[4] != R[5]); R[3] = R[3] + 4; if (_c) { psx_bb(); goto L_8009DC10; } }  /* 0x8009DC28 */
L_8009DC30:;
    R[2] = R[0] + R[0];  /* 0x8009DC30 */
L_8009DC34:;
    R[31] = lw_(R[29] + 20);  /* 0x8009DC34 */
    R[16] = lw_(R[29] + 16);  /* 0x8009DC38 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DC3C jr ra */
}

void g0_8009DBB4(void) {
L_8009DBB4:;
    R[4] = R[16] + R[0];  /* 0x8009DBB4 */
    { R[31] = 0x8009DBC0u; R[5] = R[0] + 27; psx_next = 0x8009BC84u; return; }  /* 0x8009DBB8 jal */
    R[4] = 0x8012u << 16;  /* 0x8009DBC0 */
    R[4] = R[4] - 26864;  /* 0x8009DBC4 */
    R[5] = R[0] + 2;  /* 0x8009DBC8 */
    R[2] = 0x8012u << 16;  /* 0x8009DBCC */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009DBD0 */
    R[2] = R[0] | 0xC1EE;  /* 0x8009DBD4 */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009DBD8 */
    { R[31] = 0x8009DBE4u; sw_(R[16] + 140, R[2]); psx_next = 0x8009C12Cu; return; }  /* 0x8009DBDC jal */
    R[2] = R[0] + 1;  /* 0x8009DBE4 */
    R[3] = 0x8013u << 16;  /* 0x8009DBE8 */
    { sw_(R[3] + -29556, R[0]); goto L_8009DC34; }  /* 0x8009DBEC j */
    R[2] = lb_(R[16] + 497);  /* 0x8009DBF4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_8009DC30; } }  /* 0x8009DBFC */
    R[6] = R[0] + 2;  /* 0x8009DC04 */
    R[5] = R[2] + R[0];  /* 0x8009DC08 */
    R[3] = R[16] + R[0];  /* 0x8009DC0C */
L_8009DC10:;
    R[2] = lw_(R[3] + 528);  /* 0x8009DC10 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 12);  /* 0x8009DC18 */
    { uint32_t _c = (R[2] == R[6]); R[4] = R[4] + 1; if (_c) { psx_bb(); goto L_8009DBB4; } }  /* 0x8009DC20 */
    { uint32_t _c = (R[4] != R[5]); R[3] = R[3] + 4; if (_c) { psx_bb(); goto L_8009DC10; } }  /* 0x8009DC28 */
L_8009DC30:;
    R[2] = R[0] + R[0];  /* 0x8009DC30 */
L_8009DC34:;
    R[31] = lw_(R[29] + 20);  /* 0x8009DC34 */
    R[16] = lw_(R[29] + 16);  /* 0x8009DC38 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DC3C jr ra */
}

void g0_8009DBC0(void) {
    R[4] = 0x8012u << 16;  /* 0x8009DBC0 */
    R[4] = R[4] - 26864;  /* 0x8009DBC4 */
    R[5] = R[0] + 2;  /* 0x8009DBC8 */
    R[2] = 0x8012u << 16;  /* 0x8009DBCC */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009DBD0 */
    R[2] = R[0] | 0xC1EE;  /* 0x8009DBD4 */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009DBD8 */
    { R[31] = 0x8009DBE4u; sw_(R[16] + 140, R[2]); psx_next = 0x8009C12Cu; return; }  /* 0x8009DBDC jal */
    R[2] = R[0] + 1;  /* 0x8009DBE4 */
    R[3] = 0x8013u << 16;  /* 0x8009DBE8 */
    { sw_(R[3] + -29556, R[0]); goto L_8009DC34; }  /* 0x8009DBEC j */
    R[2] = lb_(R[16] + 497);  /* 0x8009DBF4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_8009DC30; } }  /* 0x8009DBFC */
    R[6] = R[0] + 2;  /* 0x8009DC04 */
    R[5] = R[2] + R[0];  /* 0x8009DC08 */
    R[3] = R[16] + R[0];  /* 0x8009DC0C */
L_8009DC10:;
    R[2] = lw_(R[3] + 528);  /* 0x8009DC10 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 12);  /* 0x8009DC18 */
    { uint32_t _c = (R[2] == R[6]); R[4] = R[4] + 1; if (_c) { psx_next = 0x8009DBB4u; return; } }  /* 0x8009DC20 b extern */
    { uint32_t _c = (R[4] != R[5]); R[3] = R[3] + 4; if (_c) { psx_bb(); goto L_8009DC10; } }  /* 0x8009DC28 */
L_8009DC30:;
    R[2] = R[0] + R[0];  /* 0x8009DC30 */
L_8009DC34:;
    R[31] = lw_(R[29] + 20);  /* 0x8009DC34 */
    R[16] = lw_(R[29] + 16);  /* 0x8009DC38 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DC3C jr ra */
}

void g0_8009DBE4(void) {
    R[2] = R[0] + 1;  /* 0x8009DBE4 */
    R[3] = 0x8013u << 16;  /* 0x8009DBE8 */
    { sw_(R[3] + -29556, R[0]); goto L_8009DC34; }  /* 0x8009DBEC j */
    R[2] = lb_(R[16] + 497);  /* 0x8009DBF4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + R[0]; if (_c) { goto L_8009DC30; } }  /* 0x8009DBFC */
    R[6] = R[0] + 2;  /* 0x8009DC04 */
    R[5] = R[2] + R[0];  /* 0x8009DC08 */
    R[3] = R[16] + R[0];  /* 0x8009DC0C */
L_8009DC10:;
    R[2] = lw_(R[3] + 528);  /* 0x8009DC10 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 12);  /* 0x8009DC18 */
    { uint32_t _c = (R[2] == R[6]); R[4] = R[4] + 1; if (_c) { psx_next = 0x8009DBB4u; return; } }  /* 0x8009DC20 b extern */
    { uint32_t _c = (R[4] != R[5]); R[3] = R[3] + 4; if (_c) { psx_bb(); goto L_8009DC10; } }  /* 0x8009DC28 */
L_8009DC30:;
    R[2] = R[0] + R[0];  /* 0x8009DC30 */
L_8009DC34:;
    R[31] = lw_(R[29] + 20);  /* 0x8009DC34 */
    R[16] = lw_(R[29] + 16);  /* 0x8009DC38 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DC3C jr ra */
}

void g0_8009DC44(void) {
    R[2] = 0x800Fu << 16;  /* 0x8009DC44 */
    R[2] = lw_(R[2] + 25120);  /* 0x8009DC48 */
    psx_next = 0x8009DC4Cu; return;  /* fallthrough */
}

void g0_8009DC4C(void) {
    R[29] = R[29] - 32;  /* 0x8009DC4C */
    sw_(R[29] + 20, R[17]);  /* 0x8009DC50 */
    R[17] = R[4] + R[0];  /* 0x8009DC54 */
    sw_(R[29] + 24, R[31]);  /* 0x8009DC58 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[29] + 16, R[16]); if (_c) { goto L_8009DC7C; } }  /* 0x8009DC5C */
    R[2] = 0x8013u << 16;  /* 0x8009DC64 */
    R[16] = R[2] - 29656;  /* 0x8009DC68 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 4);  /* 0x8009DC6C */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009DC84; } }  /* 0x8009DC74 */
L_8009DC7C:;
    { R[2] = R[0] + R[0]; goto L_8009DC9C; }  /* 0x8009DC7C j */
L_8009DC84:;
    { R[31] = 0x8009DC8Cu; R[5] = R[0] + 3; psx_next = 0x8009BC84u; return; }  /* 0x8009DC84 jal */
    R[2] = R[0] + 1;  /* 0x8009DC8C */
    R[3] = R[0] - 1;  /* 0x8009DC90 */
    sh_(R[17] + 22, R[3]);  /* 0x8009DC94 */
    sh_(R[16] + 2, R[0]);  /* 0x8009DC98 */
L_8009DC9C:;
    R[31] = lw_(R[29] + 24);  /* 0x8009DC9C */
    R[17] = lw_(R[29] + 20);  /* 0x8009DCA0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009DCA4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009DCA8 jr ra */
}

void g0_8009DC8C(void) {
    R[2] = R[0] + 1;  /* 0x8009DC8C */
    R[3] = R[0] - 1;  /* 0x8009DC90 */
    sh_(R[17] + 22, R[3]);  /* 0x8009DC94 */
    sh_(R[16] + 2, R[0]);  /* 0x8009DC98 */
    R[31] = lw_(R[29] + 24);  /* 0x8009DC9C */
    R[17] = lw_(R[29] + 20);  /* 0x8009DCA0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009DCA4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009DCA8 jr ra */
}

void g0_8009DCB0(void) {
    R[2] = 0x8006u << 16;  /* 0x8009DCB0 */
    R[3] = R[2] + 13192;  /* 0x8009DCB4 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 38);  /* 0x8009DCB8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009DCE4; } }  /* 0x8009DCC0 */
    R[2] = lh_(R[2] + -6454);  /* 0x8009DCC8 */
    R[3] = lh_(R[3] + 2928);  /* 0x8009DCCC */
    R[2] = R[2] & R[3];  /* 0x8009DCD4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8012u << 16; if (_c) { goto L_8009DCE8; } }  /* 0x8009DCD8 */
    R[4] = R[0] + 5;  /* 0x8009DCE0 */
L_8009DCE4:;
    R[2] = 0x8012u << 16;  /* 0x8009DCE4 */
L_8009DCE8:;
    R[2] = lh_(R[2] + 31132);  /* 0x8009DCE8 */
    R[2] = R[2] & 0x1;  /* 0x8009DCF0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009DD14; } }  /* 0x8009DCF4 */
    R[2] = lh_(R[2] + 16104);  /* 0x8009DCFC */
    R[2] = R[2] & 0x1;  /* 0x8009DD04 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DD14; } }  /* 0x8009DD08 */
    R[4] = R[0] + 5;  /* 0x8009DD10 */
L_8009DD14:;
    { R[2] = R[4] + R[0]; psx_next = R[31]; return; }  /* 0x8009DD14 jr ra */
}

void g0_8009DD1C(void) {
    R[2] = 0x8012u << 16;  /* 0x8009DD1C */
    R[2] = lh_(R[2] + 31132);  /* 0x8009DD20 */
    psx_next = 0x8009DD24u; return;  /* fallthrough */
}

void g0_8009DD24(void) {
    R[29] = R[29] - 24;  /* 0x8009DD24 */
    R[2] = R[2] & 0x1;  /* 0x8009DD28 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[29] + 16, R[31]); if (_c) { goto L_8009DD4C; } }  /* 0x8009DD2C */
    R[2] = 0x8006u << 16;  /* 0x8009DD34 */
    R[2] = lh_(R[2] + 16104);  /* 0x8009DD38 */
    R[2] = R[2] & 0x1;  /* 0x8009DD40 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009DE20; } }  /* 0x8009DD44 */
L_8009DD4C:;
    R[2] = 0x8013u << 16;  /* 0x8009DD4C */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + -29588);  /* 0x8009DD50 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009DE20; } }  /* 0x8009DD58 */
    R[3] = lw_(R[4] + 352);  /* 0x8009DD60 */
    R[2] = lb_(R[3] + 1);  /* 0x8009DD68 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009DD98; } }  /* 0x8009DD70 */
    R[2] = lw_(R[3] + 24);  /* 0x8009DD78 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 26);  /* 0x8009DD80 */
    R[2] = ((int32_t)R[2] < 2049);  /* 0x8009DD88 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009DE20; } }  /* 0x8009DD8C */
    R[2] = 0x8006u << 16;  /* 0x8009DD94 */
L_8009DD98:;
    R[5] = R[2] - 6456;  /* 0x8009DD98 */
    R[3] = 0x8006u << 16;  /* 0x8009DD9C */
    R[2] = lh_(R[5] + 2);  /* 0x8009DDA0 */
    R[3] = lh_(R[3] + 16120);  /* 0x8009DDA4 */
    R[2] = R[2] & R[3];  /* 0x8009DDAC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] - 1; if (_c) { goto L_8009DE1C; } }  /* 0x8009DDB0 */
    R[5] = lw_(R[5] + 16);  /* 0x8009DDB8 */
    { uint32_t _c = (R[5] == R[2]); R[2] = 0x8011u << 16; if (_c) { goto L_8009DE1C; } }  /* 0x8009DDC0 */
    R[6] = R[2] + 29992;  /* 0x8009DDC8 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 29992);  /* 0x8009DDCC */
    R[2] = R[0] + 2;  /* 0x8009DDD0 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009DE0C; } }  /* 0x8009DDD4 */
    R[2] = (uint32_t)(int16_t)lh_(R[6] + 224);  /* 0x8009DDDC */
    R[3] = (uint32_t)(int16_t)lh_(R[6] + 226);  /* 0x8009DDE0 */
    R[2] = R[5] + R[2];  /* 0x8009DDE4 */
    R[2] = R[2] + 128;  /* 0x8009DDE8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009DDEC */
    R[2] = R[2] - R[3];  /* 0x8009DDF0 */
    R[3] = R[2] & 0x1FF;  /* 0x8009DDF4 */
    R[2] = R[0] + 128;  /* 0x8009DDF8 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 384; if (_c) { goto L_8009DE0C; } }  /* 0x8009DDFC */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009DE20; } }  /* 0x8009DE04 */
L_8009DE0C:;
    { R[31] = 0x8009DE14u; R[5] = R[0] + 8; psx_next = 0x8009BC84u; return; }  /* 0x8009DE0C jal */
    { R[2] = R[0] + 1; goto L_8009DE20; }  /* 0x8009DE14 j */
L_8009DE1C:;
    R[2] = R[0] + R[0];  /* 0x8009DE1C */
L_8009DE20:;
    R[31] = lw_(R[29] + 16);  /* 0x8009DE20 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DE28 jr ra */
}

void g0_8009DE14(void) {
    { R[2] = R[0] + 1; goto L_8009DE20; }  /* 0x8009DE14 j */
    R[2] = R[0] + R[0];  /* 0x8009DE1C */
L_8009DE20:;
    R[31] = lw_(R[29] + 16);  /* 0x8009DE20 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DE28 jr ra */
}

void g0_8009DE30(void) {
    R[29] = R[29] - 24;  /* 0x8009DE30 */
    sw_(R[29] + 16, R[16]);  /* 0x8009DE34 */
    R[16] = R[4] + R[0];  /* 0x8009DE38 */
    sw_(R[29] + 20, R[31]);  /* 0x8009DE3C */
    R[2] = lb_(R[16] + 784);  /* 0x8009DE40 */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009DE60; } }  /* 0x8009DE48 */
    { R[31] = 0x8009DE58u; R[5] = R[0] + 11; psx_next = 0x8009BC84u; return; }  /* 0x8009DE50 jal */
    { goto L_8009DF3C; }  /* 0x8009DE58 j */
L_8009DE60:;
    R[2] = R[0] + 1;  /* 0x8009DE60 */
    { R[31] = 0x8009DE6Cu; sh_(R[3] + -29654, R[2]); psx_next = 0x8009D990u; return; }  /* 0x8009DE64 jal */
    { R[31] = 0x8009DE74u; psx_next = 0x8009ADF4u; return; }  /* 0x8009DE6C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DE74 */
    { R[31] = 0x8009DE84u; R[4] = R[16] + R[0]; psx_next = 0x8009BF0Cu; return; }  /* 0x8009DE7C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DE84 */
    { R[31] = 0x8009DE94u; R[4] = R[16] + R[0]; psx_next = 0x8009C3A4u; return; }  /* 0x8009DE8C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DE94 */
    R[5] = R[0] + 10;  /* 0x8009DE9C */
    { R[31] = 0x8009DEA8u; R[6] = R[0] + R[0]; psx_next = 0x8009D268u; return; }  /* 0x8009DEA0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEA8 */
    { R[31] = 0x8009DEB8u; R[5] = R[0] + 82; psx_next = 0x8009D6E4u; return; }  /* 0x8009DEB0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEB8 */
    { R[31] = 0x8009DEC8u; R[5] = R[0] + 37; psx_next = 0x8009D4B0u; return; }  /* 0x8009DEC0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DEC8 */
    { R[31] = 0x8009DED8u; R[4] = R[0] + R[0]; psx_next = 0x8009D7DCu; return; }  /* 0x8009DED0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DED8 */
    { R[31] = 0x8009DEE8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009DEE0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEE8 */
    { R[31] = 0x8009DEF8u; R[5] = R[0] + 17; psx_next = 0x8009BC08u; return; }  /* 0x8009DEF0 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF2C; } }  /* 0x8009DEF8 */
    R[2] = lw_(R[16] + 72);  /* 0x8009DF00 */
    R[2] = lh_(R[2]);  /* 0x8009DF08 */
    R[2] = R[2] >> 13;  /* 0x8009DF10 */
    R[2] = R[2] & 0x1;  /* 0x8009DF14 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009DF30; } }  /* 0x8009DF18 */
    { R[31] = 0x8009DF28u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009DF20 jal */
    R[4] = R[16] + R[0];  /* 0x8009DF28 */
L_8009DF2C:;
    R[5] = R[0] + 5;  /* 0x8009DF2C */
L_8009DF30:;
    R[6] = R[0] - 1;  /* 0x8009DF30 */
    { R[31] = 0x8009DF3Cu; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009DF34 jal */
L_8009DF3C:;
    R[31] = lw_(R[29] + 20);  /* 0x8009DF3C */
    R[16] = lw_(R[29] + 16);  /* 0x8009DF40 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DF44 jr ra */
}

void g0_8009DE58(void) {
    { goto L_8009DF3C; }  /* 0x8009DE58 j */
    R[2] = R[0] + 1;  /* 0x8009DE60 */
    { R[31] = 0x8009DE6Cu; sh_(R[3] + -29654, R[2]); psx_next = 0x8009D990u; return; }  /* 0x8009DE64 jal */
    { R[31] = 0x8009DE74u; psx_next = 0x8009ADF4u; return; }  /* 0x8009DE6C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DE74 */
    { R[31] = 0x8009DE84u; R[4] = R[16] + R[0]; psx_next = 0x8009BF0Cu; return; }  /* 0x8009DE7C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DE84 */
    { R[31] = 0x8009DE94u; R[4] = R[16] + R[0]; psx_next = 0x8009C3A4u; return; }  /* 0x8009DE8C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DE94 */
    R[5] = R[0] + 10;  /* 0x8009DE9C */
    { R[31] = 0x8009DEA8u; R[6] = R[0] + R[0]; psx_next = 0x8009D268u; return; }  /* 0x8009DEA0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEA8 */
    { R[31] = 0x8009DEB8u; R[5] = R[0] + 82; psx_next = 0x8009D6E4u; return; }  /* 0x8009DEB0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEB8 */
    { R[31] = 0x8009DEC8u; R[5] = R[0] + 37; psx_next = 0x8009D4B0u; return; }  /* 0x8009DEC0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DEC8 */
    { R[31] = 0x8009DED8u; R[4] = R[0] + R[0]; psx_next = 0x8009D7DCu; return; }  /* 0x8009DED0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DED8 */
    { R[31] = 0x8009DEE8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009DEE0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEE8 */
    { R[31] = 0x8009DEF8u; R[5] = R[0] + 17; psx_next = 0x8009BC08u; return; }  /* 0x8009DEF0 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF2C; } }  /* 0x8009DEF8 */
    R[2] = lw_(R[16] + 72);  /* 0x8009DF00 */
    R[2] = lh_(R[2]);  /* 0x8009DF08 */
    R[2] = R[2] >> 13;  /* 0x8009DF10 */
    R[2] = R[2] & 0x1;  /* 0x8009DF14 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009DF30; } }  /* 0x8009DF18 */
    { R[31] = 0x8009DF28u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009DF20 jal */
    R[4] = R[16] + R[0];  /* 0x8009DF28 */
L_8009DF2C:;
    R[5] = R[0] + 5;  /* 0x8009DF2C */
L_8009DF30:;
    R[6] = R[0] - 1;  /* 0x8009DF30 */
    { R[31] = 0x8009DF3Cu; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009DF34 jal */
L_8009DF3C:;
    R[31] = lw_(R[29] + 20);  /* 0x8009DF3C */
    R[16] = lw_(R[29] + 16);  /* 0x8009DF40 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DF44 jr ra */
}

void g0_8009DE6C(void) {
    { R[31] = 0x8009DE74u; psx_next = 0x8009ADF4u; return; }  /* 0x8009DE6C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DE74 */
    { R[31] = 0x8009DE84u; R[4] = R[16] + R[0]; psx_next = 0x8009BF0Cu; return; }  /* 0x8009DE7C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DE84 */
    { R[31] = 0x8009DE94u; R[4] = R[16] + R[0]; psx_next = 0x8009C3A4u; return; }  /* 0x8009DE8C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DE94 */
    R[5] = R[0] + 10;  /* 0x8009DE9C */
    { R[31] = 0x8009DEA8u; R[6] = R[0] + R[0]; psx_next = 0x8009D268u; return; }  /* 0x8009DEA0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEA8 */
    { R[31] = 0x8009DEB8u; R[5] = R[0] + 82; psx_next = 0x8009D6E4u; return; }  /* 0x8009DEB0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEB8 */
    { R[31] = 0x8009DEC8u; R[5] = R[0] + 37; psx_next = 0x8009D4B0u; return; }  /* 0x8009DEC0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DEC8 */
    { R[31] = 0x8009DED8u; R[4] = R[0] + R[0]; psx_next = 0x8009D7DCu; return; }  /* 0x8009DED0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DED8 */
    { R[31] = 0x8009DEE8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009DEE0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEE8 */
    { R[31] = 0x8009DEF8u; R[5] = R[0] + 17; psx_next = 0x8009BC08u; return; }  /* 0x8009DEF0 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF2C; } }  /* 0x8009DEF8 */
    R[2] = lw_(R[16] + 72);  /* 0x8009DF00 */
    R[2] = lh_(R[2]);  /* 0x8009DF08 */
    R[2] = R[2] >> 13;  /* 0x8009DF10 */
    R[2] = R[2] & 0x1;  /* 0x8009DF14 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009DF30; } }  /* 0x8009DF18 */
    { R[31] = 0x8009DF28u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009DF20 jal */
    R[4] = R[16] + R[0];  /* 0x8009DF28 */
L_8009DF2C:;
    R[5] = R[0] + 5;  /* 0x8009DF2C */
L_8009DF30:;
    R[6] = R[0] - 1;  /* 0x8009DF30 */
    { R[31] = 0x8009DF3Cu; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009DF34 jal */
L_8009DF3C:;
    R[31] = lw_(R[29] + 20);  /* 0x8009DF3C */
    R[16] = lw_(R[29] + 16);  /* 0x8009DF40 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DF44 jr ra */
}

void g0_8009DE74(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DE74 */
    { R[31] = 0x8009DE84u; R[4] = R[16] + R[0]; psx_next = 0x8009BF0Cu; return; }  /* 0x8009DE7C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DE84 */
    { R[31] = 0x8009DE94u; R[4] = R[16] + R[0]; psx_next = 0x8009C3A4u; return; }  /* 0x8009DE8C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DE94 */
    R[5] = R[0] + 10;  /* 0x8009DE9C */
    { R[31] = 0x8009DEA8u; R[6] = R[0] + R[0]; psx_next = 0x8009D268u; return; }  /* 0x8009DEA0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEA8 */
    { R[31] = 0x8009DEB8u; R[5] = R[0] + 82; psx_next = 0x8009D6E4u; return; }  /* 0x8009DEB0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEB8 */
    { R[31] = 0x8009DEC8u; R[5] = R[0] + 37; psx_next = 0x8009D4B0u; return; }  /* 0x8009DEC0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DEC8 */
    { R[31] = 0x8009DED8u; R[4] = R[0] + R[0]; psx_next = 0x8009D7DCu; return; }  /* 0x8009DED0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DED8 */
    { R[31] = 0x8009DEE8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009DEE0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEE8 */
    { R[31] = 0x8009DEF8u; R[5] = R[0] + 17; psx_next = 0x8009BC08u; return; }  /* 0x8009DEF0 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF2C; } }  /* 0x8009DEF8 */
    R[2] = lw_(R[16] + 72);  /* 0x8009DF00 */
    R[2] = lh_(R[2]);  /* 0x8009DF08 */
    R[2] = R[2] >> 13;  /* 0x8009DF10 */
    R[2] = R[2] & 0x1;  /* 0x8009DF14 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009DF30; } }  /* 0x8009DF18 */
    { R[31] = 0x8009DF28u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009DF20 jal */
    R[4] = R[16] + R[0];  /* 0x8009DF28 */
L_8009DF2C:;
    R[5] = R[0] + 5;  /* 0x8009DF2C */
L_8009DF30:;
    R[6] = R[0] - 1;  /* 0x8009DF30 */
    { R[31] = 0x8009DF3Cu; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009DF34 jal */
L_8009DF3C:;
    R[31] = lw_(R[29] + 20);  /* 0x8009DF3C */
    R[16] = lw_(R[29] + 16);  /* 0x8009DF40 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DF44 jr ra */
}

void g0_8009DE84(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DE84 */
    { R[31] = 0x8009DE94u; R[4] = R[16] + R[0]; psx_next = 0x8009C3A4u; return; }  /* 0x8009DE8C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DE94 */
    R[5] = R[0] + 10;  /* 0x8009DE9C */
    { R[31] = 0x8009DEA8u; R[6] = R[0] + R[0]; psx_next = 0x8009D268u; return; }  /* 0x8009DEA0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEA8 */
    { R[31] = 0x8009DEB8u; R[5] = R[0] + 82; psx_next = 0x8009D6E4u; return; }  /* 0x8009DEB0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEB8 */
    { R[31] = 0x8009DEC8u; R[5] = R[0] + 37; psx_next = 0x8009D4B0u; return; }  /* 0x8009DEC0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DEC8 */
    { R[31] = 0x8009DED8u; R[4] = R[0] + R[0]; psx_next = 0x8009D7DCu; return; }  /* 0x8009DED0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DED8 */
    { R[31] = 0x8009DEE8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009DEE0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEE8 */
    { R[31] = 0x8009DEF8u; R[5] = R[0] + 17; psx_next = 0x8009BC08u; return; }  /* 0x8009DEF0 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF2C; } }  /* 0x8009DEF8 */
    R[2] = lw_(R[16] + 72);  /* 0x8009DF00 */
    R[2] = lh_(R[2]);  /* 0x8009DF08 */
    R[2] = R[2] >> 13;  /* 0x8009DF10 */
    R[2] = R[2] & 0x1;  /* 0x8009DF14 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009DF30; } }  /* 0x8009DF18 */
    { R[31] = 0x8009DF28u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009DF20 jal */
    R[4] = R[16] + R[0];  /* 0x8009DF28 */
L_8009DF2C:;
    R[5] = R[0] + 5;  /* 0x8009DF2C */
L_8009DF30:;
    R[6] = R[0] - 1;  /* 0x8009DF30 */
    { R[31] = 0x8009DF3Cu; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009DF34 jal */
L_8009DF3C:;
    R[31] = lw_(R[29] + 20);  /* 0x8009DF3C */
    R[16] = lw_(R[29] + 16);  /* 0x8009DF40 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DF44 jr ra */
}

void g0_8009DE94(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DE94 */
    R[5] = R[0] + 10;  /* 0x8009DE9C */
    { R[31] = 0x8009DEA8u; R[6] = R[0] + R[0]; psx_next = 0x8009D268u; return; }  /* 0x8009DEA0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEA8 */
    { R[31] = 0x8009DEB8u; R[5] = R[0] + 82; psx_next = 0x8009D6E4u; return; }  /* 0x8009DEB0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEB8 */
    { R[31] = 0x8009DEC8u; R[5] = R[0] + 37; psx_next = 0x8009D4B0u; return; }  /* 0x8009DEC0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DEC8 */
    { R[31] = 0x8009DED8u; R[4] = R[0] + R[0]; psx_next = 0x8009D7DCu; return; }  /* 0x8009DED0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DED8 */
    { R[31] = 0x8009DEE8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009DEE0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEE8 */
    { R[31] = 0x8009DEF8u; R[5] = R[0] + 17; psx_next = 0x8009BC08u; return; }  /* 0x8009DEF0 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF2C; } }  /* 0x8009DEF8 */
    R[2] = lw_(R[16] + 72);  /* 0x8009DF00 */
    R[2] = lh_(R[2]);  /* 0x8009DF08 */
    R[2] = R[2] >> 13;  /* 0x8009DF10 */
    R[2] = R[2] & 0x1;  /* 0x8009DF14 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009DF30; } }  /* 0x8009DF18 */
    { R[31] = 0x8009DF28u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009DF20 jal */
    R[4] = R[16] + R[0];  /* 0x8009DF28 */
L_8009DF2C:;
    R[5] = R[0] + 5;  /* 0x8009DF2C */
L_8009DF30:;
    R[6] = R[0] - 1;  /* 0x8009DF30 */
    { R[31] = 0x8009DF3Cu; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009DF34 jal */
L_8009DF3C:;
    R[31] = lw_(R[29] + 20);  /* 0x8009DF3C */
    R[16] = lw_(R[29] + 16);  /* 0x8009DF40 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DF44 jr ra */
}

void g0_8009DEA8(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEA8 */
    { R[31] = 0x8009DEB8u; R[5] = R[0] + 82; psx_next = 0x8009D6E4u; return; }  /* 0x8009DEB0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEB8 */
    { R[31] = 0x8009DEC8u; R[5] = R[0] + 37; psx_next = 0x8009D4B0u; return; }  /* 0x8009DEC0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DEC8 */
    { R[31] = 0x8009DED8u; R[4] = R[0] + R[0]; psx_next = 0x8009D7DCu; return; }  /* 0x8009DED0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DED8 */
    { R[31] = 0x8009DEE8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009DEE0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEE8 */
    { R[31] = 0x8009DEF8u; R[5] = R[0] + 17; psx_next = 0x8009BC08u; return; }  /* 0x8009DEF0 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF2C; } }  /* 0x8009DEF8 */
    R[2] = lw_(R[16] + 72);  /* 0x8009DF00 */
    R[2] = lh_(R[2]);  /* 0x8009DF08 */
    R[2] = R[2] >> 13;  /* 0x8009DF10 */
    R[2] = R[2] & 0x1;  /* 0x8009DF14 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009DF30; } }  /* 0x8009DF18 */
    { R[31] = 0x8009DF28u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009DF20 jal */
    R[4] = R[16] + R[0];  /* 0x8009DF28 */
L_8009DF2C:;
    R[5] = R[0] + 5;  /* 0x8009DF2C */
L_8009DF30:;
    R[6] = R[0] - 1;  /* 0x8009DF30 */
    { R[31] = 0x8009DF3Cu; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009DF34 jal */
L_8009DF3C:;
    R[31] = lw_(R[29] + 20);  /* 0x8009DF3C */
    R[16] = lw_(R[29] + 16);  /* 0x8009DF40 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DF44 jr ra */
}

void g0_8009DEB8(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEB8 */
    { R[31] = 0x8009DEC8u; R[5] = R[0] + 37; psx_next = 0x8009D4B0u; return; }  /* 0x8009DEC0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DEC8 */
    { R[31] = 0x8009DED8u; R[4] = R[0] + R[0]; psx_next = 0x8009D7DCu; return; }  /* 0x8009DED0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DED8 */
    { R[31] = 0x8009DEE8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009DEE0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEE8 */
    { R[31] = 0x8009DEF8u; R[5] = R[0] + 17; psx_next = 0x8009BC08u; return; }  /* 0x8009DEF0 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF2C; } }  /* 0x8009DEF8 */
    R[2] = lw_(R[16] + 72);  /* 0x8009DF00 */
    R[2] = lh_(R[2]);  /* 0x8009DF08 */
    R[2] = R[2] >> 13;  /* 0x8009DF10 */
    R[2] = R[2] & 0x1;  /* 0x8009DF14 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009DF30; } }  /* 0x8009DF18 */
    { R[31] = 0x8009DF28u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009DF20 jal */
    R[4] = R[16] + R[0];  /* 0x8009DF28 */
L_8009DF2C:;
    R[5] = R[0] + 5;  /* 0x8009DF2C */
L_8009DF30:;
    R[6] = R[0] - 1;  /* 0x8009DF30 */
    { R[31] = 0x8009DF3Cu; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009DF34 jal */
L_8009DF3C:;
    R[31] = lw_(R[29] + 20);  /* 0x8009DF3C */
    R[16] = lw_(R[29] + 16);  /* 0x8009DF40 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DF44 jr ra */
}

void g0_8009DEC8(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DEC8 */
    { R[31] = 0x8009DED8u; R[4] = R[0] + R[0]; psx_next = 0x8009D7DCu; return; }  /* 0x8009DED0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DED8 */
    { R[31] = 0x8009DEE8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009DEE0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEE8 */
    { R[31] = 0x8009DEF8u; R[5] = R[0] + 17; psx_next = 0x8009BC08u; return; }  /* 0x8009DEF0 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF2C; } }  /* 0x8009DEF8 */
    R[2] = lw_(R[16] + 72);  /* 0x8009DF00 */
    R[2] = lh_(R[2]);  /* 0x8009DF08 */
    R[2] = R[2] >> 13;  /* 0x8009DF10 */
    R[2] = R[2] & 0x1;  /* 0x8009DF14 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009DF30; } }  /* 0x8009DF18 */
    { R[31] = 0x8009DF28u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009DF20 jal */
    R[4] = R[16] + R[0];  /* 0x8009DF28 */
L_8009DF2C:;
    R[5] = R[0] + 5;  /* 0x8009DF2C */
L_8009DF30:;
    R[6] = R[0] - 1;  /* 0x8009DF30 */
    { R[31] = 0x8009DF3Cu; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009DF34 jal */
L_8009DF3C:;
    R[31] = lw_(R[29] + 20);  /* 0x8009DF3C */
    R[16] = lw_(R[29] + 16);  /* 0x8009DF40 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DF44 jr ra */
}

void g0_8009DED8(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF3C; } }  /* 0x8009DED8 */
    { R[31] = 0x8009DEE8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009DEE0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEE8 */
    { R[31] = 0x8009DEF8u; R[5] = R[0] + 17; psx_next = 0x8009BC08u; return; }  /* 0x8009DEF0 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF2C; } }  /* 0x8009DEF8 */
    R[2] = lw_(R[16] + 72);  /* 0x8009DF00 */
    R[2] = lh_(R[2]);  /* 0x8009DF08 */
    R[2] = R[2] >> 13;  /* 0x8009DF10 */
    R[2] = R[2] & 0x1;  /* 0x8009DF14 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009DF30; } }  /* 0x8009DF18 */
    { R[31] = 0x8009DF28u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009DF20 jal */
    R[4] = R[16] + R[0];  /* 0x8009DF28 */
L_8009DF2C:;
    R[5] = R[0] + 5;  /* 0x8009DF2C */
L_8009DF30:;
    R[6] = R[0] - 1;  /* 0x8009DF30 */
    { R[31] = 0x8009DF3Cu; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009DF34 jal */
L_8009DF3C:;
    R[31] = lw_(R[29] + 20);  /* 0x8009DF3C */
    R[16] = lw_(R[29] + 16);  /* 0x8009DF40 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DF44 jr ra */
}

void g0_8009DEE8(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF3C; } }  /* 0x8009DEE8 */
    { R[31] = 0x8009DEF8u; R[5] = R[0] + 17; psx_next = 0x8009BC08u; return; }  /* 0x8009DEF0 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF2C; } }  /* 0x8009DEF8 */
    R[2] = lw_(R[16] + 72);  /* 0x8009DF00 */
    R[2] = lh_(R[2]);  /* 0x8009DF08 */
    R[2] = R[2] >> 13;  /* 0x8009DF10 */
    R[2] = R[2] & 0x1;  /* 0x8009DF14 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009DF30; } }  /* 0x8009DF18 */
    { R[31] = 0x8009DF28u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009DF20 jal */
    R[4] = R[16] + R[0];  /* 0x8009DF28 */
L_8009DF2C:;
    R[5] = R[0] + 5;  /* 0x8009DF2C */
L_8009DF30:;
    R[6] = R[0] - 1;  /* 0x8009DF30 */
    { R[31] = 0x8009DF3Cu; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009DF34 jal */
L_8009DF3C:;
    R[31] = lw_(R[29] + 20);  /* 0x8009DF3C */
    R[16] = lw_(R[29] + 16);  /* 0x8009DF40 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DF44 jr ra */
}

void g0_8009DEF8(void) {
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009DF2C; } }  /* 0x8009DEF8 */
    R[2] = lw_(R[16] + 72);  /* 0x8009DF00 */
    R[2] = lh_(R[2]);  /* 0x8009DF08 */
    R[2] = R[2] >> 13;  /* 0x8009DF10 */
    R[2] = R[2] & 0x1;  /* 0x8009DF14 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009DF30; } }  /* 0x8009DF18 */
    { R[31] = 0x8009DF28u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009DF20 jal */
    R[4] = R[16] + R[0];  /* 0x8009DF28 */
L_8009DF2C:;
    R[5] = R[0] + 5;  /* 0x8009DF2C */
L_8009DF30:;
    R[6] = R[0] - 1;  /* 0x8009DF30 */
    { R[31] = 0x8009DF3Cu; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009DF34 jal */
    R[31] = lw_(R[29] + 20);  /* 0x8009DF3C */
    R[16] = lw_(R[29] + 16);  /* 0x8009DF40 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DF44 jr ra */
}

void g0_8009DF28(void) {
    R[4] = R[16] + R[0];  /* 0x8009DF28 */
    R[5] = R[0] + 5;  /* 0x8009DF2C */
    R[6] = R[0] - 1;  /* 0x8009DF30 */
    { R[31] = 0x8009DF3Cu; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009DF34 jal */
    R[31] = lw_(R[29] + 20);  /* 0x8009DF3C */
    R[16] = lw_(R[29] + 16);  /* 0x8009DF40 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DF44 jr ra */
}

void g0_8009DF3C(void) {
    R[31] = lw_(R[29] + 20);  /* 0x8009DF3C */
    R[16] = lw_(R[29] + 16);  /* 0x8009DF40 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009DF44 jr ra */
}

void g0_8009DF4C(void) {
    R[29] = R[29] - 24;  /* 0x8009DF4C */
    sw_(R[29] + 16, R[16]);  /* 0x8009DF50 */
    R[16] = R[4] + R[0];  /* 0x8009DF54 */
    sw_(R[29] + 20, R[31]);  /* 0x8009DF58 */
    R[2] = lb_(R[16] + 784);  /* 0x8009DF5C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009DF7C; } }  /* 0x8009DF64 */
    { R[31] = 0x8009DF74u; R[5] = R[0] + 11; psx_next = 0x8009BC84u; return; }  /* 0x8009DF6C jal */
    { psx_next = 0x8009E068u; return; }  /* 0x8009DF74 j extern */
L_8009DF7C:;
    { R[31] = 0x8009DF84u; psx_next = 0x8009ADF4u; return; }  /* 0x8009DF7C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E068u; return; } }  /* 0x8009DF84 b extern */
    { R[31] = 0x8009DF94u; R[4] = R[16] + R[0]; psx_next = 0x8009BF0Cu; return; }  /* 0x8009DF8C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E068u; return; } }  /* 0x8009DF94 b extern */
    psx_next = 0x8009DF9Cu; return;  /* fallthrough */
}

void g0_8009DF74(void) {
    { psx_next = 0x8009E068u; return; }  /* 0x8009DF74 j extern */
    { R[31] = 0x8009DF84u; psx_next = 0x8009ADF4u; return; }  /* 0x8009DF7C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E068u; return; } }  /* 0x8009DF84 b extern */
    { R[31] = 0x8009DF94u; R[4] = R[16] + R[0]; psx_next = 0x8009BF0Cu; return; }  /* 0x8009DF8C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E068u; return; } }  /* 0x8009DF94 b extern */
    psx_next = 0x8009DF9Cu; return;  /* fallthrough */
}

void g0_8009DF84(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E068u; return; } }  /* 0x8009DF84 b extern */
    { R[31] = 0x8009DF94u; R[4] = R[16] + R[0]; psx_next = 0x8009BF0Cu; return; }  /* 0x8009DF8C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E068u; return; } }  /* 0x8009DF94 b extern */
    psx_next = 0x8009DF9Cu; return;  /* fallthrough */
}

void g0_8009DF94(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E068u; return; } }  /* 0x8009DF94 b extern */
    psx_next = 0x8009DF9Cu; return;  /* fallthrough */
}

void g0_8009DF98(void) {
    { R[31] = 0x8009DFA4u; R[4] = R[16] + R[0]; psx_next = 0x8009C3A4u; return; }  /* 0x8009DF9C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009DFA4 */
    R[5] = R[0] + 14;  /* 0x8009DFAC */
    { R[31] = 0x8009DFB8u; R[6] = R[0] + R[0]; psx_next = 0x8009D268u; return; }  /* 0x8009DFB0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009DFB8 */
    { R[31] = 0x8009DFC8u; R[5] = R[0] + 82; psx_next = 0x8009D6E4u; return; }  /* 0x8009DFC0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009DFC8 */
    { R[31] = 0x8009DFD8u; R[5] = R[0] + 37; psx_next = 0x8009D4B0u; return; }  /* 0x8009DFD0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFD8 */
    { R[31] = 0x8009DFE8u; R[4] = R[0] + R[0]; psx_next = 0x8009D7DCu; return; }  /* 0x8009DFE0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFE8 */
    { R[31] = 0x8009DFF8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009DFF0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFF8 */
    { R[31] = 0x8009E008u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E000 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009E008 */
    { R[31] = 0x8009E018u; R[5] = R[0] + 7; psx_next = 0x8009BC08u; return; }  /* 0x8009E010 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E058; } }  /* 0x8009E018 */
    R[2] = lw_(R[16] + 72);  /* 0x8009E020 */
    R[2] = lh_(R[2]);  /* 0x8009E028 */
    R[2] = R[2] >> 13;  /* 0x8009E030 */
    R[2] = R[2] & 0x1;  /* 0x8009E034 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009E050; } }  /* 0x8009E038 */
    { R[31] = 0x8009E048u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009E040 jal */
    { goto L_8009E068; }  /* 0x8009E048 j */
L_8009E050:;
    { R[6] = R[0] - 1; goto L_8009E060; }  /* 0x8009E050 j */
L_8009E058:;
    R[5] = R[0] - 1;  /* 0x8009E058 */
    R[6] = R[0] + R[0];  /* 0x8009E05C */
L_8009E060:;
    { R[31] = 0x8009E068u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E060 jal */
L_8009E068:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E068 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E06C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E070 jr ra */
    R[2] = 0x8006u << 16;  /* 0x8009E078 */
    R[2] = lb_(R[2] + -12295);  /* 0x8009E07C */
    psx_next = 0x8009E080u; return;  /* fallthrough */
}

void g0_8009DF9C(void) {
    { R[31] = 0x8009DFA4u; R[4] = R[16] + R[0]; psx_next = 0x8009C3A4u; return; }  /* 0x8009DF9C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009DFA4 */
    R[5] = R[0] + 14;  /* 0x8009DFAC */
    { R[31] = 0x8009DFB8u; R[6] = R[0] + R[0]; psx_next = 0x8009D268u; return; }  /* 0x8009DFB0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009DFB8 */
    { R[31] = 0x8009DFC8u; R[5] = R[0] + 82; psx_next = 0x8009D6E4u; return; }  /* 0x8009DFC0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009DFC8 */
    { R[31] = 0x8009DFD8u; R[5] = R[0] + 37; psx_next = 0x8009D4B0u; return; }  /* 0x8009DFD0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFD8 */
    { R[31] = 0x8009DFE8u; R[4] = R[0] + R[0]; psx_next = 0x8009D7DCu; return; }  /* 0x8009DFE0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFE8 */
    { R[31] = 0x8009DFF8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009DFF0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFF8 */
    { R[31] = 0x8009E008u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E000 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009E008 */
    { R[31] = 0x8009E018u; R[5] = R[0] + 7; psx_next = 0x8009BC08u; return; }  /* 0x8009E010 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E058; } }  /* 0x8009E018 */
    R[2] = lw_(R[16] + 72);  /* 0x8009E020 */
    R[2] = lh_(R[2]);  /* 0x8009E028 */
    R[2] = R[2] >> 13;  /* 0x8009E030 */
    R[2] = R[2] & 0x1;  /* 0x8009E034 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009E050; } }  /* 0x8009E038 */
    { R[31] = 0x8009E048u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009E040 jal */
    { goto L_8009E068; }  /* 0x8009E048 j */
L_8009E050:;
    { R[6] = R[0] - 1; goto L_8009E060; }  /* 0x8009E050 j */
L_8009E058:;
    R[5] = R[0] - 1;  /* 0x8009E058 */
    R[6] = R[0] + R[0];  /* 0x8009E05C */
L_8009E060:;
    { R[31] = 0x8009E068u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E060 jal */
L_8009E068:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E068 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E06C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E070 jr ra */
    R[2] = 0x8006u << 16;  /* 0x8009E078 */
    R[2] = lb_(R[2] + -12295);  /* 0x8009E07C */
    psx_next = 0x8009E080u; return;  /* fallthrough */
}

void g0_8009DFA4(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009DFA4 */
    R[5] = R[0] + 14;  /* 0x8009DFAC */
    { R[31] = 0x8009DFB8u; R[6] = R[0] + R[0]; psx_next = 0x8009D268u; return; }  /* 0x8009DFB0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009DFB8 */
    { R[31] = 0x8009DFC8u; R[5] = R[0] + 82; psx_next = 0x8009D6E4u; return; }  /* 0x8009DFC0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009DFC8 */
    { R[31] = 0x8009DFD8u; R[5] = R[0] + 37; psx_next = 0x8009D4B0u; return; }  /* 0x8009DFD0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFD8 */
    { R[31] = 0x8009DFE8u; R[4] = R[0] + R[0]; psx_next = 0x8009D7DCu; return; }  /* 0x8009DFE0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFE8 */
    { R[31] = 0x8009DFF8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009DFF0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFF8 */
    { R[31] = 0x8009E008u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E000 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009E008 */
    { R[31] = 0x8009E018u; R[5] = R[0] + 7; psx_next = 0x8009BC08u; return; }  /* 0x8009E010 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E058; } }  /* 0x8009E018 */
    R[2] = lw_(R[16] + 72);  /* 0x8009E020 */
    R[2] = lh_(R[2]);  /* 0x8009E028 */
    R[2] = R[2] >> 13;  /* 0x8009E030 */
    R[2] = R[2] & 0x1;  /* 0x8009E034 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009E050; } }  /* 0x8009E038 */
    { R[31] = 0x8009E048u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009E040 jal */
    { goto L_8009E068; }  /* 0x8009E048 j */
L_8009E050:;
    { R[6] = R[0] - 1; goto L_8009E060; }  /* 0x8009E050 j */
L_8009E058:;
    R[5] = R[0] - 1;  /* 0x8009E058 */
    R[6] = R[0] + R[0];  /* 0x8009E05C */
L_8009E060:;
    { R[31] = 0x8009E068u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E060 jal */
L_8009E068:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E068 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E06C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E070 jr ra */
    R[2] = 0x8006u << 16;  /* 0x8009E078 */
    R[2] = lb_(R[2] + -12295);  /* 0x8009E07C */
    psx_next = 0x8009E080u; return;  /* fallthrough */
}

void g0_8009DFB8(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009DFB8 */
    { R[31] = 0x8009DFC8u; R[5] = R[0] + 82; psx_next = 0x8009D6E4u; return; }  /* 0x8009DFC0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009DFC8 */
    { R[31] = 0x8009DFD8u; R[5] = R[0] + 37; psx_next = 0x8009D4B0u; return; }  /* 0x8009DFD0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFD8 */
    { R[31] = 0x8009DFE8u; R[4] = R[0] + R[0]; psx_next = 0x8009D7DCu; return; }  /* 0x8009DFE0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFE8 */
    { R[31] = 0x8009DFF8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009DFF0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFF8 */
    { R[31] = 0x8009E008u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E000 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009E008 */
    { R[31] = 0x8009E018u; R[5] = R[0] + 7; psx_next = 0x8009BC08u; return; }  /* 0x8009E010 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E058; } }  /* 0x8009E018 */
    R[2] = lw_(R[16] + 72);  /* 0x8009E020 */
    R[2] = lh_(R[2]);  /* 0x8009E028 */
    R[2] = R[2] >> 13;  /* 0x8009E030 */
    R[2] = R[2] & 0x1;  /* 0x8009E034 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009E050; } }  /* 0x8009E038 */
    { R[31] = 0x8009E048u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009E040 jal */
    { goto L_8009E068; }  /* 0x8009E048 j */
L_8009E050:;
    { R[6] = R[0] - 1; goto L_8009E060; }  /* 0x8009E050 j */
L_8009E058:;
    R[5] = R[0] - 1;  /* 0x8009E058 */
    R[6] = R[0] + R[0];  /* 0x8009E05C */
L_8009E060:;
    { R[31] = 0x8009E068u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E060 jal */
L_8009E068:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E068 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E06C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E070 jr ra */
    R[2] = 0x8006u << 16;  /* 0x8009E078 */
    R[2] = lb_(R[2] + -12295);  /* 0x8009E07C */
    psx_next = 0x8009E080u; return;  /* fallthrough */
}

void g0_8009DFC8(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009DFC8 */
    { R[31] = 0x8009DFD8u; R[5] = R[0] + 37; psx_next = 0x8009D4B0u; return; }  /* 0x8009DFD0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFD8 */
    { R[31] = 0x8009DFE8u; R[4] = R[0] + R[0]; psx_next = 0x8009D7DCu; return; }  /* 0x8009DFE0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFE8 */
    { R[31] = 0x8009DFF8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009DFF0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFF8 */
    { R[31] = 0x8009E008u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E000 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009E008 */
    { R[31] = 0x8009E018u; R[5] = R[0] + 7; psx_next = 0x8009BC08u; return; }  /* 0x8009E010 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E058; } }  /* 0x8009E018 */
    R[2] = lw_(R[16] + 72);  /* 0x8009E020 */
    R[2] = lh_(R[2]);  /* 0x8009E028 */
    R[2] = R[2] >> 13;  /* 0x8009E030 */
    R[2] = R[2] & 0x1;  /* 0x8009E034 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009E050; } }  /* 0x8009E038 */
    { R[31] = 0x8009E048u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009E040 jal */
    { goto L_8009E068; }  /* 0x8009E048 j */
L_8009E050:;
    { R[6] = R[0] - 1; goto L_8009E060; }  /* 0x8009E050 j */
L_8009E058:;
    R[5] = R[0] - 1;  /* 0x8009E058 */
    R[6] = R[0] + R[0];  /* 0x8009E05C */
L_8009E060:;
    { R[31] = 0x8009E068u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E060 jal */
L_8009E068:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E068 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E06C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E070 jr ra */
    R[2] = 0x8006u << 16;  /* 0x8009E078 */
    R[2] = lb_(R[2] + -12295);  /* 0x8009E07C */
    psx_next = 0x8009E080u; return;  /* fallthrough */
}

void g0_8009DFD8(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFD8 */
    { R[31] = 0x8009DFE8u; R[4] = R[0] + R[0]; psx_next = 0x8009D7DCu; return; }  /* 0x8009DFE0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFE8 */
    { R[31] = 0x8009DFF8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009DFF0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFF8 */
    { R[31] = 0x8009E008u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E000 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009E008 */
    { R[31] = 0x8009E018u; R[5] = R[0] + 7; psx_next = 0x8009BC08u; return; }  /* 0x8009E010 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E058; } }  /* 0x8009E018 */
    R[2] = lw_(R[16] + 72);  /* 0x8009E020 */
    R[2] = lh_(R[2]);  /* 0x8009E028 */
    R[2] = R[2] >> 13;  /* 0x8009E030 */
    R[2] = R[2] & 0x1;  /* 0x8009E034 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009E050; } }  /* 0x8009E038 */
    { R[31] = 0x8009E048u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009E040 jal */
    { goto L_8009E068; }  /* 0x8009E048 j */
L_8009E050:;
    { R[6] = R[0] - 1; goto L_8009E060; }  /* 0x8009E050 j */
L_8009E058:;
    R[5] = R[0] - 1;  /* 0x8009E058 */
    R[6] = R[0] + R[0];  /* 0x8009E05C */
L_8009E060:;
    { R[31] = 0x8009E068u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E060 jal */
L_8009E068:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E068 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E06C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E070 jr ra */
    R[2] = 0x8006u << 16;  /* 0x8009E078 */
    R[2] = lb_(R[2] + -12295);  /* 0x8009E07C */
    psx_next = 0x8009E080u; return;  /* fallthrough */
}

void g0_8009DFE8(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFE8 */
    { R[31] = 0x8009DFF8u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009DFF0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFF8 */
    { R[31] = 0x8009E008u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E000 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009E008 */
    { R[31] = 0x8009E018u; R[5] = R[0] + 7; psx_next = 0x8009BC08u; return; }  /* 0x8009E010 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E058; } }  /* 0x8009E018 */
    R[2] = lw_(R[16] + 72);  /* 0x8009E020 */
    R[2] = lh_(R[2]);  /* 0x8009E028 */
    R[2] = R[2] >> 13;  /* 0x8009E030 */
    R[2] = R[2] & 0x1;  /* 0x8009E034 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009E050; } }  /* 0x8009E038 */
    { R[31] = 0x8009E048u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009E040 jal */
    { goto L_8009E068; }  /* 0x8009E048 j */
L_8009E050:;
    { R[6] = R[0] - 1; goto L_8009E060; }  /* 0x8009E050 j */
L_8009E058:;
    R[5] = R[0] - 1;  /* 0x8009E058 */
    R[6] = R[0] + R[0];  /* 0x8009E05C */
L_8009E060:;
    { R[31] = 0x8009E068u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E060 jal */
L_8009E068:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E068 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E06C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E070 jr ra */
    R[2] = 0x8006u << 16;  /* 0x8009E078 */
    R[2] = lb_(R[2] + -12295);  /* 0x8009E07C */
    psx_next = 0x8009E080u; return;  /* fallthrough */
}

void g0_8009DFF8(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E068; } }  /* 0x8009DFF8 */
    { R[31] = 0x8009E008u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E000 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009E008 */
    { R[31] = 0x8009E018u; R[5] = R[0] + 7; psx_next = 0x8009BC08u; return; }  /* 0x8009E010 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E058; } }  /* 0x8009E018 */
    R[2] = lw_(R[16] + 72);  /* 0x8009E020 */
    R[2] = lh_(R[2]);  /* 0x8009E028 */
    R[2] = R[2] >> 13;  /* 0x8009E030 */
    R[2] = R[2] & 0x1;  /* 0x8009E034 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009E050; } }  /* 0x8009E038 */
    { R[31] = 0x8009E048u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009E040 jal */
    { goto L_8009E068; }  /* 0x8009E048 j */
L_8009E050:;
    { R[6] = R[0] - 1; goto L_8009E060; }  /* 0x8009E050 j */
L_8009E058:;
    R[5] = R[0] - 1;  /* 0x8009E058 */
    R[6] = R[0] + R[0];  /* 0x8009E05C */
L_8009E060:;
    { R[31] = 0x8009E068u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E060 jal */
L_8009E068:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E068 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E06C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E070 jr ra */
    R[2] = 0x8006u << 16;  /* 0x8009E078 */
    R[2] = lb_(R[2] + -12295);  /* 0x8009E07C */
    psx_next = 0x8009E080u; return;  /* fallthrough */
}

void g0_8009E008(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E068; } }  /* 0x8009E008 */
    { R[31] = 0x8009E018u; R[5] = R[0] + 7; psx_next = 0x8009BC08u; return; }  /* 0x8009E010 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E058; } }  /* 0x8009E018 */
    R[2] = lw_(R[16] + 72);  /* 0x8009E020 */
    R[2] = lh_(R[2]);  /* 0x8009E028 */
    R[2] = R[2] >> 13;  /* 0x8009E030 */
    R[2] = R[2] & 0x1;  /* 0x8009E034 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009E050; } }  /* 0x8009E038 */
    { R[31] = 0x8009E048u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009E040 jal */
    { goto L_8009E068; }  /* 0x8009E048 j */
L_8009E050:;
    { R[6] = R[0] - 1; goto L_8009E060; }  /* 0x8009E050 j */
L_8009E058:;
    R[5] = R[0] - 1;  /* 0x8009E058 */
    R[6] = R[0] + R[0];  /* 0x8009E05C */
L_8009E060:;
    { R[31] = 0x8009E068u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E060 jal */
L_8009E068:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E068 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E06C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E070 jr ra */
    R[2] = 0x8006u << 16;  /* 0x8009E078 */
    R[2] = lb_(R[2] + -12295);  /* 0x8009E07C */
    psx_next = 0x8009E080u; return;  /* fallthrough */
}

void g0_8009E018(void) {
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E058; } }  /* 0x8009E018 */
    R[2] = lw_(R[16] + 72);  /* 0x8009E020 */
    R[2] = lh_(R[2]);  /* 0x8009E028 */
    R[2] = R[2] >> 13;  /* 0x8009E030 */
    R[2] = R[2] & 0x1;  /* 0x8009E034 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009E050; } }  /* 0x8009E038 */
    { R[31] = 0x8009E048u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009E040 jal */
    { goto L_8009E068; }  /* 0x8009E048 j */
L_8009E050:;
    { R[6] = R[0] - 1; goto L_8009E060; }  /* 0x8009E050 j */
L_8009E058:;
    R[5] = R[0] - 1;  /* 0x8009E058 */
    R[6] = R[0] + R[0];  /* 0x8009E05C */
L_8009E060:;
    { R[31] = 0x8009E068u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E060 jal */
L_8009E068:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E068 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E06C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E070 jr ra */
    R[2] = 0x8006u << 16;  /* 0x8009E078 */
    R[2] = lb_(R[2] + -12295);  /* 0x8009E07C */
    psx_next = 0x8009E080u; return;  /* fallthrough */
}

void g0_8009E048(void) {
    { goto L_8009E068; }  /* 0x8009E048 j */
    { R[6] = R[0] - 1; goto L_8009E060; }  /* 0x8009E050 j */
    R[5] = R[0] - 1;  /* 0x8009E058 */
    R[6] = R[0] + R[0];  /* 0x8009E05C */
L_8009E060:;
    { R[31] = 0x8009E068u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E060 jal */
L_8009E068:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E068 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E06C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E070 jr ra */
    R[2] = 0x8006u << 16;  /* 0x8009E078 */
    R[2] = lb_(R[2] + -12295);  /* 0x8009E07C */
    psx_next = 0x8009E080u; return;  /* fallthrough */
}

void g0_8009E068(void) {
    R[31] = lw_(R[29] + 20);  /* 0x8009E068 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E06C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E070 jr ra */
    R[2] = 0x8006u << 16;  /* 0x8009E078 */
    R[2] = lb_(R[2] + -12295);  /* 0x8009E07C */
    psx_next = 0x8009E080u; return;  /* fallthrough */
}

void g0_8009E078(void) {
    R[2] = 0x8006u << 16;  /* 0x8009E078 */
    R[2] = lb_(R[2] + -12295);  /* 0x8009E07C */
    psx_next = 0x8009E080u; return;  /* fallthrough */
}

void g0_8009E080(void) {
    R[29] = R[29] - 24;  /* 0x8009E080 */
    sw_(R[29] + 16, R[16]);  /* 0x8009E084 */
    R[16] = R[4] + R[0];  /* 0x8009E088 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[29] + 20, R[31]); if (_c) { goto L_8009E0AC; } }  /* 0x8009E08C */
    R[2] = 0x8006u << 16;  /* 0x8009E094 */
    R[2] = lh_(R[2] + -6454);  /* 0x8009E098 */
    R[2] = R[2] & 0x100;  /* 0x8009E0A0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009E0D0; } }  /* 0x8009E0A4 */
L_8009E0AC:;
    R[2] = lb_(R[16] + 784);  /* 0x8009E0AC */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009E0D0; } }  /* 0x8009E0B4 */
    R[4] = R[16] + R[0];  /* 0x8009E0BC */
    { R[31] = 0x8009E0C8u; R[5] = R[0] + 19; psx_next = 0x8009BC84u; return; }  /* 0x8009E0C0 jal */
    { psx_next = 0x8009E2B4u; return; }  /* 0x8009E0C8 j extern */
L_8009E0D0:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + -29588);  /* 0x8009E0D0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E128; } }  /* 0x8009E0D8 */
    R[3] = lw_(R[16] + 352);  /* 0x8009E0E0 */
    R[2] = lb_(R[3] + 1);  /* 0x8009E0E8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009E138u; return; } }  /* 0x8009E0F0 b extern */
    R[2] = lw_(R[3] + 24);  /* 0x8009E0F8 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 26);  /* 0x8009E100 */
    R[2] = ((int32_t)R[2] < 2049);  /* 0x8009E108 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009E138u; return; } }  /* 0x8009E10C b extern */
    R[2] = lw_(R[3] + 20);  /* 0x8009E114 */
    R[3] = 0x10u << 16;  /* 0x8009E118 */
    R[2] = R[2] & R[3];  /* 0x8009E11C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E138u; return; } }  /* 0x8009E120 b extern */
L_8009E128:;
    { R[31] = 0x8009E130u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009E128 jal */
    { psx_next = 0x8009E2B4u; return; }  /* 0x8009E130 j extern */
}

void g0_8009E0C8(void) {
    { psx_next = 0x8009E2B4u; return; }  /* 0x8009E0C8 j extern */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + -29588);  /* 0x8009E0D0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E128; } }  /* 0x8009E0D8 */
    R[3] = lw_(R[16] + 352);  /* 0x8009E0E0 */
    R[2] = lb_(R[3] + 1);  /* 0x8009E0E8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009E138u; return; } }  /* 0x8009E0F0 b extern */
    R[2] = lw_(R[3] + 24);  /* 0x8009E0F8 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 26);  /* 0x8009E100 */
    R[2] = ((int32_t)R[2] < 2049);  /* 0x8009E108 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009E138u; return; } }  /* 0x8009E10C b extern */
    R[2] = lw_(R[3] + 20);  /* 0x8009E114 */
    R[3] = 0x10u << 16;  /* 0x8009E118 */
    R[2] = R[2] & R[3];  /* 0x8009E11C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E138u; return; } }  /* 0x8009E120 b extern */
L_8009E128:;
    { R[31] = 0x8009E130u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009E128 jal */
    { psx_next = 0x8009E2B4u; return; }  /* 0x8009E130 j extern */
}

void g0_8009E130(void) {
    { psx_next = 0x8009E2B4u; return; }  /* 0x8009E130 j extern */
}

void g0_8009E134(void) {
    { R[31] = 0x8009E140u; psx_next = 0x8009ADF4u; return; }  /* 0x8009E138 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E140 b extern */
    { R[31] = 0x8009E150u; R[4] = R[16] + R[0]; psx_next = 0x8009BF0Cu; return; }  /* 0x8009E148 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E150 b extern */
    { R[31] = 0x8009E160u; R[4] = R[16] + R[0]; psx_next = 0x8009C3A4u; return; }  /* 0x8009E158 jal */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] + 18; if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E160 b extern */
    R[4] = R[16] + R[0];  /* 0x8009E168 */
    { R[31] = 0x8009E174u; R[6] = R[0] + R[0]; psx_next = 0x8009D268u; return; }  /* 0x8009E16C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E174 b extern */
    R[4] = R[16] + R[0];  /* 0x8009E17C */
    { R[31] = 0x8009E188u; R[5] = R[0] + 87; psx_next = 0x8009D6E4u; return; }  /* 0x8009E180 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E188 b extern */
    R[4] = R[16] + R[0];  /* 0x8009E190 */
    { R[31] = 0x8009E19Cu; R[5] = R[0] + 128; psx_next = 0x8009D788u; return; }  /* 0x8009E194 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E19C b extern */
    R[4] = R[16] + R[0];  /* 0x8009E1A4 */
    { R[31] = 0x8009E1B0u; R[5] = R[0] + 96; psx_next = 0x8009D4B0u; return; }  /* 0x8009E1A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_8009E1E8; } }  /* 0x8009E1B0 */
    R[2] = 0x8006u << 16;  /* 0x8009E1B8 */
    R[2] = lh_(R[2] + 16104);  /* 0x8009E1BC */
    R[3] = R[0] + 20;  /* 0x8009E1C0 */
    R[2] = R[2] & 0x1;  /* 0x8009E1C4 */
    { uint32_t _c = (R[2] != R[0]); sh_(R[4] + -29650, R[3]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1C8 b extern */
    R[2] = 0x8012u << 16;  /* 0x8009E1D0 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009E1D4 */
    R[2] = R[0] + 18617;  /* 0x8009E1D8 */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009E1DC */
    { sw_(R[16] + 140, R[2]); psx_next = 0x8009E2B4u; return; }  /* 0x8009E1E0 j extern */
L_8009E1E8:;
    { R[31] = 0x8009E1F0u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E1E8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1F0 b extern */
    R[3] = lb_(R[16] + 784);  /* 0x8009E1F8 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E210; } }  /* 0x8009E200 */
    R[2] = R[0] + 2;  /* 0x8009E208 */
    sb_(R[16] + 795, R[2]);  /* 0x8009E20C */
L_8009E210:;
    R[5] = R[0] - 1;  /* 0x8009E210 */
    R[6] = R[0] + R[0];  /* 0x8009E214 */
    { R[31] = 0x8009E220u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E218 jal */
    R[2] = 0x8006u << 16;  /* 0x8009E220 */
    R[3] = R[2] + 13192;  /* 0x8009E224 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 38);  /* 0x8009E228 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009E258u; return; } }  /* 0x8009E230 b extern */
    psx_next = 0x8009E238u; return;  /* fallthrough */
}

void g0_8009E138(void) {
    { R[31] = 0x8009E140u; psx_next = 0x8009ADF4u; return; }  /* 0x8009E138 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E140 b extern */
    { R[31] = 0x8009E150u; R[4] = R[16] + R[0]; psx_next = 0x8009BF0Cu; return; }  /* 0x8009E148 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E150 b extern */
    { R[31] = 0x8009E160u; R[4] = R[16] + R[0]; psx_next = 0x8009C3A4u; return; }  /* 0x8009E158 jal */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] + 18; if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E160 b extern */
    R[4] = R[16] + R[0];  /* 0x8009E168 */
    { R[31] = 0x8009E174u; R[6] = R[0] + R[0]; psx_next = 0x8009D268u; return; }  /* 0x8009E16C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E174 b extern */
    R[4] = R[16] + R[0];  /* 0x8009E17C */
    { R[31] = 0x8009E188u; R[5] = R[0] + 87; psx_next = 0x8009D6E4u; return; }  /* 0x8009E180 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E188 b extern */
    R[4] = R[16] + R[0];  /* 0x8009E190 */
    { R[31] = 0x8009E19Cu; R[5] = R[0] + 128; psx_next = 0x8009D788u; return; }  /* 0x8009E194 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E19C b extern */
    R[4] = R[16] + R[0];  /* 0x8009E1A4 */
    { R[31] = 0x8009E1B0u; R[5] = R[0] + 96; psx_next = 0x8009D4B0u; return; }  /* 0x8009E1A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_8009E1E8; } }  /* 0x8009E1B0 */
    R[2] = 0x8006u << 16;  /* 0x8009E1B8 */
    R[2] = lh_(R[2] + 16104);  /* 0x8009E1BC */
    R[3] = R[0] + 20;  /* 0x8009E1C0 */
    R[2] = R[2] & 0x1;  /* 0x8009E1C4 */
    { uint32_t _c = (R[2] != R[0]); sh_(R[4] + -29650, R[3]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1C8 b extern */
    R[2] = 0x8012u << 16;  /* 0x8009E1D0 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009E1D4 */
    R[2] = R[0] + 18617;  /* 0x8009E1D8 */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009E1DC */
    { sw_(R[16] + 140, R[2]); psx_next = 0x8009E2B4u; return; }  /* 0x8009E1E0 j extern */
L_8009E1E8:;
    { R[31] = 0x8009E1F0u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E1E8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1F0 b extern */
    R[3] = lb_(R[16] + 784);  /* 0x8009E1F8 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E210; } }  /* 0x8009E200 */
    R[2] = R[0] + 2;  /* 0x8009E208 */
    sb_(R[16] + 795, R[2]);  /* 0x8009E20C */
L_8009E210:;
    R[5] = R[0] - 1;  /* 0x8009E210 */
    R[6] = R[0] + R[0];  /* 0x8009E214 */
    { R[31] = 0x8009E220u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E218 jal */
    R[2] = 0x8006u << 16;  /* 0x8009E220 */
    R[3] = R[2] + 13192;  /* 0x8009E224 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 38);  /* 0x8009E228 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009E258u; return; } }  /* 0x8009E230 b extern */
    psx_next = 0x8009E238u; return;  /* fallthrough */
}

void g0_8009E140(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E140 b extern */
    { R[31] = 0x8009E150u; R[4] = R[16] + R[0]; psx_next = 0x8009BF0Cu; return; }  /* 0x8009E148 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E150 b extern */
    { R[31] = 0x8009E160u; R[4] = R[16] + R[0]; psx_next = 0x8009C3A4u; return; }  /* 0x8009E158 jal */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] + 18; if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E160 b extern */
    R[4] = R[16] + R[0];  /* 0x8009E168 */
    { R[31] = 0x8009E174u; R[6] = R[0] + R[0]; psx_next = 0x8009D268u; return; }  /* 0x8009E16C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E174 b extern */
    R[4] = R[16] + R[0];  /* 0x8009E17C */
    { R[31] = 0x8009E188u; R[5] = R[0] + 87; psx_next = 0x8009D6E4u; return; }  /* 0x8009E180 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E188 b extern */
    R[4] = R[16] + R[0];  /* 0x8009E190 */
    { R[31] = 0x8009E19Cu; R[5] = R[0] + 128; psx_next = 0x8009D788u; return; }  /* 0x8009E194 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E19C b extern */
    R[4] = R[16] + R[0];  /* 0x8009E1A4 */
    { R[31] = 0x8009E1B0u; R[5] = R[0] + 96; psx_next = 0x8009D4B0u; return; }  /* 0x8009E1A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_8009E1E8; } }  /* 0x8009E1B0 */
    R[2] = 0x8006u << 16;  /* 0x8009E1B8 */
    R[2] = lh_(R[2] + 16104);  /* 0x8009E1BC */
    R[3] = R[0] + 20;  /* 0x8009E1C0 */
    R[2] = R[2] & 0x1;  /* 0x8009E1C4 */
    { uint32_t _c = (R[2] != R[0]); sh_(R[4] + -29650, R[3]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1C8 b extern */
    R[2] = 0x8012u << 16;  /* 0x8009E1D0 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009E1D4 */
    R[2] = R[0] + 18617;  /* 0x8009E1D8 */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009E1DC */
    { sw_(R[16] + 140, R[2]); psx_next = 0x8009E2B4u; return; }  /* 0x8009E1E0 j extern */
L_8009E1E8:;
    { R[31] = 0x8009E1F0u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E1E8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1F0 b extern */
    R[3] = lb_(R[16] + 784);  /* 0x8009E1F8 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E210; } }  /* 0x8009E200 */
    R[2] = R[0] + 2;  /* 0x8009E208 */
    sb_(R[16] + 795, R[2]);  /* 0x8009E20C */
L_8009E210:;
    R[5] = R[0] - 1;  /* 0x8009E210 */
    R[6] = R[0] + R[0];  /* 0x8009E214 */
    { R[31] = 0x8009E220u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E218 jal */
    R[2] = 0x8006u << 16;  /* 0x8009E220 */
    R[3] = R[2] + 13192;  /* 0x8009E224 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 38);  /* 0x8009E228 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009E258u; return; } }  /* 0x8009E230 b extern */
    psx_next = 0x8009E238u; return;  /* fallthrough */
}

void g0_8009E150(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E150 b extern */
    { R[31] = 0x8009E160u; R[4] = R[16] + R[0]; psx_next = 0x8009C3A4u; return; }  /* 0x8009E158 jal */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] + 18; if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E160 b extern */
    R[4] = R[16] + R[0];  /* 0x8009E168 */
    { R[31] = 0x8009E174u; R[6] = R[0] + R[0]; psx_next = 0x8009D268u; return; }  /* 0x8009E16C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E174 b extern */
    R[4] = R[16] + R[0];  /* 0x8009E17C */
    { R[31] = 0x8009E188u; R[5] = R[0] + 87; psx_next = 0x8009D6E4u; return; }  /* 0x8009E180 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E188 b extern */
    R[4] = R[16] + R[0];  /* 0x8009E190 */
    { R[31] = 0x8009E19Cu; R[5] = R[0] + 128; psx_next = 0x8009D788u; return; }  /* 0x8009E194 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E19C b extern */
    R[4] = R[16] + R[0];  /* 0x8009E1A4 */
    { R[31] = 0x8009E1B0u; R[5] = R[0] + 96; psx_next = 0x8009D4B0u; return; }  /* 0x8009E1A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_8009E1E8; } }  /* 0x8009E1B0 */
    R[2] = 0x8006u << 16;  /* 0x8009E1B8 */
    R[2] = lh_(R[2] + 16104);  /* 0x8009E1BC */
    R[3] = R[0] + 20;  /* 0x8009E1C0 */
    R[2] = R[2] & 0x1;  /* 0x8009E1C4 */
    { uint32_t _c = (R[2] != R[0]); sh_(R[4] + -29650, R[3]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1C8 b extern */
    R[2] = 0x8012u << 16;  /* 0x8009E1D0 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009E1D4 */
    R[2] = R[0] + 18617;  /* 0x8009E1D8 */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009E1DC */
    { sw_(R[16] + 140, R[2]); psx_next = 0x8009E2B4u; return; }  /* 0x8009E1E0 j extern */
L_8009E1E8:;
    { R[31] = 0x8009E1F0u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E1E8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1F0 b extern */
    R[3] = lb_(R[16] + 784);  /* 0x8009E1F8 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E210; } }  /* 0x8009E200 */
    R[2] = R[0] + 2;  /* 0x8009E208 */
    sb_(R[16] + 795, R[2]);  /* 0x8009E20C */
L_8009E210:;
    R[5] = R[0] - 1;  /* 0x8009E210 */
    R[6] = R[0] + R[0];  /* 0x8009E214 */
    { R[31] = 0x8009E220u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E218 jal */
    R[2] = 0x8006u << 16;  /* 0x8009E220 */
    R[3] = R[2] + 13192;  /* 0x8009E224 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 38);  /* 0x8009E228 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009E258u; return; } }  /* 0x8009E230 b extern */
    psx_next = 0x8009E238u; return;  /* fallthrough */
}

void g0_8009E160(void) {
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] + 18; if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E160 b extern */
    R[4] = R[16] + R[0];  /* 0x8009E168 */
    { R[31] = 0x8009E174u; R[6] = R[0] + R[0]; psx_next = 0x8009D268u; return; }  /* 0x8009E16C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E174 b extern */
    R[4] = R[16] + R[0];  /* 0x8009E17C */
    { R[31] = 0x8009E188u; R[5] = R[0] + 87; psx_next = 0x8009D6E4u; return; }  /* 0x8009E180 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E188 b extern */
    R[4] = R[16] + R[0];  /* 0x8009E190 */
    { R[31] = 0x8009E19Cu; R[5] = R[0] + 128; psx_next = 0x8009D788u; return; }  /* 0x8009E194 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E19C b extern */
    R[4] = R[16] + R[0];  /* 0x8009E1A4 */
    { R[31] = 0x8009E1B0u; R[5] = R[0] + 96; psx_next = 0x8009D4B0u; return; }  /* 0x8009E1A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_8009E1E8; } }  /* 0x8009E1B0 */
    R[2] = 0x8006u << 16;  /* 0x8009E1B8 */
    R[2] = lh_(R[2] + 16104);  /* 0x8009E1BC */
    R[3] = R[0] + 20;  /* 0x8009E1C0 */
    R[2] = R[2] & 0x1;  /* 0x8009E1C4 */
    { uint32_t _c = (R[2] != R[0]); sh_(R[4] + -29650, R[3]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1C8 b extern */
    R[2] = 0x8012u << 16;  /* 0x8009E1D0 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009E1D4 */
    R[2] = R[0] + 18617;  /* 0x8009E1D8 */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009E1DC */
    { sw_(R[16] + 140, R[2]); psx_next = 0x8009E2B4u; return; }  /* 0x8009E1E0 j extern */
L_8009E1E8:;
    { R[31] = 0x8009E1F0u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E1E8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1F0 b extern */
    R[3] = lb_(R[16] + 784);  /* 0x8009E1F8 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E210; } }  /* 0x8009E200 */
    R[2] = R[0] + 2;  /* 0x8009E208 */
    sb_(R[16] + 795, R[2]);  /* 0x8009E20C */
L_8009E210:;
    R[5] = R[0] - 1;  /* 0x8009E210 */
    R[6] = R[0] + R[0];  /* 0x8009E214 */
    { R[31] = 0x8009E220u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E218 jal */
    R[2] = 0x8006u << 16;  /* 0x8009E220 */
    R[3] = R[2] + 13192;  /* 0x8009E224 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 38);  /* 0x8009E228 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009E258u; return; } }  /* 0x8009E230 b extern */
    psx_next = 0x8009E238u; return;  /* fallthrough */
}

void g0_8009E174(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E174 b extern */
    R[4] = R[16] + R[0];  /* 0x8009E17C */
    { R[31] = 0x8009E188u; R[5] = R[0] + 87; psx_next = 0x8009D6E4u; return; }  /* 0x8009E180 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E188 b extern */
    R[4] = R[16] + R[0];  /* 0x8009E190 */
    { R[31] = 0x8009E19Cu; R[5] = R[0] + 128; psx_next = 0x8009D788u; return; }  /* 0x8009E194 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E19C b extern */
    R[4] = R[16] + R[0];  /* 0x8009E1A4 */
    { R[31] = 0x8009E1B0u; R[5] = R[0] + 96; psx_next = 0x8009D4B0u; return; }  /* 0x8009E1A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_8009E1E8; } }  /* 0x8009E1B0 */
    R[2] = 0x8006u << 16;  /* 0x8009E1B8 */
    R[2] = lh_(R[2] + 16104);  /* 0x8009E1BC */
    R[3] = R[0] + 20;  /* 0x8009E1C0 */
    R[2] = R[2] & 0x1;  /* 0x8009E1C4 */
    { uint32_t _c = (R[2] != R[0]); sh_(R[4] + -29650, R[3]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1C8 b extern */
    R[2] = 0x8012u << 16;  /* 0x8009E1D0 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009E1D4 */
    R[2] = R[0] + 18617;  /* 0x8009E1D8 */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009E1DC */
    { sw_(R[16] + 140, R[2]); psx_next = 0x8009E2B4u; return; }  /* 0x8009E1E0 j extern */
L_8009E1E8:;
    { R[31] = 0x8009E1F0u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E1E8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1F0 b extern */
    R[3] = lb_(R[16] + 784);  /* 0x8009E1F8 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E210; } }  /* 0x8009E200 */
    R[2] = R[0] + 2;  /* 0x8009E208 */
    sb_(R[16] + 795, R[2]);  /* 0x8009E20C */
L_8009E210:;
    R[5] = R[0] - 1;  /* 0x8009E210 */
    R[6] = R[0] + R[0];  /* 0x8009E214 */
    { R[31] = 0x8009E220u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E218 jal */
    R[2] = 0x8006u << 16;  /* 0x8009E220 */
    R[3] = R[2] + 13192;  /* 0x8009E224 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 38);  /* 0x8009E228 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009E258u; return; } }  /* 0x8009E230 b extern */
    psx_next = 0x8009E238u; return;  /* fallthrough */
}

void g0_8009E188(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E188 b extern */
    R[4] = R[16] + R[0];  /* 0x8009E190 */
    { R[31] = 0x8009E19Cu; R[5] = R[0] + 128; psx_next = 0x8009D788u; return; }  /* 0x8009E194 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E19C b extern */
    R[4] = R[16] + R[0];  /* 0x8009E1A4 */
    { R[31] = 0x8009E1B0u; R[5] = R[0] + 96; psx_next = 0x8009D4B0u; return; }  /* 0x8009E1A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_8009E1E8; } }  /* 0x8009E1B0 */
    R[2] = 0x8006u << 16;  /* 0x8009E1B8 */
    R[2] = lh_(R[2] + 16104);  /* 0x8009E1BC */
    R[3] = R[0] + 20;  /* 0x8009E1C0 */
    R[2] = R[2] & 0x1;  /* 0x8009E1C4 */
    { uint32_t _c = (R[2] != R[0]); sh_(R[4] + -29650, R[3]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1C8 b extern */
    R[2] = 0x8012u << 16;  /* 0x8009E1D0 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009E1D4 */
    R[2] = R[0] + 18617;  /* 0x8009E1D8 */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009E1DC */
    { sw_(R[16] + 140, R[2]); psx_next = 0x8009E2B4u; return; }  /* 0x8009E1E0 j extern */
L_8009E1E8:;
    { R[31] = 0x8009E1F0u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E1E8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1F0 b extern */
    R[3] = lb_(R[16] + 784);  /* 0x8009E1F8 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E210; } }  /* 0x8009E200 */
    R[2] = R[0] + 2;  /* 0x8009E208 */
    sb_(R[16] + 795, R[2]);  /* 0x8009E20C */
L_8009E210:;
    R[5] = R[0] - 1;  /* 0x8009E210 */
    R[6] = R[0] + R[0];  /* 0x8009E214 */
    { R[31] = 0x8009E220u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E218 jal */
    R[2] = 0x8006u << 16;  /* 0x8009E220 */
    R[3] = R[2] + 13192;  /* 0x8009E224 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 38);  /* 0x8009E228 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009E258u; return; } }  /* 0x8009E230 b extern */
    psx_next = 0x8009E238u; return;  /* fallthrough */
}

void g0_8009E19C(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E19C b extern */
    R[4] = R[16] + R[0];  /* 0x8009E1A4 */
    { R[31] = 0x8009E1B0u; R[5] = R[0] + 96; psx_next = 0x8009D4B0u; return; }  /* 0x8009E1A8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_8009E1E8; } }  /* 0x8009E1B0 */
    R[2] = 0x8006u << 16;  /* 0x8009E1B8 */
    R[2] = lh_(R[2] + 16104);  /* 0x8009E1BC */
    R[3] = R[0] + 20;  /* 0x8009E1C0 */
    R[2] = R[2] & 0x1;  /* 0x8009E1C4 */
    { uint32_t _c = (R[2] != R[0]); sh_(R[4] + -29650, R[3]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1C8 b extern */
    R[2] = 0x8012u << 16;  /* 0x8009E1D0 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009E1D4 */
    R[2] = R[0] + 18617;  /* 0x8009E1D8 */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009E1DC */
    { sw_(R[16] + 140, R[2]); psx_next = 0x8009E2B4u; return; }  /* 0x8009E1E0 j extern */
L_8009E1E8:;
    { R[31] = 0x8009E1F0u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E1E8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1F0 b extern */
    R[3] = lb_(R[16] + 784);  /* 0x8009E1F8 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E210; } }  /* 0x8009E200 */
    R[2] = R[0] + 2;  /* 0x8009E208 */
    sb_(R[16] + 795, R[2]);  /* 0x8009E20C */
L_8009E210:;
    R[5] = R[0] - 1;  /* 0x8009E210 */
    R[6] = R[0] + R[0];  /* 0x8009E214 */
    { R[31] = 0x8009E220u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E218 jal */
    R[2] = 0x8006u << 16;  /* 0x8009E220 */
    R[3] = R[2] + 13192;  /* 0x8009E224 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 38);  /* 0x8009E228 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009E258u; return; } }  /* 0x8009E230 b extern */
    psx_next = 0x8009E238u; return;  /* fallthrough */
}

void g0_8009E1B0(void) {
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8013u << 16; if (_c) { goto L_8009E1E8; } }  /* 0x8009E1B0 */
    R[2] = 0x8006u << 16;  /* 0x8009E1B8 */
    R[2] = lh_(R[2] + 16104);  /* 0x8009E1BC */
    R[3] = R[0] + 20;  /* 0x8009E1C0 */
    R[2] = R[2] & 0x1;  /* 0x8009E1C4 */
    { uint32_t _c = (R[2] != R[0]); sh_(R[4] + -29650, R[3]); if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1C8 b extern */
    R[2] = 0x8012u << 16;  /* 0x8009E1D0 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009E1D4 */
    R[2] = R[0] + 18617;  /* 0x8009E1D8 */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009E1DC */
    { sw_(R[16] + 140, R[2]); psx_next = 0x8009E2B4u; return; }  /* 0x8009E1E0 j extern */
L_8009E1E8:;
    { R[31] = 0x8009E1F0u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E1E8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1F0 b extern */
    R[3] = lb_(R[16] + 784);  /* 0x8009E1F8 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E210; } }  /* 0x8009E200 */
    R[2] = R[0] + 2;  /* 0x8009E208 */
    sb_(R[16] + 795, R[2]);  /* 0x8009E20C */
L_8009E210:;
    R[5] = R[0] - 1;  /* 0x8009E210 */
    R[6] = R[0] + R[0];  /* 0x8009E214 */
    { R[31] = 0x8009E220u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E218 jal */
    R[2] = 0x8006u << 16;  /* 0x8009E220 */
    R[3] = R[2] + 13192;  /* 0x8009E224 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 38);  /* 0x8009E228 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009E258u; return; } }  /* 0x8009E230 b extern */
    psx_next = 0x8009E238u; return;  /* fallthrough */
}

void g0_8009E1F0(void) {
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { psx_next = 0x8009E2B4u; return; } }  /* 0x8009E1F0 b extern */
    R[3] = lb_(R[16] + 784);  /* 0x8009E1F8 */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E210; } }  /* 0x8009E200 */
    R[2] = R[0] + 2;  /* 0x8009E208 */
    sb_(R[16] + 795, R[2]);  /* 0x8009E20C */
L_8009E210:;
    R[5] = R[0] - 1;  /* 0x8009E210 */
    R[6] = R[0] + R[0];  /* 0x8009E214 */
    { R[31] = 0x8009E220u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E218 jal */
    R[2] = 0x8006u << 16;  /* 0x8009E220 */
    R[3] = R[2] + 13192;  /* 0x8009E224 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 38);  /* 0x8009E228 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009E258u; return; } }  /* 0x8009E230 b extern */
    psx_next = 0x8009E238u; return;  /* fallthrough */
}

void g0_8009E220(void) {
    R[2] = 0x8006u << 16;  /* 0x8009E220 */
    R[3] = R[2] + 13192;  /* 0x8009E224 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 38);  /* 0x8009E228 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009E258u; return; } }  /* 0x8009E230 b extern */
    psx_next = 0x8009E238u; return;  /* fallthrough */
}

void g0_8009E238(void) {
    R[2] = lh_(R[2] + -6454);  /* 0x8009E238 */
    R[3] = lh_(R[3] + 2928);  /* 0x8009E23C */
    R[2] = R[2] & R[3];  /* 0x8009E244 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E258; } }  /* 0x8009E248 */
    { R[31] = 0x8009E258u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009E250 jal */
L_8009E258:;
    { R[31] = 0x8009E260u; R[4] = R[0] + R[0]; psx_next = 0x8009BB90u; return; }  /* 0x8009E258 jal */
    R[2] = R[2] << 16;  /* 0x8009E260 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 20);  /* 0x8009E264 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009E268 */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009E2B4; } }  /* 0x8009E26C */
    R[2] = lw_(R[16] + 172);  /* 0x8009E274 */
    R[3] = R[2] >> 31;  /* 0x8009E27C */
    R[2] = R[2] + R[3];  /* 0x8009E280 */
    R[3] = lw_(R[16] + 176);  /* 0x8009E284 */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x8009E288 */
    sw_(R[16] + 172, R[2]);  /* 0x8009E28C */
    R[2] = R[3] >> 31;  /* 0x8009E290 */
    R[3] = R[3] + R[2];  /* 0x8009E294 */
    R[2] = lw_(R[16] + 180);  /* 0x8009E298 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009E29C */
    sw_(R[16] + 176, R[3]);  /* 0x8009E2A0 */
    R[3] = R[2] >> 31;  /* 0x8009E2A4 */
    R[2] = R[2] + R[3];  /* 0x8009E2A8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x8009E2AC */
    sw_(R[16] + 180, R[2]);  /* 0x8009E2B0 */
L_8009E2B4:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E2B4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E2B8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E2BC jr ra */
}

void g0_8009E258(void) {
    { R[31] = 0x8009E260u; R[4] = R[0] + R[0]; psx_next = 0x8009BB90u; return; }  /* 0x8009E258 jal */
    R[2] = R[2] << 16;  /* 0x8009E260 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 20);  /* 0x8009E264 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009E268 */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009E2B4; } }  /* 0x8009E26C */
    R[2] = lw_(R[16] + 172);  /* 0x8009E274 */
    R[3] = R[2] >> 31;  /* 0x8009E27C */
    R[2] = R[2] + R[3];  /* 0x8009E280 */
    R[3] = lw_(R[16] + 176);  /* 0x8009E284 */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x8009E288 */
    sw_(R[16] + 172, R[2]);  /* 0x8009E28C */
    R[2] = R[3] >> 31;  /* 0x8009E290 */
    R[3] = R[3] + R[2];  /* 0x8009E294 */
    R[2] = lw_(R[16] + 180);  /* 0x8009E298 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009E29C */
    sw_(R[16] + 176, R[3]);  /* 0x8009E2A0 */
    R[3] = R[2] >> 31;  /* 0x8009E2A4 */
    R[2] = R[2] + R[3];  /* 0x8009E2A8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x8009E2AC */
    sw_(R[16] + 180, R[2]);  /* 0x8009E2B0 */
L_8009E2B4:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E2B4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E2B8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E2BC jr ra */
}

void g0_8009E260(void) {
    R[2] = R[2] << 16;  /* 0x8009E260 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 20);  /* 0x8009E264 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009E268 */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009E2B4; } }  /* 0x8009E26C */
    R[2] = lw_(R[16] + 172);  /* 0x8009E274 */
    R[3] = R[2] >> 31;  /* 0x8009E27C */
    R[2] = R[2] + R[3];  /* 0x8009E280 */
    R[3] = lw_(R[16] + 176);  /* 0x8009E284 */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x8009E288 */
    sw_(R[16] + 172, R[2]);  /* 0x8009E28C */
    R[2] = R[3] >> 31;  /* 0x8009E290 */
    R[3] = R[3] + R[2];  /* 0x8009E294 */
    R[2] = lw_(R[16] + 180);  /* 0x8009E298 */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009E29C */
    sw_(R[16] + 176, R[3]);  /* 0x8009E2A0 */
    R[3] = R[2] >> 31;  /* 0x8009E2A4 */
    R[2] = R[2] + R[3];  /* 0x8009E2A8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x8009E2AC */
    sw_(R[16] + 180, R[2]);  /* 0x8009E2B0 */
L_8009E2B4:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E2B4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E2B8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E2BC jr ra */
}

void g0_8009E2B4(void) {
    R[31] = lw_(R[29] + 20);  /* 0x8009E2B4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E2B8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E2BC jr ra */
}

void g0_8009E2C4(void) {
    R[29] = R[29] - 24;  /* 0x8009E2C4 */
    sw_(R[29] + 16, R[16]);  /* 0x8009E2C8 */
    sw_(R[29] + 20, R[31]);  /* 0x8009E2CC */
    psx_next = 0x8009E2D0u; return;  /* fallthrough */
}

void g0_8009E2D0(void) {
    { R[31] = 0x8009E2D8u; R[16] = R[4] + R[0]; psx_next = 0x8009D8D0u; return; }  /* 0x8009E2D0 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E2D8 b extern */
    { R[31] = 0x8009E2E8u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E2E0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E2E8 b extern */
    { R[31] = 0x8009E2F8u; R[5] = R[0] + 84; psx_next = 0x8009D6E4u; return; }  /* 0x8009E2F0 jal */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E314; } }  /* 0x8009E2F8 */
    R[4] = R[16] + R[0];  /* 0x8009E300 */
    { R[31] = 0x8009E30Cu; R[5] = R[0] + 89; psx_next = 0x8009D4B0u; return; }  /* 0x8009E304 jal */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E320; } }  /* 0x8009E30C */
L_8009E314:;
    R[2] = R[0] + 20;  /* 0x8009E314 */
    { sh_(R[3] + -29650, R[2]); psx_next = 0x8009E444u; return; }  /* 0x8009E318 j extern */
L_8009E320:;
    { R[31] = 0x8009E328u; R[4] = R[0] + 1; psx_next = 0x8009D7DCu; return; }  /* 0x8009E320 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E328 b extern */
    R[2] = lb_(R[16] + 784);  /* 0x8009E330 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009E3DCu; return; } }  /* 0x8009E338 b extern */
    R[3] = lw_(R[2] + -6440);  /* 0x8009E340 */
    R[2] = R[0] - 1;  /* 0x8009E344 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 5; if (_c) { goto L_8009E360; } }  /* 0x8009E348 */
    { R[31] = 0x8009E358u; R[4] = R[0] + 8; psx_next = 0x8009DCB0u; return; }  /* 0x8009E350 jal */
    { R[4] = R[16] + R[0]; goto L_8009E364; }  /* 0x8009E358 j */
L_8009E360:;
    R[4] = R[16] + R[0];  /* 0x8009E360 */
L_8009E364:;
    R[5] = R[2] + R[0];  /* 0x8009E364 */
    R[6] = R[0] + R[0];  /* 0x8009E368 */
    { R[31] = 0x8009E374u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E36C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E374 b extern */
    { R[31] = 0x8009E384u; R[4] = R[0] + R[0]; psx_next = 0x8009BB90u; return; }  /* 0x8009E37C jal */
    R[2] = R[2] << 16;  /* 0x8009E384 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 20);  /* 0x8009E388 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009E38C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { psx_next = 0x8009E414u; return; } }  /* 0x8009E390 b extern */
    psx_next = 0x8009E398u; return;  /* fallthrough */
}

void g0_8009E2D8(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E2D8 b extern */
    { R[31] = 0x8009E2E8u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E2E0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E2E8 b extern */
    { R[31] = 0x8009E2F8u; R[5] = R[0] + 84; psx_next = 0x8009D6E4u; return; }  /* 0x8009E2F0 jal */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E314; } }  /* 0x8009E2F8 */
    R[4] = R[16] + R[0];  /* 0x8009E300 */
    { R[31] = 0x8009E30Cu; R[5] = R[0] + 89; psx_next = 0x8009D4B0u; return; }  /* 0x8009E304 jal */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E320; } }  /* 0x8009E30C */
L_8009E314:;
    R[2] = R[0] + 20;  /* 0x8009E314 */
    { sh_(R[3] + -29650, R[2]); psx_next = 0x8009E444u; return; }  /* 0x8009E318 j extern */
L_8009E320:;
    { R[31] = 0x8009E328u; R[4] = R[0] + 1; psx_next = 0x8009D7DCu; return; }  /* 0x8009E320 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E328 b extern */
    R[2] = lb_(R[16] + 784);  /* 0x8009E330 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009E3DCu; return; } }  /* 0x8009E338 b extern */
    R[3] = lw_(R[2] + -6440);  /* 0x8009E340 */
    R[2] = R[0] - 1;  /* 0x8009E344 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 5; if (_c) { goto L_8009E360; } }  /* 0x8009E348 */
    { R[31] = 0x8009E358u; R[4] = R[0] + 8; psx_next = 0x8009DCB0u; return; }  /* 0x8009E350 jal */
    { R[4] = R[16] + R[0]; goto L_8009E364; }  /* 0x8009E358 j */
L_8009E360:;
    R[4] = R[16] + R[0];  /* 0x8009E360 */
L_8009E364:;
    R[5] = R[2] + R[0];  /* 0x8009E364 */
    R[6] = R[0] + R[0];  /* 0x8009E368 */
    { R[31] = 0x8009E374u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E36C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E374 b extern */
    { R[31] = 0x8009E384u; R[4] = R[0] + R[0]; psx_next = 0x8009BB90u; return; }  /* 0x8009E37C jal */
    R[2] = R[2] << 16;  /* 0x8009E384 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 20);  /* 0x8009E388 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009E38C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { psx_next = 0x8009E414u; return; } }  /* 0x8009E390 b extern */
    psx_next = 0x8009E398u; return;  /* fallthrough */
}

void g0_8009E2E8(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E2E8 b extern */
    { R[31] = 0x8009E2F8u; R[5] = R[0] + 84; psx_next = 0x8009D6E4u; return; }  /* 0x8009E2F0 jal */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E314; } }  /* 0x8009E2F8 */
    R[4] = R[16] + R[0];  /* 0x8009E300 */
    { R[31] = 0x8009E30Cu; R[5] = R[0] + 89; psx_next = 0x8009D4B0u; return; }  /* 0x8009E304 jal */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E320; } }  /* 0x8009E30C */
L_8009E314:;
    R[2] = R[0] + 20;  /* 0x8009E314 */
    { sh_(R[3] + -29650, R[2]); psx_next = 0x8009E444u; return; }  /* 0x8009E318 j extern */
L_8009E320:;
    { R[31] = 0x8009E328u; R[4] = R[0] + 1; psx_next = 0x8009D7DCu; return; }  /* 0x8009E320 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E328 b extern */
    R[2] = lb_(R[16] + 784);  /* 0x8009E330 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009E3DCu; return; } }  /* 0x8009E338 b extern */
    R[3] = lw_(R[2] + -6440);  /* 0x8009E340 */
    R[2] = R[0] - 1;  /* 0x8009E344 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 5; if (_c) { goto L_8009E360; } }  /* 0x8009E348 */
    { R[31] = 0x8009E358u; R[4] = R[0] + 8; psx_next = 0x8009DCB0u; return; }  /* 0x8009E350 jal */
    { R[4] = R[16] + R[0]; goto L_8009E364; }  /* 0x8009E358 j */
L_8009E360:;
    R[4] = R[16] + R[0];  /* 0x8009E360 */
L_8009E364:;
    R[5] = R[2] + R[0];  /* 0x8009E364 */
    R[6] = R[0] + R[0];  /* 0x8009E368 */
    { R[31] = 0x8009E374u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E36C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E374 b extern */
    { R[31] = 0x8009E384u; R[4] = R[0] + R[0]; psx_next = 0x8009BB90u; return; }  /* 0x8009E37C jal */
    R[2] = R[2] << 16;  /* 0x8009E384 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 20);  /* 0x8009E388 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009E38C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { psx_next = 0x8009E414u; return; } }  /* 0x8009E390 b extern */
    psx_next = 0x8009E398u; return;  /* fallthrough */
}

void g0_8009E2F8(void) {
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E314; } }  /* 0x8009E2F8 */
    R[4] = R[16] + R[0];  /* 0x8009E300 */
    { R[31] = 0x8009E30Cu; R[5] = R[0] + 89; psx_next = 0x8009D4B0u; return; }  /* 0x8009E304 jal */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E320; } }  /* 0x8009E30C */
L_8009E314:;
    R[2] = R[0] + 20;  /* 0x8009E314 */
    { sh_(R[3] + -29650, R[2]); psx_next = 0x8009E444u; return; }  /* 0x8009E318 j extern */
L_8009E320:;
    { R[31] = 0x8009E328u; R[4] = R[0] + 1; psx_next = 0x8009D7DCu; return; }  /* 0x8009E320 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E328 b extern */
    R[2] = lb_(R[16] + 784);  /* 0x8009E330 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009E3DCu; return; } }  /* 0x8009E338 b extern */
    R[3] = lw_(R[2] + -6440);  /* 0x8009E340 */
    R[2] = R[0] - 1;  /* 0x8009E344 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 5; if (_c) { goto L_8009E360; } }  /* 0x8009E348 */
    { R[31] = 0x8009E358u; R[4] = R[0] + 8; psx_next = 0x8009DCB0u; return; }  /* 0x8009E350 jal */
    { R[4] = R[16] + R[0]; goto L_8009E364; }  /* 0x8009E358 j */
L_8009E360:;
    R[4] = R[16] + R[0];  /* 0x8009E360 */
L_8009E364:;
    R[5] = R[2] + R[0];  /* 0x8009E364 */
    R[6] = R[0] + R[0];  /* 0x8009E368 */
    { R[31] = 0x8009E374u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E36C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E374 b extern */
    { R[31] = 0x8009E384u; R[4] = R[0] + R[0]; psx_next = 0x8009BB90u; return; }  /* 0x8009E37C jal */
    R[2] = R[2] << 16;  /* 0x8009E384 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 20);  /* 0x8009E388 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009E38C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { psx_next = 0x8009E414u; return; } }  /* 0x8009E390 b extern */
    psx_next = 0x8009E398u; return;  /* fallthrough */
}

void g0_8009E30C(void) {
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E320; } }  /* 0x8009E30C */
    R[2] = R[0] + 20;  /* 0x8009E314 */
    { sh_(R[3] + -29650, R[2]); psx_next = 0x8009E444u; return; }  /* 0x8009E318 j extern */
L_8009E320:;
    { R[31] = 0x8009E328u; R[4] = R[0] + 1; psx_next = 0x8009D7DCu; return; }  /* 0x8009E320 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E328 b extern */
    R[2] = lb_(R[16] + 784);  /* 0x8009E330 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009E3DCu; return; } }  /* 0x8009E338 b extern */
    R[3] = lw_(R[2] + -6440);  /* 0x8009E340 */
    R[2] = R[0] - 1;  /* 0x8009E344 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 5; if (_c) { goto L_8009E360; } }  /* 0x8009E348 */
    { R[31] = 0x8009E358u; R[4] = R[0] + 8; psx_next = 0x8009DCB0u; return; }  /* 0x8009E350 jal */
    { R[4] = R[16] + R[0]; goto L_8009E364; }  /* 0x8009E358 j */
L_8009E360:;
    R[4] = R[16] + R[0];  /* 0x8009E360 */
L_8009E364:;
    R[5] = R[2] + R[0];  /* 0x8009E364 */
    R[6] = R[0] + R[0];  /* 0x8009E368 */
    { R[31] = 0x8009E374u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E36C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E374 b extern */
    { R[31] = 0x8009E384u; R[4] = R[0] + R[0]; psx_next = 0x8009BB90u; return; }  /* 0x8009E37C jal */
    R[2] = R[2] << 16;  /* 0x8009E384 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 20);  /* 0x8009E388 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009E38C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { psx_next = 0x8009E414u; return; } }  /* 0x8009E390 b extern */
    psx_next = 0x8009E398u; return;  /* fallthrough */
}

void g0_8009E328(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E328 b extern */
    R[2] = lb_(R[16] + 784);  /* 0x8009E330 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { psx_next = 0x8009E3DCu; return; } }  /* 0x8009E338 b extern */
    R[3] = lw_(R[2] + -6440);  /* 0x8009E340 */
    R[2] = R[0] - 1;  /* 0x8009E344 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 5; if (_c) { goto L_8009E360; } }  /* 0x8009E348 */
    { R[31] = 0x8009E358u; R[4] = R[0] + 8; psx_next = 0x8009DCB0u; return; }  /* 0x8009E350 jal */
    { R[4] = R[16] + R[0]; goto L_8009E364; }  /* 0x8009E358 j */
L_8009E360:;
    R[4] = R[16] + R[0];  /* 0x8009E360 */
L_8009E364:;
    R[5] = R[2] + R[0];  /* 0x8009E364 */
    R[6] = R[0] + R[0];  /* 0x8009E368 */
    { R[31] = 0x8009E374u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E36C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E374 b extern */
    { R[31] = 0x8009E384u; R[4] = R[0] + R[0]; psx_next = 0x8009BB90u; return; }  /* 0x8009E37C jal */
    R[2] = R[2] << 16;  /* 0x8009E384 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 20);  /* 0x8009E388 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009E38C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { psx_next = 0x8009E414u; return; } }  /* 0x8009E390 b extern */
    psx_next = 0x8009E398u; return;  /* fallthrough */
}

void g0_8009E358(void) {
    { R[4] = R[16] + R[0]; goto L_8009E364; }  /* 0x8009E358 j */
    R[4] = R[16] + R[0];  /* 0x8009E360 */
L_8009E364:;
    R[5] = R[2] + R[0];  /* 0x8009E364 */
    R[6] = R[0] + R[0];  /* 0x8009E368 */
    { R[31] = 0x8009E374u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E36C jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E374 b extern */
    { R[31] = 0x8009E384u; R[4] = R[0] + R[0]; psx_next = 0x8009BB90u; return; }  /* 0x8009E37C jal */
    R[2] = R[2] << 16;  /* 0x8009E384 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 20);  /* 0x8009E388 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009E38C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { psx_next = 0x8009E414u; return; } }  /* 0x8009E390 b extern */
    psx_next = 0x8009E398u; return;  /* fallthrough */
}

void g0_8009E374(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009E444u; return; } }  /* 0x8009E374 b extern */
    { R[31] = 0x8009E384u; R[4] = R[0] + R[0]; psx_next = 0x8009BB90u; return; }  /* 0x8009E37C jal */
    R[2] = R[2] << 16;  /* 0x8009E384 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 20);  /* 0x8009E388 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009E38C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { psx_next = 0x8009E414u; return; } }  /* 0x8009E390 b extern */
    psx_next = 0x8009E398u; return;  /* fallthrough */
}

void g0_8009E384(void) {
    R[2] = R[2] << 16;  /* 0x8009E384 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 20);  /* 0x8009E388 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009E38C */
    { uint32_t _c = (R[2] != R[3]); if (_c) { psx_next = 0x8009E414u; return; } }  /* 0x8009E390 b extern */
    psx_next = 0x8009E398u; return;  /* fallthrough */
}

void g0_8009E394(void) {
    R[2] = lw_(R[16] + 172);  /* 0x8009E398 */
    R[3] = R[2] >> 31;  /* 0x8009E3A0 */
    R[2] = R[2] + R[3];  /* 0x8009E3A4 */
    R[3] = lw_(R[16] + 176);  /* 0x8009E3A8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x8009E3AC */
    sw_(R[16] + 172, R[2]);  /* 0x8009E3B0 */
    R[2] = R[3] >> 31;  /* 0x8009E3B4 */
    R[3] = R[3] + R[2];  /* 0x8009E3B8 */
    R[2] = lw_(R[16] + 180);  /* 0x8009E3BC */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009E3C0 */
    sw_(R[16] + 176, R[3]);  /* 0x8009E3C4 */
    R[3] = R[2] >> 31;  /* 0x8009E3C8 */
    R[2] = R[2] + R[3];  /* 0x8009E3CC */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x8009E3D0 */
    { sw_(R[16] + 180, R[2]); goto L_8009E414; }  /* 0x8009E3D4 j */
    R[4] = R[16] + R[0];  /* 0x8009E3DC */
    R[5] = R[0] - 1;  /* 0x8009E3E0 */
    R[6] = R[5] + R[0];  /* 0x8009E3E4 */
    { R[31] = 0x8009E3F0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E3E8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_8009E408; } }  /* 0x8009E3F0 */
    R[2] = 0x8001u << 16;  /* 0x8009E3F8 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x8009E3FC */
    { sw_(R[16] + 124, R[2]); goto L_8009E414; }  /* 0x8009E400 j */
L_8009E408:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29328);  /* 0x8009E408 */
    sw_(R[16] + 124, R[2]);  /* 0x8009E410 */
L_8009E414:;
    R[2] = lw_(R[16] + 72);  /* 0x8009E414 */
    R[2] = lh_(R[2]);  /* 0x8009E41C */
    R[2] = R[2] >> 13;  /* 0x8009E424 */
    R[2] = R[2] & 0x1;  /* 0x8009E428 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E444; } }  /* 0x8009E42C */
    R[2] = lh_(R[16] + 22);  /* 0x8009E434 */
    R[2] = R[2] + 1;  /* 0x8009E43C */
    sh_(R[16] + 20, R[2]);  /* 0x8009E440 */
L_8009E444:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E444 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E448 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E44C jr ra */
}

void g0_8009E398(void) {
    R[2] = lw_(R[16] + 172);  /* 0x8009E398 */
    R[3] = R[2] >> 31;  /* 0x8009E3A0 */
    R[2] = R[2] + R[3];  /* 0x8009E3A4 */
    R[3] = lw_(R[16] + 176);  /* 0x8009E3A8 */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x8009E3AC */
    sw_(R[16] + 172, R[2]);  /* 0x8009E3B0 */
    R[2] = R[3] >> 31;  /* 0x8009E3B4 */
    R[3] = R[3] + R[2];  /* 0x8009E3B8 */
    R[2] = lw_(R[16] + 180);  /* 0x8009E3BC */
    R[3] = (uint32_t)((int32_t)R[3] >> 1);  /* 0x8009E3C0 */
    sw_(R[16] + 176, R[3]);  /* 0x8009E3C4 */
    R[3] = R[2] >> 31;  /* 0x8009E3C8 */
    R[2] = R[2] + R[3];  /* 0x8009E3CC */
    R[2] = (uint32_t)((int32_t)R[2] >> 1);  /* 0x8009E3D0 */
    { sw_(R[16] + 180, R[2]); goto L_8009E414; }  /* 0x8009E3D4 j */
    R[4] = R[16] + R[0];  /* 0x8009E3DC */
    R[5] = R[0] - 1;  /* 0x8009E3E0 */
    R[6] = R[5] + R[0];  /* 0x8009E3E4 */
    { R[31] = 0x8009E3F0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E3E8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_8009E408; } }  /* 0x8009E3F0 */
    R[2] = 0x8001u << 16;  /* 0x8009E3F8 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x8009E3FC */
    { sw_(R[16] + 124, R[2]); goto L_8009E414; }  /* 0x8009E400 j */
L_8009E408:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29328);  /* 0x8009E408 */
    sw_(R[16] + 124, R[2]);  /* 0x8009E410 */
L_8009E414:;
    R[2] = lw_(R[16] + 72);  /* 0x8009E414 */
    R[2] = lh_(R[2]);  /* 0x8009E41C */
    R[2] = R[2] >> 13;  /* 0x8009E424 */
    R[2] = R[2] & 0x1;  /* 0x8009E428 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E444; } }  /* 0x8009E42C */
    R[2] = lh_(R[16] + 22);  /* 0x8009E434 */
    R[2] = R[2] + 1;  /* 0x8009E43C */
    sh_(R[16] + 20, R[2]);  /* 0x8009E440 */
L_8009E444:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E444 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E448 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E44C jr ra */
}

void g0_8009E3DC(void) {
    R[4] = R[16] + R[0];  /* 0x8009E3DC */
    R[5] = R[0] - 1;  /* 0x8009E3E0 */
    R[6] = R[5] + R[0];  /* 0x8009E3E4 */
    { R[31] = 0x8009E3F0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E3E8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_8009E408; } }  /* 0x8009E3F0 */
    R[2] = 0x8001u << 16;  /* 0x8009E3F8 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x8009E3FC */
    { sw_(R[16] + 124, R[2]); goto L_8009E414; }  /* 0x8009E400 j */
L_8009E408:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29328);  /* 0x8009E408 */
    sw_(R[16] + 124, R[2]);  /* 0x8009E410 */
L_8009E414:;
    R[2] = lw_(R[16] + 72);  /* 0x8009E414 */
    R[2] = lh_(R[2]);  /* 0x8009E41C */
    R[2] = R[2] >> 13;  /* 0x8009E424 */
    R[2] = R[2] & 0x1;  /* 0x8009E428 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E444; } }  /* 0x8009E42C */
    R[2] = lh_(R[16] + 22);  /* 0x8009E434 */
    R[2] = R[2] + 1;  /* 0x8009E43C */
    sh_(R[16] + 20, R[2]);  /* 0x8009E440 */
L_8009E444:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E444 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E448 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E44C jr ra */
}

void g0_8009E3F0(void) {
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_8009E408; } }  /* 0x8009E3F0 */
    R[2] = 0x8001u << 16;  /* 0x8009E3F8 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x8009E3FC */
    { sw_(R[16] + 124, R[2]); goto L_8009E414; }  /* 0x8009E400 j */
L_8009E408:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29328);  /* 0x8009E408 */
    sw_(R[16] + 124, R[2]);  /* 0x8009E410 */
L_8009E414:;
    R[2] = lw_(R[16] + 72);  /* 0x8009E414 */
    R[2] = lh_(R[2]);  /* 0x8009E41C */
    R[2] = R[2] >> 13;  /* 0x8009E424 */
    R[2] = R[2] & 0x1;  /* 0x8009E428 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E444; } }  /* 0x8009E42C */
    R[2] = lh_(R[16] + 22);  /* 0x8009E434 */
    R[2] = R[2] + 1;  /* 0x8009E43C */
    sh_(R[16] + 20, R[2]);  /* 0x8009E440 */
L_8009E444:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E444 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E448 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E44C jr ra */
}

void g0_8009E414(void) {
    R[2] = lw_(R[16] + 72);  /* 0x8009E414 */
    R[2] = lh_(R[2]);  /* 0x8009E41C */
    R[2] = R[2] >> 13;  /* 0x8009E424 */
    R[2] = R[2] & 0x1;  /* 0x8009E428 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E444; } }  /* 0x8009E42C */
    R[2] = lh_(R[16] + 22);  /* 0x8009E434 */
    R[2] = R[2] + 1;  /* 0x8009E43C */
    sh_(R[16] + 20, R[2]);  /* 0x8009E440 */
L_8009E444:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E444 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E448 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E44C jr ra */
}

void g0_8009E444(void) {
    R[31] = lw_(R[29] + 20);  /* 0x8009E444 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E448 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E44C jr ra */
}

void g0_8009E454(void) {
    R[29] = R[29] - 24;  /* 0x8009E454 */
    R[2] = 0x8012u << 16;  /* 0x8009E458 */
    R[3] = R[2] + 30872;  /* 0x8009E45C */
    sw_(R[29] + 16, R[31]);  /* 0x8009E460 */
    R[2] = lh_(R[3] + 260);  /* 0x8009E464 */
    R[2] = R[2] & 0x1;  /* 0x8009E46C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009E4D0u; return; } }  /* 0x8009E470 b extern */
    R[2] = lw_(R[3] + 96);  /* 0x8009E478 */
    R[3] = lw_(R[4] + 140);  /* 0x8009E47C */
    R[2] = R[0] - R[2];  /* 0x8009E480 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8013u << 16; if (_c) { psx_next = 0x8009E4C8u; return; } }  /* 0x8009E484 b extern */
    R[3] = 0x8013u << 16;  /* 0x8009E48C */
    R[3] = R[3] - 29656;  /* 0x8009E490 */
    R[2] = lh_(R[3] + 10);  /* 0x8009E494 */
    R[2] = R[2] + 1;  /* 0x8009E49C */
    sh_(R[3] + 10, R[2]);  /* 0x8009E4A0 */
    R[2] = R[2] << 16;  /* 0x8009E4A4 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009E4A8 */
    R[2] = ((int32_t)R[2] < 30);  /* 0x8009E4AC */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009E4D0u; return; } }  /* 0x8009E4B0 b extern */
    { R[31] = 0x8009E4C0u; R[5] = R[0] + 124; psx_next = 0x8009BC84u; return; }  /* 0x8009E4B8 jal */
}

void g0_8009E4BC(void) {
    R[5] = R[0] + 124;  /* 0x8009E4BC */
    { R[2] = R[0] + 1; goto L_8009E4D0; }  /* 0x8009E4C0 j */
    sh_(R[2] + -29646, R[0]);  /* 0x8009E4C8 */
    R[2] = R[0] + R[0];  /* 0x8009E4CC */
L_8009E4D0:;
    R[31] = lw_(R[29] + 16);  /* 0x8009E4D0 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E4D8 jr ra */
}

void g0_8009E4C0(void) {
    { R[2] = R[0] + 1; goto L_8009E4D0; }  /* 0x8009E4C0 j */
    sh_(R[2] + -29646, R[0]);  /* 0x8009E4C8 */
    R[2] = R[0] + R[0];  /* 0x8009E4CC */
L_8009E4D0:;
    R[31] = lw_(R[29] + 16);  /* 0x8009E4D0 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E4D8 jr ra */
}

void g0_8009E4C8(void) {
    sh_(R[2] + -29646, R[0]);  /* 0x8009E4C8 */
    R[2] = R[0] + R[0];  /* 0x8009E4CC */
    R[31] = lw_(R[29] + 16);  /* 0x8009E4D0 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E4D8 jr ra */
}

void g0_8009E4D0(void) {
    R[31] = lw_(R[29] + 16);  /* 0x8009E4D0 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E4D8 jr ra */
}

void g0_8009E4E0(void) {
    R[29] = R[29] - 24;  /* 0x8009E4E0 */
    sw_(R[29] + 16, R[16]);  /* 0x8009E4E4 */
    sw_(R[29] + 20, R[31]);  /* 0x8009E4E8 */
    { R[31] = 0x8009E4F4u; R[16] = R[4] + R[0]; psx_next = 0x8009D8D0u; return; }  /* 0x8009E4EC jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E4F4 */
    R[5] = R[0] + 10;  /* 0x8009E4FC */
    { R[31] = 0x8009E508u; R[6] = R[0] + 2; psx_next = 0x8009D268u; return; }  /* 0x8009E500 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E508 */
    { R[31] = 0x8009E518u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E510 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E518 */
    { R[31] = 0x8009E528u; R[5] = R[0] + 83; psx_next = 0x8009D6E4u; return; }  /* 0x8009E520 jal */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E544; } }  /* 0x8009E528 */
    R[4] = R[16] + R[0];  /* 0x8009E530 */
    { R[31] = 0x8009E53Cu; R[5] = R[0] + 88; psx_next = 0x8009D4B0u; return; }  /* 0x8009E534 jal */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E550; } }  /* 0x8009E53C */
L_8009E544:;
    R[2] = R[0] + 12;  /* 0x8009E544 */
    { sh_(R[3] + -29650, R[2]); goto L_8009E664; }  /* 0x8009E548 j */
L_8009E550:;
    { R[31] = 0x8009E558u; R[4] = R[0] + 1; psx_next = 0x8009D7DCu; return; }  /* 0x8009E550 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E558 */
    { R[31] = 0x8009E568u; R[4] = R[16] + R[0]; psx_next = 0x8009E454u; return; }  /* 0x8009E560 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E568 */
    R[2] = lb_(R[16] + 784);  /* 0x8009E570 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] - 1; if (_c) { goto L_8009E5D0; } }  /* 0x8009E578 */
    R[2] = lb_(R[16] + 799);  /* 0x8009E580 */
    R[2] = (R[2] < (uint32_t)10u);  /* 0x8009E588 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[0] + R[0]; if (_c) { goto L_8009E5B0; } }  /* 0x8009E58C */
    R[2] = 0x8012u << 16;  /* 0x8009E594 */
    R[2] = lh_(R[2] + 31132);  /* 0x8009E598 */
    R[2] = R[2] & 0x1;  /* 0x8009E5A0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E5B4; } }  /* 0x8009E5A4 */
    R[6] = R[0] + 17;  /* 0x8009E5AC */
L_8009E5B0:;
    R[4] = R[16] + R[0];  /* 0x8009E5B0 */
L_8009E5B4:;
    R[5] = R[0] + 5;  /* 0x8009E5B4 */
    { R[31] = 0x8009E5C0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E5B8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8012u << 16; if (_c) { goto L_8009E664; } }  /* 0x8009E5C0 */
    { goto L_8009E600; }  /* 0x8009E5C8 j */
L_8009E5D0:;
    R[4] = R[16] + R[0];  /* 0x8009E5D0 */
    R[6] = R[5] + R[0];  /* 0x8009E5D4 */
    { R[31] = 0x8009E5E0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E5D8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_8009E5F0; } }  /* 0x8009E5E0 */
    { sw_(R[16] + 124, R[0]); goto L_8009E5FC; }  /* 0x8009E5E8 j */
L_8009E5F0:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x8009E5F0 */
    sw_(R[16] + 124, R[2]);  /* 0x8009E5F8 */
L_8009E5FC:;
    R[2] = 0x8012u << 16;  /* 0x8009E5FC */
L_8009E600:;
    R[2] = lh_(R[2] + 31132);  /* 0x8009E600 */
    R[2] = R[2] & 0x1;  /* 0x8009E608 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E60C */
    { R[31] = 0x8009E61Cu; R[5] = R[0] + 12; psx_next = 0x8009BC08u; return; }  /* 0x8009E614 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E61C */
    { R[31] = 0x8009E62Cu; R[5] = R[0] + 16; psx_next = 0x8009BC08u; return; }  /* 0x8009E624 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E62C */
    R[2] = lw_(R[16] + 72);  /* 0x8009E634 */
    R[2] = lh_(R[2]);  /* 0x8009E63C */
    R[2] = R[2] >> 13;  /* 0x8009E644 */
    R[2] = R[2] & 0x1;  /* 0x8009E648 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E64C */
    R[2] = lh_(R[16] + 22);  /* 0x8009E654 */
    R[2] = R[2] + 1;  /* 0x8009E65C */
    sh_(R[16] + 20, R[2]);  /* 0x8009E660 */
L_8009E664:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E664 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E668 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E66C jr ra */
}

void g0_8009E4F4(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E4F4 */
    R[5] = R[0] + 10;  /* 0x8009E4FC */
    { R[31] = 0x8009E508u; R[6] = R[0] + 2; psx_next = 0x8009D268u; return; }  /* 0x8009E500 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E508 */
    { R[31] = 0x8009E518u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E510 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E518 */
    { R[31] = 0x8009E528u; R[5] = R[0] + 83; psx_next = 0x8009D6E4u; return; }  /* 0x8009E520 jal */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E544; } }  /* 0x8009E528 */
    R[4] = R[16] + R[0];  /* 0x8009E530 */
    { R[31] = 0x8009E53Cu; R[5] = R[0] + 88; psx_next = 0x8009D4B0u; return; }  /* 0x8009E534 jal */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E550; } }  /* 0x8009E53C */
L_8009E544:;
    R[2] = R[0] + 12;  /* 0x8009E544 */
    { sh_(R[3] + -29650, R[2]); goto L_8009E664; }  /* 0x8009E548 j */
L_8009E550:;
    { R[31] = 0x8009E558u; R[4] = R[0] + 1; psx_next = 0x8009D7DCu; return; }  /* 0x8009E550 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E558 */
    { R[31] = 0x8009E568u; R[4] = R[16] + R[0]; psx_next = 0x8009E454u; return; }  /* 0x8009E560 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E568 */
    R[2] = lb_(R[16] + 784);  /* 0x8009E570 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] - 1; if (_c) { goto L_8009E5D0; } }  /* 0x8009E578 */
    R[2] = lb_(R[16] + 799);  /* 0x8009E580 */
    R[2] = (R[2] < (uint32_t)10u);  /* 0x8009E588 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[0] + R[0]; if (_c) { goto L_8009E5B0; } }  /* 0x8009E58C */
    R[2] = 0x8012u << 16;  /* 0x8009E594 */
    R[2] = lh_(R[2] + 31132);  /* 0x8009E598 */
    R[2] = R[2] & 0x1;  /* 0x8009E5A0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E5B4; } }  /* 0x8009E5A4 */
    R[6] = R[0] + 17;  /* 0x8009E5AC */
L_8009E5B0:;
    R[4] = R[16] + R[0];  /* 0x8009E5B0 */
L_8009E5B4:;
    R[5] = R[0] + 5;  /* 0x8009E5B4 */
    { R[31] = 0x8009E5C0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E5B8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8012u << 16; if (_c) { goto L_8009E664; } }  /* 0x8009E5C0 */
    { goto L_8009E600; }  /* 0x8009E5C8 j */
L_8009E5D0:;
    R[4] = R[16] + R[0];  /* 0x8009E5D0 */
    R[6] = R[5] + R[0];  /* 0x8009E5D4 */
    { R[31] = 0x8009E5E0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E5D8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_8009E5F0; } }  /* 0x8009E5E0 */
    { sw_(R[16] + 124, R[0]); goto L_8009E5FC; }  /* 0x8009E5E8 j */
L_8009E5F0:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x8009E5F0 */
    sw_(R[16] + 124, R[2]);  /* 0x8009E5F8 */
L_8009E5FC:;
    R[2] = 0x8012u << 16;  /* 0x8009E5FC */
L_8009E600:;
    R[2] = lh_(R[2] + 31132);  /* 0x8009E600 */
    R[2] = R[2] & 0x1;  /* 0x8009E608 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E60C */
    { R[31] = 0x8009E61Cu; R[5] = R[0] + 12; psx_next = 0x8009BC08u; return; }  /* 0x8009E614 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E61C */
    { R[31] = 0x8009E62Cu; R[5] = R[0] + 16; psx_next = 0x8009BC08u; return; }  /* 0x8009E624 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E62C */
    R[2] = lw_(R[16] + 72);  /* 0x8009E634 */
    R[2] = lh_(R[2]);  /* 0x8009E63C */
    R[2] = R[2] >> 13;  /* 0x8009E644 */
    R[2] = R[2] & 0x1;  /* 0x8009E648 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E64C */
    R[2] = lh_(R[16] + 22);  /* 0x8009E654 */
    R[2] = R[2] + 1;  /* 0x8009E65C */
    sh_(R[16] + 20, R[2]);  /* 0x8009E660 */
L_8009E664:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E664 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E668 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E66C jr ra */
}

void g0_8009E508(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E508 */
    { R[31] = 0x8009E518u; R[4] = R[16] + R[0]; psx_next = 0x8009CD00u; return; }  /* 0x8009E510 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E518 */
    { R[31] = 0x8009E528u; R[5] = R[0] + 83; psx_next = 0x8009D6E4u; return; }  /* 0x8009E520 jal */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E544; } }  /* 0x8009E528 */
    R[4] = R[16] + R[0];  /* 0x8009E530 */
    { R[31] = 0x8009E53Cu; R[5] = R[0] + 88; psx_next = 0x8009D4B0u; return; }  /* 0x8009E534 jal */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E550; } }  /* 0x8009E53C */
L_8009E544:;
    R[2] = R[0] + 12;  /* 0x8009E544 */
    { sh_(R[3] + -29650, R[2]); goto L_8009E664; }  /* 0x8009E548 j */
L_8009E550:;
    { R[31] = 0x8009E558u; R[4] = R[0] + 1; psx_next = 0x8009D7DCu; return; }  /* 0x8009E550 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E558 */
    { R[31] = 0x8009E568u; R[4] = R[16] + R[0]; psx_next = 0x8009E454u; return; }  /* 0x8009E560 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E568 */
    R[2] = lb_(R[16] + 784);  /* 0x8009E570 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] - 1; if (_c) { goto L_8009E5D0; } }  /* 0x8009E578 */
    R[2] = lb_(R[16] + 799);  /* 0x8009E580 */
    R[2] = (R[2] < (uint32_t)10u);  /* 0x8009E588 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[0] + R[0]; if (_c) { goto L_8009E5B0; } }  /* 0x8009E58C */
    R[2] = 0x8012u << 16;  /* 0x8009E594 */
    R[2] = lh_(R[2] + 31132);  /* 0x8009E598 */
    R[2] = R[2] & 0x1;  /* 0x8009E5A0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E5B4; } }  /* 0x8009E5A4 */
    R[6] = R[0] + 17;  /* 0x8009E5AC */
L_8009E5B0:;
    R[4] = R[16] + R[0];  /* 0x8009E5B0 */
L_8009E5B4:;
    R[5] = R[0] + 5;  /* 0x8009E5B4 */
    { R[31] = 0x8009E5C0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E5B8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8012u << 16; if (_c) { goto L_8009E664; } }  /* 0x8009E5C0 */
    { goto L_8009E600; }  /* 0x8009E5C8 j */
L_8009E5D0:;
    R[4] = R[16] + R[0];  /* 0x8009E5D0 */
    R[6] = R[5] + R[0];  /* 0x8009E5D4 */
    { R[31] = 0x8009E5E0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E5D8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_8009E5F0; } }  /* 0x8009E5E0 */
    { sw_(R[16] + 124, R[0]); goto L_8009E5FC; }  /* 0x8009E5E8 j */
L_8009E5F0:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x8009E5F0 */
    sw_(R[16] + 124, R[2]);  /* 0x8009E5F8 */
L_8009E5FC:;
    R[2] = 0x8012u << 16;  /* 0x8009E5FC */
L_8009E600:;
    R[2] = lh_(R[2] + 31132);  /* 0x8009E600 */
    R[2] = R[2] & 0x1;  /* 0x8009E608 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E60C */
    { R[31] = 0x8009E61Cu; R[5] = R[0] + 12; psx_next = 0x8009BC08u; return; }  /* 0x8009E614 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E61C */
    { R[31] = 0x8009E62Cu; R[5] = R[0] + 16; psx_next = 0x8009BC08u; return; }  /* 0x8009E624 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E62C */
    R[2] = lw_(R[16] + 72);  /* 0x8009E634 */
    R[2] = lh_(R[2]);  /* 0x8009E63C */
    R[2] = R[2] >> 13;  /* 0x8009E644 */
    R[2] = R[2] & 0x1;  /* 0x8009E648 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E64C */
    R[2] = lh_(R[16] + 22);  /* 0x8009E654 */
    R[2] = R[2] + 1;  /* 0x8009E65C */
    sh_(R[16] + 20, R[2]);  /* 0x8009E660 */
L_8009E664:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E664 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E668 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E66C jr ra */
}

void g0_8009E518(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E518 */
    { R[31] = 0x8009E528u; R[5] = R[0] + 83; psx_next = 0x8009D6E4u; return; }  /* 0x8009E520 jal */
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E544; } }  /* 0x8009E528 */
    R[4] = R[16] + R[0];  /* 0x8009E530 */
    { R[31] = 0x8009E53Cu; R[5] = R[0] + 88; psx_next = 0x8009D4B0u; return; }  /* 0x8009E534 jal */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E550; } }  /* 0x8009E53C */
L_8009E544:;
    R[2] = R[0] + 12;  /* 0x8009E544 */
    { sh_(R[3] + -29650, R[2]); goto L_8009E664; }  /* 0x8009E548 j */
L_8009E550:;
    { R[31] = 0x8009E558u; R[4] = R[0] + 1; psx_next = 0x8009D7DCu; return; }  /* 0x8009E550 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E558 */
    { R[31] = 0x8009E568u; R[4] = R[16] + R[0]; psx_next = 0x8009E454u; return; }  /* 0x8009E560 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E568 */
    R[2] = lb_(R[16] + 784);  /* 0x8009E570 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] - 1; if (_c) { goto L_8009E5D0; } }  /* 0x8009E578 */
    R[2] = lb_(R[16] + 799);  /* 0x8009E580 */
    R[2] = (R[2] < (uint32_t)10u);  /* 0x8009E588 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[0] + R[0]; if (_c) { goto L_8009E5B0; } }  /* 0x8009E58C */
    R[2] = 0x8012u << 16;  /* 0x8009E594 */
    R[2] = lh_(R[2] + 31132);  /* 0x8009E598 */
    R[2] = R[2] & 0x1;  /* 0x8009E5A0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E5B4; } }  /* 0x8009E5A4 */
    R[6] = R[0] + 17;  /* 0x8009E5AC */
L_8009E5B0:;
    R[4] = R[16] + R[0];  /* 0x8009E5B0 */
L_8009E5B4:;
    R[5] = R[0] + 5;  /* 0x8009E5B4 */
    { R[31] = 0x8009E5C0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E5B8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8012u << 16; if (_c) { goto L_8009E664; } }  /* 0x8009E5C0 */
    { goto L_8009E600; }  /* 0x8009E5C8 j */
L_8009E5D0:;
    R[4] = R[16] + R[0];  /* 0x8009E5D0 */
    R[6] = R[5] + R[0];  /* 0x8009E5D4 */
    { R[31] = 0x8009E5E0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E5D8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_8009E5F0; } }  /* 0x8009E5E0 */
    { sw_(R[16] + 124, R[0]); goto L_8009E5FC; }  /* 0x8009E5E8 j */
L_8009E5F0:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x8009E5F0 */
    sw_(R[16] + 124, R[2]);  /* 0x8009E5F8 */
L_8009E5FC:;
    R[2] = 0x8012u << 16;  /* 0x8009E5FC */
L_8009E600:;
    R[2] = lh_(R[2] + 31132);  /* 0x8009E600 */
    R[2] = R[2] & 0x1;  /* 0x8009E608 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E60C */
    { R[31] = 0x8009E61Cu; R[5] = R[0] + 12; psx_next = 0x8009BC08u; return; }  /* 0x8009E614 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E61C */
    { R[31] = 0x8009E62Cu; R[5] = R[0] + 16; psx_next = 0x8009BC08u; return; }  /* 0x8009E624 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E62C */
    R[2] = lw_(R[16] + 72);  /* 0x8009E634 */
    R[2] = lh_(R[2]);  /* 0x8009E63C */
    R[2] = R[2] >> 13;  /* 0x8009E644 */
    R[2] = R[2] & 0x1;  /* 0x8009E648 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E64C */
    R[2] = lh_(R[16] + 22);  /* 0x8009E654 */
    R[2] = R[2] + 1;  /* 0x8009E65C */
    sh_(R[16] + 20, R[2]);  /* 0x8009E660 */
L_8009E664:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E664 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E668 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E66C jr ra */
}

void g0_8009E528(void) {
    { uint32_t _c = (R[2] != R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E544; } }  /* 0x8009E528 */
    R[4] = R[16] + R[0];  /* 0x8009E530 */
    { R[31] = 0x8009E53Cu; R[5] = R[0] + 88; psx_next = 0x8009D4B0u; return; }  /* 0x8009E534 jal */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E550; } }  /* 0x8009E53C */
L_8009E544:;
    R[2] = R[0] + 12;  /* 0x8009E544 */
    { sh_(R[3] + -29650, R[2]); goto L_8009E664; }  /* 0x8009E548 j */
L_8009E550:;
    { R[31] = 0x8009E558u; R[4] = R[0] + 1; psx_next = 0x8009D7DCu; return; }  /* 0x8009E550 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E558 */
    { R[31] = 0x8009E568u; R[4] = R[16] + R[0]; psx_next = 0x8009E454u; return; }  /* 0x8009E560 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E568 */
    R[2] = lb_(R[16] + 784);  /* 0x8009E570 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] - 1; if (_c) { goto L_8009E5D0; } }  /* 0x8009E578 */
    R[2] = lb_(R[16] + 799);  /* 0x8009E580 */
    R[2] = (R[2] < (uint32_t)10u);  /* 0x8009E588 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[0] + R[0]; if (_c) { goto L_8009E5B0; } }  /* 0x8009E58C */
    R[2] = 0x8012u << 16;  /* 0x8009E594 */
    R[2] = lh_(R[2] + 31132);  /* 0x8009E598 */
    R[2] = R[2] & 0x1;  /* 0x8009E5A0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E5B4; } }  /* 0x8009E5A4 */
    R[6] = R[0] + 17;  /* 0x8009E5AC */
L_8009E5B0:;
    R[4] = R[16] + R[0];  /* 0x8009E5B0 */
L_8009E5B4:;
    R[5] = R[0] + 5;  /* 0x8009E5B4 */
    { R[31] = 0x8009E5C0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E5B8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8012u << 16; if (_c) { goto L_8009E664; } }  /* 0x8009E5C0 */
    { goto L_8009E600; }  /* 0x8009E5C8 j */
L_8009E5D0:;
    R[4] = R[16] + R[0];  /* 0x8009E5D0 */
    R[6] = R[5] + R[0];  /* 0x8009E5D4 */
    { R[31] = 0x8009E5E0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E5D8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_8009E5F0; } }  /* 0x8009E5E0 */
    { sw_(R[16] + 124, R[0]); goto L_8009E5FC; }  /* 0x8009E5E8 j */
L_8009E5F0:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x8009E5F0 */
    sw_(R[16] + 124, R[2]);  /* 0x8009E5F8 */
L_8009E5FC:;
    R[2] = 0x8012u << 16;  /* 0x8009E5FC */
L_8009E600:;
    R[2] = lh_(R[2] + 31132);  /* 0x8009E600 */
    R[2] = R[2] & 0x1;  /* 0x8009E608 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E60C */
    { R[31] = 0x8009E61Cu; R[5] = R[0] + 12; psx_next = 0x8009BC08u; return; }  /* 0x8009E614 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E61C */
    { R[31] = 0x8009E62Cu; R[5] = R[0] + 16; psx_next = 0x8009BC08u; return; }  /* 0x8009E624 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E62C */
    R[2] = lw_(R[16] + 72);  /* 0x8009E634 */
    R[2] = lh_(R[2]);  /* 0x8009E63C */
    R[2] = R[2] >> 13;  /* 0x8009E644 */
    R[2] = R[2] & 0x1;  /* 0x8009E648 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E64C */
    R[2] = lh_(R[16] + 22);  /* 0x8009E654 */
    R[2] = R[2] + 1;  /* 0x8009E65C */
    sh_(R[16] + 20, R[2]);  /* 0x8009E660 */
L_8009E664:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E664 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E668 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E66C jr ra */
}

void g0_8009E53C(void) {
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009E550; } }  /* 0x8009E53C */
    R[2] = R[0] + 12;  /* 0x8009E544 */
    { sh_(R[3] + -29650, R[2]); goto L_8009E664; }  /* 0x8009E548 j */
L_8009E550:;
    { R[31] = 0x8009E558u; R[4] = R[0] + 1; psx_next = 0x8009D7DCu; return; }  /* 0x8009E550 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E558 */
    { R[31] = 0x8009E568u; R[4] = R[16] + R[0]; psx_next = 0x8009E454u; return; }  /* 0x8009E560 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E568 */
    R[2] = lb_(R[16] + 784);  /* 0x8009E570 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] - 1; if (_c) { goto L_8009E5D0; } }  /* 0x8009E578 */
    R[2] = lb_(R[16] + 799);  /* 0x8009E580 */
    R[2] = (R[2] < (uint32_t)10u);  /* 0x8009E588 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[0] + R[0]; if (_c) { goto L_8009E5B0; } }  /* 0x8009E58C */
    R[2] = 0x8012u << 16;  /* 0x8009E594 */
    R[2] = lh_(R[2] + 31132);  /* 0x8009E598 */
    R[2] = R[2] & 0x1;  /* 0x8009E5A0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E5B4; } }  /* 0x8009E5A4 */
    R[6] = R[0] + 17;  /* 0x8009E5AC */
L_8009E5B0:;
    R[4] = R[16] + R[0];  /* 0x8009E5B0 */
L_8009E5B4:;
    R[5] = R[0] + 5;  /* 0x8009E5B4 */
    { R[31] = 0x8009E5C0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E5B8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8012u << 16; if (_c) { goto L_8009E664; } }  /* 0x8009E5C0 */
    { goto L_8009E600; }  /* 0x8009E5C8 j */
L_8009E5D0:;
    R[4] = R[16] + R[0];  /* 0x8009E5D0 */
    R[6] = R[5] + R[0];  /* 0x8009E5D4 */
    { R[31] = 0x8009E5E0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E5D8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_8009E5F0; } }  /* 0x8009E5E0 */
    { sw_(R[16] + 124, R[0]); goto L_8009E5FC; }  /* 0x8009E5E8 j */
L_8009E5F0:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x8009E5F0 */
    sw_(R[16] + 124, R[2]);  /* 0x8009E5F8 */
L_8009E5FC:;
    R[2] = 0x8012u << 16;  /* 0x8009E5FC */
L_8009E600:;
    R[2] = lh_(R[2] + 31132);  /* 0x8009E600 */
    R[2] = R[2] & 0x1;  /* 0x8009E608 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E60C */
    { R[31] = 0x8009E61Cu; R[5] = R[0] + 12; psx_next = 0x8009BC08u; return; }  /* 0x8009E614 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E61C */
    { R[31] = 0x8009E62Cu; R[5] = R[0] + 16; psx_next = 0x8009BC08u; return; }  /* 0x8009E624 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E62C */
    R[2] = lw_(R[16] + 72);  /* 0x8009E634 */
    R[2] = lh_(R[2]);  /* 0x8009E63C */
    R[2] = R[2] >> 13;  /* 0x8009E644 */
    R[2] = R[2] & 0x1;  /* 0x8009E648 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E64C */
    R[2] = lh_(R[16] + 22);  /* 0x8009E654 */
    R[2] = R[2] + 1;  /* 0x8009E65C */
    sh_(R[16] + 20, R[2]);  /* 0x8009E660 */
L_8009E664:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E664 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E668 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E66C jr ra */
}

void g0_8009E558(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E558 */
    { R[31] = 0x8009E568u; R[4] = R[16] + R[0]; psx_next = 0x8009E454u; return; }  /* 0x8009E560 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E568 */
    R[2] = lb_(R[16] + 784);  /* 0x8009E570 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] - 1; if (_c) { goto L_8009E5D0; } }  /* 0x8009E578 */
    R[2] = lb_(R[16] + 799);  /* 0x8009E580 */
    R[2] = (R[2] < (uint32_t)10u);  /* 0x8009E588 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[0] + R[0]; if (_c) { goto L_8009E5B0; } }  /* 0x8009E58C */
    R[2] = 0x8012u << 16;  /* 0x8009E594 */
    R[2] = lh_(R[2] + 31132);  /* 0x8009E598 */
    R[2] = R[2] & 0x1;  /* 0x8009E5A0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E5B4; } }  /* 0x8009E5A4 */
    R[6] = R[0] + 17;  /* 0x8009E5AC */
L_8009E5B0:;
    R[4] = R[16] + R[0];  /* 0x8009E5B0 */
L_8009E5B4:;
    R[5] = R[0] + 5;  /* 0x8009E5B4 */
    { R[31] = 0x8009E5C0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E5B8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8012u << 16; if (_c) { goto L_8009E664; } }  /* 0x8009E5C0 */
    { goto L_8009E600; }  /* 0x8009E5C8 j */
L_8009E5D0:;
    R[4] = R[16] + R[0];  /* 0x8009E5D0 */
    R[6] = R[5] + R[0];  /* 0x8009E5D4 */
    { R[31] = 0x8009E5E0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E5D8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_8009E5F0; } }  /* 0x8009E5E0 */
    { sw_(R[16] + 124, R[0]); goto L_8009E5FC; }  /* 0x8009E5E8 j */
L_8009E5F0:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x8009E5F0 */
    sw_(R[16] + 124, R[2]);  /* 0x8009E5F8 */
L_8009E5FC:;
    R[2] = 0x8012u << 16;  /* 0x8009E5FC */
L_8009E600:;
    R[2] = lh_(R[2] + 31132);  /* 0x8009E600 */
    R[2] = R[2] & 0x1;  /* 0x8009E608 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E60C */
    { R[31] = 0x8009E61Cu; R[5] = R[0] + 12; psx_next = 0x8009BC08u; return; }  /* 0x8009E614 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E61C */
    { R[31] = 0x8009E62Cu; R[5] = R[0] + 16; psx_next = 0x8009BC08u; return; }  /* 0x8009E624 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E62C */
    R[2] = lw_(R[16] + 72);  /* 0x8009E634 */
    R[2] = lh_(R[2]);  /* 0x8009E63C */
    R[2] = R[2] >> 13;  /* 0x8009E644 */
    R[2] = R[2] & 0x1;  /* 0x8009E648 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E64C */
    R[2] = lh_(R[16] + 22);  /* 0x8009E654 */
    R[2] = R[2] + 1;  /* 0x8009E65C */
    sh_(R[16] + 20, R[2]);  /* 0x8009E660 */
L_8009E664:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E664 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E668 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E66C jr ra */
}

void g0_8009E568(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E568 */
    R[2] = lb_(R[16] + 784);  /* 0x8009E570 */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] - 1; if (_c) { goto L_8009E5D0; } }  /* 0x8009E578 */
    R[2] = lb_(R[16] + 799);  /* 0x8009E580 */
    R[2] = (R[2] < (uint32_t)10u);  /* 0x8009E588 */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[0] + R[0]; if (_c) { goto L_8009E5B0; } }  /* 0x8009E58C */
    R[2] = 0x8012u << 16;  /* 0x8009E594 */
    R[2] = lh_(R[2] + 31132);  /* 0x8009E598 */
    R[2] = R[2] & 0x1;  /* 0x8009E5A0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E5B4; } }  /* 0x8009E5A4 */
    R[6] = R[0] + 17;  /* 0x8009E5AC */
L_8009E5B0:;
    R[4] = R[16] + R[0];  /* 0x8009E5B0 */
L_8009E5B4:;
    R[5] = R[0] + 5;  /* 0x8009E5B4 */
    { R[31] = 0x8009E5C0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E5B8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8012u << 16; if (_c) { goto L_8009E664; } }  /* 0x8009E5C0 */
    { goto L_8009E600; }  /* 0x8009E5C8 j */
L_8009E5D0:;
    R[4] = R[16] + R[0];  /* 0x8009E5D0 */
    R[6] = R[5] + R[0];  /* 0x8009E5D4 */
    { R[31] = 0x8009E5E0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E5D8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_8009E5F0; } }  /* 0x8009E5E0 */
    { sw_(R[16] + 124, R[0]); goto L_8009E5FC; }  /* 0x8009E5E8 j */
L_8009E5F0:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x8009E5F0 */
    sw_(R[16] + 124, R[2]);  /* 0x8009E5F8 */
L_8009E5FC:;
    R[2] = 0x8012u << 16;  /* 0x8009E5FC */
L_8009E600:;
    R[2] = lh_(R[2] + 31132);  /* 0x8009E600 */
    R[2] = R[2] & 0x1;  /* 0x8009E608 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E60C */
    { R[31] = 0x8009E61Cu; R[5] = R[0] + 12; psx_next = 0x8009BC08u; return; }  /* 0x8009E614 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E61C */
    { R[31] = 0x8009E62Cu; R[5] = R[0] + 16; psx_next = 0x8009BC08u; return; }  /* 0x8009E624 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E62C */
    R[2] = lw_(R[16] + 72);  /* 0x8009E634 */
    R[2] = lh_(R[2]);  /* 0x8009E63C */
    R[2] = R[2] >> 13;  /* 0x8009E644 */
    R[2] = R[2] & 0x1;  /* 0x8009E648 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E64C */
    R[2] = lh_(R[16] + 22);  /* 0x8009E654 */
    R[2] = R[2] + 1;  /* 0x8009E65C */
    sh_(R[16] + 20, R[2]);  /* 0x8009E660 */
L_8009E664:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E664 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E668 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E66C jr ra */
}

void g0_8009E5C0(void) {
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8012u << 16; if (_c) { goto L_8009E664; } }  /* 0x8009E5C0 */
    { goto L_8009E600; }  /* 0x8009E5C8 j */
    R[4] = R[16] + R[0];  /* 0x8009E5D0 */
    R[6] = R[5] + R[0];  /* 0x8009E5D4 */
    { R[31] = 0x8009E5E0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009E5D8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_8009E5F0; } }  /* 0x8009E5E0 */
    { sw_(R[16] + 124, R[0]); goto L_8009E5FC; }  /* 0x8009E5E8 j */
L_8009E5F0:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x8009E5F0 */
    sw_(R[16] + 124, R[2]);  /* 0x8009E5F8 */
L_8009E5FC:;
    R[2] = 0x8012u << 16;  /* 0x8009E5FC */
L_8009E600:;
    R[2] = lh_(R[2] + 31132);  /* 0x8009E600 */
    R[2] = R[2] & 0x1;  /* 0x8009E608 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E60C */
    { R[31] = 0x8009E61Cu; R[5] = R[0] + 12; psx_next = 0x8009BC08u; return; }  /* 0x8009E614 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E61C */
    { R[31] = 0x8009E62Cu; R[5] = R[0] + 16; psx_next = 0x8009BC08u; return; }  /* 0x8009E624 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E62C */
    R[2] = lw_(R[16] + 72);  /* 0x8009E634 */
    R[2] = lh_(R[2]);  /* 0x8009E63C */
    R[2] = R[2] >> 13;  /* 0x8009E644 */
    R[2] = R[2] & 0x1;  /* 0x8009E648 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E64C */
    R[2] = lh_(R[16] + 22);  /* 0x8009E654 */
    R[2] = R[2] + 1;  /* 0x8009E65C */
    sh_(R[16] + 20, R[2]);  /* 0x8009E660 */
L_8009E664:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E664 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E668 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E66C jr ra */
}

void g0_8009E5E0(void) {
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { goto L_8009E5F0; } }  /* 0x8009E5E0 */
    { sw_(R[16] + 124, R[0]); goto L_8009E5FC; }  /* 0x8009E5E8 j */
L_8009E5F0:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x8009E5F0 */
    sw_(R[16] + 124, R[2]);  /* 0x8009E5F8 */
L_8009E5FC:;
    R[2] = 0x8012u << 16;  /* 0x8009E5FC */
    R[2] = lh_(R[2] + 31132);  /* 0x8009E600 */
    R[2] = R[2] & 0x1;  /* 0x8009E608 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E60C */
    { R[31] = 0x8009E61Cu; R[5] = R[0] + 12; psx_next = 0x8009BC08u; return; }  /* 0x8009E614 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E61C */
    { R[31] = 0x8009E62Cu; R[5] = R[0] + 16; psx_next = 0x8009BC08u; return; }  /* 0x8009E624 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E62C */
    R[2] = lw_(R[16] + 72);  /* 0x8009E634 */
    R[2] = lh_(R[2]);  /* 0x8009E63C */
    R[2] = R[2] >> 13;  /* 0x8009E644 */
    R[2] = R[2] & 0x1;  /* 0x8009E648 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E64C */
    R[2] = lh_(R[16] + 22);  /* 0x8009E654 */
    R[2] = R[2] + 1;  /* 0x8009E65C */
    sh_(R[16] + 20, R[2]);  /* 0x8009E660 */
L_8009E664:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E664 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E668 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E66C jr ra */
}

void g0_8009E61C(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E664; } }  /* 0x8009E61C */
    { R[31] = 0x8009E62Cu; R[5] = R[0] + 16; psx_next = 0x8009BC08u; return; }  /* 0x8009E624 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E62C */
    R[2] = lw_(R[16] + 72);  /* 0x8009E634 */
    R[2] = lh_(R[2]);  /* 0x8009E63C */
    R[2] = R[2] >> 13;  /* 0x8009E644 */
    R[2] = R[2] & 0x1;  /* 0x8009E648 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E64C */
    R[2] = lh_(R[16] + 22);  /* 0x8009E654 */
    R[2] = R[2] + 1;  /* 0x8009E65C */
    sh_(R[16] + 20, R[2]);  /* 0x8009E660 */
L_8009E664:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E664 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E668 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E66C jr ra */
}

void g0_8009E62C(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E62C */
    R[2] = lw_(R[16] + 72);  /* 0x8009E634 */
    R[2] = lh_(R[2]);  /* 0x8009E63C */
    R[2] = R[2] >> 13;  /* 0x8009E644 */
    R[2] = R[2] & 0x1;  /* 0x8009E648 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E664; } }  /* 0x8009E64C */
    R[2] = lh_(R[16] + 22);  /* 0x8009E654 */
    R[2] = R[2] + 1;  /* 0x8009E65C */
    sh_(R[16] + 20, R[2]);  /* 0x8009E660 */
L_8009E664:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E664 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E668 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E66C jr ra */
}

void g0_8009E674(void) {
    R[29] = R[29] - 24;  /* 0x8009E674 */
    sw_(R[29] + 16, R[16]);  /* 0x8009E678 */
    R[16] = R[4] + R[0];  /* 0x8009E67C */
    sw_(R[29] + 20, R[31]);  /* 0x8009E680 */
    R[2] = lw_(R[16] + 72);  /* 0x8009E684 */
    R[2] = lh_(R[2]);  /* 0x8009E68C */
    R[2] = R[2] >> 13;  /* 0x8009E694 */
    R[2] = R[2] & 0x1;  /* 0x8009E698 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E6B4; } }  /* 0x8009E69C */
    { R[31] = 0x8009E6ACu; R[5] = R[0] + 31; psx_next = 0x8009BC84u; return; }  /* 0x8009E6A4 jal */
    R[2] = R[0] + 512;  /* 0x8009E6AC */
    sw_(R[16] + 124, R[2]);  /* 0x8009E6B0 */
L_8009E6B4:;
    R[31] = lw_(R[29] + 20);  /* 0x8009E6B4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E6B8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E6BC jr ra */
}

void g0_8009E6AC(void) {
    R[2] = R[0] + 512;  /* 0x8009E6AC */
    sw_(R[16] + 124, R[2]);  /* 0x8009E6B0 */
    R[31] = lw_(R[29] + 20);  /* 0x8009E6B4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E6B8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E6BC jr ra */
}

void g0_8009E6C4(void) {
    R[29] = R[29] - 24;  /* 0x8009E6C4 */
    sw_(R[29] + 16, R[31]);  /* 0x8009E6C8 */
    R[2] = lw_(R[4] + 72);  /* 0x8009E6CC */
    R[2] = lh_(R[2]);  /* 0x8009E6D4 */
    R[2] = R[2] >> 13;  /* 0x8009E6DC */
    R[2] = R[2] & 0x1;  /* 0x8009E6E0 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E6F4; } }  /* 0x8009E6E4 */
    { R[31] = 0x8009E6F4u; R[5] = R[0] + 32; psx_next = 0x8009BC84u; return; }  /* 0x8009E6EC jal */
L_8009E6F4:;
    R[31] = lw_(R[29] + 16);  /* 0x8009E6F4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E6FC jr ra */
}

void g0_8009E6F4(void) {
    R[31] = lw_(R[29] + 16);  /* 0x8009E6F4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009E6FC jr ra */
}

void g0_8009E704(void) {
    R[29] = R[29] - 32;  /* 0x8009E704 */
    sw_(R[29] + 16, R[16]);  /* 0x8009E708 */
    R[16] = R[4] + R[0];  /* 0x8009E70C */
    sw_(R[29] + 28, R[31]);  /* 0x8009E710 */
    sw_(R[29] + 24, R[18]);  /* 0x8009E714 */
    sw_(R[29] + 20, R[17]);  /* 0x8009E718 */
    R[2] = lw_(R[16] + 72);  /* 0x8009E71C */
    R[17] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x8009E724 */
    R[5] = R[0] + 32;  /* 0x8009E728 */
    { R[31] = 0x8009E734u; R[18] = R[17] + R[0]; psx_next = 0x8009BC08u; return; }  /* 0x8009E72C jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009E780; } }  /* 0x8009E734 */
    R[2] = lh_(R[2] + 16104);  /* 0x8009E73C */
    R[2] = R[2] & 0x1;  /* 0x8009E744 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 20; if (_c) { goto L_8009E780; } }  /* 0x8009E748 */
    { uint32_t _c = (R[17] != R[2]); R[2] = R[0] + 33; if (_c) { goto L_8009E770; } }  /* 0x8009E750 */
    { R[31] = 0x8009E760u; psx_next = 0x8009BCE8u; return; }  /* 0x8009E758 jal */
    R[4] = R[16] + R[0];  /* 0x8009E760 */
    { R[31] = 0x8009E76Cu; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009E764 jal */
    R[2] = R[0] + 33;  /* 0x8009E76C */
L_8009E770:;
    { uint32_t _c = (R[18] != R[2]); if (_c) { goto L_8009E780; } }  /* 0x8009E770 */
    { R[31] = 0x8009E780u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009E778 jal */
L_8009E780:;
    R[2] = lw_(R[16] + 72);  /* 0x8009E780 */
    R[2] = lh_(R[2]);  /* 0x8009E788 */
    R[2] = R[2] >> 13;  /* 0x8009E790 */
    R[2] = R[2] & 0x1;  /* 0x8009E794 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E7D8; } }  /* 0x8009E798 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 56);  /* 0x8009E7A0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E7C0; } }  /* 0x8009E7A8 */
    { R[31] = 0x8009E7B8u; R[5] = R[0] + 34; psx_next = 0x8009BC84u; return; }  /* 0x8009E7B0 jal */
    { goto L_8009E7D8; }  /* 0x8009E7B8 j */
L_8009E7C0:;
    R[2] = lh_(R[16] + 4);  /* 0x8009E7C0 */
    R[5] = R[0] + R[0];  /* 0x8009E7C4 */
    { R[31] = 0x8009E7D0u; sh_(R[16] + 6, R[2]); psx_next = 0x8009BC84u; return; }  /* 0x8009E7C8 jal */
    R[2] = R[0] + 30;  /* 0x8009E7D0 */
    sb_(R[16] + 797, R[2]);  /* 0x8009E7D4 */
L_8009E7D8:;
    R[31] = lw_(R[29] + 28);  /* 0x8009E7D8 */
    R[18] = lw_(R[29] + 24);  /* 0x8009E7DC */
    R[17] = lw_(R[29] + 20);  /* 0x8009E7E0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E7E4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009E7E8 jr ra */
}

void g0_8009E734(void) {
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009E780; } }  /* 0x8009E734 */
    R[2] = lh_(R[2] + 16104);  /* 0x8009E73C */
    R[2] = R[2] & 0x1;  /* 0x8009E744 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 20; if (_c) { goto L_8009E780; } }  /* 0x8009E748 */
    { uint32_t _c = (R[17] != R[2]); R[2] = R[0] + 33; if (_c) { goto L_8009E770; } }  /* 0x8009E750 */
    { R[31] = 0x8009E760u; psx_next = 0x8009BCE8u; return; }  /* 0x8009E758 jal */
    R[4] = R[16] + R[0];  /* 0x8009E760 */
    { R[31] = 0x8009E76Cu; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009E764 jal */
    R[2] = R[0] + 33;  /* 0x8009E76C */
L_8009E770:;
    { uint32_t _c = (R[18] != R[2]); if (_c) { goto L_8009E780; } }  /* 0x8009E770 */
    { R[31] = 0x8009E780u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009E778 jal */
L_8009E780:;
    R[2] = lw_(R[16] + 72);  /* 0x8009E780 */
    R[2] = lh_(R[2]);  /* 0x8009E788 */
    R[2] = R[2] >> 13;  /* 0x8009E790 */
    R[2] = R[2] & 0x1;  /* 0x8009E794 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E7D8; } }  /* 0x8009E798 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 56);  /* 0x8009E7A0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E7C0; } }  /* 0x8009E7A8 */
    { R[31] = 0x8009E7B8u; R[5] = R[0] + 34; psx_next = 0x8009BC84u; return; }  /* 0x8009E7B0 jal */
    { goto L_8009E7D8; }  /* 0x8009E7B8 j */
L_8009E7C0:;
    R[2] = lh_(R[16] + 4);  /* 0x8009E7C0 */
    R[5] = R[0] + R[0];  /* 0x8009E7C4 */
    { R[31] = 0x8009E7D0u; sh_(R[16] + 6, R[2]); psx_next = 0x8009BC84u; return; }  /* 0x8009E7C8 jal */
    R[2] = R[0] + 30;  /* 0x8009E7D0 */
    sb_(R[16] + 797, R[2]);  /* 0x8009E7D4 */
L_8009E7D8:;
    R[31] = lw_(R[29] + 28);  /* 0x8009E7D8 */
    R[18] = lw_(R[29] + 24);  /* 0x8009E7DC */
    R[17] = lw_(R[29] + 20);  /* 0x8009E7E0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E7E4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009E7E8 jr ra */
}

void g0_8009E760(void) {
    R[4] = R[16] + R[0];  /* 0x8009E760 */
    { R[31] = 0x8009E76Cu; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009E764 jal */
    R[2] = R[0] + 33;  /* 0x8009E76C */
    { uint32_t _c = (R[18] != R[2]); if (_c) { goto L_8009E780; } }  /* 0x8009E770 */
    { R[31] = 0x8009E780u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009E778 jal */
L_8009E780:;
    R[2] = lw_(R[16] + 72);  /* 0x8009E780 */
    R[2] = lh_(R[2]);  /* 0x8009E788 */
    R[2] = R[2] >> 13;  /* 0x8009E790 */
    R[2] = R[2] & 0x1;  /* 0x8009E794 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E7D8; } }  /* 0x8009E798 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 56);  /* 0x8009E7A0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E7C0; } }  /* 0x8009E7A8 */
    { R[31] = 0x8009E7B8u; R[5] = R[0] + 34; psx_next = 0x8009BC84u; return; }  /* 0x8009E7B0 jal */
    { goto L_8009E7D8; }  /* 0x8009E7B8 j */
L_8009E7C0:;
    R[2] = lh_(R[16] + 4);  /* 0x8009E7C0 */
    R[5] = R[0] + R[0];  /* 0x8009E7C4 */
    { R[31] = 0x8009E7D0u; sh_(R[16] + 6, R[2]); psx_next = 0x8009BC84u; return; }  /* 0x8009E7C8 jal */
    R[2] = R[0] + 30;  /* 0x8009E7D0 */
    sb_(R[16] + 797, R[2]);  /* 0x8009E7D4 */
L_8009E7D8:;
    R[31] = lw_(R[29] + 28);  /* 0x8009E7D8 */
    R[18] = lw_(R[29] + 24);  /* 0x8009E7DC */
    R[17] = lw_(R[29] + 20);  /* 0x8009E7E0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E7E4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009E7E8 jr ra */
}

void g0_8009E76C(void) {
    R[2] = R[0] + 33;  /* 0x8009E76C */
    { uint32_t _c = (R[18] != R[2]); if (_c) { goto L_8009E780; } }  /* 0x8009E770 */
    { R[31] = 0x8009E780u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009E778 jal */
L_8009E780:;
    R[2] = lw_(R[16] + 72);  /* 0x8009E780 */
    R[2] = lh_(R[2]);  /* 0x8009E788 */
    R[2] = R[2] >> 13;  /* 0x8009E790 */
    R[2] = R[2] & 0x1;  /* 0x8009E794 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E7D8; } }  /* 0x8009E798 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 56);  /* 0x8009E7A0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E7C0; } }  /* 0x8009E7A8 */
    { R[31] = 0x8009E7B8u; R[5] = R[0] + 34; psx_next = 0x8009BC84u; return; }  /* 0x8009E7B0 jal */
    { goto L_8009E7D8; }  /* 0x8009E7B8 j */
L_8009E7C0:;
    R[2] = lh_(R[16] + 4);  /* 0x8009E7C0 */
    R[5] = R[0] + R[0];  /* 0x8009E7C4 */
    { R[31] = 0x8009E7D0u; sh_(R[16] + 6, R[2]); psx_next = 0x8009BC84u; return; }  /* 0x8009E7C8 jal */
    R[2] = R[0] + 30;  /* 0x8009E7D0 */
    sb_(R[16] + 797, R[2]);  /* 0x8009E7D4 */
L_8009E7D8:;
    R[31] = lw_(R[29] + 28);  /* 0x8009E7D8 */
    R[18] = lw_(R[29] + 24);  /* 0x8009E7DC */
    R[17] = lw_(R[29] + 20);  /* 0x8009E7E0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E7E4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009E7E8 jr ra */
}

void g0_8009E780(void) {
    R[2] = lw_(R[16] + 72);  /* 0x8009E780 */
    R[2] = lh_(R[2]);  /* 0x8009E788 */
    R[2] = R[2] >> 13;  /* 0x8009E790 */
    R[2] = R[2] & 0x1;  /* 0x8009E794 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009E7D8; } }  /* 0x8009E798 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 56);  /* 0x8009E7A0 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009E7C0; } }  /* 0x8009E7A8 */
    { R[31] = 0x8009E7B8u; R[5] = R[0] + 34; psx_next = 0x8009BC84u; return; }  /* 0x8009E7B0 jal */
    { goto L_8009E7D8; }  /* 0x8009E7B8 j */
L_8009E7C0:;
    R[2] = lh_(R[16] + 4);  /* 0x8009E7C0 */
    R[5] = R[0] + R[0];  /* 0x8009E7C4 */
    { R[31] = 0x8009E7D0u; sh_(R[16] + 6, R[2]); psx_next = 0x8009BC84u; return; }  /* 0x8009E7C8 jal */
    R[2] = R[0] + 30;  /* 0x8009E7D0 */
    sb_(R[16] + 797, R[2]);  /* 0x8009E7D4 */
L_8009E7D8:;
    R[31] = lw_(R[29] + 28);  /* 0x8009E7D8 */
    R[18] = lw_(R[29] + 24);  /* 0x8009E7DC */
    R[17] = lw_(R[29] + 20);  /* 0x8009E7E0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E7E4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009E7E8 jr ra */
}

void g0_8009E7B8(void) {
    { goto L_8009E7D8; }  /* 0x8009E7B8 j */
    R[2] = lh_(R[16] + 4);  /* 0x8009E7C0 */
    R[5] = R[0] + R[0];  /* 0x8009E7C4 */
    { R[31] = 0x8009E7D0u; sh_(R[16] + 6, R[2]); psx_next = 0x8009BC84u; return; }  /* 0x8009E7C8 jal */
    R[2] = R[0] + 30;  /* 0x8009E7D0 */
    sb_(R[16] + 797, R[2]);  /* 0x8009E7D4 */
L_8009E7D8:;
    R[31] = lw_(R[29] + 28);  /* 0x8009E7D8 */
    R[18] = lw_(R[29] + 24);  /* 0x8009E7DC */
    R[17] = lw_(R[29] + 20);  /* 0x8009E7E0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E7E4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009E7E8 jr ra */
}

void g0_8009E7D0(void) {
    R[2] = R[0] + 30;  /* 0x8009E7D0 */
    sb_(R[16] + 797, R[2]);  /* 0x8009E7D4 */
    R[31] = lw_(R[29] + 28);  /* 0x8009E7D8 */
    R[18] = lw_(R[29] + 24);  /* 0x8009E7DC */
    R[17] = lw_(R[29] + 20);  /* 0x8009E7E0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E7E4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009E7E8 jr ra */
}

void g0_8009E7F0(void) {
    R[29] = R[29] - 48;  /* 0x8009E7F0 */
    sw_(R[29] + 36, R[17]);  /* 0x8009E7F4 */
    R[17] = R[4] + R[0];  /* 0x8009E7F8 */
    R[2] = 0x8006u << 16;  /* 0x8009E7FC */
    R[4] = R[2] - 6456;  /* 0x8009E800 */
    R[2] = lw_(R[2] + -6456);  /* 0x8009E804 */
    R[3] = 0xA000u << 16;  /* 0x8009E808 */
    sw_(R[29] + 40, R[31]);  /* 0x8009E80C */
    R[2] = R[2] & R[3];  /* 0x8009E810 */
    { uint32_t _c = (R[2] == R[0]); sw_(R[29] + 32, R[16]); if (_c) { goto L_8009E86C; } }  /* 0x8009E814 */
    R[16] = (uint32_t)(int16_t)lh_(R[17] + 8);  /* 0x8009E81C */
    R[2] = lw_(R[4] + 16);  /* 0x8009E820 */
    R[16] = R[16] + R[2];  /* 0x8009E828 */
    R[16] = R[16] & 0x1FF;  /* 0x8009E82C */
    R[16] = R[16] << 3;  /* 0x8009E830 */
    { R[31] = 0x8009E83Cu; R[4] = R[16] + R[0]; psx_next = 0x80035B18u; return; }  /* 0x8009E834 jal */
    R[4] = R[16] + R[0];  /* 0x8009E83C */
    sw_(R[29] + 16, R[2]);  /* 0x8009E840 */
    { R[31] = 0x8009E84Cu; sw_(R[29] + 20, R[0]); psx_next = 0x80035A48u; return; }  /* 0x8009E844 jal */
    R[4] = R[17] + R[0];  /* 0x8009E84C */
    sw_(R[29] + 24, R[2]);  /* 0x8009E850 */
    R[2] = R[0] + 1536;  /* 0x8009E854 */
    R[6] = R[29] + 16;  /* 0x8009E858 */
    sw_(R[29] + 28, R[2]);  /* 0x8009E85C */
    R[5] = lw_(R[4] + 352);  /* 0x8009E860 */
    { R[31] = 0x8009E86Cu; R[7] = R[4] + 196; psx_next = 0x80089690u; return; }  /* 0x8009E864 jal */
L_8009E86C:;
    R[31] = lw_(R[29] + 40);  /* 0x8009E86C */
    R[17] = lw_(R[29] + 36);  /* 0x8009E870 */
    R[16] = lw_(R[29] + 32);  /* 0x8009E874 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009E878 jr ra */
}

void g0_8009E83C(void) {
    R[4] = R[16] + R[0];  /* 0x8009E83C */
    sw_(R[29] + 16, R[2]);  /* 0x8009E840 */
    { R[31] = 0x8009E84Cu; sw_(R[29] + 20, R[0]); psx_next = 0x80035A48u; return; }  /* 0x8009E844 jal */
    R[4] = R[17] + R[0];  /* 0x8009E84C */
    sw_(R[29] + 24, R[2]);  /* 0x8009E850 */
    R[2] = R[0] + 1536;  /* 0x8009E854 */
    R[6] = R[29] + 16;  /* 0x8009E858 */
    sw_(R[29] + 28, R[2]);  /* 0x8009E85C */
    R[5] = lw_(R[4] + 352);  /* 0x8009E860 */
    { R[31] = 0x8009E86Cu; R[7] = R[4] + 196; psx_next = 0x80089690u; return; }  /* 0x8009E864 jal */
    R[31] = lw_(R[29] + 40);  /* 0x8009E86C */
    R[17] = lw_(R[29] + 36);  /* 0x8009E870 */
    R[16] = lw_(R[29] + 32);  /* 0x8009E874 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009E878 jr ra */
}

void g0_8009E84C(void) {
    R[4] = R[17] + R[0];  /* 0x8009E84C */
    sw_(R[29] + 24, R[2]);  /* 0x8009E850 */
    R[2] = R[0] + 1536;  /* 0x8009E854 */
    R[6] = R[29] + 16;  /* 0x8009E858 */
    sw_(R[29] + 28, R[2]);  /* 0x8009E85C */
    R[5] = lw_(R[4] + 352);  /* 0x8009E860 */
    { R[31] = 0x8009E86Cu; R[7] = R[4] + 196; psx_next = 0x80089690u; return; }  /* 0x8009E864 jal */
    R[31] = lw_(R[29] + 40);  /* 0x8009E86C */
    R[17] = lw_(R[29] + 36);  /* 0x8009E870 */
    R[16] = lw_(R[29] + 32);  /* 0x8009E874 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009E878 jr ra */
}

void g0_8009E86C(void) {
    R[31] = lw_(R[29] + 40);  /* 0x8009E86C */
    R[17] = lw_(R[29] + 36);  /* 0x8009E870 */
    R[16] = lw_(R[29] + 32);  /* 0x8009E874 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009E878 jr ra */
}

void g0_8009E880(void) {
    R[29] = R[29] - 32;  /* 0x8009E880 */
    R[3] = 0x8013u << 16;  /* 0x8009E884 */
    R[3] = R[3] - 29656;  /* 0x8009E888 */
    sw_(R[29] + 24, R[31]);  /* 0x8009E88C */
    sw_(R[29] + 20, R[17]);  /* 0x8009E890 */
    sw_(R[29] + 16, R[16]);  /* 0x8009E894 */
    R[2] = lh_(R[3] + 8);  /* 0x8009E898 */
    R[16] = R[4] + R[0];  /* 0x8009E89C */
    R[2] = R[2] + 1;  /* 0x8009E8A0 */
    sh_(R[3] + 8, R[2]);  /* 0x8009E8A4 */
    R[2] = R[2] << 16;  /* 0x8009E8A8 */
    R[3] = lw_(R[16] + 352);  /* 0x8009E8AC */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009E8B0 */
    R[3] = lw_(R[3] + 24);  /* 0x8009E8B4 */
    R[2] = ((int32_t)R[2] < 6);  /* 0x8009E8B8 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[3] + 24; if (_c) { goto L_8009E914; } }  /* 0x8009E8BC */
    R[4] = lb_(R[16] + 784);  /* 0x8009E8C4 */
    R[5] = R[0] + 2;  /* 0x8009E8C8 */
    { uint32_t _c = (R[4] == R[5]); if (_c) { goto L_8009E900; } }  /* 0x8009E8CC */
    R[2] = lb_(R[16] + 785);  /* 0x8009E8D4 */
    { uint32_t _c = (R[2] == R[5]); R[2] = R[0] + 1; if (_c) { goto L_8009E900; } }  /* 0x8009E8DC */
    { uint32_t _c = (R[4] != R[2]); if (_c) { goto L_8009E914; } }  /* 0x8009E8E4 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 2);  /* 0x8009E8EC */
    R[2] = ((int32_t)R[2] < 2049);  /* 0x8009E8F4 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009E914; } }  /* 0x8009E8F8 */
L_8009E900:;
    R[4] = R[16] + R[0];  /* 0x8009E900 */
    { R[31] = 0x8009E90Cu; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009E904 jal */
    { goto L_8009E950; }  /* 0x8009E90C j */
L_8009E914:;
    { R[31] = 0x8009E91Cu; R[4] = R[16] + R[0]; psx_next = 0x8009E7F0u; return; }  /* 0x8009E914 jal */
    R[2] = 0x8013u << 16;  /* 0x8009E91C */
    R[17] = R[2] - 29656;  /* 0x8009E920 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 8);  /* 0x8009E924 */
    R[2] = ((int32_t)R[2] < 30);  /* 0x8009E92C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009E94C; } }  /* 0x8009E930 */
    R[4] = R[16] + R[0];  /* 0x8009E938 */
    { R[31] = 0x8009E944u; R[5] = R[0] + 124; psx_next = 0x8009BC84u; return; }  /* 0x8009E93C jal */
    { sh_(R[17] + 10, R[0]); goto L_8009E950; }  /* 0x8009E944 j */
L_8009E94C:;
    sb_(R[16] + 795, R[2]);  /* 0x8009E94C */
L_8009E950:;
    R[31] = lw_(R[29] + 24);  /* 0x8009E950 */
    R[17] = lw_(R[29] + 20);  /* 0x8009E954 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E958 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009E95C jr ra */
    R[2] = 0x8013u << 16;  /* 0x8009E964 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + -29646);  /* 0x8009E968 */
    psx_next = 0x8009E96Cu; return;  /* fallthrough */
}

void g0_8009E90C(void) {
    { goto L_8009E950; }  /* 0x8009E90C j */
    { R[31] = 0x8009E91Cu; R[4] = R[16] + R[0]; psx_next = 0x8009E7F0u; return; }  /* 0x8009E914 jal */
    R[2] = 0x8013u << 16;  /* 0x8009E91C */
    R[17] = R[2] - 29656;  /* 0x8009E920 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 8);  /* 0x8009E924 */
    R[2] = ((int32_t)R[2] < 30);  /* 0x8009E92C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009E94C; } }  /* 0x8009E930 */
    R[4] = R[16] + R[0];  /* 0x8009E938 */
    { R[31] = 0x8009E944u; R[5] = R[0] + 124; psx_next = 0x8009BC84u; return; }  /* 0x8009E93C jal */
    { sh_(R[17] + 10, R[0]); goto L_8009E950; }  /* 0x8009E944 j */
L_8009E94C:;
    sb_(R[16] + 795, R[2]);  /* 0x8009E94C */
L_8009E950:;
    R[31] = lw_(R[29] + 24);  /* 0x8009E950 */
    R[17] = lw_(R[29] + 20);  /* 0x8009E954 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E958 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009E95C jr ra */
    R[2] = 0x8013u << 16;  /* 0x8009E964 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + -29646);  /* 0x8009E968 */
    psx_next = 0x8009E96Cu; return;  /* fallthrough */
}

void g0_8009E91C(void) {
    R[2] = 0x8013u << 16;  /* 0x8009E91C */
    R[17] = R[2] - 29656;  /* 0x8009E920 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 8);  /* 0x8009E924 */
    R[2] = ((int32_t)R[2] < 30);  /* 0x8009E92C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009E94C; } }  /* 0x8009E930 */
    R[4] = R[16] + R[0];  /* 0x8009E938 */
    { R[31] = 0x8009E944u; R[5] = R[0] + 124; psx_next = 0x8009BC84u; return; }  /* 0x8009E93C jal */
    { sh_(R[17] + 10, R[0]); goto L_8009E950; }  /* 0x8009E944 j */
L_8009E94C:;
    sb_(R[16] + 795, R[2]);  /* 0x8009E94C */
L_8009E950:;
    R[31] = lw_(R[29] + 24);  /* 0x8009E950 */
    R[17] = lw_(R[29] + 20);  /* 0x8009E954 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E958 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009E95C jr ra */
    R[2] = 0x8013u << 16;  /* 0x8009E964 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + -29646);  /* 0x8009E968 */
    psx_next = 0x8009E96Cu; return;  /* fallthrough */
}

void g0_8009E944(void) {
    { sh_(R[17] + 10, R[0]); goto L_8009E950; }  /* 0x8009E944 j */
    sb_(R[16] + 795, R[2]);  /* 0x8009E94C */
L_8009E950:;
    R[31] = lw_(R[29] + 24);  /* 0x8009E950 */
    R[17] = lw_(R[29] + 20);  /* 0x8009E954 */
    R[16] = lw_(R[29] + 16);  /* 0x8009E958 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009E95C jr ra */
    R[2] = 0x8013u << 16;  /* 0x8009E964 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + -29646);  /* 0x8009E968 */
    psx_next = 0x8009E96Cu; return;  /* fallthrough */
}

void g0_8009E964(void) {
    R[2] = 0x8013u << 16;  /* 0x8009E964 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + -29646);  /* 0x8009E968 */
    psx_next = 0x8009E96Cu; return;  /* fallthrough */
}

void g0_8009E96C(void) {
    R[29] = R[29] - 24;  /* 0x8009E96C */
    sw_(R[29] + 16, R[16]);  /* 0x8009E970 */
    R[16] = R[4] + R[0];  /* 0x8009E974 */
    R[2] = ((int32_t)R[2] < 30);  /* 0x8009E978 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[29] + 20, R[31]); if (_c) { goto L_8009E9CC; } }  /* 0x8009E97C */
    { R[31] = 0x8009E98Cu; psx_next = 0x8009D8D0u; return; }  /* 0x8009E984 jal */
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] + 10; if (_c) { goto L_8009EA28; } }  /* 0x8009E98C */
    R[4] = R[16] + R[0];  /* 0x8009E994 */
    { R[31] = 0x8009E9A0u; R[6] = R[0] + 1; psx_next = 0x8009D268u; return; }  /* 0x8009E998 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009EA28; } }  /* 0x8009E9A0 */
    R[2] = lb_(R[16] + 784);  /* 0x8009E9A8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009EA28; } }  /* 0x8009E9B0 */
    R[4] = R[16] + R[0];  /* 0x8009E9B8 */
    { R[31] = 0x8009E9C4u; R[5] = R[0] + 28; psx_next = 0x8009BC84u; return; }  /* 0x8009E9BC jal */
    { goto L_8009EA28; }  /* 0x8009E9C4 j */
L_8009E9CC:;
    R[2] = lw_(R[16] + 352);  /* 0x8009E9CC */
    R[2] = lw_(R[2] + 24);  /* 0x8009E9D4 */
    R[3] = lb_(R[16] + 784);  /* 0x8009E9D8 */
    R[4] = R[2] + 24;  /* 0x8009E9DC */
    R[2] = R[0] + 2;  /* 0x8009E9E0 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_8009EA08; } }  /* 0x8009E9E4 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009EA20; } }  /* 0x8009E9EC */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 2);  /* 0x8009E9F4 */
    R[2] = ((int32_t)R[2] < 2049);  /* 0x8009E9FC */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009EA20; } }  /* 0x8009EA00 */
L_8009EA08:;
    R[4] = R[16] + R[0];  /* 0x8009EA08 */
    { R[31] = 0x8009EA14u; R[5] = R[0] + 31; psx_next = 0x8009BC84u; return; }  /* 0x8009EA0C jal */
    R[2] = R[0] + 512;  /* 0x8009EA14 */
    { sw_(R[16] + 124, R[2]); goto L_8009EA28; }  /* 0x8009EA18 j */
L_8009EA20:;
    { R[31] = 0x8009EA28u; R[4] = R[16] + R[0]; psx_next = 0x8009E7F0u; return; }  /* 0x8009EA20 jal */
L_8009EA28:;
    R[31] = lw_(R[29] + 20);  /* 0x8009EA28 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EA2C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009EA30 jr ra */
}

void g0_8009E98C(void) {
    { uint32_t _c = (R[2] != R[0]); R[5] = R[0] + 10; if (_c) { goto L_8009EA28; } }  /* 0x8009E98C */
    R[4] = R[16] + R[0];  /* 0x8009E994 */
    { R[31] = 0x8009E9A0u; R[6] = R[0] + 1; psx_next = 0x8009D268u; return; }  /* 0x8009E998 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009EA28; } }  /* 0x8009E9A0 */
    R[2] = lb_(R[16] + 784);  /* 0x8009E9A8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009EA28; } }  /* 0x8009E9B0 */
    R[4] = R[16] + R[0];  /* 0x8009E9B8 */
    { R[31] = 0x8009E9C4u; R[5] = R[0] + 28; psx_next = 0x8009BC84u; return; }  /* 0x8009E9BC jal */
    { goto L_8009EA28; }  /* 0x8009E9C4 j */
    R[2] = lw_(R[16] + 352);  /* 0x8009E9CC */
    R[2] = lw_(R[2] + 24);  /* 0x8009E9D4 */
    R[3] = lb_(R[16] + 784);  /* 0x8009E9D8 */
    R[4] = R[2] + 24;  /* 0x8009E9DC */
    R[2] = R[0] + 2;  /* 0x8009E9E0 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_8009EA08; } }  /* 0x8009E9E4 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009EA20; } }  /* 0x8009E9EC */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 2);  /* 0x8009E9F4 */
    R[2] = ((int32_t)R[2] < 2049);  /* 0x8009E9FC */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009EA20; } }  /* 0x8009EA00 */
L_8009EA08:;
    R[4] = R[16] + R[0];  /* 0x8009EA08 */
    { R[31] = 0x8009EA14u; R[5] = R[0] + 31; psx_next = 0x8009BC84u; return; }  /* 0x8009EA0C jal */
    R[2] = R[0] + 512;  /* 0x8009EA14 */
    { sw_(R[16] + 124, R[2]); goto L_8009EA28; }  /* 0x8009EA18 j */
L_8009EA20:;
    { R[31] = 0x8009EA28u; R[4] = R[16] + R[0]; psx_next = 0x8009E7F0u; return; }  /* 0x8009EA20 jal */
L_8009EA28:;
    R[31] = lw_(R[29] + 20);  /* 0x8009EA28 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EA2C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009EA30 jr ra */
}

void g0_8009E9A0(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009EA28; } }  /* 0x8009E9A0 */
    R[2] = lb_(R[16] + 784);  /* 0x8009E9A8 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009EA28; } }  /* 0x8009E9B0 */
    R[4] = R[16] + R[0];  /* 0x8009E9B8 */
    { R[31] = 0x8009E9C4u; R[5] = R[0] + 28; psx_next = 0x8009BC84u; return; }  /* 0x8009E9BC jal */
    { goto L_8009EA28; }  /* 0x8009E9C4 j */
    R[2] = lw_(R[16] + 352);  /* 0x8009E9CC */
    R[2] = lw_(R[2] + 24);  /* 0x8009E9D4 */
    R[3] = lb_(R[16] + 784);  /* 0x8009E9D8 */
    R[4] = R[2] + 24;  /* 0x8009E9DC */
    R[2] = R[0] + 2;  /* 0x8009E9E0 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_8009EA08; } }  /* 0x8009E9E4 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009EA20; } }  /* 0x8009E9EC */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 2);  /* 0x8009E9F4 */
    R[2] = ((int32_t)R[2] < 2049);  /* 0x8009E9FC */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009EA20; } }  /* 0x8009EA00 */
L_8009EA08:;
    R[4] = R[16] + R[0];  /* 0x8009EA08 */
    { R[31] = 0x8009EA14u; R[5] = R[0] + 31; psx_next = 0x8009BC84u; return; }  /* 0x8009EA0C jal */
    R[2] = R[0] + 512;  /* 0x8009EA14 */
    { sw_(R[16] + 124, R[2]); goto L_8009EA28; }  /* 0x8009EA18 j */
L_8009EA20:;
    { R[31] = 0x8009EA28u; R[4] = R[16] + R[0]; psx_next = 0x8009E7F0u; return; }  /* 0x8009EA20 jal */
L_8009EA28:;
    R[31] = lw_(R[29] + 20);  /* 0x8009EA28 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EA2C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009EA30 jr ra */
}

void g0_8009E9C4(void) {
    { goto L_8009EA28; }  /* 0x8009E9C4 j */
    R[2] = lw_(R[16] + 352);  /* 0x8009E9CC */
    R[2] = lw_(R[2] + 24);  /* 0x8009E9D4 */
    R[3] = lb_(R[16] + 784);  /* 0x8009E9D8 */
    R[4] = R[2] + 24;  /* 0x8009E9DC */
    R[2] = R[0] + 2;  /* 0x8009E9E0 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_8009EA08; } }  /* 0x8009E9E4 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009EA20; } }  /* 0x8009E9EC */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 2);  /* 0x8009E9F4 */
    R[2] = ((int32_t)R[2] < 2049);  /* 0x8009E9FC */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009EA20; } }  /* 0x8009EA00 */
L_8009EA08:;
    R[4] = R[16] + R[0];  /* 0x8009EA08 */
    { R[31] = 0x8009EA14u; R[5] = R[0] + 31; psx_next = 0x8009BC84u; return; }  /* 0x8009EA0C jal */
    R[2] = R[0] + 512;  /* 0x8009EA14 */
    { sw_(R[16] + 124, R[2]); goto L_8009EA28; }  /* 0x8009EA18 j */
L_8009EA20:;
    { R[31] = 0x8009EA28u; R[4] = R[16] + R[0]; psx_next = 0x8009E7F0u; return; }  /* 0x8009EA20 jal */
L_8009EA28:;
    R[31] = lw_(R[29] + 20);  /* 0x8009EA28 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EA2C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009EA30 jr ra */
}

void g0_8009EA14(void) {
    R[2] = R[0] + 512;  /* 0x8009EA14 */
    { sw_(R[16] + 124, R[2]); goto L_8009EA28; }  /* 0x8009EA18 j */
    { R[31] = 0x8009EA28u; R[4] = R[16] + R[0]; psx_next = 0x8009E7F0u; return; }  /* 0x8009EA20 jal */
L_8009EA28:;
    R[31] = lw_(R[29] + 20);  /* 0x8009EA28 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EA2C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009EA30 jr ra */
}

void g0_8009EA28(void) {
    R[31] = lw_(R[29] + 20);  /* 0x8009EA28 */
    R[16] = lw_(R[29] + 16);  /* 0x8009EA2C */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009EA30 jr ra */
}

void g0_8009EA38(void) {
    R[6] = R[4] + R[0];  /* 0x8009EA38 */
    R[2] = 0x8006u << 16;  /* 0x8009EA3C */
    R[3] = 0x8013u << 16;  /* 0x8009EA40 */
    R[4] = (uint32_t)(int16_t)lh_(R[2] + 16102);  /* 0x8009EA44 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + -29656);  /* 0x8009EA48 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x8009EA50 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[3] - 29656; if (_c) { goto L_8009EAC4; } }  /* 0x8009EA54 */
    R[2] = (uint32_t)(int16_t)lh_(R[6] + 218);  /* 0x8009EA5C */
    { uint32_t _c = (R[2] == R[0]); R[2] = ((int32_t)R[5] < 5); if (_c) { goto L_8009EA88; } }  /* 0x8009EA64 */
    R[2] = lb_(R[3] + 30);  /* 0x8009EA6C */
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[5] < 5); if (_c) { goto L_8009EA88; } }  /* 0x8009EA74 */
    R[2] = R[0] + 1;  /* 0x8009EA7C */
    sb_(R[3] + 30, R[2]);  /* 0x8009EA80 */
    R[2] = ((int32_t)R[5] < 5);  /* 0x8009EA84 */
L_8009EA88:;
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009EAC4; } }  /* 0x8009EA88 */
    R[3] = 0x8006u << 16;  /* 0x8009EA90 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009EA94 */
    R[3] = lh_(R[3] + 16110);  /* 0x8009EA98 */
    R[2] = R[2] & R[3];  /* 0x8009EAA0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009EAC4; } }  /* 0x8009EAA4 */
    R[4] = R[2] - 29656;  /* 0x8009EAAC */
    R[3] = lb_(R[4] + 30);  /* 0x8009EAB0 */
    R[2] = R[0] + 1;  /* 0x8009EAB4 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 2; if (_c) { goto L_8009EAC4; } }  /* 0x8009EAB8 */
    sb_(R[4] + 30, R[2]);  /* 0x8009EAC0 */
L_8009EAC4:;
    { psx_next = R[31]; return; }  /* 0x8009EAC4 jr ra */
}

void g0_8009EACC(void) {
    R[29] = R[29] - 48;  /* 0x8009EACC */
    sw_(R[29] + 32, R[16]);  /* 0x8009EAD0 */
    R[16] = R[4] + R[0];  /* 0x8009EAD4 */
    sw_(R[29] + 44, R[31]);  /* 0x8009EAD8 */
    sw_(R[29] + 40, R[18]);  /* 0x8009EADC */
    sw_(R[29] + 36, R[17]);  /* 0x8009EAE0 */
    R[2] = lw_(R[16] + 72);  /* 0x8009EAE4 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x8009EAEC */
    R[2] = R[0] + 1;  /* 0x8009EAF0 */
    { uint32_t _c = (R[3] != R[2]); R[17] = R[3] + R[0]; if (_c) { goto L_8009EB18; } }  /* 0x8009EAF4 */
    { R[31] = 0x8009EB04u; psx_next = 0x8009BCE8u; return; }  /* 0x8009EAFC jal */
    R[4] = R[16] + R[0];  /* 0x8009EB04 */
    { R[31] = 0x8009EB10u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EB08 jal */
    R[2] = 0x8013u << 16;  /* 0x8009EB10 */
    sb_(R[2] + -29626, R[0]);  /* 0x8009EB14 */
L_8009EB18:;
    R[2] = 0x8013u << 16;  /* 0x8009EB18 */
    sh_(R[2] + -29656, R[0]);  /* 0x8009EB1C */
    R[4] = R[16] + R[0];  /* 0x8009EB20 */
    R[5] = R[17] + R[0];  /* 0x8009EB24 */
    { R[31] = 0x8009EB30u; R[18] = R[2] - 29656; psx_next = 0x8009EA38u; return; }  /* 0x8009EB28 jal */
    R[2] = R[0] + 10;  /* 0x8009EB30 */
    { uint32_t _c = (R[17] != R[2]); if (_c) { goto L_8009EB44; } }  /* 0x8009EB34 */
    { R[31] = 0x8009EB44u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EB3C jal */
L_8009EB44:;
    R[2] = lw_(R[16] + 72);  /* 0x8009EB44 */
    R[2] = lh_(R[2]);  /* 0x8009EB4C */
    R[2] = R[2] >> 13;  /* 0x8009EB54 */
    R[2] = R[2] & 0x1;  /* 0x8009EB58 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009EC24; } }  /* 0x8009EB5C */
    R[2] = (uint32_t)(int16_t)lh_(R[18] + 58);  /* 0x8009EB64 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009EBCC; } }  /* 0x8009EB6C */
    { R[31] = 0x8009EB7Cu; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EB74 jal */
    R[4] = R[16] + R[0];  /* 0x8009EB7C */
    { R[31] = 0x8009EB88u; R[5] = R[0] + 85; psx_next = 0x8009BC84u; return; }  /* 0x8009EB80 jal */
    R[4] = R[0] + 22;  /* 0x8009EB88 */
    R[2] = lw_(R[16] + 24);  /* 0x8009EB8C */
    R[3] = 0xFFCEu << 16;  /* 0x8009EB90 */
    sw_(R[29] + 16, R[2]);  /* 0x8009EB94 */
    R[2] = lw_(R[16] + 28);  /* 0x8009EB98 */
    R[5] = R[16] + R[0];  /* 0x8009EB9C */
    R[2] = R[2] + R[3];  /* 0x8009EBA0 */
    sw_(R[29] + 20, R[2]);  /* 0x8009EBA4 */
    R[2] = lw_(R[16] + 32);  /* 0x8009EBA8 */
    R[6] = R[29] + 16;  /* 0x8009EBAC */
    { R[31] = 0x8009EBB8u; sw_(R[29] + 24, R[2]); psx_next = 0x800AC93Cu; return; }  /* 0x8009EBB0 jal */
    { R[31] = 0x8009EBC0u; R[4] = R[0] + 16; psx_next = 0x800908F4u; return; }  /* 0x8009EBB8 jal */
    R[2] = R[2] << 5;  /* 0x8009EBC0 */
    { sh_(R[18] + 60, R[2]); goto L_8009EC24; }  /* 0x8009EBC4 j */
L_8009EBCC:;
    R[3] = lb_(R[18] + 30);  /* 0x8009EBCC */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC0C; } }  /* 0x8009EBD4 */
    { R[31] = 0x8009EBE4u; R[5] = R[0] + 93; psx_next = 0x8009BC84u; return; }  /* 0x8009EBDC jal */
    R[2] = lb_(R[16] + 781);  /* 0x8009EBE4 */
    R[2] = R[2] | 0x80;  /* 0x8009EBEC */
    { R[31] = 0x8009EBF8u; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009EBF0 jal */
    R[4] = R[16] + R[0];  /* 0x8009EBF8 */
    { R[31] = 0x8009EC04u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EBFC jal */
    { sb_(R[18] + 30, R[0]); goto L_8009EC24; }  /* 0x8009EC04 j */
L_8009EC0C:;
    { R[31] = 0x8009EC14u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009EC0C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC24; } }  /* 0x8009EC14 */
    { R[31] = 0x8009EC24u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EC1C jal */
L_8009EC24:;
    R[31] = lw_(R[29] + 44);  /* 0x8009EC24 */
    R[18] = lw_(R[29] + 40);  /* 0x8009EC28 */
    R[17] = lw_(R[29] + 36);  /* 0x8009EC2C */
    R[16] = lw_(R[29] + 32);  /* 0x8009EC30 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009EC34 jr ra */
}

void g0_8009EB04(void) {
    R[4] = R[16] + R[0];  /* 0x8009EB04 */
    { R[31] = 0x8009EB10u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EB08 jal */
    R[2] = 0x8013u << 16;  /* 0x8009EB10 */
    sb_(R[2] + -29626, R[0]);  /* 0x8009EB14 */
    R[2] = 0x8013u << 16;  /* 0x8009EB18 */
    sh_(R[2] + -29656, R[0]);  /* 0x8009EB1C */
    R[4] = R[16] + R[0];  /* 0x8009EB20 */
    R[5] = R[17] + R[0];  /* 0x8009EB24 */
    { R[31] = 0x8009EB30u; R[18] = R[2] - 29656; psx_next = 0x8009EA38u; return; }  /* 0x8009EB28 jal */
    R[2] = R[0] + 10;  /* 0x8009EB30 */
    { uint32_t _c = (R[17] != R[2]); if (_c) { goto L_8009EB44; } }  /* 0x8009EB34 */
    { R[31] = 0x8009EB44u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EB3C jal */
L_8009EB44:;
    R[2] = lw_(R[16] + 72);  /* 0x8009EB44 */
    R[2] = lh_(R[2]);  /* 0x8009EB4C */
    R[2] = R[2] >> 13;  /* 0x8009EB54 */
    R[2] = R[2] & 0x1;  /* 0x8009EB58 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009EC24; } }  /* 0x8009EB5C */
    R[2] = (uint32_t)(int16_t)lh_(R[18] + 58);  /* 0x8009EB64 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009EBCC; } }  /* 0x8009EB6C */
    { R[31] = 0x8009EB7Cu; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EB74 jal */
    R[4] = R[16] + R[0];  /* 0x8009EB7C */
    { R[31] = 0x8009EB88u; R[5] = R[0] + 85; psx_next = 0x8009BC84u; return; }  /* 0x8009EB80 jal */
    R[4] = R[0] + 22;  /* 0x8009EB88 */
    R[2] = lw_(R[16] + 24);  /* 0x8009EB8C */
    R[3] = 0xFFCEu << 16;  /* 0x8009EB90 */
    sw_(R[29] + 16, R[2]);  /* 0x8009EB94 */
    R[2] = lw_(R[16] + 28);  /* 0x8009EB98 */
    R[5] = R[16] + R[0];  /* 0x8009EB9C */
    R[2] = R[2] + R[3];  /* 0x8009EBA0 */
    sw_(R[29] + 20, R[2]);  /* 0x8009EBA4 */
    R[2] = lw_(R[16] + 32);  /* 0x8009EBA8 */
    R[6] = R[29] + 16;  /* 0x8009EBAC */
    { R[31] = 0x8009EBB8u; sw_(R[29] + 24, R[2]); psx_next = 0x800AC93Cu; return; }  /* 0x8009EBB0 jal */
    { R[31] = 0x8009EBC0u; R[4] = R[0] + 16; psx_next = 0x800908F4u; return; }  /* 0x8009EBB8 jal */
    R[2] = R[2] << 5;  /* 0x8009EBC0 */
    { sh_(R[18] + 60, R[2]); goto L_8009EC24; }  /* 0x8009EBC4 j */
L_8009EBCC:;
    R[3] = lb_(R[18] + 30);  /* 0x8009EBCC */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC0C; } }  /* 0x8009EBD4 */
    { R[31] = 0x8009EBE4u; R[5] = R[0] + 93; psx_next = 0x8009BC84u; return; }  /* 0x8009EBDC jal */
    R[2] = lb_(R[16] + 781);  /* 0x8009EBE4 */
    R[2] = R[2] | 0x80;  /* 0x8009EBEC */
    { R[31] = 0x8009EBF8u; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009EBF0 jal */
    R[4] = R[16] + R[0];  /* 0x8009EBF8 */
    { R[31] = 0x8009EC04u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EBFC jal */
    { sb_(R[18] + 30, R[0]); goto L_8009EC24; }  /* 0x8009EC04 j */
L_8009EC0C:;
    { R[31] = 0x8009EC14u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009EC0C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC24; } }  /* 0x8009EC14 */
    { R[31] = 0x8009EC24u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EC1C jal */
L_8009EC24:;
    R[31] = lw_(R[29] + 44);  /* 0x8009EC24 */
    R[18] = lw_(R[29] + 40);  /* 0x8009EC28 */
    R[17] = lw_(R[29] + 36);  /* 0x8009EC2C */
    R[16] = lw_(R[29] + 32);  /* 0x8009EC30 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009EC34 jr ra */
}

void g0_8009EB10(void) {
    R[2] = 0x8013u << 16;  /* 0x8009EB10 */
    sb_(R[2] + -29626, R[0]);  /* 0x8009EB14 */
    R[2] = 0x8013u << 16;  /* 0x8009EB18 */
    sh_(R[2] + -29656, R[0]);  /* 0x8009EB1C */
    R[4] = R[16] + R[0];  /* 0x8009EB20 */
    R[5] = R[17] + R[0];  /* 0x8009EB24 */
    { R[31] = 0x8009EB30u; R[18] = R[2] - 29656; psx_next = 0x8009EA38u; return; }  /* 0x8009EB28 jal */
    R[2] = R[0] + 10;  /* 0x8009EB30 */
    { uint32_t _c = (R[17] != R[2]); if (_c) { goto L_8009EB44; } }  /* 0x8009EB34 */
    { R[31] = 0x8009EB44u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EB3C jal */
L_8009EB44:;
    R[2] = lw_(R[16] + 72);  /* 0x8009EB44 */
    R[2] = lh_(R[2]);  /* 0x8009EB4C */
    R[2] = R[2] >> 13;  /* 0x8009EB54 */
    R[2] = R[2] & 0x1;  /* 0x8009EB58 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009EC24; } }  /* 0x8009EB5C */
    R[2] = (uint32_t)(int16_t)lh_(R[18] + 58);  /* 0x8009EB64 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009EBCC; } }  /* 0x8009EB6C */
    { R[31] = 0x8009EB7Cu; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EB74 jal */
    R[4] = R[16] + R[0];  /* 0x8009EB7C */
    { R[31] = 0x8009EB88u; R[5] = R[0] + 85; psx_next = 0x8009BC84u; return; }  /* 0x8009EB80 jal */
    R[4] = R[0] + 22;  /* 0x8009EB88 */
    R[2] = lw_(R[16] + 24);  /* 0x8009EB8C */
    R[3] = 0xFFCEu << 16;  /* 0x8009EB90 */
    sw_(R[29] + 16, R[2]);  /* 0x8009EB94 */
    R[2] = lw_(R[16] + 28);  /* 0x8009EB98 */
    R[5] = R[16] + R[0];  /* 0x8009EB9C */
    R[2] = R[2] + R[3];  /* 0x8009EBA0 */
    sw_(R[29] + 20, R[2]);  /* 0x8009EBA4 */
    R[2] = lw_(R[16] + 32);  /* 0x8009EBA8 */
    R[6] = R[29] + 16;  /* 0x8009EBAC */
    { R[31] = 0x8009EBB8u; sw_(R[29] + 24, R[2]); psx_next = 0x800AC93Cu; return; }  /* 0x8009EBB0 jal */
    { R[31] = 0x8009EBC0u; R[4] = R[0] + 16; psx_next = 0x800908F4u; return; }  /* 0x8009EBB8 jal */
    R[2] = R[2] << 5;  /* 0x8009EBC0 */
    { sh_(R[18] + 60, R[2]); goto L_8009EC24; }  /* 0x8009EBC4 j */
L_8009EBCC:;
    R[3] = lb_(R[18] + 30);  /* 0x8009EBCC */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC0C; } }  /* 0x8009EBD4 */
    { R[31] = 0x8009EBE4u; R[5] = R[0] + 93; psx_next = 0x8009BC84u; return; }  /* 0x8009EBDC jal */
    R[2] = lb_(R[16] + 781);  /* 0x8009EBE4 */
    R[2] = R[2] | 0x80;  /* 0x8009EBEC */
    { R[31] = 0x8009EBF8u; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009EBF0 jal */
    R[4] = R[16] + R[0];  /* 0x8009EBF8 */
    { R[31] = 0x8009EC04u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EBFC jal */
    { sb_(R[18] + 30, R[0]); goto L_8009EC24; }  /* 0x8009EC04 j */
L_8009EC0C:;
    { R[31] = 0x8009EC14u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009EC0C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC24; } }  /* 0x8009EC14 */
    { R[31] = 0x8009EC24u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EC1C jal */
L_8009EC24:;
    R[31] = lw_(R[29] + 44);  /* 0x8009EC24 */
    R[18] = lw_(R[29] + 40);  /* 0x8009EC28 */
    R[17] = lw_(R[29] + 36);  /* 0x8009EC2C */
    R[16] = lw_(R[29] + 32);  /* 0x8009EC30 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009EC34 jr ra */
}

void g0_8009EB30(void) {
    R[2] = R[0] + 10;  /* 0x8009EB30 */
    { uint32_t _c = (R[17] != R[2]); if (_c) { goto L_8009EB44; } }  /* 0x8009EB34 */
    { R[31] = 0x8009EB44u; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EB3C jal */
L_8009EB44:;
    R[2] = lw_(R[16] + 72);  /* 0x8009EB44 */
    R[2] = lh_(R[2]);  /* 0x8009EB4C */
    R[2] = R[2] >> 13;  /* 0x8009EB54 */
    R[2] = R[2] & 0x1;  /* 0x8009EB58 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009EC24; } }  /* 0x8009EB5C */
    R[2] = (uint32_t)(int16_t)lh_(R[18] + 58);  /* 0x8009EB64 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009EBCC; } }  /* 0x8009EB6C */
    { R[31] = 0x8009EB7Cu; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EB74 jal */
    R[4] = R[16] + R[0];  /* 0x8009EB7C */
    { R[31] = 0x8009EB88u; R[5] = R[0] + 85; psx_next = 0x8009BC84u; return; }  /* 0x8009EB80 jal */
    R[4] = R[0] + 22;  /* 0x8009EB88 */
    R[2] = lw_(R[16] + 24);  /* 0x8009EB8C */
    R[3] = 0xFFCEu << 16;  /* 0x8009EB90 */
    sw_(R[29] + 16, R[2]);  /* 0x8009EB94 */
    R[2] = lw_(R[16] + 28);  /* 0x8009EB98 */
    R[5] = R[16] + R[0];  /* 0x8009EB9C */
    R[2] = R[2] + R[3];  /* 0x8009EBA0 */
    sw_(R[29] + 20, R[2]);  /* 0x8009EBA4 */
    R[2] = lw_(R[16] + 32);  /* 0x8009EBA8 */
    R[6] = R[29] + 16;  /* 0x8009EBAC */
    { R[31] = 0x8009EBB8u; sw_(R[29] + 24, R[2]); psx_next = 0x800AC93Cu; return; }  /* 0x8009EBB0 jal */
    { R[31] = 0x8009EBC0u; R[4] = R[0] + 16; psx_next = 0x800908F4u; return; }  /* 0x8009EBB8 jal */
    R[2] = R[2] << 5;  /* 0x8009EBC0 */
    { sh_(R[18] + 60, R[2]); goto L_8009EC24; }  /* 0x8009EBC4 j */
L_8009EBCC:;
    R[3] = lb_(R[18] + 30);  /* 0x8009EBCC */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC0C; } }  /* 0x8009EBD4 */
    { R[31] = 0x8009EBE4u; R[5] = R[0] + 93; psx_next = 0x8009BC84u; return; }  /* 0x8009EBDC jal */
    R[2] = lb_(R[16] + 781);  /* 0x8009EBE4 */
    R[2] = R[2] | 0x80;  /* 0x8009EBEC */
    { R[31] = 0x8009EBF8u; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009EBF0 jal */
    R[4] = R[16] + R[0];  /* 0x8009EBF8 */
    { R[31] = 0x8009EC04u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EBFC jal */
    { sb_(R[18] + 30, R[0]); goto L_8009EC24; }  /* 0x8009EC04 j */
L_8009EC0C:;
    { R[31] = 0x8009EC14u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009EC0C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC24; } }  /* 0x8009EC14 */
    { R[31] = 0x8009EC24u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EC1C jal */
L_8009EC24:;
    R[31] = lw_(R[29] + 44);  /* 0x8009EC24 */
    R[18] = lw_(R[29] + 40);  /* 0x8009EC28 */
    R[17] = lw_(R[29] + 36);  /* 0x8009EC2C */
    R[16] = lw_(R[29] + 32);  /* 0x8009EC30 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009EC34 jr ra */
}

void g0_8009EB44(void) {
    R[2] = lw_(R[16] + 72);  /* 0x8009EB44 */
    R[2] = lh_(R[2]);  /* 0x8009EB4C */
    R[2] = R[2] >> 13;  /* 0x8009EB54 */
    R[2] = R[2] & 0x1;  /* 0x8009EB58 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009EC24; } }  /* 0x8009EB5C */
    R[2] = (uint32_t)(int16_t)lh_(R[18] + 58);  /* 0x8009EB64 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009EBCC; } }  /* 0x8009EB6C */
    { R[31] = 0x8009EB7Cu; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009EB74 jal */
    R[4] = R[16] + R[0];  /* 0x8009EB7C */
    { R[31] = 0x8009EB88u; R[5] = R[0] + 85; psx_next = 0x8009BC84u; return; }  /* 0x8009EB80 jal */
    R[4] = R[0] + 22;  /* 0x8009EB88 */
    R[2] = lw_(R[16] + 24);  /* 0x8009EB8C */
    R[3] = 0xFFCEu << 16;  /* 0x8009EB90 */
    sw_(R[29] + 16, R[2]);  /* 0x8009EB94 */
    R[2] = lw_(R[16] + 28);  /* 0x8009EB98 */
    R[5] = R[16] + R[0];  /* 0x8009EB9C */
    R[2] = R[2] + R[3];  /* 0x8009EBA0 */
    sw_(R[29] + 20, R[2]);  /* 0x8009EBA4 */
    R[2] = lw_(R[16] + 32);  /* 0x8009EBA8 */
    R[6] = R[29] + 16;  /* 0x8009EBAC */
    { R[31] = 0x8009EBB8u; sw_(R[29] + 24, R[2]); psx_next = 0x800AC93Cu; return; }  /* 0x8009EBB0 jal */
    { R[31] = 0x8009EBC0u; R[4] = R[0] + 16; psx_next = 0x800908F4u; return; }  /* 0x8009EBB8 jal */
    R[2] = R[2] << 5;  /* 0x8009EBC0 */
    { sh_(R[18] + 60, R[2]); goto L_8009EC24; }  /* 0x8009EBC4 j */
L_8009EBCC:;
    R[3] = lb_(R[18] + 30);  /* 0x8009EBCC */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC0C; } }  /* 0x8009EBD4 */
    { R[31] = 0x8009EBE4u; R[5] = R[0] + 93; psx_next = 0x8009BC84u; return; }  /* 0x8009EBDC jal */
    R[2] = lb_(R[16] + 781);  /* 0x8009EBE4 */
    R[2] = R[2] | 0x80;  /* 0x8009EBEC */
    { R[31] = 0x8009EBF8u; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009EBF0 jal */
    R[4] = R[16] + R[0];  /* 0x8009EBF8 */
    { R[31] = 0x8009EC04u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EBFC jal */
    { sb_(R[18] + 30, R[0]); goto L_8009EC24; }  /* 0x8009EC04 j */
L_8009EC0C:;
    { R[31] = 0x8009EC14u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009EC0C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC24; } }  /* 0x8009EC14 */
    { R[31] = 0x8009EC24u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EC1C jal */
L_8009EC24:;
    R[31] = lw_(R[29] + 44);  /* 0x8009EC24 */
    R[18] = lw_(R[29] + 40);  /* 0x8009EC28 */
    R[17] = lw_(R[29] + 36);  /* 0x8009EC2C */
    R[16] = lw_(R[29] + 32);  /* 0x8009EC30 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009EC34 jr ra */
}

void g0_8009EB7C(void) {
    R[4] = R[16] + R[0];  /* 0x8009EB7C */
    { R[31] = 0x8009EB88u; R[5] = R[0] + 85; psx_next = 0x8009BC84u; return; }  /* 0x8009EB80 jal */
    R[4] = R[0] + 22;  /* 0x8009EB88 */
    R[2] = lw_(R[16] + 24);  /* 0x8009EB8C */
    R[3] = 0xFFCEu << 16;  /* 0x8009EB90 */
    sw_(R[29] + 16, R[2]);  /* 0x8009EB94 */
    R[2] = lw_(R[16] + 28);  /* 0x8009EB98 */
    R[5] = R[16] + R[0];  /* 0x8009EB9C */
    R[2] = R[2] + R[3];  /* 0x8009EBA0 */
    sw_(R[29] + 20, R[2]);  /* 0x8009EBA4 */
    R[2] = lw_(R[16] + 32);  /* 0x8009EBA8 */
    R[6] = R[29] + 16;  /* 0x8009EBAC */
    { R[31] = 0x8009EBB8u; sw_(R[29] + 24, R[2]); psx_next = 0x800AC93Cu; return; }  /* 0x8009EBB0 jal */
    { R[31] = 0x8009EBC0u; R[4] = R[0] + 16; psx_next = 0x800908F4u; return; }  /* 0x8009EBB8 jal */
    R[2] = R[2] << 5;  /* 0x8009EBC0 */
    { sh_(R[18] + 60, R[2]); goto L_8009EC24; }  /* 0x8009EBC4 j */
    R[3] = lb_(R[18] + 30);  /* 0x8009EBCC */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC0C; } }  /* 0x8009EBD4 */
    { R[31] = 0x8009EBE4u; R[5] = R[0] + 93; psx_next = 0x8009BC84u; return; }  /* 0x8009EBDC jal */
    R[2] = lb_(R[16] + 781);  /* 0x8009EBE4 */
    R[2] = R[2] | 0x80;  /* 0x8009EBEC */
    { R[31] = 0x8009EBF8u; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009EBF0 jal */
    R[4] = R[16] + R[0];  /* 0x8009EBF8 */
    { R[31] = 0x8009EC04u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EBFC jal */
    { sb_(R[18] + 30, R[0]); goto L_8009EC24; }  /* 0x8009EC04 j */
L_8009EC0C:;
    { R[31] = 0x8009EC14u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009EC0C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC24; } }  /* 0x8009EC14 */
    { R[31] = 0x8009EC24u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EC1C jal */
L_8009EC24:;
    R[31] = lw_(R[29] + 44);  /* 0x8009EC24 */
    R[18] = lw_(R[29] + 40);  /* 0x8009EC28 */
    R[17] = lw_(R[29] + 36);  /* 0x8009EC2C */
    R[16] = lw_(R[29] + 32);  /* 0x8009EC30 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009EC34 jr ra */
}

void g0_8009EB88(void) {
    R[4] = R[0] + 22;  /* 0x8009EB88 */
    R[2] = lw_(R[16] + 24);  /* 0x8009EB8C */
    R[3] = 0xFFCEu << 16;  /* 0x8009EB90 */
    sw_(R[29] + 16, R[2]);  /* 0x8009EB94 */
    R[2] = lw_(R[16] + 28);  /* 0x8009EB98 */
    R[5] = R[16] + R[0];  /* 0x8009EB9C */
    R[2] = R[2] + R[3];  /* 0x8009EBA0 */
    sw_(R[29] + 20, R[2]);  /* 0x8009EBA4 */
    R[2] = lw_(R[16] + 32);  /* 0x8009EBA8 */
    R[6] = R[29] + 16;  /* 0x8009EBAC */
    { R[31] = 0x8009EBB8u; sw_(R[29] + 24, R[2]); psx_next = 0x800AC93Cu; return; }  /* 0x8009EBB0 jal */
    { R[31] = 0x8009EBC0u; R[4] = R[0] + 16; psx_next = 0x800908F4u; return; }  /* 0x8009EBB8 jal */
    R[2] = R[2] << 5;  /* 0x8009EBC0 */
    { sh_(R[18] + 60, R[2]); goto L_8009EC24; }  /* 0x8009EBC4 j */
    R[3] = lb_(R[18] + 30);  /* 0x8009EBCC */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC0C; } }  /* 0x8009EBD4 */
    { R[31] = 0x8009EBE4u; R[5] = R[0] + 93; psx_next = 0x8009BC84u; return; }  /* 0x8009EBDC jal */
    R[2] = lb_(R[16] + 781);  /* 0x8009EBE4 */
    R[2] = R[2] | 0x80;  /* 0x8009EBEC */
    { R[31] = 0x8009EBF8u; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009EBF0 jal */
    R[4] = R[16] + R[0];  /* 0x8009EBF8 */
    { R[31] = 0x8009EC04u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EBFC jal */
    { sb_(R[18] + 30, R[0]); goto L_8009EC24; }  /* 0x8009EC04 j */
L_8009EC0C:;
    { R[31] = 0x8009EC14u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009EC0C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC24; } }  /* 0x8009EC14 */
    { R[31] = 0x8009EC24u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EC1C jal */
L_8009EC24:;
    R[31] = lw_(R[29] + 44);  /* 0x8009EC24 */
    R[18] = lw_(R[29] + 40);  /* 0x8009EC28 */
    R[17] = lw_(R[29] + 36);  /* 0x8009EC2C */
    R[16] = lw_(R[29] + 32);  /* 0x8009EC30 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009EC34 jr ra */
}

void g0_8009EBB8(void) {
    { R[31] = 0x8009EBC0u; R[4] = R[0] + 16; psx_next = 0x800908F4u; return; }  /* 0x8009EBB8 jal */
    R[2] = R[2] << 5;  /* 0x8009EBC0 */
    { sh_(R[18] + 60, R[2]); goto L_8009EC24; }  /* 0x8009EBC4 j */
    R[3] = lb_(R[18] + 30);  /* 0x8009EBCC */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC0C; } }  /* 0x8009EBD4 */
    { R[31] = 0x8009EBE4u; R[5] = R[0] + 93; psx_next = 0x8009BC84u; return; }  /* 0x8009EBDC jal */
    R[2] = lb_(R[16] + 781);  /* 0x8009EBE4 */
    R[2] = R[2] | 0x80;  /* 0x8009EBEC */
    { R[31] = 0x8009EBF8u; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009EBF0 jal */
    R[4] = R[16] + R[0];  /* 0x8009EBF8 */
    { R[31] = 0x8009EC04u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EBFC jal */
    { sb_(R[18] + 30, R[0]); goto L_8009EC24; }  /* 0x8009EC04 j */
L_8009EC0C:;
    { R[31] = 0x8009EC14u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009EC0C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC24; } }  /* 0x8009EC14 */
    { R[31] = 0x8009EC24u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EC1C jal */
L_8009EC24:;
    R[31] = lw_(R[29] + 44);  /* 0x8009EC24 */
    R[18] = lw_(R[29] + 40);  /* 0x8009EC28 */
    R[17] = lw_(R[29] + 36);  /* 0x8009EC2C */
    R[16] = lw_(R[29] + 32);  /* 0x8009EC30 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009EC34 jr ra */
}

void g0_8009EBC0(void) {
    R[2] = R[2] << 5;  /* 0x8009EBC0 */
    { sh_(R[18] + 60, R[2]); goto L_8009EC24; }  /* 0x8009EBC4 j */
    R[3] = lb_(R[18] + 30);  /* 0x8009EBCC */
    { uint32_t _c = (R[3] != R[2]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC0C; } }  /* 0x8009EBD4 */
    { R[31] = 0x8009EBE4u; R[5] = R[0] + 93; psx_next = 0x8009BC84u; return; }  /* 0x8009EBDC jal */
    R[2] = lb_(R[16] + 781);  /* 0x8009EBE4 */
    R[2] = R[2] | 0x80;  /* 0x8009EBEC */
    { R[31] = 0x8009EBF8u; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009EBF0 jal */
    R[4] = R[16] + R[0];  /* 0x8009EBF8 */
    { R[31] = 0x8009EC04u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EBFC jal */
    { sb_(R[18] + 30, R[0]); goto L_8009EC24; }  /* 0x8009EC04 j */
L_8009EC0C:;
    { R[31] = 0x8009EC14u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009EC0C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC24; } }  /* 0x8009EC14 */
    { R[31] = 0x8009EC24u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EC1C jal */
L_8009EC24:;
    R[31] = lw_(R[29] + 44);  /* 0x8009EC24 */
    R[18] = lw_(R[29] + 40);  /* 0x8009EC28 */
    R[17] = lw_(R[29] + 36);  /* 0x8009EC2C */
    R[16] = lw_(R[29] + 32);  /* 0x8009EC30 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009EC34 jr ra */
}

void g0_8009EBE4(void) {
    R[2] = lb_(R[16] + 781);  /* 0x8009EBE4 */
    R[2] = R[2] | 0x80;  /* 0x8009EBEC */
    { R[31] = 0x8009EBF8u; sb_(R[16] + 781, R[2]); psx_next = 0x8009BCE8u; return; }  /* 0x8009EBF0 jal */
    R[4] = R[16] + R[0];  /* 0x8009EBF8 */
    { R[31] = 0x8009EC04u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EBFC jal */
    { sb_(R[18] + 30, R[0]); goto L_8009EC24; }  /* 0x8009EC04 j */
    { R[31] = 0x8009EC14u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009EC0C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC24; } }  /* 0x8009EC14 */
    { R[31] = 0x8009EC24u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EC1C jal */
L_8009EC24:;
    R[31] = lw_(R[29] + 44);  /* 0x8009EC24 */
    R[18] = lw_(R[29] + 40);  /* 0x8009EC28 */
    R[17] = lw_(R[29] + 36);  /* 0x8009EC2C */
    R[16] = lw_(R[29] + 32);  /* 0x8009EC30 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009EC34 jr ra */
}

void g0_8009EBF8(void) {
    R[4] = R[16] + R[0];  /* 0x8009EBF8 */
    { R[31] = 0x8009EC04u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EBFC jal */
    { sb_(R[18] + 30, R[0]); goto L_8009EC24; }  /* 0x8009EC04 j */
    { R[31] = 0x8009EC14u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009EC0C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC24; } }  /* 0x8009EC14 */
    { R[31] = 0x8009EC24u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EC1C jal */
L_8009EC24:;
    R[31] = lw_(R[29] + 44);  /* 0x8009EC24 */
    R[18] = lw_(R[29] + 40);  /* 0x8009EC28 */
    R[17] = lw_(R[29] + 36);  /* 0x8009EC2C */
    R[16] = lw_(R[29] + 32);  /* 0x8009EC30 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009EC34 jr ra */
}

void g0_8009EC04(void) {
    { sb_(R[18] + 30, R[0]); goto L_8009EC24; }  /* 0x8009EC04 j */
    { R[31] = 0x8009EC14u; R[4] = R[16] + R[0]; psx_next = 0x8009DD1Cu; return; }  /* 0x8009EC0C jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC24; } }  /* 0x8009EC14 */
    { R[31] = 0x8009EC24u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EC1C jal */
L_8009EC24:;
    R[31] = lw_(R[29] + 44);  /* 0x8009EC24 */
    R[18] = lw_(R[29] + 40);  /* 0x8009EC28 */
    R[17] = lw_(R[29] + 36);  /* 0x8009EC2C */
    R[16] = lw_(R[29] + 32);  /* 0x8009EC30 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009EC34 jr ra */
}

void g0_8009EC14(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009EC24; } }  /* 0x8009EC14 */
    { R[31] = 0x8009EC24u; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009EC1C jal */
L_8009EC24:;
    R[31] = lw_(R[29] + 44);  /* 0x8009EC24 */
    R[18] = lw_(R[29] + 40);  /* 0x8009EC28 */
    R[17] = lw_(R[29] + 36);  /* 0x8009EC2C */
    R[16] = lw_(R[29] + 32);  /* 0x8009EC30 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009EC34 jr ra */
}

void g0_8009EC24(void) {
    R[31] = lw_(R[29] + 44);  /* 0x8009EC24 */
    R[18] = lw_(R[29] + 40);  /* 0x8009EC28 */
    R[17] = lw_(R[29] + 36);  /* 0x8009EC2C */
    R[16] = lw_(R[29] + 32);  /* 0x8009EC30 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009EC34 jr ra */
}

void g0_8009EC3C(void) {
    R[29] = R[29] - 24;  /* 0x8009EC3C */
    sw_(R[29] + 16, R[16]);  /* 0x8009EC40 */
    sw_(R[29] + 20, R[31]);  /* 0x8009EC44 */
    psx_next = 0x8009EC48u; return;  /* fallthrough */
}

void g0_8009EC48(void) {
    { R[31] = 0x8009EC50u; R[16] = R[4] + R[0]; psx_next = 0x8009D8D0u; return; }  /* 0x8009EC48 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009ED30u; return; } }  /* 0x8009EC50 b extern */
    R[2] = lw_(R[16] + 72);  /* 0x8009EC58 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x8009EC60 */
    R[2] = R[0] + 1;  /* 0x8009EC64 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009EC84; } }  /* 0x8009EC68 */
    { R[31] = 0x8009EC78u; psx_next = 0x8009BCE8u; return; }  /* 0x8009EC70 jal */
    R[4] = R[16] + R[0];  /* 0x8009EC78 */
    { R[31] = 0x8009EC84u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EC7C jal */
L_8009EC84:;
    { R[31] = 0x8009EC8Cu; R[4] = R[16] + R[0]; psx_next = 0x8009E454u; return; }  /* 0x8009EC84 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009ED30u; return; } }  /* 0x8009EC8C b extern */
    R[2] = lb_(R[16] + 784);  /* 0x8009EC94 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009ECD0; } }  /* 0x8009EC9C */
    { R[31] = 0x8009ECACu; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009ECA4 jal */
    R[4] = R[16] + R[0];  /* 0x8009ECAC */
    R[5] = R[0] + 5;  /* 0x8009ECB0 */
    R[6] = R[0] + R[0];  /* 0x8009ECB4 */
    { R[31] = 0x8009ECC0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009ECB8 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009ECFCu; return; } }  /* 0x8009ECC0 b extern */
    { psx_next = 0x8009ED30u; return; }  /* 0x8009ECC8 j extern */
L_8009ECD0:;
    R[5] = R[0] - 1;  /* 0x8009ECD0 */
    R[6] = R[5] + R[0];  /* 0x8009ECD4 */
    { R[31] = 0x8009ECE0u; R[7] = R[0] + R[0]; psx_next = 0x8009D0B0u; return; }  /* 0x8009ECD8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { psx_next = 0x8009ECF0u; return; } }  /* 0x8009ECE0 b extern */
    psx_next = 0x8009ECE8u; return;  /* fallthrough */
}

void g0_8009EC50(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009ED30u; return; } }  /* 0x8009EC50 b extern */
    R[2] = lw_(R[16] + 72);  /* 0x8009EC58 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 4);  /* 0x8009EC60 */
    R[2] = R[0] + 1;  /* 0x8009EC64 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009EC84; } }  /* 0x8009EC68 */
    { R[31] = 0x8009EC78u; psx_next = 0x8009BCE8u; return; }  /* 0x8009EC70 jal */
    R[4] = R[16] + R[0];  /* 0x8009EC78 */
    { R[31] = 0x8009EC84u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EC7C jal */
L_8009EC84:;
    { R[31] = 0x8009EC8Cu; R[4] = R[16] + R[0]; psx_next = 0x8009E454u; return; }  /* 0x8009EC84 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009ED30u; return; } }  /* 0x8009EC8C b extern */
    R[2] = lb_(R[16] + 784);  /* 0x8009EC94 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009ECD0; } }  /* 0x8009EC9C */
    { R[31] = 0x8009ECACu; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009ECA4 jal */
    R[4] = R[16] + R[0];  /* 0x8009ECAC */
    R[5] = R[0] + 5;  /* 0x8009ECB0 */
    R[6] = R[0] + R[0];  /* 0x8009ECB4 */
    { R[31] = 0x8009ECC0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009ECB8 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009ECFCu; return; } }  /* 0x8009ECC0 b extern */
    { psx_next = 0x8009ED30u; return; }  /* 0x8009ECC8 j extern */
L_8009ECD0:;
    R[5] = R[0] - 1;  /* 0x8009ECD0 */
    R[6] = R[5] + R[0];  /* 0x8009ECD4 */
    { R[31] = 0x8009ECE0u; R[7] = R[0] + R[0]; psx_next = 0x8009D0B0u; return; }  /* 0x8009ECD8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { psx_next = 0x8009ECF0u; return; } }  /* 0x8009ECE0 b extern */
    psx_next = 0x8009ECE8u; return;  /* fallthrough */
}

void g0_8009EC78(void) {
    R[4] = R[16] + R[0];  /* 0x8009EC78 */
    { R[31] = 0x8009EC84u; R[5] = R[2] + R[0]; psx_next = 0x800A9E2Cu; return; }  /* 0x8009EC7C jal */
    { R[31] = 0x8009EC8Cu; R[4] = R[16] + R[0]; psx_next = 0x8009E454u; return; }  /* 0x8009EC84 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009ED30u; return; } }  /* 0x8009EC8C b extern */
    R[2] = lb_(R[16] + 784);  /* 0x8009EC94 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009ECD0; } }  /* 0x8009EC9C */
    { R[31] = 0x8009ECACu; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009ECA4 jal */
    R[4] = R[16] + R[0];  /* 0x8009ECAC */
    R[5] = R[0] + 5;  /* 0x8009ECB0 */
    R[6] = R[0] + R[0];  /* 0x8009ECB4 */
    { R[31] = 0x8009ECC0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009ECB8 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009ECFCu; return; } }  /* 0x8009ECC0 b extern */
    { psx_next = 0x8009ED30u; return; }  /* 0x8009ECC8 j extern */
L_8009ECD0:;
    R[5] = R[0] - 1;  /* 0x8009ECD0 */
    R[6] = R[5] + R[0];  /* 0x8009ECD4 */
    { R[31] = 0x8009ECE0u; R[7] = R[0] + R[0]; psx_next = 0x8009D0B0u; return; }  /* 0x8009ECD8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { psx_next = 0x8009ECF0u; return; } }  /* 0x8009ECE0 b extern */
    psx_next = 0x8009ECE8u; return;  /* fallthrough */
}

void g0_8009EC84(void) {
    { R[31] = 0x8009EC8Cu; R[4] = R[16] + R[0]; psx_next = 0x8009E454u; return; }  /* 0x8009EC84 jal */
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009ED30u; return; } }  /* 0x8009EC8C b extern */
    R[2] = lb_(R[16] + 784);  /* 0x8009EC94 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009ECD0; } }  /* 0x8009EC9C */
    { R[31] = 0x8009ECACu; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009ECA4 jal */
    R[4] = R[16] + R[0];  /* 0x8009ECAC */
    R[5] = R[0] + 5;  /* 0x8009ECB0 */
    R[6] = R[0] + R[0];  /* 0x8009ECB4 */
    { R[31] = 0x8009ECC0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009ECB8 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009ECFCu; return; } }  /* 0x8009ECC0 b extern */
    { psx_next = 0x8009ED30u; return; }  /* 0x8009ECC8 j extern */
L_8009ECD0:;
    R[5] = R[0] - 1;  /* 0x8009ECD0 */
    R[6] = R[5] + R[0];  /* 0x8009ECD4 */
    { R[31] = 0x8009ECE0u; R[7] = R[0] + R[0]; psx_next = 0x8009D0B0u; return; }  /* 0x8009ECD8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { psx_next = 0x8009ECF0u; return; } }  /* 0x8009ECE0 b extern */
    psx_next = 0x8009ECE8u; return;  /* fallthrough */
}

void g0_8009EC8C(void) {
    { uint32_t _c = (R[2] != R[0]); if (_c) { psx_next = 0x8009ED30u; return; } }  /* 0x8009EC8C b extern */
    R[2] = lb_(R[16] + 784);  /* 0x8009EC94 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009ECD0; } }  /* 0x8009EC9C */
    { R[31] = 0x8009ECACu; R[4] = R[16] + R[0]; psx_next = 0x800A9EB4u; return; }  /* 0x8009ECA4 jal */
    R[4] = R[16] + R[0];  /* 0x8009ECAC */
    R[5] = R[0] + 5;  /* 0x8009ECB0 */
    R[6] = R[0] + R[0];  /* 0x8009ECB4 */
    { R[31] = 0x8009ECC0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009ECB8 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009ECFCu; return; } }  /* 0x8009ECC0 b extern */
    { psx_next = 0x8009ED30u; return; }  /* 0x8009ECC8 j extern */
L_8009ECD0:;
    R[5] = R[0] - 1;  /* 0x8009ECD0 */
    R[6] = R[5] + R[0];  /* 0x8009ECD4 */
    { R[31] = 0x8009ECE0u; R[7] = R[0] + R[0]; psx_next = 0x8009D0B0u; return; }  /* 0x8009ECD8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { psx_next = 0x8009ECF0u; return; } }  /* 0x8009ECE0 b extern */
    psx_next = 0x8009ECE8u; return;  /* fallthrough */
}

void g0_8009ECAC(void) {
    R[4] = R[16] + R[0];  /* 0x8009ECAC */
    R[5] = R[0] + 5;  /* 0x8009ECB0 */
    R[6] = R[0] + R[0];  /* 0x8009ECB4 */
    { R[31] = 0x8009ECC0u; R[7] = R[0] + 1; psx_next = 0x8009D0B0u; return; }  /* 0x8009ECB8 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009ECFCu; return; } }  /* 0x8009ECC0 b extern */
    { psx_next = 0x8009ED30u; return; }  /* 0x8009ECC8 j extern */
    R[5] = R[0] - 1;  /* 0x8009ECD0 */
    R[6] = R[5] + R[0];  /* 0x8009ECD4 */
    { R[31] = 0x8009ECE0u; R[7] = R[0] + R[0]; psx_next = 0x8009D0B0u; return; }  /* 0x8009ECD8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { psx_next = 0x8009ECF0u; return; } }  /* 0x8009ECE0 b extern */
    psx_next = 0x8009ECE8u; return;  /* fallthrough */
}

void g0_8009ECC0(void) {
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009ECFCu; return; } }  /* 0x8009ECC0 b extern */
    { psx_next = 0x8009ED30u; return; }  /* 0x8009ECC8 j extern */
    R[5] = R[0] - 1;  /* 0x8009ECD0 */
    R[6] = R[5] + R[0];  /* 0x8009ECD4 */
    { R[31] = 0x8009ECE0u; R[7] = R[0] + R[0]; psx_next = 0x8009D0B0u; return; }  /* 0x8009ECD8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { psx_next = 0x8009ECF0u; return; } }  /* 0x8009ECE0 b extern */
    psx_next = 0x8009ECE8u; return;  /* fallthrough */
}

void g0_8009ECE0(void) {
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8001u << 16; if (_c) { psx_next = 0x8009ECF0u; return; } }  /* 0x8009ECE0 b extern */
    psx_next = 0x8009ECE8u; return;  /* fallthrough */
}

void g0_8009ECE4(void) {
    R[2] = 0x8001u << 16;  /* 0x8009ECE4 */
    { sw_(R[16] + 124, R[0]); psx_next = 0x8009ECFCu; return; }  /* 0x8009ECE8 j extern */
}

void g0_8009ECE8(void) {
    { sw_(R[16] + 124, R[0]); psx_next = 0x8009ECFCu; return; }  /* 0x8009ECE8 j extern */
}

void g0_8009ECEC(void) {
    sw_(R[16] + 124, R[0]);  /* 0x8009ECEC */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x8009ECF0 */
    sw_(R[16] + 124, R[2]);  /* 0x8009ECF8 */
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

void g0_8009ECF0(void) {
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 29320);  /* 0x8009ECF0 */
    sw_(R[16] + 124, R[2]);  /* 0x8009ECF8 */
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
