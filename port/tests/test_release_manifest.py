"""Release provenance fixtures use private tiny files, never game media or devices."""
import copy
import hashlib
import importlib.util
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

TOOL = Path(__file__).resolve().parents[1] / 'tools/release_manifest.py'
ACCEPTED = '02476fe8f185c4a994ac62752f0b062e2409d6089c802e316b93f61cc3b836fc'
TARGETS = {'macos-arm64': 'arm64', 'windows-x64': 'x86_64',
           'linux-x64': 'x86_64', 'switch-aarch64': 'aarch64'}


def fixture_record(path, content=b'fixture'):
    return {'path': path, 'sha256': hashlib.sha256(content).hexdigest(), 'size': len(content)}


def fixture_manifest():
    source = fixture_record('src/game.c', b'int game;\n')
    source_hash = hashlib.sha256(json.dumps([source], sort_keys=True, separators=(',', ':'),
                                           ensure_ascii=False).encode()).hexdigest()
    return {'schema_version': 1, 'source_sha256': source_hash, 'source_files': [source],
            'generated_headers': [fixture_record('generated/font.h', b'#define FONT 1\n')],
            'archive_sha256': ACCEPTED,
            'targets': {key: {'architecture': architecture, 'archive_sha256': ACCEPTED,
                              'compiler': None, 'dependencies': [],
                              'build': {'status': 'not_run', 'evidence': []},
                              'package': {'status': 'not_run', 'evidence': []},
                              'target_smoke': {'status': 'not_run', 'evidence': []}}
                        for key, architecture in TARGETS.items()}}


def mark_built(manifest, target='macos-arm64'):
    record = manifest['targets'][target]
    record['compiler'] = {'name': 'fixture compiler', 'version': '1.0',
                          'target': record['architecture'],
                          'evidence': fixture_record(f'{target}/compiler.txt')}
    record['dependencies'] = [dict(name=name, version='1.0',
                                   evidence=fixture_record(f'{target}/{name}.txt'))
                              for name in ('SDL2', 'zlib')]
    record['build'] = {'status': 'pass', 'evidence': [fixture_record(f'{target}/build.log')],
                       'binary': fixture_record(f'{target}/alundra2')}
    return record


def mark_packaged(manifest, target='macos-arm64'):
    record = mark_built(manifest, target)
    staged_binary = fixture_record(f'{target}/staged/alundra2')
    record['package'] = {'status': 'pass',
                        'evidence': [fixture_record(f'{target}/package.log')],
                        'binary': staged_binary,
                        'provenance': {'build_binary_sha256': record['build']['binary']['sha256'],
                                       'operations': ['copy']},
                        'files': [staged_binary,
                                  {'path': f'{target}/game-data/game.a2r',
                                   'sha256': ACCEPTED, 'size': 42}]}
    return record


def transformed_package(manifest):
    record = mark_packaged(manifest)
    staged_binary = fixture_record('macos-arm64/staged/alundra2',
                                    b'fixture after dependency rewrite and signature')
    record['package']['binary'] = staged_binary
    record['package']['files'][0] = staged_binary
    record['package']['provenance']['operations'] = ['copy', 'rewrite dependencies and rpaths', 'codesign']
    return record


def macos_smoke_report(binary_sha256):
    return {'schema_version': 1, 'target': 'macos-arm64', 'architecture': 'arm64',
            'execution': 'native', 'environment': 'macos', 'os_version': 'fixture OS',
            'hardware': 'fixture hardware', 'binary_sha256': binary_sha256,
            'archive_sha256': ACCEPTED, 'result': 'pass',
            'checks': {key: 'pass' for key in ('launch', 'audio', 'controller',
                                             'save_round_trip', 'relocation', 'menu')}}


class ReleaseManifestTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        if TOOL.exists():
            spec = importlib.util.spec_from_file_location('release_manifest', TOOL)
            cls.manifest = importlib.util.module_from_spec(spec)
            spec.loader.exec_module(cls.manifest)
        else:
            cls.manifest = None

    def setUp(self):
        self.assertIsNotNone(self.manifest, 'release manifest implementation is missing')
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name)

    def write_record(self, record, content=b'fixture'):
        path = self.root / record['path']
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(content)

    def reject(self, value, pattern, **kwargs):
        with self.assertRaisesRegex(ValueError, pattern):
            self.manifest.validate_release(value, **kwargs)

    def test_draft_validates_without_missing_target_artifacts(self):
        value = fixture_manifest()
        self.manifest.validate_release(value, artifact_root=self.root)
        self.assertFalse(self.manifest.release_ready(value, artifact_root=self.root))
        self.reject(value, 'macos-arm64.*package', require_packages=True, artifact_root=self.root)

    def test_missing_extra_targets_and_architecture_are_rejected(self):
        for invalid in ('missing', 'extra', 'architecture'):
            value = fixture_manifest()
            if invalid == 'missing':
                del value['targets']['switch-aarch64']
            elif invalid == 'extra':
                value['targets']['windows-arm64'] = value['targets']['windows-x64']
            else:
                value['targets']['switch-aarch64']['architecture'] = 'x86_64'
            self.reject(value, 'targets|switch-aarch64.*architecture')

    def test_schema_hashes_and_states_are_strict(self):
        for field, bad in [('schema_version', True), ('schema_version', 2),
                           ('source_sha256', 'a' * 63), ('archive_sha256', 'f' * 64)]:
            value = fixture_manifest()
            value[field] = bad
            self.reject(value, 'schema|source|archive identity')
        value = fixture_manifest()
        value['targets']['windows-x64']['build']['status'] = 'tested'
        self.reject(value, 'windows-x64.*build')
        value = fixture_manifest()
        value['source_files'][0]['size'] = True
        self.reject(value, 'source_files.*size')

    def test_all_four_archive_identities_must_match_accepted_bytes(self):
        for target in TARGETS:
            value = fixture_manifest()
            value['targets'][target]['archive_sha256'] = 'f' * 64
            self.reject(value, target + '.*archive identity')

    def test_source_digest_and_duplicate_paths_are_rejected(self):
        value = fixture_manifest()
        value['source_files'][0]['sha256'] = '0' * 64
        self.reject(value, 'source_sha256')
        value = fixture_manifest()
        value['generated_headers'].append(copy.deepcopy(value['generated_headers'][0]))
        self.reject(value, 'generated_headers.*duplicate')

    def test_traversal_absolute_drive_and_noncanonical_paths_are_rejected(self):
        for path in ('../outside', '/tmp/outside', 'C:/outside', 'a\\b',
                     'a/../b', 'a//b', './a', 'a\nlog', ''):
            value = fixture_manifest()
            value['generated_headers'][0]['path'] = path
            self.reject(value, 'generated_headers.*path')

    def test_source_verification_rejects_changed_missing_and_symlinked_files(self):
        value = fixture_manifest()
        self.write_record(value['source_files'][0], b'int game;\n')
        self.write_record(value['generated_headers'][0], b'#define FONT 1\n')
        self.manifest.validate_release(value, source_root=self.root)
        source = self.root / 'src/game.c'
        source.write_bytes(b'changed')
        self.reject(value, 'source_files.*(size|SHA-256)', source_root=self.root)
        source.unlink()
        self.reject(value, 'source_files.*(missing|regular)', source_root=self.root)
        source.symlink_to(self.root / 'generated/font.h')
        self.reject(value, 'source_files.*symlink', source_root=self.root)

    def test_parent_directory_symlink_is_rejected(self):
        value = fixture_manifest()
        self.write_record(value['source_files'][0], b'int game;\n')
        (self.root / 'real').mkdir()
        (self.root / 'real/font.h').write_bytes(b'#define FONT 1\n')
        (self.root / 'generated').symlink_to(self.root / 'real', target_is_directory=True)
        self.reject(value, 'generated_headers.*symlink', source_root=self.root)

    def test_pass_requires_compiler_dependency_binary_and_log_identity(self):
        for missing in ('compiler', 'dependencies', 'binary', 'evidence'):
            value = fixture_manifest()
            record = mark_built(value)
            if missing in ('compiler', 'dependencies'):
                record[missing] = None if missing == 'compiler' else []
            else:
                del record['build'][missing]
            self.reject(value, 'macos-arm64.*build')

    def test_real_build_records_hash_files_but_do_not_mark_smoke_passed(self):
        value = fixture_manifest()
        record = mark_built(value)
        for file in [record['compiler']['evidence'], record['build']['binary'],
                     *record['build']['evidence'],
                     *(dependency['evidence'] for dependency in record['dependencies'])]:
            self.write_record(file)
        self.manifest.validate_release(value, artifact_root=self.root)
        self.assertFalse(self.manifest.release_ready(value, artifact_root=self.root))
        (self.root / 'macos-arm64/alundra2').write_bytes(b'changed')
        self.reject(value, 'macos-arm64.*build.*(size|SHA-256)', artifact_root=self.root)

    def test_package_requires_build_and_exactly_one_matching_archive(self):
        for defect in ('unbuilt', 'missing', 'different', 'duplicate'):
            value = fixture_manifest()
            record = mark_packaged(value)
            if defect == 'unbuilt':
                record['build']['status'] = 'not_run'
            elif defect == 'missing':
                record['package']['files'].pop()
            elif defect == 'different':
                record['package']['files'][-1]['sha256'] = 'f' * 64
            else:
                record['package']['files'].append(dict(path='other/game.a2r', sha256=ACCEPTED, size=42))
            self.reject(value, 'macos-arm64.*(build|package)')

    def test_package_accepts_transformed_executable_with_build_provenance(self):
        value = fixture_manifest()
        record = transformed_package(value)
        self.assertNotEqual(record['build']['binary']['sha256'], record['package']['binary']['sha256'])
        try:
            self.manifest.validate_release(value)
        except ValueError as error:
            self.fail(f'Packaging must allow explicit post-build rewriting/signing: {error}')
        self.assertFalse(self.manifest.release_ready(value))

    def test_package_rejects_missing_or_wrong_build_provenance(self):
        for defect in ('missing', 'wrong_origin', 'no_operations', 'malformed_operations'):
            with self.subTest(defect=defect):
                value = fixture_manifest()
                record = mark_packaged(value)
                if defect == 'missing':
                    del record['package']['provenance']
                elif defect == 'wrong_origin':
                    record['package']['provenance']['build_binary_sha256'] = 'f' * 64
                elif defect == 'no_operations':
                    record['package']['provenance']['operations'] = []
                else:
                    record['package']['provenance']['operations'] = [123]
                self.reject(value, 'macos-arm64.*package.*provenance')

    def test_package_requires_exact_staged_binary_record_in_inventory(self):
        for defect in ('missing_record', 'different_path', 'different_size'):
            with self.subTest(defect=defect):
                value = fixture_manifest()
                record = mark_packaged(value)
                if defect == 'missing_record':
                    del record['package']['binary']
                else:
                    record['package']['binary'] = copy.deepcopy(record['package']['binary'])
                    if defect == 'different_path':
                        record['package']['binary']['path'] = 'macos-arm64/unlisted/alundra2'
                    else:
                        record['package']['binary']['size'] += 1
                self.reject(value, 'macos-arm64.*package.*(binary|executable)')

    def test_smoke_qualifies_packaged_executable_after_transformation(self):
        record = transformed_package(fixture_manifest())
        report = macos_smoke_report(record['package']['binary']['sha256'])
        try:
            self.manifest.validate_smoke_report(report, 'macos-arm64', record)
        except ValueError as error:
            self.fail(f'Native smoke must bind the final packaged executable: {error}')

    def test_smoke_rejects_build_hash_when_packaged_executable_was_transformed(self):
        record = transformed_package(fixture_manifest())
        report = macos_smoke_report(record['build']['binary']['sha256'])
        with self.assertRaisesRegex(ValueError, 'macos-arm64.*target_smoke.*binary identity'):
            self.manifest.validate_smoke_report(report, 'macos-arm64', record)

    def test_passed_smoke_without_native_reports_is_rejected(self):
        value = fixture_manifest()
        record = mark_packaged(value)
        record['target_smoke'] = {'status': 'pass', 'evidence': []}
        self.reject(value, 'macos-arm64.*target_smoke')
        record['target_smoke']['evidence'] = [fixture_record('smoke.json')]
        self.assertFalse(self.manifest.release_ready(value))

    def test_smoke_report_rejects_synthetic_wrong_host_and_wrong_binary(self):
        report = {'schema_version': 1, 'target': 'windows-x64', 'architecture': 'x86_64',
                  'execution': 'native', 'environment': 'windows', 'os_version': 'fixture OS',
                  'hardware': 'fixture hardware', 'binary_sha256': fixture_record('binary')['sha256'],
                  'archive_sha256': ACCEPTED, 'result': 'pass',
                  'checks': {'launch': 'pass', 'audio': 'pass', 'controller': 'pass',
                             'save_round_trip': 'pass', 'unicode_paths': 'pass'}}
        value = fixture_manifest()
        target = mark_packaged(value, 'windows-x64')
        self.manifest.validate_smoke_report(report, 'windows-x64', target)
        for key, replacement in [('execution', 'synthetic'), ('environment', 'macos'),
                                  ('binary_sha256', 'f' * 64), ('result', 'not_run'),
                                  ('hardware', ''), ('architecture', 'arm64')]:
            bad = copy.deepcopy(report)
            bad[key] = replacement
            with self.assertRaisesRegex(ValueError, 'windows-x64.*target_smoke'):
                self.manifest.validate_smoke_report(bad, 'windows-x64', target)
        report['checks']['save_round_trip'] = 'not_run'
        with self.assertRaisesRegex(ValueError, 'save_round_trip'):
            self.manifest.validate_smoke_report(report, 'windows-x64', target)

    def test_empty_compiler_or_dependency_evidence_cannot_support_build_pass(self):
        for kind in ('compiler', 'dependency'):
            value = fixture_manifest()
            record = mark_built(value)
            evidence = (record['compiler']['evidence'] if kind == 'compiler'
                        else record['dependencies'][0]['evidence'])
            evidence.update(sha256=hashlib.sha256(b'').hexdigest(), size=0)
            self.reject(value, 'macos-arm64.*build.*empty')

    def test_smoke_report_cannot_hide_additional_failed_or_malformed_checks(self):
        value = fixture_manifest()
        target = mark_packaged(value)
        report = {'schema_version': 1, 'target': 'macos-arm64', 'architecture': 'arm64',
                  'execution': 'native', 'environment': 'macos', 'os_version': 'fixture OS',
                  'hardware': 'fixture hardware', 'binary_sha256': target['build']['binary']['sha256'],
                  'archive_sha256': ACCEPTED, 'result': 'pass',
                  'checks': {key: 'pass' for key in ('launch', 'audio', 'controller',
                                                   'save_round_trip', 'relocation', 'menu')}}
        for bad in ('fail', 'not_run', {'status': 'pass'}):
            report['checks']['extra_check'] = bad
            with self.assertRaisesRegex(ValueError, 'macos-arm64.*target_smoke'):
                self.manifest.validate_smoke_report(report, 'macos-arm64', target)

    def test_record_cli_handles_unicode_and_spaces_and_rejects_directory(self):
        relative = 'данные с пробелом/файл.bin'
        record = fixture_record(relative, b'\x00\n\r\x1a\xff')
        self.write_record(record, b'\x00\n\r\x1a\xff')
        command = [sys.executable, str(TOOL), 'record', '--root', str(self.root), '--path', relative]
        result = subprocess.run(command, capture_output=True, text=True)
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(json.loads(result.stdout), record)
        command[-1] = 'данные с пробелом'
        result = subprocess.run(command, capture_output=True, text=True)
        self.assertNotEqual(result.returncode, 0)
        self.assertIn('regular file', result.stderr)

    def test_cli_creates_hashed_draft_and_refuses_to_overwrite(self):
        self.write_record(fixture_record('src/game.c'), b'int game;\n')
        self.write_record(fixture_record('generated/font.h'), b'#define FONT 1\n')
        output = self.root / 'manifest.json'
        command = [sys.executable, str(TOOL), 'create', '--source-root', str(self.root),
                   '--source', 'src/game.c', '--generated-header', 'generated/font.h',
                   '--output', str(output)]
        first = subprocess.run(command, capture_output=True, text=True)
        self.assertEqual(first.returncode, 0, first.stderr)
        self.assertEqual(json.loads(output.read_text()), fixture_manifest())
        repeated = subprocess.run(command, capture_output=True, text=True)
        self.assertNotEqual(repeated.returncode, 0)
        validate = subprocess.run([sys.executable, str(TOOL), 'validate', str(output),
                                   '--source-root', str(self.root), '--artifact-root', str(self.root)],
                                  capture_output=True, text=True)
        self.assertEqual(validate.returncode, 0, validate.stderr)
        self.assertFalse(json.loads(validate.stdout)['release_ready'])

    def test_cli_rejects_duplicate_json_keys(self):
        manifest = self.root / 'manifest.json'
        manifest.write_text('{"schema_version":1,"schema_version":1}')
        result = subprocess.run([sys.executable, str(TOOL), 'validate', str(manifest)],
                                capture_output=True, text=True)
        self.assertNotEqual(result.returncode, 0)
        self.assertIn('duplicate JSON key', result.stderr)


if __name__ == '__main__':
    unittest.main()
