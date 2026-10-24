"""Check native launch/data discovery without booting the game or using real saves."""
import argparse
import os
import plistlib
import shutil
import subprocess
import struct
import sys
import tempfile
import unittest
from pathlib import Path

BINARY = Path(__file__).resolve().parents[1] / "build/alundra2"


class RuntimePathTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(prefix="a2 runtime paths ")
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.cwd = self.root / "unrelated working directory"
        self.cwd.mkdir()
        self.user = self.root / "personal settings" / "nested directory"
        self.env = {key: value for key, value in os.environ.items() if not key.startswith("A2_")}
        self.env.update(A2_USER_DIR=str(self.user), SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy")

    def make_data(self, disc, image):
        # --check-data checks discovery only: these are deliberately tiny,
        # synthetic fixtures, not runnable game assets.
        disc.mkdir(parents=True)
        (disc / "SCPS_101.15").write_bytes(b"PS-X EXE" + bytes(2040))
        image.parent.mkdir(parents=True, exist_ok=True)
        image.write_bytes(bytes(2352))

    def run_check(self, *args, binary=None):
        return subprocess.run([str(binary or BINARY), *map(str, args), "--check-data"],
                              cwd=self.cwd, env=self.env, text=True, capture_output=True, timeout=15)

    def make_native(self, path):
        scripts=Path(__file__).resolve().parents[2]/"scripts"
        sys.path.insert(0,str(scripts))
        try:
            from build_native_resources import Source,build_archive,RUNTIME_FILES
        finally:
            sys.path.pop(0)
        source=self.root/"native fixtures";source.mkdir(exist_ok=True)
        exe=bytearray(0x46800);exe[:8]=b"PS-X EXE"
        struct.pack_into('<I',exe,0x10,0x80039BFC)
        struct.pack_into('<II',exe,0x18,0x80017000,0x46000)
        files=[]
        # Common fallback resources demonstrate all three profile choices.
        for name in RUNTIME_FILES:
            file=source/name;file.parent.mkdir(parents=True,exist_ok=True)
            data=exe if name=="SCPS_101.15" else bytes(64)
            if name.endswith('.PAK'):data=struct.pack('<I',4)+bytes(64)
            if name.endswith('GRP.GP'):data=struct.pack('<512I',*([2048]*512))+bytes(256)
            file.write_bytes(data)
            files.append(Source(3,name,file))
        build_archive(files,path)

    def assert_native(self, result, archive):
        self.assertEqual(result.returncode,0,result.stdout+result.stderr)
        values=dict(line.split(': ',1) for line in result.stdout.splitlines() if ': ' in line)
        self.assertIn('Native resources',values,result.stdout)
        self.assertEqual(Path(values['Native resources']).resolve(),archive.resolve())
        self.assertEqual(values['Text profiles'],'ru=1 ja=1 en=1')
        self.assertEqual(values['Voices'],'ja=0 en=0')
        self.assertNotIn('Disc image',values)
        self.assertFalse(list(self.user.glob('*.mcr')))

    def test_native_archive_runs_check_with_no_disc_files(self):
        archive=self.root/'standalone/game.a2r';self.make_native(archive)
        self.env['A2_RESOURCE_ARCHIVE']=str(archive)
        self.assert_native(self.run_check(),archive)

    def test_preset_binary_finds_shared_archive_from_unrelated_cwd(self):
        build=self.root/'relocated project'/'port'/'build'
        binary=build/'macos-arm64'/'alundra2'
        binary.parent.mkdir(parents=True)
        shutil.copy2(BINARY,binary)
        archive=build/'game-data'/'game.a2r'
        self.make_native(archive)
        self.assert_native(self.run_check(binary=binary),archive)

    def test_invalid_native_archive_does_not_fall_back_to_disc(self):
        archive=self.root/'broken.a2r';archive.write_bytes(b'broken archive')
        self.env['A2_RESOURCE_ARCHIVE']=str(archive)
        result=self.run_check()
        self.assertNotEqual(result.returncode,0)
        self.assertNotIn('Disc image:',result.stdout)

    def test_native_archive_is_found_in_relocated_bundle_without_images(self):
        app=self.root/'Native Alundra 2.app';binary=app/'Contents/MacOS/alundra2'
        binary.parent.mkdir(parents=True);shutil.copy2(BINARY,binary)
        (app/'Contents/Info.plist').write_bytes(plistlib.dumps({
            'CFBundleExecutable':'alundra2','CFBundleIdentifier':'org.alundra2.path-test',
            'CFBundlePackageType':'APPL','CFBundleName':'Alundra 2'}))
        archive=app/'Contents/Resources/game-data/game.a2r';self.make_native(archive)
        moved=self.root/'Moved Native Alundra 2.app';app.rename(moved)
        self.env.update(A2_DISC_ROOT='',A2_DISC_IMAGE='')
        self.assert_native(self.run_check(binary=moved/'Contents/MacOS/alundra2'),
                           moved/'Contents/Resources/game-data/game.a2r')

    def assert_paths(self, result, disc, image):
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
        values = dict(line.split(": ", 1) for line in result.stdout.splitlines() if ": " in line)
        self.assertEqual(Path(values["Game data"]).resolve(), disc.resolve())
        self.assertEqual(Path(values["Disc image"]).resolve(), image.resolve())
        self.assertEqual(Path(values["Settings and saves"]).resolve(), self.user.resolve())
        self.assertTrue(self.user.is_dir())
        self.assertFalse(list(self.user.glob("*.mcr")), "Checking paths must not initialize cards")

    def test_explicit_missing_disc_fails_without_falling_back_to_checkout(self):
        result = self.run_check(self.root / "absent disc")
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("Game data not found", result.stderr)

    def test_explicit_missing_image_fails(self):
        disc, image = self.root / "disc", self.root / "disc.bin"
        self.make_data(disc, image)
        result = self.run_check(disc, "--boot", self.root / "absent image.bin")
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("Disc image not found", result.stderr)

    def test_explicit_paths_override_environment_from_unrelated_directory(self):
        disc, image = self.root / "disc", self.root / "disc.bin"
        self.make_data(disc, image)
        self.env.update(A2_DISC_ROOT=str(self.root / "wrong disc"),
                        A2_DISC_IMAGE=str(self.root / "wrong image.bin"))
        self.assert_paths(self.run_check(disc, "--boot", image), disc, image)

    def test_development_layout_is_relative_to_executable_not_working_directory(self):
        checkout = self.root / "checkout"
        binary = checkout / "port/build/alundra2"
        binary.parent.mkdir(parents=True)
        shutil.copy2(BINARY, binary)
        disc, image = checkout / "disc_jp", checkout / "build/alundra2_jp.bin"
        self.make_data(disc, image)
        self.assert_paths(self.run_check(binary=binary), disc, image)

    def test_bundle_resources_are_discovered_after_app_is_moved(self):
        app = self.root / "Alundra 2.app"
        binary = app / "Contents/MacOS/alundra2"
        binary.parent.mkdir(parents=True)
        shutil.copy2(BINARY, binary)
        (app / "Contents/Info.plist").write_bytes(plistlib.dumps({
            "CFBundleExecutable": "alundra2", "CFBundleIdentifier": "org.alundra2.path-test",
            "CFBundlePackageType": "APPL", "CFBundleName": "Alundra 2",
        }))
        disc = app / "Contents/Resources/game-data/disc"
        image = app / "Contents/Resources/game-data/disc.bin"
        self.make_data(disc, image)
        self.assert_paths(self.run_check(binary=binary), disc, image)
        moved = self.root / "different folder" / "Moved Alundra 2.app"
        moved.parent.mkdir()
        app.rename(moved)
        self.assert_paths(self.run_check(binary=moved / "Contents/MacOS/alundra2"),
                          moved / "Contents/Resources/game-data/disc",
                          moved / "Contents/Resources/game-data/disc.bin")

    def test_file_cannot_be_used_as_user_directory(self):
        user_file = self.root / "existing file"
        user_file.write_bytes(b"preserve this")
        self.env["A2_USER_DIR"] = str(user_file)
        result = self.run_check()
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("Cannot create the settings/save directory", result.stderr)
        self.assertEqual(user_file.read_bytes(), b"preserve this")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(add_help=False)
    parser.add_argument("--binary", type=Path, default=BINARY)
    args, remaining = parser.parse_known_args()
    BINARY = args.binary.resolve()
    unittest.main(argv=[sys.argv[0], *remaining])
