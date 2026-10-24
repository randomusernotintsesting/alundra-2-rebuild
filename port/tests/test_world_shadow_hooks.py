import re
import struct
import sys
import unittest
from pathlib import Path
TOOLS=Path(__file__).resolve().parents[1]/'tools'
sys.path.insert(0,str(TOOLS))
from world_shadow_hooks import SITES,patch_world_shadow_hooks

class ShadowHooks(unittest.TestCase):
    def test_exact_placement_and_source(self):
        data=bytearray(0x400)
        original=''
        for pc,word,call,after in SITES:
            struct.pack_into('<I',data,pc-0x8008de88,word)
            original+='    original();  /* 0x%08X */\n'%pc
        code=original*2
        result=patch_world_shadow_hooks('GAME00',data,0x8008de88,0,code)
        self.assertEqual(result.count('a2_world_shadow_begin(R)'),2)
        self.assertEqual(result.count('a2_world_shadow_emit(R)'),2)
        self.assertEqual(re.sub(r'#ifdef A2_WORLD_PRECISION\n.*?\n#endif\n','',result,flags=re.S),code)
        self.assertIn('original();  /* 0x8008E1B8 */\n#ifdef',result)
        self.assertEqual(patch_world_shadow_hooks('SCPS',data,0x8008de88,0,code),code)
        with self.assertRaises(ValueError):patch_world_shadow_hooks('GAME00',data,0x8008de88,0,result)
        for pc,_,_,_ in SITES:
            changed=data.copy();changed[pc-0x8008de88]^=1
            with self.assertRaises(ValueError):patch_world_shadow_hooks('GAME00',changed,0x8008de88,0,code)
    def test_all_current_generated_sites(self):
        code=(TOOLS.parent/'gen/game00_008.c').read_text()
        for pc,_,_,_ in SITES:
            self.assertGreater(code.count('/* world shadow %08X */'%pc),0)
            self.assertEqual(code.count('/* world shadow %08X */'%pc),code.count('/* 0x%08X */'%pc))
if __name__=='__main__':unittest.main()
