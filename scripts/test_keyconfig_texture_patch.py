import importlib
import unittest
import tempfile
import struct
from pathlib import Path
from a2.pak import PakArchive
from menu_texture_patch import parse_container, unpack_indices, encode_lz

ROOT = Path(__file__).resolve().parent.parent
SLOTS = (347,349,351,353,355,357,359)

class KeyConfigTests(unittest.TestCase):
    def test_unknown_label_rejected_but_unrelated_custom_pixel_survives(self):
        p=importlib.import_module('keyconfig_texture_patch')
        stock=PakArchive.load(ROOT/'disc.orig/DATA/PACK0.PAK')
        def altered(offset):
            data=stock.slots[359];chunks=parse_container(data)[3]
            raw=bytearray(chunks[0]['raw']);raw[offset]^=1
            enc=encode_lz(raw);header=bytearray(data[:chunks[0]['offset']])
            struct.pack_into('<I',header,12,len(enc))
            return bytes(header)+enc+data[chunks[0]['offset']+chunks[0]['size']:],raw
        arc=PakArchive(list(stock.slots));arc.slots[359],_=altered(8*128+30)
        before=list(arc.slots)
        with self.assertRaisesRegex(ValueError,'artwork'):p.patch_keyconfig(arc,stock.slots[548],stock.slots[347])
        self.assertEqual(before,arc.slots)
        arc=PakArchive(list(stock.slots));arc.slots[359],raw=altered(220*128+120)
        p.patch_keyconfig(arc,stock.slots[548],stock.slots[347])
        self.assertEqual(parse_container(arc.slots[359])[3][0]['raw'][220*128+120],raw[220*128+120])

    def test_only_two_reviewed_soft_descender_pixels_may_meet_header_bevel(self):
        p=importlib.import_module('keyconfig_texture_patch')
        stock=PakArchive.load(ROOT/'disc.orig/DATA/PACK0.PAK')
        report=p.patch_keyconfig(PakArchive(list(stock.slots)),stock.slots[548],stock.slots[347])
        self.assertEqual(report['omitted_shadow_pixels'], [[71,19,2],[72,19,1]])

    def test_existing_stage_is_never_overwritten(self):
        p=importlib.import_module('keyconfig_texture_patch')
        with tempfile.TemporaryDirectory() as tmp:
            sentinel=Path(tmp)/'keep';sentinel.write_bytes(b'user data')
            with self.assertRaises(FileExistsError):
                p.stage_patch('missing','missing','missing',tmp)
            self.assertEqual(sentinel.read_bytes(),b'user data')

    def test_unknown_reference_and_font_are_rejected_without_changes(self):
        p=importlib.import_module('keyconfig_texture_patch')
        stock=PakArchive.load(ROOT/'disc.orig/DATA/PACK0.PAK')
        arc=PakArchive(list(stock.slots))
        for font,ref in [(b'bad',stock.slots[347]),(stock.slots[548],b'bad')]:
            with self.assertRaises(ValueError):p.patch_keyconfig(arc,font,ref)
            self.assertEqual(arc.slots,stock.slots)

    def test_localized_copies_preserve_other_pixels_and_repeat_safely(self):
        try:
            p = importlib.import_module('keyconfig_texture_patch')
        except ModuleNotFoundError:
            self.fail('key configuration patch is missing')
        stock = PakArchive.load(ROOT/'disc.orig/DATA/PACK0.PAK')
        arc = PakArchive(list(stock.slots))
        report = p.patch_keyconfig(arc, stock.slots[548], stock.slots[347])
        self.assertEqual(report['changed_slots'], list(SLOTS))
        for i,(old,new) in enumerate(zip(stock.slots,arc.slots)):
            if i not in SLOTS:
                self.assertEqual(old,new)
                continue
            w,h,pal,c = parse_container(old)
            _,_,np,nc = parse_container(new)
            self.assertEqual(pal,np)
            a=unpack_indices(c[0]['raw'],w,h,4)
            b=unpack_indices(nc[0]['raw'],w,h,4)
            for y in range(h):
                for x in range(w):
                    # Only ink-bearing interior of original 16 plates.
                    inside = (10<=x<170 and (5<=y<20 or 29<=y<44)) or (
                        48<=y<216 and 4<=y%24<20 and (3<=x<69 or 75<=x<141))
                    if not inside:
                        self.assertEqual(a[y*w+x],b[y*w+x],(i,x,y))
                    elif a[y*w+x]>=11:
                        self.assertEqual(a[y*w+x],b[y*w+x],('bevel',i,x,y))
            self.assertNotEqual(a,b)
        once=list(arc.slots)
        self.assertEqual(p.patch_keyconfig(arc,stock.slots[548],stock.slots[347])['changed_slots'],[])
        self.assertEqual(arc.slots,once)
        broken=bytearray(arc.slots[359]);broken[20]^=1;arc.slots[359]=bytes(broken)
        before=list(arc.slots)
        with self.assertRaises(ValueError):p.patch_keyconfig(arc,stock.slots[548],stock.slots[347])
        self.assertEqual(before,arc.slots)

if __name__=='__main__': unittest.main()
