"""Decode known native HUD/menu regions for design review, without editing them."""
import argparse
import json
from pathlib import Path
import struct
from PIL import Image
from a2.pak import PakArchive
from menu_texture_patch import parse_container, unpack_indices
from export_portraits import decode_rgba

ROOT = Path(__file__).resolve().parents[1]
REGIONS = (
    ('hud_health_frame',29,0,(0,0,56,36),0),
    ('hud_right_frame',29,0,(56,0,48,72),0),
    ('hud_item_glass',29,0,(56,72,32,32),1),
    ('hud_digits_small',29,0,(0,112,66,8),7),
    ('hud_digits_large',29,0,(0,120,88,8),7),
    ('hud_health_state',29,1,(0,0,56,36),0),
    ('herb',302,0,(128,192,32,32),52),
    ('settings_title',333,0,(0,0,184,24),5),
    ('settings_left',333,0,(0,24,114,24),0),
    ('settings_right',333,0,(0,48,136,24),4),
    ('settings_slider',333,0,(0,72,136,24),2),
    ('pocket_tab',298,0,(0,0,72,24),0),
    ('pocket_panel',298,1,(0,56,136,128),12),
    ('pocket_name',298,1,(0,0,168,32),3),
    ('equipment_panel',340,0,(0,64,168,96),2),
    ('key_header',347,0,(0,0,180,24),0),
    ('key_label',347,0,(0,48,72,24),0),
)

def decode_region(archive, slot, page, rect, bank):
    w,h,palette,chunks = parse_container(archive.slots[slot])
    bpp = chunks[page]['bpp']
    full = unpack_indices(chunks[page]['raw'],w,h,bpp)
    x,y,rw,rh = rect
    if not (0 <= x < x+rw <= w and 0 <= y < y+rh <= h):
        raise ValueError('region outside atlas')
    source = bytes(full[(y+j)*w+x+i] for j in range(rh) for i in range(rw))
    pal = palette[bank*32:bank*32+(1<<bpp)*2]
    return source, pal, bpp

def export(pak, output):
    archive = PakArchive.load(pak)
    output.mkdir(parents=True,exist_ok=False)
    records=[]
    for name,slot,page,rect,bank in REGIONS:
        source,pal,bpp = decode_region(archive,slot,page,rect,bank)
        im=Image.frombytes('RGBA',tuple(rect[2:]),decode_rgba(source,pal))
        im.save(output/(name+'.png'))
        records.append(dict(name=name,slot=slot,page=page,rect=rect,bank=bank,bpp=bpp,
                            indices=sorted(set(source)),palette=[f'{v:04x}' for v, in struct.iter_unpack('<H',pal)]))
    (output/'manifest.json').write_text(json.dumps(records,indent=2)+'\n')

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--pak',type=Path,default=ROOT/'port/build/verification/full-menu-v6/DATA/PACK0.PAK')
    p.add_argument('--output',type=Path,required=True)
    a=p.parse_args();export(a.pak,a.output)
