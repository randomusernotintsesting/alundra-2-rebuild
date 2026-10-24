import re
import struct
import sys
import unittest
from pathlib import Path

TOOLS = Path(__file__).resolve().parents[1] / 'tools'
sys.path.insert(0, str(TOOLS))
from actor_source_hooks import patch_actor_source_hooks


class SourceHooks(unittest.TestCase):
    def test_preserves_original_instructions_and_all_epilogue_copies(self):
        data = bytearray(0x24D04)
        struct.pack_into('<I', data, 0x2492C, 0x27BDFFE8)
        struct.pack_into('<I', data, 0x24D00, 0x8FB50014)
        original = ('    R[29] = R[29] - 24;  /* 0x8002492C */\n'
                    '    R[21] = lw_(R[29] + 20);  /* 0x80024D00 */\n')
        code = original + original
        output = patch_actor_source_hooks('SCPS', data, 0x80000000, 0, code)
        self.assertEqual(output.count('before_relocation(R[4])'), 2)
        self.assertEqual(output.count('after_relocation(R[20], R[2])'), 2)
        stripped = re.sub(r'#ifdef A2_NATIVE_ACTOR_SOURCES\n.*?#endif\n', '', output, flags=re.S)
        self.assertEqual(stripped, code)
        self.assertEqual(patch_actor_source_hooks('GAME00', data, 0x80000000, 0, code), code)
        with self.assertRaises(ValueError):
            patch_actor_source_hooks('SCPS', data, 0x80000000, 0, output)
        data[0x2492C] ^= 1
        with self.assertRaises(ValueError):
            patch_actor_source_hooks('SCPS', data, 0x80000000, 0, code)

    def test_current_generated_hook_count_matches_instruction_count(self):
        code = (TOOLS.parent / 'gen' / 'scps_008.c').read_text()
        for pc in ('8002492C', '80024D00'):
            self.assertEqual(code.count('/* actor source ' + pc + ' */'),
                             code.count('/* 0x' + pc + ' */'))


if __name__ == '__main__':
    unittest.main()
