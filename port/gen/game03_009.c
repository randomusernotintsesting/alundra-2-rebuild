#include "game03_decls.h"

void g3_8008F400(void) { psx_trap(0x8008F400u); }  /* bad delay slot at 0x8008F400 */

void g3_8008F404(void) { psx_trap(0x8008F404u); }  /* bad delay slot at 0x8008F404 */

void g3_8008F408(void) { psx_trap(0x8008F408u); }  /* bad delay slot at 0x8008F410 */

void g3_8008F40C(void) { psx_trap(0x8008F40Cu); }  /* bad delay slot at 0x8008F410 */

void g3_8008F410(void) { psx_trap(0x8008F410u); }  /* bad delay slot at 0x8008F410 */

void g3_8008F418(void) { psx_trap(0x8008F418u); }  /* bad delay slot at 0x8008F41C */

void g3_8008F41C(void) { psx_trap(0x8008F41Cu); }  /* bad delay slot at 0x8008F41C */

void g3_8008F424(void) { psx_trap(0x8008F424u); }  /* 0x8008F430: unsupported word 0x031D060F (op=0, fn=15) */

void g3_8008F428(void) { psx_trap(0x8008F428u); }  /* 0x8008F430: unsupported word 0x031D060F (op=0, fn=15) */

void g3_8008F430(void) { psx_trap(0x8008F430u); }  /* 0x8008F430: unsupported word 0x031D060F (op=0, fn=15) */

void g3_8008F43C(void) { psx_trap(0x8008F43Cu); }  /* 0x8008F43C: unsupported word 0x031D060F (op=0, fn=15) */

void g3_8008F448(void) { psx_trap(0x8008F448u); }  /* bad delay slot at 0x8008F44C */

void g3_8008F458(void) { psx_trap(0x8008F458u); }  /* bad delay slot at 0x8008F458 */

void g3_8008F464(void) { psx_trap(0x8008F464u); }  /* bad delay slot at 0x8008F464 */

void g3_8008F470(void) { psx_trap(0x8008F470u); }  /* 0x8008F474: unsupported word 0x04090409 (op=1, fn=9) */

void g3_8008F490(void) { psx_trap(0x8008F490u); }  /* 0x8008F490: unsupported word 0x0404000C (op=1, fn=12) */

void g3_8008F4A4(void) { psx_trap(0x8008F4A4u); }  /* bad delay slot at 0x8008F4A4 */

void g3_8008F504(void) { psx_trap(0x8008F504u); }  /* 0x8008F504: unsupported word 0x050A0301 (op=1, fn=1) */

void g3_8008F548(void) { psx_trap(0x8008F548u); }  /* 0x8008F554: unsupported word 0x060A000A (op=1, fn=10) */

void g3_8008F570(void) { psx_trap(0x8008F570u); }  /* bad delay slot at 0x8008F570 */

void g3_8008F594(void) { psx_trap(0x8008F594u); }  /* bad delay slot at 0x8008F598 */

void g3_8008F598(void) { psx_trap(0x8008F598u); }  /* bad delay slot at 0x8008F598 */

void g3_8008F5A0(void) { psx_trap(0x8008F5A0u); }  /* 0x8008F5A4: unsupported word 0x040D0F03 (op=1, fn=3) */

void g3_8008F5B8(void) { psx_trap(0x8008F5B8u); }  /* bad delay slot at 0x8008F5C0 */

void g3_8008F5BC(void) { psx_trap(0x8008F5BCu); }  /* bad delay slot at 0x8008F5C0 */

void g3_8008F5C8(void) {
    { uint32_t _c = ((int32_t)R[8] > 0); R[1] = (uint32_t)((int32_t)R[13] >> 28); if (_c) { psx_next = 0x800929D8u; return; } }  /* 0x8008F5C8 b extern */
    psx_next = 0x8008F5D0u; return;  /* fallthrough */
}

void g3_8008F5D0(void) { psx_trap(0x8008F5D0u); }  /* 0x8008F5D4: unsupported word 0x020D030A (op=0, fn=10) */

