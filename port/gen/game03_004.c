#include "game03_decls.h"

void g3_80088380(void) { psx_trap(0x80088380u); }  /* 0x80088384: unsupported word 0x7852002F (op=30, fn=47) */

void g3_800883A0(void) { psx_trap(0x800883A0u); }  /* 0x800883A0: unsupported word 0x66785200 (op=25, fn=0) */

void g3_800883D8(void) { psx_trap(0x800883D8u); }  /* branch into delay slot: ['0x800883ec'] */

void g3_80088408(void) { psx_trap(0x80088408u); }  /* 0x80088408: unsupported word 0x46006467 (op=17, fn=39) */

void g3_80088410(void) { psx_trap(0x80088410u); }  /* 0x80088418: unsupported word 0x6467A520 (op=25, fn=32) */

void g3_80088488(void) { psx_trap(0x80088488u); }  /* 0x80088488: unsupported word 0x7A502E2F (op=30, fn=47) */

void g3_800884F0(void) { psx_trap(0x800884F0u); }  /* 0x800884FC: unsupported word 0xBCEC0CCA (op=47, fn=10) */

void g3_80088530(void) {
    { gte_data_write(0, lw_(R[16] + -21588)); psx_next = 0x89D89158u; return; }  /* 0x80088530 j extern */
}

void g3_80088538(void) { psx_trap(0x80088538u); }  /* 0x80088538: unsupported word 0xCE8EBEDB (op=51, fn=27) */

void g3_8008856C(void) { psx_trap(0x8008856Cu); }  /* 0x80088570: unsupported word 0x67765346 (op=25, fn=6) */

void g3_80088590(void) { psx_trap(0x80088590u); }  /* 0x80088590: unsupported word 0xBCEDBBBF (op=47, fn=63) */

void g3_800885A0(void) { psx_trap(0x800885A0u); }  /* 0x800885A0: unsupported word 0x65434694 (op=25, fn=20) */

void g3_800885E0(void) { psx_trap(0x800885E0u); }  /* 0x800885E0: unsupported word 0x43003467 (op=16, fn=39) */

void g3_80088618(void) { psx_trap(0x80088618u); }  /* 0x80088618: unsupported word 0x00000B78 (op=0, fn=56) */

void g3_80088698(void) { psx_trap(0x80088698u); }  /* 0x80088698: unsupported word 0xF433334F (op=61, fn=15) */

void g3_80088700(void) { psx_trap(0x80088700u); }  /* 0x80088700: unsupported word 0x6B542246 (op=26, fn=6) */

void g3_80088704(void) { psx_trap(0x80088704u); }  /* 0x80088714: unsupported word 0x76760007 (op=29, fn=7) */

void g3_80088748(void) { psx_trap(0x80088748u); }  /* 0x80088748: unsupported word 0x68B66B86 (op=26, fn=6) */

void g3_80088760(void) { psx_trap(0x80088760u); }  /* 0x80088760: unsupported word 0x76044338 (op=29, fn=56) */

void g3_800887B4(void) { psx_trap(0x800887B4u); }  /* 0x800887B4: unsupported word 0xCCB77764 (op=51, fn=36) */

void g3_80088848(void) { psx_trap(0x80088848u); }  /* 0x80088848: unsupported word 0x52F789B0 (op=20, fn=48) */

void g3_800888B4(void) { psx_trap(0x800888B4u); }  /* 0x800888B8: unsupported word 0x6700001E (op=25, fn=30) */

void g3_80088958(void) { psx_trap(0x80088958u); }  /* 0x80088960: unsupported word 0x02150BB0 (op=0, fn=48) */

void g3_80088960(void) { psx_trap(0x80088960u); }  /* 0x80088960: unsupported word 0x02150BB0 (op=0, fn=48) */

void g3_80088994(void) { psx_trap(0x80088994u); }  /* 0x8008899C: unsupported word 0xB0000425 (op=44, fn=37) */

void g3_8008899C(void) { psx_trap(0x8008899Cu); }  /* 0x8008899C: unsupported word 0xB0000425 (op=44, fn=37) */

