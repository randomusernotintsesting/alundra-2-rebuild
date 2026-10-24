from pathlib import Path
import struct,unittest,sys
from qol_choices import patch_choices
from a2.cyrfont import charmap
from a2.textcodec import Message,encode_message
BASE=Path(__file__).resolve().parents[2]/'data'
class Choices(unittest.TestCase):
 def test_all_font_styles_get_localized_options(self):
  raw=(BASE/'1/SCPS_101.15').read_bytes()
  for lang,words in [(0,('Да','Нет')),(2,('Yes','No'))]:
   changed=patch_choices(raw,lang)
   for start,text in zip([0x3cc78,0x3cc84,0x3cc90,0x3cc9c],words*2):
    encoded=encode_message(Message('{07:0000}'+text,0),charmap() if lang==0 else None)
    self.assertEqual(changed[start:start+12],encoded.ljust(12,b'\0'))
   self.assertEqual(raw[:0x3cc78],changed[:0x3cc78]);self.assertEqual(raw[0x3cca8:],changed[0x3cca8:])
  self.assertEqual(patch_choices(raw,1),raw)
 def test_unknown_source_rejected(self):
  raw=bytearray((BASE/'1/SCPS_101.15').read_bytes());raw[0x3cc7c]^=1
  with self.assertRaises(ValueError):patch_choices(bytes(raw),0)
if __name__=='__main__':unittest.main()
