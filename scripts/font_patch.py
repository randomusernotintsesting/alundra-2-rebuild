#!/usr/bin/env python3
"""Patch the JP disc fonts with Cyrillic glyphs.

Usage: font_patch.py [-d discdir]   (default: disc_jp)

Replaces 66 unused-by-JP-text ASCII cells (Latin letters + rare symbols)
with Cyrillic in the dialogue (12x16) and subtitle (12x24) ASCII font
banks of DATA/PACK0.PAK.  The same redrawn bank is written into every
style-variant slot so Cyrillic renders no matter which font style the
engine selects:

  dialogue 12x16: slots 536, 540, 544, 548, 551
  subtitle 12x24: slots 537, 541, 545, 549, 552

Bank sizes are unchanged (96 records), per-glyph variable width is kept,
and NO SCPS_101.15 patch is needed: the engine's ASCII path already
accepts any cell (clamp is `char-0x20 < 0xE0`), the load sizes fit, and
all touched cells are <= 0x7F so the mode-0/2 `andi 0x7F` masks don't
matter either.

Latin source glyphs are always read from the pristine PACK0 stash
(disc_jp.orig), but the patch is applied to the CURRENT discdir PACK0 so
it composes with text_insert.py output.  Run this AFTER text_insert.py
(text_insert rebuilds PACK0 from pristine and would drop the font patch).

Also (re)writes scripts/charmap.json mapping each Cyrillic char to its
16-bit text token (0xFF00 | char_byte) for text_insert.py -c.
"""
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from a2 import cyrfont
from a2.pak import PakArchive
from a2.pristine import source

DIALOGUE_SLOTS = (536, 540, 544, 548, 551)
SUBTITLE_SLOTS = (537, 541, 545, 549, 552)


def main():
    args = sys.argv[1:]
    disc = "disc_jp"
    if "-d" in args:
        disc = args[args.index("-d") + 1]

    pristine = PakArchive.load(source(disc, "DATA/PACK0.PAK"))
    bank16, bank24 = cyrfont.build_banks(pristine.slots[548],
                                         pristine.slots[545])
    assert len(bank16) == len(pristine.slots[548]) == 4704
    assert len(bank24) == len(pristine.slots[545]) == 7008

    target = os.path.join(disc, "DATA", "PACK0.PAK")
    arc = PakArchive.load(target)
    changed = []
    for slot in DIALOGUE_SLOTS:
        if arc.slots[slot] != bank16:
            arc.slots[slot] = bank16
            changed.append(slot)
    for slot in SUBTITLE_SLOTS:
        if arc.slots[slot] != bank24:
            arc.slots[slot] = bank24
            changed.append(slot)
    if changed:
        arc.save(target)
        print(f"{target}: replaced font banks in slots {changed}")
    else:
        print(f"{target}: already patched, nothing to do")
    print("SCPS_101.15: no patch required (cells 0x23-0x7F are within the "
          "stock ASCII bank; sizes and clamps unchanged)")

    cm_path = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                           "charmap.json")
    cm = {c: v for c, v in sorted(cyrfont.charmap().items())}
    with open(cm_path, "w", encoding="utf-8") as f:
        json.dump(cm, f, ensure_ascii=False, indent=1)
    print(f"{cm_path}: {len(cm)} chars")


if __name__ == "__main__":
    main()
