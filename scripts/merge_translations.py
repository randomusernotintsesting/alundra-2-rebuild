#!/usr/bin/env python3
"""Merge translated batches (build/translate/out/*.json) into translations/*.json.

Usage: merge_translations.py [--force]
Only fills entries whose current "text" is empty, unless --force.
Validates everything after merging.
"""
import glob
import json
import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FILES = {"g": "grp_text.json", "p": "pack0_text.json",
         "v": "vcast_text.json", "G": "ui_text.json"}


def main():
    force = "--force" in sys.argv
    merged = {}
    for path in sorted(glob.glob(os.path.join(ROOT, "build/translate/out/*.json"))):
        merged.update(json.load(open(path, encoding="utf-8")))
    stats = {}
    conflicts = 0
    for key, fname in FILES.items():
        p = os.path.join(ROOT, "translations", fname)
        if not os.path.exists(p):
            continue
        doc = json.load(open(p, encoding="utf-8"))
        n = 0
        for eid, e in doc["entries"].items():
            if eid[0] != key or eid not in merged:
                continue
            if e.get("text") and not force and e["text"] != merged[eid]:
                conflicts += 1
                continue
            e["text"] = merged[eid]
            n += 1
        tmp = p + ".tmp"
        with open(tmp, "w", encoding="utf-8") as f:
            json.dump(doc, f, ensure_ascii=False, indent=1)
        os.replace(tmp, p)
        total = len(doc["entries"])
        done = sum(1 for e in doc["entries"].values() if e.get("text"))
        stats[fname] = f"{n} merged, {done}/{total} translated"
    for k, v in stats.items():
        print(f"{k}: {v}")
    if conflicts:
        print(f"! {conflicts} entries already had a different manual "
              "translation - kept (use --force to overwrite)")
    # archive merged batch outputs so a later merge cannot re-apply stale
    # files over newer edits (name canon, manual fixes)
    arch = os.path.join(ROOT, "build/translate/out/merged")
    os.makedirs(arch, exist_ok=True)
    for path in glob.glob(os.path.join(ROOT, "build/translate/out/*.json")):
        os.replace(path, os.path.join(arch, os.path.basename(path)))
    # final validation over everything merged
    allpath = os.path.join(ROOT, "build/translate/merged_all.json")
    json.dump(merged, open(allpath, "w", encoding="utf-8"), ensure_ascii=False)
    r = subprocess.run([sys.executable,
                        os.path.join(ROOT, "scripts/validate_translations.py"),
                        allpath], capture_output=True, text=True)
    print("validator:", "OK" if r.returncode == 0 else r.stdout[-2000:])


if __name__ == "__main__":
    main()
