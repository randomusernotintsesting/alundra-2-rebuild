"""Small real bpy fixture; run in a separate --background --factory-startup process."""
import unittest
if __name__ != '__main__':
    raise unittest.SkipTest('Dedicated Blender background fixture; not a CPython discovery test')
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import tempfile
import bpy
if not bpy.app.background:
    raise RuntimeError('This fixture requires a separate Blender --background process')

path=Path(__file__).with_name('export_model_sidecar.py')
assert path.is_file(), 'model sidecar exporter has not been implemented'
spec=importlib.util.spec_from_file_location('sidecar',path)
module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)

with tempfile.TemporaryDirectory(prefix='a2-sidecar-fixture-') as temp:
    root=Path(temp);source=root/'fixture.blend';output=root/'export'
    bpy.ops.wm.read_factory_settings(use_empty=True)
    collection=bpy.data.collections.new('Fixture');bpy.context.scene.collection.children.link(collection)
    parent=bpy.data.objects.new('Actual parent',None);bpy.context.scene.collection.objects.link(parent)
    parent.location=(3,4,5)
    mesh=bpy.data.meshes.new('UV seam mesh')
    mesh.from_pydata([(1,0,0),(2,0,0),(2,1,0),(1,1,0)],[],[(0,1,2),(0,2,3)])
    uv=mesh.uv_layers.new(name='Source UV')
    coordinates=[(0,0),(1,0),(1,1),(.25,.25),(.75,.75),(0,1)]
    for loop,value in zip(uv.data,coordinates):loop.uv=value
    colors=mesh.color_attributes.new(name='Paint',type='FLOAT_COLOR',domain='CORNER')
    for n,c in enumerate(colors.data):c.color=(n/8,.25,.5,1)
    attr=mesh.attributes.new('native_source_face','INT','FACE')
    attr.data[0].value=7;attr.data[1].value=9
    obj=bpy.data.objects.new('Fixture mesh',mesh);collection.objects.link(obj);obj.parent=parent
    obj.location=(0,2,0);obj['source_mesh_index']=1
    modifier=obj.modifiers.new('Evaluated mirror','MIRROR');modifier.use_clip=False
    image=bpy.data.images.new('Packed fixture',width=2,height=2,alpha=True)
    image.pixels=[1,.5,0,1]*4;image.pack()
    packed=bytes(image.packed_file.data)
    material=bpy.data.materials.new('Graph material');material.use_nodes=True
    texture=material.node_tree.nodes.new('ShaderNodeTexImage');texture.image=image
    material.node_tree.links.new(texture.outputs['Color'],material.node_tree.nodes.get('Principled BSDF').inputs['Base Color'])
    mesh.materials.append(material)
    bpy.context.view_layer.update();bpy.ops.wm.save_as_mainfile(filepath=str(source))
    before=hashlib.sha256(source.read_bytes()).hexdigest()
    module.export_blend(source,output,'Fixture','FIXTURE')
    data=json.loads((output/'asset.json').read_text());blob=(output/'arrays.bin').read_bytes()
    obj=next(x for x in data['objects'] if x['name']=='Fixture mesh')
    def read(desc):
        code={'f32':'f','u32':'I','i32':'i'}[desc['dtype']]
        return struct.unpack_from('<'+str(desc['count']*desc['components'])+code,blob,desc['offset'])
    assert obj['properties']['source_mesh_index']==1
    assert obj['parent']=='Actual parent'
    assert [obj['matrix_world'][i][3] for i in range(3)]==[3,6,5]
    assert obj['source_mesh']['positions']['count']==4
    assert obj['evaluated_mesh']['positions']['count']==8
    assert obj['evaluated_mesh']['triangle_vertices']['count']==4
    uv=read(obj['source_mesh']['uv_layers']['Source UV'])
    assert uv[0:2]==(0,0) and uv[6:8]==(.25,.25), 'shared vertex lost its UV seam'
    assert read(obj['source_mesh']['attributes']['native_source_face']['array'])==(7,9)
    assert any(link['to_socket']=='Base Color' for m in data['materials'] for link in m['node_tree']['links'])
    exported=data['images'][0]['files'][0]
    assert (output/exported['file']).read_bytes()==packed
    assert hashlib.sha256(source.read_bytes()).hexdigest()==before
    try:module.export_blend(source,output,'Fixture','FIXTURE')
    except FileExistsError:pass
    else:raise AssertionError('existing output directory was overwritten')
    assert hashlib.sha256(source.read_bytes()).hexdigest()==before
    print('PASS: evaluated geometry, source mesh, UV seam, face IDs, transforms, shader graph, packed image bytes and no replacement')
