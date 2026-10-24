#!/usr/bin/env python3
"""Stage Russian inventory labels, preserving original geometry and CLUTs."""
import argparse
import hashlib
import json
import struct
from pathlib import Path

from a2.cyrfont import bbox_w, build16, decode_bank
from a2.pak import PakArchive
from menu_texture_patch import (decode_chunk, encode_lz, pack_indices,
                                palette_rgb, parse_container, unpack_indices)

SLOTS = (298, 303, 308, 313, 318, 323, 328)
# text, chunk, complete native UV rectangle, palette bank, glyph scale / 4
LABELS = (("Предметы", 0, (0, 0, 72, 24), 0, 4),
          ("Стихии", 0, (72, 0, 72, 24), 0, 4),
          ("Особое", 0, (0, 24, 72, 24), 0, 4),
          ("Настройки", 0, (72, 24, 72, 24), 0, 4),
          ("Карманы", 1, (16, 56, 104, 32), 12, 5))
REFERENCE_SHA256 = "6e94a8ffbd1762258199213c62f6124caf507941317407ca0af305e3dcae4d71"
FONT_SHA256 = "e4a0ee29593a4106c6cf2627d8f2ab13c2666918938ecd70b4b5b7201afcd493"


def _sha(data):
    return hashlib.sha256(data).hexdigest()


def _extract(pixels, width, rect):
    x, y, w, h = rect
    return b"".join(pixels[r*width+x:r*width+x+w] for r in range(y, y+h))