void g3_8008F5E0(void) { psx_trap(0x8008F5E0u); }  /* bad delay slot at 0x8008F5E8 */

void g3_8008F5E4(void) { psx_trap(0x8008F5E4u); }  /* bad delay slot at 0x8008F5E8 */

void g3_8008F5E8(void) { psx_trap(0x8008F5E8u); }  /* bad delay slot at 0x8008F5E8 */

void g3_8008F5F0(void) { psx_trap(0x8008F5F0u); }  /* 0x8008F5F0: unsupported word 0x7D020D03 (op=31, fn=3) */

void g3_8008F600(void) { psx_trap(0x8008F600u); }  /* bad delay slot at 0x8008F604 */

void g3_8008F60C(void) { psx_trap(0x8008F60Cu); }  /* bad delay slot at 0x8008F60C */

void g3_8008F610(void) { psx_trap(0x8008F610u); }  /* bad delay slot at 0x8008F610 */

void g3_8008F614(void) { psx_trap(0x8008F614u); }  /* 0x8008F618: unsupported word 0x031D0905 (op=0, fn=5) */

void g3_8008F628(void) { psx_trap(0x8008F628u); }  /* 0x8008F628: unsupported word 0x0303031D (op=0, fn=29) */

void g3_8008F634(void) { psx_trap(0x8008F634u); }  /* 0x8008F640: unsupported word 0x031D0905 (op=0, fn=5) */

void g3_8008F63C(void) { psx_trap(0x8008F63Cu); }  /* 0x8008F640: unsupported word 0x031D0905 (op=0, fn=5) */

void g3_8008F650(void) { psx_trap(0x8008F650u); }  /* 0x8008F650: unsupported word 0x0303031D (op=0, fn=29) */

void g3_8008F65C(void) { psx_trap(0x8008F65Cu); }  /* bad delay slot at 0x8008F670 */

void g3_8008F664(void) { psx_trap(0x8008F664u); }  /* bad delay slot at 0x8008F670 */

void g3_8008F670(void) { psx_trap(0x8008F670u); }  /* bad delay slot at 0x8008F670 */

void g3_8008F680(void) { psx_trap(0x8008F680u); }  /* 0x8008F680: unsupported word 0x051C0F40 (op=1, fn=0) */

void g3_8008F694(void) { psx_trap(0x8008F694u); }  /* 0x8008F698: unsupported word 0x000F051C (op=0, fn=28) */

void g3_8008F69C(void) { psx_trap(0x8008F69Cu); }  /* 0x8008F69C: unsupported word 0x0208030F (op=0, fn=15) */

void g3_8008F6AC(void) { psx_trap(0x8008F6ACu); }  /* 0x8008F6AC: unsupported word 0x051C0F05 (op=1, fn=5) */

void g3_8008F6B8(void) { psx_trap(0x8008F6B8u); }  /* 0x8008F6C0: unsupported word 0x051C0A01 (op=1, fn=1) */

void g3_8008F6C0(void) { psx_trap(0x8008F6C0u); }  /* 0x8008F6C0: unsupported word 0x051C0A01 (op=1, fn=1) */

void g3_8008F714(void) {
    { R[31] = 0x8008F71Cu; psx_divu(R[0], R[2]); psx_next = 0x8C080000u; return; }  /* 0x8008F714 jal */
    { R[31] = 0x8008F724u; psx_divu(R[0], R[2]); psx_next = 0x8C08A400u; return; }  /* 0x8008F71C jal */
    { uint32_t _c = ((int32_t)R[24] <= 0); R[9] = (uint32_t)((int32_t)R[2] >> (R[0] & 31)); if (_c) { psx_next = 0x8008FF28u; return; } }  /* 0x8008F724 b extern */
    { uint32_t _c = ((int32_t)R[24] <= 0); (void)((uint32_t)((int32_t)R[0] >> (R[0] & 31))); if (_c) { psx_next = 0x8008FF30u; return; } }  /* 0x8008F72C b extern */
    psx_next = 0x8008F734u; return;  /* fallthrough */
}

