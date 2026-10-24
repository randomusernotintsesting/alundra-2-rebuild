#!/usr/bin/env python3
"""Read-only, bounded libproc sampler for an explicitly identified owned process.

CPU is summed over threads: 100% means one occupied CPU core. Resource rusage
times are Mach absolute ticks, converted by mach_timebase_info (not assumed ns).
No task port, privileged API, process signals, or hardware GPU counters are used.
"""
import argparse
import csv
import ctypes as C
from datetime import datetime, timezone
import errno
import json
import math
import os
from pathlib import Path
import platform
import re
import signal
import subprocess
import sys
import time


# Public SDK sys/resource.h RUSAGE_INFO_V4; preserve all intervening fields.
class RUsageInfoV4(C.Structure):
    _fields_ = [("ri_uuid", C.c_uint8 * 16)] + [("ri_" + name, C.c_uint64) for name in (
        "user_time system_time pkg_idle_wkups interrupt_wkups pageins wired_size "
        "resident_size phys_footprint proc_start_abstime proc_exit_abstime "
        "child_user_time child_system_time child_pkg_idle_wkups child_interrupt_wkups "
        "child_pageins child_elapsed_abstime diskio_bytesread diskio_byteswritten "
        "cpu_time_qos_default cpu_time_qos_maintenance cpu_time_qos_background "
        "cpu_time_qos_utility cpu_time_qos_legacy cpu_time_qos_user_initiated "
        "cpu_time_qos_user_interactive billed_system_time serviced_system_time "
        "logical_writes lifetime_max_phys_footprint instructions cycles billed_energy "
        "serviced_energy interval_max_phys_footprint runnable_time").split()]


class ProcBsdInfo(C.Structure):
    _fields_ = [(name, C.c_uint32) for name in (
        "pbi_flags pbi_status pbi_xstatus pbi_pid pbi_ppid pbi_uid pbi_gid pbi_ruid "
        "pbi_rgid pbi_svuid pbi_svgid rfu_1").split()] + [
        ("pbi_comm", C.c_char * 16), ("pbi_name", C.c_char * 32)] + [
        (name, C.c_uint32) for name in
        "pbi_nfiles pbi_pgid pbi_pjobc e_tdev e_tpgid".split()] + [
        ("pbi_nice", C.c_int32), ("pbi_start_tvsec", C.c_uint64),
        ("pbi_start_tvusec", C.c_uint64)]


class MachTimebase(C.Structure):
    _fields_ = [("numer", C.c_uint32), ("denom", C.c_uint32)]


def utc(seconds=None):
    return datetime.fromtimestamp(time.time() if seconds is None else seconds,
                                  timezone.utc).isoformat()


class MacProcessReader:
    def __init__(self, pid):
        if sys.platform != "darwin":
            raise RuntimeError("This sampler requires macOS libproc")
        self.pid = pid
        self.expected_start = self.expected_uuid = None
        self.lib = C.CDLL("/usr/lib/libproc.dylib", use_errno=True)
        self.lib.proc_pid_rusage.argtypes = [C.c_int, C.c_int, C.c_void_p]
        self.lib.proc_pid_rusage.restype = C.c_int
        self.lib.proc_pidinfo.argtypes = [C.c_int, C.c_int, C.c_uint64, C.c_void_p, C.c_int]
        self.lib.proc_pidinfo.restype = C.c_int
        self.lib.proc_pidpath.argtypes = [C.c_int, C.c_void_p, C.c_uint32]
        self.lib.proc_pidpath.restype = C.c_int
        system = C.CDLL("/usr/lib/libSystem.B.dylib")
        system.mach_timebase_info.argtypes = [C.POINTER(MachTimebase)]
        system.mach_timebase_info.restype = C.c_int
        base = MachTimebase()
        if system.mach_timebase_info(C.byref(base)) or not base.numer or not base.denom:
            raise RuntimeError("mach_timebase_info failed")
        self.numer, self.denom = base.numer, base.denom

    @staticmethod
    def _failure(name):
        code = C.get_errno() or errno.EIO
        raise OSError(code, name + ": " + os.strerror(code))

    def _bsd(self):
        info = ProcBsdInfo()
        if self.lib.proc_pidinfo(self.pid, 3, 0, C.byref(info), C.sizeof(info)) != C.sizeof(info):
            self._failure("proc_pidinfo")
        return info

    def _usage(self):
        info = RUsageInfoV4()
        if self.lib.proc_pid_rusage(self.pid, 4, C.byref(info)) != 0:
            self._failure("proc_pid_rusage")
        if info.ri_proc_exit_abstime:
            raise ProcessLookupError(errno.ESRCH, "Target has exited")
        return info

    def identity(self):
        before = self._bsd()
        usage = self._usage()
        path = C.create_string_buffer(4096)
        if self.lib.proc_pidpath(self.pid, path, len(path)) <= 0:
            self._failure("proc_pidpath")
        after = self._bsd()
        if (before.pbi_pid, before.pbi_start_tvsec, before.pbi_start_tvusec) != (
                after.pbi_pid, after.pbi_start_tvsec, after.pbi_start_tvusec):
            raise ValueError("PID changed during identity lookup")
        self.expected_start = usage.ri_proc_start_abstime
        self.expected_uuid = bytes(usage.ri_uuid).hex()
        seconds = before.pbi_start_tvsec + before.pbi_start_tvusec / 1e6
        return dict(pid=before.pbi_pid, uid=before.pbi_uid, path=os.fsdecode(path.value),
                    start_unix_seconds=seconds, start_utc=utc(seconds),
                    start_abstime=self.expected_start, executable_uuid=self.expected_uuid)

    def sample(self, phase):
        begin = time.monotonic_ns()
        info = self._usage()
        end = time.monotonic_ns()
        if self.expected_start is not None and (info.ri_proc_start_abstime != self.expected_start or
                                               bytes(info.ri_uuid).hex() != self.expected_uuid):
            raise ValueError("Target PID or executable identity changed; refusing mixed samples")
        return dict(monotonic_ns=(begin + end) // 2, timestamp_utc=utc(), phase=phase,
                    start_abstime=info.ri_proc_start_abstime,
                    user_ticks=info.ri_user_time, system_ticks=info.ri_system_time,
                    rss_bytes=info.ri_resident_size, footprint_bytes=info.ri_phys_footprint,
                    lifetime_peak_footprint_bytes=info.ri_lifetime_max_phys_footprint,
                    query_duration_ns=end - begin)


