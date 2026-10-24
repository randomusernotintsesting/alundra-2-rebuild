"""Verified pose exchange, independent of Blender and the game renderer.

Row-major 4x4 matrices multiply column vectors. The chosen actor frame has
world-aligned axes and the actual render-root origin; root rotation is already
in the final part matrices. This is a helper frame, not a recovered skeleton.
"""
import argparse
import hashlib
import json
import math
import struct
from collections import defaultdict
from pathlib import Path

from . import character_export as ce


def vector(values, count):
    if len(values) != count or any(not isinstance(x, (int, float)) or
                                   not math.isfinite(x) for x in values):
        raise ValueError(f'expected {count} finite numeric values')
    return list(values)


def transform(matrix, point):
    m, p = vector(matrix, 16), vector(point, 3) + [1]
    if m[12:] != [0, 0, 0, 1]:
        raise ValueError('expected affine matrix')
    return [sum(m[4 * i + j] * p[j] for j in range(4)) for i in range(3)]


def multiply(a, b):
    a, b = vector(a, 16), vector(b, 16)
    return [sum(a[4*i+k] * b[4*k+j] for k in range(4))
            for i in range(4) for j in range(4)]


def inverse(matrix):
    m = vector(matrix, 16)
    rows = [m[i*4:i*4+4] + [float(i == j) for j in range(4)] for i in range(4)]
    for i in range(4):
        pivot = max(range(i, 4), key=lambda j: abs(rows[j][i]))
        rows[i], rows[pivot] = rows[pivot], rows[i]
        divisor = rows[i][i]
        if abs(divisor) < 1e-12:
            raise ValueError('singular or ill-conditioned bind matrix')
        rows[i] = [v / divisor for v in rows[i]]
        for j in range(4):
            if j != i:
                factor = rows[j][i]
                rows[j] = [a - factor*b for a, b in zip(rows[j], rows[i])]
    return vector([x for row in rows for x in row[4:]], 16)


def part_matrices(matrix_q12, pretranslation, translation0, translation1, root_q12):
    r = vector(matrix_q12, 9)
    pre, t0, t1, root = [vector(v, 3) for v in
                         (pretranslation, translation0, translation1, root_q12)]
    actor = [1, 0, 0, root[0]/4096, 0, 1, 0, root[1]/4096,
             0, 0, 1, root[2]/4096, 0, 0, 0, 1]
    part = []
    for i in range(3):
        part.extend(v/4096 for v in r[3*i:3*i+3])
        part.append(sum(r[3*i+j]*pre[j] for j in range(3))/4096
                    + t0[i] + t1[i] - root[i]/4096)
    return actor, part + [0, 0, 0, 1]


def fixed_vertex(vertex, matrix_q12, pretranslation, translation0, translation1, camera):
    return ce.pose_vertex(vertex, matrix_q12, pretranslation,
                         [translation0[i]+translation1[i]-camera[i] for i in range(3)])


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def write_json(path, data):
    Path(path).write_text(json.dumps(data, ensure_ascii=False, indent=2,
                                    allow_nan=False) + '\n')


