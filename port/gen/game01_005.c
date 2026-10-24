#include "game01_decls.h"

void g1_800885E0(void) {
    R[29] = R[29] - 24;  /* 0x800885E0 */
    R[3] = 0x8009u << 16;  /* 0x800885E4 */
    R[2] = R[0] + 2;  /* 0x800885E8 */
    sw_(R[3] + -17440, R[2]);  /* 0x800885EC */
    R[2] = 0x8009u << 16;  /* 0x800885F0 */
    sw_(R[2] + -28880, R[0]);  /* 0x800885F4 */
    R[2] = 0x8009u << 16;  /* 0x800885F8 */
    sw_(R[29] + 16, R[31]);  /* 0x800885FC */
    { R[31] = 0x80088608u; sw_(R[2] + -28860, R[0]); psx_next = 0x8002DF4Cu; return; }  /* 0x80088600 jal */
    R[31] = lw_(R[29] + 16);  /* 0x80088608 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x80088610 jr ra */
}

void g1_80088608(void) {
    R[31] = lw_(R[29] + 16);  /* 0x80088608 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x80088610 jr ra */
}

void g1_80088618(void) {
    R[29] = R[29] - 24;  /* 0x80088618 */
    R[3] = 0x8009u << 16;  /* 0x8008861C */
    R[2] = R[0] + 3;  /* 0x80088620 */
    sw_(R[3] + -17440, R[2]);  /* 0x80088624 */
    R[2] = 0x800Au << 16;  /* 0x80088628 */
    R[4] = R[2] - 11128;  /* 0x8008862C */
    sw_(R[29] + 16, R[31]);  /* 0x80088630 */
    R[3] = lw_(R[4] + 24);  /* 0x80088634 */
    R[5] = lw_(R[4] + 16);  /* 0x80088638 */
    R[2] = 0x8009u << 16;  /* 0x8008863C */
    R[3] = ((int32_t)R[5] < (int32_t)R[3]);  /* 0x80088640 */
    { uint32_t _c = (R[3] == R[0]); sw_(R[2] + -28880, R[0]); if (_c) { goto L_80088650; } }  /* 0x80088644 */
    sw_(R[4] + 24, R[5]);  /* 0x8008864C */
L_80088650:;
    R[5] = 0x1Fu << 16;  /* 0x80088650 */
    R[5] = R[5] | 0x4000;  /* 0x80088654 */
    R[4] = R[0] + 7301;  /* 0x80088658 */
    R[2] = 0x8009u << 16;  /* 0x8008865C */
    R[3] = R[0] + 8;  /* 0x80088660 */
    sw_(R[2] + -28920, R[3]);  /* 0x80088664 */
    R[2] = R[2] - 28920;  /* 0x80088668 */
    R[3] = R[0] - 400;  /* 0x8008866C */
    sw_(R[2] + 4, R[3]);  /* 0x80088670 */
    R[2] = 0x8009u << 16;  /* 0x80088674 */
    { R[31] = 0x80088680u; sw_(R[2] + -28904, R[5]); psx_next = 0x8002DB10u; return; }  /* 0x80088678 jal */
    { R[31] = 0x80088688u; R[4] = R[0] + 1; psx_next = 0x800871F8u; return; }  /* 0x80088680 jal */
    R[31] = lw_(R[29] + 16);  /* 0x80088688 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x80088690 jr ra */
}

void g1_80088680(void) {
    { R[31] = 0x80088688u; R[4] = R[0] + 1; psx_next = 0x800871F8u; return; }  /* 0x80088680 jal */
    R[31] = lw_(R[29] + 16);  /* 0x80088688 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x80088690 jr ra */
}

void g1_80088688(void) {
    R[31] = lw_(R[29] + 16);  /* 0x80088688 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x80088690 jr ra */
}

void g1_80088698(void) {
    R[29] = R[29] - 24;  /* 0x80088698 */
    R[5] = R[0] + R[0];  /* 0x8008869C */
    R[2] = 0x800Au << 16;  /* 0x800886A0 */
    R[2] = R[2] + 13248;  /* 0x800886A4 */
    R[7] = R[2] + R[0];  /* 0x800886A8 */
    R[2] = 0x8009u << 16;  /* 0x800886AC */
    R[4] = R[2] - 29544;  /* 0x800886B0 */
    R[2] = 0x800Au << 16;  /* 0x800886B4 */
    R[3] = 0x8009u << 16;  /* 0x800886B8 */
    R[6] = lw_(R[2] + -11112);  /* 0x800886BC */
    R[2] = R[0] + 4;  /* 0x800886C0 */
    sw_(R[3] + -17440, R[2]);  /* 0x800886C4 */
    R[2] = 0x8009u << 16;  /* 0x800886C8 */
    sw_(R[29] + 16, R[31]);  /* 0x800886CC */
    sw_(R[2] + -28880, R[0]);  /* 0x800886D0 */
    sw_(R[7] + 12, R[0]);  /* 0x800886D4 */
L_800886D8:;
    R[3] = lw_(R[4]);  /* 0x800886D8 */
    R[2] = R[3] << 4;  /* 0x800886E0 */
    R[2] = R[2] - R[3];  /* 0x800886E4 */
    R[2] = R[2] << 2;  /* 0x800886E8 */
    R[2] = ((int32_t)R[6] < (int32_t)R[2]);  /* 0x800886EC */
    { uint32_t _c = (R[2] == R[0]); R[5] = R[5] + 1; if (_c) { goto L_80088704; } }  /* 0x800886F0 */
    R[2] = lw_(R[4] + 4);  /* 0x800886F8 */
    { sw_(R[7] + 12, R[2]); goto L_80088710; }  /* 0x800886FC j */
L_80088704:;
    R[2] = ((int32_t)R[5] < 16);  /* 0x80088704 */
    { uint32_t _c = (R[2] != R[0]); R[4] = R[4] + 8; if (_c) { psx_bb(); goto L_800886D8; } }  /* 0x80088708 */
L_80088710:;
    R[2] = 0x800Au << 16;  /* 0x80088710 */
    R[2] = R[2] + 13248;  /* 0x80088714 */
    R[3] = lw_(R[2] + 4);  /* 0x80088718 */
    R[4] = lw_(R[2] + 12);  /* 0x8008871C */
    { R[31] = 0x80088728u; R[4] = R[3] + R[4]; psx_next = 0x8001D2D4u; return; }  /* 0x80088720 jal */
    { R[31] = 0x80088730u; R[4] = R[0] + 1; psx_next = 0x800871F8u; return; }  /* 0x80088728 jal */
    { R[31] = 0x80088738u; R[4] = R[0] + R[0]; psx_next = 0x8002DE94u; return; }  /* 0x80088730 jal */
    R[31] = lw_(R[29] + 16);  /* 0x80088738 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x80088740 jr ra */
}

void g1_80088728(void) {
    { R[31] = 0x80088730u; R[4] = R[0] + 1; psx_next = 0x800871F8u; return; }  /* 0x80088728 jal */
    { R[31] = 0x80088738u; R[4] = R[0] + R[0]; psx_next = 0x8002DE94u; return; }  /* 0x80088730 jal */
    R[31] = lw_(R[29] + 16);  /* 0x80088738 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x80088740 jr ra */
}

void g1_80088730(void) {
    { R[31] = 0x80088738u; R[4] = R[0] + R[0]; psx_next = 0x8002DE94u; return; }  /* 0x80088730 jal */
    R[31] = lw_(R[29] + 16);  /* 0x80088738 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x80088740 jr ra */
}

void g1_80088738(void) {
    R[31] = lw_(R[29] + 16);  /* 0x80088738 */
    { R[29] = R[29] + 24; psx_next = R[31]; return; }  /* 0x80088740 jr ra */
}

