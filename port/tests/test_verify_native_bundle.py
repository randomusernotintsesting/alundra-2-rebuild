"""Pure bundle-proof fixtures: no codesign, sandbox process or game execution."""
import importlib.util
from pathlib import Path
import plistlib
import tempfile
import unittest

SOURCE = Path(__file__).resolve().parents[1] / "tools/verify_native_bundle.py"
spec = importlib.util.spec_from_file_location("verify_native_bundle", SOURCE)
verifier = importlib.util.module_from_spec(spec)
spec.loader.exec_module(verifier)


class NativeBundleProofTests(unittest.TestCase):
    def test_sbpl_quotes_backslashes_unicode_and_rejects_controls(self):
        path = Path('/private/tmp/Проверка "quoted" \\ path')
        profile = verifier.sandbox_profile([path])
        self.assertIn('\\"quoted\\"', profile)
        self.assertIn('\\\\ path', profile)
        self.assertIn('Проверка', profile)
        self.assertEqual(profile.count('(deny file-read*'), 1)
        self.assertEqual(profile.count('(deny file-write*'), 1)
        with self.assertRaises(ValueError):
            verifier.sandbox_string('/tmp/bad\npath')

    def test_inherited_media_and_driver_overrides_are_removed(self):
        env = verifier.clean_environment(dict(A2_RESOURCE_ARCHIVE='/old', A2_SKIP='1',
            SDL_VIDEO_DRIVER='cocoa', DYLD_LIBRARY_PATH='/old/lib', PATH='/usr/bin', HOME='/user'))
        self.assertEqual(env, dict(PATH='/usr/bin', HOME='/user'))

    def test_exact_owned_archive_and_relocated_bundle(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            app = root / 'Candidate.app'
            data = app / 'Contents/Resources/game-data'
            data.mkdir(parents=True)
            binary = app / 'Contents/MacOS/alundra2'
            binary.parent.mkdir()
            binary.write_bytes(b'fixture executable')
            (app / 'Contents/Info.plist').write_bytes(plistlib.dumps(dict(CFBundleExecutable='alundra2')))
            archive = data / 'game.a2r'
            archive.write_bytes(b'A2RES001')
            self.assertEqual(verifier.inspect_bundle(app, [root / 'source'])['archive'], archive.resolve())
            with self.assertRaises(ValueError):
                verifier.inspect_bundle(app, [root])
            extra = data / 'disc.bin'
            extra.write_bytes(b'old')
            with self.assertRaises(ValueError):
                verifier.inspect_bundle(app, [root / 'source'])
            extra.unlink()
            archive.unlink()
            source = root / 'outside.a2r'
            source.write_bytes(b'A2RES001')
            archive.symlink_to(source)
            with self.assertRaises(ValueError):
                verifier.inspect_bundle(app, [root / 'source'])

    def test_check_data_requires_exact_candidate_archive_and_private_user(self):
        archive, user = Path('/private/tmp/candidate/game.a2r'), Path('/private/tmp/private-user')
        log = (f'Native resources: {archive}\nText profiles: ru=1 ja=1 en=1\n'
               f'Voices: ja=1 en=1\nSettings and saves: {user}/\n')
        verifier.validate_check_data(log, archive, user)
        for invalid in (log.replace('ja=1 en=1\nSettings', 'ja=0 en=1\nSettings'),
                        log.replace(str(archive), '/old/game.a2r'),
                        log.replace(str(user), '/real-user')):
            with self.assertRaises(ValueError):
                verifier.validate_check_data(invalid, archive, user)

    @staticmethod
    def boot():
        return ('voices: native English archive ready clips=177 image_required=0\n'
                'native-resource: read EVENT00.BIN offset=0 bytes=10 async=0\n'
                'overlay -> EVENT00 (id=5) at frame 532\n'
                'voicecue: start frame=645 name=MX_11S origin=1 sectors=2296 first_sample=0 native=1\n'
                'frame limit reached (1000 frames)\n'
                'nativecd: raw_read_attempts=0 data_dma_attempts=0 fifo_attempts=0\n'
                'voicecue: end name=MX_11S reason=close consumed=112 expected=2296 frames=225792 complete=0 native=1\n')

    def test_partial_boot_cue_is_explicitly_not_full_speech_acceptance(self):
        result = verifier.validate_boot(self.boot(), 'en')
        self.assertFalse(result['complete_speech_acceptance'])
        self.assertEqual(result['voice_events'][-1]['complete'], 0)

    def test_boot_rejects_missing_events_wrong_language_and_raw_reads(self):
        for invalid in (self.boot().replace('raw_read_attempts=0', 'raw_read_attempts=1'),
                        self.boot().replace('voicecue:', 'absent:'),
                        self.boot().replace('(1000 frames)', '(900 frames)'),
                        self.boot().replace('origin=1', 'origin=3')):
            with self.assertRaises(ValueError):
                verifier.validate_boot(invalid, 'en')
        with self.assertRaises(ValueError):
            verifier.validate_boot(self.boot(), 'ja')


if __name__ == '__main__':
    unittest.main()
