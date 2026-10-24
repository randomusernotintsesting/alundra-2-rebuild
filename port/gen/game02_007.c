#include "game02_decls.h"

void g2_80090D70(void) { psx_trap(0x80090D70u); }  /* bad delay slot at 0x80090D7C */

void g2_80090ECC(void) { psx_trap(0x80090ECCu); }  /* bad delay slot at 0x80090ECC */

void g2_80090F00(void) { psx_trap(0x80090F00u); }  /* 0x80090F00: unsupported word 0xDF06D5DE (op=55, fn=30) */

void g2_80090F94(void) { psx_trap(0x80090F94u); }  /* 0x80090F94: unsupported word 0x7D017BE0 (op=31, fn=32) */

void g2_80091008(void) { psx_trap(0x80091008u); }  /* 0x80091008: unsupported word 0x027C0175 (op=0, fn=53) */

void g2_80091084(void) { psx_trap(0x80091084u); }  /* bad delay slot at 0x80091088 */

void g2_800910D4(void) { psx_trap(0x800910D4u); }  /* 0x800910D4: unsupported word 0x05060406 (op=1, fn=6) */

void g2_800910E0(void) { psx_trap(0x800910E0u); }  /* 0x800910E4: unsupported word 0x07070721 (op=1, fn=33) */

void g2_80091238(void) { psx_trap(0x80091238u); }  /* 0x80091248: unsupported word 0x02420715 (op=0, fn=21) */

void g2_80091260(void) { psx_trap(0x80091260u); }  /* 0x80091284: unsupported word 0x00A4803F (op=0, fn=63) */

void g2_80091268(void) { psx_trap(0x80091268u); }  /* 0x80091284: unsupported word 0x00A4803F (op=0, fn=63) */

void g2_800912EC(void) { psx_trap(0x800912ECu); }  /* 0x800912F0: unsupported word 0x01161414 (op=0, fn=20) */

void g2_80091328(void) { psx_trap(0x80091328u); }  /* 0x80091338: unsupported word 0xBF333332 (op=47, fn=50) */

void g2_8009134C(void) {
    R[31] = R[0] << 20;  /* 0x8009134C */
    (void)(R[24] & R[23]);  /* 0x80091350 */
    { uint32_t _c = (R[16] != R[0]); R[2] = R[8] + 27; if (_c) { psx_next = 0x80094778u; return; } }  /* 0x80091354 b extern */
    psx_next = 0x8009135Cu; return;  /* fallthrough */
}

void g2_8009135C(void) { psx_trap(0x8009135Cu); }  /* 0x80091364: unsupported word 0x50004400 (op=20, fn=0) */

void g2_800913E8(void) { psx_trap(0x800913E8u); }  /* bad delay slot at 0x800913EC */

void g2_80091474(void) { psx_trap(0x80091474u); }  /* 0x80091474: unsupported word 0x65006500 (op=25, fn=0) */

void g2_800914F4(void) { psx_trap(0x800914F4u); }  /* 0x800914F4: unsupported word 0x69056500 (op=26, fn=0) */

void g2_800915A0(void) { psx_trap(0x800915A0u); }  /* 0x800915A0: unsupported word 0x0090028A (op=0, fn=10) */

void g2_80091660(void) { psx_trap(0x80091660u); }  /* 0x80091660: unsupported word 0x43430443 (op=16, fn=3) */

void g2_800916A0(void) { psx_trap(0x800916A0u); }  /* 0x800916A4: unsupported word 0x0708590F (op=1, fn=15) */

void g2_800916A4(void) { psx_trap(0x800916A4u); }  /* 0x800916A4: unsupported word 0x0708590F (op=1, fn=15) */

void g2_800916A8(void) { psx_trap(0x800916A8u); }  /* 0x800916AC: unsupported word 0x6D006714 (op=27, fn=20) */

void g2_80091708(void) { psx_trap(0x80091708u); }  /* 0x8009170C: unsupported word 0x05D51416 (op=1, fn=22) */

void g2_80091720(void) { psx_trap(0x80091720u); }  /* 0x80091720: unsupported word 0x05021001 (op=1, fn=1) */

void g2_80091840(void) { psx_trap(0x80091840u); }  /* 0x80091840: unsupported word 0x0602E209 (op=1, fn=9) */

void g2_80091860(void) { psx_trap(0x80091860u); }  /* 0x80091860: unsupported word 0x04550F0F (op=1, fn=15) */

void g2_80091864(void) { psx_trap(0x80091864u); }  /* 0x80091868: unsupported word 0x62181416 (op=24, fn=22) */

