"""The renderer clips glyph rectangles to their declared advance width."""
import unittest
from pathlib import Path

from a2.cyrfont import build16, build24, decode_bank
from a2.pak import PakArchive


class GlyphAdvanceTests(unittest.TestCase):
    def test_small_ve_matches_original_lowercase_body_alignment(self):
        root = Path(__file__).resolve().parent.parent
        arc = PakArchive.load(str(root / "disc_jp.orig/DATA/PACK0.PAK"))
        latin = decode_bank(arc.slots[545], 24)
        glyphs = build24(latin)

        def body_bounds(pixels):
            points = [(x, y) for y, row in enumerate(pixels)
                      for x, level in enumerate(row) if level == 3]
            return (min(x for x, y in points), min(y for x, y in points),
                    max(x for x, y in points), max(y for x, y in points))

        original_a = body_bounds(latin[ord("a") - 32][0])
        self.assertEqual(original_a, (1, 10, 4, 22))
        self.assertEqual(body_bounds(glyphs["в"][0]), original_a)
        self.assertEqual(glyphs["в"][1], 6)

    def test_cyrillic_bright_body_fits_draw_rectangle(self):
        root = Path(__file__).resolve().parent.parent
        arc = PakArchive.load(str(root / "disc_jp.orig/DATA/PACK0.PAK"))
        glyphs = build16(decode_bank(arc.slots[548], 16))
        for char, (pixels, advance) in glyphs.items():
            with self.subTest(char=char):
                # L1/L2 may be intentional shadow; losing L3 cuts the body.
                self.assertFalse(any(3 in row[advance:] for row in pixels),
                                 "bright stroke extends past drawn width")


if __name__ == "__main__":
    unittest.main()
