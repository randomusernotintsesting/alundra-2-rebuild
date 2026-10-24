#include "game02_decls.h"

void g2_800A5B0C(void) { psx_trap(0x800A5B0Cu); }  /* 0x800A5B10: unsupported word 0x726A270B (op=28, fn=11) */

void g2_800A5B9C(void) { psx_trap(0x800A5B9Cu); }  /* 0x800A5BA0: unsupported word 0x7F553C06 (op=31, fn=6) */

void g2_800A5C48(void) { psx_trap(0x800A5C48u); }  /* 0x800A5C50: unsupported word 0xFF20C802 (op=63, fn=2) */

void g2_800A5CAC(void) {
    R[18] = lb_(R[20] + -28014);  /* 0x800A5CAC */
    (void)(lwr_(R[12] + -28014, R[0]));  /* 0x800A5CB0 */
    psx_next = 0x800A5CB4u; return;  /* fallthrough */
}

void g2_800A5CB4(void) { psx_trap(0x800A5CB4u); }  /* 0x800A5CB4: unsupported word 0xFFFFD904 (op=63, fn=4) */

void g2_800A5E98(void) { psx_trap(0x800A5E98u); }  /* branch into delay slot: ['0x800a6478', '0x800a6710'] */

void g2_800A5EE0(void) { psx_trap(0x800A5EE0u); }  /* branch into delay slot: ['0x800a6478', '0x800a6710'] */

void g2_800A5EFC(void) { psx_trap(0x800A5EFCu); }  /* branch into delay slot: ['0x800a6478', '0x800a6710'] */

void g2_800A5F04(void) { psx_trap(0x800A5F04u); }  /* branch into delay slot: ['0x800a6478', '0x800a6710'] */

void g2_800A5F7C(void) { psx_trap(0x800A5F7Cu); }  /* branch into delay slot: ['0x800a6478', '0x800a6710'] */

void g2_800A607C(void) { psx_trap(0x800A607Cu); }  /* branch into delay slot: ['0x800a6478', '0x800a6710'] */

void g2_800A60C4(void) { psx_trap(0x800A60C4u); }  /* branch into delay slot: ['0x800a6478', '0x800a6710'] */

void g2_800A6334(void) { psx_trap(0x800A6334u); }  /* 0x800A6334: unsupported word 0xF9590901 (op=62, fn=1) */

void g2_800A63A4(void) { psx_trap(0x800A63A4u); }  /* 0x800A63A4: unsupported word 0xFFAD0121 (op=63, fn=33) */

void g2_800A643C(void) { psx_trap(0x800A643Cu); }  /* 0x800A643C: unsupported word 0x0022EEFF (op=0, fn=63) */

void g2_800A67BC(void) { psx_trap(0x800A67BCu); }  /* 0x800A67C4: unsupported word 0xD9D900C9 (op=54, fn=9) */

void g2_800A6894(void) { psx_trap(0x800A6894u); }  /* 0x800A6894: unsupported word 0x6975D1DF (op=26, fn=31) */

void g2_800A68A8(void) { psx_trap(0x800A68A8u); }  /* 0x800A68AC: unsupported word 0xE6AA0324 (op=57, fn=36) */

void g2_800A6910(void) { psx_trap(0x800A6910u); }  /* 0x800A6918: unsupported word 0x05159248 (op=1, fn=8) */

void g2_800A6970(void) { psx_trap(0x800A6970u); }  /* 0x800A6970: unsupported word 0xD9F3FFAA (op=54, fn=42) */

void g2_800A69D8(void) { psx_trap(0x800A69D8u); }  /* 0x800A69D8: unsupported word 0x061583D9 (op=1, fn=25) */

void g2_800A6B44(void) { psx_trap(0x800A6B44u); }  /* 0x800A6B50: unsupported word 0xF3FFEB02 (op=60, fn=2) */

void g2_800A6C58(void) { psx_trap(0x800A6C58u); }  /* 0x800A6C60: unsupported word 0x59A6AA04 (op=22, fn=4) */

void g2_800A6F68(void) { psx_trap(0x800A6F68u); }  /* 0x800A6F68: unsupported word 0xC02399FD (op=48, fn=61) */

void g2_800A6FC4(void) { psx_trap(0x800A6FC4u); }  /* 0x800A6FC8: unsupported word 0xFF16B441 (op=63, fn=1) */

