"""Run the retained-emitter fixture with diagnostic-only environment changes."""
import os
from pathlib import Path
import subprocess
import sys


def run(binary, setting):
    env = os.environ.copy()
    env.pop("A2_MESH_TRACE", None)
    env.pop("A2_MESH_EMIT_TRACE", None)
    if setting is not None:
        env["A2_MESH_EMIT_TRACE"] = setting
    p = subprocess.run([str(binary)], env=env, text=True, capture_output=True, timeout=15)
    assert p.returncode == 0, p.stderr
    lines = [line for line in p.stderr.splitlines() if line.startswith("nativeemit:")]
    return p.stdout, lines


def main():
    binary = Path(sys.argv[1]).resolve()
    reference, off = run(binary, None)
    assert not off
    actual, lines = run(binary, "10:10")
    assert actual == reference, "diagnostics changed native RAM/scratch/GPR/work/continuation"
    assert len(lines) == 3 * 27 * 2, (len(lines), lines[:4])
    assert all("frame=10 " in line for line in lines)
    enters = [line for line in lines if "phase=entry " in line]
    finals = [line for line in lines if "phase=final " in line]
    assert len(enters) == len(finals) == 81
    assert all("key=T02 " in line for line in lines)
    assert any("shadow=1 " in line and "reason=shadow-pass " in line for line in finals)
    assert any("reason=part-ineligible " in line for line in finals)
    assert any("captured=1 " in line for line in finals)
    assert all("source_face=" in line and "dma=" in line and "caller=" in line for line in finals)
    for setting in ("12:15", "bad", "10", "11:10", "-1:10", "10:4294967296"):
        actual, absent = run(binary, setting)
        assert actual == reference and not absent, setting
    print("PASS: complete 81-emission census, excluded shadow/part paths, bounded frame ranges and native-state equality")


if __name__ == "__main__":
    main()