void g2_800918EC(void) { psx_trap(0x800918ECu); }  /* 0x800918EC: unsupported word 0x001A0F1C (op=0, fn=28) */

void g2_8009196C(void) { psx_trap(0x8009196Cu); }  /* bad delay slot at 0x80091970 */

void g2_8009197C(void) { psx_trap(0x8009197Cu); }  /* bad delay slot at 0x80091980 */

void g2_80091988(void) { psx_trap(0x80091988u); }  /* 0x8009198C: unsupported word 0x07060710 (op=1, fn=16) */

void g2_8009199C(void) { psx_trap(0x8009199Cu); }  /* 0x800919B4: unsupported word 0x77284626 (op=29, fn=38) */

void g2_80091A1C(void) { psx_trap(0x80091A1Cu); }  /* 0x80091A1C: unsupported word 0x04050019 (op=1, fn=25) */

void g2_80091A40(void) { psx_trap(0x80091A40u); }  /* bad delay slot at 0x80091A40 */

void g2_80091A78(void) { psx_trap(0x80091A78u); }  /* 0x80091A78: unsupported word 0x514E4848 (op=20, fn=8) */

void g2_80091AB0(void) { psx_trap(0x80091AB0u); }  /* 0x80091AB0: unsupported word 0xC5494C50 (op=49, fn=16) */

void g2_80091AD8(void) { psx_trap(0x80091AD8u); }  /* 0x80091AD8: unsupported word 0x070E1802 (op=1, fn=2) */

void g2_80091B80(void) { psx_trap(0x80091B80u); }  /* 0x80091B80: unsupported word 0x00420E2F (op=0, fn=47) */

void g2_80091B9C(void) { psx_trap(0x80091B9Cu); }  /* 0x80091B9C: unsupported word 0x601A1A34 (op=24, fn=52) */

void g2_80091C04(void) { psx_trap(0x80091C04u); }  /* 0x80091C10: unsupported word 0xD780181C (op=53, fn=28) */

void g2_80091C1C(void) { psx_trap(0x80091C1Cu); }  /* 0x80091C2C: unsupported word 0x04020014 (op=1, fn=20) */

void g2_80091C3C(void) { psx_trap(0x80091C3Cu); }  /* bad delay slot at 0x80091C3C */

void g2_80091CC0(void) { psx_trap(0x80091CC0u); }  /* bad delay slot at 0x80091CC0 */

void g2_80091CC8(void) { psx_trap(0x80091CC8u); }  /* bad delay slot at 0x80091CDC */

void g2_80091CCC(void) { psx_trap(0x80091CCCu); }  /* bad delay slot at 0x80091CDC */

void g2_80091CE4(void) { psx_trap(0x80091CE4u); }  /* bad delay slot at 0x80091CE4 */

void g2_80091CE8(void) { psx_trap(0x80091CE8u); }  /* bad delay slot at 0x80091CE8 */

void g2_80091CEC(void) { psx_trap(0x80091CECu); }  /* 0x80091CF4: unsupported word 0x551A0059 (op=21, fn=25) */

void g2_80091D74(void) { psx_trap(0x80091D74u); }  /* 0x80091D74: unsupported word 0xD61A1E2C (op=53, fn=44) */

void g2_80091D84(void) { psx_trap(0x80091D84u); }  /* 0x80091D84: unsupported word 0x00ED0405 (op=0, fn=5) */

void g2_80091D90(void) { psx_trap(0x80091D90u); }  /* 0x80091D90: unsupported word 0x0201F105 (op=0, fn=5) */

void g2_80091DA8(void) { psx_trap(0x80091DA8u); }  /* bad delay slot at 0x80091DA8 */

void g2_80091DAC(void) { psx_trap(0x80091DACu); }  /* 0x80091DBC: unsupported word 0x7D005A1D (op=31, fn=29) */

void g2_80091E40(void) { psx_trap(0x80091E40u); }  /* 0x80091E48: unsupported word 0x05280209 (op=1, fn=9) */

void g2_80091E64(void) { psx_trap(0x80091E64u); }  /* 0x80091E64: unsupported word 0x073B0F0F (op=1, fn=15) */

void g2_80091E68(void) { psx_trap(0x80091E68u); }  /* 0x80091E68: unsupported word 0x4716003B (op=17, fn=59) */

void g2_80091EF8(void) { psx_trap(0x80091EF8u); }  /* 0x80091EF8: unsupported word 0xE6A700E4 (op=57, fn=36) */

void g2_80091F20(void) { psx_trap(0x80091F20u); }  /* bad delay slot at 0x80091F24 */

