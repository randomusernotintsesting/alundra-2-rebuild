#!/usr/bin/env python3
"""Convert unified US-canon Russian names to JP-faithful names.

Spec: tools/analysis/name-unification.md  (§ JP-профиль имён)
Idempotent: running twice produces 0 changes.

Usage:
  python3 scripts/name_profile_jp.py [--dry-run]

Mapping (US-canon -> JP-canon):
  Зеппо          -> Тэтцо
  Алексия        -> Аиша
  Аль / Аля      -> Альберт / Альберта (full-name exception, 2026-09-04)
  Милена         -> Мерседес (indeclinable)
  Барон Диас     -> граф Нидзядор
  Наташа         -> Латоя
  Прунвелл       -> лорд Буриан
  Акселия        -> Шайира
  Омега          -> Хедва
  Мутокс         -> Маокс
  Тороледо       -> Гю-Йорк (indeclinable)
  Гваба          -> Гвабакакао (indeclinable)
  Дан Уэбб       -> Уэброк
  мудрец Розуэлл -> доктор Ндур
  Варуна         -> Ванилла
  Ванильная вафля -> Ванильное манджу
  Дети Короны    -> отряд «Папа-защита»
  Флинт          -> Флит (only 5 specific literal occurrences)
"""

import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TRANS = os.path.join(ROOT, "translations")

CYR = r"[А-Яа-яЁё]"


def cyrbnd(s: str) -> str:
    """Wrap a literal with Cyrillic non-word boundaries."""
    return rf"(?<!{CYR}){re.escape(s)}(?!{CYR})"


# ---------------------------------------------------------------------------
# 1. GENERAL TEXT REPLACEMENTS (applied in order)
# ---------------------------------------------------------------------------

