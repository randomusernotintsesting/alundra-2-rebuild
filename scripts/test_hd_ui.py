"""Outline Pocket plates retain exact native identity and protected frames."""
import importlib
import hashlib
import json
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path
from a2.pak import PakArchive
from a2.cyrfont import build16,decode_bank
import pocket_texture_patch as pocket
from menu_texture_patch import parse_container,unpack_indices

ROOT=Path(__file__).resolve().parents[1]
FONT=ROOT/'port/assets/fonts/PT_Serif-Web-Regular.ttf'

class HDUITests(unittest.TestCase):
    def assets(self):
        try:m=importlib.import_module('build_hd_ui')
        except ModuleNotFoundError:self.fail('HD outline plate builder missing')
        p=PakArchive.load(ROOT/'disc.orig/DATA/PACK0.PAK')
        return m.build_assets(FONT,p.slots[548],p.slots[298]),p

    def test_five_full_labels_use_outline_antialias_and_bounded_coverage(self):
        plates,_=self.assets()
        self.assertEqual([p['text'] for p in plates],['Предметы','Стихии','Особое','Настройки','Карманы'])
        for p in plates:
            w,h=p['width'],p['height'];a=p['alpha']
            self.assertEqual(len(a),w*h*16)
            self.assertTrue(any(0<v<255 for v in a));self.assertTrue(any(v==255 for v in a))
            self.assertEqual(len(p['source']),w*h);self.assertEqual(len(p['background']),w*h)
            for y in range(h):
                for x in range(w):
                    block=[a[(y*4+dy)*w*4+x*4+dx] for dy in range(4) for dx in range(4)]
                    if p['source'][y*w+x]==15:self.assertFalse(any(block),'transparent frame covered')
                    if p['page']==0 and p['source'][y*w+x] in (1,2,3,4,15):
                        self.assertFalse(any(block),'tab bevel covered')

    def test_source_matches_current_russian_and_background_preserves_frames(self):
        plates,p=self.assets();w,h,_,chunks=parse_container(p.slots[298]);g=build16(decode_bank(p.slots[548],16))
        pages=[unpack_indices(c['raw'],w,h,4) for c in chunks]
        for plate,spec in zip(plates,pocket.LABELS):
            original=pocket._extract(pages[spec[1]],w,spec[2]);expected,_=pocket._replace_label(original,spec,g)
            self.assertEqual(plate['source'],expected)
            bw,bh=plate['width'],plate['height']
            for y in range(bh):
                for x in range(bw):
                    protected=(not (3<=x<69 and 4<=y<19) or original[y*bw+x] in (1,2,3,4,15)) if spec[1]==0 else not (5<=x<99 and 5<=y<25)
                    if spec[0] in ('Особое','Настройки') and y==19 and x in (20,21):
                        self.assertEqual(plate['background'][y*bw+x],8)
                        continue
                    if protected:self.assertEqual(plate['background'][y*bw+x],original[y*bw+x])

    def test_deterministic_generation_and_physical_aspect(self):
        first,_=self.assets();second,_=self.assets();self.assertEqual(first,second)
        for p in first:
            self.assertEqual(p['physical_x_scale'],0.5)
            self.assertLessEqual(p['ink_bbox'][2],p['width']*4)
            self.assertLessEqual(p['ink_bbox'][3],p['height']*4)

    def test_old_english_descender_tips_only_are_removed_from_hd_background(self):
        plates,_=self.assets()
        for p in plates:
            if p['text'] in ('Особое','Настройки'):
                self.assertEqual(list(p['source'][19*72+20:19*72+22]),[13,14])
                self.assertNotIn(p['background'][19*72+20],(13,14))
                self.assertNotIn(p['background'][19*72+21],(13,14))

    def test_load_exact_source_clear_background_and_natural_case(self):
        import build_hd_ui as hd
        import menu_texture_patch as menu
        p=PakArchive.load(ROOT/'disc.orig/DATA/PACK0.PAK')
        plates=hd.build_load_assets(hd.FONT,p.slots[548])
        self.assertEqual([a['text'] for a in plates],['Загрузка','Слот 1','Слот 2'])
        for a,spec,source in zip(plates,menu.LABELS,menu._render_labels(p.slots[548])):
            self.assertEqual(a['physical_x_scale'],1.0)
            self.assertEqual(a['source'],source)
            self.assertEqual(a['background'],bytes(a['width']*a['height']))
            self.assertEqual(a['uv'],list(spec[1]))
            self.assertEqual((a['ink_index'],a['shadow_index']),(15,5))
            self.assertTrue(any(0<x<255 for x in a['alpha']))
            x,y,r,b=a['ink_bbox']
            self.assertGreaterEqual(x,4);self.assertGreaterEqual(y,4)
            self.assertLessEqual(r,(a['width']-1)*4)
            self.assertLessEqual(b,(a['height']-1)*4)

    def test_internal_transparent_labels_match_existing_patchers(self):
        import build_hd_ui as hd
        import settings_texture_patch as settings
        import equipment_texture_patch as equipment
        p=PakArchive.load(ROOT/'disc.orig/DATA/PACK0.PAK')
        plates=hd.build_internal_assets(hd.FONT,p)
        expected=[s[1] for s in settings.LABELS if s[4]==2]+[s[0] for s in equipment.LABELS if s[3] is None]
        self.assertEqual([a['text'] for a in plates],expected)
        for a in plates:
            self.assertFalse(any(a['background']))
            self.assertTrue(any(a['source']))
            self.assertTrue(any(0<x<255 for x in a['alpha']))
            self.assertEqual(a['ink_index'],15)

    def test_framed_buttons_preserve_bevel_and_exact_source(self):
        import build_hd_ui as hd
        p=PakArchive.load(ROOT/'disc.orig/DATA/PACK0.PAK')
        plates=hd.build_framed_assets(hd.FONT,p)
        self.assertEqual(len(plates),19)
        self.assertEqual([a['text'] for a in plates[:3]],['Выбрать','Отмена','Сброс'])
        for a in plates:
            self.assertNotEqual(a['source'],a['background'])
            self.assertTrue(any(0<v<255 for v in a['alpha']))
            w=a['width']
            for pos in a['protected_offsets']:
                self.assertEqual(a['background'][pos],a['original'][pos])
                x,y=pos%w,pos//w
                self.assertFalse(any(a['alpha'][(y*4+dy)*w*4+x*4+dx] for dy in range(4) for dx in range(4)))
                for dy in range(4):
                    for dx in range(4):
                        sx,sy=x*4+dx-2,y*4+dy-4
                        if sx>=0 and sy>=0:
                            self.assertEqual(a['alpha'][sy*w*4+sx],0,'shadow overlaps bevel')

    def test_framed_typographic_groups_share_one_safe_ppem(self):
        import build_hd_ui as hd
        p=PakArchive.load(ROOT/'disc.orig/DATA/PACK0.PAK')
        plates=hd.build_framed_assets(hd.FONT,p)
        for group in (plates[:3],plates[3:5],plates[5:]):
            self.assertEqual(len({a['ppem'] for a in group}),1)
            for a in group:
                x,y,r,b=a['ink_bbox']
                self.assertGreaterEqual(x,0);self.assertGreaterEqual(y,0)
                self.assertLessEqual(r,a['width']*4);self.assertLessEqual(b,a['height']*4)

    def test_brightness_preserves_each_band_row_and_all_four_lines(self):
        import build_hd_ui as hd
        import brightness_texture_patch as bright
        p=PakArchive.load(ROOT/'disc.orig/DATA/PACK0.PAK')
        raw=parse_container(p.slots[361])[3][0]['raw']
        plates=hd.build_brightness_assets(hd.FONT,p)
        self.assertEqual(len(plates),2)
        self.assertEqual(plates[0]['text'],'\n'.join(bright.LINES))
        for a,source in zip(plates,bright._render(raw,p.slots[548])[0]):
            self.assertEqual(a['source'],source)
            self.assertEqual(a['bpp'],8)
            for y in range(a['height']):
                self.assertEqual(a['background'][y*a['width']:(y+1)*a['width']],bytes([raw[(a['uv'][1]+y)*256]])*a['width'])
        for line in range(4):
            start=line*18*4*232*4
            self.assertTrue(any(plates[0]['alpha'][start:start+18*4*232*4]))

    def test_badges_exact_identities_and_preserved_outer_frames(self):
        import build_hd_ui as hd
        p=PakArchive.load(ROOT/'disc.orig/DATA/PACK0.PAK')
        plates=hd.build_badge_assets(hd.FONT,p)
        self.assertEqual([a['text'] for a in plates],['ОЗ','ЭП','З','ОЗ','ЭП'])
        self.assertEqual([a['physical_x_scale'] for a in plates],[0.5]*3+[1.0]*2)
        for a in plates:
            self.assertTrue(any(0<v<255 for v in a['alpha']))
            for pos in a['protected_offsets']:
                self.assertEqual(a['background'][pos],a['original'][pos])
                x,y=pos%a['width'],pos//a['width']
                self.assertFalse(any(a['alpha'][(y*4+dy)*a['width']*4+x*4+dx] for dy in range(4) for dx in range(4)))
        for a in plates[3:]:self.assertFalse(any(a['background']))

    def test_optional_title_generation_matches_v6_native_source_and_8bit_palette(self):
        from PIL import Image
        # This actual staged source is independent of the HD generator:
        # a wrong source identity would leave the title rendered at native size.
        staged=PakArchive.load(ROOT/'port/build/verification/full-menu-v6/DATA/PACK0.PAK')
        page=parse_container(staged.slots[23])[3][0]['raw']
        with tempfile.TemporaryDirectory(prefix='a2-title-hd-test-') as tmp:
            tmp=Path(tmp)
            result=subprocess.run([sys.executable,str(ROOT/'scripts/build_hd_ui.py'),
                '--header',str(tmp/'ui.h'),'--preview',str(tmp/'preview'),
                '--include-load','--include-internal','--include-framed',
                '--include-brightness','--include-badges','--include-title'],
                text=True,capture_output=True)
            self.assertEqual(result.returncode,0,result.stderr)
            plates=json.loads((tmp/'preview/metadata.json').read_text())['plates']
            self.assertEqual(len(plates),64)
            self.assertEqual([p['text'] for p in plates[-2:]],['Новая игра','Продолжить'])
            for index,(plate,x) in enumerate(zip(plates[-2:],(64,128)),62):
                source=b''.join(page[y*256+x:y*256+x+64] for y in range(240,256))
                self.assertEqual(plate['source_sha256'],hashlib.sha256(source).hexdigest())
                self.assertEqual(plate['uv'],[x,240,64,16])
                self.assertEqual(plate['bpp'],8)
                self.assertEqual(plate['physical_x_scale'],1.0)
                image=Image.open(tmp/f'preview/plate{index}-physical.png').convert('RGB')
                self.assertEqual(image.size,(256,64))
                self.assertEqual(image.getpixel((0,0)),(0,0,0))
                self.assertIn((255,255,255),{color for _,color in image.getcolors(256*64)},
                              '8bpp palette block4 must yield white title ink')

if __name__=='__main__':unittest.main()
