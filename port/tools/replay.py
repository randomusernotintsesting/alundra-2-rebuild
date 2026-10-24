"""Run a bounded input replay with isolated saves and frame/log evidence."""
import argparse
import os
from pathlib import Path
import subprocess

port = Path(__file__).resolve().parents[1]
ap = argparse.ArgumentParser(description=__doc__)
ap.add_argument("--output", type=Path, required=True)
ap.add_argument("--binary", type=Path, default=port / "build/alundra2")
ap.add_argument("--disc", type=Path, default=port.parent / "disc_jp")
ap.add_argument("--image", type=Path, default=port.parent / "build/alundra2_jp.bin")
ap.add_argument("--profile-root", type=Path, help="Staged common game-data directory")
ap.add_argument("--text-language", choices=("ru", "ja", "en"))
ap.add_argument("--voice-language", choices=("ja", "en"))
ap.add_argument("--voice-pack", type=Path, help="Explicit pack for the selected voice language")
ap.add_argument("--frames", type=int, default=6000)
ap.add_argument("--every", type=int, default=500)
ap.add_argument("--timeout", type=int, default=180)
ap.add_argument("--auto", choices=["new", "continue", "none"], default="new")
ap.add_argument("--tap", action="append", default=[], help="frame:PS1_bit[:duration]")
ap.add_argument("--no-introfix", action="store_true")
ap.add_argument("--natural-intro", action="store_true")
ap.add_argument("--realtime", action="store_true", help="Run at normal speed")
ap.add_argument("--video-driver", choices=("dummy", "cocoa"), default="dummy",
                help="Explicit cocoa opens a window on macOS and requires --realtime")
ap.add_argument("--ir-scale", type=int, choices=(1, 2, 3, 4), default=1)
ap.add_argument("--hd-ui", type=int, choices=(0,1), default=1,
                help="Enable HD typography or compare original UI at the same resolution")
ap.add_argument("--wide", action="store_true", help="Use the game's widescreen presentation setting")
ap.add_argument("--sound", action="store_true", help="Exercise output queue (silent dummy audio by default)")
ap.add_argument("--audio-driver", choices=("dummy", "coreaudio"), default="dummy",
                help="Explicit coreaudio plays audibly on macOS and requires --sound --realtime")
ap.add_argument("--tick-stats", action="store_true", help="Log measured frame/sequencer rates")
ap.add_argument("--profile-present", action="store_true", help="Measure composition/upload/SDL draw costs without changing pacing")
ap.add_argument("--audio-stats", action="store_true", help="Trace source PCM, CD streaming and silent host output queues")
ap.add_argument("--mix-stats", action="store_true", help="Measure source/mixer peaks and overload without changing PCM or enabling output")
ap.add_argument("--phase-timing", action="store_true", help="Measure exclusive execution phases with wall and thread CPU clocks")
ap.add_argument("--wait-probe", action="store_true", help="Alternate coarse wait APIs for diagnosis; requires realtime phase timing")
ap.add_argument("--no-present-vsync", action="store_true",
                help="Disable renderer present vsync for realtime phase-timing diagnosis")
ap.add_argument("--world-precision", action="store_true", help="Track guarded world projection provenance (experimental, opt-in)")
ap.add_argument("--world-raster", action="store_true", help="Use experimental subpixel world fine rendering; requires world provenance")
ap.add_argument("--world-trace", nargs=2, type=int, metavar=("FIRST", "END"), help="Bound world provenance trace to [FIRST, END) frames")
ap.add_argument("--user-dir", type=Path)
ap.add_argument("--dump-frame", type=int, help="Capture diagnostic PS1 RAM into the output directory")
ap.add_argument("--test-save-at", type=int, help="Request original save menu at an allowed location (diagnostic)")
ap.add_argument("--control-file", type=Path, help="Pause at file-specified frame checkpoints and accept new pad taps")
ap.add_argument("--pixel-watch", help="Trace GPU writes at x,y,frame")
ap.add_argument("--primitive-log", type=int, help="Trace GPU primitives starting at this frame")
args = ap.parse_args()
if args.voice_pack and not args.voice_language:
    ap.error("--voice-pack requires --voice-language")
if args.video_driver == "cocoa" and not args.realtime:
    ap.error("--video-driver cocoa requires --realtime")
if args.audio_driver != "dummy" and (not args.sound or not args.realtime):
    ap.error("--audio-driver coreaudio requires --sound and --realtime")
