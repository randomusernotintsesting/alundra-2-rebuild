"""Prepare and inspect a real Cocoa F5/F9 roundtrip; never synthesize save keys.

Prepare creates an isolated profile and launch manifest. Run opens only that
profile. The operator sends real F5/F9 through Computer Use while the game is
running between checkpoints. Resume changes ordinary frame/input stepping;
it never requests a save or load operation. No A2_TEST_SAVE_AT is used.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess

from verify_native_save_roundtrip import payload

ROOT = Path(__file__).resolve().parents[2]
APP = ROOT/'port/build/verification/september-polish/release/Alundra 2 HD.app'
SEED = ROOT/'port/build/verification/save-load-20260905/native-01/roundtrip/user/Saves/card1-BISCPS-1011500-6612A444.a2save'
FRAMES = {'ready':3000, 'saved':4200, 'moved':4500, 'loaded':5700, 'menu':6900}


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def prepare(output, binary, data, seed, archive=None, isolate_input=False):
    output,binary,data,seed = (Path(p).resolve() for p in (output,binary,data,seed))
    archive = Path(archive).resolve() if archive else None
    body = payload(seed)
    if struct.unpack_from('<H',body,0xC14)[0] != 14:
        raise ValueError('the seed must be the known map14 cabin checkpoint')
    media = (archive,) if archive else (data/'disc/SCPS_101.15',data/'disc.bin',data/'voices/en/voices.a2v')
    for path in (binary,*media):
        if not path.is_file():
            raise FileNotFoundError(path)
    output.mkdir(parents=True,exist_ok=False)
    user=output/'user'; (user/'Saves').mkdir(parents=True)
    shutil.copy2(seed,user/'Saves/seed.a2save')
    if isolate_input:
        # Keep real host F5/F9/Escape available while unrelated physical input
        # cannot walk the actor away from this bounded save/load fixture.
        # The ordinary Down step still travels through main's replay pad path.
        rows=[f'key_{bit}=0' for bit in range(16)]
        rows += [f'pad_{bit}_{slot}_{field}=0' for bit in range(16)
                 for slot in range(2) for field in ('kind','code')]
        (user/'a2settings.ini').write_text('\n'.join(rows)+'\n')
    (output/'control.txt').write_text('3000\n')
    # No inherited user settings or A2 diagnostics may alter this scenario.
    env=dict(SDL_VIDEODRIVER='cocoa',SDL_AUDIODRIVER='coreaudio',
             A2_USER_DIR=str(user),A2_PROFILE_ROOT=str(data),A2_NATIVE_SAVES='1',
             A2_LAUNCHER='0',A2_TEXT_LANGUAGE='0',A2_VOICE_LANGUAGE='1',
             A2_VOICE_PACK=str(data/'voices/en/voices.a2v'),A2_IRSCALE='3',
             A2_HDUI='1',A2_HD_PORTRAITS='1',A2_WIDE='1',A2_SOUND='1',A2_VOLUME='37',
             A2_AUTO='2',A2_SKIP='1',A2_TEST_NATIVE_LOAD='seed.a2save',
             A2_CONTROL_FILE=str(output/'control.txt'),A2_STATELOG='1',A2_TIMEOUT='240',
             A2_MAXFRAMES='7200')
    if archive:
        del env['A2_PROFILE_ROOT'], env['A2_VOICE_PACK']
        env['A2_RESOURCE_ARCHIVE'] = str(archive)
        env['A2_RESOURCE_LOG'] = '1'
    command = [str(binary),'--boot'] if archive else [str(binary),str(data/'disc'),'--boot',str(data/'disc.bin')]
    app = next((p for p in binary.parents if p.suffix == '.app'), None)
    manifest=dict(command=command,
                  env=env,seed=str(seed),seed_sha256=sha(seed),
                  seed_position_q12=list(struct.unpack_from('<3i',body,0xC50)),
                  checkpoints=FRAMES,computer_use_target=str(app) if app else None,
                  resource_backend='native-archive' if archive else 'legacy-disc',
                  isolate_physical_gameplay_input=bool(isolate_input),
                  archive_sha256=sha(archive) if archive else None,notes=[
                      'The command records the exact executable selected at preparation.',
                      'Computer Use targets the complete new .app path, never the shared bundle identifier.',
                      'TEST_NATIVE_LOAD selects only the initial fixture at the ordinary browser boundary.',
                      'A real quick F9 overrides that seed filename in the production quick branch.',
                      'Never press F5/F9 at a control pause: that loop deliberately discards key events.',
                      'Resume to saved, immediately send F5; resume to moved with ordinary Down25-frame input;',
                      'resume to loaded, immediately send F9. Wait for each control: paused marker.',
                      'A 240-second game timeout does not replace the driver timeout while at a control pause.'
                  ])
    (output/'launch.json').write_text(json.dumps(manifest,ensure_ascii=False,indent=2)+'\n')
    return dict(prepared=str(output),seed_sha256=manifest['seed_sha256'],runtime_started=False)


def run(output):
    output=Path(output).resolve(); m=json.loads((output/'launch.json').read_text())
    env={k:v for k,v in os.environ.items() if not k.startswith(('A2_','SDL_'))}
    env.update(m['env'])
    (output/'run-binary.sha256').write_text(sha(m['command'][0])+'\n')
    with (output/'run.log').open('w') as log:
        process=subprocess.Popen(m['command'],env=env,stdout=log,stderr=subprocess.STDOUT)
        (output/'pid').write_text(str(process.pid)+'\n')
        try:
            result=process.wait(timeout=300)
        except subprocess.TimeoutExpired:
            process.terminate()
            try: process.wait(timeout=5)
            except subprocess.TimeoutExpired: process.kill();process.wait()
            raise RuntimeError('owned Cocoa acceptance exceeded its 300-second bound')
    return dict(exit_code=result)


def resume(output,stage):
    output=Path(output).resolve()
    current=int((output/'control.txt').read_text().splitlines()[0])
    target=FRAMES[stage]
    if target <= current:
        raise ValueError('resume target must be a later checkpoint')
    taps='4300:6:25\n' if stage=='moved' else ''
    temporary=output/'control.next'
    temporary.write_text(f'{target}\n{taps}')
    temporary.replace(output/'control.txt')
    return dict(resumed_until=target,send_key_now='F5' if stage=='saved' else 'F9' if stage=='loaded' else None)


def verify(output,stage):
    output=Path(output).resolve();m=json.loads((output/'launch.json').read_text())
    user=output/'user';frame=FRAMES[stage]
    ram=(user/f'ram_{frame:05d}.bin').read_bytes()
    assert len(ram)==0x200000,'incomplete checkpoint capture'
    assert struct.unpack_from('<H',ram,0x12789C)[0]==14,'left permitted map14'
    assert ram[0x1310A0:0x1310A3]==b'b30','wrong cabin scene'
    assert struct.unpack_from('<I',ram,0x811D8)[0]==4,'ordinary GAME00 overlay is not active'
    assert struct.unpack_from('<I',ram,0xF6220)[0]==0,'game has not returned to ordinary play'
    assert all(ram[address]==0 for address in (0xF621C,0x11752A,0x64018)), 'quick action is still blocked by game state'
    assert 14 in struct.unpack_from('<40H',ram,0xEEF10), 'current map does not support quick saving'
    start_edge=struct.unpack_from('<H',ram,0x5E6CC)[0]&0x800
    action=struct.unpack_from('<h',ram,0x128C52)[0]
    assert not (start_edge and action<100), 'pending Start input would replace the quick action'
    assert sha(m['seed'])==m['seed_sha256'],'original seed changed'
    assert sha(user/'Saves/seed.a2save')==m['seed_sha256'],'isolated seed changed'
    log=(output/'run.log').read_text()
    assert 'native-save-error:' not in log and 'VSync: timeout' not in log,'runtime error in log'
    if m.get('resource_backend') == 'native-archive':
        assert 'native-resource: read ' in log, 'native resource backend did not read'
        assert 'voices: native English archive ready' in log, 'native voice backend did not open'
        assert 'Native playback failed:' not in log, 'native transport failure'
    # Runtime joins its normalized user directory (with trailing slash) to /Saves.
    def file_event(operation,path):
        prefix=f'native-save-file: {operation} result=1 '
        return any(Path(line[len(prefix):])==path for line in log.splitlines() if line.startswith(prefix))
    position=list(struct.unpack_from('<3i',ram,0x119728))
    result=dict(stage=stage,frame=frame,position_q12=position,seed_unchanged=True)
    if stage=='ready':
        assert 'native-save: load result=1 scene=14' in log
        assert not (user/'Saves/quick.a2save').exists(),'quick file must not precede real F5'
        assert position==m['seed_position_q12'],'fixture actor did not enter saved position'
    else:
        quick=user/'Saves/quick.a2save';body=payload(quick)
        saved_position=list(struct.unpack_from('<3i',body,0xC50))
        assert 'native-save: save result=1 scene=14' in log,'real F5 did not complete'
        assert file_event('write',quick),'save did not use production quick path'
        result.update(quick_sha256=sha(quick),saved_position_q12=saved_position)
        if stage=='moved':
            assert position!=saved_position,'ordinary input did not move the actor away'
        else:
            assert ram[0x626F8:0x63384]==body[0x100:0xD8C],'full checkpoint backup differs'
            assert position==saved_position,'actual actor is not at saved position'
        if stage=='loaded':
            assert file_event('read',quick),'F9 loaded the seed instead of the quick file'
            previous=json.loads((output/'saved-result.json').read_text())
            assert sha(quick)==previous['quick_sha256'],'load modified the saved file'
            moved=json.loads((output/'moved-result.json').read_text())
            assert moved['position_q12']!=position,'reload did not restore position'
            result.update(full_checkpoint_restored=True,quick_file_unchanged=True)
    (output/f'{stage}-result.json').write_text(json.dumps(result,indent=2)+'\n')
    return result


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    sub=parser.add_subparsers(dest='action',required=True)
    p=sub.add_parser('prepare');p.add_argument('--output',type=Path,required=True)
    p.add_argument('--binary',type=Path,default=APP/'Contents/MacOS/alundra2')
    p.add_argument('--data',type=Path,default=ROOT/'port/build/game-data')
    p.add_argument('--archive',type=Path,help='Use this native archive with no image or extracted data paths')
    p.add_argument('--seed',type=Path,default=SEED)
    p.add_argument('--isolate-input',action='store_true',
                   help='Unbind gameplay inputs only in the new private profile; actual host F5/F9 remain active')
    p=sub.add_parser('run');p.add_argument('--output',type=Path,required=True)
    for action in ('resume','verify'):
        p=sub.add_parser(action);p.add_argument('--output',type=Path,required=True)
        p.add_argument('--stage',choices=tuple(FRAMES) if action=='verify' else ('saved','moved','loaded','menu'),required=True)
    args=parser.parse_args()
    if args.action=='prepare':result=prepare(args.output,args.binary,args.data,args.seed,args.archive,args.isolate_input)
    elif args.action=='run':result=run(args.output)
    elif args.action=='resume':result=resume(args.output,args.stage)
    else:result=verify(args.output,args.stage)
    print(json.dumps(result,ensure_ascii=False,indent=2),flush=True)
