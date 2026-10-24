"""Ordinary pad route through the ship to its starboard outdoor deck.

Derived from the retained IR1 checkpoints in september-polish/lightning/
explore-exit. The original cabin route enters the pirate conversation; the
additional moves then approach and jump into the raised starboard doorway.
No guest state injection or original/user save data is involved.
"""
from replay_routes import cabin_taps


def lightning_taps():
    taps = []
    for tap in cabin_taps(dialog_taps_until=35000):
        frame, *rest = tap.split(":")
        taps.append(":".join([str(int(frame) - 1001), *rest]))
    taps += ["30001:4:800", "31010:5:180"]
    taps += [f"{frame}:13" for frame in range(31010, 32450, 90)]
    taps += ["32501:5:400", "33001:6:250", "33301:5:200", "33801:6:220"]
    taps += [f"{frame}:14" for frame in range(33801, 34390, 30)]
    taps += ["34401:5:175", "34601:4:110", "34601:5:110"]
    taps += [f"{frame}:14" for frame in range(34590, 34720, 30)]
    taps += ["35001:5:90", "35101:4:90", "35101:5:90"]
    taps += [f"{frame}:14" for frame in range(35001, 35201, 30)]
    # Exploration reached map11/d80_ at35400, then held on its name banner.
    # Dismiss it promptly and remain outdoors for the lightning observation.
    taps += ["35501:13"]
    return taps


if __name__ == "__main__":
    import json
    print(json.dumps(lightning_taps(), indent=2))
