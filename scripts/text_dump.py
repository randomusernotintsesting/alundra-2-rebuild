#!/usr/bin/env python3
"""Dump all localizable text to translation JSON files.

Usage: text_dump.py [-d discdir] [-o outdir]

Produces in outdir (default translations/):
  grp_text.json    - dialogue/room text from GRP.GP sub12 (one entry per message)
  pack0_text.json  - system/menu/item text banks from PACK0.PAK

Each entry: {"ctx": ..., "orig": "...", "text": ""}. Put the translation in
"text"; empty text = keep original. Markup: see a2/textcodec.py.
"""
import hashlib
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from a2.bank import TextBank
from a2.grp import GrpArchive
from a2.pristine import source
from a2.sub12 import TextPayload


def dump_grp(disc, out):
    arc = GrpArchive.load(source(disc, "DATA/GRP.GP"))
    entries = {}
    groups = 0
    for g in arc.groups:
        payload = g.text_payload()
        if payload is None:
            continue
        tp = TextPayload.parse(payload)
        groups += 1
        for m in tp.messages:
            eid = tp.entry_id(m, g.index)
            entries[eid] = {"ctx": g.name, "orig": m.text, "text": ""}
    path = os.path.join(out, "grp_text.json")
    with open(path, "w", encoding="utf-8") as f:
        json.dump({"source": "DATA/GRP.GP", "entries": entries},
                  f, ensure_ascii=False, indent=1)
    print(f"{path}: {len(entries)} entries from {groups} groups")


def dump_pack0(disc, out):
    from a2.pak import PakArchive
    arc = PakArchive.load(source(disc, "DATA/PACK0.PAK"))
    # detect text banks; identical entries (stored as N copies) dedup by md5
    canon_by_md5 = {}
    copies = {}  # canonical index -> [all indices]
    banks = {}
    for i, e in enumerate(arc.slots):
        if e is None:
            continue
        b = TextBank.detect(e)
        if b is None:
            continue
        h = hashlib.md5(e).hexdigest()
        if h in canon_by_md5:
            copies[canon_by_md5[h]].append(i)
            continue
        canon_by_md5[h] = i
        copies[i] = [i]
        banks[i] = b
    entries = {}
    for ci, b in sorted(banks.items()):
        for k, m in enumerate(b.messages):
            entries[f"p0.e{ci:03d}.{k}"] = {
                "ctx": f"PACK0 entry {ci} (copies: {copies[ci]})",
                "orig": m.text, "text": ""}
    path = os.path.join(out, "pack0_text.json")
    with open(path, "w", encoding="utf-8") as f:
        json.dump({"source": "DATA/PACK0.PAK",
                   "bank_copies": {str(k): v for k, v in sorted(copies.items())},
                   "entries": entries},
                  f, ensure_ascii=False, indent=1)
    print(f"{path}: {len(entries)} entries from {len(banks)} unique banks "
          f"({sum(len(v) for v in copies.values())} entries incl. copies)")


def dump_vcast(disc, out, include_all=False):
    import re
    from a2.pak import PakArchive
    from a2.vcast import Container
    arc = PakArchive.load(source(disc, "DATA/PAKVCAST.PAK"))
    canon_by_md5 = {}
    copies = {}
    entries = {}
    n_banks = 0
    for i, e in enumerate(arc.slots):
        if e is None:
            continue
        try:
            c = Container.parse(e)
            bank_slot = c.find_textbank()
        except ValueError:
            continue
        if bank_slot is None:
            continue
        # entries can share an identical text bank inside different
        # cutscene containers (e.g. 62/66) - translate once
        h = hashlib.md5(c.slots[bank_slot]).hexdigest()
        if h in canon_by_md5:
            copies[canon_by_md5[h]].append(i)
            continue
        canon_by_md5[h] = i
        copies[i] = [i]
        from a2.vcast import TextBank
        b = TextBank.parse(c.slots[bank_slot])
        # by default skip banks with no latin text (US: Japanese leftovers);
        # for the JP disc pass include_all=True - all banks are subtitles
        if not include_all and not any(
                re.search(r"[A-Za-z]", re.sub(r"\{[^}]*\}", "", m.text))
                for m in b.messages):
            continue
        n_banks += 1
        for j, m in enumerate(b.messages):
            entries[f"vc.e{i:03d}.{j}"] = {
                "ctx": f"PAKVCAST entry {i} (copies: {copies[i]})",
                "orig": m.text, "text": ""}
    path = os.path.join(out, "vcast_text.json")
    with open(path, "w", encoding="utf-8") as f:
        json.dump({"source": "DATA/PAKVCAST.PAK",
                   "entry_copies": {str(k): v for k, v in sorted(copies.items())},
                   "entries": entries},
                  f, ensure_ascii=False, indent=1)
    print(f"{path}: {len(entries)} entries from {n_banks} cutscenes")


def main():
    args = sys.argv[1:]
    disc, out = "disc", "translations"
    if "-d" in args:
        disc = args[args.index("-d") + 1]
    if "-o" in args:
        out = args[args.index("-o") + 1]
    os.makedirs(out, exist_ok=True)
    dump_grp(disc, out)
    dump_pack0(disc, out)
    dump_vcast(disc, out, include_all="-a" in args)


if __name__ == "__main__":
    main()
