"""Catch false-empty classifications, bad ISO extents, and interleave errors."""
import io
import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import audit_voice_sources as audit


def sector(channel=1, mismatch=False):
    raw = bytearray(2352)
    raw[:12] = b"\x00" + b"\xff" * 10 + b"\x00"
    raw[15] = 2
    raw[16:20] = bytes([1, channel, 0x64, 1])
    raw[20:24] = bytes([1, 1 if mismatch else channel, 0x64, 1])
    raw[40] = 0x12
    return raw


def directory_record(name, lba, size):
    name = name.encode("ascii")
    record = bytearray(33 + len(name) + (len(name) % 2 == 0))
    record[0] = len(record)
    struct.pack_into("<I", record, 2, lba)
    struct.pack_into(">I", record, 6, lba)
    struct.pack_into("<I", record, 10, size)
    struct.pack_into(">I", record, 14, size)
    record[32] = len(name)
    record[33:33 + len(name)] = name
    return record


class VoiceSourceAuditTests(unittest.TestCase):
    def test_payload_without_xa_header_is_not_reported_empty(self):
        # A header-only classifier would hide encoded bytes behind bad metadata.
        raw = bytearray(2352)
        raw[15] = 2
        raw[-1] = 0x7f
        self.assertEqual(audit.classify_sector(raw)["kind"], "non_xa_nonzero")
        self.assertEqual(audit.classify_sector(bytearray(2352))["kind"], "zero_after_16")

    def test_duplicate_channel_mismatch_is_distinct_from_empty(self):
        got = audit.classify_sector(sector(6, mismatch=True))
        self.assertEqual(got["kind"], "subheader_mismatch")
        self.assertEqual(got["primary_channel"], 6)
        self.assertEqual(got["duplicate_channel"], 1)
        self.assertTrue(got["payload_nonzero"])

    def test_audit_addresses_channel_six_after_file_offset(self):
        # File base 2, relative start 8, channel 6 => physical LBA 16, then 24.
        disc = bytearray(30 * 2352)
        disc[16 * 2352:17 * 2352] = sector(6)
        disc[24 * 2352:25 * 2352] = sector(6, mismatch=True)
        clips = [{"name": "001AS", "offset": 8, "channel": 6, "sectors": 2}]
        got = audit.audit_extent(io.BytesIO(disc), 2, 26 * 2048, clips, 8)
        clip = got["clips"][0]
        self.assertEqual(clip["first_lba"], 16)
        self.assertEqual(clip["last_lba"], 24)
        self.assertEqual(clip["kinds"], {"xa_header_valid": 1, "subheader_mismatch": 1})
        self.assertEqual(got["physical_sectors"], 26)

    def test_root_uses_2048_logical_blocks_and_skips_directory_padding(self):
        disc = bytearray(24 * 2352)
        pvd = bytearray(2048)
        pvd[:7] = b"\x01CD001\x01"
        pvd[156:190] = directory_record("\0", 20, 4096)
        struct.pack_into("<H", pvd, 128, 2048)
        struct.pack_into(">H", pvd, 130, 2048)
        disc[16 * 2352 + 24:16 * 2352 + 2072] = pvd
        first = directory_record("STEREO.XA;1", 100, 32768)
        second = directory_record("MONO.XA;1", 120, 8192)
        disc[20 * 2352 + 24:20 * 2352 + 24 + len(first)] = first
        disc[21 * 2352 + 24:21 * 2352 + 24 + len(second)] = second
        self.assertEqual(audit.read_root_files(io.BytesIO(disc)),
                         {"STEREO.XA;1": (100, 32768), "MONO.XA;1": (120, 8192)})

    def test_clip_pointer_is_relative_to_executable_load_address(self):
        exe = bytearray(4096)
        exe[:8] = b"PS-X EXE"
        struct.pack_into("<I", exe, 24, 0x80017000)
        struct.pack_into("<4I", exe, 2048 + 64, 59776, 6, 622, 0x80017080)
        exe[2048 + 128:2048 + 134] = b"001AS\0"
        self.assertEqual(audit.read_clips(exe, 0x80017040, 1, 8),
                         [{"name": "001AS", "offset": 59776, "channel": 6, "sectors": 622}])
        # The real Japanese table also contains the lowercase suffix MX_09s.
        exe[2048 + 128:2048 + 135] = b"MX_09s\0"
        self.assertEqual(audit.read_clips(exe, 0x80017040, 1, 8)[0]["name"], "MX_09s")

    def test_short_sector_and_out_of_extent_clip_are_errors(self):
        with self.assertRaises(ValueError):
            audit.classify_sector(bytes(2336))
        with self.assertRaises(ValueError):
            audit.audit_extent(io.BytesIO(bytes(2352)), 0, 2048,
                               [{"name": "bad", "offset": 0, "channel": 6, "sectors": 2}], 8)


if __name__ == "__main__":
    unittest.main()
