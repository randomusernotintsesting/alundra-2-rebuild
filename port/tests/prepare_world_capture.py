"""Validate a captured OT against live provenance; prepare an offline workload.

Every linked-list command is retained, including DrawEnv and secondary lists.
This is a post-frame VRAM workload, not historical screenshot reconstruction.
"""
import argparse
from collections import Counter, defaultdict
from decimal import Decimal, ROUND_HALF_EVEN
import hashlib
import json
import math
from pathlib import Path
import re
import struct

RECORD = struct.Struct('<IIIqqdQQII')
MAGIC = b'A2OTQ16\n'
CAMERA_RECORD = struct.Struct('<IIIqqdQQIIIQ')
CAMERA_MAGIC = b'A2OTC24\n'


def physical(address):
    p = address & 0x1FFFFFFF
    if p < 0x800000:
        return p & 0x1FFFFF
    if 0x1F800000 <= p < 0x1F800400:
        return p
    raise ValueError(f'unsupported address {address:08x}')


def read_lists(ram, roots):
    stream, summaries = [], []
    for root in roots:
        address = physical(root)
        seen = set()
        start = len(stream)
        while address != 0xFFFFFF:
            if address in seen:
                raise ValueError(f'linked-list cycle at {address:08x}')
            if address & 3 or address + 4 > len(ram):
                raise ValueError('invalid linked-list address')
            seen.add(address)
            if len(seen) > 100000:
                raise ValueError('linked-list node bound')
            header, = struct.unpack_from('<I', ram, address)
            count = header >> 24
            if address + 4 + count * 4 > len(ram):
                raise ValueError('linked-list packet outside RAM')
            for i in range(count):
                at = address + 4 + i * 4
                word, = struct.unpack_from('<I', ram, at)
                stream.append(dict(address=at, word=word, node=address))
            address = header & 0xFFFFFF
            if address == 0:
                break
            if address != 0xFFFFFF:
                address = physical(address)
        summaries.append(dict(root=f'{root:08x}', nodes=len(seen), words=len(stream)-start))
    return stream, summaries


def command_length(command):
    if command < 0x20:
        return 3 if command == 2 else 1
    if command < 0x40:
        n = 4 if command & 8 else 3
        return 1 + n * (1 + bool(command & 4) + bool(command & 16)) - bool(command & 16)
    if command < 0x60:
        return -1 if command & 8 else (4 if command & 16 else 3)
    if command < 0x80:
        return 2 + bool(command & 4) + ((command >> 3) & 3 == 0)
    if command < 0xA0:
        return 4
    if command < 0xE0:
        return 3
    return 1


def signed11(n):
    n &= 2047
    return n - 2048 if n & 1024 else n


def decode_polygons(stream):
    polygons = []
    cursor = 0
    draw_x = draw_y = 0
    while cursor < len(stream):
        command = stream[cursor]['word'] >> 24
        count = command_length(command)
        if count < 0:
            # GPU treats a polyline as terminated by this bit pattern. Keep
            # the entire original sequence, including its terminator.
            count = 1
            while cursor + count < len(stream):
                value = stream[cursor+count]['word']
                count += 1
                if value & 0xF000F000 == 0x50005000:
                    break
            else:
                raise ValueError('unterminated polyline')
        if cursor + count > len(stream):
            raise ValueError('truncated GPU command stream')
        words = stream[cursor:cursor+count]
        if 0x20 <= command < 0x40:
            vertices = []
            k = 1
            for i in range(4 if command & 8 else 3):
                if i and command & 16:
                    k += 1
                vertices.append(words[k])
                k += 1 + bool(command & 4)
            polygons.append(dict(command=command, vertices=vertices, draw_x=draw_x, draw_y=draw_y))
        elif command == 0xE5:
            draw_x = signed11(words[0]['word'])
            draw_y = signed11(words[0]['word'] >> 11)
        elif 0xA0 <= command < 0xC0:
            size = words[2]['word']
            width = ((size-1) & 1023) + 1
            height = (((size >> 16)-1) & 511) + 1
            count += (width * height + 1) // 2
            if cursor + count > len(stream):
                raise ValueError('truncated VRAM upload')
        cursor += count
    return polygons