void g3_8008F71C(void) {
    { R[31] = 0x8008F724u; psx_divu(R[0], R[2]); psx_next = 0x8C08A400u; return; }  /* 0x8008F71C jal */
    { uint32_t _c = ((int32_t)R[24] <= 0); R[9] = (uint32_t)((int32_t)R[2] >> (R[0] & 31)); if (_c) { psx_next = 0x8008FF28u; return; } }  /* 0x8008F724 b extern */
    { uint32_t _c = ((int32_t)R[24] <= 0); (void)((uint32_t)((int32_t)R[0] >> (R[0] & 31))); if (_c) { psx_next = 0x8008FF30u; return; } }  /* 0x8008F72C b extern */
    psx_next = 0x8008F734u; return;  /* fallthrough */
}

void g3_8008F724(void) {
    { uint32_t _c = ((int32_t)R[24] <= 0); R[9] = (uint32_t)((int32_t)R[2] >> (R[0] & 31)); if (_c) { psx_next = 0x8008FF28u; return; } }  /* 0x8008F724 b extern */
    { uint32_t _c = ((int32_t)R[24] <= 0); (void)((uint32_t)((int32_t)R[0] >> (R[0] & 31))); if (_c) { psx_next = 0x8008FF30u; return; } }  /* 0x8008F72C b extern */
    psx_next = 0x8008F734u; return;  /* fallthrough */
}

void g3_8008F730(void) { psx_trap(0x8008F730u); }  /* 0x8008F7C8: unsupported word 0x02020201 (op=0, fn=1) */

void g3_8008F734(void) { psx_trap(0x8008F734u); }  /* 0x8008F7C8: unsupported word 0x02020201 (op=0, fn=1) */

void g3_8008F7D0(void) { psx_trap(0x8008F7D0u); }  /* bad delay slot at 0x8008F7D0 */

void g3_8008F7D8(void) { psx_trap(0x8008F7D8u); }  /* 0x8008F7D8: unsupported word 0x000E0E0E (op=0, fn=14) */

void g3_8008F7DC(void) { psx_trap(0x8008F7DCu); }  /* bad delay slot at 0x8008F7DC */

void g3_8008F7E4(void) { psx_trap(0x8008F7E4u); }  /* bad delay slot at 0x8008F7E4 */

void g3_8008F7E8(void) { psx_trap(0x8008F7E8u); }  /* bad delay slot at 0x8008F7E8 */

void g3_8008F7EC(void) { psx_trap(0x8008F7ECu); }  /* bad delay slot at 0x8008F7EC */

void g3_8008F7F0(void) { psx_trap(0x8008F7F0u); }  /* bad delay slot at 0x8008F7F0 */

void g3_8008F7F4(void) { psx_trap(0x8008F7F4u); }  /* bad delay slot at 0x8008F7F4 */

void g3_8008F7F8(void) { psx_trap(0x8008F7F8u); }  /* 0x8008F7FC: unsupported word 0x000E0E0E (op=0, fn=14) */

void g3_8008F7FC(void) { psx_trap(0x8008F7FCu); }  /* 0x8008F7FC: unsupported word 0x000E0E0E (op=0, fn=14) */

void g3_8008F800(void) { psx_trap(0x8008F800u); }  /* bad delay slot at 0x8008F800 */

void g3_8008F808(void) { psx_trap(0x8008F808u); }  /* bad delay slot at 0x8008F808 */

void g3_8008F80C(void) { psx_trap(0x8008F80Cu); }  /* bad delay slot at 0x8008F80C */

void g3_8008F810(void) { psx_trap(0x8008F810u); }  /* bad delay slot at 0x8008F810 */

void g3_8008F814(void) { psx_trap(0x8008F814u); }  /* bad delay slot at 0x8008F814 */

void g3_8008F818(void) { psx_trap(0x8008F818u); }  /* bad delay slot at 0x8008F818 */

void g3_8008F81C(void) { psx_trap(0x8008F81Cu); }  /* 0x8008F820: unsupported word 0x000E0E0E (op=0, fn=14) */

void g3_8008F820(void) { psx_trap(0x8008F820u); }  /* 0x8008F820: unsupported word 0x000E0E0E (op=0, fn=14) */

