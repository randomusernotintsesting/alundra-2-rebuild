#!/usr/bin/env python3
"""Stage Russian brightness instructions; preserve the calibration chart exactly."""
import argparse
import hashlib
import json
import struct
from pathlib import Path

from a2.cyrfont import bbox_w, build16, decode_bank
from a2.pak import PakArchive
from menu_texture_patch import decode_chunk, encode_lz, palette_rgb, parse_container

SLOTS = (361, 363, 365, 367, 369, 371, 373)
REFERENCE_SHA256 = "25f03fa64639c5f1b9b78f5331fe77c83cd9ef2d8b0d4dfea4168940b6dca533"
FONT_SHA256 = "e4a0ee29593a4106c6cf2627d8f2ab13c2666918938ecd70b4b5b7201afcd493"
LINES = ("Настройте яркость экрана,", "чтобы хорошо различались",
         "переходы оттенков над", "центральной жёлтой линией.")
RECTS = ((12, 128, 232, 72), (76, 208, 64, 20))
LABELS = LINES + ("Выход",)


def _sha(data):
    return hashlib.sha256(data).hexdigest()


def _extract(pixels, rect):
    x, y, w, h = rect
    return b"".join(pixels[row*256+x:row*256+x+w] for row in range(y, y+h))


def _glyph_line(text, glyphs, latin):
    cells = []
    for char in text:
        if char == " ":
            cells.append(([[0]*12 for _ in range(16)], 4))
        else:
            pixels, advance = glyphs[char] if char in glyphs else latin[ord(char)-32]
            cells.append((pixels, max(advance, bbox_w(pixels))))
    width = sum(advance for _, advance in cells)
    out, x = bytearray(width*16), 0
    for pixels, advance in cells:
        for y, row in enumerate(pixels):
            for dx, value in enumerate(row):
                if value:
                    out[y*width+x+dx] = value
        x += advance
    return out, width


def _render(reference_raw, bank):
    latin = decode_bank(bank, 16)
    glyphs = build16(latin)
    regions, details = [], []
    # Gray calibration bands continue behind the English lettering. The
    # hash-checked original row's left edge is an unobscured background texel.
    # Restore each row separately, never flatten bands into a single color.
    for index, (_, y, w, h) in enumerate(RECTS):
        region = bytearray(v for row in range(y, y+h)
                           for v in [reference_raw[row*256]]*w)
        lines = LINES if index == 0 else ("Выход",)
        for row, text in enumerate(lines):
            pixels, tw = _glyph_line(text, glyphs, latin)
            top, left = row*18 if index == 0 else 2, 2
            if tw > w-left-2 or top+16 > h:
                raise ValueError(f"{text!r} does not fit the original brightness text region")
            levels = (0, 113, 104, 25)  # Existing gray antialias shades and near-white ink.
            for gy in range(16):
                for gx in range(tw):
                    value = pixels[gy*tw+gx]
                    if value:
                        region[(top+gy)*w+left+gx] = levels[value]
            details.append({"text": text, "ink_size": [tw, 16],
                            "atlas_xy": [RECTS[index][0]+left, y+top]})
        regions.append(bytes(region))
    return regions, details


