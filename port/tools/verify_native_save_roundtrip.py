"""Native checkpoint import/load/move/save/restart/load on an isolated profile.

Never opens the live player profile for writing. Selects a real file at the
semantic native-browser boundary; all scene entry and movement remains guest
code. The save request uses the existing diagnostic original-savepoint hook.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess
import zlib


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def payload(path):
    data = path.read_bytes()
    assert len(data) == 8240 and data[:8] == b"A2SAVE\r\n"
    assert struct.unpack_from("<III", data, 8) == (1, 48, 8192)
    assert data[32:48] == b"SCPS-10115" + b"\0" * 6
    body = data[48:]
    assert zlib.crc32(body) == struct.unpack_from("<I", data, 20)[0]
    assert body[:4] == b"SC\x11\x01"
    assert sum(struct.unpack("<1734H", body[:0xD8C])) & 65535 == struct.unpack_from("<H", body, 0xD8C)[0]
    return body


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ("output", "binary", "disc", "image", "seed-profile"):
        parser.add_argument("--" + name, type=Path, required=True)
    args = parser.parse_args()
    args.output = args.output.resolve()
    args.output.mkdir(parents=True, exist_ok=False)
    user = args.output / "user"
    user.mkdir()
    original_hashes = {}
    for name in ("memcard1.mcr", "memcard2.mcr"):
        source = args.seed_profile / name
        original_hashes[name] = sha(source)
        shutil.copy2(source, user / name)
    card = (user / "memcard1.mcr").read_bytes()
    own = [b for b in range(1, 16) if card[b*128] == 0x51 and card[b*128+10:b*128+24] == b"BISCPS-1011500"]
    assert len(own) == 1, "Provide the known original cabin fixture"
    old = card[own[0]*8192:(own[0]+1)*8192]
    imported = f"card1-BISCPS-1011500-{zlib.crc32(old):08X}.a2save"
    new = "roundtrip-native.a2save"

    def run(name, load_name, saving=False):
        directory = args.output / name
        directory.mkdir()
        env = {k: v for k, v in os.environ.items() if not k.startswith("A2_")}
        env.update(SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy",
                   A2_FAST="1", A2_NATIVE_SAVES="1", A2_USER_DIR=str(user),
                   A2_TEST_NATIVE_LOAD=load_name, A2_IRSCALE="1", A2_HDUI="1",
                   A2_WIDE="0", A2_SOUND="0", A2_AUTO="2", A2_SKIP="1",
                   A2_MAXFRAMES="6100" if saving else "5500", A2_TIMEOUT="150",
                   A2_STATELOG="1", A2_SHOTS="1", A2_SHOTEVERY="500",
                   A2_SHOTDIR=str(directory), A2_DUMPOUT=str(directory / "ram.bin"),
                   A2_DUMPMEM="5900:0:200000" if saving else "4300:0:200000",
                   A2_TAP="4400:6:25" if saving else "4800:4:12")
        if saving:
            env.update(A2_TEST_NATIVE_SAVE=new, A2_TEST_SAVE_AT="5100")
        command = [str(args.binary.resolve()), str(args.disc.resolve()), "--boot", str(args.image.resolve())]
        recorded = {k: v for k, v in env.items() if k.startswith(("A2_", "SDL_"))}
        (directory / "environment.json").write_text(json.dumps({"command": command, "env": recorded}, indent=2))
        with (directory / "run.log").open("w") as log:
            subprocess.run(command, env=env, stdout=log, stderr=subprocess.STDOUT, timeout=160, check=True)
        text = (directory / "run.log").read_text()
        assert "native-save: load result=1 scene=14" in text, text[-2500:]
        assert "VSync: timeout" not in text and "native-save-error:" not in text, text[-2500:]
        if saving:
            assert "native-save: save result=1 scene=14" in text, text[-2500:]
        return (directory / "ram.bin").read_bytes(), text

    saved_ram, saved_log = run("save", imported, True)
    assert payload(user / "Saves" / imported) == old, "Import changed original bytes"
    new_payload = payload(user / "Saves" / new)
    assert new_payload[0xC50:0xC5C] != old[0xC50:0xC5C], "Ordinary movement did not change saved position"
    assert saved_ram[0x626F8:0x63384] == new_payload[0x100:0xD8C]
    loaded_ram, loaded_log = run("reload", new)
    assert loaded_ram[0x626F8:0x63384] == new_payload[0x100:0xD8C], "Full restored backup differs"
    assert loaded_ram[0x119728:0x119734] == new_payload[0xC50:0xC5C], "Actor did not enter saved position"
    assert struct.unpack_from("<h", loaded_ram, 0x12789C)[0] == 14
    assert loaded_ram[0x1310A0:0x1310A3] == b"b30"
    states = re.findall(r"state: frame=(\d+).*pos=(-?\d+),(-?\d+),(-?\d+) flags=0 map_id=14", loaded_log)
    assert states
    initial = tuple(v >> 12 for v in struct.unpack_from("<3i", new_payload, 0xC50))
    final = tuple(map(int, states[-1][1:]))
    assert final != initial, "Ordinary movement after reload did not execute"
    for name, expected in original_hashes.items():
        assert sha(user / name) == expected and sha(args.seed_profile / name) == expected
    result = {"binary_sha256": sha(args.binary), "new_file_sha256": sha(user / "Saves" / new),
              "import_exact": True, "full_checkpoint_restored": True,
              "restored_position_q12": list(struct.unpack_from("<3i", new_payload, 0xC50)),
              "position_after_ordinary_movement": final, "original_cards_unchanged": True}
    (args.output / "result.json").write_text(json.dumps(result, indent=2))
    print(json.dumps(result, indent=2), flush=True)


if __name__ == "__main__":
    main()
