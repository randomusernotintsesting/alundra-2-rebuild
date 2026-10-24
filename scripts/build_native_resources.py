"""Build immutable A2RES001 resources from exact logical files, never an ISO.

PAK entry, GRP prefix/text and VCAST section boundaries keep common payloads
aligned despite translation growth. Unique chunks are spooled compressed on
disk: neither the whole input tree nor the output payload is held in memory.
"""
import argparse
from collections import namedtuple
import hashlib
import json
import math
import os
from pathlib import Path
import shutil
import struct
import tempfile
import zlib

from a2.grp import Group, HEADER_SIZE, TOC_ENTRIES

Source=namedtuple('Source','language name path')
HEADER=struct.Struct('<8s6I4Q')
FILE=struct.Struct('<64sIIQIIQ')
SPAN=struct.Struct('<Q4I')
CHUNK=struct.Struct('<Q4I')
MAX_CHUNK=65536
MAX_INDEX=64*1024*1024
RUNTIME_FILES=('SCPS_101.15','SYSTEM.CNF','GAME00.BIN','GAME01.BIN',
               'GAME02.BIN','GAME03.BIN','EVENT00.BIN','DATA/PACK0.PAK',
               'DATA/PACK1.PAK','DATA/PAKOMAKE.PAK','DATA/PAKVCAST.PAK','DATA/GRP.GP')


def canonical_name(name):
    if not isinstance(name,str):raise ValueError('resource name must be text')
    try:raw=name.encode('ascii')
    except UnicodeEncodeError as e:raise ValueError('resource name must be ASCII') from e
    if not raw or len(raw)>63 or any(c<32 or c>126 for c in raw) or '\\' in name or ':' in name:
        raise ValueError(f'invalid canonical resource name: {name!r}')
    if any(part in ('','.','..') for part in name.split('/')):
        raise ValueError(f'invalid resource path component: {name!r}')
    return raw


def read_at(file,offset,length):
    file.seek(offset);data=file.read(length)
    if len(data)!=length:raise ValueError('source truncated during resource build')
    return data