def patch_brightness_menu(archive, pristine_bank548, pristine_menu361):
    """Patch seven known copies atomically in RAM, leaving slot362 untouched."""
    if _sha(pristine_bank548) != FONT_SHA256:
        raise ValueError("unknown font source; expected pristine font548")
    if _sha(pristine_menu361) != REFERENCE_SHA256:
        raise ValueError("unknown menu source; expected pristine US slot361")
    _, _, palettes, reference = parse_container(pristine_menu361)
    reference_raw = reference[0]["raw"]
    originals = [_extract(reference_raw, rect) for rect in RECTS]
    replacements, details = _render(reference_raw, pristine_bank548)
    pending, cache = {}, {}
    for slot in SLOTS:
        if slot >= len(archive.slots) or archive.slots[slot] is None:
            raise ValueError(f"missing brightness slot {slot}")
        data = archive.slots[slot]
        if data in cache:
            pending[slot] = cache[data]
            continue
        w, h, pal, chunks = parse_container(data)
        if (w, h, len(chunks)) != (256, 256, 1) or chunks[0]["bpp"] != 8:
            raise ValueError(f"unknown brightness layout in slot {slot}")
        if pal != palettes:
            raise ValueError(f"unknown brightness palette in slot {slot}")
        raw = bytearray(chunks[0]["raw"])
        for rect, old, new in zip(RECTS, originals, replacements):
            current = _extract(raw, rect)
            if current != old and current != new:
                raise ValueError(f"unknown brightness source artwork in slot {slot}")
            x, y, rw, rh = rect
            for row in range(rh):
                raw[(y+row)*w+x:(y+row)*w+x+rw] = new[row*rw:(row+1)*rw]
        chunk = chunks[0]
        if raw == chunk["raw"]:
            result = data
        else:
            encoded = encode_lz(raw, bpp=8)
            if decode_chunk(encoded, w, h) != raw:
                raise AssertionError("native 8bpp recompression failed")
            prefix = bytearray(data[:chunk["offset"]])
            struct.pack_into("<I", prefix, 12, len(encoded))
            result = bytes(prefix) + encoded + data[chunk["offset"]+chunk["size"]:]
        cache[data] = pending[slot] = result
    changed = []
    for slot, data in pending.items():
        if archive.slots[slot] != data:
            archive.slots[slot] = data
            changed.append(slot)
    return {"changed_slots": changed, "labels": list(LABELS), "details": details,
            "uv_rectangles": [list(r) for r in RECTS], "bpp": 8,
            "reference_sha256": REFERENCE_SHA256, "font_sha256": FONT_SHA256,
            "region_hashes": [{"original": _sha(a), "patched": _sha(b)}
                              for a, b in zip(originals, replacements)]}


def stage_patch(input_pak, reference_pak, output_dir):
    """Write a NEW reviewed archive, never modifying either input or prior output."""
    input_pak, reference_pak, output_dir = map(Path, (input_pak, reference_pak, output_dir))
    if output_dir.exists():
        raise FileExistsError(f"refusing to overwrite existing stage: {output_dir}")
    source_hash, ref_hash = _sha(input_pak.read_bytes()), _sha(reference_pak.read_bytes())
    archive, pristine = PakArchive.load(input_pak), PakArchive.load(reference_pak)
    original = archive.slots[SLOTS[0]]
    report = patch_brightness_menu(archive, pristine.slots[548], pristine.slots[361])
    output_dir.mkdir(parents=True, exist_ok=False)
    (output_dir/"DATA").mkdir()
    destination = output_dir/"DATA/PACK0.PAK"
    archive.save(destination)
    saved = PakArchive.load(destination)
    if len(saved.slots) != len(archive.slots):
        raise AssertionError("staged slot count changed")
    for slot, (wanted, actual) in enumerate(zip(archive.slots, saved.slots)):
        if wanted is None:
            if actual is not None:
                raise AssertionError(f"empty staged slot {slot} changed")
        elif actual is None or not actual.startswith(wanted) or any(actual[len(wanted):]):
            raise AssertionError(f"staged slot {slot} corrupted")
    from PIL import Image
    for tag, data in (("before", original), ("after", saved.slots[SLOTS[0]])):
        w, h, palettes, chunks = parse_container(data)
        image = Image.frombytes("P", (w, h), chunks[0]["raw"])
        image.putpalette(palette_rgb(palettes))
        image.convert("RGB").resize((w*3, h*3), Image.Resampling.NEAREST).save(output_dir/f"{tag}_atlas_3x.png")
        (output_dir/f"{tag}_chunk0.raw").write_bytes(chunks[0]["raw"])
        (output_dir/f"{tag}_chunk0.chunk").write_bytes(chunks[0]["compressed"])
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
