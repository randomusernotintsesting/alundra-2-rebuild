"""Render unchanged equipment source pages for source-coordinate review."""
from pathlib import Path
from PIL import Image, ImageDraw
from a2.pak import PakArchive
from menu_texture_patch import parse_container, unpack_indices, palette_rgb

def main():
    out=Path('port/build/verification/equipment-source'); out.mkdir(parents=True,exist_ok=True)
    p=PakArchive.load('disc.orig/DATA/PACK0.PAK')
    w,h,pal,chunks=parse_container(p.slots[340])
    print(w,h,len(chunks),len(pal)//32)
    for n,c in enumerate(chunks):
        for clut in range(len(pal)//32):
            image=Image.frombytes('P',(w,h),unpack_indices(c['raw'],w,h,4))
            image.putpalette(palette_rgb(pal[clut*32:(clut+1)*32])+[0]*720)
            image.convert('RGB').resize((w*3,h*3),Image.Resampling.NEAREST).save(out/f'page{n}-clut{clut}.png')
if __name__=='__main__': main()
