"""Run sequential isolated ship replays and verify live precision provenance.

The default is metadata/trace acceptance only. --fine-raster instead captures
the experimental subpixel output, requiring unchanged native state and a
changed display. Neither mode establishes that every scene seam is fixed.
Game input uses cabin_taps only.
"""
import argparse
import hashlib
import json
import re
import shutil
import subprocess
import sys
import time
from pathlib import Path

from PIL import Image
from replay_routes import cabin_taps

ROOT = Path(__file__).resolve().parents[2]
TARGETS = {
    "retained_modelcap_line7": [(153, 67), (179, 51), (181, 84), (208, 67)],
    "retained_modelcap_line9": [(124, 84), (153, 67), (152, 104), (181, 84)],
    "retained_modelcap_line31": [(208, 67), (228, 78), (152, 104), (188, 107)],
}
FAR_TRIANGLE_TARGETS = {
    "retained_model_801AEC88_face33": [(152, 149), (181, 151), (185, 162)],
}


def sha256(path):
    with path.open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def physical(address):
    address &= 0x1FFFFFFF
    return address & 0x1FFFFF if address < 0x800000 else address


def compare_captures(output, frame, fine_raster=False):
    comparisons = {}
    for name in (f"ram_{frame:05}.bin", f"vram_{frame:05}.bin", f"frame_{frame:05}.bmp"):
        off, on = output / "off/user" / name, output / "on/user" / name
        comparison = {"off_sha256": sha256(off), "on_sha256": sha256(on), "bytes": off.stat().st_size}
        comparison["identical"] = comparison["off_sha256"] == comparison["on_sha256"]
        comparisons[name] = comparison
        if name.endswith(".bin"):
            assert comparison["identical"], f"Precision changed native artifact {name}"
        elif fine_raster:
            assert not comparison["identical"], "Experimental fine display is unexpectedly unchanged"
        else:
            assert comparison["identical"], f"Metadata changed display artifact {name}"
    return comparisons


def parsed_trace(path):
    events, primitives = [], []
    current = None
    for number, line in enumerate(path.read_text().splitlines(), 1):
        match = re.match(r"world-precision f=(\d+) (\S+) (.*)", line)
        if not match:
            continue
        frame, stage, rest = match.groups()
        event = dict(re.findall(r"(\w+)=([^\s]+)", rest))
        event.update(frame=int(frame), stage=stage, line=number, miss=" miss" in line)
        for field in ("projection", "generation", "consumer", "complete", "object",
                      "code_version", "code_valid", "draw_x", "draw_y", "disp_x", "disp_y",
                      "x", "y", "w", "h"):
            if field in event:
                event[field] = int(event[field])
        for field in ("pc", "addr", "src", "word", "producer", "code_hash", "context", "scratch"):
            if field in event:
                event[field] = int(event[field], 16)
        events.append(event)
        if stage == "primitive":
            current = dict(event, vertices=[])
            primitives.append(current)
        elif stage == "consume":
            if current is None:
                raise AssertionError("Consumer word has no primitive sequence")
            current["vertices"].append(event)
    return events, primitives


