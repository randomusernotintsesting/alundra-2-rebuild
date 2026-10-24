#!/usr/bin/env python3
"""Transplant US-localized TEXTURE slots into the Russian build's PACK0.

The Russian build translated every string/font BANK, but none of the
pre-rendered texture containers that carry Japanese text (title menu,
in-game menu pages, inventory headers — the T1-T12 census in
tools/analysis/jp-gfx/FINDINGS.md).  The US disc has all of them
professionally redrawn in English; drop those in as stage 1
(selective Russian re-rendering can override individual slots later).

Selection rule (per slot, computed — no hand-typed slot lists):
    jp  = pristine JP slot     (a2.pristine source)
    us  = US disc slot         (disc/DATA/PACK0.PAK)
    cur = current build slot   (discdir/DATA/PACK0.PAK)
    transplant IFF jp != us            (US localizers redrew it)
             AND cur == jp             (Russian build left it Japanese)
             AND looks_texture(jp)     (RLE texture container, not a bank)

Idempotent: after a run cur == us, so re-runs skip those slots.

Usage: gfx_transplant.py [-d discdir] [--dry-run]
"""
import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from a2.pak import PakArchive
from a2.pristine import source

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
US_PACK0 = os.path.join(ROOT, "disc", "DATA", "PACK0.PAK")

# Title-screen suite + ending credits: the JP code draws these chunks
# with its own UV layout and the US chunks are arranged differently —
# transplanting slot 23 painted the US legal text over the title menu.
# Keep them Japanese; they get targeted Russian redraws instead.
EXCLUDE = {23, 24, 25, 26, 27, 28}


def looks_texture(b):
    """RLE texture container: [u32 nchunks 1..10][u32 npal 1..32]
    [u16 w][u16 h] with sane dimensions."""
    if b is None or len(b) < 16 + 40:
        return False
    nchunks, npal = struct.unpack_from("<II", b, 0)
    w, h = struct.unpack_from("<HH", b, 8)
    return (1 <= nchunks <= 10 and 1 <= npal <= 32 and
            8 <= w <= 1024 and 8 <= h <= 512)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-d", "--disc", default="disc_jp")
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()

    discdir = os.path.join(ROOT, args.disc)
    cur_path = os.path.join(discdir, "DATA", "PACK0.PAK")
    cur = PakArchive.load(cur_path)
    uspk = PakArchive.load(US_PACK0)
    jppk = PakArchive.load(source(discdir, os.path.join("DATA", "PACK0.PAK")))

    n = min(len(cur.slots), len(uspk.slots), len(jppk.slots))
    moved = []
    restored = []
    skipped_ru = []
    for i in range(n):
        jp, us, ru = jppk.slots[i], uspk.slots[i], cur.slots[i]
        if jp is None or us is None:
            continue
        if i in EXCLUDE:
            if ru == us:                   # undo an earlier transplant
                cur.slots[i] = jp
                restored.append(i)
            continue
        if jp == us:
            continue                       # no JP text (identical art)
        if ru != jp:
            skipped_ru.append(i)           # Russian build already edited
            continue
        if not looks_texture(jp):
            continue                       # string/font bank — leave alone
        cur.slots[i] = us
        moved.append(i)

    print(f"transplanted {len(moved)} texture slots from US:")
    print(" ", ", ".join(map(str, moved)))
    if restored:
        print(f"restored to JP (excluded): {restored}")
    print(f"left alone (already localized by the RU build): "
          f"{len(skipped_ru)} slots")
    if not args.dry_run and (moved or restored):
        cur.save(cur_path)
        print(f"written: {cur_path}")


if __name__ == "__main__":
    main()
