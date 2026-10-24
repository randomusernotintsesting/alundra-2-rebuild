"""Add only brightness to frozen full-menu-v3, producing new full-menu-v4."""
from pathlib import Path
import hashlib
import json
import shutil
import subprocess
from a2.pak import PakArchive
from brightness_texture_patch import stage_patch,SLOTS

ROOT=Path(__file__).resolve().parents[1]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    old=ROOT/'port/build/verification/full-menu-v3';out=ROOT/'port/build/verification/full-menu-v4'
    report=stage_patch(old/'DATA/PACK0.PAK',ROOT/'disc.orig/DATA/PACK0.PAK',out)
    before=PakArchive.load(old/'DATA/PACK0.PAK');after=PakArchive.load(out/'DATA/PACK0.PAK')
    assert len(before.slots)==len(after.slots)
    assert all(a==b for i,(a,b) in enumerate(zip(before.slots,after.slots)) if i not in SLOTS)
    assert len({after.slots[i] for i in SLOTS})==1
    shutil.copy2(old/'alundra2',out/'alundra2')
    for name in ('GRP.GP','PAKVCAST.PAK'):shutil.copy2(old/'DATA'/name,out/'DATA'/name)
    subprocess.run(['cp','-cR',str(old/'disc'),str(out/'disc')],check=True)
    shutil.copy2(out/'DATA/PACK0.PAK',out/'disc/DATA/PACK0.PAK')
    subprocess.run([str(ROOT/'tools/mkpsxiso-src/build/mkpsxiso'),'-y','-o',str(out/'disc.bin'),'-c',str(out/'disc.cue'),'disc.xml'],cwd=out/'disc',check=True)
    report.update(binary_sha256=sha(out/'alundra2'),image_sha256=sha(out/'disc.bin'),unchanged_pack0_slots=761)
    for name in ('GRP.GP','PAKVCAST.PAK'):
        assert sha(out/'DATA'/name)==sha(old/'DATA'/name)==sha(out/'disc/DATA'/name)
        report[name]=sha(out/'DATA'/name)
    (out/'integration.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
    print('Verified candidate',out)
if __name__=='__main__':main()
