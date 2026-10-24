"""Pure replay planning and independent screenshot-oracle tests; no native run."""
import struct
import unittest
import json
from pathlib import Path
import tempfile

from replay_cinema import (CinemaRoute, inspect_subtitles, compare_picture, compare_runs,
                          display_at, caption_pixels, gameplay_canvas_at, expanded_at)
from compare_expanded_cinema import compare as compare_expanded


class CinemaReplayTests(unittest.TestCase):
    @staticmethod
    def state(frame, overlay=5, map_id=0, pos=None, flags=0):
        return dict(frame=frame, overlay=overlay, map_id=map_id,
                    pos=pos or [0, 0, 0], flags=flags)

    def test_start_skip_is_bounded_and_stops_at_real_gameplay(self):
        route = CinemaRoute(skip_intros=True, caption_offsets=(390, 1200))
        until, taps = route.advance(self.state(1000), [])
        self.assertEqual((until, taps), (1200, ["1001:3:4"]))
        until, taps = route.advance(self.state(1200, overlay=4), [])
        self.assertEqual(taps, [])  # A Start hold must not leak into title/gameplay.
        until, taps = route.advance(self.state(2200, 4, 213, [-890, 0, -3425]), [])
        self.assertEqual(route.first_input, 2210)
        self.assertTrue(taps)
        self.assertTrue(all(tap.split(":")[1] != "3" for tap in taps))
        until, taps = route.advance(self.state(13210), [])
        self.assertEqual((until, taps, route.stop_inputs), (13410, [], 13210))
        cue = [dict(event="start", name="002AM", frame=13420)]
        self.assertEqual(route.advance(self.state(13410), cue), (13810, []))
        self.assertEqual(route.advance(self.state(13810), cue), (14620, []))
        self.assertEqual(route.advance(self.state(14620), cue), (None, []))

    def test_natural_mode_and_wrong_tutorial_position_do_not_inject_start(self):
        route = CinemaRoute(False, (390,))
        self.assertEqual(route.advance(self.state(1000), []), (2000, []))
        route.advance(self.state(2000, 4, 213, [-890, 10, -3425]), [])
        self.assertIsNone(route.first_input)
        with self.assertRaises(RuntimeError):
            route.advance(self.state(22000), [])

    @staticmethod
    def ram():
        data = bytearray(2 * 1024 * 1024)
        for offset, value in ((0x811D8, 5), (0x79E9C, 1), (0x65A00, 2),
                              (0xACBF8, 0x80065600)):
            struct.pack_into("<I", data, offset, value)
        struct.pack_into("<HH", data, 0x65610, 0, 174)
        for index, y in enumerate((174, 190)):
            p = 0x64100 + 32 * index
            struct.pack_into("<H", data, p, 1)
            struct.pack_into("<hhhhhh", data, p + 12, 12, y, 8, 16, 8, 16)
            struct.pack_into("<I", data, p + 28, 0x80065600)
        return data

    def test_actual_glyph_extent_classification_and_unknown_state_fallback(self):
        ram = self.ram()
        self.assertEqual(inspect_subtitles(ram)["line_rows"], [174, 190])
        self.assertTrue(inspect_subtitles(ram)["ram_contract"])
        struct.pack_into("<h", ram, 0x64120 + 14, 206)
        self.assertFalse(inspect_subtitles(ram)["ram_contract"])
        self.assertFalse(inspect_subtitles(ram[:100])["ram_contract"])

    def test_attract_markers_do_not_prove_displayed_caption_or_centering(self):
        from PIL import Image
        log = ("disp: x=0 y=0 w=320 h=210 vlines=210 y1=48 hrange=608..3168 on=1\n"
               "control: paused frame=1000 overlay=5 map_id=0 pos=0,0,0 flags=0\n"
               "disp: x=0 y=256 w=320 h=216 vlines=216 y1=28 hrange=608..3168 on=1\n"
               "control: paused frame=2000 overlay=5 map_id=0 pos=0,0,0 flags=0\n")
        self.assertEqual(display_at(log, 1000)["h"], 210)
        self.assertEqual(display_at(log, 2000)["h"], 216)
        picture = Image.new("RGB", (320, 240))
        picture.putpixel((160, 190), (255, 255, 255))
        self.assertTrue(inspect_subtitles(self.ram())["ram_contract"])
        self.assertFalse(caption_pixels(picture, False, display_at(log, 1000))["visible"])
        self.assertTrue(caption_pixels(picture, False, display_at(log, 2000))["visible"])
        self.assertFalse(caption_pixels(picture, True, display_at(log, 2000))["visible"])
        picture.putpixel((160, 210), (255, 255, 255))
        self.assertTrue(caption_pixels(picture, True, display_at(log, 2000))["visible"])

    def test_pixel_oracle_preserves_picture_and_second_line_not_only_borders(self):
        from PIL import Image
        for scale in (1, 2):
            original = Image.new("RGB", (320 * scale, 240 * scale))
            pixels = original.load()
            for y in range(12 * scale, 228 * scale):
                for x in range(320 * scale):
                    pixels[x, y] = ((x * 7 + y) % 256, y % 256, x % 256)
            centered = Image.new("RGB", original.size)
            centered.paste(original.crop((0, 12 * scale, 320 * scale, 184 * scale)),
                           (0, 34 * scale))
            centered.paste(original.crop((0, 186 * scale, 320 * scale, 218 * scale)),
                           (0, 207 * scale))
            self.assertTrue(compare_picture(original, centered, True)["passed"])
            centered.putpixel((17, 232 * scale), (255, 0, 255))
            self.assertFalse(compare_picture(original, centered, True)["passed"])
            self.assertTrue(compare_picture(original, original.copy(), False)["passed"])
            self.assertFalse(compare_picture(original, centered, False)["passed"])

    def test_fallback_compares_every_pixel_at_noncinematic_transition_dimensions(self):
        from PIL import Image
        # Actual RU transitions 2400/14410 use a 256x240 canvas at IR2.
        original = Image.new("RGB", (512, 480), (12, 34, 56))
        self.assertTrue(compare_picture(original, original.copy(), False)["passed"])
        changed = original.copy()
        changed.putpixel((511, 479), (12, 34, 57))
        self.assertFalse(compare_picture(original, changed, False)["passed"])
        self.assertFalse(compare_picture(original, Image.new("RGB", (640, 480)), False)["passed"])
        # An unexpected canvas must still never enter the canonical relocation.
        self.assertFalse(compare_picture(original, original.copy(), True)["passed"])

    def test_gameplay_canvas_crops_only_original_border_rows_at_all_scales(self):
        from PIL import Image
        for scale in (1, 2, 3, 4):
            original = Image.new("RGB", (320 * scale, 240 * scale))
            # Row-dependent values expose any incorrect offset or lost edge row.
            for y in range(original.height):
                original.paste((y % 256, y // 256, 17), (0, y, original.width, y + 1))
            cropped = original.crop((0, 12 * scale, 320 * scale, 228 * scale))
            self.assertTrue(compare_picture(original, cropped, False, gameplay=True)["passed"])
            self.assertFalse(compare_picture(original, cropped, True, gameplay=True)["passed"])
            self.assertFalse(compare_picture(cropped, cropped, False, gameplay=True)["passed"])
            self.assertTrue(compare_picture(cropped, cropped, False, gameplay=True,
                                            reference_gameplay=True)["passed"])
            self.assertFalse(compare_picture(cropped, cropped, False, reference_gameplay=True)["passed"])
            changed = cropped.copy()
            changed.putpixel((changed.width - 1, changed.height - 1), (0, 0, 0))
            self.assertFalse(compare_picture(original, changed, False, gameplay=True)["passed"])

    def test_gameplay_canvas_log_state_tracks_latest_mode_and_legacy_fallback(self):
        log = ("cinema: frame=1000 centered=1 overlay=5\n"
               "cinema: frame=2400 centered=0 gameplay_canvas=1 overlay=4\n"
               "cinema: frame=14410 centered=0 gameplay_canvas=0 overlay=5\n")
        self.assertFalse(gameplay_canvas_at(log, 1000))
        self.assertTrue(gameplay_canvas_at(log, 3000))
        self.assertFalse(gameplay_canvas_at(log, 14410))

    def test_expanded_log_proves_actual_surface_and_tracks_fallback(self):
        log=("cinema: frame=100 centered=1 gameplay_canvas=0 expanded=0\n"
             "cinema: frame=200 centered=1 gameplay_canvas=0 expanded=1\n"
             "cinema: frame=300 centered=1 gameplay_canvas=0 expanded=0\n")
        self.assertFalse(expanded_at(log,199))
        self.assertTrue(expanded_at(log,200))
        self.assertFalse(expanded_at(log,300))
        self.assertFalse(expanded_at("cinema: frame=200 centered=1\n",300))

    def test_comparison_rejects_changed_state_or_controls_despite_equal_picture(self):
        from PIL import Image
        with tempfile.TemporaryDirectory() as temporary:
            before, after = Path(temporary) / "before", Path(temporary) / "after"
            for output in (before, after):
                (output / "user").mkdir(parents=True)
                report = dict(passed=True, checkpoints=[self.state(1000)],
                              captures=[dict(frame=1000, centered=False)])
                (output / "acceptance.json").write_text(json.dumps(report))
                (output / "control-01000.txt").write_text("1000\n")
                Image.new("RGB", (320, 240)).save(output / "user/frame_01000.bmp")
                for kind in ("ram", "vram"):
                    (output / f"user/{kind}_01000.bin").write_bytes(kind.encode())
            self.assertTrue(compare_runs(before, after)["passed"])
            # An older aggregate comparison failure must not poison a recheck;
            # actual failed capture contracts must still be rejected.
            report.update(passed=False, comparison_passed=False, errors=[], exit_code=0)
            (after / "acceptance.json").write_text(json.dumps(report))
            self.assertTrue(compare_runs(before, after)["passed"])
            report["errors"] = ["Missing actual visible caption"]
            (after / "acceptance.json").write_text(json.dumps(report))
            self.assertFalse(compare_runs(before, after)["passed"])
            report.update(errors=[], capture_passed=False)
            (after / "acceptance.json").write_text(json.dumps(report))
            self.assertFalse(compare_runs(before, after)["passed"])
            report.update(capture_passed=True)
            (after / "acceptance.json").write_text(json.dumps(report))
            (after / "user/ram_01000.bin").write_bytes(b"changed guest state")
            self.assertFalse(compare_runs(before, after)["passed"])
            (after / "user/ram_01000.bin").write_bytes(b"ram")
            (after / "control-01000.txt").write_text("1000\n999:3:4\n")
            self.assertFalse(compare_runs(before, after)["passed"])

    def test_expanded_comparison_requires_exact_core_guest_and_unchanged_frames(self):
        from PIL import Image
        with tempfile.TemporaryDirectory() as temporary:
            before,after=Path(temporary)/"before",Path(temporary)/"after"
            for p in (before,after):
                (p/"user").mkdir(parents=True)
                (p/"control-01000.txt").write_text("1000\n")
                for kind in ("ram","vram"):(p/f"user/{kind}_01000.bin").write_bytes(kind.encode())
            a=Image.new("RGB",(320,240));a.paste((40,80,120),(0,12,320,184));a.save(before/"user/frame_01000.bmp")
            b=Image.new("RGB",(320,240));b.paste((10,20,30),(0,12,320,228));b.paste((40,80,120),(0,34,320,206));b.save(after/"user/frame_01000.bmp")
            for p,expanded in ((before,False),(after,True)):
                (p/"acceptance.json").write_text(json.dumps(dict(passed=True,capture_passed=True,
                    checkpoints=[self.state(1000)],captures=[dict(frame=1000,centered=expanded,expanded=expanded)])))
            self.assertTrue(compare_expanded(before,after)["passed"])
            b.putpixel((0,34),(40,80,121));b.save(after/"user/frame_01000.bmp")
            self.assertFalse(compare_expanded(before,after)["passed"])
            b.putpixel((0,34),(40,80,120));b.save(after/"user/frame_01000.bmp")
            (after/"user/vram_01000.bin").write_bytes(b"changed")
            self.assertFalse(compare_expanded(before,after)["passed"])


if __name__ == "__main__":
    unittest.main()
