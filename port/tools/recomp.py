"""MIPS R3000A -> C static recompiler.

v2: full integer ISA + cop0/cop2 hooks, jalr / jr-via-jump-table,
bltzal/bgezal, fallthrough into the next function, and batch mode with
synthetic splits for cross-function branch targets.

Model: registers/HI/LO live in globals (psx_rt.h); every recompiled
function is `void f_<addr>(void)`. Calls: direct jal -> direct C call
(or extern hle_<addr> if the target is in the HLE override set);
indirect (jalr / jr to a function) -> psx_call(addr) runtime dispatch.
Branch delay slots: condition is evaluated into a temp BEFORE the slot.

Verified by port/tests/run_tests.py (golden RLE decoder tests).
"""
import struct

from modules import load

REG = [f"R[{i}]" for i in range(32)]


class Insn:
    def __init__(self, addr, word):
        self.addr, self.w = addr, word
        self.op = word >> 26
        self.rs = (word >> 21) & 31
        self.rt = (word >> 16) & 31
        self.rd = (word >> 11) & 31
        self.sa = (word >> 6) & 31
        self.fn = word & 0x3F
        self.imm = word & 0xFFFF
        self.simm = self.imm - 0x10000 if self.imm & 0x8000 else self.imm
        self.target = ((addr + 4) & 0xF0000000) | ((word & 0x03FFFFFF) << 2)
        self.btarget = addr + 4 + (self.simm << 2)

    @property
    def is_branch(self):
        if self.op in (2, 3, 4, 5, 6, 7):
            return True
        if self.op == 1 and self.rt in (0, 1, 16, 17):
            return True
        if self.op == 0 and self.fn in (8, 9):
            return True
        return False

    @property
    def writes_ra_link(self):
        return self.op == 3 or (self.op == 1 and self.rt in (16, 17)) or \
            (self.op == 0 and self.fn == 9 and self.rd == 31)


def set_reg(rd, expr):
    if rd == 0:
        return f"(void)({expr});"
    return f"{REG[rd]} = {expr};"