if args.wait_probe and (not args.realtime or not args.phase_timing):
    ap.error("--wait-probe requires --realtime and --phase-timing")
if args.no_present_vsync and (not args.realtime or not args.phase_timing):
    ap.error("--no-present-vsync requires --realtime and --phase-timing")
if args.world_raster and not args.world_precision:
    ap.error("--world-raster requires --world-precision")
if args.world_trace and (not args.world_precision or args.world_trace[0]<0 or args.world_trace[1]<=args.world_trace[0]):
    ap.error("--world-trace requires --world-precision and 0 <= FIRST < END")
out = args.output.resolve()
out.mkdir(parents=True, exist_ok=True)
env = {k: v for k, v in os.environ.items() if not k.startswith("A2_")}
env.update(SDL_VIDEODRIVER=args.video_driver, SDL_AUDIODRIVER=args.audio_driver, A2_FAST="1",
           A2_USER_DIR=str((args.user_dir or out / "user").resolve()),
           A2_IRSCALE=str(args.ir_scale), A2_WIDE="1" if args.wide else "0",
           A2_HDUI=str(args.hd_ui),
           A2_SOUND="1" if args.sound else "0",
           A2_MAXFRAMES=str(args.frames), A2_TIMEOUT=str(args.timeout),
           A2_SHOTS="1", A2_SHOTEVERY=str(args.every), A2_SHOTDIR=str(out),
           A2_STATELOG="1", A2_TAP=",".join(args.tap))
if args.profile_root:
    env["A2_PROFILE_ROOT"] = str(args.profile_root.resolve())
if args.text_language:
    env["A2_TEXT_LANGUAGE"] = str(("ru", "ja", "en").index(args.text_language))
if args.voice_language:
    env["A2_VOICE_LANGUAGE"] = str(("ja", "en").index(args.voice_language))
if args.voice_pack:
    env["A2_JAPANESE_VOICE_PACK" if args.voice_language == "ja" else "A2_VOICE_PACK"] = str(args.voice_pack.resolve())
if args.auto != "none":
    env["A2_AUTO"] = "1" if args.auto == "new" else "2"
if not args.natural_intro:
    env["A2_SKIP"] = "1"
if args.realtime:
    env.pop("A2_FAST", None)
if args.tick_stats:
    env["A2_TICKSTAT"] = "1"
if args.profile_present:
    env["A2_PROFILE_PRESENT"] = "1"
if args.audio_stats:
    env["A2_AUDIOSTAT"] = "1"
if args.mix_stats:
    env.update(A2_MIXSTAT="1", A2_AUDIOSTAT="1")
if args.phase_timing:
    env["A2_TIMING"] = "1"
if args.wait_probe:
    env["A2_WAIT_PROBE"] = "1"
if args.no_present_vsync:
    env["A2_PRESENT_VSYNC"] = "0"
if args.world_precision:
    env["A2_WORLD_PRECISION"] = "1"
if args.world_raster:
    env["A2_WORLD_RASTER"] = "1"
if args.world_trace:
    env["A2_WORLD_TRACE_FROM"], env["A2_WORLD_TRACE_TO"] = map(str,args.world_trace)
if args.dump_frame is not None:
    env.update(A2_DUMPMEM=f"{args.dump_frame}:0:200000", A2_DUMPOUT=str(out / "ram.bin"))
if args.test_save_at is not None:
    env["A2_TEST_SAVE_AT"] = str(args.test_save_at)
if args.control_file is not None:
    env["A2_CONTROL_FILE"] = str(args.control_file.resolve())
if args.pixel_watch is not None:
    env["A2_PXWATCH"] = args.pixel_watch
if args.primitive_log is not None:
    env.update(A2_PRIMLOG=str(args.primitive_log), A2_PRIMN="2000")
if args.no_introfix:
    env["A2_NOINTROFIX"] = "1"
cmd = [str(args.binary.resolve()), str(args.disc.resolve()), "--boot",
       str(args.image.resolve())]
with (out / "run.log").open("w") as log:
    try:
        result = subprocess.run(cmd, cwd=out, env=env, stdout=log,
                                stderr=subprocess.STDOUT, timeout=args.timeout + 10)
    except subprocess.TimeoutExpired:
        print("Timed out:", out / "run.log")
        raise SystemExit(2)
print(f"Replay exited {result.returncode}: {out / 'run.log'}")
raise SystemExit(result.returncode)
