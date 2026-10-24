#!/usr/bin/env python3
"""Apply Russian name-canon unification to translations JSONs.

Authoritative spec: tools/analysis/name-unification.md
Idempotent: running twice produces no further changes.

Usage:
  python3 scripts/apply_name_canon.py [--dry-run]
"""
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TRANS = os.path.join(ROOT, "translations")

# ---------------------------------------------------------------------------
# 1. GENERAL TEXT REPLACEMENTS
#    Applied in order; each is (pattern, replacement, flags).
#    Cyrillic word boundary: (?<![А-Яа-яЁё]) / (?![А-Яа-яЁё])
# ---------------------------------------------------------------------------
CYR = r"[А-Яа-яЁё]"

# Helper to build a non-Cyrillic-bounded pattern
def cyrbnd(s):
    return rf"(?<!{CYR}){re.escape(s)}(?!{CYR})"


GENERAL_REPLACEMENTS = [
    # ---- Зеппо (Тэтцо / Теццо / Теттсо) ------------------------------------
    (re.compile(r"Тэтцо"),  "Зеппо"),
    (re.compile(r"Теццо"),  "Зеппо"),
    (re.compile(r"Теттсо"), "Зеппо"),

    # ---- Алексия (Айша / Айиша / Аиша + declensions) -----------------------
    # Declensions first (longer match before shorter)
    (re.compile(r"Айиша"),  "Алексия"),
    (re.compile(r"Айше"),   "Алексии"),   # dative
    (re.compile(r"Айшу"),   "Алексию"),   # accusative
    (re.compile(r"Айша"),   "Алексия"),   # nominative
    (re.compile(r"Аиша"),   "Алексия"),

    # ---- Альберт (Аль / Ал) — word-boundary, NEVER touch Алексия/Альберт --
    # We match standalone Аль / Ал not preceded or followed by Cyrillic
    (re.compile(rf"(?<!{CYR})Аль(?!{CYR})"), "Альберт"),
    (re.compile(rf"(?<!{CYR})Ал(?!{CYR})"),  "Альберт"),

    # ---- Милена (Мерседес) --------------------------------------------------
    (re.compile(r"Мерседес"), "Милена"),

    # ---- Барон Диас (Нижадор / Ниджадор / Нихадор / «Граф») ----------------
    # Named-with-title forms first
    (re.compile(r"[Гг]раф Нижадор"),   "Барон Диас"),
    (re.compile(r"[Гг]раф Ниджадор"),  "Барон Диас"),
    (re.compile(r"[Гг]раф Нихадор"),   "Барон Диас"),
    # Plain name
    (re.compile(r"Нижадор"),  "Диас"),
    (re.compile(r"Ниджадор"), "Диас"),
    (re.compile(r"Нихадор"),  "Диас"),
    # Standalone «Граф» / «граф» (as character reference, not «посланник графа»-style)
    # Only where it is used as a standalone address/name (speaker label or bold name tag)
    # Replace «граф» only when it is the *entire* bracketed name, e.g. {04:0003}Граф{04:0007}
    # or as a speaker label {04:0001}Граф:{04:0007}
    # Also: «господина графа» → «Барона», «к графу» → «к Барону» etc.
    (re.compile(r"(?<![А-Яа-яЁё])Граф(?!(?:[А-Яа-яЁё]| [Нн]ижадор| [Нн]иджадор| [Нн]ихадор))"),
     "Барон"),
    (re.compile(r"(?<![А-Яа-яЁё])граф(?!(?:[А-Яа-яЁё]| [Нн]ижадор| [Нн]иджадор| [Нн]ихадор))"),
     "барон"),

    # ---- Наташа (Латоя) -----------------------------------------------------
    (re.compile(r"Латоя"), "Наташа"),

    # ---- Прунвелл (Лорд Буриан) ---------------------------------------------
    (re.compile(r"Лорд Буриан"), "Прунвелл"),
    (re.compile(r"Буриан"),      "Прунвелл"),

    # ---- Акселия (Шайира) ---------------------------------------------------
    (re.compile(r"Шайира"), "Акселия"),

    # ---- Омега (Хедва / Хедве / Хедвы) -------------------------------------
    # Only in speaker-label context (metric: госпожа Хедвы -> госпожа Омеги)
    # and room-name context (Гадалка Хедвы -> Гадалка Омеги)
    (re.compile(r"госпожи Хедвы"),  "госпожи Омеги"),
    (re.compile(r"госпоже Хедве"),  "госпоже Омеге"),
    (re.compile(r"Гадалка Хедвы"),  "Гадалка Омеги"),
    (re.compile(r"Хедвы"),          "Омеги"),
    (re.compile(r"Хедве"),          "Омеге"),
    (re.compile(r"Хедва"),          "Омега"),

    # ---- Мутокс (Маокс) -----------------------------------------------------
    (re.compile(r"Маокс"), "Мутокс"),

    # ---- Тороледо (Гью-Йорк / Гьюёрк) -------------------------------------
    (re.compile(r"Гью-Йорк"), "Тороледо"),
    (re.compile(r"Гьюёрк"),   "Тороледо"),

    # ---- Гваба (Гвабакао / Гуавакакао) -------------------------------------
    # Compound forms first
    (re.compile(r"Ратуша Гвабы"),      "Ратуша Гвабы"),   # already correct, no-op guard
    (re.compile(r"Мэрия Гвабы"),       "Ратуша Гвабы"),
    (re.compile(r"[Зз]ал [Гг]ваба-[Кк]акао"), "Ратуша Гвабы"),
    (re.compile(r"[Зз]ал [Гг]уавакакао"),      "Ратуша Гвабы"),
    (re.compile(r"Порт Гвабакао"),     "Порт Гваба"),
    (re.compile(r"мостом Гваба\b"),    "мостом Гвабы"),   # genitive fix
    (re.compile(r"Гвабакао"),          "Гваба"),
    (re.compile(r"Гуавакакао"),        "Гваба"),

    # ---- Дан Уэбб (Уэблок / Уэбб-Лок) -------------------------------------
    (re.compile(r"Уэбб-Лок"),  "Дан Уэбб"),
    (re.compile(r"Уэблок"),    "Дан Уэбб"),
    # «руды Уэбб» is already correct (Дан Уэбб is the city name; ore is «руда Уэбб»)

    # ---- мудрец Розуэлл (Розуэлл-Мудрец / Розуэллу-Мудрецу / доктор Ндур)
    (re.compile(r"Розуэлл-Мудрец"),    "мудрец Розуэлл"),
    (re.compile(r"Розуэллу-Мудрецу"),  "мудрецу Розуэллу"),
    (re.compile(r"доктор Ндур"),        "мудрец Розуэлл"),
    (re.compile(r"[Дд]октора Ндур"),    "мудреца Розуэлла"),

    # ---- Ванильная вафля (MUST come before Ванилла->Варуна catch-alls) --------
    # These specific phrases must be fixed before the dynasty catch-alls fire.
    (re.compile(r"Ванилл\.печенье"),          "Ванильная вафля"),
    (re.compile(r"Вафля со вкусом Ваниллы"),  "Ванильная вафля"),
    (re.compile(r"Вафля Ваниллы"),            "Ванильная вафля"),
    (re.compile(r"Ванильное печенье"),        "Ванильная вафля"),
    # Handle form already corrupted in a prior pass (Варуна catch-all ran first)
    (re.compile(r"Вафля со вкусом Варуны"),   "Ванильная вафля"),
    (re.compile(r"Вафля Варуны"),             "Ванильная вафля"),

    # ---- Варуна (Ванилла dynasty/kingdom/clan — NOT Ванильная)  ------------
    # Proper name forms (genitive Ваниллы -> Варуны, accusative Ваниллу -> Варуну, etc.)
    # Rule: replace «Ванилла» as a dynasty/family/kingdom name (followed by non-н chars)
    # Do NOT replace «Ванильн» (adjective: Ванильная вафля, Ванильное печенье)
    (re.compile(r"Ваниллу XIII"),       "Варуну XIII"),
    (re.compile(r"Ваниллы XIII"),       "Варуны XIII"),
    (re.compile(r"Ванилла XIII"),       "Варуна XIII"),
    # Named compounds
    (re.compile(r"дворец Ванилла"),     "дворец Варуны"),
    (re.compile(r"семья Ванилла"),      "семья Варуны"),
    (re.compile(r"семьи Ваниллы"),      "семьи Варуны"),
    (re.compile(r"клан Ванилла"),       "клан Варуны"),
    (re.compile(r"клана Ваниллы"),      "клана Варуны"),
    (re.compile(r"дом Ваниллы"),        "дом Варуны"),
    (re.compile(r"дома Ваниллы"),       "дома Варуны"),
    (re.compile(r"реликвию дома Ваниллы"), "реликвию дома Варуны"),
    (re.compile(r"реликвии Ваниллы"),   "реликвии Варуны"),
    (re.compile(r"королевства Ванилла"), "королевства Варуны"),
    (re.compile(r"королевство Ванилла"), "королевство Варуны"),
    (re.compile(r"королевская семья Ванилла"), "королевская семья Варуны"),
    (re.compile(r"династии Ванилла"),   "династии Варуны"),
    (re.compile(r"династия Ванилла"),   "династия Варуны"),
    (re.compile(r"7-я принцесса Ваниллы"), "7-я принцесса Варуны"),
    (re.compile(r"принцесса Ваниллы"),  "принцесса Варуны"),
    (re.compile(r"(?<![А-Яа-яЁё])первый Ванилла"), "первый Варуна"),
    # Catch-all for remaining «Ванилла» (as name, not adjective)
    # Only match Ванилла NOT followed by «н» (which would be Ванильн...)
    (re.compile(r"Ванилла(?!н)"),       "Варуна"),
    (re.compile(r"Ваниллы(?!н)"),       "Варуны"),
    (re.compile(r"Ваниллу(?!н)"),       "Варуну"),

    # ---- Дети Короны (Стражи папы) -----------------------------------------
    (re.compile(r"Стражи папы"), "Дети Короны"),

    # ---- Жрец (Сектант / Культист / Орденец) --------------------------------
    (re.compile(r"Сектант"), "Жрец"),
    (re.compile(r"Культист"), "Жрец"),
    (re.compile(r"Орденец"), "Жрец"),

    # ---- Птица Гу-Гу (Гугу / «Гу-Гу птица») --------------------------------
    (re.compile(r"Гугу"),       "Птица Гу-Гу"),
    # «Гу-Гу птица» -> «Птица Гу-Гу» (word order swap)
    (re.compile(r"Гу-Гу птица"), "Птица Гу-Гу"),
]

