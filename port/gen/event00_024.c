#include "event00_decls.h"

void ev_800B3450(void) { psx_trap(0x800B3450u); }  /* 0x800B3458: unsupported word 0x0000FFFF (op=0, fn=63) */

void ev_800B345C(void) { psx_trap(0x800B345Cu); }  /* 0x800B345C: unsupported word 0x01400001 (op=0, fn=1) */

void ev_800B349C(void) { psx_trap(0x800B349Cu); }  /* 0x800B34A4: unsupported word 0x0001FFFF (op=0, fn=63) */

void ev_800B34B4(void) { psx_trap(0x800B34B4u); }  /* 0x800B34B4: unsupported word 0x0000003C (op=0, fn=60) */

void ev_800B3570(void) { psx_trap(0x800B3570u); }  /* 0x800B3574: unsupported word 0x006E004A (op=0, fn=10) */

void ev_800B36B4(void) { psx_trap(0x800B36B4u); }  /* 0x800B36C8: unsupported word 0x000000FF (op=0, fn=63) */

void ev_800B3774(void) { psx_trap(0x800B3774u); }  /* 0x800B3774: unsupported word 0x0000008E (op=0, fn=14) */

void ev_800B3808(void) { psx_trap(0x800B3808u); }  /* 0x800B380C: unsupported word 0x000000DF (op=0, fn=31) */

void ev_800B3A04(void) { psx_trap(0x800B3A04u); }  /* 0x800B3A08: unsupported word 0xFFFFFF24 (op=63, fn=36) */

void ev_800B3D78(void) { psx_trap(0x800B3D78u); }  /* 0x800B3D78: unsupported word 0x0000008E (op=0, fn=14) */

void ev_800B3E4C(void) { psx_trap(0x800B3E4Cu); }  /* 0x800B3E4C: unsupported word 0xFFFFFFB0 (op=63, fn=48) */

void ev_800B3EB4(void) {
    R[21] = (uint32_t)(int8_t)lb_(R[0]);  /* 0x800B3EB4 */
    R[21] = (uint32_t)(int8_t)lb_(R[0] + -32768);  /* 0x800B3EB8 */
    R[28] = (uint32_t)(int8_t)lb_(R[0]);  /* 0x800B3EBC */
    R[29] = (uint32_t)(int8_t)lb_(R[0] + -32768);  /* 0x800B3EC0 */
    R[22] = (uint32_t)(int8_t)lb_(R[0]);  /* 0x800B3EC4 */
    sw_(R[21] + -8757, gte_data_read(31));  /* 0x800B3EE4 */
    psx_next = 0x800B42B8u; return;  /* fallthrough */
}

void ev_800B3EC8(void) {
    sw_(R[21] + -8757, gte_data_read(31));  /* 0x800B3EE4 */
    psx_next = 0x800B42B8u; return;  /* fallthrough */
}

void ev_800B3ED4(void) {
    sw_(R[21] + -8757, gte_data_read(31));  /* 0x800B3EE4 */
    psx_next = 0x800B42B8u; return;  /* fallthrough */
}

void ev_800B3EF8(void) {
    psx_next = 0x800B42B8u; return;  /* fallthrough */
}

void ev_800B3F18(void) {
    psx_next = 0x800B42B8u; return;  /* fallthrough */
}

void ev_800B3FD8(void) {
    psx_next = 0x800B42B8u; return;  /* fallthrough */
}

void ev_800B4000(void) {
    psx_next = 0x800B42B8u; return;  /* fallthrough */
}

void ev_800B4218(void) {
    psx_next = 0x800B42B8u; return;  /* fallthrough */
}

void ev_800B4238(void) {
    psx_next = 0x800B42B8u; return;  /* fallthrough */
}

void ev_800B4298(void) {
    psx_next = 0x800B42B8u; return;  /* fallthrough */
}

void ev_800B42B8(void) {
    psx_next = 0x800B4A20u; return;  /* fallthrough */
}

void ev_800B4A20(void) {
    psx_next = 0x800B4A9Cu; return;  /* fallthrough */
}

void ev_800B4A9C(void) {
    psx_next = 0x800B516Cu; return;  /* fallthrough */
}

