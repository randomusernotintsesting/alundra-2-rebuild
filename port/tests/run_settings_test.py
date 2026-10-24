"""Run the native settings regression against an owned temporary user directory."""
import argparse
import os
import subprocess
import sys
import tempfile
from pathlib import Path


def main():
    if os.name == "nt":
        sys.stdout.reconfigure(encoding="utf-8")
        sys.stderr.reconfigure(encoding="utf-8")
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("binary", type=Path)
    args = parser.parse_args()
    env = {key: value for key, value in os.environ.items() if not key.startswith("A2_")}
    with tempfile.TemporaryDirectory(prefix="alundra2-settings-test-") as temporary:
        directory = str(Path(temporary) / "Профиль settings 日本語")
        Path(directory).mkdir()
        env.update(A2_USER_DIR=directory, SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy")
        result = subprocess.run([str(args.binary.resolve())], cwd=directory, env=env, timeout=30,
                                capture_output=True, text=True, encoding="utf-8", errors="replace")
        print(result.stdout, end="")
        print(result.stderr, end="")
        if result.returncode == 0 and (list(Path(directory).glob("a2settings.ini.tmp*")) or list(Path(directory).glob(".a2tmp-*"))):
            print("FAIL: settings_save left temporary files behind")
            return 1
        return result.returncode


if __name__ == "__main__":
    raise SystemExit(main())
