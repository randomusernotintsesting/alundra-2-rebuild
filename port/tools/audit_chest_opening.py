#!/usr/bin/env python3
"""Read-only audit of a completed chest opening capture; never launches a game."""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import struct

T02_SHA = "fbbc6ed20a3fc8cf8ac69e1c1af74a8ae44d451fcfbb47302321c1182fefabf1"


def fields(line):
    return dict(word.split("=", 1) for word in line.split()[1:] if "=" in word)


def display_audit(lines, first, last):
    rows, malformed = [], []
    for line in lines:
        if not line.startswith("nativemesh-compose:"):
            continue
        r = fields(line)
        frame = int(r["frame"])
        if not first <= frame <= last:
            continue
        dy = int(r["dy"])
        if dy not in (0, 256):
            malformed.append({"frame": frame, "reason": "noncanonical source page", "dy": dy})
            continue
        page = dy // 256
        state = [int(v) for v in r[f"page{page}"].split(",")]
        roi = [int(v) for v in r[f"roi{page}"].split(",")]
        if len(state) != 5 or len(roi) != 4 or state[1] not in (0, 1):
            malformed.append({"frame": frame, "reason": "malformed selected-page state"})
            continue
        rows.append({"frame": frame, "page": page, "clear_frame": state[0],
                     "published": state[1], "pending": state[2], "roi": roi})
    missing = sorted(set(range(first, last + 1)) - {r["frame"] for r in rows})
    unpublished = [r for r in rows if not r["published"] or r["roi"][2] <= 0 or r["roi"][3] <= 0]
    return {"pass": bool(rows) and not (missing or malformed or unpublished),
            "observations": len(rows), "missing_frames": missing,
            "malformed": malformed, "unpublished": unpublished,
            "selected_pages": dict(Counter(str(r["page"]) for r in rows))}


def emission_audit(lines, registry, first, last, requested=False):
    rows = [fields(l) for l in lines if l.startswith("nativeemit:")]
    rows = [r for r in rows if first <= int(r["entry_frame"]) <= last]
    target = [r for r in rows if int(r["registry"], 16) == registry]
    def key(r):
        return tuple(r[k] for k in ("entry_frame", "dma", "caller", "part", "source_face", "layer"))
    entries = Counter(key(r) for r in target if r["phase"] == "entry")
    finals = Counter(key(r) for r in target if r["phase"] == "final")
    unfinished = [r for r in target if r["phase"] not in ("entry", "final")]
    rejected = [r for r in target if r["phase"] == "final" and
                (r["captured"] != "1" or r["owner_valid"] != "1")]
    limited = any(l.startswith("nativeemit-limit:") for l in lines)
    present = requested or bool(rows)
    return {"requested_or_present": present,
            "pass": (bool(entries) and entries == finals and not (unfinished or rejected or limited)) if present else None,
            "entries": sum(entries.values()), "finals": sum(finals.values()),
            "paired": entries == finals, "truncated": limited,
            "observed_entry_frames": sorted({int(r["entry_frame"]) for r in target}),
            "unfinished": unfinished, "uncaptured": rejected,
            "reason_counts": dict(Counter(r["reason"] for r in target if r["phase"] == "final"))}


