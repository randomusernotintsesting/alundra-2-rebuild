#include "game02_decls.h"

void g2_800B065C(void) { psx_trap(0x800B065Cu); }  /* 0x800B065C: unsupported word 0x005D0030 (op=0, fn=48) */

void g2_800B0680(void) { psx_trap(0x800B0680u); }  /* 0x800B0680: unsupported word 0x00620030 (op=0, fn=48) */

void g2_800B06A4(void) { psx_trap(0x800B06A4u); }  /* 0x800B06A4: unsupported word 0x00670030 (op=0, fn=48) */

void g2_800B06C8(void) { psx_trap(0x800B06C8u); }  /* 0x800B06C8: unsupported word 0x006C0030 (op=0, fn=48) */

void g2_800B06EC(void) { psx_trap(0x800B06ECu); }  /* 0x800B06EC: unsupported word 0x00710030 (op=0, fn=48) */

void g2_800B0710(void) { psx_trap(0x800B0710u); }  /* 0x800B0710: unsupported word 0x00760030 (op=0, fn=48) */

void g2_800B0734(void) { psx_trap(0x800B0734u); }  /* 0x800B0734: unsupported word 0x007B0030 (op=0, fn=48) */

void g2_800B0758(void) { psx_trap(0x800B0758u); }  /* 0x800B0758: unsupported word 0x00800030 (op=0, fn=48) */

void g2_800B077C(void) { psx_trap(0x800B077Cu); }  /* 0x800B077C: unsupported word 0x00850030 (op=0, fn=48) */

void g2_800B07A0(void) { psx_trap(0x800B07A0u); }  /* 0x800B07A0: unsupported word 0x008A0030 (op=0, fn=48) */

void g2_800B07C4(void) { psx_trap(0x800B07C4u); }  /* 0x800B07C4: unsupported word 0x008F0030 (op=0, fn=48) */

void g2_800B07E8(void) { psx_trap(0x800B07E8u); }  /* 0x800B07E8: unsupported word 0x00930030 (op=0, fn=48) */

void g2_800B080C(void) { psx_trap(0x800B080Cu); }  /* 0x800B080C: unsupported word 0x00980030 (op=0, fn=48) */

void g2_800B08A8(void) { psx_trap(0x800B08A8u); }  /* 0x800B08A8: unsupported word 0x009800A8 (op=0, fn=40) */

void g2_800B08B4(void) { psx_trap(0x800B08B4u); }  /* 0x800B08B4: unsupported word 0x009800B0 (op=0, fn=48) */

void g2_800B08C0(void) { psx_trap(0x800B08C0u); }  /* 0x800B08C0: unsupported word 0x009800B8 (op=0, fn=56) */

void g2_800B08CC(void) { psx_trap(0x800B08CCu); }  /* bad delay slot at 0x800B08D8 */

void g2_800B08D8(void) { psx_trap(0x800B08D8u); }  /* bad delay slot at 0x800B08D8 */

void g2_800B08E4(void) {
    R[10] = (uint32_t)(int8_t)lb_(R[0] + 31024);  /* 0x800B08E4 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + 31024);  /* 0x800B08E8 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + 31100);  /* 0x800B08EC */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + 31440);  /* 0x800B08F0 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + 31552);  /* 0x800B08F4 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + 32208);  /* 0x800B08F8 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -32352);  /* 0x800B08FC */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -32152);  /* 0x800B0900 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -31296);  /* 0x800B0904 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -31004);  /* 0x800B0908 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -30664);  /* 0x800B090C */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -29600);  /* 0x800B0910 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -29380);  /* 0x800B0914 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -28344);  /* 0x800B0918 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -28100);  /* 0x800B091C */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -27748);  /* 0x800B0920 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -27260);  /* 0x800B0924 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -26776);  /* 0x800B0928 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -26204);  /* 0x800B092C */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -26088);  /* 0x800B0930 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -25816);  /* 0x800B0934 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -25472);  /* 0x800B0938 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -24412);  /* 0x800B093C */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -23760);  /* 0x800B0940 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -22384);  /* 0x800B0944 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -21512);  /* 0x800B0948 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -20568);  /* 0x800B094C */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -19220);  /* 0x800B0950 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -18688);  /* 0x800B0954 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -17900);  /* 0x800B0958 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -17524);  /* 0x800B095C */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -16500);  /* 0x800B0960 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -15056);  /* 0x800B0964 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -14248);  /* 0x800B0968 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -13124);  /* 0x800B096C */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -12256);  /* 0x800B0970 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -10980);  /* 0x800B0974 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -10052);  /* 0x800B0978 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -8692);  /* 0x800B097C */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -7896);  /* 0x800B0980 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -7616);  /* 0x800B0984 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -6868);  /* 0x800B0988 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -5808);  /* 0x800B098C */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -4744);  /* 0x800B0990 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -4056);  /* 0x800B0994 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -3656);  /* 0x800B0998 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -2712);  /* 0x800B099C */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -1340);  /* 0x800B09A0 */
    R[10] = (uint32_t)(int8_t)lb_(R[0] + -64);  /* 0x800B09A4 */
    R[11] = (uint32_t)(int8_t)lb_(R[0] + 900);  /* 0x800B09A8 */
    R[11] = (uint32_t)(int8_t)lb_(R[0] + 928);  /* 0x800B09AC */
    R[29] = 0x283Bu << 16;  /* 0x800B09B4 */
    psx_next = 0x800B1380u; return;  /* fallthrough */
}

