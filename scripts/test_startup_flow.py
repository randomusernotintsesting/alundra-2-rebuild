"""Execute actual generated boot continuations without a GPU or a native run."""
from pathlib import Path
import re
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'port/tools'))


def function(source, address):
    match = re.search(r'^void f_' + address + r'\(void\) \{\n.*?^\}', source,
                      re.M | re.S)
    if not match:
        raise AssertionError('Missing generated continuation ' + address)
    return match.group()


class StartupFlowTests(unittest.TestCase):
    def test_source_guard_and_regeneration_keep_the_same_continuation(self):
        from recomp import recompile_one
        from startup_flow import patch_startup_continuation
        base = 0x8001A618
        with (ROOT / 'disc_jp/SCPS_101.15').open('rb') as source:
            source.seek(base - 0x80016800)
            data = source.read(60)
        original = recompile_one(data, base, base, base + len(data),
                                 0x8001A62C, 0x8001A654).code
        self.assertIn('0x8001A638 jal', original)
        patched = patch_startup_continuation('SCPS', data, base, 0x8001A62C, original)
        generated = function((ROOT / 'port/gen/scps_003.c').read_text(), '8001A62C')
        self.assertEqual(patched, generated)
        self.assertEqual(patch_startup_continuation('EVENT00', data, base, 0x8001A62C, original), original)
        self.assertEqual(patch_startup_continuation('SCPS', data, base, 0x8001A640, original), original)
        corrupt = bytearray(data); corrupt[20] ^= 1
        with self.assertRaisesRegex(ValueError, 'does not match'):
            patch_startup_continuation('SCPS', corrupt, base, 0x8001A62C, original)
        with self.assertRaises(ValueError):
            patch_startup_continuation('SCPS', data[:24], base, 0x8001A62C, original)

    def test_qol_hooks_are_guarded_and_reproducible(self):
        from startup_flow import patch_startup_continuation
        data = (ROOT / 'disc_jp/SCPS_101.15').read_bytes()
        source = (ROOT / 'port/gen/scps_003.c').read_text()
        for address, hook in [('8001A238','a2_startup_logo_begin();'),
                              ('8001A4B8','a2_startup_logo_fade(&R[20],&R[19]);'),
                              ('8001A654','a2_startup_movies_begin();')]:
            generated = function(source, address)
            self.assertEqual(generated.count(hook), 1)
            original = generated.replace('    ' + hook + '\n','',1)
            self.assertEqual(patch_startup_continuation('SCPS',data,0x80016800,int(address,16),original),generated)
            corrupt = bytearray(data); corrupt[int(address,16)-0x80016800] ^= 1
            with self.assertRaisesRegex(ValueError, 'does not match'):
                patch_startup_continuation('SCPS',corrupt,0x80016800,int(address,16),original)

    def test_genuine_sony_return_skips_entire_contrail_then_calls_matrix(self):
        source = (ROOT / 'port/gen/scps_003.c').read_text()
        generated = '\n'.join(function(source, a) for a in ('8001A618', '8001A62C', '8001A640'))
        harness = r'''
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
uint32_t R[32], HI, LO, psx_next;
uint32_t lw_(uint32_t address) { (void)address; abort(); }
GENERATED
int main(void) {
    const uint32_t flags[] = {0, 1, 0xffffffffu};
    for (unsigned test = 0; test < 3; ++test) {
        for (unsigned i = 0; i < 32; ++i) R[i] = 0x17892300u + i;
        R[0] = 0; HI = 0xabcdef01u; LO = 0x12345678u;
        f_8001A618();
        assert(psx_next == 0x8001A238u && R[31] == 0x8001A62Cu);
        assert(R[4] == 2 && R[5] == 1 && R[6] == R[16] && R[7] == 0);
        /* The original presenter returns Sony's skip result through R2/R31.
         * Dispatch its real return continuation rather than emulating a logo. */
        R[2] = flags[test]; psx_next = R[31];
        uint32_t before[32]; memcpy(before, R, sizeof R);
        f_8001A62C();
        assert(psx_next == 0x8001A640u);
        assert(!memcmp(R, before, sizeof R));
        assert(HI == 0xabcdef01u && LO == 0x12345678u);
        f_8001A640();
        assert(psx_next == 0x8001A238u && R[31] == 0x8001A654u);
        assert(R[4] == 6 && R[5] == 3 && R[6] == R[16] && R[7] == flags[test]);
        assert(R[2] == flags[test]);
    }
    return 0;
}
'''.replace('GENERATED', generated)
        with tempfile.TemporaryDirectory(prefix='a2-startup-') as td:
            path = Path(td); (path / 'test.c').write_text(harness)
            subprocess.run(['clang', '-std=c11', '-O1', '-g', '-UNDEBUG',
                            '-fsanitize=undefined', '-Wall', '-Wextra', '-Werror',
                            str(path / 'test.c'), '-o', str(path / 'test')], check=True)
            run = subprocess.run([str(path / 'test')], capture_output=True, text=True)
            self.assertEqual(run.returncode, 0, run.stdout + run.stderr)

    def test_overlapping_generated_copies_cannot_fall_through_after_sony(self):
        source = (ROOT / 'port/gen/scps_003.c').read_text()
        copies = re.findall(r'^void f_[0-9A-F]+\(void\) \{\n.*?^\}', source, re.M | re.S)
        duplicated = [f for f in copies if '/* 0x8001A638 jal */' in f]
        self.assertGreater(len(duplicated), 1)
        for copy in duplicated:
            # All overlapping copies yield to the dispatcher at Sony's call.
            # Its R31 selects the single patched continuation from the table.
            self.assertRegex(copy, r'R\[31\] = 0x8001A62Cu;[^\n]+return;[^\n]+0x8001A624 jal')
            self.assertLess(copy.index('0x8001A624 jal'), copy.index('0x8001A638 jal'))
        table = (ROOT / 'port/gen/scps_table.c').read_text()
        for address in ('8001A618', '8001A62C', '8001A640'):
            self.assertEqual(table.count('{ 0x' + address + 'u, f_' + address + ' }'), 1)


    def test_staged_load_uses_original_boot_and_successful_load_continuations(self):
        """Catch a wrong bypass target, altered guest stack, or lost load flags."""
        from a2.pak import PakArchive
        from recomp import recompile_one
        scps = (ROOT / 'disc_jp/SCPS_101.15').read_bytes()
        title = PakArchive.load(ROOT / 'disc_jp/DATA/PACK1.PAK').slots[34]
        generated = '\n'.join((ROOT / ('port/gen/scps_%03d.c' % i)).read_text() for i in (3, 4))
        snippets = [function(generated, a) for a in ('8001A540', '8001AB14', '8001AB68')]
        for begin, end in [(0x801464B0, 0x801464F4), (0x80146938, 0x8014695C),
                           (0x8014695C, 0x80146978), (0x80146978, 0x80146984),
                           (0x801469CC, 0x801469D4), (0x801469D4, 0x801469E4),
                           (0x80146A98, 0x80146AA0), (0x80146AA0, 0x80146AD8)]:
            snippets.append(recompile_one(title, 0x801454E0, 0x801454E0,
                0x801454E0 + len(title), begin, end).code)
        snippets.append(function((ROOT / 'port/gen/scps_011.c').read_text(), '8002A0DC'))
        harness = r'''
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "psx_rt.h"
#include "native_save_guest.h"
uint8_t PSX_RAM[PSX_RAM_SIZE], PSX_SCRATCH[0x400];
uint32_t R[32], HI, LO, psx_next, a2_ramwatch, psx_work;
int psx_bb_budget=1000000;
void psx_bb_fire(void) {abort();}
void a2_ramwatch_hit(uint32_t a,uint32_t b,int c) {(void)a;(void)b;(void)c;abort();}
void psx_mmio_write(uint32_t a,uint32_t b,int c) {(void)a;(void)b;(void)c;abort();}
uint32_t psx_mmio_read(uint32_t a,int b) {(void)a;(void)b;abort();}
void psx_call(uint32_t a) {
    assert(a==0x8002DCC8 && R[4]==10 && R[5]==15 && R[6]==0);
}
int platform_native_save_dialog(int s,uint8_t *p,char *e,size_t n) {
    (void)s;(void)p;(void)e;(void)n;abort();
}
void platform_native_save_error(const char *e) {(void)e;abort();}
GENERATED
static void read_code(const char *path,uint32_t addr,size_t size) {
    FILE *f=fopen(path,"rb");assert(f);
    assert(fread(PSX_RAM+(addr&0x1fffff),1,size,f)==size);fclose(f);
}
int main(int argc,char **argv) {
    assert(argc==3);setenv("A2_NATIVE_SAVES","1",1);
    read_code(argv[1],0x80016800,SCPS_SIZE);
    read_code(argv[2],0x801454E0,TITLE_SIZE);
    uint8_t payload[A2_CHECKPOINT_PAYLOAD_SIZE];char error[512];
    const unsigned maps[]={213,412};
    for(unsigned scenario=0;scenario<2;scenario++) {
        for(unsigned i=0;i<32;i++)R[i]=0x17890000u+i;
        R[0]=0;R[29]=0x801fff00;R[31]=0x8001aa64;
        HI=0x12345678;LO=0x9abcdef0;
        /* No staged selection leaves the original boot and opening intact. */
        assert(!a2_native_save_handle(0x8001A540));
        f_8001A540();assert(psx_next==0x8003285C && R[29]==0x801ffed8);
        R[29]=0x801fff00;R[31]=0x8001aa64;
        sw_(0x8005e6b8,1);assert(!a2_native_save_handle(0x8001AB14));
        f_8001AB14();assert(psx_next==0x8001A764); /* Original opening preparation. */
        for(unsigned i=0;i<A2_CHECKPOINT_SIZE;i++)PSX_RAM[0x63388+i]=(uint8_t)(i*37);
        sh_(0x80063388,7);sh_(0x800633a8,0);sh_(0x800633aa,10);sh_(0x800633ac,15);
        sh_(0x80063e9c,maps[scenario]);
        assert(a2_checkpoint_prepare(PSX_RAM,payload,error,sizeof error));
        assert(a2_native_stage_startup_load(payload,error,sizeof error));
        /* Mutating any guarded word rejects each redirect without changing CPU state. */
        const uint32_t entries[]={0x8001a540,0x8001ab14,0x80146578};
        sw_(0x800811d8,4);sw_(R[29]+0x5c,0x80085ac4);R[31]=0x8001aa64;
        for(unsigned entry=0;entry<3;entry++)for(unsigned word=0;word<4;word++) {
            uint32_t at=entries[entry]+word*4, original=lw_(at), saved[32];
            memcpy(saved,R,sizeof saved);uint32_t next=psx_next;
            sw_(at,original^1u);
            assert(!a2_native_save_handle(entries[entry]));
            assert(!memcmp(saved,R,sizeof saved) && psx_next==next);
            sw_(at,original);
        }
        assert(a2_native_save_handle(0x8001a540) && psx_next==0x8001aa64);
        assert(a2_native_save_handle(0x8001ab14) && psx_next==0x8001ab68);
        f_8001AB68();assert(psx_next==0x8002A0DC && R[4]==0);
        f_8002A0DC();assert(psx_next==0x8001AB70 && lw_(0x80067584)==1);
        /* Use the original TITLE00 frame. GPU initialization is an external
         * boundary here; the native replay verifies the actual shared setup. */
        R[31]=0x80085ac4;uint32_t caller[32];memcpy(caller,R,sizeof caller);
        f_801464B0();assert(psx_next==0x800864B0 && R[29]==0x801ffea0);
        assert(a2_native_save_handle(0x80146578) && psx_next==0x80146938);
        sw_(0x8005d058,99);sw_(0x8005d09c,99);
        f_80146938();assert(psx_next==0x8002C3D4 && R[4]==1);
        assert(lw_(0x8005d058)==0 && lw_(0x8005d09c)==0);
        f_8014695C();assert(psx_next==0x800C8738 && R[31]==0x80146978 && R[4]==0);
        assert(a2_native_save_handle(psx_next));
        assert(R[2]==1 && !a2_native_startup_load_pending() && a2_native_startup_load_active());
        f_80146978();assert(psx_next==0x8002A0DC && R[4]==0);
        f_8002A0DC();assert(psx_next==0x80146984);
        assert(a2_native_save_handle(psx_next) && psx_next==0x801469cc);
        f_801469CC();assert(psx_next==0x80019B24 && R[4]==1);
        f_801469D4();assert(psx_next==0x80146a98 && lh_(0x80063384)==1);
        f_80146A98();assert(psx_next==0x8002DD94 && R[4]==0xffffffffu);
        f_80146AA0();assert(psx_next==0x80085ac4 && R[2]==0 && R[29]==caller[29]);
        for(unsigned i=16;i<=23;i++)assert(R[i]==caller[i]);
        assert(R[30]==caller[30] && R[31]==caller[31]);
        assert(HI==0x12345678 && LO==0x9abcdef0);
        assert(!memcmp(PSX_RAM+0x63388,payload+0x100,A2_CHECKPOINT_SIZE));
        assert(!memcmp(PSX_RAM+0x626f8,payload+0x100,A2_CHECKPOINT_SIZE));
        memset(PSX_RAM+0xf621c,0,8);PSX_RAM[0x11752a]=0;PSX_RAM[0x64018]=0;
        sh_(0x8012789c,maps[scenario]);assert(!a2_native_save_handle(0x80085474));
        assert(!a2_native_startup_load_active());
    }
    puts("Stock SCPS/TITLE00 branches, load flags, checkpoint and guest frame verified");
}
'''.replace('GENERATED', '\n'.join(snippets)).replace('SCPS_SIZE', str(len(scps))).replace('TITLE_SIZE', str(len(title)))
        with tempfile.TemporaryDirectory(prefix='a2-startup-load-') as td:
            path = Path(td)
            (path / 'test.c').write_text(harness)
            (path / 'scps.bin').write_bytes(scps)
            (path / 'title.bin').write_bytes(title)
            subprocess.run(['clang', '-std=c11', '-D_POSIX_C_SOURCE=200809L',
                '-fno-common', '-O1', '-g', '-UNDEBUG', '-fsanitize=undefined',
                '-Wall', '-Wextra', '-Werror', '-I', str(ROOT / 'port/src'),
                str(path / 'test.c'), str(ROOT / 'port/src/native_save_guest.c'),
                '-o', str(path / 'test')], check=True)
            run = subprocess.run([str(path / 'test'), str(path / 'scps.bin'),
                str(path / 'title.bin')], capture_output=True, text=True)
            self.assertEqual(run.returncode, 0, run.stdout + run.stderr)


if __name__ == '__main__':
    unittest.main()
