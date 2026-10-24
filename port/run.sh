#!/bin/sh
# Запуск нативного порта Alundra 2. F1 / Esc — меню, F5 / F9 — сохранение / загрузка.
#
#   ./run.sh          — интро-катсцены (все модели персонажей: Зеппо,
#                       семья пиратов, Флинт), титул, меню и игра.
#   ./run.sh play     — пропустить катсцены и дойти до туториала.
#   ./run.sh remake   — то же, что play (имя оставлено по привычке).
#   ./run.sh fps60    — НЕЗАВЕРШЁННЫЙ ЭКСПЕРИМЕНТ: сокращает ожидание
#                       VSync, ускоряет движение/анимацию/скрипты.
#                       Не является корректным режимом 60 FPS.
#
# Язык текста, озвучка и портреты выбираются перед запуском.
# ГРАФИКА/ЗВУК/УПРАВЛЕНИЕ настраиваются в игре: НАЖМИ F1 (меню
# настроек: разрешение окна, fullscreen, внутреннее
# разрешение 1x-4x, фильтрация, звук, ремап клавиш; геймпад работает
# из коробки). Настройки и карты памяти сохраняются в
# ~/Library/Application Support/Alundra2/Alundra 2/ (A2_USER_DIR меняет каталог).
# Env-переменные
# A2_WIDE/A2_IRSCALE/A2_FILTER/A2_SOUND остаются только для отладки.
cd "$(dirname "$0")" || exit 1
export A2_LAUNCHER=1 A2_NATIVE_SAVES=1

# Match the documented CMake preset; retain older local builds as a fallback.
case "$(uname -s):$(uname -m)" in
    Darwin:arm64) a2_preset=macos-arm64 ;;
    Linux:x86_64) a2_preset=linux-x64 ;;
    *) a2_preset= ;;
esac
if [ -n "${A2_BINARY:-}" ]; then
    a2_binary=$A2_BINARY
    if [ ! -f "$a2_binary" ] || [ ! -x "$a2_binary" ]; then
        printf 'A2_BINARY is not an executable file: %s\n' "$a2_binary" >&2
        exit 1
    fi
elif [ -n "$a2_preset" ] && [ -x "./build/$a2_preset/alundra2" ]; then
    a2_binary=./build/$a2_preset/alundra2
elif [ -x ./build/alundra2 ]; then
    a2_binary=./build/alundra2
else
    if [ -n "$a2_preset" ]; then
        printf 'Build the game first: cmake --preset %s && cmake --build --preset %s\n' "$a2_preset" "$a2_preset" >&2
    else
        printf 'Build the game first: cmake -S . -B build && cmake --build build\n' >&2
    fi
    exit 1
fi

case "${1:-}" in
    play|remake) export A2_SKIP=1; shift ;;
    fps60) export A2_SKIP=1 A2_60=1; shift ;;
esac
exec "$a2_binary" "$@"
