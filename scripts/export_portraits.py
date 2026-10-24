"""Lossless portrait extraction for external HD editing; never edits game data."""
import argparse
import csv
import hashlib
import json
from pathlib import Path
import struct
from PIL import Image, ImageDraw
from a2.pak import PakArchive
from menu_texture_patch import parse_container, unpack_indices

ROOT = Path(__file__).resolve().parents[1]
DEFAULT_PAK = ROOT / 'port/build/verification/full-menu-v5/DATA/PACK0.PAK'


def decode_rgba(indices, palette):
    colors = []
    for value, in struct.iter_unpack('<H', palette):
        rgb = tuple((((value >> shift) & 31) << 3) | (((value >> shift) & 31) >> 2)
                    for shift in (0, 5, 10))
        # PS1 transparent color is the entire zero word, not palette index0.
        # STP is preserved in palette.bin; it does not mean alpha128 by itself.
        colors.append(bytes((*rgb, 0 if value == 0 else 255)))
    if not indices or max(indices) >= len(colors):
        raise ValueError('portrait index outside supplied palette')
    return b''.join(colors[index] for index in indices)


def export_portraits(pak_path, output):
    pak_path, output = Path(pak_path), Path(output)
    if output.exists():
        raise FileExistsError(output)
    archive = PakArchive.load(pak_path)
    prepared = []
    for slot in range(14):
        data = archive.slots[slot]
        width, height, palette, chunks = parse_container(data)
        if (width, height, len(chunks), len(palette), chunks[0]['bpp']) != (40, 48, 1, 512, 8):
            raise ValueError(f'unknown portrait container in slot{slot}')
        indices = unpack_indices(chunks[0]['raw'], width, height, 8)
        rgba = decode_rgba(indices, palette)
        prepared.append((slot, data, palette, indices, rgba))
    output.mkdir(parents=True, exist_ok=False)
    (output / 'PNG').mkdir()
    (output / 'Исходные данные').mkdir()
    records = []
    sheet = Image.new('RGB', (7*128, 2*172), (29, 32, 39))
    draw = ImageDraw.Draw(sheet)
    for slot, data, palette, indices, rgba in prepared:
        stem = f'portrait_{slot:02d}_PACK0_{slot:03d}'
        filename = stem + '.png'
        portrait = Image.frombytes('RGBA', (40, 48), rgba)
        portrait.save(output / 'PNG' / filename)
        rawdir = output / 'Исходные данные' / stem
        rawdir.mkdir()
        (rawdir / 'container.bin').write_bytes(data)
        (rawdir / 'indices.bin').write_bytes(indices)
        (rawdir / 'palette.bin').write_bytes(palette)
        x, y = (slot % 7)*128+4, (slot // 7)*172+4
        preview = portrait.resize((120, 144), Image.Resampling.NEAREST)
        sheet.paste(preview, (x, y), preview)
        draw.text((x+12, y+148), f'ID {slot:02d} / slot{slot:03d}', fill=(235, 235, 230))
        records.append(dict(slot=slot, file=filename, width=40, height=48, bpp=8,
                            chunk=0, palette=0, slot_sha256=hashlib.sha256(data).hexdigest(),
                            indices_sha256=hashlib.sha256(indices).hexdigest(),
                            rgba_sha256=hashlib.sha256(rgba).hexdigest(),
                            transparent_pixels=sum(rgba[i] == 0 for i in range(3,len(rgba),4))))
    sheet.save(output / 'Все портреты — обзор.png')
    manifest = dict(source_pak=str(pak_path.resolve()),
                    source_pak_sha256=hashlib.sha256(pak_path.read_bytes()).hexdigest(),
                    extraction='Original native codec2, no crop/upscale/repaint; RGB5 expanded to RGB8',
                    transparency='palette word0000 transparent; STP retained separately in palette.bin',
                    portraits=records)
    (output / 'manifest.json').write_text(json.dumps(manifest, ensure_ascii=False, indent=2)+'\n')
    with (output / 'Портреты.csv').open('w', encoding='utf-8-sig', newline='') as stream:
        writer = csv.writer(stream)
        writer.writerow(('ID', 'Файл', 'Ширина', 'Высота', 'Архив', 'Слот', 'SHA256 контейнера'))
        for record in records:
            writer.writerow((record['slot'], record['file'], 40, 48, 'PACK0.PAK', record['slot'], record['slot_sha256']))
    (output / 'Как подготовить HD.txt').write_text(
        'Alundra 2 — 14 исходных портретов персонажей\n\n'
        'Папка PNG: оригиналы40×48, без увеличения, обрезки и перерисовки.\n'
        'Прозрачный фон сохранён. Имена файлов содержат точные ID и слоты игры;\n'
        'имена персонажей намеренно не угадывались. Обзорный лист увеличен3×\n'
        'ближайшим соседом только для удобства просмотра.\n\n'
        'Для HD удобно сделать160×192 (4×) или320×384 (8×). Сохраняй пропорции5:6,\n'
        'положение головы, прозрачный фон и имя каждого PNG. Не объединяй портреты\n'
        'в одну картинку и не добавляй рамку или подпись. Исходники лучше оставить\n'
        'нетронутыми, а результаты вернуть отдельной папкой.\n\n'
        'Портреты.csv и manifest.json связывают картинки с исходными ресурсами.\n'
        'В «Исходные данные» сохранены контейнеры, индексы и палитры для точного\n'
        'обратного сопоставления. Значение STP палитры не превращалось произвольно\n'
        'в полупрозрачность. Архив игры, приложение и сохранения не менялись.\n', encoding='utf-8')
    return records


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--pak', type=Path, default=DEFAULT_PAK)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    records = export_portraits(args.pak, args.output)
    print(f'Exported {len(records)} original40x48 portraits: {args.output}')
