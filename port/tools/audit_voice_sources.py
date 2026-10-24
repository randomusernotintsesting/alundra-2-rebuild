"""Read-only raw-sector audit for locally supplied Alundra 2 media.

Uses ISO9660 directory extents and each image's own PS-X EXE tables; never
uses extracted assets, the native decoder, or hardcoded file LBAs. Output
is JSON on stdout. No source or replacement audio is written. Header-valid
XA means structurally acceptable encoded data, not audible acceptance.
"""
import argparse
import collections
import hashlib
import json
import re
import struct
from pathlib import Path

RAW_BYTES = 2352
ZERO_TAIL = bytes(2336)
ZERO_PAYLOAD = bytes(2304)
TABLES = {
    "SCPS_101.15;1": [("STEREO.XA;1", 0x80054758, 126, 8),
                      ("MONO.XA;1", 0x80054F38, 57, 16)],
    "SLUS_010.17;1": [("STEREO.XA;1", 0x80056EF8, 125, 8),
                      ("MONO.XA;1", 0x800576C8, 52, 16)],
}


def classify_sector(raw):
    if len(raw) != RAW_BYTES:
        raise ValueError("expected one 2352-byte raw sector")
    result = {"primary_channel": raw[17], "duplicate_channel": raw[21],
              "file": raw[16], "coding": raw[19],
              "payload_nonzero": raw[24:2328] != ZERO_PAYLOAD}
    if raw[16:] == ZERO_TAIL:
        kind = "zero_after_16"
    elif raw[15] != 2 or raw[18] & 0x44 != 0x44:
        kind = "non_xa_nonzero"
    elif raw[16:20] != raw[20:24]:
        kind = "subheader_mismatch"
    elif ((raw[19] & 3) > 1 or (raw[19] & 12) > 4 or
          (raw[19] & 48) > 16 or (raw[19] & 128)):
        kind = "invalid_coding"
    else:
        kind = "xa_header_valid"
    result["kind"] = kind
    return result


def read_raw(stream, lba, count=1):
    if lba < 0 or count < 0:
        raise ValueError("negative sector address")
    stream.seek(lba * RAW_BYTES)
    raw = stream.read(count * RAW_BYTES)
    if len(raw) != count * RAW_BYTES:
        raise ValueError(f"truncated raw image at LBA {lba}")
    return raw


