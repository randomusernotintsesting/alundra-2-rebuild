"""Translate the original Japanese credits on their original native pages.

Only PACK0 texture slots25..28 change. The 37 text pages retain every original
row's vertical anchor; the ending illustration, two blank pages, palettes,
page count, and unrelated archive entries are byte-preserved. JP is rejected
as a target language. No engine, UV, or scrolling changes are needed.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import shutil
import subprocess

from PIL import Image, ImageDraw, ImageFont
from a2.pak import PakArchive
from menu_texture_patch import decode_chunk, encode_lz, pack_indices, parse_container, unpack_indices
from export_portraits import decode_rgba

ROOT = Path(__file__).resolve().parents[1]
FONT = ROOT / 'port/assets/fonts/PT_Serif-Web-Regular.ttf'
MANIFEST = json.loads((ROOT / 'scripts/data/credits-localization.json').read_text())
CREDITS = {(p['slot'], p['page']): p['rows'] for p in MANIFEST['pages']}
SLOTS = (25, 26, 27, 28)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def render_page(rows, language, font_path=FONT):
    """Fit actual glyph ink to each original line band; never stretch text."""
    alpha = Image.new('L', (256 * 4, 256 * 4))
    records = []
    for row in rows:
        text = row[language]
        if not text:
            raise ValueError('empty credit translation')
        if language == 'en':
            text.encode('ascii')
        top, bottom = row['band']
        # Name/role sizes follow the original line height. Supersampling makes
        # the native 4bpp glyph edge clean while preserving the source CLUT.
        for ppem in range(64, 23, -1):
            font = ImageFont.truetype(str(font_path), ppem, layout_engine=ImageFont.Layout.BASIC)
            x0, y0, x1, y1 = font.getbbox(text)
            if x1-x0 <= 240*4 and y1-y0 <= (bottom-top)*4:
                break
        else:
            raise ValueError(f'credit does not fit source row: {text}')
        x = (256*4-(x1-x0))//2
        y = top*4+((bottom-top)*4-(y1-y0))//2
        ImageDraw.Draw(alpha).text((x-x0,y-y0), text, font=font, fill=255)
        records.append(dict(original=row['jp'],text=text,source_band=[top,bottom],
                            ppem=ppem/4,ink_bbox=[x//4,y//4,(x+x1-x0+3)//4,(y+y1-y0+3)//4]))
    native = alpha.resize((256,256), Image.Resampling.BOX)
    # Source index0 is background; indices1..15 run from blue to white.
    indices = bytes(0 if a < 8 else max(1,min(15,(a*15+127)//255)) for a in native.tobytes())
    return pack_indices(indices,256,256,4), records


def patch_credits(archive, language, font_path=FONT):
    if language not in ('ru','en'):
        raise ValueError('credits target must be ru or en; Japanese remains original')
    prepared = {}
    pages = []
    # Validate and prepare every slot before making any archive mutation.
    for slot in SLOTS:
        if slot >= len(archive.slots) or archive.slots[slot] is None:
            raise ValueError(f'missing credits slot{slot}')
        data = archive.slots[slot]
        w,h,palette,chunks = parse_container(data)
        reference = MANIFEST['slots'][str(slot)]
        if (w,h,len(palette),len(chunks)) != (256,256,512,10) or any(c['bpp'] != 4 for c in chunks):
            raise ValueError(f'unknown credits layout slot{slot}')
        if digest(palette) != reference['palette_sha256']:
            raise ValueError(f'unknown credits palette slot{slot}')
        encoded = []
        changed = False
        for page, chunk in enumerate(chunks):
            rows = CREDITS.get((slot,page))
            if rows is None:
                if digest(chunk['raw']) != reference['raw_sha256'][page]:
                    raise ValueError(f'unknown ending artwork slot{slot} page{page}')
                encoded.append(chunk['compressed'])
                continue
            raw, records = render_page(rows,language,font_path)
            if chunk['raw'] != raw and digest(chunk['raw']) != reference['raw_sha256'][page]:
                raise ValueError(f'unknown credits artwork slot{slot} page{page}')
            pages.append(dict(slot=slot,page=page,rows=records,raw_sha256=digest(raw)))
            if chunk['raw'] == raw:
                encoded.append(chunk['compressed'])
            else:
                compressed = encode_lz(raw,4)
                if decode_chunk(compressed,w,h) != raw:
                    raise AssertionError('credits recompression failed')
                encoded.append(compressed)
                changed = True
        if changed:
            prefix = bytearray(data[:chunks[0]['offset']])
            struct.pack_into('<10I',prefix,12,*map(len,encoded))
            tail = data[chunks[-1]['offset']+chunks[-1]['size']:]
            prepared[slot] = bytes(prefix)+b''.join(encoded)+tail
    for slot,data in prepared.items():
        archive.slots[slot] = data
    return dict(language=language,changed_slots=list(prepared),pages=pages,
                text_pages=37,preserved_ending_pages=3,credit_rows=sum(map(len,CREDITS.values())),
                manifest_sha256=digest((ROOT/'scripts/data/credits-localization.json').read_bytes()),
                font_sha256=digest(Path(font_path).read_bytes()))


def stage_patch(input_pak, output_dir, language):
    input_pak, output_dir = Path(input_pak), Path(output_dir)
    if output_dir.exists():
        raise FileExistsError(f'refusing existing stage: {output_dir}')
    source_hash = digest(input_pak.read_bytes())
    archive = PakArchive.load(input_pak)
    original = list(archive.slots)
    report = patch_credits(archive,language)
    (output_dir/'DATA').mkdir(parents=True,exist_ok=False)
    output_pak = output_dir/'DATA/PACK0.PAK'
    archive.save(output_pak)
    saved = PakArchive.load(output_pak)
    for index,(expected,actual) in enumerate(zip(archive.slots,saved.slots)):
        if index not in SLOTS:
            if original[index] != actual:
                raise AssertionError(f'unrelated slot changed: {index}')
        elif not actual.startswith(expected) or any(actual[len(expected):]):
            raise AssertionError(f'serialized credits changed: {index}')
    for slot in SLOTS:
        w,h,palette,chunks = parse_container(saved.slots[slot])
        contact = Image.new('RGB',(5*256,2*276),(24,24,24))
        for page,c in enumerate(chunks):
            indices = unpack_indices(c['raw'],w,h,4)
            image = Image.frombytes('RGBA',(w,h),decode_rgba(indices,palette[:32]))
            x,y = (page%5)*256,(page//5)*276
            contact.paste(image.convert('RGB'),(x,y+20))
            ImageDraw.Draw(contact).text((x+4,y+3),f'{language} {slot}/{page}',fill='white')
        contact.save(output_dir/f'{language}-slot{slot}.png')
    if digest(input_pak.read_bytes()) != source_hash:
        raise AssertionError('source archive changed during credits staging')
    report.update(source_sha256=source_hash,staged_sha256=digest(output_pak.read_bytes()))
    (output_dir/'credits-patch.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
    return report


def integrate_stage(source_stage, output_dir):
    """Clone an owned RU candidate and rebuild its coherent image, in isolation."""
    source_stage, output_dir = Path(source_stage), Path(output_dir)
    if (output_dir/'disc').exists() or (output_dir/'disc.bin').exists():
        raise FileExistsError('refusing existing integrated credits disc')
    report = json.loads((output_dir/'credits-patch.json').read_text())
    source_pak = source_stage/'DATA/PACK0.PAK'
    if digest(source_pak.read_bytes()) != report['source_sha256']:
        raise ValueError('credits input differs from source stage')
    original = PakArchive.load(source_pak)
    changed = PakArchive.load(output_dir/'DATA/PACK0.PAK')
    if len(original.slots) != len(changed.slots) or any(
            before != after for i,(before,after) in enumerate(zip(original.slots,changed.slots)) if i not in SLOTS):
        raise ValueError('staged archive changes unrelated slots')
    source_disc = source_stage/'disc'
    if digest((source_disc/'DATA/PACK0.PAK').read_bytes()) != report['source_sha256']:
        raise ValueError('source disc and archive are incoherent')
    hashes = {str(p.relative_to(source_disc)):digest(p.read_bytes())
              for p in source_disc.rglob('*') if p.is_file()}
    subprocess.run(['cp','-cR',str(source_disc),str(output_dir/'disc')],check=True)
    shutil.copy2(output_dir/'DATA/PACK0.PAK',output_dir/'disc/DATA/PACK0.PAK')
    for name in ('GRP.GP','PAKVCAST.PAK'):
        shutil.copy2(source_disc/'DATA'/name,output_dir/'DATA'/name)
    for name,expected in hashes.items():
        if digest((source_disc/name).read_bytes()) != expected:
            raise AssertionError(f'source disc changed: {name}')
        if name != 'DATA/PACK0.PAK' and digest((output_dir/'disc'/name).read_bytes()) != expected:
            raise AssertionError(f'non-credits disc file changed: {name}')
    subprocess.run([str(ROOT/'tools/mkpsxiso-src/build/mkpsxiso'),'-y',
                    '-o',str((output_dir/'disc.bin').resolve()),
                    '-c',str((output_dir/'disc.cue').resolve()),'disc.xml'],
                   cwd=output_dir/'disc',check=True)
    report.update(source_stage=str(source_stage.resolve()),preserved_disc_files=len(hashes)-1,
                  image_sha256=digest((output_dir/'disc.bin').read_bytes()))
    (output_dir/'integration.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
    return report


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--language',choices=('ru','en'),required=True)
    parser.add_argument('--source-stage',type=Path,help='optional coherent RU stage to clone and rebuild')
    args = parser.parse_args()
    result = stage_patch(args.input,args.output,args.language)
    if args.source_stage:
        result = integrate_stage(args.source_stage,args.output)
    print(json.dumps({k:v for k,v in result.items() if k != 'pages'},ensure_ascii=False,indent=2))
