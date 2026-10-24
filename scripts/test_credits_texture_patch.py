"""Credits stay on the same native pages, with every original row retained."""
from pathlib import Path
import unittest

from a2.pak import PakArchive
from menu_texture_patch import parse_container, unpack_indices
from credits_texture_patch import CREDITS, patch_credits

ROOT = Path(__file__).resolve().parents[1]


class CreditsTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.original = PakArchive.load(ROOT / 'disc_jp.orig/DATA/PACK0.PAK')

    def test_translations_preserve_pages_palettes_every_row_and_unrelated_slots(self):
        self.assertEqual(len(CREDITS), 37)
        for language in ('ru', 'en'):
            archive = PakArchive(list(self.original.slots))
            result = patch_credits(archive, language)
            self.assertEqual(result['changed_slots'], [25, 26, 27, 28])
            self.assertEqual(len(result['pages']), 37)
            for i, (before, after) in enumerate(zip(self.original.slots, archive.slots)):
                if i not in (25, 26, 27, 28):
                    self.assertEqual(before, after, f'unrelated slot {i}')
            for s in (25, 26, 27, 28):
                w, h, pal, before = parse_container(self.original.slots[s])
                nw, nh, npal, after = parse_container(archive.slots[s])
                self.assertEqual((nw, nh, npal, len(after)), (w, h, pal, len(before)))
                for p in range(10):
                    if (s, p) not in CREDITS:
                        self.assertEqual(before[p]['compressed'], after[p]['compressed'])
                        continue
                    row = next(r for r in result['pages'] if r['slot'] == s and r['page'] == p)
                    self.assertEqual(len(row['rows']), len(CREDITS[s, p]))
                    indices = unpack_indices(after[p]['raw'], w, h, 4)
                    for line in row['rows']:
                        x0, y0, x1, y1 = line['ink_bbox']
                        self.assertGreater(x1, x0)
                        self.assertGreater(y1, y0)
                        self.assertGreaterEqual(x0, 8)
                        self.assertLessEqual(x1, 248)
                        self.assertGreaterEqual(y0, line['source_band'][0])
                        self.assertLessEqual(y1, line['source_band'][1])
                        self.assertTrue(any(indices[y*w+x] for y in range(y0,y1) for x in range(x0,x1)))
                        self.assertTrue(line['original'])
                        if language == 'en':
                            line['text'].encode('ascii')
                    self.assertEqual(set(indices[:w] + indices[-w:]), {0})
            before = list(archive.slots)
            self.assertEqual(patch_credits(archive, language)['changed_slots'], [])
            self.assertEqual(archive.slots, before)

    def test_unknown_final_slot_rejected_before_any_mutation(self):
        archive = PakArchive(list(self.original.slots))
        damaged = bytearray(archive.slots[28]); damaged[52] ^= 1
        archive.slots[28] = bytes(damaged)
        before = list(archive.slots)
        with self.assertRaises(ValueError):
            patch_credits(archive, 'ru')
        self.assertEqual(archive.slots, before)

    def test_japanese_profile_cannot_be_accidentally_patched(self):
        archive = PakArchive(list(self.original.slots))
        with self.assertRaises(ValueError):
            patch_credits(archive, 'ja')
        self.assertEqual(archive.slots, self.original.slots)


if __name__ == '__main__':
    unittest.main()
