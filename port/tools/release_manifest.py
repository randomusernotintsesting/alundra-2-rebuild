#!/usr/bin/env python3
"""Versioned release provenance, independent from building or executing a game.

``create`` hashes only explicitly selected source/generated files and records a
four-target draft. ``record`` hashes one regular file. Paths use canonical POSIX
syntax relative to the supplied source/artifact roots, including on Windows.
``validate`` checks metadata; supplying roots also verifies recorded file bytes.
No absent target, package or native test is inferred to have passed.

A passed package records its complete staged file inventory, including exactly
one accepted game.a2r and package.binary, the final packaged executable. The
original build.binary remains a separate identity: package.provenance records
its build_binary_sha256 and the packaging operations that produced the staged
executable (for example copying, dependency rewriting and signing). Existing
package.evidence supplies the hash-addressed packaging reports. Native smoke
reports bind binary_sha256 to package.binary after every packaging operation.
Container/dependency/signature and
executable architecture inspection belong to the platform packaging verifier;
its hash-addressed report belongs in package.evidence. This provenance contract
cannot authenticate a person's native-run attestation or prove an inventory is
complete. It checks that attached native reports identify the right environment
and bytes. Actual hardware execution and package inspection remain separate work.
"""
import argparse
import hashlib
import json
from pathlib import Path, PurePosixPath
import re
import sys

SCHEMA_VERSION = 1
ACCEPTED_ARCHIVE_SHA256 = '02476fe8f185c4a994ac62752f0b062e2409d6089c802e316b93f61cc3b836fc'
TARGET_ARCHITECTURES = {'macos-arm64': 'arm64', 'windows-x64': 'x86_64',
                        'linux-x64': 'x86_64', 'switch-aarch64': 'aarch64'}
STATUSES = frozenset(('pass', 'fail', 'not_run', 'blocked_external'))
GATES = ('build', 'package', 'target_smoke')
ENVIRONMENTS = {'macos-arm64': {'macos'}, 'windows-x64': {'windows'},
                'linux-x64': {'linux-desktop', 'steam-deck'},
                'switch-aarch64': {'switch-application'}}
COMMON_CHECKS = {'launch', 'audio', 'controller', 'save_round_trip'}
EXTRA_CHECKS = {'macos': {'relocation', 'menu'},
                'windows': {'unicode_paths'},
                'linux-desktop': {'relocation'},
                'steam-deck': {'gaming_mode_1280x800', 'suspend_resume'},
                'switch-application': {'application_mode', 'paced_gameplay'}}


def require(condition, message):
    if not condition:
        raise ValueError(message)


def nonempty_string(value):
    return isinstance(value, str) and bool(value.strip()) and not any(ord(c) < 32 for c in value)


def check_hash(value, label):
    require(isinstance(value, str) and re.fullmatch('[0-9a-f]{64}', value) is not None,
            f'{label}: expected lowercase SHA-256')


def check_path(value, label):
    require(nonempty_string(value) and '\\' not in value and ':' not in value and
            not any(ord(c) == 127 for c in value), f'{label}: invalid relative path')
    path = PurePosixPath(value)
    require(not path.is_absolute() and path.parts and
            all(part not in ('', '.', '..') for part in value.split('/')) and
            str(path) == value, f'{label}: path must be canonical and relative')
    return path


def owned_file(root, relative, label):
    parts = check_path(relative, label).parts
    base = Path(root).resolve(strict=True)
    require(base.is_dir(), f'{label}: root is not a directory')
    path = base
    for part in parts:
        path = path / part
        require(not path.is_symlink(), f'{label}: symlink is not an owned regular file: {relative}')
    require(path.is_file(), f'{label}: missing regular file: {relative}')
    require(path.resolve().is_relative_to(base), f'{label}: path escapes root')
    return path


def file_record(root, relative):
    """Hash an existing regular file under root, refusing symlink components."""
    path = owned_file(root, relative, 'record')
    digest = hashlib.sha256()
    size = 0
    with path.open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            digest.update(block)
            size += len(block)
    return {'path': relative, 'sha256': digest.hexdigest(), 'size': size}


