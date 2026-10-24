"""Build a reviewable Blender scene from a pose-verified direct-source dataset.

Blender Python console:
  exec(compile(open(SCRIPT).read(), SCRIPT, 'exec')); build(JSON, BLEND)
Background:
  Blender --background --factory-startup --python SCRIPT -- JSON BLEND

Creates a new scene; existing scenes and objects are retained. Never overwrites
an existing blend file. Static capture, original source colors and UVs; this is
not a recreation of the original renderer's lighting/projection/ordering table.
"""
import hashlib
import json
import math
import struct
import sys
from pathlib import Path

import bpy
from mathutils import Vector


def _linear(value):
    return value / 12.92 if value <= 0.04045 else ((value + 0.055) / 1.055) ** 2.4


def _color(values):
    return tuple(_linear(v / 255.0) for v in values) + (1.0,)


def _attribute(tree, name):
    node = tree.nodes.new('ShaderNodeVertexColor')
    node.layer_name = name
    return node.outputs['Color']


def _material(key, layers, textures, improved):
    material = bpy.data.materials.new(('Soft / ' if improved else 'Original / ') + key)
    material.use_nodes = True
    material.diffuse_color = (0.5, 0.5, 0.5, 1)
    tree = material.node_tree
    tree.nodes.clear()
    output = tree.nodes.new('ShaderNodeOutputMaterial')
    accumulated = None
    alpha = None
    for index, layer in enumerate(layers):
        if layer['modifier_offset']:
            raise ValueError('dynamic source UV/color modifier is not validated')
        if layer['command'] & 2:
            raise ValueError('semi-transparent source material requires explicit PS1 blending')
        color = _attribute(tree, f'A2CornerColor{index}')
        if layer['textured']:
            tex = tree.nodes.new('ShaderNodeTexImage')
            tex.image = textures[(layer['tpage'], layer['clut'])]
            tex.interpolation = 'Linear' if improved else 'Closest'
            tex.extension = 'REPEAT'
            uv = tree.nodes.new('ShaderNodeUVMap'); uv.uv_map = f'A2UV{index}'
            tree.links.new(uv.outputs['UV'], tex.inputs['Vector'])
            if layer['command'] & 1:
                color = tex.outputs['Color']
            else:
                multiply = tree.nodes.new('ShaderNodeMixRGB')
                multiply.blend_type = 'MULTIPLY'; multiply.inputs[0].default_value = 1
                tree.links.new(color, multiply.inputs[1]); tree.links.new(tex.outputs['Color'], multiply.inputs[2])
                gain = tree.nodes.new('ShaderNodeVectorMath'); gain.operation = 'SCALE'
                gain.inputs['Scale'].default_value = 2
                tree.links.new(multiply.outputs['Color'], gain.inputs[0]); color = gain.outputs['Vector']
            layer_alpha = tex.outputs['Alpha']
        else:
            layer_alpha = None
        if accumulated is None or layer_alpha is None:
            accumulated, alpha = color, layer_alpha
        else:
            mix = tree.nodes.new('ShaderNodeMixRGB'); mix.blend_type = 'MIX'
            tree.links.new(layer_alpha, mix.inputs[0]); tree.links.new(accumulated, mix.inputs[1]); tree.links.new(color, mix.inputs[2])
            accumulated = mix.outputs['Color']
            # The original base colors are opaque; overlay transparent texels
            # reveal that base. No displaced duplicate polygons are created.
    if improved:
        shader = tree.nodes.new('ShaderNodeBsdfPrincipled')
        tree.links.new(accumulated, shader.inputs['Base Color'])
        shader.inputs['Roughness'].default_value = 0.85
        shader.inputs['Specular IOR Level'].default_value = 0.12
    else:
        shader = tree.nodes.new('ShaderNodeEmission')
        tree.links.new(accumulated, shader.inputs['Color'])
        shader.inputs['Strength'].default_value = 1
    if alpha is not None:
        transparent = tree.nodes.new('ShaderNodeBsdfTransparent')
        mix = tree.nodes.new('ShaderNodeMixShader')
        tree.links.new(alpha, mix.inputs[0]); tree.links.new(transparent.outputs[0], mix.inputs[1]); tree.links.new(shader.outputs[0], mix.inputs[2])
        tree.links.new(mix.outputs[0], output.inputs['Surface'])
        material.surface_render_method = 'DITHERED'
    else:
        tree.links.new(shader.outputs[0], output.inputs['Surface'])
    return material


