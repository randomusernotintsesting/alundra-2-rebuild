#include "event00_decls.h"

void ev_800811DC(void) { psx_trap(0x800811DCu); }  /* 0x800811DC: unsupported word 0x53414356 (op=20, fn=22) */

void ev_800811E8(void) { psx_trap(0x800811E8u); }  /* 0x800811E8: unsupported word 0x6F727265 (op=27, fn=37) */

void ev_800811F4(void) { psx_trap(0x800811F4u); }  /* 0x800811F4: unsupported word 0x6F727265 (op=27, fn=37) */

void ev_80081200(void) { psx_trap(0x80081200u); }  /* 0x80081200: unsupported word 0x6F727265 (op=27, fn=37) */

void ev_8008120C(void) { psx_trap(0x8008120Cu); }  /* 0x8008120C: unsupported word 0x636F6C42 (op=24, fn=2) */

void ev_8008121C(void) { psx_trap(0x8008121Cu); }  /* 0x80081220: unsupported word 0x0000000A (op=0, fn=10) */

void ev_80081224(void) { psx_trap(0x80081224u); }  /* 0x80081224: unsupported word 0x4C4C554E (op=19, fn=14) */

void ev_8008122C(void) { psx_trap(0x8008122Cu); }  /* 0x8008122C: unsupported word 0x4C4C554E (op=19, fn=14) */

void ev_80081248(void) { psx_trap(0x80081248u); }  /* 0x80081248: unsupported word 0x61706544 (op=24, fn=4) */

void ev_80081260(void) { psx_trap(0x80081260u); }  /* 0x80081260: unsupported word 0x6C706178 (op=27, fn=56) */

void ev_80081274(void) { psx_trap(0x80081274u); }  /* 0x80081274: unsupported word 0x65736178 (op=25, fn=56) */

void ev_80081298(void) { psx_trap(0x80081298u); }  /* 0x800813D8: unsupported word 0x43838983 (op=16, fn=3) */

void ev_8008129C(void) { psx_trap(0x8008129Cu); }  /* 0x800813D8: unsupported word 0x43838983 (op=16, fn=3) */

void ev_800813D0(void) { psx_trap(0x800813D0u); }  /* 0x800813D8: unsupported word 0x43838983 (op=16, fn=3) */

void ev_800813F4(void) { psx_trap(0x800813F4u); }  /* 0x80081434: unsupported word 0x696C4359 (op=26, fn=25) */

void ev_80081434(void) { psx_trap(0x80081434u); }  /* 0x80081434: unsupported word 0x696C4359 (op=26, fn=25) */

void ev_80081448(void) { psx_trap(0x80081448u); }  /* 0x80081448: unsupported word 0x5F414356 (op=23, fn=22) */

void ev_80081468(void) { psx_trap(0x80081468u); }  /* 0x80081468: unsupported word 0x73614356 (op=28, fn=22) */

void ev_8008149C(void) { psx_trap(0x8008149Cu); }  /* 0x8008149C: unsupported word 0x73614356 (op=28, fn=22) */

void ev_800814C0(void) { psx_trap(0x800814C0u); }  /* 0x800814C8: unsupported word 0x6425202F (op=25, fn=47) */

void ev_800814D0(void) { psx_trap(0x800814D0u); }  /* 0x800814D0: unsupported word 0x73614356 (op=28, fn=22) */

void ev_800814F4(void) { psx_trap(0x800814F4u); }  /* 0x80081534: unsupported word 0x00D4000A (op=0, fn=10) */

void ev_800814F8(void) { psx_trap(0x800814F8u); }  /* 0x80081534: unsupported word 0x00D4000A (op=0, fn=10) */

void ev_80081530(void) { psx_trap(0x80081530u); }  /* 0x80081534: unsupported word 0x00D4000A (op=0, fn=10) */

void ev_80081538(void) {
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4768);  /* 0x80081538 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4752);  /* 0x8008153C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4736);  /* 0x80081540 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4720);  /* 0x80081544 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4704);  /* 0x80081548 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4688);  /* 0x8008154C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4568);  /* 0x80081550 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4672);  /* 0x80081554 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4656);  /* 0x80081558 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4640);  /* 0x8008155C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4624);  /* 0x80081560 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4608);  /* 0x80081564 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4784);  /* 0x80081568 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4592);  /* 0x8008156C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4576);  /* 0x80081570 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4800);  /* 0x80081574 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081578 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x8008157C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4208);  /* 0x80081580 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3796);  /* 0x80081584 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081588 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x8008158C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3796);  /* 0x80081590 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3988);  /* 0x80081594 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081598 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3796);  /* 0x8008159C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4248);  /* 0x800815A0 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4256);  /* 0x800815A4 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4276);  /* 0x800815A8 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815AC */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815B0 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4284);  /* 0x800815B4 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4372);  /* 0x800815B8 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815BC */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4436);  /* 0x800815C0 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815C4 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815C8 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815CC */
    psx_next = 0x800815D0u; return;  /* fallthrough */
}

