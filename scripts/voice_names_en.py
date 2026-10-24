"""Transform English name identities for a selected voice, without editing tags.

The source can be original US prose or supplemental English. The reviewed
schema-1 glossary is supplied by the caller; no files or global profile state
are consulted. Japanese Latin spellings are the glossary's project proposals.
Line wrapping is deliberately left to the text staging layer.
"""
from difflib import SequenceMatcher
import re

_TAG = re.compile(r'\{[^{}]*\}')
_TRANSPARENT = re.compile(r'\{(?:SYS|04:[0-9a-fA-F]{4})\}\Z')
# Original US localization names her here even where the Japanese line does
# not: dialogue g049/g220 and the three prophecy/house UI labels.
_OMEGA_US_ADDITIONS = {'g049.name', 'g196.name', 'g197.name', 'g199.name', 'g220.s1'}
# Bare titles in the reviewed corpus refer to Nijador, including US-added
# dialogue and the document he issues. Keep Baron/Count ordinary words in
# other entries; full names have their own unambiguous rule below.
_NIJADOR_TITLE_REFERENCES = {
    'g009.s9', 'g107.s1', 'g140.s6', 'g184.s19', 'g199.s57', 'g202.s1',
    'g203.s1', 'g203.s2', 'g203.s3', 'g203.s5', 'g205.s3', 'g206.name',
    'g236.s1', 'g236.s3', 'g239.s2', 'g239.s4', 'g244.s1', 'g244.s10',
    'g265.s9', 'g269.s0', 'g340.s12', 'g340.s18', 'g340.s21', 'g340.s29',
    'g371.s1', 'g371.s12', 'g371.s16', 'g394.s15', 'g421.s13', 'g422.s10',
    'g422.s12', 'g422.s14', 'g422.s17', 'g422.name', 'g426.s0', 'g426.s7',
    'g426.s11', 'g426.s23', 'g426.s29', 'p0.e299.10', 'vc.e007.6',
    'vc.e010.6', 'vc.e017.4', 'vc.e017.7', 'vc.e017.9', 'vc.e123.2',
    'vc.e206.9', 'vc.e210.8', 'vc.e219.10', 'vc.e219.16', 'vc.e228.7',
}


def _without_tags(text):
    return _TAG.sub('', text)


def _preserve_tags(source, replacement):
    """Transfer existing controls over a visible edit; never import new ones."""
    replacement = _without_tags(replacement)
    tags, plain, cursor = [], [], 0
    visible_length = 0
    for match in _TAG.finditer(source):
        chunk = source[cursor:match.start()]
        plain.append(chunk)
        visible_length += len(chunk)
        tags.append((visible_length, match.group()))
        cursor = match.end()
    plain.append(source[cursor:])
    old = ''.join(plain)
    if not tags:
        return replacement
    edits = SequenceMatcher(None, old, replacement, autojunk=False).get_opcodes()
    insertions, previous = [], 0
    for offset, token in tags:
        if offset == 0:
            at = 0
        elif offset == len(old):
            at = len(replacement)
        else:
            at = len(replacement)
            for kind, a, b, c, d in edits:
                if a <= offset <= b:
                    if kind == 'equal':
                        at = c + offset - a
                    else:
                        at = c if b == a else c + round((offset-a)*(d-c)/(b-a))
                    break
        at = max(previous, at)
        insertions.append((at, token))
        previous = at
    result, cursor = [], 0
    for at, token in insertions:
        result.extend((replacement[cursor:at], token))
        cursor = at
    result.append(replacement[cursor:])
    return ''.join(result)


def _visible_with_offsets(text):
    """Colors/system controls are transparent; placeholders/pages are barriers."""
    visible, positions, cursor = [], [], 0
    for match in _TAG.finditer(text):
        visible.extend(text[cursor:match.start()])
        positions.extend(range(cursor, match.start()))
        if not _TRANSPARENT.fullmatch(match.group()):
            visible.append('\0')
            positions.append(match.start())
        cursor = match.end()
    visible.extend(text[cursor:])
    positions.extend(range(cursor, len(text)))
    return ''.join(visible), positions