def pose_audit(records, entity, registry, first, last):
    poses, missing, invalid, bad_source = [], [], [], []
    for r in records:
        frame = r["guest_frame"]
        if not first <= frame <= last or r["draw_object_address"] != 0x8011763C or r["shadow_pass"]:
            continue
        if not r["valid"]:
            invalid.append(frame)
            continue
        matches = [i for i in r["instances"] if i["entity_address"] == entity]
        if len(matches) != 1:
            missing.append(frame)
            continue
        i = matches[0]
        parts = sorted(i["parts"], key=lambda p: p["source_mesh_index"])
        valid = i["valid"] and i["selected_for_draw"] and i["generation_known"] and i["instance_generation"] > 0
        valid = valid and len(parts) == 2 and [p["source_mesh_index"] for p in parts] == [0, 1]
        for p in parts:
            valid = valid and p["registry_address"] == registry and p["source_key"] == "T02" and p["source_sha256"] == T02_SHA
            valid = valid and p["source_generation"] > 0 and p["valid"] and p["visible"] and not p["fallback"]
            raw = bytes.fromhex(p["raw_hex"])
            valid = valid and len(raw) == 80 and tuple(p["matrix_q12"]) == struct.unpack_from("<9h", raw, 32)
        if not valid:
            bad_source.append(frame)
            continue
        poses.append({"frame": frame, "action": i["action_id"], "generation": i["instance_generation"],
                      "source_generations": [p["source_generation"] for p in parts],
                      "body_matrix": parts[0]["matrix_q12"], "lid_matrix": parts[1]["matrix_q12"]})
    transitions = []
    for p in poses:
        if not transitions or transitions[-1]["action"] != p["action"]:
            transitions.append({"frame": p["frame"], "action": p["action"]})
    body = {tuple(p["body_matrix"]) for p in poses}
    lid = {tuple(p["lid_matrix"]) for p in poses}
    generations = sorted({p["generation"] for p in poses})
    source_generations = sorted({g for p in poses for g in p["source_generations"]})
    complete = [p["action"] for p in transitions] == [130, 132, 131]
    return {"pass": bool(poses) and complete and len(body) == 1 and len(lid) > 1 and
            len(generations) == len(source_generations) == 1 and not (missing or invalid or bad_source),
            "observations": len(poses), "transitions": transitions,
            "instance_generations": generations, "source_generations": source_generations,
            "body_matrix_count": len(body), "lid_matrix_count": len(lid),
            "invalid_main_frames": invalid, "missing_target_frames": missing, "bad_source_frames": bad_source,
            "first_pose": poses[0] if poses else None, "last_pose": poses[-1] if poses else None}


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("capture", type=Path)
    p.add_argument("--first", type=int, required=True)
    p.add_argument("--last", type=int, required=True)
    p.add_argument("--entity", type=lambda s: int(s, 0), default=0x8011A6C4)
    p.add_argument("--registry", type=lambda s: int(s, 0), default=0x801B6370)
    p.add_argument("--output", type=Path, help="New JSON output; existing files are never overwritten")
    args = p.parse_args()
    if not 0 <= args.first <= args.last <= 0xFFFFFFFF or args.last - args.first > 100000:
        p.error("require a bounded increasing guest-frame interval")
    log_path = args.capture / "run.log"
    raw = log_path.read_bytes()
    lines = raw.decode().splitlines()
    result = json.loads((args.capture / "result.json").read_text())
    launch = json.loads((args.capture / "launch.json").read_text())
    with (args.capture / "poses.jsonl").open() as f:
        poses = pose_audit((json.loads(l) for l in f), args.entity, args.registry, args.first, args.last)
    display = display_audit(lines, args.first, args.last)
    emissions = emission_audit(lines, args.registry, args.first, args.last,
                               "A2_MESH_EMIT_TRACE" in launch.get("env", {}))
    success = result.get("exit_code") == 0 and not result.get("timed_out", False)
    passed = success and display["pass"] and poses["pass"] and emissions["pass"] is not False
    report = {"pass": passed, "capture": str(args.capture.resolve()), "range": [args.first, args.last],
              "binary_sha256": result.get("binary_sha256", launch.get("binary_sha256")),
              "archive_sha256": launch.get("archive_sha256"), "log_sha256": hashlib.sha256(raw).hexdigest(),
              "process_completed": success, "display": display, "poses": poses, "emissions": emissions,
              "limits": ["Publication checks the selected source page on every requested logged presentation; aggregate counters are not used.",
                         "Missing per-frame display evidence fails this audit; it does not by itself prove a renderer fault.",
                         "Emitter completeness covers observed exact actor-emitter hooks and its declared trace window.",
                         "This read-only audit does not replace actual Cocoa image, opening/angle and same-window menu checks."]}
    if args.output:
        with args.output.open("x") as f:
            json.dump(report, f, indent=2)
            f.write("\n")
    else:
        print(json.dumps(report, indent=2))
    return 0 if passed else 1


if __name__ == "__main__":
    raise SystemExit(main())