void ev_800B4B68(void) {
    psx_next = 0x800B516Cu; return;  /* fallthrough */
}

void ev_800B4B70(void) {
    psx_next = 0x800B516Cu; return;  /* fallthrough */
}

void ev_800B516C(void) {
    psx_next = 0x800B62B8u; return;  /* fallthrough */
}

void ev_800B62B8(void) {
    psx_next = 0x800B6370u; return;  /* fallthrough */
}

void ev_800B6370(void) {
    psx_next = 0x800B63C8u; return;  /* fallthrough */
}

void ev_800B63C8(void) {
    psx_next = 0x800B6420u; return;  /* fallthrough */
}

void ev_800B6420(void) {
    psx_next = 0x800B6668u; return;  /* fallthrough */
}

void ev_800B6668(void) {
    psx_next = 0x800B673Cu; return;  /* fallthrough */
}

void ev_800B673C(void) {
    psx_next = 0x800B6994u; return;  /* fallthrough */
}

void ev_800B6994(void) {
    psx_next = 0x800B69D4u; return;  /* fallthrough */
}

void ev_800B69D4(void) {
    psx_next = 0x800B6A98u; return;  /* fallthrough */
}

void ev_800B6A98(void) {
    psx_next = 0x800B6B88u; return;  /* fallthrough */
}

void ev_800B6B88(void) {
    psx_next = 0x800B6BB8u; return;  /* fallthrough */
}

void ev_800B6BB8(void) {
    psx_next = 0x800B6C1Cu; return;  /* fallthrough */
}

void ev_800B6C1C(void) {
    psx_next = 0x800B6C88u; return;  /* fallthrough */
}

void ev_800B6C88(void) {
    psx_next = 0x800B6CA4u; return;  /* fallthrough */
}

void ev_800B6CA4(void) {
    psx_next = 0x800B6EACu; return;  /* fallthrough */
}

void ev_800B6EAC(void) {
    psx_next = 0x800B6EF4u; return;  /* fallthrough */
}

void ev_800B6EF4(void) {
    psx_next = 0x800B6F54u; return;  /* fallthrough */
}

void ev_800B6F54(void) {
    psx_next = 0x800B701Cu; return;  /* fallthrough */
}

void ev_800B701C(void) {
    psx_next = 0x800B745Cu; return;  /* fallthrough */
}

void ev_800B7388(void) {
    psx_next = 0x800B745Cu; return;  /* fallthrough */
}

void ev_800B73B0(void) {
    psx_next = 0x800B745Cu; return;  /* fallthrough */
}

void ev_800B745C(void) {
    psx_next = 0x800B7634u; return;  /* fallthrough */
}

void ev_800B74B0(void) {
    psx_next = 0x800B7634u; return;  /* fallthrough */
}

void ev_800B75B0(void) {
    psx_next = 0x800B7634u; return;  /* fallthrough */
}

void ev_800B75C8(void) {
    psx_next = 0x800B7634u; return;  /* fallthrough */
}

void ev_800B75E8(void) {
    psx_next = 0x800B7634u; return;  /* fallthrough */
}

void ev_800B7634(void) {
    psx_next = 0x800B7710u; return;  /* fallthrough */
}

void ev_800B7668(void) {
    psx_next = 0x800B7710u; return;  /* fallthrough */
}

void ev_800B76F0(void) {
    psx_next = 0x800B7710u; return;  /* fallthrough */
}

void ev_800B7710(void) {
    psx_next = 0x800B7730u; return;  /* fallthrough */
}

void ev_800B7730(void) {
    psx_next = 0x800B7764u; return;  /* fallthrough */
}

void ev_800B7760(void) {
    psx_next = 0x800B7764u; return;  /* fallthrough */
}

void ev_800B7764(void) {
    psx_next = 0x800B77BCu; return;  /* fallthrough */
}

void ev_800B7770(void) {
    psx_next = 0x800B77BCu; return;  /* fallthrough */
}

void ev_800B77BC(void) {
    psx_next = 0x800B78A4u; return;  /* fallthrough */
}

void ev_800B78A4(void) {
    psx_next = 0x800B78BCu; return;  /* fallthrough */
}