def read_data(stream, lba, size):
    raw = read_raw(stream, lba, (size + 2047) // 2048)
    return b"".join(raw[i + 24:i + 2072]
                    for i in range(0, len(raw), RAW_BYTES))[:size]


def iso_u32(record, offset):
    little = struct.unpack_from("<I", record, offset)[0]
    big = struct.unpack_from(">I", record, offset + 4)[0]
    if little != big:
        raise ValueError("ISO9660 endian copies disagree")
    return little


def read_root_files(stream):
    pvd = read_raw(stream, 16)[24:2072]
    if pvd[:7] != b"\x01CD001\x01" or pvd[128:132] != b"\x00\x08\x08\x00":
        raise ValueError("expected Mode2/2352 ISO9660 with 2048-byte logical blocks")
    root = read_data(stream, iso_u32(pvd, 158), iso_u32(pvd, 166))
    files = {}
    i = 0
    while i < len(root):
        size = root[i]
        if size == 0:
            i = (i // 2048 + 1) * 2048
            continue
        record = root[i:i + size]
        if len(record) != size or size < 34 or 33 + record[32] > size:
            raise ValueError("invalid ISO9660 directory record")
        name = record[33:33 + record[32]].decode("ascii")
        if name not in ("\0", "\1"):
            files[name] = (iso_u32(record, 2), iso_u32(record, 10))
        i += size
    return files


def read_clips(exe, table_address, count, stride):
    if len(exe) < 2048 or exe[:8] != b"PS-X EXE":
        raise ValueError("expected PS-X EXE")
    load_address = struct.unpack_from("<I", exe, 24)[0]
    table = table_address - load_address + 2048
    if table < 2048 or table + count * 16 > len(exe):
        raise ValueError("clip table lies outside executable")
    clips = []
    for index in range(count):
        offset, channel, sectors, pointer = struct.unpack_from("<4I", exe, table + index * 16)
        position = pointer - load_address + 2048
        if not 2048 <= position < len(exe):
            raise ValueError("clip name lies outside executable")
        end = exe.find(b"\0", position, position + 32)
        if end < 0:
            raise ValueError("unterminated clip name")
        name = exe[position:end].decode("ascii")
        if not re.fullmatch(r"[A-Za-z0-9_]+", name) or channel >= stride or offset % stride or sectors < 1:
            raise ValueError(f"invalid clip record {index}: {name!r}")
        clips.append({"name": name, "offset": offset, "channel": channel, "sectors": sectors})
    return clips


def audit_extent(stream, lba, size, clips, stride):
    physical_sectors = (size + 2047) // 2048
    for clip in clips:
        first = clip["offset"] + clip["channel"]
        last = first + (clip["sectors"] - 1) * stride
        if clip["sectors"] < 1 or first < 0 or last >= physical_sectors:
            raise ValueError(f"clip {clip['name']} lies outside its ISO file extent")
    raw = read_raw(stream, lba, physical_sectors)
    infos = []
    kinds = collections.Counter()
    streams = collections.Counter()
    stripped_hash = hashlib.sha256()
    for position in range(0, len(raw), RAW_BYTES):
        sector = raw[position:position + RAW_BYTES]
        info = classify_sector(sector)
        infos.append(info)
        kinds[info["kind"]] += 1
        stripped_hash.update(sector[16:])
        if sector[15] == 2 and sector[18] & 0x44 == 0x44:
            streams[f"file={sector[16]},primary={sector[17]},duplicate={sector[21]},coding={sector[19]:02x}"] += 1
    report_clips = []
    for clip in clips:
        first = clip["offset"] + clip["channel"]
        indexes = range(first, first + clip["sectors"] * stride, stride)
        selected = [infos[index] for index in indexes]
        payload_hash = hashlib.sha256()
        for index in indexes:
            payload_hash.update(raw[index * RAW_BYTES + 24:index * RAW_BYTES + 2328])
        report_clips.append(dict(clip, first_lba=lba + first,
            last_lba=lba + indexes[-1], kinds=dict(collections.Counter(i["kind"] for i in selected)),
            nonzero_payload_sectors=sum(i["payload_nonzero"] for i in selected),
            matching_stream_sectors=sum(i["kind"] == "xa_header_valid" and i["file"] == 1
                                        and i["primary_channel"] == clip["channel"] for i in selected),
            payload_sha256=payload_hash.hexdigest()))
    return {"lba": lba, "iso_size": size, "physical_sectors": physical_sectors,
            "stripped_sha256": stripped_hash.hexdigest(), "kinds": dict(kinds),
            "streams": dict(streams), "clips": report_clips,
            "zero_clips": [c["name"] for c in report_clips
                           if c["kinds"] == {"zero_after_16": c["sectors"]}]}


def audit_image(path, whole_disc=False):
    path = Path(path)
    if path.stat().st_size % RAW_BYTES:
        raise ValueError("image length is not a whole number of 2352-byte sectors")
    with path.open("rb") as stream:
        files = read_root_files(stream)
        candidates = set(files).intersection(TABLES)
        if len(candidates) != 1:
            raise ValueError("expected one recognized Japanese or US executable")
        executable = candidates.pop()
        exe = read_data(stream, *files[executable])
        result = {"path": str(path), "image_bytes": path.stat().st_size,
                  "executable": executable, "iso_root": files, "tables": {}}
        for name, address, count, stride in TABLES[executable]:
            clips = read_clips(exe, address, count, stride)
            result["tables"][name] = audit_extent(stream, *files[name], clips, stride)
        if whole_disc:
            stream.seek(0)
            kinds = collections.Counter()
            for block in iter(lambda: stream.read(RAW_BYTES * 1024), b""):
                for offset in range(0, len(block), RAW_BYTES):
                    kinds[classify_sector(block[offset:offset + RAW_BYTES])["kind"]] += 1
            result["whole_disc_kinds"] = dict(kinds)
    return result


def compare_images(left, right):
    result = {}
    for table in left["tables"]:
        a = {c["name"]: c for c in left["tables"][table]["clips"]}
        b = {c["name"]: c for c in right["tables"][table]["clips"]}
        shared = sorted(a.keys() & b.keys())
        result[table] = {"shared": len(shared), "left_only": sorted(a.keys() - b.keys()),
            "right_only": sorted(b.keys() - a.keys()),
            "same_length": sum(a[n]["sectors"] == b[n]["sectors"] for n in shared),
            "same_metadata": sum(all(a[n][k] == b[n][k] for k in ("offset", "channel", "sectors")) for n in shared),
            "same_payload": [n for n in shared if a[n]["payload_sha256"] == b[n]["payload_sha256"]],
            "different_lengths": {n: [a[n]["sectors"], b[n]["sectors"]]
                                  for n in shared if a[n]["sectors"] != b[n]["sectors"]}}
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("image", type=Path)
    parser.add_argument("--compare", type=Path, help="audit another local image and compare named clips")
    parser.add_argument("--whole-disc", action="store_true", help="also classify every physical sector")
    parser.add_argument("--summary", action="store_true", help="omit individual clip details")
    parser.add_argument("--clip", action="append", default=[], help="show details for this name only; repeatable")
    args = parser.parse_args()
    reports = [audit_image(args.image, args.whole_disc)]
    output = {"images": reports}
    if args.compare:
        reports.append(audit_image(args.compare, args.whole_disc))
        output["comparison"] = compare_images(*reports)
    for report in reports:
        for table in report["tables"].values():
            table["named_clip_count"] = len(table["clips"])
            if args.clip:
                table["clips"] = [c for c in table["clips"] if c["name"] in args.clip]
            elif args.summary:
                del table["clips"]
    print(json.dumps(output, indent=2))


if __name__ == "__main__":
    main()
