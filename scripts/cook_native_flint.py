#!/usr/bin/env python3
"""Cook approved v5 Flint data without changing geometry or executing artist code.

PC00.A2M requires its checksum-bound PC00.runtime.json: A2M2 alone does not
represent derived driver formulas, floor tracks, sampler modes or bump graphs.
The current chest-only runtime is deliberately not claimed compatible.
"""
import argparse
import copy
import hashlib
import json
import math
from pathlib import Path
import shutil
import struct

from a2.animation_bridge import multiply
from a2.native_model import pack_model

APPROVED_BLEND_SHA='c1d63fd792193fb53991167a4d2b2266122e7a5752d311b4b775e1a7c4f21d47'
SOURCE_SHA='b6cbf3c4d4cf456f4921dde96ba769d092143e855a282ca5ff87977f309eb720'
IDENTITY=[float(i==j) for i in range(4) for j in range(4)]


def require(ok,message):
    if not ok:raise ValueError(message)


def finite(v,n):
    require(len(v)==n and all(type(x) in (int,float) and math.isfinite(x) for x in v),'invalid finite vector')
    return list(v)


def flat(m):
    require(len(m)==4 and all(len(r)==4 for r in m),'expected matrix rows')
    out=finite([x for r in m for x in r],16);require(out[12:]==[0,0,0,1],'nonaffine matrix');return out


def bounds(positions):return [f(v[k] for v in positions) for f in (min,max) for k in range(3)]

