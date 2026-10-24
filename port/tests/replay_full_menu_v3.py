"""Reproduce integrated menu v3 with a frozen binary and ordinary pad inputs."""
from pathlib import Path
import subprocess
import sys
from verify_pocket_chest import pocket_chest_taps

ROOT=Path(__file__).resolve().parents[2]
BASE=ROOT/'port/build/verification/full-menu-v3'
POST='''19020:13:4
19320:14:4 19500:14:4 19700:13:4
19920:13:4 20100:5:4 20200:13:4
20420:13:4 20600:5:4 20800:13:4
21020:13:4
21320:14:4 21500:5:4 21700:13:4
21820:14:4 22000:5:4 22200:13:4
22320:12:4 22500:14:4 22700:7:4 22800:13:4
22920:14:4 23100:14:4 23300:7:4 23500:13:4'''.split()

def run(name,frames,taps):
    out=BASE/name
    if out.exists():raise FileExistsError(out)
    cmd=[sys.executable,str(ROOT/'port/tools/replay.py'),'--binary',str(BASE/'alundra2'),
         '--disc',str(BASE/'disc'),'--image',str(BASE/'disc.bin'),'--output',str(out),
         '--frames',str(frames),'--every','100','--timeout','300']
    for tap in taps:cmd+=['--tap',tap]
    subprocess.run(cmd,check=True)

if __name__=='__main__':
    if sys.argv[1:] == ['settings']:
        run('settings-replay',6500,['4700:3:4','5000:5:4','5200:5:4','5400:13:4','5800:7:4','6000:13:4'])
    else:
        run('chest-replay',23700,[x for x in pocket_chest_taps() if int(x.split(':')[0])<19000]+POST)
