"""Preserve exact GAME00/EVENT00 completed-scene observations."""
import re
import struct

PREFIX = bytes.fromhex(
    'e0ffbd271000b0af1180103cd03310261800bfaf1400b1af4041118e'
    'bacb000c9c2024264841048ebacb000c200084240100023c')
MARKER = '    psx_scene_submit_complete();  /* scene submit 80086A30 */\n'

SITES = (('GAME00', 0x80086A00, 0x80086A30, PREFIX),
         ('EVENT00', 0x800935C8, 0x80093648, bytes.fromhex(
             'e0ffbd271400b1af0b80113c0f80043c5477238e88e784241800bfaf1000b0af'
             '80100300211043008010020049cc000c212044005477228e0000000040200200'
             '21208200c020040023208200802004000f80023cd0e64224d6cb000c21208200'
             '0b80103c5477228e68761026002102002120820080200400bacb000c21209000'
             '5477228e'
         )),
         ('EVENT00', 0x80099B98, 0x80099C60, bytes.fromhex(
             'e0ffbd271800bfaf1400b1af060080141000b0af0f80023cc8ff4224180040a0'
             'f5660208740040a00f80023cc8ff422401000324180043a0740043a00f80103c'
             '0f80043c00f703928000842480100300211043008010020049cc000c21204400'
             '00f70292000000004020020021208200c020040023208200802004000f80023c'
             'c8ff4224d6cb000c212082000b80113c00f703920833248ec010030023104300'
             '801002002310430080100200231043004011020021104300c010020021208200'
             'bacb000c046a842400f70292'
         )),
)


def patch_scene_submit_hooks(module, data, base, start, code):
    del start
    for owner, lo, pc, prefix in SITES:
        if module != owner:
            continue
        pattern = re.compile(r'^    [^\n]*?/\* 0x%08X(?: [^*]*)? \*/$' % pc, re.M)
        if not pattern.search(code):
            continue
        offset = lo - base
        if offset < 0 or data[offset:offset + len(prefix)] != prefix:
            raise ValueError('Scene submit original instruction mismatch at %08X' % pc)
        marker = '    psx_scene_submit_complete();  /* scene submit %08X */\n' % pc
        if marker in code:
            raise ValueError('Scene submit hook already installed')
        code = pattern.sub(lambda match: marker + match.group(0), code)
    return code
