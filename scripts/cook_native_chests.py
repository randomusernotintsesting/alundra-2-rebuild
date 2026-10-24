#!/usr/bin/env python3
"""Cook approved evaluated chest sidecars into common native actor bind space.

Never opens or saves Blender. All source positions/triangles/corner attributes are
preserved through documented coordinate changes. The supplied bind is an observed
native pose, not the authored Blender hinge animation.
"""
import argparse
import hashlib
import json
import math
from pathlib import Path
import struct

from a2.animation_bridge import inverse, multiply, transform

IDENTITY=[1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1]
BASIS=[100,0,0,0,0,0,-100,0,0,100,0,0,0,0,0,1]
SOURCE_HASHES={'T02':'fbbc6ed20a3fc8cf8ac69e1c1af74a8ae44d451fcfbb47302321c1182fefabf1',
               'T03':'d77d72f180a3f84691f40bdcade2a20195de67855e71e71ef4470e55857805be'}

def require(ok,message):
    if not ok:raise ValueError(message)

def finite(values,n):
    require(len(values)==n and all(isinstance(x,(int,float)) and math.isfinite(x) for x in values),'invalid finite vector')
    return list(values)

def flat(matrix):
    values=[x for row in matrix for x in row] if len(matrix)==4 and isinstance(matrix[0],list) else matrix
    values=finite(values,16);require(values[12:]==[0,0,0,1],'nonaffine matrix');return values

def sha(path):return hashlib.sha256(Path(path).read_bytes()).hexdigest()

def authored_shifts(source):
    bottom=max(v[1] for v in source['parts'][0]['vertices'])
    return [[0,0,bottom/100],[0,.27,(bottom+22)/100]]

def cook_position(vertex,world,shift,bind):
    w=transform(flat(world),finite(vertex,3));shift=finite(shift,3)
    local=transform(BASIS,[w[i]-shift[i] for i in range(3)])
    return transform(flat(bind),local)

def cook_normal(normal,world,bind):
    n=finite(normal,3);total=multiply(flat(bind),multiply(BASIS,flat(world)))
    inv=inverse(total);out=[sum(inv[j*4+i]*n[j] for j in range(3)) for i in range(3)]
    length=math.sqrt(sum(x*x for x in out));require(length>1e-20,'zero or degenerate normal')
    return [x/length for x in out]

def top_uv(uv):
    uv=finite(uv,2);return [uv[0],1-uv[1]]

def clean_color(color):
    c=finite(color,4)
    require(all(0<=v<=1 for v in c[:3]),'invalid RGB range')
    require(-2**-22<=c[3]<=1+2**-22,'invalid alpha range')
    c[3]=min(1,max(0,c[3]));return c

def read_array(blob,d):
    formats={'f32':'f','u32':'I','i32':'i'}
    require(d.get('dtype') in formats,'unsupported array type')
    o,n,c,size=(d.get(k) for k in ('offset','count','components','bytes'))
    require(all(type(x) is int for x in (o,n,c,size)) and o>=0 and n>=0 and 1<=c<=16 and size==4*n*c and o+size<=len(blob),'bad array shape/range')
    result=[list(row) for row in struct.iter_unpack('<'+formats[d['dtype']]*c,blob[o:o+size])]
    require(all(all(math.isfinite(x) for x in row) for row in result),'nonfinite array')
    return result

def validate_bind(data):
    parts=data['parts'];require(len(parts)==2,'expected two native reference parts')
    result={}
    for p in parts:
        i=p['source_mesh_index'];require(i in (0,1) and i not in result,'duplicate/unknown source part')
        b=flat(p['part_to_actor']);ib=flat(p.get('inverse_bind_matrix',inverse(b)))
        for product in (multiply(b,ib),multiply(ib,b)):
            require(max(abs(x-y) for x,y in zip(product,IDENTITY))<1e-8,'bind/inverse mismatch')
        result[i]=(b,ib)
    return result

def socket(node,name):
    # Blender MapRange also has inactive VECTOR sockets with identical names.
    return next(s['default'] for s in node['inputs'] if s['name']==name)

