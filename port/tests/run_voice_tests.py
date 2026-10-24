"""Focused voice and user-volume checks; all outputs stay in a staging folder."""
import argparse
import shlex
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

def run(command, log):
    result = subprocess.run(command, cwd=ROOT, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    log.write_text('$ ' + shlex.join(map(str, command)) + '\n' + result.stdout)
    print(log.name + ': ' + ('PASS' if result.returncode == 0 else 'FAIL'))
    if result.returncode:
        print(result.stdout)
        raise SystemExit(result.returncode)

def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--output', type=Path, default=ROOT / 'port/build/verification/september-polish/voices/tests')
    args = p.parse_args();out = args.output.resolve();out.mkdir(parents=True, exist_ok=True)
    run([sys.executable,'-m','unittest','discover','-s','port/tests','-p','test_voice_pack.py','-v'],out/'pack-tests.log')
    flags = shlex.split(subprocess.check_output(['sdl2-config','--cflags','--libs'],text=True))
    cases = {
        'voice_assets':['port/src/voice_assets.c','port/src/xa_audio.c'],
        'voice_cd':['port/src/voice_assets.c','port/src/xa_audio.c'],
        'audio_user_volume':[],
        'audio_cd':['port/src/xa_audio.c'],
        'audio_cd_pacing':['port/src/xa_audio.c'],
        'audio_output':[],
    }
    for name, sources in cases.items():
        exe=out/name
        command=['cc','-std=c11','-Wall','-Wextra','-Werror','-fsanitize=undefined',
                 f'port/tests/test_{name}.c',*sources,*flags,'-o',str(exe)]
        run(command,out/f'{name}-build.log')
        run([str(exe)],out/f'{name}.log')

if __name__ == '__main__': main()
