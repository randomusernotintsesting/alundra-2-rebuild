import unittest
import verify_hd_menus as driver


class MenuReturnTests(unittest.TestCase):
    def test_retime_routes_after_measured_startup_change(self):
        _,taps,frames=driver.route('settings')
        shifted,actual=driver.shift_route(taps,frames,-1001)
        self.assertEqual(shifted[0],'3699:3:4')
        self.assertEqual(actual,[5399])
        self.assertEqual(taps[0],'4700:3:4')
        self.assertEqual(driver.shift_route(taps,frames,0),(taps,frames))
        with self.assertRaises(ValueError):driver.shift_route(taps,frames,-10000)

    def test_return_exits_each_parent_before_start(self):
        auto, taps, frames = driver.route("menu-return")
        self.assertEqual(auto, "new")
        self.assertEqual([t for t in taps if 7600 < int(t.split(":")[0]) < 9200],
                         ["7800:14:4", "8200:14:4", "8600:3:4"])
        self.assertEqual(frames, [6400, 7600, 9200, 10000])
        self.assertIn("9300:5:400", taps)
        self.assertEqual(driver.route("settings-controls")[2], [6400, 7600, 8800])

    def test_return_requires_native_mode_and_movement(self):
        before = {"frame": 9200, "flags": 0, "raw_size": (960, 720), "position": [-890, 0, -3425]}
        after = {"frame": 10000, "flags": 0, "raw_size": (960, 720), "position": [-700, 0, -3425]}
        driver.verify_menu_return([before, after])
        # Walking into a real tutorial changes cinematic flags, not menu return.
        driver.verify_menu_return([before, {**after, "flags": 0x11}])
        for change in ({"flags": 2}, {"raw_size": (960, 1440)}):
            with self.assertRaises(AssertionError):
                driver.verify_menu_return([{**before, **change}, after])
        with self.assertRaises(AssertionError):
            driver.verify_menu_return([before, {**after, "raw_size": (960, 1440)}])
        with self.assertRaises(AssertionError):
            driver.verify_menu_return([before, {**after, "position": before["position"]}])


if __name__ == "__main__":
    unittest.main()
