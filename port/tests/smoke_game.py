"""Bounded, reproducible boot-to-gameplay check using the user's local disc.

Writes isolated cards/settings and evidence into --output (never real saves).
This exercises the prologue; it does not certify full-game completability.
"""
import argparse
import os
from pathlib import Path
import re
import subprocess
import sys


def main():
    port = Path(__file__).resolve().parents[1]
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--binary", type=Path, default=port / "build/alundra2")
    ap.add_argument("--output", type=Path, required=True)
    ap.add_argument("--frames", type=int, default=12000)
    ap.add_argument("--timeout", type=int, default=180)
    ap.add_argument("--natural-intro", action="store_true")
    args = ap.parse_args()
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=True)
    env = {k: v for k, v in os.environ.items() if not k.startswith("A2_")}
    env.update(SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy",
               A2_USER_DIR=str(out / "user"), A2_FAST="1", A2_IRSCALE="1",
               A2_WIDE="0", A2_SOUND="0", A2_AUTO="1", A2_PLAY="1",
               A2_MAXFRAMES=str(args.frames), A2_TIMEOUT=str(args.timeout),
               A2_STATELOG="1", A2_SHOTS="1", A2_SHOTEVERY="1000",
               A2_SHOTDIR=str(out))
    if not args.natural_intro:
        env["A2_SKIP"] = "1"
    command = [str(args.binary.resolve()), str(port.parent / "disc_jp"),
               "--boot", str(port.parent / "build/alundra2_jp.bin")]
    with (out / "run.log").open("w") as log:
        try:
            run = subprocess.run(command, env=env, cwd=out, stdout=log,
                                 stderr=subprocess.STDOUT, timeout=args.timeout + 10)
        except subprocess.TimeoutExpired:
            print(f"FAIL: game stopped progressing; see {out / 'run.log'}")
            return 1
    text = (out / "run.log").read_text(errors="replace")
    errors = []
    if run.returncode != 0:
        errors.append(f"exit code {run.returncode}")
    if f"frame limit reached ({args.frames} frames)" not in text:
        errors.append("frame target not reached")
    states = re.findall(r"state: frame=(\d+) overlay=4 map=(\S+) pos=(-?\d+),(-?\d+),(-?\d+) flags=([0-9A-F]+)", text)
    blocked = next((s for s in states if s[1] == "a09_" and int(s[5], 16) & 0x10), None)
    released = next((s for s in states if blocked and s[1] == "a09_" and
                     int(s[0]) > int(blocked[0]) and not int(s[5], 16) & 0x10), None)
    if not released:
        errors.append("prologue cinematic did not release player control")
    after_intro = int(released[0]) + 600 if released else args.frames
    active = [s for s in states if s[1].startswith("a") and
              int(s[0]) > after_intro and not int(s[5], 16) & 0x10]
    if len({tuple(s[2:5]) for s in active}) < 3:
        errors.append("player motion after the intro not observed")
    if not list(out.glob("shot_*.bmp")):
        errors.append("no frame captures")
    for card in (out / "user").glob("memcard*.mcr"):
        if card.stat().st_size != 128 * 1024:
            errors.append(f"invalid card size: {card.name}")
    if len(list((out / "user").glob("memcard*.mcr"))) != 2:
        errors.append("two persistent memory cards not initialized")
    if errors:
        print("FAIL: " + "; ".join(errors))
        print(out / "run.log")
        return 1
    print(f"PASS: {args.frames} frames; cinematic completed; player moves; two cards; captures in {out}")
    print("Observed gameplay maps:", ", ".join(sorted({s[1] for s in active})))
    return 0


if __name__ == "__main__":
    sys.exit(main())
