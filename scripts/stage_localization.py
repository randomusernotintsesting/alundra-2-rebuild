#!/usr/bin/env python3
"""Build/verify Russian text and fonts in a new directory, preserving custom art.

Never promotes output to the working disc or changes an original image.
Usage: python3 scripts/stage_localization.py --output port/build/localization-stage
"""
import argparse
import json
from pathlib import Path

from a2.bank import TextBank
from a2.cyrfont import build_banks, charmap as font_charmap
from a2.grp import GrpArchive
from a2.pak import PakArchive
from a2.sub12 import TextPayload
from a2.textcodec import Message, encode_message
from a2.vcast import Container, TextBank as VcastBank
from font_patch import DIALOGUE_SLOTS, SUBTITLE_SLOTS
from text_insert import insert_grp, insert_pack0, insert_vcast, preflight

ROOT = Path(__file__).resolve().parents[1]


def merge_pack_assets(staged, current, text_slots):
    if len(staged.slots) != len(current.slots):
        raise ValueError("PACK0 layout changed; refusing to guess asset identities")
    if any(i < 0 or i >= len(staged.slots) for i in text_slots):
        raise ValueError("text slot is outside PACK0")
    for i in range(len(staged.slots)):
        if i not in text_slots:
            staged.slots[i] = current.slots[i]


def catalogs(transdir):
    return {name: json.loads((transdir / (name + "_text.json")).read_text(encoding="utf-8"))
            for name in ("grp", "pack0", "vcast")}


def read_messages(disc, data):
    messages = {}
    grp = GrpArchive.load(disc / "DATA/GRP.GP")
    for group in grp.groups:
        payload = group.text_payload()
        if payload is not None:
            bank = TextPayload.parse(payload)
            for msg in bank.messages:
                messages[bank.entry_id(msg, group.index)] = msg
    pack = PakArchive.load(disc / "DATA/PACK0.PAK")
    for canonical, copies in data["pack0"]["bank_copies"].items():
        canonical = int(canonical)
        for i in copies:
            if pack.slots[i] != pack.slots[canonical]:
                raise ValueError(f"PACK0 text copy {i} differs from {canonical}")
        for k, msg in enumerate(TextBank.parse(pack.slots[canonical]).messages):
            messages[f"p0.e{canonical:03d}.{k}"] = msg
    vcast = PakArchive.load(disc / "DATA/PAKVCAST.PAK")
    for canonical, copies in data["vcast"]["entry_copies"].items():
        first = None
        for i in copies:
            container = Container.parse(vcast.slots[i])
            raw = container.slots[container.find_textbank()]
            if first is not None and raw != first:
                raise ValueError(f"VCAST text copy {i} differs from {canonical}")
            first = raw
        for k, msg in enumerate(VcastBank.parse(first).messages):
            messages[f"vc.e{int(canonical):03d}.{k}"] = msg
    return messages


def compare_messages(actual, original, entries, charmap):
    if actual.keys() != original.keys() or entries.keys() != original.keys():
        raise ValueError("translation/archive message IDs differ")
    for eid, msg in actual.items():
        reference = original[eid]
        expected = Message(entries[eid].get("text") or reference.text, reference.end)
        actual_bytes = msg.encoded if hasattr(msg, "encoded") else encode_message(msg)
        if actual_bytes != encode_message(expected, charmap):
            raise ValueError(f"{eid}: staged text or terminator does not match translation")


def stage(disc, transdir, out):
    pristine = Path(str(disc) + ".orig")
    for name in ("GRP.GP", "PACK0.PAK", "PAKVCAST.PAK"):
        if not (pristine / "DATA" / name).is_file():
            raise ValueError(f"missing pristine source: {name}")
    mapping = font_charmap()
    preflight(str(transdir), mapping)
    data = catalogs(transdir)
    entries = {eid: entry for catalog in data.values()
               for eid, entry in catalog["entries"].items()}
    original = read_messages(pristine, data)
    if original.keys() != entries.keys():
        raise ValueError("catalog does not cover every canonical original message")
    # Reusing an output could confuse incomplete files with a verified build.
    out.mkdir(parents=True, exist_ok=False)
    (out / "DATA").mkdir()
    for insert in (insert_grp, insert_pack0, insert_vcast):
        insert(str(disc), str(transdir), str(out), mapping)

    pack = PakArchive.load(out / "DATA/PACK0.PAK")
    current_pack = PakArchive.load(disc / "DATA/PACK0.PAK")
    text_slots = {i for copies in data["pack0"]["bank_copies"].values() for i in copies}
    merge_pack_assets(pack, current_pack, text_slots)
    original_pack = PakArchive.load(pristine / "DATA/PACK0.PAK")
    bank16, bank24 = build_banks(original_pack.slots[548], original_pack.slots[545])
    for slots, bank in ((DIALOGUE_SLOTS, bank16), (SUBTITLE_SLOTS, bank24)):
        for i in slots:
            if len(bank) != len(original_pack.slots[i]):
                raise ValueError(f"font allocation size changed at {i}")
            pack.slots[i] = bank
    font_slots = set(DIALOGUE_SLOTS + SUBTITLE_SLOTS)
    pack.save(out / "DATA/PACK0.PAK")
    saved_pack = PakArchive.load(out / "DATA/PACK0.PAK")
    for i in range(len(pack.slots)):
        if i not in text_slots | font_slots and saved_pack.slots[i] != current_pack.slots[i]:
            raise ValueError(f"non-text PACK0 asset changed at {i}")

    # Replace only text payloads inside the CURRENT scene and cutscene assets.
    staged_grp = GrpArchive.load(out / "DATA/GRP.GP")
    current_grp = GrpArchive.load(disc / "DATA/GRP.GP")
    if [(g.index, g.aliases) for g in staged_grp.groups] != [
            (g.index, g.aliases) for g in current_grp.groups]:
        raise ValueError("GRP group identities changed")
    for new, current in zip(staged_grp.groups, current_grp.groups):
        if new.text_payload() is not None:
            current.set_text_payload(new.text_payload())
    current_grp.save(out / "DATA/GRP.GP")
    staged_vcast = PakArchive.load(out / "DATA/PAKVCAST.PAK")
    current_vcast = PakArchive.load(disc / "DATA/PAKVCAST.PAK")
    if len(staged_vcast.slots) != len(current_vcast.slots):
        raise ValueError("VCAST container identities changed")
    for copies in data["vcast"]["entry_copies"].values():
        for i in copies:
            new = Container.parse(staged_vcast.slots[i])
            current = Container.parse(current_vcast.slots[i])
            target = current.find_textbank()
            if target != new.find_textbank():
                raise ValueError(f"VCAST bank layout changed at {i}")
            current.slots[target] = new.slots[target]
            current_vcast.slots[i] = current.build()
    current_vcast.save(out / "DATA/PAKVCAST.PAK")

    compare_messages(read_messages(out, data), original, entries, mapping)
    manifest = {"canonical_messages_verified": len(entries),
                "pack0_text_slots": sorted(text_slots), "font_slots": sorted(font_slots),
                "working_disc_unchanged": str(disc),
                "preserved": "All non-text/non-font assets from the current working archives"}
    (out / "verified.json").write_text(json.dumps(manifest, indent=2) + "\n")
    print(f"Verified {len(entries)} canonical messages, all copies, and preserved assets: {out}")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--disc", type=Path, default=ROOT / "disc_jp")
    parser.add_argument("--translations", type=Path, default=ROOT / "translations")
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    stage(args.disc.resolve(), args.translations.resolve(), args.output.resolve())


if __name__ == "__main__":
    main()
