"""Reject damaged imports before output, and preserve decoded RGBA/source identity."""
import copy
import hashlib
import importlib.util
import json
from pathlib import Path
import shutil
import struct
import subprocess
import tempfile
import unittest
from PIL import Image
from a2.pak import PakArchive
from menu_texture_patch import parse_container, unpack_indices

ROOT = Path(__file__).resolve().parents[1]
ASSETS = ROOT / 'port/assets/portraits'
PAK = ROOT / 'port/build/verification/full-menu-v6/disc/DATA/PACK0.PAK'


class PortraitImport(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        path = ROOT / 'scripts/build_hd_portraits.py'
        cls.builder = None
        if path.exists():
            spec = importlib.util.spec_from_file_location('portraits_builder', path)
            cls.builder = importlib.util.module_from_spec(spec)
            spec.loader.exec_module(cls.builder)
        cls.manifest = json.loads((ASSETS / 'manifest.json').read_text())
        cls.archive = PakArchive.load(PAK)

    def require_builder(self):
        self.assertIsNotNone(self.builder, 'RGBA portrait generator is not implemented')
        return self.builder

    def test_all_fourteen_exact_pixels_and_original_signatures(self):
        b = self.require_builder()
        records = b.load_portraits(ASSETS, PAK)
        self.assertEqual([r['id'] for r in records], list(range(14)))
        for r, entry in zip(records, self.manifest['portraits']):
            slot = self.archive.slots[r['id']]
            w, h, pal, chunks = parse_container(slot)
            indices = unpack_indices(chunks[0]['raw'], w, h, 8)
            with Image.open(ASSETS / entry['path']) as im:
                self.assertEqual(r['rgba'], im.tobytes())
            self.assertEqual((r['width'], r['height']), (320, 384))
            self.assertEqual(r['indices'], indices)
            self.assertEqual(r['palette'], pal)
            self.assertEqual(hashlib.sha256(slot).hexdigest(), entry['source_slot_sha256'])
            self.assertEqual(hashlib.sha256(indices).hexdigest(), entry['source_indices_sha256'])
            alpha = r['rgba'][3::4]
            self.assertIn(0, alpha); self.assertIn(255, alpha)
            self.assertTrue(any(0 < a < 255 for a in alpha))
            colors = struct.unpack('<256H', pal)
            self.assertFalse(any(colors[i] & 0x8000 for i in indices))

    def test_invalid_import_never_replaces_existing_output(self):
        b = self.require_builder()
        mutations = {
            'missing': lambda m: m['portraits'].pop(),
            'duplicate': lambda m: m['portraits'].__setitem__(1, copy.deepcopy(m['portraits'][0])),
            'id': lambda m: m['portraits'][0].update(id=14),
            'slot': lambda m: m['portraits'][0].update(slot=3),
            'file': lambda m: m['portraits'][0].update(file='else.png'),
            'path': lambda m: m['portraits'][0].update(path='../else.png'),
            'dimensions': lambda m: m['portraits'][0].update(width=160),
            'mode': lambda m: m['portraits'][0].update(mode='RGB'),
            'png_hash': lambda m: m['portraits'][0].update(sha256='0'*64),
            'slot_hash': lambda m: m['portraits'][0].update(source_slot_sha256='0'*64),
            'indices_hash': lambda m: m['portraits'][0].update(source_indices_sha256='0'*64),
        }
        with tempfile.TemporaryDirectory() as temp:
            asset = Path(temp) / 'assets'
            shutil.copytree(ASSETS, asset)
            output = Path(temp) / 'out.h'
            for name, mutate in mutations.items():
                with self.subTest(name=name):
                    manifest = copy.deepcopy(self.manifest); mutate(manifest)
                    (asset / 'manifest.json').write_text(json.dumps(manifest))
                    output.write_text('previous output')
                    with self.assertRaises(ValueError):
                        b.build(asset, PAK, output)
                    self.assertEqual(output.read_text(), 'previous output')

    def test_actual_image_mode_dimensions_and_alpha_contract(self):
        b = self.require_builder()
        with tempfile.TemporaryDirectory() as temp:
            asset = Path(temp) / 'assets'; shutil.copytree(ASSETS, asset)
            path = asset / self.manifest['portraits'][0]['path']
            for mode, size, color in [('RGB', (320,384), (1,2,3)),
                                      ('RGBA', (160,192), (1,2,3,255)),
                                      ('RGBA', (320,384), (1,2,3,255))]:
                with self.subTest(mode=mode,size=size):
                    Image.new(mode, size, color).save(path)
                    manifest = copy.deepcopy(self.manifest)
                    manifest['portraits'][0]['sha256'] = hashlib.sha256(path.read_bytes()).hexdigest()
                    (asset / 'manifest.json').write_text(json.dumps(manifest))
                    with self.assertRaises(ValueError):
                        b.load_portraits(asset, PAK)

    def test_generated_c_consumer_receives_exact_original_and_rgba_bytes(self):
        # Catch serialization/channel-order/truncation bugs in the emitted C,
        # independently of load_portraits' in-memory decoded records.
        b = self.require_builder()
        with tempfile.TemporaryDirectory() as temp:
            temp = Path(temp)
            b.build(ASSETS, PAK, temp / 'generated.h')
            source = temp / 'consumer.c'
            source.write_text('''#include <stdio.h>
#include "generated.h"
int main(void) {
    if (a2_hd_portraits_asset_count != 14) return 2;
    for (unsigned i=0;i<14;i++) {
        const A2HDPortrait *p=&a2_hd_portraits_assets[i];
        if (p->width!=320 || p->height!=384) return 3;
        fwrite(p->source,1,40*48,stdout);
        for (unsigned c=0;c<256;c++) {
            putchar(p->palette[c]&255); putchar(p->palette[c]>>8);
        }
        fwrite(p->rgba,1,(size_t)p->width*p->height*4,stdout);
    }
    return ferror(stdout)?4:0;
}
''')
            subprocess.run(['cc','-std=c11','-I',str(ROOT / 'port/src'),str(source),
                            '-o',str(temp / 'consumer')], check=True, capture_output=True)
            actual = subprocess.run([str(temp / 'consumer')], check=True, capture_output=True).stdout
            expected = bytearray()
            for entry in self.manifest['portraits']:
                w,h,pal,chunks = parse_container(self.archive.slots[entry['id']])
                expected += unpack_indices(chunks[0]['raw'],w,h,8)
                expected += pal
                with Image.open(ASSETS / entry['path']) as im:
                    expected += im.tobytes()
            self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
