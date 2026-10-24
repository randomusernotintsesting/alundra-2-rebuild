"""Offline acceptance must identify the draw actually displayed at capture."""
import tempfile
import unittest
from pathlib import Path

from verify_world_precision import FAR_TRIANGLE_TARGETS, TARGETS, compare_captures, trace_proof


class CapturedWorldComparison(unittest.TestCase):
    def compare(self, *, fine=False, native_change=False, display_change=False):
        with tempfile.TemporaryDirectory() as directory:
            output = Path(directory)
            for side in ("off", "on"):
                user = output / side / "user"
                user.mkdir(parents=True)
                for kind in ("ram", "vram", "frame"):
                    suffix = "bmp" if kind == "frame" else "bin"
                    changed = side == "on" and (display_change if kind == "frame" else native_change)
                    (user / f"{kind}_16999.{suffix}").write_bytes(b"changed" if changed else b"same")
            return compare_captures(output, 16999, fine)

    def test_metadata_capture_requires_identical_display(self):
        self.assertTrue(all(item["identical"] for item in self.compare().values()))
        with self.assertRaisesRegex(AssertionError, "display"):
            self.compare(display_change=True)

    def test_fine_capture_requires_changed_display_but_unchanged_native_state(self):
        result = self.compare(fine=True, display_change=True)
        self.assertTrue(result["ram_16999.bin"]["identical"])
        self.assertTrue(result["vram_16999.bin"]["identical"])
        self.assertFalse(result["frame_16999.bmp"]["identical"])
        with self.assertRaisesRegex(AssertionError, "native"):
            self.compare(fine=True, native_change=True, display_change=True)
        with self.assertRaisesRegex(AssertionError, "unchanged"):
            self.compare(fine=True)


def target_draw(frame, consumer, draw_y, complete=1, include_triangle=False):
    lines = []
    targets = {**TARGETS, **FAR_TRIANGLE_TARGETS} if include_triangle else TARGETS
    for target_index, points in enumerate(targets.values()):
        packet_generation = consumer + target_index + 100
        vertices = []
        for vertex_index, (x, y) in enumerate(points):
            projection = consumer * 20 + target_index * 4 + vertex_index
            source = 0x1F800000 + vertex_index * 12
            address = 0x80090000 + target_index * 64 + vertex_index * 12
            word = (y << 16) | x
            common = f"src={source:08X} word={word:08X} projection={projection} producer=80010D4C"
            for stage, pc, addr, generation in (
                ("project", 0x80010D4C, 0, 1),
                ("mfc2", 0x80010D98, 0, 1),
                ("record", 0x80010DAC, source, 20),
                ("packet", 0x800128AC, address, packet_generation),
            ):
                lines.append(f"world-precision f={frame} {stage} pc={pc:08X} addr={addr:08X} "
                             f"generation={generation} {common}")
            vertices.append(f"world-precision f={frame} consume pc=00000000 addr={address:08X} "
                            f"generation={packet_generation} {common}")
        lines.append(f"world-precision f={frame} primitive consumer={consumer + target_index} "
                     f"complete={complete} draw_x=0 draw_y={draw_y} disp_x=0 disp_y={256 - draw_y}")
        lines.extend(vertices)
    return lines


class DisplayedWorldProof(unittest.TestCase):
    def proof(self, lines, include_triangle=False):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "trace.log"
            path.write_text("\n".join(lines) + "\n")
            return trace_proof(path, 16999, include_triangle=include_triangle)

    def test_far_triangle_requires_its_own_three_live_vertex_chains(self):
        display = ["world-precision f=16999 display x=0 y=0 w=320 h=240"]
        with self.assertRaises(AssertionError):
            self.proof(target_draw(16996, 100, 0) + display, include_triangle=True)
        proof = self.proof(target_draw(16996, 100, 0, include_triangle=True) + display,
                           include_triangle=True)
        self.assertEqual(sum(len(p["vertices"]) for p in proof["targets"].values()), 15)

    def test_selects_latest_prior_draw_of_captured_buffer(self):
        lines = target_draw(16996, 100, 0) + target_draw(16998, 200, 256)
        lines += ["world-precision f=16999 display x=0 y=0 w=320 h=240"]
        lines += target_draw(17000, 300, 0)
        proof = self.proof(lines)
        self.assertEqual({p["frame"] for p in proof["targets"].values()}, {16996})
        self.assertEqual(proof["display"]["frame"], 16999)

    def test_rejects_future_draw_even_with_same_frame_label(self):
        lines = ["world-precision f=16999 display x=0 y=0 w=320 h=240"]
        lines += target_draw(16999, 100, 0)
        with self.assertRaises(AssertionError):
            self.proof(lines)

    def test_rejects_unproven_display_and_wrong_buffer(self):
        for display in ([], ["world-precision f=16999 display x=0 y=256 w=320 h=240"]):
            with self.subTest(display=display), self.assertRaises(AssertionError):
                self.proof(target_draw(16998, 100, 0) + display)

    def test_latest_fallback_cannot_reuse_older_complete_submission(self):
        lines = target_draw(16994, 100, 0) + target_draw(16996, 200, 0, complete=0)
        lines += ["world-precision f=16999 display x=0 y=0 w=320 h=240"]
        with self.assertRaises(AssertionError):
            self.proof(lines)


if __name__ == "__main__":
    unittest.main()
