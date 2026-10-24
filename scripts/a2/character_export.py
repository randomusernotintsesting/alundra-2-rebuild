"""Direct-source AL22 static character pose export; never matches screen XY.

Requires a matching RAM/MODELCAP snapshot. Every exported posed vertex must
equal the corresponding sequential RTP input before any output is written.
Source part/mesh/vertex/face addresses are retained for review, not a promise
of a stable on-disc packing format. Runtime lighting is not baked here.
"""
import argparse
import hashlib
import json
import struct
from pathlib import Path


class Ram:
    def __init__(self, data):
        self.data = bytes(data)
        if len(self.data) != 0x200000:
            raise ValueError('expected complete 2 MiB RAM snapshot')

    def read(self, address, size):
        if address < 0 or address > 0xffffffff:
            raise ValueError('invalid RAM address')
        physical = address & 0x1fffffff
        if size < 0 or physical + size > len(self.data):
            raise ValueError(f'out-of-range RAM read {address:08x}+{size}')
        return self.data[physical:physical + size]

    def u32(self, address):
        return struct.unpack('<I', self.read(address, 4))[0]

    def i32(self, address):
        return struct.unpack('<i', self.read(address, 4))[0]

    def u16(self, address):
        return struct.unpack('<H', self.read(address, 2))[0]

    def i16(self, address):
        return struct.unpack('<h', self.read(address, 2))[0]


def signed16(value):
    return (value + 32768) % 65536 - 32768


def pose_vertex(vertex, matrix, pretranslation, translation):
    local = [signed16(vertex[k] + pretranslation[k]) for k in range(3)]
    return [signed16((sum(matrix[k * 3 + j] * local[j] for j in range(3)) >> 12)
                     + translation[k]) for k in range(3)]


def to_blender(point):
    return [point[0], point[2], -point[1]]


def from_blender(point):
    return [point[0], -point[2], point[1]]


def triangles(face):
    """Corners in original source order; preserve AL22's 1--3 quad diagonal."""
    return [[0, 1, 2]] if len(face['indices']) == 3 else [[0, 1, 3], [1, 2, 3]]


def read_layer(ram, address):
    words = [ram.u32(address + i * 4) for i in range(9)]
    command = words[0] >> 24
    if command & 0xfc not in (0x30, 0x34, 0x38, 0x3c):
        raise ValueError(f'unsupported actor face command {command:02x} at {address:08x}')
    return {
        'command': command, 'textured': bool(command & 4),
        'source_template_address': address,
        'colors': [[(word >> shift) & 255 for shift in (0, 8, 16)] for word in words[:4]],
        'uv': [[word & 255, (word >> 8) & 255] for word in
               (words[4], words[5], words[6], words[6] >> 16)],
        'clut': words[4] >> 16, 'tpage': words[5] >> 16,
        'draw_mode': words[7], 'modifier_offset': words[8] & 255,
        'source_words': words,
    }


def read_faces(ram, header, vertex_count):
    count = ram.u16(header + 14)
    if count > 8192:
        raise ValueError('unbounded actor face count')
    address = header + 24
    result = []
    for index in range(count):
        flags = ram.u16(address)
        layers = [read_layer(ram, address + 8)]
        if flags & 4:
            layers.append(read_layer(ram, address + 44))
        corners = 4 if layers[0]['command'] & 8 else 3
        indices = list(ram.read(address + 4, 4))[:corners]
        if any(v >= vertex_count for v in indices):
            raise ValueError(f'face {index} indexes outside source vertices')
        if any((4 if layer['command'] & 8 else 3) != corners for layer in layers):
            raise ValueError('layer topology disagrees with source face')
        result.append({'source_address': address, 'source_index': index,
                       'flags': flags, 'indices': indices, 'layers': layers})
        address += 80 if flags & 4 else 44
    return result


