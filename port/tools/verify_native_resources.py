#!/usr/bin/env python3
"""Independent C reader/source equality audit; streams bytes, writes only JSON."""
import argparse, hashlib, json, subprocess, sys
from pathlib import Path

parser=argparse.ArgumentParser(description=__doc__)
parser.add_argument('--reader',type=Path,required=True)
parser.add_argument('--archive',type=Path,required=True)
parser.add_argument('--game-data',type=Path,required=True)
parser.add_argument('--report',type=Path,required=True)
args=parser.parse_args()
project=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(project/'scripts'))
from build_native_resources import collect_sources
sources=collect_sources(args.game_data)
if len(sources)!=36:raise RuntimeError('Expected all 36 logical game files')
rows=[]
for source in sources:
    command=[str(args.reader.resolve()),'extract',str(args.archive.resolve()),
             str(source.language),source.name,'/dev/stdout']
    digest=hashlib.sha256();total=0
    with subprocess.Popen(command,stdout=subprocess.PIPE) as child:
        try:
            with source.path.open('rb') as original:
                while data:=child.stdout.read(1024*1024):
                    expected=original.read(len(data))
                    if data!=expected:
                        raise RuntimeError(f'Byte mismatch: {source.language}:{source.name} at {total}')
                    digest.update(data);total+=len(data)
                if original.read(1):
                    raise RuntimeError(f'Truncated C output: {source.language}:{source.name}')
            if child.wait()!=0:raise RuntimeError(f'C reader failed: {source.name}')
        except BaseException:
            if child.poll() is None:child.kill()
            child.wait();raise
    rows.append(dict(language=source.language,name=source.name,bytes=total,sha256=digest.hexdigest()))
    print(f'{source.language}:{source.name}: {total} bytes equal',flush=True)
args.report.write_text(json.dumps(dict(reader=str(args.reader.resolve()),archive=str(args.archive.resolve()),
    files_verified=len(rows),bytes_verified=sum(r['bytes'] for r in rows),files=rows),indent=2)+'\n')
