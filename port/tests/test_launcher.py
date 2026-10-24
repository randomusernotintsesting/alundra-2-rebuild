"""Exercise run.sh with isolated executable fixtures; never start the game."""
import os
from pathlib import Path
import shutil
import subprocess
import tempfile
import unittest

PORT = Path(__file__).resolve().parents[1]


class LauncherTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(prefix='a2 launcher путь ')
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.port = self.root / 'project with spaces' / 'port'
        self.port.mkdir(parents=True)
        shutil.copy2(PORT / 'run.sh', self.port / 'run.sh')
        self.env = {k: v for k, v in os.environ.items() if not k.startswith('A2_')}
        self.preset = 'macos-arm64'
        self.fake_bin = self.root / 'host tools'
        self.fake_bin.mkdir()
        self.env['PATH'] = str(self.fake_bin) + os.pathsep + self.env['PATH']
        self.host('Darwin', 'arm64')

    def host(self, system, machine):
        uname = self.fake_bin / 'uname'
        uname.write_text('#!/bin/sh\ncase "$1" in\n'
                         f'-s) printf "%s\\n" "{system}" ;;\n'
                         f'-m) printf "%s\\n" "{machine}" ;;\nesac\n')
        uname.chmod(0o755)

    def binary(self, relative):
        p = self.port / relative
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_text('#!/bin/sh\n'
                     'printf "binary=%s\\n" "$0"\n'
                     'printf "skip=%s\\nsixty=%s\\nlauncher=%s\\nsaves=%s\\n" '
                     '"$A2_SKIP" "$A2_60" "$A2_LAUNCHER" "$A2_NATIVE_SAVES"\n'
                     'for arg do printf "arg=%s\\n" "$arg"; done\n')
        p.chmod(0o755)
        return p

    def run_launcher(self, *args):
        return subprocess.run(['sh', str(self.port / 'run.sh'), *args],
                              cwd=self.root, env=self.env, text=True,
                              capture_output=True, timeout=5)

    def test_prefers_current_preset_to_legacy_binary(self):
        self.binary('build/alundra2')
        self.binary(f'build/{self.preset}/alundra2')
        result = self.run_launcher('--check-data')
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn(f'/build/{self.preset}/alundra2\n', result.stdout)
        self.assertIn('arg=--check-data\n', result.stdout)

    def test_linux_x64_uses_its_own_preset(self):
        self.host('Linux', 'x86_64')
        self.binary('build/macos-arm64/alundra2')
        self.binary('build/linux-x64/alundra2')
        self.binary('build/alundra2')
        result = self.run_launcher()
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn('/build/linux-x64/alundra2\n', result.stdout)

    def test_other_hosts_use_legacy_without_foreign_preset(self):
        self.binary('build/macos-arm64/alundra2')
        self.binary('build/linux-x64/alundra2')
        self.binary('build/alundra2')
        for system, machine in [('Darwin', 'x86_64'), ('Linux', 'aarch64'),
                                ('FreeBSD', 'amd64')]:
            with self.subTest(system=system, machine=machine):
                self.host(system, machine)
                result = self.run_launcher()
                self.assertEqual(result.returncode, 0, result.stderr)
                self.assertIn('/build/alundra2\n', result.stdout)

    def test_legacy_fallback_preserves_each_argument(self):
        self.binary('build/alundra2')
        result = self.run_launcher('--boot', '/path with spaces/игра.bin')
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn('arg=--boot\narg=/path with spaces/игра.bin\n', result.stdout)
        self.assertIn('launcher=1\nsaves=1\n', result.stdout)

    def test_explicit_binary_has_priority(self):
        self.binary('build/alundra2')
        self.binary(f'build/{self.preset}/alundra2')
        self.env['A2_BINARY'] = str(self.binary('custom path/игра'))
        result = self.run_launcher()
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn('binary=' + self.env['A2_BINARY'] + '\n', result.stdout)

    def test_invalid_explicit_binary_does_not_fall_back(self):
        self.binary('build/alundra2')
        self.env['A2_BINARY'] = str(self.port / 'missing binary')
        result = self.run_launcher()
        self.assertNotEqual(result.returncode, 0)
        self.assertIn('A2_BINARY', result.stderr)
        self.assertNotIn('binary=', result.stdout)

    def test_missing_binary_explains_build_command(self):
        result = self.run_launcher()
        self.assertNotEqual(result.returncode, 0)
        self.assertIn('cmake --build', result.stderr)

    def test_modes_set_flags_and_forward_remaining_arguments(self):
        self.binary('build/alundra2')
        for mode in ('play', 'remake', 'fps60'):
            with self.subTest(mode=mode):
                result = self.run_launcher(mode, '--check-data')
                self.assertEqual(result.returncode, 0, result.stderr)
                self.assertIn('skip=1\n', result.stdout)
                self.assertIn('sixty=' + ('1' if mode == 'fps60' else '') + '\n', result.stdout)
                self.assertIn('arg=--check-data\n', result.stdout)
                self.assertNotIn('arg=' + mode + '\n', result.stdout)

    def test_non_executable_preset_uses_legacy(self):
        preset = self.binary(f'build/{self.preset}/alundra2')
        preset.chmod(0o644)
        self.binary('build/alundra2')
        self.assertEqual(self.run_launcher().returncode, 0)


if __name__ == '__main__':
    unittest.main()