void g1_80088748(void) {
    R[2] = 0x8006u << 16;  /* 0x80088748 */
    R[2] = (uint32_t)(int16_t)lh_(R[2] + 13232);  /* 0x8008874C */
    psx_next = 0x80088750u; return;  /* fallthrough */
}

void g1_80088750(void) {
    R[29] = R[29] - 40;  /* 0x80088750 */
    { uint32_t _c = (R[2] != R[0]); sw_(R[29] + 32, R[31]); if (_c) { psx_next = 0x80088788u; return; } }  /* 0x80088754 b extern */
    R[2] = R[0] + 100;  /* 0x8008875C */
    psx_next = 0x80088760u; return;  /* fallthrough */
}

void g1_80088760(void) {
    R[4] = 0x8006u << 16;  /* 0x80088760 */
    R[5] = 0x8009u << 16;  /* 0x80088764 */
    R[4] = R[4] + 29872;  /* 0x80088768 */
    R[5] = R[5] - 17140;  /* 0x8008876C */
    R[6] = R[0] + 3;  /* 0x80088770 */
    R[7] = R[0] + 1;  /* 0x80088774 */
    sw_(R[29] + 16, R[0]);  /* 0x80088778 */
    sw_(R[29] + 20, R[0]);  /* 0x8008877C */
    { R[31] = 0x80088788u; sw_(R[29] + 24, R[2]); psx_next = 0x8002AA0Cu; return; }  /* 0x80088780 jal */
    R[31] = lw_(R[29] + 32);  /* 0x80088788 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x80088790 jr ra */
    R[9] = R[4] + R[0];  /* 0x80088798 */
    R[15] = R[5] + R[0];  /* 0x8008879C */
    R[2] = 0x8009u << 16;  /* 0x800887A0 */
    R[13] = lh_(R[2] + -29336);  /* 0x800887A4 */
    R[7] = 0x800Fu << 16;  /* 0x800887A8 */
    R[14] = 0x800Fu << 16;  /* 0x800887AC */
    R[12] = R[0] + 8;  /* 0x800887B0 */
    R[10] = 0x800Fu << 16;  /* 0x800887B4 */
    R[8] = 0xFFu << 16;  /* 0x800887B8 */
    R[8] = R[8] | 0xFFFF;  /* 0x800887BC */
    R[11] = 0xFF00u << 16;  /* 0x800887C0 */
L_800887C4:;
    R[3] = lb_(R[6]);  /* 0x800887C4 */
    { uint32_t _c = (R[3] == R[0]); R[6] = R[6] + 1; if (_c) { goto L_800888AC; } }  /* 0x800887CC */
    R[4] = lw_(R[7] + 1912);  /* 0x800887D4 */
    R[2] = lw_(R[14] + 1944);  /* 0x800887D8 */
    R[2] = (R[4] < R[2]);  /* 0x800887E0 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[3] - 32; if (_c) { goto L_800888AC; } }  /* 0x800887E4 */
    R[2] = R[3] & 0x1F;  /* 0x800887EC */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[2] << 3; if (_c) { goto L_800887FC; } }  /* 0x800887F0 */
    R[3] = R[3] + 31;  /* 0x800887F8 */
L_800887FC:;
    sb_(R[4] + 12, R[2]);  /* 0x800887FC */
    R[2] = (uint32_t)((int32_t)R[3] >> 5);  /* 0x80088800 */
    R[3] = lw_(R[7] + 1912);  /* 0x80088804 */
    R[2] = R[2] << 3;  /* 0x80088808 */
    sh_(R[4] + 8, R[9]);  /* 0x8008880C */
    sh_(R[4] + 10, R[15]);  /* 0x80088810 */
    sb_(R[3] + 13, R[2]);  /* 0x80088814 */
    R[3] = lw_(R[7] + 1912);  /* 0x80088818 */
    R[2] = lb_(R[3] + 7);  /* 0x80088820 */
    R[2] = R[2] & 0xFD;  /* 0x80088828 */
    sb_(R[3] + 7, R[2]);  /* 0x8008882C */
    R[4] = lw_(R[7] + 1912);  /* 0x80088830 */
    R[2] = lb_(R[10] + 1904);  /* 0x80088834 */
    sh_(R[3] + 16, R[12]);  /* 0x80088838 */
    sh_(R[3] + 18, R[12]);  /* 0x8008883C */
    sh_(R[3] + 14, R[13]);  /* 0x80088840 */
    sb_(R[4] + 4, R[2]);  /* 0x80088844 */
    R[3] = lw_(R[7] + 1912);  /* 0x80088848 */
    R[2] = lb_(R[10] + 1904);  /* 0x8008884C */
    sb_(R[3] + 5, R[2]);  /* 0x80088854 */
    R[3] = lw_(R[7] + 1912);  /* 0x80088858 */
    R[2] = lb_(R[10] + 1904);  /* 0x8008885C */
    R[9] = R[9] + 8;  /* 0x80088860 */
    sb_(R[3] + 6, R[2]);  /* 0x80088864 */
    R[2] = 0x800Fu << 16;  /* 0x80088868 */
    R[4] = lw_(R[7] + 1912);  /* 0x8008886C */
    R[5] = lw_(R[2] + 1896);  /* 0x80088870 */
    R[3] = lw_(R[4]);  /* 0x80088874 */
    R[2] = lw_(R[5]);  /* 0x80088878 */
    R[3] = R[3] & R[11];  /* 0x8008887C */
    R[2] = R[2] & R[8];  /* 0x80088880 */
    R[3] = R[3] | R[2];  /* 0x80088884 */
    R[2] = R[4] + 20;  /* 0x80088888 */
    sw_(R[4], R[3]);  /* 0x8008888C */
    R[3] = lw_(R[5]);  /* 0x80088890 */
    R[4] = R[4] & R[8];  /* 0x80088894 */
    sw_(R[7] + 1912, R[2]);  /* 0x80088898 */
    R[3] = R[3] & R[11];  /* 0x8008889C */
    R[3] = R[3] | R[4];  /* 0x800888A0 */
    { sw_(R[5], R[3]); psx_bb(); goto L_800887C4; }  /* 0x800888A4 j */
L_800888AC:;
    { psx_next = R[31]; return; }  /* 0x800888AC jr ra */
}

void g1_80088788(void) {
    R[31] = lw_(R[29] + 32);  /* 0x80088788 */
    { R[29] = R[29] + 40; psx_next = R[31]; return; }  /* 0x80088790 jr ra */
    R[9] = R[4] + R[0];  /* 0x80088798 */
    R[15] = R[5] + R[0];  /* 0x8008879C */
    R[2] = 0x8009u << 16;  /* 0x800887A0 */
    R[13] = lh_(R[2] + -29336);  /* 0x800887A4 */
    R[7] = 0x800Fu << 16;  /* 0x800887A8 */
    R[14] = 0x800Fu << 16;  /* 0x800887AC */
    R[12] = R[0] + 8;  /* 0x800887B0 */
    R[10] = 0x800Fu << 16;  /* 0x800887B4 */
    R[8] = 0xFFu << 16;  /* 0x800887B8 */
    R[8] = R[8] | 0xFFFF;  /* 0x800887BC */
    R[11] = 0xFF00u << 16;  /* 0x800887C0 */
L_800887C4:;
    R[3] = lb_(R[6]);  /* 0x800887C4 */
    { uint32_t _c = (R[3] == R[0]); R[6] = R[6] + 1; if (_c) { goto L_800888AC; } }  /* 0x800887CC */
    R[4] = lw_(R[7] + 1912);  /* 0x800887D4 */
    R[2] = lw_(R[14] + 1944);  /* 0x800887D8 */
    R[2] = (R[4] < R[2]);  /* 0x800887E0 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[3] - 32; if (_c) { goto L_800888AC; } }  /* 0x800887E4 */
    R[2] = R[3] & 0x1F;  /* 0x800887EC */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[2] << 3; if (_c) { goto L_800887FC; } }  /* 0x800887F0 */
    R[3] = R[3] + 31;  /* 0x800887F8 */
