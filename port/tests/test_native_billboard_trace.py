#!/usr/bin/env python3
"""Run the retained emitter fixture in isolated diagnostic environments."""
import os
from pathlib import Path
import subprocess
import sys

binary = str(Path(sys.argv[1]).resolve())
expected = None
for value in (None, "4396:4396", "4397:4400", "oops", "4400:4396", "0:4294967296"):
    env = os.environ.copy()
    env.pop("A2_BILLBOARD_TRACE", None)
    if value is not None:
        env["A2_BILLBOARD_TRACE"] = value
    run = subprocess.run([binary], env=env, text=True, capture_output=True, timeout=15)
    assert run.returncode == 0, run.stderr
    if expected is None:
        expected = run.stdout
    assert run.stdout == expected
    lines = [line for line in run.stderr.splitlines() if line.startswith("nativebillboard:")]
    if value == "4396:4396":
        assert any("pc=80014318 " in line for line in lines)
        assert any("pc=80014548 " in line and "stage=4 " in line for line in lines)
        assert any("pc=800147e4 " in line and "captured=1" in line and
                   "depth=699.31640625 " in line for line in lines)
        assert all("frame=4396 " in line for line in lines)
        assert any("reason=source-write " in line for line in lines)
    else:
        assert not lines, (value, lines)
print("billboard trace: exact retained-state assertions and bounded ON/OFF/malformed ranges PASS")
