"""Russian menu patch must preserve frames, alternate art and the input archive."""
import hashlib
import importlib
import struct
import tempfile
import unittest
from pathlib import Path

from a2.pak import PakArchive
from menu_texture_patch import encode_lz, parse_container, unpack_indices

try:
    patcher = importlib.import_module("pocket_texture_patch")
except ModuleNotFoundError:
    patcher = None

ROOT = Path(__file__).resolve().parent.parent
SLOTS = (298, 303, 308, 313, 318, 323, 328)
# Actual GP0 source areas, not imported from the implementation.
RECTS = ((0, 0, 0, 72, 24), (0, 72, 0, 72, 24), (0, 0, 24, 72, 24),
         (0, 72, 24, 72, 24), (1, 16, 56, 104, 32))


class PocketTextureTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.stock = PakArchive.load(ROOT / "disc.orig/DATA/PACK0.PAK")
        cls.font = cls.stock.slots[548]
        cls.reference = cls.stock.slots[298]

    def setUp(self):
        self.assertIsNotNone(patcher, "Russian Pocket texture patch is not implemented")
        self.arc = PakArchive(list(self.stock.slots))

    def patch(self):
        return patcher.patch_pocket_menu(self.arc, self.font, self.reference)

    def test_all_copies_translate_without_repainting_frames_or_other_art(self):
        before = list(self.arc.slots)
        report = self.patch()
        self.assertEqual(report["changed_slots"], list(SLOTS))
        self.assertEqual(set(report["labels"]), {"Карманы", "Предметы", "Стихии", "Особое", "Настройки"})
        for slot, (old, new) in enumerate(zip(before, self.arc.slots)):
            if slot not in SLOTS:
                self.assertEqual(new, old, f"unrequested slot {slot}")
                continue
            w, h, old_pal, old_chunks = parse_container(old)
            _, _, new_pal, new_chunks = parse_container(new)
            self.assertEqual(new_pal, old_pal, "all palette/selection states must survive")
            for page in (0, 1):
                op = unpack_indices(old_chunks[page]["raw"], w, h, 4)
                np = unpack_indices(new_chunks[page]["raw"], w, h, 4)
                self.assertNotEqual(op, np)
                for y in range(h):
                    for x in range(w):
                        inside = any(page == p and rx <= x < rx+rw and ry <= y < ry+rh
                                     for p, rx, ry, rw, rh in RECTS)
                        if not inside:
                            self.assertEqual(np[y*w+x], op[y*w+x], (slot, page, x, y))
                        elif page == 0 and op[y*w+x] in (1, 2, 3, 4, 15):
                            self.assertEqual(np[y*w+x], op[y*w+x], "tab frame/transparency")
                        elif page == 1 and (x < 21 or x >= 115 or y < 61 or y >= 81):
                            self.assertEqual(np[y*w+x], op[y*w+x], "Pocket frame")
                for p, x, y, rw, rh in RECTS:
                    if p == page:
                        a = b"".join(op[r*w+x:r*w+x+rw] for r in range(y, y+rh))
                        b = b"".join(np[r*w+x:r*w+x+rw] for r in range(y, y+rh))
                        self.assertNotEqual(a, b, "a requested label was left English")
                        self.assertGreater(b.count(0 if page == 0 else 14), 30,
                                           "original lettering was erased but Russian ink is missing")
            old_end = old_chunks[-1]["offset"] + old_chunks[-1]["size"]
            new_end = new_chunks[-1]["offset"] + new_chunks[-1]["size"]
            self.assertEqual(old[old_end:], new[new_end:], "trailing bytes lost")
        self.assertEqual(len({self.arc.slots[s] for s in SLOTS}), 1)

    def test_patch_is_idempotent(self):
        self.patch()
        once = list(self.arc.slots)
        self.assertEqual(self.patch()["changed_slots"], [])
        self.assertEqual(self.arc.slots, once)

    def test_element_translation_can_extend_an_existing_four_label_patch(self):
        # Restore just Element to English, simulating the previously reviewed
        # four-label stage. The upgrade must not re-render its Russian labels.
        self.patch()
        w, h, _, original_chunks = parse_container(self.reference)
        for slot in SLOTS:
            data = self.arc.slots[slot]
            chunks = parse_container(data)[3]
            raw = bytearray(chunks[0]["raw"])
            for y in range(24):
                raw[y*w//2+36:y*w//2+72] = original_chunks[0]["raw"][y*w//2+36:y*w//2+72]
            encoded = encode_lz(raw)
            header = bytearray(data[:chunks[0]["offset"]])
            struct.pack_into("<I", header, 12, len(encoded))
            self.arc.slots[slot] = bytes(header) + encoded + data[chunks[1]["offset"]:]
        before = list(self.arc.slots)
        self.assertEqual(self.patch()["changed_slots"], list(SLOTS))
        for slot in SLOTS:
            old = parse_container(before[slot])[3]
            new = parse_container(self.arc.slots[slot])[3]
            self.assertEqual(new[1]["compressed"], old[1]["compressed"])
            for y in range(h):
                for x in range(w//2):
                    if y >= 24 or not 36 <= x < 72:
                        self.assertEqual(new[0]["raw"][y*w//2+x], old[0]["raw"][y*w//2+x])

    def test_unknown_last_copy_is_rejected_atomically(self):
        bad = bytearray(self.arc.slots[SLOTS[-1]])
        bad[52 + 12*32] ^= 1  # Pocket CLUT
        self.arc.slots[SLOTS[-1]] = bytes(bad)
        before = list(self.arc.slots)
        with self.assertRaisesRegex(ValueError, "palette"):
            self.patch()
        self.assertEqual(self.arc.slots, before)

    def test_unknown_label_art_is_rejected_atomically(self):
        data = self.arc.slots[SLOTS[-1]]
        w, h, _, chunks = parse_container(data)
        raw = bytearray(chunks[0]["raw"])
        raw[10*w//2 + 20] ^= 1
        encoded = encode_lz(raw)
        prefix = bytearray(data[:chunks[0]["offset"]])
        struct.pack_into("<I", prefix, 12, len(encoded))
        self.arc.slots[SLOTS[-1]] = bytes(prefix) + encoded + data[chunks[1]["offset"]:]
        before = list(self.arc.slots)
        with self.assertRaisesRegex(ValueError, "artwork"):
            self.patch()
        self.assertEqual(self.arc.slots, before)

    def test_unknown_reference_or_font_cannot_generate_a_patch(self):
        before = list(self.arc.slots)
        for font, reference in ((self.font[:-1] + b"!", self.reference),
                                (self.font, self.reference[:-1] + b"!")):
            with self.subTest(font_changed=font != self.font):
                with self.assertRaisesRegex(ValueError, "source"):
                    patcher.patch_pocket_menu(self.arc, font, reference)
                self.assertEqual(self.arc.slots, before)

    def test_unrelated_custom_pixel_is_preserved(self):
        data = self.arc.slots[SLOTS[-1]]
        w, h, _, chunks = parse_container(data)
        raw = bytearray(chunks[0]["raw"])
        raw[210*w//2 + 100] ^= 1
        encoded = encode_lz(raw)
        prefix = bytearray(data[:chunks[0]["offset"]])
        struct.pack_into("<I", prefix, 12, len(encoded))
        self.arc.slots[SLOTS[-1]] = bytes(prefix) + encoded + data[chunks[1]["offset"]:]
        self.patch()
        after = parse_container(self.arc.slots[SLOTS[-1]])[3][0]["raw"]
        self.assertEqual(after[210*w//2 + 100], raw[210*w//2 + 100])

    def test_stage_never_overwrites_source_or_existing_output(self):
        with tempfile.TemporaryDirectory(prefix="a2-pocket-stage-") as temp:
            folder = Path(temp)
            source, reference, output = folder/"source.pak", folder/"reference.pak", folder/"stage"
            slots = [None] * 768
            slots[0] = b"PAK0"
            for s in SLOTS:
                slots[s] = self.reference
            PakArchive(slots).save(source)
            slots[548] = self.font
            PakArchive(slots).save(reference)
            before = hashlib.sha256(source.read_bytes()).digest()
            report = patcher.stage_patch(source, reference, output)
            self.assertEqual(report["changed_slots"], list(SLOTS))
            self.assertEqual(hashlib.sha256(source.read_bytes()).digest(), before)
            saved = PakArchive.load(output/"DATA/PACK0.PAK")
            self.assertEqual(patcher.patch_pocket_menu(saved, self.font, self.reference)["changed_slots"], [])
            destination_hash = hashlib.sha256((output/"DATA/PACK0.PAK").read_bytes()).digest()
            with self.assertRaises(FileExistsError):
                patcher.stage_patch(source, reference, output)
            self.assertEqual(hashlib.sha256((output/"DATA/PACK0.PAK").read_bytes()).digest(), destination_hash)
            self.assertTrue((output/"after_labels_4x.png").is_file())
            from PIL import Image
            with Image.open(output/"after_labels_4x.png") as preview:
                self.assertEqual(preview.size, (448, 512), "preview clips one of the five labels")


if __name__ == "__main__":
    unittest.main()
