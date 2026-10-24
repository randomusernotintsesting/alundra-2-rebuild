"""Equipment labels must not destroy original art or alternate copies."""
import importlib
import unittest
import struct
import tempfile
from pathlib import Path
from a2.pak import PakArchive
from menu_texture_patch import parse_container, unpack_indices, encode_lz
REFERENCE=Path(__file__).resolve().parents[1]/'disc.orig/DATA/PACK0.PAK'

class EquipmentTests(unittest.TestCase):
    def test_space_has_visible_advance_even_if_pristine_space_is_zero_width(self):
        import equipment_texture_patch as m
        p=PakArchive.load(REFERENCE);latin=m.decode_bank(p.slots[548],16);g=m.build16(latin)
        a,aw,_=m.glyph_line('АА',g,latin,16);b,bw,_=m.glyph_line('А А',g,latin,16)
        self.assertEqual(bw-aw,4)

    def test_patch_exists_and_is_atomic_idempotent(self):
        try: patcher=importlib.import_module('equipment_texture_patch')
        except ModuleNotFoundError: self.fail('Equipment translation patch missing')
        p=PakArchive.load(REFERENCE); before=list(p.slots)
        result=patcher.patch_equipment(p,before[548],before[545],before[340])
        self.assertEqual(result['changed_slots'],list(range(340,347)))
        for i,(a,b) in enumerate(zip(before,p.slots)):
            if i not in range(340,347): self.assertEqual(a,b)
        once=list(p.slots)
        self.assertEqual(patcher.patch_equipment(p,before[548],before[545],before[340])['changed_slots'],[])
        self.assertEqual(p.slots,once)

    def test_pixels_frames_palettes_second_page_and_tails_preserved(self):
        import equipment_texture_patch as m
        p=PakArchive.load(REFERENCE);before=list(p.slots)
        m.patch_equipment(p,before[548],before[545],before[340])
        rects=((120,0,88,32),(144,32,112,32),(88,160,128,32),(169,70,14,22),(185,70,14,22),(204,70,8,20))
        for slot in range(340,347):
            w,h,pal,a=parse_container(before[slot]);_,_,pal2,b=parse_container(p.slots[slot])
            self.assertEqual(pal,pal2);self.assertEqual(a[1]['compressed'],b[1]['compressed'])
            self.assertEqual(before[slot][a[1]['offset']:],p.slots[slot][b[1]['offset']:])
            old=unpack_indices(a[0]['raw'],w,h,4);new=unpack_indices(b[0]['raw'],w,h,4)
            for y in range(h):
                for x in range(w):
                    if not any(rx<=x<rx+rw and ry<=y<ry+rh for rx,ry,rw,rh in rects):self.assertEqual(old[y*w+x],new[y*w+x])
            for rect in rects:self.assertNotEqual(m.extract(old,w,rect),m.extract(new,w,rect))

    def test_bad_last_copy_and_sources_fail_without_partial_write(self):
        import equipment_texture_patch as m
        source=PakArchive.load(REFERENCE)
        for mode in ('palette','label','font','reference','missing'):
            p=PakArchive(list(source.slots));font=p.slots[548];ref=p.slots[340]
            if mode=='palette':
                d=bytearray(p.slots[346]);d[52]^=1;p.slots[346]=bytes(d)
            elif mode=='label':
                d=p.slots[346];w,h,_,c=parse_container(d);raw=bytearray(c[0]['raw']);raw[64]^=1
                enc=encode_lz(raw);head=bytearray(d[:c[0]['offset']]);struct.pack_into('<I',head,12,len(enc));p.slots[346]=bytes(head)+enc+d[c[1]['offset']:]
            elif mode=='font':font=font[:-1]+b'!'
            elif mode=='reference':ref=ref[:-1]+b'!'
            else:p.slots[346]=None
            before=list(p.slots)
            with self.subTest(mode=mode):
                with self.assertRaises(ValueError):m.patch_equipment(p,font,source.slots[545],ref)
                self.assertEqual(p.slots,before)

    def test_custom_nonlabel_pixel_survives_and_copies_may_differ(self):
        import equipment_texture_patch as m
        p=PakArchive.load(REFERENCE);ref=p.slots[340]
        d=p.slots[346];w,h,_,c=parse_container(d);raw=bytearray(c[0]['raw']);raw[220*128+120]^=1
        enc=encode_lz(raw);head=bytearray(d[:c[0]['offset']]);struct.pack_into('<I',head,12,len(enc));p.slots[346]=bytes(head)+enc+d[c[1]['offset']:]
        m.patch_equipment(p,p.slots[548],p.slots[545],ref)
        self.assertEqual(parse_container(p.slots[346])[3][0]['raw'][220*128+120],raw[220*128+120])

    def test_new_stage_only_and_sources_unchanged(self):
        import equipment_texture_patch as m
        p=PakArchive.load(REFERENCE)
        with tempfile.TemporaryDirectory() as temp:
            folder=Path(temp);src=folder/'source.pak';p.save(src);before=src.read_bytes();out=folder/'out'
            m.stage(src,src,out);self.assertEqual(src.read_bytes(),before)
            saved=(out/'DATA/PACK0.PAK').read_bytes()
            with self.assertRaises(FileExistsError):m.stage(src,src,out)
            self.assertEqual((out/'DATA/PACK0.PAK').read_bytes(),saved)

if __name__=='__main__': unittest.main()
