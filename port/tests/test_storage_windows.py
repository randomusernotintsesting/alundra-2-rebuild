"""Independent native Windows storage qualification; only disposable synthetic data."""
import argparse
import hashlib
import os
import subprocess
import tempfile
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--binary', type=Path, required=True)
    binary = parser.parse_args().binary.resolve()
    def run(command, path, marker=17, success=True):
        p = subprocess.run([str(binary), command, str(path), str(marker)], capture_output=True, text=True, encoding='utf-8', errors='replace', timeout=20)
        print(p.stdout, end='')
        if success:
            assert p.returncode == 0, (command, p.returncode, p.stderr)
        else:
            assert p.returncode != 0, command
        return p
    with tempfile.TemporaryDirectory(prefix='a2 storage ') as temp:
        root = Path(temp) / 'Проверка сохранений 日本語'
        root.mkdir()
        path = root / 'слот 1.a2save'
        run('roundtrip', path)
        run('uncertain', root / 'uncertain.a2save')
        original = path.read_bytes()
        holder = subprocess.Popen([str(binary), 'lock', str(path)], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True)
        assert holder.stdout.readline().strip() == 'READY'
        try:
            run('write', path, 31, success=False)
            assert path.read_bytes() == original
        finally:
            holder.communicate('\n', timeout=10)
            assert holder.returncode == 0
        print('PASS cross-process lock excludes writer and preserves target')
        nested = root / 'nested'; nested.mkdir(); target = nested / 'x.a2save'
        holder = subprocess.Popen([str(binary), 'pin', str(target)], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True)
        assert holder.stdout.readline().strip() == 'READY'
        try:
            try:
                root.rename(root.with_name('moved'))
                raise AssertionError('pinned ancestor renamed')
            except OSError:
                pass
        finally:
            holder.communicate('\n', timeout=10)
            assert holder.returncode == 0
        print('PASS ancestor no-delete sharing rejects directory rename')
        for command in ('new', 'raw-new'):
            racing = root / (command + '.a2save')
            processes = [subprocess.Popen([str(binary), command, str(racing), str(i)], stdout=subprocess.PIPE, stderr=subprocess.PIPE) for i in range(12)]
            results = [p.communicate(timeout=20) or None for p in processes]
            winners = [i for i,p in enumerate(processes) if p.returncode == 0]
            assert len(winners) == 1, (command, winners, results)
            before = hashlib.sha256(racing.read_bytes()).hexdigest()
            run(command, racing, 99, success=False)
            assert hashlib.sha256(racing.read_bytes()).hexdigest() == before
        print('PASS concurrent process create and lock-independent atomic no-replace: exactly one winner each')
        link = root / 'hardlink.a2save'; os.link(path, link)
        run('invalid', link); assert path.read_bytes() == original; link.unlink()
        lock_alias = root / 'slotted.a2save.lock'; os.link(path, lock_alias)
        run('write', root / 'slotted.a2save', success=False); assert path.read_bytes() == original; lock_alias.unlink()
        symlink = root / 'redirect.a2save'; symlink.symlink_to(path)
        run('invalid', symlink); assert path.read_bytes() == original; symlink.unlink()
        junction = root / 'junction'
        subprocess.run(['cmd', '/c', 'mklink', '/J', str(junction), str(nested)], check=True, capture_output=True)
        run('write', junction / 'escape.a2save', success=False); assert not (nested/'escape.a2save').exists(); junction.rmdir()
        print('PASS hardlinked targets/locks, file symlink and ancestor junction rejected without outside mutation')
        for name in ('CON.a2save', 'trailing.a2save.', 'stream.a2save:alternate'):
            run('write', root / name, success=False)
        run('browser', root)
        saves = root / 'Saves'; assert len(list(saves.glob('*.a2save'))) == 1
        p = bytearray(8192); p[:4] = b'SC\x11\x01'; p[4] = 17; p[0xc14] = 14; p[0xd8c:0xd8e] = (0x4483).to_bytes(2,'little'); p[-1] = 17 ^ 0x5a
        card = bytearray(131072); card[:2] = b'MC'; card[127] = ord('M') ^ ord('C')
        entry = bytearray(128); entry[0] = 0x51; entry[4:8] = (8192).to_bytes(4,'little'); entry[8:10] = b'\xff\xff'; entry[10:24] = b'BISCPS-1011500'; entry[127] = 0
        for b in entry[:127]: entry[127] ^= b
        card[128:256] = entry; card[8192:16384] = p; (root/'memcard1.mcr').write_bytes(card)
        run('import', root); imported = list(saves.glob('card*.a2save')); assert len(imported)==1
        snap = imported[0].read_bytes(); run('import', root); assert imported[0].read_bytes()==snap
        run('immutable', imported[0]); run('immutable', imported[0].with_name(imported[0].name.upper())); assert imported[0].read_bytes()==snap
        (root/'memcard1.mcr').write_bytes(card[:500]); run('import', root, success=False); assert imported[0].read_bytes()==snap
        assert not list(root.rglob('.a2tmp-*'))
        print('PASS Unicode/spaces browser+BCrypt filename; strict imports, idempotent snapshot, case aliases immutable, truncated card rejected; no orphan temps')
    return 0

if __name__ == '__main__':
    raise SystemExit(main())
