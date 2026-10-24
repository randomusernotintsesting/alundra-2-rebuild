#!/usr/bin/env python3
"""Stage Russian Settings text without altering native layout or state palettes."""
import argparse
import hashlib
import json
import struct
from pathlib import Path

from a2.cyrfont import bbox_w, build16, decode_bank
from a2.pak import PakArchive
from menu_texture_patch import (decode_chunk, encode_lz, pack_indices,
                                palette_rgb, parse_container, unpack_indices)

SLOTS = tuple(range(333, 340))
REFERENCE_SHA256 = "e8c8e8516a8b121e37e7cd529c615f774ac9bc1bd473e923999265ecb10759a4"
FONT_SHA256 = "e4a0ee29593a4106c6cf2627d8f2ab13c2666918938ecd70b4b5b7201afcd493"
# English/source key, Russian, page, editable UV region, unchanged CLUT bank.
# Floating text UVs come from actual GP0 frame6399; button regions exclude
# physical O/X/START legends and the decorative outline.
LABELS = [
    ("SETTINGS", "Настройки", 0, (0, 168, 184, 24), 2),
    ("Fast", "Быстро", 0, (120, 96, 136, 24), 2),
    ("Normal_speed", "Средне", 0, (120, 120, 136, 24), 2),
    ("Slow", "Медленно", 0, (120, 144, 136, 24), 2),
    ("Tap Once", "Нажатие", 0, (0, 192, 136, 24), 2),
    ("Hold Down", "Удержание", 0, (0, 216, 136, 24), 2),
    # US artwork keys are not the JP action contract: Circle applies,
    # Cross restores the saved settings (GAME00 800C9E64/800C9EA8).
    ("Cancel", "Выбрать", 0, (24, 98, 52, 28), 8),
    ("Select", "Отмена", 0, (24, 130, 52, 28), 9),
    ("Default", "Сброс", 0, (208, 58, 44, 28), 10),
]
LABELS += [(source, ru, 1, (0, row*24, 114, 24), 2) for row, (source, ru) in enumerate((
    ("Vibrate", "Вибрация"), ("Messages", "Сообщения"), ("Font", "Шрифт"),
    ("Run", "Бег"), ("Window", "Окно"), ("Sound", "Звук"),
    ("BGM Volume", "Музыка"), ("SFX Volume", "Эффекты"), ("EXIT", "Выход")))]
LABELS += [(source, ru, 1, (120, row*24, 136, 24), 2) for row, (source, ru) in enumerate((
    ("ON", "Вкл."), ("OFF", "Выкл."), ("Black", "Чёрное"),
    ("Stereo", "Стерео"), ("Mono", "Моно"), ("Font 1", "Шрифт 1"),
    ("Font 2", "Шрифт 2"), ("Font 3", "Шрифт 3"), ("Font 4", "Шрифт 4"),
    ("Normal_window", "Обычное")))]
LABELS = tuple(LABELS)


def _sha(data):
    return hashlib.sha256(data).hexdigest()


def _extract(pixels, width, rect):
    x, y, w, h = rect
    return b"".join(pixels[r*width+x:r*width+x+w] for r in range(y, y+h))


def _line(text, glyphs, latin):
    cells = []
    for char in text:
        if char == " ":
            cells.append(([[0]*12 for _ in range(16)], 4))
        else:
            pixels, advance = glyphs[char] if char in glyphs else latin[ord(char)-32]
            cells.append((pixels, max(advance, bbox_w(pixels))))
    width, x = sum(advance for _, advance in cells), 0
    out = bytearray(width*16)
    for pixels, advance in cells:
        for y, row in enumerate(pixels):
            for dx, value in enumerate(row):
                if value:
                    out[y*width+x+dx] = value
        x += advance
    return out, width


