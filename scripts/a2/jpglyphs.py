"""Decode {JP:xxxx} glyph tokens to readable Japanese.

Uses tools/analysis/jp-font/glyphmap.json (built from the SJIS<->glyph
table inside SCPS_101.15).
"""
import json
import os
import re

_MAP = None
_TOKEN = re.compile(r"\{JP:([0-9A-F]{4})\}")


def _load():
    global _MAP
    if _MAP is None:
        path = os.path.join(os.path.dirname(os.path.dirname(
            os.path.dirname(os.path.abspath(__file__)))),
            "tools", "analysis", "jp-font", "glyphmap.json")
        _MAP = {k: v["char"]
                for k, v in json.load(open(path, encoding="utf-8"))["glyphs"].items()}
    return _MAP


def decode(markup):
    """Replace {JP:xxxx} tokens in markup with the actual characters."""
    m = _load()
    return _TOKEN.sub(lambda t: m.get(t.group(1), t.group(0)), markup)
