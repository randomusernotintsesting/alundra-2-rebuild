#!/usr/bin/env python3
"""Paced isolated native storm profile from an existing copied cabin save.

Uses ordinary controller input and checks the actual scene before each phase.
No disc paths, user settings, delivered applications or original saves are written.
--idle-frames adds a no-input cabin interval, then shifts the entire initial
route. The default 0 keeps the accepted route unchanged. phase.txt is an atomic
single-word marker for the 1 Hz resource sampler; phase-events.json and result.json
retain timestamps and native frame boundaries, including failed completion.
"""
import argparse
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess
import time

TAPS = ['3001:6:160', '3401:7:20', '3441:6:90', '3490:13', '3530:13',
        '3570:13', '3901:13']

def initial_schedule(idle_frames):
    """Keep the accepted route relative to its first movement, after no-input idle."""
    if not isinstance(idle_frames,int) or not 0 <= idle_frames <= 1800 or idle_frames % 60:
        raise ValueError('Indoor idle must be 0..1800 frames in multiples of 60')
    taps=[]
    for tap in TAPS:
        start,rest=tap.split(':',1)
        taps.append(f'{int(start)+idle_frames}:{rest}')
    return dict(ready=3000,idle_until=3000+idle_frames if idle_frames else None,
                traversal_until=4200+idle_frames,taps=taps)

def idle_frame_argument(value):
    try:
        frames=int(value);initial_schedule(frames);return frames
    except (TypeError,ValueError) as error:
        raise argparse.ArgumentTypeError(str(error)) from error

def atomic_text(path,value):
    temporary=path.with_name(path.name+'.next')
    temporary.write_text(value);temporary.replace(path)

def publish_phase(output,events,phase,frame,**details):
    if phase not in ('boot','indoor','traversal','storm','complete'):
        raise ValueError('Unknown measurement phase')
    stamp=time.time()
    event=dict(phase=phase,native_frame=frame,unix_seconds=stamp,
        timestamp_utc=datetime.fromtimestamp(stamp,timezone.utc).isoformat(),
        monotonic_seconds=time.monotonic(),**details)
    events.append(event)
    atomic_text(output/'phase-events.json',json.dumps(events,indent=2)+'\n')
    atomic_text(output/'phase.txt',phase+'\n')

