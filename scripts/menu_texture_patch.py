#!/usr/bin/env python3
"""Stage Russian LOAD/SLOT labels without changing the input disc or archive."""
from pathlib import Path
import argparse
import hashlib
import json
import struct
import sys

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools/analysis/jp-gfx"))
from native_layout import decode_chunk, parse_container, pack_indices, unpack_indices, palette_rgb
from a2.cyrfont import bbox_w, build16, decode_bank
from a2.pak import PakArchive

SLOTS = (375, 379, 383, 387, 391, 395, 399)
LABELS = (("ЗАГРУЗКА", (144, 72, 112, 24)),
          ("СЛОТ 1", (80, 72, 64, 16)),
          ("СЛОТ 2", (80, 88, 64, 16)))
ORIGINAL_LABEL_HASHES = (
    "70c43470219f48fda1686de0c87acf215fd7187fa98be59f2ffa620a74388ecb",
    "de404b7aa7ea9386e0325072b45e80047421fc23bd244766a57d3171adbdc52b",
    "7def22dddba1b896b06fe7334892201675e66b0390c00b7c8cdfcddc510c11f6",
)


def encode_lz(raw, bpp=4):
    """Encode codec2 with a fresh 256-byte history inside each 16KiB strip."""
    if bpp not in (4, 8) or not raw or len(raw) > 524288:
        raise ValueError("invalid texture bytes/depth")
    raw = bytes(raw)
    out = bytearray((2, int(bpp == 8), 1, 0))

    def token(length, reference=False):
        code = length - 1
        flag = 0x80 if reference else 0
        if length <= 64:
            out.append(flag | code)
        else:
            out.extend((flag | 0x40 | (code >> 8), code & 255))

    for base in range(0, len(raw), 16384):
        end = min(base + 16384, len(raw))
        pos = literal = base
        while pos < end:
            best_length = best_distance = 0
            for distance in range(1, min(pos - base, 256) + 1):
                if raw[pos - distance] != raw[pos]:
                    continue
                length = 1
                while pos + length < end and raw[pos + length - distance] == raw[pos + length]:
                    length += 1
                if length > best_length:
                    best_length, best_distance = length, distance
                if pos + best_length == end:
                    break
            if best_length >= 3:
                if literal < pos:
                    token(pos - literal)
                    out.extend(raw[literal:pos])
                token(best_length, reference=True)
                out.append(best_distance - 1)
                pos += best_length
                literal = pos
            else:
                pos += 1
        if literal < end:
            token(end - literal)
            out.extend(raw[literal:end])
    return bytes(out)


def _render_labels(pristine_bank548):
    if len(pristine_bank548) != 96 * 49:
        raise ValueError("expected original 12x16 ASCII font bank548")
    latin = decode_bank(pristine_bank548, 16)
    glyphs = build16(latin)
    labels = []
    for text, (_, _, width, height) in LABELS:
        cells = []
        for char in text:
            if char == " ":
                cells.append(([[0] * 4 for _ in range(16)], 4))
            else:
                pixels, advance = glyphs[char] if char in glyphs else latin[ord(char) - 32]
                # Retain even faint edge/shadow pixels outside the text advance.
                cells.append((pixels, max(advance, bbox_w(pixels))))
        text_width = sum(w for _, w in cells) + len(cells) - 1
        if text_width > width - 2 or height < 16:
            raise ValueError(f"label {text!r} cannot fit its original UV rectangle")
        label = bytearray(width * height)
        x, top = (width - text_width) // 2, (height - 16) // 2
        # Three original dialogue-font intensity levels, using the menu's
        # unchanged 16-color grayscale CLUT12 (0 transparent,15 white).
        levels = (0, 5, 10, 15)
        for pixels, advance in cells:
            for y, row in enumerate(pixels):
                for dx, value in enumerate(row):
                    if value:
                        label[(top + y) * width + x + dx] = levels[value]
            x += advance + 1
        labels.append(bytes(label))
    return labels


