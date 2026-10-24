"""Disassemble a function from a module by RAM address.

Usage: python3 disasm.py SCPS 0x8001C360 [n_words]
"""
import sys
from capstone import Cs, CS_ARCH_MIPS, CS_MODE_MIPS32, CS_MODE_LITTLE_ENDIAN

from modules import load


def disasm(name, ram, count=64):
    data, base, _ = load(name)
    off = ram - base
    md = Cs(CS_ARCH_MIPS, CS_MODE_MIPS32 | CS_MODE_LITTLE_ENDIAN)
    out = []
    code = data[off:off + count * 4]
    for ins in md.disasm(code, ram):
        out.append(f"0x{ins.address:08X}  {ins.mnemonic:8s} {ins.op_str}")
    return out


if __name__ == "__main__":
    name, ram = sys.argv[1], int(sys.argv[2], 16)
    n = int(sys.argv[3]) if len(sys.argv) > 3 else 64
    print("\n".join(disasm(name, ram, n)))