GENERAL_REPLACEMENTS = [

    # ---- Ванильная вафля -> Ванильное манджу (BEFORE Варуна catch-alls) ----
    (re.compile(r"Ванильная вафля"),       "Ванильное манджу"),
    (re.compile(r"Ванильной вафли"),       "Ванильного манджу"),
    (re.compile(r"Ванильную вафлю"),       "Ванильное манджу"),

    # ---- Варуна -> Ванилла (dynasty/kingdom — NOT Ванильн- adjectives) -----
    # Handle all compound forms explicitly before the catch-alls:
    (re.compile(r"королевства Варуны"),    "королевства Ваниллы"),
    (re.compile(r"королевство Варуны"),    "королевство Ваниллы"),
    (re.compile(r"короля королевства Варуны"), "короля королевства Ваниллы"),
    (re.compile(r"принцессы Варуны"),      "принцессы Ваниллы"),
    (re.compile(r"принцесса Варуны"),      "принцесса Ваниллы"),
    (re.compile(r"7-я принцесса Варуны"),  "7-я принцесса Ваниллы"),
    (re.compile(r"династии Варуны"),       "династии Ваниллы"),
    (re.compile(r"династия Варуны"),       "династия Ваниллы"),
    (re.compile(r"семьи Варуны"),          "семьи Ваниллы"),
    (re.compile(r"семья Варуны"),          "семья Ваниллы"),
    (re.compile(r"клана Варуны"),          "клана Ваниллы"),
    (re.compile(r"клан Варуны"),           "клан Ваниллы"),
    (re.compile(r"дома Варуны"),           "дома Ваниллы"),
    (re.compile(r"дом Варуны"),            "дом Ваниллы"),
    (re.compile(r"реликвии Варуны"),       "реликвии Ваниллы"),
    (re.compile(r"реликвию дома Варуны"),  "реликвию дома Ваниллы"),
    (re.compile(r"первый Варуна"),         "первый Ванилла"),
    (re.compile(r"Варуну XIII"),           "Ваниллу XIII"),
    (re.compile(r"Варуны XIII"),           "Ваниллы XIII"),
    (re.compile(r"Варуна XIII"),           "Ванилла XIII"),
    # Catch-all: Варун* only when NOT followed by Cyrillic (single standalone form)
    # Covers: Варуна, Варуны, Варуну, Варуной, Варуне
    (re.compile(r"Варуны(?![А-Яа-яЁё])"),  "Ваниллы"),
    (re.compile(r"Варуну(?![А-Яа-яЁё])"),  "Ваниллу"),
    (re.compile(r"Варуной(?![А-Яа-яЁё])"), "Ваниллой"),
    (re.compile(r"Варуне(?![А-Яа-яЁё])"),  "Ванилле"),
    (re.compile(r"Варуна(?![А-Яа-яЁё])"),  "Ванилла"),

    # ---- Зеппо -> Тэтцо --------------------------------------------------
    # Word-boundary only so we don't mangle e.g. «Зеппони» (hypothetical)
    (re.compile(cyrbnd("Зеппо")),          "Тэтцо"),

    # ---- Алексия -> Аиша (with declensions) -------------------------------
    # Accusative first (longer form → before nominative)
    (re.compile(r"Алексию"),               "Аишу"),
    # Genitive/dative: distinguish by preceding prepositions where possible
    # Dative: к/по/к + space before -> Аише
    (re.compile(r"(?<=[кК]\s)Алексии"),    "Аише"),
    (re.compile(r"(?<=[оО]б\s)Алексии"),   "Аише"),
    # Remaining 'Алексии' -> Аиши (genitive)
    (re.compile(r"Алексии"),               "Аиши"),
    # Nominative / other cases
    (re.compile(r"Алексия"),               "Аиша"),

    # Full-name exception requested for Albert (JP アル). Preserve all other
    # JP names; boundaries keep Алундра and longer names untouched.
    (re.compile(cyrbnd("Аля")),           "Альберта"),
    (re.compile(cyrbnd("Алю")),           "Альберту"),
    (re.compile(cyrbnd("Алем")),          "Альбертом"),
    (re.compile(cyrbnd("Але")),           "Альберте"),
    (re.compile(cyrbnd("Аль")),           "Альберт"),

    # ---- Мерседес -> Милена (indeclinable; handle title forms) -------------
    # Title+name genitive (Леди Милены / госпожа Милены …)
    (re.compile(r"[Лл]еди Милены"),        "леди Мерседес"),
    (re.compile(r"[Гг]оспоже? Милен[ыуе]?"), "госпожа Мерседес"),
    # All inflected forms -> Мерседес (indeclinable)
    (re.compile(r"Милены"),                "Мерседес"),
    (re.compile(r"Милене"),                "Мерседес"),
    (re.compile(r"Милену"),                "Мерседес"),
    (re.compile(r"Миленой"),               "Мерседес"),
    # Title+name nominative (Леди/леди Милена)
    (re.compile(r"[Лл]еди Милена"),        "леди Мерседес"),
    # Standalone nominative
    (re.compile(r"Милена"),                "Мерседес"),

    # ---- Барон Диас -> граф Нидзядор ------------------------------------
    # Full title+name (all cases) FIRST:
    (re.compile(r"[Бб]арона Диаса"),       "графа Нидзядора"),
    (re.compile(r"[Бб]арону Диасу"),       "графу Нидзядору"),
    (re.compile(r"[Бб]ароном Диасом"),     "графом Нидзядором"),
    (re.compile(r"[Бб]ароне Диасе"),       "графе Нидзядоре"),
    (re.compile(r"[Бб]арон Диас"),         "граф Нидзядор"),
    # Standalone Диас (without Барон):
    (re.compile(r"Диаса"),                 "Нидзядора"),
    (re.compile(r"Диасу"),                 "Нидзядору"),
    (re.compile(r"Диасом"),                "Нидзядором"),
    (re.compile(r"Диасе"),                 "Нидзядоре"),
    (re.compile(cyrbnd("Диас")),           "Нидзядор"),
    # Standalone Барон/Барона/Барону/Бароном/Бароне -> граф/* (lowercase except sentence start)
    # We do case-insensitive replacement but output: uppercase Б -> uppercase Г,
    # lowercase б -> lowercase г (handled by sub function below)
    # Pattern: Барон[аоумe]? not followed by space + Диас
    (re.compile(r"Барона(?!\s+Диас|\s+Нидзядор)"),  "графа"),
    (re.compile(r"Барону(?!\s+Диас|\s+Нидзядор)"),   "графу"),
    (re.compile(r"Бароном(?!\s+Диас|\s+Нидзядор)"),  "графом"),
    (re.compile(r"Бароне(?!\s+Диас|\s+Нидзядор)"),   "графе"),
    (re.compile(r"Барон(?!\s+Диас|\s+Нидзядор|а|у|о|е)"), "граф"),
    (re.compile(r"барона(?!\s+Диас|\s+Нидзядор)"),   "графа"),
    (re.compile(r"барону(?!\s+Диас|\s+Нидзядор)"),   "графу"),
    (re.compile(r"бароном(?!\s+Диас|\s+Нидзядор)"),  "графом"),
    (re.compile(r"бароне(?!\s+Диас|\s+Нидзядор)"),   "графе"),
    (re.compile(r"барон(?!\s+Диас|\s+Нидзядор|а|у|о|е)"), "граф"),

    # ---- Наташа -> Латоя -----------------------------------------------
    (re.compile(r"Наташу"),                "Латою"),
    (re.compile(r"Наташи"),                "Латои"),
    (re.compile(r"Наташе"),                "Латое"),
    (re.compile(r"Наташей"),               "Латоей"),
    (re.compile(cyrbnd("Наташа")),         "Латоя"),

    # ---- Прунвелл -> лорд Буриан ----------------------------------------
    # 'лорд' already present - don't duplicate:
    (re.compile(r"[Лл]орд Прунвелла"),     "лорда Буриана"),
    (re.compile(r"[Лл]орду Прунвеллу"),    "лорду Буриану"),
    (re.compile(r"[Лл]ордом Прунвеллом"),  "лордом Бурианом"),
    (re.compile(r"[Лл]орде Прунвелле"),    "лорде Буриане"),
    (re.compile(r"[Лл]орд Прунвелл"),      "лорд Буриан"),
    # Standalone (add 'лорд' prefix):
    (re.compile(r"Прунвелла"),             "лорда Буриана"),
    (re.compile(r"Прунвеллу"),             "лорду Буриану"),
    (re.compile(r"Прунвеллом"),            "лордом Бурианом"),
    (re.compile(r"Прунвелле"),             "лорде Буриане"),
    (re.compile(r"Прунвеллу"),             "лорду Буриану"),
    (re.compile(cyrbnd("Прунвелл")),       "лорд Буриан"),

    # ---- Акселия -> Шайира ---------------------------------------------
    (re.compile(r"Акселии"),               "Шайиры"),
    (re.compile(r"Акселию"),               "Шайиру"),
    (re.compile(r"Акселией"),              "Шайирой"),
    (re.compile(r"Акселие"),               "Шайире"),
    (re.compile(cyrbnd("Акселия")),        "Шайира"),

    # ---- Омега -> Хедва ------------------------------------------------
    (re.compile(r"Омеги"),                 "Хедвы"),
    (re.compile(r"Омеге"),                 "Хедве"),
    (re.compile(r"Омегу"),                 "Хедву"),
    (re.compile(r"Омегой"),                "Хедвой"),
    (re.compile(cyrbnd("Омега")),          "Хедва"),

    # ---- Мутокс -> Маокс -----------------------------------------------
    (re.compile(r"Мутокса"),               "Маокса"),
    (re.compile(r"Мутоксу"),               "Маоксу"),
    (re.compile(r"Мутоксом"),              "Маоксом"),
    (re.compile(r"Мутоксе"),               "Маоксе"),
    (re.compile(cyrbnd("Мутокс")),         "Маокс"),

    # ---- Тороледо -> Гю-Йорк (indeclinable) ----------------------------
    # Тороледо already indeclinable in Russian
    (re.compile(r"Тороледо"),              "Гю-Йорк"),

    # ---- Гваба -> Гвабакакао (indeclinable) ----------------------------
    # Compound location names FIRST (longer → before shorter):
    (re.compile(r"Ратуша Гвабы"),          "Ратуша Гвабакакао"),
    (re.compile(r"Ратуше Гвабы"),          "Ратуше Гвабакакао"),
    (re.compile(r"Ратушу Гвабы"),          "Ратушу Гвабакакао"),
    (re.compile(r"мост Гвабы"),            "мост Гвабакакао"),
    (re.compile(r"мосту Гвабы"),           "мосту Гвабакакао"),
    (re.compile(r"мостом Гвабы"),          "мостом Гвабакакао"),
    (re.compile(r"Гавань Гвабы"),          "Гавань Гвабакакао"),
    (re.compile(r"Гавани Гвабы"),          "Гавани Гвабакакао"),
    (re.compile(r"ратуше Гваба(?!какао)"),  "ратуше Гвабакакао"),
    (re.compile(r"ратуша Гваба(?!какао)"),  "Ратуша Гвабакакао"),
    (re.compile(r"Порт Гваба(?!какао)"),   "порт Гвабакакао"),
    (re.compile(r"порт Гваба(?!какао)"),   "порт Гвабакакао"),
    (re.compile(r"[Гг]ород Гваба(?!какао)"), "город Гвабакакао"),
    # Genitive/dative/etc. of standalone Гваба:
    (re.compile(r"в Гвабу"),               "в Гвабакакао"),
    (re.compile(r"в Гвабе"),               "в Гвабакакао"),
    (re.compile(r"Гвабы"),                 "Гвабакакао"),
    (re.compile(r"Гвабе"),                 "Гвабакакао"),
    (re.compile(r"Гвабу"),                 "Гвабакакао"),
    # Nominative standalone (after all the above to avoid double-replace):
    (re.compile(r"(?<![А-Яа-яЁё])Гваба(?![А-Яа-яЁё])"), "Гвабакакао"),

    # ---- Дан Уэбб -> Уэброк -------------------------------------------
    (re.compile(r"Дана Уэбба"),            "Уэброка"),
    (re.compile(r"Дану Уэббу"),            "Уэброку"),
    (re.compile(r"Даном Уэббом"),          "Уэброком"),
    (re.compile(r"Дан Уэбб"),             "Уэброк"),
    # Standalone Уэбб (ore label, map label, abbreviation):
    (re.compile(r"руды Уэбб"),            "руды Уэброк"),
    (re.compile(r"(?<![А-Яа-яЁё])Уэбб(?![А-Яа-яЁё])"), "Уэброк"),

    # ---- мудрец Розуэлл -> доктор Ндур --------------------------------
    # Title+name forms (all cases) first:
    (re.compile(r"[Мм]удреца Розуэлла"),  "доктора Ндура"),
    (re.compile(r"[Мм]удрецу Розуэллу"),  "доктору Ндуру"),
    (re.compile(r"[Мм]удрецом Розуэллом"), "доктором Ндуром"),
    (re.compile(r"[Мм]удрец Розуэлл"),    "доктор Ндур"),
    (re.compile(r"[Мм]удрецу"),           "доктору"),   # standalone мудрецу (Розуэлл implied)
    # Standalone Розуэлл (add доктор prefix):
    (re.compile(r"Розуэлла"),             "Ндура"),
    (re.compile(r"Розуэллу"),             "Ндуру"),
    (re.compile(r"Розуэллом"),            "Ндуром"),
    (re.compile(r"Розуэлле"),             "Ндуре"),
    (re.compile(cyrbnd("Розуэлл")),       "доктор Ндур"),

    # ---- Дети Короны -> отряд «Папа-защита» ----------------------------
    (re.compile(r"Детей Короны"),         "отряда Папа-защита"),
    (re.compile(r"Детям Короны"),         "отряду Папа-защита"),
    (re.compile(r"Детьми Короны"),        "отрядом Папа-защита"),
    (re.compile(r'"Детей Короны"'),       '"отряда Папа-защита"'),
    (re.compile(r'«Детей Короны»'),       '«отряда Папа-защита»'),
    (re.compile(r'"Дети Короны"'),        '"отряд Папа-защита"'),
    (re.compile(r'«Дети Короны»'),        '«отряд Папа-защита»'),
    (re.compile(r"Дети Короны"),          "отряд Папа-защита"),

]

