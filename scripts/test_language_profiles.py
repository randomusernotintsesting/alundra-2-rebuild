import unittest
from a2.textcodec import Message, encode_message
import build_language_profiles as profile

class LanguageProfileTests(unittest.TestCase):
    def test_missing_nonblank_translation_fails_instead_of_leaking_japanese(self):
        with self.assertRaisesRegex(ValueError,'missing English'):
            profile.english_text('x',{'orig':'{SYS}{JP:0123}','jp':'猫','text':'Кот'}, {})
        self.assertEqual(profile.english_text('blank',{'orig':'{SYS}\n'},{}),'{SYS}\n')

    def test_original_choice_wrapper_and_terminator_survive_us_adaptation(self):
        text=profile.english_text('item',{'orig':'{07:0000}{SYS}{JP:0123}{07:0001}',
            'en':'{07:0000}{SYS}A key.'},{})
        self.assertEqual(text,'{07:0000}{SYS}A key.{07:0001}')
        self.assertEqual(encode_message(Message(text,0))[-2:],b'\0\0')

    def test_override_encodes_ascii_but_rejects_residual_foreign_glyphs_or_lost_variables(self):
        original={'orig':'{SYS}{0D:0000}{JP:0123}'}
        self.assertEqual(profile.english_text('x',original,{'x':'{SYS}{0D:0000} keys'}),
                         '{SYS}{0D:0000} keys')
        for invalid in ('{SYS}鍵','{SYS}{JP:0123}','{SYS}ключ','{SYS}keys'):
            with self.assertRaises(ValueError):profile.english_text('x',original,{'x':invalid})

    def test_replaces_text_without_changing_message_terminators_or_slot_identity(self):
        from a2.sub12 import TextPayload
        first=Message('{JP:0123}',0);first.ref=3
        name=Message('{JP:0456}',1);name.ref='name'
        bank=TextPayload(41,[None,None,None,0],[first,name])
        profile.replace_messages(bank.messages,['a','b'],{'a':'Hello','b':'Room'})
        parsed=TextPayload.parse(bank.build())
        self.assertEqual(parsed.room_id,41)
        self.assertEqual(parsed.slot_refs,[None,None,None,0])
        self.assertEqual([(m.text,m.end,m.ref) for m in parsed.messages], [('Hello',0,3),('Room',1,'name')])

class NativeExecutableTests(unittest.TestCase):
    def test_only_known_five_byte_disc_check_patch_is_allowed(self):
        old=bytearray(0x4000);new=bytearray(old)
        old[0x3c74:0x3c7c]=bytes.fromhex('2669000801001624')
        new[0x3c74:0x3c7c]=bytes.fromhex('3c3a010c01000424')
        self.assertEqual(profile.native_executable_bytes(bytes(new),bytes(old)),bytes(old))
        new[0x2000]=1
        with self.assertRaises(ValueError):profile.native_executable_bytes(bytes(new),bytes(old))

if __name__=='__main__':unittest.main()
