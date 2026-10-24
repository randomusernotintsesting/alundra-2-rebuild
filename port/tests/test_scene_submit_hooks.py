import re
import sys
import unittest
from pathlib import Path

TOOLS = Path(__file__).resolve().parents[1] / 'tools'
sys.path.insert(0, str(TOOLS))
from scene_submit_hooks import MARKER, PREFIX, patch_scene_submit_hooks


class SceneSubmitHooks(unittest.TestCase):
    def test_event_retained_prefixes_and_every_source_word(self):
        # Independent machine-code fixture also executes the generated calls.
        fixture = (TOOLS.parent/'tests/test_scene_submit.c').read_text()
        for name, lo, pc, expected_words in [('event_prefix',0x800935C8,0x80093648,33),
                                             ('event_alt_prefix',0x80099B98,0x80099C60,51)]:
            body = re.search(r'%s\[\]=\{(.*?)\};'%name, fixture, re.S).group(1)
            words = re.findall(r'0x([0-9a-f]+)u', body)
            self.assertEqual(len(words), expected_words)
            data = bytearray().join(int(w,16).to_bytes(4,'little') for w in words)
            marker = '    psx_scene_submit_complete();  /* scene submit %08X */\n'%pc
            original = '    R[2] = R[0];  /* 0x%08X */\n'%pc * 4
            output = patch_scene_submit_hooks('EVENT00', data, lo, 0, original)
            self.assertEqual(output.count(marker),4)
            self.assertEqual(output.replace(marker,''),original)
            self.assertNotIn('#ifdef',output)
            with self.assertRaises(ValueError):
                patch_scene_submit_hooks('EVENT00',data,lo,0,output)
            self.assertEqual(patch_scene_submit_hooks('GAME00',data,lo,0,original),original)
            for k in range(0,len(data),4):
                changed=data.copy();changed[k]^=1
                with self.assertRaises(ValueError):
                    patch_scene_submit_hooks('EVENT00',changed,lo,0,original)

    def test_exact_source_and_every_continuation(self):
        original = '    R[2] = 0x1u << 16;  /* 0x80086A30 */\n' * 3
        data = bytearray(PREFIX)
        output = patch_scene_submit_hooks('GAME00', data, 0x80086A00, 0, original)
        self.assertEqual(output.count(MARKER), 3)
        self.assertEqual(output.replace(MARKER, ''), original)
        self.assertNotIn('#ifdef', output)
        self.assertEqual(patch_scene_submit_hooks('EVENT00', data, 0x80086A00, 0, original), original)
        with self.assertRaises(ValueError):
            patch_scene_submit_hooks('GAME00', data, 0x80086A00, 0, output)
        for offset in range(0, len(data), 4):
            changed = data.copy()
            changed[offset] ^= 1
            with self.assertRaises(ValueError):
                patch_scene_submit_hooks('GAME00', changed, 0x80086A00, 0, original)

    def test_current_generated_copies_and_call_order(self):
        code = (TOOLS.parent / 'gen' / 'game00_004.c').read_text()
        self.assertEqual(code.count(MARKER), 3)
        self.assertEqual(code.count(MARKER), code.count('/* 0x80086A30 */'))
        for body in re.split(r'\nvoid ', code):
            if '/* 0x80086A30 */' in body:
                self.assertLess(body.index(MARKER), body.index('/* 0x80086A30 */'))
                self.assertLess(body.index(MARKER), body.index('/* 0x80086A4C */'))
        for filename, pc, following in [('event00_011.c',0x80093648,0x80093664),
                                        ('event00_013.c',0x80099C60,0x80099C6C)]:
            code=(TOOLS.parent/'gen'/filename).read_text()
            marker='    psx_scene_submit_complete();  /* scene submit %08X */\n'%pc
            native='/* 0x%08X */'%pc
            self.assertEqual(code.count(marker),4)
            self.assertEqual(code.count(marker),code.count(native))
            for body in re.split(r'\nvoid ',code):
                if native in body:
                    self.assertLess(body.index(marker),body.index(native))
                    self.assertLess(body.index(marker),body.index('/* 0x%08X */'%following))


if __name__ == '__main__':
    unittest.main()
