#!/usr/bin/env python3
"""Audit actual RU/EN banks and every physical copy without extracting assets.

Read only the installed A2RES archive; round-trip each message's original
bytes with the active font mapping. {JP:...} is a raw glyph token, which
can mean punctuation or a controller icon rather than Japanese text.
"""
import argparse
from collections import Counter
import json
from pathlib import Path
import re
import struct

from a2.bank import TextBank
from a2.native_archive import NativeArchive
from a2.sub12 import TextPayload
from a2.vcast import Container, TextBank as VcastBank
from name_variants import decode_actual
from stage_localization import catalogs


def pak_slots(read, size):
    first, = struct.unpack('<I', read(0, 4))
    offsets = struct.unpack(f'<{first // 4}I', read(0, first))
    nonzero = [(i, off) for i, off in enumerate(offsets) if off]
    return {i: (off, (nonzero[k + 1][1] if k + 1 < len(nonzero) else size) - off)
            for k, (i, off) in enumerate(nonzero)}


def read_installed(arc, language, prefix, data):
    result = {}
    counts = Counter()
    def add(eid, message):
        text, _ = decode_actual(message.encoded, language)
        if eid in result and result[eid] != text:
            raise ValueError(f'different physical text copy: {eid}')
        result[eid] = text
        counts['physical_messages_checked'] += 1

    read, size = arc.logical(language, prefix + 'DATA/GRP.GP')
    toc = struct.unpack('<512I', read(0, 2048))
    unique = sorted(set(toc))
    ends = dict(zip(unique, unique[1:] + [size]))
    seen = set()
    for group, off in enumerate(toc):
        if off in seen:
            counts['grp_aliases_checked'] += 1
            continue
        seen.add(off)
        suboff, subsize = struct.unpack('<2I', read(off + 0x70, 8))
        if suboff == subsize == 0:
            continue
        assert off + suboff + 0x104 + subsize == ends[off]
        bank = TextPayload.parse(read(ends[off] - subsize, subsize))
        counts['grp_text_banks_checked'] += 1
        for msg in bank.messages:
            add(bank.entry_id(msg, group), msg)

    for key, filename, copy_key, cls, tag in (
        ('pack0', 'DATA/PACK0.PAK', 'bank_copies', TextBank, 'p0'),
        ('vcast', 'DATA/PAKVCAST.PAK', 'entry_copies', VcastBank, 'vc')):
        read, size = arc.logical(language, prefix + filename)
        slots = pak_slots(read, size)
        for canonical, copies in data[key][copy_key].items():
            first = None
            for copy in copies:
                raw = read(*slots[copy])
                if key == 'vcast':
                    container = Container.parse(raw)
                    raw = container.slots[container.find_textbank()]
                if first is not None and first != raw:
                    raise ValueError(f'{prefix}{key} copy {copy} differs from {canonical}')
                first = raw
                bank = cls.parse(raw)
                counts[key + '_text_banks_checked'] += 1
                for k, msg in enumerate(bank.messages):
                    add(f'{tag}.e{int(canonical):03d}.{k}', msg)
    expected_ids = {eid for catalog in data.values() for eid in catalog['entries']}
    assert result.keys() == expected_ids
    counts['canonical_messages_checked'] = len(result)
    return result, dict(counts)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--archive', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--expected-variants', type=Path)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    data = catalogs(Path(__file__).resolve().parents[1] / 'translations')
    arc = NativeArchive(args.archive)
    report = {'archive': str(args.archive.resolve()), 'routes': {}}
    try:
        for language, lang in ((0, 'ru'), (2, 'en')):
            for voice in ('base', 'ja', 'en'):
                prefix = '' if voice == 'base' else f'NAMES/{voice.upper()}/'
                route = f'{voice}_{lang}'
                actual, counts = read_installed(arc, language, prefix, data)
                if args.expected_variants and voice != 'base':
                    expected = json.loads((args.expected_variants / f'{route}.json').read_text())
                    assert actual.keys() == expected.keys(), route
                    changes = {eid: {'prior': expected[eid], 'installed': text}
                               for eid, text in actual.items() if text != expected[eid]}
                    counts['prior_cook_differences'] = changes
                residues = {eid: text for eid, text in actual.items() if '{JP:' in text}
                glyphs = Counter(re.findall(r'\{JP:([0-9A-F]{4})\}', '\n'.join(residues.values())))
                counts.update(raw_glyph_tokens=dict(glyphs), raw_glyph_messages=residues,
                              dynamic_name_messages=sum('{NAME}' in s for s in actual.values()),
                              screenshot_message=actual['g002.s6'])
                report['routes'][route] = counts
                (args.output / f'{route}.json').write_text(json.dumps(actual, ensure_ascii=False, indent=2) + '\n')
                print(route, {k: v for k, v in counts.items()
                              if k not in ('raw_glyph_messages', 'prior_cook_differences')}, flush=True)
    finally:
        arc.close()
    (args.output / 'residue-census.json').write_text(json.dumps(report, ensure_ascii=False, indent=2) + '\n')


if __name__ == '__main__':
    main()
