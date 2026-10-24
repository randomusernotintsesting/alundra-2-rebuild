"""Protect the Japanese title artwork outside its two menu choices."""
import hashlib
from pathlib import Path
import unittest

from a2.pak import PakArchive
from menu_texture_patch import parse_container
from title_texture_patch import patch_title_menu

ROOT = Path(__file__).resolve().parents[1]


class TitleTextureTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.original = PakArchive.load(ROOT / "disc_jp.orig/DATA/PACK0.PAK")

    def test_only_menu_pixels_change_logo_credits_palettes_other_pages_survive(self):
        archive = PakArchive(list(self.original.slots))
        report = patch_title_menu(archive)
        self.assertEqual(report["changed_slots"], [23])
        for i, (before, after) in enumerate(zip(self.original.slots, archive.slots)):
            if i != 23:
                self.assertEqual(before, after, f"unrelated slot {i}")
        _, _, old_palette, old_chunks = parse_container(self.original.slots[23])
        _, _, new_palette, new_chunks = parse_container(archive.slots[23])
        self.assertEqual(new_palette, old_palette)
        self.assertEqual([c['compressed'] for c in new_chunks[1:]],
                         [c['compressed'] for c in old_chunks[1:]])
        old, new = old_chunks[0]['raw'], new_chunks[0]['raw']
        for i, (a, b) in enumerate(zip(old, new)):
            if not (64 <= i % 256 < 192 and 240 <= i // 256 < 256):
                self.assertEqual(a, b, f"artwork pixel {i%256},{i//256}")
        for x in (64, 128):
            a = b''.join(old[y*256+x:y*256+x+64] for y in range(240,256))
            b = b''.join(new[y*256+x:y*256+x+64] for y in range(240,256))
            self.assertNotEqual(a, b)
            self.assertTrue(any(v < 10 for v in b), "visible white Russian ink")
            self.assertEqual(set(b[:64]), {34}, "top margin remains transparent")
            self.assertEqual(set(b[-64:]), {34}, "bottom margin remains transparent")
        before = list(archive.slots)
        self.assertEqual(patch_title_menu(archive)['changed_slots'], [])
        self.assertEqual(archive.slots, before)

    def test_unknown_artwork_rejected_before_mutation(self):
        archive = PakArchive(list(self.original.slots))
        data = bytearray(archive.slots[23])
        data[52] ^= 1  # unknown palette must never be silently recolored
        archive.slots[23] = bytes(data)
        before = list(archive.slots)
        with self.assertRaises(ValueError):
            patch_title_menu(archive)
        self.assertEqual(archive.slots, before)


if __name__ == '__main__':
    unittest.main()
