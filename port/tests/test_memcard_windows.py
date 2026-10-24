"""Disposable Windows card persistence, malformed input and link safety tests."""
import argparse
import os
from pathlib import Path
import subprocess
import tempfile

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--binary',type=Path,required=True)
    binary=parser.parse_args().binary.resolve()
    def run(command,path):
        p=subprocess.run([str(binary),command,str(path)],capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=20)
        print(p.stdout,end='');assert p.returncode==0,(command,p.returncode,p.stderr)
    with tempfile.TemporaryDirectory(prefix='a2 card ') as tmp:
        root=Path(tmp)/'Карты 日本語';root.mkdir();run('roundtrip',root)
        first=root/'memcard1.mcr';second=root/'memcard2.mcr';before=first.read_bytes()
        assert len(before)==131072 and before[:2]==b'MC'
        run('probe-env',root)
        second.write_bytes(b'truncated');run('unavailable',root)
        assert first.read_bytes()==before and second.read_bytes()==b'truncated'
        second.unlink();os.link(first,second);run('unavailable',root)
        assert first.read_bytes()==before;second.unlink()
        alias=root/'alias';alias.mkdir();(alias/'memcard1.mcr').symlink_to(first)
        run('unavailable',alias);assert first.read_bytes()==before
        assert not list(root.rglob('.a2tmp-*'))
        print('PASS native Unicode environment; truncated/hardlinked/symlink cards rejected unchanged; no orphan temps')

if __name__=='__main__':
    main()
