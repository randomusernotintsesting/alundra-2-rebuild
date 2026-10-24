"""Portable archive model opt-in, identity, sharing, and no-replace fixtures."""
import tempfile
import unittest
import struct
from pathlib import Path

import build_native_resources as resources
from a2.native_model import pack_model
from test_native_model import triangle_model

HASHES={'T02':'fbbc6ed20a3fc8cf8ac69e1c1af74a8ae44d451fcfbb47302321c1182fefabf1','T03':'d77d72f180a3f84691f40bdcade2a20195de67855e71e71ef4470e55857805be'}

class ModelArchiveTests(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory();self.addCleanup(self.temp.cleanup);self.root=Path(self.temp.name)
        self.game=self.root/'game';self.models=self.root/'models';(self.models/'MODELS').mkdir(parents=True)
        for relative in ('disc','profiles/ja/disc','profiles/en/disc'):
            for name in resources.RUNTIME_FILES:
                path=self.game/relative/name;path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(b'placeholder')
        for key in ('T02','T03'):
            model=triangle_model();model['source_key']=key;model['source_sha256']=HASHES[key]
            (self.models/f'MODELS/{key}.A2M').write_bytes(pack_model(model))

    def test_optional_root_preserves_existing_collection(self):
        plain=resources.collect_sources(self.game)
        added=resources.collect_sources(self.game,model_root=self.models)
        self.assertEqual(added[:len(plain)],plain)
        self.assertEqual([(s.language,s.name) for s in added[len(plain):]],[(3,'MODELS/T02.A2M'),(3,'MODELS/T03.A2M')])

    def test_optional_flint_signed_colors_are_shared_and_verified(self):
        model=triangle_model();model.update(source_key='PC00',
            source_sha256='b6cbf3c4d4cf456f4921dde96ba769d092143e855a282ca5ff87977f309eb720',file_flags=1)
        model['vertices'][0]['color'][0][0]=-.074
        path=self.models/'MODELS/PC00.A2M';original=pack_model(model);path.write_bytes(original)
        sources=resources.collect_model_sources(self.models)
        self.assertEqual([(s.language,s.name) for s in sources],
                         [(3,'MODELS/T02.A2M'),(3,'MODELS/T03.A2M'),(3,'MODELS/PC00.A2M')])
        archive=self.root/'with-flint.a2r';resources.build_archive(sources,archive)
        self.assertEqual(resources.verify_archive(archive,sources)['files_verified'],3)
        for offset,value in [(24,struct.pack('<I',2)),(128,bytes(32)),(160,b'PC01')]:
            bad=bytearray(original);bad[offset:offset+len(value)]=value;path.write_bytes(bad)
            with self.assertRaises(ValueError):resources.collect_model_sources(self.models)

    def test_allowlist_ignores_other_files_but_requires_both_chests(self):
        (self.models/'MODELS/UNTRUSTED.A2M').write_bytes(b'junk')
        self.assertEqual(len(resources.collect_model_sources(self.models)),2)
        (self.models/'MODELS/T03.A2M').unlink()
        with self.assertRaises(FileNotFoundError):resources.collect_model_sources(self.models)

    def test_wrong_key_and_wrong_source_hash_rejected(self):
        path=self.models/'MODELS/T02.A2M';original=path.read_bytes()
        for offset,value in [(160,b'T03'),(128,bytes(32)),(128,bytes.fromhex(HASHES['T03']))]:
            bad=bytearray(original);bad[offset:offset+len(value)]=value;path.write_bytes(bad)
            with self.assertRaises(ValueError):resources.collect_model_sources(self.models)

    def test_bad_header_extent_and_overlapping_sections_rejected(self):
        path=self.models/'MODELS/T02.A2M';original=path.read_bytes()
        mutations=[original[:200],original[:-1],original+b'\0']
        for off,fmt,value in [(8,'I',2),(24,'I',1),(32,'I',1000001),(56,'I',3),(60,'I',1),(64,'Q',0),(72,'Q',256),(112,'Q',len(original)),(216,'I',1)]:
            bad=bytearray(original);struct.pack_into('<'+fmt,bad,off,value);mutations.append(bad)
        for bad in mutations:
            path.write_bytes(bad)
            with self.assertRaises(ValueError):resources.collect_model_sources(self.models)

    def test_models_only_archive_is_shared_deduplicated_and_never_replaced(self):
        sources=resources.collect_model_sources(self.models);archive=self.root/'models.a2r'
        result=resources.build_archive(sources,archive)
        self.assertEqual(result['file_count'],2)
        self.assertEqual(resources.verify_archive(archive,sources)['files_verified'],2)
        # Shared language3 resources resolve identically for all three profiles.
        aliases=[resources.Source(lang,s.name,s.path) for lang in range(3) for s in sources]
        self.assertEqual(resources.verify_archive(archive,aliases)['files_verified'],6)
        before=archive.read_bytes()
        with self.assertRaises(FileExistsError):resources.build_archive(sources,archive)
        self.assertEqual(archive.read_bytes(),before)
        # Native archive chunk dedup remains available and independent of name.
        duplicate=resources.build_archive([sources[0],resources.Source(3,'MODELS/COPY.A2M',sources[0].path)],self.root/'dedup.a2r')
        self.assertGreater(duplicate['shared_bytes'],0)

if __name__=='__main__':unittest.main()
