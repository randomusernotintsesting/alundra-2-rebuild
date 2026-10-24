"""Translate the resident seven-style Yes/No table without relocating pointers."""
import struct
from a2.cyrfont import charmap
from a2.textcodec import Message,encode_message
START=0x3cc78
EXPECTED=struct.pack('<24H',7,0,0x82cd,0x82a2,0,0, 7,0,0x82a2,0x82a2,0x82a6,0,
                     7,0,ord('Y'),ord('E'),ord('S'),0, 7,0,ord('N'),ord('O'),0,0)
def patch_choices(raw,language):
    if language==1:return raw
    if language not in (0,2):raise ValueError('Unknown language')
    if raw[START:START+len(EXPECTED)]!=EXPECTED:raise ValueError('Unknown resident choice source')
    result=bytearray(raw)
    words=('Да','Нет') if language==0 else ('Yes','No')
    for n,text in enumerate(words*2):
        encoded=encode_message(Message('{07:0000}'+text,0),charmap() if language==0 else None)
        if len(encoded)>12:raise ValueError('Choice exceeds resident allocation')
        result[START+n*12:START+(n+1)*12]=encoded.ljust(12,b'\0')
    return bytes(result)
