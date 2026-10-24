#!/usr/bin/env python3
"""Validate a translated batch against display constraints.

Usage: validate_translations.py <batch_output.json>
  batch_output.json: {"<entry id>": "<russian text>", ...}

Checks per entry (against the original in translations/*.json):
  - all {..} tags preserved (same multiset, {SYS} stays leading)
  - %-format specs preserved in order
  - same number of {PAGE} pages
  - allowed charset only (А-Яа-яЁё + ASCII 0x20-0x7A + newline;
    no «», long dash, ellipsis char)
  - visible Latin and ASCII cells repurposed by charmap.json are forbidden
    (control tags and printf placeholders are not visible glyphs)
  - visible line length <= 34, except measured item-description layout
  - lines per page <= max(3, original's max)
  - UI entries: visible chars + 1-byte tags <= max_inplace
  - unmeasured text: total visible length <= original * 1.3 + 8

Prints JSON {id: [errors]} for failing entries; exits 1 if any.
"""
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TAG = re.compile(r"\{[^}]*\}")
FMT = re.compile(r"%[-#0-9.lh]*[a-zA-Z]")
MAXLINE = 34
# Original full-width Latin glyphs, not the repurposed FFxx font cells.
# Verified against tools/analysis/jp-font/glyphmap.json (001F=A .. 0038=Z).
LATIN_JP_GLYPHS = set(range(0x001F, 0x0039))
with open(os.path.join(ROOT, "scripts", "charmap.json"), encoding="utf-8") as _f:
    REPURPOSED_ASCII = {chr(token & 0xFF) for token in json.load(_f).values()
                        if token >> 8 == 0xFF and token & 0xFF < 128}


def load_sources():
    src = {}
    for f in ("grp_text", "pack0_text", "vcast_text", "ui_text"):
        p = os.path.join(ROOT, "translations", f + ".json")
        if os.path.exists(p):
            src.update(json.load(open(p, encoding="utf-8"))["entries"])
    return src


def plain(s):
    # Approved JP letters consume a visible glyph/column, unlike controls.
    s = re.sub(r"\{JP:([0-9A-Fa-f]{4})\}",
               lambda m: "□" if int(m[1], 16) in LATIN_JP_GLYPHS else m[0], s)
    return TAG.sub("", s)


def control_tags(s):
    """All {..} tags except {JP:..} glyph tokens (those ARE the text and
    get replaced by the translation)."""
    return sorted(t for t in TAG.findall(s) if not t.startswith("{JP:"))


def check(entry, text):
    orig = entry["orig"]
    errs = []
    # Native item help window: 304x88, 8px inset, three 24px lines.
    # Mode2's installed 24px bank uses 6px advances (including space after
    # the original width clamp). This role applies only to verified fields;
    # unknown/dynamic glyph widths must not silently count as zero.
    layout = entry.get("layout")
    # The item-action popup also uses mode2 and auto-sizes to max text+36px.
    # Keep that complete window inside the320px source canvas.
    measured = layout in ("item_description", "item_action")
    pixel_limit = 284 if layout == "item_action" else 288
    if layout is not None and not measured:
        errs.append("неизвестный проверенный макет текста")
    if measured and (FMT.search(text) or any(
            not re.fullmatch(r"\{SYS\}|\{04:[0-9A-Fa-f]{4}\}|\{07:000[01]\}", tag)
            for tag in TAG.findall(text))):
        errs.append("макет меню требует текста с известной шириной глифов")
    if control_tags(orig) != control_tags(text):
        errs.append("управляющие теги не совпадают с оригиналом")
    jp_tags = re.findall(r"\{JP:[^}]*\}?", text)
    if any(not re.fullmatch(r"\{JP:[0-9A-Fa-f]{4}\}", tag)
           or int(tag[4:-1], 16) not in LATIN_JP_GLYPHS for tag in jp_tags):
        errs.append("в переводе остались {JP:..} токены")
    if orig.startswith("{SYS}") and not text.startswith("{SYS}"):
        errs.append("{SYS} должен быть в начале")
    if FMT.findall(orig) != FMT.findall(text):
        errs.append("%-форматы не совпадают")
    op, tp = orig.split("{PAGE}"), text.split("{PAGE}")
    if len(op) != len(tp):
        errs.append(f"страниц {len(tp)}, в оригинале {len(op)}")
    bad = sorted({c for c in TAG.sub("", text)
                  if not (c == "\n" or "А" <= c <= "я"
                          or c in "Ёё" or 0x20 <= ord(c) <= 0x7A)})
    if bad:
        errs.append("запрещённые символы: " + "".join(bad))
    # UI overlays use a separate ASCII printer; this restriction is for the
    # Russian token font only, whose old Latin cells now contain Cyrillic.
    if "max_inplace" not in entry:
        visible = FMT.sub("", plain(text))
        collisions = sorted({c for c in visible if c in REPURPOSED_ASCII
                             or "A" <= c <= "Z" or "a" <= c <= "z"})
        if collisions:
            errs.append("символы заменены кириллицей в шрифте: " + "".join(collisions))
    if "max_inplace" in entry:
        nbytes = len(plain(text)) + len(TAG.findall(text))
        if nbytes > entry["max_inplace"]:
            errs.append(f"{nbytes} байт > слота {entry['max_inplace']}")
    else:
        orig_max_lines = max(len(p.split("\n")) for p in op)
        for pi, page in enumerate(tp):
            lines = plain(page).split("\n")
            max_lines = (1 if layout == "item_action" else 3) if measured else max(3, orig_max_lines)
            if len(lines) > max_lines:
                errs.append(f"стр.{pi + 1}: {len(lines)} строк (лимит "
                            f"{max_lines})")
            for ln in lines:
                if measured and len(ln) * 6 > pixel_limit:
                    errs.append(f"строка {len(ln) * 6} пикселей (>{pixel_limit})")
                elif not measured and len(ln) > MAXLINE:
                    errs.append(f"строка {len(ln)} симв. (>34): «{ln[:24]}…»")
    # length ratio vs the English reference (JP originals are denser, so
    # comparing against them is meaningless; without a usable reference rely
    # on the line/page limits above). A reference is usable only if it has
    # actual visible latin text (US leftovers can be JP tokens themselves).
    ref = None
    for cand in (entry.get("en"), orig):
        if (cand and "{JP:" not in cand and re.search(r"[A-Za-z]", plain(cand))
                and plain(cand).strip().lower() != "temp"):
            ref = cand
            break
    if ref and not measured and len(plain(text)) > len(plain(ref)) * 1.3 + 8:
        errs.append(f"слишком длинно: {len(plain(text))} симв., "
                    f"источник {len(plain(ref))}")
    return errs


def main():
    batch = json.load(open(sys.argv[1], encoding="utf-8"))
    src = load_sources()
    out = {}
    for eid, text in batch.items():
        if eid not in src:
            out[eid] = ["неизвестный id"]
            continue
        if not text:
            continue
        errs = check(src[eid], text)
        if errs:
            out[eid] = errs
    if out:
        print(json.dumps(out, ensure_ascii=False, indent=1))
        sys.exit(1)
    print("OK")


if __name__ == "__main__":
    main()