def parsed_trace(path):
    events, primitives = [], []
    current = None
    with path.open() as source:
        for number, line in enumerate(source, 1):
            match = re.match(r'world-precision f=(\d+) (\S+) (.*)', line)
            if not match:
                continue
            frame, stage, rest = match.groups()
            event = dict(re.findall(r'(\w+)=([^\s]+)', rest))
            event.update(frame=int(frame), stage=stage, line=number, miss=' miss' in line)
            for name in ('projection', 'generation', 'consumer', 'complete', 'object', 'code_version',
                         'code_valid', 'draw_x', 'draw_y', 'disp_x', 'disp_y', 'x', 'y', 'w', 'h',
                         'kind', 'camera'):
                if name in event:
                    event[name] = int(event[name])
            for name in ('pc', 'addr', 'src', 'word', 'producer', 'code_hash', 'context', 'scratch'):
                if name in event:
                    event[name] = int(event[name], 16)
            event.setdefault('kind', 0)
            event.setdefault('camera', 0)
            events.append(event)
            if stage == 'primitive':
                current = dict(event, vertices=[])
                primitives.append(current)
            elif stage == 'consume':
                if current is None or current['frame'] != event['frame']:
                    raise ValueError('consume without primitive')
                current['vertices'].append(event)
    return events, primitives


def match_sequence(polygons, primitives):
    if len(polygons) != len(primitives):
        raise ValueError(f'polygon sequence length: OT {len(polygons)} trace {len(primitives)}')
    for index, (polygon, primitive) in enumerate(zip(polygons, primitives)):
        a = [(v['address'], v['word']) for v in polygon['vertices']]
        b = [(physical(v['addr']), v['word']) for v in primitive['vertices']]
        if a != b:
            raise ValueError(f'polygon sequence mismatch at {index}, consumer {primitive["consumer"]}')
        if any(polygon[k] != primitive[k] for k in ('draw_x', 'draw_y')):
            raise ValueError(f'draw environment mismatch at polygon {index}')


def fixed_decimal(text, scale):
    value = Decimal(text)
    if not value.is_finite():
        raise ValueError('nonfinite trace precision')
    integer = int((value * scale).to_integral_value(rounding=ROUND_HALF_EVEN))
    if abs(value - Decimal(integer) / scale) > Decimal('0.0000000005001'):
        raise ValueError(f'trace precision is not recoverable Q{int(math.log2(scale))}: {text}')
    return integer


def trace_index(events):
    index = defaultdict(list)
    for event in events:
        if 'projection' in event and not event['miss']:
            index[(event['stage'], event['projection'])].append(event)
    return index


