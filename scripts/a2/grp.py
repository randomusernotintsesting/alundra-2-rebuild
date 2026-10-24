"""GRP.GP archive reader/writer.

Format (verified on USA disc):
- TOC at offset 0: 512 x uint32 LE absolute offsets (2048 bytes).
  All nonzero; some indices alias the same offset (same group).
- Group header (256 bytes at group offset):
    +0x00  4 bytes zero
    +0x04  uint32 main data END (group-relative recorded coords)
    +0x10  sub-resource table: 22 x (uint32 offset, uint32 size),
           offsets relative to group start, zeros = empty slot
    +0xC0  16-byte null-terminated ASCII name
- Recorded coords are shifted: real bytes of region [a, b) are at [a+4, b+4).
- sub[12] (pair at +0x70/+0x74) = text container (localization target);
  its recorded size counts only the text payload, which is always the
  LAST sub12_size bytes of the group.
- Groups tile the file back-to-back, no padding; group span = next TOC
  offset - own offset. TOC alias indices share one group.
"""
import struct

TOC_ENTRIES = 512
HEADER_SIZE = 256
SUB_SLOTS = 22
TEXT_SUB = 12


class Group:
    def __init__(self, index, offset, data):
        self.index = index          # first TOC index pointing at this group
        self.aliases = [index]      # all TOC indices sharing this offset
        self.offset = offset
        self.data = bytearray(data)

    @property
    def name(self):
        return self.data[0xC0:0xD0].split(b"\x00")[0].decode("ascii", "replace")

    @property
    def main_end(self):
        """END of main data in group-relative recorded coords (not a size).
        Real main bytes live at [0x104, main_end + 4)."""
        return struct.unpack_from("<I", self.data, 0x04)[0]

    def subs(self):
        """[(offset, size), ...] for all 22 slots (zeros = empty)."""
        out = []
        for n in range(SUB_SLOTS):
            off, size = struct.unpack_from("<II", self.data, 0x10 + n * 8)
            out.append((off, size))
        return out

    def get_sub(self, n):
        """Raw bytes of sub-resource n. Recorded offsets are shifted by +4
        from the real bytes; sub12's recorded size covers only the text
        payload, preceded by a 0x100-byte preamble (use text_payload())."""
        off, size = struct.unpack_from("<II", self.data, 0x10 + n * 8)
        if off == 0 and size == 0:
            return None
        if n == TEXT_SUB:
            return bytes(self.data[off + 4:off + 0x104 + size])
        return bytes(self.data[off + 4:off + 4 + size])

    @property
    def sub12_size(self):
        return struct.unpack_from("<I", self.data, 0x74)[0]

    def text_payload(self):
        """sub12 text payload = the last sub12_size bytes of the group.
        None if the group has no sub12 (group 0)."""
        off, size = struct.unpack_from("<II", self.data, 0x70)
        if off == 0 and size == 0:
            return None
        assert off + 0x104 + size == len(self.data), self.name
        return bytes(self.data[-size:]) if size else b""

    def set_text_payload(self, payload):
        """Replace the sub12 text payload (any length, multiple of 4) and
        patch the size field. Nothing else in the group changes."""
        off, size = struct.unpack_from("<II", self.data, 0x70)
        if off == 0 and size == 0:
            raise ValueError(f"group {self.name} has no sub12")
        if len(payload) % 4:
            raise ValueError("payload size must be a multiple of 4")
        self.data = self.data[:off + 0x104] + bytearray(payload)
        struct.pack_into("<I", self.data, 0x74, len(payload))


class GrpArchive:
    def __init__(self, toc, groups, head=b"", tail=b""):
        self.toc = toc          # 512 offsets as read (identity preserved via groups)
        self.groups = groups    # list of Group, in file order
        self.head = head        # bytes between TOC end and first group (if any)
        self.tail = tail        # bytes after last group (if any)

    @classmethod
    def load(cls, path):
        with open(path, "rb") as f:
            data = f.read()
        toc = list(struct.unpack_from(f"<{TOC_ENTRIES}I", data, 0))
        # unique offsets in file order; map offset -> Group
        uniq = sorted(set(toc))
        spans = {}
        for i, off in enumerate(uniq):
            end = uniq[i + 1] if i + 1 < len(uniq) else len(data)
            spans[off] = (off, end)
        by_offset = {}
        groups = []
        for idx, off in enumerate(toc):
            if off in by_offset:
                by_offset[off].aliases.append(idx)
                continue
            g = Group(idx, off, data[spans[off][0]:spans[off][1]])
            by_offset[off] = g
            groups.append(g)
        head = data[TOC_ENTRIES * 4:uniq[0]]
        return cls(toc, groups, head=head)

    def by_name(self):
        return {g.name: g for g in self.groups}

    def save(self, path):
        """Write archive, recomputing TOC offsets from current group sizes."""
        new_off = {}
        pos = TOC_ENTRIES * 4 + len(self.head)
        for g in self.groups:
            new_off[id(g)] = pos
            pos += len(g.data)
        toc = [0] * TOC_ENTRIES
        for g in self.groups:
            for idx in g.aliases:
                toc[idx] = new_off[id(g)]
        with open(path, "wb") as f:
            f.write(struct.pack(f"<{TOC_ENTRIES}I", *toc))
            f.write(self.head)
            for g in self.groups:
                f.write(g.data)
            f.write(self.tail)