def _glyph_line(text, glyphs, scale):
    """Use the established native glyph advances; never squeeze glyph columns."""
    cells = [(glyphs[c][0], max(glyphs[c][1], bbox_w(glyphs[c][0]))) for c in text]
    width = sum(advance for _, advance in cells)
    pixels, x = bytearray(width * 16), 0
    for glyph, advance in cells:
        for y, row in enumerate(glyph):
            for dx, value in enumerate(row):
                if value:
                    pixels[y*width+x+dx] = value
        x += advance
    sw, sh = width*scale//4, 16*scale//4
    # Pocket's original heading is larger than the 12px-high tab lettering.
    # Nearest-neighbour enlargement retains the existing three ink levels.
    return bytes(pixels[(y*4//scale)*width + x*4//scale]
                 for y in range(sh) for x in range(sw)), sw, sh


def _replace_label(original, spec, glyphs):
    text, page, (_, _, w, h), _, scale = spec
    # Only the original lettering and its one-pixel edge/shadow are removed.
    # The surrounding patterned plate is never replaced with a flat rectangle.
    if page == 0:
        interior = (3, 4, 66, 15)
        bright, background, levels = {0, 11, 12, 13, 14}, {5, 6, 7, 8, 9, 10}, (0, 12, 14, 0)
    else:
        interior = (5, 5, 94, 20)
        bright, background, levels = {2, 10, 13, 14}, {8, 9, 11, 12}, (0, 10, 13, 14)
    ix, iy, iw, ih = interior
    allowed = {(x, y) for y in range(iy, iy+ih) for x in range(ix, ix+iw)}
    ink = {(x, y) for x, y in allowed if original[y*w+x] in bright}
    mask = {(x+dx, y+dy) for x, y in ink for dy in (-1, 0, 1) for dx in (-1, 0, 1)} & allowed
    # Original tab bevel colors cannot be touched, even by the shadow mask.
    if page == 0:
        mask = {(x, y) for x, y in mask if original[y*w+x] not in (1, 2, 3, 4, 15)}
    candidates = [(x, y) for y in range(iy, iy+ih) for x in range(ix, ix+iw)
                  if (x, y) not in mask and original[y*w+x] in background]
    if not ink or not candidates:
        raise ValueError("source artwork has no separable lettering/background")
    out = bytearray(original)
    for x, y in mask:
        # Deterministic nearest unoccluded original background texel. This
        # reconstructs only pixels hidden by the old text, not the plate art.
        bx, by = min(candidates, key=lambda p: (abs(p[0]-x)+abs(p[1]-y), abs(p[1]-y), p[1], p[0]))
        out[y*w+x] = original[by*w+bx]
    line, tw, th = _glyph_line(text, glyphs, scale)
    if tw > w-6 or th > h-8:
        raise ValueError(f"label {text!r} does not fit its original frame")
    left, top = (w-tw)//2, (h-th)//2
    if page == 1:
        top -= 1  # Reserve the original lower bevel for Cyrillic р's descender.
    for y in range(th):
        for x in range(tw):
            value = line[y*tw+x]
            if not value:
                continue
            dest = (top+y)*w+left+x
            if page == 0 and original[dest] in (1, 2, 3, 4, 15):
                raise ValueError(f"label {text!r} overlaps the original tab frame")
            if page == 1 and (left+x, top+y) not in allowed:
                raise ValueError(f"label {text!r} overlaps the original Pocket frame")
            out[dest] = levels[value]
    return bytes(out), {"text": text, "ink_size": [tw, th],
                        "original_label_sha256": _sha(original), "label_sha256": _sha(out)}


def patch_pocket_menu(archive, pristine_bank548, pristine_menu298):
    """Patch all seven copies atomically in RAM, rejecting unknown label art.

    Both pristine inputs are explicit and hash-checked. A copy may contain
    other pixel edits outside these five UV areas; those bytes are preserved.
    Already patched areas are accepted verbatim, making repeat runs no-ops.
    """
    if _sha(pristine_bank548) != FONT_SHA256:
        raise ValueError("unknown font source; expected pristine bank548")
    if _sha(pristine_menu298) != REFERENCE_SHA256:
        raise ValueError("unknown menu source; expected pristine US slot298")
    width, height, palettes, reference = parse_container(pristine_menu298)
    reference_pixels = [unpack_indices(c["raw"], width, height, 4) for c in reference]
    glyphs = build16(decode_bank(pristine_bank548, 16))
    replacements, details = [], []
    for spec in LABELS:
        original = _extract(reference_pixels[spec[1]], width, spec[2])
        replacement, detail = _replace_label(original, spec, glyphs)
        replacements.append((original, replacement))
        detail.update(chunk=spec[1], uv_rect=list(spec[2]), clut_bank=spec[3])
        details.append(detail)
    pending, cache = {}, {}
    for slot in SLOTS:
        if slot >= len(archive.slots) or archive.slots[slot] is None:
            raise ValueError(f"missing inventory menu slot {slot}")
        data = archive.slots[slot]
        if data in cache:
            pending[slot] = cache[data]
            continue
        w, h, pal, chunks = parse_container(data)
        if (w, h, len(chunks)) != (256, 224, 2) or any(c["bpp"] != 4 for c in chunks):
            raise ValueError(f"unknown menu layout in slot {slot}")
        if pal != palettes:
            raise ValueError(f"unknown menu palette in slot {slot}")
        pages = [bytearray(unpack_indices(c["raw"], w, h, 4)) for c in chunks]
        for spec, (original, replacement) in zip(LABELS, replacements):
            text, page, rect, _, _ = spec
            current = _extract(pages[page], w, rect)
            if current != original and current != replacement:
                raise ValueError(f"unknown {text} source artwork in slot {slot}")
            x, y, rw, rh = rect
            for row in range(rh):
                pages[page][(y+row)*w+x:(y+row)*w+x+rw] = replacement[row*rw:(row+1)*rw]
        compressed = []
        for pixels, chunk in zip(pages, chunks):
            raw = pack_indices(pixels, w, h, 4)
            encoded = chunk["compressed"] if raw == chunk["raw"] else encode_lz(raw)
            if decode_chunk(encoded, w, h) != raw:
                raise AssertionError("native chunk recompression failed")
            compressed.append(encoded)
        header = bytearray(data[:chunks[0]["offset"]])
        for page, encoded in enumerate(compressed):
            struct.pack_into("<I", header, 12+page*4, len(encoded))
        end = chunks[-1]["offset"] + chunks[-1]["size"]
        result = bytes(header) + b"".join(compressed) + data[end:]
        cache[data] = pending[slot] = result
    changed = []
    for slot, data in pending.items():
        if archive.slots[slot] != data:
            archive.slots[slot] = data
            changed.append(slot)
    return {"changed_slots": changed, "labels": [s[0] for s in LABELS], "details": details,
            "reference_sha256": REFERENCE_SHA256, "font_sha256": FONT_SHA256}


def stage_patch(input_pak, reference_pak, output_dir):
    """Create a NEW stage and review PNGs; never write to either input PAK."""
    input_pak, reference_pak, output_dir = map(Path, (input_pak, reference_pak, output_dir))
    if output_dir.exists():
        raise FileExistsError(f"refusing to overwrite existing stage: {output_dir}")
    source_hash, reference_hash = _sha(input_pak.read_bytes()), _sha(reference_pak.read_bytes())
    archive, pristine = PakArchive.load(input_pak), PakArchive.load(reference_pak)
    original = archive.slots[SLOTS[0]]
    report = patch_pocket_menu(archive, pristine.slots[548], pristine.slots[298])
    output_dir.mkdir(parents=True, exist_ok=False)
    (output_dir/"DATA").mkdir()
    destination = output_dir/"DATA/PACK0.PAK"
    archive.save(destination)
    saved = PakArchive.load(destination)
    if len(saved.slots) != len(archive.slots):
        raise AssertionError("staged archive slot count changed")
    for slot, (wanted, actual) in enumerate(zip(archive.slots, saved.slots)):
        if wanted is None:
            if actual is not None:
                raise AssertionError(f"empty staged slot {slot} changed")
        elif actual is None or not actual.startswith(wanted) or any(actual[len(wanted):]):
            raise AssertionError(f"staged slot {slot} was corrupted")
    from PIL import Image
    for tag, data in (("before", original), ("after", saved.slots[SLOTS[0]])):
        w, h, palettes, chunks = parse_container(data)
        images = []
        for page, clut in ((0, 0), (1, 12)):
            pixels = unpack_indices(chunks[page]["raw"], w, h, 4)
            img = Image.frombytes("P", (w, h), pixels)
            img.putpalette(palette_rgb(palettes[clut*32:(clut+1)*32]) + [0]*720)
            images.append(img.convert("RGB"))
            images[-1].resize((w*3, h*3), Image.Resampling.NEAREST).save(output_dir/f"{tag}_chunk{page}_clut{clut}_3x.png")
            (output_dir/f"{tag}_chunk{page}.raw").write_bytes(chunks[page]["raw"])
            (output_dir/f"{tag}_chunk{page}.chunk").write_bytes(chunks[page]["compressed"])
        sheet_height = sum(spec[2][3] for spec in LABELS)
        sheet = Image.new("RGB", (112, sheet_height), (8, 8, 16))
        yy = 0
        for _, page, (x, y, rw, rh), _, _ in LABELS:
            sheet.paste(images[page].crop((x, y, x+rw, y+rh)), ((112-rw)//2, yy))
            yy += rh
        sheet.resize((448, sheet_height*4), Image.Resampling.NEAREST).save(output_dir/f"{tag}_labels_4x.png")
    if _sha(input_pak.read_bytes()) != source_hash or _sha(reference_pak.read_bytes()) != reference_hash:
        raise RuntimeError("source archive changed during staging; do not promote")
    report.update(input_pak=str(input_pak.resolve()), source_sha256=source_hash,
                  reference_pak=str(reference_pak.resolve()), staged_sha256=_sha(destination.read_bytes()))
    (output_dir/"report.json").write_text(json.dumps(report, ensure_ascii=False, indent=2)+"\n")
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--input-pak", type=Path, required=True)
    parser.add_argument("--reference-pak", type=Path, required=True,
                        help="pristine US PACK0 with menu298 and Latin font548")
    parser.add_argument("--output-dir", type=Path, required=True, help="NEW directory only")
    args = parser.parse_args()
    print(json.dumps(stage_patch(args.input_pak, args.reference_pak, args.output_dir), ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