# ---------------------------------------------------------------------------
# 2. PER-ID SPEAKER FIXES
#    (id, old_text_exact_or_pattern, new_text)
#    Applied as exact string replacements to the «text» field of that entry.
# ---------------------------------------------------------------------------

# The 26 Флинт-speaker IDs that should say Зеппо
# (from md: vc.e069.{0,1,6,8,10,13}, vc.e219.{18,19,21}, vc.e223.{2,3,4},
#  vc.e226.{2,3,4}, vc.e228.{0,1}, vc.e238.{0,8}, vc.e264.{4,6,11,13,18}, vc.e311.{2,8})
# Special cases handled separately: e219.19 ("Флинт и Ал"), e232.5 (Алексия speaking to Зеппо)
# Excluded from speaker-fix (hero addresses): vc.e226.2 — speaker IS Флинт here (Руби calls the hero)
# Actually per md: vc.e226.2 is IN the 27-list but its TEXT is "Эй! Флинт!!"
# where Флинт is address to the hero AND the speaker is Флинт(=Зеппо).
# So the SPEAKER changes to Зеппо; the "Флинт!!" in body stays as address to hero.

SPEAKER_FIX_IDS = [
    "vc.e069.0", "vc.e069.1", "vc.e069.6", "vc.e069.8", "vc.e069.10", "vc.e069.13",
    "vc.e219.18",
    "vc.e219.21",
    "vc.e223.2", "vc.e223.3", "vc.e223.4",
    "vc.e226.3", "vc.e226.4",
    "vc.e228.0", "vc.e228.1",
    "vc.e238.0", "vc.e238.8",
    "vc.e264.4", "vc.e264.6", "vc.e264.11", "vc.e264.13", "vc.e264.18",
    "vc.e311.2", "vc.e311.8",
]
# For these, replace {04:0001}Флинт: with {04:0001}Зеппо:
# (the body text — which in e223.3, e223.4, e226.3, e226.4 still contains «Мерседес» —
# will be handled by GENERAL_REPLACEMENTS after speaker fix)

