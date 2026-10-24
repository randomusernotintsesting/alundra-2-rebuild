#include "game02_decls.h"

void g2_800A14A8(void) { psx_trap(0x800A14A8u); }  /* 0x800A14B0: unsupported word 0x4E514E47 (op=19, fn=7) */

void g2_800A1504(void) { psx_trap(0x800A1504u); }  /* 0x800A1504: unsupported word 0x51545458 (op=20, fn=24) */

void g2_800A158C(void) { psx_trap(0x800A158Cu); }  /* 0x800A158C: unsupported word 0x45B0414C (op=17, fn=12) */

void g2_800A159C(void) { psx_trap(0x800A159Cu); }  /* 0x800A159C: unsupported word 0x47084C54 (op=17, fn=20) */

void g2_800A15C0(void) { psx_trap(0x800A15C0u); }  /* 0x800A15C0: unsupported word 0x62584735 (op=24, fn=53) */

void g2_800A16B4(void) { psx_trap(0x800A16B4u); }  /* 0x800A16B4: unsupported word 0x706A5C43 (op=28, fn=3) */

void g2_800A1700(void) { psx_trap(0x800A1700u); }  /* bad delay slot at 0x800A1700 */

void g2_800A1758(void) { psx_trap(0x800A1758u); }  /* 0x800A1758: unsupported word 0x77787000 (op=29, fn=0) */

void g2_800A185C(void) { psx_trap(0x800A185Cu); }  /* 0x800A1868: unsupported word 0x777F7232 (op=29, fn=50) */

void g2_800A1884(void) { psx_trap(0x800A1884u); }  /* 0x800A1888: unsupported word 0x00161E38 (op=0, fn=56) */

void g2_800A18BC(void) { psx_trap(0x800A18BCu); }  /* 0x800A18C4: unsupported word 0xF4FF0482 (op=61, fn=2) */

void g2_800A191C(void) { psx_trap(0x800A191Cu); }  /* 0x800A1920: unsupported word 0x6C003B3B (op=27, fn=59) */

void g2_800A1970(void) {
    R[16] = R[17] + 16896;  /* 0x800A1970 */
    psx_next = 0x800A1974u; return;  /* fallthrough */
}

void g2_800A1974(void) { psx_trap(0x800A1974u); }  /* 0x800A1974: unsupported word 0xFFBE0125 (op=63, fn=37) */

void g2_800A197C(void) { psx_trap(0x800A197Cu); }  /* 0x800A1980: unsupported word 0x5C00A75E (op=23, fn=30) */

void g2_800A1AB8(void) { psx_trap(0x800A1AB8u); }  /* 0x800A1AC0: unsupported word 0x4040403E (op=16, fn=62) */

void g2_800A1EB0(void) { psx_trap(0x800A1EB0u); }  /* 0x800A1EB4: unsupported word 0x43002233 (op=16, fn=51) */

void g2_800A1EF0(void) { psx_trap(0x800A1EF0u); }  /* 0x800A1EF0: unsupported word 0xE7B31006 (op=57, fn=6) */

void g2_800A1F90(void) { psx_trap(0x800A1F90u); }  /* 0x800A1F94: unsupported word 0x4044B91E (op=16, fn=30) */

void g2_800A2038(void) { psx_trap(0x800A2038u); }  /* 0x800A203C: unsupported word 0x4E474040 (op=19, fn=0) */

void g2_800A20E0(void) { psx_trap(0x800A20E0u); }  /* 0x800A20E0: unsupported word 0x57786B20 (op=21, fn=32) */

void g2_800A2100(void) { psx_trap(0x800A2100u); }  /* 0x800A2104: unsupported word 0xC0698659 (op=48, fn=25) */

void g2_800A22D0(void) { psx_trap(0x800A22D0u); }  /* 0x800A22D4: unsupported word 0xFF00BE7F (op=63, fn=63) */

void g2_800A230C(void) { psx_trap(0x800A230Cu); }  /* 0x800A230C: unsupported word 0x5C7A0078 (op=23, fn=56) */

void g2_800A24A0(void) { psx_trap(0x800A24A0u); }  /* 0x800A24A0: unsupported word 0xBEC1C900 (op=47, fn=0) */