def validate_file(record, label, root=None):
    require(isinstance(record, dict) and set(record) == {'path', 'sha256', 'size'},
            f'{label}: expected path, sha256 and size file record')
    check_path(record['path'], label)
    check_hash(record['sha256'], label)
    require(type(record['size']) is int and record['size'] >= 0, f'{label}: invalid size')
    if root is not None:
        path = owned_file(root, record['path'], label)
        require(path.stat().st_size == record['size'], f'{label}: size mismatch: {record["path"]}')
        actual = file_record(root, record['path'])
        require(actual['sha256'] == record['sha256'], f'{label}: SHA-256 mismatch: {record["path"]}')
        require(actual['size'] == record['size'], f'{label}: size changed while hashing')
    return record


def validate_files(records, label, root=None, required=False):
    require(isinstance(records, list), f'{label}: expected file list')
    require(not required or records, f'{label}: missing file evidence')
    seen = set()
    for index, record in enumerate(records):
        validate_file(record, f'{label}[{index}]', root)
        require(record['path'] not in seen, f'{label}: duplicate path {record["path"]}')
        seen.add(record['path'])
    return records


def source_digest(records):
    """SHA-256 of UTF-8 canonical JSON file records ordered by relative path."""
    canonical = json.dumps(sorted(records, key=lambda record: record['path']),
                           ensure_ascii=False, sort_keys=True, separators=(',', ':'))
    return hashlib.sha256(canonical.encode('utf-8')).hexdigest()


def _unique_object(pairs):
    result = {}
    for key, value in pairs:
        require(key not in result, f'duplicate JSON key: {key}')
        result[key] = value
    return result


def load_manifest(path):
    with Path(path).open(encoding='utf-8') as stream:
        return json.load(stream, object_pairs_hook=_unique_object)


def validate_smoke_report(report, target, record):
    """Validate native-run identity/required results, without executing hardware."""
    label = f'{target}.target_smoke'
    require(isinstance(report, dict), f'{label}: expected JSON native report')
    require(type(report.get('schema_version')) is int and report['schema_version'] == 1,
            f'{label}: unsupported report schema')
    require(report.get('target') == target, f'{label}: report target mismatch')
    require(report.get('architecture') == TARGET_ARCHITECTURES[target],
            f'{label}: report architecture mismatch')
    require(report.get('execution') == 'native', f'{label}: execution must be native')
    environment = report.get('environment')
    require(isinstance(environment, str) and environment in ENVIRONMENTS[target],
            f'{label}: wrong native environment')
    for field in ('os_version', 'hardware'):
        require(nonempty_string(report.get(field)), f'{label}: missing {field}')
    require(report.get('binary_sha256') == record['package']['binary']['sha256'],
            f'{label}: packaged binary identity mismatch')
    require(report.get('archive_sha256') == ACCEPTED_ARCHIVE_SHA256,
            f'{label}: archive identity mismatch')
    require(report.get('result') == 'pass', f'{label}: report has no passing result')
    checks = report.get('checks')
    require(isinstance(checks, dict), f'{label}: missing check outcomes')
    for check in sorted(COMMON_CHECKS | EXTRA_CHECKS[environment]):
        require(checks.get(check) == 'pass', f'{label}: {check} is not pass')
    require(all(result == 'pass' for result in checks.values()),
            f'{label}: report contains a non-passing check outcome')
    return environment


def _validate_gate(record, target, gate, artifact_root):
    label = f'{target}.{gate}'
    value = record.get(gate)
    require(isinstance(value, dict), f'{label}: missing gate')
    status = value.get('status')
    require(isinstance(status, str) and status in STATUSES, f'{label}: invalid status')
    evidence = validate_files(value.get('evidence'), f'{label}.evidence', artifact_root,
                              required=status == 'pass')
    if status == 'pass':
        require(all(file['size'] > 0 for file in evidence), f'{label}: empty evidence file')
    if status in ('fail', 'blocked_external'):
        require(nonempty_string(value.get('reason')), f'{label}: missing failure/block reason')
    return value


