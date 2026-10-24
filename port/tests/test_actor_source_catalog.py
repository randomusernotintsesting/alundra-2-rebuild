"""Source descriptor validation at resource boundaries, independent literals."""
import hashlib
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from build_actor_source_catalog import describe, grp_mesh_ranges, canonicalize

def sample(two=False):
    # One original native mesh, one quad and four 16-byte vertex records.
    end=408 if two else 372
    b=bytearray(end+64)
    b[:5]=b'TEST\0'
    struct.pack_into('<2I',b,32,304,0xffffffff)
    struct.pack_into('<I',b,300,1)
    struct.pack_into('<HH',b,318,1,4)
    struct.pack_into('<I',b,324,end)
    struct.pack_into('<H',b,328,4 if two else 0)
    b[332:336]=bytes([0,1,2,3])
    struct.pack_into('<I',b,336,0x38808080)
    if two:struct.pack_into('<I',b,372,0x3c808080)
    return b

class DescriptorTests(unittest.TestCase):
    def test_grp_native_object_table_boundaries(self):
        mesh=sample()+bytes(4)
        b=bytearray(80+len(mesh)+32)
        struct.pack_into('<I',b,0,28)
        struct.pack_into('<H',b,28,417)
        struct.pack_into('<I',b,28+28,80)
        struct.pack_into('<I',b,28+32,80+len(mesh))
        struct.pack_into('<H',b,72,0xffff)
        b[80:80+len(mesh)]=mesh
        self.assertEqual(grp_mesh_ranges(b),[(80,80+len(mesh))])
        struct.pack_into('<I',b,28+28,len(b)+4)
        with self.assertRaises(ValueError):grp_mesh_ranges(b)
    def test_exact_boundaries_and_full_hash(self):
        for two in (False,True):
            b=sample(two);d=describe(b)
            self.assertEqual((d['key'],d['parts'],d['header'],d['faces'],d['vertices']),('TEST',1,[304],[1],[4]))
            self.assertEqual(d['bytes'],len(b))
            self.assertEqual(d['hash'],hashlib.sha256(b).hexdigest())
            b[-1]=91
            self.assertNotEqual(describe(b)['hash'],d['hash'])

    def test_final_grp_mesh_bounded_only_by_next_list(self):
        mesh=sample()+bytes(4)
        end=80+len(mesh)
        b=bytearray(end+64)
        struct.pack_into('<2I',b,0,28,end)
        struct.pack_into('<H',b,28,417)
        struct.pack_into('<I',b,56,80)
        struct.pack_into('<H',b,72,0xffff)
        b[80:end]=mesh
        self.assertEqual(grp_mesh_ranges(b),[(80,end)])
        self.assertEqual(describe(b[80:end],embedded=True)['bytes'],len(mesh))

    def test_alias_requires_independent_complete_resource(self):
        raw=sample();pak=describe(raw);grp=describe(raw+bytes(4),embedded=True)
        self.assertEqual(canonicalize([grp]),([grp],[]))
        for order in ([pak,grp],[grp,pak]):
            ds,aliases=canonicalize(order)
            self.assertEqual(ds,[pak])
            self.assertEqual(aliases,[dict(key='TEST',source_hash=grp['hash'],canonical_hash=pak['hash'],geometry_bytes=len(raw))])
        changed=bytearray(raw);changed[-1]=1
        other=describe(changed)
        ds,aliases=canonicalize([other,grp])
        self.assertEqual(len(ds),2)
        self.assertEqual(aliases,[])

    def test_bounded_embedded_resource(self):
        b=sample()
        self.assertEqual(describe(b+bytes(4)+b'NEXT',embedded=True)['bytes'],len(b)+4)
        with self.assertRaises(ValueError):describe(b+b'NEXT',embedded=True)
        with self.assertRaises(ValueError):describe(b+b'NEXT')
        with self.assertRaises(ValueError):describe(b[:-1],embedded=True)

    def test_pointers_counts_layers_and_relocation_state(self):
        for offset,kind,value in [(31,'B',1),(32,'I',308),(36,'I',0),(300,'I',33),(324,'I',368),(318,'H',2),(319,'B',255)]:
            b=sample();struct.pack_into('<'+kind,b,offset,value)
            with self.subTest(offset=offset), self.assertRaises(ValueError):describe(b)
        b=sample(True);struct.pack_into('<I',b,372,0x34808080)
        with self.assertRaises(ValueError):describe(b)
        b=sample();struct.pack_into('<I',b,336,0x20808080)
        with self.assertRaises(ValueError):describe(b)

    def test_byte_indices_are_preserved_not_reinterpreted(self):
        # Native projected slots can refer beyond this part's own vertices.
        # Actual projection provenance is a separate runtime admission gate.
        b=sample();b[333]=81
        with self.assertRaises(ValueError):describe(b)
        b[372+3*16+12]=81  # Last source vertex publishes shared slot81.
        d=describe(b)
        self.assertEqual(d['nonlocal_index_faces'],1)
        self.assertEqual(d['hash'],hashlib.sha256(b).hexdigest())
        b=sample();b[333]=5
        with self.assertRaises(ValueError):describe(b)
        b=sample();b[372+12]=59
        with self.assertRaises(ValueError):describe(b)

if __name__=='__main__':unittest.main()
