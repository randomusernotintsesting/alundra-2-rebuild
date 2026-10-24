"""Read the approved Flint snapshot; export original packed images and node graphs.
Run in background Blender with --disable-autoexec. Never saves the source blend.
"""
import argparse
import json
from pathlib import Path
import sys

sys.path.insert(0,str(Path(__file__).resolve().parent))
from export_model_sidecar import ArrayBlob,export_image,node_tree,properties,rna_settings,sha
from a2.animation_bridge import inverse,transform

APPROVED='c1d63fd792193fb53991167a4d2b2266122e7a5752d311b4b775e1a7c4f21d47'


def export(source,handoff,output):
    import bpy
    source=Path(source).resolve();handoff=Path(handoff).resolve();output=Path(output).resolve()
    before=sha(source)
    if before!=APPROVED:raise ValueError('not the approved animation snapshot')
    data=json.loads(handoff.read_text())
    if data['schema']!='a2.modern_flint_skin_preview.v5':raise ValueError('expected v5 handoff')
    if output.exists():raise ValueError('output must be a new directory')
    bpy.ops.wm.open_mainfile(filepath=str(source),load_ui=False,use_scripts=False)
    scene=bpy.data.scenes.get('SOURCE ACTIONS / Flint / editable rig')
    if scene is None:raise ValueError('approved editable scene missing')
    objects={}
    for obj in scene.objects:
        if obj.type=='MESH' and 'rig_source_object' in obj and any(m.type=='ARMATURE' for m in obj.modifiers):
            name=obj['rig_source_object']
            if name in objects:raise ValueError('duplicate authored object')
            objects[name]=obj
    if set(objects)!={m['name'] for m in data['meshes']}:raise ValueError('mesh inventory differs: '+repr({'actual_only':set(objects)-{m['name'] for m in data['meshes']},'missing':{m['name'] for m in data['meshes']}-set(objects)}))
    inv=inverse([x for row in data['actor_to_preview_reference'] for x in row])
    proof=[];materials={}
    for mesh in data['meshes']:
        obj=objects[mesh['name']];src=obj.data
        if len(src.vertices)!=len(mesh['vertices_actor_bind']):raise ValueError('vertex count changed')
        error=max(abs(a-b) for v,expected in zip(src.vertices,mesh['vertices_actor_bind']) for a,b in zip(transform(inv,list(v.co)),expected))
        if error>1e-5:raise ValueError('approved geometry differs from v5 actor-bind geometry')
        if [list(p.vertices) for p in src.polygons]!=mesh['triangles']:raise ValueError('topology changed')
        if [p.material_index for p in src.polygons]!=mesh['triangle_materials']:raise ValueError('material assignment changed')
        if [m.name for m in src.materials]!=mesh['materials']:raise ValueError('material slots changed')
        if set(mesh['uv_layers'])!={uv.name for uv in src.uv_layers}:raise ValueError('UV layers differ')
        for name,values in mesh['uv_layers'].items():
            if len(values)!=len(src.uv_layers[name].data) or any(abs(a-b)>1e-7 for v,w in zip(src.uv_layers[name].data,values) for a,b in zip(v.uv,w)):raise ValueError('UV values differ')
        for name,attr in mesh['color_attributes'].items():
            actual=src.color_attributes.get(name)
            if actual is None or actual.domain!=attr['domain'] or len(actual.data)!=len(attr['values']):raise ValueError('color layout differs')
            if any(abs(a-b)>1e-7 for v,w in zip(actual.data,attr['values']) for a,b in zip(v.color,w)):raise ValueError('color values differ')
        arm=[m.object for m in obj.modifiers if m.type=='ARMATURE']
        if len(arm)!=1:raise ValueError('expected one armature')
        weight_error=0
        for v,wanted in zip(src.vertices,mesh['skin_driver_weights']):
            actual={}
            for group in v.groups:
                idx=arm[0].data.bones[obj.vertex_groups[group.group].name].get('source_mesh_index')
                if idx is None:raise ValueError('weight has no source driver')
                actual[idx]=actual.get(idx,0)+group.weight
            total=sum(actual.values());actual={i:w/total for i,w in actual.items()}
            if set(actual)!=dict(wanted).keys():raise ValueError('weight driver changed')
            weight_error=max(weight_error,max(abs(actual[i]-w) for i,w in wanted))
        if weight_error>1e-7:raise ValueError('weights differ from v5')
        proof.append({'name':mesh['name'],'position_error':error,'weight_error':weight_error,'vertices':len(src.vertices),'triangles':len(src.polygons)})
        for mat in src.materials:materials[mat.name]=mat
    images={};records=[]
    for name,mat in sorted(materials.items()):
        if not mat.use_nodes or mat.node_tree is None:raise ValueError('material has no node graph')
        records.append({'name':name,'properties':properties(mat),'settings':rna_settings(mat),'node_tree':node_tree(mat.node_tree,images)})
    output.mkdir(parents=True);(output/'images').mkdir();blob=ArrayBlob(output/'arrays.bin')
    try:image_records=[export_image(img,i,output,blob) for i,(name,img) in enumerate(sorted(images.items()))]
    finally:blob.close()
    after=sha(source)
    if after!=before:raise ValueError('source changed during read')
    result={'format':'a2-flint-surfaces-v1','source':str(source),'source_sha256':before,'source_sha256_after':after,
            'handoff':str(handoff),'handoff_sha256':sha(handoff),'blender_version':bpy.app.version_string,
            'scene':scene.name,'geometry_verified':True,'geometry_proof':proof,'materials':records,'images':image_records}
    (output/'surfaces.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps({'output':str(output),'meshes':len(proof),'materials':len(records),'images':len(image_records),'source_unchanged':True}))


if __name__=='__main__':
    parser=argparse.ArgumentParser();parser.add_argument('--source',required=True);parser.add_argument('--handoff',required=True);parser.add_argument('--output',required=True)
    args=parser.parse_args(sys.argv[sys.argv.index('--')+1:] if '--' in sys.argv else None)
    export(args.source,args.handoff,args.output)
