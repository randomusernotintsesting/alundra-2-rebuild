"""Bounded ordinary-pad route to the first English subtitle (no RAM restore)."""
import argparse
import hashlib
import json
import re
import subprocess
import sys
import time
from pathlib import Path
from replay_routes import tutorial_taps

ROOT=Path(__file__).resolve().parents[2]
PHASES=(6000,9000,12000,14000,15000,15800,15802)

def route():
    taps=[f'{frame}:3' for frame in (*range(900,1401,100),*range(2300,2701,100))]
    for tap in tutorial_taps():
        frame,*rest=tap.split(':');taps.append(':'.join((str(int(frame)-1001),*rest)))
    return taps

def control(out,current,until,taps):
    active=[]
    if current<15000:
        for tap in taps:
            parts=list(map(int,tap.split(':')));duration=parts[2] if len(parts)>2 else 4
            if parts[0]<until and parts[0]+duration>current:active.append(tap)
    if len(active)>128:raise ValueError('Control batch exceeds native capacity')
    contents=str(until)+'\n'+('\n'.join(active)+'\n' if active else '')
    (out/f'control-{until}.txt').write_text(contents)
    pending=out/'control.next';pending.write_text(contents);pending.replace(out/'control.txt')


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--binary',type=Path,default=ROOT/'port/build/alundra2')
    p.add_argument('--output',type=Path,required=True)
    p.add_argument('--ir-scale',type=int,choices=(2,3,4),default=2)
    args=p.parse_args();out=args.output.resolve();out.mkdir(parents=True,exist_ok=False)
    base=ROOT/'port/build/verification/september-polish';taps=route()
    control(out,0,PHASES[0],taps)
    cmd=[sys.executable,str(ROOT/'port/tools/replay.py'),'--binary',str(args.binary.resolve()),
         '--disc',str(base/'profiles/en/disc'),'--image',str(base/'profiles/en/disc.bin'),
         '--profile-root',str(base),'--text-language','en','--voice-language','en',
         '--voice-pack',str(base/'voices/en/voices.a2v'),'--auto','new','--natural-intro',
         '--frames','15801','--every','1000','--ir-scale',str(args.ir_scale),'--wide',
         '--sound','--audio-stats','--timeout','600','--control-file',str(out/'control.txt'),
         '--output',str(out)]
    (out/'route.json').write_text(json.dumps(dict(command=cmd,taps=taps,
        binary_sha256=hashlib.sha256(args.binary.read_bytes()).hexdigest(),
        stop_inputs_after=15000,source='ordinary tutorial_taps shifted -1001; explicit Start only900..1400 and2300..2700'),indent=2)+'\n')
    process=subprocess.Popen(cmd,cwd=ROOT);phase=0;deadline=time.monotonic()+610
    try:
        while process.poll() is None:
            if time.monotonic()>deadline:raise TimeoutError('Bounded subtitle replay timed out')
            log=out/'run.log'
            if log.exists() and phase<len(PHASES)-1:
                with log.open('rb') as f:
                    f.seek(max(0,log.stat().st_size-8192));tail=f.read().decode(errors='replace')
                matches=list(re.finditer(r'control: paused frame=(\d+) overlay=(\d+)',tail))
                if matches and int(matches[-1][1])==PHASES[phase]:
                    current=PHASES[phase]
                    if current==15000 and int(matches[-1][2])!=5:
                        raise RuntimeError('Tutorial route did not enter the expected event')
                    phase+=1;control(out,current,PHASES[phase],taps)
                    print(f'Resumed {current} -> {PHASES[phase]}',flush=True)
            time.sleep(.1)
        if process.returncode:raise SystemExit(process.returncode)
    finally:
        if process.poll() is None:process.terminate();process.wait(timeout=10)
    from PIL import Image
    for path in sorted((out/'user').glob('frame_*.bmp')):Image.open(path).save(path.with_suffix('.png'))
    print(out/'user/frame_15800.png')

if __name__=='__main__':main()