EXPLICIT_FIXES = {
    # vc.e219.19: joint shout "Флинт и Ал" -> "Зеппо и Альберт"
    "vc.e219.19": (
        "{SYS}{04:0001}Флинт и Ал:{04:0007}Уо-о!!",
        "{SYS}{04:0001}Зеппо и Альберт:{04:0007}Уо-о!!",
    ),
    # vc.e232.5: Алексия is the speaker (jp: アイーシャ); fix speaker label only
    "vc.e232.5": (
        "{SYS}{04:0001}Флинт,{04:0007} ты что...\n{SYS}Стой! Стой!",
        "{SYS}{04:0001}Алексия:{04:0007}ты что...\n{SYS}Стой! Стой!",
    ),
    # vc.e062.31: wrong speaker label "Руби!!!" should be "Зеппо:Руби!!!"
    "vc.e062.31": (
        "{SYS}{04:0001}Руби!!!{04:0003}{04:0007}",
        "{SYS}{04:0001}Зеппо:{04:0003}Руби{04:0007}!!!",
    ),
    # vc.e213.3: wrong speaker label "Нунуги!" should be "Диас:Нунуги!"
    "vc.e213.3": (
        "{SYS}{04:0001}Нунуги!{04:0003}Нунуги{04:0007}",
        "{SYS}{04:0001}Диас:{04:0003}Нунуги{04:0007}!",
    ),
    # vc.e226.2: speaker IS Зеппо; body text addresses the hero as "Флинт" — correct, keep
    "vc.e226.2": (
        "{SYS}{04:0001}Флинт:{04:0007}Эй! Флинт!!",
        "{SYS}{04:0001}Зеппо:{04:0007}Эй! Флинт!!",
    ),
}