def trace_proof(path, checkpoint, *, include_triangle=False):
    events, primitives = parsed_trace(path)
    sequence = [p["consumer"] for p in primitives]
    assert sequence and sequence == sorted(set(sequence)), "Missing/non-monotonic consumer sequence"
    displays = [e for e in events if e["stage"] == "display" and e["frame"] == checkpoint]
    assert len(displays) == 1, f"Expected one actual present display origin at frame {checkpoint}"
    display = displays[0]
    good = [e for e in events if not e["miss"]]
    proofs = {}
    targets = {**TARGETS, **FAR_TRIANGLE_TARGETS} if include_triangle else TARGETS
    for target, points in targets.items():
        words = [((y & 65535) << 16) | (x & 65535) for x, y in points]
        matches = [p for p in primitives if p["frame"] <= checkpoint and p["line"] < display["line"]
                   and p.get("draw_x") == display["x"]
                   and p.get("draw_y") == display["y"]
                   and [v.get("word") for v in p["vertices"]] == words]
        assert matches, f"No complete earlier live consumer for displayed {target} at frame {checkpoint}"
        primitive = matches[-1]
        assert primitive["complete"] == 1, f"Latest displayed submission fell back: {target}"
        assert len({v["generation"] for v in primitive["vertices"]}) == 1
        vertices = []
        for vertex in primitive["vertices"]:
            projection = vertex["projection"]
            packets = [e for e in good if e["stage"] == "packet"
                       and e["projection"] == projection and e["generation"] == vertex["generation"]
                       and physical(e["addr"]) == physical(vertex["addr"])
                       and e["word"] == vertex["word"] and e["line"] < vertex["line"]]
            assert packets, f"No packet producer for {target}: {vertex}"
            packet = packets[-1]
            records = [e for e in good if e["stage"] == "record" and e["projection"] == projection
                       and physical(e["addr"]) == physical(packet["src"])
                       and e["word"] == packet["word"] and e["line"] < packet["line"]]
            assert records, f"No vertex-record producer for {target}: {packet}"
            record = records[-1]
            reads = [e for e in good if e["stage"] == "mfc2" and e["projection"] == projection
                     and e["word"] == record["word"] and e["line"] < record["line"]]
            projects = [e for e in good if e["stage"] == "project" and e["projection"] == projection
                        and e["word"] == record["word"] and e["line"] < record["line"]]
            assert reads and projects, f"Missing GTE/MFC2 origin for {target}: {record}"
            assert projects[-1]["pc"] == vertex["producer"] == 0x80010D4C
            assert reads[-1]["pc"] == 0x80010D98 and record["pc"] == 0x80010DAC
            assert projects[-1]["line"] < reads[-1]["line"] < record["line"] < packet["line"] < vertex["line"]
            assert physical(vertex["src"]) == physical(record["addr"])
            vertices.append({"native_xy": points[len(vertices)], "projection_id": projection,
                             "record_generation": record["generation"],
                             "packet_generation": packet["generation"],
                             "record_address": f'{record["addr"]:08X}',
                             "packet_xy_address": f'{vertex["addr"]:08X}',
                             "lines": {"project": projects[-1]["line"], "mfc2": reads[-1]["line"],
                                       "record": record["line"], "packet": packet["line"],
                                       "consume": vertex["line"]}})
        assert len({v["record_generation"] for v in vertices}) == 1, "Mixed source objects"
        proofs[target] = {"consumer": primitive["consumer"], "frame": primitive["frame"],
                          "draw_origin": [primitive["draw_x"], primitive["draw_y"]],
                          "primitive_line": primitive["line"], "vertices": vertices}
    return {"targets": proofs, "display": display, "primitive_count": len(primitives),
            "complete_count": sum(p["complete"] for p in primitives),
            "trace_events": len(events)}


