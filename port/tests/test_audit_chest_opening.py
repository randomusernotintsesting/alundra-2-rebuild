#!/usr/bin/env python3
"""Acceptance-oracle tests; no emulator, renderer or application is launched."""
import copy
import importlib.util
from pathlib import Path
import struct
import unittest

SPEC = importlib.util.spec_from_file_location(
    "opening", Path(__file__).resolve().parents[1] / "tools/audit_chest_opening.py")
audit = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(audit)


def display(frame, dy, front0=1, front1=1):
    return (f"nativemesh-compose: frame={frame} dy={dy} "
            f"page0=10,{front0},0,1,1 roi0=100,90,20,20 "
            f"page1=11,{front1},0,1,1 roi1=100,90,20,20")


def poses():
    result = []
    for frame, action, angle in ((10, 130, 0), (11, 132, 500), (12, 131, 1000)):
        parts = []
        for index in (0, 1):
            matrix = [4096, 0, 0, 0, 4096, 0, 0, angle if index else 0, 4096]
            raw = bytearray(80)
            struct.pack_into("<9h", raw, 32, *matrix)
            parts.append(dict(source_mesh_index=index, registry_address=0x801B6370,
                              source_key="T02", source_sha256=audit.T02_SHA,
                              source_generation=2, valid=1, visible=1, fallback=0,
                              matrix_q12=matrix, raw_hex=raw.hex()))
        instance = dict(entity_address=0x8011A6C4, valid=1, selected_for_draw=1,
                        generation_known=1, instance_generation=1141,
                        action_id=action, parts=parts)
        result.append(dict(guest_frame=frame, draw_object_address=0x8011763C,
                           shadow_pass=0, valid=1, instances=[instance]))
    return result


def emitted(phase, captured=1, address="000fae60"):
    return (f"nativeemit: phase={phase} entry_frame=10 frame=10 registry=801b6370 "
            f"dma={address} caller=80013d18 part=801ec5a0 source_face=2 layer=0 "
            f"captured={captured} owner_valid={captured} reason={'captured' if captured else 'snapshot-invalid'}")


class OpeningAuditTest(unittest.TestCase):
    def test_only_selected_page_is_evidence(self):
        # Both totals and the other page can claim success while the front is old.
        lines = ["nativemesh: prepared=100 published=100 displayed=99",
                 display(10, 256, front0=1, front1=0)]
        result = audit.display_audit(lines, 10, 10)
        self.assertFalse(result["pass"])
        self.assertEqual(result["unpublished"][0]["page"], 1)
        self.assertTrue(audit.display_audit([display(10, 256, 0, 1)], 10, 10)["pass"])

    def test_missing_presentation_does_not_pass_from_neighbors(self):
        result = audit.display_audit([display(10, 0), display(12, 256)], 10, 12)
        self.assertFalse(result["pass"])
        self.assertEqual(result["missing_frames"], [11])

    def test_emission_requires_exact_pairs_and_valid_owner(self):
        self.assertTrue(audit.emission_audit([emitted("entry"), emitted("final")],
                                            0x801B6370, 10, 12)["pass"])
        for final in (emitted("final", 0), emitted("final", address="000faee0")):
            self.assertFalse(audit.emission_audit([emitted("entry"), final],
                                                 0x801B6370, 10, 12)["pass"])
        self.assertFalse(audit.emission_audit([], 0x801B6370, 10, 12, requested=True)["pass"])
        self.assertIsNone(audit.emission_audit([], 0x801B6370, 10, 12)["pass"])

    def test_opening_requires_actual_pose_change_and_all_actions(self):
        rows = poses()
        run = lambda data: audit.pose_audit(data, 0x8011A6C4, 0x801B6370, 10, 12)
        self.assertTrue(run(rows)["pass"])
        self.assertFalse(run(rows[:2])["pass"])
        still = copy.deepcopy(rows)
        for row in still:
            row["instances"][0]["parts"][1] = copy.deepcopy(rows[0]["instances"][0]["parts"][1])
        self.assertFalse(run(still)["pass"])

    def test_changed_source_or_generation_or_raw_pose_rejects(self):
        for change in ("hash", "generation", "raw", "invalid"):
            rows = poses()
            part = rows[1]["instances"][0]["parts"][1]
            if change == "hash":
                part["source_sha256"] = "0" * 64
            elif change == "generation":
                rows[1]["instances"][0]["instance_generation"] += 1
            elif change == "raw":
                part["matrix_q12"][0] -= 1
            else:
                rows[1]["valid"] = 0
            self.assertFalse(audit.pose_audit(rows, 0x8011A6C4, 0x801B6370, 10, 12)["pass"], change)


if __name__ == "__main__":
    unittest.main()
