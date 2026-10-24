"""Guarded locale artwork fixes and exact-identity HD shop labels."""
from pathlib import Path
from PIL import Image,ImageDraw
from a2.pak import PakArchive
from a2.cyrfont import build16,decode_bank,bbox_w
from menu_texture_patch import parse_container,unpack_indices,palette_rgb
import build_hd_ui as base
import pocket_texture_patch as pocket
import settings_texture_patch as settings

def patch_english_font_labels(pak,pristine):
    original=settings.LABELS
    try:
        settings.LABELS=tuple((en,en,*rest) for en,ru,*rest in original if en=='Font' or en.startswith('Font '))
        return settings.patch_settings_menu(pak,pristine.slots[548],pristine.slots[333])
    finally:settings.LABELS=original

def shop_assets(installed,language):
    w,h,pal,chunks=parse_container(installed.slots[298])
    pixels=unpack_indices(chunks[1]['raw'],w,h,4)
    font=build16(decode_bank(PakArchive.load(base.ROOT/'disc.orig/DATA/PACK0.PAK').slots[548],16))
    blank={char:([[0]*12 for _ in range(16)],max(adv,bbox_w(px))) for char,(px,adv) in font.items()}
    words=('Купить','Продать','Магазин') if language==0 else ('Buy','Sell','Shop')
    results=[]
    for text,style,rect,clut,scale in zip(words,(0,0,1),((152,32,72,24),(152,56,72,24),(152,128,104,32)),(0,0,12),(4,4,5)):
        source=pocket._extract(pixels,w,rect);rw,rh=rect[2:]
        if style:
            allowed={(x,y) for y in range(4,29) for x in range(5,99)}
            ink={(x,y) for x,y in allowed if source[y*rw+x] not in (5,6,7,8)}
            mask={(x+dx,y+dy) for x,y in ink for dx in (-1,0,1) for dy in (-1,0,1)} & allowed
            candidates=[(x,y) for x,y in allowed-mask if source[y*rw+x] in (5,6,7,8)]
            bg=bytearray(source)
            for x,y in mask:
                bx,by=min(candidates,key=lambda p:(abs(p[0]-x)+abs(p[1]-y),abs(p[1]-y),p[1],p[0]))
                bg[y*rw+x]=source[by*rw+bx]
            background=bytes(bg)
        else:background,_=pocket._replace_label(source,('Предметы',0,rect,clut,scale),blank)
        ppem=base.fit_ppem([text],base.FONT,(rw-12)*4,(rh-14)*4,.5)
        word=base.outline(text,base.FONT,ppem,.5);alpha=Image.new('L',(rw*4,rh*4))
        alpha.paste(word,((rw*4-word.width)//2,(rh*4-word.height)//2-2))
        # Outside the original text interior all source texels are preserved.
        for y in range(rh):
            for x in range(rw):
                if (x<3 or x>=69 or y<4 or y>=19) if style==0 else (x<5 or x>=99 or y<4 or y>=29):
                    assert source[y*rw+x]==background[y*rw+x]
                    assert not any(alpha.getpixel((x*4+dx,y*4+dy)) for dx in range(4) for dy in range(4))
        results.append(dict(text=text,page=1,uv=list(rect),width=rw,height=rh,source=source,background=background,alpha=alpha.tobytes(),ink_index=0 if style==0 else 1,shadow_index=12 if style==0 else 4,ppem=ppem,physical_x_scale=.5,palette=pal,clut_bank=clut))
    return results

def generate_shop(root):
    plates=[]
    for lang in (0,2):plates+=shop_assets(PakArchive.load(root/'staged'/str(lang)/'DATA/PACK0.PAK'),lang)
    header=base.header_text(plates).replace('A2_HD_UI_DATA_H','A2_HD_UI_SHOP_DATA_H').replace('a2_hd_plate','a2_hd_shop_plate')
    header='\n'.join(line for line in header.splitlines() if not line.startswith('typedef struct A2HDPlate'))+'\n'
    (root/'source/port/assets/hd_ui_shop_data.h').write_text(header)
    sheet=Image.new('RGB',(850,380),(30,30,33));d=ImageDraw.Draw(sheet)
    for i,p in enumerate(plates):
        rw,rh=p['width'],p['height'];palette=palette_rgb(p['palette'][p['clut_bank']*32:(p['clut_bank']+1)*32]);im=Image.frombytes('P',(rw,rh),p['background']);im.putpalette(palette+[0]*720);im=im.convert('RGB').resize((rw*4,rh*4));alpha=Image.frombytes('L',im.size,p['alpha']);j=p['ink_index']*3;im.paste(tuple(palette[j:j+3]),(0,0,*im.size),alpha);x=i//3*425;y=i%3*126;sheet.paste(im,(x,y));d.text((x,y+rh*4),p['text'],fill='white')
    sheet.save(root/'ui-audit/shop-hd.png')
if __name__=='__main__':generate_shop(Path(__file__).resolve().parents[2])