void g2_800A6FEC(void) { psx_trap(0x800A6FECu); }  /* 0x800A6FEC: unsupported word 0x9C50F720 (op=39, fn=32) */

void g2_800A704C(void) { psx_trap(0x800A704Cu); }  /* 0x800A704C: unsupported word 0xB7730400 (op=45, fn=0) */

void g2_800A710C(void) { psx_trap(0x800A710Cu); }  /* 0x800A711C: unsupported word 0xCD03ABC5 (op=51, fn=5) */

void g2_800A71A4(void) { psx_trap(0x800A71A4u); }  /* 0x800A71A8: unsupported word 0x5FF9FFBA (op=23, fn=58) */

void g2_800A71E4(void) { psx_trap(0x800A71E4u); }  /* 0x800A71E4: unsupported word 0xC2FFFD79 (op=48, fn=57) */

void g2_800A7224(void) { psx_trap(0x800A7224u); }  /* 0x800A7228: unsupported word 0xFF28FFFF (op=63, fn=63) */

void g2_800A7290(void) { psx_trap(0x800A7290u); }  /* 0x800A7290: unsupported word 0xFFB49700 (op=63, fn=0) */

void g2_800A7294(void) { psx_trap(0x800A7294u); }  /* 0x800A7294: unsupported word 0x004BEBFF (op=0, fn=63) */

void g2_800A72F8(void) { psx_trap(0x800A72F8u); }  /* branch into delay slot: ['0x800a74dc', '0x800a7500', '0x800a7524', '0x800a7548', '0x800a75 */

void g2_800A77D0(void) { psx_trap(0x800A77D0u); }  /* 0x800A77D0: unsupported word 0xFD00FD00 (op=63, fn=0) */

void g2_800A7870(void) {
    (void)(R[2] >> 8);  /* 0x800A7870 */
    (void)(R[2] >> 8);  /* 0x800A7874 */
    (void)(R[2] << 8);  /* 0x800A7878 */
    (void)(R[2] >> 8);  /* 0x800A787C */
    (void)(R[2] >> 0);  /* 0x800A7880 */
    (void)(R[2] >> 8);  /* 0x800A7884 */
    (void)(R[0] >> 8);  /* 0x800A7888 */
    (void)(R[2] >> 8);  /* 0x800A788C */
    (void)(R[2] >> 8);  /* 0x800A7890 */
    (void)(R[2] >> 8);  /* 0x800A7894 */
    (void)(R[2] >> 8);  /* 0x800A7898 */
    (void)(R[2] << 8);  /* 0x800A789C */
    (void)(R[2] >> 8);  /* 0x800A78A0 */
    (void)(R[2] >> 0);  /* 0x800A78A4 */
    (void)(R[2] >> 8);  /* 0x800A78A8 */
    (void)(R[0] >> 8);  /* 0x800A78AC */
    (void)(R[2] >> 8);  /* 0x800A78B0 */
    (void)(R[2] >> 8);  /* 0x800A78B4 */
    psx_next = 0x800A78B8u; return;  /* fallthrough */
}

void g2_800A78B8(void) { psx_trap(0x800A78B8u); }  /* 0x800A7940: unsupported word 0x0018002C (op=0, fn=44) */

void g2_800A7930(void) { psx_trap(0x800A7930u); }  /* 0x800A7940: unsupported word 0x0018002C (op=0, fn=44) */

void g2_800A7944(void) { psx_trap(0x800A7944u); }  /* 0x800A7944: unsupported word 0x00C60001 (op=0, fn=1) */

void g2_800A797C(void) { psx_trap(0x800A797Cu); }  /* 0x800A797C: unsupported word 0x00020038 (op=0, fn=56) */

void g2_800A7990(void) { psx_trap(0x800A7990u); }  /* 0x800A7990: unsupported word 0x00CD0001 (op=0, fn=1) */

void g2_800A7A44(void) { psx_trap(0x800A7A44u); }  /* 0x800A7A48: unsupported word 0x00010056 (op=0, fn=22) */

void g2_800A7AD0(void) { psx_trap(0x800A7AD0u); }  /* 0x800A7AE0: unsupported word 0x0018002C (op=0, fn=44) */

void g2_800A7AE0(void) { psx_trap(0x800A7AE0u); }  /* 0x800A7AE0: unsupported word 0x0018002C (op=0, fn=44) */

