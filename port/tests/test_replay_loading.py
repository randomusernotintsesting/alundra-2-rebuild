"""Pure tests: no game process, image generation, or compilation."""
import struct
import unittest
import replay_loading
from replay_loading import loading_state,sequence_runs,acceptance

TABLE=((0,0),(128,0),(0,32),(128,32),(0,64),(128,64),(0,96),(128,96),(0,96),(128,64))
GOOD_LOG='nativecd: raw_read_attempts=0 data_dma_attempts=0 fifo_attempts=0\n'


def ram_state(enabled=3,tick=2,next_index=2,source=(128,0)):
    ram=bytearray(0x200000)
    for i,pair in enumerate(TABLE):struct.pack_into('<2h',ram,0x4f9e8+i*4,*pair)
    struct.pack_into('<I',ram,0x5d004,2)
    struct.pack_into('<8h',ram,0x5d010,*source,128,32,116,180,128,32)
    for offset,value in ((0xb0,tick),(0xb8,enabled),(0xbc,next_index)):
        struct.pack_into('<I',ram,0x5d000+offset,value)
    return ram


class LoadingReplayTests(unittest.TestCase):
    def test_ram_environment_is_recorded_separately_from_display_and_next_index(self):
        state=loading_state(ram_state(),501)
        self.assertTrue(state['ram_loading_active'])
        self.assertEqual(state['ram_environment_tile'],1)
        self.assertIsNone(state['displayed_tile'])
        self.assertEqual(state['next_table_index'],2)
        self.assertEqual(state['delay'],2)
        self.assertEqual(state['table'],[list(p) for p in TABLE])

    def test_frame534_after_irq_ram_does_not_relabel_earlier_presented_bmp(self):
        # Actual failed run: BMP532/533/534 share SHA25689de9ef0..., but
        # RAM534 advances to env128,0 / tick2 / next index2 after present().
        state=loading_state(ram_state(enabled=5,tick=2,next_index=2),534)
        log=('disp: x=0 y=0 w=128 h=32 vlines=32 y1=196 '
             'hrange=1750..3030 (hspan=1280) on=1\n'
             'control: paused frame=534 overlay=5\n'
             'disp: x=128 y=0 w=128 h=32 vlines=32 y1=196 '
             'hrange=1750..3030 (hspan=1280) on=1\n'
             'control: paused frame=535 overlay=5\n')
        state=replay_loading.classify_display(state,log)
        self.assertTrue(state['active'])
        self.assertEqual(state['displayed_tile'],0)
        self.assertEqual(state['display_source_rectangle'],[0,0,128,32])
        self.assertEqual(state['ram_source_rectangle'],[128,0,128,32])
        self.assertTrue(state['ram_source_differs_from_display'])

    def test_visible_tail_is_retained_after_irq_disables_loading(self):
        state=loading_state(ram_state(enabled=0),535)
        log=('disp: x=128 y=0 w=128 h=32 vlines=32 y1=196 '
             'hrange=1750..3030 (hspan=1280) on=1\ncontrol: paused frame=535\n')
        state=replay_loading.classify_display(state,log)
        self.assertTrue(state['active'])
        self.assertFalse(state['ram_loading_active'])
        self.assertEqual(state['displayed_tile'],1)
        self.assertFalse(replay_loading.classify_display(state,log.replace('on=1','on=0'))['active'])
        with self.assertRaisesRegex(ValueError,'Unknown displayed loading source'):
            replay_loading.classify_display(state,log.replace('x=128','x=64'))

    def test_stale_dispenv_after_loading_is_not_active(self):
        self.assertFalse(loading_state(ram_state(enabled=0),502)['ram_loading_active'])
        self.assertFalse(loading_state(ram_state(tick=0),502)['ram_loading_active'])

    def test_durations_are_guest_frames_and_keep_repeated_cycle_segments(self):
        states=[]
        for frame,tile in ((500,0),(501,0),(502,1),(503,1),(504,0)):
            states.append(dict(frame=frame,active=True,displayed_tile=tile))
        runs=sequence_runs(states)
        self.assertEqual([(r['tile'],r['guest_frames']) for r in runs],[(0,2),(1,2),(0,1)])
        self.assertTrue(all(r['duration_basis']=='captured guest frames' for r in runs))

    def test_short_native_load_is_accepted_without_full_turn(self):
        states=[dict(frame=500,active=True,displayed_tile=0,crop='frame.png',crop_nonblack=True)]
        result=acceptance(states,GOOD_LOG,0)
        self.assertTrue(result['passed'])
        self.assertEqual(result['observed_tiles'],[0])
        self.assertFalse(result['all_eight_tiles_observed'])

    def test_absent_display_evidence_native_error_and_transport_attempts_fail(self):
        self.assertFalse(acceptance([],GOOD_LOG,0)['passed'])
        state=dict(frame=500,active=True,displayed_tile=0,crop='frame.png',crop_nonblack=True)
        for log in ('',GOOD_LOG+'Native playback failed: damaged cue\n',
                    GOOD_LOG.replace('fifo_attempts=0','fifo_attempts=1')):
            self.assertFalse(acceptance([state],log,0)['passed'])


if __name__=='__main__':unittest.main()
