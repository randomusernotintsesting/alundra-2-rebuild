"""Verify that optional live replay pauses, captures, and resumes the real game."""
import argparse
import os
from pathlib import Path
import subprocess
import tempfile
import time

port = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--binary", type=Path, required=True)
args = parser.parse_args()
with tempfile.TemporaryDirectory(prefix="alundra-live-replay-") as temporary:
    root = Path(temporary)
    control = root / "control.txt"
    control.write_text("16\n")
    env = {k: v for k, v in os.environ.items() if not k.startswith("A2_")}
    env.update(SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy", A2_SOUND="0",
               A2_FAST="1", A2_IRSCALE="1", A2_WIDE="0", A2_MAXFRAMES="48",
               A2_TIMEOUT="30", A2_CONTROL_FILE=str(control), A2_USER_DIR=str(root / "user"))
    command = [str(args.binary.resolve()), str(port.parent / "disc_jp"),
               "--boot", str(port.parent / "build/alundra2_jp.bin")]
    with (root / "run.log").open("w") as log:
        process = subprocess.Popen(command, cwd=root, env=env, stdout=log, stderr=subprocess.STDOUT)
        try:
            for frame, next_frame in ((16, 32), (32, 64)):
                deadline = time.monotonic() + 15
                marker = f"control: paused frame={frame} "
                while marker not in (root / "run.log").read_text():
                    if process.poll() is not None or time.monotonic() > deadline:
                        raise AssertionError(f"Game did not pause at {frame}: " + (root / "run.log").read_text())
                    time.sleep(0.02)
                assert (root / f"user/ram_{frame:05}.bin").stat().st_size == 2 * 1024 * 1024
                assert (root / f"user/frame_{frame:05}.bmp").stat().st_size > 54
                time.sleep(0.15)
                assert not (root / f"user/frame_{next_frame:05}.bmp").exists(), "Game advanced while paused"
                assert process.poll() is None, "Game exited while paused"
                replacement = root / "control.next"
                replacement.write_text(f"{next_frame}\n{frame+1}:14:4\n")
                replacement.replace(control)
            assert process.wait(timeout=15) == 0
            assert "frame limit reached (48 frames)" in (root / "run.log").read_text()
        finally:
            if process.poll() is None:
                process.kill()
                process.wait(timeout=10)
print("PASS: real game paused twice, captured RAM/frames, resumed, and exited at its frame limit")
