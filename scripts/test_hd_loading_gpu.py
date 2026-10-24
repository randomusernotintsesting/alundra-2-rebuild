"""Replay the captured resident loading GT4s against the real GPU.

Only the ten loading assets are built in a temporary directory. Run this
after the paced performance measurements; it compiles a small GPU fixture.
"""
import os
from pathlib import Path
import struct
import subprocess
import tempfile
import unittest

ROOT=Path(__file__).resolve().parents[1]
EXE=ROOT/'port/build/game-data/disc/SCPS_101.15'


@unittest.skipUnless(EXE.exists(),'requires the accepted resident EXE')
class LoadingGPUIntegrationTests(unittest.TestCase):
    def test_captured_quads_locale_source_identity_and_shadow_copy(self):
        from build_hd_art import write_assets
        from build_hd_loading import build_loading,loading_source
        with tempfile.TemporaryDirectory() as temporary:
            out=Path(temporary)
            write_assets(build_loading(EXE),out/'loading_art_fixture.h',out/'previews')
            source=loading_source(EXE)
            lines=['#include <stdint.h>']
            for name,ctype,values in (
                ('loading_indices','uint8_t',source['indices']),
                ('loading_palette','uint16_t',
                 [v for v, in struct.iter_unpack('<H',source['palette'])])):
                lines.append(f'static const {ctype} {name}[]={{')
                lines.extend(','.join(str(v) for v in values[n:n+32])+','
                             for n in range(0,len(values),32))
                lines.append('};')
            (out/'loading_source_fixture.h').write_text('\n'.join(lines)+'\n')
            binary=out/'loading-gpu'
            subprocess.run([os.environ.get('CC','cc'),'-std=c11','-O1',
                '-fsanitize=undefined','-fno-sanitize-recover=all',
                '-I'+str(ROOT/'port/src'),'-I'+str(out),
                str(ROOT/'port/tests/test_hd_loading_gpu.c'),
                str(ROOT/'port/src/hd_art.c'),'-o',str(binary)],check=True)
            subprocess.run([str(binary)],check=True,
                env=dict(os.environ,A2_HDUI='1',A2_FILTER='0'))


if __name__=='__main__':unittest.main()
