# Alundra 2: Windows x64 build and actual Windows qualification

## Objective
Produce a Windows x64 candidate and test it on a real Windows Devin VM. The user explicitly requested Windows build/testing and a Reddit draft. The user authorized this public repository and Windows work through a GitHub PR. No Reddit publication, binary release, repository visibility change, or merge is authorized.

## Input
This public repository exports the code from development snapshot d8b76f5f435daf12e0341a2845127927eb404793. Generated C files are immutable inputs. Preserve macOS behavior and do not regenerate game modules. Read README.md and docs/separate-inputs.json: compile-time graphics/font headers, dialogue, model data and extracted test fixtures are intentionally excluded. Request those as a private session attachment. Do not commit them or replace them with empty production stubs. You can inspect and fix platform code and run independent synthetic tests while waiting. Report missing inputs as unavailable validation, never a passing full build.

## Reproduced failure
CMake Windows cross-configuration succeeds with MinGW x64, SDL2 2.32.10 and zlib 1.3.2. The production build fails. The original full-input local build produced 37 compiler errors; see docs/windows/compiler-errors.txt for their extracted messages. This public checkout additionally lacks the separate inputs described above.
- native_save_store.c requires POSIX openat/fstatat/flock/linkat/renameat/unlinkat/fsync and flags not available on Windows.
- save_browser_model.c requires fdopendir and /dev/urandom.
- memcard.c requires locking and atomic replacement with POSIX semantics.
- paths.c calls the POSIX two-argument mkdir; Windows paths also need separators, drive roots and Unicode coverage.
- CMake selects only the CoreText image/text backend and host UI adapter under APPLE. Windows needs a genuine platform implementation and native-menu definitions. Do not silence unresolved symbols with no-op stubs.
- Inspect settings persistence, binary I/O modes, file replacement, timing clocks and stack size.
- Metal fine rendering, mesh and antialias paths are APPLE-only; disclose differences. Do not pretend Windows has feature parity or a GPU renderer if using the CPU/SDL path.

## Scope
Make the minimum platform changes in a dedicated branch. Retain save format validation, read-failure destination preservation, locking, atomic publication, no-replace creation, imported snapshot immutability and memory-card backups. Do not remove protections merely to compile. Add focused Windows tests for changed file behavior and use existing portable tests. Windows CPU rendering is an initial candidate only; document limitations.

## Runtime data
The game archive and separate compile-time inputs are local and not included in this repository. Ask the coordinator for a PRIVATE session attachment before full compilation/gameplay. Confirm that your session actually has Windows available before attempting the Windows acceptance checklist. Never fetch a ROM from the internet and never publish game.a2r, disc images, extracted game data or personal saves. Synthetic fixtures can test data discovery and storage before the archive is available. No full runtime claim without actual game data.

## Acceptance and evidence
1. Record OS/build, CPU, memory, display adapter, driver, resolution, DPI and available renderer; record whether hardware acceleration is real or software/remote fallback.
2. Build Release x64, include all non-system runtime DLLs and third-party notices, record commands and SHA256 values, and deliver a downloadable ZIP. Verify launch on Windows without build-tool paths supplying missing DLLs.
3. Run --help and --check-data; missing data must yield a useful error. Test paths with spaces and Cyrillic, an unrelated working directory, and a fresh isolated A2_USER_DIR.
4. With privately supplied game data: record launch and startup menu, select English text, start a new game, reach controllable gameplay, move/jump/attack and open/close menus. Record screenshots/video and stdout/stderr. Do not infer a pass from process existence.
5. Test audio output and document remote-audio limitations; test keyboard remapping, fullscreen/window resize, focus loss and controller only if one is actually available.
6. Save a NEW disposable slot, move to a different state, load it, restart the process and load again. Test F5/F9 and settings persistence. Record a before/after state and save-file checksum. Never use or overwrite personal saves.
7. Corrupted/truncated saves must fail without changing the destination payload or original file. Concurrent writers and duplicate new-save paths must preserve existing files. Run meaningful storage and text-raster tests.
8. Report pass/fail/unavailable per item. No claim of complete game compatibility, stable 60 fps or all GPU compatibility from a smoke test.
9. Return exact source revision, patch/branch, binary ZIP, logs, test results, screenshots/video and remaining limitations. Do not merge or publish a release.
