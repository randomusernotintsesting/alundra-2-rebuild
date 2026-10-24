"""Portable contract tests: preserved bind geometry/corner seams and typed drivers."""
import struct
import copy
import unittest
import tempfile
import json
from pathlib import Path

import cook_native_flint as cook
from a2.native_model import pack_model


def node(name,kind,inputs=(),settings=None):
    return {'name':name,'type':kind,'settings':settings or {},'inputs':[{'name':k,'default':v} for k,v in inputs]}


def material():
    return {'name':'Original fixture','node_tree':{'nodes':[
        node('out','ShaderNodeOutputMaterial'),node('color','ShaderNodeVertexColor',settings={'layer_name':'A2CornerColor0'}),
        node('emit','ShaderNodeEmission',[('Strength',1)])],
        'links':[{'from_node':'color','from_socket':'Color','to_node':'emit','to_socket':'Color'},
                 {'from_node':'emit','from_socket':'Emission','to_node':'out','to_socket':'Surface'}]}}


def fixture():
    identity=[[float(i==j) for j in range(4)] for i in range(4)]
    bind=copy.deepcopy(identity);bind[0][3]=12.5
    inv=copy.deepcopy(identity);inv[0][3]=-12.5
    d={'schema':'a2.modern_flint_skin_preview.v5','skinning':'linear','bind_frame':2999,
       'source_asset':{'asset_id':'PC00','variant':0,'mesh':{'sha256':cook.SOURCE_SHA}},
       'actor_to_preview_reference':identity,'parts':[{'source_mesh_index':i,'bind':bind,'inverse_bind':inv} for i in range(16)],
       'derived_drivers':[{'driver_index':i,'native':False,'name':name,'bind':identity,'inverse_bind':identity}
                          for i,name in [(16,'shield_mount'),(17,'sole_contact.R'),(18,'sole_contact.L')]],
       'floor_clearance_tracks':{'walk':[{'time':0,'actor_delta':[0,0,0]}]},'clips':{},'authoring_bones':[],
       'meshes':[{'name':'fixture','vertices_actor_bind':[[1,2,3],[4,2,3],[1,5,3],[4,5,3]],
        'skin_driver_weights':[[[16,.25],[17,.75]],[[0,1]],[[18,1]],[[3,1]]],
        'triangles':[[0,1,2],[1,3,2]],'triangle_materials':[0,0],
        'corner_normals_actor_bind':[[0,0,1]]*6,
        'uv_layers':{'A2UV0':[[0,0],[1,0],[0,1],[.2,.3],[1,1],[0,1]],'A2UV1':[[.3,.4]]*6},
        'color_attributes':{'A2CornerColor0':{'domain':'CORNER','data_type':'FLOAT_COLOR','values':[[.2,.3,.4,1]]*6},
                            'A2CornerColor1':{'domain':'CORNER','data_type':'FLOAT_COLOR','values':[[.7,.6,.5,1]]*6}},
        'materials':['Original fixture'],'rigid_attachment':None}]}
    b={'format':'a2-flint-surfaces-v1','source_sha256':cook.APPROVED_BLEND_SHA,'source_sha256_after':cook.APPROVED_BLEND_SHA,
       'materials':[material()],'images':[],'geometry_verified':True}
    return d,b


