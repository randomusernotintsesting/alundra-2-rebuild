#!/usr/bin/env python3
"""Rebuild localized archives with the ORIGINAL byte layout preserved.

The game bakes absolute sector positions (streaming Setloc targets) both
for files and for content inside PACK0/GRP/PAKVCAST.  mkpsxiso lays files
out sequentially, so any size change shifts everything after it — the
localized build grew +70 sectors and broke streaming (emulator hangs at
menu, port hangs in prologue).

Strategy: for every internal unit (PAK slot / GRP group), if the localized
unit fits the original size — pad with zeros to the exact original size;
if it overflows — REVERT to the original unit (translation temporarily
lost, reported).  Output archives are byte-length-identical to pristine,
so the rebuilt disc keeps the original layout sector-for-sector.

Usage: preserve_layout.py [--out disc_fixed]
Reads  disc_jp/ (localized) + disc_jp.orig/ (pristine stash).
"""
import os, struct, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from a2.pak import PakArchive
from a2.grp import GrpArchive

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LOC = os.path.join(ROOT, "disc_jp")
ORG = os.path.join(ROOT, "disc_jp.orig")


def fix_pak(name, out_path):
    o = PakArchive.load(os.path.join(ORG, "DATA", name))
    n = PakArchive.load(os.path.join(LOC, "DATA", name))
    reverted, padded = [], 0
    slots = []
    for i, (a, b) in enumerate(zip(o.slots, n.slots)):
        la = len(a) if a is not None else 0
        lb = len(b) if b is not None else 0
        if (a is None) != (b is None):
            reverted.append(i); slots.append(a); continue
        if a is None:
            slots.append(None); continue
        if lb > la:
            reverted.append(i); slots.append(a)
        elif lb < la:
            padded += 1; slots.append(b + b"\x00" * (la - lb))
        else:
            slots.append(b)
    PakArchive(slots, tail=o.tail).save(out_path)
    osz = os.path.getsize(os.path.join(ORG, "DATA", name))
    nsz = os.path.getsize(out_path)
    assert nsz == osz, f"{name}: {nsz} != {osz}"
    print(f"{name}: padded {padded}, reverted {len(reverted)} slots "
          f"{reverted[:20]}{'...' if len(reverted) > 20 else ''}")
    return reverted


def fix_grp(out_path):
    o = GrpArchive.load(os.path.join(ORG, "DATA", "GRP.GP"))
    n = GrpArchive.load(os.path.join(LOC, "DATA", "GRP.GP"))
    on = {g.index: g for g in o.groups}
    reverted, padded = [], 0
    for g in n.groups:
        og = on.get(g.index)
        if og is None or g.offset != og.offset and False:
            continue
        if len(g.data) > len(og.data):
            g.data = bytearray(og.data)          # revert whole group
            reverted.append(g.name)
        elif len(g.data) < len(og.data):
            # pad the sub12 text payload (always the group tail) to make
            # the group byte-length match the original exactly
            pad = len(og.data) - len(g.data)
            off, size = struct.unpack_from("<II", g.data, 0x70)
            if off == 0 and size == 0:
                g.data += b"\x00" * pad          # no sub12: raw tail pad
            else:
                g.data += b"\x00" * pad
                struct.pack_into("<I", g.data, 0x74, size + pad)
            padded += 1
    n.save(out_path)
    osz = os.path.getsize(os.path.join(ORG, "DATA", "GRP.GP"))
    nsz = os.path.getsize(out_path)
    assert nsz == osz, f"GRP.GP: {nsz} != {osz}"
    # TOC must be identical to pristine (offsets preserved)
    with open(out_path, "rb") as f1, \
         open(os.path.join(ORG, "DATA", "GRP.GP"), "rb") as f2:
        assert f1.read(2048) == f2.read(2048), "GRP TOC changed!"
    print(f"GRP.GP: padded {padded}, reverted {len(reverted)} groups "
          f"{reverted[:12]}{'...' if len(reverted) > 12 else ''}")
    return reverted


def main():
    out = sys.argv[sys.argv.index("--out") + 1] if "--out" in sys.argv \
        else os.path.join(ROOT, "disc_fixed")
    os.makedirs(os.path.join(out, "DATA"), exist_ok=True)
    # hardlink everything unchanged from the localized tree
    for sub in ("", "DATA"):
        src = os.path.join(LOC, sub)
        dst = os.path.join(out, sub)
        for fn in os.listdir(src):
            s, d = os.path.join(src, fn), os.path.join(dst, fn)
            if os.path.isfile(s) and not os.path.exists(d):
                os.link(s, d)
    # exe + overlay: must already be size-identical (in-place patched)
    for fn in ("SCPS_101.15", "GAME00.BIN"):
        a = os.path.getsize(os.path.join(ORG, fn))
        b = os.path.getsize(os.path.join(LOC, fn))
        assert a == b, f"{fn} size changed: {b} vs {a} — fix separately"
    rep = {}
    for name in ("PACK0.PAK", "PAKVCAST.PAK"):
        d = os.path.join(out, "DATA", name)
        if os.path.exists(d):
            os.unlink(d)
        rep[name] = fix_pak(name, d)
    d = os.path.join(out, "DATA", "GRP.GP")
    if os.path.exists(d):
        os.unlink(d)
    rep["GRP.GP"] = fix_grp(d)
    import json
    with open(os.path.join(out, "reverted_units.json"), "w") as f:
        json.dump(rep, f, indent=1, ensure_ascii=False)
    print("tree ready:", out)


if __name__ == "__main__":
    main()
