"""PACK0.PAK text banks: parse and rebuild.

Bank entry layout:
  +0   uint32 0
  +4   uint32 N
  +8   uint32 0
  +12  uint32 offsets[N]  (byte offsets into text block, for strings 1..N;
                           string 0 starts at text block offset 0 implicitly)
  +12+4N  text block: N+1 messages back-to-back (same token grammar as sub12),
          then opaque tail bytes (preserved verbatim).
"""
import struct

from . import textcodec


class TextBank:
    def __init__(self, n, messages, tail):
        self.n = n
        self.messages = messages  # N+1, storage order; index = string ID
        self.tail = tail

    @classmethod
    def parse(cls, data):
        z0, n, z2 = struct.unpack_from("<III", data, 0)
        if z0 != 0 or z2 != 0 or not (1 <= n <= 2000):
            raise ValueError("not a text bank")
        offsets = struct.unpack_from(f"<{n}I", data, 12)
        text_start = 12 + 4 * n
        if text_start >= len(data):
            raise ValueError("not a text bank")
        msgs, consumed = textcodec.decode_block(
            data, text_start, len(data), count=n + 1)
        if len(msgs) != n + 1:
            raise ValueError(f"expected {n + 1} messages, got {len(msgs)}")
        starts = [m.offset for m in msgs]
        if starts[0] != 0 or tuple(starts[1:]) != offsets:
            raise ValueError("offset table mismatch")
        return cls(n, msgs, bytes(data[consumed:]))

    @classmethod
    def detect(cls, data):
        try:
            return cls.parse(data)
        except (ValueError, struct.error, IndexError, KeyError):
            return None

    def build(self, charmap=None):
        block, offsets = textcodec.encode_messages(self.messages, charmap)
        out = struct.pack("<III", 0, self.n, 0)
        out += struct.pack(f"<{self.n}I", *offsets[1:])
        out += block + self.tail
        return out
