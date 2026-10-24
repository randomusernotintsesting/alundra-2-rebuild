"""Literal timing and pause fixtures; no game or subprocess workload."""
import importlib.util
from pathlib import Path
import unittest

spec = importlib.util.spec_from_file_location("analysis", Path(__file__).resolve().parents[1] /
                                             "tools/analyze_resource_profiles.py")
analysis = importlib.util.module_from_spec(spec)
spec.loader.exec_module(analysis)


class AnalysisTests(unittest.TestCase):
    LOG = ("phasestat: first_frame=1 frame=60 frames=60 wall_ms=1000 cpu_ms=650 "
           "process_cpu_ms=700 gpu_wall_ms=600 gpu_max_wall_ms=25 compose_wall_ms=20\n"
           "phasestat: first_frame=61 frame=120 frames=60 wall_ms=2000 cpu_ms=1300 "
           "process_cpu_ms=1400 gpu_wall_ms=800 gpu_max_wall_ms=30 compose_wall_ms=40\n")

    def test_exact_weighted_ticks_cpu_and_explicit_mean_vs_median(self):
        rows = analysis.timing_windows(self.LOG, 1, 120)
        result = analysis.summarize_windows(rows)
        self.assertEqual(result["logical_ticks_per_second"], 40)
        self.assertEqual(result["process_cpu_percent"], 70)
        self.assertEqual(result["gpu_ms_per_60ticks_mean"], 700)
        self.assertEqual(result["gpu_ms_per_60ticks_median"], 700)
        self.assertEqual(result["gpu_render_max_ms"], 30)
        self.assertEqual(result["wall_ms_per_60ticks_mean"], 1500)

    def test_control_pause_affects_following_window_not_completed_one(self):
        log = self.LOG + "control: paused frame=60 overlay=4\n"
        self.assertEqual(len(analysis.timing_windows(log, 1, 60)), 1)
        with self.assertRaisesRegex(ValueError, "pause"):
            analysis.timing_windows(log, 61, 120)
        with self.assertRaises(ValueError):
            analysis.timing_windows(self.LOG, 1, 180)
        with self.assertRaises(ValueError):
            analysis.timing_windows(self.LOG + self.LOG, 1, 120)

    def test_tick_counts_use_conservative_frame_brackets_and_exclude_pauses(self):
        log = ("phaseframe: frame=59\n"
               "tickstat: frames/s=60 seqticks/s=60 gamefps=30 work/s=1\n"
               "phaseframe: frame=60\n"
               "phaseframe: frame=119\n"
               "tickstat: frames/s=60 seqticks/s=60 gamefps=30 work/s=1\n"
               "phaseframe: frame=120\n")
        rows = analysis.tick_counts(log, 1, 120)
        self.assertEqual(len(rows), 1)
        self.assertEqual(rows[0]["gamefps"], 30)
        self.assertEqual(rows[0]["end_frame_bounds"], [119, 120])
        self.assertEqual(analysis.tick_counts(log + "control: paused frame=70\n", 1, 120), [])

    def test_invalid_or_partial_timing_window_is_never_accepted(self):
        for log in (self.LOG.replace("frames=60", "frames=59", 1),
                    self.LOG.replace("wall_ms=1000", "wall_ms=0", 1)):
            with self.assertRaises(ValueError):
                analysis.timing_windows(log, 1, 120)


if __name__ == "__main__":
    unittest.main()
