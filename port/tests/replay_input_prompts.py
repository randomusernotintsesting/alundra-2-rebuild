"""Bounded real tutorial/menu-only presentation capture, ordinary inputs and private settings.

Prepare only by default. Explicit --run needs the shared native runtime slot.
The fixed prefix is retained from cinema-before-caption-ru; no guest memory is
restored or patched. The dialogue move is the established +500-tick capture.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import time

from replay_native_voice import ARCHIVE, ROOT, checkpoint, tutorial_ready, write_control


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--binary',type=Path,default=ROOT/'port/build/alundra2')
    p.add_argument('--archive',type=Path,default=ARCHIVE)
    p.add_argument('--output',type=Path,required=True)
    p.add_argument('--run',action='store_true')
    args=p.parse_args();out=args.output.resolve();out.mkdir(parents=True,exist_ok=False)
    user=out/'user';user.mkdir()
    (user/'a2settings.ini').write_text('key_9=225\nkey_14=44\n')
    binary,archive=args.binary.resolve(),args.archive.resolve()
    command=[str(binary),'--boot']
    overrides=dict(SDL_VIDEODRIVER='dummy',SDL_AUDIODRIVER='dummy',A2_FAST='1',
        A2_USER_DIR=str(user),A2_RESOURCE_ARCHIVE=str(archive),A2_LAUNCHER='0',
        A2_AUTO='1',A2_TEXT_LANGUAGE='0',A2_VOICE_LANGUAGE='0',A2_IRSCALE='2',
        A2_WIDE='1',A2_HDUI='1',A2_HD_PORTRAITS='1',A2_SOUND='1',
        A2_STATELOG='1',A2_DISPLOG='1',A2_MAXFRAMES='4400',A2_TIMEOUT='120',
        A2_CONTROL_FILE=str(out/'control.txt'))
    plan=dict(command=command,environment=overrides,prepared_only=not args.run,
        binary_sha256=hashlib.sha256(binary.read_bytes()).hexdigest(),
        archive=str(archive),ordinary_taps=['1001:3:4','2201:3:4','3410:5:700'],
        checkpoints=[3400,3910],no_ram_injection=True,
        note='FAST/dummy logical display evidence; no physical controller or audible claim')
    (out/'launch.json').write_text(json.dumps(plan,indent=2)+'\n')
    write_control(out,0,3400,plan['ordinary_taps'][:2])
    if not args.run:print(out/'launch.json');return
    env={k:v for k,v in os.environ.items() if not k.startswith(('A2_','SDL_','DYLD_'))};env.update(overrides)
    process=None;states=[];started=time.monotonic();result=dict(passed=False)
    with (out/'run.log').open('w') as log:
        try:
            process=subprocess.Popen(command,cwd=out,env=env,stdout=log,stderr=subprocess.STDOUT)
            (out/'pid').write_text(str(process.pid)+'\n')
            for expected in (3400,3910):
                while True:
                    text=(out/'run.log').read_text(errors='replace');state=checkpoint(text)
                    if state and state['frame']==expected:break
                    if process.poll() is not None:raise RuntimeError(f'Process exited before {expected}')
                    if time.monotonic()-started>130:raise TimeoutError('Prompt capture exceeded130 seconds')
                    time.sleep(.1)
                states.append(state);print(state,flush=True)
                if expected==3400:
                    if not tutorial_ready(state):raise RuntimeError(f'Unexpected tutorial state {state}')
                    write_control(out,3400,3910,['3410:5:700'])
            process.terminate();process.wait(timeout=10)
            result=dict(passed=process.returncode==0,exit_code=process.returncode,states=states)
        finally:
            if process and process.poll() is None:
                process.terminate()
                try:process.wait(timeout=5)
                except subprocess.TimeoutExpired:process.kill();process.wait(timeout=10)
            result.update(wall_seconds=time.monotonic()-started,states=states)
            (out/'capture.json').write_text(json.dumps(result,indent=2)+'\n')
    from PIL import Image
    for state in states:
        source=user/f"frame_{state['frame']:05}.bmp"
        with Image.open(source) as picture:picture.save(source.with_suffix('.png'))
    print(json.dumps(result,indent=2))
    if not result['passed']:raise SystemExit(1)


if __name__=='__main__':main()
