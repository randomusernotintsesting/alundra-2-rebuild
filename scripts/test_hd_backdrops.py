import importlib
import unittest
import hashlib
from pathlib import Path
from a2.pak import PakArchive

ROOT=Path(__file__).resolve().parents[1]

class HDBackdropTests(unittest.TestCase):
    def test_repeat_contracts_share_one_palette_driven_tile(self):
        module=importlib.import_module('build_hd_backdrops')
        assets=module.build_backdrops(PakArchive.load(ROOT/'disc.orig/DATA/PACK0.PAK'))
        self.assertEqual(len(assets),4)
        for a in assets:
            self.assertEqual(a['bpp'],4)
            self.assertEqual(a['uv'][2:],(32,64))
            self.assertEqual(hashlib.sha256(a['source']).hexdigest(),
                             '07516a4b45c8f255e4baa456aa63f6453d020c1259f919fef26dd1c9a3390cac')
            self.assertEqual(a['pixels'],assets[0]['pixels'])
            self.assertTrue(all(p>>24==255 for p in a['pixels']))
            self.assertTrue(all((p&255)>0 and ((p>>8)&255)>0 for p in a['pixels']))
        # Repeated outer border has no mismatched first/last fine rows.
        pixels=assets[0]['pixels']
        self.assertEqual(pixels[:128],pixels[-128:])

if __name__=='__main__':unittest.main()
