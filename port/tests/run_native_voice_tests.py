"""Focused native voice fixtures; no original media or native gameplay runs."""
import argparse
import shlex
import subprocess
import sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]


def run(command,path):
    result=subprocess.run(command,cwd=ROOT,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    path.write_text('$ '+shlex.join(map(str,command))+'\n'+result.stdout)
    print(path.name+(': PASS' if result.returncode==0 else ': FAIL'))
    if result.returncode:print(result.stdout);raise SystemExit(result.returncode)


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    out=args.output.resolve();out.mkdir(parents=True,exist_ok=True)
    run([sys.executable,'-m','unittest','discover','-s','port/tests','-p','test_native_voice.py','-v'],out/'export.log')
    for name in ['native_voice','native_voice_guest','xa_groups','audio_xa']:
        binary=out/name
        command=['cc','-std=c11','-Wall','-Wextra','-Werror','-Wno-unused-label','-fsanitize=undefined','-Iport/src',
                 f'port/tests/test_{name}.c','port/src/xa_audio.c']
        if name.startswith('native_voice'):command.append('port/src/native_voice.c')
        run(command+['-o',str(binary)],out/f'{name}-build.log')
        run([str(binary)],out/f'{name}.log')


if __name__=='__main__':main()
