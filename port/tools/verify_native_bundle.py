#!/usr/bin/env python3
"""Verify a relocated native .app while its former data locations are unreadable.

This tool does not copy, sign, repair, or replace an application. It verifies
the supplied separate bundle, then starts two sandboxed child processes with
archive autodiscovery and a private temporary user directory. The 1000-frame
dummy boot proves bounded native startup only, not complete speech or Cocoa
audio acceptance. Run only when the shared verification/runtime slot is free.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import plistlib
import re
import subprocess
import sys
import tempfile
import time

ROOT = Path(__file__).resolve().parents[2]
SANDBOX = Path("/usr/bin/sandbox-exec")
CODESIGN = Path("/usr/bin/codesign")
FRAME_LIMIT = 1000


def require(condition, message):
    if not condition:
        raise ValueError(message)


def sha256(path):
    with Path(path).open("rb") as source:
        return hashlib.file_digest(source, "sha256").hexdigest()


def sandbox_string(path):
    value = str(path)
    require(not any(ord(char) < 32 or ord(char) == 127 for char in value),
            "Sandbox paths cannot contain control characters")
    # SBPL string literals accept quoted backslash/quote escapes. Keep Unicode
    # literal rather than emitting JSON's unsupported \uXXXX representation.
    return json.dumps(value, ensure_ascii=False)


def sandbox_profile(denied):
    lines = ["(version 1)", "(allow default)"]
    for path in denied:
        quoted = sandbox_string(path)
        lines.append(f"(deny file-read* (subpath {quoted}))")
        lines.append(f"(deny file-write* (subpath {quoted}))")
    return "\n".join(lines) + "\n"


def clean_environment(inherited):
    return {key: value for key, value in inherited.items()
            if not key.startswith(("A2_", "SDL_", "DYLD_"))}


def inspect_bundle(app, denied):
    app = Path(app).expanduser().resolve(strict=True)
    denied = [Path(path).expanduser().resolve() for path in denied]
    require(app.suffix.lower() == ".app" and app.is_dir(), "Expected a separate .app directory")
    require(not any(app.is_relative_to(path) for path in denied),
            "The candidate app must be relocated outside every denied original location")
    contents = app / "Contents"
    info_path = contents / "Info.plist"
    require(info_path.is_file() and not info_path.is_symlink(), "Missing regular bundle Info.plist")
    with info_path.open("rb") as source:
        info = plistlib.load(source)
    executable = info.get("CFBundleExecutable")
    require(isinstance(executable, str) and executable not in ("", ".", "..") and
            "/" not in executable and "\\" not in executable, "Invalid bundle executable name")
    binary = contents / "MacOS" / executable
    require(binary.is_file() and not binary.is_symlink() and binary.resolve().is_relative_to(app),
            "Bundle executable must be a regular file inside the candidate")
    data = contents / "Resources/game-data"
    require(data.is_dir() and not data.is_symlink() and data.resolve().is_relative_to(app),
            "Missing owned Resources/game-data directory")
    entries = list(data.iterdir())
    require(len(entries) == 1 and entries[0].name == "game.a2r" and
            entries[0].is_file() and not entries[0].is_symlink(),
            "Bundle game-data must contain exactly one regular game.a2r, without images or extracted copies")
    archive = entries[0]
    with archive.open("rb") as source:
        require(source.read(8) == b"A2RES001", "Bundle archive is not A2RES001")
    require(not (contents / "MacOS/game-data").exists(),
            "Unexpected alternate MacOS/game-data would precede Resources autodiscovery")
    return dict(app=app, binary=binary, archive=archive,
                bundle_id=info.get("CFBundleIdentifier"), archive_bytes=archive.stat().st_size)


def validate_check_data(log, archive, user):
    resources = re.findall(r"^Native resources: (.+)$", log, re.MULTILINE)
    users = re.findall(r"^Settings and saves: (.+)$", log, re.MULTILINE)
    require(len(resources) == 1 and Path(resources[0]).resolve() == archive.resolve(),
            "--check-data did not autodiscover the candidate's bundled archive")
    require(len(users) == 1 and Path(users[0]).resolve() == user.resolve(),
            "--check-data did not use the isolated temporary user directory")
    require(re.search(r"^Text profiles: ru=1 ja=1 en=1$", log, re.MULTILINE),
            "One or more native text profiles are unavailable")
    require(re.search(r"^Voices: ja=1 en=1$", log, re.MULTILINE),
            "One or more native voice languages are unavailable")
    return dict(archive_autodiscovered=str(archive), text_profiles=["ru", "ja", "en"],
                voice_languages=["ja", "en"], isolated_user=str(user))


def fields(line):
    return {key: int(value) if value.isdecimal() else value
            for key, value in re.findall(r"([a-z_]+)=([^\s]+)", line)}


def validate_boot(log, language):
    expected = "Japanese" if language == "ja" else "English"
    count, origin = (183, 3) if language == "ja" else (177, 1)
    require(f"voices: native {expected} archive ready clips={count} image_required=0" in log,
            "Requested native voice archive did not initialize")
    require(re.search(r"overlay -> EVENT00 \(id=5\) at frame \d+", log),
            "Normal guest boot did not reach EVENT00")
    require(f"frame limit reached ({FRAME_LIMIT} frames)" in log,
            "Boot did not exit at its requested 1000-frame bound")
    require("native-resource: read " in log, "Boot lacks direct native resource-read evidence")
    require("Native playback failed:" not in log, "Native playback reported a fatal error")
    events = [dict(event=kind, **fields(line))
              for kind, line in re.findall(r"voicecue: (start|end) ([^\n]+)", log)]
    starts = [event for event in events if event["event"] == "start"]
    ends = [event for event in events if event["event"] == "end"]
    require(starts and all(event.get("native") == 1 for event in events),
            "Boot lacks genuine native voice events")
    require(any(event.get("origin") == origin and event.get("first_sample") == 0 and
                0 < event.get("frame", 0) <= FRAME_LIMIT for event in starts),
            "No native cue started from the selected source during the bounded boot")
    require(any(event.get("consumed", 0) > 0 and event.get("frames", 0) > 0 for event in ends),
            "No source audio blocks were decoded during the bounded boot")
    transport = [fields(line) for line in re.findall(r"nativecd: ([^\n]+)", log)]
    require(transport == [dict(raw_read_attempts=0, data_dma_attempts=0, fifo_attempts=0)],
            "Native raw-sector/data-DMA/FIFO diagnostics are missing or nonzero")
    return dict(frame_limit=FRAME_LIMIT, event00=True, native_resource_reads=True,
                voice_language=language, voice_events=events, transport=transport,
                complete_speech_acceptance=False,
                note="Cue ending at the frame limit may be partial; this checks relocation/startup, not full performances or audible Cocoa playback")


def run_step(name, command, profile_path, cwd, env, out, timeout, records, expected_success=True):
    argv = [str(SANDBOX), "-f", str(profile_path), *map(str, command)]
    record = dict(name=name, command=argv, cwd=str(cwd), timeout_seconds=timeout)
    records.append(record)
    started = time.monotonic()
    try:
        result = subprocess.run(argv, cwd=cwd, env=env, stdout=subprocess.PIPE,
                                stderr=subprocess.STDOUT, timeout=timeout, check=False)
        log = result.stdout.decode("utf-8", errors="replace")
        record.update(exit_code=result.returncode, wall_seconds=time.monotonic() - started)
    except subprocess.TimeoutExpired as error:
        raw = error.stdout or b""
        log = raw.decode("utf-8", errors="replace") if isinstance(raw, bytes) else raw
        record.update(timed_out=True, wall_seconds=time.monotonic() - started)
        (out / f"{name}.log").write_text(log)
        raise RuntimeError(f"Sandboxed {name} exceeded its {timeout}-second bound") from error
    (out / f"{name}.log").write_text(log)
    if expected_success:
        require(result.returncode == 0, f"Sandboxed {name} failed with exit {result.returncode}; see {name}.log")
    return result.returncode, log


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--app", type=Path, required=True, help="Separate relocated candidate, outside the repository")
    parser.add_argument("--output", type=Path, required=True, help="New durable evidence directory; never an app directory")
    parser.add_argument("--source-root", type=Path, default=ROOT)
    parser.add_argument("--old-app", type=Path, default=Path.home() / "Desktop/Alundra 2 HD.app")
    parser.add_argument("--real-user-dir", type=Path,
                        default=Path.home() / "Library/Application Support/Alundra2/Alundra 2")
    parser.add_argument("--voice-language", choices=("ja", "en"), default="en")
    parser.add_argument("--timeout", type=int, default=90, help="Per-child wall bound, 15..180 seconds")
    args = parser.parse_args()
    require(sys.platform == "darwin", "This relocation verification requires macOS")
    require(15 <= args.timeout <= 180, "Timeout must be between 15 and 180 seconds")
    require(SANDBOX.is_file() and CODESIGN.is_file(), "macOS sandbox-exec/codesign tools are missing")
    denied = [path.expanduser().resolve() for path in (args.source_root, args.old_app, args.real_user_dir)]
    bundle = inspect_bundle(args.app, denied)
    out = args.output.expanduser().resolve()
    require(not out.is_relative_to(bundle["app"]) and not any(out.is_relative_to(path) for path in denied[1:]),
            "Evidence cannot be written inside the candidate, old app, or real user directory")
    out.mkdir(parents=True, exist_ok=False)
    report = dict(passed=False, bundle={key: str(value) if isinstance(value, Path) else value
                                      for key, value in bundle.items()},
                  denied_locations=list(map(str, denied)), steps=[], errors=[],
                  scope="Relocated archive autodiscovery and bounded native startup; separate complete-speech/Cocoa acceptance required")
    try:
        # Verify content hashes outside the child sandbox without touching any
        # original media/user files. Codesign then validates the existing seal.
        report["bundle"]["binary_sha256"] = sha256(bundle["binary"])
        report["bundle"]["archive_sha256"] = sha256(bundle["archive"])
        with tempfile.TemporaryDirectory(prefix="a2-native-bundle-", dir="/private/tmp") as temporary:
            work = Path(temporary).resolve()
            require(not any(work.is_relative_to(path) for path in denied), "Temporary runtime directory falls inside a denied location")
            profile = sandbox_profile(denied)
            profile_path = work / "sandbox.sb"
            profile_path.write_text(profile)
            (out / "sandbox.sb").write_text(profile)
            user = work / "user"
            user.mkdir(mode=0o700)
            env = clean_environment(os.environ)
            overrides = dict(LC_ALL="C", A2_USER_DIR=str(user), SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy",
                             A2_LAUNCHER="0", A2_TEXT_LANGUAGE="0",
                             A2_VOICE_LANGUAGE=str(("ja", "en").index(args.voice_language)),
                             A2_FAST="1", A2_IRSCALE="1", A2_WIDE="1", A2_SOUND="1",
                             A2_AUTO="1", A2_MAXFRAMES=str(FRAME_LIMIT), A2_TIMEOUT=str(args.timeout),
                             A2_STATELOG="1", A2_RESOURCE_LOG="1", A2_AUDIOSTAT="1")
            env.update(overrides)
            report["environment_overrides"] = overrides
            report["temporary_runtime_directory"] = str(work)
            # Negative control confirms this profile actually prevents source
            # reads; it never opens a real save or old application file.
            canary = denied[0] / "port/src/main.c"
            require(canary.is_file(), "Source-root must contain port/src/main.c for the sandbox denial control")
            code, denial = run_step("sandbox-denial", ["/usr/bin/head", "-c", "1", canary],
                                   profile_path, work, env, out, args.timeout, report["steps"], False)
            require(code != 0 and ("Operation not permitted" in denial or "Permission denied" in denial),
                    "Source-read negative control did not produce a sandbox access denial")
            run_step("codesign", [CODESIGN, "--verify", "--deep", "--strict", "--verbose=2", bundle["app"]],
                     profile_path, work, env, out, args.timeout, report["steps"])
            _, check_log = run_step("check-data", [bundle["binary"], "--check-data"],
                                    profile_path, work, env, out, args.timeout, report["steps"])
            report["availability"] = validate_check_data(check_log, bundle["archive"], user)
            _, boot_log = run_step("boot", [bundle["binary"], "--boot"],
                                   profile_path, work, env, out, args.timeout, report["steps"])
            report["boot"] = validate_boot(boot_log, args.voice_language)
            report["passed"] = True
    except (Exception, KeyboardInterrupt) as error:
        report["errors"].append(f"{type(error).__name__}: {error}")
    (out / "verification.json").write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n")
    print(json.dumps(dict(passed=report["passed"], errors=report["errors"], output=str(out)), ensure_ascii=False, indent=2))
    return 0 if report["passed"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
