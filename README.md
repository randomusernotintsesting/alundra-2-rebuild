# Alundra 2: Rebuild

An unofficial Alundra 2 PC port in development. The goal is to bring the original game to desktop systems with higher-resolution presentation, keyboard and controller support, and desktop-friendly menus and saves.

The runtime combines statically recompiled PlayStation game code, a fallback interpreter, and native C/SDL2 systems for rendering, input, audio, resources and saves. Development has focused on macOS. Windows support is being brought up; no tested Windows release is available yet.

## Current status

This is a public **code snapshot**, not a complete game download or a standalone build kit. It contains the runtime, generated C modules, tools and tests from development revision `d8b76f5f435daf12e0341a2845127927eb404793`. The original development history is not included.

Embedded graphics, fonts, dialogue/subtitle data, extracted test fixtures and machine-specific research files are excluded. Some of these inputs are required at compile time. Their relative paths and SHA256 checksums are recorded in [docs/separate-inputs.json](docs/separate-inputs.json). The game archive `game.a2r`, disc images and personal saves are not distributed here. There is currently no automated clean-disc-to-complete-build procedure in this snapshot.

Windows cross-configuration with MinGW x64, SDL2 2.32.10 and zlib 1.3.2 succeeds with the complete local inputs. Compilation currently fails in platform-dependent filesystem and save code. Text rendering also needs a Windows backend. The macOS Metal renderer has features that are not available in the initial Windows CPU/SDL path.

## Building

With the required separate build inputs restored at their recorded paths, the starting point is:

```sh
cmake -S port -B build -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=OFF
cmake --build build --parallel
```

CMake 3.27+, a C11 compiler, Python 3.9+, SDL2 and zlib development packages are required. SDL2 must provide its CMake package configuration. These commands are a development starting point, not a claim that Windows currently builds. There are no binary downloads yet.

## Project boundaries

This is a fan project and is not affiliated with the original developers or publishers. Original game content and third-party components retain their respective ownership. No blanket open-source license is asserted for this mixed-origin snapshot. Existing source notices are preserved.

Please do not submit game archives, disc images, extracted assets or personal saves in issues or pull requests. Bug reports should identify the source revision, operating system and reproducible steps; remove personal paths from logs.
