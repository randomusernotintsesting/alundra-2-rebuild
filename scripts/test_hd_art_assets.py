"""Native source identity and authored HUD typography/geometry contracts."""
import importlib
import hashlib
import struct
import unittest
from unittest.mock import patch
from pathlib import Path
from PIL import ImageFont
from a2.pak import PakArchive
from export_ui_sources import decode_region

ROOT=Path(__file__).resolve().parents[1]

class HDArtAssetsTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.archive=PakArchive.load(ROOT/'disc.orig/DATA/PACK0.PAK')

    def assets(self):
        return importlib.import_module('build_hd_art').build_hud(self.archive)

    def test_numeric_families_keep_exact_native_cells_and_shared_baseline(self):
        assets=self.assets()
        for family,width,v in [('small',6,112),('large',8,120)]:
            digits=[a for a in assets if a['name'].startswith('digit_'+family+'_')]
            self.assertEqual(len(digits),10)
            self.assertEqual(len({(a['ppem'],a['baseline']) for a in digits}),1)
            for d,a in enumerate(digits):
                self.assertEqual(a['uv'],(width*(d+1),v,width,8))
                self.assertEqual(a['bpp'],4)
                source,_,_=decode_region(self.archive,29,0,a['uv'],7)
                self.assertEqual(a['source'],source)
                self.assertEqual(len(a['pixels']),width*8*16)
                alpha=[p>>24 for p in a['pixels']]
                self.assertTrue(any(0<x<255 for x in alpha))
                self.assertTrue(any(x==255 for x in alpha))
                self.assertTrue(all((p&255) in (12,15) for p in a['pixels']))

    def test_geometry_source_identity_transparent_corners_and_palette_tokens(self):
        assets=self.assets()
        names={a['name']:a for a in assets}
        for name,rect in [('health_frame',(0,0,56,36)),('right_frame',(56,0,48,72)),
                          ('item_glass',(56,72,32,32))]:
            a=names[name]
            source,_,_=decode_region(self.archive,29,0,rect,0)
            self.assertEqual(a['source'],source)
            self.assertEqual(a['uv'],rect)
            self.assertEqual(a['pixels'][0]>>24,0)
            self.assertTrue(any(0<(p>>24)<255 for p in a['pixels']))
            self.assertTrue(all((p&255)<16 and ((p>>8)&255)<16 for p in a['pixels']))
        state=names['health_state']
        self.assertEqual(state['uv'],(64,0,56,36))
        self.assertEqual(state['bpp'],8)
        source,_,_=decode_region(self.archive,29,1,(0,0,56,36),0)
        self.assertEqual(state['source'],source)
        used={p&255 for p in state['pixels'] if p>>24}
        self.assertTrue(set(source)-{0} <= used, 'health palette states must not be discarded')

    def test_deterministic_and_no_archive_mutation(self):
        original=self.archive.slots[29]
        self.assertEqual(self.assets(),self.assets())
        self.assertEqual(self.archive.slots[29],original)

    def test_hud_uses_real_bold_face_and_restores_currency_letter(self):
        module=importlib.import_module('build_hd_art')
        self.assertEqual(ImageFont.truetype(str(module.HUD_FONT),30).getname(),('PT Serif','Bold'))
        self.assertEqual(hashlib.sha256(module.HUD_FONT.read_bytes()).hexdigest(),
                         '038ba7336bd7ea14f12ad155bed51a4345cac5153275d521dec3ba04021c526e')
        # Real bold keeps the original fixed advances but adds substantial ink.
        for width in (6,8):
            bold=module.digit_family(width)
            with patch.object(module,'HUD_FONT',module.FONT):
                regular=module.digit_family(width)
            for (pixels,ppem,baseline),(old,_,_) in zip(bold,regular):
                self.assertGreater(sum(p>>24 for p in pixels),sum(p>>24 for p in old)*1.25)
                rows={i//(width*4) for i,p in enumerate(pixels) if p>>24>128}
                self.assertGreaterEqual(max(rows)-min(rows)+1,24)
        with patch.object(module,'hud_letter',wraps=module.hud_letter) as letter:
            module.right_frame()
        self.assertEqual(letter.call_args.args[1],'G')
        self.assertEqual(letter.call_args.kwargs['box'],(1.5,42,9.5,51))
        # The later lens-fit correction changes the circular frame above the
        # counters. Currency, key and multiplier pixels still remain intact.
        pixels=module.right_frame()
        protected=pixels[42*4*192:]
        self.assertEqual(hashlib.sha256(struct.pack('<'+str(len(protected))+'I',*protected)).hexdigest(),
                         'e36b17059b686a6f0713b6e11bb9ff0988e842a37708c9e6843c959906ea0f01')

    def test_health_segment_boundaries_follow_one_normal_across_ring(self):
        module=importlib.import_module('build_hd_art')
        source,_,_=decode_region(self.archive,29,1,(0,0,56,36),0)
        pixels=module.health_state(source)
        # Across the upper-left rounded end, the same radial normal must
        # represent the same live health step, not stair-step source samples.
        # A synthetic palette makes individual step identity observable.
        import math
        for cx,cy,rotation in ((13,13,0),(42,13,1),(42,23,2),(13,23,3)):
            # Odd eighth-unit vectors times odd integers land exactly on
            # fine-pixel centres along one normal. Rounded arbitrary angles
            # test different normals and mistake crisp endpoint AA for a gap.
            for vx,vy in ((-1,-1),(-1,-3),(-3,-1),(-3,-5),(-5,-3)):
                for _ in range(rotation):vx,vy=-vy,vx
                tokens=[]
                for step in range(1,65,2):
                    if not 5.75<math.hypot(vx,vy)*step/8<9.25:continue
                    x=cx+vx*step/8;y=cy+vy*step/8
                    p=pixels[int(y*4)*224+int(x*4)]
                    mix=(p>>16)&255
                    tokens.append(((p&255)*(255-mix)+((p>>8)&255)*mix)/255)
                    self.assertEqual(p>>24,255)
                self.assertGreaterEqual(len(tokens),2)
                self.assertLess(max(tokens)-min(tokens),.01,(cx,cy,vx,vy,tokens))
        # Preserve the gameplay seam and every source CLUT state, never RGB.
        self.assertTrue(set(source)-{0} <= {p&255 for p in pixels if p>>24})
        self.assertTrue(all((p&255) in set(source) and ((p>>8)&255) in set(source) for p in pixels))

    def test_rendered_currency_g_has_bowl_opening_and_horizontal_spur(self):
        module=importlib.import_module('build_hd_art')
        pixels=module.right_frame()
        def gold(x,y):
            p=pixels[int(y*4)*192+int(x*4)];mix=(p>>16)&255
            return ((255-mix) if p&255==13 else 0)+(mix if (p>>8)&255==13 else 0)
        # Hand-checked interior points in the actual rendered G, independent
        # of hud_letter calls or glyph metadata. These catch an empty label,
        # the former coin, and a closed O-shaped replacement as well.
        for point in ((3.25,46),(5.5,43.5),(5.5,49.25),(6.5,46.75),(7.25,48)):
            self.assertGreater(gold(*point),230,point)
        for point in ((7,45.5),(5,46)):
            self.assertEqual(gold(*point),0,point)

    @unittest.skipUnless((ROOT/'port/build/verification/hd-art57-menu-return/replay/user/vram_08199.bin').exists(),
                         'requires retained native HUD capture')
    def test_captured_yellow_health_palette_still_controls_the_endpoint(self):
        module=importlib.import_module('build_hd_art')
        vram=(ROOT/'port/build/verification/hd-art57-menu-return/replay/user/vram_08199.bin').read_bytes()
        clut=0x7e70
        palette=struct.unpack_from('<256H',vram,2*((clut>>6)*1024+(clut&63)*16))
        self.assertEqual(set(palette[17:99]),{0x8421})
        self.assertEqual(set(palette[99:117]),{0x1b5e})
        source,_,_=decode_region(self.archive,29,1,(0,0,56,36),0)
        pixels=module.health_state(source)
        def sample(x,y):return pixels[int(y*4)*224+int(x*4)]
        self.assertEqual(palette[sample(18,5)&255],0x1b5e)
        self.assertEqual(palette[sample(38,5)&255],0x8421)
        self.assertEqual(palette[sample(27.5,5)&255],0)

    def test_lens_keeps_native_rim_and_both_reflections(self):
        module=importlib.import_module('build_hd_art')
        pixels=module.item_glass()
        def sample(x,y):return pixels[int(y*4)*128+int(x*4)]
        # Native lens extends to x0 and y0; the earlier inset circle floated
        # inside the gold frame. Its lower reflection was also omitted.
        self.assertGreater(sample(.5,15.5)>>24,230)
        self.assertGreater(sample(15.5,.5)>>24,230)
        self.assertGreaterEqual(sample(17,28)&255,5)
        self.assertGreaterEqual(sample(10.5,4.5)&255,6)
        self.assertEqual(sample(16,16)&255,1)
        self.assertEqual(pixels[0]>>24,0)

    def test_lens_and_inner_gold_edge_meet_in_actual_packet_coordinates(self):
        module=importlib.import_module('build_hd_art')
        frame=module.right_frame()
        import math
        # Actual GP0 packets18400: frame XY264,8..311,79 / UV56,0..104,72;
        # lens XY272,12..304,44 / UV56,72..88,104. The HD lens fills32x32.
        # Immediately beyond the HD glass must meet
        # brass, not a black annulus caused by a separately guessed centre.
        for angle in range(0,360,15):
            theta=math.radians(angle)
            screen_x=8+16+16.375*math.cos(theta)
            screen_y=4+16+16.375*math.sin(theta)
            x=screen_x*48/47;y=screen_y*72/71
            # The original auxiliary attachment intentionally covers this arc.
            if x>=38 and y>=30:continue
            word=frame[int(y*4)*192+int(x*4)]
            mix=(word>>16)&255
            brass=((255-mix) if (word&255)>1 else 0)+(mix if ((word>>8)&255)>1 else 0)
            self.assertGreater(brass,180,(angle,x,y,hex(word)))

    def test_circular_bezel_is_thin_concentric_and_fully_filled(self):
        module=importlib.import_module('build_hd_art')
        import math
        frame=module.right_frame()
        glass=module.item_glass()
        def sample(pixels,width,x,y):
            return pixels[int(y*4)*width*4+int(x*4)]
        # The real packets put the lens centre at (24,20) relative to the
        # frame. Probe the rendered contour, not ellipse-call parameters.
        for angle in range(0,360,15):
            dx,dy=math.cos(math.radians(angle)),math.sin(math.radians(angle))
            self.assertGreater(sample(glass,32,16+15.6*dx,16+15.6*dy)>>24,230,angle)
            x,y=24+18.6*dx,20+18.6*dy
            if x*48/47>=37.5 and y*72/71>=29.5:continue # attachment plus antialiasing
            self.assertLess(sample(frame,48,x*48/47,y*72/71)>>24,10,angle)
            for radius in (16.35,17,17.65):
                word=sample(frame,48,(24+radius*dx)*48/47,(20+radius*dy)*72/71)
                mix=(word>>16)&255
                gold=((255-mix) if (word&255)>1 else 0)+(mix if ((word>>8)&255)>1 else 0)
                self.assertGreater(gold,180,(angle,radius,hex(word)))

    def test_live_health_caps_keep_native_step_extent_and_one_pixel_seam(self):
        module=importlib.import_module('build_hd_art')
        source,_,_=decode_region(self.archive,29,1,(0,0,56,36),0)
        pixels=module.health_state(source)
        def weight(x,y,lit):
            word=pixels[int(y*4)*224+int(x*4)];mix=(word>>16)&255
            return ((255-mix) if (word&255) in lit else 0)+(mix if ((word>>8)&255) in lit else 0)
        # Native row5: token111 at21,112 at22,116 at26, transparent16 at27.
        self.assertEqual(list(source[5*56+21:5*56+28]),[111,112,113,114,115,116,16])
        for y in (4.125,6.125,7.625):
            partial=set(range(112,117))
            self.assertGreaterEqual(weight(22.125,y,partial),250)
            self.assertLessEqual(weight(21.875,y,partial),5)
            for lit in (set(range(17,117)),partial):
                self.assertGreaterEqual(weight(26.875,y,lit),250)
                self.assertLessEqual(weight(27.125,y,lit),5)
                self.assertLessEqual(weight(27.875,y,lit),5)
            self.assertEqual(weight(26.875,y,set()),0)

    @unittest.skipUnless((ROOT/'port/build/verification/full-menu-v6/DATA/PACK0.PAK').exists(), 'requires local v6 stage')
    def test_menu_surfaces_identify_actual_localized_regions(self):
        module=importlib.import_module('build_hd_art')
        archive=PakArchive.load(ROOT/'port/build/verification/full-menu-v6/DATA/PACK0.PAK')
        assets=module.build_menus(archive)
        self.assertEqual(len(assets),32)
        for a in assets:
            source,_,bpp=decode_region(archive,a['slot'],a['page'],a['uv'],a['clut_bank'])
            self.assertEqual(a['source'],source)
            self.assertEqual(a['bpp'],bpp)
            self.assertEqual(len(a['pixels']),a['uv'][2]*a['uv'][3]*16)
            self.assertTrue(any(0<(p>>24)<255 for p in a['pixels']))
        self.assertEqual(len([a for a in assets if a['name'].startswith('key_')]),16)
        self.assertEqual(len([a for a in assets if a['name'].startswith('pocket_tab_')]),4)
        names={a['name']:a for a in assets}
        # Actual GP0 RAM21300: name packets800F6820/800F683C use79BC;
        # section packet800F68AC uses79BD, not atlas palette banks0/1.
        for name,bank,light,shadow,want_light in (
                ('equipment_name',12,8,2,0xaa13),('equipment_section',13,6,9,0xaa13)):
            a=names[name]
            self.assertEqual(a['clut_bank'],bank)
            pal=struct.unpack('<16H',a['palette'])
            self.assertEqual(pal[light],want_light)
            def brightness(word):
                return sum(((word>>shift)&31)*weight for shift,weight in ((0,299),(5,587),(10,114)))
            self.assertGreater(brightness(pal[light]),brightness(pal[shadow]))
            used={p&255 for p in a['pixels'] if p>>24}
            self.assertIn(light,used)
            self.assertIn(shadow,used)
            self.assertTrue(all(pal[index]&0x7fff for index in used))
        self.assertEqual(names['equipment_panel']['uv'],(0,64,168,96))
        self.assertEqual(names['pocket_panel']['uv'],(0,56,136,128))
        self.assertEqual(names['settings_prompt_confirm']['uv'],(24,98,52,28))
        self.assertEqual(names['settings_prompt_cancel']['uv'],(24,130,52,28))
        self.assertEqual(names['settings_prompt_reset']['uv'],(208,58,44,28))
        def token(name,x,y):
            a=names[name]
            return a['pixels'][(y*4+2)*a['uv'][2]*4+x*4+2]&255
        # Three distinct native compartments, with narrow connecting sections.
        self.assertEqual(token('equipment_panel',32,45),1)
        self.assertEqual(token('equipment_panel',120,22),10)
        self.assertEqual(token('equipment_panel',120,69),10)
        self.assertEqual(token('equipment_panel',77,22),10)
        self.assertNotEqual(token('equipment_panel',77,46),10)
        # Pocket body's palette index0 is opaque dark glass, not alpha0.
        body=names['pocket_panel']['pixels'][(80*4+2)*136*4+60*4+2]
        self.assertEqual(body&255,0)
        self.assertEqual(body>>24,255)
        for a in assets:
            self.assertTrue(all((p&255)<16 and ((p>>8)&255)<16 for p in a['pixels']))
        original={slot:archive.slots[slot] for slot in (298,333,340,347)}
        self.assertEqual(assets,module.build_menus(archive))
        self.assertEqual(original,{slot:archive.slots[slot] for slot in original})
        for slot in original:
            archive.slots[slot]=original[slot][:-1]+bytes([original[slot][-1]^1])
            with self.assertRaisesRegex(ValueError,'unknown.*menu source'):
                module.build_menus(archive)
            archive.slots[slot]=original[slot]

if __name__=='__main__': unittest.main()