def cpu_interval(previous, current, numer, denom):
    elapsed = current["monotonic_ns"] - previous["monotonic_ns"]
    du = current["user_ticks"] - previous["user_ticks"]
    ds = current["system_ticks"] - previous["system_ticks"]
    if current["start_abstime"] != previous["start_abstime"]:
        raise ValueError("PID start time changed")
    if elapsed <= 0 or min(du, ds) < 0 or numer <= 0 or denom <= 0:
        raise ValueError("Clock/counter regression or invalid timebase")
    user, system = du * numer / denom / 1e9, ds * numer / denom / 1e9
    seconds = elapsed / 1e9
    return dict(elapsed_seconds=seconds, user_seconds=user, system_seconds=system,
                cpu_user_percent=user / seconds * 100,
                cpu_system_percent=system / seconds * 100,
                cpu_percent=(user + system) / seconds * 100,
                phase_transition=previous["phase"] != current["phase"])


def summarize(samples, numer, denom):
    phases, intervals = {}, []
    for sample in samples:
        phase = phases.setdefault(sample["phase"], dict(sample_count=0, intervals=0,
            measured_seconds=0, user_seconds=0, system_seconds=0, cpu_percent_max=None,
            sampled_rss_max_bytes=0, sampled_footprint_max_bytes=0))
        phase["sample_count"] += 1
        for source, dest in (("rss_bytes", "sampled_rss_max_bytes"),
                             ("footprint_bytes", "sampled_footprint_max_bytes")):
            phase[dest] = max(phase[dest], sample[source])
    for a, b in zip(samples, samples[1:]):
        delta = cpu_interval(a, b, numer, denom)
        intervals.append(delta)
        if delta["phase_transition"]:
            continue
        phase = phases[b["phase"]]
        phase["intervals"] += 1
        phase["measured_seconds"] += delta["elapsed_seconds"]
        phase["user_seconds"] += delta["user_seconds"]
        phase["system_seconds"] += delta["system_seconds"]
        phase["cpu_percent_max"] = max(phase["cpu_percent_max"] or 0, delta["cpu_percent"])
    for phase in phases.values():
        seconds = phase["measured_seconds"]
        phase["cpu_percent_mean"] = ((phase["user_seconds"] + phase["system_seconds"]) /
                                      seconds * 100) if seconds else None
    seconds = sum(d["elapsed_seconds"] for d in intervals)
    return dict(sample_count=len(samples), measured_seconds=seconds, phases=phases,
        transition_intervals=sum(d["phase_transition"] for d in intervals),
        cpu_percent_mean=(sum(d["user_seconds"] + d["system_seconds"] for d in intervals) /
                          seconds * 100) if seconds else None,
        sampled_rss_max_bytes=max((s["rss_bytes"] for s in samples), default=None),
        sampled_footprint_max_bytes=max((s["footprint_bytes"] for s in samples), default=None),
        lifetime_peak_footprint_bytes=max((s["lifetime_peak_footprint_bytes"] for s in samples), default=None))


def read_phase(path, fallback):
    if path is None:
        return fallback
    try:
        with Path(path).open("r", encoding="ascii") as source:
            value = source.read(130).strip()
        return value if re.fullmatch(r"[A-Za-z0-9_.-]{1,64}", value) else "unknown"
    except FileNotFoundError:
        return fallback
    except (OSError, UnicodeError):
        return "unknown"