def prove_primitive(primitive, events, index=None):
    index = trace_index(events) if index is None else index
    if not primitive['complete'] or len(primitive['vertices']) not in (3, 4):
        raise ValueError('incomplete primitive cannot acquire tags')
    proof = []
    source_objects = set()
    packet_generations = set()
    projection_modes = set()
    for vertex in primitive['vertices']:
        if vertex['miss']:
            raise ValueError('complete primitive contains missed vertex')
        def previous(stage, before, predicate):
            found = [e for e in index[(stage, vertex['projection'])]
                     if e['line'] < before and e['word'] == vertex['word'] and predicate(e)]
            if not found:
                raise ValueError(f'missing {stage} proof for consumer {primitive["consumer"]}')
            return found[-1]
        packet = previous('packet', vertex['line'], lambda e:
                          physical(e['addr']) == physical(vertex['addr']) and
                          e['generation'] == vertex['generation'] and
                          physical(e['src']) == physical(vertex['src']))
        record = previous('record', packet['line'], lambda e:
                          physical(e['addr']) == physical(packet['src']))
        read = previous('mfc2', record['line'], lambda e: True)
        project = previous('project', read['line'], lambda e: True)
        producer = vertex['producer']
        contract = {
            0x80010D4C: (0x80010D98, {0x80010DAC}, {0x800128AC, 0x80012988}),
            0x8001338C: (0x80013400, {0x80013408, 0x8001341C},
                         {0x80013FF8, 0x80014248, 0x80013F04, 0x80014140}),
        }.get(producer)
        if not contract or project['pc'] != producer or read['pc'] != contract[0] or \
                record['pc'] not in contract[1] or packet['pc'] not in contract[2]:
            raise ValueError('unsupported producer/consumer hook contract')
        kind, camera = vertex.get('kind', 0), vertex.get('camera', 0)
        if kind not in (0, 1) or camera < 0 or camera > 0xFFFFFFFFFFFFFFFF:
            raise ValueError('unsupported projection kind/camera generation')
        metadata = (vertex['xy'], vertex['z'], vertex['producer'], kind, camera)
        if any((e['xy'], e['z'], e['producer'], e.get('kind', 0), e.get('camera', 0)) != metadata
               for e in (project, read, record, packet)):
            raise ValueError('provenance metadata changed between stages')
        chain = (project, read, record, packet, vertex)
        if kind == 1:
            if not camera or camera != record['generation']:
                raise ValueError('camera generation differs from source object generation')
            native = previous('project-native', project['line'], lambda e: True)
            if native['pc'] != producer or native['producer'] != producer or \
                    native.get('kind', 0) != 0 or native.get('camera', 0) != 0:
                raise ValueError('invalid project-native identity')
            nx, ny = [fixed_decimal(v, 65536) for v in native['xy'].split(',')]
            nz = fixed_decimal(native['z'], 4096)
            word = vertex['word']
            sx = (word & 65535) - (65536 if word & 32768 else 0)
            sy = (word >> 16) - (65536 if word & 0x80000000 else 0)
            if nz <= 0 or (nx // 65536, ny // 65536) != (sx, sy) or \
                    not (-1024 <= sx < 1024 and -1024 <= sy < 1024):
                raise ValueError('project-native Q16 does not prove native coordinate/depth')
            chain = (native, *chain)
        elif camera:
            raise ValueError('native projection has a camera generation')
        qx, qy = [fixed_decimal(v, 65536) for v in vertex['xy'].split(',')]
        depth_scale = 16777216 if kind == 1 else 4096
        depth = fixed_decimal(vertex['z'], depth_scale) / depth_scale
        if depth <= 0 or not (-1024*65536 <= qx < 1024*65536 and -1024*65536 <= qy < 1024*65536):
            raise ValueError('invalid projected coordinate/depth')
        if kind == 1 and not (1/4096 <= depth < 65536):
            raise ValueError('camera depth outside supported projection range')
        word = vertex['word']
        sx = (word & 65535) - (65536 if word & 32768 else 0)
        sy = (word >> 16) - (65536 if word & 0x80000000 else 0)
        if kind == 0 and (qx // 65536, qy // 65536) != (sx, sy):
            raise ValueError('Q16 does not floor to native packet coordinate')
        source_objects.add(record['generation'])
        packet_generations.add(packet['generation'])
        projection_modes.add((kind, camera))
        proof.append(dict(address=physical(vertex['addr']), word=word, qx=qx, qy=qy, z=depth,
                          projection=vertex['projection'], generation=packet['generation'],
                          producer=producer, source=physical(vertex['src']),
                          source_generation=record['generation'],
                          kind=kind, camera=camera,
                          lines={e['stage']: e['line'] for e in chain}))
    if len(source_objects) != 1:
        raise ValueError('mixed source object generations')
    if len(packet_generations) != 1:
        raise ValueError('mixed packet generations')
    if len(projection_modes) != 1:
        raise ValueError('mixed projection kind/camera generations')
    return proof


def fnv_bytes(data):
    value = 14695981039346656037
    for byte in data:
        value = ((value ^ byte) * 1099511628211) & 0xFFFFFFFFFFFFFFFF
    return value


def encode_workload(stream, tags, ram_fnv, polygon_count, seeded_count):
    camera = any(v.get('kind', 0) == 1 for v in tags.values())
    schema, magic, record = (2, CAMERA_MAGIC, CAMERA_RECORD) if camera else (1, MAGIC, RECORD)
    payload = bytearray(magic + struct.pack('<IQII', len(stream), ram_fnv, polygon_count, seeded_count))
    for command in stream:
        tag = tags.get(command['address'], {})
        values = (command['address'], command['word'], command['node'],
                  tag.get('qx', 0), tag.get('qy', 0), tag.get('z', 0),
                  tag.get('projection', 0), tag.get('generation', 0),
                  tag.get('producer', 0), tag.get('source', 0))
        if camera:
            values += (tag.get('kind', 0), tag.get('camera', 0))
        payload += record.pack(*values)
    return payload, schema


def prepare(ram_path, trace_path, frame, roots, output):
    ram = ram_path.read_bytes()
    if len(ram) != 2*1024*1024:
        raise ValueError('RAM must be exactly 2 MiB')
    code_hash = fnv_bytes(ram[0x10000:0x157B0])
    if code_hash != 0x5E1437C3F76CFA12:
        raise ValueError('RAM AL22 producer code identity is unsupported')
    events, primitives = parsed_trace(trace_path)
    consumers = [p for p in primitives if p['frame'] == frame]
    sequence = [p['consumer'] for p in primitives]
    if not sequence or sequence != sorted(set(sequence)):
        raise ValueError('non-monotonic consumer sequence')
    stream, summaries = read_lists(ram, roots)
    polygons = decode_polygons(stream)
    match_sequence(polygons, consumers)
    index = trace_index(events)
    tags, proofs = {}, []
    for primitive in consumers:
        if not primitive['complete']:
            continue  # Exact original whole-primitive fallback is retained.
        proof = prove_primitive(primitive, events, index)
        for vertex in proof:
            address = vertex['address']
            if struct.unpack_from('<I', ram, address)[0] != vertex['word']:
                raise ValueError('seed packet word differs from RAM')
            if address in tags and tags[address] != vertex:
                raise ValueError('packet address reused by different consumed generations')
            tags[address] = vertex
        proofs.append(dict(consumer=primitive['consumer'], vertices=proof))
    # Offline seeding happens before timing. Require no map collision across
    # this particular immutable workload, rather than silently evicting tags.
    slots = {}
    for address in tags:
        slot = ((address >> 2) ^ (address >> 17)) & 32767
        if slot in slots and slots[slot] != address:
            raise ValueError('packet tag-map collision: upfront restoration unsupported')
        slots[slot] = address
    ram_fnv = fnv_bytes(ram)
    payload, schema = encode_workload(stream, tags, ram_fnv, len(polygons), len(proofs))
    manifest = dict(schema=schema, frame=frame, roots=summaries, command_words=len(stream),
                    polygons=len(polygons), live_complete=sum(p['complete'] for p in consumers),
                    seeded_primitives=len(proofs), seeded_vertices=len(tags),
                    provenance_by_producer=dict(Counter(f'{v["producer"]:08x}' for v in tags.values())),
                    ram_sha256=hashlib.sha256(ram).hexdigest(), ram_fnv64=f'{ram_fnv:016x}',
                    trace_sha256=hashlib.sha256(trace_path.read_bytes()).hexdigest(),
                    workload_sha256=hashlib.sha256(payload).hexdigest(), code_fnv64=f'{code_hash:016x}',
                    caveat='Post-frame VRAM workload; no historical HD screenshot or temporal wobble claim.',
                    proof=proofs)
    output.mkdir(parents=True, exist_ok=False)
    (output/'workload.bin').write_bytes(payload)
    (output/'manifest.json').write_text(json.dumps(manifest, indent=2)+'\n')
    return manifest


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--ram', type=Path, required=True)
    parser.add_argument('--trace', type=Path, required=True)
    parser.add_argument('--frame', type=int, required=True)
    parser.add_argument('--root', type=lambda x: int(x, 0), action='append', required=True,
                        help='Complete list roots in submission order: DrawEnv, world, secondary')
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    result = prepare(args.ram, args.trace, args.frame, args.root, args.output)
    print(json.dumps({k: v for k, v in result.items() if k != 'proof'}, indent=2))


if __name__ == '__main__':
    main()