void g2_800A259C(void) { psx_trap(0x800A259Cu); }  /* 0x800A259C: unsupported word 0x7E817F7F (op=31, fn=63) */

void g2_800A2718(void) { psx_trap(0x800A2718u); }  /* 0x800A2718: unsupported word 0xC1FF6B6B (op=48, fn=43) */

void g2_800A2760(void) { psx_trap(0x800A2760u); }  /* 0x800A2768: unsupported word 0xD5F9F800 (op=53, fn=0) */

void g2_800A28E4(void) { psx_trap(0x800A28E4u); }  /* 0x800A28E8: unsupported word 0x54357C04 (op=21, fn=4) */

void g2_800A2918(void) { psx_trap(0x800A2918u); }  /* 0x800A2918: unsupported word 0xD9C800BC (op=54, fn=60) */

void g2_800A2934(void) { psx_trap(0x800A2934u); }  /* 0x800A2944: unsupported word 0xD8EE006A (op=54, fn=42) */

void g2_800A2C98(void) { psx_trap(0x800A2C98u); }  /* 0x800A2CA4: unsupported word 0x433C003B (op=16, fn=59) */

void g2_800A2CC0(void) { psx_trap(0x800A2CC0u); }  /* 0x800A2CC0: unsupported word 0x7C910054 (op=31, fn=20) */

void g2_800A2DB4(void) { psx_trap(0x800A2DB4u); }  /* 0x800A2DB8: unsupported word 0x003B0041 (op=0, fn=1) */

void g2_800A2DD8(void) { psx_trap(0x800A2DD8u); }  /* 0x800A2DE0: unsupported word 0x0089817E (op=0, fn=62) */

void g2_800A2E24(void) { psx_trap(0x800A2E24u); }  /* 0x800A2E2C: unsupported word 0x00A78185 (op=0, fn=5) */

void g2_800A2E60(void) { psx_trap(0x800A2E60u); }  /* 0x800A2E60: unsupported word 0x6D6B7287 (op=27, fn=7) */

void g2_800A2EA8(void) { psx_trap(0x800A2EA8u); }  /* 0x800A2EC4: unsupported word 0x7F7E8B8A (op=31, fn=10) */

void g2_800A2F00(void) { psx_trap(0x800A2F00u); }  /* 0x800A2F08: unsupported word 0x74667684 (op=29, fn=4) */

void g2_800A2F24(void) { psx_trap(0x800A2F24u); }  /* 0x800A2F24: unsupported word 0x548D9193 (op=21, fn=19) */

void g2_800A2F3C(void) { psx_trap(0x800A2F3Cu); }  /* 0x800A2F40: unsupported word 0x47918484 (op=17, fn=4) */

void g2_800A2F90(void) { psx_trap(0x800A2F90u); }  /* 0x800A2F90: unsupported word 0x60008A8B (op=24, fn=11) */

void g2_800A2FAC(void) { psx_trap(0x800A2FACu); }  /* 0x800A2FB4: unsupported word 0x63007F87 (op=24, fn=7) */

void g2_800A2FD0(void) { psx_trap(0x800A2FD0u); }  /* 0x800A2FD4: unsupported word 0x5800B67F (op=22, fn=63) */

void g2_800A3028(void) { psx_trap(0x800A3028u); }  /* 0x800A3034: unsupported word 0x4C85583A (op=19, fn=58) */

void g2_800A3034(void) { psx_trap(0x800A3034u); }  /* 0x800A3034: unsupported word 0x4C85583A (op=19, fn=58) */

void g2_800A3058(void) { psx_trap(0x800A3058u); }  /* 0x800A305C: unsupported word 0x47B6818B (op=17, fn=11) */

void g2_800A3060(void) { psx_trap(0x800A3060u); }  /* 0x800A3084: unsupported word 0x60109A35 (op=24, fn=53) */

void g2_800A3078(void) { psx_trap(0x800A3078u); }  /* 0x800A3084: unsupported word 0x60109A35 (op=24, fn=53) */

void g2_800A30E4(void) { psx_trap(0x800A30E4u); }  /* 0x800A30E4: unsupported word 0x00000001 (op=0, fn=1) */