void g2_80091F84(void) { psx_trap(0x80091F84u); }  /* 0x80091F84: unsupported word 0x00B0B0B0 (op=0, fn=48) */

void g2_80091F88(void) { psx_trap(0x80091F88u); }  /* 0x80091F94: unsupported word 0x73737C80 (op=28, fn=0) */

void g2_80091FC8(void) { psx_trap(0x80091FC8u); }  /* 0x80091FC8: unsupported word 0x05050500 (op=1, fn=0) */

void g2_80091FCC(void) { psx_trap(0x80091FCCu); }  /* 0x80091FD0: unsupported word 0x06020506 (op=1, fn=6) */

void g2_80091FDC(void) { psx_trap(0x80091FDCu); }  /* 0x80091FE0: unsupported word 0x00DE0F0F (op=0, fn=15) */

void g2_80091FE4(void) { psx_trap(0x80091FE4u); }  /* bad delay slot at 0x80091FEC */

void g2_80092014(void) { psx_trap(0x80092014u); }  /* bad delay slot at 0x80092014 */

void g2_80092080(void) { psx_trap(0x80092080u); }  /* 0x80092088: unsupported word 0x03000AF2 (op=0, fn=50) */

void g2_80092140(void) { psx_trap(0x80092140u); }  /* 0x80092144: unsupported word 0x05420200 (op=1, fn=0) */

void g2_80092148(void) { psx_trap(0x80092148u); }  /* 0x80092148: unsupported word 0x06050713 (op=1, fn=19) */

void g2_80092154(void) { psx_trap(0x80092154u); }  /* 0x80092158: unsupported word 0x0332002E (op=0, fn=46) */

void g2_80092158(void) { psx_trap(0x80092158u); }  /* 0x80092158: unsupported word 0x0332002E (op=0, fn=46) */

void g2_8009215C(void) { psx_trap(0x8009215Cu); }  /* 0x80092160: unsupported word 0x0170013C (op=0, fn=60) */

void g2_80092204(void) { psx_trap(0x80092204u); }  /* 0x8009220C: unsupported word 0xE30E0E00 (op=56, fn=0) */

void g2_800922B0(void) { psx_trap(0x800922B0u); }  /* 0x800922B8: unsupported word 0x020006F5 (op=0, fn=53) */

void g2_800923D4(void) {
    R[28] = (uint32_t)(int16_t)lh_(R[3] + 31082);  /* 0x800923D4 */
    { uint32_t _t = R[4]; R[18] = 0x800923E0u; sh_(R[4] + -26215, R[29]); psx_next = _t; return; }  /* 0x800923D8 jalr */
}

void g2_800923E0(void) { psx_trap(0x800923E0u); }  /* 0x800923E0: unsupported word 0xB3B0A8A8 (op=44, fn=40) */

void g2_80092454(void) { psx_trap(0x80092454u); }  /* 0x80092454: unsupported word 0x67191919 (op=25, fn=25) */

void g2_80092498(void) { psx_trap(0x80092498u); }  /* 0x8009249C: unsupported word 0x47494900 (op=17, fn=0) */

void g2_800924EC(void) { psx_trap(0x800924ECu); }  /* 0x800924EC: unsupported word 0x04030E04 (op=1, fn=4) */

void g2_80092504(void) { psx_trap(0x80092504u); }  /* bad delay slot at 0x80092504 */

void g2_80092548(void) { psx_trap(0x80092548u); }  /* 0x80092550: unsupported word 0x003F3B35 (op=0, fn=53) */

void g2_800925A4(void) { psx_trap(0x800925A4u); }  /* 0x800925A4: unsupported word 0x04720405 (op=1, fn=5) */

void g2_800925A8(void) { psx_trap(0x800925A8u); }  /* 0x800925A8: unsupported word 0x02F900F4 (op=0, fn=52) */

void g2_800925C0(void) { psx_trap(0x800925C0u); }  /* bad delay slot at 0x800925C0 */

void g2_800925C4(void) { psx_trap(0x800925C4u); }  /* bad delay slot at 0x800925C4 */

void g2_800925FC(void) { psx_trap(0x800925FCu); }  /* 0x80092604: unsupported word 0x413F3935 (op=16, fn=53) */

void g2_80092654(void) { psx_trap(0x80092654u); }  /* bad delay slot at 0x80092654 */

void g2_80092660(void) { psx_trap(0x80092660u); }  /* 0x80092660: unsupported word 0x03EF810B (op=0, fn=11) */

void g2_8009267C(void) { psx_trap(0x8009267Cu); }  /* bad delay slot at 0x8009267C */

void g2_80092680(void) { psx_trap(0x80092680u); }  /* bad delay slot at 0x80092680 */

