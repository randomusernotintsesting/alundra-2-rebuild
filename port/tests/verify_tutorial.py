"""Replay ordinary controls through the tutorial and its first room transition.

Uses the user's existing disc; no memory patches, save injection or cheats.
The frame choreography is specific to the current Japanese game build.
"""
import argparse
from pathlib import Path
import re
import subprocess
import sys
from replay_routes import tutorial_taps

port = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--output", type=Path, required=True)
parser.add_argument("--binary", type=Path, default=port / "build/alundra2")
args = parser.parse_args()
out = args.output.resolve()
out.mkdir(parents=True, exist_ok=False)

taps = tutorial_taps()
command = [sys.executable, str(port / "tools/replay.py"),
           "--binary", str(args.binary.resolve()), "--output", str(out),
           "--frames", "18500", "--every", "1000", "--timeout", "300"]
for tap in taps:
    command += ["--tap", tap]
subprocess.run(command, check=True)
log = (out / "run.log").read_text(errors="replace")
if not re.search(r"state: frame=1[78]\d{3} overlay=4 map=b03_ ", log):
    raise SystemExit(f"FAIL: tutorial did not reach the next room; see {out / 'run.log'}")
if "overlay -> EVENT00 (id=5) at frame 15764" not in log:
    raise SystemExit("FAIL: expected tutorial exit cutscene was not observed")
print("PASS: original tutorial controls, ladder, exit cutscene and a09 -> b03 transition")
