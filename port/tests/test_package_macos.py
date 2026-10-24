"""Real Mach-O relocation tests; no game data or SDL installation required."""
import plistlib
import importlib.util
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

PACKAGER = Path(__file__).resolve().parents[1] / "tools" / "package_macos.py"
ICON = PACKAGER.parents[1] / "assets/Alundra.icns"


class NativeModelPackagingTests(unittest.TestCase):
    """Pure Python preflight tests; no Mach-O compile or app publication."""
    @classmethod
    def setUpClass(cls):
        spec=importlib.util.spec_from_file_location('model_packager_fixture',PACKAGER)
        cls.packager=importlib.util.module_from_spec(spec);spec.loader.exec_module(cls.packager)
        scripts=PACKAGER.parents[2]/'scripts';sys.path.insert(0,str(scripts))
        try:
            from build_native_resources import Source,build_archive
            cls.Source=Source;cls.build_archive=staticmethod(build_archive)
        finally:sys.path.pop(0)

    def archive(self,root,name='MODELS/T02.A2M',language=3):
        payload=root/'payload';payload.write_bytes(b'A2M2'+b'MODELS/T02.A2M'+bytes(239))
        target=root/'models.a2r';self.build_archive([self.Source(language,name,payload)],target)
        return target

    def test_native_models_require_archive(self):
        with self.assertRaises(RuntimeError):self.packager.native_launch_environment(True,None)
        self.assertEqual(self.packager.native_launch_environment(False,None),{'A2_LAUNCHER':'1','A2_NATIVE_SAVES':'1'})

    def test_required_model_validates_archive_without_overriding_saved_choice(self):
        with tempfile.TemporaryDirectory() as tmp:
            archive=self.archive(Path(tmp))
            env=self.packager.native_launch_environment(True,archive)
            self.assertEqual(env,{'A2_LAUNCHER':'1','A2_NATIVE_SAVES':'1'})
            self.assertNotIn('A2_MODEL_ARCHIVE',env)
            self.assertEqual(self.packager.native_media(archive),(['ru','ja','en'],[]))

    def test_payload_name_substring_or_profile_only_entry_is_not_enough(self):
        for name,language in [('FIXTURE.DAT',3),('MODELS/T02.A2M',0),('MODELS/T03.A2M',3)]:
            with tempfile.TemporaryDirectory() as tmp:
                archive=self.archive(Path(tmp),name,language)
                with self.assertRaises(RuntimeError):self.packager.native_launch_environment(True,archive)

    def test_corrupt_index_is_rejected_before_packaging(self):
        with tempfile.TemporaryDirectory() as tmp:
            archive=self.archive(Path(tmp));data=bytearray(archive.read_bytes());data[64]^=1;archive.write_bytes(data)
            with self.assertRaises(RuntimeError):self.packager.native_launch_environment(True,archive)