void ev_80081578(void) {
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081578 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x8008157C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4208);  /* 0x80081580 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3796);  /* 0x80081584 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081588 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x8008158C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3796);  /* 0x80081590 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3988);  /* 0x80081594 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081598 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3796);  /* 0x8008159C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4248);  /* 0x800815A0 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4256);  /* 0x800815A4 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4276);  /* 0x800815A8 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815AC */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815B0 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4284);  /* 0x800815B4 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4372);  /* 0x800815B8 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815BC */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -4436);  /* 0x800815C0 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815C4 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815C8 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815CC */
    psx_next = 0x800815D0u; return;  /* fallthrough */
}

void ev_800815D0(void) {
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815D0 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815D4 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815D8 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815DC */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815E0 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815E4 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815E8 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815EC */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815F0 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815F4 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815F8 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800815FC */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081600 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081604 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081608 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x8008160C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081610 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081614 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081618 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x8008161C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081620 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081624 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081628 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x8008162C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081630 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081634 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081638 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x8008163C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081640 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081644 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081648 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x8008164C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081650 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081654 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081658 */
    psx_next = 0x8008165Cu; return;  /* fallthrough */
}

void ev_8008165C(void) {
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x8008165C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081660 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081664 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081668 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x8008166C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081670 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081674 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081678 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x8008167C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081680 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081684 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081688 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x8008168C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081690 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081694 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x80081698 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x8008169C */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800816A0 */
    R[8] = (uint32_t)(int8_t)lb_(R[0] + -3792);  /* 0x800816A4 */
    psx_next = 0x800816A8u; return;  /* fallthrough */
}

void ev_800816A8(void) { psx_trap(0x800816A8u); }  /* 0x800816E4: unsupported word 0x53414356 (op=20, fn=22) */

void ev_800816E4(void) { psx_trap(0x800816E4u); }  /* 0x800816E4: unsupported word 0x53414356 (op=20, fn=22) */

void ev_80081704(void) { psx_trap(0x80081704u); }  /* 0x80081704: unsupported word 0x696A656E (op=26, fn=46) */

void ev_8008170C(void) { psx_trap(0x8008170Cu); }  /* 0x8008170C: unsupported word 0x696A656E (op=26, fn=46) */

void ev_80081714(void) { psx_trap(0x80081714u); }  /* 0x80081714: unsupported word 0x696A656E (op=26, fn=46) */

void ev_8008171C(void) { psx_trap(0x8008171Cu); }  /* 0x8008171C: unsupported word 0x696A656E (op=26, fn=46) */

void ev_80081724(void) { psx_trap(0x80081724u); }  /* 0x80081724: unsupported word 0x696A656E (op=26, fn=46) */

void ev_8008172C(void) { psx_trap(0x8008172Cu); }  /* 0x8008172C: unsupported word 0x696A656E (op=26, fn=46) */

void ev_80081734(void) { psx_trap(0x80081734u); }  /* 0x80081734: unsupported word 0x696A656E (op=26, fn=46) */

void ev_8008173C(void) { psx_trap(0x8008173Cu); }  /* 0x8008173C: unsupported word 0x00030001 (op=0, fn=1) */

void ev_80081748(void) { psx_trap(0x80081748u); }  /* 0x800817A0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800817A0(void) { psx_trap(0x800817A0u); }  /* 0x800817A0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800817C0(void) { psx_trap(0x800817C0u); }  /* 0x800817C0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800817E0(void) { psx_trap(0x800817E0u); }  /* 0x800817E0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081800(void) { psx_trap(0x80081800u); }  /* 0x80081800: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081820(void) { psx_trap(0x80081820u); }  /* 0x80081820: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081840(void) { psx_trap(0x80081840u); }  /* 0x80081840: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081860(void) { psx_trap(0x80081860u); }  /* 0x80081860: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081880(void) { psx_trap(0x80081880u); }  /* 0x80081880: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081888(void) { psx_trap(0x80081888u); }  /* 0x80081888: unsupported word 0x74736163 (op=29, fn=35) */

void ev_800818A0(void) { psx_trap(0x800818A0u); }  /* 0x800818A0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800818C0(void) { psx_trap(0x800818C0u); }  /* 0x800818C0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800818E0(void) { psx_trap(0x800818E0u); }  /* 0x800818E0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081900(void) { psx_trap(0x80081900u); }  /* 0x80081900: unsupported word 0x6163765C (op=24, fn=28) */

