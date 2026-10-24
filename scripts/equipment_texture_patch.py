"""Reversible Russian Equipment texture staging; never modifies input archives."""
import argparse
import hashlib
import json
import struct
from pathlib import Path
from a2.pak import PakArchive
from a2.cyrfont import build16, build24, decode_bank, bbox_w
from menu_texture_patch import parse_container, unpack_indices, pack_indices, encode_lz, decode_chunk, palette_rgb

SLOTS=tuple(range(340,347))
REFERENCE_SHA='bcfd8ba16d673db8ae5f20cb35f55f0790c1cfeb9b74141fc7b1778897d81888'
FONT16_SHA='e4a0ee29593a4106c6cf2627d8f2ab13c2666918938ecd70b4b5b7201afcd493'
FONT24_SHA='0c9869a7cf6aa37ea9a274ebf83c59e2b9a468635bd712b4df803d1a751db170'
# text, full original UV rectangle, CLUT bank, protected badge inner rectangle.
LABELS=(('Снаряжение',(120,0,88,32),14,None),
        ('Уровень комбо',(144,32,112,32),14,None),
        ('Уровень стихии',(88,160,128,32),14,None),
        ('ОЗ',(168,64,16,32),4,(1,6,14,22)),
        ('ЭП',(184,64,16,32),5,(1,6,14,22)),
        ('З',(200,64,16,32),6,(4,6,8,20)))

def sha(data): return hashlib.sha256(data).hexdigest()
def extract(pixels,width,rect):
    x,y,w,h=rect
    return b''.join(pixels[r*width+x:r*width+x+w] for r in range(y,y+h))

def glyph_line(text,glyphs,latin,height):
    cells=[]
    for char in text:
        if char == ' ':
            cells.append(([[0]*4 for _ in range(height)],4))
            continue
        px,advance=glyphs[char] if char in glyphs else latin[ord(char)-32]
        cells.append((px,max(advance,bbox_w(px))))
    width=sum(a for _,a in cells); pixels=bytearray(width*height); left=0
    for px,advance in cells:
        for y,row in enumerate(px):
            for x,v in enumerate(row):
                if v:pixels[y*width+left+x]=v
        left+=advance
    return pixels,width,height

def replacement(original,spec,font16,font24):
    text,(_,_,w,h),_,inner=spec
    latin=decode_bank(font24 if inner else font16,24 if inner else 16)
    glyphs=build24(latin) if inner else build16(latin)
    line,tw,th=glyph_line(text,glyphs,latin,24 if inner else 16)
    if inner:
        # Preserve all ink, removing only blank top/bottom rows, no rescale.
        rows=[y for y in range(th) if any(line[y*tw:(y+1)*tw])]
        line=line[rows[0]*tw:(rows[-1]+1)*tw]; th=len(line)//tw
        ix,iy,iw,ih=inner
        allowed={(x,y) for y in range(iy,iy+ih) for x in range(ix,ix+iw)}
        ink={(x,y) for x,y in allowed if original[y*w+x]>=10}
        mask={(x+dx,y+dy) for x,y in ink for dx in (-1,0,1) for dy in (-1,0,1)}&allowed
        candidates=[(x,y) for x,y in sorted(allowed) if (x,y) not in mask and 1<=original[y*w+x]<=9]
        if not ink or not candidates: raise ValueError('unknown badge background')
        out=bytearray(original)
        for x,y in mask:
            bx,by=min(candidates,key=lambda p:(abs(p[0]-x)+abs(p[1]-y),abs(p[1]-y),p[1],p[0]))
            out[y*w+x]=original[by*w+bx]
        left,top=ix+(iw-tw)//2,iy+(ih-th)//2
    else:
        out=bytearray(w*h); iw,ih=w,h;left,top=(w-tw)//2,(h-th)//2
    if tw>iw or th>ih:raise ValueError(f'label {text} does not fit')
    levels=(0,6,11,15)
    for y in range(th):
        for x in range(tw):
            v=line[y*tw+x]
            if v:out[(top+y)*w+left+x]=levels[v]
    return bytes(out)

