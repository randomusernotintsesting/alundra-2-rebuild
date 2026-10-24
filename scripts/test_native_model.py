import struct
import unittest

from a2.native_model import pack_model


def triangle_model():
    identity=[1.,0,0,0,0,1.,0,0,0,0,1.,0,0,0,0,1.]
    return dict(source_key='T02',source_sha256=bytes([0x21])*32,source_variant=0,
        bounds=[0,0,0,1,1,0], index_width=2,
        vertices=[dict(position=p,normal=[0,0,1],uv=[[0,0],[0,0]],color=[[1]*4,[1]*4],
                       joints=[0]*4,weights=[1,0,0,0]) for p in ([0,0,0],[1,0,0],[0,1,0])],
        indices=[0,1,2],
        materials=[dict(kind=0,alpha_mode=0,texture=[0,None],base_color=[1]*4,roughness=.5,
            metallic=0,alpha_cutoff=0,opacity=1,specular=.5,ior=1.45,coat=0,coat_roughness=0,
            flags=0,roughness_min=0,roughness_max=0,name='wood')],
        joints=[dict(source_id=0,parent=None,flags=1,bind=identity,inverse_bind=identity)],
        submeshes=[dict(first_index=0,index_count=3,material=0,source_part=0,bounds=[0,0,0,1,1,0])],
        textures=[dict(width=2,height=2,flags=1,rgba=bytes([255,0,0,255,0,255,0,255,0,0,255,255,255,255,255,255]))])


class NativeModelTests(unittest.TestCase):
    def test_wire_offsets_and_values(self):
        b=pack_model(triangle_model())
        self.assertEqual(len(b),920)
        self.assertEqual(b[:8],b'A2M2\0\0\0\0')
        self.assertEqual(struct.unpack_from('<8Q',b,64),(256,544,552,680,824,872,904,16))
        self.assertEqual(struct.unpack_from('<3H',b,544),(0,1,2))
        self.assertEqual(struct.unpack_from('<I',b,564),(0xffffffff,))
        self.assertEqual(b[632:637],b'wood\0')
        self.assertEqual(struct.unpack_from('<f',b,352),(1.,))
        self.assertEqual(b[904:],triangle_model()['textures'][0]['rgba'])

    def test_signed_corner_rgb_explicit_flag_and_exact_binary32(self):
        m=triangle_model();m['file_flags']=1
        m['vertices'][0]['color']=[[-16,.25,16,1],[-.07422932237386703,1.0063167810440063,.5,0]]
        b=pack_model(m)
        self.assertEqual(struct.unpack_from('<I',b,24),(1,))
        self.assertEqual(b[296:328],struct.pack('<8f',*(m['vertices'][0]['color'][0]+m['vertices'][0]['color'][1])))
        m.pop('file_flags')
        with self.assertRaises(ValueError):pack_model(m)

    def test_signed_flag_does_not_relax_alpha_materials_or_finiteness(self):
        for layer,channel,value in [(0,0,-16.01),(1,2,16.01),(0,1,float('nan')),(1,0,float('inf')),(0,3,-.001),(1,3,1.001)]:
            m=triangle_model();m['file_flags']=1;m['vertices'][0]['color'][layer][channel]=value
            with self.assertRaises(ValueError):pack_model(m)
        m=triangle_model();m['file_flags']=1;m['materials'][0]['base_color'][0]=-.1
        with self.assertRaises(ValueError):pack_model(m)
        for flags in [2,3,0xffffffff,-1,True]:
            m=triangle_model();m['file_flags']=flags
            with self.assertRaises(ValueError):pack_model(m)

    def test_default_flags_preserve_old_wire_bytes(self):
        m=triangle_model();before=pack_model(m);m['file_flags']=0
        self.assertEqual(pack_model(m),before)
        self.assertEqual(before[24:28],bytes(4))

    def test_u32_indices_and_empty_texture_section(self):
        m=triangle_model();m['index_width']=4;m['textures']=[];m['materials'][0]['texture']=[None,None]
        b=pack_model(m)
        self.assertEqual(struct.unpack_from('<I',b,56),(4,))
        self.assertEqual(struct.unpack_from('<3I',b,544),(0,1,2))
        self.assertEqual(struct.unpack_from('<Q',b,120),(0,))

    def test_reject_nonfinite_and_invalid_identity(self):
        for field,value in [('source_key','T02\0hidden'),('source_sha256',bytes(32))]:
            m=triangle_model();m[field]=value
            with self.assertRaises(ValueError):pack_model(m)
        m=triangle_model();m['vertices'][0]['position'][0]=float('nan')
        with self.assertRaises(ValueError):pack_model(m)

    def test_reject_truncated_pixels_or_bad_joint(self):
        m=triangle_model();m['textures'][0]['rgba']=b'\0'
        with self.assertRaises(ValueError):pack_model(m)

    def test_reject_singular_inverse_with_large_canceling_products(self):
        m=triangle_model();j=m['joints'][0]
        j['bind']=list(j['bind']);j['inverse_bind']=list(j['inverse_bind'])
        for r in range(2):
            for c in range(2):
                j['bind'][r*4+c]=1000
                j['inverse_bind'][r*4+c]=1000 if r==c else -1000
        with self.assertRaises(ValueError):pack_model(m)
        m=triangle_model();m['vertices'][0]['joints'][0]=1
        with self.assertRaises(ValueError):pack_model(m)


if __name__=='__main__':unittest.main()
