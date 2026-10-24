"""Resource accounting contracts; live checks touch only this test process."""
import ctypes
import importlib.util
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import time
import unittest

TOOL = Path(__file__).resolve().parents[1] / "tools/profile_process_macos.py"
spec = importlib.util.spec_from_file_location("process_profile", TOOL)
profile = importlib.util.module_from_spec(spec)
spec.loader.exec_module(profile)


class AccountingTests(unittest.TestCase):
    @staticmethod
    def sample(t, user=0, system=0, phase="storm", start=123, rss=100, footprint=80):
        return dict(monotonic_ns=t, user_ticks=user, system_ticks=system,
                    start_abstime=start, phase=phase, rss_bytes=rss,
                    footprint_bytes=footprint, lifetime_peak_footprint_bytes=200)

    def test_tick_conversion_and_multicore_cpu_not_capped_or_machine_normalized(self):
        a = self.sample(1_000_000_000)
        b = self.sample(3_000_000_000, 72_000_000, 12_000_000)
        interval = profile.cpu_interval(a, b, 125, 3)
        self.assertEqual(interval["elapsed_seconds"], 2)
        self.assertEqual(interval["user_seconds"], 3)
        self.assertEqual(interval["system_seconds"], 0.5)
        self.assertEqual(interval["cpu_percent"], 175)

    def test_reuse_backwards_clock_and_counter_regression_are_rejected(self):
        a = self.sample(1_000_000_000, 10, 10)
        for b in (self.sample(2_000_000_000, 20, 20, start=124),
                  self.sample(1_000_000_000, 20, 20),
                  self.sample(2_000_000_000, 9, 20)):
            with self.assertRaises(ValueError):
                profile.cpu_interval(a, b, 1, 1)

    def test_weighted_phase_means_exclude_transition_intervals(self):
        samples = [self.sample(0), self.sample(1_000_000_000, 1_000_000_000),
                   self.sample(4_000_000_000, 1_000_000_000, rss=150),
                   self.sample(5_000_000_000, 2_000_000_000, phase="menu"),
                   self.sample(6_000_000_000, 2_500_000_000, phase="menu")]
        result = profile.summarize(samples, 1, 1)
        self.assertEqual(result["phases"]["storm"]["cpu_percent_mean"], 25)
        self.assertEqual(result["phases"]["menu"]["cpu_percent_mean"], 50)
        self.assertEqual(result["transition_intervals"], 1)
        self.assertEqual(result["phases"]["storm"]["sampled_rss_max_bytes"], 150)
        self.assertEqual(result["lifetime_peak_footprint_bytes"], 200)
        self.assertEqual(result["sampled_footprint_max_bytes"], 80)

    def test_phase_file_has_bounded_single_label_and_safe_missing_fallback(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "phase.txt"
            self.assertEqual(profile.read_phase(path, "boot"), "boot")
            path.write_text("storm\n")
            self.assertEqual(profile.read_phase(path, "boot"), "storm")
            for bad in ("storm\nmenu", "x" * 1000, "\x00"):
                path.write_text(bad)
                self.assertEqual(profile.read_phase(path, "boot"), "unknown")

    def test_cli_does_not_overwrite_existing_output(self):
        with tempfile.TemporaryDirectory() as directory:
            result = subprocess.run([sys.executable, str(TOOL), "--pid", str(os.getpid()),
                                     "--expected-path", sys.executable, "--output", directory,
                                     "--duration", "0.01"], capture_output=True, text=True)
            self.assertNotEqual(result.returncode, 0)
            self.assertIn("exists", result.stderr.lower())
            self.assertEqual(list(Path(directory).iterdir()), [])


@unittest.skipUnless(sys.platform == "darwin", "macOS libproc and SDK ABI")
class DarwinTests(unittest.TestCase):
    def test_real_cli_writes_bounded_samples_without_signalling_target(self):
        with tempfile.TemporaryDirectory() as directory:
            output = Path(directory) / "profile"
            phase = Path(directory) / "phase.txt"
            phase.write_text("indoor\n")
            reader = profile.MacProcessReader(os.getpid())
            identity = reader.identity()
            result = subprocess.run([sys.executable, str(TOOL), "--pid", str(os.getpid()),
                                     "--expected-path", identity["path"], "--output", str(output),
                                     "--phase-file", str(phase), "--interval", "0.1",
                                     "--duration", "0.21"], capture_output=True, text=True, timeout=5)
            self.assertEqual(result.returncode, 0, result.stderr)
            report = json.loads((output / "report.json").read_text())
            self.assertEqual(report["stop_reason"], "duration")
            self.assertGreaterEqual(report["sample_count"], 3)
            self.assertEqual(report["header"]["target"]["start_abstime"], identity["start_abstime"])
            self.assertEqual(set(report["phases"]), {"indoor"})
            self.assertGreater(report["sampled_rss_max_bytes"], 0)
            self.assertTrue((output / "samples.csv").read_text().startswith("elapsed_seconds,"))

    def test_ctypes_offsets_match_actual_sdk_not_handwritten_assumptions(self):
        fields = {"rusage_info_v4": ["ri_user_time", "ri_system_time", "ri_resident_size",
                  "ri_phys_footprint", "ri_proc_start_abstime", "ri_proc_exit_abstime",
                  "ri_lifetime_max_phys_footprint", "ri_runnable_time"],
                  "proc_bsdinfo": ["pbi_pid", "pbi_uid", "pbi_start_tvsec", "pbi_start_tvusec"]}
        c = '#include <stddef.h>\n#include <stdio.h>\n#include <libproc.h>\nint main(void){\n'
        for struct, names in fields.items():
            c += f'printf("{struct} %zu\\n",sizeof(struct {struct}));\n'
            for name in names:
                c += f'printf("{struct}.{name} %zu\\n",offsetof(struct {struct},{name}));\n'
        c += "return 0;}\n"
        with tempfile.TemporaryDirectory() as directory:
            source, binary = Path(directory) / "abi.c", Path(directory) / "abi"
            source.write_text(c)
            subprocess.run(["xcrun", "clang", "-Wall", "-Werror", str(source), "-o", str(binary)],
                           check=True, capture_output=True)
            actual = dict(line.split() for line in subprocess.check_output([binary], text=True).splitlines())
        for name, struct in (("rusage_info_v4", profile.RUsageInfoV4),
                             ("proc_bsdinfo", profile.ProcBsdInfo)):
            self.assertEqual(ctypes.sizeof(struct), int(actual[name]))
            for field in fields[name]:
                self.assertEqual(getattr(struct, field).offset, int(actual[name + "." + field]))

    def test_real_self_cpu_clock_units_and_start_identity(self):
        reader = profile.MacProcessReader(os.getpid())
        identity = reader.identity()
        self.assertEqual(identity["pid"], os.getpid())
        self.assertEqual(identity["uid"], os.getuid())
        self.assertLess(identity["start_unix_seconds"], time.time())
        a = reader.sample("test")
        clock_a = time.process_time_ns()
        while time.process_time_ns() - clock_a < 60_000_000:
            pass
        clock_b = time.process_time_ns()
        b = reader.sample("test")
        delta = profile.cpu_interval(a, b, reader.numer, reader.denom)
        measured = delta["user_seconds"] + delta["system_seconds"]
        expected = (clock_b - clock_a) / 1e9
        self.assertAlmostEqual(measured / expected, 1, delta=0.15)
        self.assertGreater(b["rss_bytes"], 0)
        self.assertGreater(b["footprint_bytes"], 0)
        self.assertGreaterEqual(b["lifetime_peak_footprint_bytes"], b["footprint_bytes"])


if __name__ == "__main__":
    unittest.main()