# Hero-address entries where literal «Флинт» must NOT be changed:
HERO_ADDRESS_IDS = {
    "vc.e226.2",   # body: «Эй! Флинт!!» — address to hero
    "vc.e253.10",  # body contains フリット = Флинт (hero's name)
    "vc.e256.10",  # same scene duplicate
    "vc.e025.2",   # speaker label IS {04:0001}Флинт, прости,{04:0007} — address to hero in speaker slot
    # g271.s6 «Флинтяга» stays as-is (grp, no speaker-fix needed there)
}

# ---------------------------------------------------------------------------
# 3. LINE-LENGTH REWRAPS (applied AFTER all substitutions)
#    Entries that are known to overflow 34 chars after replacement.
# ---------------------------------------------------------------------------
REWRAPS = {
    # Аль -> Альберт makes line 35 chars
    "vc.e228.5": (
        "{SYS}{04:0001}Альберт:{04:0007}маг-эволюцию запустить, мол",
        "{SYS}{04:0001}Альберт:{04:0007}маг-эволюцию\nзапустить, мол",
    ),
    # Айше -> Алексии makes line 36 chars
    "vc.e188.1": (
        "{SYS}{04:0007}Прошу дозволить жениться на {04:0003}Алексии{04:0007}!",
        "{SYS}{04:0007}Прошу дозволить\nжениться на {04:0003}Алексии{04:0007}!",
    ),
}


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def apply_general(text: str) -> str:
    for pat, repl in GENERAL_REPLACEMENTS:
        text = pat.sub(repl, text)
    return text