void g2_800B09B8(void) {
    psx_next = 0x800B1380u; return;  /* fallthrough */
}

void g2_800B0AB8(void) {
    psx_next = 0x800B1380u; return;  /* fallthrough */
}

void g2_800B0BB8(void) {
    psx_next = 0x800B1380u; return;  /* fallthrough */
}

void g2_800B1124(void) {
    psx_next = 0x800B1380u; return;  /* fallthrough */
}

void g2_800B1380(void) {
    psx_next = 0x800B1458u; return;  /* fallthrough */
}

void g2_800B1458(void) {
    psx_next = 0x800B14ACu; return;  /* fallthrough */
}

void g2_800B14AC(void) {
    psx_next = 0x800B1570u; return;  /* fallthrough */
}

void g2_800B1570(void) {
    psx_next = 0x800B164Cu; return;  /* fallthrough */
}

void g2_800B1590(void) {
    psx_next = 0x800B164Cu; return;  /* fallthrough */
}

void g2_800B164C(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B190C(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B2108(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B2200(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B2204(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B2208(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B2220(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B2300(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B2304(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B2404(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B2528(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B2624(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B2800(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B2804(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B2D34(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B3234(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B3300(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B3400(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B3430(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B3534(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B3900(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B3B04(void) {
    psx_next = 0x800B3E4Cu; return;  /* fallthrough */
}

void g2_800B3E4C(void) {
    psx_next = 0x800B42B8u; return;  /* fallthrough */
}

void g2_800B4000(void) {
    psx_next = 0x800B42B8u; return;  /* fallthrough */
}

void g2_800B42B8(void) {
    psx_next = 0x800B4A20u; return;  /* fallthrough */
}

void g2_800B4A20(void) {
    psx_next = 0x800B4A9Cu; return;  /* fallthrough */
}

void g2_800B4A9C(void) {
    psx_next = 0x800B516Cu; return;  /* fallthrough */
}

void g2_800B516C(void) {
    psx_next = 0x800B62B8u; return;  /* fallthrough */
}

void g2_800B5504(void) {
    psx_next = 0x800B62B8u; return;  /* fallthrough */
}

void g2_800B5D00(void) {
    psx_next = 0x800B62B8u; return;  /* fallthrough */
}

void g2_800B62B8(void) {
    psx_next = 0x800B6370u; return;  /* fallthrough */
}

void g2_800B6370(void) {
    psx_next = 0x800B63C8u; return;  /* fallthrough */
}

void g2_800B63C8(void) {
    psx_next = 0x800B6420u; return;  /* fallthrough */
}

void g2_800B6420(void) {
    psx_next = 0x800B6668u; return;  /* fallthrough */
}

void g2_800B6668(void) {
    psx_next = 0x800B673Cu; return;  /* fallthrough */
}

void g2_800B673C(void) {
    psx_next = 0x800B6994u; return;  /* fallthrough */
}

void g2_800B6764(void) {
    psx_next = 0x800B6994u; return;  /* fallthrough */
}

void g2_800B6994(void) {
    psx_next = 0x800B69D4u; return;  /* fallthrough */
}

void g2_800B69D4(void) {
    psx_next = 0x800B6A98u; return;  /* fallthrough */
}

void g2_800B6A98(void) {
    psx_next = 0x800B6B88u; return;  /* fallthrough */
}

void g2_800B6B88(void) {
    psx_next = 0x800B6BB8u; return;  /* fallthrough */
}

void g2_800B6BB8(void) {
    psx_next = 0x800B6C1Cu; return;  /* fallthrough */
}

void g2_800B6C1C(void) {
    psx_next = 0x800B6C88u; return;  /* fallthrough */
}

void g2_800B6C88(void) {
    psx_next = 0x800B6CA4u; return;  /* fallthrough */
}

void g2_800B6CA4(void) {
    psx_next = 0x800B6EACu; return;  /* fallthrough */
}

void g2_800B6EAC(void) {
    psx_next = 0x800B6EF4u; return;  /* fallthrough */
}

void g2_800B6EF4(void) {
    psx_next = 0x800B6F54u; return;  /* fallthrough */
}

void g2_800B6F54(void) {
    psx_next = 0x800B701Cu; return;  /* fallthrough */
}

void g2_800B701C(void) {
    psx_next = 0x800B745Cu; return;  /* fallthrough */
}

void g2_800B745C(void) {
    psx_next = 0x800B7634u; return;  /* fallthrough */
}

void g2_800B7634(void) {
    psx_next = 0x800B7710u; return;  /* fallthrough */
}

void g2_800B7710(void) {
    psx_next = 0x800B7730u; return;  /* fallthrough */
}

void g2_800B7730(void) {
    psx_next = 0x800B7764u; return;  /* fallthrough */
}

void g2_800B7764(void) {
    psx_next = 0x800B77BCu; return;  /* fallthrough */
}

void g2_800B77BC(void) {
    psx_next = 0x800B78A4u; return;  /* fallthrough */
}

void g2_800B78A4(void) {
    psx_next = 0x800B78BCu; return;  /* fallthrough */
}

void g2_800B78BC(void) {
    psx_next = 0x800B7970u; return;  /* fallthrough */
}

void g2_800B7970(void) {
    psx_next = 0x800B79A4u; return;  /* fallthrough */
}

void g2_800B79A4(void) {
    psx_next = 0x800B7B80u; return;  /* fallthrough */
}

void g2_800B7B80(void) {
    psx_next = 0x800B7C34u; return;  /* fallthrough */
}

void g2_800B7C34(void) {
    psx_next = 0x800B7CE8u; return;  /* fallthrough */
}

void g2_800B7CE8(void) {
    psx_next = 0x800B7D14u; return;  /* fallthrough */
}

void g2_800B7D14(void) {
    psx_next = 0x800B7DECu; return;  /* fallthrough */
}

void g2_800B7DEC(void) {
    psx_next = 0x800B7E24u; return;  /* fallthrough */
}

void g2_800B7E24(void) {
    psx_next = 0x800B8518u; return;  /* fallthrough */
}

void g2_800B8518(void) {
    psx_next = 0x800B8578u; return;  /* fallthrough */
}

void g2_800B8578(void) {
    psx_next = 0x800B862Cu; return;  /* fallthrough */
}

void g2_800B862C(void) {
    psx_next = 0x800BAC20u; return;  /* fallthrough */
}

void g2_800BAC20(void) {
    psx_next = 0x800BACA8u; return;  /* fallthrough */
}

void g2_800BACA8(void) {
    psx_next = 0x800BAEBCu; return;  /* fallthrough */
}

void g2_800BAEBC(void) {
    psx_next = 0x800BB008u; return;  /* fallthrough */
}

void g2_800BB008(void) {
    psx_next = 0x800BB2E0u; return;  /* fallthrough */
}

void g2_800BB2E0(void) {
    psx_next = 0x800BB470u; return;  /* fallthrough */
}

void g2_800BB470(void) {
    psx_next = 0x800BB67Cu; return;  /* fallthrough */
}

void g2_800BB67C(void) {
    psx_next = 0x800BB8A8u; return;  /* fallthrough */
}

void g2_800BB8A8(void) {
    psx_next = 0x800BC86Cu; return;  /* fallthrough */
}

void g2_800BC86C(void) {
    psx_next = 0x800BD2B4u; return;  /* fallthrough */
}

void g2_800BD2B4(void) {
    psx_next = 0x800BD31Cu; return;  /* fallthrough */
}

void g2_800BD31C(void) {
    psx_next = 0x800BD3A4u; return;  /* fallthrough */
}

void g2_800BD3A4(void) {
    psx_next = 0x800BD63Cu; return;  /* fallthrough */
}

void g2_800BD63C(void) {
    psx_next = 0x800BD668u; return;  /* fallthrough */
}

void g2_800BD668(void) {
    psx_next = 0x800BD698u; return;  /* fallthrough */
}

void g2_800BD698(void) {
    psx_next = 0x800BD6DCu; return;  /* fallthrough */
}

void g2_800BD6DC(void) {
    psx_next = 0x800BD9E4u; return;  /* fallthrough */
}

void g2_800BD9E4(void) {
    psx_next = 0x800BDADCu; return;  /* fallthrough */
}

void g2_800BDADC(void) {
    psx_next = 0x800BDB38u; return;  /* fallthrough */
}

void g2_800BDB38(void) {
    psx_next = 0x800BDB8Cu; return;  /* fallthrough */
}

void g2_800BDB8C(void) {
    psx_next = 0x800BDBF8u; return;  /* fallthrough */
}

void g2_800BDBF8(void) {
    psx_next = 0x800BDC88u; return;  /* fallthrough */
}

void g2_800BDC88(void) {
    psx_next = 0x800BDCC0u; return;  /* fallthrough */
}

void g2_800BDCC0(void) {
    psx_next = 0x800BDD34u; return;  /* fallthrough */
}

void g2_800BDD34(void) {
    psx_next = 0x800BDD6Cu; return;  /* fallthrough */
}

void g2_800BDD6C(void) {
    psx_next = 0x800BDE00u; return;  /* fallthrough */
}

void g2_800BDE00(void) {
    psx_next = 0x800BDF08u; return;  /* fallthrough */
}

void g2_800BDF08(void) {
    psx_next = 0x800BDFDCu; return;  /* fallthrough */
}

void g2_800BDFDC(void) {
    psx_next = 0x800BE394u; return;  /* fallthrough */
}

void g2_800BE394(void) {
    psx_next = 0x800BE82Cu; return;  /* fallthrough */
}

void g2_800BE82C(void) {
    psx_next = 0x800BE85Cu; return;  /* fallthrough */
}

void g2_800BE85C(void) {
    psx_next = 0x800BE88Cu; return;  /* fallthrough */
}

void g2_800BE88C(void) {
    psx_next = 0x800BE8D8u; return;  /* fallthrough */
}

void g2_800BE8D8(void) {
    psx_next = 0x800BE928u; return;  /* fallthrough */
}

void g2_800BE928(void) {
    psx_next = 0x800BE978u; return;  /* fallthrough */
}

void g2_800BE978(void) {
    psx_next = 0x800BEFB8u; return;  /* fallthrough */
}

void g2_800BEFB8(void) {
    psx_next = 0x800BEFFCu; return;  /* fallthrough */
}

void g2_800BEFFC(void) {
    psx_next = 0x800BF018u; return;  /* fallthrough */
}

void g2_800BF018(void) {
    psx_next = 0x800BF148u; return;  /* fallthrough */
}

void g2_800BF148(void) {
    psx_next = 0x800BF380u; return;  /* fallthrough */
}

void g2_800BF380(void) {
    psx_next = 0x800BF48Cu; return;  /* fallthrough */
}

void g2_800BF48C(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void g2_800BF600(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void g2_800C0C0C(void) {
    psx_next = 0x800C0E48u; return;  /* fallthrough */
}

void g2_800C0E48(void) {
    psx_next = 0x800C116Cu; return;  /* fallthrough */
}

void g2_800C116C(void) {
    psx_next = 0x800C11C8u; return;  /* fallthrough */
}

void g2_800C11C8(void) {
    psx_next = 0x800C1538u; return;  /* fallthrough */
}

void g2_800C1538(void) {
    psx_next = 0x800C17C8u; return;  /* fallthrough */
}

void g2_800C17C8(void) {
    psx_next = 0x800C18D4u; return;  /* fallthrough */
}

void g2_800C18D4(void) {
    psx_next = 0x800C1B54u; return;  /* fallthrough */
}

void g2_800C1B54(void) {
    psx_next = 0x800C1B88u; return;  /* fallthrough */
}

void g2_800C1B88(void) {
    psx_next = 0x800C1CECu; return;  /* fallthrough */
}

void g2_800C1CEC(void) {
    psx_next = 0x800C1DF0u; return;  /* fallthrough */
}

void g2_800C1DF0(void) {
    psx_next = 0x800C1F9Cu; return;  /* fallthrough */
}

void g2_800C1F9C(void) {
    psx_next = 0x800C214Cu; return;  /* fallthrough */
}
