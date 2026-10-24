"""Voice packing regressions: exact cue mapping, full duration, source integrity."""
import importlib.util
import struct
import sys
import unittest
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))

class VoicePackTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        import build_voice_pack
        cls.pack = build_voice_pack

    def test_name_mapping_preserves_full_longer_and_shorter_recordings(self):
        jp = [{'name':'FIRST','offset':0,'channel':0,'sectors':2},
              {'name':'SECOND','offset':0,'channel':1,'sectors':5},
              {'name':'MISSING','offset':40,'channel':1,'sectors':3}]
        en = [{'name':'SECOND','offset':64,'channel':1,'sectors':1},
              {'name':'FIRST','offset':16,'channel':0,'sectors':7}]
        records, span = self.pack.plan_table(jp, en, 8, 0x80054758)
        self.assertEqual([r['name'] for r in records], ['FIRST','SECOND','MISSING'])
        self.assertEqual([r['sectors'] for r in records], [7,1,3])
        self.assertEqual([r['available'] for r in records], [True,True,False])
        self.assertEqual([r['source']['offset'] if r['source'] else None for r in records], [16,64,None])
        occupied = set()
        for r in records:
            slots = {r['offset'] + r['channel'] + i * 8 for i in range(r['sectors'] + 1)}
            self.assertFalse(occupied.intersection(slots))
            occupied.update(slots)
            self.assertLess(max(slots), span)

    def test_normalization_keeps_every_encoded_sound_group_and_uses_both_headers(self):
        raw = bytearray(2352)
        raw[15] = 2; raw[16:20] = bytes([1,6,0x64,1])
        raw[20:24] = bytes([1,2,0x64,1])
        raw[24:2328] = bytes(i % 251 for i in range(2304))
        before = bytes(raw)
        normalized = self.pack.normalize_sector(raw, 3)
        self.assertEqual(normalized[16:24], bytes([1,3,0x64,1]) * 2)
        self.assertEqual(normalized[24:2328], before[24:2328])
        self.assertEqual(bytes(raw), before)
        # Independent literal EDC check uses known CRC polynomial, not builder helper.
        edc = 0
        for b in normalized[16:2348]:
            edc ^= b
            for _ in range(8):
                edc = (edc >> 1) ^ (0xD8018001 if edc & 1 else 0)
        self.assertEqual(struct.unpack_from('<I', normalized, 2348)[0], edc)

    def test_rejects_non_channel_duplicate_corruption_and_zero_sources(self):
        raw = bytearray(2352)
        with self.assertRaises(ValueError): self.pack.normalize_sector(raw, 0)
        raw[15] = 2; raw[16:20] = bytes([1,6,0x64,1]); raw[20:24] = bytes([2,2,0x64,1])
        raw[24] = 1
        with self.assertRaises(ValueError): self.pack.normalize_sector(raw, 0)

    def test_duplicate_names_and_invalid_geometry_fail(self):
        c = {'name':'DUP','offset':0,'channel':0,'sectors':1}
        with self.assertRaises(ValueError): self.pack.plan_table([c,c], [c], 8, 0x80054758)
        with self.assertRaises(ValueError): self.pack.plan_table([c], [dict(c,channel=9)], 8, 0x80054758)


class JapaneseVoicePackTests(unittest.TestCase):
    def test_complete_japanese_source_has_explicit_japanese_origin_and_all_cues(self):
        import tempfile
        import build_voice_pack as pack
        import audit_voice_sources as audit
        from test_voice_source_audit import directory_record
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            raw = bytearray(600 * 2352)
            pvd = bytearray(2048);pvd[:7]=b'\x01CD001\x01';pvd[128:132]=b'\0\x08\x08\0'
            for off,value in [(158,20),(166,2048)]:
                struct.pack_into('<I',pvd,off,value);struct.pack_into('>I',pvd,off+4,value)
            raw[16*2352+24:16*2352+2072]=pvd
            entries=[('SCPS_101.15;1',40,0x50000),('STEREO.XA;1',210,256*2048),('MONO.XA;1',466,128*2048)]
            directory=b''.join(directory_record(*e) for e in entries)
            raw[20*2352+24:20*2352+24+len(directory)]=directory
            exe=bytearray(0x50000);exe[:8]=b'PS-X EXE';struct.pack_into('<I',exe,24,0x80017000)
            cursor=0
            for table,address,count,stride in audit.TABLES['SCPS_101.15;1']:
                base=210 if stride==8 else 466
                for i in range(count):
                    name=f'C{cursor:03}'.encode();pointer=0x80061000+cursor*16
                    struct.pack_into('<4I',exe,address-0x80017000+2048+i*16,
                                     (i//stride)*stride,i%stride,1,pointer)
                    pos=pointer-0x80017000+2048;exe[pos:pos+len(name)]=name
                    sector=bytearray(2352);sector[15]=2
                    sector[16:20]=bytes([1,i%stride,0x64,1 if stride==8 else 0])
                    sector[20:24]=bytes([1,1,0x64,1 if stride==8 else 0])
                    sector[24]=1
                    raw[(base+i)*2352:(base+i+1)*2352]=sector
                    cursor+=1
            for i in range(0,len(exe),2048):raw[(40+i//2048)*2352+24:(40+i//2048)*2352+2072]=exe[i:i+2048]
            source=root/'japanese.bin';source.write_bytes(raw)
            manifest=pack.build_pack(source,source,root/'voices.a2v',language='ja')
            self.assertEqual(manifest['language'],'Japanese')
            self.assertEqual(manifest['available_clips'],183)
            self.assertEqual(manifest['unavailable_clips'],[])
            encoded=(root/'voices.a2v').read_bytes()
            self.assertEqual({struct.unpack_from('<I',encoded,32+i*64+48)[0] for i in range(183)},{3})
            self.assertEqual(source.read_bytes(),bytes(raw))

if __name__ == '__main__': unittest.main()
