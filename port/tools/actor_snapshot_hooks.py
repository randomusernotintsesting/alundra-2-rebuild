"""Exact source-guarded AnimationBridge observations; no guest instruction edits.

Apply to every overlapping generated function containing a selected instruction.
The selected instruction (including its existing delay slot) remains untouched.
"""
import re
import struct

SITES = (('GAME00', 2148041600, (4129, 604177188, 2692743168), 'a2_native_actor_snapshot_entity_reset(R[4]);'), ('GAME00', 2148061860, (666763232, 2947678232, 8425505), 'a2_native_actor_snapshot_entity_update(R[4]);'), ('GAME00', 2148072532, (1006796815, 2353161140, 666763192), 'a2_native_actor_snapshot_begin(psx_frame_no, R[4], R[31]);'), ('GAME00', 2148072776, (2785738752, 2225210038, 0), 'a2_native_actor_snapshot_instance(R[5], R[16]);'), ('GAME00', 2148074420, (2382495812, 0, 272629788), 'int32_t root_q12[3] = {(int32_t)lw_(R[29]+1296), (int32_t)lw_(R[29]+1300), (int32_t)lw_(R[29]+1304)};\n        a2_native_actor_snapshot_root(R[16], root_q12);'), ('SCPS', 2147637864, (666763232, 2947547152, 8421409), 'a2_native_actor_snapshot_animation_select(R[4], R[5], R[6]);'), ('SCPS', 2147639072, (2516713476, 2248343554, 608305153), 'a2_native_actor_snapshot_animation_update(R[16]);'), ('SCPS', 2147637324, (2160649, 39854113, 2411659412), 'a2_native_actor_snapshot_capture(psx_frame_no, R[19], (int32_t)gte_ctrl_read(26), (int32_t)gte_ctrl_read(24), (int32_t)gte_ctrl_read(25));'))
# EVENT00 has a separate arena/entity builder. These observations run before
# the named instruction, including before begin overwrites the arena in v0.
SITES += (
    ('EVENT00', 0x80088A24, (0x3c02800b, 0x244b3f18, 0x01604021),
     'a2_native_actor_snapshot_event_begin(psx_frame_no, R[2]);'),
    ('EVENT00', 0x80088E38, (0x26840104, 0x27a50320, 0x0c009716),
     'a2_native_actor_snapshot_event_instance(R[20], lw_(R[29]+2572));'),
    ('EVENT00', 0x80088EB8, (0xafa0084c, 0xafa00848, 0x8682010a),
     'int32_t root_q12[3] = {(int32_t)lw_(R[29]+2136), (int32_t)lw_(R[29]+2140), (int32_t)lw_(R[29]+2144)};\n'
     '        a2_native_actor_snapshot_root(R[20], root_q12);'),
    ('EVENT00', 0x800895E8, (0x8faf0a0c, 0x26730050, 0x25ef0050),
     'a2_native_actor_snapshot_event_part(R[20], R[21], R[19]-58);'),
    ('EVENT00', 0x8008BBA0, (0x8e630004, 0x00000000, 0x14600004),
     'a2_native_actor_snapshot_event_reset(0x800ce028u+R[22]);'),
)


def patch_actor_snapshot_hooks(module, data, base, start, code):
    del start
    for owner, pc, words, body in SITES:
        if module != owner:
            continue
        pattern = re.compile(r'^    [^\n]*?/\* 0x%08X(?: [^*]*)? \*/$' % pc, re.M)
        matches = list(pattern.finditer(code))
        if not matches:
            continue
        offset = pc - base
        expected = struct.pack('<3I', *words)
        if offset < 0 or data[offset:offset + len(expected)] != expected:
            raise ValueError('AnimationBridge instruction contract mismatch at %08X' % pc)
        if '/* actor snapshot %08X */' % pc in code:
            raise ValueError('AnimationBridge hook already installed at %08X' % pc)
        block = ('#ifdef A2_NATIVE_ACTOR_SNAPSHOT\n'
                 '    /* actor snapshot %08X */\n'
                 '    if (a2_native_actor_snapshot_enabled) {\n'
                 '        %s\n'
                 '    }\n'
                 '#endif\n') % (pc, body)
        code = pattern.sub(lambda match: block + match.group(0), code)
    return code