void ev_800B78B8(void) {
    psx_next = 0x800B78BCu; return;  /* fallthrough */
}

void ev_800B78BC(void) {
    psx_next = 0x800B7970u; return;  /* fallthrough */
}

void ev_800B7970(void) {
    psx_next = 0x800B79A4u; return;  /* fallthrough */
}

void ev_800B79A4(void) {
    psx_next = 0x800B7B80u; return;  /* fallthrough */
}

void ev_800B7B80(void) {
    psx_next = 0x800B7C34u; return;  /* fallthrough */
}

void ev_800B7C34(void) {
    psx_next = 0x800B7CE8u; return;  /* fallthrough */
}

void ev_800B7CE8(void) {
    psx_next = 0x800B7D14u; return;  /* fallthrough */
}

void ev_800B7D14(void) {
    psx_next = 0x800B7DECu; return;  /* fallthrough */
}

void ev_800B7DEC(void) {
    psx_next = 0x800B7E24u; return;  /* fallthrough */
}

void ev_800B7E24(void) {
    psx_next = 0x800B8518u; return;  /* fallthrough */
}

void ev_800B8518(void) {
    psx_next = 0x800B8578u; return;  /* fallthrough */
}

void ev_800B8578(void) {
    psx_next = 0x800B862Cu; return;  /* fallthrough */
}

void ev_800B862C(void) {
    psx_next = 0x800BAC20u; return;  /* fallthrough */
}

void ev_800B9FD0(void) {
    psx_next = 0x800BAC20u; return;  /* fallthrough */
}

void ev_800BA00C(void) {
    psx_next = 0x800BAC20u; return;  /* fallthrough */
}

void ev_800BAC20(void) {
    psx_next = 0x800BACA8u; return;  /* fallthrough */
}

void ev_800BACA8(void) {
    psx_next = 0x800BAEBCu; return;  /* fallthrough */
}

void ev_800BAEBC(void) {
    psx_next = 0x800BB008u; return;  /* fallthrough */
}

void ev_800BB008(void) {
    psx_next = 0x800BB2E0u; return;  /* fallthrough */
}

void ev_800BB2E0(void) {
    psx_next = 0x800BB470u; return;  /* fallthrough */
}

void ev_800BB470(void) {
    psx_next = 0x800BB67Cu; return;  /* fallthrough */
}

void ev_800BB67C(void) {
    psx_next = 0x800BB8A8u; return;  /* fallthrough */
}

void ev_800BB8A8(void) {
    psx_next = 0x800BC86Cu; return;  /* fallthrough */
}

void ev_800BBFCC(void) {
    psx_next = 0x800BC86Cu; return;  /* fallthrough */
}

void ev_800BC86C(void) {
    psx_next = 0x800BD2B4u; return;  /* fallthrough */
}

void ev_800BD2B4(void) {
    psx_next = 0x800BD31Cu; return;  /* fallthrough */
}

void ev_800BD31C(void) {
    psx_next = 0x800BD3A4u; return;  /* fallthrough */
}

void ev_800BD3A4(void) {
    psx_next = 0x800BD63Cu; return;  /* fallthrough */
}

void ev_800BD63C(void) {
    psx_next = 0x800BD668u; return;  /* fallthrough */
}

void ev_800BD668(void) {
    psx_next = 0x800BD698u; return;  /* fallthrough */
}

void ev_800BD698(void) {
    psx_next = 0x800BD6DCu; return;  /* fallthrough */
}

void ev_800BD6DC(void) {
    psx_next = 0x800BD9E4u; return;  /* fallthrough */
}

void ev_800BD9E4(void) {
    psx_next = 0x800BDADCu; return;  /* fallthrough */
}

void ev_800BDADC(void) {
    psx_next = 0x800BDB38u; return;  /* fallthrough */
}

void ev_800BDB38(void) {
    psx_next = 0x800BDB8Cu; return;  /* fallthrough */
}

void ev_800BDB8C(void) {
    psx_next = 0x800BDBF8u; return;  /* fallthrough */
}

void ev_800BDBF8(void) {
    psx_next = 0x800BDC88u; return;  /* fallthrough */
}

void ev_800BDC88(void) {
    psx_next = 0x800BDCC0u; return;  /* fallthrough */
}

