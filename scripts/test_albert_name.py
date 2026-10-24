import json
from pathlib import Path
import re
import unittest

from name_profile_jp import apply_general
from validate_translations import check


class AlbertNameTests(unittest.TestCase):
    def test_profile_keeps_full_name_and_cases(self):
        text = "Альберт Альберта Альберту Альбертом Альберте Алундра"
        self.assertEqual(apply_general(text), text)

    def test_profile_restores_only_bounded_short_forms(self):
        self.assertEqual(apply_general("Аль Аля Алю Алем Але Альбертон"),
                         "Альберт Альберта Альберту Альбертом Альберте Альбертон")

    def test_corpus_character_label_and_mentions(self):
        root = Path(__file__).resolve().parent.parent
        for name in ("grp", "pack0", "vcast"):
            entries = json.loads((root / "translations" / (name + "_text.json")).read_text())["entries"]
            if name == "pack0":
                self.assertEqual(entries["p0.e015.4"]["text"], "Альберт")
            for eid, entry in entries.items():
                text = entry.get("text", "")
                with self.subTest(entry=eid):
                    self.assertIsNone(re.search(r"(?<![А-Яа-яЁё])(?:Аль|Аля|Алю|Алем|Але)(?![А-Яа-яЁё])", text))
                    if "Альберт" in text:
                        self.assertEqual(check(entry, text), [])


if __name__ == "__main__":
    unittest.main()