void g3_800889DC(void) { psx_trap(0x800889DCu); }  /* 0x800889DC: unsupported word 0x000214BB (op=0, fn=59) */

void g3_800889F4(void) { psx_trap(0x800889F4u); }  /* 0x800889F8: unsupported word 0x69B99999 (op=26, fn=25) */

void g3_80088A04(void) { psx_trap(0x80088A04u); }  /* branch into delay slot: ['0x80088b18'] */

void g3_80088A30(void) { psx_trap(0x80088A30u); }  /* branch into delay slot: ['0x80088b18'] */

void g3_80088A38(void) { psx_trap(0x80088A38u); }  /* branch into delay slot: ['0x80088b18'] */

void g3_80088AD4(void) { psx_trap(0x80088AD4u); }  /* branch into delay slot: ['0x80088b18'] */

void g3_80088B28(void) { psx_trap(0x80088B28u); }  /* 0x80088B28: unsupported word 0x42010084 (op=16, fn=4) */

void g3_80088B4C(void) { psx_trap(0x80088B4Cu); }  /* 0x80088B4C: unsupported word 0x0207FCFF (op=0, fn=63) */

void g3_80088BDC(void) { psx_trap(0x80088BDCu); }  /* 0x80088BDC: unsupported word 0x07093233 (op=1, fn=51) */

void g3_80088C24(void) { psx_trap(0x80088C24u); }  /* 0x80088C24: unsupported word 0x00041F5E (op=0, fn=30) */

void g3_80088C6C(void) { psx_trap(0x80088C6Cu); }  /* 0x80088C6C: unsupported word 0xEDA99000 (op=59, fn=0) */

void g3_80088CB8(void) { psx_trap(0x80088CB8u); }  /* 0x80088CB8: unsupported word 0x0000215C (op=0, fn=28) */

void g3_80088DCC(void) { psx_trap(0x80088DCCu); }  /* 0x80088DDC: unsupported word 0x545000C5 (op=21, fn=5) */

void g3_80088DF8(void) { psx_trap(0x80088DF8u); }  /* 0x80088DF8: unsupported word 0xDBCBDEED (op=54, fn=45) */

void g3_80088E0C(void) { psx_trap(0x80088E0Cu); }  /* 0x80088E0C: unsupported word 0xC00CDACA (op=48, fn=10) */

void g3_80088E1C(void) { psx_trap(0x80088E1Cu); }  /* 0x80088E28: unsupported word 0x00DB878A (op=0, fn=10) */

void g3_80088E28(void) { psx_trap(0x80088E28u); }  /* 0x80088E28: unsupported word 0x00DB878A (op=0, fn=10) */

void g3_80088E4C(void) { psx_trap(0x80088E4Cu); }  /* 0x80088E54: unsupported word 0xCCDDDDBC (op=51, fn=60) */

void g3_80088E70(void) { psx_trap(0x80088E70u); }  /* 0x80088E70: unsupported word 0xD9CBDDDD (op=54, fn=29) */

void g3_80088E74(void) { psx_trap(0x80088E74u); }  /* 0x80088E7C: unsupported word 0xCED00CD9 (op=51, fn=25) */

void g3_80088ED8(void) { psx_trap(0x80088ED8u); }  /* 0x80088EDC: unsupported word 0xCCBDEC0B (op=51, fn=11) */

void g3_80088F44(void) { psx_trap(0x80088F44u); }  /* 0x80088F48: unsupported word 0xCC9CED0A (op=51, fn=10) */

void g3_80088F6C(void) { psx_trap(0x80088F6Cu); }  /* 0x80088F6C: unsupported word 0x50009BA9 (op=20, fn=41) */

void g3_80089060(void) { psx_trap(0x80089060u); }  /* 0x80089064: unsupported word 0x0042002F (op=0, fn=47) */

void g3_80089064(void) { psx_trap(0x80089064u); }  /* 0x80089064: unsupported word 0x0042002F (op=0, fn=47) */