def plain_stmt(i):
    """C statement for a non-branch instruction (None for nop)."""
    rs, rt, rd, sa = REG[i.rs], REG[i.rt], REG[i.rd], i.sa
    simm, imm = i.simm, i.imm
    op, fn = i.op, i.fn
    if i.w == 0:
        return None
    if op == 0:
        if fn == 0x00: return set_reg(i.rd, f"{rt} << {sa}")
        if fn == 0x02: return set_reg(i.rd, f"{rt} >> {sa}")
        if fn == 0x03: return set_reg(i.rd, f"(uint32_t)((int32_t){rt} >> {sa})")
        if fn == 0x04: return set_reg(i.rd, f"{rt} << ({rs} & 31)")
        if fn == 0x06: return set_reg(i.rd, f"{rt} >> ({rs} & 31)")
        if fn == 0x07: return set_reg(i.rd, f"(uint32_t)((int32_t){rt} >> ({rs} & 31))")
        if fn == 0x0C: return f"psx_syscall_at(0x{i.addr:08X}u);"
        if fn == 0x0D: return f"psx_break({(i.w >> 6) & 0xFFFFF});"
        if fn == 0x10: return set_reg(i.rd, "HI")
        if fn == 0x11: return f"HI = {rs};"
        if fn == 0x12: return set_reg(i.rd, "LO")
        if fn == 0x13: return f"LO = {rs};"
        if fn == 0x18: return (f"{{ int64_t _p = (int64_t)(int32_t){rs} * (int32_t){rt}; "
                               f"LO = (uint32_t)_p; HI = (uint32_t)((uint64_t)_p >> 32); }}")
        if fn == 0x19: return (f"{{ uint64_t _p = (uint64_t){rs} * {rt}; "
                               f"LO = (uint32_t)_p; HI = (uint32_t)(_p >> 32); }}")
        if fn == 0x1A: return f"psx_div((int32_t){rs}, (int32_t){rt});"
        if fn == 0x1B: return f"psx_divu({rs}, {rt});"
        if fn in (0x20, 0x21): return set_reg(i.rd, f"{rs} + {rt}")
        if fn in (0x22, 0x23): return set_reg(i.rd, f"{rs} - {rt}")
        if fn == 0x24: return set_reg(i.rd, f"{rs} & {rt}")
        if fn == 0x25: return set_reg(i.rd, f"{rs} | {rt}")
        if fn == 0x26: return set_reg(i.rd, f"{rs} ^ {rt}")
        if fn == 0x27: return set_reg(i.rd, f"~({rs} | {rt})")
        if fn == 0x2A: return set_reg(i.rd, f"((int32_t){rs} < (int32_t){rt})")
        if fn == 0x2B: return set_reg(i.rd, f"({rs} < {rt})")
    if op in (8, 9):  return set_reg(i.rt, f"{rs} + {simm}" if simm >= 0 else f"{rs} - {-simm}")
    if op == 10: return set_reg(i.rt, f"((int32_t){rs} < {simm})")
    if op == 11: return set_reg(i.rt, f"({rs} < (uint32_t){simm}u)")
    if op == 12: return set_reg(i.rt, f"{rs} & 0x{imm:X}")
    if op == 13: return set_reg(i.rt, f"{rs} | 0x{imm:X}")
    if op == 14: return set_reg(i.rt, f"{rs} ^ 0x{imm:X}")
    if op == 15: return set_reg(i.rt, f"0x{imm:X}u << 16")
    if op == 16:  # cop0
        if i.rs == 0: return set_reg(i.rt, f"psx_cop0_read({i.rd})")
        if i.rs == 4: return f"psx_cop0_write({i.rd}, {rt});"
        if i.rs == 16 and i.fn == 16: return "psx_rfe();"
    if op == 18:  # cop2 / GTE
        if i.w & (1 << 25): return f"gte_cmd(0x{i.w & 0x1FFFFFF:X}u);"
        if i.rs == 0: return set_reg(i.rt, f"gte_data_read({i.rd})")
        if i.rs == 2: return set_reg(i.rt, f"gte_ctrl_read({i.rd})")
        if i.rs == 4: return f"gte_data_write({i.rd}, {rt});"
        if i.rs == 6: return f"gte_ctrl_write({i.rd}, {rt});"
    ea = f"{REG[i.rs]} + {simm}" if simm else REG[i.rs]
    if op == 32: return set_reg(i.rt, f"(uint32_t)(int8_t)lb_({ea})")
    if op == 33: return set_reg(i.rt, f"(uint32_t)(int16_t)lh_({ea})")
    if op == 34: return set_reg(i.rt, f"lwl_({ea}, {REG[i.rt]})")
    if op == 35: return set_reg(i.rt, f"lw_({ea})")
    if op == 36: return set_reg(i.rt, f"lb_({ea})")
    if op == 37: return set_reg(i.rt, f"lh_({ea})")
    if op == 38: return set_reg(i.rt, f"lwr_({ea}, {REG[i.rt]})")
    if op == 40: return f"sb_({ea}, {REG[i.rt]});"
    if op == 41: return f"sh_({ea}, {REG[i.rt]});"
    if op == 42: return f"swl_({ea}, {REG[i.rt]});"
    if op == 43: return f"sw_({ea}, {REG[i.rt]});"
    if op == 46: return f"swr_({ea}, {REG[i.rt]});"
    if op == 50: return f"gte_data_write({i.rt}, lw_({ea}));"   # lwc2
    if op == 58: return f"sw_({ea}, gte_data_read({i.rt}));"    # swc2
    raise NotImplementedError(
        f"0x{i.addr:08X}: unsupported word 0x{i.w:08X} (op={op}, fn={fn})")


def branch_cond(i):
    rs, rt = REG[i.rs], REG[i.rt]
    if i.op == 4: return f"{rs} == {rt}"
    if i.op == 5: return f"{rs} != {rt}"
    if i.op == 6: return f"(int32_t){rs} <= 0"
    if i.op == 7: return f"(int32_t){rs} > 0"
    if i.op == 1 and i.rt in (0, 16): return f"(int32_t){rs} < 0"
    if i.op == 1 and i.rt in (1, 17): return f"(int32_t){rs} >= 0"
    raise NotImplementedError(f"0x{i.addr:08X}: branch op={i.op} rt={i.rt}")


def find_jump_table(insns, jr_addr, rs, data, base, lo, hi):
    """Recover a switch jump table feeding `jr $rs` at jr_addr.

    Pattern (gcc 2.x / PSY-Q): lw $rs, off($t) where $t = table_base
    (+ scaled index), table base built by lui/addiu. We scan back a few
    instructions for `lw rs` then for the lui/addiu pair of its base reg.
    Table entries: consecutive words that are valid code addresses.
    """
    lw = None
    for a in range(jr_addr - 4, jr_addr - 40, -4):
        i = insns.get(a)
        if i is None:
            break
        if i.op == 35 and i.rt == rs:       # lw rs, off(base)
            lw = i
            break
        if i.is_branch:
            break
    if lw is None:
        return None
    base_reg = lw.rs
    hi16 = lo16 = None
    addu_srcs = None
    for a in range(lw.addr - 4, lw.addr - 56, -4):
        i = insns.get(a)
        if i is None:
            break
        if i.op == 9 and i.rt == base_reg and lo16 is None and addu_srcs is None:
            lo16 = i.simm                                  # addiu base, x, lo
            base_reg2 = i.rs
        elif i.op == 13 and i.rt == base_reg and lo16 is None and addu_srcs is None:
            lo16 = i.imm                                   # ori base, x, lo
            base_reg2 = i.rs
        elif (i.op == 0 and i.fn == 0x21 and i.rd == base_reg
              and addu_srcs is None and lo16 is None):
            addu_srcs = (i.rs, i.rt)                       # addu base, X, idx
        elif i.op == 15:                                   # lui
            if lo16 is not None and i.rt == base_reg2:
                hi16 = i.imm
                break
            if addu_srcs and i.rt in addu_srcs:
                hi16 = i.imm
                lo16 = 0
                break
    if hi16 is None or lo16 is None:
        return None
    table = ((hi16 << 16) + lo16 + lw.simm) & 0xFFFFFFFF
    entries = []
    off = table - base
    if off < 0 or off >= len(data):
        return None
    while off + 4 <= len(data) and len(entries) < 512:
        w = struct.unpack_from("<I", data, off)[0]
        if not (lo <= w < hi) or w & 3:
            break
        entries.append(w)
        off += 4
    return (table, entries) if len(entries) >= 2 else None


