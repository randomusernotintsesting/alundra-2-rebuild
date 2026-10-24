import unittest
import json
from pathlib import Path
from a2.cyrfont import charmap
from a2.textcodec import Message, encode_message
from name_variants import decode_actual, reflow, controls, visible_width

class NameVariantsTest(unittest.TestCase):
    def test_japanese_voice_king_ordinal_survives_russian_font(self):
        from voice_names_ru import transform_ru
        root = Path(__file__).resolve().parents[1] / 'translations'
        glossary = json.loads((root / 'voice_names.json').read_text())
        overrides = json.loads((root / 'voice_name_overrides.json').read_text())
        text = transform_ru('p0.e015.14', '139-й король Варуны', 'ja', glossary, overrides)
        displayed, _ = decode_actual(encode_message(Message(text, 0), charmap()), 0)
        self.assertEqual(displayed, 'Ванилла 13-й')

    def test_real_cyrillic_cells_and_parameter_are_distinct(self):
        text = '{04:FF41}Аяёъ{}'
        text = text[:-2] + '{JP:0141}{NAME}{PAGE}\n{07:0001}'
        raw = encode_message(Message(text, 0), charmap())
        self.assertEqual(decode_actual(raw, 0), (text, 0))
        self.assertEqual(decode_actual(encode_message(Message('Al, all!{NAME}', 1)), 2), ('Al, all!{NAME}', 1))

    def test_raw_unmapped_glyphs_roundtrip(self):
        raw = bytes.fromhex('7bff030014000100')
        text, end = decode_actual(raw, 2)
        self.assertEqual(encode_message(Message(text, end)), raw)

    def test_reflow_keeps_order_pages_and_words(self):
        text = '{SYS}Meet {04:0003}Mercedes{04:0007} in the Dragon Volcano.{PAGE}Hi, {NAME}!'
        result = reflow(text, width=24, max_lines=3)
        self.assertEqual(controls(text), controls(result))
        self.assertEqual(text.replace('\n', ' '), result.replace('\n', ' '))
        self.assertTrue(all(visible_width(line) <= 24 for page in result.split('{PAGE}') for line in page.split('\n')))

    def test_fails_instead_of_silently_overflowing(self):
        with self.assertRaises(ValueError): reflow('one two three four five six seven eight', 9, 2)
        self.assertEqual(reflow('One\ntwo.', 34, 3), 'One\ntwo.')

if __name__ == '__main__': unittest.main()