void g3_80089134(void) { psx_trap(0x80089134u); }  /* 0x80089134: unsupported word 0xB0409CB9 (op=44, fn=57) */

void g3_80089160(void) { psx_trap(0x80089160u); }  /* 0x80089168: unsupported word 0x5F499999 (op=23, fn=25) */

void g3_8008918C(void) { psx_trap(0x8008918Cu); }  /* 0x8008919C: unsupported word 0x64444446 (op=25, fn=6) */

void g3_80089198(void) { psx_trap(0x80089198u); }  /* 0x8008919C: unsupported word 0x64444446 (op=25, fn=6) */

void g3_800891DC(void) { psx_trap(0x800891DCu); }  /* 0x800891E0: unsupported word 0x0001149F (op=0, fn=31) */

void g3_8008925C(void) { psx_trap(0x8008925Cu); }  /* 0x80089260: unsupported word 0x78700402 (op=30, fn=2) */

void g3_800892C8(void) { psx_trap(0x800892C8u); }  /* 0x800892CC: unsupported word 0x50214999 (op=20, fn=25) */

void g3_800892DC(void) { psx_trap(0x800892DCu); }  /* 0x800892DC: unsupported word 0x010E9494 (op=0, fn=20) */

void g3_800892F0(void) { psx_trap(0x800892F0u); }  /* 0x800892F0: unsupported word 0x66666678 (op=25, fn=56) */

void g3_800892FC(void) { psx_trap(0x800892FCu); }  /* 0x800892FC: unsupported word 0x60000009 (op=24, fn=9) */

void g3_8008933C(void) { psx_trap(0x8008933Cu); }  /* 0x80089348: unsupported word 0x4299099A (op=16, fn=26) */

void g3_80089374(void) { psx_trap(0x80089374u); }  /* 0x80089374: unsupported word 0x000E049C (op=0, fn=28) */

void g3_80089398(void) { psx_trap(0x80089398u); }  /* bad delay slot at 0x80089398 */

void g3_800893BC(void) { psx_trap(0x800893BCu); }  /* branch into delay slot: ['0x800893c0'] */

void g3_800893C8(void) { psx_trap(0x800893C8u); }  /* 0x800893C8: unsupported word 0x010E84BC (op=0, fn=60) */

void g3_800893F8(void) { psx_trap(0x800893F8u); }  /* 0x800893FC: unsupported word 0x0347ACDC (op=0, fn=28) */

void g3_8008942C(void) { psx_trap(0x8008942Cu); }  /* 0x8008942C: unsupported word 0x440333BC (op=17, fn=60) */

void g3_800894A4(void) { psx_trap(0x800894A4u); }  /* 0x800894A4: unsupported word 0x6BAA9002 (op=26, fn=2) */

void g3_80089548(void) { psx_trap(0x80089548u); }  /* 0x80089554: unsupported word 0xCC0000CC (op=51, fn=12) */

void g3_80089584(void) { psx_trap(0x80089584u); }  /* 0x80089588: unsupported word 0xDDCB004E (op=55, fn=14) */

void g3_80089640(void) { psx_trap(0x80089640u); }  /* 0x80089644: unsupported word 0xCD40A889 (op=51, fn=9) */

void g3_80089660(void) { psx_trap(0x80089660u); }  /* 0x80089664: unsupported word 0xDA888908 (op=54, fn=8) */

void g3_80089690(void) { psx_trap(0x80089690u); }  /* 0x800896A4: unsupported word 0x06040006 (op=1, fn=6) */

void g3_80089728(void) { psx_trap(0x80089728u); }  /* 0x80089728: unsupported word 0x04336600 (op=1, fn=0) */

void g3_80089760(void) { psx_trap(0x80089760u); }  /* 0x80089760: unsupported word 0x03AD4554 (op=0, fn=20) */

void g3_8008987C(void) { psx_trap(0x8008987Cu); }  /* 0x8008987C: unsupported word 0x50002A05 (op=20, fn=5) */

