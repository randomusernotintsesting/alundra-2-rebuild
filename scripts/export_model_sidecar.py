"""Read a .blend into a background process and emit a new, inspectable sidecar.

No source save, artwork changes, baking or invented skinning. Run with Blender
--background --factory-startup --disable-autoexec --python-exit-code 1 --python
this_file.py -- SOURCE.blend NEW_DIRECTORY --collection NAME --asset-id PC00.
"""
import argparse
import hashlib
import json
import math
from pathlib import Path
import struct
import sys


class ArrayBlob:
    """Explicit little-endian arrays; descriptors use row counts, not scalars."""
    def __init__(self,path):
        self.file=Path(path).open('xb')

    def add(self,rows,dtype,components):
        codes={'f32':'f','u32':'I','i32':'i'}
        if dtype not in codes or components<1:raise ValueError('invalid array layout')
        rows=list(rows);values=[]
        for row in rows:
            row=list(row)
            if len(row)!=components:raise ValueError('array row width mismatch')
            for value in row:
                if dtype=='f32':
                    value=float(value)
                    if not math.isfinite(value):raise ValueError('nonfinite geometry')
                else:
                    if not isinstance(value,int):raise ValueError('noninteger index/attribute')
                    low,high=(0,2**32-1) if dtype=='u32' else (-2**31,2**31-1)
                    if not low<=value<=high:raise ValueError('integer attribute outside dtype')
                values.append(value)
        try:data=struct.pack('<'+str(len(values))+codes[dtype],*values)
        except (OverflowError,struct.error) as exc:raise ValueError('unrepresentable array') from exc
        offset=self.file.tell();self.file.write(data)
        return dict(offset=offset,count=len(rows),components=components,dtype=dtype,bytes=len(data))

    def close(self):self.file.close()


def sha(path):return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def json_value(value):
    if value is None or isinstance(value,(str,bool,int)):return value
    if isinstance(value,float):return value if math.isfinite(value) else {'nonfinite':str(value)}
    if hasattr(value,'to_dict'):return {str(k):json_value(v) for k,v in value.to_dict().items()}
    if hasattr(value,'to_list'):return json_value(value.to_list())
    if isinstance(value,dict):return {str(k):json_value(v) for k,v in value.items()}
    if isinstance(value,(tuple,list)) or hasattr(value,'__iter__'):
        try:return [json_value(v) for v in value]
        except TypeError:pass
    if hasattr(value,'name'):return {'name':value.name,'type':type(value).__name__}
    return {'unsupported_type':type(value).__name__}


def properties(block):return {k:json_value(block[k]) for k in block.keys() if k!='_RNA_UI'}


def rna_settings(block):
    result={}
    for prop in block.bl_rna.properties:
        name=prop.identifier
        if name=='rna_type' or prop.type not in {'BOOLEAN','INT','FLOAT','STRING','ENUM'}:continue
        try:result[name]=json_value(getattr(block,name))
        except (AttributeError,TypeError,ValueError):result[name]={'unreadable':True}
    return result


def matrix(value):return [[float(x) for x in row] for row in value]


def node_tree(tree,images,ancestors=()):
    if tree.name in ancestors:return {'recursive_reference':tree.name}
    result={'name':tree.name,'nodes':[],'links':[]}
    for node in tree.nodes:
        record={'name':node.name,'type':node.bl_idname,'settings':rna_settings(node),'properties':properties(node)}
        for direction in ('inputs','outputs'):
            record[direction]=[{'index':i,'name':socket.name,'identifier':socket.identifier,
                'type':socket.bl_idname,'default':json_value(getattr(socket,'default_value',None))}
                for i,socket in enumerate(getattr(node,direction))]
        image=getattr(node,'image',None)
        if image is not None:images[image.name]=image;record['image']=image.name
        nested=getattr(node,'node_tree',None)
        if nested:record['node_tree']=node_tree(nested,images,ancestors+(tree.name,))
        for name in ('texture_mapping','color_mapping'):
            if hasattr(node,name):record[name]=rna_settings(getattr(node,name))
        result['nodes'].append(record)
    for link in tree.links:
        result['links'].append({'from_node':link.from_node.name,'from_socket':link.from_socket.name,
            'from_identifier':link.from_socket.identifier,'to_node':link.to_node.name,
            'to_socket':link.to_socket.name,'to_identifier':link.to_socket.identifier})
    return result


