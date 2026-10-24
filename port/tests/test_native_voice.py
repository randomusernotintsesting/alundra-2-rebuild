"""Native voice export keeps source groups and rejects incomplete metadata."""
import importlib.util
import struct
import tempfile
import unittest
from pathlib import Path

SPEC = importlib.util.spec_from_file_location('native_voice_builder', Path(__file__).resolve().parents[1] / 'tools/build_native_voice.py')
builder = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(builder)


def fixture(path, language='ja'):
    records, audio = [], bytearray()
    for i in range(183):
        stride = 8 if i < 126 else 16
        available = language == 'ja' or i < 177
        count = 3 if i == 0 else 1
        record = (f'C{i:03}'.encode(), (0x80054758+i*16) if i < 126 else (0x80054f38+(i-126)*16),
                  i*stride, 0, 1, i*stride*4, i % stride, count, len(audio)//2352,
                  (3 if language == 'ja' else 1) if available else 0, stride, 0, 0)
        records.append(struct.pack('<16s12I', *record))
        for block in range(count if available else 0):
            raw = bytearray(2352)
            raw[15] = 2
            raw[16:20] = raw[20:24] = bytes([1, i % stride, 0x64, int(stride == 8)])
            raw[24:2328] = bytes([(i + block) % 256])*2304
            audio.extend(raw)
    header = struct.pack('<8s6I', b'A2VOICE1', 1, 183, 100000, 100000, len(audio)//2352, 11744)
    path.write_bytes(header + b''.join(records) + audio)


class NativeVoiceExport(unittest.TestCase):
    def test_exact_groups_and_metadata(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp); source = root/'source.a2v'; fixture(source)
            files = builder.export_voice(source, root/'out')
            self.assertEqual(len(files), 184)
            self.assertEqual((root/'out/VOICE/ja/C000.adpcm').read_bytes(), bytes(2304)+bytes([1])*2304+bytes([2])*2304)
            index = (root/'out/VOICE/ja/index.a2v').read_bytes()
            self.assertEqual(struct.unpack('<8s6I', index[:32]), (b'A2NVOC01',1,183,0,183,11744,0))
            row = struct.unpack_from('<16s12I', index,32)
            self.assertEqual(row[7:11], (3,3,1,8))
            self.assertNotIn(b'CD001', index)

    def test_english_has_no_fallback_payloads(self):
        with tempfile.TemporaryDirectory() as temp:
            root=Path(temp); source=root/'source.a2v'; fixture(source,'en')
            files=builder.export_voice(source,root/'out')
            self.assertEqual(len(files),178)
            self.assertFalse((root/'out/VOICE/en/C177.adpcm').exists())

    def test_original_mixed_case_cue_is_preserved(self):
        with tempfile.TemporaryDirectory() as temp:
            root=Path(temp);source=root/'source.a2v';fixture(source)
            data=bytearray(source.read_bytes());offset=32+117*64
            data[offset:offset+16]=b'MX_09s'+bytes(10);source.write_bytes(data)
            builder.export_voice(source,root/'out')
            names={p.name for p in (root/'out/VOICE/ja').iterdir()}
            self.assertIn('MX_09s.adpcm',names)
            self.assertNotIn('MX_09S.adpcm',names)

    def test_changed_coding_rejected_before_publish(self):
        with tempfile.TemporaryDirectory() as temp:
            root=Path(temp); source=root/'source.a2v'; fixture(source)
            data=bytearray(source.read_bytes()); data[11744+2352+19]=data[11744+2352+23]=0
            source.write_bytes(data)
            with self.assertRaisesRegex(ValueError,'coding'):
                builder.export_voice(source,root/'out')
            self.assertFalse((root/'out/VOICE/ja/index.a2v').exists())

    def test_invalid_name_and_truncated_pack_rejected(self):
        with tempfile.TemporaryDirectory() as temp:
            root=Path(temp); source=root/'source.a2v'; fixture(source)
            data=bytearray(source.read_bytes());data[32:36]=b'../A';source.write_bytes(data)
            with self.assertRaises(ValueError):builder.export_voice(source,root/'out')
            fixture(source); source.write_bytes(source.read_bytes()[:-1])
            with self.assertRaises(ValueError):builder.export_voice(source,root/'out')


if __name__ == '__main__': unittest.main()