def patch_load_menu(archive, pristine_bank548):
    """Mutate only the seven supported US-transplanted slots, atomically in RAM.

    Unknown label artwork is rejected. Existing Russian output is idempotent;
    unrelated pixels, palettes, second chunk, slots and trailing data survive.
    Source bytes come from the caller, never from an implicit live disc.
    """
    labels = _render_labels(pristine_bank548)
    pending, cache = {}, {}
    report = {"changed_slots": [], "labels": [text for text, _ in LABELS],
              "uv_rectangles": [list(rect) for _, rect in LABELS], "clut_bank": 12,
              "chunks": []}
    for slot in SLOTS:
        if slot >= len(archive.slots) or archive.slots[slot] is None:
            raise ValueError(f"missing menu slot {slot}")
        data = archive.slots[slot]
        if data in cache:
            pending[slot] = cache[data]
            continue
        width, height, palettes, chunks = parse_container(data)
        if (width, height, len(chunks), len(palettes)) != (256, 256, 2, 1024):
            raise ValueError(f"unsupported menu container layout in slot {slot}")
        if any(c["bpp"] != 4 for c in chunks):
            raise ValueError("menu texture must be 4bpp")
        expected_clut = (0, 0x908a, 0x94ab, 0x9cec, 0xa52e, 0xad6f, 0xb9d2, 0xc634,
                         0xd296, 0xdef8, 0xe73a, 0xeb5b, 0xef7c, 0xf39d, 0xf7be, 0xffff)
        if struct.unpack_from("<16H", palettes, 12 * 32) != expected_clut:
            raise ValueError("unknown label palette")
        pixels = bytearray(unpack_indices(chunks[0]["raw"], width, height, 4))
        for index, ((text, (x, y, w, h)), label) in enumerate(zip(LABELS, labels)):
            old = b"".join(pixels[(y + row)*width + x:(y + row)*width + x + w]
                           for row in range(h))
            if old != label and hashlib.sha256(old).hexdigest() != ORIGINAL_LABEL_HASHES[index]:
                raise ValueError(f"unknown {text} source artwork in slot {slot}")
            for row in range(h):
                pixels[(y + row)*width + x:(y + row)*width + x + w] = label[row*w:(row+1)*w]
        raw = pack_indices(pixels, width, height, 4)
        if raw == chunks[0]["raw"]:
            result = data
        else:
            encoded = encode_lz(raw)
            if decode_chunk(encoded, width, height) != raw:
                raise AssertionError("recompression roundtrip failed")
            old = chunks[0]
            prefix = bytearray(data[:old["offset"]])
            struct.pack_into("<I", prefix, 12, len(encoded))
            result = bytes(prefix) + encoded + data[old["offset"] + old["size"]:]
            report["chunks"].append({"old_compressed_bytes": old["size"],
                                      "new_compressed_bytes": len(encoded),
                                      "raw_sha256": hashlib.sha256(raw).hexdigest()})
        cache[data] = result
        pending[slot] = result
    # No archive changes occur until every copy has passed validation.
    for slot, data in pending.items():
        if archive.slots[slot] != data:
            archive.slots[slot] = data
            report["changed_slots"].append(slot)
    return report


def stage_patch(input_pak, font_pak, output_dir):
    """Write a new staged DATA/PACK0.PAK and before/after previews, never in-place."""
    input_pak, font_pak, output_dir = Path(input_pak), Path(font_pak), Path(output_dir)
    if output_dir.exists():
        raise FileExistsError(f"refusing to overwrite existing stage: {output_dir}")
    source_hash = hashlib.sha256(input_pak.read_bytes()).hexdigest()
    archive = PakArchive.load(input_pak)
    fonts = PakArchive.load(font_pak)
    if len(archive.slots) <= SLOTS[-1] or len(fonts.slots) <= 548 or fonts.slots[548] is None:
        raise ValueError("archive missing required menu/font slots")
    original = archive.slots[SLOTS[0]]
    report = patch_load_menu(archive, fonts.slots[548])
    output_dir.mkdir(parents=True, exist_ok=False)
    (output_dir / "DATA").mkdir()
    destination = output_dir / "DATA/PACK0.PAK"
    archive.save(destination)
    saved = PakArchive.load(destination)
    # Re-open the serialized output: file alignment/repacking must not change
    # any source slot content other than zero padding between slots.
    for index, (wanted, actual) in enumerate(zip(archive.slots, saved.slots)):
        if wanted is None:
            if actual is not None:
                raise AssertionError(f"empty slot {index} changed on disk")
        elif not actual.startswith(wanted) or any(actual[len(wanted):]):
            raise AssertionError(f"staged slot {index} was corrupted on disk")
    from PIL import Image
    report.update(input_pak=str(input_pak.resolve()), source_sha256=source_hash,
                  staged_sha256=hashlib.sha256(destination.read_bytes()).hexdigest(),
                  font_source=str(font_pak.resolve()),
                  font_bank_sha256=hashlib.sha256(fonts.slots[548]).hexdigest())
    for tag, data in (("before", original), ("after", saved.slots[SLOTS[0]])):
        w, h, palettes, chunks = parse_container(data)
        raw = chunks[0]["raw"]
        pixels = unpack_indices(raw, w, h, 4)
        image = Image.frombytes("P", (w, h), pixels)
        image.putpalette(palette_rgb(palettes[12*32:13*32]) + [0] * 720)
        image.resize((w*3, h*3), Image.Resampling.NEAREST).save(output_dir / f"{tag}_atlas_clut12_3x.png")
        sheet = Image.new("RGB", (112, 56), (0, 0, 0))
        yy = 0
        for text, (x, y, rw, rh) in LABELS:
            sheet.paste(image.crop((x, y, x+rw, y+rh)).convert("RGB"), ((112-rw)//2, yy))
            yy += rh
        sheet.resize((448, 224), Image.Resampling.NEAREST).save(output_dir / f"{tag}_labels_4x.png")
        (output_dir / f"{tag}_chunk0.chunk").write_bytes(chunks[0]["compressed"])
        (output_dir / f"{tag}_chunk0.raw").write_bytes(raw)
    if hashlib.sha256(input_pak.read_bytes()).hexdigest() != source_hash:
        raise RuntimeError("input archive changed while staging; do not promote this stage")
    (output_dir / "report.json").write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n")
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--input-pak", type=Path, required=True,
                        help="current archive with US menu texture transplant")
    parser.add_argument("--font-pak", type=Path, required=True,
                        help="pristine original archive containing Latin font bank548")
    parser.add_argument("--output-dir", type=Path, required=True,
                        help="NEW stage directory; existing directories are refused")
    args = parser.parse_args()
    print(json.dumps(stage_patch(args.input_pak, args.font_pak, args.output_dir),
                     ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
