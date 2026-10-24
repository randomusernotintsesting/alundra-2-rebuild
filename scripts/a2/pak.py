"""PAK archive reader/writer.

Format:
- TOC: N x uint32 LE offsets; first uint32 = first data offset = TOC byte size;
  N = first_offset / 4; zero entries = unused slots;
  entry size = next nonzero offset - current offset.
- Slot offsets MUST stay 4-byte aligned (all stock offsets are). The engine's
  CD streamer DMAs whole middle sectors directly to
  dest_buffer + (2048 - slot_offset % 2048), and DMA MADR ignores bits 0-1,
  so a misaligned slot loads with a 2-byte slip in every direct-DMA'd sector
  (seen in-game as corrupted glyphs in the middle cells of the font banks).
"""
import struct


class PakArchive:
    def __init__(self, slots, tail=b""):
        # slots: list of bytes|None (None = unused TOC slot), file order
        self.slots = slots
        self.tail = tail

    @classmethod
    def load(cls, path):
        with open(path, "rb") as f:
            data = f.read()
        first = struct.unpack_from("<I", data, 0)[0]
        n = first // 4
        offsets = list(struct.unpack_from(f"<{n}I", data, 0))
        slots = []
        nonzero = [(i, o) for i, o in enumerate(offsets) if o]
        for k, (i, o) in enumerate(nonzero):
            end = nonzero[k + 1][1] if k + 1 < len(nonzero) else len(data)
            while len(slots) < i:
                slots.append(None)
            slots.append(data[o:end])
        while len(slots) < n:
            slots.append(None)
        return cls(slots)

    def save(self, path):
        n = len(self.slots)
        pos = n * 4
        offsets = []
        pads = []
        for s in self.slots:
            if s is None:
                offsets.append(0)
                pads.append(0)
            else:
                pad = -pos % 4      # keep slot offsets 4-byte aligned (see top)
                offsets.append(pos + pad)
                pads.append(pad)
                pos += pad + len(s)
        with open(path, "wb") as f:
            f.write(struct.pack(f"<{n}I", *offsets))
            for s, pad in zip(self.slots, pads):
                if s is not None:
                    f.write(b"\x00" * pad)
                    f.write(s)
            f.write(self.tail)