L_800887FC:;
    sb_(R[4] + 12, R[2]);  /* 0x800887FC */
    R[2] = (uint32_t)((int32_t)R[3] >> 5);  /* 0x80088800 */
    R[3] = lw_(R[7] + 1912);  /* 0x80088804 */
    R[2] = R[2] << 3;  /* 0x80088808 */
    sh_(R[4] + 8, R[9]);  /* 0x8008880C */
    sh_(R[4] + 10, R[15]);  /* 0x80088810 */
    sb_(R[3] + 13, R[2]);  /* 0x80088814 */
    R[3] = lw_(R[7] + 1912);  /* 0x80088818 */
    R[2] = lb_(R[3] + 7);  /* 0x80088820 */
    R[2] = R[2] & 0xFD;  /* 0x80088828 */
    sb_(R[3] + 7, R[2]);  /* 0x8008882C */
    R[4] = lw_(R[7] + 1912);  /* 0x80088830 */
    R[2] = lb_(R[10] + 1904);  /* 0x80088834 */
    sh_(R[3] + 16, R[12]);  /* 0x80088838 */
    sh_(R[3] + 18, R[12]);  /* 0x8008883C */
    sh_(R[3] + 14, R[13]);  /* 0x80088840 */
    sb_(R[4] + 4, R[2]);  /* 0x80088844 */
    R[3] = lw_(R[7] + 1912);  /* 0x80088848 */
    R[2] = lb_(R[10] + 1904);  /* 0x8008884C */
    sb_(R[3] + 5, R[2]);  /* 0x80088854 */
    R[3] = lw_(R[7] + 1912);  /* 0x80088858 */
    R[2] = lb_(R[10] + 1904);  /* 0x8008885C */
    R[9] = R[9] + 8;  /* 0x80088860 */
    sb_(R[3] + 6, R[2]);  /* 0x80088864 */
    R[2] = 0x800Fu << 16;  /* 0x80088868 */
    R[4] = lw_(R[7] + 1912);  /* 0x8008886C */
    R[5] = lw_(R[2] + 1896);  /* 0x80088870 */
    R[3] = lw_(R[4]);  /* 0x80088874 */
    R[2] = lw_(R[5]);  /* 0x80088878 */
    R[3] = R[3] & R[11];  /* 0x8008887C */
    R[2] = R[2] & R[8];  /* 0x80088880 */
    R[3] = R[3] | R[2];  /* 0x80088884 */
    R[2] = R[4] + 20;  /* 0x80088888 */
    sw_(R[4], R[3]);  /* 0x8008888C */
    R[3] = lw_(R[5]);  /* 0x80088890 */
    R[4] = R[4] & R[8];  /* 0x80088894 */
    sw_(R[7] + 1912, R[2]);  /* 0x80088898 */
    R[3] = R[3] & R[11];  /* 0x8008889C */
    R[3] = R[3] | R[4];  /* 0x800888A0 */
    { sw_(R[5], R[3]); psx_bb(); goto L_800887C4; }  /* 0x800888A4 j */
L_800888AC:;
    { psx_next = R[31]; return; }  /* 0x800888AC jr ra */
}

void g1_800888B4(void) {
    R[9] = R[4] + R[0];  /* 0x800888B4 */
    R[14] = R[5] + R[0];  /* 0x800888B8 */
    R[2] = 0x8009u << 16;  /* 0x800888BC */
    R[12] = lh_(R[2] + -29336);  /* 0x800888C0 */
    R[7] = 0x800Fu << 16;  /* 0x800888C4 */
    R[13] = 0x800Fu << 16;  /* 0x800888C8 */
    R[10] = 0x800Fu << 16;  /* 0x800888CC */
    R[8] = 0xFFu << 16;  /* 0x800888D0 */
    R[8] = R[8] | 0xFFFF;  /* 0x800888D4 */
    R[11] = 0xFF00u << 16;  /* 0x800888D8 */
L_800888DC:;
    R[3] = lb_(R[6]);  /* 0x800888DC */
    { uint32_t _c = (R[3] == R[0]); R[6] = R[6] + 1; if (_c) { goto L_800889CC; } }  /* 0x800888E4 */
    R[4] = lw_(R[7] + 1912);  /* 0x800888EC */
    R[2] = lw_(R[13] + 1944);  /* 0x800888F0 */
    R[2] = (R[4] < R[2]);  /* 0x800888F8 */
    { uint32_t _c = (R[2] == R[0]); R[3] = R[3] - 32; if (_c) { goto L_800889CC; } }  /* 0x800888FC */
    R[2] = R[3] & 0x1F;  /* 0x80088904 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[2] << 3; if (_c) { goto L_80088914; } }  /* 0x80088908 */
    R[3] = R[3] + 31;  /* 0x80088910 */
L_80088914:;
    sb_(R[4] + 12, R[2]);  /* 0x80088914 */
    R[2] = (uint32_t)((int32_t)R[3] >> 5);  /* 0x80088918 */
    R[2] = R[2] << 4;  /* 0x8008891C */
    R[3] = lw_(R[7] + 1912);  /* 0x80088920 */
    R[2] = R[2] + 32;  /* 0x80088924 */
    sh_(R[4] + 8, R[9]);  /* 0x80088928 */
    sh_(R[4] + 10, R[14]);  /* 0x8008892C */
    sb_(R[3] + 13, R[2]);  /* 0x80088930 */
    R[4] = lw_(R[7] + 1912);  /* 0x80088934 */
    R[3] = lb_(R[4] + 7);  /* 0x8008893C */
    R[2] = R[0] + 8;  /* 0x80088940 */
    sh_(R[4] + 16, R[2]);  /* 0x80088944 */
    R[3] = R[3] & 0xFD;  /* 0x80088948 */
    sb_(R[4] + 7, R[3]);  /* 0x8008894C */
    R[5] = lw_(R[7] + 1912);  /* 0x80088950 */
    R[3] = lb_(R[10] + 1904);  /* 0x80088954 */
    R[2] = R[0] + 16;  /* 0x80088958 */
    sh_(R[4] + 18, R[2]);  /* 0x8008895C */
    sh_(R[4] + 14, R[12]);  /* 0x80088960 */
    sb_(R[5] + 4, R[3]);  /* 0x80088964 */
    R[3] = lw_(R[7] + 1912);  /* 0x80088968 */
    R[2] = lb_(R[10] + 1904);  /* 0x8008896C */
    sb_(R[3] + 5, R[2]);  /* 0x80088974 */
    R[3] = lw_(R[7] + 1912);  /* 0x80088978 */
    R[2] = lb_(R[10] + 1904);  /* 0x8008897C */
    R[9] = R[9] + 8;  /* 0x80088980 */
    sb_(R[3] + 6, R[2]);  /* 0x80088984 */
    R[2] = 0x800Fu << 16;  /* 0x80088988 */
    R[4] = lw_(R[7] + 1912);  /* 0x8008898C */
    R[5] = lw_(R[2] + 1896);  /* 0x80088990 */
    R[3] = lw_(R[4]);  /* 0x80088994 */
    R[2] = lw_(R[5]);  /* 0x80088998 */
    R[3] = R[3] & R[11];  /* 0x8008899C */
    R[2] = R[2] & R[8];  /* 0x800889A0 */
    R[3] = R[3] | R[2];  /* 0x800889A4 */
    R[2] = R[4] + 20;  /* 0x800889A8 */
    sw_(R[4], R[3]);  /* 0x800889AC */
    R[3] = lw_(R[5]);  /* 0x800889B0 */
    R[4] = R[4] & R[8];  /* 0x800889B4 */
    sw_(R[7] + 1912, R[2]);  /* 0x800889B8 */
    R[3] = R[3] & R[11];  /* 0x800889BC */
    R[3] = R[3] | R[4];  /* 0x800889C0 */
    { sw_(R[5], R[3]); psx_bb(); goto L_800888DC; }  /* 0x800889C4 j */
L_800889CC:;
    { psx_next = R[31]; return; }  /* 0x800889CC jr ra */
}

