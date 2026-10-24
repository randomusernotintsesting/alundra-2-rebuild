# Windows x64 development build

This is a CPU/SDL candidate, not a claim of macOS Metal feature parity or
complete game compatibility. Qualification results are delivered separately;
the commands below are build/packaging instructions, not evidence of a pass.
Use a native Windows x64 machine for Windows qualification, not Linux or Wine.

## Inputs and toolchain

- CMake 3.27+, Python 3.9+, and MinGW-w64 GCC/G++ (C11/C++11).
- SDL2 development package with `SDL2Config.cmake`, and zlib headers/library.
- Restore separately supplied compile-time inputs at their recorded relative
  paths after checking their SHA256 manifest. Exclude them locally from Git.
- Obtain your own lawful runtime archive separately. Never include game data,
  build-input archives, extracted files or personal saves in source commits,
  public attachments or the binary ZIP.

The generated C modules are immutable inputs. MSVC is not qualified by these
instructions; compiler-specific options and generated code require MinGW.
Keep existing macOS paths and code unchanged when modifying Windows support.

From PowerShell, with your toolchain and dependencies already installed:

```powershell
cmake -S port -B build-win -G Ninja -DCMAKE_BUILD_TYPE=Release `
  -DSDL2_DIR=C:/dependencies/SDL2/cmake -DZLIB_ROOT=C:/dependencies/zlib
cmake --build build-win --target alundra2 test_text_raster --parallel 4
ctest --test-dir build-win -R '^text_raster$' --output-on-failure
```

Replace dependency directories with your actual installation paths. The Windows
target uses DirectWrite for Unicode shaping, WIC for images and PNG output,
and the shared SDL host menu. The executable reserves a 256 MiB stack for
recompiled guest code. Static GCC/C++ runtimes do not imply SDL/zlib are static.

## Explicit, game-data-free packaging

Use a new output filename for each candidate. The script copies only the
explicit executable, its supplied non-system DLL dependencies and text notices;
it never recurses through source, build, private-input or data directories.
It checks x64 PE imports recursively using MinGW `objdump`, rejects missing
non-system DLLs and Windows system DLL redistribution, and records hashes and
the exact source commit. It does not download any dependencies or licenses.

Example (add `--dll` for every reported missing dependency, including a
transitive compiler runtime when your build needs one):

```powershell
$rev = git rev-parse HEAD
python port/tools/package_windows.py --binary build-win/alundra2.exe `
  --dll C:/dependencies/SDL2/bin/SDL2.dll `
  --dll C:/dependencies/zlib/bin/zlib1.dll `
  --notice C:/notices/COPYING-SDL2.txt --notice C:/notices/LICENSE-zlib.txt `
  --notice port/assets/fonts/OFL-PTSerif.txt `
  --source-revision $rev --compiler 'record exact GCC version here' `
  --objdump C:/toolchain/bin/objdump.exe --output Alundra2-Windows-candidate.zip
```

Include all applicable third-party notices from the actual dependencies and
compiled resources, not just the example notices. An unresolved optional or
new system import is a packaging error to investigate, not a reason to copy
Windows system DLLs. The known-system allowlist is intentionally conservative.

After extraction, run the package with `PATH` restricted to Windows system
directories and the package itself, from an unrelated working directory.
Use paths containing spaces and Cyrillic, a fresh disposable `A2_USER_DIR`,
and `A2_RESOURCE_ARCHIVE` pointing to the privately held runtime archive.
Check missing-data diagnostics separately with the archive environment unset.
The archive need not be adjacent to the executable. No personal save is needed.

## Qualification boundaries

Follow [devin-task.md](devin-task.md) for the acceptance checklist. Report
PASS/FAIL/BLOCKED/NOT TESTED per scenario. In particular:

- A successful link, `--help`, a text test or a live process is not gameplay.
- Record display adapter/driver/DPI, SDL renderer, hardware versus remote or
  software fallback, and actual audio device availability.
- Use only new disposable saves; test save/load/restart and state checksums.
- Shell storage tests do not substitute for F5/F9 and in-game save/load.
- Windows does not enable the macOS Metal fine, native mesh or antialias paths.
- Do not claim stable 60 fps, controller support or audio playback without
  actually observing it on an available device.
- Keep package and test evidence in the private session; no public release,
  merge, or game-data attachment is authorized by these instructions.
