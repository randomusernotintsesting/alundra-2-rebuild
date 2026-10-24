"""Token codec for Alundra 2 text (GRP.GP sub12 + PACK0.PAK banks).

Encoding: 16-bit LE tokens (lo, hi).
- hi=0xFF       -> ASCII char lo (0x20-0x7A in original data)
- hi=0x00, lo<0x14 -> control code
- anything else -> Japanese glyph (leftover debug text), kept as {JP:HHHH}

Control codes:
  00, 01 = message terminators (01 standard, 00 choice/system variant)
  02 = page break, 03 = newline, 08 = system style, 0A = player name,
  0C = medal count, 0E/0F = button icons, 06 = unknown (JP only)
  04, 05, 07, 0D consume ONE following 16-bit parameter token
  (04 = text color, 05 = map-help prefix, 07 = choice option, 0D = variable)

Markup (translator-facing):
  plain ASCII, "\n" = newline, {PAGE} {SYS} {NAME} {MEDALS} = aliases,
  {0E} = raw standalone code, {04:0001} = code with parameter,
  {JP:HHHH} = raw non-ASCII token (HHHH = 16-bit value, hex).
Cyrillic: chars found in the charmap (char -> 16-bit token value) are
encoded through it; everything else must be ASCII 0x20-0x7A.
"""
import re
import struct

PARAM_CODES = {0x04, 0x05, 0x07, 0x0D}
TERMINATORS = {0x00, 0x01}
NEWLINE = 0x03

ALIASES = {0x02: "PAGE", 0x08: "SYS", 0x0A: "NAME", 0x0C: "MEDALS"}
ALIASES_REV = {v: k for k, v in ALIASES.items()}

_TAG_RE = re.compile(r"\{([0-9A-Fa-f]{2}):([0-9A-Fa-f]{4})\}"
                     r"|\{JP:([0-9A-Fa-f]{4})\}"
                     r"|\{([0-9A-Fa-f]{2})\}"
                     r"|\{([A-Z]+)\}")


class Message:
    """One message: markup text + terminator code (0x00 or 0x01)."""

    def __init__(self, text, end):
        self.text = text
        self.end = end


def decode_block(data, start, end, count=None):
    """Decode messages from data[start:end].

    count: stop after that many messages (rest returned as tail bytes).
    Returns (messages, consumed_end). messages[i].offset relative to start.
    """
    msgs = []
    i = start
    cur = i
    out = []
    while i + 1 < end:
        if count is not None and len(msgs) >= count:
            break
        lo, hi = data[i], data[i + 1]
        i += 2
        if hi == 0xFF:
            out.append(chr(lo))
        elif hi == 0x00 and lo in PARAM_CODES:
            if i + 1 >= end:
                raise ValueError(f"param code {lo:#04x} at end of block")
            p = struct.unpack_from("<H", data, i)[0]
            i += 2
            out.append(f"{{{lo:02X}:{p:04X}}}")
        elif hi == 0x00 and lo in TERMINATORS:
            m = Message("".join(out), lo)
            m.offset = cur - start
            # Exact source bytes for verification. FFxx Cyrillic cells can
            # decode as literal braces/DEL, which are not valid input markup.
            m.encoded = bytes(data[cur:i])
            msgs.append(m)
            out = []
            cur = i
        elif hi == 0x00 and lo == NEWLINE:
            out.append("\n")
        elif hi == 0x00 and lo < 0x14:
            out.append(f"{{{ALIASES.get(lo, f'{lo:02X}')}}}")
        else:
            out.append(f"{{JP:{(hi << 8) | lo:04X}}}")
    if out:
        raise ValueError(f"unterminated message at block offset {cur - start:#x}")
    return msgs, i


def encode_message(msg, charmap=None):
    """Markup + terminator -> bytes (terminator included)."""
    out = bytearray()
    text = msg.text
    i = 0
    while i < len(text):
        c = text[i]
        if c == "{":
            m = _TAG_RE.match(text, i)
            if not m:
                raise ValueError(f"bad tag at {i}: {text[i:i+12]!r}")
            hex2p, param, jp, hex2, name = m.groups()
            if hex2p is not None:
                code = int(hex2p, 16)
                if code not in PARAM_CODES:
                    raise ValueError(f"{{{hex2p}:..}} is not a param code")
                out += struct.pack("<HH", code, int(param, 16))
            elif jp is not None:
                out += struct.pack("<H", int(jp, 16))
            elif hex2 is not None:
                code = int(hex2, 16)
                if code in PARAM_CODES or code in TERMINATORS:
                    raise ValueError(f"{{{hex2}}} needs a param / is a terminator")
                out += struct.pack("<H", code)
            else:
                if name not in ALIASES_REV:
                    raise ValueError(f"unknown tag {{{name}}}")
                out += struct.pack("<H", ALIASES_REV[name])
            i = m.end()
            continue
        if c == "\n":
            out += struct.pack("<H", NEWLINE)
        elif charmap and c in charmap:
            out += struct.pack("<H", charmap[c])
        elif 0x20 <= ord(c) <= 0x7A:
            out += bytes((ord(c), 0xFF))
        else:
            raise ValueError(f"char {c!r} not encodable (add it to the charmap)")
        i += 1
    out += struct.pack("<H", msg.end)
    return bytes(out)


def encode_messages(msgs, charmap=None):
    """-> (block bytes, [message start offsets])."""
    out = bytearray()
    offsets = []
    for m in msgs:
        offsets.append(len(out))
        out += encode_message(m, charmap)
    return bytes(out), offsets
