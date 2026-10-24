"""Protect save-menu artwork, LZ upload boundaries and staged-only patching."""
import struct
import hashlib
import tempfile
import unittest
from pathlib import Path

from a2.pak import PakArchive
from menu_texture_patch import (LABELS, SLOTS, decode_chunk, encode_lz,
                                parse_container, patch_load_menu, stage_patch, unpack_indices)

ROOT = Path(__file__).resolve().parent.parent


class MenuTextureTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.stock = PakArchive.load(ROOT / "disc.orig/DATA/PACK0.PAK")
        cls.font = PakArchive.load(ROOT / "disc_jp.orig/DATA/PACK0.PAK").slots[548]

    def test_encoder_preserves_overlapping_matches_and_upload_boundaries(self):
        for raw, w, h, bpp in ((b"ABABABAB", 8, 1, 8),
                               (bytes(32768), 256, 256, 4),
                               (bytes(range(256)) * 256, 256, 256, 8)):
            with self.subTest(size=len(raw)):
                encoded = encode_lz(raw, bpp)
                self.assertGreater(len(encoded), 4, "encoder must produce a native chunk")
                self.assertEqual(decode_chunk(encoded, w, h), raw)

    def test_all_copies_change_only_three_uv_rectangles(self):
        arc = PakArchive(list(self.stock.slots))
        before = list(arc.slots)
        report = patch_load_menu(arc, self.font)
        self.assertEqual(report.get("changed_slots"), list(SLOTS))
        for index, (old, new) in enumerate(zip(before, arc.slots)):
            if index not in SLOTS:
                self.assertEqual(new, old, f"unrelated slot {index} changed")
                continue
            w, h, old_pal, old_chunks = parse_container(old)
            _, _, new_pal, new_chunks = parse_container(new)
            self.assertEqual(new_pal, old_pal)
            self.assertEqual(new_chunks[1]["compressed"], old_chunks[1]["compressed"])
            old_px = unpack_indices(old_chunks[0]["raw"], w, h, 4)
            new_px = unpack_indices(new_chunks[0]["raw"], w, h, 4)
            for y in range(h):
                for x in range(w):
                    inside = any(rx <= x < rx + rw and ry <= y < ry + rh
                                 for _, (rx, ry, rw, rh) in LABELS)
                    if not inside:
                        self.assertEqual(new_px[y*w+x], old_px[y*w+x], (x, y))
            for text, (rx, ry, rw, rh) in LABELS:
                old_label = b"".join(old_px[y*w+rx:y*w+rx+rw] for y in range(ry, ry+rh))
                new_label = b"".join(new_px[y*w+rx:y*w+rx+rw] for y in range(ry, ry+rh))
                self.assertNotEqual(new_label, old_label, text)
                self.assertIn(15, new_label, text)
        self.assertTrue(all(arc.slots[s] == arc.slots[SLOTS[0]] for s in SLOTS))

    def test_patch_is_idempotent(self):
        arc = PakArchive(list(self.stock.slots))
        patch_load_menu(arc, self.font)
        once = list(arc.slots)
        report = patch_load_menu(arc, self.font)
        self.assertEqual(report.get("changed_slots"), [])
        self.assertEqual(arc.slots, once)

    def test_unknown_last_copy_rejects_without_modifying_first_copy(self):
        arc = PakArchive(list(self.stock.slots))
        changed = bytearray(arc.slots[SLOTS[-1]])
        struct.pack_into("<H", changed, 8, 128)  # incompatible UV coordinate space
        arc.slots[SLOTS[-1]] = bytes(changed)
        before = list(arc.slots)
        with self.assertRaises(ValueError):
            patch_load_menu(arc, self.font)
        self.assertEqual(arc.slots, before)

    def test_stage_writes_new_archive_and_preserves_source_and_existing_directory(self):
        with tempfile.TemporaryDirectory(prefix="a2-menu-stage-") as folder:
            folder = Path(folder)
            source, fonts, output = folder / "source.pak", folder / "fonts.pak", folder / "stage"
            slots = [None] * 768
            slots[0] = b"PAK0"  # first TOC entry stores its byte size in this format
            for slot in SLOTS:
                slots[slot] = self.stock.slots[slot]
            PakArchive(slots).save(source)
            font_slots = [None] * 768
            font_slots[0] = b"PAK0"
            font_slots[548] = self.font
            PakArchive(font_slots).save(fonts)
            before = hashlib.sha256(source.read_bytes()).digest()
            report = stage_patch(source, fonts, output)
            self.assertTrue((output / "DATA/PACK0.PAK").is_file(), "staged PAK missing")
            self.assertEqual(report.get("changed_slots"), list(SLOTS))
            self.assertEqual(hashlib.sha256(source.read_bytes()).digest(), before)
            offsets = struct.unpack_from("<768I", (output / "DATA/PACK0.PAK").read_bytes())
            self.assertTrue(all(not offset or offset % 4 == 0 for offset in offsets))
            staged = PakArchive.load(output / "DATA/PACK0.PAK")
            self.assertEqual(patch_load_menu(staged, self.font)["changed_slots"], [])
            with self.assertRaises(FileExistsError):
                stage_patch(source, fonts, output)
            self.assertEqual(hashlib.sha256(source.read_bytes()).digest(), before)


if __name__ == "__main__":
    unittest.main()