void g3_800898B4(void) { psx_trap(0x800898B4u); }  /* 0x800898B8: unsupported word 0xBCCB0009 (op=47, fn=9) */

void g3_80089900(void) { psx_trap(0x80089900u); }  /* 0x80089900: unsupported word 0x0502042D (op=1, fn=45) */

void g3_8008994C(void) { psx_trap(0x8008994Cu); }  /* bad delay slot at 0x8008994C */

void g3_80089A04(void) { psx_trap(0x80089A04u); }  /* 0x80089A08: unsupported word 0xDEEBFED0 (op=55, fn=16) */

void g3_80089ACC(void) { psx_trap(0x80089ACCu); }  /* 0x80089AD4: unsupported word 0x003E0ABA (op=0, fn=58) */

void g3_80089AE4(void) { psx_trap(0x80089AE4u); }  /* 0x80089AE4: unsupported word 0x5E0ABAAA (op=23, fn=42) */

void g3_80089AF8(void) { psx_trap(0x80089AF8u); }  /* 0x80089B00: unsupported word 0x012EA9BC (op=0, fn=60) */

void g3_80089B00(void) { psx_trap(0x80089B00u); }  /* 0x80089B00: unsupported word 0x012EA9BC (op=0, fn=60) */

void g3_80089BB0(void) { psx_trap(0x80089BB0u); }  /* 0x80089BB0: unsupported word 0x05064949 (op=1, fn=9) */

void g3_80089BE0(void) { psx_trap(0x80089BE0u); }  /* 0x80089BEC: unsupported word 0x0000045F (op=0, fn=31) */

void g3_80089D68(void) { psx_trap(0x80089D68u); }  /* 0x80089D6C: unsupported word 0xDDB90000 (op=55, fn=0) */

void g3_80089D70(void) { psx_trap(0x80089D70u); }  /* 0x80089D70: unsupported word 0xF900A9AB (op=62, fn=43) */

void g3_80089E3C(void) { psx_trap(0x80089E3Cu); }  /* 0x80089E3C: unsupported word 0x40ABA5F8 (op=16, fn=56) */

void g3_80089F2C(void) { psx_trap(0x80089F2Cu); }  /* 0x80089F2C: unsupported word 0xDC00049B (op=55, fn=27) */

void g3_8008A078(void) { psx_trap(0x8008A078u); }  /* 0x8008A078: unsupported word 0x5744F403 (op=21, fn=3) */

void g3_8008A128(void) { psx_trap(0x8008A128u); }  /* 0x8008A140: unsupported word 0x6666699A (op=25, fn=26) */

void g3_8008A130(void) { psx_trap(0x8008A130u); }  /* 0x8008A140: unsupported word 0x6666699A (op=25, fn=26) */

void g3_8008A16C(void) { psx_trap(0x8008A16Cu); }  /* 0x8008A16C: unsupported word 0x06454150 (op=1, fn=16) */

void g3_8008A220(void) { psx_trap(0x8008A220u); }  /* 0x8008A220: unsupported word 0xB0033C9A (op=44, fn=26) */

void g3_8008A26C(void) { psx_trap(0x8008A26Cu); }  /* 0x8008A28C: unsupported word 0xD9A00000 (op=54, fn=0) */

void g3_8008A280(void) { psx_trap(0x8008A280u); }  /* 0x8008A28C: unsupported word 0xD9A00000 (op=54, fn=0) */

void g3_8008A2C4(void) { psx_trap(0x8008A2C4u); }  /* 0x8008A2C4: unsupported word 0x0098DCA9 (op=0, fn=41) */

void g3_8008A2D0(void) { psx_trap(0x8008A2D0u); }  /* 0x8008A2D0: unsupported word 0x07070B60 (op=1, fn=32) */

void g3_8008A2F4(void) { psx_trap(0x8008A2F4u); }  /* 0x8008A2F4: unsupported word 0xCDA98899 (op=51, fn=25) */

void g3_8008A2F8(void) { psx_trap(0x8008A2F8u); }  /* 0x8008A308: unsupported word 0xDACA988A (op=54, fn=10) */