void ev_8008191C(void) { psx_trap(0x8008191Cu); }  /* 0x8008191C: unsupported word 0x00313B32 (op=0, fn=50) */

void ev_80081920(void) { psx_trap(0x80081920u); }  /* 0x80081920: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081940(void) { psx_trap(0x80081940u); }  /* 0x80081940: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081954(void) { psx_trap(0x80081954u); }  /* 0x80081954: unsupported word 0x65747473 (op=25, fn=51) */

void ev_80081960(void) { psx_trap(0x80081960u); }  /* 0x80081960: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081980(void) { psx_trap(0x80081980u); }  /* 0x80081980: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800819A0(void) { psx_trap(0x800819A0u); }  /* 0x800819A0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800819C0(void) { psx_trap(0x800819C0u); }  /* 0x800819C0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800819E0(void) { psx_trap(0x800819E0u); }  /* 0x800819E0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081A00(void) { psx_trap(0x80081A00u); }  /* 0x80081A00: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081A20(void) { psx_trap(0x80081A20u); }  /* 0x80081A20: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081A40(void) { psx_trap(0x80081A40u); }  /* 0x80081A40: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081A60(void) { psx_trap(0x80081A60u); }  /* 0x80081A60: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081A80(void) { psx_trap(0x80081A80u); }  /* 0x80081A80: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081AA0(void) { psx_trap(0x80081AA0u); }  /* 0x80081AA0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081AC0(void) { psx_trap(0x80081AC0u); }  /* 0x80081AC0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081AE0(void) { psx_trap(0x80081AE0u); }  /* 0x80081AE0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081B00(void) { psx_trap(0x80081B00u); }  /* 0x80081B00: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081B20(void) { psx_trap(0x80081B20u); }  /* 0x80081B20: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081B40(void) { psx_trap(0x80081B40u); }  /* 0x80081B40: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081B60(void) { psx_trap(0x80081B60u); }  /* 0x80081B60: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081B80(void) { psx_trap(0x80081B80u); }  /* 0x80081B80: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081BA0(void) { psx_trap(0x80081BA0u); }  /* 0x80081BA0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081BC0(void) { psx_trap(0x80081BC0u); }  /* 0x80081BC0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081BC8(void) { psx_trap(0x80081BC8u); }  /* 0x80081BC8: unsupported word 0x74736163 (op=29, fn=35) */

void ev_80081BE0(void) { psx_trap(0x80081BE0u); }  /* 0x80081BE0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081C00(void) { psx_trap(0x80081C00u); }  /* 0x80081C00: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081C20(void) { psx_trap(0x80081C20u); }  /* 0x80081C20: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081C3C(void) { psx_trap(0x80081C3Cu); }  /* 0x80081C3C: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081C5C(void) { psx_trap(0x80081C5Cu); }  /* 0x80081C5C: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081C7C(void) { psx_trap(0x80081C7Cu); }  /* 0x80081C7C: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081C9C(void) { psx_trap(0x80081C9Cu); }  /* 0x80081C9C: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081CBC(void) { psx_trap(0x80081CBCu); }  /* 0x80081CBC: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081CCC(void) { psx_trap(0x80081CCCu); }  /* 0x80081CCC: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081CDC(void) { psx_trap(0x80081CDCu); }  /* 0x80081CDC: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081CFC(void) { psx_trap(0x80081CFCu); }  /* 0x80081CFC: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081D1C(void) { psx_trap(0x80081D1Cu); }  /* 0x80081D1C: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081D3C(void) { psx_trap(0x80081D3Cu); }  /* 0x80081D3C: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081D5C(void) { psx_trap(0x80081D5Cu); }  /* 0x80081D5C: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081D7C(void) { psx_trap(0x80081D7Cu); }  /* 0x80081D7C: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081D9C(void) { psx_trap(0x80081D9Cu); }  /* 0x80081D9C: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081DBC(void) { psx_trap(0x80081DBCu); }  /* 0x80081DBC: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081DDC(void) { psx_trap(0x80081DDCu); }  /* 0x80081DDC: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081DFC(void) { psx_trap(0x80081DFCu); }  /* 0x80081DFC: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081E1C(void) { psx_trap(0x80081E1Cu); }  /* 0x80081E1C: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081E3C(void) { psx_trap(0x80081E3Cu); }  /* 0x80081E3C: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081E5C(void) { psx_trap(0x80081E5Cu); }  /* 0x80081E5C: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081E68(void) { psx_trap(0x80081E68u); }  /* 0x80081E6C: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081E80(void) { psx_trap(0x80081E80u); }  /* 0x80081E80: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081EA0(void) { psx_trap(0x80081EA0u); }  /* 0x80081EA0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081EC4(void) { psx_trap(0x80081EC4u); }  /* 0x80081EC4: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081EE4(void) { psx_trap(0x80081EE4u); }  /* 0x80081EE4: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081F04(void) { psx_trap(0x80081F04u); }  /* 0x80081F04: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081F24(void) { psx_trap(0x80081F24u); }  /* 0x80081F24: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081F44(void) { psx_trap(0x80081F44u); }  /* 0x80081F44: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081F68(void) { psx_trap(0x80081F68u); }  /* 0x80081F68: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081F88(void) { psx_trap(0x80081F88u); }  /* 0x80081F88: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081FAC(void) { psx_trap(0x80081FACu); }  /* 0x80081FAC: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081FCC(void) { psx_trap(0x80081FCCu); }  /* 0x80081FCC: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80081FEC(void) { psx_trap(0x80081FECu); }  /* 0x80081FEC: unsupported word 0x6163765C (op=24, fn=28) */

