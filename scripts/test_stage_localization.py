import unittest
from a2.pak import PakArchive
from stage_localization import merge_pack_assets, compare_messages
from a2.textcodec import Message, decode_block


class StagingTests(unittest.TestCase):
    def test_nontext_assets_survive_text_rebuild(self):
        staged = PakArchive([b"new text", b"original art", None])
        current = PakArchive([b"old text", b"custom art", b"custom data"])
        merge_pack_assets(staged, current, {0})
        self.assertEqual(staged.slots, [b"new text", b"custom art", b"custom data"])

    def test_layout_mismatch_does_not_modify_staged_archive(self):
        staged = PakArchive([b"text", b"art"])
        with self.assertRaises(ValueError):
            merge_pack_assets(staged, PakArchive([b"other"]), {0})
        self.assertEqual(staged.slots, [b"text", b"art"])

    def test_unknown_slot_is_rejected(self):
        with self.assertRaises(ValueError):
            merge_pack_assets(PakArchive([b"a"]), PakArchive([b"b"]), {4})

    def test_text_and_terminator_must_match(self):
        original = {"a": Message("old", 0)}
        entries = {"a": {"text": "А"}}
        # The archive decoder returns encoded ASCII cells, not Unicode RU.
        compare_messages({"a": Message("A", 0)}, original, entries, {"А": 0xFF41})
        for bad in (Message("B", 0), Message("A", 1)):
            with self.assertRaises(ValueError):
                compare_messages({"a": bad}, original, entries, {"А": 0xFF41})

    def test_missing_message_is_rejected(self):
        with self.assertRaises(ValueError):
            compare_messages({}, {"a": Message("old", 0)}, {"a": {"text": ""}}, {})

    def test_encoded_cyrillic_brace_cell_is_not_mistaken_for_markup(self):
        raw = bytes.fromhex("7bff7dff7fff0000")
        decoded, _ = decode_block(raw, 0, len(raw))
        compare_messages({"a": decoded[0]}, {"a": Message("old", 0)},
                         {"a": {"text": "ъью"}},
                         {"ъ": 0xFF7B, "ь": 0xFF7D, "ю": 0xFF7F})


if __name__ == "__main__":
    unittest.main()
