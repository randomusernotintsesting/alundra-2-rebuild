#!/usr/bin/env python3
"""Read existing native/resource logs; never launch or control a process."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import statistics


def fields(line):
    return {key: float(value) for key, value in
            re.findall(r"([A-Za-z_][A-Za-z_0-9/]*)=([0-9]+(?:\.[0-9]+)?)", line)}


def pause_frames(log):
    return [int(value) for value in re.findall(r"^control: paused frame=(\d+)", log, re.M)]


def timing_windows(log, first, last):
    """Require complete consecutive 60-tick windows with no checkpoint pause.

    main.c calls a2_phase_frame before replay_checkpoint. A pause at frame P
    can affect the following timing interval, not the one already emitted at P.
    """
    if first <= 0 or last < first or first % 60 != 1 or last % 60:
        raise ValueError("Expected complete aligned 60-tick bounds")
    pauses, rows = pause_frames(log), []
    for line in log.splitlines():
        if not line.startswith("phasestat: first_frame="):
            continue
        row = fields(line)
        if not first <= row["first_frame"] <= row["frame"] <= last:
            continue
        if row["frames"] != 60 or row["frame"] - row["first_frame"] != 59 or row["wall_ms"] <= 0:
            raise ValueError("Invalid or partial timing window")
        if any(row["first_frame"] - 1 <= pause < row["frame"] for pause in pauses):
            raise ValueError("Control capture/pause intersects selected timing window")
        rows.append(row)
    expected = list(range(first, last + 1, 60))
    if [row["first_frame"] for row in rows] != expected:
        raise ValueError("Missing, duplicated or out-of-order selected timing windows")
    return rows


def summarize_windows(rows):
    wall = sum(row["wall_ms"] for row in rows)
    ticks = sum(row["frames"] for row in rows)
    if not rows or wall <= 0:
        raise ValueError("No positive timing interval")
    result = dict(window_count=len(rows), first_frame=int(rows[0]["first_frame"]),
                  last_frame=int(rows[-1]["frame"]), measured_seconds=wall / 1000,
                  logical_ticks=ticks, logical_ticks_per_second=ticks * 1000 / wall,
                  process_cpu_percent=sum(row["process_cpu_ms"] for row in rows) / wall * 100,
                  main_thread_cpu_percent=sum(row["cpu_ms"] for row in rows) / wall * 100,
                  gpu_render_max_ms=max(row["gpu_max_wall_ms"] for row in rows))
    for name, key in (("wall", "wall_ms"), ("gpu", "gpu_wall_ms"),
                      ("main_cpu", "cpu_ms"), ("process_cpu", "process_cpu_ms"),
                      ("compose", "compose_wall_ms")):
        values = [row[key] for row in rows]
        result[name + "_ms_per_60ticks_mean"] = statistics.mean(values)
        result[name + "_ms_per_60ticks_median"] = statistics.median(values)
    return result


def tick_counts(log, first, last):
    """Retain tickstat counts only when the entire uncertain interval is inside.

    tickstat lacks frame and exact elapsed time. Adjacent stamped records bound
    its endpoint; these counts must not be mislabeled as exact per-second rates.
    """
    lines = log.splitlines()
    stamps = []
    for line in lines:
        match = re.match(r"(?:phaseframe|phasestat|presentstat|state|control: paused|presentcatchup):? .*?\bframe=(\d+)", line)
        stamps.append(int(match[1]) if match else None)
    following, next_frame = [], None
    for stamp in reversed(stamps):
        if stamp is not None:
            next_frame = stamp
        following.append(next_frame)
    following.reverse()
    pauses, previous, rows = pause_frames(log), None, []
    for index, line in enumerate(lines):
        if stamps[index] is not None:
            previous = stamps[index]
        if not line.startswith("tickstat:") or previous is None or following[index] is None:
            continue
        counts, upper = fields(line), following[index]
        lower = previous
        start = lower - int(counts["frames/s"]) + 1
        if lower > upper or start < first or upper > last or any(start - 1 <= p < upper for p in pauses):
            continue
        rows.append(dict(counts, end_frame_bounds=[lower, upper], earliest_start_frame=start))
    return rows


def analyze_run(path, resources_required=True):
    path = path.resolve()
    result = json.loads((path / "result.json").read_text())
    if not result.get("completed") or result.get("exit_code") != 0:
        raise ValueError(str(path) + ": native route did not complete successfully")
    last = result["checkpoints"][-1]
    if last["map_id"] != 11 or last.get("map") != "d80_" or last["flags"]:
        raise ValueError(str(path) + ": final checkpoint is not ordinary storm gameplay")
    first, end = result["profile_first_frame"], result["profile_last_frame"]
    log_bytes = (path / "run.log").read_bytes()
    log = log_bytes.decode(errors="replace")
    rows = timing_windows(log, first, end)
    ticks = tick_counts(log, first, end)
    environment = json.loads((path / "environment.json").read_text())
    resources = None
    if (path / "resources/report.json").is_file():
        resources = json.loads((path / "resources/report.json").read_text())
        if resources.get("error") or resources.get("sample_count", 0) < 2:
            raise ValueError(str(path) + ": resource sampler failed or has no intervals")
        if result.get("pid") != resources["header"]["target"]["pid"]:
            raise ValueError(str(path) + ": sampler PID is not the route's child PID")
    elif resources_required:
        raise ValueError(str(path) + ": missing resource sampler report")
    boot = []
    for lo in range(1, 3000, 600):
        try:
            boot.append(summarize_windows(timing_windows(log, lo, lo + 599)))
        except ValueError as error:
            boot.append(dict(first_frame=lo, last_frame=lo + 599, excluded=str(error)))
    return dict(path=str(path), binary_sha256=environment["binary_sha256"],
                archive_sha256=environment["archive_sha256"], seed_sha256=environment["seed_sha256"],
                log_sha256=hashlib.sha256(log_bytes).hexdigest(),
                ir_scale=result.get("ir_scale", int(environment["env"]["A2_IRSCALE"])),
                idle_frames=result.get("idle_frames", 0),
                input_isolated=result.get("isolate_physical_gameplay_input", False),
                final_checkpoint=last, timing=summarize_windows(rows), timing_windows=rows,
                boot_windows=boot, tickstat_count_samples=ticks,
                resources=resources,
                caveats=["GPU phase is CPU software-renderer time, not hardware GPU utilization.",
                         "Tickstat reports counts over an interval of at least one second; exact rate uses phasestat wall time.",
                         "Resource storm phase includes warm-up and polling; exact native timing windows exclude checkpoint pauses.",
                         "Earlier baseline used a different host session and no added indoor idle; this is not a controlled feature A/B."])


def markdown(report):
    lines = ["# Native resource profile analysis", "",
             "Only completed ordinary storm routes and their declared complete timing windows are included.",
             "CPU 100% means one core. Memory is in MiB (1,048,576 bytes).", "",
             "| Run | IR | Ticks/s | CPU process % (exact storm) | GPU mean ms/60 ticks | GPU max ms/render | RSS sampled max MiB | Footprint sampled / lifetime peak MiB |",
             "| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |"]
    for run in ([report["baseline"]] if report.get("baseline") else []) + report["runs"]:
        t, r = run["timing"], run["resources"]
        rss = f'{r["sampled_rss_max_bytes"]/1048576:.2f}' if r else "not sampled"
        footprint = (f'{r["sampled_footprint_max_bytes"]/1048576:.2f} / '
                     f'{r["lifetime_peak_footprint_bytes"]/1048576:.2f}') if r else "not sampled"
        lines.append(f'| {Path(run["path"]).name} | {run["ir_scale"]} | {t["logical_ticks_per_second"]:.3f} | '
                     f'{t["process_cpu_percent"]:.2f} | {t["gpu_ms_per_60ticks_mean"]:.3f} | '
                     f'{t["gpu_render_max_ms"]:.3f} | {rss} | {footprint} |')
    lines += ["", "The GPU durations measure software rendering on the CPU. Tick rate is based on summed",
              "native timing windows; it is not a claim of unlocked on-screen presentation.", "",
              "The resource sampler's broader phase intervals include warm-up and polling. Per-phase",
              "CPU and memory values, exact native window rows, conservative tick-count samples and",
              "source hashes are retained in analysis.json. Baseline comparisons are observational:",
              "the historical run used a different host session and omitted the added indoor idle.", ""]
    return "\n".join(lines)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("runs", nargs="+", type=Path)
    parser.add_argument("--baseline", type=Path)
    parser.add_argument("--output", required=True, type=Path, help="Fresh analysis directory")
    args = parser.parse_args()
    report = dict(runs=[analyze_run(path) for path in args.runs],
                  baseline=analyze_run(args.baseline, False) if args.baseline else None)
    args.output.mkdir(parents=True, exist_ok=False)
    (args.output / "analysis.json").write_text(json.dumps(report, indent=2) + "\n")
    (args.output / "analysis.md").write_text(markdown(report))
    print(args.output / "analysis.md")


if __name__ == "__main__":
    main()