def machine_facts():
    def run(*command):
        return subprocess.check_output(command, text=True, timeout=5).strip()
    def sysctl(key):
        return run("/usr/sbin/sysctl", "-n", key)
    return dict(architecture=platform.machine(), model=sysctl("hw.model"),
                cpu_model=sysctl("machdep.cpu.brand_string"),
                physical_cores=int(sysctl("hw.physicalcpu")),
                logical_cores=int(sysctl("hw.logicalcpu")), ram_bytes=int(sysctl("hw.memsize")),
                os_name=run("/usr/bin/sw_vers", "-productName"),
                os_version=run("/usr/bin/sw_vers", "-productVersion"),
                os_build=run("/usr/bin/sw_vers", "-buildVersion"))


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--pid", type=int, required=True, help="Explicitly owned running PID")
    parser.add_argument("--expected-path", type=Path, required=True, help="Expected executable path")
    parser.add_argument("--output", type=Path, required=True, help="New output directory")
    parser.add_argument("--phase", default="unspecified")
    parser.add_argument("--phase-file", type=Path)
    parser.add_argument("--interval", type=float, default=1.0)
    parser.add_argument("--duration", type=float, default=900.0, help="Maximum seconds (up to 3600)")
    args = parser.parse_args(argv)
    if args.output.exists():
        parser.error("Output directory already exists; choose a fresh path")
    if (args.pid <= 0 or not math.isfinite(args.interval) or not 0.1 <= args.interval <= 10 or
            not math.isfinite(args.duration) or not 0 < args.duration <= 3600 or
            not re.fullmatch(r"[A-Za-z0-9_.-]{1,64}", args.phase)):
        parser.error("Require positive PID, interval 0.1..10, duration 0..3600, single phase label")
    reader = MacProcessReader(args.pid)
    identity = reader.identity()
    if identity["uid"] != os.getuid() or identity["pid"] != args.pid:
        parser.error("Target must belong to this user and retain the requested PID")
    if Path(identity["path"]).resolve() != args.expected_path.resolve(strict=True):
        parser.error("Target executable does not match --expected-path")
    facts = machine_facts()
    args.output.mkdir(parents=True, exist_ok=False)
    header = dict(schema=1, started_utc=utc(), target=identity, machine=facts,
                  interval_seconds=args.interval, maximum_duration_seconds=args.duration,
                  phase_file=str(args.phase_file) if args.phase_file else None,
                  mach_timebase=dict(numer=reader.numer, denom=reader.denom),
                  definitions=dict(cpu_percent="100% = one CPU core; summed across target threads",
                    cpu_clock="Mach absolute ticks * numer / denom = nanoseconds",
                    rss="Resident bytes sampled at interval; sampled max is not lifetime RSS peak",
                    footprint="Kernel physical footprint bytes; lifetime peak includes time before attachment",
                    phases="Endpoint labels at sample rate; changing-label intervals excluded from phase CPU means",
                    gpu="Not measured; game's GPU phase is CPU software-renderer time, not hardware GPU utilization"))
    (args.output / "header.json").write_text(json.dumps(header, indent=2) + "\n")
    samples, stop = [], []
    previous_handlers = {}
    for sig in (signal.SIGINT, signal.SIGTERM):
        previous_handlers[sig] = signal.signal(sig, lambda number, frame: stop.append(number))
    began = time.monotonic()
    deadline, end = began, began + args.duration
    reason, error = "duration", None
    fields = ["elapsed_seconds", "monotonic_ns", "timestamp_utc", "phase", "start_abstime",
              "user_ticks", "system_ticks", "rss_bytes", "footprint_bytes",
              "lifetime_peak_footprint_bytes", "query_duration_ns", "interval_seconds",
              "cpu_user_percent", "cpu_system_percent", "cpu_percent", "phase_transition"]
    try:
        with (args.output / "samples.csv").open("w", newline="") as output:
            writer = csv.DictWriter(output, fieldnames=fields)
            writer.writeheader()
            while not stop:
                sample = reader.sample(read_phase(args.phase_file, args.phase))
                sample["elapsed_seconds"] = sample["monotonic_ns"] / 1e9 - began
                row = dict(sample)
                if samples:
                    delta = cpu_interval(samples[-1], sample, reader.numer, reader.denom)
                    row.update({k: delta[k] for k in ("cpu_user_percent", "cpu_system_percent",
                                                    "cpu_percent", "phase_transition")})
                    row["interval_seconds"] = delta["elapsed_seconds"]
                samples.append(sample)
                writer.writerow(row)
                output.flush()
                now = time.monotonic()
                if now >= end:
                    break
                # Absolute cadence; skip missed deadlines instead of burst catch-up queries.
                deadline += args.interval
                while deadline <= now:
                    deadline += args.interval
                time.sleep(max(0, min(deadline, end) - now))
            if stop:
                reason = "sampler_signal"
    except ProcessLookupError:
        reason = "target_exited"
    except (OSError, ValueError) as exc:
        reason, error = "error", str(exc)
    finally:
        for sig, handler in previous_handlers.items():
            signal.signal(sig, handler)
        report = dict(header=header, finished_utc=utc(), stop_reason=reason, error=error,
                      **summarize(samples, reader.numer, reader.denom))
        (args.output / "report.json").write_text(json.dumps(report, indent=2) + "\n")
    print(json.dumps(dict(output=str(args.output), stop_reason=reason, samples=len(samples), error=error)))
    return 1 if error else 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, RuntimeError, ValueError) as exc:
        raise SystemExit(str(exc))
