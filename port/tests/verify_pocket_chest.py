"""Validate real paused-game evidence, or print the ordinary-input route."""
import argparse
from pathlib import Path
import struct

from replay_routes import tutorial_taps


def pocket_chest_taps():
    return [t for t in tutorial_taps() if int(t.split(":")[0]) < 10500] + [
        "10501:7:1900", "12520:13:4", "12650:13:4", "12800:13:4", "12950:13:4",
        "13101:6:1150", "14310:13:4", "14400:13:4", "14500:4:1250",
        "14700:13:4", "14900:13:4", "15100:13:4", "15300:13:4",
        "15500:13:4", "15700:13:4", "15801:5:450", "16100:13:4",
        "16301:5:115", "16430:6:150", "16601:7:105", "16720:13:4",
        "16800:13:4", "16900:13:4", "17000:7:40", "17060:13:4",
        "17130:13:4", "17230:13:4", "17360:13:4", "17500:13:4",
        "17630:3:4", "17820:13:4", "18120:13:4", "18420:13:4",
        "18720:4:4", "19020:5:4", "19320:5:4", "19620:3:4",
        "19950:12:4", "20220:14:4", "20400:3:4", "20820:10:4",
        "20900:10:4", "21000:12:4", "21220:3:4", "21500:4:4",
        "21600:13:4", "22020:7:4", "22120:7:4", "22300:13:4",
        "22520:6:4", "22620:13:4", "23520:13:4", "23700:14:4", "23900:3:4"]


def verify(root):
    def ram(frame):
        data = (root / "user" / f"ram_{frame:05}.bin").read_bytes()
        assert len(data) == 0x200000
        return data
    before, owned, assigned = ram(10500), ram(17800), ram(18700)
    assert before[0x63C00] == 0
    assert owned[0x63C00] == 1  # item 52: herb from the actual chest
    assert owned[0x63C22:0x63C27] == bytes.fromhex("0000ffffff")
    assert assigned[0x63C22:0x63C27] == bytes.fromhex("010034ffff")
    for frame, cursor in ((19000, 0), (19300, 1), (19600, 2)):
        data = ram(frame)
        assert struct.unpack_from("<I", data, 0x133904)[0] == cursor
        assert data[0x63C22:0x63C27] == bytes.fromhex("010034ffff")
    rejected = ram(23500)
    assert struct.unpack_from("<hh", rejected, 0x63ED0) == (200, 200)
    assert rejected[0x63C00] == 1  # cannot consume healing herb at full HP
    assert struct.unpack_from("<I", rejected, 0x133720)[0] == 80
    print("PASS: real chest acquisition, pocket assignment, three cursors, full-HP use rejection")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--evidence", type=Path)
    args = parser.parse_args()
    if args.evidence:
        verify(args.evidence)
    else:
        print(" ".join("--tap " + tap for tap in pocket_chest_taps()))
