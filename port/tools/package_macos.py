#!/usr/bin/env python3
"""Build a relocatable, ad-hoc signed macOS app from the native CLI binary.

No game data is included unless --include-data is supplied. The CMake
package_macos target supplies it for this user's local build. Existing apps
are never deleted: --replace accepts only our bundles and keeps a backup.
"""
import argparse
import datetime
import json
import os
import platform
import plistlib
import re
import shutil
import struct
import subprocess
import sys
import tempfile
import uuid
import zlib
from pathlib import Path

PORT = Path(__file__).resolve().parents[1]
BUNDLE_ID = "org.alundra2.native"
MARKER = "Contents/Resources/alundra2-package.json"


def command(*args):
    result = subprocess.run([str(x) for x in args], capture_output=True, text=True)
    if result.returncode:
        raise RuntimeError(f"{args[0]} failed: {result.stderr.strip() or result.stdout.strip()}")
    return result.stdout


def is_system(name):
    return name.startswith(("/usr/lib/", "/System/Library/"))


def load_info(binary):
    """Inspect load commands without assuming library paths contain no spaces."""
    links = command("otool", "-L", binary)
    dependencies = [line.strip().split(" (compatibility version", 1)[0]
                    for line in links.splitlines()[1:] if " (compatibility version" in line]
    ids = command("otool", "-D", binary).splitlines()[1:]
    dependencies = [dep for dep in dependencies if dep not in [x.strip() for x in ids]]
    commands = command("otool", "-l", binary)
    rpaths = re.findall(r"cmd LC_RPATH\s+cmdsize \d+\s+path (.*?) \(offset", commands)
    minimum = re.findall(r"\bminos ([0-9.]+)", commands)
    minimum += re.findall(r"cmd LC_VERSION_MIN_MACOSX\s+cmdsize \d+\s+version ([0-9.]+)", commands)
    return dependencies, rpaths, minimum


class Libraries:
    def __init__(self, binary, contents, sdl3_library=None):
        self.binary = binary.resolve()
        self.contents = contents
        self.sdl3_library = sdl3_library
        self.installed = {}
        self.names = {}
        self.minimum_versions = []
        self.architectures = set(command("lipo", "-archs", self.binary).split())

    def expand(self, value, loader):
        if value.startswith("@loader_path/"):
            return loader.parent / value[len("@loader_path/"):]
        if value.startswith("@executable_path/"):
            return self.binary.parent / value[len("@executable_path/"):]
        return Path(value)

    def resolve(self, name, loader, rpaths):
        if name.startswith("@rpath/"):
            suffix = name[len("@rpath/"):]
            candidates = [root / suffix for root in rpaths]
        else:
            candidates = [self.expand(name, loader)]
        for candidate in candidates:
            if candidate.is_file():
                return candidate.resolve()
        raise RuntimeError(f"Cannot resolve dependency {name!r} loaded by {loader}")

    def find_sdl3(self, source):
        if self.sdl3_library:
            candidate = self.sdl3_library.expanduser().resolve()
            if candidate.is_file():
                return candidate
            raise RuntimeError(f"SDL3 library does not exist: {candidate}")
        candidates = [source.parent / "libSDL3.dylib"]
        for prefix in (Path("/opt/homebrew"), Path("/usr/local")):
            candidates += [prefix / "opt/sdl3/lib/libSDL3.dylib", prefix / "lib/libSDL3.dylib"]
        for candidate in candidates:
            if candidate.is_file():
                return candidate.resolve()
        raise RuntimeError("sdl2-compat needs SDL3; pass --sdl3-library /path/to/libSDL3.dylib")

    def install(self, source, destination=None, inherited_rpaths=()):
        source = source.resolve()
        if source in self.installed:
            return self.installed[source]
        if destination is None:
            destination = self.contents / "Frameworks" / source.name
        if destination.name in self.names and self.names[destination.name] != source:
            raise RuntimeError(f"Different dependencies have the same filename: {destination.name}")
        library_arches = set(command("lipo", "-archs", source).split())
        if not self.architectures.issubset(library_arches):
            raise RuntimeError(f"Architecture mismatch: {source} has {sorted(library_arches)}, "
                               f"executable needs {sorted(self.architectures)}")
        self.installed[source] = destination
        self.names[destination.name] = source
        destination.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(source, destination)
        destination.chmod(destination.stat().st_mode | 0o700)
        dependencies, original_rpaths, minimum = load_info(source)
        self.minimum_versions.extend(minimum)
        rpaths = tuple(self.expand(value, source) for value in original_rpaths) + tuple(inherited_rpaths)
        for dependency in dependencies:
            if is_system(dependency):
                continue
            resolved = self.resolve(dependency, source, rpaths)
            copied = self.install(resolved, inherited_rpaths=rpaths)
            relative = os.path.relpath(copied, destination.parent)
            command("install_name_tool", "-change", dependency, "@loader_path/" + relative, destination)
        # All non-system links now point directly into this app; Homebrew
        # rpaths must not remain as an accidental fallback on the developer's Mac.
        for rpath in dict.fromkeys(original_rpaths):
            command("install_name_tool", "-delete_rpath", rpath, destination)
        if destination.parent.name == "Frameworks":
            command("install_name_tool", "-id", "@loader_path/" + destination.name, destination)
        # sdl2-compat dlopens SDL3, so this edge never appears in otool -L.
        # Its first macOS candidate is @loader_path/libSDL3.dylib.
        if "SDL2" in source.name and "sdl2-compat:" in command("strings", source):
            self.install(self.find_sdl3(source), self.contents / "Frameworks/libSDL3.dylib", rpaths)
        return destination

    def verify_links(self):
        for binary in self.installed.values():
            dependencies, rpaths, _ = load_info(binary)
            if rpaths:
                raise RuntimeError(f"Unresolved runtime search paths in {binary}: {rpaths}")
            for dependency in dependencies:
                if is_system(dependency):
                    continue
                if not dependency.startswith("@loader_path/"):
                    raise RuntimeError(f"Non-relocatable dependency in {binary}: {dependency}")
                target = (binary.parent / dependency[len("@loader_path/"):]).resolve()
                if not target.is_relative_to(self.contents.resolve()) or not target.is_file():
                    raise RuntimeError(f"Dependency escapes or is missing from app: {dependency}")


