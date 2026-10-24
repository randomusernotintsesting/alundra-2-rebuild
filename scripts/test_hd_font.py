"""Professional glyph generation: full Cyrillic, honest metrics and exact bank IDs."""
import importlib
import math
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

from PIL import Image, ImageDraw, ImageFont
from a2.cyrfont import CELLS, build_banks
from a2.pak import PakArchive

try:
    builder = importlib.import_module("build_hd_font")
except ModuleNotFoundError:
    builder = None

ROOT = Path(__file__).resolve().parent.parent
FONT = ROOT/"port/assets/fonts/PT_Serif-Web-Regular.ttf"


class HDFontTests(unittest.TestCase):
    def setUp(self):
        self.assertIsNotNone(builder, "professional HD font builder is not implemented")

    def assets(self):
        original = PakArchive.load(ROOT/"disc.orig/DATA/PACK0.PAK")
        return builder.build_assets(FONT, original.slots[548], original.slots[545])

    def test_token_mapping_covers_all_66_cyrillic_letters_without_tofu(self):
        assets = self.assets()
        expected = set(range(0x410, 0x450)) | {0x401, 0x451}
        self.assertEqual(len(expected), 66)
        for height in (16, 24):
            profile = assets["profiles"][height]
            glyphs = profile["glyphs"]
            self.assertEqual(len(glyphs), 96)
            actual = {g["codepoint"] for g in glyphs}
            self.assertTrue(expected <= actual)
            for char, token in CELLS.items():
                self.assertEqual(glyphs[token-32]["codepoint"], ord(char))
            font = ImageFont.truetype(str(FONT), profile["ppem"], layout_engine=ImageFont.Layout.BASIC)
            missing = bytes(font.getmask("\uffff"))
            for cp in expected:
                self.assertNotEqual(bytes(font.getmask(chr(cp))), missing, f"tofu U+{cp:04X}")
            self.assertEqual(glyphs[0]["codepoint"], 32)
            self.assertEqual(glyphs[ord('7')-32]["codepoint"], ord('7'))

    def test_alpha_is_antialiased_bounded_and_16px_padding_is_zero(self):
        assets = self.assets()
        for height in (16, 24):
            for glyph in assets["profiles"][height]["glyphs"]:
                alpha = glyph["alpha"]
                self.assertEqual(len(alpha), 48*96)
                self.assertGreaterEqual(glyph["advance"], 1)
                self.assertLessEqual(glyph["advance"], 12)
                image = Image.frombytes("L", (48, 96), alpha)
                bbox = image.getbbox()
                if glyph["codepoint"] == 32:
                    self.assertIsNone(bbox)
                    self.assertGreaterEqual(glyph["advance"], 2, "space was dropped")
                    continue
                self.assertIsNotNone(bbox, f"empty glyph U+{glyph['codepoint']:04X}")
                self.assertGreaterEqual(bbox[0], 1)
                self.assertGreaterEqual(bbox[1], 1)
                self.assertLessEqual(bbox[2], 47)
                self.assertLessEqual(bbox[3], height*4-1)
                self.assertTrue(any(0 < a < 255 for a in alpha), "hard pixel art instead of AA outline")
                self.assertFalse(any(alpha[48*height*4:]), "16px glyph leaked into 24px padding")

    def test_profile_uses_one_outline_transform_and_natural_rounded_advances(self):
        assets = self.assets()
        for height, aspect in ((16, 1), (24, .5)):
            profile = assets["profiles"][height]
            self.assertEqual(profile["aspect_x"], aspect)
            font = ImageFont.truetype(str(FONT), profile["ppem"], layout_engine=ImageFont.Layout.BASIC)
            for glyph in profile["glyphs"]:
                char = chr(glyph["codepoint"])
                expected_advance = max(1, math.floor(font.getlength(char)/4*aspect+.5))
                self.assertEqual(glyph["advance"], expected_advance, char)
                # Independently draw the outline into the common profile
                # canvas. Per-character squeezing, recentering or baseline
                # adjustment would differ from this exact transform.
                raw = Image.new("L", (int(48/aspect), height*4))
                ImageDraw.Draw(raw).text((profile["origin_x"]/aspect, profile["baseline"]),
                                         char, font=font, fill=255, anchor="ls")
                if aspect != 1:
                    raw = raw.resize((48, height*4), Image.Resampling.BOX)
                padded = Image.new("L", (48, 96))
                padded.paste(raw, (0, 0))
                self.assertEqual(glyph["alpha"], padded.tobytes(), char)
        glyphs = assets["profiles"][24]["glyphs"]
        self.assertGreater(glyphs[0x59-32]["advance"], 6, "Ш stayed artificially monospaced")
        self.assertLess(glyphs[0x21-32]["advance"], 6, "! stayed artificially monospaced")

    def test_embedded_banks_are_exact_known_cyrillic_banks_not_hd_redraws(self):
        original = PakArchive.load(ROOT/"disc.orig/DATA/PACK0.PAK")
        assets = builder.build_assets(FONT, original.slots[548], original.slots[545])
        wanted = build_banks(original.slots[548], original.slots[545])
        self.assertEqual(assets["bank16"], wanted[0])
        self.assertEqual(assets["bank24"], wanted[1])
        self.assertEqual(len(assets["bank16"]), 4704)
        self.assertEqual(len(assets["bank24"]), 7008)

    def test_generation_and_metadata_are_deterministic(self):
        first, second = self.assets(), self.assets()
        self.assertEqual(builder.header_text(first), builder.header_text(second))
        self.assertEqual(builder.metadata(first), builder.metadata(second))
        metadata = builder.metadata(first)
        for key in ("16", "24"):
            self.assertEqual(len(metadata["profiles"][key]["glyphs"]), 96)
            self.assertTrue(all("codepoint" in g and "advance" in g and "bbox" in g
                                for g in metadata["profiles"][key]["glyphs"]))

    def test_generated_header_compiles_and_preserves_every_byte(self):
        compiler = shutil.which("clang") or shutil.which("cc")
        self.assertIsNotNone(compiler, "a C compiler is required for the native asset test")
        assets = self.assets()
        expected = bytearray()
        for height in (16, 24):
            for glyph in assets["profiles"][height]["glyphs"]:
                expected.extend(glyph["codepoint"].to_bytes(2, "big"))
                expected.append(glyph["advance"])
                expected.extend(glyph["alpha"])
        expected.extend(assets["bank16"])
        expected.extend(assets["bank24"])
        with tempfile.TemporaryDirectory(prefix="a2-hd-font-test-") as directory:
            folder = Path(directory)
            (folder/"font.h").write_text(builder.header_text(assets))
            (folder/"verify.c").write_text('''#include <stdio.h>
typedef struct A2HDGlyph A2HDGlyph;
#include "font.h"
static void emit(const A2HDGlyph *glyphs) {
    for (unsigned i = 0; i < 96; ++i) {
        putchar(glyphs[i].codepoint >> 8);
        putchar(glyphs[i].codepoint & 255);
        putchar(glyphs[i].advance);
        fwrite(glyphs[i].alpha, 1, sizeof glyphs[i].alpha, stdout);
    }
}
int main(void) {
    emit(a2_hd_glyphs16);
    emit(a2_hd_glyphs24);
    fwrite(a2_hd_bank16, 1, sizeof a2_hd_bank16, stdout);
    fwrite(a2_hd_bank24, 1, sizeof a2_hd_bank24, stdout);
    return ferror(stdout) != 0;
}
''')
            subprocess.run([compiler, "-std=c11", "-Wall", "-Wextra", "-Werror",
                            str(folder/"verify.c"), "-o", str(folder/"verify")],
                           check=True, capture_output=True)
            actual = subprocess.run([str(folder/"verify")], check=True,
                                    capture_output=True).stdout
        self.assertEqual(actual, expected)


if __name__ == "__main__":
    unittest.main()
