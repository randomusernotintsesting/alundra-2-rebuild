"""Brightness text must not alter the calibration chart or triangle prompt."""
import hashlib
import importlib
import struct
import tempfile
import unittest
from pathlib import Path

from a2.pak import PakArchive
from menu_texture_patch import encode_lz, parse_container

try:
    patcher = importlib.import_module("brightness_texture_patch")
except ModuleNotFoundError:
    patcher = None

ROOT = Path(__file__).resolve().parent.parent
SLOTS = (361, 363, 365, 367, 369, 371, 373)
RECTS = ((12, 128, 232, 72), (76, 208, 64, 20))


class BrightnessTextureTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.stock = PakArchive.load(ROOT/"disc.orig/DATA/PACK0.PAK")
        cls.font, cls.reference = cls.stock.slots[548], cls.stock.slots[361]

    def setUp(self):
        self.assertIsNotNone(patcher, "Russian brightness patch is not implemented")
        self.arc = PakArchive(list(self.stock.slots))

    def patch(self):
        return patcher.patch_brightness_menu(self.arc, self.font, self.reference)

    def test_all_copies_keep_every_nontext_pixel_and_the_full_gradient_slot(self):
        before = list(self.arc.slots)
        report = self.patch()
        self.assertEqual(report["changed_slots"], list(SLOTS))
        self.assertEqual(len(report["labels"]), 5)
        for slot, (old, new) in enumerate(zip(before, self.arc.slots)):
            if slot not in SLOTS:
                self.assertEqual(new, old, f"unrequested slot {slot}, including gradients")
                continue
            w, h, old_pal, old_chunks = parse_container(old)
            _, _, new_pal, new_chunks = parse_container(new)
            self.assertEqual(new_pal, old_pal)
            self.assertEqual(new_chunks[0]["bpp"], 8, "do not repack 8bpp as 4bpp")
            op, np = old_chunks[0]["raw"], new_chunks[0]["raw"]
            for y in range(h):
                for x in range(w):
                    if not any(rx <= x < rx+rw and ry <= y < ry+rh for rx, ry, rw, rh in RECTS):
                        self.assertEqual(np[y*w+x], op[y*w+x], (slot, x, y))
            for top in (128, 146, 164, 182):
                pixels = b"".join(np[y*w+12:y*w+244] for y in range(top, top+16))
                self.assertGreater(pixels.count(25), 50, "a translated instruction line is missing")
            prompt = b"".join(np[y*w+76:y*w+140] for y in range(208, 228))
            self.assertGreater(prompt.count(25), 15, "Russian exit prompt is missing")
            # The far right of each text region is empty; preserve per-row
            # gray bands rather than flattening the background under text.
            for y in range(128, 200):
                self.assertEqual(np[y*w+242], op[y*w], f"background band row{y}")
            oe = old_chunks[0]["offset"] + old_chunks[0]["size"]
            ne = new_chunks[0]["offset"] + new_chunks[0]["size"]
            self.assertEqual(new[ne:], old[oe:])
        self.assertEqual(len({self.arc.slots[s] for s in SLOTS}), 1)

    def test_repeat_patch_is_byte_exact_noop(self):
        self.patch()
        once = list(self.arc.slots)
        self.assertEqual(self.patch()["changed_slots"], [])
        self.assertEqual(self.arc.slots, once)

    def test_unknown_last_palette_rejects_all_copies_atomically(self):
        data = bytearray(self.arc.slots[373])
        data[52 + 25*2] ^= 1
        self.arc.slots[373] = bytes(data)
        before = list(self.arc.slots)
        with self.assertRaisesRegex(ValueError, "palette"):
            self.patch()
        self.assertEqual(self.arc.slots, before)

    def _change_pixel(self, offset):
        data = self.arc.slots[373]
        w, h, _, chunks = parse_container(data)
        raw = bytearray(chunks[0]["raw"])
        raw[offset] ^= 1
        encoded = encode_lz(raw, bpp=8)
        prefix = bytearray(data[:chunks[0]["offset"]])
        struct.pack_into("<I", prefix, 12, len(encoded))
        self.arc.slots[373] = bytes(prefix) + encoded + data[chunks[0]["offset"]+chunks[0]["size"]:]
        return raw[offset]

    def test_unknown_instruction_rejects_without_partial_writes(self):
        self._change_pixel(135*256 + 20)
        before = list(self.arc.slots)
        with self.assertRaisesRegex(ValueError, "artwork"):
            self.patch()
        self.assertEqual(self.arc.slots, before)

    def test_unrelated_custom_pixel_survives(self):
        expected = self._change_pixel(254*256 + 230)
        self.patch()
        actual = parse_container(self.arc.slots[373])[3][0]["raw"]
        self.assertEqual(actual[254*256+230], expected)

    def test_unknown_pristine_font_or_reference_is_rejected(self):
        before = list(self.arc.slots)
        for font, ref in ((self.font[:-1]+b"!", self.reference),
                          (self.font, self.reference[:-1]+b"!")):
            with self.assertRaisesRegex(ValueError, "source"):
                patcher.patch_brightness_menu(self.arc, font, ref)
            self.assertEqual(self.arc.slots, before)

    def test_stage_reopens_output_without_overwriting_inputs_or_existing_stage(self):
        with tempfile.TemporaryDirectory(prefix="a2-brightness-stage-") as temp:
            folder = Path(temp)
            source, reference, output = folder/"source.pak", folder/"reference.pak", folder/"stage"
            slots = [None]*768
            slots[0] = b"PAK0"
            for slot in SLOTS:
                slots[slot] = self.reference
            slots[362] = self.stock.slots[362]
            PakArchive(slots).save(source)
            slots[548] = self.font
            PakArchive(slots).save(reference)
            original = hashlib.sha256(source.read_bytes()).digest()
            report = patcher.stage_patch(source, reference, output)
            self.assertEqual(report["changed_slots"], list(SLOTS))
            self.assertEqual(hashlib.sha256(source.read_bytes()).digest(), original)
            saved = PakArchive.load(output/"DATA/PACK0.PAK")
            self.assertEqual(saved.slots[362], self.stock.slots[362])
            self.assertEqual(patcher.patch_brightness_menu(saved, self.font, self.reference)["changed_slots"], [])
            written = hashlib.sha256((output/"DATA/PACK0.PAK").read_bytes()).digest()
            with self.assertRaises(FileExistsError):
                patcher.stage_patch(source, reference, output)
            self.assertEqual(hashlib.sha256((output/"DATA/PACK0.PAK").read_bytes()).digest(), written)
            self.assertTrue((output/"after_atlas_3x.png").is_file())


if __name__ == "__main__":
    unittest.main()
