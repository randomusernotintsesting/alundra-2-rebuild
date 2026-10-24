"""Native cinema replay: ordinary inputs, private settings, no guest restore.

Prepare only unless --run is explicit. --intro-only captures the first 3000
ticks. The longer route reuses the accepted tutorial input sequence and stops
at requested caption offsets from the real 002AM cue. --skip-intros is a bounded
ordinary Start shortcut; inputs stop at the verified tutorial state, and all
tutorial holds stop on the first subsequent EVENT checkpoint.

Run original and centered modes with identical arguments, then pass the original
output to --compare-original. Comparison requires every checkpoint and full
RAM/VRAM equality before checking each fine image pixel. FAST/dummy captures
prove composition, not unlocked onscreen presentation or audible playback.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import time

from replay_native_voice import (ARCHIVE, ROOT, checkpoint, cue_events,
                                 shifted_tutorial, tutorial_ready, write_control)


class CinemaRoute:
    def __init__(self, skip_intros=False, caption_offsets=(390,)):
        if not caption_offsets or any(value <= 0 or value > 4500 for value in caption_offsets):
            raise ValueError("Caption offsets must be within 1..4500 ticks")
        self.skip_intros = skip_intros
        self.caption_offsets = tuple(sorted(set(caption_offsets)))
        self.phase = "intro"
        self.first_input = self.stop_inputs = self.speech_start = None
        self.taps = []

    def advance(self, state, events):
        current = state["frame"]
        if self.phase == "intro":
            if tutorial_ready(state):
                self.first_input = current + 10
                self.taps = shifted_tutorial(self.first_input)
                self.phase = "tutorial"
            elif current >= 22000:
                raise RuntimeError("Intro did not reach the verified tutorial state")
            elif self.skip_intros and state["overlay"] == 5:
                return current + 200, [f"{current + 1}:3:4"]
            else:
                return current + 1000, []
        if self.phase == "tutorial":
            if state["overlay"] == 5:
                self.stop_inputs, self.taps, self.phase = current, [], "captions"
            elif current - self.first_input >= 13500:
                raise RuntimeError("Ordinary tutorial inputs did not reach EVENT")
            else:
                elapsed = current - self.first_input
                until = (min(current + 2500, self.first_input + 10200)
                         if elapsed < 10200 else current + 100)
                return until, self.taps
        if current - self.stop_inputs > 6000:
            raise RuntimeError("Caption phase exceeded its bounded duration")
        speech = [event for event in events if event["event"] == "start" and event["name"] == "002AM"]
        if not speech:
            return current + 200, []
        if len(speech) != 1 or speech[0]["frame"] <= self.stop_inputs:
            raise RuntimeError("002AM did not begin once after the tutorial input stop")
        self.speech_start = speech[0]["frame"]
        until = next((self.speech_start + offset for offset in self.caption_offsets
                      if self.speech_start + offset > current), None)
        return until, []


def inspect_subtitles(ram):
    """Read output evidence only; never used to modify or resume guest memory."""
    # These fields do not include GPU state. In particular, attract mode can
    # have the same RAM markers while using a different display region.
    result = dict(ram_contract=False, line_rows=[], glyphs=0, bounds=None)
    if len(ram) < 0xACBFC:
        return result
    word = lambda offset: struct.unpack_from("<I", ram, offset)[0]
    half = lambda offset: struct.unpack_from("<h", ram, offset)[0]
    result.update(overlay=word(0x811D8), event_active=word(0x79E9C),
                  parent=word(0xACBF8), font_mode=word(0x640F0))
    if result["overlay"] != 5 or result["event_active"] != 1 or word(0x65A00) > 168:
        return result

    def valid_parent(pointer):
        offset = pointer & 0x1FFFFFFF
        return (pointer & 0xE0000000 in (0, 0x80000000, 0xA0000000) and
                0x65600 <= offset < 0x65A00 and (offset - 0x65600) % 32 == 0 and
                half(offset + 16) == 0 and half(offset + 18) == 174)

    if result["parent"] and (not valid_parent(result["parent"]) or result["font_mode"]):
        return result
    boxes = []
    for index in range(word(0x65A00)):
        node = 0x64100 + 32 * index
        state = half(node)
        if not state:
            continue
        x, y, _, measured_h, width, height = struct.unpack_from("<hhhhhh", ram, node + 12)
        if (state not in (1, 2, 3) or result["font_mode"] or
                not valid_parent(word(node + 28)) or not 0 <= width <= 320 or
                height != 16 or measured_h != 16 or (width and y not in (174, 190))):
            return result
        if width:
            boxes.append((x, y, x + width, y + height))
    result.update(ram_contract=True, glyphs=len(boxes), line_rows=sorted({box[1] for box in boxes}))
    if boxes:
        result["bounds"] = [min(box[0] for box in boxes), min(box[1] for box in boxes),
                            max(box[2] for box in boxes), max(box[3] for box in boxes)]
    return result


def compare_picture(original, candidate, centered, gameplay=False, reference_gameplay=False):
    """Literal independent source/target bounds, including all fine pixels."""
    from PIL import Image, ImageChops
    original, candidate = original.convert("RGB"), candidate.convert("RGB")
    if centered and (gameplay or reference_gameplay):
        return dict(passed=False, error="Cinematic and gameplay layouts cannot both apply")
    if reference_gameplay and not gameplay:
        return dict(passed=False, error="Cropped reference requires explicit matching gameplay mode")
    if gameplay:
        width, height = original.size
        scale = width // 320
        source_height = 216 if reference_gameplay else 240
        if (scale not in (1, 2, 3, 4) or width != 320 * scale or
                height != source_height * scale or candidate.size != (width, 216 * scale)):
            return dict(passed=False, error="Unsupported gameplay source/target dimensions")
        expected = original if reference_gameplay else original.crop((0, 12 * scale, width, 228 * scale))
        bounds = ImageChops.difference(expected, candidate).getbbox()
        return dict(passed=bounds is None, changed_bounds=bounds, centered=False,
                    gameplay_canvas=True, reference_gameplay_canvas=reference_gameplay,
                    scale=scale, compared_pixels=width * 216 * scale)
    if original.size != candidate.size:
        return dict(passed=False, error="Capture dimensions differ")
    width, height = original.size
    canonical = (width % 320 == 0 and height == width // 320 * 240 and
                 width // 320 in (1, 2, 3, 4))
    if centered and not canonical:
        return dict(passed=False, error="Unsupported canonical capture dimensions")
    scale = width // 320 if canonical else None
    expected = original
    if centered:
        expected = Image.new("RGB", original.size)
        expected.paste(original.crop((0, 12 * scale, width, 184 * scale)), (0, 34 * scale))
        expected.paste(original.crop((0, 186 * scale, width, 218 * scale)), (0, 207 * scale))
    bounds = ImageChops.difference(expected, candidate).getbbox()
    return dict(passed=bounds is None, changed_bounds=bounds, centered=centered,
                scale=scale, compared_pixels=width * height)


def compare_runs(original_dir, candidate_dir):
    from PIL import Image
    original = json.loads((original_dir / "acceptance.json").read_text())
    candidate = json.loads((candidate_dir / "acceptance.json").read_text())
    errors, rows = [], []
    def capture_passed(report):
        if "capture_passed" in report:
            return report["capture_passed"] and not report.get("errors")
        # Legacy reports folded the later comparison into `passed`. Recover
        # only the specific successful-capture/failed-comparison combination.
        return report["passed"] or (report.get("comparison_passed") is False and
                                    report.get("errors") == [] and report.get("exit_code") == 0)
    if not capture_passed(original) or not capture_passed(candidate):
        errors.append("One of the native runs did not meet its capture contract")
    if any(row["centered"] for row in original["captures"]):
        errors.append("Reference run did not use original presentation")
    before_controls = {path.name: path.read_text() for path in original_dir.glob("control-*.txt")}
    after_controls = {path.name: path.read_text() for path in candidate_dir.glob("control-*.txt")}
    if before_controls != after_controls:
        errors.append("Ordinary control sequences differ")
    if original["checkpoints"] != candidate["checkpoints"]:
        errors.append("Checkpoint state/route sequences differ")
    before_captures = {row["frame"]: row for row in original["captures"]}
    before_frames = set(before_captures)
    after_frames = {row["frame"] for row in candidate["captures"]}
    if before_frames != after_frames:
        errors.append("Checkpoint frame sets differ")
    for capture in candidate["captures"]:
        frame = capture["frame"]
        if frame not in before_frames:
            continue
        stem = f"{frame:05}"
        equality = {kind: ((original_dir / f"user/{kind}_{stem}.bin").read_bytes() ==
                           (candidate_dir / f"user/{kind}_{stem}.bin").read_bytes())
                    for kind in ("ram", "vram")}
        with Image.open(original_dir / f"user/frame_{stem}.bmp") as before:
            with Image.open(candidate_dir / f"user/frame_{stem}.bmp") as after:
                pixels = compare_picture(before, after, capture["centered"],
                                         capture.get("gameplay_canvas", False),
                                         before_captures[frame].get("gameplay_canvas", False))
        row = dict(frame=frame, **equality, pixels=pixels)
        rows.append(row)
        if not all(equality.values()) or not pixels["passed"]:
            errors.append(f"State or complete pixel comparison failed at {frame}")
    if not rows:
        errors.append("No paired captures")
    return dict(passed=not errors, errors=errors, captures=rows)


def centered_at(log, frame):
    states = [(int(at), int(centered)) for at, centered in
              re.findall(r"cinema: frame=(\d+) centered=([01])", log) if int(at) <= frame]
    return bool(states[-1][1]) if states else False


def gameplay_canvas_at(log, frame):
    states = [(int(at), bool(re.search(r"\bgameplay_canvas=1\b", rest))) for at, rest in
              re.findall(r"cinema: frame=(\d+) centered=[01]([^\n]*)", log) if int(at) <= frame]
    return states[-1][1] if states else False


def expanded_at(log, frame):
    states = [(int(at), bool(re.search(r"\bexpanded=1\b", rest))) for at, rest in
              re.findall(r"cinema: frame=(\d+) centered=[01]([^\n]*)", log) if int(at) <= frame]
    return states[-1][1] if states else False


def display_at(log, frame):
    """Observed GPU display diagnostics before this actual paused checkpoint."""
    current = None
    for line in log.splitlines():
        if line.startswith("disp: "):
            values = re.findall(r"\b(x|y|w|h|vlines|y1|on)=(-?\d+)", line)
            current = {key: int(value) for key, value in values}
        state = checkpoint(line)
        if state and state["frame"] >= frame:
            break
    return current


def caption_pixels(image, centered, display):
    """Actual nonblack caption ink, not only allocated/fading RAM glyphs."""
    image = image.convert("RGB")
    scale = image.width // 320
    if not scale or image.size != (320 * scale, 240 * scale):
        return dict(visible=False, bounds=None)
    if centered:
        top = 207
    elif (display and display.get("h") == 216 and display.get("y1") == 28 and
          display.get("w") == 320 and display.get("on") == 1):
        top = 186
    else:
        # Do not guess the subtitle destination for a noncanonical display.
        return dict(visible=False, bounds=None)
    box = image.crop((0, top * scale, image.width, (top + 32) * scale)).getbbox()
    return dict(visible=box is not None,
                bounds=[box[0], box[1] + top * scale, box[2], box[3] + top * scale] if box else None)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--binary", type=Path, default=ROOT / "port/build/alundra2")
    parser.add_argument("--archive", type=Path, default=ARCHIVE)
    parser.add_argument("--language", choices=("ru", "ja", "en"), required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--ir-scale", type=int, choices=(1, 2, 3, 4), default=1)
    parser.add_argument("--original", action="store_true")
    parser.add_argument("--voice", choices=("ja","en"), default="ja")
    parser.add_argument("--subtitles", choices=("auto","on","off"), default="on")
    parser.add_argument("--require-expanded", action="store_true",
                        help="Require real logged expanded output with actual native subtitle ink")
    parser.add_argument("--renderer-shot-frame",type=int,
                        help="Capture actual SDL output at this tick into the private output directory")
    parser.add_argument("--skip-intros", action="store_true")
    parser.add_argument("--intro-only", action="store_true")
    parser.add_argument("--caption-offsets", default="390", help="002AM-relative capture ticks, comma-separated")
    parser.add_argument("--compare-original", type=Path)
    parser.add_argument("--timeout", type=int, default=300)
    parser.add_argument("--run", action="store_true", help="Requires the shared native runtime slot")
    args = parser.parse_args()
    route = CinemaRoute(args.skip_intros, tuple(map(int, args.caption_offsets.split(","))))
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=False)
    user = out / "user"
    user.mkdir()
    (user / "a2settings.ini").write_text(f"cinema={int(not args.original)}\nshow_input_hints=0\nfullscreen=0\nsubtitles={dict(auto=0,on=1,off=2)[args.subtitles]}\n")
    binary, archive = args.binary.resolve(), args.archive.resolve()
    overrides = dict(SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy", A2_FAST="1",
                     A2_RESOURCE_ARCHIVE=str(archive), A2_USER_DIR=str(user),
                     A2_TEXT_LANGUAGE=str(("ru", "ja", "en").index(args.language)),
                     A2_VOICE_LANGUAGE=str(("ja","en").index(args.voice)), A2_IRSCALE=str(args.ir_scale), A2_WIDE="1",
                     A2_HDUI="1", A2_FILTER="1", A2_SOUND="1", A2_STATELOG="1",
                     A2_CINEMALOG="1", A2_HUD_LOG="1", A2_DISPLOG="1", A2_AUTO="1", A2_LAUNCHER="0",
                     A2_MAXFRAMES="40000", A2_TIMEOUT=str(args.timeout),
                     A2_CONTROL_FILE=str(out / "control.txt"))
    if args.renderer_shot_frame is not None:
        if not 1<=args.renderer_shot_frame<40000:raise ValueError("Renderer shot tick must be within1..39999")
        overrides.update(A2_UISHOT=str(args.renderer_shot_frame),
                         A2_UISHOT_PATH=str(out/f"renderer_{args.renderer_shot_frame:05}.bmp"))
    command = [str(binary), "--boot"]
    plan = dict(command=command, environment=overrides, text_language=args.language,
                voice_language=args.voice, subtitles=args.subtitles, cinema=int(not args.original), prepared_only=not args.run,
                skip_intros=args.skip_intros, intro_only=args.intro_only,
                caption_offsets=route.caption_offsets, no_guest_injection=True,
                user_settings=str(user / "a2settings.ini"), no_seed_or_ram_restore=True)
    if args.run:
        plan["binary_sha256"] = hashlib.sha256(binary.read_bytes()).hexdigest()
        with archive.open("rb") as source:
            plan["archive_sha256"] = hashlib.file_digest(source, "sha256").hexdigest()
    (out / "launch.json").write_text(json.dumps(plan, indent=2) + "\n")
    write_control(out, 0, 1000, [])
    if not args.run:
        print(f"Prepared only: {out / 'launch.json'}")
        return
    env = {key: value for key, value in os.environ.items()
           if not key.startswith(("A2_", "SDL_", "DYLD_"))}
    env.update(overrides)
    states, captures, failure, process = [], [], None, None
    current, done = 0, False
    started = time.monotonic()
    with (out / "run.log").open("w") as output:
        try:
            process = subprocess.Popen(command, cwd=out, env=env, stdout=output, stderr=subprocess.STDOUT)
            while process.poll() is None:
                if time.monotonic() - started > args.timeout:
                    raise TimeoutError("Bounded cinema replay timed out")
                log = (out / "run.log").read_text(errors="replace")
                state = checkpoint(log)
                if not state or state["frame"] <= current:
                    time.sleep(.1)
                    continue
                current = state["frame"]
                states.append(dict(phase=route.phase, **state))
                ram_path = user / f"ram_{current:05}.bin"
                capture = dict(frame=current, centered=centered_at(log, current),
                               expanded=expanded_at(log,current),
                               gameplay_canvas=gameplay_canvas_at(log, current),
                               **inspect_subtitles(ram_path.read_bytes()))
                capture["display"] = display_at(log, current)
                from PIL import Image
                with Image.open(user / f"frame_{current:05}.bmp") as picture:
                    capture["caption_pixels"] = caption_pixels(picture, capture["centered"], capture["display"])
                if capture["expanded"]:
                    # Expanded scene pixels alone must not qualify as text.
                    # The authoritative native band still contains glyphs on black.
                    vram=(user/f"vram_{current:05}.bin").read_bytes()
                    by=capture["display"]["y"]
                    ink=sum(bool(struct.unpack_from("<H",vram,((by+y)*1024+x)*2)[0]&0x7fff)
                            for y in range(174,206) for x in range(320))
                    capture["native_caption_ink_pixels"]=ink
                    capture["caption_pixels"]["visible"] &= ink>0
                captures.append(capture)
                if args.intro_only:
                    until, taps = (current + 1000 if current < 3000 else None), []
                else:
                    until, taps = route.advance(state, cue_events(log))
                (out / "checkpoints.json").write_text(json.dumps(states, indent=2) + "\n")
                if route.taps and not (out / "tutorial-taps.json").exists():
                    (out / "tutorial-taps.json").write_text(json.dumps(route.taps, indent=2) + "\n")
                print(f"{route.phase}: frame {current} overlay {state['overlay']} "
                      f"lines {capture['line_rows']} centered={capture['centered']} -> {until}", flush=True)
                if until is None:
                    done = True
                    process.terminate()  # Owned SDL process, paused at its control checkpoint.
                    process.wait(timeout=10)
                    break
                if until >= 40000:
                    raise RuntimeError("Cinema route exceeded its 40000-tick ceiling")
                write_control(out, current, until, taps)
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
    errors = [failure] if failure else []
    if not done or not process or process.returncode != 0:
        errors.append("Route did not finish with controlled SDL exit0")
    eligible = [row for row in captures if row["ram_contract"]]
    captions = [row for row in eligible if row["line_rows"] and row["caption_pixels"]["visible"]]
    feature_verified = any(row["centered"] for row in captions)
    expect_subtitles=args.subtitles=="on" or (args.subtitles=="auto" and not(args.language=="en" and args.voice=="en"))
    native_captions=[row for row in eligible if row["line_rows"]]
    if not expect_subtitles and captions:
        errors.append("Subtitles remain visible despite selected policy")
    if not eligible or (not args.intro_only and not (captions if expect_subtitles else native_captions)):
        errors.append("Required actual cinematic/caption capture was not reached")
    if expect_subtitles and not args.original and not args.intro_only and not feature_verified:
        errors.append("No actual centered frame with visible subtitle pixels was captured")
    if args.require_expanded and not any(row["expanded"] for row in captions):
        errors.append("No actual expanded frame with native subtitle ink was captured")
    if args.original and any(row["centered"] for row in captures):
        errors.append("Original presentation setting was not honored")
    log = (out / "run.log").read_text(errors="replace")
    transport = re.findall(r"nativecd: ([^\n]+)", log)
    if transport != ["raw_read_attempts=0 data_dma_attempts=0 fifo_attempts=0"]:
        errors.append("Missing or nonzero native transport diagnostics")
    report = dict(passed=not errors, capture_passed=not errors, errors=errors, wall_seconds=time.monotonic() - started,
                  exit_code=process.returncode if process else None, checkpoints=states, captures=captures,
                  first_tutorial_input=route.first_input, stop_inputs_frame=route.stop_inputs,
                  speech_start=route.speech_start, observed_line_counts=sorted({len(row["line_rows"]) for row in eligible}),
                  visible_caption_line_counts=sorted({len(row["line_rows"]) for row in captions}),
                  centered_caption_feature_verified=feature_verified,
                  expanded_caption_feature_verified=any(row["expanded"] for row in captions),
                  scope="attract/fallback capture" if args.intro_only else "subtitled cinematic framing",
                  note="FAST/dummy verifies native composition; no audible or unlocked desktop claim")
    from PIL import Image
    for capture in eligible:
        bmp = user / f"frame_{capture['frame']:05}.bmp"
        with Image.open(bmp) as source:
            source.save(bmp.with_suffix(".png"))
    (out / "acceptance.json").write_text(json.dumps(report, indent=2) + "\n")
    if args.compare_original:
        comparison = compare_runs(args.compare_original.resolve(), out)
        (out / "comparison.json").write_text(json.dumps(comparison, indent=2) + "\n")
        report["comparison_passed"] = comparison["passed"]
        report["passed"] = report["passed"] and comparison["passed"]
        (out / "acceptance.json").write_text(json.dumps(report, indent=2) + "\n")
    print(json.dumps(dict(passed=report["passed"], errors=errors, output=str(out)), indent=2))
    raise SystemExit(0 if report["passed"] else 1)


if __name__ == "__main__":
    main()