def _render(original, spec, glyphs, latin):
    source, text, _, (_, _, w, h), clut = spec
    protected = set()
    if clut == 2:
        out = bytearray(w*h)
        levels = (0, 3, 10, 15)
    else:
        bright, background, frame, levels = {
            8: ({1, 2, 10, 11}, {3, 4, 5}, {12, 13, 14}, (0, 1, 11, 2)),
            9: ({5, 6, 7}, {1, 3}, {11, 12, 13}, (0, 5, 6, 7)),
            10: ({6, 9, 10}, {1, 2, 3}, {11, 12, 13}, (0, 5, 10, 9)),
        }[clut]
        protected = {(x, y) for y in range(h) for x in range(w) if original[y*w+x] in frame}
        ink = {(x, y) for y in range(h) for x in range(w) if original[y*w+x] in bright}
        mask = {(x+dx, y+dy) for x, y in ink for dy in (-1, 0, 1) for dx in (-1, 0, 1)
                if 0 <= x+dx < w and 0 <= y+dy < h} - protected
        candidates = [(x, y) for y in range(h) for x in range(w)
                      if (x, y) not in mask and original[y*w+x] in background]
        if not ink or not candidates:
            raise ValueError(f"cannot separate original {source} lettering")
        out = bytearray(original)
        for x, y in mask:
            bx, by = min(candidates, key=lambda p: (abs(p[0]-x)+abs(p[1]-y), abs(p[1]-y), p[1], p[0]))
            out[y*w+x] = original[by*w+bx]
    line, tw = _line(text, glyphs, latin)
    if tw > w-2 or h < 18:
        raise ValueError(f"{text!r} does not fit original {source} UV")
    left, top = (w-tw)//2, (h-16)//2
    for y in range(16):
        for x in range(tw):
            value = line[y*tw+x]
            if value:
                if (left+x, top+y) in protected:
                    raise ValueError(f"{text!r} overlaps the original button frame")
                out[(top+y)*w+left+x] = levels[value]
    return bytes(out), {"source": source, "text": text, "ink_size": [tw, 16],
                        "chunk": spec[2], "uv_rect": list(spec[3]), "clut_bank": clut,
                        "original_label_sha256": _sha(original), "label_sha256": _sha(out)}


def patch_settings_menu(archive, pristine_bank548, pristine_menu333):
    """Validate every copy before changing any; repeat calls are byte-exact no-ops."""
    if _sha(pristine_bank548) != FONT_SHA256:
        raise ValueError("unknown font source; expected pristine font548")
    if _sha(pristine_menu333) != REFERENCE_SHA256:
        raise ValueError("unknown menu source; expected pristine US slot333")
    w, h, palettes, reference = parse_container(pristine_menu333)
    pages = [unpack_indices(c["raw"], w, h, 4) for c in reference]
    latin = decode_bank(pristine_bank548, 16)
    glyphs = build16(latin)
    replacements, details, legacy_prompts = [], [], {}
    for spec in LABELS:
        old = _extract(pages[spec[2]], w, spec[3])
        new, detail = _render(old, spec, glyphs, latin)
        replacements.append((old, new))
        details.append(detail)
        if spec[4] in (8,9):
            legacy=(spec[0],{8:'Отмена',9:'Выбрать'}[spec[4]],*spec[2:])
            legacy_prompts[spec[3]]=_render(old,legacy,glyphs,latin)[0]
    pending, cache = {}, {}
    for slot in SLOTS:
        if slot >= len(archive.slots) or archive.slots[slot] is None:
            raise ValueError(f"missing Settings slot {slot}")
        data = archive.slots[slot]
        if data in cache:
            pending[slot] = cache[data]
            continue
        width, height, pal, chunks = parse_container(data)
        if (width, height, len(chunks)) != (256, 256, 2) or any(c["bpp"] != 4 for c in chunks):
            raise ValueError(f"unknown Settings layout in slot {slot}")
        if pal != palettes:
            raise ValueError(f"unknown Settings palette in slot {slot}")
        pixels = [bytearray(unpack_indices(c["raw"], w, h, 4)) for c in chunks]
        for spec, (old, new) in zip(LABELS, replacements):
            source, _, page, rect, _ = spec
            current = _extract(pixels[page], w, rect)
            if current != old and current != new and current != legacy_prompts.get(rect):
                raise ValueError(f"unknown {source} source artwork in slot {slot}")
            x, y, rw, rh = rect
            for row in range(rh):
                pixels[page][(y+row)*w+x:(y+row)*w+x+rw] = new[row*rw:(row+1)*rw]
        encoded = []
        for page, chunk in zip(pixels, chunks):
            raw = pack_indices(page, w, h, 4)
            value = chunk["compressed"] if raw == chunk["raw"] else encode_lz(raw)
            if decode_chunk(value, w, h) != raw:
                raise AssertionError("native chunk recompression failed")
            encoded.append(value)
        header = bytearray(data[:chunks[0]["offset"]])
        for index, chunk in enumerate(encoded):
            struct.pack_into("<I", header, 12+index*4, len(chunk))
        end = chunks[-1]["offset"] + chunks[-1]["size"]
        cache[data] = pending[slot] = bytes(header) + b"".join(encoded) + data[end:]
    changed = []
    for slot, data in pending.items():
        if archive.slots[slot] != data:
            archive.slots[slot] = data
            changed.append(slot)
    return {"changed_slots": changed, "labels": [s[1] for s in LABELS], "details": details,
            "reference_sha256": REFERENCE_SHA256, "font_sha256": FONT_SHA256}


