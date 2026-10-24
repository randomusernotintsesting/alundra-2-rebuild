"""Render source pixels and advance boundaries; never writes game assets."""
import argparse
import json
from pathlib import Path

from PIL import Image, ImageDraw
from a2.cyrfont import decode_bank
from a2.pak import PakArchive


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("output", type=Path)
    args = ap.parse_args()
    root = Path(__file__).resolve().parent.parent
    current = PakArchive.load(str(root / "disc_jp/DATA/PACK0.PAK"))
    original = PakArchive.load(str(root / "disc_jp.orig/DATA/PACK0.PAK"))
    cmap = json.loads((root / "scripts/charmap.json").read_text())
    labels = [("Ge", "Г"), ("Zhe", "Ж"), ("zhe", "ж"),
              ("en", "н"), ("pe", "п"), ("che", "ч")]
    im = Image.new("RGB", (1000, 720), "#17202a")
    draw = ImageDraw.Draw(im)
    draw.text((12, 10), "Exact 2-bit glyphs, 6x scale. Red = advance boundary. Shades 1/2/3 = dark/mid/bright.", fill="white")
    for row, (slot, height, arc, title) in enumerate([
            (548, 16, current, "Current Cyrillic 12x16"),
            (548, 16, original, "Original Latin same cells 12x16"),
            (545, 24, current, "Current Cyrillic 12x24"),
            (545, 24, original, "Original Latin same cells 12x24")]):
        glyphs = decode_bank(arc.slots[slot], height)
        top = 42 + row * 166
        draw.text((12, top), title, fill="white")
        for col, (name, ch) in enumerate(labels):
            byte = cmap[ch] & 255
            px, advance = glyphs[byte - 32]
            x0, y0 = 215 + col * 130, top + 17
            draw.text((x0, top), f"{name} / {chr(byte)}: {advance}px", fill="white")
            for y, line in enumerate(px):
                for x, level in enumerate(line):
                    color = ["#080c10", "#52606f", "#a4afbd", "#ffffff"][level]
                    draw.rectangle((x0+x*6, y0+y*6, x0+x*6+5, y0+y*6+5), fill=color)
            draw.line((x0+advance*6, y0, x0+advance*6, y0+height*6), fill="#ff4040")
    im.save(args.output)


if __name__ == "__main__":
    main()
