import unittest
from pathlib import Path
import tempfile
from PIL import Image
from replay_input_menus import menu_schedule, renderer_capture, export_renderer_capture

class MenuRouteTests(unittest.TestCase):
    def test_preserves_original_navigation_after_cabin_ready(self):
        taps,frames=menu_schedule()
        self.assertEqual(frames,[3000,4701,5901])
        self.assertEqual(taps,['3001:3:4','3301:5:4','3501:5:4','3701:13:4',
            '4101:7:4','4301:13:4','4901:14:4','5101:5:4','5301:5:4','5501:13:4'])
        self.assertTrue(all(int(t.split(':')[0])>3000 for t in taps))
        self.assertFalse(any(t.split(':')[1] not in ('3','5','7','13','14') for t in taps))

    def test_physical_capture_requires_matching_runtime_evidence(self):
        with tempfile.TemporaryDirectory() as folder:
            out=Path(folder)
            env,metadata=renderer_capture(out,5901)
            self.assertEqual(env['A2_UISHOT'],'5901')
            self.assertEqual(Path(env['A2_UISHOT_PATH']).parent,out)
            Image.new('RGB',(960,540),(20,40,60)).save(env['A2_UISHOT_PATH'])
            with self.assertRaises(RuntimeError):
                export_renderer_capture(metadata,'ui shot dumped at frame 4701\n')
            captured=export_renderer_capture(metadata,'ui shot dumped at frame 5901\n')
            self.assertEqual(captured['size'],[960,540])
            with Image.open(captured['png']) as actual:
                self.assertEqual(actual.size,(960,540))
                self.assertEqual(actual.getpixel((10,10)),(20,40,60))

    def test_adjacent_captures_preserve_inputs_and_bound_after_menu(self):
        taps,frames=menu_schedule(adjacent=True)
        self.assertEqual(taps,menu_schedule()[0])
        self.assertEqual(frames,[3000,4701,5900,5901,5902,5903])

    def test_return_uses_original_nested_menu_exit_after_neighbor_window(self):
        taps,frames=menu_schedule(adjacent=True,return_game=True)
        self.assertEqual(taps[:10],menu_schedule()[0])
        self.assertEqual(taps[10:],['6101:14:4','6501:14:4','6901:3:4'])
        self.assertEqual(frames,[3000,4701,5900,5901,5902,5903,6301,7501])
        self.assertTrue(all(int(t.split(':')[0])>5903 for t in taps[10:]))

if __name__=='__main__':unittest.main()
