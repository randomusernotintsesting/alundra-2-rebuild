"""Previous-scanline codec used by GAME02/03 embedded font resources.

Derived from JP GAME02 80087848..80087C68, not PACK0's chunk codec.
128 packed bytes form a 256-pixel 4bpp scanline. References address the
previous complete scanline, initially zero; flags are consumed MSB first.
This deliberately rejects out-of-line references rather than reading the
guest decoder's unrelated scratch memory. Never writes source assets.
"""
import struct


def resource(data, offset, base=0x800811D8, size=32768):
    if offset < 0 or offset + 12 > len(data):
        raise ValueError('font resource header outside file')
    flags, palette, stream = struct.unpack_from('<III', data, offset)
    if flags != 1:
        raise ValueError('unsupported font resource pointer mode')
    palette -= base
    stream -= base
    if palette < offset + 12 or palette + 64 > stream or stream >= len(data):
        raise ValueError('font resource pointer outside file or overlapping')
    pixels, consumed = decode(data[stream:], size)
    return {'pixels': pixels, 'palette': data[palette:palette + 64],
            'palette_start': palette, 'stream_start': stream,
            'stream_end': stream + consumed}


def decode(data, size=32768):
    if not 0 <= size <= 32768 or not data:
        raise ValueError("invalid font output size or empty stream")
    if data[0] == 0x23:
        if len(data) < size + 1:
            raise ValueError("truncated raw font")
        return bytes(data[1:size + 1]), size + 1
    pos = 1
    out = bytearray()
    previous = bytes(128)
    mask = flags = 0
    while len(out) < size:
        if not mask:
            if pos >= len(data):
                raise ValueError("truncated font flags")
            flags = data[pos]
            pos += 1
            mask = 128
        if flags & mask:
            if pos + 2 > len(data):
                raise ValueError("truncated font reference")
            start, count = data[pos], data[pos + 1] + 3
            pos += 2
            if start + count > 128 or len(out) % 128 + count > 128:
                raise ValueError("font reference crosses scanline")
            if len(out) + count > size:
                raise ValueError("font reference exceeds output")
            out.extend(previous[start:start + count])
        else:
            if pos >= len(data):
                raise ValueError("truncated font literal")
            out.append(data[pos])
            pos += 1
        if len(out) % 128 == 0:
            previous = bytes(out[-128:])
        mask >>= 1
    return bytes(out), pos


def encode(raw):
    raw = bytes(raw)
    if len(raw) > 32768:
        raise ValueError("font exceeds 256 scanlines")
    out = bytearray([0])
    previous = bytes(128)
    pos = mask = flag_at = 0
    while pos < len(raw):
        if not mask:
            flag_at = len(out)
            out.append(0)
            mask = 128
        limit = min(128 - pos % 128, len(raw) - pos)
        best_start = best_count = 0
        for start in range(128):
            count = 0
            while count < min(limit, 128 - start) and previous[start + count] == raw[pos + count]:
                count += 1
            if count > best_count:
                best_start, best_count = start, count
        if best_count >= 3:
            out[flag_at] |= mask
            out.extend((best_start, best_count - 3))
            pos += best_count
        else:
            out.append(raw[pos])
            pos += 1
        if pos % 128 == 0:
            previous = raw[pos - 128:pos]
        mask >>= 1
    plain = b"#" + raw
    return bytes(out) if len(out) < len(plain) else plain
