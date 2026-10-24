#!/usr/bin/env python3
"""Cross-reference database for all Alundra 2 modules.

Build once:   python3 xref.py build
Query:        python3 xref.py who-calls 0x8002FF90
              python3 xref.py who-writes 0x8005474C
              python3 xref.py who-reads 0x80068F60
              python3 xref.py who-refs 0x80148128        (any ref incl. ptr)
              python3 xref.py calls-from 0x80030C00 0x80030D00
              python3 xref.py refs-from 0x80030C00 0x80030D00
              python3 xref.py funcs 0x800C7070            (containing function)

Addresses reported as MODULE 0xVA. Mem refs resolved from lui+imm pairs
(linear sweep, per-register hi16 tracking; resets on register overwrite).
Function boundaries from analysis/functions_*.json if present, else from
prologue heuristic (addiu sp,sp,-N).
"""
import json, os, pickle, struct, sys

HERE = os.path.dirname(os.path.abspath(__file__))
PORT = os.path.dirname(HERE)
DISC = os.path.join(os.path.dirname(PORT), "disc_jp")
DB = os.path.join(PORT, "analysis", "xref.pickle")

MODULES = [
    # name, path, va_of_file_off0, code_start_file_off
    ("SCPS",    os.path.join(DISC, "SCPS_101.15"), 0x80016800, 0x800),
    ("GAME00",  os.path.join(DISC, "GAME00.BIN"),  0x800811D8, 0),
    ("EVENT00", os.path.join(DISC, "EVENT00.BIN"), 0x800811D8, 0),
    ("GAME01",  os.path.join(DISC, "GAME01.BIN"),  0x800811D8, 0),
    ("GAME02",  os.path.join(DISC, "GAME02.BIN"),  0x800811D8, 0),
    ("GAME03",  os.path.join(DISC, "GAME03.BIN"),  0x800811D8, 0),
]

LOADS = {0x20: "lb", 0x21: "lh", 0x23: "lw", 0x24: "lbu", 0x25: "lhu"}
STORES = {0x28: "sb", 0x29: "sh", 0x2B: "sw"}


def sweep(name, data, base, start):
    """Yield (site_va, kind, target) tuples.
    kind: call | read | write | ptr ; target: absolute address."""
    hi = {}                       # reg -> hi16<<16 from lui
    out = []
    n = len(data) & ~3
    for off in range(start, n, 4):
        w = struct.unpack_from("<I", data, off)[0]
        va = base + off
        op = w >> 26
        rs = (w >> 21) & 31
        rt = (w >> 16) & 31
        imm = w & 0xFFFF
        simm = imm - 0x10000 if imm & 0x8000 else imm
        if op == 3:                                   # jal
            out.append((va, "call", 0x80000000 | ((w & 0x3FFFFFF) << 2)))
            continue
        if op == 0x0F:                                # lui
            hi[rt] = imm << 16
            continue
        if op == 0x09 and rs in hi:                   # addiu rt, rs, imm
            tgt = (hi[rs] + simm) & 0xFFFFFFFF
            if 0x80000000 <= tgt < 0x80200000:
                out.append((va, "ptr", tgt))
            hi[rt] = None if rs != rt else hi.get(rt)
            if hi.get(rt) is None:
                hi.pop(rt, None)
            # addiu keeps full address in rt; track as exact base
            hi[rt] = tgt - 0  # store exact; mem ops add simm again below
            continue
        if op == 0x0D and rs in hi:                   # ori
            tgt = (hi[rs] | imm) & 0xFFFFFFFF
            if 0x80000000 <= tgt < 0x80200000:
                out.append((va, "ptr", tgt))
            hi[rt] = tgt
            continue
        if op in LOADS or op in STORES:
            if rs in hi and hi[rs] is not None:
                tgt = (hi[rs] + simm) & 0xFFFFFFFF
                if 0x80000000 <= tgt < 0x80200000:
                    out.append((va, "read" if op in LOADS else "write", tgt))
            if op in LOADS:
                hi.pop(rt, None)                      # rt clobbered
            continue
        # any other op writing rt/rd clobbers tracking (approximation)
        if op == 0:                                   # SPECIAL: rd written
            rd = (w >> 11) & 31
            hi.pop(rd, None)
        else:
            hi.pop(rt, None)
    return out


def find_funcs(name, data, base, start):
    """Function starts via prologue heuristic: addiu sp,sp,-N (N>0)."""
    starts = []
    n = len(data) & ~3
    for off in range(start, n, 4):
        w = struct.unpack_from("<I", data, off)[0]
        if (w >> 16) == 0x27BD and (w & 0x8000):      # addiu sp,sp,neg
            starts.append(base + off)
    return starts


def build():
    db = {"refs": [], "funcs": {}, "ptrscan": []}
    for name, path, base, start in MODULES:
        if not os.path.exists(path):
            print("skip", path)
            continue
        data = open(path, "rb").read()
        refs = sweep(name, data, base, start)
        db["refs"].extend((name, va, kind, tgt) for va, kind, tgt in refs)
        db["funcs"][name] = find_funcs(name, data, base, start)
        # data words that look like code/RAM pointers (for vtables/opcode tables)
        n = len(data) & ~3
        for off in range(start, n, 4):
            w = struct.unpack_from("<I", data, off)[0]
            if 0x80010000 <= w < 0x80200000 and (w & 3) == 0:
                db["ptrscan"].append((name, base + off, w))
        print(f"{name}: {len(refs)} refs, {len(db['funcs'][name])} funcs")
    os.makedirs(os.path.dirname(DB), exist_ok=True)
    with open(DB, "wb") as f:
        pickle.dump(db, f, protocol=4)
    print("written", DB)


def load():
    with open(DB, "rb") as f:
        return pickle.load(f)


def containing_func(db, mod, va):
    fs = db["funcs"].get(mod, [])
    import bisect
    i = bisect.bisect_right(fs, va) - 1
    return fs[i] if i >= 0 else None


def fmt(db, rows):
    for mod, va, kind, tgt in rows:
        f = containing_func(db, mod, va)
        fn = f"fn@0x{f:08X}" if f else "?"
        print(f"{mod:8} 0x{va:08X} {kind:5} -> 0x{tgt:08X}  ({fn})")


def main():
    if len(sys.argv) < 2 or sys.argv[1] == "build":
        build(); return
    cmd = sys.argv[1]
    db = load()
    if cmd in ("who-calls", "who-writes", "who-reads", "who-refs"):
        tgt = int(sys.argv[2], 16)
        want = {"who-calls": {"call"}, "who-writes": {"write"},
                "who-reads": {"read"},
                "who-refs": {"call", "read", "write", "ptr"}}[cmd]
        rows = [r for r in db["refs"] if r[3] == tgt and r[2] in want]
        fmt(db, rows)
        if cmd == "who-refs":
            for mod, va, w in db["ptrscan"]:
                if w == tgt:
                    print(f"{mod:8} 0x{va:08X} data-ptr")
    elif cmd in ("calls-from", "refs-from"):
        lo, hi = int(sys.argv[2], 16), int(sys.argv[3], 16)
        kinds = {"call"} if cmd == "calls-from" else {"call", "read",
                                                      "write", "ptr"}
        rows = [r for r in db["refs"] if lo <= r[1] < hi and r[2] in kinds]
        fmt(db, rows)
    elif cmd == "funcs":
        va = int(sys.argv[2], 16)
        for mod in db["funcs"]:
            f = containing_func(db, mod, va)
            if f:
                print(f"{mod}: containing fn 0x{f:08X}")
    else:
        print(__doc__)


if __name__ == "__main__":
    main()