def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def material_contract(material,images):
    tree=material['node_tree'];nodes=tree['nodes'];links=tree['links']
    def group(t):return [n for n in nodes if n['type']==t]
    def one(t):
        rows=group(t);require(len(rows)==1,'unsupported node count '+t);return rows[0]
    def socket(n,k):return next(s['default'] for s in n['inputs'] if s['name']==k)
    def edge(a,x,b,y):return (a['name'],x,b['name'],y)
    actual={(l['from_node'],l['from_socket'],l['to_node'],l['to_socket']) for l in links}
    require(len(actual)==len(links),'duplicate links')
    require(not any(n.get('settings',{}).get('mute') for n in nodes),'muted graph node')
    out=one('ShaderNodeOutputMaterial');sem={'source_name':material['name'],'graph':copy.deepcopy(tree),'runtime_required':True}
    m=dict(kind=0,alpha_mode=0,texture=[None,None],base_color=[1,1,1,1],roughness=1,metallic=0,alpha_cutoff=.5,
           opacity=1,specular=0,ior=1.5,coat=0,coat_roughness=.03,flags=1,roughness_min=1,roughness_max=1,name='')
    if group('ShaderNodeEmission'):
        shader=one('ShaderNodeEmission');require(socket(shader,'Strength')==1,'unsupported emission strength')
        colors=group('ShaderNodeVertexColor');c0=next((n for n in colors if n['settings']['layer_name']=='A2CornerColor0'),None)
        require(c0 is not None,'missing source corner color')
        expected={edge(shader,'Emission',out,'Surface')};sem.update(lighting='emission',vertex_color_usage='Color0')
        if not group('ShaderNodeTexImage'):
            require(len(nodes)==3,'unsupported flat emission graph');expected.add(edge(c0,'Color',shader,'Color'))
        else:
            require(len(nodes)==9 and len(colors)==2,'unsupported layered emission graph')
            c1=next((n for n in colors if n['settings']['layer_name']=='A2CornerColor1'),None);require(c1 is not None,'missing second corner color')
            tex=one('ShaderNodeTexImage');uv=one('ShaderNodeUVMap');gain=one('ShaderNodeVectorMath');mixes=group('ShaderNodeMixRGB')
            mul=next((n for n in mixes if n['settings']['blend_type']=='MULTIPLY'),None);mix=next((n for n in mixes if n['settings']['blend_type']=='MIX'),None)
            require(mul is not None and mix is not None and socket(mul,'Factor')==1,'unsupported mix')
            require(not mul['settings'].get('use_clamp') and not mix['settings'].get('use_clamp'),'unsupported clamped mix')
            require(gain['settings']['operation']=='SCALE' and socket(gain,'Scale')==2,'unsupported source gain')
            require(uv['settings']['uv_map']=='A2UV1' and tex['settings']['interpolation']=='Closest' and tex['settings']['extension']=='REPEAT','unsupported source sampler')
            expected|={edge(uv,'UV',tex,'Vector'),edge(c1,'Color',mul,'Color1'),edge(tex,'Color',mul,'Color2'),edge(mul,'Color',gain,'Vector'),edge(tex,'Alpha',mix,'Factor'),edge(c0,'Color',mix,'Color1'),edge(gain,'Vector',mix,'Color2'),edge(mix,'Color',shader,'Color')}
            require(tex['image'] in images,'missing source image');m.update(kind=1,texture=[images[tex['image']],None])
            sem.update(vertex_color_usage='layered Color0/Color1',sampler={'filter':'nearest','address':'repeat'},uv='UV1')
    else:
        shader=one('ShaderNodeBsdfPrincipled');expected={edge(shader,'BSDF',out,'Surface')}
        require(socket(shader,'Alpha')==1,'unsupported principled alpha')
        for k,label in [('roughness','Roughness'),('metallic','Metallic'),('specular','Specular IOR Level'),('ior','IOR'),('coat','Coat Weight'),('coat_roughness','Coat Roughness')]:m[k]=socket(shader,label)
        m['roughness_min']=m['roughness_max']=m['roughness'];m['base_color']=socket(shader,'Base Color')
        sem.update(lighting='principled',vertex_color_usage='none',required_note='Stored source corner colors must NOT modulate constant Principled base color.')
        if not group('ShaderNodeTexImage'):
            require(len(nodes)==2,'unsupported principled graph')
        else:
            require(len(nodes)==6,'unsupported shield graph')
            tex=one('ShaderNodeTexImage');uv=one('ShaderNodeUVMap');mix=one('ShaderNodeMixRGB');bump=one('ShaderNodeBump')
            require(mix['settings']['blend_type']=='MIX' and not mix['settings'].get('use_clamp'),'unsupported shield mix')
            require(uv['settings']['uv_map']=='Source shield central UV' and tex['settings']['interpolation']=='Linear' and tex['settings']['extension']=='CLIP','unsupported shield sampler')
            require(tex['image'] in images,'missing shield image')
            expected|={edge(uv,'UV',tex,'Vector'),edge(tex,'Alpha',mix,'Factor'),edge(tex,'Color',mix,'Color2'),edge(mix,'Color',shader,'Base Color'),edge(tex,'Alpha',bump,'Height'),edge(bump,'Normal',shader,'Normal')}
            m.update(kind=1,texture=[images[tex['image']],None],base_color=[1,1,1,1])
            sem.update(albedo='mix(shield_base, texture.rgb, texture.a)',shield_base=socket(mix,'Color1'),
                       vertex_color_usage='synthetic atlas constants for exact albedo only',uv='Source shield central UV in UV0 and UV1',
                       sampler={'filter':'linear','address':'clip'},bump={'invert':bump['settings']['invert'],
                       'strength':socket(bump,'Strength'),'distance_preview':socket(bump,'Distance'),'filter_width':socket(bump,'Filter Width')},
                       required_note='Layered record encodes exact albedo equation; approved bump and Principled response remain required runtime semantics.')
    require(actual==expected,'unsupported material links')
    return m,sem


def load_images(bundle,root):
    from PIL import Image
    textures=[];lookup={};proof=[]
    for image in bundle['images']:
        require(root is not None and image['colorspace']=='sRGB' and image['alpha_mode']=='STRAIGHT' and len(image['files'])==1,'unsupported image encoding')
        item=image['files'][0];path=(Path(root)/item['file']).resolve();require(path.is_relative_to(Path(root).resolve()),'image path escapes bundle')
        require(sha(path)==item['sha256'],'packed image checksum mismatch')
        with Image.open(path) as img:rgba=img.convert('RGBA');size=list(rgba.size);pixels=rgba.tobytes()
        require(size==image['size'],'image dimensions differ');require(image['name'] not in lookup,'duplicate image')
        lookup[image['name']]=len(textures);textures.append({'width':size[0],'height':size[1],'flags':1,'rgba':pixels})
        proof.append({'name':image['name'],'packed_sha256':item['sha256'],'rgba_sha256':hashlib.sha256(pixels).hexdigest(),'size':size})
    return textures,lookup,proof


