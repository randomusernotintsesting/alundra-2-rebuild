"""Complete a new title-patch stage with a cloned disc and rebuilt raw image."""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess

from a2.pak import PakArchive
from menu_texture_patch import parse_container

ROOT = Path(__file__).resolve().parents[1]


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def integrate(source, output):
    source, output = Path(source), Path(output)
    if (output/'disc').exists() or (output/'disc.bin').exists():
        raise FileExistsError('refusing existing integrated disc')
    before = PakArchive.load(source/'DATA/PACK0.PAK')
    after = PakArchive.load(output/'DATA/PACK0.PAK')
    if len(before.slots)!=len(after.slots) or [i for i,(a,b) in enumerate(zip(before.slots,after.slots)) if a!=b]!=[23]:
        raise ValueError('stage changes more than the title slot')
    w,h,pal,a = parse_container(before.slots[23])
    _,_,newpal,b = parse_container(after.slots[23])
    if newpal!=pal or [c['compressed'] for c in a[1:]]!=[c['compressed'] for c in b[1:]]:
        raise ValueError('stage changes title art pages or palette')
    for i,(old,new) in enumerate(zip(a[0]['raw'],b[0]['raw'])):
        if not (64<=i%w<192 and 240<=i//w<256) and old!=new:
            raise ValueError('stage changes non-choice title artwork')
    hashes = {str(p.relative_to(source/'disc')):digest(p)
              for p in (source/'disc').rglob('*') if p.is_file()}
    source_pak_hash = digest(source/'DATA/PACK0.PAK')
    # APFS clone (copy-on-write), never hardlinks to the authoritative v5.
    subprocess.run(['cp','-cR',str(source/'disc'),str(output/'disc')],check=True)
    shutil.copy2(output/'DATA/PACK0.PAK',output/'disc/DATA/PACK0.PAK')
    for name in ('GRP.GP','PAKVCAST.PAK'):
        shutil.copy2(source/'DATA'/name,output/'DATA'/name)
    for name,expected in hashes.items():
        if digest(source/'disc'/name)!=expected:
            raise AssertionError(f'source changed: {name}')
        if name!='DATA/PACK0.PAK' and digest(output/'disc'/name)!=expected:
            raise AssertionError(f'cloned non-title disc file changed: {name}')
    subprocess.run([str(ROOT/'tools/mkpsxiso-src/build/mkpsxiso'),'-y',
                    '-o',str((output/'disc.bin').resolve()),'-c',str((output/'disc.cue').resolve()),
                    'disc.xml'],cwd=output/'disc',check=True)
    if digest(source/'DATA/PACK0.PAK')!=source_pak_hash:
        raise AssertionError('source archive changed')
    report = json.loads((output/'title-patch.json').read_text())
    report.update(source_stage=str(source.resolve()),unchanged_pack0_slots=len(before.slots)-1,
                  preserved_disc_files=len(hashes)-1,
                  image_sha256=digest(output/'disc.bin'),
                  native_default_name='Requires CLI containing f_8001CFD4 Russian initializer')
    for name in ('GRP.GP','PAKVCAST.PAK'):
        report[name] = digest(output/'DATA'/name)
    (output/'integration.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
    print('Verified title-only disc candidate:',output)


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--source',type=Path,required=True)
    parser.add_argument('--stage',type=Path,required=True)
    args=parser.parse_args()
    integrate(args.source,args.stage)
