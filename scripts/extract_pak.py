#!/usr/bin/env python3
"""Extract PAK archives into per-entry files.

Usage: extract_pak.py [PAK file]... [-o outdir]
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from a2.pak import PakArchive


def main():
    args = sys.argv[1:]
    outdir = "extracted"
    if "-o" in args:
        i = args.index("-o")
        outdir = args[i + 1]
        del args[i:i + 2]
    if not args:
        args = [f"disc/DATA/{n}" for n in
                ("PACK0.PAK", "PACK1.PAK", "PAKOMAKE.PAK", "PAKVCAST.PAK")]
    for path in args:
        name = os.path.splitext(os.path.basename(path))[0].lower()
        pdir = os.path.join(outdir, name)
        os.makedirs(pdir, exist_ok=True)
        arc = PakArchive.load(path)
        count = 0
        for i, entry in enumerate(arc.slots):
            if entry is None:
                continue
            with open(os.path.join(pdir, f"{i:04d}.bin"), "wb") as f:
                f.write(entry)
            count += 1
        print(f"{path}: {count} entries -> {pdir}")


if __name__ == "__main__":
    main()
