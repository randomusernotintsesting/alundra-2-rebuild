"""Select Russian proper names by voice, keeping message controls intact.

The caller supplies decoded text, the audit glossary, and contextual fulltext
overrides. This module performs no I/O and does not reflow lines. Indeclinable
source names cannot recover arbitrary Russian cases: audited per-entry overrides
are the authority, with a small governor-based fallback for other sentences.
"""
from __future__ import annotations

import re


_TAG = re.compile(r'\{[^}]*\}')
_LETTER = r'A-Za-zА-Яа-яЁё'
_CASES = ('nom', 'gen', 'dat', 'acc', 'ins', 'prep')
_BARRIER = '\ufffc'
_SCOPED = {'dragon_volcano', 'chobidaka', 'grand_onion',
           'yurare_seagull', 'salamander'}


class _Text:
    """A visible-text view with ordered control-token anchors.

    Formatting can split a name. A replacement keeps internal control tokens in
    their original order, anchoring them proportionally within the new spelling.
    Dynamic substitutions and structural controls are barriers to phrase matches.
    """
    def __init__(self, text: str):
        self.visible = ''
        self.tags: list[tuple[int, str]] = []
        cursor = 0
        for match in _TAG.finditer(text):
            self.visible += text[cursor:match.start()]
            token = match.group()
            self.tags.append((len(self.visible), token))
            if not re.fullmatch(r'\{(?:04|07):[0-9A-Fa-f]+\}', token):
                self.visible += _BARRIER
            cursor = match.end()
        self.visible += text[cursor:]

    def sub(self, pattern: re.Pattern, replacement):
        for match in reversed(list(pattern.finditer(self.visible))):
            new = replacement(match) if callable(replacement) else replacement
            if new == match.group():
                continue
            start, end = match.span()
            old_length = end - start
            shift = len(new) - old_length
            self.tags = [
                (pos if pos <= start else
                 pos + shift if pos >= end else
                 start + round((pos - start) * len(new) / old_length), token)
                for pos, token in self.tags
            ]
            self.visible = self.visible[:start] + new + self.visible[end:]

    def render(self) -> str:
        chunks = []
        cursor = 0
        for pos, token in self.tags:
            chunks.append(self.visible[cursor:pos].replace(_BARRIER, ''))
            chunks.append(token)
            cursor = pos
        chunks.append(self.visible[cursor:].replace(_BARRIER, ''))
        return ''.join(chunks)


def _pattern(words, boundaries=True) -> re.Pattern:
    alternatives = [re.escape(word).replace(r'\ ', r'\s+')
                    for word in sorted(set(words), key=len, reverse=True) if word]
    expression = '(?:' + '|'.join(alternatives) + ')'
    if boundaries:
        expression = rf'(?<![{_LETTER}])' + expression + rf'(?![{_LETTER}])'
    return re.compile(expression, re.IGNORECASE)


def _capitalization(value: str, sample: str) -> str:
    if sample.isupper():
        return value.upper()
    if sample and sample[0].isupper():
        return value[:1].upper() + value[1:]
    return value[:1].lower() + value[1:]


def _key(value: str) -> str:
    return ' '.join(value.casefold().split())


def _choose(candidates, prefix: str):
    """Resolve only straightforward governors; fulltext overrides carry nuance."""
    if len({value for _, value in candidates}) == 1:
        return candidates[0][1]
    previous = re.search(r'([А-Яа-яЁё]+)\s*$', prefix)
    governor = previous.group(1).casefold() if previous else ''
    case = {'к': 'dat', 'ко': 'dat', 'о': 'prep', 'об': 'prep',
            'обо': 'prep', 'при': 'prep', 'на': 'prep',
            'с': 'ins', 'со': 'ins'}.get(governor)
    if governor in {'у', 'без', 'до', 'из', 'от', 'для', 'около', 'после',
                    'дом', 'дома', 'особняк', 'особняка', 'комната', 'комнаты',
                    'письмо', 'приказ', 'двор', 'подземелье', 'телохранитель'}:
        case = 'gen'
    for wanted in (case, 'nom', 'gen', 'acc', 'dat', 'ins', 'prep'):
        for found, value in candidates:
            if found == wanted:
                return value
    return candidates[0][1]


def _alias_cases(entry, source, target):
    """Known historical spellings, without treating inflected aliases as names."""
    key = entry['key']
    extra = {}
    if key == 'flit':
        extra['Флинтяга'] = ('nom', 'Флитяга' if target['nom'] == 'Флит' else 'Флинтяга')
        extra['Флитяга'] = ('nom', 'Флитяга' if target['nom'] == 'Флит' else 'Флинтяга')
    if key == 'gyuyork' and target['nom'] == 'Тороледо':
        for name in ('Гю-Йорк', 'Гью-Йорк', 'Гьюёрк'):
            for ending in ('', 'а', 'у', 'ом', 'е'):
                extra[name + ending] = ('nom', 'Тороледо')
    if key == 'aisha':
        for base in ('Айша', 'Айиша'):
            for case, ending in zip(_CASES, ('а', 'и', 'е', 'у', 'ей', 'е')):
                extra[base[:-1] + ending] = (case, target[case])
    if key in {'nijador', 'ndoul'}:
        stems = ('Нижадор', 'Ниджадор', 'Нихадор') if key == 'nijador' else ()
        for stem in stems:
            for case, ending in zip(_CASES, ('', 'а', 'у', 'а', 'ом', 'е')):
                extra[stem + ending] = (case, target[case])
        if key == 'ndoul':
            extra.update({alias: ('gen', target['gen']) for alias in ('Ндураа', 'Ндурааа')})
    if key == 'papa_guard':
        extra['Папа-защита'] = ('nom', target['nom'])
    known = set(source.values()) | set(target.values()) | set(extra)
    for alias in entry.get('russian_aliases', ()):
        if alias not in known:
            extra[alias] = ('nom', target['nom'])
    return extra


