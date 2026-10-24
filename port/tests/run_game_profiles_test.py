"""Run profile resolution with only owned synthetic files."""
import subprocess
import sys
import tempfile
with tempfile.TemporaryDirectory(prefix="alundra2-profiles-") as directory:
    raise SystemExit(subprocess.run([sys.argv[1], directory], timeout=20).returncode)