def cook_model(data,surfaces,surface_root):
    require(data['schema']=='a2.modern_flint_skin_preview.v5' and data['skinning']=='linear' and data['bind_frame']==2999,'unsupported skin contract')
    source=data['source_asset'];require(source['asset_id']=='PC00' and source['variant']==0 and source['mesh']['sha256']==SOURCE_SHA,'unproven source identity')
    require(surfaces['format']=='a2-flint-surfaces-v1' and surfaces['geometry_verified'] and surfaces['source_sha256']==surfaces['source_sha256_after']==APPROVED_BLEND_SHA,'unverified approved surfaces')
    flat(data['actor_to_preview_reference'])
    rows={}
    for p in data['parts']:
        idx=p['source_mesh_index'];require(type(idx) is int and 0<=idx<16 and idx not in rows,'duplicate/unknown native driver');rows[idx]=p
    require(set(rows)==set(range(16)),'missing native drivers')
    for p in data['derived_drivers']:
        idx=p['driver_index'];require(idx in (16,17,18) and idx not in rows and p['native'] is False,'bad derived driver')
        require(p['name']=={16:'shield_mount',17:'sole_contact.R',18:'sole_contact.L'}[idx],'derived driver name mismatch')
        require(flat(p['bind'])==flat(p['inverse_bind'])==IDENTITY,'derived driver returns ready delta; bind must be identity');rows[idx]=p
    require(set(rows)==set(range(19)),'missing derived driver')
    joints=[]
    for i,p in sorted(rows.items()):
        b=flat(p['bind']);ib=flat(p['inverse_bind'])
        require(max(abs(v-e) for v,e in zip(multiply(b,ib),IDENTITY))<1e-8,'bind inverse mismatch')
        joints.append(dict(source_id=i,parent=None,flags=1,bind=b,inverse_bind=ib))
    textures,image_lookup,image_proof=load_images(surfaces,surface_root);materials=[];semantics=[];mat_lookup={}
    for n,material in enumerate(surfaces['materials']):
        require(material['name'] not in mat_lookup,'duplicate material');m,sem=material_contract(material,image_lookup)
        m['name']=f'PC00_material_{n:02d}';mat_lookup[material['name']]=n;materials.append(m);semantics.append(sem)
    model=dict(source_key='PC00',source_sha256=SOURCE_SHA,source_variant=0,vertices=[],indices=[],materials=materials,joints=joints,submeshes=[],textures=textures)
    meshes=[];alpha_corrections=[]
    for mesh in data['meshes']:
        pos=[finite(v,3) for v in mesh['vertices_actor_bind']];tri=mesh['triangles'];n=len(pos);corners=3*len(tri)
        require(n>0 and corners>0 and len(mesh['triangle_materials'])==len(tri) and len(mesh['corner_normals_actor_bind'])==corners,'invalid mesh array lengths')
        weights=mesh['skin_driver_weights'];require(len(weights)==n,'weight count differs')
        for w in weights:
            require(1<=len(w)<=4 and len({i for i,v in w})==len(w),'duplicate or too many influences')
            require(all(type(i) is int and i in rows and type(v) in (int,float) and math.isfinite(v) and 0<=v<=1 for i,v in w) and abs(sum(v for i,v in w)-1)<1e-7,'invalid vertex weights')
        uvs=mesh['uv_layers'];cols=mesh['color_attributes']
        require(set(uvs)<=set(['A2UV0','A2UV1','Source shield central UV']) and len(uvs)<=2,'unknown UV layer')
        require(set(cols)<=set(['A2CornerColor0','A2CornerColor1']),'unknown color layer')
        require(all(len(v)==corners for v in uvs.values()),'UV length differs')
        require(all(v['domain']=='CORNER' and len(v['values'])==corners for v in cols.values()),'color layout differs')
        groups={};source_faces={};vertex_map={};mapped=[]
        for f,indices in enumerate(tri):
            require(len(indices)==3 and all(type(i) is int and 0<=i<n for i in indices),'invalid triangle')
            local_mat=mesh['triangle_materials'][f];require(type(local_mat) is int and 0<=local_mat<len(mesh['materials']),'material slot out of range')
            name=mesh['materials'][local_mat];require(name in mat_lookup,'missing material graph');mat=mat_lookup[name];sem=semantics[mat]
            source_faces.setdefault(mat,[]).append(f)
            for corner,index in enumerate(indices):
                loop=f*3+corner;normal=finite(mesh['corner_normals_actor_bind'][loop],3);length=math.sqrt(sum(v*v for v in normal));require(length>1e-20,'zero normal');normal=[v/length for v in normal]
                uv=[]
                for layer in ['A2UV0','A2UV1']:
                    values=uvs.get(layer,uvs.get('Source shield central UV'))
                    value=finite(values[loop],2) if values is not None else [0,0];uv.append([value[0],1-value[1]])
                colors=[]
                for layer in ['A2CornerColor0','A2CornerColor1']:
                    c=finite(cols[layer]['values'][loop],4) if layer in cols else [1,1,1,1]
                    require(all(-16<=v<=16 for v in c[:3]) and -2**-22<=c[3]<=1+2**-22,'invalid corner color')
                    alpha=min(1,max(0,c[3]))
                    if alpha!=c[3]:alpha_corrections.append([mesh['name'],layer,loop,c[3],alpha])
                    c[3]=alpha;colors.append(c)
                if 'shield_base' in sem:
                    require(not cols and 'Source shield central UV' in uvs,'shield source attributes differ')
                    colors=[sem['shield_base'],[.5,.5,.5,1]]
                if sem.get('vertex_color_usage','').startswith(('Color0','layered')):
                    require('A2CornerColor0' in cols,'missing required color')
                    if sem['vertex_color_usage'].startswith('layered'):require('A2CornerColor1' in cols and 'A2UV1' in uvs,'missing layered attributes')
                influences=weights[index];js=[i for i,v in influences]+[0]*(4-len(influences));ws=[v for i,v in influences]+[0]*(4-len(influences))
                v=dict(position=pos[index],normal=normal,uv=uv,color=colors,joints=js,weights=ws)
                key=json.dumps(v,separators=(',',':'))
                if key not in vertex_map:vertex_map[key]=len(model['vertices']);model['vertices'].append(v);mapped.append([vertex_map[key],index,loop])
                groups.setdefault(mat,[]).append(vertex_map[key])
        first=len(model['indices']);submesh_proof=[]
        rigid=weights[0][0][0] if all(len(w)==1 and w[0][0]==weights[0][0][0] for w in weights) else None
        for mat,indices in sorted(groups.items()):
            start=len(model['indices']);model['indices'].extend(indices)
            submesh_proof.append({'first_index':start,'material':mat,'source_triangle_indices':source_faces[mat]})
            model['submeshes'].append(dict(first_index=start,index_count=len(indices),material=mat,source_part=rigid,bounds=bounds([model['vertices'][i]['position'] for i in indices])))
        meshes.append({'name':mesh['name'],'source_vertices':n,'triangles':len(tri),'first_index':first,'index_count':len(model['indices'])-first,'packed_vertex_to_source_vertex_loop':mapped,'submesh_source_triangles':submesh_proof,'original_uv_layers':list(uvs),'original_color_layers':list(cols),'rigid_attachment':copy.deepcopy(mesh.get('rigid_attachment'))})
    model['bounds']=bounds([v['position'] for v in model['vertices']])
    signed=any(not 0<=c<=1 for v in model['vertices'] for color in v['color'] for c in color[:3])
    model['file_flags']=1 if signed else 0
    pack_model(model)
    contract={'format':'a2-pc00-runtime-contract-v1','runtime_ready':False,'requires_signed_corner_rgb':signed,'required_with_model':True,
              'source_asset':copy.deepcopy(source),'approved_blend_sha256':APPROVED_BLEND_SHA,'bind_frame':2999,
              'skinning':'linear','driver_count':19,'native_driver_ids':list(range(16)),
              'actor_to_preview_reference':copy.deepcopy(data['actor_to_preview_reference']),
              'derived_drivers':copy.deepcopy(data['derived_drivers']),'floor_clearance_tracks':copy.deepcopy(data['floor_clearance_tracks']),
              'clips':copy.deepcopy(data['clips']),'authoring_bones':copy.deepcopy(data['authoring_bones']),
              'material_semantics':semantics,'images':image_proof,'meshes':meshes,'alpha_roundoff_corrections':alpha_corrections,
              'coordinate_contract':'Vertices already actor bind. Supply native P*inverse(B), derived ready deltas. Add approved contact actor_delta after skinning; actor_to_world once. No H/presentation yaw in runtime.',
              'required_runtime_work':['19-driver PC00 provenance and pose support; current scene is chest-only.',
               'Derived shield16 and foot17/18 formulas plus grounded-clip contact tracks; other actions and terrain are unqualified.',
               'Honor material graph lighting, vertex-color usage, sampler and shield bump; current A2M2/Metal unlit shader subset is insufficient.'],
              'texture_convention':'Original packed RGBA images top-origin; UV V converted once. All original named corner layers preserved; absent attributes have explicit neutral or shield-albedo constants.'}
    return model,contract


