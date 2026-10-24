#include "game00_decls.h"

void g0_8009BA38(void) {
    R[3] = lw_(R[22] + 284);  /* 0x8009BA38 */
    R[4] = lw_(R[22] + 280);  /* 0x8009BA3C */
    R[19] = R[2] + R[0];  /* 0x8009BA40 */
    sw_(R[20] + 20, R[16]);  /* 0x8009BA44 */
    R[3] = R[3] - R[4];  /* 0x8009BA48 */
    R[3] = R[18] + R[3];  /* 0x8009BA4C */
    R[3] = R[3] + R[17];  /* 0x8009BA50 */
    { sw_(R[20] + 24, R[3]); goto L_8009BB04; }  /* 0x8009BA54 j */
    R[17] = 0x8016u << 16;  /* 0x8009BA5C */
    R[17] = R[17] | 0x7800;  /* 0x8009BA60 */
    R[16] = R[18] + R[17];  /* 0x8009BA64 */
    R[4] = R[16] + R[0];  /* 0x8009BA68 */
    R[5] = R[0] + 72;  /* 0x8009BA6C */
    R[6] = R[0] + 73;  /* 0x8009BA70 */
    R[7] = 0x4u << 16;  /* 0x8009BA74 */
    R[7] = R[7] | 0x3800;  /* 0x8009BA78 */
    { R[31] = 0x8009BA84u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x8009BA7C jal */
    R[19] = R[2] + R[0];  /* 0x8009BA84 */
    R[21] = 0x3u << 16;  /* 0x8009BA88 */
    R[21] = R[21] | 0x4800;  /* 0x8009BA8C */
    R[2] = lw_(R[22] + 292);  /* 0x8009BA90 */
    R[3] = lw_(R[22] + 288);  /* 0x8009BA94 */
    { R[4] = 0x8006u << 16; goto L_8009BAE0; }  /* 0x8009BA98 j */
    R[17] = 0x8016u << 16;  /* 0x8009BAA0 */
    R[17] = R[17] | 0x7800;  /* 0x8009BAA4 */
    R[16] = R[18] + R[17];  /* 0x8009BAA8 */
    R[4] = R[16] + R[0];  /* 0x8009BAAC */
    R[5] = R[0] + 74;  /* 0x8009BAB0 */
    R[6] = R[0] + 75;  /* 0x8009BAB4 */
    R[7] = 0x4u << 16;  /* 0x8009BAB8 */
    R[7] = R[7] | 0x3800;  /* 0x8009BABC */
    { R[31] = 0x8009BAC8u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x8009BAC0 jal */
    R[19] = R[2] + R[0];  /* 0x8009BAC8 */
    R[21] = 0x3u << 16;  /* 0x8009BACC */
    R[21] = R[21] | 0x4800;  /* 0x8009BAD0 */
    R[4] = 0x8006u << 16;  /* 0x8009BAD4 */
    R[2] = lw_(R[22] + 276);  /* 0x8009BAD8 */
    R[3] = lw_(R[22] + 272);  /* 0x8009BADC */
L_8009BAE0:;
    R[4] = R[4] + 13192;  /* 0x8009BAE0 */
    sw_(R[20] + 20, R[16]);  /* 0x8009BAE4 */
    R[2] = R[2] - R[3];  /* 0x8009BAE8 */
    R[2] = R[18] + R[2];  /* 0x8009BAEC */
    R[3] = lh_(R[4] + 2912);  /* 0x8009BAF0 */
    R[2] = R[2] + R[17];  /* 0x8009BAF4 */
    sw_(R[20] + 24, R[2]);  /* 0x8009BAF8 */
    R[3] = R[3] & 0xFFFE;  /* 0x8009BAFC */
    sh_(R[4] + 2912, R[3]);  /* 0x8009BB00 */
L_8009BB04:;
    R[5] = 0x8005u << 16;  /* 0x8009BB04 */
    R[5] = R[5] - 908;  /* 0x8009BB08 */
    R[6] = 0x8005u << 16;  /* 0x8009BB0C */
    R[6] = R[6] - 888;  /* 0x8009BB10 */
    R[17] = 0x8013u << 16;  /* 0x8009BB14 */
    R[16] = R[17] - 29480;  /* 0x8009BB18 */
    R[4] = lw_(R[16] + 20);  /* 0x8009BB1C */
    R[7] = R[0] + R[0];  /* 0x8009BB20 */
    { R[31] = 0x8009BB2Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8002492Cu; return; }  /* 0x8009BB24 jal */
    R[4] = lw_(R[16] + 24);  /* 0x8009BB2C */
    { R[31] = 0x8009BB38u; psx_next = 0x80024F10u; return; }  /* 0x8009BB30 jal */
    R[2] = lh_(R[17] + -29480);  /* 0x8009BB38 */
    sh_(R[16] + 2, R[2]);  /* 0x8009BB40 */
    R[2] = R[18] + R[19];  /* 0x8009BB44 */
    R[2] = ((int32_t)R[21] < (int32_t)R[2]);  /* 0x8009BB48 */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8008u << 16; if (_c) { goto L_8009BB64; } }  /* 0x8009BB4C */
    { R[31] = 0x8009BB5Cu; R[4] = R[4] + 8548; psx_next = 0x8001BBF8u; return; }  /* 0x8009BB54 jal */
    { R[31] = 0x8009BB64u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8009BB5C jal */
L_8009BB64:;
    R[31] = lw_(R[29] + 56);  /* 0x8009BB64 */
    R[23] = lw_(R[29] + 52);  /* 0x8009BB68 */
    R[22] = lw_(R[29] + 48);  /* 0x8009BB6C */
    R[21] = lw_(R[29] + 44);  /* 0x8009BB70 */
    R[20] = lw_(R[29] + 40);  /* 0x8009BB74 */
    R[19] = lw_(R[29] + 36);  /* 0x8009BB78 */
    R[18] = lw_(R[29] + 32);  /* 0x8009BB7C */
    R[17] = lw_(R[29] + 28);  /* 0x8009BB80 */
    R[16] = lw_(R[29] + 24);  /* 0x8009BB84 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8009BB88 jr ra */
}

void g0_8009BA84(void) {
    R[19] = R[2] + R[0];  /* 0x8009BA84 */
    R[21] = 0x3u << 16;  /* 0x8009BA88 */
    R[21] = R[21] | 0x4800;  /* 0x8009BA8C */
    R[2] = lw_(R[22] + 292);  /* 0x8009BA90 */
    R[3] = lw_(R[22] + 288);  /* 0x8009BA94 */
    { R[4] = 0x8006u << 16; goto L_8009BAE0; }  /* 0x8009BA98 j */
    R[17] = 0x8016u << 16;  /* 0x8009BAA0 */
    R[17] = R[17] | 0x7800;  /* 0x8009BAA4 */
    R[16] = R[18] + R[17];  /* 0x8009BAA8 */
    R[4] = R[16] + R[0];  /* 0x8009BAAC */
    R[5] = R[0] + 74;  /* 0x8009BAB0 */
    R[6] = R[0] + 75;  /* 0x8009BAB4 */
    R[7] = 0x4u << 16;  /* 0x8009BAB8 */
    R[7] = R[7] | 0x3800;  /* 0x8009BABC */
    { R[31] = 0x8009BAC8u; sw_(R[29] + 16, R[0]); psx_next = 0x8001BD40u; return; }  /* 0x8009BAC0 jal */
    R[19] = R[2] + R[0];  /* 0x8009BAC8 */
    R[21] = 0x3u << 16;  /* 0x8009BACC */
    R[21] = R[21] | 0x4800;  /* 0x8009BAD0 */
    R[4] = 0x8006u << 16;  /* 0x8009BAD4 */
    R[2] = lw_(R[22] + 276);  /* 0x8009BAD8 */
    R[3] = lw_(R[22] + 272);  /* 0x8009BADC */
L_8009BAE0:;
    R[4] = R[4] + 13192;  /* 0x8009BAE0 */
    sw_(R[20] + 20, R[16]);  /* 0x8009BAE4 */
    R[2] = R[2] - R[3];  /* 0x8009BAE8 */
    R[2] = R[18] + R[2];  /* 0x8009BAEC */
    R[3] = lh_(R[4] + 2912);  /* 0x8009BAF0 */
    R[2] = R[2] + R[17];  /* 0x8009BAF4 */
    sw_(R[20] + 24, R[2]);  /* 0x8009BAF8 */
    R[3] = R[3] & 0xFFFE;  /* 0x8009BAFC */
    sh_(R[4] + 2912, R[3]);  /* 0x8009BB00 */
    R[5] = 0x8005u << 16;  /* 0x8009BB04 */
    R[5] = R[5] - 908;  /* 0x8009BB08 */
    R[6] = 0x8005u << 16;  /* 0x8009BB0C */
    R[6] = R[6] - 888;  /* 0x8009BB10 */
    R[17] = 0x8013u << 16;  /* 0x8009BB14 */
    R[16] = R[17] - 29480;  /* 0x8009BB18 */
    R[4] = lw_(R[16] + 20);  /* 0x8009BB1C */
    R[7] = R[0] + R[0];  /* 0x8009BB20 */
    { R[31] = 0x8009BB2Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8002492Cu; return; }  /* 0x8009BB24 jal */
    R[4] = lw_(R[16] + 24);  /* 0x8009BB2C */
    { R[31] = 0x8009BB38u; psx_next = 0x80024F10u; return; }  /* 0x8009BB30 jal */
    R[2] = lh_(R[17] + -29480);  /* 0x8009BB38 */
    sh_(R[16] + 2, R[2]);  /* 0x8009BB40 */
    R[2] = R[18] + R[19];  /* 0x8009BB44 */
    R[2] = ((int32_t)R[21] < (int32_t)R[2]);  /* 0x8009BB48 */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8008u << 16; if (_c) { goto L_8009BB64; } }  /* 0x8009BB4C */
    { R[31] = 0x8009BB5Cu; R[4] = R[4] + 8548; psx_next = 0x8001BBF8u; return; }  /* 0x8009BB54 jal */
    { R[31] = 0x8009BB64u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8009BB5C jal */
L_8009BB64:;
    R[31] = lw_(R[29] + 56);  /* 0x8009BB64 */
    R[23] = lw_(R[29] + 52);  /* 0x8009BB68 */
    R[22] = lw_(R[29] + 48);  /* 0x8009BB6C */
    R[21] = lw_(R[29] + 44);  /* 0x8009BB70 */
    R[20] = lw_(R[29] + 40);  /* 0x8009BB74 */
    R[19] = lw_(R[29] + 36);  /* 0x8009BB78 */
    R[18] = lw_(R[29] + 32);  /* 0x8009BB7C */
    R[17] = lw_(R[29] + 28);  /* 0x8009BB80 */
    R[16] = lw_(R[29] + 24);  /* 0x8009BB84 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8009BB88 jr ra */
}

void g0_8009BAC8(void) {
    R[19] = R[2] + R[0];  /* 0x8009BAC8 */
    R[21] = 0x3u << 16;  /* 0x8009BACC */
    R[21] = R[21] | 0x4800;  /* 0x8009BAD0 */
    R[4] = 0x8006u << 16;  /* 0x8009BAD4 */
    R[2] = lw_(R[22] + 276);  /* 0x8009BAD8 */
    R[3] = lw_(R[22] + 272);  /* 0x8009BADC */
    R[4] = R[4] + 13192;  /* 0x8009BAE0 */
    sw_(R[20] + 20, R[16]);  /* 0x8009BAE4 */
    R[2] = R[2] - R[3];  /* 0x8009BAE8 */
    R[2] = R[18] + R[2];  /* 0x8009BAEC */
    R[3] = lh_(R[4] + 2912);  /* 0x8009BAF0 */
    R[2] = R[2] + R[17];  /* 0x8009BAF4 */
    sw_(R[20] + 24, R[2]);  /* 0x8009BAF8 */
    R[3] = R[3] & 0xFFFE;  /* 0x8009BAFC */
    sh_(R[4] + 2912, R[3]);  /* 0x8009BB00 */
    R[5] = 0x8005u << 16;  /* 0x8009BB04 */
    R[5] = R[5] - 908;  /* 0x8009BB08 */
    R[6] = 0x8005u << 16;  /* 0x8009BB0C */
    R[6] = R[6] - 888;  /* 0x8009BB10 */
    R[17] = 0x8013u << 16;  /* 0x8009BB14 */
    R[16] = R[17] - 29480;  /* 0x8009BB18 */
    R[4] = lw_(R[16] + 20);  /* 0x8009BB1C */
    R[7] = R[0] + R[0];  /* 0x8009BB20 */
    { R[31] = 0x8009BB2Cu; sw_(R[29] + 16, R[0]); psx_next = 0x8002492Cu; return; }  /* 0x8009BB24 jal */
    R[4] = lw_(R[16] + 24);  /* 0x8009BB2C */
    { R[31] = 0x8009BB38u; psx_next = 0x80024F10u; return; }  /* 0x8009BB30 jal */
    R[2] = lh_(R[17] + -29480);  /* 0x8009BB38 */
    sh_(R[16] + 2, R[2]);  /* 0x8009BB40 */
    R[2] = R[18] + R[19];  /* 0x8009BB44 */
    R[2] = ((int32_t)R[21] < (int32_t)R[2]);  /* 0x8009BB48 */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8008u << 16; if (_c) { goto L_8009BB64; } }  /* 0x8009BB4C */
    { R[31] = 0x8009BB5Cu; R[4] = R[4] + 8548; psx_next = 0x8001BBF8u; return; }  /* 0x8009BB54 jal */
    { R[31] = 0x8009BB64u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8009BB5C jal */
L_8009BB64:;
    R[31] = lw_(R[29] + 56);  /* 0x8009BB64 */
    R[23] = lw_(R[29] + 52);  /* 0x8009BB68 */
    R[22] = lw_(R[29] + 48);  /* 0x8009BB6C */
    R[21] = lw_(R[29] + 44);  /* 0x8009BB70 */
    R[20] = lw_(R[29] + 40);  /* 0x8009BB74 */
    R[19] = lw_(R[29] + 36);  /* 0x8009BB78 */
    R[18] = lw_(R[29] + 32);  /* 0x8009BB7C */
    R[17] = lw_(R[29] + 28);  /* 0x8009BB80 */
    R[16] = lw_(R[29] + 24);  /* 0x8009BB84 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8009BB88 jr ra */
}

void g0_8009BB2C(void) {
    R[4] = lw_(R[16] + 24);  /* 0x8009BB2C */
    { R[31] = 0x8009BB38u; psx_next = 0x80024F10u; return; }  /* 0x8009BB30 jal */
    R[2] = lh_(R[17] + -29480);  /* 0x8009BB38 */
    sh_(R[16] + 2, R[2]);  /* 0x8009BB40 */
    R[2] = R[18] + R[19];  /* 0x8009BB44 */
    R[2] = ((int32_t)R[21] < (int32_t)R[2]);  /* 0x8009BB48 */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8008u << 16; if (_c) { goto L_8009BB64; } }  /* 0x8009BB4C */
    { R[31] = 0x8009BB5Cu; R[4] = R[4] + 8548; psx_next = 0x8001BBF8u; return; }  /* 0x8009BB54 jal */
    { R[31] = 0x8009BB64u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8009BB5C jal */
L_8009BB64:;
    R[31] = lw_(R[29] + 56);  /* 0x8009BB64 */
    R[23] = lw_(R[29] + 52);  /* 0x8009BB68 */
    R[22] = lw_(R[29] + 48);  /* 0x8009BB6C */
    R[21] = lw_(R[29] + 44);  /* 0x8009BB70 */
    R[20] = lw_(R[29] + 40);  /* 0x8009BB74 */
    R[19] = lw_(R[29] + 36);  /* 0x8009BB78 */
    R[18] = lw_(R[29] + 32);  /* 0x8009BB7C */
    R[17] = lw_(R[29] + 28);  /* 0x8009BB80 */
    R[16] = lw_(R[29] + 24);  /* 0x8009BB84 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8009BB88 jr ra */
}

void g0_8009BB38(void) {
    R[2] = lh_(R[17] + -29480);  /* 0x8009BB38 */
    sh_(R[16] + 2, R[2]);  /* 0x8009BB40 */
    R[2] = R[18] + R[19];  /* 0x8009BB44 */
    R[2] = ((int32_t)R[21] < (int32_t)R[2]);  /* 0x8009BB48 */
    { uint32_t _c = (R[2] == R[0]); R[4] = 0x8008u << 16; if (_c) { goto L_8009BB64; } }  /* 0x8009BB4C */
    { R[31] = 0x8009BB5Cu; R[4] = R[4] + 8548; psx_next = 0x8001BBF8u; return; }  /* 0x8009BB54 jal */
    { R[31] = 0x8009BB64u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8009BB5C jal */
L_8009BB64:;
    R[31] = lw_(R[29] + 56);  /* 0x8009BB64 */
    R[23] = lw_(R[29] + 52);  /* 0x8009BB68 */
    R[22] = lw_(R[29] + 48);  /* 0x8009BB6C */
    R[21] = lw_(R[29] + 44);  /* 0x8009BB70 */
    R[20] = lw_(R[29] + 40);  /* 0x8009BB74 */
    R[19] = lw_(R[29] + 36);  /* 0x8009BB78 */
    R[18] = lw_(R[29] + 32);  /* 0x8009BB7C */
    R[17] = lw_(R[29] + 28);  /* 0x8009BB80 */
    R[16] = lw_(R[29] + 24);  /* 0x8009BB84 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8009BB88 jr ra */
}

void g0_8009BB5C(void) {
    { R[31] = 0x8009BB64u; R[4] = R[0] + 1; psx_next = 0x80032568u; return; }  /* 0x8009BB5C jal */
    R[31] = lw_(R[29] + 56);  /* 0x8009BB64 */
    R[23] = lw_(R[29] + 52);  /* 0x8009BB68 */
    R[22] = lw_(R[29] + 48);  /* 0x8009BB6C */
    R[21] = lw_(R[29] + 44);  /* 0x8009BB70 */
    R[20] = lw_(R[29] + 40);  /* 0x8009BB74 */
    R[19] = lw_(R[29] + 36);  /* 0x8009BB78 */
    R[18] = lw_(R[29] + 32);  /* 0x8009BB7C */
    R[17] = lw_(R[29] + 28);  /* 0x8009BB80 */
    R[16] = lw_(R[29] + 24);  /* 0x8009BB84 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8009BB88 jr ra */
}

void g0_8009BB64(void) {
    R[31] = lw_(R[29] + 56);  /* 0x8009BB64 */
    R[23] = lw_(R[29] + 52);  /* 0x8009BB68 */
    R[22] = lw_(R[29] + 48);  /* 0x8009BB6C */
    R[21] = lw_(R[29] + 44);  /* 0x8009BB70 */
    R[20] = lw_(R[29] + 40);  /* 0x8009BB74 */
    R[19] = lw_(R[29] + 36);  /* 0x8009BB78 */
    R[18] = lw_(R[29] + 32);  /* 0x8009BB7C */
    R[17] = lw_(R[29] + 28);  /* 0x8009BB80 */
    R[16] = lw_(R[29] + 24);  /* 0x8009BB84 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8009BB88 jr ra */
}

void g0_8009BB90(void) {
    R[2] = ((int32_t)R[4] < 200);  /* 0x8009BB90 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[4] - 41; if (_c) { goto L_8009BBA4; } }  /* 0x8009BB94 */
    R[4] = R[4] - 200;  /* 0x8009BB9C */
    R[3] = R[4] - 41;  /* 0x8009BBA0 */
L_8009BBA4:;
    R[2] = (R[3] < (uint32_t)41u);  /* 0x8009BBA4 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[4] - 82; if (_c) { goto L_8009BBB8; } }  /* 0x8009BBA8 */
    R[4] = R[3] + R[0];  /* 0x8009BBB0 */
    R[2] = R[4] - 82;  /* 0x8009BBB4 */
L_8009BBB8:;
    R[2] = (R[2] < (uint32_t)118u);  /* 0x8009BBB8 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[4] << 16; if (_c) { goto L_8009BC00; } }  /* 0x8009BBBC */
    R[2] = 0x8006u << 16;  /* 0x8009BBC4 */
    R[2] = lh_(R[2] + 16104);  /* 0x8009BBC8 */
    R[2] = R[2] & 0x1;  /* 0x8009BBD0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[4] << 16; if (_c) { goto L_8009BC00; } }  /* 0x8009BBD4 */
    R[2] = 0x8013u << 16;  /* 0x8009BBDC */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + -29480);  /* 0x8009BBE0 */
    R[2] = R[0] + 1;  /* 0x8009BBE4 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009BBF8; } }  /* 0x8009BBE8 */
    { R[4] = R[4] + 200; goto L_8009BBFC; }  /* 0x8009BBF0 j */
L_8009BBF8:;
    R[4] = R[4] + 41;  /* 0x8009BBF8 */
L_8009BBFC:;
    R[2] = R[4] << 16;  /* 0x8009BBFC */
L_8009BC00:;
    { R[2] = (uint32_t)((int32_t)R[2] >> 16); psx_next = R[31]; return; }  /* 0x8009BC00 jr ra */
}

void g0_8009BC08(void) {
    R[29] = R[29] - 24;  /* 0x8009BC08 */
    sw_(R[29] + 16, R[16]);  /* 0x8009BC0C */
    R[16] = R[4] + R[0];  /* 0x8009BC10 */
    sw_(R[29] + 20, R[31]);  /* 0x8009BC14 */
    { R[31] = 0x8009BC20u; R[4] = R[5] + R[0]; psx_next = 0x8009BB90u; return; }  /* 0x8009BC18 jal */
    R[2] = R[2] << 16;  /* 0x8009BC20 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009BC24 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 22);  /* 0x8009BC28 */
    R[31] = lw_(R[29] + 20);  /* 0x8009BC2C */
    R[16] = lw_(R[29] + 16);  /* 0x8009BC30 */
    R[2] = R[2] ^ R[3];  /* 0x8009BC34 */
    R[2] = (R[2] < (uint32_t)1u);  /* 0x8009BC38 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009BC3C jr ra */
}

void g0_8009BC20(void) {
    R[2] = R[2] << 16;  /* 0x8009BC20 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009BC24 */
    R[3] = (uint32_t)(int16_t)lh_(R[16] + 22);  /* 0x8009BC28 */
    R[31] = lw_(R[29] + 20);  /* 0x8009BC2C */
    R[16] = lw_(R[29] + 16);  /* 0x8009BC30 */
    R[2] = R[2] ^ R[3];  /* 0x8009BC34 */
    R[2] = (R[2] < (uint32_t)1u);  /* 0x8009BC38 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009BC3C jr ra */
}

void g0_8009BC44(void) {
    R[29] = R[29] - 24;  /* 0x8009BC44 */
    R[2] = 0x8012u << 16;  /* 0x8009BC48 */
    R[2] = R[2] - 26864;  /* 0x8009BC4C */
    { uint32_t _c = (R[4] == R[2]); sw_(R[29] + 16, R[31]); if (_c) { goto L_8009BC6C; } }  /* 0x8009BC50 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 22);  /* 0x8009BC58 */
    R[2] = R[2] ^ R[5];  /* 0x8009BC60 */
    { R[2] = (R[2] < (uint32_t)1u); goto L_8009BC74; }  /* 0x8009BC64 j */
L_8009BC6C:;
    { R[31] = 0x8009BC74u; psx_next = 0x8009BC08u; return; }  /* 0x8009BC6C jal */
L_8009BC74:;
    R[31] = lw_(R[29] + 16);  /* 0x8009BC74 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009BC7C jr ra */
}

void g0_8009BC74(void) {
    R[31] = lw_(R[29] + 16);  /* 0x8009BC74 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009BC7C jr ra */
}

void g0_8009BC84(void) {
    R[29] = R[29] - 24;  /* 0x8009BC84 */
    sw_(R[29] + 16, R[16]);  /* 0x8009BC88 */
    R[16] = R[4] + R[0];  /* 0x8009BC8C */
    sw_(R[29] + 20, R[31]);  /* 0x8009BC90 */
    { R[31] = 0x8009BC9Cu; R[4] = R[5] + R[0]; psx_next = 0x8009BB90u; return; }  /* 0x8009BC94 jal */
    sh_(R[16] + 20, R[2]);  /* 0x8009BC9C */
    R[31] = lw_(R[29] + 20);  /* 0x8009BCA0 */
    psx_next = 0x8009BCA4u; return;  /* fallthrough */
}

void g0_8009BC9C(void) {
    sh_(R[16] + 20, R[2]);  /* 0x8009BC9C */
    R[31] = lw_(R[29] + 20);  /* 0x8009BCA0 */
    psx_next = 0x8009BCA4u; return;  /* fallthrough */
}

void g0_8009BCA4(void) {
    R[16] = lw_(R[29] + 16);  /* 0x8009BCA4 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009BCA8 jr ra */
}

void g0_8009BCB0(void) {
    R[29] = R[29] - 24;  /* 0x8009BCB0 */
    R[2] = 0x8012u << 16;  /* 0x8009BCB4 */
    R[2] = R[2] - 26864;  /* 0x8009BCB8 */
    { uint32_t _c = (R[4] != R[2]); sw_(R[29] + 16, R[31]); if (_c) { goto L_8009BCD4; } }  /* 0x8009BCBC */
    { R[31] = 0x8009BCCCu; psx_next = 0x8009BC84u; return; }  /* 0x8009BCC4 jal */
    { goto L_8009BCD8; }  /* 0x8009BCCC j */
L_8009BCD4:;
    sh_(R[4] + 20, R[5]);  /* 0x8009BCD4 */
L_8009BCD8:;
    R[31] = lw_(R[29] + 16);  /* 0x8009BCD8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009BCE0 jr ra */
}

void g0_8009BCCC(void) {
    { goto L_8009BCD8; }  /* 0x8009BCCC j */
    sh_(R[4] + 20, R[5]);  /* 0x8009BCD4 */
L_8009BCD8:;
    R[31] = lw_(R[29] + 16);  /* 0x8009BCD8 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009BCE0 jr ra */
}

void g0_8009BCE8(void) {
    R[29] = R[29] - 24;  /* 0x8009BCE8 */
    sw_(R[29] + 16, R[31]);  /* 0x8009BCEC */
    { R[31] = 0x8009BCF8u; psx_next = 0x80023E64u; return; }  /* 0x8009BCF0 jal */
    R[31] = lw_(R[29] + 16);  /* 0x8009BCF8 */
    R[2] = R[2] + 1;  /* 0x8009BCFC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009BD00 jr ra */
}

void g0_8009BCF8(void) {
    R[31] = lw_(R[29] + 16);  /* 0x8009BCF8 */
    R[2] = R[2] + 1;  /* 0x8009BCFC */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009BD00 jr ra */
}

void g0_8009BD08(void) {
    R[29] = R[29] - 40;  /* 0x8009BD08 */
    sw_(R[29] + 32, R[31]);  /* 0x8009BD0C */
    R[2] = R[5] - 1;  /* 0x8009BD10 */
    R[2] = (R[2] < (uint32_t)3u);  /* 0x8009BD14 */
    { uint32_t _c = (R[2] == R[0]); R[6] = R[4] + R[0]; if (_c) { psx_next = 0x8009BD64u; return; } }  /* 0x8009BD18 b extern */
    psx_next = 0x8009BD20u; return;  /* fallthrough */
}

void g0_8009BD1C(void) {
    R[6] = R[4] + R[0];  /* 0x8009BD1C */
    R[2] = 0x8013u << 16;  /* 0x8009BD20 */
    R[2] = R[2] - 29656;  /* 0x8009BD24 */
    R[3] = R[0] + 60;  /* 0x8009BD28 */
    sh_(R[2] + 62, R[3]);  /* 0x8009BD2C */
    R[3] = 0xFFCEu << 16;  /* 0x8009BD30 */
    sh_(R[2] + 64, R[5]);  /* 0x8009BD34 */
    R[2] = lw_(R[6] + 24);  /* 0x8009BD38 */
    R[4] = R[0] + 27;  /* 0x8009BD3C */
    sw_(R[29] + 16, R[2]);  /* 0x8009BD40 */
    R[2] = lw_(R[6] + 28);  /* 0x8009BD44 */
    R[5] = R[6] + R[0];  /* 0x8009BD48 */
    R[2] = R[2] + R[3];  /* 0x8009BD4C */
    psx_next = 0x8009BD50u; return;  /* fallthrough */
}

void g0_8009BD20(void) {
    R[2] = 0x8013u << 16;  /* 0x8009BD20 */
    R[2] = R[2] - 29656;  /* 0x8009BD24 */
    R[3] = R[0] + 60;  /* 0x8009BD28 */
    sh_(R[2] + 62, R[3]);  /* 0x8009BD2C */
    R[3] = 0xFFCEu << 16;  /* 0x8009BD30 */
    sh_(R[2] + 64, R[5]);  /* 0x8009BD34 */
    R[2] = lw_(R[6] + 24);  /* 0x8009BD38 */
    R[4] = R[0] + 27;  /* 0x8009BD3C */
    sw_(R[29] + 16, R[2]);  /* 0x8009BD40 */
    R[2] = lw_(R[6] + 28);  /* 0x8009BD44 */
    R[5] = R[6] + R[0];  /* 0x8009BD48 */
    R[2] = R[2] + R[3];  /* 0x8009BD4C */
    psx_next = 0x8009BD50u; return;  /* fallthrough */
}

void g0_8009BD50(void) {
    sw_(R[29] + 20, R[2]);  /* 0x8009BD50 */
    R[2] = lw_(R[6] + 32);  /* 0x8009BD54 */
    R[6] = R[29] + 16;  /* 0x8009BD58 */
    { R[31] = 0x8009BD64u; sw_(R[29] + 24, R[2]); psx_next = 0x800AC93Cu; return; }  /* 0x8009BD5C jal */
    R[31] = lw_(R[29] + 32);  /* 0x8009BD64 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009BD6C jr ra */
}

void g0_8009BD64(void) {
    R[31] = lw_(R[29] + 32);  /* 0x8009BD64 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009BD6C jr ra */
}

void g0_8009BD74(void) {
    { uint32_t _c = (R[6] != R[0]); R[7] = R[4] + R[0]; if (_c) { psx_next = 0x8009BE1Cu; return; } }  /* 0x8009BD74 b extern */
    R[3] = lb_(R[5] + 781);  /* 0x8009BD7C */
    R[2] = R[0] - 1;  /* 0x8009BD80 */
    sb_(R[5] + 499, R[2]);  /* 0x8009BD84 */
    R[2] = R[0] + 114;  /* 0x8009BD88 */
    sh_(R[5] + 20, R[2]);  /* 0x8009BD8C */
    R[2] = lw_(R[5] + 24);  /* 0x8009BD90 */
    sb_(R[5] + 784, R[0]);  /* 0x8009BD94 */
    sw_(R[5] + 140, R[0]);  /* 0x8009BD98 */
    sw_(R[5] + 124, R[0]);  /* 0x8009BD9C */
    R[3] = R[3] | 0x80;  /* 0x8009BDA0 */
    sb_(R[5] + 781, R[3]);  /* 0x8009BDA4 */
    R[3] = lw_(R[7] + 24);  /* 0x8009BDA8 */
    R[3] = R[3] - R[2];  /* 0x8009BDB0 */
    psx_next = 0x8009BDB4u; return;  /* fallthrough */
}

void g0_8009BDB4(void) {
    R[2] = 0x8013u << 16;  /* 0x8009BDB4 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[6] = R[2] - 29656; if (_c) { goto L_8009BDC4; } }  /* 0x8009BDB8 */
    R[3] = R[3] + 3;  /* 0x8009BDC0 */
L_8009BDC4:;
    R[2] = (uint32_t)((int32_t)R[3] >> 2);  /* 0x8009BDC4 */
    sw_(R[6] + 16, R[2]);  /* 0x8009BDC8 */
    R[2] = lw_(R[7] + 28);  /* 0x8009BDCC */
    R[3] = lw_(R[7] + 488);  /* 0x8009BDD0 */
    R[4] = lw_(R[5] + 28);  /* 0x8009BDD4 */
    R[2] = R[2] + R[3];  /* 0x8009BDD8 */
    R[2] = R[2] - R[4];  /* 0x8009BDDC */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8009BDEC; } }  /* 0x8009BDE0 */
    R[2] = R[2] + 3;  /* 0x8009BDE8 */
L_8009BDEC:;
    R[2] = (uint32_t)((int32_t)R[2] >> 2);  /* 0x8009BDEC */
    sw_(R[6] + 20, R[2]);  /* 0x8009BDF0 */
    R[3] = lw_(R[7] + 32);  /* 0x8009BDF4 */
    R[2] = lw_(R[5] + 32);  /* 0x8009BDF8 */
    R[2] = R[3] - R[2];  /* 0x8009BE00 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8009BE10; } }  /* 0x8009BE04 */
    R[2] = R[2] + 3;  /* 0x8009BE0C */
L_8009BE10:;
    R[2] = (uint32_t)((int32_t)R[2] >> 2);  /* 0x8009BE10 */
    { sw_(R[6] + 24, R[2]); psx_next = R[31]; return; }  /* 0x8009BE14 jr ra */
    R[3] = lw_(R[7] + 24);  /* 0x8009BE1C */
    R[2] = lw_(R[5] + 24);  /* 0x8009BE20 */
    R[4] = R[3] - R[2];  /* 0x8009BE28 */
    { uint32_t _c = (R[4] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009BE68; } }  /* 0x8009BE2C */
    R[6] = lw_(R[2] + -29640);  /* 0x8009BE34 */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[3] = R[4] + R[0]; if (_c) { goto L_8009BE44; } }  /* 0x8009BE38 */
    R[3] = R[0] - R[3];  /* 0x8009BE40 */
L_8009BE44:;
    { uint32_t _c = ((int32_t)R[6] >= 0); R[2] = R[6] + R[0]; if (_c) { goto L_8009BE50; } }  /* 0x8009BE44 */
    R[2] = R[0] - R[2];  /* 0x8009BE4C */
L_8009BE50:;
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009BE50 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009BE64; } }  /* 0x8009BE54 */
    { sw_(R[5] + 196, R[6]); goto L_8009BE68; }  /* 0x8009BE5C j */
L_8009BE64:;
    sw_(R[5] + 196, R[4]);  /* 0x8009BE64 */
L_8009BE68:;
    R[3] = lw_(R[7] + 32);  /* 0x8009BE68 */
    R[2] = lw_(R[5] + 32);  /* 0x8009BE6C */
    R[4] = R[3] - R[2];  /* 0x8009BE74 */
    { uint32_t _c = (R[4] == R[0]); R[2] = 0x8013u << 16; if (_c) { psx_next = 0x8009BEB4u; return; } }  /* 0x8009BE78 b extern */
    R[6] = lw_(R[2] + -29632);  /* 0x8009BE80 */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[3] = R[4] + R[0]; if (_c) { psx_next = 0x8009BE90u; return; } }  /* 0x8009BE84 b extern */
    R[3] = R[0] - R[3];  /* 0x8009BE8C */
    psx_next = 0x8009BE90u; return;  /* fallthrough */
}

void g0_8009BE1C(void) {
    R[3] = lw_(R[7] + 24);  /* 0x8009BE1C */
    R[2] = lw_(R[5] + 24);  /* 0x8009BE20 */
    R[4] = R[3] - R[2];  /* 0x8009BE28 */
    { uint32_t _c = (R[4] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009BE68; } }  /* 0x8009BE2C */
    R[6] = lw_(R[2] + -29640);  /* 0x8009BE34 */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[3] = R[4] + R[0]; if (_c) { goto L_8009BE44; } }  /* 0x8009BE38 */
    R[3] = R[0] - R[3];  /* 0x8009BE40 */
L_8009BE44:;
    { uint32_t _c = ((int32_t)R[6] >= 0); R[2] = R[6] + R[0]; if (_c) { goto L_8009BE50; } }  /* 0x8009BE44 */
    R[2] = R[0] - R[2];  /* 0x8009BE4C */
L_8009BE50:;
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009BE50 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009BE64; } }  /* 0x8009BE54 */
    { sw_(R[5] + 196, R[6]); goto L_8009BE68; }  /* 0x8009BE5C j */
L_8009BE64:;
    sw_(R[5] + 196, R[4]);  /* 0x8009BE64 */
L_8009BE68:;
    R[3] = lw_(R[7] + 32);  /* 0x8009BE68 */
    R[2] = lw_(R[5] + 32);  /* 0x8009BE6C */
    R[4] = R[3] - R[2];  /* 0x8009BE74 */
    { uint32_t _c = (R[4] == R[0]); R[2] = 0x8013u << 16; if (_c) { psx_next = 0x8009BEB4u; return; } }  /* 0x8009BE78 b extern */
    R[6] = lw_(R[2] + -29632);  /* 0x8009BE80 */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[3] = R[4] + R[0]; if (_c) { psx_next = 0x8009BE90u; return; } }  /* 0x8009BE84 b extern */
    R[3] = R[0] - R[3];  /* 0x8009BE8C */
    psx_next = 0x8009BE90u; return;  /* fallthrough */
}

void g0_8009BE90(void) {
    { uint32_t _c = ((int32_t)R[6] >= 0); R[2] = R[6] + R[0]; if (_c) { goto L_8009BE9C; } }  /* 0x8009BE90 */
    R[2] = R[0] - R[2];  /* 0x8009BE98 */
L_8009BE9C:;
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009BE9C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009BEB0; } }  /* 0x8009BEA0 */
    { sw_(R[5] + 204, R[6]); goto L_8009BEB4; }  /* 0x8009BEA8 j */
L_8009BEB0:;
    sw_(R[5] + 204, R[4]);  /* 0x8009BEB0 */
L_8009BEB4:;
    R[2] = lw_(R[7] + 28);  /* 0x8009BEB4 */
    R[3] = lw_(R[7] + 488);  /* 0x8009BEB8 */
    R[4] = lw_(R[5] + 28);  /* 0x8009BEBC */
    R[2] = R[2] + R[3];  /* 0x8009BEC0 */
    R[4] = R[2] - R[4];  /* 0x8009BEC4 */
    { uint32_t _c = (R[4] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009BF04; } }  /* 0x8009BEC8 */
    R[6] = lw_(R[2] + -29636);  /* 0x8009BED0 */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[3] = R[4] + R[0]; if (_c) { goto L_8009BEE0; } }  /* 0x8009BED4 */
    R[3] = R[0] - R[3];  /* 0x8009BEDC */
L_8009BEE0:;
    { uint32_t _c = ((int32_t)R[6] >= 0); R[2] = R[6] + R[0]; if (_c) { goto L_8009BEEC; } }  /* 0x8009BEE0 */
    R[2] = R[0] - R[2];  /* 0x8009BEE8 */
L_8009BEEC:;
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009BEEC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009BF00; } }  /* 0x8009BEF0 */
    { sw_(R[5] + 200, R[6]); psx_next = R[31]; return; }  /* 0x8009BEF8 jr ra */
L_8009BF00:;
    sw_(R[5] + 200, R[4]);  /* 0x8009BF00 */
L_8009BF04:;
    { psx_next = R[31]; return; }  /* 0x8009BF04 jr ra */
}

void g0_8009BEB4(void) {
    R[2] = lw_(R[7] + 28);  /* 0x8009BEB4 */
    R[3] = lw_(R[7] + 488);  /* 0x8009BEB8 */
    R[4] = lw_(R[5] + 28);  /* 0x8009BEBC */
    R[2] = R[2] + R[3];  /* 0x8009BEC0 */
    R[4] = R[2] - R[4];  /* 0x8009BEC4 */
    { uint32_t _c = (R[4] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009BF04; } }  /* 0x8009BEC8 */
    R[6] = lw_(R[2] + -29636);  /* 0x8009BED0 */
    { uint32_t _c = ((int32_t)R[4] >= 0); R[3] = R[4] + R[0]; if (_c) { goto L_8009BEE0; } }  /* 0x8009BED4 */
    R[3] = R[0] - R[3];  /* 0x8009BEDC */
L_8009BEE0:;
    { uint32_t _c = ((int32_t)R[6] >= 0); R[2] = R[6] + R[0]; if (_c) { goto L_8009BEEC; } }  /* 0x8009BEE0 */
    R[2] = R[0] - R[2];  /* 0x8009BEE8 */
L_8009BEEC:;
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009BEEC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009BF00; } }  /* 0x8009BEF0 */
    { sw_(R[5] + 200, R[6]); psx_next = R[31]; return; }  /* 0x8009BEF8 jr ra */
L_8009BF00:;
    sw_(R[5] + 200, R[4]);  /* 0x8009BF00 */
L_8009BF04:;
    { psx_next = R[31]; return; }  /* 0x8009BF04 jr ra */
}

void g0_8009BF0C(void) {
    R[29] = R[29] - 48;  /* 0x8009BF0C */
    sw_(R[29] + 24, R[18]);  /* 0x8009BF10 */
    R[18] = R[4] + R[0];  /* 0x8009BF14 */
    sw_(R[29] + 40, R[31]);  /* 0x8009BF18 */
    sw_(R[29] + 36, R[21]);  /* 0x8009BF1C */
    sw_(R[29] + 32, R[20]);  /* 0x8009BF20 */
    sw_(R[29] + 28, R[19]);  /* 0x8009BF24 */
    sw_(R[29] + 20, R[17]);  /* 0x8009BF28 */
    sw_(R[29] + 16, R[16]);  /* 0x8009BF2C */
    R[2] = lw_(R[18] + 576);  /* 0x8009BF30 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009C108u; return; } }  /* 0x8009BF38 b extern */
    R[19] = R[0] + R[0];  /* 0x8009BF40 */
    R[2] = lb_(R[18] + 498);  /* 0x8009BF44 */
    { uint32_t _c = (R[2] == R[0]); R[16] = R[19] + R[0]; if (_c) { goto L_8009BF94; } }  /* 0x8009BF4C */
    R[6] = R[0] + 6;  /* 0x8009BF54 */
    R[4] = R[2] + R[0];  /* 0x8009BF58 */
    R[3] = R[18] + R[0];  /* 0x8009BF5C */
L_8009BF60:;
    R[5] = lw_(R[3] + 552);  /* 0x8009BF60 */
    R[2] = (uint32_t)(int16_t)lh_(R[5] + 12);  /* 0x8009BF68 */
    { uint32_t _c = (R[2] != R[6]); if (_c) { goto L_8009BF88; } }  /* 0x8009BF70 */
    R[2] = (uint32_t)(int16_t)lh_(R[5] + 20);  /* 0x8009BF78 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009C0C0u; return; } }  /* 0x8009BF80 b extern */
L_8009BF88:;
    R[16] = R[16] + 1;  /* 0x8009BF88 */
    { uint32_t _c = (R[16] != R[4]); R[3] = R[3] + 4; if (_c) { psx_bb(); goto L_8009BF60; } }  /* 0x8009BF8C */
L_8009BF94:;
    R[20] = 0x3Eu << 16;  /* 0x8009BF94 */
    R[3] = 0x8006u << 16;  /* 0x8009BF98 */
    R[2] = 0x8006u << 16;  /* 0x8009BF9C */
    R[4] = R[2] + 13192;  /* 0x8009BFA0 */
    R[2] = lh_(R[3] + -6452);  /* 0x8009BFA4 */
    R[3] = lh_(R[4] + 2920);  /* 0x8009BFA8 */
    R[2] = R[2] & R[3];  /* 0x8009BFB0 */
    { uint32_t _c = (R[2] == R[0]); R[20] = R[20] | 0x8000; if (_c) { psx_next = 0x8009C0A8u; return; } }  /* 0x8009BFB4 b extern */
    { uint32_t _c = (R[19] != R[0]); R[2] = R[0] + 1; if (_c) { psx_next = 0x8009C0B0u; return; } }  /* 0x8009BFBC b extern */
    R[2] = lb_(R[18] + 784);  /* 0x8009BFC4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009C0A8u; return; } }  /* 0x8009BFCC b extern */
    R[2] = lb_(R[18] + 496);  /* 0x8009BFD4 */
    { uint32_t _c = (R[2] == R[0]); R[16] = R[0] + R[0]; if (_c) { psx_next = 0x8009C0A8u; return; } }  /* 0x8009BFDC b extern */
    R[21] = R[4] + R[0];  /* 0x8009BFE4 */
    R[17] = R[18] + R[0];  /* 0x8009BFE8 */
    R[5] = lw_(R[17] + 500);  /* 0x8009BFEC */
    R[3] = (uint32_t)(int16_t)lh_(R[5] + 12);  /* 0x8009BFF4 */
    R[2] = R[0] + 6;  /* 0x8009BFF8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { psx_next = 0x8009C098u; return; } }  /* 0x8009BFFC b extern */
    R[2] = lb_(R[5] + 784);  /* 0x8009C004 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009C098u; return; } }  /* 0x8009C00C b extern */
    { R[31] = 0x8009C01Cu; R[4] = R[18] + R[0]; psx_next = 0x8008DC60u; return; }  /* 0x8009C014 jal */
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 4);  /* 0x8009C01C */
    R[3] = R[3] - R[2];  /* 0x8009C024 */
    R[3] = R[3] & 0x1FF;  /* 0x8009C028 */
    R[3] = R[3] - 96;  /* 0x8009C02C */
    R[3] = (R[3] < (uint32_t)321u);  /* 0x8009C030 */
    { uint32_t _c = (R[3] != R[0]); if (_c) { psx_next = 0x8009C098u; return; } }  /* 0x8009C034 b extern */
    R[5] = lw_(R[17] + 500);  /* 0x8009C03C */
    R[3] = lw_(R[18] + 24);  /* 0x8009C040 */
    R[2] = lw_(R[5] + 24);  /* 0x8009C044 */
    R[4] = lw_(R[5] + 32);  /* 0x8009C048 */
    R[3] = R[3] - R[2];  /* 0x8009C04C */
    R[2] = lw_(R[18] + 32);  /* 0x8009C050 */
    psx_next = 0x8009C054u; return;  /* fallthrough */
}

void g0_8009BF94(void) {
    R[20] = 0x3Eu << 16;  /* 0x8009BF94 */
    R[3] = 0x8006u << 16;  /* 0x8009BF98 */
    R[2] = 0x8006u << 16;  /* 0x8009BF9C */
    R[4] = R[2] + 13192;  /* 0x8009BFA0 */
    R[2] = lh_(R[3] + -6452);  /* 0x8009BFA4 */
    R[3] = lh_(R[4] + 2920);  /* 0x8009BFA8 */
    R[2] = R[2] & R[3];  /* 0x8009BFB0 */
    { uint32_t _c = (R[2] == R[0]); R[20] = R[20] | 0x8000; if (_c) { psx_next = 0x8009C0A8u; return; } }  /* 0x8009BFB4 b extern */
    { uint32_t _c = (R[19] != R[0]); R[2] = R[0] + 1; if (_c) { psx_next = 0x8009C0B0u; return; } }  /* 0x8009BFBC b extern */
    R[2] = lb_(R[18] + 784);  /* 0x8009BFC4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009C0A8u; return; } }  /* 0x8009BFCC b extern */
    R[2] = lb_(R[18] + 496);  /* 0x8009BFD4 */
    { uint32_t _c = (R[2] == R[0]); R[16] = R[0] + R[0]; if (_c) { psx_next = 0x8009C0A8u; return; } }  /* 0x8009BFDC b extern */
    R[21] = R[4] + R[0];  /* 0x8009BFE4 */
    R[17] = R[18] + R[0];  /* 0x8009BFE8 */
    R[5] = lw_(R[17] + 500);  /* 0x8009BFEC */
    R[3] = (uint32_t)(int16_t)lh_(R[5] + 12);  /* 0x8009BFF4 */
    R[2] = R[0] + 6;  /* 0x8009BFF8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { psx_next = 0x8009C098u; return; } }  /* 0x8009BFFC b extern */
    R[2] = lb_(R[5] + 784);  /* 0x8009C004 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009C098u; return; } }  /* 0x8009C00C b extern */
    { R[31] = 0x8009C01Cu; R[4] = R[18] + R[0]; psx_next = 0x8008DC60u; return; }  /* 0x8009C014 jal */
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 4);  /* 0x8009C01C */
    R[3] = R[3] - R[2];  /* 0x8009C024 */
    R[3] = R[3] & 0x1FF;  /* 0x8009C028 */
    R[3] = R[3] - 96;  /* 0x8009C02C */
    R[3] = (R[3] < (uint32_t)321u);  /* 0x8009C030 */
    { uint32_t _c = (R[3] != R[0]); if (_c) { psx_next = 0x8009C098u; return; } }  /* 0x8009C034 b extern */
    R[5] = lw_(R[17] + 500);  /* 0x8009C03C */
    R[3] = lw_(R[18] + 24);  /* 0x8009C040 */
    R[2] = lw_(R[5] + 24);  /* 0x8009C044 */
    R[4] = lw_(R[5] + 32);  /* 0x8009C048 */
    R[3] = R[3] - R[2];  /* 0x8009C04C */
    R[2] = lw_(R[18] + 32);  /* 0x8009C050 */
    psx_next = 0x8009C054u; return;  /* fallthrough */
}

void g0_8009BFEC(void) {
    R[5] = lw_(R[17] + 500);  /* 0x8009BFEC */
    R[3] = (uint32_t)(int16_t)lh_(R[5] + 12);  /* 0x8009BFF4 */
    R[2] = R[0] + 6;  /* 0x8009BFF8 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { psx_next = 0x8009C098u; return; } }  /* 0x8009BFFC b extern */
    R[2] = lb_(R[5] + 784);  /* 0x8009C004 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { psx_next = 0x8009C098u; return; } }  /* 0x8009C00C b extern */
    { R[31] = 0x8009C01Cu; R[4] = R[18] + R[0]; psx_next = 0x8008DC60u; return; }  /* 0x8009C014 jal */
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 4);  /* 0x8009C01C */
    R[3] = R[3] - R[2];  /* 0x8009C024 */
    R[3] = R[3] & 0x1FF;  /* 0x8009C028 */
    R[3] = R[3] - 96;  /* 0x8009C02C */
    R[3] = (R[3] < (uint32_t)321u);  /* 0x8009C030 */
    { uint32_t _c = (R[3] != R[0]); if (_c) { psx_next = 0x8009C098u; return; } }  /* 0x8009C034 b extern */
    R[5] = lw_(R[17] + 500);  /* 0x8009C03C */
    R[3] = lw_(R[18] + 24);  /* 0x8009C040 */
    R[2] = lw_(R[5] + 24);  /* 0x8009C044 */
    R[4] = lw_(R[5] + 32);  /* 0x8009C048 */
    R[3] = R[3] - R[2];  /* 0x8009C04C */
    R[2] = lw_(R[18] + 32);  /* 0x8009C050 */
    psx_next = 0x8009C054u; return;  /* fallthrough */
}

void g0_8009C01C(void) {
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 4);  /* 0x8009C01C */
    R[3] = R[3] - R[2];  /* 0x8009C024 */
    R[3] = R[3] & 0x1FF;  /* 0x8009C028 */
    R[3] = R[3] - 96;  /* 0x8009C02C */
    R[3] = (R[3] < (uint32_t)321u);  /* 0x8009C030 */
    { uint32_t _c = (R[3] != R[0]); if (_c) { psx_next = 0x8009C098u; return; } }  /* 0x8009C034 b extern */
    R[5] = lw_(R[17] + 500);  /* 0x8009C03C */
    R[3] = lw_(R[18] + 24);  /* 0x8009C040 */
    R[2] = lw_(R[5] + 24);  /* 0x8009C044 */
    R[4] = lw_(R[5] + 32);  /* 0x8009C048 */
    R[3] = R[3] - R[2];  /* 0x8009C04C */
    R[2] = lw_(R[18] + 32);  /* 0x8009C050 */
    psx_next = 0x8009C054u; return;  /* fallthrough */
}

void g0_8009C054(void) {
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_8009C060; } }  /* 0x8009C054 */
    R[3] = R[0] - R[3];  /* 0x8009C05C */
L_8009C060:;
    R[2] = R[2] - R[4];  /* 0x8009C060 */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8009C070; } }  /* 0x8009C064 */
    R[2] = R[0] - R[2];  /* 0x8009C06C */
L_8009C070:;
    R[3] = R[3] + R[2];  /* 0x8009C070 */
    R[2] = ((int32_t)R[3] < (int32_t)R[20]);  /* 0x8009C074 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 112; if (_c) { psx_next = 0x8009C098u; return; } }  /* 0x8009C078 b extern */
    R[20] = R[3] + R[0];  /* 0x8009C080 */
    sh_(R[18] + 20, R[2]);  /* 0x8009C084 */
    R[2] = lh_(R[21] + 2912);  /* 0x8009C088 */
    R[19] = R[5] + R[0];  /* 0x8009C08C */
    R[2] = R[2] & 0xFFFE;  /* 0x8009C090 */
    psx_next = 0x8009C094u; return;  /* fallthrough */
}

void g0_8009C094(void) {
    sh_(R[21] + 2912, R[2]);  /* 0x8009C094 */
    R[2] = lb_(R[18] + 496);  /* 0x8009C098 */
    R[16] = R[16] + 1;  /* 0x8009C09C */
    { uint32_t _c = (R[16] != R[2]); R[17] = R[17] + 4; if (_c) { psx_next = 0x8009BFECu; return; } }  /* 0x8009C0A0 b extern */
    { uint32_t _c = (R[19] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009C104; } }  /* 0x8009C0A8 */
    R[3] = R[2] + R[0];  /* 0x8009C0B0 */
    sw_(R[18] + 576, R[19]);  /* 0x8009C0B4 */
    { sb_(R[18] + 499, R[3]); goto L_8009C108; }  /* 0x8009C0B8 j */
    R[19] = R[5] + R[0];  /* 0x8009C0C0 */
    R[5] = lh_(R[19] + 2);  /* 0x8009C0C4 */
    { R[31] = 0x8009C0D0u; R[4] = R[0] + 42; psx_next = 0x8002CF6Cu; return; }  /* 0x8009C0C8 jal */
    R[4] = R[18] + R[0];  /* 0x8009C0D0 */
    R[5] = R[19] + R[0];  /* 0x8009C0D4 */
    R[2] = R[0] + 111;  /* 0x8009C0D8 */
    R[6] = R[0] + R[0];  /* 0x8009C0DC */
    { R[31] = 0x8009C0E8u; sh_(R[18] + 20, R[2]); psx_next = 0x8009BD74u; return; }  /* 0x8009C0E0 jal */
    R[3] = 0x8006u << 16;  /* 0x8009C0E8 */
    R[3] = R[3] + 13192;  /* 0x8009C0EC */
    R[2] = lh_(R[3] + 2912);  /* 0x8009C0F0 */
    R[2] = R[2] & 0xFFFE;  /* 0x8009C0F8 */
    { sh_(R[3] + 2912, R[2]); psx_next = 0x8009BF94u; return; }  /* 0x8009C0FC j extern */
L_8009C104:;
    R[2] = R[0] + R[0];  /* 0x8009C104 */
L_8009C108:;
    R[31] = lw_(R[29] + 40);  /* 0x8009C108 */
    R[21] = lw_(R[29] + 36);  /* 0x8009C10C */
    R[20] = lw_(R[29] + 32);  /* 0x8009C110 */
    psx_next = 0x8009C114u; return;  /* fallthrough */
}

void g0_8009C098(void) {
    R[2] = lb_(R[18] + 496);  /* 0x8009C098 */
    R[16] = R[16] + 1;  /* 0x8009C09C */
    { uint32_t _c = (R[16] != R[2]); R[17] = R[17] + 4; if (_c) { psx_next = 0x8009BFECu; return; } }  /* 0x8009C0A0 b extern */
    { uint32_t _c = (R[19] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009C104; } }  /* 0x8009C0A8 */
    R[3] = R[2] + R[0];  /* 0x8009C0B0 */
    sw_(R[18] + 576, R[19]);  /* 0x8009C0B4 */
    { sb_(R[18] + 499, R[3]); goto L_8009C108; }  /* 0x8009C0B8 j */
    R[19] = R[5] + R[0];  /* 0x8009C0C0 */
    R[5] = lh_(R[19] + 2);  /* 0x8009C0C4 */
    { R[31] = 0x8009C0D0u; R[4] = R[0] + 42; psx_next = 0x8002CF6Cu; return; }  /* 0x8009C0C8 jal */
    R[4] = R[18] + R[0];  /* 0x8009C0D0 */
    R[5] = R[19] + R[0];  /* 0x8009C0D4 */
    R[2] = R[0] + 111;  /* 0x8009C0D8 */
    R[6] = R[0] + R[0];  /* 0x8009C0DC */
    { R[31] = 0x8009C0E8u; sh_(R[18] + 20, R[2]); psx_next = 0x8009BD74u; return; }  /* 0x8009C0E0 jal */
    R[3] = 0x8006u << 16;  /* 0x8009C0E8 */
    R[3] = R[3] + 13192;  /* 0x8009C0EC */
    R[2] = lh_(R[3] + 2912);  /* 0x8009C0F0 */
    R[2] = R[2] & 0xFFFE;  /* 0x8009C0F8 */
    { sh_(R[3] + 2912, R[2]); psx_next = 0x8009BF94u; return; }  /* 0x8009C0FC j extern */
L_8009C104:;
    R[2] = R[0] + R[0];  /* 0x8009C104 */
L_8009C108:;
    R[31] = lw_(R[29] + 40);  /* 0x8009C108 */
    R[21] = lw_(R[29] + 36);  /* 0x8009C10C */
    R[20] = lw_(R[29] + 32);  /* 0x8009C110 */
    psx_next = 0x8009C114u; return;  /* fallthrough */
}

void g0_8009C0A8(void) {
    { uint32_t _c = (R[19] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009C104; } }  /* 0x8009C0A8 */
    R[3] = R[2] + R[0];  /* 0x8009C0B0 */
    sw_(R[18] + 576, R[19]);  /* 0x8009C0B4 */
    { sb_(R[18] + 499, R[3]); goto L_8009C108; }  /* 0x8009C0B8 j */
    R[19] = R[5] + R[0];  /* 0x8009C0C0 */
    R[5] = lh_(R[19] + 2);  /* 0x8009C0C4 */
    { R[31] = 0x8009C0D0u; R[4] = R[0] + 42; psx_next = 0x8002CF6Cu; return; }  /* 0x8009C0C8 jal */
    R[4] = R[18] + R[0];  /* 0x8009C0D0 */
    R[5] = R[19] + R[0];  /* 0x8009C0D4 */
    R[2] = R[0] + 111;  /* 0x8009C0D8 */
    R[6] = R[0] + R[0];  /* 0x8009C0DC */
    { R[31] = 0x8009C0E8u; sh_(R[18] + 20, R[2]); psx_next = 0x8009BD74u; return; }  /* 0x8009C0E0 jal */
    R[3] = 0x8006u << 16;  /* 0x8009C0E8 */
    R[3] = R[3] + 13192;  /* 0x8009C0EC */
    R[2] = lh_(R[3] + 2912);  /* 0x8009C0F0 */
    R[2] = R[2] & 0xFFFE;  /* 0x8009C0F8 */
    { sh_(R[3] + 2912, R[2]); psx_next = 0x8009BF94u; return; }  /* 0x8009C0FC j extern */
L_8009C104:;
    R[2] = R[0] + R[0];  /* 0x8009C104 */
L_8009C108:;
    R[31] = lw_(R[29] + 40);  /* 0x8009C108 */
    R[21] = lw_(R[29] + 36);  /* 0x8009C10C */
    R[20] = lw_(R[29] + 32);  /* 0x8009C110 */
    psx_next = 0x8009C114u; return;  /* fallthrough */
}

void g0_8009C0B0(void) {
    R[3] = R[2] + R[0];  /* 0x8009C0B0 */
    sw_(R[18] + 576, R[19]);  /* 0x8009C0B4 */
    { sb_(R[18] + 499, R[3]); goto L_8009C108; }  /* 0x8009C0B8 j */
    R[19] = R[5] + R[0];  /* 0x8009C0C0 */
    R[5] = lh_(R[19] + 2);  /* 0x8009C0C4 */
    { R[31] = 0x8009C0D0u; R[4] = R[0] + 42; psx_next = 0x8002CF6Cu; return; }  /* 0x8009C0C8 jal */
    R[4] = R[18] + R[0];  /* 0x8009C0D0 */
    R[5] = R[19] + R[0];  /* 0x8009C0D4 */
    R[2] = R[0] + 111;  /* 0x8009C0D8 */
    R[6] = R[0] + R[0];  /* 0x8009C0DC */
    { R[31] = 0x8009C0E8u; sh_(R[18] + 20, R[2]); psx_next = 0x8009BD74u; return; }  /* 0x8009C0E0 jal */
    R[3] = 0x8006u << 16;  /* 0x8009C0E8 */
    R[3] = R[3] + 13192;  /* 0x8009C0EC */
    R[2] = lh_(R[3] + 2912);  /* 0x8009C0F0 */
    R[2] = R[2] & 0xFFFE;  /* 0x8009C0F8 */
    { sh_(R[3] + 2912, R[2]); psx_next = 0x8009BF94u; return; }  /* 0x8009C0FC j extern */
    R[2] = R[0] + R[0];  /* 0x8009C104 */
L_8009C108:;
    R[31] = lw_(R[29] + 40);  /* 0x8009C108 */
    R[21] = lw_(R[29] + 36);  /* 0x8009C10C */
    R[20] = lw_(R[29] + 32);  /* 0x8009C110 */
    psx_next = 0x8009C114u; return;  /* fallthrough */
}

void g0_8009C0C0(void) {
    R[19] = R[5] + R[0];  /* 0x8009C0C0 */
    R[5] = lh_(R[19] + 2);  /* 0x8009C0C4 */
    { R[31] = 0x8009C0D0u; R[4] = R[0] + 42; psx_next = 0x8002CF6Cu; return; }  /* 0x8009C0C8 jal */
    R[4] = R[18] + R[0];  /* 0x8009C0D0 */
    R[5] = R[19] + R[0];  /* 0x8009C0D4 */
    R[2] = R[0] + 111;  /* 0x8009C0D8 */
    R[6] = R[0] + R[0];  /* 0x8009C0DC */
    { R[31] = 0x8009C0E8u; sh_(R[18] + 20, R[2]); psx_next = 0x8009BD74u; return; }  /* 0x8009C0E0 jal */
    R[3] = 0x8006u << 16;  /* 0x8009C0E8 */
    R[3] = R[3] + 13192;  /* 0x8009C0EC */
    R[2] = lh_(R[3] + 2912);  /* 0x8009C0F0 */
    R[2] = R[2] & 0xFFFE;  /* 0x8009C0F8 */
    { sh_(R[3] + 2912, R[2]); psx_next = 0x8009BF94u; return; }  /* 0x8009C0FC j extern */
    R[2] = R[0] + R[0];  /* 0x8009C104 */
    R[31] = lw_(R[29] + 40);  /* 0x8009C108 */
    R[21] = lw_(R[29] + 36);  /* 0x8009C10C */
    R[20] = lw_(R[29] + 32);  /* 0x8009C110 */
    psx_next = 0x8009C114u; return;  /* fallthrough */
}

void g0_8009C0D0(void) {
    R[4] = R[18] + R[0];  /* 0x8009C0D0 */
    R[5] = R[19] + R[0];  /* 0x8009C0D4 */
    R[2] = R[0] + 111;  /* 0x8009C0D8 */
    R[6] = R[0] + R[0];  /* 0x8009C0DC */
    { R[31] = 0x8009C0E8u; sh_(R[18] + 20, R[2]); psx_next = 0x8009BD74u; return; }  /* 0x8009C0E0 jal */
    R[3] = 0x8006u << 16;  /* 0x8009C0E8 */
    R[3] = R[3] + 13192;  /* 0x8009C0EC */
    R[2] = lh_(R[3] + 2912);  /* 0x8009C0F0 */
    R[2] = R[2] & 0xFFFE;  /* 0x8009C0F8 */
    { sh_(R[3] + 2912, R[2]); psx_next = 0x8009BF94u; return; }  /* 0x8009C0FC j extern */
    R[2] = R[0] + R[0];  /* 0x8009C104 */
    R[31] = lw_(R[29] + 40);  /* 0x8009C108 */
    R[21] = lw_(R[29] + 36);  /* 0x8009C10C */
    R[20] = lw_(R[29] + 32);  /* 0x8009C110 */
    psx_next = 0x8009C114u; return;  /* fallthrough */
}

void g0_8009C0E8(void) {
    R[3] = 0x8006u << 16;  /* 0x8009C0E8 */
    R[3] = R[3] + 13192;  /* 0x8009C0EC */
    R[2] = lh_(R[3] + 2912);  /* 0x8009C0F0 */
    R[2] = R[2] & 0xFFFE;  /* 0x8009C0F8 */
    { sh_(R[3] + 2912, R[2]); psx_next = 0x8009BF94u; return; }  /* 0x8009C0FC j extern */
    R[2] = R[0] + R[0];  /* 0x8009C104 */
    R[31] = lw_(R[29] + 40);  /* 0x8009C108 */
    R[21] = lw_(R[29] + 36);  /* 0x8009C10C */
    R[20] = lw_(R[29] + 32);  /* 0x8009C110 */
    psx_next = 0x8009C114u; return;  /* fallthrough */
}

void g0_8009C108(void) {
    R[31] = lw_(R[29] + 40);  /* 0x8009C108 */
    R[21] = lw_(R[29] + 36);  /* 0x8009C10C */
    R[20] = lw_(R[29] + 32);  /* 0x8009C110 */
    psx_next = 0x8009C114u; return;  /* fallthrough */
}

void g0_8009C114(void) {
    R[19] = lw_(R[29] + 28);  /* 0x8009C114 */
    R[18] = lw_(R[29] + 24);  /* 0x8009C118 */
    R[17] = lw_(R[29] + 20);  /* 0x8009C11C */
    R[16] = lw_(R[29] + 16);  /* 0x8009C120 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009C124 jr ra */
}

void g0_8009C12C(void) {
    R[29] = R[29] - 304;  /* 0x8009C12C */
    sw_(R[29] + 288, R[18]);  /* 0x8009C130 */
    R[18] = R[4] + R[0];  /* 0x8009C134 */
    sw_(R[29] + 296, R[31]);  /* 0x8009C138 */
    sw_(R[29] + 292, R[19]);  /* 0x8009C13C */
    sw_(R[29] + 284, R[17]);  /* 0x8009C140 */
    sw_(R[29] + 280, R[16]);  /* 0x8009C144 */
    R[4] = lw_(R[18] + 576);  /* 0x8009C148 */
    { uint32_t _c = (R[4] == R[0]); R[19] = R[5] + R[0]; if (_c) { psx_next = 0x8009C388u; return; } }  /* 0x8009C150 b extern */
    R[7] = R[0] + 1;  /* 0x8009C158 */
    R[8] = R[0] + R[0];  /* 0x8009C15C */
    R[2] = 0x8012u << 16;  /* 0x8009C160 */
    R[16] = R[2] - 26060;  /* 0x8009C164 */
    R[10] = R[0] + 5;  /* 0x8009C168 */
    R[9] = R[0] + 60;  /* 0x8009C16C */
    R[5] = R[16] + 791;  /* 0x8009C170 */
    R[6] = R[29] + 16;  /* 0x8009C174 */
    R[17] = R[4] + R[0];  /* 0x8009C178 */
    sw_(R[18] + 576, R[0]);  /* 0x8009C17C */
    sb_(R[18] + 499, R[0]);  /* 0x8009C180 */
    sb_(R[17] + 499, R[0]);  /* 0x8009C184 */
L_8009C188:;
    R[2] = (uint32_t)(int16_t)lh_(R[16]);  /* 0x8009C188 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009C1D0; } }  /* 0x8009C190 */
    R[3] = lb_(R[5] + -2);  /* 0x8009C198 */
    R[2] = R[3] & 0x1;  /* 0x8009C1A0 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { goto L_8009C1D0; } }  /* 0x8009C1A4 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009C1D0; } }  /* 0x8009C1AC */
    R[2] = lb_(R[5]);  /* 0x8009C1B4 */
    { uint32_t _c = (R[2] == R[10]); if (_c) { goto L_8009C1D0; } }  /* 0x8009C1BC */
    sw_(R[6] + 20, R[16]);  /* 0x8009C1C4 */
    R[6] = R[6] + 4;  /* 0x8009C1C8 */
    R[8] = R[8] + 1;  /* 0x8009C1CC */
L_8009C1D0:;
    R[7] = R[7] + 1;  /* 0x8009C1D0 */
    R[5] = R[5] + 804;  /* 0x8009C1D4 */
    { uint32_t _c = (R[7] != R[9]); R[16] = R[16] + 804; if (_c) { psx_bb(); goto L_8009C188; } }  /* 0x8009C1D8 */
    sw_(R[29] + 32, R[8]);  /* 0x8009C1E0 */
    R[4] = R[17] + R[0];  /* 0x8009C1E4 */
    { R[31] = 0x8009C1F0u; R[5] = R[29] + 16; psx_next = 0x8008AEC0u; return; }  /* 0x8009C1E8 jal */
    R[16] = R[2] + R[0];  /* 0x8009C1F0 */
    R[4] = R[17] + R[0];  /* 0x8009C1F4 */
    R[5] = R[0] + R[0];  /* 0x8009C1F8 */
    R[6] = R[5] + R[0];  /* 0x8009C1FC */
    { R[31] = 0x8009C208u; R[7] = R[5] + R[0]; psx_next = 0x80092E6Cu; return; }  /* 0x8009C200 jal */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_8009C218; } }  /* 0x8009C208 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[0] + 2; if (_c) { goto L_8009C230; } }  /* 0x8009C210 */
L_8009C218:;
    R[2] = R[0] + 2;  /* 0x8009C218 */
    sb_(R[17] + 790, R[2]);  /* 0x8009C21C */
    R[2] = R[0] + 1;  /* 0x8009C220 */
    sw_(R[17] + 580, R[0]);  /* 0x8009C224 */
    { sw_(R[17] + 592, R[2]); psx_next = 0x8009C388u; return; }  /* 0x8009C228 j extern */
L_8009C230:;
    { uint32_t _c = (R[19] == R[3]); R[2] = ((int32_t)R[19] < 3); if (_c) { psx_next = 0x8009C318u; return; } }  /* 0x8009C230 b extern */
    psx_next = 0x8009C238u; return;  /* fallthrough */
}

void g0_8009C1F0(void) {
    R[16] = R[2] + R[0];  /* 0x8009C1F0 */
    R[4] = R[17] + R[0];  /* 0x8009C1F4 */
    R[5] = R[0] + R[0];  /* 0x8009C1F8 */
    R[6] = R[5] + R[0];  /* 0x8009C1FC */
    { R[31] = 0x8009C208u; R[7] = R[5] + R[0]; psx_next = 0x80092E6Cu; return; }  /* 0x8009C200 jal */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_8009C218; } }  /* 0x8009C208 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[0] + 2; if (_c) { goto L_8009C230; } }  /* 0x8009C210 */
L_8009C218:;
    R[2] = R[0] + 2;  /* 0x8009C218 */
    sb_(R[17] + 790, R[2]);  /* 0x8009C21C */
    R[2] = R[0] + 1;  /* 0x8009C220 */
    sw_(R[17] + 580, R[0]);  /* 0x8009C224 */
    { sw_(R[17] + 592, R[2]); psx_next = 0x8009C388u; return; }  /* 0x8009C228 j extern */
L_8009C230:;
    { uint32_t _c = (R[19] == R[3]); R[2] = ((int32_t)R[19] < 3); if (_c) { psx_next = 0x8009C318u; return; } }  /* 0x8009C230 b extern */
    psx_next = 0x8009C238u; return;  /* fallthrough */
}

void g0_8009C208(void) {
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_8009C218; } }  /* 0x8009C208 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[0] + 2; if (_c) { goto L_8009C230; } }  /* 0x8009C210 */
L_8009C218:;
    R[2] = R[0] + 2;  /* 0x8009C218 */
    sb_(R[17] + 790, R[2]);  /* 0x8009C21C */
    R[2] = R[0] + 1;  /* 0x8009C220 */
    sw_(R[17] + 580, R[0]);  /* 0x8009C224 */
    { sw_(R[17] + 592, R[2]); psx_next = 0x8009C388u; return; }  /* 0x8009C228 j extern */
L_8009C230:;
    { uint32_t _c = (R[19] == R[3]); R[2] = ((int32_t)R[19] < 3); if (_c) { psx_next = 0x8009C318u; return; } }  /* 0x8009C230 b extern */
    psx_next = 0x8009C238u; return;  /* fallthrough */
}

void g0_8009C234(void) {
    R[2] = ((int32_t)R[19] < 3);  /* 0x8009C234 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009C250; } }  /* 0x8009C238 */
    { uint32_t _c = (R[19] == R[2]); R[2] = R[0] + 16384; if (_c) { goto L_8009C264; } }  /* 0x8009C240 */
    { sw_(R[17] + 200, R[2]); goto L_8009C388; }  /* 0x8009C248 j */
L_8009C250:;
    R[2] = R[0] + 3;  /* 0x8009C250 */
    { uint32_t _c = (R[19] == R[2]); R[2] = R[0] + 16384; if (_c) { goto L_8009C370; } }  /* 0x8009C254 */
    { sw_(R[17] + 200, R[2]); goto L_8009C388; }  /* 0x8009C25C j */
L_8009C264:;
    R[4] = 0x8013u << 16;  /* 0x8009C264 */
    R[2] = lh_(R[18] + 8);  /* 0x8009C268 */
    R[4] = R[4] - 29656;  /* 0x8009C26C */
    sh_(R[17] + 6, R[2]);  /* 0x8009C270 */
    R[3] = lh_(R[18] + 4);  /* 0x8009C274 */
    R[5] = lh_(R[4] + 28);  /* 0x8009C278 */
    R[2] = R[0] + 120;  /* 0x8009C27C */
    sh_(R[17] + 20, R[2]);  /* 0x8009C280 */
    sb_(R[17] + 784, R[0]);  /* 0x8009C284 */
    R[3] = R[3] + R[5];  /* 0x8009C288 */
    R[3] = R[3] & 0x1FF;  /* 0x8009C28C */
    sh_(R[17] + 4, R[3]);  /* 0x8009C290 */
    R[2] = lb_(R[4] + 32);  /* 0x8009C294 */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x1u << 16; if (_c) { goto L_8009C2C4; } }  /* 0x8009C29C */
    R[2] = R[0] + 4096;  /* 0x8009C2A4 */
    sw_(R[17] + 124, R[2]);  /* 0x8009C2A8 */
    R[2] = 0x8012u << 16;  /* 0x8009C2AC */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009C2B0 */
    R[3] = R[3] | 0x22E5;  /* 0x8009C2B4 */
    R[3] = (uint32_t)((int32_t)R[3] >> (R[2] & 31));  /* 0x8009C2B8 */
    { sw_(R[17] + 140, R[3]); goto L_8009C300; }  /* 0x8009C2BC j */
L_8009C2C4:;
    R[2] = R[0] + 2048;  /* 0x8009C2C4 */
    sw_(R[17] + 124, R[2]);  /* 0x8009C2C8 */
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 20);  /* 0x8009C2CC */
    R[2] = R[0] + 121;  /* 0x8009C2D0 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x1u << 16; if (_c) { goto L_8009C2EC; } }  /* 0x8009C2D4 */
    R[3] = 0x8012u << 16;  /* 0x8009C2DC */
    R[3] = (uint32_t)(int16_t)lh_(R[3] + 30976);  /* 0x8009C2E0 */
    { R[2] = R[2] | 0x22E5; goto L_8009C2F8; }  /* 0x8009C2E4 j */
L_8009C2EC:;
    R[2] = 0x8012u << 16;  /* 0x8009C2EC */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009C2F0 */
    R[2] = R[0] | 0xC1EE;  /* 0x8009C2F4 */
L_8009C2F8:;
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009C2F8 */
    sw_(R[17] + 140, R[2]);  /* 0x8009C2FC */
L_8009C300:;
    R[2] = lw_(R[18] + 140);  /* 0x8009C300 */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[2] = R[0] + 16384; if (_c) { goto L_8009C384; } }  /* 0x8009C308 */
    { sw_(R[18] + 140, R[0]); goto L_8009C384; }  /* 0x8009C310 j */
    R[2] = lh_(R[18] + 8);  /* 0x8009C318 */
    R[4] = 0x1u << 16;  /* 0x8009C31C */
    R[2] = R[2] + 256;  /* 0x8009C320 */
    R[2] = R[2] & 0x1FF;  /* 0x8009C324 */
    sh_(R[17] + 6, R[2]);  /* 0x8009C328 */
    R[2] = 0x8013u << 16;  /* 0x8009C32C */
    R[3] = lh_(R[18] + 4);  /* 0x8009C330 */
    R[5] = lh_(R[2] + -29628);  /* 0x8009C334 */
    R[2] = R[0] + 2048;  /* 0x8009C338 */
    sw_(R[17] + 124, R[2]);  /* 0x8009C33C */
    R[2] = R[0] + 120;  /* 0x8009C340 */
    sh_(R[17] + 20, R[2]);  /* 0x8009C344 */
    R[2] = 0x8012u << 16;  /* 0x8009C348 */
    R[3] = R[3] + R[5];  /* 0x8009C34C */
    R[3] = R[3] & 0x1FF;  /* 0x8009C350 */
    sh_(R[17] + 4, R[3]);  /* 0x8009C354 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009C358 */
    R[4] = R[4] | 0x22E5;  /* 0x8009C35C */
    sb_(R[17] + 784, R[0]);  /* 0x8009C360 */
    R[4] = (uint32_t)((int32_t)R[4] >> (R[2] & 31));  /* 0x8009C364 */
    { sw_(R[17] + 140, R[4]); goto L_8009C380; }  /* 0x8009C368 j */
L_8009C370:;
    R[2] = R[0] + 1;  /* 0x8009C370 */
    sb_(R[17] + 790, R[3]);  /* 0x8009C374 */
    sw_(R[17] + 580, R[0]);  /* 0x8009C378 */
    sw_(R[17] + 592, R[2]);  /* 0x8009C37C */
L_8009C380:;
    R[2] = R[0] + 16384;  /* 0x8009C380 */
L_8009C384:;
    sw_(R[17] + 200, R[2]);  /* 0x8009C384 */
L_8009C388:;
    R[31] = lw_(R[29] + 296);  /* 0x8009C388 */
    R[19] = lw_(R[29] + 292);  /* 0x8009C38C */
    R[18] = lw_(R[29] + 288);  /* 0x8009C390 */
    R[17] = lw_(R[29] + 284);  /* 0x8009C394 */
    R[16] = lw_(R[29] + 280);  /* 0x8009C398 */
    { R[29] = R[29] + 304; psx_next = R[31]; return; }  /* 0x8009C39C jr ra */
}

void g0_8009C238(void) {
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009C250; } }  /* 0x8009C238 */
    { uint32_t _c = (R[19] == R[2]); R[2] = R[0] + 16384; if (_c) { goto L_8009C264; } }  /* 0x8009C240 */
    { sw_(R[17] + 200, R[2]); goto L_8009C388; }  /* 0x8009C248 j */
L_8009C250:;
    R[2] = R[0] + 3;  /* 0x8009C250 */
    { uint32_t _c = (R[19] == R[2]); R[2] = R[0] + 16384; if (_c) { goto L_8009C370; } }  /* 0x8009C254 */
    { sw_(R[17] + 200, R[2]); goto L_8009C388; }  /* 0x8009C25C j */
L_8009C264:;
    R[4] = 0x8013u << 16;  /* 0x8009C264 */
    R[2] = lh_(R[18] + 8);  /* 0x8009C268 */
    R[4] = R[4] - 29656;  /* 0x8009C26C */
    sh_(R[17] + 6, R[2]);  /* 0x8009C270 */
    R[3] = lh_(R[18] + 4);  /* 0x8009C274 */
    R[5] = lh_(R[4] + 28);  /* 0x8009C278 */
    R[2] = R[0] + 120;  /* 0x8009C27C */
    sh_(R[17] + 20, R[2]);  /* 0x8009C280 */
    sb_(R[17] + 784, R[0]);  /* 0x8009C284 */
    R[3] = R[3] + R[5];  /* 0x8009C288 */
    R[3] = R[3] & 0x1FF;  /* 0x8009C28C */
    sh_(R[17] + 4, R[3]);  /* 0x8009C290 */
    R[2] = lb_(R[4] + 32);  /* 0x8009C294 */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x1u << 16; if (_c) { goto L_8009C2C4; } }  /* 0x8009C29C */
    R[2] = R[0] + 4096;  /* 0x8009C2A4 */
    sw_(R[17] + 124, R[2]);  /* 0x8009C2A8 */
    R[2] = 0x8012u << 16;  /* 0x8009C2AC */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009C2B0 */
    R[3] = R[3] | 0x22E5;  /* 0x8009C2B4 */
    R[3] = (uint32_t)((int32_t)R[3] >> (R[2] & 31));  /* 0x8009C2B8 */
    { sw_(R[17] + 140, R[3]); goto L_8009C300; }  /* 0x8009C2BC j */
L_8009C2C4:;
    R[2] = R[0] + 2048;  /* 0x8009C2C4 */
    sw_(R[17] + 124, R[2]);  /* 0x8009C2C8 */
    R[3] = (uint32_t)(int16_t)lh_(R[18] + 20);  /* 0x8009C2CC */
    R[2] = R[0] + 121;  /* 0x8009C2D0 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x1u << 16; if (_c) { goto L_8009C2EC; } }  /* 0x8009C2D4 */
    R[3] = 0x8012u << 16;  /* 0x8009C2DC */
    R[3] = (uint32_t)(int16_t)lh_(R[3] + 30976);  /* 0x8009C2E0 */
    { R[2] = R[2] | 0x22E5; goto L_8009C2F8; }  /* 0x8009C2E4 j */
L_8009C2EC:;
    R[2] = 0x8012u << 16;  /* 0x8009C2EC */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009C2F0 */
    R[2] = R[0] | 0xC1EE;  /* 0x8009C2F4 */
L_8009C2F8:;
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009C2F8 */
    sw_(R[17] + 140, R[2]);  /* 0x8009C2FC */
L_8009C300:;
    R[2] = lw_(R[18] + 140);  /* 0x8009C300 */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[2] = R[0] + 16384; if (_c) { goto L_8009C384; } }  /* 0x8009C308 */
    { sw_(R[18] + 140, R[0]); goto L_8009C384; }  /* 0x8009C310 j */
    R[2] = lh_(R[18] + 8);  /* 0x8009C318 */
    R[4] = 0x1u << 16;  /* 0x8009C31C */
    R[2] = R[2] + 256;  /* 0x8009C320 */
    R[2] = R[2] & 0x1FF;  /* 0x8009C324 */
    sh_(R[17] + 6, R[2]);  /* 0x8009C328 */
    R[2] = 0x8013u << 16;  /* 0x8009C32C */
    R[3] = lh_(R[18] + 4);  /* 0x8009C330 */
    R[5] = lh_(R[2] + -29628);  /* 0x8009C334 */
    R[2] = R[0] + 2048;  /* 0x8009C338 */
    sw_(R[17] + 124, R[2]);  /* 0x8009C33C */
    R[2] = R[0] + 120;  /* 0x8009C340 */
    sh_(R[17] + 20, R[2]);  /* 0x8009C344 */
    R[2] = 0x8012u << 16;  /* 0x8009C348 */
    R[3] = R[3] + R[5];  /* 0x8009C34C */
    R[3] = R[3] & 0x1FF;  /* 0x8009C350 */
    sh_(R[17] + 4, R[3]);  /* 0x8009C354 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009C358 */
    R[4] = R[4] | 0x22E5;  /* 0x8009C35C */
    sb_(R[17] + 784, R[0]);  /* 0x8009C360 */
    R[4] = (uint32_t)((int32_t)R[4] >> (R[2] & 31));  /* 0x8009C364 */
    { sw_(R[17] + 140, R[4]); goto L_8009C380; }  /* 0x8009C368 j */
L_8009C370:;
    R[2] = R[0] + 1;  /* 0x8009C370 */
    sb_(R[17] + 790, R[3]);  /* 0x8009C374 */
    sw_(R[17] + 580, R[0]);  /* 0x8009C378 */
    sw_(R[17] + 592, R[2]);  /* 0x8009C37C */
L_8009C380:;
    R[2] = R[0] + 16384;  /* 0x8009C380 */
L_8009C384:;
    sw_(R[17] + 200, R[2]);  /* 0x8009C384 */
L_8009C388:;
    R[31] = lw_(R[29] + 296);  /* 0x8009C388 */
    R[19] = lw_(R[29] + 292);  /* 0x8009C38C */
    R[18] = lw_(R[29] + 288);  /* 0x8009C390 */
    R[17] = lw_(R[29] + 284);  /* 0x8009C394 */
    R[16] = lw_(R[29] + 280);  /* 0x8009C398 */
    { R[29] = R[29] + 304; psx_next = R[31]; return; }  /* 0x8009C39C jr ra */
}

void g0_8009C318(void) {
    R[2] = lh_(R[18] + 8);  /* 0x8009C318 */
    R[4] = 0x1u << 16;  /* 0x8009C31C */
    R[2] = R[2] + 256;  /* 0x8009C320 */
    R[2] = R[2] & 0x1FF;  /* 0x8009C324 */
    sh_(R[17] + 6, R[2]);  /* 0x8009C328 */
    R[2] = 0x8013u << 16;  /* 0x8009C32C */
    R[3] = lh_(R[18] + 4);  /* 0x8009C330 */
    R[5] = lh_(R[2] + -29628);  /* 0x8009C334 */
    R[2] = R[0] + 2048;  /* 0x8009C338 */
    sw_(R[17] + 124, R[2]);  /* 0x8009C33C */
    R[2] = R[0] + 120;  /* 0x8009C340 */
    sh_(R[17] + 20, R[2]);  /* 0x8009C344 */
    R[2] = 0x8012u << 16;  /* 0x8009C348 */
    R[3] = R[3] + R[5];  /* 0x8009C34C */
    R[3] = R[3] & 0x1FF;  /* 0x8009C350 */
    sh_(R[17] + 4, R[3]);  /* 0x8009C354 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 30976);  /* 0x8009C358 */
    R[4] = R[4] | 0x22E5;  /* 0x8009C35C */
    sb_(R[17] + 784, R[0]);  /* 0x8009C360 */
    R[4] = (uint32_t)((int32_t)R[4] >> (R[2] & 31));  /* 0x8009C364 */
    { sw_(R[17] + 140, R[4]); goto L_8009C380; }  /* 0x8009C368 j */
    R[2] = R[0] + 1;  /* 0x8009C370 */
    sb_(R[17] + 790, R[3]);  /* 0x8009C374 */
    sw_(R[17] + 580, R[0]);  /* 0x8009C378 */
    sw_(R[17] + 592, R[2]);  /* 0x8009C37C */
L_8009C380:;
    R[2] = R[0] + 16384;  /* 0x8009C380 */
    sw_(R[17] + 200, R[2]);  /* 0x8009C384 */
    R[31] = lw_(R[29] + 296);  /* 0x8009C388 */
    R[19] = lw_(R[29] + 292);  /* 0x8009C38C */
    R[18] = lw_(R[29] + 288);  /* 0x8009C390 */
    R[17] = lw_(R[29] + 284);  /* 0x8009C394 */
    R[16] = lw_(R[29] + 280);  /* 0x8009C398 */
    { R[29] = R[29] + 304; psx_next = R[31]; return; }  /* 0x8009C39C jr ra */
}

void g0_8009C388(void) {
    R[31] = lw_(R[29] + 296);  /* 0x8009C388 */
    R[19] = lw_(R[29] + 292);  /* 0x8009C38C */
    R[18] = lw_(R[29] + 288);  /* 0x8009C390 */
    R[17] = lw_(R[29] + 284);  /* 0x8009C394 */
    R[16] = lw_(R[29] + 280);  /* 0x8009C398 */
    { R[29] = R[29] + 304; psx_next = R[31]; return; }  /* 0x8009C39C jr ra */
}

void g0_8009C3A4(void) {
    R[29] = R[29] - 56;  /* 0x8009C3A4 */
    sw_(R[29] + 24, R[18]);  /* 0x8009C3A8 */
    R[18] = R[4] + R[0];  /* 0x8009C3AC */
    sw_(R[29] + 36, R[21]);  /* 0x8009C3B0 */
    R[2] = 0x8013u << 16;  /* 0x8009C3B4 */
    sw_(R[29] + 52, R[31]);  /* 0x8009C3B8 */
    sw_(R[29] + 48, R[30]);  /* 0x8009C3BC */
    sw_(R[29] + 44, R[23]);  /* 0x8009C3C0 */
    sw_(R[29] + 40, R[22]);  /* 0x8009C3C4 */
    sw_(R[29] + 32, R[20]);  /* 0x8009C3C8 */
    sw_(R[29] + 28, R[19]);  /* 0x8009C3CC */
    sw_(R[29] + 20, R[17]);  /* 0x8009C3D0 */
    sw_(R[29] + 16, R[16]);  /* 0x8009C3D4 */
    R[3] = lb_(R[18] + 496);  /* 0x8009C3D8 */
    R[23] = lh_(R[2] + -29474);  /* 0x8009C3DC */
    { uint32_t _c = (R[3] == R[0]); R[21] = R[0] + R[0]; if (_c) { goto L_8009C624; } }  /* 0x8009C3E0 */
    R[2] = 0x8006u << 16;  /* 0x8009C3E8 */
    R[30] = R[2] - 6456;  /* 0x8009C3EC */
    R[2] = 0x8006u << 16;  /* 0x8009C3F0 */
    R[22] = R[2] + 13192;  /* 0x8009C3F4 */
    R[2] = 0x8013u << 16;  /* 0x8009C3F8 */
    R[19] = R[2] - 29656;  /* 0x8009C3FC */
    R[2] = R[23] << 16;  /* 0x8009C400 */
    R[20] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009C404 */
    R[5] = 0xBu << 16;  /* 0x8009C408 */
L_8009C40C:;
    R[2] = R[21] << 2;  /* 0x8009C40C */
    R[2] = R[18] + R[2];  /* 0x8009C410 */
    R[5] = R[5] | 0x4000;  /* 0x8009C414 */
    R[17] = lw_(R[2] + 500);  /* 0x8009C418 */
    R[3] = lw_(R[18] + 24);  /* 0x8009C41C */
    R[2] = lw_(R[17] + 24);  /* 0x8009C420 */
    R[4] = lw_(R[17] + 32);  /* 0x8009C424 */
    R[3] = R[3] - R[2];  /* 0x8009C428 */
    R[2] = lw_(R[18] + 32);  /* 0x8009C42C */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_8009C43C; } }  /* 0x8009C430 */
    R[3] = R[0] - R[3];  /* 0x8009C438 */
L_8009C43C:;
    R[2] = R[2] - R[4];  /* 0x8009C43C */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8009C44C; } }  /* 0x8009C440 */
    R[2] = R[0] - R[2];  /* 0x8009C448 */
L_8009C44C:;
    R[3] = R[3] + R[2];  /* 0x8009C44C */
    R[5] = ((int32_t)R[5] < (int32_t)R[3]);  /* 0x8009C450 */
    { uint32_t _c = (R[5] != R[0]); R[2] = 0x1u << 16; if (_c) { goto L_8009C614; } }  /* 0x8009C454 */
    R[3] = lw_(R[18] + 28);  /* 0x8009C45C */
    R[4] = lw_(R[17] + 28);  /* 0x8009C460 */
    R[2] = R[2] | 0x4000;  /* 0x8009C464 */
    R[3] = R[3] - R[4];  /* 0x8009C468 */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_8009C478; } }  /* 0x8009C46C */
    R[3] = R[0] - R[3];  /* 0x8009C474 */
L_8009C478:;
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009C478 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009C614; } }  /* 0x8009C47C */
    R[2] = lh_(R[17] + 12);  /* 0x8009C484 */
    R[2] = R[2] - 7;  /* 0x8009C48C */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x8009C490 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009C614; } }  /* 0x8009C494 */
    R[2] = lw_(R[17] + 584);  /* 0x8009C49C */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[0] + 99; if (_c) { goto L_8009C614; } }  /* 0x8009C4A4 */
    R[2] = (uint32_t)(int16_t)lh_(R[18] + 20);  /* 0x8009C4AC */
    { uint32_t _c = (R[2] == R[6]); R[4] = R[18] + R[0]; if (_c) { goto L_8009C510; } }  /* 0x8009C4B4 */
    R[16] = (uint32_t)(int16_t)lh_(R[18] + 4);  /* 0x8009C4BC */
    { R[31] = 0x8009C4C8u; R[5] = R[17] + R[0]; psx_next = 0x8008DAFCu; return; }  /* 0x8009C4C0 jal */
    { uint32_t _c = (R[16] != R[2]); if (_c) { goto L_8009C614; } }  /* 0x8009C4C8 */
    R[2] = lh_(R[30] + 4);  /* 0x8009C4D0 */
    R[3] = lh_(R[22] + 2920);  /* 0x8009C4D4 */
    R[2] = R[2] & R[3];  /* 0x8009C4DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] - 1; if (_c) { goto L_8009C614; } }  /* 0x8009C4E0 */
    sh_(R[19] + 82, R[0]);  /* 0x8009C4E8 */
    sw_(R[19] + 92, R[17]);  /* 0x8009C4EC */
    sh_(R[19] + 88, R[2]);  /* 0x8009C4F0 */
    R[6] = R[0] + 99;  /* 0x8009C4F4 */
    sh_(R[18] + 20, R[6]);  /* 0x8009C4F8 */
    R[3] = lh_(R[22] + 2912);  /* 0x8009C4FC */
    R[2] = R[0] + 1;  /* 0x8009C500 */
    R[3] = R[3] & 0xFFFE;  /* 0x8009C504 */
    { sh_(R[22] + 2912, R[3]); goto L_8009C628; }  /* 0x8009C508 j */
L_8009C510:;
    R[2] = lh_(R[30] + 2);  /* 0x8009C510 */
    R[3] = lh_(R[22] + 2920);  /* 0x8009C514 */
    R[2] = R[2] & R[3];  /* 0x8009C51C */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009C604; } }  /* 0x8009C520 */
    { R[31] = 0x8009C530u; R[5] = R[17] + R[0]; psx_next = 0x8008DAFCu; return; }  /* 0x8009C528 jal */
    { uint32_t _c = ((int32_t)R[20] < 0); R[3] = R[2] + R[0]; if (_c) { goto L_8009C5FC; } }  /* 0x8009C530 */
    R[2] = (uint32_t)(int16_t)lh_(R[19] + 88);  /* 0x8009C538 */
    { uint32_t _c = (R[20] != R[2]); R[2] = R[3] << 16; if (_c) { goto L_8009C5C4; } }  /* 0x8009C540 */
    R[2] = lh_(R[19] + 82);  /* 0x8009C548 */
    R[2] = R[2] + 1;  /* 0x8009C550 */
    sh_(R[19] + 82, R[2]);  /* 0x8009C554 */
    R[2] = R[2] << 16;  /* 0x8009C558 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009C55C */
    R[2] = ((int32_t)R[2] < 15);  /* 0x8009C560 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] << 16; if (_c) { goto L_8009C624; } }  /* 0x8009C564 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009C56C */
    { uint32_t _c = (R[2] != R[20]); R[2] = R[0] + 94; if (_c) { goto L_8009C57C; } }  /* 0x8009C570 */
    R[2] = R[0] + 129;  /* 0x8009C578 */
L_8009C57C:;
    sh_(R[17] + 20, R[2]);  /* 0x8009C57C */
    sh_(R[18] + 20, R[2]);  /* 0x8009C580 */
    R[5] = lh_(R[18] + 2);  /* 0x8009C584 */
    { R[31] = 0x8009C590u; R[4] = R[0] + 20; psx_next = 0x8002DAE8u; return; }  /* 0x8009C588 jal */
    R[5] = lh_(R[18] + 2);  /* 0x8009C590 */
    { R[31] = 0x8009C59Cu; R[4] = R[0] + 50; psx_next = 0x8002DAE8u; return; }  /* 0x8009C594 jal */
    R[3] = lb_(R[18] + 781);  /* 0x8009C59C */
    R[2] = R[0] + 1;  /* 0x8009C5A0 */
    R[3] = R[3] | 0x80;  /* 0x8009C5A4 */
    sb_(R[18] + 781, R[3]);  /* 0x8009C5A8 */
    sw_(R[19] + 84, R[0]);  /* 0x8009C5AC */
    R[4] = lh_(R[18] + 6);  /* 0x8009C5B0 */
    R[3] = R[2] + R[0];  /* 0x8009C5B4 */
    sw_(R[17] + 584, R[3]);  /* 0x8009C5B8 */
    { sh_(R[17] + 6, R[4]); goto L_8009C628; }  /* 0x8009C5BC j */
L_8009C5C4:;
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009C5C4 */
    { uint32_t _c = (R[4] == R[20]); R[2] = R[0] + 8; if (_c) { goto L_8009C5F0; } }  /* 0x8009C5C8 */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 12);  /* 0x8009C5D0 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] - 1; if (_c) { goto L_8009C5F8; } }  /* 0x8009C5D8 */
    R[2] = R[4] + 256;  /* 0x8009C5E0 */
    R[2] = R[2] & 0x1FF;  /* 0x8009C5E4 */
    { uint32_t _c = (R[2] != R[20]); R[2] = R[0] - 1; if (_c) { goto L_8009C5F8; } }  /* 0x8009C5E8 */
L_8009C5F0:;
    { sh_(R[19] + 88, R[23]); goto L_8009C5FC; }  /* 0x8009C5F0 j */
L_8009C5F8:;
    sh_(R[19] + 88, R[2]);  /* 0x8009C5F8 */
L_8009C5FC:;
    { sh_(R[19] + 82, R[0]); goto L_8009C624; }  /* 0x8009C5FC j */
L_8009C604:;
    R[4] = R[18] + R[0];  /* 0x8009C604 */
    sh_(R[19] + 82, R[0]);  /* 0x8009C608 */
    { R[31] = 0x8009C614u; sw_(R[19] + 92, R[0]); psx_next = 0x8009BC84u; return; }  /* 0x8009C60C jal */
L_8009C614:;
    R[2] = lb_(R[18] + 496);  /* 0x8009C614 */
    R[21] = R[21] + 1;  /* 0x8009C618 */
    { uint32_t _c = (R[21] != R[2]); R[5] = 0xBu << 16; if (_c) { psx_bb(); goto L_8009C40C; } }  /* 0x8009C61C */
L_8009C624:;
    R[2] = R[0] + R[0];  /* 0x8009C624 */
L_8009C628:;
    R[31] = lw_(R[29] + 52);  /* 0x8009C628 */
    R[30] = lw_(R[29] + 48);  /* 0x8009C62C */
    R[23] = lw_(R[29] + 44);  /* 0x8009C630 */
    R[22] = lw_(R[29] + 40);  /* 0x8009C634 */
    R[21] = lw_(R[29] + 36);  /* 0x8009C638 */
    R[20] = lw_(R[29] + 32);  /* 0x8009C63C */
    R[19] = lw_(R[29] + 28);  /* 0x8009C640 */
    R[18] = lw_(R[29] + 24);  /* 0x8009C644 */
    R[17] = lw_(R[29] + 20);  /* 0x8009C648 */
    R[16] = lw_(R[29] + 16);  /* 0x8009C64C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x8009C650 jr ra */
}

void g0_8009C40C(void) {
L_8009C40C:;
    R[2] = R[21] << 2;  /* 0x8009C40C */
    R[2] = R[18] + R[2];  /* 0x8009C410 */
    R[5] = R[5] | 0x4000;  /* 0x8009C414 */
    R[17] = lw_(R[2] + 500);  /* 0x8009C418 */
    R[3] = lw_(R[18] + 24);  /* 0x8009C41C */
    R[2] = lw_(R[17] + 24);  /* 0x8009C420 */
    R[4] = lw_(R[17] + 32);  /* 0x8009C424 */
    R[3] = R[3] - R[2];  /* 0x8009C428 */
    R[2] = lw_(R[18] + 32);  /* 0x8009C42C */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_8009C43C; } }  /* 0x8009C430 */
    R[3] = R[0] - R[3];  /* 0x8009C438 */
L_8009C43C:;
    R[2] = R[2] - R[4];  /* 0x8009C43C */
    { uint32_t _c = ((int32_t)R[2] >= 0); if (_c) { goto L_8009C44C; } }  /* 0x8009C440 */
    R[2] = R[0] - R[2];  /* 0x8009C448 */
L_8009C44C:;
    R[3] = R[3] + R[2];  /* 0x8009C44C */
    R[5] = ((int32_t)R[5] < (int32_t)R[3]);  /* 0x8009C450 */
    { uint32_t _c = (R[5] != R[0]); R[2] = 0x1u << 16; if (_c) { goto L_8009C614; } }  /* 0x8009C454 */
    R[3] = lw_(R[18] + 28);  /* 0x8009C45C */
    R[4] = lw_(R[17] + 28);  /* 0x8009C460 */
    R[2] = R[2] | 0x4000;  /* 0x8009C464 */
    R[3] = R[3] - R[4];  /* 0x8009C468 */
    { uint32_t _c = ((int32_t)R[3] >= 0); if (_c) { goto L_8009C478; } }  /* 0x8009C46C */
    R[3] = R[0] - R[3];  /* 0x8009C474 */
L_8009C478:;
    R[2] = ((int32_t)R[2] < (int32_t)R[3]);  /* 0x8009C478 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009C614; } }  /* 0x8009C47C */
    R[2] = lh_(R[17] + 12);  /* 0x8009C484 */
    R[2] = R[2] - 7;  /* 0x8009C48C */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x8009C490 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009C614; } }  /* 0x8009C494 */
    R[2] = lw_(R[17] + 584);  /* 0x8009C49C */
    { uint32_t _c = (R[2] != R[0]); R[6] = R[0] + 99; if (_c) { goto L_8009C614; } }  /* 0x8009C4A4 */
    R[2] = (uint32_t)(int16_t)lh_(R[18] + 20);  /* 0x8009C4AC */
    { uint32_t _c = (R[2] == R[6]); R[4] = R[18] + R[0]; if (_c) { goto L_8009C510; } }  /* 0x8009C4B4 */
    R[16] = (uint32_t)(int16_t)lh_(R[18] + 4);  /* 0x8009C4BC */
    { R[31] = 0x8009C4C8u; R[5] = R[17] + R[0]; psx_next = 0x8008DAFCu; return; }  /* 0x8009C4C0 jal */
    { uint32_t _c = (R[16] != R[2]); if (_c) { goto L_8009C614; } }  /* 0x8009C4C8 */
    R[2] = lh_(R[30] + 4);  /* 0x8009C4D0 */
    R[3] = lh_(R[22] + 2920);  /* 0x8009C4D4 */
    R[2] = R[2] & R[3];  /* 0x8009C4DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] - 1; if (_c) { goto L_8009C614; } }  /* 0x8009C4E0 */
    sh_(R[19] + 82, R[0]);  /* 0x8009C4E8 */
    sw_(R[19] + 92, R[17]);  /* 0x8009C4EC */
    sh_(R[19] + 88, R[2]);  /* 0x8009C4F0 */
    R[6] = R[0] + 99;  /* 0x8009C4F4 */
    sh_(R[18] + 20, R[6]);  /* 0x8009C4F8 */
    R[3] = lh_(R[22] + 2912);  /* 0x8009C4FC */
    R[2] = R[0] + 1;  /* 0x8009C500 */
    R[3] = R[3] & 0xFFFE;  /* 0x8009C504 */
    { sh_(R[22] + 2912, R[3]); goto L_8009C628; }  /* 0x8009C508 j */
L_8009C510:;
    R[2] = lh_(R[30] + 2);  /* 0x8009C510 */
    R[3] = lh_(R[22] + 2920);  /* 0x8009C514 */
    R[2] = R[2] & R[3];  /* 0x8009C51C */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009C604; } }  /* 0x8009C520 */
    { R[31] = 0x8009C530u; R[5] = R[17] + R[0]; psx_next = 0x8008DAFCu; return; }  /* 0x8009C528 jal */
    { uint32_t _c = ((int32_t)R[20] < 0); R[3] = R[2] + R[0]; if (_c) { goto L_8009C5FC; } }  /* 0x8009C530 */
    R[2] = (uint32_t)(int16_t)lh_(R[19] + 88);  /* 0x8009C538 */
    { uint32_t _c = (R[20] != R[2]); R[2] = R[3] << 16; if (_c) { goto L_8009C5C4; } }  /* 0x8009C540 */
    R[2] = lh_(R[19] + 82);  /* 0x8009C548 */
    R[2] = R[2] + 1;  /* 0x8009C550 */
    sh_(R[19] + 82, R[2]);  /* 0x8009C554 */
    R[2] = R[2] << 16;  /* 0x8009C558 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009C55C */
    R[2] = ((int32_t)R[2] < 15);  /* 0x8009C560 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] << 16; if (_c) { goto L_8009C624; } }  /* 0x8009C564 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009C56C */
    { uint32_t _c = (R[2] != R[20]); R[2] = R[0] + 94; if (_c) { goto L_8009C57C; } }  /* 0x8009C570 */
    R[2] = R[0] + 129;  /* 0x8009C578 */
L_8009C57C:;
    sh_(R[17] + 20, R[2]);  /* 0x8009C57C */
    sh_(R[18] + 20, R[2]);  /* 0x8009C580 */
    R[5] = lh_(R[18] + 2);  /* 0x8009C584 */
    { R[31] = 0x8009C590u; R[4] = R[0] + 20; psx_next = 0x8002DAE8u; return; }  /* 0x8009C588 jal */
    R[5] = lh_(R[18] + 2);  /* 0x8009C590 */
    { R[31] = 0x8009C59Cu; R[4] = R[0] + 50; psx_next = 0x8002DAE8u; return; }  /* 0x8009C594 jal */
    R[3] = lb_(R[18] + 781);  /* 0x8009C59C */
    R[2] = R[0] + 1;  /* 0x8009C5A0 */
    R[3] = R[3] | 0x80;  /* 0x8009C5A4 */
    sb_(R[18] + 781, R[3]);  /* 0x8009C5A8 */
    sw_(R[19] + 84, R[0]);  /* 0x8009C5AC */
    R[4] = lh_(R[18] + 6);  /* 0x8009C5B0 */
    R[3] = R[2] + R[0];  /* 0x8009C5B4 */
    sw_(R[17] + 584, R[3]);  /* 0x8009C5B8 */
    { sh_(R[17] + 6, R[4]); goto L_8009C628; }  /* 0x8009C5BC j */
L_8009C5C4:;
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009C5C4 */
    { uint32_t _c = (R[4] == R[20]); R[2] = R[0] + 8; if (_c) { goto L_8009C5F0; } }  /* 0x8009C5C8 */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 12);  /* 0x8009C5D0 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] - 1; if (_c) { goto L_8009C5F8; } }  /* 0x8009C5D8 */
    R[2] = R[4] + 256;  /* 0x8009C5E0 */
    R[2] = R[2] & 0x1FF;  /* 0x8009C5E4 */
    { uint32_t _c = (R[2] != R[20]); R[2] = R[0] - 1; if (_c) { goto L_8009C5F8; } }  /* 0x8009C5E8 */
L_8009C5F0:;
    { sh_(R[19] + 88, R[23]); goto L_8009C5FC; }  /* 0x8009C5F0 j */
L_8009C5F8:;
    sh_(R[19] + 88, R[2]);  /* 0x8009C5F8 */
L_8009C5FC:;
    { sh_(R[19] + 82, R[0]); goto L_8009C624; }  /* 0x8009C5FC j */
L_8009C604:;
    R[4] = R[18] + R[0];  /* 0x8009C604 */
    sh_(R[19] + 82, R[0]);  /* 0x8009C608 */
    { R[31] = 0x8009C614u; sw_(R[19] + 92, R[0]); psx_next = 0x8009BC84u; return; }  /* 0x8009C60C jal */
L_8009C614:;
    R[2] = lb_(R[18] + 496);  /* 0x8009C614 */
    R[21] = R[21] + 1;  /* 0x8009C618 */
    { uint32_t _c = (R[21] != R[2]); R[5] = 0xBu << 16; if (_c) { psx_bb(); goto L_8009C40C; } }  /* 0x8009C61C */
L_8009C624:;
    R[2] = R[0] + R[0];  /* 0x8009C624 */
L_8009C628:;
    R[31] = lw_(R[29] + 52);  /* 0x8009C628 */
    R[30] = lw_(R[29] + 48);  /* 0x8009C62C */
    R[23] = lw_(R[29] + 44);  /* 0x8009C630 */
    R[22] = lw_(R[29] + 40);  /* 0x8009C634 */
    R[21] = lw_(R[29] + 36);  /* 0x8009C638 */
    R[20] = lw_(R[29] + 32);  /* 0x8009C63C */
    R[19] = lw_(R[29] + 28);  /* 0x8009C640 */
    R[18] = lw_(R[29] + 24);  /* 0x8009C644 */
    R[17] = lw_(R[29] + 20);  /* 0x8009C648 */
    R[16] = lw_(R[29] + 16);  /* 0x8009C64C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x8009C650 jr ra */
}

void g0_8009C4C8(void) {
    { uint32_t _c = (R[16] != R[2]); if (_c) { goto L_8009C614; } }  /* 0x8009C4C8 */
    R[2] = lh_(R[30] + 4);  /* 0x8009C4D0 */
    R[3] = lh_(R[22] + 2920);  /* 0x8009C4D4 */
    R[2] = R[2] & R[3];  /* 0x8009C4DC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] - 1; if (_c) { goto L_8009C614; } }  /* 0x8009C4E0 */
    sh_(R[19] + 82, R[0]);  /* 0x8009C4E8 */
    sw_(R[19] + 92, R[17]);  /* 0x8009C4EC */
    sh_(R[19] + 88, R[2]);  /* 0x8009C4F0 */
    R[6] = R[0] + 99;  /* 0x8009C4F4 */
    sh_(R[18] + 20, R[6]);  /* 0x8009C4F8 */
    R[3] = lh_(R[22] + 2912);  /* 0x8009C4FC */
    R[2] = R[0] + 1;  /* 0x8009C500 */
    R[3] = R[3] & 0xFFFE;  /* 0x8009C504 */
    { sh_(R[22] + 2912, R[3]); goto L_8009C628; }  /* 0x8009C508 j */
    R[2] = lh_(R[30] + 2);  /* 0x8009C510 */
    R[3] = lh_(R[22] + 2920);  /* 0x8009C514 */
    R[2] = R[2] & R[3];  /* 0x8009C51C */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[0] + 5; if (_c) { goto L_8009C604; } }  /* 0x8009C520 */
    { R[31] = 0x8009C530u; R[5] = R[17] + R[0]; psx_next = 0x8008DAFCu; return; }  /* 0x8009C528 jal */
    { uint32_t _c = ((int32_t)R[20] < 0); R[3] = R[2] + R[0]; if (_c) { goto L_8009C5FC; } }  /* 0x8009C530 */
    R[2] = (uint32_t)(int16_t)lh_(R[19] + 88);  /* 0x8009C538 */
    { uint32_t _c = (R[20] != R[2]); R[2] = R[3] << 16; if (_c) { goto L_8009C5C4; } }  /* 0x8009C540 */
    R[2] = lh_(R[19] + 82);  /* 0x8009C548 */
    R[2] = R[2] + 1;  /* 0x8009C550 */
    sh_(R[19] + 82, R[2]);  /* 0x8009C554 */
    R[2] = R[2] << 16;  /* 0x8009C558 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009C55C */
    R[2] = ((int32_t)R[2] < 15);  /* 0x8009C560 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] << 16; if (_c) { goto L_8009C624; } }  /* 0x8009C564 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009C56C */
    { uint32_t _c = (R[2] != R[20]); R[2] = R[0] + 94; if (_c) { goto L_8009C57C; } }  /* 0x8009C570 */
    R[2] = R[0] + 129;  /* 0x8009C578 */
L_8009C57C:;
    sh_(R[17] + 20, R[2]);  /* 0x8009C57C */
    sh_(R[18] + 20, R[2]);  /* 0x8009C580 */
    R[5] = lh_(R[18] + 2);  /* 0x8009C584 */
    { R[31] = 0x8009C590u; R[4] = R[0] + 20; psx_next = 0x8002DAE8u; return; }  /* 0x8009C588 jal */
    R[5] = lh_(R[18] + 2);  /* 0x8009C590 */
    { R[31] = 0x8009C59Cu; R[4] = R[0] + 50; psx_next = 0x8002DAE8u; return; }  /* 0x8009C594 jal */
    R[3] = lb_(R[18] + 781);  /* 0x8009C59C */
    R[2] = R[0] + 1;  /* 0x8009C5A0 */
    R[3] = R[3] | 0x80;  /* 0x8009C5A4 */
    sb_(R[18] + 781, R[3]);  /* 0x8009C5A8 */
    sw_(R[19] + 84, R[0]);  /* 0x8009C5AC */
    R[4] = lh_(R[18] + 6);  /* 0x8009C5B0 */
    R[3] = R[2] + R[0];  /* 0x8009C5B4 */
    sw_(R[17] + 584, R[3]);  /* 0x8009C5B8 */
    { sh_(R[17] + 6, R[4]); goto L_8009C628; }  /* 0x8009C5BC j */
L_8009C5C4:;
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009C5C4 */
    { uint32_t _c = (R[4] == R[20]); R[2] = R[0] + 8; if (_c) { goto L_8009C5F0; } }  /* 0x8009C5C8 */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 12);  /* 0x8009C5D0 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] - 1; if (_c) { goto L_8009C5F8; } }  /* 0x8009C5D8 */
    R[2] = R[4] + 256;  /* 0x8009C5E0 */
    R[2] = R[2] & 0x1FF;  /* 0x8009C5E4 */
    { uint32_t _c = (R[2] != R[20]); R[2] = R[0] - 1; if (_c) { goto L_8009C5F8; } }  /* 0x8009C5E8 */
L_8009C5F0:;
    { sh_(R[19] + 88, R[23]); goto L_8009C5FC; }  /* 0x8009C5F0 j */
L_8009C5F8:;
    sh_(R[19] + 88, R[2]);  /* 0x8009C5F8 */
L_8009C5FC:;
    { sh_(R[19] + 82, R[0]); goto L_8009C624; }  /* 0x8009C5FC j */
L_8009C604:;
    R[4] = R[18] + R[0];  /* 0x8009C604 */
    sh_(R[19] + 82, R[0]);  /* 0x8009C608 */
    { R[31] = 0x8009C614u; sw_(R[19] + 92, R[0]); psx_next = 0x8009BC84u; return; }  /* 0x8009C60C jal */
L_8009C614:;
    R[2] = lb_(R[18] + 496);  /* 0x8009C614 */
    R[21] = R[21] + 1;  /* 0x8009C618 */
    { uint32_t _c = (R[21] != R[2]); R[5] = 0xBu << 16; if (_c) { psx_next = 0x8009C40Cu; return; } }  /* 0x8009C61C b extern */
L_8009C624:;
    R[2] = R[0] + R[0];  /* 0x8009C624 */
L_8009C628:;
    R[31] = lw_(R[29] + 52);  /* 0x8009C628 */
    R[30] = lw_(R[29] + 48);  /* 0x8009C62C */
    R[23] = lw_(R[29] + 44);  /* 0x8009C630 */
    R[22] = lw_(R[29] + 40);  /* 0x8009C634 */
    R[21] = lw_(R[29] + 36);  /* 0x8009C638 */
    R[20] = lw_(R[29] + 32);  /* 0x8009C63C */
    R[19] = lw_(R[29] + 28);  /* 0x8009C640 */
    R[18] = lw_(R[29] + 24);  /* 0x8009C644 */
    R[17] = lw_(R[29] + 20);  /* 0x8009C648 */
    R[16] = lw_(R[29] + 16);  /* 0x8009C64C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x8009C650 jr ra */
}

void g0_8009C530(void) {
    { uint32_t _c = ((int32_t)R[20] < 0); R[3] = R[2] + R[0]; if (_c) { goto L_8009C5FC; } }  /* 0x8009C530 */
    R[2] = (uint32_t)(int16_t)lh_(R[19] + 88);  /* 0x8009C538 */
    { uint32_t _c = (R[20] != R[2]); R[2] = R[3] << 16; if (_c) { goto L_8009C5C4; } }  /* 0x8009C540 */
    R[2] = lh_(R[19] + 82);  /* 0x8009C548 */
    R[2] = R[2] + 1;  /* 0x8009C550 */
    sh_(R[19] + 82, R[2]);  /* 0x8009C554 */
    R[2] = R[2] << 16;  /* 0x8009C558 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009C55C */
    R[2] = ((int32_t)R[2] < 15);  /* 0x8009C560 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] << 16; if (_c) { goto L_8009C624; } }  /* 0x8009C564 */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009C56C */
    { uint32_t _c = (R[2] != R[20]); R[2] = R[0] + 94; if (_c) { goto L_8009C57C; } }  /* 0x8009C570 */
    R[2] = R[0] + 129;  /* 0x8009C578 */
L_8009C57C:;
    sh_(R[17] + 20, R[2]);  /* 0x8009C57C */
    sh_(R[18] + 20, R[2]);  /* 0x8009C580 */
    R[5] = lh_(R[18] + 2);  /* 0x8009C584 */
    { R[31] = 0x8009C590u; R[4] = R[0] + 20; psx_next = 0x8002DAE8u; return; }  /* 0x8009C588 jal */
    R[5] = lh_(R[18] + 2);  /* 0x8009C590 */
    { R[31] = 0x8009C59Cu; R[4] = R[0] + 50; psx_next = 0x8002DAE8u; return; }  /* 0x8009C594 jal */
    R[3] = lb_(R[18] + 781);  /* 0x8009C59C */
    R[2] = R[0] + 1;  /* 0x8009C5A0 */
    R[3] = R[3] | 0x80;  /* 0x8009C5A4 */
    sb_(R[18] + 781, R[3]);  /* 0x8009C5A8 */
    sw_(R[19] + 84, R[0]);  /* 0x8009C5AC */
    R[4] = lh_(R[18] + 6);  /* 0x8009C5B0 */
    R[3] = R[2] + R[0];  /* 0x8009C5B4 */
    sw_(R[17] + 584, R[3]);  /* 0x8009C5B8 */
    { sh_(R[17] + 6, R[4]); goto L_8009C628; }  /* 0x8009C5BC j */
L_8009C5C4:;
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009C5C4 */
    { uint32_t _c = (R[4] == R[20]); R[2] = R[0] + 8; if (_c) { goto L_8009C5F0; } }  /* 0x8009C5C8 */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 12);  /* 0x8009C5D0 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] - 1; if (_c) { goto L_8009C5F8; } }  /* 0x8009C5D8 */
    R[2] = R[4] + 256;  /* 0x8009C5E0 */
    R[2] = R[2] & 0x1FF;  /* 0x8009C5E4 */
    { uint32_t _c = (R[2] != R[20]); R[2] = R[0] - 1; if (_c) { goto L_8009C5F8; } }  /* 0x8009C5E8 */
L_8009C5F0:;
    { sh_(R[19] + 88, R[23]); goto L_8009C5FC; }  /* 0x8009C5F0 j */
L_8009C5F8:;
    sh_(R[19] + 88, R[2]);  /* 0x8009C5F8 */
L_8009C5FC:;
    { sh_(R[19] + 82, R[0]); goto L_8009C624; }  /* 0x8009C5FC j */
    R[4] = R[18] + R[0];  /* 0x8009C604 */
    sh_(R[19] + 82, R[0]);  /* 0x8009C608 */
    { R[31] = 0x8009C614u; sw_(R[19] + 92, R[0]); psx_next = 0x8009BC84u; return; }  /* 0x8009C60C jal */
    R[2] = lb_(R[18] + 496);  /* 0x8009C614 */
    R[21] = R[21] + 1;  /* 0x8009C618 */
    { uint32_t _c = (R[21] != R[2]); R[5] = 0xBu << 16; if (_c) { psx_next = 0x8009C40Cu; return; } }  /* 0x8009C61C b extern */
L_8009C624:;
    R[2] = R[0] + R[0];  /* 0x8009C624 */
L_8009C628:;
    R[31] = lw_(R[29] + 52);  /* 0x8009C628 */
    R[30] = lw_(R[29] + 48);  /* 0x8009C62C */
    R[23] = lw_(R[29] + 44);  /* 0x8009C630 */
    R[22] = lw_(R[29] + 40);  /* 0x8009C634 */
    R[21] = lw_(R[29] + 36);  /* 0x8009C638 */
    R[20] = lw_(R[29] + 32);  /* 0x8009C63C */
    R[19] = lw_(R[29] + 28);  /* 0x8009C640 */
    R[18] = lw_(R[29] + 24);  /* 0x8009C644 */
    R[17] = lw_(R[29] + 20);  /* 0x8009C648 */
    R[16] = lw_(R[29] + 16);  /* 0x8009C64C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x8009C650 jr ra */
}

void g0_8009C590(void) {
    R[5] = lh_(R[18] + 2);  /* 0x8009C590 */
    { R[31] = 0x8009C59Cu; R[4] = R[0] + 50; psx_next = 0x8002DAE8u; return; }  /* 0x8009C594 jal */
    R[3] = lb_(R[18] + 781);  /* 0x8009C59C */
    R[2] = R[0] + 1;  /* 0x8009C5A0 */
    R[3] = R[3] | 0x80;  /* 0x8009C5A4 */
    sb_(R[18] + 781, R[3]);  /* 0x8009C5A8 */
    sw_(R[19] + 84, R[0]);  /* 0x8009C5AC */
    R[4] = lh_(R[18] + 6);  /* 0x8009C5B0 */
    R[3] = R[2] + R[0];  /* 0x8009C5B4 */
    sw_(R[17] + 584, R[3]);  /* 0x8009C5B8 */
    { sh_(R[17] + 6, R[4]); goto L_8009C628; }  /* 0x8009C5BC j */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009C5C4 */
    { uint32_t _c = (R[4] == R[20]); R[2] = R[0] + 8; if (_c) { goto L_8009C5F0; } }  /* 0x8009C5C8 */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 12);  /* 0x8009C5D0 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] - 1; if (_c) { goto L_8009C5F8; } }  /* 0x8009C5D8 */
    R[2] = R[4] + 256;  /* 0x8009C5E0 */
    R[2] = R[2] & 0x1FF;  /* 0x8009C5E4 */
    { uint32_t _c = (R[2] != R[20]); R[2] = R[0] - 1; if (_c) { goto L_8009C5F8; } }  /* 0x8009C5E8 */
L_8009C5F0:;
    { sh_(R[19] + 88, R[23]); goto L_8009C5FC; }  /* 0x8009C5F0 j */
L_8009C5F8:;
    sh_(R[19] + 88, R[2]);  /* 0x8009C5F8 */
L_8009C5FC:;
    { sh_(R[19] + 82, R[0]); goto L_8009C624; }  /* 0x8009C5FC j */
    R[4] = R[18] + R[0];  /* 0x8009C604 */
    sh_(R[19] + 82, R[0]);  /* 0x8009C608 */
    { R[31] = 0x8009C614u; sw_(R[19] + 92, R[0]); psx_next = 0x8009BC84u; return; }  /* 0x8009C60C jal */
    R[2] = lb_(R[18] + 496);  /* 0x8009C614 */
    R[21] = R[21] + 1;  /* 0x8009C618 */
    { uint32_t _c = (R[21] != R[2]); R[5] = 0xBu << 16; if (_c) { psx_next = 0x8009C40Cu; return; } }  /* 0x8009C61C b extern */
L_8009C624:;
    R[2] = R[0] + R[0];  /* 0x8009C624 */
L_8009C628:;
    R[31] = lw_(R[29] + 52);  /* 0x8009C628 */
    R[30] = lw_(R[29] + 48);  /* 0x8009C62C */
    R[23] = lw_(R[29] + 44);  /* 0x8009C630 */
    R[22] = lw_(R[29] + 40);  /* 0x8009C634 */
    R[21] = lw_(R[29] + 36);  /* 0x8009C638 */
    R[20] = lw_(R[29] + 32);  /* 0x8009C63C */
    R[19] = lw_(R[29] + 28);  /* 0x8009C640 */
    R[18] = lw_(R[29] + 24);  /* 0x8009C644 */
    R[17] = lw_(R[29] + 20);  /* 0x8009C648 */
    R[16] = lw_(R[29] + 16);  /* 0x8009C64C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x8009C650 jr ra */
}

void g0_8009C59C(void) {
    R[3] = lb_(R[18] + 781);  /* 0x8009C59C */
    R[2] = R[0] + 1;  /* 0x8009C5A0 */
    R[3] = R[3] | 0x80;  /* 0x8009C5A4 */
    sb_(R[18] + 781, R[3]);  /* 0x8009C5A8 */
    sw_(R[19] + 84, R[0]);  /* 0x8009C5AC */
    R[4] = lh_(R[18] + 6);  /* 0x8009C5B0 */
    R[3] = R[2] + R[0];  /* 0x8009C5B4 */
    sw_(R[17] + 584, R[3]);  /* 0x8009C5B8 */
    { sh_(R[17] + 6, R[4]); goto L_8009C628; }  /* 0x8009C5BC j */
    R[4] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009C5C4 */
    { uint32_t _c = (R[4] == R[20]); R[2] = R[0] + 8; if (_c) { goto L_8009C5F0; } }  /* 0x8009C5C8 */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + 12);  /* 0x8009C5D0 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] - 1; if (_c) { goto L_8009C5F8; } }  /* 0x8009C5D8 */
    R[2] = R[4] + 256;  /* 0x8009C5E0 */
    R[2] = R[2] & 0x1FF;  /* 0x8009C5E4 */
    { uint32_t _c = (R[2] != R[20]); R[2] = R[0] - 1; if (_c) { goto L_8009C5F8; } }  /* 0x8009C5E8 */
L_8009C5F0:;
    { sh_(R[19] + 88, R[23]); goto L_8009C5FC; }  /* 0x8009C5F0 j */
L_8009C5F8:;
    sh_(R[19] + 88, R[2]);  /* 0x8009C5F8 */
L_8009C5FC:;
    { sh_(R[19] + 82, R[0]); goto L_8009C624; }  /* 0x8009C5FC j */
    R[4] = R[18] + R[0];  /* 0x8009C604 */
    sh_(R[19] + 82, R[0]);  /* 0x8009C608 */
    { R[31] = 0x8009C614u; sw_(R[19] + 92, R[0]); psx_next = 0x8009BC84u; return; }  /* 0x8009C60C jal */
    R[2] = lb_(R[18] + 496);  /* 0x8009C614 */
    R[21] = R[21] + 1;  /* 0x8009C618 */
    { uint32_t _c = (R[21] != R[2]); R[5] = 0xBu << 16; if (_c) { psx_next = 0x8009C40Cu; return; } }  /* 0x8009C61C b extern */
L_8009C624:;
    R[2] = R[0] + R[0];  /* 0x8009C624 */
L_8009C628:;
    R[31] = lw_(R[29] + 52);  /* 0x8009C628 */
    R[30] = lw_(R[29] + 48);  /* 0x8009C62C */
    R[23] = lw_(R[29] + 44);  /* 0x8009C630 */
    R[22] = lw_(R[29] + 40);  /* 0x8009C634 */
    R[21] = lw_(R[29] + 36);  /* 0x8009C638 */
    R[20] = lw_(R[29] + 32);  /* 0x8009C63C */
    R[19] = lw_(R[29] + 28);  /* 0x8009C640 */
    R[18] = lw_(R[29] + 24);  /* 0x8009C644 */
    R[17] = lw_(R[29] + 20);  /* 0x8009C648 */
    R[16] = lw_(R[29] + 16);  /* 0x8009C64C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x8009C650 jr ra */
}

void g0_8009C614(void) {
    R[2] = lb_(R[18] + 496);  /* 0x8009C614 */
    R[21] = R[21] + 1;  /* 0x8009C618 */
    { uint32_t _c = (R[21] != R[2]); R[5] = 0xBu << 16; if (_c) { psx_next = 0x8009C40Cu; return; } }  /* 0x8009C61C b extern */
    R[2] = R[0] + R[0];  /* 0x8009C624 */
    R[31] = lw_(R[29] + 52);  /* 0x8009C628 */
    R[30] = lw_(R[29] + 48);  /* 0x8009C62C */
    R[23] = lw_(R[29] + 44);  /* 0x8009C630 */
    R[22] = lw_(R[29] + 40);  /* 0x8009C634 */
    R[21] = lw_(R[29] + 36);  /* 0x8009C638 */
    R[20] = lw_(R[29] + 32);  /* 0x8009C63C */
    R[19] = lw_(R[29] + 28);  /* 0x8009C640 */
    R[18] = lw_(R[29] + 24);  /* 0x8009C644 */
    R[17] = lw_(R[29] + 20);  /* 0x8009C648 */
    R[16] = lw_(R[29] + 16);  /* 0x8009C64C */
    { R[29] = R[29] + 56; psx_next = R[31]; return; }  /* 0x8009C650 jr ra */
}

void g0_8009C658(void) {
    R[29] = R[29] - 24;  /* 0x8009C658 */
    sw_(R[29] + 16, R[16]);  /* 0x8009C65C */
    R[16] = R[4] + R[0];  /* 0x8009C660 */
    sw_(R[29] + 20, R[31]);  /* 0x8009C664 */
    R[2] = lb_(R[16] + 797);  /* 0x8009C668 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009C730; } }  /* 0x8009C670 */
    R[2] = lh_(R[16] + 88);  /* 0x8009C678 */
    R[2] = R[2] & 0x1000;  /* 0x8009C680 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009C730; } }  /* 0x8009C684 */
    R[3] = lb_(R[16] + 789);  /* 0x8009C68C */
    R[2] = R[3] & 0x1;  /* 0x8009C694 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x2; if (_c) { goto L_8009C730; } }  /* 0x8009C698 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 5; if (_c) { goto L_8009C730; } }  /* 0x8009C6A0 */
    R[3] = lb_(R[16] + 791);  /* 0x8009C6A8 */
    { uint32_t _c = (R[3] == R[2]); if (_c) { goto L_8009C730; } }  /* 0x8009C6B0 */
    { R[31] = 0x8009C6C0u; R[5] = R[0] + 1024; psx_next = 0x8008933Cu; return; }  /* 0x8009C6B8 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 18; if (_c) { goto L_8009C6F0; } }  /* 0x8009C6C0 */
    R[4] = R[16] + R[0];  /* 0x8009C6C8 */
    { R[31] = 0x8009C6D4u; R[5] = R[0] + 256; psx_next = 0x8008933Cu; return; }  /* 0x8009C6CC jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009C708; } }  /* 0x8009C6D4 */
    { R[31] = 0x8009C6E4u; psx_next = 0x80023DC4u; return; }  /* 0x8009C6DC jal */
    R[3] = R[0] + 23;  /* 0x8009C6E4 */
    { uint32_t _c = (R[2] == R[3]); R[4] = R[0] + 65; if (_c) { goto L_8009C730; } }  /* 0x8009C6E8 */
L_8009C6F0:;
    R[5] = lh_(R[16] + 2);  /* 0x8009C6F0 */
    R[2] = R[0] + 4;  /* 0x8009C6F4 */
    { R[31] = 0x8009C700u; sb_(R[16] + 787, R[2]); psx_next = 0x8002DAE8u; return; }  /* 0x8009C6F8 jal */
    { goto L_8009C730; }  /* 0x8009C700 j */
L_8009C708:;
    { R[31] = 0x8009C710u; psx_next = 0x80023DC4u; return; }  /* 0x8009C708 jal */
    R[3] = R[0] + 26;  /* 0x8009C710 */
    { uint32_t _c = (R[2] == R[3]); R[4] = R[16] + R[0]; if (_c) { goto L_8009C730; } }  /* 0x8009C714 */
    { R[31] = 0x8009C724u; R[5] = R[0] + 8192; psx_next = 0x8008933Cu; return; }  /* 0x8009C71C jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 4; if (_c) { goto L_8009C730; } }  /* 0x8009C724 */
    sb_(R[16] + 787, R[2]);  /* 0x8009C72C */
L_8009C730:;
    R[31] = lw_(R[29] + 20);  /* 0x8009C730 */
    R[16] = lw_(R[29] + 16);  /* 0x8009C734 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009C738 jr ra */
}

void g0_8009C6C0(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[0] + 18; if (_c) { goto L_8009C6F0; } }  /* 0x8009C6C0 */
    R[4] = R[16] + R[0];  /* 0x8009C6C8 */
    { R[31] = 0x8009C6D4u; R[5] = R[0] + 256; psx_next = 0x8008933Cu; return; }  /* 0x8009C6CC jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009C708; } }  /* 0x8009C6D4 */
    { R[31] = 0x8009C6E4u; psx_next = 0x80023DC4u; return; }  /* 0x8009C6DC jal */
    R[3] = R[0] + 23;  /* 0x8009C6E4 */
    { uint32_t _c = (R[2] == R[3]); R[4] = R[0] + 65; if (_c) { goto L_8009C730; } }  /* 0x8009C6E8 */
L_8009C6F0:;
    R[5] = lh_(R[16] + 2);  /* 0x8009C6F0 */
    R[2] = R[0] + 4;  /* 0x8009C6F4 */
    { R[31] = 0x8009C700u; sb_(R[16] + 787, R[2]); psx_next = 0x8002DAE8u; return; }  /* 0x8009C6F8 jal */
    { goto L_8009C730; }  /* 0x8009C700 j */
L_8009C708:;
    { R[31] = 0x8009C710u; psx_next = 0x80023DC4u; return; }  /* 0x8009C708 jal */
    R[3] = R[0] + 26;  /* 0x8009C710 */
    { uint32_t _c = (R[2] == R[3]); R[4] = R[16] + R[0]; if (_c) { goto L_8009C730; } }  /* 0x8009C714 */
    { R[31] = 0x8009C724u; R[5] = R[0] + 8192; psx_next = 0x8008933Cu; return; }  /* 0x8009C71C jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 4; if (_c) { goto L_8009C730; } }  /* 0x8009C724 */
    sb_(R[16] + 787, R[2]);  /* 0x8009C72C */
L_8009C730:;
    R[31] = lw_(R[29] + 20);  /* 0x8009C730 */
    R[16] = lw_(R[29] + 16);  /* 0x8009C734 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009C738 jr ra */
}

void g0_8009C6D4(void) {
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009C708; } }  /* 0x8009C6D4 */
    { R[31] = 0x8009C6E4u; psx_next = 0x80023DC4u; return; }  /* 0x8009C6DC jal */
    R[3] = R[0] + 23;  /* 0x8009C6E4 */
    { uint32_t _c = (R[2] == R[3]); R[4] = R[0] + 65; if (_c) { goto L_8009C730; } }  /* 0x8009C6E8 */
    R[5] = lh_(R[16] + 2);  /* 0x8009C6F0 */
    R[2] = R[0] + 4;  /* 0x8009C6F4 */
    { R[31] = 0x8009C700u; sb_(R[16] + 787, R[2]); psx_next = 0x8002DAE8u; return; }  /* 0x8009C6F8 jal */
    { goto L_8009C730; }  /* 0x8009C700 j */
L_8009C708:;
    { R[31] = 0x8009C710u; psx_next = 0x80023DC4u; return; }  /* 0x8009C708 jal */
    R[3] = R[0] + 26;  /* 0x8009C710 */
    { uint32_t _c = (R[2] == R[3]); R[4] = R[16] + R[0]; if (_c) { goto L_8009C730; } }  /* 0x8009C714 */
    { R[31] = 0x8009C724u; R[5] = R[0] + 8192; psx_next = 0x8008933Cu; return; }  /* 0x8009C71C jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 4; if (_c) { goto L_8009C730; } }  /* 0x8009C724 */
    sb_(R[16] + 787, R[2]);  /* 0x8009C72C */
L_8009C730:;
    R[31] = lw_(R[29] + 20);  /* 0x8009C730 */
    R[16] = lw_(R[29] + 16);  /* 0x8009C734 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009C738 jr ra */
}

void g0_8009C6E4(void) {
    R[3] = R[0] + 23;  /* 0x8009C6E4 */
    { uint32_t _c = (R[2] == R[3]); R[4] = R[0] + 65; if (_c) { goto L_8009C730; } }  /* 0x8009C6E8 */
    R[5] = lh_(R[16] + 2);  /* 0x8009C6F0 */
    R[2] = R[0] + 4;  /* 0x8009C6F4 */
    { R[31] = 0x8009C700u; sb_(R[16] + 787, R[2]); psx_next = 0x8002DAE8u; return; }  /* 0x8009C6F8 jal */
    { goto L_8009C730; }  /* 0x8009C700 j */
    { R[31] = 0x8009C710u; psx_next = 0x80023DC4u; return; }  /* 0x8009C708 jal */
    R[3] = R[0] + 26;  /* 0x8009C710 */
    { uint32_t _c = (R[2] == R[3]); R[4] = R[16] + R[0]; if (_c) { goto L_8009C730; } }  /* 0x8009C714 */
    { R[31] = 0x8009C724u; R[5] = R[0] + 8192; psx_next = 0x8008933Cu; return; }  /* 0x8009C71C jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 4; if (_c) { goto L_8009C730; } }  /* 0x8009C724 */
    sb_(R[16] + 787, R[2]);  /* 0x8009C72C */
L_8009C730:;
    R[31] = lw_(R[29] + 20);  /* 0x8009C730 */
    R[16] = lw_(R[29] + 16);  /* 0x8009C734 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009C738 jr ra */
}

void g0_8009C700(void) {
    { goto L_8009C730; }  /* 0x8009C700 j */
    { R[31] = 0x8009C710u; psx_next = 0x80023DC4u; return; }  /* 0x8009C708 jal */
    R[3] = R[0] + 26;  /* 0x8009C710 */
    { uint32_t _c = (R[2] == R[3]); R[4] = R[16] + R[0]; if (_c) { goto L_8009C730; } }  /* 0x8009C714 */
    { R[31] = 0x8009C724u; R[5] = R[0] + 8192; psx_next = 0x8008933Cu; return; }  /* 0x8009C71C jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 4; if (_c) { goto L_8009C730; } }  /* 0x8009C724 */
    sb_(R[16] + 787, R[2]);  /* 0x8009C72C */
L_8009C730:;
    R[31] = lw_(R[29] + 20);  /* 0x8009C730 */
    R[16] = lw_(R[29] + 16);  /* 0x8009C734 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009C738 jr ra */
}

void g0_8009C710(void) {
    R[3] = R[0] + 26;  /* 0x8009C710 */
    { uint32_t _c = (R[2] == R[3]); R[4] = R[16] + R[0]; if (_c) { goto L_8009C730; } }  /* 0x8009C714 */
    { R[31] = 0x8009C724u; R[5] = R[0] + 8192; psx_next = 0x8008933Cu; return; }  /* 0x8009C71C jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 4; if (_c) { goto L_8009C730; } }  /* 0x8009C724 */
    sb_(R[16] + 787, R[2]);  /* 0x8009C72C */
L_8009C730:;
    R[31] = lw_(R[29] + 20);  /* 0x8009C730 */
    R[16] = lw_(R[29] + 16);  /* 0x8009C734 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009C738 jr ra */
}

void g0_8009C724(void) {
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 4; if (_c) { goto L_8009C730; } }  /* 0x8009C724 */
    sb_(R[16] + 787, R[2]);  /* 0x8009C72C */
L_8009C730:;
    R[31] = lw_(R[29] + 20);  /* 0x8009C730 */
    R[16] = lw_(R[29] + 16);  /* 0x8009C734 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x8009C738 jr ra */
}

void g0_8009C740(void) {
    R[29] = R[29] - 40;  /* 0x8009C740 */
    sw_(R[29] + 24, R[16]);  /* 0x8009C744 */
    R[16] = R[4] + R[0];  /* 0x8009C748 */
    R[5] = 0x8u << 16;  /* 0x8009C74C */
    R[5] = R[5] | 0x1000;  /* 0x8009C750 */
    sw_(R[29] + 32, R[31]);  /* 0x8009C754 */
    { R[31] = 0x8009C760u; sw_(R[29] + 28, R[17]); psx_next = 0x800893BCu; return; }  /* 0x8009C758 jal */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009C770; } }  /* 0x8009C760 */
    R[2] = R[0] + 1;  /* 0x8009C768 */
    sh_(R[3] + -29644, R[2]);  /* 0x8009C76C */
L_8009C770:;
    R[4] = R[16] + R[0];  /* 0x8009C770 */
    R[5] = 0x8u << 16;  /* 0x8009C774 */
    { R[31] = 0x8009C780u; R[5] = R[5] | 0x800; psx_next = 0x800893BCu; return; }  /* 0x8009C778 jal */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009C79C; } }  /* 0x8009C780 */
    R[2] = R[0] + 1;  /* 0x8009C788 */
    sh_(R[3] + -29644, R[2]);  /* 0x8009C78C */
    R[3] = 0x8006u << 16;  /* 0x8009C790 */
    R[2] = R[0] + 24;  /* 0x8009C794 */
    sh_(R[3] + 16032, R[2]);  /* 0x8009C798 */
L_8009C79C:;
    R[4] = R[16] + R[0];  /* 0x8009C79C */
    R[5] = 0x8u << 16;  /* 0x8009C7A0 */
    { R[31] = 0x8009C7ACu; R[5] = R[5] | 0x800; psx_next = 0x8008933Cu; return; }  /* 0x8009C7A4 jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009C88C; } }  /* 0x8009C7AC */
    R[17] = lb_(R[16] + 784);  /* 0x8009C7B4 */
    { uint32_t _c = (R[17] != R[2]); R[2] = 0x8013u << 16; if (_c) { goto L_8009C890; } }  /* 0x8009C7BC */
    R[2] = lw_(R[16] + 232);  /* 0x8009C7C4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009C7E0; } }  /* 0x8009C7CC */
    R[5] = lh_(R[16] + 2);  /* 0x8009C7D4 */
    { R[31] = 0x8009C7E0u; R[4] = R[0] + 4661; psx_next = 0x8002DAE8u; return; }  /* 0x8009C7D8 jal */
L_8009C7E0:;
    R[2] = lw_(R[16] + 16);  /* 0x8009C7E0 */
    R[3] = R[0] - 897;  /* 0x8009C7E4 */
    sw_(R[16] + 232, R[0]);  /* 0x8009C7E8 */
    R[2] = R[2] & R[3];  /* 0x8009C7EC */
    sw_(R[16] + 16, R[2]);  /* 0x8009C7F0 */
    R[2] = 0x800Fu << 16;  /* 0x8009C7F4 */
    R[3] = lw_(R[2] + 25520);  /* 0x8009C7F8 */
    R[2] = 0x8013u << 16;  /* 0x8009C7FC */
    sh_(R[2] + -29588, R[17]);  /* 0x8009C800 */
    R[2] = R[3] & 0x7;  /* 0x8009C804 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x8; if (_c) { goto L_8009C8C8; } }  /* 0x8009C808 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 4662; if (_c) { goto L_8009C81C; } }  /* 0x8009C810 */
    R[4] = R[0] + 4663;  /* 0x8009C818 */
L_8009C81C:;
    R[5] = lh_(R[16] + 2);  /* 0x8009C81C */
    { R[31] = 0x8009C828u; psx_next = 0x8002DAE8u; return; }  /* 0x8009C820 jal */
    R[4] = 0x2u << 16;  /* 0x8009C828 */
    R[4] = R[4] | 0x4001;  /* 0x8009C82C */
    R[3] = 0x800Fu << 16;  /* 0x8009C830 */
    R[2] = R[0] + 608;  /* 0x8009C834 */
    sh_(R[3] + -21236, R[2]);  /* 0x8009C838 */
    R[3] = R[3] - 21236;  /* 0x8009C83C */
    R[2] = 0x8013u << 16;  /* 0x8009C840 */
    R[2] = R[2] - 29480;  /* 0x8009C844 */
    sw_(R[3] + 4, R[4]);  /* 0x8009C848 */
    R[4] = lw_(R[2] + 132);  /* 0x8009C84C */
    R[5] = lw_(R[2] + 136);  /* 0x8009C850 */
    R[6] = lw_(R[2] + 140);  /* 0x8009C854 */
    R[2] = R[0] + 2;  /* 0x8009C858 */
    sb_(R[3] + 20, R[2]);  /* 0x8009C85C */
    sw_(R[29] + 16, R[3]);  /* 0x8009C860 */
    sw_(R[3] + 28, R[4]);  /* 0x8009C864 */
    sw_(R[3] + 32, R[5]);  /* 0x8009C868 */
    sw_(R[3] + 40, R[6]);  /* 0x8009C86C */
    R[4] = lw_(R[16] + 24);  /* 0x8009C870 */
    R[5] = lw_(R[16] + 28);  /* 0x8009C874 */
    R[6] = lw_(R[16] + 32);  /* 0x8009C878 */
    { R[31] = 0x8009C884u; R[7] = R[0] + 384; psx_next = 0x800889DCu; return; }  /* 0x8009C87C jal */
    { goto L_8009C8C8; }  /* 0x8009C884 j */
L_8009C88C:;
    R[2] = 0x8013u << 16;  /* 0x8009C88C */
L_8009C890:;
    R[4] = R[2] - 29656;  /* 0x8009C890 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 68);  /* 0x8009C894 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Au << 16; if (_c) { goto L_8009C8C8; } }  /* 0x8009C89C */
    R[3] = lw_(R[16] + 16);  /* 0x8009C8A4 */
    R[2] = R[2] + 5568;  /* 0x8009C8A8 */
    sw_(R[16] + 232, R[2]);  /* 0x8009C8AC */
    R[3] = R[3] | 0x80;  /* 0x8009C8B0 */
    sw_(R[16] + 16, R[3]);  /* 0x8009C8B4 */
    sh_(R[4] + 68, R[0]);  /* 0x8009C8B8 */
    R[5] = lh_(R[16] + 2);  /* 0x8009C8BC */
    { R[31] = 0x8009C8C8u; R[4] = R[0] + 4661; psx_next = 0x8002DAE8u; return; }  /* 0x8009C8C0 jal */
L_8009C8C8:;
    R[31] = lw_(R[29] + 32);  /* 0x8009C8C8 */
    R[17] = lw_(R[29] + 28);  /* 0x8009C8CC */
    R[16] = lw_(R[29] + 24);  /* 0x8009C8D0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009C8D4 jr ra */
}

void g0_8009C760(void) {
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009C770; } }  /* 0x8009C760 */
    R[2] = R[0] + 1;  /* 0x8009C768 */
    sh_(R[3] + -29644, R[2]);  /* 0x8009C76C */
L_8009C770:;
    R[4] = R[16] + R[0];  /* 0x8009C770 */
    R[5] = 0x8u << 16;  /* 0x8009C774 */
    { R[31] = 0x8009C780u; R[5] = R[5] | 0x800; psx_next = 0x800893BCu; return; }  /* 0x8009C778 jal */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009C79C; } }  /* 0x8009C780 */
    R[2] = R[0] + 1;  /* 0x8009C788 */
    sh_(R[3] + -29644, R[2]);  /* 0x8009C78C */
    R[3] = 0x8006u << 16;  /* 0x8009C790 */
    R[2] = R[0] + 24;  /* 0x8009C794 */
    sh_(R[3] + 16032, R[2]);  /* 0x8009C798 */
L_8009C79C:;
    R[4] = R[16] + R[0];  /* 0x8009C79C */
    R[5] = 0x8u << 16;  /* 0x8009C7A0 */
    { R[31] = 0x8009C7ACu; R[5] = R[5] | 0x800; psx_next = 0x8008933Cu; return; }  /* 0x8009C7A4 jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009C88C; } }  /* 0x8009C7AC */
    R[17] = lb_(R[16] + 784);  /* 0x8009C7B4 */
    { uint32_t _c = (R[17] != R[2]); R[2] = 0x8013u << 16; if (_c) { goto L_8009C890; } }  /* 0x8009C7BC */
    R[2] = lw_(R[16] + 232);  /* 0x8009C7C4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009C7E0; } }  /* 0x8009C7CC */
    R[5] = lh_(R[16] + 2);  /* 0x8009C7D4 */
    { R[31] = 0x8009C7E0u; R[4] = R[0] + 4661; psx_next = 0x8002DAE8u; return; }  /* 0x8009C7D8 jal */
L_8009C7E0:;
    R[2] = lw_(R[16] + 16);  /* 0x8009C7E0 */
    R[3] = R[0] - 897;  /* 0x8009C7E4 */
    sw_(R[16] + 232, R[0]);  /* 0x8009C7E8 */
    R[2] = R[2] & R[3];  /* 0x8009C7EC */
    sw_(R[16] + 16, R[2]);  /* 0x8009C7F0 */
    R[2] = 0x800Fu << 16;  /* 0x8009C7F4 */
    R[3] = lw_(R[2] + 25520);  /* 0x8009C7F8 */
    R[2] = 0x8013u << 16;  /* 0x8009C7FC */
    sh_(R[2] + -29588, R[17]);  /* 0x8009C800 */
    R[2] = R[3] & 0x7;  /* 0x8009C804 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x8; if (_c) { goto L_8009C8C8; } }  /* 0x8009C808 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 4662; if (_c) { goto L_8009C81C; } }  /* 0x8009C810 */
    R[4] = R[0] + 4663;  /* 0x8009C818 */
L_8009C81C:;
    R[5] = lh_(R[16] + 2);  /* 0x8009C81C */
    { R[31] = 0x8009C828u; psx_next = 0x8002DAE8u; return; }  /* 0x8009C820 jal */
    R[4] = 0x2u << 16;  /* 0x8009C828 */
    R[4] = R[4] | 0x4001;  /* 0x8009C82C */
    R[3] = 0x800Fu << 16;  /* 0x8009C830 */
    R[2] = R[0] + 608;  /* 0x8009C834 */
    sh_(R[3] + -21236, R[2]);  /* 0x8009C838 */
    R[3] = R[3] - 21236;  /* 0x8009C83C */
    R[2] = 0x8013u << 16;  /* 0x8009C840 */
    R[2] = R[2] - 29480;  /* 0x8009C844 */
    sw_(R[3] + 4, R[4]);  /* 0x8009C848 */
    R[4] = lw_(R[2] + 132);  /* 0x8009C84C */
    R[5] = lw_(R[2] + 136);  /* 0x8009C850 */
    R[6] = lw_(R[2] + 140);  /* 0x8009C854 */
    R[2] = R[0] + 2;  /* 0x8009C858 */
    sb_(R[3] + 20, R[2]);  /* 0x8009C85C */
    sw_(R[29] + 16, R[3]);  /* 0x8009C860 */
    sw_(R[3] + 28, R[4]);  /* 0x8009C864 */
    sw_(R[3] + 32, R[5]);  /* 0x8009C868 */
    sw_(R[3] + 40, R[6]);  /* 0x8009C86C */
    R[4] = lw_(R[16] + 24);  /* 0x8009C870 */
    R[5] = lw_(R[16] + 28);  /* 0x8009C874 */
    R[6] = lw_(R[16] + 32);  /* 0x8009C878 */
    { R[31] = 0x8009C884u; R[7] = R[0] + 384; psx_next = 0x800889DCu; return; }  /* 0x8009C87C jal */
    { goto L_8009C8C8; }  /* 0x8009C884 j */
L_8009C88C:;
    R[2] = 0x8013u << 16;  /* 0x8009C88C */
L_8009C890:;
    R[4] = R[2] - 29656;  /* 0x8009C890 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 68);  /* 0x8009C894 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Au << 16; if (_c) { goto L_8009C8C8; } }  /* 0x8009C89C */
    R[3] = lw_(R[16] + 16);  /* 0x8009C8A4 */
    R[2] = R[2] + 5568;  /* 0x8009C8A8 */
    sw_(R[16] + 232, R[2]);  /* 0x8009C8AC */
    R[3] = R[3] | 0x80;  /* 0x8009C8B0 */
    sw_(R[16] + 16, R[3]);  /* 0x8009C8B4 */
    sh_(R[4] + 68, R[0]);  /* 0x8009C8B8 */
    R[5] = lh_(R[16] + 2);  /* 0x8009C8BC */
    { R[31] = 0x8009C8C8u; R[4] = R[0] + 4661; psx_next = 0x8002DAE8u; return; }  /* 0x8009C8C0 jal */
L_8009C8C8:;
    R[31] = lw_(R[29] + 32);  /* 0x8009C8C8 */
    R[17] = lw_(R[29] + 28);  /* 0x8009C8CC */
    R[16] = lw_(R[29] + 24);  /* 0x8009C8D0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009C8D4 jr ra */
}

void g0_8009C780(void) {
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8013u << 16; if (_c) { goto L_8009C79C; } }  /* 0x8009C780 */
    R[2] = R[0] + 1;  /* 0x8009C788 */
    sh_(R[3] + -29644, R[2]);  /* 0x8009C78C */
    R[3] = 0x8006u << 16;  /* 0x8009C790 */
    R[2] = R[0] + 24;  /* 0x8009C794 */
    sh_(R[3] + 16032, R[2]);  /* 0x8009C798 */
L_8009C79C:;
    R[4] = R[16] + R[0];  /* 0x8009C79C */
    R[5] = 0x8u << 16;  /* 0x8009C7A0 */
    { R[31] = 0x8009C7ACu; R[5] = R[5] | 0x800; psx_next = 0x8008933Cu; return; }  /* 0x8009C7A4 jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009C88C; } }  /* 0x8009C7AC */
    R[17] = lb_(R[16] + 784);  /* 0x8009C7B4 */
    { uint32_t _c = (R[17] != R[2]); R[2] = 0x8013u << 16; if (_c) { goto L_8009C890; } }  /* 0x8009C7BC */
    R[2] = lw_(R[16] + 232);  /* 0x8009C7C4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009C7E0; } }  /* 0x8009C7CC */
    R[5] = lh_(R[16] + 2);  /* 0x8009C7D4 */
    { R[31] = 0x8009C7E0u; R[4] = R[0] + 4661; psx_next = 0x8002DAE8u; return; }  /* 0x8009C7D8 jal */
L_8009C7E0:;
    R[2] = lw_(R[16] + 16);  /* 0x8009C7E0 */
    R[3] = R[0] - 897;  /* 0x8009C7E4 */
    sw_(R[16] + 232, R[0]);  /* 0x8009C7E8 */
    R[2] = R[2] & R[3];  /* 0x8009C7EC */
    sw_(R[16] + 16, R[2]);  /* 0x8009C7F0 */
    R[2] = 0x800Fu << 16;  /* 0x8009C7F4 */
    R[3] = lw_(R[2] + 25520);  /* 0x8009C7F8 */
    R[2] = 0x8013u << 16;  /* 0x8009C7FC */
    sh_(R[2] + -29588, R[17]);  /* 0x8009C800 */
    R[2] = R[3] & 0x7;  /* 0x8009C804 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x8; if (_c) { goto L_8009C8C8; } }  /* 0x8009C808 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 4662; if (_c) { goto L_8009C81C; } }  /* 0x8009C810 */
    R[4] = R[0] + 4663;  /* 0x8009C818 */
L_8009C81C:;
    R[5] = lh_(R[16] + 2);  /* 0x8009C81C */
    { R[31] = 0x8009C828u; psx_next = 0x8002DAE8u; return; }  /* 0x8009C820 jal */
    R[4] = 0x2u << 16;  /* 0x8009C828 */
    R[4] = R[4] | 0x4001;  /* 0x8009C82C */
    R[3] = 0x800Fu << 16;  /* 0x8009C830 */
    R[2] = R[0] + 608;  /* 0x8009C834 */
    sh_(R[3] + -21236, R[2]);  /* 0x8009C838 */
    R[3] = R[3] - 21236;  /* 0x8009C83C */
    R[2] = 0x8013u << 16;  /* 0x8009C840 */
    R[2] = R[2] - 29480;  /* 0x8009C844 */
    sw_(R[3] + 4, R[4]);  /* 0x8009C848 */
    R[4] = lw_(R[2] + 132);  /* 0x8009C84C */
    R[5] = lw_(R[2] + 136);  /* 0x8009C850 */
    R[6] = lw_(R[2] + 140);  /* 0x8009C854 */
    R[2] = R[0] + 2;  /* 0x8009C858 */
    sb_(R[3] + 20, R[2]);  /* 0x8009C85C */
    sw_(R[29] + 16, R[3]);  /* 0x8009C860 */
    sw_(R[3] + 28, R[4]);  /* 0x8009C864 */
    sw_(R[3] + 32, R[5]);  /* 0x8009C868 */
    sw_(R[3] + 40, R[6]);  /* 0x8009C86C */
    R[4] = lw_(R[16] + 24);  /* 0x8009C870 */
    R[5] = lw_(R[16] + 28);  /* 0x8009C874 */
    R[6] = lw_(R[16] + 32);  /* 0x8009C878 */
    { R[31] = 0x8009C884u; R[7] = R[0] + 384; psx_next = 0x800889DCu; return; }  /* 0x8009C87C jal */
    { goto L_8009C8C8; }  /* 0x8009C884 j */
L_8009C88C:;
    R[2] = 0x8013u << 16;  /* 0x8009C88C */
L_8009C890:;
    R[4] = R[2] - 29656;  /* 0x8009C890 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 68);  /* 0x8009C894 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Au << 16; if (_c) { goto L_8009C8C8; } }  /* 0x8009C89C */
    R[3] = lw_(R[16] + 16);  /* 0x8009C8A4 */
    R[2] = R[2] + 5568;  /* 0x8009C8A8 */
    sw_(R[16] + 232, R[2]);  /* 0x8009C8AC */
    R[3] = R[3] | 0x80;  /* 0x8009C8B0 */
    sw_(R[16] + 16, R[3]);  /* 0x8009C8B4 */
    sh_(R[4] + 68, R[0]);  /* 0x8009C8B8 */
    R[5] = lh_(R[16] + 2);  /* 0x8009C8BC */
    { R[31] = 0x8009C8C8u; R[4] = R[0] + 4661; psx_next = 0x8002DAE8u; return; }  /* 0x8009C8C0 jal */
L_8009C8C8:;
    R[31] = lw_(R[29] + 32);  /* 0x8009C8C8 */
    R[17] = lw_(R[29] + 28);  /* 0x8009C8CC */
    R[16] = lw_(R[29] + 24);  /* 0x8009C8D0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009C8D4 jr ra */
}

void g0_8009C7AC(void) {
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009C88C; } }  /* 0x8009C7AC */
    R[17] = lb_(R[16] + 784);  /* 0x8009C7B4 */
    { uint32_t _c = (R[17] != R[2]); R[2] = 0x8013u << 16; if (_c) { goto L_8009C890; } }  /* 0x8009C7BC */
    R[2] = lw_(R[16] + 232);  /* 0x8009C7C4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009C7E0; } }  /* 0x8009C7CC */
    R[5] = lh_(R[16] + 2);  /* 0x8009C7D4 */
    { R[31] = 0x8009C7E0u; R[4] = R[0] + 4661; psx_next = 0x8002DAE8u; return; }  /* 0x8009C7D8 jal */
L_8009C7E0:;
    R[2] = lw_(R[16] + 16);  /* 0x8009C7E0 */
    R[3] = R[0] - 897;  /* 0x8009C7E4 */
    sw_(R[16] + 232, R[0]);  /* 0x8009C7E8 */
    R[2] = R[2] & R[3];  /* 0x8009C7EC */
    sw_(R[16] + 16, R[2]);  /* 0x8009C7F0 */
    R[2] = 0x800Fu << 16;  /* 0x8009C7F4 */
    R[3] = lw_(R[2] + 25520);  /* 0x8009C7F8 */
    R[2] = 0x8013u << 16;  /* 0x8009C7FC */
    sh_(R[2] + -29588, R[17]);  /* 0x8009C800 */
    R[2] = R[3] & 0x7;  /* 0x8009C804 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x8; if (_c) { goto L_8009C8C8; } }  /* 0x8009C808 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 4662; if (_c) { goto L_8009C81C; } }  /* 0x8009C810 */
    R[4] = R[0] + 4663;  /* 0x8009C818 */
L_8009C81C:;
    R[5] = lh_(R[16] + 2);  /* 0x8009C81C */
    { R[31] = 0x8009C828u; psx_next = 0x8002DAE8u; return; }  /* 0x8009C820 jal */
    R[4] = 0x2u << 16;  /* 0x8009C828 */
    R[4] = R[4] | 0x4001;  /* 0x8009C82C */
    R[3] = 0x800Fu << 16;  /* 0x8009C830 */
    R[2] = R[0] + 608;  /* 0x8009C834 */
    sh_(R[3] + -21236, R[2]);  /* 0x8009C838 */
    R[3] = R[3] - 21236;  /* 0x8009C83C */
    R[2] = 0x8013u << 16;  /* 0x8009C840 */
    R[2] = R[2] - 29480;  /* 0x8009C844 */
    sw_(R[3] + 4, R[4]);  /* 0x8009C848 */
    R[4] = lw_(R[2] + 132);  /* 0x8009C84C */
    R[5] = lw_(R[2] + 136);  /* 0x8009C850 */
    R[6] = lw_(R[2] + 140);  /* 0x8009C854 */
    R[2] = R[0] + 2;  /* 0x8009C858 */
    sb_(R[3] + 20, R[2]);  /* 0x8009C85C */
    sw_(R[29] + 16, R[3]);  /* 0x8009C860 */
    sw_(R[3] + 28, R[4]);  /* 0x8009C864 */
    sw_(R[3] + 32, R[5]);  /* 0x8009C868 */
    sw_(R[3] + 40, R[6]);  /* 0x8009C86C */
    R[4] = lw_(R[16] + 24);  /* 0x8009C870 */
    R[5] = lw_(R[16] + 28);  /* 0x8009C874 */
    R[6] = lw_(R[16] + 32);  /* 0x8009C878 */
    { R[31] = 0x8009C884u; R[7] = R[0] + 384; psx_next = 0x800889DCu; return; }  /* 0x8009C87C jal */
    { goto L_8009C8C8; }  /* 0x8009C884 j */
L_8009C88C:;
    R[2] = 0x8013u << 16;  /* 0x8009C88C */
L_8009C890:;
    R[4] = R[2] - 29656;  /* 0x8009C890 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 68);  /* 0x8009C894 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Au << 16; if (_c) { goto L_8009C8C8; } }  /* 0x8009C89C */
    R[3] = lw_(R[16] + 16);  /* 0x8009C8A4 */
    R[2] = R[2] + 5568;  /* 0x8009C8A8 */
    sw_(R[16] + 232, R[2]);  /* 0x8009C8AC */
    R[3] = R[3] | 0x80;  /* 0x8009C8B0 */
    sw_(R[16] + 16, R[3]);  /* 0x8009C8B4 */
    sh_(R[4] + 68, R[0]);  /* 0x8009C8B8 */
    R[5] = lh_(R[16] + 2);  /* 0x8009C8BC */
    { R[31] = 0x8009C8C8u; R[4] = R[0] + 4661; psx_next = 0x8002DAE8u; return; }  /* 0x8009C8C0 jal */
L_8009C8C8:;
    R[31] = lw_(R[29] + 32);  /* 0x8009C8C8 */
    R[17] = lw_(R[29] + 28);  /* 0x8009C8CC */
    R[16] = lw_(R[29] + 24);  /* 0x8009C8D0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009C8D4 jr ra */
}

void g0_8009C7E0(void) {
    R[2] = lw_(R[16] + 16);  /* 0x8009C7E0 */
    R[3] = R[0] - 897;  /* 0x8009C7E4 */
    sw_(R[16] + 232, R[0]);  /* 0x8009C7E8 */
    R[2] = R[2] & R[3];  /* 0x8009C7EC */
    sw_(R[16] + 16, R[2]);  /* 0x8009C7F0 */
    R[2] = 0x800Fu << 16;  /* 0x8009C7F4 */
    R[3] = lw_(R[2] + 25520);  /* 0x8009C7F8 */
    R[2] = 0x8013u << 16;  /* 0x8009C7FC */
    sh_(R[2] + -29588, R[17]);  /* 0x8009C800 */
    R[2] = R[3] & 0x7;  /* 0x8009C804 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[3] & 0x8; if (_c) { goto L_8009C8C8; } }  /* 0x8009C808 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[0] + 4662; if (_c) { goto L_8009C81C; } }  /* 0x8009C810 */
    R[4] = R[0] + 4663;  /* 0x8009C818 */
L_8009C81C:;
    R[5] = lh_(R[16] + 2);  /* 0x8009C81C */
    { R[31] = 0x8009C828u; psx_next = 0x8002DAE8u; return; }  /* 0x8009C820 jal */
    R[4] = 0x2u << 16;  /* 0x8009C828 */
    R[4] = R[4] | 0x4001;  /* 0x8009C82C */
    R[3] = 0x800Fu << 16;  /* 0x8009C830 */
    R[2] = R[0] + 608;  /* 0x8009C834 */
    sh_(R[3] + -21236, R[2]);  /* 0x8009C838 */
    R[3] = R[3] - 21236;  /* 0x8009C83C */
    R[2] = 0x8013u << 16;  /* 0x8009C840 */
    R[2] = R[2] - 29480;  /* 0x8009C844 */
    sw_(R[3] + 4, R[4]);  /* 0x8009C848 */
    R[4] = lw_(R[2] + 132);  /* 0x8009C84C */
    R[5] = lw_(R[2] + 136);  /* 0x8009C850 */
    R[6] = lw_(R[2] + 140);  /* 0x8009C854 */
    R[2] = R[0] + 2;  /* 0x8009C858 */
    sb_(R[3] + 20, R[2]);  /* 0x8009C85C */
    sw_(R[29] + 16, R[3]);  /* 0x8009C860 */
    sw_(R[3] + 28, R[4]);  /* 0x8009C864 */
    sw_(R[3] + 32, R[5]);  /* 0x8009C868 */
    sw_(R[3] + 40, R[6]);  /* 0x8009C86C */
    R[4] = lw_(R[16] + 24);  /* 0x8009C870 */
    R[5] = lw_(R[16] + 28);  /* 0x8009C874 */
    R[6] = lw_(R[16] + 32);  /* 0x8009C878 */
    { R[31] = 0x8009C884u; R[7] = R[0] + 384; psx_next = 0x800889DCu; return; }  /* 0x8009C87C jal */
    { goto L_8009C8C8; }  /* 0x8009C884 j */
    R[2] = 0x8013u << 16;  /* 0x8009C88C */
    R[4] = R[2] - 29656;  /* 0x8009C890 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 68);  /* 0x8009C894 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Au << 16; if (_c) { goto L_8009C8C8; } }  /* 0x8009C89C */
    R[3] = lw_(R[16] + 16);  /* 0x8009C8A4 */
    R[2] = R[2] + 5568;  /* 0x8009C8A8 */
    sw_(R[16] + 232, R[2]);  /* 0x8009C8AC */
    R[3] = R[3] | 0x80;  /* 0x8009C8B0 */
    sw_(R[16] + 16, R[3]);  /* 0x8009C8B4 */
    sh_(R[4] + 68, R[0]);  /* 0x8009C8B8 */
    R[5] = lh_(R[16] + 2);  /* 0x8009C8BC */
    { R[31] = 0x8009C8C8u; R[4] = R[0] + 4661; psx_next = 0x8002DAE8u; return; }  /* 0x8009C8C0 jal */
L_8009C8C8:;
    R[31] = lw_(R[29] + 32);  /* 0x8009C8C8 */
    R[17] = lw_(R[29] + 28);  /* 0x8009C8CC */
    R[16] = lw_(R[29] + 24);  /* 0x8009C8D0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009C8D4 jr ra */
}

void g0_8009C828(void) {
    R[4] = 0x2u << 16;  /* 0x8009C828 */
    R[4] = R[4] | 0x4001;  /* 0x8009C82C */
    R[3] = 0x800Fu << 16;  /* 0x8009C830 */
    R[2] = R[0] + 608;  /* 0x8009C834 */
    sh_(R[3] + -21236, R[2]);  /* 0x8009C838 */
    R[3] = R[3] - 21236;  /* 0x8009C83C */
    R[2] = 0x8013u << 16;  /* 0x8009C840 */
    R[2] = R[2] - 29480;  /* 0x8009C844 */
    sw_(R[3] + 4, R[4]);  /* 0x8009C848 */
    R[4] = lw_(R[2] + 132);  /* 0x8009C84C */
    R[5] = lw_(R[2] + 136);  /* 0x8009C850 */
    R[6] = lw_(R[2] + 140);  /* 0x8009C854 */
    R[2] = R[0] + 2;  /* 0x8009C858 */
    sb_(R[3] + 20, R[2]);  /* 0x8009C85C */
    sw_(R[29] + 16, R[3]);  /* 0x8009C860 */
    sw_(R[3] + 28, R[4]);  /* 0x8009C864 */
    sw_(R[3] + 32, R[5]);  /* 0x8009C868 */
    sw_(R[3] + 40, R[6]);  /* 0x8009C86C */
    R[4] = lw_(R[16] + 24);  /* 0x8009C870 */
    R[5] = lw_(R[16] + 28);  /* 0x8009C874 */
    R[6] = lw_(R[16] + 32);  /* 0x8009C878 */
    { R[31] = 0x8009C884u; R[7] = R[0] + 384; psx_next = 0x800889DCu; return; }  /* 0x8009C87C jal */
    { goto L_8009C8C8; }  /* 0x8009C884 j */
    R[2] = 0x8013u << 16;  /* 0x8009C88C */
    R[4] = R[2] - 29656;  /* 0x8009C890 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 68);  /* 0x8009C894 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Au << 16; if (_c) { goto L_8009C8C8; } }  /* 0x8009C89C */
    R[3] = lw_(R[16] + 16);  /* 0x8009C8A4 */
    R[2] = R[2] + 5568;  /* 0x8009C8A8 */
    sw_(R[16] + 232, R[2]);  /* 0x8009C8AC */
    R[3] = R[3] | 0x80;  /* 0x8009C8B0 */
    sw_(R[16] + 16, R[3]);  /* 0x8009C8B4 */
    sh_(R[4] + 68, R[0]);  /* 0x8009C8B8 */
    R[5] = lh_(R[16] + 2);  /* 0x8009C8BC */
    { R[31] = 0x8009C8C8u; R[4] = R[0] + 4661; psx_next = 0x8002DAE8u; return; }  /* 0x8009C8C0 jal */
L_8009C8C8:;
    R[31] = lw_(R[29] + 32);  /* 0x8009C8C8 */
    R[17] = lw_(R[29] + 28);  /* 0x8009C8CC */
    R[16] = lw_(R[29] + 24);  /* 0x8009C8D0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009C8D4 jr ra */
}

void g0_8009C884(void) {
    { goto L_8009C8C8; }  /* 0x8009C884 j */
    R[2] = 0x8013u << 16;  /* 0x8009C88C */
    R[4] = R[2] - 29656;  /* 0x8009C890 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 68);  /* 0x8009C894 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x800Au << 16; if (_c) { goto L_8009C8C8; } }  /* 0x8009C89C */
    R[3] = lw_(R[16] + 16);  /* 0x8009C8A4 */
    R[2] = R[2] + 5568;  /* 0x8009C8A8 */
    sw_(R[16] + 232, R[2]);  /* 0x8009C8AC */
    R[3] = R[3] | 0x80;  /* 0x8009C8B0 */
    sw_(R[16] + 16, R[3]);  /* 0x8009C8B4 */
    sh_(R[4] + 68, R[0]);  /* 0x8009C8B8 */
    R[5] = lh_(R[16] + 2);  /* 0x8009C8BC */
    { R[31] = 0x8009C8C8u; R[4] = R[0] + 4661; psx_next = 0x8002DAE8u; return; }  /* 0x8009C8C0 jal */
L_8009C8C8:;
    R[31] = lw_(R[29] + 32);  /* 0x8009C8C8 */
    R[17] = lw_(R[29] + 28);  /* 0x8009C8CC */
    R[16] = lw_(R[29] + 24);  /* 0x8009C8D0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009C8D4 jr ra */
}

void g0_8009C8C8(void) {
    R[31] = lw_(R[29] + 32);  /* 0x8009C8C8 */
    R[17] = lw_(R[29] + 28);  /* 0x8009C8CC */
    R[16] = lw_(R[29] + 24);  /* 0x8009C8D0 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009C8D4 jr ra */
}

void g0_8009C8DC(void) {
    R[2] = 0x800Fu << 16;  /* 0x8009C8DC */
    R[2] = lw_(R[2] + 25120);  /* 0x8009C8E0 */
    psx_next = 0x8009C8E4u; return;  /* fallthrough */
}

void g0_8009C8E4(void) {
    R[29] = R[29] - 40;  /* 0x8009C8E4 */
    sw_(R[29] + 20, R[17]);  /* 0x8009C8E8 */
    R[17] = R[4] + R[0];  /* 0x8009C8EC */
    sw_(R[29] + 32, R[31]);  /* 0x8009C8F0 */
    sw_(R[29] + 28, R[19]);  /* 0x8009C8F4 */
    sw_(R[29] + 24, R[18]);  /* 0x8009C8F8 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[29] + 16, R[16]); if (_c) { psx_next = 0x8009CB30u; return; } }  /* 0x8009C8FC b extern */
    R[2] = lw_(R[17] + 352);  /* 0x8009C904 */
    R[19] = lw_(R[2] + 24);  /* 0x8009C90C */
    R[3] = lw_(R[2] + 16);  /* 0x8009C910 */
    R[2] = 0x8013u << 16;  /* 0x8009C914 */
    sh_(R[2] + -29644, R[0]);  /* 0x8009C918 */
    R[2] = 0x8012u << 16;  /* 0x8009C91C */
    R[2] = lh_(R[2] + 31132);  /* 0x8009C920 */
    R[3] = R[3] & 0x1F8;  /* 0x8009C924 */
    R[2] = R[2] & 0x1;  /* 0x8009C928 */
    { uint32_t _c = (R[2] == R[0]); R[16] = (uint32_t)((int32_t)R[3] >> 3); if (_c) { goto L_8009C944; } }  /* 0x8009C92C */
    R[3] = 0x8006u << 16;  /* 0x8009C934 */
    R[2] = R[0] + 24;  /* 0x8009C938 */
    { sh_(R[3] + 16032, R[2]); goto L_8009C94C; }  /* 0x8009C93C j */
L_8009C944:;
    R[2] = 0x8006u << 16;  /* 0x8009C944 */
    sh_(R[2] + 16032, R[0]);  /* 0x8009C948 */
L_8009C94C:;
    R[4] = R[17] + R[0];  /* 0x8009C94C */
    { R[31] = 0x8009C958u; R[5] = R[0] + 64; psx_next = 0x800893BCu; return; }  /* 0x8009C950 jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009C97C; } }  /* 0x8009C958 */
    R[3] = 0x8006u << 16;  /* 0x8009C960 */
    R[3] = R[3] - 6456;  /* 0x8009C964 */
    R[4] = R[0] - 1;  /* 0x8009C968 */
    sh_(R[3] + 4, R[0]);  /* 0x8009C96C */
    sh_(R[3] + 2, R[0]);  /* 0x8009C970 */
    { sw_(R[3] + 16, R[4]); psx_next = 0x8009CB34u; return; }  /* 0x8009C974 j extern */
L_8009C97C:;
    { R[31] = 0x8009C984u; R[4] = R[17] + R[0]; psx_next = 0x8009C740u; return; }  /* 0x8009C97C jal */
    R[2] = (R[16] < (uint32_t)22u);  /* 0x8009C984 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8008u << 16; if (_c) { psx_next = 0x8009CB30u; return; } }  /* 0x8009C988 b extern */
    R[2] = R[2] + 8572;  /* 0x8009C990 */
    R[3] = R[16] << 2;  /* 0x8009C994 */
    R[3] = R[3] + R[2];  /* 0x8009C998 */
    psx_next = 0x8009C99Cu; return;  /* fallthrough */
}

void g0_8009C958(void) {
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009C97C; } }  /* 0x8009C958 */
    R[3] = 0x8006u << 16;  /* 0x8009C960 */
    R[3] = R[3] - 6456;  /* 0x8009C964 */
    R[4] = R[0] - 1;  /* 0x8009C968 */
    sh_(R[3] + 4, R[0]);  /* 0x8009C96C */
    sh_(R[3] + 2, R[0]);  /* 0x8009C970 */
    { sw_(R[3] + 16, R[4]); psx_next = 0x8009CB34u; return; }  /* 0x8009C974 j extern */
L_8009C97C:;
    { R[31] = 0x8009C984u; R[4] = R[17] + R[0]; psx_next = 0x8009C740u; return; }  /* 0x8009C97C jal */
    R[2] = (R[16] < (uint32_t)22u);  /* 0x8009C984 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8008u << 16; if (_c) { psx_next = 0x8009CB30u; return; } }  /* 0x8009C988 b extern */
    R[2] = R[2] + 8572;  /* 0x8009C990 */
    R[3] = R[16] << 2;  /* 0x8009C994 */
    R[3] = R[3] + R[2];  /* 0x8009C998 */
    psx_next = 0x8009C99Cu; return;  /* fallthrough */
}

void g0_8009C984(void) {
    R[2] = (R[16] < (uint32_t)22u);  /* 0x8009C984 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8008u << 16; if (_c) { psx_next = 0x8009CB30u; return; } }  /* 0x8009C988 b extern */
    R[2] = R[2] + 8572;  /* 0x8009C990 */
    R[3] = R[16] << 2;  /* 0x8009C994 */
    R[3] = R[3] + R[2];  /* 0x8009C998 */
    psx_next = 0x8009C99Cu; return;  /* fallthrough */
}

void g0_8009C99C(void) {
    R[2] = lw_(R[3]);  /* 0x8009C99C */
    { uint32_t _t = R[2]; psx_next = _t; return; }  /* 0x8009C9A4 jr indirect */
    R[3] = 0x8013u << 16;  /* 0x8009C9AC */
    R[2] = R[0] + 1;  /* 0x8009C9B0 */
    sh_(R[3] + -29644, R[2]);  /* 0x8009C9B4 */
    R[3] = 0x8006u << 16;  /* 0x8009C9B8 */
    R[2] = R[0] + 24;  /* 0x8009C9BC */
    sh_(R[3] + 16032, R[2]);  /* 0x8009C9C0 */
    R[2] = lw_(R[17] + 576);  /* 0x8009C9C4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CB30; } }  /* 0x8009C9CC */
    { R[31] = 0x8009C9DCu; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009C9D4 jal */
    R[4] = 0x8012u << 16;  /* 0x8009C9DC */
    R[4] = R[4] - 26864;  /* 0x8009C9E0 */
    { R[5] = R[0] + 3; goto L_8009CB20; }  /* 0x8009C9E4 j */
    R[2] = 0x8012u << 16;  /* 0x8009C9EC */
    R[2] = R[2] - 26864;  /* 0x8009C9F0 */
    { uint32_t _c = (R[17] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009CB34; } }  /* 0x8009C9F4 */
    R[4] = R[17] + R[0];  /* 0x8009C9FC */
    { R[31] = 0x8009CA08u; R[5] = R[0] + 8; psx_next = 0x8009BC08u; return; }  /* 0x8009CA00 jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009CB30; } }  /* 0x8009CA08 */
    R[3] = lb_(R[17] + 784);  /* 0x8009CA10 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009CB34; } }  /* 0x8009CA18 */
    R[4] = R[17] + R[0];  /* 0x8009CA20 */
    { R[31] = 0x8009CA2Cu; R[5] = R[0] + 9; psx_next = 0x8009BC84u; return; }  /* 0x8009CA24 jal */
    R[3] = lb_(R[17] + 781);  /* 0x8009CA2C */
    R[2] = R[0] + 1;  /* 0x8009CA30 */
    R[3] = R[3] | 0x80;  /* 0x8009CA34 */
    { sb_(R[17] + 781, R[3]); goto L_8009CB34; }  /* 0x8009CA38 j */
    R[4] = R[19] + 24;  /* 0x8009CA40 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 2);  /* 0x8009CA44 */
    R[2] = ((int32_t)R[2] < 2049);  /* 0x8009CA4C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009CB30; } }  /* 0x8009CA50 */
    R[3] = lb_(R[17] + 785);  /* 0x8009CA58 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_8009CB30; } }  /* 0x8009CA60 */
    R[18] = lb_(R[17] + 784);  /* 0x8009CA68 */
    { uint32_t _c = (R[18] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009CB34; } }  /* 0x8009CA70 */
    R[4] = (uint32_t)(int16_t)lh_(R[4] + 4);  /* 0x8009CA78 */
    R[5] = (uint32_t)(int16_t)lh_(R[19] + 24);  /* 0x8009CA7C */
    R[4] = R[0] - R[4];  /* 0x8009CA80 */
    { R[31] = 0x8009CA8Cu; R[5] = R[0] - R[5]; psx_next = 0x80037B38u; return; }  /* 0x8009CA84 jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[4] = R[17] + R[0]; if (_c) { goto L_8009CA98; } }  /* 0x8009CA8C */
    R[2] = R[2] + 7;  /* 0x8009CA94 */
L_8009CA98:;
    R[5] = R[0] + 38;  /* 0x8009CA98 */
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x8009CA9C */
    { R[31] = 0x8009CAA8u; R[16] = R[2] & 0x1FF; psx_next = 0x8009BC08u; return; }  /* 0x8009CAA0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAC0; } }  /* 0x8009CAA8 */
    { R[31] = 0x8009CAB8u; R[5] = R[0] + 124; psx_next = 0x8009BC08u; return; }  /* 0x8009CAB0 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009CACC; } }  /* 0x8009CAB8 */
L_8009CAC0:;
    sh_(R[17] + 6, R[16]);  /* 0x8009CAC0 */
    { sh_(R[17] + 4, R[16]); goto L_8009CB30; }  /* 0x8009CAC4 j */
L_8009CACC:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 6);  /* 0x8009CACC */
    R[2] = R[16] - R[2];  /* 0x8009CAD4 */
    R[2] = R[2] - 128;  /* 0x8009CAD8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CADC */
    R[2] = ((int32_t)R[2] < 257);  /* 0x8009CAE0 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAFC; } }  /* 0x8009CAE4 */
    R[2] = lw_(R[17] + 148);  /* 0x8009CAEC */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_8009CB30; } }  /* 0x8009CAF4 */
L_8009CAFC:;
    { R[31] = 0x8009CB04u; R[5] = R[0] + 38; psx_next = 0x8009BC84u; return; }  /* 0x8009CAFC jal */
    R[4] = R[17] + R[0];  /* 0x8009CB04 */
    R[5] = R[0] + 2;  /* 0x8009CB08 */
    R[2] = 0x8013u << 16;  /* 0x8009CB0C */
    sb_(R[4] + 795, R[18]);  /* 0x8009CB10 */
    sh_(R[4] + 4, R[16]);  /* 0x8009CB14 */
    sh_(R[4] + 6, R[16]);  /* 0x8009CB18 */
    sh_(R[2] + -29648, R[0]);  /* 0x8009CB1C */
L_8009CB20:;
    { R[31] = 0x8009CB28u; psx_next = 0x8009C12Cu; return; }  /* 0x8009CB20 jal */
    { R[2] = R[0] + 1; goto L_8009CB34; }  /* 0x8009CB28 j */
L_8009CB30:;
    R[2] = R[0] + R[0];  /* 0x8009CB30 */
L_8009CB34:;
    R[31] = lw_(R[29] + 32);  /* 0x8009CB34 */
    R[19] = lw_(R[29] + 28);  /* 0x8009CB38 */
    R[18] = lw_(R[29] + 24);  /* 0x8009CB3C */
    R[17] = lw_(R[29] + 20);  /* 0x8009CB40 */
    R[16] = lw_(R[29] + 16);  /* 0x8009CB44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009CB48 jr ra */
}

void g0_8009C9AC(void) {
    R[3] = 0x8013u << 16;  /* 0x8009C9AC */
    R[2] = R[0] + 1;  /* 0x8009C9B0 */
    sh_(R[3] + -29644, R[2]);  /* 0x8009C9B4 */
    R[3] = 0x8006u << 16;  /* 0x8009C9B8 */
    R[2] = R[0] + 24;  /* 0x8009C9BC */
    sh_(R[3] + 16032, R[2]);  /* 0x8009C9C0 */
    R[2] = lw_(R[17] + 576);  /* 0x8009C9C4 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CB30; } }  /* 0x8009C9CC */
    { R[31] = 0x8009C9DCu; R[5] = R[0] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009C9D4 jal */
    R[4] = 0x8012u << 16;  /* 0x8009C9DC */
    R[4] = R[4] - 26864;  /* 0x8009C9E0 */
    { R[5] = R[0] + 3; goto L_8009CB20; }  /* 0x8009C9E4 j */
    R[2] = 0x8012u << 16;  /* 0x8009C9EC */
    R[2] = R[2] - 26864;  /* 0x8009C9F0 */
    { uint32_t _c = (R[17] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009CB34; } }  /* 0x8009C9F4 */
    R[4] = R[17] + R[0];  /* 0x8009C9FC */
    { R[31] = 0x8009CA08u; R[5] = R[0] + 8; psx_next = 0x8009BC08u; return; }  /* 0x8009CA00 jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009CB30; } }  /* 0x8009CA08 */
    R[3] = lb_(R[17] + 784);  /* 0x8009CA10 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009CB34; } }  /* 0x8009CA18 */
    R[4] = R[17] + R[0];  /* 0x8009CA20 */
    { R[31] = 0x8009CA2Cu; R[5] = R[0] + 9; psx_next = 0x8009BC84u; return; }  /* 0x8009CA24 jal */
    R[3] = lb_(R[17] + 781);  /* 0x8009CA2C */
    R[2] = R[0] + 1;  /* 0x8009CA30 */
    R[3] = R[3] | 0x80;  /* 0x8009CA34 */
    { sb_(R[17] + 781, R[3]); goto L_8009CB34; }  /* 0x8009CA38 j */
    R[4] = R[19] + 24;  /* 0x8009CA40 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 2);  /* 0x8009CA44 */
    R[2] = ((int32_t)R[2] < 2049);  /* 0x8009CA4C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009CB30; } }  /* 0x8009CA50 */
    R[3] = lb_(R[17] + 785);  /* 0x8009CA58 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_8009CB30; } }  /* 0x8009CA60 */
    R[18] = lb_(R[17] + 784);  /* 0x8009CA68 */
    { uint32_t _c = (R[18] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009CB34; } }  /* 0x8009CA70 */
    R[4] = (uint32_t)(int16_t)lh_(R[4] + 4);  /* 0x8009CA78 */
    R[5] = (uint32_t)(int16_t)lh_(R[19] + 24);  /* 0x8009CA7C */
    R[4] = R[0] - R[4];  /* 0x8009CA80 */
    { R[31] = 0x8009CA8Cu; R[5] = R[0] - R[5]; psx_next = 0x80037B38u; return; }  /* 0x8009CA84 jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[4] = R[17] + R[0]; if (_c) { goto L_8009CA98; } }  /* 0x8009CA8C */
    R[2] = R[2] + 7;  /* 0x8009CA94 */
L_8009CA98:;
    R[5] = R[0] + 38;  /* 0x8009CA98 */
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x8009CA9C */
    { R[31] = 0x8009CAA8u; R[16] = R[2] & 0x1FF; psx_next = 0x8009BC08u; return; }  /* 0x8009CAA0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAC0; } }  /* 0x8009CAA8 */
    { R[31] = 0x8009CAB8u; R[5] = R[0] + 124; psx_next = 0x8009BC08u; return; }  /* 0x8009CAB0 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009CACC; } }  /* 0x8009CAB8 */
L_8009CAC0:;
    sh_(R[17] + 6, R[16]);  /* 0x8009CAC0 */
    { sh_(R[17] + 4, R[16]); goto L_8009CB30; }  /* 0x8009CAC4 j */
L_8009CACC:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 6);  /* 0x8009CACC */
    R[2] = R[16] - R[2];  /* 0x8009CAD4 */
    R[2] = R[2] - 128;  /* 0x8009CAD8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CADC */
    R[2] = ((int32_t)R[2] < 257);  /* 0x8009CAE0 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAFC; } }  /* 0x8009CAE4 */
    R[2] = lw_(R[17] + 148);  /* 0x8009CAEC */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_8009CB30; } }  /* 0x8009CAF4 */
L_8009CAFC:;
    { R[31] = 0x8009CB04u; R[5] = R[0] + 38; psx_next = 0x8009BC84u; return; }  /* 0x8009CAFC jal */
    R[4] = R[17] + R[0];  /* 0x8009CB04 */
    R[5] = R[0] + 2;  /* 0x8009CB08 */
    R[2] = 0x8013u << 16;  /* 0x8009CB0C */
    sb_(R[4] + 795, R[18]);  /* 0x8009CB10 */
    sh_(R[4] + 4, R[16]);  /* 0x8009CB14 */
    sh_(R[4] + 6, R[16]);  /* 0x8009CB18 */
    sh_(R[2] + -29648, R[0]);  /* 0x8009CB1C */
L_8009CB20:;
    { R[31] = 0x8009CB28u; psx_next = 0x8009C12Cu; return; }  /* 0x8009CB20 jal */
    { R[2] = R[0] + 1; goto L_8009CB34; }  /* 0x8009CB28 j */
L_8009CB30:;
    R[2] = R[0] + R[0];  /* 0x8009CB30 */
L_8009CB34:;
    R[31] = lw_(R[29] + 32);  /* 0x8009CB34 */
    R[19] = lw_(R[29] + 28);  /* 0x8009CB38 */
    R[18] = lw_(R[29] + 24);  /* 0x8009CB3C */
    R[17] = lw_(R[29] + 20);  /* 0x8009CB40 */
    R[16] = lw_(R[29] + 16);  /* 0x8009CB44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009CB48 jr ra */
}

void g0_8009C9DC(void) {
    R[4] = 0x8012u << 16;  /* 0x8009C9DC */
    R[4] = R[4] - 26864;  /* 0x8009C9E0 */
    { R[5] = R[0] + 3; goto L_8009CB20; }  /* 0x8009C9E4 j */
    R[2] = 0x8012u << 16;  /* 0x8009C9EC */
    R[2] = R[2] - 26864;  /* 0x8009C9F0 */
    { uint32_t _c = (R[17] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009CB34; } }  /* 0x8009C9F4 */
    R[4] = R[17] + R[0];  /* 0x8009C9FC */
    { R[31] = 0x8009CA08u; R[5] = R[0] + 8; psx_next = 0x8009BC08u; return; }  /* 0x8009CA00 jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009CB30; } }  /* 0x8009CA08 */
    R[3] = lb_(R[17] + 784);  /* 0x8009CA10 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009CB34; } }  /* 0x8009CA18 */
    R[4] = R[17] + R[0];  /* 0x8009CA20 */
    { R[31] = 0x8009CA2Cu; R[5] = R[0] + 9; psx_next = 0x8009BC84u; return; }  /* 0x8009CA24 jal */
    R[3] = lb_(R[17] + 781);  /* 0x8009CA2C */
    R[2] = R[0] + 1;  /* 0x8009CA30 */
    R[3] = R[3] | 0x80;  /* 0x8009CA34 */
    { sb_(R[17] + 781, R[3]); goto L_8009CB34; }  /* 0x8009CA38 j */
    R[4] = R[19] + 24;  /* 0x8009CA40 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 2);  /* 0x8009CA44 */
    R[2] = ((int32_t)R[2] < 2049);  /* 0x8009CA4C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009CB30; } }  /* 0x8009CA50 */
    R[3] = lb_(R[17] + 785);  /* 0x8009CA58 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_8009CB30; } }  /* 0x8009CA60 */
    R[18] = lb_(R[17] + 784);  /* 0x8009CA68 */
    { uint32_t _c = (R[18] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009CB34; } }  /* 0x8009CA70 */
    R[4] = (uint32_t)(int16_t)lh_(R[4] + 4);  /* 0x8009CA78 */
    R[5] = (uint32_t)(int16_t)lh_(R[19] + 24);  /* 0x8009CA7C */
    R[4] = R[0] - R[4];  /* 0x8009CA80 */
    { R[31] = 0x8009CA8Cu; R[5] = R[0] - R[5]; psx_next = 0x80037B38u; return; }  /* 0x8009CA84 jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[4] = R[17] + R[0]; if (_c) { goto L_8009CA98; } }  /* 0x8009CA8C */
    R[2] = R[2] + 7;  /* 0x8009CA94 */
L_8009CA98:;
    R[5] = R[0] + 38;  /* 0x8009CA98 */
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x8009CA9C */
    { R[31] = 0x8009CAA8u; R[16] = R[2] & 0x1FF; psx_next = 0x8009BC08u; return; }  /* 0x8009CAA0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAC0; } }  /* 0x8009CAA8 */
    { R[31] = 0x8009CAB8u; R[5] = R[0] + 124; psx_next = 0x8009BC08u; return; }  /* 0x8009CAB0 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009CACC; } }  /* 0x8009CAB8 */
L_8009CAC0:;
    sh_(R[17] + 6, R[16]);  /* 0x8009CAC0 */
    { sh_(R[17] + 4, R[16]); goto L_8009CB30; }  /* 0x8009CAC4 j */
L_8009CACC:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 6);  /* 0x8009CACC */
    R[2] = R[16] - R[2];  /* 0x8009CAD4 */
    R[2] = R[2] - 128;  /* 0x8009CAD8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CADC */
    R[2] = ((int32_t)R[2] < 257);  /* 0x8009CAE0 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAFC; } }  /* 0x8009CAE4 */
    R[2] = lw_(R[17] + 148);  /* 0x8009CAEC */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_8009CB30; } }  /* 0x8009CAF4 */
L_8009CAFC:;
    { R[31] = 0x8009CB04u; R[5] = R[0] + 38; psx_next = 0x8009BC84u; return; }  /* 0x8009CAFC jal */
    R[4] = R[17] + R[0];  /* 0x8009CB04 */
    R[5] = R[0] + 2;  /* 0x8009CB08 */
    R[2] = 0x8013u << 16;  /* 0x8009CB0C */
    sb_(R[4] + 795, R[18]);  /* 0x8009CB10 */
    sh_(R[4] + 4, R[16]);  /* 0x8009CB14 */
    sh_(R[4] + 6, R[16]);  /* 0x8009CB18 */
    sh_(R[2] + -29648, R[0]);  /* 0x8009CB1C */
L_8009CB20:;
    { R[31] = 0x8009CB28u; psx_next = 0x8009C12Cu; return; }  /* 0x8009CB20 jal */
    { R[2] = R[0] + 1; goto L_8009CB34; }  /* 0x8009CB28 j */
L_8009CB30:;
    R[2] = R[0] + R[0];  /* 0x8009CB30 */
L_8009CB34:;
    R[31] = lw_(R[29] + 32);  /* 0x8009CB34 */
    R[19] = lw_(R[29] + 28);  /* 0x8009CB38 */
    R[18] = lw_(R[29] + 24);  /* 0x8009CB3C */
    R[17] = lw_(R[29] + 20);  /* 0x8009CB40 */
    R[16] = lw_(R[29] + 16);  /* 0x8009CB44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009CB48 jr ra */
}

void g0_8009C9EC(void) {
    R[2] = 0x8012u << 16;  /* 0x8009C9EC */
    R[2] = R[2] - 26864;  /* 0x8009C9F0 */
    { uint32_t _c = (R[17] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009CB34; } }  /* 0x8009C9F4 */
    R[4] = R[17] + R[0];  /* 0x8009C9FC */
    { R[31] = 0x8009CA08u; R[5] = R[0] + 8; psx_next = 0x8009BC08u; return; }  /* 0x8009CA00 jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009CB30; } }  /* 0x8009CA08 */
    R[3] = lb_(R[17] + 784);  /* 0x8009CA10 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009CB34; } }  /* 0x8009CA18 */
    R[4] = R[17] + R[0];  /* 0x8009CA20 */
    { R[31] = 0x8009CA2Cu; R[5] = R[0] + 9; psx_next = 0x8009BC84u; return; }  /* 0x8009CA24 jal */
    R[3] = lb_(R[17] + 781);  /* 0x8009CA2C */
    R[2] = R[0] + 1;  /* 0x8009CA30 */
    R[3] = R[3] | 0x80;  /* 0x8009CA34 */
    { sb_(R[17] + 781, R[3]); goto L_8009CB34; }  /* 0x8009CA38 j */
    R[4] = R[19] + 24;  /* 0x8009CA40 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 2);  /* 0x8009CA44 */
    R[2] = ((int32_t)R[2] < 2049);  /* 0x8009CA4C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009CB30; } }  /* 0x8009CA50 */
    R[3] = lb_(R[17] + 785);  /* 0x8009CA58 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_8009CB30; } }  /* 0x8009CA60 */
    R[18] = lb_(R[17] + 784);  /* 0x8009CA68 */
    { uint32_t _c = (R[18] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009CB34; } }  /* 0x8009CA70 */
    R[4] = (uint32_t)(int16_t)lh_(R[4] + 4);  /* 0x8009CA78 */
    R[5] = (uint32_t)(int16_t)lh_(R[19] + 24);  /* 0x8009CA7C */
    R[4] = R[0] - R[4];  /* 0x8009CA80 */
    { R[31] = 0x8009CA8Cu; R[5] = R[0] - R[5]; psx_next = 0x80037B38u; return; }  /* 0x8009CA84 jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[4] = R[17] + R[0]; if (_c) { goto L_8009CA98; } }  /* 0x8009CA8C */
    R[2] = R[2] + 7;  /* 0x8009CA94 */
L_8009CA98:;
    R[5] = R[0] + 38;  /* 0x8009CA98 */
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x8009CA9C */
    { R[31] = 0x8009CAA8u; R[16] = R[2] & 0x1FF; psx_next = 0x8009BC08u; return; }  /* 0x8009CAA0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAC0; } }  /* 0x8009CAA8 */
    { R[31] = 0x8009CAB8u; R[5] = R[0] + 124; psx_next = 0x8009BC08u; return; }  /* 0x8009CAB0 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009CACC; } }  /* 0x8009CAB8 */
L_8009CAC0:;
    sh_(R[17] + 6, R[16]);  /* 0x8009CAC0 */
    { sh_(R[17] + 4, R[16]); goto L_8009CB30; }  /* 0x8009CAC4 j */
L_8009CACC:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 6);  /* 0x8009CACC */
    R[2] = R[16] - R[2];  /* 0x8009CAD4 */
    R[2] = R[2] - 128;  /* 0x8009CAD8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CADC */
    R[2] = ((int32_t)R[2] < 257);  /* 0x8009CAE0 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAFC; } }  /* 0x8009CAE4 */
    R[2] = lw_(R[17] + 148);  /* 0x8009CAEC */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_8009CB30; } }  /* 0x8009CAF4 */
L_8009CAFC:;
    { R[31] = 0x8009CB04u; R[5] = R[0] + 38; psx_next = 0x8009BC84u; return; }  /* 0x8009CAFC jal */
    R[4] = R[17] + R[0];  /* 0x8009CB04 */
    R[5] = R[0] + 2;  /* 0x8009CB08 */
    R[2] = 0x8013u << 16;  /* 0x8009CB0C */
    sb_(R[4] + 795, R[18]);  /* 0x8009CB10 */
    sh_(R[4] + 4, R[16]);  /* 0x8009CB14 */
    sh_(R[4] + 6, R[16]);  /* 0x8009CB18 */
    sh_(R[2] + -29648, R[0]);  /* 0x8009CB1C */
    { R[31] = 0x8009CB28u; psx_next = 0x8009C12Cu; return; }  /* 0x8009CB20 jal */
    { R[2] = R[0] + 1; goto L_8009CB34; }  /* 0x8009CB28 j */
L_8009CB30:;
    R[2] = R[0] + R[0];  /* 0x8009CB30 */
L_8009CB34:;
    R[31] = lw_(R[29] + 32);  /* 0x8009CB34 */
    R[19] = lw_(R[29] + 28);  /* 0x8009CB38 */
    R[18] = lw_(R[29] + 24);  /* 0x8009CB3C */
    R[17] = lw_(R[29] + 20);  /* 0x8009CB40 */
    R[16] = lw_(R[29] + 16);  /* 0x8009CB44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009CB48 jr ra */
}

void g0_8009CA08(void) {
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009CB30; } }  /* 0x8009CA08 */
    R[3] = lb_(R[17] + 784);  /* 0x8009CA10 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009CB34; } }  /* 0x8009CA18 */
    R[4] = R[17] + R[0];  /* 0x8009CA20 */
    { R[31] = 0x8009CA2Cu; R[5] = R[0] + 9; psx_next = 0x8009BC84u; return; }  /* 0x8009CA24 jal */
    R[3] = lb_(R[17] + 781);  /* 0x8009CA2C */
    R[2] = R[0] + 1;  /* 0x8009CA30 */
    R[3] = R[3] | 0x80;  /* 0x8009CA34 */
    { sb_(R[17] + 781, R[3]); goto L_8009CB34; }  /* 0x8009CA38 j */
    R[4] = R[19] + 24;  /* 0x8009CA40 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 2);  /* 0x8009CA44 */
    R[2] = ((int32_t)R[2] < 2049);  /* 0x8009CA4C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009CB30; } }  /* 0x8009CA50 */
    R[3] = lb_(R[17] + 785);  /* 0x8009CA58 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_8009CB30; } }  /* 0x8009CA60 */
    R[18] = lb_(R[17] + 784);  /* 0x8009CA68 */
    { uint32_t _c = (R[18] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009CB34; } }  /* 0x8009CA70 */
    R[4] = (uint32_t)(int16_t)lh_(R[4] + 4);  /* 0x8009CA78 */
    R[5] = (uint32_t)(int16_t)lh_(R[19] + 24);  /* 0x8009CA7C */
    R[4] = R[0] - R[4];  /* 0x8009CA80 */
    { R[31] = 0x8009CA8Cu; R[5] = R[0] - R[5]; psx_next = 0x80037B38u; return; }  /* 0x8009CA84 jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[4] = R[17] + R[0]; if (_c) { goto L_8009CA98; } }  /* 0x8009CA8C */
    R[2] = R[2] + 7;  /* 0x8009CA94 */
L_8009CA98:;
    R[5] = R[0] + 38;  /* 0x8009CA98 */
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x8009CA9C */
    { R[31] = 0x8009CAA8u; R[16] = R[2] & 0x1FF; psx_next = 0x8009BC08u; return; }  /* 0x8009CAA0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAC0; } }  /* 0x8009CAA8 */
    { R[31] = 0x8009CAB8u; R[5] = R[0] + 124; psx_next = 0x8009BC08u; return; }  /* 0x8009CAB0 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009CACC; } }  /* 0x8009CAB8 */
L_8009CAC0:;
    sh_(R[17] + 6, R[16]);  /* 0x8009CAC0 */
    { sh_(R[17] + 4, R[16]); goto L_8009CB30; }  /* 0x8009CAC4 j */
L_8009CACC:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 6);  /* 0x8009CACC */
    R[2] = R[16] - R[2];  /* 0x8009CAD4 */
    R[2] = R[2] - 128;  /* 0x8009CAD8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CADC */
    R[2] = ((int32_t)R[2] < 257);  /* 0x8009CAE0 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAFC; } }  /* 0x8009CAE4 */
    R[2] = lw_(R[17] + 148);  /* 0x8009CAEC */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_8009CB30; } }  /* 0x8009CAF4 */
L_8009CAFC:;
    { R[31] = 0x8009CB04u; R[5] = R[0] + 38; psx_next = 0x8009BC84u; return; }  /* 0x8009CAFC jal */
    R[4] = R[17] + R[0];  /* 0x8009CB04 */
    R[5] = R[0] + 2;  /* 0x8009CB08 */
    R[2] = 0x8013u << 16;  /* 0x8009CB0C */
    sb_(R[4] + 795, R[18]);  /* 0x8009CB10 */
    sh_(R[4] + 4, R[16]);  /* 0x8009CB14 */
    sh_(R[4] + 6, R[16]);  /* 0x8009CB18 */
    sh_(R[2] + -29648, R[0]);  /* 0x8009CB1C */
    { R[31] = 0x8009CB28u; psx_next = 0x8009C12Cu; return; }  /* 0x8009CB20 jal */
    { R[2] = R[0] + 1; goto L_8009CB34; }  /* 0x8009CB28 j */
L_8009CB30:;
    R[2] = R[0] + R[0];  /* 0x8009CB30 */
L_8009CB34:;
    R[31] = lw_(R[29] + 32);  /* 0x8009CB34 */
    R[19] = lw_(R[29] + 28);  /* 0x8009CB38 */
    R[18] = lw_(R[29] + 24);  /* 0x8009CB3C */
    R[17] = lw_(R[29] + 20);  /* 0x8009CB40 */
    R[16] = lw_(R[29] + 16);  /* 0x8009CB44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009CB48 jr ra */
}

void g0_8009CA2C(void) {
    R[3] = lb_(R[17] + 781);  /* 0x8009CA2C */
    R[2] = R[0] + 1;  /* 0x8009CA30 */
    R[3] = R[3] | 0x80;  /* 0x8009CA34 */
    { sb_(R[17] + 781, R[3]); goto L_8009CB34; }  /* 0x8009CA38 j */
    R[4] = R[19] + 24;  /* 0x8009CA40 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 2);  /* 0x8009CA44 */
    R[2] = ((int32_t)R[2] < 2049);  /* 0x8009CA4C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009CB30; } }  /* 0x8009CA50 */
    R[3] = lb_(R[17] + 785);  /* 0x8009CA58 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_8009CB30; } }  /* 0x8009CA60 */
    R[18] = lb_(R[17] + 784);  /* 0x8009CA68 */
    { uint32_t _c = (R[18] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009CB34; } }  /* 0x8009CA70 */
    R[4] = (uint32_t)(int16_t)lh_(R[4] + 4);  /* 0x8009CA78 */
    R[5] = (uint32_t)(int16_t)lh_(R[19] + 24);  /* 0x8009CA7C */
    R[4] = R[0] - R[4];  /* 0x8009CA80 */
    { R[31] = 0x8009CA8Cu; R[5] = R[0] - R[5]; psx_next = 0x80037B38u; return; }  /* 0x8009CA84 jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[4] = R[17] + R[0]; if (_c) { goto L_8009CA98; } }  /* 0x8009CA8C */
    R[2] = R[2] + 7;  /* 0x8009CA94 */
L_8009CA98:;
    R[5] = R[0] + 38;  /* 0x8009CA98 */
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x8009CA9C */
    { R[31] = 0x8009CAA8u; R[16] = R[2] & 0x1FF; psx_next = 0x8009BC08u; return; }  /* 0x8009CAA0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAC0; } }  /* 0x8009CAA8 */
    { R[31] = 0x8009CAB8u; R[5] = R[0] + 124; psx_next = 0x8009BC08u; return; }  /* 0x8009CAB0 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009CACC; } }  /* 0x8009CAB8 */
L_8009CAC0:;
    sh_(R[17] + 6, R[16]);  /* 0x8009CAC0 */
    { sh_(R[17] + 4, R[16]); goto L_8009CB30; }  /* 0x8009CAC4 j */
L_8009CACC:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 6);  /* 0x8009CACC */
    R[2] = R[16] - R[2];  /* 0x8009CAD4 */
    R[2] = R[2] - 128;  /* 0x8009CAD8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CADC */
    R[2] = ((int32_t)R[2] < 257);  /* 0x8009CAE0 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAFC; } }  /* 0x8009CAE4 */
    R[2] = lw_(R[17] + 148);  /* 0x8009CAEC */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_8009CB30; } }  /* 0x8009CAF4 */
L_8009CAFC:;
    { R[31] = 0x8009CB04u; R[5] = R[0] + 38; psx_next = 0x8009BC84u; return; }  /* 0x8009CAFC jal */
    R[4] = R[17] + R[0];  /* 0x8009CB04 */
    R[5] = R[0] + 2;  /* 0x8009CB08 */
    R[2] = 0x8013u << 16;  /* 0x8009CB0C */
    sb_(R[4] + 795, R[18]);  /* 0x8009CB10 */
    sh_(R[4] + 4, R[16]);  /* 0x8009CB14 */
    sh_(R[4] + 6, R[16]);  /* 0x8009CB18 */
    sh_(R[2] + -29648, R[0]);  /* 0x8009CB1C */
    { R[31] = 0x8009CB28u; psx_next = 0x8009C12Cu; return; }  /* 0x8009CB20 jal */
    { R[2] = R[0] + 1; goto L_8009CB34; }  /* 0x8009CB28 j */
L_8009CB30:;
    R[2] = R[0] + R[0];  /* 0x8009CB30 */
L_8009CB34:;
    R[31] = lw_(R[29] + 32);  /* 0x8009CB34 */
    R[19] = lw_(R[29] + 28);  /* 0x8009CB38 */
    R[18] = lw_(R[29] + 24);  /* 0x8009CB3C */
    R[17] = lw_(R[29] + 20);  /* 0x8009CB40 */
    R[16] = lw_(R[29] + 16);  /* 0x8009CB44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009CB48 jr ra */
}

void g0_8009CA40(void) {
    R[4] = R[19] + 24;  /* 0x8009CA40 */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 2);  /* 0x8009CA44 */
    R[2] = ((int32_t)R[2] < 2049);  /* 0x8009CA4C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 2; if (_c) { goto L_8009CB30; } }  /* 0x8009CA50 */
    R[3] = lb_(R[17] + 785);  /* 0x8009CA58 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 1; if (_c) { goto L_8009CB30; } }  /* 0x8009CA60 */
    R[18] = lb_(R[17] + 784);  /* 0x8009CA68 */
    { uint32_t _c = (R[18] != R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009CB34; } }  /* 0x8009CA70 */
    R[4] = (uint32_t)(int16_t)lh_(R[4] + 4);  /* 0x8009CA78 */
    R[5] = (uint32_t)(int16_t)lh_(R[19] + 24);  /* 0x8009CA7C */
    R[4] = R[0] - R[4];  /* 0x8009CA80 */
    { R[31] = 0x8009CA8Cu; R[5] = R[0] - R[5]; psx_next = 0x80037B38u; return; }  /* 0x8009CA84 jal */
    { uint32_t _c = ((int32_t)R[2] >= 0); R[4] = R[17] + R[0]; if (_c) { goto L_8009CA98; } }  /* 0x8009CA8C */
    R[2] = R[2] + 7;  /* 0x8009CA94 */
L_8009CA98:;
    R[5] = R[0] + 38;  /* 0x8009CA98 */
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x8009CA9C */
    { R[31] = 0x8009CAA8u; R[16] = R[2] & 0x1FF; psx_next = 0x8009BC08u; return; }  /* 0x8009CAA0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAC0; } }  /* 0x8009CAA8 */
    { R[31] = 0x8009CAB8u; R[5] = R[0] + 124; psx_next = 0x8009BC08u; return; }  /* 0x8009CAB0 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009CACC; } }  /* 0x8009CAB8 */
L_8009CAC0:;
    sh_(R[17] + 6, R[16]);  /* 0x8009CAC0 */
    { sh_(R[17] + 4, R[16]); goto L_8009CB30; }  /* 0x8009CAC4 j */
L_8009CACC:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 6);  /* 0x8009CACC */
    R[2] = R[16] - R[2];  /* 0x8009CAD4 */
    R[2] = R[2] - 128;  /* 0x8009CAD8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CADC */
    R[2] = ((int32_t)R[2] < 257);  /* 0x8009CAE0 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAFC; } }  /* 0x8009CAE4 */
    R[2] = lw_(R[17] + 148);  /* 0x8009CAEC */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_8009CB30; } }  /* 0x8009CAF4 */
L_8009CAFC:;
    { R[31] = 0x8009CB04u; R[5] = R[0] + 38; psx_next = 0x8009BC84u; return; }  /* 0x8009CAFC jal */
    R[4] = R[17] + R[0];  /* 0x8009CB04 */
    R[5] = R[0] + 2;  /* 0x8009CB08 */
    R[2] = 0x8013u << 16;  /* 0x8009CB0C */
    sb_(R[4] + 795, R[18]);  /* 0x8009CB10 */
    sh_(R[4] + 4, R[16]);  /* 0x8009CB14 */
    sh_(R[4] + 6, R[16]);  /* 0x8009CB18 */
    sh_(R[2] + -29648, R[0]);  /* 0x8009CB1C */
    { R[31] = 0x8009CB28u; psx_next = 0x8009C12Cu; return; }  /* 0x8009CB20 jal */
    { R[2] = R[0] + 1; goto L_8009CB34; }  /* 0x8009CB28 j */
L_8009CB30:;
    R[2] = R[0] + R[0];  /* 0x8009CB30 */
L_8009CB34:;
    R[31] = lw_(R[29] + 32);  /* 0x8009CB34 */
    R[19] = lw_(R[29] + 28);  /* 0x8009CB38 */
    R[18] = lw_(R[29] + 24);  /* 0x8009CB3C */
    R[17] = lw_(R[29] + 20);  /* 0x8009CB40 */
    R[16] = lw_(R[29] + 16);  /* 0x8009CB44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009CB48 jr ra */
}

void g0_8009CA8C(void) {
    { uint32_t _c = ((int32_t)R[2] >= 0); R[4] = R[17] + R[0]; if (_c) { goto L_8009CA98; } }  /* 0x8009CA8C */
    R[2] = R[2] + 7;  /* 0x8009CA94 */
L_8009CA98:;
    R[5] = R[0] + 38;  /* 0x8009CA98 */
    R[2] = (uint32_t)((int32_t)R[2] >> 3);  /* 0x8009CA9C */
    { R[31] = 0x8009CAA8u; R[16] = R[2] & 0x1FF; psx_next = 0x8009BC08u; return; }  /* 0x8009CAA0 jal */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAC0; } }  /* 0x8009CAA8 */
    { R[31] = 0x8009CAB8u; R[5] = R[0] + 124; psx_next = 0x8009BC08u; return; }  /* 0x8009CAB0 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009CACC; } }  /* 0x8009CAB8 */
L_8009CAC0:;
    sh_(R[17] + 6, R[16]);  /* 0x8009CAC0 */
    { sh_(R[17] + 4, R[16]); goto L_8009CB30; }  /* 0x8009CAC4 j */
L_8009CACC:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 6);  /* 0x8009CACC */
    R[2] = R[16] - R[2];  /* 0x8009CAD4 */
    R[2] = R[2] - 128;  /* 0x8009CAD8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CADC */
    R[2] = ((int32_t)R[2] < 257);  /* 0x8009CAE0 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAFC; } }  /* 0x8009CAE4 */
    R[2] = lw_(R[17] + 148);  /* 0x8009CAEC */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_8009CB30; } }  /* 0x8009CAF4 */
L_8009CAFC:;
    { R[31] = 0x8009CB04u; R[5] = R[0] + 38; psx_next = 0x8009BC84u; return; }  /* 0x8009CAFC jal */
    R[4] = R[17] + R[0];  /* 0x8009CB04 */
    R[5] = R[0] + 2;  /* 0x8009CB08 */
    R[2] = 0x8013u << 16;  /* 0x8009CB0C */
    sb_(R[4] + 795, R[18]);  /* 0x8009CB10 */
    sh_(R[4] + 4, R[16]);  /* 0x8009CB14 */
    sh_(R[4] + 6, R[16]);  /* 0x8009CB18 */
    sh_(R[2] + -29648, R[0]);  /* 0x8009CB1C */
    { R[31] = 0x8009CB28u; psx_next = 0x8009C12Cu; return; }  /* 0x8009CB20 jal */
    { R[2] = R[0] + 1; goto L_8009CB34; }  /* 0x8009CB28 j */
L_8009CB30:;
    R[2] = R[0] + R[0];  /* 0x8009CB30 */
L_8009CB34:;
    R[31] = lw_(R[29] + 32);  /* 0x8009CB34 */
    R[19] = lw_(R[29] + 28);  /* 0x8009CB38 */
    R[18] = lw_(R[29] + 24);  /* 0x8009CB3C */
    R[17] = lw_(R[29] + 20);  /* 0x8009CB40 */
    R[16] = lw_(R[29] + 16);  /* 0x8009CB44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009CB48 jr ra */
}

void g0_8009CAA8(void) {
    { uint32_t _c = (R[2] != R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAC0; } }  /* 0x8009CAA8 */
    { R[31] = 0x8009CAB8u; R[5] = R[0] + 124; psx_next = 0x8009BC08u; return; }  /* 0x8009CAB0 jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009CACC; } }  /* 0x8009CAB8 */
L_8009CAC0:;
    sh_(R[17] + 6, R[16]);  /* 0x8009CAC0 */
    { sh_(R[17] + 4, R[16]); goto L_8009CB30; }  /* 0x8009CAC4 j */
L_8009CACC:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 6);  /* 0x8009CACC */
    R[2] = R[16] - R[2];  /* 0x8009CAD4 */
    R[2] = R[2] - 128;  /* 0x8009CAD8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CADC */
    R[2] = ((int32_t)R[2] < 257);  /* 0x8009CAE0 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAFC; } }  /* 0x8009CAE4 */
    R[2] = lw_(R[17] + 148);  /* 0x8009CAEC */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_8009CB30; } }  /* 0x8009CAF4 */
L_8009CAFC:;
    { R[31] = 0x8009CB04u; R[5] = R[0] + 38; psx_next = 0x8009BC84u; return; }  /* 0x8009CAFC jal */
    R[4] = R[17] + R[0];  /* 0x8009CB04 */
    R[5] = R[0] + 2;  /* 0x8009CB08 */
    R[2] = 0x8013u << 16;  /* 0x8009CB0C */
    sb_(R[4] + 795, R[18]);  /* 0x8009CB10 */
    sh_(R[4] + 4, R[16]);  /* 0x8009CB14 */
    sh_(R[4] + 6, R[16]);  /* 0x8009CB18 */
    sh_(R[2] + -29648, R[0]);  /* 0x8009CB1C */
    { R[31] = 0x8009CB28u; psx_next = 0x8009C12Cu; return; }  /* 0x8009CB20 jal */
    { R[2] = R[0] + 1; goto L_8009CB34; }  /* 0x8009CB28 j */
L_8009CB30:;
    R[2] = R[0] + R[0];  /* 0x8009CB30 */
L_8009CB34:;
    R[31] = lw_(R[29] + 32);  /* 0x8009CB34 */
    R[19] = lw_(R[29] + 28);  /* 0x8009CB38 */
    R[18] = lw_(R[29] + 24);  /* 0x8009CB3C */
    R[17] = lw_(R[29] + 20);  /* 0x8009CB40 */
    R[16] = lw_(R[29] + 16);  /* 0x8009CB44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009CB48 jr ra */
}

void g0_8009CAB8(void) {
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009CACC; } }  /* 0x8009CAB8 */
    sh_(R[17] + 6, R[16]);  /* 0x8009CAC0 */
    { sh_(R[17] + 4, R[16]); goto L_8009CB30; }  /* 0x8009CAC4 j */
L_8009CACC:;
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 6);  /* 0x8009CACC */
    R[2] = R[16] - R[2];  /* 0x8009CAD4 */
    R[2] = R[2] - 128;  /* 0x8009CAD8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CADC */
    R[2] = ((int32_t)R[2] < 257);  /* 0x8009CAE0 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CAFC; } }  /* 0x8009CAE4 */
    R[2] = lw_(R[17] + 148);  /* 0x8009CAEC */
    { uint32_t _c = ((int32_t)R[2] > 0); if (_c) { goto L_8009CB30; } }  /* 0x8009CAF4 */
L_8009CAFC:;
    { R[31] = 0x8009CB04u; R[5] = R[0] + 38; psx_next = 0x8009BC84u; return; }  /* 0x8009CAFC jal */
    R[4] = R[17] + R[0];  /* 0x8009CB04 */
    R[5] = R[0] + 2;  /* 0x8009CB08 */
    R[2] = 0x8013u << 16;  /* 0x8009CB0C */
    sb_(R[4] + 795, R[18]);  /* 0x8009CB10 */
    sh_(R[4] + 4, R[16]);  /* 0x8009CB14 */
    sh_(R[4] + 6, R[16]);  /* 0x8009CB18 */
    sh_(R[2] + -29648, R[0]);  /* 0x8009CB1C */
    { R[31] = 0x8009CB28u; psx_next = 0x8009C12Cu; return; }  /* 0x8009CB20 jal */
    { R[2] = R[0] + 1; goto L_8009CB34; }  /* 0x8009CB28 j */
L_8009CB30:;
    R[2] = R[0] + R[0];  /* 0x8009CB30 */
L_8009CB34:;
    R[31] = lw_(R[29] + 32);  /* 0x8009CB34 */
    R[19] = lw_(R[29] + 28);  /* 0x8009CB38 */
    R[18] = lw_(R[29] + 24);  /* 0x8009CB3C */
    R[17] = lw_(R[29] + 20);  /* 0x8009CB40 */
    R[16] = lw_(R[29] + 16);  /* 0x8009CB44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009CB48 jr ra */
}

void g0_8009CB04(void) {
    R[4] = R[17] + R[0];  /* 0x8009CB04 */
    R[5] = R[0] + 2;  /* 0x8009CB08 */
    R[2] = 0x8013u << 16;  /* 0x8009CB0C */
    sb_(R[4] + 795, R[18]);  /* 0x8009CB10 */
    sh_(R[4] + 4, R[16]);  /* 0x8009CB14 */
    sh_(R[4] + 6, R[16]);  /* 0x8009CB18 */
    sh_(R[2] + -29648, R[0]);  /* 0x8009CB1C */
    { R[31] = 0x8009CB28u; psx_next = 0x8009C12Cu; return; }  /* 0x8009CB20 jal */
    { R[2] = R[0] + 1; goto L_8009CB34; }  /* 0x8009CB28 j */
    R[2] = R[0] + R[0];  /* 0x8009CB30 */
L_8009CB34:;
    R[31] = lw_(R[29] + 32);  /* 0x8009CB34 */
    R[19] = lw_(R[29] + 28);  /* 0x8009CB38 */
    R[18] = lw_(R[29] + 24);  /* 0x8009CB3C */
    R[17] = lw_(R[29] + 20);  /* 0x8009CB40 */
    R[16] = lw_(R[29] + 16);  /* 0x8009CB44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009CB48 jr ra */
}

void g0_8009CB28(void) {
    { R[2] = R[0] + 1; goto L_8009CB34; }  /* 0x8009CB28 j */
    R[2] = R[0] + R[0];  /* 0x8009CB30 */
L_8009CB34:;
    R[31] = lw_(R[29] + 32);  /* 0x8009CB34 */
    R[19] = lw_(R[29] + 28);  /* 0x8009CB38 */
    R[18] = lw_(R[29] + 24);  /* 0x8009CB3C */
    R[17] = lw_(R[29] + 20);  /* 0x8009CB40 */
    R[16] = lw_(R[29] + 16);  /* 0x8009CB44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009CB48 jr ra */
}

void g0_8009CB30(void) {
    R[2] = R[0] + R[0];  /* 0x8009CB30 */
    R[31] = lw_(R[29] + 32);  /* 0x8009CB34 */
    R[19] = lw_(R[29] + 28);  /* 0x8009CB38 */
    R[18] = lw_(R[29] + 24);  /* 0x8009CB3C */
    R[17] = lw_(R[29] + 20);  /* 0x8009CB40 */
    R[16] = lw_(R[29] + 16);  /* 0x8009CB44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009CB48 jr ra */
}

void g0_8009CB34(void) {
    R[31] = lw_(R[29] + 32);  /* 0x8009CB34 */
    R[19] = lw_(R[29] + 28);  /* 0x8009CB38 */
    R[18] = lw_(R[29] + 24);  /* 0x8009CB3C */
    R[17] = lw_(R[29] + 20);  /* 0x8009CB40 */
    R[16] = lw_(R[29] + 16);  /* 0x8009CB44 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009CB48 jr ra */
}

void g0_8009CB4C(void) {
    R[29] = R[29] + 40;  /* 0x8009CB4C */
    psx_next = 0x8009CB50u; return;  /* fallthrough */
}

void g0_8009CB50(void) {
    R[29] = R[29] - 32;  /* 0x8009CB50 */
    R[3] = 0x800Fu << 16;  /* 0x8009CB54 */
    R[3] = lw_(R[3] + 25120);  /* 0x8009CB58 */
    R[2] = 0x8011u << 16;  /* 0x8009CB5C */
    sw_(R[29] + 16, R[16]);  /* 0x8009CB60 */
    R[16] = (uint32_t)(int16_t)lh_(R[2] + 29992);  /* 0x8009CB64 */
    sw_(R[29] + 20, R[17]);  /* 0x8009CB68 */
    R[17] = R[2] + 29992;  /* 0x8009CB6C */
    { uint32_t _c = (R[3] != R[0]); sw_(R[29] + 24, R[31]); if (_c) { goto L_8009CC58; } }  /* 0x8009CB70 */
    { R[31] = 0x8009CB80u; psx_next = 0x80087164u; return; }  /* 0x8009CB78 jal */
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_8009CC58; } }  /* 0x8009CB80 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 2);  /* 0x8009CB88 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009CC58; } }  /* 0x8009CB90 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 228);  /* 0x8009CB98 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8011u << 16; if (_c) { goto L_8009CC44; } }  /* 0x8009CBA0 */
    R[2] = 0x8006u << 16;  /* 0x8009CBA8 */
    R[7] = R[2] - 6456;  /* 0x8009CBAC */
    R[2] = 0x8006u << 16;  /* 0x8009CBB0 */
    R[6] = R[2] + 13192;  /* 0x8009CBB4 */
    R[5] = lh_(R[6] + 2930);  /* 0x8009CBB8 */
    R[2] = lh_(R[6] + 2932);  /* 0x8009CBBC */
    R[4] = lh_(R[7] + 2);  /* 0x8009CBC0 */
    R[2] = R[5] | R[2];  /* 0x8009CBC4 */
    R[3] = R[4] & R[2];  /* 0x8009CBC8 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[4] & R[5]; if (_c) { goto L_8009CC40; } }  /* 0x8009CBCC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_8009CC00; } }  /* 0x8009CBD4 */
    R[4] = 0x8013u << 16;  /* 0x8009CBDC */
    sh_(R[17] + 228, R[2]);  /* 0x8009CBE0 */
    sh_(R[17] + 230, R[2]);  /* 0x8009CBE4 */
    R[2] = lh_(R[17] + 226);  /* 0x8009CBE8 */
    R[3] = R[0] + 1;  /* 0x8009CBEC */
    sh_(R[4] + -29472, R[3]);  /* 0x8009CBF0 */
    R[2] = R[2] + 64;  /* 0x8009CBF4 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CBF8 */
    sh_(R[17] + 232, R[2]);  /* 0x8009CBFC */
L_8009CC00:;
    R[2] = lh_(R[7] + 2);  /* 0x8009CC00 */
    R[3] = lh_(R[6] + 2932);  /* 0x8009CC04 */
    R[2] = R[2] & R[3];  /* 0x8009CC0C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_8009CC40; } }  /* 0x8009CC10 */
    sh_(R[17] + 228, R[2]);  /* 0x8009CC18 */
    R[2] = R[0] - 8;  /* 0x8009CC1C */
    R[4] = 0x8013u << 16;  /* 0x8009CC20 */
    sh_(R[17] + 230, R[2]);  /* 0x8009CC24 */
    R[2] = lh_(R[17] + 226);  /* 0x8009CC28 */
    R[3] = R[0] + 1;  /* 0x8009CC2C */
    sh_(R[4] + -29472, R[3]);  /* 0x8009CC30 */
    R[2] = R[2] - 64;  /* 0x8009CC34 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CC38 */
    sh_(R[17] + 232, R[2]);  /* 0x8009CC3C */
L_8009CC40:;
    R[2] = 0x8011u << 16;  /* 0x8009CC40 */
L_8009CC44:;
    R[2] = R[2] + 29992;  /* 0x8009CC44 */
    R[3] = R[0] + 1;  /* 0x8009CC48 */
    sw_(R[2] + 264, R[3]);  /* 0x8009CC4C */
    sb_(R[2] + 92, R[0]);  /* 0x8009CC50 */
    sb_(R[2] + 93, R[3]);  /* 0x8009CC54 */
L_8009CC58:;
    R[31] = lw_(R[29] + 24);  /* 0x8009CC58 */
    R[17] = lw_(R[29] + 20);  /* 0x8009CC5C */
    R[16] = lw_(R[29] + 16);  /* 0x8009CC60 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009CC64 jr ra */
}

void g0_8009CB80(void) {
    { uint32_t _c = (R[16] != R[0]); if (_c) { goto L_8009CC58; } }  /* 0x8009CB80 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 2);  /* 0x8009CB88 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009CC58; } }  /* 0x8009CB90 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 228);  /* 0x8009CB98 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8011u << 16; if (_c) { goto L_8009CC44; } }  /* 0x8009CBA0 */
    R[2] = 0x8006u << 16;  /* 0x8009CBA8 */
    R[7] = R[2] - 6456;  /* 0x8009CBAC */
    R[2] = 0x8006u << 16;  /* 0x8009CBB0 */
    R[6] = R[2] + 13192;  /* 0x8009CBB4 */
    R[5] = lh_(R[6] + 2930);  /* 0x8009CBB8 */
    R[2] = lh_(R[6] + 2932);  /* 0x8009CBBC */
    R[4] = lh_(R[7] + 2);  /* 0x8009CBC0 */
    R[2] = R[5] | R[2];  /* 0x8009CBC4 */
    R[3] = R[4] & R[2];  /* 0x8009CBC8 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[4] & R[5]; if (_c) { goto L_8009CC40; } }  /* 0x8009CBCC */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_8009CC00; } }  /* 0x8009CBD4 */
    R[4] = 0x8013u << 16;  /* 0x8009CBDC */
    sh_(R[17] + 228, R[2]);  /* 0x8009CBE0 */
    sh_(R[17] + 230, R[2]);  /* 0x8009CBE4 */
    R[2] = lh_(R[17] + 226);  /* 0x8009CBE8 */
    R[3] = R[0] + 1;  /* 0x8009CBEC */
    sh_(R[4] + -29472, R[3]);  /* 0x8009CBF0 */
    R[2] = R[2] + 64;  /* 0x8009CBF4 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CBF8 */
    sh_(R[17] + 232, R[2]);  /* 0x8009CBFC */
L_8009CC00:;
    R[2] = lh_(R[7] + 2);  /* 0x8009CC00 */
    R[3] = lh_(R[6] + 2932);  /* 0x8009CC04 */
    R[2] = R[2] & R[3];  /* 0x8009CC0C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 8; if (_c) { goto L_8009CC40; } }  /* 0x8009CC10 */
    sh_(R[17] + 228, R[2]);  /* 0x8009CC18 */
    R[2] = R[0] - 8;  /* 0x8009CC1C */
    R[4] = 0x8013u << 16;  /* 0x8009CC20 */
    sh_(R[17] + 230, R[2]);  /* 0x8009CC24 */
    R[2] = lh_(R[17] + 226);  /* 0x8009CC28 */
    R[3] = R[0] + 1;  /* 0x8009CC2C */
    sh_(R[4] + -29472, R[3]);  /* 0x8009CC30 */
    R[2] = R[2] - 64;  /* 0x8009CC34 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CC38 */
    sh_(R[17] + 232, R[2]);  /* 0x8009CC3C */
L_8009CC40:;
    R[2] = 0x8011u << 16;  /* 0x8009CC40 */
L_8009CC44:;
    R[2] = R[2] + 29992;  /* 0x8009CC44 */
    R[3] = R[0] + 1;  /* 0x8009CC48 */
    sw_(R[2] + 264, R[3]);  /* 0x8009CC4C */
    sb_(R[2] + 92, R[0]);  /* 0x8009CC50 */
    sb_(R[2] + 93, R[3]);  /* 0x8009CC54 */
L_8009CC58:;
    R[31] = lw_(R[29] + 24);  /* 0x8009CC58 */
    R[17] = lw_(R[29] + 20);  /* 0x8009CC5C */
    R[16] = lw_(R[29] + 16);  /* 0x8009CC60 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009CC64 jr ra */
}

void g0_8009CC6C(void) {
    R[2] = 0x8006u << 16;  /* 0x8009CC6C */
    R[5] = R[2] - 6456;  /* 0x8009CC70 */
    R[4] = lw_(R[5] + 16);  /* 0x8009CC74 */
    R[2] = R[0] - 1;  /* 0x8009CC78 */
    { uint32_t _c = (R[4] == R[2]); R[2] = 0x8011u << 16; if (_c) { goto L_8009CCF8; } }  /* 0x8009CC7C */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 29992);  /* 0x8009CC84 */
    R[2] = R[0] + 2;  /* 0x8009CC88 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8013u << 16; if (_c) { goto L_8009CCB8; } }  /* 0x8009CC8C */
    R[3] = lh_(R[5] + 2);  /* 0x8009CC94 */
    R[2] = R[3] & 0x2000;  /* 0x8009CC9C */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x8000; if (_c) { goto L_8009CCAC; } }  /* 0x8009CCA0 */
    R[4] = R[0] + R[0];  /* 0x8009CCA8 */
L_8009CCAC:;
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009CCB8; } }  /* 0x8009CCAC */
    R[4] = R[0] + 256;  /* 0x8009CCB4 */
L_8009CCB8:;
    R[3] = R[2] - 29480;  /* 0x8009CCB8 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 8);  /* 0x8009CCBC */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8011u << 16; if (_c) { goto L_8009CCDC; } }  /* 0x8009CCC4 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 4);  /* 0x8009CCCC */
    { uint32_t _c = (R[4] == R[2]); R[2] = 0x8011u << 16; if (_c) { goto L_8009CCF4; } }  /* 0x8009CCD4 */
L_8009CCDC:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 30216);  /* 0x8009CCDC */
    R[2] = R[4] + R[2];  /* 0x8009CCE4 */
    R[2] = R[2] + 128;  /* 0x8009CCE8 */
    { R[4] = R[2] & 0x1FF; goto L_8009CCF8; }  /* 0x8009CCEC j */
L_8009CCF4:;
    R[4] = (uint32_t)(int16_t)lh_(R[3] + 6);  /* 0x8009CCF4 */
L_8009CCF8:;
    { R[2] = R[4] + R[0]; psx_next = R[31]; return; }  /* 0x8009CCF8 jr ra */
}

void g0_8009CD00(void) {
    R[29] = R[29] - 64;  /* 0x8009CD00 */
    sw_(R[29] + 28, R[17]);  /* 0x8009CD04 */
    R[17] = R[4] + R[0];  /* 0x8009CD08 */
    sw_(R[29] + 60, R[31]);  /* 0x8009CD0C */
    sw_(R[29] + 56, R[30]);  /* 0x8009CD10 */
    sw_(R[29] + 52, R[23]);  /* 0x8009CD14 */
    sw_(R[29] + 48, R[22]);  /* 0x8009CD18 */
    sw_(R[29] + 44, R[21]);  /* 0x8009CD1C */
    sw_(R[29] + 40, R[20]);  /* 0x8009CD20 */
    sw_(R[29] + 36, R[19]);  /* 0x8009CD24 */
    sw_(R[29] + 32, R[18]);  /* 0x8009CD28 */
    sw_(R[29] + 24, R[16]);  /* 0x8009CD2C */
    R[2] = lw_(R[17] + 576);  /* 0x8009CD30 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D080; } }  /* 0x8009CD38 */
    R[2] = 0x8006u << 16;  /* 0x8009CD40 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + -6440);  /* 0x8009CD44 */
    R[2] = R[0] - 1;  /* 0x8009CD48 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D080; } }  /* 0x8009CD4C */
    { R[31] = 0x8009CD5Cu; psx_next = 0x8009CC6Cu; return; }  /* 0x8009CD54 jal */
    R[3] = 0x8013u << 16;  /* 0x8009CD5C */
    R[3] = lw_(R[3] + 4152);  /* 0x8009CD60 */
    sw_(R[29] + 16, R[3]);  /* 0x8009CD68 */
    R[22] = lw_(R[3] + 528);  /* 0x8009CD6C */
    R[3] = lh_(R[22]);  /* 0x8009CD74 */
    R[30] = R[2] + R[0];  /* 0x8009CD78 */
    R[2] = R[3] & 0x8000;  /* 0x8009CD7C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009D07C; } }  /* 0x8009CD80 */
    R[20] = R[2] - 29656;  /* 0x8009CD88 */
    R[16] = R[22] + 32;  /* 0x8009CD8C */
L_8009CD90:;
    R[3] = R[3] & 0xFF;  /* 0x8009CD90 */
    R[2] = R[0] + 127;  /* 0x8009CD94 */
    { uint32_t _c = (R[3] == R[2]); R[4] = R[0] + R[0]; if (_c) { goto L_8009CDC4; } }  /* 0x8009CD98 */
    R[7] = lw_(R[29] + 16);  /* 0x8009CDA0 */
    R[2] = R[3] << 2;  /* 0x8009CDA4 */
    R[2] = R[7] + R[2];  /* 0x8009CDA8 */
    R[2] = lw_(R[2]);  /* 0x8009CDAC */
    R[2] = lh_(R[2]);  /* 0x8009CDB4 */
    R[2] = R[2] & 0x8000;  /* 0x8009CDBC */
    R[4] = (R[2] < (uint32_t)1u);  /* 0x8009CDC0 */
L_8009CDC4:;
    { uint32_t _c = (R[4] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CDC4 */
    R[2] = lb_(R[16] + -30);  /* 0x8009CDCC */
    R[3] = lw_(R[16] + -12);  /* 0x8009CDD0 */
    R[4] = R[2] << 1;  /* 0x8009CDD4 */
    R[21] = R[4] + R[0];  /* 0x8009CDD8 */
    R[2] = lw_(R[16] + -24);  /* 0x8009CDDC */
    R[19] = R[0] - R[2];  /* 0x8009CDE4 */
    R[2] = R[30] - R[4];  /* 0x8009CDE8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CDEC */
    R[2] = R[2] - 96;  /* 0x8009CDF0 */
    R[2] = (R[2] < (uint32_t)321u);  /* 0x8009CDF4 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[0] - R[3]; if (_c) { goto L_8009CFAC; } }  /* 0x8009CDF8 */
    R[4] = lw_(R[17] + 476);  /* 0x8009CE00 */
    R[2] = R[0] | 0xA000;  /* 0x8009CE04 */
    R[18] = R[4] + R[2];  /* 0x8009CE08 */
    R[2] = ((int32_t)R[18] < (int32_t)R[19]);  /* 0x8009CE0C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CE10 */
    R[2] = lw_(R[17] + 488);  /* 0x8009CE18 */
    R[2] = R[4] + R[2];  /* 0x8009CE20 */
    R[2] = ((int32_t)R[3] < (int32_t)R[2]);  /* 0x8009CE24 */
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[19]); if (_c) { goto L_8009D064; } }  /* 0x8009CE28 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[19] + R[0]; if (_c) { goto L_8009CE3C; } }  /* 0x8009CE30 */
    R[18] = R[4] + R[0];  /* 0x8009CE38 */
L_8009CE3C:;
    R[23] = R[0] + 1;  /* 0x8009CE3C */
L_8009CE40:;
    R[2] = lw_(R[16] + -16);  /* 0x8009CE40 */
    R[3] = lw_(R[16] + -28);  /* 0x8009CE44 */
    R[2] = R[2] - R[3];  /* 0x8009CE4C */
    sw_(R[20] + 104, R[2]);  /* 0x8009CE50 */
    R[2] = lw_(R[16] + -12);  /* 0x8009CE54 */
    R[3] = lw_(R[16] + -24);  /* 0x8009CE58 */
    R[4] = R[20] + 104;  /* 0x8009CE5C */
    R[2] = R[2] - R[3];  /* 0x8009CE60 */
    sw_(R[20] + 108, R[2]);  /* 0x8009CE64 */
    R[2] = lw_(R[16] + -8);  /* 0x8009CE68 */
    R[3] = lw_(R[16] + -20);  /* 0x8009CE6C */
    R[5] = R[4] + R[0];  /* 0x8009CE70 */
    R[2] = R[2] - R[3];  /* 0x8009CE74 */
    { R[31] = 0x8009CE80u; sw_(R[20] + 112, R[2]); psx_next = 0x800270ACu; return; }  /* 0x8009CE78 jal */
    R[2] = lw_(R[20] + 108);  /* 0x8009CE80 */
    R[3] = R[18] - R[19];  /* 0x8009CE84 */
    R[2] = R[0] - R[2];  /* 0x8009CE88 */
    psx_div((int32_t)R[3], (int32_t)R[2]);  /* 0x8009CE8C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009CE9C; } }  /* 0x8009CE90 */
    psx_break(7168);  /* 0x8009CE98 */
L_8009CE9C:;
    R[1] = R[0] - 1;  /* 0x8009CE9C */
    { uint32_t _c = (R[2] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_8009CEB4; } }  /* 0x8009CEA0 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_8009CEB4; } }  /* 0x8009CEA8 */
    psx_break(6144);  /* 0x8009CEB0 */
L_8009CEB4:;
    R[3] = LO;  /* 0x8009CEB4 */
    R[2] = lw_(R[20] + 104);  /* 0x8009CEB8 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009CEC0 */
    R[4] = lw_(R[17] + 472);  /* 0x8009CEC4 */
    R[2] = lw_(R[16] + -28);  /* 0x8009CEC8 */
    R[6] = LO;  /* 0x8009CECC */
    R[5] = R[2] + R[6];  /* 0x8009CED0 */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x8009CED4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CED8 */
    R[2] = lw_(R[17] + 484);  /* 0x8009CEE0 */
    R[2] = R[4] + R[2];  /* 0x8009CEE8 */
    R[2] = ((int32_t)R[5] < (int32_t)R[2]);  /* 0x8009CEEC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CEF0 */
    R[2] = lw_(R[20] + 112);  /* 0x8009CEF8 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009CF00 */
    R[2] = lw_(R[16] + -20);  /* 0x8009CF04 */
    R[3] = lw_(R[17] + 480);  /* 0x8009CF08 */
    R[7] = LO;  /* 0x8009CF0C */
    R[4] = R[2] + R[7];  /* 0x8009CF10 */
    R[2] = ((int32_t)R[3] < (int32_t)R[4]);  /* 0x8009CF14 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CF18 */
    R[2] = lw_(R[17] + 492);  /* 0x8009CF20 */
    R[2] = R[3] + R[2];  /* 0x8009CF28 */
    R[2] = ((int32_t)R[4] < (int32_t)R[2]);  /* 0x8009CF2C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CF30 */
    sw_(R[20] + 100, R[22]);  /* 0x8009CF38 */
    sh_(R[20] + 50, R[0]);  /* 0x8009CF3C */
    R[2] = lw_(R[17] + 24);  /* 0x8009CF40 */
    R[3] = lw_(R[17] + 28);  /* 0x8009CF44 */
    sw_(R[17] + 140, R[0]);  /* 0x8009CF48 */
    sb_(R[17] + 784, R[0]);  /* 0x8009CF4C */
    R[2] = R[5] - R[2];  /* 0x8009CF50 */
    sw_(R[17] + 196, R[2]);  /* 0x8009CF54 */
    R[2] = lw_(R[17] + 32);  /* 0x8009CF58 */
    R[3] = R[18] - R[3];  /* 0x8009CF5C */
    sw_(R[17] + 200, R[3]);  /* 0x8009CF60 */
    R[2] = R[4] - R[2];  /* 0x8009CF64 */
    sw_(R[17] + 204, R[2]);  /* 0x8009CF68 */
    R[2] = R[0] + 1;  /* 0x8009CF6C */
    { uint32_t _c = (R[23] != R[2]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CF8C; } }  /* 0x8009CF70 */
    { R[31] = 0x8009CF80u; R[5] = R[0] + 126; psx_next = 0x8009BC84u; return; }  /* 0x8009CF78 jal */
    sh_(R[17] + 4, R[21]);  /* 0x8009CF80 */
    { sh_(R[17] + 6, R[21]); goto L_8009CFA4; }  /* 0x8009CF84 j */
L_8009CF8C:;
    { R[31] = 0x8009CF94u; R[5] = R[0] + 123; psx_next = 0x8009BC84u; return; }  /* 0x8009CF8C jal */
    R[2] = R[21] + 256;  /* 0x8009CF94 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CF98 */
    sh_(R[17] + 6, R[21]);  /* 0x8009CF9C */
    sh_(R[17] + 4, R[2]);  /* 0x8009CFA0 */
L_8009CFA4:;
    { R[2] = R[0] + 1; goto L_8009D080; }  /* 0x8009CFA4 j */
L_8009CFAC:;
    R[2] = R[4] + 256;  /* 0x8009CFAC */
    R[2] = R[2] & 0x1FF;  /* 0x8009CFB0 */
    R[21] = R[2] + R[0];  /* 0x8009CFB4 */
    R[2] = R[30] - R[2];  /* 0x8009CFB8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CFBC */
    R[2] = R[2] - 96;  /* 0x8009CFC0 */
    R[2] = (R[2] < (uint32_t)321u);  /* 0x8009CFC4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x1u << 16; if (_c) { goto L_8009D064; } }  /* 0x8009CFC8 */
    R[6] = lw_(R[17] + 476);  /* 0x8009CFD0 */
    R[2] = R[2] | 0xE000;  /* 0x8009CFD4 */
    R[4] = R[0] | 0xF000;  /* 0x8009CFD8 */
    R[3] = R[3] - R[6];  /* 0x8009CFDC */
    R[3] = R[3] + R[4];  /* 0x8009CFE0 */
    R[2] = (R[2] < R[3]);  /* 0x8009CFE4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009D064; } }  /* 0x8009CFE8 */
    R[3] = lb_(R[17] + 784);  /* 0x8009CFF0 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009D064; } }  /* 0x8009CFF8 */
    R[4] = lw_(R[16] + -4);  /* 0x8009D000 */
    R[3] = lw_(R[17] + 472);  /* 0x8009D004 */
    R[5] = lw_(R[16]);  /* 0x8009D008 */
    R[2] = ((int32_t)R[4] < (int32_t)R[3]);  /* 0x8009D00C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D010 */
    R[2] = lw_(R[17] + 484);  /* 0x8009D018 */
    R[2] = R[3] + R[2];  /* 0x8009D020 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x8009D024 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D028 */
    R[3] = lw_(R[17] + 480);  /* 0x8009D030 */
    R[2] = ((int32_t)R[5] < (int32_t)R[3]);  /* 0x8009D038 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D03C */
    R[2] = lw_(R[17] + 492);  /* 0x8009D044 */
    R[2] = R[3] + R[2];  /* 0x8009D04C */
    R[2] = ((int32_t)R[2] < (int32_t)R[5]);  /* 0x8009D050 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[6] + R[0]; if (_c) { goto L_8009D064; } }  /* 0x8009D054 */
    { R[23] = R[0] + 2; psx_bb(); goto L_8009CE40; }  /* 0x8009D05C j */
L_8009D064:;
    R[22] = R[22] + 72;  /* 0x8009D064 */
    R[3] = lh_(R[22]);  /* 0x8009D068 */
    R[2] = R[3] & 0x8000;  /* 0x8009D070 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 72; if (_c) { psx_bb(); goto L_8009CD90; } }  /* 0x8009D074 */
L_8009D07C:;
    R[2] = R[0] + R[0];  /* 0x8009D07C */
L_8009D080:;
    R[31] = lw_(R[29] + 60);  /* 0x8009D080 */
    R[30] = lw_(R[29] + 56);  /* 0x8009D084 */
    R[23] = lw_(R[29] + 52);  /* 0x8009D088 */
    R[22] = lw_(R[29] + 48);  /* 0x8009D08C */
    R[21] = lw_(R[29] + 44);  /* 0x8009D090 */
    R[20] = lw_(R[29] + 40);  /* 0x8009D094 */
    R[19] = lw_(R[29] + 36);  /* 0x8009D098 */
    R[18] = lw_(R[29] + 32);  /* 0x8009D09C */
    R[17] = lw_(R[29] + 28);  /* 0x8009D0A0 */
    R[16] = lw_(R[29] + 24);  /* 0x8009D0A4 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8009D0A8 jr ra */
}

void g0_8009CD5C(void) {
    R[3] = 0x8013u << 16;  /* 0x8009CD5C */
    R[3] = lw_(R[3] + 4152);  /* 0x8009CD60 */
    sw_(R[29] + 16, R[3]);  /* 0x8009CD68 */
    R[22] = lw_(R[3] + 528);  /* 0x8009CD6C */
    R[3] = lh_(R[22]);  /* 0x8009CD74 */
    R[30] = R[2] + R[0];  /* 0x8009CD78 */
    R[2] = R[3] & 0x8000;  /* 0x8009CD7C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009D07C; } }  /* 0x8009CD80 */
    R[20] = R[2] - 29656;  /* 0x8009CD88 */
    R[16] = R[22] + 32;  /* 0x8009CD8C */
L_8009CD90:;
    R[3] = R[3] & 0xFF;  /* 0x8009CD90 */
    R[2] = R[0] + 127;  /* 0x8009CD94 */
    { uint32_t _c = (R[3] == R[2]); R[4] = R[0] + R[0]; if (_c) { goto L_8009CDC4; } }  /* 0x8009CD98 */
    R[7] = lw_(R[29] + 16);  /* 0x8009CDA0 */
    R[2] = R[3] << 2;  /* 0x8009CDA4 */
    R[2] = R[7] + R[2];  /* 0x8009CDA8 */
    R[2] = lw_(R[2]);  /* 0x8009CDAC */
    R[2] = lh_(R[2]);  /* 0x8009CDB4 */
    R[2] = R[2] & 0x8000;  /* 0x8009CDBC */
    R[4] = (R[2] < (uint32_t)1u);  /* 0x8009CDC0 */
L_8009CDC4:;
    { uint32_t _c = (R[4] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CDC4 */
    R[2] = lb_(R[16] + -30);  /* 0x8009CDCC */
    R[3] = lw_(R[16] + -12);  /* 0x8009CDD0 */
    R[4] = R[2] << 1;  /* 0x8009CDD4 */
    R[21] = R[4] + R[0];  /* 0x8009CDD8 */
    R[2] = lw_(R[16] + -24);  /* 0x8009CDDC */
    R[19] = R[0] - R[2];  /* 0x8009CDE4 */
    R[2] = R[30] - R[4];  /* 0x8009CDE8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CDEC */
    R[2] = R[2] - 96;  /* 0x8009CDF0 */
    R[2] = (R[2] < (uint32_t)321u);  /* 0x8009CDF4 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[0] - R[3]; if (_c) { goto L_8009CFAC; } }  /* 0x8009CDF8 */
    R[4] = lw_(R[17] + 476);  /* 0x8009CE00 */
    R[2] = R[0] | 0xA000;  /* 0x8009CE04 */
    R[18] = R[4] + R[2];  /* 0x8009CE08 */
    R[2] = ((int32_t)R[18] < (int32_t)R[19]);  /* 0x8009CE0C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CE10 */
    R[2] = lw_(R[17] + 488);  /* 0x8009CE18 */
    R[2] = R[4] + R[2];  /* 0x8009CE20 */
    R[2] = ((int32_t)R[3] < (int32_t)R[2]);  /* 0x8009CE24 */
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[19]); if (_c) { goto L_8009D064; } }  /* 0x8009CE28 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[19] + R[0]; if (_c) { goto L_8009CE3C; } }  /* 0x8009CE30 */
    R[18] = R[4] + R[0];  /* 0x8009CE38 */
L_8009CE3C:;
    R[23] = R[0] + 1;  /* 0x8009CE3C */
L_8009CE40:;
    R[2] = lw_(R[16] + -16);  /* 0x8009CE40 */
    R[3] = lw_(R[16] + -28);  /* 0x8009CE44 */
    R[2] = R[2] - R[3];  /* 0x8009CE4C */
    sw_(R[20] + 104, R[2]);  /* 0x8009CE50 */
    R[2] = lw_(R[16] + -12);  /* 0x8009CE54 */
    R[3] = lw_(R[16] + -24);  /* 0x8009CE58 */
    R[4] = R[20] + 104;  /* 0x8009CE5C */
    R[2] = R[2] - R[3];  /* 0x8009CE60 */
    sw_(R[20] + 108, R[2]);  /* 0x8009CE64 */
    R[2] = lw_(R[16] + -8);  /* 0x8009CE68 */
    R[3] = lw_(R[16] + -20);  /* 0x8009CE6C */
    R[5] = R[4] + R[0];  /* 0x8009CE70 */
    R[2] = R[2] - R[3];  /* 0x8009CE74 */
    { R[31] = 0x8009CE80u; sw_(R[20] + 112, R[2]); psx_next = 0x800270ACu; return; }  /* 0x8009CE78 jal */
    R[2] = lw_(R[20] + 108);  /* 0x8009CE80 */
    R[3] = R[18] - R[19];  /* 0x8009CE84 */
    R[2] = R[0] - R[2];  /* 0x8009CE88 */
    psx_div((int32_t)R[3], (int32_t)R[2]);  /* 0x8009CE8C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009CE9C; } }  /* 0x8009CE90 */
    psx_break(7168);  /* 0x8009CE98 */
L_8009CE9C:;
    R[1] = R[0] - 1;  /* 0x8009CE9C */
    { uint32_t _c = (R[2] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_8009CEB4; } }  /* 0x8009CEA0 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_8009CEB4; } }  /* 0x8009CEA8 */
    psx_break(6144);  /* 0x8009CEB0 */
L_8009CEB4:;
    R[3] = LO;  /* 0x8009CEB4 */
    R[2] = lw_(R[20] + 104);  /* 0x8009CEB8 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009CEC0 */
    R[4] = lw_(R[17] + 472);  /* 0x8009CEC4 */
    R[2] = lw_(R[16] + -28);  /* 0x8009CEC8 */
    R[6] = LO;  /* 0x8009CECC */
    R[5] = R[2] + R[6];  /* 0x8009CED0 */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x8009CED4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CED8 */
    R[2] = lw_(R[17] + 484);  /* 0x8009CEE0 */
    R[2] = R[4] + R[2];  /* 0x8009CEE8 */
    R[2] = ((int32_t)R[5] < (int32_t)R[2]);  /* 0x8009CEEC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CEF0 */
    R[2] = lw_(R[20] + 112);  /* 0x8009CEF8 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009CF00 */
    R[2] = lw_(R[16] + -20);  /* 0x8009CF04 */
    R[3] = lw_(R[17] + 480);  /* 0x8009CF08 */
    R[7] = LO;  /* 0x8009CF0C */
    R[4] = R[2] + R[7];  /* 0x8009CF10 */
    R[2] = ((int32_t)R[3] < (int32_t)R[4]);  /* 0x8009CF14 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CF18 */
    R[2] = lw_(R[17] + 492);  /* 0x8009CF20 */
    R[2] = R[3] + R[2];  /* 0x8009CF28 */
    R[2] = ((int32_t)R[4] < (int32_t)R[2]);  /* 0x8009CF2C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CF30 */
    sw_(R[20] + 100, R[22]);  /* 0x8009CF38 */
    sh_(R[20] + 50, R[0]);  /* 0x8009CF3C */
    R[2] = lw_(R[17] + 24);  /* 0x8009CF40 */
    R[3] = lw_(R[17] + 28);  /* 0x8009CF44 */
    sw_(R[17] + 140, R[0]);  /* 0x8009CF48 */
    sb_(R[17] + 784, R[0]);  /* 0x8009CF4C */
    R[2] = R[5] - R[2];  /* 0x8009CF50 */
    sw_(R[17] + 196, R[2]);  /* 0x8009CF54 */
    R[2] = lw_(R[17] + 32);  /* 0x8009CF58 */
    R[3] = R[18] - R[3];  /* 0x8009CF5C */
    sw_(R[17] + 200, R[3]);  /* 0x8009CF60 */
    R[2] = R[4] - R[2];  /* 0x8009CF64 */
    sw_(R[17] + 204, R[2]);  /* 0x8009CF68 */
    R[2] = R[0] + 1;  /* 0x8009CF6C */
    { uint32_t _c = (R[23] != R[2]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CF8C; } }  /* 0x8009CF70 */
    { R[31] = 0x8009CF80u; R[5] = R[0] + 126; psx_next = 0x8009BC84u; return; }  /* 0x8009CF78 jal */
    sh_(R[17] + 4, R[21]);  /* 0x8009CF80 */
    { sh_(R[17] + 6, R[21]); goto L_8009CFA4; }  /* 0x8009CF84 j */
L_8009CF8C:;
    { R[31] = 0x8009CF94u; R[5] = R[0] + 123; psx_next = 0x8009BC84u; return; }  /* 0x8009CF8C jal */
    R[2] = R[21] + 256;  /* 0x8009CF94 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CF98 */
    sh_(R[17] + 6, R[21]);  /* 0x8009CF9C */
    sh_(R[17] + 4, R[2]);  /* 0x8009CFA0 */
L_8009CFA4:;
    { R[2] = R[0] + 1; goto L_8009D080; }  /* 0x8009CFA4 j */
L_8009CFAC:;
    R[2] = R[4] + 256;  /* 0x8009CFAC */
    R[2] = R[2] & 0x1FF;  /* 0x8009CFB0 */
    R[21] = R[2] + R[0];  /* 0x8009CFB4 */
    R[2] = R[30] - R[2];  /* 0x8009CFB8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CFBC */
    R[2] = R[2] - 96;  /* 0x8009CFC0 */
    R[2] = (R[2] < (uint32_t)321u);  /* 0x8009CFC4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x1u << 16; if (_c) { goto L_8009D064; } }  /* 0x8009CFC8 */
    R[6] = lw_(R[17] + 476);  /* 0x8009CFD0 */
    R[2] = R[2] | 0xE000;  /* 0x8009CFD4 */
    R[4] = R[0] | 0xF000;  /* 0x8009CFD8 */
    R[3] = R[3] - R[6];  /* 0x8009CFDC */
    R[3] = R[3] + R[4];  /* 0x8009CFE0 */
    R[2] = (R[2] < R[3]);  /* 0x8009CFE4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009D064; } }  /* 0x8009CFE8 */
    R[3] = lb_(R[17] + 784);  /* 0x8009CFF0 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009D064; } }  /* 0x8009CFF8 */
    R[4] = lw_(R[16] + -4);  /* 0x8009D000 */
    R[3] = lw_(R[17] + 472);  /* 0x8009D004 */
    R[5] = lw_(R[16]);  /* 0x8009D008 */
    R[2] = ((int32_t)R[4] < (int32_t)R[3]);  /* 0x8009D00C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D010 */
    R[2] = lw_(R[17] + 484);  /* 0x8009D018 */
    R[2] = R[3] + R[2];  /* 0x8009D020 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x8009D024 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D028 */
    R[3] = lw_(R[17] + 480);  /* 0x8009D030 */
    R[2] = ((int32_t)R[5] < (int32_t)R[3]);  /* 0x8009D038 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D03C */
    R[2] = lw_(R[17] + 492);  /* 0x8009D044 */
    R[2] = R[3] + R[2];  /* 0x8009D04C */
    R[2] = ((int32_t)R[2] < (int32_t)R[5]);  /* 0x8009D050 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[6] + R[0]; if (_c) { goto L_8009D064; } }  /* 0x8009D054 */
    { R[23] = R[0] + 2; psx_bb(); goto L_8009CE40; }  /* 0x8009D05C j */
L_8009D064:;
    R[22] = R[22] + 72;  /* 0x8009D064 */
    R[3] = lh_(R[22]);  /* 0x8009D068 */
    R[2] = R[3] & 0x8000;  /* 0x8009D070 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 72; if (_c) { psx_bb(); goto L_8009CD90; } }  /* 0x8009D074 */
L_8009D07C:;
    R[2] = R[0] + R[0];  /* 0x8009D07C */
L_8009D080:;
    R[31] = lw_(R[29] + 60);  /* 0x8009D080 */
    R[30] = lw_(R[29] + 56);  /* 0x8009D084 */
    R[23] = lw_(R[29] + 52);  /* 0x8009D088 */
    R[22] = lw_(R[29] + 48);  /* 0x8009D08C */
    R[21] = lw_(R[29] + 44);  /* 0x8009D090 */
    R[20] = lw_(R[29] + 40);  /* 0x8009D094 */
    R[19] = lw_(R[29] + 36);  /* 0x8009D098 */
    R[18] = lw_(R[29] + 32);  /* 0x8009D09C */
    R[17] = lw_(R[29] + 28);  /* 0x8009D0A0 */
    R[16] = lw_(R[29] + 24);  /* 0x8009D0A4 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8009D0A8 jr ra */
}

void g0_8009CD90(void) {
L_8009CD90:;
    R[3] = R[3] & 0xFF;  /* 0x8009CD90 */
    R[2] = R[0] + 127;  /* 0x8009CD94 */
    { uint32_t _c = (R[3] == R[2]); R[4] = R[0] + R[0]; if (_c) { goto L_8009CDC4; } }  /* 0x8009CD98 */
    R[7] = lw_(R[29] + 16);  /* 0x8009CDA0 */
    R[2] = R[3] << 2;  /* 0x8009CDA4 */
    R[2] = R[7] + R[2];  /* 0x8009CDA8 */
    R[2] = lw_(R[2]);  /* 0x8009CDAC */
    R[2] = lh_(R[2]);  /* 0x8009CDB4 */
    R[2] = R[2] & 0x8000;  /* 0x8009CDBC */
    R[4] = (R[2] < (uint32_t)1u);  /* 0x8009CDC0 */
L_8009CDC4:;
    { uint32_t _c = (R[4] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CDC4 */
    R[2] = lb_(R[16] + -30);  /* 0x8009CDCC */
    R[3] = lw_(R[16] + -12);  /* 0x8009CDD0 */
    R[4] = R[2] << 1;  /* 0x8009CDD4 */
    R[21] = R[4] + R[0];  /* 0x8009CDD8 */
    R[2] = lw_(R[16] + -24);  /* 0x8009CDDC */
    R[19] = R[0] - R[2];  /* 0x8009CDE4 */
    R[2] = R[30] - R[4];  /* 0x8009CDE8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CDEC */
    R[2] = R[2] - 96;  /* 0x8009CDF0 */
    R[2] = (R[2] < (uint32_t)321u);  /* 0x8009CDF4 */
    { uint32_t _c = (R[2] != R[0]); R[3] = R[0] - R[3]; if (_c) { goto L_8009CFAC; } }  /* 0x8009CDF8 */
    R[4] = lw_(R[17] + 476);  /* 0x8009CE00 */
    R[2] = R[0] | 0xA000;  /* 0x8009CE04 */
    R[18] = R[4] + R[2];  /* 0x8009CE08 */
    R[2] = ((int32_t)R[18] < (int32_t)R[19]);  /* 0x8009CE0C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CE10 */
    R[2] = lw_(R[17] + 488);  /* 0x8009CE18 */
    R[2] = R[4] + R[2];  /* 0x8009CE20 */
    R[2] = ((int32_t)R[3] < (int32_t)R[2]);  /* 0x8009CE24 */
    { uint32_t _c = (R[2] != R[0]); R[2] = ((int32_t)R[4] < (int32_t)R[19]); if (_c) { goto L_8009D064; } }  /* 0x8009CE28 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[19] + R[0]; if (_c) { goto L_8009CE3C; } }  /* 0x8009CE30 */
    R[18] = R[4] + R[0];  /* 0x8009CE38 */
L_8009CE3C:;
    R[23] = R[0] + 1;  /* 0x8009CE3C */
L_8009CE40:;
    R[2] = lw_(R[16] + -16);  /* 0x8009CE40 */
    R[3] = lw_(R[16] + -28);  /* 0x8009CE44 */
    R[2] = R[2] - R[3];  /* 0x8009CE4C */
    sw_(R[20] + 104, R[2]);  /* 0x8009CE50 */
    R[2] = lw_(R[16] + -12);  /* 0x8009CE54 */
    R[3] = lw_(R[16] + -24);  /* 0x8009CE58 */
    R[4] = R[20] + 104;  /* 0x8009CE5C */
    R[2] = R[2] - R[3];  /* 0x8009CE60 */
    sw_(R[20] + 108, R[2]);  /* 0x8009CE64 */
    R[2] = lw_(R[16] + -8);  /* 0x8009CE68 */
    R[3] = lw_(R[16] + -20);  /* 0x8009CE6C */
    R[5] = R[4] + R[0];  /* 0x8009CE70 */
    R[2] = R[2] - R[3];  /* 0x8009CE74 */
    { R[31] = 0x8009CE80u; sw_(R[20] + 112, R[2]); psx_next = 0x800270ACu; return; }  /* 0x8009CE78 jal */
    R[2] = lw_(R[20] + 108);  /* 0x8009CE80 */
    R[3] = R[18] - R[19];  /* 0x8009CE84 */
    R[2] = R[0] - R[2];  /* 0x8009CE88 */
    psx_div((int32_t)R[3], (int32_t)R[2]);  /* 0x8009CE8C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009CE9C; } }  /* 0x8009CE90 */
    psx_break(7168);  /* 0x8009CE98 */
L_8009CE9C:;
    R[1] = R[0] - 1;  /* 0x8009CE9C */
    { uint32_t _c = (R[2] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_8009CEB4; } }  /* 0x8009CEA0 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_8009CEB4; } }  /* 0x8009CEA8 */
    psx_break(6144);  /* 0x8009CEB0 */
L_8009CEB4:;
    R[3] = LO;  /* 0x8009CEB4 */
    R[2] = lw_(R[20] + 104);  /* 0x8009CEB8 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009CEC0 */
    R[4] = lw_(R[17] + 472);  /* 0x8009CEC4 */
    R[2] = lw_(R[16] + -28);  /* 0x8009CEC8 */
    R[6] = LO;  /* 0x8009CECC */
    R[5] = R[2] + R[6];  /* 0x8009CED0 */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x8009CED4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CED8 */
    R[2] = lw_(R[17] + 484);  /* 0x8009CEE0 */
    R[2] = R[4] + R[2];  /* 0x8009CEE8 */
    R[2] = ((int32_t)R[5] < (int32_t)R[2]);  /* 0x8009CEEC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CEF0 */
    R[2] = lw_(R[20] + 112);  /* 0x8009CEF8 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009CF00 */
    R[2] = lw_(R[16] + -20);  /* 0x8009CF04 */
    R[3] = lw_(R[17] + 480);  /* 0x8009CF08 */
    R[7] = LO;  /* 0x8009CF0C */
    R[4] = R[2] + R[7];  /* 0x8009CF10 */
    R[2] = ((int32_t)R[3] < (int32_t)R[4]);  /* 0x8009CF14 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CF18 */
    R[2] = lw_(R[17] + 492);  /* 0x8009CF20 */
    R[2] = R[3] + R[2];  /* 0x8009CF28 */
    R[2] = ((int32_t)R[4] < (int32_t)R[2]);  /* 0x8009CF2C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CF30 */
    sw_(R[20] + 100, R[22]);  /* 0x8009CF38 */
    sh_(R[20] + 50, R[0]);  /* 0x8009CF3C */
    R[2] = lw_(R[17] + 24);  /* 0x8009CF40 */
    R[3] = lw_(R[17] + 28);  /* 0x8009CF44 */
    sw_(R[17] + 140, R[0]);  /* 0x8009CF48 */
    sb_(R[17] + 784, R[0]);  /* 0x8009CF4C */
    R[2] = R[5] - R[2];  /* 0x8009CF50 */
    sw_(R[17] + 196, R[2]);  /* 0x8009CF54 */
    R[2] = lw_(R[17] + 32);  /* 0x8009CF58 */
    R[3] = R[18] - R[3];  /* 0x8009CF5C */
    sw_(R[17] + 200, R[3]);  /* 0x8009CF60 */
    R[2] = R[4] - R[2];  /* 0x8009CF64 */
    sw_(R[17] + 204, R[2]);  /* 0x8009CF68 */
    R[2] = R[0] + 1;  /* 0x8009CF6C */
    { uint32_t _c = (R[23] != R[2]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CF8C; } }  /* 0x8009CF70 */
    { R[31] = 0x8009CF80u; R[5] = R[0] + 126; psx_next = 0x8009BC84u; return; }  /* 0x8009CF78 jal */
    sh_(R[17] + 4, R[21]);  /* 0x8009CF80 */
    { sh_(R[17] + 6, R[21]); goto L_8009CFA4; }  /* 0x8009CF84 j */
L_8009CF8C:;
    { R[31] = 0x8009CF94u; R[5] = R[0] + 123; psx_next = 0x8009BC84u; return; }  /* 0x8009CF8C jal */
    R[2] = R[21] + 256;  /* 0x8009CF94 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CF98 */
    sh_(R[17] + 6, R[21]);  /* 0x8009CF9C */
    sh_(R[17] + 4, R[2]);  /* 0x8009CFA0 */
L_8009CFA4:;
    { R[2] = R[0] + 1; goto L_8009D080; }  /* 0x8009CFA4 j */
L_8009CFAC:;
    R[2] = R[4] + 256;  /* 0x8009CFAC */
    R[2] = R[2] & 0x1FF;  /* 0x8009CFB0 */
    R[21] = R[2] + R[0];  /* 0x8009CFB4 */
    R[2] = R[30] - R[2];  /* 0x8009CFB8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CFBC */
    R[2] = R[2] - 96;  /* 0x8009CFC0 */
    R[2] = (R[2] < (uint32_t)321u);  /* 0x8009CFC4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x1u << 16; if (_c) { goto L_8009D064; } }  /* 0x8009CFC8 */
    R[6] = lw_(R[17] + 476);  /* 0x8009CFD0 */
    R[2] = R[2] | 0xE000;  /* 0x8009CFD4 */
    R[4] = R[0] | 0xF000;  /* 0x8009CFD8 */
    R[3] = R[3] - R[6];  /* 0x8009CFDC */
    R[3] = R[3] + R[4];  /* 0x8009CFE0 */
    R[2] = (R[2] < R[3]);  /* 0x8009CFE4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009D064; } }  /* 0x8009CFE8 */
    R[3] = lb_(R[17] + 784);  /* 0x8009CFF0 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009D064; } }  /* 0x8009CFF8 */
    R[4] = lw_(R[16] + -4);  /* 0x8009D000 */
    R[3] = lw_(R[17] + 472);  /* 0x8009D004 */
    R[5] = lw_(R[16]);  /* 0x8009D008 */
    R[2] = ((int32_t)R[4] < (int32_t)R[3]);  /* 0x8009D00C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D010 */
    R[2] = lw_(R[17] + 484);  /* 0x8009D018 */
    R[2] = R[3] + R[2];  /* 0x8009D020 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x8009D024 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D028 */
    R[3] = lw_(R[17] + 480);  /* 0x8009D030 */
    R[2] = ((int32_t)R[5] < (int32_t)R[3]);  /* 0x8009D038 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D03C */
    R[2] = lw_(R[17] + 492);  /* 0x8009D044 */
    R[2] = R[3] + R[2];  /* 0x8009D04C */
    R[2] = ((int32_t)R[2] < (int32_t)R[5]);  /* 0x8009D050 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[6] + R[0]; if (_c) { goto L_8009D064; } }  /* 0x8009D054 */
    { R[23] = R[0] + 2; psx_bb(); goto L_8009CE40; }  /* 0x8009D05C j */
L_8009D064:;
    R[22] = R[22] + 72;  /* 0x8009D064 */
    R[3] = lh_(R[22]);  /* 0x8009D068 */
    R[2] = R[3] & 0x8000;  /* 0x8009D070 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 72; if (_c) { psx_bb(); goto L_8009CD90; } }  /* 0x8009D074 */
    R[2] = R[0] + R[0];  /* 0x8009D07C */
L_8009D080:;
    R[31] = lw_(R[29] + 60);  /* 0x8009D080 */
    R[30] = lw_(R[29] + 56);  /* 0x8009D084 */
    R[23] = lw_(R[29] + 52);  /* 0x8009D088 */
    R[22] = lw_(R[29] + 48);  /* 0x8009D08C */
    R[21] = lw_(R[29] + 44);  /* 0x8009D090 */
    R[20] = lw_(R[29] + 40);  /* 0x8009D094 */
    R[19] = lw_(R[29] + 36);  /* 0x8009D098 */
    R[18] = lw_(R[29] + 32);  /* 0x8009D09C */
    R[17] = lw_(R[29] + 28);  /* 0x8009D0A0 */
    R[16] = lw_(R[29] + 24);  /* 0x8009D0A4 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8009D0A8 jr ra */
}

void g0_8009CE40(void) {
L_8009CE40:;
    R[2] = lw_(R[16] + -16);  /* 0x8009CE40 */
    R[3] = lw_(R[16] + -28);  /* 0x8009CE44 */
    R[2] = R[2] - R[3];  /* 0x8009CE4C */
    sw_(R[20] + 104, R[2]);  /* 0x8009CE50 */
    R[2] = lw_(R[16] + -12);  /* 0x8009CE54 */
    R[3] = lw_(R[16] + -24);  /* 0x8009CE58 */
    R[4] = R[20] + 104;  /* 0x8009CE5C */
    R[2] = R[2] - R[3];  /* 0x8009CE60 */
    sw_(R[20] + 108, R[2]);  /* 0x8009CE64 */
    R[2] = lw_(R[16] + -8);  /* 0x8009CE68 */
    R[3] = lw_(R[16] + -20);  /* 0x8009CE6C */
    R[5] = R[4] + R[0];  /* 0x8009CE70 */
    R[2] = R[2] - R[3];  /* 0x8009CE74 */
    { R[31] = 0x8009CE80u; sw_(R[20] + 112, R[2]); psx_next = 0x800270ACu; return; }  /* 0x8009CE78 jal */
    R[2] = lw_(R[20] + 108);  /* 0x8009CE80 */
    R[3] = R[18] - R[19];  /* 0x8009CE84 */
    R[2] = R[0] - R[2];  /* 0x8009CE88 */
    psx_div((int32_t)R[3], (int32_t)R[2]);  /* 0x8009CE8C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009CE9C; } }  /* 0x8009CE90 */
    psx_break(7168);  /* 0x8009CE98 */
L_8009CE9C:;
    R[1] = R[0] - 1;  /* 0x8009CE9C */
    { uint32_t _c = (R[2] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_8009CEB4; } }  /* 0x8009CEA0 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_8009CEB4; } }  /* 0x8009CEA8 */
    psx_break(6144);  /* 0x8009CEB0 */
L_8009CEB4:;
    R[3] = LO;  /* 0x8009CEB4 */
    R[2] = lw_(R[20] + 104);  /* 0x8009CEB8 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009CEC0 */
    R[4] = lw_(R[17] + 472);  /* 0x8009CEC4 */
    R[2] = lw_(R[16] + -28);  /* 0x8009CEC8 */
    R[6] = LO;  /* 0x8009CECC */
    R[5] = R[2] + R[6];  /* 0x8009CED0 */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x8009CED4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CED8 */
    R[2] = lw_(R[17] + 484);  /* 0x8009CEE0 */
    R[2] = R[4] + R[2];  /* 0x8009CEE8 */
    R[2] = ((int32_t)R[5] < (int32_t)R[2]);  /* 0x8009CEEC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CEF0 */
    R[2] = lw_(R[20] + 112);  /* 0x8009CEF8 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009CF00 */
    R[2] = lw_(R[16] + -20);  /* 0x8009CF04 */
    R[3] = lw_(R[17] + 480);  /* 0x8009CF08 */
    R[7] = LO;  /* 0x8009CF0C */
    R[4] = R[2] + R[7];  /* 0x8009CF10 */
    R[2] = ((int32_t)R[3] < (int32_t)R[4]);  /* 0x8009CF14 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CF18 */
    R[2] = lw_(R[17] + 492);  /* 0x8009CF20 */
    R[2] = R[3] + R[2];  /* 0x8009CF28 */
    R[2] = ((int32_t)R[4] < (int32_t)R[2]);  /* 0x8009CF2C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CF30 */
    sw_(R[20] + 100, R[22]);  /* 0x8009CF38 */
    sh_(R[20] + 50, R[0]);  /* 0x8009CF3C */
    R[2] = lw_(R[17] + 24);  /* 0x8009CF40 */
    R[3] = lw_(R[17] + 28);  /* 0x8009CF44 */
    sw_(R[17] + 140, R[0]);  /* 0x8009CF48 */
    sb_(R[17] + 784, R[0]);  /* 0x8009CF4C */
    R[2] = R[5] - R[2];  /* 0x8009CF50 */
    sw_(R[17] + 196, R[2]);  /* 0x8009CF54 */
    R[2] = lw_(R[17] + 32);  /* 0x8009CF58 */
    R[3] = R[18] - R[3];  /* 0x8009CF5C */
    sw_(R[17] + 200, R[3]);  /* 0x8009CF60 */
    R[2] = R[4] - R[2];  /* 0x8009CF64 */
    sw_(R[17] + 204, R[2]);  /* 0x8009CF68 */
    R[2] = R[0] + 1;  /* 0x8009CF6C */
    { uint32_t _c = (R[23] != R[2]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CF8C; } }  /* 0x8009CF70 */
    { R[31] = 0x8009CF80u; R[5] = R[0] + 126; psx_next = 0x8009BC84u; return; }  /* 0x8009CF78 jal */
    sh_(R[17] + 4, R[21]);  /* 0x8009CF80 */
    { sh_(R[17] + 6, R[21]); goto L_8009CFA4; }  /* 0x8009CF84 j */
L_8009CF8C:;
    { R[31] = 0x8009CF94u; R[5] = R[0] + 123; psx_next = 0x8009BC84u; return; }  /* 0x8009CF8C jal */
    R[2] = R[21] + 256;  /* 0x8009CF94 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CF98 */
    sh_(R[17] + 6, R[21]);  /* 0x8009CF9C */
    sh_(R[17] + 4, R[2]);  /* 0x8009CFA0 */
L_8009CFA4:;
    { R[2] = R[0] + 1; goto L_8009D080; }  /* 0x8009CFA4 j */
    R[2] = R[4] + 256;  /* 0x8009CFAC */
    R[2] = R[2] & 0x1FF;  /* 0x8009CFB0 */
    R[21] = R[2] + R[0];  /* 0x8009CFB4 */
    R[2] = R[30] - R[2];  /* 0x8009CFB8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CFBC */
    R[2] = R[2] - 96;  /* 0x8009CFC0 */
    R[2] = (R[2] < (uint32_t)321u);  /* 0x8009CFC4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x1u << 16; if (_c) { goto L_8009D064; } }  /* 0x8009CFC8 */
    R[6] = lw_(R[17] + 476);  /* 0x8009CFD0 */
    R[2] = R[2] | 0xE000;  /* 0x8009CFD4 */
    R[4] = R[0] | 0xF000;  /* 0x8009CFD8 */
    R[3] = R[3] - R[6];  /* 0x8009CFDC */
    R[3] = R[3] + R[4];  /* 0x8009CFE0 */
    R[2] = (R[2] < R[3]);  /* 0x8009CFE4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009D064; } }  /* 0x8009CFE8 */
    R[3] = lb_(R[17] + 784);  /* 0x8009CFF0 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009D064; } }  /* 0x8009CFF8 */
    R[4] = lw_(R[16] + -4);  /* 0x8009D000 */
    R[3] = lw_(R[17] + 472);  /* 0x8009D004 */
    R[5] = lw_(R[16]);  /* 0x8009D008 */
    R[2] = ((int32_t)R[4] < (int32_t)R[3]);  /* 0x8009D00C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D010 */
    R[2] = lw_(R[17] + 484);  /* 0x8009D018 */
    R[2] = R[3] + R[2];  /* 0x8009D020 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x8009D024 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D028 */
    R[3] = lw_(R[17] + 480);  /* 0x8009D030 */
    R[2] = ((int32_t)R[5] < (int32_t)R[3]);  /* 0x8009D038 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D03C */
    R[2] = lw_(R[17] + 492);  /* 0x8009D044 */
    R[2] = R[3] + R[2];  /* 0x8009D04C */
    R[2] = ((int32_t)R[2] < (int32_t)R[5]);  /* 0x8009D050 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[6] + R[0]; if (_c) { goto L_8009D064; } }  /* 0x8009D054 */
    { R[23] = R[0] + 2; psx_bb(); goto L_8009CE40; }  /* 0x8009D05C j */
L_8009D064:;
    R[22] = R[22] + 72;  /* 0x8009D064 */
    R[3] = lh_(R[22]);  /* 0x8009D068 */
    R[2] = R[3] & 0x8000;  /* 0x8009D070 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 72; if (_c) { psx_next = 0x8009CD90u; return; } }  /* 0x8009D074 b extern */
    R[2] = R[0] + R[0];  /* 0x8009D07C */
L_8009D080:;
    R[31] = lw_(R[29] + 60);  /* 0x8009D080 */
    R[30] = lw_(R[29] + 56);  /* 0x8009D084 */
    R[23] = lw_(R[29] + 52);  /* 0x8009D088 */
    R[22] = lw_(R[29] + 48);  /* 0x8009D08C */
    R[21] = lw_(R[29] + 44);  /* 0x8009D090 */
    R[20] = lw_(R[29] + 40);  /* 0x8009D094 */
    R[19] = lw_(R[29] + 36);  /* 0x8009D098 */
    R[18] = lw_(R[29] + 32);  /* 0x8009D09C */
    R[17] = lw_(R[29] + 28);  /* 0x8009D0A0 */
    R[16] = lw_(R[29] + 24);  /* 0x8009D0A4 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8009D0A8 jr ra */
}

void g0_8009CE80(void) {
    R[2] = lw_(R[20] + 108);  /* 0x8009CE80 */
    R[3] = R[18] - R[19];  /* 0x8009CE84 */
    R[2] = R[0] - R[2];  /* 0x8009CE88 */
    psx_div((int32_t)R[3], (int32_t)R[2]);  /* 0x8009CE8C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009CE9C; } }  /* 0x8009CE90 */
    psx_break(7168);  /* 0x8009CE98 */
L_8009CE9C:;
    R[1] = R[0] - 1;  /* 0x8009CE9C */
    { uint32_t _c = (R[2] != R[1]); R[1] = 0x8000u << 16; if (_c) { goto L_8009CEB4; } }  /* 0x8009CEA0 */
    { uint32_t _c = (R[3] != R[1]); if (_c) { goto L_8009CEB4; } }  /* 0x8009CEA8 */
    psx_break(6144);  /* 0x8009CEB0 */
L_8009CEB4:;
    R[3] = LO;  /* 0x8009CEB4 */
    R[2] = lw_(R[20] + 104);  /* 0x8009CEB8 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009CEC0 */
    R[4] = lw_(R[17] + 472);  /* 0x8009CEC4 */
    R[2] = lw_(R[16] + -28);  /* 0x8009CEC8 */
    R[6] = LO;  /* 0x8009CECC */
    R[5] = R[2] + R[6];  /* 0x8009CED0 */
    R[2] = ((int32_t)R[4] < (int32_t)R[5]);  /* 0x8009CED4 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CED8 */
    R[2] = lw_(R[17] + 484);  /* 0x8009CEE0 */
    R[2] = R[4] + R[2];  /* 0x8009CEE8 */
    R[2] = ((int32_t)R[5] < (int32_t)R[2]);  /* 0x8009CEEC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CEF0 */
    R[2] = lw_(R[20] + 112);  /* 0x8009CEF8 */
    { int64_t _p = (int64_t)(int32_t)R[3] * (int32_t)R[2]; LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }  /* 0x8009CF00 */
    R[2] = lw_(R[16] + -20);  /* 0x8009CF04 */
    R[3] = lw_(R[17] + 480);  /* 0x8009CF08 */
    R[7] = LO;  /* 0x8009CF0C */
    R[4] = R[2] + R[7];  /* 0x8009CF10 */
    R[2] = ((int32_t)R[3] < (int32_t)R[4]);  /* 0x8009CF14 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CF18 */
    R[2] = lw_(R[17] + 492);  /* 0x8009CF20 */
    R[2] = R[3] + R[2];  /* 0x8009CF28 */
    R[2] = ((int32_t)R[4] < (int32_t)R[2]);  /* 0x8009CF2C */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009CF30 */
    sw_(R[20] + 100, R[22]);  /* 0x8009CF38 */
    sh_(R[20] + 50, R[0]);  /* 0x8009CF3C */
    R[2] = lw_(R[17] + 24);  /* 0x8009CF40 */
    R[3] = lw_(R[17] + 28);  /* 0x8009CF44 */
    sw_(R[17] + 140, R[0]);  /* 0x8009CF48 */
    sb_(R[17] + 784, R[0]);  /* 0x8009CF4C */
    R[2] = R[5] - R[2];  /* 0x8009CF50 */
    sw_(R[17] + 196, R[2]);  /* 0x8009CF54 */
    R[2] = lw_(R[17] + 32);  /* 0x8009CF58 */
    R[3] = R[18] - R[3];  /* 0x8009CF5C */
    sw_(R[17] + 200, R[3]);  /* 0x8009CF60 */
    R[2] = R[4] - R[2];  /* 0x8009CF64 */
    sw_(R[17] + 204, R[2]);  /* 0x8009CF68 */
    R[2] = R[0] + 1;  /* 0x8009CF6C */
    { uint32_t _c = (R[23] != R[2]); R[4] = R[17] + R[0]; if (_c) { goto L_8009CF8C; } }  /* 0x8009CF70 */
    { R[31] = 0x8009CF80u; R[5] = R[0] + 126; psx_next = 0x8009BC84u; return; }  /* 0x8009CF78 jal */
    sh_(R[17] + 4, R[21]);  /* 0x8009CF80 */
    { sh_(R[17] + 6, R[21]); goto L_8009CFA4; }  /* 0x8009CF84 j */
L_8009CF8C:;
    { R[31] = 0x8009CF94u; R[5] = R[0] + 123; psx_next = 0x8009BC84u; return; }  /* 0x8009CF8C jal */
    R[2] = R[21] + 256;  /* 0x8009CF94 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CF98 */
    sh_(R[17] + 6, R[21]);  /* 0x8009CF9C */
    sh_(R[17] + 4, R[2]);  /* 0x8009CFA0 */
L_8009CFA4:;
    { R[2] = R[0] + 1; goto L_8009D080; }  /* 0x8009CFA4 j */
    R[2] = R[4] + 256;  /* 0x8009CFAC */
    R[2] = R[2] & 0x1FF;  /* 0x8009CFB0 */
    R[21] = R[2] + R[0];  /* 0x8009CFB4 */
    R[2] = R[30] - R[2];  /* 0x8009CFB8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CFBC */
    R[2] = R[2] - 96;  /* 0x8009CFC0 */
    R[2] = (R[2] < (uint32_t)321u);  /* 0x8009CFC4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x1u << 16; if (_c) { goto L_8009D064; } }  /* 0x8009CFC8 */
    R[6] = lw_(R[17] + 476);  /* 0x8009CFD0 */
    R[2] = R[2] | 0xE000;  /* 0x8009CFD4 */
    R[4] = R[0] | 0xF000;  /* 0x8009CFD8 */
    R[3] = R[3] - R[6];  /* 0x8009CFDC */
    R[3] = R[3] + R[4];  /* 0x8009CFE0 */
    R[2] = (R[2] < R[3]);  /* 0x8009CFE4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009D064; } }  /* 0x8009CFE8 */
    R[3] = lb_(R[17] + 784);  /* 0x8009CFF0 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009D064; } }  /* 0x8009CFF8 */
    R[4] = lw_(R[16] + -4);  /* 0x8009D000 */
    R[3] = lw_(R[17] + 472);  /* 0x8009D004 */
    R[5] = lw_(R[16]);  /* 0x8009D008 */
    R[2] = ((int32_t)R[4] < (int32_t)R[3]);  /* 0x8009D00C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D010 */
    R[2] = lw_(R[17] + 484);  /* 0x8009D018 */
    R[2] = R[3] + R[2];  /* 0x8009D020 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x8009D024 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D028 */
    R[3] = lw_(R[17] + 480);  /* 0x8009D030 */
    R[2] = ((int32_t)R[5] < (int32_t)R[3]);  /* 0x8009D038 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D03C */
    R[2] = lw_(R[17] + 492);  /* 0x8009D044 */
    R[2] = R[3] + R[2];  /* 0x8009D04C */
    R[2] = ((int32_t)R[2] < (int32_t)R[5]);  /* 0x8009D050 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[6] + R[0]; if (_c) { goto L_8009D064; } }  /* 0x8009D054 */
    { R[23] = R[0] + 2; psx_next = 0x8009CE40u; return; }  /* 0x8009D05C j extern */
L_8009D064:;
    R[22] = R[22] + 72;  /* 0x8009D064 */
    R[3] = lh_(R[22]);  /* 0x8009D068 */
    R[2] = R[3] & 0x8000;  /* 0x8009D070 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 72; if (_c) { psx_next = 0x8009CD90u; return; } }  /* 0x8009D074 b extern */
    R[2] = R[0] + R[0];  /* 0x8009D07C */
L_8009D080:;
    R[31] = lw_(R[29] + 60);  /* 0x8009D080 */
    R[30] = lw_(R[29] + 56);  /* 0x8009D084 */
    R[23] = lw_(R[29] + 52);  /* 0x8009D088 */
    R[22] = lw_(R[29] + 48);  /* 0x8009D08C */
    R[21] = lw_(R[29] + 44);  /* 0x8009D090 */
    R[20] = lw_(R[29] + 40);  /* 0x8009D094 */
    R[19] = lw_(R[29] + 36);  /* 0x8009D098 */
    R[18] = lw_(R[29] + 32);  /* 0x8009D09C */
    R[17] = lw_(R[29] + 28);  /* 0x8009D0A0 */
    R[16] = lw_(R[29] + 24);  /* 0x8009D0A4 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8009D0A8 jr ra */
}

void g0_8009CF80(void) {
    sh_(R[17] + 4, R[21]);  /* 0x8009CF80 */
    { sh_(R[17] + 6, R[21]); goto L_8009CFA4; }  /* 0x8009CF84 j */
    { R[31] = 0x8009CF94u; R[5] = R[0] + 123; psx_next = 0x8009BC84u; return; }  /* 0x8009CF8C jal */
    R[2] = R[21] + 256;  /* 0x8009CF94 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CF98 */
    sh_(R[17] + 6, R[21]);  /* 0x8009CF9C */
    sh_(R[17] + 4, R[2]);  /* 0x8009CFA0 */
L_8009CFA4:;
    { R[2] = R[0] + 1; goto L_8009D080; }  /* 0x8009CFA4 j */
    R[2] = R[4] + 256;  /* 0x8009CFAC */
    R[2] = R[2] & 0x1FF;  /* 0x8009CFB0 */
    R[21] = R[2] + R[0];  /* 0x8009CFB4 */
    R[2] = R[30] - R[2];  /* 0x8009CFB8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CFBC */
    R[2] = R[2] - 96;  /* 0x8009CFC0 */
    R[2] = (R[2] < (uint32_t)321u);  /* 0x8009CFC4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x1u << 16; if (_c) { goto L_8009D064; } }  /* 0x8009CFC8 */
    R[6] = lw_(R[17] + 476);  /* 0x8009CFD0 */
    R[2] = R[2] | 0xE000;  /* 0x8009CFD4 */
    R[4] = R[0] | 0xF000;  /* 0x8009CFD8 */
    R[3] = R[3] - R[6];  /* 0x8009CFDC */
    R[3] = R[3] + R[4];  /* 0x8009CFE0 */
    R[2] = (R[2] < R[3]);  /* 0x8009CFE4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009D064; } }  /* 0x8009CFE8 */
    R[3] = lb_(R[17] + 784);  /* 0x8009CFF0 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009D064; } }  /* 0x8009CFF8 */
    R[4] = lw_(R[16] + -4);  /* 0x8009D000 */
    R[3] = lw_(R[17] + 472);  /* 0x8009D004 */
    R[5] = lw_(R[16]);  /* 0x8009D008 */
    R[2] = ((int32_t)R[4] < (int32_t)R[3]);  /* 0x8009D00C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D010 */
    R[2] = lw_(R[17] + 484);  /* 0x8009D018 */
    R[2] = R[3] + R[2];  /* 0x8009D020 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x8009D024 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D028 */
    R[3] = lw_(R[17] + 480);  /* 0x8009D030 */
    R[2] = ((int32_t)R[5] < (int32_t)R[3]);  /* 0x8009D038 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D03C */
    R[2] = lw_(R[17] + 492);  /* 0x8009D044 */
    R[2] = R[3] + R[2];  /* 0x8009D04C */
    R[2] = ((int32_t)R[2] < (int32_t)R[5]);  /* 0x8009D050 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[6] + R[0]; if (_c) { goto L_8009D064; } }  /* 0x8009D054 */
    { R[23] = R[0] + 2; psx_next = 0x8009CE40u; return; }  /* 0x8009D05C j extern */
L_8009D064:;
    R[22] = R[22] + 72;  /* 0x8009D064 */
    R[3] = lh_(R[22]);  /* 0x8009D068 */
    R[2] = R[3] & 0x8000;  /* 0x8009D070 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 72; if (_c) { psx_next = 0x8009CD90u; return; } }  /* 0x8009D074 b extern */
    R[2] = R[0] + R[0];  /* 0x8009D07C */
L_8009D080:;
    R[31] = lw_(R[29] + 60);  /* 0x8009D080 */
    R[30] = lw_(R[29] + 56);  /* 0x8009D084 */
    R[23] = lw_(R[29] + 52);  /* 0x8009D088 */
    R[22] = lw_(R[29] + 48);  /* 0x8009D08C */
    R[21] = lw_(R[29] + 44);  /* 0x8009D090 */
    R[20] = lw_(R[29] + 40);  /* 0x8009D094 */
    R[19] = lw_(R[29] + 36);  /* 0x8009D098 */
    R[18] = lw_(R[29] + 32);  /* 0x8009D09C */
    R[17] = lw_(R[29] + 28);  /* 0x8009D0A0 */
    R[16] = lw_(R[29] + 24);  /* 0x8009D0A4 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8009D0A8 jr ra */
}

void g0_8009CF94(void) {
    R[2] = R[21] + 256;  /* 0x8009CF94 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CF98 */
    sh_(R[17] + 6, R[21]);  /* 0x8009CF9C */
    sh_(R[17] + 4, R[2]);  /* 0x8009CFA0 */
    { R[2] = R[0] + 1; goto L_8009D080; }  /* 0x8009CFA4 j */
    R[2] = R[4] + 256;  /* 0x8009CFAC */
    R[2] = R[2] & 0x1FF;  /* 0x8009CFB0 */
    R[21] = R[2] + R[0];  /* 0x8009CFB4 */
    R[2] = R[30] - R[2];  /* 0x8009CFB8 */
    R[2] = R[2] & 0x1FF;  /* 0x8009CFBC */
    R[2] = R[2] - 96;  /* 0x8009CFC0 */
    R[2] = (R[2] < (uint32_t)321u);  /* 0x8009CFC4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x1u << 16; if (_c) { goto L_8009D064; } }  /* 0x8009CFC8 */
    R[6] = lw_(R[17] + 476);  /* 0x8009CFD0 */
    R[2] = R[2] | 0xE000;  /* 0x8009CFD4 */
    R[4] = R[0] | 0xF000;  /* 0x8009CFD8 */
    R[3] = R[3] - R[6];  /* 0x8009CFDC */
    R[3] = R[3] + R[4];  /* 0x8009CFE0 */
    R[2] = (R[2] < R[3]);  /* 0x8009CFE4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009D064; } }  /* 0x8009CFE8 */
    R[3] = lb_(R[17] + 784);  /* 0x8009CFF0 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009D064; } }  /* 0x8009CFF8 */
    R[4] = lw_(R[16] + -4);  /* 0x8009D000 */
    R[3] = lw_(R[17] + 472);  /* 0x8009D004 */
    R[5] = lw_(R[16]);  /* 0x8009D008 */
    R[2] = ((int32_t)R[4] < (int32_t)R[3]);  /* 0x8009D00C */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D010 */
    R[2] = lw_(R[17] + 484);  /* 0x8009D018 */
    R[2] = R[3] + R[2];  /* 0x8009D020 */
    R[2] = ((int32_t)R[2] < (int32_t)R[4]);  /* 0x8009D024 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D028 */
    R[3] = lw_(R[17] + 480);  /* 0x8009D030 */
    R[2] = ((int32_t)R[5] < (int32_t)R[3]);  /* 0x8009D038 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D064; } }  /* 0x8009D03C */
    R[2] = lw_(R[17] + 492);  /* 0x8009D044 */
    R[2] = R[3] + R[2];  /* 0x8009D04C */
    R[2] = ((int32_t)R[2] < (int32_t)R[5]);  /* 0x8009D050 */
    { uint32_t _c = (R[2] != R[0]); R[18] = R[6] + R[0]; if (_c) { goto L_8009D064; } }  /* 0x8009D054 */
    { R[23] = R[0] + 2; psx_next = 0x8009CE40u; return; }  /* 0x8009D05C j extern */
L_8009D064:;
    R[22] = R[22] + 72;  /* 0x8009D064 */
    R[3] = lh_(R[22]);  /* 0x8009D068 */
    R[2] = R[3] & 0x8000;  /* 0x8009D070 */
    { uint32_t _c = (R[2] != R[0]); R[16] = R[16] + 72; if (_c) { psx_next = 0x8009CD90u; return; } }  /* 0x8009D074 b extern */
    R[2] = R[0] + R[0];  /* 0x8009D07C */
L_8009D080:;
    R[31] = lw_(R[29] + 60);  /* 0x8009D080 */
    R[30] = lw_(R[29] + 56);  /* 0x8009D084 */
    R[23] = lw_(R[29] + 52);  /* 0x8009D088 */
    R[22] = lw_(R[29] + 48);  /* 0x8009D08C */
    R[21] = lw_(R[29] + 44);  /* 0x8009D090 */
    R[20] = lw_(R[29] + 40);  /* 0x8009D094 */
    R[19] = lw_(R[29] + 36);  /* 0x8009D098 */
    R[18] = lw_(R[29] + 32);  /* 0x8009D09C */
    R[17] = lw_(R[29] + 28);  /* 0x8009D0A0 */
    R[16] = lw_(R[29] + 24);  /* 0x8009D0A4 */
    { R[29] = R[29] + 64; psx_next = R[31]; return; }  /* 0x8009D0A8 jr ra */
}

void g0_8009D0B0(void) {
    R[29] = R[29] - 48;  /* 0x8009D0B0 */
    sw_(R[29] + 20, R[17]);  /* 0x8009D0B4 */
    R[17] = R[4] + R[0];  /* 0x8009D0B8 */
    sw_(R[29] + 36, R[21]);  /* 0x8009D0BC */
    R[21] = R[5] + R[0];  /* 0x8009D0C0 */
    sw_(R[29] + 32, R[20]);  /* 0x8009D0C4 */
    R[20] = R[6] + R[0];  /* 0x8009D0C8 */
    sw_(R[29] + 28, R[19]);  /* 0x8009D0CC */
    R[2] = 0x8006u << 16;  /* 0x8009D0D0 */
    sw_(R[29] + 24, R[18]);  /* 0x8009D0D4 */
    R[18] = R[2] - 6456;  /* 0x8009D0D8 */
    sw_(R[29] + 40, R[31]);  /* 0x8009D0DC */
    sw_(R[29] + 16, R[16]);  /* 0x8009D0E0 */
    R[16] = lw_(R[18] + 16);  /* 0x8009D0E4 */
    R[2] = R[0] - 1;  /* 0x8009D0E8 */
    { uint32_t _c = (R[16] == R[2]); R[19] = R[7] + R[0]; if (_c) { goto L_8009D20C; } }  /* 0x8009D0EC */
    { R[31] = 0x8009D0FCu; R[4] = R[0] + 599; psx_next = 0x8001D36Cu; return; }  /* 0x8009D0F4 jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009D108; } }  /* 0x8009D0FC */
    sh_(R[2] + -29472, R[0]);  /* 0x8009D104 */
L_8009D108:;
    R[2] = 0x8011u << 16;  /* 0x8009D108 */
    R[4] = R[2] + 29992;  /* 0x8009D10C */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 29992);  /* 0x8009D110 */
    R[2] = R[0] + 2;  /* 0x8009D114 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8013u << 16; if (_c) { goto L_8009D178; } }  /* 0x8009D118 */
    R[3] = lh_(R[18] + 2);  /* 0x8009D120 */
    R[2] = R[3] & 0x2000;  /* 0x8009D128 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x8000; if (_c) { goto L_8009D138; } }  /* 0x8009D12C */
    R[16] = R[0] + R[0];  /* 0x8009D134 */
L_8009D138:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D144; } }  /* 0x8009D138 */
    R[16] = R[0] + 256;  /* 0x8009D140 */
L_8009D144:;
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 224);  /* 0x8009D144 */
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 226);  /* 0x8009D148 */
    R[2] = R[16] + R[2];  /* 0x8009D14C */
    R[2] = R[2] + 128;  /* 0x8009D150 */
    R[2] = R[2] & 0x1FF;  /* 0x8009D154 */
    R[2] = R[2] - R[3];  /* 0x8009D158 */
    R[3] = R[2] & 0x1FF;  /* 0x8009D15C */
    R[2] = R[0] + 128;  /* 0x8009D160 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 384; if (_c) { goto L_8009D174; } }  /* 0x8009D164 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] - 1; if (_c) { goto L_8009D20C; } }  /* 0x8009D16C */
L_8009D174:;
    R[2] = 0x8013u << 16;  /* 0x8009D174 */
L_8009D178:;
    R[3] = R[2] - 29480;  /* 0x8009D178 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 8);  /* 0x8009D17C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8011u << 16; if (_c) { goto L_8009D1B0; } }  /* 0x8009D184 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 4);  /* 0x8009D18C */
    { uint32_t _c = (R[16] != R[2]); R[2] = 0x8011u << 16; if (_c) { goto L_8009D1B0; } }  /* 0x8009D194 */
    R[2] = 0x8013u << 16;  /* 0x8009D19C */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + -29612);  /* 0x8009D1A0 */
    { uint32_t _c = (R[2] == R[19]); R[2] = 0x8011u << 16; if (_c) { goto L_8009D1E8; } }  /* 0x8009D1A8 */
L_8009D1B0:;
    R[3] = 0x8013u << 16;  /* 0x8009D1B0 */
    R[2] = lh_(R[2] + 30216);  /* 0x8009D1B4 */
    R[3] = R[3] - 29480;  /* 0x8009D1B8 */
    R[2] = R[2] + R[16];  /* 0x8009D1BC */
    R[2] = R[2] + 128;  /* 0x8009D1C0 */
    R[2] = R[2] & 0x1FF;  /* 0x8009D1C4 */
    sh_(R[17] + 6, R[2]);  /* 0x8009D1C8 */
    { uint32_t _c = (R[19] == R[0]); sh_(R[3] + 6, R[2]); if (_c) { goto L_8009D1E0; } }  /* 0x8009D1CC */
    R[2] = lh_(R[17] + 6);  /* 0x8009D1D4 */
    sh_(R[17] + 4, R[2]);  /* 0x8009D1DC */
L_8009D1E0:;
    sh_(R[3] + 4, R[16]);  /* 0x8009D1E0 */
    sh_(R[3] + 8, R[0]);  /* 0x8009D1E4 */
L_8009D1E8:;
    R[2] = R[0] - 1;  /* 0x8009D1E8 */
    { uint32_t _c = (R[21] == R[2]); R[4] = R[17] + R[0]; if (_c) { goto L_8009D1FC; } }  /* 0x8009D1EC */
    { R[31] = 0x8009D1FCu; R[5] = R[21] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009D1F4 jal */
L_8009D1FC:;
    R[2] = 0x8013u << 16;  /* 0x8009D1FC */
    sh_(R[2] + -29612, R[19]);  /* 0x8009D200 */
    { R[2] = R[0] + 1; goto L_8009D244; }  /* 0x8009D204 j */
L_8009D20C:;
    { uint32_t _c = (R[20] == R[2]); R[4] = R[17] + R[0]; if (_c) { goto L_8009D21C; } }  /* 0x8009D20C */
    { R[31] = 0x8009D21Cu; R[5] = R[20] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009D214 jal */
L_8009D21C:;
    R[2] = 0x8013u << 16;  /* 0x8009D21C */
    R[2] = R[2] - 29480;  /* 0x8009D220 */
    sh_(R[2] + 6, R[16]);  /* 0x8009D224 */
    sh_(R[2] + 4, R[16]);  /* 0x8009D228 */
    sh_(R[2] + 8, R[0]);  /* 0x8009D22C */
    R[3] = lh_(R[17] + 4);  /* 0x8009D230 */
    R[2] = R[0] + R[0];  /* 0x8009D234 */
    sh_(R[17] + 6, R[3]);  /* 0x8009D238 */
    R[3] = 0x8013u << 16;  /* 0x8009D23C */
    sh_(R[3] + -29612, R[19]);  /* 0x8009D240 */
L_8009D244:;
    R[31] = lw_(R[29] + 40);  /* 0x8009D244 */
    R[21] = lw_(R[29] + 36);  /* 0x8009D248 */
    R[20] = lw_(R[29] + 32);  /* 0x8009D24C */
    R[19] = lw_(R[29] + 28);  /* 0x8009D250 */
    R[18] = lw_(R[29] + 24);  /* 0x8009D254 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D258 */
    R[16] = lw_(R[29] + 16);  /* 0x8009D25C */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009D260 jr ra */
}

void g0_8009D0FC(void) {
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009D108; } }  /* 0x8009D0FC */
    sh_(R[2] + -29472, R[0]);  /* 0x8009D104 */
L_8009D108:;
    R[2] = 0x8011u << 16;  /* 0x8009D108 */
    R[4] = R[2] + 29992;  /* 0x8009D10C */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + 29992);  /* 0x8009D110 */
    R[2] = R[0] + 2;  /* 0x8009D114 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8013u << 16; if (_c) { goto L_8009D178; } }  /* 0x8009D118 */
    R[3] = lh_(R[18] + 2);  /* 0x8009D120 */
    R[2] = R[3] & 0x2000;  /* 0x8009D128 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[3] & 0x8000; if (_c) { goto L_8009D138; } }  /* 0x8009D12C */
    R[16] = R[0] + R[0];  /* 0x8009D134 */
L_8009D138:;
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D144; } }  /* 0x8009D138 */
    R[16] = R[0] + 256;  /* 0x8009D140 */
L_8009D144:;
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 224);  /* 0x8009D144 */
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 226);  /* 0x8009D148 */
    R[2] = R[16] + R[2];  /* 0x8009D14C */
    R[2] = R[2] + 128;  /* 0x8009D150 */
    R[2] = R[2] & 0x1FF;  /* 0x8009D154 */
    R[2] = R[2] - R[3];  /* 0x8009D158 */
    R[3] = R[2] & 0x1FF;  /* 0x8009D15C */
    R[2] = R[0] + 128;  /* 0x8009D160 */
    { uint32_t _c = (R[3] == R[2]); R[2] = R[0] + 384; if (_c) { goto L_8009D174; } }  /* 0x8009D164 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] - 1; if (_c) { goto L_8009D20C; } }  /* 0x8009D16C */
L_8009D174:;
    R[2] = 0x8013u << 16;  /* 0x8009D174 */
L_8009D178:;
    R[3] = R[2] - 29480;  /* 0x8009D178 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 8);  /* 0x8009D17C */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8011u << 16; if (_c) { goto L_8009D1B0; } }  /* 0x8009D184 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 4);  /* 0x8009D18C */
    { uint32_t _c = (R[16] != R[2]); R[2] = 0x8011u << 16; if (_c) { goto L_8009D1B0; } }  /* 0x8009D194 */
    R[2] = 0x8013u << 16;  /* 0x8009D19C */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + -29612);  /* 0x8009D1A0 */
    { uint32_t _c = (R[2] == R[19]); R[2] = 0x8011u << 16; if (_c) { goto L_8009D1E8; } }  /* 0x8009D1A8 */
L_8009D1B0:;
    R[3] = 0x8013u << 16;  /* 0x8009D1B0 */
    R[2] = lh_(R[2] + 30216);  /* 0x8009D1B4 */
    R[3] = R[3] - 29480;  /* 0x8009D1B8 */
    R[2] = R[2] + R[16];  /* 0x8009D1BC */
    R[2] = R[2] + 128;  /* 0x8009D1C0 */
    R[2] = R[2] & 0x1FF;  /* 0x8009D1C4 */
    sh_(R[17] + 6, R[2]);  /* 0x8009D1C8 */
    { uint32_t _c = (R[19] == R[0]); sh_(R[3] + 6, R[2]); if (_c) { goto L_8009D1E0; } }  /* 0x8009D1CC */
    R[2] = lh_(R[17] + 6);  /* 0x8009D1D4 */
    sh_(R[17] + 4, R[2]);  /* 0x8009D1DC */
L_8009D1E0:;
    sh_(R[3] + 4, R[16]);  /* 0x8009D1E0 */
    sh_(R[3] + 8, R[0]);  /* 0x8009D1E4 */
L_8009D1E8:;
    R[2] = R[0] - 1;  /* 0x8009D1E8 */
    { uint32_t _c = (R[21] == R[2]); R[4] = R[17] + R[0]; if (_c) { goto L_8009D1FC; } }  /* 0x8009D1EC */
    { R[31] = 0x8009D1FCu; R[5] = R[21] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009D1F4 jal */
L_8009D1FC:;
    R[2] = 0x8013u << 16;  /* 0x8009D1FC */
    sh_(R[2] + -29612, R[19]);  /* 0x8009D200 */
    { R[2] = R[0] + 1; goto L_8009D244; }  /* 0x8009D204 j */
L_8009D20C:;
    { uint32_t _c = (R[20] == R[2]); R[4] = R[17] + R[0]; if (_c) { goto L_8009D21C; } }  /* 0x8009D20C */
    { R[31] = 0x8009D21Cu; R[5] = R[20] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009D214 jal */
L_8009D21C:;
    R[2] = 0x8013u << 16;  /* 0x8009D21C */
    R[2] = R[2] - 29480;  /* 0x8009D220 */
    sh_(R[2] + 6, R[16]);  /* 0x8009D224 */
    sh_(R[2] + 4, R[16]);  /* 0x8009D228 */
    sh_(R[2] + 8, R[0]);  /* 0x8009D22C */
    R[3] = lh_(R[17] + 4);  /* 0x8009D230 */
    R[2] = R[0] + R[0];  /* 0x8009D234 */
    sh_(R[17] + 6, R[3]);  /* 0x8009D238 */
    R[3] = 0x8013u << 16;  /* 0x8009D23C */
    sh_(R[3] + -29612, R[19]);  /* 0x8009D240 */
L_8009D244:;
    R[31] = lw_(R[29] + 40);  /* 0x8009D244 */
    R[21] = lw_(R[29] + 36);  /* 0x8009D248 */
    R[20] = lw_(R[29] + 32);  /* 0x8009D24C */
    R[19] = lw_(R[29] + 28);  /* 0x8009D250 */
    R[18] = lw_(R[29] + 24);  /* 0x8009D254 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D258 */
    R[16] = lw_(R[29] + 16);  /* 0x8009D25C */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009D260 jr ra */
}

void g0_8009D1FC(void) {
    R[2] = 0x8013u << 16;  /* 0x8009D1FC */
    sh_(R[2] + -29612, R[19]);  /* 0x8009D200 */
    { R[2] = R[0] + 1; goto L_8009D244; }  /* 0x8009D204 j */
    { uint32_t _c = (R[20] == R[2]); R[4] = R[17] + R[0]; if (_c) { goto L_8009D21C; } }  /* 0x8009D20C */
    { R[31] = 0x8009D21Cu; R[5] = R[20] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009D214 jal */
L_8009D21C:;
    R[2] = 0x8013u << 16;  /* 0x8009D21C */
    R[2] = R[2] - 29480;  /* 0x8009D220 */
    sh_(R[2] + 6, R[16]);  /* 0x8009D224 */
    sh_(R[2] + 4, R[16]);  /* 0x8009D228 */
    sh_(R[2] + 8, R[0]);  /* 0x8009D22C */
    R[3] = lh_(R[17] + 4);  /* 0x8009D230 */
    R[2] = R[0] + R[0];  /* 0x8009D234 */
    sh_(R[17] + 6, R[3]);  /* 0x8009D238 */
    R[3] = 0x8013u << 16;  /* 0x8009D23C */
    sh_(R[3] + -29612, R[19]);  /* 0x8009D240 */
L_8009D244:;
    R[31] = lw_(R[29] + 40);  /* 0x8009D244 */
    R[21] = lw_(R[29] + 36);  /* 0x8009D248 */
    R[20] = lw_(R[29] + 32);  /* 0x8009D24C */
    R[19] = lw_(R[29] + 28);  /* 0x8009D250 */
    R[18] = lw_(R[29] + 24);  /* 0x8009D254 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D258 */
    R[16] = lw_(R[29] + 16);  /* 0x8009D25C */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009D260 jr ra */
}

void g0_8009D21C(void) {
    R[2] = 0x8013u << 16;  /* 0x8009D21C */
    R[2] = R[2] - 29480;  /* 0x8009D220 */
    sh_(R[2] + 6, R[16]);  /* 0x8009D224 */
    sh_(R[2] + 4, R[16]);  /* 0x8009D228 */
    sh_(R[2] + 8, R[0]);  /* 0x8009D22C */
    R[3] = lh_(R[17] + 4);  /* 0x8009D230 */
    R[2] = R[0] + R[0];  /* 0x8009D234 */
    sh_(R[17] + 6, R[3]);  /* 0x8009D238 */
    R[3] = 0x8013u << 16;  /* 0x8009D23C */
    sh_(R[3] + -29612, R[19]);  /* 0x8009D240 */
    R[31] = lw_(R[29] + 40);  /* 0x8009D244 */
    R[21] = lw_(R[29] + 36);  /* 0x8009D248 */
    R[20] = lw_(R[29] + 32);  /* 0x8009D24C */
    R[19] = lw_(R[29] + 28);  /* 0x8009D250 */
    R[18] = lw_(R[29] + 24);  /* 0x8009D254 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D258 */
    R[16] = lw_(R[29] + 16);  /* 0x8009D25C */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009D260 jr ra */
}

void g0_8009D268(void) {
    R[29] = R[29] - 32;  /* 0x8009D268 */
    sw_(R[29] + 16, R[16]);  /* 0x8009D26C */
    R[16] = R[4] + R[0];  /* 0x8009D270 */
    R[3] = 0x8006u << 16;  /* 0x8009D274 */
    R[2] = 0x8006u << 16;  /* 0x8009D278 */
    R[4] = R[2] + 13192;  /* 0x8009D27C */
    R[2] = lh_(R[3] + -6452);  /* 0x8009D280 */
    sw_(R[29] + 24, R[31]);  /* 0x8009D284 */
    sw_(R[29] + 20, R[17]);  /* 0x8009D288 */
    R[3] = lh_(R[4] + 2922);  /* 0x8009D28C */
    R[2] = R[2] & R[3];  /* 0x8009D294 */
    { uint32_t _c = (R[2] == R[0]); R[17] = R[5] + R[0]; if (_c) { goto L_8009D434; } }  /* 0x8009D298 */
    R[2] = 0x8012u << 16;  /* 0x8009D2A0 */
    R[2] = lh_(R[2] + 31132);  /* 0x8009D2A4 */
    R[2] = R[2] & 0x1;  /* 0x8009D2AC */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D2CC; } }  /* 0x8009D2B0 */
    R[2] = lh_(R[4] + 2912);  /* 0x8009D2B8 */
    R[2] = R[2] & 0x1;  /* 0x8009D2C0 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x1u << 16; if (_c) { goto L_8009D364; } }  /* 0x8009D2C4 */
L_8009D2CC:;
    { uint32_t _c = (R[6] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009D2E4; } }  /* 0x8009D2CC */
    R[2] = lb_(R[2] + -12295);  /* 0x8009D2D4 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D438; } }  /* 0x8009D2DC */
L_8009D2E4:;
    R[4] = R[16] + R[0];  /* 0x8009D2E4 */
    { R[31] = 0x8009D2F0u; R[5] = R[0] + 4; psx_next = 0x8008933Cu; return; }  /* 0x8009D2E8 jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D438; } }  /* 0x8009D2F0 */
    R[2] = 0x8012u << 16;  /* 0x8009D2F8 */
    R[2] = lh_(R[2] + 31132);  /* 0x8009D2FC */
    R[3] = lw_(R[16] + 352);  /* 0x8009D300 */
    R[2] = R[2] & 0x1;  /* 0x8009D304 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x1u << 16; if (_c) { goto L_8009D364; } }  /* 0x8009D308 */
    R[2] = lw_(R[3] + 24);  /* 0x8009D310 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 26);  /* 0x8009D318 */
    R[2] = ((int32_t)R[2] < 2049);  /* 0x8009D320 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x1u << 16; if (_c) { goto L_8009D364; } }  /* 0x8009D324 */
    R[2] = lw_(R[3] + 20);  /* 0x8009D32C */
    R[3] = 0x10u << 16;  /* 0x8009D330 */
    R[2] = R[2] & R[3];  /* 0x8009D334 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x1u << 16; if (_c) { goto L_8009D364; } }  /* 0x8009D338 */
    R[2] = lb_(R[16] + 784);  /* 0x8009D340 */
    R[3] = R[0] + 2;  /* 0x8009D344 */
    { uint32_t _c = (R[2] == R[3]); R[2] = 0x1u << 16; if (_c) { goto L_8009D364; } }  /* 0x8009D348 */
    R[2] = lb_(R[16] + 785);  /* 0x8009D350 */
    { uint32_t _c = (R[2] != R[3]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D438; } }  /* 0x8009D358 */
    R[2] = 0x1u << 16;  /* 0x8009D360 */
L_8009D364:;
    R[5] = 0x8012u << 16;  /* 0x8009D364 */
    R[4] = R[5] + 30872;  /* 0x8009D368 */
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 104);  /* 0x8009D36C */
    R[2] = R[2] | 0x22E5;  /* 0x8009D370 */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009D374 */
    sw_(R[16] + 140, R[2]);  /* 0x8009D378 */
    R[2] = lh_(R[4] + 260);  /* 0x8009D37C */
    R[2] = R[2] & 0x1;  /* 0x8009D384 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009D3A4; } }  /* 0x8009D388 */
    R[2] = lh_(R[2] + 16104);  /* 0x8009D390 */
    R[2] = R[2] & 0x1;  /* 0x8009D398 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 154; if (_c) { goto L_8009D3B8; } }  /* 0x8009D39C */
L_8009D3A4:;
    R[2] = 0x800Fu << 16;  /* 0x8009D3A4 */
    R[4] = lw_(R[2] + 25524);  /* 0x8009D3A8 */
    R[5] = lh_(R[16] + 2);  /* 0x8009D3AC */
    { R[4] = R[4] + 14; goto L_8009D3CC; }  /* 0x8009D3B0 j */
L_8009D3B8:;
    R[3] = lw_(R[5] + 30872);  /* 0x8009D3B8 */
    { uint32_t _c = (R[3] == R[2]); R[4] = R[0] + 4431; if (_c) { goto L_8009D3D4; } }  /* 0x8009D3C0 */
    R[5] = lh_(R[16] + 2);  /* 0x8009D3C8 */
L_8009D3CC:;
    { R[31] = 0x8009D3D4u; psx_next = 0x8002DAE8u; return; }  /* 0x8009D3CC jal */
L_8009D3D4:;
    R[4] = R[16] + R[0];  /* 0x8009D3D4 */
    { R[31] = 0x8009D3E0u; R[5] = R[0] + 16; psx_next = 0x8008933Cu; return; }  /* 0x8009D3D8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009D41C; } }  /* 0x8009D3E0 */
    R[4] = lw_(R[16] + 140);  /* 0x8009D3E8 */
    { uint32_t _c = ((int32_t)R[4] >= 0); if (_c) { goto L_8009D3FC; } }  /* 0x8009D3F0 */
    R[4] = R[4] + 3;  /* 0x8009D3F8 */
L_8009D3FC:;
    R[4] = (uint32_t)((int32_t)R[4] >> 2);  /* 0x8009D3FC */
    R[2] = R[4] << 1;  /* 0x8009D400 */
    R[3] = 0x8012u << 16;  /* 0x8009D404 */
    R[3] = (uint32_t)(int16_t)lh_(R[3] + 30976);  /* 0x8009D408 */
    R[2] = R[2] + R[4];  /* 0x8009D40C */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009D410 */
    sw_(R[16] + 140, R[2]);  /* 0x8009D414 */
    R[4] = R[16] + R[0];  /* 0x8009D418 */
L_8009D41C:;
    { R[31] = 0x8009D424u; R[5] = R[17] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009D41C jal */
    R[2] = 0x8013u << 16;  /* 0x8009D424 */
    sh_(R[2] + -29650, R[17]);  /* 0x8009D428 */
    { R[2] = R[0] + 1; goto L_8009D438; }  /* 0x8009D42C j */
L_8009D434:;
    R[2] = R[0] + R[0];  /* 0x8009D434 */
L_8009D438:;
    R[31] = lw_(R[29] + 24);  /* 0x8009D438 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D43C */
    R[16] = lw_(R[29] + 16);  /* 0x8009D440 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D444 jr ra */
}

void g0_8009D2F0(void) {
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D438; } }  /* 0x8009D2F0 */
    R[2] = 0x8012u << 16;  /* 0x8009D2F8 */
    R[2] = lh_(R[2] + 31132);  /* 0x8009D2FC */
    R[3] = lw_(R[16] + 352);  /* 0x8009D300 */
    R[2] = R[2] & 0x1;  /* 0x8009D304 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x1u << 16; if (_c) { goto L_8009D364; } }  /* 0x8009D308 */
    R[2] = lw_(R[3] + 24);  /* 0x8009D310 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 26);  /* 0x8009D318 */
    R[2] = ((int32_t)R[2] < 2049);  /* 0x8009D320 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x1u << 16; if (_c) { goto L_8009D364; } }  /* 0x8009D324 */
    R[2] = lw_(R[3] + 20);  /* 0x8009D32C */
    R[3] = 0x10u << 16;  /* 0x8009D330 */
    R[2] = R[2] & R[3];  /* 0x8009D334 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x1u << 16; if (_c) { goto L_8009D364; } }  /* 0x8009D338 */
    R[2] = lb_(R[16] + 784);  /* 0x8009D340 */
    R[3] = R[0] + 2;  /* 0x8009D344 */
    { uint32_t _c = (R[2] == R[3]); R[2] = 0x1u << 16; if (_c) { goto L_8009D364; } }  /* 0x8009D348 */
    R[2] = lb_(R[16] + 785);  /* 0x8009D350 */
    { uint32_t _c = (R[2] != R[3]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D438; } }  /* 0x8009D358 */
    R[2] = 0x1u << 16;  /* 0x8009D360 */
L_8009D364:;
    R[5] = 0x8012u << 16;  /* 0x8009D364 */
    R[4] = R[5] + 30872;  /* 0x8009D368 */
    R[3] = (uint32_t)(int16_t)lh_(R[4] + 104);  /* 0x8009D36C */
    R[2] = R[2] | 0x22E5;  /* 0x8009D370 */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009D374 */
    sw_(R[16] + 140, R[2]);  /* 0x8009D378 */
    R[2] = lh_(R[4] + 260);  /* 0x8009D37C */
    R[2] = R[2] & 0x1;  /* 0x8009D384 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8006u << 16; if (_c) { goto L_8009D3A4; } }  /* 0x8009D388 */
    R[2] = lh_(R[2] + 16104);  /* 0x8009D390 */
    R[2] = R[2] & 0x1;  /* 0x8009D398 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 154; if (_c) { goto L_8009D3B8; } }  /* 0x8009D39C */
L_8009D3A4:;
    R[2] = 0x800Fu << 16;  /* 0x8009D3A4 */
    R[4] = lw_(R[2] + 25524);  /* 0x8009D3A8 */
    R[5] = lh_(R[16] + 2);  /* 0x8009D3AC */
    { R[4] = R[4] + 14; goto L_8009D3CC; }  /* 0x8009D3B0 j */
L_8009D3B8:;
    R[3] = lw_(R[5] + 30872);  /* 0x8009D3B8 */
    { uint32_t _c = (R[3] == R[2]); R[4] = R[0] + 4431; if (_c) { goto L_8009D3D4; } }  /* 0x8009D3C0 */
    R[5] = lh_(R[16] + 2);  /* 0x8009D3C8 */
L_8009D3CC:;
    { R[31] = 0x8009D3D4u; psx_next = 0x8002DAE8u; return; }  /* 0x8009D3CC jal */
L_8009D3D4:;
    R[4] = R[16] + R[0];  /* 0x8009D3D4 */
    { R[31] = 0x8009D3E0u; R[5] = R[0] + 16; psx_next = 0x8008933Cu; return; }  /* 0x8009D3D8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009D41C; } }  /* 0x8009D3E0 */
    R[4] = lw_(R[16] + 140);  /* 0x8009D3E8 */
    { uint32_t _c = ((int32_t)R[4] >= 0); if (_c) { goto L_8009D3FC; } }  /* 0x8009D3F0 */
    R[4] = R[4] + 3;  /* 0x8009D3F8 */
L_8009D3FC:;
    R[4] = (uint32_t)((int32_t)R[4] >> 2);  /* 0x8009D3FC */
    R[2] = R[4] << 1;  /* 0x8009D400 */
    R[3] = 0x8012u << 16;  /* 0x8009D404 */
    R[3] = (uint32_t)(int16_t)lh_(R[3] + 30976);  /* 0x8009D408 */
    R[2] = R[2] + R[4];  /* 0x8009D40C */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009D410 */
    sw_(R[16] + 140, R[2]);  /* 0x8009D414 */
    R[4] = R[16] + R[0];  /* 0x8009D418 */
L_8009D41C:;
    { R[31] = 0x8009D424u; R[5] = R[17] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009D41C jal */
    R[2] = 0x8013u << 16;  /* 0x8009D424 */
    sh_(R[2] + -29650, R[17]);  /* 0x8009D428 */
    { R[2] = R[0] + 1; goto L_8009D438; }  /* 0x8009D42C j */
    R[2] = R[0] + R[0];  /* 0x8009D434 */
L_8009D438:;
    R[31] = lw_(R[29] + 24);  /* 0x8009D438 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D43C */
    R[16] = lw_(R[29] + 16);  /* 0x8009D440 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D444 jr ra */
}

void g0_8009D3D4(void) {
    R[4] = R[16] + R[0];  /* 0x8009D3D4 */
    { R[31] = 0x8009D3E0u; R[5] = R[0] + 16; psx_next = 0x8008933Cu; return; }  /* 0x8009D3D8 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009D41C; } }  /* 0x8009D3E0 */
    R[4] = lw_(R[16] + 140);  /* 0x8009D3E8 */
    { uint32_t _c = ((int32_t)R[4] >= 0); if (_c) { goto L_8009D3FC; } }  /* 0x8009D3F0 */
    R[4] = R[4] + 3;  /* 0x8009D3F8 */
L_8009D3FC:;
    R[4] = (uint32_t)((int32_t)R[4] >> 2);  /* 0x8009D3FC */
    R[2] = R[4] << 1;  /* 0x8009D400 */
    R[3] = 0x8012u << 16;  /* 0x8009D404 */
    R[3] = (uint32_t)(int16_t)lh_(R[3] + 30976);  /* 0x8009D408 */
    R[2] = R[2] + R[4];  /* 0x8009D40C */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009D410 */
    sw_(R[16] + 140, R[2]);  /* 0x8009D414 */
    R[4] = R[16] + R[0];  /* 0x8009D418 */
L_8009D41C:;
    { R[31] = 0x8009D424u; R[5] = R[17] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009D41C jal */
    R[2] = 0x8013u << 16;  /* 0x8009D424 */
    sh_(R[2] + -29650, R[17]);  /* 0x8009D428 */
    { R[2] = R[0] + 1; goto L_8009D438; }  /* 0x8009D42C j */
    R[2] = R[0] + R[0];  /* 0x8009D434 */
L_8009D438:;
    R[31] = lw_(R[29] + 24);  /* 0x8009D438 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D43C */
    R[16] = lw_(R[29] + 16);  /* 0x8009D440 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D444 jr ra */
}

void g0_8009D3E0(void) {
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009D41C; } }  /* 0x8009D3E0 */
    R[4] = lw_(R[16] + 140);  /* 0x8009D3E8 */
    { uint32_t _c = ((int32_t)R[4] >= 0); if (_c) { goto L_8009D3FC; } }  /* 0x8009D3F0 */
    R[4] = R[4] + 3;  /* 0x8009D3F8 */
L_8009D3FC:;
    R[4] = (uint32_t)((int32_t)R[4] >> 2);  /* 0x8009D3FC */
    R[2] = R[4] << 1;  /* 0x8009D400 */
    R[3] = 0x8012u << 16;  /* 0x8009D404 */
    R[3] = (uint32_t)(int16_t)lh_(R[3] + 30976);  /* 0x8009D408 */
    R[2] = R[2] + R[4];  /* 0x8009D40C */
    R[2] = (uint32_t)((int32_t)R[2] >> (R[3] & 31));  /* 0x8009D410 */
    sw_(R[16] + 140, R[2]);  /* 0x8009D414 */
    R[4] = R[16] + R[0];  /* 0x8009D418 */
L_8009D41C:;
    { R[31] = 0x8009D424u; R[5] = R[17] + R[0]; psx_next = 0x8009BC84u; return; }  /* 0x8009D41C jal */
    R[2] = 0x8013u << 16;  /* 0x8009D424 */
    sh_(R[2] + -29650, R[17]);  /* 0x8009D428 */
    { R[2] = R[0] + 1; goto L_8009D438; }  /* 0x8009D42C j */
    R[2] = R[0] + R[0];  /* 0x8009D434 */
L_8009D438:;
    R[31] = lw_(R[29] + 24);  /* 0x8009D438 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D43C */
    R[16] = lw_(R[29] + 16);  /* 0x8009D440 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D444 jr ra */
}

void g0_8009D424(void) {
    R[2] = 0x8013u << 16;  /* 0x8009D424 */
    sh_(R[2] + -29650, R[17]);  /* 0x8009D428 */
    { R[2] = R[0] + 1; goto L_8009D438; }  /* 0x8009D42C j */
    R[2] = R[0] + R[0];  /* 0x8009D434 */
L_8009D438:;
    R[31] = lw_(R[29] + 24);  /* 0x8009D438 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D43C */
    R[16] = lw_(R[29] + 16);  /* 0x8009D440 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D444 jr ra */
}

void g0_8009D44C(void) {
    R[29] = R[29] - 32;  /* 0x8009D44C */
    sw_(R[29] + 16, R[16]);  /* 0x8009D450 */
    R[16] = R[4] + R[0];  /* 0x8009D454 */
    sw_(R[29] + 20, R[17]);  /* 0x8009D458 */
    R[17] = R[5] + R[0];  /* 0x8009D45C */
    R[2] = R[0] + 10;  /* 0x8009D460 */
    { uint32_t _c = (R[16] != R[2]); sw_(R[29] + 24, R[31]); if (_c) { goto L_8009D488; } }  /* 0x8009D464 */
    { R[31] = 0x8009D474u; R[4] = R[0] + 77; psx_next = 0x80023CE8u; return; }  /* 0x8009D46C jal */
    { uint32_t _c = ((int32_t)R[2] < 0); R[4] = R[0] + 77; if (_c) { goto L_8009D488; } }  /* 0x8009D474 */
    { R[31] = 0x8009D484u; R[5] = R[0] + 10; psx_next = 0x80023ECCu; return; }  /* 0x8009D47C jal */
    R[16] = R[16] - R[2];  /* 0x8009D484 */
L_8009D488:;
    R[4] = R[16] << 16;  /* 0x8009D488 */
    R[4] = (uint32_t)((int32_t)R[4] >> 16);  /* 0x8009D48C */
    { R[31] = 0x8009D498u; sw_(R[17], R[16]); psx_next = 0x8001D23Cu; return; }  /* 0x8009D490 jal */
    R[31] = lw_(R[29] + 24);  /* 0x8009D498 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D49C */
    R[16] = lw_(R[29] + 16);  /* 0x8009D4A0 */
    R[2] = (R[0] < R[2]);  /* 0x8009D4A4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D4A8 jr ra */
}

void g0_8009D474(void) {
    { uint32_t _c = ((int32_t)R[2] < 0); R[4] = R[0] + 77; if (_c) { goto L_8009D488; } }  /* 0x8009D474 */
    { R[31] = 0x8009D484u; R[5] = R[0] + 10; psx_next = 0x80023ECCu; return; }  /* 0x8009D47C jal */
    R[16] = R[16] - R[2];  /* 0x8009D484 */
L_8009D488:;
    R[4] = R[16] << 16;  /* 0x8009D488 */
    R[4] = (uint32_t)((int32_t)R[4] >> 16);  /* 0x8009D48C */
    { R[31] = 0x8009D498u; sw_(R[17], R[16]); psx_next = 0x8001D23Cu; return; }  /* 0x8009D490 jal */
    R[31] = lw_(R[29] + 24);  /* 0x8009D498 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D49C */
    R[16] = lw_(R[29] + 16);  /* 0x8009D4A0 */
    R[2] = (R[0] < R[2]);  /* 0x8009D4A4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D4A8 jr ra */
}

void g0_8009D484(void) {
    R[16] = R[16] - R[2];  /* 0x8009D484 */
    R[4] = R[16] << 16;  /* 0x8009D488 */
    R[4] = (uint32_t)((int32_t)R[4] >> 16);  /* 0x8009D48C */
    { R[31] = 0x8009D498u; sw_(R[17], R[16]); psx_next = 0x8001D23Cu; return; }  /* 0x8009D490 jal */
    R[31] = lw_(R[29] + 24);  /* 0x8009D498 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D49C */
    R[16] = lw_(R[29] + 16);  /* 0x8009D4A0 */
    R[2] = (R[0] < R[2]);  /* 0x8009D4A4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D4A8 jr ra */
}

void g0_8009D498(void) {
    R[31] = lw_(R[29] + 24);  /* 0x8009D498 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D49C */
    R[16] = lw_(R[29] + 16);  /* 0x8009D4A0 */
    R[2] = (R[0] < R[2]);  /* 0x8009D4A4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D4A8 jr ra */
}

void g0_8009D4B0(void) {
    R[29] = R[29] - 48;  /* 0x8009D4B0 */
    sw_(R[29] + 32, R[18]);  /* 0x8009D4B4 */
    psx_next = 0x8009D4B8u; return;  /* fallthrough */
}

void g0_8009D4B8(void) {
    R[18] = R[4] + R[0];  /* 0x8009D4B8 */
    R[2] = 0x8013u << 16;  /* 0x8009D4BC */
    sw_(R[29] + 28, R[17]);  /* 0x8009D4C0 */
    R[17] = R[2] - 29656;  /* 0x8009D4C4 */
    sw_(R[29] + 40, R[31]);  /* 0x8009D4C8 */
    sw_(R[29] + 36, R[19]);  /* 0x8009D4CC */
    sw_(R[29] + 24, R[16]);  /* 0x8009D4D0 */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 68);  /* 0x8009D4D4 */
    { uint32_t _c = (R[2] != R[0]); R[19] = R[5] + R[0]; if (_c) { goto L_8009D620; } }  /* 0x8009D4DC */
    R[2] = 0x8006u << 16;  /* 0x8009D4E4 */
    R[5] = R[2] - 6456;  /* 0x8009D4E8 */
    R[2] = 0x8006u << 16;  /* 0x8009D4EC */
    R[16] = R[2] + 13192;  /* 0x8009D4F0 */
    R[2] = lh_(R[5] + 4);  /* 0x8009D4F4 */
    R[3] = lh_(R[16] + 2924);  /* 0x8009D4F8 */
    R[2] = R[2] & R[3];  /* 0x8009D500 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D624; } }  /* 0x8009D504 */
    R[2] = (uint32_t)(int16_t)lh_(R[16] + 2842);  /* 0x8009D50C */
    R[2] = R[16] + R[2];  /* 0x8009D514 */
    R[4] = (uint32_t)(int8_t)lb_(R[2] + 2204);  /* 0x8009D518 */
    R[2] = R[0] - 1;  /* 0x8009D51C */
    { uint32_t _c = (R[4] == R[2]); R[2] = R[4] - 23; if (_c) { goto L_8009D620; } }  /* 0x8009D520 */
    R[2] = (R[2] < (uint32_t)4u);  /* 0x8009D528 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D624; } }  /* 0x8009D52C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 42);  /* 0x8009D534 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D624; } }  /* 0x8009D53C */
    R[2] = lh_(R[5] + 2);  /* 0x8009D544 */
    R[3] = lh_(R[16] + 2920);  /* 0x8009D548 */
    R[2] = R[2] & R[3];  /* 0x8009D550 */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009D5F0; } }  /* 0x8009D554 */
    R[2] = lh_(R[2] + -29480);  /* 0x8009D55C */
    R[2] = R[2] - 2;  /* 0x8009D564 */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x8009D568 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D624; } }  /* 0x8009D56C */
    { R[31] = 0x8009D57Cu; psx_next = 0x80023E24u; return; }  /* 0x8009D574 jal */
    { uint32_t _c = ((int32_t)R[2] <= 0); R[4] = R[0] + 200; if (_c) { goto L_8009D620; } }  /* 0x8009D57C */
    { R[31] = 0x8009D58Cu; R[5] = R[29] + 16; psx_next = 0x8009D44Cu; return; }  /* 0x8009D584 jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 37; if (_c) { goto L_8009D620; } }  /* 0x8009D58C */
    sh_(R[18] + 20, R[2]);  /* 0x8009D594 */
    R[2] = R[0] + 1;  /* 0x8009D598 */
    sh_(R[17] + 42, R[2]);  /* 0x8009D59C */
    R[2] = 0x8012u << 16;  /* 0x8009D5A0 */
    R[3] = R[0] + 2;  /* 0x8009D5A4 */
    sw_(R[2] + 30972, R[3]);  /* 0x8009D5A8 */
    R[2] = 0x8006u << 16;  /* 0x8009D5AC */
    { R[31] = 0x8009D5B8u; sw_(R[2] + -12128, R[3]); psx_next = 0x800A44E0u; return; }  /* 0x8009D5B0 jal */
    R[4] = 0x8012u << 16;  /* 0x8009D5B8 */
    R[4] = R[4] - 26864;  /* 0x8009D5BC */
    R[5] = 0x800Fu << 16;  /* 0x8009D5C0 */
    sw_(R[17] + 96, R[4]);  /* 0x8009D5C4 */
    R[2] = lb_(R[4] + 789);  /* 0x8009D5C8 */
    R[3] = lw_(R[5] + 25120);  /* 0x8009D5CC */
    R[2] = R[2] | 0x4;  /* 0x8009D5D0 */
    R[3] = R[3] | 0x8;  /* 0x8009D5D4 */
    sb_(R[4] + 789, R[2]);  /* 0x8009D5D8 */
    { R[31] = 0x8009D5E4u; sw_(R[5] + 25120, R[3]); psx_next = 0x800A9DDCu; return; }  /* 0x8009D5DC jal */
    R[2] = R[0] + 1;  /* 0x8009D5E4 */
    { sw_(R[18] + 140, R[0]); goto L_8009D624; }  /* 0x8009D5E8 j */
L_8009D5F0:;
    R[4] = R[0] + 10;  /* 0x8009D5F0 */
    { R[31] = 0x8009D5FCu; R[5] = R[29] + 16; psx_next = 0x8009D44Cu; return; }  /* 0x8009D5F4 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_8009D620; } }  /* 0x8009D5FC */
    R[2] = lh_(R[16] + 2912);  /* 0x8009D604 */
    R[5] = R[19] + R[0];  /* 0x8009D608 */
    R[2] = R[2] & 0xFFFE;  /* 0x8009D60C */
    { R[31] = 0x8009D618u; sh_(R[16] + 2912, R[2]); psx_next = 0x8009BC84u; return; }  /* 0x8009D610 jal */
    { R[2] = R[0] + 1; goto L_8009D624; }  /* 0x8009D618 j */
L_8009D620:;
    R[2] = R[0] + R[0];  /* 0x8009D620 */
L_8009D624:;
    R[31] = lw_(R[29] + 40);  /* 0x8009D624 */
    R[19] = lw_(R[29] + 36);  /* 0x8009D628 */
    R[18] = lw_(R[29] + 32);  /* 0x8009D62C */
    R[17] = lw_(R[29] + 28);  /* 0x8009D630 */
    R[16] = lw_(R[29] + 24);  /* 0x8009D634 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009D638 jr ra */
}

void g0_8009D57C(void) {
    { uint32_t _c = ((int32_t)R[2] <= 0); R[4] = R[0] + 200; if (_c) { goto L_8009D620; } }  /* 0x8009D57C */
    { R[31] = 0x8009D58Cu; R[5] = R[29] + 16; psx_next = 0x8009D44Cu; return; }  /* 0x8009D584 jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 37; if (_c) { goto L_8009D620; } }  /* 0x8009D58C */
    sh_(R[18] + 20, R[2]);  /* 0x8009D594 */
    R[2] = R[0] + 1;  /* 0x8009D598 */
    sh_(R[17] + 42, R[2]);  /* 0x8009D59C */
    R[2] = 0x8012u << 16;  /* 0x8009D5A0 */
    R[3] = R[0] + 2;  /* 0x8009D5A4 */
    sw_(R[2] + 30972, R[3]);  /* 0x8009D5A8 */
    R[2] = 0x8006u << 16;  /* 0x8009D5AC */
    { R[31] = 0x8009D5B8u; sw_(R[2] + -12128, R[3]); psx_next = 0x800A44E0u; return; }  /* 0x8009D5B0 jal */
    R[4] = 0x8012u << 16;  /* 0x8009D5B8 */
    R[4] = R[4] - 26864;  /* 0x8009D5BC */
    R[5] = 0x800Fu << 16;  /* 0x8009D5C0 */
    sw_(R[17] + 96, R[4]);  /* 0x8009D5C4 */
    R[2] = lb_(R[4] + 789);  /* 0x8009D5C8 */
    R[3] = lw_(R[5] + 25120);  /* 0x8009D5CC */
    R[2] = R[2] | 0x4;  /* 0x8009D5D0 */
    R[3] = R[3] | 0x8;  /* 0x8009D5D4 */
    sb_(R[4] + 789, R[2]);  /* 0x8009D5D8 */
    { R[31] = 0x8009D5E4u; sw_(R[5] + 25120, R[3]); psx_next = 0x800A9DDCu; return; }  /* 0x8009D5DC jal */
    R[2] = R[0] + 1;  /* 0x8009D5E4 */
    { sw_(R[18] + 140, R[0]); goto L_8009D624; }  /* 0x8009D5E8 j */
    R[4] = R[0] + 10;  /* 0x8009D5F0 */
    { R[31] = 0x8009D5FCu; R[5] = R[29] + 16; psx_next = 0x8009D44Cu; return; }  /* 0x8009D5F4 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_8009D620; } }  /* 0x8009D5FC */
    R[2] = lh_(R[16] + 2912);  /* 0x8009D604 */
    R[5] = R[19] + R[0];  /* 0x8009D608 */
    R[2] = R[2] & 0xFFFE;  /* 0x8009D60C */
    { R[31] = 0x8009D618u; sh_(R[16] + 2912, R[2]); psx_next = 0x8009BC84u; return; }  /* 0x8009D610 jal */
    { R[2] = R[0] + 1; goto L_8009D624; }  /* 0x8009D618 j */
L_8009D620:;
    R[2] = R[0] + R[0];  /* 0x8009D620 */
L_8009D624:;
    R[31] = lw_(R[29] + 40);  /* 0x8009D624 */
    R[19] = lw_(R[29] + 36);  /* 0x8009D628 */
    R[18] = lw_(R[29] + 32);  /* 0x8009D62C */
    R[17] = lw_(R[29] + 28);  /* 0x8009D630 */
    R[16] = lw_(R[29] + 24);  /* 0x8009D634 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009D638 jr ra */
}

void g0_8009D58C(void) {
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 37; if (_c) { goto L_8009D620; } }  /* 0x8009D58C */
    sh_(R[18] + 20, R[2]);  /* 0x8009D594 */
    R[2] = R[0] + 1;  /* 0x8009D598 */
    sh_(R[17] + 42, R[2]);  /* 0x8009D59C */
    R[2] = 0x8012u << 16;  /* 0x8009D5A0 */
    R[3] = R[0] + 2;  /* 0x8009D5A4 */
    sw_(R[2] + 30972, R[3]);  /* 0x8009D5A8 */
    R[2] = 0x8006u << 16;  /* 0x8009D5AC */
    { R[31] = 0x8009D5B8u; sw_(R[2] + -12128, R[3]); psx_next = 0x800A44E0u; return; }  /* 0x8009D5B0 jal */
    R[4] = 0x8012u << 16;  /* 0x8009D5B8 */
    R[4] = R[4] - 26864;  /* 0x8009D5BC */
    R[5] = 0x800Fu << 16;  /* 0x8009D5C0 */
    sw_(R[17] + 96, R[4]);  /* 0x8009D5C4 */
    R[2] = lb_(R[4] + 789);  /* 0x8009D5C8 */
    R[3] = lw_(R[5] + 25120);  /* 0x8009D5CC */
    R[2] = R[2] | 0x4;  /* 0x8009D5D0 */
    R[3] = R[3] | 0x8;  /* 0x8009D5D4 */
    sb_(R[4] + 789, R[2]);  /* 0x8009D5D8 */
    { R[31] = 0x8009D5E4u; sw_(R[5] + 25120, R[3]); psx_next = 0x800A9DDCu; return; }  /* 0x8009D5DC jal */
    R[2] = R[0] + 1;  /* 0x8009D5E4 */
    { sw_(R[18] + 140, R[0]); goto L_8009D624; }  /* 0x8009D5E8 j */
    R[4] = R[0] + 10;  /* 0x8009D5F0 */
    { R[31] = 0x8009D5FCu; R[5] = R[29] + 16; psx_next = 0x8009D44Cu; return; }  /* 0x8009D5F4 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_8009D620; } }  /* 0x8009D5FC */
    R[2] = lh_(R[16] + 2912);  /* 0x8009D604 */
    R[5] = R[19] + R[0];  /* 0x8009D608 */
    R[2] = R[2] & 0xFFFE;  /* 0x8009D60C */
    { R[31] = 0x8009D618u; sh_(R[16] + 2912, R[2]); psx_next = 0x8009BC84u; return; }  /* 0x8009D610 jal */
    { R[2] = R[0] + 1; goto L_8009D624; }  /* 0x8009D618 j */
L_8009D620:;
    R[2] = R[0] + R[0];  /* 0x8009D620 */
L_8009D624:;
    R[31] = lw_(R[29] + 40);  /* 0x8009D624 */
    R[19] = lw_(R[29] + 36);  /* 0x8009D628 */
    R[18] = lw_(R[29] + 32);  /* 0x8009D62C */
    R[17] = lw_(R[29] + 28);  /* 0x8009D630 */
    R[16] = lw_(R[29] + 24);  /* 0x8009D634 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009D638 jr ra */
}

void g0_8009D5B8(void) {
    R[4] = 0x8012u << 16;  /* 0x8009D5B8 */
    R[4] = R[4] - 26864;  /* 0x8009D5BC */
    R[5] = 0x800Fu << 16;  /* 0x8009D5C0 */
    sw_(R[17] + 96, R[4]);  /* 0x8009D5C4 */
    R[2] = lb_(R[4] + 789);  /* 0x8009D5C8 */
    R[3] = lw_(R[5] + 25120);  /* 0x8009D5CC */
    R[2] = R[2] | 0x4;  /* 0x8009D5D0 */
    R[3] = R[3] | 0x8;  /* 0x8009D5D4 */
    sb_(R[4] + 789, R[2]);  /* 0x8009D5D8 */
    { R[31] = 0x8009D5E4u; sw_(R[5] + 25120, R[3]); psx_next = 0x800A9DDCu; return; }  /* 0x8009D5DC jal */
    R[2] = R[0] + 1;  /* 0x8009D5E4 */
    { sw_(R[18] + 140, R[0]); goto L_8009D624; }  /* 0x8009D5E8 j */
    R[4] = R[0] + 10;  /* 0x8009D5F0 */
    { R[31] = 0x8009D5FCu; R[5] = R[29] + 16; psx_next = 0x8009D44Cu; return; }  /* 0x8009D5F4 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_8009D620; } }  /* 0x8009D5FC */
    R[2] = lh_(R[16] + 2912);  /* 0x8009D604 */
    R[5] = R[19] + R[0];  /* 0x8009D608 */
    R[2] = R[2] & 0xFFFE;  /* 0x8009D60C */
    { R[31] = 0x8009D618u; sh_(R[16] + 2912, R[2]); psx_next = 0x8009BC84u; return; }  /* 0x8009D610 jal */
    { R[2] = R[0] + 1; goto L_8009D624; }  /* 0x8009D618 j */
L_8009D620:;
    R[2] = R[0] + R[0];  /* 0x8009D620 */
L_8009D624:;
    R[31] = lw_(R[29] + 40);  /* 0x8009D624 */
    R[19] = lw_(R[29] + 36);  /* 0x8009D628 */
    R[18] = lw_(R[29] + 32);  /* 0x8009D62C */
    R[17] = lw_(R[29] + 28);  /* 0x8009D630 */
    R[16] = lw_(R[29] + 24);  /* 0x8009D634 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009D638 jr ra */
}

void g0_8009D5E4(void) {
    R[2] = R[0] + 1;  /* 0x8009D5E4 */
    { sw_(R[18] + 140, R[0]); goto L_8009D624; }  /* 0x8009D5E8 j */
    R[4] = R[0] + 10;  /* 0x8009D5F0 */
    { R[31] = 0x8009D5FCu; R[5] = R[29] + 16; psx_next = 0x8009D44Cu; return; }  /* 0x8009D5F4 jal */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_8009D620; } }  /* 0x8009D5FC */
    R[2] = lh_(R[16] + 2912);  /* 0x8009D604 */
    R[5] = R[19] + R[0];  /* 0x8009D608 */
    R[2] = R[2] & 0xFFFE;  /* 0x8009D60C */
    { R[31] = 0x8009D618u; sh_(R[16] + 2912, R[2]); psx_next = 0x8009BC84u; return; }  /* 0x8009D610 jal */
    { R[2] = R[0] + 1; goto L_8009D624; }  /* 0x8009D618 j */
L_8009D620:;
    R[2] = R[0] + R[0];  /* 0x8009D620 */
L_8009D624:;
    R[31] = lw_(R[29] + 40);  /* 0x8009D624 */
    R[19] = lw_(R[29] + 36);  /* 0x8009D628 */
    R[18] = lw_(R[29] + 32);  /* 0x8009D62C */
    R[17] = lw_(R[29] + 28);  /* 0x8009D630 */
    R[16] = lw_(R[29] + 24);  /* 0x8009D634 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009D638 jr ra */
}

void g0_8009D5FC(void) {
    { uint32_t _c = (R[2] == R[0]); R[4] = R[18] + R[0]; if (_c) { goto L_8009D620; } }  /* 0x8009D5FC */
    R[2] = lh_(R[16] + 2912);  /* 0x8009D604 */
    R[5] = R[19] + R[0];  /* 0x8009D608 */
    R[2] = R[2] & 0xFFFE;  /* 0x8009D60C */
    { R[31] = 0x8009D618u; sh_(R[16] + 2912, R[2]); psx_next = 0x8009BC84u; return; }  /* 0x8009D610 jal */
    { R[2] = R[0] + 1; goto L_8009D624; }  /* 0x8009D618 j */
L_8009D620:;
    R[2] = R[0] + R[0];  /* 0x8009D620 */
L_8009D624:;
    R[31] = lw_(R[29] + 40);  /* 0x8009D624 */
    R[19] = lw_(R[29] + 36);  /* 0x8009D628 */
    R[18] = lw_(R[29] + 32);  /* 0x8009D62C */
    R[17] = lw_(R[29] + 28);  /* 0x8009D630 */
    R[16] = lw_(R[29] + 24);  /* 0x8009D634 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009D638 jr ra */
}

void g0_8009D618(void) {
    { R[2] = R[0] + 1; goto L_8009D624; }  /* 0x8009D618 j */
    R[2] = R[0] + R[0];  /* 0x8009D620 */
L_8009D624:;
    R[31] = lw_(R[29] + 40);  /* 0x8009D624 */
    R[19] = lw_(R[29] + 36);  /* 0x8009D628 */
    R[18] = lw_(R[29] + 32);  /* 0x8009D62C */
    R[17] = lw_(R[29] + 28);  /* 0x8009D630 */
    R[16] = lw_(R[29] + 24);  /* 0x8009D634 */
    { R[29] = R[29] + 48; psx_next = R[31]; return; }  /* 0x8009D638 jr ra */
}

void g0_8009D640(void) {
    R[2] = 0x800Fu << 16;  /* 0x8009D640 */
    R[2] = lw_(R[2] + 25120);  /* 0x8009D644 */
    psx_next = 0x8009D648u; return;  /* fallthrough */
}

void g0_8009D648(void) {
    R[29] = R[29] - 32;  /* 0x8009D648 */
    sw_(R[29] + 20, R[17]);  /* 0x8009D64C */
    R[17] = R[4] + R[0];  /* 0x8009D650 */
    sw_(R[29] + 24, R[31]);  /* 0x8009D654 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[29] + 16, R[16]); if (_c) { goto L_8009D6D0; } }  /* 0x8009D658 */
    R[3] = 0x8006u << 16;  /* 0x8009D660 */
    R[2] = 0x8006u << 16;  /* 0x8009D664 */
    R[4] = R[2] + 13192;  /* 0x8009D668 */
    R[2] = lh_(R[3] + -6452);  /* 0x8009D66C */
    R[3] = lh_(R[4] + 2924);  /* 0x8009D670 */
    R[2] = R[2] & R[3];  /* 0x8009D678 */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D6D0; } }  /* 0x8009D67C */
    R[2] = (uint32_t)(int16_t)lh_(R[4] + 2842);  /* 0x8009D684 */
    R[2] = R[4] + R[2];  /* 0x8009D68C */
    R[16] = (uint32_t)(int8_t)lb_(R[2] + 2204);  /* 0x8009D690 */
    R[2] = R[0] - 1;  /* 0x8009D694 */
    { uint32_t _c = (R[16] == R[2]); R[2] = R[16] - 23; if (_c) { goto L_8009D6D0; } }  /* 0x8009D698 */
    R[2] = (R[2] < (uint32_t)4u);  /* 0x8009D6A0 */
    { uint32_t _c = (R[2] != R[0]); if (_c) { goto L_8009D6D0; } }  /* 0x8009D6A4 */
    { R[31] = 0x8009D6B4u; R[4] = R[16] + R[0]; psx_next = 0x80023FF0u; return; }  /* 0x8009D6AC jal */
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D6D0; } }  /* 0x8009D6B4 */
    { R[31] = 0x8009D6C4u; R[4] = R[16] + R[0]; psx_next = 0x80023F1Cu; return; }  /* 0x8009D6BC jal */
    R[4] = R[17] + R[0];  /* 0x8009D6C4 */
    { R[31] = 0x8009D6D0u; R[5] = R[2] + R[0]; psx_next = 0x8009BD08u; return; }  /* 0x8009D6C8 jal */
L_8009D6D0:;
    R[31] = lw_(R[29] + 24);  /* 0x8009D6D0 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D6D4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009D6D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D6DC jr ra */
}

void g0_8009D6B4(void) {
    { uint32_t _c = (R[2] == R[0]); if (_c) { goto L_8009D6D0; } }  /* 0x8009D6B4 */
    { R[31] = 0x8009D6C4u; R[4] = R[16] + R[0]; psx_next = 0x80023F1Cu; return; }  /* 0x8009D6BC jal */
    R[4] = R[17] + R[0];  /* 0x8009D6C4 */
    { R[31] = 0x8009D6D0u; R[5] = R[2] + R[0]; psx_next = 0x8009BD08u; return; }  /* 0x8009D6C8 jal */
L_8009D6D0:;
    R[31] = lw_(R[29] + 24);  /* 0x8009D6D0 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D6D4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009D6D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D6DC jr ra */
}

void g0_8009D6C4(void) {
    R[4] = R[17] + R[0];  /* 0x8009D6C4 */
    { R[31] = 0x8009D6D0u; R[5] = R[2] + R[0]; psx_next = 0x8009BD08u; return; }  /* 0x8009D6C8 jal */
    R[31] = lw_(R[29] + 24);  /* 0x8009D6D0 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D6D4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009D6D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D6DC jr ra */
}

void g0_8009D6D0(void) {
    R[31] = lw_(R[29] + 24);  /* 0x8009D6D0 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D6D4 */
    R[16] = lw_(R[29] + 16);  /* 0x8009D6D8 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D6DC jr ra */
}

void g0_8009D6E4(void) {
    R[2] = 0x8013u << 16;  /* 0x8009D6E4 */
    R[2] = lh_(R[2] + -29480);  /* 0x8009D6E8 */
    psx_next = 0x8009D6ECu; return;  /* fallthrough */
}

void g0_8009D6EC(void) {
    R[29] = R[29] - 32;  /* 0x8009D6EC */
    sw_(R[29] + 16, R[16]);  /* 0x8009D6F0 */
    R[16] = R[4] + R[0];  /* 0x8009D6F4 */
    sw_(R[29] + 20, R[17]);  /* 0x8009D6F8 */
    R[17] = R[5] + R[0];  /* 0x8009D6FC */
    R[2] = R[2] - 2;  /* 0x8009D700 */
    R[2] = (R[2] < (uint32_t)2u);  /* 0x8009D704 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[29] + 24, R[31]); if (_c) { goto L_8009D724; } }  /* 0x8009D708 */
    R[4] = R[16] + R[0];  /* 0x8009D710 */
    { R[31] = 0x8009D71Cu; R[5] = R[0] + 2; psx_next = 0x8008933Cu; return; }  /* 0x8009D714 jal */
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009D72C; } }  /* 0x8009D71C */
L_8009D724:;
    { R[2] = R[0] + R[0]; goto L_8009D774; }  /* 0x8009D724 j */
L_8009D72C:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + -29588);  /* 0x8009D72C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D774; } }  /* 0x8009D734 */
    R[3] = 0x8006u << 16;  /* 0x8009D73C */
    R[2] = 0x8006u << 16;  /* 0x8009D740 */
    R[4] = R[2] + 13192;  /* 0x8009D744 */
    R[2] = lh_(R[3] + -6452);  /* 0x8009D748 */
    R[3] = lh_(R[4] + 2918);  /* 0x8009D74C */
    R[2] = R[2] & R[3];  /* 0x8009D754 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { psx_bb(); goto L_8009D724; } }  /* 0x8009D758 */
    R[3] = lh_(R[4] + 2912);  /* 0x8009D760 */
    R[3] = R[3] | R[2];  /* 0x8009D768 */
    sh_(R[4] + 2912, R[3]);  /* 0x8009D76C */
    sh_(R[16] + 20, R[17]);  /* 0x8009D770 */
L_8009D774:;
    R[31] = lw_(R[29] + 24);  /* 0x8009D774 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D778 */
    R[16] = lw_(R[29] + 16);  /* 0x8009D77C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D780 jr ra */
}

void g0_8009D71C(void) {
    { uint32_t _c = (R[2] == R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009D72C; } }  /* 0x8009D71C */
L_8009D724:;
    { R[2] = R[0] + R[0]; goto L_8009D774; }  /* 0x8009D724 j */
L_8009D72C:;
    R[2] = (uint32_t)(int16_t)lh_(R[2] + -29588);  /* 0x8009D72C */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D774; } }  /* 0x8009D734 */
    R[3] = 0x8006u << 16;  /* 0x8009D73C */
    R[2] = 0x8006u << 16;  /* 0x8009D740 */
    R[4] = R[2] + 13192;  /* 0x8009D744 */
    R[2] = lh_(R[3] + -6452);  /* 0x8009D748 */
    R[3] = lh_(R[4] + 2918);  /* 0x8009D74C */
    R[2] = R[2] & R[3];  /* 0x8009D754 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { psx_bb(); goto L_8009D724; } }  /* 0x8009D758 */
    R[3] = lh_(R[4] + 2912);  /* 0x8009D760 */
    R[3] = R[3] | R[2];  /* 0x8009D768 */
    sh_(R[4] + 2912, R[3]);  /* 0x8009D76C */
    sh_(R[16] + 20, R[17]);  /* 0x8009D770 */
L_8009D774:;
    R[31] = lw_(R[29] + 24);  /* 0x8009D774 */
    R[17] = lw_(R[29] + 20);  /* 0x8009D778 */
    R[16] = lw_(R[29] + 16);  /* 0x8009D77C */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D780 jr ra */
}

void g0_8009D788(void) {
    R[2] = 0x8013u << 16;  /* 0x8009D788 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + -29588);  /* 0x8009D78C */
    { uint32_t _c = (R[2] == R[0]); R[3] = 0x8006u << 16; if (_c) { goto L_8009D7A4; } }  /* 0x8009D794 */
L_8009D79C:;
    { R[2] = R[0] + R[0]; psx_next = R[31]; return; }  /* 0x8009D79C jr ra */
L_8009D7A4:;
    R[2] = 0x8006u << 16;  /* 0x8009D7A4 */
    R[6] = R[2] + 13192;  /* 0x8009D7A8 */
    R[2] = lh_(R[3] + -6452);  /* 0x8009D7AC */
    R[3] = lh_(R[6] + 2920);  /* 0x8009D7B0 */
    R[2] = R[2] & R[3];  /* 0x8009D7B8 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { psx_bb(); goto L_8009D79C; } }  /* 0x8009D7BC */
    R[3] = lh_(R[6] + 2912);  /* 0x8009D7C4 */
    R[3] = R[3] & 0xFFFE;  /* 0x8009D7CC */
    sh_(R[6] + 2912, R[3]);  /* 0x8009D7D0 */
    { sh_(R[4] + 20, R[5]); psx_next = R[31]; return; }  /* 0x8009D7D4 jr ra */
}

void g0_8009D7DC(void) {
    R[2] = 0x8013u << 16;  /* 0x8009D7DC */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + -29588);  /* 0x8009D7E0 */
    psx_next = 0x8009D7E4u; return;  /* fallthrough */
}

void g0_8009D7E4(void) {
    R[29] = R[29] - 32;  /* 0x8009D7E4 */
    sw_(R[29] + 24, R[31]);  /* 0x8009D7E8 */
    sw_(R[29] + 20, R[17]);  /* 0x8009D7EC */
    { uint32_t _c = (R[2] != R[0]); sw_(R[29] + 16, R[16]); if (_c) { psx_next = 0x8009D8B8u; return; } }  /* 0x8009D7F0 b extern */
    { uint32_t _c = (R[4] == R[0]); R[2] = 0x8012u << 16; if (_c) { goto L_8009D814; } }  /* 0x8009D7F8 */
    R[2] = lh_(R[2] + 31132);  /* 0x8009D800 */
    R[2] = R[2] & 0x1;  /* 0x8009D808 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { psx_next = 0x8009D8BCu; return; } }  /* 0x8009D80C b extern */
L_8009D814:;
    R[17] = 0x8013u << 16;  /* 0x8009D814 */
    R[2] = lh_(R[17] + -29480);  /* 0x8009D818 */
    R[2] = R[2] - 2;  /* 0x8009D820 */
    psx_next = 0x8009D824u; return;  /* fallthrough */
}

void g0_8009D824(void) {
    R[2] = (R[2] < (uint32_t)2u);  /* 0x8009D824 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D8BC; } }  /* 0x8009D828 */
    R[2] = 0x8012u << 16;  /* 0x8009D830 */
    R[16] = R[2] - 26864;  /* 0x8009D834 */
    R[4] = R[16] + R[0];  /* 0x8009D838 */
    { R[31] = 0x8009D844u; R[5] = R[0] + 2; psx_next = 0x8008933Cu; return; }  /* 0x8009D83C jal */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D8BC; } }  /* 0x8009D844 */
    R[3] = 0x8006u << 16;  /* 0x8009D84C */
    R[2] = 0x8006u << 16;  /* 0x8009D850 */
    R[4] = R[2] + 13192;  /* 0x8009D854 */
    R[2] = lh_(R[3] + -6452);  /* 0x8009D858 */
    R[3] = lh_(R[4] + 2920);  /* 0x8009D85C */
    R[2] = R[2] & R[3];  /* 0x8009D864 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D8BC; } }  /* 0x8009D868 */
    R[2] = lh_(R[4] + 2912);  /* 0x8009D870 */
    R[2] = R[2] & 0x1;  /* 0x8009D878 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009D8B8; } }  /* 0x8009D87C */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + -29480);  /* 0x8009D884 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 36; if (_c) { goto L_8009D898; } }  /* 0x8009D88C */
    R[2] = R[0] + 195;  /* 0x8009D894 */
L_8009D898:;
    sh_(R[16] + 20, R[2]);  /* 0x8009D898 */
    R[4] = 0x8006u << 16;  /* 0x8009D89C */
    R[4] = R[4] + 13192;  /* 0x8009D8A0 */
    R[3] = lh_(R[4] + 2912);  /* 0x8009D8A4 */
    R[2] = R[0] + 1;  /* 0x8009D8A8 */
    R[3] = R[3] & 0xFFFE;  /* 0x8009D8AC */
    { sh_(R[4] + 2912, R[3]); goto L_8009D8BC; }  /* 0x8009D8B0 j */
L_8009D8B8:;
    R[2] = R[0] + R[0];  /* 0x8009D8B8 */
L_8009D8BC:;
    R[31] = lw_(R[29] + 24);  /* 0x8009D8BC */
    R[17] = lw_(R[29] + 20);  /* 0x8009D8C0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009D8C4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D8C8 jr ra */
}

void g0_8009D844(void) {
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D8BC; } }  /* 0x8009D844 */
    R[3] = 0x8006u << 16;  /* 0x8009D84C */
    R[2] = 0x8006u << 16;  /* 0x8009D850 */
    R[4] = R[2] + 13192;  /* 0x8009D854 */
    R[2] = lh_(R[3] + -6452);  /* 0x8009D858 */
    R[3] = lh_(R[4] + 2920);  /* 0x8009D85C */
    R[2] = R[2] & R[3];  /* 0x8009D864 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D8BC; } }  /* 0x8009D868 */
    R[2] = lh_(R[4] + 2912);  /* 0x8009D870 */
    R[2] = R[2] & 0x1;  /* 0x8009D878 */
    { uint32_t _c = (R[2] == R[0]); R[2] = R[0] + 1; if (_c) { goto L_8009D8B8; } }  /* 0x8009D87C */
    R[3] = (uint32_t)(int16_t)lh_(R[17] + -29480);  /* 0x8009D884 */
    { uint32_t _c = (R[3] != R[2]); R[2] = R[0] + 36; if (_c) { goto L_8009D898; } }  /* 0x8009D88C */
    R[2] = R[0] + 195;  /* 0x8009D894 */
L_8009D898:;
    sh_(R[16] + 20, R[2]);  /* 0x8009D898 */
    R[4] = 0x8006u << 16;  /* 0x8009D89C */
    R[4] = R[4] + 13192;  /* 0x8009D8A0 */
    R[3] = lh_(R[4] + 2912);  /* 0x8009D8A4 */
    R[2] = R[0] + 1;  /* 0x8009D8A8 */
    R[3] = R[3] & 0xFFFE;  /* 0x8009D8AC */
    { sh_(R[4] + 2912, R[3]); goto L_8009D8BC; }  /* 0x8009D8B0 j */
L_8009D8B8:;
    R[2] = R[0] + R[0];  /* 0x8009D8B8 */
L_8009D8BC:;
    R[31] = lw_(R[29] + 24);  /* 0x8009D8BC */
    R[17] = lw_(R[29] + 20);  /* 0x8009D8C0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009D8C4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D8C8 jr ra */
}

void g0_8009D8B8(void) {
    R[2] = R[0] + R[0];  /* 0x8009D8B8 */
    R[31] = lw_(R[29] + 24);  /* 0x8009D8BC */
    R[17] = lw_(R[29] + 20);  /* 0x8009D8C0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009D8C4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D8C8 jr ra */
}

void g0_8009D8BC(void) {
    R[31] = lw_(R[29] + 24);  /* 0x8009D8BC */
    R[17] = lw_(R[29] + 20);  /* 0x8009D8C0 */
    R[16] = lw_(R[29] + 16);  /* 0x8009D8C4 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D8C8 jr ra */
}

void g0_8009D8D0(void) {
    R[29] = R[29] - 32;  /* 0x8009D8D0 */
    sw_(R[29] + 16, R[16]);  /* 0x8009D8D4 */
    R[16] = R[4] + R[0];  /* 0x8009D8D8 */
    sw_(R[29] + 24, R[31]);  /* 0x8009D8DC */
    sw_(R[29] + 20, R[17]);  /* 0x8009D8E0 */
    R[2] = lb_(R[16] + 784);  /* 0x8009D8E4 */
    { uint32_t _c = (R[2] != R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009D974; } }  /* 0x8009D8EC */
    { R[31] = 0x8009D8FCu; psx_next = 0x80023DC4u; return; }  /* 0x8009D8F4 jal */
    R[3] = R[0] + 25;  /* 0x8009D8FC */
    { uint32_t _c = (R[2] != R[3]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D97C; } }  /* 0x8009D900 */
    R[2] = 0x8013u << 16;  /* 0x8009D908 */
    R[17] = R[2] - 29656;  /* 0x8009D90C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 50);  /* 0x8009D910 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D97C; } }  /* 0x8009D918 */
    R[2] = 0x8006u << 16;  /* 0x8009D920 */
    R[3] = 0x8006u << 16;  /* 0x8009D924 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009D928 */
    R[3] = lh_(R[3] + 16114);  /* 0x8009D92C */
    R[2] = R[2] & R[3];  /* 0x8009D934 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009D978; } }  /* 0x8009D938 */
    { R[31] = 0x8009D948u; R[5] = R[0] + 2; psx_next = 0x8009C12Cu; return; }  /* 0x8009D940 jal */
    R[4] = R[16] + R[0];  /* 0x8009D948 */
    { R[31] = 0x8009D954u; R[5] = R[0] + 13; psx_next = 0x8009BC84u; return; }  /* 0x8009D94C jal */
    R[2] = R[0] + 1;  /* 0x8009D954 */
    R[3] = R[2] + R[0];  /* 0x8009D958 */
    sh_(R[17] + 50, R[3]);  /* 0x8009D95C */
    sw_(R[16] + 140, R[0]);  /* 0x8009D960 */
    sw_(R[16] + 180, R[0]);  /* 0x8009D964 */
    sw_(R[16] + 176, R[0]);  /* 0x8009D968 */
    { sw_(R[16] + 172, R[0]); goto L_8009D97C; }  /* 0x8009D96C j */
L_8009D974:;
    sh_(R[2] + -29606, R[0]);  /* 0x8009D974 */
L_8009D978:;
    R[2] = R[0] + R[0];  /* 0x8009D978 */
L_8009D97C:;
    R[31] = lw_(R[29] + 24);  /* 0x8009D97C */
    R[17] = lw_(R[29] + 20);  /* 0x8009D980 */
    R[16] = lw_(R[29] + 16);  /* 0x8009D984 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D988 jr ra */
}

void g0_8009D8FC(void) {
    R[3] = R[0] + 25;  /* 0x8009D8FC */
    { uint32_t _c = (R[2] != R[3]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D97C; } }  /* 0x8009D900 */
    R[2] = 0x8013u << 16;  /* 0x8009D908 */
    R[17] = R[2] - 29656;  /* 0x8009D90C */
    R[2] = (uint32_t)(int16_t)lh_(R[17] + 50);  /* 0x8009D910 */
    { uint32_t _c = (R[2] != R[0]); R[2] = R[0] + R[0]; if (_c) { goto L_8009D97C; } }  /* 0x8009D918 */
    R[2] = 0x8006u << 16;  /* 0x8009D920 */
    R[3] = 0x8006u << 16;  /* 0x8009D924 */
    R[2] = lh_(R[2] + -6452);  /* 0x8009D928 */
    R[3] = lh_(R[3] + 16114);  /* 0x8009D92C */
    R[2] = R[2] & R[3];  /* 0x8009D934 */
    { uint32_t _c = (R[2] == R[0]); R[4] = R[16] + R[0]; if (_c) { goto L_8009D978; } }  /* 0x8009D938 */
    { R[31] = 0x8009D948u; R[5] = R[0] + 2; psx_next = 0x8009C12Cu; return; }  /* 0x8009D940 jal */
    R[4] = R[16] + R[0];  /* 0x8009D948 */
    { R[31] = 0x8009D954u; R[5] = R[0] + 13; psx_next = 0x8009BC84u; return; }  /* 0x8009D94C jal */
    R[2] = R[0] + 1;  /* 0x8009D954 */
    R[3] = R[2] + R[0];  /* 0x8009D958 */
    sh_(R[17] + 50, R[3]);  /* 0x8009D95C */
    sw_(R[16] + 140, R[0]);  /* 0x8009D960 */
    sw_(R[16] + 180, R[0]);  /* 0x8009D964 */
    sw_(R[16] + 176, R[0]);  /* 0x8009D968 */
    { sw_(R[16] + 172, R[0]); goto L_8009D97C; }  /* 0x8009D96C j */
    sh_(R[2] + -29606, R[0]);  /* 0x8009D974 */
L_8009D978:;
    R[2] = R[0] + R[0];  /* 0x8009D978 */
L_8009D97C:;
    R[31] = lw_(R[29] + 24);  /* 0x8009D97C */
    R[17] = lw_(R[29] + 20);  /* 0x8009D980 */
    R[16] = lw_(R[29] + 16);  /* 0x8009D984 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D988 jr ra */
}

void g0_8009D948(void) {
    R[4] = R[16] + R[0];  /* 0x8009D948 */
    { R[31] = 0x8009D954u; R[5] = R[0] + 13; psx_next = 0x8009BC84u; return; }  /* 0x8009D94C jal */
    R[2] = R[0] + 1;  /* 0x8009D954 */
    R[3] = R[2] + R[0];  /* 0x8009D958 */
    sh_(R[17] + 50, R[3]);  /* 0x8009D95C */
    sw_(R[16] + 140, R[0]);  /* 0x8009D960 */
    sw_(R[16] + 180, R[0]);  /* 0x8009D964 */
    sw_(R[16] + 176, R[0]);  /* 0x8009D968 */
    { sw_(R[16] + 172, R[0]); goto L_8009D97C; }  /* 0x8009D96C j */
    sh_(R[2] + -29606, R[0]);  /* 0x8009D974 */
    R[2] = R[0] + R[0];  /* 0x8009D978 */
L_8009D97C:;
    R[31] = lw_(R[29] + 24);  /* 0x8009D97C */
    R[17] = lw_(R[29] + 20);  /* 0x8009D980 */
    R[16] = lw_(R[29] + 16);  /* 0x8009D984 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D988 jr ra */
}

void g0_8009D954(void) {
    R[2] = R[0] + 1;  /* 0x8009D954 */
    R[3] = R[2] + R[0];  /* 0x8009D958 */
    sh_(R[17] + 50, R[3]);  /* 0x8009D95C */
    sw_(R[16] + 140, R[0]);  /* 0x8009D960 */
    sw_(R[16] + 180, R[0]);  /* 0x8009D964 */
    sw_(R[16] + 176, R[0]);  /* 0x8009D968 */
    { sw_(R[16] + 172, R[0]); goto L_8009D97C; }  /* 0x8009D96C j */
    sh_(R[2] + -29606, R[0]);  /* 0x8009D974 */
    R[2] = R[0] + R[0];  /* 0x8009D978 */
L_8009D97C:;
    R[31] = lw_(R[29] + 24);  /* 0x8009D97C */
    R[17] = lw_(R[29] + 20);  /* 0x8009D980 */
    R[16] = lw_(R[29] + 16);  /* 0x8009D984 */
    { R[29] = R[29] + 32; psx_next = R[31]; return; }  /* 0x8009D988 jr ra */
}

void g0_8009D990(void) {
    R[29] = R[29] - 40;  /* 0x8009D990 */
    R[2] = 0x8012u << 16;  /* 0x8009D994 */
    sw_(R[29] + 28, R[17]);  /* 0x8009D998 */
    R[17] = R[2] - 26864;  /* 0x8009D99C */
    R[2] = 0x8006u << 16;  /* 0x8009D9A0 */
    R[6] = R[2] - 6456;  /* 0x8009D9A4 */
    R[2] = 0x8006u << 16;  /* 0x8009D9A8 */
    R[2] = R[2] + 13192;  /* 0x8009D9AC */
    sw_(R[29] + 32, R[31]);  /* 0x8009D9B0 */
    sw_(R[29] + 24, R[16]);  /* 0x8009D9B4 */
    R[3] = lh_(R[2] + 2918);  /* 0x8009D9B8 */
    R[5] = lh_(R[2] + 2920);  /* 0x8009D9BC */
    R[4] = lh_(R[2] + 2922);  /* 0x8009D9C0 */
    R[2] = lh_(R[2] + 2924);  /* 0x8009D9C4 */
    R[3] = R[3] | R[5];  /* 0x8009D9C8 */
    R[4] = R[4] | R[3];  /* 0x8009D9CC */
    R[3] = lh_(R[6] + 2);  /* 0x8009D9D0 */
    R[2] = R[2] | R[4];  /* 0x8009D9D4 */
    R[3] = R[3] & R[2];  /* 0x8009D9D8 */
    { uint32_t _c = (R[3] != R[0]); R[2] = 0x8013u << 16; if (_c) { goto L_8009DA14; } }  /* 0x8009D9DC */
    R[3] = lw_(R[6] + 16);  /* 0x8009D9E4 */
    R[2] = R[0] - 1;  /* 0x8009D9E8 */
    { uint32_t _c = (R[3] != R[2]); R[2] = 0x8013u << 16; if (_c) { goto L_8009DA14; } }  /* 0x8009D9EC */
    R[5] = R[2] - 29656;  /* 0x8009D9F4 */
    R[3] = R[0] + 90;  /* 0x8009D9F8 */
    R[2] = (uint32_t)(int16_t)lh_(R[5] + 48);  /* 0x8009D9FC */
    R[4] = lh_(R[5] + 48);  /* 0x8009DA00 */
    { uint32_t _c = (R[2] == R[3]); R[2] = R[4] + 1; if (_c) { goto L_8009DA34; } }  /* 0x8009DA04 */
    { sh_(R[5] + 48, R[2]); goto L_8009DA20; }  /* 0x8009DA0C j */
L_8009DA14:;
    R[2] = R[2] - 29656;  /* 0x8009DA14 */
    sh_(R[2] + 48, R[0]);  /* 0x8009DA18 */
    sh_(R[2] + 46, R[0]);  /* 0x8009DA1C */
L_8009DA20:;
    R[2] = 0x8013u << 16;  /* 0x8009DA20 */
    R[3] = (uint32_t)(int16_t)lh_(R[2] + -29608);  /* 0x8009DA24 */
    R[2] = R[0] + 90;  /* 0x8009DA28 */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009DB50; } }  /* 0x8009DA2C */
L_8009DA34:;
    R[2] = 0x8013u << 16;  /* 0x8009DA34 */
    R[4] = R[2] - 29656;  /* 0x8009DA38 */
    R[2] = lh_(R[4] + 46);  /* 0x8009DA3C */
    R[3] = R[0] + 10;  /* 0x8009DA40 */
    R[2] = R[2] + 1;  /* 0x8009DA44 */
    sh_(R[4] + 46, R[2]);  /* 0x8009DA48 */
    R[2] = R[2] << 16;  /* 0x8009DA4C */
    R[2] = (uint32_t)((int32_t)R[2] >> 16);  /* 0x8009DA50 */
    { uint32_t _c = (R[2] != R[3]); if (_c) { goto L_8009DB50; } }  /* 0x8009DA54 */
    { R[31] = 0x8009DA64u; sh_(R[4] + 46, R[0]); psx_next = 0x8001D258u; return; }  /* 0x8009DA5C jal */
    { R[31] = 0x8009DA6Cu; R[16] = R[2] + R[0]; psx_next = 0x8001D2A4u; return; }  /* 0x8009DA64 jal */
    R[16] = R[16] << 16;  /* 0x8009DA6C */
    R[2] = R[2] << 16;  /* 0x8009DA70 */
    { uint32_t _c = (R[16] == R[2]); R[16] = R[0] + 1; if (_c) { goto L_8009DAD8; } }  /* 0x8009DA74 */
    { R[31] = 0x8009DA84u; R[4] = R[0] + 76; psx_next = 0x80023CE8u; return; }  /* 0x8009DA7C jal */
    { uint32_t _c = ((int32_t)R[2] < 0); if (_c) { goto L_8009DA9C; } }  /* 0x8009DA84 */
    R[4] = R[0] + 76;  /* 0x8009DA8C */
    { R[31] = 0x8009DA98u; R[5] = R[0] + 9; psx_next = 0x80023ECCu; return; }  /* 0x8009DA90 jal */
    R[16] = R[2] + R[16];  /* 0x8009DA98 */
L_8009DA9C:;
    R[4] = R[16] << 16;  /* 0x8009DA9C */
    { R[31] = 0x8009DAA8u; R[4] = (uint32_t)((int32_t)R[4] >> 16); psx_next = 0x8001D1C8u; return; }  /* 0x8009DAA0 jal */
    R[4] = R[0] + 29;  /* 0x8009DAA8 */
    R[5] = lw_(R[17] + 24);  /* 0x8009DAAC */
    R[7] = lw_(R[17] + 32);  /* 0x8009DAB0 */
    R[6] = lw_(R[17] + 488);  /* 0x8009DAB4 */
    R[2] = R[0] + 2;  /* 0x8009DAB8 */
    sw_(R[29] + 16, R[2]);  /* 0x8009DABC */
    R[2] = R[6] >> 31;  /* 0x8009DAC0 */
    R[6] = R[6] + R[2];  /* 0x8009DAC4 */
    R[2] = lw_(R[17] + 28);  /* 0x8009DAC8 */
    R[6] = (uint32_t)((int32_t)R[6] >> 1);  /* 0x8009DACC */
    { R[31] = 0x8009DAD8u; R[6] = R[2] + R[6]; psx_next = 0x800A7290u; return; }  /* 0x8009DAD0 jal */
L_8009DAD8:;
    { R[31] = 0x8009DAE0u; psx_next = 0x8001D16Cu; return; }  /* 0x8009DAD8 jal */
    { R[31] = 0x8009DAE8u; R[16] = R[2] + R[0]; psx_next = 0x8001D1B8u; return; }  /* 0x8009DAE0 jal */
    R[16] = R[16] << 16;  /* 0x8009DAE8 */
    R[2] = R[2] << 16;  /* 0x8009DAEC */
    { uint32_t _c = (R[16] == R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8009DB50; } }  /* 0x8009DAF0 */
    R[3] = R[3] + 15308;  /* 0x8009DAF8 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 726);  /* 0x8009DAFC */
    R[2] = R[2] + R[3];  /* 0x8009DB04 */
    R[3] = (uint32_t)(int8_t)lb_(R[2] + 88);  /* 0x8009DB08 */
    R[2] = R[0] + 51;  /* 0x8009DB0C */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009DB50; } }  /* 0x8009DB10 */
    { R[31] = 0x8009DB20u; R[4] = R[0] + 1; psx_next = 0x8001D0DCu; return; }  /* 0x8009DB18 jal */
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
L_8009DB50:;
    R[31] = lw_(R[29] + 32);  /* 0x8009DB50 */
    R[17] = lw_(R[29] + 28);  /* 0x8009DB54 */
    R[16] = lw_(R[29] + 24);  /* 0x8009DB58 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009DB5C jr ra */
}

void g0_8009DA64(void) {
    { R[31] = 0x8009DA6Cu; R[16] = R[2] + R[0]; psx_next = 0x8001D2A4u; return; }  /* 0x8009DA64 jal */
    R[16] = R[16] << 16;  /* 0x8009DA6C */
    R[2] = R[2] << 16;  /* 0x8009DA70 */
    { uint32_t _c = (R[16] == R[2]); R[16] = R[0] + 1; if (_c) { goto L_8009DAD8; } }  /* 0x8009DA74 */
    { R[31] = 0x8009DA84u; R[4] = R[0] + 76; psx_next = 0x80023CE8u; return; }  /* 0x8009DA7C jal */
    { uint32_t _c = ((int32_t)R[2] < 0); if (_c) { goto L_8009DA9C; } }  /* 0x8009DA84 */
    R[4] = R[0] + 76;  /* 0x8009DA8C */
    { R[31] = 0x8009DA98u; R[5] = R[0] + 9; psx_next = 0x80023ECCu; return; }  /* 0x8009DA90 jal */
    R[16] = R[2] + R[16];  /* 0x8009DA98 */
L_8009DA9C:;
    R[4] = R[16] << 16;  /* 0x8009DA9C */
    { R[31] = 0x8009DAA8u; R[4] = (uint32_t)((int32_t)R[4] >> 16); psx_next = 0x8001D1C8u; return; }  /* 0x8009DAA0 jal */
    R[4] = R[0] + 29;  /* 0x8009DAA8 */
    R[5] = lw_(R[17] + 24);  /* 0x8009DAAC */
    R[7] = lw_(R[17] + 32);  /* 0x8009DAB0 */
    R[6] = lw_(R[17] + 488);  /* 0x8009DAB4 */
    R[2] = R[0] + 2;  /* 0x8009DAB8 */
    sw_(R[29] + 16, R[2]);  /* 0x8009DABC */
    R[2] = R[6] >> 31;  /* 0x8009DAC0 */
    R[6] = R[6] + R[2];  /* 0x8009DAC4 */
    R[2] = lw_(R[17] + 28);  /* 0x8009DAC8 */
    R[6] = (uint32_t)((int32_t)R[6] >> 1);  /* 0x8009DACC */
    { R[31] = 0x8009DAD8u; R[6] = R[2] + R[6]; psx_next = 0x800A7290u; return; }  /* 0x8009DAD0 jal */
L_8009DAD8:;
    { R[31] = 0x8009DAE0u; psx_next = 0x8001D16Cu; return; }  /* 0x8009DAD8 jal */
    { R[31] = 0x8009DAE8u; R[16] = R[2] + R[0]; psx_next = 0x8001D1B8u; return; }  /* 0x8009DAE0 jal */
    R[16] = R[16] << 16;  /* 0x8009DAE8 */
    R[2] = R[2] << 16;  /* 0x8009DAEC */
    { uint32_t _c = (R[16] == R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8009DB50; } }  /* 0x8009DAF0 */
    R[3] = R[3] + 15308;  /* 0x8009DAF8 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 726);  /* 0x8009DAFC */
    R[2] = R[2] + R[3];  /* 0x8009DB04 */
    R[3] = (uint32_t)(int8_t)lb_(R[2] + 88);  /* 0x8009DB08 */
    R[2] = R[0] + 51;  /* 0x8009DB0C */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009DB50; } }  /* 0x8009DB10 */
    { R[31] = 0x8009DB20u; R[4] = R[0] + 1; psx_next = 0x8001D0DCu; return; }  /* 0x8009DB18 jal */
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
L_8009DB50:;
    R[31] = lw_(R[29] + 32);  /* 0x8009DB50 */
    R[17] = lw_(R[29] + 28);  /* 0x8009DB54 */
    R[16] = lw_(R[29] + 24);  /* 0x8009DB58 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009DB5C jr ra */
}

void g0_8009DA6C(void) {
    R[16] = R[16] << 16;  /* 0x8009DA6C */
    R[2] = R[2] << 16;  /* 0x8009DA70 */
    { uint32_t _c = (R[16] == R[2]); R[16] = R[0] + 1; if (_c) { goto L_8009DAD8; } }  /* 0x8009DA74 */
    { R[31] = 0x8009DA84u; R[4] = R[0] + 76; psx_next = 0x80023CE8u; return; }  /* 0x8009DA7C jal */
    { uint32_t _c = ((int32_t)R[2] < 0); if (_c) { goto L_8009DA9C; } }  /* 0x8009DA84 */
    R[4] = R[0] + 76;  /* 0x8009DA8C */
    { R[31] = 0x8009DA98u; R[5] = R[0] + 9; psx_next = 0x80023ECCu; return; }  /* 0x8009DA90 jal */
    R[16] = R[2] + R[16];  /* 0x8009DA98 */
L_8009DA9C:;
    R[4] = R[16] << 16;  /* 0x8009DA9C */
    { R[31] = 0x8009DAA8u; R[4] = (uint32_t)((int32_t)R[4] >> 16); psx_next = 0x8001D1C8u; return; }  /* 0x8009DAA0 jal */
    R[4] = R[0] + 29;  /* 0x8009DAA8 */
    R[5] = lw_(R[17] + 24);  /* 0x8009DAAC */
    R[7] = lw_(R[17] + 32);  /* 0x8009DAB0 */
    R[6] = lw_(R[17] + 488);  /* 0x8009DAB4 */
    R[2] = R[0] + 2;  /* 0x8009DAB8 */
    sw_(R[29] + 16, R[2]);  /* 0x8009DABC */
    R[2] = R[6] >> 31;  /* 0x8009DAC0 */
    R[6] = R[6] + R[2];  /* 0x8009DAC4 */
    R[2] = lw_(R[17] + 28);  /* 0x8009DAC8 */
    R[6] = (uint32_t)((int32_t)R[6] >> 1);  /* 0x8009DACC */
    { R[31] = 0x8009DAD8u; R[6] = R[2] + R[6]; psx_next = 0x800A7290u; return; }  /* 0x8009DAD0 jal */
L_8009DAD8:;
    { R[31] = 0x8009DAE0u; psx_next = 0x8001D16Cu; return; }  /* 0x8009DAD8 jal */
    { R[31] = 0x8009DAE8u; R[16] = R[2] + R[0]; psx_next = 0x8001D1B8u; return; }  /* 0x8009DAE0 jal */
    R[16] = R[16] << 16;  /* 0x8009DAE8 */
    R[2] = R[2] << 16;  /* 0x8009DAEC */
    { uint32_t _c = (R[16] == R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8009DB50; } }  /* 0x8009DAF0 */
    R[3] = R[3] + 15308;  /* 0x8009DAF8 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 726);  /* 0x8009DAFC */
    R[2] = R[2] + R[3];  /* 0x8009DB04 */
    R[3] = (uint32_t)(int8_t)lb_(R[2] + 88);  /* 0x8009DB08 */
    R[2] = R[0] + 51;  /* 0x8009DB0C */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009DB50; } }  /* 0x8009DB10 */
    { R[31] = 0x8009DB20u; R[4] = R[0] + 1; psx_next = 0x8001D0DCu; return; }  /* 0x8009DB18 jal */
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
L_8009DB50:;
    R[31] = lw_(R[29] + 32);  /* 0x8009DB50 */
    R[17] = lw_(R[29] + 28);  /* 0x8009DB54 */
    R[16] = lw_(R[29] + 24);  /* 0x8009DB58 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009DB5C jr ra */
}

void g0_8009DA84(void) {
    { uint32_t _c = ((int32_t)R[2] < 0); if (_c) { goto L_8009DA9C; } }  /* 0x8009DA84 */
    R[4] = R[0] + 76;  /* 0x8009DA8C */
    { R[31] = 0x8009DA98u; R[5] = R[0] + 9; psx_next = 0x80023ECCu; return; }  /* 0x8009DA90 jal */
    R[16] = R[2] + R[16];  /* 0x8009DA98 */
L_8009DA9C:;
    R[4] = R[16] << 16;  /* 0x8009DA9C */
    { R[31] = 0x8009DAA8u; R[4] = (uint32_t)((int32_t)R[4] >> 16); psx_next = 0x8001D1C8u; return; }  /* 0x8009DAA0 jal */
    R[4] = R[0] + 29;  /* 0x8009DAA8 */
    R[5] = lw_(R[17] + 24);  /* 0x8009DAAC */
    R[7] = lw_(R[17] + 32);  /* 0x8009DAB0 */
    R[6] = lw_(R[17] + 488);  /* 0x8009DAB4 */
    R[2] = R[0] + 2;  /* 0x8009DAB8 */
    sw_(R[29] + 16, R[2]);  /* 0x8009DABC */
    R[2] = R[6] >> 31;  /* 0x8009DAC0 */
    R[6] = R[6] + R[2];  /* 0x8009DAC4 */
    R[2] = lw_(R[17] + 28);  /* 0x8009DAC8 */
    R[6] = (uint32_t)((int32_t)R[6] >> 1);  /* 0x8009DACC */
    { R[31] = 0x8009DAD8u; R[6] = R[2] + R[6]; psx_next = 0x800A7290u; return; }  /* 0x8009DAD0 jal */
    { R[31] = 0x8009DAE0u; psx_next = 0x8001D16Cu; return; }  /* 0x8009DAD8 jal */
    { R[31] = 0x8009DAE8u; R[16] = R[2] + R[0]; psx_next = 0x8001D1B8u; return; }  /* 0x8009DAE0 jal */
    R[16] = R[16] << 16;  /* 0x8009DAE8 */
    R[2] = R[2] << 16;  /* 0x8009DAEC */
    { uint32_t _c = (R[16] == R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8009DB50; } }  /* 0x8009DAF0 */
    R[3] = R[3] + 15308;  /* 0x8009DAF8 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 726);  /* 0x8009DAFC */
    R[2] = R[2] + R[3];  /* 0x8009DB04 */
    R[3] = (uint32_t)(int8_t)lb_(R[2] + 88);  /* 0x8009DB08 */
    R[2] = R[0] + 51;  /* 0x8009DB0C */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009DB50; } }  /* 0x8009DB10 */
    { R[31] = 0x8009DB20u; R[4] = R[0] + 1; psx_next = 0x8001D0DCu; return; }  /* 0x8009DB18 jal */
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
L_8009DB50:;
    R[31] = lw_(R[29] + 32);  /* 0x8009DB50 */
    R[17] = lw_(R[29] + 28);  /* 0x8009DB54 */
    R[16] = lw_(R[29] + 24);  /* 0x8009DB58 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009DB5C jr ra */
}

void g0_8009DA98(void) {
    R[16] = R[2] + R[16];  /* 0x8009DA98 */
    R[4] = R[16] << 16;  /* 0x8009DA9C */
    { R[31] = 0x8009DAA8u; R[4] = (uint32_t)((int32_t)R[4] >> 16); psx_next = 0x8001D1C8u; return; }  /* 0x8009DAA0 jal */
    R[4] = R[0] + 29;  /* 0x8009DAA8 */
    R[5] = lw_(R[17] + 24);  /* 0x8009DAAC */
    R[7] = lw_(R[17] + 32);  /* 0x8009DAB0 */
    R[6] = lw_(R[17] + 488);  /* 0x8009DAB4 */
    R[2] = R[0] + 2;  /* 0x8009DAB8 */
    sw_(R[29] + 16, R[2]);  /* 0x8009DABC */
    R[2] = R[6] >> 31;  /* 0x8009DAC0 */
    R[6] = R[6] + R[2];  /* 0x8009DAC4 */
    R[2] = lw_(R[17] + 28);  /* 0x8009DAC8 */
    R[6] = (uint32_t)((int32_t)R[6] >> 1);  /* 0x8009DACC */
    { R[31] = 0x8009DAD8u; R[6] = R[2] + R[6]; psx_next = 0x800A7290u; return; }  /* 0x8009DAD0 jal */
    { R[31] = 0x8009DAE0u; psx_next = 0x8001D16Cu; return; }  /* 0x8009DAD8 jal */
    { R[31] = 0x8009DAE8u; R[16] = R[2] + R[0]; psx_next = 0x8001D1B8u; return; }  /* 0x8009DAE0 jal */
    R[16] = R[16] << 16;  /* 0x8009DAE8 */
    R[2] = R[2] << 16;  /* 0x8009DAEC */
    { uint32_t _c = (R[16] == R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8009DB50; } }  /* 0x8009DAF0 */
    R[3] = R[3] + 15308;  /* 0x8009DAF8 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 726);  /* 0x8009DAFC */
    R[2] = R[2] + R[3];  /* 0x8009DB04 */
    R[3] = (uint32_t)(int8_t)lb_(R[2] + 88);  /* 0x8009DB08 */
    R[2] = R[0] + 51;  /* 0x8009DB0C */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009DB50; } }  /* 0x8009DB10 */
    { R[31] = 0x8009DB20u; R[4] = R[0] + 1; psx_next = 0x8001D0DCu; return; }  /* 0x8009DB18 jal */
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
L_8009DB50:;
    R[31] = lw_(R[29] + 32);  /* 0x8009DB50 */
    R[17] = lw_(R[29] + 28);  /* 0x8009DB54 */
    R[16] = lw_(R[29] + 24);  /* 0x8009DB58 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009DB5C jr ra */
}

void g0_8009DAA8(void) {
    R[4] = R[0] + 29;  /* 0x8009DAA8 */
    R[5] = lw_(R[17] + 24);  /* 0x8009DAAC */
    R[7] = lw_(R[17] + 32);  /* 0x8009DAB0 */
    R[6] = lw_(R[17] + 488);  /* 0x8009DAB4 */
    R[2] = R[0] + 2;  /* 0x8009DAB8 */
    sw_(R[29] + 16, R[2]);  /* 0x8009DABC */
    R[2] = R[6] >> 31;  /* 0x8009DAC0 */
    R[6] = R[6] + R[2];  /* 0x8009DAC4 */
    R[2] = lw_(R[17] + 28);  /* 0x8009DAC8 */
    R[6] = (uint32_t)((int32_t)R[6] >> 1);  /* 0x8009DACC */
    { R[31] = 0x8009DAD8u; R[6] = R[2] + R[6]; psx_next = 0x800A7290u; return; }  /* 0x8009DAD0 jal */
    { R[31] = 0x8009DAE0u; psx_next = 0x8001D16Cu; return; }  /* 0x8009DAD8 jal */
    { R[31] = 0x8009DAE8u; R[16] = R[2] + R[0]; psx_next = 0x8001D1B8u; return; }  /* 0x8009DAE0 jal */
    R[16] = R[16] << 16;  /* 0x8009DAE8 */
    R[2] = R[2] << 16;  /* 0x8009DAEC */
    { uint32_t _c = (R[16] == R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8009DB50; } }  /* 0x8009DAF0 */
    R[3] = R[3] + 15308;  /* 0x8009DAF8 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 726);  /* 0x8009DAFC */
    R[2] = R[2] + R[3];  /* 0x8009DB04 */
    R[3] = (uint32_t)(int8_t)lb_(R[2] + 88);  /* 0x8009DB08 */
    R[2] = R[0] + 51;  /* 0x8009DB0C */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009DB50; } }  /* 0x8009DB10 */
    { R[31] = 0x8009DB20u; R[4] = R[0] + 1; psx_next = 0x8001D0DCu; return; }  /* 0x8009DB18 jal */
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
L_8009DB50:;
    R[31] = lw_(R[29] + 32);  /* 0x8009DB50 */
    R[17] = lw_(R[29] + 28);  /* 0x8009DB54 */
    R[16] = lw_(R[29] + 24);  /* 0x8009DB58 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009DB5C jr ra */
}

void g0_8009DAD8(void) {
    { R[31] = 0x8009DAE0u; psx_next = 0x8001D16Cu; return; }  /* 0x8009DAD8 jal */
    { R[31] = 0x8009DAE8u; R[16] = R[2] + R[0]; psx_next = 0x8001D1B8u; return; }  /* 0x8009DAE0 jal */
    R[16] = R[16] << 16;  /* 0x8009DAE8 */
    R[2] = R[2] << 16;  /* 0x8009DAEC */
    { uint32_t _c = (R[16] == R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8009DB50; } }  /* 0x8009DAF0 */
    R[3] = R[3] + 15308;  /* 0x8009DAF8 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 726);  /* 0x8009DAFC */
    R[2] = R[2] + R[3];  /* 0x8009DB04 */
    R[3] = (uint32_t)(int8_t)lb_(R[2] + 88);  /* 0x8009DB08 */
    R[2] = R[0] + 51;  /* 0x8009DB0C */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009DB50; } }  /* 0x8009DB10 */
    { R[31] = 0x8009DB20u; R[4] = R[0] + 1; psx_next = 0x8001D0DCu; return; }  /* 0x8009DB18 jal */
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
L_8009DB50:;
    R[31] = lw_(R[29] + 32);  /* 0x8009DB50 */
    R[17] = lw_(R[29] + 28);  /* 0x8009DB54 */
    R[16] = lw_(R[29] + 24);  /* 0x8009DB58 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009DB5C jr ra */
}

void g0_8009DAE0(void) {
    { R[31] = 0x8009DAE8u; R[16] = R[2] + R[0]; psx_next = 0x8001D1B8u; return; }  /* 0x8009DAE0 jal */
    R[16] = R[16] << 16;  /* 0x8009DAE8 */
    R[2] = R[2] << 16;  /* 0x8009DAEC */
    { uint32_t _c = (R[16] == R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8009DB50; } }  /* 0x8009DAF0 */
    R[3] = R[3] + 15308;  /* 0x8009DAF8 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 726);  /* 0x8009DAFC */
    R[2] = R[2] + R[3];  /* 0x8009DB04 */
    R[3] = (uint32_t)(int8_t)lb_(R[2] + 88);  /* 0x8009DB08 */
    R[2] = R[0] + 51;  /* 0x8009DB0C */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009DB50; } }  /* 0x8009DB10 */
    { R[31] = 0x8009DB20u; R[4] = R[0] + 1; psx_next = 0x8001D0DCu; return; }  /* 0x8009DB18 jal */
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
L_8009DB50:;
    R[31] = lw_(R[29] + 32);  /* 0x8009DB50 */
    R[17] = lw_(R[29] + 28);  /* 0x8009DB54 */
    R[16] = lw_(R[29] + 24);  /* 0x8009DB58 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009DB5C jr ra */
}

void g0_8009DAE8(void) {
    R[16] = R[16] << 16;  /* 0x8009DAE8 */
    R[2] = R[2] << 16;  /* 0x8009DAEC */
    { uint32_t _c = (R[16] == R[2]); R[3] = 0x8006u << 16; if (_c) { goto L_8009DB50; } }  /* 0x8009DAF0 */
    R[3] = R[3] + 15308;  /* 0x8009DAF8 */
    R[2] = (uint32_t)(int16_t)lh_(R[3] + 726);  /* 0x8009DAFC */
    R[2] = R[2] + R[3];  /* 0x8009DB04 */
    R[3] = (uint32_t)(int8_t)lb_(R[2] + 88);  /* 0x8009DB08 */
    R[2] = R[0] + 51;  /* 0x8009DB0C */
    { uint32_t _c = (R[3] != R[2]); if (_c) { goto L_8009DB50; } }  /* 0x8009DB10 */
    { R[31] = 0x8009DB20u; R[4] = R[0] + 1; psx_next = 0x8001D0DCu; return; }  /* 0x8009DB18 jal */
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
L_8009DB50:;
    R[31] = lw_(R[29] + 32);  /* 0x8009DB50 */
    R[17] = lw_(R[29] + 28);  /* 0x8009DB54 */
    R[16] = lw_(R[29] + 24);  /* 0x8009DB58 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x8009DB5C jr ra */
}
