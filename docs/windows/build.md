# Windows x64 development build

This is a CPU/SDL candidate, not a claim of macOS Metal feature parity or
complete game compatibility. Qualification results are delivered separately;
the commands below are build/packaging instructions, not evidence of a pass.
Use a native Windows x64 machine for Windows qualification, not Linux or Wine.

## Windows storage qualification

Build the `test_storage_windows`, `test_memcard_windows`, `test_settings`,
`test_launch_profile`, `test_text_raster`, and `test_phase_timing` targets, then
run CTest with `-R '^(storage_windows|memcard|settings|launch_profile|text_raster|phase_timing)$'`.
The storage runners use disposable Unicode directories and independent synthetic
save/card bytes; no game data or personal save is needed.

Windows storage pins directory ancestors without delete sharing, rejects reparse
points and hardlinked files, creates exclusive random temporary files, and
publishes using a handle-based rename. A post-publication flush/close failure is
reported as published-but-uncertain, not as an unchanged destination. There is no
portable Windows equivalent of POSIX directory fsync: file flushing and successful
rename do not establish directory-entry durability under power loss. The native
test fault-injects a post-publication failure; it is not a power-loss experiment.

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

## Normal Windows launch profile

The executable itself applies the applicable shared app-profile defaults before
startup, not only in a test launcher: `A2_LOCAL_POSE=1`, `A2_COLOR_PRECISION=1`,
`A2_PRECISE_CULL=2`, `A2_WORLD_CAMERA=1`, `A2_WORLD_PERSPECTIVE=1`,
`A2_WORLD_PRECISION=1`, and `A2_WORLD_RASTER=1`. Existing environment values are
retained as explicit overrides. The effective values and default/override origin
are written to stderr on every launch; preserve this output with the exact
source commit in qualification evidence. Defaults are set in both the executable's
C runtime and Windows process environment. Separate DLL CRT environment caches
are not assumed to be synchronized by a Windows API call alone.

`A2_COLOR_CONTINUITY`, `A2_MODEL_DEPTH`, `A2_MODEL_MINIFY`, and `A2_WORLD_DEPTH`
are not claimed active: in this source snapshot their execution depends on the
Apple-scoped native-mesh/packet-observer initialization or compile definitions.
`A2_FINE_PARALLEL`, `A2_GPU_FINE`, and `A2_GPU_PRESENT` are also unavailable on
Windows. None of these seven switches is enabled by the Windows profile; an
inherited request is logged as unavailable, not treated as feature parity.
No personal user directory or resource archive is copied from the app profile.

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