def pak_entries(file,base,end,strict=True):
    """Read only the existing a2.pak/a2.vcast offset-table convention."""
    def bad():
        if strict:raise ValueError(f'invalid PAK table at {base}')
        return None
    if end-base<4:return bad()
    first=struct.unpack('<I',read_at(file,base,4))[0]
    if first<4 or first%4 or first>end-base or first>MAX_INDEX:return bad()
    offsets=struct.unpack('<%dI'%(first//4),read_at(file,base,first))
    nz=[(i,o) for i,o in enumerate(offsets) if o]
    if not nz or nz[0][1]!=first:return bad()
    if any(o%4 or o>end-base or (j and o<=nz[j-1][1]) for j,(i,o) in enumerate(nz)):return bad()
    return [(i,base+o,base+(nz[k+1][1] if k+1<len(nz) else end-base)) for k,(i,o) in enumerate(nz)]


def semantic_boundaries(source,file,size):
    boundaries={0,size};name=source.name.upper()
    if name.startswith(('NAMES/JA/','NAMES/EN/')):name=name.split('/',2)[2]
    if name.endswith('.PAK'):
        entries=pak_entries(file,0,size)
        for _,start,end in entries:
            boundaries.update((start,end))
            if name=='DATA/PAKVCAST.PAK':
                nested=pak_entries(file,start,end,strict=False)
                if nested:
                    for _,a,b in nested:boundaries.update((a,b))
    elif name=='DATA/GRP.GP':
        if size<TOC_ENTRIES*4:raise ValueError('truncated GRP table')
        toc=struct.unpack('<%dI'%TOC_ENTRIES,read_at(file,0,TOC_ENTRIES*4))
        offsets=sorted(set(toc));boundaries.add(TOC_ENTRIES*4)
        if not offsets or offsets[0]<TOC_ENTRIES*4 or offsets[-1]>size-HEADER_SIZE:
            raise ValueError('invalid GRP offsets')
        for i,start in enumerate(offsets):
            end=offsets[i+1] if i+1<len(offsets) else size
            if end-start<HEADER_SIZE:raise ValueError('truncated GRP group')
            group=Group(i,start,read_at(file,start,HEADER_SIZE))
            text_offset,text_size=group.subs()[12]
            boundaries.update((start,start+HEADER_SIZE,end))
            if text_offset or text_size:
                payload=start+text_offset+0x104
                if payload<start+HEADER_SIZE or payload+text_size!=end:
                    raise ValueError('invalid GRP text boundary')
                boundaries.add(payload)
    return sorted(boundaries)


def source_ranges(source):
    path=Path(source.path);size=path.stat().st_size
    unit=2304*23 if source.name.startswith('VOICE/') and source.name.endswith('.adpcm') else MAX_CHUNK
    if unit!=MAX_CHUNK and size%2304:raise ValueError('incomplete voice ADPCM block')
    with path.open('rb') as file:
        boundaries=semantic_boundaries(source,file,size)
    for start,end in zip(boundaries,boundaries[1:]):
        while start<end:
            length=min(unit,end-start);yield start,length;start+=length


def _raw_chunk(spool,chunk):
    offset,stored,raw,crc,codec=chunk
    encoded=read_at(spool,offset,stored)
    data=zlib.decompress(encoded) if codec else encoded
    if len(data)!=raw or zlib.crc32(data)!=crc:raise ValueError('temporary chunk damaged')
    return data


def build_archive(sources,output,profile_mask=7):
    output=Path(output)
    if output.exists():raise FileExistsError(output)
    if not isinstance(profile_mask,int) or not 1<=profile_mask<=7:raise ValueError('invalid profile mask')
    sources=sorted(sources,key=lambda s:(s.name,s.language));seen=set()
    for s in sources:
        canonical_name(s.name)
        if not isinstance(s.language,int) or s.language not in range(4):raise ValueError('invalid source language')
        if s.language<3 and not profile_mask&(1<<s.language):raise ValueError('source outside profile mask')
        if (s.language,s.name) in seen:raise ValueError('duplicate resource language/name')
        seen.add((s.language,s.name))
        if not Path(s.path).is_file():raise ValueError(f'missing source {s.path}')
    output.parent.mkdir(parents=True,exist_ok=True)
    chunks=[];spans=[];files=[];hash_index={};logical=0;unique=0;payload_size=0
    with tempfile.TemporaryFile(dir=output.parent) as spool:
        for source in sources:
            path=Path(source.path);before=path.stat();first=len(spans);position=0
            with path.open('rb') as file:
                for offset,length in source_ranges(source):
                    if offset!=position:raise ValueError('source segmentation gap')
                    raw=read_at(file,offset,length);key=hashlib.sha256(raw).digest();chunk_id=None
                    for candidate in hash_index.get(key,[]):
                        if chunks[candidate][2]==length and _raw_chunk(spool,chunks[candidate])==raw:
                            chunk_id=candidate;break
                    if chunk_id is None:
                        compressed=zlib.compress(raw,6);codec=int(len(compressed)<len(raw))
                        encoded=compressed if codec else raw
                        chunk_id=len(chunks);chunks.append((payload_size,len(encoded),len(raw),zlib.crc32(raw),codec))
                        spool.seek(payload_size);spool.write(encoded);payload_size+=len(encoded);unique+=length
                        hash_index.setdefault(key,[]).append(chunk_id)
                    spans.append((offset,chunk_id,0,length,0));position+=length
            after=path.stat()
            if (before.st_size,before.st_mtime_ns,before.st_ino)!=(after.st_size,after.st_mtime_ns,after.st_ino) or position!=before.st_size:
                raise ValueError(f'source changed during build: {path}')
            files.append((canonical_name(source.name),source.language,0,position,first,len(spans)-first,0));logical+=position
        so=64+len(files)*96;co=so+len(spans)*24;data_offset=co+len(chunks)*24
        if data_offset-64>MAX_INDEX:raise ValueError('resource index exceeds reader bound')
        table=b''.join(FILE.pack(*f) for f in files)+b''.join(SPAN.pack(*s) for s in spans)
        table+=b''.join(CHUNK.pack(data_offset+o,stored,raw,crc,codec) for o,stored,raw,crc,codec in chunks)
        header=HEADER.pack(b'A2RES001',1,profile_mask,len(files),len(spans),len(chunks),zlib.crc32(table),64,so,co,data_offset)
        temporary=None
        try:
            with tempfile.NamedTemporaryFile(dir=output.parent,prefix=output.name+'.',suffix='.tmp',delete=False) as dst:
                temporary=Path(dst.name);dst.write(header);dst.write(table);spool.seek(0)
                shutil.copyfileobj(spool,dst,1024*1024);dst.flush();os.fsync(dst.fileno())
            # Atomic no-replace publication: another builder cannot be overwritten.
            os.link(temporary,output)
        finally:
            if temporary is not None:temporary.unlink(missing_ok=True)
    return dict(format='A2RES001',file_count=len(files),span_count=len(spans),chunk_count=len(chunks),
                logical_bytes=logical,unique_raw_bytes=unique,shared_bytes=logical-unique,
                stored_payload_bytes=payload_size,index_bytes=data_offset,
                archive_bytes=data_offset+payload_size)


def verify_archive(archive,sources):
    """Independent streaming reconstruction against every provided source file.

    C acceptance additionally uses test_resources extract, so this reader is
    an equality oracle rather than a substitute for runtime validation.
    """
    total=0;verified=0
    with Path(archive).open('rb') as file:
        h=HEADER.unpack(read_at(file,0,64));magic,version,mask,nf,ns,nc,crc,fo,so,co,do=h
        if magic!=b'A2RES001' or version!=1 or fo!=64 or so!=fo+96*nf or co!=so+24*ns or do!=co+24*nc or do-64>MAX_INDEX:
            raise ValueError('invalid archive index')
        table=read_at(file,64,do-64)
        if zlib.crc32(table)!=crc:raise ValueError('invalid archive index CRC')
        records={}
        for i in range(nf):
            n,lang,flags,size,first,count,reserved=FILE.unpack_from(table,i*96)
            records[lang,n.split(b'\0',1)[0].decode('ascii')]=(size,first,count)
        for source in sources:
            size,first,count=records.get((source.language,source.name),records.get((3,source.name),(None,None,None)))
            if size is None or size!=Path(source.path).stat().st_size:raise ValueError('missing or wrong size logical file')
            position=0
            with Path(source.path).open('rb') as original:
                for i in range(first,first+count):
                    offset,chunk,start,length,reserved=SPAN.unpack_from(table,so-64+i*24)
                    o,stored,raw,crc,codec=CHUNK.unpack_from(table,co-64+chunk*24)
                    encoded=read_at(file,o,stored);decoded=zlib.decompress(encoded) if codec else encoded
                    if offset!=position or len(decoded)!=raw or zlib.crc32(decoded)!=crc:
                        raise ValueError('invalid logical chunk')
                    actual=decoded[start:start+length]
                    if len(actual)!=length or actual!=original.read(length):raise ValueError(f'logical bytes differ: {source.name} at {offset}')
                    position+=length
            if position!=size:raise ValueError('incomplete logical reconstruction')
            total+=size;verified+=1
    return dict(files_verified=verified,bytes_verified=total)


# T02/T03 remain the required chest pair; a checked PC00 is optional. Other
# files are ignored. Original guest resources remain unchanged.
MODEL_SOURCES={
    'T02':'fbbc6ed20a3fc8cf8ac69e1c1af74a8ae44d451fcfbb47302321c1182fefabf1',
    'T03':'d77d72f180a3f84691f40bdcade2a20195de67855e71e71ef4470e55857805be',
    'PC00':'b6cbf3c4d4cf456f4921dde96ba769d092143e855a282ca5ff87977f309eb720',
}

def validate_model_header(path,key):
    """Check model identity and bounded wire envelope before archive inclusion.

    Detailed vertex/material/skin semantics remain the independent runtime C
    decoder's responsibility. This check does not claim to decode the payload.
    """
    size=path.stat().st_size
    with path.open('rb') as file:h=file.read(256)
    def need(ok,reason):
        if not ok:raise ValueError(f'{path}: invalid A2M2 {reason}')
    need(256<=size<=128*1024*1024 and len(h)==256,'size')
    need(h[:8]==b'A2M2\0\0\0\0','magic')
    version,header,extent,flags,variant=struct.unpack_from('<IIQII',h,8)
    need((version,header,extent,variant)==(1,256,size,0) and
         flags in ((0,1) if key=='PC00' else (0,)),'version/header/extent/flags/variant')
    need(h[160:192]==key.encode('ascii').ljust(32,b'\0'),'source key does not match logical name')
    need(h[128:160]==bytes.fromhex(MODEL_SOURCES[key]),'source checksum does not match approved native mesh')
    counts=struct.unpack_from('<6I',h,32);width,reserved=struct.unpack_from('<II',h,56)
    need(width in (2,4) and reserved==0 and h[216:256]==bytes(40),'reserved/index fields')
    caps=(1000000,3000000,128,64,256,64)
    need(all(n<=cap and (n>0 or i==5) for i,(n,cap) in enumerate(zip(counts,caps))) and counts[1]%3==0,'counts')
    limits=struct.unpack_from('<6f',h,192)
    need(all(math.isfinite(x) for x in limits) and all(limits[i]<=limits[i+3] for i in range(3)),'bounds')
    offsets=struct.unpack_from('<6Q',h,64);pixel_offset,pixel_bytes=struct.unpack_from('<2Q',h,112)
    need(pixel_bytes<=64*1024*1024 and bool(counts[5])==bool(pixel_bytes),'pixel section')
    ranges=[]
    for offset,count,stride in zip(offsets,counts,(96,width,128,144,48,32)):
        if count:ranges.append((offset,offset+count*stride))
        elif offset:need(offset>=256 and offset<=size and offset%4==0,'empty section offset')
    if pixel_bytes:ranges.append((pixel_offset,pixel_offset+pixel_bytes))
    elif pixel_offset:need(256<=pixel_offset<=size and pixel_offset%4==0,'empty pixel offset')
    ranges.sort()
    need(all(start>=256 and start%4==0 and end<=size for start,end in ranges),'section extent/alignment')
    need(all(ranges[i-1][1]<=ranges[i][0] for i in range(1,len(ranges))),'overlapping sections')


def collect_model_sources(model_root):
    root=Path(model_root);sources=[]
    for key in MODEL_SOURCES:
        name=f'MODELS/{key}.A2M';path=root/name
        if key=='PC00' and not path.exists():continue
        if not path.is_file():raise FileNotFoundError(path)
        validate_model_header(path,key);sources.append(Source(3,name,path))
    return sources


def collect_sources(game_data,voice_root=None,model_root=None):
    game_data=Path(game_data);sources=[]
    for language,relative in enumerate(('disc','profiles/ja/disc','profiles/en/disc')):
        root=game_data/relative
        for name in RUNTIME_FILES:
            path=root/name
            if not path.is_file():raise FileNotFoundError(path)
            sources.append(Source(language,name,path))
    if voice_root is not None:
        voice_root=Path(voice_root)
        for path in sorted((voice_root/'VOICE').rglob('*')):
            if path.is_file():sources.append(Source(3,path.relative_to(voice_root).as_posix(),path))
        for language in ('ja','en'):
            if not (voice_root/f'VOICE/{language}/index.a2v').is_file():raise FileNotFoundError(f'missing {language} native voice index')
    if model_root is not None:sources.extend(collect_model_sources(model_root))
    return sources


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--game-data',type=Path,required=True)
    parser.add_argument('--voice-root',type=Path,help='export root from build_native_voice.py')
    parser.add_argument('--model-root',type=Path,help='staging root with MODELS/T02.A2M, MODELS/T03.A2M and optional MODELS/PC00.A2M; shared by all languages')
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--report',type=Path)
    parser.add_argument('--verify',action='store_true')
    args=parser.parse_args();sources=collect_sources(args.game_data,args.voice_root,args.model_root)
    report=build_archive(sources,args.output)
    if args.verify:report['verification']=verify_archive(args.output,sources)
    text=json.dumps(report,ensure_ascii=False,indent=2)+'\n'
    if args.report:args.report.write_text(text)
    print(text,end='')


if __name__=='__main__':main()
