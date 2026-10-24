"""Reject stale or incomplete provenance before offline GPU replay."""
import copy
import struct
import tempfile
import unittest
from pathlib import Path

import prepare_world_capture as capture


class CaptureProofTests(unittest.TestCase):
    def camera_fixture(self):
        ram, events, primitive = self.fixture()
        updated = []
        for event in events:
            if event['stage'] == 'project':
                updated.append(dict(event, stage='project-native', kind=0, camera=0))
            if 'projection' in event:
                event.update(kind=1, camera=90, z='900.250000179')
                # A corrected vertex may legitimately leave its native cell.
                x, y = event['xy'].split(',')
                event['xy'] = f'{float(x)+1:.9f},{y}'
            updated.append(event)
        for line, event in enumerate(updated, 1):
            event['line'] = line
        return ram, updated, primitive

    def fixture(self):
        ram = bytearray(2 * 1024 * 1024)
        words = [0x30008080, 0x00040004, 0x808080, 0x0004001C,
                 0x808080, 0x001C0004]
        struct.pack_into('<7I', ram, 0x1000, (6 << 24) | 0xFFFFFF, *words)
        events = []
        vertices = []
        for i, (word, xy) in enumerate(zip(words[1::2], ('4.250000000,4.500000000',
                                                       '28.250000000,4.500000000',
                                                       '4.250000000,28.500000000'))):
            common = dict(frame=10, word=word, projection=100+i, producer=0x80010D4C,
                          xy=xy, z='900.250000000', miss=False)
            for stage, pc, addr, src, generation in (
                    ('project', 0x80010D4C, 0, 0, 0),
                    ('mfc2', 0x80010D98, 0, 0, 0),
                    ('record', 0x80010DAC, 0x1F800000+i*12, 0x1F800000+i*12, 90),
                    ('packet', 0x80012988, 0x1008+i*8, 0x1F800000+i*12, 120)):
                events.append(dict(common, stage=stage, pc=pc, addr=addr, src=src,
                                   generation=generation, line=len(events)+1))
            vertices.append(dict(common, stage='consume', pc=0, addr=0x1008+i*8,
                                 src=0x1F800000+i*12, generation=120, line=20+i))
        primitive = dict(frame=10, stage='primitive', consumer=1, complete=1,
                         draw_x=0, draw_y=0, line=19, vertices=vertices)
        events.extend([primitive, *vertices])
        return ram, events, primitive

    def test_exact_chain_and_q16_recovery(self):
        ram, events, primitive = self.fixture()
        stream, _ = capture.read_lists(ram, [0x80001000])
        polygons = capture.decode_polygons(stream)
        capture.match_sequence(polygons, [primitive])
        proof = capture.prove_primitive(primitive, events)
        self.assertEqual([v['qx'] for v in proof], [278528, 1851392, 278528])
        self.assertEqual(proof[0]['generation'], 120)
        self.assertEqual(proof[0]['source'], 0x1F800000)

    def test_ram_xy_change_or_order_change_is_rejected(self):
        ram, _, primitive = self.fixture()
        struct.pack_into('<I', ram, 0x1008, 0x00040005)
        stream, _ = capture.read_lists(ram, [0x1000])
        with self.assertRaisesRegex(ValueError, 'sequence'):
            capture.match_sequence(capture.decode_polygons(stream), [primitive])

    def test_missing_origin_is_not_inferred(self):
        _, events, primitive = self.fixture()
        events = [e for e in events if not (e['stage'] == 'project' and e['projection'] == 101)]
        with self.assertRaisesRegex(ValueError, 'project'):
            capture.prove_primitive(primitive, events)

    def test_stale_packet_generation_and_mixed_source_object_rejected(self):
        _, events, primitive = self.fixture()
        events[7]['generation'] += 1
        with self.assertRaisesRegex(ValueError, 'packet'):
            capture.prove_primitive(primitive, events)
        _, events, primitive = self.fixture()
        events[6]['generation'] += 1
        with self.assertRaisesRegex(ValueError, 'object'):
            capture.prove_primitive(primitive, events)

    def test_mutated_coordinate_metadata_and_non_q16_rejected(self):
        _, events, primitive = self.fixture()
        events[4]['xy'] = '28.750000000,4.500000000'
        with self.assertRaisesRegex(ValueError, 'metadata'):
            capture.prove_primitive(primitive, events)
        with self.assertRaisesRegex(ValueError, 'precision'):
            capture.fixed_decimal('4.123456789', 65536)

    def test_environment_and_cyclic_root_rejected(self):
        ram, _, primitive = self.fixture()
        primitive = copy.deepcopy(primitive)
        primitive['draw_y'] = 256
        stream, _ = capture.read_lists(ram, [0x1000])
        with self.assertRaisesRegex(ValueError, 'environment'):
            capture.match_sequence(capture.decode_polygons(stream), [primitive])
        struct.pack_into('<I', ram, 0x1000, (6 << 24) | 0x1000)
        with self.assertRaisesRegex(ValueError, 'cycle'):
            capture.read_lists(ram, [0x1000])

    def test_camera_native_chain_and_q24_depth(self):
        _, events, primitive = self.camera_fixture()
        proof = capture.prove_primitive(primitive, events)
        self.assertEqual(proof[0]['qx'], 344064)
        self.assertEqual(proof[0]['z'], 900.25 + 3 / 16777216)
        self.assertEqual((proof[0]['kind'], proof[0]['camera']), (1, 90))
        self.assertLess(proof[0]['lines']['project-native'], proof[0]['lines']['project'])

    def test_camera_missing_or_invalid_native_origin_rejected(self):
        for fault in ('missing', 'late', 'wrong-cell', 'wrong-kind', 'wrong-producer'):
            with self.subTest(fault=fault):
                _, events, primitive = self.camera_fixture()
                native = next(e for e in events if e['stage'] == 'project-native')
                if fault == 'missing': events.remove(native)
                elif fault == 'late': native['line'] = 1000
                elif fault == 'wrong-cell': native['xy'] = '5.250000000,4.500000000'
                elif fault == 'wrong-kind': native['kind'] = 1
                else: native['producer'] = 0x8001338C
                with self.assertRaisesRegex(ValueError, 'native'):
                    capture.prove_primitive(primitive, events)

    def test_camera_generation_and_mixed_kind_rejected(self):
        for fault in ('stale-camera', 'mixed-kind', 'changed-stage'):
            with self.subTest(fault=fault):
                _, events, primitive = self.camera_fixture()
                for e in events:
                    if 'projection' not in e or e['stage'] == 'project-native': continue
                    if fault == 'stale-camera': e['camera'] = 89
                    elif fault == 'changed-stage' and e['stage'] == 'record': e['camera'] = 89
                    elif fault == 'mixed-kind' and e['projection'] == 101:
                        e.update(kind=0, camera=0, xy='28.250000000,4.500000000', z='900.250000000')
                with self.assertRaisesRegex(ValueError, 'camera|kind|metadata'):
                    capture.prove_primitive(primitive, events)

    def test_camera_depth_and_coordinate_bounds_rejected(self):
        for field, value in [('z', '900.250000010'), ('z', '65536.000000000'),
                             ('z', '0.000000000'), ('xy', '1024.000000000,4.500000000'),
                             ('xy', 'NaN,4.500000000')]:
            with self.subTest(field=field, value=value):
                _, events, primitive = self.camera_fixture()
                for e in events:
                    if 'projection' in e and e['stage'] != 'project-native': e[field] = value
                with self.assertRaises(ValueError): capture.prove_primitive(primitive, events)

    def test_parser_camera_fields_and_legacy_defaults(self):
        text = ('world-precision f=10 project projection=100 word=00040004 kind=1 camera=90\n'
                'world-precision f=10 project projection=101 word=00040004\n')
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / 'trace.log'; path.write_text(text)
            events, _ = capture.parsed_trace(path)
        self.assertEqual([(e['kind'], e['camera']) for e in events], [(1, 90), (0, 0)])

    def test_workload_legacy_bytes_and_camera_extension(self):
        command = dict(address=0x1008, word=0x00040004, node=0x1000)
        _, events, primitive = self.fixture()
        old = capture.prove_primitive(primitive, events)[0]
        payload, schema = capture.encode_workload([command], {0x1008: old}, 123, 1, 1)
        expected = b'A2OTQ16\n' + struct.pack('<IQII', 1, 123, 1, 1)
        expected += struct.pack('<IIIqqdQQII', 0x1008, 0x00040004, 0x1000,
                                278528, 294912, 900.25, 100, 120, 0x80010D4C, 0x1F800000)
        self.assertEqual((schema, payload), (1, expected))
        _, events, primitive = self.camera_fixture()
        modern = capture.prove_primitive(primitive, events)[0]
        payload, schema = capture.encode_workload([command], {0x1008: modern}, 123, 1, 1)
        self.assertEqual((schema, payload[:8], len(payload)), (2, b'A2OTC24\n', 28+72))
        record = struct.unpack('<IIIqqdQQIIIQ', payload[28:])
        self.assertEqual(record[-2:], (1, 90))
        self.assertEqual(record[3:6], (344064, 294912, 900.25+3/16777216))


if __name__ == '__main__':
    unittest.main()