class FuncResult:
    def __init__(self, name, code, callees_direct, callees_hle,
                 extern_branches, uses):
        self.name = name
        self.code = code
        self.callees_direct = callees_direct  # f_xxx addresses
        self.callees_hle = callees_hle        # hle_xxx addresses
        self.extern_branches = extern_branches  # synthetic split targets
        self.uses = uses                      # set of feature strings


def recompile_one(module_data, base, lo, hi, start, end,
                  hle=frozenset(), name=None):
    """Recompile [start,end). Returns FuncResult.

    `hle`: addresses whose calls become extern hle_<addr>().
    Branches leaving [start,end) become tail-calls psx_call (and are
    reported in extern_branches so the batch driver can emit them).
    """
    data = module_data
    # if the advisory boundary cuts between a branch and its delay slot,
    # extend the range by one instruction (functions may overlap freely)
    if end - 4 >= start and end - base + 4 <= len(data):
        last = Insn(end - 4, struct.unpack_from("<I", data, end - 4 - base)[0])
        if last.is_branch:
            end += 4
    insns = {}
    for ram in range(start, end, 4):
        insns[ram] = Insn(ram, struct.unpack_from("<I", data, ram - base)[0])

    labels, delay_addrs = set(), set()
    jump_tables = {}
    extern_branches = set()
    callees_direct, callees_hle = set(), set()
    uses = set()

    for a, i in insns.items():
        if not i.is_branch:
            continue
        delay_addrs.add(a + 4)
        if i.op in (4, 5, 6, 7, 1):
            if start <= i.btarget < end:
                labels.add(i.btarget)
            else:
                extern_branches.add(i.btarget)
        elif i.op == 2:
            if start <= i.target < end:
                labels.add(i.target)
            else:
                extern_branches.add(i.target)
        elif i.op == 3:
            (callees_hle if i.target in hle else callees_direct).add(i.target)
        elif i.op == 0 and i.fn == 8 and i.rs != 31:
            jt = find_jump_table(insns, a, i.rs, data, base, lo, hi)
            if jt:
                jump_tables[a] = jt
                for t in jt[1]:
                    if start <= t < end:
                        labels.add(t)
                    else:
                        extern_branches.add(t)
            else:
                uses.add("indirect_jr")

    # a branch that targets a delay slot: force the slot to be addressable
    # by treating the branch as NOT consuming it (rare; handled by trap)
    clash = labels & delay_addrs
    if clash:
        raise NotImplementedError(
            f"branch into delay slot: {[hex(x) for x in sorted(clash)]}")

    fname = name or f"f_{start:08X}"
    out = [f"void {fname}(void) {{"]

    def emit_extern_jump(tgt, comment):
        extern_branches.add(tgt)
        out.append(f"    {{ ef_{tgt:08X}(); return; }}  /* {comment} */")

    skip = set()
    last_was_terminal = False
    for a in sorted(insns):
        if a in skip:
            continue
        i = insns[a]
        if a in labels:
            out.append(f"L_{a:08X}:;")
        last_was_terminal = False
        if not i.is_branch:
            s = plain_stmt(i)
            if s:
                out.append(f"    {s}  /* 0x{a:08X} */")
            continue
        d = insns.get(a + 4)
        if d is None or d.is_branch:
            raise NotImplementedError(f"bad delay slot at 0x{a:08X}")
        skip.add(a + 4)
        ds = plain_stmt(d)
        ds = f" {ds}" if ds else ""
        if i.op == 2:  # j
            if start <= i.target < end:
                bb = " psx_bb();" if i.target <= a else ""
                out.append(f"    {{{ds}{bb} goto L_{i.target:08X}; }}  /* 0x{a:08X} j */")
            else:
                out.append(f"    {{{ds} psx_next = 0x{i.target:08X}u; "
                           f"return; }}  /* 0x{a:08X} j extern */")
            last_was_terminal = True
        elif i.op == 3:  # jal — flat model: park target, dispatcher runs it;
            # the return site (a+8) is its own emitted segment
            out.append(f"    {{ R[31] = 0x{a + 8:08X}u;{ds} "
                       f"psx_next = 0x{i.target:08X}u; return; }}"
                       f"  /* 0x{a:08X} jal */")
            last_was_terminal = True
        elif i.op == 0 and i.fn == 8:  # jr
            if i.rs == 31:
                out.append(f"    {{{ds} psx_next = R[31]; return; }}"
                           f"  /* 0x{a:08X} jr ra */")
                last_was_terminal = True
            elif a in jump_tables:
                table, entries = jump_tables[a]
                out.append(f"    {{ uint32_t _t = {REG[i.rs]};{ds} "
                           f"switch (_t) {{  /* 0x{a:08X} jr table@0x{table:08X} */")
                seen = set()
                for t in entries:
                    if t in seen:
                        continue
                    seen.add(t)
                    if start <= t < end:
                        out.append(f"        case 0x{t:08X}u: goto L_{t:08X};")
                out.append(f"        default: psx_next = _t; return;")
                out.append(f"    }} }}")
                last_was_terminal = True
            else:
                out.append(f"    {{ uint32_t _t = {REG[i.rs]};{ds} "
                           f"psx_next = _t; return; }}  /* 0x{a:08X} jr indirect */")
                last_was_terminal = True
                uses.add("indirect_jr")
        elif i.op == 0 and i.fn == 9:  # jalr
            link = set_reg(i.rd, f"0x{a + 8:08X}u")
            out.append(f"    {{ uint32_t _t = {REG[i.rs]}; {link}{ds} "
                       f"psx_next = _t; return; }}  /* 0x{a:08X} jalr */")
            last_was_terminal = True
            uses.add("jalr")
        elif i.op == 1 and i.rt in (16, 17):  # bltzal/bgezal
            cond = branch_cond(i)
            tgt = i.btarget
            out.append(f"    {{ uint32_t _c = ({cond}); R[31] = 0x{a + 8:08X}u;"
                       f"{ds} if (_c) {{ psx_next = 0x{tgt:08X}u; return; }} }}"
                       f"  /* 0x{a:08X} b*al */")
        else:
            cond = branch_cond(i)
            if start <= i.btarget < end:
                bb = " psx_bb();" if i.btarget <= a else ""
                out.append(f"    {{ uint32_t _c = ({cond});{ds} "
                           f"if (_c) {{{bb} goto L_{i.btarget:08X}; }} }}  /* 0x{a:08X} */")
            else:
                out.append(f"    {{ uint32_t _c = ({cond});{ds} "
                           f"if (_c) {{ psx_next = 0x{i.btarget:08X}u; "
                           f"return; }} }}  /* 0x{a:08X} b extern */")

    if not last_was_terminal:
        # fell off the end: continue into the next function
        out.append(f"    psx_next = 0x{end:08X}u; return;  /* fallthrough */")
        extern_branches.add(end)
    out.append("}")
    return FuncResult(fname, "\n".join(out), callees_direct, callees_hle,
                      extern_branches, uses)


