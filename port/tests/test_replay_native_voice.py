"""Pure planning/evidence checks; this suite never starts a game process."""
import unittest

from replay_native_voice import (acceptance, checkpoint, control_text,
                                 next_intro_frame, shifted_tutorial, tutorial_ready)


class NativeVoiceReplayTests(unittest.TestCase):
    def test_prospective_boot_captures_then_normal_intro_steps(self):
        self.assertEqual([next_intro_frame(frame) for frame in (0, 100, 350, 1000)],
                         [100, 350, 1000, 2000])

    def test_observed_tutorial_state_and_not_loading_transition(self):
        settled = checkpoint("control: paused frame=18000 overlay=4 map_id=213 "
                             "pos=-890,0,-3425 flags=0\n")
        self.assertTrue(tutorial_ready(settled))
        self.assertFalse(tutorial_ready(dict(settled, flags=0x10)))
        self.assertFalse(tutorial_ready(dict(settled, pos=[-890, 149, -3257])))

    def test_shift_reproduces_accepted_natural_route_and_no_start(self):
        taps = shifted_tutorial(18010)
        self.assertEqual(taps[0], "18010:5:700")
        self.assertIn("28005:14", taps)
        self.assertIn("28510:13", taps)
        self.assertTrue(all(tap.split(":")[1] != "3" for tap in taps))

    def test_batches_preserve_overlapping_hold_and_cut_all_inputs(self):
        taps = shifted_tutorial(18010)
        self.assertIn("18910:5:2200\n", control_text(20000, 22500, taps))
        self.assertEqual(control_text(29010, 29210, []), "29210\n")
        for first in range(18000, 31500, 2500):
            self.assertLessEqual(len(control_text(first, first + 2500, taps).splitlines()) - 1, 128)

    @staticmethod
    def log(language="en"):
        count, frames, origin = (682, 2749824, 1) if language == "en" else (681, 2745792, 3)
        return ("audiostat: tick=28980 cd_nonzero=100 cd_mixed_nonzero=90 cd_dropped=0 host_fail=0\n"
                f"voicecue: start frame=29000 name=002AM origin={origin} sectors={count} first_sample=0 native=1\n"
                "audiostat: tick=29040 cd_nonzero=110 cd_mixed_nonzero=99 cd_dropped=0 host_fail=0\n"
                "audiostat: tick=33360 cd_nonzero=200 cd_mixed_nonzero=190 cd_dropped=0 host_fail=0\n"
                f"voicecue: end name=002AM reason=complete consumed={count} expected={count} frames={frames} complete=1 native=1\n"
                "audiostat: tick=33420 cd_nonzero=210 cd_mixed_nonzero=199 cd_dropped=0 host_fail=0\n"
                "nativecd: raw_read_attempts=0 data_dma_attempts=0 fifo_attempts=0\n")

    def test_full_different_sources_accepted(self):
        for language in ("ja", "en"):
            self.assertTrue(acceptance(self.log(language), language, 0, 28800)["passed"])

    def test_original_mute_after_full_source_is_complete_but_close_is_not(self):
        for language in ("ja", "en"):
            log = self.log(language).replace("reason=complete", "reason=Mute")
            self.assertTrue(acceptance(log, language, 0, 28800)["passed"])
            self.assertFalse(acceptance(log.replace("reason=Mute", "reason=close"),
                                        language, 0, 28800)["passed"])
            self.assertFalse(acceptance(log.replace("complete=1", "complete=0"),
                                        language, 0, 28800)["passed"])
            count = 681 if language == "ja" else 682
            self.assertFalse(acceptance(log.replace(f"consumed={count}",
                                                    f"consumed={count - 1}"),
                                        language, 0, 28800)["passed"])

    def test_intro_audio_cannot_prove_speech_mix(self):
        import re
        log = self.log()
        # The intro remains nonzero, but the full speech does not reach the mixer.
        muted = re.sub(r"cd_mixed_nonzero=\d+", "cd_mixed_nonzero=90", log)
        self.assertFalse(acceptance(muted, "en", 0, 28800)["passed"])
        before_only = re.sub(r"^audiostat: tick=(?!28980)[^\n]+\n", "", log, flags=re.MULTILINE)
        self.assertFalse(acceptance(before_only, "en", 0, 28800)["passed"])

    def test_bracketing_other_audio_does_not_prove_speech(self):
        log = self.log().replace("cd_nonzero=200 cd_mixed_nonzero=190",
                                 "cd_nonzero=110 cd_mixed_nonzero=99")
        self.assertFalse(acceptance(log, "en", 0, 28800)["passed"])

    def test_requires_brackets_and_monotonic_counters(self):
        log = self.log()
        self.assertFalse(acceptance(log.replace("audiostat: tick=33420", "missing: tick=33420"),
                                    "en", 0, 28800)["passed"])
        self.assertFalse(acceptance(log.replace("tick=33360", "tick=10"),
                                    "en", 0, 28800)["passed"])

    def test_reject_partial_wrong_source_transport_and_late_inputs(self):
        log = self.log()
        for invalid in (log.replace("consumed=682", "consumed=681"),
                        log.replace("origin=1", "origin=3"),
                        log.replace("raw_read_attempts=0", "raw_read_attempts=1"),
                        log.replace("nativecd:", "missing:"),
                        log.replace("frames=2749824", "frames=2745792")):
            self.assertFalse(acceptance(invalid, "en", 0, 28800)["passed"])
        self.assertFalse(acceptance(log, "en", 0, 29100)["passed"])
        self.assertFalse(acceptance(log, "en", -15, 28800)["passed"])


if __name__ == "__main__":
    unittest.main()