def convert_submission(frame, entity_address, mesh_ids):
    """Convert one proven actor submission; never invent poses for absent parts.

    entity_address selects a diagnostic instance inside this capture only.
    Source identity and observation lifetime require separate manifest proof.
    """
    if frame.get('schema') != 'a2.animation_bridge.v1':
        raise ValueError('unsupported snapshot schema')
    if not frame['valid'] or frame['shadow_pass']:
        return None
    instances = [a for a in frame['instances'] if a['entity_address'] == entity_address]
    if not instances:
        return None
    if len(instances) != 1:
        raise ValueError('mixed actor instances in a submission')
    a = instances[0]
    if not a.get('valid', True):
        return None
    if a.get('fallback', 0) & 4:
        raise ValueError('missing actor render-root; no valid actor-space pose')
    source_parts = {}
    for p in a['parts']:
        index = p['source_mesh_index']
        if index in source_parts:
            raise ValueError('duplicate stable mesh ID in actor submission')
        source_parts[index] = p
    actor = part_matrices([4096,0,0,0,4096,0,0,0,4096], [0]*3, [0]*3,
                          [0]*3, a['renderer_root_q12'])[0]
    parts, valid_mask, visible_mask = [], 0, 0
    for index in mesh_ids:
        p = source_parts.get(index)
        entry = dict(source_mesh_index=index, valid=False, visible=False,
                     part_to_actor=None, reason='not present in this submission')
        if p is not None:
            valid, visible = bool(p['valid']), bool(p['visible'])
            valid_mask |= int(valid) << index
            visible_mask |= int(visible) << index
            entry = dict(p, valid=valid, visible=visible, part_to_actor=None,
                         deformed_source=bool(p['flags'] & 0x1000),
                         matrix_only_reproduction_valid=valid and not bool(p['flags'] & 0x1000))
            if valid:
                _, entry['part_to_actor'] = part_matrices(p['matrix_q12'], p['pretranslation'],
                    p['translation0'], p['translation1'], a['renderer_root_q12'])
        parts.append(entry)
    return dict(sample_id=None, submission_sequence=frame['sequence'],
        guest_frame=frame['guest_frame'], capture_monotonic_ns=frame.get('capture_monotonic_ns'),
        capture_clock_known=bool(frame.get('clock_known',False)),
        time_seconds=None, actor_instance_id=dict(diagnostic_address=entity_address,
            generation=a['instance_generation'] if a['generation_known'] else None,
            generation_known=bool(a['generation_known'])),
        animation=a['animation'], action_id=a['action_id'],
        actor_to_world=actor, actor_world_q12=a['actor_world_q12'],
        renderer_root_q12=a['renderer_root_q12'], camera=frame['camera'],
        valid_mask=valid_mask, visible_mask=visible_mask, parts=parts)


def rtp_sequences(path):
    """Read live main/shadow submissions once, preserving draw order per tick."""
    result = defaultdict(list)
    current = None
    with Path(path).open() as stream:
        for line in stream:
            fields = line.split()
            if not fields or fields[0] not in ('PART','RTP'):
                continue
            frame = int(fields[1][1:])
            values = dict(s.split('=',1) for s in fields[2:] if '=' in s)
            if fields[0] == 'PART':
                raw = bytes.fromhex(values['raw'])
                if len(raw) != 64:
                    raise ValueError('incomplete live PART record')
                current = dict(frame=frame, object=int(values['obj'],16),
                    flags=struct.unpack_from('<I',raw)[0], inputs=[], camera_matrices_q12=[],
                    camera_q12=list(struct.unpack_from('<3i',raw,44)))
                result[frame].append(current)
            elif current is not None and current['frame'] == frame:
                current['inputs'].extend([list(map(int,values[f'v{k}'].split(',')))
                    for k in range(3) if f'v{k}' in values])
                rotation = list(map(int,values['R'].split(',')))
                if rotation not in current['camera_matrices_q12']:
                    current['camera_matrices_q12'].append(rotation)
    return result


def validate_live_rtp(frame, block, geometry, entity_address):
    """PC00 must be the proved first instance; never align by XY or nearest vertex."""
    if not frame['valid'] or frame['shadow_pass']:
        raise ValueError('only valid main submissions have a PC00 RTP oracle')
    if (frame['guest_frame'] != block['frame'] or
        frame['draw_object_address'] != block['object'] or
        frame['draw_flags'] != block['flags'] or
        frame['camera']['origin_q12'] != block['camera_q12']):
        raise ValueError('RTP and snapshot submission provenance disagree')
    if ('camera_matrices_q12' in block and
        frame['camera']['rotation_q12'] not in block['camera_matrices_q12']):
        raise ValueError('snapshot camera matrix disagrees with actual RTP GTE matrix')
    if not frame['instances'] or frame['instances'][0]['entity_address'] != entity_address:
        raise ValueError('PC00 is not the first proved actor; do not guess RTP offsets')
    actor = frame['instances'][0]
    parts = actor['parts']
    if [p['source_mesh_index'] for p in parts] != list(range(16)):
        raise ValueError('PC00 source parts are incomplete or reordered')
    camera = [v >> 12 for v in block['camera_q12']]
    expected = []
    for p in parts:
        if not p['visible']:
            continue
        if not p['valid'] or p['flags'] & 0x1000:
            raise ValueError('unknown or separately deformed vertex source in live proof')
        for v in geometry[p['source_mesh_index']]['vertices_local']:
            expected.append(fixed_vertex(v,p['matrix_q12'],p['pretranslation'],
                                        p['translation0'],p['translation1'],camera))
    if block['inputs'][:len(expected)] != expected:
        raise ValueError(f'live PC00 RTP mismatch at host frame {frame["guest_frame"]}')
    return len(expected)


