"""Behavior checks for voice-dependent Russian names; no game/runtime needed."""
import copy
import re
import unittest

try:
    from voice_names_ru import transform_ru
except ImportError:
    transform_ru = None


CASES = ('nom', 'gen', 'dat', 'acc', 'ins', 'prep')


def row(key, us, ja, ids=(), aliases=(), scope='name'):
    def cases(value):
        values = value.split('|')
        return dict(zip(CASES, values if len(values) == 6 else values * 6))
    return dict(key=key, ru_us=cases(us), ru_jp=cases(ja),
                jp_occurrence_ids=list(ids), russian_aliases=list(aliases),
                scope=scope)


GLOSSARY = {'entries': [
    row('aisha', 'Алексия|Алексии|Алексии|Алексию|Алексией|Алексии',
        'Аиша|Аиши|Аише|Аишу|Аишей|Аише', aliases=('Айша', 'Айше', 'Айшу')),
    row('latoya', 'Наташа|Наташи|Наташе|Наташу|Наташей|Наташе',
        'Латоя|Латои|Латое|Латою|Латоей|Латое'),
    row('tetzo', 'Зеппо', 'Тэтцо', aliases=('Тетцо', 'Теццо', 'Теттсо')),
    row('al', 'Альберт|Альберта|Альберту|Альберта|Альбертом|Альберте',
        'Аль|Аля|Алю|Аля|Алем|Але', aliases=('Ал', 'Аль')),
    row('flit', 'Флинт|Флинта|Флинту|Флинта|Флинтом|Флинте',
        'Флит|Флита|Флиту|Флита|Флитом|Флите', aliases=('Флитяга', 'Флинтяга')),
    row('mercedes', 'Милена|Милены|Милене|Милену|Миленой|Милене', 'Мерседес'),
    row('nijador', 'Диас|Диаса|Диасу|Диаса|Диасом|Диасе',
        'Нидзядор|Нидзядора|Нидзядору|Нидзядора|Нидзядором|Нидзядоре',
        ('g009.s4', 'g239.s0'), ('Нижадор', 'Ниджадор')),
    row('ndoul', 'Розуэлл|Розуэлла|Розуэллу|Розуэлла|Розуэллом|Розуэлле',
        'Ндур|Ндура|Ндуру|Ндура|Ндуром|Ндуре', ('g239.s0', 'g203.s9'),
        ('Ндураа', 'Ндурааа')),
    row('gwabacacao', 'Гваба|Гвабы|Гвабе|Гвабу|Гвабой|Гвабе', 'Гвабакакао'),
    row('webrock', 'Дан Уэбб|Дана Уэбба|Дану Уэббу|Дан Уэбб|Даном Уэббом|Дане Уэббе',
        'Уэброк|Уэброка|Уэброку|Уэброк|Уэброком|Уэброке'),
    row('gyuyork', 'Тороледо', 'Гю-Йорк'),
    row('frodo', 'Финрод|Финрода|Финроду|Финрода|Финродом|Финроде', 'Фродо'),
    row('papa_guard', 'Дети Короны|Детей Короны|Детям Короны|Детей Короны|Детьми Короны|Детях Короны',
        'отряд Папа-защита|отряда Папа-защита|отряду Папа-защита|отряд Папа-защита|отрядом Папа-защита|отряде Папа-защита'),
    row('dragon_volcano', 'Огнедрак|Огнедрака|Огнедраку|Огнедрак|Огнедраком|Огнедраке',
        'вулкан Дракона|вулкана Дракона|вулкану Дракона|вулкан Дракона|вулканом Дракона|вулкане Дракона',
        ('g043.s6', 'g221.name')),
    row('grand_onion', 'Королевский дворец', 'столица Гран-Онион',
        ('g422.s13',), scope='entry_only'),
    row('eden', 'руины Эдема|руин Эдема|руинам Эдема|руины Эдема|руинами Эдема|руинах Эдема',
        'райские руины|райских руин|райским руинам|райские руины|райскими руинами|райских руинах',
        ('g161.s1',), scope='named_localization'),
    row('vanilla', 'Варуна|Варуны|Варуне|Варуну|Варуной|Варуне',
        'Ванилла|Ваниллы|Ванилле|Ваниллу|Ваниллой|Ванилле'),
], 'explicit_entry_repairs': {
    'g502.name': {'ja_ru': '{04:0004}Саламандра, Сирена{04:0007}',
                  'en_ru': '{04:0004}Тритон-знак, Сирена{04:0007}'},
    'g422.s13': {'ja_ru': '{SYS}Столица Гран-Онион'},
}}


