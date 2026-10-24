#!/usr/bin/env python3
"""Alundra 2 character-model ripper (runtime-capture route).

The on-disc model encoding (PACK0 slots 581+3k) is packed/undocumented, but
the port already runs the original AL22 draw blob.  Run the port with

    A2_MODELCAP=<frame> A2_MODELCAP_OUT=cap.txt A2_RAWDUMP=<frame> \
        A2_FAST=1 A2_SKIP=1 A2_AUTO=1 A2_NOCLIP=1 A2_MAXFRAMES=<frame+1> \
        ./build/alundra2 ../disc_jp --boot ../build/alundra2_jp.bin

which emits, for that frame:
  * cap.txt  — PART markers (per 3D actor), per-vertex GTE RTP inputs (v0
    model-space + screen projection s), and emitted GPU polygons PRIM
    (screen coords + UV + tpage/clut).
  * /tmp/vram_raw.bin — 1024x512x16bpp VRAM snapshot (texture source).

Reconstruction is format-agnostic: a PRIM's on-screen vertices coincide
EXACTLY with the RTP screen projections of the model vertices, so faces are
mapped to model vertices by screen-coordinate match — no need to decode the
opaque in-RAM face records.  Textures are decoded from VRAM through the CLUT
the polygon referenced and packed into a per-model atlas.

Usage:
    model_rip.py cap.txt [--vram /tmp/vram_raw.bin] [--out model]
"""
import argparse
import os
import struct
import sys


# ------------------------------------------------------------------ parse
def parse_capture(path):
    parts = []          # each: {verts:[(x,y,z)], scr:[(sx,sy)]}
    prims = []          # each: {tex,nv,vs:[(sx,sy,u,v)],tpage,clut,col}
    cur = None
    for line in open(path):
        t = line.split()
        if not t:
            continue
        if t[0] == "PART":
            cur = {"obj": t[2].split("=")[1], "verts": [], "scr": []}
            parts.append(cur)
        elif t[0] == "RTP" and cur is not None:
            vs = {tok[1]: tok.split("=")[1] for tok in t if tok[0] == "v"
                  and tok[1].isdigit()}
            ss = {tok[1]: tok.split("=")[1] for tok in t if tok[0] == "s"
                  and tok[1].isdigit()}
            for k in vs:
                x, y, z = (int(c) for c in vs[k].split(","))
                cur["verts"].append((x, y, z))
                if k in ss:
                    sx, sy = (int(c) for c in ss[k].split(","))
                    cur["scr"].append((sx, sy))
                else:
                    cur["scr"].append(None)
        elif t[0] == "PRIM":
            d = {"tex": 0, "gou": 0, "nv": 3, "vs": [], "cols": []}
            for tok in t:
                if tok.startswith("tex="):
                    d["tex"] = int(tok.split("=")[1])
                elif tok.startswith("gou="):
                    d["gou"] = int(tok.split("=")[1])
                elif tok.startswith("nv="):
                    d["nv"] = int(tok.split("=")[1])
                elif tok.startswith("tpage="):
                    d["tpage"] = int(tok.split("=")[1], 16)
                elif tok.startswith("clut="):
                    d["clut"] = int(tok.split("=")[1], 16)
                elif tok[0] == "p" and "=" in tok and tok[1].isdigit():
                    parts_ = tok.split("=")[1].split(",")
                    sx, sy, u, v = (int(c) for c in parts_[:4])
                    col = parts_[4] if len(parts_) > 4 else "808080"
                    d["vs"].append((sx, sy, u, v))
                    d["cols"].append(col)
            prims.append(d)
    return parts, prims


