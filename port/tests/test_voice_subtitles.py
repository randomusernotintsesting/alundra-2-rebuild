"""Caption authoring contracts: no lost words, overlap, clipping or bad timing."""
import importlib.util
from pathlib import Path
import unittest
import tempfile

SCRIPT=Path(__file__).resolve().parents[2]/'scripts/build_voice_subtitles.py'

class Subtitles(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        spec=importlib.util.spec_from_file_location('subtitle_builder',SCRIPT)
        cls.m=importlib.util.module_from_spec(spec);spec.loader.exec_module(cls.m)

    def test_word_boundaries_and_explicit_silence(self):
        words=[dict(word=w,start=s,end=e) for w,s,e in [
            ('Hello,',.4,.7),('Flint!',.7,1.1),('Come',3,3.2),('here.',3.2,3.5)]]
        self.assertEqual(self.m.caption_words(words,4000),[
            dict(start_ms=400,end_ms=1350,text='Hello, Flint!'),
            dict(start_ms=3000,end_ms=3800,text='Come here.')])

    def test_long_speech_preserves_every_word_on_two_lines(self):
        text='Well actually Father a vehicle like this is probably a safer form of transportation than a sailing vessel and my hair always gets so frizzy from the salt in the air'
        words=[dict(word=w,start=.3+i*.3,end=.6+i*.3) for i,w in enumerate(text.split())]
        captions=self.m.caption_words(words,14000)
        self.assertGreater(len(captions),1)
        self.assertEqual(' '.join(c['text'].replace('\n',' ') for c in captions),text)
        for i,c in enumerate(captions):
            self.assertLessEqual(len(c['text'].splitlines()),2)
            self.assertTrue(all(len(line)<=52 for line in c['text'].splitlines()))
            self.assertLessEqual(c['end_ms']-c['start_ms'],6500)
            self.assertGreater(c['end_ms'],c['start_ms'])
            if i:self.assertGreaterEqual(c['start_ms'],captions[i-1]['end_ms'])

    def test_bounds_and_srt_rounding(self):
        c=self.m.caption_words([dict(word='Go!',start=.12,end=.95)],1000)
        self.assertEqual(c,[dict(start_ms=120,end_ms=1000,text='Go!')])
        self.assertEqual(self.m.srt(c),'1\n00:00:00,120 --> 00:00:01,000\nGo!\n\n')
        with self.assertRaises(ValueError):
            self.m.caption_words([dict(word='bad',start=-1,end=1)],2000)
        with self.assertRaises(ValueError):
            self.m.caption_words([dict(word='bad',start=2,end=1)],3000)

    def test_bilingual_export_requires_complete_translation(self):
        catalog=dict(clips=[dict(name='TEST',status='speech',duration_ms=2000,
            words=[dict(word='Hello!',start=.2,end=1)],
            captions=[dict(start_ms=200,end_ms=1250,text='Hello!')])],russian={})
        with tempfile.TemporaryDirectory() as directory:
            p=Path(directory)
            with self.assertRaises(ValueError):self.m.build(catalog,p/'data.inc',p/'srt')
            catalog['russian']['TEST:200']='Привет!'
            self.m.build(catalog,p/'data.inc',p/'srt')
            self.assertEqual((p/'srt/en/TEST.srt').read_text(),'1\n00:00:00,200 --> 00:00:01,250\nHello!\n\n')
            self.assertEqual((p/'srt/ru/TEST.srt').read_text(),'1\n00:00:00,200 --> 00:00:01,250\nПривет!\n\n')

if __name__=='__main__':unittest.main()