void g2_80092688(void) { psx_trap(0x80092688u); }  /* bad delay slot at 0x80092688 */

void g2_80092730(void) { psx_trap(0x80092730u); }  /* bad delay slot at 0x80092730 */

void g2_80092754(void) { psx_trap(0x80092754u); }  /* bad delay slot at 0x80092754 */

void g2_80092758(void) { psx_trap(0x80092758u); }  /* 0x80092768: unsupported word 0x48232623 (op=18, fn=35) */

void g2_800927DC(void) { psx_trap(0x800927DCu); }  /* 0x800927DC: unsupported word 0x6E007377 (op=27, fn=55) */

void g2_8009281C(void) { psx_trap(0x8009281Cu); }  /* bad delay slot at 0x8009281C */

void g2_80092894(void) { psx_trap(0x80092894u); }  /* 0x80092894: unsupported word 0xD3D3D306 (op=52, fn=6) */

void g2_800928E4(void) { psx_trap(0x800928E4u); }  /* 0x800928E8: unsupported word 0xE7141432 (op=57, fn=50) */

void g2_800928E8(void) { psx_trap(0x800928E8u); }  /* 0x800928E8: unsupported word 0xE7141432 (op=57, fn=50) */

void g2_80092960(void) { psx_trap(0x80092960u); }  /* 0x80092968: unsupported word 0x737501C4 (op=28, fn=4) */

void g2_80092994(void) { psx_trap(0x80092994u); }  /* bad delay slot at 0x80092994 */

void g2_800929B8(void) {
    R[1] = R[8] | 0x5D02;  /* 0x800929B8 */
    (void)(((int32_t)R[16] < 14337));  /* 0x800929BC */
    R[16] = ((int32_t)R[1] < (int32_t)R[30]);  /* 0x800929C0 */
    R[13] = R[1] & 0x2D2D;  /* 0x800929C4 */
    psx_next = 0x800929C8u; return;  /* fallthrough */
}

void g2_800929C8(void) { psx_trap(0x800929C8u); }  /* 0x800929C8: unsupported word 0x00713030 (op=0, fn=48) */

void g2_80092A68(void) { psx_trap(0x80092A68u); }  /* 0x80092A68: unsupported word 0x03FA00F3 (op=0, fn=51) */

void g2_80092A6C(void) { psx_trap(0x80092A6Cu); }  /* bad delay slot at 0x80092A6C */

void g2_80092A74(void) { psx_trap(0x80092A74u); }  /* 0x80092A78: unsupported word 0x46002918 (op=17, fn=24) */

void g2_80092A7C(void) { psx_trap(0x80092A7Cu); }  /* 0x80092A8C: unsupported word 0x00382305 (op=0, fn=5) */

void g2_80092B3C(void) { psx_trap(0x80092B3Cu); }  /* 0x80092B40: unsupported word 0x06050107 (op=1, fn=7) */

void g2_80092B44(void) { psx_trap(0x80092B44u); }  /* bad delay slot at 0x80092B4C */

void g2_80092B4C(void) { psx_trap(0x80092B4Cu); }  /* bad delay slot at 0x80092B4C */

void g2_80092B60(void) { psx_trap(0x80092B60u); }  /* 0x80092B74: unsupported word 0x50353420 (op=20, fn=32) */

void g2_80092BEC(void) { psx_trap(0x80092BECu); }  /* 0x80092BEC: unsupported word 0x04DA393F (op=1, fn=63) */

void g2_80092C74(void) { psx_trap(0x80092C74u); }  /* 0x80092C74: unsupported word 0x6A650090 (op=26, fn=16) */

void g2_80092CFC(void) { psx_trap(0x80092CFCu); }  /* 0x80092D0C: unsupported word 0x533F403F (op=20, fn=63) */

void g2_80092D60(void) { psx_trap(0x80092D60u); }  /* 0x80092D64: unsupported word 0xCDC9BC1C (op=51, fn=28) */

void g2_80092D70(void) { psx_trap(0x80092D70u); }  /* 0x80092D78: unsupported word 0xC6809BA2 (op=49, fn=34) */

void g2_80092E6C(void) { psx_trap(0x80092E6Cu); }  /* 0x80092E78: unsupported word 0xED1900E6 (op=59, fn=38) */

void g2_80092E7C(void) { psx_trap(0x80092E7Cu); }  /* 0x80092E80: unsupported word 0x0609090B (op=1, fn=11) */

void g2_80093054(void) { psx_trap(0x80093054u); }  /* bad delay slot at 0x80093054 */

