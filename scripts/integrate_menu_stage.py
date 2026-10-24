"""Build the bounded full-menu-v3 candidate from the verified v2 corpus.

Only new output artifacts; no application, source disc or existing stage writes.
"""
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
from a2.pak import PakArchive
from pocket_texture_patch import patch_pocket_menu, SLOTS as POCKET
from settings_texture_patch import patch_settings_menu, SLOTS as SETTINGS
from equipment_texture_patch import patch_equipment, SLOTS as EQUIPMENT
from keyconfig_texture_patch import patch_keyconfig, SLOTS as KEYS

ROOT=Path(__file__).resolve().parents[1]
def digest(path): return hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    source=ROOT/'port/build/verification/full-russian-menu-v2'
    core=ROOT/'port/build/localization-full-menu-v2/DATA'
    out=ROOT/'port/build/verification/full-menu-v3'
    if (out/'DATA').exists() or (out/'disc').exists():raise FileExistsError('candidate data already exists')
    if not (out/'alundra2').is_file():raise ValueError('freeze CLI before integrating')
    original=source/'DATA/PACK0.PAK'; reference=ROOT/'disc.orig/DATA/PACK0.PAK'
    source_hash=digest(original); ref_hash=digest(reference)
    arc=PakArchive.load(original);before=list(arc.slots);ref=PakArchive.load(reference)
    reports={
        'pocket':patch_pocket_menu(arc,ref.slots[548],ref.slots[298]),
        'settings':patch_settings_menu(arc,ref.slots[548],ref.slots[333]),
        'equipment':patch_equipment(arc,ref.slots[548],ref.slots[545],ref.slots[340]),
        'keyconfig':patch_keyconfig(arc,ref.slots[548],ref.slots[347]),
    }
    allowed=set(POCKET)|set(SETTINGS)|set(EQUIPMENT)|set(KEYS)
    for i,(old,new) in enumerate(zip(before,arc.slots)):
        if i not in allowed and old!=new:raise AssertionError(f'non-menu slot changed: {i}')
    (out/'DATA').mkdir()
    arc.save(out/'DATA/PACK0.PAK')
    saved=PakArchive.load(out/'DATA/PACK0.PAK')
    if len(saved.slots)!=len(arc.slots):raise AssertionError('slot count changed')
    for i,(want,got) in enumerate(zip(arc.slots,saved.slots)):
        if want is None:
            if got is not None:raise AssertionError(f'empty slot changed: {i}')
        elif got is None or not got.startswith(want) or any(got[len(want):]):raise AssertionError(f'serialized slot changed: {i}')
    for name in ('GRP.GP','PAKVCAST.PAK'):shutil.copy2(core/name,out/'DATA'/name)
    # APFS copy-on-write clone, never hardlinks: subsequent candidate writes
    # cannot alter the previously verified extracted disc.
    subprocess.run(['cp','-cR',str(source/'disc'),str(out/'disc')],check=True)
    for name in ('PACK0.PAK','GRP.GP','PAKVCAST.PAK'):shutil.copy2(out/'DATA'/name,out/'disc/DATA'/name)
    subprocess.run([str(ROOT/'tools/mkpsxiso-src/build/mkpsxiso'),'-y','-o',str(out/'disc.bin'),'-c',str(out/'disc.cue'),'disc.xml'],cwd=out/'disc',check=True)
    if digest(original)!=source_hash or digest(reference)!=ref_hash:raise RuntimeError('source changed during integration')
    manifest={'source_pack0_sha256':source_hash,'reference_sha256':ref_hash,
              'binary_sha256':digest(out/'alundra2'),'disc_image_sha256':digest(out/'disc.bin'),
              'pack0_sha256':digest(out/'DATA/PACK0.PAK'),'unchanged_nonmenu_slots':len(before)-len(allowed),'patches':reports}
    for name in ('GRP.GP','PAKVCAST.PAK'):
        assert digest(out/'DATA'/name)==digest(core/name)
        manifest[name]=digest(out/'DATA'/name)
    (out/'integration.json').write_text(json.dumps(manifest,ensure_ascii=False,indent=2)+'\n')
    print('Integrated candidate:',out)

if __name__=='__main__':main()
