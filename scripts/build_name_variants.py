#!/usr/bin/env python3
"""Append four verified voice-name text variants to an installed archive.

Explicit input/output paths; original resources are never edited. All message
copies, terminators, controls, and non-text assets are checked before packing.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
from a2.native_archive import NativeArchive
from a2.grp import GrpArchive
from a2.pak import PakArchive
from a2.sub12 import TextPayload
from a2.bank import TextBank
from a2.vcast import Container, TextBank as VcastBank
from a2.cyrfont import charmap
from a2.textcodec import Message, encode_message
from stage_localization import catalogs, read_messages
from name_variants import decode_actual, controls, reflow, visible_width
from repack_resources import append_files

ROOT = Path(__file__).resolve().parents[1]
FILES = ('DATA/GRP.GP', 'DATA/PACK0.PAK', 'DATA/PAKVCAST.PAK')

def put(path, value):
    path.write_text(json.dumps(value, ensure_ascii=False, indent=2) + '\n')

def extract(archive, work, data):
    with archive.open('rb') as f: digest = hashlib.file_digest(f, 'sha256').hexdigest()
    identity = work / 'input-sha256.txt'
    if identity.exists() and identity.read_text().strip() != digest:
        raise ValueError('Existing extraction belongs to a different input archive')
    identity.write_text(digest + '\n')
    arc = NativeArchive(archive); result = {}
    try:
        for language in (0, 2):
            dst = work / f'base-{language}'
            for name in FILES:
                if not (dst / name).exists(): arc.extract(language, name, dst / name)
            messages = read_messages(dst, data)
            result[language] = {eid: decode_actual(m.encoded, language)[0] for eid, m in messages.items()}
            put(work / f'base-{language}.json', result[language])
    finally: arc.close()
    return result

def stage(base, dst, texts, language, data):
    mapping = charmap() if language == 0 else None
    original = read_messages(base, data)
    changed = {eid for eid, msg in original.items() if encode_message(Message(texts[eid], msg.end), mapping) != msg.encoded}
    (dst / 'DATA').mkdir(parents=True, exist_ok=False)
    def rewrite(bank, ids):
        for msg, eid in zip(bank.messages, ids, strict=True): msg.text = texts[eid]
        return bank.build(mapping)
    grp = GrpArchive.load(base / FILES[0]); before = []
    for g in grp.groups:
        raw = g.text_payload()
        prefix = bytes(g.data[:-len(raw)]) if raw else bytes(g.data)
        before.append((g.index, g.aliases, prefix))
        if raw is None: continue
        bank = TextPayload.parse(raw); ids = [bank.entry_id(m, g.index) for m in bank.messages]
        if changed.intersection(ids): g.set_text_payload(rewrite(bank, ids))
    grp.save(dst / FILES[0])
    saved = GrpArchive.load(dst / FILES[0])
    for g, (index, aliases, prefix) in zip(saved.groups, before, strict=True):
        actual = bytes(g.data[:len(prefix)])
        assert (g.index, g.aliases) == (index, aliases)
        assert actual[:0x74] == prefix[:0x74] and actual[0x78:] == prefix[0x78:], ('GRP asset', index)
    del grp, saved, before
    counts = {}
    for key, name, copies_key, cls, prefix in (
        ('pack0', FILES[1], 'bank_copies', TextBank, 'p0'),
        ('vcast', FILES[2], 'entry_copies', VcastBank, 'vc')):
        pak = PakArchive.load(base / name); old = list(pak.slots); touched = set(); count = 0
        for canonical, copies in data[key][copies_key].items():
            for copy in copies:
                container = Container.parse(pak.slots[copy]) if key == 'vcast' else None
                slot = container.find_textbank() if container else None
                raw = container.slots[slot] if container else pak.slots[copy]
                bank = cls.parse(raw); ids = [f'{prefix}.e{int(canonical):03d}.{k}' for k in range(len(bank.messages))]
                count += 1
                if not changed.intersection(ids): continue
                new = rewrite(bank, ids)
                if container:
                    old_slots = list(container.slots); container.slots[slot] = new
                    pak.slots[copy] = container.build()
                    rebuilt = Container.parse(pak.slots[copy])
                    assert all(value == rebuilt.slots[k] for k, value in enumerate(old_slots) if k != slot), ('VCAST asset', copy)
                else: pak.slots[copy] = new
                touched.add(copy)
        pak.save(dst / name)
        saved = PakArchive.load(dst / name)
        assert len(saved.slots) == len(old)
        assert all(value == saved.slots[k] for k, value in enumerate(old) if k not in touched), ('Asset', name)
        counts[key] = count
        del pak, saved, old
    actual = read_messages(dst, data)
    assert actual.keys() == original.keys() == texts.keys()
    for eid, msg in actual.items():
        assert msg.encoded == encode_message(Message(texts[eid], original[eid].end), mapping), ('Text roundtrip', language, eid)
    return {'canonical_messages_verified': len(actual), 'changed': len(changed), 'physical_banks_checked': counts,
            'nontext_assets_unchanged': True}

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--archive', type=Path, required=True)
    parser.add_argument('--work', type=Path, required=True)
    parser.add_argument('--output', type=Path)
    parser.add_argument('--extract-only', action='store_true')
    parser.add_argument('--text-only', action='store_true')
    args = parser.parse_args(); args.work.mkdir(parents=True, exist_ok=True)
    data = catalogs(ROOT / 'translations'); entries = {k: v for d in data.values() for k, v in d['entries'].items()}
    texts = extract(args.archive, args.work, data)
    if args.extract_only: return
    from voice_names_ru import transform_ru
    from voice_names_en import transform_en
    glossary = json.loads((ROOT / 'translations/voice_names.json').read_text())
    overrides = json.loads((ROOT / 'translations/voice_name_overrides.json').read_text())
    layout_overrides_path = ROOT / 'translations/voice_name_layout.json'
    layouts = json.loads(layout_overrides_path.read_text()) if layout_overrides_path.exists() else {}
    additions = {}; report = {}; errors = []
    for language in (0, 2):
        for voice in ('ja', 'en'):
            route = voice + ('_ru' if language == 0 else '_en'); out = {}; changes = {}
            for eid, old in texts[language].items():
                new = transform_ru(eid, old, voice, glossary, overrides) if language == 0 else transform_en(eid, old, voice, glossary)
                new = layouts.get(route, {}).get(eid, new)
                if controls(old) != controls(new) or re.findall(r'%[-#0-9.lh]*[a-zA-Z]', old) != re.findall(r'%[-#0-9.lh]*[a-zA-Z]', new):
                    errors.append((route, eid, 'controls', old, new)); continue
                if old != new:
                    entry = entries[eid]; width = 48 if entry.get('layout') == 'item_description' else 47 if entry.get('layout') == 'item_action' else 34
                    # Retain source UI labels' single-line role and the existing
                    # dialogue page capacity. Never invent extra pages.
                    max_lines = max(3, max(p.count('\n') + 1 for p in old.split('{PAGE}')))
                    if old.startswith('{SYS}') and controls(old) == ['{SYS}'] and '\n' not in old:
                        max_lines = 1
                    try:
                        # Original English dialogue already uses wider lines.
                        # Preserve its per-page envelope; do not re-edit entire
                        # unmodified pages because a name changed elsewhere.
                        old_pages = old.split('{PAGE}'); new_pages = new.split('{PAGE}')
                        fitted = []
                        for old_page, new_page in zip(old_pages, new_pages, strict=True):
                            page_width = max(width, max(map(visible_width, old_page.split('\n')))) if language == 2 else width
                            fitted.append(old_page if old_page == new_page else reflow(new_page, page_width, max_lines))
                        new = '{PAGE}'.join(fitted)
                    except ValueError as e: errors.append((route, eid, str(e), old, new))
                    changes[eid] = {'before': old, 'after': new}
                out[eid] = new
            put(args.work / f'{route}.json', out); put(args.work / f'{route}-changes.json', changes)
            report[route] = {'canonical_messages': len(out), 'changed': len(changes)}
    put(args.work / 'text-errors.json', errors); put(args.work / 'text-summary.json', report)
    if errors: raise ValueError(f'{len(errors)} name/layout errors; see text-errors.json')
    if args.text_only: return
    if args.output is None: parser.error('--output required for archive cook')
    for language in (0, 2):
        for voice in ('ja', 'en'):
            route = voice + ('_ru' if language == 0 else '_en')
            out = json.loads((args.work / f'{route}.json').read_text()); dst = args.work / route
            report[route].update(stage(args.work / f'base-{language}', dst, out, language, data))
            additions.update({(language, f'NAMES/{voice.upper()}/{name}'): dst / name for name in FILES})
    report['archive'] = append_files(args.archive, args.output, additions)
    # Read every newly stored byte back through independent decompression/CRC.
    arc = NativeArchive(args.output)
    for (language, name), path in additions.items():
        read, size = arc.logical(language, name)
        digest = hashlib.sha256()
        for pos in range(0, size, 1024 * 1024): digest.update(read(pos, min(size - pos, 1024 * 1024)))
        with path.open('rb') as f: assert digest.hexdigest() == hashlib.file_digest(f, 'sha256').hexdigest(), name
    arc.close()
    report['archive']['all_variant_bytes_verified'] = True
    with args.archive.open('rb') as f: report['input_sha256'] = hashlib.file_digest(f, 'sha256').hexdigest()
    with args.output.open('rb') as f: report['output_sha256'] = hashlib.file_digest(f, 'sha256').hexdigest()
    put(args.work / 'acceptance.json', report); print(json.dumps(report, indent=2))

if __name__ == '__main__': main()
