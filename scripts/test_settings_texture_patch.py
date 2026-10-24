"""Settings localization must preserve native frames, prompts and state palettes."""
import hashlib
import importlib
import struct
import tempfile
import unittest
from unittest.mock import patch
from pathlib import Path

from a2.pak import PakArchive
from menu_texture_patch import encode_lz, parse_container, unpack_indices

try:
    patcher = importlib.import_module("settings_texture_patch")
except ModuleNotFoundError:
    patcher = None

ROOT = Path(__file__).resolve().parent.parent
SLOTS = tuple(range(333, 340))
# Hand checked against GP0 frame6399 and original button-word masks.
RECTS = [(0, (0, 168, 184, 24)), (0, (0, 192, 136, 24)), (0, (0, 216, 136, 24)),
         (0, (24, 98, 52, 28)), (0, (24, 130, 52, 28)), (0, (208, 58, 44, 28))]
RECTS += [(0, (120, y, 136, 24)) for y in (96, 120, 144)]
RECTS += [(1, (0, y, 114, 24)) for y in range(0, 216, 24)]
RECTS += [(1, (120, y, 136, 24)) for y in range(0, 240, 24)]


class SettingsTextureTests(unittest.TestCase):
    def test_japanese_circle_applies_and_cross_cancels(self):
        labels={s[3]:s[1] for s in patcher.LABELS}
        self.assertEqual(labels[(24,98,52,28)],'Выбрать')
        self.assertEqual(labels[(24,130,52,28)],'Отмена')

    def test_migrates_only_known_reversed_legacy_prompts(self):
        legacy=[]
        for s in patcher.LABELS:
            legacy.append((s[0],{8:'Отмена',9:'Выбрать'}.get(s[4],s[1]),*s[2:]))
        with patch.object(patcher,'LABELS',tuple(legacy)):
            self.patch()
        before=list(self.arc.slots)
        self.assertEqual(self.patch()['changed_slots'],list(SLOTS))
        for slot in SLOTS:
            w,h,_,old=parse_container(before[slot]);_,_,_,new=parse_container(self.arc.slots[slot])
            self.assertEqual(old[1]['compressed'],new[1]['compressed'])
            a=unpack_indices(old[0]['raw'],w,h,4);b=unpack_indices(new[0]['raw'],w,h,4)
            for i,(x,y) in enumerate(zip(a,b)):
                if not (24<=i%w<76 and (98<=i//w<126 or 130<=i//w<158)):
                    self.assertEqual(x,y)
        once=list(self.arc.slots);self.assertEqual(self.patch()['changed_slots'],[])
        self.assertEqual(self.arc.slots,once)

    @classmethod
    def setUpClass(cls):
        cls.stock = PakArchive.load(ROOT/"disc.orig/DATA/PACK0.PAK")
        cls.font, cls.reference = cls.stock.slots[548], cls.stock.slots[333]

    def setUp(self):
        self.assertIsNotNone(patcher, "Russian Settings texture patch is not implemented")
        self.arc = PakArchive(list(self.stock.slots))

    def patch(self):
        return patcher.patch_settings_menu(self.arc, self.font, self.reference)

    def test_all_28_labels_change_in_all_copies_without_repainting_frames(self):
        before = list(self.arc.slots)
        report = self.patch()
        self.assertEqual(report["changed_slots"], list(SLOTS))
        self.assertEqual(len(report["labels"]), 28)
        self.assertIn("Шрифт 4", report["labels"])
        self.assertIn("Удержание", report["labels"])
        for slot, (old, new) in enumerate(zip(before, self.arc.slots)):
            if slot not in SLOTS:
                self.assertEqual(new, old, f"unrequested slot {slot}")
                continue
            w, h, old_pal, old_chunks = parse_container(old)
            _, _, new_pal, new_chunks = parse_container(new)
            self.assertEqual(new_pal, old_pal, "selected/disabled palette changed")
            for page in (0, 1):
                op = unpack_indices(old_chunks[page]["raw"], w, h, 4)
                np = unpack_indices(new_chunks[page]["raw"], w, h, 4)
                for y in range(h):
                    for x in range(w):
                        if not any(page == p and rx <= x < rx+rw and ry <= y < ry+rh
                                   for p, (rx, ry, rw, rh) in RECTS):
                            self.assertEqual(np[y*w+x], op[y*w+x], (slot, page, x, y))
                for p, (x, y, rw, rh) in RECTS:
                    if p != page:
                        continue
                    a = b"".join(op[r*w+x:r*w+x+rw] for r in range(y, y+rh))
                    b = b"".join(np[r*w+x:r*w+x+rw] for r in range(y, y+rh))
                    self.assertNotEqual(a, b, (slot, page, x, y))
                    if page == 1 or (x, y) not in ((24, 98), (24, 130), (208, 58)):
                        self.assertGreater(b.count(15), 12, "label erased without Russian ink")
                    else:
                        frame, white = {(24, 98): ({12, 13, 14}, 2),
                                        (24, 130): ({11, 12, 13}, 7),
                                        (208, 58): ({11, 12, 13}, 9)}[x, y]
                        self.assertGreater(b.count(white), 12, "button label has no Russian ink")
                        for old_pixel, new_pixel in zip(a, b):
                            if old_pixel in frame:
                                self.assertEqual(new_pixel, old_pixel, "button bevel corner changed")
            oe = old_chunks[-1]["offset"] + old_chunks[-1]["size"]
            ne = new_chunks[-1]["offset"] + new_chunks[-1]["size"]
            self.assertEqual(new[ne:], old[oe:])
        self.assertEqual(len({self.arc.slots[s] for s in SLOTS}), 1)

    def test_repeat_patch_is_a_byte_exact_noop(self):
        self.patch()
        once = list(self.arc.slots)
        self.assertEqual(self.patch()["changed_slots"], [])
        self.assertEqual(self.arc.slots, once)

    def test_unknown_last_palette_rejects_all_copies_atomically(self):
        data = bytearray(self.arc.slots[339])
        data[52 + 2*32] ^= 1
        self.arc.slots[339] = bytes(data)
        before = list(self.arc.slots)
        with self.assertRaisesRegex(ValueError, "palette"):
            self.patch()
        self.assertEqual(self.arc.slots, before)

    def _change_pixel(self, byte_offset):
        data = self.arc.slots[339]
        w, h, _, chunks = parse_container(data)
        raw = bytearray(chunks[1]["raw"])
        raw[byte_offset] ^= 1
        encoded = encode_lz(raw)
        prefix = bytearray(data[:chunks[1]["offset"]])
        struct.pack_into("<I", prefix, 16, len(encoded))
        self.arc.slots[339] = bytes(prefix) + encoded + data[chunks[1]["offset"]+chunks[1]["size"]:]
        return raw

    def test_unknown_label_art_rejects_without_partial_writes(self):
        self._change_pixel(10*128 + 20)
        before = list(self.arc.slots)
        with self.assertRaisesRegex(ValueError, "artwork"):
            self.patch()
        self.assertEqual(self.arc.slots, before)

    def test_unrelated_custom_pixel_survives(self):
        raw = self._change_pixel(250*128 + 70)
        self.patch()
        actual = parse_container(self.arc.slots[339])[3][1]["raw"]
        self.assertEqual(actual[250*128+70], raw[250*128+70])

    def test_unknown_font_and_reference_are_rejected(self):
        before = list(self.arc.slots)
        for font, ref in ((self.font[:-1]+b"!", self.reference),
                          (self.font, self.reference[:-1]+b"!")):
            with self.assertRaisesRegex(ValueError, "source"):
                patcher.patch_settings_menu(self.arc, font, ref)
            self.assertEqual(self.arc.slots, before)

    def test_staging_reopens_output_and_never_overwrites_inputs_or_existing_stage(self):
        with tempfile.TemporaryDirectory(prefix="a2-settings-texture-") as temp:
            folder = Path(temp)
            source, reference, output = folder/"source.pak", folder/"reference.pak", folder/"stage"
            slots = [None] * 768
            slots[0] = b"PAK0"
            for s in SLOTS:
                slots[s] = self.reference
            PakArchive(slots).save(source)
            slots[548] = self.font
            PakArchive(slots).save(reference)
            original = hashlib.sha256(source.read_bytes()).digest()
            report = patcher.stage_patch(source, reference, output)
            self.assertEqual(report["changed_slots"], list(SLOTS))
            self.assertEqual(hashlib.sha256(source.read_bytes()).digest(), original)
            saved = PakArchive.load(output/"DATA/PACK0.PAK")
            self.assertEqual(patcher.patch_settings_menu(saved, self.font, self.reference)["changed_slots"], [])
            staged = hashlib.sha256((output/"DATA/PACK0.PAK").read_bytes()).digest()
            with self.assertRaises(FileExistsError):
                patcher.stage_patch(source, reference, output)
            self.assertEqual(hashlib.sha256((output/"DATA/PACK0.PAK").read_bytes()).digest(), staged)
            self.assertTrue((output/"after_labels_3x.png").is_file())


if __name__ == "__main__":
    unittest.main()