# ---------------------------------------------------------------------------
# 2. EXPLICIT ENTRY OVERRIDES
#    Applied AFTER general substitutions as a second pass.
#    Each entry: {id: (old_text_after_general, new_text)}
#    old_text is the expected text AFTER general substitutions.
# ---------------------------------------------------------------------------

# The 5 specific Флинт->Флит occurrences (literal hero-name occurrences):
FLINT_TO_FLIT_IDS = {
    "vc.e226.2",   # body: 'Зеппо:{04:0007}Эй! Флинт!!' — address to hero (vc.e226.2 speaker already Зеппо)
    "vc.e253.10",  # Руби calling hero
    "vc.e256.10",  # same scene duplicate
    "vc.e025.2",   # '{04:0001}Флинт, прости,{04:0007}' — speaker slot IS the hero's name in address
    # g271.s6: 'Флинтяга' -> 'Флитяга' — handled via explicit fix below
}

EXPLICIT_OVERRIDES = {
    # ---- Overflow rewraps (applied after general subs) -------------------

    # g023.s15: 'Мне надо поговорить с лордом Бурианом.' = 38 chars, 2 lines -> can add 1
    "g023.s15": (
        "Выйди на минуту.\nМне надо поговорить с лордом Бурианом.",
        "Выйди на минуту.\nМне надо поговорить\nс лордом Бурианом.",
    ),

    # g033.s2: 'Рад снова видеть тебя, лорд Буриан!\n...' = 35 chars, 3 lines max
    # -> Drop 'лорд' in vocative to fit (30 chars):
    "g033.s2": (
        "Рад снова видеть тебя, лорд Буриан!\nВыглядишь отлично!\nПохудел, что ли?",
        "Рад снова видеть тебя, Буриан!\nВыглядишь отлично!\nПохудел, что ли?",
    ),

    # g124.s8: page 0 line 0 = 35 chars, 3 lines max -> restructure (content preserved)
    "g124.s8": (
        "леди Мерседес - просто вдохновение!\n{04:0000}Она{04:0007} такая {04:0003}красотка{04:0007}!\nСтолько поклонников!",
        "леди Мерседес - просто\nвдохновение! {04:0000}Она{04:0007} такая\n{04:0003}красотка{04:0007}! Столько поклонников!",
    ),

    # g124.s9: 'леди Мерседес есть телохранитель...' = 35 chars, 3 lines max
    "g124.s9": (
        "О! Ты меня напугал! Да, у нашей\n{04:0003}леди Мерседес{04:0007} есть телохранитель...\nИ зачем ей это?",
        "О! Ты меня напугал! Да,\nу {04:0003}леди Мерседес{04:0007}\nесть телохранитель... Зачем?",
    ),

    # g182.s18: 'Лучший Вампетер в Гвабакакао - у нас!' = 37 chars
    # Page has 2 lines originally -> can add 1 (max(3,2)=3)
    "g182.s18": (
        "Добро пожаловать в наш ресторан!\nЛучший Вампетер в Гвабакакао - у нас!",
        "Добро пожаловать в наш ресторан!\nЛучший Вампетер\nв Гвабакакао - у нас!",
    ),

    # g195.s2: 'Муж - на встрече в ратуше Гвабакакао.' = 37 chars, 3 lines max
    # -> Restructure page 1 keeping 3 lines (preserve tags):
    "g195.s2": (
        "Крюк-рука?{PAGE}Извините, не знаю.\nМуж - на встрече в {04:0000}ратуше Гвабакакао{04:0007}.\nСпросите у него.",
        "Крюк-рука?{PAGE}Извините, не знаю.\nМуж на встрече в {04:0000}ратуше\nГвабакакао{04:0007}! Спросите его.",
    ),

    # g199.s62: 'Одна из принцесс отряда Папа-защита' = 35 chars
    # Page 1 has 2 lines originally -> can add 1 (max(3,2)=3)
    "g199.s62": (
        "Ты ищешь перемен в жизни.\nТебе нужен кто-то новый.{PAGE}Одна из принцесс {04:0000}отряда Папа-защита{04:0007}\n{04:0003}идеально подойдёт тебе!{04:0007}{PAGE}Но подожди ещё пару лет.",
        "Ты ищешь перемен в жизни.\nТебе нужен кто-то новый.{PAGE}Одна из принцесс\n{04:0000}отряда Папа-защита{04:0007}\n{04:0003}идеально подойдёт тебе!{04:0007}{PAGE}Но подожди ещё пару лет.",
    ),

    # g271.s6: 'Флинтяга' -> 'Флитяга'
    "g271.s6": (
        "Флинтяга!\nХочешь глянуть мой товар?",
        "Флитяга!\nХочешь глянуть мой товар?",
    ),
}


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def apply_general(text: str) -> str:
    for pat, repl in GENERAL_REPLACEMENTS:
        text = pat.sub(repl, text)
    return text


