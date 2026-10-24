"""Inspect actual configured release commands; this does not qualify other hosts."""
import argparse
import json
from pathlib import Path
import re
import shlex
import sys
import unittest

BUILD = Path(__file__).resolve().parents[1] / 'build/macos-arm64'
PLATFORM = 'macos-arm64'


class BuildPlatformTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.commands = json.loads((BUILD / 'compile_commands.json').read_text())
        cls.release = {}
        cls.targets = set()
        for entry in cls.commands:
            args = entry.get('arguments') or shlex.split(entry['command'])
            command = ' '.join(args)
            match = re.search(r'CMakeFiles/(a2_core|a2_host_sdl|alundra2)\.dir/', command)
            if not match:
                continue
            cls.targets.add(match[1])
            cls.release[Path(entry['file']).name] = args

    def test_common_and_host_targets_are_real_compilation_units(self):
        self.assertEqual(self.targets, {'a2_core', 'a2_host_sdl', 'alundra2'})
        for name in ('main.c', 'dispatch.c', 'gpu.c', 'native_save_guest.c',
                     'native_save_store.c', 'native_voice.c', 'a2_resources.c'):
            self.assertIn(name, self.release)

    def test_native_features_survive_target_split(self):
        required = {
            'main.c': ('A2_NATIVE_RESOURCES', 'A2_NATIVE_VOICE', 'A2_NATIVE_SAVES',
                       'A2_INPUT_PROMPTS', 'A2_PHASE_TIMING'),
            'dispatch.c': ('A2_NATIVE_SAVES',),
            'cd_hle.c': ('A2_NATIVE_RESOURCES', 'A2_NATIVE_VOICE'),
            'cdrom.c': ('A2_NATIVE_RESOURCES', 'A2_NATIVE_VOICE', 'A2_VOICE_ASSETS'),
            'gpu.c': ('A2_INPUT_PROMPTS', 'A2_HD_ART', 'A2_HD_PORTRAITS',
                      'A2_WORLD_PRECISION', 'A2_HUD_PRESENT'),
        }
        for source, definitions in required.items():
            for define in definitions:
                with self.subTest(source=source, define=define):
                    self.assertIn('-D' + define + '=1', self.release[source])

    def test_production_never_injects_controller_families(self):
        self.assertTrue(self.release)
        for source, args in self.release.items():
            self.assertFalse(any('A2_INPUT_TEST_VIRTUAL_TYPES' in arg for arg in args), source)

    def test_apple_sources_and_link_flags_are_host_scoped(self):
        objc = [name for name in self.release if name.endswith('.m')]
        reply = BUILD / '.cmake/api/v1/reply'
        index = json.loads(sorted(reply.glob('index-*.json'))[-1].read_text())
        model = json.loads((reply / index['reply']['codemodel-v2']['jsonFile']).read_text())
        target = next(target for target in model['configurations'][0]['targets']
                      if target['name'] == 'alundra2')
        details = json.loads((reply / target['jsonFile']).read_text())
        link = ' '.join(part['fragment'] for part in details['link']['commandFragments'])
        if PLATFORM == 'macos-arm64':
            self.assertIn('text_coretext.m', objc)
            self.assertNotIn('native_menu_macos.m', objc)
            self.assertNotIn('native_save_macos.m', objc)
            for source in ('menu_sdl.c', 'menu_model.c', 'save_browser_model.c'):
                self.assertIn(source, self.release)
            self.assertIn('-framework Cocoa', link.replace('"', ''))
            self.assertIn('-framework CoreText', link.replace('"', ''))
        else:
            self.assertEqual(objc, [])
            self.assertNotIn('-framework', link)
            self.assertNotIn('-stack_size', link)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--build-dir', type=Path, default=BUILD)
    parser.add_argument('--platform', choices=('macos-arm64', 'windows-x64', 'linux-x64', 'switch-aarch64'), default=PLATFORM)
    args, rest = parser.parse_known_args()
    BUILD, PLATFORM = args.build_dir, args.platform
    unittest.main(argv=[sys.argv[0], *rest])