void ev_8008200C(void) { psx_trap(0x8008200Cu); }  /* 0x8008200C: unsupported word 0x6163765C (op=24, fn=28) */

void ev_8008201C(void) { psx_trap(0x8008201Cu); }  /* 0x8008201C: unsupported word 0x6163765C (op=24, fn=28) */

void ev_8008202C(void) { psx_trap(0x8008202Cu); }  /* 0x8008202C: unsupported word 0x6163765C (op=24, fn=28) */

void ev_8008204C(void) { psx_trap(0x8008204Cu); }  /* 0x8008204C: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082070(void) { psx_trap(0x80082070u); }  /* 0x80082070: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082090(void) { psx_trap(0x80082090u); }  /* 0x80082090: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800820B0(void) { psx_trap(0x800820B0u); }  /* 0x800820B0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800820D0(void) { psx_trap(0x800820D0u); }  /* 0x800820D0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800820F0(void) { psx_trap(0x800820F0u); }  /* 0x800820F0: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082110(void) { psx_trap(0x80082110u); }  /* 0x80082110: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082130(void) { psx_trap(0x80082130u); }  /* 0x80082130: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082150(void) { psx_trap(0x80082150u); }  /* 0x80082150: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082170(void) { psx_trap(0x80082170u); }  /* 0x80082170: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082194(void) { psx_trap(0x80082194u); }  /* 0x80082194: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800821B4(void) { psx_trap(0x800821B4u); }  /* 0x800821B4: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800821D8(void) { psx_trap(0x800821D8u); }  /* 0x800821D8: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800821F8(void) { psx_trap(0x800821F8u); }  /* 0x800821F8: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082218(void) { psx_trap(0x80082218u); }  /* 0x80082218: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082224(void) { psx_trap(0x80082224u); }  /* 0x80082228: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082238(void) { psx_trap(0x80082238u); }  /* 0x80082238: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082258(void) { psx_trap(0x80082258u); }  /* 0x80082258: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082278(void) { psx_trap(0x80082278u); }  /* 0x80082278: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082298(void) { psx_trap(0x80082298u); }  /* 0x80082298: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800822B8(void) { psx_trap(0x800822B8u); }  /* 0x800822B8: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800822D8(void) { psx_trap(0x800822D8u); }  /* 0x800822D8: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800822F8(void) { psx_trap(0x800822F8u); }  /* 0x800822F8: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082318(void) { psx_trap(0x80082318u); }  /* 0x80082318: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082338(void) { psx_trap(0x80082338u); }  /* 0x80082338: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082358(void) { psx_trap(0x80082358u); }  /* 0x80082358: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082378(void) { psx_trap(0x80082378u); }  /* 0x80082378: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082398(void) { psx_trap(0x80082398u); }  /* 0x80082398: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800823B8(void) { psx_trap(0x800823B8u); }  /* 0x800823B8: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800823C4(void) { psx_trap(0x800823C4u); }  /* 0x800823C8: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800823D8(void) { psx_trap(0x800823D8u); }  /* 0x800823D8: unsupported word 0x6163765C (op=24, fn=28) */

void ev_800823F8(void) { psx_trap(0x800823F8u); }  /* 0x800823F8: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082418(void) { psx_trap(0x80082418u); }  /* 0x80082418: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082438(void) { psx_trap(0x80082438u); }  /* 0x80082438: unsupported word 0x6163765C (op=24, fn=28) */

void ev_80082458(void) { psx_trap(0x80082458u); }  /* 0x80082458: unsupported word 0x6163765C (op=24, fn=28) */