void g2_800A30F0(void) {
    { uint32_t _c = (R[1] == R[1]); R[3] = R[4] + 4194; if (_c) { psx_next = 0x800830F4u; return; } }  /* 0x800A30F0 b extern */
    R[3] = R[4] + 9347;  /* 0x800A30F8 */
    R[3] = ((int32_t)R[5] < 9380);  /* 0x800A30FC */
    R[4] = ((int32_t)R[5] < 9380);  /* 0x800A3100 */
    R[4] = ((int32_t)R[5] < 11428);  /* 0x800A3104 */
    R[4] = ((int32_t)R[5] < 12452);  /* 0x800A3108 */
    R[5] = ((int32_t)R[6] < 10437);  /* 0x800A310C */
    R[5] = (R[6] < (uint32_t)12484u);  /* 0x800A3110 */
    R[5] = (R[6] < (uint32_t)11461u);  /* 0x800A3114 */
    psx_next = 0x800A3118u; return;  /* fallthrough */
}

void g2_800A3118(void) { psx_trap(0x800A3118u); }  /* 0x800A3148: unsupported word 0x40E52CCA (op=16, fn=10) */

void g2_800A32E4(void) { psx_trap(0x800A32E4u); }  /* 0x800A32E4: unsupported word 0x7FFF7FFF (op=31, fn=63) */

void g2_800A32F0(void) { psx_trap(0x800A32F0u); }  /* 0x800A32F0: unsupported word 0x41410000 (op=16, fn=0) */

void g2_800A3370(void) { psx_trap(0x800A3370u); }  /* 0x800A3378: unsupported word 0x5C252300 (op=23, fn=0) */

void g2_800A3390(void) { psx_trap(0x800A3390u); }  /* 0x800A3394: unsupported word 0x7F87936A (op=31, fn=42) */

void g2_800A33A0(void) { psx_trap(0x800A33A0u); }  /* 0x800A33B4: unsupported word 0x00131B34 (op=0, fn=52) */

void g2_800A33C0(void) { psx_trap(0x800A33C0u); }  /* 0x800A33C4: unsupported word 0x4141413B (op=16, fn=59) */

void g2_800A3438(void) { psx_trap(0x800A3438u); }  /* 0x800A3438: unsupported word 0x637F7076 (op=24, fn=54) */

void g2_800A34A8(void) { psx_trap(0x800A34A8u); }  /* bad delay slot at 0x800A34A8 */

void g2_800A34C8(void) { psx_trap(0x800A34C8u); }  /* 0x800A34C8: unsupported word 0x767A8B84 (op=29, fn=4) */

void g2_800A34F4(void) { psx_trap(0x800A34F4u); }  /* 0x800A34F4: unsupported word 0x00A0E07F (op=0, fn=63) */

void g2_800A35A8(void) { psx_trap(0x800A35A8u); }  /* 0x800A35B0: unsupported word 0x004D0F0E (op=0, fn=14) */

void g2_800A3638(void) { psx_trap(0x800A3638u); }  /* 0x800A3638: unsupported word 0x02628572 (op=0, fn=50) */

void g2_800A36A8(void) { psx_trap(0x800A36A8u); }  /* 0x800A36A8: unsupported word 0x63959000 (op=24, fn=0) */

void g2_800A36B8(void) { psx_trap(0x800A36B8u); }  /* 0x800A36B8: unsupported word 0x7E107A93 (op=31, fn=19) */

void g2_800A3708(void) { psx_trap(0x800A3708u); }  /* 0x800A370C: unsupported word 0x7F8B431D (op=31, fn=29) */

void g2_800A37BC(void) { psx_trap(0x800A37BCu); }  /* 0x800A37BC: unsupported word 0x605C6300 (op=24, fn=0) */

void g2_800A39B8(void) { psx_trap(0x800A39B8u); }  /* 0x800A39B8: unsupported word 0x767C7A00 (op=29, fn=0) */

void g2_800A39E4(void) { psx_trap(0x800A39E4u); }  /* 0x800A39E4: unsupported word 0x7F7F7F7E (op=31, fn=62) */

void g2_800A3A60(void) { psx_trap(0x800A3A60u); }  /* 0x800A3A60: unsupported word 0x00720072 (op=0, fn=50) */

void g2_800A3AF0(void) { psx_trap(0x800A3AF0u); }  /* branch into delay slot: ['0x800a3cdc'] */