def patch_equipment(archive,font16,font24,reference):
    for data,want in ((font16,FONT16_SHA),(font24,FONT24_SHA),(reference,REFERENCE_SHA)):
        if sha(data)!=want:raise ValueError('unknown pristine source')
    width,height,palette,chunks=parse_container(reference)
    ref=unpack_indices(chunks[0]['raw'],width,height,4)
    replacements=[]
    for spec in LABELS:
        old=extract(ref,width,spec[1]);replacements.append((old,replacement(old,spec,font16,font24)))
    pending={};cache={}
    for slot in SLOTS:
        if slot>=len(archive.slots) or archive.slots[slot] is None:raise ValueError('missing Equipment copy')
        data=archive.slots[slot]
        if data in cache:pending[slot]=cache[data];continue
        w,h,pal,parts=parse_container(data)
        if (w,h,len(parts))!=(256,224,2) or any(c['bpp']!=4 for c in parts):raise ValueError('unknown Equipment layout')
        if pal!=palette:raise ValueError('unknown Equipment palette')
        pixels=bytearray(unpack_indices(parts[0]['raw'],w,h,4))
        for spec,(old,new) in zip(LABELS,replacements):
            if extract(pixels,w,spec[1]) not in (old,new):raise ValueError('unknown label artwork')
            x,y,rw,rh=spec[1]
            for row in range(rh):pixels[(y+row)*w+x:(y+row)*w+x+rw]=new[row*rw:(row+1)*rw]
        raw=pack_indices(pixels,w,h,4)
        encoded=parts[0]['compressed'] if raw==parts[0]['raw'] else encode_lz(raw)
        if decode_chunk(encoded,w,h)!=raw:raise AssertionError('chunk roundtrip')
        header=bytearray(data[:parts[0]['offset']]);struct.pack_into('<I',header,12,len(encoded))
        result=bytes(header)+encoded+data[parts[1]['offset']:]
        cache[data]=pending[slot]=result
    changed=[]
    for slot,data in pending.items():
        if archive.slots[slot]!=data:archive.slots[slot]=data;changed.append(slot)
    return {'changed_slots':changed,'labels':[x[0] for x in LABELS],'boundaries':LABELS}

def stage(input_pak,reference_pak,output):
    input_pak,reference_pak,output=map(Path,(input_pak,reference_pak,output))
    if output.exists():raise FileExistsError('stage already exists')
    before=sha(input_pak.read_bytes());refhash=sha(reference_pak.read_bytes())
    archive=PakArchive.load(input_pak);reference=PakArchive.load(reference_pak);old=archive.slots[340]
    report=patch_equipment(archive,reference.slots[548],reference.slots[545],reference.slots[340])
    output.mkdir(parents=True,exist_ok=False);(output/'DATA').mkdir()
    archive.save(output/'DATA/PACK0.PAK')
    saved=PakArchive.load(output/'DATA/PACK0.PAK')
    if len(saved.slots)!=len(archive.slots):raise AssertionError('slot count changed')
    for a,b in zip(archive.slots,saved.slots):
        if a is None:
            if b is not None:raise AssertionError('empty slot changed')
        elif b is None or not b.startswith(a) or any(b[len(a):]):raise AssertionError('saved slot differs')
    from PIL import Image
    for tag,data in (('before',old),('after',saved.slots[340])):
        w,h,pal,parts=parse_container(data);sheet=Image.new('RGB',(128,32*len(LABELS)))
        px=unpack_indices(parts[0]['raw'],w,h,4)
        for n,spec in enumerate(LABELS):
            _,rect,clut,_=spec;x,y,rw,rh=rect
            image=Image.frombytes('P',(rw,rh),extract(px,w,rect))
            image.putpalette(palette_rgb(pal[clut*32:(clut+1)*32])+[0]*720)
            sheet.paste(image.convert('RGB'),((128-rw)//2,n*32))
        sheet.resize((512,128*len(LABELS)),Image.Resampling.NEAREST).save(output/f'{tag}_labels_4x.png')
        for n,c in enumerate(parts):
            (output/f'{tag}_chunk{n}.raw').write_bytes(c['raw'])
            (output/f'{tag}_chunk{n}.chunk').write_bytes(c['compressed'])
    if sha(input_pak.read_bytes())!=before or sha(reference_pak.read_bytes())!=refhash:raise RuntimeError('input changed during staging')
    report.update(source_sha=before,reference_sha=refhash,staged_sha=sha((output/'DATA/PACK0.PAK').read_bytes()))
    (output/'report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
    return report

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--input-pak',required=True);p.add_argument('--reference-pak',required=True);p.add_argument('--output',required=True)
    args=p.parse_args();print(json.dumps(stage(args.input_pak,args.reference_pak,args.output),ensure_ascii=False,indent=2))
