"""Cross-check the independent C fixture, Python encoder and archive reader."""
from pathlib import Path
import subprocess
import sys
import tempfile

sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'scripts'))
from a2.native_model import pack_model
from test_native_model import triangle_model
from build_native_resources import Source,build_archive,verify_archive


def main():
    decoder=Path(sys.argv[1]).resolve()
    with tempfile.TemporaryDirectory(prefix='a2-model-contract-') as tmp:
        root=Path(tmp);literal=root/'literal.a2m';encoded=root/'encoded.a2m'
        subprocess.run([decoder,'--write-fixture',literal],check=True)
        encoded.write_bytes(pack_model(triangle_model()))
        if encoded.read_bytes()!=literal.read_bytes():raise AssertionError('encoder differs from independent literal fixture')
        archive=root/'game.a2r';sources=[Source(3,'MODELS/T02.A2M',encoded)]
        build_archive(sources,archive);verify_archive(archive,sources)
        subprocess.run([decoder,'--archive',archive],check=True)
        m=triangle_model();m['index_width']=4;m['textures']=[];m['materials'][0]['texture']=[None,None]
        encoded.write_bytes(pack_model(m));subprocess.run([decoder,'--decode',encoded],check=True)
    print('A2M2 cross-language bytes, u32 indices, optional texture and archive load passed')


if __name__=='__main__':main()