def _rules(eid, voice, glossary):
    rules = {}
    entries = {entry['key']: entry for entry in glossary['entries']}
    for entry in glossary['entries']:
        if entry.get('scope') == 'entry_only' and eid not in entry.get('jp_occurrence_ids', ()):
            continue
        us, jp = entry['en_us'], entry['en_jp_proposed']
        for alias in set(entry.get('english_us_aliases', ())) | {us, jp}:
            if ((entry['key'] == 'hedva' and alias == 'Omega') or
                (entry['key'] == 'webrock' and alias == 'Webb') or
                (entry['key'] == 'salamander' and alias in {'Newt', 'Salamander'})):
                if eid not in entry.get('jp_occurrence_ids', ()) and not (
                    entry['key'] == 'hedva' and eid in _OMEGA_US_ADDITIONS
                ):
                    continue
            # Keep official prose's optional titles and abbreviated names in
            # the US profile; only Japanese identity inputs need conversion.
            rules[alias] = jp if voice == 'ja' else (us if alias == jp else alias)

    def pair(aliases, ja, en=None):
        for alias in aliases:
            rules[alias] = ja if voice == 'ja' else (en if en is not None else alias)

    pair(('Lord Prunewell', 'Lord Burian', 'Lord Lord Burian'), 'Lord Burian', 'Lord Prunewell')
    pair(('Burian',), 'Lord Burian', 'Prunewell')
    pair(('Baron Diaz', 'Baron Nijador', 'Count Nijador'), 'Count Nijador', 'Baron Diaz')
    if eid in _NIJADOR_TITLE_REFERENCES:
        pair(('Baron', 'Count'), 'Count', 'Baron')
    if eid == 'vc.e219.10':
        pair(('B-', 'C-'), 'C-', 'B-')
    pair(('Dr. Ndoul', 'Dr Ndoul', 'Doctor Ndoul', 'Dr. Dr. Ndoul', 'Dr Dr Ndoul'),
         'Dr. Ndoul', 'Roswell the Sage')
    pair(('Ndoul',), 'Dr. Ndoul', 'Roswell')
    pair(('Roswell the Sage',), 'Dr. Ndoul')
    pair(('Axelia', 'Exilia'), 'Shaia', 'Axelya')
    pair(('Eden ruins', 'Paradise ruins'), 'Paradise ruins', 'Eden ruins')
    for prefix in ('Mt. ', 'Mt ', 'Mount '):
        pair((prefix+'Firedrake', prefix+'Dragon Volcano'), 'Dragon Volcano', prefix+'Firedrake')
        pair((prefix+'Sparrowhawk',), prefix+'Chobidaka')
        pair((prefix+'Sparrowhead', prefix+'Chobidaka'), prefix+'Chobidaka', prefix+'Sparrowhawk')
    pair(('Firedrake',), 'Dragon Volcano')
    if eid == 'g232.s1':
        pair(("There's a volcano named Firedrake", "There's a Dragon Volcano"),
             "There's a Dragon Volcano", "There's a volcano named Firedrake")
    if eid == 'g050.s50':
        pair(('the Howling Cave', "the Huey's Wind Cave"), "Huey's Wind Cave", 'the Howling Cave')
    pair(('Gamar',), 'Yugi')
    pair(('Yugi',), 'Yugi', 'Gamar')
    pair(('Gamar Island',), 'Yugi Island')
    for apostrophe in ("'", '\u2019'):
        pair(('Milena'+apostrophe+'s', 'Mercedes'+apostrophe, 'Mercedes'+apostrophe+'s'),
             'Mercedes'+apostrophe, 'Milena'+apostrophe+'s')
    pair(('Vanilla Wafers',), 'Vanilla Manju')
    # The ingredient is unrelated to the kingdom/dynasty of the same name.
    pair(('Vanilla flavored wafer', 'Vanilla-flavored wafer'), 'Vanilla flavored wafer')
    if eid == 'p0.e299.202':
        rules.pop('Vanilla', None)
    if eid in entries['salamander'].get('jp_occurrence_ids', ()):
        pair(('Newts', 'Salamanders'), 'Salamanders', 'Newts')
    if eid in {'g215.s16', 'g217.s16', 'g219.s16', 'g215.s20', 'g217.s20', 'g219.s20', 'g484.s34'}:
        pair(('Salamander',), 'Salamander', 'Newt')
    # Wampeter names two unrelated Japanese dishes. Never infer identity
    # from that English word outside these verified dialogue IDs.
    if eid in {'g182.s12', 'g182.s13', 'g182.s20', 'g182.s21', 'g185.name'}:
        pair(('Wampeter', 'Itadaki'), 'Itadaki', 'Wampeter')
    if eid == 'g182.s18':
        # US expands this same restaurant's greeting to advertise the dish
        # explicitly named Itadaki in adjacent s12/s13/s20/s21 Japanese lines.
        pair(('Wampeters', 'Itadaki dishes'), 'Itadaki dishes', 'Wampeters')
    if eid == 'g185.name':
        pair(('Goo Goo Bird', 'Tricky'), 'Tricky', 'Goo Goo Bird')
    # The US script sometimes emphasizes names (notably STAR KEY). Admit
    # exact uppercase variants without treating ordinary lower-case words
    # such as flint/newt as names, and preserve the original emphasis.
    rules.update({alias.upper(): target.upper() for alias, target in tuple(rules.items())})
    return rules


def transform_en(eid, text, voice, glossary):
    """Return English text with JA or US identities and the same control tags.

    Explicit reviewed English repairs take priority over alias conversion.
    Repairs change visible prose only: their suggested color tags cannot add,
    remove or reorder the caller's actual controls or editable {NAME} token.
    """
    if voice not in ('ja', 'en'):
        raise ValueError("voice must be 'ja' or 'en'")
    if not isinstance(text, str):
        raise TypeError('text must be a string')
    repair = glossary.get('explicit_entry_repairs', {}).get(eid, {}).get(voice+'_en')
    if repair is not None:
        text = _preserve_tags(text, repair)
    rules = _rules(eid, voice, glossary)
    # One longest-first substitution pass avoids chaining Vanilla Manju into
    # Varuna Manju or expanding a replacement's already present title.
    aliases = sorted(rules, key=lambda alias: (-len(alias), alias))
    patterns = [r'\s+'.join(re.escape(word) for word in alias.split()) for alias in aliases]
    pattern = re.compile(r'(?<!\w)(?:'+'|'.join(patterns)+r')(?!\w)')
    visible, offsets = _visible_with_offsets(text)
    changes = []
    for match in pattern.finditer(visible):
        alias = re.sub(r'\s+', ' ', match.group())
        replacement = rules[alias]
        if replacement == alias:
            continue
        begin, end = offsets[match.start()], offsets[match.end()-1]+1
        changes.append((begin, end, _preserve_tags(text[begin:end], replacement)))
    for begin, end, replacement in reversed(changes):
        text = text[:begin]+replacement+text[end:]
    return text