void g3_8008F824(void) { psx_trap(0x8008F824u); }  /* bad delay slot at 0x8008F824 */

void g3_8008F82C(void) { psx_trap(0x8008F82Cu); }  /* bad delay slot at 0x8008F82C */

void g3_8008F830(void) { psx_trap(0x8008F830u); }  /* bad delay slot at 0x8008F830 */

void g3_8008F834(void) { psx_trap(0x8008F834u); }  /* bad delay slot at 0x8008F834 */

void g3_8008F838(void) { psx_trap(0x8008F838u); }  /* bad delay slot at 0x8008F838 */

void g3_8008F83C(void) { psx_trap(0x8008F83Cu); }  /* bad delay slot at 0x8008F83C */

void g3_8008F840(void) { psx_trap(0x8008F840u); }  /* 0x8008F844: unsupported word 0x000E0E0E (op=0, fn=14) */

void g3_8008F844(void) { psx_trap(0x8008F844u); }  /* 0x8008F844: unsupported word 0x000E0E0E (op=0, fn=14) */

void g3_8008F848(void) { psx_trap(0x8008F848u); }  /* bad delay slot at 0x8008F848 */

void g3_8008F850(void) { psx_trap(0x8008F850u); }  /* bad delay slot at 0x8008F850 */

void g3_8008F854(void) { psx_trap(0x8008F854u); }  /* bad delay slot at 0x8008F854 */

void g3_8008F858(void) { psx_trap(0x8008F858u); }  /* bad delay slot at 0x8008F858 */

void g3_8008F85C(void) { psx_trap(0x8008F85Cu); }  /* 0x8008F868: unsupported word 0x007D807D (op=0, fn=61) */

void g3_8008F860(void) { psx_trap(0x8008F860u); }  /* 0x8008F868: unsupported word 0x007D807D (op=0, fn=61) */

void g3_8008F864(void) { psx_trap(0x8008F864u); }  /* 0x8008F868: unsupported word 0x007D807D (op=0, fn=61) */

void g3_8008F8F4(void) { psx_trap(0x8008F8F4u); }  /* 0x8008F8F4: unsupported word 0x00000001 (op=0, fn=1) */

void g3_8008F900(void) { psx_trap(0x8008F900u); }  /* 0x8008F900: unsupported word 0x7FFF7FFF (op=31, fn=63) */

void g3_8008F940(void) { psx_trap(0x8008F940u); }  /* 0x8008F940: unsupported word 0xFFFF0000 (op=63, fn=0) */

void g3_8008F954(void) { psx_trap(0x8008F954u); }  /* 0x8008F954: unsupported word 0xFFFFFFFF (op=63, fn=63) */

void g3_8008FA34(void) { psx_trap(0x8008FA34u); }  /* branch into delay slot: ['0x8008fc50'] */

void g3_8008FA7C(void) { psx_trap(0x8008FA7Cu); }  /* branch into delay slot: ['0x8008fc50'] */

void g3_8008FA84(void) { psx_trap(0x8008FA84u); }  /* branch into delay slot: ['0x8008fc50'] */

void g3_8008FAB4(void) { psx_trap(0x8008FAB4u); }  /* branch into delay slot: ['0x8008fc50'] */

void g3_8008FB10(void) { psx_trap(0x8008FB10u); }  /* branch into delay slot: ['0x8008fc50'] */

void g3_8008FB4C(void) { psx_trap(0x8008FB4Cu); }  /* branch into delay slot: ['0x8008fc50'] */

void g3_8008FBB4(void) { psx_trap(0x8008FBB4u); }  /* branch into delay slot: ['0x8008fc50'] */

void g3_8008FC54(void) { psx_trap(0x8008FC54u); }  /* 0x8008FC54: unsupported word 0xEFF90455 (op=59, fn=21) */

void g3_8008FC70(void) { psx_trap(0x8008FC70u); }  /* branch into delay slot: ['0x8008fc80'] */

void g3_8008FD34(void) { psx_trap(0x8008FD34u); }  /* 0x8008FD34: unsupported word 0x667911CF (op=25, fn=15) */