def bind_from_native_proof(proof):
    from a2.animation_bridge import part_matrices
    identities={x['key']:x for x in proof['source_identity']}
    require(identities['T02']['sha256']==SOURCE_HASHES['T02'] and identities['T02']['matches_original_grp'],'unproven native bind source')
    states=[s for s in proof['ordinary_lid_states'] if s['guest_frame']==16750]
    require(len(states)==1,'missing verified closed reference16750')
    state=states[0];root=state['actor_world_q12']
    require(root==[2293760,0,3522560] and state['action']==130,'unexpected reference root/action')
    parts=[]
    for p in state['parts']:
        raw=bytes.fromhex(p['raw_hex']);require(len(raw)==80,'bad reference record')
        require(struct.unpack_from('<H',raw,0)[0]==p['flags'],'reference flags mismatch')
        require(struct.unpack_from('<H',raw,2)[0]==p['source_mesh_index'],'reference part mismatch')
        require(list(struct.unpack_from('<9h',raw,32))==p['matrix_q12'],'reference matrix mismatch')
        require(list(struct.unpack_from('<3h',raw,52))==p['pretranslation'],'reference pretranslation mismatch')
        for offset,name in ((8,'translation0'),(20,'translation1')):require(list(struct.unpack_from('<3i',raw,offset))==p[name],'reference translation mismatch')
        require(not p['flags']&(7|0x200|0x1000),'reference part unavailable/deformed')
        _,b=part_matrices(p['matrix_q12'],p['pretranslation'],p['translation0'],p['translation1'],root)
        parts.append(dict(source_mesh_index=p['source_mesh_index'],part_to_actor=b,inverse_bind_matrix=inverse(b)))
    data={'parts':parts,'source_proof':proof,'reference_frame':16750}
    validate_bind(data);return data


def material_from_graph(material,image_lookup):
    tree=material['node_tree'];nodes=tree['nodes'];links=tree['links']
    def group(t):return [n for n in nodes if n['type']==t]
    def one(t):
        found=group(t);require(len(found)==1,'unsupported shader node count '+t);return found[0]
    def edge(a,asock,b,bsock):return (a['name'],asock,b['name'],bsock)
    actual={(l['from_node'],l['from_socket'],l['to_node'],l['to_socket']) for l in links}
    require(len(actual)==len(links),'duplicate material links')
    out=one('ShaderNodeOutputMaterial')
    result=dict(kind=0,alpha_mode=0,texture=[None,None],base_color=[1,1,1,1],roughness=.76,metallic=0,
                alpha_cutoff=.5,opacity=1,specular=.2,ior=1.5,coat=0,coat_roughness=.03,flags=1,
                roughness_min=.76,roughness_max=.76,name='')
    if group('ShaderNodeBsdfTransparent'):
        require(len(nodes)==6,'unsupported amber graph')
        trans=one('ShaderNodeBsdfTransparent');gloss=one('ShaderNodeBsdfAnisotropic');fr=one('ShaderNodeFresnel');mix=one('ShaderNodeMixShader')
        floor=one('ShaderNodeMath');require(floor['settings']['operation']=='MAXIMUM' and not floor['settings']['use_clamp'] and abs(floor['inputs'][1]['default']-.12)<1e-7,'unsupported amber reflection floor')
        expected={edge(fr,'Factor',floor,'Value'),edge(floor,'Value',mix,'Factor'),edge(trans,'BSDF',mix,'Shader'),edge(gloss,'BSDF',mix,'Shader'),edge(mix,'Shader',out,'Surface')}
        # The two MixShader inputs share their display name; order is checked by identifiers.
        require(actual==expected,'unsupported amber links')
        mix_inputs=[l for l in links if l['to_node']==mix['name'] and l['to_socket']=='Shader']
        require(any(l['from_node']==trans['name'] and l['to_identifier']=='Shader' for l in mix_inputs) and any(l['from_node']==gloss['name'] and l['to_identifier']=='Shader_001' for l in mix_inputs),'reversed amber mix')
        result.update(kind=3,alpha_mode=2,base_color=socket(trans,'Color'),roughness=socket(gloss,'Roughness'),ior=socket(fr,'IOR'),opacity=.38,specular=1,roughness_min=socket(gloss,'Roughness'),roughness_max=socket(gloss,'Roughness'))
        return result
    shader=one('ShaderNodeBsdfPrincipled');colors=group('ShaderNodeVertexColor')
    color0=next((n for n in colors if n['settings']['layer_name']=='Color0'),None);require(color0 is not None,'missing Color0')
    expected={edge(shader,'BSDF',out,'Surface')}
    for field,label in [('roughness','Roughness'),('metallic','Metallic'),('specular','Specular IOR Level'),('ior','IOR'),('coat','Coat Weight'),('coat_roughness','Coat Roughness')]:result[field]=socket(shader,label)
    require(socket(shader,'Alpha')==1,'unsupported principled alpha')
    result['roughness_min']=result['roughness_max']=result['roughness']
    if not group('ShaderNodeTexImage'):
        require(len(nodes)==3 and len(colors)==1,'unsupported plain graph')
        expected.add(edge(color0,'Color',shader,'Base Color'))
    else:
        tex=one('ShaderNodeTexImage');uv=one('ShaderNodeUVMap');gain=one('ShaderNodeVectorMath');mixes=group('ShaderNodeMixRGB')
        require(len(colors)==2 and len(mixes)==2,'unsupported atlas layers')
        color1=next((n for n in colors if n['settings']['layer_name']=='Color1'),None);require(color1 is not None,'missing Color1')
        mult=next((n for n in mixes if n['settings']['blend_type']=='MULTIPLY'),None);mix=next((n for n in mixes if n['settings']['blend_type']=='MIX'),None)
        require(mult is not None and mix is not None and not mult['settings']['use_clamp'] and not mix['settings']['use_clamp'],'unsupported atlas blend')
        require(socket(mult,'Factor')==1 and gain['settings']['operation']=='SCALE' and socket(gain,'Scale')==2,'unsupported atlas gain')
        require(uv['settings']['uv_map']=='UV1' and tex['settings']['interpolation']=='Closest' and tex['settings']['extension']=='EXTEND','unsupported sampler')
        require(tex['image'] in image_lookup,'unknown atlas image')
        expected|={edge(uv,'UV',tex,'Vector'),edge(color1,'Color',mult,'Color1'),edge(tex,'Color',mult,'Color2'),edge(mult,'Color',gain,'Vector'),edge(tex,'Alpha',mix,'Factor'),edge(color0,'Color',mix,'Color1'),edge(gain,'Vector',mix,'Color2'),edge(mix,'Color',shader,'Base Color')}
        result.update(kind=1,texture=[image_lookup[tex['image']],None])
        maps=group('ShaderNodeMapRange')
        require(len(nodes)==9+len(maps) and len(maps)<=1,'unsupported extra material nodes')
        if maps:
            mapping=maps[0];require(mapping['settings']['data_type']=='FLOAT' and mapping['settings']['clamp'],'unsupported roughness map')
            require(socket(mapping,'From Min')==0 and socket(mapping,'From Max')==1,'unsupported roughness domain')
            result.update(kind=2,roughness_min=socket(mapping,'To Min'),roughness_max=socket(mapping,'To Max'))
            expected|={edge(tex,'Alpha',mapping,'Value'),edge(mapping,'Result',shader,'Roughness')}
    require(actual==expected,'unsupported material links')
    return result