void g2_800A7AE8(void) { psx_trap(0x800A7AE8u); }  /* 0x800A7B04: unsupported word 0x0046003B (op=0, fn=59) */

void g2_800A7AF8(void) { psx_trap(0x800A7AF8u); }  /* 0x800A7B04: unsupported word 0x0046003B (op=0, fn=59) */

void g2_800A7B1C(void) { psx_trap(0x800A7B1Cu); }  /* 0x800A7B28: unsupported word 0x007C002C (op=0, fn=44) */

void g2_800A7B28(void) { psx_trap(0x800A7B28u); }  /* 0x800A7B28: unsupported word 0x007C002C (op=0, fn=44) */

void g2_800A7B40(void) { psx_trap(0x800A7B40u); }  /* 0x800A7B40: unsupported word 0x0002006D (op=0, fn=45) */

void g2_800A7B60(void) { psx_trap(0x800A7B60u); }  /* 0x800A7B64: unsupported word 0x0002000B (op=0, fn=11) */

void g2_800A7BC4(void) { psx_trap(0x800A7BC4u); }  /* 0x800A7BDC: unsupported word 0x00020014 (op=0, fn=20) */

void g2_800A7CD0(void) { psx_trap(0x800A7CD0u); }  /* 0x800A7CDC: unsupported word 0x00260057 (op=0, fn=23) */

void g2_800A7DD0(void) { psx_trap(0x800A7DD0u); }  /* 0x800A7DD4: unsupported word 0x000800B4 (op=0, fn=52) */

void g2_800A7E0C(void) { psx_trap(0x800A7E0Cu); }  /* 0x800A7E10: unsupported word 0x001300AE (op=0, fn=46) */

void g2_800A7E90(void) { psx_trap(0x800A7E90u); }  /* 0x800A7E98: unsupported word 0x00D10001 (op=0, fn=1) */

void g2_800A7F68(void) { psx_trap(0x800A7F68u); }  /* 0x800A7F68: unsupported word 0x0001003B (op=0, fn=59) */

void g2_800A81A0(void) { psx_trap(0x800A81A0u); }  /* 0x800A81A4: unsupported word 0x000E0030 (op=0, fn=48) */

void g2_800A8268(void) { psx_trap(0x800A8268u); }  /* 0x800A8268: unsupported word 0x0005008E (op=0, fn=14) */

void g2_800A82EC(void) { psx_trap(0x800A82ECu); }  /* 0x800A82EC: unsupported word 0x0005000F (op=0, fn=15) */

void g2_800A85C0(void) { psx_trap(0x800A85C0u); }  /* 0x800A85C0: unsupported word 0x00050030 (op=0, fn=48) */

void g2_800A85D4(void) { psx_trap(0x800A85D4u); }  /* 0x800A85D4: unsupported word 0x00740005 (op=0, fn=5) */

void g2_800A86B8(void) { psx_trap(0x800A86B8u); }  /* 0x800A86B8: unsupported word 0x00B40001 (op=0, fn=1) */

void g2_800A86BC(void) { psx_trap(0x800A86BCu); }  /* 0x800A86BC: unsupported word 0x0001008A (op=0, fn=10) */

void g2_800A86E4(void) { psx_trap(0x800A86E4u); }  /* 0x800A86E4: unsupported word 0x00020038 (op=0, fn=56) */

void g2_800A8838(void) { psx_trap(0x800A8838u); }  /* 0x800A8838: unsupported word 0x000200B1 (op=0, fn=49) */

void g2_800A8874(void) { psx_trap(0x800A8874u); }  /* 0x800A88B4: unsupported word 0x000E0078 (op=0, fn=56) */

void g2_800A89D4(void) { psx_trap(0x800A89D4u); }  /* 0x800A89D4: unsupported word 0x003400E8 (op=0, fn=40) */

void g2_800A8A44(void) { psx_trap(0x800A8A44u); }  /* 0x800A8A58: unsupported word 0x005200F2 (op=0, fn=50) */

void g2_800A8C18(void) { psx_trap(0x800A8C18u); }  /* 0x800A8C38: unsupported word 0x009A00B8 (op=0, fn=56) */

void g2_800A8C58(void) { psx_trap(0x800A8C58u); }  /* 0x800A8C58: unsupported word 0x0002009E (op=0, fn=30) */