@unittest.skipUnless(sys.platform == "darwin", "Mach-O packaging requires macOS")
class PackageTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(prefix="a2 package test ")
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.sources = self.root / "original libraries"
        self.sources.mkdir()
        self.binary = self.root / "probe"
        self.output = self.root / "Alundra 2.app"
        leaf = self.sources / "leaf.c"
        leaf.write_text("int leaf(void) { return 7; }\n")
        middle = self.sources / "middle.c"
        middle.write_text("extern int leaf(void); int answer(void) { return leaf()*6; }\n")
        main = self.root / "probe.c"
        main.write_text("#include <stdio.h>\nextern int answer(void);\n"
                        "int main(void) { printf(\"%d\\n\", answer()); return 0; }\n")
        self.run_ok("cc", "-dynamiclib", str(leaf), "-o", str(self.sources / "libleaf.dylib"),
                    "-Wl,-headerpad_max_install_names", "-install_name",
                    str(self.sources / "libleaf.dylib"))
        self.run_ok("cc", "-dynamiclib", str(middle), str(self.sources / "libleaf.dylib"),
                    "-o", str(self.sources / "libmiddle.dylib"),
                    "-Wl,-headerpad_max_install_names", "-install_name", "@rpath/libmiddle.dylib")
        self.run_ok("cc", str(main), str(self.sources / "libmiddle.dylib"),
                    "-o", str(self.binary), "-Wl,-headerpad_max_install_names",
                    "-Wl,-rpath," + str(self.sources))

    def run_ok(self, *args):
        result = subprocess.run(args, text=True, capture_output=True)
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
        return result

    def package(self, *args):
        return self.run_ok(sys.executable, str(PACKAGER), "--binary", str(self.binary),
                           "--output", str(self.output), *args)

    def test_native_archive_is_the_only_packaged_game_data(self):
        scripts=PACKAGER.parents[2]/'scripts';sys.path.insert(0,str(scripts))
        try:
            from build_native_resources import Source,build_archive
        finally:
            sys.path.pop(0)
        source=self.root/'asset';source.write_bytes(b'compact native resource'*100)
        archive=self.root/'game.a2r'
        build_archive([Source(3,'FIXTURE.DAT',source)],archive)
        original=archive.read_bytes()
        self.package('--resource-archive',str(archive))
        info=plistlib.loads((self.output/'Contents/Info.plist').read_bytes())
        self.assertNotIn('A2_NATIVE_MESH',info['LSEnvironment'])
        moved=self.root/'Moved native.app';self.output.rename(moved)
        archive.rename(self.root/'unavailable.a2r')
        data=moved/'Contents/Resources/game-data'
        self.assertEqual([p.name for p in data.iterdir()],['game.a2r'])
        self.assertEqual((data/'game.a2r').read_bytes(),original)
        self.assertFalse((moved/'Contents/Resources/branding/contrail-hd-black.png').exists())
        self.run_ok('codesign','--verify','--deep','--strict',str(moved))
        self.assertEqual(self.run_ok(str(moved/'Contents/MacOS/alundra2')).stdout.strip(),'42')

    def test_native_model_pilot_is_explicit_and_relocatable(self):
        scripts=PACKAGER.parents[2]/'scripts';sys.path.insert(0,str(scripts))
        try:
            from build_native_resources import Source,build_archive
        finally:sys.path.pop(0)
        source=self.root/'model';source.write_bytes(b'A2M2'+bytes(252))
        archive=self.root/'pilot.a2r';build_archive([Source(3,'MODELS/T02.A2M',source)],archive)
        self.package('--resource-archive',str(archive),'--native-models')
        info=plistlib.loads((self.output/'Contents/Info.plist').read_bytes())
        self.assertEqual(info['LSEnvironment'],{'A2_LAUNCHER':'1','A2_NATIVE_SAVES':'1'})
        self.assertNotIn('A2_MODEL_ARCHIVE',info['LSEnvironment'])
        self.assertEqual((self.output/'Contents/Resources/game-data/game.a2r').read_bytes(),archive.read_bytes())
        self.sources.rename(self.root/'unavailable libraries')
        moved=self.root/'Moved pilot.app';self.output.rename(moved);archive.unlink()
        self.assertEqual(self.run_ok(str(moved/'Contents/MacOS/alundra2')).stdout.strip(),'42')
        self.run_ok('codesign','--verify','--deep','--strict',str(moved))

    def test_app_runs_after_move_without_original_transitive_libraries(self):
        # A missing recursive copy or install-name rewrite breaks the moved executable.
        disc = self.root / "disc"
        disc.mkdir()
        (disc / "SCPS_101.15").write_bytes(b"fixture exe")
        image = self.root / "disc.bin"
        image.write_bytes(b"fixture disc")
        self.package("--include-data", "--disc-root", str(disc), "--disc-image", str(image))
        self.sources.rename(self.root / "unavailable libraries")
        moved = self.root / "another location" / "Moved Game.app"
        moved.parent.mkdir()
        self.output.rename(moved)
        result = self.run_ok(str(moved / "Contents/MacOS/alundra2"))
        self.assertEqual(result.stdout.strip(), "42")
        self.assertEqual((moved / "Contents/Resources/game-data/disc.bin").read_bytes(), b"fixture disc")
        self.assertEqual((moved / "Contents/Resources/game-data/disc/SCPS_101.15").read_bytes(), b"fixture exe")
        license_source=PACKAGER.parents[1]/"assets/fonts/OFL-PTSerif.txt"
        self.assertEqual((moved/"Contents/Resources/licenses/OFL-PTSerif.txt").read_bytes(),
                         license_source.read_bytes())
        info = plistlib.loads((moved / "Contents/Info.plist").read_bytes())
        self.assertEqual(info["CFBundleExecutable"], "alundra2")
        self.assertEqual(info["CFBundleIconFile"], "Alundra.icns")
        self.assertEqual((moved / "Contents/Resources/Alundra.icns").read_bytes(),
                         ICON.read_bytes())
        self.run_ok("codesign", "--verify", "--deep", "--strict", str(moved))
        for binary in [moved / "Contents/MacOS/alundra2", *(moved / "Contents/Frameworks").glob("*.dylib")]:
            links = self.run_ok("otool", "-L", str(binary)).stdout
            self.assertNotIn(str(self.sources), links)
            load_commands = self.run_ok("otool", "-l", str(binary)).stdout
            self.assertNotIn(str(self.sources), load_commands)

    def test_profiles_voices_and_branding_are_owned_and_relocatable(self):
        # Losing optional editions/voice packs on package or retaining source
        # symlinks makes launcher selections fail after the source moves.
        disc = self.root / "disc"
        disc.mkdir()
        (disc / "SCPS_101.15").write_bytes(b"base Japanese engine")
        image = self.root / "disc.bin"
        image.write_bytes(b"base image")
        profiles = self.root / "edition sources"
        voices = self.root / "voice sources"
        for language in ("ja", "en"):
            edition = profiles / language / "disc"
            edition.mkdir(parents=True)
            (edition / "SCPS_101.15").write_bytes(language.encode() + b" compatible engine")
            (edition.parent / "disc.bin").write_bytes(language.encode() + b" image")
            pack = voices / language
            pack.mkdir(parents=True)
            (pack / "voices.a2v").write_bytes(language.encode() + b" voice pack")
        self.package("--include-data", "--disc-root", str(disc), "--disc-image", str(image),
                     "--profiles-root", str(profiles), "--voices-root", str(voices))
        moved = self.root / "Moved editions.app"
        self.output.rename(moved)
        profiles.rename(self.root / "unavailable editions")
        voices.rename(self.root / "unavailable voices")
        resources = moved / "Contents/Resources"
        for language in ("ja", "en"):
            packaged = resources / "game-data/profiles" / language
            self.assertEqual((packaged / "disc/SCPS_101.15").read_bytes(),
                             language.encode() + b" compatible engine")
            self.assertEqual((packaged / "disc.bin").read_bytes(), language.encode() + b" image")
            self.assertEqual((resources / "game-data/voices" / language / "voices.a2v").read_bytes(),
                             language.encode() + b" voice pack")
        for name in ("alundra-2-rebuild.png",):
            self.assertEqual((resources / "branding" / name).read_bytes(),
                             (PACKAGER.parents[1] / "assets/branding" / name).read_bytes())
        self.assertFalse((resources/'branding/contrail-hd-black.png').exists())
        info = plistlib.loads((moved / "Contents/Info.plist").read_bytes())
        self.assertEqual(info["CFBundleDisplayName"], "Alundra 2: Rebuild")
        self.assertEqual(info["LSEnvironment"]["A2_LAUNCHER"], "1")
        self.assertEqual(info["LSEnvironment"]["A2_NATIVE_SAVES"], "1")
        self.run_ok("codesign", "--verify", "--deep", "--strict", str(moved))
        self.assertEqual(self.run_ok(str(moved / "Contents/MacOS/alundra2")).stdout.strip(), "42")

    def test_incomplete_requested_profile_preserves_existing_app(self):
        self.package()
        old_info = (self.output / "Contents/Info.plist").read_bytes()
        disc = self.root / "disc"
        disc.mkdir()
        (disc / "SCPS_101.15").write_bytes(b"fixture")
        image = self.root / "disc.bin"
        image.write_bytes(b"fixture")
        profiles = self.root / "profiles"
        (profiles / "en/disc").mkdir(parents=True)
        (profiles / "en/disc/SCPS_101.15").write_bytes(b"fixture")
        result = subprocess.run([sys.executable, str(PACKAGER), "--binary", str(self.binary),
                                 "--output", str(self.output), "--replace", "--include-data",
                                 "--disc-root", str(disc), "--disc-image", str(image),
                                 "--profiles-root", str(profiles)], text=True, capture_output=True)
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("incomplete", result.stderr.lower())
        self.assertEqual((self.output / "Contents/Info.plist").read_bytes(), old_info)
        self.assertFalse(list(self.root.glob("Alundra 2.previous-*.app")))

    def test_existing_unknown_app_is_preserved_even_with_replace(self):
        # An unconditional replace could destroy an app unrelated to this packager.
        self.output.mkdir()
        precious = self.output / "user file"
        precious.write_text("keep me")
        result = subprocess.run([sys.executable, str(PACKAGER), "--binary", str(self.binary),
                                 "--output", str(self.output), "--replace"],
                                text=True, capture_output=True)
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("existing", result.stderr.lower())
        self.assertEqual(precious.read_text(), "keep me")

    def test_sdl2_compat_dynamic_sdl3_is_available_after_move(self):
        # SDL3 is dlopened by sdl2-compat and cannot be found with otool -L.
        dynamic = self.sources / "sdl3.c"
        dynamic.write_text("int value(void) { return 42; }\n")
        sdl3 = self.sources / "libSDL3.real.dylib"
        self.run_ok("cc", "-dynamiclib", str(dynamic), "-o", str(sdl3),
                    "-Wl,-headerpad_max_install_names")
        compat = self.sources / "compat.c"
        compat.write_text("#include <dlfcn.h>\nconst char *backend = \"sdl2-compat:\";\n"
                          "int answer(void) { void *h = dlopen(\"@loader_path/libSDL3.dylib\", RTLD_NOW);\n"
                          "if (!h) return -1; int (*value)(void) = dlsym(h, \"value\");\n"
                          "return value ? value() : -2; }\n")
        sdl2 = self.sources / "libSDL2-2.0.0.dylib"
        self.run_ok("cc", "-dynamiclib", str(compat), "-o", str(sdl2),
                    "-Wl,-headerpad_max_install_names", "-install_name", str(sdl2))
        self.run_ok("cc", str(self.root / "probe.c"), str(sdl2), "-o", str(self.binary),
                    "-Wl,-headerpad_max_install_names")
        self.package("--sdl3-library", str(sdl3))
        self.sources.rename(self.root / "unavailable libraries")
        moved = self.root / "Moved Game.app"
        self.output.rename(moved)
        self.assertEqual(self.run_ok(str(moved / "Contents/MacOS/alundra2")).stdout.strip(), "42")

    def test_replacing_our_app_keeps_previous_bundle(self):
        # Rebuilding must retain the previously generated app, including its data.
        self.package()
        old_info = (self.output / "Contents/Info.plist").read_bytes()
        self.package("--replace")
        previous = list(self.root.glob("Alundra 2.previous-*.app"))
        self.assertEqual(len(previous), 1)
        self.assertEqual((previous[0] / "Contents/Info.plist").read_bytes(), old_info)
        self.run_ok(str(self.output / "Contents/MacOS/alundra2"))


if __name__ == "__main__":
    unittest.main()
