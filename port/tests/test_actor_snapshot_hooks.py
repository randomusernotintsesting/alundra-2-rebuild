import importlib.util
from pathlib import Path
import re
import struct
import unittest

ROOT = Path(__file__).resolve().parents[2]
spec = importlib.util.spec_from_file_location('actor_hooks', ROOT/'port/tools/actor_snapshot_hooks.py')
hooks = importlib.util.module_from_spec(spec)
spec.loader.exec_module(hooks)

# Literal EVENT00 producer contracts are independent of the implementation table.
EVENT_SITES = (
    (0x80088A24, (0x3c02800b, 0x244b3f18, 0x01604021),
     'a2_native_actor_snapshot_event_begin(psx_frame_no, R[2]);'),
    (0x80088E38, (0x26840104, 0x27a50320, 0x0c009716),
     'a2_native_actor_snapshot_event_instance(R[20], lw_(R[29]+2572));'),
    (0x80088EB8, (0xafa0084c, 0xafa00848, 0x8682010a),
     'int32_t root_q12[3] = {(int32_t)lw_(R[29]+2136), (int32_t)lw_(R[29]+2140), (int32_t)lw_(R[29]+2144)};\n'
     '        a2_native_actor_snapshot_root(R[20], root_q12);'),
    (0x800895E8, (0x8faf0a0c, 0x26730050, 0x25ef0050),
     'a2_native_actor_snapshot_event_part(R[20], R[21], R[19]-58);'),
    (0x8008BBA0, (0x8e630004, 0x00000000, 0x14600004),
     'a2_native_actor_snapshot_event_reset(0x800ce028u+R[22]);'),
)

class ActorSnapshotHooks(unittest.TestCase):
    def test_event_contract_and_each_word_identity(self):
        for pc, words, body in EVENT_SITES:
            # Two overlapping functions, preserving the exact guest lines and
            # labels, model the recompiler's direct and continuation entries.
            line = '    R[2] = R[0];  /* 0x%08X */' % pc
            code = ('void full(void) {\nL_%08X:;\n%s\n}\n'
                    'void continuation(void) {\n%s\n}\n') % (pc, line, line)
            data = struct.pack('<3I', *words)
            patched = hooks.patch_actor_snapshot_hooks('EVENT00', data, pc, pc, code)
            self.assertEqual(patched.count(body), 2, hex(pc))
            stripped = re.sub(r'#ifdef A2_NATIVE_ACTOR_SNAPSHOT\n.*?#endif\n',
                              '', patched, flags=re.S)
            self.assertEqual(stripped, code)
            for word_index in range(3):
                changed = list(words)
                changed[word_index] ^= 1
                with self.assertRaises(ValueError, msg=(hex(pc), word_index)):
                    hooks.patch_actor_snapshot_hooks('EVENT00', struct.pack('<3I', *changed),
                                                     pc, pc, code)
            self.assertEqual(hooks.patch_actor_snapshot_hooks('ZZZ', data, pc, pc, code), code)

    def test_all_exact_sites_and_unknown_code(self):
        for module, pc, words, body in hooks.SITES:
            data = struct.pack('<3I', *words)
            line = '    R[2] = R[0];  /* 0x%08X */' % pc
            code = 'void fixture(void) {\n'+line+'\n}\n'
            patched = hooks.patch_actor_snapshot_hooks(module,data,pc,pc,code)
            self.assertEqual(patched.count(body),1)
            self.assertIn(line,patched)
            with self.assertRaises(ValueError):
                hooks.patch_actor_snapshot_hooks(module,b'\0'*12,pc,pc,code)
            with self.assertRaises(ValueError):
                hooks.patch_actor_snapshot_hooks(module,data,pc,pc,patched)
            self.assertEqual(hooks.patch_actor_snapshot_hooks('ZZZ',data,pc,pc,code),code)

    def test_every_current_overlapping_copy(self):
        for module,pc,words,body in hooks.SITES:
            prefix={'GAME00':'game00','SCPS':'scps','EVENT00':'event00'}[module]
            total=0
            for file in (ROOT/'port/gen').glob(prefix+'_*.c'):
                text=file.read_text()
                native=len(re.findall(r'^    [^\n]*?/\* 0x%08X(?: [^*]*)? \*/$'%pc,text,re.M))
                installed=text.count('/* actor snapshot %08X */'%pc)
                self.assertEqual(native,installed,(file.name,hex(pc)))
                total+=native
            self.assertGreater(total,0,hex(pc))

if __name__=='__main__': unittest.main()
