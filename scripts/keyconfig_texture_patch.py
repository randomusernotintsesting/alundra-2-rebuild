"""Localize existing key-configuration plates; stage only, never edit a disc."""
import argparse
import hashlib
import json
import struct
from pathlib import Path
from a2.cyrfont import build16, decode_bank, bbox_w
from a2.pak import PakArchive
from menu_texture_patch import (parse_container, unpack_indices, pack_indices,
                                encode_lz, decode_chunk, palette_rgb)

SLOTS = (347,349,351,353,355,357,359)
REFERENCE_HASH = 'd21b9dcdcfcee5e17adda3d228d0f2c1ffdb09b6aed16f88c3fc11cc00f9f03e'
FONT_HASH = 'e4a0ee29593a4106c6cf2627d8f2ab13c2666918938ecd70b4b5b7201afcd493'
LABELS = [('Управление',(0,0,180,24)),('Своя схема',(0,24,180,24))]
LABELS += [(text,(x,48+24*i,72,24)) for x,texts in (
    (0,('Вправо','Влево','Предмет','Ракурс','Действие','Карманы','Бег')),
    (72,('Атака','Прыжок','Схема 1','Схема 2','Схема 3','Своя','Выход')))
    for i,text in enumerate(texts)]

def sha(data): return hashlib.sha256(data).hexdigest()

def extract(pixels, rect):
    x,y,w,h=rect
    return b''.join(pixels[r*256+x:r*256+x+w] for r in range(y,y+h))

def render(original,text,width,font):
    latin=decode_bank(font,16);glyphs=build16(latin)
    out=bytearray(original)
    left,right=(10,width-10) if width==180 else (3,width-3)
    allowed={(x,y) for y in range(5 if width==180 else 4,20) for x in range(left,right)}
    ink={(x,y) for x,y in allowed if original[y*width+x] in (0,3,4,5,6,7)}
    mask={(x+dx,y+dy) for x,y in ink for dx in (-1,0,1) for dy in (-1,0,1)} & allowed
    # Gold/brown bevel indices 11..14 and transparency15 are never repainted.
    mask={p for p in mask if original[p[1]*width+p[0]]<11}
    background=[p for p in allowed-mask if original[p[1]*width+p[0]] in (1,2,8,9,10)]
    if not ink or not background: raise ValueError('unknown lettering/background')
    for x,y in mask:
        # The plate texture is a horizontal repeating pattern. Preserve its
        # scanline and two-column phase instead of smearing nearby dark rows.
        bx,by=min(background,key=lambda p:(abs(p[1]-y),(p[0]-x)%2,abs(p[0]-x),p[0]))
        out[y*width+x]=original[by*width+bx]
    cells=[]
    for c in text:
        if c==' ':cells.append(([[0]*12 for _ in range(16)],4));continue
        pixels,advance=glyphs[c] if c in glyphs else latin[ord(c)-32]
        cells.append((pixels,max(advance,bbox_w(pixels))))
    tw=sum(w for _,w in cells)
    if tw>right-left:raise ValueError(f'{text} exceeds native plate interior')
    x=(width-tw)//2
    omitted=[]
    for pixels,advance in cells:
        for y,row in enumerate(pixels):
            for dx,v in enumerate(row):
                if not v:continue
                p=(x+dx,y+4)
                if p not in allowed or original[p[1]*width+p[0]]>=11:
                    # Explicitly reviewed faint р tail only; never general
                    # clipping, never body level3, never repaint the bevel.
                    if text=='Управление' and (p[0],p[1],v) in ((71,19,2),(72,19,1)):
                        omitted.append([p[0],p[1],v])
                        continue
                    raise ValueError(f'{text} overlaps original bevel at {p}: {original[p[1]*width+p[0]]}')
                out[p[1]*width+p[0]]=(0,5,4,0)[v]
        x+=advance
    return bytes(out),tw,omitted

