"""Deterministic ordinary-pad routes used for scene-specific regressions."""


def tutorial_taps():
    taps = ["4800:5:700", "5400:14", "5500:14", "5600:14",
            "5700:5:2200", "5700:9", "7900:4:2600", "10500:7:2000",
            "12500:6:2400", "15000:5:500", "15600:4:2300",
            "15100:13", "15300:13"]
    taps += [f"{frame}:14" for frame in range(5750, 14800, 45)]
    taps += [f"{frame}:15" for frame in range(6000, 14800, 85)]
    return taps


def cabin_taps(dialog_taps_until=25600):
    """Original cabin-switch reproducer; live-cabin used until=24600 instead."""
    taps = tutorial_taps()
    taps += ["18050:13", "18200:4:800", "19100:5:600", "20600:4:1300",
             "22000:7:1600", "23700:4:1200"]
    taps += [f"{frame}:13" for frame in range(18400, dialog_taps_until, 200)]
    taps += [f"{frame}:15" for frame in range(21900, dialog_taps_until, 80)]
    return taps