void g3_8008FDF4(void) { psx_trap(0x8008FDF4u); }  /* 0x8008FDF4: unsupported word 0x4700057A (op=17, fn=58) */

void g3_8008FEAC(void) { psx_trap(0x8008FEACu); }  /* 0x8008FEB0: unsupported word 0x4600CF01 (op=17, fn=1) */

void g3_8008FF28(void) { psx_trap(0x8008FF28u); }  /* 0x8008FF28: unsupported word 0xFFF73567 (op=63, fn=39) */

void g3_8008FF30(void) { psx_trap(0x8008FF30u); }  /* 0x8008FF30: unsupported word 0xFF704555 (op=63, fn=21) */

void g3_8008FF64(void) { psx_trap(0x8008FF64u); }  /* 0x8008FF78: unsupported word 0xBF900000 (op=47, fn=0) */

void g3_80090010(void) { psx_trap(0x80090010u); }  /* 0x80090010: unsupported word 0xFFFF0092 (op=63, fn=18) */

void g3_80090014(void) { psx_trap(0x80090014u); }  /* 0x80090014: unsupported word 0xFFF54669 (op=63, fn=41) */

void g3_80090028(void) { psx_trap(0x80090028u); }  /* 0x80090028: unsupported word 0x78032BD5 (op=30, fn=21) */

void g3_80090088(void) { psx_trap(0x80090088u); }  /* 0x80090088: unsupported word 0x0305ABDF (op=0, fn=31) */

void g3_8009009C(void) { psx_trap(0x8009009Cu); }  /* 0x800900A0: unsupported word 0x00010005 (op=0, fn=5) */

void g3_800900D4(void) {
    R[6] = lwr_(R[11] + 30639, R[6]);  /* 0x800900D4 */
    { uint64_t _p = (uint64_t)R[7] * R[29]; LO = (uint32_t)_p; HI = (uint32_t)(_p >> 32); }  /* 0x800900D8 */
    psx_next = 0x800900DCu; return;  /* fallthrough */
}

void g3_800900DC(void) { psx_trap(0x800900DCu); }  /* 0x800900DC: unsupported word 0x78888ACF (op=30, fn=15) */

void g3_800900E4(void) { psx_trap(0x800900E4u); }  /* 0x800900E4: unsupported word 0x67AFFF00 (op=25, fn=0) */

void g3_8009016C(void) { psx_trap(0x8009016Cu); }  /* 0x8009016C: unsupported word 0x01390028 (op=0, fn=40) */

void g3_800901D8(void) { psx_trap(0x800901D8u); }  /* branch into delay slot: ['0x800902b4', '0x8009038c'] */

void g3_8009037C(void) { psx_trap(0x8009037Cu); }  /* 0x80090398: unsupported word 0x0059009E (op=0, fn=30) */

void g3_80090420(void) { psx_trap(0x80090420u); }  /* 0x80090428: unsupported word 0xFFE86900 (op=63, fn=0) */

void g3_8009051C(void) { psx_trap(0x8009051Cu); }  /* 0x8009051C: unsupported word 0x68C40011 (op=26, fn=17) */

void g3_800905D4(void) { psx_trap(0x800905D4u); }  /* 0x800905D8: unsupported word 0x0503503D (op=1, fn=61) */

void g3_80090600(void) { psx_trap(0x80090600u); }  /* 0x80090600: unsupported word 0xFFA00F06 (op=63, fn=6) */

void g3_80090748(void) { psx_trap(0x80090748u); }  /* 0x80090748: unsupported word 0xF6470449 (op=61, fn=9) */

void g3_80090750(void) { psx_trap(0x80090750u); }  /* branch into delay slot: ['0x800907cc'] */

void g3_80090764(void) { psx_trap(0x80090764u); }  /* branch into delay slot: ['0x800907cc'] */

void g3_800907F8(void) { psx_trap(0x800907F8u); }  /* 0x800907F8: unsupported word 0x41F6AF06 (op=16, fn=6) */

