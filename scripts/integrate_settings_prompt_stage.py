"""New full-menu-v5 candidate: correct only the two JP Settings prompts."""
from pathlib import Path
import hashlib
import json
import shutil
import subprocess
from a2.pak import PakArchive
from settings_texture_patch import stage_patch,SLOTS
from menu_texture_patch import parse_container,unpack_indices

ROOT=Path(__file__).resolve().parents[1]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    old=ROOT/'port/build/verification/full-menu-v4'
    out=ROOT/'port/build/verification/full-menu-v5'
    if out.exists():raise FileExistsError('refusing existing full-menu-v5 stage')
    source_hash=sha(old/'DATA/PACK0.PAK')
    report=stage_patch(old/'DATA/PACK0.PAK',ROOT/'disc.orig/DATA/PACK0.PAK',out)
    before=PakArchive.load(old/'DATA/PACK0.PAK');after=PakArchive.load(out/'DATA/PACK0.PAK')
    assert len(before.slots)==len(after.slots)==768
    assert [i for i,(a,b) in enumerate(zip(before.slots,after.slots)) if a!=b]==list(SLOTS)
    assert len({after.slots[i] for i in SLOTS})==1
    for i in SLOTS:
        w,h,pal,a=parse_container(before.slots[i]);_,_,pal2,b=parse_container(after.slots[i])
        assert pal==pal2 and a[1]['compressed']==b[1]['compressed']
        ap=unpack_indices(a[0]['raw'],w,h,4);bp=unpack_indices(b[0]['raw'],w,h,4)
        for n,(x,y) in enumerate(zip(ap,bp)):
            if not (24<=n%w<76 and (98<=n//w<126 or 130<=n//w<158)):assert x==y
    shutil.copy2(old/'alundra2',out/'alundra2')
    for name in ('GRP.GP','PAKVCAST.PAK'):shutil.copy2(old/'DATA'/name,out/'DATA'/name)
    subprocess.run(['cp','-cR',str(old/'disc'),str(out/'disc')],check=True)
    shutil.copy2(out/'DATA/PACK0.PAK',out/'disc/DATA/PACK0.PAK')
    for p in (old/'disc').rglob('*'):
        if p.is_file() and p.relative_to(old/'disc')!=Path('DATA/PACK0.PAK'):
            assert sha(p)==sha(out/'disc'/p.relative_to(old/'disc'))
    subprocess.run([str(ROOT/'tools/mkpsxiso-src/build/mkpsxiso'),'-y','-o',str(out/'disc.bin'),'-c',str(out/'disc.cue'),'disc.xml'],cwd=out/'disc',check=True)
    assert sha(old/'DATA/PACK0.PAK')==source_hash
    report.update(unchanged_pack0_slots=761,only_changed_rectangles=[[24,98,52,28],[24,130,52,28]],
                  binary_sha256=sha(out/'alundra2'),image_sha256=sha(out/'disc.bin'))
    for name in ('GRP.GP','PAKVCAST.PAK'):
        assert sha(out/'DATA'/name)==sha(old/'DATA'/name)==sha(out/'disc/DATA'/name)
        report[name]=sha(out/'DATA'/name)
    (out/'integration.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
    print('Verified candidate',out)
if __name__=='__main__':main()