def replay(args, output, binary, enabled):
    run = output / ("on" if enabled else "off")
    run.mkdir()
    user = run / "user"
    assert not user.exists(), "Replay user directory must start fresh"
    control = run / "control.txt"
    control.write_text(f"{args.frame}\n")
    command = [sys.executable, str(ROOT / "port/tools/replay.py"), "--binary", str(binary),
               "--disc", str(args.data.resolve() / "disc"), "--image", str(args.data.resolve() / "disc.bin"),
               "--output", str(run), "--user-dir", str(user), "--auto", "new",
               "--frames", str(args.frame + 3), "--every", "0", "--timeout", str(args.timeout),
               "--ir-scale", "3", "--control-file", str(control), "--primitive-log", str(args.frame - 1)]
    for tap in cabin_taps():
        first, rest = tap.split(":", 1)
        shifted = int(first) + args.offset
        assert shifted > 0
        command.extend(("--tap", f"{shifted}:{rest}"))
    if enabled:
        # Include both OT buffers' producers before the captured display.
        command.extend(("--world-precision", "--world-trace", str(args.frame - 5), str(args.frame + 2)))
        if args.fine_raster:
            command.append("--world-raster")
    print(f"START world {'ON' if enabled else 'OFF'}: {run}", flush=True)
    started = time.monotonic()
    process = subprocess.Popen(command)
    deadline = started + args.timeout + 10
    try:
        vram = user / f"vram_{args.frame:05}.bin"
        while not vram.exists() or vram.stat().st_size != 1024 * 512 * 2:
            if process.poll() is not None:
                raise RuntimeError(f"Replay exited {process.returncode} before checkpoint {args.frame}")
            if time.monotonic() > deadline:
                raise TimeoutError(f"Missing checkpoint {args.frame}")
            time.sleep(0.1)
        image = Image.open(user / f"frame_{args.frame:05}.bmp").convert("RGB")
        image.save(run / "ship.png")
        resume = control.with_suffix(".next")
        resume.write_text(f"{args.frame + 4}\n")
        resume.replace(control)
        result = process.wait(timeout=max(1, deadline - time.monotonic()))
        assert result == 0, f"Replay failed: {result}"
        print(f"END world {'ON' if enabled else 'OFF'}: {time.monotonic() - started:.1f}s", flush=True)
        return {"command": command, "exit_code": result, "elapsed_seconds": time.monotonic() - started,
                "frame_size": image.size, "log": str(run / "run.log")}
    finally:
        if process.poll() is None:
            process.terminate()
            process.wait(timeout=5)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--binary", type=Path, required=True)
    parser.add_argument("--expected-sha256", required=True)
    parser.add_argument("--data", type=Path, default=ROOT / "port/build/verification/full-menu-v6")
    parser.add_argument("--frame", type=int, default=16999)
    parser.add_argument("--offset", type=int, default=-1001)
    parser.add_argument("--timeout", type=int, default=900)
    parser.add_argument("--fine-raster", action="store_true",
                        help="Capture experimental subpixel rendering, not metadata-only Gate1")
    parser.add_argument("--include-far-triangle", action="store_true",
                        help="Also prove all three vertices of the original adjacent far-triangle face33")
    args = parser.parse_args()
    assert sha256(args.binary) == args.expected_sha256, "Frozen binary identity changed"
    output = args.output.resolve()
    output.mkdir(parents=True, exist_ok=False)
    binary = output / "alundra2"
    shutil.copy2(args.binary, binary)
    manifest = {"binary_sha256": sha256(binary), "data": str(args.data.resolve()),
                "route": "cabin_taps", "offset": args.offset, "checkpoint": args.frame,
                "runs": {}, "mode": "fine_capture" if args.fine_raster else "metadata_gate1",
                "include_far_triangle": args.include_far_triangle,
                "gate1_pass": False, "fine_capture_pass": False}
    try:
        for enabled in (False, True):
            manifest["runs"]["on" if enabled else "off"] = replay(args, output, binary, enabled)
        manifest["comparisons"] = compare_captures(output, args.frame, args.fine_raster)
        manifest["proof"] = trace_proof(output / "on/run.log", args.frame,
                                        include_triangle=args.include_far_triangle)
        vertex_count = sum(len(p["vertices"]) for p in manifest["proof"]["targets"].values())
        if args.fine_raster:
            manifest["fine_capture_pass"] = True
            print(f"PASS fine capture: {vertex_count} target vertices linked; native RAM/VRAM identical; display changed. Visual/seam acceptance still required.", flush=True)
        else:
            manifest["gate1_pass"] = True
            print(f"PASS Gate1: all {vertex_count} live target vertices linked; native RAM/VRAM and captured fine display identical", flush=True)
    finally:
        (output / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")


if __name__ == "__main__":
    main()