void g1_800889D4(void) {
    R[29] = R[29] - 80;  /* 0x800889D4 */
    sw_(R[29] + 60, R[17]);  /* 0x800889D8 */
    psx_next = 0x800889DCu; return;  /* fallthrough */
}

void g1_800889DC(void) {
    R[17] = R[4] + R[0];  /* 0x800889DC */
    sw_(R[29] + 68, R[19]);  /* 0x800889E0 */
    R[19] = R[5] + R[0];  /* 0x800889E4 */
    sw_(R[29] + 64, R[18]);  /* 0x800889E8 */
    R[18] = R[6] + R[0];  /* 0x800889EC */
    sw_(R[29] + 56, R[16]);  /* 0x800889F0 */
    R[16] = R[29] + 40;  /* 0x800889F4 */
    R[4] = R[16] + R[0];  /* 0x800889F8 */
    R[2] = 0x8009u << 16;  /* 0x800889FC */
    R[5] = R[0] + R[0];  /* 0x80088A00 */
    psx_next = 0x80088A04u; return;  /* fallthrough */
}

void g1_80088A04(void) {
    R[7] = lh_(R[2] + -29350);  /* 0x80088A04 */
    R[6] = R[5] + R[0];  /* 0x80088A08 */
    sw_(R[29] + 72, R[31]);  /* 0x80088A0C */
    { R[31] = 0x80088A18u; sw_(R[29] + 16, R[0]); psx_next = 0x800359A8u; return; }  /* 0x80088A10 jal */
    { R[31] = 0x80088A20u; R[4] = R[16] + R[0]; psx_next = 0x80032E8Cu; return; }  /* 0x80088A18 jal */
    { R[31] = 0x80088A28u; R[4] = R[29] + 24; psx_next = 0x800357F8u; return; }  /* 0x80088A20 jal */
    R[2] = 0x8009u << 16;  /* 0x80088A28 */
    R[16] = R[2] - 29348;  /* 0x80088A2C */
L_80088A30:;
    R[2] = lb_(R[18]);  /* 0x80088A30 */
    { uint32_t _c = (R[2] == R[0]); R[18] = R[18] + 1; if (_c) { goto L_80088AB0; } }  /* 0x80088A38 */
    R[2] = R[2] - 32;  /* 0x80088A40 */
    R[3] = R[2] + R[0];  /* 0x80088A44 */
    R[2] = R[3] & 0x1F;  /* 0x80088A48 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[2] << 3; if (_c) { goto L_80088A58; } }  /* 0x80088A4C */
    R[3] = R[3] + 31;  /* 0x80088A54 */
L_80088A58:;
    sb_(R[29] + 36, R[2]);  /* 0x80088A58 */
    R[2] = (uint32_t)((int32_t)R[3] >> 5);  /* 0x80088A5C */
    sh_(R[29] + 32, R[17]);  /* 0x80088A60 */
    sh_(R[29] + 34, R[19]);  /* 0x80088A64 */
    R[3] = lh_(R[16] + 12);  /* 0x80088A68 */
    R[2] = R[2] << 3;  /* 0x80088A6C */
    sb_(R[29] + 37, R[2]);  /* 0x80088A70 */
    R[2] = lb_(R[29] + 31);  /* 0x80088A74 */
    R[4] = R[29] + 24;  /* 0x80088A78 */
    sh_(R[29] + 38, R[3]);  /* 0x80088A7C */
    R[3] = 0x800Fu << 16;  /* 0x80088A80 */
    R[3] = lb_(R[3] + 1904);  /* 0x80088A84 */
    R[2] = R[2] & 0xFD;  /* 0x80088A88 */
    sb_(R[29] + 31, R[2]);  /* 0x80088A8C */
    sb_(R[29] + 28, R[3]);  /* 0x80088A90 */
    sb_(R[29] + 29, R[3]);  /* 0x80088A94 */
    { R[31] = 0x80088AA0u; sb_(R[29] + 30, R[3]); psx_next = 0x80032E8Cu; return; }  /* 0x80088A98 jal */
    { R[31] = 0x80088AA8u; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x80088AA0 jal */
    { R[17] = R[17] + 8; psx_bb(); goto L_80088A30; }  /* 0x80088AA8 j */
L_80088AB0:;
    R[31] = lw_(R[29] + 72);  /* 0x80088AB0 */
    R[19] = lw_(R[29] + 68);  /* 0x80088AB4 */
    R[18] = lw_(R[29] + 64);  /* 0x80088AB8 */
    R[17] = lw_(R[29] + 60);  /* 0x80088ABC */
    R[16] = lw_(R[29] + 56);  /* 0x80088AC0 */
    { R[29] = R[29] + 80; psx_next = R[31]; return; }  /* 0x80088AC4 jr ra */
}

void g1_80088A18(void) {
    { R[31] = 0x80088A20u; R[4] = R[16] + R[0]; psx_next = 0x80032E8Cu; return; }  /* 0x80088A18 jal */
    { R[31] = 0x80088A28u; R[4] = R[29] + 24; psx_next = 0x800357F8u; return; }  /* 0x80088A20 jal */
    R[2] = 0x8009u << 16;  /* 0x80088A28 */
    R[16] = R[2] - 29348;  /* 0x80088A2C */
L_80088A30:;
    R[2] = lb_(R[18]);  /* 0x80088A30 */
    { uint32_t _c = (R[2] == R[0]); R[18] = R[18] + 1; if (_c) { goto L_80088AB0; } }  /* 0x80088A38 */
    R[2] = R[2] - 32;  /* 0x80088A40 */
    R[3] = R[2] + R[0];  /* 0x80088A44 */
    R[2] = R[3] & 0x1F;  /* 0x80088A48 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[2] << 3; if (_c) { goto L_80088A58; } }  /* 0x80088A4C */
    R[3] = R[3] + 31;  /* 0x80088A54 */
L_80088A58:;
    sb_(R[29] + 36, R[2]);  /* 0x80088A58 */
    R[2] = (uint32_t)((int32_t)R[3] >> 5);  /* 0x80088A5C */
    sh_(R[29] + 32, R[17]);  /* 0x80088A60 */
    sh_(R[29] + 34, R[19]);  /* 0x80088A64 */
    R[3] = lh_(R[16] + 12);  /* 0x80088A68 */
    R[2] = R[2] << 3;  /* 0x80088A6C */
    sb_(R[29] + 37, R[2]);  /* 0x80088A70 */
    R[2] = lb_(R[29] + 31);  /* 0x80088A74 */
    R[4] = R[29] + 24;  /* 0x80088A78 */
    sh_(R[29] + 38, R[3]);  /* 0x80088A7C */
    R[3] = 0x800Fu << 16;  /* 0x80088A80 */
    R[3] = lb_(R[3] + 1904);  /* 0x80088A84 */
    R[2] = R[2] & 0xFD;  /* 0x80088A88 */
    sb_(R[29] + 31, R[2]);  /* 0x80088A8C */
    sb_(R[29] + 28, R[3]);  /* 0x80088A90 */
    sb_(R[29] + 29, R[3]);  /* 0x80088A94 */
    { R[31] = 0x80088AA0u; sb_(R[29] + 30, R[3]); psx_next = 0x80032E8Cu; return; }  /* 0x80088A98 jal */
    { R[31] = 0x80088AA8u; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x80088AA0 jal */
    { R[17] = R[17] + 8; psx_bb(); goto L_80088A30; }  /* 0x80088AA8 j */
L_80088AB0:;
    R[31] = lw_(R[29] + 72);  /* 0x80088AB0 */
    R[19] = lw_(R[29] + 68);  /* 0x80088AB4 */
    R[18] = lw_(R[29] + 64);  /* 0x80088AB8 */
    R[17] = lw_(R[29] + 60);  /* 0x80088ABC */
    R[16] = lw_(R[29] + 56);  /* 0x80088AC0 */
    { R[29] = R[29] + 80; psx_next = R[31]; return; }  /* 0x80088AC4 jr ra */
}

void g1_80088A20(void) {
    { R[31] = 0x80088A28u; R[4] = R[29] + 24; psx_next = 0x800357F8u; return; }  /* 0x80088A20 jal */
    R[2] = 0x8009u << 16;  /* 0x80088A28 */
    R[16] = R[2] - 29348;  /* 0x80088A2C */
L_80088A30:;
    R[2] = lb_(R[18]);  /* 0x80088A30 */
    { uint32_t _c = (R[2] == R[0]); R[18] = R[18] + 1; if (_c) { goto L_80088AB0; } }  /* 0x80088A38 */
    R[2] = R[2] - 32;  /* 0x80088A40 */
    R[3] = R[2] + R[0];  /* 0x80088A44 */
    R[2] = R[3] & 0x1F;  /* 0x80088A48 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[2] << 3; if (_c) { goto L_80088A58; } }  /* 0x80088A4C */
    R[3] = R[3] + 31;  /* 0x80088A54 */
L_80088A58:;
    sb_(R[29] + 36, R[2]);  /* 0x80088A58 */
    R[2] = (uint32_t)((int32_t)R[3] >> 5);  /* 0x80088A5C */
    sh_(R[29] + 32, R[17]);  /* 0x80088A60 */
    sh_(R[29] + 34, R[19]);  /* 0x80088A64 */
    R[3] = lh_(R[16] + 12);  /* 0x80088A68 */
    R[2] = R[2] << 3;  /* 0x80088A6C */
    sb_(R[29] + 37, R[2]);  /* 0x80088A70 */
    R[2] = lb_(R[29] + 31);  /* 0x80088A74 */
    R[4] = R[29] + 24;  /* 0x80088A78 */
    sh_(R[29] + 38, R[3]);  /* 0x80088A7C */
    R[3] = 0x800Fu << 16;  /* 0x80088A80 */
    R[3] = lb_(R[3] + 1904);  /* 0x80088A84 */
    R[2] = R[2] & 0xFD;  /* 0x80088A88 */
    sb_(R[29] + 31, R[2]);  /* 0x80088A8C */
    sb_(R[29] + 28, R[3]);  /* 0x80088A90 */
    sb_(R[29] + 29, R[3]);  /* 0x80088A94 */
    { R[31] = 0x80088AA0u; sb_(R[29] + 30, R[3]); psx_next = 0x80032E8Cu; return; }  /* 0x80088A98 jal */
    { R[31] = 0x80088AA8u; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x80088AA0 jal */
    { R[17] = R[17] + 8; psx_bb(); goto L_80088A30; }  /* 0x80088AA8 j */
L_80088AB0:;
    R[31] = lw_(R[29] + 72);  /* 0x80088AB0 */
    R[19] = lw_(R[29] + 68);  /* 0x80088AB4 */
    R[18] = lw_(R[29] + 64);  /* 0x80088AB8 */
    R[17] = lw_(R[29] + 60);  /* 0x80088ABC */
    R[16] = lw_(R[29] + 56);  /* 0x80088AC0 */
    { R[29] = R[29] + 80; psx_next = R[31]; return; }  /* 0x80088AC4 jr ra */
}

void g1_80088A28(void) {
    R[2] = 0x8009u << 16;  /* 0x80088A28 */
    R[16] = R[2] - 29348;  /* 0x80088A2C */
L_80088A30:;
    R[2] = lb_(R[18]);  /* 0x80088A30 */
    { uint32_t _c = (R[2] == R[0]); R[18] = R[18] + 1; if (_c) { goto L_80088AB0; } }  /* 0x80088A38 */
    R[2] = R[2] - 32;  /* 0x80088A40 */
    R[3] = R[2] + R[0];  /* 0x80088A44 */
    R[2] = R[3] & 0x1F;  /* 0x80088A48 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[2] << 3; if (_c) { goto L_80088A58; } }  /* 0x80088A4C */
    R[3] = R[3] + 31;  /* 0x80088A54 */
L_80088A58:;
    sb_(R[29] + 36, R[2]);  /* 0x80088A58 */
    R[2] = (uint32_t)((int32_t)R[3] >> 5);  /* 0x80088A5C */
    sh_(R[29] + 32, R[17]);  /* 0x80088A60 */
    sh_(R[29] + 34, R[19]);  /* 0x80088A64 */
    R[3] = lh_(R[16] + 12);  /* 0x80088A68 */
    R[2] = R[2] << 3;  /* 0x80088A6C */
    sb_(R[29] + 37, R[2]);  /* 0x80088A70 */
    R[2] = lb_(R[29] + 31);  /* 0x80088A74 */
    R[4] = R[29] + 24;  /* 0x80088A78 */
    sh_(R[29] + 38, R[3]);  /* 0x80088A7C */
    R[3] = 0x800Fu << 16;  /* 0x80088A80 */
    R[3] = lb_(R[3] + 1904);  /* 0x80088A84 */
    R[2] = R[2] & 0xFD;  /* 0x80088A88 */
    sb_(R[29] + 31, R[2]);  /* 0x80088A8C */
    sb_(R[29] + 28, R[3]);  /* 0x80088A90 */
    sb_(R[29] + 29, R[3]);  /* 0x80088A94 */
    { R[31] = 0x80088AA0u; sb_(R[29] + 30, R[3]); psx_next = 0x80032E8Cu; return; }  /* 0x80088A98 jal */
    { R[31] = 0x80088AA8u; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x80088AA0 jal */
    { R[17] = R[17] + 8; psx_bb(); goto L_80088A30; }  /* 0x80088AA8 j */
L_80088AB0:;
    R[31] = lw_(R[29] + 72);  /* 0x80088AB0 */
    R[19] = lw_(R[29] + 68);  /* 0x80088AB4 */
    R[18] = lw_(R[29] + 64);  /* 0x80088AB8 */
    R[17] = lw_(R[29] + 60);  /* 0x80088ABC */
    R[16] = lw_(R[29] + 56);  /* 0x80088AC0 */
    { R[29] = R[29] + 80; psx_next = R[31]; return; }  /* 0x80088AC4 jr ra */
}

void g1_80088A30(void) {
L_80088A30:;
    R[2] = lb_(R[18]);  /* 0x80088A30 */
    { uint32_t _c = (R[2] == R[0]); R[18] = R[18] + 1; if (_c) { goto L_80088AB0; } }  /* 0x80088A38 */
    R[2] = R[2] - 32;  /* 0x80088A40 */
    R[3] = R[2] + R[0];  /* 0x80088A44 */
    R[2] = R[3] & 0x1F;  /* 0x80088A48 */
    { uint32_t _c = ((int32_t)R[3] >= 0); R[2] = R[2] << 3; if (_c) { goto L_80088A58; } }  /* 0x80088A4C */
    R[3] = R[3] + 31;  /* 0x80088A54 */
L_80088A58:;
    sb_(R[29] + 36, R[2]);  /* 0x80088A58 */
    R[2] = (uint32_t)((int32_t)R[3] >> 5);  /* 0x80088A5C */
    sh_(R[29] + 32, R[17]);  /* 0x80088A60 */
    sh_(R[29] + 34, R[19]);  /* 0x80088A64 */
    R[3] = lh_(R[16] + 12);  /* 0x80088A68 */
    R[2] = R[2] << 3;  /* 0x80088A6C */
    sb_(R[29] + 37, R[2]);  /* 0x80088A70 */
    R[2] = lb_(R[29] + 31);  /* 0x80088A74 */
    R[4] = R[29] + 24;  /* 0x80088A78 */
    sh_(R[29] + 38, R[3]);  /* 0x80088A7C */
    R[3] = 0x800Fu << 16;  /* 0x80088A80 */
    R[3] = lb_(R[3] + 1904);  /* 0x80088A84 */
    R[2] = R[2] & 0xFD;  /* 0x80088A88 */
    sb_(R[29] + 31, R[2]);  /* 0x80088A8C */
    sb_(R[29] + 28, R[3]);  /* 0x80088A90 */
    sb_(R[29] + 29, R[3]);  /* 0x80088A94 */
    { R[31] = 0x80088AA0u; sb_(R[29] + 30, R[3]); psx_next = 0x80032E8Cu; return; }  /* 0x80088A98 jal */
    { R[31] = 0x80088AA8u; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x80088AA0 jal */
    { R[17] = R[17] + 8; psx_bb(); goto L_80088A30; }  /* 0x80088AA8 j */
L_80088AB0:;
    R[31] = lw_(R[29] + 72);  /* 0x80088AB0 */
    R[19] = lw_(R[29] + 68);  /* 0x80088AB4 */
    R[18] = lw_(R[29] + 64);  /* 0x80088AB8 */
    R[17] = lw_(R[29] + 60);  /* 0x80088ABC */
    R[16] = lw_(R[29] + 56);  /* 0x80088AC0 */
    { R[29] = R[29] + 80; psx_next = R[31]; return; }  /* 0x80088AC4 jr ra */
}

void g1_80088AA0(void) {
    { R[31] = 0x80088AA8u; R[4] = R[0] + R[0]; psx_next = 0x800328F4u; return; }  /* 0x80088AA0 jal */
    { R[17] = R[17] + 8; psx_next = 0x80088A30u; return; }  /* 0x80088AA8 j extern */
    R[31] = lw_(R[29] + 72);  /* 0x80088AB0 */
    R[19] = lw_(R[29] + 68);  /* 0x80088AB4 */
    R[18] = lw_(R[29] + 64);  /* 0x80088AB8 */
    R[17] = lw_(R[29] + 60);  /* 0x80088ABC */
    R[16] = lw_(R[29] + 56);  /* 0x80088AC0 */
    { R[29] = R[29] + 80; psx_next = R[31]; return; }  /* 0x80088AC4 jr ra */
}

void g1_80088AA8(void) {
    { R[17] = R[17] + 8; psx_next = 0x80088A30u; return; }  /* 0x80088AA8 j extern */
    R[31] = lw_(R[29] + 72);  /* 0x80088AB0 */
    R[19] = lw_(R[29] + 68);  /* 0x80088AB4 */
    R[18] = lw_(R[29] + 64);  /* 0x80088AB8 */
    R[17] = lw_(R[29] + 60);  /* 0x80088ABC */
    R[16] = lw_(R[29] + 56);  /* 0x80088AC0 */
    { R[29] = R[29] + 80; psx_next = R[31]; return; }  /* 0x80088AC4 jr ra */
}

void g1_80088ACC(void) {
    R[29] = R[29] - 88;  /* 0x80088ACC */
    sw_(R[29] + 68, R[17]);  /* 0x80088AD0 */
    R[17] = R[4] + R[0];  /* 0x80088AD4 */
    sw_(R[29] + 76, R[19]);  /* 0x80088AD8 */
    R[19] = R[5] + R[0];  /* 0x80088ADC */
    sw_(R[29] + 72, R[18]);  /* 0x80088AE0 */
    R[18] = R[6] + R[0];  /* 0x80088AE4 */
    sw_(R[29] + 64, R[16]);  /* 0x80088AE8 */
    R[16] = R[29] + 48;  /* 0x80088AEC */
    R[4] = R[16] + R[0];  /* 0x80088AF0 */
    R[2] = 0x8009u << 16;  /* 0x80088AF4 */
    R[5] = R[0] + R[0];  /* 0x80088AF8 */
    R[7] = lh_(R[2] + -29350);  /* 0x80088AFC */
    R[6] = R[5] + R[0];  /* 0x80088B00 */
    sw_(R[29] + 80, R[31]);  /* 0x80088B04 */
    { R[31] = 0x80088B10u; sw_(R[29] + 16, R[0]); psx_next = 0x800359A8u; return; }  /* 0x80088B08 jal */
    { R[31] = 0x80088B18u; R[4] = R[16] + R[0]; psx_next = 0x80032E8Cu; return; }  /* 0x80088B10 jal */
    { R[31] = 0x80088B20u; R[4] = R[29] + 24; psx_next = 0x80035818u; return; }  /* 0x80088B18 jal */
    R[2] = 0x8009u << 16;  /* 0x80088B20 */
    R[16] = R[2] - 29348;  /* 0x80088B24 */
    psx_next = 0x80088B28u; return;  /* fallthrough */
}

void g1_80088B10(void) {
    { R[31] = 0x80088B18u; R[4] = R[16] + R[0]; psx_next = 0x80032E8Cu; return; }  /* 0x80088B10 jal */
    { R[31] = 0x80088B20u; R[4] = R[29] + 24; psx_next = 0x80035818u; return; }  /* 0x80088B18 jal */
    R[2] = 0x8009u << 16;  /* 0x80088B20 */
    R[16] = R[2] - 29348;  /* 0x80088B24 */
    psx_next = 0x80088B28u; return;  /* fallthrough */
}

void g1_80088B18(void) {
    { R[31] = 0x80088B20u; R[4] = R[29] + 24; psx_next = 0x80035818u; return; }  /* 0x80088B18 jal */
    R[2] = 0x8009u << 16;  /* 0x80088B20 */
    R[16] = R[2] - 29348;  /* 0x80088B24 */
    psx_next = 0x80088B28u; return;  /* fallthrough */
}

void g1_80088B20(void) {
    R[2] = 0x8009u << 16;  /* 0x80088B20 */
    R[16] = R[2] - 29348;  /* 0x80088B24 */
    psx_next = 0x80088B28u; return;  /* fallthrough */
}

void g1_80088B28(void) { psx_trap(0x80088B28u); }  /* 0x80088BD8: unsupported word 0x00000028 (op=0, fn=40) */

void g1_80088BAC(void) { psx_trap(0x80088BACu); }  /* 0x80088BD8: unsupported word 0x00000028 (op=0, fn=40) */

void g1_80088BB4(void) { psx_trap(0x80088BB4u); }  /* 0x80088BD8: unsupported word 0x00000028 (op=0, fn=40) */

void g1_80088BD8(void) { psx_trap(0x80088BD8u); }  /* 0x80088BD8: unsupported word 0x00000028 (op=0, fn=40) */

void g1_80088C6C(void) { psx_trap(0x80088C6Cu); }  /* 0x80088C6C: unsupported word 0x0000001E (op=0, fn=30) */

void g1_80088C98(void) { psx_trap(0x80088C98u); }  /* 0x80088C9C: unsupported word 0x000003E8 (op=0, fn=40) */

void g1_80088D54(void) { psx_trap(0x80088D54u); }  /* 0x80088D64: unsupported word 0x0000FFFF (op=0, fn=63) */

void g1_80088D5C(void) { psx_trap(0x80088D5Cu); }  /* 0x80088D64: unsupported word 0x0000FFFF (op=0, fn=63) */

void g1_80088D7C(void) {
    (void)(R[0] << 0);  /* 0x80088D7C */
    (void)(R[0] << 0);  /* 0x80088D84 */
    (void)(R[0] << 0);  /* 0x80088D8C */
    psx_next = 0x80088DCCu; return;  /* fallthrough */
}

void g1_80088DCC(void) { psx_trap(0x80088DCCu); }  /* 0x80088DD4: unsupported word 0x0000FFFF (op=0, fn=63) */

void g1_80088DDC(void) { psx_trap(0x80088DDCu); }  /* 0x80088DDC: unsupported word 0x02C00001 (op=0, fn=1) */

void g1_80088DEC(void) { psx_trap(0x80088DECu); }  /* 0x80088DEC: unsupported word 0x03400001 (op=0, fn=1) */

void g1_80088DFC(void) { psx_trap(0x80088DFCu); }  /* 0x80088DFC: unsupported word 0x03400001 (op=0, fn=1) */

void g1_80088E0C(void) { psx_trap(0x80088E0Cu); }  /* 0x80088E3C: unsupported word 0x0000FFFF (op=0, fn=63) */

void g1_80088E34(void) { psx_trap(0x80088E34u); }  /* 0x80088E3C: unsupported word 0x0000FFFF (op=0, fn=63) */

void g1_80088E44(void) {
    (void)(R[0] << 1);  /* 0x80088E50 */
    (void)(R[0] << 2);  /* 0x80088E5C */
    (void)(R[0] << 3);  /* 0x80088E68 */
    psx_next = 0x80088E74u; return;  /* fallthrough */
}

void g1_80088E54(void) {
    (void)(R[0] << 2);  /* 0x80088E5C */
    (void)(R[0] << 3);  /* 0x80088E68 */
    psx_next = 0x80088E74u; return;  /* fallthrough */
}

void g1_80088E74(void) { psx_trap(0x80088E74u); }  /* 0x80088EF4: unsupported word 0x02C00001 (op=0, fn=1) */

void g1_80088EEC(void) { psx_trap(0x80088EECu); }  /* 0x80088EF4: unsupported word 0x02C00001 (op=0, fn=1) */

void g1_80088F08(void) { psx_trap(0x80088F08u); }  /* 0x80088F0C: unsupported word 0xFFFFFE70 (op=63, fn=48) */

void g1_80088F18(void) { psx_trap(0x80088F18u); }  /* 0x80088F1C: unsupported word 0xFFFFFE70 (op=63, fn=48) */

void g1_80088F6C(void) { psx_trap(0x80088F6Cu); }  /* 0x80088F7C: unsupported word 0x00280030 (op=0, fn=48) */

void g1_8008912C(void) {
    (void)(R[0] << 2);  /* 0x80089140 */
    (void)(R[0] << 2);  /* 0x80089148 */
    (void)(R[0] << 2);  /* 0x80089154 */
    (void)(R[0] << 2);  /* 0x80089158 */
    (void)(R[0] << 2);  /* 0x8008915C */
    (void)(R[0] << 2);  /* 0x80089168 */
    (void)(R[0] << 2);  /* 0x80089170 */
    (void)(R[0] << 2);  /* 0x80089174 */
    (void)(R[0] << 2);  /* 0x80089178 */
    (void)(R[0] << 2);  /* 0x80089180 */
    (void)(R[0] << 2);  /* 0x80089184 */
    (void)(R[0] << 2);  /* 0x80089188 */
    psx_next = 0x8008918Cu; return;  /* fallthrough */
}

void g1_8008918C(void) { psx_trap(0x8008918Cu); }  /* 0x8008919C: unsupported word 0x421039CE (op=16, fn=14) */

void g1_80089190(void) { psx_trap(0x80089190u); }  /* 0x8008919C: unsupported word 0x421039CE (op=16, fn=14) */

void g1_800891BC(void) { psx_trap(0x800891BCu); }  /* bad delay slot at 0x800891BC */

void g1_8008925C(void) { psx_trap(0x8008925Cu); }  /* 0x8008926C: unsupported word 0x000029CA (op=0, fn=10) */

void g1_800892F0(void) { psx_trap(0x800892F0u); }  /* branch into delay slot: ['0x800892f4'] */

void g1_8008933C(void) {
    psx_next = 0x80089374u; return;  /* fallthrough */
}

void g1_80089374(void) { psx_trap(0x80089374u); }  /* 0x8008938C: unsupported word 0x7FFF0000 (op=31, fn=0) */

void g1_80089390(void) { psx_trap(0x80089390u); }  /* 0x80089394: unsupported word 0xDD2B000F (op=55, fn=15) */

void g1_80089398(void) { psx_trap(0x80089398u); }  /* 0x80089398: unsupported word 0xD000000D (op=52, fn=13) */

void g1_800893AC(void) { psx_trap(0x800893ACu); }  /* 0x800893AC: unsupported word 0xDD00DDDD (op=55, fn=29) */

void g1_800893BC(void) { psx_trap(0x800893BCu); }  /* 0x800893BC: unsupported word 0xDDD0000D (op=55, fn=13) */

void g1_800893CC(void) { psx_trap(0x800893CCu); }  /* 0x800893CC: unsupported word 0xF00010FF (op=60, fn=63) */

void g1_800893E8(void) { psx_trap(0x800893E8u); }  /* 0x800893E8: unsupported word 0xDD02640F (op=55, fn=15) */

void g1_8008942C(void) { psx_trap(0x8008942Cu); }  /* branch into delay slot: ['0x80089518'] */

void g1_8008951C(void) { psx_trap(0x8008951Cu); }  /* 0x8008953C: unsupported word 0xDC3F002C (op=55, fn=44) */

void g1_80089534(void) { psx_trap(0x80089534u); }  /* 0x8008953C: unsupported word 0xDC3F002C (op=55, fn=44) */

void g1_80089540(void) { psx_trap(0x80089540u); }  /* 0x80089540: unsupported word 0x014F002D (op=0, fn=45) */

void g1_80089560(void) { psx_trap(0x80089560u); }  /* 0x80089560: unsupported word 0x47000F01 (op=17, fn=1) */

void g1_80089608(void) { psx_trap(0x80089608u); }  /* 0x8008960C: unsupported word 0xD000DD05 (op=52, fn=5) */

void g1_80089654(void) { psx_trap(0x80089654u); }  /* 0x80089658: unsupported word 0xD03DDD0F (op=52, fn=15) */

void g1_8008967C(void) { psx_trap(0x8008967Cu); }  /* 0x8008967C: unsupported word 0x000FF00F (op=0, fn=15) */

void g1_8008968C(void) { psx_trap(0x8008968Cu); }  /* 0x8008968C: unsupported word 0xF00F000F (op=60, fn=15) */

void g1_80089690(void) { psx_trap(0x80089690u); }  /* branch into delay slot: ['0x80089900'] */

void g1_8008969C(void) { psx_trap(0x8008969Cu); }  /* branch into delay slot: ['0x80089900'] */

void g1_800896C8(void) { psx_trap(0x800896C8u); }  /* branch into delay slot: ['0x80089900'] */

void g1_8008972C(void) { psx_trap(0x8008972Cu); }  /* branch into delay slot: ['0x80089900'] */

void g1_80089734(void) { psx_trap(0x80089734u); }  /* branch into delay slot: ['0x80089900'] */

void g1_8008976C(void) { psx_trap(0x8008976Cu); }  /* branch into delay slot: ['0x80089900'] */

void g1_800897B0(void) { psx_trap(0x800897B0u); }  /* branch into delay slot: ['0x80089900'] */

void g1_800897BC(void) { psx_trap(0x800897BCu); }  /* branch into delay slot: ['0x80089900'] */

void g1_80089894(void) { psx_trap(0x80089894u); }  /* branch into delay slot: ['0x80089900'] */

void g1_800898D4(void) { psx_trap(0x800898D4u); }  /* 0x800898D8: unsupported word 0x026C0F6E (op=0, fn=46) */

void g1_800898DC(void) { psx_trap(0x800898DCu); }  /* 0x800898DC: unsupported word 0x011E0215 (op=0, fn=21) */

void g1_80089900(void) { psx_trap(0x80089900u); }  /* 0x80089900: unsupported word 0xFF006D9D (op=63, fn=29) */

void g1_80089904(void) { psx_trap(0x80089904u); }  /* 0x8008990C: unsupported word 0x65DF0042 (op=25, fn=2) */

void g1_80089910(void) { psx_trap(0x80089910u); }  /* 0x80089910: unsupported word 0xF0006501 (op=60, fn=1) */

void g1_80089928(void) { psx_trap(0x80089928u); }  /* 0x80089928: unsupported word 0x56021A02 (op=21, fn=2) */

void g1_8008994C(void) { psx_trap(0x8008994Cu); }  /* branch into delay slot: ['0x80089f14'] */

void g1_8008996C(void) { psx_trap(0x8008996Cu); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089A08(void) { psx_trap(0x80089A08u); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089B28(void) { psx_trap(0x80089B28u); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089B34(void) { psx_trap(0x80089B34u); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089B38(void) { psx_trap(0x80089B38u); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089B44(void) { psx_trap(0x80089B44u); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089B5C(void) { psx_trap(0x80089B5Cu); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089B6C(void) { psx_trap(0x80089B6Cu); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089B74(void) { psx_trap(0x80089B74u); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089B78(void) { psx_trap(0x80089B78u); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089BA8(void) { psx_trap(0x80089BA8u); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089BAC(void) { psx_trap(0x80089BACu); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089BBC(void) { psx_trap(0x80089BBCu); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089C78(void) { psx_trap(0x80089C78u); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089CD8(void) { psx_trap(0x80089CD8u); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089D24(void) { psx_trap(0x80089D24u); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089D3C(void) { psx_trap(0x80089D3Cu); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089D50(void) { psx_trap(0x80089D50u); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089D90(void) { psx_trap(0x80089D90u); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089DDC(void) { psx_trap(0x80089DDCu); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089E1C(void) { psx_trap(0x80089E1Cu); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089E4C(void) { psx_trap(0x80089E4Cu); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089E9C(void) { psx_trap(0x80089E9Cu); }  /* branch into delay slot: ['0x80089f14'] */

void g1_80089FB0(void) { psx_trap(0x80089FB0u); }  /* 0x80089FB0: unsupported word 0x0002009F (op=0, fn=31) */

void g1_8008A03C(void) { psx_trap(0x8008A03Cu); }  /* 0x8008A048: unsupported word 0xFBBEF000 (op=62, fn=0) */

void g1_8008A048(void) { psx_trap(0x8008A048u); }  /* 0x8008A048: unsupported word 0xFBBEF000 (op=62, fn=0) */

void g1_8008A08C(void) { psx_trap(0x8008A08Cu); }  /* 0x8008A08C: unsupported word 0xF701548B (op=61, fn=11) */

void g1_8008A0A0(void) { psx_trap(0x8008A0A0u); }  /* 0x8008A0A4: unsupported word 0x016C842F (op=0, fn=47) */

void g1_8008A154(void) { psx_trap(0x8008A154u); }  /* 0x8008A15C: unsupported word 0x002704F7 (op=0, fn=55) */

void g1_8008A168(void) { psx_trap(0x8008A168u); }  /* 0x8008A168: unsupported word 0x007F8FFA (op=0, fn=58) */

void g1_8008A240(void) { psx_trap(0x8008A240u); }  /* bad delay slot at 0x8008A244 */

void g1_8008A260(void) { psx_trap(0x8008A260u); }  /* 0x8008A260: unsupported word 0xB3000803 (op=44, fn=3) */

void g1_8008A26C(void) { psx_trap(0x8008A26Cu); }  /* 0x8008A27C: unsupported word 0xCFFA016D (op=51, fn=45) */

void g1_8008A278(void) { psx_trap(0x8008A278u); }  /* 0x8008A27C: unsupported word 0xCFFA016D (op=51, fn=45) */

void g1_8008A290(void) { psx_trap(0x8008A290u); }  /* 0x8008A29C: unsupported word 0xD6072330 (op=53, fn=48) */

void g1_8008A2C4(void) { psx_trap(0x8008A2C4u); }  /* 0x8008A2C4: unsupported word 0xF9015DF0 (op=62, fn=48) */

void g1_8008A2D0(void) { psx_trap(0x8008A2D0u); }  /* branch into delay slot: ['0x8008a418'] */

void g1_8008A2E4(void) { psx_trap(0x8008A2E4u); }  /* branch into delay slot: ['0x8008a418'] */

void g1_8008A2E8(void) { psx_trap(0x8008A2E8u); }  /* branch into delay slot: ['0x8008a418'] */

void g1_8008A31C(void) { psx_trap(0x8008A31Cu); }  /* branch into delay slot: ['0x8008a418'] */

void g1_8008A374(void) { psx_trap(0x8008A374u); }  /* branch into delay slot: ['0x8008a418'] */

void g1_8008A3C0(void) { psx_trap(0x8008A3C0u); }  /* branch into delay slot: ['0x8008a418'] */

void g1_8008A3C8(void) { psx_trap(0x8008A3C8u); }  /* branch into delay slot: ['0x8008a418'] */

void g1_8008A3F4(void) { psx_trap(0x8008A3F4u); }  /* branch into delay slot: ['0x8008a418'] */

void g1_8008A42C(void) { psx_trap(0x8008A42Cu); }  /* branch into delay slot: ['0x8008a4e4'] */

void g1_8008A454(void) { psx_trap(0x8008A454u); }  /* branch into delay slot: ['0x8008a4e4'] */

void g1_8008A4E8(void) { psx_trap(0x8008A4E8u); }  /* 0x8008A4EC: unsupported word 0x02773333 (op=0, fn=51) */

void g1_8008A54C(void) { psx_trap(0x8008A54Cu); }  /* 0x8008A54C: unsupported word 0xE0000007 (op=56, fn=7) */

void g1_8008A590(void) { psx_trap(0x8008A590u); }  /* 0x8008A594: unsupported word 0x030C65F0 (op=0, fn=48) */

void g1_8008A5D4(void) { psx_trap(0x8008A5D4u); }  /* 0x8008A5D4: unsupported word 0x0007FFFF (op=0, fn=63) */

void g1_8008A640(void) { psx_trap(0x8008A640u); }  /* 0x8008A640: unsupported word 0x503FFF00 (op=20, fn=0) */

void g1_8008A694(void) { psx_trap(0x8008A694u); }  /* 0x8008A694: unsupported word 0x07F30C00 (op=1, fn=0) */

void g1_8008A69C(void) { psx_trap(0x8008A69Cu); }  /* 0x8008A69C: unsupported word 0x003F09FF (op=0, fn=63) */

void g1_8008A6BC(void) { psx_trap(0x8008A6BCu); }  /* 0x8008A6C8: unsupported word 0x6FF33FD1 (op=27, fn=17) */

void g1_8008A6DC(void) { psx_trap(0x8008A6DCu); }  /* 0x8008A6E0: unsupported word 0xF0005F90 (op=60, fn=16) */

void g1_8008A6F4(void) { psx_trap(0x8008A6F4u); }  /* 0x8008A6FC: unsupported word 0xF2F70E90 (op=60, fn=16) */

void g1_8008A710(void) { psx_trap(0x8008A710u); }  /* 0x8008A714: unsupported word 0xBFD0036F (op=47, fn=47) */

void g1_8008A7AC(void) { psx_trap(0x8008A7ACu); }  /* branch into delay slot: ['0x8008a90c', '0x8008a9c4'] */

void g1_8008A7F8(void) { psx_trap(0x8008A7F8u); }  /* branch into delay slot: ['0x8008a90c', '0x8008a9c4'] */

void g1_8008A89C(void) { psx_trap(0x8008A89Cu); }  /* branch into delay slot: ['0x8008a90c', '0x8008a9c4'] */

void g1_8008A910(void) { psx_trap(0x8008A910u); }  /* branch into delay slot: ['0x8008a9c4'] */

void g1_8008A914(void) { psx_trap(0x8008A914u); }  /* branch into delay slot: ['0x8008a9c4'] */