class CookFlintTests(unittest.TestCase):
    def test_preserves_bind_space_and_all_driver_slots(self):
        d,b=fixture();m,e=cook.cook_model(d,b,None)
        self.assertEqual([j['source_id'] for j in m['joints']],list(range(19)))
        self.assertEqual(m['vertices'][0]['position'],[1,2,3]) # no B or presentation applied twice
        self.assertEqual(m['vertices'][0]['joints'][:2],[16,17]);self.assertEqual(m['vertices'][0]['weights'][:2],[.25,.75])
        self.assertEqual(e['derived_drivers'],d['derived_drivers']);self.assertEqual(e['floor_clearance_tracks'],d['floor_clearance_tracks'])
        self.assertFalse(e['runtime_ready']);self.assertEqual(pack_model(m)[:8],b'A2M2\0\0\0\0')

    def test_corner_seams_colors_and_one_uv_flip(self):
        d,b=fixture();m,_=cook.cook_model(d,b,None)
        a=m['vertices'][m['indices'][1]];other=m['vertices'][m['indices'][3]]
        self.assertEqual(a['position'],other['position']);self.assertNotEqual(a['uv'],other['uv'])
        self.assertEqual(other['uv'][0],[.2,.7]);self.assertEqual(other['uv'][1],[.3,.6])
        self.assertEqual(a['color'],[[.2,.3,.4,1],[.7,.6,.5,1]])

    def test_rejects_unknown_driver_or_bad_weights(self):
        for weights in ([[[19,1]]],[[[0,.2]]],[[[0,-.1],[1,1.1]]],[[[0,1],[0,0]]]):
            d,b=fixture();d['meshes'][0]['skin_driver_weights'][0]=weights[0]
            with self.assertRaises(ValueError):cook.cook_model(d,b,None)

    def test_rejects_duplicate_native_id_or_derived_bind_change(self):
        d,b=fixture();d['parts'][1]['source_mesh_index']=0
        with self.assertRaises(ValueError):cook.cook_model(d,b,None)
        d,b=fixture();d['derived_drivers'][0]['bind'][0][3]=1
        with self.assertRaises(ValueError):cook.cook_model(d,b,None)

    def test_rejects_bad_topology_normals_and_unknown_layers(self):
        for change in ('index','normal','uv'):
            d,b=fixture();mesh=d['meshes'][0]
            if change=='index':mesh['triangles'][0][0]=90
            if change=='normal':mesh['corner_normals_actor_bind'][0]=[0,0,0]
            if change=='uv':mesh['uv_layers']['Unexpected']=[[0,0]]*6
            with self.assertRaises(ValueError):cook.cook_model(d,b,None)

    def test_requires_approved_surface_proof_and_supported_graph(self):
        d,b=fixture();b['source_sha256']='0'*64
        with self.assertRaises(ValueError):cook.cook_model(d,b,None)
        d,b=fixture();b['materials'][0]['node_tree']['nodes'].append(node('unsupported','ShaderNodeNoiseTexture'))
        with self.assertRaises(ValueError):cook.cook_model(d,b,None)

    def test_signed_rgb_explicit_binary_preserves_float32(self):
        d,b=fixture();d['meshes'][0]['color_attributes']['A2CornerColor0']['values'][0]=[-.075,1.006,.2,1]
        m,e=cook.cook_model(d,b,None)
        self.assertEqual(m['vertices'][0]['color'][0],[-.075,1.006,.2,1])
        self.assertEqual(m['file_flags'],1);self.assertTrue(e['requires_signed_corner_rgb'])
        binary=pack_model(m)
        self.assertEqual(binary[296:312],struct.pack("<4f",-.075,1.006,.2,1))
        with tempfile.TemporaryDirectory() as tmp:
            out=Path(tmp)/'new';cook.write_cooked(out,m,e)
            self.assertEqual((out/'PC00.A2M').read_bytes(),binary)
            self.assertEqual(json.loads((out/'PC00.model.json').read_text())['vertices'][0]['color'][0],[-.075,1.006,.2,1])
            with self.assertRaises(ValueError):cook.write_cooked(out,m,e)

    def test_signed_color_limits_and_substantive_alpha_reject(self):
        for value in ([-16.01,0,0,1],[0,16.01,0,1],[0,0,float('nan'),1],[0,0,0,1.006]):
            d,b=fixture();d['meshes'][0]['color_attributes']['A2CornerColor0']['values'][0]=value
            with self.assertRaises(ValueError):cook.cook_model(d,b,None)

    def test_unknown_emission_link_is_not_silently_approximated(self):
        d,b=fixture();b['materials'][0]['node_tree']['links'][0]['from_socket']='Alpha'
        with self.assertRaises(ValueError):cook.cook_model(d,b,None)

    def test_deterministic_and_does_not_mutate_inputs(self):
        d,b=fixture();original=copy.deepcopy((d,b));m,e=cook.cook_model(d,b,None)
        self.assertEqual((d,b),original);self.assertEqual(pack_model(m),pack_model(cook.cook_model(d,b,None)[0]))

if __name__=='__main__':unittest.main()
