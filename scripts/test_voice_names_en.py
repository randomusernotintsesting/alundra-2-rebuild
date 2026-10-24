"""Run with --glossary PATH to exercise the complete reviewed glossary."""
import argparse
import json
from pathlib import Path
import re
import unittest

from voice_names_en import transform_en

EXPECTED = '''Alexia|Aisha
Zeppo|Tetzo
Albert|Al
Flint|Flit
Milena|Mercedes
Diaz|Nijador
Natasha|Latoya
Prunewell|Lord Burian
Axelya|Shaia
Omega|Hedva
Mutox|Maox
Roswell|Dr. Ndoul
Finrod|Frodo
Jeehan|Jiken
Lao|Ao
Tirion|Arion
Bloodfang|Mahu
George|Triff
Kate|Mayu
T-Bone|Rinkau
Varuna|Vanilla
Toroledo|Gyu-York
Gwaba|Gwabacacao
Dun Webb|Webrock
Kindra|Momomoke
Sparrowhawk|Chobidaka
Tortuga|Sunanaki
Seagull Ruins|Yurare Seagull Ruins
Mt. Firedrake|Dragon Volcano
Dragonia|Dragon Dock
Howling Cave|Huey's Wind Cave
Gamar Isle|Yugi Island
Deadeye Zach's|Guaran Hall
Royal Palace|Royal Capital Grand Onion
Church of the Key|Nejigood Church
Children of the Crown|Papa Guard
Turnkey Dam|Ma-Doll Dam
Eden Ruins|Paradise Ruins
Vanilla Wafer|Vanilla Manju
Newt Ring|Salamander
Dwarf Stone|Yurare Stone
Vita Stone|Kreis Stone
Adamant Shield|Yukio
Valar Shield|Kreis Berg
Lorien Nuts|Nantara Fruit
Grapes of Eru|Kantara Fruit
Lamp of Lumiere|Lumiere's Torch
Star Key|Star Twister'''
GLOSSARY = json.loads((Path(__file__).resolve().parents[1] / 'translations/voice_names.json').read_text())
CORPUS = None
TAG = re.compile(r'\{[^{}]*\}')


