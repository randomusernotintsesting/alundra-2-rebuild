"""Read-only strict guest/core and unchanged-frame checks for expanded cinema.

The added geometry has no pixels in the original reference. This explicitly
does not claim a complete pixel oracle for the additional strips or HD alpha;
their actual output must also be visually reviewed.
"""
import argparse
import json
from pathlib import Path
from PIL import Image, ImageChops
from replay_cinema import compare_picture


def nonblack(image):
    pixels=image.tobytes()
    return sum(pixels[k:k+3]!=b"\0\0\0" for k in range(0,len(pixels),3))


def compare(original_dir, candidate_dir):
    original=json.loads((original_dir/"acceptance.json").read_text())
    candidate=json.loads((candidate_dir/"acceptance.json").read_text())
    errors=[];rows=[]
    for label,report in (("original",original),("candidate",candidate)):
        if not report.get("capture_passed",report["passed"]):errors.append(f"{label} capture failed")
    if original["checkpoints"]!=candidate["checkpoints"]:errors.append("Checkpoint sequences differ")
    controls=lambda p:{f.name:f.read_bytes() for f in p.glob("control-*.txt")}
    if controls(original_dir)!=controls(candidate_dir):errors.append("Control sequences differ")
    old={c["frame"]:c for c in original["captures"]}
    if set(old)!={c["frame"] for c in candidate["captures"]}:errors.append("Capture frame sets differ")
    for c in candidate["captures"]:
        frame=c["frame"];stem=f"{frame:05}";row={"frame":frame,"expanded":c.get("expanded",False)}
        if frame not in old:continue
        for kind in ("ram","vram"):
            row[kind]=(original_dir/f"user/{kind}_{stem}.bin").read_bytes()==(candidate_dir/f"user/{kind}_{stem}.bin").read_bytes()
            if not row[kind]:errors.append(f"{kind} differs at {frame}")
        with Image.open(original_dir/f"user/frame_{stem}.bmp") as a, Image.open(candidate_dir/f"user/frame_{stem}.bmp") as b:
            a=a.convert("RGB");b=b.convert("RGB")
            if not row["expanded"]:
                row["pixels"]=compare_picture(a,b,c["centered"],c.get("gameplay_canvas",False),old[frame].get("gameplay_canvas",False))
                if not row["pixels"]["passed"]:errors.append(f"Complete fallback/gameplay pixels differ at {frame}")
            else:
                s=a.width//320
                if s not in (1,2,3,4) or a.size!=(320*s,240*s) or b.size!=a.size:
                    errors.append(f"Expanded dimensions differ at {frame}");continue
                source_top=(34 if old[frame]["centered"] else 12)*s
                core=ImageChops.difference(a.crop((0,source_top,320*s,source_top+172*s)),b.crop((0,34*s,320*s,206*s))).getbbox()
                bars=b.crop((0,0,320*s,12*s)).getbbox() is None and b.crop((0,239*s,320*s,240*s)).getbbox() is None
                row.update(core_pixels_equal=core is None,core_compared_pixels=320*172*s*s,bars_black=bars,
                           top_extra_nonblack_pixels=nonblack(b.crop((0,12*s,320*s,34*s))),
                           bottom_extra_nonblack_pixels=nonblack(b.crop((0,206*s,320*s,228*s))))
                if core is not None:errors.append(f"Original scene pixels differ at {frame}")
                if not bars:errors.append(f"Expanded bar bounds differ at {frame}")
        rows.append(row)
    if not any(c.get("expanded") for c in candidate["captures"]):errors.append("No logged expanded frame")
    return dict(passed=not errors,errors=errors,captures=rows,full_added_geometry_pixel_oracle=False,
                scope="Complete RAM/VRAM, original scene pixels and complete unchanged gameplay/fallback pixels; visual review required for additional geometry and HD subtitle alpha")


if __name__=="__main__":
    p=argparse.ArgumentParser(description=__doc__);p.add_argument("original",type=Path);p.add_argument("candidate",type=Path)
    args=p.parse_args();result=compare(args.original,args.candidate);print(json.dumps(result,indent=2));raise SystemExit(0 if result["passed"] else 1)
