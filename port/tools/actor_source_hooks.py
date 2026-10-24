"""Exact original source identity observations around resident relocation."""
import re
import struct

SITES = (
    (0x8002492C, 'a2_native_actor_sources_before_relocation(R[4]);'),
    (0x80024D00, 'a2_native_actor_sources_after_relocation(R[20], R[2]);'),
)


def patch_actor_source_hooks(module, data, base, start, code):
    del start
    if module != 'SCPS':
        return code
    # The original function has no calls: its post hook is a synchronous
    # transaction boundary, including the early already-relocated return.
    expected = {0x8002492C: 0x27BDFFE8, 0x80024D00: 0x8FB50014}
    for pc, body in SITES:
        pattern = re.compile(r'^    [^\n]*?/\* 0x%08X(?: [^*]*)? \*/$' % pc, re.M)
        if not pattern.search(code):
            continue
        offset = pc-base
        if offset < 0 or data[offset:offset+4] != struct.pack('<I', expected[pc]):
            raise ValueError('Actor source relocation instruction mismatch at %08X' % pc)
        if '/* actor source %08X */' % pc in code:
            raise ValueError('Actor source hook already installed')
        block = ('#ifdef A2_NATIVE_ACTOR_SOURCES\n'
                 '    /* actor source %08X */\n'
                 '    if (a2_native_actor_sources_enabled) %s\n'
                 '#endif\n') % (pc, body)
        code = pattern.sub(lambda m: block+m.group(0), code)
    return code
