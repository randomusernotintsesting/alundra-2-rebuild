"""Diagnostic original-game save/Continue replay; never manufactures save data.

Requires the opt-in A2_TEST_SAVE_AT menu-request hook. Output must be new so
the test cannot overwrite user cards or confuse old files with fresh evidence.
"""
import argparse
import os
import struct
from pathlib import Path
import subprocess

port = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--output", type=Path, required=True)
parser.add_argument("--binary", type=Path, default=port / "build/alundra2")
parser.add_argument("--save-at", type=int, default=4600)
parser.add_argument("--save-frames", type=int, default=7600)
parser.add_argument("--load-frames", type=int, default=6600)
parser.add_argument("--timeout", type=int, default=300)
parser.add_argument("--tap", action="append", default=[], help="ordinary gameplay route before saving, frame:bit[:duration]")
parser.add_argument("--save-taps", default="5400:13,5900:13,6400:13,7000:13")
parser.add_argument("--load-taps", default="3800:13,4300:13,4700:4,4800:13")
args = parser.parse_args()
out = args.output.resolve()
out.mkdir(parents=True, exist_ok=False)
(out / "user").mkdir()

def replay(name, auto, frames, taps, save_at=None):
    capture = out / name
    capture.mkdir()
    env = {k: v for k, v in os.environ.items() if not k.startswith("A2_")}
    env.update(SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy", A2_FAST="1",
               A2_USER_DIR=str(out / "user"), A2_IRSCALE="1", A2_WIDE="0",
               A2_SOUND="0", A2_AUTO=str(auto), A2_SKIP="1",
               A2_MAXFRAMES=str(frames), A2_TIMEOUT=str(args.timeout), A2_CARDLOG="1",
               A2_SHOTS="1", A2_SHOTEVERY="500", A2_SHOTDIR=str(capture),
               A2_STATELOG="1", A2_TAP=taps,
               A2_DUMPMEM=f"{frames-100}:0:200000", A2_DUMPOUT=str(capture / "ram.bin"))
    if save_at is not None:
        env["A2_TEST_SAVE_AT"] = str(save_at)
    command = [str(args.binary.resolve()), str(port.parent / "disc_jp"),
               "--boot", str(port.parent / "build/alundra2_jp.bin")]
    with (capture / "run.log").open("w") as log:
        subprocess.run(command, cwd=capture, env=env, stdout=log,
                       stderr=subprocess.STDOUT, timeout=args.timeout+10, check=True)

replay("save", 1, args.save_frames, ",".join(args.tap+[args.save_taps]), args.save_at)
card = (out / "user/memcard1.mcr").read_bytes()
entries = [n for n in range(1, 16) if card[n*128] == 0x51]
assert len(card) == 131072 and entries, "Original game did not create a save"
block = entries[0]
payload = card[block*8192:(block+1)*8192]
assert payload[:4] == b"SC\x11\x01", "Missing original PS1 save header"
checksum = sum(int.from_bytes(payload[i:i+2], "little") for i in range(0, 0xd8c, 2)) & 0xffff
assert checksum == int.from_bytes(payload[0xd8c:0xd8e], "little"), "Original save checksum mismatch"
saved_ram = (out / "save/ram.bin").read_bytes()
allowed = struct.unpack_from("<40h", saved_ram, 0xeef10)
saved_map = struct.unpack_from("<h", payload, 0xc14)[0]
assert saved_map in allowed, f"Map {saved_map} is not an original save location; do not alter the whitelist"
replay("load", 2, args.load_frames, args.load_taps)
loaded_ram = (out / "load/ram.bin").read_bytes()
assert struct.unpack_from("<h", loaded_ram, 0x63e9c)[0] == saved_map, "Saved map was not restored"
assert loaded_ram[0x63ed8:0x63ee4] == payload[0xc50:0xc5c], "Saved position was not restored"
assert struct.unpack_from("<I", loaded_ram, 0x127898)[0] == saved_map, "Continue did not enter the saved scene"
assert loaded_ram[0x1310a0:0x1310a4] != b"\0\0\0\0", "Continue did not return to gameplay"
print("Original serializer/save/ordinary Continue round trip passed:", out)