void g3_8008A36C(void) { psx_trap(0x8008A36Cu); }  /* 0x8008A370: unsupported word 0x00EE004E (op=0, fn=14) */

void g3_8008A3E4(void) { psx_trap(0x8008A3E4u); }  /* 0x8008A3EC: unsupported word 0xFCCACFFB (op=63, fn=59) */

void g3_8008A42C(void) { psx_trap(0x8008A42Cu); }  /* 0x8008A42C: unsupported word 0x770887B0 (op=29, fn=48) */

void g3_8008A50C(void) { psx_trap(0x8008A50Cu); }  /* 0x8008A510: unsupported word 0xC000004E (op=48, fn=14) */

void g3_8008A530(void) { psx_trap(0x8008A530u); }  /* 0x8008A534: unsupported word 0xD66BC000 (op=53, fn=0) */

void g3_8008A54C(void) { psx_trap(0x8008A54Cu); }  /* 0x8008A54C: unsupported word 0x00000736 (op=0, fn=54) */

void g3_8008A590(void) { psx_trap(0x8008A590u); }  /* 0x8008A590: unsupported word 0x73333300 (op=28, fn=0) */

void g3_8008A5D4(void) { psx_trap(0x8008A5D4u); }  /* 0x8008A5D4: unsupported word 0x44000000 (op=17, fn=0) */

void g3_8008A640(void) { psx_trap(0x8008A640u); }  /* 0x8008A640: unsupported word 0xFFD0032C (op=63, fn=44) */

void g3_8008A680(void) { psx_trap(0x8008A680u); }  /* 0x8008A68C: unsupported word 0xFCCDE00C (op=63, fn=12) */

void g3_8008A69C(void) { psx_trap(0x8008A69Cu); }  /* bad delay slot at 0x8008A69C */

void g3_8008A6A4(void) { psx_trap(0x8008A6A4u); }  /* bad delay slot at 0x8008A6A4 */

void g3_8008A6A8(void) { psx_trap(0x8008A6A8u); }  /* 0x8008A6AC: unsupported word 0xBCD00000 (op=47, fn=0) */

void g3_8008A6AC(void) { psx_trap(0x8008A6ACu); }  /* 0x8008A6AC: unsupported word 0xBCD00000 (op=47, fn=0) */

void g3_8008A6D0(void) { psx_trap(0x8008A6D0u); }  /* 0x8008A6D4: unsupported word 0xE000000B (op=56, fn=11) */

void g3_8008A6F4(void) { psx_trap(0x8008A6F4u); }  /* 0x8008A700: unsupported word 0x040C844E (op=1, fn=14) */

void g3_8008A700(void) { psx_trap(0x8008A700u); }  /* 0x8008A700: unsupported word 0x040C844E (op=1, fn=14) */

void g3_8008A734(void) { psx_trap(0x8008A734u); }  /* bad delay slot at 0x8008A740 */

void g3_8008A740(void) { psx_trap(0x8008A740u); }  /* bad delay slot at 0x8008A740 */

void g3_8008A748(void) { psx_trap(0x8008A748u); }  /* bad delay slot at 0x8008A74C */

void g3_8008A74C(void) { psx_trap(0x8008A74Cu); }  /* bad delay slot at 0x8008A74C */

void g3_8008A758(void) { psx_trap(0x8008A758u); }  /* 0x8008A758: unsupported word 0x7024032A (op=28, fn=42) */

void g3_8008A75C(void) { psx_trap(0x8008A75Cu); }  /* 0x8008A75C: unsupported word 0x70030206 (op=28, fn=6) */

void g3_8008A7AC(void) { psx_trap(0x8008A7ACu); }  /* 0x8008A7AC: unsupported word 0xC1100433 (op=48, fn=51) */

void g3_8008A9B0(void) { psx_trap(0x8008A9B0u); }  /* 0x8008A9B0: unsupported word 0xC0BCDA08 (op=48, fn=8) */