def capture_blocks(path, frame):
    blocks = []
    current = None
    for line in Path(path).read_text().splitlines():
        fields = line.split()
        if not fields or fields[0] not in ('PART', 'RTP'):
            continue
        line_frame = int(fields[1][1:])
        values = dict(field.split('=', 1) for field in fields[2:] if '=' in field)
        if fields[0] == 'PART':
            current = None
            if line_frame == frame:
                raw = bytes.fromhex(values['raw'])
                if len(raw) != 64:
                    raise ValueError('PART header must contain all 64 captured bytes')
                current = {'object': int(values['obj'], 16), 'raw': raw,
                           'inputs': [], 'camera_transforms': []}
                blocks.append(current)
        elif current is not None and line_frame == frame:
            for k in range(3):
                if f'v{k}' in values:
                    current['inputs'].append(list(map(int, values[f'v{k}'].split(','))))
            transform = {'R': list(map(int, values['R'].split(','))),
                         'TR': list(map(int, values['TR'].split(',')))}
            if transform not in current['camera_transforms']:
                current['camera_transforms'].append(transform)
    if not blocks:
        raise ValueError(f'no actor PART block at frame {frame}')
    return blocks


def read_capture(ram_path, capture_path, frame):
    ram = Ram(Path(ram_path).read_bytes())
    blocks = capture_blocks(capture_path, frame)
    parts, excluded = [], []
    verified = 0
    for block_index, block in enumerate(blocks):
        raw = block['raw']
        flags = struct.unpack_from('<I', raw)[0]
        if flags & 0x100:
            raise ValueError('shadow actor pass is not a character pose')
        address = struct.unpack_from('<I', raw, 20)[0]
        camera = [struct.unpack_from('<i', raw, 44 + k * 4)[0] >> 12 for k in range(3)]
        inputs = []
        for part_index in range(4096):
            node_flags = ram.u16(address)
            if node_flags & 0x8000:
                break
            if node_flags & 7 or node_flags & 0x200:
                excluded.append({'source_address': address, 'flags': node_flags,
                                 'reason': 'non-drawn record (state/light/disabled)'})
                address += 80
                continue
            mesh_index = ram.u16(address + 2)
            registry = ram.u32(address + 60)
            header = ram.u32(registry + 32 + mesh_index * 4)
            if header == 0xffffffff:
                excluded.append({'source_address': address, 'flags': node_flags,
                                 'reason': 'source registry marks mesh absent'})
                address += 80
                continue
            count = ram.u16(header + 16)
            if count > 256:
                raise ValueError('actor vertex count exceeds 8-bit face index contract')
            vertex_address = ram.u32(address + 4) if node_flags & 0x1000 else ram.u32(header + 20)
            vertices = [[ram.i16(vertex_address + i * 16 + k * 2) for k in range(3)] for i in range(count)]
            matrix = [ram.i16(address + 32 + i * 2) for i in range(9)]
            pre = [ram.i16(address + 52 + i * 2) for i in range(3)]
            translation = [ram.i32(address + 8 + k * 4) + ram.i32(address + 20 + k * 4)
                           - camera[k] for k in range(3)]
            posed = [pose_vertex(v, matrix, pre, translation) for v in vertices]
            part = {'capture_block': block_index, 'part_index': part_index,
                    'source_address': address, 'source_mesh_registry': registry,
                    'source_mesh_index': mesh_index, 'source_model_header': header,
                    'source_vertex_address': vertex_address, 'flags': node_flags,
                    'vertices': vertices, 'posed_vertices': posed,
                    'matrix_q12': matrix, 'pretranslation': pre,
                    'translation_camera_relative': translation, 'camera_world': camera,
                    'faces': read_faces(ram, header, count), 'pose_verified': False}
            parts.append(part)
            inputs.extend(posed)
            address += 80
        else:
            raise ValueError('part list has no bounded terminator')
        if inputs != block['inputs']:
            mismatch = next((i for i, (a, b) in enumerate(zip(inputs, block['inputs'])) if a != b), None)
            detail = (f' first mismatch {mismatch}: computed={inputs[mismatch]}, captured={block["inputs"][mismatch]}'
                      if mismatch is not None else '')
            raise ValueError(f'pose proof failed: source {len(inputs)} versus RTP {len(block["inputs"])} vertices;{detail}')
        for part in parts:
            if part['capture_block'] == block_index:
                part['pose_verified'] = True
        verified += len(inputs)
    return {'format': 'a2-static-actor-v1', 'frame': frame, 'parts': parts,
            'excluded_records': excluded, 'verified_pose_vertices': verified,
            'ram_sha256': hashlib.sha256(ram.data).hexdigest(),
            'capture_sha256': hashlib.sha256(Path(capture_path).read_bytes()).hexdigest(),
            'capture_camera_transforms': [b['camera_transforms'] for b in blocks],
            'limits': ['Static posed geometry; no inferred rig or hidden missing meshes.',
                       'Original source corner colors, not captured runtime GTE lighting.',
                       'Dynamic material modifiers and layered PS1 blending require separate validation.',
                       'Source addresses identify this capture, not stable on-disc replacement IDs.']}