def validate_release(manifest, artifact_root=None, source_root=None,
                     require_packages=False, require_smoke=False):
    """Reject malformed provenance; roots additionally verify the actual files.

    A draft needs no target artifacts. Complete package/smoke verification needs
    artifact_root; release_ready also requires source_root. Validation alone does
    not claim successful builds, complete package inspection or device execution.
    """
    require(isinstance(manifest, dict), 'manifest: expected JSON object')
    require(type(manifest.get('schema_version')) is int and manifest['schema_version'] == SCHEMA_VERSION,
            'schema_version: unsupported release manifest')
    for field in ('source_files', 'generated_headers'):
        validate_files(manifest.get(field), field, source_root, required=True)
    check_hash(manifest.get('source_sha256'), 'source_sha256')
    require(manifest['source_sha256'] == source_digest(manifest['source_files']),
            'source_sha256: source inventory digest mismatch')
    require(manifest.get('archive_sha256') == ACCEPTED_ARCHIVE_SHA256,
            'archive identity: expected the accepted game.a2r SHA-256')
    targets = manifest.get('targets')
    require(isinstance(targets, dict) and set(targets) == set(TARGET_ARCHITECTURES),
            'targets: expected exactly macos-arm64, windows-x64, linux-x64, switch-aarch64')
    for target, architecture in TARGET_ARCHITECTURES.items():
        record = targets[target]
        require(isinstance(record, dict), f'{target}: expected target record')
        require(record.get('architecture') == architecture, f'{target}: architecture mismatch')
        require(record.get('archive_sha256') == ACCEPTED_ARCHIVE_SHA256,
                f'{target}: archive identity mismatch')
        gates = {gate: _validate_gate(record, target, gate, artifact_root) for gate in GATES}
        compiler = record.get('compiler')
        if compiler is not None:
            require(isinstance(compiler, dict), f'{target}.build: invalid compiler')
            for field in ('name', 'version', 'target'):
                require(nonempty_string(compiler.get(field)), f'{target}.build: missing compiler {field}')
            validate_file(compiler.get('evidence'), f'{target}.build.compiler.evidence', artifact_root)
        dependencies = record.get('dependencies')
        require(isinstance(dependencies, list), f'{target}.build: expected dependency identities')
        names = set()
        for dependency in dependencies:
            require(isinstance(dependency, dict), f'{target}.build: invalid dependency')
            for field in ('name', 'version'):
                require(nonempty_string(dependency.get(field)), f'{target}.build: missing dependency {field}')
            require(dependency['name'] not in names, f'{target}.build: duplicate dependency identity')
            names.add(dependency['name'])
            validate_file(dependency.get('evidence'), f'{target}.build.dependency.evidence', artifact_root)
        build = gates['build']
        if 'binary' in build:
            validate_file(build['binary'], f'{target}.build.binary', artifact_root)
        if build['status'] == 'pass':
            require(compiler is not None and {'SDL2', 'zlib'} <= names,
                    f'{target}.build: missing compiler or SDL2/zlib dependency identities')
            require(compiler['evidence']['size'] > 0 and
                    all(dependency['evidence']['size'] > 0 for dependency in dependencies),
                    f'{target}.build: empty compiler or dependency evidence')
            require('binary' in build and build['binary']['size'] > 0,
                    f'{target}.build: missing binary')
        package = gates['package']
        if 'binary' in package:
            validate_file(package['binary'], f'{target}.package.binary', artifact_root)
        if 'files' in package:
            validate_files(package['files'], f'{target}.package.files', artifact_root,
                           required=package['status'] == 'pass')
        if package['status'] == 'pass':
            require(build['status'] == 'pass', f'{target}.package: build must pass first')
            require('files' in package, f'{target}.package: missing file inventory')
            archives = [file for file in package['files'] if PurePosixPath(file['path']).name == 'game.a2r']
            require(len(archives) == 1 and archives[0]['sha256'] == ACCEPTED_ARCHIVE_SHA256 and
                    archives[0]['size'] > 0, f'{target}.package: archive identity requires exactly one accepted game.a2r')
            require('binary' in package and package['binary']['size'] > 0,
                    f'{target}.package: missing packaged binary')
            require(package['binary'] in package['files'],
                    f'{target}.package: inventory is missing the exact packaged binary record')
            provenance = package.get('provenance')
            require(isinstance(provenance, dict), f'{target}.package.provenance: missing build origin')
            require(provenance.get('build_binary_sha256') == build['binary']['sha256'],
                    f'{target}.package.provenance: build binary identity mismatch')
            operations = provenance.get('operations')
            require(isinstance(operations, list) and operations and
                    all(nonempty_string(operation) for operation in operations),
                    f'{target}.package.provenance: missing packaging operations')
        smoke = gates['target_smoke']
        if smoke['status'] == 'pass':
            require(package['status'] == 'pass', f'{target}.target_smoke: package must pass first')
            if artifact_root is not None:
                environments = set()
                for evidence in smoke['evidence']:
                    try:
                        report = load_manifest(owned_file(artifact_root, evidence['path'], f'{target}.target_smoke'))
                    except (ValueError, OSError) as error:
                        raise ValueError(f'{target}.target_smoke: invalid native report: {error}') from error
                    environments.add(validate_smoke_report(report, target, record))
                require(environments == ENVIRONMENTS[target],
                        f'{target}.target_smoke: missing native environments: {sorted(ENVIRONMENTS[target] - environments)}')
        if require_packages or require_smoke:
            require(package['status'] == 'pass', f'{target}.package: status is {package["status"]}')
        if require_smoke:
            require(smoke['status'] == 'pass', f'{target}.target_smoke: status is {smoke["status"]}')
    if require_packages or require_smoke:
        require(artifact_root is not None, 'artifact_root: required to verify passing packages')
    return manifest