def check_existing(output, replace):
    if not output.exists() and not output.is_symlink():
        return
    if output.is_symlink() or not output.is_dir():
        raise RuntimeError(f"Refusing existing output: {output}")
    try:
        previous = json.loads((output / MARKER).read_text())
    except (OSError, ValueError):
        previous = {}
    if not replace or previous.get("packager") != "alundra2-native" or previous.get("bundle_id") != BUNDLE_ID:
        raise RuntimeError(f"Refusing existing app: {output}. --replace only accepts an app created by this tool.")


def optional_media(disc, profiles_override=None, voices_override=None):
    """Resolve complete, explicitly staged media before touching any app."""
    common = disc.parent
    if common.parent.name == "profiles":
        common = common.parent.parent
    profiles_root = profiles_override.expanduser().resolve() if profiles_override else common / "profiles"
    voices_root = voices_override.expanduser().resolve() if voices_override else common / "voices"
    if profiles_override and not profiles_root.is_dir():
        raise RuntimeError(f"Profile directory does not exist: {profiles_root}")
    if voices_override and not voices_root.is_dir():
        raise RuntimeError(f"Voice directory does not exist: {voices_root}")
    profiles = {}
    voices = {}
    for language in ("ja", "en"):
        profile = profiles_root / language
        if profile.exists():
            if not (profile / "disc/SCPS_101.15").is_file() or not (profile / "disc.bin").is_file():
                raise RuntimeError(f"Incomplete {language} profile: expected disc/SCPS_101.15 and disc.bin in {profile}")
            profiles[language] = profile
        voice = voices_root / language / "voices.a2v"
        if voice.is_file():
            voices[language] = voice
    return profiles, voices


