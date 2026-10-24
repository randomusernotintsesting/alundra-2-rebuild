#!/usr/bin/env python3
"""UI text in overlay executables (GAME01/02/03.BIN minigame UI,
GAME00.BIN memory-card save title).

Usage:
  ui_text.py dump   [-d discdir] [-o transdir]   -> translations/ui_text.json
  ui_text.py insert [-d discdir] [-t transdir] [-o outdir] [--extend]

Strings are referenced from MIPS code immediates (lui/addiu pairs), catalogued
in tools/analysis/exe-text/strings.json. Insertion:
  - if the encoded translation fits the original slot (byte_len + nul_pad - 1),
    it is written in place;
  - otherwise, with --extend, the string is appended to the end of the file
    (overlays map 1:1 to RAM at 0x80084A98 + file offset) and every reference
    immediate is repointed. NOTE: whether the loader reads the enlarged file
    must be confirmed in an emulator before shipping --extend output.

Markup: printable ASCII verbatim, any other byte as {XX} (e.g. credits embed
{01}{C0} control pairs - keep them). GAME00 entries are Shift-JIS (save title
shown by the PS1 card browser): text is given as a plain string, re-encoded
to Shift-JIS on insert.
"""
import json
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from a2.pristine import source

CATALOG = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                       "tools", "analysis", "exe-text", "strings.json")


def load_catalog():
    with open(CATALOG, encoding="utf-8") as f:
        d = json.load(f)
    bases = {k: int(v, 16) for k, v in d["load_bases"].items()}
    return bases, d["files"]


def decode_slot(raw, encoding):
    if encoding == "shift_jis":
        return raw.decode("shift_jis")
    out = []
    for b in raw:
        out.append(chr(b) if 0x20 <= b < 0x7F and chr(b) != "{" else f"{{{b:02X}}}")
    return "".join(out)


def encode_slot(text, encoding):
    if encoding == "shift_jis":
        return text.encode("shift_jis")
    out = bytearray()
    i = 0
    while i < len(text):
        if text[i] == "{":
            if len(text) < i + 4 or text[i + 3] != "}":
                raise ValueError(f"bad byte tag at {i}: {text[i:i+6]!r}")
            out.append(int(text[i + 1:i + 3], 16))
            i += 4
        else:
            b = ord(text[i])
            if not 0x20 <= b < 0x7F:
                raise ValueError(f"char {text[i]!r} is not ASCII; "
                                 "UI font has no such glyph yet")
            out.append(b)
            i += 1
    return bytes(out)


def dump(disc, transdir):
    bases, files = load_catalog()
    entries = {}
    for fname, strings in files.items():
        with open(source(disc, fname), "rb") as f:
            data = f.read()
        for s in strings:
            off, blen = int(s["offset"], 16), int(s["byte_len"], 16)
            enc = s["encoding"]
            eid = f"{fname}:{s['offset']}"
            entries[eid] = {
                "ctx": s["region"],
                "max_inplace": blen + int(s["nul_pad"], 16) - 1,
                "orig": decode_slot(data[off:off + blen], enc),
                "text": "",
            }
    path = os.path.join(transdir, "ui_text.json")
    os.makedirs(transdir, exist_ok=True)
    with open(path, "w", encoding="utf-8") as f:
        json.dump({"source": "GAME0x.BIN overlays", "entries": entries},
                  f, ensure_ascii=False, indent=1)
    print(f"{path}: {len(entries)} strings")


def patch_refs(data, refs, new_addr):
    for r in refs:
        if r["type"] == "code_imm":
            lo = new_addr & 0xFFFF
            hi = (new_addr >> 16) + (1 if lo & 0x8000 else 0)
            struct.pack_into("<H", data, int(r["imm_op_offset"], 16), lo)
            struct.pack_into("<H", data, int(r["lui_offset"], 16), hi & 0xFFFF)
        elif r["type"] == "data_ptr":
            struct.pack_into("<I", data, int(r["offset"], 16), new_addr)
        else:
            raise ValueError(f"unknown ref type {r['type']}")


def insert(disc, transdir, outdir, extend):
    bases, files = load_catalog()
    with open(os.path.join(transdir, "ui_text.json"), encoding="utf-8") as f:
        trans = json.load(f)["entries"]
    os.makedirs(outdir, exist_ok=True)
    for fname, strings in files.items():
        with open(source(disc, fname), "rb") as f:
            data = bytearray(f.read())
        base = bases[fname]
        patched = appended = 0
        for s in strings:
            eid = f"{fname}:{s['offset']}"
            t = trans.get(eid, {}).get("text")
            if not t:
                continue
            enc = encode_slot(t, s["encoding"])
            off, blen = int(s["offset"], 16), int(s["byte_len"], 16)
            slot = blen + int(s["nul_pad"], 16)
            if len(enc) < slot:  # fits incl. terminating NUL
                data[off:off + slot] = enc + b"\x00" * (slot - len(enc))
                patched += 1
            elif extend:
                while len(data) % 4:
                    data += b"\x00"
                new_off = len(data)
                data += enc + b"\x00"
                patch_refs(data, s["refs"], base + new_off)
                appended += 1
            else:
                print(f"  SKIP {eid}: needs {len(enc) + 1} bytes, slot is "
                      f"{slot} (use --extend)")
        if patched or appended:
            with open(os.path.join(outdir, fname), "wb") as f:
                f.write(data)
            print(f"{fname}: {patched} in place, {appended} appended"
                  + (" (test enlarged overlay in emulator!)" if appended else ""))


def main():
    args = sys.argv[1:]
    if not args or args[0] not in ("dump", "insert"):
        print(__doc__)
        sys.exit(1)
    cmd, args = args[0], args[1:]
    opt = {"-d": "disc", "-t": "translations", "-o": None}
    extend = "--extend" in args
    for k in ("-d", "-t", "-o"):
        if k in args:
            opt[k] = args[args.index(k) + 1]
    if cmd == "dump":
        dump(opt["-d"], opt["-o"] or opt["-t"])
    else:
        insert(opt["-d"], opt["-t"], opt["-o"] or opt["-d"], extend)


if __name__ == "__main__":
    main()
