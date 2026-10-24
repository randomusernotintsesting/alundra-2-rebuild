"""Replace only the two Japanese title choices in an explicitly supplied PAK.

Native slot23 page0, codec2 8bpp. Labels use palette block4: 34 is
transparent, 3 is white and 4..33 descend to near-black. Logo/tagline,
copyright, arrows, every other page and every palette are retained.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct

from PIL import Image, ImageDraw, ImageFont
from a2.pak import PakArchive
from menu_texture_patch import decode_chunk, encode_lz, parse_container, palette_rgb

ROOT = Path(__file__).resolve().parents[1]
FONT = ROOT / 'port/assets/fonts/PT_Serif-Web-Regular.ttf'
LABELS = (('Новая игра', (64, 240, 64, 16)),
          ('Продолжить', (128, 240, 64, 16)))
SOURCE_HASHES = ('c7757235f0f69e86a711139466a0e211715db4f9ceb531f177098f58d8013e21',
                 '12d959c2601c49e3c077dd5569864199c60df8e1fd212eca1dee4b3a7c45ec81')
PALETTE_HASH = 'e3c5b8d3fe835b29be07c66e4aa7775fa67250540c0e386d2c098e767e63fa7d'


def extract(raw, rect):
    x, y, w, h = rect
    return b''.join(raw[row*256+x:row*256+x+w] for row in range(y, y+h))


def build_assets(font_path=FONT, labels=LABELS):
    """Native source indices and 4x outline masks share the original UV area."""
    def word(text, size):
        font = ImageFont.truetype(str(font_path), size, layout_engine=ImageFont.Layout.BASIC)
        x0, y0, x1, y1 = font.getbbox(text)
        image = Image.new('L', (x1-x0+8, y1-y0+8))
        ImageDraw.Draw(image).text((4-x0,4-y0), text, font=font, fill=255)
        return image.crop(image.getbbox())
    ppem = next(size for size in range(64, 7, -1)
                if all((lambda im: im.width<=60*4 and im.height<=14*4)(word(text,size))
                       for text, _ in labels))
    result = []
    for text, rect in labels:
        raster = word(text, ppem)
        alpha = Image.new('L', (256,64))
        alpha.paste(raster, ((256-raster.width)//2,(64-raster.height)//2))
        native = alpha.resize((64,16), Image.Resampling.BOX)
        source = bytes(34 if value < 5 else min(33,3+((255-value)*31+127)//255)
                       for value in native.tobytes())
        result.append(dict(text=text,page=0,uv=list(rect),clut_bank=4,width=64,height=16,
                           ink_index=3,shadow_index=33,source=source,background=bytes([34])*1024,
                           alpha=alpha.tobytes(),ppem=ppem,physical_x_scale=1.0,
                           ink_bbox=list(alpha.getbbox()),palette_slot=23))
    return result


def patch_title_menu(archive, font_path=FONT):
    if len(archive.slots)<=23 or archive.slots[23] is None:
        raise ValueError('missing title slot23')
    data = archive.slots[23]
    w, h, palette, chunks = parse_container(data)
    if (w,h,len(chunks),len(palette)) != (256,256,10,7*512):
        raise ValueError('unknown title layout')
    if any(c['bpp']!=8 for c in chunks) or hashlib.sha256(palette).hexdigest()!=PALETTE_HASH:
        raise ValueError('unknown title palette/depth')
    assets = build_assets(font_path)
    raw = bytearray(chunks[0]['raw'])
    for asset, expected in zip(assets, SOURCE_HASHES):
        old = extract(raw, asset['uv'])
        if old!=asset['source'] and hashlib.sha256(old).hexdigest()!=expected:
            raise ValueError('unknown title choice artwork')
        x,y,rw,rh = asset['uv']
        for row in range(rh):
            raw[(y+row)*w+x:(y+row)*w+x+rw] = asset['source'][row*rw:(row+1)*rw]
    changed = bytes(raw)!=chunks[0]['raw']
    if changed:
        encoded = encode_lz(raw,8)
        if decode_chunk(encoded,w,h)!=raw:
            raise AssertionError('title recompression failed')
        first = chunks[0]
        prefix = bytearray(data[:first['offset']])
        struct.pack_into('<I',prefix,12,len(encoded))
        archive.slots[23] = bytes(prefix)+encoded+data[first['offset']+first['size']:]
    return dict(changed_slots=[23] if changed else [],labels=[p['text'] for p in assets],
                uv_rectangles=[p['uv'] for p in assets],clut_bank=4,
                transparent_index=34,ink_index=3,shadow_index=33,
                ppem=assets[0]['ppem'],physical_x_scale=1.0)


def stage_patch(input_pak, output_dir):
    output_dir = Path(output_dir)
    if output_dir.exists():
        raise FileExistsError(f'refusing existing stage: {output_dir}')
    archive = PakArchive.load(input_pak)
    original = list(archive.slots)
    source_hash = hashlib.sha256(Path(input_pak).read_bytes()).hexdigest()
    report = patch_title_menu(archive)
    output_dir.mkdir(parents=True,exist_ok=False)
    (output_dir/'DATA').mkdir()
    destination = output_dir/'DATA/PACK0.PAK'
    archive.save(destination)
    saved = PakArchive.load(destination)
    for i,(expected,actual) in enumerate(zip(archive.slots,saved.slots)):
        if i!=23:
            if actual!=original[i]: raise AssertionError(f'unrelated slot changed: {i}')
        elif not actual.startswith(expected) or any(actual[len(expected):]):
            raise AssertionError('serialized title changed')
    for tag,data in (('before',original[23]),('after',saved.slots[23])):
        _,_,palette,chunks = parse_container(data)
        image = Image.frombytes('P',(256,256),chunks[0]['raw'])
        image.putpalette(palette_rgb(palette[4*512:5*512]))
        image.crop((64,240,192,256)).resize((768,96),Image.Resampling.NEAREST).save(
            output_dir/f'{tag}_title_choices.png')
    if hashlib.sha256(Path(input_pak).read_bytes()).hexdigest()!=source_hash:
        raise RuntimeError('source changed during title staging')
    report.update(source_sha256=source_hash,
                  staged_sha256=hashlib.sha256(destination.read_bytes()).hexdigest())
    (output_dir/'title-patch.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
    return report


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args()
    print(json.dumps(stage_patch(args.input,args.output),ensure_ascii=False,indent=2))
