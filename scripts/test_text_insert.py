"""Insertion must never silently ship an original after a bad replacement."""
import json
from pathlib import Path
import tempfile
import unittest

from a2.textcodec import Message
import text_insert


class StrictInsertionTests(unittest.TestCase):
    def test_bad_translation_raises_without_mutation(self):
        msg, stats = Message("original", 1), [0, 0]
        with self.assertRaisesRegex(ValueError, "entry-1"):
            text_insert.apply(msg, {"entry-1": {"text": "🙂"}},
                              "entry-1", stats)
        self.assertEqual(msg.text, "original")
        self.assertEqual(stats, [0, 0])

    def test_missing_entry_is_an_error(self):
        msg, stats = Message("original", 1), [0, 0]
        with self.assertRaisesRegex(ValueError, "missing-1"):
            text_insert.apply(msg, {}, "missing-1", stats)
        self.assertEqual(msg.text, "original")

    def test_encodable_replacement_preserves_terminator(self):
        msg, stats = Message("original", 0), [0, 0]
        text_insert.apply(msg, {"entry-1": {"text": "А"}}, "entry-1",
                          stats, {"А": 0xFF41})
        self.assertEqual((msg.text, msg.end, stats), ("А", 0, [1, 1]))

    def test_intentionally_empty_original_is_preserved(self):
        msg, stats = Message("{07:0000}", 0), [0, 0]
        text_insert.apply(msg, {"entry-1": {"text": ""}}, "entry-1", stats)
        self.assertEqual((msg.text, stats), ("{07:0000}", [0, 1]))

    def test_preflight_catches_late_file_before_output(self):
        with tempfile.TemporaryDirectory() as tmp:
            for name in ("grp", "pack0", "vcast"):
                entry = {"orig": "А", "text": "А"}
                if name == "vcast":
                    entry["text"] = "🙂"
                Path(tmp, name + "_text.json").write_text(json.dumps(
                    {"entries": {name + ".1": entry}}), encoding="utf-8")
            with self.assertRaisesRegex(ValueError, "vcast.1"):
                text_insert.preflight(tmp, {"А": 0xFF41})

    def test_preflight_rejects_latin_font_collisions(self):
        with tempfile.TemporaryDirectory() as tmp:
            for name in ("grp", "pack0", "vcast"):
                Path(tmp, name + "_text.json").write_text(json.dumps(
                    {"entries": {name + ".1": {"orig": "OK", "text": "OK"}}}))
            with self.assertRaisesRegex(ValueError, "grp.1"):
                text_insert.preflight(tmp, {"А": 0xFF41})


if __name__ == "__main__":
    unittest.main()
