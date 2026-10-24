import importlib.util
import json
from pathlib import Path
import tempfile
import unittest
from unittest import mock

SPEC=importlib.util.spec_from_file_location('profile_lightning_native',Path(__file__).with_name('profile_lightning_native.py'))
PROFILE=importlib.util.module_from_spec(SPEC);SPEC.loader.exec_module(PROFILE)


class InitialRouteTests(unittest.TestCase):
    def test_default_preserves_accepted_taps_and_checkpoints(self):
        plan=PROFILE.initial_schedule(0)
        self.assertEqual(plan,dict(ready=3000,idle_until=None,traversal_until=4200,
            taps=['3001:6:160','3401:7:20','3441:6:90','3490:13','3530:13','3570:13','3901:13']))

    def test_indoor_interval_contains_no_replayed_press(self):
        for idle in (60,600,1800):
            plan=PROFILE.initial_schedule(idle)
            self.assertEqual(plan['idle_until'],3000+idle)
            self.assertEqual(plan['traversal_until']-plan['idle_until'],1200)
            occupied=set()
            for tap in plan['taps']:
                parts=list(map(int,tap.split(':')))
                start,bit=parts[:2];hold=parts[2] if len(parts)==3 else 4
                occupied.update(range(start,start+hold))
                self.assertIn(bit,(6,7,13))
            self.assertFalse(occupied.intersection(range(3001,plan['idle_until']+1)))
            self.assertIn(plan['idle_until']+1,occupied)
            # The first long movement and final door confirmation retain their
            # relative timing and original default four-frame hold.
            self.assertTrue(set(range(3001+idle,3161+idle))<=occupied)
            self.assertTrue(set(range(3901+idle,3905+idle))<=occupied)

    def test_invalid_indoor_windows_rejected(self):
        for value in (-60,1,59,61,1801,1860):
            with self.subTest(value=value),self.assertRaises(ValueError):
                PROFILE.initial_schedule(value)

    def test_phase_file_is_atomic_single_word_and_events_have_frame(self):
        with tempfile.TemporaryDirectory() as folder:
            root=Path(folder);events=[]
            PROFILE.publish_phase(root,events,'indoor',3000)
            self.assertEqual((root/'phase.txt').read_text(),'indoor\n')
            self.assertEqual(events[-1]['native_frame'],3000)
            self.assertEqual(events[-1]['phase'],'indoor')
            self.assertGreater(events[-1]['unix_seconds'],0)
            self.assertGreater(events[-1]['monotonic_seconds'],0)
            self.assertTrue(events[-1]['timestamp_utc'].endswith('+00:00'))
            PROFILE.publish_phase(root,events,'complete',3600,completed=False)
            self.assertEqual((root/'phase.txt').read_text(),'complete\n')
            self.assertFalse(events[-1]['completed'])
            self.assertFalse(list(root.glob('*.next')))

    def test_spawn_failure_still_records_bound_stop_without_launching_game(self):
        with tempfile.TemporaryDirectory() as folder:
            root=Path(folder);seed=root/'seed';seed.write_bytes(b'fixture save')
            binary=root/'binary';binary.write_bytes(b'fixture executable')
            archive=root/'archive';archive.write_bytes(b'fixture archive')
            out=root/'output'
            argv=['profile_lightning_native.py','--binary',str(binary),'--archive',str(archive),
                '--seed',str(seed),'--output',str(out),'--ir-scale','2','--idle-frames','600','--isolate-input']
            def no_process(*args,**kwargs):
                self.assertEqual((out/'phase.txt').read_text(),'boot\n')
                self.assertEqual(kwargs['env']['A2_IRSCALE'],'2')
                self.assertEqual(kwargs['env']['A2_TAP'].split(',')[0],'3601:6:160')
                self.assertEqual(kwargs['env']['A2_MAXFRAMES'],'10601')
                raise OSError('deliberate fixture spawn failure')
            with mock.patch('sys.argv',argv),mock.patch.object(PROFILE.subprocess,'Popen',side_effect=no_process):
                with self.assertRaisesRegex(OSError,'fixture spawn failure'):PROFILE.main()
            result=json.loads((out/'result.json').read_text())
            self.assertFalse(result['completed']);self.assertIsNone(result['pid'])
            self.assertEqual([e['phase'] for e in result['phase_events']],['boot','complete'])
            self.assertEqual((out/'phase.txt').read_text(),'complete\n')
            settings=(out/'user/a2settings.ini').read_text()
            self.assertIn('key_14=0\n',settings);self.assertIn('pad_14_1_kind=0\n',settings)
            self.assertEqual(seed.read_bytes(),b'fixture save')


if __name__=='__main__':unittest.main()