class VoiceNamesEnglish(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        if GLOSSARY is None:
            raise RuntimeError('Pass --glossary PATH to the reviewed glossary JSON')

    def render(self, text, voice='ja', eid='test.names'):
        return transform_en(eid, text, voice, GLOSSARY)

    def test_all_48_reviewed_identities_in_both_voices(self):
        """Catch a missing identity or accidentally using text-language names."""
        expected = dict(line.split('|') for line in EXPECTED.splitlines())
        self.assertEqual(len(expected), 48)
        self.assertEqual({e['en_us'] for e in GLOSSARY['entries']}, set(expected))
        for e in GLOSSARY['entries']:
            eid = e['jp_occurrence_ids'][0]
            # Explicit prose repairs need their own real input, not a name fixture.
            eid = next((x for x in e['jp_occurrence_ids']
                        if x not in GLOSSARY['explicit_entry_repairs']), eid)
            with self.subTest(name=e['key']):
                self.assertEqual(self.render(e['en_us'], 'ja', eid), expected[e['en_us']])
                self.assertEqual(self.render(e['en_us'], 'en', eid), e['en_us'])

    def test_titles_possessives_and_split_aliases(self):
        pairs = {
            "Lord Prunewell's": "Lord Burian's",
            'Prunewell': 'Lord Burian',
            'Lord\nPrunewell': 'Lord Burian',
            'Baron\nDiaz': 'Count Nijador',
            "Roswell the Sage's House": "Dr. Ndoul's House",
            "Roswell's orders": "Dr. Ndoul's orders",
            'Dr. Ndoul': 'Dr. Ndoul',
            'Mt. Firedrake': 'Dragon Volcano',
            'Mount Firedrake': 'Dragon Volcano',
            'Mt. Sparrowhead': 'Mt. Chobidaka',
            "Milena's Mansion": "Mercedes' Mansion",
            'Gamar Game Room': 'Yugi Game Room',
        }
        for old, want in pairs.items():
            with self.subTest(old=old): self.assertEqual(self.render(old), want)
        self.assertEqual(self.render('Lord Prunewell and Roswell the Sage', 'en'),
                         'Lord Prunewell and Roswell the Sage')

    def test_reverse_supplemental_japanese_names_and_idempotence(self):
        text = 'Lord Burian and Dr. Ndoul meet Count Nijador at Dragon Volcano.'
        self.assertEqual(self.render(text, 'en'),
                         'Lord Prunewell and Roswell the Sage meet Baron Diaz at Mt. Firedrake.')
        for voice in ('ja', 'en'):
            first = self.render(text, voice)
            self.assertEqual(self.render(first, voice), first)

    def test_tokens_name_placeholder_and_boundaries(self):
        text = '{SYS}{04:0001}Baron {04:0003}Diaz{04:0007}: {NAME}, Alexia!{PAGE}{Flint}'
        got = self.render(text)
        self.assertEqual(TAG.findall(got), TAG.findall(text))
        self.assertEqual(TAG.sub('', got), 'Count Nijador: , Aisha!')
        self.assertEqual(self.render('flintlock Albatross Katewood omega newt Tricky Wampeter'),
                         'flintlock Albatross Katewood omega newt Tricky Wampeter')
        self.assertEqual(self.render('Baron {NAME} Diaz'), 'Baron {NAME} Nijador')
        self.assertEqual(self.render('{NAME}'), '{NAME}')

    def test_vanilla_food_is_separate_from_kingdom(self):
        self.assertEqual(self.render('Vanilla Wafer in Varuna'), 'Vanilla Manju in Vanilla')
        self.assertEqual(self.render('Vanilla Manju in Vanilla', 'en'), 'Vanilla Wafer in Varuna')
        self.assertEqual(self.render('Vanilla flavored wafer.', 'en', 'p0.e299.202'),
                         'Vanilla flavored wafer.')
        self.assertEqual(self.render('Vanilla Wafers'), 'Vanilla Manju')

    def test_ambiguous_dishes_only_in_verified_entries(self):
        for eid in ('g182.s12', 'g182.s13', 'g182.s20', 'g182.s21'):
            result = self.render('Wampeter', eid=eid)
            self.assertIn('Itadaki', result)
            self.assertNotIn('Wampeter', result)
        self.assertEqual(self.render('Wampeter and Goo Goo Bird'), 'Wampeter and Goo Goo Bird')
        text = "Listen.{PAGE}Whether it's Wampeter or Goo Goo Bird,\nthe fresher the better!"
        result = self.render(text, eid='g185.name')
        self.assertIn('Itadaki or Tricky', result)
        self.assertEqual(TAG.findall(result), TAG.findall(text))
        self.assertEqual(self.render(text, 'en', 'g185.name'), text)

    def test_restaurant_greeting_uses_the_dish_named_in_adjacent_dialogue(self):
        text = 'Welcome to our restaurant!\nWe have the best Wampeters in Gwaba!'
        self.assertEqual(self.render(text, eid='g182.s18'),
                         'Welcome to our restaurant!\nWe have the best Itadaki dishes in Gwabacacao!')
        self.assertEqual(self.render(text, 'en', 'g182.s18'), text)
        self.assertEqual(self.render('Wampeters', eid='unrelated'), 'Wampeters')

    def test_nijador_title_references_follow_voice_only_in_reviewed_contexts(self):
        text = 'Now the Baron has the King.{PAGE}The Baron will be unstoppable!'
        self.assertEqual(self.render(text, eid='g394.s15'),
                         'Now the Count has the King.{PAGE}The Count will be unstoppable!')
        self.assertEqual(self.render(text, 'en', 'g394.s15'), text)
        self.assertEqual(self.render("the {04:0001}Baron's Orders{04:0007}", eid='g184.s19'),
                         "the {04:0001}Count's Orders{04:0007}")
        self.assertEqual(self.render('Baron or no Baron!', eid='g426.s0'), 'Count or no Count!')
        self.assertEqual(self.render('Baron and Count in an unrelated story.'),
                         'Baron and Count in an unrelated story.')
        text = '{SYS}{04:0001}Nunugi:{04:0003}B-{04:0007}...{04:0003}Baron{04:0007}...?'
        self.assertEqual(self.render(text, eid='vc.e219.10'),
                         '{SYS}{04:0001}Nunugi:{04:0003}C-{04:0007}...{04:0003}Count{04:0007}...?')

    def test_place_phrases_do_not_duplicate_articles_or_volcano(self):
        text = 'He went to the {04:0000}Howling Cave{04:0007}.'
        got = self.render(text, eid='g050.s50')
        self.assertEqual(TAG.sub('', got), "He went to Huey's Wind Cave.")
        self.assertEqual(TAG.findall(got), TAG.findall(text))
        self.assertEqual(self.render(text, 'en', 'g050.s50'), text)
        text = "There's a volcano named {04:0000}Firedrake{04:0007} just\nbeyond Mt. Sparrowhawk!"
        got = self.render(text, eid='g232.s1')
        self.assertEqual(TAG.sub('', got), "There's a Dragon Volcano just\nbeyond Mt. Chobidaka!")
        self.assertEqual(TAG.findall(got), TAG.findall(text))
        self.assertEqual(self.render(text, 'en', 'g232.s1'), text)

    def test_explicit_repairs_preserve_input_controls(self):
        inputs = {
            'g203.s9': "{SYS}Roswell's House",
            'p0.e015.14': '139th King of Varuna',
            'g420.s2': "Perhaps you've heard of me...\nLet me introduce myself. I'm Baron Diaz!",
            'g422.s13': '{SYS}Royal Palace',
            'g180.s8': "What should I make for dinner tonight?\nI'm sick of Wampeter burgers.",
        }
        expected = {
            'g203.s9': "{SYS}Dr. Ndoul's House",
            'p0.e015.14': 'Vanilla XIII',
            'g420.s2': 'I am the minister,\nDestor Nijador!',
            'g422.s13': '{SYS}Royal Capital Grand Onion',
            'g180.s8': 'What should I make for dinner?\nMaybe grilled Tricky skewers...\nBeing a housewife is hard!',
        }
        for eid, text in inputs.items():
            with self.subTest(eid=eid):
                got = self.render(text, eid=eid)
                self.assertEqual(got, expected[eid])
                self.assertEqual(TAG.findall(got), TAG.findall(text))
        self.assertEqual(self.render('Royal Palace', eid='unrelated'), 'Royal Palace')

    def test_plural_spirits_and_source_typos(self):
        self.assertEqual(self.render('{04:0001}Newts{04:0007} are Fire Spirits!', eid='g215.s20'),
                         '{04:0001}Salamanders{04:0007} are Fire Spirits!')
        self.assertEqual(self.render('Axelia and Exilia', 'en'), 'Axelya and Axelya')
        self.assertEqual(self.render('Mt. Sparrowhead', 'en'), 'Mt. Sparrowhawk')

    def test_names_added_by_us_localization_still_follow_voice(self):
        for eid in ('g049.name', 'g196.name', 'g197.name', 'g199.name', 'g220.s1'):
            with self.subTest(eid=eid):
                self.assertEqual(self.render('Mistress Omega', eid=eid), 'Mistress Hedva')
        self.assertEqual(self.render('Omega is a Greek letter.', eid='unrelated'),
                         'Omega is a Greek letter.')

    def test_emphasized_machine_name_retains_emphasis(self):
        text = 'The "Nerve-Center" where I can\nuse my STAR KEY.'
        self.assertEqual(self.render(text, eid='g340.s28'),
                         'The "Nerve-Center" where I can\nuse my STAR TWISTER.')
        self.assertEqual(self.render(text, 'en', 'g340.s28'), text)
        self.assertEqual(self.render('ALEXIA and BARON DIAZ!'), 'AISHA and COUNT NIJADOR!')
        self.assertEqual(self.render('AISHA and COUNT NIJADOR!', 'en'), 'ALEXIA and BARON DIAZ!')
        self.assertEqual(self.render('LORD PRUNEWELL and DR. NDOUL!'), 'LORD BURIAN and DR. NDOUL!')
        self.assertEqual(self.render('al and all and flint and omega'), 'al and all and flint and omega')
        self.assertEqual(self.render('Ya wanna go into the Eden ruins?', eid='g410.s5'),
                         'Ya wanna go into the Paradise ruins?')

    def test_common_words_and_unchanged_official_wrapping(self):
        text = 'Omega is a letter. Newts live here. Webb is a different surname.'
        self.assertEqual(self.render(text), text)
        text = '{SYS}Baron\n{04:0003}Diaz{04:0007} and the Church of the\nKey'
        self.assertEqual(self.render(text, 'en'), text)

    def test_optional_full_corpus_controls_and_idempotence(self):
        if CORPUS is None:
            self.skipTest('Pass --corpus PATH for the extracted full English profile')
        for voice in ('ja', 'en'):
            for eid, text in CORPUS.items():
                with self.subTest(voice=voice, eid=eid):
                    result = self.render(text, voice, eid)
                    self.assertEqual(TAG.findall(result), TAG.findall(text))
                    self.assertEqual(self.render(result, voice, eid), result)
                    if voice == 'ja':
                        self.assertNotRegex(TAG.sub('', result), r'\bBaron\b')

    def test_invalid_voice_is_not_silently_a_profile(self):
        with self.assertRaises(ValueError): self.render('Alexia', 'ru')


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--glossary', type=Path, default=Path(__file__).resolve().parents[1] / 'translations/voice_names.json')
    parser.add_argument('--corpus', type=Path)
    args, remaining = parser.parse_known_args()
    GLOSSARY = json.loads(args.glossary.read_text())
    if args.corpus:
        CORPUS = json.loads(args.corpus.read_text())
    unittest.main(argv=[__file__, *remaining])
