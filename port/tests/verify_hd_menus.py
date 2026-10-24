"""Capture real HD menu states with ordinary inputs and isolated saves.

This is a diagnostic driver, not a claim of visual acceptance. Inspect the
exported frames. Each invocation freezes its binary in a fresh directory.
"""
import argparse
import hashlib
import json
import shutil
import struct
import subprocess
import sys
import time
from pathlib import Path

from PIL import Image
from replay_full_menu_v3 import POST
from verify_pocket_chest import pocket_chest_taps

ROOT = Path(__file__).resolve().parents[2]


def route(name):
    if name == "load":
        return "continue", ["4200:13:4"], [4000, 4400]
    if name in ("settings", "font-options", "settings-controls", "menu-return"):
        taps = ["4700:3:4", "5000:5:4", "5200:5:4", "5400:13:4",
                "5800:7:4", "6000:13:4"]
        if name == "settings":
            return "new", taps, [6400]
        if name == "menu-return":
            taps += ["6600:14:4", "6800:5:4", "7000:5:4", "7200:13:4",
                     "7800:14:4", "8200:14:4", "8600:3:4", "9300:5:400"]
            return "new", taps, [6400, 7600, 9200, 10000]
        if name == "settings-controls":
            taps += ["6600:14:4", "6800:5:4", "7000:5:4", "7200:13:4",
                     "7800:14:4", "8000:3:4", "8300:5:700"]
            return "new", taps, [6400, 7600, 8800]
        # Apply2, apply1, then propose2 and cancel. No config/RAM injection.
        taps += ["6600:5:4", "6900:13:4", "7300:13:4", "7700:7:4",
                 "8000:13:4", "8400:13:4", "8800:5:4", "9100:14:4", "9500:13:4"]
        return "new", taps, [6400, 6750, 7150, 7550, 8150, 8650, 8950, 9350, 9750]
    if name == "dialogue":
        return "new", ["4800:5:700"], [5300]
    taps = [x for x in pocket_chest_taps() if int(x.split(":")[0]) < 19000] + POST
    return "new", taps, [19000, 19300, 19900, 21300, 21800, 22300, 23600]


def shift_route(taps,frames,offset):
    shifted=[]
    for tap in taps:
        first,rest=tap.split(':',1)
        frame=int(first)+offset
        if frame<=0:raise ValueError('route offset places input before boot')
        shifted.append(f'{frame}:{rest}')
    actual=[frame+offset for frame in frames]
    if any(frame<=0 for frame in actual):raise ValueError('capture before boot')
    return shifted,actual


def verify_menu_return(captures):
    by_frame = {capture.get("route_frame",capture["frame"]): capture for capture in captures}
    before, after = by_frame[9200], by_frame[10000]
    assert before["flags"] == 0, before
    for capture in (before, after):
        assert tuple(capture["raw_size"]) == (960, 720), capture
    assert before["position"] != after["position"], (before, after)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--binary", type=Path, default=ROOT / "port/build/alundra2")
    parser.add_argument("--data", type=Path, default=ROOT / "port/build/verification/full-menu-v5")
    parser.add_argument("--route", choices=("load", "settings", "font-options", "settings-controls", "menu-return", "dialogue", "chest"), required=True)
    parser.add_argument("--hd-ui", choices=(0, 1), type=int, default=1)
    parser.add_argument("--frame-offset", type=int, default=0,
                        help="Measured offset for old routes after startup timing changes")
    args = parser.parse_args()
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=False)
    binary = out / "alundra2"
    shutil.copy2(args.binary, binary)
    auto, taps, frames = route(args.route)
    route_frames=frames
    taps,frames=shift_route(taps,frames,args.frame_offset)
    control = out / "control.txt"
    control.write_text(f"{frames[0]}\n")
    command = [sys.executable, str(ROOT / "port/tools/replay.py"), "--binary", str(binary),
               "--disc", str(args.data.resolve() / "disc"), "--image", str(args.data.resolve() / "disc.bin"),
               "--output", str(out / "replay"), "--auto", auto, "--frames", str(frames[-1] + 50),
               "--every", "0", "--timeout", "900", "--ir-scale", "3", "--hd-ui", str(args.hd_ui),
               "--control-file", str(control)]
    for tap in taps:
        command += ["--tap", tap]
    manifest = {"binary_sha256": hashlib.sha256(binary.read_bytes()).hexdigest(),
                "route": args.route, "command": command, "captures": []}
    process = subprocess.Popen(command)
    deadline = time.monotonic() + 910
    try:
        for index, frame in enumerate(frames):
            user = out / "replay/user"
            vram = user / f"vram_{frame:05}.bin"
            # VRAM is written last; do not resume while RAM/BMP is incomplete.
            while not vram.exists() or vram.stat().st_size != 1024 * 512 * 2:
                if process.poll() is not None:
                    raise RuntimeError(f"Replay exited before frame {frame}: {process.returncode}")
                if time.monotonic() > deadline:
                    raise TimeoutError(f"No capture at frame {frame}")
                time.sleep(0.1)
            picture = Image.open(user / f"frame_{frame:05}.bmp").convert("RGB")
            assert picture.size in ((960, 720), (960, 1440)), picture.size
            picture.save(out / f"{frame:05}-raw.png")
            size = (1920, 1440) if picture.height == 1440 else picture.size
            # Display-aspect correction only; no letter repainting/upscaler.
            picture.resize(size, Image.Resampling.NEAREST).save(out / f"{frame:05}-4x3.png")
            ram = (user / f"ram_{frame:05}.bin").read_bytes()
            assert len(ram) == 0x200000
            capture = {"frame": frame, "route_frame": route_frames[index],
                       "raw_size": picture.size, "display_size": size}
            if args.route == "menu-return":
                capture["flags"] = struct.unpack_from("<I", ram, 0xF6220)[0]
                capture["position"] = [value >> 12 for value in struct.unpack_from("<iii", ram, 0x119728)]
            if args.route == "font-options":
                capture["font_option_saved"] = struct.unpack_from("<H", ram, 0x633A2)[0]
                capture["font_option_pending"] = struct.unpack_from("<H", ram, 0x143A10)[0]
            manifest["captures"].append(capture)
            print(f"Captured real {args.route} frame {frame}", flush=True)
            next_frame = frames[index + 1] if index + 1 < len(frames) else frames[-1] + 51
            temporary = control.with_suffix(".next")
            temporary.write_text(f"{next_frame}\n")
            temporary.replace(control)
        result = process.wait(timeout=max(1, deadline - time.monotonic()))
        manifest["exit_code"] = result
        (out / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")
        if result:
            raise RuntimeError(f"Replay failed: {result}")
        if args.route == "menu-return":
            verify_menu_return(manifest["captures"])
            print("Verified nested menu return to 240-line gameplay and ordinary movement", flush=True)
        if args.route == "font-options":
            actual = [c["font_option_saved"] for c in manifest["captures"]]
            assert actual == [0, 0, 1, 1, 0, 0, 0, 0, 0], actual
            print("Verified real Circle apply2/apply1 and Cross cancel2", flush=True)
    finally:
        if process.poll() is None:
            process.terminate()
            process.wait(timeout=5)


if __name__ == "__main__":
    main()
