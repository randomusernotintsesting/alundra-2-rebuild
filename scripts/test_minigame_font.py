"""Hand-derived vectors for the overlay's previous-scanline font codec."""
import unittest
import struct

from a2 import minigame_font as font


class FontCodecTests(unittest.TestCase):
    def test_resource_uses_absolute_pointers_and_preserves_next_object(self):
        data = struct.pack('<III', 1, 0x8000000C, 0x8000004C) + bytes(64) + b'#abcdNEXT'
        r = font.resource(data, 0, 0x80000000, 4)
        self.assertEqual(r['pixels'], b'abcd')
        self.assertEqual(r['stream_start'], 76)
        self.assertEqual(r['stream_end'], 81)
        self.assertEqual(data[r['stream_end']:], b'NEXT')

    def test_resource_rejects_pointer_outside_file(self):
        with self.assertRaises(ValueError):
            font.resource(struct.pack('<III', 1, 0x8000, 0x8000), 0, 0)

    def test_raw_marker_consumes_only_requested_image(self):
        self.assertEqual(font.decode(b"#abcdTAIL", 4), (b"abcd", 5))

    def test_initial_history_is_zero_and_copy_length_has_plus_three(self):
        self.assertEqual(font.decode(bytes([0, 0x80, 0, 1]), 4), (bytes(4), 4))

    def test_reference_reads_previous_line_not_sliding_output(self):
        # Sixteen literal groups fill one 128-byte line. Next token copies
        # previous-line bytes 3..8, not an output-relative distance.
        first = b"".join(bytes([0]) + bytes(range(i, i + 8)) for i in range(0, 128, 8))
        stream = bytes([0]) + first + bytes([0x80, 3, 3])
        self.assertEqual(font.decode(stream, 134), (bytes(range(128)) + bytes(range(3, 9)), len(stream)))

    def test_truncation_and_cross_line_reference_fail(self):
        for raw, size in [(b"#a", 2), (b"\0", 1), (b"\0\x80\0", 3),
                          (b"\0\x80\x7f\0", 3)]:
            with self.subTest(raw=raw):
                with self.assertRaises(ValueError):
                    font.decode(raw, size)

    def test_encoder_roundtrips_line_boundaries_and_raw_fallback(self):
        for raw in (bytes(256), bytes(range(128)) * 3, bytes(range(256))):
            encoded = font.encode(raw)
            self.assertEqual(font.decode(encoded, len(raw)), (raw, len(encoded)))

    def test_encoder_can_compress_zero_scanlines(self):
        self.assertLess(len(font.encode(bytes(32768))), 1100)

    def test_known_one_line_encoding(self):
        self.assertEqual(font.encode(bytes(128)), bytes([0, 128, 0, 125]))

    def test_output_limits_and_reference_overrun_are_rejected(self):
        for raw, size in [(b'', 1), (b'#', -1), (b'#', 32769),
                          (bytes([0, 128, 0, 1]), 3)]:
            with self.subTest(raw=raw, size=size):
                with self.assertRaises(ValueError):
                    font.decode(raw, size)
        with self.assertRaises(ValueError):
            font.encode(bytes(32769))


if __name__ == "__main__":
    unittest.main()
