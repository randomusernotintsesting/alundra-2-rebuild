"""Regression tests for the Russian token-font translation boundary."""
import unittest
import json
from pathlib import Path

from validate_translations import check
from a2.textcodec import Message, encode_message


class FontValidationTests(unittest.TestCase):
    def test_visible_latin_is_rejected(self):
        for text in ("OK", "ещe", "HP", "MEMORY CARD"):
            with self.subTest(text=text):
                self.assertTrue(check({"orig": text}, text))

    def test_repurposed_ascii_cells_are_rejected(self):
        for text in ("#", "$", "@", "[", "\\", "]", "^", "_", "`"):
            with self.subTest(text=text):
                self.assertTrue(check({"orig": text}, text))

    def test_tags_and_printf_are_not_visible_latin(self):
        text = "{SYS}{04:000A}{NAME}: %05ld, %#08X"
        self.assertEqual(check({"orig": text}, text), [])

    def test_safe_russian_and_punctuation_are_accepted(self):
        text = "Ёж: 10 зл., ОЗ/ЭП + 5 (100%)!"
        self.assertEqual(check({"orig": text}, text), [])

    def test_original_latin_glyphs_can_label_controls(self):
        self.assertEqual(check({"orig": "Кнопка"}, "{JP:0030}1"), [])
        self.assertEqual(check({"orig": "Трасса"}, "Трасса {JP:0031}"), [])

    def test_other_japanese_glyphs_remain_errors(self):
        self.assertTrue(check({"orig": "Слово"}, "{JP:00B9}"))

    def test_malformed_japanese_glyph_tags_are_rejected(self):
        for text in ("{JP:ZZZZ}", "{JP:123}", "{JP:0030"):
            with self.subTest(text=text):
                self.assertTrue(check({"orig": "Слово"}, text))

    def test_original_latin_glyphs_count_toward_line_limit(self):
        self.assertTrue(check({"orig": "Трасса"}, "{JP:0030}" * 35))

    def test_format_changes_still_fail(self):
        self.assertTrue(check({"orig": "%05ld"}, "%05d"))

    def test_measured_item_description_uses_pixel_budget_not_english_ratio(self):
        entry = {"orig": "{SYS}Restores 100 HP", "layout": "item_description"}
        self.assertEqual(check(entry, "{SYS}Восстанавливает 100 очков здоровья"), [])
        # The observed 288px interior accepts 48 fixed-six-pixel glyphs.
        self.assertEqual(check(entry, "{SYS}" + "а" * 48), [])
        self.assertTrue(check(entry, "{SYS}" + "а" * 49))
        self.assertTrue(check(entry, "{SYS}а\nа\nа\nа"))

    def test_measured_layout_does_not_guess_dynamic_expansion_width(self):
        for dynamic in ("{NAME}", "{MEDALS}", "{0E}", "{0D:0001}", "%d"):
            entry = {"orig": "{SYS}" + dynamic, "layout": "item_description"}
            self.assertTrue(check(entry, entry["orig"]), dynamic)

    def test_unknown_layout_cannot_bypass_validation(self):
        self.assertTrue(check({"orig": "Трава", "layout": "unknown"}, "Трава"))

    def test_autosized_item_action_accepts_a_full_verb_but_stays_on_screen(self):
        entry = {"orig": "{07:0000}Use", "layout": "item_action"}
        self.assertEqual(check(entry, "{07:0000}Использовать"), [])
        self.assertEqual(check(entry, "{07:0000}" + "а" * 47), [])
        self.assertTrue(check(entry, "{07:0000}" + "а" * 48))
        self.assertTrue(check(entry, "{07:0000}а\nа"))

    def test_unmeasured_text_keeps_existing_length_guard(self):
        self.assertTrue(check({"orig": "Restores 100 HP"},
                              "Восстанавливает 100 очков здоровья"))

    def test_translation_corpus_is_encodable_and_valid(self):
        root = Path(__file__).resolve().parent.parent
        charmap = json.loads((root / "scripts/charmap.json").read_text())
        for name in ("grp", "pack0", "vcast"):
            entries = json.loads((root / "translations" / (name + "_text.json")).read_text())["entries"]
            for eid, entry in entries.items():
                if not entry.get("text"):
                    continue
                with self.subTest(entry=eid):
                    self.assertEqual(check(entry, entry["text"]), [])
                    encode_message(Message(entry["text"], 0), charmap)

    def test_game_brand_uses_the_same_cyrillic_bank_as_its_message(self):
        root = Path(__file__).resolve().parent.parent
        entries = json.loads((root / "translations/pack0_text.json").read_text())["entries"]
        charmap = json.loads((root / "scripts/charmap.json").read_text())
        # Hand-checked FFxx cells for Алундра / Алундры: the old full-width
        # JP glyph workaround both changed the face and widened the title.
        for eid, title in (
            ("p0.e014.9", "41 ff 6c ff 74 ff 6e ff 65 ff 71 ff 61 ff"),
            ("p0.e376.14", "41 ff 6c ff 74 ff 6e ff 65 ff 71 ff 7c ff"),
            ("p0.e376.20", "41 ff 6c ff 74 ff 6e ff 65 ff 71 ff 7c ff"),
        ):
            with self.subTest(entry=eid):
                encoded = encode_message(Message(entries[eid]["text"], 0), charmap)
                self.assertIn(bytes.fromhex(title + " 20 ff 32 ff"), encoded)


if __name__ == "__main__":
    unittest.main()
