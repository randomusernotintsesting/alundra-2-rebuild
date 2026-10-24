"""GRP.GP sub[12] text payload: parse and rebuild.

Payload (= last sub12_size bytes of the group; sub12_size at header +0x74):
  +0       uint32 room_id   (opaque, preserve)
  +4       uint32 N         (slot count, 0-89; slot index = stable message ID)
  +8       uint32 slots[N]  (byte offsets into text block; 0xFFFFFFFF = empty)
  +8+4N    uint32 name_off  (extra implicit entry: room name / default string)
  +12+4N   text block: messages back-to-back, ascending, no gaps,
           then 0 or 2 bytes 0x00 pad so payload size % 4 == 0.

The group bytes BEFORE the payload (incl. the 0x104-byte scene header that
sub12_offset points at) never change when text is replaced.
"""
import struct

from . import textcodec

EMPTY = 0xFFFFFFFF


class TextPayload:
    def __init__(self, room_id, slot_refs, messages):
        self.room_id = room_id
        # slot_refs: list of length N; each item = message index or None (empty)
        self.slot_refs = slot_refs
        # messages: in storage order; each has .ref = slot index (int) or "name"
        self.messages = messages

    @classmethod
    def parse(cls, payload):
        room_id, n = struct.unpack_from("<II", payload, 0)
        slots = struct.unpack_from(f"<{n}I", payload, 8)
        name_off = struct.unpack_from("<I", payload, 8 + 4 * n)[0]
        text_start = 12 + 4 * n
        # every message is referenced by exactly one slot or name_off, so
        # the message count is known; the rest is 0/2 bytes of zero pad
        count = sum(1 for o in slots if o != EMPTY) + 1
        msgs, consumed = textcodec.decode_block(
            payload, text_start, len(payload), count=count)
        pad = payload[consumed:]
        if pad not in (b"", b"\x00\x00"):
            raise ValueError(f"unexpected pad {pad!r}")
        by_offset = {m.offset: m for m in msgs}
        slot_refs = []
        for si, off in enumerate(slots):
            if off == EMPTY:
                slot_refs.append(None)
            else:
                by_offset[off].ref = si
                slot_refs.append(off)
        by_offset[name_off].ref = "name"
        for m in msgs:
            if not hasattr(m, "ref"):
                raise ValueError(f"orphan message at {m.offset:#x}")
        # slot_refs as message indices
        idx_of = {m.offset: k for k, m in enumerate(msgs)}
        slot_refs = [idx_of[o] if o is not None else None for o in slot_refs]
        return cls(room_id, slot_refs, msgs)

    def build(self, charmap=None):
        block, offsets = textcodec.encode_messages(self.messages, charmap)
        n = len(self.slot_refs)
        slots = [EMPTY if r is None else offsets[r] for r in self.slot_refs]
        name_idx = next(k for k, m in enumerate(self.messages) if m.ref == "name")
        out = struct.pack("<II", self.room_id, n)
        out += struct.pack(f"<{n}I", *slots) if n else b""
        out += struct.pack("<I", offsets[name_idx])
        out += block
        if len(out) % 4:
            out += b"\x00\x00"
        assert len(out) % 4 == 0
        return out

    def entry_id(self, msg, group_index):
        ref = msg.ref
        return (f"g{group_index:03d}.name" if ref == "name"
                else f"g{group_index:03d}.s{ref}")