def apply_entry(eid: str, entry: dict) -> tuple[bool, str]:
    """Return (changed, new_text)."""
    text = entry.get("text", "")
    if not text:
        return False, text

    original = text

    # 1. Explicit whole-entry fixes (highest priority)
    if eid in EXPLICIT_FIXES:
        old, new = EXPLICIT_FIXES[eid]
        if old in text:
            text = text.replace(old, new)
        # After explicit fix, still run general replacements on the result
        text = apply_general(text)
        text = _apply_rewrap(eid, text)
        return text != original, text

    # 2. Speaker-label fix: Флинт -> Зеппо in {04:0001}...{04:0007}
    if eid in SPEAKER_FIX_IDS:
        # Replace speaker «Флинт:» -> «Зеппо:»
        text = re.sub(
            r'(\{04:0001\})Флинт(?=:)',
            r'\1Зеппо',
            text,
        )

    # 3. General substitutions
    #    Skip Флинт substitution in hero-address entries
    if eid not in HERO_ADDRESS_IDS:
        text = apply_general(text)
    else:
        # Apply everything EXCEPT touching «Флинт» anywhere
        # (hero-address entries may still have other names to fix)
        saved = text
        text = apply_general(text)
        # Restore «Флинт» occurrences that were in the original
        # (general replacements don't touch Флинт, so this is a no-op guard)

    # 4. Rewrap if needed
    text = _apply_rewrap(eid, text)

    return text != original, text


def _apply_rewrap(eid: str, text: str) -> str:
    if eid in REWRAPS:
        old, new = REWRAPS[eid]
        text = text.replace(old, new)
    return text


def load_json(path: str) -> dict:
    with open(path, encoding="utf-8") as f:
        return json.load(f)


def save_json(path: str, data: dict) -> None:
    with open(path, "w", encoding="utf-8") as f:
        json.dump(data, f, ensure_ascii=False, indent=1)
        f.write("\n")


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    dry_run = "--dry-run" in sys.argv

    files = {
        "grp_text":    os.path.join(TRANS, "grp_text.json"),
        "vcast_text":  os.path.join(TRANS, "vcast_text.json"),
        "pack0_text":  os.path.join(TRANS, "pack0_text.json"),
    }

    total_changed = {}

    for fname, fpath in files.items():
        data = load_json(fpath)
        entries = data["entries"]
        changed_ids = {}

        for eid, entry in entries.items():
            changed, new_text = apply_entry(eid, entry)
            if changed:
                changed_ids[eid] = new_text
                entry["text"] = new_text

        total_changed[fname] = changed_ids

        if not dry_run:
            save_json(fpath, data)

        print(f"{fname}: {len(changed_ids)} entries changed")

    if dry_run:
        print("[dry-run] files not written")
    else:
        print("Done.")

    # Dump changed entries to a temp file for validation
    all_changed = {}
    for changed_ids in total_changed.values():
        all_changed.update(changed_ids)

    dump_path = os.path.join(ROOT, "scripts", "_canon_changed.json")
    with open(dump_path, "w", encoding="utf-8") as f:
        json.dump(all_changed, f, ensure_ascii=False, indent=1)
        f.write("\n")
    print(f"Changed entries written to {dump_path}")
    print(f"Total changed: {sum(len(v) for v in total_changed.values())}")


if __name__ == "__main__":
    main()