# ------------------------------------------------------------- VRAM decode
class Vram:
    def __init__(self, path):
        self.d = open(path, "rb").read()

    def h(self, x, y):
        return struct.unpack_from("<H", self.d, ((y & 511) * 1024 + (x & 1023)) * 2)[0]

    @staticmethod
    def rgb(c):
        return ((c & 31) << 3, ((c >> 5) & 31) << 3, ((c >> 10) & 31) << 3)

    def texel(self, tpage, clut, u, v):
        """Return (r,g,b) or None for transparent (index 0 / 0x0000)."""
        tpx = (tpage & 0xF) * 64
        tpy = ((tpage >> 4) & 1) * 256
        mode = (tpage >> 7) & 3
        cx = (clut & 0x3F) * 16
        cy = (clut >> 6) & 0x1FF
        if mode == 0:                       # 4bpp
            word = self.h(tpx + (u >> 2), tpy + v)
            idx = (word >> ((u & 3) * 4)) & 0xF
            if idx == 0:
                return None
            return self.rgb(self.h(cx + idx, cy))
        if mode == 1:                       # 8bpp
            word = self.h(tpx + (u >> 1), tpy + v)
            idx = (word >> ((u & 1) * 8)) & 0xFF
            if idx == 0:
                return None
            return self.rgb(self.h(cx + idx, cy))
        c = self.h(tpx + u, tpy + v)        # 15bpp direct
        if c == 0:
            return None
        return self.rgb(c)


# --------------------------------------------------------------- reconstruct
def build_model(parts, prims, vram):
    """Return (verts, faces) where a face = dict(vidx=[...], uv=[...],
    tpage, clut). Only the last PART's vertices (the drawn actor) are used
    when there is exactly one; otherwise every part is merged."""
    # screen -> list of (part, vertex-index). Later parts win ties.
    scr_map = {}
    vbase = []          # flat vertex list (all parts)
    for p in parts:
        base = len(vbase)
        vbase.extend(p["verts"])
        for i, s in enumerate(p["scr"]):
            if s is not None:
                scr_map.setdefault(s, base + i)
    # vertex colors: each model vertex gets the gouraud color the GPU used
    vcol = [None] * len(vbase)
    faces = []
    unmatched = 0
    for pr in prims:
        idx = []
        ok = True
        for (sx, sy, u, v) in pr["vs"]:
            key = (sx, sy)
            if key not in scr_map:
                ok = False
                break
            idx.append(scr_map[key])
        if not ok:
            unmatched += 1
            continue                        # scene/HUD polygon, not the actor
        for vi, colhex in zip(idx, pr["cols"]):
            if vcol[vi] is None:
                vcol[vi] = tuple(int(colhex[j:j + 2], 16) for j in (0, 2, 4))
        faces.append({"vidx": idx, "uv": [(x[2], x[3]) for x in pr["vs"]],
                      "tex": pr["tex"], "tpage": pr.get("tpage", 0),
                      "clut": pr.get("clut", 0)})
    return vbase, faces, vcol, unmatched


