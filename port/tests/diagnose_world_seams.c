/* Offline diagnostic, not a game replay or a seam-fix regression test.
 * Preserves /tmp/a2-cabin-readonly.TWutdt/tjunction_seam.c with a portable
 * include path. Captured XY: door-fixed-hd64-ir1/modelcap.txt lines 7, 9, 31.
 * The three polygons are isolated and made solid, so background in this
 * fixture does NOT establish background visibility in the complete scene.
 *
 * From repository root, after any coordinated paced profile has ended:
 *   cc -O2 port/tests/diagnose_world_seams.c -o /tmp/a2-diagnose-world-seams
 *   /tmp/a2-diagnose-world-seams
 *
 * No SDL, game process, file writes, disc access or save/card access.
 * Not registered with CMake; expected current behavior is a nonzero gap.
 */
#define main gpu_existing_test_main
#include "test_gpu.c"
#undef main

static void quad(const int p[8]) {
    gpu_gp0(0x280000f8);
    for (int i = 0; i < 4; i++) gpu_gp0(xy(p[i * 2], p[i * 2 + 1]));
}

static int cross(int ax, int ay, int bx, int by, int x, int y) {
    return (bx - ax) * (y - ay) - (by - ay) * (x - ax);
}

int main(void) {
    const int one[] = {153, 67, 179, 51, 181, 84, 208, 67};
    const int two[] = {124, 84, 153, 67, 152, 104, 181, 84};
    const int three[] = {208, 67, 228, 78, 152, 104, 188, 107};
    for (int s = 1; s <= 3; s += 2) {
        gpu_set_ir(s);
        gpu_gp1(0);
        gpu_gp0(0xe3000000);
        gpu_gp0(0xe4000000 | 319 | (223 << 10));
        gpu_gp0(0x02f80000);
        gpu_gp0(0);
        gpu_gp0(xy(320, 224));
        quad(one);
        quad(two);
        quad(three);
        int gap = 0, total = 0;
        for (int y = 67 * s; y < 104 * s; y++) {
            for (int x = 152 * s; x < 208 * s; x++) {
                int a = cross(152 * s, 104 * s, 208 * s, 67 * s, x, y);
                int b = cross(208 * s, 67 * s, 181 * s, 84 * s, x, y);
                int c = cross(181 * s, 84 * s, 152 * s, 104 * s, x, y);
                if (a < 0 && b < 0 && c < 0) {
                    total++;
                    gap += gpu_display_px(x, y) == 0x7c00;
                }
            }
        }
        printf("IR%d captured three-quad T junction: "
               "%d/%d strict wedge pixels uncovered\n", s, gap, total);
        assert(gap == total && gap > 0);
    }
    puts("Captured rounded XY boundaries leave a gap in the isolated fixture.");
    return 0;
}
