from pathlib import Path
import re
import sys
import unittest

TOOLS=Path(__file__).resolve().parents[1]/'tools'
sys.path.insert(0,str(TOOLS))
from dialogue_packet_hooks import patch_dialogue_packet_hooks


class DialogueHooks(unittest.TestCase):
    def test_genuine_source_preserves_guest_operations_and_rejects_unknown_code(self):
        data=(TOOLS.parents[1]/'disc_jp'/'SCPS_101.15').read_bytes()
        base=0x80016800
        original='\n'.join([
            '    R[29] = R[29] - 48;  /* 0x8001F0CC */',
            '    R[29] = R[29] - 72;  /* 0x8001E294 */',
            '    R[18] = R[2] + R[0];  /* 0x8001F2AC */',
            '    R[18] = R[2] + R[0];  /* 0x8001F2AC */',
            '    R[29] = R[29] - 56;  /* 0x80021D20 */',
            '    R[2] = 0x8006u << 16;  /* 0x80020140 */',
            '    R[19] = R[2] + R[0];  /* 0x800221AC */'])
        result=patch_dialogue_packet_hooks('SCPS',data,base,0,original)
        self.assertEqual(result.count('a2_dialogue_packets_before('),7)
        stripped=re.sub(r'#ifdef A2_DIALOGUE_PACKETS\n    a2_dialogue_packets_before\(0x[0-9A-F]+u,R\);\n#endif\n','',result)
        self.assertEqual(stripped,original)
        self.assertEqual(patch_dialogue_packet_hooks('GAME00',data,base,0,original),original)
        with self.assertRaises(ValueError):patch_dialogue_packet_hooks('SCPS',data,base,0,result)
        for address in (0x8001e294,0x8001edb8,0x8001f0cc,0x8001f2a4,0x800359a8,0x80035a34):
            bad=bytearray(data);bad[address-base]^=1
            with self.assertRaises(ValueError):patch_dialogue_packet_hooks('SCPS',bad,base,0,original)

    def test_actual_generated_hooks_cover_every_observation(self):
        code=''.join((TOOLS.parent/'gen'/file).read_text() for file in ('scps_006.c','scps_007.c'))
        for pc in ('8001F0CC','8001E294','8001F2AC','80021D20','80020140','800221AC'):
            self.assertEqual(code.count('a2_dialogue_packets_before(0x'+pc+'u,R);'),
                             code.count('/* 0x'+pc+' */'))


if __name__=='__main__':unittest.main()
