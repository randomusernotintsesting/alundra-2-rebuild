"""Match PSY-Q SDK library signatures against SCPS_101.15.

Signatures: https://github.com/lab313ru/psx_psyq_signatures (cloned to
/tmp/psyq_sigs) — per-SDK-version JSON: masked byte pattern per object
file + named labels at offsets.

Usage: python3 psyq_match.py [sigdir]
Writes port/analysis/psyq_names.json  { "0x800XXXXX": "CdRead", ... }
"""
import json
import re
import sys
from pathlib import Path

from modules import load

SIGS = Path(sys.argv[1] if len(sys.argv) > 1 else "/tmp/psyq_sigs")
OUT = Path(__file__).resolve().parents[1] / "analysis"


def sig_to_regex(sig_hex):
    parts = sig_hex.split()
    out = []
    for p in parts:
        if p == "??":
            out.append(b".")
        else:
            out.append(re.escape(bytes([int(p, 16)])))
    return b"".join(out)


def match_version(ver_dir, data, base):
    names = {}
    n_objs = 0
    for jf in sorted(ver_dir.glob("*.json")):
        try:
            objs = json.loads(jf.read_text())
        except Exception:
            continue
        for obj in objs:
            sig = obj.get("sig", "")
            if len(sig.split()) < 32:          # too short = false positives
                continue
            rx = re.compile(sig_to_regex(sig), re.S)
            for m in rx.finditer(data):
                off = m.start()
                if off % 4:
                    continue
                n_objs += 1
                for lab in obj.get("labels", []):
                    # labels: {"name": ..., "offset": N} or [name, off]
                    if isinstance(lab, dict):
                        nm, lo = lab.get("name"), lab.get("offset", 0)
                    else:
                        nm, lo = lab[0], lab[1]
                    if not nm or nm.startswith("loc_"):
                        continue
                    names[base + off + lo] = nm
                break                           # first hit per object
    return names, n_objs


def main():
    data, base, _ = load("SCPS")
    best = None
    for ver_dir in sorted(SIGS.iterdir()):
        if not ver_dir.is_dir() or not list(ver_dir.glob("*.json")):
            continue
        names, n = match_version(ver_dir, data, base)
        print(f"SDK {ver_dir.name}: {n} objects matched, "
              f"{len(names)} named addresses")
        if best is None or len(names) > len(best[1]):
            best = (ver_dir.name, names)
    ver, names = best
    OUT.mkdir(exist_ok=True)
    out = OUT / "psyq_names.json"
    out.write_text(json.dumps(
        {f"0x{a:08X}": n for a, n in sorted(names.items())}, indent=0))
    print(f"best: SDK {ver} -> {out} ({len(names)} names)")


if __name__ == "__main__":
    main()
