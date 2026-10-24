"""VCAST cutscene container + dialogue text bank (PAKVCAST.PAK).

Container (one PAK entry, 208 of 311 entries; the other 103 start with
u32 1 and are a different, text-free stream format):
  - section TOC, same convention as the PAK itself:
    u32[0] = TOC byte size = 4 * slot_count = offset of first section;
    u32[k] = absolute offset of section k within the entry (4-aligned),
    0 = unused slot, nonzero offsets strictly ascending;
    section size = next nonzero offset (or entry size) - own offset.
  - sections are self-contained: all internal pointers are relative to the
    section start. No section stores absolute container offsets or the
    offsets/sizes of other sections (verified by exhaustive u32 scan).

Text bank (exactly one per dialogue container; section index is usually 1
but not guaranteed -- entry 44 has it at index 44; identify by signature):
  +0   u32 0x3E8        bank tag (constant 1000)
  +4   u32 N            pointer-slot count (message IDs 1..N)
  +8   u32 0
  +12  u32 ptr[N]       ptr[k] = offset of message (k+1) relative to the
                        text block start; 0xFFFFFFFF = unused slot;
                        NOT necessarily ascending (block order != ID order);
                        message 0 is implicit at offset 0.
  +12+4N text block     16-bit-LE-token messages back to back (a2.textcodec
                        grammar), each ends with terminator 0x0001/0x0000;
                        padded to a 4-byte boundary with one 0x0000 token
                        when the message data ends on a 2-byte boundary.
"""
import struct

from . import textcodec

BANK_TAG = 0x3E8
EMPTY_PTR = 0xFFFFFFFF


class Container:
    """slots: list of bytes|None (None = zero TOC slot), in TOC order."""

    def __init__(self, slots):
        self.slots = slots

    @classmethod
    def parse(cls, data):
        if len(data) < 8:
            raise ValueError("too small")
        first = struct.unpack_from("<I", data, 0)[0]
        if first == 0 or first % 4 or first > len(data):
            raise ValueError(f"bad TOC size {first:#x}")
        n = first // 4
        offs = struct.unpack_from(f"<{n}I", data, 0)
        nz = [(i, o) for i, o in enumerate(offs) if o]
        if not nz or nz[0][1] != first:
            raise ValueError("first section != TOC end")
        prev = 0
        for _, o in nz:
            if o % 4 or o <= prev or o > len(data):
                raise ValueError(f"bad section offset {o:#x}")
            prev = o
        slots = [None] * n
        for k, (i, o) in enumerate(nz):
            end = nz[k + 1][1] if k + 1 < len(nz) else len(data)
            slots[i] = data[o:end]
        return cls(slots)

    def build(self):
        pos = 4 * len(self.slots)
        offs = []
        for s in self.slots:
            if s is None:
                offs.append(0)
            else:
                offs.append(pos)
                pos += len(s)
        return struct.pack(f"<{len(offs)}I", *offs) + b"".join(
            s for s in self.slots if s is not None)

    def find_textbank(self):
        """-> slot index of the text bank, or None."""
        hits = [i for i, s in enumerate(self.slots) if s is not None and is_textbank(s)]
        if len(hits) > 1:
            raise ValueError(f"multiple text banks: {hits}")
        return hits[0] if hits else None


def is_textbank(sub):
    if len(sub) < 12:
        return False
    tag, n, zero = struct.unpack_from("<3I", sub, 0)
    return tag == BANK_TAG and zero == 0 and 12 + 4 * n <= len(sub)


class TextBank:
    """messages: list of textcodec.Message in block (storage) order;
    slot_targets: per pointer slot, message index (int) or None (0xFFFFFFFF).
    Message ID k (k>=1) -> messages[slot_targets[k-1]]; ID 0 -> messages[0].
    """

    def __init__(self, messages, slot_targets):
        self.messages = messages
        self.slot_targets = slot_targets

    @classmethod
    def parse(cls, sub):
        if not is_textbank(sub):
            raise ValueError("not a text bank")
        n = struct.unpack_from("<I", sub, 4)[0]
        ptrs = list(struct.unpack_from(f"<{n}I", sub, 12))
        msgs, consumed = textcodec.decode_block(sub, 12 + 4 * n, len(sub))
        if consumed != len(sub):
            raise ValueError(f"trailing bytes after text block: {len(sub)-consumed}")
        # strip the alignment pad token (decodes as one empty end=00 message
        # sitting at a 2-mod-4 block offset, never pointer-referenced)
        if (msgs and msgs[-1].text == "" and msgs[-1].end == 0
                and msgs[-1].offset % 4 == 2
                and msgs[-1].offset not in ptrs):
            msgs.pop()
        starts = {m.offset: j for j, m in enumerate(msgs)}
        targets = []
        for p in ptrs:
            if p == EMPTY_PTR:
                targets.append(None)
            elif p in starts:
                targets.append(starts[p])
            else:
                raise ValueError(f"pointer {p:#x} hits no message start")
        return cls(msgs, targets)

    def build(self, charmap=None):
        block, offsets = textcodec.encode_messages(self.messages, charmap)
        if len(block) % 4:
            block += b"\x00\x00"
        ptrs = [EMPTY_PTR if t is None else offsets[t] for t in self.slot_targets]
        n = len(ptrs)
        return (struct.pack("<3I", BANK_TAG, n, 0)
                + struct.pack(f"<{n}I", *ptrs) + block)