class VoiceNamesRussianTest(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(transform_ru, 'Russian voice-name transformer is not implemented')
        self.glossary = copy.deepcopy(GLOSSARY)

    def run_name(self, text, voice='ja', eid='other', overrides=None):
        return transform_ru(eid, text, voice, self.glossary, overrides or {})

    def test_override_applied_before_other_names_without_losing_target_case(self):
        override = {'vc.e223.3': {'en_ru': 'Тэтцо: Милену атаковал Мефисто!'}}
        self.assertEqual(self.run_name('Тэтцо: Мерседес атаковал Мефисто!', 'en',
                                       'vc.e223.3', override),
                         'Зеппо: Милену атаковал Мефисто!')

    def test_six_case_source_forms_map_without_substring_corruption(self):
        self.assertEqual(self.run_name('Альберту, Альбертом, Альберте; Алексию, Алексией'),
                         'Алю, Алем, Але; Аишу, Аишей')

    def test_al_does_not_change_alundra_or_longer_names(self):
        self.assertEqual(self.run_name('Аль, Ал, Алундра, Альбертсон, Алексия'),
                         'Аль, Аль, Алундра, Альбертсон, Аиша')

    def test_ready_target_forms_are_idempotent(self):
        text = 'У Милены, с Миленой; до Гвабы, в Гвабе, в Гвабу, с Гвабой.'
        self.assertEqual(self.run_name(text, 'en'), text)

    def test_independent_genitive_dative_and_prepositional_alexia(self):
        self.assertEqual(self.run_name('Письмо Алексии. К Алексии. Об Алексии. На Алексии.'),
                         'Письмо Аиши. К Аише. Об Аише. На Аише.')

    def test_indecinable_mercedes_context_from_override_is_preserved(self):
        text = '{04:0003}Мерседес{04:0007} и дом Мерседес.'
        overrides = {'m': {'en_ru': '{04:0003}Милена{04:0007} и дом Милены.'}}
        self.assertEqual(self.run_name(text, 'en', 'm', overrides),
                         '{04:0003}Милена{04:0007} и дом Милены.')

    def test_frodo_genitive_and_accusative_are_indeclinable(self):
        self.assertEqual(self.run_name('Дом Финрода. Вижу Финрода. Поговори с Финродом.'),
                         'Дом Фродо. Вижу Фродо. Поговори с Фродо.')

    def test_custom_player_token_and_parameter_tokens_never_change(self):
        text = '{SYS}{NAME}: Флинт, Флинта, Флитяга. {0D:0000}{PAGE}{NAME}'
        want = '{SYS}{NAME}: Флит, Флита, Флитяга. {0D:0000}{PAGE}{NAME}'
        self.assertEqual(self.run_name(text), want)
        self.assertEqual(self.run_name('Флитяга!', 'en'), 'Флинтяга!')

    def test_name_split_across_color_tags_preserves_exact_tag_sequence(self):
        text = 'Дом {04:0003}Дана{04:0007}\n{04:0003}Уэбба{04:0007}.{PAGE}{NAME}'
        result = self.run_name(text)
        self.assertEqual(re.findall(r'\{[^}]*\}', result), re.findall(r'\{[^}]*\}', text))
        visible = re.sub(r'\{[^}]*\}', '', result)
        self.assertEqual(visible, 'Дом Уэброка.')

    def test_names_do_not_match_across_page_or_dynamic_name_tokens(self):
        text = 'Дан{PAGE}Уэбб; Дан{NAME}Уэбб'
        self.assertEqual(self.run_name(text), text)

    def test_color_tag_is_name_boundary_when_source_omits_a_space(self):
        self.assertEqual(self.run_name('дочь{04:0003}Латою{04:0007}в заложницы.', 'en'),
                         'дочь{04:0003}Наташу{04:0007}в заложницы.')

    def test_scoped_count_title_changes_but_unrelated_title_does_not(self):
        self.assertEqual(self.run_name('Граф Нидзядор и графа Нидзядора.', 'en', 'g009.s4'),
                         'Барон Диас и барона Диаса.')
        self.assertEqual(self.run_name('Граф данных и барон Мюнхгаузен.', 'en'),
                         'Граф данных и барон Мюнхгаузен.')

    def test_ndoul_title_does_not_rename_generic_three_eyed_sage(self):
        self.assertEqual(self.run_name('Доктор Ндур нашёл статую трёхглазого мудреца.',
                                       'en', 'g239.s0'),
                         'Мудрец Розуэлл нашёл статую трёхглазого мудреца.')

    def test_repeated_ndoul_suffix_is_repaired_by_target_genitive(self):
        self.assertEqual(self.run_name('Дом доктора Ндурааа', 'en', 'g203.s9'),
                         'Дом мудреца Розуэлла')

    def test_declined_gyuyork_source_does_not_leave_russian_suffix_on_toroledo(self):
        self.assertEqual(self.run_name('Из Гю-Йорка, в Гю-Йорке.', 'en'),
                         'Из Тороледо, в Тороледо.')

    def test_group_accusative_uses_context_override_before_common_map(self):
        overrides = {'g394.s12': {'en_ru': 'Мы создали {04:0000}Детей Короны{04:0007}.'}}
        self.assertEqual(self.run_name('Мы создали {04:0000}отряда Папа-защита{04:0007}.',
                                       'en', 'g394.s12', overrides),
                         'Мы создали {04:0000}Детей Короны{04:0007}.')

    def test_g502_firedrake_is_a_spirit_and_not_a_volcano(self):
        text = '{04:0004}Огнедрак, Сирена{04:0007}'
        self.assertEqual(self.run_name(text, 'ja', 'g502.name'),
                         '{04:0004}Саламандра, Сирена{04:0007}')
        self.assertEqual(self.run_name(text, 'en', 'g502.name'),
                         '{04:0004}Тритон-знак, Сирена{04:0007}')
        self.assertEqual(self.run_name('Огнедрак, Сирена'), 'Огнедрак, Сирена')

    def test_real_volcano_location_changes_without_duplicate_head(self):
        self.assertEqual(self.run_name('{SYS}Гора Огнедрак', 'ja', 'g221.name'),
                         '{SYS}Вулкан Дракона')

    def test_entry_only_palace_mapping_never_changes_other_palaces(self):
        self.assertEqual(self.run_name('{SYS}Королевский дворец', 'ja', 'g422.s13'),
                         '{SYS}Столица Гран-Онион')
        self.assertEqual(self.run_name('Королевский дворец'), 'Королевский дворец')

    def test_named_eden_key_description_not_limited_to_location_labels(self):
        self.assertEqual(self.run_name('{07:0000}{SYS}Ключ к Руинам Эдема.{07:0001}',
                                       'ja', 'p0.e299.185'),
                         '{07:0000}{SYS}Ключ к Райским руинам.{07:0001}')

    def test_vanilla_sweet_is_not_renamed_to_varuna(self):
        self.assertEqual(self.run_name('Королевство Ваниллы. Ванильное манджу.', 'en'),
                         'Королевство Варуны. Ванильное манджу.')

    def test_override_with_changed_controls_is_rejected(self):
        with self.assertRaises(ValueError):
            self.run_name('{NAME}{PAGE}Мерседес', 'en', 'bad',
                          {'bad': {'en_ru': 'Милена'}})

    def test_invalid_voice_rejected_without_mutating_configuration(self):
        before = copy.deepcopy(self.glossary)
        with self.assertRaises(ValueError):
            self.run_name('Мерседес', 'fr')
        self.assertEqual(self.glossary, before)


if __name__ == '__main__':
    unittest.main()
