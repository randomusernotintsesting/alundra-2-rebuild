import importlib.util
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
import zipfile

spec = importlib.util.spec_from_file_location(
    "package_windows", Path(__file__).resolve().parents[1] / "tools/package_windows.py")
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)
real_imports = module.imports


class PackageWindowsTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.binary = self.make("alundra2.exe", b"synthetic PE fixture")
        self.sdl = self.make("SDL2.dll", b"synthetic SDL fixture")
        self.runtime = self.make("libwinpthread-1.dll", b"synthetic runtime fixture")
        self.notice = self.make("COPYING-SDL.txt", b"Synthetic license notice")
        self.make("game.a2r", b"must never be copied")
        self.make("private.h", b"must never be copied")
        self.output = self.root / "candidate.zip"
        self.dependencies = {"alundra2.exe": ["KERNEL32.dll", "SDL2.dll"],
                             "SDL2.dll": ["api-ms-win-core-file-l1-1-0.dll", "libwinpthread-1.dll"],
                             "libwinpthread-1.dll": ["msvcrt.dll"]}
        mock = patch.object(module, "imports", side_effect=lambda path, _: self.dependencies[path.name])
        self.addCleanup(mock.stop)
        mock.start()

    def make(self, name, data):
        path = self.root / name
        path.write_bytes(data)
        return path

    def package(self, dlls=None, notices=None):
        return module.package(self.binary, dlls if dlls is not None else [self.sdl, self.runtime],
                              notices if notices is not None else [self.notice], self.output,
                              "objdump", "a" * 40, "synthetic compiler")

    def test_explicit_only_recursive_dependencies_and_manifest(self):
        digest = self.package()
        self.assertEqual(len(digest), 64)
        with zipfile.ZipFile(self.output) as archive:
            self.assertEqual(set(archive.namelist()), {"alundra2.exe", "SDL2.dll", "libwinpthread-1.dll",
                             "third-party-notices/COPYING-SDL.txt", "BUILD-MANIFEST.json", "README-Windows.txt"})

    def test_missing_transitive_dependency_fails_before_zip(self):
        with self.assertRaisesRegex(ValueError, "missing non-system dependency"):
            self.package([self.sdl])
        self.assertFalse(self.output.exists())

    def test_prior_evidence_not_overwritten(self):
        self.output.write_bytes(b"old evidence")
        with self.assertRaisesRegex(ValueError, "output exists"):
            self.package()
        self.assertEqual(self.output.read_bytes(), b"old evidence")

    def test_system_dll_and_duplicate_name_rejected(self):
        with self.assertRaisesRegex(ValueError, "not a non-system DLL"):
            self.package([self.make("kernel32.dll", b"fixture")])
        with self.assertRaisesRegex(ValueError, "duplicate DLL"):
            self.package([self.sdl, self.sdl])

    def test_notices_required_and_duplicate_rejected(self):
        with self.assertRaisesRegex(ValueError, "notice is required"):
            self.package(notices=[])
        with self.assertRaisesRegex(ValueError, "duplicate/oversized"):
            self.package(notices=[self.notice, self.notice])

    def test_x86_objdump_rejected(self):
        with patch.object(module.subprocess, "run") as run:
            run.return_value.stdout = "file format pei-i386\n DLL Name: KERNEL32.dll\n"
            with self.assertRaisesRegex(ValueError, "not a Windows x64"):
                real_imports(self.binary, "objdump")
            run.return_value.stdout = "file format pei-x86-64\n DLL Name: SDL2.dll\n"
            self.assertEqual(real_imports(self.binary, "objdump"), ["SDL2.dll"])


if __name__ == "__main__":
    unittest.main()
