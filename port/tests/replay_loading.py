"""Bounded ordinary boot loading capture; prepare only unless --run is supplied.

Uses the existing live control checkpoints. It never writes guest RAM, invokes
guest functions, supplies game inputs, or changes the original loading timer.
Images are crops of saved engine BMP renders, not desktop screenshots.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import time

FIRST,LAST=480,560
PAUSE=re.compile(r'control: paused frame=(\d+)\b')
DISPLAY=re.compile(r'disp: x=(\d+) y=(\d+) w=(\d+) h=(\d+) vlines=(\d+) y1=(\d+) '
                   r'hrange=(\d+)\.\.(\d+) \(hspan=(\d+)\) on=(\d+)')


def loading_state(ram,frame):
    if len(ram)!=0x200000:raise ValueError('Incomplete checkpoint RAM')
    read=lambda offset:struct.unpack_from('<I',ram,offset)[0]
    table=[list(struct.unpack_from('<2h',ram,0x4f9e8+i*4)) for i in range(10)]
    env=list(struct.unpack_from('<8h',ram,0x5d010))
    enabled,tick,index=read(0x5d0b8),read(0x5d0b0),read(0x5d0bc)
    source=env[:2]
    active=bool(enabled and tick and env[2:4]==[128,32] and source in table)
    tile=(source[1]//32)*2+source[0]//128 if source in table and env[2:4]==[128,32] else None
    return dict(frame=frame,active=False,ram_loading_active=active,enabled=enabled,advance_tick=tick,
                next_table_index=index,delay=read(0x5d004),table=table,
                ram_source_rectangle=env[:4],ram_screen_rectangle=env[4:],ram_environment_tile=tile,
                displayed_tile=None,ram_capture_phase='after guest VBlank IRQ')


def classify_display(state,log):
    """Classify the BMP's display, independently of the later RAM checkpoint.

    main.c presents first, then dispatches the original VBlank IRQ, then dumps
    RAM. That handler may have advanced its display environment by the time
    RAM is captured. The disp line records the source used by present().
    Scope it to this checkpoint so replaying a retained full log is also safe.
    """
    state=dict(state)
    state.update(active=False,displayed_tile=None,display_capture_phase='before guest VBlank IRQ')
    state.pop('display',None)
    markers=[m for m in PAUSE.finditer(log) if int(m.group(1))==state['frame']]
    displays=list(DISPLAY.finditer(log[:markers[-1].start()])) if markers else []
    if not displays:return state
    keys=('x','y','width','height','vlines','y1','hrange_start','hrange_end','hspan','on')
    d=dict(zip(keys,map(int,displays[-1].groups())))
    source=[d['x'],d['y']]
    state.update(display=d,display_source_rectangle=source+[d['width'],d['height']],
                 ram_source_differs_from_display=source!=state['ram_source_rectangle'][:2])
    if d['on'] and d['width']==128 and d['height']==32:
        if source not in state['table']:raise ValueError('Unknown displayed loading source')
        state.update(active=True,displayed_tile=(d['y']//32)*2+d['x']//128)
    return state


def sequence_runs(states):
    runs=[]
    for state in states:
        if not state['active']:continue
        frame,tile=state['frame'],state['displayed_tile']
        if runs and runs[-1]['tile']==tile and runs[-1]['last_frame']+1==frame:
            runs[-1]['last_frame']=frame;runs[-1]['guest_frames']+=1
        else:
            runs.append(dict(tile=tile,first_frame=frame,last_frame=frame,guest_frames=1,
                             duration_basis='captured guest frames'))
    return runs


def acceptance(states,log,exit_code):
    active=[s for s in states if s['active']]
    errors=[]
    if exit_code!=0:errors.append(f'Native exit code {exit_code}')
    if not active:errors.append('No active loading frames observed')
    if any(not s.get('crop') or not s.get('crop_nonblack') for s in active):
        errors.append('Active loading frame lacks a visible recorded engine crop')
    transport=[tuple(map(int,row)) for row in re.findall(
        r'nativecd: raw_read_attempts=(\d+) data_dma_attempts=(\d+) fifo_attempts=(\d+)',log)]
    if transport!=[(0,0,0)]:errors.append('Missing or nonzero native CD transport diagnostics')
    if re.search(r'Native playback failed:|nativefatal|\bFATAL\b|AddressSanitizer|runtime error:|'
                 r'native-resource: (?:busy|read|queue|enqueue) [^\n]*: ',log):
        errors.append('Native fatal/resource failure in log')
    tiles=sorted({s['displayed_tile'] for s in active})
    return dict(passed=not errors,errors=errors,exit_code=exit_code,active_frames=len(active),
                observed_tiles=tiles,all_eight_tiles_observed=tiles==list(range(8)),
                sequence=sequence_runs(states),transport=transport,
                duration_note='Pauses add host wall time; durations count captured guest frames only. '
                'Boundary segments may be truncated. A complete turn is not required for a short native load.')


def write_control(out,until):
    temporary=out/'control.next'
    temporary.write_text(str(until)+'\n')
    temporary.replace(out/'control.txt')


def record_checkpoint(out,frame,log):
    from PIL import Image
    user=out/'user'
    ram=user/f'ram_{frame:05}.bin'
    vram=user/f'vram_{frame:05}.bin'
    bmp=user/f'frame_{frame:05}.bmp'
    state=classify_display(loading_state(ram.read_bytes(),frame),log)
    d=state.get('display',{})
    if state['active']:
        with Image.open(bmp) as im:
            width,height=im.size
            if width%4 or height!=960:raise ValueError('Unexpected native IR4 capture extent')
            canvas=width//4
            cycles=2560//canvas
            x=max(0,(d['hrange_start']-608)//cycles)
            y=max(0,d['y1']-16)
            x=min(x,max(0,canvas-128));y=min(y,240-32)
            crop=im.crop((x*4,y*4,(x+128)*4,(y+32)*4)).convert('RGB')
            target=out/'display'/f'loading_{frame:05}.png'
            target.parent.mkdir(exist_ok=True)
            crop.save(target)
            state.update(crop=str(target),crop_nonblack=crop.getbbox() is not None,
                         crop_rectangle=[x*4,y*4,128*4,32*4],engine_bmp=str(bmp),
                         ram=str(ram),vram=str(vram),engine_bmp_sha256=hashlib.sha256(bmp.read_bytes()).hexdigest())
    elif frame!=FIRST:
        # Remove only this runner's unneeded output; retain all parsed counters.
        for path in (ram,vram,bmp):path.unlink()
    return state


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--binary',type=Path,required=True)
    parser.add_argument('--archive',type=Path,help='Defaults to game.a2r inside the binary\'s app bundle')
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--language',choices=('ru','ja','en'),default='ru')
    parser.add_argument('--timeout',type=int,default=120)
    parser.add_argument('--run',action='store_true',help='Requires the root agent\'s runtime slot')
    args=parser.parse_args()
    out=args.output.resolve();out.mkdir(parents=True,exist_ok=False)
    binary=args.binary.resolve()
    archive=(args.archive or binary.parent.parent/'Resources/game-data/game.a2r').resolve()
    env=dict(SDL_VIDEODRIVER='cocoa',SDL_AUDIODRIVER='coreaudio',
             A2_RESOURCE_ARCHIVE=str(archive),A2_USER_DIR=str(out/'user'),
             A2_LAUNCHER='0',A2_TEXT_LANGUAGE=str(('ru','ja','en').index(args.language)),
             A2_VOICE_LANGUAGE='0' if args.language=='ja' else '1',
             A2_IRSCALE='4',A2_WIDE='1',A2_HDUI='1',A2_FILTER='1',A2_SOUND='1',
             A2_DISPLOG='1',A2_MAXFRAMES=str(LAST+1),A2_TIMEOUT=str(args.timeout),
             A2_CONTROL_FILE=str(out/'control.txt'))
    plan=dict(command=[str(binary),'--boot'],environment=env,prepared_only=not args.run,
              checkpoints=list(range(FIRST,LAST+1)),normal_exit_frame=LAST+1,
              no_guest_writes=True,no_game_inputs=True,
              crop_source='Existing engine BMP checkpoint output only',
              hd_vram_note='Checkpoint VRAM is native 16-bit data. It cannot prove HD subpixels '
              'in undisplayed tiles; the separate actual-GT4 fixture covers all eight tiles.')
    (out/'launch.json').write_text(json.dumps(plan,indent=2)+'\n')
    write_control(out,FIRST)
    if not args.run:
        print(f'Prepared only: {out / "launch.json"}');return
    if not binary.is_file() or not archive.is_file():raise ValueError('Missing native binary/archive')
    runtime_env={k:v for k,v in os.environ.items() if not k.startswith('A2_')}
    runtime_env.update(env)
    states=[];failure=None;process=None;started=time.monotonic();last=FIRST-1
    plan['binary_sha256']=hashlib.sha256(binary.read_bytes()).hexdigest()
    plan['archive_bytes']=archive.stat().st_size
    (out/'launch.json').write_text(json.dumps(plan,indent=2)+'\n')
    with (out/'run.log').open('w') as output:
        try:
            process=subprocess.Popen(plan['command'],cwd=out,env=runtime_env,stdout=output,stderr=subprocess.STDOUT)
            while process.poll() is None:
                if time.monotonic()-started>args.timeout:raise TimeoutError('Loading capture timed out')
                log=(out/'run.log').read_text(errors='replace')
                markers=list(PAUSE.finditer(log))
                frame=int(markers[-1].group(1)) if markers else 0
                if frame<=last:time.sleep(.02);continue
                if frame!=last+1:raise ValueError(f'Unexpected checkpoint {frame} after {last}')
                states.append(record_checkpoint(out,frame,log));last=frame
                (out/'checkpoints.json').write_text(json.dumps(states,indent=2)+'\n')
                write_control(out,frame+1)
        except (Exception,KeyboardInterrupt) as error:
            failure=f'{type(error).__name__}: {error}'
        finally:
            if process and process.poll() is None:
                process.terminate()
                try:process.wait(timeout=5)
                except subprocess.TimeoutExpired:process.kill();process.wait(timeout=5)
    report=acceptance(states,(out/'run.log').read_text(errors='replace'),process.returncode if process else None)
    if last!=LAST:report['errors'].append(f'Incomplete checkpoint interval: last={last}')
    if failure:report['errors'].append(failure)
    report.update(passed=not report['errors'],wall_seconds=time.monotonic()-started,checkpoints=states)
    (out/'acceptance.json').write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps({k:report[k] for k in ('passed','errors','observed_tiles','sequence')},indent=2))
    raise SystemExit(0 if report['passed'] else 1)


if __name__=='__main__':main()