def native_media(archive, require_models=False):
    """Read checked index metadata; payload validation belongs to runtime QA."""
    with archive.open('rb') as stream:
        header=stream.read(64)
        if len(header)!=64:raise RuntimeError('Native archive header is truncated')
        magic,version,mask,nf,ns,nc,crc,fo,so,co,end=struct.unpack('<8s6I4Q',header)
        if (magic!=b'A2RES001' or version!=1 or not 1<=mask<=7 or fo!=64 or
            so!=64+96*nf or co!=so+24*ns or end!=co+24*nc or end-64>64*1024*1024):
            raise RuntimeError('Native archive index is invalid')
        table=stream.read(end-64)
        if len(table)!=end-64 or zlib.crc32(table)!=crc:
            raise RuntimeError('Native archive index checksum failed')
        names={table[i*96:i*96+64].split(b'\0',1)[0] for i in range(nf)}
        if require_models:
            matches=[]
            for i in range(nf):
                name,language,flags,size,first,count,reserved=struct.unpack_from('<64sIIQIIQ',table,i*96)
                if name==b'MODELS/T02.A2M'.ljust(64,b'\0') and language==3:
                    if flags or reserved or size<256 or not count or first+count>ns:
                        raise RuntimeError('Native model logical entry is invalid')
                    matches.append(i)
            if len(matches)!=1:
                raise RuntimeError('--native-models requires shared logical MODELS/T02.A2M in the resource archive')
    profiles=[name for i,name in enumerate(('ru','ja','en')) if mask&(1<<i)]
    voices=[name for name in ('ja','en') if f'VOICE/{name}/index.a2v'.encode() in names]
    return profiles,voices


def native_launch_environment(native_models, archive):
    environment={"A2_LAUNCHER":"1","A2_NATIVE_SAVES":"1"}
    if native_models:
        if archive is None:raise RuntimeError('--native-models requires --resource-archive')
        native_media(archive,require_models=True)
        # This flag validates experimental resources only. Original models
        # remain the default; diagnostic opt-in is deliberately not bundled.
    return environment


