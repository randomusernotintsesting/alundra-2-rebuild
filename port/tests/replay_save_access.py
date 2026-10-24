"""Verify startup load and ordinary quick-save round trips in private profiles.

The Eden route walks out through the original door (412 -> 410). The tutorial
starts a real new game and skips its movies with normal pad input. No RAM edits.
Only compact evidence is kept after full checkpoint and Q12 position checks.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
import time
import zlib
from PIL import Image
from replay_native_voice import checkpoint, write_control


def digest(data):
    return hashlib.sha256(data).hexdigest()


def replay(args, name, seed, frames, taps=(), saving=0, loading=0, new_game=False):
    out = args.output / name
    out.mkdir(parents=True, exist_ok=False)
    user = out / 'user'
    (user / 'Saves').mkdir(parents=True)
    shutil.copy2(seed, user / 'Saves/seed.a2save')
    settings = ['fullscreen=0', 'window_w=960', 'window_h=540', 'skip_intro=1']
    settings += [f'key_{i}=0' for i in range(16)]
    settings += [f'pad_{i}_{j}_{f}=0' for i in range(16) for j in range(2)
                 for f in ('kind', 'code')]
    (user / 'a2settings.ini').write_text('\n'.join(settings) + '\n')
    env = {k: v for k, v in os.environ.items() if not k.startswith(('A2_', 'SDL_', 'DYLD_'))}
    launch = dict(SDL_VIDEODRIVER='dummy', SDL_AUDIODRIVER='dummy', A2_FAST='1',
                  A2_USER_DIR=str(user), A2_RESOURCE_ARCHIVE=str(args.archive),
                  A2_NATIVE_SAVES='1', A2_LAUNCHER='0', A2_TEST_NATIVE_LOAD='seed.a2save',
                  A2_TEXT_LANGUAGE='0', A2_VOICE_LANGUAGE='0', A2_IRSCALE='1', A2_SOUND='0',
                  A2_STATELOG='1', A2_CONTROL_FILE=str(out / 'control.txt'),
                  A2_MAXFRAMES=str(frames[-1] + 1), A2_TIMEOUT='60')
    if new_game:
        launch.update(A2_AUTO='1', A2_SKIP='1')
    else:
        launch['A2_TEST_STARTUP_LOAD'] = '1'
    if saving:
        launch['A2_TEST_QUICK_SAVE_AT'] = str(saving)
    if loading:
        launch['A2_TEST_QUICK_LOAD_AT'] = str(loading)
    env.update(launch)
    write_control(out, 0, frames[0], taps)
    (out / 'launch.json').write_text(json.dumps(dict(binary=str(args.binary), env=launch,
         binary_sha256=digest(args.binary.read_bytes()), seed_sha256=digest(seed.read_bytes())), indent=2))
    states = []
    start = time.monotonic()
    with (out / 'run.log').open('w') as log:
        proc = subprocess.Popen([str(args.binary), '--boot'], env=env, stdout=log, stderr=subprocess.STDOUT)
        try:
            for i, frame in enumerate(frames):
                while True:
                    state = checkpoint((out / 'run.log').read_text(errors='replace'))
                    if state and state['frame'] == frame:
                        break
                    if proc.poll() is not None:
                        raise RuntimeError(f'{name}: exited before frame {frame}')
                    if time.monotonic() - start > 70:
                        raise TimeoutError(f'{name}: bounded replay exceeded 70 seconds')
                    time.sleep(.04)
                assert state['overlay'] == 4 and state['flags'] == 0, state
                ram = (user / f'ram_{frame:05}.bin').read_bytes()
                state.update(position_q12=list(struct.unpack_from('<3i', ram, 0x119728)),
                             backup_sha256=digest(ram[0x626f8:0x63384]), ram_sha256=digest(ram))
                states.append(state)
                if i + 1 < len(frames):
                    write_control(out, frame, frames[i + 1], taps)
                else:
                    proc.terminate()
            assert proc.wait(timeout=10) == 0
        finally:
            if proc.poll() is None:
                proc.terminate()
                proc.wait(timeout=10)
    source = user / 'Saves/quick.a2save' if saving else seed
    file = source.read_bytes()
    payload = file[48:]
    assert len(file) == 8240 and zlib.crc32(payload) == struct.unpack_from('<I', file, 20)[0]
    scene = struct.unpack_from('<H', payload, 0xc14)[0]
    saved_position = list(struct.unpack_from('<3i', payload, 0xc50))
    backup_sha = digest(payload[0x100:0xd8c])
    restored = [states[-1]] if saving else states
    for state in restored:
        assert state['map_id'] == scene and state['position_q12'] == saved_position, state
        assert state['backup_sha256'] == backup_sha, state
    if saving:
        before_move = states[2]
        assert before_move['position_q12'] == saved_position
        assert before_move['backup_sha256'] == backup_sha
        assert states[-2]['position_q12'] != saved_position, 'Replay must actually move after saving'
        assert scene not in (14,20,10,24,59,331,28,297,106,121,418,422,185,142,152,89,163,174,472,222,
                             286,350,414,490,178,450,412,472,118,424,430,75,243,311,489,305,271,232,281,271)
        assert struct.unpack_from('<I', file, 8)[0] == 2
    report = dict(passed=True, scene=scene, exact_position_restored=True,
                  full_persistent_checkpoint_restored=True, states=states,
                  save_sha256=digest(file), wall_seconds=time.monotonic()-start)
    (out / 'acceptance.json').write_text(json.dumps(report, indent=2))
    Image.open(user / f'frame_{frames[-1]:05}.bmp').save(out / 'gameplay.png')
    for pattern in ('ram_*.bin', 'vram_*.bin', 'frame_*.bmp'):
        for path in user.glob(pattern):
            path.unlink()
    print(f'PASS {name}: map {scene}, exact position and complete checkpoint restored.', flush=True)
    return source


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('binary', 'archive', 'eden_seed', 'legacy_seed', 'output'):
        parser.add_argument('--' + name.replace('_', '-'), type=Path, required=True)
    args = parser.parse_args()
    for name in vars(args):
        setattr(args, name, getattr(args, name).resolve())
    args.output.mkdir(parents=True, exist_ok=False)
    replay(args, 'legacy-startup', args.legacy_seed, [600,900])
    route = '2101:5:20,2161:6:90,2281:5:30,2341:6:80,2461:7:25,2521:6:50,2581:13:4,2641:7:80,2641:14:8,2821:4:30,2881:7:60,3001:6:70,3121:6:50,4701:5:40'.split(',')
    eden = replay(args, 'eden-roundtrip', args.eden_seed, [600,4300,4600,4990,5500], route, 4301,5001)
    replay(args, 'eden-restart', eden, [600,900])
    tutorial = replay(args, 'tutorial-roundtrip', args.legacy_seed, [3600,4000,4400,4900,5500],
                      ['3701:5:30','4601:5:30'], 4001,5001,new_game=True)
    replay(args, 'tutorial-restart', tutorial, [600,900])
    print('PASS: legacy startup, outdoor and tutorial quick-save/load, and cold restarts.')


if __name__ == '__main__':
    main()
