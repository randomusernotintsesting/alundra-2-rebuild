#!/usr/bin/env python3
"""Patch the JP disc's remaining "easy" Japanese/English graphics to Russian.

Usage: gfx_patch.py [-d discdir]   (default: disc_jp)

1. SCPS_101.15 @0x395D8 — the boot-resident 4bpp 256x144 texture atlas
   (window patterns + ASCII fonts + pre-rendered "NOW LOADING" band at
   rows 115-124).  The Latin lettering (x 0..105) is erased back to the
   striped window background and "ЗАГРУЗКА..." is drawn in the same
   style: white body (idx 15), 1px dark outline (idx 0), on the F/7
   stripe pattern; the baked black underline row (125) and the analog
   stick icons (x >= 106) are kept untouched.
   HARD BUDGET: the recompressed RLE stream must stay <= 7870 bytes
   (live SJIS table data follows the container — zero slack).  The
   stream size word at 0x395E4 is updated, any tail gap zero-filled.

2. GAME00.BIN @0x1B48 / @0x1B60 — Shift-JIS memory-card save titles
   drawn by the PS1 BIOS card browser.  Replaced in place with
   full-width JIS X 0208 row-7 Cyrillic (valid Shift-JIS):
       0x1B48 (<=11 FW chars): "アランドラ２／旅の記録" -> "АЛУНДРА２"
       0x1B60 (<=13 FW chars): "ＡＬＵＮＤＲＡ２／ＦＩＬＥ" -> "АЛУНДРА２／ФАЙЛ"
   Whether the console BIOS font renders row-7 Cyrillic is an
   emulator-test item (see tools/analysis/jp-gfx/PATCHES.md).

Like font_patch.py, sources are always read from the pristine stash
(a2.pristine.source) and the patch is applied to the CURRENT discdir
files, so the script is idempotent and composes with text_insert.py.
"""
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from a2.pristine import source

# ---------------- A2 RLE codec (routine @0x8001C3AC US / JP analog) ----------

def rle_decompress(s):
    out = bytearray()
    i, n = 0, len(s)
    while i < n:
        c = s[i]; i += 1
        if c & 0x40:
            ln = ((c & 0x3F) << 8 | s[i]) + 1; i += 1
        else:
            ln = (c & 0x3F) + 1
        if c & 0x80:
            out += bytes([s[i]]) * ln; i += 1
        else:
            out += s[i:i + ln]; i += ln
    return bytes(out), i


def rle_compress(data):
    out = bytearray()
    n = len(data)

    def emit_lit(p, end):
        while p < end:
            ln = min(end - p, 0x4000)
            if ln <= 64:
                out.append(ln - 1)
            else:
                out.append(0x40 | ((ln - 1) >> 8))
                out.append((ln - 1) & 0xFF)
            out.extend(data[p:p + ln])
            p += ln

    i = 0
    lit = None
    while i < n:
        r = 1
        while i + r < n and data[i + r] == data[i] and r < 0x4000:
            r += 1
        if r >= 3:
            if lit is not None:
                emit_lit(lit, i)
                lit = None
            if r <= 64:
                out.append(0x80 | (r - 1))
            else:
                out.append(0xC0 | ((r - 1) >> 8))
                out.append((r - 1) & 0xFF)
            out.append(data[i])
            i += r
        else:
            if lit is None:
                lit = i
            i += r
    if lit is not None:
        emit_lit(lit, n)
    return bytes(out)


# ---------------- ЗАГРУЗКА... glyphs (white bodies, 8 rows) -----------------

GLYPHS = {
    "З": ["..####.", ".##..##", ".....##", "...###.",
          ".....##", ".....##", ".##..##", "..####."],
    "А": ["..##...", ".####..", "##..##.", "##..##.",
          "######.", "##..##.", "##..##.", "##..##."],
    "Г": ["######.", "######.", "##.....", "##.....",
          "##.....", "##.....", "##.....", "##....."],
    "Р": ["#####..", "##..##.", "##..##.", "#####..",
          "##.....", "##.....", "##.....", "##....."],
    "У": ["##..##.", "##..##.", "##..##.", ".#####.",
          "....##.", "....##.", "...##..", ".###..."],
    "К": ["##..##.", "##.##..", "####...", "###....",
          "####...", "##.##..", "##..##.", "##..##."],
    ".": ["..", "..", "..", "..", "..", "..", "##", "##"],
}
TEXT = "ЗАГРУЗКА..."