def mesh_record(mesh,blob):
    mesh.calc_loop_triangles()
    result={'name':mesh.name,'properties':properties(mesh),'material_slots':[m.name if m else None for m in mesh.materials],
        'positions':blob.add((v.co for v in mesh.vertices),'f32',3),
        'loop_vertex':blob.add(([int(v.vertex_index)] for v in mesh.loops),'u32',1),
        'loop_normals':blob.add((v.vector for v in mesh.corner_normals),'f32',3),
        'triangle_vertices':blob.add((t.vertices for t in mesh.loop_triangles),'u32',3),
        'triangle_loops':blob.add((t.loops for t in mesh.loop_triangles),'u32',3),
        'triangle_polygons':blob.add(([int(t.polygon_index)] for t in mesh.loop_triangles),'u32',1),
        'triangle_material':blob.add(([int(t.material_index)] for t in mesh.loop_triangles),'u32',1),
        'polygon_loop_start':blob.add(([int(p.loop_start)] for p in mesh.polygons),'u32',1),
        'polygon_loop_total':blob.add(([int(p.loop_total)] for p in mesh.polygons),'u32',1),
        'uv_layers':{},'attributes':{},'vertex_group_weights':[]}
    for layer in mesh.uv_layers:result['uv_layers'][layer.name]=blob.add((v.uv for v in layer.data),'f32',2)
    layouts={'INT':('value','i32',1),'INT8':('value','i32',1),'FLOAT':('value','f32',1),
        'BOOLEAN':('value','u32',1),'FLOAT2':('vector','f32',2),'FLOAT_VECTOR':('vector','f32',3),
        'FLOAT_COLOR':('color','f32',4),'BYTE_COLOR':('color','f32',4),'INT32_2D':('value','i32',2)}
    for attribute in mesh.attributes:
        if attribute.name.startswith('.'):continue
        descriptor={'domain':attribute.domain,'blender_type':attribute.data_type}
        layout=layouts.get(attribute.data_type)
        if layout:
            field,dtype,width=layout
            rows=[]
            for item in attribute.data:
                value=getattr(item,field)
                rows.append([int(value) if dtype!='f32' else float(value)] if width==1 else value)
            descriptor['array']=blob.add(rows,dtype,width)
        else:descriptor['unsupported']=True
        result['attributes'][attribute.name]=descriptor
    for vertex in mesh.vertices:
        result['vertex_group_weights'].append([[int(g.group),float(g.weight)] for g in vertex.groups])
    if len(mesh.corner_normals)!=len(mesh.loops):raise ValueError('corner normal count mismatch')
    return result


def export_image(image,index,output,blob):
    record={'name':image.name,'source':image.source,'filepath':image.filepath,
        'size':list(image.size),'channels':image.channels,'alpha_mode':image.alpha_mode,
        'colorspace':image.colorspace_settings.name,'is_float':image.is_float,'files':[]}
    packed=list(image.packed_files)
    entries=[(item.filepath,item.packed_file) for item in packed]
    if not entries and image.packed_file:entries=[(image.filepath,image.packed_file)]
    for n,(name,packed_file) in enumerate(entries):
        data=bytes(packed_file.data)
        extension='.png' if data.startswith(b'\x89PNG\r\n\x1a\n') else '.jpg' if data.startswith(b'\xff\xd8') else '.bin'
        filename=f'images/image-{index:03d}-{n:02d}{extension}'
        with (output/filename).open('xb') as stream:stream.write(data)
        record['files'].append({'file':filename,'original_path':name,'bytes':len(data),
            'sha256':hashlib.sha256(data).hexdigest(),'encoding':'original packed bytes'})
    if not entries:
        # Preserve Blender's decoded float values, without color transforms or
        # quantization. No image is resaved or unpacked beside the source file.
        pixels=list(image.pixels)
        record['decoded_pixels']=blob.add(([v] for v in pixels),'f32',1)
        record['decoded_layout']='Blender linear pixel buffer, bottom row first; channels as reported'
    return record