void g2_800A3AF8(void) { psx_trap(0x800A3AF8u); }  /* branch into delay slot: ['0x800a3cdc'] */

void g2_800A3B74(void) { psx_trap(0x800A3B74u); }  /* branch into delay slot: ['0x800a3cdc'] */

void g2_800A3B78(void) { psx_trap(0x800A3B78u); }  /* branch into delay slot: ['0x800a3cdc'] */

void g2_800A3BC8(void) { psx_trap(0x800A3BC8u); }  /* branch into delay slot: ['0x800a3cdc'] */

void g2_800A3CE0(void) { psx_trap(0x800A3CE0u); }  /* 0x800A3CE8: unsupported word 0x7A828201 (op=30, fn=1) */

void g2_800A3D5C(void) { psx_trap(0x800A3D5Cu); }  /* 0x800A3D5C: unsupported word 0x075A817A (op=1, fn=58) */

void g2_800A3DC8(void) { psx_trap(0x800A3DC8u); }  /* 0x800A3DC8: unsupported word 0x7F045766 (op=31, fn=38) */

void g2_800A3DF0(void) { psx_trap(0x800A3DF0u); }  /* 0x800A3DF0: unsupported word 0x54547487 (op=21, fn=7) */

void g2_800A3E10(void) { psx_trap(0x800A3E10u); }  /* 0x800A3E14: unsupported word 0x4384877E (op=16, fn=62) */

void g2_800A3E14(void) { psx_trap(0x800A3E14u); }  /* 0x800A3E14: unsupported word 0x4384877E (op=16, fn=62) */

void g2_800A3ED0(void) { psx_trap(0x800A3ED0u); }  /* bad delay slot at 0x800A3ED0 */

void g2_800A3ED8(void) { psx_trap(0x800A3ED8u); }  /* 0x800A3ED8: unsupported word 0x7F8D3900 (op=31, fn=0) */

void g2_800A3F88(void) { psx_trap(0x800A3F88u); }  /* 0x800A3F8C: unsupported word 0x63602E13 (op=24, fn=19) */

void g2_800A4170(void) { psx_trap(0x800A4170u); }  /* 0x800A417C: unsupported word 0xBF2D0408 (op=47, fn=8) */

void g2_800A427C(void) { psx_trap(0x800A427Cu); }  /* 0x800A4284: unsupported word 0x5E6A7000 (op=23, fn=0) */

void g2_800A42B0(void) { psx_trap(0x800A42B0u); }  /* 0x800A42BC: unsupported word 0x706B7700 (op=28, fn=0) */

void g2_800A42D8(void) { psx_trap(0x800A42D8u); }  /* 0x800A42D8: unsupported word 0x74030306 (op=29, fn=6) */

void g2_800A4334(void) { psx_trap(0x800A4334u); }  /* 0x800A433C: unsupported word 0x050B8AA4 (op=1, fn=36) */

void g2_800A4358(void) { psx_trap(0x800A4358u); }  /* 0x800A4364: unsupported word 0x9D005A85 (op=39, fn=5) */

void g2_800A43E0(void) { psx_trap(0x800A43E0u); }  /* 0x800A43E0: unsupported word 0x6B0F1220 (op=26, fn=32) */

void g2_800A44D8(void) {
    psx_div((int32_t)R[3], (int32_t)R[10]);  /* 0x800A44D8 */
    psx_break(792612);  /* 0x800A44DC */
    psx_next = 0x800A44E0u; return;  /* fallthrough */
}

void g2_800A44E0(void) { psx_trap(0x800A44E0u); }  /* 0x800A44E0: unsupported word 0x009D9A0B (op=0, fn=11) */

void g2_800A4500(void) { psx_trap(0x800A4500u); }  /* 0x800A4504: unsupported word 0x00930E0F (op=0, fn=15) */

void g2_800A450C(void) { psx_trap(0x800A450Cu); }  /* 0x800A4510: unsupported word 0x7684007F (op=29, fn=63) */

void g2_800A4570(void) { psx_trap(0x800A4570u); }  /* 0x800A4570: unsupported word 0x589F0893 (op=22, fn=19) */