void g2_800A8C60(void) { psx_trap(0x800A8C60u); }  /* 0x800A8C70: unsupported word 0x000A0094 (op=0, fn=20) */

void g2_800A8D3C(void) { psx_trap(0x800A8D3Cu); }  /* 0x800A8D3C: unsupported word 0x000500AC (op=0, fn=44) */

void g2_800A8E50(void) { psx_trap(0x800A8E50u); }  /* 0x800A8E54: unsupported word 0x001800BE (op=0, fn=62) */

void g2_800A8F00(void) { psx_trap(0x800A8F00u); }  /* 0x800A8F00: unsupported word 0x00E00005 (op=0, fn=5) */

void g2_800A9148(void) { psx_trap(0x800A9148u); }  /* 0x800A9148: unsupported word 0x00040028 (op=0, fn=40) */

void g2_800A923C(void) { psx_trap(0x800A923Cu); }  /* 0x800A923C: unsupported word 0x0007003A (op=0, fn=58) */

void g2_800A9250(void) { psx_trap(0x800A9250u); }  /* 0x800A9258: unsupported word 0x0009006C (op=0, fn=44) */

void g2_800A925C(void) { psx_trap(0x800A925Cu); }  /* 0x800A9260: unsupported word 0x0007000A (op=0, fn=10) */

void g2_800A939C(void) { psx_trap(0x800A939Cu); }  /* 0x800A93A0: unsupported word 0x001F00B4 (op=0, fn=52) */

void g2_800A93D8(void) { psx_trap(0x800A93D8u); }  /* 0x800A93DC: unsupported word 0x0026002C (op=0, fn=44) */

void g2_800A9444(void) { psx_trap(0x800A9444u); }  /* 0x800A9444: unsupported word 0x00080038 (op=0, fn=56) */

void g2_800A94EC(void) { psx_trap(0x800A94ECu); }  /* 0x800A94EC: unsupported word 0x00030075 (op=0, fn=53) */

void g2_800A9510(void) { psx_trap(0x800A9510u); }  /* 0x800A9510: unsupported word 0x0003007B (op=0, fn=59) */

void g2_800A9534(void) { psx_trap(0x800A9534u); }  /* 0x800A9534: unsupported word 0x00030081 (op=0, fn=1) */

void g2_800A9584(void) { psx_trap(0x800A9584u); }  /* 0x800A9588: unsupported word 0x001A007D (op=0, fn=61) */

void g2_800A96C4(void) { psx_trap(0x800A96C4u); }  /* 0x800A96C8: unsupported word 0x0002008A (op=0, fn=10) */

void g2_800A9768(void) { psx_trap(0x800A9768u); }  /* 0x800A9768: unsupported word 0x0007005F (op=0, fn=31) */

void g2_800A97C4(void) { psx_trap(0x800A97C4u); }  /* 0x800A97E4: unsupported word 0x002A001D (op=0, fn=29) */

void g2_800A97E0(void) { psx_trap(0x800A97E0u); }  /* 0x800A97E4: unsupported word 0x002A001D (op=0, fn=29) */

void g2_800A99A4(void) { psx_trap(0x800A99A4u); }  /* 0x800A99B0: unsupported word 0x00090015 (op=0, fn=21) */

void g2_800A99B4(void) { psx_trap(0x800A99B4u); }  /* 0x800A99B4: unsupported word 0x0016003C (op=0, fn=60) */

void g2_800A99C0(void) { psx_trap(0x800A99C0u); }  /* 0x800A99C0: unsupported word 0x00230016 (op=0, fn=22) */

void g2_800A99CC(void) { psx_trap(0x800A99CCu); }  /* 0x800A99CC: unsupported word 0x002A002C (op=0, fn=44) */

void g2_800A99D8(void) { psx_trap(0x800A99D8u); }  /* 0x800A99D8: unsupported word 0x00360037 (op=0, fn=55) */

void g2_800A99E4(void) { psx_trap(0x800A99E4u); }  /* bad delay slot at 0x800A99F0 */

void g2_800A99F0(void) { psx_trap(0x800A99F0u); }  /* bad delay slot at 0x800A99F0 */

void g2_800A99FC(void) { psx_trap(0x800A99FCu); }  /* 0x800A99FC: unsupported word 0x007A000F (op=0, fn=15) */

