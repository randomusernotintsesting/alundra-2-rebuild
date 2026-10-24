import tempfile
import unittest
from pathlib import Path
from PIL import Image
import export_portraits as exporter


class PortraitExportTests(unittest.TestCase):
    def test_palette_zero_is_not_necessarily_transparent(self):
        # Opaque index0, transparent nonzero1, opaque STP-black2.
        palette = bytes((31, 128, 0, 0, 0, 128)) + bytes(506)
        rgba = exporter.decode_rgba(bytes((0, 1, 2)), palette)
        self.assertEqual(rgba, bytes((255, 0, 0, 255, 0, 0, 0, 0, 0, 0, 0, 255)))

    def test_export_preserves_size_pixels_ids_and_refuses_overwrite(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp) / 'portraits'
            records = exporter.export_portraits(exporter.DEFAULT_PAK, root)
            self.assertEqual([r['slot'] for r in records], list(range(14)))
            for record in records:
                with Image.open(root / 'PNG' / record['file']) as im:
                    self.assertEqual(im.size, (40, 48))
                    self.assertEqual(im.mode, 'RGBA')
                self.assertEqual(len(record['slot_sha256']), 64)
            with self.assertRaises(FileExistsError):
                exporter.export_portraits(exporter.DEFAULT_PAK, root)
            self.assertTrue((root / 'manifest.json').is_file())


if __name__ == '__main__':
    unittest.main()
