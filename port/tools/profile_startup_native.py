#!/usr/bin/env python3
"""Clone the accepted uninterrupted startup manifest into a fresh private run.

Preparation is the default. --run requires the shared heavy runtime slot.
No original application, source manifest or user profile is changed.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import time


def sha(path):
    with Path(path).open('rb') as source:return hashlib.file_digest(source,'sha256').hexdigest()


def prepare(reference,binary,archive,output):
    reference,binary,output=reference.resolve(),binary.resolve(),output.resolve()
    if output.exists():raise FileExistsError('Output directory already exists')
    before=json.loads((reference/'launch.json').read_text())
    result=json.loads((reference/'result.json').read_text())
    if not result.get('completed') or result.get('exit_code')!=0 or result.get('frames')!=3600:
        raise ValueError('Reference startup did not complete3600ticks')
    env=dict(before['env'])
    forbidden=('A2_CONTROL_FILE','A2_SHOTS','A2_SHOT','A2_SHOTEVERY','A2_SHOTDIR','A2_STATELOG',
               'A2_TAP','A2_FAST','A2_PLAY','A2_MASH','A2_MIXSTAT','A2_AUDIOSTAT')
    if any(key in env for key in forbidden):raise ValueError('Reference includes diagnostic pauses/input or unpaced timing')
    if env.get('A2_MAXFRAMES')!='3600' or env.get('A2_TIMEOUT')!='145':
        raise ValueError('Reference lacks the agreed startup bound')
    archive=archive.resolve() if archive else Path(env['A2_RESOURCE_ARCHIVE'])
    seed=reference/'user/Saves/seed.a2save'
    if sha(archive)!=before['archive_sha256'] or sha(seed)!=before['seed_sha256']:
        raise ValueError('Archive or seed differs from accepted reference')
    binary_hash=sha(binary)
    user=output/'user';(user/'Saves').mkdir(parents=True)
    shutil.copy2(seed,user/'Saves/seed.a2save')
    shutil.copy2(reference/'user/a2settings.ini',user/'a2settings.ini')
    env.update(A2_USER_DIR=str(user),A2_RESOURCE_ARCHIVE=str(archive))
    plan=dict(command=[str(binary),'--boot'],env=env,binary_sha256=binary_hash,
              archive_sha256=before['archive_sha256'],seed_sha256=before['seed_sha256'],
              settings_sha256=sha(user/'a2settings.ini'),reference=str(reference),
              reference_manifest_sha256=sha(reference/'launch.json'),
              maximum_wall_seconds=150,no_control_checkpoints=True,no_screenshots=True)
    (output/'launch.json').write_text(json.dumps(plan,indent=2)+'\n')
    return plan


def run(plan,output):
    env={k:v for k,v in os.environ.items() if not k.startswith(('A2_','SDL_','DYLD_'))}
    env.update(plan['env'])
    process=sampler=None;result={};started=time.monotonic()
    try:
        with (output/'run.log').open('w') as log,(output/'sampler.log').open('w') as slog:
            process=subprocess.Popen(plan['command'],env=env,cwd=output,stdout=log,stderr=subprocess.STDOUT)
            (output/'pid').write_text(str(process.pid));print('started PID',process.pid,flush=True)
            sampler=subprocess.Popen([sys.executable,str(Path(__file__).with_name('profile_process_macos.py')),
                '--pid',str(process.pid),'--expected-path',plan['command'][0],'--output',str(output/'resources'),
                '--phase','startup','--interval','1','--duration','150'],stdout=slog,stderr=subprocess.STDOUT)
            previous=0
            while process.poll() is None:
                if time.monotonic()-started>150:raise TimeoutError('Owned startup exceeded150seconds')
                text=(output/'run.log').read_text(errors='replace')
                frames=re.findall(r'phasestat: first_frame=\d+ frame=(\d+)',text)
                if frames and int(frames[-1])>=previous+600:
                    previous=int(frames[-1]);print('frame',previous,'elapsed',round(time.monotonic()-started,2),flush=True)
                time.sleep(1)
            sampler.wait(timeout=5)
            text=(output/'run.log').read_text(errors='replace')
            result=dict(completed=process.returncode==0 and sampler.returncode==0 and
                        'frame limit reached (3600 frames)' in text and 'native-save: load result=1 scene=14' in text,
                        exit_code=process.returncode,sampler_exit_code=sampler.returncode,pid=process.pid,
                        elapsed_seconds=time.monotonic()-started,frames=3600,interrupted=False)
    except BaseException as error:
        result=dict(completed=False,error=repr(error),elapsed_seconds=time.monotonic()-started)
        raise
    finally:
        for child in (process,sampler):
            if child and child.poll() is None:
                child.terminate()
                try:child.wait(timeout=3)
                except subprocess.TimeoutExpired:child.kill();child.wait(timeout=3)
        (output/'result.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(result),flush=True)
    return 0 if result['completed'] else 1


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--reference',required=True,type=Path)
    parser.add_argument('--binary',required=True,type=Path)
    parser.add_argument('--archive',type=Path)
    parser.add_argument('--output',required=True,type=Path)
    parser.add_argument('--run',action='store_true')
    args=parser.parse_args();plan=prepare(args.reference,args.binary,args.archive,args.output)
    if args.run:return run(plan,args.output.resolve())
    print('Prepared only:',args.output/'launch.json');return 0


if __name__=='__main__':raise SystemExit(main())