def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--binary', type=Path, required=True)
    parser.add_argument('--archive', type=Path, required=True)
    parser.add_argument('--seed', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--changed-outdoor-view', action='store_true',
                        help='Turn the camera and walk before the bounded outdoor measurement')
    parser.add_argument('--isolate-input', action='store_true',
                        help='Unbind physical gameplay inputs in the new private profile; keep ordinary replay taps')
    parser.add_argument('--ir-scale',type=int,choices=(1,2,3,4),default=4)
    parser.add_argument('--idle-frames',type=idle_frame_argument,default=0,
                        help='Paced indoor frames before traversal, 0..1800 in multiples of 60')
    args = parser.parse_args()
    schedule=initial_schedule(args.idle_frames)
    binary, archive, seed, out = [p.resolve() for p in
                                 (args.binary, args.archive, args.seed, args.output)]
    out.mkdir(parents=True, exist_ok=False)
    phase_events=[];publish_phase(out,phase_events,'boot',0)
    user = out / 'user'; (user / 'Saves').mkdir(parents=True)
    shutil.copy2(seed, user / 'Saves/seed.a2save')
    if args.isolate_input:
        rows=[f'key_{bit}=0' for bit in range(16)]
        rows += [f'pad_{bit}_{slot}_{field}=0' for bit in range(16)
                 for slot in range(2) for field in ('kind','code')]
        (user/'a2settings.ini').write_text('\n'.join(rows)+'\n')
    control = out / 'control.txt'; control.write_text('3000\n')
    env = {k: v for k, v in os.environ.items() if not k.startswith(('A2_', 'SDL_'))}
    env.update(SDL_VIDEODRIVER='cocoa', SDL_AUDIODRIVER='coreaudio',
               A2_USER_DIR=str(user), A2_RESOURCE_ARCHIVE=str(archive),
               A2_NATIVE_SAVES='1', A2_TEST_NATIVE_LOAD='seed.a2save',
               A2_IRSCALE=str(args.ir_scale), A2_WIDE='1', A2_FILTER='1', A2_HDUI='1',
               A2_HD_PORTRAITS='1', A2_SOUND='1', A2_VOLUME='100',
               A2_TEXT_LANGUAGE='0', A2_VOICE_LANGUAGE='0', A2_LAUNCHER='0',
               A2_AUTO='2', A2_SKIP='1', A2_MAXFRAMES=str(10001+args.idle_frames), A2_TIMEOUT='900',
               A2_TIMING='1', A2_TICKSTAT='1', A2_AUDIOSTAT='1', A2_MIXSTAT='1',
               A2_PROFILE_PRESENT='1', A2_HUD_LOG='1', A2_STATELOG='1', A2_SHOTS='1',
               A2_SHOTEVERY='500', A2_SHOTDIR=str(out),
               A2_CONTROL_FILE=str(control), A2_TAP=','.join(schedule['taps']))
    command = [str(binary), '--boot']
    (out / 'environment.json').write_text(json.dumps(dict(
        command=command, env={k: v for k, v in env.items() if k.startswith(('A2_', 'SDL_'))},
        binary_sha256=sha(binary), archive_sha256=sha(archive), seed_sha256=sha(seed),
        isolate_physical_gameplay_input=bool(args.isolate_input),ir_scale=args.ir_scale,
        idle_frames=args.idle_frames,initial_schedule=schedule,
        phase_events_file=str(out/'phase-events.json')), indent=2))
    started = time.monotonic(); last_status = ''; checkpoints = []
    process=None;result={};scheduled=list(schedule['taps'])
    (out/'complete-route.json').write_text(json.dumps(scheduled,indent=2)+'\n')
    with (out / 'run.log').open('w') as log:
        try:
            process = subprocess.Popen(command, cwd=out, env=env, stdout=log, stderr=subprocess.STDOUT)
            (out / 'pid').write_text(str(process.pid))
            def checkpoint(frame):
                nonlocal last_status
                while True:
                    content = (out / 'run.log').read_text(errors='replace')
                    states = re.findall(r'state: frame=[^\n]+', content)
                    if states and states[-1] != last_status:
                        last_status = states[-1]; print(last_status, flush=True)
                    if f'control: paused frame={frame} ' in content:
                        break
                    if process.poll() is not None:
                        raise RuntimeError(f'Exited {process.returncode} before checkpoint {frame}')
                    if time.monotonic() - started > 910:
                        raise TimeoutError('Bounded native profile exceeded 910 seconds')
                    time.sleep(1)
                ram = (user / f'ram_{frame:05}.bin').read_bytes()
                state = dict(frame=frame, map_id=struct.unpack_from('<H', ram, 0x12789c)[0],
                    map=ram[0x1310a0:0x1310a4].decode('ascii', errors='replace').replace('\x00', '_'),
                    pos=tuple(v >> 12 for v in struct.unpack_from('<iii', ram, 0x119728)),
                    flags=struct.unpack_from('<I', ram, 0xf6220)[0],
                    action=struct.unpack_from('<H', ram, 0x119724)[0],
                    ladder=struct.unpack_from('<I', ram, 0x128c8c)[0])
                checkpoints.append(state)
                (out / 'checkpoints.json').write_text(json.dumps(checkpoints, indent=2))
                print('checkpoint', state, flush=True)
                return state
            state = checkpoint(3000)
            if state['map_id'] != 14 or state['flags'] or state['pos'] != (-175, 0, 24):
                raise RuntimeError(f'Unexpected cabin seed {state}')
            if schedule['idle_until'] is not None:
                publish_phase(out,phase_events,'indoor',state['frame'])
                payload=f"{schedule['idle_until']}\n"
                (out/f"control-3000-to-{schedule['idle_until']}.txt").write_text(payload)
                atomic_text(control,payload);state=checkpoint(schedule['idle_until'])
                if state['map_id'] != 14 or state['flags'] or state['pos'] != (-175,0,24):
                    raise RuntimeError(f'Indoor interval did not remain at the cabin seed: {state}')
            publish_phase(out,phase_events,'traversal',state['frame'])
            payload=f"{schedule['traversal_until']}\n"
            (out/f"control-{state['frame']}-to-{schedule['traversal_until']}.txt").write_text(payload)
            atomic_text(control,payload);state=checkpoint(schedule['traversal_until'])
            if state['map_id'] != 5 or state['flags']:
                raise RuntimeError(f'Expected lower ladder room {state}')
            def advance(duration, inputs=()):
                nonlocal state
                taps = [f"{state['frame']+offset}:{bit}:{hold}" for offset, bit, hold in inputs]
                until = state['frame'] + duration
                payload = str(until) + '\n' + ''.join(tap + '\n' for tap in taps)
                (out / f"control-{state['frame']}-to-{until}.txt").write_text(payload)
                scheduled.extend(taps)
                (out / 'complete-route.json').write_text(json.dumps(scheduled, indent=2))
                atomic_text(control,payload); state = checkpoint(until)
            def align_x(target):
                for _ in range(16):
                    delta = target - state['pos'][0]
                    if abs(delta) <= 5:
                        return
                    hold = min(25, max(2, abs(delta)//4))
                    advance(hold+8, [(1, 6 if delta > 0 else 4, hold)])
                raise RuntimeError(f'Cannot align to ladder/door X={target}: {state}')
            align_x(-138)
            advance(16, [(1, 13, 4)])
            for _ in range(24):
                if state['action'] == 126 and state['ladder'] == 0x801c31e8:
                    break
                advance(24, [(1, 7, 20)])
            else:
                raise RuntimeError(f'Failed ordinary ladder grab: {state}')
            for _ in range(24):
                if state['pos'][1] == 300 and state['action'] != 126:
                    break
                advance(24, [(1, 4, 20)])
            else:
                raise RuntimeError(f'Failed ordinary ladder climb: {state}')
            align_x(-61)
            for _ in range(10):
                if state['map_id'] == 11:
                    break
                advance(90, [(1, 7, 80), (12, 13, 4), (52, 13, 4)])
            for _ in range(12):
                if state['map_id'] == 11 and state['map'] == 'd80_' and state['pos'][0] > 500:
                    break
                advance(60)
            else:
                raise RuntimeError(f'Outdoor transition did not finish: {state}')
            for _ in range(5):
                if not state['flags']:
                    break
                advance(120, [(1, 13, 4)])
            if state['map_id'] != 11 or state['flags']:
                raise RuntimeError(f'Outdoor banner did not dismiss: {state}')
            if args.changed_outdoor_view:
                advance(90, [(1, 10, 30), (41, 4, 30)])
                if state['map_id'] != 11 or state['flags']:
                    raise RuntimeError(f'Changed view left outdoor play: {state}')
            # Whole windows after a fixed warm-up; movement stops for the profile.
            first_window = ((state['frame'] + 180 + 59)//60)*60 + 1
            end_frame = first_window - 1 + 1200
            publish_phase(out,phase_events,'storm',state['frame'],
                          profile_first_frame=first_window,profile_last_frame=end_frame)
            advance(end_frame-state['frame'])
            if state['map_id'] != 11 or state['flags']:
                raise RuntimeError(f'Left ordinary outdoor play during profile: {state}')
            process.terminate(); process.wait(timeout=10)
            if process.returncode:
                raise RuntimeError(f'Unexpected controlled exit {process.returncode}')
            result = dict(exit_code=process.returncode, elapsed_seconds=time.monotonic()-started,
                          checkpoints=checkpoints, completed=True,
                          profile_first_frame=first_window, profile_last_frame=end_frame,
                          changed_outdoor_view=args.changed_outdoor_view,
                          stop_reason='Explicit completion at the verified outdoor profile checkpoint')
        except BaseException as error:
            result = dict(exit_code=process.poll() if process else None, elapsed_seconds=time.monotonic()-started,
                          checkpoints=checkpoints, completed=False, error=repr(error))
            raise
        finally:
            if process and process.poll() is None:
                process.terminate()
                try: process.wait(timeout=5)
                except subprocess.TimeoutExpired: process.kill(); process.wait(timeout=10)
            if process:result['exit_code']=process.returncode
            publish_phase(out,phase_events,'complete',checkpoints[-1]['frame'] if checkpoints else 0,
                          completed=bool(result.get('completed')))
            result.update(ir_scale=args.ir_scale,idle_frames=args.idle_frames,
                          isolate_physical_gameplay_input=bool(args.isolate_input),
                          phase_events=phase_events,pid=process.pid if process else None)
            atomic_text(out/'result.json',json.dumps(result,indent=2)+'\n')
    print(json.dumps({k: v for k, v in result.items() if k != "checkpoints"}, indent=2), flush=True)

if __name__ == '__main__':
    main()
