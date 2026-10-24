"""Source-guarded native startup changes retained by batch regeneration."""
import struct

SONY_CALL_SETUP = 0x8001A618
CONTRAIL_RETURN = 0x8001A62C
MATRIX_CONTINUATION = 0x8001A640
# Complete argument/call sequences for Sony, Contrail, Matrix. The original
# presenter owns their fade/hold intervals; skipping its Contrail call removes
# that interval too. Refuse another executable or an unexpected boot sequence.
ORIGINAL_WORDS = (
    0x24040002, 0x24050001, 0x02003021, 0x0C00688E, 0x00003821,
    0x24040004, 0x24050002, 0x02003021, 0x0C00688E, 0x00403821,
    0x24040006, 0x24050003, 0x02003021, 0x0C00688E, 0x00403821,
)


def patch_startup_continuation(module, data, base, start, code):
    if module != 'SCPS':
        return code
    hooks = {
        0x8001A238: ((0x27bdffb0,0xafb20030,0x00809021,0x00a01021), 'a2_startup_logo_begin();'),
        0x8001A4B8: ((0x24020001,0x16820005,0x24020003,0x2aa200b4), 'a2_startup_logo_fade(&R[20],&R[19]);'),
        0x8001A654: ((0x14400007,0,0x0c013a3c,0x00002021), 'a2_startup_movies_begin();'),
    }
    if start in hooks:
        words, hook = hooks[start]
        offset = start - base
        if offset < 0 or data[offset:offset+16] != struct.pack('<4I', *words):
            raise ValueError('Native startup hook does not match SCPS instructions')
        signature = f'void f_{start:08X}(void) {{\n'
        if not code.startswith(signature):
            raise ValueError('Unexpected generated startup function')
        return code.replace(signature, signature + '    ' + hook + '\n', 1)
    if start != CONTRAIL_RETURN:
        return code
    offset = SONY_CALL_SETUP - base
    expected = struct.pack('<15I', *ORIGINAL_WORDS)
    if offset < 0 or data[offset:offset + len(expected)] != expected:
        raise ValueError('Native startup continuation does not match SCPS logo calls')
    return '''void f_8001A62C(void) {
    /* Skip Contrail's complete interval; preserve Sony's R2 skip result. */
    psx_next = 0x8001A640u;
    return;
}'''
