"""Pilot recompiler end-to-end test.

1. Recompile the RLE decoder (SCPS 0x8001C26C..0x8001C554) to C.
2. Golden vectors:
   a. real game data: resident ASCII atlas container @SCPS file 0x395D8
      (chunks decoded with the verified reference a2rle.py)
   b. 200 deterministic synthetic streams (all 4 token forms)
3. Build with cc, run, compare byte-for-byte.
"""
import random
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
PORT = HERE.parent
ROOT = PORT.parent
sys.path.insert(0, str(PORT / "tools"))
sys.path.insert(0, str(ROOT / "tools" / "analysis" / "font-hunt"))

from recomp import recompile          # noqa: E402
from a2rle import decompress          # noqa: E402
from modules import load              # noqa: E402

BUILD = HERE / "build"
FUNC = (0x8001C26C, 0x8001C554)
ATLAS_OFF = 0x395D8


def container_chunks(data, off):
    nch, npal = struct.unpack_from("<II", data, off)
    sizes = struct.unpack_from("<10I", data, off + 12)
    pos = off + 52 + npal * 512
    out = []
    for i in range(nch):
        out.append(data[pos:pos + sizes[i]])
        pos += sizes[i]
    return out


def synth_stream(rng):
    """Random valid RLE stream exercising all 4 token forms."""
    stream, golden = bytearray(), bytearray()
    for _ in range(rng.randrange(1, 30)):
        form = rng.randrange(4)
        if form == 0:    # short literal (1..64)
            ln = rng.randrange(1, 65)
            lit = bytes(rng.randrange(256) for _ in range(ln))
            stream.append(ln - 1); stream += lit; golden += lit
        elif form == 1:  # long literal (1..16384)
            ln = rng.randrange(1, 1000)
            lit = bytes(rng.randrange(256) for _ in range(ln))
            stream.append(0x40 | ((ln - 1) >> 8)); stream.append((ln - 1) & 0xFF)
            stream += lit; golden += lit
        elif form == 2:  # short run
            ln = rng.randrange(1, 65); v = rng.randrange(256)
            stream.append(0x80 | (ln - 1)); stream.append(v)
            golden += bytes([v]) * ln
        else:            # long run
            ln = rng.randrange(1, 5000); v = rng.randrange(256)
            stream.append(0xC0 | ((ln - 1) >> 8)); stream.append((ln - 1) & 0xFF)
            stream.append(v); golden += bytes([v]) * ln
    return bytes(stream), bytes(golden)


def main():
    BUILD.mkdir(exist_ok=True)

    # 1. generate C
    gen = BUILD / "rle_decode.gen.c"
    gen.write_text(recompile("SCPS", *FUNC))
    print(f"generated {gen.name} ({len(gen.read_text().splitlines())} lines)")

    # 2. build
    exe = BUILD / "test_rle"
    subprocess.run(
        ["cc", "-O1", "-Wall", f"-I{PORT/'src'}",
         str(gen), str(HERE / "test_rle.c"), "-o", str(exe)],
        check=True)

    cases = []

    # 3a. real container chunks
    data, _, _ = load("SCPS")
    for i, stream in enumerate(container_chunks(data, ATLAS_OFF)):
        golden, used = decompress(stream)
        assert used == len(stream), "reference did not consume full stream"
        cases.append((f"atlas_chunk{i}", stream, golden))

    # 3b. synthetic fuzz
    rng = random.Random(0xA2A2)
    for i in range(200):
        stream, golden = synth_stream(rng)
        ref, _ = decompress(stream)
        assert ref == golden, "synthetic encoder is wrong"
        cases.append((f"synth{i:03d}", stream, golden))

    # 4. run
    failed = 0
    for name, stream, golden in cases:
        s, g = BUILD / f"{name}.bin", BUILD / f"{name}.gold"
        s.write_bytes(stream); g.write_bytes(golden)
        r = subprocess.run([str(exe), str(s), str(g)], capture_output=True, text=True)
        if r.returncode != 0:
            failed += 1
            print(f"FAIL {name}: {r.stderr.strip() or r.stdout.strip()}")
    total = len(cases)
    print(f"{total - failed}/{total} passed "
          f"({len(cases) - 200} real game vectors, 200 synthetic)")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