void ev_800BDCC0(void) {
    psx_next = 0x800BDD34u; return;  /* fallthrough */
}

void ev_800BDD34(void) {
    psx_next = 0x800BDD6Cu; return;  /* fallthrough */
}

void ev_800BDD6C(void) {
    psx_next = 0x800BDE00u; return;  /* fallthrough */
}

void ev_800BDE00(void) {
    psx_next = 0x800BDF08u; return;  /* fallthrough */
}

void ev_800BDF08(void) {
    psx_next = 0x800BDFDCu; return;  /* fallthrough */
}

void ev_800BDFD0(void) {
    psx_next = 0x800BDFDCu; return;  /* fallthrough */
}

void ev_800BDFDC(void) {
    psx_next = 0x800BE394u; return;  /* fallthrough */
}

void ev_800BE394(void) {
    psx_next = 0x800BE82Cu; return;  /* fallthrough */
}

void ev_800BE82C(void) {
    psx_next = 0x800BE85Cu; return;  /* fallthrough */
}

void ev_800BE85C(void) {
    psx_next = 0x800BE88Cu; return;  /* fallthrough */
}

void ev_800BE88C(void) {
    psx_next = 0x800BE8D8u; return;  /* fallthrough */
}

void ev_800BE8D8(void) {
    psx_next = 0x800BE928u; return;  /* fallthrough */
}

void ev_800BE928(void) {
    psx_next = 0x800BE978u; return;  /* fallthrough */
}

void ev_800BE978(void) {
    psx_next = 0x800BEFB8u; return;  /* fallthrough */
}

void ev_800BEFB8(void) {
    psx_next = 0x800BEFFCu; return;  /* fallthrough */
}

void ev_800BEFFC(void) {
    psx_next = 0x800BF018u; return;  /* fallthrough */
}

void ev_800BF018(void) {
    psx_next = 0x800BF148u; return;  /* fallthrough */
}

void ev_800BF148(void) {
    psx_next = 0x800BF380u; return;  /* fallthrough */
}

void ev_800BF380(void) {
    psx_next = 0x800BF48Cu; return;  /* fallthrough */
}

void ev_800BF48C(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void ev_800BFC00(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void ev_800BFF00(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void ev_800BFFEC(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void ev_800BFFFC(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void ev_800C0004(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void ev_800C0008(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void ev_800C0010(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void ev_800C0018(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void ev_800C0088(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void ev_800C00AC(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void ev_800C00C0(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void ev_800C0104(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void ev_800C03DC(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void ev_800C040C(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void ev_800C043C(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void ev_800C06C0(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void ev_800C0E48(void) {
    psx_next = 0x800C116Cu; return;  /* fallthrough */
}

void ev_800C1000(void) {
    psx_next = 0x800C116Cu; return;  /* fallthrough */
}

void ev_800C116C(void) {
    psx_next = 0x800C11C8u; return;  /* fallthrough */
}

void ev_800C11C8(void) {
    psx_next = 0x800C1538u; return;  /* fallthrough */
}

void ev_800C1538(void) {
    psx_next = 0x800C17C8u; return;  /* fallthrough */
}

void ev_800C17C8(void) {
    psx_next = 0x800C18D4u; return;  /* fallthrough */
}

void ev_800C18D4(void) {
    psx_next = 0x800C1B54u; return;  /* fallthrough */
}

void ev_800C1B54(void) {
    psx_next = 0x800C1B88u; return;  /* fallthrough */
}

void ev_800C1B88(void) {
    psx_next = 0x800C1CECu; return;  /* fallthrough */
}

void ev_800C1CEC(void) {
    psx_next = 0x800C1DF0u; return;  /* fallthrough */
}

void ev_800C1DF0(void) {
    psx_next = 0x800C1F9Cu; return;  /* fallthrough */
}

void ev_800C1F9C(void) {
    psx_next = 0x800C214Cu; return;  /* fallthrough */
}

void ev_800C214C(void) {
    psx_next = 0x800C22C4u; return;  /* fallthrough */
}

void ev_800C22C4(void) {
    psx_next = 0x800C2310u; return;  /* fallthrough */
}