def bounds(vertices):
    require(bool(vertices),'empty bounds')
    return [min(v[k] for v in vertices) for k in range(3)]+[max(v[k] for v in vertices) for k in range(3)]


def cook_asset(sidecar_dir,native_dir,bind_data):
    from PIL import Image
    sidecar_dir=Path(sidecar_dir);native_dir=Path(native_dir)
    asset=json.loads((sidecar_dir/'asset.json').read_text());source=json.loads((native_dir/'model.json').read_text())
    key=asset['asset_id'];require(key in SOURCE_HASHES and source['id']==key,'unknown source identity')
    require(source['sha256']==sha(native_dir/'model.bin')==SOURCE_HASHES[key],'native source checksum mismatch')
    require(asset['format']=='a2-blender-sidecar-v1' and asset['frame']==1,'expected approved closed sidecar')
    require(asset['source_sha256']==asset['source_sha256_after'],'source blend changed during export')
    blob=(sidecar_dir/asset['array_file']).read_bytes();require(hashlib.sha256(blob).hexdigest()==asset['array_sha256'],'sidecar array checksum mismatch')
    binds=validate_bind(bind_data);shifts=authored_shifts(source)
    textures=[];lookup={};image_proofs=[]
    for image in asset['images']:
        require(image['colorspace']=='sRGB' and image['alpha_mode']=='STRAIGHT' and len(image['files'])==1,'unsupported image representation')
        entry=image['files'][0];path=sidecar_dir/entry['file'];require(sha(path)==entry['sha256'],'packed image checksum mismatch')
        with Image.open(path) as img:
            rgba=img.convert('RGBA');width,height=rgba.size;pixels=rgba.tobytes()
        require([width,height]==image['size'],'image size mismatch')
        lookup[image['name']]=len(textures);textures.append(dict(width=width,height=height,flags=1,rgba=pixels))
        image_proofs.append(dict(name=image['name'],packed_sha256=entry['sha256'],rgba_sha256=hashlib.sha256(pixels).hexdigest(),width=width,height=height))
    materials=[];material_lookup={}
    for n,material in enumerate(asset['materials']):
        cooked=material_from_graph(material,lookup);cooked['name']=f'{key}_material_{n:02d}';material_lookup[material['name']]=n;materials.append(cooked)
    model=dict(source_key=key,source_sha256=source['sha256'],source_variant=0,index_width=4,vertices=[],indices=[],materials=materials,
               joints=[dict(source_id=i,parent=None,flags=1,bind=binds[i][0],inverse_bind=binds[i][1]) for i in (0,1)],submeshes=[],textures=textures)
    objects=[];vertex_map={};source_checks=[];original_counts=[0,0];triangles=0;alpha_corrections=[]
    for obj in asset['objects']:
        if obj['type']!='MESH':continue
        props=obj['properties'];part=props.get('source_mesh_index');require(part in (0,1) and props.get('source_model')==key,'unbound modern mesh')
        mesh=obj['evaluated_mesh'];world=flat(obj['evaluated_matrix_world']);bind=binds[part][0]
        positions=read_array(blob,mesh['positions']);normals=read_array(blob,mesh['loop_normals']);loop_vertex=read_array(blob,mesh['loop_vertex']);tri_loops=read_array(blob,mesh['triangle_loops']);tri_verts=read_array(blob,mesh['triangle_vertices']);tri_mats=read_array(blob,mesh['triangle_material']);tri_poly=read_array(blob,mesh['triangle_polygons'])
        require(len(tri_loops)==len(tri_verts)==len(tri_mats)==len(tri_poly),'triangle arrays disagree')
        original_counts[part]+=len(positions)
        uvs={name:read_array(blob,d) for name,d in mesh['uv_layers'].items()}
        colors={name:read_array(blob,d['array']) for name,d in mesh['attributes'].items() if name in ('Color0','Color1') and d['domain']=='CORNER'}
        for name,values in colors.items():
            for loop,c in enumerate(values):
                corrected=clean_color(c)
                if corrected!=c:alpha_corrections.append(dict(object=obj['name'],layer=name,loop=loop,original=c[3],cooked=corrected[3]))
                values[loop]=corrected
        has_amber=props.get('source_face_index')==1 and 'construction' in props
        if not has_amber:
            require(set(colors)=={'Color0','Color1'} and {'UV0','UV1'}<=set(uvs),'missing corner layers')
            # Ordered retained original exterior vertices prove authoring inverse;
            # bevel output need not contain any original corners.
            initial=read_array(blob,obj['source_mesh']['positions'])
            error=0
            for old,expected in zip(initial[:8],source['parts'][part]['vertices'][:8]):
                actual=cook_position(old,world,shifts[part],IDENTITY)
                error=max(error,max(abs(x-y) for x,y in zip(actual,expected)))
            require(len(initial)>=8 and error<1e-4,'source authoring placement proof failed')
            source_checks.append(dict(object=obj['name'],source_part=part,ordered_exterior_vertices=8,max_native_coordinate_error=error))
        else:require(part==1 and key=='T03','amber must stay on T03 lid')
        srcface=mesh['attributes'].get('native_source_face');face_ids=read_array(blob,srcface['array']) if srcface else None
        for material_slot in sorted({x[0] for x in tri_mats}):
            require(0<=material_slot<len(mesh['material_slots']),'material slot out of range')
            material_index=material_lookup[mesh['material_slots'][material_slot]];first=len(model['indices']);subpositions=[];source_faces=[]
            require(not has_amber or materials[material_index]['kind']==3,'amber material lost')
            for t,loops in enumerate(tri_loops):
                if tri_mats[t][0]!=material_slot:continue
                source_faces.append(face_ids[tri_poly[t][0]][0] if face_ids else None)
                for corner,loop in enumerate(loops):
                    require(0<=loop<len(loop_vertex) and loop<len(normals),'loop index out of range')
                    vi=loop_vertex[loop][0];require(vi==tri_verts[t][corner] and 0<=vi<len(positions),'triangle/loop disagreement')
                    pos=cook_position(positions[vi],world,shifts[part],bind);normal=cook_normal(normals[loop],world,bind)
                    uv=[top_uv(uvs[f'UV{i}'][loop]) if f'UV{i}' in uvs else [0,0] for i in (0,1)]
                    color=[colors[f'Color{i}'][loop] if f'Color{i}' in colors else [1,1,1,1] for i in (0,1)]
                    require(all(len(c)==4 and all(0<=x<=1 for x in c) for c in color),'invalid linear corner color')
                    vertex=dict(position=pos,normal=normal,uv=uv,color=color,joints=[part,0,0,0],weights=[1,0,0,0])
                    token=tuple(pos+normal+uv[0]+uv[1]+color[0]+color[1]+[part])
                    if token not in vertex_map:vertex_map[token]=len(model['vertices']);model['vertices'].append(vertex)
                    model['indices'].append(vertex_map[token]);subpositions.append(pos)
            require(len(model['indices'])>first,'empty material submesh')
            model['submeshes'].append(dict(first_index=first,index_count=len(model['indices'])-first,material=material_index,source_part=part,bounds=bounds(subpositions)))
            objects.append(dict(name=obj['name'],source_mesh_index=part,properties=props,submesh=len(model['submeshes'])-1,source_face_ids=source_faces))
        triangles+=len(tri_loops)
    expected=(652,1280) if key=='T02' else (677,1326)
    require((sum(original_counts),triangles)==expected,'approved evaluated geometry counts changed')
    model['bounds']=bounds([v['position'] for v in model['vertices']])
    evidence=dict(asset_id=key,sidecar_sha256=sha(sidecar_dir/'asset.json'),array_sha256=asset['array_sha256'],blend_sha256=asset['source_sha256'],source_sha256=source['sha256'],
        evaluated_geometry_vertices=sum(original_counts),triangles=triangles,packed_vertices=len(model['vertices']),source_part_vertices=original_counts,authoring_shifts=shifts,
        alpha_roundoff_corrections=alpha_corrections,ordered_source_checks=source_checks,objects=objects,images=image_proofs,original_material_graphs=asset['materials'],
        native_bind_joints=model['joints'],coordinate_formula='bind_part * (100 * C_inverse * (evaluated_world * v - authored_shift_part))',
        uv_contract='Both UV sets converted exactly once: (u,v)->(u,1-v); image RGBA rows remain top-down; atlas samples UV1.',
        runtime_approximations=['Principled/coat/IOR are retained parameter inputs to the host shader, not full Blender BSDF execution.',
          'Amber uses source transparent tint as base_color, authored display opacity .38 and source roughness/IOR. Near-white glossy tint, source Fresnel minimum .12 and full directional colored transmission are approximated by runtime reflection/straight-alpha shading.',
          'T03 uses the same two-part source pose contract as T02; no live T03 pose/CLUT qualification is claimed. Accepted packed bank-6 art remains unchanged.',
          'Authored Blender hinge is provenance only; native part transforms drive both lid geometry and amber.'],
        source_hinge=[o for o in asset['objects'] if o['type']=='EMPTY'])
    return model,evidence


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--sidecars',type=Path,required=True)
    parser.add_argument('--native-root',type=Path,required=True)
    parser.add_argument('--bind',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();bind=json.loads(args.bind.read_text())
    if 'ordinary_lid_states' in bind:bind=bind_from_native_proof(bind)
    from a2.native_model import pack_model
    results=[];payloads={}
    for key in ('T02','T03'):
        model,evidence=cook_asset(args.sidecars/key,args.native_root/f'{key} Native Source',bind)
        data=pack_model(model);payloads[key+'.A2M']=data;evidence['output_sha256']=hashlib.sha256(data).hexdigest();evidence['output_bytes']=len(data);evidence['bind_proof_sha256']=sha(args.bind);results.append(evidence)
    args.output.mkdir(parents=True,exist_ok=False)
    for name,data in payloads.items():(args.output/name).write_bytes(data)
    (args.output/'cook-report.json').write_text(json.dumps({'schema':'a2.chest_cook.v1','assets':results},ensure_ascii=False,indent=2,allow_nan=False)+'\n')
    print(json.dumps([{'asset':r['asset_id'],'bytes':r['output_bytes'],'triangles':r['triangles'],'sha256':r['output_sha256']} for r in results],indent=2))

if __name__=='__main__':main()
