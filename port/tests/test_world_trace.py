"""Run the real trace fixture in separate processes: env is intentionally lazy."""
import argparse
import os
from pathlib import Path
import subprocess


def run(binary, mode, window):
    env = {k: v for k, v in os.environ.items() if not k.startswith('A2_')}
    if window is not None:
        env['A2_WORLD_TRACE_FROM'], env['A2_WORLD_TRACE_TO'] = window
    return subprocess.run([str(binary), mode], env=env, capture_output=True, timeout=10)


def verify(binary, reference=None):
    for mode in ('off', 'before', 'on', 'after', 'cap'):
        window = None if mode == 'off' else ('10', '11')
        result = run(binary, mode, window)
        assert result.returncode == 0, (mode, result.returncode, result.stderr[-2000:])
        lines = result.stderr.splitlines()
        expected = 12 if mode == 'on' else 30000 if mode == 'cap' else 0
        assert len(lines) == expected, (mode, len(lines), expected)
        if mode == 'cap':
            assert b'project-native' in lines[-1]
    journal = run(binary, 'journal', ('10', '12'))
    assert journal.returncode == 0, journal.stderr[-2000:]
    lines = journal.stderr.splitlines()
    assert len(lines) == 24
    assert all(line.startswith((b'world-precision f=10 ', b'world-precision f=11 '))
               for line in lines)
    if reference:
        for mode in ('journal', 'cap'):
            window = ('10', '12') if mode == 'journal' else ('10', '11')
            before = run(reference, mode, window)
            after = run(binary, mode, window)
            assert before.returncode == 0, before.stderr[-2000:]
            assert before.stderr == after.stderr
    print('PASS: trace OFF/ON, half-open window, non-consuming predicate, 30000 cap'
          + (', exact frozen-source journals' if reference else ''))


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('binary', type=Path)
    parser.add_argument('--reference', type=Path)
    args = parser.parse_args()
    verify(args.binary.resolve(), args.reference.resolve() if args.reference else None)