def recompile(module, start, end, known=frozenset(), name=None):
    """Single-function wrapper for tests: emits the function plus all its
    internal call-return-site segments and a dispatch table over them."""
    import struct as _s
    data, base, _ = load(module)
    entries = {start}
    for ram in range(start, end, 4):
        w = _s.unpack_from("<I", data, ram - base)[0]
        op = w >> 26
        if (op == 3 or (op == 1 and ((w >> 16) & 31) in (16, 17)) or
                (op == 0 and (w & 0x3F) == 9)):
            if start <= ram + 8 < end:
                entries.add(ram + 8)
    parts, externs = [], set()
    for s in sorted(entries):
        r = recompile_one(data, base, 0x80010000, 0x80200000, s, end,
                          hle=frozenset(), name=f"f_{s:08X}")
        parts.append(r.code)
        externs |= r.callees_direct
    header = ["/* generated by recomp.py — do not edit */",
              '#include "psx_rt.h"', ""]
    for s in sorted(entries):
        header.append(f"void f_{s:08X}(void);")
    table = ["", "const psx_func_entry test_table[] = {"]
    for s in sorted(entries):
        table.append(f"    {{ 0x{s:08X}u, f_{s:08X} }},")
    table.append("};")
    table.append(f"const int test_table_n = {len(entries)};")
    return ("\n".join(header) + "\n" + "\n\n".join(parts)
            + "\n".join(table) + "\n")


if __name__ == "__main__":
    import sys
    mod, s, e = sys.argv[1], int(sys.argv[2], 16), int(sys.argv[3], 16)
    print(recompile(mod, s, e))
