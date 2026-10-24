"""Capture original guest menus with native device labels from a copied save.

Prepare only unless --run is explicit. The route uses ordinary pad bits, never
RAM restoration, injected menu state or host F1. The initial save is selected
through the existing native save browser fixture, then checked in actual RAM.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
import sys
import time

from replay_native_voice import ARCHIVE,ROOT,checkpoint,write_control
from verify_hd_menus import route,shift_route

SEED=ROOT/'port/build/verification/save-load-20260905/native-01/roundtrip/user/Saves/card1-BISCPS-1011500-6612A444.a2save'


def menu_schedule(adjacent=False,return_game=False):
    _,taps,frames=route('menu-return' if return_game else 'settings-controls')
    # Original Start4700 -> new Start3001 after the verified copied cabin save.
    taps,frames=shift_route(taps,frames,-1699)
    checkpoints=[3000,*frames[:2]]
    if adjacent:checkpoints=[*checkpoints[:-1],*range(frames[1]-1,frames[1]+3)]
    if return_game:checkpoints += [6301,frames[2]]
    cutoff=frames[2] if return_game else frames[1]
    return [tap for tap in taps if int(tap.split(':')[0])<cutoff],checkpoints


def renderer_capture(out,frame):
    path=out/'keyconfig-renderer.bmp'
    return dict(A2_UISHOT=str(frame),A2_UISHOT_PATH=str(path)),dict(
        frame=frame,bmp=str(path),method='SDL_RenderReadPixels after composition; no resize',
        scope='Actual renderer pixels under SDL dummy; no physical window or display claim')


def export_renderer_capture(metadata,log):
    from PIL import Image
    if f"ui shot dumped at frame {metadata['frame']}\n" not in log:
        raise RuntimeError('Missing matching actual SDL renderer capture log')
    source=Path(metadata['bmp'])
    with Image.open(source) as picture:
        size=list(picture.size)
        picture.save(source.with_suffix('.png'))
    return dict(metadata,size=size,png=str(source.with_suffix('.png')),
        bmp_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),
        aspect_ratio=size[0]/size[1])


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--binary',type=Path,default=ROOT/'port/build/alundra2')
    p.add_argument('--archive',type=Path,default=ARCHIVE)
    p.add_argument('--seed',type=Path,default=SEED)
    p.add_argument('--output',type=Path,required=True)
    p.add_argument('--keyconfig-neighbors',action='store_true',help='Retain four consecutive menu presentations for cadence diagnostics')
    p.add_argument('--return-game',action='store_true',help='Leave nested menus using the original Cancel/Cancel/Start route')
    p.add_argument('--run',action='store_true')
    args=p.parse_args();out=args.output.resolve();out.mkdir(parents=True,exist_ok=False)
    user=out/'user';(user/'Saves').mkdir(parents=True)
    seed=args.seed.resolve();shutil.copy2(seed,user/'Saves/seed.a2save')
    # Keep meaningful configured keyboard labels while preventing unrelated
    # physical pad state from moving the actor during this bounded fixture.
    settings=['key_9=225','key_14=44']
    settings += [f'pad_{bit}_{slot}_{field}=0' for bit in range(16)
                 for slot in range(2) for field in ('kind','code')]
    (user/'a2settings.ini').write_text('\n'.join(settings)+'\n')
    binary,archive=args.binary.resolve(),args.archive.resolve()
    taps,frames=menu_schedule(args.keyconfig_neighbors,args.return_game);command=[str(binary),'--boot']
    overrides=dict(SDL_VIDEODRIVER='dummy',SDL_AUDIODRIVER='dummy',A2_FAST='1',
        A2_USER_DIR=str(user),A2_RESOURCE_ARCHIVE=str(archive),A2_LAUNCHER='0',
        A2_AUTO='2',A2_SKIP='1',A2_TEST_NATIVE_LOAD='seed.a2save',A2_NATIVE_SAVES='1',
        A2_TEXT_LANGUAGE='0',A2_VOICE_LANGUAGE='0',A2_IRSCALE='2',A2_WIDE='1',
        A2_HDUI='1',A2_HD_PORTRAITS='1',A2_SOUND='1',A2_STATELOG='1',A2_DISPLOG='1',
        A2_HUD_LOG='1',
        A2_MAXFRAMES=str(frames[-1]+60),A2_TIMEOUT='150',A2_CONTROL_FILE=str(out/'control.txt'))
    renderer_env,renderer_metadata=renderer_capture(out,5901);overrides.update(renderer_env)
    plan=dict(command=command,environment=overrides,prepared_only=not args.run,
        renderer_capture=renderer_metadata,
        ordinary_taps=taps,checkpoints=frames,seed=str(seed),
        seed_sha256=hashlib.sha256(seed.read_bytes()).hexdigest(),
        no_ram_injection=True,note='FAST/dummy guest-menu images; keyboard bindings come from private production settings')
    if args.run:plan['binary_sha256']=hashlib.sha256(binary.read_bytes()).hexdigest()
    (out/'launch.json').write_text(json.dumps(plan,indent=2)+'\n');write_control(out,0,frames[0],[])
    if not args.run:print(out/'launch.json');return
    env={k:v for k,v in os.environ.items() if not k.startswith(('A2_','SDL_','DYLD_'))};env.update(overrides)
    process=None;states=[];started=time.monotonic();result=dict(passed=False)
    with (out/'run.log').open('w') as log:
        try:
            process=subprocess.Popen(command,cwd=out,env=env,stdout=log,stderr=subprocess.STDOUT)
            (out/'pid').write_text(str(process.pid)+'\n')
            for index,expected in enumerate(frames):
                while True:
                    text=(out/'run.log').read_text(errors='replace');state=checkpoint(text)
                    if state and state['frame']==expected:break
                    if process.poll() is not None:raise RuntimeError(f'Exited before frame{expected}')
                    if time.monotonic()-started>160:raise TimeoutError('Menu capture exceeded160 seconds')
                    time.sleep(.1)
                ram=(user/f'ram_{expected:05}.bin').read_bytes()
                if len(ram)!=0x200000:raise RuntimeError('Incomplete RAM capture')
                if state['overlay']!=4 or state['map_id']!=14:raise RuntimeError(f'Left expected guest scene: {state}')
                if index==0 and (state['flags'] or state['pos']!=[-175,0,24]):
                    raise RuntimeError(f'Wrong initial copied cabin state: {state}')
                if args.return_game and index==len(frames)-1 and state['flags']:
                    raise RuntimeError(f'Nested menu did not return to ordinary gameplay: {state}')
                state['keyconfig_preview']=list(struct.unpack_from('<9H',ram,0x143a88))
                state['guest_actions']=list(struct.unpack_from('<9H',ram,0x63eee))
                states.append(state);print(state,flush=True)
                if index+1<len(frames):write_control(out,expected,frames[index+1],taps)
            process.terminate();process.wait(timeout=10)
            if process.returncode:raise RuntimeError(f'Controlled exit{process.returncode}')
            renderer=export_renderer_capture(renderer_metadata,(out/'run.log').read_text(errors='replace'))
            result=dict(passed=True,exit_code=0,requires_visual_review=True,renderer_capture=renderer)
        except BaseException as error:
            result['error']=repr(error);raise
        finally:
            if process and process.poll() is None:
                process.terminate()
                try:process.wait(timeout=5)
                except subprocess.TimeoutExpired:process.kill();process.wait(timeout=10)
            result.update(wall_seconds=time.monotonic()-started,states=states,
                          exit_code=process.returncode if process else None)
            (out/'capture.json').write_text(json.dumps(result,indent=2)+'\n')
    from PIL import Image
    for state in states:
        source=user/f"frame_{state['frame']:05}.bmp"
        with Image.open(source) as picture:
            picture.save(source.with_suffix('.png'))
            picture.resize((960,540),Image.Resampling.LANCZOS).save(
                source.with_name(source.stem+'-scaled-16x9-preview.png'))
    print(json.dumps(result,indent=2))


if __name__=='__main__':main()
