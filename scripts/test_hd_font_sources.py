"""Original English font styles must all match without weakening identity."""
import hashlib
import json
from pathlib import Path
import subprocess
import tempfile
import unittest

from a2.pak import PakArchive
from build_hd_font_sources import SLOTS, header_text, metadata, sources

ROOT=Path(__file__).resolve().parents[1]


class HDFontSourceTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.original=PakArchive.load(ROOT/'disc_jp.orig/DATA/PACK0.PAK')

    def test_all_original_style_bytes_preserved_and_embedded_output_current(self):
        before=list(self.original.slots)
        data=sources(self.original)
        self.assertEqual(self.original.slots,before)
        for height,slots in SLOTS.items():
            self.assertEqual(data[height]['banks'][1:],[before[s] for s in slots])
            self.assertEqual(len(set(data[height]['keys'])),6)
            self.assertEqual(len(set(hashlib.sha256(b).hexdigest() for b in data[height]['banks'])),6)
        self.assertEqual((ROOT/'port/assets/hd_font_sources.h').read_text(),header_text(data))
        self.assertEqual(json.loads((ROOT/'port/assets/hd_font_sources.json').read_text()),metadata(data))

    def test_unknown_style_dimensions_rejected(self):
        damaged=PakArchive(list(self.original.slots));damaged.slots[536]=b'unknown'
        with self.assertRaises(ValueError):
            sources(damaged)

    def test_real_host_accepts_captured_event_cache_and_all_variants_with_ubsan(self):
        with tempfile.TemporaryDirectory(prefix='a2-hd-font-styles-') as directory:
            directory=Path(directory)
            for slots in SLOTS.values():
                for slot in slots:
                    (directory/f'bank{slot}.bin').write_bytes(self.original.slots[slot])
            exe=directory/'test_hd_font_styles'
            subprocess.run(['clang','-std=c11','-O1','-g','-UNDEBUG',
                            '-fsanitize=undefined','-Wall','-Wextra','-Werror',
                            '-I'+str(ROOT/'port/src'),str(ROOT/'port/tests/test_hd_font_styles.c'),
                            '-o',str(exe)],check=True,capture_output=True,text=True)
            result=subprocess.run([str(exe),str(directory)],check=True,capture_output=True,text=True)
            self.assertIn('All ten original Latin style banks',result.stdout)
            self.assertEqual(result.stderr,'')


if __name__=='__main__':
    unittest.main()