void g2_800A45B8(void) { psx_trap(0x800A45B8u); }  /* 0x800A45C0: unsupported word 0x7A7C013F (op=30, fn=63) */

void g2_800A4608(void) { psx_trap(0x800A4608u); }  /* 0x800A4608: unsupported word 0x00121216 (op=0, fn=22) */

void g2_800A4674(void) { psx_trap(0x800A4674u); }  /* 0x800A467C: unsupported word 0x03080B0F (op=0, fn=15) */

void g2_800A46F0(void) { psx_trap(0x800A46F0u); }  /* bad delay slot at 0x800A46F0 */

void g2_800A47F8(void) { psx_trap(0x800A47F8u); }  /* 0x800A47FC: unsupported word 0x78803B2D (op=30, fn=45) */

void g2_800A4800(void) { psx_trap(0x800A4800u); }  /* 0x800A4800: unsupported word 0x72856A08 (op=28, fn=8) */

void g2_800A4814(void) { psx_trap(0x800A4814u); }  /* 0x800A4828: unsupported word 0x666A7078 (op=25, fn=56) */

void g2_800A4884(void) { psx_trap(0x800A4884u); }  /* bad delay slot at 0x800A488C */

void g2_800A48C4(void) { psx_trap(0x800A48C4u); }  /* 0x800A48D0: unsupported word 0x70760244 (op=28, fn=4) */

void g2_800A4900(void) { psx_trap(0x800A4900u); }  /* bad delay slot at 0x800A4900 */

void g2_800A4914(void) { psx_trap(0x800A4914u); }  /* 0x800A4914: unsupported word 0x76603000 (op=29, fn=0) */

void g2_800A4918(void) { psx_trap(0x800A4918u); }  /* 0x800A4918: unsupported word 0x76727070 (op=29, fn=48) */

void g2_800A497C(void) { psx_trap(0x800A497Cu); }  /* 0x800A4988: unsupported word 0x6413061C (op=25, fn=28) */

void g2_800A499C(void) { psx_trap(0x800A499Cu); }  /* 0x800A499C: unsupported word 0x6A6A6B72 (op=26, fn=50) */

void g2_800A4A14(void) { psx_trap(0x800A4A14u); }  /* 0x800A4A14: unsupported word 0x41156A01 (op=16, fn=1) */

void g2_800A4A18(void) { psx_trap(0x800A4A18u); }  /* 0x800A4A18: unsupported word 0x70766A30 (op=28, fn=48) */

void g2_800A4A60(void) { psx_trap(0x800A4A60u); }  /* 0x800A4A60: unsupported word 0x018A008A (op=0, fn=10) */

void g2_800A4AF8(void) { psx_trap(0x800A4AF8u); }  /* 0x800A4B00: unsupported word 0x41244798 (op=16, fn=24) */

void g2_800A4B08(void) { psx_trap(0x800A4B08u); }  /* 0x800A4B0C: unsupported word 0x60606363 (op=24, fn=35) */

void g2_800A4B20(void) { psx_trap(0x800A4B20u); }  /* 0x800A4B30: unsupported word 0x03538001 (op=0, fn=1) */

void g2_800A4B44(void) { psx_trap(0x800A4B44u); }  /* bad delay slot at 0x800A4B48 */

void g2_800A4B70(void) { psx_trap(0x800A4B70u); }  /* 0x800A4B70: unsupported word 0x41003329 (op=16, fn=41) */

void g2_800A4B94(void) { psx_trap(0x800A4B94u); }  /* 0x800A4B9C: unsupported word 0x6B626040 (op=26, fn=0) */

void g2_800A4BD0(void) { psx_trap(0x800A4BD0u); }  /* 0x800A4BE8: unsupported word 0x005B1F85 (op=0, fn=5) */

void g2_800A4C00(void) { psx_trap(0x800A4C00u); }  /* 0x800A4C00: unsupported word 0x005B070B (op=0, fn=11) */

void g2_800A4C2C(void) { psx_trap(0x800A4C2Cu); }  /* 0x800A4C3C: unsupported word 0x5C828A36 (op=23, fn=54) */

void g2_800A4C40(void) { psx_trap(0x800A4C40u); }  /* 0x800A4C50: unsupported word 0x40619A84 (op=16, fn=4) */