def release_ready(manifest, artifact_root=None, source_root=None):
    """True only for complete passing gates with source and artifact bytes verified."""
    validate_release(manifest, artifact_root=artifact_root, source_root=source_root)
    return artifact_root is not None and source_root is not None and all(
        record[gate]['status'] == 'pass' for record in manifest['targets'].values() for gate in GATES)


def create_manifest(source_root, sources, generated_headers):
    records = sorted((file_record(source_root, path) for path in sources), key=lambda record: record['path'])
    generated = sorted((file_record(source_root, path) for path in generated_headers), key=lambda record: record['path'])
    manifest = {'schema_version': SCHEMA_VERSION, 'source_sha256': source_digest(records),
                'source_files': records, 'generated_headers': generated,
                'archive_sha256': ACCEPTED_ARCHIVE_SHA256,
                'targets': {target: {'architecture': architecture,
                                      'archive_sha256': ACCEPTED_ARCHIVE_SHA256,
                                      'compiler': None, 'dependencies': [],
                                      **{gate: {'status': 'not_run', 'evidence': []} for gate in GATES}}
                            for target, architecture in TARGET_ARCHITECTURES.items()}}
    validate_release(manifest)
    return manifest


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest='command', required=True)
    create = commands.add_parser('create', help='hash selected inputs and create an unrun four-target draft')
    create.add_argument('--source-root', type=Path, required=True)
    create.add_argument('--source', action='append', required=True)
    create.add_argument('--generated-header', action='append', required=True)
    create.add_argument('--output', type=Path, required=True)
    record = commands.add_parser('record', help='print one contained regular file identity')
    record.add_argument('--root', type=Path, required=True)
    record.add_argument('--path', required=True)
    validate = commands.add_parser('validate', help='validate records and optionally verify their actual files')
    validate.add_argument('manifest', type=Path)
    validate.add_argument('--artifact-root', type=Path)
    validate.add_argument('--source-root', type=Path)
    validate.add_argument('--require-packages', action='store_true')
    validate.add_argument('--require-smoke', action='store_true')
    args = parser.parse_args(argv)
    try:
        if args.command == 'record':
            result = file_record(args.root, args.path)
        elif args.command == 'create':
            result = create_manifest(args.source_root, args.source, args.generated_header)
            with args.output.open('x', encoding='utf-8') as output:
                json.dump(result, output, ensure_ascii=False, indent=2)
                output.write('\n')
            result = {'manifest': str(args.output), 'release_ready': False}
        else:
            manifest = load_manifest(args.manifest)
            validate_release(manifest, artifact_root=args.artifact_root, source_root=args.source_root,
                             require_packages=args.require_packages, require_smoke=args.require_smoke)
            result = {'schema_version': manifest['schema_version'],
                      'artifact_files_verified': args.artifact_root is not None,
                      'source_files_verified': args.source_root is not None,
                      'release_ready': args.artifact_root is not None and args.source_root is not None and all(
                          target[gate]['status'] == 'pass' for target in manifest['targets'].values() for gate in GATES)}
        print(json.dumps(result, ensure_ascii=False, indent=2))
        return 0
    except (ValueError, OSError) as error:
        print(f'release manifest: {error}', file=sys.stderr)
        return 1


if __name__ == '__main__':
    raise SystemExit(main())