void g2_80093098(void) { psx_trap(0x80093098u); }  /* 0x800930AC: unsupported word 0x433D3934 (op=16, fn=52) */

void g2_80093130(void) { psx_trap(0x80093130u); }  /* bad delay slot at 0x80093130 */

void g2_80093138(void) { psx_trap(0x80093138u); }  /* bad delay slot at 0x80093138 */

void g2_8009313C(void) { psx_trap(0x8009313Cu); }  /* bad delay slot at 0x8009313C */

void g2_8009323C(void) { psx_trap(0x8009323Cu); }  /* 0x80093250: unsupported word 0x00414F01 (op=0, fn=1) */

void g2_800932F4(void) { psx_trap(0x800932F4u); }  /* bad delay slot at 0x800932F4 */

void g2_80093300(void) { psx_trap(0x80093300u); }  /* bad delay slot at 0x80093300 */

void g2_80093324(void) { psx_trap(0x80093324u); }  /* 0x80093328: unsupported word 0x47604442 (op=17, fn=2) */

void g2_8009334C(void) { psx_trap(0x8009334Cu); }  /* 0x80093358: unsupported word 0x5B5E5E01 (op=22, fn=1) */

void g2_80093388(void) { psx_trap(0x80093388u); }  /* 0x80093388: unsupported word 0x019FBCB3 (op=0, fn=51) */

void g2_80093398(void) { psx_trap(0x80093398u); }  /* 0x80093398: unsupported word 0xCFD7D30A (op=51, fn=10) */

void g2_800933AC(void) { psx_trap(0x800933ACu); }  /* 0x800933AC: unsupported word 0x767B7B01 (op=29, fn=1) */

void g2_80093498(void) { psx_trap(0x80093498u); }  /* 0x800934A0: unsupported word 0x5D121416 (op=23, fn=22) */

void g2_800934B8(void) { psx_trap(0x800934B8u); }  /* 0x800934C4: unsupported word 0x04550027 (op=1, fn=39) */

void g2_80093540(void) { psx_trap(0x80093540u); }  /* 0x80093544: unsupported word 0xB3BBC2C4 (op=44, fn=4) */

void g2_80093548(void) { psx_trap(0x80093548u); }  /* 0x80093548: unsupported word 0x03C9A5B3 (op=0, fn=51) */

void g2_80093588(void) { psx_trap(0x80093588u); }  /* 0x80093588: unsupported word 0x5A1D1A28 (op=22, fn=40) */

void g2_800935C8(void) { psx_trap(0x800935C8u); }  /* 0x800935D8: unsupported word 0x51504900 (op=20, fn=0) */

void g2_8009368C(void) { psx_trap(0x8009368Cu); }  /* 0x8009368C: unsupported word 0x002B073F (op=0, fn=63) */

void g2_800936C0(void) { psx_trap(0x800936C0u); }  /* 0x800936C0: unsupported word 0x7E803D3B (op=31, fn=59) */

void g2_80093738(void) { psx_trap(0x80093738u); }  /* 0x8009373C: unsupported word 0x0104054A (op=0, fn=10) */

void g2_80093774(void) { psx_trap(0x80093774u); }  /* 0x80093774: unsupported word 0x54473B2D (op=21, fn=45) */

void g2_8009379C(void) { psx_trap(0x8009379Cu); }  /* 0x8009379C: unsupported word 0x403D003A (op=16, fn=58) */

void g2_8009380C(void) { psx_trap(0x8009380Cu); }  /* 0x8009380C: unsupported word 0x00D000CF (op=0, fn=15) */

void g2_80093830(void) { psx_trap(0x80093830u); }  /* 0x80093830: unsupported word 0xFB025002 (op=62, fn=2) */

void g2_8009385C(void) { psx_trap(0x8009385Cu); }  /* 0x80093860: unsupported word 0x060D0F16 (op=1, fn=22) */

void g2_80093888(void) {
    R[2] = R[16] + 8477;  /* 0x80093888 */
    R[18] = R[1] | 0x302A;  /* 0x8009388C */
    psx_next = 0x80093890u; return;  /* fallthrough */
}

void g2_80093890(void) { psx_trap(0x80093890u); }  /* 0x80093894: unsupported word 0x4C4C4800 (op=19, fn=0) */

void g2_8009392C(void) { psx_trap(0x8009392Cu); }  /* 0x80093934: unsupported word 0x413B0035 (op=16, fn=53) */

void g2_80093938(void) { psx_trap(0x80093938u); }  /* 0x80093938: unsupported word 0x4C494741 (op=19, fn=1) */

void g2_8009396C(void) { psx_trap(0x8009396Cu); }  /* bad delay slot at 0x8009396C */