def reference_data(ram_path, capture_path, disk_geometry_path, registry, root_q12, frame=2999):
    """Verify every RTP input first, then select and verify all 16 PC00 parts."""
    full = ce.read_capture(ram_path, capture_path, frame)
    blocks = ce.capture_blocks(capture_path,frame)
    ram = ce.Ram(Path(ram_path).read_bytes())
    selected = [p for p in full['parts'] if p['source_mesh_registry'] == registry]
    if sorted(p['source_mesh_index'] for p in selected) != list(range(16)):
        raise ValueError('PC00 reference must have exactly one of each source mesh 0..15')
    disk = json.loads(Path(disk_geometry_path).read_text())
    meshes = {m['mesh_index']: m for m in disk['meshes']}
    geometries, poses, errors = [], [], []
    local_wraps = final_wraps = 0
    camera_proofs = []
    for p in sorted(selected, key=lambda p: p['source_mesh_index']):
        index, addr = p['source_mesh_index'], p['source_address']
        t0 = [ram.i32(addr + 8 + k*4) for k in range(3)]
        t1 = [ram.i32(addr + 20 + k*4) for k in range(3)]
        r, pre = p['matrix_q12'], p['pretranslation']
        original = [v['position'] for v in meshes[index]['vertices']]
        deformed = bool(p['flags'] & 0x1000)
        if not deformed and p['vertices'] != original:
            raise ValueError(f'part {index}: local vertices differ from disk resource')
        actor, part = part_matrices(r, pre, t0, t1, root_q12)
        world_matrix = multiply(actor, part)
        world, float_world, actor_vertices = [], [], []
        for vertex, expected in zip(p['vertices'], p['posed_vertices']):
            local = [ce.signed16(vertex[k]+pre[k]) for k in range(3)]
            local_wraps += sum(vertex[k]+pre[k] != local[k] for k in range(3))
            unwrapped = [(sum(r[k*3+j]*local[j] for j in range(3)) >> 12)
                         + t0[k]+t1[k]-p['camera_world'][k] for k in range(3)]
            final_wraps += sum(unwrapped[k] != ce.signed16(unwrapped[k]) for k in range(3))
            actual = fixed_vertex(vertex, r, pre, t0, t1, p['camera_world'])
            if actual != expected:
                raise ValueError('independent fixed pose changed the verified RTP sequence')
            w = [actual[k]+p['camera_world'][k] for k in range(3)]
            fw = transform(world_matrix, vertex)
            world.append(w); float_world.append(fw)
            actor_vertices.append(transform(part, vertex))
            errors.extend(abs(fw[k]-w[k]) for k in range(3))
            # Independent cancellation: reconstruct translation from two
            # camera-relative inputs, then remove camera before building P.
            for camera in (p['camera_world'], [1001, -502, 303]):
                relative = [t0[k]+t1[k]-camera[k] for k in range(3)]
                _, candidate = part_matrices(r, pre, relative, camera, root_q12)
                camera_proofs.append(max(abs(a-b) for a, b in zip(part, candidate)))
        geometries.append(dict(source_mesh_index=index, vertices_local=p['vertices'],
            original_disk_vertices_local=original, faces=p['faces'],
            deformed_source=deformed, source_vertex_address=p['source_vertex_address']))
        poses.append(dict(source_mesh_index=index, valid=True, visible=True,
            part_to_actor=part, bind_matrix=part, inverse_bind_matrix=inverse(part),
            matrix_q12=r, pretranslation=pre, translation0=t0, translation1=t1,
            translation_camera_relative=p['translation_camera_relative'],
            camera_origin_q12=list(struct.unpack_from('<3i',blocks[p['capture_block']]['raw'],44)),
            camera_origin_integer=p['camera_world'], flags=p['flags'],
            deformed_source=deformed, raw_part_hex=ram.read(addr,80).hex(),
            diagnostic=dict(address=addr, capture_block=p['capture_block'],
                            part_index=p['part_index']),
            vertices_camera_relative_fixed=p['posed_vertices'],
            vertices_world_fixed=world, vertices_world_float=float_world,
            vertices_actor_float=actor_vertices))
    count = sum(len(g['vertices_local']) for g in geometries)
    if count != 430:
        raise ValueError(f'PC00 reference has {count} vertices, expected 430')
    # This retained reference has a separately proved entity→registry binding;
    # do not generalize its address to a runtime asset identity.
    entity = 0x80119710
    if ram.u32(entity+64) != registry:
        raise ValueError('retained PC00 entity does not own the selected registry')
    return dict(reference=dict(schema='a2.reference_pose.v1', captured_frame=frame,
        ram_dump_frame=3000 if frame == 2999 else None,
        actor_frame='world axes, render-root origin; rotation remains in parts',
        actor_to_world=actor, renderer_root_q12=list(root_q12),
        actor_world_q12=[ram.i32(entity+24+4*k) for k in range(3)],
        actor_offset_q12=[ram.i32(entity+36+4*k) for k in range(3)],
        actor_instance_id=dict(diagnostic_address=entity,generation=None,generation_known=False),
        valid_mask=65535, visible_mask=65535, parts=poses),
        geometry=dict(schema='a2.reference_geometry.v1', parts=geometries),
        validation=dict(fixed_point=dict(exact=True, flint_vertices=count,
            scene_vertices=full['verified_pose_vertices'], scene_parts=len(full['parts']),
            local_signed16_wrap_coordinates=local_wraps,
            final_signed16_wrap_coordinates=final_wraps),
            float_vs_fixed=dict(units='game units per coordinate',
                max_absolute_error=max(errors), mean_absolute_error=sum(errors)/len(errors),
                coordinates=len(errors), bit_exact=False),
            camera_independence=dict(method='two-origin algebraic reconstruction per vertex',
                comparisons=len(camera_proofs), max_matrix_difference=max(camera_proofs)),
            source=dict(ram_sha256=full['ram_sha256'], capture_sha256=full['capture_sha256'],
                disk_geometry_sha256=sha(disk_geometry_path))),
        parts=dict(schema='a2.parts.v1', source_key='PC00', source_mesh_ids=list(range(16)),
            original_joint_hierarchy_known=False, anatomical_rest_pose_known=False,
            chosen_bind_pose=f'captured PART/RTP {frame}',
            helper_rig='optional flat part drivers under one root; not original hierarchy',
            parts=[dict(source_mesh_index=i, joint_id=None, parent_id=None,
                        helper_driver_id=f'PC00/part/{i:02d}') for i in range(16)]))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest='command', required=True)
    p = sub.add_parser('reference')
    p.add_argument('--ram', type=Path, required=True)
    p.add_argument('--capture', type=Path, required=True)
    p.add_argument('--disk-geometry', type=Path, required=True)
    p.add_argument('--registry', type=lambda s: int(s,0), required=True)
    p.add_argument('--root-q12', type=int, nargs=3, required=True)
    p.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    data = reference_data(args.ram, args.capture, args.disk_geometry,
                          args.registry, args.root_q12)
    args.output.mkdir(parents=True, exist_ok=False)
    for key, filename in [('reference','reference_pose.json'),('geometry','geometry.json'),
                          ('validation','validation.json'),('parts','parts.json')]:
        write_json(args.output/filename, data[key])
    print(json.dumps(data['validation'], indent=2))


if __name__ == '__main__':
    main()
