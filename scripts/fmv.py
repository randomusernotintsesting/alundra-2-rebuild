#!/usr/bin/env python3
"""FMV (A2STR.STR) export / import for hard-subbing.

Usage:
  fmv.py export                     -> build/fmv/a2str_video.mp4 (edit this)
  fmv.py import <subtitled.mp4>     -> disc/A2STR.STR (then build_disc.sh)
  fmv.py import <subtitled.mp4> --frames 120-300,700-915
                                    (replace only these frame ranges; the
                                     rest keep original quality)

The video must stay 320x240, 15 fps, exactly 915 frames. Audio is part of
the STR stream and is never touched - subtitles are burned into frames only.

Requires: ffmpeg (brew), java (brew openjdk), tools/jpsxdec/.
"""
import os
import shutil
import subprocess
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from a2.pristine import source

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
JAVA = "/opt/homebrew/opt/openjdk/bin/java"
JPSXDEC = os.path.join(ROOT, "tools", "jpsxdec", "jpsxdec_v2.1-beta", "jpsxdec.jar")
FRAMES = 915
WIDTH, HEIGHT = 320, 240


def run(cmd, **kw):
    r = subprocess.run(cmd, capture_output=True, text=True, **kw)
    if r.returncode != 0:
        sys.exit(f"FAILED: {' '.join(map(str, cmd))}\n{r.stdout}{r.stderr}")
    return r


def jpsxdec(*args):
    return run([JAVA, "-jar", JPSXDEC, *args])


def export(disc):
    out = os.path.join(ROOT, "build", "fmv")
    os.makedirs(out, exist_ok=True)
    str_file = source(disc, "A2STR.STR")
    idx = os.path.join(out, "a2str.idx")
    jpsxdec("-f", str_file, "-x", idx)
    jpsxdec("-x", idx, "-i", "0", "-dir", out, "-vidfmt", "avi:rgb")
    avi = os.path.join(out, "A2STR.STR[0].avi")
    mp4 = os.path.join(out, "a2str_video.mp4")
    run(["ffmpeg", "-y", "-v", "error", "-i", avi,
         "-c:v", "libx264", "-preset", "slow", "-crf", "12",
         "-pix_fmt", "yuv420p", "-c:a", "aac", "-b:a", "192k", mp4])
    os.remove(avi)
    print(f"{mp4}: 320x240, 15 fps, {FRAMES} frames")
    print("Наложите хардсабы (размер/частоту кадров/число кадров не менять)"
          " и выполните: fmv.py import <файл>")


def parse_ranges(spec):
    out = set()
    for part in spec.split(","):
        a, _, b = part.partition("-")
        out.update(range(int(a), int(b or a) + 1))
    if not out or min(out) < 1 or max(out) > FRAMES:
        sys.exit(f"--frames: номера должны быть в 1..{FRAMES}")
    return sorted(out)


def import_(disc, video, frames_spec):
    wanted = parse_ranges(frames_spec) if frames_spec else range(1, FRAMES + 1)
    # validate the user video
    r = run(["ffprobe", "-v", "error", "-select_streams", "v",
             "-count_frames", "-show_entries",
             "stream=width,height,nb_read_frames", "-of", "csv=p=0", video])
    w, h, n = (int(x) for x in r.stdout.strip().split(","))
    if (w, h) != (WIDTH, HEIGHT):
        sys.exit(f"видео {w}x{h}, должно быть {WIDTH}x{HEIGHT}")
    if n != FRAMES:
        sys.exit(f"в видео {n} кадров, должно быть ровно {FRAMES} "
                 "(не меняйте частоту кадров и длительность)")
    str_src = source(disc, "A2STR.STR")
    with tempfile.TemporaryDirectory() as tmp:
        print("извлечение кадров...")
        run(["ffmpeg", "-y", "-v", "error", "-i", video,
             os.path.join(tmp, "%04d.png")])
        xml = os.path.join(tmp, "replace.xml")
        with open(xml, "w") as f:
            f.write('<?xml version="1.0"?>\n<str-replace version="0.3">\n')
            for i in wanted:
                f.write(f' <replace frame="{i}">{tmp}/{i:04d}.png</replace>\n')
            f.write("</str-replace>\n")
        work = os.path.join(tmp, "work.str")
        shutil.copy(str_src, work)
        idx = os.path.join(tmp, "work.idx")
        print(f"замена {len(list(wanted))} кадров (MDEC-кодирование)...")
        jpsxdec("-f", work, "-x", idx)
        jpsxdec("-x", idx, "-i", "0", "-replaceframes", xml)
        # sanity: result must still index as the same video
        chk = os.path.join(tmp, "check.idx")
        jpsxdec("-f", work, "-x", chk)
        with open(chk) as f:
            ok = any("Type:Video" in ln and f"Frame Count:{FRAMES}" in ln
                     for ln in f)
        if not ok:
            sys.exit("результат не прошёл проверку структуры STR")
        dst = os.path.join(disc, "A2STR.STR")
        shutil.move(work, dst)
    print(f"{dst}: видео заменено. Теперь scripts/build_disc.sh")


def main():
    args = sys.argv[1:]
    disc = "disc"
    if "-d" in args:
        i = args.index("-d")
        disc = args[i + 1]
        del args[i:i + 2]
    frames_spec = None
    if "--frames" in args:
        i = args.index("--frames")
        frames_spec = args[i + 1]
        del args[i:i + 2]
    if args[:1] == ["export"]:
        export(disc)
    elif args[:1] == ["import"] and len(args) == 2:
        import_(disc, args[1], frames_spec)
    else:
        print(__doc__)
        sys.exit(1)


if __name__ == "__main__":
    main()
