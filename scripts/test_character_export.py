import importlib.util
import struct
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SPEC = importlib.util.find_spec('a2.character_export')
if SPEC:
    from a2 import character_export as ce


class CharacterExportTests(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(SPEC, 'direct source character exporter is missing')

    def test_fixed_pose_translation_rotation_and_signed_wrap(self):
        ident = [4096, 0, 0, 0, 4096, 0, 0, 0, 4096]
        self.assertEqual(ce.pose_vertex([2, -3, 5], ident, [0, 0, 0], [7, 8, 9]), [9, 5, 14])
        quarter = [0, -4096, 0, 4096, 0, 0, 0, 0, 4096]
        self.assertEqual(ce.pose_vertex([2, -3, 5], quarter, [1, 2, 3], [7, 8, 9]), [8, 11, 17])
        self.assertEqual(ce.pose_vertex([32767, -32768, -1], ident, [1, -1, 0], [0, 0, 0]), [-32768, 32767, -1])
        self.assertEqual(ce.pose_vertex([-1, 1, 3], [2048,0,0,0,4096,0,0,0,4096], [0,0,0], [0,0,0]), [-1,1,3])

    def test_axis_conversion_roundtrip(self):
        for point in ([1, 2, 3], [-17, 29, -31], [0, 0, 0]):
            self.assertEqual(ce.from_blender(ce.to_blender(point)), point)
        self.assertEqual(ce.to_blender([1, 2, 3]), [1, 3, -2])

    def test_bounded_ram_rejects_alias_and_end_wrap(self):
        ram = ce.Ram(bytes(2 * 1024 * 1024))
        self.assertEqual(ram.u32(0x80000000), 0)
        for address in (0x1f800000, 0x801ffffe, 0x80200000, -1):
            with self.assertRaises(ValueError):
                ram.u32(address)

    def test_direct_faces_full_indices_variable_stride_and_corner_colors(self):
        data = bytearray(2 * 1024 * 1024)
        header = 0x1000
        struct.pack_into('<HH', data, header + 14, 2, 4)
        first = header + 24
        struct.pack_into('<H', data, first, 4)
        data[first + 4:first + 8] = bytes([0, 1, 2, 3])
        struct.pack_into('<4I', data, first + 8, 0x381e140a, 0x003c3228, 0x005a5046, 0x00786e64)
        struct.pack_into('<4I', data, first + 44, 0x3c808080, 0x00808080, 0x00808080, 0x00808080)
        second = first + 80
        data[second + 4:second + 8] = bytes([3, 1, 0, 0])
        struct.pack_into('<4I', data, second + 8, 0x30808080, 0x00808080, 0x00808080, 0x00808080)
        faces = ce.read_faces(ce.Ram(data), header, 4)
        self.assertEqual([f['source_address'] for f in faces], [0x1018, 0x1068])
        self.assertEqual(faces[0]['indices'], [0,1,2,3])
        self.assertEqual(faces[1]['indices'], [3,1,0])
        self.assertEqual(faces[0]['layers'][0]['colors'][0], [10,20,30])
        self.assertEqual(len(faces[0]['layers']), 2)
        self.assertEqual(ce.triangles(faces[0]), [[0,1,3], [1,2,3]])
        data[second + 4] = 4
        with self.assertRaises(ValueError):
            ce.read_faces(ce.Ram(data), header, 4)

    def test_palette_zero_index_is_not_automatically_transparent(self):
        vram = bytearray(1024 * 512 * 2)
        struct.pack_into('<H', vram, 0, 0)
        # CLUT at x16. Index0 can carry an opaque color.
        struct.pack_into('<H', vram, 32, 0x001f)
        self.assertEqual(ce.vram_texel(vram, 0, 1, 0, 0), [255,0,0,255,False])
        struct.pack_into('<H', vram, 32, 0x8000)
        self.assertEqual(ce.vram_texel(vram, 0, 1, 0, 0), [0,0,0,255,True])
        struct.pack_into('<H', vram, 32, 0)
        self.assertEqual(ce.vram_texel(vram, 0, 1, 0, 0), [0,0,0,0,False])

    def test_retained_complete_pose_matches_every_sequential_input(self):
        base = ROOT / 'port/build/verification/render-stability-20260906/flint-capture'
        dataset = ce.read_capture(base / 'user/ram_03000.bin', base / 'modelcap.txt', 2999)
        self.assertEqual(dataset['verified_pose_vertices'], 537)
        self.assertEqual(len(dataset['parts']), 27)
        self.assertTrue(all(p['pose_verified'] for p in dataset['parts']))
        self.assertEqual(dataset['parts'][0]['posed_vertices'][0], [-811,689,-3])
        self.assertEqual(dataset['parts'][0]['faces'][0]['indices'], [0,1,2,3])
        self.assertEqual(len(dataset['parts'][0]['faces']), 57)
        for frame in (2997, 3001):
            with self.assertRaisesRegex(ValueError, 'pose proof failed'):
                ce.read_capture(base / 'user/ram_03000.bin', base / 'modelcap.txt', frame)

    def test_stale_retained_part_pose_is_rejected(self):
        base = ROOT / 'port/build/verification/door-fixed-hd64-ir1'
        with self.assertRaisesRegex(ValueError, 'first mismatch 163'):
            ce.read_capture(base / 'user/ram_18000.bin', base / 'modelcap.txt', 18000)


if __name__ == '__main__':
    unittest.main()
