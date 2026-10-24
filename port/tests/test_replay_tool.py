"""Verify replay input selection without launching or controlling a game."""
from pathlib import Path
import io
import os
import runpy
import subprocess
import tempfile
import unittest
from unittest.mock import patch

PORT = Path(__file__).resolve().parents[1]


class ReplayInputTests(unittest.TestCase):
    def run_replay(self, extra, expected_exit=0):
        with tempfile.TemporaryDirectory() as tmp:
            argv = [str(PORT / "tools/replay.py"), "--output", tmp, *extra]
            # The external GUI/game process is the only substituted boundary.
            with patch("sys.argv", argv), patch("subprocess.run") as launch:
                launch.return_value = subprocess.CompletedProcess([], 0)
                with self.assertRaises(SystemExit) as result:
                    runpy.run_path(str(PORT / "tools/replay.py"), run_name="__main__")
                self.assertEqual(result.exception.code, expected_exit)
                return launch.call_args

    def test_default_disc_and_image_remain_unchanged(self):
        call = self.run_replay([])
        command = call.args[0]
        self.assertEqual(command[1:], [str(PORT.parent / "disc_jp"), "--boot",
                                      str(PORT.parent / "build/alundra2_jp.bin")])
        env = call.kwargs["env"]
        self.assertEqual((env["A2_IRSCALE"], env["A2_SOUND"], env["A2_FAST"]),
                         ("1", "0", "1"))
        self.assertEqual(env["A2_WIDE"], "0")
        self.assertNotIn("A2_TICKSTAT", env)
        self.assertNotIn("A2_PROFILE_PRESENT", env)
        self.assertNotIn("A2_AUDIOSTAT", env)
        self.assertEqual(env["A2_AUTO"], "1")

    def test_explicit_disc_and_image_select_isolated_resources(self):
        command = self.run_replay(["--disc", "/tmp/a2-test-disc",
                                   "--image", "/tmp/a2-test-disc.bin"]).args[0]
        self.assertEqual(command[1:], [str(Path("/tmp/a2-test-disc").resolve()),
                                      "--boot", str(Path("/tmp/a2-test-disc.bin").resolve())])

    def test_realtime_audio_profile_reaches_isolated_dummy_backend(self):
        call = self.run_replay(["--realtime", "--sound", "--ir-scale", "3",
                                "--tick-stats", "--wide"])
        env = call.kwargs["env"]
        self.assertNotIn("A2_FAST", env)
        self.assertEqual((env["A2_SOUND"], env["A2_IRSCALE"], env["A2_TICKSTAT"]),
                         ("1", "3", "1"))
        self.assertEqual(env["SDL_AUDIODRIVER"], "dummy")
        self.assertEqual(env["SDL_VIDEODRIVER"], "dummy")
        self.assertEqual(env["A2_WIDE"], "1")

    def test_real_audio_output_is_explicit_and_requires_normal_speed(self):
        call = self.run_replay(["--realtime", "--sound", "--audio-driver", "coreaudio"])
        env = call.kwargs["env"]
        self.assertEqual(env["SDL_AUDIODRIVER"], "coreaudio")
        self.assertEqual(env["SDL_VIDEODRIVER"], "dummy")
        self.assertNotIn("A2_FAST", env)
        self.assertNotIn("A2_WAIT_PROBE", env)
        for extra in (["--audio-driver", "coreaudio"],
                      ["--sound", "--audio-driver", "coreaudio"],
                      ["--realtime", "--audio-driver", "coreaudio"]):
            self.assertIsNone(self.run_replay(extra, expected_exit=2))

    def test_default_video_overrides_inherited_cocoa(self):
        with patch.dict(os.environ, {"SDL_VIDEODRIVER": "cocoa"}):
            env = self.run_replay([]).kwargs["env"]
        self.assertEqual(env["SDL_VIDEODRIVER"], "dummy")

    def test_cocoa_realtime_preserves_coreaudio_and_isolated_user_directory(self):
        with patch.dict(os.environ, {"SDL_VIDEODRIVER": "dummy", "A2_FAST": "1",
                                     "A2_USER_DIR": "/tmp/a2-inherited-user"}):
            call = self.run_replay(["--video-driver", "cocoa", "--realtime",
                                    "--sound", "--audio-driver", "coreaudio"])
        env = call.kwargs["env"]
        self.assertEqual(env["SDL_VIDEODRIVER"], "cocoa")
        self.assertEqual(env["SDL_AUDIODRIVER"], "coreaudio")
        self.assertEqual(env["A2_SOUND"], "1")
        self.assertNotIn("A2_FAST", env)
        self.assertEqual(env["A2_USER_DIR"], str(call.kwargs["cwd"] / "user"))

    def test_cocoa_realtime_does_not_require_or_enable_audio(self):
        env = self.run_replay(["--video-driver", "cocoa", "--realtime"]).kwargs["env"]
        self.assertEqual(env["SDL_VIDEODRIVER"], "cocoa")
        self.assertEqual(env["SDL_AUDIODRIVER"], "dummy")
        self.assertEqual(env["A2_SOUND"], "0")
        self.assertNotIn("A2_FAST", env)

    def test_cocoa_without_realtime_rejects_before_launch(self):
        with patch("sys.stderr", new_callable=io.StringIO) as error:
            call = self.run_replay(["--video-driver", "cocoa"], expected_exit=2)
        self.assertIsNone(call)
        self.assertIn("requires --realtime", error.getvalue())

    def test_original_ui_comparison_is_explicit_and_keeps_same_resolution(self):
        env=self.run_replay(["--hd-ui", "0", "--ir-scale", "3"]).kwargs["env"]
        self.assertEqual(env["A2_HDUI"], "0")
        self.assertEqual(env["A2_IRSCALE"], "3")

    def test_present_profiling_is_explicit_and_does_not_disable_pacing(self):
        env=self.run_replay(["--profile-present", "--realtime"]).kwargs["env"]
        self.assertEqual(env["A2_PROFILE_PRESENT"], "1")
        self.assertNotIn("A2_FAST", env)

    def test_natural_intro_without_autopilot_has_no_inherited_input(self):
        inherited = dict(A2_AUTO="2", A2_SKIP="1", A2_MASH="1", A2_PLAY="1",
                         A2_TAP="100:3:4", A2_AUDIOSTAT="1")
        with patch.dict(os.environ, inherited):
            env = self.run_replay(["--auto", "none", "--natural-intro"]).kwargs["env"]
        for name in ("A2_AUTO", "A2_SKIP", "A2_MASH", "A2_PLAY", "A2_AUDIOSTAT"):
            self.assertNotIn(name, env)
        self.assertEqual(env["A2_TAP"], "")

    def test_audio_diagnostics_are_opt_in_and_keep_normal_speed(self):
        env = self.run_replay(["--audio-stats", "--realtime", "--sound"]).kwargs["env"]
        self.assertEqual(env["A2_AUDIOSTAT"], "1")
        self.assertEqual(env["SDL_AUDIODRIVER"], "dummy")
        self.assertEqual(env["A2_SOUND"], "1")
        self.assertNotIn("A2_FAST", env)

    def test_phase_timing_is_explicit_and_keeps_realtime_sound(self):
        with patch.dict(os.environ, {"A2_TIMING": "1"}):
            default = self.run_replay([]).kwargs["env"]
        self.assertNotIn("A2_TIMING", default)
        env = self.run_replay(["--phase-timing", "--realtime", "--sound"]).kwargs["env"]
        self.assertEqual(env["A2_TIMING"], "1")
        self.assertEqual(env["A2_SOUND"], "1")
        self.assertEqual(env["SDL_AUDIODRIVER"], "dummy")
        self.assertNotIn("A2_FAST", env)

    def test_mix_measurement_is_explicit_and_does_not_enable_sound_or_change_pacing(self):
        with patch.dict(os.environ, {"A2_MIXSTAT":"1"}):
            default=self.run_replay([]).kwargs["env"]
        self.assertNotIn("A2_MIXSTAT",default)
        env=self.run_replay(["--mix-stats"]).kwargs["env"]
        self.assertEqual(env["A2_MIXSTAT"],"1")
        self.assertEqual(env["A2_AUDIOSTAT"],"1")
        self.assertEqual(env["A2_SOUND"],"0")
        self.assertEqual(env["A2_FAST"],"1")

    def test_world_provenance_trace_requires_explicit_replay_option(self):
        with patch.dict(os.environ, {"A2_WORLD_PRECISION":"1", "A2_WORLD_TRACE_FROM":"10"}):
            default=self.run_replay([]).kwargs["env"]
        self.assertNotIn("A2_WORLD_PRECISION",default)
        self.assertNotIn("A2_WORLD_TRACE_FROM",default)
        env=self.run_replay(["--world-precision", "--world-trace", "16998", "17001"]).kwargs["env"]
        self.assertEqual(env["A2_WORLD_PRECISION"],"1")
        self.assertEqual(env["A2_WORLD_TRACE_FROM"],"16998")
        self.assertEqual(env["A2_WORLD_TRACE_TO"],"17001")
        self.assertNotIn("A2_WORLD_RASTER",env)

    def test_wait_probe_requires_explicit_normal_speed_diagnostics(self):
        with patch.dict(os.environ, {"A2_WAIT_PROBE": "1"}):
            default = self.run_replay([]).kwargs["env"]
        self.assertNotIn("A2_WAIT_PROBE", default)
        env = self.run_replay(["--wait-probe", "--realtime", "--phase-timing"]).kwargs["env"]
        self.assertEqual(env["A2_WAIT_PROBE"], "1")
        self.assertEqual(env["A2_TIMING"], "1")
        self.assertNotIn("A2_FAST", env)
        self.assertEqual(env["SDL_VIDEODRIVER"], "dummy")

    def test_wait_probe_rejects_unpaced_or_unmeasured_runs(self):
        self.assertIsNone(self.run_replay(["--wait-probe"], expected_exit=2))
        self.assertIsNone(self.run_replay(["--wait-probe", "--realtime"], expected_exit=2))

    def test_no_present_vsync_reaches_realtime_measured_audio_run_only(self):
        with patch.dict(os.environ, {"A2_PRESENT_VSYNC": "0"}):
            default = self.run_replay([]).kwargs["env"]
        self.assertNotIn("A2_PRESENT_VSYNC", default)
        env = self.run_replay(["--no-present-vsync", "--realtime", "--phase-timing",
                               "--sound", "--audio-driver", "coreaudio"]).kwargs["env"]
        self.assertEqual(env["A2_PRESENT_VSYNC"], "0")
        self.assertEqual(env["A2_TIMING"], "1")
        self.assertEqual(env["A2_SOUND"], "1")
        self.assertEqual(env["SDL_AUDIODRIVER"], "coreaudio")
        self.assertNotIn("A2_FAST", env)

    def test_no_present_vsync_rejects_unpaced_or_unmeasured_runs(self):
        self.assertIsNone(self.run_replay(["--no-present-vsync", "--phase-timing"], expected_exit=2))
        self.assertIsNone(self.run_replay(["--no-present-vsync", "--realtime"], expected_exit=2))

    def test_world_fine_raster_is_separate_from_provenance(self):
        with patch.dict(os.environ, {"A2_WORLD_RASTER": "1"}):
            default = self.run_replay(["--world-precision"]).kwargs["env"]
        self.assertNotIn("A2_WORLD_RASTER", default)
        env = self.run_replay(["--world-precision", "--world-raster", "--ir-scale", "3"]).kwargs["env"]
        self.assertEqual(env["A2_WORLD_PRECISION"], "1")
        self.assertEqual(env["A2_WORLD_RASTER"], "1")
        self.assertEqual(env["A2_IRSCALE"], "3")
        self.assertIsNone(self.run_replay(["--world-raster"], expected_exit=2))


if __name__ == "__main__":
    unittest.main()
