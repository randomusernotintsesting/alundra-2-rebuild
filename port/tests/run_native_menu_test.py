"""Exercise real macOS menu controls with synthetic, owned profile fixtures."""
import argparse
import struct
import shutil
import subprocess
import tempfile
from pathlib import Path

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("binary", type=Path)
parser.add_argument("output", type=Path)
args = parser.parse_args()
args.output.mkdir(parents=True, exist_ok=True)
with tempfile.TemporaryDirectory(prefix="alundra2-menu-test-") as directory:
    root = Path(directory) / "game-data"
    branding = root.parent / "branding"
    branding.mkdir()
    shutil.copy2(Path(__file__).resolve().parents[1] / "assets/branding/alundra2-hd-black.png",
                 branding / "alundra2-hd-black.png")
    for language in ("ru", "ja", "en"):
        disc = root / "profiles" / language / "disc"
        disc.mkdir(parents=True)
        exe = bytearray(0x46800)
        exe[:8] = b"PS-X EXE"
        struct.pack_into("<I", exe, 0x10, 0x80039BFC)
        struct.pack_into("<II", exe, 0x18, 0x80017000, 0x46000)
        (disc / "SCPS_101.15").write_bytes(exe)
        (disc.parent / "disc.bin").write_bytes(b"owned menu fixture")
    voice = root / "voices" / "en"
    voice.mkdir(parents=True)
    metadata = 32 + 183 * 64
    pack = bytearray(metadata + 2352)
    pack[:8] = b"A2VOICE1"
    struct.pack_into("<6I", pack, 8, 1, 183, 1, 1, 1, metadata)
    struct.pack_into("<I", pack, 32 + 48, 1)
    (voice / "voices.a2v").write_bytes(pack)
    japanese = root / "voices" / "ja"
    japanese.mkdir(parents=True)
    for index in range(183):
        struct.pack_into("<I", pack, 32 + index * 64 + 48, 3)
    (japanese / "voices.a2v").write_bytes(pack)
    raise SystemExit(subprocess.run(
        [str(args.binary.resolve()), str(root), str(args.output.resolve())], timeout=30
    ).returncode)