def _titles(view: _Text, entry, voice: str, scoped: bool):
    key = entry['key']
    if key not in {'nijador', 'ndoul'}:
        return
    us = ('барон', 'барона', 'барону', 'барона', 'бароном', 'бароне')
    ja = ('граф', 'графа', 'графу', 'графа', 'графом', 'графе')
    if key == 'ndoul':
        us = ('мудрец', 'мудреца', 'мудрецу', 'мудреца', 'мудрецом', 'мудреце')
        ja = ('доктор', 'доктора', 'доктору', 'доктора', 'доктором', 'докторе')
    source, target = (us, ja) if voice == 'ja' else (ja, us)
    table = dict(zip(source, target))
    pattern = _pattern(source)
    names = set(entry['ru_us'].values()) | set(entry['ru_jp'].values())
    names.update(entry.get('russian_aliases', ()))
    follows = re.compile(r'\s+' + _pattern(names).pattern)

    def replace(match):
        # An identified count's isolated title is meaningful. A generic sage in
        # the same entry can still refer to the three-eyed idol; never touch it.
        if (key == 'nijador' and scoped) or follows.match(view.visible, match.end()):
            return _capitalization(table[match.group().casefold()], match.group())
        return match.group()
    view.sub(pattern, replace)


def _volcano_head(view: _Text, entry, voice):
    if voice != 'ja':
        return
    table = {'гора': 'nom', 'горы': 'gen', 'горе': 'prep',
             'гору': 'acc', 'горой': 'ins'}
    pattern = re.compile(rf'(?<![{_LETTER}])(?P<head>гора|горы|горе|гору|горой)'
                         rf'\s+Огнедрак(?:а|у|ом|е)?(?![{_LETTER}])', re.IGNORECASE)
    view.sub(pattern, lambda m: _capitalization(entry['ru_jp'][table[m['head'].casefold()]], m['head']))


def transform_ru(eid: str, text: str, voice: str, glossary: dict,
                 overrides: dict) -> str:
    """Return RU text using the edition names selected by ``ja``/``en`` voice.

    Context overrides take precedence over glossary repairs. Every control token,
    including custom ``{NAME}``, must survive in its original order. Invalid
    override controls are rejected instead of silently changing game flow.
    """
    if voice not in {'ja', 'en'}:
        raise ValueError(f'Unsupported voice: {voice!r}')
    controls = _TAG.findall(text)
    variant = voice + '_ru'
    repairs = glossary.get('explicit_entry_repairs', {}).get(eid, {})
    text = overrides.get(eid, {}).get(variant, repairs.get(variant, text))
    if _TAG.findall(text) != controls:
        raise ValueError(f'{eid}: name override changes ordered control tokens')
    view = _Text(text)
    for entry in glossary.get('entries', ()):
        scoped = eid in entry.get('jp_occurrence_ids', ())
        if (entry.get('scope') == 'entry_only' or entry['key'] in _SCOPED) and not scoped:
            continue
        _titles(view, entry, voice, scoped)
        if entry['key'] == 'dragon_volcano':
            _volcano_head(view, entry, voice)
        source = entry['ru_us' if voice == 'ja' else 'ru_jp']
        target = entry['ru_jp' if voice == 'ja' else 'ru_us']
        protected = {_key(value) for value in target.values()}
        mapping = {}
        spellings = {}
        for case in _CASES:
            spelling = source[case]
            normalized = _key(spelling)
            mapping.setdefault(normalized, []).append((case, target[case]))
            spellings[normalized] = spelling
        for spelling, pair in _alias_cases(entry, source, target).items():
            normalized = _key(spelling)
            mapping.setdefault(normalized, []).append(pair)
            spellings[normalized] = spelling
        # Target phrases join the same longest-first match, so a ready target
        # such as «отряд Папа-защита» shields its shorter historical alias.
        for spelling in target.values():
            spellings.setdefault(_key(spelling), spelling)
        if not spellings:
            continue

        def replace(match):
            # Existing captions sometimes omit spaces around color spans.
            # A control anchor is a lexical boundary even when the visible text
            # is glued together; a normal Cyrillic substring still is not.
            anchors = {position for position, _ in view.tags}
            start, end = match.span()
            if ((start and start not in anchors and
                 re.fullmatch('[' + _LETTER + ']', view.visible[start - 1])) or
                (end < len(view.visible) and end not in anchors and
                 re.fullmatch('[' + _LETTER + ']', view.visible[end]))):
                return match.group()
            normalized = _key(match.group())
            if normalized in protected:
                return match.group()
            value = _choose(mapping[normalized], view.visible[:match.start()])
            return _capitalization(value, match.group())

        view.sub(_pattern(spellings.values(), boundaries=False), replace)
    result = view.render()
    if _TAG.findall(result) != controls:
        raise ValueError(f'{eid}: name transformation changes ordered control tokens')
    return result
