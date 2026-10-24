"""Adaptive, ordinary-input 002AM acceptance from a new game in a native archive.

Without --run this writes only a prospective launch plan. The live route never
restores RAM, invokes guest functions, or selects an overlay/voice directly.
Checkpoint RAM/VRAM files are output evidence only; decisions use game log state.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import time

from replay_routes import tutorial_taps

ROOT = Path(__file__).resolve().parents[2]
ARCHIVE = ROOT / "port/build/verification/september-polish/native-resources/game.a2r"
CHECKPOINT = re.compile(r"control: paused frame=(\d+) overlay=(\d+) map_id=(\d+) "
                        r"pos=(-?\d+),(-?\d+),(-?\d+) flags=([0-9A-F]+)")
EXPECTED = {"ja": (681, 2745792, 3), "en": (682, 2749824, 1)}
EARLY_BOOT_CHECKPOINTS = (100, 350, 1000)


def fields(line):
    return {key: int(value) if value.isdecimal() else value
            for key, value in re.findall(r"([a-z_]+)=([^\s]+)", line)}


def cue_events(log):
    return [dict(event=kind, **fields(line))
            for kind, line in re.findall(r"voicecue: (start|end) ([^\n]+)", log)]


def speech_audio_window(log):
    """Bracket 002AM and also require growth strictly inside its live interval.

    The interior comparison prevents a prior cue's last queued samples or the
    following cue from satisfying the check between the outer measurements.
    """
    starts, ends, stats = [], [], []
    for index, line in enumerate(log.splitlines()):
        if line.startswith("audiostat: "):
            stats.append((index, fields(line)))
        elif line.startswith("voicecue: ") and fields(line).get("name") == "002AM":
            if line.startswith("voicecue: start "):
                starts.append(index)
            elif line.startswith("voicecue: end "):
                ends.append(index)
    evidence = dict(passed=False, before_start=None, after_complete=None,
                    interior_first=None, interior_last=None, delta={}, interior_delta={})
    if len(starts) != 1 or len(ends) != 1 or starts[0] >= ends[0]:
        return evidence
    before = [row for index, row in stats if index < starts[0]]
    after = [row for index, row in stats if index > ends[0]]
    inside = [row for index, row in stats if starts[0] < index < ends[0]]
    if not before or not after or len(inside) < 2:
        return evidence
    evidence.update(before_start=before[-1], after_complete=after[0],
                    interior_first=inside[0], interior_last=inside[-1],
                    interior_measurements=len(inside))
    rows = [before[-1], *inside, after[0]]
    keys = ("tick", "cd_nonzero", "cd_mixed_nonzero")
    if any(not isinstance(row.get(key), int) for row in rows for key in keys):
        return evidence
    if any(new["tick"] <= old["tick"] or
           any(new[key] < old[key] for key in keys[1:])
           for old, new in zip(rows, rows[1:])):
        return evidence
    evidence["delta"] = {key: after[0][key] - before[-1][key] for key in keys[1:]}
    evidence["interior_delta"] = {key: inside[-1][key] - inside[0][key] for key in keys[1:]}
    evidence["passed"] = all(value > 0 for value in evidence["interior_delta"].values())
    return evidence


def checkpoint(log):
    found = list(CHECKPOINT.finditer(log))
    if not found:
        return None
    values = found[-1].groups()
    return dict(frame=int(values[0]), overlay=int(values[1]), map_id=int(values[2]),
                pos=list(map(int, values[3:6])), flags=int(values[6], 16))


def tutorial_ready(state):
    return (state["overlay"] == 4 and state["map_id"] == 213 and
            state["pos"] == [-890, 0, -3425] and state["flags"] == 0)


def next_intro_frame(current):
    return next((frame for frame in EARLY_BOOT_CHECKPOINTS if frame > current), current + 1000)


def shifted_tutorial(first_frame):
    result = []
    for tap in tutorial_taps():
        original, *rest = tap.split(":")
        result.append(":".join((str(int(original) + first_frame - 4800), *rest)))
    return result


def control_text(current, until, taps):
    active = []
    for tap in taps:
        parts = list(map(int, tap.split(":")))
        duration = parts[2] if len(parts) == 3 else 4
        if parts[0] < until and parts[0] + duration > current:
            active.append(tap)
    if len(active) > 128:
        raise ValueError("Control batch exceeds native capacity")
    return str(until) + "\n" + "".join(tap + "\n" for tap in active)


def write_control(out, current, until, taps):
    contents = control_text(current, until, taps)
    (out / f"control-{until:05}.txt").write_text(contents)
    temporary = out / "control.next"
    temporary.write_text(contents)
    temporary.replace(out / "control.txt")


def acceptance(log, language, exit_code, stop_inputs_frame):
    events = cue_events(log)
    speech_audio = speech_audio_window(log)
    starts = [event for event in events if event["event"] == "start" and event["name"] == "002AM"]
    ends = [event for event in events if event["event"] == "end" and event["name"] == "002AM"]
    blocks, frames, origin = EXPECTED[language]
    transport = [fields(line) for line in re.findall(r"nativecd: ([^\n]+)", log)]
    metrics = {}
    for key in ("decode_failed", "data_overrun", "cd_dropped", "host_fail",
                "cd_nonzero", "cd_mixed_nonzero", "host_starve", "host_overflow"):
        values = [int(value) for value in re.findall(rf"\b{key}=(\d+)", log)]
        metrics[key] = max(values) if values else None
    errors = []
    if exit_code != 0:
        errors.append(f"Process exit {exit_code}")
    if (len(starts) != 1 or starts[0].get("origin") != origin or
            starts[0].get("first_sample") != 0 or starts[0].get("sectors") != blocks or
            stop_inputs_frame is None or starts[0].get("frame", 0) <= stop_inputs_frame):
        errors.append("002AM did not start once from its own origin after all route inputs stopped")
    # Native guest timing can issue its original Mute after the last complete
    # source block and before the transport's next padding/end tick. The exact
    # source count and complete flag distinguish that ending from a cut-off;
    # an operator close must never substitute for the natural ending.
    if (len(ends) != 1 or ends[0].get("reason") not in ("complete", "Mute") or
            ends[0].get("complete") != 1 or ends[0].get("consumed") != blocks or
            ends[0].get("expected") != blocks or ends[0].get("frames") != frames):
        errors.append("002AM completion differs from the accepted full source")
    expected_transport = {"raw_read_attempts": 0, "data_dma_attempts": 0, "fifo_attempts": 0}
    if transport != [expected_transport]:
        errors.append("Native transport diagnostics missing or nonzero")
    if not events or any(event.get("native") != 1 for event in events):
        errors.append("Non-native or missing voice events")
    if any(event.get("name") == "058CS" for event in events):
        errors.append("Adjacent-cue leak 058CS observed")
    if any(metrics[key] not in (None, 0) for key in ("decode_failed", "data_overrun", "cd_dropped", "host_fail")):
        errors.append("Source decoder, CD delivery, or host device failure")
    if not speech_audio["passed"]:
        errors.append("002AM-specific decoded/mixed audio growth or its bracketing measurements missing")
    if "Native playback failed:" in log:
        errors.append("Native playback fatal error")
    return dict(passed=not errors, errors=errors, language=language, exit_code=exit_code,
                stop_inputs_frame=stop_inputs_frame, voice_events=events,
                speech_starts=starts, speech_completions=ends,
                transport=transport, metrics_max=metrics, speech_audio=speech_audio,
                expected_002AM=dict(blocks=blocks, stereo_frames=frames, origin=origin),
                note="FAST/dummy verifies logical PCM delivery; audible output requires the separate paced Cocoa run")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--binary", type=Path, default=ROOT / "port/build/alundra2")
    parser.add_argument("--archive", type=Path, default=ARCHIVE)
    parser.add_argument("--bundle-archive", action="store_true", help="Let the packaged executable find its archive")
    parser.add_argument("--language", choices=("ja", "en"), required=True)
    parser.add_argument("--text-language", choices=("ru", "ja", "en"))
    parser.add_argument("--subtitles", type=int, choices=(0, 1, 2), default=0)
    parser.add_argument("--english-subtitle-language", type=int, choices=(0, 1, 2), default=0)
    parser.add_argument("--skip-intro", action="store_true")
    parser.add_argument("--verify-subtitles", action="store_true")
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--ir-scale", type=int, choices=(1, 2, 3, 4), default=2)
    parser.add_argument("--timeout", type=int, default=900)
    parser.add_argument("--run", action="store_true", help="Execute only after the shared heavy runtime slot is granted")
    args = parser.parse_args()
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=False)
    (out / "user").mkdir()
    (out / "user/a2settings.ini").write_text(
        f"skip_intro={int(args.skip_intro)}\nsubtitles={args.subtitles}\n"
        f"english_subtitle_language={args.english_subtitle_language}\n")
    binary, archive = args.binary.resolve(), args.archive.resolve()
    text_language = args.text_language or args.language
    overrides = dict(SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy", A2_FAST="1",
                     A2_RESOURCE_ARCHIVE=str(archive), A2_USER_DIR=str(out / "user"),
                     A2_TEXT_LANGUAGE=str(("ru", "ja", "en").index(text_language)),
                     A2_VOICE_LANGUAGE=str(("ja", "en").index(args.language)),
                     A2_IRSCALE=str(args.ir_scale), A2_WIDE="1", A2_HDUI="1", A2_FILTER="0",
                     A2_SUBTITLELOG="1", A2_SOUND="1", A2_AUDIOSTAT="1", A2_STATELOG="1", A2_AUTO="1",
                     A2_LAUNCHER="0", A2_MAXFRAMES="40000", A2_TIMEOUT=str(args.timeout),
                     A2_CONTROL_FILE=str(out / "control.txt"))
    command = [str(binary), "--boot"]
    if args.bundle_archive:
        overrides.pop("A2_RESOURCE_ARCHIVE")
    plan = dict(command=command, environment=overrides, language=args.language,
                text_language=text_language, subtitles=args.subtitles,
                english_subtitle_language=args.english_subtitle_language,
                archive_bytes=archive.stat().st_size, prepared_only=not args.run,
                intro=("Skip initial logos/intro through persisted setting" if args.skip_intro else "Natural") +
                      "; title New Game is selected with ordinary Up/Circle by A2_AUTO=1",
                tutorial="Wait for real map213/position(-890,0,-3425)/flags0, then shift tutorial_taps",
                input_stop="Clear all remaining holds on first post-tutorial EVENT checkpoint",
                boot_screenshots=dict(prospective_frames=EARLY_BOOT_CHECKPOINTS,
                                      note="Capture timing only; actual Sony/Matrix content requires visual inspection"),
                no_image_argument=True, no_guest_injection=True, no_cutscene_skip=True,
                limits=dict(max_frames=40000, timeout_seconds=args.timeout, max_tutorial_frames=13500))
    if args.run:
        plan["binary_sha256"] = hashlib.sha256(binary.read_bytes()).hexdigest()
        with archive.open("rb") as source:
            plan["archive_sha256"] = hashlib.file_digest(source, "sha256").hexdigest()
    (out / "launch.json").write_text(json.dumps(plan, indent=2) + "\n")
    write_control(out, 0, next_intro_frame(0), [])
    if not args.run:
        print(f"Prepared only: {out / 'launch.json'}")
        return
    env = {key: value for key, value in os.environ.items() if not key.startswith("A2_")}
    env.update(overrides)
    phase, first_input, stop_inputs, subtitle_frame = "intro", None, None, None
    taps, states = [], []
    current = 0
    process = None
    failure = None
    started = time.monotonic()
    with (out / "run.log").open("w") as output:
        try:
            process = subprocess.Popen(command, cwd=out, env=env, stdout=output, stderr=subprocess.STDOUT)
            while process.poll() is None:
                if time.monotonic() - started > args.timeout:
                    raise TimeoutError("Bounded native voice replay timed out")
                log = (out / "run.log").read_text(errors="replace")
                state = checkpoint(log)
                if not state or state["frame"] <= current:
                    time.sleep(.1)
                    continue
                current = state["frame"]
                states.append(dict(phase=phase, **state))
                events = cue_events(log)
                speech = [event for event in events if event["event"] == "start" and event["name"] == "002AM"]
                complete = any(event["event"] == "end" and event["name"] == "002AM" and
                               event.get("complete") == 1 for event in events)
                if phase == "intro":
                    if tutorial_ready(state):
                        first_input = current + 10
                        taps = shifted_tutorial(first_input)
                        (out / "tutorial-taps.json").write_text(json.dumps(taps, indent=2) + "\n")
                        phase = "tutorial"
                    elif current >= 22000:
                        raise RuntimeError("Natural intro did not reach the verified tutorial start")
                if phase == "tutorial":
                    if state["overlay"] == 5:
                        stop_inputs, taps, phase = current, [], "speech"
                    elif current - first_input >= 13500:
                        raise RuntimeError("Ordinary tutorial inputs did not reach the next EVENT")
                if phase == "speech" and speech:
                    if subtitle_frame is None:
                        subtitle_frame = speech[0]["frame"] + 390
                    if complete:
                        print(f"002AM complete at checkpoint {current}; requesting SDL quit", flush=True)
                        process.terminate()  # SDL handles SIGTERM as quit while the checkpoint is paused.
                        process.wait(timeout=10)
                        break
                if phase == "intro":
                    until = next_intro_frame(current)
                elif phase == "tutorial":
                    elapsed = current - first_input
                    until = min(current + 2500, first_input + 10200) if elapsed < 10200 else current + 100
                elif subtitle_frame and current < subtitle_frame:
                    until = subtitle_frame
                elif speech:
                    until = max(current + 100, speech[0]["frame"] + 4600)
                else:
                    until = current + 200
                if until >= 40000:
                    raise RuntimeError("Bounded route reached its frame ceiling before full 002AM")
                write_control(out, current, until, taps)
                (out / "checkpoints.json").write_text(json.dumps(states, indent=2) + "\n")
                print(f"{phase}: frame {current} overlay {state['overlay']} map {state['map_id']} -> {until}", flush=True)
        except (Exception, KeyboardInterrupt) as error:
            failure = f"{type(error).__name__}: {error}"
        finally:
            if process and process.poll() is None:
                process.terminate()
                try:
                    process.wait(timeout=10)
                except subprocess.TimeoutExpired:
                    process.kill()
                    process.wait(timeout=10)
    report = acceptance((out / "run.log").read_text(errors="replace"), args.language,
                        process.returncode if process else None, stop_inputs)
    report.update(binary_sha256=plan["binary_sha256"], archive_sha256=plan["archive_sha256"],
                  first_tutorial_input=first_input, subtitle_frame=subtitle_frame,
                  wall_seconds=time.monotonic() - started, checkpoints=states)
    if args.verify_subtitles:
        if args.language != "en":
            raise ValueError("Host subtitle verification requires English audio")
        catalog = json.loads((ROOT / "translations/english_voice_subtitles.json").read_text())
        clip = next(c for c in catalog["clips"] if c["name"] == "002AM")
        log = (out / "run.log").read_text()
        events = list(re.finditer(r"^subtitle: frame=(\d+) name=(\S+) ms=(\d+) text=", log, re.M))
        russian = args.english_subtitle_language == 1 or (
            args.english_subtitle_language == 0 and text_language == "ru")
        from textwrap import wrap
        seen = []
        for event in events:
            tail = log[event.end():]
            if tail.startswith("<clear>\n"):
                continue
            ms = int(event[3])
            current = next((c for c in clip["captions"] if c["start_ms"] <= ms < c["end_ms"]), None)
            if event[2] != "002AM" or current is None or args.subtitles == 2:
                report["errors"].append("Caption appeared outside the enabled 002AM source interval")
                continue
            wanted = ("\n".join(wrap(catalog["russian"]["002AM:" + str(current["start_ms"])],
                                   width=52, break_long_words=False, break_on_hyphens=False))
                      if russian else current["text"])
            if not tail.startswith(wanted + "\n") or ms - current["start_ms"] > 34:
                report["errors"].append(f"Wrong caption language/text or late onset at {ms}")
            seen.append(current["start_ms"])
        expected = [] if args.subtitles == 2 else [c["start_ms"] for c in clip["captions"]]
        if seen != expected:
            report["errors"].append("Caption sequence differs from the complete source catalog")
        report["caption_track"] = dict(language="ru" if russian else "en", setting=args.subtitles,
                                       expected=len(expected), observed=len(seen), starts_ms=seen)
        report["passed"] = not report["errors"]
    if failure:
        report["errors"].append(failure)
        report["passed"] = False
    # Preserve exact native captures; PNG files are only lossless view copies.
    report["boot_screenshots"] = []
    for frame in (*EARLY_BOOT_CHECKPOINTS, *([subtitle_frame] if subtitle_frame is not None else [])):
        bmp = out / f"user/frame_{frame:05}.bmp"
        if bmp.exists():
            from PIL import Image
            Image.open(bmp).save(bmp.with_suffix(".png"))
            if frame == subtitle_frame:
                report["subtitle_screenshot"] = str(bmp.with_suffix(".png"))
            else:
                report["boot_screenshots"].append(dict(frame=frame, path=str(bmp.with_suffix(".png"))))
    (out / "acceptance.json").write_text(json.dumps(report, indent=2) + "\n")
    print(json.dumps(dict(passed=report["passed"], errors=report["errors"], output=str(out)), indent=2))
    raise SystemExit(0 if report["passed"] else 1)


if __name__ == "__main__":
    main()