def stage_patch(input_pak, reference_pak, output_dir):
    """Write only to a NEW stage; sources and previously staged files are untouched."""
    input_pak, reference_pak, output_dir = map(Path, (input_pak, reference_pak, output_dir))
    if output_dir.exists():
        raise FileExistsError(f"refusing to overwrite existing stage: {output_dir}")
    source_hash, ref_hash = _sha(input_pak.read_bytes()), _sha(reference_pak.read_bytes())
    archive, pristine = PakArchive.load(input_pak), PakArchive.load(reference_pak)
    original = archive.slots[SLOTS[0]]
    report = patch_settings_menu(archive, pristine.slots[548], pristine.slots[333])
    output_dir.mkdir(parents=True, exist_ok=False)
    (output_dir/"DATA").mkdir()
    destination = output_dir/"DATA/PACK0.PAK"
    archive.save(destination)
    saved = PakArchive.load(destination)
    if len(saved.slots) != len(archive.slots):
        raise AssertionError("staged slot count changed")
    for index, (wanted, actual) in enumerate(zip(archive.slots, saved.slots)):
        if wanted is None:
            if actual is not None:
                raise AssertionError(f"staged empty slot {index} changed")
        elif actual is None or not actual.startswith(wanted) or any(actual[len(wanted):]):
            raise AssertionError(f"staged slot {index} corrupted")
    from PIL import Image
    for tag, data in (("before", original), ("after", saved.slots[SLOTS[0]])):
        w, h, palettes, chunks = parse_container(data)
        images = {}
        for page, chunk in enumerate(chunks):
            pixels = unpack_indices(chunk["raw"], w, h, 4)
            for clut in ((2, 8, 9, 10) if page == 0 else (2,)):
                img = Image.frombytes("P", (w, h), pixels)
                img.putpalette(palette_rgb(palettes[clut*32:(clut+1)*32]) + [0]*720)
                images[page, clut] = img.convert("RGB")
            images[page, 2].resize((w*3, h*3), Image.Resampling.NEAREST).save(output_dir/f"{tag}_chunk{page}_clut2_3x.png")
            (output_dir/f"{tag}_chunk{page}.raw").write_bytes(chunk["raw"])
            (output_dir/f"{tag}_chunk{page}.chunk").write_bytes(chunk["compressed"])
        sheet = Image.new("RGB", (368, 14*32), (12, 12, 16))
        for index, spec in enumerate(LABELS):
            _, _, page, (x, y, rw, rh), clut = spec
            if clut in (8, 9, 10):
                x, y, rw, rh = {8: (0, 96, 80, 32), 9: (0, 128, 80, 32), 10: (176, 56, 80, 32)}[clut]
            sheet.paste(images[page, clut].crop((x, y, x+rw, y+rh)),
                        ((index//14)*184+(184-rw)//2, (index%14)*32+(32-rh)//2))
        sheet.resize((1104, 1344), Image.Resampling.NEAREST).save(output_dir/f"{tag}_labels_3x.png")
    if _sha(input_pak.read_bytes()) != source_hash or _sha(reference_pak.read_bytes()) != ref_hash:
        raise RuntimeError("source archive changed while staging; do not promote")
    report.update(input_pak=str(input_pak.resolve()), source_sha256=source_hash,
                  reference_pak=str(reference_pak.resolve()), staged_sha256=_sha(destination.read_bytes()))
    (output_dir/"report.json").write_text(json.dumps(report, ensure_ascii=False, indent=2)+"\n")
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--input-pak", type=Path, required=True)
    parser.add_argument("--reference-pak", type=Path, required=True)
    parser.add_argument("--output-dir", type=Path, required=True, help="NEW directory only")
    args = parser.parse_args()
    print(json.dumps(stage_patch(args.input_pak, args.reference_pak, args.output_dir), ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