def write_cooked(output,model,contract):
    """Write a new binary and faithful canonical records; runtime sidecar is required."""
    output=Path(output);require(not output.exists(),'output must be new');output.mkdir(parents=True)
    canonical=copy.deepcopy(model);(output/'textures').mkdir()
    for i,t in enumerate(canonical['textures']):
        pixels=t.pop('rgba');name=f'textures/image-{i:03d}.rgba';(output/name).write_bytes(pixels)
        t['rgba_file']=name;t['rgba_sha256']=hashlib.sha256(pixels).hexdigest();t['rgba_bytes']=len(pixels)
    data=json.dumps(canonical,ensure_ascii=False,separators=(',',':')).encode()+b'\n'
    (output/'PC00.model.json').write_bytes(data)
    binary=pack_model(model);(output/'PC00.A2M').write_bytes(binary)
    contract.update(model_json_sha256=hashlib.sha256(data).hexdigest(),artifact_kind='A2M2 binary plus required runtime contract',
                    model_sha256=hashlib.sha256(binary).hexdigest(),model_bytes=len(binary),file_flags=model['file_flags'],
                    signed_corner_rgb_contract={'header_flags_byte':24,'bit':0,'name':'SIGNED_CORNER_RGB','rgb_range':[-16,16],
                    'alpha_range':[0,1],'default_behavior':'unit RGBA unchanged','unknown_bits':'reject','record_layout_changes':False})
    return contract


