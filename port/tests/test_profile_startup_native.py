"""Startup comparison preparation only; never launch native workloads."""
import importlib.util
import json
from pathlib import Path
import tempfile
import unittest

spec=importlib.util.spec_from_file_location('startup',Path(__file__).resolve().parents[1]/'tools/profile_startup_native.py')
startup=importlib.util.module_from_spec(spec);spec.loader.exec_module(startup)

class StartupTests(unittest.TestCase):
    def test_reference_copy_changes_only_executable_private_paths_and_records_identity(self):
        with tempfile.TemporaryDirectory() as tmp:
            root=Path(tmp).resolve();ref=root/'before';user=ref/'user';(user/'Saves').mkdir(parents=True)
            (user/'Saves/seed.a2save').write_bytes(b'owned seed')
            (user/'a2settings.ini').write_text('key_0=0\n')
            binary=root/'candidate';binary.write_bytes(b'fixture executable; never launched')
            archive=root/'game.a2r';archive.write_bytes(b'fixture resources')
            env=dict(A2_USER_DIR=str(user),A2_RESOURCE_ARCHIVE=str(archive),A2_MAXFRAMES='3600',
                     A2_TIMEOUT='145',A2_IRSCALE='4',SDL_VIDEODRIVER='cocoa')
            manifest=dict(command=['/old/binary','--boot'],env=env,
                          archive_sha256=startup.sha(archive),seed_sha256=startup.sha(user/'Saves/seed.a2save'))
            (ref/'launch.json').write_text(json.dumps(manifest))
            (ref/'result.json').write_text(json.dumps(dict(completed=True,exit_code=0,frames=3600)))
            output=root/'after';plan=startup.prepare(ref,binary,None,output)
            self.assertEqual(plan['env']['A2_IRSCALE'],'4')
            self.assertEqual(plan['command'],[str(binary),'--boot'])
            self.assertEqual(plan['env']['A2_USER_DIR'],str(output/'user'))
            self.assertEqual((output/'user/Saves/seed.a2save').read_bytes(),b'owned seed')
            self.assertEqual((ref/'launch.json').read_text(),json.dumps(manifest))
            with self.assertRaises(FileExistsError):startup.prepare(ref,binary,None,output)
            manifest['env']['A2_CONTROL_FILE']='/accidental/replay'
            (ref/'launch.json').write_text(json.dumps(manifest))
            with self.assertRaisesRegex(ValueError,'diagnostic'):
                startup.prepare(ref,binary,None,root/'bad')
            self.assertFalse((root/'bad').exists())

if __name__=='__main__':unittest.main()
