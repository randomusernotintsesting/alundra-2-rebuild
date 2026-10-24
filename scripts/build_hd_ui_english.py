"""English menu outlines matched against exact installed native atlas rectangles."""
import argparse,hashlib,json,sys
from pathlib import Path
from PIL import Image,ImageDraw
from a2.pak import PakArchive
from menu_texture_patch import parse_container,unpack_indices,palette_rgb
# Legacy texture decoders alter sys.path; prefer this checkout's generators.
sys.path.insert(0,str(Path(__file__).resolve().parent))
import build_hd_ui as base
import settings_texture_patch as settings
import title_texture_patch as title

LABELS={'Предметы':'Items','Стихии':'Magic','Особое':'Key Items','Настройки':'Settings','Карманы':'Pockets',
'Загрузка':'Load','Слот 1':'Slot 1','Слот 2':'Slot 2','Снаряжение':'Equipment','Уровень комбо':'Combo Level',
'Уровень стихии':'Element Level','Выбрать':'Confirm','Отмена':'Cancel','Сброс':'Default','Управление':'Key Config',
'Своя схема':'Custom','Вправо':'Right','Влево':'Left','Предмет':'Item','Ракурс':'View','Действие':'Action',
'Бег':'Run','Атака':'Attack','Прыжок':'Jump','Схема 1':'Type A','Схема 2':'Type B','Схема 3':'Type C',
'Своя':'Custom','Выход':'Exit','ОЗ':'HP','ЭП':'EP','З':'G'}
LABELS.update({ru:en.replace('_speed','').replace('_window','') for en,ru,*_ in settings.LABELS if ru not in LABELS})

def build_assets(installed,pristine):
    a=base.build_assets(base.FONT,pristine.slots[548],pristine.slots[298])
    for p in a:p['palette_slot']=298
    extra=base.build_load_assets(base.FONT,pristine.slots[548])
    for p in extra:p['palette_slot']=375
    a+=extra+base.build_internal_assets(base.FONT,pristine)+base.build_framed_assets(base.FONT,pristine)+base.build_badge_assets(base.FONT,pristine)
    result=[]
    for p in a:
        p=dict(p);p['text']=LABELS[p['text']]
        w,h,pal,chunks=parse_container(installed.slots[p['palette_slot']]);c=chunks[p['page']]
        pixels=unpack_indices(c['raw'],w,h,c['bpp']);x,y,rw,rh=p['uv']
        p['source']=bytes(pixels[(y+j)*w+x+i] for j in range(rh) for i in range(rw))
        # Preserve the proven text-free background and original safe outline box.
        old=Image.frombytes('L',(rw*4,rh*4),p['alpha']).getbbox()
        if old is None:raise ValueError('Missing safe text box')
        left,top,right,bottom=old
        # Keep the original visual line height; use the plate's safe horizontal margin.
        margin=4 if p['palette_slot'] in (298,333,347) else 2
        iw=(rw-2*margin)*4;ih=bottom-top
        ppem=base.fit_ppem([p['text']],base.FONT,iw,ih,p['physical_x_scale'])
        word=base.outline(p['text'],base.FONT,ppem,p['physical_x_scale'])
        alpha=Image.new('L',(rw*4,rh*4));alpha.paste(word,((rw*4-word.width)//2,top+(ih-word.height)//2))
        for at in p.get('protected_offsets',[]):
            if any(alpha.getpixel((at%rw*4+dx,at//rw*4+dy)) for dy in range(4) for dx in range(4)):
                raise ValueError('Outline overlaps a protected frame: '+p['text'])
        p['alpha']=alpha.tobytes();p['ppem']=ppem;p['ink_bbox']=list(alpha.getbbox());p['palette']=pal
        result.append(p)
    # The title uses a separate 8-bit atlas, absent from the pause-menu plates.
    # Keep its installed source pixels for exact matching; only the 4x coverage
    # changes. The native palette and transparent background are shared with RU.
    w,h,pal,chunks=parse_container(installed.slots[23])
    if (w,h,chunks[0]['bpp'])!=(256,256,8) or hashlib.sha256(pal).hexdigest()!=title.PALETTE_HASH:
        raise ValueError('Unknown English title atlas/palette')
    labels=tuple((text,rect) for text,(_,rect) in zip(('New Game','Continue'),title.LABELS))
    for p in title.build_assets(base.FONT,labels):
        p['source']=title.extract(chunks[0]['raw'],p['uv']);p['palette']=pal
        result.append(p)
    return result

def generate(installed,header,preview):
    a=build_assets(PakArchive.load(installed),PakArchive.load(base.ROOT/'disc.orig/DATA/PACK0.PAK'))
    text=base.header_text(a).replace('A2_HD_UI_DATA_H','A2_HD_UI_EN_DATA_H')
    text='\n'.join(line for line in text.splitlines() if not line.startswith('typedef struct A2HDPlate'))+'\n'
    text=text.replace('a2_hd_plate','a2_hd_en_plate');header.write_text(text)
    preview.mkdir(parents=True,exist_ok=True);ims=[];meta=[]
    for p in a:
        palette_size=512 if p['palette_slot']==23 else 32
        rgb=palette_rgb(p['palette'][p['clut_bank']*palette_size:(p['clut_bank']+1)*palette_size]);colors=[tuple(rgb[i:i+3]) for i in range(0,len(rgb),3)]
        im=Image.frombytes('P',(p['width'],p['height']),p['background']);im.putpalette(rgb+[0]*(768-len(rgb)))
        im=im.convert('RGB').resize((p['width']*4,p['height']*4));alpha=Image.frombytes('L',im.size,p['alpha'])
        im.paste(colors[p['ink_index']],(0,0,*im.size),alpha)
        im=im.resize((round(im.width/p['physical_x_scale']),im.height))
        ims.append(im);meta.append({k:v for k,v in p.items() if k not in ('source','background','alpha','original','protected_offsets','palette')})
    sheet=Image.new('RGB',(1500,sum(max(ims[j].height for j in range(i,min(i+3,len(ims))))+25 for i in range(0,len(ims),3))), (22,22,24))
    draw=ImageDraw.Draw(sheet);y=0
    for i in range(0,len(ims),3):
        row=ims[i:i+3]
        for j,im in enumerate(row):
            im.thumbnail((490,160));draw.text((j*500+5,y),a[i+j]['text'],fill='white');sheet.paste(im,(j*500+5,y+16))
        y+=max(im.height for im in row)+25
    sheet.crop((0,0,1500,y)).save(preview/'english-menu-outlines.png')
    (preview/'english-menu-outlines.json').write_text(json.dumps(meta,ensure_ascii=False,indent=2)+'\n')
    print('English outline plates:',len(a))
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--pak',required=True,type=Path);p.add_argument('--header',required=True,type=Path);p.add_argument('--preview',required=True,type=Path)
    args=p.parse_args();generate(args.pak,args.header,args.preview)