def main():
    parser=argparse.ArgumentParser();parser.add_argument('--handoff',type=Path,required=True);parser.add_argument('--surfaces',type=Path,required=True);parser.add_argument('--driver-tools',type=Path,required=True);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    data=json.loads(args.handoff.read_text());bundle=json.loads(args.surfaces.read_text());require(bundle['handoff_sha256']==sha(args.handoff),'surface/handoff mismatch')
    require(not args.output.exists(),'output must be new');model,contract=cook_model(data,bundle,args.surfaces.parent)
    contract.update(handoff_sha256=sha(args.handoff),surfaces_sha256=sha(args.surfaces),driver_implementations=[])
    tools=['contact_fixes.py','feet_only.py','animation_bridge.py','clip_stream.py']
    for name in tools:require((args.driver_tools/name).is_file(),'missing driver implementation '+name)
    write_cooked(args.output,model,contract);(args.output/'contract').mkdir()
    for name in tools:
        src=args.driver_tools/name;shutil.copy2(src,args.output/'contract'/name);contract['driver_implementations'].append({'file':'contract/'+name,'sha256':sha(src)})
    (args.output/'PC00.runtime.json').write_text(json.dumps(contract,ensure_ascii=False,indent=2)+'\n')
    shutil.copy2(args.handoff,args.output/'contract/flint-skin-preview.json');shutil.copy2(args.surfaces,args.output/'contract/surfaces.json')
    for image in bundle['images']:
        for entry in image['files']:
            dst=args.output/'contract'/entry['file'];dst.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(args.surfaces.parent/entry['file'],dst)
    print(json.dumps({'output':str(args.output),'model_json_sha256':contract['model_json_sha256'],'vertices':len(model['vertices']),'triangles':len(model['indices'])//3,'joints':len(model['joints']),'runtime_ready':False,'binary_emitted':True,'model_sha256':contract['model_sha256']}))

if __name__=='__main__':main()
