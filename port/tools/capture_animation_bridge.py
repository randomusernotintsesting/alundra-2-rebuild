#!/usr/bin/env python3
"""Bounded, isolated, paced original-pose capture for the Blender bridge."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import time


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--binary', type=Path, required=True)
    parser.add_argument('--archive', type=Path, required=True)
    parser.add_argument('--seed', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--capture-start', type=int, default=2990)
    parser.add_argument('--end-frame', type=int, default=4000)
    parser.add_argument('--dump-frame', type=int, default=3000)
    parser.add_argument('--taps', default='3301:6:90,3601:15:4')
    parser.add_argument('--without-snapshot', action='store_true')
    args = parser.parse_args()
    if not 0 < args.capture_start < args.end_frame <= 12000:
        parser.error('capture range must be positive, increasing and <=12000')
    binary, archive, seed, out = [p.resolve() for p in
                                (args.binary,args.archive,args.seed,args.output)]
    out.mkdir(parents=True, exist_ok=False)
    user = out/'user'; (user/'Saves').mkdir(parents=True)
    shutil.copy2(seed, user/'Saves/seed.a2save')
    rows=[f'key_{bit}=0' for bit in range(16)]
    rows += [f'pad_{bit}_{slot}_{field}=0' for bit in range(16)
             for slot in range(2) for field in ('kind','code')]
    (user/'a2settings.ini').write_text('\n'.join(rows)+'\n')
    control=out/'control.txt'; control.write_text(f'{args.end_frame}\n')
    env={k:v for k,v in os.environ.items() if not k.startswith(('A2_','SDL_'))}
    env.update(SDL_VIDEODRIVER='dummy', SDL_AUDIODRIVER='dummy',
        A2_USER_DIR=str(user), A2_RESOURCE_ARCHIVE=str(archive),
        A2_NATIVE_SAVES='1', A2_TEST_NATIVE_LOAD='seed.a2save',
        A2_LAUNCHER='0', A2_AUTO='2', A2_SKIP='1', A2_IRSCALE='1',
        A2_WIDE='1', A2_FILTER='1', A2_HDUI='1', A2_SOUND='1',
        A2_TEXT_LANGUAGE='0', A2_VOICE_LANGUAGE='0', A2_TIMEOUT='180',
        A2_STATELOG='1', A2_MAXFRAMES=str(args.end_frame+2),
        A2_CONTROL_FILE=str(control), A2_TAP=args.taps,
        A2_DUMPMEM=f'{args.dump_frame}:80000000:200000',
        A2_DUMPOUT=str(out/f'ram_{args.dump_frame:05d}.bin'),
        A2_MODELCAP=str(args.capture_start),
        A2_MODELCAP_N=str(args.end_frame-args.capture_start+1),
        A2_MODELCAP_OUT=str(out/'modelcap.txt'))
    if not args.without_snapshot:
        env['A2_ACTOR_CAPTURE']=str(out/'actor-snapshots.jsonl')
    command=[str(binary),'--boot']
    (out/'launch.json').write_text(json.dumps(dict(command=command,
        env={k:v for k,v in env.items() if k.startswith(('A2_','SDL_'))},
        binary_sha256=sha(binary),archive_sha256=sha(archive),seed_sha256=sha(seed),
        timing='paced host run, monotonic capture timestamps; animation FPS is not assumed',
        display='dummy; this capture is not a visual/performance qualification'),indent=2)+'\n')
    start=time.monotonic(); resumed=False
    with (out/'run.log').open('w') as log:
        proc=subprocess.Popen(command,cwd=out,env=env,stdout=log,stderr=subprocess.STDOUT)
        (out/'pid').write_text(str(proc.pid)+'\n')
        try:
            while proc.poll() is None:
                if time.monotonic()-start>190:
                    raise TimeoutError('animation capture exceeded bounded timeout')
                if not resumed and (user/f'ram_{args.end_frame:05d}.bin').exists():
                    # Wait for the complete pause marker; a file alone can be
                    # observed before its writer has finished.
                    if f'control: paused frame={args.end_frame} ' in (out/'run.log').read_text(errors='replace'):
                        temp=out/'control.next'; temp.write_text(f'{args.end_frame+10}\n')
                        temp.replace(control); resumed=True
                time.sleep(.1)
            code=proc.wait()
        finally:
            if proc.poll() is None:
                proc.terminate()
                try: proc.wait(timeout=5)
                except subprocess.TimeoutExpired: proc.kill();proc.wait()
    snapshot_valid=None; records=valid_records=0
    if not args.without_snapshot:
        markers=re.findall(r'actorcapture: published=(\d+) rejected=(\d+) output_error=(\d+)',
                           (out/'run.log').read_text(errors='replace'))
        snapshot_valid=bool(markers and markers[-1][2]=='0')
        try:
            with (out/'actor-snapshots.jsonl').open() as stream:
                for line in stream:
                    record=json.loads(line)
                    if not line.endswith('\n') or record.get('schema')!='a2.animation_bridge.v1':
                        raise ValueError('incomplete or unknown snapshot record')
                    records+=1;valid_records+=bool(record['valid'])
            snapshot_valid=bool(snapshot_valid and valid_records and markers and
                                records==int(markers[-1][0])+int(markers[-1][1]))
        except (OSError,ValueError,KeyError):
            snapshot_valid=False
    result=dict(exit_code=code,elapsed_seconds=time.monotonic()-start,checkpoint_reached=resumed,
                snapshot_valid=snapshot_valid,snapshot_records=records,valid_snapshot_records=valid_records)
    (out/'result.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(result))
    if code or not resumed or snapshot_valid is False: raise SystemExit(1)


if __name__ == '__main__':
    main()