void g2_800A9A08(void) { psx_trap(0x800A9A08u); }  /* 0x800A9A08: unsupported word 0x008B0096 (op=0, fn=22) */

void g2_800A9A14(void) { psx_trap(0x800A9A14u); }  /* 0x800A9A14: unsupported word 0x009800BF (op=0, fn=63) */

void g2_800A9A18(void) { psx_trap(0x800A9A18u); }  /* 0x800A9A18: unsupported word 0x0009002D (op=0, fn=45) */

void g2_800A9A28(void) { psx_trap(0x800A9A28u); }  /* 0x800A9A30: unsupported word 0x0006000F (op=0, fn=15) */

void g2_800A9A54(void) { psx_trap(0x800A9A54u); }  /* 0x800A9A54: unsupported word 0x0006001C (op=0, fn=28) */

void g2_800A9AA0(void) { psx_trap(0x800A9AA0u); }  /* 0x800A9AA0: unsupported word 0x004C001E (op=0, fn=30) */

void g2_800A9AE8(void) { psx_trap(0x800A9AE8u); }  /* 0x800A9AFC: unsupported word 0x00060085 (op=0, fn=5) */

void g2_800A9B18(void) { psx_trap(0x800A9B18u); }  /* 0x800A9B24: unsupported word 0x00950017 (op=0, fn=23) */

void g2_800A9B24(void) { psx_trap(0x800A9B24u); }  /* 0x800A9B24: unsupported word 0x00950017 (op=0, fn=23) */

void g2_800A9B28(void) { psx_trap(0x800A9B28u); }  /* 0x800A9B28: unsupported word 0x00040039 (op=0, fn=57) */

void g2_800A9B4C(void) { psx_trap(0x800A9B4Cu); }  /* 0x800A9B4C: unsupported word 0x00040028 (op=0, fn=40) */

void g2_800A9C80(void) { psx_trap(0x800A9C80u); }  /* 0x800A9C80: unsupported word 0x000600B0 (op=0, fn=48) */

void g2_800A9DC4(void) { psx_trap(0x800A9DC4u); }  /* 0x800A9DC4: unsupported word 0x00060035 (op=0, fn=53) */

void g2_800A9DD0(void) { psx_trap(0x800A9DD0u); }  /* 0x800A9DD0: unsupported word 0x00060036 (op=0, fn=54) */

void g2_800A9DDC(void) { psx_trap(0x800A9DDCu); }  /* 0x800A9DDC: unsupported word 0x00060036 (op=0, fn=54) */

void g2_800A9E2C(void) { psx_trap(0x800A9E2Cu); }  /* 0x800A9E34: unsupported word 0x00400031 (op=0, fn=49) */

void g2_800A9E98(void) { psx_trap(0x800A9E98u); }  /* 0x800A9E9C: unsupported word 0x0006004A (op=0, fn=10) */

void g2_800A9EB4(void) { psx_trap(0x800A9EB4u); }  /* 0x800A9EB4: unsupported word 0x0006004E (op=0, fn=14) */

void g2_800A9ED4(void) { psx_trap(0x800A9ED4u); }  /* 0x800A9EDC: unsupported word 0x00580030 (op=0, fn=48) */

void g2_800A9F08(void) { psx_trap(0x800A9F08u); }  /* 0x800A9F0C: unsupported word 0x005C0028 (op=0, fn=40) */

void g2_800AA0A4(void) { psx_trap(0x800AA0A4u); }  /* 0x800AA0A4: unsupported word 0x0007006C (op=0, fn=44) */

void g2_800AA0EC(void) { psx_trap(0x800AA0ECu); }  /* 0x800AA104: unsupported word 0x00070028 (op=0, fn=40) */

void g2_800AA330(void) { psx_trap(0x800AA330u); }  /* 0x800AA340: unsupported word 0x000400F4 (op=0, fn=52) */

void g2_800AA380(void) { psx_trap(0x800AA380u); }  /* 0x800AA388: unsupported word 0x000800DE (op=0, fn=30) */

void g2_800AA508(void) { psx_trap(0x800AA508u); }  /* 0x800AA508: unsupported word 0x0022001C (op=0, fn=28) */

void g2_800AA7EC(void) { psx_trap(0x800AA7ECu); }  /* 0x800AA7FC: unsupported word 0x0048002C (op=0, fn=44) */

