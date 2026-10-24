import unittest
from pathlib import Path
from a2.pak import PakArchive
from build_hd_font import build_assets, DEFAULT_FONT

ROOT=Path(__file__).resolve().parents[1]

class EnglishFontTests(unittest.TestCase):
    def test_english_uses_ascii_outlines_and_original_bank_identity(self):
        archive=PakArchive.load(ROOT/'disc_jp.orig/DATA/PACK0.PAK')
        assets=build_assets(DEFAULT_FONT,archive.slots[548],archive.slots[545],language='en')
        self.assertEqual(assets['bank16'],archive.slots[548])
        self.assertEqual(assets['bank24'],archive.slots[545])
        for height in (16,24):
            profile=assets['profiles'][height]
            self.assertEqual(profile['glyphs'][ord('Y')-32]['codepoint'],ord('Y'))
            for glyph in profile['glyphs'][:95]:
                self.assertEqual(glyph['codepoint'],glyph['index']+32)
            self.assertTrue(any(profile['glyphs'][ord('Y')-32]['alpha']))

if __name__=='__main__':unittest.main()
