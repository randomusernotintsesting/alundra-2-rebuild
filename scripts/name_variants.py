"""Lossless installed text decoding and bounded voice-name text layout."""
import re
import struct
from a2.cyrfont import charmap
from a2.textcodec import ALIASES, PARAM_CODES, Message, encode_message

TAG = re.compile(r'\{[^}]*\}')
INVERSE_RU = {v: k for k, v in charmap().items()}

def decode_actual(raw, language):
    tokens = struct.unpack('<%dH' % (len(raw) // 2), raw)
    out = []; i = 0
    while i < len(tokens):
        t = tokens[i]; i += 1
        if t in (0, 1):
            if i != len(tokens): raise ValueError('Bytes after message terminator')
            text = ''.join(out)
            if encode_message(Message(text, t), charmap() if language == 0 else None) != raw:
                raise ValueError('Installed text did not round trip')
            return text, t
        if t in PARAM_CODES:
            if i == len(tokens): raise ValueError('Missing control parameter')
            out.append(f'{{{t:02X}:{tokens[i]:04X}}}'); i += 1
        elif t == 3: out.append('\n')
        elif t < 0x14: out.append('{' + ALIASES.get(t, f'{t:02X}') + '}')
        elif language == 0 and t in INVERSE_RU: out.append(INVERSE_RU[t])
        elif 0xFF20 <= t <= 0xFF7A: out.append(chr(t & 255))
        else: out.append(f'{{JP:{t:04X}}}')
    raise ValueError('Unterminated message')

def controls(text):
    return [x for x in TAG.findall(text) if not x.startswith('{JP:')]

def visible_width(text):
    return len(TAG.sub(lambda m: 'x' * (8 if m[0] == '{NAME}' else 1 if m[0].startswith('{JP:') else 0), text))

def reflow(text, width=34, max_lines=3):
    pages = []
    for page in text.split('{PAGE}'):
        if all(visible_width(line) <= width for line in page.split('\n')) and page.count('\n') < max_lines:
            pages.append(page); continue
        words = re.split(r'\s+', page.strip()); lines = []; line = ''
        for word in words:
            if visible_width(word) > width: raise ValueError('Name/word exceeds line width: ' + word)
            trial = line + (' ' if line else '') + word
            if visible_width(trial) > width:
                lines.append(line); line = word
            else: line = trial
        lines.append(line)
        if len(lines) > max_lines: raise ValueError(f'Page needs {len(lines)} lines, limit {max_lines}: {page}')
        pages.append('\n'.join(lines))
    result = '{PAGE}'.join(pages)
    if controls(result) != controls(text): raise ValueError('Reflow changed controls')
    return result
