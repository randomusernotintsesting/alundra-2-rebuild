"""Compare serial frozen baseline/candidate triangle throughput and pixels.

Use logs from diagnose_gpu_triangles, with at least two runs per workload.
This is a same-machine performance acceptance check, not a CTest wall timeout.
"""
import argparse
from collections import defaultdict
from pathlib import Path
import re
from statistics import median


def records(path):
    result = defaultdict(list)
    for line in path.read_text().splitlines():
        match = re.fullmatch(
            r"cmd=(\w+) small=(\d) IR4 ms=([\d.]+) native=(\w+) fine=(\w+)", line
        )
        if match:
            command, small, elapsed, native, fine = match.groups()
            result[command, small].append((float(elapsed), native, fine))
    return result


def verify(baseline, candidate):
    old, new = records(baseline), records(candidate)
    expected = {(command, small) for command in ("38", "3A", "3C", "3E") for small in ("0", "1")}
    assert old.keys() == new.keys() == expected, "missing triangle workloads"
    for key in sorted(expected):
        assert len(old[key]) >= 2 and len(new[key]) >= 2, "repeat each serial workload"
        assert len({row[1:] for row in old[key] + new[key]}) == 1, f"changed native/fine pixels: {key}"
        before, after = median(row[0] for row in old[key]), median(row[0] for row in new[key])
        improvement = 1 - after / before
        print(f"command {key[0]}, small={key[1]}: {before:.4f} -> {after:.4f} ms ({improvement:.1%} faster)")
        assert improvement >= 0.1, f"no material throughput improvement: {key}"


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("baseline", type=Path)
    parser.add_argument("candidate", type=Path)
    args = parser.parse_args()
    verify(args.baseline, args.candidate)
    print("PASS: all eight triangle workloads preserve native/fine pixels and improve median throughput by at least 10%")