void g3_80090800(void) { psx_trap(0x80090800u); }  /* 0x80090804: unsupported word 0xBF07020D (op=47, fn=13) */

void g3_80090814(void) { psx_trap(0x80090814u); }  /* 0x80090814: unsupported word 0xB207043D (op=44, fn=61) */

void g3_8009083C(void) { psx_trap(0x8009083Cu); }  /* 0x8009083C: unsupported word 0x75464055 (op=29, fn=21) */

void g3_80090880(void) { psx_trap(0x80090880u); }  /* 0x80090880: unsupported word 0x0428DAAE (op=1, fn=46) */

void g3_800908A8(void) { psx_trap(0x800908A8u); }  /* 0x800908A8: unsupported word 0xFF900024 (op=63, fn=36) */

void g3_800908E0(void) { psx_trap(0x800908E0u); }  /* 0x800908EC: unsupported word 0xFD502B00 (op=63, fn=0) */

void g3_800908F4(void) { psx_trap(0x800908F4u); }  /* 0x800908F4: unsupported word 0x6F900151 (op=27, fn=17) */

void g3_80090928(void) { psx_trap(0x80090928u); }  /* branch into delay slot: ['0x80090a48'] */

void g3_800909A4(void) { psx_trap(0x800909A4u); }  /* 0x800909A4: unsupported word 0x01237001 (op=0, fn=1) */

void g3_800909F8(void) { psx_trap(0x800909F8u); }  /* 0x800909F8: unsupported word 0x072E0F6E (op=1, fn=46) */

void g3_80090A04(void) { psx_trap(0x80090A04u); }  /* 0x80090A04: unsupported word 0x6FDAAC05 (op=27, fn=5) */

void g3_80090A4C(void) { psx_trap(0x80090A4Cu); }  /* 0x80090A4C: unsupported word 0xE501015F (op=57, fn=31) */

void g3_80090A5C(void) { psx_trap(0x80090A5Cu); }  /* 0x80090A60: unsupported word 0xC2017997 (op=48, fn=23) */

void g3_80090A94(void) { psx_trap(0x80090A94u); }  /* 0x80090AA0: unsupported word 0x4CFFFF80 (op=19, fn=0) */

void g3_80090A98(void) { psx_trap(0x80090A98u); }  /* 0x80090AA0: unsupported word 0x4CFFFF80 (op=19, fn=0) */

void g3_80090A9C(void) { psx_trap(0x80090A9Cu); }  /* 0x80090AA0: unsupported word 0x4CFFFF80 (op=19, fn=0) */

void g3_80090AB0(void) { psx_trap(0x80090AB0u); }  /* 0x80090AB0: unsupported word 0xD51D080E (op=53, fn=14) */

void g3_80090AB8(void) { psx_trap(0x80090AB8u); }  /* bad delay slot at 0x80090ABC */

void g3_80090AC8(void) { psx_trap(0x80090AC8u); }  /* 0x80090AC8: unsupported word 0x502D091C (op=20, fn=28) */

void g3_80090AD8(void) { psx_trap(0x80090AD8u); }  /* 0x80090ADC: unsupported word 0xFF11FBAF (op=63, fn=47) */

void g3_80090AE4(void) { psx_trap(0x80090AE4u); }  /* bad delay slot at 0x80090AE4 */

void g3_80090AEC(void) { psx_trap(0x80090AECu); }  /* 0x80090AF4: unsupported word 0x04ABB900 (op=1, fn=0) */

void g3_80090B54(void) { psx_trap(0x80090B54u); }  /* 0x80090B54: unsupported word 0x4438022C (op=17, fn=44) */

void g3_80090B90(void) { psx_trap(0x80090B90u); }  /* 0x80090B90: unsupported word 0x41005665 (op=16, fn=37) */

void g3_80090BBC(void) { psx_trap(0x80090BBCu); }  /* 0x80090BCC: unsupported word 0xFFFF8004 (op=63, fn=4) */

void g3_80090BC4(void) { psx_trap(0x80090BC4u); }  /* 0x80090BCC: unsupported word 0xFFFF8004 (op=63, fn=4) */