void g2_800AA890(void) { psx_trap(0x800AA890u); }  /* 0x800AA894: unsupported word 0x0008008B (op=0, fn=11) */

void g2_800AA8A4(void) { psx_trap(0x800AA8A4u); }  /* 0x800AA8A8: unsupported word 0x0009000B (op=0, fn=11) */

void g2_800AA8AC(void) { psx_trap(0x800AA8ACu); }  /* 0x800AA8B4: unsupported word 0x0008000B (op=0, fn=11) */

void g2_800AA8B8(void) { psx_trap(0x800AA8B8u); }  /* 0x800AA8B8: unsupported word 0x000E005F (op=0, fn=31) */

void g2_800AA8D0(void) { psx_trap(0x800AA8D0u); }  /* 0x800AA8DC: unsupported word 0x001200EC (op=0, fn=44) */

void g2_800AA8DC(void) { psx_trap(0x800AA8DCu); }  /* 0x800AA8DC: unsupported word 0x001200EC (op=0, fn=44) */

void g2_800AA918(void) { psx_trap(0x800AA918u); }  /* 0x800AA924: unsupported word 0x001900E9 (op=0, fn=41) */

void g2_800AA924(void) { psx_trap(0x800AA924u); }  /* 0x800AA924: unsupported word 0x001900E9 (op=0, fn=41) */

void g2_800AAA24(void) { psx_trap(0x800AAA24u); }  /* 0x800AAA34: unsupported word 0x00080055 (op=0, fn=21) */

void g2_800AAA70(void) { psx_trap(0x800AAA70u); }  /* bad delay slot at 0x800AAA80 */

void g2_800AAA88(void) { psx_trap(0x800AAA88u); }  /* 0x800AAA8C: unsupported word 0x006B00B5 (op=0, fn=53) */

void g2_800AAB60(void) { psx_trap(0x800AAB60u); }  /* 0x800AAB60: unsupported word 0x00090085 (op=0, fn=5) */

void g2_800AAB70(void) { psx_trap(0x800AAB70u); }  /* 0x800AAB70: unsupported word 0x0086006F (op=0, fn=47) */

void g2_800AAB88(void) { psx_trap(0x800AAB88u); }  /* bad delay slot at 0x800AAB98 */

void g2_800AABC4(void) { psx_trap(0x800AABC4u); }  /* 0x800AABC4: unsupported word 0x008D00DC (op=0, fn=28) */

void g2_800AABD0(void) { psx_trap(0x800AABD0u); }  /* 0x800AABE4: unsupported word 0x00090094 (op=0, fn=20) */

void g2_800AABE8(void) { psx_trap(0x800AABE8u); }  /* 0x800AABE8: unsupported word 0x0094001F (op=0, fn=31) */

void g2_800AABF4(void) { psx_trap(0x800AABF4u); }  /* 0x800AABF4: unsupported word 0x009400E9 (op=0, fn=41) */

void g2_800AABF8(void) { psx_trap(0x800AABF8u); }  /* 0x800AABF8: unsupported word 0x0001009D (op=0, fn=29) */

void g2_800AACEC(void) { psx_trap(0x800AACECu); }  /* 0x800AACF0: unsupported word 0x00BC0001 (op=0, fn=1) */

void g2_800AAF60(void) { psx_trap(0x800AAF60u); }  /* 0x800AAF60: unsupported word 0x009B0001 (op=0, fn=1) */

void g2_800AAFA8(void) { psx_trap(0x800AAFA8u); }  /* 0x800AAFDC: unsupported word 0x000C0032 (op=0, fn=50) */

void g2_800AB0D8(void) { psx_trap(0x800AB0D8u); }  /* 0x800AB0F8: unsupported word 0x0007000F (op=0, fn=15) */

void g2_800AB100(void) { psx_trap(0x800AB100u); }  /* 0x800AB108: unsupported word 0x00130016 (op=0, fn=22) */

void g2_800AB204(void) { psx_trap(0x800AB204u); }  /* 0x800AB204: unsupported word 0x001300BE (op=0, fn=62) */

void g2_800AB43C(void) { psx_trap(0x800AB43Cu); }  /* 0x800AB444: unsupported word 0x0093007E (op=0, fn=62) */

void g2_800AB4EC(void) { psx_trap(0x800AB4ECu); }  /* 0x800AB4FC: unsupported word 0x0005006C (op=0, fn=44) */