void g2_800A4C54(void) { psx_trap(0x800A4C54u); }  /* 0x800A4C58: unsupported word 0x72726D2F (op=28, fn=47) */

void g2_800A4DE0(void) { psx_trap(0x800A4DE0u); }  /* 0x800A4DE8: unsupported word 0x475C5E54 (op=17, fn=20) */

void g2_800A4E0C(void) { psx_trap(0x800A4E0Cu); }  /* 0x800A4E0C: unsupported word 0x037F382F (op=0, fn=47) */

void g2_800A4EB0(void) { psx_trap(0x800A4EB0u); }  /* 0x800A4EB0: unsupported word 0x70721014 (op=28, fn=20) */

void g2_800A4F00(void) { psx_trap(0x800A4F00u); }  /* 0x800A4F04: unsupported word 0x5C512E15 (op=23, fn=21) */

void g2_800A4F68(void) { psx_trap(0x800A4F68u); }  /* 0x800A4F70: unsupported word 0x6B605439 (op=26, fn=57) */

void g2_800A5138(void) { psx_trap(0x800A5138u); }  /* 0x800A513C: unsupported word 0x06AC7203 (op=1, fn=3) */

void g2_800A51A0(void) { psx_trap(0x800A51A0u); }  /* 0x800A51A0: unsupported word 0x66901D6C (op=25, fn=44) */

void g2_800A5208(void) { psx_trap(0x800A5208u); }  /* 0x800A5208: unsupported word 0x0429FFFF (op=1, fn=63) */

void g2_800A525C(void) { psx_trap(0x800A525Cu); }  /* 0x800A525C: unsupported word 0x00C3AAFB (op=0, fn=59) */

void g2_800A5270(void) { psx_trap(0x800A5270u); }  /* 0x800A5270: unsupported word 0xFBCAB214 (op=62, fn=20) */

void g2_800A5348(void) { psx_trap(0x800A5348u); }  /* 0x800A534C: unsupported word 0xFF18A601 (op=63, fn=1) */

void g2_800A5358(void) { psx_trap(0x800A5358u); }  /* bad delay slot at 0x800A5358 */

void g2_800A54AC(void) { psx_trap(0x800A54ACu); }  /* 0x800A54AC: unsupported word 0x4104B4FF (op=16, fn=63) */

void g2_800A5548(void) { psx_trap(0x800A5548u); }  /* 0x800A5548: unsupported word 0x5438642F (op=21, fn=47) */

void g2_800A558C(void) { psx_trap(0x800A558Cu); }  /* 0x800A5594: unsupported word 0xD6F39292 (op=53, fn=18) */

void g2_800A5688(void) { psx_trap(0x800A5688u); }  /* 0x800A5688: unsupported word 0x5327726B (op=20, fn=43) */

void g2_800A5754(void) { psx_trap(0x800A5754u); }  /* 0x800A5754: unsupported word 0x042E0212 (op=1, fn=18) */

void g2_800A57C0(void) { psx_trap(0x800A57C0u); }  /* 0x800A57C0: unsupported word 0x0100031E (op=0, fn=30) */

void g2_800A5834(void) { psx_trap(0x800A5834u); }  /* 0x800A5838: unsupported word 0x06397600 (op=1, fn=0) */

void g2_800A5860(void) { psx_trap(0x800A5860u); }  /* 0x800A5864: unsupported word 0x4197FFAE (op=16, fn=46) */

void g2_800A592C(void) { psx_trap(0x800A592Cu); }  /* 0x800A592C: unsupported word 0x76D56B14 (op=29, fn=20) */

void g2_800A5964(void) { psx_trap(0x800A5964u); }  /* 0x800A5964: unsupported word 0xFFCA0700 (op=63, fn=0) */

void g2_800A59D4(void) { psx_trap(0x800A59D4u); }  /* 0x800A59D4: unsupported word 0xF10206CE (op=60, fn=14) */

void g2_800A5A6C(void) { psx_trap(0x800A5A6Cu); }  /* 0x800A5A6C: unsupported word 0x5572106B (op=21, fn=43) */

void g2_800A5AAC(void) { psx_trap(0x800A5AACu); }  /* 0x800A5AAC: unsupported word 0x7A3A3C3B (op=30, fn=59) */
