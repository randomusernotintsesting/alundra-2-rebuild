#!/usr/bin/env python3
"""Read-only GAME02/03 font extraction; writes PNG/JSON evidence, never BINs."""
import argparse
import hashlib
import json
from pathlib import Path
import struct

from PIL import Image
from a2.minigame_font import resource, encode, decode


SOURCES = {
    'GAME02.BIN': (0xd584, 0x80087d58, 'f7186b984b871050b1ab9e766d47b068a17a0f44b062d29e89fb0a76ae515308'),
    'GAME03.BIN': (0xe71c, 0x80086d50, '95e4e318dcb21832e98f714ec231ce91085d20b72932d367b6019f5308469601'),
}
BASE = 0x800811d8


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--disc', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    report = {}
    for name, (offset, metric_base, expected_hash) in SOURCES.items():
        data = (args.disc / name).read_bytes()
        source_hash = hashlib.sha256(data).hexdigest()
        if source_hash != expected_hash:
            raise SystemExit(f'{name}: unexpected source SHA-256; refusing stale offsets')
        font = resource(data, offset)
        packed = font['pixels']
        encoded = encode(packed)
        if decode(encoded) != (packed, len(encoded)):
            raise SystemExit('font codec roundtrip failed')
        pixels = [n for byte in packed for n in (byte & 15, byte >> 4)]
        palette = struct.unpack('<16H', font['palette'][:32])
        rgb = [((v & 31) * 255 // 31, ((v >> 5) & 31) * 255 // 31,
                ((v >> 10) & 31) * 255 // 31) for v in palette]
        image = Image.new('RGB', (256, 256))
        image.putdata([rgb[v] for v in pixels])
        image.save(args.output / (name + '.font.png'))
        image.resize((768, 768), Image.Resampling.NEAREST).save(
            args.output / (name + '.font.3x.png'))
        metrics = {}
        for code in range(33, 96):
            at = metric_base - BASE + code * 8
            metrics[f'{code:02X}'] = dict(zip(('u', 'v', 'width', 'advance'),
                                             struct.unpack_from('<4H', data, at)))
        report[name] = {
            'source_sha256': source_hash,
            'header_offset': hex(offset),
            'palette_offset': hex(font['palette_start']),
            'stream_offset': hex(font['stream_start']),
            'stream_end': hex(font['stream_end']),
            'compressed_budget_bytes': font['stream_end'] - font['stream_start'],
            'following_bytes': data[font['stream_end']:font['stream_end'] + 16].hex(),
            'packed_sha256': hashlib.sha256(packed).hexdigest(),
            'reencoded_bytes': len(encoded),
            'reencoded_identical': encoded == data[font['stream_start']:font['stream_end']],
            'palette_first16': [f'{v:04X}' for v in palette],
            'metric_address_before_byte_indexing': hex(metric_base),
            'metrics': metrics,
        }
    (args.output / 'font-boundaries.json').write_text(
        json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({name: {k: v for k, v in info.items() if k != 'metrics'}
                      for name, info in report.items()}, indent=2))


if __name__ == '__main__':
    main()
