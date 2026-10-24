"""Replay Start using normal input and a copied Eden save; reject black frames."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import time

from PIL import Image
from replay_native_voice import checkpoint, write_control


def sha256(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('binary', 'archive', 'output', 'seed'):
        parser.add_argument('--' + name, type=Path, required=True)
    parser.add_argument('--headless', action='store_true')
    parser.add_argument('--fill', type=int, choices=(0, 1), default=1)
    parser.add_argument('--ir', type=int, choices=(1, 2, 3, 4), default=2)
    parser.add_argument('--language', choices=('ru', 'en', 'jp'), default='ru')
    parser.add_argument('--frames', default='1700,2379,2380,2381,2390,2391,2392,2400,2900')
    args = parser.parse_args()
    frames = [int(frame) for frame in args.frames.split(',')]
    if frames != sorted(set(frames)) or frames[0] != 1700 or frames[-1] != 2900:
        parser.error('Frames must increase from 1700 to 2900.')
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=False)
    user = out / 'user'
    (user / 'Saves').mkdir(parents=True)
    shutil.copy2(args.seed, user / 'Saves/seed.a2save')
    settings = ['window_w=1440', 'window_h=900', 'fullscreen=0',
                f'fill_screen={args.fill}', 'skip_intro=1', 'subtitles=0']
    # Physical input cannot move the actor or interfere with this replay.
    settings += [f'key_{i}=0' for i in range(16)]
    settings += [f'pad_{i}_{j}_{field}=0' for i in range(16)
                 for j in range(2) for field in ('kind', 'code')]
    (user / 'a2settings.ini').write_text('\n'.join(settings) + '\n')
    taps = ['1801:3:4', '2601:3:4']
    write_control(out, 0, frames[0], [])
    env = {k: v for k, v in os.environ.items()
           if not k.startswith(('A2_', 'SDL_', 'DYLD_'))}
    launch = dict(
        SDL_VIDEODRIVER='dummy' if args.headless else 'cocoa', SDL_AUDIODRIVER='dummy',
        A2_USER_DIR=str(user), A2_RESOURCE_ARCHIVE=str(args.archive.resolve()),
        A2_LAUNCHER='0', A2_AUTO='2', A2_TEST_NATIVE_LOAD='seed.a2save',
        A2_NATIVE_SAVES='1', A2_TEXT_LANGUAGE=str(('ru', 'en', 'jp').index(args.language)),
        A2_VOICE_LANGUAGE='1', A2_IRSCALE=str(args.ir), A2_HDUI='1', A2_HD_PORTRAITS='1',
        A2_WIDE='1', A2_SOUND='0', A2_STATELOG='1', A2_CINEMALOG='1',
        A2_MAXFRAMES='2901', A2_TIMEOUT='100', A2_CONTROL_FILE=str(out / 'control.txt'),
        A2_WORLD_PRECISION='1', A2_WORLD_CAMERA='1', A2_WORLD_RASTER='1',
        A2_LOCAL_POSE='1', A2_MODEL_DEPTH='1', A2_PRECISE_CULL='2',
        A2_COLOR_CONTINUITY='1', A2_COLOR_PRECISION='1', A2_MODEL_MINIFY='1',
        A2_FINE_PARALLEL='1', A2_FILTER='1', A2_ANTIALIAS='1', A2_GPU_PRESENT='1')
    if args.headless:
        launch['A2_FAST'] = '1'
    else:
        launch.update(A2_UISHOT='2400', A2_UISHOT_PATH=str(out / 'window.bmp'))
    env.update(launch)
    command = [str(args.binary.resolve()), '--boot']
    (out / 'launch.json').write_text(json.dumps(dict(
        env=launch, command=command, seed_sha256=sha256(args.seed),
        binary_sha256=sha256(args.binary)), indent=2))
    states = []
    start = time.monotonic()
    with (out / 'run.log').open('w') as log:
        proc = subprocess.Popen(command, env=env, stdout=log, stderr=subprocess.STDOUT)
        (out / 'pid').write_text(str(proc.pid))
        try:
            for n, frame in enumerate(frames):
                while True:
                    state = checkpoint((out / 'run.log').read_text(errors='replace'))
                    if state and state['frame'] == frame:
                        break
                    if proc.poll() is not None:
                        raise RuntimeError('Game exited before the checkpoint.')
                    if time.monotonic() - start > 110:
                        raise TimeoutError('Bounded Start replay exceeded 110 seconds.')
                    time.sleep(.05)
                states.append(state)
                print(state, flush=True)
                assert state['map_id'] == 412 and state['overlay'] == 4, state
                expected_flags = 2 if 1850 <= frame <= 2600 else 0
                assert state['flags'] == expected_flags, state
                if n + 1 < len(frames):
                    write_control(out, frame, frames[n + 1], taps)
                else:
                    proc.terminate()
            code = proc.wait(timeout=10)
            assert code == 0, code
        finally:
            if proc.poll() is None:
                proc.terminate()
                proc.wait(timeout=10)
    shots = []
    for frame in frames:
        path = user / f'frame_{frame:05}.bmp'
        im = Image.open(path).convert('RGB')
        nonblack = sum(count for count, color in im.getcolors(im.width * im.height)
                       if max(color) > 8)
        # The failing build is entirely black at 2380 and 2391 while flags=2.
        assert nonblack > im.width * im.height // 10, f'Black frame at {frame}'
        im.save(path.with_suffix('.png'))
        shots.append(dict(frame=frame, size=im.size, nonblack_pixels=nonblack,
                          sha256=hashlib.sha256(im.tobytes()).hexdigest()))
    report = dict(passed=True, states=states, shots=shots,
                  wall_seconds=time.monotonic() - start)
    (out / 'replay.json').write_text(json.dumps(report, indent=2))
    print('PASS: gameplay → Start menu → gameplay; all captured frames populated.')


if __name__ == '__main__':
    main()