def vram_texel(data, tpage, clut, u, v):
    if len(data) != 1024 * 512 * 2:
        raise ValueError('expected 1 MiB VRAM snapshot')
    def word(x, y):
        return struct.unpack_from('<H', data, (((y & 511) * 1024) + (x & 1023)) * 2)[0]
    x, y = (tpage & 15) * 64, ((tpage >> 4) & 1) * 256
    mode = (tpage >> 7) & 3
    u, v = u & 255, v & 255
    if mode < 2:
        index = ((word(x + (u >> 2), y + v) >> ((u & 3) * 4)) & 15) if mode == 0 else ((word(x + (u >> 1), y + v) >> ((u & 1) * 8)) & 255)
        color = word((clut & 63) * 16 + index, (clut >> 6) & 511)
    elif mode == 2:
        color = word(x + u, y + v)
    else:
        raise ValueError('reserved PS1 texture depth')
    return [((color >> k) & 31) * 255 // 31 for k in (0, 5, 10)] + [255 if color else 0, bool(color & 0x8000)]


def export_bundle(ram_path, capture_path, vram_path, frame, registry, output):
    """Create a new, self-contained immutable-input pilot directory."""
    from PIL import Image
    data = read_capture(ram_path, capture_path, frame)
    data['parts'] = [part for part in data['parts'] if part['source_mesh_registry'] == registry]
    if not data['parts']:
        raise ValueError('selected source registry has no verified parts')
    vram = Path(vram_path).read_bytes()
    if len(vram) != 0x100000:
        raise ValueError('expected 1 MiB VRAM snapshot')
    data['vram_sha256'] = hashlib.sha256(vram).hexdigest()
    data['selected_registry'] = registry
    data['selected_vertices'] = sum(len(p['vertices']) for p in data['parts'])
    data['selected_faces'] = sum(len(p['faces']) for p in data['parts'])
    keys = sorted({(layer['tpage'], layer['clut']) for part in data['parts']
                   for face in part['faces'] for layer in face['layers'] if layer['textured']})
    output = Path(output)
    output.mkdir(parents=True, exist_ok=False)
    textures = []
    for page, clut in keys:
        name = f'texture-{page:03x}-{clut:04x}.png'
        rgba, stp = bytearray(), bytearray()
        for y in range(256):
            for x in range(256):
                pixel = vram_texel(vram, page, clut, x, y)
                rgba.extend(pixel[:4]); stp.append(255 if pixel[4] else 0)
        Image.frombytes('RGBA', (256, 256), bytes(rgba)).save(output / name)
        Image.frombytes('L', (256, 256), bytes(stp)).save(output / name.replace('.png', '-stp.png'))
        textures.append({'tpage': page, 'clut': clut, 'file': name,
                         'stp_file': name.replace('.png', '-stp.png')})
    data['textures'] = textures
    data['inputs'] = {'ram': str(Path(ram_path).resolve()),
                      'capture': str(Path(capture_path).resolve()),
                      'vram': str(Path(vram_path).resolve())}
    (output / 'character.json').write_text(json.dumps(data, indent=2) + '\n')
    return output / 'character.json'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--ram', type=Path, required=True)
    parser.add_argument('--capture', type=Path, required=True)
    parser.add_argument('--frame', type=int, required=True)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    data = read_capture(args.ram, args.capture, args.frame)
    with args.out.open('x') as output:
        json.dump(data, output, indent=2)
        output.write('\n')
    print(f'{len(data["parts"])} parts; all {data["verified_pose_vertices"]} posed vertices verified')


if __name__ == '__main__':
    main()