ATLAS_OFF = 0x395D8       # container in SCPS_101.15
STREAM_OFF = ATLAS_OFF + 52 + 512   # 1 CLUT block of 512 B
BUDGET = 7870             # original stream size; SJIS table follows
AW, AH = 256, 144         # 4bpp, stride 128 B
BAND_Y0, BAND_Y1 = 113, 124   # rows to clear (incl.)
BAND_X1 = 105                 # last column to clear
BODY_Y = 116                  # glyph body top row
TEXT_X = 6                    # first glyph column


def patch_atlas(pixels):
    """pixels: bytearray of the 18432-byte 4bpp bitmap (modified in place)."""
    def setpx(x, y, v):
        o = y * 128 + x // 2
        pixels[o] = (pixels[o] & 0xF0) | v if x % 2 == 0 \
            else (pixels[o] & 0x0F) | (v << 4)

    for y in range(BAND_Y0, BAND_Y1 + 1):          # stripe background
        for x in range(0, BAND_X1 + 1):
            setpx(x, y, 0xF if x % 2 == 0 else 7)

    body = set()
    x = TEXT_X
    for ch in TEXT:
        g = GLYPHS[ch]
        for r, row in enumerate(g):
            for c, p in enumerate(row):
                if p == "#":
                    body.add((x + c, BODY_Y + r))
        x += len(g[0]) + (2 if ch == "." else 3)
    for px, py in body:
        setpx(px, py, 0xF)
    for px, py in body:                            # 1px dark outline
        for dx in (-1, 0, 1):
            for dy in (-1, 0, 1):
                q = (px + dx, py + dy)
                if q not in body and 0 <= q[0] <= BAND_X1 \
                        and BAND_Y0 <= q[1] <= BAND_Y1:
                    setpx(q[0], q[1], 0)


def patch_scps(disc):
    pristine = open(source(disc, "SCPS_101.15"), "rb").read()
    nch, npal = struct.unpack_from("<II", pristine, ATLAS_OFF)
    w, h = struct.unpack_from("<HH", pristine, ATLAS_OFF + 8)
    size0 = struct.unpack_from("<I", pristine, ATLAS_OFF + 12)[0]
    assert (nch, npal, w, h, size0) == (1, 1, AW, AH, BUDGET), \
        "unexpected atlas container layout"

    raw, _ = rle_decompress(pristine[STREAM_OFF:STREAM_OFF + size0])
    pixels = bytearray(raw[:AW * AH // 2])     # drop encoder tail slop
    patch_atlas(pixels)
    stream = rle_compress(bytes(pixels))
    back, _ = rle_decompress(stream)
    assert back == bytes(pixels), "RLE roundtrip failed"
    assert len(stream) <= BUDGET, \
        f"stream {len(stream)} B exceeds budget {BUDGET} B - must relocate"

    target = os.path.join(disc, "SCPS_101.15")
    data = bytearray(open(target, "rb").read())
    new = bytearray(pristine)                  # patch on top of pristine
    struct.pack_into("<I", new, ATLAS_OFF + 12, len(stream))
    new[STREAM_OFF:STREAM_OFF + len(stream)] = stream
    new[STREAM_OFF + len(stream):STREAM_OFF + BUDGET] = \
        bytes(BUDGET - len(stream))            # zero-fill dead tail
    region = slice(ATLAS_OFF, STREAM_OFF + BUDGET)
    if data[region] == new[region]:
        print(f"{target}: atlas already patched, nothing to do")
        return
    data[region] = new[region]
    open(target, "wb").write(data)
    print(f"{target}: ЗАГРУЗКА... drawn, stream {len(stream)}/{BUDGET} B")


# ---------------- memory-card save titles -----------------------------------

TITLES = (
    (0x1B48, 24, "АЛУНДРА２"),            # <=11 FW chars + 2 NUL
    (0x1B60, 28, "АЛУНДРА２／ФАЙЛ"),      # <=13 FW chars + 2 NUL
)


def patch_game00(disc):
    pristine = open(source(disc, "GAME00.BIN"), "rb").read()
    target = os.path.join(disc, "GAME00.BIN")
    data = bytearray(open(target, "rb").read())
    changed = False
    for off, slot, text in TITLES:
        enc = text.encode("shift_jis")
        assert len(enc) <= slot - 2, (text, len(enc), slot)
        blob = enc + bytes(slot - len(enc))
        assert len(pristine[off:off + slot]) == slot
        if data[off:off + slot] != blob:
            data[off:off + slot] = blob
            changed = True
    if changed:
        open(target, "wb").write(data)
        print(f"{target}: save titles -> "
              + " / ".join(t for _, _, t in TITLES))
    else:
        print(f"{target}: save titles already patched, nothing to do")


def main():
    args = sys.argv[1:]
    disc = "disc_jp"
    if "-d" in args:
        disc = args[args.index("-d") + 1]
    patch_scps(disc)
    patch_game00(disc)


if __name__ == "__main__":
    main()