def package(args):
    if sys.platform != "darwin":
        raise RuntimeError("macOS is required (otool, install_name_tool and codesign)")
    binary = args.binary.expanduser().resolve()
    output = args.output.expanduser().absolute()
    if output.suffix.lower() != ".app":
        raise RuntimeError("Output must be an .app directory")
    check_existing(output, args.replace)
    if not binary.is_file():
        raise RuntimeError(f"Build the native binary first: {binary}")
    disc = args.disc_root.expanduser().resolve()
    image = args.disc_image.expanduser().resolve()
    archive=args.resource_archive.expanduser().resolve() if args.resource_archive else None
    native_models=bool(getattr(args,'native_models',False))
    launch_environment=native_launch_environment(native_models,archive)
    includes_data=bool(args.include_data or archive)
    native_profiles,native_voices=native_media(archive) if archive else ([],[])
    if args.include_data and not archive and (not (disc / "SCPS_101.15").is_file() or not image.is_file()):
        raise RuntimeError("--include-data needs an extracted JP disc (SCPS_101.15) and its .bin image")
    profiles, voices = optional_media(disc, args.profiles_root, args.voices_root) if args.include_data and not archive else ({}, {})
    output.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix=".alundra2-package-", dir=output.parent) as temporary:
        app = Path(temporary) / output.name
        contents = app / "Contents"
        resources = contents / "Resources"
        resources.mkdir(parents=True)
        # Outline-derived HD glyphs are embedded in the executable; their
        # redistributable source font's notice must travel with the app.
        licenses = resources / "licenses"
        licenses.mkdir()
        shutil.copy2(PORT / "assets/fonts/OFL-PTSerif.txt", licenses / "OFL-PTSerif.txt")
        shutil.copy2(PORT / "assets/Alundra.icns", resources / "Alundra.icns")
        branding = resources / "branding"
        branding.mkdir()
        for name in ("alundra-2-rebuild.png",):
            source = PORT / "assets/branding" / name
            shutil.copy2(source, branding / name)
        libraries = Libraries(binary, contents, args.sdl3_library)
        libraries.install(binary, contents / "MacOS/alundra2")
        libraries.verify_links()
        minimum = max(libraries.minimum_versions or [platform.mac_ver()[0]],
                      key=lambda version: tuple(int(part) for part in version.split(".")))
        info = {
            "CFBundleName": "Alundra 2: Rebuild", "CFBundleDisplayName": "Alundra 2: Rebuild",
            "CFBundleIdentifier": BUNDLE_ID, "CFBundleExecutable": "alundra2",
            "CFBundleIconFile": "Alundra.icns",
            "CFBundlePackageType": "APPL", "CFBundleShortVersionString": "0.1.0",
            "CFBundleVersion": "1", "LSMinimumSystemVersion": minimum,
            "LSApplicationCategoryType": "public.app-category.role-playing-games",
            "NSHighResolutionCapable": True,
            # LaunchServices applies these only when launching the app bundle;
            # direct command-line diagnostic runs keep their explicit environment.
            "LSEnvironment": launch_environment,
        }
        with (contents / "Info.plist").open("wb") as stream:
            plistlib.dump(info, stream)
        (app / MARKER).write_text(json.dumps({"packager": "alundra2-native", "bundle_id": BUNDLE_ID,
                                            "includes_game_data": includes_data,
                                            "resource_backend": "native-archive" if archive else "legacy-disc",
                                            "text_profiles": native_profiles if archive else ["ru", *profiles] if args.include_data else [],
                                            "voice_packs": native_voices if archive else list(voices),
                                            **({"native_models": True} if native_models else {})}, indent=2) + "\n")
        if archive:
            data=resources/"game-data";data.mkdir()
            shutil.copy2(archive,data/"game.a2r")
        elif args.include_data:
            data = resources / "game-data"
            data.mkdir()
            # Dereference source hardlinks/symlinks: the finished app must own
            # independent files and keep working when the source folder moves.
            shutil.copytree(disc, data / "disc", ignore=shutil.ignore_patterns(".DS_Store"))
            shutil.copy2(image, data / "disc.bin")
            for language, profile in profiles.items():
                destination = data / "profiles" / language
                destination.mkdir(parents=True)
                shutil.copytree(profile / "disc", destination / "disc",
                                ignore=shutil.ignore_patterns(".DS_Store"))
                shutil.copy2(profile / "disc.bin", destination / "disc.bin")
                if (profile / "profile.json").is_file():
                    shutil.copy2(profile / "profile.json", destination / "profile.json")
            for language, source in voices.items():
                destination = data / "voices" / language
                destination.mkdir(parents=True)
                shutil.copy2(source, destination / "voices.a2v")
        for item in libraries.installed.values():
            command("codesign", "--force", "--sign", "-", "--timestamp=none", item)
        command("codesign", "--force", "--sign", "-", "--timestamp=none", app)
        command("codesign", "--verify", "--deep", "--strict", app)
        # Recheck immediately before moving anything. Failed builds never touch
        # the previous app; successful replacements keep it as a named backup.
        check_existing(output, args.replace)
        backup = None
        if output.exists():
            stamp = datetime.datetime.now().strftime("%Y%m%d-%H%M%S")
            backup = output.with_name(f"{output.stem}.previous-{stamp}-{uuid.uuid4().hex[:6]}.app")
            output.rename(backup)
        try:
            app.rename(output)
        except OSError:
            if backup is not None and not output.exists():
                backup.rename(output)
            raise
        if backup is not None:
            print(f"Previous app retained: {backup}")
    print(f"Packaged: {output}")
    print(f"Architectures: {', '.join(sorted(libraries.architectures))}; minimum macOS: {minimum}")
    print(f"Bundled native libraries: {len(libraries.installed) - 1}; game data: {includes_data}")
    return output


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--binary", type=Path, default=PORT / "build/alundra2")
    parser.add_argument("--output", type=Path, default=PORT / "build/Alundra 2 Rebuild.app")
    parser.add_argument("--include-data", action="store_true", help="copy this user's existing game data into the local app")
    parser.add_argument("--resource-archive",type=Path,
                        help="package one native game.a2r instead of disc images and extracted copies")
    parser.add_argument("--native-models",action="store_true",
                        help="validate bundled models; requires shared MODELS/T02.A2M inside --resource-archive")
    parser.add_argument("--disc-root", type=Path, default=PORT.parent / "disc_jp")
    parser.add_argument("--disc-image", type=Path, default=PORT.parent / "build/alundra2_jp.bin")
    parser.add_argument("--profiles-root", type=Path,
                        help="staged ja/en directories, each with disc/ and disc.bin (default: beside disc)")
    parser.add_argument("--voices-root", type=Path,
                        help="optional ja/en directories containing voices.a2v (default: beside disc)")
    parser.add_argument("--sdl3-library", type=Path, help="SDL3 dylib for an sdl2-compat build, if not found automatically")
    parser.add_argument("--replace", action="store_true", help="replace our existing app, preserving it as a dated backup")
    args = parser.parse_args()
    try:
        package(args)
    except (OSError, RuntimeError) as error:
        parser.exit(1, f"Packaging failed: {error}\n")


if __name__ == "__main__":
    main()
