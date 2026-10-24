"""Function inventory for Alundra 2 JP executables.

Segments each module into functions using two evidence sources:
  1. jal targets (intra- and inter-module)
  2. stack-frame prologues: addiu sp,sp,-N at word-aligned offsets
Then walks each function to collect: callees (jal), BIOS syscalls
(jr $tN with tN=0xA0/0xB0/0xC0 and t1=num in the surrounding window),
hardware register access (lui reg,0x1F80), and jr-$ra presence.

Output: port/analysis/functions.json
Usage: python3 inventory.py
"""
import json
import struct
import sys
from collections import defaultdict
from pathlib import Path

from modules import MODULES, load, entry_pc

OUT = Path(__file__).resolve().parents[1] / "analysis"

RAM_LO, RAM_HI = 0x80010000, 0x80200000  # plausible code range (2MB RAM)


def words(data, start):
    """Yield (file_offset, word) for word-aligned code region."""
    end = len(data) - (len(data) - start) % 4
    for off in range(start, end, 4):
        yield off, struct.unpack_from("<I", data, off)[0]


def scan_module(name):
    data, base, code_start = load(name)
    size = len(data)
    lo_ram = base + code_start
    hi_ram = base + size

    jal_targets = set()
    prologues = set()
    insns = {}  # ram -> word

    for off, w in words(data, code_start):
        ram = base + off
        insns[ram] = w
        op = w >> 26
        if op == 3:  # jal
            tgt = (ram & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
            if RAM_LO <= tgt < RAM_HI:
                jal_targets.add(tgt)
        # addiu sp,sp,-N : op=9 rs=29 rt=29 imm<0
        if op == 9 and ((w >> 21) & 31) == 29 and ((w >> 16) & 31) == 29:
            imm = w & 0xFFFF
            if imm >= 0x8000:
                prologues.add(ram)

    return {
        "name": name, "base": base, "code_start": code_start, "size": size,
        "lo": lo_ram, "hi": hi_ram,
        "jal_targets": jal_targets, "prologues": prologues, "insns": insns,
    }


T_REGS = {8: "t0", 9: "t1", 10: "t2", 11: "t3"}


def analyze_function(mod, start, end):
    """Walk [start,end) collecting calls/syscalls/hw access."""
    insns = mod["insns"]
    callees = set()
    syscalls = []
    hw = False
    has_jr_ra = False
    last_imm = {}  # reg -> last immediate loaded via addiu rt,zero,imm / ori rt,zero,imm
    for ram in range(start, end, 4):
        w = insns.get(ram)
        if w is None:
            continue
        op = w >> 26
        rs, rt = (w >> 21) & 31, (w >> 16) & 31
        imm = w & 0xFFFF
        if op == 3:
            tgt = (ram & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
            callees.add(tgt)
        elif op in (9, 13) and rs == 0:  # addiu/ori rt, zero, imm
            last_imm[rt] = imm
        elif op == 15:  # lui
            if imm == 0x1F80:
                hw = True
            last_imm.pop(rt, None)
        elif op == 0 and (w & 0x3F) == 8:  # jr
            if rs == 31:
                has_jr_ra = True
            elif rs in T_REGS:
                # delay slot may set t1
                nw = insns.get(ram + 4)
                if nw is not None and (nw >> 26) in (9, 13) and ((nw >> 21) & 31) == 0:
                    last_imm[(nw >> 16) & 31] = nw & 0xFFFF
                table = last_imm.get(rs)
                if table in (0xA0, 0xB0, 0xC0):
                    num = last_imm.get(9)  # t1
                    syscalls.append([table, num])
    return callees, syscalls, hw, has_jr_ra


def main():
    mods = {name: scan_module(name) for name in MODULES}

    # seeds across modules: every jal target seen anywhere + prologues + entry
    all_targets = set()
    for m in mods.values():
        all_targets |= m["jal_targets"]
    all_targets.add(entry_pc())

    report = {}
    for name, m in mods.items():
        starts = sorted(
            t for t in (m["prologues"] | all_targets) if m["lo"] <= t < m["hi"]
        )
        funcs = []
        for i, s in enumerate(starts):
            e = starts[i + 1] if i + 1 < len(starts) else m["hi"]
            callees, syscalls, hw, jr_ra = analyze_function(m, s, e)
            funcs.append({
                "ram": s, "size": e - s,
                "file_off": s - m["base"],
                "callees": sorted(callees),
                "syscalls": syscalls,
                "hw": hw, "jr_ra": jr_ra,
                "is_jal_target": s in all_targets,
                "has_prologue": s in m["prologues"],
            })
        report[name] = {
            "base": m["base"], "lo": m["lo"], "hi": m["hi"],
            "n_functions": len(funcs), "functions": funcs,
        }
        n_sys = sum(1 for f in funcs if f["syscalls"])
        n_hw = sum(1 for f in funcs if f["hw"])
        print(f"{name}: {len(funcs)} candidate functions, "
              f"{n_sys} with BIOS syscalls, {n_hw} touching HW regs")

    OUT.mkdir(exist_ok=True)
    out = OUT / "functions.json"
    out.write_text(json.dumps(report))
    print(f"wrote {out}")


if __name__ == "__main__":
    sys.exit(main())