def export_blend(source,output,collection_name,asset_id):
    import bpy
    source=Path(source).resolve();output=Path(output).resolve()
    if output.exists():raise FileExistsError(output)
    before=sha(source)
    bpy.ops.wm.open_mainfile(filepath=str(source),load_ui=False,use_scripts=False)
    collection=bpy.data.collections.get(collection_name)
    if collection is None:raise ValueError('selected collection is missing: '+collection_name)
    objects=sorted(collection.all_objects,key=lambda o:o.name)
    if not any(o.type=='MESH' for o in objects):raise ValueError('selected collection has no meshes')
    output.mkdir(parents=True,exist_ok=False);(output/'images').mkdir()
    blob=ArrayBlob(output/'arrays.bin');images={};materials={};depsgraph=bpy.context.evaluated_depsgraph_get()
    scene=bpy.context.scene
    result={'format':'a2-blender-sidecar-v1','asset_id':asset_id,'source':str(source),'source_sha256':before,
        'blender_version':bpy.app.version_string,'blender_build_hash':bpy.app.build_hash.decode(),
        'collection':collection_name,'scene':scene.name,'frame':scene.frame_current,
        'units':rna_settings(scene.unit_settings),'array_file':'arrays.bin','byte_order':'little',
        'coordinate_contract':'Unmodified Blender local positions; row-major matrices act on column vectors. No normalization or inferred inverse bind.',
        'color_contract':'Color attributes are Blender linear values; UV coordinates remain unchanged; packed image bytes and color-space labels are preserved.',
        'runtime_ready':False,'skinning_inferred':False,'objects':[],'materials':[],'images':[],
        'limitations':['No skeleton, weights or animation binding is inferred.',
            'Shader graphs are descriptions, not an implemented runtime material mapping.',
            'Current frame only; authored chest preview keys are not native animation.']}
    try:
        for obj in objects:
            item={'name':obj.name,'type':obj.type,'parent':obj.parent.name if obj.parent else None,
                'parent_type':obj.parent_type,'parent_bone':obj.parent_bone,
                'properties':properties(obj),'collections':[c.name for c in obj.users_collection],
                'matrix_world':matrix(obj.matrix_world),'matrix_local':matrix(obj.matrix_local),
                'matrix_basis':matrix(obj.matrix_basis),'matrix_parent_inverse':matrix(obj.matrix_parent_inverse),
                'vertex_groups':[{'index':g.index,'name':g.name} for g in obj.vertex_groups],
                'modifiers':[{'name':m.name,'type':m.type,'settings':rna_settings(m)} for m in obj.modifiers]}
            if obj.type in {'MESH','CURVE','SURFACE','FONT','META'}:
                if obj.type=='MESH':item['source_mesh']=mesh_record(obj.data,blob)
                evaluated=obj.evaluated_get(depsgraph)
                item['evaluated_matrix_world']=matrix(evaluated.matrix_world)
                mesh=evaluated.to_mesh(preserve_all_data_layers=True,depsgraph=depsgraph)
                try:
                    item['evaluated_mesh']=mesh_record(mesh,blob)
                    for material in list(mesh.materials)+list(obj.data.materials):
                        if material:materials[material.name]=material
                finally:evaluated.to_mesh_clear()
            result['objects'].append(item)
        for name,material in sorted(materials.items()):
            record={'name':name,'properties':properties(material),'settings':rna_settings(material),'runtime_shader_ready':False}
            if material.use_nodes:record['node_tree']=node_tree(material.node_tree,images)
            result['materials'].append(record)
        result['images']=[export_image(image,i,output,blob) for i,(_,image) in enumerate(sorted(images.items()))]
        ancestors={}
        for obj in objects:
            parent=obj.parent
            while parent:
                ancestors[parent.name]={'name':parent.name,'type':parent.type,'parent':parent.parent.name if parent.parent else None,
                    'matrix_world':matrix(parent.matrix_world),'matrix_local':matrix(parent.matrix_local),'properties':properties(parent)}
                parent=parent.parent
        result['ancestors']=list(ancestors.values())
        result['scene_object_inventory']=[{'name':o.name,'type':o.type,'properties':properties(o),
            'collections':[c.name for c in o.users_collection]} for o in scene.objects]
    finally:blob.close()
    result['array_sha256']=sha(output/'arrays.bin');result['array_bytes']=(output/'arrays.bin').stat().st_size
    result['source_sha256_after']=sha(source)
    if result['source_sha256_after']!=before:raise RuntimeError('source changed during export')
    result['summary']={'meshes':sum('evaluated_mesh' in o for o in result['objects']),
        'vertices':sum(o['evaluated_mesh']['positions']['count'] for o in result['objects'] if 'evaluated_mesh' in o),
        'triangles':sum(o['evaluated_mesh']['triangle_vertices']['count'] for o in result['objects'] if 'evaluated_mesh' in o),
        'materials':len(result['materials']),'images':len(result['images'])}
    with (output/'asset.json').open('x',encoding='utf-8') as stream:json.dump(result,stream,ensure_ascii=False,indent=2,allow_nan=False)
    return result


def main():
    args=sys.argv[sys.argv.index('--')+1:] if '--' in sys.argv else sys.argv[1:]
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source',type=Path);parser.add_argument('output',type=Path)
    parser.add_argument('--collection',required=True);parser.add_argument('--asset-id',required=True)
    options=parser.parse_args(args)
    result=export_blend(options.source,options.output,options.collection,options.asset_id)
    print(json.dumps({'output':str(options.output),'source_sha256':result['source_sha256'],**result['summary']}))


if __name__=='__main__':main()
