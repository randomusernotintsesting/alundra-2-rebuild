"""The production art build must include resident window and loading assets."""
import json
from pathlib import Path
import tempfile
import unittest

from build_hd_art import generate

ROOT=Path(__file__).resolve().parents[1]
PAK=ROOT/'port/build/verification/full-menu-v6/DATA/PACK0.PAK'
EXE=ROOT/'disc_jp/SCPS_101.15'

@unittest.skipUnless(PAK.exists() and EXE.exists(),'requires local v6 assets and Japanese EXE')
class HDArtIntegrationTests(unittest.TestCase):
    def test_full_generation_includes_resident_frame_item_branding_and_loading(self):
        with tempfile.TemporaryDirectory() as temporary:
            out=Path(temporary)
            generate(PAK,out/'art.h',out/'previews',include_menus=True,
                     include_items=True,exe=EXE,include_branding=True,include_loading=True)
            records=json.loads((out/'previews/manifest.json').read_text())
            frames=[r for r in records if r['name']=='description_frame']
            self.assertEqual(len(frames),1)
            self.assertEqual(frames[0]['uv'],[0,144,24,24])
            self.assertEqual(frames[0]['source_kind'],'resident_exe')
            self.assertTrue((out/'previews/description_frame.png').is_file())
            self.assertEqual(len([r for r in records if r['name']=='item_herb']),1)
            self.assertTrue((out/'previews/item_herb.png').is_file())
            self.assertEqual(len(records),76)
            self.assertFalse(any(r.get('brand')=='contrail' for r in records))
            loading=[r for r in records if r['name'].startswith('loading_')]
            self.assertEqual(len(loading),10)
            labels=[r for r in loading if 'text' in r]
            self.assertEqual([(r['text'],r['language_mask']) for r in labels],
                             [('Загрузка',1),('Now Loading',6)])
            self.assertTrue(all(r['language_mask']==0 for r in records
                                if r not in labels))

if __name__=='__main__':unittest.main()