void g3_8008A9E8(void) {
    { uint32_t _c = (R[6] != R[13]); sw_(R[8] + -16360, R[0]); if (_c) { psx_next = 0x80072150u; return; } }  /* 0x8008A9E8 b extern */
    psx_next = 0x8008A9F0u; return;  /* fallthrough */
}

void g3_8008A9F0(void) { psx_trap(0x8008A9F0u); }  /* 0x8008A9F0: unsupported word 0xCCF9D99C (op=51, fn=28) */

void g3_8008AA54(void) { psx_trap(0x8008AA54u); }  /* 0x8008AA54: unsupported word 0x59EC0219 (op=22, fn=25) */

void g3_8008AAB4(void) { psx_trap(0x8008AAB4u); }  /* 0x8008AAB4: unsupported word 0x9CED2202 (op=39, fn=2) */

void g3_8008AB4C(void) { psx_trap(0x8008AB4Cu); }  /* 0x8008AB50: unsupported word 0x4FB9A005 (op=19, fn=5) */

void g3_8008AC80(void) { psx_trap(0x8008AC80u); }  /* 0x8008AC80: unsupported word 0xB0AA955A (op=44, fn=26) */

void g3_8008ACA8(void) { psx_trap(0x8008ACA8u); }  /* 0x8008ACAC: unsupported word 0x04ACBDDD (op=1, fn=29) */

void g3_8008ADB0(void) { psx_trap(0x8008ADB0u); }  /* 0x8008ADB0: unsupported word 0xD0040100 (op=52, fn=0) */

void g3_8008AEC0(void) { psx_trap(0x8008AEC0u); }  /* branch into delay slot: ['0x8008af2c'] */

void g3_8008AF50(void) { psx_trap(0x8008AF50u); }  /* 0x8008AF54: unsupported word 0x61110016 (op=24, fn=22) */

void g3_8008AF90(void) { psx_trap(0x8008AF90u); }  /* 0x8008AF90: unsupported word 0x55505BCB (op=21, fn=11) */

void g3_8008B068(void) { psx_trap(0x8008B068u); }  /* 0x8008B068: unsupported word 0x030455B5 (op=0, fn=53) */

void g3_8008B0D0(void) { psx_trap(0x8008B0D0u); }  /* 0x8008B0D0: unsupported word 0x425F5003 (op=16, fn=3) */

void g3_8008B0D4(void) { psx_trap(0x8008B0D4u); }  /* 0x8008B0E0: unsupported word 0xBCCB0004 (op=47, fn=4) */

void g3_8008B114(void) { psx_trap(0x8008B114u); }  /* 0x8008B114: unsupported word 0x060CDAAD (op=1, fn=45) */

void g3_8008B124(void) { psx_trap(0x8008B124u); }  /* 0x8008B124: unsupported word 0x43AAAA9B (op=16, fn=27) */

void g3_8008B1B0(void) { psx_trap(0x8008B1B0u); }  /* 0x8008B1B0: unsupported word 0xDA888CC8 (op=54, fn=8) */

void g3_8008B1D0(void) { psx_trap(0x8008B1D0u); }  /* 0x8008B1D0: unsupported word 0x9D08D988 (op=39, fn=8) */

void g3_8008B208(void) { psx_trap(0x8008B208u); }  /* 0x8008B21C: unsupported word 0x4D300CC3 (op=19, fn=3) */

void g3_8008B300(void) { psx_trap(0x8008B300u); }  /* 0x8008B300: unsupported word 0x70003678 (op=28, fn=56) */

void g3_8008B33C(void) { psx_trap(0x8008B33Cu); }  /* 0x8008B33C: unsupported word 0xBCCB0043 (op=47, fn=3) */

void g3_8008B364(void) { psx_trap(0x8008B364u); }  /* 0x8008B36C: unsupported word 0x73477449 (op=28, fn=9) */

void g3_8008B3A0(void) { psx_trap(0x8008B3A0u); }  /* 0x8008B3A4: unsupported word 0xBCCC5445 (op=47, fn=5) */
