#!/usr/bin/env python3
"""Package only explicit Windows binaries/notices; never traverse asset directories."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess
import zipfile


SYSTEM_DLLS = set("""
advapi32 bcrypt cfgmgr32 comctl32 comdlg32 crypt32 d2d1 d3d9 d3d11 d3d12
dcomp dinput8 dsound dwmapi dwrite dxgi dxguid gdi32 hid imm32 iphlpapi
kernel32 kernelbase mf mfplat mfreadwrite msvcrt ntdll ole32 oleaut32 opengl32
powrprof propsys psapi rpcrt4 secur32 setupapi shell32 shlwapi ucrtbase user32
userenv uuid uxtheme version windowscodecs winhttp winmm winspool ws2_32 wtsapi32
xinput1_4 xinput9_1_0
""".split())


def imports(path, objdump):
    result = subprocess.run([objdump, "-p", str(path)], check=True,
                            stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                            encoding="utf-8", errors="replace")
    if "file format pei-x86-64" not in result.stdout:
        raise ValueError(f"not a Windows x64 PE binary: {path.name}")
    return re.findall(r"DLL Name:\s*([^\s]+)", result.stdout, re.IGNORECASE)


def is_system(name):
    lower = name.lower()
    return (lower.endswith(".dll") and
            (lower[:-4] in SYSTEM_DLLS or lower.startswith(("api-ms-win-", "ext-ms-win-"))))


def collect(binary, dlls, objdump):
    if binary.suffix.lower() != ".exe" or not binary.is_file():
        raise ValueError("--binary must be an existing .exe")
    available = {}
    for dll in dlls:
        key = dll.name.lower()
        if dll.suffix.lower() != ".dll" or not dll.is_file() or is_system(key):
            raise ValueError(f"not a non-system DLL: {dll.name}")
        if key in available:
            raise ValueError(f"duplicate DLL name: {dll.name}")
        available[key] = dll
    files = {binary.name: binary}
    queue = [binary]
    seen = {binary.name.lower()}
    dependencies = {}
    while queue:
        path = queue.pop()
        dependencies[path.name] = imports(path, objdump)
        for name in dependencies[path.name]:
            if is_system(name) or name.lower() in seen:
                continue
            if name.lower() not in available:
                raise ValueError(f"missing non-system dependency {name} (required by {path.name})")
            dll = available[name.lower()]
            files[dll.name] = dll
            seen.add(name.lower())
            queue.append(dll)
    return files, dependencies


def package(binary, dlls, notices, output, objdump, revision, compiler):
    if not re.fullmatch(r"[0-9a-f]{40}", revision):
        raise ValueError("--source-revision must be the exact 40-digit source commit")
    if output.exists():
        raise ValueError("output exists; use a new filename to preserve prior evidence")
    files, dependencies = collect(binary, dlls, objdump)
    notice_names = set()
    if not notices:
        raise ValueError("at least one third-party notice is required")
    for path in notices:
        key = path.name.lower()
        if key in notice_names or path.stat().st_size > 1024 * 1024:
            raise ValueError(f"duplicate/oversized notice: {path.name}")
        content = path.read_text(encoding="utf-8")
        if not content.strip() or "\0" in content:
            raise ValueError(f"not a text notice: {path.name}")
        notice_names.add(key)
        files["third-party-notices/" + path.name] = path
    manifest = {"source_revision": revision, "compiler": compiler,
                "architecture": "Windows x64", "imports": dependencies,
                "sha256": {name: hashlib.sha256(path.read_bytes()).hexdigest()
                           for name, path in sorted(files.items())}}
    readme = """Alundra 2: Rebuild - Windows x64 development candidate

No game archive, extracted game files, private build inputs or personal saves
are distributed as separate files in this ZIP. The executable contains the
compiled resources necessary to run the port. Supply your own lawful game.a2r.
Do not upload game content or personal saves to the public repository.

Extract the entire ZIP to one directory; do not launch inside the ZIP.
Run alundra2.exe --help or alundra2.exe --check-data from a terminal.
Set A2_RESOURCE_ARCHIVE to the full path of your own game.a2r.
Set A2_USER_DIR to a NEW disposable writable directory for qualification.

This candidate uses the CPU/SDL renderer. macOS Metal fine rendering, native
mesh and antialiasing features are not Windows feature-parity claims.
Remote display/audio devices may limit qualification. Consult the separate
qualification report for actual PASS/FAIL/BLOCKED/NOT TESTED results.

This mixed-origin fan snapshot has no blanket open-source license. Preserve
all third-party notices. No affiliation with the original developers/publishers.
"""
    created = False
    try:
        with zipfile.ZipFile(output, "x", compression=zipfile.ZIP_DEFLATED) as archive:
            created = True
            for name, path in sorted(files.items()):
                archive.write(path, name)
            archive.writestr("BUILD-MANIFEST.json", json.dumps(manifest, indent=2) + "\n")
            archive.writestr("README-Windows.txt", readme)
    except Exception:
        if created and output.exists():
            output.unlink()
        raise
    return hashlib.sha256(output.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--binary", required=True, type=Path)
    parser.add_argument("--dll", action="append", default=[], type=Path)
    parser.add_argument("--notice", action="append", default=[], type=Path)
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--objdump", default="objdump")
    parser.add_argument("--source-revision", required=True)
    parser.add_argument("--compiler", required=True)
    args = parser.parse_args()
    try:
        digest = package(args.binary, args.dll, args.notice, args.output, args.objdump,
                         args.source_revision, args.compiler)
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        parser.exit(1, f"package_windows: {error}\n")
    print(f"SHA256 {digest}  {args.output.name}")


if __name__ == "__main__":
    main()