def apply_flint_to_flit(eid: str, text: str) -> str:
    """For specific IDs, change literal Флинт -> Флит (hero name)."""
    # vc.e226.2: 'Эй! Флинт!!' -> 'Эй! Флит!!'
    # vc.e253.10 / vc.e256.10: '...Флинт...' -> '...Флит...'
    # vc.e025.2: '{04:0001}Флинт, прости,{04:0007}' -> '{04:0001}Флит, прости,{04:0007}'
    return re.sub(r"Флинт", "Флит", text)


def apply_entry(eid: str, entry: dict) -> tuple[bool, str]:
    """Return (changed, new_text)."""
    text = entry.get("text", "")
    if not text:
        return False, text

    original = text

    # 1. General substitutions
    text = apply_general(text)

    # 2. Флинт -> Флит for the 5 specific hero-address entries
    if eid in FLINT_TO_FLIT_IDS:
        text = apply_flint_to_flit(eid, text)

    # 3. Explicit overrides (post-general-sub rewraps / fixes)
    if eid in EXPLICIT_OVERRIDES:
        old, new = EXPLICIT_OVERRIDES[eid]
        if old in text:
            text = text.replace(old, new)
        # If old not found (e.g. idempotent run), text is already correct

    return text != original, text


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
        "grp_text":   os.path.join(TRANS, "grp_text.json"),
        "vcast_text": os.path.join(TRANS, "vcast_text.json"),
        "pack0_text": os.path.join(TRANS, "pack0_text.json"),
    }

    total_changed: dict[str, dict[str, str]] = {}

    for fname, fpath in files.items():
        data = load_json(fpath)
        entries = data["entries"]
        changed_ids: dict[str, str] = {}

        for eid, entry in entries.items():
            changed, new_text = apply_entry(eid, entry)
            if changed:
                changed_ids[eid] = new_text
                if not dry_run:
                    entry["text"] = new_text

        total_changed[fname] = changed_ids

        if not dry_run:
            save_json(fpath, data)

        print(f"{fname}: {len(changed_ids)} entries changed")

    if dry_run:
        print("[dry-run] files not written")
    else:
        print("Done.")

    # Dump changed entries for validator
    all_changed: dict[str, str] = {}
    for changed_ids in total_changed.values():
        all_changed.update(changed_ids)

    dump_path = os.path.join(ROOT, "scripts", "_jp_changed.json")
    with open(dump_path, "w", encoding="utf-8") as f:
        json.dump(all_changed, f, ensure_ascii=False, indent=1)
        f.write("\n")

    total = sum(len(v) for v in total_changed.values())
    print(f"Changed entries written to {dump_path}")
    print(f"Total changed: {total}")


if __name__ == "__main__":
    main()