def bake_atlas(faces, vram, cell=256):
    """One RGB tile per (tpage,clut); pack in a grid; remap face UVs.
    Returns (PIL image, per-face list of remapped [(U,V)...] in 0..1)."""
    from PIL import Image
    keys = sorted({(f["tpage"], f["clut"]) for f in faces if f["tex"]})
    if not keys:
        return None, None
    cols = min(4, len(keys)) or 1
    rows = (len(keys) + cols - 1) // cols
    atlas = Image.new("RGBA", (cols * cell, rows * cell), (0, 0, 0, 0))
    slot = {}
    for n, (tp, cl) in enumerate(keys):
        ox, oy = (n % cols) * cell, (n // cols) * cell
        for v in range(cell):
            for u in range(cell):
                rgb = vram.texel(tp, cl, u, v)
                if rgb is not None:
                    atlas.putpixel((ox + u, oy + v), (*rgb, 255))
        slot[(tp, cl)] = (ox, oy)
    Aw, Ah = atlas.size
    face_uv = []
    for f in faces:
        if f["tex"] and (f["tpage"], f["clut"]) in slot:
            ox, oy = slot[(f["tpage"], f["clut"])]
            face_uv.append([((ox + u) / Aw, 1.0 - (oy + v) / Ah)
                            for (u, v) in f["uv"]])
        else:
            face_uv.append(None)
    return atlas, face_uv


# -------------------------------------------------------------------- write
def write_obj(verts, faces, face_uv, vcol, out_base, has_atlas):
    mtl = out_base + ".mtl"
    obj = out_base + ".obj"
    png = os.path.basename(out_base) + ".atlas.png"
    with open(mtl, "w") as m:
        m.write("newmtl a2tex\nKa 1 1 1\nKd 1 1 1\n")
        if has_atlas:
            m.write("map_Kd %s\n" % png)
        m.write("newmtl a2flat\nKa 0.5 0.5 0.5\nKd 0.6 0.6 0.6\n")
    with open(obj, "w") as f:
        f.write("mtllib %s\n" % os.path.basename(mtl))
        for i, (x, y, z) in enumerate(verts):
            # extended "v x y z r g b" vertex color (Blender/MeshLab read it)
            c = vcol[i] if vcol[i] else (128, 128, 128)
            f.write("v %d %d %d %.4f %.4f %.4f\n" % (
                x, -y, z, c[0] / 255, c[1] / 255, c[2] / 255))  # PS1 Y is down
        vt_idx = {}
        vt_list = []
        if has_atlas:
            for fi, f_ in enumerate(faces):
                if face_uv[fi]:
                    for uv in face_uv[fi]:
                        if uv not in vt_idx:
                            vt_idx[uv] = len(vt_list) + 1
                            vt_list.append(uv)
            for (u, v) in vt_list:
                f.write("vt %.5f %.5f\n" % (u, v))
        cur_mtl = None
        for fi, f_ in enumerate(faces):
            want = "a2tex" if (has_atlas and face_uv[fi]) else "a2flat"
            if want != cur_mtl:
                f.write("usemtl %s\n" % want)
                cur_mtl = want
            vs = [i + 1 for i in f_["vidx"]]
            uvs = face_uv[fi] if has_atlas else None
            # triangulate quads (0,1,2)+(1,2,3) matching the GPU winding
            tris = [(0, 1, 2)] + ([(1, 2, 3)] if len(vs) == 4 else [])
            for (a, b, c) in tris:
                if uvs:
                    f.write("f %d/%d %d/%d %d/%d\n" % (
                        vs[a], vt_idx[uvs[a]], vs[b], vt_idx[uvs[b]],
                        vs[c], vt_idx[uvs[c]]))
                else:
                    f.write("f %d %d %d\n" % (vs[a], vs[b], vs[c]))
    return obj


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("capture")
    ap.add_argument("--vram", default="/tmp/vram_raw.bin")
    ap.add_argument("--out", default="model")
    ap.add_argument("--textures", action="store_true",
                    help="also bake a VRAM texture atlas (mostly HUD false "
                         "matches for flat-shaded actors; off by default)")
    args = ap.parse_args()

    parts, prims = parse_capture(args.capture)
    print("parts:%d  prims:%d (%d textured)" % (
        len(parts), len(prims), sum(p["tex"] for p in prims)))
    for i, p in enumerate(parts):
        print("  part %d: %d verts" % (i, len(p["verts"])))

    vram = Vram(args.vram) if os.path.exists(args.vram) else None
    verts, faces, vcol, unmatched = build_model(parts, prims, vram)
    ntex = sum(1 for f in faces if f["tex"])
    print("actor faces:%d (%d textured, %d flat/gouraud)  "
          "scene/HUD prims skipped:%d" % (
              len(faces), ntex, len(faces) - ntex, unmatched))

    atlas, face_uv = (None, None)
    if vram and args.textures:
        try:
            atlas, face_uv = bake_atlas(faces, vram)
        except ImportError:
            print("  (PIL missing — geometry only)", file=sys.stderr)
    has_atlas = atlas is not None
    if has_atlas:
        atlas.save(args.out + ".atlas.png")
        print("wrote %s.atlas.png" % args.out)

    obj = write_obj(verts, faces, face_uv, vcol, args.out, has_atlas)
    print("wrote %s  (%d verts, %d faces, per-vertex colors)"
          % (obj, len(verts), len(faces)))


if __name__ == "__main__":
    main()
