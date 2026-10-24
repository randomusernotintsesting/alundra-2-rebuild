#!/usr/bin/env python3
"""Extract GRP.GP into per-group directories with sub-resources.

Usage: extract_grp.py [GRP.GP] [outdir]
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from a2.grp import GrpArchive


def main():
    grp_path = sys.argv[1] if len(sys.argv) > 1 else "disc/DATA/GRP.GP"
    outdir = sys.argv[2] if len(sys.argv) > 2 else "extracted/grp"
    arc = GrpArchive.load(grp_path)
    for g in arc.groups:
        name = g.name or f"group{g.index:03d}"
        gdir = os.path.join(outdir, f"{g.index:03d}_{name}")
        os.makedirs(gdir, exist_ok=True)
        with open(os.path.join(gdir, "header.bin"), "wb") as f:
            f.write(g.data[:256])
        # header +0x04 is the END of main data (group-relative, recorded
        # coords); real bytes of recorded region [a, b) live at [a+4, b+4)
        with open(os.path.join(gdir, "main.bin"), "wb") as f:
            f.write(g.data[0x104:g.main_end + 4])
        for n, (off, size) in enumerate(g.subs()):
            if off or size:
                with open(os.path.join(gdir, f"sub_{n:02d}.bin"), "wb") as f:
                    f.write(g.get_sub(n))
    print(f"extracted {len(arc.groups)} groups -> {outdir}")


if __name__ == "__main__":
    main()
