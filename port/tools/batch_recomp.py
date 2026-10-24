"""Batch recompiler: whole module -> chunked C + dispatch table.

Usage: python3 batch_recomp.py SCPS ../gen

Function boundaries come from port/analysis/functions.json and stay FIXED.
Additional entry points (cross-function branch targets, address-taken
candidates from data words and lui/addiu pairs) are emitted as OVERLAPPING
functions: f_<entry> covers [entry, end-of-enclosing-original-function).
This keeps jump-table recovery intact while making every plausible
indirect-call target callable.
"""
import bisect
import json
import re
import struct
import sys
from pathlib import Path

from modules import MODULES, load
from recomp import recompile_one
from startup_flow import patch_startup_continuation
from actor_snapshot_hooks import patch_actor_snapshot_hooks
from dialogue_packet_hooks import patch_dialogue_packet_hooks
from actor_source_hooks import patch_actor_source_hooks
from scene_submit_hooks import patch_scene_submit_hooks
from world_shadow_hooks import patch_world_shadow_hooks

ANALYSIS = Path(__file__).resolve().parents[1] / "analysis"
CHUNK = 150

HLE_OVERRIDES = set()

# per-module symbol prefix: overlays share the address space, so their
# function names must not collide; addresses OUTSIDE the module (SCPS
# callees) keep the f_ prefix
PREFIX = {"SCPS": "f_", "GAME00": "g0_", "GAME01": "g1_",
          "GAME02": "g2_", "GAME03": "g3_", "EVENT00": "ev_"}


def address_taken(data, base, lo, hi, code_start):
    """Code addresses referenced by data words or lui/addiu(/ori) pairs."""
    cands = set()
    last_lui = {}
    for off in range(code_start, len(data) - 3, 4):
        w = struct.unpack_from("<I", data, off)[0]
        if lo <= w < hi and w % 4 == 0:
            cands.add(w)
        op = w >> 26
        rs, rt = (w >> 21) & 31, (w >> 16) & 31
        imm = w & 0xFFFF
        if op == 15:
            last_lui[rt] = imm << 16
        elif op == 9 and rs in last_lui:
            simm = imm - 0x10000 if imm & 0x8000 else imm
            a = (last_lui[rs] + simm) & 0xFFFFFFFF
            if lo <= a < hi and a % 4 == 0:
                cands.add(a)
        elif op == 13 and rs in last_lui:
            a = last_lui[rs] | imm
            if lo <= a < hi and a % 4 == 0:
                cands.add(a)
    return cands


