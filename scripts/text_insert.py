#!/usr/bin/env python3
"""Insert translated text back into game files.

Usage: text_insert.py [-d discdir] [-t transdir] [-c charmap.json] [-o outdir]

Reads translations/grp_text.json and translations/pack0_text.json, re-parses
the ORIGINAL archives for structure, replaces message text where "text" is
non-empty, rebuilds DATA/GRP.GP and DATA/PACK0.PAK into outdir (default:
in place under discdir — originals are the disc/ extraction, re-extractable
from the .bin image at any time).

charmap.json (optional): {"А": 128, ...} maps non-ASCII chars to 16-bit
token values (needed for Cyrillic once the font is patched).
"""
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from a2.bank import TextBank
from a2.grp import GrpArchive
from a2.pak import PakArchive
from a2.sub12 import TextPayload
from a2.textcodec import Message, encode_message
from a2.pristine import source
from validate_translations import check


def load_translations(path):
    with open(path, encoding="utf-8") as f:
        return json.load(f)


def apply(msg, trans, eid, stats, charmap=None, skipped=None):
    if eid not in trans:
        raise ValueError(f"{eid}: missing translation entry")
    t = trans[eid]
    if t.get("text"):
        try:
            encode_message(Message(t["text"], msg.end), charmap)
        except ValueError as e:
            raise ValueError(f"{eid}: {e}") from e
        msg.text = t["text"]
        stats[0] += 1
    stats[1] += 1


def preflight(transdir, charmap):
    """Reject bad replacements in any bank before writing any archive.

    Layout/font validation is specific to the Russian charmap; encoding
    validation also applies when this tool is used without that mapping.
    """
    for name in ("grp", "pack0", "vcast"):
        data = load_translations(os.path.join(transdir, name + "_text.json"))
        for eid, entry in data["entries"].items():
            text = entry.get("text")
            if not text:
                continue
            try:
                encode_message(Message(text, 1), charmap)
            except ValueError as e:
                raise ValueError(f"{eid}: {e}") from e
            if charmap:
                errors = check(entry, text)
                if errors:
                    raise ValueError(f"{eid}: {'; '.join(errors)}")


def insert_grp(disc, transdir, outdir, charmap):
    data = load_translations(os.path.join(transdir, "grp_text.json"))
    trans = data["entries"]
    arc = GrpArchive.load(source(disc, "DATA/GRP.GP"))
    stats = [0, 0]
    for g in arc.groups:
        payload = g.text_payload()
        if payload is None:
            continue
        tp = TextPayload.parse(payload)
        for m in tp.messages:
            apply(m, trans, tp.entry_id(m, g.index), stats, charmap)
        g.set_text_payload(tp.build(charmap))
    out = os.path.join(outdir, "DATA", "GRP.GP")
    arc.save(out)
    print(f"{out}: rebuilt, {stats[0]}/{stats[1]} messages translated")


def insert_pack0(disc, transdir, outdir, charmap):
    data = load_translations(os.path.join(transdir, "pack0_text.json"))
    trans = data["entries"]
    copies = {int(k): v for k, v in data["bank_copies"].items()}
    arc = PakArchive.load(source(disc, "DATA/PACK0.PAK"))
    stats = [0, 0]
    for ci, idxs in sorted(copies.items()):
        b = TextBank.parse(arc.slots[ci])
        for k, m in enumerate(b.messages):
            apply(m, trans, f"p0.e{ci:03d}.{k}", stats, charmap)
        built = b.build(charmap)
        for i in idxs:
            arc.slots[i] = built
    out = os.path.join(outdir, "DATA", "PACK0.PAK")
    arc.save(out)
    print(f"{out}: rebuilt, {stats[0]}/{stats[1]} messages translated")


def insert_vcast(disc, transdir, outdir, charmap):
    from a2.vcast import Container, TextBank
    data = load_translations(os.path.join(transdir, "vcast_text.json"))
    trans = data["entries"]
    copies = {int(k): v for k, v in data["entry_copies"].items()}
    if not any(t.get("text") for t in trans.values()):
        print("vcast: no translations, PAKVCAST.PAK left untouched")
        return
    arc = PakArchive.load(source(disc, "DATA/PAKVCAST.PAK"))
    translated = {k.split(".")[1] for k, t in trans.items() if t.get("text")}
    stats = [0, 0]
    for ci, idxs in sorted(copies.items()):
        if f"e{ci:03d}" not in translated:
            continue
        # idxs share an identical text bank but their containers differ:
        # rebuild each container with the translated bank
        bank = None
        for i in idxs:
            c = Container.parse(arc.slots[i])
            slot = c.find_textbank()
            if bank is None:
                b = TextBank.parse(c.slots[slot])
                for k, m in enumerate(b.messages):
                    apply(m, trans, f"vc.e{ci:03d}.{k}", stats, charmap)
                bank = b.build(charmap)
            c.slots[slot] = bank
            arc.slots[i] = c.build()
    out = os.path.join(outdir, "DATA", "PAKVCAST.PAK")
    arc.save(out)
    print(f"{out}: rebuilt, {stats[0]} messages translated")


def main():
    args = sys.argv[1:]
    disc, transdir, charmap_path = "disc", "translations", None
    outdir = None
    if "-d" in args:
        disc = args[args.index("-d") + 1]
    if "-t" in args:
        transdir = args[args.index("-t") + 1]
    if "-c" in args:
        charmap_path = args[args.index("-c") + 1]
    if "-o" in args:
        outdir = args[args.index("-o") + 1]
    outdir = outdir or disc
    charmap = None
    if charmap_path:
        with open(charmap_path, encoding="utf-8") as f:
            charmap = {k: int(v) for k, v in json.load(f).items()}
    preflight(transdir, charmap)
    os.makedirs(os.path.join(outdir, "DATA"), exist_ok=True)
    insert_grp(disc, transdir, outdir, charmap)
    insert_pack0(disc, transdir, outdir, charmap)
    insert_vcast(disc, transdir, outdir, charmap)


if __name__ == "__main__":
    main()
