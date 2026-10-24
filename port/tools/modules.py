"""Load maps for Alundra 2 JP (SCPS-101.15) executables.

SCPS: header t_addr=0x80017000, code at file 0x800 => RAM = 0x80016800
+ file_off.  Overlays (JP!): ALL load at 0x800811D8, entire file incl.
the 4-byte ID word (GAME00=4 EVENT00=5 GAME01=6 GAME02=7 GAME03=8);
derived from the overlay dispatch table at SCPS RAM 0x8004F9A0 (pairs of
name-ptr/entry: EVENT00 0x800842C0, GAME00 0x80085D60/0x80085A78/
0x80085ADC, GAME01 0x80081498, GAME02 0x8008148C, GAME03 0x800813E4) —
0x800811D8 is the unique base putting every entry on a prologue in its
file.  (US base 0x80084A98 does NOT apply to JP.)
"""
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
DISC = ROOT / "disc_jp"

OVERLAY_BASE = 0x800811D8

MODULES = {
    # name: (path, ram_base_for_file_offset_0, code_start_file_offset)
    "SCPS":    (DISC / "SCPS_101.15", 0x80016800, 0x800),
    "GAME00":  (DISC / "GAME00.BIN",  OVERLAY_BASE, 4),
    "GAME01":  (DISC / "GAME01.BIN",  OVERLAY_BASE, 4),
    "GAME02":  (DISC / "GAME02.BIN",  OVERLAY_BASE, 4),
    "GAME03":  (DISC / "GAME03.BIN",  OVERLAY_BASE, 4),
    "EVENT00": (DISC / "EVENT00.BIN", OVERLAY_BASE, 4),
}


def load(name):
    path, base, code_start = MODULES[name]
    data = path.read_bytes()
    return data, base, code_start


def entry_pc(name="SCPS"):
    path, _, _ = MODULES[name]
    hdr = path.read_bytes()[:0x800]
    return struct.unpack_from("<I", hdr, 0x10)[0]
