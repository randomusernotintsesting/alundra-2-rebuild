"""Small resident-only loading proofs; never build the full art header or run a game."""
import hashlib
from pathlib import Path
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
EXE = ROOT / 'port/build/game-data/disc/SCPS_101.15'


class LoadingAssetsTests(unittest.TestCase):
    def test_native_sources_and_animation_are_preserved(self):
        from build_hd_loading import build_loading, loading_source, FRAME_ORDER
        before = EXE.read_bytes()
        source = loading_source(EXE)
        assets = build_loading(EXE)
        self.assertEqual(EXE.read_bytes(), before)
        self.assertEqual(len(source['primitives']), 24)
        self.assertEqual(FRAME_ORDER, (0, 1, 2, 3, 4, 5, 6, 7, 6, 5))
        self.assertEqual(len(assets), 10)
        labels = [a for a in assets if 'text' in a]
        self.assertEqual([(a['text'], a['language_mask']) for a in labels],
                         [('Загрузка', 1), ('Now Loading', 6)])
        self.assertEqual({a['uv'] for a in labels}, {(0, 176, 96, 16)})
        for a in assets:
            x, y, w, h = a['source_rect']
            expected = b''.join(source['indices'][row * 256 + x:row * 256 + x + w]
                                for row in range(y, y + h))
            self.assertEqual(a['source'], expected)
            self.assertEqual(a['source_sha256'], hashlib.sha256(expected).hexdigest())
            self.assertEqual(a['uv'], (x, y + 64, w, h))
            self.assertEqual(a['bpp'], 4)
            self.assertEqual(len(a['pixels']), w * h * 16)
            self.assertTrue(any(0 < p >> 24 < 255 for p in a['pixels']))
            self.assertTrue(all((p & 255) < 16 and ((p >> 8) & 255) < 16 for p in a['pixels']))

    def test_rejects_changed_atlas_or_native_composition(self):
        from build_hd_loading import build_loading
        before = EXE.read_bytes()
        with tempfile.TemporaryDirectory() as temp:
            path = Path(temp) / 'SCPS_101.15'
            for offset in (0x395d8 + 600, 0x3d584 + 12):
                changed = bytearray(before)
                changed[offset] ^= 1
                path.write_bytes(changed)
                with self.assertRaisesRegex(ValueError, 'loading'):
                    build_loading(path)

    def test_preview_uses_all_original_frames_and_same_geometry(self):
        from build_hd_loading import build_loading, loading_source, preview_frames
        source = loading_source(EXE)
        native = preview_frames(source)
        hd = preview_frames(source, build_loading(EXE), language=0)
        self.assertEqual(len(native), 8)
        self.assertEqual([im.size for im in hd], [(512, 128)] * 8)
        self.assertGreater(len({im.tobytes() for im in native}), 5)
        self.assertTrue(all(a.tobytes() != b.tobytes() for a, b in zip(native, hd)))


if __name__ == '__main__':
    unittest.main()
