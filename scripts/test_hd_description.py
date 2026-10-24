"""Contracts for the shared resident text-window frame, not screenshot paint."""
import hashlib
from pathlib import Path
import struct
import tempfile
import unittest

from build_hd_description import build_description

ROOT = Path(__file__).resolve().parents[1]
EXE = ROOT / 'disc_jp/SCPS_101.15'
SOURCE_SHA = '8d7b4e3c6d71164a7808180c77d19167d395b7aeff7faafc878afed5d1c31f16'
PALETTE = (0x0000, 0x0002, 0x0466, 0x08c9, 0x0d2e, 0x15b3,
           0x1e37, 0x2eda, 0x479f, 0x67ff, 0xd294, 0x00aa,
           0x00ed, 0x0150, 0x01b3, 0x0216)


@unittest.skipUnless(EXE.exists(), 'requires local pristine Japanese EXE')
class HDDescriptionTests(unittest.TestCase):
    def asset(self):
        return build_description(EXE)

    def test_exact_resident_source_and_runtime_mapping(self):
        asset = self.asset()
        self.assertIn('source', asset)
        self.assertEqual(asset['uv'], (0, 144, 24, 24))
        self.assertEqual(asset['bpp'], 4)
        self.assertEqual(asset['clut_bank'], 6)
        self.assertEqual(len(asset['source']), 576)
        self.assertEqual(hashlib.sha256(asset['source']).hexdigest(), SOURCE_SHA)
        self.assertEqual(struct.unpack('<16H', asset['palette']), PALETTE)
        self.assertEqual(asset['container_offset'], 0x395d8)
        self.assertEqual(asset['container_sha256'],
                         '7d8ea1c755b73842a27a17c6ddeec931c5dea084a1ac48e6f1367f7b48e8233d')

    def test_rejects_changed_container_and_truncated_exe(self):
        original = EXE.read_bytes()
        with tempfile.TemporaryDirectory() as tmp:
            target = Path(tmp) / 'SCPS_101.15'
            for offset in (0x395d8, 0x395d8 + 52 + 192, 0x395d8 + 8433):
                changed = bytearray(original)
                changed[offset] ^= 1
                target.write_bytes(changed)
                with self.assertRaisesRegex(ValueError, 'unknown.*frame source'):
                    build_description(target)
            target.write_bytes(original[:0x395d8 + 8433])
            with self.assertRaisesRegex(ValueError, 'unknown.*frame source'):
                build_description(target)

    def test_all_nine_tiles_join_and_repeat_without_seams(self):
        pixels = self.asset()['pixels']
        self.assertEqual(len(pixels), 96 * 96)
        # Native E2 repeats the middle eight texels; it never stretches them.
        # Equality also across 7.75/8 and 15.75/16 catches corner joins.
        for y in range(96):
            self.assertEqual(len(set(pixels[y * 96 + 31:y * 96 + 65])), 1)
        for x in range(96):
            self.assertEqual(len({pixels[y * 96 + x] for y in range(31, 65)}), 1)

    def test_native_subtractive_body_and_transparent_outer_edge_survive(self):
        asset = self.asset()
        pixels = asset['pixels']
        # Index 10 is the original STP subtractive center, not baked black RGB.
        body = 10 | (10 << 8) | (255 << 24)
        for y in range(32, 64):
            self.assertEqual(pixels[y * 96 + 32:y * 96 + 64], [body] * 32)
        self.assertTrue(PALETTE[10] & 0x8000)
        self.assertTrue(all(not (v & 0x8000) for v in PALETTE[1:10]))
        self.assertTrue(all(pixels[x] >> 24 == 0 for x in range(96)))
        self.assertTrue(all(pixels[95 * 96 + x] >> 24 == 0 for x in range(96)))
        self.assertEqual(pixels[0] >> 24, 0)
        self.assertTrue(any(0 < (p >> 24) < 255 for p in pixels))
        self.assertTrue(any(0 < ((p >> 16) & 255) < 255 and
                            10 in (p & 255, (p >> 8) & 255) for p in pixels))
        self.assertTrue(all(1 <= (p & 255) <= 10 and
                            1 <= ((p >> 8) & 255) <= 10 for p in pixels))
        # Integrated gold width along a straight side is under 1.25 native
        # pixels; the old post occupied seven. Center and geometry stay native.
        line = pixels[48 * 96:49 * 96][:32]
        gold = sum((p >> 24) / 255 * (1 - ((p >> 16) & 255) / 255)
                   for p in line if (p & 255) != 10) / 4
        self.assertGreater(gold, .5)
        self.assertLess(gold, 1.25)

    def test_deterministic_and_does_not_modify_exe(self):
        original = EXE.read_bytes()
        self.assertEqual(self.asset(), self.asset())
        self.assertEqual(EXE.read_bytes(), original)


class HDDescriptionMalformedTests(unittest.TestCase):
    def test_explicit_truncated_source_fails_without_local_game_files(self):
        with tempfile.TemporaryDirectory() as tmp:
            target = Path(tmp) / 'SCPS_101.15'
            target.write_bytes(b'PS-X EXE')
            with self.assertRaisesRegex(ValueError, 'unknown.*frame source'):
                build_description(target)


if __name__ == '__main__':
    unittest.main()
