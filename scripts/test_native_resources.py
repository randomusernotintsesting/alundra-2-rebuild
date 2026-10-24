"""Small independently encoded A2RES001 fixtures and logical-source tests."""
import importlib.util
import os
from pathlib import Path
import struct
import subprocess
import tempfile
import unittest
import zlib

ROOT=Path(__file__).resolve().parents[1]
FILE_BACKEND=ROOT/'port/src/platform'/('file_windows.c' if os.name=='nt' else 'file_posix.c')
COMPILER=os.environ.get('CC', 'gcc' if os.name=='nt' else 'clang')
SANITIZER=[] if os.name=='nt' else ['-fsanitize=undefined']
HEADER=struct.Struct('<8s6I4Q')
FILE=struct.Struct('<64sIIQIIQ')
SPAN=struct.Struct('<Q4I')
CHUNK=struct.Struct('<Q4I')


def fixture():
    raw=[b'ABC',b'x'*128,b'RU',b'JP']
    encoded=[raw[0],zlib.compress(raw[1]),raw[2],raw[3]]
    files=[('DATA/SHARED',3,6,0,2),('LABEL',3,2,2,1),('LABEL',0,2,3,1),('EMPTY',3,0,4,0)]
    spans=[(0,0,0,3,0),(3,1,5,3,0),(0,3,0,2,0),(0,2,0,2,0)]
    table=b''.join(FILE.pack(n.encode(),l,0,size,first,count,0) for n,l,size,first,count in files)
    table+=b''.join(SPAN.pack(*s) for s in spans)
    begin=64+len(table)+len(raw)*24;pos=begin
    for i,(a,b) in enumerate(zip(raw,encoded)):
        table+=CHUNK.pack(pos,len(b),len(a),zlib.crc32(a),i==1);pos+=len(b)
    return HEADER.pack(b'A2RES001',1,7,len(files),len(spans),len(raw),zlib.crc32(table),64,64+len(files)*96,64+len(files)*96+len(spans)*24,begin)+table+b''.join(encoded)


def reindex(data):
    data=bytearray(data);end=struct.unpack_from('<Q',data,56)[0]
    struct.pack_into('<I',data,28,zlib.crc32(data[64:end]));return bytes(data)


class ResourcesTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temp=tempfile.TemporaryDirectory(prefix='a2-resources-');cls.work=Path(cls.temp.name)
        cls.exe=cls.work/'test_resources'
        subprocess.run([COMPILER,'-std=c11','-D_POSIX_C_SOURCE=200809L','-O1','-g','-UNDEBUG',
                        *SANITIZER,'-Wall','-Wextra','-Werror','-I'+str(ROOT/'port/src'),
                        str(ROOT/'port/tests/test_resources.c'),str(ROOT/'port/src/a2_resources.c'),str(FILE_BACKEND),'-lz','-o',str(cls.exe)],check=True)
    @classmethod
    def tearDownClass(cls):cls.temp.cleanup()
    def run_fixture(self,mode,data):
        p=self.work/'fixture.a2r';p.write_bytes(data)
        result=subprocess.run([str(self.exe),mode,str(p)],capture_output=True,text=True)
        self.assertEqual(result.returncode,0,result.stdout+result.stderr)
    def test_common_override_cross_span_and_bounds(self):self.run_fixture('valid',fixture())
    def test_corrupt_payload_is_rejected_at_read(self):
        data=bytearray(fixture());data[-7]^=1;self.run_fixture('bad-payload',data)
    def test_raw_chunk_crc_failure(self):
        data=bytearray(fixture());start=struct.unpack_from('<Q',data,56)[0];data[start]^=1
        self.run_fixture('bad-payload',data)
    def test_structural_rejections(self):
        good=fixture();cases={}
        cases['truncated_header']=good[:63];cases['truncated_index']=good[:100]
        cases['trailing_payload']=good+b'x';cases['truncated_payload']=good[:-1]
        x=bytearray(good);x[64]^=1;cases['index_crc']=x
        for label,offset,fmt,value in [('offset_overflow',32,'Q',2**64-1),('count_overflow',16,'I',2**32-1),
                                    ('span_chunk_id',64+4*96+8,'I',999),('span_gap',64+4*96,'Q',1),
                                    ('span_chunk_overflow',64+4*96+12,'I',2**32-1),
                                    ('file_reserved',64+88,'Q',1),('bad_codec',64+4*96+4*24+20,'I',3),
                                    ('raw_size_zero',64+4*96+4*24+12,'I',0),
                                    ('span_reserved',64+4*96+20,'I',1),
                                    ('file_flags',64+68,'I',1),('file_span_overflow',64+80,'I',2**32-1),
                                    ('file_length_overflow',64+72,'Q',2**64-1),('invalid_profile',12,'I',8),
                                    ('raw_size_over_limit',64+4*96+4*24+12,'I',65537),
                                    ('payload_offset_overflow',64+4*96+4*24,'Q',2**64-1)]:
            x=bytearray(good);struct.pack_into('<'+fmt,x,offset,value)
            cases[label]=reindex(x) if offset>=64 else x
        for label,name in [('absolute','/DATA/SHARED'),('parent','../BAD'),('dot','DATA/./BAD'),('backslash','DATA\\BAD')]:
            x=bytearray(good);x[64:128]=name.encode().ljust(64,b'\0');cases[label]=reindex(x)
        x=bytearray(good);struct.pack_into('<I',x,64+2*96+64,3);cases['duplicate']=reindex(x)
        for label,data in cases.items():
            with self.subTest(label=label):self.run_fixture('reject',data)


class BuilderTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        spec=importlib.util.spec_from_file_location('build_native_resources',ROOT/'scripts/build_native_resources.py')
        cls.builder=importlib.util.module_from_spec(spec);spec.loader.exec_module(cls.builder)
    def test_builder_archive_reconstructs_with_c_reader_and_cache_eviction(self):
        with tempfile.TemporaryDirectory() as td:
            d=Path(td);exe=d/'reader'
            subprocess.run([COMPILER,'-std=c11','-O1','-g','-UNDEBUG',*SANITIZER,
                            '-Wall','-Wextra','-Werror','-I'+str(ROOT/'port/src'),
                            str(ROOT/'port/tests/test_resources.c'),str(ROOT/'port/src/a2_resources.c'),str(FILE_BACKEND),
                            '-lz','-o',str(exe)],check=True)
            common=d/'common';local=d/'local'
            # More unique blocks than the bounded cache; includes incompressible data.
            import random
            rng=random.Random(24)
            value=b''.join(bytes([i])*65536 for i in range(6))+rng.randbytes(65536)+b'end'
            common.write_bytes(value);local.write_bytes(b'English override')
            sources=[self.builder.Source(3,'A',common),self.builder.Source(2,'A',local)]
            archive=d/'game.a2r';self.builder.build_archive(sources,archive)
            for language,expected in [(0,value),(1,value),(2,local.read_bytes())]:
                output=d/f'extracted{language}'
                subprocess.run([str(exe),'extract',str(archive),str(language),'A',str(output)],check=True)
                self.assertEqual(output.read_bytes(),expected)
    def test_literal_dedup_requires_bytes_and_is_deterministic(self):
        with tempfile.TemporaryDirectory() as td:
            d=Path(td);a=d/'a';b=d/'b';c=d/'c';a.write_bytes(b'common'*12000);b.write_bytes(a.read_bytes());c.write_bytes(b'other!'*12000)
            sources=[self.builder.Source(0,'A',a),self.builder.Source(1,'A',b),self.builder.Source(2,'A',c)]
            out=d/'game.a2r';report=self.builder.build_archive(sources,out)
            out2=d/'again.a2r';self.builder.build_archive(list(reversed(sources)),out2)
            self.assertEqual(out.read_bytes(),out2.read_bytes())
            self.assertEqual(report['logical_bytes'],216000)
            self.assertEqual(report['unique_raw_bytes'],144000)
            self.assertEqual(report['shared_bytes'],72000)
            with self.assertRaises(FileExistsError):self.builder.build_archive(sources,out)
    def test_semantic_boundaries_retain_common_body_after_text_shift(self):
        from a2.grp import GrpArchive,Group
        from a2.pak import PakArchive
        from a2.vcast import Container
        with tempfile.TemporaryDirectory() as td:
            d=Path(td);sources=[];originals={}
            for language,text in [(0,b'ru'*40),(1,b'ja'*4)]:
                root=d/str(language);(root/'DATA').mkdir(parents=True)
                # Real PAK/VCAST parser output: variable text lengths shift later offsets.
                bank=struct.pack('<III',1000,0,0)+text
                entry=Container([b'SCRIPT'*60,bank,b'GEOMETRY'*200]).build()
                PakArchive([entry,b'unchanged'*120]).save(root/'DATA/PAKVCAST.PAK')
                PakArchive([b'SAME'*300,text,b'END'*200]).save(root/'DATA/PACK0.PAK')
                body=bytearray(0x100+400+0x100)+bytearray(text)
                struct.pack_into('<II',body,0x70,0x100+400-4,len(text))
                body[0x100:0x100+400]=b'BODY'*100
                body[0xC0:0xC5]=b'map00'
                group=Group(0,2048,body);group.aliases=list(range(512))
                GrpArchive([2048]*512,[group]).save(root/'DATA/GRP.GP')
                for p in sorted((root/'DATA').iterdir()):
                    source=self.builder.Source(language,'DATA/'+p.name,p);sources.append(source);originals[(language,source.name)]=p.read_bytes()
            result=self.builder.build_archive(sources,d/'game.a2r')
            self.assertGreater(result['shared_bytes'],3000)
            check=self.builder.verify_archive(d/'game.a2r',sources)
            self.assertEqual(check['files_verified'],6)
            self.assertEqual(check['bytes_verified'],sum(map(len,originals.values())))
    def test_hash_collision_does_not_share_different_bytes(self):
        from unittest.mock import patch
        with tempfile.TemporaryDirectory() as td:
            d=Path(td);a=d/'a';b=d/'b';a.write_bytes(b'a'*300);b.write_bytes(b'b'*300)
            class Collision:
                def digest(self):return b'0'*32
            with patch.object(self.builder.hashlib,'sha256',return_value=Collision()):
                report=self.builder.build_archive([self.builder.Source(0,'A',a),self.builder.Source(1,'A',b)],d/'game.a2r')
            self.assertEqual(report['shared_bytes'],0)
            self.assertEqual(report['chunk_count'],2)
    def test_voice_chunk_boundaries_preserve_whole_adpcm_blocks(self):
        with tempfile.TemporaryDirectory() as td:
            d=Path(td);p=d/'cue';p.write_bytes(bytes(2304*25))
            s=self.builder.Source(3,'VOICE/ja/002AM.adpcm',p)
            self.assertEqual(list(self.builder.source_ranges(s)),[(0,52992),(52992,4608)])
    def test_bad_names_duplicate_records_and_source_layout_rejected(self):
        with tempfile.TemporaryDirectory() as td:
            d=Path(td);p=d/'source';p.write_bytes(b'abc')
            for name in ['/A','../A','A/./B','A\\B','A'*64]:
                with self.subTest(name=name),self.assertRaises(ValueError):
                    self.builder.build_archive([self.builder.Source(0,name,p)],d/'bad.a2r')
            with self.assertRaises(ValueError):
                self.builder.build_archive([self.builder.Source(0,'A',p)]*2,d/'duplicate.a2r')
            with self.assertRaises(ValueError):list(self.builder.source_ranges(self.builder.Source(0,'DATA/PACK0.PAK',p)))


if __name__=='__main__':unittest.main()