def main(mod, outdir):
    out = Path(outdir)
    out.mkdir(parents=True, exist_ok=True)
    report = json.loads((ANALYSIS / "functions.json").read_text())[mod]
    data, base, code_start = load(mod)
    lo, hi = report["lo"], report["hi"]

    bounds = sorted(f["ram"] for f in report["functions"])

    def end_of(s):
        k = bisect.bisect_right(bounds, s)
        return bounds[k] if k < len(bounds) else hi

    entries = set(bounds)
    entries |= address_taken(data, base, lo, hi, code_start)
    # every call return site (jal/bal/jalr): longjmp and exception-exit
    # continuations, plus jr-through-register returns
    for off in range(code_start, len(data) - 3, 4):
        w = struct.unpack_from("<I", data, off)[0]
        op = w >> 26
        is_call = (op == 3 or
                   (op == 1 and ((w >> 16) & 31) in (16, 17)) or
                   (op == 0 and (w & 0x3F) == 9))
        if is_call:
            ret = base + off + 8
            if lo <= ret < hi:
                entries.add(ret)

    results, failed = {}, {}
    queue = sorted(entries)
    while queue:
        next_queue = []
        for s in queue:
            if s in results or s in failed:
                continue
            try:
                r = recompile_one(data, base, lo, hi, s, end_of(s),
                                  hle=HLE_OVERRIDES)
                r.code = patch_startup_continuation(mod, data, base, s, r.code)
                r.code = patch_actor_snapshot_hooks(mod, data, base, s, r.code)
                r.code = patch_dialogue_packet_hooks(mod, data, base, s, r.code)
                r.code = patch_actor_source_hooks(mod, data, base, s, r.code)
                r.code = patch_scene_submit_hooks(mod, data, base, s, r.code)
                r.code = patch_world_shadow_hooks(mod, data, base, s, r.code)
                results[s] = r
            except NotImplementedError as ex:
                failed[s] = str(ex)
                continue
            for t in r.extern_branches:
                if lo <= t < hi and t not in results and t not in failed:
                    next_queue.append(t)
        queue = next_queue

    emitted = set(results) | set(failed)
    pfx = PREFIX[mod]

    def fixup(code, r):
        for t in sorted(r.extern_branches):
            # a branch/jump/fallthrough into another function is a JUMP:
            # the current frame is dead — always tail, never a call
            # (direct f_X() here piles host frames in jr-state-machines)
            code = code.replace(f"ef_{t:08X}()", f"psx_tail(0x{t:08X}u)")
        for t in sorted(r.callees_direct):
            if t not in emitted or not (lo <= t < hi):
                code = code.replace(f"f_{t:08X}();", f"psx_call(0x{t:08X}u);")
        return code

    def prefix_syms(text):
        """f_<addr> -> module prefix for in-module addresses only."""
        if pfx == "f_":
            return text
        def sub(m):
            a = int(m.group(1), 16)
            return (pfx if lo <= a < hi else "f_") + m.group(1)
        return re.sub(r"\bf_([0-9A-F]{8})\b", sub, text)

    ordered = sorted(emitted)
    chunks = [ordered[i:i + CHUNK] for i in range(0, len(ordered), CHUNK)]
    all_text = []
    for ci, chunk in enumerate(chunks):
        body = []
        for s in chunk:
            if s in failed:
                body.append(f"void f_{s:08X}(void) {{ psx_trap(0x{s:08X}u); }}"
                            f"  /* {failed[s][:90]} */")
            else:
                r = results[s]
                body.append(fixup(r.code, r))
            body.append("")
        all_text.append(prefix_syms("\n".join(body)))

    # declare every referenced symbol (own prefix + cross-module f_)
    refs = set()
    for t in all_text:
        refs |= set(re.findall(r"\b(?:f_|g\d_|ev_)[0-9A-F]{8}\b", t))
    decls = ["/* generated */", "#pragma once", '#include "psx_rt.h"', ""]
    for s in sorted(refs):
        decls.append(f"void {s}(void);")
    for h in sorted(HLE_OVERRIDES):
        decls.append(f"void hle_{h:08X}(void);")
    (out / f"{mod.lower()}_decls.h").write_text("\n".join(decls) + "\n")

    for ci, text in enumerate(all_text):
        (out / f"{mod.lower()}_{ci:03d}.c").write_text(
            f'#include "{mod.lower()}_decls.h"\n' + ('#include "startup_qol.h"\n' if mod == 'SCPS' else '') + '\n' + text)
    for old in out.glob(f"{mod.lower()}_[0-9][0-9][0-9].c"):
        idx = int(old.stem.split("_")[-1])
        if idx >= len(chunks):
            old.unlink()

    table = ['#include "psx_rt.h"', f'#include "{mod.lower()}_decls.h"', "",
             f"const psx_func_entry {mod.lower()}_table[] = {{"]
    for s in ordered:
        table.append(f"    {{ 0x{s:08X}u, {pfx}{s:08X} }},")
    table.append("};")
    table.append(f"const int {mod.lower()}_table_n = {len(ordered)};")
    (out / f"{mod.lower()}_table.c").write_text("\n".join(table) + "\n")

    print(f"{mod}: {len(results)} translated, {len(failed)} trap stubs, "
          f"{len(chunks)} chunks")
    return 0


if __name__ == "__main__":
    main(sys.argv[1] if len(sys.argv) > 1 else "SCPS",
         sys.argv[2] if len(sys.argv) > 2 else
         str(Path(__file__).resolve().parents[1] / "gen"))
