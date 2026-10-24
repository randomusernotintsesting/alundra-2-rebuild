"""Copy existing compressed resources verbatim, appending verified file replacements."""
from pathlib import Path
import collections,hashlib,shutil,struct,zlib
from build_native_resources import HEADER,FILE,SPAN,CHUNK,Source,source_ranges,canonical_name

def replace_files(source,output,replacements,*,additions=None):
    source,output=Path(source),Path(output)
    if output.exists():raise FileExistsError(output)
    with source.open('rb') as src:
        h=list(HEADER.unpack(src.read(64)));magic,version,mask,nf,ns,nc,crc,fo,so,co,old_data=h
        if magic!=b'A2RES001' or version!=1:raise ValueError('Unknown archive')
        table=src.read(old_data-64)
        if zlib.crc32(table)!=crc:raise ValueError('Bad source table')
        files=[list(FILE.unpack_from(table,i*96)) for i in range(nf)]
        existing={(r[1],r[0].split(b'\0',1)[0].decode()) for r in files}
        additions=additions or {}
        for (language,name),path in sorted(additions.items()):
            encoded=canonical_name(name)
            if (language,name) in existing or (language,name) in replacements:
                raise ValueError('Added resource already exists')
            if language not in range(4) or (language<3 and not mask&(1<<language)):
                raise ValueError('Added resource language is unavailable')
            files.append([encoded.ljust(64,b'\0'),language,0,0,0,0,0])
        spans=[SPAN.unpack_from(table,so-64+i*24) for i in range(ns)]
        chunks=[list(CHUNK.unpack_from(table,co-64+i*24)) for i in range(nc)]
        candidates=collections.defaultdict(list)
        for i,c in enumerate(chunks):candidates[(c[2],c[3])].append(i)
        pending=dict(replacements)|dict(additions);extra=[];offset=source.stat().st_size-old_data
        for record in files:
            name=record[0].split(b'\0',1)[0].decode();key=(record[1],name)
            if key not in pending:continue
            path=Path(pending.pop(key));first=len(spans)
            with path.open('rb') as f:
                for pos,n in source_ranges(Source(key[0],key[1],path)):
                    f.seek(pos);raw=f.read(n)
                    if len(raw)!=n:raise ValueError('Short replacement')
                    crc_raw=zlib.crc32(raw);match=None
                    for i in candidates[(n,crc_raw)]:
                        c=chunks[i]
                        if i<nc:src.seek(c[0]);encoded=src.read(c[1])
                        else:encoded=extra[i-nc]
                        decoded=zlib.decompress(encoded) if c[4] else encoded
                        if decoded==raw:match=i;break
                    if match is None:
                        encoded=zlib.compress(raw,6);codec=int(len(encoded)<len(raw));encoded=encoded if codec else raw
                        match=len(chunks);chunks.append([offset,len(encoded),n,crc_raw,codec]);extra.append(encoded);offset+=len(encoded)
                        candidates[(n,crc_raw)].append(match)
                    spans.append((pos,match,0,n,0))
            record[3:6]=[path.stat().st_size,first,len(spans)-first]
        if pending:raise ValueError('Replacement names absent from base archive')
        new_so=64+96*len(files);new_co=new_so+24*len(spans);new_data=new_co+24*len(chunks)
        for i,c in enumerate(chunks):c[0]=(c[0]-old_data if i<nc else c[0])+new_data
        table=b''.join(FILE.pack(*r) for r in files)+b''.join(SPAN.pack(*r) for r in spans)+b''.join(CHUNK.pack(*r) for r in chunks)
        header=HEADER.pack(magic,version,mask,len(files),len(spans),len(chunks),zlib.crc32(table),64,new_so,new_co,new_data)
        with output.open('xb') as dst:
            dst.write(header);dst.write(table);src.seek(old_data);shutil.copyfileobj(src,dst,1024*1024)
            for encoded in extra:dst.write(encoded)
    return {'replaced_files':len(replacements),'added_files':len(additions),'old_chunks_preserved':nc,'appended_chunks':len(chunks)-nc,'bytes':output.stat().st_size}

def append_files(source,output,additions):
    return replace_files(source,output,{},additions=additions)