def _geometry_digest(mesh):
    digest = hashlib.sha256()
    for vertex in mesh.vertices:
        digest.update(struct.pack('<3f', *vertex.co))
    for polygon in mesh.polygons:
        digest.update(struct.pack('<I', len(polygon.vertices)))
        digest.update(struct.pack('<' + 'I' * len(polygon.vertices), *polygon.vertices))
    return digest.hexdigest()


def build(dataset_path, blend_path):
    dataset_path, blend_path = Path(dataset_path).resolve(), Path(blend_path).resolve()
    if blend_path.exists():
        raise FileExistsError(f'refusing existing blend file: {blend_path}')
    data = json.loads(dataset_path.read_text())
    if data['format'] != 'a2-static-actor-v1' or not data['parts'] or not all(p['pose_verified'] for p in data['parts']):
        raise ValueError('requires complete pose-verified source data')
    for part in data['parts']:
        for face in part['faces']:
            for layer in face['layers']:
                if layer['modifier_offset'] or layer['command'] & 2:
                    raise ValueError('unvalidated dynamic or semi-transparent material')
    textures = {}
    for item in data.get('textures', []):
        image = bpy.data.images.load(str(dataset_path.parent / item['file']), check_existing=False)
        image.pack()
        textures[(item['tpage'], item['clut'])] = image
    scene = bpy.data.scenes.new('Alundra 2 — Flint source study')
    original = bpy.data.collections.new('01 Original source geometry and colors')
    comparison = bpy.data.collections.new('02 Same geometry — soft lighting')
    scene.collection.children.link(original); scene.collection.children.link(comparison)
    if bpy.context.window:
        bpy.context.window.scene = scene
    points = [v for part in data['parts'] for v in part['posed_vertices']]
    lower = [min(p[k] for p in points) for k in range(3)]
    upper = [max(p[k] for p in points) for k in range(3)]
    origin = [(lower[0] + upper[0]) / 2, upper[1], (lower[2] + upper[2]) / 2]
    scale = 0.01
    height = (upper[1] - lower[1]) * scale
    spacing = max((upper[0] - lower[0]) * scale * 1.6, height * 0.75)
    material_cache = {}
    verification = []
    for part in data['parts']:
        positions = [[(p[0]-origin[0])*scale, (p[2]-origin[2])*scale, -(p[1]-origin[1])*scale]
                     for p in part['posed_vertices']]
        topology, source_corners, source_faces = [], [], []
        for face in part['faces']:
            for corners in ([[0,1,2]] if len(face['indices']) == 3 else [[0,1,3],[1,2,3]]):
                topology.append([face['indices'][k] for k in corners])
                source_corners.append(corners); source_faces.append(face)
        mesh = bpy.data.meshes.new(f'Source mesh {part["source_mesh_index"]:02d}')
        mesh.from_pydata(positions, [], topology); mesh.update()
        for index in range(2):
            color = mesh.color_attributes.new(name=f'A2CornerColor{index}', type='FLOAT_COLOR', domain='CORNER')
            uv = mesh.uv_layers.new(name=f'A2UV{index}')
            for polygon, face, corners in zip(mesh.polygons, source_faces, source_corners):
                layer = face['layers'][min(index, len(face['layers'])-1)]
                for loop_index, corner in zip(polygon.loop_indices, corners):
                    color.data[loop_index].color = _color(layer['colors'][corner])
                    u, v = layer['uv'][corner]
                    uv.data[loop_index].uv = ((u+0.5)/256, 1-(v+0.5)/256)
        ids = mesh.attributes.new(name='a2_source_vertex_index', type='INT', domain='POINT')
        for i, value in enumerate(ids.data): value.value = i
        face_ids = mesh.attributes.new(name='a2_source_face_index', type='INT', domain='FACE')
        for value, face in zip(face_ids.data, source_faces): value.value = face['source_index']
        for improved, collection in ((False,original),(True,comparison)):
            current_mesh = mesh.copy() if improved else mesh
            current_mesh.materials.clear()
            obj = bpy.data.objects.new(f'Flint part {part["source_mesh_index"]:02d}' + (' — soft' if improved else ' — original'), current_mesh)
            collection.objects.link(obj)
            obj.location.x = spacing / 2 if improved else -spacing / 2
            obj['source_part_address'] = f'{part["source_address"]:08X}'
            obj['source_model_header'] = f'{part["source_model_header"]:08X}'
            obj['source_vertex_address'] = f'{part["source_vertex_address"]:08X}'
            obj['source_registry'] = f'{part["source_mesh_registry"]:08X}'
            obj['source_origin'] = origin; obj['source_scale'] = scale
            obj['static_pose_verified'] = True
            local_materials = {}
            for polygon, face in zip(current_mesh.polygons, source_faces):
                key = tuple((layer['command'],layer['tpage'],layer['clut']) for layer in face['layers'])
                cache_key = (improved,key)
                if cache_key not in material_cache:
                    material_cache[cache_key] = _material(str(key), face['layers'], textures, improved)
                if key not in local_materials:
                    local_materials[key] = len(current_mesh.materials)
                    current_mesh.materials.append(material_cache[cache_key])
                polygon.material_index = local_materials[key]
                polygon.use_smooth = improved
            if improved:
                assert _geometry_digest(current_mesh) == _geometry_digest(mesh), 'comparison geometry changed'
        verification.append({'part':part['source_mesh_index'], 'vertices':len(mesh.vertices),
                             'triangles':len(mesh.polygons), 'geometry_sha256':_geometry_digest(mesh)})
    world = bpy.data.worlds.new('Flint study neutral world'); world.use_nodes = True
    world.node_tree.nodes['Background'].inputs[0].default_value = (0.07,0.08,0.1,1)
    world.node_tree.nodes['Background'].inputs[1].default_value = 0.5
    scene.world = world
    for name, position, energy, size in [('Key',(-3,-4,6),500,5),('Fill',(4,1,3),260,4)]:
        lamp = bpy.data.lights.new('Flint study '+name, type='AREA'); lamp.energy=energy; lamp.shape='DISK'; lamp.size=size
        obj = bpy.data.objects.new(lamp.name,lamp); scene.collection.objects.link(obj)
        obj.location=position; obj.rotation_euler=(Vector((0,0,height/2))-obj.location).to_track_quat('-Z','Y').to_euler()
    cam = bpy.data.cameras.new('Flint study camera'); cam.type='ORTHO'; cam.ortho_scale=max(spacing*2.25,height*2)
    camera = bpy.data.objects.new(cam.name,cam);scene.collection.objects.link(camera)
    camera.location=(height*0.7,-height*4,height*1.7)
    target=Vector((0,0,height*0.5));camera.rotation_euler=(target-camera.location).to_track_quat('-Z','Y').to_euler()
    scene.camera=camera
    scene.render.engine='CYCLES';scene.cycles.samples=24
    scene.render.resolution_x=1600;scene.render.resolution_y=1100;scene.render.resolution_percentage=100
    scene.view_settings.view_transform='Standard';scene.view_settings.look='None'
    scene['a2_capture_frame']=data['frame'];scene['a2_ram_sha256']=data['ram_sha256']
    scene['a2_static_pose_note']='All source indices and captured posed vertices preserved; source colors, not PS1 runtime lighting. Right-hand study changes only normals/materials.'
    source_text=bpy.data.texts.new('A2 source manifest.json');source_text.write(json.dumps(data,indent=2))
    note=bpy.data.texts.new('READ ME — original and comparison')
    note.write('Left: original complete source topology, flat surface normals, original corner colors and texture layers.\nRight: identical vertex positions and triangles; smooth normals and soft material lighting only.\nStatic captured pose, not a recovered skeleton. Blender uses its own lighting, depth and color pipeline; this is not a pixel-identical PS1 rendering. All source IDs/transforms are embedded in the JSON text block.\n')
    # Make the assembled character visible immediately in the user's Blender
    # window without removing or changing any preexisting scene objects.
    if bpy.context.window:
        for area in bpy.context.window.screen.areas:
            if area.type=='VIEW_3D':
                area.spaces.active.region_3d.view_perspective='CAMERA'
                area.spaces.active.shading.type='MATERIAL'
    blend_path.parent.mkdir(parents=True,exist_ok=True)
    bpy.ops.wm.save_as_mainfile(filepath=str(blend_path),check_existing=False)
    report={'blend':str(blend_path),'parts':verification,'original_and_comparison_geometry_identical':True,
            'source_vertices':sum(v['vertices'] for v in verification),'triangles':sum(v['triangles'] for v in verification),
            'packed_textures':len(textures),'capture_frame':data['frame']}
    blend_path.with_suffix('.verification.json').write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps(report,indent=2))
    return scene


if __name__=='__main__' and '--' in sys.argv:
    args=sys.argv[sys.argv.index('--')+1:]
    if len(args)!=2:raise ValueError('expected dataset.json output.blend after --')
    build(*args)