def patch_keyconfig(archive,font,reference):
    if sha(font)!=FONT_HASH or sha(reference)!=REFERENCE_HASH:
        raise ValueError('unknown reference/font source')
    w,h,pal,chunks=parse_container(reference)
    pixels=unpack_indices(chunks[0]['raw'],w,h,4)
    replacements=[];omitted=[]
    for text,rect in LABELS:
        old=extract(pixels,rect);new,tw,skipped=render(old,text,rect[2],font)
        omitted.extend(skipped)
        replacements.append((old,new,tw))
    pending={};cache={}
    for slot in SLOTS:
        if slot>=len(archive.slots) or archive.slots[slot] is None:raise ValueError('missing keyconfig copy')
        data=archive.slots[slot]
        if data in cache:pending[slot]=cache[data];continue
        dw,dh,dp,dc=parse_container(data)
        if (dw,dh,len(dc))!=(256,224,1) or dp!=pal or dc[0]['bpp']!=4:
            raise ValueError('unknown layout/palette')
        out=bytearray(unpack_indices(dc[0]['raw'],w,h,4))
        for (_,rect),(old,new,_) in zip(LABELS,replacements):
            if extract(out,rect) not in (old,new):raise ValueError('unknown label artwork')
            x,y,rw,rh=rect
            for r in range(rh):out[(y+r)*w+x:(y+r)*w+x+rw]=new[r*rw:(r+1)*rw]
        raw=pack_indices(out,w,h,4)
        if raw==dc[0]['raw']:result=data
        else:
            enc=encode_lz(raw)
            if decode_chunk(enc,w,h)!=raw:raise AssertionError('codec roundtrip')
            header=bytearray(data[:dc[0]['offset']]);struct.pack_into('<I',header,12,len(enc))
            result=bytes(header)+enc+data[dc[0]['offset']+dc[0]['size']:]
        cache[data]=pending[slot]=result
    changed=[s for s in SLOTS if archive.slots[s]!=pending[s]]
    for s in SLOTS:archive.slots[s]=pending[s]
    return {'changed_slots':changed,'labels':[{'text':t,'uv':r,'width':v[2]} for (t,r),v in zip(LABELS,replacements)],
            'clut_banks':[0,1], 'untouched_controller_slot':348,
            'omitted_shadow_pixels':omitted,
            'unused_us_legend_art':'preserved; pristine JP area is empty; no observed native draw'}

def stage_patch(input_pak,reference_pak,font_pak,output):
    output=Path(output)
    if output.exists():raise FileExistsError('refusing to overwrite existing stage')
    arc=PakArchive.load(input_pak);ref=PakArchive.load(reference_pak);fonts=PakArchive.load(font_pak)
    before=arc.slots[347];report=patch_keyconfig(arc,fonts.slots[548],ref.slots[347])
    output.mkdir(parents=True);(output/'DATA').mkdir();arc.save(output/'DATA/PACK0.PAK')
    saved=PakArchive.load(output/'DATA/PACK0.PAK')
    for wanted,actual in zip(arc.slots,saved.slots):
        if wanted is None:
            if actual is not None:raise AssertionError('empty slot changed')
        elif not actual.startswith(wanted) or any(actual[len(wanted):]):raise AssertionError('serialization changed slot')
    from PIL import Image
    for tag,data in [('before',before),('after',saved.slots[347])]:
        w,h,pal,c=parse_container(data)
        im=Image.frombytes('P',(w,h),unpack_indices(c[0]['raw'],w,h,4))
        im.putpalette(palette_rgb(pal[:32])+[0]*720)
        im.resize((768,672),Image.Resampling.NEAREST).save(output/(tag+'.png'))
        (output/(tag+'.chunk')).write_bytes(c[0]['compressed'])
        (output/(tag+'.raw')).write_bytes(c[0]['raw'])
    report['source_sha256']=sha(Path(input_pak).read_bytes())
    (output/'report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
    return report

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    for name in ['input','reference','font','output']:p.add_argument('--'+name,type=Path,required=True)
    a=p.parse_args();print(json.dumps(stage_patch(a.input,a.reference,a.font,a.output),ensure_ascii=False,indent=2))
