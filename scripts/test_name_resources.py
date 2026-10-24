"""Independently encoded native resource fixtures for voice-selected text."""
import ctypes as C
import os
from pathlib import Path
import struct
import subprocess
import sys
import tempfile
import unittest
import zlib

ROOT = Path(__file__).resolve().parents[1]
TEXT_FILES = ('DATA/GRP.GP', 'DATA/PACK0.PAK', 'DATA/PAKVCAST.PAK')

def fixture(variants=True, omit=None):
    rows = [(lang, name, f'base-{lang}-{name}'.encode())
            for lang in (0, 1, 2) for name in TEXT_FILES]
    rows += [(3, 'VOICE/en/002AM.adpcm', b'unchanged audio')]
    if variants:
        rows += [(lang, f'NAMES/{voice}/{name}', f'{lang}-{voice}-{name}'.encode())
                 for lang in (0, 2) for voice in ('JA', 'EN') for name in TEXT_FILES
                 if (lang, voice, name) != omit]
    n = len(rows); data_start = 64 + n * 144
    files = b''.join(struct.pack('<64sIIQIIQ', name.encode(), lang, 0, len(data), i, 1, 0)
                     for i, (lang, name, data) in enumerate(rows))
    spans = b''.join(struct.pack('<Q4I', 0, i, 0, len(data), 0)
                     for i, (_, _, data) in enumerate(rows))
    chunks = b''; offset = data_start
    for _, _, data in rows:
        chunks += struct.pack('<Q4I', offset, len(data), len(data), zlib.crc32(data), 0)
        offset += len(data)
    index = files + spans + chunks
    return struct.pack('<8s6I4Q', b'A2RES001', 1, 7, n, n, n, zlib.crc32(index),
                       64, 64+n*96, 64+n*120, data_start) + index + b''.join(r[2] for r in rows)

class NameResourcesTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temp = tempfile.TemporaryDirectory(prefix='a2-name-resources-')
        cls.work = Path(cls.temp.name); library = cls.work/'reader.dylib'
        subprocess.run([os.environ.get('CC', 'clang'), '-std=c11', '-D_POSIX_C_SOURCE=200809L',
                        '-O1', '-Wall', '-Wextra', '-Werror', '-I'+str(ROOT/'port/src'),
                        '-dynamiclib' if sys.platform == 'darwin' else '-shared', '-fPIC',
                        str(ROOT/'port/src/a2_resources.c'), str(ROOT/'port/src/platform/file_posix.c'),
                        '-lz', '-o', str(library)], check=True)
        cls.lib = C.CDLL(str(library))
        cls.lib.a2_resources_open.argtypes = [C.c_char_p, C.POINTER(C.c_void_p), C.c_void_p, C.c_size_t]
        cls.lib.a2_resources_close.argtypes = [C.c_void_p]
        cls.lib.a2_resource_find.argtypes = [C.c_void_p, C.c_int, C.c_char_p]
        cls.lib.a2_resource_size.argtypes = [C.c_void_p, C.c_uint]; cls.lib.a2_resource_size.restype = C.c_uint64
        cls.lib.a2_resource_pread.argtypes = [C.c_void_p, C.c_uint, C.c_uint64, C.c_void_p, C.c_size_t, C.c_void_p, C.c_size_t]

    @classmethod
    def tearDownClass(cls): cls.temp.cleanup()

    def setUp(self): self.store = C.c_void_p()
    def tearDown(self): self.lib.a2_resources_close(self.store)
    def open(self, **kwargs):
        path = self.work/'fixture.a2r'; path.write_bytes(fixture(**kwargs))
        error = C.create_string_buffer(256)
        self.assertEqual(self.lib.a2_resources_open(os.fsencode(path), C.byref(self.store), error, 256), 1, error.value)
    def select(self, voice):
        fn = getattr(self.lib, 'a2_resources_set_name_voice', None)
        self.assertIsNotNone(fn, 'Native lookup cannot yet select names by actual voice')
        fn.argtypes = [C.c_void_p, C.c_int]; return fn(self.store, voice)
    def find(self, lang, name): return self.lib.a2_resource_find(self.store, lang, name.encode())
    def read(self, resource):
        size = self.lib.a2_resource_size(self.store, resource); buf = C.create_string_buffer(size)
        self.assertEqual(self.lib.a2_resource_pread(self.store, resource, 0, buf, size, None, 0), 1)
        return buf.raw
    def test_all_combinations_and_existing_ids_are_stable(self):
        self.open(); previous = self.find(0, TEXT_FILES[0])
        for voice, name_voice in enumerate(('JA', 'EN')):
            self.assertEqual(self.select(voice), 1)
            for lang in (0, 2):
                for name in TEXT_FILES:
                    self.assertEqual(self.read(self.find(lang, name)), f'{lang}-{name_voice}-{name}'.encode())
            self.assertEqual(self.read(self.find(1, TEXT_FILES[0])), b'base-1-DATA/GRP.GP')
            self.assertEqual(self.read(self.find(0, 'VOICE/en/002AM.adpcm')), b'unchanged audio')
            self.assertEqual(self.read(previous), b'base-0-DATA/GRP.GP')
        self.assertEqual(self.select(7), 0)
        self.assertEqual(self.read(self.find(0, TEXT_FILES[0])), b'0-EN-DATA/GRP.GP')
    def test_legacy_archive_keeps_original_lookup(self):
        self.open(variants=False)
        self.assertEqual(self.select(1), 1)
        self.assertEqual(self.read(self.find(0, TEXT_FILES[0])), b'base-0-DATA/GRP.GP')
    def test_incomplete_variant_set_is_rejected_without_mixed_fallback(self):
        self.open(omit=(2, 'EN', TEXT_FILES[1]))
        self.assertEqual(self.select(1), 0)
        self.assertEqual(self.read(self.find(0, TEXT_FILES[0])), b'base-0-DATA/GRP.GP')

if __name__ == '__main__': unittest.main()
