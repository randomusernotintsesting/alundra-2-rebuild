"""Typed GAME00 shadow batch entry and post-OT-link observation."""
import re
import struct

SITES = ((0x8008DE88, 0x27BDFFB8, 'a2_world_shadow_begin(R);', False),
         (0x8008E1B8, 0xAC820000, 'a2_world_shadow_emit(R);', True))


def patch_world_shadow_hooks(module, data, base, start, code):
    del start
    if module != 'GAME00':
        return code
    for pc, instruction, call, after in SITES:
        pattern = re.compile(r'^    [^\n]*?/\* 0x%08X(?: [^*]*)? \*/$' % pc, re.M)
        if not pattern.search(code):
            continue
        offset = pc-base
        if offset < 0 or data[offset:offset+4] != struct.pack('<I', instruction):
            raise ValueError('World shadow instruction mismatch at %08X' % pc)
        marker = '/* world shadow %08X */' % pc
        if marker in code:
            raise ValueError('World shadow hook already installed')
        block = '#ifdef A2_WORLD_PRECISION\n    %s %s\n#endif' % (call, marker)
        code = pattern.sub(lambda m: m.group(0)+'\n'+block if after else block+'\n'+m.group(0), code)
    return code
