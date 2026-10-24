import unittest
from pathlib import Path
from a2.pak import PakArchive
from export_ui_sources import decode_region

ROOT=Path(__file__).resolve().parents[1]

class BrandingTests(unittest.TestCase):
    def test_branding_replaces_only_identified_source_rectangles(self):
        from build_hd_branding import build_branding
        archive=PakArchive.load(ROOT/'port/build/verification/full-menu-v6/disc/DATA/PACK0.PAK')
        before=list(archive.slots)
        assets=build_branding(archive)
        self.assertEqual(len(assets),8)
        self.assertEqual(archive.slots,before)
        self.assertEqual({a['brand'] for a in assets},{'title','sony','matrix','copyright'})
        for a in assets:
            source,palette,bpp=decode_region(archive,23,a['page'],a['uv'],a['clut_bank'])
            self.assertEqual(a['source'],source)
            self.assertEqual(a['palette'],palette)
            self.assertEqual(bpp,8)
            self.assertEqual(len(a['pixels']),a['uv'][2]*a['uv'][3]*16)
            alpha=[p>>24 for p in a['pixels']]
            self.assertIn(0,alpha)
            # The short copyright and aspect-corrected Matrix mark fit in
            # their first page. Keep a transparent second replacement to
            # remove the original text/mark remaining on that source slice.
            if not any(alpha):
                self.assertIn((a['brand'],a['page']),{('copyright',1),('matrix',7)})
        for brand in {a['brand'] for a in assets}:
            self.assertTrue(any(p>>24 for a in assets if a['brand']==brand for p in a['pixels']))
        title=[a for a in assets if a['brand']=='title']
        self.assertEqual([a['page'] for a in title],[0,1])
        self.assertTrue(all(a['uv'][1]+a['uv'][3]<=160 for a in title))

if __name__=='__main__':unittest.main()
