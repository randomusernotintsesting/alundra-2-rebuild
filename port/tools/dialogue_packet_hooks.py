"""Preserve source-proven resident dialogue rectangle observations."""
import hashlib
import re

SOURCES=(
    (0x8001e294,0x8001edec,'5f378e3eeee5c893ac37901068f64bfe4dc99d497ef43ca343c798ee19cf4078'),
    (0x8001f0cc,0x8001f2fc,'71521fa1ad78d0a0511a59afd1e4e08254fbbcbbc4935e993dc681f379078d81'),
    (0x800359a8,0x80035a3c,'b5157daf9168cb9b42d0bbbc0ad2c70853f875866aceea9a6b4c67ce2db8168a'),
    (0x80020140,0x8002037c,'01be8bde3fdd6b3ed3be288859c66e9a5d5332e3ff543d60de129613eebc866b'),
    (0x80021d20,0x8002220c,'e733cfbfb23bc82fc72caf3e62db20688b165d7b6bdd943cf56c585ba60ff22d'))

def patch_dialogue_packet_hooks(module,data,base,start,code):
    del start
    if module!='SCPS':return code
    pattern=re.compile(r'^    [^\n]*?/\* 0x(8001F0CC|8001E294|8001F2AC|80021D20|80020140|800221AC) \*/$',re.M)
    if not pattern.search(code):return code
    if 'a2_dialogue_packets_before(' in code:raise ValueError('Dialogue packet hooks already installed')
    for first,last,expected in SOURCES:
        if first<base or hashlib.sha256(data[first-base:last-base]).hexdigest()!=expected:
            raise ValueError('Dialogue packet producer original code identity mismatch')
    return pattern.sub(lambda m:'#ifdef A2_DIALOGUE_PACKETS\n    a2_dialogue_packets_before(0x'+m.group(1)+'u,R);\n#endif\n'+m.group(0),code)
